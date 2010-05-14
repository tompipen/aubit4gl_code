
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
#line 224 "y.tab.c"

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
     INT_VALUE = 2231,
     NAMED = 2232,
     NAMED_GEN = 2233,
     CHAR_VALUE = 2234,
     NOT_USED_1 = 2235,
     NOT_USED_2 = 2236,
     NOT_USED_3 = 2237,
     NOT_USED_4 = 2238,
     NOT_USED_5 = 2239,
     NOT_USED_6 = 2240,
     NOT_USED_7 = 2241,
     NOT_USED_8 = 2242,
     NUMBER_VALUE = 2243,
     SEMICOLON = 2244,
     QUESTION_MARK = 2245,
     CLINE = 2246,
     CH = 2247,
     MARK_VAR = 2248,
     END_MARK_VAR = 2249,
     WITH_LISTING_IN = 1001,
     SET_CONSTRAINTS_ALL_DEFERRED = 1002,
     KW_LIMIT = 1003,
     DOCUMENT = 1004,
     ON_EXCEPTION = 1006,
     SET_DEBUG_FILE_TO = 1007,
     CREATE_DBA_PROCEDURE = 1012,
     CREATE_FUNCTION = 1013,
     CREATE_DBA_FUNCTION = 1014,
     USE_SESSION = 1016,
     KW_RUN_CLIENT = 1017,
     LEFT_JOIN = 1019,
     IGNORE_ERRORS = 1022,
     SQLERRMESSAGE = 1023,
     DISPLAY_NULL_TO = 1024,
     UNBUFFERED = 1025,
     KW_PICTURE = 1026,
     ON_CHANGE = 1027,
     INNER_JOIN = 1028,
     UI_INTERFACE_DOT_FRONTCALL = 1031,
     UICOMBOBOX = 1035,
     UIFORM = 1038,
     USING_BTREE = 1054,
     USING_RTREE = 1055,
     SET_BUFFERED_LOG = 1074,
     SET_LOG = 1077,
     MDY = 1079,
     WEEKDAY = 1080,
     MODE_ANSI = 1083,
     START_DATABASE = 1084,
     WITH_LOG_IN = 1085,
     SET_CONSTRAINTS_ALL_IMMEDIATE = 1086,
     DATETIME_VALUE = 1099,
     INTERVAL_VALUE = 1100,
     RECOVER_TABLE = 1101,
     ROLLFORWARD_DATABASE = 1102,
     CONCAT_PIPES = 1116,
     DROP_TRIGGER = 1118,
     DROP_AUDIT_FOR = 1119,
     CREATE_AUDIT_FOR = 1120,
     EXECUTE_PROCEDURE = 1124,
     ALTER_TABLE = 1131,
     ALTER_INDEX = 1132,
     NEXT_SIZE = 1133,
     XSET_MULTIPLY_EQUAL_OPEN_BRACKET = 1170,
     XSET_ident_DOT_MULTIPLY_EQUAL_OPEN_BRACKET = 1171,
     XSET_ident_DOT_MULTIPLY_EQUAL = 1172,
     XSET_MULTIPLY_EQUAL = 1173,
     XSET_OPEN_BRACKET = 1174,
     CREATE_DATABASE = 1177,
     DROP_DATABASE = 1178,
     ADD_CONSTRAINT = 1180,
     DROP_CONSTRAINT = 1181,
     DROP_SYNONYM = 1182,
     CONSTRAINT = 1183,
     NOT_FIELD_TOUCHED_CURRENT = 1186,
     FIELD_TOUCHED_CURRENT = 1187,
     DOUBLE_PRECISION = 1194,
     COUNT_MULTIPLY = 1195,
     MODIFY_NEXT_SIZE = 1215,
     LOCK_MODE_PAGE = 1216,
     LOCK_MODE_ROW = 1217,
     UNITS_YEAR = 1224,
     UNITS_MONTH = 1225,
     UNITS_DAY = 1226,
     UNITS_HOUR = 1227,
     UNITS_MINUTE = 1228,
     UNITS_SECOND = 1229,
     TO_CLUSTER = 1234,
     TO_NOT_CLUSTER = 1235,
     CREATE_UC_IDX = 1237,
     CREATE_U_IDX = 1238,
     CREATE_C_IDX = 1239,
     CREATE_IDX = 1240,
     DOUBLE_COLON = 1250,
     SQLSICS = 1256,
     CREATE_SCHEMA = 1257,
     SQLSIRR = 1258,
     UPDATESTATS_T = 1259,
     SQLSICR = 1260,
     SQLSIDR = 1271,
     CREATE_TEMP_TABLE = 1272,
     WITH_CHECK_OPTION = 1280,
     WITH_GRANT_OPTION = 1281,
     SQLSLMNW = 1282,
     WHERE_CURRENT_OF = 1288,
     NOT_NULL_UNIQUE = 1296,
     SQLSLMW = 1303,
     ALL_PRIVILEGES = 1305,
     CREATE_SYNONYM = 1309,
     DROP_TABLE = 1310,
     INEXCLUSIVE = 1312,
     UPDATESTATS = 1317,
     CREATE_TABLE = 1343,
     DEFAULT_NULL = 1344,
     DEFAULT_TODAY = 1345,
     DEFAULT_USER = 1346,
     UNLOCK_TABLE = 1359,
     ROLLBACK_W = 1367,
     SQLSEON = 1369,
     SQLSEOFF = 1370,
     CREATE_VIEW = 1374,
     DELETE_FROM = 1375,
     EXTENT_SIZE = 1382,
     FOREIGN_KEY = 1383,
     INSERT_INTO = 1386,
     IS_NOT_NULL = 1388,
     NOT_MATCHES = 1391,
     PRIMARY_KEY = 1397,
     WITH_NO_LOG = 1404,
     INSHARE = 1407,
     BEGIN_WORK = 1413,
     DROP_INDEX = 1418,
     FOR_UPDATE_OF = 1424,
     FOR_UPDATE = 1425,
     LOCK_TABLE = 1430,
     NOT_EXISTS = 1432,
     REFERENCES = 1434,
     RENCOL = 1435,
     SMALLFLOAT = 1437,
     COMMIT_W = 1448,
     RENTAB = 1455,
     KW_CHAR = 1458,
     NCHAR = 1459,
     NVARCHAR = 1460,
     DELIMITER = 1462,
     DROP_VIEW = 1464,
     EXCLUSIVE = 1467,
     GREATER_THAN_EQ = 1471,
     INTO_TEMP = 1473,
     DATABASE = 1497,
     DATETIME = 1498,
     DISTINCT = 1500,
     FRACTION = 1507,
     GROUP_BY = 1509,
     INTERVAL = 1510,
     NOT_LIKE = 1512,
     NOT_ILIKE = 1513,
     NOT_NULL = 1514,
     RESOURCE = 1520,
     SMALLINT = 1521,
     IS_NULL = 1527,
     LESS_THAN_EQ = 1528,
     BETWEEN = 1530,
     CLOSE_BRACKET = 1533,
     CONNECT = 1536,
     KW_CURRENT = 1537,
     KW_DECIMAL = 1539,
     DEFAULT = 1541,
     INTEGER = 1549,
     SERIAL8 = 1551,
     MATCHES = 1554,
     VARCHAR = 1567,
     CLOSE_SQUARE = 1570,
     GREATER_THAN = 1571,
     KW_FALSE = 1572,
     NOT_IN = 1573,
     OPEN_BRACKET = 1575,
     KW_DELETE = 1583,
     KW_ESCAPE = 1586,
     EXISTS = 1587,
     EXTEND = 1588,
     HAVING = 1592,
     KW_INSERT = 1594,
     MINUTE = 1598,
     MODIFY = 1599,
     EQUAL = 1601,
     NOT_EQUAL = 1602,
     OPEN_SQUARE = 1604,
     PUBLIC = 1608,
     REVOKE = 1612,
     SECOND = 1616,
     KW_SELECT = 1620,
     SERIAL = 1621,
     UNIQUE = 1624,
     KW_UPDATE = 1626,
     VALUES = 1627,
     KW_NULL = 1630,
     KW_TRUE = 1631,
     ALTER = 1633,
     CHECK = 1639,
     COUNT = 1643,
     KW_FIRST = 1648,
     KW_FLOAT = 1649,
     GRANT = 1652,
     INDEX = 1655,
     LESS_THAN = 1658,
     MONEY = 1660,
     MONTH = 1661,
     KW_MULTIPLY = 1663,
     ORDER = 1664,
     OUTER = 1665,
     UNION = 1674,
     WHERE = 1677,
     KW_BYTE = 1684,
     CASE = 1686,
     KW_DATE = 1688,
     DESC = 1689,
     KW_DIVIDE = 1690,
     DROP = 1693,
     ELSE = 1694,
     FROM = 1698,
     HOUR = 1704,
     INTO = 1705,
     LIKE = 1708,
     REAL = 1717,
     SOME = 1722,
     KW_TEXT = 1726,
     KW_THEN = 1727,
     USER = 1728,
     WHEN = 1730,
     YEAR = 1733,
     KW_DOW = 1734,
     XSET = 1736,
     ADD = 1737,
     ALL = 1738,
     KW_AND = 1739,
     ANY = 1740,
     ASC = 1741,
     AVG = 1742,
     COLON = 1743,
     KW_COMMA = 1744,
     DAY = 1745,
     DBA = 1746,
     KW_FOR = 1750,
     XMAX = 1755,
     XMIN = 1756,
     KW_MINUS = 1757,
     KW_MOD = 1758,
     KW_NOT = 1759,
     KW_SUM = 1766,
     ATSIGN = 1769,
     KW_PLUS = 1770,
     KW_AS = 1776,
     KW_BY = 1778,
     KW_DOT = 1779,
     KW_IN = 1782,
     KW_ON = 1784,
     KW_OR = 1785,
     KW_TO = 1786,
     BEFORE = 1824,
     END = 1828,
     TILDE = 1835,
     ILIKE = 1836,
     FILLFACTOR = 1839,
     TIME = 1844,
     KW_TODAY = 1851,
     KW_ROWID = 1852,
     TIMESTAMP = 2200,
     KW_TAG = 2221,
     LINTMODULEISLIBRARY = 2222,
     KW_PUBLIC = 2223,
     KW_PRIVATE = 2224,
     COPYBACK = 2225,
     REFERENCES_BLOBTYPE_DEFAULT_NULL = 2226,
     REFERENCES_BLOBTYPE = 2227,
     SORT = 2228,
     KWPIPE = 2229
   };
#endif
/* Tokens.  */
#define INT_VALUE 2231
#define NAMED 2232
#define NAMED_GEN 2233
#define CHAR_VALUE 2234
#define NOT_USED_1 2235
#define NOT_USED_2 2236
#define NOT_USED_3 2237
#define NOT_USED_4 2238
#define NOT_USED_5 2239
#define NOT_USED_6 2240
#define NOT_USED_7 2241
#define NOT_USED_8 2242
#define NUMBER_VALUE 2243
#define SEMICOLON 2244
#define QUESTION_MARK 2245
#define CLINE 2246
#define CH 2247
#define MARK_VAR 2248
#define END_MARK_VAR 2249
#define WITH_LISTING_IN 1001
#define SET_CONSTRAINTS_ALL_DEFERRED 1002
#define KW_LIMIT 1003
#define DOCUMENT 1004
#define ON_EXCEPTION 1006
#define SET_DEBUG_FILE_TO 1007
#define CREATE_DBA_PROCEDURE 1012
#define CREATE_FUNCTION 1013
#define CREATE_DBA_FUNCTION 1014
#define USE_SESSION 1016
#define KW_RUN_CLIENT 1017
#define LEFT_JOIN 1019
#define IGNORE_ERRORS 1022
#define SQLERRMESSAGE 1023
#define DISPLAY_NULL_TO 1024
#define UNBUFFERED 1025
#define KW_PICTURE 1026
#define ON_CHANGE 1027
#define INNER_JOIN 1028
#define UI_INTERFACE_DOT_FRONTCALL 1031
#define UICOMBOBOX 1035
#define UIFORM 1038
#define USING_BTREE 1054
#define USING_RTREE 1055
#define SET_BUFFERED_LOG 1074
#define SET_LOG 1077
#define MDY 1079
#define WEEKDAY 1080
#define MODE_ANSI 1083
#define START_DATABASE 1084
#define WITH_LOG_IN 1085
#define SET_CONSTRAINTS_ALL_IMMEDIATE 1086
#define DATETIME_VALUE 1099
#define INTERVAL_VALUE 1100
#define RECOVER_TABLE 1101
#define ROLLFORWARD_DATABASE 1102
#define CONCAT_PIPES 1116
#define DROP_TRIGGER 1118
#define DROP_AUDIT_FOR 1119
#define CREATE_AUDIT_FOR 1120
#define EXECUTE_PROCEDURE 1124
#define ALTER_TABLE 1131
#define ALTER_INDEX 1132
#define NEXT_SIZE 1133
#define XSET_MULTIPLY_EQUAL_OPEN_BRACKET 1170
#define XSET_ident_DOT_MULTIPLY_EQUAL_OPEN_BRACKET 1171
#define XSET_ident_DOT_MULTIPLY_EQUAL 1172
#define XSET_MULTIPLY_EQUAL 1173
#define XSET_OPEN_BRACKET 1174
#define CREATE_DATABASE 1177
#define DROP_DATABASE 1178
#define ADD_CONSTRAINT 1180
#define DROP_CONSTRAINT 1181
#define DROP_SYNONYM 1182
#define CONSTRAINT 1183
#define NOT_FIELD_TOUCHED_CURRENT 1186
#define FIELD_TOUCHED_CURRENT 1187
#define DOUBLE_PRECISION 1194
#define COUNT_MULTIPLY 1195
#define MODIFY_NEXT_SIZE 1215
#define LOCK_MODE_PAGE 1216
#define LOCK_MODE_ROW 1217
#define UNITS_YEAR 1224
#define UNITS_MONTH 1225
#define UNITS_DAY 1226
#define UNITS_HOUR 1227
#define UNITS_MINUTE 1228
#define UNITS_SECOND 1229
#define TO_CLUSTER 1234
#define TO_NOT_CLUSTER 1235
#define CREATE_UC_IDX 1237
#define CREATE_U_IDX 1238
#define CREATE_C_IDX 1239
#define CREATE_IDX 1240
#define DOUBLE_COLON 1250
#define SQLSICS 1256
#define CREATE_SCHEMA 1257
#define SQLSIRR 1258
#define UPDATESTATS_T 1259
#define SQLSICR 1260
#define SQLSIDR 1271
#define CREATE_TEMP_TABLE 1272
#define WITH_CHECK_OPTION 1280
#define WITH_GRANT_OPTION 1281
#define SQLSLMNW 1282
#define WHERE_CURRENT_OF 1288
#define NOT_NULL_UNIQUE 1296
#define SQLSLMW 1303
#define ALL_PRIVILEGES 1305
#define CREATE_SYNONYM 1309
#define DROP_TABLE 1310
#define INEXCLUSIVE 1312
#define UPDATESTATS 1317
#define CREATE_TABLE 1343
#define DEFAULT_NULL 1344
#define DEFAULT_TODAY 1345
#define DEFAULT_USER 1346
#define UNLOCK_TABLE 1359
#define ROLLBACK_W 1367
#define SQLSEON 1369
#define SQLSEOFF 1370
#define CREATE_VIEW 1374
#define DELETE_FROM 1375
#define EXTENT_SIZE 1382
#define FOREIGN_KEY 1383
#define INSERT_INTO 1386
#define IS_NOT_NULL 1388
#define NOT_MATCHES 1391
#define PRIMARY_KEY 1397
#define WITH_NO_LOG 1404
#define INSHARE 1407
#define BEGIN_WORK 1413
#define DROP_INDEX 1418
#define FOR_UPDATE_OF 1424
#define FOR_UPDATE 1425
#define LOCK_TABLE 1430
#define NOT_EXISTS 1432
#define REFERENCES 1434
#define RENCOL 1435
#define SMALLFLOAT 1437
#define COMMIT_W 1448
#define RENTAB 1455
#define KW_CHAR 1458
#define NCHAR 1459
#define NVARCHAR 1460
#define DELIMITER 1462
#define DROP_VIEW 1464
#define EXCLUSIVE 1467
#define GREATER_THAN_EQ 1471
#define INTO_TEMP 1473
#define DATABASE 1497
#define DATETIME 1498
#define DISTINCT 1500
#define FRACTION 1507
#define GROUP_BY 1509
#define INTERVAL 1510
#define NOT_LIKE 1512
#define NOT_ILIKE 1513
#define NOT_NULL 1514
#define RESOURCE 1520
#define SMALLINT 1521
#define IS_NULL 1527
#define LESS_THAN_EQ 1528
#define BETWEEN 1530
#define CLOSE_BRACKET 1533
#define CONNECT 1536
#define KW_CURRENT 1537
#define KW_DECIMAL 1539
#define DEFAULT 1541
#define INTEGER 1549
#define SERIAL8 1551
#define MATCHES 1554
#define VARCHAR 1567
#define CLOSE_SQUARE 1570
#define GREATER_THAN 1571
#define KW_FALSE 1572
#define NOT_IN 1573
#define OPEN_BRACKET 1575
#define KW_DELETE 1583
#define KW_ESCAPE 1586
#define EXISTS 1587
#define EXTEND 1588
#define HAVING 1592
#define KW_INSERT 1594
#define MINUTE 1598
#define MODIFY 1599
#define EQUAL 1601
#define NOT_EQUAL 1602
#define OPEN_SQUARE 1604
#define PUBLIC 1608
#define REVOKE 1612
#define SECOND 1616
#define KW_SELECT 1620
#define SERIAL 1621
#define UNIQUE 1624
#define KW_UPDATE 1626
#define VALUES 1627
#define KW_NULL 1630
#define KW_TRUE 1631
#define ALTER 1633
#define CHECK 1639
#define COUNT 1643
#define KW_FIRST 1648
#define KW_FLOAT 1649
#define GRANT 1652
#define INDEX 1655
#define LESS_THAN 1658
#define MONEY 1660
#define MONTH 1661
#define KW_MULTIPLY 1663
#define ORDER 1664
#define OUTER 1665
#define UNION 1674
#define WHERE 1677
#define KW_BYTE 1684
#define CASE 1686
#define KW_DATE 1688
#define DESC 1689
#define KW_DIVIDE 1690
#define DROP 1693
#define ELSE 1694
#define FROM 1698
#define HOUR 1704
#define INTO 1705
#define LIKE 1708
#define REAL 1717
#define SOME 1722
#define KW_TEXT 1726
#define KW_THEN 1727
#define USER 1728
#define WHEN 1730
#define YEAR 1733
#define KW_DOW 1734
#define XSET 1736
#define ADD 1737
#define ALL 1738
#define KW_AND 1739
#define ANY 1740
#define ASC 1741
#define AVG 1742
#define COLON 1743
#define KW_COMMA 1744
#define DAY 1745
#define DBA 1746
#define KW_FOR 1750
#define XMAX 1755
#define XMIN 1756
#define KW_MINUS 1757
#define KW_MOD 1758
#define KW_NOT 1759
#define KW_SUM 1766
#define ATSIGN 1769
#define KW_PLUS 1770
#define KW_AS 1776
#define KW_BY 1778
#define KW_DOT 1779
#define KW_IN 1782
#define KW_ON 1784
#define KW_OR 1785
#define KW_TO 1786
#define BEFORE 1824
#define END 1828
#define TILDE 1835
#define ILIKE 1836
#define FILLFACTOR 1839
#define TIME 1844
#define KW_TODAY 1851
#define KW_ROWID 1852
#define TIMESTAMP 2200
#define KW_TAG 2221
#define LINTMODULEISLIBRARY 2222
#define KW_PUBLIC 2223
#define KW_PRIVATE 2224
#define COPYBACK 2225
#define REFERENCES_BLOBTYPE_DEFAULT_NULL 2226
#define REFERENCES_BLOBTYPE 2227
#define SORT 2228
#define KWPIPE 2229




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
#line 843 "y.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 855 "y.tab.c"

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
#define YYFINAL  155
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   2528

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  280
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  226
/* YYNRULES -- Number of rules.  */
#define YYNRULES  628
/* YYNRULES -- Number of states.  */
#define YYNSTATES  1117

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   2249

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
       2,    22,    23,    24,    25,     2,    26,    27,     2,     2,
       2,     2,    28,    29,    30,     2,    31,    32,     2,    33,
       2,     2,    34,    35,    36,    37,    38,    39,    40,     2,
       2,    41,     2,     2,     2,    42,     2,     2,    43,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,    44,    45,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,    46,     2,     2,    47,     2,    48,
      49,     2,     2,    50,    51,    52,    53,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    54,
      55,    56,    57,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,    58,     2,    59,    60,
      61,     2,     2,     2,    62,     2,     2,     2,     2,     2,
       2,    63,    64,    65,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      66,    67,    68,    69,    70,     2,     2,    71,    72,     2,
      73,    74,    75,    76,     2,     2,    77,    78,     2,     2,
       2,     2,     2,     2,    79,    80,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,    81,    82,    83,     2,     2,
       2,     2,     2,     2,    84,    85,    86,    87,    88,    89,
       2,     2,     2,     2,    90,    91,     2,    92,    93,    94,
      95,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      96,     2,     2,     2,     2,     2,    97,    98,    99,   100,
     101,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,   102,   103,     2,     2,     2,     2,     2,     2,     2,
     104,   105,   106,     2,     2,     2,     2,     2,   107,     2,
       2,     2,     2,     2,     2,     2,   108,     2,     2,     2,
       2,     2,     2,   109,     2,   110,     2,     2,     2,   111,
     112,     2,   113,     2,     2,     2,     2,   114,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   115,   116,   117,   118,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,   119,
       2,     2,     2,     2,     2,     2,     2,   120,     2,   121,
     122,     2,     2,     2,   123,   124,     2,     2,     2,     2,
       2,     2,   125,   126,     2,     2,   127,     2,   128,     2,
       2,   129,     2,     2,     2,     2,     2,   130,     2,     2,
       2,     2,     2,     2,   131,     2,     2,   132,     2,     2,
       2,     2,     2,   133,     2,     2,     2,     2,   134,     2,
       2,     2,     2,     2,   135,   136,     2,     2,     2,     2,
     137,     2,   138,     2,   139,   140,     2,   141,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,   142,     2,
       2,     2,     2,     2,     2,   143,     2,     2,   144,   145,
     146,     2,   147,     2,   148,     2,     2,   149,     2,     2,
       2,   150,     2,   151,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,   152,   153,     2,
     154,     2,     2,     2,     2,     2,     2,   155,     2,   156,
     157,     2,   158,   159,   160,     2,     2,     2,     2,     2,
     161,   162,     2,     2,     2,     2,     2,   163,   164,     2,
     165,     2,     2,   166,     2,     2,   167,   168,     2,   169,
       2,   170,     2,     2,     2,     2,     2,     2,     2,   171,
       2,   172,     2,     2,   173,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,   174,     2,     2,
     175,   176,   177,   178,     2,   179,     2,     2,     2,     2,
       2,     2,     2,   180,     2,     2,   181,   182,   183,     2,
       2,     2,   184,     2,   185,     2,     2,     2,   186,   187,
       2,   188,   189,     2,   190,     2,     2,     2,   191,     2,
       2,     2,   192,     2,     2,     2,   193,     2,     2,     2,
     194,   195,     2,     2,   196,     2,   197,   198,     2,     2,
     199,   200,     2,   201,     2,     2,     2,     2,     2,   202,
       2,     2,     2,   203,     2,     2,     2,     2,   204,   205,
       2,     2,   206,     2,     2,   207,     2,     2,   208,     2,
     209,   210,     2,   211,   212,   213,     2,     2,     2,     2,
       2,     2,     2,     2,   214,     2,     2,   215,     2,     2,
       2,     2,     2,     2,   216,     2,   217,     2,   218,   219,
     220,     2,     2,   221,   222,     2,     2,     2,   223,     2,
       2,     2,     2,     2,   224,   225,     2,     2,   226,     2,
       2,     2,     2,     2,     2,     2,     2,   227,     2,     2,
       2,     2,   228,     2,     2,     2,   229,   230,   231,     2,
     232,     2,     2,   233,   234,     2,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,     2,     2,     2,
     246,     2,     2,     2,     2,   247,   248,   249,   250,   251,
       2,     2,     2,     2,     2,     2,   252,     2,     2,   253,
     254,     2,     2,     2,     2,     2,   255,     2,   256,   257,
       2,     2,   258,     2,   259,   260,   261,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,   262,     2,     2,     2,   263,     2,
       2,     2,     2,     2,     2,   264,   265,     2,     2,   266,
       2,     2,     2,     2,   267,     2,     2,     2,     2,     2,
       2,   268,   269,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     270,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,   271,   272,   273,   274,   275,   276,   277,   278,   279,
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
    1344,  1345,  1347,  1349,  1351,  1353,  1357,  1359,  1362,  1366,
    1368,  1371,  1374,  1378,  1381,  1385,  1389,  1393,  1397,  1399,
    1401,  1403,  1405,  1407,  1409,  1411,  1413,  1415,  1421,  1427,
    1433,  1439,  1445,  1449,  1454,  1459,  1464,  1469,  1474,  1479,
    1484,  1489,  1493,  1498,  1500,  1502,  1506,  1508,  1511,  1516,
    1519,  1521,  1525,  1531,  1537,  1542,  1548,  1550,  1552,  1554,
    1556,  1558,  1560,  1566,  1570,  1576,  1580,  1582,  1586,  1588,
    1590,  1593,  1596,  1598,  1600,  1604,  1606,  1610,  1616,  1620,
    1626,  1634,  1636,  1640,  1644,  1646,  1648,  1652,  1658,  1662,
    1668,  1676,  1680,  1682,  1684,  1688,  1694,  1698,  1704,  1712,
    1714,  1716,  1718,  1721,  1723,  1725,  1726,  1728,  1730,  1734,
    1736,  1738,  1740,  1741,  1743,  1745,  1747,  1749,  1751,  1753,
    1755,  1758,  1760,  1762,  1763,  1765,  1768,  1770,  1774,  1776,
    1780,  1786,  1788,  1790,  1793,  1795,  1797,  1799,  1801,  1803,
    1805,  1807,  1809,  1813,  1817,  1821,  1825,  1827,  1830,  1832,
    1834,  1836,  1838,  1840,  1842,  1844,  1846,  1850,  1854,  1858,
    1864,  1870,  1875,  1882,  1891,  1900,  1907,  1916,  1927,  1938,
    1940,  1944,  1946,  1948,  1950,  1953,  1956,  1959,  1960
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     486,     0,    -1,   197,   477,   284,   282,    -1,    -1,   107,
     481,    -1,   215,   393,    -1,    -1,   107,   481,    -1,   215,
     393,    -1,    70,   289,   166,   188,   179,   290,   166,    -1,
      66,   290,   166,    -1,    67,   290,   166,    -1,   235,   285,
      -1,    69,   290,    -1,    68,   290,    -1,   288,    -1,   285,
     243,   288,    -1,   287,    -1,   253,   287,    -1,   480,   419,
      -1,   480,   257,   480,   419,    -1,   480,   257,   480,   257,
     480,   419,    -1,   480,   257,   211,    -1,   286,   188,   291,
      -1,   286,    -1,   289,   243,   286,    -1,   291,    -1,   290,
     243,   291,    -1,   465,    -1,   199,    -1,   293,    -1,   112,
     477,    -1,   148,   477,    -1,   134,   479,    -1,    59,   480,
      -1,   304,    -1,   295,    -1,   115,   477,   179,   309,   166,
     296,    -1,   103,   477,   179,   309,   166,   305,   296,   305,
      -1,    -1,   297,    -1,   298,    -1,   297,   298,    -1,   258,
     299,    -1,   125,     3,    -1,    65,     3,    -1,    82,    -1,
      83,    -1,     4,    -1,    -1,   301,    -1,   302,    -1,   301,
     302,    -1,   258,   299,    -1,   266,     3,    -1,    44,    -1,
      45,    -1,   477,    -1,    93,   479,   259,   303,   179,   307,
     166,   300,    -1,    92,   479,   259,   303,   179,   307,   166,
     300,    -1,    94,   479,   259,   303,   179,   307,   166,   300,
      -1,    95,   479,   259,   303,   179,   307,   166,   300,    -1,
      71,   490,    -1,    72,   490,    -1,   111,   477,   246,   477,
      -1,    61,   477,   258,     6,    -1,    60,   477,    -1,    75,
     477,    -1,    56,   477,    -1,    57,   480,    -1,    -1,   131,
      -1,    -1,   131,    -1,   308,    -1,   307,   243,   308,    -1,
     480,   240,    -1,   480,   219,    -1,   480,    -1,   310,    -1,
     309,   243,   310,    -1,   373,    -1,   371,    -1,    63,   480,
     312,    -1,    64,   479,    90,    -1,    64,   479,    91,    -1,
     313,    -1,   312,   243,   313,    -1,   314,    -1,   317,    -1,
     320,    -1,   325,    -1,   328,    -1,   324,    -1,   323,    -1,
     236,   315,    -1,   236,   179,   316,   166,    -1,   310,    -1,
     310,   262,   480,    -1,   315,    -1,   316,   243,   315,    -1,
     221,   319,    -1,   221,   179,   318,   166,    -1,   319,    -1,
     318,   243,   319,    -1,   480,    -1,   187,   322,    -1,   187,
     179,   321,   166,    -1,   322,    -1,   321,   243,   322,    -1,
     310,    -1,    82,    -1,    83,    -1,    81,     3,    -1,    73,
     371,   327,    -1,    73,   179,   326,   166,    -1,   371,   327,
      -1,   326,   243,   371,   327,    -1,    -1,    76,   480,    -1,
      74,   329,    -1,    74,   179,   329,   166,    -1,   330,    -1,
     329,   243,   330,    -1,   480,    -1,   120,    -1,    -1,   127,
     333,   477,   336,   334,    -1,    -1,   198,   335,   179,   339,
     166,    -1,   459,    -1,    -1,   179,   337,   166,    -1,   338,
      -1,   337,   243,   338,    -1,   480,    -1,   480,   257,   480,
      -1,   340,    -1,   339,   243,   340,    -1,   465,    -1,   199,
      -1,   124,   477,   283,    -1,   133,    -1,   142,    -1,    -1,
     149,    -1,   346,    -1,    51,   480,    52,     6,    50,    -1,
      51,   480,    52,     6,    -1,    53,    -1,    46,    -1,    47,
      -1,   100,   480,    -1,   114,    -1,   343,    -1,   342,    -1,
     331,    -1,   345,    -1,   379,    -1,   383,    -1,   429,    -1,
     292,    -1,   294,    -1,   311,    -1,   206,   352,   259,   477,
     261,   357,   351,    -1,   192,   352,   259,   477,   223,   357,
      -1,   206,   350,   261,   357,    -1,   192,   350,   223,   357,
      -1,   167,    -1,   161,    -1,   245,    -1,    -1,   105,    -1,
     255,   418,    -1,   110,    -1,   237,    -1,   353,    -1,   354,
      -1,   353,   243,   354,    -1,   194,   355,    -1,   185,    -1,
     180,    -1,   197,   355,    -1,   201,    -1,   207,    -1,    -1,
     179,   356,   166,    -1,   420,    -1,   356,   243,   420,    -1,
     358,    -1,   357,   243,   358,    -1,   191,    -1,   418,    -1,
     123,   477,   360,   255,   450,   362,    -1,    -1,   179,   361,
     166,    -1,   420,    -1,   361,   243,   420,    -1,    -1,   104,
      -1,   202,   179,   449,   166,    -1,   126,   179,   366,   166,
     365,    -1,   139,   367,    -1,   368,    -1,   477,    -1,   477,
     179,   368,   166,    -1,   420,    -1,   368,   243,   420,    -1,
     196,   179,   370,   166,    -1,   154,   179,   370,   166,    -1,
     130,   179,   370,   166,    -1,   420,    -1,   370,   243,   420,
      -1,   369,    -1,   364,    -1,   363,    -1,   170,   425,    -1,
     118,    -1,   117,    -1,   116,    -1,   480,   409,   374,   375,
      -1,    -1,   372,    -1,    -1,   376,    -1,   377,    -1,   376,
     377,    -1,   378,   327,    -1,   160,    -1,   108,    -1,   196,
      -1,   154,    -1,   365,    -1,   202,   179,   449,   166,    -1,
     130,    -1,    98,   380,   382,    -1,   381,    -1,   418,    -1,
     383,    -1,   382,   383,    -1,   359,    -1,   349,    -1,   184,
     393,    -1,   215,   393,    -1,   223,   387,    -1,   389,    -1,
     387,   243,   389,    -1,   387,   243,   213,   389,    -1,   387,
     243,   213,   179,   387,   166,    -1,   387,    33,   388,   259,
     393,    -1,   387,    40,   388,   259,   393,    -1,   387,    -1,
     179,   387,   166,    -1,   477,    -1,   477,   424,    -1,   477,
     255,   424,    -1,    -1,   386,   391,    -1,   392,    -1,   385,
     392,    -1,    -1,   446,    -1,   446,   384,    -1,   384,    -1,
     394,    -1,   393,   260,   394,    -1,   395,    -1,   394,   238,
     395,    -1,   396,    -1,   251,   396,    -1,   406,    -1,   179,
     393,   166,    -1,   182,   460,    -1,   138,   460,    -1,    -1,
     181,   402,    -1,    -1,   181,   402,    -1,    -1,   181,   402,
      -1,   503,    -1,   425,    -1,    -1,   251,    -1,   465,   403,
     163,    -1,   465,   403,   128,    -1,   465,   405,   465,    -1,
     465,   188,   465,    -1,   465,   188,   199,    -1,   465,   403,
     165,   465,   238,   465,    -1,   465,   226,   401,   400,    -1,
     465,   158,   401,   400,    -1,   465,   265,   401,   399,    -1,
     465,   159,   401,   399,    -1,   465,   173,   401,   398,    -1,
     465,   129,   401,   398,    -1,   189,    -1,   208,    -1,   176,
      -1,   264,    -1,   164,    -1,   150,    -1,   404,    -1,   472,
      -1,   397,    -1,   465,    -1,    -1,   237,    -1,   154,    -1,
     196,    -1,    -1,   237,    -1,   154,    -1,   196,    -1,   410,
      -1,   411,    -1,   412,    -1,   414,    -1,   144,    -1,   144,
     179,   415,   166,    -1,   195,    -1,   195,   179,     3,   166,
      -1,   172,    -1,   172,   179,     3,   166,    -1,   169,    -1,
     169,   179,   416,   413,   166,    -1,   209,   179,   416,   413,
     166,    -1,   209,    -1,   218,    -1,   171,    -1,   162,    -1,
     145,    -1,   145,   179,   415,   166,    -1,   146,    -1,   146,
     179,     3,   166,    -1,   146,   179,     3,   243,     3,   166,
      -1,   153,   427,   261,   428,    -1,   153,    -1,   157,   427,
     261,   428,    -1,   451,    -1,   157,    -1,   157,   427,   179,
       3,   166,   261,   428,    -1,   229,    -1,   216,    -1,   174,
      -1,   174,   179,     3,   166,    -1,   174,   179,     3,   243,
       3,   166,    -1,    -1,   243,   417,    -1,   205,   179,   416,
     166,    -1,   227,    -1,   141,    -1,   205,    -1,    79,    -1,
       3,    -1,     3,    -1,     3,    -1,   480,    -1,     6,    -1,
      -1,   190,     3,   175,    -1,   190,     3,   243,     3,   175,
      -1,   423,    -1,   253,   423,    -1,   422,    -1,   253,   422,
      -1,   480,   419,    -1,   475,   257,   480,   419,    -1,   475,
     257,   211,    -1,   269,    -1,   480,   419,    -1,   475,   257,
     480,   419,    -1,   480,   257,   480,   257,   480,   419,    -1,
     475,   257,   211,    -1,   480,    -1,     6,    -1,   482,    -1,
       3,    -1,   440,    -1,    -1,   427,   261,   428,    -1,   233,
      -1,   210,    -1,   244,    -1,   224,    -1,   186,    -1,   193,
      -1,   155,    -1,   233,    -1,   210,    -1,   244,    -1,   224,
      -1,   186,    -1,   193,    -1,   155,    -1,   155,   179,     3,
     166,    -1,   434,    -1,   433,    -1,   430,    -1,   143,   431,
     261,   431,    -1,   140,   475,   257,   432,   261,   432,    -1,
     480,    -1,   480,    -1,   119,   477,    -1,   137,   477,   435,
      -1,   132,    -1,   113,    -1,   437,    -1,   437,   427,   261,
     428,    -1,    54,    -1,   439,    -1,   439,   427,   179,     3,
     166,   261,   428,    -1,   439,   427,   261,   428,    -1,    55,
      -1,   168,   426,    -1,   212,   256,   442,    -1,   443,    -1,
     442,   243,   443,    -1,   444,   445,    -1,     3,    -1,   421,
      -1,    -1,   240,    -1,   219,    -1,   156,   447,    -1,   448,
      -1,   447,   243,   448,    -1,   421,    -1,     3,    -1,   393,
      -1,   459,    -1,   267,    -1,   267,   179,     3,   166,    -1,
     270,    -1,   270,   179,     3,   166,    -1,    -1,    -1,   194,
     461,   462,   453,   463,   454,   484,   390,   456,   457,    -1,
     194,   461,   462,   463,   390,   456,    -1,    -1,   214,   408,
     455,    -1,    -1,   441,    -1,   441,   151,   458,   306,    -1,
     151,   458,   306,    -1,   480,    -1,   194,   461,   462,   463,
     390,    -1,   179,   194,   461,   462,   463,   390,   166,    -1,
      -1,   204,     3,    -1,    -1,   237,    -1,   154,    -1,   196,
      -1,   464,    -1,   463,   243,   464,    -1,   465,    -1,   465,
     480,    -1,   465,   255,   480,    -1,   503,    -1,   249,   503,
      -1,   254,   503,    -1,   503,   220,   465,    -1,   503,   471,
      -1,   503,   211,   465,    -1,   503,   254,   465,    -1,   503,
     249,   465,    -1,   503,    58,   465,    -1,   425,    -1,   200,
      -1,   177,    -1,   231,    -1,   268,    -1,   269,    -1,   267,
      -1,   211,    -1,    80,    -1,   241,   179,   407,   465,   166,
      -1,   247,   179,   407,   465,   166,    -1,   248,   179,   407,
     465,   166,    -1,   252,   179,   407,   465,   166,    -1,   203,
     179,   407,   465,   166,    -1,     4,   179,   166,    -1,     4,
     179,   469,   166,    -1,   233,   179,   469,   166,    -1,   210,
     179,   469,   166,    -1,   244,   179,   469,   166,    -1,    48,
     179,   469,   166,    -1,    49,   179,   469,   166,    -1,   234,
     179,   469,   166,    -1,   218,   179,   469,   166,    -1,   179,
     465,   166,    -1,   183,   179,   470,   166,    -1,   436,    -1,
     438,    -1,   217,   467,   263,    -1,   468,    -1,   467,   468,
      -1,   232,   393,   230,   465,    -1,   222,   465,    -1,   465,
      -1,   469,   243,   465,    -1,   168,   243,   427,   261,   428,
      -1,   496,   243,   427,   261,   428,    -1,   168,   427,   261,
     428,    -1,   465,   243,   427,   261,   428,    -1,    84,    -1,
      85,    -1,    86,    -1,    87,    -1,    88,    -1,    89,    -1,
     465,   258,   179,   473,   166,    -1,   465,   258,   460,    -1,
     465,   178,   179,   473,   166,    -1,   465,   178,   460,    -1,
     474,    -1,   473,   243,   474,    -1,   496,    -1,   425,    -1,
     249,     3,    -1,   249,   482,    -1,   476,    -1,     6,    -1,
       6,   257,   480,    -1,   480,    -1,   480,   242,   480,    -1,
     480,   242,     6,   257,   480,    -1,   480,   253,   480,    -1,
     480,   253,   480,   242,   480,    -1,   480,   253,   480,   242,
       6,   257,   480,    -1,   478,    -1,     6,   257,   480,    -1,
     480,   257,   480,    -1,     6,    -1,   480,    -1,   480,   242,
     480,    -1,   480,   242,     6,   257,   480,    -1,   480,   253,
     480,    -1,   480,   253,   480,   242,   480,    -1,   480,   253,
     480,   242,     6,   257,   480,    -1,     6,   257,   480,    -1,
       6,    -1,   480,    -1,   480,   242,   480,    -1,   480,   242,
       6,   257,   480,    -1,   480,   253,   480,    -1,   480,   253,
     480,   242,   480,    -1,   480,   253,   480,   242,     6,   257,
     480,    -1,     4,    -1,     4,    -1,    15,    -1,   257,     3,
      -1,     4,    -1,     6,    -1,    -1,   480,    -1,   488,    -1,
     486,    16,   488,    -1,   332,    -1,   281,    -1,   341,    -1,
      -1,   497,    -1,   348,    -1,   489,    -1,   495,    -1,   487,
      -1,   347,    -1,     1,    -1,   491,   492,    -1,   485,    -1,
     452,    -1,    -1,   136,    -1,   135,   493,    -1,   494,    -1,
     493,   243,   494,    -1,   480,    -1,   480,   257,   480,    -1,
       6,   257,   480,   257,   480,    -1,   122,    -1,   121,    -1,
     109,   505,    -1,   106,    -1,   102,    -1,    99,    -1,    97,
      -1,   101,    -1,   502,    -1,    17,    -1,   498,    -1,   152,
     483,   344,    -1,    20,     6,    21,    -1,   179,   499,   166,
      -1,   499,   500,   499,    -1,     3,    -1,   501,     3,    -1,
     254,    -1,   249,    -1,   211,    -1,   220,    -1,   250,    -1,
     254,    -1,   249,    -1,   480,    -1,   480,   257,   211,    -1,
     480,   257,   269,    -1,   480,   257,   480,    -1,   480,   257,
     480,   257,   480,    -1,     6,   257,   480,   257,   480,    -1,
     480,   190,   499,   175,    -1,   480,   257,   480,   190,   499,
     175,    -1,   480,   257,   480,   257,   480,   190,   499,   175,
      -1,     6,   257,   480,   257,   480,   190,   499,   175,    -1,
     480,   190,   499,   243,   499,   175,    -1,   480,   257,   480,
     190,   499,   243,   499,   175,    -1,   480,   257,   480,   257,
     480,   190,   499,   243,   499,   175,    -1,     6,   257,   480,
     257,   480,   190,   499,   243,   499,   175,    -1,   504,    -1,
     504,    96,   409,    -1,   466,    -1,   496,    -1,   460,    -1,
     237,   460,    -1,   239,   460,    -1,   228,   460,    -1,    -1,
       3,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   454,   454,   480,   483,   500,   505,   508,   525,   531,
     540,   549,   558,   565,   580,   635,   642,   653,   656,   661,
     668,   685,   702,   723,   732,   735,   743,   746,   754,   755,
     762,   765,   773,   776,   780,   786,   787,   791,   801,   815,
     816,   820,   821,   826,   834,   842,   850,   858,   868,   870,
     870,   873,   874,   878,   885,   892,   899,   908,   912,   919,
     931,   942,   948,   952,   956,   961,   965,   968,   972,   975,
     982,   983,   993,   994,   998,   999,  1003,  1012,  1021,  1028,
    1031,  1037,  1040,  1051,  1055,  1060,  1067,  1070,  1079,  1082,
    1086,  1090,  1094,  1098,  1102,  1110,  1114,  1122,  1125,  1132,
    1135,  1142,  1145,  1152,  1153,  1158,  1162,  1165,  1171,  1174,
    1180,  1187,  1188,  1192,  1200,  1204,  1211,  1213,  1218,  1219,
    1223,  1225,  1231,  1232,  1235,  1246,  1252,  1252,  1261,  1261,
    1270,  1295,  1298,  1306,  1309,  1316,  1319,  1327,  1328,  1334,
    1335,  1343,  1361,  1365,  1370,  1371,  1381,  1390,  1394,  1398,
    1403,  1407,  1411,  1414,  1421,  1422,  1423,  1427,  1428,  1429,
    1430,  1431,  1432,  1433,  1441,  1442,  1443,  1444,  1449,  1450,
    1451,  1454,  1455,  1456,  1460,  1461,  1462,  1466,  1467,  1471,
    1478,  1479,  1480,  1487,  1488,  1491,  1492,  1497,  1498,  1503,
    1504,  1509,  1510,  1515,  1522,  1523,  1528,  1529,  1533,  1534,
    1541,  1549,  1556,  1563,  1567,  1568,  1573,  1574,  1580,  1584,
    1589,  1596,  1597,  1603,  1606,  1609,  1616,  1617,  1618,  1619,
    1625,  1648,  1649,  1652,  1654,  1661,  1664,  1670,  1678,  1683,
    1689,  1694,  1700,  1703,  1708,  1716,  1725,  1730,  1734,  1735,
    1741,  1744,  1755,  1764,  1771,  1777,  1778,  1781,  1786,  1797,
    1801,  1808,  1809,  1813,  1817,  1821,  1828,  1833,  1841,  1844,
    1850,  1853,  1858,  1863,  1876,  1879,  1885,  1888,  1894,  1897,
    1903,  1906,  1913,  1917,  1928,  1928,  1929,  1929,  1930,  1930,
    1933,  1938,  1943,  1944,  1949,  1958,  1966,  1969,  1972,  1976,
    1983,  1986,  1990,  1993,  1996,  1999,  2005,  2012,  2015,  2018,
    2021,  2022,  2027,  2030,  2033,  2036,  2043,  2044,  2045,  2049,
    2056,  2057,  2058,  2062,  2076,  2083,  2084,  2085,  2089,  2090,
    2095,  2096,  2105,  2107,  2116,  2119,  2127,  2137,  2145,  2147,
    2148,  2149,  2150,  2151,  2152,  2153,  2161,  2162,  2163,  2164,
    2165,  2166,  2167,  2168,  2169,  2170,  2171,  2181,  2182,  2188,
    2190,  2191,  2192,  2193,  2197,  2201,  2205,  2212,  2213,  2218,
    2219,  2223,  2231,  2234,  2241,  2244,  2254,  2257,  2260,  2263,
    2270,  2277,  2285,  2294,  2301,  2305,  2310,  2311,  2312,  2317,
    2319,  2328,  2328,  2328,  2328,  2328,  2328,  2328,  2329,  2329,
    2329,  2329,  2329,  2329,  2329,  2329,  2374,  2375,  2376,  2381,
    2382,  2385,  2386,  2390,  2397,  2408,  2409,  2422,  2423,  2427,
    2431,  2432,  2435,  2441,  2445,  2468,  2478,  2481,  2487,  2496,
    2500,  2507,  2508,  2510,  2515,  2521,  2524,  2530,  2531,  2538,
    2551,  2561,  2568,  2585,  2592,  2617,  2619,  2617,  2641,  2685,
    2686,  2700,  2703,  2710,  2720,  2732,  2738,  2751,  2766,  2768,
    2774,  2775,  2776,  2777,  2787,  2790,  2796,  2799,  2804,  2813,
    2816,  2820,  2827,  2830,  2833,  2836,  2839,  2842,  2845,  2846,
    2847,  2848,  2849,  2850,  2851,  2852,  2853,  2855,  2859,  2863,
    2867,  2871,  2875,  2879,  2883,  2886,  2889,  2892,  2895,  2898,
    2901,  2904,  2907,  2911,  2915,  2919,  2927,  2930,  2939,  2945,
    2952,  2955,  2983,  2986,  2989,  2992,  2998,  2999,  3000,  3001,
    3002,  3003,  3008,  3012,  3016,  3020,  3027,  3030,  3035,  3036,
    3037,  3039,  3045,  3055,  3059,  3063,  3067,  3071,  3075,  3079,
    3083,  3091,  3101,  3106,  3110,  3114,  3118,  3122,  3127,  3131,
    3135,  3143,  3146,  3151,  3152,  3153,  3158,  3159,  3160,  3168,
    3171,  3176,  3177,  3181,  3182,  3187,  3211,  3228,  3229,  3233,
    3240,  3246,  3256,  3258,  3261,  3262,  3263,  3264,  3266,  3269,
    3273,  3278,  3282,  3288,  3289,  3292,  3297,  3298,  3301,  3302,
    3303,  3313,  3314,  3315,  3316,  3317,  3318,  3319,  3320,  3324,
    3330,  3332,  3351,  3359,  3366,  3367,  3368,  3369,  3374,  3375,
    3376,  3377,  3378,  3383,  3384,  3400,  3401,  3402,  3403,  3404,
    3405,  3406,  3407,  3408,  3409,  3411,  3412,  3413,  3414,  3419,
    3422,  3431,  3432,  3433,  3434,  3435,  3436,  3440,  3441
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
  "WITH_LISTING_IN", "SET_CONSTRAINTS_ALL_DEFERRED", "KW_LIMIT",
  "DOCUMENT", "ON_EXCEPTION", "SET_DEBUG_FILE_TO", "CREATE_DBA_PROCEDURE",
  "CREATE_FUNCTION", "CREATE_DBA_FUNCTION", "USE_SESSION", "KW_RUN_CLIENT",
  "LEFT_JOIN", "IGNORE_ERRORS", "SQLERRMESSAGE", "DISPLAY_NULL_TO",
  "UNBUFFERED", "KW_PICTURE", "ON_CHANGE", "INNER_JOIN",
  "UI_INTERFACE_DOT_FRONTCALL", "UICOMBOBOX", "UIFORM", "USING_BTREE",
  "USING_RTREE", "SET_BUFFERED_LOG", "SET_LOG", "MDY", "WEEKDAY",
  "MODE_ANSI", "START_DATABASE", "WITH_LOG_IN",
  "SET_CONSTRAINTS_ALL_IMMEDIATE", "DATETIME_VALUE", "INTERVAL_VALUE",
  "RECOVER_TABLE", "ROLLFORWARD_DATABASE", "CONCAT_PIPES", "DROP_TRIGGER",
  "DROP_AUDIT_FOR", "CREATE_AUDIT_FOR", "EXECUTE_PROCEDURE", "ALTER_TABLE",
  "ALTER_INDEX", "NEXT_SIZE", "XSET_MULTIPLY_EQUAL_OPEN_BRACKET",
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
  "FILLFACTOR", "TIME", "KW_TODAY", "KW_ROWID", "TIMESTAMP", "KW_TAG",
  "LINTMODULEISLIBRARY", "KW_PUBLIC", "KW_PRIVATE", "COPYBACK",
  "REFERENCES_BLOBTYPE_DEFAULT_NULL", "REFERENCES_BLOBTYPE", "SORT",
  "KWPIPE", "$accept", "update_statement_c", "where_upd_p", "where_del_p",
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
  "op_ad", "select_list_slil", "value_expression_pls_sli",
  "value_expression_sli", "value_expression_complex_sli", "sql_case_stmt",
  "sql_case_stmt_element", "value_expr_list_slil", "extend_qual_sli",
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
       0,   256,  2230,  2231,  2232,  2233,  2234,  2235,  2236,  2237,
    2238,  2239,  2240,  2241,  2242,  2243,  2244,  2245,  2246,  2247,
    2248,  2249,  1001,  1002,  1003,  1004,  1006,  1007,  1012,  1013,
    1014,  1016,  1017,  1019,  1022,  1023,  1024,  1025,  1026,  1027,
    1028,  1031,  1035,  1038,  1054,  1055,  1074,  1077,  1079,  1080,
    1083,  1084,  1085,  1086,  1099,  1100,  1101,  1102,  1116,  1118,
    1119,  1120,  1124,  1131,  1132,  1133,  1170,  1171,  1172,  1173,
    1174,  1177,  1178,  1180,  1181,  1182,  1183,  1186,  1187,  1194,
    1195,  1215,  1216,  1217,  1224,  1225,  1226,  1227,  1228,  1229,
    1234,  1235,  1237,  1238,  1239,  1240,  1250,  1256,  1257,  1258,
    1259,  1260,  1271,  1272,  1280,  1281,  1282,  1288,  1296,  1303,
    1305,  1309,  1310,  1312,  1317,  1343,  1344,  1345,  1346,  1359,
    1367,  1369,  1370,  1374,  1375,  1382,  1383,  1386,  1388,  1391,
    1397,  1404,  1407,  1413,  1418,  1424,  1425,  1430,  1432,  1434,
    1435,  1437,  1448,  1455,  1458,  1459,  1460,  1462,  1464,  1467,
    1471,  1473,  1497,  1498,  1500,  1507,  1509,  1510,  1512,  1513,
    1514,  1520,  1521,  1527,  1528,  1530,  1533,  1536,  1537,  1539,
    1541,  1549,  1551,  1554,  1567,  1570,  1571,  1572,  1573,  1575,
    1583,  1586,  1587,  1588,  1592,  1594,  1598,  1599,  1601,  1602,
    1604,  1608,  1612,  1616,  1620,  1621,  1624,  1626,  1627,  1630,
    1631,  1633,  1639,  1643,  1648,  1649,  1652,  1655,  1658,  1660,
    1661,  1663,  1664,  1665,  1674,  1677,  1684,  1686,  1688,  1689,
    1690,  1693,  1694,  1698,  1704,  1705,  1708,  1717,  1722,  1726,
    1727,  1728,  1730,  1733,  1734,  1736,  1737,  1738,  1739,  1740,
    1741,  1742,  1743,  1744,  1745,  1746,  1750,  1755,  1756,  1757,
    1758,  1759,  1766,  1769,  1770,  1776,  1778,  1779,  1782,  1784,
    1785,  1786,  1824,  1828,  1835,  1836,  1839,  1844,  1851,  1852,
    2200,  2221,  2222,  2223,  2224,  2225,  2226,  2227,  2228,  2229
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint16 yyr1[] =
{
       0,   280,   281,   282,   282,   282,   283,   283,   283,   284,
     284,   284,   284,   284,   284,   285,   285,   286,   286,   287,
     287,   287,   287,   288,   289,   289,   290,   290,   291,   291,
     292,   293,   293,   293,   293,   294,   294,   295,   295,   296,
     296,   297,   297,   298,   298,   298,   298,   298,   299,   300,
     300,   301,   301,   302,   302,   302,   302,   303,   304,   304,
     304,   304,   304,   304,   304,   304,   304,   304,   304,   304,
     305,   305,   306,   306,   307,   307,   308,   308,   308,   309,
     309,   310,   310,   311,   311,   311,   312,   312,   313,   313,
     313,   313,   313,   313,   313,   314,   314,   315,   315,   316,
     316,   317,   317,   318,   318,   319,   320,   320,   321,   321,
     322,   323,   323,   324,   325,   325,   326,   326,   327,   327,
     328,   328,   329,   329,   330,   331,   333,   332,   335,   334,
     334,   336,   336,   337,   337,   338,   338,   339,   339,   340,
     340,   341,   342,   343,   344,   344,   345,   346,   346,   346,
     346,   346,   346,   346,   347,   347,   347,   348,   348,   348,
     348,   348,   348,   348,   349,   349,   349,   349,   350,   350,
     350,   351,   351,   351,   352,   352,   352,   353,   353,   354,
     354,   354,   354,   354,   354,   355,   355,   356,   356,   357,
     357,   358,   358,   359,   360,   360,   361,   361,   362,   362,
     363,   364,   365,   366,   367,   367,   368,   368,   369,   369,
     369,   370,   370,   371,   371,   371,   372,   372,   372,   372,
     373,   374,   374,   375,   375,   376,   376,   377,   378,   378,
     378,   378,   378,   378,   378,   379,   380,   381,   382,   382,
     383,   383,   384,   385,   386,   387,   387,   387,   387,   387,
     387,   388,   388,   389,   389,   389,   390,   390,   391,   391,
     392,   392,   392,   392,   393,   393,   394,   394,   395,   395,
     396,   396,   397,   397,   398,   398,   399,   399,   400,   400,
     401,   402,   403,   403,   404,   404,   404,   404,   404,   404,
     404,   404,   404,   404,   404,   404,   405,   405,   405,   405,
     405,   405,   406,   406,   406,   406,   407,   407,   407,   407,
     408,   408,   408,   408,   409,   410,   410,   410,   411,   411,
     412,   412,   412,   412,   412,   412,   412,   412,   412,   412,
     412,   412,   412,   412,   412,   412,   412,   412,   412,   412,
     412,   412,   412,   412,   412,   412,   412,   413,   413,   414,
     414,   414,   414,   414,   415,   416,   417,   418,   418,   419,
     419,   419,   420,   420,   421,   421,   422,   422,   422,   422,
     423,   423,   423,   423,   424,   425,   425,   425,   425,   426,
     426,   427,   427,   427,   427,   427,   427,   427,   428,   428,
     428,   428,   428,   428,   428,   428,   429,   429,   429,   430,
     430,   431,   432,   433,   434,   435,   435,   436,   436,   437,
     438,   438,   438,   439,   440,   441,   442,   442,   443,   444,
     444,   445,   445,   445,   446,   447,   447,   448,   448,   449,
     450,   451,   451,   451,   451,   453,   454,   452,   455,   456,
     456,   457,   457,   457,   457,   458,   459,   460,   461,   461,
     462,   462,   462,   462,   463,   463,   464,   464,   464,   465,
     465,   465,   466,   466,   466,   466,   466,   466,   466,   466,
     466,   466,   466,   466,   466,   466,   466,   466,   466,   466,
     466,   466,   466,   466,   466,   466,   466,   466,   466,   466,
     466,   466,   466,   466,   466,   466,   467,   467,   468,   468,
     469,   469,   470,   470,   470,   470,   471,   471,   471,   471,
     471,   471,   472,   472,   472,   472,   473,   473,   474,   474,
     474,   474,   475,   476,   476,   476,   476,   476,   476,   476,
     476,   477,   478,   478,   478,   478,   478,   478,   478,   478,
     478,   479,   479,   479,   479,   479,   479,   479,   479,   480,
     481,   482,   482,   483,   483,   484,   485,   486,   486,   487,
     487,   487,   488,   488,   488,   488,   488,   488,   488,   488,
     489,   490,   491,   492,   492,   492,   493,   493,   494,   494,
     494,   495,   495,   495,   495,   495,   495,   495,   495,   496,
     496,   496,   497,   498,   499,   499,   499,   499,   500,   500,
     500,   500,   500,   501,   501,   502,   502,   502,   502,   502,
     502,   502,   502,   502,   502,   502,   502,   502,   502,   503,
     503,   504,   504,   504,   504,   504,   504,   505,   505
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
       0,     1,     1,     1,     1,     3,     1,     2,     3,     1,
       2,     2,     3,     2,     3,     3,     3,     3,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     5,     5,     5,
       5,     5,     3,     4,     4,     4,     4,     4,     4,     4,
       4,     3,     4,     1,     1,     3,     1,     2,     4,     2,
       1,     3,     5,     5,     4,     5,     1,     1,     1,     1,
       1,     1,     5,     3,     5,     3,     1,     3,     1,     1,
       2,     2,     1,     1,     3,     1,     3,     5,     3,     5,
       7,     1,     3,     3,     1,     1,     3,     5,     3,     5,
       7,     3,     1,     1,     3,     5,     3,     5,     7,     1,
       1,     1,     2,     1,     1,     0,     1,     1,     3,     1,
       1,     1,     0,     1,     1,     1,     1,     1,     1,     1,
       2,     1,     1,     0,     1,     2,     1,     3,     1,     3,
       5,     1,     1,     2,     1,     1,     1,     1,     1,     1,
       1,     1,     3,     3,     3,     3,     1,     2,     1,     1,
       1,     1,     1,     1,     1,     1,     3,     3,     3,     5,
       5,     4,     6,     8,     8,     6,     8,    10,    10,     1,
       3,     1,     1,     1,     2,     2,     2,     0,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       0,   569,   150,   151,     0,   149,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     587,     0,   586,     0,   588,   585,     0,   584,   627,     0,
       0,   153,     0,     0,   125,   582,   581,     0,     0,   126,
     142,     0,     0,     0,   143,     0,     0,     0,     0,   448,
       0,     0,   560,   161,    30,   162,    36,    35,   163,   156,
     559,   561,   155,   154,   157,   146,   568,   564,   241,   240,
     158,   159,   160,   398,   397,   396,   572,     0,   567,   557,
     565,   573,   566,   563,   549,     0,   534,    68,   531,   535,
      69,    34,    66,     0,     0,   542,     0,   543,   556,   571,
      62,    63,    67,     0,     0,     0,     0,   358,     0,   236,
     237,   357,   152,     0,   628,   583,     0,    31,     0,   403,
     194,     6,     0,    33,     0,     0,     0,   522,   525,     0,
     401,    32,   553,   554,   144,   174,   169,   168,   181,   180,
     185,   185,   183,   184,   175,   170,     0,     0,   176,   177,
       0,   450,     0,     0,     0,     1,     0,     0,   574,   570,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   111,
     112,     0,     0,     0,    83,    86,    88,    89,    90,    94,
      93,    91,    92,     0,    84,    85,     0,     0,     0,     0,
       0,     0,   235,   238,     0,     0,     0,     0,     0,     0,
       0,   141,   131,   406,   405,   404,     0,     0,     0,     0,
       0,   145,   592,     0,   179,   182,     0,     0,     0,   449,
     452,   453,   451,   435,     0,     0,     0,     0,     0,     0,
       3,     0,     0,   558,     0,   578,   575,   576,   148,   532,
       0,   536,   538,   533,    65,     0,     0,     0,     0,     0,
       0,   215,   214,   213,   118,     0,   120,   122,   124,   113,
       0,   110,   106,    82,    81,     0,     0,   101,   105,     0,
      97,    95,     0,   541,     0,   544,   546,     0,    57,     0,
       0,     0,   239,     0,    79,    64,     0,     0,     0,   196,
     362,     0,   359,     0,   550,     7,   377,   549,   375,   551,
     590,     0,     0,     0,   409,   413,   476,     0,   379,   470,
       0,     0,     0,   469,     0,     0,   475,     0,     0,     0,
     471,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   474,   472,   473,     8,   264,   266,
     268,   304,   302,   270,   468,   493,   407,   494,   410,   378,
     623,   305,   621,   303,   605,   376,   622,   591,   589,   459,
     619,     0,     0,   524,     0,   402,     0,   526,   528,   399,
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
     272,     0,   306,     0,     0,     0,     0,   496,     0,   626,
       0,     0,   624,   625,   306,     0,   306,   306,   460,   269,
     306,   461,   552,     0,     0,     0,     0,     0,   301,     0,
       0,   300,     0,   298,     0,     0,   296,   297,     0,   283,
       0,   299,     0,     0,     0,     0,     0,     0,   506,   507,
     508,   509,   510,   511,     0,     0,     0,     0,   463,     0,
       0,   133,   135,   128,   127,   130,     0,     0,     0,   186,
       0,     0,     0,   436,   454,   456,     0,    10,     0,    11,
      18,     0,     0,     0,    19,     0,     0,     4,     5,     0,
       0,   579,   577,   537,     0,   539,     0,   203,   206,     0,
     211,     0,   115,     0,   116,     0,   429,     0,   119,   121,
     123,   107,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   219,   218,   217,     0,
     222,   223,   102,     0,    96,     0,    98,   545,     0,   547,
       0,    74,    78,     0,     0,     0,    71,    39,    80,     0,
      46,    47,     0,     0,    37,    40,    41,   197,   373,   359,
       0,     0,   450,   199,   193,   482,   500,     0,     0,   593,
       0,     0,     0,   450,   271,   491,   379,     0,     0,   622,
     308,   309,   307,     0,     0,   499,     0,   495,   497,     0,
       0,     0,     0,     0,     0,     0,     0,   265,   267,     0,
       0,     0,   274,   280,   278,   276,   274,     0,   515,   288,
     287,   278,     0,   513,   276,   285,   284,     0,   286,   596,
       0,   604,   603,     0,     0,   606,   607,   608,   467,   464,
     462,   466,   465,   620,   132,     0,     0,     0,   400,   527,
       0,   529,   188,   190,   165,     0,   555,     0,   457,    27,
       0,    25,    22,   359,    16,    23,   171,     0,     0,     0,
       0,   210,     0,   209,   118,   208,   200,   109,   354,     0,
       0,     0,     0,     0,     0,   355,   347,     0,     0,     0,
       0,   347,     0,     0,   375,   216,   229,   234,     0,   231,
     228,   230,     0,   232,   220,   224,   225,   118,   104,   100,
       0,    49,     0,    77,    76,    49,    49,    49,    70,    45,
      44,    48,    43,    42,   371,   360,     0,     0,     0,   483,
       0,     0,   487,   488,   394,   392,   393,   389,   391,   388,
     390,   380,     0,     0,     0,     0,   492,     0,     0,   485,
       0,   490,   484,   489,     0,   486,     0,     0,     0,   408,
       0,   412,     0,   295,     0,   291,     0,   293,   294,     0,
     519,     0,   516,   518,   290,     0,   292,     0,     0,   611,
     600,   601,     0,   599,   602,   598,     0,   597,     0,     0,
     134,   136,     0,     0,   455,   256,   458,     0,     0,    20,
     172,     0,   164,   580,   540,   201,   207,   212,   117,   319,
     332,   334,     0,   336,     0,   338,     0,     0,   323,   345,
       0,   321,   349,     0,   432,   434,   202,   204,     0,   226,
     227,   548,    55,    56,     0,     0,    59,    50,    51,    75,
      58,    60,    61,    38,     0,   359,   256,   501,   610,     0,
     256,     0,     0,     0,     0,   481,   498,   477,   478,   479,
     480,     0,   275,   281,   279,   277,   520,   521,   514,     0,
     512,     0,   594,     0,   595,     0,   609,   140,     0,   137,
     139,   530,     0,   260,   439,     0,   359,   173,     0,     0,
     356,   348,   325,     0,   326,     0,     0,    53,    54,    52,
     361,   372,   446,     0,     0,     0,     0,   380,     0,     0,
       0,   517,   289,   615,   612,     0,     0,   129,     0,   244,
     245,   253,     0,     0,     0,   263,   260,   257,   258,   261,
     310,   441,     9,    21,   335,     0,   346,     0,   233,     0,
     395,   447,   502,   505,   503,   411,     0,     0,   138,     0,
       0,     0,     0,   254,   374,   428,     0,   369,   427,   364,
     424,   425,     0,   359,   242,   243,   259,   262,   312,   313,
     311,     0,     0,     0,   442,   437,   341,   205,   614,     0,
     616,   613,     0,     0,   251,     0,     0,     0,   246,   255,
     365,     0,     0,   366,   448,   440,    72,   445,     0,     0,
       0,     0,     0,     0,     0,     0,   247,   426,   368,   359,
     450,    73,   444,   419,   420,   415,   416,   421,    72,   618,
     617,   252,   249,   250,     0,   367,     0,     0,   423,   422,
     418,   443,   248,   256,   417,   439,   438
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    52,   397,   201,   230,   392,   393,   389,   394,   390,
     381,   382,    53,    54,    55,    56,   644,   645,   646,   802,
     916,   917,   918,   277,    57,   637,  1092,   630,   631,   283,
     261,    58,   174,   175,   176,   271,   449,   177,   446,   267,
     178,   417,   262,   179,   180,   181,   409,   414,   182,   256,
     257,    59,    60,   122,   554,   727,   362,   550,   551,   958,
     959,    61,    62,    63,   212,    64,    65,    66,    67,    68,
     146,   882,   147,   148,   149,   214,   370,   373,   374,    69,
     198,   288,   654,   251,   252,   783,   586,   906,   587,   253,
     589,   263,   620,   264,   621,   784,   785,   786,   787,    70,
     108,   109,   192,    71,  1005,  1006,   963,  1064,  1065,  1000,
     964,  1007,  1008,   596,   338,   339,   340,   341,   843,   847,
     845,   692,   942,   533,   342,   534,   343,   673,  1051,   440,
     441,   442,   443,   897,   444,   759,   766,   971,   375,   467,
     590,  1038,  1039,   290,  1033,   344,   485,   486,   821,    72,
      73,   129,   364,    74,    75,   205,   345,   346,   347,   348,
     349,  1054,  1095,  1096,  1097,  1110,  1009,  1040,  1041,   597,
     469,   445,    76,   378,   736,  1075,  1011,  1055,  1076,   470,
     350,   151,   223,   563,   564,   351,   352,   496,   497,   657,
     668,   548,   353,   851,   852,   291,   127,  1001,    88,    96,
     354,   295,   355,   134,   875,    99,    77,    78,    79,    80,
     100,    81,   159,   236,   237,    82,   356,    83,   357,   713,
     866,   714,   358,   359,   360,   115
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -891
static const yytype_int16 yypact[] =
{
    2322,  -891,  -891,  -891,   168,  -891,   540,   168,   168,   540,
     540,   168,   687,   168,   168,   540,   687,   687,   687,   687,
    -891,   688,  -891,   168,  -891,  -891,   540,  -891,   178,   540,
     540,  -891,   540,   540,  -891,  -891,  -891,   540,   540,  -891,
    -891,   687,   540,   694,  -891,   168,   540,   725,   398,    92,
     540,   398,  -891,  -891,  -891,  -891,  -891,  -891,  -891,  -891,
    -891,  -891,  -891,  -891,  -891,  -891,  -891,  -891,  -891,  -891,
    -891,  -891,  -891,  -891,  -891,  -891,  -891,   264,  -891,  -891,
    -891,   376,  -891,  -891,  -891,   266,     6,  -891,  -891,   288,
    -891,  -891,  -891,    87,   341,   242,   622,   411,  -891,  -891,
    -891,  -891,  -891,    99,   133,   160,   246,  -891,    54,  -891,
    -891,  -891,  -891,   336,  -891,  -891,   281,  -891,   352,  -891,
     360,   -50,   540,  -891,   350,   309,   315,  -891,   412,   303,
    -891,  -891,  -891,  -891,   432,  -891,  -891,  -891,  -891,  -891,
     467,   467,  -891,  -891,  -891,  -891,   401,   377,   409,  -891,
     653,    -7,   153,   402,   428,  -891,  2322,   761,  -891,  -891,
     668,   168,   769,   168,   168,   695,   551,   111,   703,  -891,
    -891,   302,   116,   304,   480,  -891,  -891,  -891,  -891,  -891,
    -891,  -891,  -891,   168,  -891,  -891,   783,   168,   540,   540,
     540,   540,    54,  -891,   146,   540,   146,    96,   496,   748,
    1129,  -891,   577,  -891,  -891,  -891,   168,   168,   791,   168,
     168,  -891,  -891,    96,  -891,  -891,   138,   540,   746,  -891,
    -891,  -891,  -891,  -891,  1352,  1352,  1352,  1352,    70,    70,
     -41,   138,   540,  -891,   500,   512,   533,  -891,   732,  -891,
     526,  -891,   549,  -891,  -891,   627,   633,   638,   624,   649,
     650,  -891,  -891,  -891,   758,   168,   558,  -891,  -891,  -891,
     146,  -891,  -891,  -891,  -891,   563,   168,  -891,  -891,   146,
     573,  -891,   341,  -891,   579,  -891,   595,   659,  -891,   660,
     663,   667,  -891,     7,  -891,  -891,    10,   694,    34,  -891,
    -891,   598,   457,   664,  -891,  -891,  -891,   680,   605,  -891,
    -891,   861,   701,   702,  -891,  -891,  -891,   708,   451,  -891,
     919,   708,   709,  -891,   712,   713,  -891,   -68,   716,   708,
    -891,   717,   718,   708,   708,   726,   727,   728,   730,  2103,
    1211,   733,  2103,   870,  -891,  -891,  -891,   644,   675,  -891,
    -891,  -891,  -891,  -891,  -891,  -891,   451,  -891,   451,  -891,
    -891,   635,  -891,  -891,   -10,  -891,  -891,  -891,  -891,   406,
     786,   168,   212,  -891,   656,  -891,   661,  -891,   678,  -891,
     121,  -891,  -891,   681,  -891,  -891,   698,  -891,  1880,  1434,
    -891,   125,  -891,  -891,   126,   684,   684,   168,  -891,  -891,
     150,     4,   686,   742,  -891,   748,  1129,  -891,   681,   671,
     168,   168,   761,  -891,   168,   798,    96,    96,    96,   162,
     758,    96,  1129,   168,  -891,   188,   168,   190,  -891,  -891,
    -891,   754,   756,   759,   451,   451,  -891,   763,  -891,   765,
     766,   767,   770,   772,  -891,  -891,  -891,  -891,   773,   777,
     516,  -891,  -891,  -891,  -891,  -891,   194,  -891,  -891,   195,
     168,  -891,   168,   812,   168,   168,   168,   168,   806,   146,
     113,  -891,  -891,    96,    77,   954,   168,  -891,    92,   855,
    -891,  1575,   168,   940,  1880,  1880,   768,  -891,  -891,  -891,
    -891,  -891,  -891,  -891,  -891,  -891,   704,    92,   -20,   690,
    -891,  2021,    61,  1880,  1880,  1129,   -66,  -891,  1880,  -891,
    1880,  1880,  -891,  -891,    61,  1880,    61,    61,   406,  -891,
      61,   406,  -891,  1129,  1129,   705,   -27,  2103,  -891,  2103,
    2103,  -891,  2103,  -891,   784,  1657,  -891,  -891,  2103,  -891,
     785,  -891,  2103,   356,  1880,    58,    48,  1880,  -891,  -891,
    -891,  -891,  -891,  -891,  1880,  1880,  1880,  1880,  -891,   563,
     204,  -891,   715,  -891,  -891,  -891,   168,   168,   821,  -891,
      96,   138,   138,   734,  -891,    60,   803,  -891,  1352,  -891,
    -891,   782,    70,    93,  -891,    70,  1352,  -891,   644,   138,
     719,  -891,  -891,  -891,   721,  -891,   809,   736,  -891,   211,
    -891,   245,  -891,   624,  -891,   259,   644,   814,  -891,  -891,
    -891,  -891,   146,   978,   978,   979,   722,    -9,   981,   982,
     983,   984,   981,   981,   985,   986,  -891,  -891,  -891,    86,
    -891,   455,  -891,   168,  -891,   146,  -891,  -891,   735,  -891,
     275,  -891,   147,   291,   295,   306,  -891,   113,  -891,   987,
    -891,  -891,   988,   991,  -891,   113,  -891,  -891,  -891,   810,
     -36,   739,    -7,  -891,  -891,  -891,  -891,   307,   744,  -891,
     331,   354,   452,    -7,  -891,  -891,   415,   760,   836,   762,
    -891,  -891,  -891,  1880,   357,  -891,   -59,  -891,  -891,   359,
     371,   385,  1880,   407,  1880,  1880,  1880,   675,  -891,   452,
    1001,   452,   825,   406,   826,   827,   825,    90,  -891,  -891,
    -891,   826,    90,  -891,   827,  -891,  -891,  1880,  -891,  -891,
      58,  -891,  -891,   260,  1006,  -891,  -891,   182,  -891,  -891,
    -891,  -891,  -891,  -891,  -891,   168,   168,   831,  -891,  -891,
     755,  -891,  -891,  -891,   681,  1880,  -891,   168,  -891,  -891,
     832,  -891,  -891,   218,  -891,  -891,    56,   168,   168,   874,
      96,  -891,    96,  -891,   758,  -891,  -891,  -891,  -891,   848,
     849,   424,   452,  1013,   452,  -891,   774,   852,   425,   853,
     854,   774,   856,   857,  -891,  -891,  -891,  -891,   540,  -891,
    -891,  -891,   842,  -891,  -891,   455,  -891,   758,  -891,  -891,
     168,    43,   168,  -891,  -891,    43,    43,    43,   806,  -891,
    -891,  -891,  -891,  -891,  -891,  -891,  1021,   168,  1880,  -891,
    1880,   168,  -891,  -891,   851,  -891,  -891,  -891,  -891,  -891,
    -891,  -891,  1880,   451,   776,   451,  -891,   451,   865,  -891,
    1880,  -891,  -891,  -891,   867,  -891,   868,   869,   872,  -891,
     873,  -891,    86,  -891,    86,  -891,    86,  -891,  -891,    69,
    -891,   437,  -891,  -891,  -891,   445,  -891,   804,    83,  -891,
    -891,  -891,    58,  -891,  -891,  -891,    58,  -891,    58,   168,
    -891,  -891,  1798,   168,  -891,   818,  -891,  1352,   168,  -891,
    -891,   688,  -891,  -891,  -891,  -891,  -891,  -891,  -891,  -891,
    -891,  -891,  1040,  -891,   878,  -891,  1042,   880,  -891,  -891,
    1044,  -891,  -891,   883,  -891,  -891,  -891,   871,  1129,  -891,
    -891,  -891,  -891,  -891,   991,  1048,  -891,    43,  -891,  -891,
    -891,  -891,  -891,  -891,   877,   810,    59,  -891,   863,  1051,
      59,   794,   452,   795,   797,  -891,  -891,  -891,  -891,  -891,
    -891,   799,  -891,  -891,  -891,  -891,  -891,  -891,  -891,   110,
    -891,  1880,  -891,   135,   560,   373,   876,  -891,   446,  -891,
    -891,  -891,   540,   345,   847,   447,   810,  -891,   896,   808,
    -891,  -891,  -891,   898,  -891,    96,   904,  -891,  -891,  -891,
    -891,  -891,  -891,    58,   905,   906,   452,   907,   452,   452,
     452,  -891,  -891,  -891,  -891,    58,    58,  -891,  1798,    71,
    -891,    76,    67,  1129,  1129,  -891,   261,  -891,  -891,   892,
     101,   -13,  -891,  -891,  -891,   452,  -891,   454,  -891,   429,
    -891,  -891,  -891,  -891,  -891,  -891,   216,   640,  -891,   102,
     102,   131,   168,  -891,  -891,  -891,    52,  -891,  -891,  -891,
     834,  -891,   822,   513,   644,   644,  -891,  -891,  -891,  -891,
    -891,   884,   168,   824,   931,  -891,  -891,  -891,  -891,    58,
    -891,  -891,    58,   540,    71,   829,   830,   145,  -891,  -891,
    -891,    67,    94,  -891,    92,  -891,   952,  -891,    72,   168,
     491,   621,    79,  1129,  1129,   540,  -891,  -891,  -891,   810,
      -7,  -891,  -891,  -891,  -891,   841,  -891,   267,   952,  -891,
    -891,  -891,   644,   644,   108,  -891,  1880,    72,  -891,  -891,
    -891,  -891,  -891,    59,  -891,   847,  -891
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -891,  -891,  -891,  -891,  -891,  -891,  -178,   699,   510,  -891,
    -195,  -241,  -891,  -891,  -891,  -891,   453,  -891,   448,   177,
    -421,  -891,   175,   440,  -891,   296,    -3,   214,   305,   903,
    -129,  -891,  -891,   828,  -891,  -246,  -891,  -891,  -891,  -242,
    -891,  -891,  -207,  -891,  -891,  -891,  -891,  -374,  -891,   850,
     691,  -891,  -891,  -891,  -891,  -891,  -891,  -891,   379,  -891,
     112,  -891,  -891,  -891,  -891,  -891,  -891,  -891,  -891,  -891,
    1055,  -891,  1057,  -891,   891,   970,  -891,  -180,   553,  -891,
    -891,  -891,  -891,  -891,  -891,   363,  -891,  -891,   140,  -891,
    -200,  -126,  -891,  -891,  -891,  -891,  -891,   332,  -891,  -891,
    -891,  -891,  -891,    47,   107,  -891,  -891,  -853,    88,  -869,
    -794,  -891,   114,  -182,   608,   609,   796,  -891,   431,   420,
     427,   325,  -428,  -891,  -891,  -891,  -891,   232,  -891,   576,
    -891,  -891,  -891,   367,  -891,   527,   105,  -891,    -5,  -370,
    -170,  -890,    98,   858,   109,  -571,  -891,  -301,  -546,  -891,
    -891,   929,   584,  -891,  -891,  -891,  -891,  -891,  -891,  -891,
    -891,  -891,  -891,    35,  -891,  -891,  -891,  -891,    80,   235,
    -891,  -891,  -891,  -891,  -891,  -891,    39,  -891,    78,   793,
    -190,  -433,  -603,  -753,   426,    42,  -891,  -891,   666,   410,
    -891,  -891,  -891,   462,   210,   -42,  -891,    53,  -891,   743,
      -4,   779,   316,  -891,  -891,  -891,  -891,  -891,  1016,  -891,
    1155,  -891,  -891,  -891,   778,  -891,  -471,  -891,  -891,  -633,
    -891,  -891,  -891,   -43,  -891,  -891
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -563
static const yytype_int16 yytable[] =
{
      85,   126,    89,    90,    91,    89,    89,    94,    97,    98,
      98,    89,    97,    97,    97,    97,   110,   111,   337,   112,
     669,   574,    89,   448,   447,    89,    89,   289,    89,    89,
     384,   385,   386,    89,    89,   652,   594,    97,    89,   128,
     254,   130,    89,   371,   270,   515,    89,   516,   775,   808,
     388,   398,    84,   418,   663,   926,    84,   199,   125,    87,
     822,   709,    92,    93,    84,   284,   395,   284,   102,   930,
    1035,    84,   946,   125,    84,  1093,    84,   858,   125,   113,
      84,    84,   116,   117,   299,   118,   119,   912,   913,   296,
     120,   121,   774,   296,    84,   124,   298,    84,    84,   131,
      84,   299,   125,   152,  1029,   299,    84,   300,    86,   999,
     301,  1030,  1029,   296,    84,    84,   298,   477,    89,  1030,
      84,   490,   410,   606,   607,   299,   850,   300,   488,   499,
     301,   850,   982,   502,   503,    84,   985,    86,  1052,   805,
     270,  1029,    84,   839,   107,   841,   664,   220,  1030,    84,
      84,    86,   690,   235,   494,   193,   494,   239,   241,   242,
     243,   880,  1068,   258,   495,   200,   495,   265,   268,   265,
     763,   830,    84,   458,   396,   202,   460,    37,   639,   273,
     535,   114,   275,   276,    89,    89,    89,    89,  1094,   221,
     265,    89,   265,   292,   465,   640,   641,   677,  1086,  1053,
     462,   513,   363,   365,   367,   368,   130,   806,   591,   292,
    1082,   595,   111,    89,   578,   670,   893,  1094,   895,   224,
     225,   226,   227,   228,   391,   391,   853,   111,    89,   953,
     222,   853,  1104,   954,   691,   955,   588,   710,   642,   282,
     513,   278,   278,   278,   278,  1101,    48,   536,   285,   952,
     459,   258,   764,   459,   308,  1048,   265,   671,   308,   715,
      51,   573,   268,   161,   155,   265,   383,   383,   383,   383,
     376,   943,   245,   943,  1112,   943,   246,   463,   308,   804,
     156,  1063,   962,   292,   487,   399,   508,   559,   648,   511,
     255,   567,   569,   647,   860,   266,   150,  1049,   672,   561,
     247,   914,   735,   861,   742,  1088,    84,   711,    84,   915,
     993,   881,   712,   676,  1031,   737,   571,   716,   160,  1115,
    1036,  1037,  1031,   387,  1085,  1036,   333,   739,   592,   372,
     638,  1032,   863,   864,   698,   745,  1037,   865,  1050,   849,
     703,  1037,   249,   333,  1067,   165,   860,   333,   250,   287,
    1019,  1031,   489,  1113,   599,   861,   601,   552,   188,   849,
     622,   624,  1026,  1027,   560,   824,   793,   333,   568,   568,
     724,   643,   868,   879,   920,   921,   922,   751,   850,   789,
     888,   788,   734,   391,   863,   864,   987,   794,   229,   865,
     732,  1060,   189,   572,   741,   757,   580,   581,   235,   746,
     583,   585,   292,   292,   292,   593,   468,   292,   465,   598,
     553,   753,   258,   910,   166,   167,   944,  1002,   945,   190,
     565,   566,   168,   169,   170,   755,  1080,   860,   245,  1081,
     245,   416,   246,   602,   246,   859,   861,   623,   625,   869,
    1022,   791,  1023,  1024,  1025,  1003,   626,   725,   627,   629,
     632,   632,   632,   632,   752,   265,   247,   795,   247,   292,
     649,   796,   651,   203,   537,   863,   864,   754,   658,  1056,
     865,   860,   797,   809,   693,   878,   693,   693,   853,   693,
     861,   260,   204,   269,   705,   693,  1108,  1106,   752,   693,
     538,   539,   540,   541,   542,   543,   270,   812,   249,   183,
     249,  1002,   752,   862,   250,   191,   250,  1109,   135,   863,
     864,   157,   158,   656,   865,   194,   656,   656,   792,   706,
     813,   707,   931,   829,   933,   831,   934,   195,   171,  1003,
     162,   196,   717,   667,   792,   656,   675,   832,   792,   197,
     656,   163,   656,   656,    84,   164,    86,   656,   994,   792,
     810,   833,   365,   729,   731,   981,   292,   111,   111,   136,
    1004,   738,   172,   776,   210,   137,   206,   700,   391,   743,
     478,   391,   207,   835,   810,   111,   708,   173,   138,   718,
     886,   211,   887,   139,   860,   777,   719,   720,   721,   722,
     891,   899,   140,   861,   778,   141,  1013,   810,   265,   142,
     810,   479,   810,   948,  1058,   143,   478,   814,   480,   779,
     383,   950,   997,  1012,   810,   780,   995,   544,   383,   268,
    1057,   265,   863,   864,   216,   481,   545,   865,   810,   279,
     280,   281,   616,   617,   618,   144,   217,   479,   815,   482,
     860,  1090,   419,   145,   480,   816,   213,   465,   483,   861,
     810,   781,   218,   186,   208,   546,   219,   782,   823,   484,
     547,   481,   817,   231,   187,   209,  1099,   892,   900,   633,
     634,   635,  1059,  1073,   238,   482,   818,   245,   863,   864,
     949,   246,   965,   865,   483,   819,   619,   232,   949,   998,
     568,    84,    84,    95,   107,   484,   820,   750,    84,   208,
     125,   244,   860,   465,   420,   247,   259,   421,   422,   423,
     209,   861,   184,   185,   466,   828,   424,   770,   771,  1105,
     425,   552,   871,   272,   834,   426,   836,   837,   838,   132,
     248,   133,   427,   876,   428,   429,   682,   430,   684,   685,
     863,   864,   686,   883,   884,   865,   292,   249,   292,   857,
     245,   293,   294,   250,   246,   208,   361,   400,   431,   103,
     104,   105,   106,  -282,   517,    84,   209,   234,   432,   401,
    -525,   860,   433,    84,    89,   240,   402,   565,   247,   434,
     861,   435,   403,   404,   123,   518,   911,    84,   632,   274,
     436,   405,   437,   519,   520,    84,  1100,   366,  -282,   521,
    -282,   416,    84,   925,   584,   588,   406,   928,   522,   863,
     864,   523,   407,   524,   865,  1061,    84,   408,   628,   517,
     249,  1044,  1045,   525,   526,    84,   250,   730,   411,   412,
     438,   907,   860,   439,   413,   450,   452,   453,   454,   455,
     518,   861,   456,   527,   694,   695,   457,   696,   519,   520,
     565,   860,   927,   701,   521,   464,   665,   704,   468,   471,
     861,   528,   472,   522,   565,   956,   523,   473,   524,   961,
     863,   864,   936,   512,   966,   865,   967,   111,   525,   526,
     474,   475,   549,  1062,   660,   661,   529,   476,   491,   863,
     864,   492,   493,   530,   865,   498,   500,   501,   527,   531,
     532,  1102,  1103,   674,   513,   504,   505,   506,   679,   507,
     680,   681,   510,   514,   960,   683,   528,   556,   557,   383,
     558,   562,   296,   297,   561,   298,   138,   568,  -305,   575,
     576,   139,   579,   603,   299,   604,   300,   636,   605,   301,
     140,   529,   608,   141,   609,   610,   611,   142,   530,   612,
    -305,   613,   614,   143,   531,   532,   615,   650,    89,   653,
    1042,   659,   487,   697,   702,   662,   689,   302,   303,   665,
     740,   292,   726,   304,   305,   749,   747,   735,   748,   750,
     756,   758,   761,   762,   765,   767,   768,   769,   772,   773,
     799,   800,   790,   992,  1042,   801,   807,  1034,  1043,   306,
     465,   811,   826,   825,   840,   827,   842,   844,   846,   867,
     872,   877,   873,   778,   889,   890,   894,   896,   898,   901,
     902,   908,   904,   905,   924,    89,    89,    89,  1034,  1042,
     929,   935,  1043,   937,   938,   939,  1042,   932,   940,   941,
     960,   962,   951,   968,   969,   970,   972,   973,  1077,   974,
     975,   978,   980,   983,   984,   986,   988,   307,   989,    89,
     990,  1010,  1014,    89,  1016,  1042,   996,  1043,  1089,  1015,
    1018,  1020,  1021,  -504,  1043,  1077,  1003,  1071,  1074,  1072,
    1078,    89,  1079,  1091,  1107,   744,   570,   308,  1083,  1084,
     798,   977,   979,   803,   923,  1111,   309,   919,   310,   286,
     451,   311,   312,  1043,   870,   415,   153,   600,   154,   377,
    1028,   215,   885,   487,   733,  1017,  1047,   909,  1066,   313,
    1046,   687,   314,   688,   856,   723,   509,   848,   854,   315,
     316,   760,   296,   297,  1070,   298,   317,   318,   903,   369,
     728,  1069,  1114,   976,   299,   461,   300,   319,   565,   301,
     320,  1087,   321,   322,  1116,   555,   323,  1098,   324,   991,
     325,   874,   678,   326,   855,   947,   327,   328,   329,   101,
     330,   331,   233,   332,   577,     0,   333,   302,   303,     0,
     582,     0,     0,   304,   305,     0,   334,   335,   336,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   306,
       0,     0,     0,     0,   296,   297,     0,   298,     0,     0,
       0,     0,     0,     0,     0,     0,   299,     0,   300,     0,
       0,   301,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   302,
     303,     0,     0,     0,     0,   304,   305,   307,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   306,     0,     0,     0,     0,     0,   308,     0,     0,
       0,     0,     0,     0,     0,     0,   309,     0,   310,     0,
       0,   311,   312,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   313,
       0,     0,   314,     0,     0,     0,     0,     0,     0,   315,
     316,     0,     0,     0,     0,     0,   317,   318,     0,   307,
       0,     0,     0,     0,     0,   296,   297,   319,   298,     0,
     320,     0,   321,   322,     0,     0,   323,   299,   324,   300,
     325,     0,   301,   326,     0,     0,   327,   328,   329,   308,
     330,   331,     0,   332,     0,     0,   333,     0,   309,     0,
     310,     0,     0,   311,   312,     0,   334,   335,   336,     0,
     302,   303,     0,     0,     0,     0,   304,   305,     0,     0,
       0,   313,     0,     0,   314,     0,     0,     0,     0,     0,
       0,   315,   316,     0,     0,     0,     0,     0,   317,   318,
       0,     0,   306,     0,     0,     0,     0,   296,   297,   319,
     298,     0,   320,     0,   321,   322,     0,     0,   323,   299,
     324,   300,   325,     0,   301,   326,     0,     0,   327,   328,
     329,     0,     0,   331,     0,   332,     0,     0,   333,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   334,   335,
     336,     0,   302,   303,     0,     0,     0,     0,   304,   305,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   306,     0,     0,     0,     0,     0,
     308,     0,     0,     0,     0,     0,     0,     0,     0,   309,
       0,   379,     0,     0,     0,   312,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   380,   313,     0,     0,   314,     0,     0,     0,     0,
       0,     0,   315,   316,     0,     0,     0,     0,     0,   317,
     318,     0,     0,     0,     0,     0,     0,     0,   296,   297,
     319,   298,     0,   320,     0,   321,   322,     0,     0,   323,
     299,   324,   300,   325,     0,   301,   326,     0,     0,   327,
     328,   329,   308,     0,   331,     0,   332,     0,     0,   333,
       0,   309,     0,   379,     0,     0,     0,   312,     0,   334,
     335,   336,     0,   302,   303,     0,     0,     0,   487,   304,
     305,     0,     0,     0,   313,     0,     0,   314,     0,     0,
       0,     0,     0,     0,   315,   316,     0,     0,     0,     0,
       0,   317,   318,     0,     0,   306,     0,     0,     0,     0,
     296,   297,   319,   298,     0,   320,     0,   321,   322,     0,
       0,   323,   299,   324,   300,   325,     0,   301,   326,     0,
       0,   327,   328,   329,     0,     0,   331,     0,   332,     0,
       0,   333,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   334,   335,   336,     0,   302,   303,     0,     0,     0,
       0,   304,   305,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   306,     0,     0,
       0,   655,     0,   308,     0,     0,     0,     0,     0,     0,
       0,     0,   309,     0,   379,     0,     0,     0,   312,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   313,     0,     0,   314,     0,
       0,     0,     0,     0,     0,   315,   316,     0,     0,     0,
       0,     0,   317,   318,     0,     0,     0,     0,     0,     0,
       0,   296,   297,   319,   298,     0,   320,     0,   321,   322,
       0,     0,   323,   299,   324,   300,   325,     0,   301,   326,
       0,     0,   327,   328,   329,   308,     0,   331,     0,   332,
       0,     0,   333,     0,   309,     0,   379,     0,     0,     0,
     312,     0,   334,   335,   336,     0,   302,   303,     0,     0,
       0,     0,   304,   305,     0,     0,   699,   313,     0,     0,
     314,     0,     0,     0,     0,     0,     0,   315,   316,     0,
       0,     0,     0,     0,   317,   318,     0,     0,   306,     0,
       0,     0,     0,   296,   297,   319,   298,     0,   320,     0,
     321,   322,     0,     0,   323,   299,   324,   300,   325,     0,
     301,   326,     0,     0,   327,   328,   329,     0,     0,   331,
       0,   332,     0,     0,   333,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   334,   335,   336,     0,   302,   303,
       0,     0,     0,     0,   304,   305,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     306,     0,     0,     0,     0,     0,   308,     0,     0,     0,
       0,     0,     0,     0,     0,   309,     0,   379,     0,     0,
       0,   312,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   957,   313,     0,
       0,   314,     0,     0,     0,     0,     0,     0,   315,   316,
       0,     0,     0,     0,     0,   317,   318,     0,     0,     0,
       0,     0,     0,     0,   296,   297,   319,   298,     0,   320,
       0,   321,   322,     0,     0,   323,   299,   324,   300,   325,
       0,   301,   326,     0,     0,   327,   328,   329,   308,     0,
     331,     0,   332,     0,     0,   333,     0,   309,     0,   379,
       0,     0,     0,   312,     0,   334,   335,   336,     0,   302,
     303,     0,     0,     0,     0,   304,   305,     0,     0,     0,
     313,     0,     0,   314,     0,     0,     0,     0,     0,     0,
     315,   316,     0,     0,     0,     0,     0,   317,   318,     0,
       0,   306,     0,     0,     0,     0,   296,   297,   319,   298,
       0,   320,     0,   321,   322,     0,     0,   323,   299,   324,
     300,   325,     0,   301,   326,     0,     0,   327,   328,   329,
       0,     0,   331,     0,   332,     0,     0,   333,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   334,   335,   336,
       0,   302,   303,     0,     0,     0,     0,   304,   305,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   306,     0,     0,     0,     0,     0,   666,
       0,     0,     0,     0,     0,     0,     0,     0,   309,     0,
     379,     0,     0,     0,   312,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   313,     0,     0,   314,     0,     0,     0,     0,     0,
       0,   315,   316,     0,     0,     0,     0,     0,   317,   318,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   319,
       0,     0,   320,     0,   321,   322,     0,     0,   323,     0,
     324,     0,   325,     0,     0,   326,     0,     0,   327,   328,
     329,   308,     0,   331,     0,   332,     0,     0,   333,     0,
     309,     0,   379,     0,     0,     0,   312,     0,   334,   335,
     336,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   313,     0,     0,   314,     0,     0,     0,
       0,     0,     0,   315,   316,     0,     0,     0,     0,     0,
     317,   318,  -562,     1,     0,     0,     0,     0,     0,     0,
       0,   319,     0,     0,   320,     0,   321,   322,  -562,     0,
     323,     0,   324,     0,   325,     0,     0,   326,     0,     0,
     327,   328,     0,     0,     0,   331,     0,     0,     0,     0,
     333,     0,     0,     0,     0,     0,     0,     0,     2,     3,
     334,   335,   336,     4,     0,     5,     0,     0,     6,     7,
       0,     8,     9,    10,     0,    11,    12,     0,     0,     0,
       0,     0,     0,    13,    14,     0,     0,    15,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    16,    17,    18,    19,     0,    20,
      21,    22,    23,    24,    25,    26,     0,     0,    27,     0,
       0,    28,     0,    29,    30,     0,    31,    32,     0,     0,
       0,    33,    34,    35,    36,    37,    38,     0,     0,    39,
       0,     0,     0,     0,     0,    40,    41,     0,     0,    42,
       0,     0,    43,     0,    44,    45,     0,     0,     0,     0,
      46,     0,     0,     0,    47,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    48,     0,    49,     0,     0,    50,
       0,     0,     0,     0,     0,     0,     0,     0,    51
};

static const yytype_int16 yycheck[] =
{
       4,    43,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    21,    21,   200,    23,
     491,   391,    26,   269,   266,    29,    30,   197,    32,    33,
     225,   226,   227,    37,    38,   468,   410,    41,    42,    43,
     166,    45,    46,   213,   173,   346,    50,   348,   619,   652,
     228,   231,     4,   260,   487,   808,     4,   107,     6,     6,
     663,     3,     9,    10,     4,   194,   107,   196,    15,   822,
       3,     4,     3,     6,     4,     3,     4,   710,     6,    26,
       4,     4,    29,    30,    15,    32,    33,    44,    45,     3,
      37,    38,     6,     3,     4,    42,     6,     4,     4,    46,
       4,    15,     6,    50,    33,    15,     4,    17,     6,   962,
      20,    40,    33,     3,     4,     4,     6,   307,   122,    40,
       4,   311,   248,   424,   425,    15,   697,    17,   310,   319,
      20,   702,   926,   323,   324,     4,   930,     6,   151,   175,
     269,    33,     4,   689,     6,   691,   166,   154,    40,     4,
       4,     6,   179,   157,   222,   108,   222,   161,   162,   163,
     164,   105,  1031,   167,   232,   215,   232,   171,   172,   173,
     179,   230,     4,   166,   215,   122,   166,   123,    65,   183,
     190,     3,   186,   187,   188,   189,   190,   191,  1078,   196,
     194,   195,   196,   197,   190,    82,    83,   263,  1067,   212,
     166,   260,   206,   207,   208,   209,   210,   243,   408,   213,
    1063,   411,   216,   217,   396,   154,   762,  1107,   764,    66,
      67,    68,    69,    70,   228,   229,   697,   231,   232,   862,
     237,   702,  1085,   866,   261,   868,   406,   179,   125,   192,
     260,   188,   189,   190,   191,   166,   192,   257,   195,   166,
     243,   255,   261,   243,   168,   154,   260,   196,   168,   211,
     206,   257,   266,   257,     0,   269,   224,   225,   226,   227,
     217,   842,   126,   844,   166,   846,   130,   243,   168,   649,
      16,   179,   223,   287,   194,   232,   329,   166,   211,   332,
     179,   166,   166,   463,   211,   179,   204,   196,   237,   243,
     154,   258,   243,   220,   211,   211,     4,   249,     4,   266,
     175,   255,   254,   495,   243,   255,   166,   269,    52,  1113,
     253,   269,   243,   253,   179,   253,   257,   568,   166,   191,
     459,   255,   249,   250,   524,   576,   269,   254,   237,   249,
     530,   269,   196,   257,   213,   258,   211,   257,   202,   253,
     983,   243,   310,  1106,   166,   220,   166,   361,   259,   249,
     166,   166,   995,   996,   243,   666,   219,   257,   243,   243,
     166,   258,   190,   743,   795,   796,   797,   166,   949,   625,
     754,   623,   562,   387,   249,   250,   932,   240,   235,   254,
     560,   175,   259,   243,   572,   602,   400,   401,   402,   579,
     404,   405,   406,   407,   408,   243,   194,   411,   190,   413,
     198,   166,   416,   787,    73,    74,   844,   156,   846,   259,
     378,   379,    81,    82,    83,   166,  1059,   211,   126,  1062,
     126,   243,   130,   243,   130,   175,   220,   243,   243,   257,
     986,   166,   988,   989,   990,   184,   450,   243,   452,   453,
     454,   455,   456,   457,   243,   459,   154,   166,   154,   463,
     464,   166,   466,   113,    58,   249,   250,   593,   472,  1015,
     254,   211,   166,   166,   517,   257,   519,   520,   949,   522,
     220,   179,   132,   179,   128,   528,   219,  1090,   243,   532,
      84,    85,    86,    87,    88,    89,   625,   166,   196,   257,
     196,   156,   243,   243,   202,   259,   202,   240,   110,   249,
     250,   135,   136,   471,   254,   179,   474,   475,   243,   163,
     166,   165,   823,   166,   825,   166,   827,   246,   187,   184,
     242,   179,   536,   491,   243,   493,   494,   166,   243,   179,
     498,   253,   500,   501,     4,   257,     6,   505,   175,   243,
     243,   166,   556,   557,   558,   925,   560,   561,   562,   161,
     215,   565,   221,   108,   261,   167,   257,   525,   572,   573,
     155,   575,   257,   166,   243,   579,   534,   236,   180,   537,
     750,   149,   752,   185,   211,   130,   544,   545,   546,   547,
     166,   166,   194,   220,   139,   197,   966,   243,   602,   201,
     243,   186,   243,   166,   175,   207,   155,   155,   193,   154,
     568,   166,   166,   166,   243,   160,   243,   211,   576,   623,
     166,   625,   249,   250,   223,   210,   220,   254,   243,   189,
     190,   191,   116,   117,   118,   237,   259,   186,   186,   224,
     211,  1074,    79,   245,   193,   193,   179,   190,   233,   220,
     243,   196,   243,   242,   242,   249,     3,   202,   243,   244,
     254,   210,   210,   261,   253,   253,   175,   243,   243,   455,
     456,   457,   243,  1043,     6,   224,   224,   126,   249,   250,
     243,   130,   877,   254,   233,   233,   170,   259,   243,   243,
     243,     4,     4,     6,     6,   244,   244,   243,     4,   242,
       6,     6,   211,   190,   141,   154,     3,   144,   145,   146,
     253,   220,    90,    91,   257,   673,   153,   612,   613,  1089,
     157,   725,   726,   243,   682,   162,   684,   685,   686,     4,
     179,     6,   169,   737,   171,   172,   504,   174,   506,   507,
     249,   250,   510,   747,   748,   254,   750,   196,   752,   707,
     126,   255,     4,   202,   130,   242,   179,   257,   195,    16,
      17,    18,    19,   128,   129,     4,   253,     6,   205,   257,
     257,   211,   209,     4,   778,     6,   243,   735,   154,   216,
     220,   218,    50,   257,    41,   150,   790,     4,   792,     6,
     227,   242,   229,   158,   159,     4,   175,     6,   163,   164,
     165,   243,     4,   807,     6,   975,   179,   811,   173,   249,
     250,   176,   179,   178,   254,   175,     4,   179,     6,   129,
     196,  1003,  1004,   188,   189,     4,   202,     6,   179,   179,
     267,   778,   211,   270,    76,   262,   257,   242,   179,   179,
     150,   220,   179,   208,   519,   520,   179,   522,   158,   159,
     808,   211,   810,   528,   164,   257,   166,   532,   194,   179,
     220,   226,   257,   173,   822,   869,   176,     6,   178,   873,
     249,   250,   830,     3,   878,   254,   881,   881,   188,   189,
     179,   179,    96,   243,   474,   475,   251,   179,   179,   249,
     250,   179,   179,   258,   254,   179,   179,   179,   208,   264,
     265,  1083,  1084,   493,   260,   179,   179,   179,   498,   179,
     500,   501,   179,   238,   872,   505,   226,   261,   257,   877,
     242,   223,     3,     4,   243,     6,   180,   243,   238,   243,
     188,   185,   261,   179,    15,   179,    17,   131,   179,    20,
     194,   251,   179,   197,   179,   179,   179,   201,   258,   179,
     260,   179,   179,   207,   264,   265,   179,     3,   962,   104,
    1002,    21,   194,   179,   179,   261,   261,    48,    49,   166,
     188,   975,   257,    54,    55,   166,   257,   243,   257,   243,
     166,     3,     3,   261,     3,     3,     3,     3,     3,     3,
       3,     3,   257,   951,  1036,     4,   257,  1001,  1002,    80,
     190,   257,   166,   243,     3,   243,   181,   181,   181,     3,
     179,   179,   257,   139,   166,   166,     3,   243,   166,   166,
     166,   179,   166,   166,     3,  1029,  1030,  1031,  1032,  1071,
     179,   166,  1036,   166,   166,   166,  1078,   261,   166,   166,
     998,   223,   238,     3,   166,     3,   166,     3,  1052,   166,
     179,     3,   175,   190,     3,   261,   261,   138,   261,  1063,
     261,   214,   166,  1067,   166,  1107,   190,  1071,  1072,   261,
     166,   166,   166,   166,  1078,  1079,   184,   243,   194,   257,
     256,  1085,   151,   131,   243,   575,   387,   168,   259,   259,
     637,   914,   917,   645,   798,  1098,   177,   792,   179,   196,
     272,   182,   183,  1107,   725,   255,    51,   416,    51,   218,
     998,   141,   749,   194,   561,   975,  1009,   785,  1030,   200,
    1006,   513,   203,   514,   704,   549,   330,   696,   701,   210,
     211,   604,     3,     4,  1036,     6,   217,   218,   771,   210,
     556,  1032,  1107,   908,    15,   287,    17,   228,  1106,    20,
     231,  1071,   233,   234,  1115,   362,   237,  1079,   239,   949,
     241,   735,   496,   244,   702,   849,   247,   248,   249,    14,
     251,   252,   156,   254,   395,    -1,   257,    48,    49,    -1,
     402,    -1,    -1,    54,    55,    -1,   267,   268,   269,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    80,
      -1,    -1,    -1,    -1,     3,     4,    -1,     6,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    15,    -1,    17,    -1,
      -1,    20,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    48,
      49,    -1,    -1,    -1,    -1,    54,    55,   138,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    80,    -1,    -1,    -1,    -1,    -1,   168,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   177,    -1,   179,    -1,
      -1,   182,   183,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   200,
      -1,    -1,   203,    -1,    -1,    -1,    -1,    -1,    -1,   210,
     211,    -1,    -1,    -1,    -1,    -1,   217,   218,    -1,   138,
      -1,    -1,    -1,    -1,    -1,     3,     4,   228,     6,    -1,
     231,    -1,   233,   234,    -1,    -1,   237,    15,   239,    17,
     241,    -1,    20,   244,    -1,    -1,   247,   248,   249,   168,
     251,   252,    -1,   254,    -1,    -1,   257,    -1,   177,    -1,
     179,    -1,    -1,   182,   183,    -1,   267,   268,   269,    -1,
      48,    49,    -1,    -1,    -1,    -1,    54,    55,    -1,    -1,
      -1,   200,    -1,    -1,   203,    -1,    -1,    -1,    -1,    -1,
      -1,   210,   211,    -1,    -1,    -1,    -1,    -1,   217,   218,
      -1,    -1,    80,    -1,    -1,    -1,    -1,     3,     4,   228,
       6,    -1,   231,    -1,   233,   234,    -1,    -1,   237,    15,
     239,    17,   241,    -1,    20,   244,    -1,    -1,   247,   248,
     249,    -1,    -1,   252,    -1,   254,    -1,    -1,   257,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   267,   268,
     269,    -1,    48,    49,    -1,    -1,    -1,    -1,    54,    55,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    80,    -1,    -1,    -1,    -1,    -1,
     168,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   177,
      -1,   179,    -1,    -1,    -1,   183,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   199,   200,    -1,    -1,   203,    -1,    -1,    -1,    -1,
      -1,    -1,   210,   211,    -1,    -1,    -1,    -1,    -1,   217,
     218,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     3,     4,
     228,     6,    -1,   231,    -1,   233,   234,    -1,    -1,   237,
      15,   239,    17,   241,    -1,    20,   244,    -1,    -1,   247,
     248,   249,   168,    -1,   252,    -1,   254,    -1,    -1,   257,
      -1,   177,    -1,   179,    -1,    -1,    -1,   183,    -1,   267,
     268,   269,    -1,    48,    49,    -1,    -1,    -1,   194,    54,
      55,    -1,    -1,    -1,   200,    -1,    -1,   203,    -1,    -1,
      -1,    -1,    -1,    -1,   210,   211,    -1,    -1,    -1,    -1,
      -1,   217,   218,    -1,    -1,    80,    -1,    -1,    -1,    -1,
       3,     4,   228,     6,    -1,   231,    -1,   233,   234,    -1,
      -1,   237,    15,   239,    17,   241,    -1,    20,   244,    -1,
      -1,   247,   248,   249,    -1,    -1,   252,    -1,   254,    -1,
      -1,   257,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   267,   268,   269,    -1,    48,    49,    -1,    -1,    -1,
      -1,    54,    55,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    80,    -1,    -1,
      -1,   166,    -1,   168,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   177,    -1,   179,    -1,    -1,    -1,   183,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   200,    -1,    -1,   203,    -1,
      -1,    -1,    -1,    -1,    -1,   210,   211,    -1,    -1,    -1,
      -1,    -1,   217,   218,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,     3,     4,   228,     6,    -1,   231,    -1,   233,   234,
      -1,    -1,   237,    15,   239,    17,   241,    -1,    20,   244,
      -1,    -1,   247,   248,   249,   168,    -1,   252,    -1,   254,
      -1,    -1,   257,    -1,   177,    -1,   179,    -1,    -1,    -1,
     183,    -1,   267,   268,   269,    -1,    48,    49,    -1,    -1,
      -1,    -1,    54,    55,    -1,    -1,   199,   200,    -1,    -1,
     203,    -1,    -1,    -1,    -1,    -1,    -1,   210,   211,    -1,
      -1,    -1,    -1,    -1,   217,   218,    -1,    -1,    80,    -1,
      -1,    -1,    -1,     3,     4,   228,     6,    -1,   231,    -1,
     233,   234,    -1,    -1,   237,    15,   239,    17,   241,    -1,
      20,   244,    -1,    -1,   247,   248,   249,    -1,    -1,   252,
      -1,   254,    -1,    -1,   257,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   267,   268,   269,    -1,    48,    49,
      -1,    -1,    -1,    -1,    54,    55,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      80,    -1,    -1,    -1,    -1,    -1,   168,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   177,    -1,   179,    -1,    -1,
      -1,   183,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   199,   200,    -1,
      -1,   203,    -1,    -1,    -1,    -1,    -1,    -1,   210,   211,
      -1,    -1,    -1,    -1,    -1,   217,   218,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,     3,     4,   228,     6,    -1,   231,
      -1,   233,   234,    -1,    -1,   237,    15,   239,    17,   241,
      -1,    20,   244,    -1,    -1,   247,   248,   249,   168,    -1,
     252,    -1,   254,    -1,    -1,   257,    -1,   177,    -1,   179,
      -1,    -1,    -1,   183,    -1,   267,   268,   269,    -1,    48,
      49,    -1,    -1,    -1,    -1,    54,    55,    -1,    -1,    -1,
     200,    -1,    -1,   203,    -1,    -1,    -1,    -1,    -1,    -1,
     210,   211,    -1,    -1,    -1,    -1,    -1,   217,   218,    -1,
      -1,    80,    -1,    -1,    -1,    -1,     3,     4,   228,     6,
      -1,   231,    -1,   233,   234,    -1,    -1,   237,    15,   239,
      17,   241,    -1,    20,   244,    -1,    -1,   247,   248,   249,
      -1,    -1,   252,    -1,   254,    -1,    -1,   257,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   267,   268,   269,
      -1,    48,    49,    -1,    -1,    -1,    -1,    54,    55,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    80,    -1,    -1,    -1,    -1,    -1,   168,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   177,    -1,
     179,    -1,    -1,    -1,   183,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   200,    -1,    -1,   203,    -1,    -1,    -1,    -1,    -1,
      -1,   210,   211,    -1,    -1,    -1,    -1,    -1,   217,   218,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   228,
      -1,    -1,   231,    -1,   233,   234,    -1,    -1,   237,    -1,
     239,    -1,   241,    -1,    -1,   244,    -1,    -1,   247,   248,
     249,   168,    -1,   252,    -1,   254,    -1,    -1,   257,    -1,
     177,    -1,   179,    -1,    -1,    -1,   183,    -1,   267,   268,
     269,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   200,    -1,    -1,   203,    -1,    -1,    -1,
      -1,    -1,    -1,   210,   211,    -1,    -1,    -1,    -1,    -1,
     217,   218,     0,     1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   228,    -1,    -1,   231,    -1,   233,   234,    16,    -1,
     237,    -1,   239,    -1,   241,    -1,    -1,   244,    -1,    -1,
     247,   248,    -1,    -1,    -1,   252,    -1,    -1,    -1,    -1,
     257,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    46,    47,
     267,   268,   269,    51,    -1,    53,    -1,    -1,    56,    57,
      -1,    59,    60,    61,    -1,    63,    64,    -1,    -1,    -1,
      -1,    -1,    -1,    71,    72,    -1,    -1,    75,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    92,    93,    94,    95,    -1,    97,
      98,    99,   100,   101,   102,   103,    -1,    -1,   106,    -1,
      -1,   109,    -1,   111,   112,    -1,   114,   115,    -1,    -1,
      -1,   119,   120,   121,   122,   123,   124,    -1,    -1,   127,
      -1,    -1,    -1,    -1,    -1,   133,   134,    -1,    -1,   137,
      -1,    -1,   140,    -1,   142,   143,    -1,    -1,    -1,    -1,
     148,    -1,    -1,    -1,   152,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   192,    -1,   194,    -1,    -1,   197,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   206
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
{
       0,     1,    46,    47,    51,    53,    56,    57,    59,    60,
      61,    63,    64,    71,    72,    75,    92,    93,    94,    95,
      97,    98,    99,   100,   101,   102,   103,   106,   109,   111,
     112,   114,   115,   119,   120,   121,   122,   123,   124,   127,
     133,   134,   137,   140,   142,   143,   148,   152,   192,   194,
     197,   206,   281,   292,   293,   294,   295,   304,   311,   331,
     332,   341,   342,   343,   345,   346,   347,   348,   349,   359,
     379,   383,   429,   430,   433,   434,   452,   486,   487,   488,
     489,   491,   495,   497,     4,   480,     6,   477,   478,   480,
     480,   480,   477,   477,   480,     6,   479,   480,   480,   485,
     490,   490,   477,   479,   479,   479,   479,     6,   380,   381,
     418,   480,   480,   477,     3,   505,   477,   477,   477,   477,
     477,   477,   333,   479,   477,     6,   475,   476,   480,   431,
     480,   477,     4,     6,   483,   110,   161,   167,   180,   185,
     194,   197,   201,   207,   237,   245,   350,   352,   353,   354,
     204,   461,   477,   350,   352,     0,    16,   135,   136,   492,
      52,   257,   242,   253,   257,   258,    73,    74,    81,    82,
      83,   187,   221,   236,   312,   313,   314,   317,   320,   323,
     324,   325,   328,   257,    90,    91,   242,   253,   259,   259,
     259,   259,   382,   383,   179,   246,   179,   179,   360,   107,
     215,   283,   477,   113,   132,   435,   257,   257,   242,   253,
     261,   149,   344,   179,   355,   355,   223,   259,   243,     3,
     154,   196,   237,   462,    66,    67,    68,    69,    70,   235,
     284,   261,   259,   488,     6,   480,   493,   494,     6,   480,
       6,   480,   480,   480,     6,   126,   130,   154,   179,   196,
     202,   363,   364,   369,   371,   179,   329,   330,   480,     3,
     179,   310,   322,   371,   373,   480,   179,   319,   480,   179,
     310,   315,   243,   480,     6,   480,   480,   303,   477,   303,
     303,   303,   383,   309,   310,   477,   309,   253,   361,   420,
     423,   475,   480,   255,     4,   481,     3,     4,     6,    15,
      17,    20,    48,    49,    54,    55,    80,   138,   168,   177,
     179,   182,   183,   200,   203,   210,   211,   217,   218,   228,
     231,   233,   234,   237,   239,   241,   244,   247,   248,   249,
     251,   252,   254,   257,   267,   268,   269,   393,   394,   395,
     396,   397,   404,   406,   425,   436,   437,   438,   439,   440,
     460,   465,   466,   472,   480,   482,   496,   498,   502,   503,
     504,   179,   336,   480,   432,   480,     6,   480,   480,   431,
     356,   420,   191,   357,   358,   418,   477,   354,   453,   179,
     199,   290,   291,   465,   290,   290,   290,   253,   286,   287,
     289,   480,   285,   286,   288,   107,   215,   282,   357,   477,
     257,   257,   243,    50,   257,   242,   179,   179,   179,   326,
     371,   179,   179,    76,   327,   329,   243,   321,   322,    79,
     141,   144,   145,   146,   153,   157,   162,   169,   171,   172,
     174,   195,   205,   209,   216,   218,   227,   229,   267,   270,
     409,   410,   411,   412,   414,   451,   318,   319,   315,   316,
     262,   313,   257,   242,   179,   179,   179,   179,   166,   243,
     166,   423,   166,   243,   257,   190,   257,   419,   194,   450,
     459,   179,   257,     6,   179,   179,   179,   460,   155,   186,
     193,   210,   224,   233,   244,   426,   427,   194,   393,   465,
     460,   179,   179,   179,   222,   232,   467,   468,   179,   460,
     179,   179,   460,   460,   179,   179,   179,   179,   503,   396,
     179,   503,     3,   260,   238,   427,   427,   129,   150,   158,
     159,   164,   173,   176,   178,   188,   189,   208,   226,   251,
     258,   264,   265,   403,   405,   190,   257,    58,    84,    85,
      86,    87,    88,    89,   211,   220,   249,   254,   471,    96,
     337,   338,   480,   198,   334,   459,   261,   257,   242,   166,
     243,   243,   223,   463,   464,   465,   465,   166,   243,   166,
     287,   166,   243,   257,   419,   243,   188,   481,   393,   261,
     480,   480,   494,   480,     6,   480,   366,   368,   420,   370,
     420,   370,   166,   243,   327,   370,   393,   449,   480,   166,
     330,   166,   243,   179,   179,   179,   427,   427,   179,   179,
     179,   179,   179,   179,   179,   179,   116,   117,   118,   170,
     372,   374,   166,   243,   166,   243,   480,   480,     6,   480,
     307,   308,   480,   307,   307,   307,   131,   305,   310,    65,
      82,    83,   125,   258,   296,   297,   298,   420,   211,   480,
       3,   480,   461,   104,   362,   166,   465,   469,   480,    21,
     469,   469,   261,   461,   166,   166,   168,   465,   470,   496,
     154,   196,   237,   407,   469,   465,   393,   263,   468,   469,
     469,   469,   407,   469,   407,   407,   407,   394,   395,   261,
     179,   261,   401,   503,   401,   401,   401,   179,   460,   199,
     465,   401,   179,   460,   401,   128,   163,   165,   465,     3,
     179,   249,   254,   499,   501,   211,   269,   480,   465,   465,
     465,   465,   465,   409,   166,   243,   257,   335,   432,   480,
       6,   480,   420,   358,   357,   243,   454,   255,   480,   291,
     188,   286,   211,   480,   288,   291,   357,   257,   257,   166,
     243,   166,   243,   166,   371,   166,   166,   322,     3,   415,
     415,     3,   261,   179,   261,     3,   416,     3,     3,     3,
     416,   416,     3,     3,     6,   425,   108,   130,   139,   154,
     160,   196,   202,   365,   375,   376,   377,   378,   319,   315,
     257,   166,   243,   219,   240,   166,   166,   166,   296,     3,
       3,     4,   299,   298,   419,   175,   243,   257,   462,   166,
     243,   257,   166,   166,   155,   186,   193,   210,   224,   233,
     244,   428,   462,   243,   427,   243,   166,   243,   465,   166,
     230,   166,   166,   166,   465,   166,   465,   465,   465,   428,
       3,   428,   181,   398,   181,   400,   181,   399,   398,   249,
     425,   473,   474,   496,   400,   473,   399,   465,   499,   175,
     211,   220,   243,   249,   250,   254,   500,     3,   190,   257,
     338,   480,   179,   257,   464,   484,   480,   179,   257,   419,
     105,   255,   351,   480,   480,   365,   420,   420,   327,   166,
     166,   166,   243,   428,     3,   428,   243,   413,   166,   166,
     243,   166,   166,   413,   166,   166,   367,   477,   179,   377,
     327,   480,    44,    45,   258,   266,   300,   301,   302,   308,
     300,   300,   300,   305,     3,   480,   463,   465,   480,   179,
     463,   427,   261,   427,   427,   166,   465,   166,   166,   166,
     166,   166,   402,   425,   402,   402,     3,   482,   166,   243,
     166,   238,   166,   499,   499,   499,   480,   199,   339,   340,
     465,   480,   223,   386,   390,   290,   480,   418,     3,   166,
       3,   417,   166,     3,   166,   179,   449,   299,     3,   302,
     175,   419,   390,   190,     3,   390,   261,   428,   261,   261,
     261,   474,   465,   175,   175,   243,   190,   166,   243,   387,
     389,   477,   156,   184,   215,   384,   385,   391,   392,   446,
     214,   456,   166,   419,   166,   261,   166,   368,   166,   499,
     166,   166,   428,   428,   428,   428,   499,   499,   340,    33,
      40,   243,   255,   424,   480,     3,   253,   269,   421,   422,
     447,   448,   475,   480,   393,   393,   392,   384,   154,   196,
     237,   408,   151,   212,   441,   457,   428,   166,   175,   243,
     175,   175,   243,   179,   387,   388,   388,   213,   389,   424,
     422,   243,   257,   419,   194,   455,   458,   480,   256,   151,
     499,   499,   387,   259,   259,   179,   389,   448,   211,   480,
     461,   131,   306,     3,   421,   442,   443,   444,   458,   175,
     175,   166,   393,   393,   387,   419,   462,   243,   219,   240,
     445,   306,   166,   463,   443,   390,   456
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
#line 454 "sql.yacc"
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
#line 480 "sql.yacc"
    {
		(yyval.ptr)=0;
	}
    break;

  case 4:

/* Line 1455 of yacc.c  */
#line 483 "sql.yacc"
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
#line 500 "sql.yacc"
    {
		(yyval.ptr)=A4GL_new_select_list_item_expr((yyvsp[(2) - (2)].s_select_list_item));
	}
    break;

  case 6:

/* Line 1455 of yacc.c  */
#line 505 "sql.yacc"
    {
		(yyval.ptr)=0;
	}
    break;

  case 7:

/* Line 1455 of yacc.c  */
#line 508 "sql.yacc"
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
#line 525 "sql.yacc"
    {
		 (yyval.ptr)=A4GL_new_select_list_item_expr((yyvsp[(2) - (2)].s_select_list_item));
	}
    break;

  case 9:

/* Line 1455 of yacc.c  */
#line 531 "sql.yacc"
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
#line 540 "sql.yacc"
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

  case 12:

/* Line 1455 of yacc.c  */
#line 558 "sql.yacc"
    {
		(yyval.update_cmd)=(yyvsp[(2) - (2)].update_cmd);
		add_feature("UPDATE_COLUMN_EQ_VALUE_LIST");
    }
    break;

  case 13:

/* Line 1455 of yacc.c  */
#line 565 "sql.yacc"
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
#line 580 "sql.yacc"
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
#line 635 "sql.yacc"
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
#line 642 "sql.yacc"
    {
		(yyval.update_cmd)=(yyvsp[(1) - (3)].update_cmd);
		add_str_list((yyval.update_cmd)->column_list, (yyvsp[(3) - (3)].upd_pair)->column_name);
		local_add_select_list_item_list((yyval.update_cmd)->value_list, (yyvsp[(3) - (3)].upd_pair)->value);
	}
    break;

  case 17:

/* Line 1455 of yacc.c  */
#line 653 "sql.yacc"
    {
                strcpy((yyval.str),(yyvsp[(1) - (1)].str));
        }
    break;

  case 18:

/* Line 1455 of yacc.c  */
#line 656 "sql.yacc"
    {
                strcpy((yyval.str),(yyvsp[(2) - (2)].str));
        }
    break;

  case 19:

/* Line 1455 of yacc.c  */
#line 661 "sql.yacc"
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
#line 668 "sql.yacc"
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
#line 685 "sql.yacc"
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
#line 702 "sql.yacc"
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
#line 723 "sql.yacc"
    {
		(yyval.upd_pair)=malloc(sizeof(struct s_update_pair));
		(yyval.upd_pair)->column_name=acl_strdup((yyvsp[(1) - (3)].str));
		(yyval.upd_pair)->value=(yyvsp[(3) - (3)].s_select_list_item);
	}
    break;

  case 24:

/* Line 1455 of yacc.c  */
#line 732 "sql.yacc"
    {
			(yyval.str_list)=new_str_list((yyvsp[(1) - (1)].str));
		}
    break;

  case 25:

/* Line 1455 of yacc.c  */
#line 735 "sql.yacc"
    {
			(yyval.str_list)=add_str_list((yyvsp[(1) - (3)].str_list), (yyvsp[(3) - (3)].str));
		}
    break;

  case 26:

/* Line 1455 of yacc.c  */
#line 743 "sql.yacc"
    { 
		(yyval.s_select_list_item_list)=local_new_select_list_item_list((yyvsp[(1) - (1)].s_select_list_item));
	}
    break;

  case 27:

/* Line 1455 of yacc.c  */
#line 746 "sql.yacc"
    { 
		(yyval.s_select_list_item_list)=local_add_select_list_item_list((yyvsp[(1) - (3)].s_select_list_item_list),(yyvsp[(3) - (3)].s_select_list_item));
	}
    break;

  case 28:

/* Line 1455 of yacc.c  */
#line 754 "sql.yacc"
    {(yyval.s_select_list_item)=(yyvsp[(1) - (1)].s_select_list_item);}
    break;

  case 29:

/* Line 1455 of yacc.c  */
#line 755 "sql.yacc"
    {(yyval.s_select_list_item)=new_select_list_item_builtin_const(E_SLI_BUILTIN_CONST_NULL); }
    break;

  case 30:

/* Line 1455 of yacc.c  */
#line 762 "sql.yacc"
    { (yyval.sql_string)=make_sql_string_and_free(acl_strdup((yyvsp[(1) - (1)].str)), NULL);}
    break;

  case 31:

/* Line 1455 of yacc.c  */
#line 765 "sql.yacc"
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
#line 773 "sql.yacc"
    {SPRINTF2((yyval.str),"%s %s ",(yyvsp[(1) - (2)].str),(yyvsp[(2) - (2)].str));
			add_feature("DROP_VIEW");
}
    break;

  case 33:

/* Line 1455 of yacc.c  */
#line 776 "sql.yacc"
    {SPRINTF2((yyval.str),"%s %s",(yyvsp[(1) - (2)].str),(yyvsp[(2) - (2)].str));
		if (strchr((yyvsp[(2) - (2)].str),'@') || strchr((yyvsp[(2) - (2)].str),':')) add_feature("DROP_INDEX_QUALIFIED_PATH");
			add_feature("DROP_INDEX");
}
    break;

  case 34:

/* Line 1455 of yacc.c  */
#line 780 "sql.yacc"
    {SPRINTF2((yyval.str),"%s %s",(yyvsp[(1) - (2)].str),(yyvsp[(2) - (2)].str));
			add_feature("DROP_TRIGGER");
}
    break;

  case 35:

/* Line 1455 of yacc.c  */
#line 786 "sql.yacc"
    {(yyval.sql_string)=acl_strdup((yyvsp[(1) - (1)].str));}
    break;

  case 36:

/* Line 1455 of yacc.c  */
#line 787 "sql.yacc"
    {(yyval.sql_string)=(yyvsp[(1) - (1)].sql_string);}
    break;

  case 37:

/* Line 1455 of yacc.c  */
#line 791 "sql.yacc"
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
#line 801 "sql.yacc"
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
#line 815 "sql.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 40:

/* Line 1455 of yacc.c  */
#line 816 "sql.yacc"
    {strcpy((yyval.str),(yyvsp[(1) - (1)].str));}
    break;

  case 42:

/* Line 1455 of yacc.c  */
#line 821 "sql.yacc"
    {SPRINTF2((yyval.str),"%s%s",(yyvsp[(1) - (2)].str),(yyvsp[(2) - (2)].str)); }
    break;

  case 43:

/* Line 1455 of yacc.c  */
#line 826 "sql.yacc"
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
#line 834 "sql.yacc"
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
#line 842 "sql.yacc"
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
#line 850 "sql.yacc"
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
#line 858 "sql.yacc"
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
#line 870 "sql.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 50:

/* Line 1455 of yacc.c  */
#line 870 "sql.yacc"
    {strcpy((yyval.str),(yyvsp[(1) - (1)].str));}
    break;

  case 52:

/* Line 1455 of yacc.c  */
#line 874 "sql.yacc"
    {SPRINTF2((yyval.str),"%s%s",(yyvsp[(1) - (2)].str),(yyvsp[(2) - (2)].str));}
    break;

  case 53:

/* Line 1455 of yacc.c  */
#line 878 "sql.yacc"
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
#line 885 "sql.yacc"
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
#line 892 "sql.yacc"
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
#line 899 "sql.yacc"
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
#line 908 "sql.yacc"
    { strcpy(last_tmp_name,(yyvsp[(1) - (1)].str)); }
    break;

  case 58:

/* Line 1455 of yacc.c  */
#line 912 "sql.yacc"
    {SPRINTF7((yyval.str),"CREATE UNIQUE INDEX %s %s %s %s %s %s %s",(yyvsp[(2) - (8)].str),(yyvsp[(3) - (8)].str),(yyvsp[(4) - (8)].str),(yyvsp[(5) - (8)].str),(yyvsp[(6) - (8)].str),(yyvsp[(7) - (8)].str),(yyvsp[(8) - (8)].str));
		add_feature("CREATE_INDEX");
		add_feature("CREATE_INDEX_UNIQUE");
		if (strchr((yyvsp[(2) - (8)].str),'@') || strchr((yyvsp[(2) - (8)].str),':')) add_feature("CREATE_INDEX_QUALIFIED_PATH");
		if (strchr((yyvsp[(6) - (8)].str),',')) { add_feature("CREATE_INDEX_COMPOSITE"); }
	
}
    break;

  case 59:

/* Line 1455 of yacc.c  */
#line 919 "sql.yacc"
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
#line 931 "sql.yacc"
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
#line 942 "sql.yacc"
    {
		if (strchr((yyvsp[(2) - (8)].str),'@') || strchr((yyvsp[(2) - (8)].str),':')) add_feature("CREATE_INDEX_QUALIFIED_PATH");
		if (strchr((yyvsp[(6) - (8)].str),',')) { add_feature("CREATE_INDEX_COMPOSITE"); }
			add_feature("CREATE_INDEX");
			SPRINTF7((yyval.str)," CREATE INDEX %s %s %s %s %s %s %s",(yyvsp[(2) - (8)].str),(yyvsp[(3) - (8)].str),(yyvsp[(4) - (8)].str),(yyvsp[(5) - (8)].str),(yyvsp[(6) - (8)].str),(yyvsp[(7) - (8)].str),(yyvsp[(8) - (8)].str));
	}
    break;

  case 62:

/* Line 1455 of yacc.c  */
#line 948 "sql.yacc"
    {
		add_feature("CREATE_DATABASE");
		a4gl_yyerror("You cannot create a database from within Aubit4gl - if the target database allows - prepare and execute it manually");
	}
    break;

  case 63:

/* Line 1455 of yacc.c  */
#line 952 "sql.yacc"
    {
		add_feature("DROP_DATABASE");
		a4gl_yyerror("You cannot drop a database from within Aubit4gl - if the target database allows - prepare and execute it manually");
	}
    break;

  case 64:

/* Line 1455 of yacc.c  */
#line 956 "sql.yacc"
    { 
		if (strchr((yyvsp[(2) - (4)].str),'@') || strchr((yyvsp[(2) - (4)].str),':')) add_feature("CREATE_SYNONYM_QUALIFIED_PATH");
			add_feature("CREATE_SYNONYM");
			SPRINTF3((yyval.str),"%s %s FOR %s",(yyvsp[(1) - (4)].str),(yyvsp[(2) - (4)].str),(yyvsp[(4) - (4)].str)); 
	}
    break;

  case 65:

/* Line 1455 of yacc.c  */
#line 961 "sql.yacc"
    { 
		add_feature("CREATE_AUDIT");
		SPRINTF2((yyval.str),"CREATE AUDIT FOR %s IN '%s'",(yyvsp[(2) - (4)].str),A4GL_strip_quotes((yyvsp[(4) - (4)].str))); 
	}
    break;

  case 66:

/* Line 1455 of yacc.c  */
#line 965 "sql.yacc"
    { 
		add_feature("DROP_AUDIT");
		SPRINTF1((yyval.str),"DROP AUDIT FOR %s",(yyvsp[(2) - (2)].str)); }
    break;

  case 67:

/* Line 1455 of yacc.c  */
#line 968 "sql.yacc"
    { 
		if (strchr((yyvsp[(2) - (2)].str),'@') || strchr((yyvsp[(2) - (2)].str),':')) add_feature("DROP_SYNONYM_QUALIFIED_PATH");
		add_feature("DROP_SYNONYM");
		SPRINTF2((yyval.str),"%s %s",(yyvsp[(1) - (2)].str),(yyvsp[(2) - (2)].str)); }
    break;

  case 68:

/* Line 1455 of yacc.c  */
#line 972 "sql.yacc"
    { 
		add_feature("RECOVER_TABLE");
		SPRINTF1((yyval.str),"RECOVER TABLE %s",(yyvsp[(2) - (2)].str)); }
    break;

  case 69:

/* Line 1455 of yacc.c  */
#line 975 "sql.yacc"
    { 
		add_feature("ROLLFORWARD_DATABASE");
		SPRINTF1((yyval.str),"ROLLFORWARD DATABASE %s",(yyvsp[(2) - (2)].str)); }
    break;

  case 70:

/* Line 1455 of yacc.c  */
#line 982 "sql.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 71:

/* Line 1455 of yacc.c  */
#line 983 "sql.yacc"
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
#line 993 "sql.yacc"
    {(yyval.integer_val)=0;}
    break;

  case 73:

/* Line 1455 of yacc.c  */
#line 994 "sql.yacc"
    { (yyval.integer_val)=1;}
    break;

  case 75:

/* Line 1455 of yacc.c  */
#line 999 "sql.yacc"
    {SPRINTF2((yyval.str),"%s,%s",(yyvsp[(1) - (3)].str),(yyvsp[(3) - (3)].str));}
    break;

  case 76:

/* Line 1455 of yacc.c  */
#line 1003 "sql.yacc"
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
#line 1012 "sql.yacc"
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
#line 1021 "sql.yacc"
    {
		strcpy((yyval.str),A4GL_confirm_colname(last_tmp_name,(yyvsp[(1) - (1)].str)));
}
    break;

  case 79:

/* Line 1455 of yacc.c  */
#line 1028 "sql.yacc"
    {
		(yyval.sql_string)=(yyvsp[(1) - (1)].sql_string);
	}
    break;

  case 80:

/* Line 1455 of yacc.c  */
#line 1031 "sql.yacc"
    {
		(yyval.sql_string)=make_sql_string_and_free((yyvsp[(1) - (3)].sql_string),kw_comma,strdup("\n"),(yyvsp[(3) - (3)].sql_string),NULL);
	}
    break;

  case 81:

/* Line 1455 of yacc.c  */
#line 1037 "sql.yacc"
    {
		(yyval.sql_string)=make_sql_string_and_free(strdup("   "),(yyvsp[(1) - (1)].sql_string),NULL);
	}
    break;

  case 82:

/* Line 1455 of yacc.c  */
#line 1040 "sql.yacc"
    {
		(yyval.sql_string)=make_sql_string_and_free(strdup("   "),(yyvsp[(1) - (1)].sql_string),NULL);
	}
    break;

  case 83:

/* Line 1455 of yacc.c  */
#line 1051 "sql.yacc"
    {
		add_feature("ALTER_TABLE");
	(yyval.sql_string)=make_sql_string_and_free(acl_strdup((yyvsp[(1) - (3)].str)),kw_space,acl_strdup((yyvsp[(2) - (3)].str)),kw_space,(yyvsp[(3) - (3)].sql_string),NULL);
	}
    break;

  case 84:

/* Line 1455 of yacc.c  */
#line 1055 "sql.yacc"
    {
		add_feature("CLUSTER_INDEX");
		add_feature("ALTER_INDEX_CLUSTER");
		(yyval.sql_string)=make_sql_string_and_free(acl_strdup("ALTER INDEX "),acl_strdup((yyvsp[(2) - (3)].str)),acl_strdup(" TO CLUSTER"),NULL);
		}
    break;

  case 85:

/* Line 1455 of yacc.c  */
#line 1060 "sql.yacc"
    {
		add_feature("ALTER_INDEX_NOT_CLUSTER");
		(yyval.sql_string)=make_sql_string_and_free(acl_strdup("ALTER INDEX "),acl_strdup((yyvsp[(2) - (3)].str)),acl_strdup(" TO NOT CLUSTER"),NULL);
		}
    break;

  case 86:

/* Line 1455 of yacc.c  */
#line 1067 "sql.yacc"
    {
		(yyval.sql_string)=(yyvsp[(1) - (1)].sql_string);
	}
    break;

  case 87:

/* Line 1455 of yacc.c  */
#line 1070 "sql.yacc"
    {
		(yyval.sql_string)=make_sql_string_and_free((yyvsp[(1) - (3)].sql_string),kw_comma,(yyvsp[(3) - (3)].sql_string),NULL);
	}
    break;

  case 88:

/* Line 1455 of yacc.c  */
#line 1079 "sql.yacc"
    {
		(yyval.sql_string)=(yyvsp[(1) - (1)].sql_string);
	}
    break;

  case 89:

/* Line 1455 of yacc.c  */
#line 1082 "sql.yacc"
    {
	add_feature("ALTER_TABLE_DROP");
		(yyval.sql_string)=acl_strdup((yyvsp[(1) - (1)].str));
	}
    break;

  case 90:

/* Line 1455 of yacc.c  */
#line 1086 "sql.yacc"
    {
	add_feature("ALTER_TABLE_MODIFY");
		(yyval.sql_string)=(yyvsp[(1) - (1)].sql_string);
	}
    break;

  case 91:

/* Line 1455 of yacc.c  */
#line 1090 "sql.yacc"
    {
		add_feature("ALTER_TABLE_ADD_CONSTRAINT");
		(yyval.sql_string)=acl_strdup((yyvsp[(1) - (1)].str));
	}
    break;

  case 92:

/* Line 1455 of yacc.c  */
#line 1094 "sql.yacc"
    {
		add_feature("ALTER_TABLE_DROP_CONSTRAINT");
		(yyval.sql_string)=acl_strdup((yyvsp[(1) - (1)].str));
	}
    break;

  case 93:

/* Line 1455 of yacc.c  */
#line 1098 "sql.yacc"
    {
		add_feature("ALTER_TABLE_MODIFY_NEXT");
		(yyval.sql_string)=acl_strdup((yyvsp[(1) - (1)].str));
	}
    break;

  case 94:

/* Line 1455 of yacc.c  */
#line 1102 "sql.yacc"
    {
		add_feature("ALTER_TABLE_LOCK_MODE");
		(yyval.sql_string)=acl_strdup((yyvsp[(1) - (1)].str));
	}
    break;

  case 95:

/* Line 1455 of yacc.c  */
#line 1110 "sql.yacc"
    {
		add_feature("ALTER_TABLE_ADD");
		(yyval.sql_string)=make_sql_string_and_free(acl_strdup("ADD "),(yyvsp[(2) - (2)].sql_string),NULL);
	}
    break;

  case 96:

/* Line 1455 of yacc.c  */
#line 1114 "sql.yacc"
    {
		add_feature("ALTER_TABLE_ADD");
		(yyval.sql_string)=make_sql_string_and_free(acl_strdup("ADD "),kw_ob,(yyvsp[(3) - (4)].sql_string),kw_cb,NULL);
	}
    break;

  case 97:

/* Line 1455 of yacc.c  */
#line 1122 "sql.yacc"
    {
		(yyval.sql_string)=(yyvsp[(1) - (1)].sql_string);
	}
    break;

  case 98:

/* Line 1455 of yacc.c  */
#line 1125 "sql.yacc"
    {
		add_feature("ALTER_TABLE_ADD_BEFORE");
		(yyval.sql_string)=make_sql_string_and_free((yyvsp[(1) - (3)].sql_string),acl_strdup(" BEFORE "),acl_strdup((yyvsp[(3) - (3)].str)),NULL);
	}
    break;

  case 99:

/* Line 1455 of yacc.c  */
#line 1132 "sql.yacc"
    {
		(yyval.sql_string)=(yyvsp[(1) - (1)].sql_string);
	}
    break;

  case 100:

/* Line 1455 of yacc.c  */
#line 1135 "sql.yacc"
    {
		(yyval.sql_string)=make_sql_string_and_free((yyvsp[(1) - (3)].sql_string),kw_comma,(yyvsp[(3) - (3)].sql_string),NULL);
	}
    break;

  case 101:

/* Line 1455 of yacc.c  */
#line 1142 "sql.yacc"
    {
		SPRINTF1((yyval.str),"DROP %s",(yyvsp[(2) - (2)].str));
	}
    break;

  case 102:

/* Line 1455 of yacc.c  */
#line 1145 "sql.yacc"
    {
		SPRINTF1((yyval.str),"DROP (%s)",(yyvsp[(3) - (4)].str));
	}
    break;

  case 104:

/* Line 1455 of yacc.c  */
#line 1153 "sql.yacc"
    {
		SPRINTF2((yyval.str),"%s,%s",(yyvsp[(1) - (3)].str),(yyvsp[(3) - (3)].str));
	}
    break;

  case 106:

/* Line 1455 of yacc.c  */
#line 1162 "sql.yacc"
    {
		(yyval.sql_string)=make_sql_string_and_free(acl_strdup("MODIFY "),(yyvsp[(2) - (2)].sql_string),NULL);
	}
    break;

  case 107:

/* Line 1455 of yacc.c  */
#line 1165 "sql.yacc"
    {
		(yyval.sql_string)=make_sql_string_and_free(acl_strdup("MODIFY "),kw_ob,(yyvsp[(3) - (4)].sql_string),kw_cb,NULL);
	}
    break;

  case 108:

/* Line 1455 of yacc.c  */
#line 1171 "sql.yacc"
    {
		(yyval.sql_string)=(yyvsp[(1) - (1)].sql_string);
	}
    break;

  case 109:

/* Line 1455 of yacc.c  */
#line 1174 "sql.yacc"
    {
		(yyval.sql_string)=make_sql_string_and_free((yyvsp[(1) - (3)].sql_string),kw_comma,(yyvsp[(3) - (3)].sql_string),NULL);
	}
    break;

  case 110:

/* Line 1455 of yacc.c  */
#line 1180 "sql.yacc"
    {
		(yyval.sql_string)=(yyvsp[(1) - (1)].sql_string);
	}
    break;

  case 111:

/* Line 1455 of yacc.c  */
#line 1187 "sql.yacc"
    {strcpy((yyval.str),"LOCK MODE (PAGE)");}
    break;

  case 112:

/* Line 1455 of yacc.c  */
#line 1188 "sql.yacc"
    {strcpy((yyval.str),"LOCK MODE (ROW)");}
    break;

  case 113:

/* Line 1455 of yacc.c  */
#line 1192 "sql.yacc"
    {
		add_feature("DDL_NEXT_SIZE");
		SPRINTF1((yyval.str),"MODIFY NEXT SIZE %d",atoi((yyvsp[(2) - (2)].str)));
	}
    break;

  case 114:

/* Line 1455 of yacc.c  */
#line 1200 "sql.yacc"
    {
		add_feature("DDL_CONSTRAINT");
		SPRINTF2((yyval.str),"ADD CONSTRAINT %s%s",(yyvsp[(2) - (3)].sql_string),(yyvsp[(3) - (3)].str));
	}
    break;

  case 115:

/* Line 1455 of yacc.c  */
#line 1204 "sql.yacc"
    {
		add_feature("ADD_CONSTRAINT");
		SPRINTF1((yyval.str),"ADD CONSTRAINT (%s)",(yyvsp[(3) - (4)].sql_string));
	}
    break;

  case 116:

/* Line 1455 of yacc.c  */
#line 1211 "sql.yacc"
    {
		(yyval.sql_string)=make_sql_string_and_free((yyvsp[(1) - (2)].sql_string),acl_strdup((yyvsp[(2) - (2)].str)),NULL);
}
    break;

  case 117:

/* Line 1455 of yacc.c  */
#line 1213 "sql.yacc"
    {
	(yyval.sql_string)=make_sql_string_and_free((yyvsp[(1) - (4)].sql_string),kw_comma,(yyvsp[(3) - (4)].sql_string),acl_strdup((yyvsp[(4) - (4)].str)), NULL);
}
    break;

  case 118:

/* Line 1455 of yacc.c  */
#line 1218 "sql.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 119:

/* Line 1455 of yacc.c  */
#line 1219 "sql.yacc"
    {SPRINTF2((yyval.str)," %s %s",(yyvsp[(1) - (2)].str),(yyvsp[(2) - (2)].str)); add_feature("DDL_CONSTRAINT");}
    break;

  case 120:

/* Line 1455 of yacc.c  */
#line 1224 "sql.yacc"
    { SPRINTF1((yyval.str),"DROP CONSTRAINT %s",(yyvsp[(2) - (2)].str)); add_feature("DROP_CONSTRAINT"); }
    break;

  case 121:

/* Line 1455 of yacc.c  */
#line 1225 "sql.yacc"
    {add_feature("DROP_CONSTRAINT");
		SPRINTF1((yyval.str),"DROP CONSTRAINT (%s)",(yyvsp[(3) - (4)].str));
	}
    break;

  case 122:

/* Line 1455 of yacc.c  */
#line 1231 "sql.yacc"
    {strcpy((yyval.str),(yyvsp[(1) - (1)].str));}
    break;

  case 123:

/* Line 1455 of yacc.c  */
#line 1232 "sql.yacc"
    {SPRINTF2((yyval.str),"%s,%s",(yyvsp[(1) - (3)].str),(yyvsp[(3) - (3)].str));}
    break;

  case 125:

/* Line 1455 of yacc.c  */
#line 1246 "sql.yacc"
    {  add_feature("ROLLBACK_WORK"); }
    break;

  case 126:

/* Line 1455 of yacc.c  */
#line 1252 "sql.yacc"
    { insql=1;}
    break;

  case 127:

/* Line 1455 of yacc.c  */
#line 1252 "sql.yacc"
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
#line 1261 "sql.yacc"
    {insql=1;}
    break;

  case 129:

/* Line 1455 of yacc.c  */
#line 1261 "sql.yacc"
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
#line 1270 "sql.yacc"
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
#line 1295 "sql.yacc"
    {
			(yyval.str_list)=0;
	}
    break;

  case 132:

/* Line 1455 of yacc.c  */
#line 1298 "sql.yacc"
    {
			(yyval.str_list)=(yyvsp[(2) - (3)].str_list);
			 add_feature("INSERT_COLUMNLIST_EQ_VALUELIST");
	}
    break;

  case 133:

/* Line 1455 of yacc.c  */
#line 1306 "sql.yacc"
    {
                        (yyval.str_list)=new_str_list((yyvsp[(1) - (1)].str));
	}
    break;

  case 134:

/* Line 1455 of yacc.c  */
#line 1309 "sql.yacc"
    {
                        (yyval.str_list)=add_str_list((yyvsp[(1) - (3)].str_list), (yyvsp[(3) - (3)].str));
	}
    break;

  case 135:

/* Line 1455 of yacc.c  */
#line 1316 "sql.yacc"
    {	
			strcpy((yyval.str),(yyvsp[(1) - (1)].str));
	}
    break;

  case 136:

/* Line 1455 of yacc.c  */
#line 1319 "sql.yacc"
    { 
			/* with a table prefix - on an insert ? We'll just silently drop it... */
			strcpy((yyval.str),(yyvsp[(3) - (3)].str));
			A4GL_warn("Dropped table prefix from INSERT column name");
	}
    break;

  case 137:

/* Line 1455 of yacc.c  */
#line 1327 "sql.yacc"
    { (yyval.s_select_list_item_list)=local_new_select_list_item_list((yyvsp[(1) - (1)].s_select_list_item));}
    break;

  case 138:

/* Line 1455 of yacc.c  */
#line 1328 "sql.yacc"
    {
		(yyval.s_select_list_item_list)=local_add_select_list_item_list((yyvsp[(1) - (3)].s_select_list_item_list),(yyvsp[(3) - (3)].s_select_list_item));
	}
    break;

  case 139:

/* Line 1455 of yacc.c  */
#line 1334 "sql.yacc"
    {(yyval.s_select_list_item)=(yyvsp[(1) - (1)].s_select_list_item);}
    break;

  case 140:

/* Line 1455 of yacc.c  */
#line 1335 "sql.yacc"
    {(yyval.s_select_list_item)=new_select_list_item_builtin_const(E_SLI_BUILTIN_CONST_NULL); }
    break;

  case 141:

/* Line 1455 of yacc.c  */
#line 1343 "sql.yacc"
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
#line 1361 "sql.yacc"
    { add_feature("BEGIN_WORK"); }
    break;

  case 143:

/* Line 1455 of yacc.c  */
#line 1365 "sql.yacc"
    { add_feature("COMMIT_WORK"); }
    break;

  case 144:

/* Line 1455 of yacc.c  */
#line 1370 "sql.yacc"
    {(yyval.e_boolean)=EB_FALSE;}
    break;

  case 145:

/* Line 1455 of yacc.c  */
#line 1371 "sql.yacc"
    {
		add_feature("DATABASE_EXCLUSIVE");
		{(yyval.e_boolean)=EB_TRUE;}
	}
    break;

  case 146:

/* Line 1455 of yacc.c  */
#line 1381 "sql.yacc"
    {
	char buff[256];
	(yyval.sql_string)=make_sql_string_and_free(acl_strdup((yyvsp[(1) - (1)].str)),NULL);
	SPRINTF1(buff,"Warning: Informix specific SQL @ line %d\n",yylineno);
	ansi_violation(buff,1);
	}
    break;

  case 147:

/* Line 1455 of yacc.c  */
#line 1390 "sql.yacc"
    {
			add_feature("START_DATABASE_WITH_LOG_MODE_ANSI");
			sprintf((yyval.str),"START DATABASE %s WITH LOG IN %s MODE ANSI", (yyvsp[(2) - (5)].str),(yyvsp[(4) - (5)].str));
	}
    break;

  case 148:

/* Line 1455 of yacc.c  */
#line 1394 "sql.yacc"
    {
			add_feature("START_DATABASE_WITH_LOG");
			sprintf((yyval.str),"START DATABASE %s WITH LOG IN %s", (yyvsp[(2) - (4)].str),(yyvsp[(4) - (4)].str));
	}
    break;

  case 149:

/* Line 1455 of yacc.c  */
#line 1399 "sql.yacc"
    {
			add_feature("SET_CONSTRAINTS_ALL_IMMEDIATE");
			SPRINTF1((yyval.str),"%s",(yyvsp[(1) - (1)].str)); 
	}
    break;

  case 150:

/* Line 1455 of yacc.c  */
#line 1403 "sql.yacc"
    {
		add_feature("SET_BUFFERED_LOG");
			SPRINTF1((yyval.str),"%s",(yyvsp[(1) - (1)].str)); 
	}
    break;

  case 151:

/* Line 1455 of yacc.c  */
#line 1407 "sql.yacc"
    {
		add_feature("SET_LOG");
			SPRINTF1((yyval.str),"%s",(yyvsp[(1) - (1)].str)); 
	}
    break;

  case 152:

/* Line 1455 of yacc.c  */
#line 1411 "sql.yacc"
    {
			SPRINTF2((yyval.str),"%s %s",(yyvsp[(1) - (2)].str),(yyvsp[(2) - (2)].str)); add_feature("UPDATE_STATISTICS_TABLE");
	}
    break;

  case 153:

/* Line 1455 of yacc.c  */
#line 1414 "sql.yacc"
    {
		add_feature("UPDATE_STATISTICS");
			SPRINTF1((yyval.str),"%s",(yyvsp[(1) - (1)].str)); 
	}
    break;

  case 154:

/* Line 1455 of yacc.c  */
#line 1421 "sql.yacc"
    { (yyval.integer_val)=1; }
    break;

  case 155:

/* Line 1455 of yacc.c  */
#line 1422 "sql.yacc"
    { (yyval.integer_val)=-1; }
    break;

  case 156:

/* Line 1455 of yacc.c  */
#line 1423 "sql.yacc"
    { (yyval.integer_val)=0; }
    break;

  case 157:

/* Line 1455 of yacc.c  */
#line 1427 "sql.yacc"
    { (yyval.sql_string)=(yyvsp[(1) - (1)].sql_string); }
    break;

  case 158:

/* Line 1455 of yacc.c  */
#line 1428 "sql.yacc"
    { (yyval.sql_string)=(yyvsp[(1) - (1)].sql_string); }
    break;

  case 159:

/* Line 1455 of yacc.c  */
#line 1429 "sql.yacc"
    { (yyval.sql_string)=(yyvsp[(1) - (1)].sql_string); }
    break;

  case 160:

/* Line 1455 of yacc.c  */
#line 1430 "sql.yacc"
    { (yyval.sql_string)=(yyvsp[(1) - (1)].sql_string); }
    break;

  case 161:

/* Line 1455 of yacc.c  */
#line 1431 "sql.yacc"
    { (yyval.sql_string)=(yyvsp[(1) - (1)].sql_string); }
    break;

  case 162:

/* Line 1455 of yacc.c  */
#line 1432 "sql.yacc"
    { (yyval.sql_string)=(yyvsp[(1) - (1)].sql_string); }
    break;

  case 163:

/* Line 1455 of yacc.c  */
#line 1433 "sql.yacc"
    { (yyval.sql_string)=(yyvsp[(1) - (1)].sql_string); }
    break;

  case 164:

/* Line 1455 of yacc.c  */
#line 1441 "sql.yacc"
    {SPRINTF7((yyval.str),"%s %s %s %s %s %s %s",(yyvsp[(1) - (7)].str),(yyvsp[(2) - (7)].str),(yyvsp[(3) - (7)].str),(yyvsp[(4) - (7)].str),(yyvsp[(5) - (7)].str),(yyvsp[(6) - (7)].str),(yyvsp[(7) - (7)].str));  add_feature("GRANT"); }
    break;

  case 165:

/* Line 1455 of yacc.c  */
#line 1442 "sql.yacc"
    {SPRINTF6((yyval.str),"%s %s %s %s %s %s",(yyvsp[(1) - (6)].str),(yyvsp[(2) - (6)].str),(yyvsp[(3) - (6)].str),(yyvsp[(4) - (6)].str),(yyvsp[(5) - (6)].str),(yyvsp[(6) - (6)].str));  add_feature("REVOKE"); }
    break;

  case 166:

/* Line 1455 of yacc.c  */
#line 1443 "sql.yacc"
    {SPRINTF4((yyval.str),"%s %s %s %s ",(yyvsp[(1) - (4)].str),(yyvsp[(2) - (4)].str),(yyvsp[(3) - (4)].str),(yyvsp[(4) - (4)].str)); add_feature("GRANT"); }
    break;

  case 167:

/* Line 1455 of yacc.c  */
#line 1444 "sql.yacc"
    {SPRINTF4((yyval.str),"%s %s %s %s ",(yyvsp[(1) - (4)].str),(yyvsp[(2) - (4)].str),(yyvsp[(3) - (4)].str),(yyvsp[(4) - (4)].str));  add_feature("REVOKE"); }
    break;

  case 171:

/* Line 1455 of yacc.c  */
#line 1454 "sql.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 172:

/* Line 1455 of yacc.c  */
#line 1455 "sql.yacc"
    {SPRINTF1((yyval.str)," %s ",(yyvsp[(1) - (1)].str));}
    break;

  case 173:

/* Line 1455 of yacc.c  */
#line 1456 "sql.yacc"
    {SPRINTF2((yyval.str)," %s %s",(yyvsp[(1) - (2)].str),(yyvsp[(2) - (2)].str));}
    break;

  case 174:

/* Line 1455 of yacc.c  */
#line 1460 "sql.yacc"
    {SPRINTF1((yyval.str)," %s ",(yyvsp[(1) - (1)].str));}
    break;

  case 175:

/* Line 1455 of yacc.c  */
#line 1461 "sql.yacc"
    {SPRINTF1((yyval.str)," %s ",(yyvsp[(1) - (1)].str));}
    break;

  case 178:

/* Line 1455 of yacc.c  */
#line 1468 "sql.yacc"
    {SPRINTF3((yyval.str)," %s %s %s",(yyvsp[(1) - (3)].str),(yyvsp[(2) - (3)].str),(yyvsp[(3) - (3)].str));}
    break;

  case 179:

/* Line 1455 of yacc.c  */
#line 1471 "sql.yacc"
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
#line 1480 "sql.yacc"
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
#line 1491 "sql.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 186:

/* Line 1455 of yacc.c  */
#line 1493 "sql.yacc"
    {SPRINTF3((yyval.str)," %s %s %s",(yyvsp[(1) - (3)].str),(yyvsp[(2) - (3)].str),(yyvsp[(3) - (3)].str));}
    break;

  case 188:

/* Line 1455 of yacc.c  */
#line 1499 "sql.yacc"
    {SPRINTF3((yyval.str)," %s %s %s",(yyvsp[(1) - (3)].str),(yyvsp[(2) - (3)].str),(yyvsp[(3) - (3)].str));}
    break;

  case 190:

/* Line 1455 of yacc.c  */
#line 1505 "sql.yacc"
    {SPRINTF3((yyval.str)," %s %s %s",(yyvsp[(1) - (3)].str),(yyvsp[(2) - (3)].str),(yyvsp[(3) - (3)].str));}
    break;

  case 193:

/* Line 1455 of yacc.c  */
#line 1515 "sql.yacc"
    {
		add_feature("CREATE_VIEW_AS_SELECT");
		(yyval.sql_string)=make_sql_string_and_free(acl_strdup((yyvsp[(1) - (6)].str)),kw_space,acl_strdup((yyvsp[(2) - (6)].str)),kw_space,acl_strdup((yyvsp[(3) - (6)].str)),kw_space,acl_strdup((yyvsp[(4) - (6)].str)),kw_space,(yyvsp[(5) - (6)].sql_string),kw_space,acl_strdup((yyvsp[(6) - (6)].str)),NULL);
	
}
    break;

  case 194:

/* Line 1455 of yacc.c  */
#line 1522 "sql.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 195:

/* Line 1455 of yacc.c  */
#line 1524 "sql.yacc"
    {SPRINTF3((yyval.str)," %s %s %s",(yyvsp[(1) - (3)].str),(yyvsp[(2) - (3)].str),(yyvsp[(3) - (3)].str));}
    break;

  case 197:

/* Line 1455 of yacc.c  */
#line 1530 "sql.yacc"
    {SPRINTF3((yyval.str)," %s %s %s",(yyvsp[(1) - (3)].str),(yyvsp[(2) - (3)].str),(yyvsp[(3) - (3)].str));}
    break;

  case 198:

/* Line 1455 of yacc.c  */
#line 1533 "sql.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 199:

/* Line 1455 of yacc.c  */
#line 1534 "sql.yacc"
    {
		add_feature("CREATE_VIEW_SELECT_WITH_CHECK");
	}
    break;

  case 200:

/* Line 1455 of yacc.c  */
#line 1541 "sql.yacc"
    {
		(yyval.sql_string)=make_sql_string_and_free(strdup("CHECK ("),(yyvsp[(3) - (4)].sql_string),kw_cb,NULL);
		add_feature("DDL_CHECK");
	}
    break;

  case 201:

/* Line 1455 of yacc.c  */
#line 1550 "sql.yacc"
    {SPRINTF5((yyval.str)," %s %s %s %s %s",(yyvsp[(1) - (5)].str),(yyvsp[(2) - (5)].str),(yyvsp[(3) - (5)].str),(yyvsp[(4) - (5)].str),(yyvsp[(5) - (5)].str));
	add_feature("DDL_FOREIGN_KEY");
}
    break;

  case 202:

/* Line 1455 of yacc.c  */
#line 1557 "sql.yacc"
    {SPRINTF2((yyval.str)," %s %s",(yyvsp[(1) - (2)].str),(yyvsp[(2) - (2)].str));
add_feature("DDL_REFERENCES");
}
    break;

  case 205:

/* Line 1455 of yacc.c  */
#line 1569 "sql.yacc"
    {SPRINTF4((yyval.str)," %s %s %s %s",(yyvsp[(1) - (4)].str),(yyvsp[(2) - (4)].str),(yyvsp[(3) - (4)].str),(yyvsp[(4) - (4)].str));}
    break;

  case 207:

/* Line 1455 of yacc.c  */
#line 1575 "sql.yacc"
    {SPRINTF3((yyval.str)," %s %s %s",(yyvsp[(1) - (3)].str),(yyvsp[(2) - (3)].str),(yyvsp[(3) - (3)].str));}
    break;

  case 208:

/* Line 1455 of yacc.c  */
#line 1580 "sql.yacc"
    {
		SPRINTF3((yyval.str)," UNIQUE %s %s %s",(yyvsp[(2) - (4)].str),(yyvsp[(3) - (4)].str),(yyvsp[(4) - (4)].str));
add_feature("DDL_UNIQUE");
	}
    break;

  case 209:

/* Line 1455 of yacc.c  */
#line 1584 "sql.yacc"
    {
		ansi_violation("Use UNIQUE not DISTINCT",0);
		SPRINTF3((yyval.str)," UNIQUE %s %s %s",(yyvsp[(2) - (4)].str),(yyvsp[(3) - (4)].str),(yyvsp[(4) - (4)].str));
add_feature("DDL_DISTINCT");
	}
    break;

  case 210:

/* Line 1455 of yacc.c  */
#line 1590 "sql.yacc"
    {SPRINTF4((yyval.str)," %s %s %s %s",(yyvsp[(1) - (4)].str),(yyvsp[(2) - (4)].str),(yyvsp[(3) - (4)].str),(yyvsp[(4) - (4)].str));
add_feature("DDL_PRIMARY_KEY");
}
    break;

  case 212:

/* Line 1455 of yacc.c  */
#line 1598 "sql.yacc"
    {SPRINTF3((yyval.str)," %s %s %s",(yyvsp[(1) - (3)].str),(yyvsp[(2) - (3)].str),(yyvsp[(3) - (3)].str));}
    break;

  case 213:

/* Line 1455 of yacc.c  */
#line 1603 "sql.yacc"
    {
		(yyval.sql_string)=acl_strdup((yyvsp[(1) - (1)].str));
	}
    break;

  case 214:

/* Line 1455 of yacc.c  */
#line 1606 "sql.yacc"
    {
		(yyval.sql_string)=acl_strdup((yyvsp[(1) - (1)].str));
	}
    break;

  case 215:

/* Line 1455 of yacc.c  */
#line 1609 "sql.yacc"
    {
		(yyval.sql_string)=(yyvsp[(1) - (1)].sql_string);
	}
    break;

  case 216:

/* Line 1455 of yacc.c  */
#line 1616 "sql.yacc"
    {SPRINTF2((yyval.str)," %s %s",(yyvsp[(1) - (2)].str),(yyvsp[(2) - (2)].str)); add_feature("DDL_DEFAULT_VALUE"); }
    break;

  case 217:

/* Line 1455 of yacc.c  */
#line 1617 "sql.yacc"
    {SPRINTF1((yyval.str)," DEFAULT %s", A4GLSQLCV_get_sqlconst("USER")); add_feature("DDL_DEFAULT_VALUE"); }
    break;

  case 218:

/* Line 1455 of yacc.c  */
#line 1618 "sql.yacc"
    {SPRINTF1((yyval.str)," DEFAULT %s", A4GLSQLCV_get_sqlconst("TODAY")); add_feature("DDL_DEFAULT_VALUE"); }
    break;

  case 219:

/* Line 1455 of yacc.c  */
#line 1619 "sql.yacc"
    { SPRINTF1((yyval.str)," %s",(yyvsp[(1) - (1)].str)); add_feature("DDL_DEFAULT_VALUE"); }
    break;

  case 220:

/* Line 1455 of yacc.c  */
#line 1625 "sql.yacc"
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

/* Line 1455 of yacc.c  */
#line 1648 "sql.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 223:

/* Line 1455 of yacc.c  */
#line 1652 "sql.yacc"
    {
		(yyval.sql_string)=acl_strdup("");
	}
    break;

  case 224:

/* Line 1455 of yacc.c  */
#line 1654 "sql.yacc"
    {
		(yyval.sql_string)=(yyvsp[(1) - (1)].sql_string);
	}
    break;

  case 225:

/* Line 1455 of yacc.c  */
#line 1661 "sql.yacc"
    {
		(yyval.sql_string)=(yyvsp[(1) - (1)].sql_string);
	}
    break;

  case 226:

/* Line 1455 of yacc.c  */
#line 1664 "sql.yacc"
    {
		(yyval.sql_string)=make_sql_string_and_free((yyvsp[(1) - (2)].sql_string),kw_space,(yyvsp[(2) - (2)].sql_string),NULL);
	}
    break;

  case 227:

/* Line 1455 of yacc.c  */
#line 1670 "sql.yacc"
    {
		(yyval.sql_string)=make_sql_string_and_free((yyvsp[(1) - (2)].sql_string),acl_strdup((yyvsp[(2) - (2)].str)),NULL);
	}
    break;

  case 228:

/* Line 1455 of yacc.c  */
#line 1678 "sql.yacc"
    {
		SPRINTF1((yyval.str)," %s ",(yyvsp[(1) - (1)].str));
		(yyval.sql_string)=acl_strdup((yyval.str));
		add_feature("DDL_NOT_NULL");
	}
    break;

  case 229:

/* Line 1455 of yacc.c  */
#line 1683 "sql.yacc"
    {
		SPRINTF0((yyval.str)," NOT NULL UNIQUE ");
		(yyval.sql_string)=acl_strdup((yyval.str));
		add_feature("DDL_NOT_NULL");
		add_feature("DDL_UNIQUE");
	}
    break;

  case 230:

/* Line 1455 of yacc.c  */
#line 1689 "sql.yacc"
    {
		SPRINTF0((yyval.str)," UNIQUE ");
		(yyval.sql_string)=acl_strdup((yyval.str));
		add_feature("DDL_UNIQUE");
	}
    break;

  case 231:

/* Line 1455 of yacc.c  */
#line 1694 "sql.yacc"
    {
		ansi_violation("Use UNIQUE not DISTINCT",0);
		SPRINTF0((yyval.str)," UNIQUE ");
		(yyval.sql_string)=acl_strdup((yyval.str));
		add_feature("DDL_DISTINCT");
	}
    break;

  case 232:

/* Line 1455 of yacc.c  */
#line 1700 "sql.yacc"
    {
		(yyval.sql_string)=acl_strdup((yyvsp[(1) - (1)].str));
	}
    break;

  case 233:

/* Line 1455 of yacc.c  */
#line 1703 "sql.yacc"
    {
		(yyval.sql_string)=make_sql_string_and_free(acl_strdup("CHECK ("),(yyvsp[(3) - (4)].sql_string),kw_cb,NULL);
		add_feature("DDL_CHECK");
		
	}
    break;

  case 234:

/* Line 1455 of yacc.c  */
#line 1708 "sql.yacc"
    {
		(yyval.sql_string)=make_sql_string_and_free(acl_strdup(" PRIMARY KEY "),NULL);
		add_feature("DDL_PRIMARY_KEY");
	}
    break;

  case 235:

/* Line 1455 of yacc.c  */
#line 1717 "sql.yacc"
    {
		add_feature("CREATE_SCHEMA");

(yyval.sql_string)=make_sql_string_and_free(acl_strdup((yyvsp[(1) - (3)].str)),kw_space,acl_strdup((yyvsp[(2) - (3)].str)),kw_space,acl_strdup((yyvsp[(3) - (3)].str)),NULL);
}
    break;

  case 236:

/* Line 1455 of yacc.c  */
#line 1726 "sql.yacc"
    {SPRINTF1((yyval.str)," %s",(yyvsp[(1) - (1)].str));}
    break;

  case 239:

/* Line 1455 of yacc.c  */
#line 1735 "sql.yacc"
    {
		(yyval.sql_string)=make_sql_string_and_free((yyvsp[(1) - (2)].sql_string),kw_space,(yyvsp[(2) - (2)].sql_string),NULL);
	}
    break;

  case 240:

/* Line 1455 of yacc.c  */
#line 1741 "sql.yacc"
    {
		(yyval.sql_string)=(yyvsp[(1) - (1)].sql_string);
	}
    break;

  case 241:

/* Line 1455 of yacc.c  */
#line 1744 "sql.yacc"
    {
		(yyval.sql_string)=acl_strdup((yyvsp[(1) - (1)].str));
	}
    break;

  case 242:

/* Line 1455 of yacc.c  */
#line 1755 "sql.yacc"
    {
		 add_feature("HAVING"); 
		(yyval.s_select_list_item)=(yyvsp[(2) - (2)].s_select_list_item);
	}
    break;

  case 243:

/* Line 1455 of yacc.c  */
#line 1764 "sql.yacc"
    {
		 (yyval.s_select_list_item)=(yyvsp[(2) - (2)].s_select_list_item);
	}
    break;

  case 244:

/* Line 1455 of yacc.c  */
#line 1771 "sql.yacc"
    {
		(yyval.u_table)=(yyvsp[(2) - (2)].u_table);
	}
    break;

  case 245:

/* Line 1455 of yacc.c  */
#line 1777 "sql.yacc"
    {(yyval.u_table)=(yyvsp[(1) - (1)].u_table);}
    break;

  case 246:

/* Line 1455 of yacc.c  */
#line 1778 "sql.yacc"
    {
		(yyval.u_table)=A4GLSQLPARSE_append_tablename((yyvsp[(1) - (3)].u_table),(yyvsp[(3) - (3)].u_table),E_OUTER_NONE,NULL);
	}
    break;

  case 247:

/* Line 1455 of yacc.c  */
#line 1781 "sql.yacc"
    {
		(yyval.u_table)=A4GLSQLPARSE_append_tablename((yyvsp[(1) - (4)].u_table),(yyvsp[(4) - (4)].u_table),E_OUTER_NORMAL,NULL);
		A4GL_warn("OUTER join *may* not be portable to non-informix database");
		add_feature("SELECT_OUTER");
	}
    break;

  case 248:

/* Line 1455 of yacc.c  */
#line 1786 "sql.yacc"
    {
		(yyval.u_table)=A4GLSQLPARSE_append_tablename((yyvsp[(1) - (6)].u_table),(yyvsp[(5) - (6)].u_table),E_OUTER_NORMAL,NULL);
		A4GL_warn("OUTER join *may* not be portable to non-informix database");
		add_feature("SELECT_OUTER");
	}
    break;

  case 249:

/* Line 1455 of yacc.c  */
#line 1797 "sql.yacc"
    {
		(yyval.u_table)=A4GLSQLPARSE_append_tablename((yyvsp[(1) - (5)].u_table),(yyvsp[(3) - (5)].u_table),E_OUTER_LEFT_OUTER, (yyvsp[(5) - (5)].s_select_list_item));
		add_feature("SELECT_OUTER");
	}
    break;

  case 250:

/* Line 1455 of yacc.c  */
#line 1801 "sql.yacc"
    {
		(yyval.u_table)=A4GLSQLPARSE_append_tablename((yyvsp[(1) - (5)].u_table),(yyvsp[(3) - (5)].u_table),E_INNER, (yyvsp[(5) - (5)].s_select_list_item));
		add_feature("SELECT_INNER");
	}
    break;

  case 252:

/* Line 1455 of yacc.c  */
#line 1809 "sql.yacc"
    {(yyval.u_table)=(yyvsp[(2) - (3)].u_table);}
    break;

  case 253:

/* Line 1455 of yacc.c  */
#line 1813 "sql.yacc"
    { 
			//A4GL_add_crud("SELECT",$<str>1);
			(yyval.u_table)=A4GLSQLPARSE_new_tablename((yyvsp[(1) - (1)].str),NULL);
	}
    break;

  case 254:

/* Line 1455 of yacc.c  */
#line 1817 "sql.yacc"
    { 
			//A4GL_add_crud("SELECT",$<str>1);
			(yyval.u_table)=A4GLSQLPARSE_new_tablename((yyvsp[(1) - (2)].str),(yyvsp[(2) - (2)].str));
	}
    break;

  case 255:

/* Line 1455 of yacc.c  */
#line 1821 "sql.yacc"
    { 
			//A4GL_add_crud("SELECT",$<str>1);
			(yyval.u_table)=A4GLSQLPARSE_new_tablename((yyvsp[(1) - (3)].str),(yyvsp[(3) - (3)].str));
	}
    break;

  case 256:

/* Line 1455 of yacc.c  */
#line 1828 "sql.yacc"
    {
			/* No from or where etc.. */
			/* eg.. select user ; */
			(yyval.s_select)=new_empty_select();
		}
    break;

  case 257:

/* Line 1455 of yacc.c  */
#line 1833 "sql.yacc"
    {
		(yyval.s_select)=(yyvsp[(2) - (2)].s_select);
		(yyval.s_select)->first=(yyvsp[(1) - (2)].u_table);
			A4GL_set_associated_mem( (yyval.s_select), (yyval.s_select)->first);
}
    break;

  case 258:

/* Line 1455 of yacc.c  */
#line 1841 "sql.yacc"
    {
		(yyval.s_select)=(yyvsp[(1) - (1)].s_select);
	}
    break;

  case 259:

/* Line 1455 of yacc.c  */
#line 1844 "sql.yacc"
    {
		(yyval.s_select)=(yyvsp[(2) - (2)].s_select);
		(yyval.s_select)->where_clause=(yyvsp[(1) - (2)].s_select_list_item);
	}
    break;

  case 260:

/* Line 1455 of yacc.c  */
#line 1850 "sql.yacc"
    {
		(yyval.s_select)=new_empty_select();
	}
    break;

  case 261:

/* Line 1455 of yacc.c  */
#line 1853 "sql.yacc"
    {
		(yyval.s_select)=new_empty_select();
		(yyval.s_select)->group_by=(yyvsp[(1) - (1)].s_select_list_item_list);
		(yyval.s_select)->having=0;
	}
    break;

  case 262:

/* Line 1455 of yacc.c  */
#line 1858 "sql.yacc"
    {
		(yyval.s_select)=new_empty_select();
		(yyval.s_select)->group_by=(yyvsp[(1) - (2)].s_select_list_item_list);
		(yyval.s_select)->having=(yyvsp[(2) - (2)].s_select_list_item);
	}
    break;

  case 263:

/* Line 1455 of yacc.c  */
#line 1863 "sql.yacc"
    {
		(yyval.s_select)=new_empty_select();
		(yyval.s_select)->group_by=0;
		(yyval.s_select)->having=(yyvsp[(1) - (1)].s_select_list_item);

	}
    break;

  case 264:

/* Line 1455 of yacc.c  */
#line 1876 "sql.yacc"
    {
		(yyval.s_select_list_item)=(yyvsp[(1) - (1)].s_select_list_item);
	}
    break;

  case 265:

/* Line 1455 of yacc.c  */
#line 1879 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_op_expr((yyvsp[(1) - (3)].s_select_list_item),(yyvsp[(3) - (3)].s_select_list_item)," OR ");
	}
    break;

  case 266:

/* Line 1455 of yacc.c  */
#line 1885 "sql.yacc"
    {
		(yyval.s_select_list_item)=(yyvsp[(1) - (1)].s_select_list_item);
	}
    break;

  case 267:

/* Line 1455 of yacc.c  */
#line 1888 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_op_expr((yyvsp[(1) - (3)].s_select_list_item),(yyvsp[(3) - (3)].s_select_list_item)," AND ");
	}
    break;

  case 268:

/* Line 1455 of yacc.c  */
#line 1894 "sql.yacc"
    {
		(yyval.s_select_list_item)=(yyvsp[(1) - (1)].s_select_list_item);
	}
    break;

  case 269:

/* Line 1455 of yacc.c  */
#line 1897 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_simple_expr(E_SLI_NOT,(yyvsp[(2) - (2)].s_select_list_item));
	}
    break;

  case 270:

/* Line 1455 of yacc.c  */
#line 1903 "sql.yacc"
    {
		(yyval.s_select_list_item)=(yyvsp[(1) - (1)].s_select_list_item);
	}
    break;

  case 271:

/* Line 1455 of yacc.c  */
#line 1906 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_simple_expr(E_SLI_BRACKET_EXPR,(yyvsp[(2) - (3)].s_select_list_item));
	}
    break;

  case 272:

/* Line 1455 of yacc.c  */
#line 1913 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_sq(E_SQE_EXISTS, (yyvsp[(2) - (2)].s_select_list_item));
		add_feature("WHERE_EXISTS");
	}
    break;

  case 273:

/* Line 1455 of yacc.c  */
#line 1917 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_sq(E_SQE_NOT_EXISTS, (yyvsp[(2) - (2)].s_select_list_item));
		add_feature("WHERE_EXISTS");
	}
    break;

  case 274:

/* Line 1455 of yacc.c  */
#line 1928 "sql.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 275:

/* Line 1455 of yacc.c  */
#line 1928 "sql.yacc"
    {SPRINTF1((yyval.str)," ESCAPE %s",(yyvsp[(2) - (2)].str));add_feature("WHERE_MATCHES_ESCAPE");}
    break;

  case 276:

/* Line 1455 of yacc.c  */
#line 1929 "sql.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 277:

/* Line 1455 of yacc.c  */
#line 1929 "sql.yacc"
    {SPRINTF1((yyval.str)," ESCAPE %s",(yyvsp[(2) - (2)].str));add_feature("WHERE_ILIKE_ESCAPE");}
    break;

  case 278:

/* Line 1455 of yacc.c  */
#line 1930 "sql.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 279:

/* Line 1455 of yacc.c  */
#line 1930 "sql.yacc"
    {SPRINTF1((yyval.str)," ESCAPE %s",(yyvsp[(2) - (2)].str));add_feature("WHERE_LIKE_ESCAPE");}
    break;

  case 280:

/* Line 1455 of yacc.c  */
#line 1933 "sql.yacc"
    {
		 (yyval.s_select_list_item)=(yyvsp[(1) - (1)].s_select_list_item);
	}
    break;

  case 282:

/* Line 1455 of yacc.c  */
#line 1943 "sql.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 283:

/* Line 1455 of yacc.c  */
#line 1944 "sql.yacc"
    {strcpy((yyval.str)," NOT ");}
    break;

  case 284:

/* Line 1455 of yacc.c  */
#line 1949 "sql.yacc"
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
#line 1958 "sql.yacc"
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
#line 1966 "sql.yacc"
    { 
			(yyval.s_select_list_item)=new_select_list_item_op_expr((yyvsp[(1) - (3)].s_select_list_item),(yyvsp[(3) - (3)].s_select_list_item),(yyvsp[(2) - (3)].str));
	}
    break;

  case 287:

/* Line 1455 of yacc.c  */
#line 1969 "sql.yacc"
    { 
			(yyval.s_select_list_item)=new_select_list_item_op_expr((yyvsp[(1) - (3)].s_select_list_item),(yyvsp[(3) - (3)].s_select_list_item),"=");
	}
    break;

  case 288:

/* Line 1455 of yacc.c  */
#line 1972 "sql.yacc"
    { 
			FPRINTF(stderr,"Warning: Corrected =NULL to IS NULL line %d\n",yylineno);
			(yyval.s_select_list_item)=new_select_list_item_simple_expr(E_SLI_ISNULL,(yyvsp[(1) - (3)].s_select_list_item));
	}
    break;

  case 289:

/* Line 1455 of yacc.c  */
#line 1976 "sql.yacc"
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
#line 1983 "sql.yacc"
    { 
			(yyval.s_select_list_item)=new_select_list_item_regex(E_SLI_REGEX_LIKE,(yyvsp[(1) - (4)].s_select_list_item),(yyvsp[(3) - (4)].s_select_list_item),(yyvsp[(4) - (4)].str));
	}
    break;

  case 291:

/* Line 1455 of yacc.c  */
#line 1986 "sql.yacc"
    { 
			(yyval.s_select_list_item)=new_select_list_item_regex(E_SLI_REGEX_NOT_LIKE,(yyvsp[(1) - (4)].s_select_list_item),(yyvsp[(3) - (4)].s_select_list_item),(yyvsp[(4) - (4)].str));

	}
    break;

  case 292:

/* Line 1455 of yacc.c  */
#line 1990 "sql.yacc"
    { 
			(yyval.s_select_list_item)=new_select_list_item_regex(E_SLI_REGEX_ILIKE,(yyvsp[(1) - (4)].s_select_list_item),(yyvsp[(3) - (4)].s_select_list_item),(yyvsp[(4) - (4)].str));
	}
    break;

  case 293:

/* Line 1455 of yacc.c  */
#line 1993 "sql.yacc"
    { 
			(yyval.s_select_list_item)=new_select_list_item_regex(E_SLI_REGEX_NOT_ILIKE,(yyvsp[(1) - (4)].s_select_list_item),(yyvsp[(3) - (4)].s_select_list_item),(yyvsp[(4) - (4)].str));
	}
    break;

  case 294:

/* Line 1455 of yacc.c  */
#line 1996 "sql.yacc"
    { 
			(yyval.s_select_list_item)=new_select_list_item_regex(E_SLI_REGEX_MATCHES,(yyvsp[(1) - (4)].s_select_list_item),(yyvsp[(3) - (4)].s_select_list_item),(yyvsp[(4) - (4)].str));
	}
    break;

  case 295:

/* Line 1455 of yacc.c  */
#line 1999 "sql.yacc"
    { 
			(yyval.s_select_list_item)=new_select_list_item_regex(E_SLI_REGEX_NOT_MATCHES,(yyvsp[(1) - (4)].s_select_list_item),(yyvsp[(3) - (4)].s_select_list_item),(yyvsp[(4) - (4)].str));
	}
    break;

  case 296:

/* Line 1455 of yacc.c  */
#line 2005 "sql.yacc"
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
#line 2012 "sql.yacc"
    {
			strcpy((yyval.str)," < ");
	}
    break;

  case 298:

/* Line 1455 of yacc.c  */
#line 2015 "sql.yacc"
    {
			strcpy((yyval.str)," > ");
	}
    break;

  case 299:

/* Line 1455 of yacc.c  */
#line 2018 "sql.yacc"
    {
			strcpy((yyval.str)," ~ ");
	}
    break;

  case 300:

/* Line 1455 of yacc.c  */
#line 2021 "sql.yacc"
    {strcpy((yyval.str)," <= ");}
    break;

  case 301:

/* Line 1455 of yacc.c  */
#line 2022 "sql.yacc"
    {strcpy((yyval.str)," >= ");}
    break;

  case 302:

/* Line 1455 of yacc.c  */
#line 2027 "sql.yacc"
    {
		(yyval.s_select_list_item)=(yyvsp[(1) - (1)].s_select_list_item);
	}
    break;

  case 303:

/* Line 1455 of yacc.c  */
#line 2030 "sql.yacc"
    {
		(yyval.s_select_list_item)=(yyvsp[(1) - (1)].s_select_list_item);
	}
    break;

  case 304:

/* Line 1455 of yacc.c  */
#line 2033 "sql.yacc"
    {
		(yyval.s_select_list_item)=(yyvsp[(1) - (1)].s_select_list_item);
	}
    break;

  case 305:

/* Line 1455 of yacc.c  */
#line 2036 "sql.yacc"
    {
                 (yyval.s_select_list_item)=(yyvsp[(1) - (1)].s_select_list_item);
        }
    break;

  case 306:

/* Line 1455 of yacc.c  */
#line 2043 "sql.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 307:

/* Line 1455 of yacc.c  */
#line 2044 "sql.yacc"
    {strcpy((yyval.str)," ALL "); add_feature("AGG_ALL");}
    break;

  case 308:

/* Line 1455 of yacc.c  */
#line 2045 "sql.yacc"
    {
		strcpy((yyval.str)," DISTINCT ");
		add_feature("AGG_DISTINCT");
	}
    break;

  case 309:

/* Line 1455 of yacc.c  */
#line 2049 "sql.yacc"
    {
		ansi_violation("Use DISTINCT not UNIQUE",0);
		strcpy((yyval.str)," DISTINCT ");
		add_feature("AGG_DISTINCT");
	}
    break;

  case 310:

/* Line 1455 of yacc.c  */
#line 2056 "sql.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 311:

/* Line 1455 of yacc.c  */
#line 2057 "sql.yacc"
    {strcpy((yyval.str)," ALL "); add_feature("UNION_ALL");}
    break;

  case 312:

/* Line 1455 of yacc.c  */
#line 2058 "sql.yacc"
    {
		strcpy((yyval.str)," DISTINCT ");
		add_feature("UNION_DISTINCT");
	}
    break;

  case 313:

/* Line 1455 of yacc.c  */
#line 2062 "sql.yacc"
    {
		ansi_violation("Use DISTINCT not UNIQUE",0);
		add_feature("UNION_DISTINCT");
		strcpy((yyval.str)," DISTINCT ");
	}
    break;

  case 314:

/* Line 1455 of yacc.c  */
#line 2076 "sql.yacc"
    {
		strcpy((yyval.str),A4GLSQLCV_dtype_alias((yyvsp[(1) - (1)].str)));
	}
    break;

  case 319:

/* Line 1455 of yacc.c  */
#line 2091 "sql.yacc"
    {SPRINTF4((yyval.str)," %s %s%s%s",(yyvsp[(1) - (4)].str),(yyvsp[(2) - (4)].str),(yyvsp[(3) - (4)].str),(yyvsp[(4) - (4)].str));}
    break;

  case 320:

/* Line 1455 of yacc.c  */
#line 2095 "sql.yacc"
    {strcpy((yyval.str),"SERIAL"); add_feature("DDL_SERIAL"); }
    break;

  case 321:

/* Line 1455 of yacc.c  */
#line 2096 "sql.yacc"
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
#line 2105 "sql.yacc"
    {strcpy((yyval.str),"SERIAL8"); add_feature("DDL_SERIAL8"); }
    break;

  case 323:

/* Line 1455 of yacc.c  */
#line 2107 "sql.yacc"
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
#line 2116 "sql.yacc"
    {
 			add_feature("DDL_DECIMAL");
	}
    break;

  case 325:

/* Line 1455 of yacc.c  */
#line 2119 "sql.yacc"
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
#line 2127 "sql.yacc"
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
#line 2137 "sql.yacc"
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
#line 2145 "sql.yacc"
    {strcpy((yyval.str),"DATE");
 			add_feature("DDL_DATE"); }
    break;

  case 329:

/* Line 1455 of yacc.c  */
#line 2147 "sql.yacc"
    {strcpy((yyval.str),"INTEGER");}
    break;

  case 330:

/* Line 1455 of yacc.c  */
#line 2148 "sql.yacc"
    {strcpy((yyval.str),"SMALLINT");}
    break;

  case 331:

/* Line 1455 of yacc.c  */
#line 2149 "sql.yacc"
    {strcpy((yyval.str),"NCHAR"); add_feature("DDL_NCHAR");}
    break;

  case 332:

/* Line 1455 of yacc.c  */
#line 2150 "sql.yacc"
    {SPRINTF1((yyval.str),"NCHAR(%s)",(yyvsp[(3) - (4)].str)); add_feature("DDL_NCHAR");}
    break;

  case 333:

/* Line 1455 of yacc.c  */
#line 2151 "sql.yacc"
    {add_feature("DDL_NVARCHAR");}
    break;

  case 334:

/* Line 1455 of yacc.c  */
#line 2152 "sql.yacc"
    {SPRINTF1((yyval.str),"NVARCHAR(%s)",(yyvsp[(3) - (4)].str)); add_feature("DDL_NVARCHAR");}
    break;

  case 335:

/* Line 1455 of yacc.c  */
#line 2153 "sql.yacc"
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
#line 2161 "sql.yacc"
    {SPRINTF2((yyval.str),"DATETIME %s TO %s",(yyvsp[(2) - (4)].str),(yyvsp[(4) - (4)].str)); add_feature("DDL_DATETIME");}
    break;

  case 337:

/* Line 1455 of yacc.c  */
#line 2162 "sql.yacc"
    {add_feature("DDL_DATETIME");}
    break;

  case 338:

/* Line 1455 of yacc.c  */
#line 2163 "sql.yacc"
    {SPRINTF2((yyval.str),"INTERVAL %s TO %s",(yyvsp[(2) - (4)].str),(yyvsp[(4) - (4)].str)); add_feature("DDL_INTERVAL");}
    break;

  case 339:

/* Line 1455 of yacc.c  */
#line 2164 "sql.yacc"
    {strcpy((yyval.str),(yyvsp[(1) - (1)].str));}
    break;

  case 340:

/* Line 1455 of yacc.c  */
#line 2165 "sql.yacc"
    {add_feature("DDL_INTERVAL");}
    break;

  case 341:

/* Line 1455 of yacc.c  */
#line 2166 "sql.yacc"
    {SPRINTF3((yyval.str),"INTERVAL %s(%s) TO %s",(yyvsp[(2) - (7)].str),(yyvsp[(4) - (7)].str),(yyvsp[(7) - (7)].str)); add_feature("DDL_INTERVAL");}
    break;

  case 342:

/* Line 1455 of yacc.c  */
#line 2167 "sql.yacc"
    {add_feature("DDL_TEXT");}
    break;

  case 343:

/* Line 1455 of yacc.c  */
#line 2168 "sql.yacc"
    {add_feature("DDL_BYTE");}
    break;

  case 344:

/* Line 1455 of yacc.c  */
#line 2169 "sql.yacc"
    {add_feature("DDL_VARCHAR");}
    break;

  case 345:

/* Line 1455 of yacc.c  */
#line 2170 "sql.yacc"
    {SPRINTF1((yyval.str),"VARCHAR(%s)",(yyvsp[(3) - (4)].str));add_feature("DDL_VARCHAR");}
    break;

  case 346:

/* Line 1455 of yacc.c  */
#line 2171 "sql.yacc"
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
#line 2181 "sql.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 348:

/* Line 1455 of yacc.c  */
#line 2182 "sql.yacc"
    {
		SPRINTF1((yyval.str),",%s",(yyvsp[(2) - (2)].str));
}
    break;

  case 349:

/* Line 1455 of yacc.c  */
#line 2189 "sql.yacc"
    {SPRINTF4((yyval.str)," %s %s %s %s",(yyvsp[(1) - (4)].str),(yyvsp[(2) - (4)].str),(yyvsp[(3) - (4)].str),(yyvsp[(4) - (4)].str));}
    break;

  case 353:

/* Line 1455 of yacc.c  */
#line 2193 "sql.yacc"
    {add_feature("DDL_DOUBLE_PRECISION"); SPRINTF1((yyval.str)," %s",(yyvsp[(1) - (1)].str));}
    break;

  case 359:

/* Line 1455 of yacc.c  */
#line 2218 "sql.yacc"
    {(yyval.int_list.i0)=0;}
    break;

  case 360:

/* Line 1455 of yacc.c  */
#line 2219 "sql.yacc"
    {
		(yyval.int_list.i0)=1;
		(yyval.int_list.i1)=atoi((yyvsp[(2) - (3)].str));
	}
    break;

  case 361:

/* Line 1455 of yacc.c  */
#line 2223 "sql.yacc"
    {
		(yyval.int_list.i0)=2;
		(yyval.int_list.i1)=atoi((yyvsp[(2) - (5)].str));
		(yyval.int_list.i2)=atoi((yyvsp[(4) - (5)].str));
	}
    break;

  case 362:

/* Line 1455 of yacc.c  */
#line 2231 "sql.yacc"
    {
		strcpy((yyval.str),(yyvsp[(1) - (1)].str));
	}
    break;

  case 363:

/* Line 1455 of yacc.c  */
#line 2234 "sql.yacc"
    {
		strcpy((yyval.str),(yyvsp[(2) - (2)].str));
	}
    break;

  case 364:

/* Line 1455 of yacc.c  */
#line 2241 "sql.yacc"
    {
		(yyval.s_select_list_item)= (yyvsp[(1) - (1)].s_select_list_item);
	}
    break;

  case 365:

/* Line 1455 of yacc.c  */
#line 2244 "sql.yacc"
    {
		(yyval.s_select_list_item)= (yyvsp[(2) - (2)].s_select_list_item);
	}
    break;

  case 366:

/* Line 1455 of yacc.c  */
#line 2254 "sql.yacc"
    { 
		(yyval.s_select_list_item)=new_select_list_item_col(0,(yyvsp[(1) - (2)].str),&(yyvsp[(2) - (2)].int_list));
	}
    break;

  case 367:

/* Line 1455 of yacc.c  */
#line 2257 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_col((yyvsp[(1) - (4)].str),(yyvsp[(3) - (4)].str),&(yyvsp[(4) - (4)].int_list));
	}
    break;

  case 368:

/* Line 1455 of yacc.c  */
#line 2260 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_col((yyvsp[(1) - (3)].str),"*",0);
	}
    break;

  case 369:

/* Line 1455 of yacc.c  */
#line 2263 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_col(0,"rowid",0);
	}
    break;

  case 370:

/* Line 1455 of yacc.c  */
#line 2270 "sql.yacc"
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
#line 2277 "sql.yacc"
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
#line 2285 "sql.yacc"
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
#line 2294 "sql.yacc"
    {
		SPRINTF1((yyval.str),"%s",A4GLSQLCV_check_colname((yyvsp[(1) - (3)].str),"*"));
		ADDMAP("Use Column",(yyval.str));
	}
    break;

  case 375:

/* Line 1455 of yacc.c  */
#line 2305 "sql.yacc"
    { strcpy((yyval.str),(yyvsp[(1) - (1)].str)); 
#ifdef DEBUG
A4GL_debug("Set $<str>$ to %s\n",(yyval.str)); 
#endif
}
    break;

  case 379:

/* Line 1455 of yacc.c  */
#line 2317 "sql.yacc"
    { strcpy((yyval.str),A4GLSQLCV_generate_current(0,0)); 
}
    break;

  case 380:

/* Line 1455 of yacc.c  */
#line 2319 "sql.yacc"
    {
		strcpy((yyval.str),A4GLSQLCV_generate_current((yyvsp[(1) - (3)].str),(yyvsp[(3) - (3)].str)));
	}
    break;

  case 395:

/* Line 1455 of yacc.c  */
#line 2329 "sql.yacc"
    {SPRINTF1((yyval.str),"FRACTION(%s)",(yyvsp[(3) - (4)].str));}
    break;

  case 396:

/* Line 1455 of yacc.c  */
#line 2374 "sql.yacc"
    { (yyval.sql_string)=make_sql_string_and_free(acl_strdup((yyvsp[(1) - (1)].str)), NULL);}
    break;

  case 397:

/* Line 1455 of yacc.c  */
#line 2375 "sql.yacc"
    { (yyval.sql_string)=make_sql_string_and_free(acl_strdup((yyvsp[(1) - (1)].str)), NULL);}
    break;

  case 398:

/* Line 1455 of yacc.c  */
#line 2376 "sql.yacc"
    { (yyval.sql_string)=make_sql_string_and_free(acl_strdup((yyvsp[(1) - (1)].str)), NULL);}
    break;

  case 399:

/* Line 1455 of yacc.c  */
#line 2381 "sql.yacc"
    { add_feature("RENAME_TABLE"); strcpy((yyval.str),A4GLSQLCV_rentab((yyvsp[(2) - (4)].str),(yyvsp[(4) - (4)].str))); }
    break;

  case 400:

/* Line 1455 of yacc.c  */
#line 2382 "sql.yacc"
    { add_feature("RENAME_COLUMN"); strcpy((yyval.str),A4GLSQLCV_rencol((yyvsp[(2) - (6)].str),(yyvsp[(4) - (6)].str),(yyvsp[(6) - (6)].str)) ); }
    break;

  case 403:

/* Line 1455 of yacc.c  */
#line 2390 "sql.yacc"
    {
		add_feature("UNLOCK_TABLE");
		SPRINTF2((yyval.str),"%s %s",(yyvsp[(1) - (2)].str),(yyvsp[(2) - (2)].str));
	}
    break;

  case 404:

/* Line 1455 of yacc.c  */
#line 2397 "sql.yacc"
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

/* Line 1455 of yacc.c  */
#line 2408 "sql.yacc"
    { add_feature("LOCK_TABLE_SHARED");}
    break;

  case 406:

/* Line 1455 of yacc.c  */
#line 2409 "sql.yacc"
    {add_feature("LOCK_TABLE_EXCLUSIVE");}
    break;

  case 407:

/* Line 1455 of yacc.c  */
#line 2422 "sql.yacc"
    {strcpy((yyval.str),A4GLSQLCV_datetime_value((yyvsp[(1) - (1)].str)));}
    break;

  case 408:

/* Line 1455 of yacc.c  */
#line 2423 "sql.yacc"
    {strcpy((yyval.str),A4GLSQLCV_make_dtime_extend((yyvsp[(1) - (4)].str),(yyvsp[(2) - (4)].str),(yyvsp[(4) - (4)].str),0));}
    break;

  case 409:

/* Line 1455 of yacc.c  */
#line 2427 "sql.yacc"
    {strcpy((yyval.str),(yyvsp[(1) - (1)].str));}
    break;

  case 410:

/* Line 1455 of yacc.c  */
#line 2431 "sql.yacc"
    {strcpy((yyval.str),A4GLSQLCV_interval_value((yyvsp[(1) - (1)].str)));}
    break;

  case 411:

/* Line 1455 of yacc.c  */
#line 2432 "sql.yacc"
    {
			strcpy((yyval.str),A4GLSQLCV_make_ival_extend((yyvsp[(1) - (7)].str),(yyvsp[(2) - (7)].str),(yyvsp[(4) - (7)].str),(yyvsp[(7) - (7)].str),0));
		}
    break;

  case 412:

/* Line 1455 of yacc.c  */
#line 2435 "sql.yacc"
    {
		strcpy((yyval.str),A4GLSQLCV_make_ival_extend((yyvsp[(1) - (4)].str),(yyvsp[(2) - (4)].str),(char *)0, (yyvsp[(4) - (4)].str),0));
	}
    break;

  case 413:

/* Line 1455 of yacc.c  */
#line 2441 "sql.yacc"
    {SPRINTF1((yyval.str),"%s",(yyvsp[(1) - (1)].str));}
    break;

  case 414:

/* Line 1455 of yacc.c  */
#line 2445 "sql.yacc"
    {
	strcpy((yyval.str),(yyvsp[(2) - (2)].str));
}
    break;

  case 415:

/* Line 1455 of yacc.c  */
#line 2468 "sql.yacc"
    {
		(yyval.s_select_list_item_list)=(yyvsp[(3) - (3)].s_select_list_item_list);
		add_feature("ORDER_BY");
	}
    break;

  case 416:

/* Line 1455 of yacc.c  */
#line 2478 "sql.yacc"
    {
			(yyval.s_select_list_item_list)=local_new_select_list_item_list((yyvsp[(1) - (1)].s_select_list_item));
	}
    break;

  case 417:

/* Line 1455 of yacc.c  */
#line 2481 "sql.yacc"
    {
			(yyval.s_select_list_item_list)=local_add_select_list_item_list((yyvsp[(1) - (3)].s_select_list_item_list),(yyvsp[(3) - (3)].s_select_list_item));
	}
    break;

  case 418:

/* Line 1455 of yacc.c  */
#line 2487 "sql.yacc"
    {
		if (strcmp((yyvsp[(2) - (2)].str),"DESC")!=0) {
			(yyval.s_select_list_item)=new_select_list_item_simple_expr(E_SLI_ASC,(yyvsp[(1) - (2)].s_select_list_item));
		} else {
			(yyval.s_select_list_item)=new_select_list_item_simple_expr(E_SLI_DESC,(yyvsp[(1) - (2)].s_select_list_item));
		}
	}
    break;

  case 419:

/* Line 1455 of yacc.c  */
#line 2496 "sql.yacc"
    { 
		add_feature("ORDER_BY_NUMBER");
		(yyval.s_select_list_item)=new_select_list_item_literal((yyvsp[(1) - (1)].str));
	}
    break;

  case 420:

/* Line 1455 of yacc.c  */
#line 2500 "sql.yacc"
    {
		(yyval.s_select_list_item)=(yyvsp[(1) - (1)].s_select_list_item);
		(yyval.s_select_list_item)->data.type=E_SLI_COLUMN_ORDERBY;
	}
    break;

  case 421:

/* Line 1455 of yacc.c  */
#line 2507 "sql.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 422:

/* Line 1455 of yacc.c  */
#line 2509 "sql.yacc"
    {add_feature("ORDER_BY_ASC"); strcpy((yyval.str),"ASC");}
    break;

  case 423:

/* Line 1455 of yacc.c  */
#line 2511 "sql.yacc"
    {add_feature("ORDER_BY_DESC"); strcpy((yyval.str),"DESC");}
    break;

  case 424:

/* Line 1455 of yacc.c  */
#line 2515 "sql.yacc"
    {
		(yyval.s_select_list_item_list)=(yyvsp[(2) - (2)].s_select_list_item_list);
	}
    break;

  case 425:

/* Line 1455 of yacc.c  */
#line 2521 "sql.yacc"
    {
			(yyval.s_select_list_item_list)=local_new_select_list_item_list((yyvsp[(1) - (1)].s_select_list_item));
	}
    break;

  case 426:

/* Line 1455 of yacc.c  */
#line 2524 "sql.yacc"
    {
			(yyval.s_select_list_item_list)=local_add_select_list_item_list((yyvsp[(1) - (3)].s_select_list_item_list),(yyvsp[(3) - (3)].s_select_list_item));
	}
    break;

  case 427:

/* Line 1455 of yacc.c  */
#line 2530 "sql.yacc"
    { (yyval.s_select_list_item)=(yyvsp[(1) - (1)].s_select_list_item); }
    break;

  case 428:

/* Line 1455 of yacc.c  */
#line 2531 "sql.yacc"
    { (yyval.s_select_list_item)=new_select_list_item_literal((yyvsp[(1) - (1)].str)); }
    break;

  case 429:

/* Line 1455 of yacc.c  */
#line 2538 "sql.yacc"
    {
	(yyval.sql_string)=get_select_list_item(0,(yyvsp[(1) - (1)].s_select_list_item));
}
    break;

  case 430:

/* Line 1455 of yacc.c  */
#line 2551 "sql.yacc"
    {
		A4GL_set_sql_lineno(yylineno);
		(yyval.sql_string)=make_select_stmt_v2(current_upd_table, (yyvsp[(1) - (1)].s_select),"");
		map_select_stmt("SELECT",(yyvsp[(1) - (1)].s_select));
		A4GL_free_select_stmt((yyvsp[(1) - (1)].s_select));
}
    break;

  case 431:

/* Line 1455 of yacc.c  */
#line 2561 "sql.yacc"
    { 
	if (A4GLSQLCV_check_requirement("ALLOW_TIME_DATATYPE")) {
       		strcpy((yyval.str),"TIME"); break;
	} else {
       		strcpy((yyval.str),"DATETIME HOUR TO FRACTION(2)"); break;
	}
 }
    break;

  case 432:

/* Line 1455 of yacc.c  */
#line 2568 "sql.yacc"
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

/* Line 1455 of yacc.c  */
#line 2585 "sql.yacc"
    {
	if (A4GLSQLCV_check_requirement("ALLOW_TIMESTAMP_DATATYPE")) {
		strcpy((yyval.str),"TIMESTAMP");
	} else {
                strcpy((yyval.str),"DATETIME YEAR TO FRACTION(2)"); 
	}
 }
    break;

  case 434:

/* Line 1455 of yacc.c  */
#line 2592 "sql.yacc"
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

/* Line 1455 of yacc.c  */
#line 2617 "sql.yacc"
    { 
		//start_bind('i',0);
		 set_ignore_indicators();}
    break;

  case 436:

/* Line 1455 of yacc.c  */
#line 2619 "sql.yacc"
    { clr_ignore_indicators();}
    break;

  case 437:

/* Line 1455 of yacc.c  */
#line 2621 "sql.yacc"
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

/* Line 1455 of yacc.c  */
#line 2642 "sql.yacc"
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

/* Line 1455 of yacc.c  */
#line 2685 "sql.yacc"
    { (yyval.s_select)=0;}
    break;

  case 440:

/* Line 1455 of yacc.c  */
#line 2686 "sql.yacc"
    { 
		(yyval.s_select)=(yyvsp[(3) - (3)].s_select);
		(yyval.s_select)->union_op=acl_strdup((yyvsp[(2) - (3)].str));
		A4GL_set_associated_mem((yyval.s_select), (yyval.s_select)->union_op);
		add_feature("SELECT_UNION"); 
	}
    break;

  case 441:

/* Line 1455 of yacc.c  */
#line 2700 "sql.yacc"
    {
		(yyval.s_select_finish)=0;
	}
    break;

  case 442:

/* Line 1455 of yacc.c  */
#line 2703 "sql.yacc"
    {  
		(yyval.s_select_finish)=acl_malloc2(sizeof(struct s_select_finish));
		(yyval.s_select_finish)->order_by=(yyvsp[(1) - (1)].s_select_list_item_list);
		(yyval.s_select_finish)->insert_into=0;
		(yyval.s_select_finish)->into_temp=0;
		(yyval.s_select_finish)->nolog=0;
	}
    break;

  case 443:

/* Line 1455 of yacc.c  */
#line 2710 "sql.yacc"
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

/* Line 1455 of yacc.c  */
#line 2720 "sql.yacc"
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

/* Line 1455 of yacc.c  */
#line 2738 "sql.yacc"
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

/* Line 1455 of yacc.c  */
#line 2751 "sql.yacc"
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

/* Line 1455 of yacc.c  */
#line 2766 "sql.yacc"
    {(yyval.integer_val)=-1;}
    break;

  case 449:

/* Line 1455 of yacc.c  */
#line 2768 "sql.yacc"
    {
		(yyval.integer_val)=atol((yyvsp[(2) - (2)].str));
	}
    break;

  case 450:

/* Line 1455 of yacc.c  */
#line 2774 "sql.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 451:

/* Line 1455 of yacc.c  */
#line 2775 "sql.yacc"
    {strcpy((yyval.str),"ALL"); add_feature("SELECT_ALL");}
    break;

  case 452:

/* Line 1455 of yacc.c  */
#line 2776 "sql.yacc"
    {strcpy((yyval.str),"DISTINCT"); add_feature("SELECT_DISTINCT");}
    break;

  case 453:

/* Line 1455 of yacc.c  */
#line 2777 "sql.yacc"
    {strcpy((yyval.str),"DISTINCT");
		add_feature("SELECT_UNIQUE");
		ansi_violation("Use DISTINCT not UNIQUE",0);
		strcpy((yyval.str),"DISTINCT");
	}
    break;

  case 454:

/* Line 1455 of yacc.c  */
#line 2787 "sql.yacc"
    { 
		 (yyval.s_select_list_item_list)=local_new_select_list_item_list((yyvsp[(1) - (1)].s_select_list_item));
	}
    break;

  case 455:

/* Line 1455 of yacc.c  */
#line 2790 "sql.yacc"
    { 
		(yyval.s_select_list_item_list)=local_add_select_list_item_list((yyvsp[(1) - (3)].s_select_list_item_list),(yyvsp[(3) - (3)].s_select_list_item));
	}
    break;

  case 456:

/* Line 1455 of yacc.c  */
#line 2796 "sql.yacc"
    {
		(yyval.s_select_list_item)=(yyvsp[(1) - (1)].s_select_list_item);
	}
    break;

  case 457:

/* Line 1455 of yacc.c  */
#line 2799 "sql.yacc"
    {
		(yyval.s_select_list_item)=(yyvsp[(1) - (2)].s_select_list_item);
		(yyval.s_select_list_item)->alias=acl_strdup((yyvsp[(2) - (2)].str));
		A4GL_set_associated_mem((yyval.s_select_list_item), (yyval.s_select_list_item)->alias);
	}
    break;

  case 458:

/* Line 1455 of yacc.c  */
#line 2804 "sql.yacc"
    {
		(yyval.s_select_list_item)=(yyvsp[(1) - (3)].s_select_list_item);
		(yyval.s_select_list_item)->alias=acl_strdup((yyvsp[(3) - (3)].str));
		A4GL_set_associated_mem((yyval.s_select_list_item), (yyval.s_select_list_item)->alias);
	}
    break;

  case 459:

/* Line 1455 of yacc.c  */
#line 2813 "sql.yacc"
    {
		(yyval.s_select_list_item)=(yyvsp[(1) - (1)].s_select_list_item); /* A4GLSQLCV_check_expr($<sql_string>1) */
	}
    break;

  case 460:

/* Line 1455 of yacc.c  */
#line 2816 "sql.yacc"
    {
		(yyval.s_select_list_item)=(yyvsp[(2) - (2)].s_select_list_item);
		(yyval.s_select_list_item)->sign='-';
	}
    break;

  case 461:

/* Line 1455 of yacc.c  */
#line 2820 "sql.yacc"
    {
		(yyval.s_select_list_item)=(yyvsp[(2) - (2)].s_select_list_item);
	}
    break;

  case 462:

/* Line 1455 of yacc.c  */
#line 2827 "sql.yacc"
    {
			(yyval.s_select_list_item)=new_select_list_item_op_expr ((yyvsp[(1) - (3)].s_select_list_item), (yyvsp[(3) - (3)].s_select_list_item), "/");
	}
    break;

  case 463:

/* Line 1455 of yacc.c  */
#line 2830 "sql.yacc"
    {
			(yyval.s_select_list_item)=new_select_list_item_simple_expr((enum e_sli)(yyvsp[(2) - (2)].integer_val), (yyvsp[(1) - (2)].s_select_list_item));
	}
    break;

  case 464:

/* Line 1455 of yacc.c  */
#line 2833 "sql.yacc"
    {
			(yyval.s_select_list_item)=new_select_list_item_op_expr ((yyvsp[(1) - (3)].s_select_list_item), (yyvsp[(3) - (3)].s_select_list_item), "*");
	}
    break;

  case 465:

/* Line 1455 of yacc.c  */
#line 2836 "sql.yacc"
    {
			(yyval.s_select_list_item)=new_select_list_item_op_expr ((yyvsp[(1) - (3)].s_select_list_item), (yyvsp[(3) - (3)].s_select_list_item), "+");
	}
    break;

  case 466:

/* Line 1455 of yacc.c  */
#line 2839 "sql.yacc"
    {
			(yyval.s_select_list_item)=new_select_list_item_op_expr ((yyvsp[(1) - (3)].s_select_list_item), (yyvsp[(3) - (3)].s_select_list_item), "-");
	}
    break;

  case 467:

/* Line 1455 of yacc.c  */
#line 2842 "sql.yacc"
    {
			(yyval.s_select_list_item)=new_select_list_item_op_expr ((yyvsp[(1) - (3)].s_select_list_item), (yyvsp[(3) - (3)].s_select_list_item), "||");
	}
    break;

  case 468:

/* Line 1455 of yacc.c  */
#line 2845 "sql.yacc"
    { (yyval.s_select_list_item)=new_select_list_item_literal((yyvsp[(1) - (1)].str)); }
    break;

  case 469:

/* Line 1455 of yacc.c  */
#line 2846 "sql.yacc"
    { (yyval.s_select_list_item)=new_select_list_item_builtin_const(E_SLI_BUILTIN_CONST_TRUE); }
    break;

  case 470:

/* Line 1455 of yacc.c  */
#line 2847 "sql.yacc"
    { (yyval.s_select_list_item)=new_select_list_item_builtin_const(E_SLI_BUILTIN_CONST_FALSE); }
    break;

  case 471:

/* Line 1455 of yacc.c  */
#line 2848 "sql.yacc"
    { (yyval.s_select_list_item)=new_select_list_item_builtin_const(E_SLI_BUILTIN_CONST_USER); }
    break;

  case 472:

/* Line 1455 of yacc.c  */
#line 2849 "sql.yacc"
    { (yyval.s_select_list_item)=new_select_list_item_builtin_const(E_SLI_BUILTIN_CONST_TODAY); }
    break;

  case 473:

/* Line 1455 of yacc.c  */
#line 2850 "sql.yacc"
    { (yyval.s_select_list_item)=new_select_list_item_builtin_const(E_SLI_BUILTIN_CONST_ROWID); }
    break;

  case 474:

/* Line 1455 of yacc.c  */
#line 2851 "sql.yacc"
    { (yyval.s_select_list_item)=new_select_list_item_builtin_const(E_SLI_BUILTIN_CONST_TIME); }
    break;

  case 475:

/* Line 1455 of yacc.c  */
#line 2852 "sql.yacc"
    { (yyval.s_select_list_item)=new_select_list_item_builtin_const(E_SLI_BUILTIN_CONST_STAR); }
    break;

  case 476:

/* Line 1455 of yacc.c  */
#line 2853 "sql.yacc"
    { (yyval.s_select_list_item)=new_select_list_item_builtin_const(E_SLI_BUILTIN_CONST_COUNT_STAR); }
    break;

  case 477:

/* Line 1455 of yacc.c  */
#line 2855 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_agg1(E_SLI_BUILTIN_AGG_AVG,(yyvsp[(3) - (5)].str),(yyvsp[(4) - (5)].s_select_list_item));
		add_feature("SELECT_AVG");
	}
    break;

  case 478:

/* Line 1455 of yacc.c  */
#line 2859 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_agg1(E_SLI_BUILTIN_AGG_MAX,(yyvsp[(3) - (5)].str),(yyvsp[(4) - (5)].s_select_list_item));
		add_feature("SELECT_MAX");
	}
    break;

  case 479:

/* Line 1455 of yacc.c  */
#line 2863 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_agg1(E_SLI_BUILTIN_AGG_MIN,(yyvsp[(3) - (5)].str),(yyvsp[(4) - (5)].s_select_list_item));
		add_feature("SELECT_MIN");
	}
    break;

  case 480:

/* Line 1455 of yacc.c  */
#line 2867 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_agg1(E_SLI_BUILTIN_AGG_SUM,(yyvsp[(3) - (5)].str),(yyvsp[(4) - (5)].s_select_list_item));
		add_feature("SELECT_SUM");
	}
    break;

  case 481:

/* Line 1455 of yacc.c  */
#line 2871 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_agg1(E_SLI_BUILTIN_AGG_COUNT,(yyvsp[(3) - (5)].str),(yyvsp[(4) - (5)].s_select_list_item));
		add_feature("SELECT_COUNT");
	}
    break;

  case 482:

/* Line 1455 of yacc.c  */
#line 2875 "sql.yacc"
    {
		add_sql_function((yyvsp[(1) - (3)].str));
		(yyval.s_select_list_item)=new_select_list_item_fcall((yyvsp[(1) - (3)].str),0);
	}
    break;

  case 483:

/* Line 1455 of yacc.c  */
#line 2879 "sql.yacc"
    {
		add_sql_function((yyvsp[(1) - (4)].str));
		(yyval.s_select_list_item)=new_select_list_item_fcall((yyvsp[(1) - (4)].str),(yyvsp[(3) - (4)].s_select_list_item_list));
	}
    break;

  case 484:

/* Line 1455 of yacc.c  */
#line 2883 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_builtin_fcall(E_SLI_BUILTIN_FUNC_YEAR,(yyvsp[(3) - (4)].s_select_list_item_list));
	}
    break;

  case 485:

/* Line 1455 of yacc.c  */
#line 2886 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_builtin_fcall(E_SLI_BUILTIN_FUNC_MONTH,(yyvsp[(3) - (4)].s_select_list_item_list));
	}
    break;

  case 486:

/* Line 1455 of yacc.c  */
#line 2889 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_builtin_fcall(E_SLI_BUILTIN_FUNC_DAY,(yyvsp[(3) - (4)].s_select_list_item_list));
	}
    break;

  case 487:

/* Line 1455 of yacc.c  */
#line 2892 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_builtin_fcall(E_SLI_BUILTIN_FUNC_MDY,(yyvsp[(3) - (4)].s_select_list_item_list));
	}
    break;

  case 488:

/* Line 1455 of yacc.c  */
#line 2895 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_builtin_fcall(E_SLI_BUILTIN_FUNC_WEEKDAY,(yyvsp[(3) - (4)].s_select_list_item_list));
	}
    break;

  case 489:

/* Line 1455 of yacc.c  */
#line 2898 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_builtin_fcall(E_SLI_BUILTIN_FUNC_DOW,(yyvsp[(3) - (4)].s_select_list_item_list));
	}
    break;

  case 490:

/* Line 1455 of yacc.c  */
#line 2901 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_builtin_fcall(E_SLI_BUILTIN_FUNC_DATE,(yyvsp[(3) - (4)].s_select_list_item_list));
	}
    break;

  case 491:

/* Line 1455 of yacc.c  */
#line 2904 "sql.yacc"
    {
		  (yyval.s_select_list_item)=new_select_list_item_simple_expr(E_SLI_BRACKET_EXPR,(yyvsp[(2) - (3)].s_select_list_item));
	}
    break;

  case 492:

/* Line 1455 of yacc.c  */
#line 2907 "sql.yacc"
    { 
		add_feature("EXTEND"); 
		(yyval.s_select_list_item)=(yyvsp[(3) - (4)].s_select_list_item);
	}
    break;

  case 493:

/* Line 1455 of yacc.c  */
#line 2911 "sql.yacc"
    { 
		(yyval.s_select_list_item)=new_select_list_item_datetime((yyvsp[(1) - (1)].str));
		add_feature("FUNC_DATETIME");
	}
    break;

  case 494:

/* Line 1455 of yacc.c  */
#line 2915 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_interval((yyvsp[(1) - (1)].str));
		add_feature("FUNC_INTERVAL");
	}
    break;

  case 495:

/* Line 1455 of yacc.c  */
#line 2919 "sql.yacc"
    {
		(yyval.s_select_list_item)=(yyvsp[(2) - (3)].s_select_list_item);
	}
    break;

  case 496:

/* Line 1455 of yacc.c  */
#line 2927 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_case((yyvsp[(1) - (1)].s_select_list_item));
	}
    break;

  case 497:

/* Line 1455 of yacc.c  */
#line 2930 "sql.yacc"
    {
		(yyval.s_select_list_item)=append_select_list_item_case(
							(yyvsp[(1) - (2)].s_select_list_item),
							(yyvsp[(2) - (2)].s_select_list_item));
	}
    break;

  case 498:

/* Line 1455 of yacc.c  */
#line 2939 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_case_element(
				(yyvsp[(2) - (4)].s_select_list_item),
				(yyvsp[(4) - (4)].s_select_list_item));

	}
    break;

  case 499:

/* Line 1455 of yacc.c  */
#line 2945 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_case_element( 0, (yyvsp[(2) - (2)].s_select_list_item));
	}
    break;

  case 500:

/* Line 1455 of yacc.c  */
#line 2952 "sql.yacc"
    {
		(yyval.s_select_list_item_list)=local_new_select_list_item_list((yyvsp[(1) - (1)].s_select_list_item));
	}
    break;

  case 501:

/* Line 1455 of yacc.c  */
#line 2955 "sql.yacc"
    {
			(yyval.s_select_list_item_list)=local_add_select_list_item_list((yyvsp[(1) - (3)].s_select_list_item_list),(yyvsp[(3) - (3)].s_select_list_item));
	}
    break;

  case 502:

/* Line 1455 of yacc.c  */
#line 2983 "sql.yacc"
    {
			(yyval.s_select_list_item)=new_select_list_item_extend(new_select_list_item_builtin_const(E_SLI_BUILTIN_CONST_CURRENT),(yyvsp[(3) - (5)].str),(yyvsp[(5) - (5)].str));
	}
    break;

  case 503:

/* Line 1455 of yacc.c  */
#line 2986 "sql.yacc"
    {
			(yyval.s_select_list_item)=new_select_list_item_extend((yyvsp[(1) - (5)].s_select_list_item),(yyvsp[(3) - (5)].str),(yyvsp[(5) - (5)].str));
	}
    break;

  case 504:

/* Line 1455 of yacc.c  */
#line 2989 "sql.yacc"
    {
			(yyval.s_select_list_item)=new_select_list_item_extend(new_select_list_item_builtin_const(E_SLI_BUILTIN_CONST_CURRENT),(yyvsp[(2) - (4)].str),(yyvsp[(4) - (4)].str));
	}
    break;

  case 505:

/* Line 1455 of yacc.c  */
#line 2992 "sql.yacc"
    {
			(yyval.s_select_list_item)=new_select_list_item_extend((yyvsp[(1) - (5)].s_select_list_item),(yyvsp[(3) - (5)].str),(yyvsp[(5) - (5)].str));
	}
    break;

  case 506:

/* Line 1455 of yacc.c  */
#line 2998 "sql.yacc"
    {(yyval.integer_val)=E_SLI_UNITS_YEAR;}
    break;

  case 507:

/* Line 1455 of yacc.c  */
#line 2999 "sql.yacc"
    {(yyval.integer_val)=E_SLI_UNITS_MONTH;}
    break;

  case 508:

/* Line 1455 of yacc.c  */
#line 3000 "sql.yacc"
    {(yyval.integer_val)=E_SLI_UNITS_DAY;}
    break;

  case 509:

/* Line 1455 of yacc.c  */
#line 3001 "sql.yacc"
    {(yyval.integer_val)=E_SLI_UNITS_HOUR;}
    break;

  case 510:

/* Line 1455 of yacc.c  */
#line 3002 "sql.yacc"
    {(yyval.integer_val)=E_SLI_UNITS_MINUTE;}
    break;

  case 511:

/* Line 1455 of yacc.c  */
#line 3003 "sql.yacc"
    {(yyval.integer_val)=E_SLI_UNITS_SECOND;}
    break;

  case 512:

/* Line 1455 of yacc.c  */
#line 3008 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_op_slil((yyvsp[(1) - (5)].s_select_list_item),(yyvsp[(4) - (5)].s_select_list_item_list),E_SLI_IN_VALUES);
                add_feature("WHERE_IN");
        }
    break;

  case 513:

/* Line 1455 of yacc.c  */
#line 3012 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_op_sli((yyvsp[(1) - (3)].s_select_list_item),(yyvsp[(3) - (3)].s_select_list_item),E_SLI_IN_SELECT);
                add_feature("WHERE_IN_SELECT");
        }
    break;

  case 514:

/* Line 1455 of yacc.c  */
#line 3016 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_op_slil((yyvsp[(1) - (5)].s_select_list_item),(yyvsp[(4) - (5)].s_select_list_item_list),E_SLI_NOT_IN_VALUES);
                add_feature("WHERE_IN");
        }
    break;

  case 515:

/* Line 1455 of yacc.c  */
#line 3020 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_op_sli((yyvsp[(1) - (3)].s_select_list_item),(yyvsp[(3) - (3)].s_select_list_item),E_SLI_NOT_IN_SELECT);
                add_feature("WHERE_IN_SELECT");
        }
    break;

  case 516:

/* Line 1455 of yacc.c  */
#line 3027 "sql.yacc"
    {
		(yyval.s_select_list_item_list)=local_new_select_list_item_list((yyvsp[(1) - (1)].s_select_list_item));
	}
    break;

  case 517:

/* Line 1455 of yacc.c  */
#line 3030 "sql.yacc"
    {
                (yyval.s_select_list_item_list)=local_add_select_list_item_list((yyvsp[(1) - (3)].s_select_list_item_list),(yyvsp[(3) - (3)].s_select_list_item));
	}
    break;

  case 518:

/* Line 1455 of yacc.c  */
#line 3035 "sql.yacc"
    { (yyval.s_select_list_item)=(yyvsp[(1) - (1)].s_select_list_item);}
    break;

  case 519:

/* Line 1455 of yacc.c  */
#line 3036 "sql.yacc"
    { (yyval.s_select_list_item)=new_select_list_item_literal((yyvsp[(1) - (1)].str)); }
    break;

  case 520:

/* Line 1455 of yacc.c  */
#line 3037 "sql.yacc"
    { 
		char buff[256]; SPRINTF1(buff," -%s",(yyvsp[(2) - (2)].str)); (yyval.s_select_list_item)=new_select_list_item_literal(buff); }
    break;

  case 521:

/* Line 1455 of yacc.c  */
#line 3039 "sql.yacc"
    { char buff[256]; SPRINTF1(buff," -%s",(yyvsp[(2) - (2)].str)); (yyval.s_select_list_item)=new_select_list_item_literal(buff); }
    break;

  case 522:

/* Line 1455 of yacc.c  */
#line 3045 "sql.yacc"
    {
                if (strstr((yyvsp[(1) - (1)].str),"systables")!=0) { add_feature("IFX_SYSTABLES"); }
                if (strstr((yyvsp[(1) - (1)].str),"syscolumns")!=0) { add_feature("IFX_SYSCOLUMNS"); }
                if (strstr((yyvsp[(1) - (1)].str),"sysindexes")!=0) { add_feature("IFX_SYSINDEXES"); }
                strcpy((yyval.str),A4GLSQLCV_check_tablename((yyvsp[(1) - (1)].str)));
                }
    break;

  case 523:

/* Line 1455 of yacc.c  */
#line 3055 "sql.yacc"
    {
	     SPRINTF1((yyval.str),"%s", A4GLSQLCV_ownerize_tablename(NULL, A4GL_strip_quotes((yyvsp[(1) - (1)].str))));
             ADDMAP("Use Table",(yyval.str));
        }
    break;

  case 524:

/* Line 1455 of yacc.c  */
#line 3059 "sql.yacc"
    {
	     SPRINTF1((yyval.str),"%s", A4GLSQLCV_ownerize_tablename((yyvsp[(1) - (3)].str), (yyvsp[(3) - (3)].str)));
	     ADDMAP("Use Table",(yyval.str));
        }
    break;

  case 525:

/* Line 1455 of yacc.c  */
#line 3063 "sql.yacc"
    {
	     SPRINTF1((yyval.str),"%s", A4GLSQLCV_ownerize_tablename(NULL, (yyvsp[(1) - (1)].str)));
	     ADDMAP("Use Table",(yyval.str));
	}
    break;

  case 526:

/* Line 1455 of yacc.c  */
#line 3067 "sql.yacc"
    {
	     SPRINTF1((yyval.str),"%s", A4GLSQLCV_db_tablename((yyvsp[(1) - (3)].str), NULL, A4GLSQLCV_ownerize_tablename(NULL, (yyvsp[(3) - (3)].str))));
	     ADDMAP("Use Table",(yyval.str));
	}
    break;

  case 527:

/* Line 1455 of yacc.c  */
#line 3071 "sql.yacc"
    {
	     SPRINTF1((yyval.str),"%s", A4GLSQLCV_db_tablename((yyvsp[(1) - (5)].str), NULL, A4GLSQLCV_ownerize_tablename((yyvsp[(3) - (5)].str),(yyvsp[(5) - (5)].str))));
	     ADDMAP("Use Table",(yyval.str));
        }
    break;

  case 528:

/* Line 1455 of yacc.c  */
#line 3075 "sql.yacc"
    {
	     SPRINTF1((yyval.str),"%s", A4GLSQLCV_db_tablename(NULL,(yyvsp[(1) - (3)].str), A4GLSQLCV_ownerize_tablename(NULL, (yyvsp[(3) - (3)].str))));
	     ADDMAP("Use Table",(yyval.str));
	}
    break;

  case 529:

/* Line 1455 of yacc.c  */
#line 3079 "sql.yacc"
    {
	     SPRINTF1((yyval.str),"%s", A4GLSQLCV_db_tablename((yyvsp[(1) - (5)].str), (yyvsp[(3) - (5)].str), A4GLSQLCV_ownerize_tablename(NULL, (yyvsp[(5) - (5)].str))));
	     ADDMAP("Use Table",(yyval.str));
	}
    break;

  case 530:

/* Line 1455 of yacc.c  */
#line 3083 "sql.yacc"
    {
	     SPRINTF1((yyval.str),"%s", A4GLSQLCV_db_tablename((yyvsp[(1) - (7)].str), (yyvsp[(3) - (7)].str), A4GLSQLCV_ownerize_tablename((yyvsp[(5) - (7)].str), (yyvsp[(7) - (7)].str))));
	     ADDMAP("Use Table",(yyval.str));
        }
    break;

  case 531:

/* Line 1455 of yacc.c  */
#line 3091 "sql.yacc"
    {
                if (strstr((yyvsp[(1) - (1)].str),"systables")!=0) { add_feature("IFX_SYSTABLES"); }
                if (strstr((yyvsp[(1) - (1)].str),"syscolumns")!=0) { add_feature("IFX_SYSCOLUMNS"); }
                if (strstr((yyvsp[(1) - (1)].str),"sysindexes")!=0) { add_feature("IFX_SYSINDEXES"); }
                strcpy((yyval.str),A4GLSQLCV_check_tablename((yyvsp[(1) - (1)].str)));
                }
    break;

  case 532:

/* Line 1455 of yacc.c  */
#line 3101 "sql.yacc"
    {

	     SPRINTF1((yyval.str),"%s", A4GLSQLCV_ownerize_tablename((yyvsp[(1) - (3)].str), (yyvsp[(3) - (3)].str)));
	     ADDMAP("Use Table",(yyval.str));
        }
    break;

  case 533:

/* Line 1455 of yacc.c  */
#line 3106 "sql.yacc"
    {
	     SPRINTF1((yyval.str),"%s", A4GLSQLCV_ownerize_tablename((yyvsp[(1) - (3)].str), (yyvsp[(3) - (3)].str)));
	     ADDMAP("Use Table",(yyval.str));
        }
    break;

  case 534:

/* Line 1455 of yacc.c  */
#line 3110 "sql.yacc"
    {
	     SPRINTF1((yyval.str),"%s", A4GLSQLCV_ownerize_tablename(NULL, A4GL_strip_quotes((yyvsp[(1) - (1)].str))));
	     ADDMAP("Use Table",(yyval.str));
        }
    break;

  case 535:

/* Line 1455 of yacc.c  */
#line 3114 "sql.yacc"
    {
             SPRINTF1((yyval.str),"%s", A4GLSQLCV_ownerize_tablename(NULL, (yyvsp[(1) - (1)].str)));
	     ADDMAP("Use Table",(yyval.str));
	}
    break;

  case 536:

/* Line 1455 of yacc.c  */
#line 3118 "sql.yacc"
    {
             SPRINTF1((yyval.str),"%s", A4GLSQLCV_db_tablename((yyvsp[(1) - (3)].str),NULL, A4GLSQLCV_ownerize_tablename(NULL, (yyvsp[(3) - (3)].str))));
	     ADDMAP("Use Table",(yyval.str));
	}
    break;

  case 537:

/* Line 1455 of yacc.c  */
#line 3122 "sql.yacc"
    {
	     SPRINTF1((yyval.str),"%s", A4GLSQLCV_db_tablename((yyvsp[(1) - (5)].str), NULL,A4GLSQLCV_ownerize_tablename((yyvsp[(3) - (5)].str), (yyvsp[(5) - (5)].str))));
	     ADDMAP("Use Table",(yyval.str));
        }
    break;

  case 538:

/* Line 1455 of yacc.c  */
#line 3127 "sql.yacc"
    {
             SPRINTF1((yyval.str),"%s", A4GLSQLCV_db_tablename(NULL, (yyvsp[(1) - (3)].str), A4GLSQLCV_ownerize_tablename(NULL, (yyvsp[(3) - (3)].str))));
	     ADDMAP("Use Table",(yyval.str));
	}
    break;

  case 539:

/* Line 1455 of yacc.c  */
#line 3131 "sql.yacc"
    {
            SPRINTF1((yyval.str),"%s", A4GLSQLCV_db_tablename( (yyvsp[(1) - (5)].str), (yyvsp[(3) - (5)].str), A4GLSQLCV_ownerize_tablename(NULL, (yyvsp[(5) - (5)].str))));
	    ADDMAP("Use Table",(yyval.str));
	}
    break;

  case 540:

/* Line 1455 of yacc.c  */
#line 3135 "sql.yacc"
    {
	     SPRINTF1((yyval.str),"%s", A4GLSQLCV_db_tablename((yyvsp[(1) - (7)].str), (yyvsp[(3) - (7)].str), A4GLSQLCV_ownerize_tablename((yyvsp[(5) - (7)].str), (yyvsp[(7) - (7)].str))));
	     ADDMAP("Use Table",(yyval.str));
        }
    break;

  case 541:

/* Line 1455 of yacc.c  */
#line 3143 "sql.yacc"
    {
	     SPRINTF1((yyval.str),"%s", A4GLSQLCV_ownerize_tablename((yyvsp[(1) - (3)].str), (yyvsp[(3) - (3)].str)));
        }
    break;

  case 542:

/* Line 1455 of yacc.c  */
#line 3146 "sql.yacc"
    {
	        SPRINTF1((yyval.str),"%s", A4GLSQLCV_ownerize_tablename(NULL, (yyvsp[(1) - (1)].str)));
                ADDMAP("Use Index",(yyval.str));
        }
    break;

  case 543:

/* Line 1455 of yacc.c  */
#line 3151 "sql.yacc"
    {strcpy((yyval.str),(yyvsp[(1) - (1)].str)); ADDMAP("Use Index",(yyvsp[(1) - (1)].str)); }
    break;

  case 544:

/* Line 1455 of yacc.c  */
#line 3152 "sql.yacc"
    { SPRINTF3((yyval.str),"%s%s%s",(yyvsp[(1) - (3)].str),(yyvsp[(2) - (3)].str),(yyvsp[(3) - (3)].str)); ADDMAP("Use Index",(yyval.str)); }
    break;

  case 545:

/* Line 1455 of yacc.c  */
#line 3153 "sql.yacc"
    {
	     SPRINTF2((yyval.str),"%s:%s", (yyvsp[(1) - (5)].str), A4GLSQLCV_ownerize_tablename((yyvsp[(3) - (5)].str), (yyvsp[(5) - (5)].str)));
             ADDMAP("Use Index",(yyval.str));
        }
    break;

  case 546:

/* Line 1455 of yacc.c  */
#line 3158 "sql.yacc"
    {strcpy((yyval.str),(yyvsp[(1) - (3)].str)); ADDMAP("Use Index",(yyvsp[(1) - (3)].str)); }
    break;

  case 547:

/* Line 1455 of yacc.c  */
#line 3159 "sql.yacc"
    { SPRINTF4((yyval.str),"%s@%s%s%s",(yyvsp[(1) - (5)].str),(yyvsp[(3) - (5)].str),(yyvsp[(4) - (5)].str),(yyvsp[(5) - (5)].str)); ADDMAP("Use Index",(yyval.str)); }
    break;

  case 548:

/* Line 1455 of yacc.c  */
#line 3160 "sql.yacc"
    {
	     SPRINTF3((yyval.str),"%s@%s:%s", (yyvsp[(1) - (7)].str), (yyvsp[(3) - (7)].str), A4GLSQLCV_ownerize_tablename((yyvsp[(5) - (7)].str), (yyvsp[(7) - (7)].str)));
             ADDMAP("Use Index",(yyval.str));
        }
    break;

  case 550:

/* Line 1455 of yacc.c  */
#line 3171 "sql.yacc"
    {
                      (yyval.ptr)=A4GL_new_expr_simple_string(A4GL_get_clobbered_from((yyval.str)), ET_EXPR_IDENTIFIER);
	}
    break;

  case 552:

/* Line 1455 of yacc.c  */
#line 3177 "sql.yacc"
    { sprintf((yyval.str),".%s",(yyvsp[(2) - (2)].str)); }
    break;

  case 554:

/* Line 1455 of yacc.c  */
#line 3182 "sql.yacc"
    {strcpy((yyval.str), A4GL_strip_quotes ((yyvsp[(1) - (1)].str)));}
    break;

  case 559:

/* Line 1455 of yacc.c  */
#line 3233 "sql.yacc"
    {
			int converted;
			(yyval.sql_string)=get_insert_cmd((yyvsp[(1) - (1)].insert_cmd),&converted);
			A4GL_free_associated_mem((yyvsp[(1) - (1)].insert_cmd));
			acl_free((yyvsp[(1) - (1)].insert_cmd));

		}
    break;

  case 560:

/* Line 1455 of yacc.c  */
#line 3240 "sql.yacc"
    {
			int converted;
			(yyval.sql_string)=get_update_cmd((yyvsp[(1) - (1)].update_cmd),&converted);
			A4GL_free_associated_mem((yyvsp[(1) - (1)].update_cmd));
			acl_free((yyvsp[(1) - (1)].update_cmd));
		}
    break;

  case 561:

/* Line 1455 of yacc.c  */
#line 3246 "sql.yacc"
    {
			int converted;
			(yyval.sql_string)=get_delete_cmd((yyvsp[(1) - (1)].delete_cmd),&converted);
			A4GL_free_associated_mem((yyvsp[(1) - (1)].delete_cmd));
			acl_free((yyvsp[(1) - (1)].delete_cmd));
		}
    break;

  case 564:

/* Line 1455 of yacc.c  */
#line 3261 "sql.yacc"
    { print_exec_select((yyvsp[(1) - (1)].sql_string));  }
    break;

  case 565:

/* Line 1455 of yacc.c  */
#line 3262 "sql.yacc"
    { print_exec_select((yyvsp[(1) - (1)].sql_string));  }
    break;

  case 567:

/* Line 1455 of yacc.c  */
#line 3264 "sql.yacc"
    { print_exec_select((yyvsp[(1) - (1)].sql_string));  }
    break;

  case 568:

/* Line 1455 of yacc.c  */
#line 3266 "sql.yacc"
    {
			print_sql_commit ((yyvsp[(1) - (1)].integer_val));
	}
    break;

  case 569:

/* Line 1455 of yacc.c  */
#line 3269 "sql.yacc"
    {print_unable_to_parse();}
    break;

  case 570:

/* Line 1455 of yacc.c  */
#line 3273 "sql.yacc"
    { (yyval.sql_string)=make_sql_string_and_free((yyvsp[(1) - (2)].sql_string),acl_strdup((yyvsp[(2) - (2)].str)),0);
}
    break;

  case 572:

/* Line 1455 of yacc.c  */
#line 3282 "sql.yacc"
    {
			(yyval.sql_string)=make_select_stmt_v2("", (yyvsp[(1) - (1)].s_select),"");
			A4GL_free_select_stmt((yyvsp[(1) - (1)].s_select));
		}
    break;

  case 573:

/* Line 1455 of yacc.c  */
#line 3288 "sql.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 574:

/* Line 1455 of yacc.c  */
#line 3289 "sql.yacc"
    {
			strcpy((yyval.str),A4GLSQLCV_get_forupdate(NULL));
		}
    break;

  case 575:

/* Line 1455 of yacc.c  */
#line 3292 "sql.yacc"
    {
			strcpy((yyval.str),A4GLSQLCV_get_forupdate((yyvsp[(2) - (2)].str)));
		}
    break;

  case 576:

/* Line 1455 of yacc.c  */
#line 3297 "sql.yacc"
    { strcpy((yyval.str),(yyvsp[(1) - (1)].str)); }
    break;

  case 577:

/* Line 1455 of yacc.c  */
#line 3298 "sql.yacc"
    { sprintf((yyval.str),"%s,%s",(yyvsp[(1) - (3)].str),(yyvsp[(3) - (3)].str)); }
    break;

  case 579:

/* Line 1455 of yacc.c  */
#line 3302 "sql.yacc"
    {sprintf((yyval.str),"%s.%s",A4GLSQLCV_ownerize_tablename(NULL, (yyvsp[(1) - (3)].str)),(yyvsp[(3) - (3)].str));}
    break;

  case 580:

/* Line 1455 of yacc.c  */
#line 3303 "sql.yacc"
    {
        sprintf((yyval.str),"%s.%s", A4GLSQLCV_ownerize_tablename((yyvsp[(1) - (5)].str), (yyvsp[(3) - (5)].str)), (yyvsp[(5) - (5)].str));
}
    break;

  case 581:

/* Line 1455 of yacc.c  */
#line 3313 "sql.yacc"
    { print_exec_sql(acl_strdup((yyvsp[(1) - (1)].str))); }
    break;

  case 582:

/* Line 1455 of yacc.c  */
#line 3314 "sql.yacc"
    { print_exec_sql(acl_strdup((yyvsp[(1) - (1)].str))); }
    break;

  case 583:

/* Line 1455 of yacc.c  */
#line 3315 "sql.yacc"
    { sprintf((yyval.str),"%s %s",(yyvsp[(1) - (2)].str),(yyvsp[(2) - (2)].str)); print_exec_sql(acl_strdup((yyval.str))); }
    break;

  case 584:

/* Line 1455 of yacc.c  */
#line 3316 "sql.yacc"
    { print_exec_sql(acl_strdup((yyvsp[(1) - (1)].str))); }
    break;

  case 585:

/* Line 1455 of yacc.c  */
#line 3317 "sql.yacc"
    { print_exec_sql(acl_strdup((yyvsp[(1) - (1)].str))); }
    break;

  case 586:

/* Line 1455 of yacc.c  */
#line 3318 "sql.yacc"
    { print_exec_sql(acl_strdup((yyvsp[(1) - (1)].str))); }
    break;

  case 587:

/* Line 1455 of yacc.c  */
#line 3319 "sql.yacc"
    { print_exec_sql(acl_strdup((yyvsp[(1) - (1)].str))); }
    break;

  case 588:

/* Line 1455 of yacc.c  */
#line 3320 "sql.yacc"
    { print_exec_sql(acl_strdup((yyvsp[(1) - (1)].str))); }
    break;

  case 589:

/* Line 1455 of yacc.c  */
#line 3324 "sql.yacc"
    { 
	char *s;
	s=acl_strdup((yyvsp[(1) - (1)].str));
	(yyval.s_select_list_item)=new_select_list_item_column_from_transform(s);
	acl_free(s);
	}
    break;

  case 590:

/* Line 1455 of yacc.c  */
#line 3330 "sql.yacc"
    {  
		(yyval.s_select_list_item)=new_select_list_item_builtin_const(E_SLI_QUERY_PLACEHOLDER);}
    break;

  case 591:

/* Line 1455 of yacc.c  */
#line 3332 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_replace_var((yyvsp[(1) - (1)].sql_string));
	}
    break;

  case 592:

/* Line 1455 of yacc.c  */
#line 3351 "sql.yacc"
    {
        add_feature("DATABASE_USED");
       conn_db((yyvsp[(2) - (3)].str));
}
    break;

  case 593:

/* Line 1455 of yacc.c  */
#line 3359 "sql.yacc"
    {
		(yyval.sql_string)=acl_strdup((yyvsp[(2) - (3)].str));
}
    break;

  case 594:

/* Line 1455 of yacc.c  */
#line 3366 "sql.yacc"
    {sprintf((yyval.str),"(%s)",(yyvsp[(2) - (3)].str));}
    break;

  case 595:

/* Line 1455 of yacc.c  */
#line 3367 "sql.yacc"
    { sprintf((yyval.str),"%s%s%s",(yyvsp[(1) - (3)].str),(yyvsp[(2) - (3)].str),(yyvsp[(3) - (3)].str));}
    break;

  case 596:

/* Line 1455 of yacc.c  */
#line 3368 "sql.yacc"
    {sprintf((yyval.str),"%d",atoi((yyvsp[(1) - (1)].str)));}
    break;

  case 597:

/* Line 1455 of yacc.c  */
#line 3369 "sql.yacc"
    {sprintf((yyval.str),"(%s%s)",(yyvsp[(1) - (2)].str),(yyvsp[(2) - (2)].str));}
    break;

  case 598:

/* Line 1455 of yacc.c  */
#line 3374 "sql.yacc"
    {strcpy((yyval.str),"+");}
    break;

  case 599:

/* Line 1455 of yacc.c  */
#line 3375 "sql.yacc"
    {strcpy((yyval.str),"-");}
    break;

  case 600:

/* Line 1455 of yacc.c  */
#line 3376 "sql.yacc"
    {strcpy((yyval.str),"*");}
    break;

  case 601:

/* Line 1455 of yacc.c  */
#line 3377 "sql.yacc"
    {strcpy((yyval.str),"/");}
    break;

  case 602:

/* Line 1455 of yacc.c  */
#line 3378 "sql.yacc"
    {strcpy((yyval.str),"%");}
    break;

  case 603:

/* Line 1455 of yacc.c  */
#line 3383 "sql.yacc"
    {strcpy((yyval.str),"+");}
    break;

  case 604:

/* Line 1455 of yacc.c  */
#line 3384 "sql.yacc"
    {strcpy((yyval.str),"-");}
    break;

  case 605:

/* Line 1455 of yacc.c  */
#line 3400 "sql.yacc"
    {sprintf((yyval.str),"%s", A4GLSQLCV_check_tablename((yyvsp[(1) - (1)].str)));}
    break;

  case 606:

/* Line 1455 of yacc.c  */
#line 3401 "sql.yacc"
    {sprintf((yyval.str),"%s.*", A4GLSQLCV_ownerize_tablename(NULL,(yyvsp[(1) - (3)].str)));}
    break;

  case 607:

/* Line 1455 of yacc.c  */
#line 3402 "sql.yacc"
    {sprintf((yyval.str),"%s.%s", (yyvsp[(1) - (3)].str),A4GLSQLCV_get_sqlconst ("rowid"));}
    break;

  case 608:

/* Line 1455 of yacc.c  */
#line 3403 "sql.yacc"
    {sprintf((yyval.str),"%s.%s", A4GLSQLCV_ownerize_tablename(NULL,(yyvsp[(1) - (3)].str)),(yyvsp[(3) - (3)].str));}
    break;

  case 609:

/* Line 1455 of yacc.c  */
#line 3404 "sql.yacc"
    {sprintf((yyval.str),"%s.%s", A4GLSQLCV_ownerize_tablename((yyvsp[(1) - (5)].str),(yyvsp[(3) - (5)].str)),(yyvsp[(5) - (5)].str));}
    break;

  case 610:

/* Line 1455 of yacc.c  */
#line 3405 "sql.yacc"
    {sprintf((yyval.str),"%s.%s", A4GLSQLCV_ownerize_tablename((yyvsp[(1) - (5)].str),(yyvsp[(3) - (5)].str)),(yyvsp[(5) - (5)].str));}
    break;

  case 611:

/* Line 1455 of yacc.c  */
#line 3406 "sql.yacc"
    {sprintf((yyval.str),"%s", (yyvsp[(1) - (4)].str)); strcpy((yyval.str), A4GLSQLCV_make_substr_s((yyvsp[(1) - (4)].str), 1,(yyvsp[(3) - (4)].str),0));}
    break;

  case 612:

/* Line 1455 of yacc.c  */
#line 3407 "sql.yacc"
    {char buff[256]; sprintf(buff,"%s.%s", A4GLSQLCV_ownerize_tablename(NULL,(yyvsp[(1) - (6)].str)),(yyvsp[(3) - (6)].str)); strcpy((yyval.str), A4GLSQLCV_make_substr_s(buff,1,(yyvsp[(5) - (6)].str),0));}
    break;

  case 613:

/* Line 1455 of yacc.c  */
#line 3408 "sql.yacc"
    {char buff[256]; sprintf(buff,"%s.%s", A4GLSQLCV_ownerize_tablename((yyvsp[(1) - (8)].str),(yyvsp[(3) - (8)].str)), (yyvsp[(5) - (8)].str)); strcpy((yyval.str), A4GLSQLCV_make_substr_s(buff,1,(yyvsp[(7) - (8)].str),0));  }
    break;

  case 614:

/* Line 1455 of yacc.c  */
#line 3409 "sql.yacc"
    {char buff[256]; sprintf(buff,"%s.%s", A4GLSQLCV_ownerize_tablename((yyvsp[(1) - (8)].str),(yyvsp[(3) - (8)].str)), (yyvsp[(5) - (8)].str));  strcpy((yyval.str), A4GLSQLCV_make_substr_s(buff,1,(yyvsp[(7) - (8)].str),0)); }
    break;

  case 615:

/* Line 1455 of yacc.c  */
#line 3411 "sql.yacc"
    {sprintf((yyval.str),"%s", (yyvsp[(1) - (6)].str)); strcpy((yyval.str), A4GLSQLCV_make_substr_s((yyvsp[(1) - (6)].str), 2,(yyvsp[(3) - (6)].str),(yyvsp[(5) - (6)].str)));}
    break;

  case 616:

/* Line 1455 of yacc.c  */
#line 3412 "sql.yacc"
    {char buff[256]; sprintf(buff,"%s.%s", A4GLSQLCV_ownerize_tablename(NULL,(yyvsp[(1) - (8)].str)),(yyvsp[(3) - (8)].str)); strcpy((yyval.str), A4GLSQLCV_make_substr_s(buff,2,(yyvsp[(5) - (8)].str),(yyvsp[(7) - (8)].str)));}
    break;

  case 617:

/* Line 1455 of yacc.c  */
#line 3413 "sql.yacc"
    {char buff[256]; sprintf(buff,"%s.%s", A4GLSQLCV_ownerize_tablename((yyvsp[(1) - (10)].str),(yyvsp[(3) - (10)].str)), (yyvsp[(5) - (10)].str)); strcpy((yyval.str), A4GLSQLCV_make_substr_s(buff,2,(yyvsp[(7) - (10)].str),(yyvsp[(9) - (10)].str)));  }
    break;

  case 618:

/* Line 1455 of yacc.c  */
#line 3414 "sql.yacc"
    {char buff[256]; sprintf(buff,"%s.%s", A4GLSQLCV_ownerize_tablename((yyvsp[(1) - (10)].str),(yyvsp[(3) - (10)].str)), (yyvsp[(5) - (10)].str));  strcpy((yyval.str), A4GLSQLCV_make_substr_s(buff,2,(yyvsp[(7) - (10)].str),(yyvsp[(9) - (10)].str))); }
    break;

  case 619:

/* Line 1455 of yacc.c  */
#line 3419 "sql.yacc"
    {
                (yyval.s_select_list_item)=(yyvsp[(1) - (1)].s_select_list_item);
        }
    break;

  case 620:

/* Line 1455 of yacc.c  */
#line 3422 "sql.yacc"
    {
                (yyval.s_select_list_item)=new_select_list_item_cast((yyvsp[(1) - (3)].s_select_list_item), (yyvsp[(3) - (3)].str));
        }
    break;

  case 621:

/* Line 1455 of yacc.c  */
#line 3431 "sql.yacc"
    { (yyvsp[(1) - (1)].s_select_list_item)=(yyvsp[(1) - (1)].s_select_list_item); }
    break;

  case 622:

/* Line 1455 of yacc.c  */
#line 3432 "sql.yacc"
    {(yyvsp[(1) - (1)].s_select_list_item)=(yyvsp[(1) - (1)].s_select_list_item);}
    break;

  case 623:

/* Line 1455 of yacc.c  */
#line 3433 "sql.yacc"
    {  (yyval.s_select_list_item)=new_select_list_item_sq(E_SQE_DONT_CARE,(yyvsp[(1) - (1)].s_select_list_item)); }
    break;

  case 624:

/* Line 1455 of yacc.c  */
#line 3434 "sql.yacc"
    { (yyval.s_select_list_item)=new_select_list_item_sq(E_SQE_ALL,(yyvsp[(2) - (2)].s_select_list_item)); }
    break;

  case 625:

/* Line 1455 of yacc.c  */
#line 3435 "sql.yacc"
    { (yyval.s_select_list_item)=new_select_list_item_sq(E_SQE_ANY,(yyvsp[(2) - (2)].s_select_list_item)); }
    break;

  case 626:

/* Line 1455 of yacc.c  */
#line 3436 "sql.yacc"
    { (yyval.s_select_list_item)=new_select_list_item_sq(E_SQE_SOME,(yyvsp[(2) - (2)].s_select_list_item)); }
    break;

  case 627:

/* Line 1455 of yacc.c  */
#line 3440 "sql.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 628:

/* Line 1455 of yacc.c  */
#line 3441 "sql.yacc"
    {strcpy((yyval.str),(yyvsp[(1) - (1)].str));}
    break;



/* Line 1455 of yacc.c  */
#line 8911 "y.tab.c"
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
#line 3447 "sql.yacc"


#if LEX_YY_PREGEN
#include "../../tools/no_yacc/cygwin/compilers/sql/lex.sqlparse_yy.c"
#else
#include "lex.yy.c"
#endif
#include "util.c"
#include "cmds.c"

