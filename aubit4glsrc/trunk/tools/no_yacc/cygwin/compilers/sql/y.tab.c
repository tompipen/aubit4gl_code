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
     INT_VALUE = 2245,
     NAMED = 2246,
     NAMED_GEN = 2247,
     CHAR_VALUE = 2248,
     NOT_USED_1 = 2249,
     NOT_USED_2 = 2250,
     NOT_USED_3 = 2251,
     NOT_USED_4 = 2252,
     NOT_USED_5 = 2253,
     NOT_USED_6 = 2254,
     NOT_USED_7 = 2255,
     NOT_USED_8 = 2256,
     NUMBER_VALUE = 2257,
     SEMICOLON = 2258,
     QUESTION_MARK = 2259,
     CLINE = 2260,
     CH = 2261,
     MARK_VAR = 2262,
     END_MARK_VAR = 2263,
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
     KW_ASCII_OPEN_BRACKET = 1206,
     MODIFY_NEXT_SIZE = 1218,
     LOCK_MODE_PAGE = 1219,
     LOCK_MODE_ROW = 1220,
     UNITS_YEAR = 1227,
     UNITS_MONTH = 1228,
     UNITS_DAY = 1229,
     UNITS_HOUR = 1230,
     UNITS_MINUTE = 1231,
     UNITS_SECOND = 1232,
     TO_CLUSTER = 1237,
     TO_NOT_CLUSTER = 1238,
     CREATE_UC_IDX = 1240,
     CREATE_U_IDX = 1241,
     CREATE_C_IDX = 1242,
     CREATE_IDX = 1243,
     DOUBLE_COLON = 1253,
     SQLSICS = 1259,
     CREATE_SCHEMA = 1260,
     SQLSIRR = 1261,
     UPDATESTATS_T = 1262,
     SQLSICR = 1263,
     SQLSIDR = 1274,
     CREATE_TEMP_TABLE = 1275,
     WITH_CHECK_OPTION = 1283,
     WITH_GRANT_OPTION = 1284,
     SQLSLMNW = 1285,
     WHERE_CURRENT_OF = 1291,
     NOT_NULL_UNIQUE = 1299,
     SQLSLMW = 1306,
     ALL_PRIVILEGES = 1308,
     CREATE_SYNONYM = 1312,
     DROP_TABLE = 1313,
     INEXCLUSIVE = 1315,
     UPDATESTATS = 1320,
     CREATE_TABLE = 1346,
     DEFAULT_NULL = 1347,
     DEFAULT_TODAY = 1348,
     DEFAULT_USER = 1349,
     EXIT_TODO = 1356,
     CONTINUE_TODO = 1357,
     UNLOCK_TABLE = 1364,
     ROLLBACK_W = 1372,
     SQLSEON = 1374,
     SQLSEOFF = 1375,
     CREATE_VIEW = 1379,
     DELETE_FROM = 1380,
     EXTENT_SIZE = 1387,
     FOREIGN_KEY = 1388,
     INSERT_INTO = 1391,
     IS_NOT_NULL = 1393,
     NOT_MATCHES = 1396,
     PRIMARY_KEY = 1402,
     WITH_NO_LOG = 1409,
     INSHARE = 1412,
     BEGIN_WORK = 1418,
     DROP_INDEX = 1423,
     FOR_UPDATE_OF = 1429,
     FOR_UPDATE = 1430,
     LOCK_TABLE = 1435,
     NOT_EXISTS = 1437,
     REFERENCES = 1439,
     RENCOL = 1440,
     SMALLFLOAT = 1442,
     COMMIT_W = 1453,
     RENTAB = 1460,
     KW_CHAR = 1463,
     NCHAR = 1464,
     NVARCHAR = 1465,
     DELIMITER = 1467,
     DROP_VIEW = 1469,
     EXCLUSIVE = 1472,
     GREATER_THAN_EQ = 1476,
     INTO_TEMP = 1478,
     DATABASE = 1502,
     DATETIME = 1503,
     DISTINCT = 1505,
     FRACTION = 1512,
     GROUP_BY = 1514,
     INTERVAL = 1515,
     NOT_LIKE = 1517,
     NOT_ILIKE = 1518,
     NOT_NULL = 1519,
     RESOURCE = 1525,
     SMALLINT = 1526,
     IS_NULL = 1532,
     LESS_THAN_EQ = 1533,
     BETWEEN = 1535,
     CLOSE_BRACKET = 1538,
     CONNECT = 1541,
     KW_CURRENT = 1542,
     KW_DECIMAL = 1544,
     DEFAULT = 1546,
     INTEGER = 1554,
     SERIAL8 = 1556,
     MATCHES = 1559,
     VARCHAR = 1572,
     CLOSE_SQUARE = 1575,
     GREATER_THAN = 1576,
     KW_FALSE = 1577,
     NOT_IN = 1578,
     OPEN_BRACKET = 1580,
     KW_DELETE = 1588,
     KW_ESCAPE = 1591,
     EXISTS = 1592,
     EXTEND = 1593,
     HAVING = 1597,
     KW_INSERT = 1599,
     MINUTE = 1603,
     MODIFY = 1604,
     EQUAL = 1606,
     NOT_EQUAL = 1607,
     OPEN_SQUARE = 1609,
     PUBLIC = 1613,
     KW_RETURN_KEY = 1616,
     REVOKE = 1618,
     SECOND = 1622,
     KW_SELECT = 1626,
     SERIAL = 1627,
     UNIQUE = 1630,
     KW_UPDATE = 1632,
     VALUES = 1633,
     KW_NULL = 1636,
     KW_TRUE = 1637,
     ALTER = 1639,
     CHECK = 1645,
     COUNT = 1649,
     KW_FIRST = 1654,
     KW_FLOAT = 1655,
     GRANT = 1658,
     INDEX = 1661,
     LESS_THAN = 1664,
     MONEY = 1666,
     MONTH = 1667,
     KW_MULTIPLY = 1669,
     ORDER = 1670,
     OUTER = 1671,
     UNION = 1680,
     WHERE = 1683,
     KW_BYTE = 1690,
     CASE = 1692,
     KW_DATE = 1694,
     DESC = 1695,
     KW_DIVIDE = 1696,
     DROP = 1699,
     ELSE = 1700,
     FROM = 1704,
     HOUR = 1710,
     INTO = 1711,
     LIKE = 1714,
     REAL = 1723,
     SOME = 1728,
     KW_TEXT = 1732,
     KW_THEN = 1733,
     USER = 1734,
     WHEN = 1736,
     YEAR = 1739,
     KW_DOW = 1740,
     XSET = 1742,
     ADD = 1743,
     ALL = 1744,
     KW_AND = 1745,
     ANY = 1746,
     ASC = 1747,
     AVG = 1748,
     COLON = 1749,
     KW_COMMA = 1750,
     DAY = 1751,
     DBA = 1752,
     KW_FOR = 1756,
     XMAX = 1761,
     XMIN = 1762,
     KW_MINUS = 1763,
     KW_MOD = 1764,
     KW_NOT = 1765,
     KW_SUM = 1772,
     ATSIGN = 1775,
     KW_PLUS = 1776,
     KW_AS = 1782,
     KW_BY = 1784,
     KW_DOT = 1785,
     KW_IN = 1788,
     KW_ON = 1790,
     KW_OR = 1791,
     KW_TO = 1792,
     BEFORE = 1830,
     END = 1834,
     TILDE = 1841,
     ILIKE = 1842,
     FILLFACTOR = 1845,
     TIME = 1850,
     KW_TODAY = 1857,
     KW_ROWID = 1858,
     TIMESTAMP = 2206,
     SET_TEXT_FORMAT = 2218,
     KW_TAG = 2228,
     LINTMODULEISLIBRARY = 2229,
     KW_PUBLIC = 2230,
     KW_PRIVATE = 2231,
     COPYBACK = 2232,
     REFERENCES_BLOBTYPE_DEFAULT_NULL = 2233,
     REFERENCES_BLOBTYPE = 2234,
     SORT = 2235,
     KWPIPE = 2236,
     KW_DONE = 2237,
     END_TODO = 2238,
     KW_TODO = 2239,
     KW_ALWAYS = 2240,
     PROGRAM_TIMEOUT = 2241,
     USING_SQLTYPE = 2242,
     KW_OBJECT = 2243
   };
#endif
/* Tokens.  */
#define INT_VALUE 2245
#define NAMED 2246
#define NAMED_GEN 2247
#define CHAR_VALUE 2248
#define NOT_USED_1 2249
#define NOT_USED_2 2250
#define NOT_USED_3 2251
#define NOT_USED_4 2252
#define NOT_USED_5 2253
#define NOT_USED_6 2254
#define NOT_USED_7 2255
#define NOT_USED_8 2256
#define NUMBER_VALUE 2257
#define SEMICOLON 2258
#define QUESTION_MARK 2259
#define CLINE 2260
#define CH 2261
#define MARK_VAR 2262
#define END_MARK_VAR 2263
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
#define KW_ASCII_OPEN_BRACKET 1206
#define MODIFY_NEXT_SIZE 1218
#define LOCK_MODE_PAGE 1219
#define LOCK_MODE_ROW 1220
#define UNITS_YEAR 1227
#define UNITS_MONTH 1228
#define UNITS_DAY 1229
#define UNITS_HOUR 1230
#define UNITS_MINUTE 1231
#define UNITS_SECOND 1232
#define TO_CLUSTER 1237
#define TO_NOT_CLUSTER 1238
#define CREATE_UC_IDX 1240
#define CREATE_U_IDX 1241
#define CREATE_C_IDX 1242
#define CREATE_IDX 1243
#define DOUBLE_COLON 1253
#define SQLSICS 1259
#define CREATE_SCHEMA 1260
#define SQLSIRR 1261
#define UPDATESTATS_T 1262
#define SQLSICR 1263
#define SQLSIDR 1274
#define CREATE_TEMP_TABLE 1275
#define WITH_CHECK_OPTION 1283
#define WITH_GRANT_OPTION 1284
#define SQLSLMNW 1285
#define WHERE_CURRENT_OF 1291
#define NOT_NULL_UNIQUE 1299
#define SQLSLMW 1306
#define ALL_PRIVILEGES 1308
#define CREATE_SYNONYM 1312
#define DROP_TABLE 1313
#define INEXCLUSIVE 1315
#define UPDATESTATS 1320
#define CREATE_TABLE 1346
#define DEFAULT_NULL 1347
#define DEFAULT_TODAY 1348
#define DEFAULT_USER 1349
#define EXIT_TODO 1356
#define CONTINUE_TODO 1357
#define UNLOCK_TABLE 1364
#define ROLLBACK_W 1372
#define SQLSEON 1374
#define SQLSEOFF 1375
#define CREATE_VIEW 1379
#define DELETE_FROM 1380
#define EXTENT_SIZE 1387
#define FOREIGN_KEY 1388
#define INSERT_INTO 1391
#define IS_NOT_NULL 1393
#define NOT_MATCHES 1396
#define PRIMARY_KEY 1402
#define WITH_NO_LOG 1409
#define INSHARE 1412
#define BEGIN_WORK 1418
#define DROP_INDEX 1423
#define FOR_UPDATE_OF 1429
#define FOR_UPDATE 1430
#define LOCK_TABLE 1435
#define NOT_EXISTS 1437
#define REFERENCES 1439
#define RENCOL 1440
#define SMALLFLOAT 1442
#define COMMIT_W 1453
#define RENTAB 1460
#define KW_CHAR 1463
#define NCHAR 1464
#define NVARCHAR 1465
#define DELIMITER 1467
#define DROP_VIEW 1469
#define EXCLUSIVE 1472
#define GREATER_THAN_EQ 1476
#define INTO_TEMP 1478
#define DATABASE 1502
#define DATETIME 1503
#define DISTINCT 1505
#define FRACTION 1512
#define GROUP_BY 1514
#define INTERVAL 1515
#define NOT_LIKE 1517
#define NOT_ILIKE 1518
#define NOT_NULL 1519
#define RESOURCE 1525
#define SMALLINT 1526
#define IS_NULL 1532
#define LESS_THAN_EQ 1533
#define BETWEEN 1535
#define CLOSE_BRACKET 1538
#define CONNECT 1541
#define KW_CURRENT 1542
#define KW_DECIMAL 1544
#define DEFAULT 1546
#define INTEGER 1554
#define SERIAL8 1556
#define MATCHES 1559
#define VARCHAR 1572
#define CLOSE_SQUARE 1575
#define GREATER_THAN 1576
#define KW_FALSE 1577
#define NOT_IN 1578
#define OPEN_BRACKET 1580
#define KW_DELETE 1588
#define KW_ESCAPE 1591
#define EXISTS 1592
#define EXTEND 1593
#define HAVING 1597
#define KW_INSERT 1599
#define MINUTE 1603
#define MODIFY 1604
#define EQUAL 1606
#define NOT_EQUAL 1607
#define OPEN_SQUARE 1609
#define PUBLIC 1613
#define KW_RETURN_KEY 1616
#define REVOKE 1618
#define SECOND 1622
#define KW_SELECT 1626
#define SERIAL 1627
#define UNIQUE 1630
#define KW_UPDATE 1632
#define VALUES 1633
#define KW_NULL 1636
#define KW_TRUE 1637
#define ALTER 1639
#define CHECK 1645
#define COUNT 1649
#define KW_FIRST 1654
#define KW_FLOAT 1655
#define GRANT 1658
#define INDEX 1661
#define LESS_THAN 1664
#define MONEY 1666
#define MONTH 1667
#define KW_MULTIPLY 1669
#define ORDER 1670
#define OUTER 1671
#define UNION 1680
#define WHERE 1683
#define KW_BYTE 1690
#define CASE 1692
#define KW_DATE 1694
#define DESC 1695
#define KW_DIVIDE 1696
#define DROP 1699
#define ELSE 1700
#define FROM 1704
#define HOUR 1710
#define INTO 1711
#define LIKE 1714
#define REAL 1723
#define SOME 1728
#define KW_TEXT 1732
#define KW_THEN 1733
#define USER 1734
#define WHEN 1736
#define YEAR 1739
#define KW_DOW 1740
#define XSET 1742
#define ADD 1743
#define ALL 1744
#define KW_AND 1745
#define ANY 1746
#define ASC 1747
#define AVG 1748
#define COLON 1749
#define KW_COMMA 1750
#define DAY 1751
#define DBA 1752
#define KW_FOR 1756
#define XMAX 1761
#define XMIN 1762
#define KW_MINUS 1763
#define KW_MOD 1764
#define KW_NOT 1765
#define KW_SUM 1772
#define ATSIGN 1775
#define KW_PLUS 1776
#define KW_AS 1782
#define KW_BY 1784
#define KW_DOT 1785
#define KW_IN 1788
#define KW_ON 1790
#define KW_OR 1791
#define KW_TO 1792
#define BEFORE 1830
#define END 1834
#define TILDE 1841
#define ILIKE 1842
#define FILLFACTOR 1845
#define TIME 1850
#define KW_TODAY 1857
#define KW_ROWID 1858
#define TIMESTAMP 2206
#define SET_TEXT_FORMAT 2218
#define KW_TAG 2228
#define LINTMODULEISLIBRARY 2229
#define KW_PUBLIC 2230
#define KW_PRIVATE 2231
#define COPYBACK 2232
#define REFERENCES_BLOBTYPE_DEFAULT_NULL 2233
#define REFERENCES_BLOBTYPE 2234
#define SORT 2235
#define KWPIPE 2236
#define KW_DONE 2237
#define END_TODO 2238
#define KW_TODO 2239
#define KW_ALWAYS 2240
#define PROGRAM_TIMEOUT 2241
#define USING_SQLTYPE 2242
#define KW_OBJECT 2243




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
#line 870 "y.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 882 "y.tab.c"

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
#define YYLAST   2324

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  294
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  228
/* YYNRULES -- Number of rules.  */
#define YYNRULES  631
/* YYNRULES -- Number of states.  */
#define YYNSTATES  1111

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   2263

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
       2,     2,     2,     2,     2,     2,    83,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    84,    85,
      86,     2,     2,     2,     2,     2,     2,    87,    88,    89,
      90,    91,    92,     2,     2,     2,     2,    93,    94,     2,
      95,    96,    97,    98,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    99,     2,     2,     2,     2,     2,   100,
     101,   102,   103,   104,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,   105,   106,     2,     2,     2,     2,
       2,     2,     2,   107,   108,   109,     2,     2,     2,     2,
       2,   110,     2,     2,     2,     2,     2,     2,     2,   111,
       2,     2,     2,     2,     2,     2,   112,     2,   113,     2,
       2,     2,   114,   115,     2,   116,     2,     2,     2,     2,
     117,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,   118,   119,   120,   121,
       2,     2,     2,     2,     2,     2,   122,   123,     2,     2,
       2,     2,     2,     2,   124,     2,     2,     2,     2,     2,
       2,     2,   125,     2,   126,   127,     2,     2,     2,   128,
     129,     2,     2,     2,     2,     2,     2,   130,   131,     2,
       2,   132,     2,   133,     2,     2,   134,     2,     2,     2,
       2,     2,   135,     2,     2,     2,     2,     2,     2,   136,
       2,     2,   137,     2,     2,     2,     2,     2,   138,     2,
       2,     2,     2,   139,     2,     2,     2,     2,     2,   140,
     141,     2,     2,     2,     2,   142,     2,   143,     2,   144,
     145,     2,   146,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   147,     2,     2,     2,     2,     2,     2,
     148,     2,     2,   149,   150,   151,     2,   152,     2,   153,
       2,     2,   154,     2,     2,     2,   155,     2,   156,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,   157,   158,     2,   159,     2,     2,     2,     2,
       2,     2,   160,     2,   161,   162,     2,   163,   164,   165,
       2,     2,     2,     2,     2,   166,   167,     2,     2,     2,
       2,     2,   168,   169,     2,   170,     2,     2,   171,     2,
       2,   172,   173,     2,   174,     2,   175,     2,     2,     2,
       2,     2,     2,     2,   176,     2,   177,     2,     2,   178,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,   179,     2,     2,   180,   181,   182,   183,     2,
     184,     2,     2,     2,     2,     2,     2,     2,   185,     2,
       2,   186,   187,   188,     2,     2,     2,   189,     2,   190,
       2,     2,     2,   191,   192,     2,   193,   194,     2,   195,
       2,     2,     2,   196,     2,     2,   197,     2,   198,     2,
       2,     2,   199,     2,     2,     2,   200,   201,     2,     2,
     202,     2,   203,   204,     2,     2,   205,   206,     2,   207,
       2,     2,     2,     2,     2,   208,     2,     2,     2,   209,
       2,     2,     2,     2,   210,   211,     2,     2,   212,     2,
       2,   213,     2,     2,   214,     2,   215,   216,     2,   217,
     218,   219,     2,     2,     2,     2,     2,     2,     2,     2,
     220,     2,     2,   221,     2,     2,     2,     2,     2,     2,
     222,     2,   223,     2,   224,   225,   226,     2,     2,   227,
     228,     2,     2,     2,   229,     2,     2,     2,     2,     2,
     230,   231,     2,     2,   232,     2,     2,     2,     2,     2,
       2,     2,     2,   233,     2,     2,     2,     2,   234,     2,
       2,     2,   235,   236,   237,     2,   238,     2,     2,   239,
     240,     2,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,     2,     2,     2,   252,     2,     2,     2,
       2,   253,   254,   255,   256,   257,     2,     2,     2,     2,
       2,     2,   258,     2,     2,   259,   260,     2,     2,     2,
       2,     2,   261,     2,   262,   263,     2,     2,   264,     2,
     265,   266,   267,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     268,     2,     2,     2,   269,     2,     2,     2,     2,     2,
       2,   270,   271,     2,     2,   272,     2,     2,     2,     2,
     273,     2,     2,     2,     2,     2,     2,   274,   275,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,   276,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,   277,     2,
       2,     2,     2,     2,     2,     2,     2,     2,   278,   279,
     280,   281,   282,   283,   284,   285,   286,   287,   288,   289,
     290,   291,   292,   293,     2,     3,     4,     5,     6,     7,
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
     502,     0,    -1,   203,   493,   298,   296,    -1,    -1,   110,
     497,    -1,   221,   407,    -1,    -1,   110,   497,    -1,   221,
     407,    -1,    71,   303,   171,   193,   184,   304,   171,    -1,
      67,   304,   171,    -1,    68,   304,   171,    -1,   241,   299,
      -1,    70,   304,    -1,    69,   304,    -1,   302,    -1,   299,
     249,   302,    -1,   301,    -1,   259,   301,    -1,   496,   433,
      -1,   496,   263,   496,   433,    -1,   496,   263,   496,   263,
     496,   433,    -1,   496,   263,   217,    -1,   300,   193,   305,
      -1,   300,    -1,   303,   249,   300,    -1,   305,    -1,   304,
     249,   305,    -1,   480,    -1,   205,    -1,   307,    -1,   115,
     493,    -1,   153,   493,    -1,   139,   495,    -1,    60,   496,
      -1,   318,    -1,   309,    -1,   118,   493,   184,   323,   171,
     310,    -1,   106,   493,   184,   323,   171,   319,   310,   319,
      -1,    -1,   311,    -1,   312,    -1,   311,   312,    -1,   264,
     313,    -1,   130,     3,    -1,    66,     3,    -1,    85,    -1,
      86,    -1,     4,    -1,    -1,   315,    -1,   316,    -1,   315,
     316,    -1,   264,   313,    -1,   272,     3,    -1,    45,    -1,
      46,    -1,   493,    -1,    96,   495,   265,   317,   184,   321,
     171,   314,    -1,    95,   495,   265,   317,   184,   321,   171,
     314,    -1,    97,   495,   265,   317,   184,   321,   171,   314,
      -1,    98,   495,   265,   317,   184,   321,   171,   314,    -1,
      72,   506,    -1,    73,   506,    -1,   114,   493,   252,   493,
      -1,    62,   493,   264,     6,    -1,    61,   493,    -1,    76,
     493,    -1,    57,   493,    -1,    58,   496,    -1,    -1,   136,
      -1,    -1,   136,    -1,   322,    -1,   321,   249,   322,    -1,
     496,   246,    -1,   496,   225,    -1,   496,    -1,   324,    -1,
     323,   249,   324,    -1,   387,    -1,   385,    -1,    64,   496,
     326,    -1,    65,   495,    93,    -1,    65,   495,    94,    -1,
     327,    -1,   326,   249,   327,    -1,   328,    -1,   331,    -1,
     334,    -1,   339,    -1,   342,    -1,   338,    -1,   337,    -1,
     242,   329,    -1,   242,   184,   330,   171,    -1,   324,    -1,
     324,   268,   496,    -1,   329,    -1,   330,   249,   329,    -1,
     227,   333,    -1,   227,   184,   332,   171,    -1,   333,    -1,
     332,   249,   333,    -1,   496,    -1,   192,   336,    -1,   192,
     184,   335,   171,    -1,   336,    -1,   335,   249,   336,    -1,
     324,    -1,    85,    -1,    86,    -1,    84,     3,    -1,    74,
     385,   341,    -1,    74,   184,   340,   171,    -1,   385,   341,
      -1,   340,   249,   385,   341,    -1,    -1,    77,   496,    -1,
      75,   343,    -1,    75,   184,   343,   171,    -1,   344,    -1,
     343,   249,   344,    -1,   496,    -1,   125,    -1,    -1,   132,
     347,   493,   350,   348,    -1,    -1,   204,   349,   184,   353,
     171,    -1,   473,    -1,    -1,   184,   351,   171,    -1,   352,
      -1,   351,   249,   352,    -1,   496,    -1,   496,   263,   496,
      -1,   354,    -1,   353,   249,   354,    -1,   480,    -1,   205,
      -1,   129,   493,   297,    -1,   138,    -1,   147,    -1,    -1,
     154,    -1,   360,    -1,    52,   496,    53,     6,    51,    -1,
      52,   496,    53,     6,    -1,    54,    -1,    47,    -1,    48,
      -1,   103,   496,    -1,   117,    -1,   357,    -1,   356,    -1,
     345,    -1,   359,    -1,   393,    -1,   397,    -1,   443,    -1,
     306,    -1,   308,    -1,   325,    -1,   212,   366,   265,   493,
     267,   371,   365,    -1,   198,   366,   265,   493,   229,   371,
      -1,   212,   364,   267,   371,    -1,   198,   364,   229,   371,
      -1,   172,    -1,   166,    -1,   251,    -1,    -1,   108,    -1,
     261,   432,    -1,   113,    -1,   243,    -1,   367,    -1,   368,
      -1,   367,   249,   368,    -1,   200,   369,    -1,   190,    -1,
     185,    -1,   203,   369,    -1,   207,    -1,   213,    -1,    -1,
     184,   370,   171,    -1,   434,    -1,   370,   249,   434,    -1,
     372,    -1,   371,   249,   372,    -1,   196,    -1,   432,    -1,
     128,   493,   374,   261,   464,   376,    -1,    -1,   184,   375,
     171,    -1,   434,    -1,   375,   249,   434,    -1,    -1,   107,
      -1,   208,   184,   463,   171,    -1,   131,   184,   380,   171,
     379,    -1,   144,   381,    -1,   382,    -1,   493,    -1,   493,
     184,   382,   171,    -1,   434,    -1,   382,   249,   434,    -1,
     202,   184,   384,   171,    -1,   159,   184,   384,   171,    -1,
     135,   184,   384,   171,    -1,   434,    -1,   384,   249,   434,
      -1,   383,    -1,   378,    -1,   377,    -1,   175,   439,    -1,
     121,    -1,   120,    -1,   119,    -1,   496,   423,   388,   389,
      -1,    -1,   386,    -1,    -1,   390,    -1,   391,    -1,   390,
     391,    -1,   392,   341,    -1,   165,    -1,   111,    -1,   202,
      -1,   159,    -1,   379,    -1,   208,   184,   463,   171,    -1,
     135,    -1,   101,   394,   396,    -1,   395,    -1,   432,    -1,
     397,    -1,   396,   397,    -1,   373,    -1,   363,    -1,   189,
     407,    -1,   221,   407,    -1,   229,   401,    -1,   403,    -1,
     401,   249,   403,    -1,   401,   249,   219,   403,    -1,   401,
     249,   219,   184,   401,   171,    -1,   401,    34,   402,   265,
     407,    -1,   401,    41,   402,   265,   407,    -1,   401,    -1,
     184,   401,   171,    -1,   493,    -1,   493,   438,    -1,   493,
     261,   438,    -1,    -1,   400,   405,    -1,   406,    -1,   399,
     406,    -1,    -1,   460,    -1,   460,   398,    -1,   398,    -1,
     408,    -1,   407,   266,   408,    -1,   409,    -1,   408,   244,
     409,    -1,   410,    -1,   257,   410,    -1,   420,    -1,   184,
     407,   171,    -1,   187,   474,    -1,   143,   474,    -1,    -1,
     186,   416,    -1,    -1,   186,   416,    -1,    -1,   186,   416,
      -1,   519,    -1,   439,    -1,    -1,   257,    -1,   480,   417,
     168,    -1,   480,   417,   133,    -1,   480,   419,   480,    -1,
     480,   193,   480,    -1,   480,   193,   205,    -1,   480,   417,
     170,   480,   244,   480,    -1,   480,   232,   415,   414,    -1,
     480,   163,   415,   414,    -1,   480,   271,   415,   413,    -1,
     480,   164,   415,   413,    -1,   480,   178,   415,   412,    -1,
     480,   134,   415,   412,    -1,   194,    -1,   214,    -1,   181,
      -1,   270,    -1,   169,    -1,   155,    -1,   418,    -1,   488,
      -1,   411,    -1,   480,    -1,    -1,   243,    -1,   159,    -1,
     202,    -1,    -1,   243,    -1,   159,    -1,   202,    -1,   424,
      -1,   425,    -1,   426,    -1,   428,    -1,   149,    -1,   149,
     184,   429,   171,    -1,   201,    -1,   201,   184,     3,   171,
      -1,   177,    -1,   177,   184,     3,   171,    -1,   174,    -1,
     174,   184,   430,   427,   171,    -1,   215,   184,   430,   427,
     171,    -1,   215,    -1,   224,    -1,   176,    -1,   167,    -1,
     150,    -1,   150,   184,   429,   171,    -1,   151,    -1,   151,
     184,     3,   171,    -1,   151,   184,     3,   249,     3,   171,
      -1,   158,   441,   267,   442,    -1,   158,    -1,   162,   441,
     267,   442,    -1,   465,    -1,   162,    -1,   162,   441,   184,
       3,   171,   267,   442,    -1,   235,    -1,   222,    -1,   179,
      -1,   179,   184,     3,   171,    -1,   179,   184,     3,   249,
       3,   171,    -1,    -1,   249,   431,    -1,   211,   184,   430,
     171,    -1,   233,    -1,   146,    -1,   211,    -1,    81,    -1,
       3,    -1,     3,    -1,     3,    -1,   496,    -1,     6,    -1,
      -1,   195,     3,   180,    -1,   195,     3,   249,     3,   180,
      -1,   437,    -1,   259,   437,    -1,   436,    -1,   259,   436,
      -1,   496,   433,    -1,   491,   263,   496,   433,    -1,   491,
     263,   217,    -1,   275,    -1,   496,   433,    -1,   491,   263,
     496,   433,    -1,   496,   263,   496,   263,   496,   433,    -1,
     491,   263,   217,    -1,   496,    -1,     6,    -1,   498,    -1,
       3,    -1,   454,    -1,    -1,   441,   267,   442,    -1,   239,
      -1,   216,    -1,   250,    -1,   230,    -1,   191,    -1,   199,
      -1,   160,    -1,   239,    -1,   216,    -1,   250,    -1,   230,
      -1,   191,    -1,   199,    -1,   160,    -1,   160,   184,     3,
     171,    -1,   448,    -1,   447,    -1,   444,    -1,   148,   445,
     267,   445,    -1,   145,   491,   263,   446,   267,   446,    -1,
     496,    -1,   496,    -1,   124,   493,    -1,   142,   493,   449,
      -1,   137,    -1,   116,    -1,   451,    -1,   451,   441,   267,
     442,    -1,    55,    -1,   453,    -1,   453,   441,   184,     3,
     171,   267,   442,    -1,   453,   441,   267,   442,    -1,    56,
      -1,   173,   440,    -1,   218,   262,   456,    -1,   457,    -1,
     456,   249,   457,    -1,   458,   459,    -1,     3,    -1,   435,
      -1,    -1,   246,    -1,   225,    -1,   161,   461,    -1,   462,
      -1,   461,   249,   462,    -1,   435,    -1,     3,    -1,   407,
      -1,   473,    -1,   273,    -1,   273,   184,     3,   171,    -1,
     276,    -1,   276,   184,     3,   171,    -1,    -1,    -1,   200,
     475,   476,   467,   477,   468,   500,   404,   470,   471,    -1,
     200,   475,   476,   477,   404,   470,    -1,    -1,   220,   422,
     469,    -1,    -1,   455,    -1,   455,   156,   472,   320,    -1,
     156,   472,   320,    -1,   496,    -1,   200,   475,   476,   477,
     404,    -1,   184,   200,   475,   476,   477,   404,   171,    -1,
      -1,   210,     3,    -1,    -1,   243,    -1,   159,    -1,   202,
      -1,   478,    -1,   479,    -1,   477,   249,   479,    -1,   480,
      -1,   480,   496,    -1,   480,   261,   496,    -1,   519,    -1,
     255,   519,    -1,   260,   519,    -1,   519,   226,   480,    -1,
     519,   487,    -1,   519,   217,   480,    -1,   519,   260,   480,
      -1,   519,   255,   480,    -1,   519,    59,   480,    -1,   439,
      -1,   206,    -1,   182,    -1,   237,    -1,   274,    -1,   275,
      -1,   273,    -1,   217,    -1,    82,    -1,   247,   184,   421,
     480,   171,    -1,   253,   184,   421,   480,   171,    -1,   254,
     184,   421,   480,   171,    -1,   258,   184,   421,   480,   171,
      -1,   209,   184,   421,   480,   171,    -1,     4,   184,   171,
      -1,     4,   184,   484,   171,    -1,   239,   184,   484,   171,
      -1,   216,   184,   484,   171,    -1,   250,   184,   484,   171,
      -1,    49,   184,   484,   171,    -1,    50,   184,   484,   171,
      -1,   240,   184,   484,   171,    -1,   224,   184,   484,   171,
      -1,   184,   480,   171,    -1,   188,   184,   486,   171,    -1,
     450,    -1,   452,    -1,   223,   482,   269,    -1,   483,    -1,
     482,   483,    -1,   238,   407,   236,   480,    -1,   228,   480,
      -1,   480,    -1,   484,   249,   480,    -1,    -1,   249,   441,
     267,   442,    -1,   441,   267,   442,    -1,    -1,   512,   485,
      -1,   480,   485,    -1,    87,    -1,    88,    -1,    89,    -1,
      90,    -1,    91,    -1,    92,    -1,   480,   264,   184,   489,
     171,    -1,   480,   264,   474,    -1,   480,   183,   184,   489,
     171,    -1,   480,   183,   474,    -1,   490,    -1,   489,   249,
     490,    -1,   512,    -1,   439,    -1,   255,     3,    -1,   255,
     498,    -1,   492,    -1,     6,    -1,     6,   263,   496,    -1,
     496,    -1,   496,   248,   496,    -1,   496,   248,     6,   263,
     496,    -1,   496,   259,   496,    -1,   496,   259,   496,   248,
     496,    -1,   496,   259,   496,   248,     6,   263,   496,    -1,
     494,    -1,     6,   263,   496,    -1,   496,   263,   496,    -1,
       6,    -1,   496,    -1,   496,   248,   496,    -1,   496,   248,
       6,   263,   496,    -1,   496,   259,   496,    -1,   496,   259,
     496,   248,   496,    -1,   496,   259,   496,   248,     6,   263,
     496,    -1,     6,   263,   496,    -1,     6,    -1,   496,    -1,
     496,   248,   496,    -1,   496,   248,     6,   263,   496,    -1,
     496,   259,   496,    -1,   496,   259,   496,   248,   496,    -1,
     496,   259,   496,   248,     6,   263,   496,    -1,     4,    -1,
       4,    -1,    15,    -1,   263,     3,    -1,     4,    -1,     6,
      -1,    -1,   496,    -1,   504,    -1,   502,    16,   504,    -1,
     346,    -1,   295,    -1,   355,    -1,    -1,   513,    -1,   362,
      -1,   505,    -1,   511,    -1,   503,    -1,   361,    -1,     1,
      -1,   507,   508,    -1,   501,    -1,   466,    -1,    -1,   141,
      -1,   140,   509,    -1,   510,    -1,   509,   249,   510,    -1,
     496,    -1,   496,   263,   496,    -1,     6,   263,   496,   263,
     496,    -1,   127,    -1,   126,    -1,   112,   521,    -1,   109,
      -1,   105,    -1,   102,    -1,   100,    -1,   104,    -1,   518,
      -1,    17,    -1,   514,    -1,   157,   499,   358,    -1,    20,
       6,    21,    -1,   184,   515,   171,    -1,   515,   516,   515,
      -1,     3,    -1,   517,     3,    -1,   260,    -1,   255,    -1,
     217,    -1,   226,    -1,   256,    -1,   260,    -1,   255,    -1,
     496,    -1,   496,   263,   217,    -1,   496,   263,   275,    -1,
     496,   263,   496,    -1,   496,   263,   496,   263,   496,    -1,
       6,   263,   496,   263,   496,    -1,   496,   195,   515,   180,
      -1,   496,   263,   496,   195,   515,   180,    -1,   496,   263,
     496,   263,   496,   195,   515,   180,    -1,     6,   263,   496,
     263,   496,   195,   515,   180,    -1,   496,   195,   515,   249,
     515,   180,    -1,   496,   263,   496,   195,   515,   249,   515,
     180,    -1,   496,   263,   496,   263,   496,   195,   515,   249,
     515,   180,    -1,     6,   263,   496,   263,   496,   195,   515,
     249,   515,   180,    -1,   520,    -1,   520,    99,   423,    -1,
     481,    -1,   512,    -1,   474,    -1,   243,   474,    -1,   245,
     474,    -1,   234,   474,    -1,    -1,     3,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   468,   468,   494,   497,   514,   519,   522,   539,   545,
     554,   563,   572,   579,   594,   649,   656,   667,   670,   675,
     682,   699,   716,   737,   746,   749,   757,   760,   768,   769,
     776,   779,   787,   790,   794,   800,   801,   805,   815,   829,
     830,   834,   835,   840,   848,   856,   864,   872,   882,   884,
     884,   887,   888,   892,   899,   906,   913,   922,   926,   933,
     945,   956,   962,   966,   970,   975,   979,   982,   986,   989,
     996,   997,  1007,  1008,  1012,  1013,  1017,  1026,  1035,  1042,
    1045,  1051,  1054,  1065,  1069,  1074,  1081,  1084,  1093,  1096,
    1100,  1104,  1108,  1112,  1116,  1124,  1128,  1136,  1139,  1146,
    1149,  1156,  1159,  1166,  1167,  1172,  1176,  1179,  1185,  1188,
    1194,  1201,  1202,  1206,  1214,  1218,  1225,  1227,  1232,  1233,
    1237,  1239,  1245,  1246,  1249,  1260,  1266,  1266,  1275,  1275,
    1284,  1309,  1312,  1320,  1323,  1330,  1333,  1341,  1342,  1348,
    1349,  1357,  1375,  1379,  1384,  1385,  1395,  1404,  1408,  1412,
    1417,  1421,  1425,  1428,  1435,  1441,  1446,  1454,  1455,  1456,
    1457,  1458,  1459,  1460,  1468,  1469,  1470,  1471,  1476,  1477,
    1478,  1481,  1482,  1483,  1487,  1488,  1489,  1493,  1494,  1498,
    1505,  1506,  1507,  1514,  1515,  1518,  1519,  1524,  1525,  1530,
    1531,  1536,  1537,  1542,  1549,  1550,  1555,  1556,  1560,  1561,
    1568,  1576,  1583,  1590,  1594,  1595,  1600,  1601,  1607,  1611,
    1616,  1623,  1624,  1630,  1633,  1636,  1643,  1644,  1645,  1646,
    1652,  1675,  1676,  1679,  1681,  1688,  1691,  1697,  1705,  1710,
    1716,  1721,  1727,  1730,  1735,  1743,  1752,  1757,  1761,  1762,
    1768,  1771,  1782,  1791,  1798,  1804,  1805,  1808,  1813,  1824,
    1828,  1835,  1836,  1840,  1844,  1848,  1855,  1860,  1868,  1871,
    1877,  1880,  1885,  1890,  1903,  1906,  1912,  1915,  1921,  1924,
    1930,  1933,  1940,  1944,  1955,  1955,  1956,  1956,  1957,  1957,
    1960,  1965,  1970,  1971,  1976,  1985,  1993,  1996,  1999,  2003,
    2010,  2013,  2017,  2020,  2023,  2026,  2032,  2039,  2042,  2045,
    2048,  2049,  2054,  2057,  2060,  2063,  2070,  2071,  2072,  2076,
    2083,  2084,  2085,  2089,  2103,  2110,  2111,  2112,  2116,  2117,
    2122,  2123,  2132,  2134,  2143,  2146,  2154,  2164,  2172,  2174,
    2175,  2176,  2177,  2178,  2179,  2180,  2188,  2189,  2190,  2191,
    2192,  2193,  2194,  2195,  2196,  2197,  2198,  2208,  2209,  2215,
    2217,  2218,  2219,  2220,  2224,  2228,  2232,  2239,  2240,  2245,
    2246,  2250,  2258,  2261,  2268,  2271,  2281,  2284,  2287,  2290,
    2297,  2304,  2312,  2321,  2328,  2332,  2337,  2338,  2339,  2344,
    2345,  2354,  2354,  2354,  2354,  2354,  2354,  2354,  2355,  2355,
    2355,  2355,  2355,  2355,  2355,  2355,  2400,  2401,  2402,  2407,
    2408,  2411,  2412,  2416,  2423,  2434,  2435,  2448,  2449,  2453,
    2457,  2458,  2461,  2467,  2471,  2494,  2504,  2507,  2513,  2522,
    2526,  2533,  2534,  2536,  2541,  2547,  2550,  2556,  2557,  2564,
    2577,  2587,  2594,  2611,  2618,  2643,  2645,  2643,  2667,  2711,
    2712,  2726,  2729,  2736,  2746,  2758,  2764,  2777,  2792,  2794,
    2800,  2801,  2802,  2803,  2813,  2820,  2823,  2829,  2832,  2837,
    2846,  2849,  2853,  2860,  2863,  2866,  2869,  2872,  2875,  2878,
    2879,  2880,  2881,  2882,  2883,  2884,  2885,  2886,  2888,  2892,
    2896,  2900,  2904,  2908,  2912,  2916,  2919,  2922,  2925,  2928,
    2931,  2934,  2937,  2940,  2944,  2948,  2952,  2960,  2963,  2972,
    2978,  2985,  2988,  3012,  3013,  3014,  3017,  3018,  3021,  3027,
    3028,  3029,  3030,  3031,  3032,  3037,  3041,  3045,  3049,  3056,
    3059,  3064,  3065,  3066,  3068,  3074,  3084,  3088,  3092,  3096,
    3100,  3104,  3108,  3112,  3120,  3130,  3135,  3139,  3143,  3147,
    3151,  3156,  3160,  3164,  3172,  3175,  3180,  3181,  3182,  3187,
    3188,  3189,  3197,  3200,  3205,  3206,  3210,  3211,  3216,  3240,
    3257,  3258,  3262,  3269,  3275,  3285,  3287,  3290,  3291,  3292,
    3293,  3295,  3298,  3302,  3307,  3311,  3317,  3318,  3321,  3326,
    3327,  3330,  3331,  3332,  3342,  3343,  3344,  3345,  3346,  3347,
    3348,  3349,  3353,  3359,  3361,  3380,  3388,  3395,  3396,  3397,
    3398,  3403,  3404,  3405,  3406,  3407,  3412,  3413,  3429,  3430,
    3431,  3432,  3433,  3434,  3435,  3436,  3437,  3438,  3440,  3441,
    3442,  3443,  3448,  3451,  3460,  3461,  3462,  3463,  3464,  3465,
    3469,  3470
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
  "DOUBLE_PRECISION", "COUNT_MULTIPLY", "KW_ASCII_OPEN_BRACKET",
  "MODIFY_NEXT_SIZE", "LOCK_MODE_PAGE", "LOCK_MODE_ROW", "UNITS_YEAR",
  "UNITS_MONTH", "UNITS_DAY", "UNITS_HOUR", "UNITS_MINUTE", "UNITS_SECOND",
  "TO_CLUSTER", "TO_NOT_CLUSTER", "CREATE_UC_IDX", "CREATE_U_IDX",
  "CREATE_C_IDX", "CREATE_IDX", "DOUBLE_COLON", "SQLSICS", "CREATE_SCHEMA",
  "SQLSIRR", "UPDATESTATS_T", "SQLSICR", "SQLSIDR", "CREATE_TEMP_TABLE",
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
       0,   256,  2244,  2245,  2246,  2247,  2248,  2249,  2250,  2251,
    2252,  2253,  2254,  2255,  2256,  2257,  2258,  2259,  2260,  2261,
    2262,  2263,  1001,  1002,  1003,  1004,  1005,  1007,  1008,  1013,
    1014,  1015,  1017,  1018,  1020,  1023,  1024,  1025,  1026,  1027,
    1028,  1029,  1032,  1036,  1039,  1055,  1056,  1075,  1078,  1080,
    1081,  1084,  1085,  1086,  1087,  1100,  1101,  1102,  1103,  1117,
    1119,  1120,  1121,  1125,  1132,  1133,  1134,  1171,  1172,  1173,
    1174,  1175,  1178,  1179,  1181,  1182,  1183,  1184,  1187,  1188,
    1190,  1196,  1197,  1206,  1218,  1219,  1220,  1227,  1228,  1229,
    1230,  1231,  1232,  1237,  1238,  1240,  1241,  1242,  1243,  1253,
    1259,  1260,  1261,  1262,  1263,  1274,  1275,  1283,  1284,  1285,
    1291,  1299,  1306,  1308,  1312,  1313,  1315,  1320,  1346,  1347,
    1348,  1349,  1356,  1357,  1364,  1372,  1374,  1375,  1379,  1380,
    1387,  1388,  1391,  1393,  1396,  1402,  1409,  1412,  1418,  1423,
    1429,  1430,  1435,  1437,  1439,  1440,  1442,  1453,  1460,  1463,
    1464,  1465,  1467,  1469,  1472,  1476,  1478,  1502,  1503,  1505,
    1512,  1514,  1515,  1517,  1518,  1519,  1525,  1526,  1532,  1533,
    1535,  1538,  1541,  1542,  1544,  1546,  1554,  1556,  1559,  1572,
    1575,  1576,  1577,  1578,  1580,  1588,  1591,  1592,  1593,  1597,
    1599,  1603,  1604,  1606,  1607,  1609,  1613,  1616,  1618,  1622,
    1626,  1627,  1630,  1632,  1633,  1636,  1637,  1639,  1645,  1649,
    1654,  1655,  1658,  1661,  1664,  1666,  1667,  1669,  1670,  1671,
    1680,  1683,  1690,  1692,  1694,  1695,  1696,  1699,  1700,  1704,
    1710,  1711,  1714,  1723,  1728,  1732,  1733,  1734,  1736,  1739,
    1740,  1742,  1743,  1744,  1745,  1746,  1747,  1748,  1749,  1750,
    1751,  1752,  1756,  1761,  1762,  1763,  1764,  1765,  1772,  1775,
    1776,  1782,  1784,  1785,  1788,  1790,  1791,  1792,  1830,  1834,
    1841,  1842,  1845,  1850,  1857,  1858,  2206,  2218,  2228,  2229,
    2230,  2231,  2232,  2233,  2234,  2235,  2236,  2237,  2238,  2239,
    2240,  2241,  2242,  2243
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint16 yyr1[] =
{
       0,   294,   295,   296,   296,   296,   297,   297,   297,   298,
     298,   298,   298,   298,   298,   299,   299,   300,   300,   301,
     301,   301,   301,   302,   303,   303,   304,   304,   305,   305,
     306,   307,   307,   307,   307,   308,   308,   309,   309,   310,
     310,   311,   311,   312,   312,   312,   312,   312,   313,   314,
     314,   315,   315,   316,   316,   316,   316,   317,   318,   318,
     318,   318,   318,   318,   318,   318,   318,   318,   318,   318,
     319,   319,   320,   320,   321,   321,   322,   322,   322,   323,
     323,   324,   324,   325,   325,   325,   326,   326,   327,   327,
     327,   327,   327,   327,   327,   328,   328,   329,   329,   330,
     330,   331,   331,   332,   332,   333,   334,   334,   335,   335,
     336,   337,   337,   338,   339,   339,   340,   340,   341,   341,
     342,   342,   343,   343,   344,   345,   347,   346,   349,   348,
     348,   350,   350,   351,   351,   352,   352,   353,   353,   354,
     354,   355,   356,   357,   358,   358,   359,   360,   360,   360,
     360,   360,   360,   360,   361,   361,   361,   362,   362,   362,
     362,   362,   362,   362,   363,   363,   363,   363,   364,   364,
     364,   365,   365,   365,   366,   366,   366,   367,   367,   368,
     368,   368,   368,   368,   368,   369,   369,   370,   370,   371,
     371,   372,   372,   373,   374,   374,   375,   375,   376,   376,
     377,   378,   379,   380,   381,   381,   382,   382,   383,   383,
     383,   384,   384,   385,   385,   385,   386,   386,   386,   386,
     387,   388,   388,   389,   389,   390,   390,   391,   392,   392,
     392,   392,   392,   392,   392,   393,   394,   395,   396,   396,
     397,   397,   398,   399,   400,   401,   401,   401,   401,   401,
     401,   402,   402,   403,   403,   403,   404,   404,   405,   405,
     406,   406,   406,   406,   407,   407,   408,   408,   409,   409,
     410,   410,   411,   411,   412,   412,   413,   413,   414,   414,
     415,   416,   417,   417,   418,   418,   418,   418,   418,   418,
     418,   418,   418,   418,   418,   418,   419,   419,   419,   419,
     419,   419,   420,   420,   420,   420,   421,   421,   421,   421,
     422,   422,   422,   422,   423,   424,   424,   424,   425,   425,
     426,   426,   426,   426,   426,   426,   426,   426,   426,   426,
     426,   426,   426,   426,   426,   426,   426,   426,   426,   426,
     426,   426,   426,   426,   426,   426,   426,   427,   427,   428,
     428,   428,   428,   428,   429,   430,   431,   432,   432,   433,
     433,   433,   434,   434,   435,   435,   436,   436,   436,   436,
     437,   437,   437,   437,   438,   439,   439,   439,   439,   440,
     440,   441,   441,   441,   441,   441,   441,   441,   442,   442,
     442,   442,   442,   442,   442,   442,   443,   443,   443,   444,
     444,   445,   446,   447,   448,   449,   449,   450,   450,   451,
     452,   452,   452,   453,   454,   455,   456,   456,   457,   458,
     458,   459,   459,   459,   460,   461,   461,   462,   462,   463,
     464,   465,   465,   465,   465,   467,   468,   466,   469,   470,
     470,   471,   471,   471,   471,   472,   473,   474,   475,   475,
     476,   476,   476,   476,   477,   478,   478,   479,   479,   479,
     480,   480,   480,   481,   481,   481,   481,   481,   481,   481,
     481,   481,   481,   481,   481,   481,   481,   481,   481,   481,
     481,   481,   481,   481,   481,   481,   481,   481,   481,   481,
     481,   481,   481,   481,   481,   481,   481,   482,   482,   483,
     483,   484,   484,   485,   485,   485,   486,   486,   486,   487,
     487,   487,   487,   487,   487,   488,   488,   488,   488,   489,
     489,   490,   490,   490,   490,   491,   492,   492,   492,   492,
     492,   492,   492,   492,   493,   494,   494,   494,   494,   494,
     494,   494,   494,   494,   495,   495,   495,   495,   495,   495,
     495,   495,   496,   497,   498,   498,   499,   499,   500,   501,
     502,   502,   503,   503,   503,   504,   504,   504,   504,   504,
     504,   504,   504,   505,   506,   507,   508,   508,   508,   509,
     509,   510,   510,   510,   511,   511,   511,   511,   511,   511,
     511,   511,   512,   512,   512,   513,   514,   515,   515,   515,
     515,   516,   516,   516,   516,   516,   517,   517,   518,   518,
     518,   518,   518,   518,   518,   518,   518,   518,   518,   518,
     518,   518,   519,   519,   520,   520,   520,   520,   520,   520,
     521,   521
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
#define YYPACT_NINF -863
static const yytype_int16 yypact[] =
{
    2057,  -863,  -863,  -863,   139,  -863,   599,   139,   139,   599,
     599,   139,   636,   139,   139,   599,   636,   636,   636,   636,
    -863,   681,  -863,   139,  -863,  -863,   599,  -863,   147,   599,
     599,  -863,   599,   599,  -863,  -863,  -863,   599,   599,  -863,
    -863,   636,   599,   711,  -863,   139,   599,   723,   538,   -36,
     599,   538,  -863,  -863,  -863,  -863,  -863,  -863,  -863,  -863,
    -863,  -863,  -863,  -863,  -863,  -863,  -863,  -863,  -863,  -863,
    -863,  -863,  -863,  -863,  -863,  -863,  -863,   257,  -863,  -863,
    -863,    15,  -863,  -863,  -863,   253,    60,  -863,  -863,   427,
    -863,  -863,  -863,    47,   404,    66,   170,   270,  -863,  -863,
    -863,  -863,  -863,   113,   150,   164,   177,  -863,     2,  -863,
    -863,  -863,  -863,   308,  -863,  -863,    82,  -863,   317,  -863,
     335,    39,   599,  -863,   131,   267,   283,  -863,   384,   299,
    -863,  -863,  -863,  -863,   194,  -863,  -863,  -863,  -863,  -863,
     449,   449,  -863,  -863,  -863,  -863,   331,   323,   368,  -863,
     650,     6,   370,   391,   398,  -863,  2057,   749,  -863,  -863,
     663,   139,   757,   139,   139,   664,   625,   100,   675,  -863,
    -863,   143,   120,   206,   440,  -863,  -863,  -863,  -863,  -863,
    -863,  -863,  -863,   139,  -863,  -863,   825,   139,   599,   599,
     599,   599,     2,  -863,   295,   599,   295,    85,   437,   690,
     905,  -863,   523,  -863,  -863,  -863,   139,   139,   833,   139,
     139,  -863,  -863,    85,  -863,  -863,   232,   599,   635,  -863,
    -863,  -863,  -863,  -863,  1180,  1180,  1180,  1180,    61,    61,
      70,   232,   599,  -863,   455,   461,   463,  -863,   686,  -863,
     477,  -863,   504,  -863,  -863,   584,   608,   613,   659,   620,
     629,  -863,  -863,  -863,   692,   139,   530,  -863,  -863,  -863,
     295,  -863,  -863,  -863,  -863,   433,   139,  -863,  -863,   295,
     549,  -863,   404,  -863,   561,  -863,   580,   648,  -863,   678,
     691,   706,  -863,   -61,  -863,  -863,   -20,   711,     1,  -863,
    -863,   628,   -41,   643,  -863,  -863,  -863,   714,   632,  -863,
    -863,   841,   722,   728,  -863,  -863,  -863,   733,   543,  -863,
     676,   733,   734,  -863,   740,   743,  -863,    90,   744,   733,
    -863,   748,   761,   733,   733,   762,   763,   768,   769,  1827,
    1120,   773,  1827,   904,  -863,  -863,  -863,   693,   697,  -863,
    -863,  -863,  -863,  -863,  -863,  -863,   543,  -863,   543,  -863,
    -863,   602,  -863,  -863,    31,  -863,  -863,  -863,  -863,   421,
     859,   139,   344,  -863,   695,  -863,   704,  -863,   720,  -863,
      10,  -863,  -863,   721,  -863,  -863,   745,  -863,  1767,  1263,
    -863,    18,  -863,  -863,    28,   727,   727,   139,  -863,  -863,
      30,   108,   729,   784,  -863,   690,   905,  -863,   721,   712,
     139,   139,   749,  -863,   139,   850,    85,    85,    85,   126,
     692,    85,   905,   139,  -863,   144,   139,   184,  -863,  -863,
    -863,   796,   798,   799,   543,   543,  -863,   800,  -863,   802,
     805,   806,   807,   808,  -863,  -863,  -863,  -863,   811,   812,
     541,  -863,  -863,  -863,  -863,  -863,   187,  -863,  -863,   195,
     139,  -863,   139,   882,   139,   139,   139,   139,   861,   295,
      46,  -863,  -863,    85,    76,   995,   139,  -863,   -36,   892,
    -863,  1409,   139,   979,  1767,  1767,   801,  -863,  -863,  -863,
    -863,  -863,  -863,  -863,  -863,  -863,   735,   -36,   -55,  2053,
    -863,  1767,   180,  1767,  1767,   905,   197,  -863,  1767,  -863,
    1767,  1767,  -863,  -863,   180,  1767,   180,   180,   421,  -863,
     180,   421,  -863,   905,   905,   737,   -51,  1827,  -863,  1827,
    1827,  -863,  1827,  -863,   821,  1492,  -863,  -863,  1827,  -863,
     822,  -863,  1827,   373,  1767,    59,    75,  1767,  -863,  -863,
    -863,  -863,  -863,  -863,  1767,  1767,  1767,  1767,  -863,   433,
     249,  -863,   746,  -863,  -863,  -863,   139,   139,   931,  -863,
      85,   232,   232,   758,  -863,  -863,    20,   837,  -863,  1180,
    -863,  -863,   817,    61,    83,  -863,    61,  1180,  -863,   693,
     232,   750,  -863,  -863,  -863,   751,  -863,   840,   766,  -863,
     251,  -863,   256,  -863,   659,  -863,   286,   693,   845,  -863,
    -863,  -863,  -863,   295,  1009,  1009,  1014,   756,   -44,  1015,
    1021,  1022,  1024,  1015,  1015,  1025,  1026,  -863,  -863,  -863,
      99,  -863,   372,  -863,   139,  -863,   295,  -863,  -863,   767,
    -863,   290,  -863,    23,   293,   298,   315,  -863,    46,  -863,
    1028,  -863,  -863,  1029,  1030,  -863,    46,  -863,  -863,  -863,
     838,   -72,   772,     6,  -863,  -863,  -863,  -863,   352,   774,
    -863,   367,   369,   548,     6,  -863,  -863,   376,   865,   374,
    -863,  -863,  -863,  1767,   379,  -863,   -21,  -863,  -863,   380,
     390,   392,  1767,   400,  1767,  1767,  1767,   697,  -863,   548,
    1036,   548,   854,   421,   855,   857,   854,   122,  -863,  -863,
    -863,   855,   122,  -863,   857,  -863,  -863,  1767,  -863,  -863,
      59,  -863,  -863,   428,  1041,  -863,  -863,   117,  -863,  -863,
    -863,  -863,  -863,  -863,  -863,   139,   139,   862,  -863,  -863,
     786,  -863,  -863,  -863,   721,  1767,  -863,   139,  -863,  -863,
     863,  -863,  -863,   129,  -863,  -863,   -30,   139,   139,   906,
      85,  -863,    85,  -863,   692,  -863,  -863,  -863,  -863,   880,
     881,   407,   548,  1051,   548,  -863,   809,   884,   410,   885,
     888,   809,   889,   893,  -863,  -863,  -863,  -863,   599,  -863,
    -863,  -863,   879,  -863,  -863,   372,  -863,   692,  -863,  -863,
     139,    74,   139,  -863,  -863,    74,    74,    74,   861,  -863,
    -863,  -863,  -863,  -863,  -863,  -863,  1062,   139,  1767,  -863,
    1767,   139,  -863,  -863,   883,  -863,  -863,  -863,  -863,  -863,
    -863,  -863,  1767,   543,   803,  -863,  -863,  -863,   895,  -863,
    1767,  -863,  -863,  -863,   900,  -863,   901,   902,   908,  -863,
     909,  -863,    99,  -863,    99,  -863,    99,  -863,  -863,    69,
    -863,   422,  -863,  -863,  -863,   443,  -863,   832,   239,  -863,
    -863,  -863,    59,  -863,  -863,  -863,    59,  -863,    59,   139,
    -863,  -863,  1552,   139,  -863,   848,  -863,  1180,   139,  -863,
    -863,   681,  -863,  -863,  -863,  -863,  -863,  -863,  -863,  -863,
    -863,  -863,  1078,  -863,   911,  -863,  1080,   913,  -863,  -863,
    1082,  -863,  -863,   915,  -863,  -863,  -863,   907,   905,  -863,
    -863,  -863,  -863,  -863,  1030,  1085,  -863,    74,  -863,  -863,
    -863,  -863,  -863,  -863,   910,   838,   255,  -863,   899,  1092,
     255,   829,   548,  -863,  -863,  -863,  -863,  -863,  -863,   831,
    -863,  -863,  -863,  -863,  -863,  -863,  -863,   158,  -863,  1767,
    -863,   265,   585,   550,   912,  -863,   448,  -863,  -863,  -863,
     599,     9,   886,   450,   838,  -863,   928,   834,  -863,  -863,
    -863,   929,  -863,    85,   932,  -863,  -863,  -863,  -863,  -863,
    -863,    59,   933,   934,   548,  -863,   548,  -863,  -863,  -863,
    -863,    59,    59,  -863,  1552,    72,  -863,    48,    93,   905,
     905,  -863,   313,  -863,  -863,   919,   215,   145,  -863,  -863,
    -863,   548,  -863,   456,  -863,   595,  -863,  -863,  -863,  -863,
     342,   597,  -863,   103,   103,    89,   139,  -863,  -863,  -863,
      79,  -863,  -863,  -863,   853,  -863,   846,   567,   693,   693,
    -863,  -863,  -863,  -863,  -863,   916,   139,   851,   954,  -863,
    -863,  -863,  -863,    59,  -863,  -863,    59,   599,    72,   847,
     852,   123,  -863,  -863,  -863,    93,    88,  -863,   -36,  -863,
     982,  -863,    97,   139,   494,   688,    81,   905,   905,   599,
    -863,  -863,  -863,   838,     6,  -863,  -863,  -863,  -863,   866,
    -863,   271,   982,  -863,  -863,  -863,   693,   693,   104,  -863,
    1767,    97,  -863,  -863,  -863,  -863,  -863,   255,  -863,   886,
    -863
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -863,  -863,  -863,  -863,  -863,  -863,  -168,   732,   544,  -863,
    -182,    96,  -863,  -863,  -863,  -863,   487,  -863,   481,   216,
    -160,  -863,   214,   511,  -863,   334,    41,   447,   346,   938,
    -133,  -863,  -863,   864,  -863,  -242,  -863,  -863,  -863,  -243,
    -863,  -863,  -209,  -863,  -863,  -863,  -863,  -355,  -863,   891,
     725,  -863,  -863,  -863,  -863,  -863,  -863,  -863,   418,  -863,
     153,  -863,  -863,  -863,  -863,  -863,  -863,  -863,  -863,  -863,
    1098,  -863,  1100,  -863,   935,  1013,  -863,  -156,   596,  -863,
    -863,  -863,  -863,  -863,  -863,   412,  -863,  -863,   183,  -863,
     178,  -131,  -863,  -863,  -863,  -863,  -863,   381,  -863,  -863,
    -863,  -863,  -863,    63,   159,  -863,  -863,  -862,   148,  -772,
    -782,  -863,   165,  -199,   658,   660,   843,  -863,   485,   473,
     484,   453,    94,  -863,  -863,  -863,  -863,   377,  -863,   633,
    -863,  -863,  -863,   416,  -863,   583,  -253,  -863,    -1,  -370,
    -165,  -625,   160,   914,   163,  -556,  -863,  -290,  -568,  -863,
    -863,   981,   637,  -863,  -863,  -863,  -863,  -863,  -863,  -863,
    -863,  -863,  -863,    91,  -863,  -863,  -863,  -863,   133,   288,
    -863,  -863,  -863,  -863,  -863,  -863,    95,  -863,   121,   844,
     -53,  -438,  -617,  -751,  -863,   464,  -158,  -863,  -863,   707,
     396,   536,  -863,  -863,  -863,   505,   261,   -27,  -863,    44,
    -863,   947,    -4,   814,   361,  -863,  -863,  -863,  -863,  -863,
    1055,  -863,  1198,  -863,  -863,  -863,   813,  -863,  -460,  -863,
    -863,  -622,  -863,  -863,  -863,   -47,  -863,  -863
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
     388,   284,   709,   284,   775,    84,   383,   383,   383,   383,
     113,   930,   944,   116,   117,   398,   118,   119,   880,    84,
      84,   120,   121,    84,   299,   125,   124,    84,   858,    84,
     131,   125,    84,    84,   152,    86,  1029,    84,   995,   125,
    1087,    84,   296,   125,    84,   774,  1023,    84,   805,    86,
     458,   488,   640,  1024,   299,  1023,   665,   410,    89,   912,
     913,   839,  1024,   841,    84,   296,    84,    84,   298,    86,
      37,   641,   642,   690,   607,   608,   270,   299,  1023,   300,
     763,   850,   301,    84,   980,  1024,   850,    84,   983,   199,
     114,   460,   489,   235,   465,   157,   158,   239,   241,   242,
     243,   296,    84,   258,   298,   220,   202,   265,   268,   265,
     998,   193,   462,   299,   150,   300,   643,   806,   301,   273,
     395,   559,   275,   276,    89,    89,    89,    89,   459,   568,
     265,    89,   265,   292,   893,  1076,   895,   579,   999,   570,
      48,   572,   363,   365,   367,   368,   130,   208,   221,   292,
      84,   513,   111,    89,    51,   830,   691,  1098,   209,   561,
     566,   567,   466,   764,   391,   391,   535,   111,    89,   459,
    1000,   881,   278,   278,   278,   278,    84,   853,   107,   285,
     951,   589,   853,   710,   952,   513,   953,   203,   793,   222,
     463,   258,  1095,  1062,   477,   282,   265,   155,   490,   560,
     200,   376,   268,   184,   185,   265,   499,   569,   204,   794,
     502,   503,   308,   156,   245,  1106,   399,   569,   246,   573,
     804,   737,   508,   292,   255,   511,   941,  1057,   941,  1080,
     941,   396,   715,   649,   536,   308,   676,   593,   648,    84,
     742,  1046,   247,   465,   266,  1082,   160,  1079,  1061,  1026,
     644,   165,   868,   657,   711,   600,   657,   657,   494,   712,
     387,  1025,   487,   161,   465,  1109,   639,   260,   495,   183,
    1025,   308,   333,   667,   195,   657,   675,   245,   914,   670,
     657,   246,   657,   657,   287,   249,   915,   657,   211,  1107,
     716,   250,  1030,  1025,  1031,   602,  1030,   552,   623,  1015,
     770,   771,   333,  1047,   985,   247,   625,   700,  1031,  1020,
    1021,   574,  1031,   879,  1042,   594,   708,   849,   188,   718,
     869,   788,   671,   391,   789,   333,   719,   720,   721,   722,
     269,   850,   878,   416,   757,   732,   581,   582,   235,   888,
     584,   586,   292,   292,   292,   741,   734,   292,   249,   599,
     950,   383,   258,   849,   250,   189,  1018,  1043,  1019,   383,
     724,   333,   751,   672,   746,   494,   245,   753,   372,   190,
     246,  1074,   910,   603,  1075,   495,   624,   224,   225,   226,
     227,   228,   191,  1050,   626,   989,   627,  1088,   628,   630,
     633,   633,   633,   633,   247,   265,   860,   755,  1044,   292,
     650,   791,   652,   754,   795,   861,   677,  1100,   659,   796,
     693,   698,   693,   693,   998,   693,  1088,   703,   166,   167,
     537,   693,   860,   776,   960,   693,   797,   853,   168,   169,
     170,   861,   194,   270,   863,   864,  1102,   249,   725,   865,
     752,   196,   999,   250,   735,   752,   705,   777,   538,   539,
     540,   541,   542,   543,   419,   828,   778,  1103,   186,   197,
     863,   864,  1054,   809,   834,   865,   836,   837,   838,   187,
     206,   779,   717,   931,   478,   752,   478,   780,   812,   792,
     813,   706,   792,   707,   468,  -503,   207,   792,   553,   857,
     829,   831,   365,   729,   731,   979,   292,   111,   111,   860,
     216,   832,   738,   833,   792,   479,   210,   479,   861,   391,
     743,   835,   391,   480,   781,   480,   111,   566,   891,   420,
     782,   899,   421,   422,   423,   886,   592,   887,   217,   596,
     481,   424,   481,   946,  1009,   425,   171,   863,   864,   265,
     426,   810,   865,    84,   482,    86,   482,   427,   859,   428,
     429,   229,   430,   483,   948,   483,   810,   218,   810,   993,
     268,  1008,   265,   823,   484,   823,   484,  1051,   810,   810,
    1084,   172,   208,   213,   431,   920,   921,   922,   544,   810,
      84,   810,    95,   209,   432,   860,   173,   545,   433,   810,
     566,   135,   927,   219,   861,   434,   892,   435,   231,   900,
     617,   618,   619,   232,   566,   739,   436,  1067,   437,   238,
     244,   947,   934,   745,  1093,   162,   546,   862,   259,   296,
     297,   547,   298,   863,   864,    84,   163,   107,   865,   272,
     164,   299,   947,   300,   294,   963,   301,   994,   293,   569,
     279,   280,   281,   478,   136,   750,   438,   361,   814,   439,
     137,   860,   402,  1099,   958,    84,   620,   125,   400,   383,
     861,   552,   871,   138,   401,   302,   303,   132,   139,   133,
     990,   304,   305,   876,   479,  -282,   517,   403,   140,   815,
     404,   141,   480,   883,   884,   142,   292,   816,   292,   863,
     864,   143,   405,    84,   865,   234,   245,   518,   306,   481,
     246,    84,   465,   240,   817,   519,   520,   860,   406,   413,
    -282,   521,  -282,   482,    89,  1052,   861,  1055,   818,   416,
     522,   144,   483,   523,   247,   524,   911,   819,   633,   145,
     245,   988,   407,   484,   246,   525,   526,   408,   820,   991,
    1038,  1039,   860,   925,   411,   863,   864,   928,   589,   248,
     865,   861,   860,   412,   860,   208,   527,   450,   247,   307,
     138,   861,   907,   861,   452,   139,   209,   249,   453,    84,
    -528,   274,   454,   250,   528,   140,   958,    84,   141,   366,
     863,   864,   142,   468,  1053,   865,  1056,   473,   143,   308,
     863,   864,   863,   864,    84,   865,   585,   865,   309,   529,
     310,   249,   455,   311,   312,   954,   530,   250,  1094,   959,
     661,   662,   531,   532,   964,   456,   487,   111,  1096,  1097,
     965,   682,   313,   684,   685,   314,    84,   686,   629,   674,
     457,   464,   315,   316,   679,   472,   680,   681,   471,   317,
     318,   683,   634,   635,   636,   860,   474,   512,   296,   297,
     319,   298,   475,   320,   861,   321,   322,   476,   491,   323,
     299,   324,   300,   325,   492,   301,   326,   493,   498,   327,
     328,   329,   500,   330,   331,    84,   332,   730,   942,   333,
     943,   514,   566,   863,   864,   501,   504,   505,   865,   334,
     335,   336,   506,   507,   302,   303,    89,   510,   549,   513,
     304,   305,   556,   103,   104,   105,   106,   557,   558,   292,
     561,  1036,   694,   695,   562,   696,   569,   577,   576,   580,
     604,   701,   605,   606,   609,   704,   610,   306,   123,   611,
     612,   613,   614,  1028,  1037,   615,   616,   637,   651,   654,
     660,   487,   663,  1036,   689,   697,   702,   735,   666,   726,
     740,   749,   758,   747,   748,   750,   756,   761,   765,    89,
      89,    89,  1028,   762,   767,   768,  1037,   769,   772,   773,
     790,   799,   800,   465,   801,   807,   826,   811,  1036,   840,
     842,   844,  1071,   846,   867,  1036,   872,   877,   307,   873,
     778,   889,   890,    89,   894,   898,   901,    89,   896,   902,
     904,  1037,  1083,   908,   905,   924,   933,   929,  1037,  1071,
     932,   935,   936,   937,  1036,    89,   949,   960,   308,   938,
     939,   966,   967,   968,   970,   971,   972,   309,   976,   310,
     978,   973,   311,   312,   981,   982,   984,  1037,   986,  1010,
    1012,  1011,  1065,  1014,  1016,  1017,  1006,   992,   999,  1066,
    1073,   313,  1077,  1072,   314,  1101,  1068,  1078,  1085,   571,
     744,   315,   316,   296,   297,   798,   298,   803,   317,   318,
     975,   977,   923,  1105,   286,   299,   451,   300,   919,   319,
     301,   601,   320,   870,   321,   322,   415,  1022,   323,   153,
     324,   154,   325,   377,   215,   326,  1013,   733,   327,   328,
     329,   885,   330,   331,  1041,   332,   909,  1040,   333,   302,
     303,   687,  1060,   509,   688,   304,   305,   856,   334,   335,
     336,   848,   723,   296,   297,   854,   298,   903,   760,  1063,
    1064,   369,  1108,   728,  1092,   299,   974,   300,  1081,   874,
     301,   461,   306,   678,  1110,   827,   555,   855,   987,   578,
     945,   233,   101,     0,     0,   583,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   302,
     303,     0,     0,     0,     0,   304,   305,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   306,   307,     0,     0,   296,   297,     0,   298,
       0,     0,     0,     0,     0,     0,     0,     0,   299,     0,
     300,     0,     0,   301,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   308,     0,     0,     0,     0,     0,     0,
       0,     0,   309,     0,   310,     0,     0,   311,   312,     0,
       0,     0,   302,   303,     0,     0,     0,     0,   304,   305,
       0,     0,     0,     0,     0,     0,   313,     0,     0,   314,
       0,     0,     0,     0,     0,     0,   315,   316,     0,     0,
       0,     0,     0,   317,   318,   306,     0,     0,     0,     0,
       0,     0,     0,   308,   319,     0,     0,   320,     0,   321,
     322,     0,   309,   323,   379,   324,     0,   325,   312,     0,
     326,     0,     0,   327,   328,   329,     0,     0,   331,     0,
     332,     0,     0,   333,     0,   380,   313,     0,     0,   314,
       0,     0,     0,   334,   335,   336,   315,   316,     0,     0,
       0,     0,     0,   317,   318,     0,     0,     0,     0,     0,
       0,     0,   296,   297,   319,   298,     0,   320,     0,   321,
     322,     0,     0,   323,   299,   324,   300,   325,     0,   301,
     326,     0,     0,   327,   328,   329,   308,     0,   331,     0,
     332,     0,     0,   333,     0,   309,     0,   379,     0,     0,
       0,   312,     0,   334,   335,   336,     0,     0,   302,   303,
       0,     0,     0,   487,   304,   305,     0,     0,     0,   313,
       0,     0,   314,     0,     0,     0,     0,     0,     0,   315,
     316,     0,     0,     0,     0,     0,   317,   318,     0,     0,
       0,   306,     0,     0,     0,   296,   297,   319,   298,     0,
     320,     0,   321,   322,     0,     0,   323,   299,   324,   300,
     325,     0,   301,   326,     0,     0,   327,   328,   329,     0,
       0,   331,     0,   332,     0,     0,   333,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   334,   335,   336,     0,
       0,   302,   303,     0,     0,     0,     0,   304,   305,     0,
       0,     0,     0,     0,     0,   296,   297,     0,   298,     0,
       0,     0,     0,     0,     0,     0,     0,   299,     0,   300,
       0,     0,   301,     0,   306,     0,     0,     0,     0,     0,
     656,     0,   308,     0,     0,     0,     0,     0,     0,     0,
       0,   309,     0,   379,     0,     0,     0,   312,     0,     0,
       0,   302,   303,     0,     0,     0,     0,   304,   305,     0,
       0,     0,     0,     0,     0,   313,     0,     0,   314,     0,
       0,     0,     0,     0,     0,   315,   316,     0,     0,     0,
       0,     0,   317,   318,   306,     0,     0,     0,     0,     0,
       0,     0,     0,   319,     0,     0,   320,     0,   321,   322,
       0,     0,   323,     0,   324,     0,   325,     0,     0,   326,
       0,     0,   327,   328,   329,   308,     0,   331,     0,   332,
       0,     0,   333,     0,   309,     0,   379,     0,     0,     0,
     312,     0,   334,   335,   336,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   699,   313,     0,
       0,   314,     0,     0,     0,     0,     0,     0,   315,   316,
       0,     0,     0,     0,     0,   317,   318,     0,     0,     0,
       0,     0,     0,     0,     0,   308,   319,     0,     0,   320,
       0,   321,   322,     0,   309,   323,   379,   324,     0,   325,
     312,     0,   326,     0,     0,   327,   328,   329,     0,     0,
     331,     0,   332,     0,     0,   333,     0,   955,   313,     0,
       0,   314,     0,     0,     0,   334,   335,   336,   315,   316,
     296,   297,     0,   298,     0,   317,   318,     0,     0,     0,
       0,     0,   299,     0,   300,     0,   319,   301,     0,   320,
       0,   321,   322,     0,     0,   323,     0,   324,     0,   325,
       0,     0,   326,     0,     0,   327,   328,   329,     0,     0,
     331,     0,   332,     0,     0,   333,   302,   303,     0,     0,
       0,     0,   304,   305,     0,   334,   335,   336,     0,     0,
     296,   297,     0,   298,     0,     0,     0,     0,     0,     0,
       0,     0,   299,     0,   300,     0,     0,   301,     0,   306,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   302,   303,     0,     0,
       0,     0,   304,   305,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   306,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     308,     0,     0,     0,     0,     0,     0,     0,     0,   309,
       0,   379,     0,     0,     0,   312,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   313,     0,     0,   314,     0,     0,     0,
       0,     0,     0,   315,   316,     0,     0,     0,     0,     0,
     317,   318,     0,     0,     0,     0,     0,     0,     0,     0,
     308,   319,     0,     0,   320,     0,   321,   322,     0,   309,
     323,   379,   324,     0,   325,   312,     0,   326,     0,     0,
     327,   328,   329,     0,     0,   331,     0,   332,     0,     0,
     333,     0,     0,   313,     0,     0,   314,     0,     0,     0,
     334,   335,   336,   315,   316,     0,     0,     0,     0,     0,
     317,   318,     0,     0,     0,     0,     0,  -565,     1,     0,
       0,   319,     0,     0,   320,     0,   321,   322,     0,     0,
     323,     0,   324,  -565,   325,     0,     0,   326,     0,     0,
     327,   328,     0,     0,     0,   331,     0,     0,     0,     0,
     333,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     334,   335,   336,     0,     2,     3,     0,     0,     0,     4,
       0,     5,     0,     0,     6,     7,     0,     8,     9,    10,
       0,    11,    12,     0,     0,     0,     0,     0,     0,    13,
      14,     0,     0,    15,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    16,    17,    18,    19,     0,    20,    21,    22,
      23,    24,    25,    26,     0,     0,    27,     0,     0,    28,
       0,    29,    30,     0,    31,    32,     0,     0,     0,     0,
       0,    33,    34,    35,    36,    37,    38,   517,     0,    39,
       0,     0,     0,     0,     0,    40,    41,     0,     0,    42,
       0,     0,    43,     0,    44,    45,     0,     0,   518,     0,
      46,     0,     0,     0,    47,     0,   519,   520,     0,     0,
       0,     0,   521,     0,   666,     0,     0,     0,     0,     0,
       0,   522,     0,     0,   523,     0,   524,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   525,   526,     0,     0,
       0,     0,     0,     0,     0,    48,     0,    49,     0,     0,
      50,     0,     0,     0,     0,     0,     0,   527,     0,    51,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   528,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  -305,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     529,     0,     0,     0,     0,     0,     0,   530,     0,  -305,
       0,     0,     0,   531,   532
};

static const yytype_int16 yycheck[] =
{
       4,   200,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    43,    21,   308,    23,
      21,   391,    26,   266,     4,    29,    30,   269,    32,    33,
     468,   491,   197,    37,    38,   166,   653,    41,    42,    43,
     173,    45,    46,   225,   226,   227,    50,   664,   213,   487,
       6,   260,     4,     9,    10,   410,   346,   808,   348,    15,
     228,   194,     3,   196,   620,     4,   224,   225,   226,   227,
      26,   822,     3,    29,    30,   231,    32,    33,   108,     4,
       4,    37,    38,     4,    15,     6,    42,     4,   710,     4,
      46,     6,     4,     4,    50,     6,     3,     4,   960,     6,
       3,     4,     3,     6,     4,     6,    34,     4,   180,     6,
     171,   310,    66,    41,    15,    34,   171,   248,   122,    45,
      46,   689,    41,   691,     4,     3,     4,     4,     6,     6,
     128,    85,    86,   184,   424,   425,   269,    15,    34,    17,
     184,   697,    20,     4,   926,    41,   702,     4,   930,   110,
       3,   171,   310,   157,   195,   140,   141,   161,   162,   163,
     164,     3,     4,   167,     6,   159,   122,   171,   172,   173,
     161,   108,   171,    15,   210,    17,   130,   249,    20,   183,
     110,   171,   186,   187,   188,   189,   190,   191,   249,   171,
     194,   195,   196,   197,   762,  1057,   764,   396,   189,   171,
     198,   171,   206,   207,   208,   209,   210,   248,   202,   213,
       4,   266,   216,   217,   212,   236,   267,  1079,   259,   249,
     378,   379,   263,   267,   228,   229,   195,   231,   232,   249,
     221,   261,   188,   189,   190,   191,     4,   697,     6,   195,
     862,   406,   702,   184,   866,   266,   868,   116,   225,   243,
     249,   255,   171,  1025,   307,   192,   260,     0,   311,   249,
     221,   217,   266,    93,    94,   269,   319,   249,   137,   246,
     323,   324,   173,    16,   131,   171,   232,   249,   135,   249,
     650,   261,   329,   287,   184,   332,   842,   184,   844,  1061,
     846,   221,   217,   217,   263,   173,   495,   171,   463,     4,
     217,   156,   159,   195,   184,   217,    53,   184,   219,   261,
     264,   264,   195,   471,   255,   171,   474,   475,   228,   260,
     259,   249,   200,   263,   195,  1107,   459,   184,   238,   263,
     249,   173,   263,   491,   252,   493,   494,   131,   264,   159,
     498,   135,   500,   501,   259,   202,   272,   505,   154,  1100,
     275,   208,   259,   249,   275,   171,   259,   361,   171,   981,
     613,   614,   263,   218,   932,   159,   171,   525,   275,   991,
     992,   263,   275,   743,   159,   249,   534,   255,   265,   537,
     263,   624,   202,   387,   626,   263,   544,   545,   546,   547,
     184,   947,   263,   249,   603,   560,   400,   401,   402,   754,
     404,   405,   406,   407,   408,   573,   562,   411,   202,   413,
     171,   569,   416,   255,   208,   265,   984,   202,   986,   577,
     171,   263,   171,   243,   580,   228,   131,   171,   196,   265,
     135,  1053,   787,   249,  1056,   238,   249,    67,    68,    69,
      70,    71,   265,  1011,   249,   180,   450,  1072,   452,   453,
     454,   455,   456,   457,   159,   459,   217,   171,   243,   463,
     464,   171,   466,   594,   171,   226,   269,  1084,   472,   171,
     517,   524,   519,   520,   161,   522,  1101,   530,    74,    75,
      59,   528,   217,   111,   229,   532,   171,   947,    84,    85,
      86,   226,   184,   626,   255,   256,   225,   202,   249,   260,
     249,   184,   189,   208,   249,   249,   133,   135,    87,    88,
      89,    90,    91,    92,    81,   673,   144,   246,   248,   184,
     255,   256,   180,   171,   682,   260,   684,   685,   686,   259,
     263,   159,   536,   823,   160,   249,   160,   165,   171,   249,
     171,   168,   249,   170,   200,   171,   263,   249,   204,   707,
     171,   171,   556,   557,   558,   925,   560,   561,   562,   217,
     229,   171,   566,   171,   249,   191,   267,   191,   226,   573,
     574,   171,   576,   199,   202,   199,   580,   735,   171,   146,
     208,   171,   149,   150,   151,   750,   408,   752,   265,   411,
     216,   158,   216,   171,   964,   162,   192,   255,   256,   603,
     167,   249,   260,     4,   230,     6,   230,   174,   180,   176,
     177,   241,   179,   239,   171,   239,   249,   249,   249,   171,
     624,   171,   626,   249,   250,   249,   250,   171,   249,   249,
    1068,   227,   248,   184,   201,   795,   796,   797,   217,   249,
       4,   249,     6,   259,   211,   217,   242,   226,   215,   249,
     808,   113,   810,     3,   226,   222,   249,   224,   267,   249,
     119,   120,   121,   265,   822,   569,   233,  1037,   235,     6,
       6,   249,   830,   577,   180,   248,   255,   249,     3,     3,
       4,   260,     6,   255,   256,     4,   259,     6,   260,   249,
     263,    15,   249,    17,     4,   877,    20,   249,   261,   249,
     189,   190,   191,   160,   166,   249,   273,   184,   160,   276,
     172,   217,   249,  1083,   872,     4,   175,     6,   263,   877,
     226,   725,   726,   185,   263,    49,    50,     4,   190,     6,
     180,    55,    56,   737,   191,   133,   134,    51,   200,   191,
     263,   203,   199,   747,   748,   207,   750,   199,   752,   255,
     256,   213,   248,     4,   260,     6,   131,   155,    82,   216,
     135,     4,   195,     6,   216,   163,   164,   217,   184,    77,
     168,   169,   170,   230,   778,   180,   226,   180,   230,   249,
     178,   243,   239,   181,   159,   183,   790,   239,   792,   251,
     131,   949,   184,   250,   135,   193,   194,   184,   250,   249,
     999,  1000,   217,   807,   184,   255,   256,   811,   973,   184,
     260,   226,   217,   184,   217,   248,   214,   268,   159,   143,
     185,   226,   778,   226,   263,   190,   259,   202,   248,     4,
     263,     6,   184,   208,   232,   200,   994,     4,   203,     6,
     255,   256,   207,   200,   249,   260,   249,     6,   213,   173,
     255,   256,   255,   256,     4,   260,     6,   260,   182,   257,
     184,   202,   184,   187,   188,   869,   264,   208,   180,   873,
     474,   475,   270,   271,   878,   184,   200,   881,  1077,  1078,
     881,   504,   206,   506,   507,   209,     4,   510,     6,   493,
     184,   263,   216,   217,   498,   263,   500,   501,   184,   223,
     224,   505,   455,   456,   457,   217,   184,     3,     3,     4,
     234,     6,   184,   237,   226,   239,   240,   184,   184,   243,
      15,   245,    17,   247,   184,    20,   250,   184,   184,   253,
     254,   255,   184,   257,   258,     4,   260,     6,   844,   263,
     846,   244,  1100,   255,   256,   184,   184,   184,   260,   273,
     274,   275,   184,   184,    49,    50,   960,   184,    99,   266,
      55,    56,   267,    16,    17,    18,    19,   263,   248,   973,
     249,   998,   519,   520,   229,   522,   249,   193,   249,   267,
     184,   528,   184,   184,   184,   532,   184,    82,    41,   184,
     184,   184,   184,   997,   998,   184,   184,   136,     3,   107,
      21,   200,   267,  1030,   267,   184,   184,   249,   171,   263,
     193,   171,     3,   263,   263,   249,   171,     3,     3,  1023,
    1024,  1025,  1026,   267,     3,     3,  1030,     3,     3,     3,
     263,     3,     3,   195,     4,   263,   171,   263,  1065,     3,
     186,   186,  1046,   186,     3,  1072,   184,   184,   143,   263,
     144,   171,   171,  1057,     3,   171,   171,  1061,   249,   171,
     171,  1065,  1066,   184,   171,     3,   171,   184,  1072,  1073,
     267,   171,   171,   171,  1101,  1079,   244,   229,   173,   171,
     171,     3,   171,     3,   171,     3,   171,   182,     3,   184,
     180,   184,   187,   188,   195,     3,   267,  1101,   267,   171,
     171,   267,   249,   171,   171,   171,   220,   195,   189,   263,
     156,   206,   265,   262,   209,   249,   200,   265,   136,   387,
     576,   216,   217,     3,     4,   638,     6,   646,   223,   224,
     914,   917,   798,  1092,   196,    15,   272,    17,   792,   234,
      20,   416,   237,   725,   239,   240,   255,   994,   243,    51,
     245,    51,   247,   218,   141,   250,   973,   561,   253,   254,
     255,   749,   257,   258,  1005,   260,   785,  1002,   263,    49,
      50,   513,  1024,   330,   514,    55,    56,   704,   273,   274,
     275,   696,   549,     3,     4,   701,     6,   771,   605,  1026,
    1030,   210,  1101,   556,  1073,    15,   908,    17,  1065,   735,
      20,   287,    82,   496,  1109,   669,   362,   702,   947,   395,
     849,   156,    14,    -1,    -1,   402,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    49,
      50,    -1,    -1,    -1,    -1,    55,    56,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    82,   143,    -1,    -1,     3,     4,    -1,     6,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    15,    -1,
      17,    -1,    -1,    20,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   173,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   182,    -1,   184,    -1,    -1,   187,   188,    -1,
      -1,    -1,    49,    50,    -1,    -1,    -1,    -1,    55,    56,
      -1,    -1,    -1,    -1,    -1,    -1,   206,    -1,    -1,   209,
      -1,    -1,    -1,    -1,    -1,    -1,   216,   217,    -1,    -1,
      -1,    -1,    -1,   223,   224,    82,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   173,   234,    -1,    -1,   237,    -1,   239,
     240,    -1,   182,   243,   184,   245,    -1,   247,   188,    -1,
     250,    -1,    -1,   253,   254,   255,    -1,    -1,   258,    -1,
     260,    -1,    -1,   263,    -1,   205,   206,    -1,    -1,   209,
      -1,    -1,    -1,   273,   274,   275,   216,   217,    -1,    -1,
      -1,    -1,    -1,   223,   224,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,     3,     4,   234,     6,    -1,   237,    -1,   239,
     240,    -1,    -1,   243,    15,   245,    17,   247,    -1,    20,
     250,    -1,    -1,   253,   254,   255,   173,    -1,   258,    -1,
     260,    -1,    -1,   263,    -1,   182,    -1,   184,    -1,    -1,
      -1,   188,    -1,   273,   274,   275,    -1,    -1,    49,    50,
      -1,    -1,    -1,   200,    55,    56,    -1,    -1,    -1,   206,
      -1,    -1,   209,    -1,    -1,    -1,    -1,    -1,    -1,   216,
     217,    -1,    -1,    -1,    -1,    -1,   223,   224,    -1,    -1,
      -1,    82,    -1,    -1,    -1,     3,     4,   234,     6,    -1,
     237,    -1,   239,   240,    -1,    -1,   243,    15,   245,    17,
     247,    -1,    20,   250,    -1,    -1,   253,   254,   255,    -1,
      -1,   258,    -1,   260,    -1,    -1,   263,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   273,   274,   275,    -1,
      -1,    49,    50,    -1,    -1,    -1,    -1,    55,    56,    -1,
      -1,    -1,    -1,    -1,    -1,     3,     4,    -1,     6,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    15,    -1,    17,
      -1,    -1,    20,    -1,    82,    -1,    -1,    -1,    -1,    -1,
     171,    -1,   173,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   182,    -1,   184,    -1,    -1,    -1,   188,    -1,    -1,
      -1,    49,    50,    -1,    -1,    -1,    -1,    55,    56,    -1,
      -1,    -1,    -1,    -1,    -1,   206,    -1,    -1,   209,    -1,
      -1,    -1,    -1,    -1,    -1,   216,   217,    -1,    -1,    -1,
      -1,    -1,   223,   224,    82,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   234,    -1,    -1,   237,    -1,   239,   240,
      -1,    -1,   243,    -1,   245,    -1,   247,    -1,    -1,   250,
      -1,    -1,   253,   254,   255,   173,    -1,   258,    -1,   260,
      -1,    -1,   263,    -1,   182,    -1,   184,    -1,    -1,    -1,
     188,    -1,   273,   274,   275,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   205,   206,    -1,
      -1,   209,    -1,    -1,    -1,    -1,    -1,    -1,   216,   217,
      -1,    -1,    -1,    -1,    -1,   223,   224,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   173,   234,    -1,    -1,   237,
      -1,   239,   240,    -1,   182,   243,   184,   245,    -1,   247,
     188,    -1,   250,    -1,    -1,   253,   254,   255,    -1,    -1,
     258,    -1,   260,    -1,    -1,   263,    -1,   205,   206,    -1,
      -1,   209,    -1,    -1,    -1,   273,   274,   275,   216,   217,
       3,     4,    -1,     6,    -1,   223,   224,    -1,    -1,    -1,
      -1,    -1,    15,    -1,    17,    -1,   234,    20,    -1,   237,
      -1,   239,   240,    -1,    -1,   243,    -1,   245,    -1,   247,
      -1,    -1,   250,    -1,    -1,   253,   254,   255,    -1,    -1,
     258,    -1,   260,    -1,    -1,   263,    49,    50,    -1,    -1,
      -1,    -1,    55,    56,    -1,   273,   274,   275,    -1,    -1,
       3,     4,    -1,     6,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    15,    -1,    17,    -1,    -1,    20,    -1,    82,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    49,    50,    -1,    -1,
      -1,    -1,    55,    56,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    82,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     173,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   182,
      -1,   184,    -1,    -1,    -1,   188,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   206,    -1,    -1,   209,    -1,    -1,    -1,
      -1,    -1,    -1,   216,   217,    -1,    -1,    -1,    -1,    -1,
     223,   224,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     173,   234,    -1,    -1,   237,    -1,   239,   240,    -1,   182,
     243,   184,   245,    -1,   247,   188,    -1,   250,    -1,    -1,
     253,   254,   255,    -1,    -1,   258,    -1,   260,    -1,    -1,
     263,    -1,    -1,   206,    -1,    -1,   209,    -1,    -1,    -1,
     273,   274,   275,   216,   217,    -1,    -1,    -1,    -1,    -1,
     223,   224,    -1,    -1,    -1,    -1,    -1,     0,     1,    -1,
      -1,   234,    -1,    -1,   237,    -1,   239,   240,    -1,    -1,
     243,    -1,   245,    16,   247,    -1,    -1,   250,    -1,    -1,
     253,   254,    -1,    -1,    -1,   258,    -1,    -1,    -1,    -1,
     263,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     273,   274,   275,    -1,    47,    48,    -1,    -1,    -1,    52,
      -1,    54,    -1,    -1,    57,    58,    -1,    60,    61,    62,
      -1,    64,    65,    -1,    -1,    -1,    -1,    -1,    -1,    72,
      73,    -1,    -1,    76,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    95,    96,    97,    98,    -1,   100,   101,   102,
     103,   104,   105,   106,    -1,    -1,   109,    -1,    -1,   112,
      -1,   114,   115,    -1,   117,   118,    -1,    -1,    -1,    -1,
      -1,   124,   125,   126,   127,   128,   129,   134,    -1,   132,
      -1,    -1,    -1,    -1,    -1,   138,   139,    -1,    -1,   142,
      -1,    -1,   145,    -1,   147,   148,    -1,    -1,   155,    -1,
     153,    -1,    -1,    -1,   157,    -1,   163,   164,    -1,    -1,
      -1,    -1,   169,    -1,   171,    -1,    -1,    -1,    -1,    -1,
      -1,   178,    -1,    -1,   181,    -1,   183,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   193,   194,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   198,    -1,   200,    -1,    -1,
     203,    -1,    -1,    -1,    -1,    -1,    -1,   214,    -1,   212,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   232,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   244,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     257,    -1,    -1,    -1,    -1,    -1,    -1,   264,    -1,   266,
      -1,    -1,    -1,   270,   271
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
{
       0,     1,    47,    48,    52,    54,    57,    58,    60,    61,
      62,    64,    65,    72,    73,    76,    95,    96,    97,    98,
     100,   101,   102,   103,   104,   105,   106,   109,   112,   114,
     115,   117,   118,   124,   125,   126,   127,   128,   129,   132,
     138,   139,   142,   145,   147,   148,   153,   157,   198,   200,
     203,   212,   295,   306,   307,   308,   309,   318,   325,   345,
     346,   355,   356,   357,   359,   360,   361,   362,   363,   373,
     393,   397,   443,   444,   447,   448,   466,   502,   503,   504,
     505,   507,   511,   513,     4,   496,     6,   493,   494,   496,
     496,   496,   493,   493,   496,     6,   495,   496,   496,   501,
     506,   506,   493,   495,   495,   495,   495,     6,   394,   395,
     432,   496,   496,   493,     3,   521,   493,   493,   493,   493,
     493,   493,   347,   495,   493,     6,   491,   492,   496,   445,
     496,   493,     4,     6,   499,   113,   166,   172,   185,   190,
     200,   203,   207,   213,   243,   251,   364,   366,   367,   368,
     210,   475,   493,   364,   366,     0,    16,   140,   141,   508,
      53,   263,   248,   259,   263,   264,    74,    75,    84,    85,
      86,   192,   227,   242,   326,   327,   328,   331,   334,   337,
     338,   339,   342,   263,    93,    94,   248,   259,   265,   265,
     265,   265,   396,   397,   184,   252,   184,   184,   374,   110,
     221,   297,   493,   116,   137,   449,   263,   263,   248,   259,
     267,   154,   358,   184,   369,   369,   229,   265,   249,     3,
     159,   202,   243,   476,    67,    68,    69,    70,    71,   241,
     298,   267,   265,   504,     6,   496,   509,   510,     6,   496,
       6,   496,   496,   496,     6,   131,   135,   159,   184,   202,
     208,   377,   378,   383,   385,   184,   343,   344,   496,     3,
     184,   324,   336,   385,   387,   496,   184,   333,   496,   184,
     324,   329,   249,   496,     6,   496,   496,   317,   493,   317,
     317,   317,   397,   323,   324,   493,   323,   259,   375,   434,
     437,   491,   496,   261,     4,   497,     3,     4,     6,    15,
      17,    20,    49,    50,    55,    56,    82,   143,   173,   182,
     184,   187,   188,   206,   209,   216,   217,   223,   224,   234,
     237,   239,   240,   243,   245,   247,   250,   253,   254,   255,
     257,   258,   260,   263,   273,   274,   275,   407,   408,   409,
     410,   411,   418,   420,   439,   450,   451,   452,   453,   454,
     474,   480,   481,   488,   496,   498,   512,   514,   518,   519,
     520,   184,   350,   496,   446,   496,     6,   496,   496,   445,
     370,   434,   196,   371,   372,   432,   493,   368,   467,   184,
     205,   304,   305,   480,   304,   304,   304,   259,   300,   301,
     303,   496,   299,   300,   302,   110,   221,   296,   371,   493,
     263,   263,   249,    51,   263,   248,   184,   184,   184,   340,
     385,   184,   184,    77,   341,   343,   249,   335,   336,    81,
     146,   149,   150,   151,   158,   162,   167,   174,   176,   177,
     179,   201,   211,   215,   222,   224,   233,   235,   273,   276,
     423,   424,   425,   426,   428,   465,   332,   333,   329,   330,
     268,   327,   263,   248,   184,   184,   184,   184,   171,   249,
     171,   437,   171,   249,   263,   195,   263,   433,   200,   464,
     473,   184,   263,     6,   184,   184,   184,   474,   160,   191,
     199,   216,   230,   239,   250,   440,   441,   200,   407,   480,
     474,   184,   184,   184,   228,   238,   482,   483,   184,   474,
     184,   184,   474,   474,   184,   184,   184,   184,   519,   410,
     184,   519,     3,   266,   244,   441,   441,   134,   155,   163,
     164,   169,   178,   181,   183,   193,   194,   214,   232,   257,
     264,   270,   271,   417,   419,   195,   263,    59,    87,    88,
      89,    90,    91,    92,   217,   226,   255,   260,   487,    99,
     351,   352,   496,   204,   348,   473,   267,   263,   248,   171,
     249,   249,   229,   477,   478,   479,   480,   480,   171,   249,
     171,   301,   171,   249,   263,   433,   249,   193,   497,   407,
     267,   496,   496,   510,   496,     6,   496,   380,   382,   434,
     384,   434,   384,   171,   249,   341,   384,   407,   463,   496,
     171,   344,   171,   249,   184,   184,   184,   441,   441,   184,
     184,   184,   184,   184,   184,   184,   184,   119,   120,   121,
     175,   386,   388,   171,   249,   171,   249,   496,   496,     6,
     496,   321,   322,   496,   321,   321,   321,   136,   319,   324,
      66,    85,    86,   130,   264,   310,   311,   312,   434,   217,
     496,     3,   496,   475,   107,   376,   171,   480,   484,   496,
      21,   484,   484,   267,   475,   171,   171,   480,   486,   512,
     159,   202,   243,   421,   484,   480,   407,   269,   483,   484,
     484,   484,   421,   484,   421,   421,   421,   408,   409,   267,
     184,   267,   415,   519,   415,   415,   415,   184,   474,   205,
     480,   415,   184,   474,   415,   133,   168,   170,   480,     3,
     184,   255,   260,   515,   517,   217,   275,   496,   480,   480,
     480,   480,   480,   423,   171,   249,   263,   349,   446,   496,
       6,   496,   434,   372,   371,   249,   468,   261,   496,   305,
     193,   300,   217,   496,   302,   305,   371,   263,   263,   171,
     249,   171,   249,   171,   385,   171,   171,   336,     3,   429,
     429,     3,   267,   184,   267,     3,   430,     3,     3,     3,
     430,   430,     3,     3,     6,   439,   111,   135,   144,   159,
     165,   202,   208,   379,   389,   390,   391,   392,   333,   329,
     263,   171,   249,   225,   246,   171,   171,   171,   310,     3,
       3,     4,   313,   312,   433,   180,   249,   263,   476,   171,
     249,   263,   171,   171,   160,   191,   199,   216,   230,   239,
     250,   442,   476,   249,   441,   485,   171,   485,   480,   171,
     236,   171,   171,   171,   480,   171,   480,   480,   480,   442,
       3,   442,   186,   412,   186,   414,   186,   413,   412,   255,
     439,   489,   490,   512,   414,   489,   413,   480,   515,   180,
     217,   226,   249,   255,   256,   260,   516,     3,   195,   263,
     352,   496,   184,   263,   479,   500,   496,   184,   263,   433,
     108,   261,   365,   496,   496,   379,   434,   434,   341,   171,
     171,   171,   249,   442,     3,   442,   249,   427,   171,   171,
     249,   171,   171,   427,   171,   171,   381,   493,   184,   391,
     341,   496,    45,    46,   264,   272,   314,   315,   316,   322,
     314,   314,   314,   319,     3,   496,   477,   480,   496,   184,
     477,   441,   267,   171,   480,   171,   171,   171,   171,   171,
     416,   439,   416,   416,     3,   498,   171,   249,   171,   244,
     171,   515,   515,   515,   496,   205,   353,   354,   480,   496,
     229,   400,   404,   304,   496,   432,     3,   171,     3,   431,
     171,     3,   171,   184,   463,   313,     3,   316,   180,   433,
     404,   195,     3,   404,   267,   442,   267,   490,   480,   180,
     180,   249,   195,   171,   249,   401,   403,   493,   161,   189,
     221,   398,   399,   405,   406,   460,   220,   470,   171,   433,
     171,   267,   171,   382,   171,   515,   171,   171,   442,   442,
     515,   515,   354,    34,    41,   249,   261,   438,   496,     3,
     259,   275,   435,   436,   461,   462,   491,   496,   407,   407,
     406,   398,   159,   202,   243,   422,   156,   218,   455,   471,
     442,   171,   180,   249,   180,   180,   249,   184,   401,   402,
     402,   219,   403,   438,   436,   249,   263,   433,   200,   469,
     472,   496,   262,   156,   515,   515,   401,   265,   265,   184,
     403,   462,   217,   496,   475,   136,   320,     3,   435,   456,
     457,   458,   472,   180,   180,   171,   407,   407,   401,   433,
     476,   249,   225,   246,   459,   320,   171,   477,   457,   404,
     470
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
#line 468 "sql.yacc"
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
#line 494 "sql.yacc"
    {
		(yyval.ptr)=0;
	}
    break;

  case 4:

/* Line 1464 of yacc.c  */
#line 497 "sql.yacc"
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
#line 514 "sql.yacc"
    {
		(yyval.ptr)=A4GL_new_select_list_item_expr((yyvsp[(2) - (2)].s_select_list_item));
	}
    break;

  case 6:

/* Line 1464 of yacc.c  */
#line 519 "sql.yacc"
    {
		(yyval.ptr)=0;
	}
    break;

  case 7:

/* Line 1464 of yacc.c  */
#line 522 "sql.yacc"
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
#line 539 "sql.yacc"
    {
		 (yyval.ptr)=A4GL_new_select_list_item_expr((yyvsp[(2) - (2)].s_select_list_item));
	}
    break;

  case 9:

/* Line 1464 of yacc.c  */
#line 545 "sql.yacc"
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
#line 554 "sql.yacc"
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

  case 12:

/* Line 1464 of yacc.c  */
#line 572 "sql.yacc"
    {
		(yyval.update_cmd)=(yyvsp[(2) - (2)].update_cmd);
		add_feature("UPDATE_COLUMN_EQ_VALUE_LIST");
    }
    break;

  case 13:

/* Line 1464 of yacc.c  */
#line 579 "sql.yacc"
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
#line 594 "sql.yacc"
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
#line 649 "sql.yacc"
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
#line 656 "sql.yacc"
    {
		(yyval.update_cmd)=(yyvsp[(1) - (3)].update_cmd);
		add_str_list((yyval.update_cmd)->column_list, (yyvsp[(3) - (3)].upd_pair)->column_name);
		local_add_select_list_item_list((yyval.update_cmd)->value_list, (yyvsp[(3) - (3)].upd_pair)->value);
	}
    break;

  case 17:

/* Line 1464 of yacc.c  */
#line 667 "sql.yacc"
    {
                strcpy((yyval.str),(yyvsp[(1) - (1)].str));
        }
    break;

  case 18:

/* Line 1464 of yacc.c  */
#line 670 "sql.yacc"
    {
                strcpy((yyval.str),(yyvsp[(2) - (2)].str));
        }
    break;

  case 19:

/* Line 1464 of yacc.c  */
#line 675 "sql.yacc"
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
#line 682 "sql.yacc"
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
#line 699 "sql.yacc"
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
#line 716 "sql.yacc"
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
#line 737 "sql.yacc"
    {
		(yyval.upd_pair)=malloc(sizeof(struct s_update_pair));
		(yyval.upd_pair)->column_name=acl_strdup((yyvsp[(1) - (3)].str));
		(yyval.upd_pair)->value=(yyvsp[(3) - (3)].s_select_list_item);
	}
    break;

  case 24:

/* Line 1464 of yacc.c  */
#line 746 "sql.yacc"
    {
			(yyval.str_list)=new_str_list((yyvsp[(1) - (1)].str));
		}
    break;

  case 25:

/* Line 1464 of yacc.c  */
#line 749 "sql.yacc"
    {
			(yyval.str_list)=add_str_list((yyvsp[(1) - (3)].str_list), (yyvsp[(3) - (3)].str));
		}
    break;

  case 26:

/* Line 1464 of yacc.c  */
#line 757 "sql.yacc"
    { 
		(yyval.s_select_list_item_list)=local_new_select_list_item_list((yyvsp[(1) - (1)].s_select_list_item));
	}
    break;

  case 27:

/* Line 1464 of yacc.c  */
#line 760 "sql.yacc"
    { 
		(yyval.s_select_list_item_list)=local_add_select_list_item_list((yyvsp[(1) - (3)].s_select_list_item_list),(yyvsp[(3) - (3)].s_select_list_item));
	}
    break;

  case 28:

/* Line 1464 of yacc.c  */
#line 768 "sql.yacc"
    {(yyval.s_select_list_item)=(yyvsp[(1) - (1)].s_select_list_item);}
    break;

  case 29:

/* Line 1464 of yacc.c  */
#line 769 "sql.yacc"
    {(yyval.s_select_list_item)=new_select_list_item_builtin_const(E_SLI_BUILTIN_CONST_NULL); }
    break;

  case 30:

/* Line 1464 of yacc.c  */
#line 776 "sql.yacc"
    { (yyval.sql_string)=make_sql_string_and_free(acl_strdup((yyvsp[(1) - (1)].str)), NULL);}
    break;

  case 31:

/* Line 1464 of yacc.c  */
#line 779 "sql.yacc"
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
#line 787 "sql.yacc"
    {SPRINTF2((yyval.str),"%s %s ",(yyvsp[(1) - (2)].str),(yyvsp[(2) - (2)].str));
			add_feature("DROP_VIEW");
}
    break;

  case 33:

/* Line 1464 of yacc.c  */
#line 790 "sql.yacc"
    {SPRINTF2((yyval.str),"%s %s",(yyvsp[(1) - (2)].str),(yyvsp[(2) - (2)].str));
		if (strchr((yyvsp[(2) - (2)].str),'@') || strchr((yyvsp[(2) - (2)].str),':')) add_feature("DROP_INDEX_QUALIFIED_PATH");
			add_feature("DROP_INDEX");
}
    break;

  case 34:

/* Line 1464 of yacc.c  */
#line 794 "sql.yacc"
    {SPRINTF2((yyval.str),"%s %s",(yyvsp[(1) - (2)].str),(yyvsp[(2) - (2)].str));
			add_feature("DROP_TRIGGER");
}
    break;

  case 35:

/* Line 1464 of yacc.c  */
#line 800 "sql.yacc"
    {(yyval.sql_string)=acl_strdup((yyvsp[(1) - (1)].str));}
    break;

  case 36:

/* Line 1464 of yacc.c  */
#line 801 "sql.yacc"
    {(yyval.sql_string)=(yyvsp[(1) - (1)].sql_string);}
    break;

  case 37:

/* Line 1464 of yacc.c  */
#line 805 "sql.yacc"
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
#line 815 "sql.yacc"
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
#line 829 "sql.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 40:

/* Line 1464 of yacc.c  */
#line 830 "sql.yacc"
    {strcpy((yyval.str),(yyvsp[(1) - (1)].str));}
    break;

  case 42:

/* Line 1464 of yacc.c  */
#line 835 "sql.yacc"
    {SPRINTF2((yyval.str),"%s%s",(yyvsp[(1) - (2)].str),(yyvsp[(2) - (2)].str)); }
    break;

  case 43:

/* Line 1464 of yacc.c  */
#line 840 "sql.yacc"
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
#line 848 "sql.yacc"
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
#line 856 "sql.yacc"
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
#line 864 "sql.yacc"
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
#line 872 "sql.yacc"
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
#line 884 "sql.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 50:

/* Line 1464 of yacc.c  */
#line 884 "sql.yacc"
    {strcpy((yyval.str),(yyvsp[(1) - (1)].str));}
    break;

  case 52:

/* Line 1464 of yacc.c  */
#line 888 "sql.yacc"
    {SPRINTF2((yyval.str),"%s%s",(yyvsp[(1) - (2)].str),(yyvsp[(2) - (2)].str));}
    break;

  case 53:

/* Line 1464 of yacc.c  */
#line 892 "sql.yacc"
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
#line 899 "sql.yacc"
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
#line 906 "sql.yacc"
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
#line 913 "sql.yacc"
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
#line 922 "sql.yacc"
    { strcpy(last_tmp_name,(yyvsp[(1) - (1)].str)); }
    break;

  case 58:

/* Line 1464 of yacc.c  */
#line 926 "sql.yacc"
    {SPRINTF7((yyval.str),"CREATE UNIQUE INDEX %s %s %s %s %s %s %s",(yyvsp[(2) - (8)].str),(yyvsp[(3) - (8)].str),(yyvsp[(4) - (8)].str),(yyvsp[(5) - (8)].str),(yyvsp[(6) - (8)].str),(yyvsp[(7) - (8)].str),(yyvsp[(8) - (8)].str));
		add_feature("CREATE_INDEX");
		add_feature("CREATE_INDEX_UNIQUE");
		if (strchr((yyvsp[(2) - (8)].str),'@') || strchr((yyvsp[(2) - (8)].str),':')) add_feature("CREATE_INDEX_QUALIFIED_PATH");
		if (strchr((yyvsp[(6) - (8)].str),',')) { add_feature("CREATE_INDEX_COMPOSITE"); }
	
}
    break;

  case 59:

/* Line 1464 of yacc.c  */
#line 933 "sql.yacc"
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
#line 945 "sql.yacc"
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
#line 956 "sql.yacc"
    {
		if (strchr((yyvsp[(2) - (8)].str),'@') || strchr((yyvsp[(2) - (8)].str),':')) add_feature("CREATE_INDEX_QUALIFIED_PATH");
		if (strchr((yyvsp[(6) - (8)].str),',')) { add_feature("CREATE_INDEX_COMPOSITE"); }
			add_feature("CREATE_INDEX");
			SPRINTF7((yyval.str)," CREATE INDEX %s %s %s %s %s %s %s",(yyvsp[(2) - (8)].str),(yyvsp[(3) - (8)].str),(yyvsp[(4) - (8)].str),(yyvsp[(5) - (8)].str),(yyvsp[(6) - (8)].str),(yyvsp[(7) - (8)].str),(yyvsp[(8) - (8)].str));
	}
    break;

  case 62:

/* Line 1464 of yacc.c  */
#line 962 "sql.yacc"
    {
		add_feature("CREATE_DATABASE");
		a4gl_yyerror("You cannot create a database from within Aubit4gl - if the target database allows - prepare and execute it manually");
	}
    break;

  case 63:

/* Line 1464 of yacc.c  */
#line 966 "sql.yacc"
    {
		add_feature("DROP_DATABASE");
		a4gl_yyerror("You cannot drop a database from within Aubit4gl - if the target database allows - prepare and execute it manually");
	}
    break;

  case 64:

/* Line 1464 of yacc.c  */
#line 970 "sql.yacc"
    { 
		if (strchr((yyvsp[(2) - (4)].str),'@') || strchr((yyvsp[(2) - (4)].str),':')) add_feature("CREATE_SYNONYM_QUALIFIED_PATH");
			add_feature("CREATE_SYNONYM");
			SPRINTF3((yyval.str),"%s %s FOR %s",(yyvsp[(1) - (4)].str),(yyvsp[(2) - (4)].str),(yyvsp[(4) - (4)].str)); 
	}
    break;

  case 65:

/* Line 1464 of yacc.c  */
#line 975 "sql.yacc"
    { 
		add_feature("CREATE_AUDIT");
		SPRINTF2((yyval.str),"CREATE AUDIT FOR %s IN '%s'",(yyvsp[(2) - (4)].str),A4GL_strip_quotes((yyvsp[(4) - (4)].str))); 
	}
    break;

  case 66:

/* Line 1464 of yacc.c  */
#line 979 "sql.yacc"
    { 
		add_feature("DROP_AUDIT");
		SPRINTF1((yyval.str),"DROP AUDIT FOR %s",(yyvsp[(2) - (2)].str)); }
    break;

  case 67:

/* Line 1464 of yacc.c  */
#line 982 "sql.yacc"
    { 
		if (strchr((yyvsp[(2) - (2)].str),'@') || strchr((yyvsp[(2) - (2)].str),':')) add_feature("DROP_SYNONYM_QUALIFIED_PATH");
		add_feature("DROP_SYNONYM");
		SPRINTF2((yyval.str),"%s %s",(yyvsp[(1) - (2)].str),(yyvsp[(2) - (2)].str)); }
    break;

  case 68:

/* Line 1464 of yacc.c  */
#line 986 "sql.yacc"
    { 
		add_feature("RECOVER_TABLE");
		SPRINTF1((yyval.str),"RECOVER TABLE %s",(yyvsp[(2) - (2)].str)); }
    break;

  case 69:

/* Line 1464 of yacc.c  */
#line 989 "sql.yacc"
    { 
		add_feature("ROLLFORWARD_DATABASE");
		SPRINTF1((yyval.str),"ROLLFORWARD DATABASE %s",(yyvsp[(2) - (2)].str)); }
    break;

  case 70:

/* Line 1464 of yacc.c  */
#line 996 "sql.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 71:

/* Line 1464 of yacc.c  */
#line 997 "sql.yacc"
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
#line 1007 "sql.yacc"
    {(yyval.integer_val)=0;}
    break;

  case 73:

/* Line 1464 of yacc.c  */
#line 1008 "sql.yacc"
    { (yyval.integer_val)=1;}
    break;

  case 75:

/* Line 1464 of yacc.c  */
#line 1013 "sql.yacc"
    {SPRINTF2((yyval.str),"%s,%s",(yyvsp[(1) - (3)].str),(yyvsp[(3) - (3)].str));}
    break;

  case 76:

/* Line 1464 of yacc.c  */
#line 1017 "sql.yacc"
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
#line 1026 "sql.yacc"
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
#line 1035 "sql.yacc"
    {
		strcpy((yyval.str),A4GL_confirm_colname(last_tmp_name,(yyvsp[(1) - (1)].str)));
}
    break;

  case 79:

/* Line 1464 of yacc.c  */
#line 1042 "sql.yacc"
    {
		(yyval.sql_string)=(yyvsp[(1) - (1)].sql_string);
	}
    break;

  case 80:

/* Line 1464 of yacc.c  */
#line 1045 "sql.yacc"
    {
		(yyval.sql_string)=make_sql_string_and_free((yyvsp[(1) - (3)].sql_string),kw_comma,strdup("\n"),(yyvsp[(3) - (3)].sql_string),NULL);
	}
    break;

  case 81:

/* Line 1464 of yacc.c  */
#line 1051 "sql.yacc"
    {
		(yyval.sql_string)=make_sql_string_and_free(strdup("   "),(yyvsp[(1) - (1)].sql_string),NULL);
	}
    break;

  case 82:

/* Line 1464 of yacc.c  */
#line 1054 "sql.yacc"
    {
		(yyval.sql_string)=make_sql_string_and_free(strdup("   "),(yyvsp[(1) - (1)].sql_string),NULL);
	}
    break;

  case 83:

/* Line 1464 of yacc.c  */
#line 1065 "sql.yacc"
    {
		add_feature("ALTER_TABLE");
	(yyval.sql_string)=make_sql_string_and_free(acl_strdup((yyvsp[(1) - (3)].str)),kw_space,acl_strdup((yyvsp[(2) - (3)].str)),kw_space,(yyvsp[(3) - (3)].sql_string),NULL);
	}
    break;

  case 84:

/* Line 1464 of yacc.c  */
#line 1069 "sql.yacc"
    {
		add_feature("CLUSTER_INDEX");
		add_feature("ALTER_INDEX_CLUSTER");
		(yyval.sql_string)=make_sql_string_and_free(acl_strdup("ALTER INDEX "),acl_strdup((yyvsp[(2) - (3)].str)),acl_strdup(" TO CLUSTER"),NULL);
		}
    break;

  case 85:

/* Line 1464 of yacc.c  */
#line 1074 "sql.yacc"
    {
		add_feature("ALTER_INDEX_NOT_CLUSTER");
		(yyval.sql_string)=make_sql_string_and_free(acl_strdup("ALTER INDEX "),acl_strdup((yyvsp[(2) - (3)].str)),acl_strdup(" TO NOT CLUSTER"),NULL);
		}
    break;

  case 86:

/* Line 1464 of yacc.c  */
#line 1081 "sql.yacc"
    {
		(yyval.sql_string)=(yyvsp[(1) - (1)].sql_string);
	}
    break;

  case 87:

/* Line 1464 of yacc.c  */
#line 1084 "sql.yacc"
    {
		(yyval.sql_string)=make_sql_string_and_free((yyvsp[(1) - (3)].sql_string),kw_comma,(yyvsp[(3) - (3)].sql_string),NULL);
	}
    break;

  case 88:

/* Line 1464 of yacc.c  */
#line 1093 "sql.yacc"
    {
		(yyval.sql_string)=(yyvsp[(1) - (1)].sql_string);
	}
    break;

  case 89:

/* Line 1464 of yacc.c  */
#line 1096 "sql.yacc"
    {
	add_feature("ALTER_TABLE_DROP");
		(yyval.sql_string)=acl_strdup((yyvsp[(1) - (1)].str));
	}
    break;

  case 90:

/* Line 1464 of yacc.c  */
#line 1100 "sql.yacc"
    {
	add_feature("ALTER_TABLE_MODIFY");
		(yyval.sql_string)=(yyvsp[(1) - (1)].sql_string);
	}
    break;

  case 91:

/* Line 1464 of yacc.c  */
#line 1104 "sql.yacc"
    {
		add_feature("ALTER_TABLE_ADD_CONSTRAINT");
		(yyval.sql_string)=acl_strdup((yyvsp[(1) - (1)].str));
	}
    break;

  case 92:

/* Line 1464 of yacc.c  */
#line 1108 "sql.yacc"
    {
		add_feature("ALTER_TABLE_DROP_CONSTRAINT");
		(yyval.sql_string)=acl_strdup((yyvsp[(1) - (1)].str));
	}
    break;

  case 93:

/* Line 1464 of yacc.c  */
#line 1112 "sql.yacc"
    {
		add_feature("ALTER_TABLE_MODIFY_NEXT");
		(yyval.sql_string)=acl_strdup((yyvsp[(1) - (1)].str));
	}
    break;

  case 94:

/* Line 1464 of yacc.c  */
#line 1116 "sql.yacc"
    {
		add_feature("ALTER_TABLE_LOCK_MODE");
		(yyval.sql_string)=acl_strdup((yyvsp[(1) - (1)].str));
	}
    break;

  case 95:

/* Line 1464 of yacc.c  */
#line 1124 "sql.yacc"
    {
		add_feature("ALTER_TABLE_ADD");
		(yyval.sql_string)=make_sql_string_and_free(acl_strdup("ADD "),(yyvsp[(2) - (2)].sql_string),NULL);
	}
    break;

  case 96:

/* Line 1464 of yacc.c  */
#line 1128 "sql.yacc"
    {
		add_feature("ALTER_TABLE_ADD");
		(yyval.sql_string)=make_sql_string_and_free(acl_strdup("ADD "),kw_ob,(yyvsp[(3) - (4)].sql_string),kw_cb,NULL);
	}
    break;

  case 97:

/* Line 1464 of yacc.c  */
#line 1136 "sql.yacc"
    {
		(yyval.sql_string)=(yyvsp[(1) - (1)].sql_string);
	}
    break;

  case 98:

/* Line 1464 of yacc.c  */
#line 1139 "sql.yacc"
    {
		add_feature("ALTER_TABLE_ADD_BEFORE");
		(yyval.sql_string)=make_sql_string_and_free((yyvsp[(1) - (3)].sql_string),acl_strdup(" BEFORE "),acl_strdup((yyvsp[(3) - (3)].str)),NULL);
	}
    break;

  case 99:

/* Line 1464 of yacc.c  */
#line 1146 "sql.yacc"
    {
		(yyval.sql_string)=(yyvsp[(1) - (1)].sql_string);
	}
    break;

  case 100:

/* Line 1464 of yacc.c  */
#line 1149 "sql.yacc"
    {
		(yyval.sql_string)=make_sql_string_and_free((yyvsp[(1) - (3)].sql_string),kw_comma,(yyvsp[(3) - (3)].sql_string),NULL);
	}
    break;

  case 101:

/* Line 1464 of yacc.c  */
#line 1156 "sql.yacc"
    {
		SPRINTF1((yyval.str),"DROP %s",(yyvsp[(2) - (2)].str));
	}
    break;

  case 102:

/* Line 1464 of yacc.c  */
#line 1159 "sql.yacc"
    {
		SPRINTF1((yyval.str),"DROP (%s)",(yyvsp[(3) - (4)].str));
	}
    break;

  case 104:

/* Line 1464 of yacc.c  */
#line 1167 "sql.yacc"
    {
		SPRINTF2((yyval.str),"%s,%s",(yyvsp[(1) - (3)].str),(yyvsp[(3) - (3)].str));
	}
    break;

  case 106:

/* Line 1464 of yacc.c  */
#line 1176 "sql.yacc"
    {
		(yyval.sql_string)=make_sql_string_and_free(acl_strdup("MODIFY "),(yyvsp[(2) - (2)].sql_string),NULL);
	}
    break;

  case 107:

/* Line 1464 of yacc.c  */
#line 1179 "sql.yacc"
    {
		(yyval.sql_string)=make_sql_string_and_free(acl_strdup("MODIFY "),kw_ob,(yyvsp[(3) - (4)].sql_string),kw_cb,NULL);
	}
    break;

  case 108:

/* Line 1464 of yacc.c  */
#line 1185 "sql.yacc"
    {
		(yyval.sql_string)=(yyvsp[(1) - (1)].sql_string);
	}
    break;

  case 109:

/* Line 1464 of yacc.c  */
#line 1188 "sql.yacc"
    {
		(yyval.sql_string)=make_sql_string_and_free((yyvsp[(1) - (3)].sql_string),kw_comma,(yyvsp[(3) - (3)].sql_string),NULL);
	}
    break;

  case 110:

/* Line 1464 of yacc.c  */
#line 1194 "sql.yacc"
    {
		(yyval.sql_string)=(yyvsp[(1) - (1)].sql_string);
	}
    break;

  case 111:

/* Line 1464 of yacc.c  */
#line 1201 "sql.yacc"
    {strcpy((yyval.str),"LOCK MODE (PAGE)");}
    break;

  case 112:

/* Line 1464 of yacc.c  */
#line 1202 "sql.yacc"
    {strcpy((yyval.str),"LOCK MODE (ROW)");}
    break;

  case 113:

/* Line 1464 of yacc.c  */
#line 1206 "sql.yacc"
    {
		add_feature("DDL_NEXT_SIZE");
		SPRINTF1((yyval.str),"MODIFY NEXT SIZE %d",atoi((yyvsp[(2) - (2)].str)));
	}
    break;

  case 114:

/* Line 1464 of yacc.c  */
#line 1214 "sql.yacc"
    {
		add_feature("DDL_CONSTRAINT");
		SPRINTF2((yyval.str),"ADD CONSTRAINT %s%s",(yyvsp[(2) - (3)].sql_string),(yyvsp[(3) - (3)].str));
	}
    break;

  case 115:

/* Line 1464 of yacc.c  */
#line 1218 "sql.yacc"
    {
		add_feature("ADD_CONSTRAINT");
		SPRINTF1((yyval.str),"ADD CONSTRAINT (%s)",(yyvsp[(3) - (4)].sql_string));
	}
    break;

  case 116:

/* Line 1464 of yacc.c  */
#line 1225 "sql.yacc"
    {
		(yyval.sql_string)=make_sql_string_and_free((yyvsp[(1) - (2)].sql_string),acl_strdup((yyvsp[(2) - (2)].str)),NULL);
}
    break;

  case 117:

/* Line 1464 of yacc.c  */
#line 1227 "sql.yacc"
    {
	(yyval.sql_string)=make_sql_string_and_free((yyvsp[(1) - (4)].sql_string),kw_comma,(yyvsp[(3) - (4)].sql_string),acl_strdup((yyvsp[(4) - (4)].str)), NULL);
}
    break;

  case 118:

/* Line 1464 of yacc.c  */
#line 1232 "sql.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 119:

/* Line 1464 of yacc.c  */
#line 1233 "sql.yacc"
    {SPRINTF2((yyval.str)," %s %s",(yyvsp[(1) - (2)].str),(yyvsp[(2) - (2)].str)); add_feature("DDL_CONSTRAINT");}
    break;

  case 120:

/* Line 1464 of yacc.c  */
#line 1238 "sql.yacc"
    { SPRINTF1((yyval.str),"DROP CONSTRAINT %s",(yyvsp[(2) - (2)].str)); add_feature("DROP_CONSTRAINT"); }
    break;

  case 121:

/* Line 1464 of yacc.c  */
#line 1239 "sql.yacc"
    {add_feature("DROP_CONSTRAINT");
		SPRINTF1((yyval.str),"DROP CONSTRAINT (%s)",(yyvsp[(3) - (4)].str));
	}
    break;

  case 122:

/* Line 1464 of yacc.c  */
#line 1245 "sql.yacc"
    {strcpy((yyval.str),(yyvsp[(1) - (1)].str));}
    break;

  case 123:

/* Line 1464 of yacc.c  */
#line 1246 "sql.yacc"
    {SPRINTF2((yyval.str),"%s,%s",(yyvsp[(1) - (3)].str),(yyvsp[(3) - (3)].str));}
    break;

  case 125:

/* Line 1464 of yacc.c  */
#line 1260 "sql.yacc"
    {  add_feature("ROLLBACK_WORK"); }
    break;

  case 126:

/* Line 1464 of yacc.c  */
#line 1266 "sql.yacc"
    { insql=1;}
    break;

  case 127:

/* Line 1464 of yacc.c  */
#line 1266 "sql.yacc"
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
#line 1275 "sql.yacc"
    {insql=1;}
    break;

  case 129:

/* Line 1464 of yacc.c  */
#line 1275 "sql.yacc"
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
#line 1284 "sql.yacc"
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
#line 1309 "sql.yacc"
    {
			(yyval.str_list)=0;
	}
    break;

  case 132:

/* Line 1464 of yacc.c  */
#line 1312 "sql.yacc"
    {
			(yyval.str_list)=(yyvsp[(2) - (3)].str_list);
			 add_feature("INSERT_COLUMNLIST_EQ_VALUELIST");
	}
    break;

  case 133:

/* Line 1464 of yacc.c  */
#line 1320 "sql.yacc"
    {
                        (yyval.str_list)=new_str_list((yyvsp[(1) - (1)].str));
	}
    break;

  case 134:

/* Line 1464 of yacc.c  */
#line 1323 "sql.yacc"
    {
                        (yyval.str_list)=add_str_list((yyvsp[(1) - (3)].str_list), (yyvsp[(3) - (3)].str));
	}
    break;

  case 135:

/* Line 1464 of yacc.c  */
#line 1330 "sql.yacc"
    {	
			strcpy((yyval.str),(yyvsp[(1) - (1)].str));
	}
    break;

  case 136:

/* Line 1464 of yacc.c  */
#line 1333 "sql.yacc"
    { 
			/* with a table prefix - on an insert ? We'll just silently drop it... */
			strcpy((yyval.str),(yyvsp[(3) - (3)].str));
			A4GL_warn("Dropped table prefix from INSERT column name");
	}
    break;

  case 137:

/* Line 1464 of yacc.c  */
#line 1341 "sql.yacc"
    { (yyval.s_select_list_item_list)=local_new_select_list_item_list((yyvsp[(1) - (1)].s_select_list_item));}
    break;

  case 138:

/* Line 1464 of yacc.c  */
#line 1342 "sql.yacc"
    {
		(yyval.s_select_list_item_list)=local_add_select_list_item_list((yyvsp[(1) - (3)].s_select_list_item_list),(yyvsp[(3) - (3)].s_select_list_item));
	}
    break;

  case 139:

/* Line 1464 of yacc.c  */
#line 1348 "sql.yacc"
    {(yyval.s_select_list_item)=(yyvsp[(1) - (1)].s_select_list_item);}
    break;

  case 140:

/* Line 1464 of yacc.c  */
#line 1349 "sql.yacc"
    {(yyval.s_select_list_item)=new_select_list_item_builtin_const(E_SLI_BUILTIN_CONST_NULL); }
    break;

  case 141:

/* Line 1464 of yacc.c  */
#line 1357 "sql.yacc"
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
#line 1375 "sql.yacc"
    { add_feature("BEGIN_WORK"); }
    break;

  case 143:

/* Line 1464 of yacc.c  */
#line 1379 "sql.yacc"
    { add_feature("COMMIT_WORK"); }
    break;

  case 144:

/* Line 1464 of yacc.c  */
#line 1384 "sql.yacc"
    {(yyval.e_boolean)=EB_FALSE;}
    break;

  case 145:

/* Line 1464 of yacc.c  */
#line 1385 "sql.yacc"
    {
		add_feature("DATABASE_EXCLUSIVE");
		{(yyval.e_boolean)=EB_TRUE;}
	}
    break;

  case 146:

/* Line 1464 of yacc.c  */
#line 1395 "sql.yacc"
    {
	char buff[256];
	(yyval.sql_string)=make_sql_string_and_free(acl_strdup((yyvsp[(1) - (1)].str)),NULL);
	SPRINTF1(buff,"Warning: Informix specific SQL @ line %d\n",yylineno);
	ansi_violation(buff,1);
	}
    break;

  case 147:

/* Line 1464 of yacc.c  */
#line 1404 "sql.yacc"
    {
			add_feature("START_DATABASE_WITH_LOG_MODE_ANSI");
			sprintf((yyval.str),"START DATABASE %s WITH LOG IN %s MODE ANSI", (yyvsp[(2) - (5)].str),(yyvsp[(4) - (5)].str));
	}
    break;

  case 148:

/* Line 1464 of yacc.c  */
#line 1408 "sql.yacc"
    {
			add_feature("START_DATABASE_WITH_LOG");
			sprintf((yyval.str),"START DATABASE %s WITH LOG IN %s", (yyvsp[(2) - (4)].str),(yyvsp[(4) - (4)].str));
	}
    break;

  case 149:

/* Line 1464 of yacc.c  */
#line 1413 "sql.yacc"
    {
			add_feature("SET_CONSTRAINTS_ALL_IMMEDIATE");
			SPRINTF1((yyval.str),"%s",(yyvsp[(1) - (1)].str)); 
	}
    break;

  case 150:

/* Line 1464 of yacc.c  */
#line 1417 "sql.yacc"
    {
		add_feature("SET_BUFFERED_LOG");
			SPRINTF1((yyval.str),"%s",(yyvsp[(1) - (1)].str)); 
	}
    break;

  case 151:

/* Line 1464 of yacc.c  */
#line 1421 "sql.yacc"
    {
		add_feature("SET_LOG");
			SPRINTF1((yyval.str),"%s",(yyvsp[(1) - (1)].str)); 
	}
    break;

  case 152:

/* Line 1464 of yacc.c  */
#line 1425 "sql.yacc"
    {
			SPRINTF2((yyval.str),"%s %s",(yyvsp[(1) - (2)].str),(yyvsp[(2) - (2)].str)); add_feature("UPDATE_STATISTICS_TABLE");
	}
    break;

  case 153:

/* Line 1464 of yacc.c  */
#line 1428 "sql.yacc"
    {
		add_feature("UPDATE_STATISTICS");
			SPRINTF1((yyval.str),"%s",(yyvsp[(1) - (1)].str)); 
	}
    break;

  case 154:

/* Line 1464 of yacc.c  */
#line 1435 "sql.yacc"
    { (yyval.integer_val)=1; 
#ifndef  SQLCOMPILER
				set_cmdlineno(token_read_on_line);
#endif

}
    break;

  case 155:

/* Line 1464 of yacc.c  */
#line 1441 "sql.yacc"
    { (yyval.integer_val)=-1; 
#ifndef  SQLCOMPILER
set_cmdlineno(token_read_on_line);
#endif
}
    break;

  case 156:

/* Line 1464 of yacc.c  */
#line 1446 "sql.yacc"
    { (yyval.integer_val)=0; 
#ifndef  SQLCOMPILER
set_cmdlineno(token_read_on_line);
#endif
}
    break;

  case 157:

/* Line 1464 of yacc.c  */
#line 1454 "sql.yacc"
    { (yyval.sql_string)=(yyvsp[(1) - (1)].sql_string); }
    break;

  case 158:

/* Line 1464 of yacc.c  */
#line 1455 "sql.yacc"
    { (yyval.sql_string)=(yyvsp[(1) - (1)].sql_string); }
    break;

  case 159:

/* Line 1464 of yacc.c  */
#line 1456 "sql.yacc"
    { (yyval.sql_string)=(yyvsp[(1) - (1)].sql_string); }
    break;

  case 160:

/* Line 1464 of yacc.c  */
#line 1457 "sql.yacc"
    { (yyval.sql_string)=(yyvsp[(1) - (1)].sql_string); }
    break;

  case 161:

/* Line 1464 of yacc.c  */
#line 1458 "sql.yacc"
    { (yyval.sql_string)=(yyvsp[(1) - (1)].sql_string); }
    break;

  case 162:

/* Line 1464 of yacc.c  */
#line 1459 "sql.yacc"
    { (yyval.sql_string)=(yyvsp[(1) - (1)].sql_string); }
    break;

  case 163:

/* Line 1464 of yacc.c  */
#line 1460 "sql.yacc"
    { (yyval.sql_string)=(yyvsp[(1) - (1)].sql_string); }
    break;

  case 164:

/* Line 1464 of yacc.c  */
#line 1468 "sql.yacc"
    {SPRINTF7((yyval.str),"%s %s %s %s %s %s %s",(yyvsp[(1) - (7)].str),(yyvsp[(2) - (7)].str),(yyvsp[(3) - (7)].str),(yyvsp[(4) - (7)].str),(yyvsp[(5) - (7)].str),(yyvsp[(6) - (7)].str),(yyvsp[(7) - (7)].str));  add_feature("GRANT"); }
    break;

  case 165:

/* Line 1464 of yacc.c  */
#line 1469 "sql.yacc"
    {SPRINTF6((yyval.str),"%s %s %s %s %s %s",(yyvsp[(1) - (6)].str),(yyvsp[(2) - (6)].str),(yyvsp[(3) - (6)].str),(yyvsp[(4) - (6)].str),(yyvsp[(5) - (6)].str),(yyvsp[(6) - (6)].str));  add_feature("REVOKE"); }
    break;

  case 166:

/* Line 1464 of yacc.c  */
#line 1470 "sql.yacc"
    {SPRINTF4((yyval.str),"%s %s %s %s ",(yyvsp[(1) - (4)].str),(yyvsp[(2) - (4)].str),(yyvsp[(3) - (4)].str),(yyvsp[(4) - (4)].str)); add_feature("GRANT"); }
    break;

  case 167:

/* Line 1464 of yacc.c  */
#line 1471 "sql.yacc"
    {SPRINTF4((yyval.str),"%s %s %s %s ",(yyvsp[(1) - (4)].str),(yyvsp[(2) - (4)].str),(yyvsp[(3) - (4)].str),(yyvsp[(4) - (4)].str));  add_feature("REVOKE"); }
    break;

  case 171:

/* Line 1464 of yacc.c  */
#line 1481 "sql.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 172:

/* Line 1464 of yacc.c  */
#line 1482 "sql.yacc"
    {SPRINTF1((yyval.str)," %s ",(yyvsp[(1) - (1)].str));}
    break;

  case 173:

/* Line 1464 of yacc.c  */
#line 1483 "sql.yacc"
    {SPRINTF2((yyval.str)," %s %s",(yyvsp[(1) - (2)].str),(yyvsp[(2) - (2)].str));}
    break;

  case 174:

/* Line 1464 of yacc.c  */
#line 1487 "sql.yacc"
    {SPRINTF1((yyval.str)," %s ",(yyvsp[(1) - (1)].str));}
    break;

  case 175:

/* Line 1464 of yacc.c  */
#line 1488 "sql.yacc"
    {SPRINTF1((yyval.str)," %s ",(yyvsp[(1) - (1)].str));}
    break;

  case 178:

/* Line 1464 of yacc.c  */
#line 1495 "sql.yacc"
    {SPRINTF3((yyval.str)," %s %s %s",(yyvsp[(1) - (3)].str),(yyvsp[(2) - (3)].str),(yyvsp[(3) - (3)].str));}
    break;

  case 179:

/* Line 1464 of yacc.c  */
#line 1498 "sql.yacc"
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
#line 1507 "sql.yacc"
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
#line 1518 "sql.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 186:

/* Line 1464 of yacc.c  */
#line 1520 "sql.yacc"
    {SPRINTF3((yyval.str)," %s %s %s",(yyvsp[(1) - (3)].str),(yyvsp[(2) - (3)].str),(yyvsp[(3) - (3)].str));}
    break;

  case 188:

/* Line 1464 of yacc.c  */
#line 1526 "sql.yacc"
    {SPRINTF3((yyval.str)," %s %s %s",(yyvsp[(1) - (3)].str),(yyvsp[(2) - (3)].str),(yyvsp[(3) - (3)].str));}
    break;

  case 190:

/* Line 1464 of yacc.c  */
#line 1532 "sql.yacc"
    {SPRINTF3((yyval.str)," %s %s %s",(yyvsp[(1) - (3)].str),(yyvsp[(2) - (3)].str),(yyvsp[(3) - (3)].str));}
    break;

  case 193:

/* Line 1464 of yacc.c  */
#line 1542 "sql.yacc"
    {
		add_feature("CREATE_VIEW_AS_SELECT");
		(yyval.sql_string)=make_sql_string_and_free(acl_strdup((yyvsp[(1) - (6)].str)),kw_space,acl_strdup((yyvsp[(2) - (6)].str)),kw_space,acl_strdup((yyvsp[(3) - (6)].str)),kw_space,acl_strdup((yyvsp[(4) - (6)].str)),kw_space,(yyvsp[(5) - (6)].sql_string),kw_space,acl_strdup((yyvsp[(6) - (6)].str)),NULL);
	
}
    break;

  case 194:

/* Line 1464 of yacc.c  */
#line 1549 "sql.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 195:

/* Line 1464 of yacc.c  */
#line 1551 "sql.yacc"
    {SPRINTF3((yyval.str)," %s %s %s",(yyvsp[(1) - (3)].str),(yyvsp[(2) - (3)].str),(yyvsp[(3) - (3)].str));}
    break;

  case 197:

/* Line 1464 of yacc.c  */
#line 1557 "sql.yacc"
    {SPRINTF3((yyval.str)," %s %s %s",(yyvsp[(1) - (3)].str),(yyvsp[(2) - (3)].str),(yyvsp[(3) - (3)].str));}
    break;

  case 198:

/* Line 1464 of yacc.c  */
#line 1560 "sql.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 199:

/* Line 1464 of yacc.c  */
#line 1561 "sql.yacc"
    {
		add_feature("CREATE_VIEW_SELECT_WITH_CHECK");
	}
    break;

  case 200:

/* Line 1464 of yacc.c  */
#line 1568 "sql.yacc"
    {
		(yyval.sql_string)=make_sql_string_and_free(strdup("CHECK ("),(yyvsp[(3) - (4)].sql_string),kw_cb,NULL);
		add_feature("DDL_CHECK");
	}
    break;

  case 201:

/* Line 1464 of yacc.c  */
#line 1577 "sql.yacc"
    {SPRINTF5((yyval.str)," %s %s %s %s %s",(yyvsp[(1) - (5)].str),(yyvsp[(2) - (5)].str),(yyvsp[(3) - (5)].str),(yyvsp[(4) - (5)].str),(yyvsp[(5) - (5)].str));
	add_feature("DDL_FOREIGN_KEY");
}
    break;

  case 202:

/* Line 1464 of yacc.c  */
#line 1584 "sql.yacc"
    {SPRINTF2((yyval.str)," %s %s",(yyvsp[(1) - (2)].str),(yyvsp[(2) - (2)].str));
add_feature("DDL_REFERENCES");
}
    break;

  case 205:

/* Line 1464 of yacc.c  */
#line 1596 "sql.yacc"
    {SPRINTF4((yyval.str)," %s %s %s %s",(yyvsp[(1) - (4)].str),(yyvsp[(2) - (4)].str),(yyvsp[(3) - (4)].str),(yyvsp[(4) - (4)].str));}
    break;

  case 207:

/* Line 1464 of yacc.c  */
#line 1602 "sql.yacc"
    {SPRINTF3((yyval.str)," %s %s %s",(yyvsp[(1) - (3)].str),(yyvsp[(2) - (3)].str),(yyvsp[(3) - (3)].str));}
    break;

  case 208:

/* Line 1464 of yacc.c  */
#line 1607 "sql.yacc"
    {
		SPRINTF3((yyval.str)," UNIQUE %s %s %s",(yyvsp[(2) - (4)].str),(yyvsp[(3) - (4)].str),(yyvsp[(4) - (4)].str));
add_feature("DDL_UNIQUE");
	}
    break;

  case 209:

/* Line 1464 of yacc.c  */
#line 1611 "sql.yacc"
    {
		ansi_violation("Use UNIQUE not DISTINCT",0);
		SPRINTF3((yyval.str)," UNIQUE %s %s %s",(yyvsp[(2) - (4)].str),(yyvsp[(3) - (4)].str),(yyvsp[(4) - (4)].str));
add_feature("DDL_DISTINCT");
	}
    break;

  case 210:

/* Line 1464 of yacc.c  */
#line 1617 "sql.yacc"
    {SPRINTF4((yyval.str)," %s %s %s %s",(yyvsp[(1) - (4)].str),(yyvsp[(2) - (4)].str),(yyvsp[(3) - (4)].str),(yyvsp[(4) - (4)].str));
add_feature("DDL_PRIMARY_KEY");
}
    break;

  case 212:

/* Line 1464 of yacc.c  */
#line 1625 "sql.yacc"
    {SPRINTF3((yyval.str)," %s %s %s",(yyvsp[(1) - (3)].str),(yyvsp[(2) - (3)].str),(yyvsp[(3) - (3)].str));}
    break;

  case 213:

/* Line 1464 of yacc.c  */
#line 1630 "sql.yacc"
    {
		(yyval.sql_string)=acl_strdup((yyvsp[(1) - (1)].str));
	}
    break;

  case 214:

/* Line 1464 of yacc.c  */
#line 1633 "sql.yacc"
    {
		(yyval.sql_string)=acl_strdup((yyvsp[(1) - (1)].str));
	}
    break;

  case 215:

/* Line 1464 of yacc.c  */
#line 1636 "sql.yacc"
    {
		(yyval.sql_string)=(yyvsp[(1) - (1)].sql_string);
	}
    break;

  case 216:

/* Line 1464 of yacc.c  */
#line 1643 "sql.yacc"
    {SPRINTF2((yyval.str)," %s %s",(yyvsp[(1) - (2)].str),(yyvsp[(2) - (2)].str)); add_feature("DDL_DEFAULT_VALUE"); }
    break;

  case 217:

/* Line 1464 of yacc.c  */
#line 1644 "sql.yacc"
    {SPRINTF1((yyval.str)," DEFAULT %s", A4GLSQLCV_get_sqlconst("USER")); add_feature("DDL_DEFAULT_VALUE"); }
    break;

  case 218:

/* Line 1464 of yacc.c  */
#line 1645 "sql.yacc"
    {SPRINTF1((yyval.str)," DEFAULT %s", A4GLSQLCV_get_sqlconst("TODAY")); add_feature("DDL_DEFAULT_VALUE"); }
    break;

  case 219:

/* Line 1464 of yacc.c  */
#line 1646 "sql.yacc"
    { SPRINTF1((yyval.str)," %s",(yyvsp[(1) - (1)].str)); add_feature("DDL_DEFAULT_VALUE"); }
    break;

  case 220:

/* Line 1464 of yacc.c  */
#line 1652 "sql.yacc"
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
#line 1675 "sql.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 223:

/* Line 1464 of yacc.c  */
#line 1679 "sql.yacc"
    {
		(yyval.sql_string)=acl_strdup("");
	}
    break;

  case 224:

/* Line 1464 of yacc.c  */
#line 1681 "sql.yacc"
    {
		(yyval.sql_string)=(yyvsp[(1) - (1)].sql_string);
	}
    break;

  case 225:

/* Line 1464 of yacc.c  */
#line 1688 "sql.yacc"
    {
		(yyval.sql_string)=(yyvsp[(1) - (1)].sql_string);
	}
    break;

  case 226:

/* Line 1464 of yacc.c  */
#line 1691 "sql.yacc"
    {
		(yyval.sql_string)=make_sql_string_and_free((yyvsp[(1) - (2)].sql_string),kw_space,(yyvsp[(2) - (2)].sql_string),NULL);
	}
    break;

  case 227:

/* Line 1464 of yacc.c  */
#line 1697 "sql.yacc"
    {
		(yyval.sql_string)=make_sql_string_and_free((yyvsp[(1) - (2)].sql_string),acl_strdup((yyvsp[(2) - (2)].str)),NULL);
	}
    break;

  case 228:

/* Line 1464 of yacc.c  */
#line 1705 "sql.yacc"
    {
		SPRINTF1((yyval.str)," %s ",(yyvsp[(1) - (1)].str));
		(yyval.sql_string)=acl_strdup((yyval.str));
		add_feature("DDL_NOT_NULL");
	}
    break;

  case 229:

/* Line 1464 of yacc.c  */
#line 1710 "sql.yacc"
    {
		SPRINTF0((yyval.str)," NOT NULL UNIQUE ");
		(yyval.sql_string)=acl_strdup((yyval.str));
		add_feature("DDL_NOT_NULL");
		add_feature("DDL_UNIQUE");
	}
    break;

  case 230:

/* Line 1464 of yacc.c  */
#line 1716 "sql.yacc"
    {
		SPRINTF0((yyval.str)," UNIQUE ");
		(yyval.sql_string)=acl_strdup((yyval.str));
		add_feature("DDL_UNIQUE");
	}
    break;

  case 231:

/* Line 1464 of yacc.c  */
#line 1721 "sql.yacc"
    {
		ansi_violation("Use UNIQUE not DISTINCT",0);
		SPRINTF0((yyval.str)," UNIQUE ");
		(yyval.sql_string)=acl_strdup((yyval.str));
		add_feature("DDL_DISTINCT");
	}
    break;

  case 232:

/* Line 1464 of yacc.c  */
#line 1727 "sql.yacc"
    {
		(yyval.sql_string)=acl_strdup((yyvsp[(1) - (1)].str));
	}
    break;

  case 233:

/* Line 1464 of yacc.c  */
#line 1730 "sql.yacc"
    {
		(yyval.sql_string)=make_sql_string_and_free(acl_strdup("CHECK ("),(yyvsp[(3) - (4)].sql_string),kw_cb,NULL);
		add_feature("DDL_CHECK");
		
	}
    break;

  case 234:

/* Line 1464 of yacc.c  */
#line 1735 "sql.yacc"
    {
		(yyval.sql_string)=make_sql_string_and_free(acl_strdup(" PRIMARY KEY "),NULL);
		add_feature("DDL_PRIMARY_KEY");
	}
    break;

  case 235:

/* Line 1464 of yacc.c  */
#line 1744 "sql.yacc"
    {
		add_feature("CREATE_SCHEMA");

(yyval.sql_string)=make_sql_string_and_free(acl_strdup((yyvsp[(1) - (3)].str)),kw_space,acl_strdup((yyvsp[(2) - (3)].str)),kw_space,acl_strdup((yyvsp[(3) - (3)].str)),NULL);
}
    break;

  case 236:

/* Line 1464 of yacc.c  */
#line 1753 "sql.yacc"
    {SPRINTF1((yyval.str)," %s",(yyvsp[(1) - (1)].str));}
    break;

  case 239:

/* Line 1464 of yacc.c  */
#line 1762 "sql.yacc"
    {
		(yyval.sql_string)=make_sql_string_and_free((yyvsp[(1) - (2)].sql_string),kw_space,(yyvsp[(2) - (2)].sql_string),NULL);
	}
    break;

  case 240:

/* Line 1464 of yacc.c  */
#line 1768 "sql.yacc"
    {
		(yyval.sql_string)=(yyvsp[(1) - (1)].sql_string);
	}
    break;

  case 241:

/* Line 1464 of yacc.c  */
#line 1771 "sql.yacc"
    {
		(yyval.sql_string)=acl_strdup((yyvsp[(1) - (1)].str));
	}
    break;

  case 242:

/* Line 1464 of yacc.c  */
#line 1782 "sql.yacc"
    {
		 add_feature("HAVING"); 
		(yyval.s_select_list_item)=(yyvsp[(2) - (2)].s_select_list_item);
	}
    break;

  case 243:

/* Line 1464 of yacc.c  */
#line 1791 "sql.yacc"
    {
		 (yyval.s_select_list_item)=(yyvsp[(2) - (2)].s_select_list_item);
	}
    break;

  case 244:

/* Line 1464 of yacc.c  */
#line 1798 "sql.yacc"
    {
		(yyval.u_table)=(yyvsp[(2) - (2)].u_table);
	}
    break;

  case 245:

/* Line 1464 of yacc.c  */
#line 1804 "sql.yacc"
    {(yyval.u_table)=(yyvsp[(1) - (1)].u_table);}
    break;

  case 246:

/* Line 1464 of yacc.c  */
#line 1805 "sql.yacc"
    {
		(yyval.u_table)=A4GLSQLPARSE_append_tablename((yyvsp[(1) - (3)].u_table),(yyvsp[(3) - (3)].u_table),E_OUTER_NONE,NULL);
	}
    break;

  case 247:

/* Line 1464 of yacc.c  */
#line 1808 "sql.yacc"
    {
		(yyval.u_table)=A4GLSQLPARSE_append_tablename((yyvsp[(1) - (4)].u_table),(yyvsp[(4) - (4)].u_table),E_OUTER_NORMAL,NULL);
		A4GL_warn("OUTER join *may* not be portable to non-informix database");
		add_feature("SELECT_OUTER");
	}
    break;

  case 248:

/* Line 1464 of yacc.c  */
#line 1813 "sql.yacc"
    {
		(yyval.u_table)=A4GLSQLPARSE_append_tablename((yyvsp[(1) - (6)].u_table),(yyvsp[(5) - (6)].u_table),E_OUTER_NORMAL,NULL);
		A4GL_warn("OUTER join *may* not be portable to non-informix database");
		add_feature("SELECT_OUTER");
	}
    break;

  case 249:

/* Line 1464 of yacc.c  */
#line 1824 "sql.yacc"
    {
		(yyval.u_table)=A4GLSQLPARSE_append_tablename((yyvsp[(1) - (5)].u_table),(yyvsp[(3) - (5)].u_table),E_OUTER_LEFT_OUTER, (yyvsp[(5) - (5)].s_select_list_item));
		add_feature("SELECT_OUTER");
	}
    break;

  case 250:

/* Line 1464 of yacc.c  */
#line 1828 "sql.yacc"
    {
		(yyval.u_table)=A4GLSQLPARSE_append_tablename((yyvsp[(1) - (5)].u_table),(yyvsp[(3) - (5)].u_table),E_INNER, (yyvsp[(5) - (5)].s_select_list_item));
		add_feature("SELECT_INNER");
	}
    break;

  case 252:

/* Line 1464 of yacc.c  */
#line 1836 "sql.yacc"
    {(yyval.u_table)=(yyvsp[(2) - (3)].u_table);}
    break;

  case 253:

/* Line 1464 of yacc.c  */
#line 1840 "sql.yacc"
    { 
			//A4GL_add_crud("SELECT",$<str>1);
			(yyval.u_table)=A4GLSQLPARSE_new_tablename((yyvsp[(1) - (1)].str),NULL);
	}
    break;

  case 254:

/* Line 1464 of yacc.c  */
#line 1844 "sql.yacc"
    { 
			//A4GL_add_crud("SELECT",$<str>1);
			(yyval.u_table)=A4GLSQLPARSE_new_tablename((yyvsp[(1) - (2)].str),(yyvsp[(2) - (2)].str));
	}
    break;

  case 255:

/* Line 1464 of yacc.c  */
#line 1848 "sql.yacc"
    { 
			//A4GL_add_crud("SELECT",$<str>1);
			(yyval.u_table)=A4GLSQLPARSE_new_tablename((yyvsp[(1) - (3)].str),(yyvsp[(3) - (3)].str));
	}
    break;

  case 256:

/* Line 1464 of yacc.c  */
#line 1855 "sql.yacc"
    {
			/* No from or where etc.. */
			/* eg.. select user ; */
			(yyval.s_select)=new_empty_select();
		}
    break;

  case 257:

/* Line 1464 of yacc.c  */
#line 1860 "sql.yacc"
    {
		(yyval.s_select)=(yyvsp[(2) - (2)].s_select);
		(yyval.s_select)->first=(yyvsp[(1) - (2)].u_table);
			A4GL_set_associated_mem( (yyval.s_select), (yyval.s_select)->first);
}
    break;

  case 258:

/* Line 1464 of yacc.c  */
#line 1868 "sql.yacc"
    {
		(yyval.s_select)=(yyvsp[(1) - (1)].s_select);
	}
    break;

  case 259:

/* Line 1464 of yacc.c  */
#line 1871 "sql.yacc"
    {
		(yyval.s_select)=(yyvsp[(2) - (2)].s_select);
		(yyval.s_select)->where_clause=(yyvsp[(1) - (2)].s_select_list_item);
	}
    break;

  case 260:

/* Line 1464 of yacc.c  */
#line 1877 "sql.yacc"
    {
		(yyval.s_select)=new_empty_select();
	}
    break;

  case 261:

/* Line 1464 of yacc.c  */
#line 1880 "sql.yacc"
    {
		(yyval.s_select)=new_empty_select();
		(yyval.s_select)->group_by=(yyvsp[(1) - (1)].s_select_list_item_list);
		(yyval.s_select)->having=0;
	}
    break;

  case 262:

/* Line 1464 of yacc.c  */
#line 1885 "sql.yacc"
    {
		(yyval.s_select)=new_empty_select();
		(yyval.s_select)->group_by=(yyvsp[(1) - (2)].s_select_list_item_list);
		(yyval.s_select)->having=(yyvsp[(2) - (2)].s_select_list_item);
	}
    break;

  case 263:

/* Line 1464 of yacc.c  */
#line 1890 "sql.yacc"
    {
		(yyval.s_select)=new_empty_select();
		(yyval.s_select)->group_by=0;
		(yyval.s_select)->having=(yyvsp[(1) - (1)].s_select_list_item);

	}
    break;

  case 264:

/* Line 1464 of yacc.c  */
#line 1903 "sql.yacc"
    {
		(yyval.s_select_list_item)=(yyvsp[(1) - (1)].s_select_list_item);
	}
    break;

  case 265:

/* Line 1464 of yacc.c  */
#line 1906 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_op_expr((yyvsp[(1) - (3)].s_select_list_item),(yyvsp[(3) - (3)].s_select_list_item)," OR ");
	}
    break;

  case 266:

/* Line 1464 of yacc.c  */
#line 1912 "sql.yacc"
    {
		(yyval.s_select_list_item)=(yyvsp[(1) - (1)].s_select_list_item);
	}
    break;

  case 267:

/* Line 1464 of yacc.c  */
#line 1915 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_op_expr((yyvsp[(1) - (3)].s_select_list_item),(yyvsp[(3) - (3)].s_select_list_item)," AND ");
	}
    break;

  case 268:

/* Line 1464 of yacc.c  */
#line 1921 "sql.yacc"
    {
		(yyval.s_select_list_item)=(yyvsp[(1) - (1)].s_select_list_item);
	}
    break;

  case 269:

/* Line 1464 of yacc.c  */
#line 1924 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_simple_expr(E_SLI_NOT,(yyvsp[(2) - (2)].s_select_list_item));
	}
    break;

  case 270:

/* Line 1464 of yacc.c  */
#line 1930 "sql.yacc"
    {
		(yyval.s_select_list_item)=(yyvsp[(1) - (1)].s_select_list_item);
	}
    break;

  case 271:

/* Line 1464 of yacc.c  */
#line 1933 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_simple_expr(E_SLI_BRACKET_EXPR,(yyvsp[(2) - (3)].s_select_list_item));
	}
    break;

  case 272:

/* Line 1464 of yacc.c  */
#line 1940 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_sq(E_SQE_EXISTS, (yyvsp[(2) - (2)].s_select_list_item));
		add_feature("WHERE_EXISTS");
	}
    break;

  case 273:

/* Line 1464 of yacc.c  */
#line 1944 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_sq(E_SQE_NOT_EXISTS, (yyvsp[(2) - (2)].s_select_list_item));
		add_feature("WHERE_EXISTS");
	}
    break;

  case 274:

/* Line 1464 of yacc.c  */
#line 1955 "sql.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 275:

/* Line 1464 of yacc.c  */
#line 1955 "sql.yacc"
    {SPRINTF1((yyval.str)," ESCAPE %s",(yyvsp[(2) - (2)].str));add_feature("WHERE_MATCHES_ESCAPE");}
    break;

  case 276:

/* Line 1464 of yacc.c  */
#line 1956 "sql.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 277:

/* Line 1464 of yacc.c  */
#line 1956 "sql.yacc"
    {SPRINTF1((yyval.str)," ESCAPE %s",(yyvsp[(2) - (2)].str));add_feature("WHERE_ILIKE_ESCAPE");}
    break;

  case 278:

/* Line 1464 of yacc.c  */
#line 1957 "sql.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 279:

/* Line 1464 of yacc.c  */
#line 1957 "sql.yacc"
    {SPRINTF1((yyval.str)," ESCAPE %s",(yyvsp[(2) - (2)].str));add_feature("WHERE_LIKE_ESCAPE");}
    break;

  case 280:

/* Line 1464 of yacc.c  */
#line 1960 "sql.yacc"
    {
		 (yyval.s_select_list_item)=(yyvsp[(1) - (1)].s_select_list_item);
	}
    break;

  case 282:

/* Line 1464 of yacc.c  */
#line 1970 "sql.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 283:

/* Line 1464 of yacc.c  */
#line 1971 "sql.yacc"
    {strcpy((yyval.str)," NOT ");}
    break;

  case 284:

/* Line 1464 of yacc.c  */
#line 1976 "sql.yacc"
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
#line 1985 "sql.yacc"
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
#line 1993 "sql.yacc"
    { 
			(yyval.s_select_list_item)=new_select_list_item_op_expr((yyvsp[(1) - (3)].s_select_list_item),(yyvsp[(3) - (3)].s_select_list_item),(yyvsp[(2) - (3)].str));
	}
    break;

  case 287:

/* Line 1464 of yacc.c  */
#line 1996 "sql.yacc"
    { 
			(yyval.s_select_list_item)=new_select_list_item_op_expr((yyvsp[(1) - (3)].s_select_list_item),(yyvsp[(3) - (3)].s_select_list_item),"=");
	}
    break;

  case 288:

/* Line 1464 of yacc.c  */
#line 1999 "sql.yacc"
    { 
			FPRINTF(stderr,"Warning: Corrected =NULL to IS NULL line %d\n",yylineno);
			(yyval.s_select_list_item)=new_select_list_item_simple_expr(E_SLI_ISNULL,(yyvsp[(1) - (3)].s_select_list_item));
	}
    break;

  case 289:

/* Line 1464 of yacc.c  */
#line 2003 "sql.yacc"
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
#line 2010 "sql.yacc"
    { 
			(yyval.s_select_list_item)=new_select_list_item_regex(E_SLI_REGEX_LIKE,(yyvsp[(1) - (4)].s_select_list_item),(yyvsp[(3) - (4)].s_select_list_item),(yyvsp[(4) - (4)].str));
	}
    break;

  case 291:

/* Line 1464 of yacc.c  */
#line 2013 "sql.yacc"
    { 
			(yyval.s_select_list_item)=new_select_list_item_regex(E_SLI_REGEX_NOT_LIKE,(yyvsp[(1) - (4)].s_select_list_item),(yyvsp[(3) - (4)].s_select_list_item),(yyvsp[(4) - (4)].str));

	}
    break;

  case 292:

/* Line 1464 of yacc.c  */
#line 2017 "sql.yacc"
    { 
			(yyval.s_select_list_item)=new_select_list_item_regex(E_SLI_REGEX_ILIKE,(yyvsp[(1) - (4)].s_select_list_item),(yyvsp[(3) - (4)].s_select_list_item),(yyvsp[(4) - (4)].str));
	}
    break;

  case 293:

/* Line 1464 of yacc.c  */
#line 2020 "sql.yacc"
    { 
			(yyval.s_select_list_item)=new_select_list_item_regex(E_SLI_REGEX_NOT_ILIKE,(yyvsp[(1) - (4)].s_select_list_item),(yyvsp[(3) - (4)].s_select_list_item),(yyvsp[(4) - (4)].str));
	}
    break;

  case 294:

/* Line 1464 of yacc.c  */
#line 2023 "sql.yacc"
    { 
			(yyval.s_select_list_item)=new_select_list_item_regex(E_SLI_REGEX_MATCHES,(yyvsp[(1) - (4)].s_select_list_item),(yyvsp[(3) - (4)].s_select_list_item),(yyvsp[(4) - (4)].str));
	}
    break;

  case 295:

/* Line 1464 of yacc.c  */
#line 2026 "sql.yacc"
    { 
			(yyval.s_select_list_item)=new_select_list_item_regex(E_SLI_REGEX_NOT_MATCHES,(yyvsp[(1) - (4)].s_select_list_item),(yyvsp[(3) - (4)].s_select_list_item),(yyvsp[(4) - (4)].str));
	}
    break;

  case 296:

/* Line 1464 of yacc.c  */
#line 2032 "sql.yacc"
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
#line 2039 "sql.yacc"
    {
			strcpy((yyval.str)," < ");
	}
    break;

  case 298:

/* Line 1464 of yacc.c  */
#line 2042 "sql.yacc"
    {
			strcpy((yyval.str)," > ");
	}
    break;

  case 299:

/* Line 1464 of yacc.c  */
#line 2045 "sql.yacc"
    {
			strcpy((yyval.str)," ~ ");
	}
    break;

  case 300:

/* Line 1464 of yacc.c  */
#line 2048 "sql.yacc"
    {strcpy((yyval.str)," <= ");}
    break;

  case 301:

/* Line 1464 of yacc.c  */
#line 2049 "sql.yacc"
    {strcpy((yyval.str)," >= ");}
    break;

  case 302:

/* Line 1464 of yacc.c  */
#line 2054 "sql.yacc"
    {
		(yyval.s_select_list_item)=(yyvsp[(1) - (1)].s_select_list_item);
	}
    break;

  case 303:

/* Line 1464 of yacc.c  */
#line 2057 "sql.yacc"
    {
		(yyval.s_select_list_item)=(yyvsp[(1) - (1)].s_select_list_item);
	}
    break;

  case 304:

/* Line 1464 of yacc.c  */
#line 2060 "sql.yacc"
    {
		(yyval.s_select_list_item)=(yyvsp[(1) - (1)].s_select_list_item);
	}
    break;

  case 305:

/* Line 1464 of yacc.c  */
#line 2063 "sql.yacc"
    {
                 (yyval.s_select_list_item)=(yyvsp[(1) - (1)].s_select_list_item);
        }
    break;

  case 306:

/* Line 1464 of yacc.c  */
#line 2070 "sql.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 307:

/* Line 1464 of yacc.c  */
#line 2071 "sql.yacc"
    {strcpy((yyval.str)," ALL "); add_feature("AGG_ALL");}
    break;

  case 308:

/* Line 1464 of yacc.c  */
#line 2072 "sql.yacc"
    {
		strcpy((yyval.str)," DISTINCT ");
		add_feature("AGG_DISTINCT");
	}
    break;

  case 309:

/* Line 1464 of yacc.c  */
#line 2076 "sql.yacc"
    {
		ansi_violation("Use DISTINCT not UNIQUE",0);
		strcpy((yyval.str)," DISTINCT ");
		add_feature("AGG_DISTINCT");
	}
    break;

  case 310:

/* Line 1464 of yacc.c  */
#line 2083 "sql.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 311:

/* Line 1464 of yacc.c  */
#line 2084 "sql.yacc"
    {strcpy((yyval.str)," ALL "); add_feature("UNION_ALL");}
    break;

  case 312:

/* Line 1464 of yacc.c  */
#line 2085 "sql.yacc"
    {
		strcpy((yyval.str)," DISTINCT ");
		add_feature("UNION_DISTINCT");
	}
    break;

  case 313:

/* Line 1464 of yacc.c  */
#line 2089 "sql.yacc"
    {
		ansi_violation("Use DISTINCT not UNIQUE",0);
		add_feature("UNION_DISTINCT");
		strcpy((yyval.str)," DISTINCT ");
	}
    break;

  case 314:

/* Line 1464 of yacc.c  */
#line 2103 "sql.yacc"
    {
		strcpy((yyval.str),A4GLSQLCV_dtype_alias((yyvsp[(1) - (1)].str)));
	}
    break;

  case 319:

/* Line 1464 of yacc.c  */
#line 2118 "sql.yacc"
    {SPRINTF4((yyval.str)," %s %s%s%s",(yyvsp[(1) - (4)].str),(yyvsp[(2) - (4)].str),(yyvsp[(3) - (4)].str),(yyvsp[(4) - (4)].str));}
    break;

  case 320:

/* Line 1464 of yacc.c  */
#line 2122 "sql.yacc"
    {strcpy((yyval.str),"SERIAL"); add_feature("DDL_SERIAL"); }
    break;

  case 321:

/* Line 1464 of yacc.c  */
#line 2123 "sql.yacc"
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
#line 2132 "sql.yacc"
    {strcpy((yyval.str),"SERIAL8"); add_feature("DDL_SERIAL8"); }
    break;

  case 323:

/* Line 1464 of yacc.c  */
#line 2134 "sql.yacc"
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
#line 2143 "sql.yacc"
    {
 			add_feature("DDL_DECIMAL");
	}
    break;

  case 325:

/* Line 1464 of yacc.c  */
#line 2146 "sql.yacc"
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
#line 2154 "sql.yacc"
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
#line 2164 "sql.yacc"
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
#line 2172 "sql.yacc"
    {strcpy((yyval.str),"DATE");
 			add_feature("DDL_DATE"); }
    break;

  case 329:

/* Line 1464 of yacc.c  */
#line 2174 "sql.yacc"
    {strcpy((yyval.str),"INTEGER");}
    break;

  case 330:

/* Line 1464 of yacc.c  */
#line 2175 "sql.yacc"
    {strcpy((yyval.str),"SMALLINT");}
    break;

  case 331:

/* Line 1464 of yacc.c  */
#line 2176 "sql.yacc"
    {strcpy((yyval.str),"NCHAR"); add_feature("DDL_NCHAR");}
    break;

  case 332:

/* Line 1464 of yacc.c  */
#line 2177 "sql.yacc"
    {SPRINTF1((yyval.str),"NCHAR(%s)",(yyvsp[(3) - (4)].str)); add_feature("DDL_NCHAR");}
    break;

  case 333:

/* Line 1464 of yacc.c  */
#line 2178 "sql.yacc"
    {add_feature("DDL_NVARCHAR");}
    break;

  case 334:

/* Line 1464 of yacc.c  */
#line 2179 "sql.yacc"
    {SPRINTF1((yyval.str),"NVARCHAR(%s)",(yyvsp[(3) - (4)].str)); add_feature("DDL_NVARCHAR");}
    break;

  case 335:

/* Line 1464 of yacc.c  */
#line 2180 "sql.yacc"
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
#line 2188 "sql.yacc"
    {SPRINTF2((yyval.str),"DATETIME %s TO %s",(yyvsp[(2) - (4)].str),(yyvsp[(4) - (4)].str)); add_feature("DDL_DATETIME");}
    break;

  case 337:

/* Line 1464 of yacc.c  */
#line 2189 "sql.yacc"
    {add_feature("DDL_DATETIME");}
    break;

  case 338:

/* Line 1464 of yacc.c  */
#line 2190 "sql.yacc"
    {SPRINTF2((yyval.str),"INTERVAL %s TO %s",(yyvsp[(2) - (4)].str),(yyvsp[(4) - (4)].str)); add_feature("DDL_INTERVAL");}
    break;

  case 339:

/* Line 1464 of yacc.c  */
#line 2191 "sql.yacc"
    {strcpy((yyval.str),(yyvsp[(1) - (1)].str));}
    break;

  case 340:

/* Line 1464 of yacc.c  */
#line 2192 "sql.yacc"
    {add_feature("DDL_INTERVAL");}
    break;

  case 341:

/* Line 1464 of yacc.c  */
#line 2193 "sql.yacc"
    {SPRINTF3((yyval.str),"INTERVAL %s(%s) TO %s",(yyvsp[(2) - (7)].str),(yyvsp[(4) - (7)].str),(yyvsp[(7) - (7)].str)); add_feature("DDL_INTERVAL");}
    break;

  case 342:

/* Line 1464 of yacc.c  */
#line 2194 "sql.yacc"
    {add_feature("DDL_TEXT");}
    break;

  case 343:

/* Line 1464 of yacc.c  */
#line 2195 "sql.yacc"
    {add_feature("DDL_BYTE");}
    break;

  case 344:

/* Line 1464 of yacc.c  */
#line 2196 "sql.yacc"
    {add_feature("DDL_VARCHAR");}
    break;

  case 345:

/* Line 1464 of yacc.c  */
#line 2197 "sql.yacc"
    {SPRINTF1((yyval.str),"VARCHAR(%s)",(yyvsp[(3) - (4)].str));add_feature("DDL_VARCHAR");}
    break;

  case 346:

/* Line 1464 of yacc.c  */
#line 2198 "sql.yacc"
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
#line 2208 "sql.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 348:

/* Line 1464 of yacc.c  */
#line 2209 "sql.yacc"
    {
		SPRINTF1((yyval.str),",%s",(yyvsp[(2) - (2)].str));
}
    break;

  case 349:

/* Line 1464 of yacc.c  */
#line 2216 "sql.yacc"
    {SPRINTF4((yyval.str)," %s %s %s %s",(yyvsp[(1) - (4)].str),(yyvsp[(2) - (4)].str),(yyvsp[(3) - (4)].str),(yyvsp[(4) - (4)].str));}
    break;

  case 353:

/* Line 1464 of yacc.c  */
#line 2220 "sql.yacc"
    {add_feature("DDL_DOUBLE_PRECISION"); SPRINTF1((yyval.str)," %s",(yyvsp[(1) - (1)].str));}
    break;

  case 359:

/* Line 1464 of yacc.c  */
#line 2245 "sql.yacc"
    {(yyval.int_list.i0)=0;}
    break;

  case 360:

/* Line 1464 of yacc.c  */
#line 2246 "sql.yacc"
    {
		(yyval.int_list.i0)=1;
		(yyval.int_list.i1)=atoi((yyvsp[(2) - (3)].str));
	}
    break;

  case 361:

/* Line 1464 of yacc.c  */
#line 2250 "sql.yacc"
    {
		(yyval.int_list.i0)=2;
		(yyval.int_list.i1)=atoi((yyvsp[(2) - (5)].str));
		(yyval.int_list.i2)=atoi((yyvsp[(4) - (5)].str));
	}
    break;

  case 362:

/* Line 1464 of yacc.c  */
#line 2258 "sql.yacc"
    {
		strcpy((yyval.str),(yyvsp[(1) - (1)].str));
	}
    break;

  case 363:

/* Line 1464 of yacc.c  */
#line 2261 "sql.yacc"
    {
		strcpy((yyval.str),(yyvsp[(2) - (2)].str));
	}
    break;

  case 364:

/* Line 1464 of yacc.c  */
#line 2268 "sql.yacc"
    {
		(yyval.s_select_list_item)= (yyvsp[(1) - (1)].s_select_list_item);
	}
    break;

  case 365:

/* Line 1464 of yacc.c  */
#line 2271 "sql.yacc"
    {
		(yyval.s_select_list_item)= (yyvsp[(2) - (2)].s_select_list_item);
	}
    break;

  case 366:

/* Line 1464 of yacc.c  */
#line 2281 "sql.yacc"
    { 
		(yyval.s_select_list_item)=new_select_list_item_col(0,(yyvsp[(1) - (2)].str),&(yyvsp[(2) - (2)].int_list));
	}
    break;

  case 367:

/* Line 1464 of yacc.c  */
#line 2284 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_col((yyvsp[(1) - (4)].str),(yyvsp[(3) - (4)].str),&(yyvsp[(4) - (4)].int_list));
	}
    break;

  case 368:

/* Line 1464 of yacc.c  */
#line 2287 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_col((yyvsp[(1) - (3)].str),"*",0);
	}
    break;

  case 369:

/* Line 1464 of yacc.c  */
#line 2290 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_col(0,"rowid",0);
	}
    break;

  case 370:

/* Line 1464 of yacc.c  */
#line 2297 "sql.yacc"
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
#line 2304 "sql.yacc"
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
#line 2312 "sql.yacc"
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
#line 2321 "sql.yacc"
    {
		SPRINTF1((yyval.str),"%s",A4GLSQLCV_check_colname((yyvsp[(1) - (3)].str),"*"));
		ADDMAP("Use Column",(yyval.str));
	}
    break;

  case 375:

/* Line 1464 of yacc.c  */
#line 2332 "sql.yacc"
    { strcpy((yyval.str),(yyvsp[(1) - (1)].str)); 
#ifdef DEBUG
A4GL_debug("Set $<str>$ to %s\n",(yyval.str)); 
#endif
}
    break;

  case 379:

/* Line 1464 of yacc.c  */
#line 2344 "sql.yacc"
    { strcpy((yyval.str),A4GLSQLCV_generate_current(0,0)); }
    break;

  case 380:

/* Line 1464 of yacc.c  */
#line 2345 "sql.yacc"
    {
		strcpy((yyval.str),A4GLSQLCV_generate_current((yyvsp[(1) - (3)].str),(yyvsp[(3) - (3)].str)));
	}
    break;

  case 395:

/* Line 1464 of yacc.c  */
#line 2355 "sql.yacc"
    {SPRINTF1((yyval.str),"FRACTION(%s)",(yyvsp[(3) - (4)].str));}
    break;

  case 396:

/* Line 1464 of yacc.c  */
#line 2400 "sql.yacc"
    { (yyval.sql_string)=make_sql_string_and_free(acl_strdup((yyvsp[(1) - (1)].str)), NULL);}
    break;

  case 397:

/* Line 1464 of yacc.c  */
#line 2401 "sql.yacc"
    { (yyval.sql_string)=make_sql_string_and_free(acl_strdup((yyvsp[(1) - (1)].str)), NULL);}
    break;

  case 398:

/* Line 1464 of yacc.c  */
#line 2402 "sql.yacc"
    { (yyval.sql_string)=make_sql_string_and_free(acl_strdup((yyvsp[(1) - (1)].str)), NULL);}
    break;

  case 399:

/* Line 1464 of yacc.c  */
#line 2407 "sql.yacc"
    { add_feature("RENAME_TABLE"); strcpy((yyval.str),A4GLSQLCV_rentab((yyvsp[(2) - (4)].str),(yyvsp[(4) - (4)].str))); }
    break;

  case 400:

/* Line 1464 of yacc.c  */
#line 2408 "sql.yacc"
    { add_feature("RENAME_COLUMN"); strcpy((yyval.str),A4GLSQLCV_rencol((yyvsp[(2) - (6)].str),(yyvsp[(4) - (6)].str),(yyvsp[(6) - (6)].str)) ); }
    break;

  case 403:

/* Line 1464 of yacc.c  */
#line 2416 "sql.yacc"
    {
		add_feature("UNLOCK_TABLE");
		SPRINTF2((yyval.str),"%s %s",(yyvsp[(1) - (2)].str),(yyvsp[(2) - (2)].str));
	}
    break;

  case 404:

/* Line 1464 of yacc.c  */
#line 2423 "sql.yacc"
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
#line 2434 "sql.yacc"
    { add_feature("LOCK_TABLE_SHARED");}
    break;

  case 406:

/* Line 1464 of yacc.c  */
#line 2435 "sql.yacc"
    {add_feature("LOCK_TABLE_EXCLUSIVE");}
    break;

  case 407:

/* Line 1464 of yacc.c  */
#line 2448 "sql.yacc"
    {strcpy((yyval.str),A4GLSQLCV_datetime_value((yyvsp[(1) - (1)].str)));}
    break;

  case 408:

/* Line 1464 of yacc.c  */
#line 2449 "sql.yacc"
    {strcpy((yyval.str),A4GLSQLCV_make_dtime_extend((yyvsp[(1) - (4)].str),(yyvsp[(2) - (4)].str),(yyvsp[(4) - (4)].str),0));}
    break;

  case 409:

/* Line 1464 of yacc.c  */
#line 2453 "sql.yacc"
    {strcpy((yyval.str),(yyvsp[(1) - (1)].str));}
    break;

  case 410:

/* Line 1464 of yacc.c  */
#line 2457 "sql.yacc"
    {strcpy((yyval.str),A4GLSQLCV_interval_value((yyvsp[(1) - (1)].str)));}
    break;

  case 411:

/* Line 1464 of yacc.c  */
#line 2458 "sql.yacc"
    {
			strcpy((yyval.str),A4GLSQLCV_make_ival_extend((yyvsp[(1) - (7)].str),(yyvsp[(2) - (7)].str),(yyvsp[(4) - (7)].str),(yyvsp[(7) - (7)].str),0));
		}
    break;

  case 412:

/* Line 1464 of yacc.c  */
#line 2461 "sql.yacc"
    {
		strcpy((yyval.str),A4GLSQLCV_make_ival_extend((yyvsp[(1) - (4)].str),(yyvsp[(2) - (4)].str),(char *)0, (yyvsp[(4) - (4)].str),0));
	}
    break;

  case 413:

/* Line 1464 of yacc.c  */
#line 2467 "sql.yacc"
    {SPRINTF1((yyval.str),"%s",(yyvsp[(1) - (1)].str));}
    break;

  case 414:

/* Line 1464 of yacc.c  */
#line 2471 "sql.yacc"
    {
	strcpy((yyval.str),(yyvsp[(2) - (2)].str));
}
    break;

  case 415:

/* Line 1464 of yacc.c  */
#line 2494 "sql.yacc"
    {
		(yyval.s_select_list_item_list)=(yyvsp[(3) - (3)].s_select_list_item_list);
		add_feature("ORDER_BY");
	}
    break;

  case 416:

/* Line 1464 of yacc.c  */
#line 2504 "sql.yacc"
    {
			(yyval.s_select_list_item_list)=local_new_select_list_item_list((yyvsp[(1) - (1)].s_select_list_item));
	}
    break;

  case 417:

/* Line 1464 of yacc.c  */
#line 2507 "sql.yacc"
    {
			(yyval.s_select_list_item_list)=local_add_select_list_item_list((yyvsp[(1) - (3)].s_select_list_item_list),(yyvsp[(3) - (3)].s_select_list_item));
	}
    break;

  case 418:

/* Line 1464 of yacc.c  */
#line 2513 "sql.yacc"
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
#line 2522 "sql.yacc"
    { 
		add_feature("ORDER_BY_NUMBER");
		(yyval.s_select_list_item)=new_select_list_item_literal((yyvsp[(1) - (1)].str));
	}
    break;

  case 420:

/* Line 1464 of yacc.c  */
#line 2526 "sql.yacc"
    {
		(yyval.s_select_list_item)=(yyvsp[(1) - (1)].s_select_list_item);
		(yyval.s_select_list_item)->data.type=E_SLI_COLUMN_ORDERBY;
	}
    break;

  case 421:

/* Line 1464 of yacc.c  */
#line 2533 "sql.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 422:

/* Line 1464 of yacc.c  */
#line 2535 "sql.yacc"
    {add_feature("ORDER_BY_ASC"); strcpy((yyval.str),"ASC");}
    break;

  case 423:

/* Line 1464 of yacc.c  */
#line 2537 "sql.yacc"
    {add_feature("ORDER_BY_DESC"); strcpy((yyval.str),"DESC");}
    break;

  case 424:

/* Line 1464 of yacc.c  */
#line 2541 "sql.yacc"
    {
		(yyval.s_select_list_item_list)=(yyvsp[(2) - (2)].s_select_list_item_list);
	}
    break;

  case 425:

/* Line 1464 of yacc.c  */
#line 2547 "sql.yacc"
    {
			(yyval.s_select_list_item_list)=local_new_select_list_item_list((yyvsp[(1) - (1)].s_select_list_item));
	}
    break;

  case 426:

/* Line 1464 of yacc.c  */
#line 2550 "sql.yacc"
    {
			(yyval.s_select_list_item_list)=local_add_select_list_item_list((yyvsp[(1) - (3)].s_select_list_item_list),(yyvsp[(3) - (3)].s_select_list_item));
	}
    break;

  case 427:

/* Line 1464 of yacc.c  */
#line 2556 "sql.yacc"
    { (yyval.s_select_list_item)=(yyvsp[(1) - (1)].s_select_list_item); }
    break;

  case 428:

/* Line 1464 of yacc.c  */
#line 2557 "sql.yacc"
    { (yyval.s_select_list_item)=new_select_list_item_literal((yyvsp[(1) - (1)].str)); }
    break;

  case 429:

/* Line 1464 of yacc.c  */
#line 2564 "sql.yacc"
    {
	(yyval.sql_string)=get_select_list_item(0,(yyvsp[(1) - (1)].s_select_list_item));
}
    break;

  case 430:

/* Line 1464 of yacc.c  */
#line 2577 "sql.yacc"
    {
		A4GL_set_sql_lineno(yylineno);
		(yyval.sql_string)=make_select_stmt_v2(current_upd_table, (yyvsp[(1) - (1)].s_select),"");
		map_select_stmt("SELECT",(yyvsp[(1) - (1)].s_select));
		A4GL_free_select_stmt((yyvsp[(1) - (1)].s_select));
}
    break;

  case 431:

/* Line 1464 of yacc.c  */
#line 2587 "sql.yacc"
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
#line 2594 "sql.yacc"
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
#line 2611 "sql.yacc"
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
#line 2618 "sql.yacc"
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
#line 2643 "sql.yacc"
    { 
		//start_bind('i',0);
		 set_ignore_indicators();}
    break;

  case 436:

/* Line 1464 of yacc.c  */
#line 2645 "sql.yacc"
    { clr_ignore_indicators();}
    break;

  case 437:

/* Line 1464 of yacc.c  */
#line 2647 "sql.yacc"
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
#line 2668 "sql.yacc"
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
#line 2711 "sql.yacc"
    { (yyval.s_select)=0;}
    break;

  case 440:

/* Line 1464 of yacc.c  */
#line 2712 "sql.yacc"
    { 
		(yyval.s_select)=(yyvsp[(3) - (3)].s_select);
		(yyval.s_select)->union_op=acl_strdup((yyvsp[(2) - (3)].str));
		A4GL_set_associated_mem((yyval.s_select), (yyval.s_select)->union_op);
		add_feature("SELECT_UNION"); 
	}
    break;

  case 441:

/* Line 1464 of yacc.c  */
#line 2726 "sql.yacc"
    {
		(yyval.s_select_finish)=0;
	}
    break;

  case 442:

/* Line 1464 of yacc.c  */
#line 2729 "sql.yacc"
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
#line 2736 "sql.yacc"
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
#line 2746 "sql.yacc"
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
#line 2764 "sql.yacc"
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
#line 2777 "sql.yacc"
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
#line 2792 "sql.yacc"
    {(yyval.integer_val)=-1;}
    break;

  case 449:

/* Line 1464 of yacc.c  */
#line 2794 "sql.yacc"
    {
		(yyval.integer_val)=atol((yyvsp[(2) - (2)].str));
	}
    break;

  case 450:

/* Line 1464 of yacc.c  */
#line 2800 "sql.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 451:

/* Line 1464 of yacc.c  */
#line 2801 "sql.yacc"
    {strcpy((yyval.str),"ALL"); add_feature("SELECT_ALL");}
    break;

  case 452:

/* Line 1464 of yacc.c  */
#line 2802 "sql.yacc"
    {strcpy((yyval.str),"DISTINCT"); add_feature("SELECT_DISTINCT");}
    break;

  case 453:

/* Line 1464 of yacc.c  */
#line 2803 "sql.yacc"
    {strcpy((yyval.str),"DISTINCT");
		add_feature("SELECT_UNIQUE");
		ansi_violation("Use DISTINCT not UNIQUE",0);
		strcpy((yyval.str),"DISTINCT");
	}
    break;

  case 454:

/* Line 1464 of yacc.c  */
#line 2813 "sql.yacc"
    {
			(yyval.s_select_list_item_list)=rationalize_select_list_item_list((yyvsp[(1) - (1)].s_select_list_item_list));
		}
    break;

  case 455:

/* Line 1464 of yacc.c  */
#line 2820 "sql.yacc"
    { 
		 (yyval.s_select_list_item_list)=local_new_select_list_item_list((yyvsp[(1) - (1)].s_select_list_item));
	}
    break;

  case 456:

/* Line 1464 of yacc.c  */
#line 2823 "sql.yacc"
    { 
		(yyval.s_select_list_item_list)=local_add_select_list_item_list((yyvsp[(1) - (3)].s_select_list_item_list),(yyvsp[(3) - (3)].s_select_list_item));
	}
    break;

  case 457:

/* Line 1464 of yacc.c  */
#line 2829 "sql.yacc"
    {
		(yyval.s_select_list_item)=(yyvsp[(1) - (1)].s_select_list_item);
	}
    break;

  case 458:

/* Line 1464 of yacc.c  */
#line 2832 "sql.yacc"
    {
		(yyval.s_select_list_item)=(yyvsp[(1) - (2)].s_select_list_item);
		(yyval.s_select_list_item)->alias=acl_strdup((yyvsp[(2) - (2)].str));
		A4GL_set_associated_mem((yyval.s_select_list_item), (yyval.s_select_list_item)->alias);
	}
    break;

  case 459:

/* Line 1464 of yacc.c  */
#line 2837 "sql.yacc"
    {
		(yyval.s_select_list_item)=(yyvsp[(1) - (3)].s_select_list_item);
		(yyval.s_select_list_item)->alias=acl_strdup((yyvsp[(3) - (3)].str));
		A4GL_set_associated_mem((yyval.s_select_list_item), (yyval.s_select_list_item)->alias);
	}
    break;

  case 460:

/* Line 1464 of yacc.c  */
#line 2846 "sql.yacc"
    {
		(yyval.s_select_list_item)=(yyvsp[(1) - (1)].s_select_list_item); /* A4GLSQLCV_check_expr($<sql_string>1) */
	}
    break;

  case 461:

/* Line 1464 of yacc.c  */
#line 2849 "sql.yacc"
    {
		(yyval.s_select_list_item)=(yyvsp[(2) - (2)].s_select_list_item);
		(yyval.s_select_list_item)->sign='-';
	}
    break;

  case 462:

/* Line 1464 of yacc.c  */
#line 2853 "sql.yacc"
    {
		(yyval.s_select_list_item)=(yyvsp[(2) - (2)].s_select_list_item);
	}
    break;

  case 463:

/* Line 1464 of yacc.c  */
#line 2860 "sql.yacc"
    {
			(yyval.s_select_list_item)=new_select_list_item_op_expr ((yyvsp[(1) - (3)].s_select_list_item), (yyvsp[(3) - (3)].s_select_list_item), "/");
	}
    break;

  case 464:

/* Line 1464 of yacc.c  */
#line 2863 "sql.yacc"
    {
			(yyval.s_select_list_item)=new_select_list_item_simple_expr((enum e_sli)(yyvsp[(2) - (2)].integer_val), (yyvsp[(1) - (2)].s_select_list_item));
	}
    break;

  case 465:

/* Line 1464 of yacc.c  */
#line 2866 "sql.yacc"
    {
			(yyval.s_select_list_item)=new_select_list_item_op_expr ((yyvsp[(1) - (3)].s_select_list_item), (yyvsp[(3) - (3)].s_select_list_item), "*");
	}
    break;

  case 466:

/* Line 1464 of yacc.c  */
#line 2869 "sql.yacc"
    {
			(yyval.s_select_list_item)=new_select_list_item_op_expr ((yyvsp[(1) - (3)].s_select_list_item), (yyvsp[(3) - (3)].s_select_list_item), "+");
	}
    break;

  case 467:

/* Line 1464 of yacc.c  */
#line 2872 "sql.yacc"
    {
			(yyval.s_select_list_item)=new_select_list_item_op_expr ((yyvsp[(1) - (3)].s_select_list_item), (yyvsp[(3) - (3)].s_select_list_item), "-");
	}
    break;

  case 468:

/* Line 1464 of yacc.c  */
#line 2875 "sql.yacc"
    {
			(yyval.s_select_list_item)=new_select_list_item_op_expr ((yyvsp[(1) - (3)].s_select_list_item), (yyvsp[(3) - (3)].s_select_list_item), "||");
	}
    break;

  case 469:

/* Line 1464 of yacc.c  */
#line 2878 "sql.yacc"
    { (yyval.s_select_list_item)=new_select_list_item_literal((yyvsp[(1) - (1)].str)); }
    break;

  case 470:

/* Line 1464 of yacc.c  */
#line 2879 "sql.yacc"
    { (yyval.s_select_list_item)=new_select_list_item_builtin_const(E_SLI_BUILTIN_CONST_TRUE); }
    break;

  case 471:

/* Line 1464 of yacc.c  */
#line 2880 "sql.yacc"
    { (yyval.s_select_list_item)=new_select_list_item_builtin_const(E_SLI_BUILTIN_CONST_FALSE); }
    break;

  case 472:

/* Line 1464 of yacc.c  */
#line 2881 "sql.yacc"
    { (yyval.s_select_list_item)=new_select_list_item_builtin_const(E_SLI_BUILTIN_CONST_USER); }
    break;

  case 473:

/* Line 1464 of yacc.c  */
#line 2882 "sql.yacc"
    { (yyval.s_select_list_item)=new_select_list_item_builtin_const(E_SLI_BUILTIN_CONST_TODAY); }
    break;

  case 474:

/* Line 1464 of yacc.c  */
#line 2883 "sql.yacc"
    { (yyval.s_select_list_item)=new_select_list_item_builtin_const(E_SLI_BUILTIN_CONST_ROWID); }
    break;

  case 475:

/* Line 1464 of yacc.c  */
#line 2884 "sql.yacc"
    { (yyval.s_select_list_item)=new_select_list_item_builtin_const(E_SLI_BUILTIN_CONST_TIME); }
    break;

  case 476:

/* Line 1464 of yacc.c  */
#line 2885 "sql.yacc"
    { (yyval.s_select_list_item)=new_select_list_item_builtin_const(E_SLI_BUILTIN_CONST_STAR); }
    break;

  case 477:

/* Line 1464 of yacc.c  */
#line 2886 "sql.yacc"
    { (yyval.s_select_list_item)=new_select_list_item_builtin_const(E_SLI_BUILTIN_CONST_COUNT_STAR); }
    break;

  case 478:

/* Line 1464 of yacc.c  */
#line 2888 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_agg1(E_SLI_BUILTIN_AGG_AVG,(yyvsp[(3) - (5)].str),(yyvsp[(4) - (5)].s_select_list_item));
		add_feature("SELECT_AVG");
	}
    break;

  case 479:

/* Line 1464 of yacc.c  */
#line 2892 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_agg1(E_SLI_BUILTIN_AGG_MAX,(yyvsp[(3) - (5)].str),(yyvsp[(4) - (5)].s_select_list_item));
		add_feature("SELECT_MAX");
	}
    break;

  case 480:

/* Line 1464 of yacc.c  */
#line 2896 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_agg1(E_SLI_BUILTIN_AGG_MIN,(yyvsp[(3) - (5)].str),(yyvsp[(4) - (5)].s_select_list_item));
		add_feature("SELECT_MIN");
	}
    break;

  case 481:

/* Line 1464 of yacc.c  */
#line 2900 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_agg1(E_SLI_BUILTIN_AGG_SUM,(yyvsp[(3) - (5)].str),(yyvsp[(4) - (5)].s_select_list_item));
		add_feature("SELECT_SUM");
	}
    break;

  case 482:

/* Line 1464 of yacc.c  */
#line 2904 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_agg1(E_SLI_BUILTIN_AGG_COUNT,(yyvsp[(3) - (5)].str),(yyvsp[(4) - (5)].s_select_list_item));
		add_feature("SELECT_COUNT");
	}
    break;

  case 483:

/* Line 1464 of yacc.c  */
#line 2908 "sql.yacc"
    {
		add_sql_function((yyvsp[(1) - (3)].str));
		(yyval.s_select_list_item)=new_select_list_item_fcall((yyvsp[(1) - (3)].str),0);
	}
    break;

  case 484:

/* Line 1464 of yacc.c  */
#line 2912 "sql.yacc"
    {
		add_sql_function((yyvsp[(1) - (4)].str));
		(yyval.s_select_list_item)=new_select_list_item_fcall((yyvsp[(1) - (4)].str),(yyvsp[(3) - (4)].s_select_list_item_list));
	}
    break;

  case 485:

/* Line 1464 of yacc.c  */
#line 2916 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_builtin_fcall(E_SLI_BUILTIN_FUNC_YEAR,(yyvsp[(3) - (4)].s_select_list_item_list));
	}
    break;

  case 486:

/* Line 1464 of yacc.c  */
#line 2919 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_builtin_fcall(E_SLI_BUILTIN_FUNC_MONTH,(yyvsp[(3) - (4)].s_select_list_item_list));
	}
    break;

  case 487:

/* Line 1464 of yacc.c  */
#line 2922 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_builtin_fcall(E_SLI_BUILTIN_FUNC_DAY,(yyvsp[(3) - (4)].s_select_list_item_list));
	}
    break;

  case 488:

/* Line 1464 of yacc.c  */
#line 2925 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_builtin_fcall(E_SLI_BUILTIN_FUNC_MDY,(yyvsp[(3) - (4)].s_select_list_item_list));
	}
    break;

  case 489:

/* Line 1464 of yacc.c  */
#line 2928 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_builtin_fcall(E_SLI_BUILTIN_FUNC_WEEKDAY,(yyvsp[(3) - (4)].s_select_list_item_list));
	}
    break;

  case 490:

/* Line 1464 of yacc.c  */
#line 2931 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_builtin_fcall(E_SLI_BUILTIN_FUNC_DOW,(yyvsp[(3) - (4)].s_select_list_item_list));
	}
    break;

  case 491:

/* Line 1464 of yacc.c  */
#line 2934 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_builtin_fcall(E_SLI_BUILTIN_FUNC_DATE,(yyvsp[(3) - (4)].s_select_list_item_list));
	}
    break;

  case 492:

/* Line 1464 of yacc.c  */
#line 2937 "sql.yacc"
    {
		  (yyval.s_select_list_item)=new_select_list_item_simple_expr(E_SLI_BRACKET_EXPR,(yyvsp[(2) - (3)].s_select_list_item));
	}
    break;

  case 493:

/* Line 1464 of yacc.c  */
#line 2940 "sql.yacc"
    { 
		add_feature("EXTEND"); 
		(yyval.s_select_list_item)=(yyvsp[(3) - (4)].s_select_list_item);
	}
    break;

  case 494:

/* Line 1464 of yacc.c  */
#line 2944 "sql.yacc"
    { 
		(yyval.s_select_list_item)=new_select_list_item_datetime((yyvsp[(1) - (1)].str));
		add_feature("FUNC_DATETIME");
	}
    break;

  case 495:

/* Line 1464 of yacc.c  */
#line 2948 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_interval((yyvsp[(1) - (1)].str));
		add_feature("FUNC_INTERVAL");
	}
    break;

  case 496:

/* Line 1464 of yacc.c  */
#line 2952 "sql.yacc"
    {
		(yyval.s_select_list_item)=(yyvsp[(2) - (3)].s_select_list_item);
	}
    break;

  case 497:

/* Line 1464 of yacc.c  */
#line 2960 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_case((yyvsp[(1) - (1)].s_select_list_item));
	}
    break;

  case 498:

/* Line 1464 of yacc.c  */
#line 2963 "sql.yacc"
    {
		(yyval.s_select_list_item)=append_select_list_item_case(
							(yyvsp[(1) - (2)].s_select_list_item),
							(yyvsp[(2) - (2)].s_select_list_item));
	}
    break;

  case 499:

/* Line 1464 of yacc.c  */
#line 2972 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_case_element(
				(yyvsp[(2) - (4)].s_select_list_item),
				(yyvsp[(4) - (4)].s_select_list_item));

	}
    break;

  case 500:

/* Line 1464 of yacc.c  */
#line 2978 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_case_element( 0, (yyvsp[(2) - (2)].s_select_list_item));
	}
    break;

  case 501:

/* Line 1464 of yacc.c  */
#line 2985 "sql.yacc"
    {
		(yyval.s_select_list_item_list)=local_new_select_list_item_list((yyvsp[(1) - (1)].s_select_list_item));
	}
    break;

  case 502:

/* Line 1464 of yacc.c  */
#line 2988 "sql.yacc"
    {
			(yyval.s_select_list_item_list)=local_add_select_list_item_list((yyvsp[(1) - (3)].s_select_list_item_list),(yyvsp[(3) - (3)].s_select_list_item));
	}
    break;

  case 503:

/* Line 1464 of yacc.c  */
#line 3012 "sql.yacc"
    {(yyval.str_list)=NULL;}
    break;

  case 504:

/* Line 1464 of yacc.c  */
#line 3013 "sql.yacc"
    { (yyval.str_list)=new_str_list((yyvsp[(2) - (4)].str));  add_str_list((yyval.str_list),(yyvsp[(4) - (4)].str));}
    break;

  case 505:

/* Line 1464 of yacc.c  */
#line 3014 "sql.yacc"
    { (yyval.str_list)=new_str_list((yyvsp[(1) - (3)].str));  add_str_list((yyval.str_list),(yyvsp[(3) - (3)].str));}
    break;

  case 507:

/* Line 1464 of yacc.c  */
#line 3018 "sql.yacc"
    {
			(yyval.s_select_list_item)=new_select_list_item_extend((yyvsp[(1) - (2)].s_select_list_item),(yyvsp[(2) - (2)].str_list));
	}
    break;

  case 508:

/* Line 1464 of yacc.c  */
#line 3021 "sql.yacc"
    {
			(yyval.s_select_list_item)=new_select_list_item_extend((yyvsp[(1) - (2)].s_select_list_item),(yyvsp[(2) - (2)].str_list));
	}
    break;

  case 509:

/* Line 1464 of yacc.c  */
#line 3027 "sql.yacc"
    {(yyval.integer_val)=E_SLI_UNITS_YEAR;}
    break;

  case 510:

/* Line 1464 of yacc.c  */
#line 3028 "sql.yacc"
    {(yyval.integer_val)=E_SLI_UNITS_MONTH;}
    break;

  case 511:

/* Line 1464 of yacc.c  */
#line 3029 "sql.yacc"
    {(yyval.integer_val)=E_SLI_UNITS_DAY;}
    break;

  case 512:

/* Line 1464 of yacc.c  */
#line 3030 "sql.yacc"
    {(yyval.integer_val)=E_SLI_UNITS_HOUR;}
    break;

  case 513:

/* Line 1464 of yacc.c  */
#line 3031 "sql.yacc"
    {(yyval.integer_val)=E_SLI_UNITS_MINUTE;}
    break;

  case 514:

/* Line 1464 of yacc.c  */
#line 3032 "sql.yacc"
    {(yyval.integer_val)=E_SLI_UNITS_SECOND;}
    break;

  case 515:

/* Line 1464 of yacc.c  */
#line 3037 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_op_slil((yyvsp[(1) - (5)].s_select_list_item),(yyvsp[(4) - (5)].s_select_list_item_list),E_SLI_IN_VALUES);
                add_feature("WHERE_IN");
        }
    break;

  case 516:

/* Line 1464 of yacc.c  */
#line 3041 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_op_sli((yyvsp[(1) - (3)].s_select_list_item),(yyvsp[(3) - (3)].s_select_list_item),E_SLI_IN_SELECT);
                add_feature("WHERE_IN_SELECT");
        }
    break;

  case 517:

/* Line 1464 of yacc.c  */
#line 3045 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_op_slil((yyvsp[(1) - (5)].s_select_list_item),(yyvsp[(4) - (5)].s_select_list_item_list),E_SLI_NOT_IN_VALUES);
                add_feature("WHERE_IN");
        }
    break;

  case 518:

/* Line 1464 of yacc.c  */
#line 3049 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_op_sli((yyvsp[(1) - (3)].s_select_list_item),(yyvsp[(3) - (3)].s_select_list_item),E_SLI_NOT_IN_SELECT);
                add_feature("WHERE_IN_SELECT");
        }
    break;

  case 519:

/* Line 1464 of yacc.c  */
#line 3056 "sql.yacc"
    {
		(yyval.s_select_list_item_list)=local_new_select_list_item_list((yyvsp[(1) - (1)].s_select_list_item));
	}
    break;

  case 520:

/* Line 1464 of yacc.c  */
#line 3059 "sql.yacc"
    {
                (yyval.s_select_list_item_list)=local_add_select_list_item_list((yyvsp[(1) - (3)].s_select_list_item_list),(yyvsp[(3) - (3)].s_select_list_item));
	}
    break;

  case 521:

/* Line 1464 of yacc.c  */
#line 3064 "sql.yacc"
    { (yyval.s_select_list_item)=(yyvsp[(1) - (1)].s_select_list_item);}
    break;

  case 522:

/* Line 1464 of yacc.c  */
#line 3065 "sql.yacc"
    { (yyval.s_select_list_item)=new_select_list_item_literal((yyvsp[(1) - (1)].str)); }
    break;

  case 523:

/* Line 1464 of yacc.c  */
#line 3066 "sql.yacc"
    { 
		char buff[256]; SPRINTF1(buff," -%s",(yyvsp[(2) - (2)].str)); (yyval.s_select_list_item)=new_select_list_item_literal(buff); }
    break;

  case 524:

/* Line 1464 of yacc.c  */
#line 3068 "sql.yacc"
    { char buff[256]; SPRINTF1(buff," -%s",(yyvsp[(2) - (2)].str)); (yyval.s_select_list_item)=new_select_list_item_literal(buff); }
    break;

  case 525:

/* Line 1464 of yacc.c  */
#line 3074 "sql.yacc"
    {
                if (strstr((yyvsp[(1) - (1)].str),"systables")!=0) { add_feature("IFX_SYSTABLES"); }
                if (strstr((yyvsp[(1) - (1)].str),"syscolumns")!=0) { add_feature("IFX_SYSCOLUMNS"); }
                if (strstr((yyvsp[(1) - (1)].str),"sysindexes")!=0) { add_feature("IFX_SYSINDEXES"); }
                strcpy((yyval.str),A4GLSQLCV_check_tablename((yyvsp[(1) - (1)].str)));
                }
    break;

  case 526:

/* Line 1464 of yacc.c  */
#line 3084 "sql.yacc"
    {
	     SPRINTF1((yyval.str),"%s", A4GLSQLCV_ownerize_tablename(NULL, A4GL_strip_quotes((yyvsp[(1) - (1)].str))));
             ADDMAP("Use Table",(yyval.str));
        }
    break;

  case 527:

/* Line 1464 of yacc.c  */
#line 3088 "sql.yacc"
    {
	     SPRINTF1((yyval.str),"%s", A4GLSQLCV_ownerize_tablename((yyvsp[(1) - (3)].str), (yyvsp[(3) - (3)].str)));
	     ADDMAP("Use Table",(yyval.str));
        }
    break;

  case 528:

/* Line 1464 of yacc.c  */
#line 3092 "sql.yacc"
    {
	     SPRINTF1((yyval.str),"%s", A4GLSQLCV_ownerize_tablename(NULL, (yyvsp[(1) - (1)].str)));
	     ADDMAP("Use Table",(yyval.str));
	}
    break;

  case 529:

/* Line 1464 of yacc.c  */
#line 3096 "sql.yacc"
    {
	     SPRINTF1((yyval.str),"%s", A4GLSQLCV_db_tablename((yyvsp[(1) - (3)].str), NULL, A4GLSQLCV_ownerize_tablename(NULL, (yyvsp[(3) - (3)].str))));
	     ADDMAP("Use Table",(yyval.str));
	}
    break;

  case 530:

/* Line 1464 of yacc.c  */
#line 3100 "sql.yacc"
    {
	     SPRINTF1((yyval.str),"%s", A4GLSQLCV_db_tablename((yyvsp[(1) - (5)].str), NULL, A4GLSQLCV_ownerize_tablename((yyvsp[(3) - (5)].str),(yyvsp[(5) - (5)].str))));
	     ADDMAP("Use Table",(yyval.str));
        }
    break;

  case 531:

/* Line 1464 of yacc.c  */
#line 3104 "sql.yacc"
    {
	     SPRINTF1((yyval.str),"%s", A4GLSQLCV_db_tablename(NULL,(yyvsp[(1) - (3)].str), A4GLSQLCV_ownerize_tablename(NULL, (yyvsp[(3) - (3)].str))));
	     ADDMAP("Use Table",(yyval.str));
	}
    break;

  case 532:

/* Line 1464 of yacc.c  */
#line 3108 "sql.yacc"
    {
	     SPRINTF1((yyval.str),"%s", A4GLSQLCV_db_tablename((yyvsp[(1) - (5)].str), (yyvsp[(3) - (5)].str), A4GLSQLCV_ownerize_tablename(NULL, (yyvsp[(5) - (5)].str))));
	     ADDMAP("Use Table",(yyval.str));
	}
    break;

  case 533:

/* Line 1464 of yacc.c  */
#line 3112 "sql.yacc"
    {
	     SPRINTF1((yyval.str),"%s", A4GLSQLCV_db_tablename((yyvsp[(1) - (7)].str), (yyvsp[(3) - (7)].str), A4GLSQLCV_ownerize_tablename((yyvsp[(5) - (7)].str), (yyvsp[(7) - (7)].str))));
	     ADDMAP("Use Table",(yyval.str));
        }
    break;

  case 534:

/* Line 1464 of yacc.c  */
#line 3120 "sql.yacc"
    {
                if (strstr((yyvsp[(1) - (1)].str),"systables")!=0) { add_feature("IFX_SYSTABLES"); }
                if (strstr((yyvsp[(1) - (1)].str),"syscolumns")!=0) { add_feature("IFX_SYSCOLUMNS"); }
                if (strstr((yyvsp[(1) - (1)].str),"sysindexes")!=0) { add_feature("IFX_SYSINDEXES"); }
                strcpy((yyval.str),A4GLSQLCV_check_tablename((yyvsp[(1) - (1)].str)));
                }
    break;

  case 535:

/* Line 1464 of yacc.c  */
#line 3130 "sql.yacc"
    {

	     SPRINTF1((yyval.str),"%s", A4GLSQLCV_ownerize_tablename((yyvsp[(1) - (3)].str), (yyvsp[(3) - (3)].str)));
	     ADDMAP("Use Table",(yyval.str));
        }
    break;

  case 536:

/* Line 1464 of yacc.c  */
#line 3135 "sql.yacc"
    {
	     SPRINTF1((yyval.str),"%s", A4GLSQLCV_ownerize_tablename((yyvsp[(1) - (3)].str), (yyvsp[(3) - (3)].str)));
	     ADDMAP("Use Table",(yyval.str));
        }
    break;

  case 537:

/* Line 1464 of yacc.c  */
#line 3139 "sql.yacc"
    {
	     SPRINTF1((yyval.str),"%s", A4GLSQLCV_ownerize_tablename(NULL, A4GL_strip_quotes((yyvsp[(1) - (1)].str))));
	     ADDMAP("Use Table",(yyval.str));
        }
    break;

  case 538:

/* Line 1464 of yacc.c  */
#line 3143 "sql.yacc"
    {
             SPRINTF1((yyval.str),"%s", A4GLSQLCV_ownerize_tablename(NULL, (yyvsp[(1) - (1)].str)));
	     ADDMAP("Use Table",(yyval.str));
	}
    break;

  case 539:

/* Line 1464 of yacc.c  */
#line 3147 "sql.yacc"
    {
             SPRINTF1((yyval.str),"%s", A4GLSQLCV_db_tablename((yyvsp[(1) - (3)].str),NULL, A4GLSQLCV_ownerize_tablename(NULL, (yyvsp[(3) - (3)].str))));
	     ADDMAP("Use Table",(yyval.str));
	}
    break;

  case 540:

/* Line 1464 of yacc.c  */
#line 3151 "sql.yacc"
    {
	     SPRINTF1((yyval.str),"%s", A4GLSQLCV_db_tablename((yyvsp[(1) - (5)].str), NULL,A4GLSQLCV_ownerize_tablename((yyvsp[(3) - (5)].str), (yyvsp[(5) - (5)].str))));
	     ADDMAP("Use Table",(yyval.str));
        }
    break;

  case 541:

/* Line 1464 of yacc.c  */
#line 3156 "sql.yacc"
    {
             SPRINTF1((yyval.str),"%s", A4GLSQLCV_db_tablename(NULL, (yyvsp[(1) - (3)].str), A4GLSQLCV_ownerize_tablename(NULL, (yyvsp[(3) - (3)].str))));
	     ADDMAP("Use Table",(yyval.str));
	}
    break;

  case 542:

/* Line 1464 of yacc.c  */
#line 3160 "sql.yacc"
    {
            SPRINTF1((yyval.str),"%s", A4GLSQLCV_db_tablename( (yyvsp[(1) - (5)].str), (yyvsp[(3) - (5)].str), A4GLSQLCV_ownerize_tablename(NULL, (yyvsp[(5) - (5)].str))));
	    ADDMAP("Use Table",(yyval.str));
	}
    break;

  case 543:

/* Line 1464 of yacc.c  */
#line 3164 "sql.yacc"
    {
	     SPRINTF1((yyval.str),"%s", A4GLSQLCV_db_tablename((yyvsp[(1) - (7)].str), (yyvsp[(3) - (7)].str), A4GLSQLCV_ownerize_tablename((yyvsp[(5) - (7)].str), (yyvsp[(7) - (7)].str))));
	     ADDMAP("Use Table",(yyval.str));
        }
    break;

  case 544:

/* Line 1464 of yacc.c  */
#line 3172 "sql.yacc"
    {
	     SPRINTF1((yyval.str),"%s", A4GLSQLCV_ownerize_tablename((yyvsp[(1) - (3)].str), (yyvsp[(3) - (3)].str)));
        }
    break;

  case 545:

/* Line 1464 of yacc.c  */
#line 3175 "sql.yacc"
    {
	        SPRINTF1((yyval.str),"%s", A4GLSQLCV_ownerize_tablename(NULL, (yyvsp[(1) - (1)].str)));
                ADDMAP("Use Index",(yyval.str));
        }
    break;

  case 546:

/* Line 1464 of yacc.c  */
#line 3180 "sql.yacc"
    {strcpy((yyval.str),(yyvsp[(1) - (1)].str)); ADDMAP("Use Index",(yyvsp[(1) - (1)].str)); }
    break;

  case 547:

/* Line 1464 of yacc.c  */
#line 3181 "sql.yacc"
    { SPRINTF3((yyval.str),"%s%s%s",(yyvsp[(1) - (3)].str),(yyvsp[(2) - (3)].str),(yyvsp[(3) - (3)].str)); ADDMAP("Use Index",(yyval.str)); }
    break;

  case 548:

/* Line 1464 of yacc.c  */
#line 3182 "sql.yacc"
    {
	     SPRINTF2((yyval.str),"%s:%s", (yyvsp[(1) - (5)].str), A4GLSQLCV_ownerize_tablename((yyvsp[(3) - (5)].str), (yyvsp[(5) - (5)].str)));
             ADDMAP("Use Index",(yyval.str));
        }
    break;

  case 549:

/* Line 1464 of yacc.c  */
#line 3187 "sql.yacc"
    {strcpy((yyval.str),(yyvsp[(1) - (3)].str)); ADDMAP("Use Index",(yyvsp[(1) - (3)].str)); }
    break;

  case 550:

/* Line 1464 of yacc.c  */
#line 3188 "sql.yacc"
    { SPRINTF4((yyval.str),"%s@%s%s%s",(yyvsp[(1) - (5)].str),(yyvsp[(3) - (5)].str),(yyvsp[(4) - (5)].str),(yyvsp[(5) - (5)].str)); ADDMAP("Use Index",(yyval.str)); }
    break;

  case 551:

/* Line 1464 of yacc.c  */
#line 3189 "sql.yacc"
    {
	     SPRINTF3((yyval.str),"%s@%s:%s", (yyvsp[(1) - (7)].str), (yyvsp[(3) - (7)].str), A4GLSQLCV_ownerize_tablename((yyvsp[(5) - (7)].str), (yyvsp[(7) - (7)].str)));
             ADDMAP("Use Index",(yyval.str));
        }
    break;

  case 553:

/* Line 1464 of yacc.c  */
#line 3200 "sql.yacc"
    {
                      (yyval.ptr)=A4GL_new_expr_simple_string(A4GL_get_clobbered_from((yyval.str)), ET_EXPR_IDENTIFIER);
	}
    break;

  case 555:

/* Line 1464 of yacc.c  */
#line 3206 "sql.yacc"
    { sprintf((yyval.str),".%s",(yyvsp[(2) - (2)].str)); }
    break;

  case 557:

/* Line 1464 of yacc.c  */
#line 3211 "sql.yacc"
    {strcpy((yyval.str), A4GL_strip_quotes ((yyvsp[(1) - (1)].str)));}
    break;

  case 562:

/* Line 1464 of yacc.c  */
#line 3262 "sql.yacc"
    {
			int converted;
			(yyval.sql_string)=get_insert_cmd((yyvsp[(1) - (1)].insert_cmd),&converted);
			A4GL_free_associated_mem((yyvsp[(1) - (1)].insert_cmd));
			acl_free((yyvsp[(1) - (1)].insert_cmd));

		}
    break;

  case 563:

/* Line 1464 of yacc.c  */
#line 3269 "sql.yacc"
    {
			int converted;
			(yyval.sql_string)=get_update_cmd((yyvsp[(1) - (1)].update_cmd),&converted);
			A4GL_free_associated_mem((yyvsp[(1) - (1)].update_cmd));
			acl_free((yyvsp[(1) - (1)].update_cmd));
		}
    break;

  case 564:

/* Line 1464 of yacc.c  */
#line 3275 "sql.yacc"
    {
			int converted;
			(yyval.sql_string)=get_delete_cmd((yyvsp[(1) - (1)].delete_cmd),&converted);
			A4GL_free_associated_mem((yyvsp[(1) - (1)].delete_cmd));
			acl_free((yyvsp[(1) - (1)].delete_cmd));
		}
    break;

  case 567:

/* Line 1464 of yacc.c  */
#line 3290 "sql.yacc"
    { print_exec_select((yyvsp[(1) - (1)].sql_string));  }
    break;

  case 568:

/* Line 1464 of yacc.c  */
#line 3291 "sql.yacc"
    { print_exec_select((yyvsp[(1) - (1)].sql_string));  }
    break;

  case 570:

/* Line 1464 of yacc.c  */
#line 3293 "sql.yacc"
    { print_exec_select((yyvsp[(1) - (1)].sql_string));  }
    break;

  case 571:

/* Line 1464 of yacc.c  */
#line 3295 "sql.yacc"
    {
			print_sql_commit ((yyvsp[(1) - (1)].integer_val));
	}
    break;

  case 572:

/* Line 1464 of yacc.c  */
#line 3298 "sql.yacc"
    {print_unable_to_parse();}
    break;

  case 573:

/* Line 1464 of yacc.c  */
#line 3302 "sql.yacc"
    { (yyval.sql_string)=make_sql_string_and_free((yyvsp[(1) - (2)].sql_string),acl_strdup((yyvsp[(2) - (2)].str)),0);
}
    break;

  case 575:

/* Line 1464 of yacc.c  */
#line 3311 "sql.yacc"
    {
			(yyval.sql_string)=make_select_stmt_v2("", (yyvsp[(1) - (1)].s_select),"");
			A4GL_free_select_stmt((yyvsp[(1) - (1)].s_select));
		}
    break;

  case 576:

/* Line 1464 of yacc.c  */
#line 3317 "sql.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 577:

/* Line 1464 of yacc.c  */
#line 3318 "sql.yacc"
    {
			strcpy((yyval.str),A4GLSQLCV_get_forupdate(NULL));
		}
    break;

  case 578:

/* Line 1464 of yacc.c  */
#line 3321 "sql.yacc"
    {
			strcpy((yyval.str),A4GLSQLCV_get_forupdate((yyvsp[(2) - (2)].str)));
		}
    break;

  case 579:

/* Line 1464 of yacc.c  */
#line 3326 "sql.yacc"
    { strcpy((yyval.str),(yyvsp[(1) - (1)].str)); }
    break;

  case 580:

/* Line 1464 of yacc.c  */
#line 3327 "sql.yacc"
    { sprintf((yyval.str),"%s,%s",(yyvsp[(1) - (3)].str),(yyvsp[(3) - (3)].str)); }
    break;

  case 582:

/* Line 1464 of yacc.c  */
#line 3331 "sql.yacc"
    {sprintf((yyval.str),"%s.%s",A4GLSQLCV_ownerize_tablename(NULL, (yyvsp[(1) - (3)].str)),(yyvsp[(3) - (3)].str));}
    break;

  case 583:

/* Line 1464 of yacc.c  */
#line 3332 "sql.yacc"
    {
        sprintf((yyval.str),"%s.%s", A4GLSQLCV_ownerize_tablename((yyvsp[(1) - (5)].str), (yyvsp[(3) - (5)].str)), (yyvsp[(5) - (5)].str));
}
    break;

  case 584:

/* Line 1464 of yacc.c  */
#line 3342 "sql.yacc"
    { print_exec_sql(acl_strdup((yyvsp[(1) - (1)].str))); }
    break;

  case 585:

/* Line 1464 of yacc.c  */
#line 3343 "sql.yacc"
    { print_exec_sql(acl_strdup((yyvsp[(1) - (1)].str))); }
    break;

  case 586:

/* Line 1464 of yacc.c  */
#line 3344 "sql.yacc"
    { sprintf((yyval.str),"%s %s",(yyvsp[(1) - (2)].str),(yyvsp[(2) - (2)].str)); print_exec_sql(acl_strdup((yyval.str))); }
    break;

  case 587:

/* Line 1464 of yacc.c  */
#line 3345 "sql.yacc"
    { print_exec_sql(acl_strdup((yyvsp[(1) - (1)].str))); }
    break;

  case 588:

/* Line 1464 of yacc.c  */
#line 3346 "sql.yacc"
    { print_exec_sql(acl_strdup((yyvsp[(1) - (1)].str))); }
    break;

  case 589:

/* Line 1464 of yacc.c  */
#line 3347 "sql.yacc"
    { print_exec_sql(acl_strdup((yyvsp[(1) - (1)].str))); }
    break;

  case 590:

/* Line 1464 of yacc.c  */
#line 3348 "sql.yacc"
    { print_exec_sql(acl_strdup((yyvsp[(1) - (1)].str))); }
    break;

  case 591:

/* Line 1464 of yacc.c  */
#line 3349 "sql.yacc"
    { print_exec_sql(acl_strdup((yyvsp[(1) - (1)].str))); }
    break;

  case 592:

/* Line 1464 of yacc.c  */
#line 3353 "sql.yacc"
    { 
	char *s;
	s=acl_strdup((yyvsp[(1) - (1)].str));
	(yyval.s_select_list_item)=new_select_list_item_column_from_transform(s);
	acl_free(s);
	}
    break;

  case 593:

/* Line 1464 of yacc.c  */
#line 3359 "sql.yacc"
    {  
		(yyval.s_select_list_item)=new_select_list_item_builtin_const(E_SLI_QUERY_PLACEHOLDER);}
    break;

  case 594:

/* Line 1464 of yacc.c  */
#line 3361 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_replace_var((yyvsp[(1) - (1)].sql_string));
	}
    break;

  case 595:

/* Line 1464 of yacc.c  */
#line 3380 "sql.yacc"
    {
        add_feature("DATABASE_USED");
       conn_db((yyvsp[(2) - (3)].str));
}
    break;

  case 596:

/* Line 1464 of yacc.c  */
#line 3388 "sql.yacc"
    {
		(yyval.sql_string)=acl_strdup((yyvsp[(2) - (3)].str));
}
    break;

  case 597:

/* Line 1464 of yacc.c  */
#line 3395 "sql.yacc"
    {sprintf((yyval.str),"(%s)",(yyvsp[(2) - (3)].str));}
    break;

  case 598:

/* Line 1464 of yacc.c  */
#line 3396 "sql.yacc"
    { sprintf((yyval.str),"%s%s%s",(yyvsp[(1) - (3)].str),(yyvsp[(2) - (3)].str),(yyvsp[(3) - (3)].str));}
    break;

  case 599:

/* Line 1464 of yacc.c  */
#line 3397 "sql.yacc"
    {sprintf((yyval.str),"%d",atoi((yyvsp[(1) - (1)].str)));}
    break;

  case 600:

/* Line 1464 of yacc.c  */
#line 3398 "sql.yacc"
    {sprintf((yyval.str),"(%s%s)",(yyvsp[(1) - (2)].str),(yyvsp[(2) - (2)].str));}
    break;

  case 601:

/* Line 1464 of yacc.c  */
#line 3403 "sql.yacc"
    {strcpy((yyval.str),"+");}
    break;

  case 602:

/* Line 1464 of yacc.c  */
#line 3404 "sql.yacc"
    {strcpy((yyval.str),"-");}
    break;

  case 603:

/* Line 1464 of yacc.c  */
#line 3405 "sql.yacc"
    {strcpy((yyval.str),"*");}
    break;

  case 604:

/* Line 1464 of yacc.c  */
#line 3406 "sql.yacc"
    {strcpy((yyval.str),"/");}
    break;

  case 605:

/* Line 1464 of yacc.c  */
#line 3407 "sql.yacc"
    {strcpy((yyval.str),"%");}
    break;

  case 606:

/* Line 1464 of yacc.c  */
#line 3412 "sql.yacc"
    {strcpy((yyval.str),"+");}
    break;

  case 607:

/* Line 1464 of yacc.c  */
#line 3413 "sql.yacc"
    {strcpy((yyval.str),"-");}
    break;

  case 608:

/* Line 1464 of yacc.c  */
#line 3429 "sql.yacc"
    {sprintf((yyval.str),"%s", A4GLSQLCV_check_tablename((yyvsp[(1) - (1)].str)));}
    break;

  case 609:

/* Line 1464 of yacc.c  */
#line 3430 "sql.yacc"
    {sprintf((yyval.str),"%s.*", A4GLSQLCV_ownerize_tablename(NULL,(yyvsp[(1) - (3)].str)));}
    break;

  case 610:

/* Line 1464 of yacc.c  */
#line 3431 "sql.yacc"
    {sprintf((yyval.str),"%s.%s", (yyvsp[(1) - (3)].str),A4GLSQLCV_get_sqlconst ("rowid"));}
    break;

  case 611:

/* Line 1464 of yacc.c  */
#line 3432 "sql.yacc"
    {sprintf((yyval.str),"%s.%s", A4GLSQLCV_ownerize_tablename(NULL,(yyvsp[(1) - (3)].str)),(yyvsp[(3) - (3)].str));}
    break;

  case 612:

/* Line 1464 of yacc.c  */
#line 3433 "sql.yacc"
    {sprintf((yyval.str),"%s.%s", A4GLSQLCV_ownerize_tablename((yyvsp[(1) - (5)].str),(yyvsp[(3) - (5)].str)),(yyvsp[(5) - (5)].str));}
    break;

  case 613:

/* Line 1464 of yacc.c  */
#line 3434 "sql.yacc"
    {sprintf((yyval.str),"%s.%s", A4GLSQLCV_ownerize_tablename((yyvsp[(1) - (5)].str),(yyvsp[(3) - (5)].str)),(yyvsp[(5) - (5)].str));}
    break;

  case 614:

/* Line 1464 of yacc.c  */
#line 3435 "sql.yacc"
    {sprintf((yyval.str),"%s", (yyvsp[(1) - (4)].str)); strcpy((yyval.str), A4GLSQLCV_make_substr_s((yyvsp[(1) - (4)].str), 1,(yyvsp[(3) - (4)].str),0));}
    break;

  case 615:

/* Line 1464 of yacc.c  */
#line 3436 "sql.yacc"
    {char buff[256]; sprintf(buff,"%s.%s", A4GLSQLCV_ownerize_tablename(NULL,(yyvsp[(1) - (6)].str)),(yyvsp[(3) - (6)].str)); strcpy((yyval.str), A4GLSQLCV_make_substr_s(buff,1,(yyvsp[(5) - (6)].str),0));}
    break;

  case 616:

/* Line 1464 of yacc.c  */
#line 3437 "sql.yacc"
    {char buff[256]; sprintf(buff,"%s.%s", A4GLSQLCV_ownerize_tablename((yyvsp[(1) - (8)].str),(yyvsp[(3) - (8)].str)), (yyvsp[(5) - (8)].str)); strcpy((yyval.str), A4GLSQLCV_make_substr_s(buff,1,(yyvsp[(7) - (8)].str),0));  }
    break;

  case 617:

/* Line 1464 of yacc.c  */
#line 3438 "sql.yacc"
    {char buff[256]; sprintf(buff,"%s.%s", A4GLSQLCV_ownerize_tablename((yyvsp[(1) - (8)].str),(yyvsp[(3) - (8)].str)), (yyvsp[(5) - (8)].str));  strcpy((yyval.str), A4GLSQLCV_make_substr_s(buff,1,(yyvsp[(7) - (8)].str),0)); }
    break;

  case 618:

/* Line 1464 of yacc.c  */
#line 3440 "sql.yacc"
    {sprintf((yyval.str),"%s", (yyvsp[(1) - (6)].str)); strcpy((yyval.str), A4GLSQLCV_make_substr_s((yyvsp[(1) - (6)].str), 2,(yyvsp[(3) - (6)].str),(yyvsp[(5) - (6)].str)));}
    break;

  case 619:

/* Line 1464 of yacc.c  */
#line 3441 "sql.yacc"
    {char buff[256]; sprintf(buff,"%s.%s", A4GLSQLCV_ownerize_tablename(NULL,(yyvsp[(1) - (8)].str)),(yyvsp[(3) - (8)].str)); strcpy((yyval.str), A4GLSQLCV_make_substr_s(buff,2,(yyvsp[(5) - (8)].str),(yyvsp[(7) - (8)].str)));}
    break;

  case 620:

/* Line 1464 of yacc.c  */
#line 3442 "sql.yacc"
    {char buff[256]; sprintf(buff,"%s.%s", A4GLSQLCV_ownerize_tablename((yyvsp[(1) - (10)].str),(yyvsp[(3) - (10)].str)), (yyvsp[(5) - (10)].str)); strcpy((yyval.str), A4GLSQLCV_make_substr_s(buff,2,(yyvsp[(7) - (10)].str),(yyvsp[(9) - (10)].str)));  }
    break;

  case 621:

/* Line 1464 of yacc.c  */
#line 3443 "sql.yacc"
    {char buff[256]; sprintf(buff,"%s.%s", A4GLSQLCV_ownerize_tablename((yyvsp[(1) - (10)].str),(yyvsp[(3) - (10)].str)), (yyvsp[(5) - (10)].str));  strcpy((yyval.str), A4GLSQLCV_make_substr_s(buff,2,(yyvsp[(7) - (10)].str),(yyvsp[(9) - (10)].str))); }
    break;

  case 622:

/* Line 1464 of yacc.c  */
#line 3448 "sql.yacc"
    {
                (yyval.s_select_list_item)=(yyvsp[(1) - (1)].s_select_list_item);
        }
    break;

  case 623:

/* Line 1464 of yacc.c  */
#line 3451 "sql.yacc"
    {
                (yyval.s_select_list_item)=new_select_list_item_cast((yyvsp[(1) - (3)].s_select_list_item), (yyvsp[(3) - (3)].str));
        }
    break;

  case 624:

/* Line 1464 of yacc.c  */
#line 3460 "sql.yacc"
    { (yyvsp[(1) - (1)].s_select_list_item)=(yyvsp[(1) - (1)].s_select_list_item); }
    break;

  case 625:

/* Line 1464 of yacc.c  */
#line 3461 "sql.yacc"
    {(yyvsp[(1) - (1)].s_select_list_item)=(yyvsp[(1) - (1)].s_select_list_item);}
    break;

  case 626:

/* Line 1464 of yacc.c  */
#line 3462 "sql.yacc"
    {  (yyval.s_select_list_item)=new_select_list_item_sq(E_SQE_DONT_CARE,(yyvsp[(1) - (1)].s_select_list_item)); }
    break;

  case 627:

/* Line 1464 of yacc.c  */
#line 3463 "sql.yacc"
    { (yyval.s_select_list_item)=new_select_list_item_sq(E_SQE_ALL,(yyvsp[(2) - (2)].s_select_list_item)); }
    break;

  case 628:

/* Line 1464 of yacc.c  */
#line 3464 "sql.yacc"
    { (yyval.s_select_list_item)=new_select_list_item_sq(E_SQE_ANY,(yyvsp[(2) - (2)].s_select_list_item)); }
    break;

  case 629:

/* Line 1464 of yacc.c  */
#line 3465 "sql.yacc"
    { (yyval.s_select_list_item)=new_select_list_item_sq(E_SQE_SOME,(yyvsp[(2) - (2)].s_select_list_item)); }
    break;

  case 630:

/* Line 1464 of yacc.c  */
#line 3469 "sql.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 631:

/* Line 1464 of yacc.c  */
#line 3470 "sql.yacc"
    {strcpy((yyval.str),(yyvsp[(1) - (1)].str));}
    break;



/* Line 1464 of yacc.c  */
#line 8943 "y.tab.c"
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
#line 3476 "sql.yacc"


#if LEX_YY_PREGEN
#include "../../tools/no_yacc/cygwin/compilers/sql/lex.sqlparse_yy.c"
#else
#include "lex.yy.c"
#endif
#include "util.c"
#include "cmds.c"

