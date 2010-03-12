
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
     INT_VALUE = 2230,
     NAMED = 2231,
     NAMED_GEN = 2232,
     CHAR_VALUE = 2233,
     NOT_USED_1 = 2234,
     NOT_USED_2 = 2235,
     NOT_USED_3 = 2236,
     NOT_USED_4 = 2237,
     NOT_USED_5 = 2238,
     NOT_USED_6 = 2239,
     NOT_USED_7 = 2240,
     NOT_USED_8 = 2241,
     NUMBER_VALUE = 2242,
     SEMICOLON = 2243,
     QUESTION_MARK = 2244,
     CLINE = 2245,
     CH = 2246,
     MARK_VAR = 2247,
     END_MARK_VAR = 2248,
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
     SORT = 2228
   };
#endif
/* Tokens.  */
#define INT_VALUE 2230
#define NAMED 2231
#define NAMED_GEN 2232
#define CHAR_VALUE 2233
#define NOT_USED_1 2234
#define NOT_USED_2 2235
#define NOT_USED_3 2236
#define NOT_USED_4 2237
#define NOT_USED_5 2238
#define NOT_USED_6 2239
#define NOT_USED_7 2240
#define NOT_USED_8 2241
#define NUMBER_VALUE 2242
#define SEMICOLON 2243
#define QUESTION_MARK 2244
#define CLINE 2245
#define CH 2246
#define MARK_VAR 2247
#define END_MARK_VAR 2248
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
#line 839 "y.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 851 "y.tab.c"

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
#define YYLAST   2303

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  278
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  226
/* YYNRULES -- Number of rules.  */
#define YYNRULES  627
/* YYNRULES -- Number of states.  */
#define YYNSTATES  1115

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   2248

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
       2,     2,     2,     2,     2,     2,     2,     2,    58,    59,
      60,     2,     2,     2,    61,     2,     2,     2,     2,     2,
       2,    62,    63,    64,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      65,    66,    67,    68,    69,     2,     2,    70,    71,     2,
      72,    73,    74,    75,     2,     2,    76,    77,     2,     2,
       2,     2,     2,     2,    78,    79,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,    80,    81,    82,     2,     2,
       2,     2,     2,     2,    83,    84,    85,    86,    87,    88,
       2,     2,     2,     2,    89,    90,     2,    91,    92,    93,
      94,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      95,     2,     2,     2,     2,     2,    96,    97,    98,    99,
     100,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,   101,   102,     2,     2,     2,     2,     2,     2,     2,
     103,   104,   105,     2,     2,     2,     2,     2,   106,     2,
       2,     2,     2,     2,     2,     2,   107,     2,     2,     2,
       2,     2,     2,   108,     2,   109,     2,     2,     2,   110,
     111,     2,   112,     2,     2,     2,     2,   113,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   114,   115,   116,   117,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,   118,
       2,     2,     2,     2,     2,     2,     2,   119,     2,   120,
     121,     2,     2,     2,   122,   123,     2,     2,     2,     2,
       2,     2,   124,   125,     2,     2,   126,     2,   127,     2,
       2,   128,     2,     2,     2,     2,     2,   129,     2,     2,
       2,     2,     2,     2,   130,     2,     2,   131,     2,     2,
       2,     2,     2,   132,     2,     2,     2,     2,   133,     2,
       2,     2,     2,     2,   134,   135,     2,     2,     2,     2,
     136,     2,   137,     2,   138,   139,     2,   140,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,   141,     2,
       2,     2,     2,     2,     2,   142,     2,     2,   143,   144,
     145,     2,   146,     2,   147,     2,     2,   148,     2,     2,
       2,   149,     2,   150,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,   151,   152,     2,
     153,     2,     2,     2,     2,     2,     2,   154,     2,   155,
     156,     2,   157,   158,   159,     2,     2,     2,     2,     2,
     160,   161,     2,     2,     2,     2,     2,   162,   163,     2,
     164,     2,     2,   165,     2,     2,   166,   167,     2,   168,
       2,   169,     2,     2,     2,     2,     2,     2,     2,   170,
       2,   171,     2,     2,   172,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,   173,     2,     2,
     174,   175,   176,   177,     2,   178,     2,     2,     2,     2,
       2,     2,     2,   179,     2,     2,   180,   181,   182,     2,
       2,     2,   183,     2,   184,     2,     2,     2,   185,   186,
       2,   187,   188,     2,   189,     2,     2,     2,   190,     2,
       2,     2,   191,     2,     2,     2,   192,     2,     2,     2,
     193,   194,     2,     2,   195,     2,   196,   197,     2,     2,
     198,   199,     2,   200,     2,     2,     2,     2,     2,   201,
       2,     2,     2,   202,     2,     2,     2,     2,   203,   204,
       2,     2,   205,     2,     2,   206,     2,     2,   207,     2,
     208,   209,     2,   210,   211,   212,     2,     2,     2,     2,
       2,     2,     2,     2,   213,     2,     2,   214,     2,     2,
       2,     2,     2,     2,   215,     2,   216,     2,   217,   218,
     219,     2,     2,   220,   221,     2,     2,     2,   222,     2,
       2,     2,     2,     2,   223,   224,     2,     2,   225,     2,
       2,     2,     2,     2,     2,     2,     2,   226,     2,     2,
       2,     2,   227,     2,     2,     2,   228,   229,   230,     2,
     231,     2,     2,   232,   233,     2,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,     2,     2,     2,
     245,     2,     2,     2,     2,   246,   247,   248,   249,   250,
       2,     2,     2,     2,     2,     2,   251,     2,     2,   252,
     253,     2,     2,     2,     2,     2,   254,     2,   255,   256,
       2,     2,   257,     2,   258,   259,   260,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,   261,     2,     2,     2,   262,     2,
       2,     2,     2,     2,     2,   263,   264,     2,     2,   265,
       2,     2,     2,     2,   266,     2,     2,     2,     2,     2,
       2,   267,   268,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     269,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,   270,   271,   272,   273,   274,   275,   276,   277,     2,
       3,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21
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
    1368,  1371,  1374,  1378,  1381,  1385,  1389,  1393,  1395,  1397,
    1399,  1401,  1403,  1405,  1407,  1409,  1411,  1417,  1423,  1429,
    1435,  1441,  1445,  1450,  1455,  1460,  1465,  1470,  1475,  1480,
    1485,  1489,  1494,  1496,  1498,  1502,  1504,  1507,  1512,  1515,
    1517,  1521,  1527,  1533,  1538,  1544,  1546,  1548,  1550,  1552,
    1554,  1556,  1562,  1566,  1572,  1576,  1578,  1582,  1584,  1586,
    1589,  1592,  1594,  1596,  1600,  1602,  1606,  1612,  1616,  1622,
    1630,  1632,  1636,  1640,  1642,  1644,  1648,  1654,  1658,  1664,
    1672,  1676,  1678,  1680,  1684,  1690,  1694,  1700,  1708,  1710,
    1712,  1714,  1717,  1719,  1721,  1722,  1724,  1726,  1730,  1732,
    1734,  1736,  1737,  1739,  1741,  1743,  1745,  1747,  1749,  1751,
    1754,  1756,  1758,  1759,  1761,  1764,  1766,  1770,  1772,  1776,
    1782,  1784,  1786,  1789,  1791,  1793,  1795,  1797,  1799,  1801,
    1803,  1805,  1809,  1813,  1817,  1821,  1823,  1826,  1828,  1830,
    1832,  1834,  1836,  1838,  1840,  1842,  1846,  1850,  1854,  1860,
    1866,  1871,  1878,  1887,  1896,  1903,  1912,  1923,  1934,  1936,
    1940,  1942,  1944,  1946,  1949,  1952,  1955,  1956
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     484,     0,    -1,   196,   475,   282,   280,    -1,    -1,   106,
     479,    -1,   214,   391,    -1,    -1,   106,   479,    -1,   214,
     391,    -1,    69,   287,   165,   187,   178,   288,   165,    -1,
      65,   288,   165,    -1,    66,   288,   165,    -1,   234,   283,
      -1,    68,   288,    -1,    67,   288,    -1,   286,    -1,   283,
     242,   286,    -1,   285,    -1,   252,   285,    -1,   478,   417,
      -1,   478,   256,   478,   417,    -1,   478,   256,   478,   256,
     478,   417,    -1,   478,   256,   210,    -1,   284,   187,   289,
      -1,   284,    -1,   287,   242,   284,    -1,   289,    -1,   288,
     242,   289,    -1,   463,    -1,   198,    -1,   291,    -1,   111,
     475,    -1,   147,   475,    -1,   133,   477,    -1,    58,   478,
      -1,   302,    -1,   293,    -1,   114,   475,   178,   307,   165,
     294,    -1,   102,   475,   178,   307,   165,   303,   294,   303,
      -1,    -1,   295,    -1,   296,    -1,   295,   296,    -1,   257,
     297,    -1,   124,     3,    -1,    64,     3,    -1,    81,    -1,
      82,    -1,     4,    -1,    -1,   299,    -1,   300,    -1,   299,
     300,    -1,   257,   297,    -1,   265,     3,    -1,    44,    -1,
      45,    -1,   475,    -1,    92,   477,   258,   301,   178,   305,
     165,   298,    -1,    91,   477,   258,   301,   178,   305,   165,
     298,    -1,    93,   477,   258,   301,   178,   305,   165,   298,
      -1,    94,   477,   258,   301,   178,   305,   165,   298,    -1,
      70,   488,    -1,    71,   488,    -1,   110,   475,   245,   475,
      -1,    60,   475,   257,     6,    -1,    59,   475,    -1,    74,
     475,    -1,    56,   475,    -1,    57,   478,    -1,    -1,   130,
      -1,    -1,   130,    -1,   306,    -1,   305,   242,   306,    -1,
     478,   239,    -1,   478,   218,    -1,   478,    -1,   308,    -1,
     307,   242,   308,    -1,   371,    -1,   369,    -1,    62,   478,
     310,    -1,    63,   477,    89,    -1,    63,   477,    90,    -1,
     311,    -1,   310,   242,   311,    -1,   312,    -1,   315,    -1,
     318,    -1,   323,    -1,   326,    -1,   322,    -1,   321,    -1,
     235,   313,    -1,   235,   178,   314,   165,    -1,   308,    -1,
     308,   261,   478,    -1,   313,    -1,   314,   242,   313,    -1,
     220,   317,    -1,   220,   178,   316,   165,    -1,   317,    -1,
     316,   242,   317,    -1,   478,    -1,   186,   320,    -1,   186,
     178,   319,   165,    -1,   320,    -1,   319,   242,   320,    -1,
     308,    -1,    81,    -1,    82,    -1,    80,     3,    -1,    72,
     369,   325,    -1,    72,   178,   324,   165,    -1,   369,   325,
      -1,   324,   242,   369,   325,    -1,    -1,    75,   478,    -1,
      73,   327,    -1,    73,   178,   327,   165,    -1,   328,    -1,
     327,   242,   328,    -1,   478,    -1,   119,    -1,    -1,   126,
     331,   475,   334,   332,    -1,    -1,   197,   333,   178,   337,
     165,    -1,   457,    -1,    -1,   178,   335,   165,    -1,   336,
      -1,   335,   242,   336,    -1,   478,    -1,   478,   256,   478,
      -1,   338,    -1,   337,   242,   338,    -1,   463,    -1,   198,
      -1,   123,   475,   281,    -1,   132,    -1,   141,    -1,    -1,
     148,    -1,   344,    -1,    51,   478,    52,     6,    50,    -1,
      51,   478,    52,     6,    -1,    53,    -1,    46,    -1,    47,
      -1,    99,   478,    -1,   113,    -1,   341,    -1,   340,    -1,
     329,    -1,   343,    -1,   377,    -1,   381,    -1,   427,    -1,
     290,    -1,   292,    -1,   309,    -1,   205,   350,   258,   475,
     260,   355,   349,    -1,   191,   350,   258,   475,   222,   355,
      -1,   205,   348,   260,   355,    -1,   191,   348,   222,   355,
      -1,   166,    -1,   160,    -1,   244,    -1,    -1,   104,    -1,
     254,   416,    -1,   109,    -1,   236,    -1,   351,    -1,   352,
      -1,   351,   242,   352,    -1,   193,   353,    -1,   184,    -1,
     179,    -1,   196,   353,    -1,   200,    -1,   206,    -1,    -1,
     178,   354,   165,    -1,   418,    -1,   354,   242,   418,    -1,
     356,    -1,   355,   242,   356,    -1,   190,    -1,   416,    -1,
     122,   475,   358,   254,   448,   360,    -1,    -1,   178,   359,
     165,    -1,   418,    -1,   359,   242,   418,    -1,    -1,   103,
      -1,   201,   178,   447,   165,    -1,   125,   178,   364,   165,
     363,    -1,   138,   365,    -1,   366,    -1,   475,    -1,   475,
     178,   366,   165,    -1,   418,    -1,   366,   242,   418,    -1,
     195,   178,   368,   165,    -1,   153,   178,   368,   165,    -1,
     129,   178,   368,   165,    -1,   418,    -1,   368,   242,   418,
      -1,   367,    -1,   362,    -1,   361,    -1,   169,   423,    -1,
     117,    -1,   116,    -1,   115,    -1,   478,   407,   372,   373,
      -1,    -1,   370,    -1,    -1,   374,    -1,   375,    -1,   374,
     375,    -1,   376,   325,    -1,   159,    -1,   107,    -1,   195,
      -1,   153,    -1,   363,    -1,   201,   178,   447,   165,    -1,
     129,    -1,    97,   378,   380,    -1,   379,    -1,   416,    -1,
     381,    -1,   380,   381,    -1,   357,    -1,   347,    -1,   183,
     391,    -1,   214,   391,    -1,   222,   385,    -1,   387,    -1,
     385,   242,   387,    -1,   385,   242,   212,   387,    -1,   385,
     242,   212,   178,   385,   165,    -1,   385,    33,   386,   258,
     391,    -1,   385,    40,   386,   258,   391,    -1,   385,    -1,
     178,   385,   165,    -1,   475,    -1,   475,   422,    -1,   475,
     254,   422,    -1,    -1,   384,   389,    -1,   390,    -1,   383,
     390,    -1,    -1,   444,    -1,   444,   382,    -1,   382,    -1,
     392,    -1,   391,   259,   392,    -1,   393,    -1,   392,   237,
     393,    -1,   394,    -1,   250,   394,    -1,   404,    -1,   178,
     391,   165,    -1,   181,   458,    -1,   137,   458,    -1,    -1,
     180,   400,    -1,    -1,   180,   400,    -1,    -1,   180,   400,
      -1,   501,    -1,   423,    -1,    -1,   250,    -1,   463,   401,
     162,    -1,   463,   401,   127,    -1,   463,   403,   463,    -1,
     463,   187,   463,    -1,   463,   187,   198,    -1,   463,   401,
     164,   463,   237,   463,    -1,   463,   225,   399,   398,    -1,
     463,   157,   399,   398,    -1,   463,   264,   399,   397,    -1,
     463,   158,   399,   397,    -1,   463,   172,   399,   396,    -1,
     463,   128,   399,   396,    -1,   188,    -1,   207,    -1,   175,
      -1,   263,    -1,   163,    -1,   149,    -1,   402,    -1,   470,
      -1,   395,    -1,   463,    -1,    -1,   236,    -1,   153,    -1,
     195,    -1,    -1,   236,    -1,   153,    -1,   195,    -1,   408,
      -1,   409,    -1,   410,    -1,   412,    -1,   143,    -1,   143,
     178,   413,   165,    -1,   194,    -1,   194,   178,     3,   165,
      -1,   171,    -1,   171,   178,     3,   165,    -1,   168,    -1,
     168,   178,   414,   411,   165,    -1,   208,   178,   414,   411,
     165,    -1,   208,    -1,   217,    -1,   170,    -1,   161,    -1,
     144,    -1,   144,   178,   413,   165,    -1,   145,    -1,   145,
     178,     3,   165,    -1,   145,   178,     3,   242,     3,   165,
      -1,   152,   425,   260,   426,    -1,   152,    -1,   156,   425,
     260,   426,    -1,   449,    -1,   156,    -1,   156,   425,   178,
       3,   165,   260,   426,    -1,   228,    -1,   215,    -1,   173,
      -1,   173,   178,     3,   165,    -1,   173,   178,     3,   242,
       3,   165,    -1,    -1,   242,   415,    -1,   204,   178,   414,
     165,    -1,   226,    -1,   140,    -1,   204,    -1,    78,    -1,
       3,    -1,     3,    -1,     3,    -1,   478,    -1,     6,    -1,
      -1,   189,     3,   174,    -1,   189,     3,   242,     3,   174,
      -1,   421,    -1,   252,   421,    -1,   420,    -1,   252,   420,
      -1,   478,   417,    -1,   473,   256,   478,   417,    -1,   473,
     256,   210,    -1,   268,    -1,   478,   417,    -1,   473,   256,
     478,   417,    -1,   478,   256,   478,   256,   478,   417,    -1,
     473,   256,   210,    -1,   478,    -1,     6,    -1,   480,    -1,
       3,    -1,   438,    -1,    -1,   425,   260,   426,    -1,   232,
      -1,   209,    -1,   243,    -1,   223,    -1,   185,    -1,   192,
      -1,   154,    -1,   232,    -1,   209,    -1,   243,    -1,   223,
      -1,   185,    -1,   192,    -1,   154,    -1,   154,   178,     3,
     165,    -1,   432,    -1,   431,    -1,   428,    -1,   142,   429,
     260,   429,    -1,   139,   473,   256,   430,   260,   430,    -1,
     478,    -1,   478,    -1,   118,   475,    -1,   136,   475,   433,
      -1,   131,    -1,   112,    -1,   435,    -1,   435,   425,   260,
     426,    -1,    54,    -1,   437,    -1,   437,   425,   178,     3,
     165,   260,   426,    -1,   437,   425,   260,   426,    -1,    55,
      -1,   167,   424,    -1,   211,   255,   440,    -1,   441,    -1,
     440,   242,   441,    -1,   442,   443,    -1,     3,    -1,   419,
      -1,    -1,   239,    -1,   218,    -1,   155,   445,    -1,   446,
      -1,   445,   242,   446,    -1,   419,    -1,     3,    -1,   391,
      -1,   457,    -1,   266,    -1,   266,   178,     3,   165,    -1,
     269,    -1,   269,   178,     3,   165,    -1,    -1,    -1,   193,
     459,   460,   451,   461,   452,   482,   388,   454,   455,    -1,
     193,   459,   460,   461,   388,   454,    -1,    -1,   213,   406,
     453,    -1,    -1,   439,    -1,   439,   150,   456,   304,    -1,
     150,   456,   304,    -1,   478,    -1,   193,   459,   460,   461,
     388,    -1,   178,   193,   459,   460,   461,   388,   165,    -1,
      -1,   203,     3,    -1,    -1,   236,    -1,   153,    -1,   195,
      -1,   462,    -1,   461,   242,   462,    -1,   463,    -1,   463,
     478,    -1,   463,   254,   478,    -1,   501,    -1,   248,   501,
      -1,   253,   501,    -1,   501,   219,   463,    -1,   501,   469,
      -1,   501,   210,   463,    -1,   501,   253,   463,    -1,   501,
     248,   463,    -1,   423,    -1,   199,    -1,   176,    -1,   230,
      -1,   267,    -1,   268,    -1,   266,    -1,   210,    -1,    79,
      -1,   240,   178,   405,   463,   165,    -1,   246,   178,   405,
     463,   165,    -1,   247,   178,   405,   463,   165,    -1,   251,
     178,   405,   463,   165,    -1,   202,   178,   405,   463,   165,
      -1,     4,   178,   165,    -1,     4,   178,   467,   165,    -1,
     232,   178,   467,   165,    -1,   209,   178,   467,   165,    -1,
     243,   178,   467,   165,    -1,    48,   178,   467,   165,    -1,
      49,   178,   467,   165,    -1,   233,   178,   467,   165,    -1,
     217,   178,   467,   165,    -1,   178,   463,   165,    -1,   182,
     178,   468,   165,    -1,   434,    -1,   436,    -1,   216,   465,
     262,    -1,   466,    -1,   465,   466,    -1,   231,   391,   229,
     463,    -1,   221,   463,    -1,   463,    -1,   467,   242,   463,
      -1,   167,   242,   425,   260,   426,    -1,   494,   242,   425,
     260,   426,    -1,   167,   425,   260,   426,    -1,   463,   242,
     425,   260,   426,    -1,    83,    -1,    84,    -1,    85,    -1,
      86,    -1,    87,    -1,    88,    -1,   463,   257,   178,   471,
     165,    -1,   463,   257,   458,    -1,   463,   177,   178,   471,
     165,    -1,   463,   177,   458,    -1,   472,    -1,   471,   242,
     472,    -1,   494,    -1,   423,    -1,   248,     3,    -1,   248,
     480,    -1,   474,    -1,     6,    -1,     6,   256,   478,    -1,
     478,    -1,   478,   241,   478,    -1,   478,   241,     6,   256,
     478,    -1,   478,   252,   478,    -1,   478,   252,   478,   241,
     478,    -1,   478,   252,   478,   241,     6,   256,   478,    -1,
     476,    -1,     6,   256,   478,    -1,   478,   256,   478,    -1,
       6,    -1,   478,    -1,   478,   241,   478,    -1,   478,   241,
       6,   256,   478,    -1,   478,   252,   478,    -1,   478,   252,
     478,   241,   478,    -1,   478,   252,   478,   241,     6,   256,
     478,    -1,     6,   256,   478,    -1,     6,    -1,   478,    -1,
     478,   241,   478,    -1,   478,   241,     6,   256,   478,    -1,
     478,   252,   478,    -1,   478,   252,   478,   241,   478,    -1,
     478,   252,   478,   241,     6,   256,   478,    -1,     4,    -1,
       4,    -1,    15,    -1,   256,     3,    -1,     4,    -1,     6,
      -1,    -1,   478,    -1,   486,    -1,   484,    16,   486,    -1,
     330,    -1,   279,    -1,   339,    -1,    -1,   495,    -1,   346,
      -1,   487,    -1,   493,    -1,   485,    -1,   345,    -1,     1,
      -1,   489,   490,    -1,   483,    -1,   450,    -1,    -1,   135,
      -1,   134,   491,    -1,   492,    -1,   491,   242,   492,    -1,
     478,    -1,   478,   256,   478,    -1,     6,   256,   478,   256,
     478,    -1,   121,    -1,   120,    -1,   108,   503,    -1,   105,
      -1,   101,    -1,    98,    -1,    96,    -1,   100,    -1,   500,
      -1,    17,    -1,   496,    -1,   151,   481,   342,    -1,    20,
       6,    21,    -1,   178,   497,   165,    -1,   497,   498,   497,
      -1,     3,    -1,   499,     3,    -1,   253,    -1,   248,    -1,
     210,    -1,   219,    -1,   249,    -1,   253,    -1,   248,    -1,
     478,    -1,   478,   256,   210,    -1,   478,   256,   268,    -1,
     478,   256,   478,    -1,   478,   256,   478,   256,   478,    -1,
       6,   256,   478,   256,   478,    -1,   478,   189,   497,   174,
      -1,   478,   256,   478,   189,   497,   174,    -1,   478,   256,
     478,   256,   478,   189,   497,   174,    -1,     6,   256,   478,
     256,   478,   189,   497,   174,    -1,   478,   189,   497,   242,
     497,   174,    -1,   478,   256,   478,   189,   497,   242,   497,
     174,    -1,   478,   256,   478,   256,   478,   189,   497,   242,
     497,   174,    -1,     6,   256,   478,   256,   478,   189,   497,
     242,   497,   174,    -1,   502,    -1,   502,    95,   407,    -1,
     464,    -1,   494,    -1,   458,    -1,   236,   458,    -1,   238,
     458,    -1,   227,   458,    -1,    -1,     3,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   452,   452,   478,   481,   498,   503,   506,   523,   529,
     538,   547,   556,   563,   578,   633,   640,   651,   654,   659,
     666,   683,   700,   721,   730,   733,   741,   744,   752,   753,
     760,   763,   771,   774,   778,   784,   785,   789,   799,   813,
     814,   818,   819,   824,   832,   840,   848,   856,   866,   868,
     868,   871,   872,   876,   883,   890,   897,   906,   910,   917,
     929,   940,   946,   950,   954,   959,   963,   966,   970,   973,
     980,   981,   991,   992,   996,   997,  1001,  1010,  1019,  1026,
    1029,  1035,  1038,  1049,  1053,  1058,  1065,  1068,  1077,  1080,
    1084,  1088,  1092,  1096,  1100,  1108,  1112,  1120,  1123,  1130,
    1133,  1140,  1143,  1150,  1151,  1156,  1160,  1163,  1169,  1172,
    1178,  1185,  1186,  1190,  1198,  1202,  1209,  1211,  1216,  1217,
    1221,  1223,  1229,  1230,  1233,  1244,  1250,  1250,  1259,  1259,
    1268,  1293,  1296,  1304,  1307,  1314,  1317,  1325,  1326,  1332,
    1333,  1341,  1359,  1363,  1368,  1369,  1379,  1388,  1392,  1396,
    1401,  1405,  1409,  1412,  1419,  1420,  1421,  1425,  1426,  1427,
    1428,  1429,  1430,  1431,  1439,  1440,  1441,  1442,  1447,  1448,
    1449,  1452,  1453,  1454,  1458,  1459,  1460,  1464,  1465,  1469,
    1476,  1477,  1478,  1485,  1486,  1489,  1490,  1495,  1496,  1501,
    1502,  1507,  1508,  1513,  1520,  1521,  1526,  1527,  1531,  1532,
    1539,  1547,  1554,  1561,  1565,  1566,  1571,  1572,  1578,  1582,
    1587,  1594,  1595,  1601,  1604,  1607,  1614,  1615,  1616,  1617,
    1623,  1646,  1647,  1650,  1652,  1659,  1662,  1668,  1676,  1681,
    1687,  1692,  1698,  1701,  1706,  1714,  1723,  1728,  1732,  1733,
    1739,  1742,  1753,  1762,  1769,  1775,  1776,  1779,  1784,  1795,
    1799,  1806,  1807,  1811,  1815,  1819,  1826,  1831,  1839,  1842,
    1848,  1851,  1856,  1861,  1874,  1877,  1883,  1886,  1892,  1895,
    1901,  1904,  1911,  1915,  1926,  1926,  1927,  1927,  1928,  1928,
    1931,  1936,  1941,  1942,  1947,  1956,  1964,  1967,  1970,  1974,
    1981,  1984,  1988,  1991,  1994,  1997,  2003,  2010,  2013,  2016,
    2019,  2020,  2025,  2028,  2031,  2034,  2041,  2042,  2043,  2047,
    2054,  2055,  2056,  2060,  2074,  2081,  2082,  2083,  2087,  2088,
    2093,  2094,  2103,  2105,  2114,  2117,  2125,  2135,  2143,  2145,
    2146,  2147,  2148,  2149,  2150,  2151,  2159,  2160,  2161,  2162,
    2163,  2164,  2165,  2166,  2167,  2168,  2169,  2179,  2180,  2186,
    2188,  2189,  2190,  2191,  2195,  2199,  2203,  2210,  2211,  2216,
    2217,  2221,  2229,  2232,  2239,  2242,  2252,  2255,  2258,  2261,
    2268,  2275,  2283,  2292,  2299,  2303,  2308,  2309,  2310,  2315,
    2317,  2326,  2326,  2326,  2326,  2326,  2326,  2326,  2327,  2327,
    2327,  2327,  2327,  2327,  2327,  2327,  2372,  2373,  2374,  2379,
    2380,  2383,  2384,  2388,  2395,  2406,  2407,  2420,  2421,  2425,
    2429,  2430,  2433,  2439,  2443,  2466,  2476,  2479,  2485,  2494,
    2498,  2505,  2506,  2508,  2513,  2519,  2522,  2528,  2529,  2536,
    2549,  2559,  2566,  2583,  2590,  2615,  2617,  2615,  2639,  2683,
    2684,  2698,  2701,  2708,  2718,  2730,  2736,  2749,  2764,  2766,
    2772,  2773,  2774,  2775,  2785,  2788,  2794,  2797,  2802,  2811,
    2814,  2818,  2825,  2828,  2831,  2834,  2837,  2840,  2841,  2842,
    2843,  2844,  2845,  2846,  2847,  2848,  2850,  2854,  2858,  2862,
    2866,  2870,  2874,  2878,  2881,  2884,  2887,  2890,  2893,  2896,
    2899,  2902,  2906,  2910,  2914,  2922,  2925,  2934,  2940,  2947,
    2950,  2978,  2981,  2984,  2987,  2993,  2994,  2995,  2996,  2997,
    2998,  3003,  3007,  3011,  3015,  3022,  3025,  3030,  3031,  3032,
    3034,  3040,  3050,  3054,  3058,  3062,  3066,  3070,  3074,  3078,
    3086,  3096,  3101,  3105,  3109,  3113,  3117,  3122,  3126,  3130,
    3138,  3141,  3146,  3147,  3148,  3153,  3154,  3155,  3163,  3166,
    3171,  3172,  3176,  3177,  3182,  3206,  3223,  3224,  3228,  3235,
    3241,  3251,  3253,  3256,  3257,  3258,  3259,  3261,  3264,  3268,
    3273,  3277,  3283,  3284,  3287,  3292,  3293,  3296,  3297,  3298,
    3308,  3309,  3310,  3311,  3312,  3313,  3314,  3315,  3319,  3325,
    3327,  3346,  3354,  3361,  3362,  3363,  3364,  3369,  3370,  3371,
    3372,  3373,  3378,  3379,  3395,  3396,  3397,  3398,  3399,  3400,
    3401,  3402,  3403,  3404,  3406,  3407,  3408,  3409,  3414,  3417,
    3426,  3427,  3428,  3429,  3430,  3431,  3435,  3436
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
  "RECOVER_TABLE", "ROLLFORWARD_DATABASE", "DROP_TRIGGER",
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
       0,   256,  2229,  2230,  2231,  2232,  2233,  2234,  2235,  2236,
    2237,  2238,  2239,  2240,  2241,  2242,  2243,  2244,  2245,  2246,
    2247,  2248,  1001,  1002,  1003,  1004,  1006,  1007,  1012,  1013,
    1014,  1016,  1017,  1019,  1022,  1023,  1024,  1025,  1026,  1027,
    1028,  1031,  1035,  1038,  1054,  1055,  1074,  1077,  1079,  1080,
    1083,  1084,  1085,  1086,  1099,  1100,  1101,  1102,  1118,  1119,
    1120,  1124,  1131,  1132,  1133,  1170,  1171,  1172,  1173,  1174,
    1177,  1178,  1180,  1181,  1182,  1183,  1186,  1187,  1194,  1195,
    1215,  1216,  1217,  1224,  1225,  1226,  1227,  1228,  1229,  1234,
    1235,  1237,  1238,  1239,  1240,  1250,  1256,  1257,  1258,  1259,
    1260,  1271,  1272,  1280,  1281,  1282,  1288,  1296,  1303,  1305,
    1309,  1310,  1312,  1317,  1343,  1344,  1345,  1346,  1359,  1367,
    1369,  1370,  1374,  1375,  1382,  1383,  1386,  1388,  1391,  1397,
    1404,  1407,  1413,  1418,  1424,  1425,  1430,  1432,  1434,  1435,
    1437,  1448,  1455,  1458,  1459,  1460,  1462,  1464,  1467,  1471,
    1473,  1497,  1498,  1500,  1507,  1509,  1510,  1512,  1513,  1514,
    1520,  1521,  1527,  1528,  1530,  1533,  1536,  1537,  1539,  1541,
    1549,  1551,  1554,  1567,  1570,  1571,  1572,  1573,  1575,  1583,
    1586,  1587,  1588,  1592,  1594,  1598,  1599,  1601,  1602,  1604,
    1608,  1612,  1616,  1620,  1621,  1624,  1626,  1627,  1630,  1631,
    1633,  1639,  1643,  1648,  1649,  1652,  1655,  1658,  1660,  1661,
    1663,  1664,  1665,  1674,  1677,  1684,  1686,  1688,  1689,  1690,
    1693,  1694,  1698,  1704,  1705,  1708,  1717,  1722,  1726,  1727,
    1728,  1730,  1733,  1734,  1736,  1737,  1738,  1739,  1740,  1741,
    1742,  1743,  1744,  1745,  1746,  1750,  1755,  1756,  1757,  1758,
    1759,  1766,  1769,  1770,  1776,  1778,  1779,  1782,  1784,  1785,
    1786,  1824,  1828,  1835,  1836,  1839,  1844,  1851,  1852,  2200,
    2221,  2222,  2223,  2224,  2225,  2226,  2227,  2228
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint16 yyr1[] =
{
       0,   278,   279,   280,   280,   280,   281,   281,   281,   282,
     282,   282,   282,   282,   282,   283,   283,   284,   284,   285,
     285,   285,   285,   286,   287,   287,   288,   288,   289,   289,
     290,   291,   291,   291,   291,   292,   292,   293,   293,   294,
     294,   295,   295,   296,   296,   296,   296,   296,   297,   298,
     298,   299,   299,   300,   300,   300,   300,   301,   302,   302,
     302,   302,   302,   302,   302,   302,   302,   302,   302,   302,
     303,   303,   304,   304,   305,   305,   306,   306,   306,   307,
     307,   308,   308,   309,   309,   309,   310,   310,   311,   311,
     311,   311,   311,   311,   311,   312,   312,   313,   313,   314,
     314,   315,   315,   316,   316,   317,   318,   318,   319,   319,
     320,   321,   321,   322,   323,   323,   324,   324,   325,   325,
     326,   326,   327,   327,   328,   329,   331,   330,   333,   332,
     332,   334,   334,   335,   335,   336,   336,   337,   337,   338,
     338,   339,   340,   341,   342,   342,   343,   344,   344,   344,
     344,   344,   344,   344,   345,   345,   345,   346,   346,   346,
     346,   346,   346,   346,   347,   347,   347,   347,   348,   348,
     348,   349,   349,   349,   350,   350,   350,   351,   351,   352,
     352,   352,   352,   352,   352,   353,   353,   354,   354,   355,
     355,   356,   356,   357,   358,   358,   359,   359,   360,   360,
     361,   362,   363,   364,   365,   365,   366,   366,   367,   367,
     367,   368,   368,   369,   369,   369,   370,   370,   370,   370,
     371,   372,   372,   373,   373,   374,   374,   375,   376,   376,
     376,   376,   376,   376,   376,   377,   378,   379,   380,   380,
     381,   381,   382,   383,   384,   385,   385,   385,   385,   385,
     385,   386,   386,   387,   387,   387,   388,   388,   389,   389,
     390,   390,   390,   390,   391,   391,   392,   392,   393,   393,
     394,   394,   395,   395,   396,   396,   397,   397,   398,   398,
     399,   400,   401,   401,   402,   402,   402,   402,   402,   402,
     402,   402,   402,   402,   402,   402,   403,   403,   403,   403,
     403,   403,   404,   404,   404,   404,   405,   405,   405,   405,
     406,   406,   406,   406,   407,   408,   408,   408,   409,   409,
     410,   410,   410,   410,   410,   410,   410,   410,   410,   410,
     410,   410,   410,   410,   410,   410,   410,   410,   410,   410,
     410,   410,   410,   410,   410,   410,   410,   411,   411,   412,
     412,   412,   412,   412,   413,   414,   415,   416,   416,   417,
     417,   417,   418,   418,   419,   419,   420,   420,   420,   420,
     421,   421,   421,   421,   422,   423,   423,   423,   423,   424,
     424,   425,   425,   425,   425,   425,   425,   425,   426,   426,
     426,   426,   426,   426,   426,   426,   427,   427,   427,   428,
     428,   429,   430,   431,   432,   433,   433,   434,   434,   435,
     436,   436,   436,   437,   438,   439,   440,   440,   441,   442,
     442,   443,   443,   443,   444,   445,   445,   446,   446,   447,
     448,   449,   449,   449,   449,   451,   452,   450,   453,   454,
     454,   455,   455,   455,   455,   456,   457,   458,   459,   459,
     460,   460,   460,   460,   461,   461,   462,   462,   462,   463,
     463,   463,   464,   464,   464,   464,   464,   464,   464,   464,
     464,   464,   464,   464,   464,   464,   464,   464,   464,   464,
     464,   464,   464,   464,   464,   464,   464,   464,   464,   464,
     464,   464,   464,   464,   464,   465,   465,   466,   466,   467,
     467,   468,   468,   468,   468,   469,   469,   469,   469,   469,
     469,   470,   470,   470,   470,   471,   471,   472,   472,   472,
     472,   473,   474,   474,   474,   474,   474,   474,   474,   474,
     475,   476,   476,   476,   476,   476,   476,   476,   476,   476,
     477,   477,   477,   477,   477,   477,   477,   477,   478,   479,
     480,   480,   481,   481,   482,   483,   484,   484,   485,   485,
     485,   486,   486,   486,   486,   486,   486,   486,   486,   487,
     488,   489,   490,   490,   490,   491,   491,   492,   492,   492,
     493,   493,   493,   493,   493,   493,   493,   493,   494,   494,
     494,   495,   496,   497,   497,   497,   497,   498,   498,   498,
     498,   498,   499,   499,   500,   500,   500,   500,   500,   500,
     500,   500,   500,   500,   500,   500,   500,   500,   501,   501,
     502,   502,   502,   502,   502,   502,   503,   503
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
       2,     2,     3,     2,     3,     3,     3,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     5,     5,     5,     5,
       5,     3,     4,     4,     4,     4,     4,     4,     4,     4,
       3,     4,     1,     1,     3,     1,     2,     4,     2,     1,
       3,     5,     5,     4,     5,     1,     1,     1,     1,     1,
       1,     5,     3,     5,     3,     1,     3,     1,     1,     2,
       2,     1,     1,     3,     1,     3,     5,     3,     5,     7,
       1,     3,     3,     1,     1,     3,     5,     3,     5,     7,
       3,     1,     1,     3,     5,     3,     5,     7,     1,     1,
       1,     2,     1,     1,     0,     1,     1,     3,     1,     1,
       1,     0,     1,     1,     1,     1,     1,     1,     1,     2,
       1,     1,     0,     1,     2,     1,     3,     1,     3,     5,
       1,     1,     2,     1,     1,     1,     1,     1,     1,     1,
       1,     3,     3,     3,     3,     1,     2,     1,     1,     1,
       1,     1,     1,     1,     1,     3,     3,     3,     5,     5,
       4,     6,     8,     8,     6,     8,    10,    10,     1,     3,
       1,     1,     1,     2,     2,     2,     0,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       0,   568,   150,   151,     0,   149,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     586,     0,   585,     0,   587,   584,     0,   583,   626,     0,
       0,   153,     0,     0,   125,   581,   580,     0,     0,   126,
     142,     0,     0,     0,   143,     0,     0,     0,     0,   448,
       0,     0,   559,   161,    30,   162,    36,    35,   163,   156,
     558,   560,   155,   154,   157,   146,   567,   563,   241,   240,
     158,   159,   160,   398,   397,   396,   571,     0,   566,   556,
     564,   572,   565,   562,   548,     0,   533,    68,   530,   534,
      69,    34,    66,     0,     0,   541,     0,   542,   555,   570,
      62,    63,    67,     0,     0,     0,     0,   358,     0,   236,
     237,   357,   152,     0,   627,   582,     0,    31,     0,   403,
     194,     6,     0,    33,     0,     0,     0,   521,   524,     0,
     401,    32,   552,   553,   144,   174,   169,   168,   181,   180,
     185,   185,   183,   184,   175,   170,     0,     0,   176,   177,
       0,   450,     0,     0,     0,     1,     0,     0,   573,   569,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   111,
     112,     0,     0,     0,    83,    86,    88,    89,    90,    94,
      93,    91,    92,     0,    84,    85,     0,     0,     0,     0,
       0,     0,   235,   238,     0,     0,     0,     0,     0,     0,
       0,   141,   131,   406,   405,   404,     0,     0,     0,     0,
       0,   145,   591,     0,   179,   182,     0,     0,     0,   449,
     452,   453,   451,   435,     0,     0,     0,     0,     0,     0,
       3,     0,     0,   557,     0,   577,   574,   575,   148,   531,
       0,   535,   537,   532,    65,     0,     0,     0,     0,     0,
       0,   215,   214,   213,   118,     0,   120,   122,   124,   113,
       0,   110,   106,    82,    81,     0,     0,   101,   105,     0,
      97,    95,     0,   540,     0,   543,   545,     0,    57,     0,
       0,     0,   239,     0,    79,    64,     0,     0,     0,   196,
     362,     0,   359,     0,   549,     7,   377,   548,   375,   550,
     589,     0,     0,     0,   409,   413,   475,     0,   379,   469,
       0,     0,     0,   468,     0,     0,   474,     0,     0,     0,
     470,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   473,   471,   472,     8,   264,   266,
     268,   304,   302,   270,   467,   492,   407,   493,   410,   378,
     622,   305,   620,   303,   604,   376,   621,   590,   588,   459,
     618,     0,     0,   523,     0,   402,     0,   525,   527,   399,
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
     272,     0,   306,     0,     0,     0,     0,   495,     0,   625,
       0,     0,   623,   624,   306,     0,   306,   306,   460,   269,
     306,   461,   551,     0,     0,     0,     0,     0,   301,     0,
       0,   300,     0,   298,     0,     0,   296,   297,     0,   283,
       0,   299,     0,     0,     0,     0,     0,   505,   506,   507,
     508,   509,   510,     0,     0,     0,     0,   463,     0,     0,
     133,   135,   128,   127,   130,     0,     0,     0,   186,     0,
       0,     0,   436,   454,   456,     0,    10,     0,    11,    18,
       0,     0,     0,    19,     0,     0,     4,     5,     0,     0,
     578,   576,   536,     0,   538,     0,   203,   206,     0,   211,
       0,   115,     0,   116,     0,   429,     0,   119,   121,   123,
     107,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   219,   218,   217,     0,   222,
     223,   102,     0,    96,     0,    98,   544,     0,   546,     0,
      74,    78,     0,     0,     0,    71,    39,    80,     0,    46,
      47,     0,     0,    37,    40,    41,   197,   373,   359,     0,
       0,   450,   199,   193,   481,   499,     0,     0,   592,     0,
       0,     0,   450,   271,   490,   379,     0,     0,   621,   308,
     309,   307,     0,     0,   498,     0,   494,   496,     0,     0,
       0,     0,     0,     0,     0,     0,   265,   267,     0,     0,
       0,   274,   280,   278,   276,   274,     0,   514,   288,   287,
     278,     0,   512,   276,   285,   284,     0,   286,   595,     0,
     603,   602,     0,     0,   605,   606,   607,   464,   462,   466,
     465,   619,   132,     0,     0,     0,   400,   526,     0,   528,
     188,   190,   165,     0,   554,     0,   457,    27,     0,    25,
      22,   359,    16,    23,   171,     0,     0,     0,     0,   210,
       0,   209,   118,   208,   200,   109,   354,     0,     0,     0,
       0,     0,     0,   355,   347,     0,     0,     0,     0,   347,
       0,     0,   375,   216,   229,   234,     0,   231,   228,   230,
       0,   232,   220,   224,   225,   118,   104,   100,     0,    49,
       0,    77,    76,    49,    49,    49,    70,    45,    44,    48,
      43,    42,   371,   360,     0,     0,     0,   482,     0,     0,
     486,   487,   394,   392,   393,   389,   391,   388,   390,   380,
       0,     0,     0,     0,   491,     0,     0,   484,     0,   489,
     483,   488,     0,   485,     0,     0,     0,   408,     0,   412,
       0,   295,     0,   291,     0,   293,   294,     0,   518,     0,
     515,   517,   290,     0,   292,     0,     0,   610,   599,   600,
       0,   598,   601,   597,     0,   596,     0,     0,   134,   136,
       0,     0,   455,   256,   458,     0,     0,    20,   172,     0,
     164,   579,   539,   201,   207,   212,   117,   319,   332,   334,
       0,   336,     0,   338,     0,     0,   323,   345,     0,   321,
     349,     0,   432,   434,   202,   204,     0,   226,   227,   547,
      55,    56,     0,     0,    59,    50,    51,    75,    58,    60,
      61,    38,     0,   359,   256,   500,   609,     0,   256,     0,
       0,     0,     0,   480,   497,   476,   477,   478,   479,     0,
     275,   281,   279,   277,   519,   520,   513,     0,   511,     0,
     593,     0,   594,     0,   608,   140,     0,   137,   139,   529,
       0,   260,   439,     0,   359,   173,     0,     0,   356,   348,
     325,     0,   326,     0,     0,    53,    54,    52,   361,   372,
     446,     0,     0,     0,     0,   380,     0,     0,     0,   516,
     289,   614,   611,     0,     0,   129,     0,   244,   245,   253,
       0,     0,     0,   263,   260,   257,   258,   261,   310,   441,
       9,    21,   335,     0,   346,     0,   233,     0,   395,   447,
     501,   504,   502,   411,     0,     0,   138,     0,     0,     0,
       0,   254,   374,   428,     0,   369,   427,   364,   424,   425,
       0,   359,   242,   243,   259,   262,   312,   313,   311,     0,
       0,     0,   442,   437,   341,   205,   613,     0,   615,   612,
       0,     0,   251,     0,     0,     0,   246,   255,   365,     0,
       0,   366,   448,   440,    72,   445,     0,     0,     0,     0,
       0,     0,     0,     0,   247,   426,   368,   359,   450,    73,
     444,   419,   420,   415,   416,   421,    72,   617,   616,   252,
     249,   250,     0,   367,     0,     0,   423,   422,   418,   443,
     248,   256,   417,   439,   438
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    52,   397,   201,   230,   392,   393,   389,   394,   390,
     381,   382,    53,    54,    55,    56,   643,   644,   645,   800,
     914,   915,   916,   277,    57,   636,  1090,   629,   630,   283,
     261,    58,   174,   175,   176,   271,   449,   177,   446,   267,
     178,   417,   262,   179,   180,   181,   409,   414,   182,   256,
     257,    59,    60,   122,   553,   725,   362,   549,   550,   956,
     957,    61,    62,    63,   212,    64,    65,    66,    67,    68,
     146,   880,   147,   148,   149,   214,   370,   373,   374,    69,
     198,   288,   653,   251,   252,   781,   585,   904,   586,   253,
     588,   263,   619,   264,   620,   782,   783,   784,   785,    70,
     108,   109,   192,    71,  1003,  1004,   961,  1062,  1063,   998,
     962,  1005,  1006,   595,   338,   339,   340,   341,   841,   845,
     843,   691,   940,   533,   342,   534,   343,   672,  1049,   440,
     441,   442,   443,   895,   444,   757,   764,   969,   375,   467,
     589,  1036,  1037,   290,  1031,   344,   485,   486,   819,    72,
      73,   129,   364,    74,    75,   205,   345,   346,   347,   348,
     349,  1052,  1093,  1094,  1095,  1108,  1007,  1038,  1039,   596,
     469,   445,    76,   378,   734,  1073,  1009,  1053,  1074,   470,
     350,   151,   223,   562,   563,   351,   352,   496,   497,   656,
     667,   547,   353,   849,   850,   291,   127,   999,    88,    96,
     354,   295,   355,   134,   873,    99,    77,    78,    79,    80,
     100,    81,   159,   236,   237,    82,   356,    83,   357,   712,
     864,   713,   358,   359,   360,   115
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -885
static const yytype_int16 yypact[] =
{
    2002,  -885,  -885,  -885,   152,  -885,   369,   152,   152,   369,
     369,   152,   415,   152,   152,   369,   415,   415,   415,   415,
    -885,   487,  -885,   152,  -885,  -885,   369,  -885,   159,   369,
     369,  -885,   369,   369,  -885,  -885,  -885,   369,   369,  -885,
    -885,   415,   369,   535,  -885,   152,   369,   580,   504,   -15,
     369,   504,  -885,  -885,  -885,  -885,  -885,  -885,  -885,  -885,
    -885,  -885,  -885,  -885,  -885,  -885,  -885,  -885,  -885,  -885,
    -885,  -885,  -885,  -885,  -885,  -885,  -885,   194,  -885,  -885,
    -885,   230,  -885,  -885,  -885,   148,   -49,  -885,  -885,   435,
    -885,  -885,  -885,    -7,   443,     1,   349,   295,  -885,  -885,
    -885,  -885,  -885,    15,    41,   155,   185,  -885,    17,  -885,
    -885,  -885,  -885,   126,  -885,  -885,   127,  -885,   170,  -885,
     181,   -44,   369,  -885,   122,   218,   231,  -885,   302,   223,
    -885,  -885,  -885,  -885,   373,  -885,  -885,  -885,  -885,  -885,
     322,   322,  -885,  -885,  -885,  -885,   290,   253,   296,  -885,
     559,   228,   367,   305,   320,  -885,  2002,   606,  -885,  -885,
     577,   152,   646,   152,   152,   581,   456,    80,   622,  -885,
    -885,   289,   116,   301,   403,  -885,  -885,  -885,  -885,  -885,
    -885,  -885,  -885,   152,  -885,  -885,   705,   152,   369,   369,
     369,   369,    17,  -885,   215,   369,   215,    79,   392,   651,
     983,  -885,   478,  -885,  -885,  -885,   152,   152,   718,   152,
     152,  -885,  -885,    79,  -885,  -885,   120,   369,   849,  -885,
    -885,  -885,  -885,  -885,  1205,  1205,  1205,  1205,    59,    59,
       2,   120,   369,  -885,   410,   416,   417,  -885,   621,  -885,
     419,  -885,   440,  -885,  -885,   520,   524,   536,   649,   537,
     547,  -885,  -885,  -885,   614,   152,   457,  -885,  -885,  -885,
     215,  -885,  -885,  -885,  -885,   749,   152,  -885,  -885,   215,
     468,  -885,   443,  -885,   477,  -885,   497,   584,  -885,   597,
     598,   607,  -885,   -22,  -885,  -885,   -13,   535,     7,  -885,
    -885,   499,   460,   600,  -885,  -885,  -885,   612,   540,  -885,
    -885,   791,   620,   625,  -885,  -885,  -885,   632,   379,  -885,
     930,   632,   635,  -885,   636,   638,  -885,    75,   639,   632,
    -885,   643,   648,   632,   632,   650,   658,   661,   676,  1784,
     613,   677,  1784,   821,  -885,  -885,  -885,   603,   628,  -885,
    -885,  -885,  -885,  -885,  -885,  -885,   379,  -885,   379,  -885,
    -885,  1999,  -885,  -885,   -24,  -885,  -885,  -885,  -885,   421,
     763,   152,   234,  -885,   608,  -885,   615,  -885,   629,  -885,
      32,  -885,  -885,   634,  -885,  -885,   655,  -885,  1649,  1287,
    -885,    34,  -885,  -885,    46,   641,   641,   152,  -885,  -885,
      78,    56,   653,   691,  -885,   651,   983,  -885,   634,   631,
     152,   152,   606,  -885,   152,   739,    79,    79,    79,   103,
     614,    79,   983,   152,  -885,   107,   152,   124,  -885,  -885,
    -885,   707,   710,   719,   379,   379,  -885,   720,  -885,   724,
     725,   729,   730,   731,  -885,  -885,  -885,  -885,   737,   743,
     521,  -885,  -885,  -885,  -885,  -885,   138,  -885,  -885,   164,
     152,  -885,   152,   748,   152,   152,   152,   152,   766,   215,
     154,  -885,  -885,    79,    76,   920,   152,  -885,   -15,   822,
    -885,  1340,   152,   903,  1649,  1649,   734,  -885,  -885,  -885,
    -885,  -885,  -885,  -885,  -885,  -885,   668,   -15,   -64,  2039,
    -885,  1702,   246,  1649,  1649,   983,   359,  -885,  1649,  -885,
    1649,  1649,  -885,  -885,   246,  1649,   246,   246,   421,  -885,
     246,   421,  -885,   983,   983,   669,   -45,  1784,  -885,  1784,
    1784,  -885,  1784,  -885,   752,  1427,  -885,  -885,  1784,  -885,
     753,  -885,  1784,   399,  1649,    93,    53,  -885,  -885,  -885,
    -885,  -885,  -885,  1649,  1649,  1649,  1649,  -885,   749,   186,
    -885,   679,  -885,  -885,  -885,   152,   152,   765,  -885,    79,
     120,   120,   696,  -885,    62,   776,  -885,  1205,  -885,  -885,
     755,    59,   108,  -885,    59,  1205,  -885,   603,   120,   690,
    -885,  -885,  -885,   692,  -885,   784,   709,  -885,   187,  -885,
     195,  -885,   649,  -885,   198,   603,   787,  -885,  -885,  -885,
    -885,   215,   951,   951,   952,   699,   -37,   957,   958,   959,
     960,   957,   957,   962,   964,  -885,  -885,  -885,    87,  -885,
     381,  -885,   152,  -885,   215,  -885,  -885,   714,  -885,   202,
    -885,   227,   219,   255,   259,  -885,   154,  -885,   968,  -885,
    -885,   969,   970,  -885,   154,  -885,  -885,  -885,   792,   -25,
     726,   228,  -885,  -885,  -885,  -885,   293,   727,  -885,   300,
     304,   494,   228,  -885,  -885,   271,   738,   811,   746,  -885,
    -885,  -885,  1649,   306,  -885,   -28,  -885,  -885,   324,   352,
     362,  1649,   363,  1649,  1649,  1649,   628,  -885,   494,   987,
     494,   813,   421,   814,   817,   813,    94,  -885,  -885,  -885,
     814,    94,  -885,   817,  -885,  -885,  1649,  -885,  -885,    93,
    -885,  -885,   405,   988,  -885,  -885,    81,  -885,  -885,  -885,
    -885,  -885,  -885,   152,   152,   827,  -885,  -885,   750,  -885,
    -885,  -885,   634,  1649,  -885,   152,  -885,  -885,   829,  -885,
    -885,   102,  -885,  -885,    85,   152,   152,   861,    79,  -885,
      79,  -885,   614,  -885,  -885,  -885,  -885,   843,   846,   364,
     494,  1009,   494,  -885,   771,   851,   365,   852,   854,   771,
     855,   856,  -885,  -885,  -885,  -885,   369,  -885,  -885,  -885,
     844,  -885,  -885,   381,  -885,   614,  -885,  -885,   152,    44,
     152,  -885,  -885,    44,    44,    44,   766,  -885,  -885,  -885,
    -885,  -885,  -885,  -885,  1026,   152,  1649,  -885,  1649,   152,
    -885,  -885,   857,  -885,  -885,  -885,  -885,  -885,  -885,  -885,
    1649,   379,   779,   379,  -885,   379,   871,  -885,  1649,  -885,
    -885,  -885,   875,  -885,   876,   878,   879,  -885,   883,  -885,
      87,  -885,    87,  -885,    87,  -885,  -885,    58,  -885,   366,
    -885,  -885,  -885,   372,  -885,   815,    11,  -885,  -885,  -885,
      93,  -885,  -885,  -885,    93,  -885,    93,   152,  -885,  -885,
    1562,   152,  -885,   828,  -885,  1205,   152,  -885,  -885,   487,
    -885,  -885,  -885,  -885,  -885,  -885,  -885,  -885,  -885,  -885,
    1048,  -885,   888,  -885,  1051,   891,  -885,  -885,  1055,  -885,
    -885,   894,  -885,  -885,  -885,   882,   983,  -885,  -885,  -885,
    -885,  -885,   970,  1061,  -885,    44,  -885,  -885,  -885,  -885,
    -885,  -885,   895,   792,    25,  -885,   881,  1065,    25,   818,
     494,   820,   823,  -885,  -885,  -885,  -885,  -885,  -885,   824,
    -885,  -885,  -885,  -885,  -885,  -885,  -885,   131,  -885,  1649,
    -885,   508,   663,   486,   885,  -885,   384,  -885,  -885,  -885,
     369,   114,   858,   385,   792,  -885,   910,   825,  -885,  -885,
    -885,   911,  -885,    79,   912,  -885,  -885,  -885,  -885,  -885,
    -885,    93,   916,   917,   494,   921,   494,   494,   494,  -885,
    -885,  -885,  -885,    93,    93,  -885,  1562,    73,  -885,    72,
      65,   983,   983,  -885,    97,  -885,  -885,   904,   262,   -34,
    -885,  -885,  -885,   494,  -885,   393,  -885,   511,  -885,  -885,
    -885,  -885,  -885,  -885,   539,   599,  -885,   169,   169,   123,
     152,  -885,  -885,  -885,    68,  -885,  -885,  -885,   847,  -885,
     832,   495,   603,   603,  -885,  -885,  -885,  -885,  -885,   897,
     152,   836,   942,  -885,  -885,  -885,  -885,    93,  -885,  -885,
      93,   369,    73,   835,   837,   192,  -885,  -885,  -885,    65,
     128,  -885,   -15,  -885,   966,  -885,   101,   152,   558,   589,
      77,   983,   983,   369,  -885,  -885,  -885,   792,   228,  -885,
    -885,  -885,  -885,   860,  -885,   260,   966,  -885,  -885,  -885,
     603,   603,    90,  -885,  1649,   101,  -885,  -885,  -885,  -885,
    -885,    25,  -885,   858,  -885
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -885,  -885,  -885,  -885,  -885,  -885,  -177,   711,   525,  -885,
    -195,  -275,  -885,  -885,  -885,  -885,   464,  -885,   459,   193,
    -100,  -885,   189,   517,  -885,   311,    13,   310,   323,   914,
    -129,  -885,  -885,   842,  -885,  -219,  -885,  -885,  -885,  -246,
    -885,  -885,  -208,  -885,  -885,  -885,  -885,  -363,  -885,   862,
     700,  -885,  -885,  -885,  -885,  -885,  -885,  -885,   395,  -885,
     119,  -885,  -885,  -885,  -885,  -885,  -885,  -885,  -885,  -885,
    1068,  -885,  1070,  -885,   906,   981,  -885,  -183,   565,  -885,
    -885,  -885,  -885,  -885,  -885,   383,  -885,  -885,   153,  -885,
    -264,  -145,  -885,  -885,  -885,  -885,  -885,   344,  -885,  -885,
    -885,  -885,  -885,   -31,   121,  -885,  -885,  -835,   105,  -884,
    -809,  -885,   130,  -182,   618,   623,   805,  -885,   441,   438,
     442,   482,  -249,  -885,  -885,  -885,  -885,   380,  -885,   590,
    -885,  -885,  -885,   374,  -885,   541,   -67,  -885,    -5,  -364,
    -173,  -720,   111,   864,   118,  -565,  -885,  -303,  -596,  -885,
    -885,   939,   601,  -885,  -885,  -885,  -885,  -885,  -885,  -885,
    -885,  -885,  -885,    47,  -885,  -885,  -885,  -885,    84,   248,
    -885,  -885,  -885,  -885,  -885,  -885,    42,  -885,    92,   796,
    -169,  -433,  -602,  -750,   434,    98,  -885,  -885,   675,   439,
    -885,  -885,  -885,   471,   232,   -42,  -885,    49,  -885,   816,
      -4,   780,   327,  -885,  -885,  -885,  -885,  -885,  1028,  -885,
    1173,  -885,  -885,  -885,   786,  -885,  -455,  -885,  -885,  -686,
    -885,  -885,  -885,   -47,  -885,  -885
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -562
static const yytype_int16 yytable[] =
{
      85,   126,    89,    90,    91,    89,    89,    94,    97,    98,
      98,    89,    97,    97,    97,    97,   110,   111,   337,   112,
     447,   254,    89,   856,   289,    89,    89,   573,    89,    89,
     384,   385,   386,    89,    89,   651,   668,    97,    89,   128,
     371,   130,    89,   515,   270,   516,    89,   593,   398,   806,
     448,   388,   418,   773,   662,    87,   924,    84,    92,    93,
     820,   944,   199,    84,   102,   284,    84,   284,  1033,    84,
     928,   125,    84,   299,   125,   113,    84,   193,   116,   117,
      84,   118,   119,    84,    84,   125,   120,   121,   910,   911,
     296,   124,   837,   772,   839,   131,   708,   296,    84,   152,
     298,   663,   299,   410,  1091,    84,  1027,   125,   395,   299,
    1027,   300,    84,  1028,   301,   980,  1050,  1028,    89,   983,
      84,   605,   606,  1027,    84,   997,   107,    84,   488,    86,
    1028,   848,    84,   689,   296,    84,   848,   298,   477,    37,
     270,   761,   490,   458,   590,  1066,   299,   594,   300,   803,
     499,   301,   460,   235,   502,   503,    84,   239,   241,   242,
     243,   282,   114,   258,   891,   535,   893,   265,   268,   265,
     200,   202,   462,    84,   951,    86,   950,  1051,   952,   273,
     953,  1084,   275,   276,    89,    89,    89,    89,   150,   878,
     265,    89,   265,   292,   155,   513,    84,   558,    86,   566,
     160,   828,   363,   365,   367,   368,   130,   161,    48,   292,
     156,   568,   111,    89,   577,   690,   396,   804,   638,    84,
     459,   858,    51,   762,   391,   391,  1080,   111,    89,   459,
     859,   513,   536,   587,   203,   639,   640,   278,   278,   278,
     278,   851,  1099,   570,   285,   465,   851,   960,  1102,   463,
     165,   258,  1000,   204,   308,  1110,   265,   183,   255,   861,
     862,   308,   268,   714,   863,   265,   376,   733,   591,  1000,
     866,   709,   598,   188,   559,   941,   567,   941,   641,   941,
    1001,   399,   508,   292,   802,   511,   647,   487,   567,   600,
     646,   465,   737,    84,   266,  1017,   494,  1001,   308,   189,
     743,   912,  1113,   621,   194,    84,   495,  1024,  1025,   913,
     372,   387,   572,   675,   333,  1029,   735,  1034,   740,  1029,
     571,   715,   383,   383,   383,   383,  1030,   560,  1002,   623,
     637,   287,  1029,  1035,   985,  1065,  1035,   867,  1086,   879,
     245,   710,   847,   333,   246,   592,   711,  1061,   196,   416,
     333,   722,   749,  1034,  1111,   697,  1092,   551,   876,   197,
     751,   702,   822,   753,   157,   158,   601,   789,   247,  1035,
    1083,  1078,   195,    84,  1079,    86,   786,   877,   732,   847,
     622,   220,   848,   391,   793,  1092,   730,   333,  1020,   886,
    1021,  1022,  1023,   755,   739,   744,   579,   580,   235,   669,
     582,   584,   292,   292,   292,   787,   624,   292,   489,   597,
     249,   642,   258,   190,   245,  1046,   250,  1054,   246,    84,
     794,    95,   908,   221,   795,   478,   245,   468,   723,   750,
     246,   552,   224,   225,   226,   227,   228,   750,   184,   185,
     750,   670,   247,   191,   790,   791,   625,   752,   626,   628,
     631,   631,   631,   631,   247,   265,   479,  1047,   807,   292,
     648,   790,   650,   480,   222,   810,   792,   260,   657,   811,
     692,   827,   692,   692,   206,   692,   564,   565,  1106,   269,
     481,   692,   671,   210,   249,   692,  1104,   207,   774,   829,
     250,    84,   851,   107,   482,   270,   249,   790,  1048,  1107,
     213,   790,   250,   483,   537,   538,   539,   540,   541,   542,
     775,   217,   216,   821,   484,   166,   167,   830,   929,   776,
     931,   211,   932,   168,   169,   170,   704,   831,   833,   889,
     897,   946,   716,   478,   777,   808,   186,   948,   218,    84,
     778,   125,   808,   208,   768,   769,   808,   187,   808,   995,
    1010,   365,   727,   729,   209,   292,   111,   111,  1055,   979,
     736,   705,   219,   706,   479,   231,   808,   391,   741,   655,
     391,   480,   655,   655,   111,   884,   779,   885,   232,   857,
     494,   245,   780,   238,   132,   246,   133,   244,   481,   666,
     495,   655,   674,   942,   808,   943,   655,   265,   655,   655,
    1011,   229,   482,   655,   808,   808,   890,   898,   947,   247,
      84,   483,   234,   135,   947,   858,   296,   297,   268,   298,
     265,   676,   484,   699,   859,   259,   996,   567,   299,   171,
     300,   543,   707,   301,   248,   748,   615,   616,   617,  1088,
     544,   717,   718,   719,   720,   272,   293,   860,   812,   465,
      84,   249,   240,   861,   862,   294,   361,   250,   863,   402,
     992,   302,   303,   172,   136,   383,   400,   304,   305,   545,
     137,   403,   401,   383,   546,   404,   162,  1071,   173,   813,
     963,   405,   991,   138,   465,  1056,   814,   163,   139,   413,
     618,   164,   306,   918,   919,   920,   858,   140,   406,   416,
     141,   208,   407,   815,   142,   859,   279,   280,   281,    84,
     143,   274,   209,  1058,   408,   411,   466,   816,   858,   551,
     869,   858,    84,  1103,   366,   412,   817,   859,   993,   450,
     859,   874,  1097,   452,   861,   862,   208,   818,   453,   863,
     144,   881,   882,    84,   292,   583,   292,   209,   145,   858,
     307,  -524,    84,  1057,   627,   464,   861,   862,   859,   861,
     862,   863,   454,  1098,   863,   632,   633,   634,   858,    84,
     826,   728,    89,  1059,   245,   455,   456,   859,   246,   832,
     308,   834,   835,   836,   909,   457,   631,   861,   862,   309,
     471,   310,   863,   468,   311,   312,   472,   473,   474,   858,
     587,   923,   247,   475,   855,   926,   861,   862,   859,   858,
     476,   863,   313,   491,   492,   314,   493,   498,   859,  1042,
    1043,   500,   315,   316,   512,   905,   501,   419,   504,   317,
     318,   564,   103,   104,   105,   106,   505,   861,   862,   506,
     319,  1060,   863,   320,   249,   321,   322,   861,   862,   323,
     250,   324,   863,   325,   507,   510,   326,   123,   548,   327,
     328,   329,   513,   954,   331,   514,   332,   959,   555,   333,
     557,   556,   964,   858,   965,   111,   560,   561,   575,   334,
     335,   336,   859,   567,   681,   602,   683,   684,   603,   420,
     685,   578,   421,   422,   423,   574,   635,   604,   607,  1100,
    1101,   424,   608,   609,   564,   425,   925,   610,   611,   612,
     426,   861,   862,   659,   660,   613,   863,   427,   564,   428,
     429,   614,   430,   649,   658,   652,   934,   487,   661,   688,
     696,   701,   673,   296,   297,   724,   298,   678,   733,   679,
     680,   664,   738,   431,   682,   299,   745,   300,   746,   747,
     301,   748,   754,   432,   756,   759,    89,   433,  1040,   760,
     763,   765,   766,   767,   434,   770,   435,   771,   958,   292,
     788,   797,   798,   383,   799,   436,   824,   437,   302,   303,
     823,   465,   805,   809,   304,   305,   296,   297,   825,   298,
     838,   865,  1040,   840,   842,  1032,  1041,   844,   299,   776,
     300,   693,   694,   301,   695,   870,   871,   875,   887,   306,
     700,   888,   892,   894,   703,   438,   896,   899,   439,   900,
     902,   903,   906,    89,    89,    89,  1032,  1040,   138,   922,
    1041,   302,   303,   139,  1040,   927,   933,   304,   305,   930,
     935,   936,   140,   937,   938,   141,  1075,   990,   939,   142,
     960,   966,   949,   967,   968,   143,   970,    89,   971,   972,
     973,    89,   306,  1040,   976,  1041,  1087,   307,   982,   978,
     981,  1008,  1041,  1075,   994,  1012,  1014,  1016,   984,    89,
     986,  1018,  1019,   987,   988,  1013,  -503,  1001,  1070,  1069,
    1072,  1076,  1077,  1081,   958,  1082,  1089,   308,   569,   742,
     796,  1041,  1105,   801,   977,   975,   309,   921,   310,  1109,
     286,   311,   312,   917,   451,  1026,   599,   415,   868,   153,
     307,   154,   215,   487,   377,   731,  1015,   907,  1045,   313,
     883,   686,   314,  1064,  1044,   509,   846,   687,   721,   315,
     316,   854,   852,   901,   758,  1068,   317,   318,  1067,   369,
     308,   461,  1112,  1085,   974,  1114,   726,   319,   554,   309,
     320,   310,   321,   322,   311,   312,   323,   872,   324,  1096,
     325,   677,   853,   326,   945,   576,   327,   328,   329,   989,
     330,   331,   313,   332,   233,   314,   333,   101,   581,     0,
       0,     0,   315,   316,     0,     0,   334,   335,   336,   317,
     318,     0,   564,     0,     0,     0,     0,     0,   296,   297,
     319,   298,     0,   320,     0,   321,   322,     0,     0,   323,
     299,   324,   300,   325,     0,   301,   326,     0,     0,   327,
     328,   329,     0,   330,   331,     0,   332,     0,     0,   333,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   334,
     335,   336,     0,   302,   303,     0,     0,     0,     0,   304,
     305,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   306,     0,     0,     0,     0,     0,
     296,   297,     0,   298,     0,     0,     0,     0,     0,     0,
       0,     0,   299,     0,   300,     0,     0,   301,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   302,   303,     0,     0,     0,
       0,   304,   305,   296,   297,     0,   298,     0,     0,     0,
       0,     0,     0,     0,     0,   299,     0,   300,     0,     0,
     301,     0,     0,     0,     0,     0,   306,     0,     0,     0,
       0,     0,   308,     0,     0,     0,     0,     0,     0,     0,
       0,   309,     0,   379,     0,     0,     0,   312,   302,   303,
       0,     0,     0,     0,   304,   305,     0,     0,     0,     0,
       0,     0,     0,   380,   313,     0,     0,   314,     0,     0,
       0,     0,     0,     0,   315,   316,     0,     0,     0,   306,
       0,   317,   318,     0,     0,     0,     0,     0,     0,     0,
     296,   297,   319,   298,     0,   320,     0,   321,   322,     0,
       0,   323,   299,   324,   300,   325,     0,   301,   326,     0,
       0,   327,   328,   329,   308,     0,   331,     0,   332,     0,
       0,   333,     0,   309,     0,   379,     0,     0,     0,   312,
       0,   334,   335,   336,     0,   302,   303,     0,     0,     0,
     487,   304,   305,     0,     0,     0,   313,     0,     0,   314,
       0,     0,     0,     0,     0,     0,   315,   316,     0,     0,
       0,     0,     0,   317,   318,   654,   306,   308,     0,     0,
       0,     0,     0,     0,   319,     0,   309,   320,   379,   321,
     322,     0,   312,   323,     0,   324,     0,   325,     0,     0,
     326,     0,     0,   327,   328,   329,     0,     0,   331,   313,
     332,     0,   314,   333,     0,     0,     0,     0,     0,   315,
     316,     0,     0,   334,   335,   336,   317,   318,     0,     0,
       0,     0,     0,     0,     0,   296,   297,   319,   298,     0,
     320,     0,   321,   322,     0,     0,   323,   299,   324,   300,
     325,     0,   301,   326,     0,     0,   327,   328,   329,     0,
       0,   331,     0,   332,   308,     0,   333,     0,     0,     0,
       0,     0,     0,   309,     0,   379,   334,   335,   336,   312,
     302,   303,     0,     0,     0,     0,   304,   305,     0,     0,
       0,     0,     0,     0,     0,   698,   313,     0,     0,   314,
       0,     0,     0,     0,     0,     0,   315,   316,     0,     0,
       0,   306,     0,   317,   318,     0,     0,     0,     0,     0,
       0,     0,   296,   297,   319,   298,     0,   320,     0,   321,
     322,     0,     0,   323,   299,   324,   300,   325,     0,   301,
     326,     0,     0,   327,   328,   329,     0,     0,   331,     0,
     332,     0,     0,   333,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   334,   335,   336,     0,   302,   303,     0,
       0,     0,     0,   304,   305,   296,   297,     0,   298,     0,
       0,     0,     0,     0,     0,     0,     0,   299,     0,   300,
       0,     0,   301,     0,     0,     0,     0,     0,   306,   308,
       0,     0,     0,     0,     0,     0,     0,     0,   309,     0,
     379,     0,     0,     0,   312,     0,     0,     0,     0,     0,
     302,   303,     0,     0,     0,     0,   304,   305,     0,     0,
     955,   313,     0,     0,   314,     0,     0,     0,     0,     0,
       0,   315,   316,     0,     0,     0,     0,     0,   317,   318,
       0,   306,     0,     0,     0,     0,     0,   296,   297,   319,
     298,     0,   320,     0,   321,   322,     0,     0,   323,   299,
     324,   300,   325,     0,   301,   326,     0,     0,   327,   328,
     329,     0,     0,   331,     0,   332,   308,     0,   333,     0,
       0,     0,     0,     0,     0,   309,     0,   379,   334,   335,
     336,   312,   302,   303,     0,     0,     0,     0,   304,   305,
       0,     0,     0,     0,     0,     0,     0,     0,   313,     0,
       0,   314,     0,     0,     0,     0,     0,     0,   315,   316,
       0,     0,     0,   306,     0,   317,   318,     0,     0,   665,
       0,     0,     0,     0,     0,     0,   319,     0,   309,   320,
     379,   321,   322,     0,   312,   323,     0,   324,     0,   325,
       0,     0,   326,     0,     0,   327,   328,   329,     0,     0,
     331,   313,   332,     0,   314,   333,     0,     0,     0,     0,
       0,   315,   316,     0,     0,   334,   335,   336,   317,   318,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   319,
       0,     0,   320,     0,   321,   322,     0,     0,   323,     0,
     324,     0,   325,     0,     0,   326,     0,     0,   327,   328,
     329,   308,     0,   331,     0,   332,     0,     0,   333,     0,
     309,     0,   379,     0,     0,     0,   312,     0,   334,   335,
     336,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   313,     0,     0,   314,     0,     0,     0,
       0,     0,     0,   315,   316,     0,     0,     0,     0,     0,
     317,   318,  -561,     1,     0,     0,     0,     0,     0,     0,
       0,   319,     0,     0,   320,     0,   321,   322,  -561,     0,
     323,     0,   324,     0,   325,     0,     0,   326,     0,     0,
     327,   328,     0,     0,     0,   331,     0,     0,     0,     0,
     333,     0,     0,     0,     0,     0,     0,     0,     2,     3,
     334,   335,   336,     4,     0,     5,     0,     0,     6,     7,
       8,     9,    10,     0,    11,    12,     0,     0,     0,     0,
       0,     0,    13,    14,     0,     0,    15,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    16,    17,    18,    19,     0,    20,    21,
      22,    23,    24,    25,    26,     0,     0,    27,     0,     0,
      28,     0,    29,    30,     0,    31,    32,     0,     0,     0,
      33,    34,    35,    36,    37,    38,  -282,   517,    39,     0,
       0,     0,     0,     0,    40,    41,     0,     0,    42,     0,
       0,    43,     0,    44,    45,     0,     0,     0,   518,    46,
       0,     0,     0,    47,     0,     0,   519,   520,     0,     0,
       0,  -282,   521,  -282,     0,     0,     0,   517,     0,     0,
       0,   522,     0,     0,   523,     0,   524,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   525,   526,   518,     0,
       0,     0,     0,    48,     0,    49,   519,   520,    50,     0,
       0,     0,   521,     0,   664,     0,   527,    51,     0,     0,
       0,   522,     0,     0,   523,     0,   524,     0,     0,     0,
       0,     0,     0,     0,   528,     0,   525,   526,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   527,     0,     0,   529,
       0,     0,     0,     0,     0,     0,   530,     0,     0,     0,
       0,     0,   531,   532,   528,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  -305,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   529,
       0,     0,     0,     0,     0,     0,   530,     0,  -305,     0,
       0,     0,   531,   532
};

static const yytype_int16 yycheck[] =
{
       4,    43,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    21,    21,   200,    23,
     266,   166,    26,   709,   197,    29,    30,   391,    32,    33,
     225,   226,   227,    37,    38,   468,   491,    41,    42,    43,
     213,    45,    46,   346,   173,   348,    50,   410,   231,   651,
     269,   228,   260,   618,   487,     6,   806,     4,     9,    10,
     662,     3,   106,     4,    15,   194,     4,   196,     3,     4,
     820,     6,     4,    15,     6,    26,     4,   108,    29,    30,
       4,    32,    33,     4,     4,     6,    37,    38,    44,    45,
       3,    42,   688,     6,   690,    46,     3,     3,     4,    50,
       6,   165,    15,   248,     3,     4,    33,     6,   106,    15,
      33,    17,     4,    40,    20,   924,   150,    40,   122,   928,
       4,   424,   425,    33,     4,   960,     6,     4,   310,     6,
      40,   696,     4,   178,     3,     4,   701,     6,   307,   122,
     269,   178,   311,   165,   408,  1029,    15,   411,    17,   174,
     319,    20,   165,   157,   323,   324,     4,   161,   162,   163,
     164,   192,     3,   167,   760,   189,   762,   171,   172,   173,
     214,   122,   165,     4,   860,     6,   165,   211,   864,   183,
     866,  1065,   186,   187,   188,   189,   190,   191,   203,   104,
     194,   195,   196,   197,     0,   259,     4,   165,     6,   165,
      52,   229,   206,   207,   208,   209,   210,   256,   191,   213,
      16,   165,   216,   217,   396,   260,   214,   242,    64,     4,
     242,   210,   205,   260,   228,   229,  1061,   231,   232,   242,
     219,   259,   256,   406,   112,    81,    82,   188,   189,   190,
     191,   696,   165,   165,   195,   189,   701,   222,  1083,   242,
     257,   255,   155,   131,   167,   165,   260,   256,   178,   248,
     249,   167,   266,   210,   253,   269,   217,   242,   165,   155,
     189,   178,   165,   258,   242,   840,   242,   842,   124,   844,
     183,   232,   329,   287,   648,   332,   210,   193,   242,   165,
     463,   189,   567,     4,   178,   981,   221,   183,   167,   258,
     575,   257,  1111,   165,   178,     4,   231,   993,   994,   265,
     190,   252,   256,   495,   256,   242,   254,   252,   210,   242,
     242,   268,   224,   225,   226,   227,   254,   242,   214,   165,
     459,   252,   242,   268,   930,   212,   268,   256,   210,   254,
     125,   248,   248,   256,   129,   242,   253,   178,   178,   242,
     256,   165,   165,   252,  1104,   524,  1076,   361,   256,   178,
     165,   530,   665,   165,   134,   135,   242,   165,   153,   268,
     178,  1057,   245,     4,  1060,     6,   622,   741,   561,   248,
     242,   153,   947,   387,   165,  1105,   559,   256,   984,   752,
     986,   987,   988,   601,   571,   578,   400,   401,   402,   153,
     404,   405,   406,   407,   408,   624,   242,   411,   310,   413,
     195,   257,   416,   258,   125,   153,   201,  1013,   129,     4,
     165,     6,   785,   195,   165,   154,   125,   193,   242,   242,
     129,   197,    65,    66,    67,    68,    69,   242,    89,    90,
     242,   195,   153,   258,   242,   218,   450,   592,   452,   453,
     454,   455,   456,   457,   153,   459,   185,   195,   165,   463,
     464,   242,   466,   192,   236,   165,   239,   178,   472,   165,
     517,   165,   519,   520,   256,   522,   378,   379,   218,   178,
     209,   528,   236,   260,   195,   532,  1088,   256,   107,   165,
     201,     4,   947,     6,   223,   624,   195,   242,   236,   239,
     178,   242,   201,   232,    83,    84,    85,    86,    87,    88,
     129,   258,   222,   242,   243,    72,    73,   165,   821,   138,
     823,   148,   825,    80,    81,    82,   127,   165,   165,   165,
     165,   165,   536,   154,   153,   242,   241,   165,   242,     4,
     159,     6,   242,   241,   611,   612,   242,   252,   242,   165,
     165,   555,   556,   557,   252,   559,   560,   561,   165,   923,
     564,   162,     3,   164,   185,   260,   242,   571,   572,   471,
     574,   192,   474,   475,   578,   748,   195,   750,   258,   174,
     221,   125,   201,     6,     4,   129,     6,     6,   209,   491,
     231,   493,   494,   842,   242,   844,   498,   601,   500,   501,
     964,   234,   223,   505,   242,   242,   242,   242,   242,   153,
       4,   232,     6,   109,   242,   210,     3,     4,   622,     6,
     624,   262,   243,   525,   219,     3,   242,   242,    15,   186,
      17,   210,   534,    20,   178,   242,   115,   116,   117,  1072,
     219,   543,   544,   545,   546,   242,   254,   242,   154,   189,
       4,   195,     6,   248,   249,     4,   178,   201,   253,   242,
     174,    48,    49,   220,   160,   567,   256,    54,    55,   248,
     166,    50,   256,   575,   253,   256,   241,  1041,   235,   185,
     875,   241,   174,   179,   189,   174,   192,   252,   184,    75,
     169,   256,    79,   793,   794,   795,   210,   193,   178,   242,
     196,   241,   178,   209,   200,   219,   189,   190,   191,     4,
     206,     6,   252,   174,   178,   178,   256,   223,   210,   723,
     724,   210,     4,  1087,     6,   178,   232,   219,   242,   261,
     219,   735,   174,   256,   248,   249,   241,   243,   241,   253,
     236,   745,   746,     4,   748,     6,   750,   252,   244,   210,
     137,   256,     4,   242,     6,   256,   248,   249,   219,   248,
     249,   253,   178,   174,   253,   455,   456,   457,   210,     4,
     672,     6,   776,   174,   125,   178,   178,   219,   129,   681,
     167,   683,   684,   685,   788,   178,   790,   248,   249,   176,
     178,   178,   253,   193,   181,   182,   256,     6,   178,   210,
     973,   805,   153,   178,   706,   809,   248,   249,   219,   210,
     178,   253,   199,   178,   178,   202,   178,   178,   219,  1001,
    1002,   178,   209,   210,     3,   776,   178,    78,   178,   216,
     217,   733,    16,    17,    18,    19,   178,   248,   249,   178,
     227,   242,   253,   230,   195,   232,   233,   248,   249,   236,
     201,   238,   253,   240,   178,   178,   243,    41,    95,   246,
     247,   248,   259,   867,   251,   237,   253,   871,   260,   256,
     241,   256,   876,   210,   879,   879,   242,   222,   187,   266,
     267,   268,   219,   242,   504,   178,   506,   507,   178,   140,
     510,   260,   143,   144,   145,   242,   130,   178,   178,  1081,
    1082,   152,   178,   178,   806,   156,   808,   178,   178,   178,
     161,   248,   249,   474,   475,   178,   253,   168,   820,   170,
     171,   178,   173,     3,    21,   103,   828,   193,   260,   260,
     178,   178,   493,     3,     4,   256,     6,   498,   242,   500,
     501,   165,   187,   194,   505,    15,   256,    17,   256,   165,
      20,   242,   165,   204,     3,     3,   960,   208,  1000,   260,
       3,     3,     3,     3,   215,     3,   217,     3,   870,   973,
     256,     3,     3,   875,     4,   226,   165,   228,    48,    49,
     242,   189,   256,   256,    54,    55,     3,     4,   242,     6,
       3,     3,  1034,   180,   180,   999,  1000,   180,    15,   138,
      17,   519,   520,    20,   522,   178,   256,   178,   165,    79,
     528,   165,     3,   242,   532,   266,   165,   165,   269,   165,
     165,   165,   178,  1027,  1028,  1029,  1030,  1069,   179,     3,
    1034,    48,    49,   184,  1076,   178,   165,    54,    55,   260,
     165,   165,   193,   165,   165,   196,  1050,   949,   165,   200,
     222,     3,   237,   165,     3,   206,   165,  1061,     3,   165,
     178,  1065,    79,  1105,     3,  1069,  1070,   137,     3,   174,
     189,   213,  1076,  1077,   189,   165,   165,   165,   260,  1083,
     260,   165,   165,   260,   260,   260,   165,   183,   256,   242,
     193,   255,   150,   258,   996,   258,   130,   167,   387,   574,
     636,  1105,   242,   644,   915,   912,   176,   796,   178,  1096,
     196,   181,   182,   790,   272,   996,   416,   255,   723,    51,
     137,    51,   141,   193,   218,   560,   973,   783,  1007,   199,
     747,   513,   202,  1028,  1004,   330,   695,   514,   548,   209,
     210,   703,   700,   769,   603,  1034,   216,   217,  1030,   210,
     167,   287,  1105,  1069,   906,  1113,   555,   227,   362,   176,
     230,   178,   232,   233,   181,   182,   236,   733,   238,  1077,
     240,   496,   701,   243,   847,   395,   246,   247,   248,   947,
     250,   251,   199,   253,   156,   202,   256,    14,   402,    -1,
      -1,    -1,   209,   210,    -1,    -1,   266,   267,   268,   216,
     217,    -1,  1104,    -1,    -1,    -1,    -1,    -1,     3,     4,
     227,     6,    -1,   230,    -1,   232,   233,    -1,    -1,   236,
      15,   238,    17,   240,    -1,    20,   243,    -1,    -1,   246,
     247,   248,    -1,   250,   251,    -1,   253,    -1,    -1,   256,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   266,
     267,   268,    -1,    48,    49,    -1,    -1,    -1,    -1,    54,
      55,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    79,    -1,    -1,    -1,    -1,    -1,
       3,     4,    -1,     6,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    15,    -1,    17,    -1,    -1,    20,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    48,    49,    -1,    -1,    -1,
      -1,    54,    55,     3,     4,    -1,     6,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    15,    -1,    17,    -1,    -1,
      20,    -1,    -1,    -1,    -1,    -1,    79,    -1,    -1,    -1,
      -1,    -1,   167,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   176,    -1,   178,    -1,    -1,    -1,   182,    48,    49,
      -1,    -1,    -1,    -1,    54,    55,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   198,   199,    -1,    -1,   202,    -1,    -1,
      -1,    -1,    -1,    -1,   209,   210,    -1,    -1,    -1,    79,
      -1,   216,   217,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
       3,     4,   227,     6,    -1,   230,    -1,   232,   233,    -1,
      -1,   236,    15,   238,    17,   240,    -1,    20,   243,    -1,
      -1,   246,   247,   248,   167,    -1,   251,    -1,   253,    -1,
      -1,   256,    -1,   176,    -1,   178,    -1,    -1,    -1,   182,
      -1,   266,   267,   268,    -1,    48,    49,    -1,    -1,    -1,
     193,    54,    55,    -1,    -1,    -1,   199,    -1,    -1,   202,
      -1,    -1,    -1,    -1,    -1,    -1,   209,   210,    -1,    -1,
      -1,    -1,    -1,   216,   217,   165,    79,   167,    -1,    -1,
      -1,    -1,    -1,    -1,   227,    -1,   176,   230,   178,   232,
     233,    -1,   182,   236,    -1,   238,    -1,   240,    -1,    -1,
     243,    -1,    -1,   246,   247,   248,    -1,    -1,   251,   199,
     253,    -1,   202,   256,    -1,    -1,    -1,    -1,    -1,   209,
     210,    -1,    -1,   266,   267,   268,   216,   217,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,     3,     4,   227,     6,    -1,
     230,    -1,   232,   233,    -1,    -1,   236,    15,   238,    17,
     240,    -1,    20,   243,    -1,    -1,   246,   247,   248,    -1,
      -1,   251,    -1,   253,   167,    -1,   256,    -1,    -1,    -1,
      -1,    -1,    -1,   176,    -1,   178,   266,   267,   268,   182,
      48,    49,    -1,    -1,    -1,    -1,    54,    55,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   198,   199,    -1,    -1,   202,
      -1,    -1,    -1,    -1,    -1,    -1,   209,   210,    -1,    -1,
      -1,    79,    -1,   216,   217,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,     3,     4,   227,     6,    -1,   230,    -1,   232,
     233,    -1,    -1,   236,    15,   238,    17,   240,    -1,    20,
     243,    -1,    -1,   246,   247,   248,    -1,    -1,   251,    -1,
     253,    -1,    -1,   256,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   266,   267,   268,    -1,    48,    49,    -1,
      -1,    -1,    -1,    54,    55,     3,     4,    -1,     6,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    15,    -1,    17,
      -1,    -1,    20,    -1,    -1,    -1,    -1,    -1,    79,   167,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   176,    -1,
     178,    -1,    -1,    -1,   182,    -1,    -1,    -1,    -1,    -1,
      48,    49,    -1,    -1,    -1,    -1,    54,    55,    -1,    -1,
     198,   199,    -1,    -1,   202,    -1,    -1,    -1,    -1,    -1,
      -1,   209,   210,    -1,    -1,    -1,    -1,    -1,   216,   217,
      -1,    79,    -1,    -1,    -1,    -1,    -1,     3,     4,   227,
       6,    -1,   230,    -1,   232,   233,    -1,    -1,   236,    15,
     238,    17,   240,    -1,    20,   243,    -1,    -1,   246,   247,
     248,    -1,    -1,   251,    -1,   253,   167,    -1,   256,    -1,
      -1,    -1,    -1,    -1,    -1,   176,    -1,   178,   266,   267,
     268,   182,    48,    49,    -1,    -1,    -1,    -1,    54,    55,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   199,    -1,
      -1,   202,    -1,    -1,    -1,    -1,    -1,    -1,   209,   210,
      -1,    -1,    -1,    79,    -1,   216,   217,    -1,    -1,   167,
      -1,    -1,    -1,    -1,    -1,    -1,   227,    -1,   176,   230,
     178,   232,   233,    -1,   182,   236,    -1,   238,    -1,   240,
      -1,    -1,   243,    -1,    -1,   246,   247,   248,    -1,    -1,
     251,   199,   253,    -1,   202,   256,    -1,    -1,    -1,    -1,
      -1,   209,   210,    -1,    -1,   266,   267,   268,   216,   217,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   227,
      -1,    -1,   230,    -1,   232,   233,    -1,    -1,   236,    -1,
     238,    -1,   240,    -1,    -1,   243,    -1,    -1,   246,   247,
     248,   167,    -1,   251,    -1,   253,    -1,    -1,   256,    -1,
     176,    -1,   178,    -1,    -1,    -1,   182,    -1,   266,   267,
     268,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   199,    -1,    -1,   202,    -1,    -1,    -1,
      -1,    -1,    -1,   209,   210,    -1,    -1,    -1,    -1,    -1,
     216,   217,     0,     1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   227,    -1,    -1,   230,    -1,   232,   233,    16,    -1,
     236,    -1,   238,    -1,   240,    -1,    -1,   243,    -1,    -1,
     246,   247,    -1,    -1,    -1,   251,    -1,    -1,    -1,    -1,
     256,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    46,    47,
     266,   267,   268,    51,    -1,    53,    -1,    -1,    56,    57,
      58,    59,    60,    -1,    62,    63,    -1,    -1,    -1,    -1,
      -1,    -1,    70,    71,    -1,    -1,    74,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    91,    92,    93,    94,    -1,    96,    97,
      98,    99,   100,   101,   102,    -1,    -1,   105,    -1,    -1,
     108,    -1,   110,   111,    -1,   113,   114,    -1,    -1,    -1,
     118,   119,   120,   121,   122,   123,   127,   128,   126,    -1,
      -1,    -1,    -1,    -1,   132,   133,    -1,    -1,   136,    -1,
      -1,   139,    -1,   141,   142,    -1,    -1,    -1,   149,   147,
      -1,    -1,    -1,   151,    -1,    -1,   157,   158,    -1,    -1,
      -1,   162,   163,   164,    -1,    -1,    -1,   128,    -1,    -1,
      -1,   172,    -1,    -1,   175,    -1,   177,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   187,   188,   149,    -1,
      -1,    -1,    -1,   191,    -1,   193,   157,   158,   196,    -1,
      -1,    -1,   163,    -1,   165,    -1,   207,   205,    -1,    -1,
      -1,   172,    -1,    -1,   175,    -1,   177,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   225,    -1,   187,   188,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   207,    -1,    -1,   250,
      -1,    -1,    -1,    -1,    -1,    -1,   257,    -1,    -1,    -1,
      -1,    -1,   263,   264,   225,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   237,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   250,
      -1,    -1,    -1,    -1,    -1,    -1,   257,    -1,   259,    -1,
      -1,    -1,   263,   264
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
{
       0,     1,    46,    47,    51,    53,    56,    57,    58,    59,
      60,    62,    63,    70,    71,    74,    91,    92,    93,    94,
      96,    97,    98,    99,   100,   101,   102,   105,   108,   110,
     111,   113,   114,   118,   119,   120,   121,   122,   123,   126,
     132,   133,   136,   139,   141,   142,   147,   151,   191,   193,
     196,   205,   279,   290,   291,   292,   293,   302,   309,   329,
     330,   339,   340,   341,   343,   344,   345,   346,   347,   357,
     377,   381,   427,   428,   431,   432,   450,   484,   485,   486,
     487,   489,   493,   495,     4,   478,     6,   475,   476,   478,
     478,   478,   475,   475,   478,     6,   477,   478,   478,   483,
     488,   488,   475,   477,   477,   477,   477,     6,   378,   379,
     416,   478,   478,   475,     3,   503,   475,   475,   475,   475,
     475,   475,   331,   477,   475,     6,   473,   474,   478,   429,
     478,   475,     4,     6,   481,   109,   160,   166,   179,   184,
     193,   196,   200,   206,   236,   244,   348,   350,   351,   352,
     203,   459,   475,   348,   350,     0,    16,   134,   135,   490,
      52,   256,   241,   252,   256,   257,    72,    73,    80,    81,
      82,   186,   220,   235,   310,   311,   312,   315,   318,   321,
     322,   323,   326,   256,    89,    90,   241,   252,   258,   258,
     258,   258,   380,   381,   178,   245,   178,   178,   358,   106,
     214,   281,   475,   112,   131,   433,   256,   256,   241,   252,
     260,   148,   342,   178,   353,   353,   222,   258,   242,     3,
     153,   195,   236,   460,    65,    66,    67,    68,    69,   234,
     282,   260,   258,   486,     6,   478,   491,   492,     6,   478,
       6,   478,   478,   478,     6,   125,   129,   153,   178,   195,
     201,   361,   362,   367,   369,   178,   327,   328,   478,     3,
     178,   308,   320,   369,   371,   478,   178,   317,   478,   178,
     308,   313,   242,   478,     6,   478,   478,   301,   475,   301,
     301,   301,   381,   307,   308,   475,   307,   252,   359,   418,
     421,   473,   478,   254,     4,   479,     3,     4,     6,    15,
      17,    20,    48,    49,    54,    55,    79,   137,   167,   176,
     178,   181,   182,   199,   202,   209,   210,   216,   217,   227,
     230,   232,   233,   236,   238,   240,   243,   246,   247,   248,
     250,   251,   253,   256,   266,   267,   268,   391,   392,   393,
     394,   395,   402,   404,   423,   434,   435,   436,   437,   438,
     458,   463,   464,   470,   478,   480,   494,   496,   500,   501,
     502,   178,   334,   478,   430,   478,     6,   478,   478,   429,
     354,   418,   190,   355,   356,   416,   475,   352,   451,   178,
     198,   288,   289,   463,   288,   288,   288,   252,   284,   285,
     287,   478,   283,   284,   286,   106,   214,   280,   355,   475,
     256,   256,   242,    50,   256,   241,   178,   178,   178,   324,
     369,   178,   178,    75,   325,   327,   242,   319,   320,    78,
     140,   143,   144,   145,   152,   156,   161,   168,   170,   171,
     173,   194,   204,   208,   215,   217,   226,   228,   266,   269,
     407,   408,   409,   410,   412,   449,   316,   317,   313,   314,
     261,   311,   256,   241,   178,   178,   178,   178,   165,   242,
     165,   421,   165,   242,   256,   189,   256,   417,   193,   448,
     457,   178,   256,     6,   178,   178,   178,   458,   154,   185,
     192,   209,   223,   232,   243,   424,   425,   193,   391,   463,
     458,   178,   178,   178,   221,   231,   465,   466,   178,   458,
     178,   178,   458,   458,   178,   178,   178,   178,   501,   394,
     178,   501,     3,   259,   237,   425,   425,   128,   149,   157,
     158,   163,   172,   175,   177,   187,   188,   207,   225,   250,
     257,   263,   264,   401,   403,   189,   256,    83,    84,    85,
      86,    87,    88,   210,   219,   248,   253,   469,    95,   335,
     336,   478,   197,   332,   457,   260,   256,   241,   165,   242,
     242,   222,   461,   462,   463,   463,   165,   242,   165,   285,
     165,   242,   256,   417,   242,   187,   479,   391,   260,   478,
     478,   492,   478,     6,   478,   364,   366,   418,   368,   418,
     368,   165,   242,   325,   368,   391,   447,   478,   165,   328,
     165,   242,   178,   178,   178,   425,   425,   178,   178,   178,
     178,   178,   178,   178,   178,   115,   116,   117,   169,   370,
     372,   165,   242,   165,   242,   478,   478,     6,   478,   305,
     306,   478,   305,   305,   305,   130,   303,   308,    64,    81,
      82,   124,   257,   294,   295,   296,   418,   210,   478,     3,
     478,   459,   103,   360,   165,   463,   467,   478,    21,   467,
     467,   260,   459,   165,   165,   167,   463,   468,   494,   153,
     195,   236,   405,   467,   463,   391,   262,   466,   467,   467,
     467,   405,   467,   405,   405,   405,   392,   393,   260,   178,
     260,   399,   501,   399,   399,   399,   178,   458,   198,   463,
     399,   178,   458,   399,   127,   162,   164,   463,     3,   178,
     248,   253,   497,   499,   210,   268,   478,   463,   463,   463,
     463,   407,   165,   242,   256,   333,   430,   478,     6,   478,
     418,   356,   355,   242,   452,   254,   478,   289,   187,   284,
     210,   478,   286,   289,   355,   256,   256,   165,   242,   165,
     242,   165,   369,   165,   165,   320,     3,   413,   413,     3,
     260,   178,   260,     3,   414,     3,     3,     3,   414,   414,
       3,     3,     6,   423,   107,   129,   138,   153,   159,   195,
     201,   363,   373,   374,   375,   376,   317,   313,   256,   165,
     242,   218,   239,   165,   165,   165,   294,     3,     3,     4,
     297,   296,   417,   174,   242,   256,   460,   165,   242,   256,
     165,   165,   154,   185,   192,   209,   223,   232,   243,   426,
     460,   242,   425,   242,   165,   242,   463,   165,   229,   165,
     165,   165,   463,   165,   463,   463,   463,   426,     3,   426,
     180,   396,   180,   398,   180,   397,   396,   248,   423,   471,
     472,   494,   398,   471,   397,   463,   497,   174,   210,   219,
     242,   248,   249,   253,   498,     3,   189,   256,   336,   478,
     178,   256,   462,   482,   478,   178,   256,   417,   104,   254,
     349,   478,   478,   363,   418,   418,   325,   165,   165,   165,
     242,   426,     3,   426,   242,   411,   165,   165,   242,   165,
     165,   411,   165,   165,   365,   475,   178,   375,   325,   478,
      44,    45,   257,   265,   298,   299,   300,   306,   298,   298,
     298,   303,     3,   478,   461,   463,   478,   178,   461,   425,
     260,   425,   425,   165,   463,   165,   165,   165,   165,   165,
     400,   423,   400,   400,     3,   480,   165,   242,   165,   237,
     165,   497,   497,   497,   478,   198,   337,   338,   463,   478,
     222,   384,   388,   288,   478,   416,     3,   165,     3,   415,
     165,     3,   165,   178,   447,   297,     3,   300,   174,   417,
     388,   189,     3,   388,   260,   426,   260,   260,   260,   472,
     463,   174,   174,   242,   189,   165,   242,   385,   387,   475,
     155,   183,   214,   382,   383,   389,   390,   444,   213,   454,
     165,   417,   165,   260,   165,   366,   165,   497,   165,   165,
     426,   426,   426,   426,   497,   497,   338,    33,    40,   242,
     254,   422,   478,     3,   252,   268,   419,   420,   445,   446,
     473,   478,   391,   391,   390,   382,   153,   195,   236,   406,
     150,   211,   439,   455,   426,   165,   174,   242,   174,   174,
     242,   178,   385,   386,   386,   212,   387,   422,   420,   242,
     256,   417,   193,   453,   456,   478,   255,   150,   497,   497,
     385,   258,   258,   178,   387,   446,   210,   478,   459,   130,
     304,     3,   419,   440,   441,   442,   456,   174,   174,   165,
     391,   391,   385,   417,   460,   242,   218,   239,   443,   304,
     165,   461,   441,   388,   454
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
#line 452 "sql.yacc"
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
#line 478 "sql.yacc"
    {
		(yyval.ptr)=0;
	}
    break;

  case 4:

/* Line 1455 of yacc.c  */
#line 481 "sql.yacc"
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
#line 498 "sql.yacc"
    {
		(yyval.ptr)=A4GL_new_select_list_item_expr((yyvsp[(2) - (2)].s_select_list_item));
	}
    break;

  case 6:

/* Line 1455 of yacc.c  */
#line 503 "sql.yacc"
    {
		(yyval.ptr)=0;
	}
    break;

  case 7:

/* Line 1455 of yacc.c  */
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
		add_feature("DELETE_WHERE_CURRENT_OF");
		}
	}
    break;

  case 8:

/* Line 1455 of yacc.c  */
#line 523 "sql.yacc"
    {
		 (yyval.ptr)=A4GL_new_select_list_item_expr((yyvsp[(2) - (2)].s_select_list_item));
	}
    break;

  case 9:

/* Line 1455 of yacc.c  */
#line 529 "sql.yacc"
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
#line 538 "sql.yacc"
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

  case 12:

/* Line 1455 of yacc.c  */
#line 556 "sql.yacc"
    {
		(yyval.update_cmd)=(yyvsp[(2) - (2)].update_cmd);
		add_feature("UPDATE_COLUMN_EQ_VALUE_LIST");
    }
    break;

  case 13:

/* Line 1455 of yacc.c  */
#line 563 "sql.yacc"
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
		//$<update_cmd>$->value_list=make_select_list_item_list_from_variable_record(buff); 
		(yyval.update_cmd)->where_clause=0;
#endif
	}
    break;

  case 15:

/* Line 1455 of yacc.c  */
#line 633 "sql.yacc"
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
#line 640 "sql.yacc"
    {
		(yyval.update_cmd)=(yyvsp[(1) - (3)].update_cmd);
		add_str_list((yyval.update_cmd)->column_list, (yyvsp[(3) - (3)].upd_pair)->column_name);
		local_add_select_list_item_list((yyval.update_cmd)->value_list, (yyvsp[(3) - (3)].upd_pair)->value);
	}
    break;

  case 17:

/* Line 1455 of yacc.c  */
#line 651 "sql.yacc"
    {
                strcpy((yyval.str),(yyvsp[(1) - (1)].str));
        }
    break;

  case 18:

/* Line 1455 of yacc.c  */
#line 654 "sql.yacc"
    {
                strcpy((yyval.str),(yyvsp[(2) - (2)].str));
        }
    break;

  case 19:

/* Line 1455 of yacc.c  */
#line 659 "sql.yacc"
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
#line 666 "sql.yacc"
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
#line 683 "sql.yacc"
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
#line 700 "sql.yacc"
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
#line 721 "sql.yacc"
    {
		(yyval.upd_pair)=malloc(sizeof(struct s_update_pair));
		(yyval.upd_pair)->column_name=acl_strdup((yyvsp[(1) - (3)].str));
		(yyval.upd_pair)->value=(yyvsp[(3) - (3)].s_select_list_item);
	}
    break;

  case 24:

/* Line 1455 of yacc.c  */
#line 730 "sql.yacc"
    {
			(yyval.str_list)=new_str_list((yyvsp[(1) - (1)].str));
		}
    break;

  case 25:

/* Line 1455 of yacc.c  */
#line 733 "sql.yacc"
    {
			(yyval.str_list)=add_str_list((yyvsp[(1) - (3)].str_list), (yyvsp[(3) - (3)].str));
		}
    break;

  case 26:

/* Line 1455 of yacc.c  */
#line 741 "sql.yacc"
    { 
		(yyval.s_select_list_item_list)=local_new_select_list_item_list((yyvsp[(1) - (1)].s_select_list_item));
	}
    break;

  case 27:

/* Line 1455 of yacc.c  */
#line 744 "sql.yacc"
    { 
		(yyval.s_select_list_item_list)=local_add_select_list_item_list((yyvsp[(1) - (3)].s_select_list_item_list),(yyvsp[(3) - (3)].s_select_list_item));
	}
    break;

  case 28:

/* Line 1455 of yacc.c  */
#line 752 "sql.yacc"
    {(yyval.s_select_list_item)=(yyvsp[(1) - (1)].s_select_list_item);}
    break;

  case 29:

/* Line 1455 of yacc.c  */
#line 753 "sql.yacc"
    {(yyval.s_select_list_item)=new_select_list_item_builtin_const(E_SLI_BUILTIN_CONST_NULL); }
    break;

  case 30:

/* Line 1455 of yacc.c  */
#line 760 "sql.yacc"
    { (yyval.sql_string)=make_sql_string_and_free(acl_strdup((yyvsp[(1) - (1)].str)), NULL);}
    break;

  case 31:

/* Line 1455 of yacc.c  */
#line 763 "sql.yacc"
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
#line 771 "sql.yacc"
    {SPRINTF2((yyval.str),"%s %s ",(yyvsp[(1) - (2)].str),(yyvsp[(2) - (2)].str));
			add_feature("DROP_VIEW");
}
    break;

  case 33:

/* Line 1455 of yacc.c  */
#line 774 "sql.yacc"
    {SPRINTF2((yyval.str),"%s %s",(yyvsp[(1) - (2)].str),(yyvsp[(2) - (2)].str));
		if (strchr((yyvsp[(2) - (2)].str),'@') || strchr((yyvsp[(2) - (2)].str),':')) add_feature("DROP_INDEX_QUALIFIED_PATH");
			add_feature("DROP_INDEX");
}
    break;

  case 34:

/* Line 1455 of yacc.c  */
#line 778 "sql.yacc"
    {SPRINTF2((yyval.str),"%s %s",(yyvsp[(1) - (2)].str),(yyvsp[(2) - (2)].str));
			add_feature("DROP_TRIGGER");
}
    break;

  case 35:

/* Line 1455 of yacc.c  */
#line 784 "sql.yacc"
    {(yyval.sql_string)=acl_strdup((yyvsp[(1) - (1)].str));}
    break;

  case 36:

/* Line 1455 of yacc.c  */
#line 785 "sql.yacc"
    {(yyval.sql_string)=(yyvsp[(1) - (1)].sql_string);}
    break;

  case 37:

/* Line 1455 of yacc.c  */
#line 789 "sql.yacc"
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
#line 799 "sql.yacc"
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
#line 813 "sql.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 40:

/* Line 1455 of yacc.c  */
#line 814 "sql.yacc"
    {strcpy((yyval.str),(yyvsp[(1) - (1)].str));}
    break;

  case 42:

/* Line 1455 of yacc.c  */
#line 819 "sql.yacc"
    {SPRINTF2((yyval.str),"%s%s",(yyvsp[(1) - (2)].str),(yyvsp[(2) - (2)].str)); }
    break;

  case 43:

/* Line 1455 of yacc.c  */
#line 824 "sql.yacc"
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
#line 832 "sql.yacc"
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
#line 840 "sql.yacc"
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
#line 848 "sql.yacc"
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
#line 856 "sql.yacc"
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
#line 868 "sql.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 50:

/* Line 1455 of yacc.c  */
#line 868 "sql.yacc"
    {strcpy((yyval.str),(yyvsp[(1) - (1)].str));}
    break;

  case 52:

/* Line 1455 of yacc.c  */
#line 872 "sql.yacc"
    {SPRINTF2((yyval.str),"%s%s",(yyvsp[(1) - (2)].str),(yyvsp[(2) - (2)].str));}
    break;

  case 53:

/* Line 1455 of yacc.c  */
#line 876 "sql.yacc"
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
#line 883 "sql.yacc"
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
#line 890 "sql.yacc"
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
#line 897 "sql.yacc"
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
#line 906 "sql.yacc"
    { strcpy(last_tmp_name,(yyvsp[(1) - (1)].str)); }
    break;

  case 58:

/* Line 1455 of yacc.c  */
#line 910 "sql.yacc"
    {SPRINTF7((yyval.str),"CREATE UNIQUE INDEX %s %s %s %s %s %s %s",(yyvsp[(2) - (8)].str),(yyvsp[(3) - (8)].str),(yyvsp[(4) - (8)].str),(yyvsp[(5) - (8)].str),(yyvsp[(6) - (8)].str),(yyvsp[(7) - (8)].str),(yyvsp[(8) - (8)].str));
		add_feature("CREATE_INDEX");
		add_feature("CREATE_INDEX_UNIQUE");
		if (strchr((yyvsp[(2) - (8)].str),'@') || strchr((yyvsp[(2) - (8)].str),':')) add_feature("CREATE_INDEX_QUALIFIED_PATH");
		if (strchr((yyvsp[(6) - (8)].str),',')) { add_feature("CREATE_INDEX_COMPOSITE"); }
	
}
    break;

  case 59:

/* Line 1455 of yacc.c  */
#line 917 "sql.yacc"
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
#line 929 "sql.yacc"
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
#line 940 "sql.yacc"
    {
		if (strchr((yyvsp[(2) - (8)].str),'@') || strchr((yyvsp[(2) - (8)].str),':')) add_feature("CREATE_INDEX_QUALIFIED_PATH");
		if (strchr((yyvsp[(6) - (8)].str),',')) { add_feature("CREATE_INDEX_COMPOSITE"); }
			add_feature("CREATE_INDEX");
			SPRINTF7((yyval.str)," CREATE INDEX %s %s %s %s %s %s %s",(yyvsp[(2) - (8)].str),(yyvsp[(3) - (8)].str),(yyvsp[(4) - (8)].str),(yyvsp[(5) - (8)].str),(yyvsp[(6) - (8)].str),(yyvsp[(7) - (8)].str),(yyvsp[(8) - (8)].str));
	}
    break;

  case 62:

/* Line 1455 of yacc.c  */
#line 946 "sql.yacc"
    {
		add_feature("CREATE_DATABASE");
		a4gl_yyerror("You cannot create a database from within Aubit4gl - if the target database allows - prepare and execute it manually");
	}
    break;

  case 63:

/* Line 1455 of yacc.c  */
#line 950 "sql.yacc"
    {
		add_feature("DROP_DATABASE");
		a4gl_yyerror("You cannot drop a database from within Aubit4gl - if the target database allows - prepare and execute it manually");
	}
    break;

  case 64:

/* Line 1455 of yacc.c  */
#line 954 "sql.yacc"
    { 
		if (strchr((yyvsp[(2) - (4)].str),'@') || strchr((yyvsp[(2) - (4)].str),':')) add_feature("CREATE_SYNONYM_QUALIFIED_PATH");
			add_feature("CREATE_SYNONYM");
			SPRINTF3((yyval.str),"%s %s FOR %s",(yyvsp[(1) - (4)].str),(yyvsp[(2) - (4)].str),(yyvsp[(4) - (4)].str)); 
	}
    break;

  case 65:

/* Line 1455 of yacc.c  */
#line 959 "sql.yacc"
    { 
		add_feature("CREATE_AUDIT");
		SPRINTF2((yyval.str),"CREATE AUDIT FOR %s IN '%s'",(yyvsp[(2) - (4)].str),A4GL_strip_quotes((yyvsp[(4) - (4)].str))); 
	}
    break;

  case 66:

/* Line 1455 of yacc.c  */
#line 963 "sql.yacc"
    { 
		add_feature("DROP_AUDIT");
		SPRINTF1((yyval.str),"DROP AUDIT FOR %s",(yyvsp[(2) - (2)].str)); }
    break;

  case 67:

/* Line 1455 of yacc.c  */
#line 966 "sql.yacc"
    { 
		if (strchr((yyvsp[(2) - (2)].str),'@') || strchr((yyvsp[(2) - (2)].str),':')) add_feature("DROP_SYNONYM_QUALIFIED_PATH");
		add_feature("DROP_SYNONYM");
		SPRINTF2((yyval.str),"%s %s",(yyvsp[(1) - (2)].str),(yyvsp[(2) - (2)].str)); }
    break;

  case 68:

/* Line 1455 of yacc.c  */
#line 970 "sql.yacc"
    { 
		add_feature("RECOVER_TABLE");
		SPRINTF1((yyval.str),"RECOVER TABLE %s",(yyvsp[(2) - (2)].str)); }
    break;

  case 69:

/* Line 1455 of yacc.c  */
#line 973 "sql.yacc"
    { 
		add_feature("ROLLFORWARD_DATABASE");
		SPRINTF1((yyval.str),"ROLLFORWARD DATABASE %s",(yyvsp[(2) - (2)].str)); }
    break;

  case 70:

/* Line 1455 of yacc.c  */
#line 980 "sql.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 71:

/* Line 1455 of yacc.c  */
#line 981 "sql.yacc"
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
#line 991 "sql.yacc"
    {(yyval.integer_val)=0;}
    break;

  case 73:

/* Line 1455 of yacc.c  */
#line 992 "sql.yacc"
    { (yyval.integer_val)=1;}
    break;

  case 75:

/* Line 1455 of yacc.c  */
#line 997 "sql.yacc"
    {SPRINTF2((yyval.str),"%s,%s",(yyvsp[(1) - (3)].str),(yyvsp[(3) - (3)].str));}
    break;

  case 76:

/* Line 1455 of yacc.c  */
#line 1001 "sql.yacc"
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
#line 1010 "sql.yacc"
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
#line 1019 "sql.yacc"
    {
		strcpy((yyval.str),A4GL_confirm_colname(last_tmp_name,(yyvsp[(1) - (1)].str)));
}
    break;

  case 79:

/* Line 1455 of yacc.c  */
#line 1026 "sql.yacc"
    {
		(yyval.sql_string)=(yyvsp[(1) - (1)].sql_string);
	}
    break;

  case 80:

/* Line 1455 of yacc.c  */
#line 1029 "sql.yacc"
    {
		(yyval.sql_string)=make_sql_string_and_free((yyvsp[(1) - (3)].sql_string),kw_comma,strdup("\n"),(yyvsp[(3) - (3)].sql_string),NULL);
	}
    break;

  case 81:

/* Line 1455 of yacc.c  */
#line 1035 "sql.yacc"
    {
		(yyval.sql_string)=make_sql_string_and_free(strdup("   "),(yyvsp[(1) - (1)].sql_string),NULL);
	}
    break;

  case 82:

/* Line 1455 of yacc.c  */
#line 1038 "sql.yacc"
    {
		(yyval.sql_string)=make_sql_string_and_free(strdup("   "),(yyvsp[(1) - (1)].sql_string),NULL);
	}
    break;

  case 83:

/* Line 1455 of yacc.c  */
#line 1049 "sql.yacc"
    {
		add_feature("ALTER_TABLE");
	(yyval.sql_string)=make_sql_string_and_free(acl_strdup((yyvsp[(1) - (3)].str)),kw_space,acl_strdup((yyvsp[(2) - (3)].str)),kw_space,(yyvsp[(3) - (3)].sql_string),NULL);
	}
    break;

  case 84:

/* Line 1455 of yacc.c  */
#line 1053 "sql.yacc"
    {
		add_feature("CLUSTER_INDEX");
		add_feature("ALTER_INDEX_CLUSTER");
		(yyval.sql_string)=make_sql_string_and_free(acl_strdup("ALTER INDEX "),acl_strdup((yyvsp[(2) - (3)].str)),acl_strdup(" TO CLUSTER"),NULL);
		}
    break;

  case 85:

/* Line 1455 of yacc.c  */
#line 1058 "sql.yacc"
    {
		add_feature("ALTER_INDEX_NOT_CLUSTER");
		(yyval.sql_string)=make_sql_string_and_free(acl_strdup("ALTER INDEX "),acl_strdup((yyvsp[(2) - (3)].str)),acl_strdup(" TO NOT CLUSTER"),NULL);
		}
    break;

  case 86:

/* Line 1455 of yacc.c  */
#line 1065 "sql.yacc"
    {
		(yyval.sql_string)=(yyvsp[(1) - (1)].sql_string);
	}
    break;

  case 87:

/* Line 1455 of yacc.c  */
#line 1068 "sql.yacc"
    {
		(yyval.sql_string)=make_sql_string_and_free((yyvsp[(1) - (3)].sql_string),kw_comma,(yyvsp[(3) - (3)].sql_string),NULL);
	}
    break;

  case 88:

/* Line 1455 of yacc.c  */
#line 1077 "sql.yacc"
    {
		(yyval.sql_string)=(yyvsp[(1) - (1)].sql_string);
	}
    break;

  case 89:

/* Line 1455 of yacc.c  */
#line 1080 "sql.yacc"
    {
	add_feature("ALTER_TABLE_DROP");
		(yyval.sql_string)=acl_strdup((yyvsp[(1) - (1)].str));
	}
    break;

  case 90:

/* Line 1455 of yacc.c  */
#line 1084 "sql.yacc"
    {
	add_feature("ALTER_TABLE_MODIFY");
		(yyval.sql_string)=(yyvsp[(1) - (1)].sql_string);
	}
    break;

  case 91:

/* Line 1455 of yacc.c  */
#line 1088 "sql.yacc"
    {
		add_feature("ALTER_TABLE_ADD_CONSTRAINT");
		(yyval.sql_string)=acl_strdup((yyvsp[(1) - (1)].str));
	}
    break;

  case 92:

/* Line 1455 of yacc.c  */
#line 1092 "sql.yacc"
    {
		add_feature("ALTER_TABLE_DROP_CONSTRAINT");
		(yyval.sql_string)=acl_strdup((yyvsp[(1) - (1)].str));
	}
    break;

  case 93:

/* Line 1455 of yacc.c  */
#line 1096 "sql.yacc"
    {
		add_feature("ALTER_TABLE_MODIFY_NEXT");
		(yyval.sql_string)=acl_strdup((yyvsp[(1) - (1)].str));
	}
    break;

  case 94:

/* Line 1455 of yacc.c  */
#line 1100 "sql.yacc"
    {
		add_feature("ALTER_TABLE_LOCK_MODE");
		(yyval.sql_string)=acl_strdup((yyvsp[(1) - (1)].str));
	}
    break;

  case 95:

/* Line 1455 of yacc.c  */
#line 1108 "sql.yacc"
    {
		add_feature("ALTER_TABLE_ADD");
		(yyval.sql_string)=make_sql_string_and_free(acl_strdup("ADD "),(yyvsp[(2) - (2)].sql_string),NULL);
	}
    break;

  case 96:

/* Line 1455 of yacc.c  */
#line 1112 "sql.yacc"
    {
		add_feature("ALTER_TABLE_ADD");
		(yyval.sql_string)=make_sql_string_and_free(acl_strdup("ADD "),kw_ob,(yyvsp[(3) - (4)].sql_string),kw_cb,NULL);
	}
    break;

  case 97:

/* Line 1455 of yacc.c  */
#line 1120 "sql.yacc"
    {
		(yyval.sql_string)=(yyvsp[(1) - (1)].sql_string);
	}
    break;

  case 98:

/* Line 1455 of yacc.c  */
#line 1123 "sql.yacc"
    {
		add_feature("ALTER_TABLE_ADD_BEFORE");
		(yyval.sql_string)=make_sql_string_and_free((yyvsp[(1) - (3)].sql_string),acl_strdup(" BEFORE "),acl_strdup((yyvsp[(3) - (3)].str)),NULL);
	}
    break;

  case 99:

/* Line 1455 of yacc.c  */
#line 1130 "sql.yacc"
    {
		(yyval.sql_string)=(yyvsp[(1) - (1)].sql_string);
	}
    break;

  case 100:

/* Line 1455 of yacc.c  */
#line 1133 "sql.yacc"
    {
		(yyval.sql_string)=make_sql_string_and_free((yyvsp[(1) - (3)].sql_string),kw_comma,(yyvsp[(3) - (3)].sql_string),NULL);
	}
    break;

  case 101:

/* Line 1455 of yacc.c  */
#line 1140 "sql.yacc"
    {
		SPRINTF1((yyval.str),"DROP %s",(yyvsp[(2) - (2)].str));
	}
    break;

  case 102:

/* Line 1455 of yacc.c  */
#line 1143 "sql.yacc"
    {
		SPRINTF1((yyval.str),"DROP (%s)",(yyvsp[(3) - (4)].str));
	}
    break;

  case 104:

/* Line 1455 of yacc.c  */
#line 1151 "sql.yacc"
    {
		SPRINTF2((yyval.str),"%s,%s",(yyvsp[(1) - (3)].str),(yyvsp[(3) - (3)].str));
	}
    break;

  case 106:

/* Line 1455 of yacc.c  */
#line 1160 "sql.yacc"
    {
		(yyval.sql_string)=make_sql_string_and_free(acl_strdup("MODIFY "),(yyvsp[(2) - (2)].sql_string),NULL);
	}
    break;

  case 107:

/* Line 1455 of yacc.c  */
#line 1163 "sql.yacc"
    {
		(yyval.sql_string)=make_sql_string_and_free(acl_strdup("MODIFY "),kw_ob,(yyvsp[(3) - (4)].sql_string),kw_cb,NULL);
	}
    break;

  case 108:

/* Line 1455 of yacc.c  */
#line 1169 "sql.yacc"
    {
		(yyval.sql_string)=(yyvsp[(1) - (1)].sql_string);
	}
    break;

  case 109:

/* Line 1455 of yacc.c  */
#line 1172 "sql.yacc"
    {
		(yyval.sql_string)=make_sql_string_and_free((yyvsp[(1) - (3)].sql_string),kw_comma,(yyvsp[(3) - (3)].sql_string),NULL);
	}
    break;

  case 110:

/* Line 1455 of yacc.c  */
#line 1178 "sql.yacc"
    {
		(yyval.sql_string)=(yyvsp[(1) - (1)].sql_string);
	}
    break;

  case 111:

/* Line 1455 of yacc.c  */
#line 1185 "sql.yacc"
    {strcpy((yyval.str),"LOCK MODE (PAGE)");}
    break;

  case 112:

/* Line 1455 of yacc.c  */
#line 1186 "sql.yacc"
    {strcpy((yyval.str),"LOCK MODE (ROW)");}
    break;

  case 113:

/* Line 1455 of yacc.c  */
#line 1190 "sql.yacc"
    {
		add_feature("DDL_NEXT_SIZE");
		SPRINTF1((yyval.str),"MODIFY NEXT SIZE %d",atoi((yyvsp[(2) - (2)].str)));
	}
    break;

  case 114:

/* Line 1455 of yacc.c  */
#line 1198 "sql.yacc"
    {
		add_feature("DDL_CONSTRAINT");
		SPRINTF2((yyval.str),"ADD CONSTRAINT %s%s",(yyvsp[(2) - (3)].sql_string),(yyvsp[(3) - (3)].str));
	}
    break;

  case 115:

/* Line 1455 of yacc.c  */
#line 1202 "sql.yacc"
    {
		add_feature("ADD_CONSTRAINT");
		SPRINTF1((yyval.str),"ADD CONSTRAINT (%s)",(yyvsp[(3) - (4)].sql_string));
	}
    break;

  case 116:

/* Line 1455 of yacc.c  */
#line 1209 "sql.yacc"
    {
		(yyval.sql_string)=make_sql_string_and_free((yyvsp[(1) - (2)].sql_string),acl_strdup((yyvsp[(2) - (2)].str)),NULL);
}
    break;

  case 117:

/* Line 1455 of yacc.c  */
#line 1211 "sql.yacc"
    {
	(yyval.sql_string)=make_sql_string_and_free((yyvsp[(1) - (4)].sql_string),kw_comma,(yyvsp[(3) - (4)].sql_string),acl_strdup((yyvsp[(4) - (4)].str)), NULL);
}
    break;

  case 118:

/* Line 1455 of yacc.c  */
#line 1216 "sql.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 119:

/* Line 1455 of yacc.c  */
#line 1217 "sql.yacc"
    {SPRINTF2((yyval.str)," %s %s",(yyvsp[(1) - (2)].str),(yyvsp[(2) - (2)].str)); add_feature("DDL_CONSTRAINT");}
    break;

  case 120:

/* Line 1455 of yacc.c  */
#line 1222 "sql.yacc"
    { SPRINTF1((yyval.str),"DROP CONSTRAINT %s",(yyvsp[(2) - (2)].str)); add_feature("DROP_CONSTRAINT"); }
    break;

  case 121:

/* Line 1455 of yacc.c  */
#line 1223 "sql.yacc"
    {add_feature("DROP_CONSTRAINT");
		SPRINTF1((yyval.str),"DROP CONSTRAINT (%s)",(yyvsp[(3) - (4)].str));
	}
    break;

  case 122:

/* Line 1455 of yacc.c  */
#line 1229 "sql.yacc"
    {strcpy((yyval.str),(yyvsp[(1) - (1)].str));}
    break;

  case 123:

/* Line 1455 of yacc.c  */
#line 1230 "sql.yacc"
    {SPRINTF2((yyval.str),"%s,%s",(yyvsp[(1) - (3)].str),(yyvsp[(3) - (3)].str));}
    break;

  case 125:

/* Line 1455 of yacc.c  */
#line 1244 "sql.yacc"
    {  add_feature("ROLLBACK_WORK"); }
    break;

  case 126:

/* Line 1455 of yacc.c  */
#line 1250 "sql.yacc"
    { insql=1;}
    break;

  case 127:

/* Line 1455 of yacc.c  */
#line 1250 "sql.yacc"
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
#line 1259 "sql.yacc"
    {insql=1;}
    break;

  case 129:

/* Line 1455 of yacc.c  */
#line 1259 "sql.yacc"
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
#line 1268 "sql.yacc"
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
#line 1293 "sql.yacc"
    {
			(yyval.str_list)=0;
	}
    break;

  case 132:

/* Line 1455 of yacc.c  */
#line 1296 "sql.yacc"
    {
			(yyval.str_list)=(yyvsp[(2) - (3)].str_list);
			 add_feature("INSERT_COLUMNLIST_EQ_VALUELIST");
	}
    break;

  case 133:

/* Line 1455 of yacc.c  */
#line 1304 "sql.yacc"
    {
                        (yyval.str_list)=new_str_list((yyvsp[(1) - (1)].str));
	}
    break;

  case 134:

/* Line 1455 of yacc.c  */
#line 1307 "sql.yacc"
    {
                        (yyval.str_list)=add_str_list((yyvsp[(1) - (3)].str_list), (yyvsp[(3) - (3)].str));
	}
    break;

  case 135:

/* Line 1455 of yacc.c  */
#line 1314 "sql.yacc"
    {	
			strcpy((yyval.str),(yyvsp[(1) - (1)].str));
	}
    break;

  case 136:

/* Line 1455 of yacc.c  */
#line 1317 "sql.yacc"
    { 
			/* with a table prefix - on an insert ? We'll just silently drop it... */
			strcpy((yyval.str),(yyvsp[(3) - (3)].str));
			A4GL_warn("Dropped table prefix from INSERT column name");
	}
    break;

  case 137:

/* Line 1455 of yacc.c  */
#line 1325 "sql.yacc"
    { (yyval.s_select_list_item_list)=local_new_select_list_item_list((yyvsp[(1) - (1)].s_select_list_item));}
    break;

  case 138:

/* Line 1455 of yacc.c  */
#line 1326 "sql.yacc"
    {
		(yyval.s_select_list_item_list)=local_add_select_list_item_list((yyvsp[(1) - (3)].s_select_list_item_list),(yyvsp[(3) - (3)].s_select_list_item));
	}
    break;

  case 139:

/* Line 1455 of yacc.c  */
#line 1332 "sql.yacc"
    {(yyval.s_select_list_item)=(yyvsp[(1) - (1)].s_select_list_item);}
    break;

  case 140:

/* Line 1455 of yacc.c  */
#line 1333 "sql.yacc"
    {(yyval.s_select_list_item)=new_select_list_item_builtin_const(E_SLI_BUILTIN_CONST_NULL); }
    break;

  case 141:

/* Line 1455 of yacc.c  */
#line 1341 "sql.yacc"
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
#line 1359 "sql.yacc"
    { add_feature("BEGIN_WORK"); }
    break;

  case 143:

/* Line 1455 of yacc.c  */
#line 1363 "sql.yacc"
    { add_feature("COMMIT_WORK"); }
    break;

  case 144:

/* Line 1455 of yacc.c  */
#line 1368 "sql.yacc"
    {(yyval.e_boolean)=EB_FALSE;}
    break;

  case 145:

/* Line 1455 of yacc.c  */
#line 1369 "sql.yacc"
    {
		add_feature("DATABASE_EXCLUSIVE");
		{(yyval.e_boolean)=EB_TRUE;}
	}
    break;

  case 146:

/* Line 1455 of yacc.c  */
#line 1379 "sql.yacc"
    {
	char buff[256];
	(yyval.sql_string)=make_sql_string_and_free(acl_strdup((yyvsp[(1) - (1)].str)),NULL);
	SPRINTF1(buff,"Warning: Informix specific SQL @ line %d\n",yylineno);
	ansi_violation(buff,1);
	}
    break;

  case 147:

/* Line 1455 of yacc.c  */
#line 1388 "sql.yacc"
    {
			add_feature("START_DATABASE_WITH_LOG_MODE_ANSI");
			sprintf((yyval.str),"START DATABASE %s WITH LOG IN %s MODE ANSI", (yyvsp[(2) - (5)].str),(yyvsp[(4) - (5)].str));
	}
    break;

  case 148:

/* Line 1455 of yacc.c  */
#line 1392 "sql.yacc"
    {
			add_feature("START_DATABASE_WITH_LOG");
			sprintf((yyval.str),"START DATABASE %s WITH LOG IN %s", (yyvsp[(2) - (4)].str),(yyvsp[(4) - (4)].str));
	}
    break;

  case 149:

/* Line 1455 of yacc.c  */
#line 1397 "sql.yacc"
    {
			add_feature("SET_CONSTRAINTS_ALL_IMMEDIATE");
			SPRINTF1((yyval.str),"%s",(yyvsp[(1) - (1)].str)); 
	}
    break;

  case 150:

/* Line 1455 of yacc.c  */
#line 1401 "sql.yacc"
    {
		add_feature("SET_BUFFERED_LOG");
			SPRINTF1((yyval.str),"%s",(yyvsp[(1) - (1)].str)); 
	}
    break;

  case 151:

/* Line 1455 of yacc.c  */
#line 1405 "sql.yacc"
    {
		add_feature("SET_LOG");
			SPRINTF1((yyval.str),"%s",(yyvsp[(1) - (1)].str)); 
	}
    break;

  case 152:

/* Line 1455 of yacc.c  */
#line 1409 "sql.yacc"
    {
			SPRINTF2((yyval.str),"%s %s",(yyvsp[(1) - (2)].str),(yyvsp[(2) - (2)].str)); add_feature("UPDATE_STATISTICS_TABLE");
	}
    break;

  case 153:

/* Line 1455 of yacc.c  */
#line 1412 "sql.yacc"
    {
		add_feature("UPDATE_STATISTICS");
			SPRINTF1((yyval.str),"%s",(yyvsp[(1) - (1)].str)); 
	}
    break;

  case 154:

/* Line 1455 of yacc.c  */
#line 1419 "sql.yacc"
    { (yyval.integer_val)=1; }
    break;

  case 155:

/* Line 1455 of yacc.c  */
#line 1420 "sql.yacc"
    { (yyval.integer_val)=-1; }
    break;

  case 156:

/* Line 1455 of yacc.c  */
#line 1421 "sql.yacc"
    { (yyval.integer_val)=0; }
    break;

  case 157:

/* Line 1455 of yacc.c  */
#line 1425 "sql.yacc"
    { (yyval.sql_string)=(yyvsp[(1) - (1)].sql_string); }
    break;

  case 158:

/* Line 1455 of yacc.c  */
#line 1426 "sql.yacc"
    { (yyval.sql_string)=(yyvsp[(1) - (1)].sql_string); }
    break;

  case 159:

/* Line 1455 of yacc.c  */
#line 1427 "sql.yacc"
    { (yyval.sql_string)=(yyvsp[(1) - (1)].sql_string); }
    break;

  case 160:

/* Line 1455 of yacc.c  */
#line 1428 "sql.yacc"
    { (yyval.sql_string)=(yyvsp[(1) - (1)].sql_string); }
    break;

  case 161:

/* Line 1455 of yacc.c  */
#line 1429 "sql.yacc"
    { (yyval.sql_string)=(yyvsp[(1) - (1)].sql_string); }
    break;

  case 162:

/* Line 1455 of yacc.c  */
#line 1430 "sql.yacc"
    { (yyval.sql_string)=(yyvsp[(1) - (1)].sql_string); }
    break;

  case 163:

/* Line 1455 of yacc.c  */
#line 1431 "sql.yacc"
    { (yyval.sql_string)=(yyvsp[(1) - (1)].sql_string); }
    break;

  case 164:

/* Line 1455 of yacc.c  */
#line 1439 "sql.yacc"
    {SPRINTF7((yyval.str),"%s %s %s %s %s %s %s",(yyvsp[(1) - (7)].str),(yyvsp[(2) - (7)].str),(yyvsp[(3) - (7)].str),(yyvsp[(4) - (7)].str),(yyvsp[(5) - (7)].str),(yyvsp[(6) - (7)].str),(yyvsp[(7) - (7)].str));  add_feature("GRANT"); }
    break;

  case 165:

/* Line 1455 of yacc.c  */
#line 1440 "sql.yacc"
    {SPRINTF6((yyval.str),"%s %s %s %s %s %s",(yyvsp[(1) - (6)].str),(yyvsp[(2) - (6)].str),(yyvsp[(3) - (6)].str),(yyvsp[(4) - (6)].str),(yyvsp[(5) - (6)].str),(yyvsp[(6) - (6)].str));  add_feature("REVOKE"); }
    break;

  case 166:

/* Line 1455 of yacc.c  */
#line 1441 "sql.yacc"
    {SPRINTF4((yyval.str),"%s %s %s %s ",(yyvsp[(1) - (4)].str),(yyvsp[(2) - (4)].str),(yyvsp[(3) - (4)].str),(yyvsp[(4) - (4)].str)); add_feature("GRANT"); }
    break;

  case 167:

/* Line 1455 of yacc.c  */
#line 1442 "sql.yacc"
    {SPRINTF4((yyval.str),"%s %s %s %s ",(yyvsp[(1) - (4)].str),(yyvsp[(2) - (4)].str),(yyvsp[(3) - (4)].str),(yyvsp[(4) - (4)].str));  add_feature("REVOKE"); }
    break;

  case 171:

/* Line 1455 of yacc.c  */
#line 1452 "sql.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 172:

/* Line 1455 of yacc.c  */
#line 1453 "sql.yacc"
    {SPRINTF1((yyval.str)," %s ",(yyvsp[(1) - (1)].str));}
    break;

  case 173:

/* Line 1455 of yacc.c  */
#line 1454 "sql.yacc"
    {SPRINTF2((yyval.str)," %s %s",(yyvsp[(1) - (2)].str),(yyvsp[(2) - (2)].str));}
    break;

  case 174:

/* Line 1455 of yacc.c  */
#line 1458 "sql.yacc"
    {SPRINTF1((yyval.str)," %s ",(yyvsp[(1) - (1)].str));}
    break;

  case 175:

/* Line 1455 of yacc.c  */
#line 1459 "sql.yacc"
    {SPRINTF1((yyval.str)," %s ",(yyvsp[(1) - (1)].str));}
    break;

  case 178:

/* Line 1455 of yacc.c  */
#line 1466 "sql.yacc"
    {SPRINTF3((yyval.str)," %s %s %s",(yyvsp[(1) - (3)].str),(yyvsp[(2) - (3)].str),(yyvsp[(3) - (3)].str));}
    break;

  case 179:

/* Line 1455 of yacc.c  */
#line 1469 "sql.yacc"
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
#line 1478 "sql.yacc"
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
#line 1489 "sql.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 186:

/* Line 1455 of yacc.c  */
#line 1491 "sql.yacc"
    {SPRINTF3((yyval.str)," %s %s %s",(yyvsp[(1) - (3)].str),(yyvsp[(2) - (3)].str),(yyvsp[(3) - (3)].str));}
    break;

  case 188:

/* Line 1455 of yacc.c  */
#line 1497 "sql.yacc"
    {SPRINTF3((yyval.str)," %s %s %s",(yyvsp[(1) - (3)].str),(yyvsp[(2) - (3)].str),(yyvsp[(3) - (3)].str));}
    break;

  case 190:

/* Line 1455 of yacc.c  */
#line 1503 "sql.yacc"
    {SPRINTF3((yyval.str)," %s %s %s",(yyvsp[(1) - (3)].str),(yyvsp[(2) - (3)].str),(yyvsp[(3) - (3)].str));}
    break;

  case 193:

/* Line 1455 of yacc.c  */
#line 1513 "sql.yacc"
    {
		add_feature("CREATE_VIEW_AS_SELECT");
		(yyval.sql_string)=make_sql_string_and_free(acl_strdup((yyvsp[(1) - (6)].str)),kw_space,acl_strdup((yyvsp[(2) - (6)].str)),kw_space,acl_strdup((yyvsp[(3) - (6)].str)),kw_space,acl_strdup((yyvsp[(4) - (6)].str)),kw_space,(yyvsp[(5) - (6)].sql_string),kw_space,acl_strdup((yyvsp[(6) - (6)].str)),NULL);
	
}
    break;

  case 194:

/* Line 1455 of yacc.c  */
#line 1520 "sql.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 195:

/* Line 1455 of yacc.c  */
#line 1522 "sql.yacc"
    {SPRINTF3((yyval.str)," %s %s %s",(yyvsp[(1) - (3)].str),(yyvsp[(2) - (3)].str),(yyvsp[(3) - (3)].str));}
    break;

  case 197:

/* Line 1455 of yacc.c  */
#line 1528 "sql.yacc"
    {SPRINTF3((yyval.str)," %s %s %s",(yyvsp[(1) - (3)].str),(yyvsp[(2) - (3)].str),(yyvsp[(3) - (3)].str));}
    break;

  case 198:

/* Line 1455 of yacc.c  */
#line 1531 "sql.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 199:

/* Line 1455 of yacc.c  */
#line 1532 "sql.yacc"
    {
		add_feature("CREATE_VIEW_SELECT_WITH_CHECK");
	}
    break;

  case 200:

/* Line 1455 of yacc.c  */
#line 1539 "sql.yacc"
    {
		(yyval.sql_string)=make_sql_string_and_free(strdup("CHECK ("),(yyvsp[(3) - (4)].sql_string),kw_cb,NULL);
		add_feature("DDL_CHECK");
	}
    break;

  case 201:

/* Line 1455 of yacc.c  */
#line 1548 "sql.yacc"
    {SPRINTF5((yyval.str)," %s %s %s %s %s",(yyvsp[(1) - (5)].str),(yyvsp[(2) - (5)].str),(yyvsp[(3) - (5)].str),(yyvsp[(4) - (5)].str),(yyvsp[(5) - (5)].str));
	add_feature("DDL_FOREIGN_KEY");
}
    break;

  case 202:

/* Line 1455 of yacc.c  */
#line 1555 "sql.yacc"
    {SPRINTF2((yyval.str)," %s %s",(yyvsp[(1) - (2)].str),(yyvsp[(2) - (2)].str));
add_feature("DDL_REFERENCES");
}
    break;

  case 205:

/* Line 1455 of yacc.c  */
#line 1567 "sql.yacc"
    {SPRINTF4((yyval.str)," %s %s %s %s",(yyvsp[(1) - (4)].str),(yyvsp[(2) - (4)].str),(yyvsp[(3) - (4)].str),(yyvsp[(4) - (4)].str));}
    break;

  case 207:

/* Line 1455 of yacc.c  */
#line 1573 "sql.yacc"
    {SPRINTF3((yyval.str)," %s %s %s",(yyvsp[(1) - (3)].str),(yyvsp[(2) - (3)].str),(yyvsp[(3) - (3)].str));}
    break;

  case 208:

/* Line 1455 of yacc.c  */
#line 1578 "sql.yacc"
    {
		SPRINTF3((yyval.str)," UNIQUE %s %s %s",(yyvsp[(2) - (4)].str),(yyvsp[(3) - (4)].str),(yyvsp[(4) - (4)].str));
add_feature("DDL_UNIQUE");
	}
    break;

  case 209:

/* Line 1455 of yacc.c  */
#line 1582 "sql.yacc"
    {
		ansi_violation("Use UNIQUE not DISTINCT",0);
		SPRINTF3((yyval.str)," UNIQUE %s %s %s",(yyvsp[(2) - (4)].str),(yyvsp[(3) - (4)].str),(yyvsp[(4) - (4)].str));
add_feature("DDL_DISTINCT");
	}
    break;

  case 210:

/* Line 1455 of yacc.c  */
#line 1588 "sql.yacc"
    {SPRINTF4((yyval.str)," %s %s %s %s",(yyvsp[(1) - (4)].str),(yyvsp[(2) - (4)].str),(yyvsp[(3) - (4)].str),(yyvsp[(4) - (4)].str));
add_feature("DDL_PRIMARY_KEY");
}
    break;

  case 212:

/* Line 1455 of yacc.c  */
#line 1596 "sql.yacc"
    {SPRINTF3((yyval.str)," %s %s %s",(yyvsp[(1) - (3)].str),(yyvsp[(2) - (3)].str),(yyvsp[(3) - (3)].str));}
    break;

  case 213:

/* Line 1455 of yacc.c  */
#line 1601 "sql.yacc"
    {
		(yyval.sql_string)=acl_strdup((yyvsp[(1) - (1)].str));
	}
    break;

  case 214:

/* Line 1455 of yacc.c  */
#line 1604 "sql.yacc"
    {
		(yyval.sql_string)=acl_strdup((yyvsp[(1) - (1)].str));
	}
    break;

  case 215:

/* Line 1455 of yacc.c  */
#line 1607 "sql.yacc"
    {
		(yyval.sql_string)=(yyvsp[(1) - (1)].sql_string);
	}
    break;

  case 216:

/* Line 1455 of yacc.c  */
#line 1614 "sql.yacc"
    {SPRINTF2((yyval.str)," %s %s",(yyvsp[(1) - (2)].str),(yyvsp[(2) - (2)].str)); add_feature("DDL_DEFAULT_VALUE"); }
    break;

  case 217:

/* Line 1455 of yacc.c  */
#line 1615 "sql.yacc"
    {SPRINTF1((yyval.str)," DEFAULT %s", A4GLSQLCV_get_sqlconst("USER")); add_feature("DDL_DEFAULT_VALUE"); }
    break;

  case 218:

/* Line 1455 of yacc.c  */
#line 1616 "sql.yacc"
    {SPRINTF1((yyval.str)," DEFAULT %s", A4GLSQLCV_get_sqlconst("TODAY")); add_feature("DDL_DEFAULT_VALUE"); }
    break;

  case 219:

/* Line 1455 of yacc.c  */
#line 1617 "sql.yacc"
    { SPRINTF1((yyval.str)," %s",(yyvsp[(1) - (1)].str)); add_feature("DDL_DEFAULT_VALUE"); }
    break;

  case 220:

/* Line 1455 of yacc.c  */
#line 1623 "sql.yacc"
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
#line 1646 "sql.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 223:

/* Line 1455 of yacc.c  */
#line 1650 "sql.yacc"
    {
		(yyval.sql_string)=acl_strdup("");
	}
    break;

  case 224:

/* Line 1455 of yacc.c  */
#line 1652 "sql.yacc"
    {
		(yyval.sql_string)=(yyvsp[(1) - (1)].sql_string);
	}
    break;

  case 225:

/* Line 1455 of yacc.c  */
#line 1659 "sql.yacc"
    {
		(yyval.sql_string)=(yyvsp[(1) - (1)].sql_string);
	}
    break;

  case 226:

/* Line 1455 of yacc.c  */
#line 1662 "sql.yacc"
    {
		(yyval.sql_string)=make_sql_string_and_free((yyvsp[(1) - (2)].sql_string),kw_space,(yyvsp[(2) - (2)].sql_string),NULL);
	}
    break;

  case 227:

/* Line 1455 of yacc.c  */
#line 1668 "sql.yacc"
    {
		(yyval.sql_string)=make_sql_string_and_free((yyvsp[(1) - (2)].sql_string),acl_strdup((yyvsp[(2) - (2)].str)),NULL);
	}
    break;

  case 228:

/* Line 1455 of yacc.c  */
#line 1676 "sql.yacc"
    {
		SPRINTF1((yyval.str)," %s ",(yyvsp[(1) - (1)].str));
		(yyval.sql_string)=acl_strdup((yyval.str));
		add_feature("DDL_NOT_NULL");
	}
    break;

  case 229:

/* Line 1455 of yacc.c  */
#line 1681 "sql.yacc"
    {
		SPRINTF0((yyval.str)," NOT NULL UNIQUE ");
		(yyval.sql_string)=acl_strdup((yyval.str));
		add_feature("DDL_NOT_NULL");
		add_feature("DDL_UNIQUE");
	}
    break;

  case 230:

/* Line 1455 of yacc.c  */
#line 1687 "sql.yacc"
    {
		SPRINTF0((yyval.str)," UNIQUE ");
		(yyval.sql_string)=acl_strdup((yyval.str));
		add_feature("DDL_UNIQUE");
	}
    break;

  case 231:

/* Line 1455 of yacc.c  */
#line 1692 "sql.yacc"
    {
		ansi_violation("Use UNIQUE not DISTINCT",0);
		SPRINTF0((yyval.str)," UNIQUE ");
		(yyval.sql_string)=acl_strdup((yyval.str));
		add_feature("DDL_DISTINCT");
	}
    break;

  case 232:

/* Line 1455 of yacc.c  */
#line 1698 "sql.yacc"
    {
		(yyval.sql_string)=acl_strdup((yyvsp[(1) - (1)].str));
	}
    break;

  case 233:

/* Line 1455 of yacc.c  */
#line 1701 "sql.yacc"
    {
		(yyval.sql_string)=make_sql_string_and_free(acl_strdup("CHECK ("),(yyvsp[(3) - (4)].sql_string),kw_cb,NULL);
		add_feature("DDL_CHECK");
		
	}
    break;

  case 234:

/* Line 1455 of yacc.c  */
#line 1706 "sql.yacc"
    {
		(yyval.sql_string)=make_sql_string_and_free(acl_strdup(" PRIMARY KEY "),NULL);
		add_feature("DDL_PRIMARY_KEY");
	}
    break;

  case 235:

/* Line 1455 of yacc.c  */
#line 1715 "sql.yacc"
    {
		add_feature("CREATE_SCHEMA");

(yyval.sql_string)=make_sql_string_and_free(acl_strdup((yyvsp[(1) - (3)].str)),kw_space,acl_strdup((yyvsp[(2) - (3)].str)),kw_space,acl_strdup((yyvsp[(3) - (3)].str)),NULL);
}
    break;

  case 236:

/* Line 1455 of yacc.c  */
#line 1724 "sql.yacc"
    {SPRINTF1((yyval.str)," %s",(yyvsp[(1) - (1)].str));}
    break;

  case 239:

/* Line 1455 of yacc.c  */
#line 1733 "sql.yacc"
    {
		(yyval.sql_string)=make_sql_string_and_free((yyvsp[(1) - (2)].sql_string),kw_space,(yyvsp[(2) - (2)].sql_string),NULL);
	}
    break;

  case 240:

/* Line 1455 of yacc.c  */
#line 1739 "sql.yacc"
    {
		(yyval.sql_string)=(yyvsp[(1) - (1)].sql_string);
	}
    break;

  case 241:

/* Line 1455 of yacc.c  */
#line 1742 "sql.yacc"
    {
		(yyval.sql_string)=acl_strdup((yyvsp[(1) - (1)].str));
	}
    break;

  case 242:

/* Line 1455 of yacc.c  */
#line 1753 "sql.yacc"
    {
		 add_feature("HAVING"); 
		(yyval.s_select_list_item)=(yyvsp[(2) - (2)].s_select_list_item);
	}
    break;

  case 243:

/* Line 1455 of yacc.c  */
#line 1762 "sql.yacc"
    {
		 (yyval.s_select_list_item)=(yyvsp[(2) - (2)].s_select_list_item);
	}
    break;

  case 244:

/* Line 1455 of yacc.c  */
#line 1769 "sql.yacc"
    {
		(yyval.u_table)=(yyvsp[(2) - (2)].u_table);
	}
    break;

  case 245:

/* Line 1455 of yacc.c  */
#line 1775 "sql.yacc"
    {(yyval.u_table)=(yyvsp[(1) - (1)].u_table);}
    break;

  case 246:

/* Line 1455 of yacc.c  */
#line 1776 "sql.yacc"
    {
		(yyval.u_table)=A4GLSQLPARSE_append_tablename((yyvsp[(1) - (3)].u_table),(yyvsp[(3) - (3)].u_table),E_OUTER_NONE,NULL);
	}
    break;

  case 247:

/* Line 1455 of yacc.c  */
#line 1779 "sql.yacc"
    {
		(yyval.u_table)=A4GLSQLPARSE_append_tablename((yyvsp[(1) - (4)].u_table),(yyvsp[(4) - (4)].u_table),E_OUTER_NORMAL,NULL);
		A4GL_warn("OUTER join *may* not be portable to non-informix database");
		add_feature("SELECT_OUTER");
	}
    break;

  case 248:

/* Line 1455 of yacc.c  */
#line 1784 "sql.yacc"
    {
		(yyval.u_table)=A4GLSQLPARSE_append_tablename((yyvsp[(1) - (6)].u_table),(yyvsp[(5) - (6)].u_table),E_OUTER_NORMAL,NULL);
		A4GL_warn("OUTER join *may* not be portable to non-informix database");
		add_feature("SELECT_OUTER");
	}
    break;

  case 249:

/* Line 1455 of yacc.c  */
#line 1795 "sql.yacc"
    {
		(yyval.u_table)=A4GLSQLPARSE_append_tablename((yyvsp[(1) - (5)].u_table),(yyvsp[(3) - (5)].u_table),E_OUTER_LEFT_OUTER, (yyvsp[(5) - (5)].s_select_list_item));
		add_feature("SELECT_OUTER");
	}
    break;

  case 250:

/* Line 1455 of yacc.c  */
#line 1799 "sql.yacc"
    {
		(yyval.u_table)=A4GLSQLPARSE_append_tablename((yyvsp[(1) - (5)].u_table),(yyvsp[(3) - (5)].u_table),E_INNER, (yyvsp[(5) - (5)].s_select_list_item));
		add_feature("SELECT_INNER");
	}
    break;

  case 252:

/* Line 1455 of yacc.c  */
#line 1807 "sql.yacc"
    {(yyval.u_table)=(yyvsp[(2) - (3)].u_table);}
    break;

  case 253:

/* Line 1455 of yacc.c  */
#line 1811 "sql.yacc"
    { 
			//A4GL_add_crud("SELECT",$<str>1);
			(yyval.u_table)=A4GLSQLPARSE_new_tablename((yyvsp[(1) - (1)].str),NULL);
	}
    break;

  case 254:

/* Line 1455 of yacc.c  */
#line 1815 "sql.yacc"
    { 
			//A4GL_add_crud("SELECT",$<str>1);
			(yyval.u_table)=A4GLSQLPARSE_new_tablename((yyvsp[(1) - (2)].str),(yyvsp[(2) - (2)].str));
	}
    break;

  case 255:

/* Line 1455 of yacc.c  */
#line 1819 "sql.yacc"
    { 
			//A4GL_add_crud("SELECT",$<str>1);
			(yyval.u_table)=A4GLSQLPARSE_new_tablename((yyvsp[(1) - (3)].str),(yyvsp[(3) - (3)].str));
	}
    break;

  case 256:

/* Line 1455 of yacc.c  */
#line 1826 "sql.yacc"
    {
			/* No from or where etc.. */
			/* eg.. select user ; */
			(yyval.s_select)=new_empty_select();
		}
    break;

  case 257:

/* Line 1455 of yacc.c  */
#line 1831 "sql.yacc"
    {
		(yyval.s_select)=(yyvsp[(2) - (2)].s_select);
		(yyval.s_select)->first=(yyvsp[(1) - (2)].u_table);
			A4GL_set_associated_mem( (yyval.s_select), (yyval.s_select)->first);
}
    break;

  case 258:

/* Line 1455 of yacc.c  */
#line 1839 "sql.yacc"
    {
		(yyval.s_select)=(yyvsp[(1) - (1)].s_select);
	}
    break;

  case 259:

/* Line 1455 of yacc.c  */
#line 1842 "sql.yacc"
    {
		(yyval.s_select)=(yyvsp[(2) - (2)].s_select);
		(yyval.s_select)->where_clause=(yyvsp[(1) - (2)].s_select_list_item);
	}
    break;

  case 260:

/* Line 1455 of yacc.c  */
#line 1848 "sql.yacc"
    {
		(yyval.s_select)=new_empty_select();
	}
    break;

  case 261:

/* Line 1455 of yacc.c  */
#line 1851 "sql.yacc"
    {
		(yyval.s_select)=new_empty_select();
		(yyval.s_select)->group_by=(yyvsp[(1) - (1)].s_select_list_item_list);
		(yyval.s_select)->having=0;
	}
    break;

  case 262:

/* Line 1455 of yacc.c  */
#line 1856 "sql.yacc"
    {
		(yyval.s_select)=new_empty_select();
		(yyval.s_select)->group_by=(yyvsp[(1) - (2)].s_select_list_item_list);
		(yyval.s_select)->having=(yyvsp[(2) - (2)].s_select_list_item);
	}
    break;

  case 263:

/* Line 1455 of yacc.c  */
#line 1861 "sql.yacc"
    {
		(yyval.s_select)=new_empty_select();
		(yyval.s_select)->group_by=0;
		(yyval.s_select)->having=(yyvsp[(1) - (1)].s_select_list_item);

	}
    break;

  case 264:

/* Line 1455 of yacc.c  */
#line 1874 "sql.yacc"
    {
		(yyval.s_select_list_item)=(yyvsp[(1) - (1)].s_select_list_item);
	}
    break;

  case 265:

/* Line 1455 of yacc.c  */
#line 1877 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_op_expr((yyvsp[(1) - (3)].s_select_list_item),(yyvsp[(3) - (3)].s_select_list_item)," OR ");
	}
    break;

  case 266:

/* Line 1455 of yacc.c  */
#line 1883 "sql.yacc"
    {
		(yyval.s_select_list_item)=(yyvsp[(1) - (1)].s_select_list_item);
	}
    break;

  case 267:

/* Line 1455 of yacc.c  */
#line 1886 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_op_expr((yyvsp[(1) - (3)].s_select_list_item),(yyvsp[(3) - (3)].s_select_list_item)," AND ");
	}
    break;

  case 268:

/* Line 1455 of yacc.c  */
#line 1892 "sql.yacc"
    {
		(yyval.s_select_list_item)=(yyvsp[(1) - (1)].s_select_list_item);
	}
    break;

  case 269:

/* Line 1455 of yacc.c  */
#line 1895 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_simple_expr(E_SLI_NOT,(yyvsp[(2) - (2)].s_select_list_item));
	}
    break;

  case 270:

/* Line 1455 of yacc.c  */
#line 1901 "sql.yacc"
    {
		(yyval.s_select_list_item)=(yyvsp[(1) - (1)].s_select_list_item);
	}
    break;

  case 271:

/* Line 1455 of yacc.c  */
#line 1904 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_simple_expr(E_SLI_BRACKET_EXPR,(yyvsp[(2) - (3)].s_select_list_item));
	}
    break;

  case 272:

/* Line 1455 of yacc.c  */
#line 1911 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_sq(E_SQE_EXISTS, (yyvsp[(2) - (2)].s_select_list_item));
		add_feature("WHERE_EXISTS");
	}
    break;

  case 273:

/* Line 1455 of yacc.c  */
#line 1915 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_sq(E_SQE_NOT_EXISTS, (yyvsp[(2) - (2)].s_select_list_item));
		add_feature("WHERE_EXISTS");
	}
    break;

  case 274:

/* Line 1455 of yacc.c  */
#line 1926 "sql.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 275:

/* Line 1455 of yacc.c  */
#line 1926 "sql.yacc"
    {SPRINTF1((yyval.str)," ESCAPE %s",(yyvsp[(2) - (2)].str));add_feature("WHERE_MATCHES_ESCAPE");}
    break;

  case 276:

/* Line 1455 of yacc.c  */
#line 1927 "sql.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 277:

/* Line 1455 of yacc.c  */
#line 1927 "sql.yacc"
    {SPRINTF1((yyval.str)," ESCAPE %s",(yyvsp[(2) - (2)].str));add_feature("WHERE_ILIKE_ESCAPE");}
    break;

  case 278:

/* Line 1455 of yacc.c  */
#line 1928 "sql.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 279:

/* Line 1455 of yacc.c  */
#line 1928 "sql.yacc"
    {SPRINTF1((yyval.str)," ESCAPE %s",(yyvsp[(2) - (2)].str));add_feature("WHERE_LIKE_ESCAPE");}
    break;

  case 280:

/* Line 1455 of yacc.c  */
#line 1931 "sql.yacc"
    {
		 (yyval.s_select_list_item)=(yyvsp[(1) - (1)].s_select_list_item);
	}
    break;

  case 282:

/* Line 1455 of yacc.c  */
#line 1941 "sql.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 283:

/* Line 1455 of yacc.c  */
#line 1942 "sql.yacc"
    {strcpy((yyval.str)," NOT ");}
    break;

  case 284:

/* Line 1455 of yacc.c  */
#line 1947 "sql.yacc"
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
#line 1956 "sql.yacc"
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
#line 1964 "sql.yacc"
    { 
			(yyval.s_select_list_item)=new_select_list_item_op_expr((yyvsp[(1) - (3)].s_select_list_item),(yyvsp[(3) - (3)].s_select_list_item),(yyvsp[(2) - (3)].str));
	}
    break;

  case 287:

/* Line 1455 of yacc.c  */
#line 1967 "sql.yacc"
    { 
			(yyval.s_select_list_item)=new_select_list_item_op_expr((yyvsp[(1) - (3)].s_select_list_item),(yyvsp[(3) - (3)].s_select_list_item),"=");
	}
    break;

  case 288:

/* Line 1455 of yacc.c  */
#line 1970 "sql.yacc"
    { 
			FPRINTF(stderr,"Warning: Corrected =NULL to IS NULL line %d\n",yylineno);
			(yyval.s_select_list_item)=new_select_list_item_simple_expr(E_SLI_ISNULL,(yyvsp[(1) - (3)].s_select_list_item));
	}
    break;

  case 289:

/* Line 1455 of yacc.c  */
#line 1974 "sql.yacc"
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
#line 1981 "sql.yacc"
    { 
			(yyval.s_select_list_item)=new_select_list_item_regex(E_SLI_REGEX_LIKE,(yyvsp[(1) - (4)].s_select_list_item),(yyvsp[(3) - (4)].s_select_list_item),(yyvsp[(4) - (4)].str));
	}
    break;

  case 291:

/* Line 1455 of yacc.c  */
#line 1984 "sql.yacc"
    { 
			(yyval.s_select_list_item)=new_select_list_item_regex(E_SLI_REGEX_NOT_LIKE,(yyvsp[(1) - (4)].s_select_list_item),(yyvsp[(3) - (4)].s_select_list_item),(yyvsp[(4) - (4)].str));

	}
    break;

  case 292:

/* Line 1455 of yacc.c  */
#line 1988 "sql.yacc"
    { 
			(yyval.s_select_list_item)=new_select_list_item_regex(E_SLI_REGEX_ILIKE,(yyvsp[(1) - (4)].s_select_list_item),(yyvsp[(3) - (4)].s_select_list_item),(yyvsp[(4) - (4)].str));
	}
    break;

  case 293:

/* Line 1455 of yacc.c  */
#line 1991 "sql.yacc"
    { 
			(yyval.s_select_list_item)=new_select_list_item_regex(E_SLI_REGEX_NOT_ILIKE,(yyvsp[(1) - (4)].s_select_list_item),(yyvsp[(3) - (4)].s_select_list_item),(yyvsp[(4) - (4)].str));
	}
    break;

  case 294:

/* Line 1455 of yacc.c  */
#line 1994 "sql.yacc"
    { 
			(yyval.s_select_list_item)=new_select_list_item_regex(E_SLI_REGEX_MATCHES,(yyvsp[(1) - (4)].s_select_list_item),(yyvsp[(3) - (4)].s_select_list_item),(yyvsp[(4) - (4)].str));
	}
    break;

  case 295:

/* Line 1455 of yacc.c  */
#line 1997 "sql.yacc"
    { 
			(yyval.s_select_list_item)=new_select_list_item_regex(E_SLI_REGEX_NOT_MATCHES,(yyvsp[(1) - (4)].s_select_list_item),(yyvsp[(3) - (4)].s_select_list_item),(yyvsp[(4) - (4)].str));
	}
    break;

  case 296:

/* Line 1455 of yacc.c  */
#line 2003 "sql.yacc"
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
#line 2010 "sql.yacc"
    {
			strcpy((yyval.str)," < ");
	}
    break;

  case 298:

/* Line 1455 of yacc.c  */
#line 2013 "sql.yacc"
    {
			strcpy((yyval.str)," > ");
	}
    break;

  case 299:

/* Line 1455 of yacc.c  */
#line 2016 "sql.yacc"
    {
			strcpy((yyval.str)," ~ ");
	}
    break;

  case 300:

/* Line 1455 of yacc.c  */
#line 2019 "sql.yacc"
    {strcpy((yyval.str)," <= ");}
    break;

  case 301:

/* Line 1455 of yacc.c  */
#line 2020 "sql.yacc"
    {strcpy((yyval.str)," >= ");}
    break;

  case 302:

/* Line 1455 of yacc.c  */
#line 2025 "sql.yacc"
    {
		(yyval.s_select_list_item)=(yyvsp[(1) - (1)].s_select_list_item);
	}
    break;

  case 303:

/* Line 1455 of yacc.c  */
#line 2028 "sql.yacc"
    {
		(yyval.s_select_list_item)=(yyvsp[(1) - (1)].s_select_list_item);
	}
    break;

  case 304:

/* Line 1455 of yacc.c  */
#line 2031 "sql.yacc"
    {
		(yyval.s_select_list_item)=(yyvsp[(1) - (1)].s_select_list_item);
	}
    break;

  case 305:

/* Line 1455 of yacc.c  */
#line 2034 "sql.yacc"
    {
                 (yyval.s_select_list_item)=(yyvsp[(1) - (1)].s_select_list_item);
        }
    break;

  case 306:

/* Line 1455 of yacc.c  */
#line 2041 "sql.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 307:

/* Line 1455 of yacc.c  */
#line 2042 "sql.yacc"
    {strcpy((yyval.str)," ALL "); add_feature("AGG_ALL");}
    break;

  case 308:

/* Line 1455 of yacc.c  */
#line 2043 "sql.yacc"
    {
		strcpy((yyval.str)," DISTINCT ");
		add_feature("AGG_DISTINCT");
	}
    break;

  case 309:

/* Line 1455 of yacc.c  */
#line 2047 "sql.yacc"
    {
		ansi_violation("Use DISTINCT not UNIQUE",0);
		strcpy((yyval.str)," DISTINCT ");
		add_feature("AGG_DISTINCT");
	}
    break;

  case 310:

/* Line 1455 of yacc.c  */
#line 2054 "sql.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 311:

/* Line 1455 of yacc.c  */
#line 2055 "sql.yacc"
    {strcpy((yyval.str)," ALL "); add_feature("UNION_ALL");}
    break;

  case 312:

/* Line 1455 of yacc.c  */
#line 2056 "sql.yacc"
    {
		strcpy((yyval.str)," DISTINCT ");
		add_feature("UNION_DISTINCT");
	}
    break;

  case 313:

/* Line 1455 of yacc.c  */
#line 2060 "sql.yacc"
    {
		ansi_violation("Use DISTINCT not UNIQUE",0);
		add_feature("UNION_DISTINCT");
		strcpy((yyval.str)," DISTINCT ");
	}
    break;

  case 314:

/* Line 1455 of yacc.c  */
#line 2074 "sql.yacc"
    {
		strcpy((yyval.str),A4GLSQLCV_dtype_alias((yyvsp[(1) - (1)].str)));
	}
    break;

  case 319:

/* Line 1455 of yacc.c  */
#line 2089 "sql.yacc"
    {SPRINTF4((yyval.str)," %s %s%s%s",(yyvsp[(1) - (4)].str),(yyvsp[(2) - (4)].str),(yyvsp[(3) - (4)].str),(yyvsp[(4) - (4)].str));}
    break;

  case 320:

/* Line 1455 of yacc.c  */
#line 2093 "sql.yacc"
    {strcpy((yyval.str),"SERIAL"); add_feature("DDL_SERIAL"); }
    break;

  case 321:

/* Line 1455 of yacc.c  */
#line 2094 "sql.yacc"
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
#line 2103 "sql.yacc"
    {strcpy((yyval.str),"SERIAL8"); add_feature("DDL_SERIAL8"); }
    break;

  case 323:

/* Line 1455 of yacc.c  */
#line 2105 "sql.yacc"
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
#line 2114 "sql.yacc"
    {
 			add_feature("DDL_DECIMAL");
	}
    break;

  case 325:

/* Line 1455 of yacc.c  */
#line 2117 "sql.yacc"
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
#line 2125 "sql.yacc"
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
#line 2135 "sql.yacc"
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
#line 2143 "sql.yacc"
    {strcpy((yyval.str),"DATE");
 			add_feature("DDL_DATE"); }
    break;

  case 329:

/* Line 1455 of yacc.c  */
#line 2145 "sql.yacc"
    {strcpy((yyval.str),"INTEGER");}
    break;

  case 330:

/* Line 1455 of yacc.c  */
#line 2146 "sql.yacc"
    {strcpy((yyval.str),"SMALLINT");}
    break;

  case 331:

/* Line 1455 of yacc.c  */
#line 2147 "sql.yacc"
    {strcpy((yyval.str),"NCHAR"); add_feature("DDL_NCHAR");}
    break;

  case 332:

/* Line 1455 of yacc.c  */
#line 2148 "sql.yacc"
    {SPRINTF1((yyval.str),"NCHAR(%s)",(yyvsp[(3) - (4)].str)); add_feature("DDL_NCHAR");}
    break;

  case 333:

/* Line 1455 of yacc.c  */
#line 2149 "sql.yacc"
    {add_feature("DDL_NVARCHAR");}
    break;

  case 334:

/* Line 1455 of yacc.c  */
#line 2150 "sql.yacc"
    {SPRINTF1((yyval.str),"NVARCHAR(%s)",(yyvsp[(3) - (4)].str)); add_feature("DDL_NVARCHAR");}
    break;

  case 335:

/* Line 1455 of yacc.c  */
#line 2151 "sql.yacc"
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
#line 2159 "sql.yacc"
    {SPRINTF2((yyval.str),"DATETIME %s TO %s",(yyvsp[(2) - (4)].str),(yyvsp[(4) - (4)].str)); add_feature("DDL_DATETIME");}
    break;

  case 337:

/* Line 1455 of yacc.c  */
#line 2160 "sql.yacc"
    {add_feature("DDL_DATETIME");}
    break;

  case 338:

/* Line 1455 of yacc.c  */
#line 2161 "sql.yacc"
    {SPRINTF2((yyval.str),"INTERVAL %s TO %s",(yyvsp[(2) - (4)].str),(yyvsp[(4) - (4)].str)); add_feature("DDL_INTERVAL");}
    break;

  case 339:

/* Line 1455 of yacc.c  */
#line 2162 "sql.yacc"
    {strcpy((yyval.str),(yyvsp[(1) - (1)].str));}
    break;

  case 340:

/* Line 1455 of yacc.c  */
#line 2163 "sql.yacc"
    {add_feature("DDL_INTERVAL");}
    break;

  case 341:

/* Line 1455 of yacc.c  */
#line 2164 "sql.yacc"
    {SPRINTF3((yyval.str),"INTERVAL %s(%s) TO %s",(yyvsp[(2) - (7)].str),(yyvsp[(4) - (7)].str),(yyvsp[(7) - (7)].str)); add_feature("DDL_INTERVAL");}
    break;

  case 342:

/* Line 1455 of yacc.c  */
#line 2165 "sql.yacc"
    {add_feature("DDL_TEXT");}
    break;

  case 343:

/* Line 1455 of yacc.c  */
#line 2166 "sql.yacc"
    {add_feature("DDL_BYTE");}
    break;

  case 344:

/* Line 1455 of yacc.c  */
#line 2167 "sql.yacc"
    {add_feature("DDL_VARCHAR");}
    break;

  case 345:

/* Line 1455 of yacc.c  */
#line 2168 "sql.yacc"
    {SPRINTF1((yyval.str),"VARCHAR(%s)",(yyvsp[(3) - (4)].str));add_feature("DDL_VARCHAR");}
    break;

  case 346:

/* Line 1455 of yacc.c  */
#line 2169 "sql.yacc"
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
#line 2179 "sql.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 348:

/* Line 1455 of yacc.c  */
#line 2180 "sql.yacc"
    {
		SPRINTF1((yyval.str),",%s",(yyvsp[(2) - (2)].str));
}
    break;

  case 349:

/* Line 1455 of yacc.c  */
#line 2187 "sql.yacc"
    {SPRINTF4((yyval.str)," %s %s %s %s",(yyvsp[(1) - (4)].str),(yyvsp[(2) - (4)].str),(yyvsp[(3) - (4)].str),(yyvsp[(4) - (4)].str));}
    break;

  case 353:

/* Line 1455 of yacc.c  */
#line 2191 "sql.yacc"
    {add_feature("DDL_DOUBLE_PRECISION"); SPRINTF1((yyval.str)," %s",(yyvsp[(1) - (1)].str));}
    break;

  case 359:

/* Line 1455 of yacc.c  */
#line 2216 "sql.yacc"
    {(yyval.int_list.i0)=0;}
    break;

  case 360:

/* Line 1455 of yacc.c  */
#line 2217 "sql.yacc"
    {
		(yyval.int_list.i0)=1;
		(yyval.int_list.i1)=atoi((yyvsp[(2) - (3)].str));
	}
    break;

  case 361:

/* Line 1455 of yacc.c  */
#line 2221 "sql.yacc"
    {
		(yyval.int_list.i0)=2;
		(yyval.int_list.i1)=atoi((yyvsp[(2) - (5)].str));
		(yyval.int_list.i2)=atoi((yyvsp[(4) - (5)].str));
	}
    break;

  case 362:

/* Line 1455 of yacc.c  */
#line 2229 "sql.yacc"
    {
		strcpy((yyval.str),(yyvsp[(1) - (1)].str));
	}
    break;

  case 363:

/* Line 1455 of yacc.c  */
#line 2232 "sql.yacc"
    {
		strcpy((yyval.str),(yyvsp[(2) - (2)].str));
	}
    break;

  case 364:

/* Line 1455 of yacc.c  */
#line 2239 "sql.yacc"
    {
		(yyval.s_select_list_item)= (yyvsp[(1) - (1)].s_select_list_item);
	}
    break;

  case 365:

/* Line 1455 of yacc.c  */
#line 2242 "sql.yacc"
    {
		(yyval.s_select_list_item)= (yyvsp[(2) - (2)].s_select_list_item);
	}
    break;

  case 366:

/* Line 1455 of yacc.c  */
#line 2252 "sql.yacc"
    { 
		(yyval.s_select_list_item)=new_select_list_item_col(0,(yyvsp[(1) - (2)].str),&(yyvsp[(2) - (2)].int_list));
	}
    break;

  case 367:

/* Line 1455 of yacc.c  */
#line 2255 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_col((yyvsp[(1) - (4)].str),(yyvsp[(3) - (4)].str),&(yyvsp[(4) - (4)].int_list));
	}
    break;

  case 368:

/* Line 1455 of yacc.c  */
#line 2258 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_col((yyvsp[(1) - (3)].str),"*",0);
	}
    break;

  case 369:

/* Line 1455 of yacc.c  */
#line 2261 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_col(0,"rowid",0);
	}
    break;

  case 370:

/* Line 1455 of yacc.c  */
#line 2268 "sql.yacc"
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
#line 2275 "sql.yacc"
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
#line 2283 "sql.yacc"
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
#line 2292 "sql.yacc"
    {
		SPRINTF1((yyval.str),"%s",A4GLSQLCV_check_colname((yyvsp[(1) - (3)].str),"*"));
		ADDMAP("Use Column",(yyval.str));
	}
    break;

  case 375:

/* Line 1455 of yacc.c  */
#line 2303 "sql.yacc"
    { strcpy((yyval.str),(yyvsp[(1) - (1)].str)); 
#ifdef DEBUG
A4GL_debug("Set $<str>$ to %s\n",(yyval.str)); 
#endif
}
    break;

  case 379:

/* Line 1455 of yacc.c  */
#line 2315 "sql.yacc"
    { strcpy((yyval.str),A4GLSQLCV_generate_current(0,0)); 
}
    break;

  case 380:

/* Line 1455 of yacc.c  */
#line 2317 "sql.yacc"
    {
		strcpy((yyval.str),A4GLSQLCV_generate_current((yyvsp[(1) - (3)].str),(yyvsp[(3) - (3)].str)));
	}
    break;

  case 395:

/* Line 1455 of yacc.c  */
#line 2327 "sql.yacc"
    {SPRINTF1((yyval.str),"FRACTION(%s)",(yyvsp[(3) - (4)].str));}
    break;

  case 396:

/* Line 1455 of yacc.c  */
#line 2372 "sql.yacc"
    { (yyval.sql_string)=make_sql_string_and_free(acl_strdup((yyvsp[(1) - (1)].str)), NULL);}
    break;

  case 397:

/* Line 1455 of yacc.c  */
#line 2373 "sql.yacc"
    { (yyval.sql_string)=make_sql_string_and_free(acl_strdup((yyvsp[(1) - (1)].str)), NULL);}
    break;

  case 398:

/* Line 1455 of yacc.c  */
#line 2374 "sql.yacc"
    { (yyval.sql_string)=make_sql_string_and_free(acl_strdup((yyvsp[(1) - (1)].str)), NULL);}
    break;

  case 399:

/* Line 1455 of yacc.c  */
#line 2379 "sql.yacc"
    { add_feature("RENAME_TABLE"); strcpy((yyval.str),A4GLSQLCV_rentab((yyvsp[(2) - (4)].str),(yyvsp[(4) - (4)].str))); }
    break;

  case 400:

/* Line 1455 of yacc.c  */
#line 2380 "sql.yacc"
    { add_feature("RENAME_COLUMN"); strcpy((yyval.str),A4GLSQLCV_rencol((yyvsp[(2) - (6)].str),(yyvsp[(4) - (6)].str),(yyvsp[(6) - (6)].str)) ); }
    break;

  case 403:

/* Line 1455 of yacc.c  */
#line 2388 "sql.yacc"
    {
		add_feature("UNLOCK_TABLE");
		SPRINTF2((yyval.str),"%s %s",(yyvsp[(1) - (2)].str),(yyvsp[(2) - (2)].str));
	}
    break;

  case 404:

/* Line 1455 of yacc.c  */
#line 2395 "sql.yacc"
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
#line 2406 "sql.yacc"
    { add_feature("LOCK_TABLE_SHARED");}
    break;

  case 406:

/* Line 1455 of yacc.c  */
#line 2407 "sql.yacc"
    {add_feature("LOCK_TABLE_EXCLUSIVE");}
    break;

  case 407:

/* Line 1455 of yacc.c  */
#line 2420 "sql.yacc"
    {strcpy((yyval.str),A4GLSQLCV_datetime_value((yyvsp[(1) - (1)].str)));}
    break;

  case 408:

/* Line 1455 of yacc.c  */
#line 2421 "sql.yacc"
    {strcpy((yyval.str),A4GLSQLCV_make_dtime_extend((yyvsp[(1) - (4)].str),(yyvsp[(2) - (4)].str),(yyvsp[(4) - (4)].str),0));}
    break;

  case 409:

/* Line 1455 of yacc.c  */
#line 2425 "sql.yacc"
    {strcpy((yyval.str),(yyvsp[(1) - (1)].str));}
    break;

  case 410:

/* Line 1455 of yacc.c  */
#line 2429 "sql.yacc"
    {strcpy((yyval.str),A4GLSQLCV_interval_value((yyvsp[(1) - (1)].str)));}
    break;

  case 411:

/* Line 1455 of yacc.c  */
#line 2430 "sql.yacc"
    {
			strcpy((yyval.str),A4GLSQLCV_make_ival_extend((yyvsp[(1) - (7)].str),(yyvsp[(2) - (7)].str),(yyvsp[(4) - (7)].str),(yyvsp[(7) - (7)].str),0));
		}
    break;

  case 412:

/* Line 1455 of yacc.c  */
#line 2433 "sql.yacc"
    {
		strcpy((yyval.str),A4GLSQLCV_make_ival_extend((yyvsp[(1) - (4)].str),(yyvsp[(2) - (4)].str),(char *)0, (yyvsp[(4) - (4)].str),0));
	}
    break;

  case 413:

/* Line 1455 of yacc.c  */
#line 2439 "sql.yacc"
    {SPRINTF1((yyval.str),"%s",(yyvsp[(1) - (1)].str));}
    break;

  case 414:

/* Line 1455 of yacc.c  */
#line 2443 "sql.yacc"
    {
	strcpy((yyval.str),(yyvsp[(2) - (2)].str));
}
    break;

  case 415:

/* Line 1455 of yacc.c  */
#line 2466 "sql.yacc"
    {
		(yyval.s_select_list_item_list)=(yyvsp[(3) - (3)].s_select_list_item_list);
		add_feature("ORDER_BY");
	}
    break;

  case 416:

/* Line 1455 of yacc.c  */
#line 2476 "sql.yacc"
    {
			(yyval.s_select_list_item_list)=local_new_select_list_item_list((yyvsp[(1) - (1)].s_select_list_item));
	}
    break;

  case 417:

/* Line 1455 of yacc.c  */
#line 2479 "sql.yacc"
    {
			(yyval.s_select_list_item_list)=local_add_select_list_item_list((yyvsp[(1) - (3)].s_select_list_item_list),(yyvsp[(3) - (3)].s_select_list_item));
	}
    break;

  case 418:

/* Line 1455 of yacc.c  */
#line 2485 "sql.yacc"
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
#line 2494 "sql.yacc"
    { 
		add_feature("ORDER_BY_NUMBER");
		(yyval.s_select_list_item)=new_select_list_item_literal((yyvsp[(1) - (1)].str));
	}
    break;

  case 420:

/* Line 1455 of yacc.c  */
#line 2498 "sql.yacc"
    {
		(yyval.s_select_list_item)=(yyvsp[(1) - (1)].s_select_list_item);
		(yyval.s_select_list_item)->data.type=E_SLI_COLUMN_ORDERBY;
	}
    break;

  case 421:

/* Line 1455 of yacc.c  */
#line 2505 "sql.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 422:

/* Line 1455 of yacc.c  */
#line 2507 "sql.yacc"
    {add_feature("ORDER_BY_ASC"); strcpy((yyval.str),"ASC");}
    break;

  case 423:

/* Line 1455 of yacc.c  */
#line 2509 "sql.yacc"
    {add_feature("ORDER_BY_DESC"); strcpy((yyval.str),"DESC");}
    break;

  case 424:

/* Line 1455 of yacc.c  */
#line 2513 "sql.yacc"
    {
		(yyval.s_select_list_item_list)=(yyvsp[(2) - (2)].s_select_list_item_list);
	}
    break;

  case 425:

/* Line 1455 of yacc.c  */
#line 2519 "sql.yacc"
    {
			(yyval.s_select_list_item_list)=local_new_select_list_item_list((yyvsp[(1) - (1)].s_select_list_item));
	}
    break;

  case 426:

/* Line 1455 of yacc.c  */
#line 2522 "sql.yacc"
    {
			(yyval.s_select_list_item_list)=local_add_select_list_item_list((yyvsp[(1) - (3)].s_select_list_item_list),(yyvsp[(3) - (3)].s_select_list_item));
	}
    break;

  case 427:

/* Line 1455 of yacc.c  */
#line 2528 "sql.yacc"
    { (yyval.s_select_list_item)=(yyvsp[(1) - (1)].s_select_list_item); }
    break;

  case 428:

/* Line 1455 of yacc.c  */
#line 2529 "sql.yacc"
    { (yyval.s_select_list_item)=new_select_list_item_literal((yyvsp[(1) - (1)].str)); }
    break;

  case 429:

/* Line 1455 of yacc.c  */
#line 2536 "sql.yacc"
    {
	(yyval.sql_string)=get_select_list_item(0,(yyvsp[(1) - (1)].s_select_list_item));
}
    break;

  case 430:

/* Line 1455 of yacc.c  */
#line 2549 "sql.yacc"
    {
		A4GL_set_sql_lineno(yylineno);
		(yyval.sql_string)=make_select_stmt_v2(current_upd_table, (yyvsp[(1) - (1)].s_select),"");
		map_select_stmt("SELECT",(yyvsp[(1) - (1)].s_select));
		A4GL_free_select_stmt((yyvsp[(1) - (1)].s_select));
}
    break;

  case 431:

/* Line 1455 of yacc.c  */
#line 2559 "sql.yacc"
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
#line 2566 "sql.yacc"
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
#line 2583 "sql.yacc"
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
#line 2590 "sql.yacc"
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
#line 2615 "sql.yacc"
    { 
		//start_bind('i',0);
		 set_ignore_indicators();}
    break;

  case 436:

/* Line 1455 of yacc.c  */
#line 2617 "sql.yacc"
    { clr_ignore_indicators();}
    break;

  case 437:

/* Line 1455 of yacc.c  */
#line 2619 "sql.yacc"
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
#line 2640 "sql.yacc"
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
#line 2683 "sql.yacc"
    { (yyval.s_select)=0;}
    break;

  case 440:

/* Line 1455 of yacc.c  */
#line 2684 "sql.yacc"
    { 
		(yyval.s_select)=(yyvsp[(3) - (3)].s_select);
		(yyval.s_select)->union_op=acl_strdup((yyvsp[(2) - (3)].str));
		A4GL_set_associated_mem((yyval.s_select), (yyval.s_select)->union_op);
		add_feature("SELECT_UNION"); 
	}
    break;

  case 441:

/* Line 1455 of yacc.c  */
#line 2698 "sql.yacc"
    {
		(yyval.s_select_finish)=0;
	}
    break;

  case 442:

/* Line 1455 of yacc.c  */
#line 2701 "sql.yacc"
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
#line 2708 "sql.yacc"
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
#line 2718 "sql.yacc"
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
#line 2736 "sql.yacc"
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
#line 2749 "sql.yacc"
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
#line 2764 "sql.yacc"
    {(yyval.integer_val)=-1;}
    break;

  case 449:

/* Line 1455 of yacc.c  */
#line 2766 "sql.yacc"
    {
		(yyval.integer_val)=atol((yyvsp[(2) - (2)].str));
	}
    break;

  case 450:

/* Line 1455 of yacc.c  */
#line 2772 "sql.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 451:

/* Line 1455 of yacc.c  */
#line 2773 "sql.yacc"
    {strcpy((yyval.str),"ALL"); add_feature("SELECT_ALL");}
    break;

  case 452:

/* Line 1455 of yacc.c  */
#line 2774 "sql.yacc"
    {strcpy((yyval.str),"DISTINCT"); add_feature("SELECT_DISTINCT");}
    break;

  case 453:

/* Line 1455 of yacc.c  */
#line 2775 "sql.yacc"
    {strcpy((yyval.str),"DISTINCT");
		add_feature("SELECT_UNIQUE");
		ansi_violation("Use DISTINCT not UNIQUE",0);
		strcpy((yyval.str),"DISTINCT");
	}
    break;

  case 454:

/* Line 1455 of yacc.c  */
#line 2785 "sql.yacc"
    { 
		 (yyval.s_select_list_item_list)=local_new_select_list_item_list((yyvsp[(1) - (1)].s_select_list_item));
	}
    break;

  case 455:

/* Line 1455 of yacc.c  */
#line 2788 "sql.yacc"
    { 
		(yyval.s_select_list_item_list)=local_add_select_list_item_list((yyvsp[(1) - (3)].s_select_list_item_list),(yyvsp[(3) - (3)].s_select_list_item));
	}
    break;

  case 456:

/* Line 1455 of yacc.c  */
#line 2794 "sql.yacc"
    {
		(yyval.s_select_list_item)=(yyvsp[(1) - (1)].s_select_list_item);
	}
    break;

  case 457:

/* Line 1455 of yacc.c  */
#line 2797 "sql.yacc"
    {
		(yyval.s_select_list_item)=(yyvsp[(1) - (2)].s_select_list_item);
		(yyval.s_select_list_item)->alias=acl_strdup((yyvsp[(2) - (2)].str));
		A4GL_set_associated_mem((yyval.s_select_list_item), (yyval.s_select_list_item)->alias);
	}
    break;

  case 458:

/* Line 1455 of yacc.c  */
#line 2802 "sql.yacc"
    {
		(yyval.s_select_list_item)=(yyvsp[(1) - (3)].s_select_list_item);
		(yyval.s_select_list_item)->alias=acl_strdup((yyvsp[(3) - (3)].str));
		A4GL_set_associated_mem((yyval.s_select_list_item), (yyval.s_select_list_item)->alias);
	}
    break;

  case 459:

/* Line 1455 of yacc.c  */
#line 2811 "sql.yacc"
    {
		(yyval.s_select_list_item)=(yyvsp[(1) - (1)].s_select_list_item); /* A4GLSQLCV_check_expr($<sql_string>1) */
	}
    break;

  case 460:

/* Line 1455 of yacc.c  */
#line 2814 "sql.yacc"
    {
		(yyval.s_select_list_item)=(yyvsp[(2) - (2)].s_select_list_item);
		(yyval.s_select_list_item)->sign='-';
	}
    break;

  case 461:

/* Line 1455 of yacc.c  */
#line 2818 "sql.yacc"
    {
		(yyval.s_select_list_item)=(yyvsp[(2) - (2)].s_select_list_item);
	}
    break;

  case 462:

/* Line 1455 of yacc.c  */
#line 2825 "sql.yacc"
    {
			(yyval.s_select_list_item)=new_select_list_item_op_expr ((yyvsp[(1) - (3)].s_select_list_item), (yyvsp[(3) - (3)].s_select_list_item), "/");
	}
    break;

  case 463:

/* Line 1455 of yacc.c  */
#line 2828 "sql.yacc"
    {
			(yyval.s_select_list_item)=new_select_list_item_simple_expr((enum e_sli)(yyvsp[(2) - (2)].integer_val), (yyvsp[(1) - (2)].s_select_list_item));
	}
    break;

  case 464:

/* Line 1455 of yacc.c  */
#line 2831 "sql.yacc"
    {
			(yyval.s_select_list_item)=new_select_list_item_op_expr ((yyvsp[(1) - (3)].s_select_list_item), (yyvsp[(3) - (3)].s_select_list_item), "*");
	}
    break;

  case 465:

/* Line 1455 of yacc.c  */
#line 2834 "sql.yacc"
    {
			(yyval.s_select_list_item)=new_select_list_item_op_expr ((yyvsp[(1) - (3)].s_select_list_item), (yyvsp[(3) - (3)].s_select_list_item), "+");
	}
    break;

  case 466:

/* Line 1455 of yacc.c  */
#line 2837 "sql.yacc"
    {
			(yyval.s_select_list_item)=new_select_list_item_op_expr ((yyvsp[(1) - (3)].s_select_list_item), (yyvsp[(3) - (3)].s_select_list_item), "-");
	}
    break;

  case 467:

/* Line 1455 of yacc.c  */
#line 2840 "sql.yacc"
    { (yyval.s_select_list_item)=new_select_list_item_literal((yyvsp[(1) - (1)].str)); }
    break;

  case 468:

/* Line 1455 of yacc.c  */
#line 2841 "sql.yacc"
    { (yyval.s_select_list_item)=new_select_list_item_builtin_const(E_SLI_BUILTIN_CONST_TRUE); }
    break;

  case 469:

/* Line 1455 of yacc.c  */
#line 2842 "sql.yacc"
    { (yyval.s_select_list_item)=new_select_list_item_builtin_const(E_SLI_BUILTIN_CONST_FALSE); }
    break;

  case 470:

/* Line 1455 of yacc.c  */
#line 2843 "sql.yacc"
    { (yyval.s_select_list_item)=new_select_list_item_builtin_const(E_SLI_BUILTIN_CONST_USER); }
    break;

  case 471:

/* Line 1455 of yacc.c  */
#line 2844 "sql.yacc"
    { (yyval.s_select_list_item)=new_select_list_item_builtin_const(E_SLI_BUILTIN_CONST_TODAY); }
    break;

  case 472:

/* Line 1455 of yacc.c  */
#line 2845 "sql.yacc"
    { (yyval.s_select_list_item)=new_select_list_item_builtin_const(E_SLI_BUILTIN_CONST_ROWID); }
    break;

  case 473:

/* Line 1455 of yacc.c  */
#line 2846 "sql.yacc"
    { (yyval.s_select_list_item)=new_select_list_item_builtin_const(E_SLI_BUILTIN_CONST_TIME); }
    break;

  case 474:

/* Line 1455 of yacc.c  */
#line 2847 "sql.yacc"
    { (yyval.s_select_list_item)=new_select_list_item_builtin_const(E_SLI_BUILTIN_CONST_STAR); }
    break;

  case 475:

/* Line 1455 of yacc.c  */
#line 2848 "sql.yacc"
    { (yyval.s_select_list_item)=new_select_list_item_builtin_const(E_SLI_BUILTIN_CONST_COUNT_STAR); }
    break;

  case 476:

/* Line 1455 of yacc.c  */
#line 2850 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_agg1(E_SLI_BUILTIN_AGG_AVG,(yyvsp[(3) - (5)].str),(yyvsp[(4) - (5)].s_select_list_item));
		add_feature("SELECT_AVG");
	}
    break;

  case 477:

/* Line 1455 of yacc.c  */
#line 2854 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_agg1(E_SLI_BUILTIN_AGG_MAX,(yyvsp[(3) - (5)].str),(yyvsp[(4) - (5)].s_select_list_item));
		add_feature("SELECT_MAX");
	}
    break;

  case 478:

/* Line 1455 of yacc.c  */
#line 2858 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_agg1(E_SLI_BUILTIN_AGG_MIN,(yyvsp[(3) - (5)].str),(yyvsp[(4) - (5)].s_select_list_item));
		add_feature("SELECT_MIN");
	}
    break;

  case 479:

/* Line 1455 of yacc.c  */
#line 2862 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_agg1(E_SLI_BUILTIN_AGG_SUM,(yyvsp[(3) - (5)].str),(yyvsp[(4) - (5)].s_select_list_item));
		add_feature("SELECT_SUM");
	}
    break;

  case 480:

/* Line 1455 of yacc.c  */
#line 2866 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_agg1(E_SLI_BUILTIN_AGG_COUNT,(yyvsp[(3) - (5)].str),(yyvsp[(4) - (5)].s_select_list_item));
		add_feature("SELECT_COUNT");
	}
    break;

  case 481:

/* Line 1455 of yacc.c  */
#line 2870 "sql.yacc"
    {
		add_sql_function((yyvsp[(1) - (3)].str));
		(yyval.s_select_list_item)=new_select_list_item_fcall((yyvsp[(1) - (3)].str),0);
	}
    break;

  case 482:

/* Line 1455 of yacc.c  */
#line 2874 "sql.yacc"
    {
		add_sql_function((yyvsp[(1) - (4)].str));
		(yyval.s_select_list_item)=new_select_list_item_fcall((yyvsp[(1) - (4)].str),(yyvsp[(3) - (4)].s_select_list_item_list));
	}
    break;

  case 483:

/* Line 1455 of yacc.c  */
#line 2878 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_builtin_fcall(E_SLI_BUILTIN_FUNC_YEAR,(yyvsp[(3) - (4)].s_select_list_item_list));
	}
    break;

  case 484:

/* Line 1455 of yacc.c  */
#line 2881 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_builtin_fcall(E_SLI_BUILTIN_FUNC_MONTH,(yyvsp[(3) - (4)].s_select_list_item_list));
	}
    break;

  case 485:

/* Line 1455 of yacc.c  */
#line 2884 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_builtin_fcall(E_SLI_BUILTIN_FUNC_DAY,(yyvsp[(3) - (4)].s_select_list_item_list));
	}
    break;

  case 486:

/* Line 1455 of yacc.c  */
#line 2887 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_builtin_fcall(E_SLI_BUILTIN_FUNC_MDY,(yyvsp[(3) - (4)].s_select_list_item_list));
	}
    break;

  case 487:

/* Line 1455 of yacc.c  */
#line 2890 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_builtin_fcall(E_SLI_BUILTIN_FUNC_WEEKDAY,(yyvsp[(3) - (4)].s_select_list_item_list));
	}
    break;

  case 488:

/* Line 1455 of yacc.c  */
#line 2893 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_builtin_fcall(E_SLI_BUILTIN_FUNC_DOW,(yyvsp[(3) - (4)].s_select_list_item_list));
	}
    break;

  case 489:

/* Line 1455 of yacc.c  */
#line 2896 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_builtin_fcall(E_SLI_BUILTIN_FUNC_DATE,(yyvsp[(3) - (4)].s_select_list_item_list));
	}
    break;

  case 490:

/* Line 1455 of yacc.c  */
#line 2899 "sql.yacc"
    {
		  (yyval.s_select_list_item)=new_select_list_item_simple_expr(E_SLI_BRACKET_EXPR,(yyvsp[(2) - (3)].s_select_list_item));
	}
    break;

  case 491:

/* Line 1455 of yacc.c  */
#line 2902 "sql.yacc"
    { 
		add_feature("EXTEND"); 
		(yyval.s_select_list_item)=(yyvsp[(3) - (4)].s_select_list_item);
	}
    break;

  case 492:

/* Line 1455 of yacc.c  */
#line 2906 "sql.yacc"
    { 
		(yyval.s_select_list_item)=new_select_list_item_datetime((yyvsp[(1) - (1)].str));
		add_feature("FUNC_DATETIME");
	}
    break;

  case 493:

/* Line 1455 of yacc.c  */
#line 2910 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_interval((yyvsp[(1) - (1)].str));
		add_feature("FUNC_INTERVAL");
	}
    break;

  case 494:

/* Line 1455 of yacc.c  */
#line 2914 "sql.yacc"
    {
		(yyval.s_select_list_item)=(yyvsp[(2) - (3)].s_select_list_item);
	}
    break;

  case 495:

/* Line 1455 of yacc.c  */
#line 2922 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_case((yyvsp[(1) - (1)].s_select_list_item));
	}
    break;

  case 496:

/* Line 1455 of yacc.c  */
#line 2925 "sql.yacc"
    {
		(yyval.s_select_list_item)=append_select_list_item_case(
							(yyvsp[(1) - (2)].s_select_list_item),
							(yyvsp[(2) - (2)].s_select_list_item));
	}
    break;

  case 497:

/* Line 1455 of yacc.c  */
#line 2934 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_case_element(
				(yyvsp[(2) - (4)].s_select_list_item),
				(yyvsp[(4) - (4)].s_select_list_item));

	}
    break;

  case 498:

/* Line 1455 of yacc.c  */
#line 2940 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_case_element( 0, (yyvsp[(2) - (2)].s_select_list_item));
	}
    break;

  case 499:

/* Line 1455 of yacc.c  */
#line 2947 "sql.yacc"
    {
		(yyval.s_select_list_item_list)=local_new_select_list_item_list((yyvsp[(1) - (1)].s_select_list_item));
	}
    break;

  case 500:

/* Line 1455 of yacc.c  */
#line 2950 "sql.yacc"
    {
			(yyval.s_select_list_item_list)=local_add_select_list_item_list((yyvsp[(1) - (3)].s_select_list_item_list),(yyvsp[(3) - (3)].s_select_list_item));
	}
    break;

  case 501:

/* Line 1455 of yacc.c  */
#line 2978 "sql.yacc"
    {
			(yyval.s_select_list_item)=new_select_list_item_extend(new_select_list_item_builtin_const(E_SLI_BUILTIN_CONST_CURRENT),(yyvsp[(3) - (5)].str),(yyvsp[(5) - (5)].str));
	}
    break;

  case 502:

/* Line 1455 of yacc.c  */
#line 2981 "sql.yacc"
    {
			(yyval.s_select_list_item)=new_select_list_item_extend((yyvsp[(1) - (5)].s_select_list_item),(yyvsp[(3) - (5)].str),(yyvsp[(5) - (5)].str));
	}
    break;

  case 503:

/* Line 1455 of yacc.c  */
#line 2984 "sql.yacc"
    {
			(yyval.s_select_list_item)=new_select_list_item_extend(new_select_list_item_builtin_const(E_SLI_BUILTIN_CONST_CURRENT),(yyvsp[(2) - (4)].str),(yyvsp[(4) - (4)].str));
	}
    break;

  case 504:

/* Line 1455 of yacc.c  */
#line 2987 "sql.yacc"
    {
			(yyval.s_select_list_item)=new_select_list_item_extend((yyvsp[(1) - (5)].s_select_list_item),(yyvsp[(3) - (5)].str),(yyvsp[(5) - (5)].str));
	}
    break;

  case 505:

/* Line 1455 of yacc.c  */
#line 2993 "sql.yacc"
    {(yyval.integer_val)=E_SLI_UNITS_YEAR;}
    break;

  case 506:

/* Line 1455 of yacc.c  */
#line 2994 "sql.yacc"
    {(yyval.integer_val)=E_SLI_UNITS_MONTH;}
    break;

  case 507:

/* Line 1455 of yacc.c  */
#line 2995 "sql.yacc"
    {(yyval.integer_val)=E_SLI_UNITS_DAY;}
    break;

  case 508:

/* Line 1455 of yacc.c  */
#line 2996 "sql.yacc"
    {(yyval.integer_val)=E_SLI_UNITS_HOUR;}
    break;

  case 509:

/* Line 1455 of yacc.c  */
#line 2997 "sql.yacc"
    {(yyval.integer_val)=E_SLI_UNITS_MINUTE;}
    break;

  case 510:

/* Line 1455 of yacc.c  */
#line 2998 "sql.yacc"
    {(yyval.integer_val)=E_SLI_UNITS_SECOND;}
    break;

  case 511:

/* Line 1455 of yacc.c  */
#line 3003 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_op_slil((yyvsp[(1) - (5)].s_select_list_item),(yyvsp[(4) - (5)].s_select_list_item_list),E_SLI_IN_VALUES);
                add_feature("WHERE_IN");
        }
    break;

  case 512:

/* Line 1455 of yacc.c  */
#line 3007 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_op_sli((yyvsp[(1) - (3)].s_select_list_item),(yyvsp[(3) - (3)].s_select_list_item),E_SLI_IN_SELECT);
                add_feature("WHERE_IN_SELECT");
        }
    break;

  case 513:

/* Line 1455 of yacc.c  */
#line 3011 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_op_slil((yyvsp[(1) - (5)].s_select_list_item),(yyvsp[(4) - (5)].s_select_list_item_list),E_SLI_NOT_IN_VALUES);
                add_feature("WHERE_IN");
        }
    break;

  case 514:

/* Line 1455 of yacc.c  */
#line 3015 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_op_sli((yyvsp[(1) - (3)].s_select_list_item),(yyvsp[(3) - (3)].s_select_list_item),E_SLI_NOT_IN_SELECT);
                add_feature("WHERE_IN_SELECT");
        }
    break;

  case 515:

/* Line 1455 of yacc.c  */
#line 3022 "sql.yacc"
    {
		(yyval.s_select_list_item_list)=local_new_select_list_item_list((yyvsp[(1) - (1)].s_select_list_item));
	}
    break;

  case 516:

/* Line 1455 of yacc.c  */
#line 3025 "sql.yacc"
    {
                (yyval.s_select_list_item_list)=local_add_select_list_item_list((yyvsp[(1) - (3)].s_select_list_item_list),(yyvsp[(3) - (3)].s_select_list_item));
	}
    break;

  case 517:

/* Line 1455 of yacc.c  */
#line 3030 "sql.yacc"
    { (yyval.s_select_list_item)=(yyvsp[(1) - (1)].s_select_list_item);}
    break;

  case 518:

/* Line 1455 of yacc.c  */
#line 3031 "sql.yacc"
    { (yyval.s_select_list_item)=new_select_list_item_literal((yyvsp[(1) - (1)].str)); }
    break;

  case 519:

/* Line 1455 of yacc.c  */
#line 3032 "sql.yacc"
    { 
		char buff[256]; SPRINTF1(buff," -%s",(yyvsp[(2) - (2)].str)); (yyval.s_select_list_item)=new_select_list_item_literal(buff); }
    break;

  case 520:

/* Line 1455 of yacc.c  */
#line 3034 "sql.yacc"
    { char buff[256]; SPRINTF1(buff," -%s",(yyvsp[(2) - (2)].str)); (yyval.s_select_list_item)=new_select_list_item_literal(buff); }
    break;

  case 521:

/* Line 1455 of yacc.c  */
#line 3040 "sql.yacc"
    {
                if (strstr((yyvsp[(1) - (1)].str),"systables")!=0) { add_feature("IFX_SYSTABLES"); }
                if (strstr((yyvsp[(1) - (1)].str),"syscolumns")!=0) { add_feature("IFX_SYSCOLUMNS"); }
                if (strstr((yyvsp[(1) - (1)].str),"sysindexes")!=0) { add_feature("IFX_SYSINDEXES"); }
                strcpy((yyval.str),A4GLSQLCV_check_tablename((yyvsp[(1) - (1)].str)));
                }
    break;

  case 522:

/* Line 1455 of yacc.c  */
#line 3050 "sql.yacc"
    {
	     SPRINTF1((yyval.str),"%s", A4GLSQLCV_ownerize_tablename(NULL, A4GL_strip_quotes((yyvsp[(1) - (1)].str))));
             ADDMAP("Use Table",(yyval.str));
        }
    break;

  case 523:

/* Line 1455 of yacc.c  */
#line 3054 "sql.yacc"
    {
	     SPRINTF1((yyval.str),"%s", A4GLSQLCV_ownerize_tablename((yyvsp[(1) - (3)].str), (yyvsp[(3) - (3)].str)));
	     ADDMAP("Use Table",(yyval.str));
        }
    break;

  case 524:

/* Line 1455 of yacc.c  */
#line 3058 "sql.yacc"
    {
	     SPRINTF1((yyval.str),"%s", A4GLSQLCV_ownerize_tablename(NULL, (yyvsp[(1) - (1)].str)));
	     ADDMAP("Use Table",(yyval.str));
	}
    break;

  case 525:

/* Line 1455 of yacc.c  */
#line 3062 "sql.yacc"
    {
	     SPRINTF1((yyval.str),"%s", A4GLSQLCV_db_tablename((yyvsp[(1) - (3)].str), NULL, A4GLSQLCV_ownerize_tablename(NULL, (yyvsp[(3) - (3)].str))));
	     ADDMAP("Use Table",(yyval.str));
	}
    break;

  case 526:

/* Line 1455 of yacc.c  */
#line 3066 "sql.yacc"
    {
	     SPRINTF1((yyval.str),"%s", A4GLSQLCV_db_tablename((yyvsp[(1) - (5)].str), NULL, A4GLSQLCV_ownerize_tablename((yyvsp[(3) - (5)].str),(yyvsp[(5) - (5)].str))));
	     ADDMAP("Use Table",(yyval.str));
        }
    break;

  case 527:

/* Line 1455 of yacc.c  */
#line 3070 "sql.yacc"
    {
	     SPRINTF1((yyval.str),"%s", A4GLSQLCV_db_tablename(NULL,(yyvsp[(1) - (3)].str), A4GLSQLCV_ownerize_tablename(NULL, (yyvsp[(3) - (3)].str))));
	     ADDMAP("Use Table",(yyval.str));
	}
    break;

  case 528:

/* Line 1455 of yacc.c  */
#line 3074 "sql.yacc"
    {
	     SPRINTF1((yyval.str),"%s", A4GLSQLCV_db_tablename((yyvsp[(1) - (5)].str), (yyvsp[(3) - (5)].str), A4GLSQLCV_ownerize_tablename(NULL, (yyvsp[(5) - (5)].str))));
	     ADDMAP("Use Table",(yyval.str));
	}
    break;

  case 529:

/* Line 1455 of yacc.c  */
#line 3078 "sql.yacc"
    {
	     SPRINTF1((yyval.str),"%s", A4GLSQLCV_db_tablename((yyvsp[(1) - (7)].str), (yyvsp[(3) - (7)].str), A4GLSQLCV_ownerize_tablename((yyvsp[(5) - (7)].str), (yyvsp[(7) - (7)].str))));
	     ADDMAP("Use Table",(yyval.str));
        }
    break;

  case 530:

/* Line 1455 of yacc.c  */
#line 3086 "sql.yacc"
    {
                if (strstr((yyvsp[(1) - (1)].str),"systables")!=0) { add_feature("IFX_SYSTABLES"); }
                if (strstr((yyvsp[(1) - (1)].str),"syscolumns")!=0) { add_feature("IFX_SYSCOLUMNS"); }
                if (strstr((yyvsp[(1) - (1)].str),"sysindexes")!=0) { add_feature("IFX_SYSINDEXES"); }
                strcpy((yyval.str),A4GLSQLCV_check_tablename((yyvsp[(1) - (1)].str)));
                }
    break;

  case 531:

/* Line 1455 of yacc.c  */
#line 3096 "sql.yacc"
    {

	     SPRINTF1((yyval.str),"%s", A4GLSQLCV_ownerize_tablename((yyvsp[(1) - (3)].str), (yyvsp[(3) - (3)].str)));
	     ADDMAP("Use Table",(yyval.str));
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
#line 3105 "sql.yacc"
    {
	     SPRINTF1((yyval.str),"%s", A4GLSQLCV_ownerize_tablename(NULL, A4GL_strip_quotes((yyvsp[(1) - (1)].str))));
	     ADDMAP("Use Table",(yyval.str));
        }
    break;

  case 534:

/* Line 1455 of yacc.c  */
#line 3109 "sql.yacc"
    {
             SPRINTF1((yyval.str),"%s", A4GLSQLCV_ownerize_tablename(NULL, (yyvsp[(1) - (1)].str)));
	     ADDMAP("Use Table",(yyval.str));
	}
    break;

  case 535:

/* Line 1455 of yacc.c  */
#line 3113 "sql.yacc"
    {
             SPRINTF1((yyval.str),"%s", A4GLSQLCV_db_tablename((yyvsp[(1) - (3)].str),NULL, A4GLSQLCV_ownerize_tablename(NULL, (yyvsp[(3) - (3)].str))));
	     ADDMAP("Use Table",(yyval.str));
	}
    break;

  case 536:

/* Line 1455 of yacc.c  */
#line 3117 "sql.yacc"
    {
	     SPRINTF1((yyval.str),"%s", A4GLSQLCV_db_tablename((yyvsp[(1) - (5)].str), NULL,A4GLSQLCV_ownerize_tablename((yyvsp[(3) - (5)].str), (yyvsp[(5) - (5)].str))));
	     ADDMAP("Use Table",(yyval.str));
        }
    break;

  case 537:

/* Line 1455 of yacc.c  */
#line 3122 "sql.yacc"
    {
             SPRINTF1((yyval.str),"%s", A4GLSQLCV_db_tablename(NULL, (yyvsp[(1) - (3)].str), A4GLSQLCV_ownerize_tablename(NULL, (yyvsp[(3) - (3)].str))));
	     ADDMAP("Use Table",(yyval.str));
	}
    break;

  case 538:

/* Line 1455 of yacc.c  */
#line 3126 "sql.yacc"
    {
            SPRINTF1((yyval.str),"%s", A4GLSQLCV_db_tablename( (yyvsp[(1) - (5)].str), (yyvsp[(3) - (5)].str), A4GLSQLCV_ownerize_tablename(NULL, (yyvsp[(5) - (5)].str))));
	    ADDMAP("Use Table",(yyval.str));
	}
    break;

  case 539:

/* Line 1455 of yacc.c  */
#line 3130 "sql.yacc"
    {
	     SPRINTF1((yyval.str),"%s", A4GLSQLCV_db_tablename((yyvsp[(1) - (7)].str), (yyvsp[(3) - (7)].str), A4GLSQLCV_ownerize_tablename((yyvsp[(5) - (7)].str), (yyvsp[(7) - (7)].str))));
	     ADDMAP("Use Table",(yyval.str));
        }
    break;

  case 540:

/* Line 1455 of yacc.c  */
#line 3138 "sql.yacc"
    {
	     SPRINTF1((yyval.str),"%s", A4GLSQLCV_ownerize_tablename((yyvsp[(1) - (3)].str), (yyvsp[(3) - (3)].str)));
        }
    break;

  case 541:

/* Line 1455 of yacc.c  */
#line 3141 "sql.yacc"
    {
	        SPRINTF1((yyval.str),"%s", A4GLSQLCV_ownerize_tablename(NULL, (yyvsp[(1) - (1)].str)));
                ADDMAP("Use Index",(yyval.str));
        }
    break;

  case 542:

/* Line 1455 of yacc.c  */
#line 3146 "sql.yacc"
    {strcpy((yyval.str),(yyvsp[(1) - (1)].str)); ADDMAP("Use Index",(yyvsp[(1) - (1)].str)); }
    break;

  case 543:

/* Line 1455 of yacc.c  */
#line 3147 "sql.yacc"
    { SPRINTF3((yyval.str),"%s%s%s",(yyvsp[(1) - (3)].str),(yyvsp[(2) - (3)].str),(yyvsp[(3) - (3)].str)); ADDMAP("Use Index",(yyval.str)); }
    break;

  case 544:

/* Line 1455 of yacc.c  */
#line 3148 "sql.yacc"
    {
	     SPRINTF2((yyval.str),"%s:%s", (yyvsp[(1) - (5)].str), A4GLSQLCV_ownerize_tablename((yyvsp[(3) - (5)].str), (yyvsp[(5) - (5)].str)));
             ADDMAP("Use Index",(yyval.str));
        }
    break;

  case 545:

/* Line 1455 of yacc.c  */
#line 3153 "sql.yacc"
    {strcpy((yyval.str),(yyvsp[(1) - (3)].str)); ADDMAP("Use Index",(yyvsp[(1) - (3)].str)); }
    break;

  case 546:

/* Line 1455 of yacc.c  */
#line 3154 "sql.yacc"
    { SPRINTF4((yyval.str),"%s@%s%s%s",(yyvsp[(1) - (5)].str),(yyvsp[(3) - (5)].str),(yyvsp[(4) - (5)].str),(yyvsp[(5) - (5)].str)); ADDMAP("Use Index",(yyval.str)); }
    break;

  case 547:

/* Line 1455 of yacc.c  */
#line 3155 "sql.yacc"
    {
	     SPRINTF3((yyval.str),"%s@%s:%s", (yyvsp[(1) - (7)].str), (yyvsp[(3) - (7)].str), A4GLSQLCV_ownerize_tablename((yyvsp[(5) - (7)].str), (yyvsp[(7) - (7)].str)));
             ADDMAP("Use Index",(yyval.str));
        }
    break;

  case 549:

/* Line 1455 of yacc.c  */
#line 3166 "sql.yacc"
    {
                      (yyval.ptr)=A4GL_new_expr_simple_string(A4GL_get_clobbered_from((yyval.str)), ET_EXPR_IDENTIFIER);
	}
    break;

  case 551:

/* Line 1455 of yacc.c  */
#line 3172 "sql.yacc"
    { sprintf((yyval.str),".%s",(yyvsp[(2) - (2)].str)); }
    break;

  case 553:

/* Line 1455 of yacc.c  */
#line 3177 "sql.yacc"
    {strcpy((yyval.str), A4GL_strip_quotes ((yyvsp[(1) - (1)].str)));}
    break;

  case 558:

/* Line 1455 of yacc.c  */
#line 3228 "sql.yacc"
    {
			int converted;
			(yyval.sql_string)=get_insert_cmd((yyvsp[(1) - (1)].insert_cmd),&converted);
			A4GL_free_associated_mem((yyvsp[(1) - (1)].insert_cmd));
			acl_free((yyvsp[(1) - (1)].insert_cmd));

		}
    break;

  case 559:

/* Line 1455 of yacc.c  */
#line 3235 "sql.yacc"
    {
			int converted;
			(yyval.sql_string)=get_update_cmd((yyvsp[(1) - (1)].update_cmd),&converted);
			A4GL_free_associated_mem((yyvsp[(1) - (1)].update_cmd));
			acl_free((yyvsp[(1) - (1)].update_cmd));
		}
    break;

  case 560:

/* Line 1455 of yacc.c  */
#line 3241 "sql.yacc"
    {
			int converted;
			(yyval.sql_string)=get_delete_cmd((yyvsp[(1) - (1)].delete_cmd),&converted);
			A4GL_free_associated_mem((yyvsp[(1) - (1)].delete_cmd));
			acl_free((yyvsp[(1) - (1)].delete_cmd));
		}
    break;

  case 563:

/* Line 1455 of yacc.c  */
#line 3256 "sql.yacc"
    { print_exec_select((yyvsp[(1) - (1)].sql_string));  }
    break;

  case 564:

/* Line 1455 of yacc.c  */
#line 3257 "sql.yacc"
    { print_exec_select((yyvsp[(1) - (1)].sql_string));  }
    break;

  case 566:

/* Line 1455 of yacc.c  */
#line 3259 "sql.yacc"
    { print_exec_select((yyvsp[(1) - (1)].sql_string));  }
    break;

  case 567:

/* Line 1455 of yacc.c  */
#line 3261 "sql.yacc"
    {
			print_sql_commit ((yyvsp[(1) - (1)].integer_val));
	}
    break;

  case 568:

/* Line 1455 of yacc.c  */
#line 3264 "sql.yacc"
    {print_unable_to_parse();}
    break;

  case 569:

/* Line 1455 of yacc.c  */
#line 3268 "sql.yacc"
    { (yyval.sql_string)=make_sql_string_and_free((yyvsp[(1) - (2)].sql_string),acl_strdup((yyvsp[(2) - (2)].str)),0);
}
    break;

  case 571:

/* Line 1455 of yacc.c  */
#line 3277 "sql.yacc"
    {
			(yyval.sql_string)=make_select_stmt_v2("", (yyvsp[(1) - (1)].s_select),"");
			A4GL_free_select_stmt((yyvsp[(1) - (1)].s_select));
		}
    break;

  case 572:

/* Line 1455 of yacc.c  */
#line 3283 "sql.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 573:

/* Line 1455 of yacc.c  */
#line 3284 "sql.yacc"
    {
			strcpy((yyval.str),A4GLSQLCV_get_forupdate(NULL));
		}
    break;

  case 574:

/* Line 1455 of yacc.c  */
#line 3287 "sql.yacc"
    {
			strcpy((yyval.str),A4GLSQLCV_get_forupdate((yyvsp[(2) - (2)].str)));
		}
    break;

  case 575:

/* Line 1455 of yacc.c  */
#line 3292 "sql.yacc"
    { strcpy((yyval.str),(yyvsp[(1) - (1)].str)); }
    break;

  case 576:

/* Line 1455 of yacc.c  */
#line 3293 "sql.yacc"
    { sprintf((yyval.str),"%s,%s",(yyvsp[(1) - (3)].str),(yyvsp[(3) - (3)].str)); }
    break;

  case 578:

/* Line 1455 of yacc.c  */
#line 3297 "sql.yacc"
    {sprintf((yyval.str),"%s.%s",A4GLSQLCV_ownerize_tablename(NULL, (yyvsp[(1) - (3)].str)),(yyvsp[(3) - (3)].str));}
    break;

  case 579:

/* Line 1455 of yacc.c  */
#line 3298 "sql.yacc"
    {
        sprintf((yyval.str),"%s.%s", A4GLSQLCV_ownerize_tablename((yyvsp[(1) - (5)].str), (yyvsp[(3) - (5)].str)), (yyvsp[(5) - (5)].str));
}
    break;

  case 580:

/* Line 1455 of yacc.c  */
#line 3308 "sql.yacc"
    { print_exec_sql(acl_strdup((yyvsp[(1) - (1)].str))); }
    break;

  case 581:

/* Line 1455 of yacc.c  */
#line 3309 "sql.yacc"
    { print_exec_sql(acl_strdup((yyvsp[(1) - (1)].str))); }
    break;

  case 582:

/* Line 1455 of yacc.c  */
#line 3310 "sql.yacc"
    { sprintf((yyval.str),"%s %s",(yyvsp[(1) - (2)].str),(yyvsp[(2) - (2)].str)); print_exec_sql(acl_strdup((yyval.str))); }
    break;

  case 583:

/* Line 1455 of yacc.c  */
#line 3311 "sql.yacc"
    { print_exec_sql(acl_strdup((yyvsp[(1) - (1)].str))); }
    break;

  case 584:

/* Line 1455 of yacc.c  */
#line 3312 "sql.yacc"
    { print_exec_sql(acl_strdup((yyvsp[(1) - (1)].str))); }
    break;

  case 585:

/* Line 1455 of yacc.c  */
#line 3313 "sql.yacc"
    { print_exec_sql(acl_strdup((yyvsp[(1) - (1)].str))); }
    break;

  case 586:

/* Line 1455 of yacc.c  */
#line 3314 "sql.yacc"
    { print_exec_sql(acl_strdup((yyvsp[(1) - (1)].str))); }
    break;

  case 587:

/* Line 1455 of yacc.c  */
#line 3315 "sql.yacc"
    { print_exec_sql(acl_strdup((yyvsp[(1) - (1)].str))); }
    break;

  case 588:

/* Line 1455 of yacc.c  */
#line 3319 "sql.yacc"
    { 
	char *s;
	s=acl_strdup((yyvsp[(1) - (1)].str));
	(yyval.s_select_list_item)=new_select_list_item_column_from_transform(s);
	acl_free(s);
	}
    break;

  case 589:

/* Line 1455 of yacc.c  */
#line 3325 "sql.yacc"
    {  
		(yyval.s_select_list_item)=new_select_list_item_builtin_const(E_SLI_QUERY_PLACEHOLDER);}
    break;

  case 590:

/* Line 1455 of yacc.c  */
#line 3327 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_replace_var((yyvsp[(1) - (1)].sql_string));
	}
    break;

  case 591:

/* Line 1455 of yacc.c  */
#line 3346 "sql.yacc"
    {
        add_feature("DATABASE_USED");
       conn_db((yyvsp[(2) - (3)].str));
}
    break;

  case 592:

/* Line 1455 of yacc.c  */
#line 3354 "sql.yacc"
    {
		(yyval.sql_string)=acl_strdup((yyvsp[(2) - (3)].str));
}
    break;

  case 593:

/* Line 1455 of yacc.c  */
#line 3361 "sql.yacc"
    {sprintf((yyval.str),"(%s)",(yyvsp[(2) - (3)].str));}
    break;

  case 594:

/* Line 1455 of yacc.c  */
#line 3362 "sql.yacc"
    { sprintf((yyval.str),"%s%s%s",(yyvsp[(1) - (3)].str),(yyvsp[(2) - (3)].str),(yyvsp[(3) - (3)].str));}
    break;

  case 595:

/* Line 1455 of yacc.c  */
#line 3363 "sql.yacc"
    {sprintf((yyval.str),"%d",atoi((yyvsp[(1) - (1)].str)));}
    break;

  case 596:

/* Line 1455 of yacc.c  */
#line 3364 "sql.yacc"
    {sprintf((yyval.str),"(%s%s)",(yyvsp[(1) - (2)].str),(yyvsp[(2) - (2)].str));}
    break;

  case 597:

/* Line 1455 of yacc.c  */
#line 3369 "sql.yacc"
    {strcpy((yyval.str),"+");}
    break;

  case 598:

/* Line 1455 of yacc.c  */
#line 3370 "sql.yacc"
    {strcpy((yyval.str),"-");}
    break;

  case 599:

/* Line 1455 of yacc.c  */
#line 3371 "sql.yacc"
    {strcpy((yyval.str),"*");}
    break;

  case 600:

/* Line 1455 of yacc.c  */
#line 3372 "sql.yacc"
    {strcpy((yyval.str),"/");}
    break;

  case 601:

/* Line 1455 of yacc.c  */
#line 3373 "sql.yacc"
    {strcpy((yyval.str),"%");}
    break;

  case 602:

/* Line 1455 of yacc.c  */
#line 3378 "sql.yacc"
    {strcpy((yyval.str),"+");}
    break;

  case 603:

/* Line 1455 of yacc.c  */
#line 3379 "sql.yacc"
    {strcpy((yyval.str),"-");}
    break;

  case 604:

/* Line 1455 of yacc.c  */
#line 3395 "sql.yacc"
    {sprintf((yyval.str),"%s", A4GLSQLCV_check_tablename((yyvsp[(1) - (1)].str)));}
    break;

  case 605:

/* Line 1455 of yacc.c  */
#line 3396 "sql.yacc"
    {sprintf((yyval.str),"%s.*", A4GLSQLCV_ownerize_tablename(NULL,(yyvsp[(1) - (3)].str)));}
    break;

  case 606:

/* Line 1455 of yacc.c  */
#line 3397 "sql.yacc"
    {sprintf((yyval.str),"%s.%s", (yyvsp[(1) - (3)].str),A4GLSQLCV_get_sqlconst ("rowid"));}
    break;

  case 607:

/* Line 1455 of yacc.c  */
#line 3398 "sql.yacc"
    {sprintf((yyval.str),"%s.%s", A4GLSQLCV_ownerize_tablename(NULL,(yyvsp[(1) - (3)].str)),(yyvsp[(3) - (3)].str));}
    break;

  case 608:

/* Line 1455 of yacc.c  */
#line 3399 "sql.yacc"
    {sprintf((yyval.str),"%s.%s", A4GLSQLCV_ownerize_tablename((yyvsp[(1) - (5)].str),(yyvsp[(3) - (5)].str)),(yyvsp[(5) - (5)].str));}
    break;

  case 609:

/* Line 1455 of yacc.c  */
#line 3400 "sql.yacc"
    {sprintf((yyval.str),"%s.%s", A4GLSQLCV_ownerize_tablename((yyvsp[(1) - (5)].str),(yyvsp[(3) - (5)].str)),(yyvsp[(5) - (5)].str));}
    break;

  case 610:

/* Line 1455 of yacc.c  */
#line 3401 "sql.yacc"
    {sprintf((yyval.str),"%s", (yyvsp[(1) - (4)].str)); strcpy((yyval.str), A4GLSQLCV_make_substr_s((yyvsp[(1) - (4)].str), 1,(yyvsp[(3) - (4)].str),0));}
    break;

  case 611:

/* Line 1455 of yacc.c  */
#line 3402 "sql.yacc"
    {char buff[256]; sprintf(buff,"%s.%s", A4GLSQLCV_ownerize_tablename(NULL,(yyvsp[(1) - (6)].str)),(yyvsp[(3) - (6)].str)); strcpy((yyval.str), A4GLSQLCV_make_substr_s(buff,1,(yyvsp[(5) - (6)].str),0));}
    break;

  case 612:

/* Line 1455 of yacc.c  */
#line 3403 "sql.yacc"
    {char buff[256]; sprintf(buff,"%s.%s", A4GLSQLCV_ownerize_tablename((yyvsp[(1) - (8)].str),(yyvsp[(3) - (8)].str)), (yyvsp[(5) - (8)].str)); strcpy((yyval.str), A4GLSQLCV_make_substr_s(buff,1,(yyvsp[(7) - (8)].str),0));  }
    break;

  case 613:

/* Line 1455 of yacc.c  */
#line 3404 "sql.yacc"
    {char buff[256]; sprintf(buff,"%s.%s", A4GLSQLCV_ownerize_tablename((yyvsp[(1) - (8)].str),(yyvsp[(3) - (8)].str)), (yyvsp[(5) - (8)].str));  strcpy((yyval.str), A4GLSQLCV_make_substr_s(buff,1,(yyvsp[(7) - (8)].str),0)); }
    break;

  case 614:

/* Line 1455 of yacc.c  */
#line 3406 "sql.yacc"
    {sprintf((yyval.str),"%s", (yyvsp[(1) - (6)].str)); strcpy((yyval.str), A4GLSQLCV_make_substr_s((yyvsp[(1) - (6)].str), 2,(yyvsp[(3) - (6)].str),(yyvsp[(5) - (6)].str)));}
    break;

  case 615:

/* Line 1455 of yacc.c  */
#line 3407 "sql.yacc"
    {char buff[256]; sprintf(buff,"%s.%s", A4GLSQLCV_ownerize_tablename(NULL,(yyvsp[(1) - (8)].str)),(yyvsp[(3) - (8)].str)); strcpy((yyval.str), A4GLSQLCV_make_substr_s(buff,2,(yyvsp[(5) - (8)].str),(yyvsp[(7) - (8)].str)));}
    break;

  case 616:

/* Line 1455 of yacc.c  */
#line 3408 "sql.yacc"
    {char buff[256]; sprintf(buff,"%s.%s", A4GLSQLCV_ownerize_tablename((yyvsp[(1) - (10)].str),(yyvsp[(3) - (10)].str)), (yyvsp[(5) - (10)].str)); strcpy((yyval.str), A4GLSQLCV_make_substr_s(buff,2,(yyvsp[(7) - (10)].str),(yyvsp[(9) - (10)].str)));  }
    break;

  case 617:

/* Line 1455 of yacc.c  */
#line 3409 "sql.yacc"
    {char buff[256]; sprintf(buff,"%s.%s", A4GLSQLCV_ownerize_tablename((yyvsp[(1) - (10)].str),(yyvsp[(3) - (10)].str)), (yyvsp[(5) - (10)].str));  strcpy((yyval.str), A4GLSQLCV_make_substr_s(buff,2,(yyvsp[(7) - (10)].str),(yyvsp[(9) - (10)].str))); }
    break;

  case 618:

/* Line 1455 of yacc.c  */
#line 3414 "sql.yacc"
    {
                (yyval.s_select_list_item)=(yyvsp[(1) - (1)].s_select_list_item);
        }
    break;

  case 619:

/* Line 1455 of yacc.c  */
#line 3417 "sql.yacc"
    {
                (yyval.s_select_list_item)=new_select_list_item_cast((yyvsp[(1) - (3)].s_select_list_item), (yyvsp[(3) - (3)].str));
        }
    break;

  case 620:

/* Line 1455 of yacc.c  */
#line 3426 "sql.yacc"
    { (yyvsp[(1) - (1)].s_select_list_item)=(yyvsp[(1) - (1)].s_select_list_item); }
    break;

  case 621:

/* Line 1455 of yacc.c  */
#line 3427 "sql.yacc"
    {(yyvsp[(1) - (1)].s_select_list_item)=(yyvsp[(1) - (1)].s_select_list_item);}
    break;

  case 622:

/* Line 1455 of yacc.c  */
#line 3428 "sql.yacc"
    {  (yyval.s_select_list_item)=new_select_list_item_sq(E_SQE_DONT_CARE,(yyvsp[(1) - (1)].s_select_list_item)); }
    break;

  case 623:

/* Line 1455 of yacc.c  */
#line 3429 "sql.yacc"
    { (yyval.s_select_list_item)=new_select_list_item_sq(E_SQE_ALL,(yyvsp[(2) - (2)].s_select_list_item)); }
    break;

  case 624:

/* Line 1455 of yacc.c  */
#line 3430 "sql.yacc"
    { (yyval.s_select_list_item)=new_select_list_item_sq(E_SQE_ANY,(yyvsp[(2) - (2)].s_select_list_item)); }
    break;

  case 625:

/* Line 1455 of yacc.c  */
#line 3431 "sql.yacc"
    { (yyval.s_select_list_item)=new_select_list_item_sq(E_SQE_SOME,(yyvsp[(2) - (2)].s_select_list_item)); }
    break;

  case 626:

/* Line 1455 of yacc.c  */
#line 3435 "sql.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 627:

/* Line 1455 of yacc.c  */
#line 3436 "sql.yacc"
    {strcpy((yyval.str),(yyvsp[(1) - (1)].str));}
    break;



/* Line 1455 of yacc.c  */
#line 8853 "y.tab.c"
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
#line 3442 "sql.yacc"


#if LEX_YY_PREGEN
#include "../../tools/no_yacc/cygwin/compilers/sql/lex.sqlparse_yy.c"
#else
#include "lex.yy.c"
#endif
#include "util.c"
#include "cmds.c"

