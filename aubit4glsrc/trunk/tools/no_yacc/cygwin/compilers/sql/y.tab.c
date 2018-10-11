/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

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
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1


/* Substitute the variable and function names.  */
#define yyparse         sqlparse_yyparse
#define yylex           sqlparse_yylex
#define yyerror         sqlparse_yyerror
#define yydebug         sqlparse_yydebug
#define yynerrs         sqlparse_yynerrs

#define yylval          sqlparse_yylval
#define yychar          sqlparse_yychar

/* Copy the first part of user declarations.  */
#line 1 "sql.yacc" /* yacc.c:339  */

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


#line 216 "y.tab.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "y.tab.h".  */
#ifndef YY_SQLPARSE_YY_Y_TAB_H_INCLUDED
# define YY_SQLPARSE_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif
#if YYDEBUG
extern int sqlparse_yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    INT_VALUE = 2286,
    NAMED = 2287,
    NAMED_GEN = 2288,
    CHAR_VALUE = 2289,
    NOT_USED_1 = 2290,
    NOT_USED_2 = 2291,
    NOT_USED_3 = 2292,
    NOT_USED_4 = 2293,
    NOT_USED_5 = 2294,
    NOT_USED_6 = 2295,
    NOT_USED_7 = 2296,
    NOT_USED_8 = 2297,
    NUMBER_VALUE = 2298,
    SEMICOLON = 2299,
    QUESTION_MARK = 2300,
    CLINE = 2301,
    CH = 2302,
    MARK_VAR = 2303,
    END_MARK_VAR = 2304,
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
    LVARCHAR = 1494,
    DELIMITER = 1496,
    DROP_VIEW = 1498,
    EXCLUSIVE = 1501,
    GREATER_THAN_EQ = 1505,
    INTO_TEMP = 1507,
    DATABASE = 1531,
    DATETIME = 1532,
    DISTINCT = 1534,
    FRACTION = 1541,
    GROUP_BY = 1543,
    INTERVAL = 1544,
    NOT_LIKE = 1546,
    NOT_ILIKE = 1547,
    NOT_NULL = 1548,
    RESOURCE = 1554,
    SMALLINT = 1555,
    IS_NULL = 1561,
    LESS_THAN_EQ = 1562,
    BETWEEN = 1564,
    CLOSE_BRACKET = 1567,
    CONNECT = 1570,
    KW_CURRENT = 1571,
    KW_DECIMAL = 1573,
    KW_DEFAULT = 1575,
    FGL_SYNCFIELDS = 1583,
    INTEGER = 1584,
    SERIAL8 = 1586,
    MATCHES = 1589,
    VARCHAR = 1602,
    CLOSE_SQUARE = 1605,
    GREATER_THAN = 1606,
    KW_FALSE = 1607,
    NOT_IN = 1608,
    OPEN_BRACKET_SELECT = 1610,
    OPEN_BRACKET = 1611,
    KW_DELETE = 1619,
    KW_ESCAPE = 1622,
    EXISTS = 1623,
    EXTEND = 1624,
    HAVING = 1628,
    KW_INSERT = 1630,
    MINUTE = 1634,
    MODIFY = 1635,
    EQUAL = 1637,
    NOT_EQUAL = 1638,
    OPEN_SQUARE = 1640,
    PUBLIC = 1644,
    KW_RETURN_KEY = 1647,
    REVOKE = 1649,
    SECOND = 1653,
    KW_SELECT = 1657,
    SERIAL = 1658,
    UNIQUE = 1661,
    KW_UPDATE = 1663,
    VALUES = 1664,
    KW_NULL = 1667,
    KW_TRUE = 1668,
    ALTER = 1670,
    CHECK = 1676,
    KW_FIRST = 1684,
    KW_FLOAT = 1685,
    GRANT = 1688,
    INDEX = 1691,
    LESS_THAN = 1694,
    MONEY = 1696,
    MONTH = 1697,
    KW_MULTIPLY = 1699,
    ORDER = 1700,
    OUTER = 1701,
    UNION = 1710,
    WHERE = 1713,
    KW_BYTE = 1720,
    CASE = 1722,
    KW_DATE = 1724,
    DESC = 1725,
    KW_DIVIDE = 1726,
    DROP = 1729,
    ELSE = 1730,
    FROM = 1734,
    HOUR = 1740,
    INTO = 1741,
    LIKE = 1744,
    REAL = 1753,
    SOME = 1758,
    KW_TEXT = 1762,
    KW_THEN = 1763,
    USER = 1764,
    WHEN = 1766,
    YEAR = 1769,
    KW_DOW = 1770,
    XSET = 1772,
    ADD = 1773,
    ALL = 1774,
    KW_AND = 1775,
    ANY = 1776,
    ASC = 1777,
    AVG = 1778,
    COLON = 1779,
    KW_COMMA = 1780,
    DAY = 1781,
    DBA = 1782,
    KW_FOR = 1786,
    XMAX = 1791,
    XMIN = 1792,
    KW_MINUS = 1793,
    KW_MOD = 1794,
    KW_NOT = 1795,
    KW_SUM = 1802,
    ATSIGN = 1805,
    KW_PLUS = 1806,
    KW_AS = 1812,
    KW_BY = 1814,
    KW_DOT = 1815,
    KW_IN = 1818,
    KW_ON = 1820,
    KW_OR = 1821,
    KW_TO = 1822,
    BEFORE = 1860,
    END = 1864,
    TILDE = 1871,
    ILIKE = 1872,
    FILLFACTOR = 1875,
    TIME = 1880,
    KW_TODAY = 1887,
    KW_ROWID = 1888,
    TIMESTAMP = 2236,
    KWPIPE = 2266,
    COUNT = 2279,
    DIALOG = 2280,
    SUBDIALOG = 2281,
    PDF_XY = 2282,
    SET_VALUE = 2283,
    KW_EMBEDDED = 2284
  };
#endif
/* Tokens.  */
#define INT_VALUE 2286
#define NAMED 2287
#define NAMED_GEN 2288
#define CHAR_VALUE 2289
#define NOT_USED_1 2290
#define NOT_USED_2 2291
#define NOT_USED_3 2292
#define NOT_USED_4 2293
#define NOT_USED_5 2294
#define NOT_USED_6 2295
#define NOT_USED_7 2296
#define NOT_USED_8 2297
#define NUMBER_VALUE 2298
#define SEMICOLON 2299
#define QUESTION_MARK 2300
#define CLINE 2301
#define CH 2302
#define MARK_VAR 2303
#define END_MARK_VAR 2304
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
#define LVARCHAR 1494
#define DELIMITER 1496
#define DROP_VIEW 1498
#define EXCLUSIVE 1501
#define GREATER_THAN_EQ 1505
#define INTO_TEMP 1507
#define DATABASE 1531
#define DATETIME 1532
#define DISTINCT 1534
#define FRACTION 1541
#define GROUP_BY 1543
#define INTERVAL 1544
#define NOT_LIKE 1546
#define NOT_ILIKE 1547
#define NOT_NULL 1548
#define RESOURCE 1554
#define SMALLINT 1555
#define IS_NULL 1561
#define LESS_THAN_EQ 1562
#define BETWEEN 1564
#define CLOSE_BRACKET 1567
#define CONNECT 1570
#define KW_CURRENT 1571
#define KW_DECIMAL 1573
#define KW_DEFAULT 1575
#define FGL_SYNCFIELDS 1583
#define INTEGER 1584
#define SERIAL8 1586
#define MATCHES 1589
#define VARCHAR 1602
#define CLOSE_SQUARE 1605
#define GREATER_THAN 1606
#define KW_FALSE 1607
#define NOT_IN 1608
#define OPEN_BRACKET_SELECT 1610
#define OPEN_BRACKET 1611
#define KW_DELETE 1619
#define KW_ESCAPE 1622
#define EXISTS 1623
#define EXTEND 1624
#define HAVING 1628
#define KW_INSERT 1630
#define MINUTE 1634
#define MODIFY 1635
#define EQUAL 1637
#define NOT_EQUAL 1638
#define OPEN_SQUARE 1640
#define PUBLIC 1644
#define KW_RETURN_KEY 1647
#define REVOKE 1649
#define SECOND 1653
#define KW_SELECT 1657
#define SERIAL 1658
#define UNIQUE 1661
#define KW_UPDATE 1663
#define VALUES 1664
#define KW_NULL 1667
#define KW_TRUE 1668
#define ALTER 1670
#define CHECK 1676
#define KW_FIRST 1684
#define KW_FLOAT 1685
#define GRANT 1688
#define INDEX 1691
#define LESS_THAN 1694
#define MONEY 1696
#define MONTH 1697
#define KW_MULTIPLY 1699
#define ORDER 1700
#define OUTER 1701
#define UNION 1710
#define WHERE 1713
#define KW_BYTE 1720
#define CASE 1722
#define KW_DATE 1724
#define DESC 1725
#define KW_DIVIDE 1726
#define DROP 1729
#define ELSE 1730
#define FROM 1734
#define HOUR 1740
#define INTO 1741
#define LIKE 1744
#define REAL 1753
#define SOME 1758
#define KW_TEXT 1762
#define KW_THEN 1763
#define USER 1764
#define WHEN 1766
#define YEAR 1769
#define KW_DOW 1770
#define XSET 1772
#define ADD 1773
#define ALL 1774
#define KW_AND 1775
#define ANY 1776
#define ASC 1777
#define AVG 1778
#define COLON 1779
#define KW_COMMA 1780
#define DAY 1781
#define DBA 1782
#define KW_FOR 1786
#define XMAX 1791
#define XMIN 1792
#define KW_MINUS 1793
#define KW_MOD 1794
#define KW_NOT 1795
#define KW_SUM 1802
#define ATSIGN 1805
#define KW_PLUS 1806
#define KW_AS 1812
#define KW_BY 1814
#define KW_DOT 1815
#define KW_IN 1818
#define KW_ON 1820
#define KW_OR 1821
#define KW_TO 1822
#define BEFORE 1860
#define END 1864
#define TILDE 1871
#define ILIKE 1872
#define FILLFACTOR 1875
#define TIME 1880
#define KW_TODAY 1887
#define KW_ROWID 1888
#define TIMESTAMP 2236
#define KWPIPE 2266
#define COUNT 2279
#define DIALOG 2280
#define SUBDIALOG 2281
#define PDF_XY 2282
#define SET_VALUE 2283
#define KW_EMBEDDED 2284

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 145 "sql.yacc" /* yacc.c:355  */

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



#line 905 "y.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE sqlparse_yylval;

int sqlparse_yyparse (void);

#endif /* !YY_SQLPARSE_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 922 "y.tab.c" /* yacc.c:358  */

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
#else
typedef signed char yytype_int8;
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
# elif ! defined YYSIZE_T
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
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
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
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
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
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
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

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  155
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   2179

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  314
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  229
/* YYNRULES -- Number of rules.  */
#define YYNRULES  633
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  1115

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   2304

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
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
       2,   177,   178,   179,   180,     2,   181,     2,   182,     2,
       2,   183,     2,     2,     2,   184,     2,   185,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,   186,   187,     2,   188,     2,     2,     2,     2,     2,
       2,   189,     2,   190,   191,     2,   192,   193,   194,     2,
       2,     2,     2,     2,   195,   196,     2,     2,     2,     2,
       2,   197,   198,     2,   199,     2,     2,   200,     2,     2,
     201,   202,     2,   203,     2,   204,     2,     2,     2,     2,
       2,     2,     2,   205,   206,     2,   207,     2,     2,   208,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,   209,     2,     2,   210,   211,   212,   213,     2,
     214,   215,     2,     2,     2,     2,     2,     2,     2,   216,
       2,     2,   217,   218,   219,     2,     2,     2,   220,     2,
     221,     2,     2,     2,   222,   223,     2,   224,   225,     2,
     226,     2,     2,     2,   227,     2,     2,   228,     2,   229,
       2,     2,     2,   230,     2,     2,     2,   231,   232,     2,
       2,   233,     2,   234,   235,     2,     2,   236,   237,     2,
     238,     2,     2,     2,     2,     2,   239,     2,     2,     2,
       2,     2,     2,     2,   240,   241,     2,     2,   242,     2,
       2,   243,     2,     2,   244,     2,   245,   246,     2,   247,
     248,   249,     2,     2,     2,     2,     2,     2,     2,     2,
     250,     2,     2,   251,     2,     2,     2,     2,     2,     2,
     252,     2,   253,     2,   254,   255,   256,     2,     2,   257,
     258,     2,     2,     2,   259,     2,     2,     2,     2,     2,
     260,   261,     2,     2,   262,     2,     2,     2,     2,     2,
       2,     2,     2,   263,     2,     2,     2,     2,   264,     2,
       2,     2,   265,   266,   267,     2,   268,     2,     2,   269,
     270,     2,   271,   272,   273,   274,   275,   276,   277,   278,
     279,   280,   281,     2,     2,     2,   282,     2,     2,     2,
       2,   283,   284,   285,   286,   287,     2,     2,     2,     2,
       2,     2,   288,     2,     2,   289,   290,     2,     2,     2,
       2,     2,   291,     2,   292,   293,     2,     2,   294,     2,
     295,   296,   297,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     298,     2,     2,     2,   299,     2,     2,     2,     2,     2,
       2,   300,   301,     2,     2,   302,     2,     2,     2,     2,
     303,     2,     2,     2,     2,     2,     2,   304,   305,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,   306,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,   307,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,   308,
     309,   310,   311,   312,   313,     2,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   489,   489,   518,   521,   538,   543,   546,   563,   569,
     578,   587,   596,   603,   618,   673,   680,   691,   694,   699,
     706,   723,   740,   761,   770,   773,   781,   784,   792,   793,
     800,   803,   811,   814,   818,   824,   825,   829,   839,   853,
     854,   858,   859,   864,   872,   880,   888,   896,   906,   908,
     908,   911,   912,   916,   923,   930,   937,   946,   950,   957,
     969,   980,   986,   990,   994,   999,  1003,  1006,  1010,  1013,
    1020,  1021,  1031,  1032,  1036,  1037,  1041,  1050,  1059,  1066,
    1069,  1075,  1078,  1089,  1093,  1098,  1105,  1108,  1117,  1120,
    1124,  1128,  1132,  1136,  1140,  1148,  1152,  1160,  1163,  1170,
    1173,  1180,  1183,  1190,  1191,  1196,  1200,  1203,  1209,  1212,
    1218,  1225,  1226,  1230,  1238,  1242,  1249,  1251,  1256,  1257,
    1261,  1263,  1269,  1270,  1273,  1284,  1290,  1290,  1299,  1299,
    1308,  1333,  1336,  1344,  1347,  1354,  1357,  1365,  1366,  1372,
    1373,  1381,  1403,  1407,  1412,  1413,  1423,  1432,  1436,  1440,
    1445,  1449,  1453,  1456,  1463,  1469,  1474,  1482,  1483,  1484,
    1485,  1486,  1487,  1488,  1496,  1497,  1498,  1499,  1504,  1505,
    1506,  1509,  1510,  1511,  1515,  1516,  1517,  1521,  1522,  1526,
    1533,  1534,  1535,  1542,  1543,  1546,  1547,  1552,  1553,  1558,
    1559,  1564,  1565,  1570,  1577,  1578,  1583,  1584,  1588,  1589,
    1596,  1604,  1611,  1618,  1622,  1623,  1628,  1629,  1635,  1639,
    1644,  1651,  1652,  1658,  1661,  1664,  1671,  1672,  1673,  1674,
    1680,  1703,  1704,  1707,  1709,  1716,  1719,  1725,  1733,  1738,
    1744,  1749,  1755,  1758,  1763,  1771,  1780,  1785,  1789,  1790,
    1796,  1799,  1810,  1819,  1826,  1832,  1833,  1836,  1841,  1852,
    1856,  1863,  1864,  1868,  1872,  1876,  1883,  1888,  1896,  1899,
    1905,  1908,  1913,  1918,  1931,  1934,  1940,  1943,  1949,  1952,
    1958,  1961,  1968,  1972,  1983,  1983,  1984,  1984,  1985,  1985,
    1988,  1993,  1998,  1999,  2004,  2013,  2021,  2024,  2027,  2031,
    2038,  2041,  2045,  2048,  2051,  2054,  2060,  2067,  2070,  2073,
    2076,  2077,  2082,  2085,  2088,  2091,  2098,  2099,  2100,  2104,
    2111,  2112,  2113,  2117,  2131,  2138,  2139,  2140,  2144,  2145,
    2150,  2151,  2160,  2162,  2171,  2174,  2182,  2192,  2200,  2202,
    2203,  2204,  2205,  2206,  2207,  2208,  2216,  2217,  2218,  2219,
    2220,  2221,  2222,  2223,  2224,  2225,  2226,  2236,  2237,  2243,
    2245,  2246,  2247,  2248,  2252,  2256,  2260,  2267,  2268,  2273,
    2274,  2278,  2286,  2289,  2296,  2299,  2309,  2312,  2315,  2318,
    2325,  2332,  2340,  2349,  2356,  2360,  2365,  2366,  2367,  2372,
    2373,  2382,  2382,  2382,  2382,  2382,  2382,  2382,  2383,  2383,
    2383,  2383,  2383,  2383,  2383,  2383,  2428,  2429,  2430,  2435,
    2436,  2439,  2440,  2444,  2451,  2462,  2463,  2476,  2477,  2481,
    2485,  2486,  2489,  2495,  2499,  2522,  2532,  2535,  2541,  2550,
    2554,  2561,  2562,  2564,  2569,  2575,  2578,  2584,  2585,  2592,
    2605,  2615,  2622,  2639,  2646,  2671,  2673,  2671,  2695,  2739,
    2740,  2754,  2757,  2764,  2774,  2786,  2792,  2805,  2820,  2822,
    2828,  2829,  2830,  2831,  2841,  2848,  2851,  2857,  2860,  2865,
    2874,  2877,  2881,  2888,  2891,  2894,  2897,  2900,  2903,  2906,
    2907,  2908,  2909,  2910,  2911,  2912,  2913,  2914,  2916,  2920,
    2924,  2928,  2932,  2936,  2940,  2944,  2947,  2950,  2953,  2956,
    2959,  2962,  2965,  2968,  2972,  2976,  2980,  2983,  2992,  2995,
    3004,  3010,  3017,  3020,  3044,  3045,  3046,  3049,  3050,  3053,
    3059,  3060,  3061,  3062,  3063,  3064,  3069,  3073,  3077,  3081,
    3088,  3091,  3096,  3097,  3098,  3100,  3106,  3116,  3120,  3124,
    3128,  3132,  3136,  3140,  3144,  3152,  3162,  3167,  3171,  3175,
    3179,  3183,  3188,  3192,  3196,  3204,  3207,  3212,  3213,  3214,
    3219,  3220,  3221,  3229,  3232,  3237,  3238,  3242,  3243,  3248,
    3273,  3290,  3291,  3295,  3302,  3308,  3318,  3320,  3323,  3324,
    3325,  3326,  3328,  3331,  3335,  3340,  3344,  3350,  3351,  3354,
    3359,  3360,  3363,  3364,  3365,  3375,  3376,  3377,  3378,  3379,
    3380,  3381,  3382,  3386,  3392,  3394,  3413,  3421,  3428,  3429,
    3430,  3431,  3436,  3437,  3438,  3439,  3440,  3445,  3446,  3462,
    3463,  3464,  3465,  3466,  3467,  3468,  3469,  3470,  3471,  3473,
    3474,  3475,  3476,  3481,  3484,  3493,  3494,  3495,  3496,  3497,
    3498,  3502,  3503,  3517
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
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
  "LVARCHAR", "DELIMITER", "DROP_VIEW", "EXCLUSIVE", "GREATER_THAN_EQ",
  "INTO_TEMP", "DATABASE", "DATETIME", "DISTINCT", "FRACTION", "GROUP_BY",
  "INTERVAL", "NOT_LIKE", "NOT_ILIKE", "NOT_NULL", "RESOURCE", "SMALLINT",
  "IS_NULL", "LESS_THAN_EQ", "BETWEEN", "CLOSE_BRACKET", "CONNECT",
  "KW_CURRENT", "KW_DECIMAL", "KW_DEFAULT", "FGL_SYNCFIELDS", "INTEGER",
  "SERIAL8", "MATCHES", "VARCHAR", "CLOSE_SQUARE", "GREATER_THAN",
  "KW_FALSE", "NOT_IN", "OPEN_BRACKET_SELECT", "OPEN_BRACKET", "KW_DELETE",
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
  "value_expression_initial_sli_nocast", "op_fgl_expr", "atline", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,  2285,  2286,  2287,  2288,  2289,  2290,  2291,  2292,
    2293,  2294,  2295,  2296,  2297,  2298,  2299,  2300,  2301,  2302,
    2303,  2304,  1000,  1001,  1002,  1003,  1004,  1005,  1007,  1008,
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
    1494,  1496,  1498,  1501,  1505,  1507,  1531,  1532,  1534,  1541,
    1543,  1544,  1546,  1547,  1548,  1554,  1555,  1561,  1562,  1564,
    1567,  1570,  1571,  1573,  1575,  1583,  1584,  1586,  1589,  1602,
    1605,  1606,  1607,  1608,  1610,  1611,  1619,  1622,  1623,  1624,
    1628,  1630,  1634,  1635,  1637,  1638,  1640,  1644,  1647,  1649,
    1653,  1657,  1658,  1661,  1663,  1664,  1667,  1668,  1670,  1676,
    1684,  1685,  1688,  1691,  1694,  1696,  1697,  1699,  1700,  1701,
    1710,  1713,  1720,  1722,  1724,  1725,  1726,  1729,  1730,  1734,
    1740,  1741,  1744,  1753,  1758,  1762,  1763,  1764,  1766,  1769,
    1770,  1772,  1773,  1774,  1775,  1776,  1777,  1778,  1779,  1780,
    1781,  1782,  1786,  1791,  1792,  1793,  1794,  1795,  1802,  1805,
    1806,  1812,  1814,  1815,  1818,  1820,  1821,  1822,  1860,  1864,
    1871,  1872,  1875,  1880,  1887,  1888,  2236,  2266,  2279,  2280,
    2281,  2282,  2283,  2284
};
# endif

#define YYPACT_NINF -861

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-861)))

#define YYTABLE_NINF -567

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    1846,  -861,  -861,  -861,   270,  -861,   654,   270,   270,   654,
     654,   270,   661,   270,   270,   654,   661,   661,   661,   661,
    -861,   682,  -861,   270,  -861,  -861,   654,  -861,   130,   654,
     654,  -861,   654,   654,  -861,  -861,  -861,   654,  -861,  -861,
    -861,   661,   654,   690,  -861,   270,   654,   701,   496,   -79,
     654,   496,  -861,  -861,  -861,  -861,  -861,  -861,  -861,  -861,
    -861,  -861,  -861,  -861,  -861,  -861,  -861,  -861,  -861,  -861,
    -861,  -861,  -861,  -861,  -861,  -861,  -861,   283,  -861,  -861,
    -861,   -30,  -861,  -861,  -861,   102,   -14,  -861,  -861,   384,
    -861,  -861,  -861,  -114,   485,     4,   326,   176,  -861,  -861,
    -861,  -861,  -861,    14,    32,   101,   132,  -861,   -15,  -861,
    -861,  -861,  -861,   251,  -861,  -861,   200,  -861,   275,  -861,
     294,   654,   654,  -861,   107,   212,   222,  -861,   343,   277,
    -861,  -861,  -861,  -861,   403,  -861,  -861,  -861,  -861,  -861,
     376,   376,  -861,  -861,  -861,  -861,   349,   355,   336,  -861,
     635,   -56,  -861,   357,   383,  -861,  1846,   715,  -861,  -861,
     687,   270,   729,   270,   270,   692,   446,    66,   696,  -861,
    -861,   256,    75,   265,   430,  -861,  -861,  -861,  -861,  -861,
    -861,  -861,  -861,   270,  -861,  -861,   734,   270,   654,   654,
     654,   654,   -15,  -861,   267,   654,   267,   116,   419,   -35,
     500,  -861,  -861,  -861,   270,   270,   744,   270,   270,  -861,
    -861,   116,  -861,  -861,   121,   654,   762,  -861,  -861,  -861,
    -861,  -861,   346,   121,   654,  -861,   429,   432,   447,  -861,
     658,  -861,   444,  -861,   463,  -861,  -861,   538,   544,   550,
     289,   551,   553,  -861,  -861,  -861,   672,   270,   502,  -861,
    -861,  -861,   267,  -861,  -861,  -861,  -861,  1852,   270,  -861,
    -861,   267,   490,  -861,   485,  -861,   503,  -861,   511,   580,
    -861,   585,   595,   608,  -861,   -90,  -861,  -861,   -55,   690,
     -51,  -861,  -861,   518,   171,   593,   823,   686,  -861,   270,
      49,  -861,   542,  -861,   549,  -861,   569,  -861,   -50,  -861,
    -861,   571,  -861,  -861,   599,  -861,  1492,  1042,  1042,  1042,
    1042,    58,    58,    -5,   571,   558,   270,   270,   715,  -861,
     270,   814,   116,   116,   116,   -34,   672,   116,   686,   270,
    -861,   -28,   270,   -26,  -861,  -861,  -861,   648,   652,   653,
     498,   498,  -861,   656,  -861,   665,   669,   674,   678,   679,
    -861,  -861,  -861,  -861,   680,   684,   453,  -861,  -861,  -861,
    -861,  -861,    -6,  -861,  -861,    -1,   270,  -861,   270,   829,
     270,   270,   270,   270,   709,   267,   129,  -861,  -861,   116,
      59,   884,   270,  -861,   -79,   764,  -861,  -861,  -861,  -861,
     688,   609,  -861,  -861,   901,   693,   694,  -861,  -861,  -861,
     697,   498,  -861,   -79,   686,   697,   695,  -861,   699,  -861,
     561,   700,   697,  -861,   703,   704,   697,   697,   705,   706,
     707,   710,  1607,   932,   711,  1607,   913,  -861,  -861,  -861,
     712,   632,   655,  -861,  -861,  -861,  -861,  -861,  -861,  -861,
     498,  -861,   498,  -861,  -861,   881,  -861,  -861,   -98,  -861,
    -861,  -861,  -861,   428,   806,    23,  -861,   644,  -861,  -861,
    -861,   270,   270,   855,  -861,   116,   121,   121,  1492,   662,
    -861,  -861,    39,  -861,    36,  -861,  -861,    52,   663,   663,
     270,  -861,  -861,    61,   -84,   664,   720,  -861,   823,   686,
    -861,   121,   667,  -861,  -861,  -861,   671,  -861,   746,   675,
    -861,    70,  -861,   138,  -861,   289,  -861,   172,   632,   748,
    -861,  -861,  -861,  -861,   267,   954,   954,   955,  -861,  -861,
    -861,  -861,  -861,  -861,  -861,   668,  -109,   964,   965,   969,
     974,   964,   964,   977,   978,  -861,  -861,  -861,    93,  -861,
     416,  -861,   270,  -861,   267,  -861,  -861,   689,  -861,   190,
    -861,   217,   195,   204,   207,  -861,   129,  -861,   983,  -861,
    -861,   984,   988,  -861,   129,  -861,  -861,  -861,   772,   -32,
     713,   -56,  -861,  -861,  1157,   270,   982,  1492,  1492,  -861,
    -861,   714,   -56,   -91,  1878,  -861,  1492,  1492,  1492,   686,
     329,   401,  -861,  1492,  -861,  1492,  1492,  -861,  -861,   -18,
    1492,   -18,   -18,   428,  -861,   -18,   428,  -861,   -18,   686,
     686,   716,   -99,  1607,  -861,  1607,  1607,  -861,  1607,  -861,
     316,  1267,  -861,  -861,  1607,  -861,   340,  -861,  1607,   104,
    1492,   118,    47,  1492,  -861,  -861,  -861,  -861,  -861,  -861,
    1492,  1492,  1492,  1492,  -861,  1852,  -861,   270,   270,   789,
    -861,  -861,   717,  -861,  -861,  -861,   571,   809,  1492,  -861,
     270,  -861,  -861,  1042,  -861,  -861,   790,    58,    74,  -861,
      58,  1042,  -861,   632,   -23,   270,   270,   847,   116,  -861,
     116,  -861,   672,  -861,  -861,  -861,  -861,   820,   824,   209,
     610,  1020,   610,  -861,   749,   825,   218,   830,   833,   749,
     834,   835,  -861,  -861,  -861,  -861,   654,  -861,  -861,  -861,
     821,  -861,  -861,   416,  -861,   672,  -861,  -861,   270,    40,
     270,  -861,  -861,    40,    40,    40,   709,  -861,  -861,  -861,
    -861,  -861,  -861,  -861,  1026,   270,  1492,  -861,  -861,   220,
     747,  -861,   233,   250,   610,  1492,  -861,  -861,   347,   849,
     360,   279,  -861,  -161,   412,  -861,  -861,   284,   291,   319,
    -861,  -861,  -861,  1492,   320,  1492,  1492,  1492,  1492,   655,
    -861,   610,  1044,   610,   836,   428,   837,   841,   836,   109,
    -861,  -861,  -861,   837,   109,  -861,   841,  -861,  -861,  1492,
    -861,  -861,   118,  -861,  -861,   271,  1060,  -861,  -861,    50,
    -861,  -861,  -861,  -861,  -861,  -861,  -861,  -861,  1382,   270,
    -861,   805,  -861,  -861,   851,  -861,  -861,   290,  -861,  -861,
    -861,   682,  -861,  -861,  -861,  -861,  -861,  -861,  -861,  -861,
    -861,  -861,  1066,   857,  -861,  -861,  -861,  -861,  -861,  -861,
    -861,   882,  -861,  1078,   883,  -861,  -861,  1081,  -861,  -861,
     885,  -861,  -861,  -861,   871,   686,  -861,  -861,  -861,  -861,
    -861,   988,  1084,  -861,    40,  -861,  -861,  -861,  -861,  -861,
    -861,   878,   772,     7,  -861,  1492,   270,  -861,  -861,  -861,
       7,   498,   793,  -861,  -861,  -861,  -861,  1492,  -861,  -861,
    -861,  -861,   891,  -861,   893,   895,   896,   900,  -861,   902,
    -861,    93,  -861,    93,  -861,    93,  -861,  -861,    99,  -861,
     332,  -861,  -861,  -861,   334,  -861,   827,   333,  -861,  -861,
    -861,   118,  -861,  -861,  -861,   118,  -861,   118,   270,  -861,
     335,  -861,  -861,  -861,   654,   402,   854,  1042,   270,  -861,
    -861,   908,  1106,   813,  -861,  -861,  -861,   914,  -861,   116,
     919,  -861,  -861,  -861,  -861,  -861,  -861,  -861,   897,   921,
     831,   610,  -861,  -861,  -861,  -861,  -861,  -861,   832,  -861,
    -861,  -861,  -861,  -861,  -861,  -861,   109,  -861,  1492,  -861,
     536,   356,   596,   898,  -861,  1382,    95,  -861,    46,    84,
     686,   686,  -861,   -44,  -861,  -861,   906,     9,   111,   368,
     772,  -861,   922,   610,  -861,   373,  -861,   118,  -861,   610,
    -861,   610,  -861,  -861,  -861,  -861,   118,   118,  -861,   148,
     148,    80,   270,  -861,  -861,  -861,    55,  -861,  -861,  -861,
     848,  -861,   838,   259,   632,   632,  -861,  -861,  -861,  -861,
    -861,   899,   270,   840,   948,  -861,  -861,  -861,  -861,  -861,
    -861,   606,  -861,  -861,   741,   627,   654,    95,   842,   843,
     167,  -861,  -861,  -861,    84,    94,  -861,   -79,  -861,   971,
    -861,    88,   270,  -861,   118,  -861,  -861,   118,    91,   686,
     686,   654,  -861,  -861,  -861,   772,   -56,  -861,  -861,  -861,
    -861,   860,  -861,   241,   971,   765,   785,  -861,   632,   632,
     157,  -861,  1492,    88,  -861,  -861,  -861,  -861,  -861,  -861,
    -861,     7,  -861,   854,  -861
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
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

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -861,  -861,  -861,  -861,  -861,  -861,  -280,   660,   466,  -861,
    -254,  -193,  -861,  -861,  -861,  -861,   586,  -861,   577,   287,
      79,  -861,   281,   581,  -861,   426,    60,   505,   433,   959,
    -113,  -861,  -861,   892,  -861,  -234,  -861,  -861,  -861,  -187,
    -861,  -861,  -175,  -861,  -861,  -861,  -861,  -302,  -861,   910,
     826,  -861,  -861,  -861,  -861,  -861,  -861,  -861,   512,  -861,
     177,  -861,  -861,  -861,  -861,  -861,  -861,  -861,  -861,  -861,
    1113,  -861,  1114,  -861,   950,  1029,  -861,  -141,   718,  -861,
    -861,  -861,  -861,  -861,  -861,   494,  -861,  -861,   224,  -861,
     324,  -121,  -861,  -861,  -861,  -861,  -861,   454,  -861,  -861,
    -861,  -861,  -861,   -11,   180,  -861,  -861,  -860,   160,  -771,
    -750,  -861,   194,  -267,   574,   578,   766,  -861,   413,   404,
     409,   136,  -158,  -861,  -861,  -861,  -861,   189,  -861,   548,
    -861,  -861,  -861,   495,  -861,   681,   150,  -861,   -20,  -461,
    -167,  -779,   169,   924,   178,  -520,  -861,  -306,  -536,  -861,
    -861,   990,   743,  -861,  -861,  -861,  -861,  -861,  -861,  -861,
    -861,  -861,  -861,   103,  -861,  -861,  -861,  -861,   144,   358,
    -861,  -861,  -861,  -861,  -861,  -861,    97,  -861,   139,   928,
    -112,  -363,  -535,  -688,  -861,   556,  -242,  -861,   629,  -491,
     520,   471,  -861,  -861,  -861,   439,   248,   -27,  -861,    43,
    -861,   768,    -4,   740,   321,  -861,  -861,  -861,  -861,  -861,
    1074,  -861,  1217,  -861,  -861,  -861,   916,  -861,  -554,  -861,
    -861,  -515,  -861,  -861,  -861,  -181,  -861,  -861,  1086
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

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      85,   110,    89,    90,    91,    89,    89,    94,    97,    98,
      98,    89,    97,    97,    97,    97,   126,   111,   703,   112,
     431,   571,    89,   669,   506,    89,    89,   364,    89,    89,
     281,   481,   750,    89,   525,   526,   736,    97,    89,   128,
     582,   130,    89,    84,   299,   246,    89,   745,   873,    87,
      84,    84,    92,    93,   477,   478,   479,   880,   102,    84,
     262,   125,    84,    84,   472,   476,   476,   476,   476,   113,
      84,   363,   116,   117,   986,   118,   119,   334,    84,    84,
     120,   276,   314,   276,    84,   124,    86,  1025,    84,   131,
     125,  1089,    84,   152,   125,   581,   389,   193,    84,   702,
     756,   286,   973,   859,   860,   887,   691,   732,   392,   746,
     374,   820,   389,    84,   392,   391,   772,    89,    89,   326,
      84,   791,   125,   956,   392,    84,   393,   107,   631,   394,
     959,   488,   218,   114,   611,   609,   612,   583,   157,   158,
    1019,    37,   381,   590,  1019,   376,   989,  1020,   262,   378,
     464,  1020,    84,   227,    86,   500,   842,   231,   233,   234,
     235,   150,   584,   250,   199,   200,   504,   257,   260,   257,
     760,    84,   511,    86,   513,   160,   990,   219,   733,   265,
     165,   274,   267,   268,    89,    89,    89,    89,   692,   375,
     257,    89,   257,   284,   541,   632,  1078,  1038,   773,   543,
     291,   293,   295,   296,   130,   609,  1019,   284,   879,   668,
     111,    89,   566,  1020,    48,   761,   287,   220,   558,   111,
      89,  1100,   673,   646,   375,   912,   657,    51,   379,   465,
     912,   270,   270,   270,   270,   898,   662,   900,   277,   559,
     560,   603,  1039,   250,   606,   505,   489,   734,   257,   201,
    1061,   332,   664,   514,   260,   762,   466,   257,   304,   909,
      84,   666,   557,   756,   909,   787,   934,   315,   821,    84,
     679,    84,   202,   542,    84,   284,   927,   917,   544,   161,
     384,   247,  1040,   155,   458,   457,   658,   561,   579,  1082,
     258,  1097,  1090,   585,   797,   401,  1042,   183,   654,   156,
     594,   788,   647,   789,   597,   598,   567,   484,   484,   188,
     717,   401,   492,   493,   227,   663,   495,   497,   284,   284,
     284,   816,   753,   284,  1090,   510,   656,   189,   250,  1060,
     660,   663,   738,   792,   861,   738,   738,  1022,   681,   685,
     667,  1084,   862,   928,   748,   738,   752,   480,   300,   680,
     674,   738,   798,   738,   738,   716,   939,  1110,   738,  1043,
    1027,  1113,   545,  1056,   546,   548,   551,   551,   551,   551,
    1021,   257,   683,  1026,  1021,   284,   568,  1026,   570,   782,
     828,   970,  1081,   970,   682,   970,   426,   815,   790,  1027,
     719,   800,   426,  1027,   908,   723,   190,   381,   801,   802,
     803,   804,   426,   793,   724,   279,   980,   725,   794,   831,
     981,   955,   982,   857,  1111,   237,   472,   680,   846,   238,
     874,   476,   912,   562,   237,  1010,   237,   191,   238,   476,
     238,   262,   775,   877,   775,   775,  1021,   775,   307,   308,
     309,   310,   311,   775,   239,   184,   185,   775,   237,   206,
     878,   680,   238,   239,   186,   239,   909,   293,   651,   653,
     207,   284,   111,   111,   382,   187,   194,  1049,   661,   720,
     813,   252,   721,  1052,   720,  1053,   484,   239,   819,   886,
     261,   918,   195,   720,   889,   381,   720,   111,   832,   241,
     196,   890,  1051,   722,   472,   242,  1104,   847,   241,   875,
     241,  1054,  1055,   472,   242,   204,   242,   633,   780,   197,
     257,   826,   875,   827,   785,   205,   381,  1105,   919,   891,
     893,   892,   241,   894,   895,   896,   897,   920,   242,   875,
     403,   779,   975,   979,   977,   984,   518,   206,   260,  1047,
     257,   634,   635,   636,   637,   638,   639,   916,   207,   518,
     921,  1102,  -529,   704,   403,   784,   922,   923,   875,  1095,
    -504,   924,  1096,   875,   389,   390,   932,   391,  1046,   519,
     875,   740,  1066,  1050,   208,   960,   392,   520,   393,   705,
     919,   394,   519,   938,   166,   167,   209,   588,   706,   920,
     520,   211,   989,   521,   168,   169,   170,   589,   875,   875,
     535,   536,   537,   919,   707,   237,   521,   522,   214,   238,
     708,   976,   920,   976,   985,   216,   523,   312,   922,   923,
     522,   206,   990,   924,  1101,   609,   881,   524,   799,   523,
     395,   396,   207,   957,   239,   135,   397,   398,   217,   881,
     524,   922,   923,   457,   807,   962,   924,   663,   503,   709,
     215,   507,   678,   991,   223,   710,   812,   538,    84,   588,
      86,   240,   162,   484,   817,    84,   484,    95,   399,   589,
     588,   823,   824,   163,   284,   640,   284,   164,   224,   241,
     589,   698,   699,   999,   641,   242,    84,   518,   107,   389,
     390,   136,   391,   230,    84,   476,   125,   137,   236,   251,
     755,   392,    89,   393,  1086,   132,   394,   133,   171,   264,
     285,   888,   138,   642,   858,   289,   551,   139,   643,    84,
     519,   226,   316,  1034,  1035,   317,   318,   140,   520,   319,
     141,   872,   400,    84,   142,   232,  1013,   320,    84,   143,
     266,   321,   172,   932,   521,   971,  1014,   972,    84,   854,
     294,   776,   777,   322,   778,   395,   396,   173,   522,   323,
     783,   397,   398,   401,   786,   324,   327,   523,   328,   144,
     271,   272,   273,   402,   329,   403,   404,   145,   524,   405,
     406,   332,   500,   919,   103,   104,   105,   106,   366,   369,
     765,   766,   920,   399,   767,   370,   368,   768,   407,   833,
     371,   940,   867,   868,   869,   933,  1015,   408,   409,   123,
     372,   380,  1098,  1099,   410,   411,  1073,   111,    84,   588,
     496,   922,   923,   373,   384,   412,   924,   387,   413,   589,
     414,   415,   834,    84,   416,   547,   417,  1076,   418,   461,
     835,   419,   462,   919,   420,   421,   422,   463,   423,   424,
     466,   425,   920,   919,   426,   491,   836,   400,   467,    84,
     472,   652,   920,   515,   427,   428,   429,   516,   517,   430,
     837,   527,   958,   555,   919,  1016,   552,   553,   554,   838,
     528,   922,   923,   920,   529,  1074,   924,   569,   401,   530,
     839,   922,   923,   531,   532,   533,   924,   572,   402,   534,
     403,   404,   575,   574,   405,   406,  1077,   576,   577,   578,
     586,   403,   922,   923,   587,   593,   607,   924,   595,   596,
     599,   600,   601,   407,   983,   602,   605,   608,   609,   610,
      89,   645,   408,   409,  1000,   389,   390,   648,   391,   410,
     411,   658,   663,   670,   671,   284,   677,   392,   684,   393,
     412,  1075,   394,   413,   678,   414,   415,   686,   689,   416,
     675,   417,  1032,   418,   676,   690,   419,   693,   695,   420,
     421,   422,   696,   423,   424,  1108,   425,   697,   138,   426,
     700,   701,   718,   139,  1024,  1033,   727,   728,   919,   427,
     428,   429,   729,   140,   430,  1109,   141,   920,   381,  1032,
     142,   395,   396,   741,   808,   143,   735,   397,   398,   747,
     809,   744,   919,   771,   814,    89,    89,    89,  1024,   706,
     829,   920,  1033,   841,   830,   845,   922,   923,   843,   871,
     848,   924,   919,   849,   851,   852,   855,  1032,  1070,   399,
     876,   920,  -282,   613,  1032,   389,   390,   899,   391,   884,
     922,   923,    89,   901,   903,   924,    89,   392,   905,   393,
    1033,  1085,   394,   926,   934,   614,   937,  1033,  1070,   941,
     922,   923,   942,   615,   616,   924,  1032,    89,  -282,   617,
    -282,   944,   943,   946,   947,   948,   949,   952,   954,   618,
     961,   963,   619,   964,   620,   965,   966,   742,   743,  1033,
     967,   978,   968,   400,   997,   621,   622,   751,  1001,  1002,
    1003,   395,   396,   757,  1004,   758,   759,   397,   398,  1006,
     764,  1008,  1048,  1007,  1017,   623,   990,  1064,  1009,  1011,
    1067,  1065,  1071,  1072,   401,  1087,   818,  1079,  1080,  1103,
     665,   731,   726,   624,   402,   953,   403,   404,   951,   399,
     405,   406,   870,   866,  1107,   278,   367,   331,   512,   806,
     389,   390,  1018,   391,   153,   154,   305,   856,   625,   407,
     213,   825,   392,  1005,   393,   626,  1037,   394,   408,   409,
    1059,   627,   628,   769,   655,   410,   411,  1036,   770,   604,
     915,   907,   913,   805,   850,  1063,   412,   688,   297,   413,
    1062,   414,   415,   377,   650,   416,  1112,   417,  1083,   418,
    1114,  1094,   419,   950,   810,   420,   421,   422,   460,   754,
     424,   885,   425,   914,  1012,   426,   395,   396,   672,   974,
     225,   101,   397,   398,   494,   427,   428,   429,   222,     0,
     430,     0,     0,     0,   401,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   402,     0,   403,   468,     0,     0,
       0,   406,     0,     0,   399,     0,     0,     0,     0,     0,
     389,   390,     0,   391,     0,     0,     0,     0,   473,   407,
       0,     0,   392,     0,   393,     0,     0,   394,   408,   409,
       0,     0,     0,     0,     0,   410,   411,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   412,     0,     0,   413,
       0,   414,   415,     0,     0,   416,     0,   417,     0,   418,
       0,     0,   419,     0,     0,   420,   421,   422,     0,     0,
     424,     0,   425,     0,     0,   426,   395,   396,     0,     0,
       0,     0,   397,   398,     0,   427,   428,   429,     0,     0,
     430,     0,     0,     0,     0,     0,     0,   737,     0,   401,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   402,
       0,   403,   468,     0,   399,     0,   406,     0,     0,     0,
       0,     0,     0,     0,     0,   389,   390,     0,   391,     0,
       0,     0,     0,     0,   407,     0,     0,   392,     0,   393,
       0,     0,   394,   408,   409,     0,     0,     0,     0,     0,
     410,   411,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   412,     0,     0,   413,     0,   414,   415,     0,     0,
     416,     0,   417,     0,   418,     0,     0,   419,     0,     0,
     420,   421,   422,     0,     0,   424,     0,   425,     0,     0,
     426,   395,   396,     0,     0,     0,     0,   397,   398,     0,
     427,   428,   429,     0,     0,   430,     0,     0,     0,   401,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   402,
       0,   403,   468,     0,     0,     0,   406,     0,     0,   399,
       0,     0,     0,     0,     0,   389,   390,     0,   391,     0,
       0,     0,     0,   781,   407,     0,     0,   392,     0,   393,
       0,     0,   394,   408,   409,     0,     0,     0,     0,     0,
     410,   411,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   412,     0,     0,   413,     0,   414,   415,     0,     0,
     416,     0,   417,     0,   418,     0,     0,   419,     0,     0,
     420,   421,   422,     0,     0,   424,     0,   425,     0,     0,
     426,   395,   396,     0,     0,     0,     0,   397,   398,     0,
     427,   428,   429,     0,     0,   430,     0,     0,     0,     0,
       0,     0,     0,     0,   401,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   402,     0,   403,   468,     0,   399,
       0,   406,     0,     0,     0,     0,     0,     0,     0,     0,
     389,   390,     0,   391,     0,     0,     0,     0,   929,   407,
       0,     0,   392,     0,   393,     0,     0,   394,   408,   409,
       0,     0,     0,     0,     0,   410,   411,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   412,     0,     0,   413,
       0,   414,   415,     0,     0,   416,     0,   417,     0,   418,
       0,     0,   419,     0,     0,   420,   421,   422,     0,     0,
     424,     0,   425,     0,     0,   426,   395,   396,     0,     0,
       0,     0,   397,   398,     0,   427,   428,   429,     0,     0,
     430,     0,     0,     0,   401,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   402,     0,   403,   468,     0,     0,
       0,   406,     0,     0,   399,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   407,
       0,     0,     0,     0,     0,     0,     0,     0,   408,   409,
       0,     0,     0,     0,     0,   410,   411,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   412,     0,     0,   413,
       0,   414,   415,     0,     0,   416,     0,   417,     0,   418,
       0,     0,   419,     0,     0,   420,   421,   422,     0,     0,
     424,     0,   425,     0,     0,   426,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   427,   428,   429,     0,     0,
     430,     0,     0,     0,     0,     0,     0,     0,     0,   401,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   402,
       0,   403,   468,     0,     0,     0,   406,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   407,     0,  -566,     1,     0,     0,
       0,     0,     0,   408,   409,     0,     0,     0,     0,     0,
     410,   411,  -566,     0,     0,     0,     0,     0,     0,     0,
       0,   412,     0,     0,   413,     0,   414,   415,     0,     0,
     416,     0,   417,     0,   418,     0,     0,   419,     0,     0,
     420,   421,     0,     0,     0,   424,     0,     0,     0,     0,
     426,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     427,   428,   429,     2,     3,   430,     0,     0,     4,     0,
       5,     0,     0,     6,     7,     0,     8,     9,    10,     0,
       0,     0,     0,    11,    12,     0,     0,     0,     0,     0,
       0,     0,     0,    13,    14,     0,     0,    15,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   335,     0,
       0,     0,     0,     0,     0,     0,     0,    16,    17,    18,
      19,     0,    20,    21,    22,    23,    24,    25,    26,     0,
       0,    27,     0,     0,    28,     0,    29,    30,     0,     0,
       0,    31,    32,     0,     0,     0,     0,     0,    33,    34,
      35,    36,    37,    38,     0,     0,    39,     0,     0,     0,
       0,     0,    40,    41,     0,     0,    42,     0,     0,    43,
       0,    44,    45,     0,     0,     0,   336,     0,    46,   337,
     338,   339,    47,     0,     0,     0,     0,     0,     0,   340,
     613,     0,     0,   341,     0,     0,     0,     0,   342,     0,
       0,     0,     0,     0,     0,   343,     0,     0,   344,   345,
       0,   346,   614,     0,     0,     0,     0,     0,     0,     0,
     615,   616,     0,     0,     0,    48,   617,    49,   747,     0,
      50,     0,     0,     0,   347,     0,   618,     0,    51,   619,
       0,   620,     0,   348,     0,     0,     0,   349,     0,     0,
       0,     0,   621,   622,   350,     0,   351,     0,     0,     0,
       0,     0,     0,     0,     0,   352,     0,   353,     0,     0,
       0,     0,   623,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     624,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  -305,     0,     0,   354,     0,     0,   355,     0,
       0,     0,     0,     0,     0,   625,     0,     0,     0,     0,
       0,     0,   626,     0,  -305,     0,     0,     0,   627,   628
};

static const yytype_int16 yycheck[] =
{
       4,    21,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    43,    21,   538,    23,
     287,   384,    26,   484,   326,    29,    30,   261,    32,    33,
     197,   311,   586,    37,   340,   341,   571,    41,    42,    43,
     403,    45,    46,     4,   211,   166,    50,   582,   736,     6,
       4,     4,     9,    10,   308,   309,   310,   745,    15,     4,
     173,     6,     4,     4,   306,   307,   308,   309,   310,    26,
       4,   258,    29,    30,   934,    32,    33,   252,     4,     4,
      37,   194,   223,   196,     4,    42,     6,     3,     4,    46,
       6,     3,     4,    50,     6,   401,     3,   108,     4,     6,
     591,   136,     3,    63,    64,   266,   215,   568,    15,   200,
     200,   134,     3,     4,    15,     6,   215,   121,   122,   240,
       4,     3,     6,   873,    15,     4,    17,     6,   226,    20,
     880,   136,   188,     3,   440,   296,   442,   404,   168,   169,
      49,   156,   226,   410,    49,   200,   190,    56,   261,   200,
     200,    56,     4,   157,     6,   322,   692,   161,   162,   163,
     164,   240,   404,   167,   121,   122,   200,   171,   172,   173,
     188,     4,   200,     6,   200,    73,   220,   233,   210,   183,
     294,   192,   186,   187,   188,   189,   190,   191,   297,   279,
     194,   195,   196,   197,   200,   293,  1056,   188,   297,   200,
     204,   205,   206,   207,   208,   296,    49,   211,   744,   293,
     214,   215,   379,    56,   229,   233,   251,   273,    89,   223,
     224,  1081,   489,   200,   279,   779,   468,   242,   279,   279,
     784,   188,   189,   190,   191,   771,   200,   773,   195,   110,
     111,   422,   233,   247,   425,   279,   251,   279,   252,   142,
    1021,   279,   200,   279,   258,   273,   279,   261,   215,   779,
       4,   200,   375,   754,   784,   161,   259,   224,   291,     4,
     200,     4,   165,   279,     4,   279,   226,   792,   279,   293,
     231,   215,   273,     0,   235,   289,   279,   158,   400,  1060,
     215,   200,  1071,   405,   247,   202,   185,   293,   465,    16,
     412,   197,   279,   199,   416,   417,   247,   311,   312,   295,
     544,   202,   316,   317,   318,   279,   320,   321,   322,   323,
     324,   247,   589,   327,  1103,   329,   467,   295,   332,   249,
     291,   279,   574,   215,   294,   577,   578,   291,   200,   514,
     279,   247,   302,   293,   586,   587,   588,   289,   227,   279,
     491,   593,   305,   595,   596,   542,   817,   200,   600,   248,
     305,  1111,   366,   215,   368,   369,   370,   371,   372,   373,
     279,   375,   200,   289,   279,   379,   380,   289,   382,   621,
     682,   901,   215,   903,   505,   905,   293,   667,   630,   305,
     200,   633,   293,   305,   285,   200,   295,   226,   640,   641,
     642,   643,   293,   285,   200,   289,   921,   200,   290,   200,
     925,   872,   927,   715,  1102,   159,   658,   279,   200,   163,
     200,   663,   976,   294,   159,   961,   159,   295,   163,   671,
     163,   544,   613,   200,   615,   616,   279,   618,    92,    93,
      94,    95,    96,   624,   188,   119,   120,   628,   159,   278,
     200,   279,   163,   188,   278,   188,   976,   461,   462,   463,
     289,   465,   466,   467,   293,   289,   215,  1003,   472,   279,
     663,   215,   255,  1009,   279,  1011,   480,   188,   671,   200,
     215,   210,   282,   279,   200,   226,   279,   491,   279,   233,
     215,   200,  1007,   276,   736,   239,   255,   279,   233,   279,
     233,  1016,  1017,   745,   239,   293,   239,    79,   620,   215,
     514,   678,   279,   680,   626,   293,   226,   276,   247,   200,
     200,   763,   233,   765,   766,   767,   768,   256,   239,   279,
     214,   215,   200,   200,   200,   200,   189,   278,   542,  1000,
     544,   113,   114,   115,   116,   117,   118,   789,   289,   189,
     279,  1086,   293,   137,   214,   215,   285,   286,   279,  1074,
     200,   290,  1077,   279,     3,     4,   808,     6,   200,   222,
     279,   575,  1033,   200,   297,   881,    15,   230,    17,   163,
     247,    20,   222,   293,    99,   100,   183,   258,   172,   256,
     230,   215,   190,   246,   109,   110,   111,   268,   279,   279,
     147,   148,   149,   247,   188,   159,   246,   260,   259,   163,
     194,   279,   256,   279,   279,   279,   269,   271,   285,   286,
     260,   278,   220,   290,  1085,   296,   279,   280,   632,   269,
      69,    70,   289,   875,   188,   139,    75,    76,     3,   279,
     280,   285,   286,   647,   648,   887,   290,   279,   324,   233,
     295,   327,   279,   251,   297,   239,   660,   204,     4,   258,
       6,   215,   278,   667,   668,     4,   670,     6,   107,   268,
     258,   675,   676,   289,   678,   247,   680,   293,   295,   233,
     268,   531,   532,   937,   256,   239,     4,   189,     6,     3,
       4,   195,     6,     6,     4,   937,     6,   201,     6,     3,
     299,    15,   706,    17,  1067,     4,    20,     6,   223,   279,
     291,   299,   216,   285,   718,   215,   720,   221,   290,     4,
     222,     6,   293,   990,   991,   293,   279,   231,   230,    71,
     234,   735,   171,     4,   238,     6,   978,   293,     4,   243,
       6,   278,   257,   985,   246,   903,   210,   905,     4,   706,
       6,   615,   616,   215,   618,    69,    70,   272,   260,   215,
     624,    75,    76,   202,   628,   215,   215,   269,   215,   273,
     189,   190,   191,   212,   102,   214,   215,   281,   280,   218,
     219,   279,   949,   247,    16,    17,    18,    19,   298,   278,
     601,   602,   256,   107,   605,   215,   293,   608,   237,   189,
     215,   821,   723,   724,   725,   809,   210,   246,   247,    41,
     215,   293,  1079,  1080,   253,   254,   210,   821,     4,   258,
       6,   285,   286,   215,   231,   264,   290,     4,   267,   268,
     269,   270,   222,     4,   273,     6,   275,   210,   277,   297,
     230,   280,   293,   247,   283,   284,   285,   278,   287,   288,
     279,   290,   256,   247,   293,   297,   246,   171,   259,     4,
    1102,     6,   256,   215,   303,   304,   305,   215,   215,   308,
     260,   215,   876,   164,   247,   279,   371,   372,   373,   269,
     215,   285,   286,   256,   215,   279,   290,     3,   202,   215,
     280,   285,   286,   215,   215,   215,   290,   133,   212,   215,
     214,   215,   293,   215,   218,   219,   279,     6,   215,   215,
     215,   214,   285,   286,   215,   215,     3,   290,   215,   215,
     215,   215,   215,   237,   928,   215,   215,   215,   296,   274,
     934,   125,   246,   247,   938,     3,     4,   293,     6,   253,
     254,   279,   279,   279,   224,   949,   200,    15,   200,    17,
     264,   210,    20,   267,   279,   269,   270,     3,     3,   273,
     293,   275,   989,   277,   293,   297,   280,     3,     3,   283,
     284,   285,     3,   287,   288,   210,   290,     3,   216,   293,
       3,     3,   293,   221,   988,   989,     3,     3,   247,   303,
     304,   305,     4,   231,   308,   210,   234,   256,   226,  1026,
     238,    69,    70,    21,   215,   243,   293,    75,    76,   200,
     293,   297,   247,   297,   224,  1019,  1020,  1021,  1022,   172,
     200,   256,  1026,     3,   200,   200,   285,   286,   279,     3,
     200,   290,   247,   200,   200,   200,   215,  1064,  1042,   107,
     293,   256,   161,   162,  1071,     3,     4,     3,     6,   200,
     285,   286,  1056,   217,   217,   290,  1060,    15,   217,    17,
    1064,  1065,    20,     3,   259,   184,   215,  1071,  1072,     3,
     285,   286,   215,   192,   193,   290,  1103,  1081,   197,   198,
     199,     3,   200,   200,     3,   200,   215,     3,   210,   208,
     297,   200,   211,   200,   213,   200,   200,   577,   578,  1103,
     200,   274,   200,   171,   250,   224,   225,   587,   200,     3,
     297,    69,    70,   593,   200,   595,   596,    75,    76,   200,
     600,   200,   200,   226,   226,   244,   220,   279,   297,   297,
     231,   293,   292,   185,   202,   164,   670,   295,   295,   279,
     480,   564,   556,   262,   212,   864,   214,   215,   861,   107,
     218,   219,   726,   720,  1094,   196,   264,   247,   332,   647,
       3,     4,   985,     6,    51,    51,   216,   713,   287,   237,
     141,   677,    15,   949,    17,   294,   996,    20,   246,   247,
    1020,   300,   301,   609,   466,   253,   254,   993,   610,   423,
     786,   778,   783,   645,   699,  1026,   264,   516,   208,   267,
    1022,   269,   270,   279,   461,   273,  1103,   275,  1064,   277,
    1113,  1072,   280,   855,   658,   283,   284,   285,   290,   590,
     288,   750,   290,   784,   976,   293,    69,    70,   488,   908,
     156,    14,    75,    76,   318,   303,   304,   305,   152,    -1,
     308,    -1,    -1,    -1,   202,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   212,    -1,   214,   215,    -1,    -1,
      -1,   219,    -1,    -1,   107,    -1,    -1,    -1,    -1,    -1,
       3,     4,    -1,     6,    -1,    -1,    -1,    -1,   236,   237,
      -1,    -1,    15,    -1,    17,    -1,    -1,    20,   246,   247,
      -1,    -1,    -1,    -1,    -1,   253,   254,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   264,    -1,    -1,   267,
      -1,   269,   270,    -1,    -1,   273,    -1,   275,    -1,   277,
      -1,    -1,   280,    -1,    -1,   283,   284,   285,    -1,    -1,
     288,    -1,   290,    -1,    -1,   293,    69,    70,    -1,    -1,
      -1,    -1,    75,    76,    -1,   303,   304,   305,    -1,    -1,
     308,    -1,    -1,    -1,    -1,    -1,    -1,   200,    -1,   202,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   212,
      -1,   214,   215,    -1,   107,    -1,   219,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,     3,     4,    -1,     6,    -1,
      -1,    -1,    -1,    -1,   237,    -1,    -1,    15,    -1,    17,
      -1,    -1,    20,   246,   247,    -1,    -1,    -1,    -1,    -1,
     253,   254,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   264,    -1,    -1,   267,    -1,   269,   270,    -1,    -1,
     273,    -1,   275,    -1,   277,    -1,    -1,   280,    -1,    -1,
     283,   284,   285,    -1,    -1,   288,    -1,   290,    -1,    -1,
     293,    69,    70,    -1,    -1,    -1,    -1,    75,    76,    -1,
     303,   304,   305,    -1,    -1,   308,    -1,    -1,    -1,   202,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   212,
      -1,   214,   215,    -1,    -1,    -1,   219,    -1,    -1,   107,
      -1,    -1,    -1,    -1,    -1,     3,     4,    -1,     6,    -1,
      -1,    -1,    -1,   236,   237,    -1,    -1,    15,    -1,    17,
      -1,    -1,    20,   246,   247,    -1,    -1,    -1,    -1,    -1,
     253,   254,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   264,    -1,    -1,   267,    -1,   269,   270,    -1,    -1,
     273,    -1,   275,    -1,   277,    -1,    -1,   280,    -1,    -1,
     283,   284,   285,    -1,    -1,   288,    -1,   290,    -1,    -1,
     293,    69,    70,    -1,    -1,    -1,    -1,    75,    76,    -1,
     303,   304,   305,    -1,    -1,   308,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   202,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   212,    -1,   214,   215,    -1,   107,
      -1,   219,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
       3,     4,    -1,     6,    -1,    -1,    -1,    -1,   236,   237,
      -1,    -1,    15,    -1,    17,    -1,    -1,    20,   246,   247,
      -1,    -1,    -1,    -1,    -1,   253,   254,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   264,    -1,    -1,   267,
      -1,   269,   270,    -1,    -1,   273,    -1,   275,    -1,   277,
      -1,    -1,   280,    -1,    -1,   283,   284,   285,    -1,    -1,
     288,    -1,   290,    -1,    -1,   293,    69,    70,    -1,    -1,
      -1,    -1,    75,    76,    -1,   303,   304,   305,    -1,    -1,
     308,    -1,    -1,    -1,   202,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   212,    -1,   214,   215,    -1,    -1,
      -1,   219,    -1,    -1,   107,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   237,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   246,   247,
      -1,    -1,    -1,    -1,    -1,   253,   254,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   264,    -1,    -1,   267,
      -1,   269,   270,    -1,    -1,   273,    -1,   275,    -1,   277,
      -1,    -1,   280,    -1,    -1,   283,   284,   285,    -1,    -1,
     288,    -1,   290,    -1,    -1,   293,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   303,   304,   305,    -1,    -1,
     308,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   202,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   212,
      -1,   214,   215,    -1,    -1,    -1,   219,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   237,    -1,     0,     1,    -1,    -1,
      -1,    -1,    -1,   246,   247,    -1,    -1,    -1,    -1,    -1,
     253,   254,    16,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   264,    -1,    -1,   267,    -1,   269,   270,    -1,    -1,
     273,    -1,   275,    -1,   277,    -1,    -1,   280,    -1,    -1,
     283,   284,    -1,    -1,    -1,   288,    -1,    -1,    -1,    -1,
     293,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     303,   304,   305,    67,    68,   308,    -1,    -1,    72,    -1,
      74,    -1,    -1,    77,    78,    -1,    80,    81,    82,    -1,
      -1,    -1,    -1,    87,    88,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    97,    98,    -1,    -1,   101,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   106,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   121,   122,   123,
     124,    -1,   126,   127,   128,   129,   130,   131,   132,    -1,
      -1,   135,    -1,    -1,   138,    -1,   140,   141,    -1,    -1,
      -1,   145,   146,    -1,    -1,    -1,    -1,    -1,   152,   153,
     154,   155,   156,   157,    -1,    -1,   160,    -1,    -1,    -1,
      -1,    -1,   166,   167,    -1,    -1,   170,    -1,    -1,   173,
      -1,   175,   176,    -1,    -1,    -1,   174,    -1,   182,   177,
     178,   179,   186,    -1,    -1,    -1,    -1,    -1,    -1,   187,
     162,    -1,    -1,   191,    -1,    -1,    -1,    -1,   196,    -1,
      -1,    -1,    -1,    -1,    -1,   203,    -1,    -1,   206,   207,
      -1,   209,   184,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     192,   193,    -1,    -1,    -1,   229,   198,   231,   200,    -1,
     234,    -1,    -1,    -1,   232,    -1,   208,    -1,   242,   211,
      -1,   213,    -1,   241,    -1,    -1,    -1,   245,    -1,    -1,
      -1,    -1,   224,   225,   252,    -1,   254,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   263,    -1,   265,    -1,    -1,
      -1,    -1,   244,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     262,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   274,    -1,    -1,   303,    -1,    -1,   306,    -1,
      -1,    -1,    -1,    -1,    -1,   287,    -1,    -1,    -1,    -1,
      -1,    -1,   294,    -1,   296,    -1,    -1,    -1,   300,   301
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
{
       0,     1,    67,    68,    72,    74,    77,    78,    80,    81,
      82,    87,    88,    97,    98,   101,   121,   122,   123,   124,
     126,   127,   128,   129,   130,   131,   132,   135,   138,   140,
     141,   145,   146,   152,   153,   154,   155,   156,   157,   160,
     166,   167,   170,   173,   175,   176,   182,   186,   229,   231,
     234,   242,   315,   326,   327,   328,   329,   338,   345,   365,
     366,   375,   376,   377,   379,   380,   381,   382,   383,   393,
     413,   417,   463,   464,   467,   468,   486,   522,   523,   524,
     525,   527,   531,   533,     4,   516,     6,   513,   514,   516,
     516,   516,   513,   513,   516,     6,   515,   516,   516,   521,
     526,   526,   513,   515,   515,   515,   515,     6,   414,   415,
     452,   516,   516,   513,     3,   541,   513,   513,   513,   513,
     513,   542,   367,   515,   513,     6,   511,   512,   516,   465,
     516,   513,     4,     6,   519,   139,   195,   201,   216,   221,
     231,   234,   238,   243,   273,   281,   384,   386,   387,   388,
     240,   495,   513,   384,   386,     0,    16,   168,   169,   528,
      73,   293,   278,   289,   293,   294,    99,   100,   109,   110,
     111,   223,   257,   272,   346,   347,   348,   351,   354,   357,
     358,   359,   362,   293,   119,   120,   278,   289,   295,   295,
     295,   295,   416,   417,   215,   282,   215,   215,   394,   513,
     513,   142,   165,   469,   293,   293,   278,   289,   297,   183,
     378,   215,   389,   389,   259,   295,   279,     3,   188,   233,
     273,   496,   542,   297,   295,   524,     6,   516,   529,   530,
       6,   516,     6,   516,   516,   516,     6,   159,   163,   188,
     215,   233,   239,   397,   398,   403,   405,   215,   363,   364,
     516,     3,   215,   344,   356,   405,   407,   516,   215,   353,
     516,   215,   344,   349,   279,   516,     6,   516,   516,   337,
     513,   337,   337,   337,   417,   343,   344,   513,   343,   289,
     395,   454,   457,   511,   516,   291,   136,   251,   317,   215,
     370,   516,   466,   516,     6,   516,   516,   465,   390,   454,
     227,   391,   392,   452,   513,   388,   487,    92,    93,    94,
      95,    96,   271,   318,   391,   513,   293,   293,   279,    71,
     293,   278,   215,   215,   215,   360,   405,   215,   215,   102,
     361,   363,   279,   355,   356,   106,   174,   177,   178,   179,
     187,   191,   196,   203,   206,   207,   209,   232,   241,   245,
     252,   254,   263,   265,   303,   306,   443,   444,   445,   446,
     448,   485,   352,   353,   349,   350,   298,   347,   293,   278,
     215,   215,   215,   215,   200,   279,   200,   457,   200,   279,
     293,   226,   293,   453,   231,   484,   493,     4,   517,     3,
       4,     6,    15,    17,    20,    69,    70,    75,    76,   107,
     171,   202,   212,   214,   215,   218,   219,   237,   246,   247,
     253,   254,   264,   267,   269,   270,   273,   275,   277,   280,
     283,   284,   285,   287,   288,   290,   293,   303,   304,   305,
     308,   427,   428,   429,   430,   431,   438,   440,   459,   470,
     471,   472,   473,   474,   494,   500,   501,   508,   516,   518,
     532,   534,   538,   539,   540,   371,   372,   516,   235,   368,
     493,   297,   293,   278,   200,   279,   279,   259,   215,   497,
     498,   499,   500,   236,   324,   325,   500,   324,   324,   324,
     289,   320,   321,   323,   516,   319,   320,   322,   136,   251,
     316,   297,   516,   516,   530,   516,     6,   516,   400,   402,
     454,   404,   454,   404,   200,   279,   361,   404,   427,   483,
     516,   200,   364,   200,   279,   215,   215,   215,   189,   222,
     230,   246,   260,   269,   280,   461,   461,   215,   215,   215,
     215,   215,   215,   215,   215,   147,   148,   149,   204,   406,
     408,   200,   279,   200,   279,   516,   516,     6,   516,   341,
     342,   516,   341,   341,   341,   164,   339,   344,    89,   110,
     111,   158,   294,   330,   331,   332,   454,   247,   516,     3,
     516,   495,   133,   396,   215,   293,     6,   215,   215,   494,
     460,   461,   495,   427,   500,   494,   215,   215,   258,   268,
     427,   502,   503,   215,   494,   215,   215,   494,   494,   215,
     215,   215,   215,   539,   430,   215,   539,     3,   215,   296,
     274,   461,   461,   162,   184,   192,   193,   198,   208,   211,
     213,   224,   225,   244,   262,   287,   294,   300,   301,   437,
     439,   226,   293,    79,   113,   114,   115,   116,   117,   118,
     247,   256,   285,   290,   507,   125,   200,   279,   293,   369,
     466,   516,     6,   516,   454,   392,   391,   500,   279,   488,
     291,   516,   200,   279,   200,   321,   200,   279,   293,   453,
     279,   224,   517,   427,   391,   293,   293,   200,   279,   200,
     279,   200,   405,   200,   200,   356,     3,   449,   449,     3,
     297,   215,   297,     3,   450,     3,     3,     3,   450,   450,
       3,     3,     6,   459,   137,   163,   172,   188,   194,   233,
     239,   399,   409,   410,   411,   412,   353,   349,   293,   200,
     279,   255,   276,   200,   200,   200,   330,     3,     3,     4,
     333,   332,   453,   210,   279,   293,   496,   200,   500,   504,
     516,    21,   504,   504,   297,   496,   200,   200,   500,   506,
     532,   504,   500,   427,   502,   299,   503,   504,   504,   504,
     188,   233,   273,   441,   504,   441,   441,   441,   441,   428,
     429,   297,   215,   297,   435,   539,   435,   435,   435,   215,
     494,   236,   500,   435,   215,   494,   435,   161,   197,   199,
     500,     3,   215,   285,   290,   535,   537,   247,   305,   516,
     500,   500,   500,   500,   500,   443,   372,   516,   215,   293,
     499,   520,   516,   325,   224,   320,   247,   516,   322,   325,
     134,   291,   385,   516,   516,   399,   454,   454,   361,   200,
     200,   200,   279,   189,   222,   230,   246,   260,   269,   280,
     462,     3,   462,   279,   447,   200,   200,   279,   200,   200,
     447,   200,   200,   401,   513,   215,   411,   361,   516,    63,
      64,   294,   302,   334,   335,   336,   342,   334,   334,   334,
     339,     3,   516,   497,   200,   279,   293,   200,   200,   462,
     497,   279,   461,   505,   200,   505,   200,   266,   299,   200,
     200,   200,   500,   200,   500,   500,   500,   500,   462,     3,
     462,   217,   432,   217,   434,   217,   433,   432,   285,   459,
     509,   510,   532,   434,   509,   433,   500,   535,   210,   247,
     256,   279,   285,   286,   290,   536,     3,   226,   293,   236,
     373,   374,   500,   516,   259,   420,   424,   215,   293,   453,
     452,     3,   215,   200,     3,   451,   200,     3,   200,   215,
     483,   333,     3,   336,   210,   453,   424,   500,   516,   424,
     461,   297,   500,   200,   200,   200,   200,   200,   200,   436,
     459,   436,   436,     3,   518,   200,   279,   200,   274,   200,
     535,   535,   535,   516,   200,   279,   421,   423,   513,   190,
     220,   251,   418,   419,   425,   426,   480,   250,   490,   324,
     516,   200,     3,   297,   200,   402,   200,   226,   200,   297,
     462,   297,   510,   500,   210,   210,   279,   226,   374,    49,
      56,   279,   291,   458,   516,     3,   289,   305,   455,   456,
     481,   482,   511,   516,   427,   427,   426,   418,   188,   233,
     273,   442,   185,   248,   475,   491,   200,   453,   200,   462,
     200,   535,   462,   462,   535,   535,   215,   421,   422,   422,
     249,   423,   458,   456,   279,   293,   453,   231,   489,   492,
     516,   292,   185,   210,   279,   210,   210,   279,   421,   295,
     295,   215,   423,   482,   247,   516,   495,   164,   340,     3,
     455,   476,   477,   478,   492,   535,   535,   200,   427,   427,
     421,   453,   496,   279,   255,   276,   479,   340,   210,   210,
     200,   497,   477,   424,   490
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint16 yyr1[] =
{
       0,   314,   315,   316,   316,   316,   317,   317,   317,   318,
     318,   318,   318,   318,   318,   319,   319,   320,   320,   321,
     321,   321,   321,   322,   323,   323,   324,   324,   325,   325,
     326,   327,   327,   327,   327,   328,   328,   329,   329,   330,
     330,   331,   331,   332,   332,   332,   332,   332,   333,   334,
     334,   335,   335,   336,   336,   336,   336,   337,   338,   338,
     338,   338,   338,   338,   338,   338,   338,   338,   338,   338,
     339,   339,   340,   340,   341,   341,   342,   342,   342,   343,
     343,   344,   344,   345,   345,   345,   346,   346,   347,   347,
     347,   347,   347,   347,   347,   348,   348,   349,   349,   350,
     350,   351,   351,   352,   352,   353,   354,   354,   355,   355,
     356,   357,   357,   358,   359,   359,   360,   360,   361,   361,
     362,   362,   363,   363,   364,   365,   367,   366,   369,   368,
     368,   370,   370,   371,   371,   372,   372,   373,   373,   374,
     374,   375,   376,   377,   378,   378,   379,   380,   380,   380,
     380,   380,   380,   380,   381,   381,   381,   382,   382,   382,
     382,   382,   382,   382,   383,   383,   383,   383,   384,   384,
     384,   385,   385,   385,   386,   386,   386,   387,   387,   388,
     388,   388,   388,   388,   388,   389,   389,   390,   390,   391,
     391,   392,   392,   393,   394,   394,   395,   395,   396,   396,
     397,   398,   399,   400,   401,   401,   402,   402,   403,   403,
     403,   404,   404,   405,   405,   405,   406,   406,   406,   406,
     407,   408,   408,   409,   409,   410,   410,   411,   412,   412,
     412,   412,   412,   412,   412,   413,   414,   415,   416,   416,
     417,   417,   418,   419,   420,   421,   421,   421,   421,   421,
     421,   422,   422,   423,   423,   423,   424,   424,   425,   425,
     426,   426,   426,   426,   427,   427,   428,   428,   429,   429,
     430,   430,   431,   431,   432,   432,   433,   433,   434,   434,
     435,   436,   437,   437,   438,   438,   438,   438,   438,   438,
     438,   438,   438,   438,   438,   438,   439,   439,   439,   439,
     439,   439,   440,   440,   440,   440,   441,   441,   441,   441,
     442,   442,   442,   442,   443,   444,   444,   444,   445,   445,
     446,   446,   446,   446,   446,   446,   446,   446,   446,   446,
     446,   446,   446,   446,   446,   446,   446,   446,   446,   446,
     446,   446,   446,   446,   446,   446,   446,   447,   447,   448,
     448,   448,   448,   448,   449,   450,   451,   452,   452,   453,
     453,   453,   454,   454,   455,   455,   456,   456,   456,   456,
     457,   457,   457,   457,   458,   459,   459,   459,   459,   460,
     460,   461,   461,   461,   461,   461,   461,   461,   462,   462,
     462,   462,   462,   462,   462,   462,   463,   463,   463,   464,
     464,   465,   466,   467,   468,   469,   469,   470,   470,   471,
     472,   472,   472,   473,   474,   475,   476,   476,   477,   478,
     478,   479,   479,   479,   480,   481,   481,   482,   482,   483,
     484,   485,   485,   485,   485,   487,   488,   486,   489,   490,
     490,   491,   491,   491,   491,   492,   493,   494,   495,   495,
     496,   496,   496,   496,   497,   498,   498,   499,   499,   499,
     500,   500,   500,   501,   501,   501,   501,   501,   501,   501,
     501,   501,   501,   501,   501,   501,   501,   501,   501,   501,
     501,   501,   501,   501,   501,   501,   501,   501,   501,   501,
     501,   501,   501,   501,   501,   501,   501,   501,   502,   502,
     503,   503,   504,   504,   505,   505,   505,   506,   506,   506,
     507,   507,   507,   507,   507,   507,   508,   508,   508,   508,
     509,   509,   510,   510,   510,   510,   511,   512,   512,   512,
     512,   512,   512,   512,   512,   513,   514,   514,   514,   514,
     514,   514,   514,   514,   514,   515,   515,   515,   515,   515,
     515,   515,   515,   516,   517,   518,   518,   519,   519,   520,
     521,   522,   522,   523,   523,   523,   524,   524,   524,   524,
     524,   524,   524,   524,   525,   526,   527,   528,   528,   528,
     529,   529,   530,   530,   530,   531,   531,   531,   531,   531,
     531,   531,   531,   532,   532,   532,   533,   534,   535,   535,
     535,   535,   536,   536,   536,   536,   536,   537,   537,   538,
     538,   538,   538,   538,   538,   538,   538,   538,   538,   538,
     538,   538,   538,   539,   539,   540,   540,   540,   540,   540,
     540,   541,   541,   542
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
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


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
do                                                              \
  if (yychar == YYEMPTY)                                        \
    {                                                           \
      yychar = (Token);                                         \
      yylval = (Value);                                         \
      YYPOPSTACK (yylen);                                       \
      yystate = *yyssp;                                         \
      goto yybackup;                                            \
    }                                                           \
  else                                                          \
    {                                                           \
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;                                                  \
    }                                                           \
while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

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
#ifndef YYINITDEPTH
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
static YYSIZE_T
yystrlen (const char *yystr)
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
static char *
yystpcpy (char *yydest, const char *yysrc)
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

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
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
  int yytoken = 0;
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

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
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
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex (yystate);
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
      if (yytable_value_is_error (yyn))
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
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

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
     '$$ = $1'.

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
#line 489 "sql.yacc" /* yacc.c:1646  */
    {
		if ((yyvsp[0].ptr)==0 && (yyvsp[-3].integer_val)>=0) {
   				if (A4GL_isyes(acl_getenv("A4GL_ERR_UPDNOWHERE"))) {
                                        yylineno=(yyvsp[-2].integer_val);
                                        a4gl_yyerror("UPDATE with no WHERE clause");
                                } else {
		 			A4GL_warn("UPDATE with no WHERE clause"); 
				}
		}
		(yyval.update_cmd)=(yyvsp[-1].update_cmd);
		(yyval.update_cmd)->table=strdup((yyvsp[-3].str));
		(yyval.update_cmd)->where_clause=(yyvsp[0].ptr);
		(yyval.update_cmd)->value_list=expand_slil((yyval.update_cmd)->value_list);

		if ((yyval.update_cmd)->column_list==0) {
			char colname[200];
			int idtype;
			int isize;
			int rval;
			rval = A4GLSQL_get_columns ((yyvsp[-3].str), colname, &idtype, &isize);
			if (rval) {
				(yyval.update_cmd)->column_list=generate_update_column_list_for((yyvsp[-3].str),  (yyval.update_cmd)->value_list);
			}
		}
	}
#line 3386 "y.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 518 "sql.yacc" /* yacc.c:1646  */
    {
		(yyval.ptr)=0;
	}
#line 3394 "y.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 521 "sql.yacc" /* yacc.c:1646  */
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
			(yyval.ptr)=A4GL_new_expr_simple_expr((yyvsp[0].ptr), ET_EXPR_WHERE_CURRENT_OF);
			A4GL_cursor_current((yyvsp[0].ptr));
		}
		add_feature("UPDATE_WHERE_CURRENT_OF");
		}
	}
#line 3416 "y.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 538 "sql.yacc" /* yacc.c:1646  */
    {
		(yyval.ptr)=A4GL_new_select_list_item_expr((yyvsp[0].s_select_list_item));
	}
#line 3424 "y.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 543 "sql.yacc" /* yacc.c:1646  */
    {
		(yyval.ptr)=0;
	}
#line 3432 "y.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 546 "sql.yacc" /* yacc.c:1646  */
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
			(yyval.ptr)=A4GL_new_expr_simple_expr((yyvsp[0].ptr), ET_EXPR_WHERE_CURRENT_OF);
                        A4GL_cursor_current((yyvsp[0].ptr));
		}
		add_feature("DELETE_WHERE_CURRENT_OF");
		}
	}
#line 3454 "y.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 563 "sql.yacc" /* yacc.c:1646  */
    {
		 (yyval.ptr)=A4GL_new_select_list_item_expr((yyvsp[0].s_select_list_item));
	}
#line 3462 "y.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 569 "sql.yacc" /* yacc.c:1646  */
    {
		add_feature("UPDATE_COLUMNLIST_EQ_VALUELIST");
		(yyval.update_cmd)=malloc(sizeof(struct struct_update_cmd));
		(yyval.update_cmd)->connid=0;
		(yyval.update_cmd)->table=0;
		(yyval.update_cmd)->column_list=(yyvsp[-5].str_list);
		(yyval.update_cmd)->value_list=(yyvsp[-1].s_select_list_item_list);
		(yyval.update_cmd)->where_clause=0;
    }
#line 3476 "y.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 578 "sql.yacc" /* yacc.c:1646  */
    {	
		(yyval.update_cmd)=malloc(sizeof(struct struct_update_cmd));
		(yyval.update_cmd)->connid=0;
		(yyval.update_cmd)->table=0;
		(yyval.update_cmd)->column_list=0; 		/* A column list of 0 means .* */
		(yyval.update_cmd)->value_list=(yyvsp[-1].s_select_list_item_list);
		(yyval.update_cmd)->where_clause=0;
		add_feature("UPDATE_SET_STAR");
    }
#line 3490 "y.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 587 "sql.yacc" /* yacc.c:1646  */
    {	
		(yyval.update_cmd)=malloc(sizeof(struct struct_update_cmd));
		(yyval.update_cmd)->connid=0;
		(yyval.update_cmd)->table=0;
		(yyval.update_cmd)->column_list=0; 		/* A column list of 0 means .* */
		(yyval.update_cmd)->value_list=(yyvsp[-1].s_select_list_item_list);
		(yyval.update_cmd)->where_clause=0;
		 add_feature("UPDATE_SET_STAR");
    }
#line 3504 "y.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 596 "sql.yacc" /* yacc.c:1646  */
    {
		(yyval.update_cmd)=(yyvsp[0].update_cmd);
		add_feature("UPDATE_COLUMN_EQ_VALUE_LIST");
    }
#line 3513 "y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 603 "sql.yacc" /* yacc.c:1646  */
    {
		char buff[200];
		SPRINTF1(buff,"%s.*", (yyvsp[0].str));
#ifdef SQLCOMPILER
		(yyval.sql_string)=strdup("IMPOSSIBLE") ;
#else
		(yyval.update_cmd)=malloc(sizeof(struct struct_update_cmd));
		(yyval.update_cmd)->connid=0;
		(yyval.update_cmd)->table=0;
		(yyval.update_cmd)->column_list=0; 		//* A column list of 0 means .* 
		(yyval.update_cmd)->value_list=(yyvsp[0].s_select_list_item_list);
		(yyval.update_cmd)->where_clause=0;

#endif
	}
#line 3533 "y.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 618 "sql.yacc" /* yacc.c:1646  */
    {
		char buff[200];
		SPRINTF1(buff,"%s.*", (yyvsp[0].str));
#ifdef SQLCOMPILER
		(yyval.sql_string)=strdup("IMPOSSIBLE") ;
#else
		(yyval.update_cmd)=malloc(sizeof(struct struct_update_cmd));
		(yyval.update_cmd)->connid=0;
		(yyval.update_cmd)->table=0;
		(yyval.update_cmd)->column_list=0; 		//* A column list of 0 means .*
		(yyval.update_cmd)->value_list=(yyvsp[0].s_select_list_item_list);
		//$<update_cmd>$->value_list=make_select_list_item_list_from_variable_record(buff); 
		(yyval.update_cmd)->where_clause=0;
#endif
	}
#line 3553 "y.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 673 "sql.yacc" /* yacc.c:1646  */
    {
		(yyval.update_cmd)=malloc(sizeof(struct_update_cmd));
		(yyval.update_cmd)->column_list=new_str_list((yyvsp[0].upd_pair)->column_name);
		(yyval.update_cmd)->value_list=0;
		(yyval.update_cmd)->where_clause=0;
		(yyval.update_cmd)->value_list=local_new_select_list_item_list((yyvsp[0].upd_pair)->value);
	}
#line 3565 "y.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 680 "sql.yacc" /* yacc.c:1646  */
    {
		(yyval.update_cmd)=(yyvsp[-2].update_cmd);
		add_str_list((yyval.update_cmd)->column_list, (yyvsp[0].upd_pair)->column_name);
		local_add_select_list_item_list((yyval.update_cmd)->value_list, (yyvsp[0].upd_pair)->value);
	}
#line 3575 "y.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 691 "sql.yacc" /* yacc.c:1646  */
    {
                strcpy((yyval.str),(yyvsp[0].str));
        }
#line 3583 "y.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 694 "sql.yacc" /* yacc.c:1646  */
    {
                strcpy((yyval.str),(yyvsp[0].str));
        }
#line 3591 "y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 699 "sql.yacc" /* yacc.c:1646  */
    {
                struct ilist *i;
                i=&(yyvsp[0].int_list);
                if (strcmp((yyvsp[-1].str),"rowid")==0) { add_feature("ROWID"); }
                ADDMAP("Use Column",(yyvsp[-1].str));
                strcpy((yyval.str),A4GLSQLCV_make_substr(A4GL_confirm_colname(current_upd_table,(yyvsp[-1].str)), i->i0,i->i1,i->i2));
        }
#line 3603 "y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 706 "sql.yacc" /* yacc.c:1646  */
    {
                struct ilist *i;
                if (strcmp((yyvsp[-1].str),"rowid")==0) { add_feature("ROWID"); }
                if (A4GLSQLCV_check_requirement("NO_UPDATE_TABLE")) {
                        strcpy((yyval.str),(yyvsp[-1].str));
                } else {
                        if (A4GLSQLCV_check_requirement("OMIT_UPDATE_TABLE")) {
                                SPRINTF1((yyval.str),"%s",A4GLSQLCV_check_colname(current_upd_table,(yyvsp[-1].str)));
                        } else {
                                SPRINTF1((yyval.str),"%s",A4GLSQLCV_check_colname(A4GLSQLCV_ownerize_tablename(NULL,(yyvsp[-3].str)),(yyvsp[-1].str)));
                        }
                }

                ADDMAP("Use Column",(yyval.str));
                i=&(yyvsp[0].int_list);
                strcpy((yyval.str),A4GLSQLCV_make_substr((yyval.str),i->i0,i->i1,i->i2));
        }
#line 3625 "y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 723 "sql.yacc" /* yacc.c:1646  */
    {
                struct ilist *i;
                if (strcmp((yyvsp[-1].str),"rowid")==0) { add_feature("ROWID"); }
                if (A4GLSQLCV_check_requirement("NO_UPDATE_TABLE")) {
                        strcpy((yyval.str),(yyvsp[-1].str));
                } else {
                        if (A4GLSQLCV_check_requirement("OMIT_UPDATE_TABLE")) {
                                SPRINTF1((yyval.str),"%s",A4GLSQLCV_check_colname(current_upd_table,(yyvsp[-1].str)));
                        } else {
                                SPRINTF1((yyval.str),"%s",A4GLSQLCV_check_colname(A4GLSQLCV_ownerize_tablename((yyvsp[-5].str),(yyvsp[-3].str)),(yyvsp[-1].str)));
                        }
                }

                ADDMAP("Use Column",(yyval.str));
                i=&(yyvsp[0].int_list);
                strcpy((yyval.str),A4GLSQLCV_make_substr((yyval.str),i->i0,i->i1,i->i2));
        }
#line 3647 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 740 "sql.yacc" /* yacc.c:1646  */
    {
                if (A4GLSQLCV_check_requirement("NO_UPDATE_TABLE")) {
                        strcpy((yyval.str),"*");
                } else {
                if (A4GLSQLCV_check_requirement("OMIT_UPDATE_TABLE")) {
                        SPRINTF1((yyval.str),"%s",A4GLSQLCV_check_colname(current_upd_table,"*"));
                } else {
                        SPRINTF1((yyval.str),"%s",A4GLSQLCV_check_colname(A4GLSQLCV_ownerize_tablename(NULL,(yyvsp[-2].str)),"*"));
                }
                }

                ADDMAP("Use Column",(yyval.str));
        }
#line 3665 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 761 "sql.yacc" /* yacc.c:1646  */
    {
		(yyval.upd_pair)=malloc(sizeof(struct s_update_pair));
		(yyval.upd_pair)->column_name=acl_strdup((yyvsp[-2].str));
		(yyval.upd_pair)->value=(yyvsp[0].s_select_list_item);
	}
#line 3675 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 770 "sql.yacc" /* yacc.c:1646  */
    {
			(yyval.str_list)=new_str_list((yyvsp[0].str));
		}
#line 3683 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 773 "sql.yacc" /* yacc.c:1646  */
    {
			(yyval.str_list)=add_str_list((yyvsp[-2].str_list), (yyvsp[0].str));
		}
#line 3691 "y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 781 "sql.yacc" /* yacc.c:1646  */
    { 
		(yyval.s_select_list_item_list)=local_new_select_list_item_list((yyvsp[0].s_select_list_item));
	}
#line 3699 "y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 784 "sql.yacc" /* yacc.c:1646  */
    { 
		(yyval.s_select_list_item_list)=local_add_select_list_item_list((yyvsp[-2].s_select_list_item_list),(yyvsp[0].s_select_list_item));
	}
#line 3707 "y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 792 "sql.yacc" /* yacc.c:1646  */
    {(yyval.s_select_list_item)=(yyvsp[0].s_select_list_item);}
#line 3713 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 793 "sql.yacc" /* yacc.c:1646  */
    {(yyval.s_select_list_item)=new_select_list_item_builtin_const(E_SLI_BUILTIN_CONST_NULL); }
#line 3719 "y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 800 "sql.yacc" /* yacc.c:1646  */
    { (yyval.sql_string)=make_sql_string_and_free(acl_strdup((yyvsp[0].str)), NULL);}
#line 3725 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 803 "sql.yacc" /* yacc.c:1646  */
    {
			if (A4GLSQLCV_check_requirement("ADD_CASCADE")) {
				SPRINTF1((yyval.str), "DROP TABLE %s CASCADE",(yyvsp[0].str));
			} else {
				SPRINTF1((yyval.str), "DROP TABLE %s",(yyvsp[0].str));
			}
			add_feature("DROP_TABLE");
		}
#line 3738 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 811 "sql.yacc" /* yacc.c:1646  */
    {SPRINTF2((yyval.str),"%s %s ",(yyvsp[-1].str),(yyvsp[0].str));
			add_feature("DROP_VIEW");
}
#line 3746 "y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 814 "sql.yacc" /* yacc.c:1646  */
    {SPRINTF2((yyval.str),"%s %s",(yyvsp[-1].str),(yyvsp[0].str));
		if (strchr((yyvsp[0].str),'@') || strchr((yyvsp[0].str),':')) add_feature("DROP_INDEX_QUALIFIED_PATH");
			add_feature("DROP_INDEX");
}
#line 3755 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 818 "sql.yacc" /* yacc.c:1646  */
    {SPRINTF2((yyval.str),"%s %s",(yyvsp[-1].str),(yyvsp[0].str));
			add_feature("DROP_TRIGGER");
}
#line 3763 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 824 "sql.yacc" /* yacc.c:1646  */
    {(yyval.sql_string)=acl_strdup((yyvsp[0].str));}
#line 3769 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 825 "sql.yacc" /* yacc.c:1646  */
    {(yyval.sql_string)=(yyvsp[0].sql_string);}
#line 3775 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 829 "sql.yacc" /* yacc.c:1646  */
    {
                if (A4GLSQLCV_check_requirement ("ADD_WITH_OIDS")) {
                        (yyval.sql_string)=make_sql_string_and_free(acl_strdup((yyvsp[-5].str)),kw_space,acl_strdup((yyvsp[-4].str)),kw_space,kw_ob,(yyvsp[-2].sql_string),kw_cb,acl_strdup(" WITH OIDS "),acl_strdup((yyvsp[0].str)),NULL);
                } else {
                        (yyval.sql_string)=make_sql_string_and_free(acl_strdup((yyvsp[-5].str)),kw_space,acl_strdup((yyvsp[-4].str)),kw_space,kw_ob,(yyvsp[-2].sql_string),kw_cb,acl_strdup((yyvsp[0].str)),NULL);
                }

		add_feature("CREATE_TABLE");
	}
#line 3789 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 839 "sql.yacc" /* yacc.c:1646  */
    {
		char *tstr;
		tstr="";
		if (strlen((yyvsp[-2].str))) tstr=(yyvsp[-2].str);
		if (strlen((yyvsp[0].str))) tstr=(yyvsp[0].str);
		map_create_temp((yyvsp[-6].str),(yyvsp[-4].sql_string));
		(yyval.sql_string)=A4GLSQLCV_create_temp_table((yyvsp[-6].str),(yyvsp[-4].sql_string),tstr,(yyvsp[-1].str));
		add_feature("CREATE_TEMP_TABLE");
		acl_free((yyvsp[-4].sql_string));
	}
#line 3804 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 853 "sql.yacc" /* yacc.c:1646  */
    {strcpy((yyval.str),"");}
#line 3810 "y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 854 "sql.yacc" /* yacc.c:1646  */
    {strcpy((yyval.str),(yyvsp[0].str));}
#line 3816 "y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 859 "sql.yacc" /* yacc.c:1646  */
    {SPRINTF2((yyval.str),"%s%s",(yyvsp[-1].str),(yyvsp[0].str)); }
#line 3822 "y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 864 "sql.yacc" /* yacc.c:1646  */
    {
			add_feature("CREATE_TABLE_IN");
                        if (A4GLSQLCV_check_requirement("OMIT_TABLE_IN")) {
                                strcpy((yyval.str),"");
			} else {
				SPRINTF1((yyval.str)," IN %s",(yyvsp[0].str));
			}
		}
#line 3835 "y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 872 "sql.yacc" /* yacc.c:1646  */
    {
			add_feature("CREATE_TABLE_WITH_EXTENT_SIZE");
                        if (A4GLSQLCV_check_requirement("OMIT_TABLE_EXTENTS")) {
                                strcpy((yyval.str),"");
			} else {
				SPRINTF1((yyval.str)," EXTENT SIZE %s",(yyvsp[0].str)); 
			}
	}
#line 3848 "y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 880 "sql.yacc" /* yacc.c:1646  */
    {
			add_feature("CREATE_TABLE_WITH_NEXT_EXTENT_SIZE");
                        if (A4GLSQLCV_check_requirement("OMIT_TABLE_EXTENTS")) {
                                strcpy((yyval.str),"");
			} else {
				SPRINTF1((yyval.str)," NEXT SIZE %s",(yyvsp[0].str)); 
			}
	}
#line 3861 "y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 888 "sql.yacc" /* yacc.c:1646  */
    {
			add_feature("CREATE_TABLE_LOCK_MODE"); 
                        if (A4GLSQLCV_check_requirement("OMIT_LOCK_MODE")) {
                                strcpy((yyval.str),"");
			} else {
				SPRINTF0((yyval.str)," LOCK MODE PAGE"); 
			}
	}
#line 3874 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 896 "sql.yacc" /* yacc.c:1646  */
    {
			add_feature("CREATE_TABLE_LOCK_MODE");
                        if (A4GLSQLCV_check_requirement("OMIT_LOCK_MODE")) {
                                strcpy((yyval.str),"");
			} else {
				SPRINTF0((yyval.str)," LOCK MODE ROW"); 
			}
	}
#line 3887 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 908 "sql.yacc" /* yacc.c:1646  */
    {strcpy((yyval.str),"");}
#line 3893 "y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 908 "sql.yacc" /* yacc.c:1646  */
    {strcpy((yyval.str),(yyvsp[0].str));}
#line 3899 "y.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 912 "sql.yacc" /* yacc.c:1646  */
    {SPRINTF2((yyval.str),"%s%s",(yyvsp[-1].str),(yyvsp[0].str));}
#line 3905 "y.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 916 "sql.yacc" /* yacc.c:1646  */
    {
                        if (A4GLSQLCV_check_requirement("OMIT_INDEX_IN")) {
                                strcpy((yyval.str),"");
                        } else {
                                SPRINTF1((yyval.str)," IN %s",(yyvsp[0].str)); add_feature("INDEX_IN");
                        }
        }
#line 3917 "y.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 923 "sql.yacc" /* yacc.c:1646  */
    {
                        if (A4GLSQLCV_check_requirement("OMIT_INDEX_FILLFACTOR")) {
                                strcpy((yyval.str),"");
                        } else {
                                SPRINTF1((yyval.str),"FILLFACTOR %s",(yyvsp[0].str)); add_feature("INDEX_FILLFACTOR");
                        }
        }
#line 3929 "y.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 930 "sql.yacc" /* yacc.c:1646  */
    {
                        if (A4GLSQLCV_check_requirement("OMIT_INDEX_USING")) {
                                strcpy((yyval.str),"");
                        } else {
                                strcpy((yyval.str),"USING BTREE"); add_feature("INDEX_BTREE");
                        }
        }
#line 3941 "y.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 937 "sql.yacc" /* yacc.c:1646  */
    {
                        if (A4GLSQLCV_check_requirement("OMIT_INDEX_USING")) {
                                strcpy((yyval.str),"");
                        } else {
                                strcpy((yyval.str),"USING RTREE"); add_feature("INDEX_RTREE");
                        }
        }
#line 3953 "y.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 946 "sql.yacc" /* yacc.c:1646  */
    { strcpy(last_tmp_name,(yyvsp[0].str)); }
#line 3959 "y.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 950 "sql.yacc" /* yacc.c:1646  */
    {SPRINTF7((yyval.str),"CREATE UNIQUE INDEX %s %s %s %s %s %s %s",(yyvsp[-6].str),(yyvsp[-5].str),(yyvsp[-4].str),(yyvsp[-3].str),(yyvsp[-2].str),(yyvsp[-1].str),(yyvsp[0].str));
		add_feature("CREATE_INDEX");
		add_feature("CREATE_INDEX_UNIQUE");
		if (strchr((yyvsp[-6].str),'@') || strchr((yyvsp[-6].str),':')) add_feature("CREATE_INDEX_QUALIFIED_PATH");
		if (strchr((yyvsp[-2].str),',')) { add_feature("CREATE_INDEX_COMPOSITE"); }
	
}
#line 3971 "y.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 957 "sql.yacc" /* yacc.c:1646  */
    {
		add_feature("CREATE_INDEX");
		add_feature("CREATE_INDEX_UNIQUE");
		add_feature("CLUSTER_INDEX");
		if (strchr((yyvsp[-6].str),'@') || strchr((yyvsp[-6].str),':')) add_feature("CREATE_INDEX_QUALIFIED_PATH");
		if (strchr((yyvsp[-2].str),',')) { add_feature("CREATE_INDEX_COMPOSITE"); }
		if (A4GLSQLCV_check_requirement("OMIT_INDEX_CLUSTER")) {
		SPRINTF7((yyval.str),"CREATE UNIQUE INDEX %s %s %s %s %s %s %s",(yyvsp[-6].str),(yyvsp[-5].str),(yyvsp[-4].str),(yyvsp[-3].str),(yyvsp[-2].str),(yyvsp[-1].str),(yyvsp[0].str));
		} else {
		SPRINTF7((yyval.str),"CREATE UNIQUE CLUSTER INDEX %s %s %s %s %s %s %s",(yyvsp[-6].str),(yyvsp[-5].str),(yyvsp[-4].str),(yyvsp[-3].str),(yyvsp[-2].str),(yyvsp[-1].str),(yyvsp[0].str));
		}
	}
#line 3988 "y.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 969 "sql.yacc" /* yacc.c:1646  */
    {
		add_feature("CREATE_INDEX");
		add_feature("CLUSTER_INDEX");
		if (strchr((yyvsp[-6].str),'@') || strchr((yyvsp[-6].str),':')) add_feature("CREATE_INDEX_QUALIFIED_PATH");
		if (strchr((yyvsp[-2].str),',')) { add_feature("CREATE_INDEX_COMPOSITE"); }
		if (A4GLSQLCV_check_requirement("OMIT_INDEX_CLUSTER")) {
			SPRINTF7((yyval.str),"CREATE INDEX %s %s %s %s %s %s %s",(yyvsp[-6].str),(yyvsp[-5].str),(yyvsp[-4].str),(yyvsp[-3].str),(yyvsp[-2].str),(yyvsp[-1].str),(yyvsp[0].str));
		} else {
			SPRINTF7((yyval.str),"CREATE CLUSTER INDEX %s %s %s %s %s %s %s",(yyvsp[-6].str),(yyvsp[-5].str),(yyvsp[-4].str),(yyvsp[-3].str),(yyvsp[-2].str),(yyvsp[-1].str),(yyvsp[0].str));
		}
	}
#line 4004 "y.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 980 "sql.yacc" /* yacc.c:1646  */
    {
		if (strchr((yyvsp[-6].str),'@') || strchr((yyvsp[-6].str),':')) add_feature("CREATE_INDEX_QUALIFIED_PATH");
		if (strchr((yyvsp[-2].str),',')) { add_feature("CREATE_INDEX_COMPOSITE"); }
			add_feature("CREATE_INDEX");
			SPRINTF7((yyval.str)," CREATE INDEX %s %s %s %s %s %s %s",(yyvsp[-6].str),(yyvsp[-5].str),(yyvsp[-4].str),(yyvsp[-3].str),(yyvsp[-2].str),(yyvsp[-1].str),(yyvsp[0].str));
	}
#line 4015 "y.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 986 "sql.yacc" /* yacc.c:1646  */
    {
		add_feature("CREATE_DATABASE");
		a4gl_yyerror("You cannot create a database from within Aubit4gl - if the target database allows - prepare and execute it manually");
	}
#line 4024 "y.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 990 "sql.yacc" /* yacc.c:1646  */
    {
		add_feature("DROP_DATABASE");
		a4gl_yyerror("You cannot drop a database from within Aubit4gl - if the target database allows - prepare and execute it manually");
	}
#line 4033 "y.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 994 "sql.yacc" /* yacc.c:1646  */
    { 
		if (strchr((yyvsp[-2].str),'@') || strchr((yyvsp[-2].str),':')) add_feature("CREATE_SYNONYM_QUALIFIED_PATH");
			add_feature("CREATE_SYNONYM");
			SPRINTF3((yyval.str),"%s %s FOR %s",(yyvsp[-3].str),(yyvsp[-2].str),(yyvsp[0].str)); 
	}
#line 4043 "y.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 999 "sql.yacc" /* yacc.c:1646  */
    { 
		add_feature("CREATE_AUDIT");
		SPRINTF2((yyval.str),"CREATE AUDIT FOR %s IN '%s'",(yyvsp[-2].str),A4GL_strip_quotes((yyvsp[0].str))); 
	}
#line 4052 "y.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 1003 "sql.yacc" /* yacc.c:1646  */
    { 
		add_feature("DROP_AUDIT");
		SPRINTF1((yyval.str),"DROP AUDIT FOR %s",(yyvsp[0].str)); }
#line 4060 "y.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 1006 "sql.yacc" /* yacc.c:1646  */
    { 
		if (strchr((yyvsp[0].str),'@') || strchr((yyvsp[0].str),':')) add_feature("DROP_SYNONYM_QUALIFIED_PATH");
		add_feature("DROP_SYNONYM");
		SPRINTF2((yyval.str),"%s %s",(yyvsp[-1].str),(yyvsp[0].str)); }
#line 4069 "y.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 1010 "sql.yacc" /* yacc.c:1646  */
    { 
		add_feature("RECOVER_TABLE");
		SPRINTF1((yyval.str),"RECOVER TABLE %s",(yyvsp[0].str)); }
#line 4077 "y.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 1013 "sql.yacc" /* yacc.c:1646  */
    { 
		add_feature("ROLLFORWARD_DATABASE");
		SPRINTF1((yyval.str),"ROLLFORWARD DATABASE %s",(yyvsp[0].str)); }
#line 4085 "y.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 1020 "sql.yacc" /* yacc.c:1646  */
    {strcpy((yyval.str),"");}
#line 4091 "y.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 1021 "sql.yacc" /* yacc.c:1646  */
    {
		add_feature("SELECT_INTO_TEMP_WITH_NO_LOG");
		if (A4GLSQLCV_check_requirement("OMIT_NO_LOG")) {
			strcpy((yyval.str),"");
		} else {
			SPRINTF1((yyval.str)," %s ",(yyvsp[0].str));
		}
	}
#line 4104 "y.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 1031 "sql.yacc" /* yacc.c:1646  */
    {(yyval.integer_val)=0;}
#line 4110 "y.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 1032 "sql.yacc" /* yacc.c:1646  */
    { (yyval.integer_val)=1;}
#line 4116 "y.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 1037 "sql.yacc" /* yacc.c:1646  */
    {SPRINTF2((yyval.str),"%s,%s",(yyvsp[-2].str),(yyvsp[0].str));}
#line 4122 "y.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 1041 "sql.yacc" /* yacc.c:1646  */
    {
		add_feature("CREATE_INDEX_ASC");
		strcpy((yyval.str),A4GL_confirm_colname(last_tmp_name,(yyvsp[-1].str)));
		if (A4GLSQLCV_check_requirement("OMIT_INDEX_ORDER")) {
			SPRINTF1((yyval.str),"%s",(yyvsp[-1].str));
		} else {
			SPRINTF1((yyval.str),"%s ASC",(yyvsp[-1].str));
		}
}
#line 4136 "y.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 1050 "sql.yacc" /* yacc.c:1646  */
    {
		add_feature("CREATE_INDEX_DESC");
		strcpy((yyval.str),A4GL_confirm_colname(last_tmp_name,(yyvsp[-1].str)));
		if (A4GLSQLCV_check_requirement("OMIT_INDEX_ORDER")) {
			SPRINTF1((yyval.str),"%s",(yyvsp[-1].str));
		} else {
			SPRINTF1((yyval.str),"%s DESC",(yyvsp[-1].str));
		}
}
#line 4150 "y.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 1059 "sql.yacc" /* yacc.c:1646  */
    {
		strcpy((yyval.str),A4GL_confirm_colname(last_tmp_name,(yyvsp[0].str)));
}
#line 4158 "y.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 1066 "sql.yacc" /* yacc.c:1646  */
    {
		(yyval.sql_string)=(yyvsp[0].sql_string);
	}
#line 4166 "y.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 1069 "sql.yacc" /* yacc.c:1646  */
    {
		(yyval.sql_string)=make_sql_string_and_free((yyvsp[-2].sql_string),kw_comma,strdup("\n"),(yyvsp[0].sql_string),NULL);
	}
#line 4174 "y.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 1075 "sql.yacc" /* yacc.c:1646  */
    {
		(yyval.sql_string)=make_sql_string_and_free(strdup("   "),(yyvsp[0].sql_string),NULL);
	}
#line 4182 "y.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 1078 "sql.yacc" /* yacc.c:1646  */
    {
		(yyval.sql_string)=make_sql_string_and_free(strdup("   "),(yyvsp[0].sql_string),NULL);
	}
#line 4190 "y.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 1089 "sql.yacc" /* yacc.c:1646  */
    {
		add_feature("ALTER_TABLE");
	(yyval.sql_string)=make_sql_string_and_free(acl_strdup((yyvsp[-2].str)),kw_space,acl_strdup((yyvsp[-1].str)),kw_space,(yyvsp[0].sql_string),NULL);
	}
#line 4199 "y.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 1093 "sql.yacc" /* yacc.c:1646  */
    {
		add_feature("CLUSTER_INDEX");
		add_feature("ALTER_INDEX_CLUSTER");
		(yyval.sql_string)=make_sql_string_and_free(acl_strdup("ALTER INDEX "),acl_strdup((yyvsp[-1].str)),acl_strdup(" TO CLUSTER"),NULL);
		}
#line 4209 "y.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 1098 "sql.yacc" /* yacc.c:1646  */
    {
		add_feature("ALTER_INDEX_NOT_CLUSTER");
		(yyval.sql_string)=make_sql_string_and_free(acl_strdup("ALTER INDEX "),acl_strdup((yyvsp[-1].str)),acl_strdup(" TO NOT CLUSTER"),NULL);
		}
#line 4218 "y.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 1105 "sql.yacc" /* yacc.c:1646  */
    {
		(yyval.sql_string)=(yyvsp[0].sql_string);
	}
#line 4226 "y.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 1108 "sql.yacc" /* yacc.c:1646  */
    {
		(yyval.sql_string)=make_sql_string_and_free((yyvsp[-2].sql_string),kw_comma,(yyvsp[0].sql_string),NULL);
	}
#line 4234 "y.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 1117 "sql.yacc" /* yacc.c:1646  */
    {
		(yyval.sql_string)=(yyvsp[0].sql_string);
	}
#line 4242 "y.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 1120 "sql.yacc" /* yacc.c:1646  */
    {
	add_feature("ALTER_TABLE_DROP");
		(yyval.sql_string)=acl_strdup((yyvsp[0].str));
	}
#line 4251 "y.tab.c" /* yacc.c:1646  */
    break;

  case 90:
#line 1124 "sql.yacc" /* yacc.c:1646  */
    {
	add_feature("ALTER_TABLE_MODIFY");
		(yyval.sql_string)=(yyvsp[0].sql_string);
	}
#line 4260 "y.tab.c" /* yacc.c:1646  */
    break;

  case 91:
#line 1128 "sql.yacc" /* yacc.c:1646  */
    {
		add_feature("ALTER_TABLE_ADD_CONSTRAINT");
		(yyval.sql_string)=acl_strdup((yyvsp[0].str));
	}
#line 4269 "y.tab.c" /* yacc.c:1646  */
    break;

  case 92:
#line 1132 "sql.yacc" /* yacc.c:1646  */
    {
		add_feature("ALTER_TABLE_DROP_CONSTRAINT");
		(yyval.sql_string)=acl_strdup((yyvsp[0].str));
	}
#line 4278 "y.tab.c" /* yacc.c:1646  */
    break;

  case 93:
#line 1136 "sql.yacc" /* yacc.c:1646  */
    {
		add_feature("ALTER_TABLE_MODIFY_NEXT");
		(yyval.sql_string)=acl_strdup((yyvsp[0].str));
	}
#line 4287 "y.tab.c" /* yacc.c:1646  */
    break;

  case 94:
#line 1140 "sql.yacc" /* yacc.c:1646  */
    {
		add_feature("ALTER_TABLE_LOCK_MODE");
		(yyval.sql_string)=acl_strdup((yyvsp[0].str));
	}
#line 4296 "y.tab.c" /* yacc.c:1646  */
    break;

  case 95:
#line 1148 "sql.yacc" /* yacc.c:1646  */
    {
		add_feature("ALTER_TABLE_ADD");
		(yyval.sql_string)=make_sql_string_and_free(acl_strdup("ADD "),(yyvsp[0].sql_string),NULL);
	}
#line 4305 "y.tab.c" /* yacc.c:1646  */
    break;

  case 96:
#line 1152 "sql.yacc" /* yacc.c:1646  */
    {
		add_feature("ALTER_TABLE_ADD");
		(yyval.sql_string)=make_sql_string_and_free(acl_strdup("ADD "),kw_ob,(yyvsp[-1].sql_string),kw_cb,NULL);
	}
#line 4314 "y.tab.c" /* yacc.c:1646  */
    break;

  case 97:
#line 1160 "sql.yacc" /* yacc.c:1646  */
    {
		(yyval.sql_string)=(yyvsp[0].sql_string);
	}
#line 4322 "y.tab.c" /* yacc.c:1646  */
    break;

  case 98:
#line 1163 "sql.yacc" /* yacc.c:1646  */
    {
		add_feature("ALTER_TABLE_ADD_BEFORE");
		(yyval.sql_string)=make_sql_string_and_free((yyvsp[-2].sql_string),acl_strdup(" BEFORE "),acl_strdup((yyvsp[0].str)),NULL);
	}
#line 4331 "y.tab.c" /* yacc.c:1646  */
    break;

  case 99:
#line 1170 "sql.yacc" /* yacc.c:1646  */
    {
		(yyval.sql_string)=(yyvsp[0].sql_string);
	}
#line 4339 "y.tab.c" /* yacc.c:1646  */
    break;

  case 100:
#line 1173 "sql.yacc" /* yacc.c:1646  */
    {
		(yyval.sql_string)=make_sql_string_and_free((yyvsp[-2].sql_string),kw_comma,(yyvsp[0].sql_string),NULL);
	}
#line 4347 "y.tab.c" /* yacc.c:1646  */
    break;

  case 101:
#line 1180 "sql.yacc" /* yacc.c:1646  */
    {
		SPRINTF1((yyval.str),"DROP %s",(yyvsp[0].str));
	}
#line 4355 "y.tab.c" /* yacc.c:1646  */
    break;

  case 102:
#line 1183 "sql.yacc" /* yacc.c:1646  */
    {
		SPRINTF1((yyval.str),"DROP (%s)",(yyvsp[-1].str));
	}
#line 4363 "y.tab.c" /* yacc.c:1646  */
    break;

  case 104:
#line 1191 "sql.yacc" /* yacc.c:1646  */
    {
		SPRINTF2((yyval.str),"%s,%s",(yyvsp[-2].str),(yyvsp[0].str));
	}
#line 4371 "y.tab.c" /* yacc.c:1646  */
    break;

  case 106:
#line 1200 "sql.yacc" /* yacc.c:1646  */
    {
		(yyval.sql_string)=make_sql_string_and_free(acl_strdup("MODIFY "),(yyvsp[0].sql_string),NULL);
	}
#line 4379 "y.tab.c" /* yacc.c:1646  */
    break;

  case 107:
#line 1203 "sql.yacc" /* yacc.c:1646  */
    {
		(yyval.sql_string)=make_sql_string_and_free(acl_strdup("MODIFY "),kw_ob,(yyvsp[-1].sql_string),kw_cb,NULL);
	}
#line 4387 "y.tab.c" /* yacc.c:1646  */
    break;

  case 108:
#line 1209 "sql.yacc" /* yacc.c:1646  */
    {
		(yyval.sql_string)=(yyvsp[0].sql_string);
	}
#line 4395 "y.tab.c" /* yacc.c:1646  */
    break;

  case 109:
#line 1212 "sql.yacc" /* yacc.c:1646  */
    {
		(yyval.sql_string)=make_sql_string_and_free((yyvsp[-2].sql_string),kw_comma,(yyvsp[0].sql_string),NULL);
	}
#line 4403 "y.tab.c" /* yacc.c:1646  */
    break;

  case 110:
#line 1218 "sql.yacc" /* yacc.c:1646  */
    {
		(yyval.sql_string)=(yyvsp[0].sql_string);
	}
#line 4411 "y.tab.c" /* yacc.c:1646  */
    break;

  case 111:
#line 1225 "sql.yacc" /* yacc.c:1646  */
    {strcpy((yyval.str),"LOCK MODE (PAGE)");}
#line 4417 "y.tab.c" /* yacc.c:1646  */
    break;

  case 112:
#line 1226 "sql.yacc" /* yacc.c:1646  */
    {strcpy((yyval.str),"LOCK MODE (ROW)");}
#line 4423 "y.tab.c" /* yacc.c:1646  */
    break;

  case 113:
#line 1230 "sql.yacc" /* yacc.c:1646  */
    {
		add_feature("DDL_NEXT_SIZE");
		SPRINTF1((yyval.str),"MODIFY NEXT SIZE %d",atoi((yyvsp[0].str)));
	}
#line 4432 "y.tab.c" /* yacc.c:1646  */
    break;

  case 114:
#line 1238 "sql.yacc" /* yacc.c:1646  */
    {
		add_feature("DDL_CONSTRAINT");
		SPRINTF2((yyval.str),"ADD CONSTRAINT %s%s",(yyvsp[-1].sql_string),(yyvsp[0].str));
	}
#line 4441 "y.tab.c" /* yacc.c:1646  */
    break;

  case 115:
#line 1242 "sql.yacc" /* yacc.c:1646  */
    {
		add_feature("ADD_CONSTRAINT");
		SPRINTF1((yyval.str),"ADD CONSTRAINT (%s)",(yyvsp[-1].sql_string));
	}
#line 4450 "y.tab.c" /* yacc.c:1646  */
    break;

  case 116:
#line 1249 "sql.yacc" /* yacc.c:1646  */
    {
		(yyval.sql_string)=make_sql_string_and_free((yyvsp[-1].sql_string),acl_strdup((yyvsp[0].str)),NULL);
}
#line 4458 "y.tab.c" /* yacc.c:1646  */
    break;

  case 117:
#line 1251 "sql.yacc" /* yacc.c:1646  */
    {
	(yyval.sql_string)=make_sql_string_and_free((yyvsp[-3].sql_string),kw_comma,(yyvsp[-1].sql_string),acl_strdup((yyvsp[0].str)), NULL);
}
#line 4466 "y.tab.c" /* yacc.c:1646  */
    break;

  case 118:
#line 1256 "sql.yacc" /* yacc.c:1646  */
    {strcpy((yyval.str),"");}
#line 4472 "y.tab.c" /* yacc.c:1646  */
    break;

  case 119:
#line 1257 "sql.yacc" /* yacc.c:1646  */
    {SPRINTF2((yyval.str)," %s %s",(yyvsp[-1].str),(yyvsp[0].str)); add_feature("DDL_CONSTRAINT");}
#line 4478 "y.tab.c" /* yacc.c:1646  */
    break;

  case 120:
#line 1262 "sql.yacc" /* yacc.c:1646  */
    { SPRINTF1((yyval.str),"DROP CONSTRAINT %s",(yyvsp[0].str)); add_feature("DROP_CONSTRAINT"); }
#line 4484 "y.tab.c" /* yacc.c:1646  */
    break;

  case 121:
#line 1263 "sql.yacc" /* yacc.c:1646  */
    {add_feature("DROP_CONSTRAINT");
		SPRINTF1((yyval.str),"DROP CONSTRAINT (%s)",(yyvsp[-1].str));
	}
#line 4492 "y.tab.c" /* yacc.c:1646  */
    break;

  case 122:
#line 1269 "sql.yacc" /* yacc.c:1646  */
    {strcpy((yyval.str),(yyvsp[0].str));}
#line 4498 "y.tab.c" /* yacc.c:1646  */
    break;

  case 123:
#line 1270 "sql.yacc" /* yacc.c:1646  */
    {SPRINTF2((yyval.str),"%s,%s",(yyvsp[-2].str),(yyvsp[0].str));}
#line 4504 "y.tab.c" /* yacc.c:1646  */
    break;

  case 125:
#line 1284 "sql.yacc" /* yacc.c:1646  */
    {  add_feature("ROLLBACK_WORK"); }
#line 4510 "y.tab.c" /* yacc.c:1646  */
    break;

  case 126:
#line 1290 "sql.yacc" /* yacc.c:1646  */
    { insql=1;}
#line 4516 "y.tab.c" /* yacc.c:1646  */
    break;

  case 127:
#line 1290 "sql.yacc" /* yacc.c:1646  */
    {
		(yyval.insert_cmd)=(yyvsp[0].insert_cmd);
		(yyval.insert_cmd)->connid=0;
		(yyval.insert_cmd)->table=acl_strdup((yyvsp[-2].str));
		A4GL_set_associated_mem((yyval.insert_cmd), (yyval.insert_cmd)->table);
		(yyval.insert_cmd)->column_list=(yyvsp[-1].str_list);
	}
#line 4528 "y.tab.c" /* yacc.c:1646  */
    break;

  case 128:
#line 1299 "sql.yacc" /* yacc.c:1646  */
    {insql=1;}
#line 4534 "y.tab.c" /* yacc.c:1646  */
    break;

  case 129:
#line 1299 "sql.yacc" /* yacc.c:1646  */
    { 
		(yyval.insert_cmd)=malloc(sizeof(struct_insert_cmd));
		(yyval.insert_cmd)->connid=0;
		(yyval.insert_cmd)->column_list=0;
		(yyval.insert_cmd)->table=0;
		(yyval.insert_cmd)->value_list=0;
		(yyval.insert_cmd)->subselect=0;
		(yyval.insert_cmd)->value_list= expand_slil((yyvsp[-1].s_select_list_item_list));
	}
#line 4548 "y.tab.c" /* yacc.c:1646  */
    break;

  case 130:
#line 1308 "sql.yacc" /* yacc.c:1646  */
    {
				if ((yyvsp[0].s_select)->sf==0) {
				        (yyvsp[0].s_select)->sf=acl_malloc2(sizeof(struct s_select_finish));
					(yyvsp[0].s_select)->sf->order_by=0;
					(yyvsp[0].s_select)->sf->into_temp=0;
					(yyvsp[0].s_select)->sf->nolog=0;
					(yyvsp[0].s_select)->sf->insert_into=0;
					A4GL_set_associated_mem((yyvsp[0].s_select), (yyvsp[0].s_select)->sf);
				}
				(yyvsp[0].s_select)->sf->insert_into=0;
		
        			map_select_stmt("SELECT",(yyvsp[0].s_select));
				add_feature("INSERT_INTO_SELECT_FROM");
	        (yyval.insert_cmd)=malloc(sizeof(struct_insert_cmd));
                (yyval.insert_cmd)->connid=0;
                (yyval.insert_cmd)->column_list=0;
                (yyval.insert_cmd)->table=0;
                (yyval.insert_cmd)->value_list=0;
                (yyval.insert_cmd)->subselect=(yyvsp[0].s_select);
	}
#line 4573 "y.tab.c" /* yacc.c:1646  */
    break;

  case 131:
#line 1333 "sql.yacc" /* yacc.c:1646  */
    {
			(yyval.str_list)=0;
	}
#line 4581 "y.tab.c" /* yacc.c:1646  */
    break;

  case 132:
#line 1336 "sql.yacc" /* yacc.c:1646  */
    {
			(yyval.str_list)=(yyvsp[-1].str_list);
			 add_feature("INSERT_COLUMNLIST_EQ_VALUELIST");
	}
#line 4590 "y.tab.c" /* yacc.c:1646  */
    break;

  case 133:
#line 1344 "sql.yacc" /* yacc.c:1646  */
    {
                        (yyval.str_list)=new_str_list((yyvsp[0].str));
	}
#line 4598 "y.tab.c" /* yacc.c:1646  */
    break;

  case 134:
#line 1347 "sql.yacc" /* yacc.c:1646  */
    {
                        (yyval.str_list)=add_str_list((yyvsp[-2].str_list), (yyvsp[0].str));
	}
#line 4606 "y.tab.c" /* yacc.c:1646  */
    break;

  case 135:
#line 1354 "sql.yacc" /* yacc.c:1646  */
    {	
			strcpy((yyval.str),(yyvsp[0].str));
	}
#line 4614 "y.tab.c" /* yacc.c:1646  */
    break;

  case 136:
#line 1357 "sql.yacc" /* yacc.c:1646  */
    { 
			/* with a table prefix - on an insert ? We'll just silently drop it... */
			strcpy((yyval.str),(yyvsp[0].str));
			A4GL_warn("Dropped table prefix from INSERT column name");
	}
#line 4624 "y.tab.c" /* yacc.c:1646  */
    break;

  case 137:
#line 1365 "sql.yacc" /* yacc.c:1646  */
    { (yyval.s_select_list_item_list)=local_new_select_list_item_list((yyvsp[0].s_select_list_item));}
#line 4630 "y.tab.c" /* yacc.c:1646  */
    break;

  case 138:
#line 1366 "sql.yacc" /* yacc.c:1646  */
    {
		(yyval.s_select_list_item_list)=local_add_select_list_item_list((yyvsp[-2].s_select_list_item_list),(yyvsp[0].s_select_list_item));
	}
#line 4638 "y.tab.c" /* yacc.c:1646  */
    break;

  case 139:
#line 1372 "sql.yacc" /* yacc.c:1646  */
    {(yyval.s_select_list_item)=(yyvsp[0].s_select_list_item);}
#line 4644 "y.tab.c" /* yacc.c:1646  */
    break;

  case 140:
#line 1373 "sql.yacc" /* yacc.c:1646  */
    {(yyval.s_select_list_item)=new_select_list_item_builtin_const(E_SLI_BUILTIN_CONST_NULL); }
#line 4650 "y.tab.c" /* yacc.c:1646  */
    break;

  case 141:
#line 1381 "sql.yacc" /* yacc.c:1646  */
    {

			if ((yyvsp[0].ptr)==0 && (yyvsp[-2].integer_val)>=0) { 
				if (A4GL_isyes(acl_getenv("A4GL_ERR_DELNOWHERE"))) {
					yylineno=(yyvsp[-2].integer_val);
					a4gl_yyerror("DELETE with no WHERE clause"); 
				} else {
					A4GL_warn("DELETE with no WHERE clause"); 
				}
			}
			add_feature("ANSI_DELETE");

			(yyval.delete_cmd)=malloc(sizeof(struct struct_delete_cmd));
			(yyval.delete_cmd)->connid=NULL;
			(yyval.delete_cmd)->table=acl_strdup((yyvsp[-1].str));
			(yyval.delete_cmd)->where_clause=(yyvsp[0].ptr);	
			A4GL_set_associated_mem((yyval.delete_cmd), (yyval.delete_cmd)->table);
			
		}
#line 4674 "y.tab.c" /* yacc.c:1646  */
    break;

  case 142:
#line 1403 "sql.yacc" /* yacc.c:1646  */
    { add_feature("BEGIN_WORK"); }
#line 4680 "y.tab.c" /* yacc.c:1646  */
    break;

  case 143:
#line 1407 "sql.yacc" /* yacc.c:1646  */
    { add_feature("COMMIT_WORK"); }
#line 4686 "y.tab.c" /* yacc.c:1646  */
    break;

  case 144:
#line 1412 "sql.yacc" /* yacc.c:1646  */
    {(yyval.e_boolean)=EB_FALSE;}
#line 4692 "y.tab.c" /* yacc.c:1646  */
    break;

  case 145:
#line 1413 "sql.yacc" /* yacc.c:1646  */
    {
		add_feature("DATABASE_EXCLUSIVE");
		{(yyval.e_boolean)=EB_TRUE;}
	}
#line 4701 "y.tab.c" /* yacc.c:1646  */
    break;

  case 146:
#line 1423 "sql.yacc" /* yacc.c:1646  */
    {
	char buff[256];
	(yyval.sql_string)=make_sql_string_and_free(acl_strdup((yyvsp[0].str)),NULL);
	SPRINTF1(buff,"Warning: Informix specific SQL @ line %d\n",yylineno);
	ansi_violation(buff,1);
	}
#line 4712 "y.tab.c" /* yacc.c:1646  */
    break;

  case 147:
#line 1432 "sql.yacc" /* yacc.c:1646  */
    {
			add_feature("START_DATABASE_WITH_LOG_MODE_ANSI");
			sprintf((yyval.str),"START DATABASE %s WITH LOG IN %s MODE ANSI", (yyvsp[-3].str),(yyvsp[-1].str));
	}
#line 4721 "y.tab.c" /* yacc.c:1646  */
    break;

  case 148:
#line 1436 "sql.yacc" /* yacc.c:1646  */
    {
			add_feature("START_DATABASE_WITH_LOG");
			sprintf((yyval.str),"START DATABASE %s WITH LOG IN %s", (yyvsp[-2].str),(yyvsp[0].str));
	}
#line 4730 "y.tab.c" /* yacc.c:1646  */
    break;

  case 149:
#line 1441 "sql.yacc" /* yacc.c:1646  */
    {
			add_feature("SET_CONSTRAINTS_ALL_IMMEDIATE");
			SPRINTF1((yyval.str),"%s",(yyvsp[0].str)); 
	}
#line 4739 "y.tab.c" /* yacc.c:1646  */
    break;

  case 150:
#line 1445 "sql.yacc" /* yacc.c:1646  */
    {
		add_feature("SET_BUFFERED_LOG");
			SPRINTF1((yyval.str),"%s",(yyvsp[0].str)); 
	}
#line 4748 "y.tab.c" /* yacc.c:1646  */
    break;

  case 151:
#line 1449 "sql.yacc" /* yacc.c:1646  */
    {
		add_feature("SET_LOG");
			SPRINTF1((yyval.str),"%s",(yyvsp[0].str)); 
	}
#line 4757 "y.tab.c" /* yacc.c:1646  */
    break;

  case 152:
#line 1453 "sql.yacc" /* yacc.c:1646  */
    {
			SPRINTF2((yyval.str),"%s %s",(yyvsp[-1].str),(yyvsp[0].str)); add_feature("UPDATE_STATISTICS_TABLE");
	}
#line 4765 "y.tab.c" /* yacc.c:1646  */
    break;

  case 153:
#line 1456 "sql.yacc" /* yacc.c:1646  */
    {
		add_feature("UPDATE_STATISTICS");
			SPRINTF1((yyval.str),"%s",(yyvsp[0].str)); 
	}
#line 4774 "y.tab.c" /* yacc.c:1646  */
    break;

  case 154:
#line 1463 "sql.yacc" /* yacc.c:1646  */
    { (yyval.integer_val)=1; 
#ifndef  SQLCOMPILER
				set_cmdlineno(token_read_on_line);
#endif

}
#line 4785 "y.tab.c" /* yacc.c:1646  */
    break;

  case 155:
#line 1469 "sql.yacc" /* yacc.c:1646  */
    { (yyval.integer_val)=-1; 
#ifndef  SQLCOMPILER
set_cmdlineno(token_read_on_line);
#endif
}
#line 4795 "y.tab.c" /* yacc.c:1646  */
    break;

  case 156:
#line 1474 "sql.yacc" /* yacc.c:1646  */
    { (yyval.integer_val)=0; 
#ifndef  SQLCOMPILER
set_cmdlineno(token_read_on_line);
#endif
}
#line 4805 "y.tab.c" /* yacc.c:1646  */
    break;

  case 157:
#line 1482 "sql.yacc" /* yacc.c:1646  */
    { (yyval.sql_string)=(yyvsp[0].sql_string); }
#line 4811 "y.tab.c" /* yacc.c:1646  */
    break;

  case 158:
#line 1483 "sql.yacc" /* yacc.c:1646  */
    { (yyval.sql_string)=(yyvsp[0].sql_string); }
#line 4817 "y.tab.c" /* yacc.c:1646  */
    break;

  case 159:
#line 1484 "sql.yacc" /* yacc.c:1646  */
    { (yyval.sql_string)=(yyvsp[0].sql_string); }
#line 4823 "y.tab.c" /* yacc.c:1646  */
    break;

  case 160:
#line 1485 "sql.yacc" /* yacc.c:1646  */
    { (yyval.sql_string)=(yyvsp[0].sql_string); }
#line 4829 "y.tab.c" /* yacc.c:1646  */
    break;

  case 161:
#line 1486 "sql.yacc" /* yacc.c:1646  */
    { (yyval.sql_string)=(yyvsp[0].sql_string); }
#line 4835 "y.tab.c" /* yacc.c:1646  */
    break;

  case 162:
#line 1487 "sql.yacc" /* yacc.c:1646  */
    { (yyval.sql_string)=(yyvsp[0].sql_string); }
#line 4841 "y.tab.c" /* yacc.c:1646  */
    break;

  case 163:
#line 1488 "sql.yacc" /* yacc.c:1646  */
    { (yyval.sql_string)=(yyvsp[0].sql_string); }
#line 4847 "y.tab.c" /* yacc.c:1646  */
    break;

  case 164:
#line 1496 "sql.yacc" /* yacc.c:1646  */
    {SPRINTF7((yyval.str),"%s %s %s %s %s %s %s",(yyvsp[-6].str),(yyvsp[-5].str),(yyvsp[-4].str),(yyvsp[-3].str),(yyvsp[-2].str),(yyvsp[-1].str),(yyvsp[0].str));  add_feature("GRANT"); }
#line 4853 "y.tab.c" /* yacc.c:1646  */
    break;

  case 165:
#line 1497 "sql.yacc" /* yacc.c:1646  */
    {SPRINTF6((yyval.str),"%s %s %s %s %s %s",(yyvsp[-5].str),(yyvsp[-4].str),(yyvsp[-3].str),(yyvsp[-2].str),(yyvsp[-1].str),(yyvsp[0].str));  add_feature("REVOKE"); }
#line 4859 "y.tab.c" /* yacc.c:1646  */
    break;

  case 166:
#line 1498 "sql.yacc" /* yacc.c:1646  */
    {SPRINTF4((yyval.str),"%s %s %s %s ",(yyvsp[-3].str),(yyvsp[-2].str),(yyvsp[-1].str),(yyvsp[0].str)); add_feature("GRANT"); }
#line 4865 "y.tab.c" /* yacc.c:1646  */
    break;

  case 167:
#line 1499 "sql.yacc" /* yacc.c:1646  */
    {SPRINTF4((yyval.str),"%s %s %s %s ",(yyvsp[-3].str),(yyvsp[-2].str),(yyvsp[-1].str),(yyvsp[0].str));  add_feature("REVOKE"); }
#line 4871 "y.tab.c" /* yacc.c:1646  */
    break;

  case 171:
#line 1509 "sql.yacc" /* yacc.c:1646  */
    {strcpy((yyval.str),"");}
#line 4877 "y.tab.c" /* yacc.c:1646  */
    break;

  case 172:
#line 1510 "sql.yacc" /* yacc.c:1646  */
    {SPRINTF1((yyval.str)," %s ",(yyvsp[0].str));}
#line 4883 "y.tab.c" /* yacc.c:1646  */
    break;

  case 173:
#line 1511 "sql.yacc" /* yacc.c:1646  */
    {SPRINTF2((yyval.str)," %s %s",(yyvsp[-1].str),(yyvsp[0].str));}
#line 4889 "y.tab.c" /* yacc.c:1646  */
    break;

  case 174:
#line 1515 "sql.yacc" /* yacc.c:1646  */
    {SPRINTF1((yyval.str)," %s ",(yyvsp[0].str));}
#line 4895 "y.tab.c" /* yacc.c:1646  */
    break;

  case 175:
#line 1516 "sql.yacc" /* yacc.c:1646  */
    {SPRINTF1((yyval.str)," %s ",(yyvsp[0].str));}
#line 4901 "y.tab.c" /* yacc.c:1646  */
    break;

  case 178:
#line 1523 "sql.yacc" /* yacc.c:1646  */
    {SPRINTF3((yyval.str)," %s %s %s",(yyvsp[-2].str),(yyvsp[-1].str),(yyvsp[0].str));}
#line 4907 "y.tab.c" /* yacc.c:1646  */
    break;

  case 179:
#line 1526 "sql.yacc" /* yacc.c:1646  */
    {
		if (A4GLSQLCV_check_requirement("SIMPLE_GRANT_SELECT"))  {
			SPRINTF0((yyval.str)," SELECT");
		} else {
			SPRINTF2((yyval.str)," %s %s",(yyvsp[-1].str),(yyvsp[0].str));
		}
	}
#line 4919 "y.tab.c" /* yacc.c:1646  */
    break;

  case 182:
#line 1535 "sql.yacc" /* yacc.c:1646  */
    {
		if (A4GLSQLCV_check_requirement("SIMPLE_GRANT_UPDATE"))  {
			SPRINTF0((yyval.str)," UPDATE");
		} else {
			SPRINTF2((yyval.str)," %s %s",(yyvsp[-1].str),(yyvsp[0].str));
		}
	}
#line 4931 "y.tab.c" /* yacc.c:1646  */
    break;

  case 185:
#line 1546 "sql.yacc" /* yacc.c:1646  */
    {strcpy((yyval.str),"");}
#line 4937 "y.tab.c" /* yacc.c:1646  */
    break;

  case 186:
#line 1548 "sql.yacc" /* yacc.c:1646  */
    {SPRINTF3((yyval.str)," %s %s %s",(yyvsp[-2].str),(yyvsp[-1].str),(yyvsp[0].str));}
#line 4943 "y.tab.c" /* yacc.c:1646  */
    break;

  case 188:
#line 1554 "sql.yacc" /* yacc.c:1646  */
    {SPRINTF3((yyval.str)," %s %s %s",(yyvsp[-2].str),(yyvsp[-1].str),(yyvsp[0].str));}
#line 4949 "y.tab.c" /* yacc.c:1646  */
    break;

  case 190:
#line 1560 "sql.yacc" /* yacc.c:1646  */
    {SPRINTF3((yyval.str)," %s %s %s",(yyvsp[-2].str),(yyvsp[-1].str),(yyvsp[0].str));}
#line 4955 "y.tab.c" /* yacc.c:1646  */
    break;

  case 193:
#line 1570 "sql.yacc" /* yacc.c:1646  */
    {
		add_feature("CREATE_VIEW_AS_SELECT");
		(yyval.sql_string)=make_sql_string_and_free(acl_strdup((yyvsp[-5].str)),kw_space,acl_strdup((yyvsp[-4].str)),kw_space,acl_strdup((yyvsp[-3].str)),kw_space,acl_strdup((yyvsp[-2].str)),kw_space,(yyvsp[-1].sql_string),kw_space,acl_strdup((yyvsp[0].str)),NULL);
	
}
#line 4965 "y.tab.c" /* yacc.c:1646  */
    break;

  case 194:
#line 1577 "sql.yacc" /* yacc.c:1646  */
    {strcpy((yyval.str),"");}
#line 4971 "y.tab.c" /* yacc.c:1646  */
    break;

  case 195:
#line 1579 "sql.yacc" /* yacc.c:1646  */
    {SPRINTF3((yyval.str)," %s %s %s",(yyvsp[-2].str),(yyvsp[-1].str),(yyvsp[0].str));}
#line 4977 "y.tab.c" /* yacc.c:1646  */
    break;

  case 197:
#line 1585 "sql.yacc" /* yacc.c:1646  */
    {SPRINTF3((yyval.str)," %s %s %s",(yyvsp[-2].str),(yyvsp[-1].str),(yyvsp[0].str));}
#line 4983 "y.tab.c" /* yacc.c:1646  */
    break;

  case 198:
#line 1588 "sql.yacc" /* yacc.c:1646  */
    {strcpy((yyval.str),"");}
#line 4989 "y.tab.c" /* yacc.c:1646  */
    break;

  case 199:
#line 1589 "sql.yacc" /* yacc.c:1646  */
    {
		add_feature("CREATE_VIEW_SELECT_WITH_CHECK");
	}
#line 4997 "y.tab.c" /* yacc.c:1646  */
    break;

  case 200:
#line 1596 "sql.yacc" /* yacc.c:1646  */
    {
		(yyval.sql_string)=make_sql_string_and_free(strdup("CHECK ("),(yyvsp[-1].sql_string),kw_cb,NULL);
		add_feature("DDL_CHECK");
	}
#line 5006 "y.tab.c" /* yacc.c:1646  */
    break;

  case 201:
#line 1605 "sql.yacc" /* yacc.c:1646  */
    {SPRINTF5((yyval.str)," %s %s %s %s %s",(yyvsp[-4].str),(yyvsp[-3].str),(yyvsp[-2].str),(yyvsp[-1].str),(yyvsp[0].str));
	add_feature("DDL_FOREIGN_KEY");
}
#line 5014 "y.tab.c" /* yacc.c:1646  */
    break;

  case 202:
#line 1612 "sql.yacc" /* yacc.c:1646  */
    {SPRINTF2((yyval.str)," %s %s",(yyvsp[-1].str),(yyvsp[0].str));
add_feature("DDL_REFERENCES");
}
#line 5022 "y.tab.c" /* yacc.c:1646  */
    break;

  case 205:
#line 1624 "sql.yacc" /* yacc.c:1646  */
    {SPRINTF4((yyval.str)," %s %s %s %s",(yyvsp[-3].str),(yyvsp[-2].str),(yyvsp[-1].str),(yyvsp[0].str));}
#line 5028 "y.tab.c" /* yacc.c:1646  */
    break;

  case 207:
#line 1630 "sql.yacc" /* yacc.c:1646  */
    {SPRINTF3((yyval.str)," %s %s %s",(yyvsp[-2].str),(yyvsp[-1].str),(yyvsp[0].str));}
#line 5034 "y.tab.c" /* yacc.c:1646  */
    break;

  case 208:
#line 1635 "sql.yacc" /* yacc.c:1646  */
    {
		SPRINTF3((yyval.str)," UNIQUE %s %s %s",(yyvsp[-2].str),(yyvsp[-1].str),(yyvsp[0].str));
add_feature("DDL_UNIQUE");
	}
#line 5043 "y.tab.c" /* yacc.c:1646  */
    break;

  case 209:
#line 1639 "sql.yacc" /* yacc.c:1646  */
    {
		ansi_violation("Use UNIQUE not DISTINCT",0);
		SPRINTF3((yyval.str)," UNIQUE %s %s %s",(yyvsp[-2].str),(yyvsp[-1].str),(yyvsp[0].str));
add_feature("DDL_DISTINCT");
	}
#line 5053 "y.tab.c" /* yacc.c:1646  */
    break;

  case 210:
#line 1645 "sql.yacc" /* yacc.c:1646  */
    {SPRINTF4((yyval.str)," %s %s %s %s",(yyvsp[-3].str),(yyvsp[-2].str),(yyvsp[-1].str),(yyvsp[0].str));
add_feature("DDL_PRIMARY_KEY");
}
#line 5061 "y.tab.c" /* yacc.c:1646  */
    break;

  case 212:
#line 1653 "sql.yacc" /* yacc.c:1646  */
    {SPRINTF3((yyval.str)," %s %s %s",(yyvsp[-2].str),(yyvsp[-1].str),(yyvsp[0].str));}
#line 5067 "y.tab.c" /* yacc.c:1646  */
    break;

  case 213:
#line 1658 "sql.yacc" /* yacc.c:1646  */
    {
		(yyval.sql_string)=acl_strdup((yyvsp[0].str));
	}
#line 5075 "y.tab.c" /* yacc.c:1646  */
    break;

  case 214:
#line 1661 "sql.yacc" /* yacc.c:1646  */
    {
		(yyval.sql_string)=acl_strdup((yyvsp[0].str));
	}
#line 5083 "y.tab.c" /* yacc.c:1646  */
    break;

  case 215:
#line 1664 "sql.yacc" /* yacc.c:1646  */
    {
		(yyval.sql_string)=(yyvsp[0].sql_string);
	}
#line 5091 "y.tab.c" /* yacc.c:1646  */
    break;

  case 216:
#line 1671 "sql.yacc" /* yacc.c:1646  */
    {SPRINTF2((yyval.str)," %s %s",(yyvsp[-1].str),(yyvsp[0].str)); add_feature("DDL_DEFAULT_VALUE"); }
#line 5097 "y.tab.c" /* yacc.c:1646  */
    break;

  case 217:
#line 1672 "sql.yacc" /* yacc.c:1646  */
    {SPRINTF1((yyval.str)," DEFAULT %s", A4GLSQLCV_get_sqlconst("USER")); add_feature("DDL_DEFAULT_VALUE"); }
#line 5103 "y.tab.c" /* yacc.c:1646  */
    break;

  case 218:
#line 1673 "sql.yacc" /* yacc.c:1646  */
    {SPRINTF1((yyval.str)," DEFAULT %s", A4GLSQLCV_get_sqlconst("TODAY")); add_feature("DDL_DEFAULT_VALUE"); }
#line 5109 "y.tab.c" /* yacc.c:1646  */
    break;

  case 219:
#line 1674 "sql.yacc" /* yacc.c:1646  */
    { SPRINTF1((yyval.str)," %s",(yyvsp[0].str)); add_feature("DDL_DEFAULT_VALUE"); }
#line 5115 "y.tab.c" /* yacc.c:1646  */
    break;

  case 220:
#line 1680 "sql.yacc" /* yacc.c:1646  */
    {

#ifdef DEBUG
			A4GL_debug("Str1:%s",(yyvsp[-3].str));
			A4GL_debug("Str2:%s",(yyvsp[-2].str));
			A4GL_debug("Str3:%s",(yyvsp[-1].str));
			A4GL_debug("Str4:%s",(yyvsp[0].sql_string));
#endif

                (yyval.sql_string)=make_sql_string_and_free(acl_strdup((yyvsp[-3].str)),kw_space,acl_strdup((yyvsp[-2].str)),NULL);
                if (strlen((yyvsp[-1].str))) {
                        (yyval.sql_string)=make_sql_string_and_free((yyval.sql_string), kw_space,acl_strdup((yyvsp[-1].str)),NULL);
                }
                if (strlen((yyvsp[0].sql_string))) {
                        (yyval.sql_string)=make_sql_string_and_free((yyval.sql_string), kw_space,acl_strdup((yyvsp[0].sql_string)),NULL);
                } else {
			free((yyvsp[0].sql_string));
		}


	}
#line 5141 "y.tab.c" /* yacc.c:1646  */
    break;

  case 221:
#line 1703 "sql.yacc" /* yacc.c:1646  */
    {strcpy((yyval.str),"");}
#line 5147 "y.tab.c" /* yacc.c:1646  */
    break;

  case 223:
#line 1707 "sql.yacc" /* yacc.c:1646  */
    {
		(yyval.sql_string)=acl_strdup("");
	}
#line 5155 "y.tab.c" /* yacc.c:1646  */
    break;

  case 224:
#line 1709 "sql.yacc" /* yacc.c:1646  */
    {
		(yyval.sql_string)=(yyvsp[0].sql_string);
	}
#line 5163 "y.tab.c" /* yacc.c:1646  */
    break;

  case 225:
#line 1716 "sql.yacc" /* yacc.c:1646  */
    {
		(yyval.sql_string)=(yyvsp[0].sql_string);
	}
#line 5171 "y.tab.c" /* yacc.c:1646  */
    break;

  case 226:
#line 1719 "sql.yacc" /* yacc.c:1646  */
    {
		(yyval.sql_string)=make_sql_string_and_free((yyvsp[-1].sql_string),kw_space,(yyvsp[0].sql_string),NULL);
	}
#line 5179 "y.tab.c" /* yacc.c:1646  */
    break;

  case 227:
#line 1725 "sql.yacc" /* yacc.c:1646  */
    {
		(yyval.sql_string)=make_sql_string_and_free((yyvsp[-1].sql_string),acl_strdup((yyvsp[0].str)),NULL);
	}
#line 5187 "y.tab.c" /* yacc.c:1646  */
    break;

  case 228:
#line 1733 "sql.yacc" /* yacc.c:1646  */
    {
		SPRINTF1((yyval.str)," %s ",(yyvsp[0].str));
		(yyval.sql_string)=acl_strdup((yyval.str));
		add_feature("DDL_NOT_NULL");
	}
#line 5197 "y.tab.c" /* yacc.c:1646  */
    break;

  case 229:
#line 1738 "sql.yacc" /* yacc.c:1646  */
    {
		SPRINTF0((yyval.str)," NOT NULL UNIQUE ");
		(yyval.sql_string)=acl_strdup((yyval.str));
		add_feature("DDL_NOT_NULL");
		add_feature("DDL_UNIQUE");
	}
#line 5208 "y.tab.c" /* yacc.c:1646  */
    break;

  case 230:
#line 1744 "sql.yacc" /* yacc.c:1646  */
    {
		SPRINTF0((yyval.str)," UNIQUE ");
		(yyval.sql_string)=acl_strdup((yyval.str));
		add_feature("DDL_UNIQUE");
	}
#line 5218 "y.tab.c" /* yacc.c:1646  */
    break;

  case 231:
#line 1749 "sql.yacc" /* yacc.c:1646  */
    {
		ansi_violation("Use UNIQUE not DISTINCT",0);
		SPRINTF0((yyval.str)," UNIQUE ");
		(yyval.sql_string)=acl_strdup((yyval.str));
		add_feature("DDL_DISTINCT");
	}
#line 5229 "y.tab.c" /* yacc.c:1646  */
    break;

  case 232:
#line 1755 "sql.yacc" /* yacc.c:1646  */
    {
		(yyval.sql_string)=acl_strdup((yyvsp[0].str));
	}
#line 5237 "y.tab.c" /* yacc.c:1646  */
    break;

  case 233:
#line 1758 "sql.yacc" /* yacc.c:1646  */
    {
		(yyval.sql_string)=make_sql_string_and_free(acl_strdup("CHECK ("),(yyvsp[-1].sql_string),kw_cb,NULL);
		add_feature("DDL_CHECK");
		
	}
#line 5247 "y.tab.c" /* yacc.c:1646  */
    break;

  case 234:
#line 1763 "sql.yacc" /* yacc.c:1646  */
    {
		(yyval.sql_string)=make_sql_string_and_free(acl_strdup(" PRIMARY KEY "),NULL);
		add_feature("DDL_PRIMARY_KEY");
	}
#line 5256 "y.tab.c" /* yacc.c:1646  */
    break;

  case 235:
#line 1772 "sql.yacc" /* yacc.c:1646  */
    {
		add_feature("CREATE_SCHEMA");

(yyval.sql_string)=make_sql_string_and_free(acl_strdup((yyvsp[-2].str)),kw_space,acl_strdup((yyvsp[-1].str)),kw_space,acl_strdup((yyvsp[0].str)),NULL);
}
#line 5266 "y.tab.c" /* yacc.c:1646  */
    break;

  case 236:
#line 1781 "sql.yacc" /* yacc.c:1646  */
    {SPRINTF1((yyval.str)," %s",(yyvsp[0].str));}
#line 5272 "y.tab.c" /* yacc.c:1646  */
    break;

  case 239:
#line 1790 "sql.yacc" /* yacc.c:1646  */
    {
		(yyval.sql_string)=make_sql_string_and_free((yyvsp[-1].sql_string),kw_space,(yyvsp[0].sql_string),NULL);
	}
#line 5280 "y.tab.c" /* yacc.c:1646  */
    break;

  case 240:
#line 1796 "sql.yacc" /* yacc.c:1646  */
    {
		(yyval.sql_string)=(yyvsp[0].sql_string);
	}
#line 5288 "y.tab.c" /* yacc.c:1646  */
    break;

  case 241:
#line 1799 "sql.yacc" /* yacc.c:1646  */
    {
		(yyval.sql_string)=acl_strdup((yyvsp[0].str));
	}
#line 5296 "y.tab.c" /* yacc.c:1646  */
    break;

  case 242:
#line 1810 "sql.yacc" /* yacc.c:1646  */
    {
		 add_feature("HAVING"); 
		(yyval.s_select_list_item)=(yyvsp[0].s_select_list_item);
	}
#line 5305 "y.tab.c" /* yacc.c:1646  */
    break;

  case 243:
#line 1819 "sql.yacc" /* yacc.c:1646  */
    {
		 (yyval.s_select_list_item)=(yyvsp[0].s_select_list_item);
	}
#line 5313 "y.tab.c" /* yacc.c:1646  */
    break;

  case 244:
#line 1826 "sql.yacc" /* yacc.c:1646  */
    {
		(yyval.u_table)=(yyvsp[0].u_table);
	}
#line 5321 "y.tab.c" /* yacc.c:1646  */
    break;

  case 245:
#line 1832 "sql.yacc" /* yacc.c:1646  */
    {(yyval.u_table)=(yyvsp[0].u_table);}
#line 5327 "y.tab.c" /* yacc.c:1646  */
    break;

  case 246:
#line 1833 "sql.yacc" /* yacc.c:1646  */
    {
		(yyval.u_table)=A4GLSQLPARSE_append_tablename((yyvsp[-2].u_table),(yyvsp[0].u_table),E_OUTER_NONE,NULL);
	}
#line 5335 "y.tab.c" /* yacc.c:1646  */
    break;

  case 247:
#line 1836 "sql.yacc" /* yacc.c:1646  */
    {
		(yyval.u_table)=A4GLSQLPARSE_append_tablename((yyvsp[-3].u_table),(yyvsp[0].u_table),E_OUTER_NORMAL,NULL);
		A4GL_warn("OUTER join *may* not be portable to non-informix database");
		add_feature("SELECT_OUTER");
	}
#line 5345 "y.tab.c" /* yacc.c:1646  */
    break;

  case 248:
#line 1841 "sql.yacc" /* yacc.c:1646  */
    {
		(yyval.u_table)=A4GLSQLPARSE_append_tablename((yyvsp[-5].u_table),(yyvsp[-1].u_table),E_OUTER_NORMAL,NULL);
		A4GL_warn("OUTER join *may* not be portable to non-informix database");
		add_feature("SELECT_OUTER");
	}
#line 5355 "y.tab.c" /* yacc.c:1646  */
    break;

  case 249:
#line 1852 "sql.yacc" /* yacc.c:1646  */
    {
		(yyval.u_table)=A4GLSQLPARSE_append_tablename((yyvsp[-4].u_table),(yyvsp[-2].u_table),E_OUTER_LEFT_OUTER, (yyvsp[0].s_select_list_item));
		add_feature("SELECT_OUTER");
	}
#line 5364 "y.tab.c" /* yacc.c:1646  */
    break;

  case 250:
#line 1856 "sql.yacc" /* yacc.c:1646  */
    {
		(yyval.u_table)=A4GLSQLPARSE_append_tablename((yyvsp[-4].u_table),(yyvsp[-2].u_table),E_INNER, (yyvsp[0].s_select_list_item));
		add_feature("SELECT_INNER");
	}
#line 5373 "y.tab.c" /* yacc.c:1646  */
    break;

  case 252:
#line 1864 "sql.yacc" /* yacc.c:1646  */
    {(yyval.u_table)=(yyvsp[-1].u_table);}
#line 5379 "y.tab.c" /* yacc.c:1646  */
    break;

  case 253:
#line 1868 "sql.yacc" /* yacc.c:1646  */
    { 
			//A4GL_add_crud("SELECT",$<str>1);
			(yyval.u_table)=A4GLSQLPARSE_new_tablename((yyvsp[0].str),NULL);
	}
#line 5388 "y.tab.c" /* yacc.c:1646  */
    break;

  case 254:
#line 1872 "sql.yacc" /* yacc.c:1646  */
    { 
			//A4GL_add_crud("SELECT",$<str>1);
			(yyval.u_table)=A4GLSQLPARSE_new_tablename((yyvsp[-1].str),(yyvsp[0].str));
	}
#line 5397 "y.tab.c" /* yacc.c:1646  */
    break;

  case 255:
#line 1876 "sql.yacc" /* yacc.c:1646  */
    { 
			//A4GL_add_crud("SELECT",$<str>1);
			(yyval.u_table)=A4GLSQLPARSE_new_tablename((yyvsp[-2].str),(yyvsp[0].str));
	}
#line 5406 "y.tab.c" /* yacc.c:1646  */
    break;

  case 256:
#line 1883 "sql.yacc" /* yacc.c:1646  */
    {
			/* No from or where etc.. */
			/* eg.. select user ; */
			(yyval.s_select)=new_empty_select();
		}
#line 5416 "y.tab.c" /* yacc.c:1646  */
    break;

  case 257:
#line 1888 "sql.yacc" /* yacc.c:1646  */
    {
		(yyval.s_select)=(yyvsp[0].s_select);
		(yyval.s_select)->first=(yyvsp[-1].u_table);
			A4GL_set_associated_mem( (yyval.s_select), (yyval.s_select)->first);
}
#line 5426 "y.tab.c" /* yacc.c:1646  */
    break;

  case 258:
#line 1896 "sql.yacc" /* yacc.c:1646  */
    {
		(yyval.s_select)=(yyvsp[0].s_select);
	}
#line 5434 "y.tab.c" /* yacc.c:1646  */
    break;

  case 259:
#line 1899 "sql.yacc" /* yacc.c:1646  */
    {
		(yyval.s_select)=(yyvsp[0].s_select);
		(yyval.s_select)->where_clause=(yyvsp[-1].s_select_list_item);
	}
#line 5443 "y.tab.c" /* yacc.c:1646  */
    break;

  case 260:
#line 1905 "sql.yacc" /* yacc.c:1646  */
    {
		(yyval.s_select)=new_empty_select();
	}
#line 5451 "y.tab.c" /* yacc.c:1646  */
    break;

  case 261:
#line 1908 "sql.yacc" /* yacc.c:1646  */
    {
		(yyval.s_select)=new_empty_select();
		(yyval.s_select)->group_by=(yyvsp[0].s_select_list_item_list);
		(yyval.s_select)->having=0;
	}
#line 5461 "y.tab.c" /* yacc.c:1646  */
    break;

  case 262:
#line 1913 "sql.yacc" /* yacc.c:1646  */
    {
		(yyval.s_select)=new_empty_select();
		(yyval.s_select)->group_by=(yyvsp[-1].s_select_list_item_list);
		(yyval.s_select)->having=(yyvsp[0].s_select_list_item);
	}
#line 5471 "y.tab.c" /* yacc.c:1646  */
    break;

  case 263:
#line 1918 "sql.yacc" /* yacc.c:1646  */
    {
		(yyval.s_select)=new_empty_select();
		(yyval.s_select)->group_by=0;
		(yyval.s_select)->having=(yyvsp[0].s_select_list_item);

	}
#line 5482 "y.tab.c" /* yacc.c:1646  */
    break;

  case 264:
#line 1931 "sql.yacc" /* yacc.c:1646  */
    {
		(yyval.s_select_list_item)=(yyvsp[0].s_select_list_item);
	}
#line 5490 "y.tab.c" /* yacc.c:1646  */
    break;

  case 265:
#line 1934 "sql.yacc" /* yacc.c:1646  */
    {
		(yyval.s_select_list_item)=new_select_list_item_op_expr((yyvsp[-2].s_select_list_item),(yyvsp[0].s_select_list_item)," OR ");
	}
#line 5498 "y.tab.c" /* yacc.c:1646  */
    break;

  case 266:
#line 1940 "sql.yacc" /* yacc.c:1646  */
    {
		(yyval.s_select_list_item)=(yyvsp[0].s_select_list_item);
	}
#line 5506 "y.tab.c" /* yacc.c:1646  */
    break;

  case 267:
#line 1943 "sql.yacc" /* yacc.c:1646  */
    {
		(yyval.s_select_list_item)=new_select_list_item_op_expr((yyvsp[-2].s_select_list_item),(yyvsp[0].s_select_list_item)," AND ");
	}
#line 5514 "y.tab.c" /* yacc.c:1646  */
    break;

  case 268:
#line 1949 "sql.yacc" /* yacc.c:1646  */
    {
		(yyval.s_select_list_item)=(yyvsp[0].s_select_list_item);
	}
#line 5522 "y.tab.c" /* yacc.c:1646  */
    break;

  case 269:
#line 1952 "sql.yacc" /* yacc.c:1646  */
    {
		(yyval.s_select_list_item)=new_select_list_item_simple_expr(E_SLI_NOT,(yyvsp[0].s_select_list_item));
	}
#line 5530 "y.tab.c" /* yacc.c:1646  */
    break;

  case 270:
#line 1958 "sql.yacc" /* yacc.c:1646  */
    {
		(yyval.s_select_list_item)=(yyvsp[0].s_select_list_item);
	}
#line 5538 "y.tab.c" /* yacc.c:1646  */
    break;

  case 271:
#line 1961 "sql.yacc" /* yacc.c:1646  */
    {
		(yyval.s_select_list_item)=new_select_list_item_simple_expr(E_SLI_BRACKET_EXPR,(yyvsp[-1].s_select_list_item));
	}
#line 5546 "y.tab.c" /* yacc.c:1646  */
    break;

  case 272:
#line 1968 "sql.yacc" /* yacc.c:1646  */
    {
		(yyval.s_select_list_item)=new_select_list_item_sq(E_SQE_EXISTS, (yyvsp[0].s_select_list_item));
		add_feature("WHERE_EXISTS");
	}
#line 5555 "y.tab.c" /* yacc.c:1646  */
    break;

  case 273:
#line 1972 "sql.yacc" /* yacc.c:1646  */
    {
		(yyval.s_select_list_item)=new_select_list_item_sq(E_SQE_NOT_EXISTS, (yyvsp[0].s_select_list_item));
		add_feature("WHERE_EXISTS");
	}
#line 5564 "y.tab.c" /* yacc.c:1646  */
    break;

  case 274:
#line 1983 "sql.yacc" /* yacc.c:1646  */
    {strcpy((yyval.str),"");}
#line 5570 "y.tab.c" /* yacc.c:1646  */
    break;

  case 275:
#line 1983 "sql.yacc" /* yacc.c:1646  */
    {SPRINTF1((yyval.str)," ESCAPE %s",(yyvsp[0].str));add_feature("WHERE_MATCHES_ESCAPE");}
#line 5576 "y.tab.c" /* yacc.c:1646  */
    break;

  case 276:
#line 1984 "sql.yacc" /* yacc.c:1646  */
    {strcpy((yyval.str),"");}
#line 5582 "y.tab.c" /* yacc.c:1646  */
    break;

  case 277:
#line 1984 "sql.yacc" /* yacc.c:1646  */
    {SPRINTF1((yyval.str)," ESCAPE %s",(yyvsp[0].str));add_feature("WHERE_ILIKE_ESCAPE");}
#line 5588 "y.tab.c" /* yacc.c:1646  */
    break;

  case 278:
#line 1985 "sql.yacc" /* yacc.c:1646  */
    {strcpy((yyval.str),"");}
#line 5594 "y.tab.c" /* yacc.c:1646  */
    break;

  case 279:
#line 1985 "sql.yacc" /* yacc.c:1646  */
    {SPRINTF1((yyval.str)," ESCAPE %s",(yyvsp[0].str));add_feature("WHERE_LIKE_ESCAPE");}
#line 5600 "y.tab.c" /* yacc.c:1646  */
    break;

  case 280:
#line 1988 "sql.yacc" /* yacc.c:1646  */
    {
		 (yyval.s_select_list_item)=(yyvsp[0].s_select_list_item);
	}
#line 5608 "y.tab.c" /* yacc.c:1646  */
    break;

  case 282:
#line 1998 "sql.yacc" /* yacc.c:1646  */
    {strcpy((yyval.str),"");}
#line 5614 "y.tab.c" /* yacc.c:1646  */
    break;

  case 283:
#line 1999 "sql.yacc" /* yacc.c:1646  */
    {strcpy((yyval.str)," NOT ");}
#line 5620 "y.tab.c" /* yacc.c:1646  */
    break;

  case 284:
#line 2004 "sql.yacc" /* yacc.c:1646  */
    { 
		if (strlen((yyvsp[-1].str))==0) {
			(yyval.s_select_list_item)=new_select_list_item_simple_expr(E_SLI_ISNULL,(yyvsp[-2].s_select_list_item));
		} else {
			(yyval.s_select_list_item)=new_select_list_item_simple_expr(E_SLI_ISNOTNULL,(yyvsp[-2].s_select_list_item));
		}

		add_feature("WHERE_NULL");
	}
#line 5634 "y.tab.c" /* yacc.c:1646  */
    break;

  case 285:
#line 2013 "sql.yacc" /* yacc.c:1646  */
    { 
		if (strlen((yyvsp[-1].str))==0) {
			(yyval.s_select_list_item)=new_select_list_item_simple_expr(E_SLI_ISNOTNULL,(yyvsp[-2].s_select_list_item));
		} else {
			(yyval.s_select_list_item)=new_select_list_item_simple_expr(E_SLI_ISNULL,(yyvsp[-2].s_select_list_item));
		}
		add_feature("WHERE_NULL");
	}
#line 5647 "y.tab.c" /* yacc.c:1646  */
    break;

  case 286:
#line 2021 "sql.yacc" /* yacc.c:1646  */
    { 
			(yyval.s_select_list_item)=new_select_list_item_op_expr((yyvsp[-2].s_select_list_item),(yyvsp[0].s_select_list_item),(yyvsp[-1].str));
	}
#line 5655 "y.tab.c" /* yacc.c:1646  */
    break;

  case 287:
#line 2024 "sql.yacc" /* yacc.c:1646  */
    { 
			(yyval.s_select_list_item)=new_select_list_item_op_expr((yyvsp[-2].s_select_list_item),(yyvsp[0].s_select_list_item),"=");
	}
#line 5663 "y.tab.c" /* yacc.c:1646  */
    break;

  case 288:
#line 2027 "sql.yacc" /* yacc.c:1646  */
    { 
			FPRINTF(stderr,"Warning: Corrected =NULL to IS NULL line %d\n",yylineno);
			(yyval.s_select_list_item)=new_select_list_item_simple_expr(E_SLI_ISNULL,(yyvsp[-2].s_select_list_item));
	}
#line 5672 "y.tab.c" /* yacc.c:1646  */
    break;

  case 289:
#line 2031 "sql.yacc" /* yacc.c:1646  */
    { 
		if (strlen((yyvsp[-4].str))) {
			(yyval.s_select_list_item)=new_select_list_item_op_between((yyvsp[-4].str),(yyvsp[-5].s_select_list_item),(yyvsp[-2].s_select_list_item),(yyvsp[0].s_select_list_item),1);
		} else {
			(yyval.s_select_list_item)=new_select_list_item_op_between((yyvsp[-4].str),(yyvsp[-5].s_select_list_item),(yyvsp[-2].s_select_list_item),(yyvsp[0].s_select_list_item),0);
		}
	}
#line 5684 "y.tab.c" /* yacc.c:1646  */
    break;

  case 290:
#line 2038 "sql.yacc" /* yacc.c:1646  */
    { 
			(yyval.s_select_list_item)=new_select_list_item_regex(E_SLI_REGEX_LIKE,(yyvsp[-3].s_select_list_item),(yyvsp[-1].s_select_list_item),(yyvsp[0].str));
	}
#line 5692 "y.tab.c" /* yacc.c:1646  */
    break;

  case 291:
#line 2041 "sql.yacc" /* yacc.c:1646  */
    { 
			(yyval.s_select_list_item)=new_select_list_item_regex(E_SLI_REGEX_NOT_LIKE,(yyvsp[-3].s_select_list_item),(yyvsp[-1].s_select_list_item),(yyvsp[0].str));

	}
#line 5701 "y.tab.c" /* yacc.c:1646  */
    break;

  case 292:
#line 2045 "sql.yacc" /* yacc.c:1646  */
    { 
			(yyval.s_select_list_item)=new_select_list_item_regex(E_SLI_REGEX_ILIKE,(yyvsp[-3].s_select_list_item),(yyvsp[-1].s_select_list_item),(yyvsp[0].str));
	}
#line 5709 "y.tab.c" /* yacc.c:1646  */
    break;

  case 293:
#line 2048 "sql.yacc" /* yacc.c:1646  */
    { 
			(yyval.s_select_list_item)=new_select_list_item_regex(E_SLI_REGEX_NOT_ILIKE,(yyvsp[-3].s_select_list_item),(yyvsp[-1].s_select_list_item),(yyvsp[0].str));
	}
#line 5717 "y.tab.c" /* yacc.c:1646  */
    break;

  case 294:
#line 2051 "sql.yacc" /* yacc.c:1646  */
    { 
			(yyval.s_select_list_item)=new_select_list_item_regex(E_SLI_REGEX_MATCHES,(yyvsp[-3].s_select_list_item),(yyvsp[-1].s_select_list_item),(yyvsp[0].str));
	}
#line 5725 "y.tab.c" /* yacc.c:1646  */
    break;

  case 295:
#line 2054 "sql.yacc" /* yacc.c:1646  */
    { 
			(yyval.s_select_list_item)=new_select_list_item_regex(E_SLI_REGEX_NOT_MATCHES,(yyvsp[-3].s_select_list_item),(yyvsp[-1].s_select_list_item),(yyvsp[0].str));
	}
#line 5733 "y.tab.c" /* yacc.c:1646  */
    break;

  case 296:
#line 2060 "sql.yacc" /* yacc.c:1646  */
    {
			if (A4GLSQLCV_check_requirement("NOT_EQUAL_AS_LESS_GREATER_THAN"))  {
				strcpy((yyval.str)," <> ");
			} else {
				strcpy((yyval.str)," != ");
			}
	}
#line 5745 "y.tab.c" /* yacc.c:1646  */
    break;

  case 297:
#line 2067 "sql.yacc" /* yacc.c:1646  */
    {
			strcpy((yyval.str)," < ");
	}
#line 5753 "y.tab.c" /* yacc.c:1646  */
    break;

  case 298:
#line 2070 "sql.yacc" /* yacc.c:1646  */
    {
			strcpy((yyval.str)," > ");
	}
#line 5761 "y.tab.c" /* yacc.c:1646  */
    break;

  case 299:
#line 2073 "sql.yacc" /* yacc.c:1646  */
    {
			strcpy((yyval.str)," ~ ");
	}
#line 5769 "y.tab.c" /* yacc.c:1646  */
    break;

  case 300:
#line 2076 "sql.yacc" /* yacc.c:1646  */
    {strcpy((yyval.str)," <= ");}
#line 5775 "y.tab.c" /* yacc.c:1646  */
    break;

  case 301:
#line 2077 "sql.yacc" /* yacc.c:1646  */
    {strcpy((yyval.str)," >= ");}
#line 5781 "y.tab.c" /* yacc.c:1646  */
    break;

  case 302:
#line 2082 "sql.yacc" /* yacc.c:1646  */
    {
		(yyval.s_select_list_item)=(yyvsp[0].s_select_list_item);
	}
#line 5789 "y.tab.c" /* yacc.c:1646  */
    break;

  case 303:
#line 2085 "sql.yacc" /* yacc.c:1646  */
    {
		(yyval.s_select_list_item)=(yyvsp[0].s_select_list_item);
	}
#line 5797 "y.tab.c" /* yacc.c:1646  */
    break;

  case 304:
#line 2088 "sql.yacc" /* yacc.c:1646  */
    {
		(yyval.s_select_list_item)=(yyvsp[0].s_select_list_item);
	}
#line 5805 "y.tab.c" /* yacc.c:1646  */
    break;

  case 305:
#line 2091 "sql.yacc" /* yacc.c:1646  */
    {
                 (yyval.s_select_list_item)=(yyvsp[0].s_select_list_item);
        }
#line 5813 "y.tab.c" /* yacc.c:1646  */
    break;

  case 306:
#line 2098 "sql.yacc" /* yacc.c:1646  */
    {strcpy((yyval.str),"");}
#line 5819 "y.tab.c" /* yacc.c:1646  */
    break;

  case 307:
#line 2099 "sql.yacc" /* yacc.c:1646  */
    {strcpy((yyval.str)," ALL "); add_feature("AGG_ALL");}
#line 5825 "y.tab.c" /* yacc.c:1646  */
    break;

  case 308:
#line 2100 "sql.yacc" /* yacc.c:1646  */
    {
		strcpy((yyval.str)," DISTINCT ");
		add_feature("AGG_DISTINCT");
	}
#line 5834 "y.tab.c" /* yacc.c:1646  */
    break;

  case 309:
#line 2104 "sql.yacc" /* yacc.c:1646  */
    {
		ansi_violation("Use DISTINCT not UNIQUE",0);
		strcpy((yyval.str)," DISTINCT ");
		add_feature("AGG_DISTINCT");
	}
#line 5844 "y.tab.c" /* yacc.c:1646  */
    break;

  case 310:
#line 2111 "sql.yacc" /* yacc.c:1646  */
    {strcpy((yyval.str),"");}
#line 5850 "y.tab.c" /* yacc.c:1646  */
    break;

  case 311:
#line 2112 "sql.yacc" /* yacc.c:1646  */
    {strcpy((yyval.str)," ALL "); add_feature("UNION_ALL");}
#line 5856 "y.tab.c" /* yacc.c:1646  */
    break;

  case 312:
#line 2113 "sql.yacc" /* yacc.c:1646  */
    {
		strcpy((yyval.str)," DISTINCT ");
		add_feature("UNION_DISTINCT");
	}
#line 5865 "y.tab.c" /* yacc.c:1646  */
    break;

  case 313:
#line 2117 "sql.yacc" /* yacc.c:1646  */
    {
		ansi_violation("Use DISTINCT not UNIQUE",0);
		add_feature("UNION_DISTINCT");
		strcpy((yyval.str)," DISTINCT ");
	}
#line 5875 "y.tab.c" /* yacc.c:1646  */
    break;

  case 314:
#line 2131 "sql.yacc" /* yacc.c:1646  */
    {
		strcpy((yyval.str),A4GLSQLCV_dtype_alias((yyvsp[0].str)));
	}
#line 5883 "y.tab.c" /* yacc.c:1646  */
    break;

  case 319:
#line 2146 "sql.yacc" /* yacc.c:1646  */
    {SPRINTF4((yyval.str)," %s %s%s%s",(yyvsp[-3].str),(yyvsp[-2].str),(yyvsp[-1].str),(yyvsp[0].str));}
#line 5889 "y.tab.c" /* yacc.c:1646  */
    break;

  case 320:
#line 2150 "sql.yacc" /* yacc.c:1646  */
    {strcpy((yyval.str),"SERIAL"); add_feature("DDL_SERIAL"); }
#line 5895 "y.tab.c" /* yacc.c:1646  */
    break;

  case 321:
#line 2151 "sql.yacc" /* yacc.c:1646  */
    {
			add_feature("DDL_SERIAL");
			if (A4GLSQLCV_check_requirement("NO_SERIAL_START_VALUE"))  {
				SPRINTF0((yyval.str),"SERIAL");
			} else {
				SPRINTF1((yyval.str),"SERIAL(%s)",(yyvsp[-1].str));
			}
	}
#line 5908 "y.tab.c" /* yacc.c:1646  */
    break;

  case 322:
#line 2160 "sql.yacc" /* yacc.c:1646  */
    {strcpy((yyval.str),"SERIAL8"); add_feature("DDL_SERIAL8"); }
#line 5914 "y.tab.c" /* yacc.c:1646  */
    break;

  case 323:
#line 2162 "sql.yacc" /* yacc.c:1646  */
    {
			add_feature("DDL_SERIAL8");
			if (A4GLSQLCV_check_requirement("NO_SERIAL_START_VALUE"))  {
				SPRINTF0((yyval.str),"SERIAL8");
			} else {
				SPRINTF1((yyval.str),"SERIAL8(%s)",(yyvsp[-1].str));
			}
	}
#line 5927 "y.tab.c" /* yacc.c:1646  */
    break;

  case 324:
#line 2171 "sql.yacc" /* yacc.c:1646  */
    {
 			add_feature("DDL_DECIMAL");
	}
#line 5935 "y.tab.c" /* yacc.c:1646  */
    break;

  case 325:
#line 2174 "sql.yacc" /* yacc.c:1646  */
    {
 			add_feature("DDL_DECIMAL");
		if (strlen((yyvsp[-1].str))) {
			SPRINTF2((yyval.str),"DECIMAL(%s%s)",(yyvsp[-2].str),(yyvsp[-1].str));
		} else {
			SPRINTF1((yyval.str),"DECIMAL(%s)",(yyvsp[-2].str));
		}
	}
#line 5948 "y.tab.c" /* yacc.c:1646  */
    break;

  case 326:
#line 2182 "sql.yacc" /* yacc.c:1646  */
    {
 			add_feature("DDL_MONEY");
		if (A4GLSQLCV_check_requirement("MONEY_AS_DECIMAL")) {
			SPRINTF2((yyval.str)," DECIMAL(%s%s)",(yyvsp[-2].str),(yyvsp[-1].str));
		} else {
			SPRINTF2((yyval.str)," MONEY(%s%s)",(yyvsp[-2].str),(yyvsp[-1].str));
		}
	}
#line 5961 "y.tab.c" /* yacc.c:1646  */
    break;

  case 327:
#line 2192 "sql.yacc" /* yacc.c:1646  */
    {
 			add_feature("DDL_MONEY");
		if (A4GLSQLCV_check_requirement ("MONEY_AS_DECIMAL")) {
			strcpy((yyval.str),"DECIMAL");
		} else {
			strcpy((yyval.str),"MONEY");
		}
	}
#line 5974 "y.tab.c" /* yacc.c:1646  */
    break;

  case 328:
#line 2200 "sql.yacc" /* yacc.c:1646  */
    {strcpy((yyval.str),"DATE");
 			add_feature("DDL_DATE"); }
#line 5981 "y.tab.c" /* yacc.c:1646  */
    break;

  case 329:
#line 2202 "sql.yacc" /* yacc.c:1646  */
    {strcpy((yyval.str),"INTEGER");}
#line 5987 "y.tab.c" /* yacc.c:1646  */
    break;

  case 330:
#line 2203 "sql.yacc" /* yacc.c:1646  */
    {strcpy((yyval.str),"SMALLINT");}
#line 5993 "y.tab.c" /* yacc.c:1646  */
    break;

  case 331:
#line 2204 "sql.yacc" /* yacc.c:1646  */
    {strcpy((yyval.str),"NCHAR"); add_feature("DDL_NCHAR");}
#line 5999 "y.tab.c" /* yacc.c:1646  */
    break;

  case 332:
#line 2205 "sql.yacc" /* yacc.c:1646  */
    {SPRINTF1((yyval.str),"NCHAR(%s)",(yyvsp[-1].str)); add_feature("DDL_NCHAR");}
#line 6005 "y.tab.c" /* yacc.c:1646  */
    break;

  case 333:
#line 2206 "sql.yacc" /* yacc.c:1646  */
    {add_feature("DDL_NVARCHAR");}
#line 6011 "y.tab.c" /* yacc.c:1646  */
    break;

  case 334:
#line 2207 "sql.yacc" /* yacc.c:1646  */
    {SPRINTF1((yyval.str),"NVARCHAR(%s)",(yyvsp[-1].str)); add_feature("DDL_NVARCHAR");}
#line 6017 "y.tab.c" /* yacc.c:1646  */
    break;

  case 335:
#line 2208 "sql.yacc" /* yacc.c:1646  */
    {
			add_feature("DDL_NVARCHAR");
			if (A4GLSQLCV_check_requirement("IGNORE_DTYPE_VARCHAR_MIN"))  {
				SPRINTF1((yyval.str),"NVARCHAR(%s)",(yyvsp[-3].str));
			} else {
				SPRINTF2((yyval.str),"NVARCHAR(%s,%s)",(yyvsp[-3].str),(yyvsp[-1].str));
			}
	}
#line 6030 "y.tab.c" /* yacc.c:1646  */
    break;

  case 336:
#line 2216 "sql.yacc" /* yacc.c:1646  */
    {SPRINTF2((yyval.str),"DATETIME %s TO %s",(yyvsp[-2].str),(yyvsp[0].str)); add_feature("DDL_DATETIME");}
#line 6036 "y.tab.c" /* yacc.c:1646  */
    break;

  case 337:
#line 2217 "sql.yacc" /* yacc.c:1646  */
    {add_feature("DDL_DATETIME");}
#line 6042 "y.tab.c" /* yacc.c:1646  */
    break;

  case 338:
#line 2218 "sql.yacc" /* yacc.c:1646  */
    {SPRINTF2((yyval.str),"INTERVAL %s TO %s",(yyvsp[-2].str),(yyvsp[0].str)); add_feature("DDL_INTERVAL");}
#line 6048 "y.tab.c" /* yacc.c:1646  */
    break;

  case 339:
#line 2219 "sql.yacc" /* yacc.c:1646  */
    {strcpy((yyval.str),(yyvsp[0].str));}
#line 6054 "y.tab.c" /* yacc.c:1646  */
    break;

  case 340:
#line 2220 "sql.yacc" /* yacc.c:1646  */
    {add_feature("DDL_INTERVAL");}
#line 6060 "y.tab.c" /* yacc.c:1646  */
    break;

  case 341:
#line 2221 "sql.yacc" /* yacc.c:1646  */
    {SPRINTF3((yyval.str),"INTERVAL %s(%s) TO %s",(yyvsp[-5].str),(yyvsp[-3].str),(yyvsp[0].str)); add_feature("DDL_INTERVAL");}
#line 6066 "y.tab.c" /* yacc.c:1646  */
    break;

  case 342:
#line 2222 "sql.yacc" /* yacc.c:1646  */
    {add_feature("DDL_TEXT");}
#line 6072 "y.tab.c" /* yacc.c:1646  */
    break;

  case 343:
#line 2223 "sql.yacc" /* yacc.c:1646  */
    {add_feature("DDL_BYTE");}
#line 6078 "y.tab.c" /* yacc.c:1646  */
    break;

  case 344:
#line 2224 "sql.yacc" /* yacc.c:1646  */
    {add_feature("DDL_VARCHAR");}
#line 6084 "y.tab.c" /* yacc.c:1646  */
    break;

  case 345:
#line 2225 "sql.yacc" /* yacc.c:1646  */
    {SPRINTF1((yyval.str),"VARCHAR(%s)",(yyvsp[-1].str));add_feature("DDL_VARCHAR");}
#line 6090 "y.tab.c" /* yacc.c:1646  */
    break;

  case 346:
#line 2226 "sql.yacc" /* yacc.c:1646  */
    {
			add_feature("DDL_VARCHAR");
			if (A4GLSQLCV_check_requirement("IGNORE_DTYPE_VARCHAR_MIN"))  {
				SPRINTF1((yyval.str),"VARCHAR(%s)",(yyvsp[-3].str));
			} else {
				SPRINTF2((yyval.str),"VARCHAR(%s,%s)",(yyvsp[-3].str),(yyvsp[-1].str));
			}
		}
#line 6103 "y.tab.c" /* yacc.c:1646  */
    break;

  case 347:
#line 2236 "sql.yacc" /* yacc.c:1646  */
    {strcpy((yyval.str),"");}
#line 6109 "y.tab.c" /* yacc.c:1646  */
    break;

  case 348:
#line 2237 "sql.yacc" /* yacc.c:1646  */
    {
		SPRINTF1((yyval.str),",%s",(yyvsp[0].str));
}
#line 6117 "y.tab.c" /* yacc.c:1646  */
    break;

  case 349:
#line 2244 "sql.yacc" /* yacc.c:1646  */
    {SPRINTF4((yyval.str)," %s %s %s %s",(yyvsp[-3].str),(yyvsp[-2].str),(yyvsp[-1].str),(yyvsp[0].str));}
#line 6123 "y.tab.c" /* yacc.c:1646  */
    break;

  case 353:
#line 2248 "sql.yacc" /* yacc.c:1646  */
    {add_feature("DDL_DOUBLE_PRECISION"); SPRINTF1((yyval.str)," %s",(yyvsp[0].str));}
#line 6129 "y.tab.c" /* yacc.c:1646  */
    break;

  case 359:
#line 2273 "sql.yacc" /* yacc.c:1646  */
    {(yyval.int_list.i0)=0;}
#line 6135 "y.tab.c" /* yacc.c:1646  */
    break;

  case 360:
#line 2274 "sql.yacc" /* yacc.c:1646  */
    {
		(yyval.int_list.i0)=1;
		(yyval.int_list.i1)=atoi((yyvsp[-1].str));
	}
#line 6144 "y.tab.c" /* yacc.c:1646  */
    break;

  case 361:
#line 2278 "sql.yacc" /* yacc.c:1646  */
    {
		(yyval.int_list.i0)=2;
		(yyval.int_list.i1)=atoi((yyvsp[-3].str));
		(yyval.int_list.i2)=atoi((yyvsp[-1].str));
	}
#line 6154 "y.tab.c" /* yacc.c:1646  */
    break;

  case 362:
#line 2286 "sql.yacc" /* yacc.c:1646  */
    {
		strcpy((yyval.str),(yyvsp[0].str));
	}
#line 6162 "y.tab.c" /* yacc.c:1646  */
    break;

  case 363:
#line 2289 "sql.yacc" /* yacc.c:1646  */
    {
		strcpy((yyval.str),(yyvsp[0].str));
	}
#line 6170 "y.tab.c" /* yacc.c:1646  */
    break;

  case 364:
#line 2296 "sql.yacc" /* yacc.c:1646  */
    {
		(yyval.s_select_list_item)= (yyvsp[0].s_select_list_item);
	}
#line 6178 "y.tab.c" /* yacc.c:1646  */
    break;

  case 365:
#line 2299 "sql.yacc" /* yacc.c:1646  */
    {
		(yyval.s_select_list_item)= (yyvsp[0].s_select_list_item);
	}
#line 6186 "y.tab.c" /* yacc.c:1646  */
    break;

  case 366:
#line 2309 "sql.yacc" /* yacc.c:1646  */
    { 
		(yyval.s_select_list_item)=new_select_list_item_col(0,(yyvsp[-1].str),&(yyvsp[0].int_list));
	}
#line 6194 "y.tab.c" /* yacc.c:1646  */
    break;

  case 367:
#line 2312 "sql.yacc" /* yacc.c:1646  */
    {
		(yyval.s_select_list_item)=new_select_list_item_col((yyvsp[-3].str),(yyvsp[-1].str),&(yyvsp[0].int_list));
	}
#line 6202 "y.tab.c" /* yacc.c:1646  */
    break;

  case 368:
#line 2315 "sql.yacc" /* yacc.c:1646  */
    {
		(yyval.s_select_list_item)=new_select_list_item_col((yyvsp[-2].str),"*",0);
	}
#line 6210 "y.tab.c" /* yacc.c:1646  */
    break;

  case 369:
#line 2318 "sql.yacc" /* yacc.c:1646  */
    {
		(yyval.s_select_list_item)=new_select_list_item_col(0,"rowid",0);
	}
#line 6218 "y.tab.c" /* yacc.c:1646  */
    break;

  case 370:
#line 2325 "sql.yacc" /* yacc.c:1646  */
    { 
		struct ilist *i;
		i=&(yyvsp[0].int_list);
		if (strcmp((yyvsp[-1].str),"rowid")==0) { strcpy((yyvsp[-1].str), A4GLSQLCV_get_sqlconst ("rowid")); add_feature("ROWID"); }
		ADDMAP("Use Column",(yyvsp[-1].str));
		strcpy((yyval.str),A4GLSQLCV_make_substr(A4GLSQLCV_check_colname(0,(yyvsp[-1].str)), i->i0,i->i1,i->i2));
	}
#line 6230 "y.tab.c" /* yacc.c:1646  */
    break;

  case 371:
#line 2332 "sql.yacc" /* yacc.c:1646  */
    {
		struct ilist *i;
		if (strcmp((yyvsp[-1].str),"rowid")==0) { strcpy((yyvsp[-1].str), A4GLSQLCV_get_sqlconst ("rowid"));  add_feature("ROWID");}
		SPRINTF1((yyval.str),"%s",A4GLSQLCV_check_colname((yyvsp[-3].str),(yyvsp[-1].str)));
		ADDMAP("Use Column",(yyval.str));
		i=&(yyvsp[0].int_list);
		strcpy((yyval.str),A4GLSQLCV_make_substr((yyval.str),i->i0,i->i1,i->i2));
	}
#line 6243 "y.tab.c" /* yacc.c:1646  */
    break;

  case 372:
#line 2340 "sql.yacc" /* yacc.c:1646  */
    {
		struct ilist *i;
		if (strcmp((yyvsp[-3].str),"rowid")==0) { strcpy((yyvsp[-3].str), A4GLSQLCV_get_sqlconst ("rowid")); add_feature("ROWID"); }
		// First identifier is the owner...
		SPRINTF1((yyval.str),"%s",A4GLSQLCV_check_colname(A4GLSQLCV_ownerize_tablename((yyvsp[-5].str),(yyvsp[-3].str)),(yyvsp[-1].str)));
		ADDMAP("Use Column",(yyval.str));
		i=&(yyvsp[-2].int_list);
		strcpy((yyval.str),A4GLSQLCV_make_substr((yyval.str),i->i0,i->i1,i->i2));
	}
#line 6257 "y.tab.c" /* yacc.c:1646  */
    break;

  case 373:
#line 2349 "sql.yacc" /* yacc.c:1646  */
    {
		SPRINTF1((yyval.str),"%s",A4GLSQLCV_check_colname((yyvsp[-2].str),"*"));
		ADDMAP("Use Column",(yyval.str));
	}
#line 6266 "y.tab.c" /* yacc.c:1646  */
    break;

  case 375:
#line 2360 "sql.yacc" /* yacc.c:1646  */
    { strcpy((yyval.str),(yyvsp[0].str)); 
#ifdef DEBUG
A4GL_debug("Set $<str>$ to %s\n",(yyval.str)); 
#endif
}
#line 6276 "y.tab.c" /* yacc.c:1646  */
    break;

  case 379:
#line 2372 "sql.yacc" /* yacc.c:1646  */
    { strcpy((yyval.str),A4GLSQLCV_generate_current(0,0)); }
#line 6282 "y.tab.c" /* yacc.c:1646  */
    break;

  case 380:
#line 2373 "sql.yacc" /* yacc.c:1646  */
    {
		strcpy((yyval.str),A4GLSQLCV_generate_current((yyvsp[-2].str),(yyvsp[0].str)));
	}
#line 6290 "y.tab.c" /* yacc.c:1646  */
    break;

  case 395:
#line 2383 "sql.yacc" /* yacc.c:1646  */
    {SPRINTF1((yyval.str),"FRACTION(%s)",(yyvsp[-1].str));}
#line 6296 "y.tab.c" /* yacc.c:1646  */
    break;

  case 396:
#line 2428 "sql.yacc" /* yacc.c:1646  */
    { (yyval.sql_string)=make_sql_string_and_free(acl_strdup((yyvsp[0].str)), NULL);}
#line 6302 "y.tab.c" /* yacc.c:1646  */
    break;

  case 397:
#line 2429 "sql.yacc" /* yacc.c:1646  */
    { (yyval.sql_string)=make_sql_string_and_free(acl_strdup((yyvsp[0].str)), NULL);}
#line 6308 "y.tab.c" /* yacc.c:1646  */
    break;

  case 398:
#line 2430 "sql.yacc" /* yacc.c:1646  */
    { (yyval.sql_string)=make_sql_string_and_free(acl_strdup((yyvsp[0].str)), NULL);}
#line 6314 "y.tab.c" /* yacc.c:1646  */
    break;

  case 399:
#line 2435 "sql.yacc" /* yacc.c:1646  */
    { add_feature("RENAME_TABLE"); strcpy((yyval.str),A4GLSQLCV_rentab((yyvsp[-2].str),(yyvsp[0].str))); }
#line 6320 "y.tab.c" /* yacc.c:1646  */
    break;

  case 400:
#line 2436 "sql.yacc" /* yacc.c:1646  */
    { add_feature("RENAME_COLUMN"); strcpy((yyval.str),A4GLSQLCV_rencol((yyvsp[-4].str),(yyvsp[-2].str),(yyvsp[0].str)) ); }
#line 6326 "y.tab.c" /* yacc.c:1646  */
    break;

  case 403:
#line 2444 "sql.yacc" /* yacc.c:1646  */
    {
		add_feature("UNLOCK_TABLE");
		SPRINTF2((yyval.str),"%s %s",(yyvsp[-1].str),(yyvsp[0].str));
	}
#line 6335 "y.tab.c" /* yacc.c:1646  */
    break;

  case 404:
#line 2451 "sql.yacc" /* yacc.c:1646  */
    {
		add_feature("LOCK_TABLE");
		SPRINTF3((yyval.str),"%s %s %s",
					(yyvsp[-2].str),
					(yyvsp[-1].str),
					(yyvsp[0].str)
					);
		}
#line 6348 "y.tab.c" /* yacc.c:1646  */
    break;

  case 405:
#line 2462 "sql.yacc" /* yacc.c:1646  */
    { add_feature("LOCK_TABLE_SHARED");}
#line 6354 "y.tab.c" /* yacc.c:1646  */
    break;

  case 406:
#line 2463 "sql.yacc" /* yacc.c:1646  */
    {add_feature("LOCK_TABLE_EXCLUSIVE");}
#line 6360 "y.tab.c" /* yacc.c:1646  */
    break;

  case 407:
#line 2476 "sql.yacc" /* yacc.c:1646  */
    {strcpy((yyval.str),A4GLSQLCV_datetime_value((yyvsp[0].str)));}
#line 6366 "y.tab.c" /* yacc.c:1646  */
    break;

  case 408:
#line 2477 "sql.yacc" /* yacc.c:1646  */
    {strcpy((yyval.str),A4GLSQLCV_make_dtime_extend((yyvsp[-3].str),(yyvsp[-2].str),(yyvsp[0].str),0));}
#line 6372 "y.tab.c" /* yacc.c:1646  */
    break;

  case 409:
#line 2481 "sql.yacc" /* yacc.c:1646  */
    {strcpy((yyval.str),(yyvsp[0].str));}
#line 6378 "y.tab.c" /* yacc.c:1646  */
    break;

  case 410:
#line 2485 "sql.yacc" /* yacc.c:1646  */
    {strcpy((yyval.str),A4GLSQLCV_interval_value((yyvsp[0].str)));}
#line 6384 "y.tab.c" /* yacc.c:1646  */
    break;

  case 411:
#line 2486 "sql.yacc" /* yacc.c:1646  */
    {
			strcpy((yyval.str),A4GLSQLCV_make_ival_extend((yyvsp[-6].str),(yyvsp[-5].str),(yyvsp[-3].str),(yyvsp[0].str),0));
		}
#line 6392 "y.tab.c" /* yacc.c:1646  */
    break;

  case 412:
#line 2489 "sql.yacc" /* yacc.c:1646  */
    {
		strcpy((yyval.str),A4GLSQLCV_make_ival_extend((yyvsp[-3].str),(yyvsp[-2].str),(char *)0, (yyvsp[0].str),0));
	}
#line 6400 "y.tab.c" /* yacc.c:1646  */
    break;

  case 413:
#line 2495 "sql.yacc" /* yacc.c:1646  */
    {SPRINTF1((yyval.str),"%s",(yyvsp[0].str));}
#line 6406 "y.tab.c" /* yacc.c:1646  */
    break;

  case 414:
#line 2499 "sql.yacc" /* yacc.c:1646  */
    {
	strcpy((yyval.str),(yyvsp[0].str));
}
#line 6414 "y.tab.c" /* yacc.c:1646  */
    break;

  case 415:
#line 2522 "sql.yacc" /* yacc.c:1646  */
    {
		(yyval.s_select_list_item_list)=(yyvsp[0].s_select_list_item_list);
		add_feature("ORDER_BY");
	}
#line 6423 "y.tab.c" /* yacc.c:1646  */
    break;

  case 416:
#line 2532 "sql.yacc" /* yacc.c:1646  */
    {
			(yyval.s_select_list_item_list)=local_new_select_list_item_list((yyvsp[0].s_select_list_item));
	}
#line 6431 "y.tab.c" /* yacc.c:1646  */
    break;

  case 417:
#line 2535 "sql.yacc" /* yacc.c:1646  */
    {
			(yyval.s_select_list_item_list)=local_add_select_list_item_list((yyvsp[-2].s_select_list_item_list),(yyvsp[0].s_select_list_item));
	}
#line 6439 "y.tab.c" /* yacc.c:1646  */
    break;

  case 418:
#line 2541 "sql.yacc" /* yacc.c:1646  */
    {
		if (strcmp((yyvsp[0].str),"DESC")!=0) {
			(yyval.s_select_list_item)=new_select_list_item_simple_expr(E_SLI_ASC,(yyvsp[-1].s_select_list_item));
		} else {
			(yyval.s_select_list_item)=new_select_list_item_simple_expr(E_SLI_DESC,(yyvsp[-1].s_select_list_item));
		}
	}
#line 6451 "y.tab.c" /* yacc.c:1646  */
    break;

  case 419:
#line 2550 "sql.yacc" /* yacc.c:1646  */
    { 
		add_feature("ORDER_BY_NUMBER");
		(yyval.s_select_list_item)=new_select_list_item_literal((yyvsp[0].str));
	}
#line 6460 "y.tab.c" /* yacc.c:1646  */
    break;

  case 420:
#line 2554 "sql.yacc" /* yacc.c:1646  */
    {
		(yyval.s_select_list_item)=(yyvsp[0].s_select_list_item);
		(yyval.s_select_list_item)->data.type=E_SLI_COLUMN_ORDERBY;
	}
#line 6469 "y.tab.c" /* yacc.c:1646  */
    break;

  case 421:
#line 2561 "sql.yacc" /* yacc.c:1646  */
    {strcpy((yyval.str),"");}
#line 6475 "y.tab.c" /* yacc.c:1646  */
    break;

  case 422:
#line 2563 "sql.yacc" /* yacc.c:1646  */
    {add_feature("ORDER_BY_ASC"); strcpy((yyval.str),"ASC");}
#line 6481 "y.tab.c" /* yacc.c:1646  */
    break;

  case 423:
#line 2565 "sql.yacc" /* yacc.c:1646  */
    {add_feature("ORDER_BY_DESC"); strcpy((yyval.str),"DESC");}
#line 6487 "y.tab.c" /* yacc.c:1646  */
    break;

  case 424:
#line 2569 "sql.yacc" /* yacc.c:1646  */
    {
		(yyval.s_select_list_item_list)=(yyvsp[0].s_select_list_item_list);
	}
#line 6495 "y.tab.c" /* yacc.c:1646  */
    break;

  case 425:
#line 2575 "sql.yacc" /* yacc.c:1646  */
    {
			(yyval.s_select_list_item_list)=local_new_select_list_item_list((yyvsp[0].s_select_list_item));
	}
#line 6503 "y.tab.c" /* yacc.c:1646  */
    break;

  case 426:
#line 2578 "sql.yacc" /* yacc.c:1646  */
    {
			(yyval.s_select_list_item_list)=local_add_select_list_item_list((yyvsp[-2].s_select_list_item_list),(yyvsp[0].s_select_list_item));
	}
#line 6511 "y.tab.c" /* yacc.c:1646  */
    break;

  case 427:
#line 2584 "sql.yacc" /* yacc.c:1646  */
    { (yyval.s_select_list_item)=(yyvsp[0].s_select_list_item); }
#line 6517 "y.tab.c" /* yacc.c:1646  */
    break;

  case 428:
#line 2585 "sql.yacc" /* yacc.c:1646  */
    { (yyval.s_select_list_item)=new_select_list_item_literal((yyvsp[0].str)); }
#line 6523 "y.tab.c" /* yacc.c:1646  */
    break;

  case 429:
#line 2592 "sql.yacc" /* yacc.c:1646  */
    {
	(yyval.sql_string)=get_select_list_item(0,(yyvsp[0].s_select_list_item));
}
#line 6531 "y.tab.c" /* yacc.c:1646  */
    break;

  case 430:
#line 2605 "sql.yacc" /* yacc.c:1646  */
    {
		A4GL_set_sql_lineno(yylineno);
		(yyval.sql_string)=make_select_stmt_v2(current_upd_table, (yyvsp[0].s_select),"");
		map_select_stmt("SELECT",(yyvsp[0].s_select));
		A4GL_free_select_stmt((yyvsp[0].s_select));
}
#line 6542 "y.tab.c" /* yacc.c:1646  */
    break;

  case 431:
#line 2615 "sql.yacc" /* yacc.c:1646  */
    { 
	if (A4GLSQLCV_check_requirement("ALLOW_TIME_DATATYPE")) {
       		strcpy((yyval.str),"TIME"); break;
	} else {
       		strcpy((yyval.str),"DATETIME HOUR TO FRACTION(2)"); break;
	}
 }
#line 6554 "y.tab.c" /* yacc.c:1646  */
    break;

  case 432:
#line 2622 "sql.yacc" /* yacc.c:1646  */
    {
	int n;
       	n=atoi((yyvsp[-1].str));
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
#line 6576 "y.tab.c" /* yacc.c:1646  */
    break;

  case 433:
#line 2639 "sql.yacc" /* yacc.c:1646  */
    {
	if (A4GLSQLCV_check_requirement("ALLOW_TIMESTAMP_DATATYPE")) {
		strcpy((yyval.str),"TIMESTAMP");
	} else {
                strcpy((yyval.str),"DATETIME YEAR TO FRACTION(2)"); 
	}
 }
#line 6588 "y.tab.c" /* yacc.c:1646  */
    break;

  case 434:
#line 2646 "sql.yacc" /* yacc.c:1646  */
    {
        int n;
       	n=atoi((yyvsp[-1].str));
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
#line 6610 "y.tab.c" /* yacc.c:1646  */
    break;

  case 435:
#line 2671 "sql.yacc" /* yacc.c:1646  */
    { 
		//start_bind('i',0);
		 set_ignore_indicators();}
#line 6618 "y.tab.c" /* yacc.c:1646  */
    break;

  case 436:
#line 2673 "sql.yacc" /* yacc.c:1646  */
    { clr_ignore_indicators();}
#line 6624 "y.tab.c" /* yacc.c:1646  */
    break;

  case 437:
#line 2675 "sql.yacc" /* yacc.c:1646  */
    {


		(yyval.s_select)=(yyvsp[-2].s_select);
		if ((yyvsp[-8].integer_val)!=-1) {
			(yyval.s_select)->limit.start=1;
			(yyval.s_select)->limit.end=(yyvsp[-8].integer_val);
		}
		(yyval.s_select)->modifier=acl_strdup((yyvsp[-7].str));
		A4GL_set_associated_mem((yyval.s_select), (yyval.s_select)->modifier);
		(yyval.s_select)->into=(yyvsp[-3].ptr_list);
		(yyval.s_select)->select_list=(yyvsp[-5].s_select_list_item_list);
		(yyval.s_select)->next=(yyvsp[-1].s_select);
		(yyval.s_select)->sf=(yyvsp[0].s_select_finish);
		A4GL_set_associated_mem((yyval.s_select), (yyval.s_select)->sf);
}
#line 6645 "y.tab.c" /* yacc.c:1646  */
    break;

  case 438:
#line 2696 "sql.yacc" /* yacc.c:1646  */
    {
	        (yyval.s_select)=(yyvsp[-1].s_select);
                (yyval.s_select)->modifier=acl_strdup((yyvsp[-3].str));
		A4GL_set_associated_mem((yyval.s_select), (yyval.s_select)->modifier);
		if ((yyvsp[-4].integer_val)!=-1) {
			(yyval.s_select)->limit.start=1;
			(yyval.s_select)->limit.end=(yyvsp[-4].integer_val);
		}
                (yyval.s_select)->into=0;
                (yyval.s_select)->select_list=(yyvsp[-2].s_select_list_item_list);
		(yyval.s_select)->next=(yyvsp[0].s_select);
	}
#line 6662 "y.tab.c" /* yacc.c:1646  */
    break;

  case 439:
#line 2739 "sql.yacc" /* yacc.c:1646  */
    { (yyval.s_select)=0;}
#line 6668 "y.tab.c" /* yacc.c:1646  */
    break;

  case 440:
#line 2740 "sql.yacc" /* yacc.c:1646  */
    { 
		(yyval.s_select)=(yyvsp[0].s_select);
		(yyval.s_select)->union_op=acl_strdup((yyvsp[-1].str));
		A4GL_set_associated_mem((yyval.s_select), (yyval.s_select)->union_op);
		add_feature("SELECT_UNION"); 
	}
#line 6679 "y.tab.c" /* yacc.c:1646  */
    break;

  case 441:
#line 2754 "sql.yacc" /* yacc.c:1646  */
    {
		(yyval.s_select_finish)=0;
	}
#line 6687 "y.tab.c" /* yacc.c:1646  */
    break;

  case 442:
#line 2757 "sql.yacc" /* yacc.c:1646  */
    {  
		(yyval.s_select_finish)=acl_malloc2(sizeof(struct s_select_finish));
		(yyval.s_select_finish)->order_by=(yyvsp[0].s_select_list_item_list);
		(yyval.s_select_finish)->insert_into=0;
		(yyval.s_select_finish)->into_temp=0;
		(yyval.s_select_finish)->nolog=0;
	}
#line 6699 "y.tab.c" /* yacc.c:1646  */
    break;

  case 443:
#line 2764 "sql.yacc" /* yacc.c:1646  */
    { 
		(yyval.s_select_finish)=acl_malloc2(sizeof(struct s_select_finish));
		add_feature("SELECT_INTO_TEMP_ORDER_BY");
		(yyval.s_select_finish)->order_by=(yyvsp[-3].s_select_list_item_list);
		(yyval.s_select_finish)->insert_into=0;
		(yyval.s_select_finish)->into_temp=strdup((yyvsp[-1].str));
		A4GL_set_associated_mem((yyval.s_select_finish), (yyval.s_select_finish)->into_temp);
		(yyval.s_select_finish)->nolog=(yyvsp[0].integer_val);

	}
#line 6714 "y.tab.c" /* yacc.c:1646  */
    break;

  case 444:
#line 2774 "sql.yacc" /* yacc.c:1646  */
    { 
		(yyval.s_select_finish)=acl_malloc2(sizeof(struct s_select_finish));
		add_feature("SELECT_INTO_TEMP");
		(yyval.s_select_finish)->order_by=0;
		(yyval.s_select_finish)->into_temp=strdup((yyvsp[-1].str));
		A4GL_set_associated_mem((yyval.s_select_finish), (yyval.s_select_finish)->into_temp);
		(yyval.s_select_finish)->insert_into=0;
		(yyval.s_select_finish)->nolog=(yyvsp[0].integer_val);
}
#line 6728 "y.tab.c" /* yacc.c:1646  */
    break;

  case 446:
#line 2792 "sql.yacc" /* yacc.c:1646  */
    {
		(yyval.s_select)=(yyvsp[0].s_select);
		if ((yyvsp[-3].integer_val)!=-1) {
			(yyval.s_select)->limit.start=1;
			(yyval.s_select)->limit.end=(yyvsp[-3].integer_val);
		}
		(yyval.s_select)->modifier=acl_strdup((yyvsp[-2].str));
		A4GL_set_associated_mem((yyval.s_select), (yyval.s_select)->modifier);
		(yyval.s_select)->select_list=(yyvsp[-1].s_select_list_item_list);
	}
#line 6743 "y.tab.c" /* yacc.c:1646  */
    break;

  case 447:
#line 2805 "sql.yacc" /* yacc.c:1646  */
    {
		(yyval.s_select)=(yyvsp[-1].s_select);
		if ((yyvsp[-4].integer_val)!=-1) {
			(yyval.s_select)->limit.start=1;
			(yyval.s_select)->limit.end=(yyvsp[-4].integer_val);
		}
		(yyval.s_select)->modifier=acl_strdup((yyvsp[-3].str));
		A4GL_set_associated_mem((yyval.s_select), (yyval.s_select)->modifier);
		(yyval.s_select)->select_list=(yyvsp[-2].s_select_list_item_list);
		(yyval.s_select_list_item)=new_select_list_subquery((yyval.s_select));
	}
#line 6759 "y.tab.c" /* yacc.c:1646  */
    break;

  case 448:
#line 2820 "sql.yacc" /* yacc.c:1646  */
    {(yyval.integer_val)=-1;}
#line 6765 "y.tab.c" /* yacc.c:1646  */
    break;

  case 449:
#line 2822 "sql.yacc" /* yacc.c:1646  */
    {
		(yyval.integer_val)=atol((yyvsp[0].str));
	}
#line 6773 "y.tab.c" /* yacc.c:1646  */
    break;

  case 450:
#line 2828 "sql.yacc" /* yacc.c:1646  */
    {strcpy((yyval.str),"");}
#line 6779 "y.tab.c" /* yacc.c:1646  */
    break;

  case 451:
#line 2829 "sql.yacc" /* yacc.c:1646  */
    {strcpy((yyval.str),"ALL"); add_feature("SELECT_ALL");}
#line 6785 "y.tab.c" /* yacc.c:1646  */
    break;

  case 452:
#line 2830 "sql.yacc" /* yacc.c:1646  */
    {strcpy((yyval.str),"DISTINCT"); add_feature("SELECT_DISTINCT");}
#line 6791 "y.tab.c" /* yacc.c:1646  */
    break;

  case 453:
#line 2831 "sql.yacc" /* yacc.c:1646  */
    {strcpy((yyval.str),"DISTINCT");
		add_feature("SELECT_UNIQUE");
		ansi_violation("Use DISTINCT not UNIQUE",0);
		strcpy((yyval.str),"DISTINCT");
	}
#line 6801 "y.tab.c" /* yacc.c:1646  */
    break;

  case 454:
#line 2841 "sql.yacc" /* yacc.c:1646  */
    {
			(yyval.s_select_list_item_list)=rationalize_select_list_item_list((yyvsp[0].s_select_list_item_list));
		}
#line 6809 "y.tab.c" /* yacc.c:1646  */
    break;

  case 455:
#line 2848 "sql.yacc" /* yacc.c:1646  */
    { 
		 (yyval.s_select_list_item_list)=local_new_select_list_item_list((yyvsp[0].s_select_list_item));
	}
#line 6817 "y.tab.c" /* yacc.c:1646  */
    break;

  case 456:
#line 2851 "sql.yacc" /* yacc.c:1646  */
    { 
		(yyval.s_select_list_item_list)=local_add_select_list_item_list((yyvsp[-2].s_select_list_item_list),(yyvsp[0].s_select_list_item));
	}
#line 6825 "y.tab.c" /* yacc.c:1646  */
    break;

  case 457:
#line 2857 "sql.yacc" /* yacc.c:1646  */
    {
		(yyval.s_select_list_item)=(yyvsp[0].s_select_list_item);
	}
#line 6833 "y.tab.c" /* yacc.c:1646  */
    break;

  case 458:
#line 2860 "sql.yacc" /* yacc.c:1646  */
    {
		(yyval.s_select_list_item)=(yyvsp[-1].s_select_list_item);
		(yyval.s_select_list_item)->alias=acl_strdup((yyvsp[0].str));
		A4GL_set_associated_mem((yyval.s_select_list_item), (yyval.s_select_list_item)->alias);
	}
#line 6843 "y.tab.c" /* yacc.c:1646  */
    break;

  case 459:
#line 2865 "sql.yacc" /* yacc.c:1646  */
    {
		(yyval.s_select_list_item)=(yyvsp[-2].s_select_list_item);
		(yyval.s_select_list_item)->alias=acl_strdup((yyvsp[0].str));
		A4GL_set_associated_mem((yyval.s_select_list_item), (yyval.s_select_list_item)->alias);
	}
#line 6853 "y.tab.c" /* yacc.c:1646  */
    break;

  case 460:
#line 2874 "sql.yacc" /* yacc.c:1646  */
    {
		(yyval.s_select_list_item)=(yyvsp[0].s_select_list_item); /* A4GLSQLCV_check_expr($<sql_string>1) */
	}
#line 6861 "y.tab.c" /* yacc.c:1646  */
    break;

  case 461:
#line 2877 "sql.yacc" /* yacc.c:1646  */
    {
		(yyval.s_select_list_item)=(yyvsp[0].s_select_list_item);
		(yyval.s_select_list_item)->sign='-';
	}
#line 6870 "y.tab.c" /* yacc.c:1646  */
    break;

  case 462:
#line 2881 "sql.yacc" /* yacc.c:1646  */
    {
		(yyval.s_select_list_item)=(yyvsp[0].s_select_list_item);
	}
#line 6878 "y.tab.c" /* yacc.c:1646  */
    break;

  case 463:
#line 2888 "sql.yacc" /* yacc.c:1646  */
    {
			(yyval.s_select_list_item)=new_select_list_item_op_expr ((yyvsp[-2].s_select_list_item), (yyvsp[0].s_select_list_item), "/");
	}
#line 6886 "y.tab.c" /* yacc.c:1646  */
    break;

  case 464:
#line 2891 "sql.yacc" /* yacc.c:1646  */
    {
			(yyval.s_select_list_item)=new_select_list_item_simple_expr((enum e_sli)(yyvsp[0].integer_val), (yyvsp[-1].s_select_list_item));
	}
#line 6894 "y.tab.c" /* yacc.c:1646  */
    break;

  case 465:
#line 2894 "sql.yacc" /* yacc.c:1646  */
    {
			(yyval.s_select_list_item)=new_select_list_item_op_expr ((yyvsp[-2].s_select_list_item), (yyvsp[0].s_select_list_item), "*");
	}
#line 6902 "y.tab.c" /* yacc.c:1646  */
    break;

  case 466:
#line 2897 "sql.yacc" /* yacc.c:1646  */
    {
			(yyval.s_select_list_item)=new_select_list_item_op_expr ((yyvsp[-2].s_select_list_item), (yyvsp[0].s_select_list_item), "+");
	}
#line 6910 "y.tab.c" /* yacc.c:1646  */
    break;

  case 467:
#line 2900 "sql.yacc" /* yacc.c:1646  */
    {
			(yyval.s_select_list_item)=new_select_list_item_op_expr ((yyvsp[-2].s_select_list_item), (yyvsp[0].s_select_list_item), "-");
	}
#line 6918 "y.tab.c" /* yacc.c:1646  */
    break;

  case 468:
#line 2903 "sql.yacc" /* yacc.c:1646  */
    {
			(yyval.s_select_list_item)=new_select_list_item_op_expr ((yyvsp[-2].s_select_list_item), (yyvsp[0].s_select_list_item), "||");
	}
#line 6926 "y.tab.c" /* yacc.c:1646  */
    break;

  case 469:
#line 2906 "sql.yacc" /* yacc.c:1646  */
    { (yyval.s_select_list_item)=new_select_list_item_literal((yyvsp[0].str)); }
#line 6932 "y.tab.c" /* yacc.c:1646  */
    break;

  case 470:
#line 2907 "sql.yacc" /* yacc.c:1646  */
    { (yyval.s_select_list_item)=new_select_list_item_builtin_const(E_SLI_BUILTIN_CONST_TRUE); }
#line 6938 "y.tab.c" /* yacc.c:1646  */
    break;

  case 471:
#line 2908 "sql.yacc" /* yacc.c:1646  */
    { (yyval.s_select_list_item)=new_select_list_item_builtin_const(E_SLI_BUILTIN_CONST_FALSE); }
#line 6944 "y.tab.c" /* yacc.c:1646  */
    break;

  case 472:
#line 2909 "sql.yacc" /* yacc.c:1646  */
    { (yyval.s_select_list_item)=new_select_list_item_builtin_const(E_SLI_BUILTIN_CONST_USER); }
#line 6950 "y.tab.c" /* yacc.c:1646  */
    break;

  case 473:
#line 2910 "sql.yacc" /* yacc.c:1646  */
    { (yyval.s_select_list_item)=new_select_list_item_builtin_const(E_SLI_BUILTIN_CONST_TODAY); }
#line 6956 "y.tab.c" /* yacc.c:1646  */
    break;

  case 474:
#line 2911 "sql.yacc" /* yacc.c:1646  */
    { (yyval.s_select_list_item)=new_select_list_item_builtin_const(E_SLI_BUILTIN_CONST_ROWID); }
#line 6962 "y.tab.c" /* yacc.c:1646  */
    break;

  case 475:
#line 2912 "sql.yacc" /* yacc.c:1646  */
    { (yyval.s_select_list_item)=new_select_list_item_builtin_const(E_SLI_BUILTIN_CONST_TIME); }
#line 6968 "y.tab.c" /* yacc.c:1646  */
    break;

  case 476:
#line 2913 "sql.yacc" /* yacc.c:1646  */
    { (yyval.s_select_list_item)=new_select_list_item_builtin_const(E_SLI_BUILTIN_CONST_STAR); }
#line 6974 "y.tab.c" /* yacc.c:1646  */
    break;

  case 477:
#line 2914 "sql.yacc" /* yacc.c:1646  */
    { (yyval.s_select_list_item)=new_select_list_item_builtin_const(E_SLI_BUILTIN_CONST_COUNT_STAR); }
#line 6980 "y.tab.c" /* yacc.c:1646  */
    break;

  case 478:
#line 2916 "sql.yacc" /* yacc.c:1646  */
    {
		(yyval.s_select_list_item)=new_select_list_item_agg1(E_SLI_BUILTIN_AGG_AVG,(yyvsp[-2].str),(yyvsp[-1].s_select_list_item));
		add_feature("SELECT_AVG");
	}
#line 6989 "y.tab.c" /* yacc.c:1646  */
    break;

  case 479:
#line 2920 "sql.yacc" /* yacc.c:1646  */
    {
		(yyval.s_select_list_item)=new_select_list_item_agg1(E_SLI_BUILTIN_AGG_MAX,(yyvsp[-2].str),(yyvsp[-1].s_select_list_item));
		add_feature("SELECT_MAX");
	}
#line 6998 "y.tab.c" /* yacc.c:1646  */
    break;

  case 480:
#line 2924 "sql.yacc" /* yacc.c:1646  */
    {
		(yyval.s_select_list_item)=new_select_list_item_agg1(E_SLI_BUILTIN_AGG_MIN,(yyvsp[-2].str),(yyvsp[-1].s_select_list_item));
		add_feature("SELECT_MIN");
	}
#line 7007 "y.tab.c" /* yacc.c:1646  */
    break;

  case 481:
#line 2928 "sql.yacc" /* yacc.c:1646  */
    {
		(yyval.s_select_list_item)=new_select_list_item_agg1(E_SLI_BUILTIN_AGG_SUM,(yyvsp[-2].str),(yyvsp[-1].s_select_list_item));
		add_feature("SELECT_SUM");
	}
#line 7016 "y.tab.c" /* yacc.c:1646  */
    break;

  case 482:
#line 2932 "sql.yacc" /* yacc.c:1646  */
    {
		(yyval.s_select_list_item)=new_select_list_item_agg1(E_SLI_BUILTIN_AGG_COUNT,(yyvsp[-2].str),(yyvsp[-1].s_select_list_item));
		add_feature("SELECT_COUNT");
	}
#line 7025 "y.tab.c" /* yacc.c:1646  */
    break;

  case 483:
#line 2936 "sql.yacc" /* yacc.c:1646  */
    {
		add_sql_function((yyvsp[-2].str));
		(yyval.s_select_list_item)=new_select_list_item_fcall((yyvsp[-2].str),0);
	}
#line 7034 "y.tab.c" /* yacc.c:1646  */
    break;

  case 484:
#line 2940 "sql.yacc" /* yacc.c:1646  */
    {
		add_sql_function((yyvsp[-3].str));
		(yyval.s_select_list_item)=new_select_list_item_fcall((yyvsp[-3].str),(yyvsp[-1].s_select_list_item_list));
	}
#line 7043 "y.tab.c" /* yacc.c:1646  */
    break;

  case 485:
#line 2944 "sql.yacc" /* yacc.c:1646  */
    {
		(yyval.s_select_list_item)=new_select_list_item_builtin_fcall(E_SLI_BUILTIN_FUNC_YEAR,(yyvsp[-1].s_select_list_item_list));
	}
#line 7051 "y.tab.c" /* yacc.c:1646  */
    break;

  case 486:
#line 2947 "sql.yacc" /* yacc.c:1646  */
    {
		(yyval.s_select_list_item)=new_select_list_item_builtin_fcall(E_SLI_BUILTIN_FUNC_MONTH,(yyvsp[-1].s_select_list_item_list));
	}
#line 7059 "y.tab.c" /* yacc.c:1646  */
    break;

  case 487:
#line 2950 "sql.yacc" /* yacc.c:1646  */
    {
		(yyval.s_select_list_item)=new_select_list_item_builtin_fcall(E_SLI_BUILTIN_FUNC_DAY,(yyvsp[-1].s_select_list_item_list));
	}
#line 7067 "y.tab.c" /* yacc.c:1646  */
    break;

  case 488:
#line 2953 "sql.yacc" /* yacc.c:1646  */
    {
		(yyval.s_select_list_item)=new_select_list_item_builtin_fcall(E_SLI_BUILTIN_FUNC_MDY,(yyvsp[-1].s_select_list_item_list));
	}
#line 7075 "y.tab.c" /* yacc.c:1646  */
    break;

  case 489:
#line 2956 "sql.yacc" /* yacc.c:1646  */
    {
		(yyval.s_select_list_item)=new_select_list_item_builtin_fcall(E_SLI_BUILTIN_FUNC_WEEKDAY,(yyvsp[-1].s_select_list_item_list));
	}
#line 7083 "y.tab.c" /* yacc.c:1646  */
    break;

  case 490:
#line 2959 "sql.yacc" /* yacc.c:1646  */
    {
		(yyval.s_select_list_item)=new_select_list_item_builtin_fcall(E_SLI_BUILTIN_FUNC_DOW,(yyvsp[-1].s_select_list_item_list));
	}
#line 7091 "y.tab.c" /* yacc.c:1646  */
    break;

  case 491:
#line 2962 "sql.yacc" /* yacc.c:1646  */
    {
		(yyval.s_select_list_item)=new_select_list_item_builtin_fcall(E_SLI_BUILTIN_FUNC_DATE,(yyvsp[-1].s_select_list_item_list));
	}
#line 7099 "y.tab.c" /* yacc.c:1646  */
    break;

  case 492:
#line 2965 "sql.yacc" /* yacc.c:1646  */
    {
		  (yyval.s_select_list_item)=new_select_list_item_simple_expr(E_SLI_BRACKET_EXPR,(yyvsp[-1].s_select_list_item));
	}
#line 7107 "y.tab.c" /* yacc.c:1646  */
    break;

  case 493:
#line 2968 "sql.yacc" /* yacc.c:1646  */
    { 
		add_feature("EXTEND"); 
		(yyval.s_select_list_item)=(yyvsp[-1].s_select_list_item);
	}
#line 7116 "y.tab.c" /* yacc.c:1646  */
    break;

  case 494:
#line 2972 "sql.yacc" /* yacc.c:1646  */
    { 
		(yyval.s_select_list_item)=new_select_list_item_datetime((yyvsp[0].str));
		add_feature("FUNC_DATETIME");
	}
#line 7125 "y.tab.c" /* yacc.c:1646  */
    break;

  case 495:
#line 2976 "sql.yacc" /* yacc.c:1646  */
    {
		(yyval.s_select_list_item)=new_select_list_item_interval((yyvsp[0].str));
		add_feature("FUNC_INTERVAL");
	}
#line 7134 "y.tab.c" /* yacc.c:1646  */
    break;

  case 496:
#line 2980 "sql.yacc" /* yacc.c:1646  */
    {
		(yyval.s_select_list_item)=(yyvsp[-1].s_select_list_item);
	}
#line 7142 "y.tab.c" /* yacc.c:1646  */
    break;

  case 497:
#line 2983 "sql.yacc" /* yacc.c:1646  */
    {
		(yyvsp[-1].s_select_list_item)->data.s_select_list_item_data_u.sqlcase.master_condition=(yyvsp[-2].s_select_list_item);
		(yyval.s_select_list_item)=(yyvsp[-1].s_select_list_item);
	}
#line 7151 "y.tab.c" /* yacc.c:1646  */
    break;

  case 498:
#line 2992 "sql.yacc" /* yacc.c:1646  */
    {
		(yyval.s_select_list_item)=new_select_list_item_case((yyvsp[0].s_select_list_item));
	}
#line 7159 "y.tab.c" /* yacc.c:1646  */
    break;

  case 499:
#line 2995 "sql.yacc" /* yacc.c:1646  */
    {
		(yyval.s_select_list_item)=append_select_list_item_case(
							(yyvsp[-1].s_select_list_item),
							(yyvsp[0].s_select_list_item));
	}
#line 7169 "y.tab.c" /* yacc.c:1646  */
    break;

  case 500:
#line 3004 "sql.yacc" /* yacc.c:1646  */
    {
		(yyval.s_select_list_item)=new_select_list_item_case_element(
				(yyvsp[-2].s_select_list_item),
				(yyvsp[0].s_select_list_item));

	}
#line 7180 "y.tab.c" /* yacc.c:1646  */
    break;

  case 501:
#line 3010 "sql.yacc" /* yacc.c:1646  */
    {
		(yyval.s_select_list_item)=new_select_list_item_case_element( 0, (yyvsp[0].s_select_list_item));
	}
#line 7188 "y.tab.c" /* yacc.c:1646  */
    break;

  case 502:
#line 3017 "sql.yacc" /* yacc.c:1646  */
    {
		(yyval.s_select_list_item_list)=local_new_select_list_item_list((yyvsp[0].s_select_list_item));
	}
#line 7196 "y.tab.c" /* yacc.c:1646  */
    break;

  case 503:
#line 3020 "sql.yacc" /* yacc.c:1646  */
    {
			(yyval.s_select_list_item_list)=local_add_select_list_item_list((yyvsp[-2].s_select_list_item_list),(yyvsp[0].s_select_list_item));
	}
#line 7204 "y.tab.c" /* yacc.c:1646  */
    break;

  case 504:
#line 3044 "sql.yacc" /* yacc.c:1646  */
    {(yyval.str_list)=NULL;}
#line 7210 "y.tab.c" /* yacc.c:1646  */
    break;

  case 505:
#line 3045 "sql.yacc" /* yacc.c:1646  */
    { (yyval.str_list)=new_str_list((yyvsp[-2].str));  add_str_list((yyval.str_list),(yyvsp[0].str));}
#line 7216 "y.tab.c" /* yacc.c:1646  */
    break;

  case 506:
#line 3046 "sql.yacc" /* yacc.c:1646  */
    { (yyval.str_list)=new_str_list((yyvsp[-2].str));  add_str_list((yyval.str_list),(yyvsp[0].str));}
#line 7222 "y.tab.c" /* yacc.c:1646  */
    break;

  case 508:
#line 3050 "sql.yacc" /* yacc.c:1646  */
    {
			(yyval.s_select_list_item)=new_select_list_item_extend((yyvsp[-1].s_select_list_item),(yyvsp[0].str_list));
	}
#line 7230 "y.tab.c" /* yacc.c:1646  */
    break;

  case 509:
#line 3053 "sql.yacc" /* yacc.c:1646  */
    {
			(yyval.s_select_list_item)=new_select_list_item_extend((yyvsp[-1].s_select_list_item),(yyvsp[0].str_list));
	}
#line 7238 "y.tab.c" /* yacc.c:1646  */
    break;

  case 510:
#line 3059 "sql.yacc" /* yacc.c:1646  */
    {(yyval.integer_val)=E_SLI_UNITS_YEAR;}
#line 7244 "y.tab.c" /* yacc.c:1646  */
    break;

  case 511:
#line 3060 "sql.yacc" /* yacc.c:1646  */
    {(yyval.integer_val)=E_SLI_UNITS_MONTH;}
#line 7250 "y.tab.c" /* yacc.c:1646  */
    break;

  case 512:
#line 3061 "sql.yacc" /* yacc.c:1646  */
    {(yyval.integer_val)=E_SLI_UNITS_DAY;}
#line 7256 "y.tab.c" /* yacc.c:1646  */
    break;

  case 513:
#line 3062 "sql.yacc" /* yacc.c:1646  */
    {(yyval.integer_val)=E_SLI_UNITS_HOUR;}
#line 7262 "y.tab.c" /* yacc.c:1646  */
    break;

  case 514:
#line 3063 "sql.yacc" /* yacc.c:1646  */
    {(yyval.integer_val)=E_SLI_UNITS_MINUTE;}
#line 7268 "y.tab.c" /* yacc.c:1646  */
    break;

  case 515:
#line 3064 "sql.yacc" /* yacc.c:1646  */
    {(yyval.integer_val)=E_SLI_UNITS_SECOND;}
#line 7274 "y.tab.c" /* yacc.c:1646  */
    break;

  case 516:
#line 3069 "sql.yacc" /* yacc.c:1646  */
    {
		(yyval.s_select_list_item)=new_select_list_item_op_slil((yyvsp[-4].s_select_list_item),(yyvsp[-1].s_select_list_item_list),E_SLI_IN_VALUES);
                add_feature("WHERE_IN");
        }
#line 7283 "y.tab.c" /* yacc.c:1646  */
    break;

  case 517:
#line 3073 "sql.yacc" /* yacc.c:1646  */
    {
		(yyval.s_select_list_item)=new_select_list_item_op_sli((yyvsp[-2].s_select_list_item),(yyvsp[0].s_select_list_item),E_SLI_IN_SELECT);
                add_feature("WHERE_IN_SELECT");
        }
#line 7292 "y.tab.c" /* yacc.c:1646  */
    break;

  case 518:
#line 3077 "sql.yacc" /* yacc.c:1646  */
    {
		(yyval.s_select_list_item)=new_select_list_item_op_slil((yyvsp[-4].s_select_list_item),(yyvsp[-1].s_select_list_item_list),E_SLI_NOT_IN_VALUES);
                add_feature("WHERE_IN");
        }
#line 7301 "y.tab.c" /* yacc.c:1646  */
    break;

  case 519:
#line 3081 "sql.yacc" /* yacc.c:1646  */
    {
		(yyval.s_select_list_item)=new_select_list_item_op_sli((yyvsp[-2].s_select_list_item),(yyvsp[0].s_select_list_item),E_SLI_NOT_IN_SELECT);
                add_feature("WHERE_IN_SELECT");
        }
#line 7310 "y.tab.c" /* yacc.c:1646  */
    break;

  case 520:
#line 3088 "sql.yacc" /* yacc.c:1646  */
    {
		(yyval.s_select_list_item_list)=local_new_select_list_item_list((yyvsp[0].s_select_list_item));
	}
#line 7318 "y.tab.c" /* yacc.c:1646  */
    break;

  case 521:
#line 3091 "sql.yacc" /* yacc.c:1646  */
    {
                (yyval.s_select_list_item_list)=local_add_select_list_item_list((yyvsp[-2].s_select_list_item_list),(yyvsp[0].s_select_list_item));
	}
#line 7326 "y.tab.c" /* yacc.c:1646  */
    break;

  case 522:
#line 3096 "sql.yacc" /* yacc.c:1646  */
    { (yyval.s_select_list_item)=(yyvsp[0].s_select_list_item);}
#line 7332 "y.tab.c" /* yacc.c:1646  */
    break;

  case 523:
#line 3097 "sql.yacc" /* yacc.c:1646  */
    { (yyval.s_select_list_item)=new_select_list_item_literal((yyvsp[0].str)); }
#line 7338 "y.tab.c" /* yacc.c:1646  */
    break;

  case 524:
#line 3098 "sql.yacc" /* yacc.c:1646  */
    { 
		char buff[256]; SPRINTF1(buff," -%s",(yyvsp[0].str)); (yyval.s_select_list_item)=new_select_list_item_literal(buff); }
#line 7345 "y.tab.c" /* yacc.c:1646  */
    break;

  case 525:
#line 3100 "sql.yacc" /* yacc.c:1646  */
    { char buff[256]; SPRINTF1(buff," -%s",(yyvsp[0].str)); (yyval.s_select_list_item)=new_select_list_item_literal(buff); }
#line 7351 "y.tab.c" /* yacc.c:1646  */
    break;

  case 526:
#line 3106 "sql.yacc" /* yacc.c:1646  */
    {
                if (strstr((yyvsp[0].str),"systables")!=0) { add_feature("IFX_SYSTABLES"); }
                if (strstr((yyvsp[0].str),"syscolumns")!=0) { add_feature("IFX_SYSCOLUMNS"); }
                if (strstr((yyvsp[0].str),"sysindexes")!=0) { add_feature("IFX_SYSINDEXES"); }
                strcpy((yyval.str),A4GLSQLCV_check_tablename((yyvsp[0].str)));
                }
#line 7362 "y.tab.c" /* yacc.c:1646  */
    break;

  case 527:
#line 3116 "sql.yacc" /* yacc.c:1646  */
    {
	     SPRINTF1((yyval.str),"%s", A4GLSQLCV_ownerize_tablename(NULL, A4GL_strip_quotes((yyvsp[0].str))));
             ADDMAP("Use Table",(yyval.str));
        }
#line 7371 "y.tab.c" /* yacc.c:1646  */
    break;

  case 528:
#line 3120 "sql.yacc" /* yacc.c:1646  */
    {
	     SPRINTF1((yyval.str),"%s", A4GLSQLCV_ownerize_tablename((yyvsp[-2].str), (yyvsp[0].str)));
	     ADDMAP("Use Table",(yyval.str));
        }
#line 7380 "y.tab.c" /* yacc.c:1646  */
    break;

  case 529:
#line 3124 "sql.yacc" /* yacc.c:1646  */
    {
	     SPRINTF1((yyval.str),"%s", A4GLSQLCV_ownerize_tablename(NULL, (yyvsp[0].str)));
	     ADDMAP("Use Table",(yyval.str));
	}
#line 7389 "y.tab.c" /* yacc.c:1646  */
    break;

  case 530:
#line 3128 "sql.yacc" /* yacc.c:1646  */
    {
	     SPRINTF1((yyval.str),"%s", A4GLSQLCV_db_tablename((yyvsp[-2].str), NULL, A4GLSQLCV_ownerize_tablename(NULL, (yyvsp[0].str))));
	     ADDMAP("Use Table",(yyval.str));
	}
#line 7398 "y.tab.c" /* yacc.c:1646  */
    break;

  case 531:
#line 3132 "sql.yacc" /* yacc.c:1646  */
    {
	     SPRINTF1((yyval.str),"%s", A4GLSQLCV_db_tablename((yyvsp[-4].str), NULL, A4GLSQLCV_ownerize_tablename((yyvsp[-2].str),(yyvsp[0].str))));
	     ADDMAP("Use Table",(yyval.str));
        }
#line 7407 "y.tab.c" /* yacc.c:1646  */
    break;

  case 532:
#line 3136 "sql.yacc" /* yacc.c:1646  */
    {
	     SPRINTF1((yyval.str),"%s", A4GLSQLCV_db_tablename(NULL,(yyvsp[-2].str), A4GLSQLCV_ownerize_tablename(NULL, (yyvsp[0].str))));
	     ADDMAP("Use Table",(yyval.str));
	}
#line 7416 "y.tab.c" /* yacc.c:1646  */
    break;

  case 533:
#line 3140 "sql.yacc" /* yacc.c:1646  */
    {
	     SPRINTF1((yyval.str),"%s", A4GLSQLCV_db_tablename((yyvsp[-4].str), (yyvsp[-2].str), A4GLSQLCV_ownerize_tablename(NULL, (yyvsp[0].str))));
	     ADDMAP("Use Table",(yyval.str));
	}
#line 7425 "y.tab.c" /* yacc.c:1646  */
    break;

  case 534:
#line 3144 "sql.yacc" /* yacc.c:1646  */
    {
	     SPRINTF1((yyval.str),"%s", A4GLSQLCV_db_tablename((yyvsp[-6].str), (yyvsp[-4].str), A4GLSQLCV_ownerize_tablename((yyvsp[-2].str), (yyvsp[0].str))));
	     ADDMAP("Use Table",(yyval.str));
        }
#line 7434 "y.tab.c" /* yacc.c:1646  */
    break;

  case 535:
#line 3152 "sql.yacc" /* yacc.c:1646  */
    {
                if (strstr((yyvsp[0].str),"systables")!=0) { add_feature("IFX_SYSTABLES"); }
                if (strstr((yyvsp[0].str),"syscolumns")!=0) { add_feature("IFX_SYSCOLUMNS"); }
                if (strstr((yyvsp[0].str),"sysindexes")!=0) { add_feature("IFX_SYSINDEXES"); }
                strcpy((yyval.str),A4GLSQLCV_check_tablename((yyvsp[0].str)));
                }
#line 7445 "y.tab.c" /* yacc.c:1646  */
    break;

  case 536:
#line 3162 "sql.yacc" /* yacc.c:1646  */
    {

	     SPRINTF1((yyval.str),"%s", A4GLSQLCV_ownerize_tablename((yyvsp[-2].str), (yyvsp[0].str)));
	     ADDMAP("Use Table",(yyval.str));
        }
#line 7455 "y.tab.c" /* yacc.c:1646  */
    break;

  case 537:
#line 3167 "sql.yacc" /* yacc.c:1646  */
    {
	     SPRINTF1((yyval.str),"%s", A4GLSQLCV_ownerize_tablename((yyvsp[-2].str), (yyvsp[0].str)));
	     ADDMAP("Use Table",(yyval.str));
        }
#line 7464 "y.tab.c" /* yacc.c:1646  */
    break;

  case 538:
#line 3171 "sql.yacc" /* yacc.c:1646  */
    {
	     SPRINTF1((yyval.str),"%s", A4GLSQLCV_ownerize_tablename(NULL, A4GL_strip_quotes((yyvsp[0].str))));
	     ADDMAP("Use Table",(yyval.str));
        }
#line 7473 "y.tab.c" /* yacc.c:1646  */
    break;

  case 539:
#line 3175 "sql.yacc" /* yacc.c:1646  */
    {
             SPRINTF1((yyval.str),"%s", A4GLSQLCV_ownerize_tablename(NULL, (yyvsp[0].str)));
	     ADDMAP("Use Table",(yyval.str));
	}
#line 7482 "y.tab.c" /* yacc.c:1646  */
    break;

  case 540:
#line 3179 "sql.yacc" /* yacc.c:1646  */
    {
             SPRINTF1((yyval.str),"%s", A4GLSQLCV_db_tablename((yyvsp[-2].str),NULL, A4GLSQLCV_ownerize_tablename(NULL, (yyvsp[0].str))));
	     ADDMAP("Use Table",(yyval.str));
	}
#line 7491 "y.tab.c" /* yacc.c:1646  */
    break;

  case 541:
#line 3183 "sql.yacc" /* yacc.c:1646  */
    {
	     SPRINTF1((yyval.str),"%s", A4GLSQLCV_db_tablename((yyvsp[-4].str), NULL,A4GLSQLCV_ownerize_tablename((yyvsp[-2].str), (yyvsp[0].str))));
	     ADDMAP("Use Table",(yyval.str));
        }
#line 7500 "y.tab.c" /* yacc.c:1646  */
    break;

  case 542:
#line 3188 "sql.yacc" /* yacc.c:1646  */
    {
             SPRINTF1((yyval.str),"%s", A4GLSQLCV_db_tablename(NULL, (yyvsp[-2].str), A4GLSQLCV_ownerize_tablename(NULL, (yyvsp[0].str))));
	     ADDMAP("Use Table",(yyval.str));
	}
#line 7509 "y.tab.c" /* yacc.c:1646  */
    break;

  case 543:
#line 3192 "sql.yacc" /* yacc.c:1646  */
    {
            SPRINTF1((yyval.str),"%s", A4GLSQLCV_db_tablename( (yyvsp[-4].str), (yyvsp[-2].str), A4GLSQLCV_ownerize_tablename(NULL, (yyvsp[0].str))));
	    ADDMAP("Use Table",(yyval.str));
	}
#line 7518 "y.tab.c" /* yacc.c:1646  */
    break;

  case 544:
#line 3196 "sql.yacc" /* yacc.c:1646  */
    {
	     SPRINTF1((yyval.str),"%s", A4GLSQLCV_db_tablename((yyvsp[-6].str), (yyvsp[-4].str), A4GLSQLCV_ownerize_tablename((yyvsp[-2].str), (yyvsp[0].str))));
	     ADDMAP("Use Table",(yyval.str));
        }
#line 7527 "y.tab.c" /* yacc.c:1646  */
    break;

  case 545:
#line 3204 "sql.yacc" /* yacc.c:1646  */
    {
	     SPRINTF1((yyval.str),"%s", A4GLSQLCV_ownerize_tablename((yyvsp[-2].str), (yyvsp[0].str)));
        }
#line 7535 "y.tab.c" /* yacc.c:1646  */
    break;

  case 546:
#line 3207 "sql.yacc" /* yacc.c:1646  */
    {
	        SPRINTF1((yyval.str),"%s", A4GLSQLCV_ownerize_tablename(NULL, (yyvsp[0].str)));
                ADDMAP("Use Index",(yyval.str));
        }
#line 7544 "y.tab.c" /* yacc.c:1646  */
    break;

  case 547:
#line 3212 "sql.yacc" /* yacc.c:1646  */
    {strcpy((yyval.str),(yyvsp[0].str)); ADDMAP("Use Index",(yyvsp[0].str)); }
#line 7550 "y.tab.c" /* yacc.c:1646  */
    break;

  case 548:
#line 3213 "sql.yacc" /* yacc.c:1646  */
    { SPRINTF3((yyval.str),"%s%s%s",(yyvsp[-2].str),(yyvsp[-1].str),(yyvsp[0].str)); ADDMAP("Use Index",(yyval.str)); }
#line 7556 "y.tab.c" /* yacc.c:1646  */
    break;

  case 549:
#line 3214 "sql.yacc" /* yacc.c:1646  */
    {
	     SPRINTF2((yyval.str),"%s:%s", (yyvsp[-4].str), A4GLSQLCV_ownerize_tablename((yyvsp[-2].str), (yyvsp[0].str)));
             ADDMAP("Use Index",(yyval.str));
        }
#line 7565 "y.tab.c" /* yacc.c:1646  */
    break;

  case 550:
#line 3219 "sql.yacc" /* yacc.c:1646  */
    {strcpy((yyval.str),(yyvsp[-2].str)); ADDMAP("Use Index",(yyvsp[-2].str)); }
#line 7571 "y.tab.c" /* yacc.c:1646  */
    break;

  case 551:
#line 3220 "sql.yacc" /* yacc.c:1646  */
    { SPRINTF4((yyval.str),"%s@%s%s%s",(yyvsp[-4].str),(yyvsp[-2].str),(yyvsp[-1].str),(yyvsp[0].str)); ADDMAP("Use Index",(yyval.str)); }
#line 7577 "y.tab.c" /* yacc.c:1646  */
    break;

  case 552:
#line 3221 "sql.yacc" /* yacc.c:1646  */
    {
	     SPRINTF3((yyval.str),"%s@%s:%s", (yyvsp[-6].str), (yyvsp[-4].str), A4GLSQLCV_ownerize_tablename((yyvsp[-2].str), (yyvsp[0].str)));
             ADDMAP("Use Index",(yyval.str));
        }
#line 7586 "y.tab.c" /* yacc.c:1646  */
    break;

  case 554:
#line 3232 "sql.yacc" /* yacc.c:1646  */
    {
                      (yyval.ptr)=A4GL_new_expr_simple_string(A4GL_get_clobbered_from((yyval.str)), ET_EXPR_IDENTIFIER);
	}
#line 7594 "y.tab.c" /* yacc.c:1646  */
    break;

  case 556:
#line 3238 "sql.yacc" /* yacc.c:1646  */
    { sprintf((yyval.str),".%s",(yyvsp[0].str)); }
#line 7600 "y.tab.c" /* yacc.c:1646  */
    break;

  case 558:
#line 3243 "sql.yacc" /* yacc.c:1646  */
    {strcpy((yyval.str), A4GL_strip_quotes ((yyvsp[0].str)));}
#line 7606 "y.tab.c" /* yacc.c:1646  */
    break;

  case 559:
#line 3248 "sql.yacc" /* yacc.c:1646  */
    {(yyval.ptr_list)=0;}
#line 7612 "y.tab.c" /* yacc.c:1646  */
    break;

  case 563:
#line 3295 "sql.yacc" /* yacc.c:1646  */
    {
			int converted;
			(yyval.sql_string)=get_insert_cmd((yyvsp[0].insert_cmd),&converted);
			A4GL_free_associated_mem((yyvsp[0].insert_cmd));
			acl_free((yyvsp[0].insert_cmd));

		}
#line 7624 "y.tab.c" /* yacc.c:1646  */
    break;

  case 564:
#line 3302 "sql.yacc" /* yacc.c:1646  */
    {
			int converted;
			(yyval.sql_string)=get_update_cmd((yyvsp[0].update_cmd),&converted);
			A4GL_free_associated_mem((yyvsp[0].update_cmd));
			acl_free((yyvsp[0].update_cmd));
		}
#line 7635 "y.tab.c" /* yacc.c:1646  */
    break;

  case 565:
#line 3308 "sql.yacc" /* yacc.c:1646  */
    {
			int converted;
			(yyval.sql_string)=get_delete_cmd((yyvsp[0].delete_cmd),&converted);
			A4GL_free_associated_mem((yyvsp[0].delete_cmd));
			acl_free((yyvsp[0].delete_cmd));
		}
#line 7646 "y.tab.c" /* yacc.c:1646  */
    break;

  case 568:
#line 3323 "sql.yacc" /* yacc.c:1646  */
    { print_exec_select((yyvsp[0].sql_string));  }
#line 7652 "y.tab.c" /* yacc.c:1646  */
    break;

  case 569:
#line 3324 "sql.yacc" /* yacc.c:1646  */
    { print_exec_select((yyvsp[0].sql_string));  }
#line 7658 "y.tab.c" /* yacc.c:1646  */
    break;

  case 571:
#line 3326 "sql.yacc" /* yacc.c:1646  */
    { print_exec_select((yyvsp[0].sql_string));  }
#line 7664 "y.tab.c" /* yacc.c:1646  */
    break;

  case 572:
#line 3328 "sql.yacc" /* yacc.c:1646  */
    {
			print_sql_commit ((yyvsp[0].integer_val));
	}
#line 7672 "y.tab.c" /* yacc.c:1646  */
    break;

  case 573:
#line 3331 "sql.yacc" /* yacc.c:1646  */
    {print_unable_to_parse();}
#line 7678 "y.tab.c" /* yacc.c:1646  */
    break;

  case 574:
#line 3335 "sql.yacc" /* yacc.c:1646  */
    { (yyval.sql_string)=make_sql_string_and_free((yyvsp[-1].sql_string),acl_strdup((yyvsp[0].str)),0);
}
#line 7685 "y.tab.c" /* yacc.c:1646  */
    break;

  case 576:
#line 3344 "sql.yacc" /* yacc.c:1646  */
    {
			(yyval.sql_string)=make_select_stmt_v2("", (yyvsp[0].s_select),"");
			A4GL_free_select_stmt((yyvsp[0].s_select));
		}
#line 7694 "y.tab.c" /* yacc.c:1646  */
    break;

  case 577:
#line 3350 "sql.yacc" /* yacc.c:1646  */
    {strcpy((yyval.str),"");}
#line 7700 "y.tab.c" /* yacc.c:1646  */
    break;

  case 578:
#line 3351 "sql.yacc" /* yacc.c:1646  */
    {
			strcpy((yyval.str),A4GLSQLCV_get_forupdate(NULL));
		}
#line 7708 "y.tab.c" /* yacc.c:1646  */
    break;

  case 579:
#line 3354 "sql.yacc" /* yacc.c:1646  */
    {
			strcpy((yyval.str),A4GLSQLCV_get_forupdate((yyvsp[0].str)));
		}
#line 7716 "y.tab.c" /* yacc.c:1646  */
    break;

  case 580:
#line 3359 "sql.yacc" /* yacc.c:1646  */
    { strcpy((yyval.str),(yyvsp[0].str)); }
#line 7722 "y.tab.c" /* yacc.c:1646  */
    break;

  case 581:
#line 3360 "sql.yacc" /* yacc.c:1646  */
    { sprintf((yyval.str),"%s,%s",(yyvsp[-2].str),(yyvsp[0].str)); }
#line 7728 "y.tab.c" /* yacc.c:1646  */
    break;

  case 583:
#line 3364 "sql.yacc" /* yacc.c:1646  */
    {sprintf((yyval.str),"%s.%s",A4GLSQLCV_ownerize_tablename(NULL, (yyvsp[-2].str)),(yyvsp[0].str));}
#line 7734 "y.tab.c" /* yacc.c:1646  */
    break;

  case 584:
#line 3365 "sql.yacc" /* yacc.c:1646  */
    {
        sprintf((yyval.str),"%s.%s", A4GLSQLCV_ownerize_tablename((yyvsp[-4].str), (yyvsp[-2].str)), (yyvsp[0].str));
}
#line 7742 "y.tab.c" /* yacc.c:1646  */
    break;

  case 585:
#line 3375 "sql.yacc" /* yacc.c:1646  */
    { print_exec_sql(acl_strdup((yyvsp[0].str))); }
#line 7748 "y.tab.c" /* yacc.c:1646  */
    break;

  case 586:
#line 3376 "sql.yacc" /* yacc.c:1646  */
    { print_exec_sql(acl_strdup((yyvsp[0].str))); }
#line 7754 "y.tab.c" /* yacc.c:1646  */
    break;

  case 587:
#line 3377 "sql.yacc" /* yacc.c:1646  */
    { sprintf((yyval.str),"%s %s",(yyvsp[-1].str),(yyvsp[0].str)); print_exec_sql(acl_strdup((yyval.str))); }
#line 7760 "y.tab.c" /* yacc.c:1646  */
    break;

  case 588:
#line 3378 "sql.yacc" /* yacc.c:1646  */
    { print_exec_sql(acl_strdup((yyvsp[0].str))); }
#line 7766 "y.tab.c" /* yacc.c:1646  */
    break;

  case 589:
#line 3379 "sql.yacc" /* yacc.c:1646  */
    { print_exec_sql(acl_strdup((yyvsp[0].str))); }
#line 7772 "y.tab.c" /* yacc.c:1646  */
    break;

  case 590:
#line 3380 "sql.yacc" /* yacc.c:1646  */
    { print_exec_sql(acl_strdup((yyvsp[0].str))); }
#line 7778 "y.tab.c" /* yacc.c:1646  */
    break;

  case 591:
#line 3381 "sql.yacc" /* yacc.c:1646  */
    { print_exec_sql(acl_strdup((yyvsp[0].str))); }
#line 7784 "y.tab.c" /* yacc.c:1646  */
    break;

  case 592:
#line 3382 "sql.yacc" /* yacc.c:1646  */
    { print_exec_sql(acl_strdup((yyvsp[0].str))); }
#line 7790 "y.tab.c" /* yacc.c:1646  */
    break;

  case 593:
#line 3386 "sql.yacc" /* yacc.c:1646  */
    { 
	char *s;
	s=acl_strdup((yyvsp[0].str));
	(yyval.s_select_list_item)=new_select_list_item_column_from_transform(s);
	acl_free(s);
	}
#line 7801 "y.tab.c" /* yacc.c:1646  */
    break;

  case 594:
#line 3392 "sql.yacc" /* yacc.c:1646  */
    {  
		(yyval.s_select_list_item)=new_select_list_item_builtin_const(E_SLI_QUERY_PLACEHOLDER);}
#line 7808 "y.tab.c" /* yacc.c:1646  */
    break;

  case 595:
#line 3394 "sql.yacc" /* yacc.c:1646  */
    {
		(yyval.s_select_list_item)=new_select_list_item_replace_var((yyvsp[0].sql_string));
	}
#line 7816 "y.tab.c" /* yacc.c:1646  */
    break;

  case 596:
#line 3413 "sql.yacc" /* yacc.c:1646  */
    {
        add_feature("DATABASE_USED");
       conn_db((yyvsp[-1].str));
}
#line 7825 "y.tab.c" /* yacc.c:1646  */
    break;

  case 597:
#line 3421 "sql.yacc" /* yacc.c:1646  */
    {
		(yyval.sql_string)=acl_strdup((yyvsp[-1].str));
}
#line 7833 "y.tab.c" /* yacc.c:1646  */
    break;

  case 598:
#line 3428 "sql.yacc" /* yacc.c:1646  */
    {sprintf((yyval.str),"(%s)",(yyvsp[-1].str));}
#line 7839 "y.tab.c" /* yacc.c:1646  */
    break;

  case 599:
#line 3429 "sql.yacc" /* yacc.c:1646  */
    { sprintf((yyval.str),"%s%s%s",(yyvsp[-2].str),(yyvsp[-1].str),(yyvsp[0].str));}
#line 7845 "y.tab.c" /* yacc.c:1646  */
    break;

  case 600:
#line 3430 "sql.yacc" /* yacc.c:1646  */
    {sprintf((yyval.str),"%d",atoi((yyvsp[0].str)));}
#line 7851 "y.tab.c" /* yacc.c:1646  */
    break;

  case 601:
#line 3431 "sql.yacc" /* yacc.c:1646  */
    {sprintf((yyval.str),"(%s%s)",(yyvsp[-1].str),(yyvsp[0].str));}
#line 7857 "y.tab.c" /* yacc.c:1646  */
    break;

  case 602:
#line 3436 "sql.yacc" /* yacc.c:1646  */
    {strcpy((yyval.str),"+");}
#line 7863 "y.tab.c" /* yacc.c:1646  */
    break;

  case 603:
#line 3437 "sql.yacc" /* yacc.c:1646  */
    {strcpy((yyval.str),"-");}
#line 7869 "y.tab.c" /* yacc.c:1646  */
    break;

  case 604:
#line 3438 "sql.yacc" /* yacc.c:1646  */
    {strcpy((yyval.str),"*");}
#line 7875 "y.tab.c" /* yacc.c:1646  */
    break;

  case 605:
#line 3439 "sql.yacc" /* yacc.c:1646  */
    {strcpy((yyval.str),"/");}
#line 7881 "y.tab.c" /* yacc.c:1646  */
    break;

  case 606:
#line 3440 "sql.yacc" /* yacc.c:1646  */
    {strcpy((yyval.str),"%");}
#line 7887 "y.tab.c" /* yacc.c:1646  */
    break;

  case 607:
#line 3445 "sql.yacc" /* yacc.c:1646  */
    {strcpy((yyval.str),"+");}
#line 7893 "y.tab.c" /* yacc.c:1646  */
    break;

  case 608:
#line 3446 "sql.yacc" /* yacc.c:1646  */
    {strcpy((yyval.str),"-");}
#line 7899 "y.tab.c" /* yacc.c:1646  */
    break;

  case 609:
#line 3462 "sql.yacc" /* yacc.c:1646  */
    {sprintf((yyval.str),"%s", A4GLSQLCV_check_tablename((yyvsp[0].str)));}
#line 7905 "y.tab.c" /* yacc.c:1646  */
    break;

  case 610:
#line 3463 "sql.yacc" /* yacc.c:1646  */
    {sprintf((yyval.str),"%s.*", A4GLSQLCV_ownerize_tablename(NULL,(yyvsp[-2].str)));}
#line 7911 "y.tab.c" /* yacc.c:1646  */
    break;

  case 611:
#line 3464 "sql.yacc" /* yacc.c:1646  */
    {sprintf((yyval.str),"%s.%s", (yyvsp[-2].str),A4GLSQLCV_get_sqlconst ("rowid"));}
#line 7917 "y.tab.c" /* yacc.c:1646  */
    break;

  case 612:
#line 3465 "sql.yacc" /* yacc.c:1646  */
    {sprintf((yyval.str),"%s.%s", A4GLSQLCV_ownerize_tablename(NULL,(yyvsp[-2].str)),(yyvsp[0].str));}
#line 7923 "y.tab.c" /* yacc.c:1646  */
    break;

  case 613:
#line 3466 "sql.yacc" /* yacc.c:1646  */
    {sprintf((yyval.str),"%s.%s", A4GLSQLCV_ownerize_tablename((yyvsp[-4].str),(yyvsp[-2].str)),(yyvsp[0].str));}
#line 7929 "y.tab.c" /* yacc.c:1646  */
    break;

  case 614:
#line 3467 "sql.yacc" /* yacc.c:1646  */
    {sprintf((yyval.str),"%s.%s", A4GLSQLCV_ownerize_tablename((yyvsp[-4].str),(yyvsp[-2].str)),(yyvsp[0].str));}
#line 7935 "y.tab.c" /* yacc.c:1646  */
    break;

  case 615:
#line 3468 "sql.yacc" /* yacc.c:1646  */
    {sprintf((yyval.str),"%s", (yyvsp[-3].str)); strcpy((yyval.str), A4GLSQLCV_make_substr_s((yyvsp[-3].str), 1,(yyvsp[-1].str),0));}
#line 7941 "y.tab.c" /* yacc.c:1646  */
    break;

  case 616:
#line 3469 "sql.yacc" /* yacc.c:1646  */
    {char buff[256]; sprintf(buff,"%s.%s", A4GLSQLCV_ownerize_tablename(NULL,(yyvsp[-5].str)),(yyvsp[-3].str)); strcpy((yyval.str), A4GLSQLCV_make_substr_s(buff,1,(yyvsp[-1].str),0));}
#line 7947 "y.tab.c" /* yacc.c:1646  */
    break;

  case 617:
#line 3470 "sql.yacc" /* yacc.c:1646  */
    {char buff[256]; sprintf(buff,"%s.%s", A4GLSQLCV_ownerize_tablename((yyvsp[-7].str),(yyvsp[-5].str)), (yyvsp[-3].str)); strcpy((yyval.str), A4GLSQLCV_make_substr_s(buff,1,(yyvsp[-1].str),0));  }
#line 7953 "y.tab.c" /* yacc.c:1646  */
    break;

  case 618:
#line 3471 "sql.yacc" /* yacc.c:1646  */
    {char buff[256]; sprintf(buff,"%s.%s", A4GLSQLCV_ownerize_tablename((yyvsp[-7].str),(yyvsp[-5].str)), (yyvsp[-3].str));  strcpy((yyval.str), A4GLSQLCV_make_substr_s(buff,1,(yyvsp[-1].str),0)); }
#line 7959 "y.tab.c" /* yacc.c:1646  */
    break;

  case 619:
#line 3473 "sql.yacc" /* yacc.c:1646  */
    {sprintf((yyval.str),"%s", (yyvsp[-5].str)); strcpy((yyval.str), A4GLSQLCV_make_substr_s((yyvsp[-5].str), 2,(yyvsp[-3].str),(yyvsp[-1].str)));}
#line 7965 "y.tab.c" /* yacc.c:1646  */
    break;

  case 620:
#line 3474 "sql.yacc" /* yacc.c:1646  */
    {char buff[256]; sprintf(buff,"%s.%s", A4GLSQLCV_ownerize_tablename(NULL,(yyvsp[-7].str)),(yyvsp[-5].str)); strcpy((yyval.str), A4GLSQLCV_make_substr_s(buff,2,(yyvsp[-3].str),(yyvsp[-1].str)));}
#line 7971 "y.tab.c" /* yacc.c:1646  */
    break;

  case 621:
#line 3475 "sql.yacc" /* yacc.c:1646  */
    {char buff[256]; sprintf(buff,"%s.%s", A4GLSQLCV_ownerize_tablename((yyvsp[-9].str),(yyvsp[-7].str)), (yyvsp[-5].str)); strcpy((yyval.str), A4GLSQLCV_make_substr_s(buff,2,(yyvsp[-3].str),(yyvsp[-1].str)));  }
#line 7977 "y.tab.c" /* yacc.c:1646  */
    break;

  case 622:
#line 3476 "sql.yacc" /* yacc.c:1646  */
    {char buff[256]; sprintf(buff,"%s.%s", A4GLSQLCV_ownerize_tablename((yyvsp[-9].str),(yyvsp[-7].str)), (yyvsp[-5].str));  strcpy((yyval.str), A4GLSQLCV_make_substr_s(buff,2,(yyvsp[-3].str),(yyvsp[-1].str))); }
#line 7983 "y.tab.c" /* yacc.c:1646  */
    break;

  case 623:
#line 3481 "sql.yacc" /* yacc.c:1646  */
    {
                (yyval.s_select_list_item)=(yyvsp[0].s_select_list_item);
        }
#line 7991 "y.tab.c" /* yacc.c:1646  */
    break;

  case 624:
#line 3484 "sql.yacc" /* yacc.c:1646  */
    {
                (yyval.s_select_list_item)=new_select_list_item_cast((yyvsp[-2].s_select_list_item), (yyvsp[0].str));
        }
#line 7999 "y.tab.c" /* yacc.c:1646  */
    break;

  case 625:
#line 3493 "sql.yacc" /* yacc.c:1646  */
    { (yyvsp[0].s_select_list_item)=(yyvsp[0].s_select_list_item); }
#line 8005 "y.tab.c" /* yacc.c:1646  */
    break;

  case 626:
#line 3494 "sql.yacc" /* yacc.c:1646  */
    {(yyvsp[0].s_select_list_item)=(yyvsp[0].s_select_list_item);}
#line 8011 "y.tab.c" /* yacc.c:1646  */
    break;

  case 627:
#line 3495 "sql.yacc" /* yacc.c:1646  */
    {  (yyval.s_select_list_item)=new_select_list_item_sq(E_SQE_DONT_CARE,(yyvsp[0].s_select_list_item)); }
#line 8017 "y.tab.c" /* yacc.c:1646  */
    break;

  case 628:
#line 3496 "sql.yacc" /* yacc.c:1646  */
    { (yyval.s_select_list_item)=new_select_list_item_sq(E_SQE_ALL,(yyvsp[0].s_select_list_item)); }
#line 8023 "y.tab.c" /* yacc.c:1646  */
    break;

  case 629:
#line 3497 "sql.yacc" /* yacc.c:1646  */
    { (yyval.s_select_list_item)=new_select_list_item_sq(E_SQE_ANY,(yyvsp[0].s_select_list_item)); }
#line 8029 "y.tab.c" /* yacc.c:1646  */
    break;

  case 630:
#line 3498 "sql.yacc" /* yacc.c:1646  */
    { (yyval.s_select_list_item)=new_select_list_item_sq(E_SQE_SOME,(yyvsp[0].s_select_list_item)); }
#line 8035 "y.tab.c" /* yacc.c:1646  */
    break;

  case 631:
#line 3502 "sql.yacc" /* yacc.c:1646  */
    {strcpy((yyval.str),"");}
#line 8041 "y.tab.c" /* yacc.c:1646  */
    break;

  case 632:
#line 3503 "sql.yacc" /* yacc.c:1646  */
    {strcpy((yyval.str),(yyvsp[0].str));}
#line 8047 "y.tab.c" /* yacc.c:1646  */
    break;

  case 633:
#line 3517 "sql.yacc" /* yacc.c:1646  */
    {
	(yyval.integer_val)=-1;
}
#line 8055 "y.tab.c" /* yacc.c:1646  */
    break;


#line 8059 "y.tab.c" /* yacc.c:1646  */
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
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

  /* Do not reclaim the symbols of the rule whose action triggered
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
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
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

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


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

#if !defined yyoverflow || YYERROR_VERBOSE
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
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
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
  return yyresult;
}
#line 3520 "sql.yacc" /* yacc.c:1906  */


#if LEX_YY_PREGEN
#include "../../tools/no_yacc/cygwin/compilers/sql/lex.sqlparse_yy.c"
#else
#include "lex.yy.c"
#endif
#include "util.c"
#include "cmds.c"
