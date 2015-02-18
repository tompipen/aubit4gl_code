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
     INT_VALUE = 2285,
     NAMED = 2286,
     NAMED_GEN = 2287,
     CHAR_VALUE = 2288,
     NOT_USED_1 = 2289,
     NOT_USED_2 = 2290,
     NOT_USED_3 = 2291,
     NOT_USED_4 = 2292,
     NOT_USED_5 = 2293,
     NOT_USED_6 = 2294,
     NOT_USED_7 = 2295,
     NOT_USED_8 = 2296,
     NUMBER_VALUE = 2297,
     SEMICOLON = 2298,
     QUESTION_MARK = 2299,
     CLINE = 2300,
     CH = 2301,
     MARK_VAR = 2302,
     END_MARK_VAR = 2303,
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
     CURRENT_FIELD_DISPLAY = 1151,
     CURRENT_ROW_DISPLAY = 1152,
     ALTER_TABLE = 1155,
     ALTER_INDEX = 1156,
     NEXT_SIZE = 1157,
     KW_WHENEVER_SIGNAL = 1194,
     KW_SIGNAL_TOKEN = 1195,
     XSET_MULTIPLY_EQUAL_OPEN_BRACKET = 1196,
     XSET_ident_DOT_MULTIPLY_EQUAL_OPEN_BRACKET = 1197,
     XSET_ident_DOT_MULTIPLY_EQUAL = 1198,
     XSET_MULTIPLY_EQUAL = 1199,
     XSET_OPEN_BRACKET = 1200,
     CREATE_DATABASE = 1203,
     DROP_DATABASE = 1204,
     ADD_CONSTRAINT = 1206,
     DROP_CONSTRAINT = 1207,
     DROP_SYNONYM = 1208,
     CONSTRAINT = 1209,
     NOT_FIELD_TOUCHED_CURRENT = 1212,
     FIELD_TOUCHED_CURRENT = 1213,
     OBJECT_FUNCTION = 1215,
     DOUBLE_PRECISION = 1221,
     COUNT_MULTIPLY = 1222,
     KW_ASCII_OPEN_BRACKET = 1231,
     MODIFY_NEXT_SIZE = 1243,
     LOCK_MODE_PAGE = 1244,
     LOCK_MODE_ROW = 1245,
     TO_UI = 1250,
     UNITS_YEAR = 1253,
     UNITS_MONTH = 1254,
     UNITS_DAY = 1255,
     UNITS_HOUR = 1256,
     UNITS_MINUTE = 1257,
     UNITS_SECOND = 1258,
     TO_CLUSTER = 1263,
     TO_NOT_CLUSTER = 1264,
     CREATE_UC_IDX = 1266,
     CREATE_U_IDX = 1267,
     CREATE_C_IDX = 1268,
     CREATE_IDX = 1269,
     DOUBLE_COLON = 1279,
     SQLSICS = 1285,
     CREATE_SCHEMA = 1286,
     SQLSIRR = 1287,
     UPDATESTATS_T = 1288,
     SQLSICR = 1289,
     SQLSIDR = 1300,
     CREATE_TEMP_TABLE = 1301,
     WITH_CHECK_OPTION = 1309,
     WITH_GRANT_OPTION = 1310,
     SQLSLMNW = 1311,
     WHERE_CURRENT_OF = 1317,
     NOT_NULL_UNIQUE = 1325,
     SQLSLMW = 1332,
     ALL_PRIVILEGES = 1334,
     CREATE_SYNONYM = 1338,
     DROP_TABLE = 1339,
     INEXCLUSIVE = 1341,
     REPORT_TO_FILE = 1342,
     REPORT_TO_UI = 1343,
     UPDATESTATS = 1348,
     CREATE_TABLE = 1374,
     DEFAULT_NULL = 1375,
     DEFAULT_TODAY = 1376,
     DEFAULT_USER = 1377,
     EXIT_TODO = 1384,
     CONTINUE_TODO = 1385,
     UNLOCK_TABLE = 1392,
     ROLLBACK_W = 1400,
     SQLSEON = 1402,
     SQLSEOFF = 1403,
     CREATE_VIEW = 1407,
     DELETE_FROM = 1408,
     EXTENT_SIZE = 1415,
     FOREIGN_KEY = 1416,
     INSERT_INTO = 1419,
     IS_NOT_NULL = 1421,
     NOT_MATCHES = 1424,
     PRIMARY_KEY = 1430,
     WITH_NO_LOG = 1437,
     INSHARE = 1440,
     BEGIN_WORK = 1446,
     DROP_INDEX = 1451,
     FOR_UPDATE_OF = 1457,
     FOR_UPDATE = 1458,
     LOCK_TABLE = 1463,
     NOT_EXISTS = 1465,
     REFERENCES = 1467,
     RENCOL = 1468,
     SMALLFLOAT = 1470,
     COMMIT_W = 1481,
     RENTAB = 1488,
     KW_CHAR = 1491,
     NCHAR = 1492,
     NVARCHAR = 1493,
     DELIMITER = 1495,
     DROP_VIEW = 1497,
     EXCLUSIVE = 1500,
     GREATER_THAN_EQ = 1504,
     INTO_TEMP = 1506,
     DATABASE = 1530,
     DATETIME = 1531,
     DISTINCT = 1533,
     FRACTION = 1540,
     GROUP_BY = 1542,
     INTERVAL = 1543,
     NOT_LIKE = 1545,
     NOT_ILIKE = 1546,
     NOT_NULL = 1547,
     RESOURCE = 1553,
     SMALLINT = 1554,
     IS_NULL = 1560,
     LESS_THAN_EQ = 1561,
     BETWEEN = 1563,
     CLOSE_BRACKET = 1566,
     CONNECT = 1569,
     KW_CURRENT = 1570,
     KW_DECIMAL = 1572,
     KW_DEFAULT = 1574,
     FGL_SYNCFIELDS = 1582,
     INTEGER = 1583,
     SERIAL8 = 1585,
     MATCHES = 1588,
     VARCHAR = 1601,
     CLOSE_SQUARE = 1604,
     GREATER_THAN = 1605,
     KW_FALSE = 1606,
     NOT_IN = 1607,
     OPEN_BRACKET_SELECT = 1609,
     OPEN_BRACKET = 1610,
     KW_DELETE = 1618,
     KW_ESCAPE = 1621,
     EXISTS = 1622,
     EXTEND = 1623,
     HAVING = 1627,
     KW_INSERT = 1629,
     MINUTE = 1633,
     MODIFY = 1634,
     EQUAL = 1636,
     NOT_EQUAL = 1637,
     OPEN_SQUARE = 1639,
     PUBLIC = 1643,
     KW_RETURN_KEY = 1646,
     REVOKE = 1648,
     SECOND = 1652,
     KW_SELECT = 1656,
     SERIAL = 1657,
     UNIQUE = 1660,
     KW_UPDATE = 1662,
     VALUES = 1663,
     KW_NULL = 1666,
     KW_TRUE = 1667,
     ALTER = 1669,
     CHECK = 1675,
     KW_FIRST = 1683,
     KW_FLOAT = 1684,
     GRANT = 1687,
     INDEX = 1690,
     LESS_THAN = 1693,
     MONEY = 1695,
     MONTH = 1696,
     KW_MULTIPLY = 1698,
     ORDER = 1699,
     OUTER = 1700,
     UNION = 1709,
     WHERE = 1712,
     KW_BYTE = 1719,
     CASE = 1721,
     KW_DATE = 1723,
     DESC = 1724,
     KW_DIVIDE = 1725,
     DROP = 1728,
     ELSE = 1729,
     FROM = 1733,
     HOUR = 1739,
     INTO = 1740,
     LIKE = 1743,
     REAL = 1752,
     SOME = 1757,
     KW_TEXT = 1761,
     KW_THEN = 1762,
     USER = 1763,
     WHEN = 1765,
     YEAR = 1768,
     KW_DOW = 1769,
     XSET = 1771,
     ADD = 1772,
     ALL = 1773,
     KW_AND = 1774,
     ANY = 1775,
     ASC = 1776,
     AVG = 1777,
     COLON = 1778,
     KW_COMMA = 1779,
     DAY = 1780,
     DBA = 1781,
     KW_FOR = 1785,
     XMAX = 1790,
     XMIN = 1791,
     KW_MINUS = 1792,
     KW_MOD = 1793,
     KW_NOT = 1794,
     KW_SUM = 1801,
     ATSIGN = 1804,
     KW_PLUS = 1805,
     KW_AS = 1811,
     KW_BY = 1813,
     KW_DOT = 1814,
     KW_IN = 1817,
     KW_ON = 1819,
     KW_OR = 1820,
     KW_TO = 1821,
     BEFORE = 1859,
     END = 1863,
     TILDE = 1870,
     ILIKE = 1871,
     FILLFACTOR = 1874,
     TIME = 1879,
     KW_TODAY = 1886,
     KW_ROWID = 1887,
     TIMESTAMP = 2235,
     KWPIPE = 2265,
     COUNT = 2278,
     DIALOG = 2279,
     SUBDIALOG = 2280,
     PDF_XY = 2281,
     SET_VALUE = 2282,
     KW_EMBEDDED = 2283
   };
#endif
/* Tokens.  */
#define INT_VALUE 2285
#define NAMED 2286
#define NAMED_GEN 2287
#define CHAR_VALUE 2288
#define NOT_USED_1 2289
#define NOT_USED_2 2290
#define NOT_USED_3 2291
#define NOT_USED_4 2292
#define NOT_USED_5 2293
#define NOT_USED_6 2294
#define NOT_USED_7 2295
#define NOT_USED_8 2296
#define NUMBER_VALUE 2297
#define SEMICOLON 2298
#define QUESTION_MARK 2299
#define CLINE 2300
#define CH 2301
#define MARK_VAR 2302
#define END_MARK_VAR 2303
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
#define CURRENT_FIELD_DISPLAY 1151
#define CURRENT_ROW_DISPLAY 1152
#define ALTER_TABLE 1155
#define ALTER_INDEX 1156
#define NEXT_SIZE 1157
#define KW_WHENEVER_SIGNAL 1194
#define KW_SIGNAL_TOKEN 1195
#define XSET_MULTIPLY_EQUAL_OPEN_BRACKET 1196
#define XSET_ident_DOT_MULTIPLY_EQUAL_OPEN_BRACKET 1197
#define XSET_ident_DOT_MULTIPLY_EQUAL 1198
#define XSET_MULTIPLY_EQUAL 1199
#define XSET_OPEN_BRACKET 1200
#define CREATE_DATABASE 1203
#define DROP_DATABASE 1204
#define ADD_CONSTRAINT 1206
#define DROP_CONSTRAINT 1207
#define DROP_SYNONYM 1208
#define CONSTRAINT 1209
#define NOT_FIELD_TOUCHED_CURRENT 1212
#define FIELD_TOUCHED_CURRENT 1213
#define OBJECT_FUNCTION 1215
#define DOUBLE_PRECISION 1221
#define COUNT_MULTIPLY 1222
#define KW_ASCII_OPEN_BRACKET 1231
#define MODIFY_NEXT_SIZE 1243
#define LOCK_MODE_PAGE 1244
#define LOCK_MODE_ROW 1245
#define TO_UI 1250
#define UNITS_YEAR 1253
#define UNITS_MONTH 1254
#define UNITS_DAY 1255
#define UNITS_HOUR 1256
#define UNITS_MINUTE 1257
#define UNITS_SECOND 1258
#define TO_CLUSTER 1263
#define TO_NOT_CLUSTER 1264
#define CREATE_UC_IDX 1266
#define CREATE_U_IDX 1267
#define CREATE_C_IDX 1268
#define CREATE_IDX 1269
#define DOUBLE_COLON 1279
#define SQLSICS 1285
#define CREATE_SCHEMA 1286
#define SQLSIRR 1287
#define UPDATESTATS_T 1288
#define SQLSICR 1289
#define SQLSIDR 1300
#define CREATE_TEMP_TABLE 1301
#define WITH_CHECK_OPTION 1309
#define WITH_GRANT_OPTION 1310
#define SQLSLMNW 1311
#define WHERE_CURRENT_OF 1317
#define NOT_NULL_UNIQUE 1325
#define SQLSLMW 1332
#define ALL_PRIVILEGES 1334
#define CREATE_SYNONYM 1338
#define DROP_TABLE 1339
#define INEXCLUSIVE 1341
#define REPORT_TO_FILE 1342
#define REPORT_TO_UI 1343
#define UPDATESTATS 1348
#define CREATE_TABLE 1374
#define DEFAULT_NULL 1375
#define DEFAULT_TODAY 1376
#define DEFAULT_USER 1377
#define EXIT_TODO 1384
#define CONTINUE_TODO 1385
#define UNLOCK_TABLE 1392
#define ROLLBACK_W 1400
#define SQLSEON 1402
#define SQLSEOFF 1403
#define CREATE_VIEW 1407
#define DELETE_FROM 1408
#define EXTENT_SIZE 1415
#define FOREIGN_KEY 1416
#define INSERT_INTO 1419
#define IS_NOT_NULL 1421
#define NOT_MATCHES 1424
#define PRIMARY_KEY 1430
#define WITH_NO_LOG 1437
#define INSHARE 1440
#define BEGIN_WORK 1446
#define DROP_INDEX 1451
#define FOR_UPDATE_OF 1457
#define FOR_UPDATE 1458
#define LOCK_TABLE 1463
#define NOT_EXISTS 1465
#define REFERENCES 1467
#define RENCOL 1468
#define SMALLFLOAT 1470
#define COMMIT_W 1481
#define RENTAB 1488
#define KW_CHAR 1491
#define NCHAR 1492
#define NVARCHAR 1493
#define DELIMITER 1495
#define DROP_VIEW 1497
#define EXCLUSIVE 1500
#define GREATER_THAN_EQ 1504
#define INTO_TEMP 1506
#define DATABASE 1530
#define DATETIME 1531
#define DISTINCT 1533
#define FRACTION 1540
#define GROUP_BY 1542
#define INTERVAL 1543
#define NOT_LIKE 1545
#define NOT_ILIKE 1546
#define NOT_NULL 1547
#define RESOURCE 1553
#define SMALLINT 1554
#define IS_NULL 1560
#define LESS_THAN_EQ 1561
#define BETWEEN 1563
#define CLOSE_BRACKET 1566
#define CONNECT 1569
#define KW_CURRENT 1570
#define KW_DECIMAL 1572
#define KW_DEFAULT 1574
#define FGL_SYNCFIELDS 1582
#define INTEGER 1583
#define SERIAL8 1585
#define MATCHES 1588
#define VARCHAR 1601
#define CLOSE_SQUARE 1604
#define GREATER_THAN 1605
#define KW_FALSE 1606
#define NOT_IN 1607
#define OPEN_BRACKET_SELECT 1609
#define OPEN_BRACKET 1610
#define KW_DELETE 1618
#define KW_ESCAPE 1621
#define EXISTS 1622
#define EXTEND 1623
#define HAVING 1627
#define KW_INSERT 1629
#define MINUTE 1633
#define MODIFY 1634
#define EQUAL 1636
#define NOT_EQUAL 1637
#define OPEN_SQUARE 1639
#define PUBLIC 1643
#define KW_RETURN_KEY 1646
#define REVOKE 1648
#define SECOND 1652
#define KW_SELECT 1656
#define SERIAL 1657
#define UNIQUE 1660
#define KW_UPDATE 1662
#define VALUES 1663
#define KW_NULL 1666
#define KW_TRUE 1667
#define ALTER 1669
#define CHECK 1675
#define KW_FIRST 1683
#define KW_FLOAT 1684
#define GRANT 1687
#define INDEX 1690
#define LESS_THAN 1693
#define MONEY 1695
#define MONTH 1696
#define KW_MULTIPLY 1698
#define ORDER 1699
#define OUTER 1700
#define UNION 1709
#define WHERE 1712
#define KW_BYTE 1719
#define CASE 1721
#define KW_DATE 1723
#define DESC 1724
#define KW_DIVIDE 1725
#define DROP 1728
#define ELSE 1729
#define FROM 1733
#define HOUR 1739
#define INTO 1740
#define LIKE 1743
#define REAL 1752
#define SOME 1757
#define KW_TEXT 1761
#define KW_THEN 1762
#define USER 1763
#define WHEN 1765
#define YEAR 1768
#define KW_DOW 1769
#define XSET 1771
#define ADD 1772
#define ALL 1773
#define KW_AND 1774
#define ANY 1775
#define ASC 1776
#define AVG 1777
#define COLON 1778
#define KW_COMMA 1779
#define DAY 1780
#define DBA 1781
#define KW_FOR 1785
#define XMAX 1790
#define XMIN 1791
#define KW_MINUS 1792
#define KW_MOD 1793
#define KW_NOT 1794
#define KW_SUM 1801
#define ATSIGN 1804
#define KW_PLUS 1805
#define KW_AS 1811
#define KW_BY 1813
#define KW_DOT 1814
#define KW_IN 1817
#define KW_ON 1819
#define KW_OR 1820
#define KW_TO 1821
#define BEFORE 1859
#define END 1863
#define TILDE 1870
#define ILIKE 1871
#define FILLFACTOR 1874
#define TIME 1879
#define KW_TODAY 1886
#define KW_ROWID 1887
#define TIMESTAMP 2235
#define KWPIPE 2265
#define COUNT 2278
#define DIALOG 2279
#define SUBDIALOG 2280
#define PDF_XY 2281
#define SET_VALUE 2282
#define KW_EMBEDDED 2283




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
#line 908 "y.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 920 "y.tab.c"

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
#define YYLAST   2259

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  313
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  229
/* YYNRULES -- Number of rules.  */
#define YYNRULES  633
/* YYNRULES -- Number of states.  */
#define YYNSTATES  1115

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   2303

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
      84,    85,    86,     2,     2,    87,    88,    89,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,    90,    91,    92,    93,    94,    95,
      96,     2,     2,    97,    98,     2,    99,   100,   101,   102,
       2,     2,   103,   104,     2,   105,     2,     2,     2,     2,
       2,   106,   107,     2,     2,     2,     2,     2,     2,     2,
       2,   108,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   109,   110,   111,     2,     2,     2,     2,
     112,     2,     2,   113,   114,   115,   116,   117,   118,     2,
       2,     2,     2,   119,   120,     2,   121,   122,   123,   124,
       2,     2,     2,     2,     2,     2,     2,     2,     2,   125,
       2,     2,     2,     2,     2,   126,   127,   128,   129,   130,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     131,   132,     2,     2,     2,     2,     2,     2,     2,   133,
     134,   135,     2,     2,     2,     2,     2,   136,     2,     2,
       2,     2,     2,     2,     2,   137,     2,     2,     2,     2,
       2,     2,   138,     2,   139,     2,     2,     2,   140,   141,
       2,   142,   143,   144,     2,     2,     2,     2,   145,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,   146,   147,   148,   149,     2,     2,
       2,     2,     2,     2,   150,   151,     2,     2,     2,     2,
       2,     2,   152,     2,     2,     2,     2,     2,     2,     2,
     153,     2,   154,   155,     2,     2,     2,   156,   157,     2,
       2,     2,     2,     2,     2,   158,   159,     2,     2,   160,
       2,   161,     2,     2,   162,     2,     2,     2,     2,     2,
     163,     2,     2,     2,     2,     2,     2,   164,     2,     2,
     165,     2,     2,     2,     2,     2,   166,     2,     2,     2,
       2,   167,     2,     2,     2,     2,     2,   168,   169,     2,
       2,     2,     2,   170,     2,   171,     2,   172,   173,     2,
     174,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,   175,     2,     2,     2,     2,     2,     2,   176,     2,
       2,   177,   178,   179,     2,   180,     2,   181,     2,     2,
     182,     2,     2,     2,   183,     2,   184,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     185,   186,     2,   187,     2,     2,     2,     2,     2,     2,
     188,     2,   189,   190,     2,   191,   192,   193,     2,     2,
       2,     2,     2,   194,   195,     2,     2,     2,     2,     2,
     196,   197,     2,   198,     2,     2,   199,     2,     2,   200,
     201,     2,   202,     2,   203,     2,     2,     2,     2,     2,
       2,     2,   204,   205,     2,   206,     2,     2,   207,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,   208,     2,     2,   209,   210,   211,   212,     2,   213,
     214,     2,     2,     2,     2,     2,     2,     2,   215,     2,
       2,   216,   217,   218,     2,     2,     2,   219,     2,   220,
       2,     2,     2,   221,   222,     2,   223,   224,     2,   225,
       2,     2,     2,   226,     2,     2,   227,     2,   228,     2,
       2,     2,   229,     2,     2,     2,   230,   231,     2,     2,
     232,     2,   233,   234,     2,     2,   235,   236,     2,   237,
       2,     2,     2,     2,     2,   238,     2,     2,     2,     2,
       2,     2,     2,   239,   240,     2,     2,   241,     2,     2,
     242,     2,     2,   243,     2,   244,   245,     2,   246,   247,
     248,     2,     2,     2,     2,     2,     2,     2,     2,   249,
       2,     2,   250,     2,     2,     2,     2,     2,     2,   251,
       2,   252,     2,   253,   254,   255,     2,     2,   256,   257,
       2,     2,     2,   258,     2,     2,     2,     2,     2,   259,
     260,     2,     2,   261,     2,     2,     2,     2,     2,     2,
       2,     2,   262,     2,     2,     2,     2,   263,     2,     2,
       2,   264,   265,   266,     2,   267,     2,     2,   268,   269,
       2,   270,   271,   272,   273,   274,   275,   276,   277,   278,
     279,   280,     2,     2,     2,   281,     2,     2,     2,     2,
     282,   283,   284,   285,   286,     2,     2,     2,     2,     2,
       2,   287,     2,     2,   288,   289,     2,     2,     2,     2,
       2,   290,     2,   291,   292,     2,     2,   293,     2,   294,
     295,   296,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,   297,
       2,     2,     2,   298,     2,     2,     2,     2,     2,     2,
     299,   300,     2,     2,   301,     2,     2,     2,     2,   302,
       2,     2,     2,     2,     2,     2,   303,   304,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,   305,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,   306,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,   307,   308,
     309,   310,   311,   312,     2,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21
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
     521,     0,    -1,   233,   512,   541,   317,   315,    -1,    -1,
     136,   516,    -1,   250,   426,    -1,    -1,   136,   516,    -1,
     250,   426,    -1,    96,   322,   199,   223,   214,   323,   199,
      -1,    92,   323,   199,    -1,    93,   323,   199,    -1,   270,
     318,    -1,    95,   323,    -1,    94,   323,    -1,   321,    -1,
     318,   278,   321,    -1,   320,    -1,   288,   320,    -1,   515,
     452,    -1,   515,   292,   515,   452,    -1,   515,   292,   515,
     292,   515,   452,    -1,   515,   292,   246,    -1,   319,   223,
     324,    -1,   319,    -1,   322,   278,   319,    -1,   324,    -1,
     323,   278,   324,    -1,   499,    -1,   235,    -1,   326,    -1,
     141,   512,    -1,   181,   512,    -1,   167,   514,    -1,    80,
     515,    -1,   337,    -1,   328,    -1,   146,   512,   214,   342,
     199,   329,    -1,   132,   512,   214,   342,   199,   338,   329,
     338,    -1,    -1,   330,    -1,   331,    -1,   330,   331,    -1,
     293,   332,    -1,   158,     3,    -1,    89,     3,    -1,   110,
      -1,   111,    -1,     4,    -1,    -1,   334,    -1,   335,    -1,
     334,   335,    -1,   293,   332,    -1,   301,     3,    -1,    63,
      -1,    64,    -1,   512,    -1,   122,   514,   294,   336,   214,
     340,   199,   333,    -1,   121,   514,   294,   336,   214,   340,
     199,   333,    -1,   123,   514,   294,   336,   214,   340,   199,
     333,    -1,   124,   514,   294,   336,   214,   340,   199,   333,
      -1,    97,   525,    -1,    98,   525,    -1,   140,   512,   281,
     512,    -1,    82,   512,   293,     6,    -1,    81,   512,    -1,
     101,   512,    -1,    77,   512,    -1,    78,   515,    -1,    -1,
     164,    -1,    -1,   164,    -1,   341,    -1,   340,   278,   341,
      -1,   515,   275,    -1,   515,   254,    -1,   515,    -1,   343,
      -1,   342,   278,   343,    -1,   406,    -1,   404,    -1,    87,
     515,   345,    -1,    88,   514,   119,    -1,    88,   514,   120,
      -1,   346,    -1,   345,   278,   346,    -1,   347,    -1,   350,
      -1,   353,    -1,   358,    -1,   361,    -1,   357,    -1,   356,
      -1,   271,   348,    -1,   271,   214,   349,   199,    -1,   343,
      -1,   343,   297,   515,    -1,   348,    -1,   349,   278,   348,
      -1,   256,   352,    -1,   256,   214,   351,   199,    -1,   352,
      -1,   351,   278,   352,    -1,   515,    -1,   222,   355,    -1,
     222,   214,   354,   199,    -1,   355,    -1,   354,   278,   355,
      -1,   343,    -1,   110,    -1,   111,    -1,   109,     3,    -1,
      99,   404,   360,    -1,    99,   214,   359,   199,    -1,   404,
     360,    -1,   359,   278,   404,   360,    -1,    -1,   102,   515,
      -1,   100,   362,    -1,   100,   214,   362,   199,    -1,   363,
      -1,   362,   278,   363,    -1,   515,    -1,   153,    -1,    -1,
     160,   366,   512,   369,   367,    -1,    -1,   234,   368,   214,
     372,   199,    -1,   492,    -1,    -1,   214,   370,   199,    -1,
     371,    -1,   370,   278,   371,    -1,   515,    -1,   515,   292,
     515,    -1,   373,    -1,   372,   278,   373,    -1,   499,    -1,
     235,    -1,   157,   541,   512,   316,    -1,   166,    -1,   175,
      -1,    -1,   182,    -1,   379,    -1,    72,   515,    73,     6,
      71,    -1,    72,   515,    73,     6,    -1,    74,    -1,    67,
      -1,    68,    -1,   129,   515,    -1,   145,    -1,   376,    -1,
     375,    -1,   364,    -1,   378,    -1,   412,    -1,   416,    -1,
     462,    -1,   325,    -1,   327,    -1,   344,    -1,   241,   385,
     294,   512,   296,   390,   384,    -1,   228,   385,   294,   512,
     258,   390,    -1,   241,   383,   296,   390,    -1,   228,   383,
     258,   390,    -1,   200,    -1,   194,    -1,   280,    -1,    -1,
     134,    -1,   290,   451,    -1,   139,    -1,   272,    -1,   386,
      -1,   387,    -1,   386,   278,   387,    -1,   230,   388,    -1,
     220,    -1,   215,    -1,   233,   388,    -1,   237,    -1,   242,
      -1,    -1,   214,   389,   199,    -1,   453,    -1,   389,   278,
     453,    -1,   391,    -1,   390,   278,   391,    -1,   226,    -1,
     451,    -1,   156,   512,   393,   290,   483,   395,    -1,    -1,
     214,   394,   199,    -1,   453,    -1,   394,   278,   453,    -1,
      -1,   133,    -1,   238,   214,   482,   199,    -1,   159,   214,
     399,   199,   398,    -1,   172,   400,    -1,   401,    -1,   512,
      -1,   512,   214,   401,   199,    -1,   453,    -1,   401,   278,
     453,    -1,   232,   214,   403,   199,    -1,   187,   214,   403,
     199,    -1,   163,   214,   403,   199,    -1,   453,    -1,   403,
     278,   453,    -1,   402,    -1,   397,    -1,   396,    -1,   203,
     458,    -1,   149,    -1,   148,    -1,   147,    -1,   515,   442,
     407,   408,    -1,    -1,   405,    -1,    -1,   409,    -1,   410,
      -1,   409,   410,    -1,   411,   360,    -1,   193,    -1,   137,
      -1,   232,    -1,   187,    -1,   398,    -1,   238,   214,   482,
     199,    -1,   163,    -1,   127,   413,   415,    -1,   414,    -1,
     451,    -1,   416,    -1,   415,   416,    -1,   392,    -1,   382,
      -1,   219,   426,    -1,   250,   426,    -1,   258,   420,    -1,
     422,    -1,   420,   278,   422,    -1,   420,   278,   248,   422,
      -1,   420,   278,   248,   214,   420,   199,    -1,   420,    49,
     421,   294,   426,    -1,   420,    56,   421,   294,   426,    -1,
     420,    -1,   214,   420,   199,    -1,   512,    -1,   512,   457,
      -1,   512,   290,   457,    -1,    -1,   419,   424,    -1,   425,
      -1,   418,   425,    -1,    -1,   479,    -1,   479,   417,    -1,
     417,    -1,   427,    -1,   426,   295,   427,    -1,   428,    -1,
     427,   273,   428,    -1,   429,    -1,   286,   429,    -1,   439,
      -1,   214,   426,   199,    -1,   217,   493,    -1,   171,   493,
      -1,    -1,   216,   435,    -1,    -1,   216,   435,    -1,    -1,
     216,   435,    -1,   538,    -1,   458,    -1,    -1,   286,    -1,
     499,   436,   196,    -1,   499,   436,   161,    -1,   499,   438,
     499,    -1,   499,   223,   499,    -1,   499,   223,   235,    -1,
     499,   436,   198,   499,   273,   499,    -1,   499,   261,   434,
     433,    -1,   499,   191,   434,   433,    -1,   499,   300,   434,
     432,    -1,   499,   192,   434,   432,    -1,   499,   207,   434,
     431,    -1,   499,   162,   434,   431,    -1,   224,    -1,   243,
      -1,   210,    -1,   299,    -1,   197,    -1,   183,    -1,   437,
      -1,   507,    -1,   430,    -1,   499,    -1,    -1,   272,    -1,
     187,    -1,   232,    -1,    -1,   272,    -1,   187,    -1,   232,
      -1,   443,    -1,   444,    -1,   445,    -1,   447,    -1,   177,
      -1,   177,   214,   448,   199,    -1,   231,    -1,   231,   214,
       3,   199,    -1,   206,    -1,   206,   214,     3,   199,    -1,
     202,    -1,   202,   214,   449,   446,   199,    -1,   244,   214,
     449,   446,   199,    -1,   244,    -1,   253,    -1,   205,    -1,
     195,    -1,   178,    -1,   178,   214,   448,   199,    -1,   179,
      -1,   179,   214,     3,   199,    -1,   179,   214,     3,   278,
       3,   199,    -1,   186,   460,   296,   461,    -1,   186,    -1,
     190,   460,   296,   461,    -1,   484,    -1,   190,    -1,   190,
     460,   214,     3,   199,   296,   461,    -1,   264,    -1,   251,
      -1,   208,    -1,   208,   214,     3,   199,    -1,   208,   214,
       3,   278,     3,   199,    -1,    -1,   278,   450,    -1,   240,
     214,   449,   199,    -1,   262,    -1,   174,    -1,   240,    -1,
     106,    -1,     3,    -1,     3,    -1,     3,    -1,   515,    -1,
       6,    -1,    -1,   225,     3,   209,    -1,   225,     3,   278,
       3,   209,    -1,   456,    -1,   288,   456,    -1,   455,    -1,
     288,   455,    -1,   515,   452,    -1,   510,   292,   515,   452,
      -1,   510,   292,   246,    -1,   304,    -1,   515,   452,    -1,
     510,   292,   515,   452,    -1,   515,   292,   515,   292,   515,
     452,    -1,   510,   292,   246,    -1,   515,    -1,     6,    -1,
     517,    -1,     3,    -1,   473,    -1,    -1,   460,   296,   461,
      -1,   268,    -1,   245,    -1,   279,    -1,   259,    -1,   221,
      -1,   229,    -1,   188,    -1,   268,    -1,   245,    -1,   279,
      -1,   259,    -1,   221,    -1,   229,    -1,   188,    -1,   188,
     214,     3,   199,    -1,   467,    -1,   466,    -1,   463,    -1,
     176,   464,   296,   464,    -1,   173,   510,   292,   465,   296,
     465,    -1,   515,    -1,   515,    -1,   152,   512,    -1,   170,
     512,   468,    -1,   165,    -1,   142,    -1,   470,    -1,   470,
     460,   296,   461,    -1,    75,    -1,   472,    -1,   472,   460,
     214,     3,   199,   296,   461,    -1,   472,   460,   296,   461,
      -1,    76,    -1,   201,   459,    -1,   247,   291,   475,    -1,
     476,    -1,   475,   278,   476,    -1,   477,   478,    -1,     3,
      -1,   454,    -1,    -1,   275,    -1,   254,    -1,   189,   480,
      -1,   481,    -1,   480,   278,   481,    -1,   454,    -1,     3,
      -1,   426,    -1,   492,    -1,   302,    -1,   302,   214,     3,
     199,    -1,   305,    -1,   305,   214,     3,   199,    -1,    -1,
      -1,   230,   494,   495,   486,   496,   487,   519,   423,   489,
     490,    -1,   230,   494,   495,   496,   423,   489,    -1,    -1,
     249,   441,   488,    -1,    -1,   474,    -1,   474,   184,   491,
     339,    -1,   184,   491,   339,    -1,   515,    -1,   230,   494,
     495,   496,   423,    -1,   213,   494,   495,   496,   423,   199,
      -1,    -1,   239,     3,    -1,    -1,   272,    -1,   187,    -1,
     232,    -1,   497,    -1,   498,    -1,   496,   278,   498,    -1,
     499,    -1,   499,   515,    -1,   499,   290,   515,    -1,   538,
      -1,   284,   538,    -1,   289,   538,    -1,   538,   255,   499,
      -1,   538,   506,    -1,   538,   246,   499,    -1,   538,   289,
     499,    -1,   538,   284,   499,    -1,   538,    79,   499,    -1,
     458,    -1,   236,    -1,   211,    -1,   266,    -1,   303,    -1,
     304,    -1,   302,    -1,   246,    -1,   107,    -1,   276,   214,
     440,   499,   199,    -1,   282,   214,   440,   499,   199,    -1,
     283,   214,   440,   499,   199,    -1,   287,   214,   440,   499,
     199,    -1,   307,   214,   440,   499,   199,    -1,     4,   214,
     199,    -1,     4,   214,   503,   199,    -1,   268,   214,   503,
     199,    -1,   245,   214,   503,   199,    -1,   279,   214,   503,
     199,    -1,    69,   214,   503,   199,    -1,    70,   214,   503,
     199,    -1,   269,   214,   503,   199,    -1,   253,   214,   503,
     199,    -1,   214,   499,   199,    -1,   218,   214,   505,   199,
      -1,   469,    -1,   471,    -1,   252,   501,   298,    -1,   252,
     426,   501,   298,    -1,   502,    -1,   501,   502,    -1,   267,
     426,   265,   499,    -1,   257,   499,    -1,   499,    -1,   503,
     278,   499,    -1,    -1,   278,   460,   296,   461,    -1,   460,
     296,   461,    -1,    -1,   531,   504,    -1,   499,   504,    -1,
     113,    -1,   114,    -1,   115,    -1,   116,    -1,   117,    -1,
     118,    -1,   499,   293,   214,   508,   199,    -1,   499,   293,
     493,    -1,   499,   212,   214,   508,   199,    -1,   499,   212,
     493,    -1,   509,    -1,   508,   278,   509,    -1,   531,    -1,
     458,    -1,   284,     3,    -1,   284,   517,    -1,   511,    -1,
       6,    -1,     6,   292,   515,    -1,   515,    -1,   515,   277,
     515,    -1,   515,   277,     6,   292,   515,    -1,   515,   288,
     515,    -1,   515,   288,   515,   277,   515,    -1,   515,   288,
     515,   277,     6,   292,   515,    -1,   513,    -1,     6,   292,
     515,    -1,   515,   292,   515,    -1,     6,    -1,   515,    -1,
     515,   277,   515,    -1,   515,   277,     6,   292,   515,    -1,
     515,   288,   515,    -1,   515,   288,   515,   277,   515,    -1,
     515,   288,   515,   277,     6,   292,   515,    -1,     6,   292,
     515,    -1,     6,    -1,   515,    -1,   515,   277,   515,    -1,
     515,   277,     6,   292,   515,    -1,   515,   288,   515,    -1,
     515,   288,   515,   277,   515,    -1,   515,   288,   515,   277,
       6,   292,   515,    -1,     4,    -1,     4,    -1,    15,    -1,
     292,     3,    -1,     4,    -1,     6,    -1,    -1,   515,    -1,
     523,    -1,   521,    16,   523,    -1,   365,    -1,   314,    -1,
     374,    -1,    -1,   532,    -1,   381,    -1,   524,    -1,   530,
      -1,   522,    -1,   380,    -1,     1,    -1,   526,   527,    -1,
     520,    -1,   485,    -1,    -1,   169,    -1,   168,   528,    -1,
     529,    -1,   528,   278,   529,    -1,   515,    -1,   515,   292,
     515,    -1,     6,   292,   515,   292,   515,    -1,   155,    -1,
     154,    -1,   138,   540,    -1,   135,    -1,   131,    -1,   128,
      -1,   126,    -1,   130,    -1,   537,    -1,    17,    -1,   533,
      -1,   185,   518,   377,    -1,    20,     6,    21,    -1,   214,
     534,   199,    -1,   534,   535,   534,    -1,     3,    -1,   536,
       3,    -1,   289,    -1,   284,    -1,   246,    -1,   255,    -1,
     285,    -1,   289,    -1,   284,    -1,   515,    -1,   515,   292,
     246,    -1,   515,   292,   304,    -1,   515,   292,   515,    -1,
     515,   292,   515,   292,   515,    -1,     6,   292,   515,   292,
     515,    -1,   515,   225,   534,   209,    -1,   515,   292,   515,
     225,   534,   209,    -1,   515,   292,   515,   292,   515,   225,
     534,   209,    -1,     6,   292,   515,   292,   515,   225,   534,
     209,    -1,   515,   225,   534,   278,   534,   209,    -1,   515,
     292,   515,   225,   534,   278,   534,   209,    -1,   515,   292,
     515,   292,   515,   225,   534,   278,   534,   209,    -1,     6,
     292,   515,   292,   515,   225,   534,   278,   534,   209,    -1,
     539,    -1,   539,   125,   442,    -1,   500,    -1,   531,    -1,
     493,    -1,   272,   493,    -1,   274,   493,    -1,   263,   493,
      -1,    -1,     3,    -1,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   488,   488,   517,   520,   537,   542,   545,   562,   568,
     577,   586,   595,   602,   617,   672,   679,   690,   693,   698,
     705,   722,   739,   760,   769,   772,   780,   783,   791,   792,
     799,   802,   810,   813,   817,   823,   824,   828,   838,   852,
     853,   857,   858,   863,   871,   879,   887,   895,   905,   907,
     907,   910,   911,   915,   922,   929,   936,   945,   949,   956,
     968,   979,   985,   989,   993,   998,  1002,  1005,  1009,  1012,
    1019,  1020,  1030,  1031,  1035,  1036,  1040,  1049,  1058,  1065,
    1068,  1074,  1077,  1088,  1092,  1097,  1104,  1107,  1116,  1119,
    1123,  1127,  1131,  1135,  1139,  1147,  1151,  1159,  1162,  1169,
    1172,  1179,  1182,  1189,  1190,  1195,  1199,  1202,  1208,  1211,
    1217,  1224,  1225,  1229,  1237,  1241,  1248,  1250,  1255,  1256,
    1260,  1262,  1268,  1269,  1272,  1283,  1289,  1289,  1298,  1298,
    1307,  1332,  1335,  1343,  1346,  1353,  1356,  1364,  1365,  1371,
    1372,  1380,  1402,  1406,  1411,  1412,  1422,  1431,  1435,  1439,
    1444,  1448,  1452,  1455,  1462,  1468,  1473,  1481,  1482,  1483,
    1484,  1485,  1486,  1487,  1495,  1496,  1497,  1498,  1503,  1504,
    1505,  1508,  1509,  1510,  1514,  1515,  1516,  1520,  1521,  1525,
    1532,  1533,  1534,  1541,  1542,  1545,  1546,  1551,  1552,  1557,
    1558,  1563,  1564,  1569,  1576,  1577,  1582,  1583,  1587,  1588,
    1595,  1603,  1610,  1617,  1621,  1622,  1627,  1628,  1634,  1638,
    1643,  1650,  1651,  1657,  1660,  1663,  1670,  1671,  1672,  1673,
    1679,  1702,  1703,  1706,  1708,  1715,  1718,  1724,  1732,  1737,
    1743,  1748,  1754,  1757,  1762,  1770,  1779,  1784,  1788,  1789,
    1795,  1798,  1809,  1818,  1825,  1831,  1832,  1835,  1840,  1851,
    1855,  1862,  1863,  1867,  1871,  1875,  1882,  1887,  1895,  1898,
    1904,  1907,  1912,  1917,  1930,  1933,  1939,  1942,  1948,  1951,
    1957,  1960,  1967,  1971,  1982,  1982,  1983,  1983,  1984,  1984,
    1987,  1992,  1997,  1998,  2003,  2012,  2020,  2023,  2026,  2030,
    2037,  2040,  2044,  2047,  2050,  2053,  2059,  2066,  2069,  2072,
    2075,  2076,  2081,  2084,  2087,  2090,  2097,  2098,  2099,  2103,
    2110,  2111,  2112,  2116,  2130,  2137,  2138,  2139,  2143,  2144,
    2149,  2150,  2159,  2161,  2170,  2173,  2181,  2191,  2199,  2201,
    2202,  2203,  2204,  2205,  2206,  2207,  2215,  2216,  2217,  2218,
    2219,  2220,  2221,  2222,  2223,  2224,  2225,  2235,  2236,  2242,
    2244,  2245,  2246,  2247,  2251,  2255,  2259,  2266,  2267,  2272,
    2273,  2277,  2285,  2288,  2295,  2298,  2308,  2311,  2314,  2317,
    2324,  2331,  2339,  2348,  2355,  2359,  2364,  2365,  2366,  2371,
    2372,  2381,  2381,  2381,  2381,  2381,  2381,  2381,  2382,  2382,
    2382,  2382,  2382,  2382,  2382,  2382,  2427,  2428,  2429,  2434,
    2435,  2438,  2439,  2443,  2450,  2461,  2462,  2475,  2476,  2480,
    2484,  2485,  2488,  2494,  2498,  2521,  2531,  2534,  2540,  2549,
    2553,  2560,  2561,  2563,  2568,  2574,  2577,  2583,  2584,  2591,
    2604,  2614,  2621,  2638,  2645,  2670,  2672,  2670,  2694,  2738,
    2739,  2753,  2756,  2763,  2773,  2785,  2791,  2804,  2819,  2821,
    2827,  2828,  2829,  2830,  2840,  2847,  2850,  2856,  2859,  2864,
    2873,  2876,  2880,  2887,  2890,  2893,  2896,  2899,  2902,  2905,
    2906,  2907,  2908,  2909,  2910,  2911,  2912,  2913,  2915,  2919,
    2923,  2927,  2931,  2935,  2939,  2943,  2946,  2949,  2952,  2955,
    2958,  2961,  2964,  2967,  2971,  2975,  2979,  2982,  2991,  2994,
    3003,  3009,  3016,  3019,  3043,  3044,  3045,  3048,  3049,  3052,
    3058,  3059,  3060,  3061,  3062,  3063,  3068,  3072,  3076,  3080,
    3087,  3090,  3095,  3096,  3097,  3099,  3105,  3115,  3119,  3123,
    3127,  3131,  3135,  3139,  3143,  3151,  3161,  3166,  3170,  3174,
    3178,  3182,  3187,  3191,  3195,  3203,  3206,  3211,  3212,  3213,
    3218,  3219,  3220,  3228,  3231,  3236,  3237,  3241,  3242,  3247,
    3272,  3289,  3290,  3294,  3301,  3307,  3317,  3319,  3322,  3323,
    3324,  3325,  3327,  3330,  3334,  3339,  3343,  3349,  3350,  3353,
    3358,  3359,  3362,  3363,  3364,  3374,  3375,  3376,  3377,  3378,
    3379,  3380,  3381,  3385,  3391,  3393,  3412,  3420,  3427,  3428,
    3429,  3430,  3435,  3436,  3437,  3438,  3439,  3444,  3445,  3461,
    3462,  3463,  3464,  3465,  3466,  3467,  3468,  3469,  3470,  3472,
    3473,  3474,  3475,  3480,  3483,  3492,  3493,  3494,  3495,  3496,
    3497,  3501,  3502,  3516
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
  "CURRENT_FIELD_DISPLAY", "CURRENT_ROW_DISPLAY", "ALTER_TABLE",
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
       0,   256,  2284,  2285,  2286,  2287,  2288,  2289,  2290,  2291,
    2292,  2293,  2294,  2295,  2296,  2297,  2298,  2299,  2300,  2301,
    2302,  2303,  1000,  1001,  1002,  1003,  1004,  1005,  1007,  1008,
    1009,  1010,  1011,  1012,  1013,  1014,  1015,  1016,  1017,  1018,
    1019,  1020,  1022,  1023,  1028,  1029,  1030,  1032,  1033,  1035,
    1038,  1039,  1040,  1041,  1042,  1043,  1044,  1047,  1051,  1052,
    1053,  1054,  1057,  1073,  1074,  1085,  1086,  1095,  1098,  1100,
    1101,  1104,  1105,  1106,  1107,  1120,  1121,  1122,  1123,  1137,
    1139,  1140,  1141,  1145,  1150,  1151,  1152,  1155,  1156,  1157,
    1194,  1195,  1196,  1197,  1198,  1199,  1200,  1203,  1204,  1206,
    1207,  1208,  1209,  1212,  1213,  1215,  1221,  1222,  1231,  1243,
    1244,  1245,  1250,  1253,  1254,  1255,  1256,  1257,  1258,  1263,
    1264,  1266,  1267,  1268,  1269,  1279,  1285,  1286,  1287,  1288,
    1289,  1300,  1301,  1309,  1310,  1311,  1317,  1325,  1332,  1334,
    1338,  1339,  1341,  1342,  1343,  1348,  1374,  1375,  1376,  1377,
    1384,  1385,  1392,  1400,  1402,  1403,  1407,  1408,  1415,  1416,
    1419,  1421,  1424,  1430,  1437,  1440,  1446,  1451,  1457,  1458,
    1463,  1465,  1467,  1468,  1470,  1481,  1488,  1491,  1492,  1493,
    1495,  1497,  1500,  1504,  1506,  1530,  1531,  1533,  1540,  1542,
    1543,  1545,  1546,  1547,  1553,  1554,  1560,  1561,  1563,  1566,
    1569,  1570,  1572,  1574,  1582,  1583,  1585,  1588,  1601,  1604,
    1605,  1606,  1607,  1609,  1610,  1618,  1621,  1622,  1623,  1627,
    1629,  1633,  1634,  1636,  1637,  1639,  1643,  1646,  1648,  1652,
    1656,  1657,  1660,  1662,  1663,  1666,  1667,  1669,  1675,  1683,
    1684,  1687,  1690,  1693,  1695,  1696,  1698,  1699,  1700,  1709,
    1712,  1719,  1721,  1723,  1724,  1725,  1728,  1729,  1733,  1739,
    1740,  1743,  1752,  1757,  1761,  1762,  1763,  1765,  1768,  1769,
    1771,  1772,  1773,  1774,  1775,  1776,  1777,  1778,  1779,  1780,
    1781,  1785,  1790,  1791,  1792,  1793,  1794,  1801,  1804,  1805,
    1811,  1813,  1814,  1817,  1819,  1820,  1821,  1859,  1863,  1870,
    1871,  1874,  1879,  1886,  1887,  2235,  2265,  2278,  2279,  2280,
    2281,  2282,  2283
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint16 yyr1[] =
{
       0,   313,   314,   315,   315,   315,   316,   316,   316,   317,
     317,   317,   317,   317,   317,   318,   318,   319,   319,   320,
     320,   320,   320,   321,   322,   322,   323,   323,   324,   324,
     325,   326,   326,   326,   326,   327,   327,   328,   328,   329,
     329,   330,   330,   331,   331,   331,   331,   331,   332,   333,
     333,   334,   334,   335,   335,   335,   335,   336,   337,   337,
     337,   337,   337,   337,   337,   337,   337,   337,   337,   337,
     338,   338,   339,   339,   340,   340,   341,   341,   341,   342,
     342,   343,   343,   344,   344,   344,   345,   345,   346,   346,
     346,   346,   346,   346,   346,   347,   347,   348,   348,   349,
     349,   350,   350,   351,   351,   352,   353,   353,   354,   354,
     355,   356,   356,   357,   358,   358,   359,   359,   360,   360,
     361,   361,   362,   362,   363,   364,   366,   365,   368,   367,
     367,   369,   369,   370,   370,   371,   371,   372,   372,   373,
     373,   374,   375,   376,   377,   377,   378,   379,   379,   379,
     379,   379,   379,   379,   380,   380,   380,   381,   381,   381,
     381,   381,   381,   381,   382,   382,   382,   382,   383,   383,
     383,   384,   384,   384,   385,   385,   385,   386,   386,   387,
     387,   387,   387,   387,   387,   388,   388,   389,   389,   390,
     390,   391,   391,   392,   393,   393,   394,   394,   395,   395,
     396,   397,   398,   399,   400,   400,   401,   401,   402,   402,
     402,   403,   403,   404,   404,   404,   405,   405,   405,   405,
     406,   407,   407,   408,   408,   409,   409,   410,   411,   411,
     411,   411,   411,   411,   411,   412,   413,   414,   415,   415,
     416,   416,   417,   418,   419,   420,   420,   420,   420,   420,
     420,   421,   421,   422,   422,   422,   423,   423,   424,   424,
     425,   425,   425,   425,   426,   426,   427,   427,   428,   428,
     429,   429,   430,   430,   431,   431,   432,   432,   433,   433,
     434,   435,   436,   436,   437,   437,   437,   437,   437,   437,
     437,   437,   437,   437,   437,   437,   438,   438,   438,   438,
     438,   438,   439,   439,   439,   439,   440,   440,   440,   440,
     441,   441,   441,   441,   442,   443,   443,   443,   444,   444,
     445,   445,   445,   445,   445,   445,   445,   445,   445,   445,
     445,   445,   445,   445,   445,   445,   445,   445,   445,   445,
     445,   445,   445,   445,   445,   445,   445,   446,   446,   447,
     447,   447,   447,   447,   448,   449,   450,   451,   451,   452,
     452,   452,   453,   453,   454,   454,   455,   455,   455,   455,
     456,   456,   456,   456,   457,   458,   458,   458,   458,   459,
     459,   460,   460,   460,   460,   460,   460,   460,   461,   461,
     461,   461,   461,   461,   461,   461,   462,   462,   462,   463,
     463,   464,   465,   466,   467,   468,   468,   469,   469,   470,
     471,   471,   471,   472,   473,   474,   475,   475,   476,   477,
     477,   478,   478,   478,   479,   480,   480,   481,   481,   482,
     483,   484,   484,   484,   484,   486,   487,   485,   488,   489,
     489,   490,   490,   490,   490,   491,   492,   493,   494,   494,
     495,   495,   495,   495,   496,   497,   497,   498,   498,   498,
     499,   499,   499,   500,   500,   500,   500,   500,   500,   500,
     500,   500,   500,   500,   500,   500,   500,   500,   500,   500,
     500,   500,   500,   500,   500,   500,   500,   500,   500,   500,
     500,   500,   500,   500,   500,   500,   500,   500,   501,   501,
     502,   502,   503,   503,   504,   504,   504,   505,   505,   505,
     506,   506,   506,   506,   506,   506,   507,   507,   507,   507,
     508,   508,   509,   509,   509,   509,   510,   511,   511,   511,
     511,   511,   511,   511,   511,   512,   513,   513,   513,   513,
     513,   513,   513,   513,   513,   514,   514,   514,   514,   514,
     514,   514,   514,   515,   516,   517,   517,   518,   518,   519,
     520,   521,   521,   522,   522,   522,   523,   523,   523,   523,
     523,   523,   523,   523,   524,   525,   526,   527,   527,   527,
     528,   528,   529,   529,   529,   530,   530,   530,   530,   530,
     530,   530,   530,   531,   531,   531,   532,   533,   534,   534,
     534,   534,   535,   535,   535,   535,   535,   536,   536,   537,
     537,   537,   537,   537,   537,   537,   537,   537,   537,   537,
     537,   537,   537,   538,   538,   539,   539,   539,   539,   539,
     539,   540,   540,   541
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
#define YYPACT_NINF -931
static const yytype_int16 yypact[] =
{
    2018,  -931,  -931,  -931,   157,  -931,   466,   157,   157,   466,
     466,   157,   526,   157,   157,   466,   526,   526,   526,   526,
    -931,   589,  -931,   157,  -931,  -931,   466,  -931,   117,   466,
     466,  -931,   466,   466,  -931,  -931,  -931,   466,  -931,  -931,
    -931,   526,   466,   654,  -931,   157,   466,   688,   397,   -61,
     466,   397,  -931,  -931,  -931,  -931,  -931,  -931,  -931,  -931,
    -931,  -931,  -931,  -931,  -931,  -931,  -931,  -931,  -931,  -931,
    -931,  -931,  -931,  -931,  -931,  -931,  -931,   279,  -931,  -931,
    -931,   -22,  -931,  -931,  -931,   122,     4,  -931,  -931,    13,
    -931,  -931,  -931,   -28,   355,    11,   131,   258,  -931,  -931,
    -931,  -931,  -931,    95,   109,   134,   143,  -931,    32,  -931,
    -931,  -931,  -931,   246,  -931,  -931,   126,  -931,   265,  -931,
     294,   466,   466,  -931,   135,   253,   256,  -931,   267,   305,
    -931,  -931,  -931,  -931,   378,  -931,  -931,  -931,  -931,  -931,
     376,   376,  -931,  -931,  -931,  -931,   346,   324,   343,  -931,
     658,   -17,  -931,   377,   371,  -931,  2018,   721,  -931,  -931,
     675,   157,   758,   157,   157,   694,   483,    66,   710,  -931,
    -931,   264,    96,   290,   444,  -931,  -931,  -931,  -931,  -931,
    -931,  -931,  -931,   157,  -931,  -931,   775,   157,   466,   466,
     466,   466,    32,  -931,   282,   466,   282,    84,   438,   -33,
     519,  -931,  -931,  -931,   157,   157,   782,   157,   157,  -931,
    -931,    84,  -931,  -931,   121,   466,   696,  -931,  -931,  -931,
    -931,  -931,   340,   121,   466,  -931,   447,   448,   479,  -931,
     697,  -931,   484,  -931,   522,  -931,  -931,   573,   588,   593,
     393,   596,   608,  -931,  -931,  -931,   724,   157,   552,  -931,
    -931,  -931,   282,  -931,  -931,  -931,  -931,   501,   157,  -931,
    -931,   282,   538,  -931,   355,  -931,   545,  -931,   562,   626,
    -931,   627,   629,   630,  -931,   -64,  -931,  -931,   -60,   654,
     -55,  -931,  -931,   558,   413,   619,   848,   872,  -931,   157,
     140,  -931,   561,  -931,   567,  -931,   577,  -931,   -50,  -931,
    -931,   595,  -931,  -931,   609,  -931,  1685,  1195,  1195,  1195,
    1195,    94,    94,    -6,   595,   578,   157,   157,   721,  -931,
     157,   810,    84,    84,    84,   -25,   724,    84,   872,   157,
    -931,    -2,   157,    10,  -931,  -931,  -931,   663,   665,   670,
     532,   532,  -931,   671,  -931,   674,   679,   682,   683,   684,
    -931,  -931,  -931,  -931,   687,   695,   563,  -931,  -931,  -931,
    -931,  -931,    14,  -931,  -931,    28,   157,  -931,   157,   814,
     157,   157,   157,   157,   731,   282,    22,  -931,  -931,    84,
      75,   899,   157,  -931,   -61,   777,  -931,  -931,  -931,  -931,
     699,   616,  -931,  -931,   906,   703,   705,  -931,  -931,  -931,
     709,   532,  -931,   -61,   872,   709,   707,  -931,   711,  -931,
     579,   714,   709,  -931,   723,   725,   709,   709,   726,   729,
     732,   735,  1780,   971,   736,  1780,   920,  -931,  -931,  -931,
     742,   640,   685,  -931,  -931,  -931,  -931,  -931,  -931,  -931,
     532,  -931,   532,  -931,  -931,   708,  -931,  -931,   -53,  -931,
    -931,  -931,  -931,   368,   835,   162,  -931,   669,  -931,  -931,
    -931,   157,   157,   815,  -931,    84,   121,   121,  1685,   686,
    -931,  -931,    39,  -931,   174,  -931,  -931,   211,   690,   690,
     157,  -931,  -931,   213,    45,   693,   749,  -931,   848,   872,
    -931,   121,   689,  -931,  -931,  -931,   700,  -931,   779,   702,
    -931,   219,  -931,   220,  -931,   393,  -931,   231,   640,   791,
    -931,  -931,  -931,  -931,   282,   973,   973,   990,  -931,  -931,
    -931,  -931,  -931,  -931,  -931,   706,   -98,   992,  1001,  1002,
    1003,   992,   992,  1006,  1008,  -931,  -931,  -931,    71,  -931,
     370,  -931,   157,  -931,   282,  -931,  -931,   720,  -931,   239,
    -931,  -100,   240,   249,   281,  -931,    22,  -931,  1010,  -931,
    -931,  1011,  1016,  -931,    22,  -931,  -931,  -931,   796,  -112,
     733,   -17,  -931,  -931,  1290,   157,  1005,  1685,  1685,  -931,
    -931,   727,   -17,   -89,  1121,  -931,  1685,  1685,  1685,   872,
     274,   148,  -931,  1685,  -931,  1685,  1685,  -931,  -931,   -16,
    1685,   -16,   -16,   368,  -931,   -16,   368,  -931,   -16,   872,
     872,   728,   -91,  1780,  -931,  1780,  1780,  -931,  1780,  -931,
     229,  1440,  -931,  -931,  1780,  -931,   615,  -931,  1780,   113,
    1685,    68,    23,  1685,  -931,  -931,  -931,  -931,  -931,  -931,
    1685,  1685,  1685,  1685,  -931,   501,  -931,   157,   157,   816,
    -931,  -931,   737,  -931,  -931,  -931,   595,   832,  1685,  -931,
     157,  -931,  -931,  1195,  -931,  -931,   811,    94,    78,  -931,
      94,  1195,  -931,   640,   -12,   157,   157,   861,    84,  -931,
      84,  -931,   724,  -931,  -931,  -931,  -931,   836,   837,   289,
     635,  1036,   635,  -931,   767,   843,   300,   851,   852,   767,
     855,   856,  -931,  -931,  -931,  -931,   466,  -931,  -931,  -931,
     844,  -931,  -931,   370,  -931,   724,  -931,  -931,   157,    49,
     157,  -931,  -931,    49,    49,    49,   731,  -931,  -931,  -931,
    -931,  -931,  -931,  -931,  1054,   157,  1685,  -931,  -931,   301,
     770,  -931,   320,   335,   635,  1685,  -931,  -931,   341,   860,
     530,   338,  -931,  -114,   384,  -931,  -931,   344,   351,   354,
    -931,  -931,  -931,  1685,   362,  1685,  1685,  1685,  1685,   685,
    -931,   635,  1060,   635,   849,   368,   850,   853,   849,   125,
    -931,  -931,  -931,   850,   125,  -931,   853,  -931,  -931,  1685,
    -931,  -931,    68,  -931,  -931,   303,  1061,  -931,  -931,    56,
    -931,  -931,  -931,  -931,  -931,  -931,  -931,  -931,  1535,   157,
    -931,   812,  -931,  -931,   857,  -931,  -931,   116,  -931,  -931,
    -931,   589,  -931,  -931,  -931,  -931,  -931,  -931,  -931,  -931,
    -931,  -931,  1069,   865,  -931,  -931,  -931,  -931,  -931,  -931,
    -931,   875,  -931,  1072,   881,  -931,  -931,  1078,  -931,  -931,
     883,  -931,  -931,  -931,   870,   872,  -931,  -931,  -931,  -931,
    -931,  1016,  1088,  -931,    49,  -931,  -931,  -931,  -931,  -931,
    -931,   884,   796,   119,  -931,  1685,   157,  -931,  -931,  -931,
     119,   532,   798,  -931,  -931,  -931,  -931,  1685,  -931,  -931,
    -931,  -931,   893,  -931,   896,   897,   901,   902,  -931,   903,
    -931,    71,  -931,    71,  -931,    71,  -931,  -931,    47,  -931,
     369,  -931,  -931,  -931,   375,  -931,   825,   404,  -931,  -931,
    -931,    68,  -931,  -931,  -931,    68,  -931,    68,   157,  -931,
     390,  -931,  -931,  -931,   466,   365,   858,  1195,   157,  -931,
    -931,   905,  1106,   817,  -931,  -931,  -931,   912,  -931,    84,
     913,  -931,  -931,  -931,  -931,  -931,  -931,  -931,   889,   916,
     820,   635,  -931,  -931,  -931,  -931,  -931,  -931,   823,  -931,
    -931,  -931,  -931,  -931,  -931,  -931,   125,  -931,  1685,  -931,
     453,   471,   489,   895,  -931,  1535,    65,  -931,    59,    98,
     872,   872,  -931,    74,  -931,  -931,   904,   -11,   -58,   406,
     796,  -931,   922,   635,  -931,   407,  -931,    68,  -931,   635,
    -931,   635,  -931,  -931,  -931,  -931,    68,    68,  -931,   146,
     146,    90,   157,  -931,  -931,  -931,    55,  -931,  -931,  -931,
     854,  -931,   830,   442,   640,   640,  -931,  -931,  -931,  -931,
    -931,   898,   157,   838,   942,  -931,  -931,  -931,  -931,  -931,
    -931,   549,  -931,  -931,   698,   681,   466,    65,   833,   839,
     190,  -931,  -931,  -931,    98,    87,  -931,   -61,  -931,   966,
    -931,   102,   157,  -931,    68,  -931,  -931,    68,   193,   872,
     872,   466,  -931,  -931,  -931,   796,   -17,  -931,  -931,  -931,
    -931,   859,  -931,    29,   966,   743,   764,  -931,   640,   640,
     196,  -931,  1685,   102,  -931,  -931,  -931,  -931,  -931,  -931,
    -931,   119,  -931,   858,  -931
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -931,  -931,  -931,  -931,  -931,  -931,  -280,   651,   464,  -931,
    -254,  -374,  -931,  -931,  -931,  -931,   580,  -931,   575,   284,
     -88,  -931,   283,   557,  -931,   417,    58,   412,   429,   954,
    -113,  -931,  -931,   907,  -931,  -210,  -931,  -931,  -931,  -149,
    -931,  -931,  -174,  -931,  -931,  -931,  -931,  -302,  -931,   910,
     821,  -931,  -931,  -931,  -931,  -931,  -931,  -931,   513,  -931,
     177,  -931,  -931,  -931,  -931,  -931,  -931,  -931,  -931,  -931,
    1112,  -931,  1114,  -931,   950,  1026,  -931,  -136,   704,  -931,
    -931,  -931,  -931,  -931,  -931,   491,  -931,  -931,   224,  -931,
     -40,  -121,  -931,  -931,  -931,  -931,  -931,   456,  -931,  -931,
    -931,  -931,  -931,     7,   181,  -931,  -931,  -810,   158,  -883,
    -781,  -931,   187,  -267,   572,   576,   760,  -931,   409,   405,
     410,   339,  -509,  -931,  -931,  -931,  -931,   395,  -931,   547,
    -931,  -931,  -931,   495,  -931,   680,    33,  -931,   -20,  -461,
    -167,  -930,   164,   918,   173,  -520,  -931,  -306,  -536,  -931,
    -931,   994,   739,  -931,  -931,  -931,  -931,  -931,  -931,  -931,
    -931,  -931,  -931,   100,  -931,  -931,  -931,  -931,   141,   349,
    -931,  -931,  -931,  -931,  -931,  -931,    93,  -931,   136,   919,
    -176,  -363,  -535,  -688,  -931,   553,  -242,  -931,   623,  -507,
     510,   468,  -931,  -931,  -931,   430,   243,   -27,  -931,    43,
    -931,   753,    -4,   734,   312,  -931,  -931,  -931,  -931,  -931,
    1065,  -931,  1211,  -931,  -931,  -931,   908,  -931,  -554,  -931,
    -931,  -501,  -931,  -931,  -931,  -123,  -931,  -931,  1075
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
     262,   125,   392,    84,   472,   476,   476,   476,   476,   113,
      84,   791,   116,   117,   389,   118,   119,   702,   334,    84,
     120,   276,    84,   276,   756,   124,   392,   314,    84,   131,
     125,    84,   956,   152,    84,   581,    86,   733,    84,   959,
      84,  1025,    84,   286,   125,  1089,    84,   732,   125,   363,
     746,   558,   859,   860,  1019,   193,   691,    89,    89,   326,
     114,  1020,   820,   772,   986,    84,  1042,   107,   389,    84,
     488,   391,   559,   560,   611,   374,   612,   583,  1061,   376,
     392,  1090,   393,   590,   378,   394,   157,   158,   262,   464,
      84,   887,    86,   227,   721,   500,   842,   231,   233,   234,
     235,    84,   584,   250,   199,   200,   734,   257,   260,   257,
     218,   760,   631,  1090,   504,   722,  1038,  1082,   150,   265,
     561,   609,   267,   268,    89,    89,    89,    89,    37,  1043,
     257,    89,   257,   284,    84,   160,    86,   511,   692,   274,
     291,   293,   295,   296,   130,   773,   609,   284,   879,   513,
     111,    89,   566,   541,   375,   219,   761,   287,   375,   111,
      89,  1039,   673,   379,   579,   912,   657,   543,   465,   585,
     912,   270,   270,   270,   270,   898,   594,   900,   277,   632,
     597,   598,  1019,   250,   489,  1019,  1078,   756,   257,  1020,
     184,   185,  1020,   505,   260,   220,   762,   257,   304,   909,
      48,  1040,   557,   989,   909,   165,   466,   315,    84,   797,
     381,  1100,   401,    51,   787,   284,   332,   201,   821,   155,
     247,   927,   792,  1104,   503,   457,    84,   507,   514,   813,
     162,   917,   542,   990,    84,   156,   161,   819,   654,   603,
     202,   163,   606,   183,  1105,   164,   544,   484,   484,   788,
     258,   789,   492,   493,   227,   562,   495,   497,   284,   284,
     284,   567,   753,   284,   816,   510,   401,   798,   250,   660,
    1113,   656,   738,  1084,   717,   738,   738,   668,  1060,   426,
     685,   381,   861,  1021,   748,   738,   752,   300,   928,  1022,
     862,   738,   793,   738,   738,   674,   939,   794,   738,  1027,
    1056,   646,   545,   426,   546,   548,   551,   551,   551,   551,
     384,   257,   279,   662,   458,   284,   568,   934,   570,   782,
     828,   970,   480,   970,   682,   970,  1026,   815,   790,   188,
    1026,   800,  1097,   716,   971,  1110,   972,   658,   801,   802,
     803,   804,  1027,   189,  1081,   588,  1027,   195,   938,   908,
     664,   955,   666,   857,  1111,   589,   472,   426,   679,   681,
     980,   476,   912,   237,   981,  1010,   982,   238,   190,   476,
     683,   262,   307,   308,   309,   310,   311,   191,   719,   723,
     647,   237,   403,   779,   780,   238,   755,   633,   724,   237,
     785,   239,   663,   238,   166,   167,   909,   293,   651,   653,
     194,   284,   111,   111,   168,   169,   170,  1049,   661,   239,
      84,  1021,    86,  1052,  1021,  1053,   484,   239,   252,   196,
     725,   634,   635,   636,   637,   638,   639,   111,   831,   663,
     775,   667,   775,   775,   472,   775,   241,   680,   680,   846,
     874,   775,   242,   472,   261,   775,  1051,   704,   197,   680,
     257,   826,   918,   827,   241,  1054,  1055,   720,   720,   877,
     242,   892,   241,   894,   895,   896,   897,   720,   242,   518,
      84,   588,    95,   705,   878,   186,   135,   886,   260,  1047,
     257,   589,   706,   889,   206,   204,   187,   916,   205,   919,
     890,  1102,   237,   891,   989,   207,   238,   707,   920,   720,
     209,   893,   519,   708,   698,   699,   932,   832,   975,   609,
     520,   740,  1066,  1095,   977,   960,  1096,   171,   847,   875,
     239,   921,   389,   390,   990,   391,   521,   922,   923,   984,
     211,   136,   924,    84,   392,   107,   393,   137,   875,   394,
     522,   208,   709,   979,   214,  1046,  1050,   335,   710,   523,
     312,   172,   138,   875,   640,   991,   875,   139,   215,   881,
     524,   216,   875,   641,  1101,   241,   173,   140,   799,   875,
     141,   242,   875,   957,   142,   867,   868,   869,   381,   143,
     875,   588,   237,   457,   807,   962,   238,   976,   395,   396,
     919,   589,   642,   976,   397,   398,   812,   643,    84,   920,
     125,   217,  1014,   484,   817,   224,   484,   381,   985,   144,
     239,   823,   824,   223,   284,   336,   284,   145,   337,   338,
     339,   230,   888,   999,   663,   678,   399,   340,   922,   923,
     206,   341,   132,   924,   133,   476,   342,   240,  1015,   919,
     236,   207,    89,   343,  1086,   382,   344,   345,   920,   346,
     535,   536,   537,   251,   858,   241,   551,   919,   518,   206,
     518,   242,   264,  1034,  1035,    84,   920,   226,   285,  -504,
     207,   872,   347,   289,  -529,   919,  1013,   922,   923,   316,
     317,   348,   924,   932,   920,   349,   271,   272,   273,   854,
     400,   519,   350,   519,   351,   922,   923,   318,  1073,   520,
     924,   520,    84,   352,   232,   353,   538,  1016,   319,   103,
     104,   105,   106,   922,   923,   521,   320,   521,   924,    84,
     401,   266,   500,   552,   553,   554,    84,   322,   294,   522,
     402,   522,   403,   404,   123,   919,   405,   406,   523,   321,
     523,   940,   323,   354,   920,   933,   355,   324,   881,   524,
     327,   524,  1098,  1099,    84,   407,   496,   111,    84,    84,
     547,   652,   328,   833,   408,   409,   329,  1074,   403,   784,
     332,   410,   411,   922,   923,   366,   588,   368,   924,   369,
     370,   371,   412,   372,   373,   413,   589,   414,   415,   384,
     380,   416,   387,   417,   463,   418,   834,   461,   419,   462,
     472,   420,   421,   422,   835,   423,   424,   467,   425,  -282,
     613,   426,   958,   466,   491,   389,   390,   515,   391,   516,
     836,   427,   428,   429,   517,   527,   430,   392,   528,   393,
    1076,   614,   394,   529,   837,   555,   530,   531,   532,   615,
     616,   533,   569,   838,  -282,   617,  -282,  1075,   575,   534,
     572,   138,   576,   574,   839,   618,   139,   577,   619,   578,
     620,   586,   403,   607,   983,   587,   140,   919,   593,   141,
      89,   621,   622,   142,  1000,   609,   920,   595,   143,   596,
     599,   395,   396,   600,   919,   284,   601,   397,   398,   602,
     605,   623,  1108,   920,   776,   777,   608,   778,   610,  1077,
     645,   648,  1032,   783,   658,   922,   923,   786,   663,   624,
     924,   670,   671,  1109,   389,   390,   686,   391,   677,   399,
     678,   675,   922,   923,  1024,  1033,   392,   924,   393,   919,
     684,   394,   676,   689,   625,   693,   765,   766,   920,  1032,
     767,   626,   690,   768,   695,   696,   697,   627,   628,   700,
     919,   701,   718,   727,   728,    89,    89,    89,  1024,   920,
     729,   381,  1033,   744,   771,   735,   741,   922,   923,   809,
     808,   747,   924,   706,   814,   829,   830,  1032,  1070,   841,
     395,   396,   845,   400,  1032,   843,   397,   398,   922,   923,
     848,   849,    89,   924,   851,   852,    89,   871,   855,   884,
    1033,  1085,   876,   899,   926,   901,   903,  1033,  1070,   905,
     934,   937,   941,   401,   943,   944,  1032,    89,   399,   942,
     946,   947,   948,   402,   949,   403,   404,   742,   743,   405,
     406,   952,   963,   954,   961,   964,   965,   751,   978,  1033,
     966,   967,   968,   757,  1001,   758,   759,   997,   407,  1002,
     764,  1004,  1006,  1003,  1007,  1008,  1009,   408,   409,  1011,
    1017,  1048,  1065,   990,   410,   411,  1072,  1079,  1067,  1071,
    1087,   665,  1064,  1080,   818,   412,   726,  1103,   413,   731,
     414,   415,   400,   870,   416,   951,   417,   953,   418,   866,
     278,   419,  1107,   512,   420,   421,   422,   331,   423,   424,
     806,   425,  1018,   153,   426,   154,   305,   213,   825,   856,
     655,   367,   401,  1005,   427,   428,   429,  1037,  1059,   430,
    1036,   769,   402,   604,   403,   404,   770,   907,   405,   406,
    1063,   915,   805,   913,   850,  1062,   688,   377,   389,   390,
     650,   391,   297,  1112,   950,  1083,  1114,   407,  1094,   460,
     392,   810,   393,   754,   914,   394,   408,   409,   885,  1012,
     974,   225,   672,   410,   411,   101,   494,   222,     0,     0,
       0,     0,     0,     0,   412,     0,     0,   413,     0,   414,
     415,     0,     0,   416,     0,   417,     0,   418,     0,     0,
     419,     0,     0,   420,   421,   422,     0,     0,   424,     0,
     425,     0,     0,   426,   395,   396,     0,     0,     0,     0,
     397,   398,     0,   427,   428,   429,     0,     0,   430,     0,
       0,     0,     0,   613,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   389,   390,     0,   391,     0,     0,     0,
       0,     0,   399,     0,   614,   392,     0,   393,     0,     0,
     394,     0,   615,   616,     0,     0,     0,     0,   617,     0,
     747,     0,     0,     0,     0,     0,     0,     0,   618,     0,
       0,   619,     0,   620,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   621,   622,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   395,
     396,     0,     0,     0,   623,   397,   398,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   624,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  -305,     0,   401,   399,     0,     0,
       0,     0,     0,     0,     0,     0,   402,   625,   403,   468,
       0,     0,     0,   406,   626,     0,  -305,     0,     0,     0,
     627,   628,     0,     0,     0,     0,     0,     0,     0,     0,
     473,   407,     0,     0,     0,     0,     0,     0,     0,     0,
     408,   409,     0,   389,   390,     0,   391,   410,   411,     0,
       0,     0,     0,     0,     0,   392,     0,   393,   412,     0,
     394,   413,     0,   414,   415,     0,     0,   416,     0,   417,
       0,   418,     0,     0,   419,     0,     0,   420,   421,   422,
       0,     0,   424,     0,   425,     0,     0,   426,     0,   737,
       0,   401,     0,     0,     0,     0,     0,   427,   428,   429,
       0,   402,   430,   403,   468,     0,     0,     0,   406,   395,
     396,     0,     0,     0,     0,   397,   398,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   407,     0,     0,     0,
       0,     0,     0,     0,     0,   408,   409,     0,   389,   390,
       0,   391,   410,   411,     0,     0,     0,   399,     0,     0,
     392,     0,   393,   412,     0,   394,   413,     0,   414,   415,
       0,     0,   416,     0,   417,     0,   418,     0,     0,   419,
       0,     0,   420,   421,   422,     0,     0,   424,     0,   425,
       0,     0,   426,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   427,   428,   429,     0,     0,   430,     0,     0,
       0,     0,     0,     0,   395,   396,     0,     0,     0,     0,
     397,   398,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   401,   399,     0,     0,     0,     0,     0,     0,     0,
       0,   402,     0,   403,   468,     0,     0,     0,   406,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   781,   407,     0,     0,     0,
       0,     0,     0,     0,     0,   408,   409,     0,   389,   390,
       0,   391,   410,   411,     0,     0,     0,     0,     0,     0,
     392,     0,   393,   412,     0,   394,   413,     0,   414,   415,
       0,     0,   416,     0,   417,     0,   418,     0,     0,   419,
       0,     0,   420,   421,   422,     0,     0,   424,     0,   425,
       0,     0,   426,     0,     0,     0,   401,     0,     0,     0,
       0,     0,   427,   428,   429,     0,   402,   430,   403,   468,
       0,     0,     0,   406,   395,   396,     0,     0,     0,     0,
     397,   398,     0,     0,     0,     0,     0,     0,     0,     0,
     929,   407,     0,     0,     0,     0,     0,     0,     0,     0,
     408,   409,     0,   389,   390,     0,   391,   410,   411,     0,
       0,     0,   399,     0,     0,   392,     0,   393,   412,     0,
     394,   413,     0,   414,   415,     0,     0,   416,     0,   417,
       0,   418,     0,     0,   419,     0,     0,   420,   421,   422,
       0,     0,   424,     0,   425,     0,     0,   426,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   427,   428,   429,
       0,     0,   430,     0,     0,     0,     0,     0,     0,   395,
     396,     0,     0,     0,     0,   397,   398,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   401,   399,     0,     0,
       0,     0,     0,     0,     0,     0,   402,     0,   403,   468,
       0,     0,     0,   406,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   407,     0,     0,     0,     0,     0,     0,     0,     0,
     408,   409,     0,     0,     0,     0,     0,   410,   411,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   412,     0,
       0,   413,     0,   414,   415,     0,     0,   416,     0,   417,
       0,   418,     0,     0,   419,     0,     0,   420,   421,   422,
       0,     0,   424,     0,   425,     0,     0,   426,     0,     0,
       0,   401,     0,     0,     0,     0,     0,   427,   428,   429,
       0,   402,   430,   403,   468,     0,     0,     0,   406,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   407,     0,  -566,     1,
       0,     0,     0,     0,     0,   408,   409,     0,     0,     0,
       0,     0,   410,   411,  -566,     0,     0,     0,     0,     0,
       0,     0,     0,   412,     0,     0,   413,     0,   414,   415,
       0,     0,   416,     0,   417,     0,   418,     0,     0,   419,
       0,     0,   420,   421,     0,     0,     0,   424,     0,     0,
       0,     0,   426,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   427,   428,   429,     2,     3,   430,     0,     0,
       4,     0,     5,     0,     0,     6,     7,     0,     8,     9,
      10,     0,     0,     0,     0,    11,    12,     0,     0,     0,
       0,     0,     0,     0,     0,    13,    14,     0,     0,    15,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    16,
      17,    18,    19,     0,    20,    21,    22,    23,    24,    25,
      26,     0,     0,    27,     0,     0,    28,     0,    29,    30,
       0,     0,     0,    31,    32,     0,     0,     0,     0,     0,
      33,    34,    35,    36,    37,    38,     0,     0,    39,     0,
       0,     0,     0,     0,    40,    41,     0,     0,    42,     0,
       0,    43,     0,    44,    45,     0,     0,     0,     0,    46,
       0,     0,     0,    47,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    48,     0,    49,     0,
       0,    50,     0,     0,     0,     0,     0,     0,     0,    51
};

static const yytype_int16 yycheck[] =
{
       4,    21,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    43,    21,   538,    23,
     287,   384,    26,   484,   326,    29,    30,     4,    32,    33,
     197,   311,   586,    37,   340,   341,   571,    41,    42,    43,
     403,    45,    46,     4,   211,   166,    50,   582,   736,     6,
       3,   261,     9,    10,   308,   309,   310,   745,    15,     4,
     173,     6,    15,     4,   306,   307,   308,   309,   310,    26,
       4,     3,    29,    30,     3,    32,    33,     6,   252,     4,
      37,   194,     4,   196,   591,    42,    15,   223,     4,    46,
       6,     4,   873,    50,     4,   401,     6,   209,     4,   880,
       4,     3,     4,   136,     6,     3,     4,   568,     6,   258,
     199,    89,    63,    64,    49,   108,   214,   121,   122,   240,
       3,    56,   134,   214,   934,     4,   184,     6,     3,     4,
     136,     6,   110,   111,   440,   199,   442,   404,  1021,   199,
      15,  1071,    17,   410,   199,    20,   168,   169,   261,   199,
       4,   265,     6,   157,   254,   322,   692,   161,   162,   163,
     164,     4,   404,   167,   121,   122,   278,   171,   172,   173,
     187,   187,   225,  1103,   199,   275,   187,  1060,   239,   183,
     158,   295,   186,   187,   188,   189,   190,   191,   156,   247,
     194,   195,   196,   197,     4,    73,     6,   199,   296,   192,
     204,   205,   206,   207,   208,   296,   295,   211,   744,   199,
     214,   215,   379,   199,   278,   232,   232,   250,   278,   223,
     224,   232,   489,   278,   400,   779,   468,   199,   278,   405,
     784,   188,   189,   190,   191,   771,   412,   773,   195,   292,
     416,   417,    49,   247,   250,    49,  1056,   754,   252,    56,
     119,   120,    56,   278,   258,   272,   272,   261,   215,   779,
     228,   272,   375,   189,   784,   293,   278,   224,     4,   246,
     225,  1081,   201,   241,   161,   279,   278,   142,   290,     0,
     214,   225,   214,   254,   324,   289,     4,   327,   278,   663,
     277,   792,   278,   219,     4,    16,   292,   671,   465,   422,
     165,   288,   425,   292,   275,   292,   278,   311,   312,   196,
     214,   198,   316,   317,   318,   293,   320,   321,   322,   323,
     324,   246,   589,   327,   246,   329,   201,   304,   332,   290,
    1111,   467,   574,   246,   544,   577,   578,   292,   248,   292,
     514,   225,   293,   278,   586,   587,   588,   226,   292,   290,
     301,   593,   284,   595,   596,   491,   817,   289,   600,   304,
     214,   199,   366,   292,   368,   369,   370,   371,   372,   373,
     230,   375,   288,   199,   234,   379,   380,   258,   382,   621,
     682,   901,   288,   903,   505,   905,   288,   667,   630,   294,
     288,   633,   199,   542,   903,   199,   905,   278,   640,   641,
     642,   643,   304,   294,   214,   257,   304,   281,   292,   284,
     199,   872,   199,   715,  1102,   267,   658,   292,   199,   199,
     921,   663,   976,   159,   925,   961,   927,   163,   294,   671,
     199,   544,    92,    93,    94,    95,    96,   294,   199,   199,
     278,   159,   213,   214,   620,   163,   298,    79,   199,   159,
     626,   187,   278,   163,    99,   100,   976,   461,   462,   463,
     214,   465,   466,   467,   109,   110,   111,  1003,   472,   187,
       4,   278,     6,  1009,   278,  1011,   480,   187,   214,   214,
     199,   113,   114,   115,   116,   117,   118,   491,   199,   278,
     613,   278,   615,   616,   736,   618,   232,   278,   278,   199,
     199,   624,   238,   745,   214,   628,  1007,   137,   214,   278,
     514,   678,   209,   680,   232,  1016,  1017,   278,   278,   199,
     238,   763,   232,   765,   766,   767,   768,   278,   238,   188,
       4,   257,     6,   163,   199,   277,   139,   199,   542,  1000,
     544,   267,   172,   199,   277,   292,   288,   789,   292,   246,
     199,  1086,   159,   199,   189,   288,   163,   187,   255,   278,
     182,   199,   221,   193,   531,   532,   808,   278,   199,   295,
     229,   575,  1033,  1074,   199,   881,  1077,   222,   278,   278,
     187,   278,     3,     4,   219,     6,   245,   284,   285,   199,
     214,   194,   289,     4,    15,     6,    17,   200,   278,    20,
     259,   296,   232,   199,   258,   199,   199,   106,   238,   268,
     270,   256,   215,   278,   246,   250,   278,   220,   294,   278,
     279,   278,   278,   255,  1085,   232,   271,   230,   632,   278,
     233,   238,   278,   875,   237,   723,   724,   725,   225,   242,
     278,   257,   159,   647,   648,   887,   163,   278,    69,    70,
     246,   267,   284,   278,    75,    76,   660,   289,     4,   255,
       6,     3,   209,   667,   668,   294,   670,   225,   278,   272,
     187,   675,   676,   296,   678,   174,   680,   280,   177,   178,
     179,     6,   298,   937,   278,   278,   107,   186,   284,   285,
     277,   190,     4,   289,     6,   937,   195,   214,   209,   246,
       6,   288,   706,   202,  1067,   292,   205,   206,   255,   208,
     147,   148,   149,     3,   718,   232,   720,   246,   188,   277,
     188,   238,   278,   990,   991,     4,   255,     6,   290,   199,
     288,   735,   231,   214,   292,   246,   978,   284,   285,   292,
     292,   240,   289,   985,   255,   244,   189,   190,   191,   706,
     171,   221,   251,   221,   253,   284,   285,   278,   209,   229,
     289,   229,     4,   262,     6,   264,   203,   278,    71,    16,
      17,    18,    19,   284,   285,   245,   292,   245,   289,     4,
     201,     6,   949,   371,   372,   373,     4,   214,     6,   259,
     211,   259,   213,   214,    41,   246,   217,   218,   268,   277,
     268,   821,   214,   302,   255,   809,   305,   214,   278,   279,
     214,   279,  1079,  1080,     4,   236,     6,   821,     4,     4,
       6,     6,   214,   188,   245,   246,   102,   278,   213,   214,
     278,   252,   253,   284,   285,   297,   257,   292,   289,   277,
     214,   214,   263,   214,   214,   266,   267,   268,   269,   230,
     292,   272,     4,   274,   277,   276,   221,   296,   279,   292,
    1102,   282,   283,   284,   229,   286,   287,   258,   289,   161,
     162,   292,   876,   278,   296,     3,     4,   214,     6,   214,
     245,   302,   303,   304,   214,   214,   307,    15,   214,    17,
     209,   183,    20,   214,   259,   164,   214,   214,   214,   191,
     192,   214,     3,   268,   196,   197,   198,   209,   292,   214,
     133,   215,     6,   214,   279,   207,   220,   214,   210,   214,
     212,   214,   213,     3,   928,   214,   230,   246,   214,   233,
     934,   223,   224,   237,   938,   295,   255,   214,   242,   214,
     214,    69,    70,   214,   246,   949,   214,    75,    76,   214,
     214,   243,   209,   255,   615,   616,   214,   618,   273,   278,
     125,   292,   989,   624,   278,   284,   285,   628,   278,   261,
     289,   278,   223,   209,     3,     4,     3,     6,   199,   107,
     278,   292,   284,   285,   988,   989,    15,   289,    17,   246,
     199,    20,   292,     3,   286,     3,   601,   602,   255,  1026,
     605,   293,   296,   608,     3,     3,     3,   299,   300,     3,
     246,     3,   292,     3,     3,  1019,  1020,  1021,  1022,   255,
       4,   225,  1026,   296,   296,   292,    21,   284,   285,   292,
     214,   199,   289,   172,   223,   199,   199,  1064,  1042,     3,
      69,    70,   199,   171,  1071,   278,    75,    76,   284,   285,
     199,   199,  1056,   289,   199,   199,  1060,     3,   214,   199,
    1064,  1065,   292,     3,     3,   216,   216,  1071,  1072,   216,
     258,   214,     3,   201,   199,     3,  1103,  1081,   107,   214,
     199,     3,   199,   211,   214,   213,   214,   577,   578,   217,
     218,     3,   199,   209,   296,   199,   199,   587,   273,  1103,
     199,   199,   199,   593,   199,   595,   596,   249,   236,     3,
     600,   199,   199,   296,   225,   199,   296,   245,   246,   296,
     225,   199,   292,   219,   252,   253,   184,   294,   230,   291,
     164,   480,   278,   294,   670,   263,   556,   278,   266,   564,
     268,   269,   171,   726,   272,   861,   274,   864,   276,   720,
     196,   279,  1094,   332,   282,   283,   284,   247,   286,   287,
     647,   289,   985,    51,   292,    51,   216,   141,   677,   713,
     466,   264,   201,   949,   302,   303,   304,   996,  1020,   307,
     993,   609,   211,   423,   213,   214,   610,   778,   217,   218,
    1026,   786,   645,   783,   699,  1022,   516,   279,     3,     4,
     461,     6,   208,  1103,   855,  1064,  1113,   236,  1072,   290,
      15,   658,    17,   590,   784,    20,   245,   246,   750,   976,
     908,   156,   488,   252,   253,    14,   318,   152,    -1,    -1,
      -1,    -1,    -1,    -1,   263,    -1,    -1,   266,    -1,   268,
     269,    -1,    -1,   272,    -1,   274,    -1,   276,    -1,    -1,
     279,    -1,    -1,   282,   283,   284,    -1,    -1,   287,    -1,
     289,    -1,    -1,   292,    69,    70,    -1,    -1,    -1,    -1,
      75,    76,    -1,   302,   303,   304,    -1,    -1,   307,    -1,
      -1,    -1,    -1,   162,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,     3,     4,    -1,     6,    -1,    -1,    -1,
      -1,    -1,   107,    -1,   183,    15,    -1,    17,    -1,    -1,
      20,    -1,   191,   192,    -1,    -1,    -1,    -1,   197,    -1,
     199,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   207,    -1,
      -1,   210,    -1,   212,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   223,   224,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    69,
      70,    -1,    -1,    -1,   243,    75,    76,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   261,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   273,    -1,   201,   107,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   211,   286,   213,   214,
      -1,    -1,    -1,   218,   293,    -1,   295,    -1,    -1,    -1,
     299,   300,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     235,   236,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     245,   246,    -1,     3,     4,    -1,     6,   252,   253,    -1,
      -1,    -1,    -1,    -1,    -1,    15,    -1,    17,   263,    -1,
      20,   266,    -1,   268,   269,    -1,    -1,   272,    -1,   274,
      -1,   276,    -1,    -1,   279,    -1,    -1,   282,   283,   284,
      -1,    -1,   287,    -1,   289,    -1,    -1,   292,    -1,   199,
      -1,   201,    -1,    -1,    -1,    -1,    -1,   302,   303,   304,
      -1,   211,   307,   213,   214,    -1,    -1,    -1,   218,    69,
      70,    -1,    -1,    -1,    -1,    75,    76,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   236,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   245,   246,    -1,     3,     4,
      -1,     6,   252,   253,    -1,    -1,    -1,   107,    -1,    -1,
      15,    -1,    17,   263,    -1,    20,   266,    -1,   268,   269,
      -1,    -1,   272,    -1,   274,    -1,   276,    -1,    -1,   279,
      -1,    -1,   282,   283,   284,    -1,    -1,   287,    -1,   289,
      -1,    -1,   292,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   302,   303,   304,    -1,    -1,   307,    -1,    -1,
      -1,    -1,    -1,    -1,    69,    70,    -1,    -1,    -1,    -1,
      75,    76,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   201,   107,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   211,    -1,   213,   214,    -1,    -1,    -1,   218,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   235,   236,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   245,   246,    -1,     3,     4,
      -1,     6,   252,   253,    -1,    -1,    -1,    -1,    -1,    -1,
      15,    -1,    17,   263,    -1,    20,   266,    -1,   268,   269,
      -1,    -1,   272,    -1,   274,    -1,   276,    -1,    -1,   279,
      -1,    -1,   282,   283,   284,    -1,    -1,   287,    -1,   289,
      -1,    -1,   292,    -1,    -1,    -1,   201,    -1,    -1,    -1,
      -1,    -1,   302,   303,   304,    -1,   211,   307,   213,   214,
      -1,    -1,    -1,   218,    69,    70,    -1,    -1,    -1,    -1,
      75,    76,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     235,   236,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     245,   246,    -1,     3,     4,    -1,     6,   252,   253,    -1,
      -1,    -1,   107,    -1,    -1,    15,    -1,    17,   263,    -1,
      20,   266,    -1,   268,   269,    -1,    -1,   272,    -1,   274,
      -1,   276,    -1,    -1,   279,    -1,    -1,   282,   283,   284,
      -1,    -1,   287,    -1,   289,    -1,    -1,   292,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   302,   303,   304,
      -1,    -1,   307,    -1,    -1,    -1,    -1,    -1,    -1,    69,
      70,    -1,    -1,    -1,    -1,    75,    76,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   201,   107,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   211,    -1,   213,   214,
      -1,    -1,    -1,   218,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   236,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     245,   246,    -1,    -1,    -1,    -1,    -1,   252,   253,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   263,    -1,
      -1,   266,    -1,   268,   269,    -1,    -1,   272,    -1,   274,
      -1,   276,    -1,    -1,   279,    -1,    -1,   282,   283,   284,
      -1,    -1,   287,    -1,   289,    -1,    -1,   292,    -1,    -1,
      -1,   201,    -1,    -1,    -1,    -1,    -1,   302,   303,   304,
      -1,   211,   307,   213,   214,    -1,    -1,    -1,   218,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   236,    -1,     0,     1,
      -1,    -1,    -1,    -1,    -1,   245,   246,    -1,    -1,    -1,
      -1,    -1,   252,   253,    16,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   263,    -1,    -1,   266,    -1,   268,   269,
      -1,    -1,   272,    -1,   274,    -1,   276,    -1,    -1,   279,
      -1,    -1,   282,   283,    -1,    -1,    -1,   287,    -1,    -1,
      -1,    -1,   292,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   302,   303,   304,    67,    68,   307,    -1,    -1,
      72,    -1,    74,    -1,    -1,    77,    78,    -1,    80,    81,
      82,    -1,    -1,    -1,    -1,    87,    88,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    97,    98,    -1,    -1,   101,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   121,
     122,   123,   124,    -1,   126,   127,   128,   129,   130,   131,
     132,    -1,    -1,   135,    -1,    -1,   138,    -1,   140,   141,
      -1,    -1,    -1,   145,   146,    -1,    -1,    -1,    -1,    -1,
     152,   153,   154,   155,   156,   157,    -1,    -1,   160,    -1,
      -1,    -1,    -1,    -1,   166,   167,    -1,    -1,   170,    -1,
      -1,   173,    -1,   175,   176,    -1,    -1,    -1,    -1,   181,
      -1,    -1,    -1,   185,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   228,    -1,   230,    -1,
      -1,   233,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   241
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
{
       0,     1,    67,    68,    72,    74,    77,    78,    80,    81,
      82,    87,    88,    97,    98,   101,   121,   122,   123,   124,
     126,   127,   128,   129,   130,   131,   132,   135,   138,   140,
     141,   145,   146,   152,   153,   154,   155,   156,   157,   160,
     166,   167,   170,   173,   175,   176,   181,   185,   228,   230,
     233,   241,   314,   325,   326,   327,   328,   337,   344,   364,
     365,   374,   375,   376,   378,   379,   380,   381,   382,   392,
     412,   416,   462,   463,   466,   467,   485,   521,   522,   523,
     524,   526,   530,   532,     4,   515,     6,   512,   513,   515,
     515,   515,   512,   512,   515,     6,   514,   515,   515,   520,
     525,   525,   512,   514,   514,   514,   514,     6,   413,   414,
     451,   515,   515,   512,     3,   540,   512,   512,   512,   512,
     512,   541,   366,   514,   512,     6,   510,   511,   515,   464,
     515,   512,     4,     6,   518,   139,   194,   200,   215,   220,
     230,   233,   237,   242,   272,   280,   383,   385,   386,   387,
     239,   494,   512,   383,   385,     0,    16,   168,   169,   527,
      73,   292,   277,   288,   292,   293,    99,   100,   109,   110,
     111,   222,   256,   271,   345,   346,   347,   350,   353,   356,
     357,   358,   361,   292,   119,   120,   277,   288,   294,   294,
     294,   294,   415,   416,   214,   281,   214,   214,   393,   512,
     512,   142,   165,   468,   292,   292,   277,   288,   296,   182,
     377,   214,   388,   388,   258,   294,   278,     3,   187,   232,
     272,   495,   541,   296,   294,   523,     6,   515,   528,   529,
       6,   515,     6,   515,   515,   515,     6,   159,   163,   187,
     214,   232,   238,   396,   397,   402,   404,   214,   362,   363,
     515,     3,   214,   343,   355,   404,   406,   515,   214,   352,
     515,   214,   343,   348,   278,   515,     6,   515,   515,   336,
     512,   336,   336,   336,   416,   342,   343,   512,   342,   288,
     394,   453,   456,   510,   515,   290,   136,   250,   316,   214,
     369,   515,   465,   515,     6,   515,   515,   464,   389,   453,
     226,   390,   391,   451,   512,   387,   486,    92,    93,    94,
      95,    96,   270,   317,   390,   512,   292,   292,   278,    71,
     292,   277,   214,   214,   214,   359,   404,   214,   214,   102,
     360,   362,   278,   354,   355,   106,   174,   177,   178,   179,
     186,   190,   195,   202,   205,   206,   208,   231,   240,   244,
     251,   253,   262,   264,   302,   305,   442,   443,   444,   445,
     447,   484,   351,   352,   348,   349,   297,   346,   292,   277,
     214,   214,   214,   214,   199,   278,   199,   456,   199,   278,
     292,   225,   292,   452,   230,   483,   492,     4,   516,     3,
       4,     6,    15,    17,    20,    69,    70,    75,    76,   107,
     171,   201,   211,   213,   214,   217,   218,   236,   245,   246,
     252,   253,   263,   266,   268,   269,   272,   274,   276,   279,
     282,   283,   284,   286,   287,   289,   292,   302,   303,   304,
     307,   426,   427,   428,   429,   430,   437,   439,   458,   469,
     470,   471,   472,   473,   493,   499,   500,   507,   515,   517,
     531,   533,   537,   538,   539,   370,   371,   515,   234,   367,
     492,   296,   292,   277,   199,   278,   278,   258,   214,   496,
     497,   498,   499,   235,   323,   324,   499,   323,   323,   323,
     288,   319,   320,   322,   515,   318,   319,   321,   136,   250,
     315,   296,   515,   515,   529,   515,     6,   515,   399,   401,
     453,   403,   453,   403,   199,   278,   360,   403,   426,   482,
     515,   199,   363,   199,   278,   214,   214,   214,   188,   221,
     229,   245,   259,   268,   279,   460,   460,   214,   214,   214,
     214,   214,   214,   214,   214,   147,   148,   149,   203,   405,
     407,   199,   278,   199,   278,   515,   515,     6,   515,   340,
     341,   515,   340,   340,   340,   164,   338,   343,    89,   110,
     111,   158,   293,   329,   330,   331,   453,   246,   515,     3,
     515,   494,   133,   395,   214,   292,     6,   214,   214,   493,
     459,   460,   494,   426,   499,   493,   214,   214,   257,   267,
     426,   501,   502,   214,   493,   214,   214,   493,   493,   214,
     214,   214,   214,   538,   429,   214,   538,     3,   214,   295,
     273,   460,   460,   162,   183,   191,   192,   197,   207,   210,
     212,   223,   224,   243,   261,   286,   293,   299,   300,   436,
     438,   225,   292,    79,   113,   114,   115,   116,   117,   118,
     246,   255,   284,   289,   506,   125,   199,   278,   292,   368,
     465,   515,     6,   515,   453,   391,   390,   499,   278,   487,
     290,   515,   199,   278,   199,   320,   199,   278,   292,   452,
     278,   223,   516,   426,   390,   292,   292,   199,   278,   199,
     278,   199,   404,   199,   199,   355,     3,   448,   448,     3,
     296,   214,   296,     3,   449,     3,     3,     3,   449,   449,
       3,     3,     6,   458,   137,   163,   172,   187,   193,   232,
     238,   398,   408,   409,   410,   411,   352,   348,   292,   199,
     278,   254,   275,   199,   199,   199,   329,     3,     3,     4,
     332,   331,   452,   209,   278,   292,   495,   199,   499,   503,
     515,    21,   503,   503,   296,   495,   199,   199,   499,   505,
     531,   503,   499,   426,   501,   298,   502,   503,   503,   503,
     187,   232,   272,   440,   503,   440,   440,   440,   440,   427,
     428,   296,   214,   296,   434,   538,   434,   434,   434,   214,
     493,   235,   499,   434,   214,   493,   434,   161,   196,   198,
     499,     3,   214,   284,   289,   534,   536,   246,   304,   515,
     499,   499,   499,   499,   499,   442,   371,   515,   214,   292,
     498,   519,   515,   324,   223,   319,   246,   515,   321,   324,
     134,   290,   384,   515,   515,   398,   453,   453,   360,   199,
     199,   199,   278,   188,   221,   229,   245,   259,   268,   279,
     461,     3,   461,   278,   446,   199,   199,   278,   199,   199,
     446,   199,   199,   400,   512,   214,   410,   360,   515,    63,
      64,   293,   301,   333,   334,   335,   341,   333,   333,   333,
     338,     3,   515,   496,   199,   278,   292,   199,   199,   461,
     496,   278,   460,   504,   199,   504,   199,   265,   298,   199,
     199,   199,   499,   199,   499,   499,   499,   499,   461,     3,
     461,   216,   431,   216,   433,   216,   432,   431,   284,   458,
     508,   509,   531,   433,   508,   432,   499,   534,   209,   246,
     255,   278,   284,   285,   289,   535,     3,   225,   292,   235,
     372,   373,   499,   515,   258,   419,   423,   214,   292,   452,
     451,     3,   214,   199,     3,   450,   199,     3,   199,   214,
     482,   332,     3,   335,   209,   452,   423,   499,   515,   423,
     460,   296,   499,   199,   199,   199,   199,   199,   199,   435,
     458,   435,   435,     3,   517,   199,   278,   199,   273,   199,
     534,   534,   534,   515,   199,   278,   420,   422,   512,   189,
     219,   250,   417,   418,   424,   425,   479,   249,   489,   323,
     515,   199,     3,   296,   199,   401,   199,   225,   199,   296,
     461,   296,   509,   499,   209,   209,   278,   225,   373,    49,
      56,   278,   290,   457,   515,     3,   288,   304,   454,   455,
     480,   481,   510,   515,   426,   426,   425,   417,   187,   232,
     272,   441,   184,   247,   474,   490,   199,   452,   199,   461,
     199,   534,   461,   461,   534,   534,   214,   420,   421,   421,
     248,   422,   457,   455,   278,   292,   452,   230,   488,   491,
     515,   291,   184,   209,   278,   209,   209,   278,   420,   294,
     294,   214,   422,   481,   246,   515,   494,   164,   339,     3,
     454,   475,   476,   477,   491,   534,   534,   199,   426,   426,
     420,   452,   495,   278,   254,   275,   478,   339,   209,   209,
     199,   496,   476,   423,   489
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
#line 488 "sql.yacc"
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
#line 517 "sql.yacc"
    {
		(yyval.ptr)=0;
	}
    break;

  case 4:

/* Line 1464 of yacc.c  */
#line 520 "sql.yacc"
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
#line 537 "sql.yacc"
    {
		(yyval.ptr)=A4GL_new_select_list_item_expr((yyvsp[(2) - (2)].s_select_list_item));
	}
    break;

  case 6:

/* Line 1464 of yacc.c  */
#line 542 "sql.yacc"
    {
		(yyval.ptr)=0;
	}
    break;

  case 7:

/* Line 1464 of yacc.c  */
#line 545 "sql.yacc"
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
#line 562 "sql.yacc"
    {
		 (yyval.ptr)=A4GL_new_select_list_item_expr((yyvsp[(2) - (2)].s_select_list_item));
	}
    break;

  case 9:

/* Line 1464 of yacc.c  */
#line 568 "sql.yacc"
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
#line 577 "sql.yacc"
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
#line 586 "sql.yacc"
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
#line 595 "sql.yacc"
    {
		(yyval.update_cmd)=(yyvsp[(2) - (2)].update_cmd);
		add_feature("UPDATE_COLUMN_EQ_VALUE_LIST");
    }
    break;

  case 13:

/* Line 1464 of yacc.c  */
#line 602 "sql.yacc"
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
#line 617 "sql.yacc"
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
#line 672 "sql.yacc"
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
#line 679 "sql.yacc"
    {
		(yyval.update_cmd)=(yyvsp[(1) - (3)].update_cmd);
		add_str_list((yyval.update_cmd)->column_list, (yyvsp[(3) - (3)].upd_pair)->column_name);
		local_add_select_list_item_list((yyval.update_cmd)->value_list, (yyvsp[(3) - (3)].upd_pair)->value);
	}
    break;

  case 17:

/* Line 1464 of yacc.c  */
#line 690 "sql.yacc"
    {
                strcpy((yyval.str),(yyvsp[(1) - (1)].str));
        }
    break;

  case 18:

/* Line 1464 of yacc.c  */
#line 693 "sql.yacc"
    {
                strcpy((yyval.str),(yyvsp[(2) - (2)].str));
        }
    break;

  case 19:

/* Line 1464 of yacc.c  */
#line 698 "sql.yacc"
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
#line 705 "sql.yacc"
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
#line 722 "sql.yacc"
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
#line 739 "sql.yacc"
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
#line 760 "sql.yacc"
    {
		(yyval.upd_pair)=malloc(sizeof(struct s_update_pair));
		(yyval.upd_pair)->column_name=acl_strdup((yyvsp[(1) - (3)].str));
		(yyval.upd_pair)->value=(yyvsp[(3) - (3)].s_select_list_item);
	}
    break;

  case 24:

/* Line 1464 of yacc.c  */
#line 769 "sql.yacc"
    {
			(yyval.str_list)=new_str_list((yyvsp[(1) - (1)].str));
		}
    break;

  case 25:

/* Line 1464 of yacc.c  */
#line 772 "sql.yacc"
    {
			(yyval.str_list)=add_str_list((yyvsp[(1) - (3)].str_list), (yyvsp[(3) - (3)].str));
		}
    break;

  case 26:

/* Line 1464 of yacc.c  */
#line 780 "sql.yacc"
    { 
		(yyval.s_select_list_item_list)=local_new_select_list_item_list((yyvsp[(1) - (1)].s_select_list_item));
	}
    break;

  case 27:

/* Line 1464 of yacc.c  */
#line 783 "sql.yacc"
    { 
		(yyval.s_select_list_item_list)=local_add_select_list_item_list((yyvsp[(1) - (3)].s_select_list_item_list),(yyvsp[(3) - (3)].s_select_list_item));
	}
    break;

  case 28:

/* Line 1464 of yacc.c  */
#line 791 "sql.yacc"
    {(yyval.s_select_list_item)=(yyvsp[(1) - (1)].s_select_list_item);}
    break;

  case 29:

/* Line 1464 of yacc.c  */
#line 792 "sql.yacc"
    {(yyval.s_select_list_item)=new_select_list_item_builtin_const(E_SLI_BUILTIN_CONST_NULL); }
    break;

  case 30:

/* Line 1464 of yacc.c  */
#line 799 "sql.yacc"
    { (yyval.sql_string)=make_sql_string_and_free(acl_strdup((yyvsp[(1) - (1)].str)), NULL);}
    break;

  case 31:

/* Line 1464 of yacc.c  */
#line 802 "sql.yacc"
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
#line 810 "sql.yacc"
    {SPRINTF2((yyval.str),"%s %s ",(yyvsp[(1) - (2)].str),(yyvsp[(2) - (2)].str));
			add_feature("DROP_VIEW");
}
    break;

  case 33:

/* Line 1464 of yacc.c  */
#line 813 "sql.yacc"
    {SPRINTF2((yyval.str),"%s %s",(yyvsp[(1) - (2)].str),(yyvsp[(2) - (2)].str));
		if (strchr((yyvsp[(2) - (2)].str),'@') || strchr((yyvsp[(2) - (2)].str),':')) add_feature("DROP_INDEX_QUALIFIED_PATH");
			add_feature("DROP_INDEX");
}
    break;

  case 34:

/* Line 1464 of yacc.c  */
#line 817 "sql.yacc"
    {SPRINTF2((yyval.str),"%s %s",(yyvsp[(1) - (2)].str),(yyvsp[(2) - (2)].str));
			add_feature("DROP_TRIGGER");
}
    break;

  case 35:

/* Line 1464 of yacc.c  */
#line 823 "sql.yacc"
    {(yyval.sql_string)=acl_strdup((yyvsp[(1) - (1)].str));}
    break;

  case 36:

/* Line 1464 of yacc.c  */
#line 824 "sql.yacc"
    {(yyval.sql_string)=(yyvsp[(1) - (1)].sql_string);}
    break;

  case 37:

/* Line 1464 of yacc.c  */
#line 828 "sql.yacc"
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
#line 838 "sql.yacc"
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
#line 852 "sql.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 40:

/* Line 1464 of yacc.c  */
#line 853 "sql.yacc"
    {strcpy((yyval.str),(yyvsp[(1) - (1)].str));}
    break;

  case 42:

/* Line 1464 of yacc.c  */
#line 858 "sql.yacc"
    {SPRINTF2((yyval.str),"%s%s",(yyvsp[(1) - (2)].str),(yyvsp[(2) - (2)].str)); }
    break;

  case 43:

/* Line 1464 of yacc.c  */
#line 863 "sql.yacc"
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
#line 871 "sql.yacc"
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
#line 879 "sql.yacc"
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
#line 887 "sql.yacc"
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
#line 895 "sql.yacc"
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
#line 907 "sql.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 50:

/* Line 1464 of yacc.c  */
#line 907 "sql.yacc"
    {strcpy((yyval.str),(yyvsp[(1) - (1)].str));}
    break;

  case 52:

/* Line 1464 of yacc.c  */
#line 911 "sql.yacc"
    {SPRINTF2((yyval.str),"%s%s",(yyvsp[(1) - (2)].str),(yyvsp[(2) - (2)].str));}
    break;

  case 53:

/* Line 1464 of yacc.c  */
#line 915 "sql.yacc"
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
#line 922 "sql.yacc"
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
#line 929 "sql.yacc"
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
#line 936 "sql.yacc"
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
#line 945 "sql.yacc"
    { strcpy(last_tmp_name,(yyvsp[(1) - (1)].str)); }
    break;

  case 58:

/* Line 1464 of yacc.c  */
#line 949 "sql.yacc"
    {SPRINTF7((yyval.str),"CREATE UNIQUE INDEX %s %s %s %s %s %s %s",(yyvsp[(2) - (8)].str),(yyvsp[(3) - (8)].str),(yyvsp[(4) - (8)].str),(yyvsp[(5) - (8)].str),(yyvsp[(6) - (8)].str),(yyvsp[(7) - (8)].str),(yyvsp[(8) - (8)].str));
		add_feature("CREATE_INDEX");
		add_feature("CREATE_INDEX_UNIQUE");
		if (strchr((yyvsp[(2) - (8)].str),'@') || strchr((yyvsp[(2) - (8)].str),':')) add_feature("CREATE_INDEX_QUALIFIED_PATH");
		if (strchr((yyvsp[(6) - (8)].str),',')) { add_feature("CREATE_INDEX_COMPOSITE"); }
	
}
    break;

  case 59:

/* Line 1464 of yacc.c  */
#line 956 "sql.yacc"
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
#line 968 "sql.yacc"
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
#line 979 "sql.yacc"
    {
		if (strchr((yyvsp[(2) - (8)].str),'@') || strchr((yyvsp[(2) - (8)].str),':')) add_feature("CREATE_INDEX_QUALIFIED_PATH");
		if (strchr((yyvsp[(6) - (8)].str),',')) { add_feature("CREATE_INDEX_COMPOSITE"); }
			add_feature("CREATE_INDEX");
			SPRINTF7((yyval.str)," CREATE INDEX %s %s %s %s %s %s %s",(yyvsp[(2) - (8)].str),(yyvsp[(3) - (8)].str),(yyvsp[(4) - (8)].str),(yyvsp[(5) - (8)].str),(yyvsp[(6) - (8)].str),(yyvsp[(7) - (8)].str),(yyvsp[(8) - (8)].str));
	}
    break;

  case 62:

/* Line 1464 of yacc.c  */
#line 985 "sql.yacc"
    {
		add_feature("CREATE_DATABASE");
		a4gl_yyerror("You cannot create a database from within Aubit4gl - if the target database allows - prepare and execute it manually");
	}
    break;

  case 63:

/* Line 1464 of yacc.c  */
#line 989 "sql.yacc"
    {
		add_feature("DROP_DATABASE");
		a4gl_yyerror("You cannot drop a database from within Aubit4gl - if the target database allows - prepare and execute it manually");
	}
    break;

  case 64:

/* Line 1464 of yacc.c  */
#line 993 "sql.yacc"
    { 
		if (strchr((yyvsp[(2) - (4)].str),'@') || strchr((yyvsp[(2) - (4)].str),':')) add_feature("CREATE_SYNONYM_QUALIFIED_PATH");
			add_feature("CREATE_SYNONYM");
			SPRINTF3((yyval.str),"%s %s FOR %s",(yyvsp[(1) - (4)].str),(yyvsp[(2) - (4)].str),(yyvsp[(4) - (4)].str)); 
	}
    break;

  case 65:

/* Line 1464 of yacc.c  */
#line 998 "sql.yacc"
    { 
		add_feature("CREATE_AUDIT");
		SPRINTF2((yyval.str),"CREATE AUDIT FOR %s IN '%s'",(yyvsp[(2) - (4)].str),A4GL_strip_quotes((yyvsp[(4) - (4)].str))); 
	}
    break;

  case 66:

/* Line 1464 of yacc.c  */
#line 1002 "sql.yacc"
    { 
		add_feature("DROP_AUDIT");
		SPRINTF1((yyval.str),"DROP AUDIT FOR %s",(yyvsp[(2) - (2)].str)); }
    break;

  case 67:

/* Line 1464 of yacc.c  */
#line 1005 "sql.yacc"
    { 
		if (strchr((yyvsp[(2) - (2)].str),'@') || strchr((yyvsp[(2) - (2)].str),':')) add_feature("DROP_SYNONYM_QUALIFIED_PATH");
		add_feature("DROP_SYNONYM");
		SPRINTF2((yyval.str),"%s %s",(yyvsp[(1) - (2)].str),(yyvsp[(2) - (2)].str)); }
    break;

  case 68:

/* Line 1464 of yacc.c  */
#line 1009 "sql.yacc"
    { 
		add_feature("RECOVER_TABLE");
		SPRINTF1((yyval.str),"RECOVER TABLE %s",(yyvsp[(2) - (2)].str)); }
    break;

  case 69:

/* Line 1464 of yacc.c  */
#line 1012 "sql.yacc"
    { 
		add_feature("ROLLFORWARD_DATABASE");
		SPRINTF1((yyval.str),"ROLLFORWARD DATABASE %s",(yyvsp[(2) - (2)].str)); }
    break;

  case 70:

/* Line 1464 of yacc.c  */
#line 1019 "sql.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 71:

/* Line 1464 of yacc.c  */
#line 1020 "sql.yacc"
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
#line 1030 "sql.yacc"
    {(yyval.integer_val)=0;}
    break;

  case 73:

/* Line 1464 of yacc.c  */
#line 1031 "sql.yacc"
    { (yyval.integer_val)=1;}
    break;

  case 75:

/* Line 1464 of yacc.c  */
#line 1036 "sql.yacc"
    {SPRINTF2((yyval.str),"%s,%s",(yyvsp[(1) - (3)].str),(yyvsp[(3) - (3)].str));}
    break;

  case 76:

/* Line 1464 of yacc.c  */
#line 1040 "sql.yacc"
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
#line 1049 "sql.yacc"
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
#line 1058 "sql.yacc"
    {
		strcpy((yyval.str),A4GL_confirm_colname(last_tmp_name,(yyvsp[(1) - (1)].str)));
}
    break;

  case 79:

/* Line 1464 of yacc.c  */
#line 1065 "sql.yacc"
    {
		(yyval.sql_string)=(yyvsp[(1) - (1)].sql_string);
	}
    break;

  case 80:

/* Line 1464 of yacc.c  */
#line 1068 "sql.yacc"
    {
		(yyval.sql_string)=make_sql_string_and_free((yyvsp[(1) - (3)].sql_string),kw_comma,strdup("\n"),(yyvsp[(3) - (3)].sql_string),NULL);
	}
    break;

  case 81:

/* Line 1464 of yacc.c  */
#line 1074 "sql.yacc"
    {
		(yyval.sql_string)=make_sql_string_and_free(strdup("   "),(yyvsp[(1) - (1)].sql_string),NULL);
	}
    break;

  case 82:

/* Line 1464 of yacc.c  */
#line 1077 "sql.yacc"
    {
		(yyval.sql_string)=make_sql_string_and_free(strdup("   "),(yyvsp[(1) - (1)].sql_string),NULL);
	}
    break;

  case 83:

/* Line 1464 of yacc.c  */
#line 1088 "sql.yacc"
    {
		add_feature("ALTER_TABLE");
	(yyval.sql_string)=make_sql_string_and_free(acl_strdup((yyvsp[(1) - (3)].str)),kw_space,acl_strdup((yyvsp[(2) - (3)].str)),kw_space,(yyvsp[(3) - (3)].sql_string),NULL);
	}
    break;

  case 84:

/* Line 1464 of yacc.c  */
#line 1092 "sql.yacc"
    {
		add_feature("CLUSTER_INDEX");
		add_feature("ALTER_INDEX_CLUSTER");
		(yyval.sql_string)=make_sql_string_and_free(acl_strdup("ALTER INDEX "),acl_strdup((yyvsp[(2) - (3)].str)),acl_strdup(" TO CLUSTER"),NULL);
		}
    break;

  case 85:

/* Line 1464 of yacc.c  */
#line 1097 "sql.yacc"
    {
		add_feature("ALTER_INDEX_NOT_CLUSTER");
		(yyval.sql_string)=make_sql_string_and_free(acl_strdup("ALTER INDEX "),acl_strdup((yyvsp[(2) - (3)].str)),acl_strdup(" TO NOT CLUSTER"),NULL);
		}
    break;

  case 86:

/* Line 1464 of yacc.c  */
#line 1104 "sql.yacc"
    {
		(yyval.sql_string)=(yyvsp[(1) - (1)].sql_string);
	}
    break;

  case 87:

/* Line 1464 of yacc.c  */
#line 1107 "sql.yacc"
    {
		(yyval.sql_string)=make_sql_string_and_free((yyvsp[(1) - (3)].sql_string),kw_comma,(yyvsp[(3) - (3)].sql_string),NULL);
	}
    break;

  case 88:

/* Line 1464 of yacc.c  */
#line 1116 "sql.yacc"
    {
		(yyval.sql_string)=(yyvsp[(1) - (1)].sql_string);
	}
    break;

  case 89:

/* Line 1464 of yacc.c  */
#line 1119 "sql.yacc"
    {
	add_feature("ALTER_TABLE_DROP");
		(yyval.sql_string)=acl_strdup((yyvsp[(1) - (1)].str));
	}
    break;

  case 90:

/* Line 1464 of yacc.c  */
#line 1123 "sql.yacc"
    {
	add_feature("ALTER_TABLE_MODIFY");
		(yyval.sql_string)=(yyvsp[(1) - (1)].sql_string);
	}
    break;

  case 91:

/* Line 1464 of yacc.c  */
#line 1127 "sql.yacc"
    {
		add_feature("ALTER_TABLE_ADD_CONSTRAINT");
		(yyval.sql_string)=acl_strdup((yyvsp[(1) - (1)].str));
	}
    break;

  case 92:

/* Line 1464 of yacc.c  */
#line 1131 "sql.yacc"
    {
		add_feature("ALTER_TABLE_DROP_CONSTRAINT");
		(yyval.sql_string)=acl_strdup((yyvsp[(1) - (1)].str));
	}
    break;

  case 93:

/* Line 1464 of yacc.c  */
#line 1135 "sql.yacc"
    {
		add_feature("ALTER_TABLE_MODIFY_NEXT");
		(yyval.sql_string)=acl_strdup((yyvsp[(1) - (1)].str));
	}
    break;

  case 94:

/* Line 1464 of yacc.c  */
#line 1139 "sql.yacc"
    {
		add_feature("ALTER_TABLE_LOCK_MODE");
		(yyval.sql_string)=acl_strdup((yyvsp[(1) - (1)].str));
	}
    break;

  case 95:

/* Line 1464 of yacc.c  */
#line 1147 "sql.yacc"
    {
		add_feature("ALTER_TABLE_ADD");
		(yyval.sql_string)=make_sql_string_and_free(acl_strdup("ADD "),(yyvsp[(2) - (2)].sql_string),NULL);
	}
    break;

  case 96:

/* Line 1464 of yacc.c  */
#line 1151 "sql.yacc"
    {
		add_feature("ALTER_TABLE_ADD");
		(yyval.sql_string)=make_sql_string_and_free(acl_strdup("ADD "),kw_ob,(yyvsp[(3) - (4)].sql_string),kw_cb,NULL);
	}
    break;

  case 97:

/* Line 1464 of yacc.c  */
#line 1159 "sql.yacc"
    {
		(yyval.sql_string)=(yyvsp[(1) - (1)].sql_string);
	}
    break;

  case 98:

/* Line 1464 of yacc.c  */
#line 1162 "sql.yacc"
    {
		add_feature("ALTER_TABLE_ADD_BEFORE");
		(yyval.sql_string)=make_sql_string_and_free((yyvsp[(1) - (3)].sql_string),acl_strdup(" BEFORE "),acl_strdup((yyvsp[(3) - (3)].str)),NULL);
	}
    break;

  case 99:

/* Line 1464 of yacc.c  */
#line 1169 "sql.yacc"
    {
		(yyval.sql_string)=(yyvsp[(1) - (1)].sql_string);
	}
    break;

  case 100:

/* Line 1464 of yacc.c  */
#line 1172 "sql.yacc"
    {
		(yyval.sql_string)=make_sql_string_and_free((yyvsp[(1) - (3)].sql_string),kw_comma,(yyvsp[(3) - (3)].sql_string),NULL);
	}
    break;

  case 101:

/* Line 1464 of yacc.c  */
#line 1179 "sql.yacc"
    {
		SPRINTF1((yyval.str),"DROP %s",(yyvsp[(2) - (2)].str));
	}
    break;

  case 102:

/* Line 1464 of yacc.c  */
#line 1182 "sql.yacc"
    {
		SPRINTF1((yyval.str),"DROP (%s)",(yyvsp[(3) - (4)].str));
	}
    break;

  case 104:

/* Line 1464 of yacc.c  */
#line 1190 "sql.yacc"
    {
		SPRINTF2((yyval.str),"%s,%s",(yyvsp[(1) - (3)].str),(yyvsp[(3) - (3)].str));
	}
    break;

  case 106:

/* Line 1464 of yacc.c  */
#line 1199 "sql.yacc"
    {
		(yyval.sql_string)=make_sql_string_and_free(acl_strdup("MODIFY "),(yyvsp[(2) - (2)].sql_string),NULL);
	}
    break;

  case 107:

/* Line 1464 of yacc.c  */
#line 1202 "sql.yacc"
    {
		(yyval.sql_string)=make_sql_string_and_free(acl_strdup("MODIFY "),kw_ob,(yyvsp[(3) - (4)].sql_string),kw_cb,NULL);
	}
    break;

  case 108:

/* Line 1464 of yacc.c  */
#line 1208 "sql.yacc"
    {
		(yyval.sql_string)=(yyvsp[(1) - (1)].sql_string);
	}
    break;

  case 109:

/* Line 1464 of yacc.c  */
#line 1211 "sql.yacc"
    {
		(yyval.sql_string)=make_sql_string_and_free((yyvsp[(1) - (3)].sql_string),kw_comma,(yyvsp[(3) - (3)].sql_string),NULL);
	}
    break;

  case 110:

/* Line 1464 of yacc.c  */
#line 1217 "sql.yacc"
    {
		(yyval.sql_string)=(yyvsp[(1) - (1)].sql_string);
	}
    break;

  case 111:

/* Line 1464 of yacc.c  */
#line 1224 "sql.yacc"
    {strcpy((yyval.str),"LOCK MODE (PAGE)");}
    break;

  case 112:

/* Line 1464 of yacc.c  */
#line 1225 "sql.yacc"
    {strcpy((yyval.str),"LOCK MODE (ROW)");}
    break;

  case 113:

/* Line 1464 of yacc.c  */
#line 1229 "sql.yacc"
    {
		add_feature("DDL_NEXT_SIZE");
		SPRINTF1((yyval.str),"MODIFY NEXT SIZE %d",atoi((yyvsp[(2) - (2)].str)));
	}
    break;

  case 114:

/* Line 1464 of yacc.c  */
#line 1237 "sql.yacc"
    {
		add_feature("DDL_CONSTRAINT");
		SPRINTF2((yyval.str),"ADD CONSTRAINT %s%s",(yyvsp[(2) - (3)].sql_string),(yyvsp[(3) - (3)].str));
	}
    break;

  case 115:

/* Line 1464 of yacc.c  */
#line 1241 "sql.yacc"
    {
		add_feature("ADD_CONSTRAINT");
		SPRINTF1((yyval.str),"ADD CONSTRAINT (%s)",(yyvsp[(3) - (4)].sql_string));
	}
    break;

  case 116:

/* Line 1464 of yacc.c  */
#line 1248 "sql.yacc"
    {
		(yyval.sql_string)=make_sql_string_and_free((yyvsp[(1) - (2)].sql_string),acl_strdup((yyvsp[(2) - (2)].str)),NULL);
}
    break;

  case 117:

/* Line 1464 of yacc.c  */
#line 1250 "sql.yacc"
    {
	(yyval.sql_string)=make_sql_string_and_free((yyvsp[(1) - (4)].sql_string),kw_comma,(yyvsp[(3) - (4)].sql_string),acl_strdup((yyvsp[(4) - (4)].str)), NULL);
}
    break;

  case 118:

/* Line 1464 of yacc.c  */
#line 1255 "sql.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 119:

/* Line 1464 of yacc.c  */
#line 1256 "sql.yacc"
    {SPRINTF2((yyval.str)," %s %s",(yyvsp[(1) - (2)].str),(yyvsp[(2) - (2)].str)); add_feature("DDL_CONSTRAINT");}
    break;

  case 120:

/* Line 1464 of yacc.c  */
#line 1261 "sql.yacc"
    { SPRINTF1((yyval.str),"DROP CONSTRAINT %s",(yyvsp[(2) - (2)].str)); add_feature("DROP_CONSTRAINT"); }
    break;

  case 121:

/* Line 1464 of yacc.c  */
#line 1262 "sql.yacc"
    {add_feature("DROP_CONSTRAINT");
		SPRINTF1((yyval.str),"DROP CONSTRAINT (%s)",(yyvsp[(3) - (4)].str));
	}
    break;

  case 122:

/* Line 1464 of yacc.c  */
#line 1268 "sql.yacc"
    {strcpy((yyval.str),(yyvsp[(1) - (1)].str));}
    break;

  case 123:

/* Line 1464 of yacc.c  */
#line 1269 "sql.yacc"
    {SPRINTF2((yyval.str),"%s,%s",(yyvsp[(1) - (3)].str),(yyvsp[(3) - (3)].str));}
    break;

  case 125:

/* Line 1464 of yacc.c  */
#line 1283 "sql.yacc"
    {  add_feature("ROLLBACK_WORK"); }
    break;

  case 126:

/* Line 1464 of yacc.c  */
#line 1289 "sql.yacc"
    { insql=1;}
    break;

  case 127:

/* Line 1464 of yacc.c  */
#line 1289 "sql.yacc"
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
#line 1298 "sql.yacc"
    {insql=1;}
    break;

  case 129:

/* Line 1464 of yacc.c  */
#line 1298 "sql.yacc"
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
#line 1307 "sql.yacc"
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
#line 1332 "sql.yacc"
    {
			(yyval.str_list)=0;
	}
    break;

  case 132:

/* Line 1464 of yacc.c  */
#line 1335 "sql.yacc"
    {
			(yyval.str_list)=(yyvsp[(2) - (3)].str_list);
			 add_feature("INSERT_COLUMNLIST_EQ_VALUELIST");
	}
    break;

  case 133:

/* Line 1464 of yacc.c  */
#line 1343 "sql.yacc"
    {
                        (yyval.str_list)=new_str_list((yyvsp[(1) - (1)].str));
	}
    break;

  case 134:

/* Line 1464 of yacc.c  */
#line 1346 "sql.yacc"
    {
                        (yyval.str_list)=add_str_list((yyvsp[(1) - (3)].str_list), (yyvsp[(3) - (3)].str));
	}
    break;

  case 135:

/* Line 1464 of yacc.c  */
#line 1353 "sql.yacc"
    {	
			strcpy((yyval.str),(yyvsp[(1) - (1)].str));
	}
    break;

  case 136:

/* Line 1464 of yacc.c  */
#line 1356 "sql.yacc"
    { 
			/* with a table prefix - on an insert ? We'll just silently drop it... */
			strcpy((yyval.str),(yyvsp[(3) - (3)].str));
			A4GL_warn("Dropped table prefix from INSERT column name");
	}
    break;

  case 137:

/* Line 1464 of yacc.c  */
#line 1364 "sql.yacc"
    { (yyval.s_select_list_item_list)=local_new_select_list_item_list((yyvsp[(1) - (1)].s_select_list_item));}
    break;

  case 138:

/* Line 1464 of yacc.c  */
#line 1365 "sql.yacc"
    {
		(yyval.s_select_list_item_list)=local_add_select_list_item_list((yyvsp[(1) - (3)].s_select_list_item_list),(yyvsp[(3) - (3)].s_select_list_item));
	}
    break;

  case 139:

/* Line 1464 of yacc.c  */
#line 1371 "sql.yacc"
    {(yyval.s_select_list_item)=(yyvsp[(1) - (1)].s_select_list_item);}
    break;

  case 140:

/* Line 1464 of yacc.c  */
#line 1372 "sql.yacc"
    {(yyval.s_select_list_item)=new_select_list_item_builtin_const(E_SLI_BUILTIN_CONST_NULL); }
    break;

  case 141:

/* Line 1464 of yacc.c  */
#line 1380 "sql.yacc"
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
#line 1402 "sql.yacc"
    { add_feature("BEGIN_WORK"); }
    break;

  case 143:

/* Line 1464 of yacc.c  */
#line 1406 "sql.yacc"
    { add_feature("COMMIT_WORK"); }
    break;

  case 144:

/* Line 1464 of yacc.c  */
#line 1411 "sql.yacc"
    {(yyval.e_boolean)=EB_FALSE;}
    break;

  case 145:

/* Line 1464 of yacc.c  */
#line 1412 "sql.yacc"
    {
		add_feature("DATABASE_EXCLUSIVE");
		{(yyval.e_boolean)=EB_TRUE;}
	}
    break;

  case 146:

/* Line 1464 of yacc.c  */
#line 1422 "sql.yacc"
    {
	char buff[256];
	(yyval.sql_string)=make_sql_string_and_free(acl_strdup((yyvsp[(1) - (1)].str)),NULL);
	SPRINTF1(buff,"Warning: Informix specific SQL @ line %d\n",yylineno);
	ansi_violation(buff,1);
	}
    break;

  case 147:

/* Line 1464 of yacc.c  */
#line 1431 "sql.yacc"
    {
			add_feature("START_DATABASE_WITH_LOG_MODE_ANSI");
			sprintf((yyval.str),"START DATABASE %s WITH LOG IN %s MODE ANSI", (yyvsp[(2) - (5)].str),(yyvsp[(4) - (5)].str));
	}
    break;

  case 148:

/* Line 1464 of yacc.c  */
#line 1435 "sql.yacc"
    {
			add_feature("START_DATABASE_WITH_LOG");
			sprintf((yyval.str),"START DATABASE %s WITH LOG IN %s", (yyvsp[(2) - (4)].str),(yyvsp[(4) - (4)].str));
	}
    break;

  case 149:

/* Line 1464 of yacc.c  */
#line 1440 "sql.yacc"
    {
			add_feature("SET_CONSTRAINTS_ALL_IMMEDIATE");
			SPRINTF1((yyval.str),"%s",(yyvsp[(1) - (1)].str)); 
	}
    break;

  case 150:

/* Line 1464 of yacc.c  */
#line 1444 "sql.yacc"
    {
		add_feature("SET_BUFFERED_LOG");
			SPRINTF1((yyval.str),"%s",(yyvsp[(1) - (1)].str)); 
	}
    break;

  case 151:

/* Line 1464 of yacc.c  */
#line 1448 "sql.yacc"
    {
		add_feature("SET_LOG");
			SPRINTF1((yyval.str),"%s",(yyvsp[(1) - (1)].str)); 
	}
    break;

  case 152:

/* Line 1464 of yacc.c  */
#line 1452 "sql.yacc"
    {
			SPRINTF2((yyval.str),"%s %s",(yyvsp[(1) - (2)].str),(yyvsp[(2) - (2)].str)); add_feature("UPDATE_STATISTICS_TABLE");
	}
    break;

  case 153:

/* Line 1464 of yacc.c  */
#line 1455 "sql.yacc"
    {
		add_feature("UPDATE_STATISTICS");
			SPRINTF1((yyval.str),"%s",(yyvsp[(1) - (1)].str)); 
	}
    break;

  case 154:

/* Line 1464 of yacc.c  */
#line 1462 "sql.yacc"
    { (yyval.integer_val)=1; 
#ifndef  SQLCOMPILER
				set_cmdlineno(token_read_on_line);
#endif

}
    break;

  case 155:

/* Line 1464 of yacc.c  */
#line 1468 "sql.yacc"
    { (yyval.integer_val)=-1; 
#ifndef  SQLCOMPILER
set_cmdlineno(token_read_on_line);
#endif
}
    break;

  case 156:

/* Line 1464 of yacc.c  */
#line 1473 "sql.yacc"
    { (yyval.integer_val)=0; 
#ifndef  SQLCOMPILER
set_cmdlineno(token_read_on_line);
#endif
}
    break;

  case 157:

/* Line 1464 of yacc.c  */
#line 1481 "sql.yacc"
    { (yyval.sql_string)=(yyvsp[(1) - (1)].sql_string); }
    break;

  case 158:

/* Line 1464 of yacc.c  */
#line 1482 "sql.yacc"
    { (yyval.sql_string)=(yyvsp[(1) - (1)].sql_string); }
    break;

  case 159:

/* Line 1464 of yacc.c  */
#line 1483 "sql.yacc"
    { (yyval.sql_string)=(yyvsp[(1) - (1)].sql_string); }
    break;

  case 160:

/* Line 1464 of yacc.c  */
#line 1484 "sql.yacc"
    { (yyval.sql_string)=(yyvsp[(1) - (1)].sql_string); }
    break;

  case 161:

/* Line 1464 of yacc.c  */
#line 1485 "sql.yacc"
    { (yyval.sql_string)=(yyvsp[(1) - (1)].sql_string); }
    break;

  case 162:

/* Line 1464 of yacc.c  */
#line 1486 "sql.yacc"
    { (yyval.sql_string)=(yyvsp[(1) - (1)].sql_string); }
    break;

  case 163:

/* Line 1464 of yacc.c  */
#line 1487 "sql.yacc"
    { (yyval.sql_string)=(yyvsp[(1) - (1)].sql_string); }
    break;

  case 164:

/* Line 1464 of yacc.c  */
#line 1495 "sql.yacc"
    {SPRINTF7((yyval.str),"%s %s %s %s %s %s %s",(yyvsp[(1) - (7)].str),(yyvsp[(2) - (7)].str),(yyvsp[(3) - (7)].str),(yyvsp[(4) - (7)].str),(yyvsp[(5) - (7)].str),(yyvsp[(6) - (7)].str),(yyvsp[(7) - (7)].str));  add_feature("GRANT"); }
    break;

  case 165:

/* Line 1464 of yacc.c  */
#line 1496 "sql.yacc"
    {SPRINTF6((yyval.str),"%s %s %s %s %s %s",(yyvsp[(1) - (6)].str),(yyvsp[(2) - (6)].str),(yyvsp[(3) - (6)].str),(yyvsp[(4) - (6)].str),(yyvsp[(5) - (6)].str),(yyvsp[(6) - (6)].str));  add_feature("REVOKE"); }
    break;

  case 166:

/* Line 1464 of yacc.c  */
#line 1497 "sql.yacc"
    {SPRINTF4((yyval.str),"%s %s %s %s ",(yyvsp[(1) - (4)].str),(yyvsp[(2) - (4)].str),(yyvsp[(3) - (4)].str),(yyvsp[(4) - (4)].str)); add_feature("GRANT"); }
    break;

  case 167:

/* Line 1464 of yacc.c  */
#line 1498 "sql.yacc"
    {SPRINTF4((yyval.str),"%s %s %s %s ",(yyvsp[(1) - (4)].str),(yyvsp[(2) - (4)].str),(yyvsp[(3) - (4)].str),(yyvsp[(4) - (4)].str));  add_feature("REVOKE"); }
    break;

  case 171:

/* Line 1464 of yacc.c  */
#line 1508 "sql.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 172:

/* Line 1464 of yacc.c  */
#line 1509 "sql.yacc"
    {SPRINTF1((yyval.str)," %s ",(yyvsp[(1) - (1)].str));}
    break;

  case 173:

/* Line 1464 of yacc.c  */
#line 1510 "sql.yacc"
    {SPRINTF2((yyval.str)," %s %s",(yyvsp[(1) - (2)].str),(yyvsp[(2) - (2)].str));}
    break;

  case 174:

/* Line 1464 of yacc.c  */
#line 1514 "sql.yacc"
    {SPRINTF1((yyval.str)," %s ",(yyvsp[(1) - (1)].str));}
    break;

  case 175:

/* Line 1464 of yacc.c  */
#line 1515 "sql.yacc"
    {SPRINTF1((yyval.str)," %s ",(yyvsp[(1) - (1)].str));}
    break;

  case 178:

/* Line 1464 of yacc.c  */
#line 1522 "sql.yacc"
    {SPRINTF3((yyval.str)," %s %s %s",(yyvsp[(1) - (3)].str),(yyvsp[(2) - (3)].str),(yyvsp[(3) - (3)].str));}
    break;

  case 179:

/* Line 1464 of yacc.c  */
#line 1525 "sql.yacc"
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
#line 1534 "sql.yacc"
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
#line 1545 "sql.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 186:

/* Line 1464 of yacc.c  */
#line 1547 "sql.yacc"
    {SPRINTF3((yyval.str)," %s %s %s",(yyvsp[(1) - (3)].str),(yyvsp[(2) - (3)].str),(yyvsp[(3) - (3)].str));}
    break;

  case 188:

/* Line 1464 of yacc.c  */
#line 1553 "sql.yacc"
    {SPRINTF3((yyval.str)," %s %s %s",(yyvsp[(1) - (3)].str),(yyvsp[(2) - (3)].str),(yyvsp[(3) - (3)].str));}
    break;

  case 190:

/* Line 1464 of yacc.c  */
#line 1559 "sql.yacc"
    {SPRINTF3((yyval.str)," %s %s %s",(yyvsp[(1) - (3)].str),(yyvsp[(2) - (3)].str),(yyvsp[(3) - (3)].str));}
    break;

  case 193:

/* Line 1464 of yacc.c  */
#line 1569 "sql.yacc"
    {
		add_feature("CREATE_VIEW_AS_SELECT");
		(yyval.sql_string)=make_sql_string_and_free(acl_strdup((yyvsp[(1) - (6)].str)),kw_space,acl_strdup((yyvsp[(2) - (6)].str)),kw_space,acl_strdup((yyvsp[(3) - (6)].str)),kw_space,acl_strdup((yyvsp[(4) - (6)].str)),kw_space,(yyvsp[(5) - (6)].sql_string),kw_space,acl_strdup((yyvsp[(6) - (6)].str)),NULL);
	
}
    break;

  case 194:

/* Line 1464 of yacc.c  */
#line 1576 "sql.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 195:

/* Line 1464 of yacc.c  */
#line 1578 "sql.yacc"
    {SPRINTF3((yyval.str)," %s %s %s",(yyvsp[(1) - (3)].str),(yyvsp[(2) - (3)].str),(yyvsp[(3) - (3)].str));}
    break;

  case 197:

/* Line 1464 of yacc.c  */
#line 1584 "sql.yacc"
    {SPRINTF3((yyval.str)," %s %s %s",(yyvsp[(1) - (3)].str),(yyvsp[(2) - (3)].str),(yyvsp[(3) - (3)].str));}
    break;

  case 198:

/* Line 1464 of yacc.c  */
#line 1587 "sql.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 199:

/* Line 1464 of yacc.c  */
#line 1588 "sql.yacc"
    {
		add_feature("CREATE_VIEW_SELECT_WITH_CHECK");
	}
    break;

  case 200:

/* Line 1464 of yacc.c  */
#line 1595 "sql.yacc"
    {
		(yyval.sql_string)=make_sql_string_and_free(strdup("CHECK ("),(yyvsp[(3) - (4)].sql_string),kw_cb,NULL);
		add_feature("DDL_CHECK");
	}
    break;

  case 201:

/* Line 1464 of yacc.c  */
#line 1604 "sql.yacc"
    {SPRINTF5((yyval.str)," %s %s %s %s %s",(yyvsp[(1) - (5)].str),(yyvsp[(2) - (5)].str),(yyvsp[(3) - (5)].str),(yyvsp[(4) - (5)].str),(yyvsp[(5) - (5)].str));
	add_feature("DDL_FOREIGN_KEY");
}
    break;

  case 202:

/* Line 1464 of yacc.c  */
#line 1611 "sql.yacc"
    {SPRINTF2((yyval.str)," %s %s",(yyvsp[(1) - (2)].str),(yyvsp[(2) - (2)].str));
add_feature("DDL_REFERENCES");
}
    break;

  case 205:

/* Line 1464 of yacc.c  */
#line 1623 "sql.yacc"
    {SPRINTF4((yyval.str)," %s %s %s %s",(yyvsp[(1) - (4)].str),(yyvsp[(2) - (4)].str),(yyvsp[(3) - (4)].str),(yyvsp[(4) - (4)].str));}
    break;

  case 207:

/* Line 1464 of yacc.c  */
#line 1629 "sql.yacc"
    {SPRINTF3((yyval.str)," %s %s %s",(yyvsp[(1) - (3)].str),(yyvsp[(2) - (3)].str),(yyvsp[(3) - (3)].str));}
    break;

  case 208:

/* Line 1464 of yacc.c  */
#line 1634 "sql.yacc"
    {
		SPRINTF3((yyval.str)," UNIQUE %s %s %s",(yyvsp[(2) - (4)].str),(yyvsp[(3) - (4)].str),(yyvsp[(4) - (4)].str));
add_feature("DDL_UNIQUE");
	}
    break;

  case 209:

/* Line 1464 of yacc.c  */
#line 1638 "sql.yacc"
    {
		ansi_violation("Use UNIQUE not DISTINCT",0);
		SPRINTF3((yyval.str)," UNIQUE %s %s %s",(yyvsp[(2) - (4)].str),(yyvsp[(3) - (4)].str),(yyvsp[(4) - (4)].str));
add_feature("DDL_DISTINCT");
	}
    break;

  case 210:

/* Line 1464 of yacc.c  */
#line 1644 "sql.yacc"
    {SPRINTF4((yyval.str)," %s %s %s %s",(yyvsp[(1) - (4)].str),(yyvsp[(2) - (4)].str),(yyvsp[(3) - (4)].str),(yyvsp[(4) - (4)].str));
add_feature("DDL_PRIMARY_KEY");
}
    break;

  case 212:

/* Line 1464 of yacc.c  */
#line 1652 "sql.yacc"
    {SPRINTF3((yyval.str)," %s %s %s",(yyvsp[(1) - (3)].str),(yyvsp[(2) - (3)].str),(yyvsp[(3) - (3)].str));}
    break;

  case 213:

/* Line 1464 of yacc.c  */
#line 1657 "sql.yacc"
    {
		(yyval.sql_string)=acl_strdup((yyvsp[(1) - (1)].str));
	}
    break;

  case 214:

/* Line 1464 of yacc.c  */
#line 1660 "sql.yacc"
    {
		(yyval.sql_string)=acl_strdup((yyvsp[(1) - (1)].str));
	}
    break;

  case 215:

/* Line 1464 of yacc.c  */
#line 1663 "sql.yacc"
    {
		(yyval.sql_string)=(yyvsp[(1) - (1)].sql_string);
	}
    break;

  case 216:

/* Line 1464 of yacc.c  */
#line 1670 "sql.yacc"
    {SPRINTF2((yyval.str)," %s %s",(yyvsp[(1) - (2)].str),(yyvsp[(2) - (2)].str)); add_feature("DDL_DEFAULT_VALUE"); }
    break;

  case 217:

/* Line 1464 of yacc.c  */
#line 1671 "sql.yacc"
    {SPRINTF1((yyval.str)," DEFAULT %s", A4GLSQLCV_get_sqlconst("USER")); add_feature("DDL_DEFAULT_VALUE"); }
    break;

  case 218:

/* Line 1464 of yacc.c  */
#line 1672 "sql.yacc"
    {SPRINTF1((yyval.str)," DEFAULT %s", A4GLSQLCV_get_sqlconst("TODAY")); add_feature("DDL_DEFAULT_VALUE"); }
    break;

  case 219:

/* Line 1464 of yacc.c  */
#line 1673 "sql.yacc"
    { SPRINTF1((yyval.str)," %s",(yyvsp[(1) - (1)].str)); add_feature("DDL_DEFAULT_VALUE"); }
    break;

  case 220:

/* Line 1464 of yacc.c  */
#line 1679 "sql.yacc"
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
#line 1702 "sql.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 223:

/* Line 1464 of yacc.c  */
#line 1706 "sql.yacc"
    {
		(yyval.sql_string)=acl_strdup("");
	}
    break;

  case 224:

/* Line 1464 of yacc.c  */
#line 1708 "sql.yacc"
    {
		(yyval.sql_string)=(yyvsp[(1) - (1)].sql_string);
	}
    break;

  case 225:

/* Line 1464 of yacc.c  */
#line 1715 "sql.yacc"
    {
		(yyval.sql_string)=(yyvsp[(1) - (1)].sql_string);
	}
    break;

  case 226:

/* Line 1464 of yacc.c  */
#line 1718 "sql.yacc"
    {
		(yyval.sql_string)=make_sql_string_and_free((yyvsp[(1) - (2)].sql_string),kw_space,(yyvsp[(2) - (2)].sql_string),NULL);
	}
    break;

  case 227:

/* Line 1464 of yacc.c  */
#line 1724 "sql.yacc"
    {
		(yyval.sql_string)=make_sql_string_and_free((yyvsp[(1) - (2)].sql_string),acl_strdup((yyvsp[(2) - (2)].str)),NULL);
	}
    break;

  case 228:

/* Line 1464 of yacc.c  */
#line 1732 "sql.yacc"
    {
		SPRINTF1((yyval.str)," %s ",(yyvsp[(1) - (1)].str));
		(yyval.sql_string)=acl_strdup((yyval.str));
		add_feature("DDL_NOT_NULL");
	}
    break;

  case 229:

/* Line 1464 of yacc.c  */
#line 1737 "sql.yacc"
    {
		SPRINTF0((yyval.str)," NOT NULL UNIQUE ");
		(yyval.sql_string)=acl_strdup((yyval.str));
		add_feature("DDL_NOT_NULL");
		add_feature("DDL_UNIQUE");
	}
    break;

  case 230:

/* Line 1464 of yacc.c  */
#line 1743 "sql.yacc"
    {
		SPRINTF0((yyval.str)," UNIQUE ");
		(yyval.sql_string)=acl_strdup((yyval.str));
		add_feature("DDL_UNIQUE");
	}
    break;

  case 231:

/* Line 1464 of yacc.c  */
#line 1748 "sql.yacc"
    {
		ansi_violation("Use UNIQUE not DISTINCT",0);
		SPRINTF0((yyval.str)," UNIQUE ");
		(yyval.sql_string)=acl_strdup((yyval.str));
		add_feature("DDL_DISTINCT");
	}
    break;

  case 232:

/* Line 1464 of yacc.c  */
#line 1754 "sql.yacc"
    {
		(yyval.sql_string)=acl_strdup((yyvsp[(1) - (1)].str));
	}
    break;

  case 233:

/* Line 1464 of yacc.c  */
#line 1757 "sql.yacc"
    {
		(yyval.sql_string)=make_sql_string_and_free(acl_strdup("CHECK ("),(yyvsp[(3) - (4)].sql_string),kw_cb,NULL);
		add_feature("DDL_CHECK");
		
	}
    break;

  case 234:

/* Line 1464 of yacc.c  */
#line 1762 "sql.yacc"
    {
		(yyval.sql_string)=make_sql_string_and_free(acl_strdup(" PRIMARY KEY "),NULL);
		add_feature("DDL_PRIMARY_KEY");
	}
    break;

  case 235:

/* Line 1464 of yacc.c  */
#line 1771 "sql.yacc"
    {
		add_feature("CREATE_SCHEMA");

(yyval.sql_string)=make_sql_string_and_free(acl_strdup((yyvsp[(1) - (3)].str)),kw_space,acl_strdup((yyvsp[(2) - (3)].str)),kw_space,acl_strdup((yyvsp[(3) - (3)].str)),NULL);
}
    break;

  case 236:

/* Line 1464 of yacc.c  */
#line 1780 "sql.yacc"
    {SPRINTF1((yyval.str)," %s",(yyvsp[(1) - (1)].str));}
    break;

  case 239:

/* Line 1464 of yacc.c  */
#line 1789 "sql.yacc"
    {
		(yyval.sql_string)=make_sql_string_and_free((yyvsp[(1) - (2)].sql_string),kw_space,(yyvsp[(2) - (2)].sql_string),NULL);
	}
    break;

  case 240:

/* Line 1464 of yacc.c  */
#line 1795 "sql.yacc"
    {
		(yyval.sql_string)=(yyvsp[(1) - (1)].sql_string);
	}
    break;

  case 241:

/* Line 1464 of yacc.c  */
#line 1798 "sql.yacc"
    {
		(yyval.sql_string)=acl_strdup((yyvsp[(1) - (1)].str));
	}
    break;

  case 242:

/* Line 1464 of yacc.c  */
#line 1809 "sql.yacc"
    {
		 add_feature("HAVING"); 
		(yyval.s_select_list_item)=(yyvsp[(2) - (2)].s_select_list_item);
	}
    break;

  case 243:

/* Line 1464 of yacc.c  */
#line 1818 "sql.yacc"
    {
		 (yyval.s_select_list_item)=(yyvsp[(2) - (2)].s_select_list_item);
	}
    break;

  case 244:

/* Line 1464 of yacc.c  */
#line 1825 "sql.yacc"
    {
		(yyval.u_table)=(yyvsp[(2) - (2)].u_table);
	}
    break;

  case 245:

/* Line 1464 of yacc.c  */
#line 1831 "sql.yacc"
    {(yyval.u_table)=(yyvsp[(1) - (1)].u_table);}
    break;

  case 246:

/* Line 1464 of yacc.c  */
#line 1832 "sql.yacc"
    {
		(yyval.u_table)=A4GLSQLPARSE_append_tablename((yyvsp[(1) - (3)].u_table),(yyvsp[(3) - (3)].u_table),E_OUTER_NONE,NULL);
	}
    break;

  case 247:

/* Line 1464 of yacc.c  */
#line 1835 "sql.yacc"
    {
		(yyval.u_table)=A4GLSQLPARSE_append_tablename((yyvsp[(1) - (4)].u_table),(yyvsp[(4) - (4)].u_table),E_OUTER_NORMAL,NULL);
		A4GL_warn("OUTER join *may* not be portable to non-informix database");
		add_feature("SELECT_OUTER");
	}
    break;

  case 248:

/* Line 1464 of yacc.c  */
#line 1840 "sql.yacc"
    {
		(yyval.u_table)=A4GLSQLPARSE_append_tablename((yyvsp[(1) - (6)].u_table),(yyvsp[(5) - (6)].u_table),E_OUTER_NORMAL,NULL);
		A4GL_warn("OUTER join *may* not be portable to non-informix database");
		add_feature("SELECT_OUTER");
	}
    break;

  case 249:

/* Line 1464 of yacc.c  */
#line 1851 "sql.yacc"
    {
		(yyval.u_table)=A4GLSQLPARSE_append_tablename((yyvsp[(1) - (5)].u_table),(yyvsp[(3) - (5)].u_table),E_OUTER_LEFT_OUTER, (yyvsp[(5) - (5)].s_select_list_item));
		add_feature("SELECT_OUTER");
	}
    break;

  case 250:

/* Line 1464 of yacc.c  */
#line 1855 "sql.yacc"
    {
		(yyval.u_table)=A4GLSQLPARSE_append_tablename((yyvsp[(1) - (5)].u_table),(yyvsp[(3) - (5)].u_table),E_INNER, (yyvsp[(5) - (5)].s_select_list_item));
		add_feature("SELECT_INNER");
	}
    break;

  case 252:

/* Line 1464 of yacc.c  */
#line 1863 "sql.yacc"
    {(yyval.u_table)=(yyvsp[(2) - (3)].u_table);}
    break;

  case 253:

/* Line 1464 of yacc.c  */
#line 1867 "sql.yacc"
    { 
			//A4GL_add_crud("SELECT",$<str>1);
			(yyval.u_table)=A4GLSQLPARSE_new_tablename((yyvsp[(1) - (1)].str),NULL);
	}
    break;

  case 254:

/* Line 1464 of yacc.c  */
#line 1871 "sql.yacc"
    { 
			//A4GL_add_crud("SELECT",$<str>1);
			(yyval.u_table)=A4GLSQLPARSE_new_tablename((yyvsp[(1) - (2)].str),(yyvsp[(2) - (2)].str));
	}
    break;

  case 255:

/* Line 1464 of yacc.c  */
#line 1875 "sql.yacc"
    { 
			//A4GL_add_crud("SELECT",$<str>1);
			(yyval.u_table)=A4GLSQLPARSE_new_tablename((yyvsp[(1) - (3)].str),(yyvsp[(3) - (3)].str));
	}
    break;

  case 256:

/* Line 1464 of yacc.c  */
#line 1882 "sql.yacc"
    {
			/* No from or where etc.. */
			/* eg.. select user ; */
			(yyval.s_select)=new_empty_select();
		}
    break;

  case 257:

/* Line 1464 of yacc.c  */
#line 1887 "sql.yacc"
    {
		(yyval.s_select)=(yyvsp[(2) - (2)].s_select);
		(yyval.s_select)->first=(yyvsp[(1) - (2)].u_table);
			A4GL_set_associated_mem( (yyval.s_select), (yyval.s_select)->first);
}
    break;

  case 258:

/* Line 1464 of yacc.c  */
#line 1895 "sql.yacc"
    {
		(yyval.s_select)=(yyvsp[(1) - (1)].s_select);
	}
    break;

  case 259:

/* Line 1464 of yacc.c  */
#line 1898 "sql.yacc"
    {
		(yyval.s_select)=(yyvsp[(2) - (2)].s_select);
		(yyval.s_select)->where_clause=(yyvsp[(1) - (2)].s_select_list_item);
	}
    break;

  case 260:

/* Line 1464 of yacc.c  */
#line 1904 "sql.yacc"
    {
		(yyval.s_select)=new_empty_select();
	}
    break;

  case 261:

/* Line 1464 of yacc.c  */
#line 1907 "sql.yacc"
    {
		(yyval.s_select)=new_empty_select();
		(yyval.s_select)->group_by=(yyvsp[(1) - (1)].s_select_list_item_list);
		(yyval.s_select)->having=0;
	}
    break;

  case 262:

/* Line 1464 of yacc.c  */
#line 1912 "sql.yacc"
    {
		(yyval.s_select)=new_empty_select();
		(yyval.s_select)->group_by=(yyvsp[(1) - (2)].s_select_list_item_list);
		(yyval.s_select)->having=(yyvsp[(2) - (2)].s_select_list_item);
	}
    break;

  case 263:

/* Line 1464 of yacc.c  */
#line 1917 "sql.yacc"
    {
		(yyval.s_select)=new_empty_select();
		(yyval.s_select)->group_by=0;
		(yyval.s_select)->having=(yyvsp[(1) - (1)].s_select_list_item);

	}
    break;

  case 264:

/* Line 1464 of yacc.c  */
#line 1930 "sql.yacc"
    {
		(yyval.s_select_list_item)=(yyvsp[(1) - (1)].s_select_list_item);
	}
    break;

  case 265:

/* Line 1464 of yacc.c  */
#line 1933 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_op_expr((yyvsp[(1) - (3)].s_select_list_item),(yyvsp[(3) - (3)].s_select_list_item)," OR ");
	}
    break;

  case 266:

/* Line 1464 of yacc.c  */
#line 1939 "sql.yacc"
    {
		(yyval.s_select_list_item)=(yyvsp[(1) - (1)].s_select_list_item);
	}
    break;

  case 267:

/* Line 1464 of yacc.c  */
#line 1942 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_op_expr((yyvsp[(1) - (3)].s_select_list_item),(yyvsp[(3) - (3)].s_select_list_item)," AND ");
	}
    break;

  case 268:

/* Line 1464 of yacc.c  */
#line 1948 "sql.yacc"
    {
		(yyval.s_select_list_item)=(yyvsp[(1) - (1)].s_select_list_item);
	}
    break;

  case 269:

/* Line 1464 of yacc.c  */
#line 1951 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_simple_expr(E_SLI_NOT,(yyvsp[(2) - (2)].s_select_list_item));
	}
    break;

  case 270:

/* Line 1464 of yacc.c  */
#line 1957 "sql.yacc"
    {
		(yyval.s_select_list_item)=(yyvsp[(1) - (1)].s_select_list_item);
	}
    break;

  case 271:

/* Line 1464 of yacc.c  */
#line 1960 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_simple_expr(E_SLI_BRACKET_EXPR,(yyvsp[(2) - (3)].s_select_list_item));
	}
    break;

  case 272:

/* Line 1464 of yacc.c  */
#line 1967 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_sq(E_SQE_EXISTS, (yyvsp[(2) - (2)].s_select_list_item));
		add_feature("WHERE_EXISTS");
	}
    break;

  case 273:

/* Line 1464 of yacc.c  */
#line 1971 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_sq(E_SQE_NOT_EXISTS, (yyvsp[(2) - (2)].s_select_list_item));
		add_feature("WHERE_EXISTS");
	}
    break;

  case 274:

/* Line 1464 of yacc.c  */
#line 1982 "sql.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 275:

/* Line 1464 of yacc.c  */
#line 1982 "sql.yacc"
    {SPRINTF1((yyval.str)," ESCAPE %s",(yyvsp[(2) - (2)].str));add_feature("WHERE_MATCHES_ESCAPE");}
    break;

  case 276:

/* Line 1464 of yacc.c  */
#line 1983 "sql.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 277:

/* Line 1464 of yacc.c  */
#line 1983 "sql.yacc"
    {SPRINTF1((yyval.str)," ESCAPE %s",(yyvsp[(2) - (2)].str));add_feature("WHERE_ILIKE_ESCAPE");}
    break;

  case 278:

/* Line 1464 of yacc.c  */
#line 1984 "sql.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 279:

/* Line 1464 of yacc.c  */
#line 1984 "sql.yacc"
    {SPRINTF1((yyval.str)," ESCAPE %s",(yyvsp[(2) - (2)].str));add_feature("WHERE_LIKE_ESCAPE");}
    break;

  case 280:

/* Line 1464 of yacc.c  */
#line 1987 "sql.yacc"
    {
		 (yyval.s_select_list_item)=(yyvsp[(1) - (1)].s_select_list_item);
	}
    break;

  case 282:

/* Line 1464 of yacc.c  */
#line 1997 "sql.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 283:

/* Line 1464 of yacc.c  */
#line 1998 "sql.yacc"
    {strcpy((yyval.str)," NOT ");}
    break;

  case 284:

/* Line 1464 of yacc.c  */
#line 2003 "sql.yacc"
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
#line 2012 "sql.yacc"
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
#line 2020 "sql.yacc"
    { 
			(yyval.s_select_list_item)=new_select_list_item_op_expr((yyvsp[(1) - (3)].s_select_list_item),(yyvsp[(3) - (3)].s_select_list_item),(yyvsp[(2) - (3)].str));
	}
    break;

  case 287:

/* Line 1464 of yacc.c  */
#line 2023 "sql.yacc"
    { 
			(yyval.s_select_list_item)=new_select_list_item_op_expr((yyvsp[(1) - (3)].s_select_list_item),(yyvsp[(3) - (3)].s_select_list_item),"=");
	}
    break;

  case 288:

/* Line 1464 of yacc.c  */
#line 2026 "sql.yacc"
    { 
			FPRINTF(stderr,"Warning: Corrected =NULL to IS NULL line %d\n",yylineno);
			(yyval.s_select_list_item)=new_select_list_item_simple_expr(E_SLI_ISNULL,(yyvsp[(1) - (3)].s_select_list_item));
	}
    break;

  case 289:

/* Line 1464 of yacc.c  */
#line 2030 "sql.yacc"
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
#line 2037 "sql.yacc"
    { 
			(yyval.s_select_list_item)=new_select_list_item_regex(E_SLI_REGEX_LIKE,(yyvsp[(1) - (4)].s_select_list_item),(yyvsp[(3) - (4)].s_select_list_item),(yyvsp[(4) - (4)].str));
	}
    break;

  case 291:

/* Line 1464 of yacc.c  */
#line 2040 "sql.yacc"
    { 
			(yyval.s_select_list_item)=new_select_list_item_regex(E_SLI_REGEX_NOT_LIKE,(yyvsp[(1) - (4)].s_select_list_item),(yyvsp[(3) - (4)].s_select_list_item),(yyvsp[(4) - (4)].str));

	}
    break;

  case 292:

/* Line 1464 of yacc.c  */
#line 2044 "sql.yacc"
    { 
			(yyval.s_select_list_item)=new_select_list_item_regex(E_SLI_REGEX_ILIKE,(yyvsp[(1) - (4)].s_select_list_item),(yyvsp[(3) - (4)].s_select_list_item),(yyvsp[(4) - (4)].str));
	}
    break;

  case 293:

/* Line 1464 of yacc.c  */
#line 2047 "sql.yacc"
    { 
			(yyval.s_select_list_item)=new_select_list_item_regex(E_SLI_REGEX_NOT_ILIKE,(yyvsp[(1) - (4)].s_select_list_item),(yyvsp[(3) - (4)].s_select_list_item),(yyvsp[(4) - (4)].str));
	}
    break;

  case 294:

/* Line 1464 of yacc.c  */
#line 2050 "sql.yacc"
    { 
			(yyval.s_select_list_item)=new_select_list_item_regex(E_SLI_REGEX_MATCHES,(yyvsp[(1) - (4)].s_select_list_item),(yyvsp[(3) - (4)].s_select_list_item),(yyvsp[(4) - (4)].str));
	}
    break;

  case 295:

/* Line 1464 of yacc.c  */
#line 2053 "sql.yacc"
    { 
			(yyval.s_select_list_item)=new_select_list_item_regex(E_SLI_REGEX_NOT_MATCHES,(yyvsp[(1) - (4)].s_select_list_item),(yyvsp[(3) - (4)].s_select_list_item),(yyvsp[(4) - (4)].str));
	}
    break;

  case 296:

/* Line 1464 of yacc.c  */
#line 2059 "sql.yacc"
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
#line 2066 "sql.yacc"
    {
			strcpy((yyval.str)," < ");
	}
    break;

  case 298:

/* Line 1464 of yacc.c  */
#line 2069 "sql.yacc"
    {
			strcpy((yyval.str)," > ");
	}
    break;

  case 299:

/* Line 1464 of yacc.c  */
#line 2072 "sql.yacc"
    {
			strcpy((yyval.str)," ~ ");
	}
    break;

  case 300:

/* Line 1464 of yacc.c  */
#line 2075 "sql.yacc"
    {strcpy((yyval.str)," <= ");}
    break;

  case 301:

/* Line 1464 of yacc.c  */
#line 2076 "sql.yacc"
    {strcpy((yyval.str)," >= ");}
    break;

  case 302:

/* Line 1464 of yacc.c  */
#line 2081 "sql.yacc"
    {
		(yyval.s_select_list_item)=(yyvsp[(1) - (1)].s_select_list_item);
	}
    break;

  case 303:

/* Line 1464 of yacc.c  */
#line 2084 "sql.yacc"
    {
		(yyval.s_select_list_item)=(yyvsp[(1) - (1)].s_select_list_item);
	}
    break;

  case 304:

/* Line 1464 of yacc.c  */
#line 2087 "sql.yacc"
    {
		(yyval.s_select_list_item)=(yyvsp[(1) - (1)].s_select_list_item);
	}
    break;

  case 305:

/* Line 1464 of yacc.c  */
#line 2090 "sql.yacc"
    {
                 (yyval.s_select_list_item)=(yyvsp[(1) - (1)].s_select_list_item);
        }
    break;

  case 306:

/* Line 1464 of yacc.c  */
#line 2097 "sql.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 307:

/* Line 1464 of yacc.c  */
#line 2098 "sql.yacc"
    {strcpy((yyval.str)," ALL "); add_feature("AGG_ALL");}
    break;

  case 308:

/* Line 1464 of yacc.c  */
#line 2099 "sql.yacc"
    {
		strcpy((yyval.str)," DISTINCT ");
		add_feature("AGG_DISTINCT");
	}
    break;

  case 309:

/* Line 1464 of yacc.c  */
#line 2103 "sql.yacc"
    {
		ansi_violation("Use DISTINCT not UNIQUE",0);
		strcpy((yyval.str)," DISTINCT ");
		add_feature("AGG_DISTINCT");
	}
    break;

  case 310:

/* Line 1464 of yacc.c  */
#line 2110 "sql.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 311:

/* Line 1464 of yacc.c  */
#line 2111 "sql.yacc"
    {strcpy((yyval.str)," ALL "); add_feature("UNION_ALL");}
    break;

  case 312:

/* Line 1464 of yacc.c  */
#line 2112 "sql.yacc"
    {
		strcpy((yyval.str)," DISTINCT ");
		add_feature("UNION_DISTINCT");
	}
    break;

  case 313:

/* Line 1464 of yacc.c  */
#line 2116 "sql.yacc"
    {
		ansi_violation("Use DISTINCT not UNIQUE",0);
		add_feature("UNION_DISTINCT");
		strcpy((yyval.str)," DISTINCT ");
	}
    break;

  case 314:

/* Line 1464 of yacc.c  */
#line 2130 "sql.yacc"
    {
		strcpy((yyval.str),A4GLSQLCV_dtype_alias((yyvsp[(1) - (1)].str)));
	}
    break;

  case 319:

/* Line 1464 of yacc.c  */
#line 2145 "sql.yacc"
    {SPRINTF4((yyval.str)," %s %s%s%s",(yyvsp[(1) - (4)].str),(yyvsp[(2) - (4)].str),(yyvsp[(3) - (4)].str),(yyvsp[(4) - (4)].str));}
    break;

  case 320:

/* Line 1464 of yacc.c  */
#line 2149 "sql.yacc"
    {strcpy((yyval.str),"SERIAL"); add_feature("DDL_SERIAL"); }
    break;

  case 321:

/* Line 1464 of yacc.c  */
#line 2150 "sql.yacc"
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
#line 2159 "sql.yacc"
    {strcpy((yyval.str),"SERIAL8"); add_feature("DDL_SERIAL8"); }
    break;

  case 323:

/* Line 1464 of yacc.c  */
#line 2161 "sql.yacc"
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
#line 2170 "sql.yacc"
    {
 			add_feature("DDL_DECIMAL");
	}
    break;

  case 325:

/* Line 1464 of yacc.c  */
#line 2173 "sql.yacc"
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
#line 2181 "sql.yacc"
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
#line 2191 "sql.yacc"
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
#line 2199 "sql.yacc"
    {strcpy((yyval.str),"DATE");
 			add_feature("DDL_DATE"); }
    break;

  case 329:

/* Line 1464 of yacc.c  */
#line 2201 "sql.yacc"
    {strcpy((yyval.str),"INTEGER");}
    break;

  case 330:

/* Line 1464 of yacc.c  */
#line 2202 "sql.yacc"
    {strcpy((yyval.str),"SMALLINT");}
    break;

  case 331:

/* Line 1464 of yacc.c  */
#line 2203 "sql.yacc"
    {strcpy((yyval.str),"NCHAR"); add_feature("DDL_NCHAR");}
    break;

  case 332:

/* Line 1464 of yacc.c  */
#line 2204 "sql.yacc"
    {SPRINTF1((yyval.str),"NCHAR(%s)",(yyvsp[(3) - (4)].str)); add_feature("DDL_NCHAR");}
    break;

  case 333:

/* Line 1464 of yacc.c  */
#line 2205 "sql.yacc"
    {add_feature("DDL_NVARCHAR");}
    break;

  case 334:

/* Line 1464 of yacc.c  */
#line 2206 "sql.yacc"
    {SPRINTF1((yyval.str),"NVARCHAR(%s)",(yyvsp[(3) - (4)].str)); add_feature("DDL_NVARCHAR");}
    break;

  case 335:

/* Line 1464 of yacc.c  */
#line 2207 "sql.yacc"
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
#line 2215 "sql.yacc"
    {SPRINTF2((yyval.str),"DATETIME %s TO %s",(yyvsp[(2) - (4)].str),(yyvsp[(4) - (4)].str)); add_feature("DDL_DATETIME");}
    break;

  case 337:

/* Line 1464 of yacc.c  */
#line 2216 "sql.yacc"
    {add_feature("DDL_DATETIME");}
    break;

  case 338:

/* Line 1464 of yacc.c  */
#line 2217 "sql.yacc"
    {SPRINTF2((yyval.str),"INTERVAL %s TO %s",(yyvsp[(2) - (4)].str),(yyvsp[(4) - (4)].str)); add_feature("DDL_INTERVAL");}
    break;

  case 339:

/* Line 1464 of yacc.c  */
#line 2218 "sql.yacc"
    {strcpy((yyval.str),(yyvsp[(1) - (1)].str));}
    break;

  case 340:

/* Line 1464 of yacc.c  */
#line 2219 "sql.yacc"
    {add_feature("DDL_INTERVAL");}
    break;

  case 341:

/* Line 1464 of yacc.c  */
#line 2220 "sql.yacc"
    {SPRINTF3((yyval.str),"INTERVAL %s(%s) TO %s",(yyvsp[(2) - (7)].str),(yyvsp[(4) - (7)].str),(yyvsp[(7) - (7)].str)); add_feature("DDL_INTERVAL");}
    break;

  case 342:

/* Line 1464 of yacc.c  */
#line 2221 "sql.yacc"
    {add_feature("DDL_TEXT");}
    break;

  case 343:

/* Line 1464 of yacc.c  */
#line 2222 "sql.yacc"
    {add_feature("DDL_BYTE");}
    break;

  case 344:

/* Line 1464 of yacc.c  */
#line 2223 "sql.yacc"
    {add_feature("DDL_VARCHAR");}
    break;

  case 345:

/* Line 1464 of yacc.c  */
#line 2224 "sql.yacc"
    {SPRINTF1((yyval.str),"VARCHAR(%s)",(yyvsp[(3) - (4)].str));add_feature("DDL_VARCHAR");}
    break;

  case 346:

/* Line 1464 of yacc.c  */
#line 2225 "sql.yacc"
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
#line 2235 "sql.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 348:

/* Line 1464 of yacc.c  */
#line 2236 "sql.yacc"
    {
		SPRINTF1((yyval.str),",%s",(yyvsp[(2) - (2)].str));
}
    break;

  case 349:

/* Line 1464 of yacc.c  */
#line 2243 "sql.yacc"
    {SPRINTF4((yyval.str)," %s %s %s %s",(yyvsp[(1) - (4)].str),(yyvsp[(2) - (4)].str),(yyvsp[(3) - (4)].str),(yyvsp[(4) - (4)].str));}
    break;

  case 353:

/* Line 1464 of yacc.c  */
#line 2247 "sql.yacc"
    {add_feature("DDL_DOUBLE_PRECISION"); SPRINTF1((yyval.str)," %s",(yyvsp[(1) - (1)].str));}
    break;

  case 359:

/* Line 1464 of yacc.c  */
#line 2272 "sql.yacc"
    {(yyval.int_list.i0)=0;}
    break;

  case 360:

/* Line 1464 of yacc.c  */
#line 2273 "sql.yacc"
    {
		(yyval.int_list.i0)=1;
		(yyval.int_list.i1)=atoi((yyvsp[(2) - (3)].str));
	}
    break;

  case 361:

/* Line 1464 of yacc.c  */
#line 2277 "sql.yacc"
    {
		(yyval.int_list.i0)=2;
		(yyval.int_list.i1)=atoi((yyvsp[(2) - (5)].str));
		(yyval.int_list.i2)=atoi((yyvsp[(4) - (5)].str));
	}
    break;

  case 362:

/* Line 1464 of yacc.c  */
#line 2285 "sql.yacc"
    {
		strcpy((yyval.str),(yyvsp[(1) - (1)].str));
	}
    break;

  case 363:

/* Line 1464 of yacc.c  */
#line 2288 "sql.yacc"
    {
		strcpy((yyval.str),(yyvsp[(2) - (2)].str));
	}
    break;

  case 364:

/* Line 1464 of yacc.c  */
#line 2295 "sql.yacc"
    {
		(yyval.s_select_list_item)= (yyvsp[(1) - (1)].s_select_list_item);
	}
    break;

  case 365:

/* Line 1464 of yacc.c  */
#line 2298 "sql.yacc"
    {
		(yyval.s_select_list_item)= (yyvsp[(2) - (2)].s_select_list_item);
	}
    break;

  case 366:

/* Line 1464 of yacc.c  */
#line 2308 "sql.yacc"
    { 
		(yyval.s_select_list_item)=new_select_list_item_col(0,(yyvsp[(1) - (2)].str),&(yyvsp[(2) - (2)].int_list));
	}
    break;

  case 367:

/* Line 1464 of yacc.c  */
#line 2311 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_col((yyvsp[(1) - (4)].str),(yyvsp[(3) - (4)].str),&(yyvsp[(4) - (4)].int_list));
	}
    break;

  case 368:

/* Line 1464 of yacc.c  */
#line 2314 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_col((yyvsp[(1) - (3)].str),"*",0);
	}
    break;

  case 369:

/* Line 1464 of yacc.c  */
#line 2317 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_col(0,"rowid",0);
	}
    break;

  case 370:

/* Line 1464 of yacc.c  */
#line 2324 "sql.yacc"
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
#line 2331 "sql.yacc"
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
#line 2339 "sql.yacc"
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
#line 2348 "sql.yacc"
    {
		SPRINTF1((yyval.str),"%s",A4GLSQLCV_check_colname((yyvsp[(1) - (3)].str),"*"));
		ADDMAP("Use Column",(yyval.str));
	}
    break;

  case 375:

/* Line 1464 of yacc.c  */
#line 2359 "sql.yacc"
    { strcpy((yyval.str),(yyvsp[(1) - (1)].str)); 
#ifdef DEBUG
A4GL_debug("Set $<str>$ to %s\n",(yyval.str)); 
#endif
}
    break;

  case 379:

/* Line 1464 of yacc.c  */
#line 2371 "sql.yacc"
    { strcpy((yyval.str),A4GLSQLCV_generate_current(0,0)); }
    break;

  case 380:

/* Line 1464 of yacc.c  */
#line 2372 "sql.yacc"
    {
		strcpy((yyval.str),A4GLSQLCV_generate_current((yyvsp[(1) - (3)].str),(yyvsp[(3) - (3)].str)));
	}
    break;

  case 395:

/* Line 1464 of yacc.c  */
#line 2382 "sql.yacc"
    {SPRINTF1((yyval.str),"FRACTION(%s)",(yyvsp[(3) - (4)].str));}
    break;

  case 396:

/* Line 1464 of yacc.c  */
#line 2427 "sql.yacc"
    { (yyval.sql_string)=make_sql_string_and_free(acl_strdup((yyvsp[(1) - (1)].str)), NULL);}
    break;

  case 397:

/* Line 1464 of yacc.c  */
#line 2428 "sql.yacc"
    { (yyval.sql_string)=make_sql_string_and_free(acl_strdup((yyvsp[(1) - (1)].str)), NULL);}
    break;

  case 398:

/* Line 1464 of yacc.c  */
#line 2429 "sql.yacc"
    { (yyval.sql_string)=make_sql_string_and_free(acl_strdup((yyvsp[(1) - (1)].str)), NULL);}
    break;

  case 399:

/* Line 1464 of yacc.c  */
#line 2434 "sql.yacc"
    { add_feature("RENAME_TABLE"); strcpy((yyval.str),A4GLSQLCV_rentab((yyvsp[(2) - (4)].str),(yyvsp[(4) - (4)].str))); }
    break;

  case 400:

/* Line 1464 of yacc.c  */
#line 2435 "sql.yacc"
    { add_feature("RENAME_COLUMN"); strcpy((yyval.str),A4GLSQLCV_rencol((yyvsp[(2) - (6)].str),(yyvsp[(4) - (6)].str),(yyvsp[(6) - (6)].str)) ); }
    break;

  case 403:

/* Line 1464 of yacc.c  */
#line 2443 "sql.yacc"
    {
		add_feature("UNLOCK_TABLE");
		SPRINTF2((yyval.str),"%s %s",(yyvsp[(1) - (2)].str),(yyvsp[(2) - (2)].str));
	}
    break;

  case 404:

/* Line 1464 of yacc.c  */
#line 2450 "sql.yacc"
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
#line 2461 "sql.yacc"
    { add_feature("LOCK_TABLE_SHARED");}
    break;

  case 406:

/* Line 1464 of yacc.c  */
#line 2462 "sql.yacc"
    {add_feature("LOCK_TABLE_EXCLUSIVE");}
    break;

  case 407:

/* Line 1464 of yacc.c  */
#line 2475 "sql.yacc"
    {strcpy((yyval.str),A4GLSQLCV_datetime_value((yyvsp[(1) - (1)].str)));}
    break;

  case 408:

/* Line 1464 of yacc.c  */
#line 2476 "sql.yacc"
    {strcpy((yyval.str),A4GLSQLCV_make_dtime_extend((yyvsp[(1) - (4)].str),(yyvsp[(2) - (4)].str),(yyvsp[(4) - (4)].str),0));}
    break;

  case 409:

/* Line 1464 of yacc.c  */
#line 2480 "sql.yacc"
    {strcpy((yyval.str),(yyvsp[(1) - (1)].str));}
    break;

  case 410:

/* Line 1464 of yacc.c  */
#line 2484 "sql.yacc"
    {strcpy((yyval.str),A4GLSQLCV_interval_value((yyvsp[(1) - (1)].str)));}
    break;

  case 411:

/* Line 1464 of yacc.c  */
#line 2485 "sql.yacc"
    {
			strcpy((yyval.str),A4GLSQLCV_make_ival_extend((yyvsp[(1) - (7)].str),(yyvsp[(2) - (7)].str),(yyvsp[(4) - (7)].str),(yyvsp[(7) - (7)].str),0));
		}
    break;

  case 412:

/* Line 1464 of yacc.c  */
#line 2488 "sql.yacc"
    {
		strcpy((yyval.str),A4GLSQLCV_make_ival_extend((yyvsp[(1) - (4)].str),(yyvsp[(2) - (4)].str),(char *)0, (yyvsp[(4) - (4)].str),0));
	}
    break;

  case 413:

/* Line 1464 of yacc.c  */
#line 2494 "sql.yacc"
    {SPRINTF1((yyval.str),"%s",(yyvsp[(1) - (1)].str));}
    break;

  case 414:

/* Line 1464 of yacc.c  */
#line 2498 "sql.yacc"
    {
	strcpy((yyval.str),(yyvsp[(2) - (2)].str));
}
    break;

  case 415:

/* Line 1464 of yacc.c  */
#line 2521 "sql.yacc"
    {
		(yyval.s_select_list_item_list)=(yyvsp[(3) - (3)].s_select_list_item_list);
		add_feature("ORDER_BY");
	}
    break;

  case 416:

/* Line 1464 of yacc.c  */
#line 2531 "sql.yacc"
    {
			(yyval.s_select_list_item_list)=local_new_select_list_item_list((yyvsp[(1) - (1)].s_select_list_item));
	}
    break;

  case 417:

/* Line 1464 of yacc.c  */
#line 2534 "sql.yacc"
    {
			(yyval.s_select_list_item_list)=local_add_select_list_item_list((yyvsp[(1) - (3)].s_select_list_item_list),(yyvsp[(3) - (3)].s_select_list_item));
	}
    break;

  case 418:

/* Line 1464 of yacc.c  */
#line 2540 "sql.yacc"
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
#line 2549 "sql.yacc"
    { 
		add_feature("ORDER_BY_NUMBER");
		(yyval.s_select_list_item)=new_select_list_item_literal((yyvsp[(1) - (1)].str));
	}
    break;

  case 420:

/* Line 1464 of yacc.c  */
#line 2553 "sql.yacc"
    {
		(yyval.s_select_list_item)=(yyvsp[(1) - (1)].s_select_list_item);
		(yyval.s_select_list_item)->data.type=E_SLI_COLUMN_ORDERBY;
	}
    break;

  case 421:

/* Line 1464 of yacc.c  */
#line 2560 "sql.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 422:

/* Line 1464 of yacc.c  */
#line 2562 "sql.yacc"
    {add_feature("ORDER_BY_ASC"); strcpy((yyval.str),"ASC");}
    break;

  case 423:

/* Line 1464 of yacc.c  */
#line 2564 "sql.yacc"
    {add_feature("ORDER_BY_DESC"); strcpy((yyval.str),"DESC");}
    break;

  case 424:

/* Line 1464 of yacc.c  */
#line 2568 "sql.yacc"
    {
		(yyval.s_select_list_item_list)=(yyvsp[(2) - (2)].s_select_list_item_list);
	}
    break;

  case 425:

/* Line 1464 of yacc.c  */
#line 2574 "sql.yacc"
    {
			(yyval.s_select_list_item_list)=local_new_select_list_item_list((yyvsp[(1) - (1)].s_select_list_item));
	}
    break;

  case 426:

/* Line 1464 of yacc.c  */
#line 2577 "sql.yacc"
    {
			(yyval.s_select_list_item_list)=local_add_select_list_item_list((yyvsp[(1) - (3)].s_select_list_item_list),(yyvsp[(3) - (3)].s_select_list_item));
	}
    break;

  case 427:

/* Line 1464 of yacc.c  */
#line 2583 "sql.yacc"
    { (yyval.s_select_list_item)=(yyvsp[(1) - (1)].s_select_list_item); }
    break;

  case 428:

/* Line 1464 of yacc.c  */
#line 2584 "sql.yacc"
    { (yyval.s_select_list_item)=new_select_list_item_literal((yyvsp[(1) - (1)].str)); }
    break;

  case 429:

/* Line 1464 of yacc.c  */
#line 2591 "sql.yacc"
    {
	(yyval.sql_string)=get_select_list_item(0,(yyvsp[(1) - (1)].s_select_list_item));
}
    break;

  case 430:

/* Line 1464 of yacc.c  */
#line 2604 "sql.yacc"
    {
		A4GL_set_sql_lineno(yylineno);
		(yyval.sql_string)=make_select_stmt_v2(current_upd_table, (yyvsp[(1) - (1)].s_select),"");
		map_select_stmt("SELECT",(yyvsp[(1) - (1)].s_select));
		A4GL_free_select_stmt((yyvsp[(1) - (1)].s_select));
}
    break;

  case 431:

/* Line 1464 of yacc.c  */
#line 2614 "sql.yacc"
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
#line 2621 "sql.yacc"
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
#line 2638 "sql.yacc"
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
#line 2645 "sql.yacc"
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
#line 2670 "sql.yacc"
    { 
		//start_bind('i',0);
		 set_ignore_indicators();}
    break;

  case 436:

/* Line 1464 of yacc.c  */
#line 2672 "sql.yacc"
    { clr_ignore_indicators();}
    break;

  case 437:

/* Line 1464 of yacc.c  */
#line 2674 "sql.yacc"
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
#line 2695 "sql.yacc"
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
#line 2738 "sql.yacc"
    { (yyval.s_select)=0;}
    break;

  case 440:

/* Line 1464 of yacc.c  */
#line 2739 "sql.yacc"
    { 
		(yyval.s_select)=(yyvsp[(3) - (3)].s_select);
		(yyval.s_select)->union_op=acl_strdup((yyvsp[(2) - (3)].str));
		A4GL_set_associated_mem((yyval.s_select), (yyval.s_select)->union_op);
		add_feature("SELECT_UNION"); 
	}
    break;

  case 441:

/* Line 1464 of yacc.c  */
#line 2753 "sql.yacc"
    {
		(yyval.s_select_finish)=0;
	}
    break;

  case 442:

/* Line 1464 of yacc.c  */
#line 2756 "sql.yacc"
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
#line 2763 "sql.yacc"
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
#line 2773 "sql.yacc"
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
#line 2791 "sql.yacc"
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
#line 2804 "sql.yacc"
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
#line 2819 "sql.yacc"
    {(yyval.integer_val)=-1;}
    break;

  case 449:

/* Line 1464 of yacc.c  */
#line 2821 "sql.yacc"
    {
		(yyval.integer_val)=atol((yyvsp[(2) - (2)].str));
	}
    break;

  case 450:

/* Line 1464 of yacc.c  */
#line 2827 "sql.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 451:

/* Line 1464 of yacc.c  */
#line 2828 "sql.yacc"
    {strcpy((yyval.str),"ALL"); add_feature("SELECT_ALL");}
    break;

  case 452:

/* Line 1464 of yacc.c  */
#line 2829 "sql.yacc"
    {strcpy((yyval.str),"DISTINCT"); add_feature("SELECT_DISTINCT");}
    break;

  case 453:

/* Line 1464 of yacc.c  */
#line 2830 "sql.yacc"
    {strcpy((yyval.str),"DISTINCT");
		add_feature("SELECT_UNIQUE");
		ansi_violation("Use DISTINCT not UNIQUE",0);
		strcpy((yyval.str),"DISTINCT");
	}
    break;

  case 454:

/* Line 1464 of yacc.c  */
#line 2840 "sql.yacc"
    {
			(yyval.s_select_list_item_list)=rationalize_select_list_item_list((yyvsp[(1) - (1)].s_select_list_item_list));
		}
    break;

  case 455:

/* Line 1464 of yacc.c  */
#line 2847 "sql.yacc"
    { 
		 (yyval.s_select_list_item_list)=local_new_select_list_item_list((yyvsp[(1) - (1)].s_select_list_item));
	}
    break;

  case 456:

/* Line 1464 of yacc.c  */
#line 2850 "sql.yacc"
    { 
		(yyval.s_select_list_item_list)=local_add_select_list_item_list((yyvsp[(1) - (3)].s_select_list_item_list),(yyvsp[(3) - (3)].s_select_list_item));
	}
    break;

  case 457:

/* Line 1464 of yacc.c  */
#line 2856 "sql.yacc"
    {
		(yyval.s_select_list_item)=(yyvsp[(1) - (1)].s_select_list_item);
	}
    break;

  case 458:

/* Line 1464 of yacc.c  */
#line 2859 "sql.yacc"
    {
		(yyval.s_select_list_item)=(yyvsp[(1) - (2)].s_select_list_item);
		(yyval.s_select_list_item)->alias=acl_strdup((yyvsp[(2) - (2)].str));
		A4GL_set_associated_mem((yyval.s_select_list_item), (yyval.s_select_list_item)->alias);
	}
    break;

  case 459:

/* Line 1464 of yacc.c  */
#line 2864 "sql.yacc"
    {
		(yyval.s_select_list_item)=(yyvsp[(1) - (3)].s_select_list_item);
		(yyval.s_select_list_item)->alias=acl_strdup((yyvsp[(3) - (3)].str));
		A4GL_set_associated_mem((yyval.s_select_list_item), (yyval.s_select_list_item)->alias);
	}
    break;

  case 460:

/* Line 1464 of yacc.c  */
#line 2873 "sql.yacc"
    {
		(yyval.s_select_list_item)=(yyvsp[(1) - (1)].s_select_list_item); /* A4GLSQLCV_check_expr($<sql_string>1) */
	}
    break;

  case 461:

/* Line 1464 of yacc.c  */
#line 2876 "sql.yacc"
    {
		(yyval.s_select_list_item)=(yyvsp[(2) - (2)].s_select_list_item);
		(yyval.s_select_list_item)->sign='-';
	}
    break;

  case 462:

/* Line 1464 of yacc.c  */
#line 2880 "sql.yacc"
    {
		(yyval.s_select_list_item)=(yyvsp[(2) - (2)].s_select_list_item);
	}
    break;

  case 463:

/* Line 1464 of yacc.c  */
#line 2887 "sql.yacc"
    {
			(yyval.s_select_list_item)=new_select_list_item_op_expr ((yyvsp[(1) - (3)].s_select_list_item), (yyvsp[(3) - (3)].s_select_list_item), "/");
	}
    break;

  case 464:

/* Line 1464 of yacc.c  */
#line 2890 "sql.yacc"
    {
			(yyval.s_select_list_item)=new_select_list_item_simple_expr((enum e_sli)(yyvsp[(2) - (2)].integer_val), (yyvsp[(1) - (2)].s_select_list_item));
	}
    break;

  case 465:

/* Line 1464 of yacc.c  */
#line 2893 "sql.yacc"
    {
			(yyval.s_select_list_item)=new_select_list_item_op_expr ((yyvsp[(1) - (3)].s_select_list_item), (yyvsp[(3) - (3)].s_select_list_item), "*");
	}
    break;

  case 466:

/* Line 1464 of yacc.c  */
#line 2896 "sql.yacc"
    {
			(yyval.s_select_list_item)=new_select_list_item_op_expr ((yyvsp[(1) - (3)].s_select_list_item), (yyvsp[(3) - (3)].s_select_list_item), "+");
	}
    break;

  case 467:

/* Line 1464 of yacc.c  */
#line 2899 "sql.yacc"
    {
			(yyval.s_select_list_item)=new_select_list_item_op_expr ((yyvsp[(1) - (3)].s_select_list_item), (yyvsp[(3) - (3)].s_select_list_item), "-");
	}
    break;

  case 468:

/* Line 1464 of yacc.c  */
#line 2902 "sql.yacc"
    {
			(yyval.s_select_list_item)=new_select_list_item_op_expr ((yyvsp[(1) - (3)].s_select_list_item), (yyvsp[(3) - (3)].s_select_list_item), "||");
	}
    break;

  case 469:

/* Line 1464 of yacc.c  */
#line 2905 "sql.yacc"
    { (yyval.s_select_list_item)=new_select_list_item_literal((yyvsp[(1) - (1)].str)); }
    break;

  case 470:

/* Line 1464 of yacc.c  */
#line 2906 "sql.yacc"
    { (yyval.s_select_list_item)=new_select_list_item_builtin_const(E_SLI_BUILTIN_CONST_TRUE); }
    break;

  case 471:

/* Line 1464 of yacc.c  */
#line 2907 "sql.yacc"
    { (yyval.s_select_list_item)=new_select_list_item_builtin_const(E_SLI_BUILTIN_CONST_FALSE); }
    break;

  case 472:

/* Line 1464 of yacc.c  */
#line 2908 "sql.yacc"
    { (yyval.s_select_list_item)=new_select_list_item_builtin_const(E_SLI_BUILTIN_CONST_USER); }
    break;

  case 473:

/* Line 1464 of yacc.c  */
#line 2909 "sql.yacc"
    { (yyval.s_select_list_item)=new_select_list_item_builtin_const(E_SLI_BUILTIN_CONST_TODAY); }
    break;

  case 474:

/* Line 1464 of yacc.c  */
#line 2910 "sql.yacc"
    { (yyval.s_select_list_item)=new_select_list_item_builtin_const(E_SLI_BUILTIN_CONST_ROWID); }
    break;

  case 475:

/* Line 1464 of yacc.c  */
#line 2911 "sql.yacc"
    { (yyval.s_select_list_item)=new_select_list_item_builtin_const(E_SLI_BUILTIN_CONST_TIME); }
    break;

  case 476:

/* Line 1464 of yacc.c  */
#line 2912 "sql.yacc"
    { (yyval.s_select_list_item)=new_select_list_item_builtin_const(E_SLI_BUILTIN_CONST_STAR); }
    break;

  case 477:

/* Line 1464 of yacc.c  */
#line 2913 "sql.yacc"
    { (yyval.s_select_list_item)=new_select_list_item_builtin_const(E_SLI_BUILTIN_CONST_COUNT_STAR); }
    break;

  case 478:

/* Line 1464 of yacc.c  */
#line 2915 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_agg1(E_SLI_BUILTIN_AGG_AVG,(yyvsp[(3) - (5)].str),(yyvsp[(4) - (5)].s_select_list_item));
		add_feature("SELECT_AVG");
	}
    break;

  case 479:

/* Line 1464 of yacc.c  */
#line 2919 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_agg1(E_SLI_BUILTIN_AGG_MAX,(yyvsp[(3) - (5)].str),(yyvsp[(4) - (5)].s_select_list_item));
		add_feature("SELECT_MAX");
	}
    break;

  case 480:

/* Line 1464 of yacc.c  */
#line 2923 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_agg1(E_SLI_BUILTIN_AGG_MIN,(yyvsp[(3) - (5)].str),(yyvsp[(4) - (5)].s_select_list_item));
		add_feature("SELECT_MIN");
	}
    break;

  case 481:

/* Line 1464 of yacc.c  */
#line 2927 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_agg1(E_SLI_BUILTIN_AGG_SUM,(yyvsp[(3) - (5)].str),(yyvsp[(4) - (5)].s_select_list_item));
		add_feature("SELECT_SUM");
	}
    break;

  case 482:

/* Line 1464 of yacc.c  */
#line 2931 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_agg1(E_SLI_BUILTIN_AGG_COUNT,(yyvsp[(3) - (5)].str),(yyvsp[(4) - (5)].s_select_list_item));
		add_feature("SELECT_COUNT");
	}
    break;

  case 483:

/* Line 1464 of yacc.c  */
#line 2935 "sql.yacc"
    {
		add_sql_function((yyvsp[(1) - (3)].str));
		(yyval.s_select_list_item)=new_select_list_item_fcall((yyvsp[(1) - (3)].str),0);
	}
    break;

  case 484:

/* Line 1464 of yacc.c  */
#line 2939 "sql.yacc"
    {
		add_sql_function((yyvsp[(1) - (4)].str));
		(yyval.s_select_list_item)=new_select_list_item_fcall((yyvsp[(1) - (4)].str),(yyvsp[(3) - (4)].s_select_list_item_list));
	}
    break;

  case 485:

/* Line 1464 of yacc.c  */
#line 2943 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_builtin_fcall(E_SLI_BUILTIN_FUNC_YEAR,(yyvsp[(3) - (4)].s_select_list_item_list));
	}
    break;

  case 486:

/* Line 1464 of yacc.c  */
#line 2946 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_builtin_fcall(E_SLI_BUILTIN_FUNC_MONTH,(yyvsp[(3) - (4)].s_select_list_item_list));
	}
    break;

  case 487:

/* Line 1464 of yacc.c  */
#line 2949 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_builtin_fcall(E_SLI_BUILTIN_FUNC_DAY,(yyvsp[(3) - (4)].s_select_list_item_list));
	}
    break;

  case 488:

/* Line 1464 of yacc.c  */
#line 2952 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_builtin_fcall(E_SLI_BUILTIN_FUNC_MDY,(yyvsp[(3) - (4)].s_select_list_item_list));
	}
    break;

  case 489:

/* Line 1464 of yacc.c  */
#line 2955 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_builtin_fcall(E_SLI_BUILTIN_FUNC_WEEKDAY,(yyvsp[(3) - (4)].s_select_list_item_list));
	}
    break;

  case 490:

/* Line 1464 of yacc.c  */
#line 2958 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_builtin_fcall(E_SLI_BUILTIN_FUNC_DOW,(yyvsp[(3) - (4)].s_select_list_item_list));
	}
    break;

  case 491:

/* Line 1464 of yacc.c  */
#line 2961 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_builtin_fcall(E_SLI_BUILTIN_FUNC_DATE,(yyvsp[(3) - (4)].s_select_list_item_list));
	}
    break;

  case 492:

/* Line 1464 of yacc.c  */
#line 2964 "sql.yacc"
    {
		  (yyval.s_select_list_item)=new_select_list_item_simple_expr(E_SLI_BRACKET_EXPR,(yyvsp[(2) - (3)].s_select_list_item));
	}
    break;

  case 493:

/* Line 1464 of yacc.c  */
#line 2967 "sql.yacc"
    { 
		add_feature("EXTEND"); 
		(yyval.s_select_list_item)=(yyvsp[(3) - (4)].s_select_list_item);
	}
    break;

  case 494:

/* Line 1464 of yacc.c  */
#line 2971 "sql.yacc"
    { 
		(yyval.s_select_list_item)=new_select_list_item_datetime((yyvsp[(1) - (1)].str));
		add_feature("FUNC_DATETIME");
	}
    break;

  case 495:

/* Line 1464 of yacc.c  */
#line 2975 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_interval((yyvsp[(1) - (1)].str));
		add_feature("FUNC_INTERVAL");
	}
    break;

  case 496:

/* Line 1464 of yacc.c  */
#line 2979 "sql.yacc"
    {
		(yyval.s_select_list_item)=(yyvsp[(2) - (3)].s_select_list_item);
	}
    break;

  case 497:

/* Line 1464 of yacc.c  */
#line 2982 "sql.yacc"
    {
		(yyvsp[(3) - (4)].s_select_list_item)->data.s_select_list_item_data_u.sqlcase.master_condition=(yyvsp[(2) - (4)].s_select_list_item);
		(yyval.s_select_list_item)=(yyvsp[(3) - (4)].s_select_list_item);
	}
    break;

  case 498:

/* Line 1464 of yacc.c  */
#line 2991 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_case((yyvsp[(1) - (1)].s_select_list_item));
	}
    break;

  case 499:

/* Line 1464 of yacc.c  */
#line 2994 "sql.yacc"
    {
		(yyval.s_select_list_item)=append_select_list_item_case(
							(yyvsp[(1) - (2)].s_select_list_item),
							(yyvsp[(2) - (2)].s_select_list_item));
	}
    break;

  case 500:

/* Line 1464 of yacc.c  */
#line 3003 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_case_element(
				(yyvsp[(2) - (4)].s_select_list_item),
				(yyvsp[(4) - (4)].s_select_list_item));

	}
    break;

  case 501:

/* Line 1464 of yacc.c  */
#line 3009 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_case_element( 0, (yyvsp[(2) - (2)].s_select_list_item));
	}
    break;

  case 502:

/* Line 1464 of yacc.c  */
#line 3016 "sql.yacc"
    {
		(yyval.s_select_list_item_list)=local_new_select_list_item_list((yyvsp[(1) - (1)].s_select_list_item));
	}
    break;

  case 503:

/* Line 1464 of yacc.c  */
#line 3019 "sql.yacc"
    {
			(yyval.s_select_list_item_list)=local_add_select_list_item_list((yyvsp[(1) - (3)].s_select_list_item_list),(yyvsp[(3) - (3)].s_select_list_item));
	}
    break;

  case 504:

/* Line 1464 of yacc.c  */
#line 3043 "sql.yacc"
    {(yyval.str_list)=NULL;}
    break;

  case 505:

/* Line 1464 of yacc.c  */
#line 3044 "sql.yacc"
    { (yyval.str_list)=new_str_list((yyvsp[(2) - (4)].str));  add_str_list((yyval.str_list),(yyvsp[(4) - (4)].str));}
    break;

  case 506:

/* Line 1464 of yacc.c  */
#line 3045 "sql.yacc"
    { (yyval.str_list)=new_str_list((yyvsp[(1) - (3)].str));  add_str_list((yyval.str_list),(yyvsp[(3) - (3)].str));}
    break;

  case 508:

/* Line 1464 of yacc.c  */
#line 3049 "sql.yacc"
    {
			(yyval.s_select_list_item)=new_select_list_item_extend((yyvsp[(1) - (2)].s_select_list_item),(yyvsp[(2) - (2)].str_list));
	}
    break;

  case 509:

/* Line 1464 of yacc.c  */
#line 3052 "sql.yacc"
    {
			(yyval.s_select_list_item)=new_select_list_item_extend((yyvsp[(1) - (2)].s_select_list_item),(yyvsp[(2) - (2)].str_list));
	}
    break;

  case 510:

/* Line 1464 of yacc.c  */
#line 3058 "sql.yacc"
    {(yyval.integer_val)=E_SLI_UNITS_YEAR;}
    break;

  case 511:

/* Line 1464 of yacc.c  */
#line 3059 "sql.yacc"
    {(yyval.integer_val)=E_SLI_UNITS_MONTH;}
    break;

  case 512:

/* Line 1464 of yacc.c  */
#line 3060 "sql.yacc"
    {(yyval.integer_val)=E_SLI_UNITS_DAY;}
    break;

  case 513:

/* Line 1464 of yacc.c  */
#line 3061 "sql.yacc"
    {(yyval.integer_val)=E_SLI_UNITS_HOUR;}
    break;

  case 514:

/* Line 1464 of yacc.c  */
#line 3062 "sql.yacc"
    {(yyval.integer_val)=E_SLI_UNITS_MINUTE;}
    break;

  case 515:

/* Line 1464 of yacc.c  */
#line 3063 "sql.yacc"
    {(yyval.integer_val)=E_SLI_UNITS_SECOND;}
    break;

  case 516:

/* Line 1464 of yacc.c  */
#line 3068 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_op_slil((yyvsp[(1) - (5)].s_select_list_item),(yyvsp[(4) - (5)].s_select_list_item_list),E_SLI_IN_VALUES);
                add_feature("WHERE_IN");
        }
    break;

  case 517:

/* Line 1464 of yacc.c  */
#line 3072 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_op_sli((yyvsp[(1) - (3)].s_select_list_item),(yyvsp[(3) - (3)].s_select_list_item),E_SLI_IN_SELECT);
                add_feature("WHERE_IN_SELECT");
        }
    break;

  case 518:

/* Line 1464 of yacc.c  */
#line 3076 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_op_slil((yyvsp[(1) - (5)].s_select_list_item),(yyvsp[(4) - (5)].s_select_list_item_list),E_SLI_NOT_IN_VALUES);
                add_feature("WHERE_IN");
        }
    break;

  case 519:

/* Line 1464 of yacc.c  */
#line 3080 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_op_sli((yyvsp[(1) - (3)].s_select_list_item),(yyvsp[(3) - (3)].s_select_list_item),E_SLI_NOT_IN_SELECT);
                add_feature("WHERE_IN_SELECT");
        }
    break;

  case 520:

/* Line 1464 of yacc.c  */
#line 3087 "sql.yacc"
    {
		(yyval.s_select_list_item_list)=local_new_select_list_item_list((yyvsp[(1) - (1)].s_select_list_item));
	}
    break;

  case 521:

/* Line 1464 of yacc.c  */
#line 3090 "sql.yacc"
    {
                (yyval.s_select_list_item_list)=local_add_select_list_item_list((yyvsp[(1) - (3)].s_select_list_item_list),(yyvsp[(3) - (3)].s_select_list_item));
	}
    break;

  case 522:

/* Line 1464 of yacc.c  */
#line 3095 "sql.yacc"
    { (yyval.s_select_list_item)=(yyvsp[(1) - (1)].s_select_list_item);}
    break;

  case 523:

/* Line 1464 of yacc.c  */
#line 3096 "sql.yacc"
    { (yyval.s_select_list_item)=new_select_list_item_literal((yyvsp[(1) - (1)].str)); }
    break;

  case 524:

/* Line 1464 of yacc.c  */
#line 3097 "sql.yacc"
    { 
		char buff[256]; SPRINTF1(buff," -%s",(yyvsp[(2) - (2)].str)); (yyval.s_select_list_item)=new_select_list_item_literal(buff); }
    break;

  case 525:

/* Line 1464 of yacc.c  */
#line 3099 "sql.yacc"
    { char buff[256]; SPRINTF1(buff," -%s",(yyvsp[(2) - (2)].str)); (yyval.s_select_list_item)=new_select_list_item_literal(buff); }
    break;

  case 526:

/* Line 1464 of yacc.c  */
#line 3105 "sql.yacc"
    {
                if (strstr((yyvsp[(1) - (1)].str),"systables")!=0) { add_feature("IFX_SYSTABLES"); }
                if (strstr((yyvsp[(1) - (1)].str),"syscolumns")!=0) { add_feature("IFX_SYSCOLUMNS"); }
                if (strstr((yyvsp[(1) - (1)].str),"sysindexes")!=0) { add_feature("IFX_SYSINDEXES"); }
                strcpy((yyval.str),A4GLSQLCV_check_tablename((yyvsp[(1) - (1)].str)));
                }
    break;

  case 527:

/* Line 1464 of yacc.c  */
#line 3115 "sql.yacc"
    {
	     SPRINTF1((yyval.str),"%s", A4GLSQLCV_ownerize_tablename(NULL, A4GL_strip_quotes((yyvsp[(1) - (1)].str))));
             ADDMAP("Use Table",(yyval.str));
        }
    break;

  case 528:

/* Line 1464 of yacc.c  */
#line 3119 "sql.yacc"
    {
	     SPRINTF1((yyval.str),"%s", A4GLSQLCV_ownerize_tablename((yyvsp[(1) - (3)].str), (yyvsp[(3) - (3)].str)));
	     ADDMAP("Use Table",(yyval.str));
        }
    break;

  case 529:

/* Line 1464 of yacc.c  */
#line 3123 "sql.yacc"
    {
	     SPRINTF1((yyval.str),"%s", A4GLSQLCV_ownerize_tablename(NULL, (yyvsp[(1) - (1)].str)));
	     ADDMAP("Use Table",(yyval.str));
	}
    break;

  case 530:

/* Line 1464 of yacc.c  */
#line 3127 "sql.yacc"
    {
	     SPRINTF1((yyval.str),"%s", A4GLSQLCV_db_tablename((yyvsp[(1) - (3)].str), NULL, A4GLSQLCV_ownerize_tablename(NULL, (yyvsp[(3) - (3)].str))));
	     ADDMAP("Use Table",(yyval.str));
	}
    break;

  case 531:

/* Line 1464 of yacc.c  */
#line 3131 "sql.yacc"
    {
	     SPRINTF1((yyval.str),"%s", A4GLSQLCV_db_tablename((yyvsp[(1) - (5)].str), NULL, A4GLSQLCV_ownerize_tablename((yyvsp[(3) - (5)].str),(yyvsp[(5) - (5)].str))));
	     ADDMAP("Use Table",(yyval.str));
        }
    break;

  case 532:

/* Line 1464 of yacc.c  */
#line 3135 "sql.yacc"
    {
	     SPRINTF1((yyval.str),"%s", A4GLSQLCV_db_tablename(NULL,(yyvsp[(1) - (3)].str), A4GLSQLCV_ownerize_tablename(NULL, (yyvsp[(3) - (3)].str))));
	     ADDMAP("Use Table",(yyval.str));
	}
    break;

  case 533:

/* Line 1464 of yacc.c  */
#line 3139 "sql.yacc"
    {
	     SPRINTF1((yyval.str),"%s", A4GLSQLCV_db_tablename((yyvsp[(1) - (5)].str), (yyvsp[(3) - (5)].str), A4GLSQLCV_ownerize_tablename(NULL, (yyvsp[(5) - (5)].str))));
	     ADDMAP("Use Table",(yyval.str));
	}
    break;

  case 534:

/* Line 1464 of yacc.c  */
#line 3143 "sql.yacc"
    {
	     SPRINTF1((yyval.str),"%s", A4GLSQLCV_db_tablename((yyvsp[(1) - (7)].str), (yyvsp[(3) - (7)].str), A4GLSQLCV_ownerize_tablename((yyvsp[(5) - (7)].str), (yyvsp[(7) - (7)].str))));
	     ADDMAP("Use Table",(yyval.str));
        }
    break;

  case 535:

/* Line 1464 of yacc.c  */
#line 3151 "sql.yacc"
    {
                if (strstr((yyvsp[(1) - (1)].str),"systables")!=0) { add_feature("IFX_SYSTABLES"); }
                if (strstr((yyvsp[(1) - (1)].str),"syscolumns")!=0) { add_feature("IFX_SYSCOLUMNS"); }
                if (strstr((yyvsp[(1) - (1)].str),"sysindexes")!=0) { add_feature("IFX_SYSINDEXES"); }
                strcpy((yyval.str),A4GLSQLCV_check_tablename((yyvsp[(1) - (1)].str)));
                }
    break;

  case 536:

/* Line 1464 of yacc.c  */
#line 3161 "sql.yacc"
    {

	     SPRINTF1((yyval.str),"%s", A4GLSQLCV_ownerize_tablename((yyvsp[(1) - (3)].str), (yyvsp[(3) - (3)].str)));
	     ADDMAP("Use Table",(yyval.str));
        }
    break;

  case 537:

/* Line 1464 of yacc.c  */
#line 3166 "sql.yacc"
    {
	     SPRINTF1((yyval.str),"%s", A4GLSQLCV_ownerize_tablename((yyvsp[(1) - (3)].str), (yyvsp[(3) - (3)].str)));
	     ADDMAP("Use Table",(yyval.str));
        }
    break;

  case 538:

/* Line 1464 of yacc.c  */
#line 3170 "sql.yacc"
    {
	     SPRINTF1((yyval.str),"%s", A4GLSQLCV_ownerize_tablename(NULL, A4GL_strip_quotes((yyvsp[(1) - (1)].str))));
	     ADDMAP("Use Table",(yyval.str));
        }
    break;

  case 539:

/* Line 1464 of yacc.c  */
#line 3174 "sql.yacc"
    {
             SPRINTF1((yyval.str),"%s", A4GLSQLCV_ownerize_tablename(NULL, (yyvsp[(1) - (1)].str)));
	     ADDMAP("Use Table",(yyval.str));
	}
    break;

  case 540:

/* Line 1464 of yacc.c  */
#line 3178 "sql.yacc"
    {
             SPRINTF1((yyval.str),"%s", A4GLSQLCV_db_tablename((yyvsp[(1) - (3)].str),NULL, A4GLSQLCV_ownerize_tablename(NULL, (yyvsp[(3) - (3)].str))));
	     ADDMAP("Use Table",(yyval.str));
	}
    break;

  case 541:

/* Line 1464 of yacc.c  */
#line 3182 "sql.yacc"
    {
	     SPRINTF1((yyval.str),"%s", A4GLSQLCV_db_tablename((yyvsp[(1) - (5)].str), NULL,A4GLSQLCV_ownerize_tablename((yyvsp[(3) - (5)].str), (yyvsp[(5) - (5)].str))));
	     ADDMAP("Use Table",(yyval.str));
        }
    break;

  case 542:

/* Line 1464 of yacc.c  */
#line 3187 "sql.yacc"
    {
             SPRINTF1((yyval.str),"%s", A4GLSQLCV_db_tablename(NULL, (yyvsp[(1) - (3)].str), A4GLSQLCV_ownerize_tablename(NULL, (yyvsp[(3) - (3)].str))));
	     ADDMAP("Use Table",(yyval.str));
	}
    break;

  case 543:

/* Line 1464 of yacc.c  */
#line 3191 "sql.yacc"
    {
            SPRINTF1((yyval.str),"%s", A4GLSQLCV_db_tablename( (yyvsp[(1) - (5)].str), (yyvsp[(3) - (5)].str), A4GLSQLCV_ownerize_tablename(NULL, (yyvsp[(5) - (5)].str))));
	    ADDMAP("Use Table",(yyval.str));
	}
    break;

  case 544:

/* Line 1464 of yacc.c  */
#line 3195 "sql.yacc"
    {
	     SPRINTF1((yyval.str),"%s", A4GLSQLCV_db_tablename((yyvsp[(1) - (7)].str), (yyvsp[(3) - (7)].str), A4GLSQLCV_ownerize_tablename((yyvsp[(5) - (7)].str), (yyvsp[(7) - (7)].str))));
	     ADDMAP("Use Table",(yyval.str));
        }
    break;

  case 545:

/* Line 1464 of yacc.c  */
#line 3203 "sql.yacc"
    {
	     SPRINTF1((yyval.str),"%s", A4GLSQLCV_ownerize_tablename((yyvsp[(1) - (3)].str), (yyvsp[(3) - (3)].str)));
        }
    break;

  case 546:

/* Line 1464 of yacc.c  */
#line 3206 "sql.yacc"
    {
	        SPRINTF1((yyval.str),"%s", A4GLSQLCV_ownerize_tablename(NULL, (yyvsp[(1) - (1)].str)));
                ADDMAP("Use Index",(yyval.str));
        }
    break;

  case 547:

/* Line 1464 of yacc.c  */
#line 3211 "sql.yacc"
    {strcpy((yyval.str),(yyvsp[(1) - (1)].str)); ADDMAP("Use Index",(yyvsp[(1) - (1)].str)); }
    break;

  case 548:

/* Line 1464 of yacc.c  */
#line 3212 "sql.yacc"
    { SPRINTF3((yyval.str),"%s%s%s",(yyvsp[(1) - (3)].str),(yyvsp[(2) - (3)].str),(yyvsp[(3) - (3)].str)); ADDMAP("Use Index",(yyval.str)); }
    break;

  case 549:

/* Line 1464 of yacc.c  */
#line 3213 "sql.yacc"
    {
	     SPRINTF2((yyval.str),"%s:%s", (yyvsp[(1) - (5)].str), A4GLSQLCV_ownerize_tablename((yyvsp[(3) - (5)].str), (yyvsp[(5) - (5)].str)));
             ADDMAP("Use Index",(yyval.str));
        }
    break;

  case 550:

/* Line 1464 of yacc.c  */
#line 3218 "sql.yacc"
    {strcpy((yyval.str),(yyvsp[(1) - (3)].str)); ADDMAP("Use Index",(yyvsp[(1) - (3)].str)); }
    break;

  case 551:

/* Line 1464 of yacc.c  */
#line 3219 "sql.yacc"
    { SPRINTF4((yyval.str),"%s@%s%s%s",(yyvsp[(1) - (5)].str),(yyvsp[(3) - (5)].str),(yyvsp[(4) - (5)].str),(yyvsp[(5) - (5)].str)); ADDMAP("Use Index",(yyval.str)); }
    break;

  case 552:

/* Line 1464 of yacc.c  */
#line 3220 "sql.yacc"
    {
	     SPRINTF3((yyval.str),"%s@%s:%s", (yyvsp[(1) - (7)].str), (yyvsp[(3) - (7)].str), A4GLSQLCV_ownerize_tablename((yyvsp[(5) - (7)].str), (yyvsp[(7) - (7)].str)));
             ADDMAP("Use Index",(yyval.str));
        }
    break;

  case 554:

/* Line 1464 of yacc.c  */
#line 3231 "sql.yacc"
    {
                      (yyval.ptr)=A4GL_new_expr_simple_string(A4GL_get_clobbered_from((yyval.str)), ET_EXPR_IDENTIFIER);
	}
    break;

  case 556:

/* Line 1464 of yacc.c  */
#line 3237 "sql.yacc"
    { sprintf((yyval.str),".%s",(yyvsp[(2) - (2)].str)); }
    break;

  case 558:

/* Line 1464 of yacc.c  */
#line 3242 "sql.yacc"
    {strcpy((yyval.str), A4GL_strip_quotes ((yyvsp[(1) - (1)].str)));}
    break;

  case 559:

/* Line 1464 of yacc.c  */
#line 3247 "sql.yacc"
    {(yyval.ptr_list)=0;}
    break;

  case 563:

/* Line 1464 of yacc.c  */
#line 3294 "sql.yacc"
    {
			int converted;
			(yyval.sql_string)=get_insert_cmd((yyvsp[(1) - (1)].insert_cmd),&converted);
			A4GL_free_associated_mem((yyvsp[(1) - (1)].insert_cmd));
			acl_free((yyvsp[(1) - (1)].insert_cmd));

		}
    break;

  case 564:

/* Line 1464 of yacc.c  */
#line 3301 "sql.yacc"
    {
			int converted;
			(yyval.sql_string)=get_update_cmd((yyvsp[(1) - (1)].update_cmd),&converted);
			A4GL_free_associated_mem((yyvsp[(1) - (1)].update_cmd));
			acl_free((yyvsp[(1) - (1)].update_cmd));
		}
    break;

  case 565:

/* Line 1464 of yacc.c  */
#line 3307 "sql.yacc"
    {
			int converted;
			(yyval.sql_string)=get_delete_cmd((yyvsp[(1) - (1)].delete_cmd),&converted);
			A4GL_free_associated_mem((yyvsp[(1) - (1)].delete_cmd));
			acl_free((yyvsp[(1) - (1)].delete_cmd));
		}
    break;

  case 568:

/* Line 1464 of yacc.c  */
#line 3322 "sql.yacc"
    { print_exec_select((yyvsp[(1) - (1)].sql_string));  }
    break;

  case 569:

/* Line 1464 of yacc.c  */
#line 3323 "sql.yacc"
    { print_exec_select((yyvsp[(1) - (1)].sql_string));  }
    break;

  case 571:

/* Line 1464 of yacc.c  */
#line 3325 "sql.yacc"
    { print_exec_select((yyvsp[(1) - (1)].sql_string));  }
    break;

  case 572:

/* Line 1464 of yacc.c  */
#line 3327 "sql.yacc"
    {
			print_sql_commit ((yyvsp[(1) - (1)].integer_val));
	}
    break;

  case 573:

/* Line 1464 of yacc.c  */
#line 3330 "sql.yacc"
    {print_unable_to_parse();}
    break;

  case 574:

/* Line 1464 of yacc.c  */
#line 3334 "sql.yacc"
    { (yyval.sql_string)=make_sql_string_and_free((yyvsp[(1) - (2)].sql_string),acl_strdup((yyvsp[(2) - (2)].str)),0);
}
    break;

  case 576:

/* Line 1464 of yacc.c  */
#line 3343 "sql.yacc"
    {
			(yyval.sql_string)=make_select_stmt_v2("", (yyvsp[(1) - (1)].s_select),"");
			A4GL_free_select_stmt((yyvsp[(1) - (1)].s_select));
		}
    break;

  case 577:

/* Line 1464 of yacc.c  */
#line 3349 "sql.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 578:

/* Line 1464 of yacc.c  */
#line 3350 "sql.yacc"
    {
			strcpy((yyval.str),A4GLSQLCV_get_forupdate(NULL));
		}
    break;

  case 579:

/* Line 1464 of yacc.c  */
#line 3353 "sql.yacc"
    {
			strcpy((yyval.str),A4GLSQLCV_get_forupdate((yyvsp[(2) - (2)].str)));
		}
    break;

  case 580:

/* Line 1464 of yacc.c  */
#line 3358 "sql.yacc"
    { strcpy((yyval.str),(yyvsp[(1) - (1)].str)); }
    break;

  case 581:

/* Line 1464 of yacc.c  */
#line 3359 "sql.yacc"
    { sprintf((yyval.str),"%s,%s",(yyvsp[(1) - (3)].str),(yyvsp[(3) - (3)].str)); }
    break;

  case 583:

/* Line 1464 of yacc.c  */
#line 3363 "sql.yacc"
    {sprintf((yyval.str),"%s.%s",A4GLSQLCV_ownerize_tablename(NULL, (yyvsp[(1) - (3)].str)),(yyvsp[(3) - (3)].str));}
    break;

  case 584:

/* Line 1464 of yacc.c  */
#line 3364 "sql.yacc"
    {
        sprintf((yyval.str),"%s.%s", A4GLSQLCV_ownerize_tablename((yyvsp[(1) - (5)].str), (yyvsp[(3) - (5)].str)), (yyvsp[(5) - (5)].str));
}
    break;

  case 585:

/* Line 1464 of yacc.c  */
#line 3374 "sql.yacc"
    { print_exec_sql(acl_strdup((yyvsp[(1) - (1)].str))); }
    break;

  case 586:

/* Line 1464 of yacc.c  */
#line 3375 "sql.yacc"
    { print_exec_sql(acl_strdup((yyvsp[(1) - (1)].str))); }
    break;

  case 587:

/* Line 1464 of yacc.c  */
#line 3376 "sql.yacc"
    { sprintf((yyval.str),"%s %s",(yyvsp[(1) - (2)].str),(yyvsp[(2) - (2)].str)); print_exec_sql(acl_strdup((yyval.str))); }
    break;

  case 588:

/* Line 1464 of yacc.c  */
#line 3377 "sql.yacc"
    { print_exec_sql(acl_strdup((yyvsp[(1) - (1)].str))); }
    break;

  case 589:

/* Line 1464 of yacc.c  */
#line 3378 "sql.yacc"
    { print_exec_sql(acl_strdup((yyvsp[(1) - (1)].str))); }
    break;

  case 590:

/* Line 1464 of yacc.c  */
#line 3379 "sql.yacc"
    { print_exec_sql(acl_strdup((yyvsp[(1) - (1)].str))); }
    break;

  case 591:

/* Line 1464 of yacc.c  */
#line 3380 "sql.yacc"
    { print_exec_sql(acl_strdup((yyvsp[(1) - (1)].str))); }
    break;

  case 592:

/* Line 1464 of yacc.c  */
#line 3381 "sql.yacc"
    { print_exec_sql(acl_strdup((yyvsp[(1) - (1)].str))); }
    break;

  case 593:

/* Line 1464 of yacc.c  */
#line 3385 "sql.yacc"
    { 
	char *s;
	s=acl_strdup((yyvsp[(1) - (1)].str));
	(yyval.s_select_list_item)=new_select_list_item_column_from_transform(s);
	acl_free(s);
	}
    break;

  case 594:

/* Line 1464 of yacc.c  */
#line 3391 "sql.yacc"
    {  
		(yyval.s_select_list_item)=new_select_list_item_builtin_const(E_SLI_QUERY_PLACEHOLDER);}
    break;

  case 595:

/* Line 1464 of yacc.c  */
#line 3393 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_replace_var((yyvsp[(1) - (1)].sql_string));
	}
    break;

  case 596:

/* Line 1464 of yacc.c  */
#line 3412 "sql.yacc"
    {
        add_feature("DATABASE_USED");
       conn_db((yyvsp[(2) - (3)].str));
}
    break;

  case 597:

/* Line 1464 of yacc.c  */
#line 3420 "sql.yacc"
    {
		(yyval.sql_string)=acl_strdup((yyvsp[(2) - (3)].str));
}
    break;

  case 598:

/* Line 1464 of yacc.c  */
#line 3427 "sql.yacc"
    {sprintf((yyval.str),"(%s)",(yyvsp[(2) - (3)].str));}
    break;

  case 599:

/* Line 1464 of yacc.c  */
#line 3428 "sql.yacc"
    { sprintf((yyval.str),"%s%s%s",(yyvsp[(1) - (3)].str),(yyvsp[(2) - (3)].str),(yyvsp[(3) - (3)].str));}
    break;

  case 600:

/* Line 1464 of yacc.c  */
#line 3429 "sql.yacc"
    {sprintf((yyval.str),"%d",atoi((yyvsp[(1) - (1)].str)));}
    break;

  case 601:

/* Line 1464 of yacc.c  */
#line 3430 "sql.yacc"
    {sprintf((yyval.str),"(%s%s)",(yyvsp[(1) - (2)].str),(yyvsp[(2) - (2)].str));}
    break;

  case 602:

/* Line 1464 of yacc.c  */
#line 3435 "sql.yacc"
    {strcpy((yyval.str),"+");}
    break;

  case 603:

/* Line 1464 of yacc.c  */
#line 3436 "sql.yacc"
    {strcpy((yyval.str),"-");}
    break;

  case 604:

/* Line 1464 of yacc.c  */
#line 3437 "sql.yacc"
    {strcpy((yyval.str),"*");}
    break;

  case 605:

/* Line 1464 of yacc.c  */
#line 3438 "sql.yacc"
    {strcpy((yyval.str),"/");}
    break;

  case 606:

/* Line 1464 of yacc.c  */
#line 3439 "sql.yacc"
    {strcpy((yyval.str),"%");}
    break;

  case 607:

/* Line 1464 of yacc.c  */
#line 3444 "sql.yacc"
    {strcpy((yyval.str),"+");}
    break;

  case 608:

/* Line 1464 of yacc.c  */
#line 3445 "sql.yacc"
    {strcpy((yyval.str),"-");}
    break;

  case 609:

/* Line 1464 of yacc.c  */
#line 3461 "sql.yacc"
    {sprintf((yyval.str),"%s", A4GLSQLCV_check_tablename((yyvsp[(1) - (1)].str)));}
    break;

  case 610:

/* Line 1464 of yacc.c  */
#line 3462 "sql.yacc"
    {sprintf((yyval.str),"%s.*", A4GLSQLCV_ownerize_tablename(NULL,(yyvsp[(1) - (3)].str)));}
    break;

  case 611:

/* Line 1464 of yacc.c  */
#line 3463 "sql.yacc"
    {sprintf((yyval.str),"%s.%s", (yyvsp[(1) - (3)].str),A4GLSQLCV_get_sqlconst ("rowid"));}
    break;

  case 612:

/* Line 1464 of yacc.c  */
#line 3464 "sql.yacc"
    {sprintf((yyval.str),"%s.%s", A4GLSQLCV_ownerize_tablename(NULL,(yyvsp[(1) - (3)].str)),(yyvsp[(3) - (3)].str));}
    break;

  case 613:

/* Line 1464 of yacc.c  */
#line 3465 "sql.yacc"
    {sprintf((yyval.str),"%s.%s", A4GLSQLCV_ownerize_tablename((yyvsp[(1) - (5)].str),(yyvsp[(3) - (5)].str)),(yyvsp[(5) - (5)].str));}
    break;

  case 614:

/* Line 1464 of yacc.c  */
#line 3466 "sql.yacc"
    {sprintf((yyval.str),"%s.%s", A4GLSQLCV_ownerize_tablename((yyvsp[(1) - (5)].str),(yyvsp[(3) - (5)].str)),(yyvsp[(5) - (5)].str));}
    break;

  case 615:

/* Line 1464 of yacc.c  */
#line 3467 "sql.yacc"
    {sprintf((yyval.str),"%s", (yyvsp[(1) - (4)].str)); strcpy((yyval.str), A4GLSQLCV_make_substr_s((yyvsp[(1) - (4)].str), 1,(yyvsp[(3) - (4)].str),0));}
    break;

  case 616:

/* Line 1464 of yacc.c  */
#line 3468 "sql.yacc"
    {char buff[256]; sprintf(buff,"%s.%s", A4GLSQLCV_ownerize_tablename(NULL,(yyvsp[(1) - (6)].str)),(yyvsp[(3) - (6)].str)); strcpy((yyval.str), A4GLSQLCV_make_substr_s(buff,1,(yyvsp[(5) - (6)].str),0));}
    break;

  case 617:

/* Line 1464 of yacc.c  */
#line 3469 "sql.yacc"
    {char buff[256]; sprintf(buff,"%s.%s", A4GLSQLCV_ownerize_tablename((yyvsp[(1) - (8)].str),(yyvsp[(3) - (8)].str)), (yyvsp[(5) - (8)].str)); strcpy((yyval.str), A4GLSQLCV_make_substr_s(buff,1,(yyvsp[(7) - (8)].str),0));  }
    break;

  case 618:

/* Line 1464 of yacc.c  */
#line 3470 "sql.yacc"
    {char buff[256]; sprintf(buff,"%s.%s", A4GLSQLCV_ownerize_tablename((yyvsp[(1) - (8)].str),(yyvsp[(3) - (8)].str)), (yyvsp[(5) - (8)].str));  strcpy((yyval.str), A4GLSQLCV_make_substr_s(buff,1,(yyvsp[(7) - (8)].str),0)); }
    break;

  case 619:

/* Line 1464 of yacc.c  */
#line 3472 "sql.yacc"
    {sprintf((yyval.str),"%s", (yyvsp[(1) - (6)].str)); strcpy((yyval.str), A4GLSQLCV_make_substr_s((yyvsp[(1) - (6)].str), 2,(yyvsp[(3) - (6)].str),(yyvsp[(5) - (6)].str)));}
    break;

  case 620:

/* Line 1464 of yacc.c  */
#line 3473 "sql.yacc"
    {char buff[256]; sprintf(buff,"%s.%s", A4GLSQLCV_ownerize_tablename(NULL,(yyvsp[(1) - (8)].str)),(yyvsp[(3) - (8)].str)); strcpy((yyval.str), A4GLSQLCV_make_substr_s(buff,2,(yyvsp[(5) - (8)].str),(yyvsp[(7) - (8)].str)));}
    break;

  case 621:

/* Line 1464 of yacc.c  */
#line 3474 "sql.yacc"
    {char buff[256]; sprintf(buff,"%s.%s", A4GLSQLCV_ownerize_tablename((yyvsp[(1) - (10)].str),(yyvsp[(3) - (10)].str)), (yyvsp[(5) - (10)].str)); strcpy((yyval.str), A4GLSQLCV_make_substr_s(buff,2,(yyvsp[(7) - (10)].str),(yyvsp[(9) - (10)].str)));  }
    break;

  case 622:

/* Line 1464 of yacc.c  */
#line 3475 "sql.yacc"
    {char buff[256]; sprintf(buff,"%s.%s", A4GLSQLCV_ownerize_tablename((yyvsp[(1) - (10)].str),(yyvsp[(3) - (10)].str)), (yyvsp[(5) - (10)].str));  strcpy((yyval.str), A4GLSQLCV_make_substr_s(buff,2,(yyvsp[(7) - (10)].str),(yyvsp[(9) - (10)].str))); }
    break;

  case 623:

/* Line 1464 of yacc.c  */
#line 3480 "sql.yacc"
    {
                (yyval.s_select_list_item)=(yyvsp[(1) - (1)].s_select_list_item);
        }
    break;

  case 624:

/* Line 1464 of yacc.c  */
#line 3483 "sql.yacc"
    {
                (yyval.s_select_list_item)=new_select_list_item_cast((yyvsp[(1) - (3)].s_select_list_item), (yyvsp[(3) - (3)].str));
        }
    break;

  case 625:

/* Line 1464 of yacc.c  */
#line 3492 "sql.yacc"
    { (yyvsp[(1) - (1)].s_select_list_item)=(yyvsp[(1) - (1)].s_select_list_item); }
    break;

  case 626:

/* Line 1464 of yacc.c  */
#line 3493 "sql.yacc"
    {(yyvsp[(1) - (1)].s_select_list_item)=(yyvsp[(1) - (1)].s_select_list_item);}
    break;

  case 627:

/* Line 1464 of yacc.c  */
#line 3494 "sql.yacc"
    {  (yyval.s_select_list_item)=new_select_list_item_sq(E_SQE_DONT_CARE,(yyvsp[(1) - (1)].s_select_list_item)); }
    break;

  case 628:

/* Line 1464 of yacc.c  */
#line 3495 "sql.yacc"
    { (yyval.s_select_list_item)=new_select_list_item_sq(E_SQE_ALL,(yyvsp[(2) - (2)].s_select_list_item)); }
    break;

  case 629:

/* Line 1464 of yacc.c  */
#line 3496 "sql.yacc"
    { (yyval.s_select_list_item)=new_select_list_item_sq(E_SQE_ANY,(yyvsp[(2) - (2)].s_select_list_item)); }
    break;

  case 630:

/* Line 1464 of yacc.c  */
#line 3497 "sql.yacc"
    { (yyval.s_select_list_item)=new_select_list_item_sq(E_SQE_SOME,(yyvsp[(2) - (2)].s_select_list_item)); }
    break;

  case 631:

/* Line 1464 of yacc.c  */
#line 3501 "sql.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 632:

/* Line 1464 of yacc.c  */
#line 3502 "sql.yacc"
    {strcpy((yyval.str),(yyvsp[(1) - (1)].str));}
    break;

  case 633:

/* Line 1464 of yacc.c  */
#line 3516 "sql.yacc"
    {
	(yyval.integer_val)=-1;
}
    break;



/* Line 1464 of yacc.c  */
#line 9012 "y.tab.c"
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
#line 3519 "sql.yacc"


#if LEX_YY_PREGEN
#include "../../tools/no_yacc/cygwin/compilers/sql/lex.sqlparse_yy.c"
#else
#include "lex.yy.c"
#endif
#include "util.c"
#include "cmds.c"

