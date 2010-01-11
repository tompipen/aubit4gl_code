
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


#define add_feature A4GL_add_feature
void add_sql_function(char *s);

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

int insql=0;
static char *make_sql_string_and_free(char *,...);
char last_tmp_name[256];
#define ADDMAP(x,y) addmap_runtime(x,y)
#define ADDMAP_MODULE(x,y) addmap_runtime(x,y)

int yylineno;
int table_cnt=0;
char* curr_func="";
char *infilename="";
int doing_declare=0;
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
#line 199 "y.tab.c"

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
     INT_VALUE = 2229,
     NAMED = 2230,
     NAMED_GEN = 2231,
     CHAR_VALUE = 2232,
     NOT_USED_1 = 2233,
     NOT_USED_2 = 2234,
     NOT_USED_3 = 2235,
     NOT_USED_4 = 2236,
     NOT_USED_5 = 2237,
     NOT_USED_6 = 2238,
     NOT_USED_7 = 2239,
     NOT_USED_8 = 2240,
     NUMBER_VALUE = 2241,
     SEMICOLON = 2242,
     QUESTION_MARK = 2243,
     CLINE = 2244,
     CH = 2245,
     MARK_VAR = 2246,
     END_MARK_VAR = 2247,
     WITH_LISTING_IN = 1001,
     SET_CONSTRAINTS_ALL_DEFERRED = 1002,
     DOCUMENT = 1003,
     ON_EXCEPTION = 1005,
     SET_DEBUG_FILE_TO = 1006,
     CREATE_DBA_PROCEDURE = 1011,
     CREATE_FUNCTION = 1012,
     CREATE_DBA_FUNCTION = 1013,
     USE_SESSION = 1015,
     KW_RUN_CLIENT = 1016,
     LEFT_JOIN = 1018,
     IGNORE_ERRORS = 1021,
     SQLERRMESSAGE = 1022,
     DISPLAY_NULL_TO = 1023,
     UNBUFFERED = 1024,
     KW_PICTURE = 1025,
     ON_CHANGE = 1026,
     INNER_JOIN = 1027,
     UI_INTERFACE_DOT_FRONTCALL = 1030,
     UICOMBOBOX = 1034,
     UIFORM = 1037,
     USING_BTREE = 1053,
     USING_RTREE = 1054,
     SET_BUFFERED_LOG = 1073,
     SET_LOG = 1076,
     MDY = 1078,
     WEEKDAY = 1079,
     MODE_ANSI = 1082,
     START_DATABASE = 1083,
     WITH_LOG_IN = 1084,
     SET_CONSTRAINTS_ALL_IMMEDIATE = 1085,
     DATETIME_VALUE = 1098,
     INTERVAL_VALUE = 1099,
     RECOVER_TABLE = 1100,
     ROLLFORWARD_DATABASE = 1101,
     DROP_TRIGGER = 1117,
     DROP_AUDIT_FOR = 1118,
     CREATE_AUDIT_FOR = 1119,
     EXECUTE_PROCEDURE = 1123,
     ALTER_TABLE = 1130,
     ALTER_INDEX = 1131,
     NEXT_SIZE = 1132,
     XSET_MULTIPLY_EQUAL_OPEN_BRACKET = 1169,
     XSET_ident_DOT_MULTIPLY_EQUAL_OPEN_BRACKET = 1170,
     XSET_ident_DOT_MULTIPLY_EQUAL = 1171,
     XSET_MULTIPLY_EQUAL = 1172,
     XSET_OPEN_BRACKET = 1173,
     CREATE_DATABASE = 1176,
     DROP_DATABASE = 1177,
     ADD_CONSTRAINT = 1179,
     DROP_CONSTRAINT = 1180,
     DROP_SYNONYM = 1181,
     CONSTRAINT = 1182,
     NOT_FIELD_TOUCHED_CURRENT = 1185,
     FIELD_TOUCHED_CURRENT = 1186,
     DOUBLE_PRECISION = 1193,
     COUNT_MULTIPLY = 1194,
     MODIFY_NEXT_SIZE = 1214,
     LOCK_MODE_PAGE = 1215,
     LOCK_MODE_ROW = 1216,
     UNITS_YEAR = 1223,
     UNITS_MONTH = 1224,
     UNITS_DAY = 1225,
     UNITS_HOUR = 1226,
     UNITS_MINUTE = 1227,
     UNITS_SECOND = 1228,
     TO_CLUSTER = 1233,
     TO_NOT_CLUSTER = 1234,
     CREATE_UC_IDX = 1236,
     CREATE_U_IDX = 1237,
     CREATE_C_IDX = 1238,
     CREATE_IDX = 1239,
     DOUBLE_COLON = 1249,
     SQLSICS = 1255,
     CREATE_SCHEMA = 1256,
     SQLSIRR = 1257,
     UPDATESTATS_T = 1258,
     SQLSICR = 1259,
     SQLSIDR = 1270,
     CREATE_TEMP_TABLE = 1271,
     WITH_CHECK_OPTION = 1279,
     WITH_GRANT_OPTION = 1280,
     SQLSLMNW = 1281,
     WHERE_CURRENT_OF = 1287,
     NOT_NULL_UNIQUE = 1295,
     SQLSLMW = 1302,
     ALL_PRIVILEGES = 1304,
     CREATE_SYNONYM = 1308,
     DROP_TABLE = 1309,
     INEXCLUSIVE = 1311,
     UPDATESTATS = 1316,
     CREATE_TABLE = 1342,
     DEFAULT_NULL = 1343,
     DEFAULT_TODAY = 1344,
     DEFAULT_USER = 1345,
     UNLOCK_TABLE = 1358,
     ROLLBACK_W = 1366,
     SQLSEON = 1368,
     SQLSEOFF = 1369,
     CREATE_VIEW = 1373,
     DELETE_FROM = 1374,
     EXTENT_SIZE = 1381,
     FOREIGN_KEY = 1382,
     INSERT_INTO = 1385,
     IS_NOT_NULL = 1387,
     NOT_MATCHES = 1390,
     PRIMARY_KEY = 1396,
     WITH_NO_LOG = 1403,
     INSHARE = 1406,
     BEGIN_WORK = 1412,
     DROP_INDEX = 1417,
     FOR_UPDATE_OF = 1423,
     FOR_UPDATE = 1424,
     LOCK_TABLE = 1429,
     NOT_EXISTS = 1431,
     REFERENCES = 1433,
     RENCOL = 1434,
     SMALLFLOAT = 1436,
     COMMIT_W = 1447,
     RENTAB = 1454,
     KW_CHAR = 1457,
     NCHAR = 1458,
     NVARCHAR = 1459,
     DELIMITER = 1461,
     DROP_VIEW = 1463,
     EXCLUSIVE = 1466,
     GREATER_THAN_EQ = 1470,
     INTO_TEMP = 1472,
     DATABASE = 1496,
     DATETIME = 1497,
     DISTINCT = 1499,
     FRACTION = 1506,
     GROUP_BY = 1508,
     INTERVAL = 1509,
     NOT_LIKE = 1511,
     NOT_ILIKE = 1512,
     NOT_NULL = 1513,
     RESOURCE = 1519,
     SMALLINT = 1520,
     IS_NULL = 1526,
     LESS_THAN_EQ = 1527,
     BETWEEN = 1529,
     CLOSE_BRACKET = 1532,
     CONNECT = 1535,
     KW_CURRENT = 1536,
     KW_DECIMAL = 1538,
     DEFAULT = 1540,
     INTEGER = 1548,
     SERIAL8 = 1550,
     MATCHES = 1553,
     VARCHAR = 1566,
     CLOSE_SQUARE = 1569,
     GREATER_THAN = 1570,
     KW_FALSE = 1571,
     NOT_IN = 1572,
     OPEN_BRACKET = 1574,
     KW_DELETE = 1582,
     KW_ESCAPE = 1585,
     EXISTS = 1586,
     EXTEND = 1587,
     HAVING = 1591,
     KW_INSERT = 1593,
     MINUTE = 1597,
     MODIFY = 1598,
     EQUAL = 1600,
     NOT_EQUAL = 1601,
     OPEN_SQUARE = 1603,
     PUBLIC = 1607,
     REVOKE = 1611,
     SECOND = 1615,
     KW_SELECT = 1619,
     SERIAL = 1620,
     UNIQUE = 1623,
     KW_UPDATE = 1625,
     VALUES = 1626,
     KW_NULL = 1629,
     KW_TRUE = 1630,
     ALTER = 1632,
     CHECK = 1638,
     COUNT = 1642,
     KW_FIRST = 1647,
     KW_FLOAT = 1648,
     GRANT = 1651,
     INDEX = 1654,
     LESS_THAN = 1657,
     MONEY = 1659,
     MONTH = 1660,
     KW_MULTIPLY = 1662,
     ORDER = 1663,
     OUTER = 1664,
     UNION = 1673,
     WHERE = 1676,
     KW_BYTE = 1683,
     CASE = 1685,
     KW_DATE = 1687,
     DESC = 1688,
     KW_DIVIDE = 1689,
     DROP = 1692,
     ELSE = 1693,
     FROM = 1697,
     HOUR = 1703,
     INTO = 1704,
     LIKE = 1707,
     REAL = 1716,
     SOME = 1721,
     KW_TEXT = 1725,
     KW_THEN = 1726,
     USER = 1727,
     WHEN = 1729,
     YEAR = 1732,
     KW_DOW = 1733,
     XSET = 1735,
     ADD = 1736,
     ALL = 1737,
     KW_AND = 1738,
     ANY = 1739,
     ASC = 1740,
     AVG = 1741,
     COLON = 1742,
     KW_COMMA = 1743,
     DAY = 1744,
     DBA = 1745,
     KW_FOR = 1749,
     XMAX = 1754,
     XMIN = 1755,
     KW_MINUS = 1756,
     KW_MOD = 1757,
     KW_NOT = 1758,
     KW_SUM = 1765,
     ATSIGN = 1768,
     KW_PLUS = 1769,
     KW_AS = 1775,
     KW_BY = 1777,
     KW_DOT = 1778,
     KW_IN = 1781,
     KW_ON = 1783,
     KW_OR = 1784,
     KW_TO = 1785,
     BEFORE = 1823,
     END = 1827,
     TILDE = 1834,
     ILIKE = 1835,
     FILLFACTOR = 1838,
     TIME = 1843,
     KW_TODAY = 1850,
     KW_ROWID = 1851,
     TIMESTAMP = 2199,
     KW_TAG = 2220,
     LINTMODULEISLIBRARY = 2221,
     KW_PUBLIC = 2222,
     KW_PRIVATE = 2223,
     COPYBACK = 2224,
     REFERENCES_BLOBTYPE_DEFAULT_NULL = 2225,
     REFERENCES_BLOBTYPE = 2226,
     BEGIN = 2227
   };
#endif
/* Tokens.  */
#define INT_VALUE 2229
#define NAMED 2230
#define NAMED_GEN 2231
#define CHAR_VALUE 2232
#define NOT_USED_1 2233
#define NOT_USED_2 2234
#define NOT_USED_3 2235
#define NOT_USED_4 2236
#define NOT_USED_5 2237
#define NOT_USED_6 2238
#define NOT_USED_7 2239
#define NOT_USED_8 2240
#define NUMBER_VALUE 2241
#define SEMICOLON 2242
#define QUESTION_MARK 2243
#define CLINE 2244
#define CH 2245
#define MARK_VAR 2246
#define END_MARK_VAR 2247
#define WITH_LISTING_IN 1001
#define SET_CONSTRAINTS_ALL_DEFERRED 1002
#define DOCUMENT 1003
#define ON_EXCEPTION 1005
#define SET_DEBUG_FILE_TO 1006
#define CREATE_DBA_PROCEDURE 1011
#define CREATE_FUNCTION 1012
#define CREATE_DBA_FUNCTION 1013
#define USE_SESSION 1015
#define KW_RUN_CLIENT 1016
#define LEFT_JOIN 1018
#define IGNORE_ERRORS 1021
#define SQLERRMESSAGE 1022
#define DISPLAY_NULL_TO 1023
#define UNBUFFERED 1024
#define KW_PICTURE 1025
#define ON_CHANGE 1026
#define INNER_JOIN 1027
#define UI_INTERFACE_DOT_FRONTCALL 1030
#define UICOMBOBOX 1034
#define UIFORM 1037
#define USING_BTREE 1053
#define USING_RTREE 1054
#define SET_BUFFERED_LOG 1073
#define SET_LOG 1076
#define MDY 1078
#define WEEKDAY 1079
#define MODE_ANSI 1082
#define START_DATABASE 1083
#define WITH_LOG_IN 1084
#define SET_CONSTRAINTS_ALL_IMMEDIATE 1085
#define DATETIME_VALUE 1098
#define INTERVAL_VALUE 1099
#define RECOVER_TABLE 1100
#define ROLLFORWARD_DATABASE 1101
#define DROP_TRIGGER 1117
#define DROP_AUDIT_FOR 1118
#define CREATE_AUDIT_FOR 1119
#define EXECUTE_PROCEDURE 1123
#define ALTER_TABLE 1130
#define ALTER_INDEX 1131
#define NEXT_SIZE 1132
#define XSET_MULTIPLY_EQUAL_OPEN_BRACKET 1169
#define XSET_ident_DOT_MULTIPLY_EQUAL_OPEN_BRACKET 1170
#define XSET_ident_DOT_MULTIPLY_EQUAL 1171
#define XSET_MULTIPLY_EQUAL 1172
#define XSET_OPEN_BRACKET 1173
#define CREATE_DATABASE 1176
#define DROP_DATABASE 1177
#define ADD_CONSTRAINT 1179
#define DROP_CONSTRAINT 1180
#define DROP_SYNONYM 1181
#define CONSTRAINT 1182
#define NOT_FIELD_TOUCHED_CURRENT 1185
#define FIELD_TOUCHED_CURRENT 1186
#define DOUBLE_PRECISION 1193
#define COUNT_MULTIPLY 1194
#define MODIFY_NEXT_SIZE 1214
#define LOCK_MODE_PAGE 1215
#define LOCK_MODE_ROW 1216
#define UNITS_YEAR 1223
#define UNITS_MONTH 1224
#define UNITS_DAY 1225
#define UNITS_HOUR 1226
#define UNITS_MINUTE 1227
#define UNITS_SECOND 1228
#define TO_CLUSTER 1233
#define TO_NOT_CLUSTER 1234
#define CREATE_UC_IDX 1236
#define CREATE_U_IDX 1237
#define CREATE_C_IDX 1238
#define CREATE_IDX 1239
#define DOUBLE_COLON 1249
#define SQLSICS 1255
#define CREATE_SCHEMA 1256
#define SQLSIRR 1257
#define UPDATESTATS_T 1258
#define SQLSICR 1259
#define SQLSIDR 1270
#define CREATE_TEMP_TABLE 1271
#define WITH_CHECK_OPTION 1279
#define WITH_GRANT_OPTION 1280
#define SQLSLMNW 1281
#define WHERE_CURRENT_OF 1287
#define NOT_NULL_UNIQUE 1295
#define SQLSLMW 1302
#define ALL_PRIVILEGES 1304
#define CREATE_SYNONYM 1308
#define DROP_TABLE 1309
#define INEXCLUSIVE 1311
#define UPDATESTATS 1316
#define CREATE_TABLE 1342
#define DEFAULT_NULL 1343
#define DEFAULT_TODAY 1344
#define DEFAULT_USER 1345
#define UNLOCK_TABLE 1358
#define ROLLBACK_W 1366
#define SQLSEON 1368
#define SQLSEOFF 1369
#define CREATE_VIEW 1373
#define DELETE_FROM 1374
#define EXTENT_SIZE 1381
#define FOREIGN_KEY 1382
#define INSERT_INTO 1385
#define IS_NOT_NULL 1387
#define NOT_MATCHES 1390
#define PRIMARY_KEY 1396
#define WITH_NO_LOG 1403
#define INSHARE 1406
#define BEGIN_WORK 1412
#define DROP_INDEX 1417
#define FOR_UPDATE_OF 1423
#define FOR_UPDATE 1424
#define LOCK_TABLE 1429
#define NOT_EXISTS 1431
#define REFERENCES 1433
#define RENCOL 1434
#define SMALLFLOAT 1436
#define COMMIT_W 1447
#define RENTAB 1454
#define KW_CHAR 1457
#define NCHAR 1458
#define NVARCHAR 1459
#define DELIMITER 1461
#define DROP_VIEW 1463
#define EXCLUSIVE 1466
#define GREATER_THAN_EQ 1470
#define INTO_TEMP 1472
#define DATABASE 1496
#define DATETIME 1497
#define DISTINCT 1499
#define FRACTION 1506
#define GROUP_BY 1508
#define INTERVAL 1509
#define NOT_LIKE 1511
#define NOT_ILIKE 1512
#define NOT_NULL 1513
#define RESOURCE 1519
#define SMALLINT 1520
#define IS_NULL 1526
#define LESS_THAN_EQ 1527
#define BETWEEN 1529
#define CLOSE_BRACKET 1532
#define CONNECT 1535
#define KW_CURRENT 1536
#define KW_DECIMAL 1538
#define DEFAULT 1540
#define INTEGER 1548
#define SERIAL8 1550
#define MATCHES 1553
#define VARCHAR 1566
#define CLOSE_SQUARE 1569
#define GREATER_THAN 1570
#define KW_FALSE 1571
#define NOT_IN 1572
#define OPEN_BRACKET 1574
#define KW_DELETE 1582
#define KW_ESCAPE 1585
#define EXISTS 1586
#define EXTEND 1587
#define HAVING 1591
#define KW_INSERT 1593
#define MINUTE 1597
#define MODIFY 1598
#define EQUAL 1600
#define NOT_EQUAL 1601
#define OPEN_SQUARE 1603
#define PUBLIC 1607
#define REVOKE 1611
#define SECOND 1615
#define KW_SELECT 1619
#define SERIAL 1620
#define UNIQUE 1623
#define KW_UPDATE 1625
#define VALUES 1626
#define KW_NULL 1629
#define KW_TRUE 1630
#define ALTER 1632
#define CHECK 1638
#define COUNT 1642
#define KW_FIRST 1647
#define KW_FLOAT 1648
#define GRANT 1651
#define INDEX 1654
#define LESS_THAN 1657
#define MONEY 1659
#define MONTH 1660
#define KW_MULTIPLY 1662
#define ORDER 1663
#define OUTER 1664
#define UNION 1673
#define WHERE 1676
#define KW_BYTE 1683
#define CASE 1685
#define KW_DATE 1687
#define DESC 1688
#define KW_DIVIDE 1689
#define DROP 1692
#define ELSE 1693
#define FROM 1697
#define HOUR 1703
#define INTO 1704
#define LIKE 1707
#define REAL 1716
#define SOME 1721
#define KW_TEXT 1725
#define KW_THEN 1726
#define USER 1727
#define WHEN 1729
#define YEAR 1732
#define KW_DOW 1733
#define XSET 1735
#define ADD 1736
#define ALL 1737
#define KW_AND 1738
#define ANY 1739
#define ASC 1740
#define AVG 1741
#define COLON 1742
#define KW_COMMA 1743
#define DAY 1744
#define DBA 1745
#define KW_FOR 1749
#define XMAX 1754
#define XMIN 1755
#define KW_MINUS 1756
#define KW_MOD 1757
#define KW_NOT 1758
#define KW_SUM 1765
#define ATSIGN 1768
#define KW_PLUS 1769
#define KW_AS 1775
#define KW_BY 1777
#define KW_DOT 1778
#define KW_IN 1781
#define KW_ON 1783
#define KW_OR 1784
#define KW_TO 1785
#define BEFORE 1823
#define END 1827
#define TILDE 1834
#define ILIKE 1835
#define FILLFACTOR 1838
#define TIME 1843
#define KW_TODAY 1850
#define KW_ROWID 1851
#define TIMESTAMP 2199
#define KW_TAG 2220
#define LINTMODULEISLIBRARY 2221
#define KW_PUBLIC 2222
#define KW_PRIVATE 2223
#define COPYBACK 2224
#define REFERENCES_BLOBTYPE_DEFAULT_NULL 2225
#define REFERENCES_BLOBTYPE 2226
#define BEGIN 2227




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 214 of yacc.c  */
#line 119 "sql.yacc"

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
#line 812 "y.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 824 "y.tab.c"

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
#define YYLAST   2342

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  277
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  226
/* YYNRULES -- Number of rules.  */
#define YYNRULES  627
/* YYNRULES -- Number of states.  */
#define YYNSTATES  1115

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   2247

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
       2,    22,    23,    24,     2,    25,    26,     2,     2,     2,
       2,    27,    28,    29,     2,    30,    31,     2,    32,     2,
       2,    33,    34,    35,    36,    37,    38,    39,     2,     2,
      40,     2,     2,     2,    41,     2,     2,    42,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    43,    44,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    45,     2,     2,    46,     2,    47,    48,
       2,     2,    49,    50,    51,    52,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    53,    54,
      55,    56,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,    57,    58,    59,
       2,     2,     2,    60,     2,     2,     2,     2,     2,     2,
      61,    62,    63,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    64,
      65,    66,    67,    68,     2,     2,    69,    70,     2,    71,
      72,    73,    74,     2,     2,    75,    76,     2,     2,     2,
       2,     2,     2,    77,    78,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,    79,    80,    81,     2,     2,     2,
       2,     2,     2,    82,    83,    84,    85,    86,    87,     2,
       2,     2,     2,    88,    89,     2,    90,    91,    92,    93,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    94,
       2,     2,     2,     2,     2,    95,    96,    97,    98,    99,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     100,   101,     2,     2,     2,     2,     2,     2,     2,   102,
     103,   104,     2,     2,     2,     2,     2,   105,     2,     2,
       2,     2,     2,     2,     2,   106,     2,     2,     2,     2,
       2,     2,   107,     2,   108,     2,     2,     2,   109,   110,
       2,   111,     2,     2,     2,     2,   112,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,   113,   114,   115,   116,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,   117,     2,
       2,     2,     2,     2,     2,     2,   118,     2,   119,   120,
       2,     2,     2,   121,   122,     2,     2,     2,     2,     2,
       2,   123,   124,     2,     2,   125,     2,   126,     2,     2,
     127,     2,     2,     2,     2,     2,   128,     2,     2,     2,
       2,     2,     2,   129,     2,     2,   130,     2,     2,     2,
       2,     2,   131,     2,     2,     2,     2,   132,     2,     2,
       2,     2,     2,   133,   134,     2,     2,     2,     2,   135,
       2,   136,     2,   137,   138,     2,   139,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,   140,     2,     2,
       2,     2,     2,     2,   141,     2,     2,   142,   143,   144,
       2,   145,     2,   146,     2,     2,   147,     2,     2,     2,
     148,     2,   149,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,   150,   151,     2,   152,
       2,     2,     2,     2,     2,     2,   153,     2,   154,   155,
       2,   156,   157,   158,     2,     2,     2,     2,     2,   159,
     160,     2,     2,     2,     2,     2,   161,   162,     2,   163,
       2,     2,   164,     2,     2,   165,   166,     2,   167,     2,
     168,     2,     2,     2,     2,     2,     2,     2,   169,     2,
     170,     2,     2,   171,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,   172,     2,     2,   173,
     174,   175,   176,     2,   177,     2,     2,     2,     2,     2,
       2,     2,   178,     2,     2,   179,   180,   181,     2,     2,
       2,   182,     2,   183,     2,     2,     2,   184,   185,     2,
     186,   187,     2,   188,     2,     2,     2,   189,     2,     2,
       2,   190,     2,     2,     2,   191,     2,     2,     2,   192,
     193,     2,     2,   194,     2,   195,   196,     2,     2,   197,
     198,     2,   199,     2,     2,     2,     2,     2,   200,     2,
       2,     2,   201,     2,     2,     2,     2,   202,   203,     2,
       2,   204,     2,     2,   205,     2,     2,   206,     2,   207,
     208,     2,   209,   210,   211,     2,     2,     2,     2,     2,
       2,     2,     2,   212,     2,     2,   213,     2,     2,     2,
       2,     2,     2,   214,     2,   215,     2,   216,   217,   218,
       2,     2,   219,   220,     2,     2,     2,   221,     2,     2,
       2,     2,     2,   222,   223,     2,     2,   224,     2,     2,
       2,     2,     2,     2,     2,     2,   225,     2,     2,     2,
       2,   226,     2,     2,     2,   227,   228,   229,     2,   230,
       2,     2,   231,   232,     2,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,     2,     2,     2,   244,
       2,     2,     2,     2,   245,   246,   247,   248,   249,     2,
       2,     2,     2,     2,     2,   250,     2,     2,   251,   252,
       2,     2,     2,     2,     2,   253,     2,   254,   255,     2,
       2,   256,     2,   257,   258,   259,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   260,     2,     2,     2,   261,     2,     2,
       2,     2,     2,     2,   262,   263,     2,     2,   264,     2,
       2,     2,     2,   265,     2,     2,     2,     2,     2,     2,
     266,   267,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,   268,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     269,   270,   271,   272,   273,   274,   275,   276,     2,     3,
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
     483,     0,    -1,   195,   474,   281,   279,    -1,    -1,   105,
     478,    -1,   213,   390,    -1,    -1,   105,   478,    -1,   213,
     390,    -1,    68,   286,   164,   186,   177,   287,   164,    -1,
      64,   287,   164,    -1,    65,   287,   164,    -1,   233,   282,
      -1,    67,   287,    -1,    66,   287,    -1,   285,    -1,   282,
     241,   285,    -1,   284,    -1,   251,   284,    -1,   477,   416,
      -1,   477,   255,   477,   416,    -1,   477,   255,   477,   255,
     477,   416,    -1,   477,   255,   209,    -1,   283,   186,   288,
      -1,   283,    -1,   286,   241,   283,    -1,   288,    -1,   287,
     241,   288,    -1,   462,    -1,   197,    -1,   290,    -1,   110,
     474,    -1,   146,   474,    -1,   132,   476,    -1,    57,   477,
      -1,   301,    -1,   292,    -1,   113,   474,   177,   306,   164,
     293,    -1,   101,   474,   177,   306,   164,   302,   293,   302,
      -1,    -1,   294,    -1,   295,    -1,   294,   295,    -1,   256,
     296,    -1,   123,     3,    -1,    63,     3,    -1,    80,    -1,
      81,    -1,     4,    -1,    -1,   298,    -1,   299,    -1,   298,
     299,    -1,   256,   296,    -1,   264,     3,    -1,    43,    -1,
      44,    -1,   474,    -1,    91,   476,   257,   300,   177,   304,
     164,   297,    -1,    90,   476,   257,   300,   177,   304,   164,
     297,    -1,    92,   476,   257,   300,   177,   304,   164,   297,
      -1,    93,   476,   257,   300,   177,   304,   164,   297,    -1,
      69,   487,    -1,    70,   487,    -1,   109,   474,   244,   474,
      -1,    59,   474,   256,     6,    -1,    58,   474,    -1,    73,
     474,    -1,    55,   474,    -1,    56,   477,    -1,    -1,   129,
      -1,    -1,   129,    -1,   305,    -1,   304,   241,   305,    -1,
     477,   238,    -1,   477,   217,    -1,   477,    -1,   307,    -1,
     306,   241,   307,    -1,   370,    -1,   368,    -1,    61,   477,
     309,    -1,    62,   476,    88,    -1,    62,   476,    89,    -1,
     310,    -1,   309,   241,   310,    -1,   311,    -1,   314,    -1,
     317,    -1,   322,    -1,   325,    -1,   321,    -1,   320,    -1,
     234,   312,    -1,   234,   177,   313,   164,    -1,   307,    -1,
     307,   260,   477,    -1,   312,    -1,   313,   241,   312,    -1,
     219,   316,    -1,   219,   177,   315,   164,    -1,   316,    -1,
     315,   241,   316,    -1,   477,    -1,   185,   319,    -1,   185,
     177,   318,   164,    -1,   319,    -1,   318,   241,   319,    -1,
     307,    -1,    80,    -1,    81,    -1,    79,     3,    -1,    71,
     368,   324,    -1,    71,   177,   323,   164,    -1,   368,   324,
      -1,   323,   241,   368,   324,    -1,    -1,    74,   477,    -1,
      72,   326,    -1,    72,   177,   326,   164,    -1,   327,    -1,
     326,   241,   327,    -1,   477,    -1,   118,    -1,    -1,   125,
     330,   474,   333,   331,    -1,    -1,   196,   332,   177,   336,
     164,    -1,   456,    -1,    -1,   177,   334,   164,    -1,   335,
      -1,   334,   241,   335,    -1,   477,    -1,   477,   255,   477,
      -1,   337,    -1,   336,   241,   337,    -1,   462,    -1,   197,
      -1,   122,   474,   280,    -1,   131,    -1,   140,    -1,    -1,
     147,    -1,   343,    -1,    50,   477,    51,     6,    49,    -1,
      50,   477,    51,     6,    -1,    52,    -1,    45,    -1,    46,
      -1,    98,   477,    -1,   112,    -1,   340,    -1,   339,    -1,
     328,    -1,   342,    -1,   376,    -1,   380,    -1,   426,    -1,
     289,    -1,   291,    -1,   308,    -1,   204,   349,   257,   474,
     259,   354,   348,    -1,   190,   349,   257,   474,   221,   354,
      -1,   204,   347,   259,   354,    -1,   190,   347,   221,   354,
      -1,   165,    -1,   159,    -1,   243,    -1,    -1,   103,    -1,
     253,   415,    -1,   108,    -1,   235,    -1,   350,    -1,   351,
      -1,   350,   241,   351,    -1,   192,   352,    -1,   183,    -1,
     178,    -1,   195,   352,    -1,   199,    -1,   205,    -1,    -1,
     177,   353,   164,    -1,   417,    -1,   353,   241,   417,    -1,
     355,    -1,   354,   241,   355,    -1,   189,    -1,   415,    -1,
     121,   474,   357,   253,   447,   359,    -1,    -1,   177,   358,
     164,    -1,   417,    -1,   358,   241,   417,    -1,    -1,   102,
      -1,   200,   177,   446,   164,    -1,   124,   177,   363,   164,
     362,    -1,   137,   364,    -1,   365,    -1,   474,    -1,   474,
     177,   365,   164,    -1,   417,    -1,   365,   241,   417,    -1,
     194,   177,   367,   164,    -1,   152,   177,   367,   164,    -1,
     128,   177,   367,   164,    -1,   417,    -1,   367,   241,   417,
      -1,   366,    -1,   361,    -1,   360,    -1,   168,   422,    -1,
     116,    -1,   115,    -1,   114,    -1,   477,   406,   371,   372,
      -1,    -1,   369,    -1,    -1,   373,    -1,   374,    -1,   373,
     374,    -1,   375,   324,    -1,   158,    -1,   106,    -1,   194,
      -1,   152,    -1,   362,    -1,   200,   177,   446,   164,    -1,
     128,    -1,    96,   377,   379,    -1,   378,    -1,   415,    -1,
     380,    -1,   379,   380,    -1,   356,    -1,   346,    -1,   182,
     390,    -1,   213,   390,    -1,   221,   384,    -1,   386,    -1,
     384,   241,   386,    -1,   384,   241,   211,   386,    -1,   384,
     241,   211,   177,   384,   164,    -1,   384,    32,   385,   257,
     390,    -1,   384,    39,   385,   257,   390,    -1,   384,    -1,
     177,   384,   164,    -1,   474,    -1,   474,   421,    -1,   474,
     253,   421,    -1,    -1,   383,   388,    -1,   389,    -1,   382,
     389,    -1,    -1,   443,    -1,   443,   381,    -1,   381,    -1,
     391,    -1,   390,   258,   391,    -1,   392,    -1,   391,   236,
     392,    -1,   393,    -1,   249,   393,    -1,   403,    -1,   177,
     390,   164,    -1,   180,   457,    -1,   136,   457,    -1,    -1,
     179,   399,    -1,    -1,   179,   399,    -1,    -1,   179,   399,
      -1,   500,    -1,   422,    -1,    -1,   249,    -1,   462,   400,
     161,    -1,   462,   400,   126,    -1,   462,   402,   462,    -1,
     462,   186,   462,    -1,   462,   186,   197,    -1,   462,   400,
     163,   462,   236,   462,    -1,   462,   224,   398,   397,    -1,
     462,   156,   398,   397,    -1,   462,   263,   398,   396,    -1,
     462,   157,   398,   396,    -1,   462,   171,   398,   395,    -1,
     462,   127,   398,   395,    -1,   187,    -1,   206,    -1,   174,
      -1,   262,    -1,   162,    -1,   148,    -1,   401,    -1,   469,
      -1,   394,    -1,   462,    -1,    -1,   235,    -1,   152,    -1,
     194,    -1,    -1,   235,    -1,   152,    -1,   194,    -1,   407,
      -1,   408,    -1,   409,    -1,   411,    -1,   142,    -1,   142,
     177,   412,   164,    -1,   193,    -1,   193,   177,     3,   164,
      -1,   170,    -1,   170,   177,     3,   164,    -1,   167,    -1,
     167,   177,   413,   410,   164,    -1,   207,   177,   413,   410,
     164,    -1,   207,    -1,   216,    -1,   169,    -1,   160,    -1,
     143,    -1,   143,   177,   412,   164,    -1,   144,    -1,   144,
     177,     3,   164,    -1,   144,   177,     3,   241,     3,   164,
      -1,   151,   424,   259,   425,    -1,   151,    -1,   155,   424,
     259,   425,    -1,   448,    -1,   155,    -1,   155,   424,   177,
       3,   164,   259,   425,    -1,   227,    -1,   214,    -1,   172,
      -1,   172,   177,     3,   164,    -1,   172,   177,     3,   241,
       3,   164,    -1,    -1,   241,   414,    -1,   203,   177,   413,
     164,    -1,   225,    -1,   139,    -1,   203,    -1,    77,    -1,
       3,    -1,     3,    -1,     3,    -1,   477,    -1,     6,    -1,
      -1,   188,     3,   173,    -1,   188,     3,   241,     3,   173,
      -1,   420,    -1,   251,   420,    -1,   419,    -1,   251,   419,
      -1,   477,   416,    -1,   472,   255,   477,   416,    -1,   472,
     255,   209,    -1,   267,    -1,   477,   416,    -1,   472,   255,
     477,   416,    -1,   477,   255,   477,   255,   477,   416,    -1,
     472,   255,   209,    -1,   477,    -1,     6,    -1,   479,    -1,
       3,    -1,   437,    -1,    -1,   424,   259,   425,    -1,   231,
      -1,   208,    -1,   242,    -1,   222,    -1,   184,    -1,   191,
      -1,   153,    -1,   231,    -1,   208,    -1,   242,    -1,   222,
      -1,   184,    -1,   191,    -1,   153,    -1,   153,   177,     3,
     164,    -1,   431,    -1,   430,    -1,   427,    -1,   141,   428,
     259,   428,    -1,   138,   472,   255,   429,   259,   429,    -1,
     477,    -1,   477,    -1,   117,   474,    -1,   135,   474,   432,
      -1,   130,    -1,   111,    -1,   434,    -1,   434,   424,   259,
     425,    -1,    53,    -1,   436,    -1,   436,   424,   177,     3,
     164,   259,   425,    -1,   436,   424,   259,   425,    -1,    54,
      -1,   166,   423,    -1,   210,   254,   439,    -1,   440,    -1,
     439,   241,   440,    -1,   441,   442,    -1,     3,    -1,   418,
      -1,    -1,   238,    -1,   217,    -1,   154,   444,    -1,   445,
      -1,   444,   241,   445,    -1,   418,    -1,     3,    -1,   390,
      -1,   456,    -1,   265,    -1,   265,   177,     3,   164,    -1,
     268,    -1,   268,   177,     3,   164,    -1,    -1,    -1,   192,
     458,   459,   450,   460,   451,   481,   387,   453,   454,    -1,
     192,   458,   459,   460,   387,   453,    -1,    -1,   212,   405,
     452,    -1,    -1,   438,    -1,   438,   149,   455,   303,    -1,
     149,   455,   303,    -1,   477,    -1,   192,   458,   459,   460,
     387,    -1,   177,   192,   458,   459,   460,   387,   164,    -1,
      -1,   202,     3,    -1,    -1,   235,    -1,   152,    -1,   194,
      -1,   461,    -1,   460,   241,   461,    -1,   462,    -1,   462,
     477,    -1,   462,   253,   477,    -1,   500,    -1,   247,   500,
      -1,   252,   500,    -1,   500,   218,   462,    -1,   500,   468,
      -1,   500,   209,   462,    -1,   500,   252,   462,    -1,   500,
     247,   462,    -1,   422,    -1,   198,    -1,   175,    -1,   229,
      -1,   266,    -1,   267,    -1,   265,    -1,   209,    -1,    78,
      -1,   239,   177,   404,   462,   164,    -1,   245,   177,   404,
     462,   164,    -1,   246,   177,   404,   462,   164,    -1,   250,
     177,   404,   462,   164,    -1,   201,   177,   404,   462,   164,
      -1,     4,   177,   164,    -1,     4,   177,   466,   164,    -1,
     231,   177,   466,   164,    -1,   208,   177,   466,   164,    -1,
     242,   177,   466,   164,    -1,    47,   177,   466,   164,    -1,
      48,   177,   466,   164,    -1,   232,   177,   466,   164,    -1,
     216,   177,   466,   164,    -1,   177,   462,   164,    -1,   181,
     177,   467,   164,    -1,   433,    -1,   435,    -1,   215,   464,
     261,    -1,   465,    -1,   464,   465,    -1,   230,   390,   228,
     462,    -1,   220,   462,    -1,   462,    -1,   466,   241,   462,
      -1,   166,   241,   424,   259,   425,    -1,   493,   241,   424,
     259,   425,    -1,   166,   424,   259,   425,    -1,   462,   241,
     424,   259,   425,    -1,    82,    -1,    83,    -1,    84,    -1,
      85,    -1,    86,    -1,    87,    -1,   462,   256,   177,   470,
     164,    -1,   462,   256,   457,    -1,   462,   176,   177,   470,
     164,    -1,   462,   176,   457,    -1,   471,    -1,   470,   241,
     471,    -1,   493,    -1,   422,    -1,   247,     3,    -1,   247,
     479,    -1,   473,    -1,     6,    -1,     6,   255,   477,    -1,
     477,    -1,   477,   240,   477,    -1,   477,   240,     6,   255,
     477,    -1,   477,   251,   477,    -1,   477,   251,   477,   240,
     477,    -1,   477,   251,   477,   240,     6,   255,   477,    -1,
     475,    -1,     6,   255,   477,    -1,   477,   255,   477,    -1,
       6,    -1,   477,    -1,   477,   240,   477,    -1,   477,   240,
       6,   255,   477,    -1,   477,   251,   477,    -1,   477,   251,
     477,   240,   477,    -1,   477,   251,   477,   240,     6,   255,
     477,    -1,     6,   255,   477,    -1,     6,    -1,   477,    -1,
     477,   240,   477,    -1,   477,   240,     6,   255,   477,    -1,
     477,   251,   477,    -1,   477,   251,   477,   240,   477,    -1,
     477,   251,   477,   240,     6,   255,   477,    -1,     4,    -1,
       4,    -1,    15,    -1,   255,     3,    -1,     4,    -1,     6,
      -1,    -1,   477,    -1,   485,    -1,   483,    16,   485,    -1,
     329,    -1,   278,    -1,   338,    -1,    -1,   494,    -1,   345,
      -1,   486,    -1,   492,    -1,   484,    -1,   344,    -1,     1,
      -1,   488,   489,    -1,   482,    -1,   449,    -1,    -1,   134,
      -1,   133,   490,    -1,   491,    -1,   490,   241,   491,    -1,
     477,    -1,   477,   255,   477,    -1,     6,   255,   477,   255,
     477,    -1,   120,    -1,   119,    -1,   107,   502,    -1,   104,
      -1,   100,    -1,    97,    -1,    95,    -1,    99,    -1,   499,
      -1,    17,    -1,   495,    -1,   150,   480,   341,    -1,    20,
       6,    21,    -1,   177,   496,   164,    -1,   496,   497,   496,
      -1,     3,    -1,   498,     3,    -1,   252,    -1,   247,    -1,
     209,    -1,   218,    -1,   248,    -1,   252,    -1,   247,    -1,
     477,    -1,   477,   255,   209,    -1,   477,   255,   267,    -1,
     477,   255,   477,    -1,   477,   255,   477,   255,   477,    -1,
       6,   255,   477,   255,   477,    -1,   477,   188,   496,   173,
      -1,   477,   255,   477,   188,   496,   173,    -1,   477,   255,
     477,   255,   477,   188,   496,   173,    -1,     6,   255,   477,
     255,   477,   188,   496,   173,    -1,   477,   188,   496,   241,
     496,   173,    -1,   477,   255,   477,   188,   496,   241,   496,
     173,    -1,   477,   255,   477,   255,   477,   188,   496,   241,
     496,   173,    -1,     6,   255,   477,   255,   477,   188,   496,
     241,   496,   173,    -1,   501,    -1,   501,    94,   406,    -1,
     463,    -1,   493,    -1,   457,    -1,   235,   457,    -1,   237,
     457,    -1,   226,   457,    -1,    -1,     3,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   426,   426,   452,   455,   472,   477,   480,   497,   503,
     512,   521,   530,   537,   552,   607,   614,   625,   628,   633,
     640,   657,   674,   695,   704,   707,   715,   718,   726,   727,
     734,   737,   745,   748,   752,   758,   759,   763,   773,   787,
     788,   792,   793,   798,   806,   814,   822,   830,   840,   842,
     842,   845,   846,   850,   857,   864,   871,   880,   884,   891,
     903,   914,   920,   924,   928,   933,   937,   940,   944,   947,
     954,   955,   965,   966,   970,   971,   975,   984,   993,  1000,
    1003,  1009,  1012,  1023,  1027,  1032,  1039,  1042,  1051,  1054,
    1058,  1062,  1066,  1070,  1074,  1082,  1086,  1094,  1097,  1104,
    1107,  1114,  1117,  1124,  1125,  1130,  1134,  1137,  1143,  1146,
    1152,  1159,  1160,  1164,  1172,  1176,  1183,  1185,  1190,  1191,
    1195,  1197,  1203,  1204,  1207,  1218,  1224,  1224,  1233,  1233,
    1242,  1267,  1270,  1278,  1281,  1288,  1291,  1299,  1300,  1306,
    1307,  1315,  1333,  1337,  1342,  1343,  1353,  1362,  1366,  1370,
    1375,  1379,  1383,  1386,  1393,  1394,  1395,  1399,  1400,  1401,
    1402,  1403,  1404,  1405,  1413,  1414,  1415,  1416,  1421,  1422,
    1423,  1426,  1427,  1428,  1432,  1433,  1434,  1438,  1439,  1443,
    1450,  1451,  1452,  1459,  1460,  1463,  1464,  1469,  1470,  1475,
    1476,  1481,  1482,  1487,  1494,  1495,  1500,  1501,  1505,  1506,
    1513,  1521,  1528,  1535,  1539,  1540,  1545,  1546,  1552,  1556,
    1561,  1568,  1569,  1575,  1578,  1581,  1588,  1589,  1590,  1591,
    1597,  1618,  1619,  1622,  1624,  1631,  1634,  1640,  1648,  1653,
    1659,  1664,  1670,  1673,  1678,  1686,  1695,  1700,  1704,  1705,
    1711,  1714,  1725,  1734,  1741,  1747,  1748,  1751,  1756,  1767,
    1771,  1778,  1779,  1783,  1787,  1791,  1798,  1803,  1811,  1814,
    1820,  1823,  1828,  1833,  1846,  1849,  1855,  1858,  1864,  1867,
    1873,  1876,  1883,  1887,  1898,  1898,  1899,  1899,  1900,  1900,
    1903,  1908,  1913,  1914,  1919,  1928,  1936,  1939,  1942,  1946,
    1953,  1956,  1960,  1963,  1966,  1969,  1975,  1982,  1985,  1988,
    1991,  1992,  1997,  2000,  2003,  2006,  2013,  2014,  2015,  2019,
    2026,  2027,  2028,  2032,  2046,  2053,  2054,  2055,  2059,  2060,
    2065,  2066,  2075,  2077,  2086,  2089,  2097,  2107,  2115,  2117,
    2118,  2119,  2120,  2121,  2122,  2123,  2131,  2132,  2133,  2134,
    2135,  2136,  2137,  2138,  2139,  2140,  2141,  2151,  2152,  2158,
    2160,  2161,  2162,  2163,  2167,  2171,  2175,  2182,  2183,  2188,
    2189,  2193,  2201,  2204,  2211,  2214,  2224,  2227,  2230,  2233,
    2240,  2247,  2255,  2264,  2271,  2275,  2276,  2277,  2278,  2283,
    2285,  2294,  2294,  2294,  2294,  2294,  2294,  2294,  2295,  2295,
    2295,  2295,  2295,  2295,  2295,  2295,  2340,  2341,  2342,  2347,
    2348,  2351,  2352,  2356,  2363,  2374,  2375,  2388,  2389,  2393,
    2397,  2398,  2401,  2407,  2411,  2434,  2444,  2447,  2453,  2462,
    2466,  2473,  2474,  2476,  2481,  2487,  2490,  2496,  2497,  2504,
    2517,  2527,  2534,  2551,  2558,  2583,  2585,  2583,  2607,  2651,
    2652,  2666,  2669,  2676,  2686,  2698,  2704,  2717,  2732,  2734,
    2740,  2741,  2742,  2743,  2753,  2756,  2762,  2765,  2770,  2779,
    2782,  2786,  2793,  2796,  2799,  2802,  2805,  2808,  2809,  2810,
    2811,  2812,  2813,  2814,  2815,  2816,  2818,  2822,  2826,  2830,
    2834,  2838,  2842,  2846,  2849,  2852,  2855,  2858,  2861,  2864,
    2867,  2870,  2874,  2878,  2882,  2890,  2893,  2902,  2908,  2915,
    2918,  2946,  2949,  2952,  2955,  2961,  2962,  2963,  2964,  2965,
    2966,  2971,  2975,  2979,  2983,  2990,  2993,  2998,  2999,  3000,
    3002,  3008,  3018,  3022,  3026,  3030,  3034,  3038,  3042,  3046,
    3054,  3064,  3069,  3073,  3077,  3081,  3085,  3090,  3094,  3098,
    3106,  3109,  3114,  3115,  3116,  3121,  3122,  3123,  3131,  3134,
    3139,  3140,  3144,  3145,  3150,  3174,  3191,  3192,  3196,  3203,
    3209,  3219,  3221,  3224,  3225,  3226,  3227,  3229,  3232,  3236,
    3241,  3245,  3251,  3252,  3255,  3260,  3261,  3264,  3265,  3266,
    3276,  3277,  3278,  3279,  3280,  3281,  3282,  3283,  3287,  3293,
    3295,  3314,  3322,  3329,  3330,  3331,  3332,  3337,  3338,  3339,
    3340,  3341,  3346,  3347,  3363,  3364,  3365,  3366,  3367,  3368,
    3369,  3370,  3371,  3372,  3374,  3375,  3376,  3377,  3382,  3385,
    3394,  3395,  3396,  3397,  3398,  3399,  3403,  3404
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
  "WITH_LISTING_IN", "SET_CONSTRAINTS_ALL_DEFERRED", "DOCUMENT",
  "ON_EXCEPTION", "SET_DEBUG_FILE_TO", "CREATE_DBA_PROCEDURE",
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
  "REFERENCES_BLOBTYPE_DEFAULT_NULL", "REFERENCES_BLOBTYPE", "BEGIN",
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
       0,   256,  2228,  2229,  2230,  2231,  2232,  2233,  2234,  2235,
    2236,  2237,  2238,  2239,  2240,  2241,  2242,  2243,  2244,  2245,
    2246,  2247,  1001,  1002,  1003,  1005,  1006,  1011,  1012,  1013,
    1015,  1016,  1018,  1021,  1022,  1023,  1024,  1025,  1026,  1027,
    1030,  1034,  1037,  1053,  1054,  1073,  1076,  1078,  1079,  1082,
    1083,  1084,  1085,  1098,  1099,  1100,  1101,  1117,  1118,  1119,
    1123,  1130,  1131,  1132,  1169,  1170,  1171,  1172,  1173,  1176,
    1177,  1179,  1180,  1181,  1182,  1185,  1186,  1193,  1194,  1214,
    1215,  1216,  1223,  1224,  1225,  1226,  1227,  1228,  1233,  1234,
    1236,  1237,  1238,  1239,  1249,  1255,  1256,  1257,  1258,  1259,
    1270,  1271,  1279,  1280,  1281,  1287,  1295,  1302,  1304,  1308,
    1309,  1311,  1316,  1342,  1343,  1344,  1345,  1358,  1366,  1368,
    1369,  1373,  1374,  1381,  1382,  1385,  1387,  1390,  1396,  1403,
    1406,  1412,  1417,  1423,  1424,  1429,  1431,  1433,  1434,  1436,
    1447,  1454,  1457,  1458,  1459,  1461,  1463,  1466,  1470,  1472,
    1496,  1497,  1499,  1506,  1508,  1509,  1511,  1512,  1513,  1519,
    1520,  1526,  1527,  1529,  1532,  1535,  1536,  1538,  1540,  1548,
    1550,  1553,  1566,  1569,  1570,  1571,  1572,  1574,  1582,  1585,
    1586,  1587,  1591,  1593,  1597,  1598,  1600,  1601,  1603,  1607,
    1611,  1615,  1619,  1620,  1623,  1625,  1626,  1629,  1630,  1632,
    1638,  1642,  1647,  1648,  1651,  1654,  1657,  1659,  1660,  1662,
    1663,  1664,  1673,  1676,  1683,  1685,  1687,  1688,  1689,  1692,
    1693,  1697,  1703,  1704,  1707,  1716,  1721,  1725,  1726,  1727,
    1729,  1732,  1733,  1735,  1736,  1737,  1738,  1739,  1740,  1741,
    1742,  1743,  1744,  1745,  1749,  1754,  1755,  1756,  1757,  1758,
    1765,  1768,  1769,  1775,  1777,  1778,  1781,  1783,  1784,  1785,
    1823,  1827,  1834,  1835,  1838,  1843,  1850,  1851,  2199,  2220,
    2221,  2222,  2223,  2224,  2225,  2226,  2227
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint16 yyr1[] =
{
       0,   277,   278,   279,   279,   279,   280,   280,   280,   281,
     281,   281,   281,   281,   281,   282,   282,   283,   283,   284,
     284,   284,   284,   285,   286,   286,   287,   287,   288,   288,
     289,   290,   290,   290,   290,   291,   291,   292,   292,   293,
     293,   294,   294,   295,   295,   295,   295,   295,   296,   297,
     297,   298,   298,   299,   299,   299,   299,   300,   301,   301,
     301,   301,   301,   301,   301,   301,   301,   301,   301,   301,
     302,   302,   303,   303,   304,   304,   305,   305,   305,   306,
     306,   307,   307,   308,   308,   308,   309,   309,   310,   310,
     310,   310,   310,   310,   310,   311,   311,   312,   312,   313,
     313,   314,   314,   315,   315,   316,   317,   317,   318,   318,
     319,   320,   320,   321,   322,   322,   323,   323,   324,   324,
     325,   325,   326,   326,   327,   328,   330,   329,   332,   331,
     331,   333,   333,   334,   334,   335,   335,   336,   336,   337,
     337,   338,   339,   340,   341,   341,   342,   343,   343,   343,
     343,   343,   343,   343,   344,   344,   344,   345,   345,   345,
     345,   345,   345,   345,   346,   346,   346,   346,   347,   347,
     347,   348,   348,   348,   349,   349,   349,   350,   350,   351,
     351,   351,   351,   351,   351,   352,   352,   353,   353,   354,
     354,   355,   355,   356,   357,   357,   358,   358,   359,   359,
     360,   361,   362,   363,   364,   364,   365,   365,   366,   366,
     366,   367,   367,   368,   368,   368,   369,   369,   369,   369,
     370,   371,   371,   372,   372,   373,   373,   374,   375,   375,
     375,   375,   375,   375,   375,   376,   377,   378,   379,   379,
     380,   380,   381,   382,   383,   384,   384,   384,   384,   384,
     384,   385,   385,   386,   386,   386,   387,   387,   388,   388,
     389,   389,   389,   389,   390,   390,   391,   391,   392,   392,
     393,   393,   394,   394,   395,   395,   396,   396,   397,   397,
     398,   399,   400,   400,   401,   401,   401,   401,   401,   401,
     401,   401,   401,   401,   401,   401,   402,   402,   402,   402,
     402,   402,   403,   403,   403,   403,   404,   404,   404,   404,
     405,   405,   405,   405,   406,   407,   407,   407,   408,   408,
     409,   409,   409,   409,   409,   409,   409,   409,   409,   409,
     409,   409,   409,   409,   409,   409,   409,   409,   409,   409,
     409,   409,   409,   409,   409,   409,   409,   410,   410,   411,
     411,   411,   411,   411,   412,   413,   414,   415,   415,   416,
     416,   416,   417,   417,   418,   418,   419,   419,   419,   419,
     420,   420,   420,   420,   421,   422,   422,   422,   422,   423,
     423,   424,   424,   424,   424,   424,   424,   424,   425,   425,
     425,   425,   425,   425,   425,   425,   426,   426,   426,   427,
     427,   428,   429,   430,   431,   432,   432,   433,   433,   434,
     435,   435,   435,   436,   437,   438,   439,   439,   440,   441,
     441,   442,   442,   442,   443,   444,   444,   445,   445,   446,
     447,   448,   448,   448,   448,   450,   451,   449,   452,   453,
     453,   454,   454,   454,   454,   455,   456,   457,   458,   458,
     459,   459,   459,   459,   460,   460,   461,   461,   461,   462,
     462,   462,   463,   463,   463,   463,   463,   463,   463,   463,
     463,   463,   463,   463,   463,   463,   463,   463,   463,   463,
     463,   463,   463,   463,   463,   463,   463,   463,   463,   463,
     463,   463,   463,   463,   463,   464,   464,   465,   465,   466,
     466,   467,   467,   467,   467,   468,   468,   468,   468,   468,
     468,   469,   469,   469,   469,   470,   470,   471,   471,   471,
     471,   472,   473,   473,   473,   473,   473,   473,   473,   473,
     474,   475,   475,   475,   475,   475,   475,   475,   475,   475,
     476,   476,   476,   476,   476,   476,   476,   476,   477,   478,
     479,   479,   480,   480,   481,   482,   483,   483,   484,   484,
     484,   485,   485,   485,   485,   485,   485,   485,   485,   486,
     487,   488,   489,   489,   489,   490,   490,   491,   491,   491,
     492,   492,   492,   492,   492,   492,   492,   492,   493,   493,
     493,   494,   495,   496,   496,   496,   496,   497,   497,   497,
     497,   497,   498,   498,   499,   499,   499,   499,   499,   499,
     499,   499,   499,   499,   499,   499,   499,   499,   500,   500,
     501,   501,   501,   501,   501,   501,   502,   502
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
#define YYPACT_NINF -929
static const yytype_int16 yypact[] =
{
    2083,  -929,  -929,  -929,   135,  -929,   678,   135,   135,   678,
     678,   135,   712,   135,   135,   678,   712,   712,   712,   712,
    -929,   741,  -929,   135,  -929,  -929,   678,  -929,    93,   678,
     678,  -929,   678,   678,  -929,  -929,  -929,   678,   678,  -929,
    -929,   712,   678,   781,  -929,   135,   678,   789,   522,   -40,
     678,   522,  -929,  -929,  -929,  -929,  -929,  -929,  -929,  -929,
    -929,  -929,  -929,  -929,  -929,  -929,  -929,  -929,  -929,  -929,
    -929,  -929,  -929,  -929,  -929,  -929,  -929,   456,  -929,  -929,
    -929,   515,  -929,  -929,  -929,   125,   -47,  -929,  -929,   411,
    -929,  -929,  -929,   -20,   289,    -8,   601,   286,  -929,  -929,
    -929,  -929,  -929,    21,    36,    45,   130,  -929,    26,  -929,
    -929,  -929,  -929,   138,  -929,  -929,   109,  -929,   251,  -929,
     254,     5,   678,  -929,   313,   208,   223,  -929,   413,   226,
    -929,  -929,  -929,  -929,   347,  -929,  -929,  -929,  -929,  -929,
     320,   320,  -929,  -929,  -929,  -929,   304,   291,   322,  -929,
     563,    13,   133,   321,   329,  -929,  2083,   792,  -929,  -929,
     598,   135,   806,   135,   135,   603,   555,    84,   610,  -929,
    -929,   287,    97,   290,   396,  -929,  -929,  -929,  -929,  -929,
    -929,  -929,  -929,   135,  -929,  -929,   811,   135,   678,   678,
     678,   678,    26,  -929,   341,   678,   341,   100,   405,   667,
     984,  -929,   492,  -929,  -929,  -929,   135,   135,   843,   135,
     135,  -929,  -929,   100,  -929,  -929,   150,   678,   619,  -929,
    -929,  -929,  -929,  -929,  1205,  1205,  1205,  1205,    68,    68,
      10,   150,   678,  -929,   430,   438,   455,  -929,   659,  -929,
     467,  -929,   471,  -929,  -929,   549,   557,   561,   609,   571,
     575,  -929,  -929,  -929,   682,   135,   518,  -929,  -929,  -929,
     341,  -929,  -929,  -929,  -929,   485,   135,  -929,  -929,   341,
     511,  -929,   289,  -929,   520,  -929,   538,   611,  -929,   629,
     630,   639,  -929,   -12,  -929,  -929,    31,   781,    47,  -929,
    -929,   568,   458,   648,  -929,  -929,  -929,   669,   595,  -929,
    -929,   848,   681,   688,  -929,  -929,  -929,   692,    96,  -929,
     931,   692,   693,  -929,   696,   699,  -929,    34,   705,   692,
    -929,   706,   707,   692,   692,   708,   710,   711,   714,  1881,
    1101,   715,  1881,   890,  -929,  -929,  -929,   636,   660,  -929,
    -929,  -929,  -929,  -929,  -929,  -929,    96,  -929,    96,  -929,
    -929,   665,  -929,  -929,     0,  -929,  -929,  -929,  -929,   416,
     801,   135,   283,  -929,   638,  -929,   643,  -929,   661,  -929,
      56,  -929,  -929,   662,  -929,  -929,   684,  -929,  1711,  1322,
    -929,    71,  -929,  -929,    99,   666,   666,   135,  -929,  -929,
     106,    44,   668,   716,  -929,   667,   984,  -929,   662,   649,
     135,   135,   792,  -929,   135,   855,   100,   100,   100,   118,
     682,   100,   984,   135,  -929,   134,   135,   139,  -929,  -929,
    -929,   733,   734,   735,    96,    96,  -929,   736,  -929,   738,
     739,   740,   742,   743,  -929,  -929,  -929,  -929,   745,   746,
     560,  -929,  -929,  -929,  -929,  -929,   179,  -929,  -929,   188,
     135,  -929,   135,   858,   135,   135,   135,   135,   795,   341,
      92,  -929,  -929,   100,    62,   922,   135,  -929,   -40,   827,
    -929,  1375,   135,   909,  1711,  1711,   744,  -929,  -929,  -929,
    -929,  -929,  -929,  -929,  -929,  -929,   672,   -40,   -48,  2079,
    -929,  1764,    23,  1711,  1711,   984,   193,  -929,  1711,  -929,
    1711,  1711,  -929,  -929,    23,  1711,    23,    23,   416,  -929,
      23,   416,  -929,   984,   984,   673,   -33,  1881,  -929,  1881,
    1881,  -929,  1881,  -929,   756,  1458,  -929,  -929,  1881,  -929,
     761,  -929,  1881,   273,  1711,    54,    59,  -929,  -929,  -929,
    -929,  -929,  -929,  1711,  1711,  1711,  1711,  -929,   485,   199,
    -929,   685,  -929,  -929,  -929,   135,   135,   862,  -929,   100,
     150,   150,   698,  -929,    57,   777,  -929,  1205,  -929,  -929,
     757,    68,    76,  -929,    68,  1205,  -929,   636,   150,   687,
    -929,  -929,  -929,   689,  -929,   783,   704,  -929,   220,  -929,
     242,  -929,   609,  -929,   280,   636,   785,  -929,  -929,  -929,
    -929,   341,   947,   947,   949,   694,    -7,   951,   952,   954,
     956,   951,   951,   957,   958,  -929,  -929,  -929,    87,  -929,
     227,  -929,   135,  -929,   341,  -929,  -929,   709,  -929,   293,
    -929,   395,   302,   324,   340,  -929,    92,  -929,   959,  -929,
    -929,   960,   961,  -929,    92,  -929,  -929,  -929,   778,   -22,
     717,    13,  -929,  -929,  -929,  -929,   343,   719,  -929,   353,
     360,   380,    13,  -929,  -929,   305,   726,   807,   729,  -929,
    -929,  -929,  1711,   364,  -929,   107,  -929,  -929,   365,   366,
     390,  1711,   394,  1711,  1711,  1711,   660,  -929,   380,   972,
     380,   797,   416,   798,   802,   797,    94,  -929,  -929,  -929,
     798,    94,  -929,   802,  -929,  -929,  1711,  -929,  -929,    54,
    -929,  -929,   264,   977,  -929,  -929,   117,  -929,  -929,  -929,
    -929,  -929,  -929,   135,   135,   805,  -929,  -929,   728,  -929,
    -929,  -929,   662,  1711,  -929,   135,  -929,  -929,   809,  -929,
    -929,   170,  -929,  -929,    16,   135,   135,   852,   100,  -929,
     100,  -929,   682,  -929,  -929,  -929,  -929,   829,   830,   397,
     380,   988,   380,  -929,   759,   833,   415,   834,   838,   759,
     839,   841,  -929,  -929,  -929,  -929,   678,  -929,  -929,  -929,
     831,  -929,  -929,   227,  -929,   682,  -929,  -929,   135,    64,
     135,  -929,  -929,    64,    64,    64,   795,  -929,  -929,  -929,
    -929,  -929,  -929,  -929,  1003,   135,  1711,  -929,  1711,   135,
    -929,  -929,   835,  -929,  -929,  -929,  -929,  -929,  -929,  -929,
    1711,    96,   748,    96,  -929,    96,   846,  -929,  1711,  -929,
    -929,  -929,   847,  -929,   849,   850,   851,  -929,   853,  -929,
      87,  -929,    87,  -929,    87,  -929,  -929,    74,  -929,   418,
    -929,  -929,  -929,   419,  -929,   780,   262,  -929,  -929,  -929,
      54,  -929,  -929,  -929,    54,  -929,    54,   135,  -929,  -929,
    1628,   135,  -929,   799,  -929,  1205,   135,  -929,  -929,   741,
    -929,  -929,  -929,  -929,  -929,  -929,  -929,  -929,  -929,  -929,
    1015,  -929,   857,  -929,  1016,   864,  -929,  -929,  1019,  -929,
    -929,   865,  -929,  -929,  -929,   856,   984,  -929,  -929,  -929,
    -929,  -929,   961,  1032,  -929,    64,  -929,  -929,  -929,  -929,
    -929,  -929,   863,   778,   -60,  -929,   854,  1036,   -60,   782,
     380,   784,   786,  -929,  -929,  -929,  -929,  -929,  -929,   790,
    -929,  -929,  -929,  -929,  -929,  -929,  -929,   126,  -929,  1711,
    -929,   477,   590,   297,   860,  -929,   426,  -929,  -929,  -929,
     678,   337,   828,   429,   778,  -929,   880,   791,  -929,  -929,
    -929,   887,  -929,   100,   888,  -929,  -929,  -929,  -929,  -929,
    -929,    54,   889,   891,   380,   892,   380,   380,   380,  -929,
    -929,  -929,  -929,    54,    54,  -929,  1628,    73,  -929,    58,
      65,   984,   984,  -929,   256,  -929,  -929,   872,    82,    40,
    -929,  -929,  -929,   380,  -929,   431,  -929,   367,  -929,  -929,
    -929,  -929,  -929,  -929,   488,   369,  -929,   119,   119,   120,
     135,  -929,  -929,  -929,    79,  -929,  -929,  -929,   817,  -929,
     804,   503,   636,   636,  -929,  -929,  -929,  -929,  -929,   868,
     135,   810,   919,  -929,  -929,  -929,  -929,    54,  -929,  -929,
      54,   678,    73,   812,   813,   190,  -929,  -929,  -929,    65,
      80,  -929,   -40,  -929,   942,  -929,    70,   135,   521,   542,
      95,   984,   984,   678,  -929,  -929,  -929,   778,    13,  -929,
    -929,  -929,  -929,   836,  -929,   409,   942,  -929,  -929,  -929,
     636,   636,   103,  -929,  1711,    70,  -929,  -929,  -929,  -929,
    -929,   -60,  -929,   828,  -929
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -929,  -929,  -929,  -929,  -929,  -929,  -177,   691,   500,  -929,
    -195,   -36,  -929,  -929,  -929,  -929,   439,  -929,   432,   168,
     -91,  -929,   166,   573,  -929,   288,   -14,   388,   295,   893,
    -129,  -929,  -929,   814,  -929,  -219,  -929,  -929,  -929,  -246,
    -929,  -929,  -208,  -929,  -929,  -929,  -929,  -363,  -929,   832,
     674,  -929,  -929,  -929,  -929,  -929,  -929,  -929,   368,  -929,
     102,  -929,  -929,  -929,  -929,  -929,  -929,  -929,  -929,  -929,
    1037,  -929,  1041,  -929,   875,   955,  -929,  -183,   523,  -929,
    -929,  -929,  -929,  -929,  -929,   348,  -929,  -929,   127,  -929,
       8,  -145,  -929,  -929,  -929,  -929,  -929,   316,  -929,  -929,
    -929,  -929,  -929,    30,   108,  -929,  -929,  -840,    75,  -756,
    -811,  -929,   105,  -182,   589,   596,   787,  -929,   424,   410,
     414,   358,    37,  -929,  -929,  -929,  -929,   270,  -929,   574,
    -929,  -929,  -929,   356,  -929,   524,   155,  -929,    -5,  -364,
    -173,  -928,    90,   844,   104,  -565,  -929,  -303,  -596,  -929,
    -929,   916,   578,  -929,  -929,  -929,  -929,  -929,  -929,  -929,
    -929,  -929,  -929,    25,  -929,  -929,  -929,  -929,    66,   222,
    -929,  -929,  -929,  -929,  -929,  -929,    24,  -929,    61,   774,
    -174,  -433,  -602,  -750,   408,    98,  -929,  -929,   646,   355,
    -929,  -929,  -929,   442,   197,   -42,  -929,    49,  -929,   816,
      -4,   750,   306,  -929,  -929,  -929,  -929,  -929,   995,  -929,
    1138,  -929,  -929,  -929,   754,  -929,  -455,  -929,  -929,  -686,
    -929,  -929,  -929,   -87,  -929,  -929
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
     448,   388,   418,   773,   662,    87,   924,   708,    92,    93,
     820,    84,    84,    84,   102,   284,    84,   284,  1033,    84,
     928,   125,    84,  1091,    84,   113,   125,   944,   116,   117,
      84,   118,   119,    84,    84,   125,   120,   121,    84,   299,
     296,   124,   837,   772,   839,   131,   114,   296,    84,   152,
     298,    84,   299,   410,    84,  1027,   125,   910,   911,   299,
     199,   300,  1028,   980,   301,   395,   663,   983,    89,   878,
     997,   605,   606,    84,    84,    86,    86,  1027,   488,   296,
      84,   848,   298,   477,  1028,  1027,   848,   490,   193,    84,
     270,   299,  1028,   300,   689,   499,   301,    37,  1092,   502,
     503,   803,   458,   235,    84,   638,   107,   239,   241,   242,
     243,   960,   150,   258,   891,   220,   893,   265,   268,   265,
     761,   202,   639,   640,   951,   669,   160,  1092,   952,   273,
     953,   733,   275,   276,    89,    89,    89,    89,   535,  1050,
     265,    89,   265,   292,    84,   460,    86,   224,   225,   226,
     227,   228,   363,   365,   367,   368,   130,   221,   161,   292,
     513,   462,   111,    89,   577,   641,    48,   670,   200,   804,
     558,  1080,   282,   396,   391,   391,   690,   111,    89,   459,
      51,   709,   465,   587,  1046,   566,   165,   278,   278,   278,
     278,   851,   508,  1102,   285,   511,   851,   183,   222,   478,
    1051,   258,   762,   308,   494,   536,   265,   560,   671,  1099,
     308,   255,   268,   568,   495,   265,   376,  1110,   714,   879,
     570,   647,   459,  1066,   266,   941,  1047,   941,   188,   941,
     479,   399,   591,   292,   802,   740,   487,   480,   463,  1086,
     646,    84,   308,   189,    84,  1017,  1061,   559,   598,   572,
    1113,   710,   190,   600,   481,   866,   711,  1024,  1025,  1084,
     735,  1030,   567,   675,  1029,   194,  1034,  1048,   482,   387,
     912,  1034,   383,   383,   383,   383,   715,   483,   913,   333,
     637,  1065,  1035,   774,   985,   828,  1029,  1035,   484,   372,
     567,   847,   333,   621,  1029,    84,  1035,   571,   642,   333,
     697,   287,   623,   195,  1111,   775,   702,   551,   465,   592,
     166,   167,   822,   722,   776,   513,   229,  1083,   168,   169,
     170,  1078,   867,   847,  1079,   416,   786,   877,   732,   777,
     601,   333,   848,   391,   749,   778,   730,   191,  1020,   886,
    1021,  1022,  1023,   755,   739,   744,   579,   580,   235,   704,
     582,   584,   292,   292,   292,   787,   751,   292,   489,   597,
    1000,   245,   258,   494,   245,   246,   590,  1054,   246,   594,
     622,   779,   908,   495,   203,   876,   950,   780,   196,   624,
     692,   197,   692,   692,   705,   692,   706,   857,  1001,   247,
     723,   692,   247,   204,   753,   692,   625,   752,   626,   628,
     631,   631,   631,   631,   676,   265,   155,   789,   478,   292,
     648,   750,   650,   206,   260,   245,   793,   269,   657,   246,
     992,   858,   156,   858,   171,   468,   564,   565,   207,   552,
     859,   249,   859,   750,   249,   210,  1104,   250,   794,   479,
     250,  1000,   851,   247,   211,   270,   480,   213,   537,   538,
     539,   540,   541,   542,   795,   860,   858,   807,   172,   861,
     862,   861,   862,   481,   863,   859,   863,   810,   929,  1001,
     931,   750,   932,   173,   811,   216,   186,   482,   827,   829,
     830,   737,   716,   812,   790,   249,   483,   187,   993,   743,
    1056,   250,  1059,   790,   861,   862,   821,   484,   217,   863,
    1002,   365,   727,   729,   831,   292,   111,   111,   833,   979,
     736,   889,   419,   218,   813,   790,   219,   391,   741,   655,
     391,   814,   655,   655,   111,   884,   858,   885,   858,   897,
     231,   790,   946,   948,   808,   859,   232,   859,   815,   666,
     995,   655,   674,  1010,   808,  1055,   655,   265,   655,   655,
    1011,   808,   816,   655,   238,   808,   808,   808,  1057,   244,
    1060,   817,   791,   259,   861,   862,   861,   862,   268,   863,
     265,   863,   818,   699,   420,   543,  1106,   421,   422,   423,
     135,   808,   707,   792,   544,   808,   424,   272,   890,  1088,
     425,   717,   718,   719,   720,   426,   465,  1107,   157,   158,
     991,   162,   427,   208,   428,   429,   898,   430,   293,   947,
     947,  1058,   163,   545,   209,   383,   164,   996,   546,   361,
     567,   294,   748,   383,   615,   616,   617,  1071,   431,   245,
     963,   136,    84,   246,    86,   400,   858,   137,   432,   184,
     185,   465,   433,   401,  1097,   859,   402,   858,   208,   434,
     138,   435,   918,   919,   920,   139,   859,   247,   403,   209,
     436,   405,   437,   466,   140,  1098,    84,   141,    95,   551,
     869,   142,   404,  1103,   861,   862,   406,   143,   618,   863,
     858,   874,   248,   245,   407,   861,   862,   246,   408,   859,
     863,   881,   882,   208,   292,    84,   292,   107,   411,   249,
     438,   858,   412,   439,   209,   250,   413,   144,  -524,   416,
     859,   247,   279,   280,   281,   145,   768,   769,   861,   862,
     826,   450,    89,   863,   681,   452,   683,   684,   453,   832,
     685,   834,   835,   836,   909,    84,   631,   125,   454,   861,
     862,  -282,   517,   132,   863,   133,    84,   138,   234,   858,
     587,   923,   139,   249,   855,   926,   455,   456,   859,   250,
      84,   140,   240,   518,   141,    84,   457,   274,   142,  1042,
    1043,   519,   520,   464,   143,   905,  -282,   521,  -282,   659,
     660,   564,   103,   104,   105,   106,   522,   861,   862,   523,
     468,   524,   863,   632,   633,   634,   471,    84,   673,   366,
     472,   525,   526,   678,   473,   679,   680,   123,   474,    84,
     682,   583,    84,   954,   627,   475,    84,   959,   728,   476,
     491,   527,   964,   492,   965,   111,   493,   693,   694,   942,
     695,   943,   498,   500,   501,   504,   700,   505,   506,   528,
     703,   507,   510,   512,   513,   548,   514,   555,   556,  1100,
    1101,   557,   575,   560,   564,   561,   925,   567,   578,   574,
     602,   603,   604,   607,   529,   608,   609,   610,   564,   611,
     612,   530,   613,   614,   635,   649,   934,   531,   532,   652,
     658,   661,   688,   696,   296,   297,   487,   298,   701,   733,
     724,   664,   745,   738,   746,   748,   299,   747,   300,   754,
     756,   301,   759,   760,   763,   765,    89,   766,  1040,   767,
     770,   771,   797,   798,   788,   799,   465,   823,   958,   292,
     825,   824,   805,   383,   809,   838,   840,   842,   302,   303,
     865,   844,   870,   871,   304,   305,   875,   296,   297,   776,
     298,   892,  1040,   887,   888,  1032,  1041,   896,   899,   299,
     894,   300,   900,   902,   301,   903,   922,   930,   906,   306,
     933,   935,   927,   936,   937,   938,   949,   939,   966,   968,
     960,   967,   971,    89,    89,    89,  1032,  1040,   970,   972,
    1041,   302,   303,   973,  1040,   976,   978,   304,   305,   982,
    1008,   984,   981,   986,  1012,   987,  1075,   990,   994,   988,
    1013,  1014,  1016,  1018,  1001,  1019,  -503,    89,  1069,  1070,
    1072,    89,   306,  1040,  1076,  1041,  1087,   307,  1077,  1081,
    1082,  1089,  1041,  1075,   742,   796,   801,  1105,   569,    89,
     975,   977,  1109,   731,   921,   917,   451,   415,   153,   286,
     599,   868,   154,   377,   958,   883,   215,   308,  1026,   907,
    1015,  1041,   686,  1064,   296,   297,   309,   298,   310,  1044,
     687,   311,   312,   854,   852,  1045,   299,   509,   300,   846,
     307,   301,   721,   487,  1068,   901,   369,   758,   974,   313,
    1112,   461,   314,   726,  1067,  1085,   554,  1114,  1096,   315,
     316,   872,   677,   853,   989,   576,   317,   318,   302,   303,
     308,   233,   101,   945,   304,   305,   581,   319,     0,   309,
     320,   310,   321,   322,   311,   312,   323,     0,   324,     0,
     325,     0,     0,   326,     0,     0,   327,   328,   329,   306,
     330,   331,   313,   332,     0,   314,   333,     0,     0,     0,
       0,     0,   315,   316,     0,     0,   334,   335,   336,   317,
     318,     0,   564,     0,     0,     0,     0,     0,   296,   297,
     319,   298,     0,   320,     0,   321,   322,     0,     0,   323,
     299,   324,   300,   325,     0,   301,   326,     0,     0,   327,
     328,   329,     0,   330,   331,     0,   332,   307,     0,   333,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   334,
     335,   336,   302,   303,     0,     0,     0,     0,   304,   305,
       0,     0,     0,     0,     0,     0,     0,   308,     0,     0,
       0,     0,     0,     0,     0,     0,   309,     0,   310,     0,
       0,   311,   312,   306,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   313,
       0,     0,   314,     0,     0,     0,     0,     0,     0,   315,
     316,     0,     0,     0,     0,     0,   317,   318,     0,     0,
       0,     0,     0,     0,     0,   296,   297,   319,   298,     0,
     320,     0,   321,   322,     0,     0,   323,   299,   324,   300,
     325,     0,   301,   326,     0,     0,   327,   328,   329,     0,
       0,   331,     0,   332,     0,     0,   333,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   334,   335,   336,   302,
     303,   308,     0,     0,     0,   304,   305,     0,   296,   297,
     309,   298,   379,     0,     0,     0,   312,     0,     0,     0,
     299,     0,   300,     0,     0,   301,     0,     0,     0,     0,
     306,     0,   380,   313,     0,     0,   314,     0,     0,     0,
       0,     0,     0,   315,   316,     0,     0,     0,     0,     0,
     317,   318,   302,   303,     0,     0,     0,     0,   304,   305,
       0,   319,     0,     0,   320,     0,   321,   322,     0,     0,
     323,     0,   324,     0,   325,     0,     0,   326,     0,     0,
     327,   328,   329,   306,     0,   331,     0,   332,     0,     0,
     333,   296,   297,     0,   298,     0,     0,     0,     0,     0,
     334,   335,   336,   299,     0,   300,     0,     0,   301,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   308,     0,
       0,     0,     0,     0,     0,     0,     0,   309,     0,   379,
       0,     0,     0,   312,     0,   302,   303,     0,     0,     0,
       0,   304,   305,     0,   487,     0,     0,     0,     0,     0,
     313,     0,     0,   314,     0,     0,     0,     0,     0,     0,
     315,   316,     0,     0,     0,     0,   306,   317,   318,   654,
       0,   308,     0,     0,     0,     0,     0,     0,   319,     0,
     309,   320,   379,   321,   322,     0,   312,   323,     0,   324,
       0,   325,     0,     0,   326,     0,     0,   327,   328,   329,
       0,     0,   331,   313,   332,     0,   314,   333,     0,     0,
       0,     0,     0,   315,   316,     0,     0,   334,   335,   336,
     317,   318,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   319,     0,     0,   320,     0,   321,   322,     0,     0,
     323,     0,   324,     0,   325,     0,     0,   326,     0,     0,
     327,   328,   329,     0,   308,   331,     0,   332,     0,     0,
     333,   296,   297,   309,   298,   379,     0,     0,     0,   312,
     334,   335,   336,   299,     0,   300,     0,     0,   301,     0,
       0,     0,     0,     0,     0,   698,   313,     0,     0,   314,
       0,     0,     0,     0,     0,     0,   315,   316,     0,     0,
       0,     0,     0,   317,   318,   302,   303,     0,     0,     0,
       0,   304,   305,     0,   319,     0,     0,   320,     0,   321,
     322,     0,     0,   323,     0,   324,     0,   325,     0,     0,
     326,     0,     0,   327,   328,   329,   306,     0,   331,     0,
     332,     0,     0,   333,   296,   297,     0,   298,     0,     0,
       0,     0,     0,   334,   335,   336,   299,     0,   300,     0,
       0,   301,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   302,   303,
       0,     0,     0,     0,   304,   305,     0,   296,   297,     0,
     298,     0,     0,     0,     0,     0,     0,     0,     0,   299,
       0,   300,     0,     0,   301,     0,     0,     0,     0,   306,
       0,     0,     0,     0,   308,     0,     0,     0,     0,     0,
       0,     0,     0,   309,     0,   379,     0,     0,     0,   312,
       0,   302,   303,     0,     0,     0,     0,   304,   305,     0,
       0,     0,     0,     0,     0,   955,   313,     0,     0,   314,
       0,     0,     0,     0,     0,     0,   315,   316,     0,     0,
       0,     0,   306,   317,   318,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   319,     0,     0,   320,     0,   321,
     322,     0,     0,   323,     0,   324,     0,   325,     0,     0,
     326,     0,     0,   327,   328,   329,     0,   308,   331,     0,
     332,     0,     0,   333,   296,   297,   309,   298,   379,     0,
       0,     0,   312,   334,   335,   336,   299,     0,   300,     0,
       0,   301,     0,     0,     0,     0,     0,     0,     0,   313,
       0,     0,   314,     0,     0,     0,     0,     0,     0,   315,
     316,     0,     0,     0,     0,     0,   317,   318,   302,   303,
     665,     0,     0,     0,   304,   305,     0,   319,     0,   309,
     320,   379,   321,   322,     0,   312,   323,     0,   324,     0,
     325,     0,     0,   326,     0,     0,   327,   328,   329,   306,
       0,   331,   313,   332,     0,   314,   333,     0,     0,     0,
       0,     0,   315,   316,     0,     0,   334,   335,   336,   317,
     318,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     319,     0,     0,   320,     0,   321,   322,     0,     0,   323,
       0,   324,     0,   325,     0,     0,   326,     0,     0,   327,
     328,   329,     0,     0,   331,     0,   332,     0,     0,   333,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   334,
     335,   336,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   308,     0,     0,
       0,     0,     0,     0,     0,     0,   309,     0,   379,     0,
       0,     0,   312,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   313,
       0,     0,   314,  -561,     1,     0,     0,     0,     0,   315,
     316,     0,     0,     0,     0,     0,   317,   318,     0,  -561,
       0,     0,     0,     0,     0,     0,     0,   319,     0,     0,
     320,     0,   321,   322,     0,     0,   323,     0,   324,     0,
     325,     0,     0,   326,     0,     0,   327,   328,     2,     3,
       0,   331,     0,     4,     0,     5,   333,     0,     6,     7,
       8,     9,    10,     0,    11,    12,   334,   335,   336,     0,
       0,     0,    13,    14,     0,     0,    15,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    16,    17,    18,    19,     0,    20,    21,
      22,    23,    24,    25,    26,     0,     0,    27,     0,     0,
      28,     0,    29,    30,     0,    31,    32,     0,     0,     0,
      33,    34,    35,    36,    37,    38,   517,     0,    39,     0,
       0,     0,     0,     0,    40,    41,     0,     0,    42,     0,
       0,    43,     0,    44,    45,     0,     0,   518,     0,    46,
       0,     0,     0,    47,     0,   519,   520,     0,     0,     0,
       0,   521,     0,   664,     0,     0,     0,     0,     0,     0,
     522,     0,     0,   523,     0,   524,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   525,   526,     0,     0,     0,
       0,     0,     0,    48,     0,    49,     0,     0,    50,     0,
       0,     0,     0,     0,     0,   527,     0,    51,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   528,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  -305,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   529,     0,
       0,     0,     0,     0,     0,   530,     0,  -305,     0,     0,
       0,   531,   532
};

static const yytype_int16 yycheck[] =
{
       4,    43,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    21,    21,   200,    23,
     266,   166,    26,   709,   197,    29,    30,   391,    32,    33,
     225,   226,   227,    37,    38,   468,   491,    41,    42,    43,
     213,    45,    46,   346,   173,   348,    50,   410,   231,   651,
     269,   228,   260,   618,   487,     6,   806,     3,     9,    10,
     662,     4,     4,     4,    15,   194,     4,   196,     3,     4,
     820,     6,     4,     3,     4,    26,     6,     3,    29,    30,
       4,    32,    33,     4,     4,     6,    37,    38,     4,    15,
       3,    42,   688,     6,   690,    46,     3,     3,     4,    50,
       6,     4,    15,   248,     4,    32,     6,    43,    44,    15,
     105,    17,    39,   924,    20,   105,   164,   928,   122,   103,
     960,   424,   425,     4,     4,     6,     6,    32,   310,     3,
       4,   696,     6,   307,    39,    32,   701,   311,   108,     4,
     269,    15,    39,    17,   177,   319,    20,   121,  1076,   323,
     324,   173,   164,   157,     4,    63,     6,   161,   162,   163,
     164,   221,   202,   167,   760,   152,   762,   171,   172,   173,
     177,   122,    80,    81,   860,   152,    51,  1105,   864,   183,
     866,   241,   186,   187,   188,   189,   190,   191,   188,   149,
     194,   195,   196,   197,     4,   164,     6,    64,    65,    66,
      67,    68,   206,   207,   208,   209,   210,   194,   255,   213,
     258,   164,   216,   217,   396,   123,   190,   194,   213,   241,
     164,  1061,   192,   213,   228,   229,   259,   231,   232,   241,
     204,   177,   188,   406,   152,   164,   256,   188,   189,   190,
     191,   696,   329,  1083,   195,   332,   701,   255,   235,   153,
     210,   255,   259,   166,   220,   255,   260,   241,   235,   164,
     166,   177,   266,   164,   230,   269,   217,   164,   209,   253,
     164,   209,   241,  1029,   177,   840,   194,   842,   257,   844,
     184,   232,   164,   287,   648,   209,   192,   191,   241,   209,
     463,     4,   166,   257,     4,   981,   177,   241,   164,   255,
    1111,   247,   257,   164,   208,   188,   252,   993,   994,  1065,
     253,   253,   241,   495,   241,   177,   251,   235,   222,   251,
     256,   251,   224,   225,   226,   227,   267,   231,   264,   255,
     459,   211,   267,   106,   930,   228,   241,   267,   242,   189,
     241,   247,   255,   164,   241,     4,   267,   241,   256,   255,
     524,   251,   164,   244,  1104,   128,   530,   361,   188,   241,
      71,    72,   665,   164,   137,   258,   233,   177,    79,    80,
      81,  1057,   255,   247,  1060,   241,   622,   741,   561,   152,
     241,   255,   947,   387,   164,   158,   559,   257,   984,   752,
     986,   987,   988,   601,   571,   578,   400,   401,   402,   126,
     404,   405,   406,   407,   408,   624,   164,   411,   310,   413,
     154,   124,   416,   220,   124,   128,   408,  1013,   128,   411,
     241,   194,   785,   230,   111,   255,   164,   200,   177,   241,
     517,   177,   519,   520,   161,   522,   163,   173,   182,   152,
     241,   528,   152,   130,   164,   532,   450,   592,   452,   453,
     454,   455,   456,   457,   261,   459,     0,   164,   153,   463,
     464,   241,   466,   255,   177,   124,   164,   177,   472,   128,
     173,   209,    16,   209,   185,   192,   378,   379,   255,   196,
     218,   194,   218,   241,   194,   259,  1088,   200,   164,   184,
     200,   154,   947,   152,   147,   624,   191,   177,    82,    83,
      84,    85,    86,    87,   164,   241,   209,   164,   219,   247,
     248,   247,   248,   208,   252,   218,   252,   164,   821,   182,
     823,   241,   825,   234,   164,   221,   240,   222,   164,   164,
     164,   567,   536,   153,   241,   194,   231,   251,   241,   575,
     173,   200,   173,   241,   247,   248,   241,   242,   257,   252,
     213,   555,   556,   557,   164,   559,   560,   561,   164,   923,
     564,   164,    77,   241,   184,   241,     3,   571,   572,   471,
     574,   191,   474,   475,   578,   748,   209,   750,   209,   164,
     259,   241,   164,   164,   241,   218,   257,   218,   208,   491,
     164,   493,   494,   164,   241,   164,   498,   601,   500,   501,
     964,   241,   222,   505,     6,   241,   241,   241,   241,     6,
     241,   231,   217,     3,   247,   248,   247,   248,   622,   252,
     624,   252,   242,   525,   139,   209,   217,   142,   143,   144,
     108,   241,   534,   238,   218,   241,   151,   241,   241,  1072,
     155,   543,   544,   545,   546,   160,   188,   238,   133,   134,
     173,   240,   167,   240,   169,   170,   241,   172,   253,   241,
     241,   173,   251,   247,   251,   567,   255,   241,   252,   177,
     241,     4,   241,   575,   114,   115,   116,  1041,   193,   124,
     875,   159,     4,   128,     6,   255,   209,   165,   203,    88,
      89,   188,   207,   255,   173,   218,   241,   209,   240,   214,
     178,   216,   793,   794,   795,   183,   218,   152,    49,   251,
     225,   240,   227,   255,   192,   173,     4,   195,     6,   723,
     724,   199,   255,  1087,   247,   248,   177,   205,   168,   252,
     209,   735,   177,   124,   177,   247,   248,   128,   177,   218,
     252,   745,   746,   240,   748,     4,   750,     6,   177,   194,
     265,   209,   177,   268,   251,   200,    74,   235,   255,   241,
     218,   152,   189,   190,   191,   243,   611,   612,   247,   248,
     672,   260,   776,   252,   504,   255,   506,   507,   240,   681,
     510,   683,   684,   685,   788,     4,   790,     6,   177,   247,
     248,   126,   127,     4,   252,     6,     4,   178,     6,   209,
     973,   805,   183,   194,   706,   809,   177,   177,   218,   200,
       4,   192,     6,   148,   195,     4,   177,     6,   199,  1001,
    1002,   156,   157,   255,   205,   776,   161,   162,   163,   474,
     475,   733,    16,    17,    18,    19,   171,   247,   248,   174,
     192,   176,   252,   455,   456,   457,   177,     4,   493,     6,
     255,   186,   187,   498,     6,   500,   501,    41,   177,     4,
     505,     6,     4,   867,     6,   177,     4,   871,     6,   177,
     177,   206,   876,   177,   879,   879,   177,   519,   520,   842,
     522,   844,   177,   177,   177,   177,   528,   177,   177,   224,
     532,   177,   177,     3,   258,    94,   236,   259,   255,  1081,
    1082,   240,   186,   241,   806,   221,   808,   241,   259,   241,
     177,   177,   177,   177,   249,   177,   177,   177,   820,   177,
     177,   256,   177,   177,   129,     3,   828,   262,   263,   102,
      21,   259,   259,   177,     3,     4,   192,     6,   177,   241,
     255,   164,   255,   186,   255,   241,    15,   164,    17,   164,
       3,    20,     3,   259,     3,     3,   960,     3,  1000,     3,
       3,     3,     3,     3,   255,     4,   188,   241,   870,   973,
     241,   164,   255,   875,   255,     3,   179,   179,    47,    48,
       3,   179,   177,   255,    53,    54,   177,     3,     4,   137,
       6,     3,  1034,   164,   164,   999,  1000,   164,   164,    15,
     241,    17,   164,   164,    20,   164,     3,   259,   177,    78,
     164,   164,   177,   164,   164,   164,   236,   164,     3,     3,
     221,   164,     3,  1027,  1028,  1029,  1030,  1069,   164,   164,
    1034,    47,    48,   177,  1076,     3,   173,    53,    54,     3,
     212,   259,   188,   259,   164,   259,  1050,   949,   188,   259,
     259,   164,   164,   164,   182,   164,   164,  1061,   241,   255,
     192,  1065,    78,  1105,   254,  1069,  1070,   136,   149,   257,
     257,   129,  1076,  1077,   574,   636,   644,   241,   387,  1083,
     912,   915,  1096,   560,   796,   790,   272,   255,    51,   196,
     416,   723,    51,   218,   996,   747,   141,   166,   996,   783,
     973,  1105,   513,  1028,     3,     4,   175,     6,   177,  1004,
     514,   180,   181,   703,   700,  1007,    15,   330,    17,   695,
     136,    20,   548,   192,  1034,   769,   210,   603,   906,   198,
    1105,   287,   201,   555,  1030,  1069,   362,  1113,  1077,   208,
     209,   733,   496,   701,   947,   395,   215,   216,    47,    48,
     166,   156,    14,   847,    53,    54,   402,   226,    -1,   175,
     229,   177,   231,   232,   180,   181,   235,    -1,   237,    -1,
     239,    -1,    -1,   242,    -1,    -1,   245,   246,   247,    78,
     249,   250,   198,   252,    -1,   201,   255,    -1,    -1,    -1,
      -1,    -1,   208,   209,    -1,    -1,   265,   266,   267,   215,
     216,    -1,  1104,    -1,    -1,    -1,    -1,    -1,     3,     4,
     226,     6,    -1,   229,    -1,   231,   232,    -1,    -1,   235,
      15,   237,    17,   239,    -1,    20,   242,    -1,    -1,   245,
     246,   247,    -1,   249,   250,    -1,   252,   136,    -1,   255,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   265,
     266,   267,    47,    48,    -1,    -1,    -1,    -1,    53,    54,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   166,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   175,    -1,   177,    -1,
      -1,   180,   181,    78,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   198,
      -1,    -1,   201,    -1,    -1,    -1,    -1,    -1,    -1,   208,
     209,    -1,    -1,    -1,    -1,    -1,   215,   216,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,     3,     4,   226,     6,    -1,
     229,    -1,   231,   232,    -1,    -1,   235,    15,   237,    17,
     239,    -1,    20,   242,    -1,    -1,   245,   246,   247,    -1,
      -1,   250,    -1,   252,    -1,    -1,   255,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   265,   266,   267,    47,
      48,   166,    -1,    -1,    -1,    53,    54,    -1,     3,     4,
     175,     6,   177,    -1,    -1,    -1,   181,    -1,    -1,    -1,
      15,    -1,    17,    -1,    -1,    20,    -1,    -1,    -1,    -1,
      78,    -1,   197,   198,    -1,    -1,   201,    -1,    -1,    -1,
      -1,    -1,    -1,   208,   209,    -1,    -1,    -1,    -1,    -1,
     215,   216,    47,    48,    -1,    -1,    -1,    -1,    53,    54,
      -1,   226,    -1,    -1,   229,    -1,   231,   232,    -1,    -1,
     235,    -1,   237,    -1,   239,    -1,    -1,   242,    -1,    -1,
     245,   246,   247,    78,    -1,   250,    -1,   252,    -1,    -1,
     255,     3,     4,    -1,     6,    -1,    -1,    -1,    -1,    -1,
     265,   266,   267,    15,    -1,    17,    -1,    -1,    20,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   166,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   175,    -1,   177,
      -1,    -1,    -1,   181,    -1,    47,    48,    -1,    -1,    -1,
      -1,    53,    54,    -1,   192,    -1,    -1,    -1,    -1,    -1,
     198,    -1,    -1,   201,    -1,    -1,    -1,    -1,    -1,    -1,
     208,   209,    -1,    -1,    -1,    -1,    78,   215,   216,   164,
      -1,   166,    -1,    -1,    -1,    -1,    -1,    -1,   226,    -1,
     175,   229,   177,   231,   232,    -1,   181,   235,    -1,   237,
      -1,   239,    -1,    -1,   242,    -1,    -1,   245,   246,   247,
      -1,    -1,   250,   198,   252,    -1,   201,   255,    -1,    -1,
      -1,    -1,    -1,   208,   209,    -1,    -1,   265,   266,   267,
     215,   216,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   226,    -1,    -1,   229,    -1,   231,   232,    -1,    -1,
     235,    -1,   237,    -1,   239,    -1,    -1,   242,    -1,    -1,
     245,   246,   247,    -1,   166,   250,    -1,   252,    -1,    -1,
     255,     3,     4,   175,     6,   177,    -1,    -1,    -1,   181,
     265,   266,   267,    15,    -1,    17,    -1,    -1,    20,    -1,
      -1,    -1,    -1,    -1,    -1,   197,   198,    -1,    -1,   201,
      -1,    -1,    -1,    -1,    -1,    -1,   208,   209,    -1,    -1,
      -1,    -1,    -1,   215,   216,    47,    48,    -1,    -1,    -1,
      -1,    53,    54,    -1,   226,    -1,    -1,   229,    -1,   231,
     232,    -1,    -1,   235,    -1,   237,    -1,   239,    -1,    -1,
     242,    -1,    -1,   245,   246,   247,    78,    -1,   250,    -1,
     252,    -1,    -1,   255,     3,     4,    -1,     6,    -1,    -1,
      -1,    -1,    -1,   265,   266,   267,    15,    -1,    17,    -1,
      -1,    20,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    47,    48,
      -1,    -1,    -1,    -1,    53,    54,    -1,     3,     4,    -1,
       6,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    15,
      -1,    17,    -1,    -1,    20,    -1,    -1,    -1,    -1,    78,
      -1,    -1,    -1,    -1,   166,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   175,    -1,   177,    -1,    -1,    -1,   181,
      -1,    47,    48,    -1,    -1,    -1,    -1,    53,    54,    -1,
      -1,    -1,    -1,    -1,    -1,   197,   198,    -1,    -1,   201,
      -1,    -1,    -1,    -1,    -1,    -1,   208,   209,    -1,    -1,
      -1,    -1,    78,   215,   216,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   226,    -1,    -1,   229,    -1,   231,
     232,    -1,    -1,   235,    -1,   237,    -1,   239,    -1,    -1,
     242,    -1,    -1,   245,   246,   247,    -1,   166,   250,    -1,
     252,    -1,    -1,   255,     3,     4,   175,     6,   177,    -1,
      -1,    -1,   181,   265,   266,   267,    15,    -1,    17,    -1,
      -1,    20,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   198,
      -1,    -1,   201,    -1,    -1,    -1,    -1,    -1,    -1,   208,
     209,    -1,    -1,    -1,    -1,    -1,   215,   216,    47,    48,
     166,    -1,    -1,    -1,    53,    54,    -1,   226,    -1,   175,
     229,   177,   231,   232,    -1,   181,   235,    -1,   237,    -1,
     239,    -1,    -1,   242,    -1,    -1,   245,   246,   247,    78,
      -1,   250,   198,   252,    -1,   201,   255,    -1,    -1,    -1,
      -1,    -1,   208,   209,    -1,    -1,   265,   266,   267,   215,
     216,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     226,    -1,    -1,   229,    -1,   231,   232,    -1,    -1,   235,
      -1,   237,    -1,   239,    -1,    -1,   242,    -1,    -1,   245,
     246,   247,    -1,    -1,   250,    -1,   252,    -1,    -1,   255,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   265,
     266,   267,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   166,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   175,    -1,   177,    -1,
      -1,    -1,   181,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   198,
      -1,    -1,   201,     0,     1,    -1,    -1,    -1,    -1,   208,
     209,    -1,    -1,    -1,    -1,    -1,   215,   216,    -1,    16,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   226,    -1,    -1,
     229,    -1,   231,   232,    -1,    -1,   235,    -1,   237,    -1,
     239,    -1,    -1,   242,    -1,    -1,   245,   246,    45,    46,
      -1,   250,    -1,    50,    -1,    52,   255,    -1,    55,    56,
      57,    58,    59,    -1,    61,    62,   265,   266,   267,    -1,
      -1,    -1,    69,    70,    -1,    -1,    73,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    90,    91,    92,    93,    -1,    95,    96,
      97,    98,    99,   100,   101,    -1,    -1,   104,    -1,    -1,
     107,    -1,   109,   110,    -1,   112,   113,    -1,    -1,    -1,
     117,   118,   119,   120,   121,   122,   127,    -1,   125,    -1,
      -1,    -1,    -1,    -1,   131,   132,    -1,    -1,   135,    -1,
      -1,   138,    -1,   140,   141,    -1,    -1,   148,    -1,   146,
      -1,    -1,    -1,   150,    -1,   156,   157,    -1,    -1,    -1,
      -1,   162,    -1,   164,    -1,    -1,    -1,    -1,    -1,    -1,
     171,    -1,    -1,   174,    -1,   176,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   186,   187,    -1,    -1,    -1,
      -1,    -1,    -1,   190,    -1,   192,    -1,    -1,   195,    -1,
      -1,    -1,    -1,    -1,    -1,   206,    -1,   204,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   224,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   236,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   249,    -1,
      -1,    -1,    -1,    -1,    -1,   256,    -1,   258,    -1,    -1,
      -1,   262,   263
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
{
       0,     1,    45,    46,    50,    52,    55,    56,    57,    58,
      59,    61,    62,    69,    70,    73,    90,    91,    92,    93,
      95,    96,    97,    98,    99,   100,   101,   104,   107,   109,
     110,   112,   113,   117,   118,   119,   120,   121,   122,   125,
     131,   132,   135,   138,   140,   141,   146,   150,   190,   192,
     195,   204,   278,   289,   290,   291,   292,   301,   308,   328,
     329,   338,   339,   340,   342,   343,   344,   345,   346,   356,
     376,   380,   426,   427,   430,   431,   449,   483,   484,   485,
     486,   488,   492,   494,     4,   477,     6,   474,   475,   477,
     477,   477,   474,   474,   477,     6,   476,   477,   477,   482,
     487,   487,   474,   476,   476,   476,   476,     6,   377,   378,
     415,   477,   477,   474,     3,   502,   474,   474,   474,   474,
     474,   474,   330,   476,   474,     6,   472,   473,   477,   428,
     477,   474,     4,     6,   480,   108,   159,   165,   178,   183,
     192,   195,   199,   205,   235,   243,   347,   349,   350,   351,
     202,   458,   474,   347,   349,     0,    16,   133,   134,   489,
      51,   255,   240,   251,   255,   256,    71,    72,    79,    80,
      81,   185,   219,   234,   309,   310,   311,   314,   317,   320,
     321,   322,   325,   255,    88,    89,   240,   251,   257,   257,
     257,   257,   379,   380,   177,   244,   177,   177,   357,   105,
     213,   280,   474,   111,   130,   432,   255,   255,   240,   251,
     259,   147,   341,   177,   352,   352,   221,   257,   241,     3,
     152,   194,   235,   459,    64,    65,    66,    67,    68,   233,
     281,   259,   257,   485,     6,   477,   490,   491,     6,   477,
       6,   477,   477,   477,     6,   124,   128,   152,   177,   194,
     200,   360,   361,   366,   368,   177,   326,   327,   477,     3,
     177,   307,   319,   368,   370,   477,   177,   316,   477,   177,
     307,   312,   241,   477,     6,   477,   477,   300,   474,   300,
     300,   300,   380,   306,   307,   474,   306,   251,   358,   417,
     420,   472,   477,   253,     4,   478,     3,     4,     6,    15,
      17,    20,    47,    48,    53,    54,    78,   136,   166,   175,
     177,   180,   181,   198,   201,   208,   209,   215,   216,   226,
     229,   231,   232,   235,   237,   239,   242,   245,   246,   247,
     249,   250,   252,   255,   265,   266,   267,   390,   391,   392,
     393,   394,   401,   403,   422,   433,   434,   435,   436,   437,
     457,   462,   463,   469,   477,   479,   493,   495,   499,   500,
     501,   177,   333,   477,   429,   477,     6,   477,   477,   428,
     353,   417,   189,   354,   355,   415,   474,   351,   450,   177,
     197,   287,   288,   462,   287,   287,   287,   251,   283,   284,
     286,   477,   282,   283,   285,   105,   213,   279,   354,   474,
     255,   255,   241,    49,   255,   240,   177,   177,   177,   323,
     368,   177,   177,    74,   324,   326,   241,   318,   319,    77,
     139,   142,   143,   144,   151,   155,   160,   167,   169,   170,
     172,   193,   203,   207,   214,   216,   225,   227,   265,   268,
     406,   407,   408,   409,   411,   448,   315,   316,   312,   313,
     260,   310,   255,   240,   177,   177,   177,   177,   164,   241,
     164,   420,   164,   241,   255,   188,   255,   416,   192,   447,
     456,   177,   255,     6,   177,   177,   177,   457,   153,   184,
     191,   208,   222,   231,   242,   423,   424,   192,   390,   462,
     457,   177,   177,   177,   220,   230,   464,   465,   177,   457,
     177,   177,   457,   457,   177,   177,   177,   177,   500,   393,
     177,   500,     3,   258,   236,   424,   424,   127,   148,   156,
     157,   162,   171,   174,   176,   186,   187,   206,   224,   249,
     256,   262,   263,   400,   402,   188,   255,    82,    83,    84,
      85,    86,    87,   209,   218,   247,   252,   468,    94,   334,
     335,   477,   196,   331,   456,   259,   255,   240,   164,   241,
     241,   221,   460,   461,   462,   462,   164,   241,   164,   284,
     164,   241,   255,   416,   241,   186,   478,   390,   259,   477,
     477,   491,   477,     6,   477,   363,   365,   417,   367,   417,
     367,   164,   241,   324,   367,   390,   446,   477,   164,   327,
     164,   241,   177,   177,   177,   424,   424,   177,   177,   177,
     177,   177,   177,   177,   177,   114,   115,   116,   168,   369,
     371,   164,   241,   164,   241,   477,   477,     6,   477,   304,
     305,   477,   304,   304,   304,   129,   302,   307,    63,    80,
      81,   123,   256,   293,   294,   295,   417,   209,   477,     3,
     477,   458,   102,   359,   164,   462,   466,   477,    21,   466,
     466,   259,   458,   164,   164,   166,   462,   467,   493,   152,
     194,   235,   404,   466,   462,   390,   261,   465,   466,   466,
     466,   404,   466,   404,   404,   404,   391,   392,   259,   177,
     259,   398,   500,   398,   398,   398,   177,   457,   197,   462,
     398,   177,   457,   398,   126,   161,   163,   462,     3,   177,
     247,   252,   496,   498,   209,   267,   477,   462,   462,   462,
     462,   406,   164,   241,   255,   332,   429,   477,     6,   477,
     417,   355,   354,   241,   451,   253,   477,   288,   186,   283,
     209,   477,   285,   288,   354,   255,   255,   164,   241,   164,
     241,   164,   368,   164,   164,   319,     3,   412,   412,     3,
     259,   177,   259,     3,   413,     3,     3,     3,   413,   413,
       3,     3,     6,   422,   106,   128,   137,   152,   158,   194,
     200,   362,   372,   373,   374,   375,   316,   312,   255,   164,
     241,   217,   238,   164,   164,   164,   293,     3,     3,     4,
     296,   295,   416,   173,   241,   255,   459,   164,   241,   255,
     164,   164,   153,   184,   191,   208,   222,   231,   242,   425,
     459,   241,   424,   241,   164,   241,   462,   164,   228,   164,
     164,   164,   462,   164,   462,   462,   462,   425,     3,   425,
     179,   395,   179,   397,   179,   396,   395,   247,   422,   470,
     471,   493,   397,   470,   396,   462,   496,   173,   209,   218,
     241,   247,   248,   252,   497,     3,   188,   255,   335,   477,
     177,   255,   461,   481,   477,   177,   255,   416,   103,   253,
     348,   477,   477,   362,   417,   417,   324,   164,   164,   164,
     241,   425,     3,   425,   241,   410,   164,   164,   241,   164,
     164,   410,   164,   164,   364,   474,   177,   374,   324,   477,
      43,    44,   256,   264,   297,   298,   299,   305,   297,   297,
     297,   302,     3,   477,   460,   462,   477,   177,   460,   424,
     259,   424,   424,   164,   462,   164,   164,   164,   164,   164,
     399,   422,   399,   399,     3,   479,   164,   241,   164,   236,
     164,   496,   496,   496,   477,   197,   336,   337,   462,   477,
     221,   383,   387,   287,   477,   415,     3,   164,     3,   414,
     164,     3,   164,   177,   446,   296,     3,   299,   173,   416,
     387,   188,     3,   387,   259,   425,   259,   259,   259,   471,
     462,   173,   173,   241,   188,   164,   241,   384,   386,   474,
     154,   182,   213,   381,   382,   388,   389,   443,   212,   453,
     164,   416,   164,   259,   164,   365,   164,   496,   164,   164,
     425,   425,   425,   425,   496,   496,   337,    32,    39,   241,
     253,   421,   477,     3,   251,   267,   418,   419,   444,   445,
     472,   477,   390,   390,   389,   381,   152,   194,   235,   405,
     149,   210,   438,   454,   425,   164,   173,   241,   173,   173,
     241,   177,   384,   385,   385,   211,   386,   421,   419,   241,
     255,   416,   192,   452,   455,   477,   254,   149,   496,   496,
     384,   257,   257,   177,   386,   445,   209,   477,   458,   129,
     303,     3,   418,   439,   440,   441,   455,   173,   173,   164,
     390,   390,   384,   416,   459,   241,   217,   238,   442,   303,
     164,   460,   440,   387,   453
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
#line 426 "sql.yacc"
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
#line 452 "sql.yacc"
    {
		(yyval.ptr)=0;
	}
    break;

  case 4:

/* Line 1455 of yacc.c  */
#line 455 "sql.yacc"
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
#line 472 "sql.yacc"
    {
		(yyval.ptr)=A4GL_new_select_list_item_expr((yyvsp[(2) - (2)].s_select_list_item));
	}
    break;

  case 6:

/* Line 1455 of yacc.c  */
#line 477 "sql.yacc"
    {
		(yyval.ptr)=0;
	}
    break;

  case 7:

/* Line 1455 of yacc.c  */
#line 480 "sql.yacc"
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
#line 497 "sql.yacc"
    {
		 (yyval.ptr)=A4GL_new_select_list_item_expr((yyvsp[(2) - (2)].s_select_list_item));
	}
    break;

  case 9:

/* Line 1455 of yacc.c  */
#line 503 "sql.yacc"
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
#line 512 "sql.yacc"
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
#line 521 "sql.yacc"
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
#line 530 "sql.yacc"
    {
		(yyval.update_cmd)=(yyvsp[(2) - (2)].update_cmd);
		add_feature("UPDATE_COLUMN_EQ_VALUE_LIST");
    }
    break;

  case 13:

/* Line 1455 of yacc.c  */
#line 537 "sql.yacc"
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
#line 552 "sql.yacc"
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
#line 607 "sql.yacc"
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
#line 614 "sql.yacc"
    {
		(yyval.update_cmd)=(yyvsp[(1) - (3)].update_cmd);
		add_str_list((yyval.update_cmd)->column_list, (yyvsp[(3) - (3)].upd_pair)->column_name);
		local_add_select_list_item_list((yyval.update_cmd)->value_list, (yyvsp[(3) - (3)].upd_pair)->value);
	}
    break;

  case 17:

/* Line 1455 of yacc.c  */
#line 625 "sql.yacc"
    {
                strcpy((yyval.str),(yyvsp[(1) - (1)].str));
        }
    break;

  case 18:

/* Line 1455 of yacc.c  */
#line 628 "sql.yacc"
    {
                strcpy((yyval.str),(yyvsp[(2) - (2)].str));
        }
    break;

  case 19:

/* Line 1455 of yacc.c  */
#line 633 "sql.yacc"
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
#line 640 "sql.yacc"
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
#line 657 "sql.yacc"
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
#line 674 "sql.yacc"
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
#line 695 "sql.yacc"
    {
		(yyval.upd_pair)=malloc(sizeof(struct s_update_pair));
		(yyval.upd_pair)->column_name=acl_strdup((yyvsp[(1) - (3)].str));
		(yyval.upd_pair)->value=(yyvsp[(3) - (3)].s_select_list_item);
	}
    break;

  case 24:

/* Line 1455 of yacc.c  */
#line 704 "sql.yacc"
    {
			(yyval.str_list)=new_str_list((yyvsp[(1) - (1)].str));
		}
    break;

  case 25:

/* Line 1455 of yacc.c  */
#line 707 "sql.yacc"
    {
			(yyval.str_list)=add_str_list((yyvsp[(1) - (3)].str_list), (yyvsp[(3) - (3)].str));
		}
    break;

  case 26:

/* Line 1455 of yacc.c  */
#line 715 "sql.yacc"
    { 
		(yyval.s_select_list_item_list)=local_new_select_list_item_list((yyvsp[(1) - (1)].s_select_list_item));
	}
    break;

  case 27:

/* Line 1455 of yacc.c  */
#line 718 "sql.yacc"
    { 
		(yyval.s_select_list_item_list)=local_add_select_list_item_list((yyvsp[(1) - (3)].s_select_list_item_list),(yyvsp[(3) - (3)].s_select_list_item));
	}
    break;

  case 28:

/* Line 1455 of yacc.c  */
#line 726 "sql.yacc"
    {(yyval.s_select_list_item)=(yyvsp[(1) - (1)].s_select_list_item);}
    break;

  case 29:

/* Line 1455 of yacc.c  */
#line 727 "sql.yacc"
    {(yyval.s_select_list_item)=new_select_list_item_builtin_const(E_SLI_BUILTIN_CONST_NULL); }
    break;

  case 30:

/* Line 1455 of yacc.c  */
#line 734 "sql.yacc"
    { (yyval.sql_string)=make_sql_string_and_free(acl_strdup((yyvsp[(1) - (1)].str)), NULL);}
    break;

  case 31:

/* Line 1455 of yacc.c  */
#line 737 "sql.yacc"
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
#line 745 "sql.yacc"
    {SPRINTF2((yyval.str),"%s %s ",(yyvsp[(1) - (2)].str),(yyvsp[(2) - (2)].str));
			add_feature("DROP_VIEW");
}
    break;

  case 33:

/* Line 1455 of yacc.c  */
#line 748 "sql.yacc"
    {SPRINTF2((yyval.str),"%s %s",(yyvsp[(1) - (2)].str),(yyvsp[(2) - (2)].str));
		if (strchr((yyvsp[(2) - (2)].str),'@') || strchr((yyvsp[(2) - (2)].str),':')) add_feature("DROP_INDEX_QUALIFIED_PATH");
			add_feature("DROP_INDEX");
}
    break;

  case 34:

/* Line 1455 of yacc.c  */
#line 752 "sql.yacc"
    {SPRINTF2((yyval.str),"%s %s",(yyvsp[(1) - (2)].str),(yyvsp[(2) - (2)].str));
			add_feature("DROP_TRIGGER");
}
    break;

  case 35:

/* Line 1455 of yacc.c  */
#line 758 "sql.yacc"
    {(yyval.sql_string)=acl_strdup((yyvsp[(1) - (1)].str));}
    break;

  case 36:

/* Line 1455 of yacc.c  */
#line 759 "sql.yacc"
    {(yyval.sql_string)=(yyvsp[(1) - (1)].sql_string);}
    break;

  case 37:

/* Line 1455 of yacc.c  */
#line 763 "sql.yacc"
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
#line 773 "sql.yacc"
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
#line 787 "sql.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 40:

/* Line 1455 of yacc.c  */
#line 788 "sql.yacc"
    {strcpy((yyval.str),(yyvsp[(1) - (1)].str));}
    break;

  case 42:

/* Line 1455 of yacc.c  */
#line 793 "sql.yacc"
    {SPRINTF2((yyval.str),"%s%s",(yyvsp[(1) - (2)].str),(yyvsp[(2) - (2)].str)); }
    break;

  case 43:

/* Line 1455 of yacc.c  */
#line 798 "sql.yacc"
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
#line 806 "sql.yacc"
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
#line 814 "sql.yacc"
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
#line 822 "sql.yacc"
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
#line 830 "sql.yacc"
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
#line 842 "sql.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 50:

/* Line 1455 of yacc.c  */
#line 842 "sql.yacc"
    {strcpy((yyval.str),(yyvsp[(1) - (1)].str));}
    break;

  case 52:

/* Line 1455 of yacc.c  */
#line 846 "sql.yacc"
    {SPRINTF2((yyval.str),"%s%s",(yyvsp[(1) - (2)].str),(yyvsp[(2) - (2)].str));}
    break;

  case 53:

/* Line 1455 of yacc.c  */
#line 850 "sql.yacc"
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
#line 857 "sql.yacc"
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
#line 864 "sql.yacc"
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
#line 871 "sql.yacc"
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
#line 880 "sql.yacc"
    { strcpy(last_tmp_name,(yyvsp[(1) - (1)].str)); }
    break;

  case 58:

/* Line 1455 of yacc.c  */
#line 884 "sql.yacc"
    {SPRINTF7((yyval.str),"CREATE UNIQUE INDEX %s %s %s %s %s %s %s",(yyvsp[(2) - (8)].str),(yyvsp[(3) - (8)].str),(yyvsp[(4) - (8)].str),(yyvsp[(5) - (8)].str),(yyvsp[(6) - (8)].str),(yyvsp[(7) - (8)].str),(yyvsp[(8) - (8)].str));
		add_feature("CREATE_INDEX");
		add_feature("CREATE_INDEX_UNIQUE");
		if (strchr((yyvsp[(2) - (8)].str),'@') || strchr((yyvsp[(2) - (8)].str),':')) add_feature("CREATE_INDEX_QUALIFIED_PATH");
		if (strchr((yyvsp[(6) - (8)].str),',')) { add_feature("CREATE_INDEX_COMPOSITE"); }
	
}
    break;

  case 59:

/* Line 1455 of yacc.c  */
#line 891 "sql.yacc"
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
#line 903 "sql.yacc"
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
#line 914 "sql.yacc"
    {
		if (strchr((yyvsp[(2) - (8)].str),'@') || strchr((yyvsp[(2) - (8)].str),':')) add_feature("CREATE_INDEX_QUALIFIED_PATH");
		if (strchr((yyvsp[(6) - (8)].str),',')) { add_feature("CREATE_INDEX_COMPOSITE"); }
			add_feature("CREATE_INDEX");
			SPRINTF7((yyval.str)," CREATE INDEX %s %s %s %s %s %s %s",(yyvsp[(2) - (8)].str),(yyvsp[(3) - (8)].str),(yyvsp[(4) - (8)].str),(yyvsp[(5) - (8)].str),(yyvsp[(6) - (8)].str),(yyvsp[(7) - (8)].str),(yyvsp[(8) - (8)].str));
	}
    break;

  case 62:

/* Line 1455 of yacc.c  */
#line 920 "sql.yacc"
    {
		add_feature("CREATE_DATABASE");
		a4gl_yyerror("You cannot create a database from within Aubit4gl - if the target database allows - prepare and execute it manually");
	}
    break;

  case 63:

/* Line 1455 of yacc.c  */
#line 924 "sql.yacc"
    {
		add_feature("DROP_DATABASE");
		a4gl_yyerror("You cannot drop a database from within Aubit4gl - if the target database allows - prepare and execute it manually");
	}
    break;

  case 64:

/* Line 1455 of yacc.c  */
#line 928 "sql.yacc"
    { 
		if (strchr((yyvsp[(2) - (4)].str),'@') || strchr((yyvsp[(2) - (4)].str),':')) add_feature("CREATE_SYNONYM_QUALIFIED_PATH");
			add_feature("CREATE_SYNONYM");
			SPRINTF3((yyval.str),"%s %s FOR %s",(yyvsp[(1) - (4)].str),(yyvsp[(2) - (4)].str),(yyvsp[(4) - (4)].str)); 
	}
    break;

  case 65:

/* Line 1455 of yacc.c  */
#line 933 "sql.yacc"
    { 
		add_feature("CREATE_AUDIT");
		SPRINTF2((yyval.str),"CREATE AUDIT FOR %s IN '%s'",(yyvsp[(2) - (4)].str),A4GL_strip_quotes((yyvsp[(4) - (4)].str))); 
	}
    break;

  case 66:

/* Line 1455 of yacc.c  */
#line 937 "sql.yacc"
    { 
		add_feature("DROP_AUDIT");
		SPRINTF1((yyval.str),"DROP AUDIT FOR %s",(yyvsp[(2) - (2)].str)); }
    break;

  case 67:

/* Line 1455 of yacc.c  */
#line 940 "sql.yacc"
    { 
		if (strchr((yyvsp[(2) - (2)].str),'@') || strchr((yyvsp[(2) - (2)].str),':')) add_feature("DROP_SYNONYM_QUALIFIED_PATH");
		add_feature("DROP_SYNONYM");
		SPRINTF2((yyval.str),"%s %s",(yyvsp[(1) - (2)].str),(yyvsp[(2) - (2)].str)); }
    break;

  case 68:

/* Line 1455 of yacc.c  */
#line 944 "sql.yacc"
    { 
		add_feature("RECOVER_TABLE");
		SPRINTF1((yyval.str),"RECOVER TABLE %s",(yyvsp[(2) - (2)].str)); }
    break;

  case 69:

/* Line 1455 of yacc.c  */
#line 947 "sql.yacc"
    { 
		add_feature("ROLLFORWARD_DATABASE");
		SPRINTF1((yyval.str),"ROLLFORWARD DATABASE %s",(yyvsp[(2) - (2)].str)); }
    break;

  case 70:

/* Line 1455 of yacc.c  */
#line 954 "sql.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 71:

/* Line 1455 of yacc.c  */
#line 955 "sql.yacc"
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
#line 965 "sql.yacc"
    {(yyval.integer_val)=0;}
    break;

  case 73:

/* Line 1455 of yacc.c  */
#line 966 "sql.yacc"
    { (yyval.integer_val)=1;}
    break;

  case 75:

/* Line 1455 of yacc.c  */
#line 971 "sql.yacc"
    {SPRINTF2((yyval.str),"%s,%s",(yyvsp[(1) - (3)].str),(yyvsp[(3) - (3)].str));}
    break;

  case 76:

/* Line 1455 of yacc.c  */
#line 975 "sql.yacc"
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
#line 984 "sql.yacc"
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
#line 993 "sql.yacc"
    {
		strcpy((yyval.str),A4GL_confirm_colname(last_tmp_name,(yyvsp[(1) - (1)].str)));
}
    break;

  case 79:

/* Line 1455 of yacc.c  */
#line 1000 "sql.yacc"
    {
		(yyval.sql_string)=(yyvsp[(1) - (1)].sql_string);
	}
    break;

  case 80:

/* Line 1455 of yacc.c  */
#line 1003 "sql.yacc"
    {
		(yyval.sql_string)=make_sql_string_and_free((yyvsp[(1) - (3)].sql_string),kw_comma,strdup("\n"),(yyvsp[(3) - (3)].sql_string),NULL);
	}
    break;

  case 81:

/* Line 1455 of yacc.c  */
#line 1009 "sql.yacc"
    {
		(yyval.sql_string)=make_sql_string_and_free(strdup("   "),(yyvsp[(1) - (1)].sql_string),NULL);
	}
    break;

  case 82:

/* Line 1455 of yacc.c  */
#line 1012 "sql.yacc"
    {
		(yyval.sql_string)=make_sql_string_and_free(strdup("   "),(yyvsp[(1) - (1)].sql_string),NULL);
	}
    break;

  case 83:

/* Line 1455 of yacc.c  */
#line 1023 "sql.yacc"
    {
		add_feature("ALTER_TABLE");
	(yyval.sql_string)=make_sql_string_and_free(acl_strdup((yyvsp[(1) - (3)].str)),kw_space,acl_strdup((yyvsp[(2) - (3)].str)),kw_space,(yyvsp[(3) - (3)].sql_string),NULL);
	}
    break;

  case 84:

/* Line 1455 of yacc.c  */
#line 1027 "sql.yacc"
    {
		add_feature("CLUSTER_INDEX");
		add_feature("ALTER_INDEX_CLUSTER");
		(yyval.sql_string)=make_sql_string_and_free(acl_strdup("ALTER INDEX "),acl_strdup((yyvsp[(2) - (3)].str)),acl_strdup(" TO CLUSTER"),NULL);
		}
    break;

  case 85:

/* Line 1455 of yacc.c  */
#line 1032 "sql.yacc"
    {
		add_feature("ALTER_INDEX_NOT_CLUSTER");
		(yyval.sql_string)=make_sql_string_and_free(acl_strdup("ALTER INDEX "),acl_strdup((yyvsp[(2) - (3)].str)),acl_strdup(" TO NOT CLUSTER"),NULL);
		}
    break;

  case 86:

/* Line 1455 of yacc.c  */
#line 1039 "sql.yacc"
    {
		(yyval.sql_string)=(yyvsp[(1) - (1)].sql_string);
	}
    break;

  case 87:

/* Line 1455 of yacc.c  */
#line 1042 "sql.yacc"
    {
		(yyval.sql_string)=make_sql_string_and_free((yyvsp[(1) - (3)].sql_string),kw_comma,(yyvsp[(3) - (3)].sql_string),NULL);
	}
    break;

  case 88:

/* Line 1455 of yacc.c  */
#line 1051 "sql.yacc"
    {
		(yyval.sql_string)=(yyvsp[(1) - (1)].sql_string);
	}
    break;

  case 89:

/* Line 1455 of yacc.c  */
#line 1054 "sql.yacc"
    {
	add_feature("ALTER_TABLE_DROP");
		(yyval.sql_string)=acl_strdup((yyvsp[(1) - (1)].str));
	}
    break;

  case 90:

/* Line 1455 of yacc.c  */
#line 1058 "sql.yacc"
    {
	add_feature("ALTER_TABLE_MODIFY");
		(yyval.sql_string)=(yyvsp[(1) - (1)].sql_string);
	}
    break;

  case 91:

/* Line 1455 of yacc.c  */
#line 1062 "sql.yacc"
    {
		add_feature("ALTER_TABLE_ADD_CONSTRAINT");
		(yyval.sql_string)=acl_strdup((yyvsp[(1) - (1)].str));
	}
    break;

  case 92:

/* Line 1455 of yacc.c  */
#line 1066 "sql.yacc"
    {
		add_feature("ALTER_TABLE_DROP_CONSTRAINT");
		(yyval.sql_string)=acl_strdup((yyvsp[(1) - (1)].str));
	}
    break;

  case 93:

/* Line 1455 of yacc.c  */
#line 1070 "sql.yacc"
    {
		add_feature("ALTER_TABLE_MODIFY_NEXT");
		(yyval.sql_string)=acl_strdup((yyvsp[(1) - (1)].str));
	}
    break;

  case 94:

/* Line 1455 of yacc.c  */
#line 1074 "sql.yacc"
    {
		add_feature("ALTER_TABLE_LOCK_MODE");
		(yyval.sql_string)=acl_strdup((yyvsp[(1) - (1)].str));
	}
    break;

  case 95:

/* Line 1455 of yacc.c  */
#line 1082 "sql.yacc"
    {
		add_feature("ALTER_TABLE_ADD");
		(yyval.sql_string)=make_sql_string_and_free(acl_strdup("ADD "),(yyvsp[(2) - (2)].sql_string),NULL);
	}
    break;

  case 96:

/* Line 1455 of yacc.c  */
#line 1086 "sql.yacc"
    {
		add_feature("ALTER_TABLE_ADD");
		(yyval.sql_string)=make_sql_string_and_free(acl_strdup("ADD "),kw_ob,(yyvsp[(3) - (4)].sql_string),kw_cb,NULL);
	}
    break;

  case 97:

/* Line 1455 of yacc.c  */
#line 1094 "sql.yacc"
    {
		(yyval.sql_string)=(yyvsp[(1) - (1)].sql_string);
	}
    break;

  case 98:

/* Line 1455 of yacc.c  */
#line 1097 "sql.yacc"
    {
		add_feature("ALTER_TABLE_ADD_BEFORE");
		(yyval.sql_string)=make_sql_string_and_free((yyvsp[(1) - (3)].sql_string),acl_strdup(" BEFORE "),acl_strdup((yyvsp[(3) - (3)].str)),NULL);
	}
    break;

  case 99:

/* Line 1455 of yacc.c  */
#line 1104 "sql.yacc"
    {
		(yyval.sql_string)=(yyvsp[(1) - (1)].sql_string);
	}
    break;

  case 100:

/* Line 1455 of yacc.c  */
#line 1107 "sql.yacc"
    {
		(yyval.sql_string)=make_sql_string_and_free((yyvsp[(1) - (3)].sql_string),kw_comma,(yyvsp[(3) - (3)].sql_string),NULL);
	}
    break;

  case 101:

/* Line 1455 of yacc.c  */
#line 1114 "sql.yacc"
    {
		SPRINTF1((yyval.str),"DROP %s",(yyvsp[(2) - (2)].str));
	}
    break;

  case 102:

/* Line 1455 of yacc.c  */
#line 1117 "sql.yacc"
    {
		SPRINTF1((yyval.str),"DROP (%s)",(yyvsp[(3) - (4)].str));
	}
    break;

  case 104:

/* Line 1455 of yacc.c  */
#line 1125 "sql.yacc"
    {
		SPRINTF2((yyval.str),"%s,%s",(yyvsp[(1) - (3)].str),(yyvsp[(3) - (3)].str));
	}
    break;

  case 106:

/* Line 1455 of yacc.c  */
#line 1134 "sql.yacc"
    {
		(yyval.sql_string)=make_sql_string_and_free(acl_strdup("MODIFY "),(yyvsp[(2) - (2)].sql_string),NULL);
	}
    break;

  case 107:

/* Line 1455 of yacc.c  */
#line 1137 "sql.yacc"
    {
		(yyval.sql_string)=make_sql_string_and_free(acl_strdup("MODIFY "),kw_ob,(yyvsp[(3) - (4)].sql_string),kw_cb,NULL);
	}
    break;

  case 108:

/* Line 1455 of yacc.c  */
#line 1143 "sql.yacc"
    {
		(yyval.sql_string)=(yyvsp[(1) - (1)].sql_string);
	}
    break;

  case 109:

/* Line 1455 of yacc.c  */
#line 1146 "sql.yacc"
    {
		(yyval.sql_string)=make_sql_string_and_free((yyvsp[(1) - (3)].sql_string),kw_comma,(yyvsp[(3) - (3)].sql_string),NULL);
	}
    break;

  case 110:

/* Line 1455 of yacc.c  */
#line 1152 "sql.yacc"
    {
		(yyval.sql_string)=(yyvsp[(1) - (1)].sql_string);
	}
    break;

  case 111:

/* Line 1455 of yacc.c  */
#line 1159 "sql.yacc"
    {strcpy((yyval.str),"LOCK MODE (PAGE)");}
    break;

  case 112:

/* Line 1455 of yacc.c  */
#line 1160 "sql.yacc"
    {strcpy((yyval.str),"LOCK MODE (ROW)");}
    break;

  case 113:

/* Line 1455 of yacc.c  */
#line 1164 "sql.yacc"
    {
		add_feature("DDL_NEXT_SIZE");
		SPRINTF1((yyval.str),"MODIFY NEXT SIZE %d",atoi((yyvsp[(2) - (2)].str)));
	}
    break;

  case 114:

/* Line 1455 of yacc.c  */
#line 1172 "sql.yacc"
    {
		add_feature("DDL_CONSTRAINT");
		SPRINTF2((yyval.str),"ADD CONSTRAINT %s%s",(yyvsp[(2) - (3)].sql_string),(yyvsp[(3) - (3)].str));
	}
    break;

  case 115:

/* Line 1455 of yacc.c  */
#line 1176 "sql.yacc"
    {
		add_feature("ADD_CONSTRAINT");
		SPRINTF1((yyval.str),"ADD CONSTRAINT (%s)",(yyvsp[(3) - (4)].sql_string));
	}
    break;

  case 116:

/* Line 1455 of yacc.c  */
#line 1183 "sql.yacc"
    {
		(yyval.sql_string)=make_sql_string_and_free((yyvsp[(1) - (2)].sql_string),acl_strdup((yyvsp[(2) - (2)].str)),NULL);
}
    break;

  case 117:

/* Line 1455 of yacc.c  */
#line 1185 "sql.yacc"
    {
	(yyval.sql_string)=make_sql_string_and_free((yyvsp[(1) - (4)].sql_string),kw_comma,(yyvsp[(3) - (4)].sql_string),acl_strdup((yyvsp[(4) - (4)].str)), NULL);
}
    break;

  case 118:

/* Line 1455 of yacc.c  */
#line 1190 "sql.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 119:

/* Line 1455 of yacc.c  */
#line 1191 "sql.yacc"
    {SPRINTF2((yyval.str)," %s %s",(yyvsp[(1) - (2)].str),(yyvsp[(2) - (2)].str)); add_feature("DDL_CONSTRAINT");}
    break;

  case 120:

/* Line 1455 of yacc.c  */
#line 1196 "sql.yacc"
    { SPRINTF1((yyval.str),"DROP CONSTRAINT %s",(yyvsp[(2) - (2)].str)); add_feature("DROP_CONSTRAINT"); }
    break;

  case 121:

/* Line 1455 of yacc.c  */
#line 1197 "sql.yacc"
    {add_feature("DROP_CONSTRAINT");
		SPRINTF1((yyval.str),"DROP CONSTRAINT (%s)",(yyvsp[(3) - (4)].str));
	}
    break;

  case 122:

/* Line 1455 of yacc.c  */
#line 1203 "sql.yacc"
    {strcpy((yyval.str),(yyvsp[(1) - (1)].str));}
    break;

  case 123:

/* Line 1455 of yacc.c  */
#line 1204 "sql.yacc"
    {SPRINTF2((yyval.str),"%s,%s",(yyvsp[(1) - (3)].str),(yyvsp[(3) - (3)].str));}
    break;

  case 125:

/* Line 1455 of yacc.c  */
#line 1218 "sql.yacc"
    {  add_feature("ROLLBACK_WORK"); }
    break;

  case 126:

/* Line 1455 of yacc.c  */
#line 1224 "sql.yacc"
    { insql=1;}
    break;

  case 127:

/* Line 1455 of yacc.c  */
#line 1224 "sql.yacc"
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
#line 1233 "sql.yacc"
    {insql=1;}
    break;

  case 129:

/* Line 1455 of yacc.c  */
#line 1233 "sql.yacc"
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
#line 1242 "sql.yacc"
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
#line 1267 "sql.yacc"
    {
			(yyval.str_list)=0;
	}
    break;

  case 132:

/* Line 1455 of yacc.c  */
#line 1270 "sql.yacc"
    {
			(yyval.str_list)=(yyvsp[(2) - (3)].str_list);
			 add_feature("INSERT_COLUMNLIST_EQ_VALUELIST");
	}
    break;

  case 133:

/* Line 1455 of yacc.c  */
#line 1278 "sql.yacc"
    {
                        (yyval.str_list)=new_str_list((yyvsp[(1) - (1)].str));
	}
    break;

  case 134:

/* Line 1455 of yacc.c  */
#line 1281 "sql.yacc"
    {
                        (yyval.str_list)=add_str_list((yyvsp[(1) - (3)].str_list), (yyvsp[(3) - (3)].str));
	}
    break;

  case 135:

/* Line 1455 of yacc.c  */
#line 1288 "sql.yacc"
    {	
			strcpy((yyval.str),(yyvsp[(1) - (1)].str));
	}
    break;

  case 136:

/* Line 1455 of yacc.c  */
#line 1291 "sql.yacc"
    { 
			/* with a table prefix - on an insert ? We'll just silently drop it... */
			strcpy((yyval.str),(yyvsp[(3) - (3)].str));
			A4GL_warn("Dropped table prefix from INSERT column name");
	}
    break;

  case 137:

/* Line 1455 of yacc.c  */
#line 1299 "sql.yacc"
    { (yyval.s_select_list_item_list)=local_new_select_list_item_list((yyvsp[(1) - (1)].s_select_list_item));}
    break;

  case 138:

/* Line 1455 of yacc.c  */
#line 1300 "sql.yacc"
    {
		(yyval.s_select_list_item_list)=local_add_select_list_item_list((yyvsp[(1) - (3)].s_select_list_item_list),(yyvsp[(3) - (3)].s_select_list_item));
	}
    break;

  case 139:

/* Line 1455 of yacc.c  */
#line 1306 "sql.yacc"
    {(yyval.s_select_list_item)=(yyvsp[(1) - (1)].s_select_list_item);}
    break;

  case 140:

/* Line 1455 of yacc.c  */
#line 1307 "sql.yacc"
    {(yyval.s_select_list_item)=new_select_list_item_builtin_const(E_SLI_BUILTIN_CONST_NULL); }
    break;

  case 141:

/* Line 1455 of yacc.c  */
#line 1315 "sql.yacc"
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
#line 1333 "sql.yacc"
    { add_feature("BEGIN_WORK"); }
    break;

  case 143:

/* Line 1455 of yacc.c  */
#line 1337 "sql.yacc"
    { add_feature("COMMIT_WORK"); }
    break;

  case 144:

/* Line 1455 of yacc.c  */
#line 1342 "sql.yacc"
    {(yyval.e_boolean)=EB_FALSE;}
    break;

  case 145:

/* Line 1455 of yacc.c  */
#line 1343 "sql.yacc"
    {
		add_feature("DATABASE_EXCLUSIVE");
		{(yyval.e_boolean)=EB_TRUE;}
	}
    break;

  case 146:

/* Line 1455 of yacc.c  */
#line 1353 "sql.yacc"
    {
	char buff[256];
	(yyval.sql_string)=make_sql_string_and_free(acl_strdup((yyvsp[(1) - (1)].str)),NULL);
	SPRINTF1(buff,"Warning: Informix specific SQL @ line %d\n",yylineno);
	ansi_violation(buff,1);
	}
    break;

  case 147:

/* Line 1455 of yacc.c  */
#line 1362 "sql.yacc"
    {
			add_feature("START_DATABASE_WITH_LOG_MODE_ANSI");
			sprintf((yyval.str),"START DATABASE %s WITH LOG IN %s MODE ANSI", (yyvsp[(2) - (5)].str),(yyvsp[(4) - (5)].str));
	}
    break;

  case 148:

/* Line 1455 of yacc.c  */
#line 1366 "sql.yacc"
    {
			add_feature("START_DATABASE_WITH_LOG");
			sprintf((yyval.str),"START DATABASE %s WITH LOG IN %s", (yyvsp[(2) - (4)].str),(yyvsp[(4) - (4)].str));
	}
    break;

  case 149:

/* Line 1455 of yacc.c  */
#line 1371 "sql.yacc"
    {
			add_feature("SET_CONSTRAINTS_ALL_IMMEDIATE");
			SPRINTF1((yyval.str),"%s",(yyvsp[(1) - (1)].str)); 
	}
    break;

  case 150:

/* Line 1455 of yacc.c  */
#line 1375 "sql.yacc"
    {
		add_feature("SET_BUFFERED_LOG");
			SPRINTF1((yyval.str),"%s",(yyvsp[(1) - (1)].str)); 
	}
    break;

  case 151:

/* Line 1455 of yacc.c  */
#line 1379 "sql.yacc"
    {
		add_feature("SET_LOG");
			SPRINTF1((yyval.str),"%s",(yyvsp[(1) - (1)].str)); 
	}
    break;

  case 152:

/* Line 1455 of yacc.c  */
#line 1383 "sql.yacc"
    {
			SPRINTF2((yyval.str),"%s %s",(yyvsp[(1) - (2)].str),(yyvsp[(2) - (2)].str)); add_feature("UPDATE_STATISTICS_TABLE");
	}
    break;

  case 153:

/* Line 1455 of yacc.c  */
#line 1386 "sql.yacc"
    {
		add_feature("UPDATE_STATISTICS");
			SPRINTF1((yyval.str),"%s",(yyvsp[(1) - (1)].str)); 
	}
    break;

  case 154:

/* Line 1455 of yacc.c  */
#line 1393 "sql.yacc"
    { (yyval.integer_val)=1; }
    break;

  case 155:

/* Line 1455 of yacc.c  */
#line 1394 "sql.yacc"
    { (yyval.integer_val)=-1; }
    break;

  case 156:

/* Line 1455 of yacc.c  */
#line 1395 "sql.yacc"
    { (yyval.integer_val)=0; }
    break;

  case 157:

/* Line 1455 of yacc.c  */
#line 1399 "sql.yacc"
    { (yyval.sql_string)=(yyvsp[(1) - (1)].sql_string); }
    break;

  case 158:

/* Line 1455 of yacc.c  */
#line 1400 "sql.yacc"
    { (yyval.sql_string)=(yyvsp[(1) - (1)].sql_string); }
    break;

  case 159:

/* Line 1455 of yacc.c  */
#line 1401 "sql.yacc"
    { (yyval.sql_string)=(yyvsp[(1) - (1)].sql_string); }
    break;

  case 160:

/* Line 1455 of yacc.c  */
#line 1402 "sql.yacc"
    { (yyval.sql_string)=(yyvsp[(1) - (1)].sql_string); }
    break;

  case 161:

/* Line 1455 of yacc.c  */
#line 1403 "sql.yacc"
    { (yyval.sql_string)=(yyvsp[(1) - (1)].sql_string); }
    break;

  case 162:

/* Line 1455 of yacc.c  */
#line 1404 "sql.yacc"
    { (yyval.sql_string)=(yyvsp[(1) - (1)].sql_string); }
    break;

  case 163:

/* Line 1455 of yacc.c  */
#line 1405 "sql.yacc"
    { (yyval.sql_string)=(yyvsp[(1) - (1)].sql_string); }
    break;

  case 164:

/* Line 1455 of yacc.c  */
#line 1413 "sql.yacc"
    {SPRINTF7((yyval.str),"%s %s %s %s %s %s %s",(yyvsp[(1) - (7)].str),(yyvsp[(2) - (7)].str),(yyvsp[(3) - (7)].str),(yyvsp[(4) - (7)].str),(yyvsp[(5) - (7)].str),(yyvsp[(6) - (7)].str),(yyvsp[(7) - (7)].str));  add_feature("GRANT"); }
    break;

  case 165:

/* Line 1455 of yacc.c  */
#line 1414 "sql.yacc"
    {SPRINTF6((yyval.str),"%s %s %s %s %s %s",(yyvsp[(1) - (6)].str),(yyvsp[(2) - (6)].str),(yyvsp[(3) - (6)].str),(yyvsp[(4) - (6)].str),(yyvsp[(5) - (6)].str),(yyvsp[(6) - (6)].str));  add_feature("REVOKE"); }
    break;

  case 166:

/* Line 1455 of yacc.c  */
#line 1415 "sql.yacc"
    {SPRINTF4((yyval.str),"%s %s %s %s ",(yyvsp[(1) - (4)].str),(yyvsp[(2) - (4)].str),(yyvsp[(3) - (4)].str),(yyvsp[(4) - (4)].str)); add_feature("GRANT"); }
    break;

  case 167:

/* Line 1455 of yacc.c  */
#line 1416 "sql.yacc"
    {SPRINTF4((yyval.str),"%s %s %s %s ",(yyvsp[(1) - (4)].str),(yyvsp[(2) - (4)].str),(yyvsp[(3) - (4)].str),(yyvsp[(4) - (4)].str));  add_feature("REVOKE"); }
    break;

  case 171:

/* Line 1455 of yacc.c  */
#line 1426 "sql.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 172:

/* Line 1455 of yacc.c  */
#line 1427 "sql.yacc"
    {SPRINTF1((yyval.str)," %s ",(yyvsp[(1) - (1)].str));}
    break;

  case 173:

/* Line 1455 of yacc.c  */
#line 1428 "sql.yacc"
    {SPRINTF2((yyval.str)," %s %s",(yyvsp[(1) - (2)].str),(yyvsp[(2) - (2)].str));}
    break;

  case 174:

/* Line 1455 of yacc.c  */
#line 1432 "sql.yacc"
    {SPRINTF1((yyval.str)," %s ",(yyvsp[(1) - (1)].str));}
    break;

  case 175:

/* Line 1455 of yacc.c  */
#line 1433 "sql.yacc"
    {SPRINTF1((yyval.str)," %s ",(yyvsp[(1) - (1)].str));}
    break;

  case 178:

/* Line 1455 of yacc.c  */
#line 1440 "sql.yacc"
    {SPRINTF3((yyval.str)," %s %s %s",(yyvsp[(1) - (3)].str),(yyvsp[(2) - (3)].str),(yyvsp[(3) - (3)].str));}
    break;

  case 179:

/* Line 1455 of yacc.c  */
#line 1443 "sql.yacc"
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
#line 1452 "sql.yacc"
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
#line 1463 "sql.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 186:

/* Line 1455 of yacc.c  */
#line 1465 "sql.yacc"
    {SPRINTF3((yyval.str)," %s %s %s",(yyvsp[(1) - (3)].str),(yyvsp[(2) - (3)].str),(yyvsp[(3) - (3)].str));}
    break;

  case 188:

/* Line 1455 of yacc.c  */
#line 1471 "sql.yacc"
    {SPRINTF3((yyval.str)," %s %s %s",(yyvsp[(1) - (3)].str),(yyvsp[(2) - (3)].str),(yyvsp[(3) - (3)].str));}
    break;

  case 190:

/* Line 1455 of yacc.c  */
#line 1477 "sql.yacc"
    {SPRINTF3((yyval.str)," %s %s %s",(yyvsp[(1) - (3)].str),(yyvsp[(2) - (3)].str),(yyvsp[(3) - (3)].str));}
    break;

  case 193:

/* Line 1455 of yacc.c  */
#line 1487 "sql.yacc"
    {
		add_feature("CREATE_VIEW_AS_SELECT");
		(yyval.sql_string)=make_sql_string_and_free(acl_strdup((yyvsp[(1) - (6)].str)),kw_space,acl_strdup((yyvsp[(2) - (6)].str)),kw_space,acl_strdup((yyvsp[(3) - (6)].str)),kw_space,acl_strdup((yyvsp[(4) - (6)].str)),kw_space,(yyvsp[(5) - (6)].sql_string),kw_space,acl_strdup((yyvsp[(6) - (6)].str)),NULL);
	
}
    break;

  case 194:

/* Line 1455 of yacc.c  */
#line 1494 "sql.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 195:

/* Line 1455 of yacc.c  */
#line 1496 "sql.yacc"
    {SPRINTF3((yyval.str)," %s %s %s",(yyvsp[(1) - (3)].str),(yyvsp[(2) - (3)].str),(yyvsp[(3) - (3)].str));}
    break;

  case 197:

/* Line 1455 of yacc.c  */
#line 1502 "sql.yacc"
    {SPRINTF3((yyval.str)," %s %s %s",(yyvsp[(1) - (3)].str),(yyvsp[(2) - (3)].str),(yyvsp[(3) - (3)].str));}
    break;

  case 198:

/* Line 1455 of yacc.c  */
#line 1505 "sql.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 199:

/* Line 1455 of yacc.c  */
#line 1506 "sql.yacc"
    {
		add_feature("CREATE_VIEW_SELECT_WITH_CHECK");
	}
    break;

  case 200:

/* Line 1455 of yacc.c  */
#line 1513 "sql.yacc"
    {
		(yyval.sql_string)=make_sql_string_and_free(strdup("CHECK ("),(yyvsp[(3) - (4)].sql_string),kw_cb,NULL);
		add_feature("DDL_CHECK");
	}
    break;

  case 201:

/* Line 1455 of yacc.c  */
#line 1522 "sql.yacc"
    {SPRINTF5((yyval.str)," %s %s %s %s %s",(yyvsp[(1) - (5)].str),(yyvsp[(2) - (5)].str),(yyvsp[(3) - (5)].str),(yyvsp[(4) - (5)].str),(yyvsp[(5) - (5)].str));
	add_feature("DDL_FOREIGN_KEY");
}
    break;

  case 202:

/* Line 1455 of yacc.c  */
#line 1529 "sql.yacc"
    {SPRINTF2((yyval.str)," %s %s",(yyvsp[(1) - (2)].str),(yyvsp[(2) - (2)].str));
add_feature("DDL_REFERENCES");
}
    break;

  case 205:

/* Line 1455 of yacc.c  */
#line 1541 "sql.yacc"
    {SPRINTF4((yyval.str)," %s %s %s %s",(yyvsp[(1) - (4)].str),(yyvsp[(2) - (4)].str),(yyvsp[(3) - (4)].str),(yyvsp[(4) - (4)].str));}
    break;

  case 207:

/* Line 1455 of yacc.c  */
#line 1547 "sql.yacc"
    {SPRINTF3((yyval.str)," %s %s %s",(yyvsp[(1) - (3)].str),(yyvsp[(2) - (3)].str),(yyvsp[(3) - (3)].str));}
    break;

  case 208:

/* Line 1455 of yacc.c  */
#line 1552 "sql.yacc"
    {
		SPRINTF3((yyval.str)," UNIQUE %s %s %s",(yyvsp[(2) - (4)].str),(yyvsp[(3) - (4)].str),(yyvsp[(4) - (4)].str));
add_feature("DDL_UNIQUE");
	}
    break;

  case 209:

/* Line 1455 of yacc.c  */
#line 1556 "sql.yacc"
    {
		ansi_violation("Use UNIQUE not DISTINCT",0);
		SPRINTF3((yyval.str)," UNIQUE %s %s %s",(yyvsp[(2) - (4)].str),(yyvsp[(3) - (4)].str),(yyvsp[(4) - (4)].str));
add_feature("DDL_DISTINCT");
	}
    break;

  case 210:

/* Line 1455 of yacc.c  */
#line 1562 "sql.yacc"
    {SPRINTF4((yyval.str)," %s %s %s %s",(yyvsp[(1) - (4)].str),(yyvsp[(2) - (4)].str),(yyvsp[(3) - (4)].str),(yyvsp[(4) - (4)].str));
add_feature("DDL_PRIMARY_KEY");
}
    break;

  case 212:

/* Line 1455 of yacc.c  */
#line 1570 "sql.yacc"
    {SPRINTF3((yyval.str)," %s %s %s",(yyvsp[(1) - (3)].str),(yyvsp[(2) - (3)].str),(yyvsp[(3) - (3)].str));}
    break;

  case 213:

/* Line 1455 of yacc.c  */
#line 1575 "sql.yacc"
    {
		(yyval.sql_string)=acl_strdup((yyvsp[(1) - (1)].str));
	}
    break;

  case 214:

/* Line 1455 of yacc.c  */
#line 1578 "sql.yacc"
    {
		(yyval.sql_string)=acl_strdup((yyvsp[(1) - (1)].str));
	}
    break;

  case 215:

/* Line 1455 of yacc.c  */
#line 1581 "sql.yacc"
    {
		(yyval.sql_string)=(yyvsp[(1) - (1)].sql_string);
	}
    break;

  case 216:

/* Line 1455 of yacc.c  */
#line 1588 "sql.yacc"
    {SPRINTF2((yyval.str)," %s %s",(yyvsp[(1) - (2)].str),(yyvsp[(2) - (2)].str)); add_feature("DDL_DEFAULT_VALUE"); }
    break;

  case 217:

/* Line 1455 of yacc.c  */
#line 1589 "sql.yacc"
    {SPRINTF1((yyval.str)," DEFAULT %s", A4GLSQLCV_get_sqlconst("USER")); add_feature("DDL_DEFAULT_VALUE"); }
    break;

  case 218:

/* Line 1455 of yacc.c  */
#line 1590 "sql.yacc"
    {SPRINTF1((yyval.str)," DEFAULT %s", A4GLSQLCV_get_sqlconst("TODAY")); add_feature("DDL_DEFAULT_VALUE"); }
    break;

  case 219:

/* Line 1455 of yacc.c  */
#line 1591 "sql.yacc"
    { SPRINTF1((yyval.str)," %s",(yyvsp[(1) - (1)].str)); add_feature("DDL_DEFAULT_VALUE"); }
    break;

  case 220:

/* Line 1455 of yacc.c  */
#line 1597 "sql.yacc"
    {

			A4GL_debug("Str1:%s",(yyvsp[(1) - (4)].str));
			A4GL_debug("Str2:%s",(yyvsp[(2) - (4)].str));
			A4GL_debug("Str3:%s",(yyvsp[(3) - (4)].str));
			A4GL_debug("Str4:%s",(yyvsp[(4) - (4)].sql_string));

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
#line 1618 "sql.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 223:

/* Line 1455 of yacc.c  */
#line 1622 "sql.yacc"
    {
		(yyval.sql_string)=acl_strdup("");
	}
    break;

  case 224:

/* Line 1455 of yacc.c  */
#line 1624 "sql.yacc"
    {
		(yyval.sql_string)=(yyvsp[(1) - (1)].sql_string);
	}
    break;

  case 225:

/* Line 1455 of yacc.c  */
#line 1631 "sql.yacc"
    {
		(yyval.sql_string)=(yyvsp[(1) - (1)].sql_string);
	}
    break;

  case 226:

/* Line 1455 of yacc.c  */
#line 1634 "sql.yacc"
    {
		(yyval.sql_string)=make_sql_string_and_free((yyvsp[(1) - (2)].sql_string),kw_space,(yyvsp[(2) - (2)].sql_string),NULL);
	}
    break;

  case 227:

/* Line 1455 of yacc.c  */
#line 1640 "sql.yacc"
    {
		(yyval.sql_string)=make_sql_string_and_free((yyvsp[(1) - (2)].sql_string),acl_strdup((yyvsp[(2) - (2)].str)),NULL);
	}
    break;

  case 228:

/* Line 1455 of yacc.c  */
#line 1648 "sql.yacc"
    {
		SPRINTF1((yyval.str)," %s ",(yyvsp[(1) - (1)].str));
		(yyval.sql_string)=acl_strdup((yyval.str));
		add_feature("DDL_NOT_NULL");
	}
    break;

  case 229:

/* Line 1455 of yacc.c  */
#line 1653 "sql.yacc"
    {
		SPRINTF0((yyval.str)," NOT NULL UNIQUE ");
		(yyval.sql_string)=acl_strdup((yyval.str));
		add_feature("DDL_NOT_NULL");
		add_feature("DDL_UNIQUE");
	}
    break;

  case 230:

/* Line 1455 of yacc.c  */
#line 1659 "sql.yacc"
    {
		SPRINTF0((yyval.str)," UNIQUE ");
		(yyval.sql_string)=acl_strdup((yyval.str));
		add_feature("DDL_UNIQUE");
	}
    break;

  case 231:

/* Line 1455 of yacc.c  */
#line 1664 "sql.yacc"
    {
		ansi_violation("Use UNIQUE not DISTINCT",0);
		SPRINTF0((yyval.str)," UNIQUE ");
		(yyval.sql_string)=acl_strdup((yyval.str));
		add_feature("DDL_DISTINCT");
	}
    break;

  case 232:

/* Line 1455 of yacc.c  */
#line 1670 "sql.yacc"
    {
		(yyval.sql_string)=acl_strdup((yyvsp[(1) - (1)].str));
	}
    break;

  case 233:

/* Line 1455 of yacc.c  */
#line 1673 "sql.yacc"
    {
		(yyval.sql_string)=make_sql_string_and_free(acl_strdup("CHECK ("),(yyvsp[(3) - (4)].sql_string),kw_cb,NULL);
		add_feature("DDL_CHECK");
		
	}
    break;

  case 234:

/* Line 1455 of yacc.c  */
#line 1678 "sql.yacc"
    {
		(yyval.sql_string)=make_sql_string_and_free(acl_strdup(" PRIMARY KEY "),NULL);
		add_feature("DDL_PRIMARY_KEY");
	}
    break;

  case 235:

/* Line 1455 of yacc.c  */
#line 1687 "sql.yacc"
    {
		add_feature("CREATE_SCHEMA");

(yyval.sql_string)=make_sql_string_and_free(acl_strdup((yyvsp[(1) - (3)].str)),kw_space,acl_strdup((yyvsp[(2) - (3)].str)),kw_space,acl_strdup((yyvsp[(3) - (3)].str)),NULL);
}
    break;

  case 236:

/* Line 1455 of yacc.c  */
#line 1696 "sql.yacc"
    {SPRINTF1((yyval.str)," %s",(yyvsp[(1) - (1)].str));}
    break;

  case 239:

/* Line 1455 of yacc.c  */
#line 1705 "sql.yacc"
    {
		(yyval.sql_string)=make_sql_string_and_free((yyvsp[(1) - (2)].sql_string),kw_space,(yyvsp[(2) - (2)].sql_string),NULL);
	}
    break;

  case 240:

/* Line 1455 of yacc.c  */
#line 1711 "sql.yacc"
    {
		(yyval.sql_string)=(yyvsp[(1) - (1)].sql_string);
	}
    break;

  case 241:

/* Line 1455 of yacc.c  */
#line 1714 "sql.yacc"
    {
		(yyval.sql_string)=acl_strdup((yyvsp[(1) - (1)].str));
	}
    break;

  case 242:

/* Line 1455 of yacc.c  */
#line 1725 "sql.yacc"
    {
		 add_feature("HAVING"); 
		(yyval.s_select_list_item)=(yyvsp[(2) - (2)].s_select_list_item);
	}
    break;

  case 243:

/* Line 1455 of yacc.c  */
#line 1734 "sql.yacc"
    {
		 (yyval.s_select_list_item)=(yyvsp[(2) - (2)].s_select_list_item);
	}
    break;

  case 244:

/* Line 1455 of yacc.c  */
#line 1741 "sql.yacc"
    {
		(yyval.u_table)=(yyvsp[(2) - (2)].u_table);
	}
    break;

  case 245:

/* Line 1455 of yacc.c  */
#line 1747 "sql.yacc"
    {(yyval.u_table)=(yyvsp[(1) - (1)].u_table);}
    break;

  case 246:

/* Line 1455 of yacc.c  */
#line 1748 "sql.yacc"
    {
		(yyval.u_table)=A4GLSQLPARSE_append_tablename((yyvsp[(1) - (3)].u_table),(yyvsp[(3) - (3)].u_table),E_OUTER_NONE,NULL);
	}
    break;

  case 247:

/* Line 1455 of yacc.c  */
#line 1751 "sql.yacc"
    {
		(yyval.u_table)=A4GLSQLPARSE_append_tablename((yyvsp[(1) - (4)].u_table),(yyvsp[(4) - (4)].u_table),E_OUTER_NORMAL,NULL);
		A4GL_warn("OUTER join *may* not be portable to non-informix database");
		add_feature("SELECT_OUTER");
	}
    break;

  case 248:

/* Line 1455 of yacc.c  */
#line 1756 "sql.yacc"
    {
		(yyval.u_table)=A4GLSQLPARSE_append_tablename((yyvsp[(1) - (6)].u_table),(yyvsp[(5) - (6)].u_table),E_OUTER_NORMAL,NULL);
		A4GL_warn("OUTER join *may* not be portable to non-informix database");
		add_feature("SELECT_OUTER");
	}
    break;

  case 249:

/* Line 1455 of yacc.c  */
#line 1767 "sql.yacc"
    {
		(yyval.u_table)=A4GLSQLPARSE_append_tablename((yyvsp[(1) - (5)].u_table),(yyvsp[(3) - (5)].u_table),E_OUTER_LEFT_OUTER, (yyvsp[(5) - (5)].s_select_list_item));
		add_feature("SELECT_OUTER");
	}
    break;

  case 250:

/* Line 1455 of yacc.c  */
#line 1771 "sql.yacc"
    {
		(yyval.u_table)=A4GLSQLPARSE_append_tablename((yyvsp[(1) - (5)].u_table),(yyvsp[(3) - (5)].u_table),E_INNER, (yyvsp[(5) - (5)].s_select_list_item));
		add_feature("SELECT_INNER");
	}
    break;

  case 252:

/* Line 1455 of yacc.c  */
#line 1779 "sql.yacc"
    {(yyval.u_table)=(yyvsp[(2) - (3)].u_table);}
    break;

  case 253:

/* Line 1455 of yacc.c  */
#line 1783 "sql.yacc"
    { 
			//A4GL_add_crud("SELECT",$<str>1);
			(yyval.u_table)=A4GLSQLPARSE_new_tablename((yyvsp[(1) - (1)].str),NULL);
	}
    break;

  case 254:

/* Line 1455 of yacc.c  */
#line 1787 "sql.yacc"
    { 
			//A4GL_add_crud("SELECT",$<str>1);
			(yyval.u_table)=A4GLSQLPARSE_new_tablename((yyvsp[(1) - (2)].str),(yyvsp[(2) - (2)].str));
	}
    break;

  case 255:

/* Line 1455 of yacc.c  */
#line 1791 "sql.yacc"
    { 
			//A4GL_add_crud("SELECT",$<str>1);
			(yyval.u_table)=A4GLSQLPARSE_new_tablename((yyvsp[(1) - (3)].str),(yyvsp[(3) - (3)].str));
	}
    break;

  case 256:

/* Line 1455 of yacc.c  */
#line 1798 "sql.yacc"
    {
			/* No from or where etc.. */
			/* eg.. select user ; */
			(yyval.s_select)=new_empty_select();
		}
    break;

  case 257:

/* Line 1455 of yacc.c  */
#line 1803 "sql.yacc"
    {
		(yyval.s_select)=(yyvsp[(2) - (2)].s_select);
		(yyval.s_select)->first=(yyvsp[(1) - (2)].u_table);
			A4GL_set_associated_mem( (yyval.s_select), (yyval.s_select)->first);
}
    break;

  case 258:

/* Line 1455 of yacc.c  */
#line 1811 "sql.yacc"
    {
		(yyval.s_select)=(yyvsp[(1) - (1)].s_select);
	}
    break;

  case 259:

/* Line 1455 of yacc.c  */
#line 1814 "sql.yacc"
    {
		(yyval.s_select)=(yyvsp[(2) - (2)].s_select);
		(yyval.s_select)->where_clause=(yyvsp[(1) - (2)].s_select_list_item);
	}
    break;

  case 260:

/* Line 1455 of yacc.c  */
#line 1820 "sql.yacc"
    {
		(yyval.s_select)=new_empty_select();
	}
    break;

  case 261:

/* Line 1455 of yacc.c  */
#line 1823 "sql.yacc"
    {
		(yyval.s_select)=new_empty_select();
		(yyval.s_select)->group_by=(yyvsp[(1) - (1)].s_select_list_item_list);
		(yyval.s_select)->having=0;
	}
    break;

  case 262:

/* Line 1455 of yacc.c  */
#line 1828 "sql.yacc"
    {
		(yyval.s_select)=new_empty_select();
		(yyval.s_select)->group_by=(yyvsp[(1) - (2)].s_select_list_item_list);
		(yyval.s_select)->having=(yyvsp[(2) - (2)].s_select_list_item);
	}
    break;

  case 263:

/* Line 1455 of yacc.c  */
#line 1833 "sql.yacc"
    {
		(yyval.s_select)=new_empty_select();
		(yyval.s_select)->group_by=0;
		(yyval.s_select)->having=(yyvsp[(1) - (1)].s_select_list_item);

	}
    break;

  case 264:

/* Line 1455 of yacc.c  */
#line 1846 "sql.yacc"
    {
		(yyval.s_select_list_item)=(yyvsp[(1) - (1)].s_select_list_item);
	}
    break;

  case 265:

/* Line 1455 of yacc.c  */
#line 1849 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_op_expr((yyvsp[(1) - (3)].s_select_list_item),(yyvsp[(3) - (3)].s_select_list_item)," OR ");
	}
    break;

  case 266:

/* Line 1455 of yacc.c  */
#line 1855 "sql.yacc"
    {
		(yyval.s_select_list_item)=(yyvsp[(1) - (1)].s_select_list_item);
	}
    break;

  case 267:

/* Line 1455 of yacc.c  */
#line 1858 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_op_expr((yyvsp[(1) - (3)].s_select_list_item),(yyvsp[(3) - (3)].s_select_list_item)," AND ");
	}
    break;

  case 268:

/* Line 1455 of yacc.c  */
#line 1864 "sql.yacc"
    {
		(yyval.s_select_list_item)=(yyvsp[(1) - (1)].s_select_list_item);
	}
    break;

  case 269:

/* Line 1455 of yacc.c  */
#line 1867 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_simple_expr(E_SLI_NOT,(yyvsp[(2) - (2)].s_select_list_item));
	}
    break;

  case 270:

/* Line 1455 of yacc.c  */
#line 1873 "sql.yacc"
    {
		(yyval.s_select_list_item)=(yyvsp[(1) - (1)].s_select_list_item);
	}
    break;

  case 271:

/* Line 1455 of yacc.c  */
#line 1876 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_simple_expr(E_SLI_BRACKET_EXPR,(yyvsp[(2) - (3)].s_select_list_item));
	}
    break;

  case 272:

/* Line 1455 of yacc.c  */
#line 1883 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_sq(E_SQE_EXISTS, (yyvsp[(2) - (2)].s_select_list_item));
		add_feature("WHERE_EXISTS");
	}
    break;

  case 273:

/* Line 1455 of yacc.c  */
#line 1887 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_sq(E_SQE_NOT_EXISTS, (yyvsp[(2) - (2)].s_select_list_item));
		add_feature("WHERE_EXISTS");
	}
    break;

  case 274:

/* Line 1455 of yacc.c  */
#line 1898 "sql.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 275:

/* Line 1455 of yacc.c  */
#line 1898 "sql.yacc"
    {SPRINTF1((yyval.str)," ESCAPE %s",(yyvsp[(2) - (2)].str));add_feature("WHERE_MATCHES_ESCAPE");}
    break;

  case 276:

/* Line 1455 of yacc.c  */
#line 1899 "sql.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 277:

/* Line 1455 of yacc.c  */
#line 1899 "sql.yacc"
    {SPRINTF1((yyval.str)," ESCAPE %s",(yyvsp[(2) - (2)].str));add_feature("WHERE_ILIKE_ESCAPE");}
    break;

  case 278:

/* Line 1455 of yacc.c  */
#line 1900 "sql.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 279:

/* Line 1455 of yacc.c  */
#line 1900 "sql.yacc"
    {SPRINTF1((yyval.str)," ESCAPE %s",(yyvsp[(2) - (2)].str));add_feature("WHERE_LIKE_ESCAPE");}
    break;

  case 280:

/* Line 1455 of yacc.c  */
#line 1903 "sql.yacc"
    {
		 (yyval.s_select_list_item)=(yyvsp[(1) - (1)].s_select_list_item);
	}
    break;

  case 282:

/* Line 1455 of yacc.c  */
#line 1913 "sql.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 283:

/* Line 1455 of yacc.c  */
#line 1914 "sql.yacc"
    {strcpy((yyval.str)," NOT ");}
    break;

  case 284:

/* Line 1455 of yacc.c  */
#line 1919 "sql.yacc"
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
#line 1928 "sql.yacc"
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
#line 1936 "sql.yacc"
    { 
			(yyval.s_select_list_item)=new_select_list_item_op_expr((yyvsp[(1) - (3)].s_select_list_item),(yyvsp[(3) - (3)].s_select_list_item),(yyvsp[(2) - (3)].str));
	}
    break;

  case 287:

/* Line 1455 of yacc.c  */
#line 1939 "sql.yacc"
    { 
			(yyval.s_select_list_item)=new_select_list_item_op_expr((yyvsp[(1) - (3)].s_select_list_item),(yyvsp[(3) - (3)].s_select_list_item),"=");
	}
    break;

  case 288:

/* Line 1455 of yacc.c  */
#line 1942 "sql.yacc"
    { 
			FPRINTF(stderr,"Warning: Corrected =NULL to IS NULL line %d\n",yylineno);
			(yyval.s_select_list_item)=new_select_list_item_simple_expr(E_SLI_ISNULL,(yyvsp[(1) - (3)].s_select_list_item));
	}
    break;

  case 289:

/* Line 1455 of yacc.c  */
#line 1946 "sql.yacc"
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
#line 1953 "sql.yacc"
    { 
			(yyval.s_select_list_item)=new_select_list_item_regex(E_SLI_REGEX_LIKE,(yyvsp[(1) - (4)].s_select_list_item),(yyvsp[(3) - (4)].s_select_list_item),(yyvsp[(4) - (4)].str));
	}
    break;

  case 291:

/* Line 1455 of yacc.c  */
#line 1956 "sql.yacc"
    { 
			(yyval.s_select_list_item)=new_select_list_item_regex(E_SLI_REGEX_NOT_LIKE,(yyvsp[(1) - (4)].s_select_list_item),(yyvsp[(3) - (4)].s_select_list_item),(yyvsp[(4) - (4)].str));

	}
    break;

  case 292:

/* Line 1455 of yacc.c  */
#line 1960 "sql.yacc"
    { 
			(yyval.s_select_list_item)=new_select_list_item_regex(E_SLI_REGEX_ILIKE,(yyvsp[(1) - (4)].s_select_list_item),(yyvsp[(3) - (4)].s_select_list_item),(yyvsp[(4) - (4)].str));
	}
    break;

  case 293:

/* Line 1455 of yacc.c  */
#line 1963 "sql.yacc"
    { 
			(yyval.s_select_list_item)=new_select_list_item_regex(E_SLI_REGEX_NOT_ILIKE,(yyvsp[(1) - (4)].s_select_list_item),(yyvsp[(3) - (4)].s_select_list_item),(yyvsp[(4) - (4)].str));
	}
    break;

  case 294:

/* Line 1455 of yacc.c  */
#line 1966 "sql.yacc"
    { 
			(yyval.s_select_list_item)=new_select_list_item_regex(E_SLI_REGEX_MATCHES,(yyvsp[(1) - (4)].s_select_list_item),(yyvsp[(3) - (4)].s_select_list_item),(yyvsp[(4) - (4)].str));
	}
    break;

  case 295:

/* Line 1455 of yacc.c  */
#line 1969 "sql.yacc"
    { 
			(yyval.s_select_list_item)=new_select_list_item_regex(E_SLI_REGEX_NOT_MATCHES,(yyvsp[(1) - (4)].s_select_list_item),(yyvsp[(3) - (4)].s_select_list_item),(yyvsp[(4) - (4)].str));
	}
    break;

  case 296:

/* Line 1455 of yacc.c  */
#line 1975 "sql.yacc"
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
#line 1982 "sql.yacc"
    {
			strcpy((yyval.str)," < ");
	}
    break;

  case 298:

/* Line 1455 of yacc.c  */
#line 1985 "sql.yacc"
    {
			strcpy((yyval.str)," > ");
	}
    break;

  case 299:

/* Line 1455 of yacc.c  */
#line 1988 "sql.yacc"
    {
			strcpy((yyval.str)," ~ ");
	}
    break;

  case 300:

/* Line 1455 of yacc.c  */
#line 1991 "sql.yacc"
    {strcpy((yyval.str)," <= ");}
    break;

  case 301:

/* Line 1455 of yacc.c  */
#line 1992 "sql.yacc"
    {strcpy((yyval.str)," >= ");}
    break;

  case 302:

/* Line 1455 of yacc.c  */
#line 1997 "sql.yacc"
    {
		(yyval.s_select_list_item)=(yyvsp[(1) - (1)].s_select_list_item);
	}
    break;

  case 303:

/* Line 1455 of yacc.c  */
#line 2000 "sql.yacc"
    {
		(yyval.s_select_list_item)=(yyvsp[(1) - (1)].s_select_list_item);
	}
    break;

  case 304:

/* Line 1455 of yacc.c  */
#line 2003 "sql.yacc"
    {
		(yyval.s_select_list_item)=(yyvsp[(1) - (1)].s_select_list_item);
	}
    break;

  case 305:

/* Line 1455 of yacc.c  */
#line 2006 "sql.yacc"
    {
                 (yyval.s_select_list_item)=(yyvsp[(1) - (1)].s_select_list_item);
        }
    break;

  case 306:

/* Line 1455 of yacc.c  */
#line 2013 "sql.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 307:

/* Line 1455 of yacc.c  */
#line 2014 "sql.yacc"
    {strcpy((yyval.str)," ALL "); add_feature("AGG_ALL");}
    break;

  case 308:

/* Line 1455 of yacc.c  */
#line 2015 "sql.yacc"
    {
		strcpy((yyval.str)," DISTINCT ");
		add_feature("AGG_DISTINCT");
	}
    break;

  case 309:

/* Line 1455 of yacc.c  */
#line 2019 "sql.yacc"
    {
		ansi_violation("Use DISTINCT not UNIQUE",0);
		strcpy((yyval.str)," DISTINCT ");
		add_feature("AGG_DISTINCT");
	}
    break;

  case 310:

/* Line 1455 of yacc.c  */
#line 2026 "sql.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 311:

/* Line 1455 of yacc.c  */
#line 2027 "sql.yacc"
    {strcpy((yyval.str)," ALL "); add_feature("UNION_ALL");}
    break;

  case 312:

/* Line 1455 of yacc.c  */
#line 2028 "sql.yacc"
    {
		strcpy((yyval.str)," DISTINCT ");
		add_feature("UNION_DISTINCT");
	}
    break;

  case 313:

/* Line 1455 of yacc.c  */
#line 2032 "sql.yacc"
    {
		ansi_violation("Use DISTINCT not UNIQUE",0);
		add_feature("UNION_DISTINCT");
		strcpy((yyval.str)," DISTINCT ");
	}
    break;

  case 314:

/* Line 1455 of yacc.c  */
#line 2046 "sql.yacc"
    {
		strcpy((yyval.str),A4GLSQLCV_dtype_alias((yyvsp[(1) - (1)].str)));
	}
    break;

  case 319:

/* Line 1455 of yacc.c  */
#line 2061 "sql.yacc"
    {SPRINTF4((yyval.str)," %s %s%s%s",(yyvsp[(1) - (4)].str),(yyvsp[(2) - (4)].str),(yyvsp[(3) - (4)].str),(yyvsp[(4) - (4)].str));}
    break;

  case 320:

/* Line 1455 of yacc.c  */
#line 2065 "sql.yacc"
    {strcpy((yyval.str),"SERIAL"); add_feature("DDL_SERIAL"); }
    break;

  case 321:

/* Line 1455 of yacc.c  */
#line 2066 "sql.yacc"
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
#line 2075 "sql.yacc"
    {strcpy((yyval.str),"SERIAL8"); add_feature("DDL_SERIAL8"); }
    break;

  case 323:

/* Line 1455 of yacc.c  */
#line 2077 "sql.yacc"
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
#line 2086 "sql.yacc"
    {
 			add_feature("DDL_DECIMAL");
	}
    break;

  case 325:

/* Line 1455 of yacc.c  */
#line 2089 "sql.yacc"
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
#line 2097 "sql.yacc"
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
#line 2107 "sql.yacc"
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
#line 2115 "sql.yacc"
    {strcpy((yyval.str),"DATE");
 			add_feature("DDL_DATE"); }
    break;

  case 329:

/* Line 1455 of yacc.c  */
#line 2117 "sql.yacc"
    {strcpy((yyval.str),"INTEGER");}
    break;

  case 330:

/* Line 1455 of yacc.c  */
#line 2118 "sql.yacc"
    {strcpy((yyval.str),"SMALLINT");}
    break;

  case 331:

/* Line 1455 of yacc.c  */
#line 2119 "sql.yacc"
    {strcpy((yyval.str),"NCHAR"); add_feature("DDL_NCHAR");}
    break;

  case 332:

/* Line 1455 of yacc.c  */
#line 2120 "sql.yacc"
    {SPRINTF1((yyval.str),"NCHAR(%s)",(yyvsp[(3) - (4)].str)); add_feature("DDL_NCHAR");}
    break;

  case 333:

/* Line 1455 of yacc.c  */
#line 2121 "sql.yacc"
    {add_feature("DDL_NVARCHAR");}
    break;

  case 334:

/* Line 1455 of yacc.c  */
#line 2122 "sql.yacc"
    {SPRINTF1((yyval.str),"NVARCHAR(%s)",(yyvsp[(3) - (4)].str)); add_feature("DDL_NVARCHAR");}
    break;

  case 335:

/* Line 1455 of yacc.c  */
#line 2123 "sql.yacc"
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
#line 2131 "sql.yacc"
    {SPRINTF2((yyval.str),"DATETIME %s TO %s",(yyvsp[(2) - (4)].str),(yyvsp[(4) - (4)].str)); add_feature("DDL_DATETIME");}
    break;

  case 337:

/* Line 1455 of yacc.c  */
#line 2132 "sql.yacc"
    {add_feature("DDL_DATETIME");}
    break;

  case 338:

/* Line 1455 of yacc.c  */
#line 2133 "sql.yacc"
    {SPRINTF2((yyval.str),"INTERVAL %s TO %s",(yyvsp[(2) - (4)].str),(yyvsp[(4) - (4)].str)); add_feature("DDL_INTERVAL");}
    break;

  case 339:

/* Line 1455 of yacc.c  */
#line 2134 "sql.yacc"
    {strcpy((yyval.str),(yyvsp[(1) - (1)].str));}
    break;

  case 340:

/* Line 1455 of yacc.c  */
#line 2135 "sql.yacc"
    {add_feature("DDL_INTERVAL");}
    break;

  case 341:

/* Line 1455 of yacc.c  */
#line 2136 "sql.yacc"
    {SPRINTF3((yyval.str),"INTERVAL %s(%s) TO %s",(yyvsp[(2) - (7)].str),(yyvsp[(4) - (7)].str),(yyvsp[(7) - (7)].str)); add_feature("DDL_INTERVAL");}
    break;

  case 342:

/* Line 1455 of yacc.c  */
#line 2137 "sql.yacc"
    {add_feature("DDL_TEXT");}
    break;

  case 343:

/* Line 1455 of yacc.c  */
#line 2138 "sql.yacc"
    {add_feature("DDL_BYTE");}
    break;

  case 344:

/* Line 1455 of yacc.c  */
#line 2139 "sql.yacc"
    {add_feature("DDL_VARCHAR");}
    break;

  case 345:

/* Line 1455 of yacc.c  */
#line 2140 "sql.yacc"
    {SPRINTF1((yyval.str),"VARCHAR(%s)",(yyvsp[(3) - (4)].str));add_feature("DDL_VARCHAR");}
    break;

  case 346:

/* Line 1455 of yacc.c  */
#line 2141 "sql.yacc"
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
#line 2151 "sql.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 348:

/* Line 1455 of yacc.c  */
#line 2152 "sql.yacc"
    {
		SPRINTF1((yyval.str),",%s",(yyvsp[(2) - (2)].str));
}
    break;

  case 349:

/* Line 1455 of yacc.c  */
#line 2159 "sql.yacc"
    {SPRINTF4((yyval.str)," %s %s %s %s",(yyvsp[(1) - (4)].str),(yyvsp[(2) - (4)].str),(yyvsp[(3) - (4)].str),(yyvsp[(4) - (4)].str));}
    break;

  case 353:

/* Line 1455 of yacc.c  */
#line 2163 "sql.yacc"
    {add_feature("DDL_DOUBLE_PRECISION"); SPRINTF1((yyval.str)," %s",(yyvsp[(1) - (1)].str));}
    break;

  case 359:

/* Line 1455 of yacc.c  */
#line 2188 "sql.yacc"
    {(yyval.int_list.i0)=0;}
    break;

  case 360:

/* Line 1455 of yacc.c  */
#line 2189 "sql.yacc"
    {
		(yyval.int_list.i0)=1;
		(yyval.int_list.i1)=atoi((yyvsp[(2) - (3)].str));
	}
    break;

  case 361:

/* Line 1455 of yacc.c  */
#line 2193 "sql.yacc"
    {
		(yyval.int_list.i0)=2;
		(yyval.int_list.i1)=atoi((yyvsp[(2) - (5)].str));
		(yyval.int_list.i2)=atoi((yyvsp[(4) - (5)].str));
	}
    break;

  case 362:

/* Line 1455 of yacc.c  */
#line 2201 "sql.yacc"
    {
		strcpy((yyval.str),(yyvsp[(1) - (1)].str));
	}
    break;

  case 363:

/* Line 1455 of yacc.c  */
#line 2204 "sql.yacc"
    {
		strcpy((yyval.str),(yyvsp[(2) - (2)].str));
	}
    break;

  case 364:

/* Line 1455 of yacc.c  */
#line 2211 "sql.yacc"
    {
		(yyval.s_select_list_item)= (yyvsp[(1) - (1)].s_select_list_item);
	}
    break;

  case 365:

/* Line 1455 of yacc.c  */
#line 2214 "sql.yacc"
    {
		(yyval.s_select_list_item)= (yyvsp[(2) - (2)].s_select_list_item);
	}
    break;

  case 366:

/* Line 1455 of yacc.c  */
#line 2224 "sql.yacc"
    { 
		(yyval.s_select_list_item)=new_select_list_item_col(0,(yyvsp[(1) - (2)].str),&(yyvsp[(2) - (2)].int_list));
	}
    break;

  case 367:

/* Line 1455 of yacc.c  */
#line 2227 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_col((yyvsp[(1) - (4)].str),(yyvsp[(3) - (4)].str),&(yyvsp[(4) - (4)].int_list));
	}
    break;

  case 368:

/* Line 1455 of yacc.c  */
#line 2230 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_col((yyvsp[(1) - (3)].str),"*",0);
	}
    break;

  case 369:

/* Line 1455 of yacc.c  */
#line 2233 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_col(0,"rowid",0);
	}
    break;

  case 370:

/* Line 1455 of yacc.c  */
#line 2240 "sql.yacc"
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
#line 2247 "sql.yacc"
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
#line 2255 "sql.yacc"
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
#line 2264 "sql.yacc"
    {
		SPRINTF1((yyval.str),"%s",A4GLSQLCV_check_colname((yyvsp[(1) - (3)].str),"*"));
		ADDMAP("Use Column",(yyval.str));
	}
    break;

  case 375:

/* Line 1455 of yacc.c  */
#line 2275 "sql.yacc"
    { strcpy((yyval.str),(yyvsp[(1) - (1)].str)); A4GL_debug("Set $<str>$ to %s\n",(yyval.str)); }
    break;

  case 379:

/* Line 1455 of yacc.c  */
#line 2283 "sql.yacc"
    { strcpy((yyval.str),A4GLSQLCV_generate_current(0,0)); 
}
    break;

  case 380:

/* Line 1455 of yacc.c  */
#line 2285 "sql.yacc"
    {
		strcpy((yyval.str),A4GLSQLCV_generate_current((yyvsp[(1) - (3)].str),(yyvsp[(3) - (3)].str)));
	}
    break;

  case 395:

/* Line 1455 of yacc.c  */
#line 2295 "sql.yacc"
    {SPRINTF1((yyval.str),"FRACTION(%s)",(yyvsp[(3) - (4)].str));}
    break;

  case 396:

/* Line 1455 of yacc.c  */
#line 2340 "sql.yacc"
    { (yyval.sql_string)=make_sql_string_and_free(acl_strdup((yyvsp[(1) - (1)].str)), NULL);}
    break;

  case 397:

/* Line 1455 of yacc.c  */
#line 2341 "sql.yacc"
    { (yyval.sql_string)=make_sql_string_and_free(acl_strdup((yyvsp[(1) - (1)].str)), NULL);}
    break;

  case 398:

/* Line 1455 of yacc.c  */
#line 2342 "sql.yacc"
    { (yyval.sql_string)=make_sql_string_and_free(acl_strdup((yyvsp[(1) - (1)].str)), NULL);}
    break;

  case 399:

/* Line 1455 of yacc.c  */
#line 2347 "sql.yacc"
    { add_feature("RENAME_TABLE"); strcpy((yyval.str),A4GLSQLCV_rentab((yyvsp[(2) - (4)].str),(yyvsp[(4) - (4)].str))); }
    break;

  case 400:

/* Line 1455 of yacc.c  */
#line 2348 "sql.yacc"
    { add_feature("RENAME_COLUMN"); strcpy((yyval.str),A4GLSQLCV_rencol((yyvsp[(2) - (6)].str),(yyvsp[(4) - (6)].str),(yyvsp[(6) - (6)].str)) ); }
    break;

  case 403:

/* Line 1455 of yacc.c  */
#line 2356 "sql.yacc"
    {
		add_feature("UNLOCK_TABLE");
		SPRINTF2((yyval.str),"%s %s",(yyvsp[(1) - (2)].str),(yyvsp[(2) - (2)].str));
	}
    break;

  case 404:

/* Line 1455 of yacc.c  */
#line 2363 "sql.yacc"
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
#line 2374 "sql.yacc"
    { add_feature("LOCK_TABLE_SHARED");}
    break;

  case 406:

/* Line 1455 of yacc.c  */
#line 2375 "sql.yacc"
    {add_feature("LOCK_TABLE_EXCLUSIVE");}
    break;

  case 407:

/* Line 1455 of yacc.c  */
#line 2388 "sql.yacc"
    {strcpy((yyval.str),A4GLSQLCV_datetime_value((yyvsp[(1) - (1)].str)));}
    break;

  case 408:

/* Line 1455 of yacc.c  */
#line 2389 "sql.yacc"
    {strcpy((yyval.str),A4GLSQLCV_make_dtime_extend((yyvsp[(1) - (4)].str),(yyvsp[(2) - (4)].str),(yyvsp[(4) - (4)].str),0));}
    break;

  case 409:

/* Line 1455 of yacc.c  */
#line 2393 "sql.yacc"
    {strcpy((yyval.str),(yyvsp[(1) - (1)].str));}
    break;

  case 410:

/* Line 1455 of yacc.c  */
#line 2397 "sql.yacc"
    {strcpy((yyval.str),A4GLSQLCV_interval_value((yyvsp[(1) - (1)].str)));}
    break;

  case 411:

/* Line 1455 of yacc.c  */
#line 2398 "sql.yacc"
    {
			strcpy((yyval.str),A4GLSQLCV_make_ival_extend((yyvsp[(1) - (7)].str),(yyvsp[(2) - (7)].str),(yyvsp[(4) - (7)].str),(yyvsp[(7) - (7)].str),0));
		}
    break;

  case 412:

/* Line 1455 of yacc.c  */
#line 2401 "sql.yacc"
    {
		strcpy((yyval.str),A4GLSQLCV_make_ival_extend((yyvsp[(1) - (4)].str),(yyvsp[(2) - (4)].str),(char *)0, (yyvsp[(4) - (4)].str),0));
	}
    break;

  case 413:

/* Line 1455 of yacc.c  */
#line 2407 "sql.yacc"
    {SPRINTF1((yyval.str),"%s",(yyvsp[(1) - (1)].str));}
    break;

  case 414:

/* Line 1455 of yacc.c  */
#line 2411 "sql.yacc"
    {
	strcpy((yyval.str),(yyvsp[(2) - (2)].str));
}
    break;

  case 415:

/* Line 1455 of yacc.c  */
#line 2434 "sql.yacc"
    {
		(yyval.s_select_list_item_list)=(yyvsp[(3) - (3)].s_select_list_item_list);
		add_feature("ORDER_BY");
	}
    break;

  case 416:

/* Line 1455 of yacc.c  */
#line 2444 "sql.yacc"
    {
			(yyval.s_select_list_item_list)=local_new_select_list_item_list((yyvsp[(1) - (1)].s_select_list_item));
	}
    break;

  case 417:

/* Line 1455 of yacc.c  */
#line 2447 "sql.yacc"
    {
			(yyval.s_select_list_item_list)=local_add_select_list_item_list((yyvsp[(1) - (3)].s_select_list_item_list),(yyvsp[(3) - (3)].s_select_list_item));
	}
    break;

  case 418:

/* Line 1455 of yacc.c  */
#line 2453 "sql.yacc"
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
#line 2462 "sql.yacc"
    { 
		add_feature("ORDER_BY_NUMBER");
		(yyval.s_select_list_item)=new_select_list_item_literal((yyvsp[(1) - (1)].str));
	}
    break;

  case 420:

/* Line 1455 of yacc.c  */
#line 2466 "sql.yacc"
    {
		(yyval.s_select_list_item)=(yyvsp[(1) - (1)].s_select_list_item);
		(yyval.s_select_list_item)->data.type=E_SLI_COLUMN_ORDERBY;
	}
    break;

  case 421:

/* Line 1455 of yacc.c  */
#line 2473 "sql.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 422:

/* Line 1455 of yacc.c  */
#line 2475 "sql.yacc"
    {add_feature("ORDER_BY_ASC"); strcpy((yyval.str),"ASC");}
    break;

  case 423:

/* Line 1455 of yacc.c  */
#line 2477 "sql.yacc"
    {add_feature("ORDER_BY_DESC"); strcpy((yyval.str),"DESC");}
    break;

  case 424:

/* Line 1455 of yacc.c  */
#line 2481 "sql.yacc"
    {
		(yyval.s_select_list_item_list)=(yyvsp[(2) - (2)].s_select_list_item_list);
	}
    break;

  case 425:

/* Line 1455 of yacc.c  */
#line 2487 "sql.yacc"
    {
			(yyval.s_select_list_item_list)=local_new_select_list_item_list((yyvsp[(1) - (1)].s_select_list_item));
	}
    break;

  case 426:

/* Line 1455 of yacc.c  */
#line 2490 "sql.yacc"
    {
			(yyval.s_select_list_item_list)=local_add_select_list_item_list((yyvsp[(1) - (3)].s_select_list_item_list),(yyvsp[(3) - (3)].s_select_list_item));
	}
    break;

  case 427:

/* Line 1455 of yacc.c  */
#line 2496 "sql.yacc"
    { (yyval.s_select_list_item)=(yyvsp[(1) - (1)].s_select_list_item); }
    break;

  case 428:

/* Line 1455 of yacc.c  */
#line 2497 "sql.yacc"
    { (yyval.s_select_list_item)=new_select_list_item_literal((yyvsp[(1) - (1)].str)); }
    break;

  case 429:

/* Line 1455 of yacc.c  */
#line 2504 "sql.yacc"
    {
	(yyval.sql_string)=get_select_list_item(0,(yyvsp[(1) - (1)].s_select_list_item));
}
    break;

  case 430:

/* Line 1455 of yacc.c  */
#line 2517 "sql.yacc"
    {
		A4GL_set_sql_lineno(yylineno);
		(yyval.sql_string)=make_select_stmt_v2(current_upd_table, (yyvsp[(1) - (1)].s_select),"");
		map_select_stmt("SELECT",(yyvsp[(1) - (1)].s_select));
		A4GL_free_select_stmt((yyvsp[(1) - (1)].s_select));
}
    break;

  case 431:

/* Line 1455 of yacc.c  */
#line 2527 "sql.yacc"
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
#line 2534 "sql.yacc"
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
#line 2551 "sql.yacc"
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
#line 2558 "sql.yacc"
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
#line 2583 "sql.yacc"
    { 
		//start_bind('i',0);
		 set_ignore_indicators();}
    break;

  case 436:

/* Line 1455 of yacc.c  */
#line 2585 "sql.yacc"
    { clr_ignore_indicators();}
    break;

  case 437:

/* Line 1455 of yacc.c  */
#line 2587 "sql.yacc"
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
#line 2608 "sql.yacc"
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
#line 2651 "sql.yacc"
    { (yyval.s_select)=0;}
    break;

  case 440:

/* Line 1455 of yacc.c  */
#line 2652 "sql.yacc"
    { 
		(yyval.s_select)=(yyvsp[(3) - (3)].s_select);
		(yyval.s_select)->union_op=acl_strdup((yyvsp[(2) - (3)].str));
		A4GL_set_associated_mem((yyval.s_select), (yyval.s_select)->union_op);
		add_feature("SELECT_UNION"); 
	}
    break;

  case 441:

/* Line 1455 of yacc.c  */
#line 2666 "sql.yacc"
    {
		(yyval.s_select_finish)=0;
	}
    break;

  case 442:

/* Line 1455 of yacc.c  */
#line 2669 "sql.yacc"
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
#line 2676 "sql.yacc"
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
#line 2686 "sql.yacc"
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
#line 2704 "sql.yacc"
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
#line 2717 "sql.yacc"
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
#line 2732 "sql.yacc"
    {(yyval.integer_val)=-1;}
    break;

  case 449:

/* Line 1455 of yacc.c  */
#line 2734 "sql.yacc"
    {
		(yyval.integer_val)=atol((yyvsp[(2) - (2)].str));
	}
    break;

  case 450:

/* Line 1455 of yacc.c  */
#line 2740 "sql.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 451:

/* Line 1455 of yacc.c  */
#line 2741 "sql.yacc"
    {strcpy((yyval.str),"ALL"); add_feature("SELECT_ALL");}
    break;

  case 452:

/* Line 1455 of yacc.c  */
#line 2742 "sql.yacc"
    {strcpy((yyval.str),"DISTINCT"); add_feature("SELECT_DISTINCT");}
    break;

  case 453:

/* Line 1455 of yacc.c  */
#line 2743 "sql.yacc"
    {strcpy((yyval.str),"DISTINCT");
		add_feature("SELECT_UNIQUE");
		ansi_violation("Use DISTINCT not UNIQUE",0);
		strcpy((yyval.str),"DISTINCT");
	}
    break;

  case 454:

/* Line 1455 of yacc.c  */
#line 2753 "sql.yacc"
    { 
		 (yyval.s_select_list_item_list)=local_new_select_list_item_list((yyvsp[(1) - (1)].s_select_list_item));
	}
    break;

  case 455:

/* Line 1455 of yacc.c  */
#line 2756 "sql.yacc"
    { 
		(yyval.s_select_list_item_list)=local_add_select_list_item_list((yyvsp[(1) - (3)].s_select_list_item_list),(yyvsp[(3) - (3)].s_select_list_item));
	}
    break;

  case 456:

/* Line 1455 of yacc.c  */
#line 2762 "sql.yacc"
    {
		(yyval.s_select_list_item)=(yyvsp[(1) - (1)].s_select_list_item);
	}
    break;

  case 457:

/* Line 1455 of yacc.c  */
#line 2765 "sql.yacc"
    {
		(yyval.s_select_list_item)=(yyvsp[(1) - (2)].s_select_list_item);
		(yyval.s_select_list_item)->alias=acl_strdup((yyvsp[(2) - (2)].str));
		A4GL_set_associated_mem((yyval.s_select_list_item), (yyval.s_select_list_item)->alias);
	}
    break;

  case 458:

/* Line 1455 of yacc.c  */
#line 2770 "sql.yacc"
    {
		(yyval.s_select_list_item)=(yyvsp[(1) - (3)].s_select_list_item);
		(yyval.s_select_list_item)->alias=acl_strdup((yyvsp[(3) - (3)].str));
		A4GL_set_associated_mem((yyval.s_select_list_item), (yyval.s_select_list_item)->alias);
	}
    break;

  case 459:

/* Line 1455 of yacc.c  */
#line 2779 "sql.yacc"
    {
		(yyval.s_select_list_item)=(yyvsp[(1) - (1)].s_select_list_item); /* A4GLSQLCV_check_expr($<sql_string>1) */
	}
    break;

  case 460:

/* Line 1455 of yacc.c  */
#line 2782 "sql.yacc"
    {
		(yyval.s_select_list_item)=(yyvsp[(2) - (2)].s_select_list_item);
		(yyval.s_select_list_item)->sign='-';
	}
    break;

  case 461:

/* Line 1455 of yacc.c  */
#line 2786 "sql.yacc"
    {
		(yyval.s_select_list_item)=(yyvsp[(2) - (2)].s_select_list_item);
	}
    break;

  case 462:

/* Line 1455 of yacc.c  */
#line 2793 "sql.yacc"
    {
			(yyval.s_select_list_item)=new_select_list_item_op_expr ((yyvsp[(1) - (3)].s_select_list_item), (yyvsp[(3) - (3)].s_select_list_item), "/");
	}
    break;

  case 463:

/* Line 1455 of yacc.c  */
#line 2796 "sql.yacc"
    {
			(yyval.s_select_list_item)=new_select_list_item_simple_expr((enum e_sli)(yyvsp[(2) - (2)].integer_val), (yyvsp[(1) - (2)].s_select_list_item));
	}
    break;

  case 464:

/* Line 1455 of yacc.c  */
#line 2799 "sql.yacc"
    {
			(yyval.s_select_list_item)=new_select_list_item_op_expr ((yyvsp[(1) - (3)].s_select_list_item), (yyvsp[(3) - (3)].s_select_list_item), "*");
	}
    break;

  case 465:

/* Line 1455 of yacc.c  */
#line 2802 "sql.yacc"
    {
			(yyval.s_select_list_item)=new_select_list_item_op_expr ((yyvsp[(1) - (3)].s_select_list_item), (yyvsp[(3) - (3)].s_select_list_item), "+");
	}
    break;

  case 466:

/* Line 1455 of yacc.c  */
#line 2805 "sql.yacc"
    {
			(yyval.s_select_list_item)=new_select_list_item_op_expr ((yyvsp[(1) - (3)].s_select_list_item), (yyvsp[(3) - (3)].s_select_list_item), "-");
	}
    break;

  case 467:

/* Line 1455 of yacc.c  */
#line 2808 "sql.yacc"
    { (yyval.s_select_list_item)=new_select_list_item_literal((yyvsp[(1) - (1)].str)); }
    break;

  case 468:

/* Line 1455 of yacc.c  */
#line 2809 "sql.yacc"
    { (yyval.s_select_list_item)=new_select_list_item_builtin_const(E_SLI_BUILTIN_CONST_TRUE); }
    break;

  case 469:

/* Line 1455 of yacc.c  */
#line 2810 "sql.yacc"
    { (yyval.s_select_list_item)=new_select_list_item_builtin_const(E_SLI_BUILTIN_CONST_FALSE); }
    break;

  case 470:

/* Line 1455 of yacc.c  */
#line 2811 "sql.yacc"
    { (yyval.s_select_list_item)=new_select_list_item_builtin_const(E_SLI_BUILTIN_CONST_USER); }
    break;

  case 471:

/* Line 1455 of yacc.c  */
#line 2812 "sql.yacc"
    { (yyval.s_select_list_item)=new_select_list_item_builtin_const(E_SLI_BUILTIN_CONST_TODAY); }
    break;

  case 472:

/* Line 1455 of yacc.c  */
#line 2813 "sql.yacc"
    { (yyval.s_select_list_item)=new_select_list_item_builtin_const(E_SLI_BUILTIN_CONST_ROWID); }
    break;

  case 473:

/* Line 1455 of yacc.c  */
#line 2814 "sql.yacc"
    { (yyval.s_select_list_item)=new_select_list_item_builtin_const(E_SLI_BUILTIN_CONST_TIME); }
    break;

  case 474:

/* Line 1455 of yacc.c  */
#line 2815 "sql.yacc"
    { (yyval.s_select_list_item)=new_select_list_item_builtin_const(E_SLI_BUILTIN_CONST_STAR); }
    break;

  case 475:

/* Line 1455 of yacc.c  */
#line 2816 "sql.yacc"
    { (yyval.s_select_list_item)=new_select_list_item_builtin_const(E_SLI_BUILTIN_CONST_COUNT_STAR); }
    break;

  case 476:

/* Line 1455 of yacc.c  */
#line 2818 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_agg1(E_SLI_BUILTIN_AGG_AVG,(yyvsp[(3) - (5)].str),(yyvsp[(4) - (5)].s_select_list_item));
		add_feature("SELECT_AVG");
	}
    break;

  case 477:

/* Line 1455 of yacc.c  */
#line 2822 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_agg1(E_SLI_BUILTIN_AGG_MAX,(yyvsp[(3) - (5)].str),(yyvsp[(4) - (5)].s_select_list_item));
		add_feature("SELECT_MAX");
	}
    break;

  case 478:

/* Line 1455 of yacc.c  */
#line 2826 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_agg1(E_SLI_BUILTIN_AGG_MIN,(yyvsp[(3) - (5)].str),(yyvsp[(4) - (5)].s_select_list_item));
		add_feature("SELECT_MIN");
	}
    break;

  case 479:

/* Line 1455 of yacc.c  */
#line 2830 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_agg1(E_SLI_BUILTIN_AGG_SUM,(yyvsp[(3) - (5)].str),(yyvsp[(4) - (5)].s_select_list_item));
		add_feature("SELECT_SUM");
	}
    break;

  case 480:

/* Line 1455 of yacc.c  */
#line 2834 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_agg1(E_SLI_BUILTIN_AGG_COUNT,(yyvsp[(3) - (5)].str),(yyvsp[(4) - (5)].s_select_list_item));
		add_feature("SELECT_COUNT");
	}
    break;

  case 481:

/* Line 1455 of yacc.c  */
#line 2838 "sql.yacc"
    {
		add_sql_function((yyvsp[(1) - (3)].str));
		(yyval.s_select_list_item)=new_select_list_item_fcall((yyvsp[(1) - (3)].str),0);
	}
    break;

  case 482:

/* Line 1455 of yacc.c  */
#line 2842 "sql.yacc"
    {
		add_sql_function((yyvsp[(1) - (4)].str));
		(yyval.s_select_list_item)=new_select_list_item_fcall((yyvsp[(1) - (4)].str),(yyvsp[(3) - (4)].s_select_list_item_list));
	}
    break;

  case 483:

/* Line 1455 of yacc.c  */
#line 2846 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_builtin_fcall(E_SLI_BUILTIN_FUNC_YEAR,(yyvsp[(3) - (4)].s_select_list_item_list));
	}
    break;

  case 484:

/* Line 1455 of yacc.c  */
#line 2849 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_builtin_fcall(E_SLI_BUILTIN_FUNC_MONTH,(yyvsp[(3) - (4)].s_select_list_item_list));
	}
    break;

  case 485:

/* Line 1455 of yacc.c  */
#line 2852 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_builtin_fcall(E_SLI_BUILTIN_FUNC_DAY,(yyvsp[(3) - (4)].s_select_list_item_list));
	}
    break;

  case 486:

/* Line 1455 of yacc.c  */
#line 2855 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_builtin_fcall(E_SLI_BUILTIN_FUNC_MDY,(yyvsp[(3) - (4)].s_select_list_item_list));
	}
    break;

  case 487:

/* Line 1455 of yacc.c  */
#line 2858 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_builtin_fcall(E_SLI_BUILTIN_FUNC_WEEKDAY,(yyvsp[(3) - (4)].s_select_list_item_list));
	}
    break;

  case 488:

/* Line 1455 of yacc.c  */
#line 2861 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_builtin_fcall(E_SLI_BUILTIN_FUNC_DOW,(yyvsp[(3) - (4)].s_select_list_item_list));
	}
    break;

  case 489:

/* Line 1455 of yacc.c  */
#line 2864 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_builtin_fcall(E_SLI_BUILTIN_FUNC_DATE,(yyvsp[(3) - (4)].s_select_list_item_list));
	}
    break;

  case 490:

/* Line 1455 of yacc.c  */
#line 2867 "sql.yacc"
    {
		  (yyval.s_select_list_item)=new_select_list_item_simple_expr(E_SLI_BRACKET_EXPR,(yyvsp[(2) - (3)].s_select_list_item));
	}
    break;

  case 491:

/* Line 1455 of yacc.c  */
#line 2870 "sql.yacc"
    { 
		add_feature("EXTEND"); 
		(yyval.s_select_list_item)=(yyvsp[(3) - (4)].s_select_list_item);
	}
    break;

  case 492:

/* Line 1455 of yacc.c  */
#line 2874 "sql.yacc"
    { 
		(yyval.s_select_list_item)=new_select_list_item_datetime((yyvsp[(1) - (1)].str));
		add_feature("FUNC_DATETIME");
	}
    break;

  case 493:

/* Line 1455 of yacc.c  */
#line 2878 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_interval((yyvsp[(1) - (1)].str));
		add_feature("FUNC_INTERVAL");
	}
    break;

  case 494:

/* Line 1455 of yacc.c  */
#line 2882 "sql.yacc"
    {
		(yyval.s_select_list_item)=(yyvsp[(2) - (3)].s_select_list_item);
	}
    break;

  case 495:

/* Line 1455 of yacc.c  */
#line 2890 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_case((yyvsp[(1) - (1)].s_select_list_item));
	}
    break;

  case 496:

/* Line 1455 of yacc.c  */
#line 2893 "sql.yacc"
    {
		(yyval.s_select_list_item)=append_select_list_item_case(
							(yyvsp[(1) - (2)].s_select_list_item),
							(yyvsp[(2) - (2)].s_select_list_item));
	}
    break;

  case 497:

/* Line 1455 of yacc.c  */
#line 2902 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_case_element(
				(yyvsp[(2) - (4)].s_select_list_item),
				(yyvsp[(4) - (4)].s_select_list_item));

	}
    break;

  case 498:

/* Line 1455 of yacc.c  */
#line 2908 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_case_element( 0, (yyvsp[(2) - (2)].s_select_list_item));
	}
    break;

  case 499:

/* Line 1455 of yacc.c  */
#line 2915 "sql.yacc"
    {
		(yyval.s_select_list_item_list)=local_new_select_list_item_list((yyvsp[(1) - (1)].s_select_list_item));
	}
    break;

  case 500:

/* Line 1455 of yacc.c  */
#line 2918 "sql.yacc"
    {
			(yyval.s_select_list_item_list)=local_add_select_list_item_list((yyvsp[(1) - (3)].s_select_list_item_list),(yyvsp[(3) - (3)].s_select_list_item));
	}
    break;

  case 501:

/* Line 1455 of yacc.c  */
#line 2946 "sql.yacc"
    {
			(yyval.s_select_list_item)=new_select_list_item_extend(new_select_list_item_builtin_const(E_SLI_BUILTIN_CONST_CURRENT),(yyvsp[(3) - (5)].str),(yyvsp[(5) - (5)].str));
	}
    break;

  case 502:

/* Line 1455 of yacc.c  */
#line 2949 "sql.yacc"
    {
			(yyval.s_select_list_item)=new_select_list_item_extend((yyvsp[(1) - (5)].s_select_list_item),(yyvsp[(3) - (5)].str),(yyvsp[(5) - (5)].str));
	}
    break;

  case 503:

/* Line 1455 of yacc.c  */
#line 2952 "sql.yacc"
    {
			(yyval.s_select_list_item)=new_select_list_item_extend(new_select_list_item_builtin_const(E_SLI_BUILTIN_CONST_CURRENT),(yyvsp[(2) - (4)].str),(yyvsp[(4) - (4)].str));
	}
    break;

  case 504:

/* Line 1455 of yacc.c  */
#line 2955 "sql.yacc"
    {
			(yyval.s_select_list_item)=new_select_list_item_extend((yyvsp[(1) - (5)].s_select_list_item),(yyvsp[(3) - (5)].str),(yyvsp[(5) - (5)].str));
	}
    break;

  case 505:

/* Line 1455 of yacc.c  */
#line 2961 "sql.yacc"
    {(yyval.integer_val)=E_SLI_UNITS_YEAR;}
    break;

  case 506:

/* Line 1455 of yacc.c  */
#line 2962 "sql.yacc"
    {(yyval.integer_val)=E_SLI_UNITS_MONTH;}
    break;

  case 507:

/* Line 1455 of yacc.c  */
#line 2963 "sql.yacc"
    {(yyval.integer_val)=E_SLI_UNITS_DAY;}
    break;

  case 508:

/* Line 1455 of yacc.c  */
#line 2964 "sql.yacc"
    {(yyval.integer_val)=E_SLI_UNITS_HOUR;}
    break;

  case 509:

/* Line 1455 of yacc.c  */
#line 2965 "sql.yacc"
    {(yyval.integer_val)=E_SLI_UNITS_MINUTE;}
    break;

  case 510:

/* Line 1455 of yacc.c  */
#line 2966 "sql.yacc"
    {(yyval.integer_val)=E_SLI_UNITS_SECOND;}
    break;

  case 511:

/* Line 1455 of yacc.c  */
#line 2971 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_op_slil((yyvsp[(1) - (5)].s_select_list_item),(yyvsp[(4) - (5)].s_select_list_item_list),E_SLI_IN_VALUES);
                add_feature("WHERE_IN");
        }
    break;

  case 512:

/* Line 1455 of yacc.c  */
#line 2975 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_op_sli((yyvsp[(1) - (3)].s_select_list_item),(yyvsp[(3) - (3)].s_select_list_item),E_SLI_IN_SELECT);
                add_feature("WHERE_IN_SELECT");
        }
    break;

  case 513:

/* Line 1455 of yacc.c  */
#line 2979 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_op_slil((yyvsp[(1) - (5)].s_select_list_item),(yyvsp[(4) - (5)].s_select_list_item_list),E_SLI_NOT_IN_VALUES);
                add_feature("WHERE_IN");
        }
    break;

  case 514:

/* Line 1455 of yacc.c  */
#line 2983 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_op_sli((yyvsp[(1) - (3)].s_select_list_item),(yyvsp[(3) - (3)].s_select_list_item),E_SLI_NOT_IN_SELECT);
                add_feature("WHERE_IN_SELECT");
        }
    break;

  case 515:

/* Line 1455 of yacc.c  */
#line 2990 "sql.yacc"
    {
		(yyval.s_select_list_item_list)=local_new_select_list_item_list((yyvsp[(1) - (1)].s_select_list_item));
	}
    break;

  case 516:

/* Line 1455 of yacc.c  */
#line 2993 "sql.yacc"
    {
                (yyval.s_select_list_item_list)=local_add_select_list_item_list((yyvsp[(1) - (3)].s_select_list_item_list),(yyvsp[(3) - (3)].s_select_list_item));
	}
    break;

  case 517:

/* Line 1455 of yacc.c  */
#line 2998 "sql.yacc"
    { (yyval.s_select_list_item)=(yyvsp[(1) - (1)].s_select_list_item);}
    break;

  case 518:

/* Line 1455 of yacc.c  */
#line 2999 "sql.yacc"
    { (yyval.s_select_list_item)=new_select_list_item_literal((yyvsp[(1) - (1)].str)); }
    break;

  case 519:

/* Line 1455 of yacc.c  */
#line 3000 "sql.yacc"
    { 
		char buff[256]; SPRINTF1(buff," -%s",(yyvsp[(2) - (2)].str)); (yyval.s_select_list_item)=new_select_list_item_literal(buff); }
    break;

  case 520:

/* Line 1455 of yacc.c  */
#line 3002 "sql.yacc"
    { char buff[256]; SPRINTF1(buff," -%s",(yyvsp[(2) - (2)].str)); (yyval.s_select_list_item)=new_select_list_item_literal(buff); }
    break;

  case 521:

/* Line 1455 of yacc.c  */
#line 3008 "sql.yacc"
    {
                if (strstr((yyvsp[(1) - (1)].str),"systables")!=0) { add_feature("IFX_SYSTABLES"); }
                if (strstr((yyvsp[(1) - (1)].str),"syscolumns")!=0) { add_feature("IFX_SYSCOLUMNS"); }
                if (strstr((yyvsp[(1) - (1)].str),"sysindexes")!=0) { add_feature("IFX_SYSINDEXES"); }
                strcpy((yyval.str),A4GLSQLCV_check_tablename((yyvsp[(1) - (1)].str)));
                }
    break;

  case 522:

/* Line 1455 of yacc.c  */
#line 3018 "sql.yacc"
    {
	     SPRINTF1((yyval.str),"%s", A4GLSQLCV_ownerize_tablename(NULL, A4GL_strip_quotes((yyvsp[(1) - (1)].str))));
             ADDMAP("Use Table",(yyval.str));
        }
    break;

  case 523:

/* Line 1455 of yacc.c  */
#line 3022 "sql.yacc"
    {
	     SPRINTF1((yyval.str),"%s", A4GLSQLCV_ownerize_tablename((yyvsp[(1) - (3)].str), (yyvsp[(3) - (3)].str)));
	     ADDMAP("Use Table",(yyval.str));
        }
    break;

  case 524:

/* Line 1455 of yacc.c  */
#line 3026 "sql.yacc"
    {
	     SPRINTF1((yyval.str),"%s", A4GLSQLCV_ownerize_tablename(NULL, (yyvsp[(1) - (1)].str)));
	     ADDMAP("Use Table",(yyval.str));
	}
    break;

  case 525:

/* Line 1455 of yacc.c  */
#line 3030 "sql.yacc"
    {
	     SPRINTF1((yyval.str),"%s", A4GLSQLCV_db_tablename((yyvsp[(1) - (3)].str), NULL, A4GLSQLCV_ownerize_tablename(NULL, (yyvsp[(3) - (3)].str))));
	     ADDMAP("Use Table",(yyval.str));
	}
    break;

  case 526:

/* Line 1455 of yacc.c  */
#line 3034 "sql.yacc"
    {
	     SPRINTF1((yyval.str),"%s", A4GLSQLCV_db_tablename((yyvsp[(1) - (5)].str), NULL, A4GLSQLCV_ownerize_tablename((yyvsp[(3) - (5)].str),(yyvsp[(5) - (5)].str))));
	     ADDMAP("Use Table",(yyval.str));
        }
    break;

  case 527:

/* Line 1455 of yacc.c  */
#line 3038 "sql.yacc"
    {
	     SPRINTF1((yyval.str),"%s", A4GLSQLCV_db_tablename(NULL,(yyvsp[(1) - (3)].str), A4GLSQLCV_ownerize_tablename(NULL, (yyvsp[(3) - (3)].str))));
	     ADDMAP("Use Table",(yyval.str));
	}
    break;

  case 528:

/* Line 1455 of yacc.c  */
#line 3042 "sql.yacc"
    {
	     SPRINTF1((yyval.str),"%s", A4GLSQLCV_db_tablename((yyvsp[(1) - (5)].str), (yyvsp[(3) - (5)].str), A4GLSQLCV_ownerize_tablename(NULL, (yyvsp[(5) - (5)].str))));
	     ADDMAP("Use Table",(yyval.str));
	}
    break;

  case 529:

/* Line 1455 of yacc.c  */
#line 3046 "sql.yacc"
    {
	     SPRINTF1((yyval.str),"%s", A4GLSQLCV_db_tablename((yyvsp[(1) - (7)].str), (yyvsp[(3) - (7)].str), A4GLSQLCV_ownerize_tablename((yyvsp[(5) - (7)].str), (yyvsp[(7) - (7)].str))));
	     ADDMAP("Use Table",(yyval.str));
        }
    break;

  case 530:

/* Line 1455 of yacc.c  */
#line 3054 "sql.yacc"
    {
                if (strstr((yyvsp[(1) - (1)].str),"systables")!=0) { add_feature("IFX_SYSTABLES"); }
                if (strstr((yyvsp[(1) - (1)].str),"syscolumns")!=0) { add_feature("IFX_SYSCOLUMNS"); }
                if (strstr((yyvsp[(1) - (1)].str),"sysindexes")!=0) { add_feature("IFX_SYSINDEXES"); }
                strcpy((yyval.str),A4GLSQLCV_check_tablename((yyvsp[(1) - (1)].str)));
                }
    break;

  case 531:

/* Line 1455 of yacc.c  */
#line 3064 "sql.yacc"
    {

	     SPRINTF1((yyval.str),"%s", A4GLSQLCV_ownerize_tablename((yyvsp[(1) - (3)].str), (yyvsp[(3) - (3)].str)));
	     ADDMAP("Use Table",(yyval.str));
        }
    break;

  case 532:

/* Line 1455 of yacc.c  */
#line 3069 "sql.yacc"
    {
	     SPRINTF1((yyval.str),"%s", A4GLSQLCV_ownerize_tablename((yyvsp[(1) - (3)].str), (yyvsp[(3) - (3)].str)));
	     ADDMAP("Use Table",(yyval.str));
        }
    break;

  case 533:

/* Line 1455 of yacc.c  */
#line 3073 "sql.yacc"
    {
	     SPRINTF1((yyval.str),"%s", A4GLSQLCV_ownerize_tablename(NULL, A4GL_strip_quotes((yyvsp[(1) - (1)].str))));
	     ADDMAP("Use Table",(yyval.str));
        }
    break;

  case 534:

/* Line 1455 of yacc.c  */
#line 3077 "sql.yacc"
    {
             SPRINTF1((yyval.str),"%s", A4GLSQLCV_ownerize_tablename(NULL, (yyvsp[(1) - (1)].str)));
	     ADDMAP("Use Table",(yyval.str));
	}
    break;

  case 535:

/* Line 1455 of yacc.c  */
#line 3081 "sql.yacc"
    {
             SPRINTF1((yyval.str),"%s", A4GLSQLCV_db_tablename((yyvsp[(1) - (3)].str),NULL, A4GLSQLCV_ownerize_tablename(NULL, (yyvsp[(3) - (3)].str))));
	     ADDMAP("Use Table",(yyval.str));
	}
    break;

  case 536:

/* Line 1455 of yacc.c  */
#line 3085 "sql.yacc"
    {
	     SPRINTF1((yyval.str),"%s", A4GLSQLCV_db_tablename((yyvsp[(1) - (5)].str), NULL,A4GLSQLCV_ownerize_tablename((yyvsp[(3) - (5)].str), (yyvsp[(5) - (5)].str))));
	     ADDMAP("Use Table",(yyval.str));
        }
    break;

  case 537:

/* Line 1455 of yacc.c  */
#line 3090 "sql.yacc"
    {
             SPRINTF1((yyval.str),"%s", A4GLSQLCV_db_tablename(NULL, (yyvsp[(1) - (3)].str), A4GLSQLCV_ownerize_tablename(NULL, (yyvsp[(3) - (3)].str))));
	     ADDMAP("Use Table",(yyval.str));
	}
    break;

  case 538:

/* Line 1455 of yacc.c  */
#line 3094 "sql.yacc"
    {
            SPRINTF1((yyval.str),"%s", A4GLSQLCV_db_tablename( (yyvsp[(1) - (5)].str), (yyvsp[(3) - (5)].str), A4GLSQLCV_ownerize_tablename(NULL, (yyvsp[(5) - (5)].str))));
	    ADDMAP("Use Table",(yyval.str));
	}
    break;

  case 539:

/* Line 1455 of yacc.c  */
#line 3098 "sql.yacc"
    {
	     SPRINTF1((yyval.str),"%s", A4GLSQLCV_db_tablename((yyvsp[(1) - (7)].str), (yyvsp[(3) - (7)].str), A4GLSQLCV_ownerize_tablename((yyvsp[(5) - (7)].str), (yyvsp[(7) - (7)].str))));
	     ADDMAP("Use Table",(yyval.str));
        }
    break;

  case 540:

/* Line 1455 of yacc.c  */
#line 3106 "sql.yacc"
    {
	     SPRINTF1((yyval.str),"%s", A4GLSQLCV_ownerize_tablename((yyvsp[(1) - (3)].str), (yyvsp[(3) - (3)].str)));
        }
    break;

  case 541:

/* Line 1455 of yacc.c  */
#line 3109 "sql.yacc"
    {
	        SPRINTF1((yyval.str),"%s", A4GLSQLCV_ownerize_tablename(NULL, (yyvsp[(1) - (1)].str)));
                ADDMAP("Use Index",(yyval.str));
        }
    break;

  case 542:

/* Line 1455 of yacc.c  */
#line 3114 "sql.yacc"
    {strcpy((yyval.str),(yyvsp[(1) - (1)].str)); ADDMAP("Use Index",(yyvsp[(1) - (1)].str)); }
    break;

  case 543:

/* Line 1455 of yacc.c  */
#line 3115 "sql.yacc"
    { SPRINTF3((yyval.str),"%s%s%s",(yyvsp[(1) - (3)].str),(yyvsp[(2) - (3)].str),(yyvsp[(3) - (3)].str)); ADDMAP("Use Index",(yyval.str)); }
    break;

  case 544:

/* Line 1455 of yacc.c  */
#line 3116 "sql.yacc"
    {
	     SPRINTF2((yyval.str),"%s:%s", (yyvsp[(1) - (5)].str), A4GLSQLCV_ownerize_tablename((yyvsp[(3) - (5)].str), (yyvsp[(5) - (5)].str)));
             ADDMAP("Use Index",(yyval.str));
        }
    break;

  case 545:

/* Line 1455 of yacc.c  */
#line 3121 "sql.yacc"
    {strcpy((yyval.str),(yyvsp[(1) - (3)].str)); ADDMAP("Use Index",(yyvsp[(1) - (3)].str)); }
    break;

  case 546:

/* Line 1455 of yacc.c  */
#line 3122 "sql.yacc"
    { SPRINTF4((yyval.str),"%s@%s%s%s",(yyvsp[(1) - (5)].str),(yyvsp[(3) - (5)].str),(yyvsp[(4) - (5)].str),(yyvsp[(5) - (5)].str)); ADDMAP("Use Index",(yyval.str)); }
    break;

  case 547:

/* Line 1455 of yacc.c  */
#line 3123 "sql.yacc"
    {
	     SPRINTF3((yyval.str),"%s@%s:%s", (yyvsp[(1) - (7)].str), (yyvsp[(3) - (7)].str), A4GLSQLCV_ownerize_tablename((yyvsp[(5) - (7)].str), (yyvsp[(7) - (7)].str)));
             ADDMAP("Use Index",(yyval.str));
        }
    break;

  case 549:

/* Line 1455 of yacc.c  */
#line 3134 "sql.yacc"
    {
                      (yyval.ptr)=A4GL_new_expr_simple_string(A4GL_get_clobbered_from((yyval.str)), ET_EXPR_IDENTIFIER);
	}
    break;

  case 551:

/* Line 1455 of yacc.c  */
#line 3140 "sql.yacc"
    { sprintf((yyval.str),".%s",(yyvsp[(2) - (2)].str)); }
    break;

  case 553:

/* Line 1455 of yacc.c  */
#line 3145 "sql.yacc"
    {strcpy((yyval.str), A4GL_strip_quotes ((yyvsp[(1) - (1)].str)));}
    break;

  case 558:

/* Line 1455 of yacc.c  */
#line 3196 "sql.yacc"
    {
			int converted;
			(yyval.sql_string)=get_insert_cmd((yyvsp[(1) - (1)].insert_cmd),&converted);
			A4GL_free_associated_mem((yyvsp[(1) - (1)].insert_cmd));
			acl_free((yyvsp[(1) - (1)].insert_cmd));

		}
    break;

  case 559:

/* Line 1455 of yacc.c  */
#line 3203 "sql.yacc"
    {
			int converted;
			(yyval.sql_string)=get_update_cmd((yyvsp[(1) - (1)].update_cmd),&converted);
			A4GL_free_associated_mem((yyvsp[(1) - (1)].update_cmd));
			acl_free((yyvsp[(1) - (1)].update_cmd));
		}
    break;

  case 560:

/* Line 1455 of yacc.c  */
#line 3209 "sql.yacc"
    {
			int converted;
			(yyval.sql_string)=get_delete_cmd((yyvsp[(1) - (1)].delete_cmd),&converted);
			A4GL_free_associated_mem((yyvsp[(1) - (1)].delete_cmd));
			acl_free((yyvsp[(1) - (1)].delete_cmd));
		}
    break;

  case 563:

/* Line 1455 of yacc.c  */
#line 3224 "sql.yacc"
    { print_exec_select((yyvsp[(1) - (1)].sql_string));  }
    break;

  case 564:

/* Line 1455 of yacc.c  */
#line 3225 "sql.yacc"
    { print_exec_select((yyvsp[(1) - (1)].sql_string));  }
    break;

  case 566:

/* Line 1455 of yacc.c  */
#line 3227 "sql.yacc"
    { print_exec_select((yyvsp[(1) - (1)].sql_string));  }
    break;

  case 567:

/* Line 1455 of yacc.c  */
#line 3229 "sql.yacc"
    {
			print_sql_commit ((yyvsp[(1) - (1)].integer_val));
	}
    break;

  case 568:

/* Line 1455 of yacc.c  */
#line 3232 "sql.yacc"
    {print_unable_to_parse();}
    break;

  case 569:

/* Line 1455 of yacc.c  */
#line 3236 "sql.yacc"
    { (yyval.sql_string)=make_sql_string_and_free((yyvsp[(1) - (2)].sql_string),acl_strdup((yyvsp[(2) - (2)].str)),0);
}
    break;

  case 571:

/* Line 1455 of yacc.c  */
#line 3245 "sql.yacc"
    {
			(yyval.sql_string)=make_select_stmt_v2("", (yyvsp[(1) - (1)].s_select),"");
			A4GL_free_select_stmt((yyvsp[(1) - (1)].s_select));
		}
    break;

  case 572:

/* Line 1455 of yacc.c  */
#line 3251 "sql.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 573:

/* Line 1455 of yacc.c  */
#line 3252 "sql.yacc"
    {
			strcpy((yyval.str),A4GLSQLCV_get_forupdate(NULL));
		}
    break;

  case 574:

/* Line 1455 of yacc.c  */
#line 3255 "sql.yacc"
    {
			strcpy((yyval.str),A4GLSQLCV_get_forupdate((yyvsp[(2) - (2)].str)));
		}
    break;

  case 575:

/* Line 1455 of yacc.c  */
#line 3260 "sql.yacc"
    { strcpy((yyval.str),(yyvsp[(1) - (1)].str)); }
    break;

  case 576:

/* Line 1455 of yacc.c  */
#line 3261 "sql.yacc"
    { sprintf((yyval.str),"%s,%s",(yyvsp[(1) - (3)].str),(yyvsp[(3) - (3)].str)); }
    break;

  case 578:

/* Line 1455 of yacc.c  */
#line 3265 "sql.yacc"
    {sprintf((yyval.str),"%s.%s",A4GLSQLCV_ownerize_tablename(NULL, (yyvsp[(1) - (3)].str)),(yyvsp[(3) - (3)].str));}
    break;

  case 579:

/* Line 1455 of yacc.c  */
#line 3266 "sql.yacc"
    {
        sprintf((yyval.str),"%s.%s", A4GLSQLCV_ownerize_tablename((yyvsp[(1) - (5)].str), (yyvsp[(3) - (5)].str)), (yyvsp[(5) - (5)].str));
}
    break;

  case 580:

/* Line 1455 of yacc.c  */
#line 3276 "sql.yacc"
    { print_exec_sql(acl_strdup((yyvsp[(1) - (1)].str))); }
    break;

  case 581:

/* Line 1455 of yacc.c  */
#line 3277 "sql.yacc"
    { print_exec_sql(acl_strdup((yyvsp[(1) - (1)].str))); }
    break;

  case 582:

/* Line 1455 of yacc.c  */
#line 3278 "sql.yacc"
    { sprintf((yyval.str),"%s %s",(yyvsp[(1) - (2)].str),(yyvsp[(2) - (2)].str)); print_exec_sql(acl_strdup((yyval.str))); }
    break;

  case 583:

/* Line 1455 of yacc.c  */
#line 3279 "sql.yacc"
    { print_exec_sql(acl_strdup((yyvsp[(1) - (1)].str))); }
    break;

  case 584:

/* Line 1455 of yacc.c  */
#line 3280 "sql.yacc"
    { print_exec_sql(acl_strdup((yyvsp[(1) - (1)].str))); }
    break;

  case 585:

/* Line 1455 of yacc.c  */
#line 3281 "sql.yacc"
    { print_exec_sql(acl_strdup((yyvsp[(1) - (1)].str))); }
    break;

  case 586:

/* Line 1455 of yacc.c  */
#line 3282 "sql.yacc"
    { print_exec_sql(acl_strdup((yyvsp[(1) - (1)].str))); }
    break;

  case 587:

/* Line 1455 of yacc.c  */
#line 3283 "sql.yacc"
    { print_exec_sql(acl_strdup((yyvsp[(1) - (1)].str))); }
    break;

  case 588:

/* Line 1455 of yacc.c  */
#line 3287 "sql.yacc"
    { 
	char *s;
	s=acl_strdup((yyvsp[(1) - (1)].str));
	(yyval.s_select_list_item)=new_select_list_item_column_from_transform(s);
	acl_free(s);
	}
    break;

  case 589:

/* Line 1455 of yacc.c  */
#line 3293 "sql.yacc"
    {  
		(yyval.s_select_list_item)=new_select_list_item_builtin_const(E_SLI_QUERY_PLACEHOLDER);}
    break;

  case 590:

/* Line 1455 of yacc.c  */
#line 3295 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_replace_var((yyvsp[(1) - (1)].sql_string));
	}
    break;

  case 591:

/* Line 1455 of yacc.c  */
#line 3314 "sql.yacc"
    {
        add_feature("DATABASE_USED");
       conn_db((yyvsp[(2) - (3)].str));
}
    break;

  case 592:

/* Line 1455 of yacc.c  */
#line 3322 "sql.yacc"
    {
		(yyval.sql_string)=acl_strdup((yyvsp[(2) - (3)].str));
}
    break;

  case 593:

/* Line 1455 of yacc.c  */
#line 3329 "sql.yacc"
    {sprintf((yyval.str),"(%s)",(yyvsp[(2) - (3)].str));}
    break;

  case 594:

/* Line 1455 of yacc.c  */
#line 3330 "sql.yacc"
    { sprintf((yyval.str),"%s%s%s",(yyvsp[(1) - (3)].str),(yyvsp[(2) - (3)].str),(yyvsp[(3) - (3)].str));}
    break;

  case 595:

/* Line 1455 of yacc.c  */
#line 3331 "sql.yacc"
    {sprintf((yyval.str),"%d",atoi((yyvsp[(1) - (1)].str)));}
    break;

  case 596:

/* Line 1455 of yacc.c  */
#line 3332 "sql.yacc"
    {sprintf((yyval.str),"(%s%s)",(yyvsp[(1) - (2)].str),(yyvsp[(2) - (2)].str));}
    break;

  case 597:

/* Line 1455 of yacc.c  */
#line 3337 "sql.yacc"
    {strcpy((yyval.str),"+");}
    break;

  case 598:

/* Line 1455 of yacc.c  */
#line 3338 "sql.yacc"
    {strcpy((yyval.str),"-");}
    break;

  case 599:

/* Line 1455 of yacc.c  */
#line 3339 "sql.yacc"
    {strcpy((yyval.str),"*");}
    break;

  case 600:

/* Line 1455 of yacc.c  */
#line 3340 "sql.yacc"
    {strcpy((yyval.str),"/");}
    break;

  case 601:

/* Line 1455 of yacc.c  */
#line 3341 "sql.yacc"
    {strcpy((yyval.str),"%");}
    break;

  case 602:

/* Line 1455 of yacc.c  */
#line 3346 "sql.yacc"
    {strcpy((yyval.str),"+");}
    break;

  case 603:

/* Line 1455 of yacc.c  */
#line 3347 "sql.yacc"
    {strcpy((yyval.str),"-");}
    break;

  case 604:

/* Line 1455 of yacc.c  */
#line 3363 "sql.yacc"
    {sprintf((yyval.str),"%s", A4GLSQLCV_check_tablename((yyvsp[(1) - (1)].str)));}
    break;

  case 605:

/* Line 1455 of yacc.c  */
#line 3364 "sql.yacc"
    {sprintf((yyval.str),"%s.*", A4GLSQLCV_ownerize_tablename(NULL,(yyvsp[(1) - (3)].str)));}
    break;

  case 606:

/* Line 1455 of yacc.c  */
#line 3365 "sql.yacc"
    {sprintf((yyval.str),"%s.%s", (yyvsp[(1) - (3)].str),A4GLSQLCV_get_sqlconst ("rowid"));}
    break;

  case 607:

/* Line 1455 of yacc.c  */
#line 3366 "sql.yacc"
    {sprintf((yyval.str),"%s.%s", A4GLSQLCV_ownerize_tablename(NULL,(yyvsp[(1) - (3)].str)),(yyvsp[(3) - (3)].str));}
    break;

  case 608:

/* Line 1455 of yacc.c  */
#line 3367 "sql.yacc"
    {sprintf((yyval.str),"%s.%s", A4GLSQLCV_ownerize_tablename((yyvsp[(1) - (5)].str),(yyvsp[(3) - (5)].str)),(yyvsp[(5) - (5)].str));}
    break;

  case 609:

/* Line 1455 of yacc.c  */
#line 3368 "sql.yacc"
    {sprintf((yyval.str),"%s.%s", A4GLSQLCV_ownerize_tablename((yyvsp[(1) - (5)].str),(yyvsp[(3) - (5)].str)),(yyvsp[(5) - (5)].str));}
    break;

  case 610:

/* Line 1455 of yacc.c  */
#line 3369 "sql.yacc"
    {sprintf((yyval.str),"%s", (yyvsp[(1) - (4)].str)); strcpy((yyval.str), A4GLSQLCV_make_substr_s((yyvsp[(1) - (4)].str), 1,(yyvsp[(3) - (4)].str),0));}
    break;

  case 611:

/* Line 1455 of yacc.c  */
#line 3370 "sql.yacc"
    {char buff[256]; sprintf(buff,"%s.%s", A4GLSQLCV_ownerize_tablename(NULL,(yyvsp[(1) - (6)].str)),(yyvsp[(3) - (6)].str)); strcpy((yyval.str), A4GLSQLCV_make_substr_s(buff,1,(yyvsp[(5) - (6)].str),0));}
    break;

  case 612:

/* Line 1455 of yacc.c  */
#line 3371 "sql.yacc"
    {char buff[256]; sprintf(buff,"%s.%s", A4GLSQLCV_ownerize_tablename((yyvsp[(1) - (8)].str),(yyvsp[(3) - (8)].str)), (yyvsp[(5) - (8)].str)); strcpy((yyval.str), A4GLSQLCV_make_substr_s(buff,1,(yyvsp[(7) - (8)].str),0));  }
    break;

  case 613:

/* Line 1455 of yacc.c  */
#line 3372 "sql.yacc"
    {char buff[256]; sprintf(buff,"%s.%s", A4GLSQLCV_ownerize_tablename((yyvsp[(1) - (8)].str),(yyvsp[(3) - (8)].str)), (yyvsp[(5) - (8)].str));  strcpy((yyval.str), A4GLSQLCV_make_substr_s(buff,1,(yyvsp[(7) - (8)].str),0)); }
    break;

  case 614:

/* Line 1455 of yacc.c  */
#line 3374 "sql.yacc"
    {sprintf((yyval.str),"%s", (yyvsp[(1) - (6)].str)); strcpy((yyval.str), A4GLSQLCV_make_substr_s((yyvsp[(1) - (6)].str), 2,(yyvsp[(3) - (6)].str),(yyvsp[(5) - (6)].str)));}
    break;

  case 615:

/* Line 1455 of yacc.c  */
#line 3375 "sql.yacc"
    {char buff[256]; sprintf(buff,"%s.%s", A4GLSQLCV_ownerize_tablename(NULL,(yyvsp[(1) - (8)].str)),(yyvsp[(3) - (8)].str)); strcpy((yyval.str), A4GLSQLCV_make_substr_s(buff,2,(yyvsp[(5) - (8)].str),(yyvsp[(7) - (8)].str)));}
    break;

  case 616:

/* Line 1455 of yacc.c  */
#line 3376 "sql.yacc"
    {char buff[256]; sprintf(buff,"%s.%s", A4GLSQLCV_ownerize_tablename((yyvsp[(1) - (10)].str),(yyvsp[(3) - (10)].str)), (yyvsp[(5) - (10)].str)); strcpy((yyval.str), A4GLSQLCV_make_substr_s(buff,2,(yyvsp[(7) - (10)].str),(yyvsp[(9) - (10)].str)));  }
    break;

  case 617:

/* Line 1455 of yacc.c  */
#line 3377 "sql.yacc"
    {char buff[256]; sprintf(buff,"%s.%s", A4GLSQLCV_ownerize_tablename((yyvsp[(1) - (10)].str),(yyvsp[(3) - (10)].str)), (yyvsp[(5) - (10)].str));  strcpy((yyval.str), A4GLSQLCV_make_substr_s(buff,2,(yyvsp[(7) - (10)].str),(yyvsp[(9) - (10)].str))); }
    break;

  case 618:

/* Line 1455 of yacc.c  */
#line 3382 "sql.yacc"
    {
                (yyval.s_select_list_item)=(yyvsp[(1) - (1)].s_select_list_item);
        }
    break;

  case 619:

/* Line 1455 of yacc.c  */
#line 3385 "sql.yacc"
    {
                (yyval.s_select_list_item)=new_select_list_item_cast((yyvsp[(1) - (3)].s_select_list_item), (yyvsp[(3) - (3)].str));
        }
    break;

  case 620:

/* Line 1455 of yacc.c  */
#line 3394 "sql.yacc"
    { (yyvsp[(1) - (1)].s_select_list_item)=(yyvsp[(1) - (1)].s_select_list_item); }
    break;

  case 621:

/* Line 1455 of yacc.c  */
#line 3395 "sql.yacc"
    {(yyvsp[(1) - (1)].s_select_list_item)=(yyvsp[(1) - (1)].s_select_list_item);}
    break;

  case 622:

/* Line 1455 of yacc.c  */
#line 3396 "sql.yacc"
    {  (yyval.s_select_list_item)=new_select_list_item_sq(E_SQE_DONT_CARE,(yyvsp[(1) - (1)].s_select_list_item)); }
    break;

  case 623:

/* Line 1455 of yacc.c  */
#line 3397 "sql.yacc"
    { (yyval.s_select_list_item)=new_select_list_item_sq(E_SQE_ALL,(yyvsp[(2) - (2)].s_select_list_item)); }
    break;

  case 624:

/* Line 1455 of yacc.c  */
#line 3398 "sql.yacc"
    { (yyval.s_select_list_item)=new_select_list_item_sq(E_SQE_ANY,(yyvsp[(2) - (2)].s_select_list_item)); }
    break;

  case 625:

/* Line 1455 of yacc.c  */
#line 3399 "sql.yacc"
    { (yyval.s_select_list_item)=new_select_list_item_sq(E_SQE_SOME,(yyvsp[(2) - (2)].s_select_list_item)); }
    break;

  case 626:

/* Line 1455 of yacc.c  */
#line 3403 "sql.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 627:

/* Line 1455 of yacc.c  */
#line 3404 "sql.yacc"
    {strcpy((yyval.str),(yyvsp[(1) - (1)].str));}
    break;



/* Line 1455 of yacc.c  */
#line 8828 "y.tab.c"
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
#line 3410 "sql.yacc"


#if LEX_YY_PREGEN
#include "../../tools/no_yacc/cygwin/compilers/sql/lex.sqlparse_yy.c"
#else
#include "lex.yy.c"
#endif
#include "util.c"
#include "cmds.c"

