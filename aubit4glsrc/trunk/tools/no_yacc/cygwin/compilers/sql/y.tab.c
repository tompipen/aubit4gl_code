
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
     INT_VALUE = 2238,
     NAMED = 2239,
     NAMED_GEN = 2240,
     CHAR_VALUE = 2241,
     NOT_USED_1 = 2242,
     NOT_USED_2 = 2243,
     NOT_USED_3 = 2244,
     NOT_USED_4 = 2245,
     NOT_USED_5 = 2246,
     NOT_USED_6 = 2247,
     NOT_USED_7 = 2248,
     NOT_USED_8 = 2249,
     NUMBER_VALUE = 2250,
     SEMICOLON = 2251,
     QUESTION_MARK = 2252,
     CLINE = 2253,
     CH = 2254,
     MARK_VAR = 2255,
     END_MARK_VAR = 2256,
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
     EXIT_TODO = 1353,
     CONTINUE_TODO = 1354,
     UNLOCK_TABLE = 1361,
     ROLLBACK_W = 1369,
     SQLSEON = 1371,
     SQLSEOFF = 1372,
     CREATE_VIEW = 1376,
     DELETE_FROM = 1377,
     EXTENT_SIZE = 1384,
     FOREIGN_KEY = 1385,
     INSERT_INTO = 1388,
     IS_NOT_NULL = 1390,
     NOT_MATCHES = 1393,
     PRIMARY_KEY = 1399,
     WITH_NO_LOG = 1406,
     INSHARE = 1409,
     BEGIN_WORK = 1415,
     DROP_INDEX = 1420,
     FOR_UPDATE_OF = 1426,
     FOR_UPDATE = 1427,
     LOCK_TABLE = 1432,
     NOT_EXISTS = 1434,
     REFERENCES = 1436,
     RENCOL = 1437,
     SMALLFLOAT = 1439,
     COMMIT_W = 1450,
     RENTAB = 1457,
     KW_CHAR = 1460,
     NCHAR = 1461,
     NVARCHAR = 1462,
     DELIMITER = 1464,
     DROP_VIEW = 1466,
     EXCLUSIVE = 1469,
     GREATER_THAN_EQ = 1473,
     INTO_TEMP = 1475,
     DATABASE = 1499,
     DATETIME = 1500,
     DISTINCT = 1502,
     FRACTION = 1509,
     GROUP_BY = 1511,
     INTERVAL = 1512,
     NOT_LIKE = 1514,
     NOT_ILIKE = 1515,
     NOT_NULL = 1516,
     RESOURCE = 1522,
     SMALLINT = 1523,
     IS_NULL = 1529,
     LESS_THAN_EQ = 1530,
     BETWEEN = 1532,
     CLOSE_BRACKET = 1535,
     CONNECT = 1538,
     KW_CURRENT = 1539,
     KW_DECIMAL = 1541,
     DEFAULT = 1543,
     INTEGER = 1551,
     SERIAL8 = 1553,
     MATCHES = 1556,
     VARCHAR = 1569,
     CLOSE_SQUARE = 1572,
     GREATER_THAN = 1573,
     KW_FALSE = 1574,
     NOT_IN = 1575,
     OPEN_BRACKET = 1577,
     KW_DELETE = 1585,
     KW_ESCAPE = 1588,
     EXISTS = 1589,
     EXTEND = 1590,
     HAVING = 1594,
     KW_INSERT = 1596,
     MINUTE = 1600,
     MODIFY = 1601,
     EQUAL = 1603,
     NOT_EQUAL = 1604,
     OPEN_SQUARE = 1606,
     PUBLIC = 1610,
     KW_RETURN_KEY = 1613,
     REVOKE = 1615,
     SECOND = 1619,
     KW_SELECT = 1623,
     SERIAL = 1624,
     UNIQUE = 1627,
     KW_UPDATE = 1629,
     VALUES = 1630,
     KW_NULL = 1633,
     KW_TRUE = 1634,
     ALTER = 1636,
     CHECK = 1642,
     COUNT = 1646,
     KW_FIRST = 1651,
     KW_FLOAT = 1652,
     GRANT = 1655,
     INDEX = 1658,
     LESS_THAN = 1661,
     MONEY = 1663,
     MONTH = 1664,
     KW_MULTIPLY = 1666,
     ORDER = 1667,
     OUTER = 1668,
     UNION = 1677,
     WHERE = 1680,
     KW_BYTE = 1687,
     CASE = 1689,
     KW_DATE = 1691,
     DESC = 1692,
     KW_DIVIDE = 1693,
     DROP = 1696,
     ELSE = 1697,
     FROM = 1701,
     HOUR = 1707,
     INTO = 1708,
     LIKE = 1711,
     REAL = 1720,
     SOME = 1725,
     KW_TEXT = 1729,
     KW_THEN = 1730,
     USER = 1731,
     WHEN = 1733,
     YEAR = 1736,
     KW_DOW = 1737,
     XSET = 1739,
     ADD = 1740,
     ALL = 1741,
     KW_AND = 1742,
     ANY = 1743,
     ASC = 1744,
     AVG = 1745,
     COLON = 1746,
     KW_COMMA = 1747,
     DAY = 1748,
     DBA = 1749,
     KW_FOR = 1753,
     XMAX = 1758,
     XMIN = 1759,
     KW_MINUS = 1760,
     KW_MOD = 1761,
     KW_NOT = 1762,
     KW_SUM = 1769,
     ATSIGN = 1772,
     KW_PLUS = 1773,
     KW_AS = 1779,
     KW_BY = 1781,
     KW_DOT = 1782,
     KW_IN = 1785,
     KW_ON = 1787,
     KW_OR = 1788,
     KW_TO = 1789,
     BEFORE = 1827,
     END = 1831,
     TILDE = 1838,
     ILIKE = 1839,
     FILLFACTOR = 1842,
     TIME = 1847,
     KW_TODAY = 1854,
     KW_ROWID = 1855,
     TIMESTAMP = 2203,
     KW_TAG = 2224,
     LINTMODULEISLIBRARY = 2225,
     KW_PUBLIC = 2226,
     KW_PRIVATE = 2227,
     COPYBACK = 2228,
     REFERENCES_BLOBTYPE_DEFAULT_NULL = 2229,
     REFERENCES_BLOBTYPE = 2230,
     SORT = 2231,
     KWPIPE = 2232,
     KW_DONE = 2233,
     END_TODO = 2234,
     KW_TODO = 2235,
     KW_ALWAYS = 2236
   };
#endif
/* Tokens.  */
#define INT_VALUE 2238
#define NAMED 2239
#define NAMED_GEN 2240
#define CHAR_VALUE 2241
#define NOT_USED_1 2242
#define NOT_USED_2 2243
#define NOT_USED_3 2244
#define NOT_USED_4 2245
#define NOT_USED_5 2246
#define NOT_USED_6 2247
#define NOT_USED_7 2248
#define NOT_USED_8 2249
#define NUMBER_VALUE 2250
#define SEMICOLON 2251
#define QUESTION_MARK 2252
#define CLINE 2253
#define CH 2254
#define MARK_VAR 2255
#define END_MARK_VAR 2256
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
#define EXIT_TODO 1353
#define CONTINUE_TODO 1354
#define UNLOCK_TABLE 1361
#define ROLLBACK_W 1369
#define SQLSEON 1371
#define SQLSEOFF 1372
#define CREATE_VIEW 1376
#define DELETE_FROM 1377
#define EXTENT_SIZE 1384
#define FOREIGN_KEY 1385
#define INSERT_INTO 1388
#define IS_NOT_NULL 1390
#define NOT_MATCHES 1393
#define PRIMARY_KEY 1399
#define WITH_NO_LOG 1406
#define INSHARE 1409
#define BEGIN_WORK 1415
#define DROP_INDEX 1420
#define FOR_UPDATE_OF 1426
#define FOR_UPDATE 1427
#define LOCK_TABLE 1432
#define NOT_EXISTS 1434
#define REFERENCES 1436
#define RENCOL 1437
#define SMALLFLOAT 1439
#define COMMIT_W 1450
#define RENTAB 1457
#define KW_CHAR 1460
#define NCHAR 1461
#define NVARCHAR 1462
#define DELIMITER 1464
#define DROP_VIEW 1466
#define EXCLUSIVE 1469
#define GREATER_THAN_EQ 1473
#define INTO_TEMP 1475
#define DATABASE 1499
#define DATETIME 1500
#define DISTINCT 1502
#define FRACTION 1509
#define GROUP_BY 1511
#define INTERVAL 1512
#define NOT_LIKE 1514
#define NOT_ILIKE 1515
#define NOT_NULL 1516
#define RESOURCE 1522
#define SMALLINT 1523
#define IS_NULL 1529
#define LESS_THAN_EQ 1530
#define BETWEEN 1532
#define CLOSE_BRACKET 1535
#define CONNECT 1538
#define KW_CURRENT 1539
#define KW_DECIMAL 1541
#define DEFAULT 1543
#define INTEGER 1551
#define SERIAL8 1553
#define MATCHES 1556
#define VARCHAR 1569
#define CLOSE_SQUARE 1572
#define GREATER_THAN 1573
#define KW_FALSE 1574
#define NOT_IN 1575
#define OPEN_BRACKET 1577
#define KW_DELETE 1585
#define KW_ESCAPE 1588
#define EXISTS 1589
#define EXTEND 1590
#define HAVING 1594
#define KW_INSERT 1596
#define MINUTE 1600
#define MODIFY 1601
#define EQUAL 1603
#define NOT_EQUAL 1604
#define OPEN_SQUARE 1606
#define PUBLIC 1610
#define KW_RETURN_KEY 1613
#define REVOKE 1615
#define SECOND 1619
#define KW_SELECT 1623
#define SERIAL 1624
#define UNIQUE 1627
#define KW_UPDATE 1629
#define VALUES 1630
#define KW_NULL 1633
#define KW_TRUE 1634
#define ALTER 1636
#define CHECK 1642
#define COUNT 1646
#define KW_FIRST 1651
#define KW_FLOAT 1652
#define GRANT 1655
#define INDEX 1658
#define LESS_THAN 1661
#define MONEY 1663
#define MONTH 1664
#define KW_MULTIPLY 1666
#define ORDER 1667
#define OUTER 1668
#define UNION 1677
#define WHERE 1680
#define KW_BYTE 1687
#define CASE 1689
#define KW_DATE 1691
#define DESC 1692
#define KW_DIVIDE 1693
#define DROP 1696
#define ELSE 1697
#define FROM 1701
#define HOUR 1707
#define INTO 1708
#define LIKE 1711
#define REAL 1720
#define SOME 1725
#define KW_TEXT 1729
#define KW_THEN 1730
#define USER 1731
#define WHEN 1733
#define YEAR 1736
#define KW_DOW 1737
#define XSET 1739
#define ADD 1740
#define ALL 1741
#define KW_AND 1742
#define ANY 1743
#define ASC 1744
#define AVG 1745
#define COLON 1746
#define KW_COMMA 1747
#define DAY 1748
#define DBA 1749
#define KW_FOR 1753
#define XMAX 1758
#define XMIN 1759
#define KW_MINUS 1760
#define KW_MOD 1761
#define KW_NOT 1762
#define KW_SUM 1769
#define ATSIGN 1772
#define KW_PLUS 1773
#define KW_AS 1779
#define KW_BY 1781
#define KW_DOT 1782
#define KW_IN 1785
#define KW_ON 1787
#define KW_OR 1788
#define KW_TO 1789
#define BEFORE 1827
#define END 1831
#define TILDE 1838
#define ILIKE 1839
#define FILLFACTOR 1842
#define TIME 1847
#define KW_TODAY 1854
#define KW_ROWID 1855
#define TIMESTAMP 2203
#define KW_TAG 2224
#define LINTMODULEISLIBRARY 2225
#define KW_PUBLIC 2226
#define KW_PRIVATE 2227
#define COPYBACK 2228
#define REFERENCES_BLOBTYPE_DEFAULT_NULL 2229
#define REFERENCES_BLOBTYPE 2230
#define SORT 2231
#define KWPIPE 2232
#define KW_DONE 2233
#define END_TODO 2234
#define KW_TODO 2235
#define KW_ALWAYS 2236




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
#line 857 "y.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 869 "y.tab.c"

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
#define YYLAST   2403

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  287
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  226
/* YYNRULES -- Number of rules.  */
#define YYNRULES  628
/* YYNRULES -- Number of states.  */
#define YYNSTATES  1117

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   2256

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
       2,     2,     2,   119,   120,     2,     2,     2,     2,     2,
       2,   121,     2,     2,     2,     2,     2,     2,     2,   122,
       2,   123,   124,     2,     2,     2,   125,   126,     2,     2,
       2,     2,     2,     2,   127,   128,     2,     2,   129,     2,
     130,     2,     2,   131,     2,     2,     2,     2,     2,   132,
       2,     2,     2,     2,     2,     2,   133,     2,     2,   134,
       2,     2,     2,     2,     2,   135,     2,     2,     2,     2,
     136,     2,     2,     2,     2,     2,   137,   138,     2,     2,
       2,     2,   139,     2,   140,     2,   141,   142,     2,   143,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     144,     2,     2,     2,     2,     2,     2,   145,     2,     2,
     146,   147,   148,     2,   149,     2,   150,     2,     2,   151,
       2,     2,     2,   152,     2,   153,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,   154,
     155,     2,   156,     2,     2,     2,     2,     2,     2,   157,
       2,   158,   159,     2,   160,   161,   162,     2,     2,     2,
       2,     2,   163,   164,     2,     2,     2,     2,     2,   165,
     166,     2,   167,     2,     2,   168,     2,     2,   169,   170,
       2,   171,     2,   172,     2,     2,     2,     2,     2,     2,
       2,   173,     2,   174,     2,     2,   175,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,   176,
       2,     2,   177,   178,   179,   180,     2,   181,     2,     2,
       2,     2,     2,     2,     2,   182,     2,     2,   183,   184,
     185,     2,     2,     2,   186,     2,   187,     2,     2,     2,
     188,   189,     2,   190,   191,     2,   192,     2,     2,     2,
     193,     2,     2,   194,     2,   195,     2,     2,     2,   196,
       2,     2,     2,   197,   198,     2,     2,   199,     2,   200,
     201,     2,     2,   202,   203,     2,   204,     2,     2,     2,
       2,     2,   205,     2,     2,     2,   206,     2,     2,     2,
       2,   207,   208,     2,     2,   209,     2,     2,   210,     2,
       2,   211,     2,   212,   213,     2,   214,   215,   216,     2,
       2,     2,     2,     2,     2,     2,     2,   217,     2,     2,
     218,     2,     2,     2,     2,     2,     2,   219,     2,   220,
       2,   221,   222,   223,     2,     2,   224,   225,     2,     2,
       2,   226,     2,     2,     2,     2,     2,   227,   228,     2,
       2,   229,     2,     2,     2,     2,     2,     2,     2,     2,
     230,     2,     2,     2,     2,   231,     2,     2,     2,   232,
     233,   234,     2,   235,     2,     2,   236,   237,     2,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
       2,     2,     2,   249,     2,     2,     2,     2,   250,   251,
     252,   253,   254,     2,     2,     2,     2,     2,     2,   255,
       2,     2,   256,   257,     2,     2,     2,     2,     2,   258,
       2,   259,   260,     2,     2,   261,     2,   262,   263,   264,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,   265,     2,     2,
       2,   266,     2,     2,     2,     2,     2,     2,   267,   268,
       2,     2,   269,     2,     2,     2,     2,   270,     2,     2,
       2,     2,     2,     2,   271,   272,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   273,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,   274,   275,   276,   277,   278,   279,
     280,   281,   282,   283,   284,   285,   286,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21
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
     493,     0,    -1,   200,   484,   291,   289,    -1,    -1,   107,
     488,    -1,   218,   400,    -1,    -1,   107,   488,    -1,   218,
     400,    -1,    70,   296,   168,   190,   181,   297,   168,    -1,
      66,   297,   168,    -1,    67,   297,   168,    -1,   238,   292,
      -1,    69,   297,    -1,    68,   297,    -1,   295,    -1,   292,
     246,   295,    -1,   294,    -1,   256,   294,    -1,   487,   426,
      -1,   487,   260,   487,   426,    -1,   487,   260,   487,   260,
     487,   426,    -1,   487,   260,   214,    -1,   293,   190,   298,
      -1,   293,    -1,   296,   246,   293,    -1,   298,    -1,   297,
     246,   298,    -1,   472,    -1,   202,    -1,   300,    -1,   112,
     484,    -1,   150,   484,    -1,   136,   486,    -1,    59,   487,
      -1,   311,    -1,   302,    -1,   115,   484,   181,   316,   168,
     303,    -1,   103,   484,   181,   316,   168,   312,   303,   312,
      -1,    -1,   304,    -1,   305,    -1,   304,   305,    -1,   261,
     306,    -1,   127,     3,    -1,    65,     3,    -1,    82,    -1,
      83,    -1,     4,    -1,    -1,   308,    -1,   309,    -1,   308,
     309,    -1,   261,   306,    -1,   269,     3,    -1,    44,    -1,
      45,    -1,   484,    -1,    93,   486,   262,   310,   181,   314,
     168,   307,    -1,    92,   486,   262,   310,   181,   314,   168,
     307,    -1,    94,   486,   262,   310,   181,   314,   168,   307,
      -1,    95,   486,   262,   310,   181,   314,   168,   307,    -1,
      71,   497,    -1,    72,   497,    -1,   111,   484,   249,   484,
      -1,    61,   484,   261,     6,    -1,    60,   484,    -1,    75,
     484,    -1,    56,   484,    -1,    57,   487,    -1,    -1,   133,
      -1,    -1,   133,    -1,   315,    -1,   314,   246,   315,    -1,
     487,   243,    -1,   487,   222,    -1,   487,    -1,   317,    -1,
     316,   246,   317,    -1,   380,    -1,   378,    -1,    63,   487,
     319,    -1,    64,   486,    90,    -1,    64,   486,    91,    -1,
     320,    -1,   319,   246,   320,    -1,   321,    -1,   324,    -1,
     327,    -1,   332,    -1,   335,    -1,   331,    -1,   330,    -1,
     239,   322,    -1,   239,   181,   323,   168,    -1,   317,    -1,
     317,   265,   487,    -1,   322,    -1,   323,   246,   322,    -1,
     224,   326,    -1,   224,   181,   325,   168,    -1,   326,    -1,
     325,   246,   326,    -1,   487,    -1,   189,   329,    -1,   189,
     181,   328,   168,    -1,   329,    -1,   328,   246,   329,    -1,
     317,    -1,    82,    -1,    83,    -1,    81,     3,    -1,    73,
     378,   334,    -1,    73,   181,   333,   168,    -1,   378,   334,
      -1,   333,   246,   378,   334,    -1,    -1,    76,   487,    -1,
      74,   336,    -1,    74,   181,   336,   168,    -1,   337,    -1,
     336,   246,   337,    -1,   487,    -1,   122,    -1,    -1,   129,
     340,   484,   343,   341,    -1,    -1,   201,   342,   181,   346,
     168,    -1,   466,    -1,    -1,   181,   344,   168,    -1,   345,
      -1,   344,   246,   345,    -1,   487,    -1,   487,   260,   487,
      -1,   347,    -1,   346,   246,   347,    -1,   472,    -1,   202,
      -1,   126,   484,   290,    -1,   135,    -1,   144,    -1,    -1,
     151,    -1,   353,    -1,    51,   487,    52,     6,    50,    -1,
      51,   487,    52,     6,    -1,    53,    -1,    46,    -1,    47,
      -1,   100,   487,    -1,   114,    -1,   350,    -1,   349,    -1,
     338,    -1,   352,    -1,   386,    -1,   390,    -1,   436,    -1,
     299,    -1,   301,    -1,   318,    -1,   209,   359,   262,   484,
     264,   364,   358,    -1,   195,   359,   262,   484,   226,   364,
      -1,   209,   357,   264,   364,    -1,   195,   357,   226,   364,
      -1,   169,    -1,   163,    -1,   248,    -1,    -1,   105,    -1,
     258,   425,    -1,   110,    -1,   240,    -1,   360,    -1,   361,
      -1,   360,   246,   361,    -1,   197,   362,    -1,   187,    -1,
     182,    -1,   200,   362,    -1,   204,    -1,   210,    -1,    -1,
     181,   363,   168,    -1,   427,    -1,   363,   246,   427,    -1,
     365,    -1,   364,   246,   365,    -1,   193,    -1,   425,    -1,
     125,   484,   367,   258,   457,   369,    -1,    -1,   181,   368,
     168,    -1,   427,    -1,   368,   246,   427,    -1,    -1,   104,
      -1,   205,   181,   456,   168,    -1,   128,   181,   373,   168,
     372,    -1,   141,   374,    -1,   375,    -1,   484,    -1,   484,
     181,   375,   168,    -1,   427,    -1,   375,   246,   427,    -1,
     199,   181,   377,   168,    -1,   156,   181,   377,   168,    -1,
     132,   181,   377,   168,    -1,   427,    -1,   377,   246,   427,
      -1,   376,    -1,   371,    -1,   370,    -1,   172,   432,    -1,
     118,    -1,   117,    -1,   116,    -1,   487,   416,   381,   382,
      -1,    -1,   379,    -1,    -1,   383,    -1,   384,    -1,   383,
     384,    -1,   385,   334,    -1,   162,    -1,   108,    -1,   199,
      -1,   156,    -1,   372,    -1,   205,   181,   456,   168,    -1,
     132,    -1,    98,   387,   389,    -1,   388,    -1,   425,    -1,
     390,    -1,   389,   390,    -1,   366,    -1,   356,    -1,   186,
     400,    -1,   218,   400,    -1,   226,   394,    -1,   396,    -1,
     394,   246,   396,    -1,   394,   246,   216,   396,    -1,   394,
     246,   216,   181,   394,   168,    -1,   394,    33,   395,   262,
     400,    -1,   394,    40,   395,   262,   400,    -1,   394,    -1,
     181,   394,   168,    -1,   484,    -1,   484,   431,    -1,   484,
     258,   431,    -1,    -1,   393,   398,    -1,   399,    -1,   392,
     399,    -1,    -1,   453,    -1,   453,   391,    -1,   391,    -1,
     401,    -1,   400,   263,   401,    -1,   402,    -1,   401,   241,
     402,    -1,   403,    -1,   254,   403,    -1,   413,    -1,   181,
     400,   168,    -1,   184,   467,    -1,   140,   467,    -1,    -1,
     183,   409,    -1,    -1,   183,   409,    -1,    -1,   183,   409,
      -1,   510,    -1,   432,    -1,    -1,   254,    -1,   472,   410,
     165,    -1,   472,   410,   130,    -1,   472,   412,   472,    -1,
     472,   190,   472,    -1,   472,   190,   202,    -1,   472,   410,
     167,   472,   241,   472,    -1,   472,   229,   408,   407,    -1,
     472,   160,   408,   407,    -1,   472,   268,   408,   406,    -1,
     472,   161,   408,   406,    -1,   472,   175,   408,   405,    -1,
     472,   131,   408,   405,    -1,   191,    -1,   211,    -1,   178,
      -1,   267,    -1,   166,    -1,   152,    -1,   411,    -1,   479,
      -1,   404,    -1,   472,    -1,    -1,   240,    -1,   156,    -1,
     199,    -1,    -1,   240,    -1,   156,    -1,   199,    -1,   417,
      -1,   418,    -1,   419,    -1,   421,    -1,   146,    -1,   146,
     181,   422,   168,    -1,   198,    -1,   198,   181,     3,   168,
      -1,   174,    -1,   174,   181,     3,   168,    -1,   171,    -1,
     171,   181,   423,   420,   168,    -1,   212,   181,   423,   420,
     168,    -1,   212,    -1,   221,    -1,   173,    -1,   164,    -1,
     147,    -1,   147,   181,   422,   168,    -1,   148,    -1,   148,
     181,     3,   168,    -1,   148,   181,     3,   246,     3,   168,
      -1,   155,   434,   264,   435,    -1,   155,    -1,   159,   434,
     264,   435,    -1,   458,    -1,   159,    -1,   159,   434,   181,
       3,   168,   264,   435,    -1,   232,    -1,   219,    -1,   176,
      -1,   176,   181,     3,   168,    -1,   176,   181,     3,   246,
       3,   168,    -1,    -1,   246,   424,    -1,   208,   181,   423,
     168,    -1,   230,    -1,   143,    -1,   208,    -1,    79,    -1,
       3,    -1,     3,    -1,     3,    -1,   487,    -1,     6,    -1,
      -1,   192,     3,   177,    -1,   192,     3,   246,     3,   177,
      -1,   430,    -1,   256,   430,    -1,   429,    -1,   256,   429,
      -1,   487,   426,    -1,   482,   260,   487,   426,    -1,   482,
     260,   214,    -1,   272,    -1,   487,   426,    -1,   482,   260,
     487,   426,    -1,   487,   260,   487,   260,   487,   426,    -1,
     482,   260,   214,    -1,   487,    -1,     6,    -1,   489,    -1,
       3,    -1,   447,    -1,    -1,   434,   264,   435,    -1,   236,
      -1,   213,    -1,   247,    -1,   227,    -1,   188,    -1,   196,
      -1,   157,    -1,   236,    -1,   213,    -1,   247,    -1,   227,
      -1,   188,    -1,   196,    -1,   157,    -1,   157,   181,     3,
     168,    -1,   441,    -1,   440,    -1,   437,    -1,   145,   438,
     264,   438,    -1,   142,   482,   260,   439,   264,   439,    -1,
     487,    -1,   487,    -1,   121,   484,    -1,   139,   484,   442,
      -1,   134,    -1,   113,    -1,   444,    -1,   444,   434,   264,
     435,    -1,    54,    -1,   446,    -1,   446,   434,   181,     3,
     168,   264,   435,    -1,   446,   434,   264,   435,    -1,    55,
      -1,   170,   433,    -1,   215,   259,   449,    -1,   450,    -1,
     449,   246,   450,    -1,   451,   452,    -1,     3,    -1,   428,
      -1,    -1,   243,    -1,   222,    -1,   158,   454,    -1,   455,
      -1,   454,   246,   455,    -1,   428,    -1,     3,    -1,   400,
      -1,   466,    -1,   270,    -1,   270,   181,     3,   168,    -1,
     273,    -1,   273,   181,     3,   168,    -1,    -1,    -1,   197,
     468,   469,   460,   470,   461,   491,   397,   463,   464,    -1,
     197,   468,   469,   470,   397,   463,    -1,    -1,   217,   415,
     462,    -1,    -1,   448,    -1,   448,   153,   465,   313,    -1,
     153,   465,   313,    -1,   487,    -1,   197,   468,   469,   470,
     397,    -1,   181,   197,   468,   469,   470,   397,   168,    -1,
      -1,   207,     3,    -1,    -1,   240,    -1,   156,    -1,   199,
      -1,   471,    -1,   470,   246,   471,    -1,   472,    -1,   472,
     487,    -1,   472,   258,   487,    -1,   510,    -1,   252,   510,
      -1,   257,   510,    -1,   510,   223,   472,    -1,   510,   478,
      -1,   510,   214,   472,    -1,   510,   257,   472,    -1,   510,
     252,   472,    -1,   510,    58,   472,    -1,   432,    -1,   203,
      -1,   179,    -1,   234,    -1,   271,    -1,   272,    -1,   270,
      -1,   214,    -1,    80,    -1,   244,   181,   414,   472,   168,
      -1,   250,   181,   414,   472,   168,    -1,   251,   181,   414,
     472,   168,    -1,   255,   181,   414,   472,   168,    -1,   206,
     181,   414,   472,   168,    -1,     4,   181,   168,    -1,     4,
     181,   476,   168,    -1,   236,   181,   476,   168,    -1,   213,
     181,   476,   168,    -1,   247,   181,   476,   168,    -1,    48,
     181,   476,   168,    -1,    49,   181,   476,   168,    -1,   237,
     181,   476,   168,    -1,   221,   181,   476,   168,    -1,   181,
     472,   168,    -1,   185,   181,   477,   168,    -1,   443,    -1,
     445,    -1,   220,   474,   266,    -1,   475,    -1,   474,   475,
      -1,   235,   400,   233,   472,    -1,   225,   472,    -1,   472,
      -1,   476,   246,   472,    -1,   170,   246,   434,   264,   435,
      -1,   503,   246,   434,   264,   435,    -1,   170,   434,   264,
     435,    -1,   472,   246,   434,   264,   435,    -1,    84,    -1,
      85,    -1,    86,    -1,    87,    -1,    88,    -1,    89,    -1,
     472,   261,   181,   480,   168,    -1,   472,   261,   467,    -1,
     472,   180,   181,   480,   168,    -1,   472,   180,   467,    -1,
     481,    -1,   480,   246,   481,    -1,   503,    -1,   432,    -1,
     252,     3,    -1,   252,   489,    -1,   483,    -1,     6,    -1,
       6,   260,   487,    -1,   487,    -1,   487,   245,   487,    -1,
     487,   245,     6,   260,   487,    -1,   487,   256,   487,    -1,
     487,   256,   487,   245,   487,    -1,   487,   256,   487,   245,
       6,   260,   487,    -1,   485,    -1,     6,   260,   487,    -1,
     487,   260,   487,    -1,     6,    -1,   487,    -1,   487,   245,
     487,    -1,   487,   245,     6,   260,   487,    -1,   487,   256,
     487,    -1,   487,   256,   487,   245,   487,    -1,   487,   256,
     487,   245,     6,   260,   487,    -1,     6,   260,   487,    -1,
       6,    -1,   487,    -1,   487,   245,   487,    -1,   487,   245,
       6,   260,   487,    -1,   487,   256,   487,    -1,   487,   256,
     487,   245,   487,    -1,   487,   256,   487,   245,     6,   260,
     487,    -1,     4,    -1,     4,    -1,    15,    -1,   260,     3,
      -1,     4,    -1,     6,    -1,    -1,   487,    -1,   495,    -1,
     493,    16,   495,    -1,   339,    -1,   288,    -1,   348,    -1,
      -1,   504,    -1,   355,    -1,   496,    -1,   502,    -1,   494,
      -1,   354,    -1,     1,    -1,   498,   499,    -1,   492,    -1,
     459,    -1,    -1,   138,    -1,   137,   500,    -1,   501,    -1,
     500,   246,   501,    -1,   487,    -1,   487,   260,   487,    -1,
       6,   260,   487,   260,   487,    -1,   124,    -1,   123,    -1,
     109,   512,    -1,   106,    -1,   102,    -1,    99,    -1,    97,
      -1,   101,    -1,   509,    -1,    17,    -1,   505,    -1,   154,
     490,   351,    -1,    20,     6,    21,    -1,   181,   506,   168,
      -1,   506,   507,   506,    -1,     3,    -1,   508,     3,    -1,
     257,    -1,   252,    -1,   214,    -1,   223,    -1,   253,    -1,
     257,    -1,   252,    -1,   487,    -1,   487,   260,   214,    -1,
     487,   260,   272,    -1,   487,   260,   487,    -1,   487,   260,
     487,   260,   487,    -1,     6,   260,   487,   260,   487,    -1,
     487,   192,   506,   177,    -1,   487,   260,   487,   192,   506,
     177,    -1,   487,   260,   487,   260,   487,   192,   506,   177,
      -1,     6,   260,   487,   260,   487,   192,   506,   177,    -1,
     487,   192,   506,   246,   506,   177,    -1,   487,   260,   487,
     192,   506,   246,   506,   177,    -1,   487,   260,   487,   260,
     487,   192,   506,   246,   506,   177,    -1,     6,   260,   487,
     260,   487,   192,   506,   246,   506,   177,    -1,   511,    -1,
     511,    96,   416,    -1,   473,    -1,   503,    -1,   467,    -1,
     240,   467,    -1,   242,   467,    -1,   231,   467,    -1,    -1,
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
    1410,  1414,  1418,  1421,  1428,  1429,  1430,  1434,  1435,  1436,
    1437,  1438,  1439,  1440,  1448,  1449,  1450,  1451,  1456,  1457,
    1458,  1461,  1462,  1463,  1467,  1468,  1469,  1473,  1474,  1478,
    1485,  1486,  1487,  1494,  1495,  1498,  1499,  1504,  1505,  1510,
    1511,  1516,  1517,  1522,  1529,  1530,  1535,  1536,  1540,  1541,
    1548,  1556,  1563,  1570,  1574,  1575,  1580,  1581,  1587,  1591,
    1596,  1603,  1604,  1610,  1613,  1616,  1623,  1624,  1625,  1626,
    1632,  1655,  1656,  1659,  1661,  1668,  1671,  1677,  1685,  1690,
    1696,  1701,  1707,  1710,  1715,  1723,  1732,  1737,  1741,  1742,
    1748,  1751,  1762,  1771,  1778,  1784,  1785,  1788,  1793,  1804,
    1808,  1815,  1816,  1820,  1824,  1828,  1835,  1840,  1848,  1851,
    1857,  1860,  1865,  1870,  1883,  1886,  1892,  1895,  1901,  1904,
    1910,  1913,  1920,  1924,  1935,  1935,  1936,  1936,  1937,  1937,
    1940,  1945,  1950,  1951,  1956,  1965,  1973,  1976,  1979,  1983,
    1990,  1993,  1997,  2000,  2003,  2006,  2012,  2019,  2022,  2025,
    2028,  2029,  2034,  2037,  2040,  2043,  2050,  2051,  2052,  2056,
    2063,  2064,  2065,  2069,  2083,  2090,  2091,  2092,  2096,  2097,
    2102,  2103,  2112,  2114,  2123,  2126,  2134,  2144,  2152,  2154,
    2155,  2156,  2157,  2158,  2159,  2160,  2168,  2169,  2170,  2171,
    2172,  2173,  2174,  2175,  2176,  2177,  2178,  2188,  2189,  2195,
    2197,  2198,  2199,  2200,  2204,  2208,  2212,  2219,  2220,  2225,
    2226,  2230,  2238,  2241,  2248,  2251,  2261,  2264,  2267,  2270,
    2277,  2284,  2292,  2301,  2308,  2312,  2317,  2318,  2319,  2324,
    2326,  2335,  2335,  2335,  2335,  2335,  2335,  2335,  2336,  2336,
    2336,  2336,  2336,  2336,  2336,  2336,  2381,  2382,  2383,  2388,
    2389,  2392,  2393,  2397,  2404,  2415,  2416,  2429,  2430,  2434,
    2438,  2439,  2442,  2448,  2452,  2475,  2485,  2488,  2494,  2503,
    2507,  2514,  2515,  2517,  2522,  2528,  2531,  2537,  2538,  2545,
    2558,  2568,  2575,  2592,  2599,  2624,  2626,  2624,  2648,  2692,
    2693,  2707,  2710,  2717,  2727,  2739,  2745,  2758,  2773,  2775,
    2781,  2782,  2783,  2784,  2794,  2797,  2803,  2806,  2811,  2820,
    2823,  2827,  2834,  2837,  2840,  2843,  2846,  2849,  2852,  2853,
    2854,  2855,  2856,  2857,  2858,  2859,  2860,  2862,  2866,  2870,
    2874,  2878,  2882,  2886,  2890,  2893,  2896,  2899,  2902,  2905,
    2908,  2911,  2914,  2918,  2922,  2926,  2934,  2937,  2946,  2952,
    2959,  2962,  2990,  2993,  2996,  2999,  3005,  3006,  3007,  3008,
    3009,  3010,  3015,  3019,  3023,  3027,  3034,  3037,  3042,  3043,
    3044,  3046,  3052,  3062,  3066,  3070,  3074,  3078,  3082,  3086,
    3090,  3098,  3108,  3113,  3117,  3121,  3125,  3129,  3134,  3138,
    3142,  3150,  3153,  3158,  3159,  3160,  3165,  3166,  3167,  3175,
    3178,  3183,  3184,  3188,  3189,  3194,  3218,  3235,  3236,  3240,
    3247,  3253,  3263,  3265,  3268,  3269,  3270,  3271,  3273,  3276,
    3280,  3285,  3289,  3295,  3296,  3299,  3304,  3305,  3308,  3309,
    3310,  3320,  3321,  3322,  3323,  3324,  3325,  3326,  3327,  3331,
    3337,  3339,  3358,  3366,  3373,  3374,  3375,  3376,  3381,  3382,
    3383,  3384,  3385,  3390,  3391,  3407,  3408,  3409,  3410,  3411,
    3412,  3413,  3414,  3415,  3416,  3418,  3419,  3420,  3421,  3426,
    3429,  3438,  3439,  3440,  3441,  3442,  3443,  3447,  3448
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
  "FILLFACTOR", "TIME", "KW_TODAY", "KW_ROWID", "TIMESTAMP", "KW_TAG",
  "LINTMODULEISLIBRARY", "KW_PUBLIC", "KW_PRIVATE", "COPYBACK",
  "REFERENCES_BLOBTYPE_DEFAULT_NULL", "REFERENCES_BLOBTYPE", "SORT",
  "KWPIPE", "KW_DONE", "END_TODO", "KW_TODO", "KW_ALWAYS", "$accept",
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
       0,   256,  2237,  2238,  2239,  2240,  2241,  2242,  2243,  2244,
    2245,  2246,  2247,  2248,  2249,  2250,  2251,  2252,  2253,  2254,
    2255,  2256,  1001,  1002,  1003,  1004,  1006,  1007,  1012,  1013,
    1014,  1016,  1017,  1019,  1022,  1023,  1024,  1025,  1026,  1027,
    1028,  1031,  1035,  1038,  1054,  1055,  1074,  1077,  1079,  1080,
    1083,  1084,  1085,  1086,  1099,  1100,  1101,  1102,  1116,  1118,
    1119,  1120,  1124,  1131,  1132,  1133,  1170,  1171,  1172,  1173,
    1174,  1177,  1178,  1180,  1181,  1182,  1183,  1186,  1187,  1194,
    1195,  1215,  1216,  1217,  1224,  1225,  1226,  1227,  1228,  1229,
    1234,  1235,  1237,  1238,  1239,  1240,  1250,  1256,  1257,  1258,
    1259,  1260,  1271,  1272,  1280,  1281,  1282,  1288,  1296,  1303,
    1305,  1309,  1310,  1312,  1317,  1343,  1344,  1345,  1346,  1353,
    1354,  1361,  1369,  1371,  1372,  1376,  1377,  1384,  1385,  1388,
    1390,  1393,  1399,  1406,  1409,  1415,  1420,  1426,  1427,  1432,
    1434,  1436,  1437,  1439,  1450,  1457,  1460,  1461,  1462,  1464,
    1466,  1469,  1473,  1475,  1499,  1500,  1502,  1509,  1511,  1512,
    1514,  1515,  1516,  1522,  1523,  1529,  1530,  1532,  1535,  1538,
    1539,  1541,  1543,  1551,  1553,  1556,  1569,  1572,  1573,  1574,
    1575,  1577,  1585,  1588,  1589,  1590,  1594,  1596,  1600,  1601,
    1603,  1604,  1606,  1610,  1613,  1615,  1619,  1623,  1624,  1627,
    1629,  1630,  1633,  1634,  1636,  1642,  1646,  1651,  1652,  1655,
    1658,  1661,  1663,  1664,  1666,  1667,  1668,  1677,  1680,  1687,
    1689,  1691,  1692,  1693,  1696,  1697,  1701,  1707,  1708,  1711,
    1720,  1725,  1729,  1730,  1731,  1733,  1736,  1737,  1739,  1740,
    1741,  1742,  1743,  1744,  1745,  1746,  1747,  1748,  1749,  1753,
    1758,  1759,  1760,  1761,  1762,  1769,  1772,  1773,  1779,  1781,
    1782,  1785,  1787,  1788,  1789,  1827,  1831,  1838,  1839,  1842,
    1847,  1854,  1855,  2203,  2224,  2225,  2226,  2227,  2228,  2229,
    2230,  2231,  2232,  2233,  2234,  2235,  2236
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
     469,   469,   469,   469,   470,   470,   471,   471,   471,   472,
     472,   472,   473,   473,   473,   473,   473,   473,   473,   473,
     473,   473,   473,   473,   473,   473,   473,   473,   473,   473,
     473,   473,   473,   473,   473,   473,   473,   473,   473,   473,
     473,   473,   473,   473,   473,   473,   474,   474,   475,   475,
     476,   476,   477,   477,   477,   477,   478,   478,   478,   478,
     478,   478,   479,   479,   479,   479,   480,   480,   481,   481,
     481,   481,   482,   483,   483,   483,   483,   483,   483,   483,
     483,   484,   485,   485,   485,   485,   485,   485,   485,   485,
     485,   486,   486,   486,   486,   486,   486,   486,   486,   487,
     488,   489,   489,   490,   490,   491,   492,   493,   493,   494,
     494,   494,   495,   495,   495,   495,   495,   495,   495,   495,
     496,   497,   498,   499,   499,   499,   500,   500,   501,   501,
     501,   502,   502,   502,   502,   502,   502,   502,   502,   503,
     503,   503,   504,   505,   506,   506,   506,   506,   507,   507,
     507,   507,   507,   508,   508,   509,   509,   509,   509,   509,
     509,   509,   509,   509,   509,   509,   509,   509,   509,   510,
     510,   511,   511,   511,   511,   511,   511,   512,   512
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
#define YYPACT_NINF -869
static const yytype_int16 yypact[] =
{
    2194,  -869,  -869,  -869,   184,  -869,   331,   184,   184,   331,
     331,   184,   616,   184,   184,   331,   616,   616,   616,   616,
    -869,   628,  -869,   184,  -869,  -869,   331,  -869,   198,   331,
     331,  -869,   331,   331,  -869,  -869,  -869,   331,   331,  -869,
    -869,   616,   331,   654,  -869,   184,   331,   764,   462,  -150,
     331,   462,  -869,  -869,  -869,  -869,  -869,  -869,  -869,  -869,
    -869,  -869,  -869,  -869,  -869,  -869,  -869,  -869,  -869,  -869,
    -869,  -869,  -869,  -869,  -869,  -869,  -869,   375,  -869,  -869,
    -869,   517,  -869,  -869,  -869,   171,  -114,  -869,  -869,   429,
    -869,  -869,  -869,    16,   411,   108,   621,   163,  -869,  -869,
    -869,  -869,  -869,    65,   112,   195,   275,  -869,   -33,  -869,
    -869,  -869,  -869,   364,  -869,  -869,    73,  -869,   393,  -869,
     403,     3,   331,  -869,   280,   334,   341,  -869,   304,   301,
    -869,  -869,  -869,  -869,   446,  -869,  -869,  -869,  -869,  -869,
     423,   423,  -869,  -869,  -869,  -869,   387,   367,   380,  -869,
     648,     0,   128,   399,   421,  -869,  2194,   804,  -869,  -869,
     662,   184,   809,   184,   184,   685,   548,   111,   693,  -869,
    -869,   162,   123,   283,   457,  -869,  -869,  -869,  -869,  -869,
    -869,  -869,  -869,   184,  -869,  -869,   820,   184,   331,   331,
     331,   331,   -33,  -869,   278,   331,   278,   100,   450,   719,
    1002,  -869,   555,  -869,  -869,  -869,   184,   184,   842,   184,
     184,  -869,  -869,   100,  -869,  -869,   126,   331,   602,  -869,
    -869,  -869,  -869,  -869,  1215,  1215,  1215,  1215,    70,    70,
      35,   126,   331,  -869,   480,   481,   510,  -869,   707,  -869,
     504,  -869,   526,  -869,  -869,   598,   606,   611,   406,   620,
     623,  -869,  -869,  -869,   721,   184,   574,  -869,  -869,  -869,
     278,  -869,  -869,  -869,  -869,   469,   184,  -869,  -869,   278,
     558,  -869,   411,  -869,   570,  -869,   589,   656,  -869,   660,
     668,   674,  -869,   -14,  -869,  -869,    13,   654,    32,  -869,
    -869,   596,   513,   665,  -869,  -869,  -869,   678,   603,  -869,
    -869,   860,   689,   694,  -869,  -869,  -869,   699,   473,  -869,
     907,   699,   704,  -869,   711,   714,  -869,   -74,   716,   699,
    -869,   717,   718,   699,   699,   724,   726,   728,   734,  1972,
    1120,   739,  1972,   885,  -869,  -869,  -869,   663,   659,  -869,
    -869,  -869,  -869,  -869,  -869,  -869,   473,  -869,   473,  -869,
    -869,   600,  -869,  -869,   -96,  -869,  -869,  -869,  -869,   413,
     827,   184,   394,  -869,   661,  -869,   669,  -869,   686,  -869,
      40,  -869,  -869,   687,  -869,  -869,   706,  -869,  1759,  1333,
    -869,    95,  -869,  -869,   113,   691,   691,   184,  -869,  -869,
     139,   -90,   692,   749,  -869,   719,  1002,  -869,   687,   681,
     184,   184,   804,  -869,   184,   867,   100,   100,   100,   141,
     721,   100,  1002,   184,  -869,   142,   184,   143,  -869,  -869,
    -869,   759,   761,   765,   473,   473,  -869,   766,  -869,   768,
     769,   770,   771,   772,  -869,  -869,  -869,  -869,   773,   776,
     358,  -869,  -869,  -869,  -869,  -869,   170,  -869,  -869,   177,
     184,  -869,   184,   875,   184,   184,   184,   184,   826,   278,
      90,  -869,  -869,   100,    84,   960,   184,  -869,  -150,   861,
    -869,  1428,   184,   943,  1759,  1759,   775,  -869,  -869,  -869,
    -869,  -869,  -869,  -869,  -869,  -869,   702,  -150,   -48,   667,
    -869,  1854,    96,  1759,  1759,  1002,   254,  -869,  1759,  -869,
    1759,  1759,  -869,  -869,    96,  1759,    96,    96,   413,  -869,
      96,   413,  -869,  1002,  1002,   703,    -7,  1972,  -869,  1972,
    1972,  -869,  1972,  -869,   787,  1546,  -869,  -869,  1972,  -869,
     788,  -869,  1972,   182,  1759,    49,    60,  1759,  -869,  -869,
    -869,  -869,  -869,  -869,  1759,  1759,  1759,  1759,  -869,   469,
     190,  -869,   710,  -869,  -869,  -869,   184,   184,   880,  -869,
     100,   126,   126,   727,  -869,    57,   806,  -869,  1215,  -869,
    -869,   785,    70,    85,  -869,    70,  1215,  -869,   663,   126,
     720,  -869,  -869,  -869,   722,  -869,   808,   731,  -869,   201,
    -869,   249,  -869,   406,  -869,   260,   663,   810,  -869,  -869,
    -869,  -869,   278,   976,   976,   978,   725,     8,   980,   981,
     982,   983,   980,   980,   985,   987,  -869,  -869,  -869,   110,
    -869,   324,  -869,   184,  -869,   278,  -869,  -869,   732,  -869,
     262,  -869,   248,   263,   273,   293,  -869,    90,  -869,   988,
    -869,  -869,   992,   995,  -869,    90,  -869,  -869,  -869,   811,
     -27,   736,     0,  -869,  -869,  -869,  -869,   295,   740,  -869,
     298,   305,   549,     0,  -869,  -869,   451,   755,   834,   758,
    -869,  -869,  -869,  1759,   335,  -869,    25,  -869,  -869,   337,
     339,   344,  1759,   346,  1759,  1759,  1759,   659,  -869,   549,
    1004,   549,   828,   413,   829,   830,   828,    94,  -869,  -869,
    -869,   829,    94,  -869,   830,  -869,  -869,  1759,  -869,  -869,
      49,  -869,  -869,   258,  1006,  -869,  -869,   -15,  -869,  -869,
    -869,  -869,  -869,  -869,  -869,   184,   184,   833,  -869,  -869,
     750,  -869,  -869,  -869,   687,  1759,  -869,   184,  -869,  -869,
     835,  -869,  -869,   185,  -869,  -869,   102,   184,   184,   874,
     100,  -869,   100,  -869,   721,  -869,  -869,  -869,  -869,   850,
     852,   353,   549,  1018,   549,  -869,   777,   856,   360,   862,
     863,   777,   865,   866,  -869,  -869,  -869,  -869,   331,  -869,
    -869,  -869,   854,  -869,  -869,   324,  -869,   721,  -869,  -869,
     184,    36,   184,  -869,  -869,    36,    36,    36,   826,  -869,
    -869,  -869,  -869,  -869,  -869,  -869,  1034,   184,  1759,  -869,
    1759,   184,  -869,  -869,   857,  -869,  -869,  -869,  -869,  -869,
    -869,  -869,  1759,   473,   778,   473,  -869,   473,   871,  -869,
    1759,  -869,  -869,  -869,   873,  -869,   876,   877,   878,  -869,
     881,  -869,   110,  -869,   110,  -869,   110,  -869,  -869,    69,
    -869,   363,  -869,  -869,  -869,   391,  -869,   802,    -3,  -869,
    -869,  -869,    49,  -869,  -869,  -869,    49,  -869,    49,   184,
    -869,  -869,  1641,   184,  -869,   832,  -869,  1215,   184,  -869,
    -869,   628,  -869,  -869,  -869,  -869,  -869,  -869,  -869,  -869,
    -869,  -869,  1049,  -869,   886,  -869,  1050,   887,  -869,  -869,
    1057,  -869,  -869,   893,  -869,  -869,  -869,   883,  1002,  -869,
    -869,  -869,  -869,  -869,   995,  1059,  -869,    36,  -869,  -869,
    -869,  -869,  -869,  -869,   889,   811,   212,  -869,   879,  1066,
     212,   812,   549,   814,   815,  -869,  -869,  -869,  -869,  -869,
    -869,   816,  -869,  -869,  -869,  -869,  -869,  -869,  -869,   132,
    -869,  1759,  -869,   119,   630,   400,   891,  -869,   402,  -869,
    -869,  -869,   331,   332,   853,   410,   811,  -869,   904,   821,
    -869,  -869,  -869,   905,  -869,   100,   916,  -869,  -869,  -869,
    -869,  -869,  -869,    49,   919,   921,   549,   922,   549,   549,
     549,  -869,  -869,  -869,  -869,    49,    49,  -869,  1641,    68,
    -869,    62,    67,  1002,  1002,  -869,   103,  -869,  -869,   908,
     165,    93,  -869,  -869,  -869,   549,  -869,   425,  -869,   461,
    -869,  -869,  -869,  -869,  -869,  -869,   350,   586,  -869,   135,
     135,   101,   184,  -869,  -869,  -869,    52,  -869,  -869,  -869,
     847,  -869,   836,   580,   663,   663,  -869,  -869,  -869,  -869,
    -869,   898,   184,   838,   945,  -869,  -869,  -869,  -869,    49,
    -869,  -869,    49,   331,    68,   837,   839,   174,  -869,  -869,
    -869,    67,    89,  -869,  -150,  -869,   967,  -869,    72,   184,
     502,   637,    54,  1002,  1002,   331,  -869,  -869,  -869,   811,
       0,  -869,  -869,  -869,  -869,   859,  -869,   303,   967,  -869,
    -869,  -869,   663,   663,    79,  -869,  1759,    72,  -869,  -869,
    -869,  -869,  -869,   212,  -869,   853,  -869
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -869,  -869,  -869,  -869,  -869,  -869,  -178,   715,   531,  -869,
    -195,  -292,  -869,  -869,  -869,  -869,   470,  -869,   463,   197,
      -2,  -869,   192,   592,  -869,   314,    17,   361,   322,   920,
    -129,  -869,  -869,   845,  -869,  -246,  -869,  -869,  -869,  -242,
    -869,  -869,  -207,  -869,  -869,  -869,  -869,  -374,  -869,   864,
     709,  -869,  -869,  -869,  -869,  -869,  -869,  -869,   397,  -869,
     120,  -869,  -869,  -869,  -869,  -869,  -869,  -869,  -869,  -869,
    1078,  -869,  1079,  -869,   913,   991,  -869,  -180,   572,  -869,
    -869,  -869,  -869,  -869,  -869,   385,  -869,  -869,   161,  -869,
     155,  -126,  -869,  -869,  -869,  -869,  -869,   354,  -869,  -869,
    -869,  -869,  -869,    63,   136,  -869,  -869,  -825,   116,  -613,
    -782,  -869,   144,  -182,   639,   641,   823,  -869,   460,   456,
     464,   384,    47,  -869,  -869,  -869,  -869,   228,  -869,   614,
    -869,  -869,  -869,   395,  -869,   566,   138,  -869,    -5,  -370,
    -170,  -868,   137,   884,   148,  -571,  -869,  -301,  -546,  -869,
    -869,   966,   626,  -869,  -869,  -869,  -869,  -869,  -869,  -869,
    -869,  -869,  -869,    77,  -869,  -869,  -869,  -869,   114,   281,
    -869,  -869,  -869,  -869,  -869,  -869,    75,  -869,   109,   831,
    -190,  -433,  -603,  -753,   459,    42,  -869,  -869,   695,   443,
    -869,  -869,  -869,   490,   246,   -42,  -869,    53,  -869,   676,
      -4,   801,   348,  -869,  -869,  -869,  -869,  -869,  1042,  -869,
    1185,  -869,  -869,  -869,   799,  -869,  -471,  -869,  -869,  -633,
    -869,  -869,  -869,   -95,  -869,  -869
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
     388,   398,   709,   418,   663,   926,    84,   150,   125,    87,
     822,    84,    92,    93,    84,   284,    84,   284,   102,   930,
    1035,    84,   946,   125,    84,  1093,    84,   858,   125,   113,
     912,   913,   116,   117,   299,   118,   119,  1029,    84,    84,
     120,   121,    37,    84,  1030,   124,   535,   296,    84,   131,
     298,  1029,   465,   152,    84,    84,   125,    86,  1030,   299,
     199,   300,  1029,   296,   301,    84,   774,   477,    89,  1030,
     664,   490,   410,   606,   607,   299,   850,    84,   488,   499,
      84,   850,   107,   502,   503,   296,    84,   999,   298,    84,
     270,    86,   395,   839,   982,   841,   161,   299,   985,   300,
     805,   494,   301,   235,   458,   639,   220,   239,   241,   242,
     243,   495,    48,   258,   536,   952,    84,   265,   268,   265,
     573,   193,   640,   641,   690,   202,    51,   868,    84,   273,
      86,   460,   275,   276,    89,    89,    89,    89,    84,   763,
     265,    89,   265,   292,   224,   225,   226,   227,   228,   221,
     462,   114,   363,   365,   367,   368,   130,   880,   559,   292,
    1094,   860,   111,    89,   578,   513,   893,   642,   895,   806,
     861,   200,  1101,   160,   391,   391,   853,   111,    89,   953,
     710,   853,   459,   954,   508,   955,   588,   511,  1082,  1094,
     222,   278,   278,   278,   278,   869,  1052,  1112,   285,   863,
     864,   258,   670,   396,   865,   282,   265,   691,   830,   459,
    1104,  1002,   268,   567,   308,   265,   383,   383,   383,   383,
     376,   943,   764,   943,   715,   943,   739,   165,   463,   804,
     308,   569,    84,   292,   745,   399,   560,    84,   513,  1003,
     245,   487,   255,   647,   246,   671,   993,   914,   648,   742,
    1031,   711,   308,  1088,   266,   915,   712,   571,  1053,   592,
     599,   601,   705,   676,  1031,   737,  1063,  1067,   247,   372,
    1032,  1048,   195,  1036,  1037,  1031,   387,   188,  1036,   333,
     638,  1115,   716,   860,   698,    84,   672,    86,   622,  1037,
     703,   568,   861,   260,  1037,   624,   849,   706,   561,   707,
    1019,   643,   489,  1113,   333,  1085,   287,   552,   724,   568,
     881,   249,  1026,  1027,  1049,   824,   229,   250,   183,   751,
     333,   863,   864,   879,   189,   155,   865,   465,   850,   789,
     888,   788,   734,   391,   849,   572,   987,   593,   416,   602,
     732,   156,   333,   203,   741,   757,   580,   581,   235,   746,
     583,   585,   292,   292,   292,  1050,   245,   292,   186,   598,
     246,   245,   258,   910,   204,   246,   623,   753,  1068,   187,
     565,   566,   693,   625,   693,   693,  1080,   693,   755,  1081,
     791,   795,   776,   693,   247,   859,   725,   693,   962,   247,
    1022,   796,  1023,  1024,  1025,   878,   626,   752,   627,   629,
     632,   632,   632,   632,  1086,   265,   777,   190,   735,   292,
     649,   797,   651,   809,   269,   778,   812,   754,   658,  1056,
     793,   537,   860,   813,   616,   617,   618,   249,   853,   494,
     779,   861,   249,   250,   166,   167,   780,  1106,   250,   495,
    1002,   794,   168,   169,   170,   752,   270,   538,   539,   540,
     541,   542,   543,   829,   862,   831,   752,   832,   792,   792,
     863,   864,   833,   656,   835,   865,   656,   656,  1003,   792,
     677,   891,   931,   781,   933,  1108,   934,  1060,   899,   782,
     619,   948,   717,   667,   245,   656,   675,   191,   246,   792,
     656,   810,   656,   656,   810,   194,  1109,   656,   419,   208,
    1004,   810,   365,   729,   731,   981,   292,   111,   111,   950,
     209,   738,   247,   591,   860,   210,   595,   700,   391,   743,
     997,   391,   135,   861,   196,   111,   708,   994,  1012,   718,
     886,   810,   887,   810,   197,   810,   719,   720,   721,   722,
     810,   468,   810,  1057,   206,   553,  1013,   211,   265,   892,
     171,   207,   863,   864,   213,   249,   900,   865,   478,   949,
     383,   250,   420,   216,   860,   421,   422,   423,   383,   268,
      84,   265,    95,   861,   424,   136,   218,   544,   425,   217,
     478,   137,    84,   426,   107,   172,   545,   949,  1058,   479,
     427,  1090,   428,   429,   138,   430,   995,   480,   998,   139,
     173,   219,   863,   864,   157,   158,   568,   865,    84,   140,
     125,   479,   141,   231,   481,   546,   142,   431,   238,   480,
     547,   750,   143,  1073,   162,   860,   245,   432,   482,  1099,
     246,   433,   965,   232,   861,   163,   481,   483,   434,   164,
     435,   244,   103,   104,   105,   106,   259,   823,   484,   436,
     482,   437,   144,   272,   247,   465,   814,  1059,   293,   483,
     145,   184,   185,   863,   864,   828,   860,   123,   865,  1105,
     484,   552,   871,   294,   834,   861,   836,   837,   838,   248,
    -282,   517,   682,   876,   684,   685,   361,   815,   686,   438,
     400,   401,   439,   883,   884,   816,   292,   249,   292,   857,
     770,   771,   518,   250,   863,   864,   402,   403,   208,   865,
     519,   520,   817,  1061,   404,  -282,   521,  -282,   132,   209,
     133,   405,   465,   466,    89,   522,   818,   565,   523,   406,
     524,   279,   280,   281,   138,   819,   911,   407,   632,   139,
     525,   526,   408,   920,   921,   922,   820,   413,   517,   140,
     860,   411,   141,   925,   412,   588,   142,   928,    84,   861,
     234,   527,   143,    84,  1100,   240,   633,   634,   635,   518,
     416,  1044,  1045,   450,    84,   208,   274,   519,   520,   528,
     452,   907,  1062,   521,   453,   665,   209,   454,   863,   864,
    -525,   455,   522,   865,   860,   523,    84,   524,   366,   456,
     565,   860,   927,   861,   529,   457,   464,   525,   526,   471,
     861,   530,   468,   472,   565,   956,   473,   531,   532,   961,
     474,    84,   936,   584,   966,   475,   967,   111,   527,    84,
     476,   628,   863,   864,    84,   491,   730,   865,   512,   863,
     864,   944,   492,   945,   865,   493,   528,   498,   500,   501,
     514,  1102,  1103,   694,   695,   504,   696,   505,  -305,   506,
     296,   297,   701,   298,   960,   507,   704,   660,   661,   383,
     510,   529,   299,   549,   300,   556,   513,   301,   530,   557,
    -305,   558,   562,   561,   531,   532,   674,   568,   575,   576,
     603,   679,   604,   680,   681,   579,   605,   608,   683,   609,
     610,   611,   612,   613,   614,   302,   303,   615,    89,   636,
    1042,   304,   305,   650,   659,   653,   662,   689,   697,   702,
     726,   292,   487,   735,   665,   740,   749,   750,   756,   758,
     747,   761,   748,   765,   767,   768,   769,   306,   772,   762,
     773,   799,   790,   992,  1042,   800,   807,  1034,  1043,   801,
     811,   825,   826,   465,   827,   296,   297,   840,   298,   867,
     873,   842,   844,   846,   872,   778,   877,   299,   889,   300,
     890,   894,   301,   896,   898,    89,    89,    89,  1034,  1042,
     901,   902,  1043,   904,   905,   908,  1042,   924,   929,   935,
     960,   937,   932,   951,   938,   939,   940,   307,  1077,   941,
     302,   303,   968,   970,   969,   972,   304,   305,   962,    89,
     973,   974,   978,    89,   975,  1042,   980,  1043,  1089,   984,
    1010,   983,  1014,  1016,  1043,  1077,   986,   308,   988,   989,
     990,    89,   306,   996,  1018,  1015,   309,  1020,   310,  1021,
    -504,   311,   312,  1071,  1003,  1074,  1072,  1078,  1079,  1083,
    1091,  1084,   570,  1043,   487,  1107,   744,   798,   803,   979,
     313,   977,   923,   314,   919,  1111,   286,   451,  1028,   415,
     315,   316,   870,   296,   297,   600,   298,   317,   318,   153,
     154,   377,   215,   733,   885,   299,  1017,   300,   319,   909,
     301,   320,   307,   321,   322,  1047,  1066,   323,   565,   324,
    1046,   325,   687,   509,   326,   688,   848,   327,   328,   329,
     856,   330,   331,   723,   332,   854,   903,   333,   302,   303,
     760,   461,   308,  1070,   304,   305,   369,   334,   335,   336,
    1069,   309,   728,   310,  1114,  1087,   311,   312,  1098,   976,
    1116,   678,   855,   555,   874,   991,   577,   947,   233,   101,
     306,   582,     0,     0,     0,   313,     0,     0,   314,     0,
       0,     0,     0,     0,     0,   315,   316,     0,   296,   297,
       0,   298,   317,   318,     0,     0,     0,     0,     0,     0,
     299,     0,   300,   319,     0,   301,   320,     0,   321,   322,
       0,     0,   323,     0,   324,     0,   325,     0,     0,   326,
       0,     0,   327,   328,   329,     0,   330,   331,     0,   332,
     307,     0,   333,   302,   303,     0,     0,     0,     0,   304,
     305,     0,   334,   335,   336,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     308,     0,     0,     0,     0,   306,     0,     0,     0,   309,
       0,   310,     0,     0,   311,   312,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   313,     0,     0,   314,     0,     0,     0,
       0,     0,     0,   315,   316,     0,   296,   297,     0,   298,
     317,   318,     0,     0,     0,     0,     0,     0,   299,     0,
     300,   319,     0,   301,   320,     0,   321,   322,     0,     0,
     323,     0,   324,     0,   325,     0,     0,   326,     0,     0,
     327,   328,   329,     0,     0,   331,     0,   332,     0,     0,
     333,   302,   303,     0,     0,   308,     0,   304,   305,     0,
     334,   335,   336,     0,   309,     0,   379,     0,     0,     0,
     312,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   306,     0,     0,     0,   380,   313,     0,
       0,   314,     0,     0,     0,     0,     0,     0,   315,   316,
       0,   296,   297,     0,   298,   317,   318,     0,     0,     0,
       0,     0,     0,   299,     0,   300,   319,     0,   301,   320,
       0,   321,   322,     0,     0,   323,     0,   324,     0,   325,
       0,     0,   326,     0,     0,   327,   328,   329,     0,     0,
     331,     0,   332,     0,     0,   333,   302,   303,     0,     0,
       0,     0,   304,   305,     0,   334,   335,   336,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   308,     0,     0,     0,     0,   306,     0,
       0,     0,   309,     0,   379,     0,     0,     0,   312,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     487,     0,     0,     0,     0,     0,   313,     0,     0,   314,
       0,     0,     0,     0,     0,     0,   315,   316,     0,   296,
     297,     0,   298,   317,   318,     0,     0,     0,     0,     0,
       0,   299,     0,   300,   319,     0,   301,   320,     0,   321,
     322,     0,     0,   323,     0,   324,     0,   325,     0,     0,
     326,     0,     0,   327,   328,   329,     0,     0,   331,     0,
     332,     0,     0,   333,   302,   303,   655,     0,   308,     0,
     304,   305,     0,   334,   335,   336,     0,   309,     0,   379,
       0,     0,     0,   312,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   306,     0,     0,     0,
       0,   313,     0,     0,   314,     0,     0,     0,     0,     0,
       0,   315,   316,     0,   296,   297,     0,   298,   317,   318,
       0,     0,     0,     0,     0,     0,   299,     0,   300,   319,
       0,   301,   320,     0,   321,   322,     0,     0,   323,     0,
     324,     0,   325,     0,     0,   326,     0,     0,   327,   328,
     329,     0,     0,   331,     0,   332,     0,     0,   333,   302,
     303,     0,     0,     0,     0,   304,   305,     0,   334,   335,
     336,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   308,     0,     0,     0,
       0,   306,     0,     0,     0,   309,     0,   379,     0,     0,
       0,   312,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   699,   313,
       0,     0,   314,     0,     0,     0,     0,     0,     0,   315,
     316,     0,   296,   297,     0,   298,   317,   318,     0,     0,
       0,     0,     0,     0,   299,     0,   300,   319,     0,   301,
     320,     0,   321,   322,     0,     0,   323,     0,   324,     0,
     325,     0,     0,   326,     0,     0,   327,   328,   329,     0,
       0,   331,     0,   332,     0,     0,   333,   302,   303,     0,
       0,   308,     0,   304,   305,     0,   334,   335,   336,     0,
     309,     0,   379,     0,     0,     0,   312,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   306,
       0,     0,     0,   957,   313,     0,     0,   314,     0,     0,
       0,     0,     0,     0,   315,   316,     0,   296,   297,     0,
     298,   317,   318,     0,     0,     0,     0,     0,     0,   299,
       0,   300,   319,     0,   301,   320,     0,   321,   322,     0,
       0,   323,     0,   324,     0,   325,     0,     0,   326,     0,
       0,   327,   328,   329,     0,     0,   331,     0,   332,     0,
       0,   333,   302,   303,     0,     0,     0,     0,   304,   305,
       0,   334,   335,   336,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   308,
       0,     0,     0,     0,   306,     0,     0,     0,   309,     0,
     379,     0,     0,     0,   312,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   313,     0,     0,   314,     0,     0,     0,     0,
       0,     0,   315,   316,     0,   296,   297,     0,   298,   317,
     318,     0,     0,     0,     0,     0,     0,   299,     0,   300,
     319,     0,   301,   320,     0,   321,   322,     0,     0,   323,
       0,   324,     0,   325,     0,     0,   326,     0,     0,   327,
     328,   329,     0,     0,   331,     0,   332,     0,     0,   333,
     302,   303,     0,     0,   666,     0,   304,   305,     0,   334,
     335,   336,     0,   309,     0,   379,     0,     0,     0,   312,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   306,     0,     0,     0,     0,   313,     0,     0,
     314,     0,     0,     0,     0,     0,     0,   315,   316,     0,
       0,     0,     0,     0,   317,   318,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   319,     0,     0,   320,     0,
     321,   322,     0,     0,   323,     0,   324,     0,   325,     0,
       0,   326,     0,     0,   327,   328,   329,     0,     0,   331,
       0,   332,     0,     0,   333,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   334,   335,   336,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   308,     0,     0,     0,     0,     0,     0,     0,
       0,   309,     0,   379,     0,     0,     0,   312,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   313,     0,     0,   314,     0,
       0,     0,     0,     0,     0,   315,   316,     0,     0,     0,
       0,     0,   317,   318,  -562,     1,     0,     0,     0,     0,
       0,     0,     0,   319,     0,     0,   320,     0,   321,   322,
    -562,     0,   323,     0,   324,     0,   325,     0,     0,   326,
       0,     0,   327,   328,     0,     0,     0,   331,     0,     0,
       0,     0,   333,     0,     0,     0,     0,     0,     0,     0,
       2,     3,   334,   335,   336,     4,     0,     5,     0,     0,
       6,     7,     0,     8,     9,    10,     0,    11,    12,     0,
       0,     0,     0,     0,     0,    13,    14,     0,     0,    15,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    16,    17,    18,    19,
       0,    20,    21,    22,    23,    24,    25,    26,     0,     0,
      27,     0,     0,    28,     0,    29,    30,     0,    31,    32,
       0,     0,     0,     0,     0,    33,    34,    35,    36,    37,
      38,     0,     0,    39,     0,     0,     0,     0,     0,    40,
      41,     0,     0,    42,     0,     0,    43,     0,    44,    45,
       0,     0,     0,     0,    46,     0,     0,     0,    47,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    48,
       0,    49,     0,     0,    50,     0,     0,     0,     0,     0,
       0,     0,     0,    51
};

static const yytype_int16 yycheck[] =
{
       4,    43,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    21,    21,   200,    23,
     491,   391,    26,   269,   266,    29,    30,   197,    32,    33,
     225,   226,   227,    37,    38,   468,   410,    41,    42,    43,
     166,    45,    46,   213,   173,   346,    50,   348,   619,   652,
     228,   231,     3,   260,   487,   808,     4,   207,     6,     6,
     663,     4,     9,    10,     4,   194,     4,   196,    15,   822,
       3,     4,     3,     6,     4,     3,     4,   710,     6,    26,
      44,    45,    29,    30,    15,    32,    33,    33,     4,     4,
      37,    38,   125,     4,    40,    42,   192,     3,     4,    46,
       6,    33,   192,    50,     4,     4,     6,     6,    40,    15,
     107,    17,    33,     3,    20,     4,     6,   307,   122,    40,
     168,   311,   248,   424,   425,    15,   697,     4,   310,   319,
       4,   702,     6,   323,   324,     3,     4,   962,     6,     4,
     269,     6,   107,   689,   926,   691,   260,    15,   930,    17,
     177,   225,    20,   157,   168,    65,   156,   161,   162,   163,
     164,   235,   195,   167,   260,   168,     4,   171,   172,   173,
     260,   108,    82,    83,   181,   122,   209,   192,     4,   183,
       6,   168,   186,   187,   188,   189,   190,   191,     4,   181,
     194,   195,   196,   197,    66,    67,    68,    69,    70,   199,
     168,     3,   206,   207,   208,   209,   210,   105,   168,   213,
    1078,   214,   216,   217,   396,   263,   762,   127,   764,   246,
     223,   218,   168,    52,   228,   229,   697,   231,   232,   862,
     181,   702,   246,   866,   329,   868,   406,   332,  1063,  1107,
     240,   188,   189,   190,   191,   260,   153,   168,   195,   252,
     253,   255,   156,   218,   257,   192,   260,   264,   233,   246,
    1085,   158,   266,   168,   170,   269,   224,   225,   226,   227,
     217,   842,   264,   844,   214,   846,   568,   261,   246,   649,
     170,   168,     4,   287,   576,   232,   246,     4,   263,   186,
     128,   197,   181,   463,   132,   199,   177,   261,   214,   214,
     246,   252,   170,   214,   181,   269,   257,   168,   215,   168,
     168,   168,   130,   495,   246,   258,   181,   216,   156,   193,
     258,   156,   249,   256,   272,   246,   256,   262,   256,   260,
     459,  1113,   272,   214,   524,     4,   240,     6,   168,   272,
     530,   246,   223,   181,   272,   168,   252,   165,   246,   167,
     983,   261,   310,  1106,   260,   181,   256,   361,   168,   246,
     258,   199,   995,   996,   199,   666,   238,   205,   260,   168,
     260,   252,   253,   743,   262,     0,   257,   192,   949,   625,
     754,   623,   562,   387,   252,   246,   932,   246,   246,   246,
     560,    16,   260,   113,   572,   602,   400,   401,   402,   579,
     404,   405,   406,   407,   408,   240,   128,   411,   245,   413,
     132,   128,   416,   787,   134,   132,   246,   168,  1031,   256,
     378,   379,   517,   246,   519,   520,  1059,   522,   168,  1062,
     168,   168,   108,   528,   156,   177,   246,   532,   226,   156,
     986,   168,   988,   989,   990,   260,   450,   246,   452,   453,
     454,   455,   456,   457,  1067,   459,   132,   262,   246,   463,
     464,   168,   466,   168,   181,   141,   168,   593,   472,  1015,
     222,    58,   214,   168,   116,   117,   118,   199,   949,   225,
     156,   223,   199,   205,    73,    74,   162,  1090,   205,   235,
     158,   243,    81,    82,    83,   246,   625,    84,    85,    86,
      87,    88,    89,   168,   246,   168,   246,   168,   246,   246,
     252,   253,   168,   471,   168,   257,   474,   475,   186,   246,
     266,   168,   823,   199,   825,   222,   827,   177,   168,   205,
     172,   168,   536,   491,   128,   493,   494,   262,   132,   246,
     498,   246,   500,   501,   246,   181,   243,   505,    79,   245,
     218,   246,   556,   557,   558,   925,   560,   561,   562,   168,
     256,   565,   156,   408,   214,   264,   411,   525,   572,   573,
     168,   575,   110,   223,   181,   579,   534,   177,   168,   537,
     750,   246,   752,   246,   181,   246,   544,   545,   546,   547,
     246,   197,   246,   168,   260,   201,   966,   151,   602,   246,
     189,   260,   252,   253,   181,   199,   246,   257,   157,   246,
     568,   205,   143,   226,   214,   146,   147,   148,   576,   623,
       4,   625,     6,   223,   155,   163,   246,   214,   159,   262,
     157,   169,     4,   164,     6,   224,   223,   246,   177,   188,
     171,  1074,   173,   174,   182,   176,   246,   196,   246,   187,
     239,     3,   252,   253,   137,   138,   246,   257,     4,   197,
       6,   188,   200,   264,   213,   252,   204,   198,     6,   196,
     257,   246,   210,  1043,   245,   214,   128,   208,   227,   177,
     132,   212,   877,   262,   223,   256,   213,   236,   219,   260,
     221,     6,    16,    17,    18,    19,     3,   246,   247,   230,
     227,   232,   240,   246,   156,   192,   157,   246,   258,   236,
     248,    90,    91,   252,   253,   673,   214,    41,   257,  1089,
     247,   725,   726,     4,   682,   223,   684,   685,   686,   181,
     130,   131,   504,   737,   506,   507,   181,   188,   510,   270,
     260,   260,   273,   747,   748,   196,   750,   199,   752,   707,
     612,   613,   152,   205,   252,   253,   246,    50,   245,   257,
     160,   161,   213,   177,   260,   165,   166,   167,     4,   256,
       6,   245,   192,   260,   778,   175,   227,   735,   178,   181,
     180,   189,   190,   191,   182,   236,   790,   181,   792,   187,
     190,   191,   181,   795,   796,   797,   247,    76,   131,   197,
     214,   181,   200,   807,   181,   975,   204,   811,     4,   223,
       6,   211,   210,     4,   177,     6,   455,   456,   457,   152,
     246,  1003,  1004,   265,     4,   245,     6,   160,   161,   229,
     260,   778,   246,   166,   245,   168,   256,   181,   252,   253,
     260,   181,   175,   257,   214,   178,     4,   180,     6,   181,
     808,   214,   810,   223,   254,   181,   260,   190,   191,   181,
     223,   261,   197,   260,   822,   869,     6,   267,   268,   873,
     181,     4,   830,     6,   878,   181,   881,   881,   211,     4,
     181,     6,   252,   253,     4,   181,     6,   257,     3,   252,
     253,   844,   181,   846,   257,   181,   229,   181,   181,   181,
     241,  1083,  1084,   519,   520,   181,   522,   181,   241,   181,
       3,     4,   528,     6,   872,   181,   532,   474,   475,   877,
     181,   254,    15,    96,    17,   264,   263,    20,   261,   260,
     263,   245,   226,   246,   267,   268,   493,   246,   246,   190,
     181,   498,   181,   500,   501,   264,   181,   181,   505,   181,
     181,   181,   181,   181,   181,    48,    49,   181,   962,   133,
    1002,    54,    55,     3,    21,   104,   264,   264,   181,   181,
     260,   975,   197,   246,   168,   190,   168,   246,   168,     3,
     260,     3,   260,     3,     3,     3,     3,    80,     3,   264,
       3,     3,   260,   951,  1036,     3,   260,  1001,  1002,     4,
     260,   246,   168,   192,   246,     3,     4,     3,     6,     3,
     260,   183,   183,   183,   181,   141,   181,    15,   168,    17,
     168,     3,    20,   246,   168,  1029,  1030,  1031,  1032,  1071,
     168,   168,  1036,   168,   168,   181,  1078,     3,   181,   168,
     998,   168,   264,   241,   168,   168,   168,   140,  1052,   168,
      48,    49,     3,     3,   168,   168,    54,    55,   226,  1063,
       3,   168,     3,  1067,   181,  1107,   177,  1071,  1072,     3,
     217,   192,   168,   168,  1078,  1079,   264,   170,   264,   264,
     264,  1085,    80,   192,   168,   264,   179,   168,   181,   168,
     168,   184,   185,   246,   186,   197,   260,   259,   153,   262,
     133,   262,   387,  1107,   197,   246,   575,   637,   645,   917,
     203,   914,   798,   206,   792,  1098,   196,   272,   998,   255,
     213,   214,   725,     3,     4,   416,     6,   220,   221,    51,
      51,   218,   141,   561,   749,    15,   975,    17,   231,   785,
      20,   234,   140,   236,   237,  1009,  1030,   240,  1106,   242,
    1006,   244,   513,   330,   247,   514,   696,   250,   251,   252,
     704,   254,   255,   549,   257,   701,   771,   260,    48,    49,
     604,   287,   170,  1036,    54,    55,   210,   270,   271,   272,
    1032,   179,   556,   181,  1107,  1071,   184,   185,  1079,   908,
    1115,   496,   702,   362,   735,   949,   395,   849,   156,    14,
      80,   402,    -1,    -1,    -1,   203,    -1,    -1,   206,    -1,
      -1,    -1,    -1,    -1,    -1,   213,   214,    -1,     3,     4,
      -1,     6,   220,   221,    -1,    -1,    -1,    -1,    -1,    -1,
      15,    -1,    17,   231,    -1,    20,   234,    -1,   236,   237,
      -1,    -1,   240,    -1,   242,    -1,   244,    -1,    -1,   247,
      -1,    -1,   250,   251,   252,    -1,   254,   255,    -1,   257,
     140,    -1,   260,    48,    49,    -1,    -1,    -1,    -1,    54,
      55,    -1,   270,   271,   272,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     170,    -1,    -1,    -1,    -1,    80,    -1,    -1,    -1,   179,
      -1,   181,    -1,    -1,   184,   185,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   203,    -1,    -1,   206,    -1,    -1,    -1,
      -1,    -1,    -1,   213,   214,    -1,     3,     4,    -1,     6,
     220,   221,    -1,    -1,    -1,    -1,    -1,    -1,    15,    -1,
      17,   231,    -1,    20,   234,    -1,   236,   237,    -1,    -1,
     240,    -1,   242,    -1,   244,    -1,    -1,   247,    -1,    -1,
     250,   251,   252,    -1,    -1,   255,    -1,   257,    -1,    -1,
     260,    48,    49,    -1,    -1,   170,    -1,    54,    55,    -1,
     270,   271,   272,    -1,   179,    -1,   181,    -1,    -1,    -1,
     185,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    80,    -1,    -1,    -1,   202,   203,    -1,
      -1,   206,    -1,    -1,    -1,    -1,    -1,    -1,   213,   214,
      -1,     3,     4,    -1,     6,   220,   221,    -1,    -1,    -1,
      -1,    -1,    -1,    15,    -1,    17,   231,    -1,    20,   234,
      -1,   236,   237,    -1,    -1,   240,    -1,   242,    -1,   244,
      -1,    -1,   247,    -1,    -1,   250,   251,   252,    -1,    -1,
     255,    -1,   257,    -1,    -1,   260,    48,    49,    -1,    -1,
      -1,    -1,    54,    55,    -1,   270,   271,   272,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   170,    -1,    -1,    -1,    -1,    80,    -1,
      -1,    -1,   179,    -1,   181,    -1,    -1,    -1,   185,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     197,    -1,    -1,    -1,    -1,    -1,   203,    -1,    -1,   206,
      -1,    -1,    -1,    -1,    -1,    -1,   213,   214,    -1,     3,
       4,    -1,     6,   220,   221,    -1,    -1,    -1,    -1,    -1,
      -1,    15,    -1,    17,   231,    -1,    20,   234,    -1,   236,
     237,    -1,    -1,   240,    -1,   242,    -1,   244,    -1,    -1,
     247,    -1,    -1,   250,   251,   252,    -1,    -1,   255,    -1,
     257,    -1,    -1,   260,    48,    49,   168,    -1,   170,    -1,
      54,    55,    -1,   270,   271,   272,    -1,   179,    -1,   181,
      -1,    -1,    -1,   185,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    80,    -1,    -1,    -1,
      -1,   203,    -1,    -1,   206,    -1,    -1,    -1,    -1,    -1,
      -1,   213,   214,    -1,     3,     4,    -1,     6,   220,   221,
      -1,    -1,    -1,    -1,    -1,    -1,    15,    -1,    17,   231,
      -1,    20,   234,    -1,   236,   237,    -1,    -1,   240,    -1,
     242,    -1,   244,    -1,    -1,   247,    -1,    -1,   250,   251,
     252,    -1,    -1,   255,    -1,   257,    -1,    -1,   260,    48,
      49,    -1,    -1,    -1,    -1,    54,    55,    -1,   270,   271,
     272,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   170,    -1,    -1,    -1,
      -1,    80,    -1,    -1,    -1,   179,    -1,   181,    -1,    -1,
      -1,   185,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   202,   203,
      -1,    -1,   206,    -1,    -1,    -1,    -1,    -1,    -1,   213,
     214,    -1,     3,     4,    -1,     6,   220,   221,    -1,    -1,
      -1,    -1,    -1,    -1,    15,    -1,    17,   231,    -1,    20,
     234,    -1,   236,   237,    -1,    -1,   240,    -1,   242,    -1,
     244,    -1,    -1,   247,    -1,    -1,   250,   251,   252,    -1,
      -1,   255,    -1,   257,    -1,    -1,   260,    48,    49,    -1,
      -1,   170,    -1,    54,    55,    -1,   270,   271,   272,    -1,
     179,    -1,   181,    -1,    -1,    -1,   185,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    80,
      -1,    -1,    -1,   202,   203,    -1,    -1,   206,    -1,    -1,
      -1,    -1,    -1,    -1,   213,   214,    -1,     3,     4,    -1,
       6,   220,   221,    -1,    -1,    -1,    -1,    -1,    -1,    15,
      -1,    17,   231,    -1,    20,   234,    -1,   236,   237,    -1,
      -1,   240,    -1,   242,    -1,   244,    -1,    -1,   247,    -1,
      -1,   250,   251,   252,    -1,    -1,   255,    -1,   257,    -1,
      -1,   260,    48,    49,    -1,    -1,    -1,    -1,    54,    55,
      -1,   270,   271,   272,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   170,
      -1,    -1,    -1,    -1,    80,    -1,    -1,    -1,   179,    -1,
     181,    -1,    -1,    -1,   185,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   203,    -1,    -1,   206,    -1,    -1,    -1,    -1,
      -1,    -1,   213,   214,    -1,     3,     4,    -1,     6,   220,
     221,    -1,    -1,    -1,    -1,    -1,    -1,    15,    -1,    17,
     231,    -1,    20,   234,    -1,   236,   237,    -1,    -1,   240,
      -1,   242,    -1,   244,    -1,    -1,   247,    -1,    -1,   250,
     251,   252,    -1,    -1,   255,    -1,   257,    -1,    -1,   260,
      48,    49,    -1,    -1,   170,    -1,    54,    55,    -1,   270,
     271,   272,    -1,   179,    -1,   181,    -1,    -1,    -1,   185,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    80,    -1,    -1,    -1,    -1,   203,    -1,    -1,
     206,    -1,    -1,    -1,    -1,    -1,    -1,   213,   214,    -1,
      -1,    -1,    -1,    -1,   220,   221,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   231,    -1,    -1,   234,    -1,
     236,   237,    -1,    -1,   240,    -1,   242,    -1,   244,    -1,
      -1,   247,    -1,    -1,   250,   251,   252,    -1,    -1,   255,
      -1,   257,    -1,    -1,   260,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   270,   271,   272,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   170,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   179,    -1,   181,    -1,    -1,    -1,   185,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   203,    -1,    -1,   206,    -1,
      -1,    -1,    -1,    -1,    -1,   213,   214,    -1,    -1,    -1,
      -1,    -1,   220,   221,     0,     1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   231,    -1,    -1,   234,    -1,   236,   237,
      16,    -1,   240,    -1,   242,    -1,   244,    -1,    -1,   247,
      -1,    -1,   250,   251,    -1,    -1,    -1,   255,    -1,    -1,
      -1,    -1,   260,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      46,    47,   270,   271,   272,    51,    -1,    53,    -1,    -1,
      56,    57,    -1,    59,    60,    61,    -1,    63,    64,    -1,
      -1,    -1,    -1,    -1,    -1,    71,    72,    -1,    -1,    75,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    92,    93,    94,    95,
      -1,    97,    98,    99,   100,   101,   102,   103,    -1,    -1,
     106,    -1,    -1,   109,    -1,   111,   112,    -1,   114,   115,
      -1,    -1,    -1,    -1,    -1,   121,   122,   123,   124,   125,
     126,    -1,    -1,   129,    -1,    -1,    -1,    -1,    -1,   135,
     136,    -1,    -1,   139,    -1,    -1,   142,    -1,   144,   145,
      -1,    -1,    -1,    -1,   150,    -1,    -1,    -1,   154,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   195,
      -1,   197,    -1,    -1,   200,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   209
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
{
       0,     1,    46,    47,    51,    53,    56,    57,    59,    60,
      61,    63,    64,    71,    72,    75,    92,    93,    94,    95,
      97,    98,    99,   100,   101,   102,   103,   106,   109,   111,
     112,   114,   115,   121,   122,   123,   124,   125,   126,   129,
     135,   136,   139,   142,   144,   145,   150,   154,   195,   197,
     200,   209,   288,   299,   300,   301,   302,   311,   318,   338,
     339,   348,   349,   350,   352,   353,   354,   355,   356,   366,
     386,   390,   436,   437,   440,   441,   459,   493,   494,   495,
     496,   498,   502,   504,     4,   487,     6,   484,   485,   487,
     487,   487,   484,   484,   487,     6,   486,   487,   487,   492,
     497,   497,   484,   486,   486,   486,   486,     6,   387,   388,
     425,   487,   487,   484,     3,   512,   484,   484,   484,   484,
     484,   484,   340,   486,   484,     6,   482,   483,   487,   438,
     487,   484,     4,     6,   490,   110,   163,   169,   182,   187,
     197,   200,   204,   210,   240,   248,   357,   359,   360,   361,
     207,   468,   484,   357,   359,     0,    16,   137,   138,   499,
      52,   260,   245,   256,   260,   261,    73,    74,    81,    82,
      83,   189,   224,   239,   319,   320,   321,   324,   327,   330,
     331,   332,   335,   260,    90,    91,   245,   256,   262,   262,
     262,   262,   389,   390,   181,   249,   181,   181,   367,   107,
     218,   290,   484,   113,   134,   442,   260,   260,   245,   256,
     264,   151,   351,   181,   362,   362,   226,   262,   246,     3,
     156,   199,   240,   469,    66,    67,    68,    69,    70,   238,
     291,   264,   262,   495,     6,   487,   500,   501,     6,   487,
       6,   487,   487,   487,     6,   128,   132,   156,   181,   199,
     205,   370,   371,   376,   378,   181,   336,   337,   487,     3,
     181,   317,   329,   378,   380,   487,   181,   326,   487,   181,
     317,   322,   246,   487,     6,   487,   487,   310,   484,   310,
     310,   310,   390,   316,   317,   484,   316,   256,   368,   427,
     430,   482,   487,   258,     4,   488,     3,     4,     6,    15,
      17,    20,    48,    49,    54,    55,    80,   140,   170,   179,
     181,   184,   185,   203,   206,   213,   214,   220,   221,   231,
     234,   236,   237,   240,   242,   244,   247,   250,   251,   252,
     254,   255,   257,   260,   270,   271,   272,   400,   401,   402,
     403,   404,   411,   413,   432,   443,   444,   445,   446,   447,
     467,   472,   473,   479,   487,   489,   503,   505,   509,   510,
     511,   181,   343,   487,   439,   487,     6,   487,   487,   438,
     363,   427,   193,   364,   365,   425,   484,   361,   460,   181,
     202,   297,   298,   472,   297,   297,   297,   256,   293,   294,
     296,   487,   292,   293,   295,   107,   218,   289,   364,   484,
     260,   260,   246,    50,   260,   245,   181,   181,   181,   333,
     378,   181,   181,    76,   334,   336,   246,   328,   329,    79,
     143,   146,   147,   148,   155,   159,   164,   171,   173,   174,
     176,   198,   208,   212,   219,   221,   230,   232,   270,   273,
     416,   417,   418,   419,   421,   458,   325,   326,   322,   323,
     265,   320,   260,   245,   181,   181,   181,   181,   168,   246,
     168,   430,   168,   246,   260,   192,   260,   426,   197,   457,
     466,   181,   260,     6,   181,   181,   181,   467,   157,   188,
     196,   213,   227,   236,   247,   433,   434,   197,   400,   472,
     467,   181,   181,   181,   225,   235,   474,   475,   181,   467,
     181,   181,   467,   467,   181,   181,   181,   181,   510,   403,
     181,   510,     3,   263,   241,   434,   434,   131,   152,   160,
     161,   166,   175,   178,   180,   190,   191,   211,   229,   254,
     261,   267,   268,   410,   412,   192,   260,    58,    84,    85,
      86,    87,    88,    89,   214,   223,   252,   257,   478,    96,
     344,   345,   487,   201,   341,   466,   264,   260,   245,   168,
     246,   246,   226,   470,   471,   472,   472,   168,   246,   168,
     294,   168,   246,   260,   426,   246,   190,   488,   400,   264,
     487,   487,   501,   487,     6,   487,   373,   375,   427,   377,
     427,   377,   168,   246,   334,   377,   400,   456,   487,   168,
     337,   168,   246,   181,   181,   181,   434,   434,   181,   181,
     181,   181,   181,   181,   181,   181,   116,   117,   118,   172,
     379,   381,   168,   246,   168,   246,   487,   487,     6,   487,
     314,   315,   487,   314,   314,   314,   133,   312,   317,    65,
      82,    83,   127,   261,   303,   304,   305,   427,   214,   487,
       3,   487,   468,   104,   369,   168,   472,   476,   487,    21,
     476,   476,   264,   468,   168,   168,   170,   472,   477,   503,
     156,   199,   240,   414,   476,   472,   400,   266,   475,   476,
     476,   476,   414,   476,   414,   414,   414,   401,   402,   264,
     181,   264,   408,   510,   408,   408,   408,   181,   467,   202,
     472,   408,   181,   467,   408,   130,   165,   167,   472,     3,
     181,   252,   257,   506,   508,   214,   272,   487,   472,   472,
     472,   472,   472,   416,   168,   246,   260,   342,   439,   487,
       6,   487,   427,   365,   364,   246,   461,   258,   487,   298,
     190,   293,   214,   487,   295,   298,   364,   260,   260,   168,
     246,   168,   246,   168,   378,   168,   168,   329,     3,   422,
     422,     3,   264,   181,   264,     3,   423,     3,     3,     3,
     423,   423,     3,     3,     6,   432,   108,   132,   141,   156,
     162,   199,   205,   372,   382,   383,   384,   385,   326,   322,
     260,   168,   246,   222,   243,   168,   168,   168,   303,     3,
       3,     4,   306,   305,   426,   177,   246,   260,   469,   168,
     246,   260,   168,   168,   157,   188,   196,   213,   227,   236,
     247,   435,   469,   246,   434,   246,   168,   246,   472,   168,
     233,   168,   168,   168,   472,   168,   472,   472,   472,   435,
       3,   435,   183,   405,   183,   407,   183,   406,   405,   252,
     432,   480,   481,   503,   407,   480,   406,   472,   506,   177,
     214,   223,   246,   252,   253,   257,   507,     3,   192,   260,
     345,   487,   181,   260,   471,   491,   487,   181,   260,   426,
     105,   258,   358,   487,   487,   372,   427,   427,   334,   168,
     168,   168,   246,   435,     3,   435,   246,   420,   168,   168,
     246,   168,   168,   420,   168,   168,   374,   484,   181,   384,
     334,   487,    44,    45,   261,   269,   307,   308,   309,   315,
     307,   307,   307,   312,     3,   487,   470,   472,   487,   181,
     470,   434,   264,   434,   434,   168,   472,   168,   168,   168,
     168,   168,   409,   432,   409,   409,     3,   489,   168,   246,
     168,   241,   168,   506,   506,   506,   487,   202,   346,   347,
     472,   487,   226,   393,   397,   297,   487,   425,     3,   168,
       3,   424,   168,     3,   168,   181,   456,   306,     3,   309,
     177,   426,   397,   192,     3,   397,   264,   435,   264,   264,
     264,   481,   472,   177,   177,   246,   192,   168,   246,   394,
     396,   484,   158,   186,   218,   391,   392,   398,   399,   453,
     217,   463,   168,   426,   168,   264,   168,   375,   168,   506,
     168,   168,   435,   435,   435,   435,   506,   506,   347,    33,
      40,   246,   258,   431,   487,     3,   256,   272,   428,   429,
     454,   455,   482,   487,   400,   400,   399,   391,   156,   199,
     240,   415,   153,   215,   448,   464,   435,   168,   177,   246,
     177,   177,   246,   181,   394,   395,   395,   216,   396,   431,
     429,   246,   260,   426,   197,   462,   465,   487,   259,   153,
     506,   506,   394,   262,   262,   181,   396,   455,   214,   487,
     468,   133,   313,     3,   428,   449,   450,   451,   465,   177,
     177,   168,   400,   400,   394,   426,   469,   246,   222,   243,
     452,   313,   168,   470,   450,   397,   463
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

/* Line 1455 of yacc.c  */
#line 487 "sql.yacc"
    {
		(yyval.ptr)=0;
	}
    break;

  case 4:

/* Line 1455 of yacc.c  */
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

/* Line 1455 of yacc.c  */
#line 507 "sql.yacc"
    {
		(yyval.ptr)=A4GL_new_select_list_item_expr((yyvsp[(2) - (2)].s_select_list_item));
	}
    break;

  case 6:

/* Line 1455 of yacc.c  */
#line 512 "sql.yacc"
    {
		(yyval.ptr)=0;
	}
    break;

  case 7:

/* Line 1455 of yacc.c  */
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

/* Line 1455 of yacc.c  */
#line 532 "sql.yacc"
    {
		 (yyval.ptr)=A4GL_new_select_list_item_expr((yyvsp[(2) - (2)].s_select_list_item));
	}
    break;

  case 9:

/* Line 1455 of yacc.c  */
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

  case 11:

/* Line 1455 of yacc.c  */
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

/* Line 1455 of yacc.c  */
#line 565 "sql.yacc"
    {
		(yyval.update_cmd)=(yyvsp[(2) - (2)].update_cmd);
		add_feature("UPDATE_COLUMN_EQ_VALUE_LIST");
    }
    break;

  case 13:

/* Line 1455 of yacc.c  */
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

/* Line 1455 of yacc.c  */
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

/* Line 1455 of yacc.c  */
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

/* Line 1455 of yacc.c  */
#line 649 "sql.yacc"
    {
		(yyval.update_cmd)=(yyvsp[(1) - (3)].update_cmd);
		add_str_list((yyval.update_cmd)->column_list, (yyvsp[(3) - (3)].upd_pair)->column_name);
		local_add_select_list_item_list((yyval.update_cmd)->value_list, (yyvsp[(3) - (3)].upd_pair)->value);
	}
    break;

  case 17:

/* Line 1455 of yacc.c  */
#line 660 "sql.yacc"
    {
                strcpy((yyval.str),(yyvsp[(1) - (1)].str));
        }
    break;

  case 18:

/* Line 1455 of yacc.c  */
#line 663 "sql.yacc"
    {
                strcpy((yyval.str),(yyvsp[(2) - (2)].str));
        }
    break;

  case 19:

/* Line 1455 of yacc.c  */
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

/* Line 1455 of yacc.c  */
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

/* Line 1455 of yacc.c  */
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

/* Line 1455 of yacc.c  */
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

/* Line 1455 of yacc.c  */
#line 730 "sql.yacc"
    {
		(yyval.upd_pair)=malloc(sizeof(struct s_update_pair));
		(yyval.upd_pair)->column_name=acl_strdup((yyvsp[(1) - (3)].str));
		(yyval.upd_pair)->value=(yyvsp[(3) - (3)].s_select_list_item);
	}
    break;

  case 24:

/* Line 1455 of yacc.c  */
#line 739 "sql.yacc"
    {
			(yyval.str_list)=new_str_list((yyvsp[(1) - (1)].str));
		}
    break;

  case 25:

/* Line 1455 of yacc.c  */
#line 742 "sql.yacc"
    {
			(yyval.str_list)=add_str_list((yyvsp[(1) - (3)].str_list), (yyvsp[(3) - (3)].str));
		}
    break;

  case 26:

/* Line 1455 of yacc.c  */
#line 750 "sql.yacc"
    { 
		(yyval.s_select_list_item_list)=local_new_select_list_item_list((yyvsp[(1) - (1)].s_select_list_item));
	}
    break;

  case 27:

/* Line 1455 of yacc.c  */
#line 753 "sql.yacc"
    { 
		(yyval.s_select_list_item_list)=local_add_select_list_item_list((yyvsp[(1) - (3)].s_select_list_item_list),(yyvsp[(3) - (3)].s_select_list_item));
	}
    break;

  case 28:

/* Line 1455 of yacc.c  */
#line 761 "sql.yacc"
    {(yyval.s_select_list_item)=(yyvsp[(1) - (1)].s_select_list_item);}
    break;

  case 29:

/* Line 1455 of yacc.c  */
#line 762 "sql.yacc"
    {(yyval.s_select_list_item)=new_select_list_item_builtin_const(E_SLI_BUILTIN_CONST_NULL); }
    break;

  case 30:

/* Line 1455 of yacc.c  */
#line 769 "sql.yacc"
    { (yyval.sql_string)=make_sql_string_and_free(acl_strdup((yyvsp[(1) - (1)].str)), NULL);}
    break;

  case 31:

/* Line 1455 of yacc.c  */
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

/* Line 1455 of yacc.c  */
#line 780 "sql.yacc"
    {SPRINTF2((yyval.str),"%s %s ",(yyvsp[(1) - (2)].str),(yyvsp[(2) - (2)].str));
			add_feature("DROP_VIEW");
}
    break;

  case 33:

/* Line 1455 of yacc.c  */
#line 783 "sql.yacc"
    {SPRINTF2((yyval.str),"%s %s",(yyvsp[(1) - (2)].str),(yyvsp[(2) - (2)].str));
		if (strchr((yyvsp[(2) - (2)].str),'@') || strchr((yyvsp[(2) - (2)].str),':')) add_feature("DROP_INDEX_QUALIFIED_PATH");
			add_feature("DROP_INDEX");
}
    break;

  case 34:

/* Line 1455 of yacc.c  */
#line 787 "sql.yacc"
    {SPRINTF2((yyval.str),"%s %s",(yyvsp[(1) - (2)].str),(yyvsp[(2) - (2)].str));
			add_feature("DROP_TRIGGER");
}
    break;

  case 35:

/* Line 1455 of yacc.c  */
#line 793 "sql.yacc"
    {(yyval.sql_string)=acl_strdup((yyvsp[(1) - (1)].str));}
    break;

  case 36:

/* Line 1455 of yacc.c  */
#line 794 "sql.yacc"
    {(yyval.sql_string)=(yyvsp[(1) - (1)].sql_string);}
    break;

  case 37:

/* Line 1455 of yacc.c  */
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

/* Line 1455 of yacc.c  */
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

/* Line 1455 of yacc.c  */
#line 822 "sql.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 40:

/* Line 1455 of yacc.c  */
#line 823 "sql.yacc"
    {strcpy((yyval.str),(yyvsp[(1) - (1)].str));}
    break;

  case 42:

/* Line 1455 of yacc.c  */
#line 828 "sql.yacc"
    {SPRINTF2((yyval.str),"%s%s",(yyvsp[(1) - (2)].str),(yyvsp[(2) - (2)].str)); }
    break;

  case 43:

/* Line 1455 of yacc.c  */
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

/* Line 1455 of yacc.c  */
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

/* Line 1455 of yacc.c  */
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

/* Line 1455 of yacc.c  */
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

/* Line 1455 of yacc.c  */
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

/* Line 1455 of yacc.c  */
#line 877 "sql.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 50:

/* Line 1455 of yacc.c  */
#line 877 "sql.yacc"
    {strcpy((yyval.str),(yyvsp[(1) - (1)].str));}
    break;

  case 52:

/* Line 1455 of yacc.c  */
#line 881 "sql.yacc"
    {SPRINTF2((yyval.str),"%s%s",(yyvsp[(1) - (2)].str),(yyvsp[(2) - (2)].str));}
    break;

  case 53:

/* Line 1455 of yacc.c  */
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

/* Line 1455 of yacc.c  */
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

/* Line 1455 of yacc.c  */
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

/* Line 1455 of yacc.c  */
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

/* Line 1455 of yacc.c  */
#line 915 "sql.yacc"
    { strcpy(last_tmp_name,(yyvsp[(1) - (1)].str)); }
    break;

  case 58:

/* Line 1455 of yacc.c  */
#line 919 "sql.yacc"
    {SPRINTF7((yyval.str),"CREATE UNIQUE INDEX %s %s %s %s %s %s %s",(yyvsp[(2) - (8)].str),(yyvsp[(3) - (8)].str),(yyvsp[(4) - (8)].str),(yyvsp[(5) - (8)].str),(yyvsp[(6) - (8)].str),(yyvsp[(7) - (8)].str),(yyvsp[(8) - (8)].str));
		add_feature("CREATE_INDEX");
		add_feature("CREATE_INDEX_UNIQUE");
		if (strchr((yyvsp[(2) - (8)].str),'@') || strchr((yyvsp[(2) - (8)].str),':')) add_feature("CREATE_INDEX_QUALIFIED_PATH");
		if (strchr((yyvsp[(6) - (8)].str),',')) { add_feature("CREATE_INDEX_COMPOSITE"); }
	
}
    break;

  case 59:

/* Line 1455 of yacc.c  */
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

/* Line 1455 of yacc.c  */
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

/* Line 1455 of yacc.c  */
#line 949 "sql.yacc"
    {
		if (strchr((yyvsp[(2) - (8)].str),'@') || strchr((yyvsp[(2) - (8)].str),':')) add_feature("CREATE_INDEX_QUALIFIED_PATH");
		if (strchr((yyvsp[(6) - (8)].str),',')) { add_feature("CREATE_INDEX_COMPOSITE"); }
			add_feature("CREATE_INDEX");
			SPRINTF7((yyval.str)," CREATE INDEX %s %s %s %s %s %s %s",(yyvsp[(2) - (8)].str),(yyvsp[(3) - (8)].str),(yyvsp[(4) - (8)].str),(yyvsp[(5) - (8)].str),(yyvsp[(6) - (8)].str),(yyvsp[(7) - (8)].str),(yyvsp[(8) - (8)].str));
	}
    break;

  case 62:

/* Line 1455 of yacc.c  */
#line 955 "sql.yacc"
    {
		add_feature("CREATE_DATABASE");
		a4gl_yyerror("You cannot create a database from within Aubit4gl - if the target database allows - prepare and execute it manually");
	}
    break;

  case 63:

/* Line 1455 of yacc.c  */
#line 959 "sql.yacc"
    {
		add_feature("DROP_DATABASE");
		a4gl_yyerror("You cannot drop a database from within Aubit4gl - if the target database allows - prepare and execute it manually");
	}
    break;

  case 64:

/* Line 1455 of yacc.c  */
#line 963 "sql.yacc"
    { 
		if (strchr((yyvsp[(2) - (4)].str),'@') || strchr((yyvsp[(2) - (4)].str),':')) add_feature("CREATE_SYNONYM_QUALIFIED_PATH");
			add_feature("CREATE_SYNONYM");
			SPRINTF3((yyval.str),"%s %s FOR %s",(yyvsp[(1) - (4)].str),(yyvsp[(2) - (4)].str),(yyvsp[(4) - (4)].str)); 
	}
    break;

  case 65:

/* Line 1455 of yacc.c  */
#line 968 "sql.yacc"
    { 
		add_feature("CREATE_AUDIT");
		SPRINTF2((yyval.str),"CREATE AUDIT FOR %s IN '%s'",(yyvsp[(2) - (4)].str),A4GL_strip_quotes((yyvsp[(4) - (4)].str))); 
	}
    break;

  case 66:

/* Line 1455 of yacc.c  */
#line 972 "sql.yacc"
    { 
		add_feature("DROP_AUDIT");
		SPRINTF1((yyval.str),"DROP AUDIT FOR %s",(yyvsp[(2) - (2)].str)); }
    break;

  case 67:

/* Line 1455 of yacc.c  */
#line 975 "sql.yacc"
    { 
		if (strchr((yyvsp[(2) - (2)].str),'@') || strchr((yyvsp[(2) - (2)].str),':')) add_feature("DROP_SYNONYM_QUALIFIED_PATH");
		add_feature("DROP_SYNONYM");
		SPRINTF2((yyval.str),"%s %s",(yyvsp[(1) - (2)].str),(yyvsp[(2) - (2)].str)); }
    break;

  case 68:

/* Line 1455 of yacc.c  */
#line 979 "sql.yacc"
    { 
		add_feature("RECOVER_TABLE");
		SPRINTF1((yyval.str),"RECOVER TABLE %s",(yyvsp[(2) - (2)].str)); }
    break;

  case 69:

/* Line 1455 of yacc.c  */
#line 982 "sql.yacc"
    { 
		add_feature("ROLLFORWARD_DATABASE");
		SPRINTF1((yyval.str),"ROLLFORWARD DATABASE %s",(yyvsp[(2) - (2)].str)); }
    break;

  case 70:

/* Line 1455 of yacc.c  */
#line 989 "sql.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 71:

/* Line 1455 of yacc.c  */
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

/* Line 1455 of yacc.c  */
#line 1000 "sql.yacc"
    {(yyval.integer_val)=0;}
    break;

  case 73:

/* Line 1455 of yacc.c  */
#line 1001 "sql.yacc"
    { (yyval.integer_val)=1;}
    break;

  case 75:

/* Line 1455 of yacc.c  */
#line 1006 "sql.yacc"
    {SPRINTF2((yyval.str),"%s,%s",(yyvsp[(1) - (3)].str),(yyvsp[(3) - (3)].str));}
    break;

  case 76:

/* Line 1455 of yacc.c  */
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

/* Line 1455 of yacc.c  */
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

/* Line 1455 of yacc.c  */
#line 1028 "sql.yacc"
    {
		strcpy((yyval.str),A4GL_confirm_colname(last_tmp_name,(yyvsp[(1) - (1)].str)));
}
    break;

  case 79:

/* Line 1455 of yacc.c  */
#line 1035 "sql.yacc"
    {
		(yyval.sql_string)=(yyvsp[(1) - (1)].sql_string);
	}
    break;

  case 80:

/* Line 1455 of yacc.c  */
#line 1038 "sql.yacc"
    {
		(yyval.sql_string)=make_sql_string_and_free((yyvsp[(1) - (3)].sql_string),kw_comma,strdup("\n"),(yyvsp[(3) - (3)].sql_string),NULL);
	}
    break;

  case 81:

/* Line 1455 of yacc.c  */
#line 1044 "sql.yacc"
    {
		(yyval.sql_string)=make_sql_string_and_free(strdup("   "),(yyvsp[(1) - (1)].sql_string),NULL);
	}
    break;

  case 82:

/* Line 1455 of yacc.c  */
#line 1047 "sql.yacc"
    {
		(yyval.sql_string)=make_sql_string_and_free(strdup("   "),(yyvsp[(1) - (1)].sql_string),NULL);
	}
    break;

  case 83:

/* Line 1455 of yacc.c  */
#line 1058 "sql.yacc"
    {
		add_feature("ALTER_TABLE");
	(yyval.sql_string)=make_sql_string_and_free(acl_strdup((yyvsp[(1) - (3)].str)),kw_space,acl_strdup((yyvsp[(2) - (3)].str)),kw_space,(yyvsp[(3) - (3)].sql_string),NULL);
	}
    break;

  case 84:

/* Line 1455 of yacc.c  */
#line 1062 "sql.yacc"
    {
		add_feature("CLUSTER_INDEX");
		add_feature("ALTER_INDEX_CLUSTER");
		(yyval.sql_string)=make_sql_string_and_free(acl_strdup("ALTER INDEX "),acl_strdup((yyvsp[(2) - (3)].str)),acl_strdup(" TO CLUSTER"),NULL);
		}
    break;

  case 85:

/* Line 1455 of yacc.c  */
#line 1067 "sql.yacc"
    {
		add_feature("ALTER_INDEX_NOT_CLUSTER");
		(yyval.sql_string)=make_sql_string_and_free(acl_strdup("ALTER INDEX "),acl_strdup((yyvsp[(2) - (3)].str)),acl_strdup(" TO NOT CLUSTER"),NULL);
		}
    break;

  case 86:

/* Line 1455 of yacc.c  */
#line 1074 "sql.yacc"
    {
		(yyval.sql_string)=(yyvsp[(1) - (1)].sql_string);
	}
    break;

  case 87:

/* Line 1455 of yacc.c  */
#line 1077 "sql.yacc"
    {
		(yyval.sql_string)=make_sql_string_and_free((yyvsp[(1) - (3)].sql_string),kw_comma,(yyvsp[(3) - (3)].sql_string),NULL);
	}
    break;

  case 88:

/* Line 1455 of yacc.c  */
#line 1086 "sql.yacc"
    {
		(yyval.sql_string)=(yyvsp[(1) - (1)].sql_string);
	}
    break;

  case 89:

/* Line 1455 of yacc.c  */
#line 1089 "sql.yacc"
    {
	add_feature("ALTER_TABLE_DROP");
		(yyval.sql_string)=acl_strdup((yyvsp[(1) - (1)].str));
	}
    break;

  case 90:

/* Line 1455 of yacc.c  */
#line 1093 "sql.yacc"
    {
	add_feature("ALTER_TABLE_MODIFY");
		(yyval.sql_string)=(yyvsp[(1) - (1)].sql_string);
	}
    break;

  case 91:

/* Line 1455 of yacc.c  */
#line 1097 "sql.yacc"
    {
		add_feature("ALTER_TABLE_ADD_CONSTRAINT");
		(yyval.sql_string)=acl_strdup((yyvsp[(1) - (1)].str));
	}
    break;

  case 92:

/* Line 1455 of yacc.c  */
#line 1101 "sql.yacc"
    {
		add_feature("ALTER_TABLE_DROP_CONSTRAINT");
		(yyval.sql_string)=acl_strdup((yyvsp[(1) - (1)].str));
	}
    break;

  case 93:

/* Line 1455 of yacc.c  */
#line 1105 "sql.yacc"
    {
		add_feature("ALTER_TABLE_MODIFY_NEXT");
		(yyval.sql_string)=acl_strdup((yyvsp[(1) - (1)].str));
	}
    break;

  case 94:

/* Line 1455 of yacc.c  */
#line 1109 "sql.yacc"
    {
		add_feature("ALTER_TABLE_LOCK_MODE");
		(yyval.sql_string)=acl_strdup((yyvsp[(1) - (1)].str));
	}
    break;

  case 95:

/* Line 1455 of yacc.c  */
#line 1117 "sql.yacc"
    {
		add_feature("ALTER_TABLE_ADD");
		(yyval.sql_string)=make_sql_string_and_free(acl_strdup("ADD "),(yyvsp[(2) - (2)].sql_string),NULL);
	}
    break;

  case 96:

/* Line 1455 of yacc.c  */
#line 1121 "sql.yacc"
    {
		add_feature("ALTER_TABLE_ADD");
		(yyval.sql_string)=make_sql_string_and_free(acl_strdup("ADD "),kw_ob,(yyvsp[(3) - (4)].sql_string),kw_cb,NULL);
	}
    break;

  case 97:

/* Line 1455 of yacc.c  */
#line 1129 "sql.yacc"
    {
		(yyval.sql_string)=(yyvsp[(1) - (1)].sql_string);
	}
    break;

  case 98:

/* Line 1455 of yacc.c  */
#line 1132 "sql.yacc"
    {
		add_feature("ALTER_TABLE_ADD_BEFORE");
		(yyval.sql_string)=make_sql_string_and_free((yyvsp[(1) - (3)].sql_string),acl_strdup(" BEFORE "),acl_strdup((yyvsp[(3) - (3)].str)),NULL);
	}
    break;

  case 99:

/* Line 1455 of yacc.c  */
#line 1139 "sql.yacc"
    {
		(yyval.sql_string)=(yyvsp[(1) - (1)].sql_string);
	}
    break;

  case 100:

/* Line 1455 of yacc.c  */
#line 1142 "sql.yacc"
    {
		(yyval.sql_string)=make_sql_string_and_free((yyvsp[(1) - (3)].sql_string),kw_comma,(yyvsp[(3) - (3)].sql_string),NULL);
	}
    break;

  case 101:

/* Line 1455 of yacc.c  */
#line 1149 "sql.yacc"
    {
		SPRINTF1((yyval.str),"DROP %s",(yyvsp[(2) - (2)].str));
	}
    break;

  case 102:

/* Line 1455 of yacc.c  */
#line 1152 "sql.yacc"
    {
		SPRINTF1((yyval.str),"DROP (%s)",(yyvsp[(3) - (4)].str));
	}
    break;

  case 104:

/* Line 1455 of yacc.c  */
#line 1160 "sql.yacc"
    {
		SPRINTF2((yyval.str),"%s,%s",(yyvsp[(1) - (3)].str),(yyvsp[(3) - (3)].str));
	}
    break;

  case 106:

/* Line 1455 of yacc.c  */
#line 1169 "sql.yacc"
    {
		(yyval.sql_string)=make_sql_string_and_free(acl_strdup("MODIFY "),(yyvsp[(2) - (2)].sql_string),NULL);
	}
    break;

  case 107:

/* Line 1455 of yacc.c  */
#line 1172 "sql.yacc"
    {
		(yyval.sql_string)=make_sql_string_and_free(acl_strdup("MODIFY "),kw_ob,(yyvsp[(3) - (4)].sql_string),kw_cb,NULL);
	}
    break;

  case 108:

/* Line 1455 of yacc.c  */
#line 1178 "sql.yacc"
    {
		(yyval.sql_string)=(yyvsp[(1) - (1)].sql_string);
	}
    break;

  case 109:

/* Line 1455 of yacc.c  */
#line 1181 "sql.yacc"
    {
		(yyval.sql_string)=make_sql_string_and_free((yyvsp[(1) - (3)].sql_string),kw_comma,(yyvsp[(3) - (3)].sql_string),NULL);
	}
    break;

  case 110:

/* Line 1455 of yacc.c  */
#line 1187 "sql.yacc"
    {
		(yyval.sql_string)=(yyvsp[(1) - (1)].sql_string);
	}
    break;

  case 111:

/* Line 1455 of yacc.c  */
#line 1194 "sql.yacc"
    {strcpy((yyval.str),"LOCK MODE (PAGE)");}
    break;

  case 112:

/* Line 1455 of yacc.c  */
#line 1195 "sql.yacc"
    {strcpy((yyval.str),"LOCK MODE (ROW)");}
    break;

  case 113:

/* Line 1455 of yacc.c  */
#line 1199 "sql.yacc"
    {
		add_feature("DDL_NEXT_SIZE");
		SPRINTF1((yyval.str),"MODIFY NEXT SIZE %d",atoi((yyvsp[(2) - (2)].str)));
	}
    break;

  case 114:

/* Line 1455 of yacc.c  */
#line 1207 "sql.yacc"
    {
		add_feature("DDL_CONSTRAINT");
		SPRINTF2((yyval.str),"ADD CONSTRAINT %s%s",(yyvsp[(2) - (3)].sql_string),(yyvsp[(3) - (3)].str));
	}
    break;

  case 115:

/* Line 1455 of yacc.c  */
#line 1211 "sql.yacc"
    {
		add_feature("ADD_CONSTRAINT");
		SPRINTF1((yyval.str),"ADD CONSTRAINT (%s)",(yyvsp[(3) - (4)].sql_string));
	}
    break;

  case 116:

/* Line 1455 of yacc.c  */
#line 1218 "sql.yacc"
    {
		(yyval.sql_string)=make_sql_string_and_free((yyvsp[(1) - (2)].sql_string),acl_strdup((yyvsp[(2) - (2)].str)),NULL);
}
    break;

  case 117:

/* Line 1455 of yacc.c  */
#line 1220 "sql.yacc"
    {
	(yyval.sql_string)=make_sql_string_and_free((yyvsp[(1) - (4)].sql_string),kw_comma,(yyvsp[(3) - (4)].sql_string),acl_strdup((yyvsp[(4) - (4)].str)), NULL);
}
    break;

  case 118:

/* Line 1455 of yacc.c  */
#line 1225 "sql.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 119:

/* Line 1455 of yacc.c  */
#line 1226 "sql.yacc"
    {SPRINTF2((yyval.str)," %s %s",(yyvsp[(1) - (2)].str),(yyvsp[(2) - (2)].str)); add_feature("DDL_CONSTRAINT");}
    break;

  case 120:

/* Line 1455 of yacc.c  */
#line 1231 "sql.yacc"
    { SPRINTF1((yyval.str),"DROP CONSTRAINT %s",(yyvsp[(2) - (2)].str)); add_feature("DROP_CONSTRAINT"); }
    break;

  case 121:

/* Line 1455 of yacc.c  */
#line 1232 "sql.yacc"
    {add_feature("DROP_CONSTRAINT");
		SPRINTF1((yyval.str),"DROP CONSTRAINT (%s)",(yyvsp[(3) - (4)].str));
	}
    break;

  case 122:

/* Line 1455 of yacc.c  */
#line 1238 "sql.yacc"
    {strcpy((yyval.str),(yyvsp[(1) - (1)].str));}
    break;

  case 123:

/* Line 1455 of yacc.c  */
#line 1239 "sql.yacc"
    {SPRINTF2((yyval.str),"%s,%s",(yyvsp[(1) - (3)].str),(yyvsp[(3) - (3)].str));}
    break;

  case 125:

/* Line 1455 of yacc.c  */
#line 1253 "sql.yacc"
    {  add_feature("ROLLBACK_WORK"); }
    break;

  case 126:

/* Line 1455 of yacc.c  */
#line 1259 "sql.yacc"
    { insql=1;}
    break;

  case 127:

/* Line 1455 of yacc.c  */
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

/* Line 1455 of yacc.c  */
#line 1268 "sql.yacc"
    {insql=1;}
    break;

  case 129:

/* Line 1455 of yacc.c  */
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

/* Line 1455 of yacc.c  */
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

/* Line 1455 of yacc.c  */
#line 1302 "sql.yacc"
    {
			(yyval.str_list)=0;
	}
    break;

  case 132:

/* Line 1455 of yacc.c  */
#line 1305 "sql.yacc"
    {
			(yyval.str_list)=(yyvsp[(2) - (3)].str_list);
			 add_feature("INSERT_COLUMNLIST_EQ_VALUELIST");
	}
    break;

  case 133:

/* Line 1455 of yacc.c  */
#line 1313 "sql.yacc"
    {
                        (yyval.str_list)=new_str_list((yyvsp[(1) - (1)].str));
	}
    break;

  case 134:

/* Line 1455 of yacc.c  */
#line 1316 "sql.yacc"
    {
                        (yyval.str_list)=add_str_list((yyvsp[(1) - (3)].str_list), (yyvsp[(3) - (3)].str));
	}
    break;

  case 135:

/* Line 1455 of yacc.c  */
#line 1323 "sql.yacc"
    {	
			strcpy((yyval.str),(yyvsp[(1) - (1)].str));
	}
    break;

  case 136:

/* Line 1455 of yacc.c  */
#line 1326 "sql.yacc"
    { 
			/* with a table prefix - on an insert ? We'll just silently drop it... */
			strcpy((yyval.str),(yyvsp[(3) - (3)].str));
			A4GL_warn("Dropped table prefix from INSERT column name");
	}
    break;

  case 137:

/* Line 1455 of yacc.c  */
#line 1334 "sql.yacc"
    { (yyval.s_select_list_item_list)=local_new_select_list_item_list((yyvsp[(1) - (1)].s_select_list_item));}
    break;

  case 138:

/* Line 1455 of yacc.c  */
#line 1335 "sql.yacc"
    {
		(yyval.s_select_list_item_list)=local_add_select_list_item_list((yyvsp[(1) - (3)].s_select_list_item_list),(yyvsp[(3) - (3)].s_select_list_item));
	}
    break;

  case 139:

/* Line 1455 of yacc.c  */
#line 1341 "sql.yacc"
    {(yyval.s_select_list_item)=(yyvsp[(1) - (1)].s_select_list_item);}
    break;

  case 140:

/* Line 1455 of yacc.c  */
#line 1342 "sql.yacc"
    {(yyval.s_select_list_item)=new_select_list_item_builtin_const(E_SLI_BUILTIN_CONST_NULL); }
    break;

  case 141:

/* Line 1455 of yacc.c  */
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

/* Line 1455 of yacc.c  */
#line 1368 "sql.yacc"
    { add_feature("BEGIN_WORK"); }
    break;

  case 143:

/* Line 1455 of yacc.c  */
#line 1372 "sql.yacc"
    { add_feature("COMMIT_WORK"); }
    break;

  case 144:

/* Line 1455 of yacc.c  */
#line 1377 "sql.yacc"
    {(yyval.e_boolean)=EB_FALSE;}
    break;

  case 145:

/* Line 1455 of yacc.c  */
#line 1378 "sql.yacc"
    {
		add_feature("DATABASE_EXCLUSIVE");
		{(yyval.e_boolean)=EB_TRUE;}
	}
    break;

  case 146:

/* Line 1455 of yacc.c  */
#line 1388 "sql.yacc"
    {
	char buff[256];
	(yyval.sql_string)=make_sql_string_and_free(acl_strdup((yyvsp[(1) - (1)].str)),NULL);
	SPRINTF1(buff,"Warning: Informix specific SQL @ line %d\n",yylineno);
	ansi_violation(buff,1);
	}
    break;

  case 147:

/* Line 1455 of yacc.c  */
#line 1397 "sql.yacc"
    {
			add_feature("START_DATABASE_WITH_LOG_MODE_ANSI");
			sprintf((yyval.str),"START DATABASE %s WITH LOG IN %s MODE ANSI", (yyvsp[(2) - (5)].str),(yyvsp[(4) - (5)].str));
	}
    break;

  case 148:

/* Line 1455 of yacc.c  */
#line 1401 "sql.yacc"
    {
			add_feature("START_DATABASE_WITH_LOG");
			sprintf((yyval.str),"START DATABASE %s WITH LOG IN %s", (yyvsp[(2) - (4)].str),(yyvsp[(4) - (4)].str));
	}
    break;

  case 149:

/* Line 1455 of yacc.c  */
#line 1406 "sql.yacc"
    {
			add_feature("SET_CONSTRAINTS_ALL_IMMEDIATE");
			SPRINTF1((yyval.str),"%s",(yyvsp[(1) - (1)].str)); 
	}
    break;

  case 150:

/* Line 1455 of yacc.c  */
#line 1410 "sql.yacc"
    {
		add_feature("SET_BUFFERED_LOG");
			SPRINTF1((yyval.str),"%s",(yyvsp[(1) - (1)].str)); 
	}
    break;

  case 151:

/* Line 1455 of yacc.c  */
#line 1414 "sql.yacc"
    {
		add_feature("SET_LOG");
			SPRINTF1((yyval.str),"%s",(yyvsp[(1) - (1)].str)); 
	}
    break;

  case 152:

/* Line 1455 of yacc.c  */
#line 1418 "sql.yacc"
    {
			SPRINTF2((yyval.str),"%s %s",(yyvsp[(1) - (2)].str),(yyvsp[(2) - (2)].str)); add_feature("UPDATE_STATISTICS_TABLE");
	}
    break;

  case 153:

/* Line 1455 of yacc.c  */
#line 1421 "sql.yacc"
    {
		add_feature("UPDATE_STATISTICS");
			SPRINTF1((yyval.str),"%s",(yyvsp[(1) - (1)].str)); 
	}
    break;

  case 154:

/* Line 1455 of yacc.c  */
#line 1428 "sql.yacc"
    { (yyval.integer_val)=1; }
    break;

  case 155:

/* Line 1455 of yacc.c  */
#line 1429 "sql.yacc"
    { (yyval.integer_val)=-1; }
    break;

  case 156:

/* Line 1455 of yacc.c  */
#line 1430 "sql.yacc"
    { (yyval.integer_val)=0; }
    break;

  case 157:

/* Line 1455 of yacc.c  */
#line 1434 "sql.yacc"
    { (yyval.sql_string)=(yyvsp[(1) - (1)].sql_string); }
    break;

  case 158:

/* Line 1455 of yacc.c  */
#line 1435 "sql.yacc"
    { (yyval.sql_string)=(yyvsp[(1) - (1)].sql_string); }
    break;

  case 159:

/* Line 1455 of yacc.c  */
#line 1436 "sql.yacc"
    { (yyval.sql_string)=(yyvsp[(1) - (1)].sql_string); }
    break;

  case 160:

/* Line 1455 of yacc.c  */
#line 1437 "sql.yacc"
    { (yyval.sql_string)=(yyvsp[(1) - (1)].sql_string); }
    break;

  case 161:

/* Line 1455 of yacc.c  */
#line 1438 "sql.yacc"
    { (yyval.sql_string)=(yyvsp[(1) - (1)].sql_string); }
    break;

  case 162:

/* Line 1455 of yacc.c  */
#line 1439 "sql.yacc"
    { (yyval.sql_string)=(yyvsp[(1) - (1)].sql_string); }
    break;

  case 163:

/* Line 1455 of yacc.c  */
#line 1440 "sql.yacc"
    { (yyval.sql_string)=(yyvsp[(1) - (1)].sql_string); }
    break;

  case 164:

/* Line 1455 of yacc.c  */
#line 1448 "sql.yacc"
    {SPRINTF7((yyval.str),"%s %s %s %s %s %s %s",(yyvsp[(1) - (7)].str),(yyvsp[(2) - (7)].str),(yyvsp[(3) - (7)].str),(yyvsp[(4) - (7)].str),(yyvsp[(5) - (7)].str),(yyvsp[(6) - (7)].str),(yyvsp[(7) - (7)].str));  add_feature("GRANT"); }
    break;

  case 165:

/* Line 1455 of yacc.c  */
#line 1449 "sql.yacc"
    {SPRINTF6((yyval.str),"%s %s %s %s %s %s",(yyvsp[(1) - (6)].str),(yyvsp[(2) - (6)].str),(yyvsp[(3) - (6)].str),(yyvsp[(4) - (6)].str),(yyvsp[(5) - (6)].str),(yyvsp[(6) - (6)].str));  add_feature("REVOKE"); }
    break;

  case 166:

/* Line 1455 of yacc.c  */
#line 1450 "sql.yacc"
    {SPRINTF4((yyval.str),"%s %s %s %s ",(yyvsp[(1) - (4)].str),(yyvsp[(2) - (4)].str),(yyvsp[(3) - (4)].str),(yyvsp[(4) - (4)].str)); add_feature("GRANT"); }
    break;

  case 167:

/* Line 1455 of yacc.c  */
#line 1451 "sql.yacc"
    {SPRINTF4((yyval.str),"%s %s %s %s ",(yyvsp[(1) - (4)].str),(yyvsp[(2) - (4)].str),(yyvsp[(3) - (4)].str),(yyvsp[(4) - (4)].str));  add_feature("REVOKE"); }
    break;

  case 171:

/* Line 1455 of yacc.c  */
#line 1461 "sql.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 172:

/* Line 1455 of yacc.c  */
#line 1462 "sql.yacc"
    {SPRINTF1((yyval.str)," %s ",(yyvsp[(1) - (1)].str));}
    break;

  case 173:

/* Line 1455 of yacc.c  */
#line 1463 "sql.yacc"
    {SPRINTF2((yyval.str)," %s %s",(yyvsp[(1) - (2)].str),(yyvsp[(2) - (2)].str));}
    break;

  case 174:

/* Line 1455 of yacc.c  */
#line 1467 "sql.yacc"
    {SPRINTF1((yyval.str)," %s ",(yyvsp[(1) - (1)].str));}
    break;

  case 175:

/* Line 1455 of yacc.c  */
#line 1468 "sql.yacc"
    {SPRINTF1((yyval.str)," %s ",(yyvsp[(1) - (1)].str));}
    break;

  case 178:

/* Line 1455 of yacc.c  */
#line 1475 "sql.yacc"
    {SPRINTF3((yyval.str)," %s %s %s",(yyvsp[(1) - (3)].str),(yyvsp[(2) - (3)].str),(yyvsp[(3) - (3)].str));}
    break;

  case 179:

/* Line 1455 of yacc.c  */
#line 1478 "sql.yacc"
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
#line 1487 "sql.yacc"
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
#line 1498 "sql.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 186:

/* Line 1455 of yacc.c  */
#line 1500 "sql.yacc"
    {SPRINTF3((yyval.str)," %s %s %s",(yyvsp[(1) - (3)].str),(yyvsp[(2) - (3)].str),(yyvsp[(3) - (3)].str));}
    break;

  case 188:

/* Line 1455 of yacc.c  */
#line 1506 "sql.yacc"
    {SPRINTF3((yyval.str)," %s %s %s",(yyvsp[(1) - (3)].str),(yyvsp[(2) - (3)].str),(yyvsp[(3) - (3)].str));}
    break;

  case 190:

/* Line 1455 of yacc.c  */
#line 1512 "sql.yacc"
    {SPRINTF3((yyval.str)," %s %s %s",(yyvsp[(1) - (3)].str),(yyvsp[(2) - (3)].str),(yyvsp[(3) - (3)].str));}
    break;

  case 193:

/* Line 1455 of yacc.c  */
#line 1522 "sql.yacc"
    {
		add_feature("CREATE_VIEW_AS_SELECT");
		(yyval.sql_string)=make_sql_string_and_free(acl_strdup((yyvsp[(1) - (6)].str)),kw_space,acl_strdup((yyvsp[(2) - (6)].str)),kw_space,acl_strdup((yyvsp[(3) - (6)].str)),kw_space,acl_strdup((yyvsp[(4) - (6)].str)),kw_space,(yyvsp[(5) - (6)].sql_string),kw_space,acl_strdup((yyvsp[(6) - (6)].str)),NULL);
	
}
    break;

  case 194:

/* Line 1455 of yacc.c  */
#line 1529 "sql.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 195:

/* Line 1455 of yacc.c  */
#line 1531 "sql.yacc"
    {SPRINTF3((yyval.str)," %s %s %s",(yyvsp[(1) - (3)].str),(yyvsp[(2) - (3)].str),(yyvsp[(3) - (3)].str));}
    break;

  case 197:

/* Line 1455 of yacc.c  */
#line 1537 "sql.yacc"
    {SPRINTF3((yyval.str)," %s %s %s",(yyvsp[(1) - (3)].str),(yyvsp[(2) - (3)].str),(yyvsp[(3) - (3)].str));}
    break;

  case 198:

/* Line 1455 of yacc.c  */
#line 1540 "sql.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 199:

/* Line 1455 of yacc.c  */
#line 1541 "sql.yacc"
    {
		add_feature("CREATE_VIEW_SELECT_WITH_CHECK");
	}
    break;

  case 200:

/* Line 1455 of yacc.c  */
#line 1548 "sql.yacc"
    {
		(yyval.sql_string)=make_sql_string_and_free(strdup("CHECK ("),(yyvsp[(3) - (4)].sql_string),kw_cb,NULL);
		add_feature("DDL_CHECK");
	}
    break;

  case 201:

/* Line 1455 of yacc.c  */
#line 1557 "sql.yacc"
    {SPRINTF5((yyval.str)," %s %s %s %s %s",(yyvsp[(1) - (5)].str),(yyvsp[(2) - (5)].str),(yyvsp[(3) - (5)].str),(yyvsp[(4) - (5)].str),(yyvsp[(5) - (5)].str));
	add_feature("DDL_FOREIGN_KEY");
}
    break;

  case 202:

/* Line 1455 of yacc.c  */
#line 1564 "sql.yacc"
    {SPRINTF2((yyval.str)," %s %s",(yyvsp[(1) - (2)].str),(yyvsp[(2) - (2)].str));
add_feature("DDL_REFERENCES");
}
    break;

  case 205:

/* Line 1455 of yacc.c  */
#line 1576 "sql.yacc"
    {SPRINTF4((yyval.str)," %s %s %s %s",(yyvsp[(1) - (4)].str),(yyvsp[(2) - (4)].str),(yyvsp[(3) - (4)].str),(yyvsp[(4) - (4)].str));}
    break;

  case 207:

/* Line 1455 of yacc.c  */
#line 1582 "sql.yacc"
    {SPRINTF3((yyval.str)," %s %s %s",(yyvsp[(1) - (3)].str),(yyvsp[(2) - (3)].str),(yyvsp[(3) - (3)].str));}
    break;

  case 208:

/* Line 1455 of yacc.c  */
#line 1587 "sql.yacc"
    {
		SPRINTF3((yyval.str)," UNIQUE %s %s %s",(yyvsp[(2) - (4)].str),(yyvsp[(3) - (4)].str),(yyvsp[(4) - (4)].str));
add_feature("DDL_UNIQUE");
	}
    break;

  case 209:

/* Line 1455 of yacc.c  */
#line 1591 "sql.yacc"
    {
		ansi_violation("Use UNIQUE not DISTINCT",0);
		SPRINTF3((yyval.str)," UNIQUE %s %s %s",(yyvsp[(2) - (4)].str),(yyvsp[(3) - (4)].str),(yyvsp[(4) - (4)].str));
add_feature("DDL_DISTINCT");
	}
    break;

  case 210:

/* Line 1455 of yacc.c  */
#line 1597 "sql.yacc"
    {SPRINTF4((yyval.str)," %s %s %s %s",(yyvsp[(1) - (4)].str),(yyvsp[(2) - (4)].str),(yyvsp[(3) - (4)].str),(yyvsp[(4) - (4)].str));
add_feature("DDL_PRIMARY_KEY");
}
    break;

  case 212:

/* Line 1455 of yacc.c  */
#line 1605 "sql.yacc"
    {SPRINTF3((yyval.str)," %s %s %s",(yyvsp[(1) - (3)].str),(yyvsp[(2) - (3)].str),(yyvsp[(3) - (3)].str));}
    break;

  case 213:

/* Line 1455 of yacc.c  */
#line 1610 "sql.yacc"
    {
		(yyval.sql_string)=acl_strdup((yyvsp[(1) - (1)].str));
	}
    break;

  case 214:

/* Line 1455 of yacc.c  */
#line 1613 "sql.yacc"
    {
		(yyval.sql_string)=acl_strdup((yyvsp[(1) - (1)].str));
	}
    break;

  case 215:

/* Line 1455 of yacc.c  */
#line 1616 "sql.yacc"
    {
		(yyval.sql_string)=(yyvsp[(1) - (1)].sql_string);
	}
    break;

  case 216:

/* Line 1455 of yacc.c  */
#line 1623 "sql.yacc"
    {SPRINTF2((yyval.str)," %s %s",(yyvsp[(1) - (2)].str),(yyvsp[(2) - (2)].str)); add_feature("DDL_DEFAULT_VALUE"); }
    break;

  case 217:

/* Line 1455 of yacc.c  */
#line 1624 "sql.yacc"
    {SPRINTF1((yyval.str)," DEFAULT %s", A4GLSQLCV_get_sqlconst("USER")); add_feature("DDL_DEFAULT_VALUE"); }
    break;

  case 218:

/* Line 1455 of yacc.c  */
#line 1625 "sql.yacc"
    {SPRINTF1((yyval.str)," DEFAULT %s", A4GLSQLCV_get_sqlconst("TODAY")); add_feature("DDL_DEFAULT_VALUE"); }
    break;

  case 219:

/* Line 1455 of yacc.c  */
#line 1626 "sql.yacc"
    { SPRINTF1((yyval.str)," %s",(yyvsp[(1) - (1)].str)); add_feature("DDL_DEFAULT_VALUE"); }
    break;

  case 220:

/* Line 1455 of yacc.c  */
#line 1632 "sql.yacc"
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
#line 1655 "sql.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 223:

/* Line 1455 of yacc.c  */
#line 1659 "sql.yacc"
    {
		(yyval.sql_string)=acl_strdup("");
	}
    break;

  case 224:

/* Line 1455 of yacc.c  */
#line 1661 "sql.yacc"
    {
		(yyval.sql_string)=(yyvsp[(1) - (1)].sql_string);
	}
    break;

  case 225:

/* Line 1455 of yacc.c  */
#line 1668 "sql.yacc"
    {
		(yyval.sql_string)=(yyvsp[(1) - (1)].sql_string);
	}
    break;

  case 226:

/* Line 1455 of yacc.c  */
#line 1671 "sql.yacc"
    {
		(yyval.sql_string)=make_sql_string_and_free((yyvsp[(1) - (2)].sql_string),kw_space,(yyvsp[(2) - (2)].sql_string),NULL);
	}
    break;

  case 227:

/* Line 1455 of yacc.c  */
#line 1677 "sql.yacc"
    {
		(yyval.sql_string)=make_sql_string_and_free((yyvsp[(1) - (2)].sql_string),acl_strdup((yyvsp[(2) - (2)].str)),NULL);
	}
    break;

  case 228:

/* Line 1455 of yacc.c  */
#line 1685 "sql.yacc"
    {
		SPRINTF1((yyval.str)," %s ",(yyvsp[(1) - (1)].str));
		(yyval.sql_string)=acl_strdup((yyval.str));
		add_feature("DDL_NOT_NULL");
	}
    break;

  case 229:

/* Line 1455 of yacc.c  */
#line 1690 "sql.yacc"
    {
		SPRINTF0((yyval.str)," NOT NULL UNIQUE ");
		(yyval.sql_string)=acl_strdup((yyval.str));
		add_feature("DDL_NOT_NULL");
		add_feature("DDL_UNIQUE");
	}
    break;

  case 230:

/* Line 1455 of yacc.c  */
#line 1696 "sql.yacc"
    {
		SPRINTF0((yyval.str)," UNIQUE ");
		(yyval.sql_string)=acl_strdup((yyval.str));
		add_feature("DDL_UNIQUE");
	}
    break;

  case 231:

/* Line 1455 of yacc.c  */
#line 1701 "sql.yacc"
    {
		ansi_violation("Use UNIQUE not DISTINCT",0);
		SPRINTF0((yyval.str)," UNIQUE ");
		(yyval.sql_string)=acl_strdup((yyval.str));
		add_feature("DDL_DISTINCT");
	}
    break;

  case 232:

/* Line 1455 of yacc.c  */
#line 1707 "sql.yacc"
    {
		(yyval.sql_string)=acl_strdup((yyvsp[(1) - (1)].str));
	}
    break;

  case 233:

/* Line 1455 of yacc.c  */
#line 1710 "sql.yacc"
    {
		(yyval.sql_string)=make_sql_string_and_free(acl_strdup("CHECK ("),(yyvsp[(3) - (4)].sql_string),kw_cb,NULL);
		add_feature("DDL_CHECK");
		
	}
    break;

  case 234:

/* Line 1455 of yacc.c  */
#line 1715 "sql.yacc"
    {
		(yyval.sql_string)=make_sql_string_and_free(acl_strdup(" PRIMARY KEY "),NULL);
		add_feature("DDL_PRIMARY_KEY");
	}
    break;

  case 235:

/* Line 1455 of yacc.c  */
#line 1724 "sql.yacc"
    {
		add_feature("CREATE_SCHEMA");

(yyval.sql_string)=make_sql_string_and_free(acl_strdup((yyvsp[(1) - (3)].str)),kw_space,acl_strdup((yyvsp[(2) - (3)].str)),kw_space,acl_strdup((yyvsp[(3) - (3)].str)),NULL);
}
    break;

  case 236:

/* Line 1455 of yacc.c  */
#line 1733 "sql.yacc"
    {SPRINTF1((yyval.str)," %s",(yyvsp[(1) - (1)].str));}
    break;

  case 239:

/* Line 1455 of yacc.c  */
#line 1742 "sql.yacc"
    {
		(yyval.sql_string)=make_sql_string_and_free((yyvsp[(1) - (2)].sql_string),kw_space,(yyvsp[(2) - (2)].sql_string),NULL);
	}
    break;

  case 240:

/* Line 1455 of yacc.c  */
#line 1748 "sql.yacc"
    {
		(yyval.sql_string)=(yyvsp[(1) - (1)].sql_string);
	}
    break;

  case 241:

/* Line 1455 of yacc.c  */
#line 1751 "sql.yacc"
    {
		(yyval.sql_string)=acl_strdup((yyvsp[(1) - (1)].str));
	}
    break;

  case 242:

/* Line 1455 of yacc.c  */
#line 1762 "sql.yacc"
    {
		 add_feature("HAVING"); 
		(yyval.s_select_list_item)=(yyvsp[(2) - (2)].s_select_list_item);
	}
    break;

  case 243:

/* Line 1455 of yacc.c  */
#line 1771 "sql.yacc"
    {
		 (yyval.s_select_list_item)=(yyvsp[(2) - (2)].s_select_list_item);
	}
    break;

  case 244:

/* Line 1455 of yacc.c  */
#line 1778 "sql.yacc"
    {
		(yyval.u_table)=(yyvsp[(2) - (2)].u_table);
	}
    break;

  case 245:

/* Line 1455 of yacc.c  */
#line 1784 "sql.yacc"
    {(yyval.u_table)=(yyvsp[(1) - (1)].u_table);}
    break;

  case 246:

/* Line 1455 of yacc.c  */
#line 1785 "sql.yacc"
    {
		(yyval.u_table)=A4GLSQLPARSE_append_tablename((yyvsp[(1) - (3)].u_table),(yyvsp[(3) - (3)].u_table),E_OUTER_NONE,NULL);
	}
    break;

  case 247:

/* Line 1455 of yacc.c  */
#line 1788 "sql.yacc"
    {
		(yyval.u_table)=A4GLSQLPARSE_append_tablename((yyvsp[(1) - (4)].u_table),(yyvsp[(4) - (4)].u_table),E_OUTER_NORMAL,NULL);
		A4GL_warn("OUTER join *may* not be portable to non-informix database");
		add_feature("SELECT_OUTER");
	}
    break;

  case 248:

/* Line 1455 of yacc.c  */
#line 1793 "sql.yacc"
    {
		(yyval.u_table)=A4GLSQLPARSE_append_tablename((yyvsp[(1) - (6)].u_table),(yyvsp[(5) - (6)].u_table),E_OUTER_NORMAL,NULL);
		A4GL_warn("OUTER join *may* not be portable to non-informix database");
		add_feature("SELECT_OUTER");
	}
    break;

  case 249:

/* Line 1455 of yacc.c  */
#line 1804 "sql.yacc"
    {
		(yyval.u_table)=A4GLSQLPARSE_append_tablename((yyvsp[(1) - (5)].u_table),(yyvsp[(3) - (5)].u_table),E_OUTER_LEFT_OUTER, (yyvsp[(5) - (5)].s_select_list_item));
		add_feature("SELECT_OUTER");
	}
    break;

  case 250:

/* Line 1455 of yacc.c  */
#line 1808 "sql.yacc"
    {
		(yyval.u_table)=A4GLSQLPARSE_append_tablename((yyvsp[(1) - (5)].u_table),(yyvsp[(3) - (5)].u_table),E_INNER, (yyvsp[(5) - (5)].s_select_list_item));
		add_feature("SELECT_INNER");
	}
    break;

  case 252:

/* Line 1455 of yacc.c  */
#line 1816 "sql.yacc"
    {(yyval.u_table)=(yyvsp[(2) - (3)].u_table);}
    break;

  case 253:

/* Line 1455 of yacc.c  */
#line 1820 "sql.yacc"
    { 
			//A4GL_add_crud("SELECT",$<str>1);
			(yyval.u_table)=A4GLSQLPARSE_new_tablename((yyvsp[(1) - (1)].str),NULL);
	}
    break;

  case 254:

/* Line 1455 of yacc.c  */
#line 1824 "sql.yacc"
    { 
			//A4GL_add_crud("SELECT",$<str>1);
			(yyval.u_table)=A4GLSQLPARSE_new_tablename((yyvsp[(1) - (2)].str),(yyvsp[(2) - (2)].str));
	}
    break;

  case 255:

/* Line 1455 of yacc.c  */
#line 1828 "sql.yacc"
    { 
			//A4GL_add_crud("SELECT",$<str>1);
			(yyval.u_table)=A4GLSQLPARSE_new_tablename((yyvsp[(1) - (3)].str),(yyvsp[(3) - (3)].str));
	}
    break;

  case 256:

/* Line 1455 of yacc.c  */
#line 1835 "sql.yacc"
    {
			/* No from or where etc.. */
			/* eg.. select user ; */
			(yyval.s_select)=new_empty_select();
		}
    break;

  case 257:

/* Line 1455 of yacc.c  */
#line 1840 "sql.yacc"
    {
		(yyval.s_select)=(yyvsp[(2) - (2)].s_select);
		(yyval.s_select)->first=(yyvsp[(1) - (2)].u_table);
			A4GL_set_associated_mem( (yyval.s_select), (yyval.s_select)->first);
}
    break;

  case 258:

/* Line 1455 of yacc.c  */
#line 1848 "sql.yacc"
    {
		(yyval.s_select)=(yyvsp[(1) - (1)].s_select);
	}
    break;

  case 259:

/* Line 1455 of yacc.c  */
#line 1851 "sql.yacc"
    {
		(yyval.s_select)=(yyvsp[(2) - (2)].s_select);
		(yyval.s_select)->where_clause=(yyvsp[(1) - (2)].s_select_list_item);
	}
    break;

  case 260:

/* Line 1455 of yacc.c  */
#line 1857 "sql.yacc"
    {
		(yyval.s_select)=new_empty_select();
	}
    break;

  case 261:

/* Line 1455 of yacc.c  */
#line 1860 "sql.yacc"
    {
		(yyval.s_select)=new_empty_select();
		(yyval.s_select)->group_by=(yyvsp[(1) - (1)].s_select_list_item_list);
		(yyval.s_select)->having=0;
	}
    break;

  case 262:

/* Line 1455 of yacc.c  */
#line 1865 "sql.yacc"
    {
		(yyval.s_select)=new_empty_select();
		(yyval.s_select)->group_by=(yyvsp[(1) - (2)].s_select_list_item_list);
		(yyval.s_select)->having=(yyvsp[(2) - (2)].s_select_list_item);
	}
    break;

  case 263:

/* Line 1455 of yacc.c  */
#line 1870 "sql.yacc"
    {
		(yyval.s_select)=new_empty_select();
		(yyval.s_select)->group_by=0;
		(yyval.s_select)->having=(yyvsp[(1) - (1)].s_select_list_item);

	}
    break;

  case 264:

/* Line 1455 of yacc.c  */
#line 1883 "sql.yacc"
    {
		(yyval.s_select_list_item)=(yyvsp[(1) - (1)].s_select_list_item);
	}
    break;

  case 265:

/* Line 1455 of yacc.c  */
#line 1886 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_op_expr((yyvsp[(1) - (3)].s_select_list_item),(yyvsp[(3) - (3)].s_select_list_item)," OR ");
	}
    break;

  case 266:

/* Line 1455 of yacc.c  */
#line 1892 "sql.yacc"
    {
		(yyval.s_select_list_item)=(yyvsp[(1) - (1)].s_select_list_item);
	}
    break;

  case 267:

/* Line 1455 of yacc.c  */
#line 1895 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_op_expr((yyvsp[(1) - (3)].s_select_list_item),(yyvsp[(3) - (3)].s_select_list_item)," AND ");
	}
    break;

  case 268:

/* Line 1455 of yacc.c  */
#line 1901 "sql.yacc"
    {
		(yyval.s_select_list_item)=(yyvsp[(1) - (1)].s_select_list_item);
	}
    break;

  case 269:

/* Line 1455 of yacc.c  */
#line 1904 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_simple_expr(E_SLI_NOT,(yyvsp[(2) - (2)].s_select_list_item));
	}
    break;

  case 270:

/* Line 1455 of yacc.c  */
#line 1910 "sql.yacc"
    {
		(yyval.s_select_list_item)=(yyvsp[(1) - (1)].s_select_list_item);
	}
    break;

  case 271:

/* Line 1455 of yacc.c  */
#line 1913 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_simple_expr(E_SLI_BRACKET_EXPR,(yyvsp[(2) - (3)].s_select_list_item));
	}
    break;

  case 272:

/* Line 1455 of yacc.c  */
#line 1920 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_sq(E_SQE_EXISTS, (yyvsp[(2) - (2)].s_select_list_item));
		add_feature("WHERE_EXISTS");
	}
    break;

  case 273:

/* Line 1455 of yacc.c  */
#line 1924 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_sq(E_SQE_NOT_EXISTS, (yyvsp[(2) - (2)].s_select_list_item));
		add_feature("WHERE_EXISTS");
	}
    break;

  case 274:

/* Line 1455 of yacc.c  */
#line 1935 "sql.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 275:

/* Line 1455 of yacc.c  */
#line 1935 "sql.yacc"
    {SPRINTF1((yyval.str)," ESCAPE %s",(yyvsp[(2) - (2)].str));add_feature("WHERE_MATCHES_ESCAPE");}
    break;

  case 276:

/* Line 1455 of yacc.c  */
#line 1936 "sql.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 277:

/* Line 1455 of yacc.c  */
#line 1936 "sql.yacc"
    {SPRINTF1((yyval.str)," ESCAPE %s",(yyvsp[(2) - (2)].str));add_feature("WHERE_ILIKE_ESCAPE");}
    break;

  case 278:

/* Line 1455 of yacc.c  */
#line 1937 "sql.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 279:

/* Line 1455 of yacc.c  */
#line 1937 "sql.yacc"
    {SPRINTF1((yyval.str)," ESCAPE %s",(yyvsp[(2) - (2)].str));add_feature("WHERE_LIKE_ESCAPE");}
    break;

  case 280:

/* Line 1455 of yacc.c  */
#line 1940 "sql.yacc"
    {
		 (yyval.s_select_list_item)=(yyvsp[(1) - (1)].s_select_list_item);
	}
    break;

  case 282:

/* Line 1455 of yacc.c  */
#line 1950 "sql.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 283:

/* Line 1455 of yacc.c  */
#line 1951 "sql.yacc"
    {strcpy((yyval.str)," NOT ");}
    break;

  case 284:

/* Line 1455 of yacc.c  */
#line 1956 "sql.yacc"
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
#line 1965 "sql.yacc"
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
#line 1973 "sql.yacc"
    { 
			(yyval.s_select_list_item)=new_select_list_item_op_expr((yyvsp[(1) - (3)].s_select_list_item),(yyvsp[(3) - (3)].s_select_list_item),(yyvsp[(2) - (3)].str));
	}
    break;

  case 287:

/* Line 1455 of yacc.c  */
#line 1976 "sql.yacc"
    { 
			(yyval.s_select_list_item)=new_select_list_item_op_expr((yyvsp[(1) - (3)].s_select_list_item),(yyvsp[(3) - (3)].s_select_list_item),"=");
	}
    break;

  case 288:

/* Line 1455 of yacc.c  */
#line 1979 "sql.yacc"
    { 
			FPRINTF(stderr,"Warning: Corrected =NULL to IS NULL line %d\n",yylineno);
			(yyval.s_select_list_item)=new_select_list_item_simple_expr(E_SLI_ISNULL,(yyvsp[(1) - (3)].s_select_list_item));
	}
    break;

  case 289:

/* Line 1455 of yacc.c  */
#line 1983 "sql.yacc"
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
#line 1990 "sql.yacc"
    { 
			(yyval.s_select_list_item)=new_select_list_item_regex(E_SLI_REGEX_LIKE,(yyvsp[(1) - (4)].s_select_list_item),(yyvsp[(3) - (4)].s_select_list_item),(yyvsp[(4) - (4)].str));
	}
    break;

  case 291:

/* Line 1455 of yacc.c  */
#line 1993 "sql.yacc"
    { 
			(yyval.s_select_list_item)=new_select_list_item_regex(E_SLI_REGEX_NOT_LIKE,(yyvsp[(1) - (4)].s_select_list_item),(yyvsp[(3) - (4)].s_select_list_item),(yyvsp[(4) - (4)].str));

	}
    break;

  case 292:

/* Line 1455 of yacc.c  */
#line 1997 "sql.yacc"
    { 
			(yyval.s_select_list_item)=new_select_list_item_regex(E_SLI_REGEX_ILIKE,(yyvsp[(1) - (4)].s_select_list_item),(yyvsp[(3) - (4)].s_select_list_item),(yyvsp[(4) - (4)].str));
	}
    break;

  case 293:

/* Line 1455 of yacc.c  */
#line 2000 "sql.yacc"
    { 
			(yyval.s_select_list_item)=new_select_list_item_regex(E_SLI_REGEX_NOT_ILIKE,(yyvsp[(1) - (4)].s_select_list_item),(yyvsp[(3) - (4)].s_select_list_item),(yyvsp[(4) - (4)].str));
	}
    break;

  case 294:

/* Line 1455 of yacc.c  */
#line 2003 "sql.yacc"
    { 
			(yyval.s_select_list_item)=new_select_list_item_regex(E_SLI_REGEX_MATCHES,(yyvsp[(1) - (4)].s_select_list_item),(yyvsp[(3) - (4)].s_select_list_item),(yyvsp[(4) - (4)].str));
	}
    break;

  case 295:

/* Line 1455 of yacc.c  */
#line 2006 "sql.yacc"
    { 
			(yyval.s_select_list_item)=new_select_list_item_regex(E_SLI_REGEX_NOT_MATCHES,(yyvsp[(1) - (4)].s_select_list_item),(yyvsp[(3) - (4)].s_select_list_item),(yyvsp[(4) - (4)].str));
	}
    break;

  case 296:

/* Line 1455 of yacc.c  */
#line 2012 "sql.yacc"
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
#line 2019 "sql.yacc"
    {
			strcpy((yyval.str)," < ");
	}
    break;

  case 298:

/* Line 1455 of yacc.c  */
#line 2022 "sql.yacc"
    {
			strcpy((yyval.str)," > ");
	}
    break;

  case 299:

/* Line 1455 of yacc.c  */
#line 2025 "sql.yacc"
    {
			strcpy((yyval.str)," ~ ");
	}
    break;

  case 300:

/* Line 1455 of yacc.c  */
#line 2028 "sql.yacc"
    {strcpy((yyval.str)," <= ");}
    break;

  case 301:

/* Line 1455 of yacc.c  */
#line 2029 "sql.yacc"
    {strcpy((yyval.str)," >= ");}
    break;

  case 302:

/* Line 1455 of yacc.c  */
#line 2034 "sql.yacc"
    {
		(yyval.s_select_list_item)=(yyvsp[(1) - (1)].s_select_list_item);
	}
    break;

  case 303:

/* Line 1455 of yacc.c  */
#line 2037 "sql.yacc"
    {
		(yyval.s_select_list_item)=(yyvsp[(1) - (1)].s_select_list_item);
	}
    break;

  case 304:

/* Line 1455 of yacc.c  */
#line 2040 "sql.yacc"
    {
		(yyval.s_select_list_item)=(yyvsp[(1) - (1)].s_select_list_item);
	}
    break;

  case 305:

/* Line 1455 of yacc.c  */
#line 2043 "sql.yacc"
    {
                 (yyval.s_select_list_item)=(yyvsp[(1) - (1)].s_select_list_item);
        }
    break;

  case 306:

/* Line 1455 of yacc.c  */
#line 2050 "sql.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 307:

/* Line 1455 of yacc.c  */
#line 2051 "sql.yacc"
    {strcpy((yyval.str)," ALL "); add_feature("AGG_ALL");}
    break;

  case 308:

/* Line 1455 of yacc.c  */
#line 2052 "sql.yacc"
    {
		strcpy((yyval.str)," DISTINCT ");
		add_feature("AGG_DISTINCT");
	}
    break;

  case 309:

/* Line 1455 of yacc.c  */
#line 2056 "sql.yacc"
    {
		ansi_violation("Use DISTINCT not UNIQUE",0);
		strcpy((yyval.str)," DISTINCT ");
		add_feature("AGG_DISTINCT");
	}
    break;

  case 310:

/* Line 1455 of yacc.c  */
#line 2063 "sql.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 311:

/* Line 1455 of yacc.c  */
#line 2064 "sql.yacc"
    {strcpy((yyval.str)," ALL "); add_feature("UNION_ALL");}
    break;

  case 312:

/* Line 1455 of yacc.c  */
#line 2065 "sql.yacc"
    {
		strcpy((yyval.str)," DISTINCT ");
		add_feature("UNION_DISTINCT");
	}
    break;

  case 313:

/* Line 1455 of yacc.c  */
#line 2069 "sql.yacc"
    {
		ansi_violation("Use DISTINCT not UNIQUE",0);
		add_feature("UNION_DISTINCT");
		strcpy((yyval.str)," DISTINCT ");
	}
    break;

  case 314:

/* Line 1455 of yacc.c  */
#line 2083 "sql.yacc"
    {
		strcpy((yyval.str),A4GLSQLCV_dtype_alias((yyvsp[(1) - (1)].str)));
	}
    break;

  case 319:

/* Line 1455 of yacc.c  */
#line 2098 "sql.yacc"
    {SPRINTF4((yyval.str)," %s %s%s%s",(yyvsp[(1) - (4)].str),(yyvsp[(2) - (4)].str),(yyvsp[(3) - (4)].str),(yyvsp[(4) - (4)].str));}
    break;

  case 320:

/* Line 1455 of yacc.c  */
#line 2102 "sql.yacc"
    {strcpy((yyval.str),"SERIAL"); add_feature("DDL_SERIAL"); }
    break;

  case 321:

/* Line 1455 of yacc.c  */
#line 2103 "sql.yacc"
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
#line 2112 "sql.yacc"
    {strcpy((yyval.str),"SERIAL8"); add_feature("DDL_SERIAL8"); }
    break;

  case 323:

/* Line 1455 of yacc.c  */
#line 2114 "sql.yacc"
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
#line 2123 "sql.yacc"
    {
 			add_feature("DDL_DECIMAL");
	}
    break;

  case 325:

/* Line 1455 of yacc.c  */
#line 2126 "sql.yacc"
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
#line 2134 "sql.yacc"
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
#line 2144 "sql.yacc"
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
#line 2152 "sql.yacc"
    {strcpy((yyval.str),"DATE");
 			add_feature("DDL_DATE"); }
    break;

  case 329:

/* Line 1455 of yacc.c  */
#line 2154 "sql.yacc"
    {strcpy((yyval.str),"INTEGER");}
    break;

  case 330:

/* Line 1455 of yacc.c  */
#line 2155 "sql.yacc"
    {strcpy((yyval.str),"SMALLINT");}
    break;

  case 331:

/* Line 1455 of yacc.c  */
#line 2156 "sql.yacc"
    {strcpy((yyval.str),"NCHAR"); add_feature("DDL_NCHAR");}
    break;

  case 332:

/* Line 1455 of yacc.c  */
#line 2157 "sql.yacc"
    {SPRINTF1((yyval.str),"NCHAR(%s)",(yyvsp[(3) - (4)].str)); add_feature("DDL_NCHAR");}
    break;

  case 333:

/* Line 1455 of yacc.c  */
#line 2158 "sql.yacc"
    {add_feature("DDL_NVARCHAR");}
    break;

  case 334:

/* Line 1455 of yacc.c  */
#line 2159 "sql.yacc"
    {SPRINTF1((yyval.str),"NVARCHAR(%s)",(yyvsp[(3) - (4)].str)); add_feature("DDL_NVARCHAR");}
    break;

  case 335:

/* Line 1455 of yacc.c  */
#line 2160 "sql.yacc"
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
#line 2168 "sql.yacc"
    {SPRINTF2((yyval.str),"DATETIME %s TO %s",(yyvsp[(2) - (4)].str),(yyvsp[(4) - (4)].str)); add_feature("DDL_DATETIME");}
    break;

  case 337:

/* Line 1455 of yacc.c  */
#line 2169 "sql.yacc"
    {add_feature("DDL_DATETIME");}
    break;

  case 338:

/* Line 1455 of yacc.c  */
#line 2170 "sql.yacc"
    {SPRINTF2((yyval.str),"INTERVAL %s TO %s",(yyvsp[(2) - (4)].str),(yyvsp[(4) - (4)].str)); add_feature("DDL_INTERVAL");}
    break;

  case 339:

/* Line 1455 of yacc.c  */
#line 2171 "sql.yacc"
    {strcpy((yyval.str),(yyvsp[(1) - (1)].str));}
    break;

  case 340:

/* Line 1455 of yacc.c  */
#line 2172 "sql.yacc"
    {add_feature("DDL_INTERVAL");}
    break;

  case 341:

/* Line 1455 of yacc.c  */
#line 2173 "sql.yacc"
    {SPRINTF3((yyval.str),"INTERVAL %s(%s) TO %s",(yyvsp[(2) - (7)].str),(yyvsp[(4) - (7)].str),(yyvsp[(7) - (7)].str)); add_feature("DDL_INTERVAL");}
    break;

  case 342:

/* Line 1455 of yacc.c  */
#line 2174 "sql.yacc"
    {add_feature("DDL_TEXT");}
    break;

  case 343:

/* Line 1455 of yacc.c  */
#line 2175 "sql.yacc"
    {add_feature("DDL_BYTE");}
    break;

  case 344:

/* Line 1455 of yacc.c  */
#line 2176 "sql.yacc"
    {add_feature("DDL_VARCHAR");}
    break;

  case 345:

/* Line 1455 of yacc.c  */
#line 2177 "sql.yacc"
    {SPRINTF1((yyval.str),"VARCHAR(%s)",(yyvsp[(3) - (4)].str));add_feature("DDL_VARCHAR");}
    break;

  case 346:

/* Line 1455 of yacc.c  */
#line 2178 "sql.yacc"
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
#line 2188 "sql.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 348:

/* Line 1455 of yacc.c  */
#line 2189 "sql.yacc"
    {
		SPRINTF1((yyval.str),",%s",(yyvsp[(2) - (2)].str));
}
    break;

  case 349:

/* Line 1455 of yacc.c  */
#line 2196 "sql.yacc"
    {SPRINTF4((yyval.str)," %s %s %s %s",(yyvsp[(1) - (4)].str),(yyvsp[(2) - (4)].str),(yyvsp[(3) - (4)].str),(yyvsp[(4) - (4)].str));}
    break;

  case 353:

/* Line 1455 of yacc.c  */
#line 2200 "sql.yacc"
    {add_feature("DDL_DOUBLE_PRECISION"); SPRINTF1((yyval.str)," %s",(yyvsp[(1) - (1)].str));}
    break;

  case 359:

/* Line 1455 of yacc.c  */
#line 2225 "sql.yacc"
    {(yyval.int_list.i0)=0;}
    break;

  case 360:

/* Line 1455 of yacc.c  */
#line 2226 "sql.yacc"
    {
		(yyval.int_list.i0)=1;
		(yyval.int_list.i1)=atoi((yyvsp[(2) - (3)].str));
	}
    break;

  case 361:

/* Line 1455 of yacc.c  */
#line 2230 "sql.yacc"
    {
		(yyval.int_list.i0)=2;
		(yyval.int_list.i1)=atoi((yyvsp[(2) - (5)].str));
		(yyval.int_list.i2)=atoi((yyvsp[(4) - (5)].str));
	}
    break;

  case 362:

/* Line 1455 of yacc.c  */
#line 2238 "sql.yacc"
    {
		strcpy((yyval.str),(yyvsp[(1) - (1)].str));
	}
    break;

  case 363:

/* Line 1455 of yacc.c  */
#line 2241 "sql.yacc"
    {
		strcpy((yyval.str),(yyvsp[(2) - (2)].str));
	}
    break;

  case 364:

/* Line 1455 of yacc.c  */
#line 2248 "sql.yacc"
    {
		(yyval.s_select_list_item)= (yyvsp[(1) - (1)].s_select_list_item);
	}
    break;

  case 365:

/* Line 1455 of yacc.c  */
#line 2251 "sql.yacc"
    {
		(yyval.s_select_list_item)= (yyvsp[(2) - (2)].s_select_list_item);
	}
    break;

  case 366:

/* Line 1455 of yacc.c  */
#line 2261 "sql.yacc"
    { 
		(yyval.s_select_list_item)=new_select_list_item_col(0,(yyvsp[(1) - (2)].str),&(yyvsp[(2) - (2)].int_list));
	}
    break;

  case 367:

/* Line 1455 of yacc.c  */
#line 2264 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_col((yyvsp[(1) - (4)].str),(yyvsp[(3) - (4)].str),&(yyvsp[(4) - (4)].int_list));
	}
    break;

  case 368:

/* Line 1455 of yacc.c  */
#line 2267 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_col((yyvsp[(1) - (3)].str),"*",0);
	}
    break;

  case 369:

/* Line 1455 of yacc.c  */
#line 2270 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_col(0,"rowid",0);
	}
    break;

  case 370:

/* Line 1455 of yacc.c  */
#line 2277 "sql.yacc"
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
#line 2284 "sql.yacc"
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
#line 2292 "sql.yacc"
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
#line 2301 "sql.yacc"
    {
		SPRINTF1((yyval.str),"%s",A4GLSQLCV_check_colname((yyvsp[(1) - (3)].str),"*"));
		ADDMAP("Use Column",(yyval.str));
	}
    break;

  case 375:

/* Line 1455 of yacc.c  */
#line 2312 "sql.yacc"
    { strcpy((yyval.str),(yyvsp[(1) - (1)].str)); 
#ifdef DEBUG
A4GL_debug("Set $<str>$ to %s\n",(yyval.str)); 
#endif
}
    break;

  case 379:

/* Line 1455 of yacc.c  */
#line 2324 "sql.yacc"
    { strcpy((yyval.str),A4GLSQLCV_generate_current(0,0)); 
}
    break;

  case 380:

/* Line 1455 of yacc.c  */
#line 2326 "sql.yacc"
    {
		strcpy((yyval.str),A4GLSQLCV_generate_current((yyvsp[(1) - (3)].str),(yyvsp[(3) - (3)].str)));
	}
    break;

  case 395:

/* Line 1455 of yacc.c  */
#line 2336 "sql.yacc"
    {SPRINTF1((yyval.str),"FRACTION(%s)",(yyvsp[(3) - (4)].str));}
    break;

  case 396:

/* Line 1455 of yacc.c  */
#line 2381 "sql.yacc"
    { (yyval.sql_string)=make_sql_string_and_free(acl_strdup((yyvsp[(1) - (1)].str)), NULL);}
    break;

  case 397:

/* Line 1455 of yacc.c  */
#line 2382 "sql.yacc"
    { (yyval.sql_string)=make_sql_string_and_free(acl_strdup((yyvsp[(1) - (1)].str)), NULL);}
    break;

  case 398:

/* Line 1455 of yacc.c  */
#line 2383 "sql.yacc"
    { (yyval.sql_string)=make_sql_string_and_free(acl_strdup((yyvsp[(1) - (1)].str)), NULL);}
    break;

  case 399:

/* Line 1455 of yacc.c  */
#line 2388 "sql.yacc"
    { add_feature("RENAME_TABLE"); strcpy((yyval.str),A4GLSQLCV_rentab((yyvsp[(2) - (4)].str),(yyvsp[(4) - (4)].str))); }
    break;

  case 400:

/* Line 1455 of yacc.c  */
#line 2389 "sql.yacc"
    { add_feature("RENAME_COLUMN"); strcpy((yyval.str),A4GLSQLCV_rencol((yyvsp[(2) - (6)].str),(yyvsp[(4) - (6)].str),(yyvsp[(6) - (6)].str)) ); }
    break;

  case 403:

/* Line 1455 of yacc.c  */
#line 2397 "sql.yacc"
    {
		add_feature("UNLOCK_TABLE");
		SPRINTF2((yyval.str),"%s %s",(yyvsp[(1) - (2)].str),(yyvsp[(2) - (2)].str));
	}
    break;

  case 404:

/* Line 1455 of yacc.c  */
#line 2404 "sql.yacc"
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
#line 2415 "sql.yacc"
    { add_feature("LOCK_TABLE_SHARED");}
    break;

  case 406:

/* Line 1455 of yacc.c  */
#line 2416 "sql.yacc"
    {add_feature("LOCK_TABLE_EXCLUSIVE");}
    break;

  case 407:

/* Line 1455 of yacc.c  */
#line 2429 "sql.yacc"
    {strcpy((yyval.str),A4GLSQLCV_datetime_value((yyvsp[(1) - (1)].str)));}
    break;

  case 408:

/* Line 1455 of yacc.c  */
#line 2430 "sql.yacc"
    {strcpy((yyval.str),A4GLSQLCV_make_dtime_extend((yyvsp[(1) - (4)].str),(yyvsp[(2) - (4)].str),(yyvsp[(4) - (4)].str),0));}
    break;

  case 409:

/* Line 1455 of yacc.c  */
#line 2434 "sql.yacc"
    {strcpy((yyval.str),(yyvsp[(1) - (1)].str));}
    break;

  case 410:

/* Line 1455 of yacc.c  */
#line 2438 "sql.yacc"
    {strcpy((yyval.str),A4GLSQLCV_interval_value((yyvsp[(1) - (1)].str)));}
    break;

  case 411:

/* Line 1455 of yacc.c  */
#line 2439 "sql.yacc"
    {
			strcpy((yyval.str),A4GLSQLCV_make_ival_extend((yyvsp[(1) - (7)].str),(yyvsp[(2) - (7)].str),(yyvsp[(4) - (7)].str),(yyvsp[(7) - (7)].str),0));
		}
    break;

  case 412:

/* Line 1455 of yacc.c  */
#line 2442 "sql.yacc"
    {
		strcpy((yyval.str),A4GLSQLCV_make_ival_extend((yyvsp[(1) - (4)].str),(yyvsp[(2) - (4)].str),(char *)0, (yyvsp[(4) - (4)].str),0));
	}
    break;

  case 413:

/* Line 1455 of yacc.c  */
#line 2448 "sql.yacc"
    {SPRINTF1((yyval.str),"%s",(yyvsp[(1) - (1)].str));}
    break;

  case 414:

/* Line 1455 of yacc.c  */
#line 2452 "sql.yacc"
    {
	strcpy((yyval.str),(yyvsp[(2) - (2)].str));
}
    break;

  case 415:

/* Line 1455 of yacc.c  */
#line 2475 "sql.yacc"
    {
		(yyval.s_select_list_item_list)=(yyvsp[(3) - (3)].s_select_list_item_list);
		add_feature("ORDER_BY");
	}
    break;

  case 416:

/* Line 1455 of yacc.c  */
#line 2485 "sql.yacc"
    {
			(yyval.s_select_list_item_list)=local_new_select_list_item_list((yyvsp[(1) - (1)].s_select_list_item));
	}
    break;

  case 417:

/* Line 1455 of yacc.c  */
#line 2488 "sql.yacc"
    {
			(yyval.s_select_list_item_list)=local_add_select_list_item_list((yyvsp[(1) - (3)].s_select_list_item_list),(yyvsp[(3) - (3)].s_select_list_item));
	}
    break;

  case 418:

/* Line 1455 of yacc.c  */
#line 2494 "sql.yacc"
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
#line 2503 "sql.yacc"
    { 
		add_feature("ORDER_BY_NUMBER");
		(yyval.s_select_list_item)=new_select_list_item_literal((yyvsp[(1) - (1)].str));
	}
    break;

  case 420:

/* Line 1455 of yacc.c  */
#line 2507 "sql.yacc"
    {
		(yyval.s_select_list_item)=(yyvsp[(1) - (1)].s_select_list_item);
		(yyval.s_select_list_item)->data.type=E_SLI_COLUMN_ORDERBY;
	}
    break;

  case 421:

/* Line 1455 of yacc.c  */
#line 2514 "sql.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 422:

/* Line 1455 of yacc.c  */
#line 2516 "sql.yacc"
    {add_feature("ORDER_BY_ASC"); strcpy((yyval.str),"ASC");}
    break;

  case 423:

/* Line 1455 of yacc.c  */
#line 2518 "sql.yacc"
    {add_feature("ORDER_BY_DESC"); strcpy((yyval.str),"DESC");}
    break;

  case 424:

/* Line 1455 of yacc.c  */
#line 2522 "sql.yacc"
    {
		(yyval.s_select_list_item_list)=(yyvsp[(2) - (2)].s_select_list_item_list);
	}
    break;

  case 425:

/* Line 1455 of yacc.c  */
#line 2528 "sql.yacc"
    {
			(yyval.s_select_list_item_list)=local_new_select_list_item_list((yyvsp[(1) - (1)].s_select_list_item));
	}
    break;

  case 426:

/* Line 1455 of yacc.c  */
#line 2531 "sql.yacc"
    {
			(yyval.s_select_list_item_list)=local_add_select_list_item_list((yyvsp[(1) - (3)].s_select_list_item_list),(yyvsp[(3) - (3)].s_select_list_item));
	}
    break;

  case 427:

/* Line 1455 of yacc.c  */
#line 2537 "sql.yacc"
    { (yyval.s_select_list_item)=(yyvsp[(1) - (1)].s_select_list_item); }
    break;

  case 428:

/* Line 1455 of yacc.c  */
#line 2538 "sql.yacc"
    { (yyval.s_select_list_item)=new_select_list_item_literal((yyvsp[(1) - (1)].str)); }
    break;

  case 429:

/* Line 1455 of yacc.c  */
#line 2545 "sql.yacc"
    {
	(yyval.sql_string)=get_select_list_item(0,(yyvsp[(1) - (1)].s_select_list_item));
}
    break;

  case 430:

/* Line 1455 of yacc.c  */
#line 2558 "sql.yacc"
    {
		A4GL_set_sql_lineno(yylineno);
		(yyval.sql_string)=make_select_stmt_v2(current_upd_table, (yyvsp[(1) - (1)].s_select),"");
		map_select_stmt("SELECT",(yyvsp[(1) - (1)].s_select));
		A4GL_free_select_stmt((yyvsp[(1) - (1)].s_select));
}
    break;

  case 431:

/* Line 1455 of yacc.c  */
#line 2568 "sql.yacc"
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
#line 2575 "sql.yacc"
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
#line 2592 "sql.yacc"
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
#line 2599 "sql.yacc"
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
#line 2624 "sql.yacc"
    { 
		//start_bind('i',0);
		 set_ignore_indicators();}
    break;

  case 436:

/* Line 1455 of yacc.c  */
#line 2626 "sql.yacc"
    { clr_ignore_indicators();}
    break;

  case 437:

/* Line 1455 of yacc.c  */
#line 2628 "sql.yacc"
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
#line 2649 "sql.yacc"
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
#line 2692 "sql.yacc"
    { (yyval.s_select)=0;}
    break;

  case 440:

/* Line 1455 of yacc.c  */
#line 2693 "sql.yacc"
    { 
		(yyval.s_select)=(yyvsp[(3) - (3)].s_select);
		(yyval.s_select)->union_op=acl_strdup((yyvsp[(2) - (3)].str));
		A4GL_set_associated_mem((yyval.s_select), (yyval.s_select)->union_op);
		add_feature("SELECT_UNION"); 
	}
    break;

  case 441:

/* Line 1455 of yacc.c  */
#line 2707 "sql.yacc"
    {
		(yyval.s_select_finish)=0;
	}
    break;

  case 442:

/* Line 1455 of yacc.c  */
#line 2710 "sql.yacc"
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
#line 2717 "sql.yacc"
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
#line 2727 "sql.yacc"
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
#line 2745 "sql.yacc"
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
#line 2758 "sql.yacc"
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
#line 2773 "sql.yacc"
    {(yyval.integer_val)=-1;}
    break;

  case 449:

/* Line 1455 of yacc.c  */
#line 2775 "sql.yacc"
    {
		(yyval.integer_val)=atol((yyvsp[(2) - (2)].str));
	}
    break;

  case 450:

/* Line 1455 of yacc.c  */
#line 2781 "sql.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 451:

/* Line 1455 of yacc.c  */
#line 2782 "sql.yacc"
    {strcpy((yyval.str),"ALL"); add_feature("SELECT_ALL");}
    break;

  case 452:

/* Line 1455 of yacc.c  */
#line 2783 "sql.yacc"
    {strcpy((yyval.str),"DISTINCT"); add_feature("SELECT_DISTINCT");}
    break;

  case 453:

/* Line 1455 of yacc.c  */
#line 2784 "sql.yacc"
    {strcpy((yyval.str),"DISTINCT");
		add_feature("SELECT_UNIQUE");
		ansi_violation("Use DISTINCT not UNIQUE",0);
		strcpy((yyval.str),"DISTINCT");
	}
    break;

  case 454:

/* Line 1455 of yacc.c  */
#line 2794 "sql.yacc"
    { 
		 (yyval.s_select_list_item_list)=local_new_select_list_item_list((yyvsp[(1) - (1)].s_select_list_item));
	}
    break;

  case 455:

/* Line 1455 of yacc.c  */
#line 2797 "sql.yacc"
    { 
		(yyval.s_select_list_item_list)=local_add_select_list_item_list((yyvsp[(1) - (3)].s_select_list_item_list),(yyvsp[(3) - (3)].s_select_list_item));
	}
    break;

  case 456:

/* Line 1455 of yacc.c  */
#line 2803 "sql.yacc"
    {
		(yyval.s_select_list_item)=(yyvsp[(1) - (1)].s_select_list_item);
	}
    break;

  case 457:

/* Line 1455 of yacc.c  */
#line 2806 "sql.yacc"
    {
		(yyval.s_select_list_item)=(yyvsp[(1) - (2)].s_select_list_item);
		(yyval.s_select_list_item)->alias=acl_strdup((yyvsp[(2) - (2)].str));
		A4GL_set_associated_mem((yyval.s_select_list_item), (yyval.s_select_list_item)->alias);
	}
    break;

  case 458:

/* Line 1455 of yacc.c  */
#line 2811 "sql.yacc"
    {
		(yyval.s_select_list_item)=(yyvsp[(1) - (3)].s_select_list_item);
		(yyval.s_select_list_item)->alias=acl_strdup((yyvsp[(3) - (3)].str));
		A4GL_set_associated_mem((yyval.s_select_list_item), (yyval.s_select_list_item)->alias);
	}
    break;

  case 459:

/* Line 1455 of yacc.c  */
#line 2820 "sql.yacc"
    {
		(yyval.s_select_list_item)=(yyvsp[(1) - (1)].s_select_list_item); /* A4GLSQLCV_check_expr($<sql_string>1) */
	}
    break;

  case 460:

/* Line 1455 of yacc.c  */
#line 2823 "sql.yacc"
    {
		(yyval.s_select_list_item)=(yyvsp[(2) - (2)].s_select_list_item);
		(yyval.s_select_list_item)->sign='-';
	}
    break;

  case 461:

/* Line 1455 of yacc.c  */
#line 2827 "sql.yacc"
    {
		(yyval.s_select_list_item)=(yyvsp[(2) - (2)].s_select_list_item);
	}
    break;

  case 462:

/* Line 1455 of yacc.c  */
#line 2834 "sql.yacc"
    {
			(yyval.s_select_list_item)=new_select_list_item_op_expr ((yyvsp[(1) - (3)].s_select_list_item), (yyvsp[(3) - (3)].s_select_list_item), "/");
	}
    break;

  case 463:

/* Line 1455 of yacc.c  */
#line 2837 "sql.yacc"
    {
			(yyval.s_select_list_item)=new_select_list_item_simple_expr((enum e_sli)(yyvsp[(2) - (2)].integer_val), (yyvsp[(1) - (2)].s_select_list_item));
	}
    break;

  case 464:

/* Line 1455 of yacc.c  */
#line 2840 "sql.yacc"
    {
			(yyval.s_select_list_item)=new_select_list_item_op_expr ((yyvsp[(1) - (3)].s_select_list_item), (yyvsp[(3) - (3)].s_select_list_item), "*");
	}
    break;

  case 465:

/* Line 1455 of yacc.c  */
#line 2843 "sql.yacc"
    {
			(yyval.s_select_list_item)=new_select_list_item_op_expr ((yyvsp[(1) - (3)].s_select_list_item), (yyvsp[(3) - (3)].s_select_list_item), "+");
	}
    break;

  case 466:

/* Line 1455 of yacc.c  */
#line 2846 "sql.yacc"
    {
			(yyval.s_select_list_item)=new_select_list_item_op_expr ((yyvsp[(1) - (3)].s_select_list_item), (yyvsp[(3) - (3)].s_select_list_item), "-");
	}
    break;

  case 467:

/* Line 1455 of yacc.c  */
#line 2849 "sql.yacc"
    {
			(yyval.s_select_list_item)=new_select_list_item_op_expr ((yyvsp[(1) - (3)].s_select_list_item), (yyvsp[(3) - (3)].s_select_list_item), "||");
	}
    break;

  case 468:

/* Line 1455 of yacc.c  */
#line 2852 "sql.yacc"
    { (yyval.s_select_list_item)=new_select_list_item_literal((yyvsp[(1) - (1)].str)); }
    break;

  case 469:

/* Line 1455 of yacc.c  */
#line 2853 "sql.yacc"
    { (yyval.s_select_list_item)=new_select_list_item_builtin_const(E_SLI_BUILTIN_CONST_TRUE); }
    break;

  case 470:

/* Line 1455 of yacc.c  */
#line 2854 "sql.yacc"
    { (yyval.s_select_list_item)=new_select_list_item_builtin_const(E_SLI_BUILTIN_CONST_FALSE); }
    break;

  case 471:

/* Line 1455 of yacc.c  */
#line 2855 "sql.yacc"
    { (yyval.s_select_list_item)=new_select_list_item_builtin_const(E_SLI_BUILTIN_CONST_USER); }
    break;

  case 472:

/* Line 1455 of yacc.c  */
#line 2856 "sql.yacc"
    { (yyval.s_select_list_item)=new_select_list_item_builtin_const(E_SLI_BUILTIN_CONST_TODAY); }
    break;

  case 473:

/* Line 1455 of yacc.c  */
#line 2857 "sql.yacc"
    { (yyval.s_select_list_item)=new_select_list_item_builtin_const(E_SLI_BUILTIN_CONST_ROWID); }
    break;

  case 474:

/* Line 1455 of yacc.c  */
#line 2858 "sql.yacc"
    { (yyval.s_select_list_item)=new_select_list_item_builtin_const(E_SLI_BUILTIN_CONST_TIME); }
    break;

  case 475:

/* Line 1455 of yacc.c  */
#line 2859 "sql.yacc"
    { (yyval.s_select_list_item)=new_select_list_item_builtin_const(E_SLI_BUILTIN_CONST_STAR); }
    break;

  case 476:

/* Line 1455 of yacc.c  */
#line 2860 "sql.yacc"
    { (yyval.s_select_list_item)=new_select_list_item_builtin_const(E_SLI_BUILTIN_CONST_COUNT_STAR); }
    break;

  case 477:

/* Line 1455 of yacc.c  */
#line 2862 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_agg1(E_SLI_BUILTIN_AGG_AVG,(yyvsp[(3) - (5)].str),(yyvsp[(4) - (5)].s_select_list_item));
		add_feature("SELECT_AVG");
	}
    break;

  case 478:

/* Line 1455 of yacc.c  */
#line 2866 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_agg1(E_SLI_BUILTIN_AGG_MAX,(yyvsp[(3) - (5)].str),(yyvsp[(4) - (5)].s_select_list_item));
		add_feature("SELECT_MAX");
	}
    break;

  case 479:

/* Line 1455 of yacc.c  */
#line 2870 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_agg1(E_SLI_BUILTIN_AGG_MIN,(yyvsp[(3) - (5)].str),(yyvsp[(4) - (5)].s_select_list_item));
		add_feature("SELECT_MIN");
	}
    break;

  case 480:

/* Line 1455 of yacc.c  */
#line 2874 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_agg1(E_SLI_BUILTIN_AGG_SUM,(yyvsp[(3) - (5)].str),(yyvsp[(4) - (5)].s_select_list_item));
		add_feature("SELECT_SUM");
	}
    break;

  case 481:

/* Line 1455 of yacc.c  */
#line 2878 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_agg1(E_SLI_BUILTIN_AGG_COUNT,(yyvsp[(3) - (5)].str),(yyvsp[(4) - (5)].s_select_list_item));
		add_feature("SELECT_COUNT");
	}
    break;

  case 482:

/* Line 1455 of yacc.c  */
#line 2882 "sql.yacc"
    {
		add_sql_function((yyvsp[(1) - (3)].str));
		(yyval.s_select_list_item)=new_select_list_item_fcall((yyvsp[(1) - (3)].str),0);
	}
    break;

  case 483:

/* Line 1455 of yacc.c  */
#line 2886 "sql.yacc"
    {
		add_sql_function((yyvsp[(1) - (4)].str));
		(yyval.s_select_list_item)=new_select_list_item_fcall((yyvsp[(1) - (4)].str),(yyvsp[(3) - (4)].s_select_list_item_list));
	}
    break;

  case 484:

/* Line 1455 of yacc.c  */
#line 2890 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_builtin_fcall(E_SLI_BUILTIN_FUNC_YEAR,(yyvsp[(3) - (4)].s_select_list_item_list));
	}
    break;

  case 485:

/* Line 1455 of yacc.c  */
#line 2893 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_builtin_fcall(E_SLI_BUILTIN_FUNC_MONTH,(yyvsp[(3) - (4)].s_select_list_item_list));
	}
    break;

  case 486:

/* Line 1455 of yacc.c  */
#line 2896 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_builtin_fcall(E_SLI_BUILTIN_FUNC_DAY,(yyvsp[(3) - (4)].s_select_list_item_list));
	}
    break;

  case 487:

/* Line 1455 of yacc.c  */
#line 2899 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_builtin_fcall(E_SLI_BUILTIN_FUNC_MDY,(yyvsp[(3) - (4)].s_select_list_item_list));
	}
    break;

  case 488:

/* Line 1455 of yacc.c  */
#line 2902 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_builtin_fcall(E_SLI_BUILTIN_FUNC_WEEKDAY,(yyvsp[(3) - (4)].s_select_list_item_list));
	}
    break;

  case 489:

/* Line 1455 of yacc.c  */
#line 2905 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_builtin_fcall(E_SLI_BUILTIN_FUNC_DOW,(yyvsp[(3) - (4)].s_select_list_item_list));
	}
    break;

  case 490:

/* Line 1455 of yacc.c  */
#line 2908 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_builtin_fcall(E_SLI_BUILTIN_FUNC_DATE,(yyvsp[(3) - (4)].s_select_list_item_list));
	}
    break;

  case 491:

/* Line 1455 of yacc.c  */
#line 2911 "sql.yacc"
    {
		  (yyval.s_select_list_item)=new_select_list_item_simple_expr(E_SLI_BRACKET_EXPR,(yyvsp[(2) - (3)].s_select_list_item));
	}
    break;

  case 492:

/* Line 1455 of yacc.c  */
#line 2914 "sql.yacc"
    { 
		add_feature("EXTEND"); 
		(yyval.s_select_list_item)=(yyvsp[(3) - (4)].s_select_list_item);
	}
    break;

  case 493:

/* Line 1455 of yacc.c  */
#line 2918 "sql.yacc"
    { 
		(yyval.s_select_list_item)=new_select_list_item_datetime((yyvsp[(1) - (1)].str));
		add_feature("FUNC_DATETIME");
	}
    break;

  case 494:

/* Line 1455 of yacc.c  */
#line 2922 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_interval((yyvsp[(1) - (1)].str));
		add_feature("FUNC_INTERVAL");
	}
    break;

  case 495:

/* Line 1455 of yacc.c  */
#line 2926 "sql.yacc"
    {
		(yyval.s_select_list_item)=(yyvsp[(2) - (3)].s_select_list_item);
	}
    break;

  case 496:

/* Line 1455 of yacc.c  */
#line 2934 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_case((yyvsp[(1) - (1)].s_select_list_item));
	}
    break;

  case 497:

/* Line 1455 of yacc.c  */
#line 2937 "sql.yacc"
    {
		(yyval.s_select_list_item)=append_select_list_item_case(
							(yyvsp[(1) - (2)].s_select_list_item),
							(yyvsp[(2) - (2)].s_select_list_item));
	}
    break;

  case 498:

/* Line 1455 of yacc.c  */
#line 2946 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_case_element(
				(yyvsp[(2) - (4)].s_select_list_item),
				(yyvsp[(4) - (4)].s_select_list_item));

	}
    break;

  case 499:

/* Line 1455 of yacc.c  */
#line 2952 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_case_element( 0, (yyvsp[(2) - (2)].s_select_list_item));
	}
    break;

  case 500:

/* Line 1455 of yacc.c  */
#line 2959 "sql.yacc"
    {
		(yyval.s_select_list_item_list)=local_new_select_list_item_list((yyvsp[(1) - (1)].s_select_list_item));
	}
    break;

  case 501:

/* Line 1455 of yacc.c  */
#line 2962 "sql.yacc"
    {
			(yyval.s_select_list_item_list)=local_add_select_list_item_list((yyvsp[(1) - (3)].s_select_list_item_list),(yyvsp[(3) - (3)].s_select_list_item));
	}
    break;

  case 502:

/* Line 1455 of yacc.c  */
#line 2990 "sql.yacc"
    {
			(yyval.s_select_list_item)=new_select_list_item_extend(new_select_list_item_builtin_const(E_SLI_BUILTIN_CONST_CURRENT),(yyvsp[(3) - (5)].str),(yyvsp[(5) - (5)].str));
	}
    break;

  case 503:

/* Line 1455 of yacc.c  */
#line 2993 "sql.yacc"
    {
			(yyval.s_select_list_item)=new_select_list_item_extend((yyvsp[(1) - (5)].s_select_list_item),(yyvsp[(3) - (5)].str),(yyvsp[(5) - (5)].str));
	}
    break;

  case 504:

/* Line 1455 of yacc.c  */
#line 2996 "sql.yacc"
    {
			(yyval.s_select_list_item)=new_select_list_item_extend(new_select_list_item_builtin_const(E_SLI_BUILTIN_CONST_CURRENT),(yyvsp[(2) - (4)].str),(yyvsp[(4) - (4)].str));
	}
    break;

  case 505:

/* Line 1455 of yacc.c  */
#line 2999 "sql.yacc"
    {
			(yyval.s_select_list_item)=new_select_list_item_extend((yyvsp[(1) - (5)].s_select_list_item),(yyvsp[(3) - (5)].str),(yyvsp[(5) - (5)].str));
	}
    break;

  case 506:

/* Line 1455 of yacc.c  */
#line 3005 "sql.yacc"
    {(yyval.integer_val)=E_SLI_UNITS_YEAR;}
    break;

  case 507:

/* Line 1455 of yacc.c  */
#line 3006 "sql.yacc"
    {(yyval.integer_val)=E_SLI_UNITS_MONTH;}
    break;

  case 508:

/* Line 1455 of yacc.c  */
#line 3007 "sql.yacc"
    {(yyval.integer_val)=E_SLI_UNITS_DAY;}
    break;

  case 509:

/* Line 1455 of yacc.c  */
#line 3008 "sql.yacc"
    {(yyval.integer_val)=E_SLI_UNITS_HOUR;}
    break;

  case 510:

/* Line 1455 of yacc.c  */
#line 3009 "sql.yacc"
    {(yyval.integer_val)=E_SLI_UNITS_MINUTE;}
    break;

  case 511:

/* Line 1455 of yacc.c  */
#line 3010 "sql.yacc"
    {(yyval.integer_val)=E_SLI_UNITS_SECOND;}
    break;

  case 512:

/* Line 1455 of yacc.c  */
#line 3015 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_op_slil((yyvsp[(1) - (5)].s_select_list_item),(yyvsp[(4) - (5)].s_select_list_item_list),E_SLI_IN_VALUES);
                add_feature("WHERE_IN");
        }
    break;

  case 513:

/* Line 1455 of yacc.c  */
#line 3019 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_op_sli((yyvsp[(1) - (3)].s_select_list_item),(yyvsp[(3) - (3)].s_select_list_item),E_SLI_IN_SELECT);
                add_feature("WHERE_IN_SELECT");
        }
    break;

  case 514:

/* Line 1455 of yacc.c  */
#line 3023 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_op_slil((yyvsp[(1) - (5)].s_select_list_item),(yyvsp[(4) - (5)].s_select_list_item_list),E_SLI_NOT_IN_VALUES);
                add_feature("WHERE_IN");
        }
    break;

  case 515:

/* Line 1455 of yacc.c  */
#line 3027 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_op_sli((yyvsp[(1) - (3)].s_select_list_item),(yyvsp[(3) - (3)].s_select_list_item),E_SLI_NOT_IN_SELECT);
                add_feature("WHERE_IN_SELECT");
        }
    break;

  case 516:

/* Line 1455 of yacc.c  */
#line 3034 "sql.yacc"
    {
		(yyval.s_select_list_item_list)=local_new_select_list_item_list((yyvsp[(1) - (1)].s_select_list_item));
	}
    break;

  case 517:

/* Line 1455 of yacc.c  */
#line 3037 "sql.yacc"
    {
                (yyval.s_select_list_item_list)=local_add_select_list_item_list((yyvsp[(1) - (3)].s_select_list_item_list),(yyvsp[(3) - (3)].s_select_list_item));
	}
    break;

  case 518:

/* Line 1455 of yacc.c  */
#line 3042 "sql.yacc"
    { (yyval.s_select_list_item)=(yyvsp[(1) - (1)].s_select_list_item);}
    break;

  case 519:

/* Line 1455 of yacc.c  */
#line 3043 "sql.yacc"
    { (yyval.s_select_list_item)=new_select_list_item_literal((yyvsp[(1) - (1)].str)); }
    break;

  case 520:

/* Line 1455 of yacc.c  */
#line 3044 "sql.yacc"
    { 
		char buff[256]; SPRINTF1(buff," -%s",(yyvsp[(2) - (2)].str)); (yyval.s_select_list_item)=new_select_list_item_literal(buff); }
    break;

  case 521:

/* Line 1455 of yacc.c  */
#line 3046 "sql.yacc"
    { char buff[256]; SPRINTF1(buff," -%s",(yyvsp[(2) - (2)].str)); (yyval.s_select_list_item)=new_select_list_item_literal(buff); }
    break;

  case 522:

/* Line 1455 of yacc.c  */
#line 3052 "sql.yacc"
    {
                if (strstr((yyvsp[(1) - (1)].str),"systables")!=0) { add_feature("IFX_SYSTABLES"); }
                if (strstr((yyvsp[(1) - (1)].str),"syscolumns")!=0) { add_feature("IFX_SYSCOLUMNS"); }
                if (strstr((yyvsp[(1) - (1)].str),"sysindexes")!=0) { add_feature("IFX_SYSINDEXES"); }
                strcpy((yyval.str),A4GLSQLCV_check_tablename((yyvsp[(1) - (1)].str)));
                }
    break;

  case 523:

/* Line 1455 of yacc.c  */
#line 3062 "sql.yacc"
    {
	     SPRINTF1((yyval.str),"%s", A4GLSQLCV_ownerize_tablename(NULL, A4GL_strip_quotes((yyvsp[(1) - (1)].str))));
             ADDMAP("Use Table",(yyval.str));
        }
    break;

  case 524:

/* Line 1455 of yacc.c  */
#line 3066 "sql.yacc"
    {
	     SPRINTF1((yyval.str),"%s", A4GLSQLCV_ownerize_tablename((yyvsp[(1) - (3)].str), (yyvsp[(3) - (3)].str)));
	     ADDMAP("Use Table",(yyval.str));
        }
    break;

  case 525:

/* Line 1455 of yacc.c  */
#line 3070 "sql.yacc"
    {
	     SPRINTF1((yyval.str),"%s", A4GLSQLCV_ownerize_tablename(NULL, (yyvsp[(1) - (1)].str)));
	     ADDMAP("Use Table",(yyval.str));
	}
    break;

  case 526:

/* Line 1455 of yacc.c  */
#line 3074 "sql.yacc"
    {
	     SPRINTF1((yyval.str),"%s", A4GLSQLCV_db_tablename((yyvsp[(1) - (3)].str), NULL, A4GLSQLCV_ownerize_tablename(NULL, (yyvsp[(3) - (3)].str))));
	     ADDMAP("Use Table",(yyval.str));
	}
    break;

  case 527:

/* Line 1455 of yacc.c  */
#line 3078 "sql.yacc"
    {
	     SPRINTF1((yyval.str),"%s", A4GLSQLCV_db_tablename((yyvsp[(1) - (5)].str), NULL, A4GLSQLCV_ownerize_tablename((yyvsp[(3) - (5)].str),(yyvsp[(5) - (5)].str))));
	     ADDMAP("Use Table",(yyval.str));
        }
    break;

  case 528:

/* Line 1455 of yacc.c  */
#line 3082 "sql.yacc"
    {
	     SPRINTF1((yyval.str),"%s", A4GLSQLCV_db_tablename(NULL,(yyvsp[(1) - (3)].str), A4GLSQLCV_ownerize_tablename(NULL, (yyvsp[(3) - (3)].str))));
	     ADDMAP("Use Table",(yyval.str));
	}
    break;

  case 529:

/* Line 1455 of yacc.c  */
#line 3086 "sql.yacc"
    {
	     SPRINTF1((yyval.str),"%s", A4GLSQLCV_db_tablename((yyvsp[(1) - (5)].str), (yyvsp[(3) - (5)].str), A4GLSQLCV_ownerize_tablename(NULL, (yyvsp[(5) - (5)].str))));
	     ADDMAP("Use Table",(yyval.str));
	}
    break;

  case 530:

/* Line 1455 of yacc.c  */
#line 3090 "sql.yacc"
    {
	     SPRINTF1((yyval.str),"%s", A4GLSQLCV_db_tablename((yyvsp[(1) - (7)].str), (yyvsp[(3) - (7)].str), A4GLSQLCV_ownerize_tablename((yyvsp[(5) - (7)].str), (yyvsp[(7) - (7)].str))));
	     ADDMAP("Use Table",(yyval.str));
        }
    break;

  case 531:

/* Line 1455 of yacc.c  */
#line 3098 "sql.yacc"
    {
                if (strstr((yyvsp[(1) - (1)].str),"systables")!=0) { add_feature("IFX_SYSTABLES"); }
                if (strstr((yyvsp[(1) - (1)].str),"syscolumns")!=0) { add_feature("IFX_SYSCOLUMNS"); }
                if (strstr((yyvsp[(1) - (1)].str),"sysindexes")!=0) { add_feature("IFX_SYSINDEXES"); }
                strcpy((yyval.str),A4GLSQLCV_check_tablename((yyvsp[(1) - (1)].str)));
                }
    break;

  case 532:

/* Line 1455 of yacc.c  */
#line 3108 "sql.yacc"
    {

	     SPRINTF1((yyval.str),"%s", A4GLSQLCV_ownerize_tablename((yyvsp[(1) - (3)].str), (yyvsp[(3) - (3)].str)));
	     ADDMAP("Use Table",(yyval.str));
        }
    break;

  case 533:

/* Line 1455 of yacc.c  */
#line 3113 "sql.yacc"
    {
	     SPRINTF1((yyval.str),"%s", A4GLSQLCV_ownerize_tablename((yyvsp[(1) - (3)].str), (yyvsp[(3) - (3)].str)));
	     ADDMAP("Use Table",(yyval.str));
        }
    break;

  case 534:

/* Line 1455 of yacc.c  */
#line 3117 "sql.yacc"
    {
	     SPRINTF1((yyval.str),"%s", A4GLSQLCV_ownerize_tablename(NULL, A4GL_strip_quotes((yyvsp[(1) - (1)].str))));
	     ADDMAP("Use Table",(yyval.str));
        }
    break;

  case 535:

/* Line 1455 of yacc.c  */
#line 3121 "sql.yacc"
    {
             SPRINTF1((yyval.str),"%s", A4GLSQLCV_ownerize_tablename(NULL, (yyvsp[(1) - (1)].str)));
	     ADDMAP("Use Table",(yyval.str));
	}
    break;

  case 536:

/* Line 1455 of yacc.c  */
#line 3125 "sql.yacc"
    {
             SPRINTF1((yyval.str),"%s", A4GLSQLCV_db_tablename((yyvsp[(1) - (3)].str),NULL, A4GLSQLCV_ownerize_tablename(NULL, (yyvsp[(3) - (3)].str))));
	     ADDMAP("Use Table",(yyval.str));
	}
    break;

  case 537:

/* Line 1455 of yacc.c  */
#line 3129 "sql.yacc"
    {
	     SPRINTF1((yyval.str),"%s", A4GLSQLCV_db_tablename((yyvsp[(1) - (5)].str), NULL,A4GLSQLCV_ownerize_tablename((yyvsp[(3) - (5)].str), (yyvsp[(5) - (5)].str))));
	     ADDMAP("Use Table",(yyval.str));
        }
    break;

  case 538:

/* Line 1455 of yacc.c  */
#line 3134 "sql.yacc"
    {
             SPRINTF1((yyval.str),"%s", A4GLSQLCV_db_tablename(NULL, (yyvsp[(1) - (3)].str), A4GLSQLCV_ownerize_tablename(NULL, (yyvsp[(3) - (3)].str))));
	     ADDMAP("Use Table",(yyval.str));
	}
    break;

  case 539:

/* Line 1455 of yacc.c  */
#line 3138 "sql.yacc"
    {
            SPRINTF1((yyval.str),"%s", A4GLSQLCV_db_tablename( (yyvsp[(1) - (5)].str), (yyvsp[(3) - (5)].str), A4GLSQLCV_ownerize_tablename(NULL, (yyvsp[(5) - (5)].str))));
	    ADDMAP("Use Table",(yyval.str));
	}
    break;

  case 540:

/* Line 1455 of yacc.c  */
#line 3142 "sql.yacc"
    {
	     SPRINTF1((yyval.str),"%s", A4GLSQLCV_db_tablename((yyvsp[(1) - (7)].str), (yyvsp[(3) - (7)].str), A4GLSQLCV_ownerize_tablename((yyvsp[(5) - (7)].str), (yyvsp[(7) - (7)].str))));
	     ADDMAP("Use Table",(yyval.str));
        }
    break;

  case 541:

/* Line 1455 of yacc.c  */
#line 3150 "sql.yacc"
    {
	     SPRINTF1((yyval.str),"%s", A4GLSQLCV_ownerize_tablename((yyvsp[(1) - (3)].str), (yyvsp[(3) - (3)].str)));
        }
    break;

  case 542:

/* Line 1455 of yacc.c  */
#line 3153 "sql.yacc"
    {
	        SPRINTF1((yyval.str),"%s", A4GLSQLCV_ownerize_tablename(NULL, (yyvsp[(1) - (1)].str)));
                ADDMAP("Use Index",(yyval.str));
        }
    break;

  case 543:

/* Line 1455 of yacc.c  */
#line 3158 "sql.yacc"
    {strcpy((yyval.str),(yyvsp[(1) - (1)].str)); ADDMAP("Use Index",(yyvsp[(1) - (1)].str)); }
    break;

  case 544:

/* Line 1455 of yacc.c  */
#line 3159 "sql.yacc"
    { SPRINTF3((yyval.str),"%s%s%s",(yyvsp[(1) - (3)].str),(yyvsp[(2) - (3)].str),(yyvsp[(3) - (3)].str)); ADDMAP("Use Index",(yyval.str)); }
    break;

  case 545:

/* Line 1455 of yacc.c  */
#line 3160 "sql.yacc"
    {
	     SPRINTF2((yyval.str),"%s:%s", (yyvsp[(1) - (5)].str), A4GLSQLCV_ownerize_tablename((yyvsp[(3) - (5)].str), (yyvsp[(5) - (5)].str)));
             ADDMAP("Use Index",(yyval.str));
        }
    break;

  case 546:

/* Line 1455 of yacc.c  */
#line 3165 "sql.yacc"
    {strcpy((yyval.str),(yyvsp[(1) - (3)].str)); ADDMAP("Use Index",(yyvsp[(1) - (3)].str)); }
    break;

  case 547:

/* Line 1455 of yacc.c  */
#line 3166 "sql.yacc"
    { SPRINTF4((yyval.str),"%s@%s%s%s",(yyvsp[(1) - (5)].str),(yyvsp[(3) - (5)].str),(yyvsp[(4) - (5)].str),(yyvsp[(5) - (5)].str)); ADDMAP("Use Index",(yyval.str)); }
    break;

  case 548:

/* Line 1455 of yacc.c  */
#line 3167 "sql.yacc"
    {
	     SPRINTF3((yyval.str),"%s@%s:%s", (yyvsp[(1) - (7)].str), (yyvsp[(3) - (7)].str), A4GLSQLCV_ownerize_tablename((yyvsp[(5) - (7)].str), (yyvsp[(7) - (7)].str)));
             ADDMAP("Use Index",(yyval.str));
        }
    break;

  case 550:

/* Line 1455 of yacc.c  */
#line 3178 "sql.yacc"
    {
                      (yyval.ptr)=A4GL_new_expr_simple_string(A4GL_get_clobbered_from((yyval.str)), ET_EXPR_IDENTIFIER);
	}
    break;

  case 552:

/* Line 1455 of yacc.c  */
#line 3184 "sql.yacc"
    { sprintf((yyval.str),".%s",(yyvsp[(2) - (2)].str)); }
    break;

  case 554:

/* Line 1455 of yacc.c  */
#line 3189 "sql.yacc"
    {strcpy((yyval.str), A4GL_strip_quotes ((yyvsp[(1) - (1)].str)));}
    break;

  case 559:

/* Line 1455 of yacc.c  */
#line 3240 "sql.yacc"
    {
			int converted;
			(yyval.sql_string)=get_insert_cmd((yyvsp[(1) - (1)].insert_cmd),&converted);
			A4GL_free_associated_mem((yyvsp[(1) - (1)].insert_cmd));
			acl_free((yyvsp[(1) - (1)].insert_cmd));

		}
    break;

  case 560:

/* Line 1455 of yacc.c  */
#line 3247 "sql.yacc"
    {
			int converted;
			(yyval.sql_string)=get_update_cmd((yyvsp[(1) - (1)].update_cmd),&converted);
			A4GL_free_associated_mem((yyvsp[(1) - (1)].update_cmd));
			acl_free((yyvsp[(1) - (1)].update_cmd));
		}
    break;

  case 561:

/* Line 1455 of yacc.c  */
#line 3253 "sql.yacc"
    {
			int converted;
			(yyval.sql_string)=get_delete_cmd((yyvsp[(1) - (1)].delete_cmd),&converted);
			A4GL_free_associated_mem((yyvsp[(1) - (1)].delete_cmd));
			acl_free((yyvsp[(1) - (1)].delete_cmd));
		}
    break;

  case 564:

/* Line 1455 of yacc.c  */
#line 3268 "sql.yacc"
    { print_exec_select((yyvsp[(1) - (1)].sql_string));  }
    break;

  case 565:

/* Line 1455 of yacc.c  */
#line 3269 "sql.yacc"
    { print_exec_select((yyvsp[(1) - (1)].sql_string));  }
    break;

  case 567:

/* Line 1455 of yacc.c  */
#line 3271 "sql.yacc"
    { print_exec_select((yyvsp[(1) - (1)].sql_string));  }
    break;

  case 568:

/* Line 1455 of yacc.c  */
#line 3273 "sql.yacc"
    {
			print_sql_commit ((yyvsp[(1) - (1)].integer_val));
	}
    break;

  case 569:

/* Line 1455 of yacc.c  */
#line 3276 "sql.yacc"
    {print_unable_to_parse();}
    break;

  case 570:

/* Line 1455 of yacc.c  */
#line 3280 "sql.yacc"
    { (yyval.sql_string)=make_sql_string_and_free((yyvsp[(1) - (2)].sql_string),acl_strdup((yyvsp[(2) - (2)].str)),0);
}
    break;

  case 572:

/* Line 1455 of yacc.c  */
#line 3289 "sql.yacc"
    {
			(yyval.sql_string)=make_select_stmt_v2("", (yyvsp[(1) - (1)].s_select),"");
			A4GL_free_select_stmt((yyvsp[(1) - (1)].s_select));
		}
    break;

  case 573:

/* Line 1455 of yacc.c  */
#line 3295 "sql.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 574:

/* Line 1455 of yacc.c  */
#line 3296 "sql.yacc"
    {
			strcpy((yyval.str),A4GLSQLCV_get_forupdate(NULL));
		}
    break;

  case 575:

/* Line 1455 of yacc.c  */
#line 3299 "sql.yacc"
    {
			strcpy((yyval.str),A4GLSQLCV_get_forupdate((yyvsp[(2) - (2)].str)));
		}
    break;

  case 576:

/* Line 1455 of yacc.c  */
#line 3304 "sql.yacc"
    { strcpy((yyval.str),(yyvsp[(1) - (1)].str)); }
    break;

  case 577:

/* Line 1455 of yacc.c  */
#line 3305 "sql.yacc"
    { sprintf((yyval.str),"%s,%s",(yyvsp[(1) - (3)].str),(yyvsp[(3) - (3)].str)); }
    break;

  case 579:

/* Line 1455 of yacc.c  */
#line 3309 "sql.yacc"
    {sprintf((yyval.str),"%s.%s",A4GLSQLCV_ownerize_tablename(NULL, (yyvsp[(1) - (3)].str)),(yyvsp[(3) - (3)].str));}
    break;

  case 580:

/* Line 1455 of yacc.c  */
#line 3310 "sql.yacc"
    {
        sprintf((yyval.str),"%s.%s", A4GLSQLCV_ownerize_tablename((yyvsp[(1) - (5)].str), (yyvsp[(3) - (5)].str)), (yyvsp[(5) - (5)].str));
}
    break;

  case 581:

/* Line 1455 of yacc.c  */
#line 3320 "sql.yacc"
    { print_exec_sql(acl_strdup((yyvsp[(1) - (1)].str))); }
    break;

  case 582:

/* Line 1455 of yacc.c  */
#line 3321 "sql.yacc"
    { print_exec_sql(acl_strdup((yyvsp[(1) - (1)].str))); }
    break;

  case 583:

/* Line 1455 of yacc.c  */
#line 3322 "sql.yacc"
    { sprintf((yyval.str),"%s %s",(yyvsp[(1) - (2)].str),(yyvsp[(2) - (2)].str)); print_exec_sql(acl_strdup((yyval.str))); }
    break;

  case 584:

/* Line 1455 of yacc.c  */
#line 3323 "sql.yacc"
    { print_exec_sql(acl_strdup((yyvsp[(1) - (1)].str))); }
    break;

  case 585:

/* Line 1455 of yacc.c  */
#line 3324 "sql.yacc"
    { print_exec_sql(acl_strdup((yyvsp[(1) - (1)].str))); }
    break;

  case 586:

/* Line 1455 of yacc.c  */
#line 3325 "sql.yacc"
    { print_exec_sql(acl_strdup((yyvsp[(1) - (1)].str))); }
    break;

  case 587:

/* Line 1455 of yacc.c  */
#line 3326 "sql.yacc"
    { print_exec_sql(acl_strdup((yyvsp[(1) - (1)].str))); }
    break;

  case 588:

/* Line 1455 of yacc.c  */
#line 3327 "sql.yacc"
    { print_exec_sql(acl_strdup((yyvsp[(1) - (1)].str))); }
    break;

  case 589:

/* Line 1455 of yacc.c  */
#line 3331 "sql.yacc"
    { 
	char *s;
	s=acl_strdup((yyvsp[(1) - (1)].str));
	(yyval.s_select_list_item)=new_select_list_item_column_from_transform(s);
	acl_free(s);
	}
    break;

  case 590:

/* Line 1455 of yacc.c  */
#line 3337 "sql.yacc"
    {  
		(yyval.s_select_list_item)=new_select_list_item_builtin_const(E_SLI_QUERY_PLACEHOLDER);}
    break;

  case 591:

/* Line 1455 of yacc.c  */
#line 3339 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_replace_var((yyvsp[(1) - (1)].sql_string));
	}
    break;

  case 592:

/* Line 1455 of yacc.c  */
#line 3358 "sql.yacc"
    {
        add_feature("DATABASE_USED");
       conn_db((yyvsp[(2) - (3)].str));
}
    break;

  case 593:

/* Line 1455 of yacc.c  */
#line 3366 "sql.yacc"
    {
		(yyval.sql_string)=acl_strdup((yyvsp[(2) - (3)].str));
}
    break;

  case 594:

/* Line 1455 of yacc.c  */
#line 3373 "sql.yacc"
    {sprintf((yyval.str),"(%s)",(yyvsp[(2) - (3)].str));}
    break;

  case 595:

/* Line 1455 of yacc.c  */
#line 3374 "sql.yacc"
    { sprintf((yyval.str),"%s%s%s",(yyvsp[(1) - (3)].str),(yyvsp[(2) - (3)].str),(yyvsp[(3) - (3)].str));}
    break;

  case 596:

/* Line 1455 of yacc.c  */
#line 3375 "sql.yacc"
    {sprintf((yyval.str),"%d",atoi((yyvsp[(1) - (1)].str)));}
    break;

  case 597:

/* Line 1455 of yacc.c  */
#line 3376 "sql.yacc"
    {sprintf((yyval.str),"(%s%s)",(yyvsp[(1) - (2)].str),(yyvsp[(2) - (2)].str));}
    break;

  case 598:

/* Line 1455 of yacc.c  */
#line 3381 "sql.yacc"
    {strcpy((yyval.str),"+");}
    break;

  case 599:

/* Line 1455 of yacc.c  */
#line 3382 "sql.yacc"
    {strcpy((yyval.str),"-");}
    break;

  case 600:

/* Line 1455 of yacc.c  */
#line 3383 "sql.yacc"
    {strcpy((yyval.str),"*");}
    break;

  case 601:

/* Line 1455 of yacc.c  */
#line 3384 "sql.yacc"
    {strcpy((yyval.str),"/");}
    break;

  case 602:

/* Line 1455 of yacc.c  */
#line 3385 "sql.yacc"
    {strcpy((yyval.str),"%");}
    break;

  case 603:

/* Line 1455 of yacc.c  */
#line 3390 "sql.yacc"
    {strcpy((yyval.str),"+");}
    break;

  case 604:

/* Line 1455 of yacc.c  */
#line 3391 "sql.yacc"
    {strcpy((yyval.str),"-");}
    break;

  case 605:

/* Line 1455 of yacc.c  */
#line 3407 "sql.yacc"
    {sprintf((yyval.str),"%s", A4GLSQLCV_check_tablename((yyvsp[(1) - (1)].str)));}
    break;

  case 606:

/* Line 1455 of yacc.c  */
#line 3408 "sql.yacc"
    {sprintf((yyval.str),"%s.*", A4GLSQLCV_ownerize_tablename(NULL,(yyvsp[(1) - (3)].str)));}
    break;

  case 607:

/* Line 1455 of yacc.c  */
#line 3409 "sql.yacc"
    {sprintf((yyval.str),"%s.%s", (yyvsp[(1) - (3)].str),A4GLSQLCV_get_sqlconst ("rowid"));}
    break;

  case 608:

/* Line 1455 of yacc.c  */
#line 3410 "sql.yacc"
    {sprintf((yyval.str),"%s.%s", A4GLSQLCV_ownerize_tablename(NULL,(yyvsp[(1) - (3)].str)),(yyvsp[(3) - (3)].str));}
    break;

  case 609:

/* Line 1455 of yacc.c  */
#line 3411 "sql.yacc"
    {sprintf((yyval.str),"%s.%s", A4GLSQLCV_ownerize_tablename((yyvsp[(1) - (5)].str),(yyvsp[(3) - (5)].str)),(yyvsp[(5) - (5)].str));}
    break;

  case 610:

/* Line 1455 of yacc.c  */
#line 3412 "sql.yacc"
    {sprintf((yyval.str),"%s.%s", A4GLSQLCV_ownerize_tablename((yyvsp[(1) - (5)].str),(yyvsp[(3) - (5)].str)),(yyvsp[(5) - (5)].str));}
    break;

  case 611:

/* Line 1455 of yacc.c  */
#line 3413 "sql.yacc"
    {sprintf((yyval.str),"%s", (yyvsp[(1) - (4)].str)); strcpy((yyval.str), A4GLSQLCV_make_substr_s((yyvsp[(1) - (4)].str), 1,(yyvsp[(3) - (4)].str),0));}
    break;

  case 612:

/* Line 1455 of yacc.c  */
#line 3414 "sql.yacc"
    {char buff[256]; sprintf(buff,"%s.%s", A4GLSQLCV_ownerize_tablename(NULL,(yyvsp[(1) - (6)].str)),(yyvsp[(3) - (6)].str)); strcpy((yyval.str), A4GLSQLCV_make_substr_s(buff,1,(yyvsp[(5) - (6)].str),0));}
    break;

  case 613:

/* Line 1455 of yacc.c  */
#line 3415 "sql.yacc"
    {char buff[256]; sprintf(buff,"%s.%s", A4GLSQLCV_ownerize_tablename((yyvsp[(1) - (8)].str),(yyvsp[(3) - (8)].str)), (yyvsp[(5) - (8)].str)); strcpy((yyval.str), A4GLSQLCV_make_substr_s(buff,1,(yyvsp[(7) - (8)].str),0));  }
    break;

  case 614:

/* Line 1455 of yacc.c  */
#line 3416 "sql.yacc"
    {char buff[256]; sprintf(buff,"%s.%s", A4GLSQLCV_ownerize_tablename((yyvsp[(1) - (8)].str),(yyvsp[(3) - (8)].str)), (yyvsp[(5) - (8)].str));  strcpy((yyval.str), A4GLSQLCV_make_substr_s(buff,1,(yyvsp[(7) - (8)].str),0)); }
    break;

  case 615:

/* Line 1455 of yacc.c  */
#line 3418 "sql.yacc"
    {sprintf((yyval.str),"%s", (yyvsp[(1) - (6)].str)); strcpy((yyval.str), A4GLSQLCV_make_substr_s((yyvsp[(1) - (6)].str), 2,(yyvsp[(3) - (6)].str),(yyvsp[(5) - (6)].str)));}
    break;

  case 616:

/* Line 1455 of yacc.c  */
#line 3419 "sql.yacc"
    {char buff[256]; sprintf(buff,"%s.%s", A4GLSQLCV_ownerize_tablename(NULL,(yyvsp[(1) - (8)].str)),(yyvsp[(3) - (8)].str)); strcpy((yyval.str), A4GLSQLCV_make_substr_s(buff,2,(yyvsp[(5) - (8)].str),(yyvsp[(7) - (8)].str)));}
    break;

  case 617:

/* Line 1455 of yacc.c  */
#line 3420 "sql.yacc"
    {char buff[256]; sprintf(buff,"%s.%s", A4GLSQLCV_ownerize_tablename((yyvsp[(1) - (10)].str),(yyvsp[(3) - (10)].str)), (yyvsp[(5) - (10)].str)); strcpy((yyval.str), A4GLSQLCV_make_substr_s(buff,2,(yyvsp[(7) - (10)].str),(yyvsp[(9) - (10)].str)));  }
    break;

  case 618:

/* Line 1455 of yacc.c  */
#line 3421 "sql.yacc"
    {char buff[256]; sprintf(buff,"%s.%s", A4GLSQLCV_ownerize_tablename((yyvsp[(1) - (10)].str),(yyvsp[(3) - (10)].str)), (yyvsp[(5) - (10)].str));  strcpy((yyval.str), A4GLSQLCV_make_substr_s(buff,2,(yyvsp[(7) - (10)].str),(yyvsp[(9) - (10)].str))); }
    break;

  case 619:

/* Line 1455 of yacc.c  */
#line 3426 "sql.yacc"
    {
                (yyval.s_select_list_item)=(yyvsp[(1) - (1)].s_select_list_item);
        }
    break;

  case 620:

/* Line 1455 of yacc.c  */
#line 3429 "sql.yacc"
    {
                (yyval.s_select_list_item)=new_select_list_item_cast((yyvsp[(1) - (3)].s_select_list_item), (yyvsp[(3) - (3)].str));
        }
    break;

  case 621:

/* Line 1455 of yacc.c  */
#line 3438 "sql.yacc"
    { (yyvsp[(1) - (1)].s_select_list_item)=(yyvsp[(1) - (1)].s_select_list_item); }
    break;

  case 622:

/* Line 1455 of yacc.c  */
#line 3439 "sql.yacc"
    {(yyvsp[(1) - (1)].s_select_list_item)=(yyvsp[(1) - (1)].s_select_list_item);}
    break;

  case 623:

/* Line 1455 of yacc.c  */
#line 3440 "sql.yacc"
    {  (yyval.s_select_list_item)=new_select_list_item_sq(E_SQE_DONT_CARE,(yyvsp[(1) - (1)].s_select_list_item)); }
    break;

  case 624:

/* Line 1455 of yacc.c  */
#line 3441 "sql.yacc"
    { (yyval.s_select_list_item)=new_select_list_item_sq(E_SQE_ALL,(yyvsp[(2) - (2)].s_select_list_item)); }
    break;

  case 625:

/* Line 1455 of yacc.c  */
#line 3442 "sql.yacc"
    { (yyval.s_select_list_item)=new_select_list_item_sq(E_SQE_ANY,(yyvsp[(2) - (2)].s_select_list_item)); }
    break;

  case 626:

/* Line 1455 of yacc.c  */
#line 3443 "sql.yacc"
    { (yyval.s_select_list_item)=new_select_list_item_sq(E_SQE_SOME,(yyvsp[(2) - (2)].s_select_list_item)); }
    break;

  case 627:

/* Line 1455 of yacc.c  */
#line 3447 "sql.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 628:

/* Line 1455 of yacc.c  */
#line 3448 "sql.yacc"
    {strcpy((yyval.str),(yyvsp[(1) - (1)].str));}
    break;



/* Line 1455 of yacc.c  */
#line 8904 "y.tab.c"
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
#line 3454 "sql.yacc"


#if LEX_YY_PREGEN
#include "../../tools/no_yacc/cygwin/compilers/sql/lex.sqlparse_yy.c"
#else
#include "lex.yy.c"
#endif
#include "util.c"
#include "cmds.c"

