
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
     INT_VALUE = 2228,
     NAMED = 2229,
     NAMED_GEN = 2230,
     CHAR_VALUE = 2231,
     NOT_USED_1 = 2232,
     NOT_USED_2 = 2233,
     NOT_USED_3 = 2234,
     NOT_USED_4 = 2235,
     NOT_USED_5 = 2236,
     NOT_USED_6 = 2237,
     NOT_USED_7 = 2238,
     NOT_USED_8 = 2239,
     NUMBER_VALUE = 2240,
     SEMICOLON = 2241,
     QUESTION_MARK = 2242,
     CLINE = 2243,
     CH = 2244,
     MARK_VAR = 2245,
     END_MARK_VAR = 2246,
     WITH_LISTING_IN = 1001,
     DOCUMENT = 1002,
     ON_EXCEPTION = 1004,
     SET_DEBUG_FILE_TO = 1005,
     CREATE_DBA_PROCEDURE = 1010,
     CREATE_FUNCTION = 1011,
     CREATE_DBA_FUNCTION = 1012,
     USE_SESSION = 1014,
     KW_RUN_CLIENT = 1015,
     LEFT_JOIN = 1017,
     IGNORE_ERRORS = 1020,
     SQLERRMESSAGE = 1021,
     DISPLAY_NULL_TO = 1022,
     UNBUFFERED = 1023,
     KW_PICTURE = 1024,
     ON_CHANGE = 1025,
     INNER_JOIN = 1026,
     UI_INTERFACE_DOT_FRONTCALL = 1029,
     UICOMBOBOX = 1033,
     UIFORM = 1036,
     USING_BTREE = 1052,
     USING_RTREE = 1053,
     SET_BUFFERED_LOG = 1072,
     SET_LOG = 1075,
     MDY = 1077,
     WEEKDAY = 1078,
     MODE_ANSI = 1081,
     START_DATABASE = 1082,
     WITH_LOG_IN = 1083,
     SET_CONSTRAINTS_ALL_IMMEDIATE = 1084,
     DATETIME_VALUE = 1097,
     INTERVAL_VALUE = 1098,
     RECOVER_TABLE = 1099,
     ROLLFORWARD_DATABASE = 1100,
     DROP_TRIGGER = 1116,
     DROP_AUDIT_FOR = 1117,
     CREATE_AUDIT_FOR = 1118,
     EXECUTE_PROCEDURE = 1122,
     ALTER_TABLE = 1129,
     ALTER_INDEX = 1130,
     NEXT_SIZE = 1131,
     XSET_MULTIPLY_EQUAL_OPEN_BRACKET = 1168,
     XSET_ident_DOT_MULTIPLY_EQUAL_OPEN_BRACKET = 1169,
     XSET_ident_DOT_MULTIPLY_EQUAL = 1170,
     XSET_MULTIPLY_EQUAL = 1171,
     XSET_OPEN_BRACKET = 1172,
     CREATE_DATABASE = 1175,
     DROP_DATABASE = 1176,
     ADD_CONSTRAINT = 1178,
     DROP_CONSTRAINT = 1179,
     DROP_SYNONYM = 1180,
     CONSTRAINT = 1181,
     NOT_FIELD_TOUCHED_CURRENT = 1184,
     FIELD_TOUCHED_CURRENT = 1185,
     DOUBLE_PRECISION = 1192,
     COUNT_MULTIPLY = 1193,
     MODIFY_NEXT_SIZE = 1213,
     LOCK_MODE_PAGE = 1214,
     LOCK_MODE_ROW = 1215,
     UNITS_YEAR = 1222,
     UNITS_MONTH = 1223,
     UNITS_DAY = 1224,
     UNITS_HOUR = 1225,
     UNITS_MINUTE = 1226,
     UNITS_SECOND = 1227,
     TO_CLUSTER = 1232,
     TO_NOT_CLUSTER = 1233,
     CREATE_UC_IDX = 1235,
     CREATE_U_IDX = 1236,
     CREATE_C_IDX = 1237,
     CREATE_IDX = 1238,
     DOUBLE_COLON = 1248,
     SQLSICS = 1254,
     CREATE_SCHEMA = 1255,
     SQLSIRR = 1256,
     UPDATESTATS_T = 1257,
     SQLSICR = 1258,
     SQLSIDR = 1269,
     CREATE_TEMP_TABLE = 1270,
     WITH_CHECK_OPTION = 1278,
     WITH_GRANT_OPTION = 1279,
     SQLSLMNW = 1280,
     WHERE_CURRENT_OF = 1286,
     NOT_NULL_UNIQUE = 1294,
     SQLSLMW = 1301,
     ALL_PRIVILEGES = 1303,
     CREATE_SYNONYM = 1307,
     DROP_TABLE = 1308,
     INEXCLUSIVE = 1310,
     UPDATESTATS = 1315,
     CREATE_TABLE = 1341,
     DEFAULT_NULL = 1342,
     DEFAULT_TODAY = 1343,
     DEFAULT_USER = 1344,
     UNLOCK_TABLE = 1357,
     ROLLBACK_W = 1365,
     SQLSEON = 1367,
     SQLSEOFF = 1368,
     CREATE_VIEW = 1372,
     DELETE_FROM = 1373,
     EXTENT_SIZE = 1380,
     FOREIGN_KEY = 1381,
     INSERT_INTO = 1384,
     IS_NOT_NULL = 1386,
     NOT_MATCHES = 1389,
     PRIMARY_KEY = 1395,
     WITH_NO_LOG = 1402,
     INSHARE = 1405,
     BEGIN_WORK = 1411,
     DROP_INDEX = 1416,
     FOR_UPDATE_OF = 1422,
     FOR_UPDATE = 1423,
     LOCK_TABLE = 1428,
     NOT_EXISTS = 1430,
     REFERENCES = 1432,
     RENCOL = 1433,
     SMALLFLOAT = 1435,
     COMMIT_W = 1446,
     RENTAB = 1453,
     KW_CHAR = 1456,
     NCHAR = 1457,
     NVARCHAR = 1458,
     DELIMITER = 1460,
     DROP_VIEW = 1462,
     EXCLUSIVE = 1465,
     GREATER_THAN_EQ = 1469,
     INTO_TEMP = 1471,
     DATABASE = 1495,
     DATETIME = 1496,
     DISTINCT = 1498,
     FRACTION = 1505,
     GROUP_BY = 1507,
     INTERVAL = 1508,
     NOT_LIKE = 1510,
     NOT_ILIKE = 1511,
     NOT_NULL = 1512,
     RESOURCE = 1518,
     SMALLINT = 1519,
     IS_NULL = 1525,
     LESS_THAN_EQ = 1526,
     BETWEEN = 1528,
     CLOSE_BRACKET = 1531,
     CONNECT = 1534,
     KW_CURRENT = 1535,
     KW_DECIMAL = 1537,
     DEFAULT = 1539,
     INTEGER = 1547,
     SERIAL8 = 1549,
     MATCHES = 1552,
     VARCHAR = 1565,
     CLOSE_SQUARE = 1568,
     GREATER_THAN = 1569,
     KW_FALSE = 1570,
     NOT_IN = 1571,
     OPEN_BRACKET = 1573,
     KW_DELETE = 1581,
     KW_ESCAPE = 1584,
     EXISTS = 1585,
     EXTEND = 1586,
     HAVING = 1590,
     KW_INSERT = 1592,
     MINUTE = 1596,
     MODIFY = 1597,
     EQUAL = 1599,
     NOT_EQUAL = 1600,
     OPEN_SQUARE = 1602,
     PUBLIC = 1606,
     REVOKE = 1610,
     SECOND = 1614,
     KW_SELECT = 1618,
     SERIAL = 1619,
     UNIQUE = 1622,
     KW_UPDATE = 1624,
     VALUES = 1625,
     KW_NULL = 1628,
     KW_TRUE = 1629,
     ALTER = 1631,
     CHECK = 1637,
     COUNT = 1641,
     KW_FIRST = 1646,
     KW_FLOAT = 1647,
     GRANT = 1650,
     INDEX = 1653,
     LESS_THAN = 1656,
     MONEY = 1658,
     MONTH = 1659,
     KW_MULTIPLY = 1661,
     ORDER = 1662,
     OUTER = 1663,
     UNION = 1672,
     WHERE = 1675,
     KW_BYTE = 1682,
     CASE = 1684,
     KW_DATE = 1686,
     DESC = 1687,
     KW_DIVIDE = 1688,
     DROP = 1691,
     ELSE = 1692,
     FROM = 1696,
     HOUR = 1702,
     INTO = 1703,
     LIKE = 1706,
     REAL = 1715,
     SOME = 1720,
     KW_TEXT = 1724,
     KW_THEN = 1725,
     USER = 1726,
     WHEN = 1728,
     YEAR = 1731,
     KW_DOW = 1732,
     XSET = 1734,
     ADD = 1735,
     ALL = 1736,
     KW_AND = 1737,
     ANY = 1738,
     ASC = 1739,
     AVG = 1740,
     COLON = 1741,
     KW_COMMA = 1742,
     DAY = 1743,
     DBA = 1744,
     KW_FOR = 1748,
     XMAX = 1753,
     XMIN = 1754,
     KW_MINUS = 1755,
     KW_MOD = 1756,
     KW_NOT = 1757,
     KW_SUM = 1764,
     ATSIGN = 1767,
     KW_PLUS = 1768,
     KW_AS = 1774,
     KW_BY = 1776,
     KW_DOT = 1777,
     KW_IN = 1780,
     KW_ON = 1782,
     KW_OR = 1783,
     KW_TO = 1784,
     BEFORE = 1822,
     END = 1826,
     TILDE = 1833,
     ILIKE = 1834,
     FILLFACTOR = 1837,
     TIME = 1842,
     KW_TODAY = 1849,
     KW_ROWID = 1850,
     TIMESTAMP = 2198,
     KW_TAG = 2219,
     LINTMODULEISLIBRARY = 2220,
     KW_PUBLIC = 2221,
     KW_PRIVATE = 2222,
     COPYBACK = 2223,
     REFERENCES_BLOBTYPE_DEFAULT_NULL = 2224,
     REFERENCES_BLOBTYPE = 2225,
     BEGIN = 2226
   };
#endif
/* Tokens.  */
#define INT_VALUE 2228
#define NAMED 2229
#define NAMED_GEN 2230
#define CHAR_VALUE 2231
#define NOT_USED_1 2232
#define NOT_USED_2 2233
#define NOT_USED_3 2234
#define NOT_USED_4 2235
#define NOT_USED_5 2236
#define NOT_USED_6 2237
#define NOT_USED_7 2238
#define NOT_USED_8 2239
#define NUMBER_VALUE 2240
#define SEMICOLON 2241
#define QUESTION_MARK 2242
#define CLINE 2243
#define CH 2244
#define MARK_VAR 2245
#define END_MARK_VAR 2246
#define WITH_LISTING_IN 1001
#define DOCUMENT 1002
#define ON_EXCEPTION 1004
#define SET_DEBUG_FILE_TO 1005
#define CREATE_DBA_PROCEDURE 1010
#define CREATE_FUNCTION 1011
#define CREATE_DBA_FUNCTION 1012
#define USE_SESSION 1014
#define KW_RUN_CLIENT 1015
#define LEFT_JOIN 1017
#define IGNORE_ERRORS 1020
#define SQLERRMESSAGE 1021
#define DISPLAY_NULL_TO 1022
#define UNBUFFERED 1023
#define KW_PICTURE 1024
#define ON_CHANGE 1025
#define INNER_JOIN 1026
#define UI_INTERFACE_DOT_FRONTCALL 1029
#define UICOMBOBOX 1033
#define UIFORM 1036
#define USING_BTREE 1052
#define USING_RTREE 1053
#define SET_BUFFERED_LOG 1072
#define SET_LOG 1075
#define MDY 1077
#define WEEKDAY 1078
#define MODE_ANSI 1081
#define START_DATABASE 1082
#define WITH_LOG_IN 1083
#define SET_CONSTRAINTS_ALL_IMMEDIATE 1084
#define DATETIME_VALUE 1097
#define INTERVAL_VALUE 1098
#define RECOVER_TABLE 1099
#define ROLLFORWARD_DATABASE 1100
#define DROP_TRIGGER 1116
#define DROP_AUDIT_FOR 1117
#define CREATE_AUDIT_FOR 1118
#define EXECUTE_PROCEDURE 1122
#define ALTER_TABLE 1129
#define ALTER_INDEX 1130
#define NEXT_SIZE 1131
#define XSET_MULTIPLY_EQUAL_OPEN_BRACKET 1168
#define XSET_ident_DOT_MULTIPLY_EQUAL_OPEN_BRACKET 1169
#define XSET_ident_DOT_MULTIPLY_EQUAL 1170
#define XSET_MULTIPLY_EQUAL 1171
#define XSET_OPEN_BRACKET 1172
#define CREATE_DATABASE 1175
#define DROP_DATABASE 1176
#define ADD_CONSTRAINT 1178
#define DROP_CONSTRAINT 1179
#define DROP_SYNONYM 1180
#define CONSTRAINT 1181
#define NOT_FIELD_TOUCHED_CURRENT 1184
#define FIELD_TOUCHED_CURRENT 1185
#define DOUBLE_PRECISION 1192
#define COUNT_MULTIPLY 1193
#define MODIFY_NEXT_SIZE 1213
#define LOCK_MODE_PAGE 1214
#define LOCK_MODE_ROW 1215
#define UNITS_YEAR 1222
#define UNITS_MONTH 1223
#define UNITS_DAY 1224
#define UNITS_HOUR 1225
#define UNITS_MINUTE 1226
#define UNITS_SECOND 1227
#define TO_CLUSTER 1232
#define TO_NOT_CLUSTER 1233
#define CREATE_UC_IDX 1235
#define CREATE_U_IDX 1236
#define CREATE_C_IDX 1237
#define CREATE_IDX 1238
#define DOUBLE_COLON 1248
#define SQLSICS 1254
#define CREATE_SCHEMA 1255
#define SQLSIRR 1256
#define UPDATESTATS_T 1257
#define SQLSICR 1258
#define SQLSIDR 1269
#define CREATE_TEMP_TABLE 1270
#define WITH_CHECK_OPTION 1278
#define WITH_GRANT_OPTION 1279
#define SQLSLMNW 1280
#define WHERE_CURRENT_OF 1286
#define NOT_NULL_UNIQUE 1294
#define SQLSLMW 1301
#define ALL_PRIVILEGES 1303
#define CREATE_SYNONYM 1307
#define DROP_TABLE 1308
#define INEXCLUSIVE 1310
#define UPDATESTATS 1315
#define CREATE_TABLE 1341
#define DEFAULT_NULL 1342
#define DEFAULT_TODAY 1343
#define DEFAULT_USER 1344
#define UNLOCK_TABLE 1357
#define ROLLBACK_W 1365
#define SQLSEON 1367
#define SQLSEOFF 1368
#define CREATE_VIEW 1372
#define DELETE_FROM 1373
#define EXTENT_SIZE 1380
#define FOREIGN_KEY 1381
#define INSERT_INTO 1384
#define IS_NOT_NULL 1386
#define NOT_MATCHES 1389
#define PRIMARY_KEY 1395
#define WITH_NO_LOG 1402
#define INSHARE 1405
#define BEGIN_WORK 1411
#define DROP_INDEX 1416
#define FOR_UPDATE_OF 1422
#define FOR_UPDATE 1423
#define LOCK_TABLE 1428
#define NOT_EXISTS 1430
#define REFERENCES 1432
#define RENCOL 1433
#define SMALLFLOAT 1435
#define COMMIT_W 1446
#define RENTAB 1453
#define KW_CHAR 1456
#define NCHAR 1457
#define NVARCHAR 1458
#define DELIMITER 1460
#define DROP_VIEW 1462
#define EXCLUSIVE 1465
#define GREATER_THAN_EQ 1469
#define INTO_TEMP 1471
#define DATABASE 1495
#define DATETIME 1496
#define DISTINCT 1498
#define FRACTION 1505
#define GROUP_BY 1507
#define INTERVAL 1508
#define NOT_LIKE 1510
#define NOT_ILIKE 1511
#define NOT_NULL 1512
#define RESOURCE 1518
#define SMALLINT 1519
#define IS_NULL 1525
#define LESS_THAN_EQ 1526
#define BETWEEN 1528
#define CLOSE_BRACKET 1531
#define CONNECT 1534
#define KW_CURRENT 1535
#define KW_DECIMAL 1537
#define DEFAULT 1539
#define INTEGER 1547
#define SERIAL8 1549
#define MATCHES 1552
#define VARCHAR 1565
#define CLOSE_SQUARE 1568
#define GREATER_THAN 1569
#define KW_FALSE 1570
#define NOT_IN 1571
#define OPEN_BRACKET 1573
#define KW_DELETE 1581
#define KW_ESCAPE 1584
#define EXISTS 1585
#define EXTEND 1586
#define HAVING 1590
#define KW_INSERT 1592
#define MINUTE 1596
#define MODIFY 1597
#define EQUAL 1599
#define NOT_EQUAL 1600
#define OPEN_SQUARE 1602
#define PUBLIC 1606
#define REVOKE 1610
#define SECOND 1614
#define KW_SELECT 1618
#define SERIAL 1619
#define UNIQUE 1622
#define KW_UPDATE 1624
#define VALUES 1625
#define KW_NULL 1628
#define KW_TRUE 1629
#define ALTER 1631
#define CHECK 1637
#define COUNT 1641
#define KW_FIRST 1646
#define KW_FLOAT 1647
#define GRANT 1650
#define INDEX 1653
#define LESS_THAN 1656
#define MONEY 1658
#define MONTH 1659
#define KW_MULTIPLY 1661
#define ORDER 1662
#define OUTER 1663
#define UNION 1672
#define WHERE 1675
#define KW_BYTE 1682
#define CASE 1684
#define KW_DATE 1686
#define DESC 1687
#define KW_DIVIDE 1688
#define DROP 1691
#define ELSE 1692
#define FROM 1696
#define HOUR 1702
#define INTO 1703
#define LIKE 1706
#define REAL 1715
#define SOME 1720
#define KW_TEXT 1724
#define KW_THEN 1725
#define USER 1726
#define WHEN 1728
#define YEAR 1731
#define KW_DOW 1732
#define XSET 1734
#define ADD 1735
#define ALL 1736
#define KW_AND 1737
#define ANY 1738
#define ASC 1739
#define AVG 1740
#define COLON 1741
#define KW_COMMA 1742
#define DAY 1743
#define DBA 1744
#define KW_FOR 1748
#define XMAX 1753
#define XMIN 1754
#define KW_MINUS 1755
#define KW_MOD 1756
#define KW_NOT 1757
#define KW_SUM 1764
#define ATSIGN 1767
#define KW_PLUS 1768
#define KW_AS 1774
#define KW_BY 1776
#define KW_DOT 1777
#define KW_IN 1780
#define KW_ON 1782
#define KW_OR 1783
#define KW_TO 1784
#define BEFORE 1822
#define END 1826
#define TILDE 1833
#define ILIKE 1834
#define FILLFACTOR 1837
#define TIME 1842
#define KW_TODAY 1849
#define KW_ROWID 1850
#define TIMESTAMP 2198
#define KW_TAG 2219
#define LINTMODULEISLIBRARY 2220
#define KW_PUBLIC 2221
#define KW_PRIVATE 2222
#define COPYBACK 2223
#define REFERENCES_BLOBTYPE_DEFAULT_NULL 2224
#define REFERENCES_BLOBTYPE 2225
#define BEGIN 2226




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
#line 810 "y.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 822 "y.tab.c"

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
#define YYLAST   2595

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  276
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  226
/* YYNRULES -- Number of rules.  */
#define YYNRULES  627
/* YYNRULES -- Number of states.  */
#define YYNSTATES  1115

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   2246

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
       2,    22,    23,     2,    24,    25,     2,     2,     2,     2,
      26,    27,    28,     2,    29,    30,     2,    31,     2,     2,
      32,    33,    34,    35,    36,    37,    38,     2,     2,    39,
       2,     2,     2,    40,     2,     2,    41,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,    42,    43,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,    44,     2,     2,    45,     2,    46,    47,     2,
       2,    48,    49,    50,    51,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,    52,    53,    54,
      55,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,    56,    57,    58,     2,
       2,     2,    59,     2,     2,     2,     2,     2,     2,    60,
      61,    62,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    63,    64,
      65,    66,    67,     2,     2,    68,    69,     2,    70,    71,
      72,    73,     2,     2,    74,    75,     2,     2,     2,     2,
       2,     2,    76,    77,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    78,    79,    80,     2,     2,     2,     2,
       2,     2,    81,    82,    83,    84,    85,    86,     2,     2,
       2,     2,    87,    88,     2,    89,    90,    91,    92,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    93,     2,
       2,     2,     2,     2,    94,    95,    96,    97,    98,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    99,
     100,     2,     2,     2,     2,     2,     2,     2,   101,   102,
     103,     2,     2,     2,     2,     2,   104,     2,     2,     2,
       2,     2,     2,     2,   105,     2,     2,     2,     2,     2,
       2,   106,     2,   107,     2,     2,     2,   108,   109,     2,
     110,     2,     2,     2,     2,   111,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,   112,   113,   114,   115,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,   116,     2,     2,
       2,     2,     2,     2,     2,   117,     2,   118,   119,     2,
       2,     2,   120,   121,     2,     2,     2,     2,     2,     2,
     122,   123,     2,     2,   124,     2,   125,     2,     2,   126,
       2,     2,     2,     2,     2,   127,     2,     2,     2,     2,
       2,     2,   128,     2,     2,   129,     2,     2,     2,     2,
       2,   130,     2,     2,     2,     2,   131,     2,     2,     2,
       2,     2,   132,   133,     2,     2,     2,     2,   134,     2,
     135,     2,   136,   137,     2,   138,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,   139,     2,     2,     2,
       2,     2,     2,   140,     2,     2,   141,   142,   143,     2,
     144,     2,   145,     2,     2,   146,     2,     2,     2,   147,
       2,   148,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,   149,   150,     2,   151,     2,
       2,     2,     2,     2,     2,   152,     2,   153,   154,     2,
     155,   156,   157,     2,     2,     2,     2,     2,   158,   159,
       2,     2,     2,     2,     2,   160,   161,     2,   162,     2,
       2,   163,     2,     2,   164,   165,     2,   166,     2,   167,
       2,     2,     2,     2,     2,     2,     2,   168,     2,   169,
       2,     2,   170,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,   171,     2,     2,   172,   173,
     174,   175,     2,   176,     2,     2,     2,     2,     2,     2,
       2,   177,     2,     2,   178,   179,   180,     2,     2,     2,
     181,     2,   182,     2,     2,     2,   183,   184,     2,   185,
     186,     2,   187,     2,     2,     2,   188,     2,     2,     2,
     189,     2,     2,     2,   190,     2,     2,     2,   191,   192,
       2,     2,   193,     2,   194,   195,     2,     2,   196,   197,
       2,   198,     2,     2,     2,     2,     2,   199,     2,     2,
       2,   200,     2,     2,     2,     2,   201,   202,     2,     2,
     203,     2,     2,   204,     2,     2,   205,     2,   206,   207,
       2,   208,   209,   210,     2,     2,     2,     2,     2,     2,
       2,     2,   211,     2,     2,   212,     2,     2,     2,     2,
       2,     2,   213,     2,   214,     2,   215,   216,   217,     2,
       2,   218,   219,     2,     2,     2,   220,     2,     2,     2,
       2,     2,   221,   222,     2,     2,   223,     2,     2,     2,
       2,     2,     2,     2,     2,   224,     2,     2,     2,     2,
     225,     2,     2,     2,   226,   227,   228,     2,   229,     2,
       2,   230,   231,     2,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,     2,     2,     2,   243,     2,
       2,     2,     2,   244,   245,   246,   247,   248,     2,     2,
       2,     2,     2,     2,   249,     2,     2,   250,   251,     2,
       2,     2,     2,     2,   252,     2,   253,   254,     2,     2,
     255,     2,   256,   257,   258,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,   259,     2,     2,     2,   260,     2,     2,     2,
       2,     2,     2,   261,   262,     2,     2,   263,     2,     2,
       2,     2,   264,     2,     2,     2,     2,     2,     2,   265,
     266,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,   267,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,   268,
     269,   270,   271,   272,   273,   274,   275,     2,     3,     4,
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
     482,     0,    -1,   194,   473,   280,   278,    -1,    -1,   104,
     477,    -1,   212,   389,    -1,    -1,   104,   477,    -1,   212,
     389,    -1,    67,   285,   163,   185,   176,   286,   163,    -1,
      63,   286,   163,    -1,    64,   286,   163,    -1,   232,   281,
      -1,    66,   286,    -1,    65,   286,    -1,   284,    -1,   281,
     240,   284,    -1,   283,    -1,   250,   283,    -1,   476,   415,
      -1,   476,   254,   476,   415,    -1,   476,   254,   476,   254,
     476,   415,    -1,   476,   254,   208,    -1,   282,   185,   287,
      -1,   282,    -1,   285,   240,   282,    -1,   287,    -1,   286,
     240,   287,    -1,   461,    -1,   196,    -1,   289,    -1,   109,
     473,    -1,   145,   473,    -1,   131,   475,    -1,    56,   476,
      -1,   300,    -1,   291,    -1,   112,   473,   176,   305,   163,
     292,    -1,   100,   473,   176,   305,   163,   301,   292,   301,
      -1,    -1,   293,    -1,   294,    -1,   293,   294,    -1,   255,
     295,    -1,   122,     3,    -1,    62,     3,    -1,    79,    -1,
      80,    -1,     4,    -1,    -1,   297,    -1,   298,    -1,   297,
     298,    -1,   255,   295,    -1,   263,     3,    -1,    42,    -1,
      43,    -1,   473,    -1,    90,   475,   256,   299,   176,   303,
     163,   296,    -1,    89,   475,   256,   299,   176,   303,   163,
     296,    -1,    91,   475,   256,   299,   176,   303,   163,   296,
      -1,    92,   475,   256,   299,   176,   303,   163,   296,    -1,
      68,   486,    -1,    69,   486,    -1,   108,   473,   243,   473,
      -1,    58,   473,   255,     6,    -1,    57,   473,    -1,    72,
     473,    -1,    54,   473,    -1,    55,   476,    -1,    -1,   128,
      -1,    -1,   128,    -1,   304,    -1,   303,   240,   304,    -1,
     476,   237,    -1,   476,   216,    -1,   476,    -1,   306,    -1,
     305,   240,   306,    -1,   369,    -1,   367,    -1,    60,   476,
     308,    -1,    61,   475,    87,    -1,    61,   475,    88,    -1,
     309,    -1,   308,   240,   309,    -1,   310,    -1,   313,    -1,
     316,    -1,   321,    -1,   324,    -1,   320,    -1,   319,    -1,
     233,   311,    -1,   233,   176,   312,   163,    -1,   306,    -1,
     306,   259,   476,    -1,   311,    -1,   312,   240,   311,    -1,
     218,   315,    -1,   218,   176,   314,   163,    -1,   315,    -1,
     314,   240,   315,    -1,   476,    -1,   184,   318,    -1,   184,
     176,   317,   163,    -1,   318,    -1,   317,   240,   318,    -1,
     306,    -1,    79,    -1,    80,    -1,    78,     3,    -1,    70,
     367,   323,    -1,    70,   176,   322,   163,    -1,   367,   323,
      -1,   322,   240,   367,   323,    -1,    -1,    73,   476,    -1,
      71,   325,    -1,    71,   176,   325,   163,    -1,   326,    -1,
     325,   240,   326,    -1,   476,    -1,   117,    -1,    -1,   124,
     329,   473,   332,   330,    -1,    -1,   195,   331,   176,   335,
     163,    -1,   455,    -1,    -1,   176,   333,   163,    -1,   334,
      -1,   333,   240,   334,    -1,   476,    -1,   476,   254,   476,
      -1,   336,    -1,   335,   240,   336,    -1,   461,    -1,   196,
      -1,   121,   473,   279,    -1,   130,    -1,   139,    -1,    -1,
     146,    -1,   342,    -1,    49,   476,    50,     6,    48,    -1,
      49,   476,    50,     6,    -1,    51,    -1,    44,    -1,    45,
      -1,    97,   476,    -1,   111,    -1,   339,    -1,   338,    -1,
     327,    -1,   341,    -1,   375,    -1,   379,    -1,   425,    -1,
     288,    -1,   290,    -1,   307,    -1,   203,   348,   256,   473,
     258,   353,   347,    -1,   189,   348,   256,   473,   220,   353,
      -1,   203,   346,   258,   353,    -1,   189,   346,   220,   353,
      -1,   164,    -1,   158,    -1,   242,    -1,    -1,   102,    -1,
     252,   414,    -1,   107,    -1,   234,    -1,   349,    -1,   350,
      -1,   349,   240,   350,    -1,   191,   351,    -1,   182,    -1,
     177,    -1,   194,   351,    -1,   198,    -1,   204,    -1,    -1,
     176,   352,   163,    -1,   416,    -1,   352,   240,   416,    -1,
     354,    -1,   353,   240,   354,    -1,   188,    -1,   414,    -1,
     120,   473,   356,   252,   446,   358,    -1,    -1,   176,   357,
     163,    -1,   416,    -1,   357,   240,   416,    -1,    -1,   101,
      -1,   199,   176,   445,   163,    -1,   123,   176,   362,   163,
     361,    -1,   136,   363,    -1,   364,    -1,   473,    -1,   473,
     176,   364,   163,    -1,   416,    -1,   364,   240,   416,    -1,
     193,   176,   366,   163,    -1,   151,   176,   366,   163,    -1,
     127,   176,   366,   163,    -1,   416,    -1,   366,   240,   416,
      -1,   365,    -1,   360,    -1,   359,    -1,   167,   421,    -1,
     115,    -1,   114,    -1,   113,    -1,   476,   405,   370,   371,
      -1,    -1,   368,    -1,    -1,   372,    -1,   373,    -1,   372,
     373,    -1,   374,   323,    -1,   157,    -1,   105,    -1,   193,
      -1,   151,    -1,   361,    -1,   199,   176,   445,   163,    -1,
     127,    -1,    95,   376,   378,    -1,   377,    -1,   414,    -1,
     379,    -1,   378,   379,    -1,   355,    -1,   345,    -1,   181,
     389,    -1,   212,   389,    -1,   220,   383,    -1,   385,    -1,
     383,   240,   385,    -1,   383,   240,   210,   385,    -1,   383,
     240,   210,   176,   383,   163,    -1,   383,    31,   384,   256,
     389,    -1,   383,    38,   384,   256,   389,    -1,   383,    -1,
     176,   383,   163,    -1,   473,    -1,   473,   420,    -1,   473,
     252,   420,    -1,    -1,   382,   387,    -1,   388,    -1,   381,
     388,    -1,    -1,   442,    -1,   442,   380,    -1,   380,    -1,
     390,    -1,   389,   257,   390,    -1,   391,    -1,   390,   235,
     391,    -1,   392,    -1,   248,   392,    -1,   402,    -1,   176,
     389,   163,    -1,   179,   456,    -1,   135,   456,    -1,    -1,
     178,   398,    -1,    -1,   178,   398,    -1,    -1,   178,   398,
      -1,   499,    -1,   421,    -1,    -1,   248,    -1,   461,   399,
     160,    -1,   461,   399,   125,    -1,   461,   401,   461,    -1,
     461,   185,   461,    -1,   461,   185,   196,    -1,   461,   399,
     162,   461,   235,   461,    -1,   461,   223,   397,   396,    -1,
     461,   155,   397,   396,    -1,   461,   262,   397,   395,    -1,
     461,   156,   397,   395,    -1,   461,   170,   397,   394,    -1,
     461,   126,   397,   394,    -1,   186,    -1,   205,    -1,   173,
      -1,   261,    -1,   161,    -1,   147,    -1,   400,    -1,   468,
      -1,   393,    -1,   461,    -1,    -1,   234,    -1,   151,    -1,
     193,    -1,    -1,   234,    -1,   151,    -1,   193,    -1,   406,
      -1,   407,    -1,   408,    -1,   410,    -1,   141,    -1,   141,
     176,   411,   163,    -1,   192,    -1,   192,   176,     3,   163,
      -1,   169,    -1,   169,   176,     3,   163,    -1,   166,    -1,
     166,   176,   412,   409,   163,    -1,   206,   176,   412,   409,
     163,    -1,   206,    -1,   215,    -1,   168,    -1,   159,    -1,
     142,    -1,   142,   176,   411,   163,    -1,   143,    -1,   143,
     176,     3,   163,    -1,   143,   176,     3,   240,     3,   163,
      -1,   150,   423,   258,   424,    -1,   150,    -1,   154,   423,
     258,   424,    -1,   447,    -1,   154,    -1,   154,   423,   176,
       3,   163,   258,   424,    -1,   226,    -1,   213,    -1,   171,
      -1,   171,   176,     3,   163,    -1,   171,   176,     3,   240,
       3,   163,    -1,    -1,   240,   413,    -1,   202,   176,   412,
     163,    -1,   224,    -1,   138,    -1,   202,    -1,    76,    -1,
       3,    -1,     3,    -1,     3,    -1,   476,    -1,     6,    -1,
      -1,   187,     3,   172,    -1,   187,     3,   240,     3,   172,
      -1,   419,    -1,   250,   419,    -1,   418,    -1,   250,   418,
      -1,   476,   415,    -1,   471,   254,   476,   415,    -1,   471,
     254,   208,    -1,   266,    -1,   476,   415,    -1,   471,   254,
     476,   415,    -1,   476,   254,   476,   254,   476,   415,    -1,
     471,   254,   208,    -1,   476,    -1,     6,    -1,   478,    -1,
       3,    -1,   436,    -1,    -1,   423,   258,   424,    -1,   230,
      -1,   207,    -1,   241,    -1,   221,    -1,   183,    -1,   190,
      -1,   152,    -1,   230,    -1,   207,    -1,   241,    -1,   221,
      -1,   183,    -1,   190,    -1,   152,    -1,   152,   176,     3,
     163,    -1,   430,    -1,   429,    -1,   426,    -1,   140,   427,
     258,   427,    -1,   137,   471,   254,   428,   258,   428,    -1,
     476,    -1,   476,    -1,   116,   473,    -1,   134,   473,   431,
      -1,   129,    -1,   110,    -1,   433,    -1,   433,   423,   258,
     424,    -1,    52,    -1,   435,    -1,   435,   423,   176,     3,
     163,   258,   424,    -1,   435,   423,   258,   424,    -1,    53,
      -1,   165,   422,    -1,   209,   253,   438,    -1,   439,    -1,
     438,   240,   439,    -1,   440,   441,    -1,     3,    -1,   417,
      -1,    -1,   237,    -1,   216,    -1,   153,   443,    -1,   444,
      -1,   443,   240,   444,    -1,   417,    -1,     3,    -1,   389,
      -1,   455,    -1,   264,    -1,   264,   176,     3,   163,    -1,
     267,    -1,   267,   176,     3,   163,    -1,    -1,    -1,   191,
     457,   458,   449,   459,   450,   480,   386,   452,   453,    -1,
     191,   457,   458,   459,   386,   452,    -1,    -1,   211,   404,
     451,    -1,    -1,   437,    -1,   437,   148,   454,   302,    -1,
     148,   454,   302,    -1,   476,    -1,   191,   457,   458,   459,
     386,    -1,   176,   191,   457,   458,   459,   386,   163,    -1,
      -1,   201,     3,    -1,    -1,   234,    -1,   151,    -1,   193,
      -1,   460,    -1,   459,   240,   460,    -1,   461,    -1,   461,
     476,    -1,   461,   252,   476,    -1,   499,    -1,   246,   499,
      -1,   251,   499,    -1,   499,   217,   461,    -1,   499,   467,
      -1,   499,   208,   461,    -1,   499,   251,   461,    -1,   499,
     246,   461,    -1,   421,    -1,   197,    -1,   174,    -1,   228,
      -1,   265,    -1,   266,    -1,   264,    -1,   208,    -1,    77,
      -1,   238,   176,   403,   461,   163,    -1,   244,   176,   403,
     461,   163,    -1,   245,   176,   403,   461,   163,    -1,   249,
     176,   403,   461,   163,    -1,   200,   176,   403,   461,   163,
      -1,     4,   176,   163,    -1,     4,   176,   465,   163,    -1,
     230,   176,   465,   163,    -1,   207,   176,   465,   163,    -1,
     241,   176,   465,   163,    -1,    46,   176,   465,   163,    -1,
      47,   176,   465,   163,    -1,   231,   176,   465,   163,    -1,
     215,   176,   465,   163,    -1,   176,   461,   163,    -1,   180,
     176,   466,   163,    -1,   432,    -1,   434,    -1,   214,   463,
     260,    -1,   464,    -1,   463,   464,    -1,   229,   389,   227,
     461,    -1,   219,   461,    -1,   461,    -1,   465,   240,   461,
      -1,   165,   240,   423,   258,   424,    -1,   492,   240,   423,
     258,   424,    -1,   165,   423,   258,   424,    -1,   461,   240,
     423,   258,   424,    -1,    81,    -1,    82,    -1,    83,    -1,
      84,    -1,    85,    -1,    86,    -1,   461,   255,   176,   469,
     163,    -1,   461,   255,   456,    -1,   461,   175,   176,   469,
     163,    -1,   461,   175,   456,    -1,   470,    -1,   469,   240,
     470,    -1,   492,    -1,   421,    -1,   246,     3,    -1,   246,
     478,    -1,   472,    -1,     6,    -1,     6,   254,   476,    -1,
     476,    -1,   476,   239,   476,    -1,   476,   239,     6,   254,
     476,    -1,   476,   250,   476,    -1,   476,   250,   476,   239,
     476,    -1,   476,   250,   476,   239,     6,   254,   476,    -1,
     474,    -1,     6,   254,   476,    -1,   476,   254,   476,    -1,
       6,    -1,   476,    -1,   476,   239,   476,    -1,   476,   239,
       6,   254,   476,    -1,   476,   250,   476,    -1,   476,   250,
     476,   239,   476,    -1,   476,   250,   476,   239,     6,   254,
     476,    -1,     6,   254,   476,    -1,     6,    -1,   476,    -1,
     476,   239,   476,    -1,   476,   239,     6,   254,   476,    -1,
     476,   250,   476,    -1,   476,   250,   476,   239,   476,    -1,
     476,   250,   476,   239,     6,   254,   476,    -1,     4,    -1,
       4,    -1,    15,    -1,   254,     3,    -1,     4,    -1,     6,
      -1,    -1,   476,    -1,   484,    -1,   482,    16,   484,    -1,
     328,    -1,   277,    -1,   337,    -1,    -1,   493,    -1,   344,
      -1,   485,    -1,   491,    -1,   483,    -1,   343,    -1,     1,
      -1,   487,   488,    -1,   481,    -1,   448,    -1,    -1,   133,
      -1,   132,   489,    -1,   490,    -1,   489,   240,   490,    -1,
     476,    -1,   476,   254,   476,    -1,     6,   254,   476,   254,
     476,    -1,   119,    -1,   118,    -1,   106,   501,    -1,   103,
      -1,    99,    -1,    96,    -1,    94,    -1,    98,    -1,   498,
      -1,    17,    -1,   494,    -1,   149,   479,   340,    -1,    20,
       6,    21,    -1,   176,   495,   163,    -1,   495,   496,   495,
      -1,     3,    -1,   497,     3,    -1,   251,    -1,   246,    -1,
     208,    -1,   217,    -1,   247,    -1,   251,    -1,   246,    -1,
     476,    -1,   476,   254,   208,    -1,   476,   254,   266,    -1,
     476,   254,   476,    -1,   476,   254,   476,   254,   476,    -1,
       6,   254,   476,   254,   476,    -1,   476,   187,   495,   172,
      -1,   476,   254,   476,   187,   495,   172,    -1,   476,   254,
     476,   254,   476,   187,   495,   172,    -1,     6,   254,   476,
     254,   476,   187,   495,   172,    -1,   476,   187,   495,   240,
     495,   172,    -1,   476,   254,   476,   187,   495,   240,   495,
     172,    -1,   476,   254,   476,   254,   476,   187,   495,   240,
     495,   172,    -1,     6,   254,   476,   254,   476,   187,   495,
     240,   495,   172,    -1,   500,    -1,   500,    93,   405,    -1,
     462,    -1,   492,    -1,   456,    -1,   234,   456,    -1,   236,
     456,    -1,   225,   456,    -1,    -1,     3,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   425,   425,   451,   454,   471,   476,   479,   496,   502,
     511,   520,   529,   536,   551,   606,   613,   624,   627,   632,
     639,   656,   673,   694,   703,   706,   714,   717,   725,   726,
     733,   736,   744,   747,   751,   757,   758,   762,   772,   786,
     787,   791,   792,   797,   805,   813,   821,   829,   839,   841,
     841,   844,   845,   849,   856,   863,   870,   879,   883,   890,
     902,   913,   919,   923,   927,   932,   936,   939,   943,   946,
     953,   954,   964,   965,   969,   970,   974,   983,   992,   999,
    1002,  1008,  1011,  1022,  1026,  1031,  1038,  1041,  1050,  1053,
    1057,  1061,  1065,  1069,  1073,  1081,  1085,  1093,  1096,  1103,
    1106,  1113,  1116,  1123,  1124,  1129,  1133,  1136,  1142,  1145,
    1151,  1158,  1159,  1163,  1171,  1175,  1182,  1184,  1189,  1190,
    1194,  1196,  1202,  1203,  1206,  1217,  1223,  1223,  1232,  1232,
    1241,  1266,  1269,  1277,  1280,  1287,  1290,  1298,  1299,  1305,
    1306,  1314,  1332,  1336,  1341,  1342,  1352,  1361,  1365,  1369,
    1374,  1378,  1382,  1385,  1392,  1393,  1394,  1398,  1399,  1400,
    1401,  1402,  1403,  1404,  1412,  1413,  1414,  1415,  1420,  1421,
    1422,  1425,  1426,  1427,  1431,  1432,  1433,  1437,  1438,  1442,
    1449,  1450,  1451,  1458,  1459,  1462,  1463,  1468,  1469,  1474,
    1475,  1480,  1481,  1486,  1493,  1494,  1499,  1500,  1504,  1505,
    1512,  1520,  1527,  1534,  1538,  1539,  1544,  1545,  1551,  1555,
    1560,  1567,  1568,  1574,  1577,  1580,  1587,  1588,  1589,  1590,
    1596,  1617,  1618,  1621,  1623,  1630,  1633,  1639,  1647,  1652,
    1658,  1663,  1669,  1672,  1677,  1685,  1694,  1699,  1703,  1704,
    1710,  1713,  1724,  1733,  1740,  1746,  1747,  1750,  1755,  1766,
    1770,  1777,  1778,  1782,  1786,  1790,  1797,  1802,  1810,  1813,
    1819,  1822,  1827,  1832,  1845,  1848,  1854,  1857,  1863,  1866,
    1872,  1875,  1882,  1886,  1897,  1897,  1898,  1898,  1899,  1899,
    1902,  1907,  1912,  1913,  1918,  1927,  1935,  1938,  1941,  1945,
    1952,  1955,  1959,  1962,  1965,  1968,  1974,  1981,  1984,  1987,
    1990,  1991,  1996,  1999,  2002,  2005,  2012,  2013,  2014,  2018,
    2025,  2026,  2027,  2031,  2045,  2052,  2053,  2054,  2058,  2059,
    2064,  2065,  2074,  2076,  2085,  2088,  2096,  2106,  2114,  2116,
    2117,  2118,  2119,  2120,  2121,  2122,  2130,  2131,  2132,  2133,
    2134,  2135,  2136,  2137,  2138,  2139,  2140,  2150,  2151,  2157,
    2159,  2160,  2161,  2162,  2166,  2170,  2174,  2181,  2182,  2187,
    2188,  2192,  2200,  2203,  2210,  2213,  2223,  2226,  2229,  2232,
    2239,  2246,  2254,  2263,  2270,  2274,  2275,  2276,  2277,  2282,
    2284,  2293,  2293,  2293,  2293,  2293,  2293,  2293,  2294,  2294,
    2294,  2294,  2294,  2294,  2294,  2294,  2339,  2340,  2341,  2346,
    2347,  2350,  2351,  2355,  2362,  2373,  2374,  2387,  2388,  2392,
    2396,  2397,  2400,  2406,  2410,  2433,  2443,  2446,  2452,  2461,
    2465,  2472,  2473,  2475,  2480,  2486,  2489,  2495,  2496,  2503,
    2516,  2526,  2533,  2550,  2557,  2582,  2584,  2582,  2606,  2650,
    2651,  2665,  2668,  2675,  2685,  2697,  2703,  2716,  2731,  2733,
    2739,  2740,  2741,  2742,  2752,  2755,  2761,  2764,  2769,  2778,
    2781,  2785,  2792,  2795,  2798,  2801,  2804,  2807,  2808,  2809,
    2810,  2811,  2812,  2813,  2814,  2815,  2817,  2821,  2825,  2829,
    2833,  2837,  2841,  2845,  2848,  2851,  2854,  2857,  2860,  2863,
    2866,  2869,  2873,  2877,  2881,  2889,  2892,  2901,  2907,  2914,
    2917,  2945,  2948,  2951,  2954,  2960,  2961,  2962,  2963,  2964,
    2965,  2970,  2974,  2978,  2982,  2989,  2992,  2997,  2998,  2999,
    3001,  3007,  3017,  3021,  3025,  3029,  3033,  3037,  3041,  3045,
    3053,  3063,  3068,  3072,  3076,  3080,  3084,  3089,  3093,  3097,
    3105,  3108,  3113,  3114,  3115,  3120,  3121,  3122,  3130,  3133,
    3138,  3139,  3143,  3144,  3149,  3173,  3190,  3191,  3195,  3202,
    3208,  3218,  3220,  3223,  3224,  3225,  3226,  3228,  3231,  3235,
    3240,  3244,  3250,  3251,  3254,  3259,  3260,  3263,  3264,  3265,
    3275,  3276,  3277,  3278,  3279,  3280,  3281,  3282,  3286,  3292,
    3294,  3313,  3321,  3328,  3329,  3330,  3331,  3336,  3337,  3338,
    3339,  3340,  3345,  3346,  3362,  3363,  3364,  3365,  3366,  3367,
    3368,  3369,  3370,  3371,  3373,  3374,  3375,  3376,  3381,  3384,
    3393,  3394,  3395,  3396,  3397,  3398,  3402,  3403
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
  "WITH_LISTING_IN", "DOCUMENT", "ON_EXCEPTION", "SET_DEBUG_FILE_TO",
  "CREATE_DBA_PROCEDURE", "CREATE_FUNCTION", "CREATE_DBA_FUNCTION",
  "USE_SESSION", "KW_RUN_CLIENT", "LEFT_JOIN", "IGNORE_ERRORS",
  "SQLERRMESSAGE", "DISPLAY_NULL_TO", "UNBUFFERED", "KW_PICTURE",
  "ON_CHANGE", "INNER_JOIN", "UI_INTERFACE_DOT_FRONTCALL", "UICOMBOBOX",
  "UIFORM", "USING_BTREE", "USING_RTREE", "SET_BUFFERED_LOG", "SET_LOG",
  "MDY", "WEEKDAY", "MODE_ANSI", "START_DATABASE", "WITH_LOG_IN",
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
       0,   256,  2227,  2228,  2229,  2230,  2231,  2232,  2233,  2234,
    2235,  2236,  2237,  2238,  2239,  2240,  2241,  2242,  2243,  2244,
    2245,  2246,  1001,  1002,  1004,  1005,  1010,  1011,  1012,  1014,
    1015,  1017,  1020,  1021,  1022,  1023,  1024,  1025,  1026,  1029,
    1033,  1036,  1052,  1053,  1072,  1075,  1077,  1078,  1081,  1082,
    1083,  1084,  1097,  1098,  1099,  1100,  1116,  1117,  1118,  1122,
    1129,  1130,  1131,  1168,  1169,  1170,  1171,  1172,  1175,  1176,
    1178,  1179,  1180,  1181,  1184,  1185,  1192,  1193,  1213,  1214,
    1215,  1222,  1223,  1224,  1225,  1226,  1227,  1232,  1233,  1235,
    1236,  1237,  1238,  1248,  1254,  1255,  1256,  1257,  1258,  1269,
    1270,  1278,  1279,  1280,  1286,  1294,  1301,  1303,  1307,  1308,
    1310,  1315,  1341,  1342,  1343,  1344,  1357,  1365,  1367,  1368,
    1372,  1373,  1380,  1381,  1384,  1386,  1389,  1395,  1402,  1405,
    1411,  1416,  1422,  1423,  1428,  1430,  1432,  1433,  1435,  1446,
    1453,  1456,  1457,  1458,  1460,  1462,  1465,  1469,  1471,  1495,
    1496,  1498,  1505,  1507,  1508,  1510,  1511,  1512,  1518,  1519,
    1525,  1526,  1528,  1531,  1534,  1535,  1537,  1539,  1547,  1549,
    1552,  1565,  1568,  1569,  1570,  1571,  1573,  1581,  1584,  1585,
    1586,  1590,  1592,  1596,  1597,  1599,  1600,  1602,  1606,  1610,
    1614,  1618,  1619,  1622,  1624,  1625,  1628,  1629,  1631,  1637,
    1641,  1646,  1647,  1650,  1653,  1656,  1658,  1659,  1661,  1662,
    1663,  1672,  1675,  1682,  1684,  1686,  1687,  1688,  1691,  1692,
    1696,  1702,  1703,  1706,  1715,  1720,  1724,  1725,  1726,  1728,
    1731,  1732,  1734,  1735,  1736,  1737,  1738,  1739,  1740,  1741,
    1742,  1743,  1744,  1748,  1753,  1754,  1755,  1756,  1757,  1764,
    1767,  1768,  1774,  1776,  1777,  1780,  1782,  1783,  1784,  1822,
    1826,  1833,  1834,  1837,  1842,  1849,  1850,  2198,  2219,  2220,
    2221,  2222,  2223,  2224,  2225,  2226
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint16 yyr1[] =
{
       0,   276,   277,   278,   278,   278,   279,   279,   279,   280,
     280,   280,   280,   280,   280,   281,   281,   282,   282,   283,
     283,   283,   283,   284,   285,   285,   286,   286,   287,   287,
     288,   289,   289,   289,   289,   290,   290,   291,   291,   292,
     292,   293,   293,   294,   294,   294,   294,   294,   295,   296,
     296,   297,   297,   298,   298,   298,   298,   299,   300,   300,
     300,   300,   300,   300,   300,   300,   300,   300,   300,   300,
     301,   301,   302,   302,   303,   303,   304,   304,   304,   305,
     305,   306,   306,   307,   307,   307,   308,   308,   309,   309,
     309,   309,   309,   309,   309,   310,   310,   311,   311,   312,
     312,   313,   313,   314,   314,   315,   316,   316,   317,   317,
     318,   319,   319,   320,   321,   321,   322,   322,   323,   323,
     324,   324,   325,   325,   326,   327,   329,   328,   331,   330,
     330,   332,   332,   333,   333,   334,   334,   335,   335,   336,
     336,   337,   338,   339,   340,   340,   341,   342,   342,   342,
     342,   342,   342,   342,   343,   343,   343,   344,   344,   344,
     344,   344,   344,   344,   345,   345,   345,   345,   346,   346,
     346,   347,   347,   347,   348,   348,   348,   349,   349,   350,
     350,   350,   350,   350,   350,   351,   351,   352,   352,   353,
     353,   354,   354,   355,   356,   356,   357,   357,   358,   358,
     359,   360,   361,   362,   363,   363,   364,   364,   365,   365,
     365,   366,   366,   367,   367,   367,   368,   368,   368,   368,
     369,   370,   370,   371,   371,   372,   372,   373,   374,   374,
     374,   374,   374,   374,   374,   375,   376,   377,   378,   378,
     379,   379,   380,   381,   382,   383,   383,   383,   383,   383,
     383,   384,   384,   385,   385,   385,   386,   386,   387,   387,
     388,   388,   388,   388,   389,   389,   390,   390,   391,   391,
     392,   392,   393,   393,   394,   394,   395,   395,   396,   396,
     397,   398,   399,   399,   400,   400,   400,   400,   400,   400,
     400,   400,   400,   400,   400,   400,   401,   401,   401,   401,
     401,   401,   402,   402,   402,   402,   403,   403,   403,   403,
     404,   404,   404,   404,   405,   406,   406,   406,   407,   407,
     408,   408,   408,   408,   408,   408,   408,   408,   408,   408,
     408,   408,   408,   408,   408,   408,   408,   408,   408,   408,
     408,   408,   408,   408,   408,   408,   408,   409,   409,   410,
     410,   410,   410,   410,   411,   412,   413,   414,   414,   415,
     415,   415,   416,   416,   417,   417,   418,   418,   418,   418,
     419,   419,   419,   419,   420,   421,   421,   421,   421,   422,
     422,   423,   423,   423,   423,   423,   423,   423,   424,   424,
     424,   424,   424,   424,   424,   424,   425,   425,   425,   426,
     426,   427,   428,   429,   430,   431,   431,   432,   432,   433,
     434,   434,   434,   435,   436,   437,   438,   438,   439,   440,
     440,   441,   441,   441,   442,   443,   443,   444,   444,   445,
     446,   447,   447,   447,   447,   449,   450,   448,   451,   452,
     452,   453,   453,   453,   453,   454,   455,   456,   457,   457,
     458,   458,   458,   458,   459,   459,   460,   460,   460,   461,
     461,   461,   462,   462,   462,   462,   462,   462,   462,   462,
     462,   462,   462,   462,   462,   462,   462,   462,   462,   462,
     462,   462,   462,   462,   462,   462,   462,   462,   462,   462,
     462,   462,   462,   462,   462,   463,   463,   464,   464,   465,
     465,   466,   466,   466,   466,   467,   467,   467,   467,   467,
     467,   468,   468,   468,   468,   469,   469,   470,   470,   470,
     470,   471,   472,   472,   472,   472,   472,   472,   472,   472,
     473,   474,   474,   474,   474,   474,   474,   474,   474,   474,
     475,   475,   475,   475,   475,   475,   475,   475,   476,   477,
     478,   478,   479,   479,   480,   481,   482,   482,   483,   483,
     483,   484,   484,   484,   484,   484,   484,   484,   484,   485,
     486,   487,   488,   488,   488,   489,   489,   490,   490,   490,
     491,   491,   491,   491,   491,   491,   491,   491,   492,   492,
     492,   493,   494,   495,   495,   495,   495,   496,   496,   496,
     496,   496,   497,   497,   498,   498,   498,   498,   498,   498,
     498,   498,   498,   498,   498,   498,   498,   498,   499,   499,
     500,   500,   500,   500,   500,   500,   501,   501
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
#define YYPACT_NINF -819
static const yytype_int16 yypact[] =
{
    2392,  -819,  -819,  -819,   133,  -819,   642,   133,   133,   642,
     642,   133,   678,   133,   133,   642,   678,   678,   678,   678,
    -819,   687,  -819,   133,  -819,  -819,   642,  -819,   250,   642,
     642,  -819,   642,   642,  -819,  -819,  -819,   642,   642,  -819,
    -819,   678,   642,   703,  -819,   133,   642,   726,   523,  -139,
     642,   523,  -819,  -819,  -819,  -819,  -819,  -819,  -819,  -819,
    -819,  -819,  -819,  -819,  -819,  -819,  -819,  -819,  -819,  -819,
    -819,  -819,  -819,  -819,  -819,  -819,  -819,   337,  -819,  -819,
    -819,   431,  -819,  -819,  -819,   214,    45,  -819,  -819,   372,
    -819,  -819,  -819,    72,   290,    90,   392,   -19,  -819,  -819,
    -819,  -819,  -819,   116,   159,   187,   283,  -819,   196,  -819,
    -819,  -819,  -819,   336,  -819,  -819,   254,  -819,   403,  -819,
     407,   -24,   642,  -819,    52,   330,   353,  -819,    18,   343,
    -819,  -819,  -819,  -819,   442,  -819,  -819,  -819,  -819,  -819,
     432,   432,  -819,  -819,  -819,  -819,   411,   381,   418,  -819,
     661,   -18,   134,   414,   429,  -819,  2392,   741,  -819,  -819,
     673,   133,   756,   133,   133,   690,   575,   121,   700,  -819,
    -819,   166,   145,   331,   464,  -819,  -819,  -819,  -819,  -819,
    -819,  -819,  -819,   133,  -819,  -819,   765,   133,   642,   642,
     642,   642,   196,  -819,   103,   642,   103,   100,   456,   707,
    1038,  -819,   539,  -819,  -819,  -819,   133,   133,   771,   133,
     133,  -819,  -819,   100,  -819,  -819,   113,   642,   650,  -819,
    -819,  -819,  -819,  -819,  1291,  1291,  1291,  1291,    68,    68,
      37,   113,   642,  -819,   462,   468,   493,  -819,   686,  -819,
     483,  -819,   509,  -819,  -819,   562,   576,   579,   616,   580,
     583,  -819,  -819,  -819,   693,   133,   540,  -819,  -819,  -819,
     103,  -819,  -819,  -819,  -819,   486,   133,  -819,  -819,   103,
     504,  -819,   290,  -819,   531,  -819,   555,   635,  -819,   636,
     637,   638,  -819,   -67,  -819,  -819,    -8,   703,    31,  -819,
    -819,   544,   356,   627,  -819,  -819,  -819,   645,   569,  -819,
    -819,   818,   658,   666,  -819,  -819,  -819,   667,   364,  -819,
     913,   667,   669,  -819,   674,   689,  -819,   205,   694,   667,
    -819,   695,   705,   667,   667,   706,   708,   711,   716,  2190,
    1177,   717,  2190,   823,  -819,  -819,  -819,   592,   602,  -819,
    -819,  -819,  -819,  -819,  -819,  -819,   364,  -819,   364,  -819,
    -819,   691,  -819,  -819,    28,  -819,  -819,  -819,  -819,   417,
     769,   133,   340,  -819,   621,  -819,   640,  -819,   656,  -819,
      32,  -819,  -819,   662,  -819,  -819,   683,  -819,  1937,  1430,
    -819,    33,  -819,  -819,    54,   665,   665,   133,  -819,  -819,
      60,   125,   668,   713,  -819,   707,  1038,  -819,   662,   649,
     133,   133,   741,  -819,   133,   772,   100,   100,   100,    66,
     693,   100,  1038,   133,  -819,   106,   133,   140,  -819,  -819,
    -819,   733,   734,   735,   364,   364,  -819,   736,  -819,   737,
     739,   744,   745,   746,  -819,  -819,  -819,  -819,   747,   748,
     499,  -819,  -819,  -819,  -819,  -819,   147,  -819,  -819,   180,
     133,  -819,   133,   785,   133,   133,   133,   133,   797,   103,
     156,  -819,  -819,   100,    80,   924,   133,  -819,  -139,   828,
    -819,  1545,   133,   910,  1937,  1937,   743,  -819,  -819,  -819,
    -819,  -819,  -819,  -819,  -819,  -819,   677,  -139,   -47,  1391,
    -819,  2051,    14,  1937,  1937,  1038,   361,  -819,  1937,  -819,
    1937,  1937,  -819,  -819,    14,  1937,    14,    14,   417,  -819,
      14,   417,  -819,  1038,  1038,   679,   -15,  2190,  -819,  2190,
    2190,  -819,  2190,  -819,   760,  1684,  -819,  -819,  2190,  -819,
     762,  -819,  2190,   457,  1937,    58,    53,  -819,  -819,  -819,
    -819,  -819,  -819,  1937,  1937,  1937,  1937,  -819,   486,   186,
    -819,   688,  -819,  -819,  -819,   133,   133,   789,  -819,   100,
     113,   113,   692,  -819,    59,   777,  -819,  1291,  -819,  -819,
     758,    68,    84,  -819,    68,  1291,  -819,   592,   113,   696,
    -819,  -819,  -819,   697,  -819,   778,   704,  -819,   204,  -819,
     243,  -819,   616,  -819,   253,   592,   782,  -819,  -819,  -819,
    -819,   103,   944,   944,   945,   699,     0,   946,   951,   952,
     958,   946,   946,   959,   960,  -819,  -819,  -819,    87,  -819,
     334,  -819,   133,  -819,   103,  -819,  -819,   710,  -819,   256,
    -819,   241,   266,   273,   274,  -819,   156,  -819,   964,  -819,
    -819,   967,   968,  -819,   156,  -819,  -819,  -819,   784,    36,
     720,   -18,  -819,  -819,  -819,  -819,   275,   721,  -819,   277,
     279,   426,   -18,  -819,  -819,   304,   738,   813,   740,  -819,
    -819,  -819,  1937,   300,  -819,   -85,  -819,  -819,   301,   302,
     306,  1937,   308,  1937,  1937,  1937,   602,  -819,   426,   974,
     426,   801,   417,   803,   804,   801,    94,  -819,  -819,  -819,
     803,    94,  -819,   804,  -819,  -819,  1937,  -819,  -819,    58,
    -819,  -819,   443,   980,  -819,  -819,   236,  -819,  -819,  -819,
    -819,  -819,  -819,   133,   133,   808,  -819,  -819,   731,  -819,
    -819,  -819,   662,  1937,  -819,   133,  -819,  -819,   810,  -819,
    -819,   339,  -819,  -819,    46,   133,   133,   851,   100,  -819,
     100,  -819,   693,  -819,  -819,  -819,  -819,   825,   826,   309,
     426,   988,   426,  -819,   753,   831,   310,   834,   835,   753,
     836,   837,  -819,  -819,  -819,  -819,   642,  -819,  -819,  -819,
     827,  -819,  -819,   334,  -819,   693,  -819,  -819,   133,   101,
     133,  -819,  -819,   101,   101,   101,   797,  -819,  -819,  -819,
    -819,  -819,  -819,  -819,   998,   133,  1937,  -819,  1937,   133,
    -819,  -819,   829,  -819,  -819,  -819,  -819,  -819,  -819,  -819,
    1937,   364,   749,   364,  -819,   364,   841,  -819,  1937,  -819,
    -819,  -819,   843,  -819,   845,   846,   847,  -819,   848,  -819,
      87,  -819,    87,  -819,    87,  -819,  -819,    74,  -819,   318,
    -819,  -819,  -819,   321,  -819,   767,   258,  -819,  -819,  -819,
      58,  -819,  -819,  -819,    58,  -819,    58,   133,  -819,  -819,
    1798,   133,  -819,   792,  -819,  1291,   133,  -819,  -819,   687,
    -819,  -819,  -819,  -819,  -819,  -819,  -819,  -819,  -819,  -819,
    1010,  -819,   852,  -819,  1011,   853,  -819,  -819,  1014,  -819,
    -819,   855,  -819,  -819,  -819,   844,  1038,  -819,  -819,  -819,
    -819,  -819,   968,  1016,  -819,   101,  -819,  -819,  -819,  -819,
    -819,  -819,   849,   784,    47,  -819,   842,  1019,    47,   770,
     426,   773,   774,  -819,  -819,  -819,  -819,  -819,  -819,   775,
    -819,  -819,  -819,  -819,  -819,  -819,  -819,   109,  -819,  1937,
    -819,   167,   622,   478,   850,  -819,   325,  -819,  -819,  -819,
     642,   423,   824,   326,   784,  -819,   873,   780,  -819,  -819,
    -819,   876,  -819,   100,   877,  -819,  -819,  -819,  -819,  -819,
    -819,    58,   880,   882,   426,   886,   426,   426,   426,  -819,
    -819,  -819,  -819,    58,    58,  -819,  1798,    89,  -819,    62,
      65,  1038,  1038,  -819,   110,  -819,  -819,   869,    26,   319,
    -819,  -819,  -819,   426,  -819,   347,  -819,   556,  -819,  -819,
    -819,  -819,  -819,  -819,   489,   582,  -819,   104,   104,   128,
     133,  -819,  -819,  -819,    79,  -819,  -819,  -819,   811,  -819,
     798,   399,   592,   592,  -819,  -819,  -819,  -819,  -819,   863,
     133,   806,   908,  -819,  -819,  -819,  -819,    58,  -819,  -819,
      58,   642,    89,   812,   814,   150,  -819,  -819,  -819,    65,
      97,  -819,  -139,  -819,   932,  -819,    70,   133,   541,   589,
      92,  1038,  1038,   642,  -819,  -819,  -819,   784,   -18,  -819,
    -819,  -819,  -819,   822,  -819,   365,   932,  -819,  -819,  -819,
     592,   592,   107,  -819,  1937,    70,  -819,  -819,  -819,  -819,
    -819,    47,  -819,   824,  -819
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -819,  -819,  -819,  -819,  -819,  -819,  -177,   680,   490,  -819,
    -195,   -46,  -819,  -819,  -819,  -819,   433,  -819,   427,   162,
    -257,  -819,   160,   480,  -819,   280,   -16,   219,   287,   885,
    -129,  -819,  -819,   816,  -819,  -219,  -819,  -819,  -819,  -246,
    -819,  -819,  -208,  -819,  -819,  -819,  -819,  -363,  -819,   840,
     670,  -819,  -819,  -819,  -819,  -819,  -819,  -819,   359,  -819,
     102,  -819,  -819,  -819,  -819,  -819,  -819,  -819,  -819,  -819,
    1032,  -819,  1045,  -819,   879,   961,  -819,  -183,   543,  -819,
    -819,  -819,  -819,  -819,  -819,   352,  -819,  -819,   127,  -819,
     251,  -145,  -819,  -819,  -819,  -819,  -819,   322,  -819,  -819,
    -819,  -819,  -819,    -3,    99,  -819,  -819,  -710,    81,  -818,
    -778,  -819,   108,  -182,   594,   597,   786,  -819,   413,   415,
     419,   369,   -34,  -819,  -819,  -819,  -819,   -79,  -819,   566,
    -819,  -819,  -819,   348,  -819,   519,  -390,  -819,    -5,  -364,
    -173,  -695,    91,   858,    93,  -565,  -819,  -303,  -596,  -819,
    -819,   914,   571,  -819,  -819,  -819,  -819,  -819,  -819,  -819,
    -819,  -819,  -819,    24,  -819,  -819,  -819,  -819,    61,   225,
    -819,  -819,  -819,  -819,  -819,  -819,    19,  -819,    56,   788,
    -172,  -433,  -602,  -750,   401,    98,  -819,  -819,   639,   385,
    -819,  -819,  -819,   435,   190,   -42,  -819,    49,  -819,   839,
      -4,   751,   292,  -819,  -819,  -819,  -819,  -819,   984,  -819,
    1128,  -819,  -819,  -819,   750,  -819,  -455,  -819,  -819,  -686,
    -819,  -819,  -819,   -87,  -819,  -819
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
     820,   708,   150,    84,   102,   284,    84,   284,  1033,    84,
     928,   125,    84,  1091,    84,   113,   125,   944,   116,   117,
     199,   118,   119,    84,    84,   125,   120,   121,    84,   299,
     296,   124,   837,   772,   839,   131,   458,   296,    84,   152,
     298,    84,   299,   410,    84,   193,   125,    84,    84,   299,
      86,   300,   296,    84,   301,   298,   663,    84,    89,   107,
    1027,   605,   606,  1027,   299,    84,   300,  1028,   488,   301,
    1028,   848,    84,   220,    86,   477,   848,    84,  1027,   490,
     270,   395,   828,   910,   911,  1028,   980,   499,   878,    84,
     983,   502,   503,   235,    84,   460,    86,   239,   241,   242,
     243,   689,   203,   258,   891,   669,   893,   265,   268,   265,
      84,   202,   513,   459,   951,   221,   761,  1046,   952,   273,
     953,   204,   275,   276,    89,    89,    89,    89,   200,   282,
     265,    89,   265,   292,   462,   558,   566,   224,   225,   226,
     227,   228,   363,   365,   367,   368,   130,   670,   803,   292,
     513,  1066,   111,    89,   577,   535,   222,   568,   638,  1047,
     186,   768,   769,   570,   391,   391,   245,   111,    89,   591,
     246,   187,   459,   587,   709,   639,   640,   278,   278,   278,
     278,   851,   508,   690,   285,   511,   851,  1084,   671,   396,
     997,   258,   308,   114,   247,  1099,   265,   208,   762,   308,
    1048,   714,   268,  1000,   160,   265,   376,   960,   209,   598,
    1110,   463,   559,   567,   308,   941,   804,   941,   641,   941,
    1061,   399,   536,   292,   802,   487,   560,   733,   647,   245,
     646,  1001,   740,   246,   567,  1017,   249,   255,   879,   161,
     571,   372,   250,   600,   710,  1086,   592,  1024,  1025,   711,
     621,   735,   465,   675,  1030,  1034,    37,   247,   387,   715,
    1034,   266,   383,   383,   383,   383,  1083,   165,   333,  1029,
     637,  1035,  1029,  1113,   985,    84,  1035,   155,  1065,   991,
     847,   333,   260,   623,   183,  1035,   416,  1029,   333,   722,
     287,  1080,   697,   156,  1111,   847,   912,   551,   702,   249,
     166,   167,   822,   333,   913,   250,   229,   749,   168,   169,
     170,  1078,   188,  1102,  1079,   858,   786,   877,   732,   572,
     601,  1092,   848,   391,   859,    48,   730,   622,  1020,   886,
    1021,  1022,  1023,   755,   739,   744,   579,   580,   235,    51,
     582,   584,   292,   292,   292,   787,   751,   292,   489,   597,
    1092,   642,   258,   861,   862,   189,   753,  1054,   863,   789,
     624,   950,   908,   866,   494,   681,   723,   683,   684,   793,
     692,   685,   692,   692,   495,   692,   794,   795,   807,   774,
     810,   692,   811,   190,   750,   692,   625,   752,   626,   628,
     631,   631,   631,   631,   245,   265,   478,   791,   246,   292,
     648,   775,   650,   827,   829,   830,   858,  1050,   657,   831,
     776,   833,   889,   897,   171,   859,   564,   565,   792,   184,
     185,   946,   247,   750,   948,   777,  1104,   479,   995,  1010,
     867,   778,   851,   750,   480,   270,   790,   195,   537,   538,
     539,   540,   541,   542,   861,   862,   790,   269,   172,   863,
    1055,   481,   194,   790,   790,   808,   478,   808,   929,   808,
     931,   737,   932,   173,   249,   482,   465,   779,  1051,   743,
     250,   468,   716,   780,   483,   552,   918,   919,   920,   191,
     808,   808,   808,   465,   821,   484,   808,   479,   808,   890,
     898,   365,   727,   729,   480,   292,   111,   111,   947,   979,
     736,   947,   419,   157,   158,   996,   567,   391,   741,   655,
     391,   481,   655,   655,   111,   884,  1000,   885,   812,   196,
     494,  1106,   704,   197,   206,   482,   465,   748,   211,   666,
     495,   655,   674,   876,   483,   208,   655,   265,   655,   655,
    1011,   210,  1107,   655,  1001,   484,   209,   207,   213,   813,
     466,   162,   615,   616,   617,   857,   814,   705,   268,   706,
     265,   676,   163,   699,   420,   543,   164,   421,   422,   423,
     135,   216,   707,   815,   544,  1002,   424,   217,   208,  1088,
     425,   717,   718,   719,   720,   426,    84,   816,    86,   209,
     992,   858,   427,  -524,   428,   429,   817,   430,   218,   590,
     859,  1058,   594,   545,   219,   383,   618,   818,   546,   279,
     280,   281,   231,   383,   632,   633,   634,  1071,   431,   238,
     963,   136,    84,   860,    95,   232,   858,   137,   432,   861,
     862,    84,   433,   107,   863,   859,   244,   858,   245,   434,
     138,   435,   246,   259,   272,   139,   859,    84,   293,   125,
     436,   294,   437,  1097,   140,   361,   400,   141,   993,   551,
     869,   142,   401,  1103,   861,   862,   247,   143,  1056,   863,
     132,   874,   133,   402,   403,   861,   862,   404,   406,   245,
     863,   881,   882,   246,   292,    84,   292,   234,   405,   858,
     438,   248,   407,   439,  1059,   408,   411,   144,   859,   412,
      84,  1098,   240,   450,   858,   145,   413,   247,   249,    84,
     826,   274,    89,   859,   250,    84,    84,   366,   583,   832,
     416,   834,   835,   836,   909,   452,   631,   861,   862,    84,
     858,   627,   863,    84,   453,   728,  1057,   858,   464,   859,
     587,   923,   861,   862,   855,   926,   859,   863,   942,   249,
     943,   454,   455,   456,   457,   250,  -282,   517,   468,  1042,
    1043,   471,  1060,   472,   473,   905,   512,   138,   861,   862,
     858,   564,   139,   863,   474,   861,   862,   514,   518,   859,
     863,   140,   475,   476,   141,   491,   519,   520,   142,   513,
     492,  -282,   521,  -282,   143,   103,   104,   105,   106,   659,
     660,   522,   548,   954,   523,   493,   524,   959,   861,   862,
     498,   500,   964,   863,   965,   111,   525,   526,   673,   555,
     123,   501,   504,   678,   505,   679,   680,   506,   693,   694,
     682,   695,   507,   510,   556,   557,   527,   700,   575,  1100,
    1101,   703,   560,   561,   564,   567,   925,   578,   574,   602,
     603,   604,   607,   608,   528,   609,   296,   297,   564,   298,
     610,   611,   612,   613,   614,   635,   934,   649,   299,   652,
     300,   658,   733,   301,   487,   661,   696,   688,   701,   529,
     664,   747,   724,   738,   748,   754,   530,   756,   759,   763,
     745,   746,   531,   532,   765,   766,    89,   760,  1040,   302,
     303,   767,   770,   771,   788,   304,   305,   797,   958,   292,
     798,   465,   799,   383,   805,   809,   824,   838,   823,   840,
     825,   842,   844,   865,   870,   871,   875,   776,   887,   888,
     306,   892,  1040,   894,   896,  1032,  1041,   899,   900,   902,
     903,   922,   949,   906,   933,   927,   935,   930,   936,   937,
     938,   939,   960,   966,   968,   967,   970,   971,   972,   976,
     973,   978,   982,    89,    89,    89,  1032,  1040,   984,   981,
    1041,   986,   987,   988,  1040,  1008,  1012,   994,  1013,  1014,
    1016,   296,   297,  1018,   298,  1019,  1075,   990,   307,  -503,
    1001,  1069,  1070,   299,  1072,   300,  1077,    89,   301,  1076,
    1089,    89,  1105,  1040,   742,  1041,  1087,   569,  1081,   796,
    1082,   801,  1041,  1075,   975,   977,   921,   917,   308,    89,
    1109,   286,   868,   153,   302,   303,   599,   309,   451,   310,
     304,   305,   311,   312,   958,   415,   154,   377,  1026,   883,
    1015,  1041,   215,   731,   487,   907,  1045,   686,   846,  1064,
     313,   687,  1044,   314,   721,   306,   509,   901,   854,   852,
     315,   316,   758,  1067,   369,  1068,   726,   317,   318,  1112,
    1085,   974,  1114,  1096,   872,   677,   853,   989,   319,   945,
     233,   320,   101,   321,   322,   461,   576,   323,     0,   324,
     554,   325,   581,     0,   326,     0,     0,   327,   328,   329,
       0,   330,   331,     0,   332,     0,     0,   333,     0,     0,
       0,     0,     0,   307,     0,     0,     0,   334,   335,   336,
     296,   297,     0,   298,     0,     0,     0,     0,     0,     0,
       0,     0,   299,     0,   300,     0,     0,   301,     0,     0,
       0,     0,   564,   308,     0,     0,     0,     0,     0,     0,
       0,     0,   309,     0,   310,     0,     0,   311,   312,     0,
       0,     0,     0,   302,   303,     0,     0,     0,     0,   304,
     305,     0,     0,     0,     0,   313,     0,     0,   314,     0,
       0,     0,     0,     0,     0,   315,   316,     0,     0,     0,
       0,     0,   317,   318,   306,     0,     0,     0,     0,     0,
       0,     0,     0,   319,     0,     0,   320,     0,   321,   322,
       0,     0,   323,     0,   324,     0,   325,     0,     0,   326,
       0,     0,   327,   328,   329,     0,   330,   331,     0,   332,
       0,     0,   333,     0,   296,   297,     0,   298,     0,     0,
       0,     0,   334,   335,   336,     0,   299,     0,   300,     0,
       0,   301,   307,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   302,   303,     0,
       0,     0,   308,   304,   305,     0,     0,     0,     0,     0,
       0,   309,     0,   310,     0,     0,   311,   312,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   306,     0,
       0,     0,     0,     0,   313,     0,     0,   314,     0,     0,
       0,     0,     0,     0,   315,   316,     0,     0,     0,     0,
       0,   317,   318,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   319,     0,     0,   320,     0,   321,   322,     0,
       0,   323,     0,   324,     0,   325,     0,     0,   326,     0,
       0,   327,   328,   329,     0,     0,   331,     0,   332,     0,
       0,   333,     0,   296,   297,     0,   298,     0,     0,     0,
       0,   334,   335,   336,     0,   299,     0,   300,     0,     0,
     301,     0,     0,     0,     0,     0,   308,     0,     0,     0,
       0,     0,     0,     0,     0,   309,     0,   379,     0,     0,
       0,   312,     0,     0,     0,     0,   302,   303,     0,     0,
       0,     0,   304,   305,     0,     0,     0,   380,   313,     0,
       0,   314,     0,     0,     0,     0,     0,     0,   315,   316,
       0,     0,     0,     0,     0,   317,   318,   306,     0,     0,
       0,     0,     0,     0,     0,     0,   319,   517,     0,   320,
       0,   321,   322,     0,     0,   323,     0,   324,     0,   325,
       0,     0,   326,     0,     0,   327,   328,   329,   518,     0,
     331,     0,   332,     0,     0,   333,   519,   520,   296,   297,
       0,   298,   521,     0,   664,   334,   335,   336,     0,     0,
     299,   522,   300,     0,   523,   301,   524,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   525,   526,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   302,   303,     0,     0,   308,   527,   304,   305,     0,
       0,     0,     0,     0,   309,     0,   379,     0,     0,     0,
     312,     0,     0,     0,   528,     0,     0,     0,     0,     0,
       0,   487,   306,     0,     0,     0,  -305,   313,     0,     0,
     314,     0,     0,     0,     0,     0,     0,   315,   316,   529,
       0,     0,     0,     0,   317,   318,   530,     0,  -305,     0,
       0,     0,   531,   532,     0,   319,     0,     0,   320,     0,
     321,   322,     0,     0,   323,     0,   324,     0,   325,     0,
       0,   326,     0,     0,   327,   328,   329,     0,     0,   331,
       0,   332,     0,     0,   333,     0,     0,   296,   297,     0,
     298,     0,     0,     0,   334,   335,   336,     0,     0,   299,
       0,   300,     0,     0,   301,     0,     0,     0,   654,     0,
     308,     0,     0,     0,     0,     0,     0,     0,     0,   309,
       0,   379,     0,     0,     0,   312,     0,     0,     0,     0,
     302,   303,     0,     0,     0,     0,   304,   305,     0,     0,
       0,     0,   313,     0,     0,   314,     0,     0,     0,     0,
       0,     0,   315,   316,     0,     0,     0,     0,     0,   317,
     318,   306,     0,     0,     0,     0,     0,     0,     0,     0,
     319,     0,     0,   320,     0,   321,   322,     0,     0,   323,
       0,   324,     0,   325,     0,     0,   326,     0,     0,   327,
     328,   329,     0,     0,   331,     0,   332,     0,     0,   333,
       0,   296,   297,     0,   298,     0,     0,     0,     0,   334,
     335,   336,     0,   299,     0,   300,     0,     0,   301,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   302,   303,     0,     0,     0,   308,
     304,   305,     0,     0,     0,     0,     0,     0,   309,     0,
     379,     0,     0,     0,   312,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   306,     0,     0,     0,     0,
     698,   313,     0,     0,   314,     0,     0,     0,     0,     0,
       0,   315,   316,     0,     0,     0,     0,     0,   317,   318,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   319,
       0,     0,   320,     0,   321,   322,     0,     0,   323,     0,
     324,     0,   325,     0,     0,   326,     0,     0,   327,   328,
     329,     0,     0,   331,     0,   332,     0,     0,   333,     0,
     296,   297,     0,   298,     0,     0,     0,     0,   334,   335,
     336,     0,   299,     0,   300,     0,     0,   301,     0,     0,
       0,     0,     0,   308,     0,     0,     0,     0,     0,     0,
       0,     0,   309,     0,   379,     0,     0,     0,   312,     0,
       0,     0,     0,   302,   303,     0,     0,     0,     0,   304,
     305,     0,     0,     0,   955,   313,     0,     0,   314,     0,
       0,     0,     0,     0,     0,   315,   316,     0,     0,     0,
       0,     0,   317,   318,   306,     0,     0,     0,     0,     0,
       0,     0,     0,   319,     0,     0,   320,     0,   321,   322,
       0,     0,   323,     0,   324,     0,   325,     0,     0,   326,
       0,     0,   327,   328,   329,     0,     0,   331,     0,   332,
       0,     0,   333,     0,   296,   297,     0,   298,     0,     0,
       0,     0,   334,   335,   336,     0,   299,     0,   300,     0,
       0,   301,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   302,   303,     0,
       0,     0,   308,   304,   305,     0,     0,     0,     0,     0,
       0,   309,     0,   379,     0,     0,     0,   312,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   306,     0,
       0,     0,     0,     0,   313,     0,     0,   314,     0,     0,
       0,     0,     0,     0,   315,   316,     0,     0,     0,     0,
       0,   317,   318,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   319,     0,     0,   320,     0,   321,   322,     0,
       0,   323,     0,   324,     0,   325,     0,     0,   326,     0,
       0,   327,   328,   329,     0,     0,   331,     0,   332,     0,
       0,   333,     0,   296,   297,     0,   298,     0,     0,     0,
       0,   334,   335,   336,     0,   299,     0,   300,     0,     0,
     301,     0,     0,     0,     0,     0,   665,     0,     0,     0,
       0,     0,     0,     0,     0,   309,     0,   379,     0,     0,
       0,   312,     0,     0,     0,     0,   302,   303,     0,     0,
       0,     0,   304,   305,     0,     0,     0,     0,   313,     0,
       0,   314,     0,     0,     0,     0,     0,     0,   315,   316,
       0,     0,     0,     0,     0,   317,   318,   306,     0,     0,
       0,     0,     0,     0,     0,     0,   319,     0,     0,   320,
       0,   321,   322,     0,     0,   323,     0,   324,     0,   325,
       0,     0,   326,     0,     0,   327,   328,   329,     0,     0,
     331,     0,   332,     0,     0,   333,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   334,   335,   336,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   308,     0,     0,     0,     0,
       0,     0,     0,     0,   309,     0,   379,     0,     0,     0,
     312,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   313,     0,     0,
     314,     0,  -561,     1,     0,     0,     0,   315,   316,     0,
       0,     0,     0,     0,   317,   318,     0,     0,  -561,     0,
       0,     0,     0,     0,     0,   319,     0,     0,   320,     0,
     321,   322,     0,     0,   323,     0,   324,     0,   325,     0,
       0,   326,     0,     0,   327,   328,     2,     3,     0,   331,
       0,     4,     0,     5,   333,     0,     6,     7,     8,     9,
      10,     0,    11,    12,   334,   335,   336,     0,     0,     0,
      13,    14,     0,     0,    15,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    16,    17,    18,    19,     0,    20,    21,    22,    23,
      24,    25,    26,     0,     0,    27,     0,     0,    28,     0,
      29,    30,     0,    31,    32,     0,     0,     0,    33,    34,
      35,    36,    37,    38,     0,     0,    39,     0,     0,     0,
       0,     0,    40,    41,     0,     0,    42,     0,     0,    43,
       0,    44,    45,     0,     0,     0,     0,    46,     0,     0,
       0,    47,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    48,     0,    49,     0,     0,    50,     0,     0,     0,
       0,     0,     0,     0,     0,    51
};

static const yytype_int16 yycheck[] =
{
       4,    43,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    21,    21,   200,    23,
     266,   166,    26,   709,   197,    29,    30,   391,    32,    33,
     225,   226,   227,    37,    38,   468,   491,    41,    42,    43,
     213,    45,    46,   346,   173,   348,    50,   410,   231,   651,
     269,   228,   260,   618,   487,     6,   806,     4,     9,    10,
     662,     3,   201,     4,    15,   194,     4,   196,     3,     4,
     820,     6,     4,     3,     4,    26,     6,     3,    29,    30,
     104,    32,    33,     4,     4,     6,    37,    38,     4,    15,
       3,    42,   688,     6,   690,    46,   163,     3,     4,    50,
       6,     4,    15,   248,     4,   108,     6,     4,     4,    15,
       6,    17,     3,     4,    20,     6,   163,     4,   122,     6,
      31,   424,   425,    31,    15,     4,    17,    38,   310,    20,
      38,   696,     4,   151,     6,   307,   701,     4,    31,   311,
     269,   104,   227,    42,    43,    38,   924,   319,   102,     4,
     928,   323,   324,   157,     4,   163,     6,   161,   162,   163,
     164,   176,   110,   167,   760,   151,   762,   171,   172,   173,
       4,   122,   257,   240,   860,   193,   176,   151,   864,   183,
     866,   129,   186,   187,   188,   189,   190,   191,   212,   192,
     194,   195,   196,   197,   163,   163,   163,    63,    64,    65,
      66,    67,   206,   207,   208,   209,   210,   193,   172,   213,
     257,  1029,   216,   217,   396,   187,   234,   163,    62,   193,
     239,   611,   612,   163,   228,   229,   123,   231,   232,   163,
     127,   250,   240,   406,   176,    79,    80,   188,   189,   190,
     191,   696,   329,   258,   195,   332,   701,  1065,   234,   212,
     960,   255,   165,     3,   151,   163,   260,   239,   258,   165,
     234,   208,   266,   153,    50,   269,   217,   220,   250,   163,
     163,   240,   240,   240,   165,   840,   240,   842,   122,   844,
     176,   232,   254,   287,   648,   191,   240,   240,   208,   123,
     463,   181,   208,   127,   240,   981,   193,   176,   252,   254,
     240,   188,   199,   163,   246,   208,   240,   993,   994,   251,
     163,   252,   187,   495,   252,   250,   120,   151,   250,   266,
     250,   176,   224,   225,   226,   227,   176,   255,   254,   240,
     459,   266,   240,  1111,   930,     4,   266,     0,   210,   172,
     246,   254,   176,   163,   254,   266,   240,   240,   254,   163,
     250,  1061,   524,    16,  1104,   246,   255,   361,   530,   193,
      70,    71,   665,   254,   263,   199,   232,   163,    78,    79,
      80,  1057,   256,  1083,  1060,   208,   622,   741,   561,   254,
     240,  1076,   947,   387,   217,   189,   559,   240,   984,   752,
     986,   987,   988,   601,   571,   578,   400,   401,   402,   203,
     404,   405,   406,   407,   408,   624,   163,   411,   310,   413,
    1105,   255,   416,   246,   247,   256,   163,  1013,   251,   163,
     240,   163,   785,   187,   219,   504,   240,   506,   507,   163,
     517,   510,   519,   520,   229,   522,   163,   163,   163,   105,
     163,   528,   163,   256,   240,   532,   450,   592,   452,   453,
     454,   455,   456,   457,   123,   459,   152,   216,   127,   463,
     464,   127,   466,   163,   163,   163,   208,   148,   472,   163,
     136,   163,   163,   163,   184,   217,   378,   379,   237,    87,
      88,   163,   151,   240,   163,   151,  1088,   183,   163,   163,
     254,   157,   947,   240,   190,   624,   240,   243,    81,    82,
      83,    84,    85,    86,   246,   247,   240,   176,   218,   251,
     163,   207,   176,   240,   240,   240,   152,   240,   821,   240,
     823,   567,   825,   233,   193,   221,   187,   193,   209,   575,
     199,   191,   536,   199,   230,   195,   793,   794,   795,   256,
     240,   240,   240,   187,   240,   241,   240,   183,   240,   240,
     240,   555,   556,   557,   190,   559,   560,   561,   240,   923,
     564,   240,    76,   132,   133,   240,   240,   571,   572,   471,
     574,   207,   474,   475,   578,   748,   153,   750,   152,   176,
     219,   216,   125,   176,   254,   221,   187,   240,   146,   491,
     229,   493,   494,   254,   230,   239,   498,   601,   500,   501,
     964,   258,   237,   505,   181,   241,   250,   254,   176,   183,
     254,   239,   113,   114,   115,   172,   190,   160,   622,   162,
     624,   260,   250,   525,   138,   208,   254,   141,   142,   143,
     107,   220,   534,   207,   217,   212,   150,   256,   239,  1072,
     154,   543,   544,   545,   546,   159,     4,   221,     6,   250,
     172,   208,   166,   254,   168,   169,   230,   171,   240,   408,
     217,   172,   411,   246,     3,   567,   167,   241,   251,   189,
     190,   191,   258,   575,   455,   456,   457,  1041,   192,     6,
     875,   158,     4,   240,     6,   256,   208,   164,   202,   246,
     247,     4,   206,     6,   251,   217,     6,   208,   123,   213,
     177,   215,   127,     3,   240,   182,   217,     4,   252,     6,
     224,     4,   226,   172,   191,   176,   254,   194,   240,   723,
     724,   198,   254,  1087,   246,   247,   151,   204,   172,   251,
       4,   735,     6,   240,    48,   246,   247,   254,   176,   123,
     251,   745,   746,   127,   748,     4,   750,     6,   239,   208,
     264,   176,   176,   267,   172,   176,   176,   234,   217,   176,
       4,   172,     6,   259,   208,   242,    73,   151,   193,     4,
     672,     6,   776,   217,   199,     4,     4,     6,     6,   681,
     240,   683,   684,   685,   788,   254,   790,   246,   247,     4,
     208,     6,   251,     4,   239,     6,   240,   208,   254,   217,
     973,   805,   246,   247,   706,   809,   217,   251,   842,   193,
     844,   176,   176,   176,   176,   199,   125,   126,   191,  1001,
    1002,   176,   240,   254,     6,   776,     3,   177,   246,   247,
     208,   733,   182,   251,   176,   246,   247,   235,   147,   217,
     251,   191,   176,   176,   194,   176,   155,   156,   198,   257,
     176,   160,   161,   162,   204,    16,    17,    18,    19,   474,
     475,   170,    93,   867,   173,   176,   175,   871,   246,   247,
     176,   176,   876,   251,   879,   879,   185,   186,   493,   258,
      41,   176,   176,   498,   176,   500,   501,   176,   519,   520,
     505,   522,   176,   176,   254,   239,   205,   528,   185,  1081,
    1082,   532,   240,   220,   806,   240,   808,   258,   240,   176,
     176,   176,   176,   176,   223,   176,     3,     4,   820,     6,
     176,   176,   176,   176,   176,   128,   828,     3,    15,   101,
      17,    21,   240,    20,   191,   258,   176,   258,   176,   248,
     163,   163,   254,   185,   240,   163,   255,     3,     3,     3,
     254,   254,   261,   262,     3,     3,   960,   258,  1000,    46,
      47,     3,     3,     3,   254,    52,    53,     3,   870,   973,
       3,   187,     4,   875,   254,   254,   163,     3,   240,   178,
     240,   178,   178,     3,   176,   254,   176,   136,   163,   163,
      77,     3,  1034,   240,   163,   999,  1000,   163,   163,   163,
     163,     3,   235,   176,   163,   176,   163,   258,   163,   163,
     163,   163,   220,     3,     3,   163,   163,     3,   163,     3,
     176,   172,     3,  1027,  1028,  1029,  1030,  1069,   258,   187,
    1034,   258,   258,   258,  1076,   211,   163,   187,   258,   163,
     163,     3,     4,   163,     6,   163,  1050,   949,   135,   163,
     181,   240,   254,    15,   191,    17,   148,  1061,    20,   253,
     128,  1065,   240,  1105,   574,  1069,  1070,   387,   256,   636,
     256,   644,  1076,  1077,   912,   915,   796,   790,   165,  1083,
    1096,   196,   723,    51,    46,    47,   416,   174,   272,   176,
      52,    53,   179,   180,   996,   255,    51,   218,   996,   747,
     973,  1105,   141,   560,   191,   783,  1007,   513,   695,  1028,
     197,   514,  1004,   200,   548,    77,   330,   769,   703,   700,
     207,   208,   603,  1030,   210,  1034,   555,   214,   215,  1105,
    1069,   906,  1113,  1077,   733,   496,   701,   947,   225,   847,
     156,   228,    14,   230,   231,   287,   395,   234,    -1,   236,
     362,   238,   402,    -1,   241,    -1,    -1,   244,   245,   246,
      -1,   248,   249,    -1,   251,    -1,    -1,   254,    -1,    -1,
      -1,    -1,    -1,   135,    -1,    -1,    -1,   264,   265,   266,
       3,     4,    -1,     6,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    15,    -1,    17,    -1,    -1,    20,    -1,    -1,
      -1,    -1,  1104,   165,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   174,    -1,   176,    -1,    -1,   179,   180,    -1,
      -1,    -1,    -1,    46,    47,    -1,    -1,    -1,    -1,    52,
      53,    -1,    -1,    -1,    -1,   197,    -1,    -1,   200,    -1,
      -1,    -1,    -1,    -1,    -1,   207,   208,    -1,    -1,    -1,
      -1,    -1,   214,   215,    77,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   225,    -1,    -1,   228,    -1,   230,   231,
      -1,    -1,   234,    -1,   236,    -1,   238,    -1,    -1,   241,
      -1,    -1,   244,   245,   246,    -1,   248,   249,    -1,   251,
      -1,    -1,   254,    -1,     3,     4,    -1,     6,    -1,    -1,
      -1,    -1,   264,   265,   266,    -1,    15,    -1,    17,    -1,
      -1,    20,   135,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    46,    47,    -1,
      -1,    -1,   165,    52,    53,    -1,    -1,    -1,    -1,    -1,
      -1,   174,    -1,   176,    -1,    -1,   179,   180,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    77,    -1,
      -1,    -1,    -1,    -1,   197,    -1,    -1,   200,    -1,    -1,
      -1,    -1,    -1,    -1,   207,   208,    -1,    -1,    -1,    -1,
      -1,   214,   215,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   225,    -1,    -1,   228,    -1,   230,   231,    -1,
      -1,   234,    -1,   236,    -1,   238,    -1,    -1,   241,    -1,
      -1,   244,   245,   246,    -1,    -1,   249,    -1,   251,    -1,
      -1,   254,    -1,     3,     4,    -1,     6,    -1,    -1,    -1,
      -1,   264,   265,   266,    -1,    15,    -1,    17,    -1,    -1,
      20,    -1,    -1,    -1,    -1,    -1,   165,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   174,    -1,   176,    -1,    -1,
      -1,   180,    -1,    -1,    -1,    -1,    46,    47,    -1,    -1,
      -1,    -1,    52,    53,    -1,    -1,    -1,   196,   197,    -1,
      -1,   200,    -1,    -1,    -1,    -1,    -1,    -1,   207,   208,
      -1,    -1,    -1,    -1,    -1,   214,   215,    77,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   225,   126,    -1,   228,
      -1,   230,   231,    -1,    -1,   234,    -1,   236,    -1,   238,
      -1,    -1,   241,    -1,    -1,   244,   245,   246,   147,    -1,
     249,    -1,   251,    -1,    -1,   254,   155,   156,     3,     4,
      -1,     6,   161,    -1,   163,   264,   265,   266,    -1,    -1,
      15,   170,    17,    -1,   173,    20,   175,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   185,   186,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    46,    47,    -1,    -1,   165,   205,    52,    53,    -1,
      -1,    -1,    -1,    -1,   174,    -1,   176,    -1,    -1,    -1,
     180,    -1,    -1,    -1,   223,    -1,    -1,    -1,    -1,    -1,
      -1,   191,    77,    -1,    -1,    -1,   235,   197,    -1,    -1,
     200,    -1,    -1,    -1,    -1,    -1,    -1,   207,   208,   248,
      -1,    -1,    -1,    -1,   214,   215,   255,    -1,   257,    -1,
      -1,    -1,   261,   262,    -1,   225,    -1,    -1,   228,    -1,
     230,   231,    -1,    -1,   234,    -1,   236,    -1,   238,    -1,
      -1,   241,    -1,    -1,   244,   245,   246,    -1,    -1,   249,
      -1,   251,    -1,    -1,   254,    -1,    -1,     3,     4,    -1,
       6,    -1,    -1,    -1,   264,   265,   266,    -1,    -1,    15,
      -1,    17,    -1,    -1,    20,    -1,    -1,    -1,   163,    -1,
     165,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   174,
      -1,   176,    -1,    -1,    -1,   180,    -1,    -1,    -1,    -1,
      46,    47,    -1,    -1,    -1,    -1,    52,    53,    -1,    -1,
      -1,    -1,   197,    -1,    -1,   200,    -1,    -1,    -1,    -1,
      -1,    -1,   207,   208,    -1,    -1,    -1,    -1,    -1,   214,
     215,    77,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     225,    -1,    -1,   228,    -1,   230,   231,    -1,    -1,   234,
      -1,   236,    -1,   238,    -1,    -1,   241,    -1,    -1,   244,
     245,   246,    -1,    -1,   249,    -1,   251,    -1,    -1,   254,
      -1,     3,     4,    -1,     6,    -1,    -1,    -1,    -1,   264,
     265,   266,    -1,    15,    -1,    17,    -1,    -1,    20,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    46,    47,    -1,    -1,    -1,   165,
      52,    53,    -1,    -1,    -1,    -1,    -1,    -1,   174,    -1,
     176,    -1,    -1,    -1,   180,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    77,    -1,    -1,    -1,    -1,
     196,   197,    -1,    -1,   200,    -1,    -1,    -1,    -1,    -1,
      -1,   207,   208,    -1,    -1,    -1,    -1,    -1,   214,   215,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   225,
      -1,    -1,   228,    -1,   230,   231,    -1,    -1,   234,    -1,
     236,    -1,   238,    -1,    -1,   241,    -1,    -1,   244,   245,
     246,    -1,    -1,   249,    -1,   251,    -1,    -1,   254,    -1,
       3,     4,    -1,     6,    -1,    -1,    -1,    -1,   264,   265,
     266,    -1,    15,    -1,    17,    -1,    -1,    20,    -1,    -1,
      -1,    -1,    -1,   165,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   174,    -1,   176,    -1,    -1,    -1,   180,    -1,
      -1,    -1,    -1,    46,    47,    -1,    -1,    -1,    -1,    52,
      53,    -1,    -1,    -1,   196,   197,    -1,    -1,   200,    -1,
      -1,    -1,    -1,    -1,    -1,   207,   208,    -1,    -1,    -1,
      -1,    -1,   214,   215,    77,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   225,    -1,    -1,   228,    -1,   230,   231,
      -1,    -1,   234,    -1,   236,    -1,   238,    -1,    -1,   241,
      -1,    -1,   244,   245,   246,    -1,    -1,   249,    -1,   251,
      -1,    -1,   254,    -1,     3,     4,    -1,     6,    -1,    -1,
      -1,    -1,   264,   265,   266,    -1,    15,    -1,    17,    -1,
      -1,    20,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    46,    47,    -1,
      -1,    -1,   165,    52,    53,    -1,    -1,    -1,    -1,    -1,
      -1,   174,    -1,   176,    -1,    -1,    -1,   180,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    77,    -1,
      -1,    -1,    -1,    -1,   197,    -1,    -1,   200,    -1,    -1,
      -1,    -1,    -1,    -1,   207,   208,    -1,    -1,    -1,    -1,
      -1,   214,   215,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   225,    -1,    -1,   228,    -1,   230,   231,    -1,
      -1,   234,    -1,   236,    -1,   238,    -1,    -1,   241,    -1,
      -1,   244,   245,   246,    -1,    -1,   249,    -1,   251,    -1,
      -1,   254,    -1,     3,     4,    -1,     6,    -1,    -1,    -1,
      -1,   264,   265,   266,    -1,    15,    -1,    17,    -1,    -1,
      20,    -1,    -1,    -1,    -1,    -1,   165,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   174,    -1,   176,    -1,    -1,
      -1,   180,    -1,    -1,    -1,    -1,    46,    47,    -1,    -1,
      -1,    -1,    52,    53,    -1,    -1,    -1,    -1,   197,    -1,
      -1,   200,    -1,    -1,    -1,    -1,    -1,    -1,   207,   208,
      -1,    -1,    -1,    -1,    -1,   214,   215,    77,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   225,    -1,    -1,   228,
      -1,   230,   231,    -1,    -1,   234,    -1,   236,    -1,   238,
      -1,    -1,   241,    -1,    -1,   244,   245,   246,    -1,    -1,
     249,    -1,   251,    -1,    -1,   254,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   264,   265,   266,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   165,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   174,    -1,   176,    -1,    -1,    -1,
     180,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   197,    -1,    -1,
     200,    -1,     0,     1,    -1,    -1,    -1,   207,   208,    -1,
      -1,    -1,    -1,    -1,   214,   215,    -1,    -1,    16,    -1,
      -1,    -1,    -1,    -1,    -1,   225,    -1,    -1,   228,    -1,
     230,   231,    -1,    -1,   234,    -1,   236,    -1,   238,    -1,
      -1,   241,    -1,    -1,   244,   245,    44,    45,    -1,   249,
      -1,    49,    -1,    51,   254,    -1,    54,    55,    56,    57,
      58,    -1,    60,    61,   264,   265,   266,    -1,    -1,    -1,
      68,    69,    -1,    -1,    72,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    89,    90,    91,    92,    -1,    94,    95,    96,    97,
      98,    99,   100,    -1,    -1,   103,    -1,    -1,   106,    -1,
     108,   109,    -1,   111,   112,    -1,    -1,    -1,   116,   117,
     118,   119,   120,   121,    -1,    -1,   124,    -1,    -1,    -1,
      -1,    -1,   130,   131,    -1,    -1,   134,    -1,    -1,   137,
      -1,   139,   140,    -1,    -1,    -1,    -1,   145,    -1,    -1,
      -1,   149,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   189,    -1,   191,    -1,    -1,   194,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   203
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
{
       0,     1,    44,    45,    49,    51,    54,    55,    56,    57,
      58,    60,    61,    68,    69,    72,    89,    90,    91,    92,
      94,    95,    96,    97,    98,    99,   100,   103,   106,   108,
     109,   111,   112,   116,   117,   118,   119,   120,   121,   124,
     130,   131,   134,   137,   139,   140,   145,   149,   189,   191,
     194,   203,   277,   288,   289,   290,   291,   300,   307,   327,
     328,   337,   338,   339,   341,   342,   343,   344,   345,   355,
     375,   379,   425,   426,   429,   430,   448,   482,   483,   484,
     485,   487,   491,   493,     4,   476,     6,   473,   474,   476,
     476,   476,   473,   473,   476,     6,   475,   476,   476,   481,
     486,   486,   473,   475,   475,   475,   475,     6,   376,   377,
     414,   476,   476,   473,     3,   501,   473,   473,   473,   473,
     473,   473,   329,   475,   473,     6,   471,   472,   476,   427,
     476,   473,     4,     6,   479,   107,   158,   164,   177,   182,
     191,   194,   198,   204,   234,   242,   346,   348,   349,   350,
     201,   457,   473,   346,   348,     0,    16,   132,   133,   488,
      50,   254,   239,   250,   254,   255,    70,    71,    78,    79,
      80,   184,   218,   233,   308,   309,   310,   313,   316,   319,
     320,   321,   324,   254,    87,    88,   239,   250,   256,   256,
     256,   256,   378,   379,   176,   243,   176,   176,   356,   104,
     212,   279,   473,   110,   129,   431,   254,   254,   239,   250,
     258,   146,   340,   176,   351,   351,   220,   256,   240,     3,
     151,   193,   234,   458,    63,    64,    65,    66,    67,   232,
     280,   258,   256,   484,     6,   476,   489,   490,     6,   476,
       6,   476,   476,   476,     6,   123,   127,   151,   176,   193,
     199,   359,   360,   365,   367,   176,   325,   326,   476,     3,
     176,   306,   318,   367,   369,   476,   176,   315,   476,   176,
     306,   311,   240,   476,     6,   476,   476,   299,   473,   299,
     299,   299,   379,   305,   306,   473,   305,   250,   357,   416,
     419,   471,   476,   252,     4,   477,     3,     4,     6,    15,
      17,    20,    46,    47,    52,    53,    77,   135,   165,   174,
     176,   179,   180,   197,   200,   207,   208,   214,   215,   225,
     228,   230,   231,   234,   236,   238,   241,   244,   245,   246,
     248,   249,   251,   254,   264,   265,   266,   389,   390,   391,
     392,   393,   400,   402,   421,   432,   433,   434,   435,   436,
     456,   461,   462,   468,   476,   478,   492,   494,   498,   499,
     500,   176,   332,   476,   428,   476,     6,   476,   476,   427,
     352,   416,   188,   353,   354,   414,   473,   350,   449,   176,
     196,   286,   287,   461,   286,   286,   286,   250,   282,   283,
     285,   476,   281,   282,   284,   104,   212,   278,   353,   473,
     254,   254,   240,    48,   254,   239,   176,   176,   176,   322,
     367,   176,   176,    73,   323,   325,   240,   317,   318,    76,
     138,   141,   142,   143,   150,   154,   159,   166,   168,   169,
     171,   192,   202,   206,   213,   215,   224,   226,   264,   267,
     405,   406,   407,   408,   410,   447,   314,   315,   311,   312,
     259,   309,   254,   239,   176,   176,   176,   176,   163,   240,
     163,   419,   163,   240,   254,   187,   254,   415,   191,   446,
     455,   176,   254,     6,   176,   176,   176,   456,   152,   183,
     190,   207,   221,   230,   241,   422,   423,   191,   389,   461,
     456,   176,   176,   176,   219,   229,   463,   464,   176,   456,
     176,   176,   456,   456,   176,   176,   176,   176,   499,   392,
     176,   499,     3,   257,   235,   423,   423,   126,   147,   155,
     156,   161,   170,   173,   175,   185,   186,   205,   223,   248,
     255,   261,   262,   399,   401,   187,   254,    81,    82,    83,
      84,    85,    86,   208,   217,   246,   251,   467,    93,   333,
     334,   476,   195,   330,   455,   258,   254,   239,   163,   240,
     240,   220,   459,   460,   461,   461,   163,   240,   163,   283,
     163,   240,   254,   415,   240,   185,   477,   389,   258,   476,
     476,   490,   476,     6,   476,   362,   364,   416,   366,   416,
     366,   163,   240,   323,   366,   389,   445,   476,   163,   326,
     163,   240,   176,   176,   176,   423,   423,   176,   176,   176,
     176,   176,   176,   176,   176,   113,   114,   115,   167,   368,
     370,   163,   240,   163,   240,   476,   476,     6,   476,   303,
     304,   476,   303,   303,   303,   128,   301,   306,    62,    79,
      80,   122,   255,   292,   293,   294,   416,   208,   476,     3,
     476,   457,   101,   358,   163,   461,   465,   476,    21,   465,
     465,   258,   457,   163,   163,   165,   461,   466,   492,   151,
     193,   234,   403,   465,   461,   389,   260,   464,   465,   465,
     465,   403,   465,   403,   403,   403,   390,   391,   258,   176,
     258,   397,   499,   397,   397,   397,   176,   456,   196,   461,
     397,   176,   456,   397,   125,   160,   162,   461,     3,   176,
     246,   251,   495,   497,   208,   266,   476,   461,   461,   461,
     461,   405,   163,   240,   254,   331,   428,   476,     6,   476,
     416,   354,   353,   240,   450,   252,   476,   287,   185,   282,
     208,   476,   284,   287,   353,   254,   254,   163,   240,   163,
     240,   163,   367,   163,   163,   318,     3,   411,   411,     3,
     258,   176,   258,     3,   412,     3,     3,     3,   412,   412,
       3,     3,     6,   421,   105,   127,   136,   151,   157,   193,
     199,   361,   371,   372,   373,   374,   315,   311,   254,   163,
     240,   216,   237,   163,   163,   163,   292,     3,     3,     4,
     295,   294,   415,   172,   240,   254,   458,   163,   240,   254,
     163,   163,   152,   183,   190,   207,   221,   230,   241,   424,
     458,   240,   423,   240,   163,   240,   461,   163,   227,   163,
     163,   163,   461,   163,   461,   461,   461,   424,     3,   424,
     178,   394,   178,   396,   178,   395,   394,   246,   421,   469,
     470,   492,   396,   469,   395,   461,   495,   172,   208,   217,
     240,   246,   247,   251,   496,     3,   187,   254,   334,   476,
     176,   254,   460,   480,   476,   176,   254,   415,   102,   252,
     347,   476,   476,   361,   416,   416,   323,   163,   163,   163,
     240,   424,     3,   424,   240,   409,   163,   163,   240,   163,
     163,   409,   163,   163,   363,   473,   176,   373,   323,   476,
      42,    43,   255,   263,   296,   297,   298,   304,   296,   296,
     296,   301,     3,   476,   459,   461,   476,   176,   459,   423,
     258,   423,   423,   163,   461,   163,   163,   163,   163,   163,
     398,   421,   398,   398,     3,   478,   163,   240,   163,   235,
     163,   495,   495,   495,   476,   196,   335,   336,   461,   476,
     220,   382,   386,   286,   476,   414,     3,   163,     3,   413,
     163,     3,   163,   176,   445,   295,     3,   298,   172,   415,
     386,   187,     3,   386,   258,   424,   258,   258,   258,   470,
     461,   172,   172,   240,   187,   163,   240,   383,   385,   473,
     153,   181,   212,   380,   381,   387,   388,   442,   211,   452,
     163,   415,   163,   258,   163,   364,   163,   495,   163,   163,
     424,   424,   424,   424,   495,   495,   336,    31,    38,   240,
     252,   420,   476,     3,   250,   266,   417,   418,   443,   444,
     471,   476,   389,   389,   388,   380,   151,   193,   234,   404,
     148,   209,   437,   453,   424,   163,   172,   240,   172,   172,
     240,   176,   383,   384,   384,   210,   385,   420,   418,   240,
     254,   415,   191,   451,   454,   476,   253,   148,   495,   495,
     383,   256,   256,   176,   385,   444,   208,   476,   457,   128,
     302,     3,   417,   438,   439,   440,   454,   172,   172,   163,
     389,   389,   383,   415,   458,   240,   216,   237,   441,   302,
     163,   459,   439,   386,   452
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
#line 425 "sql.yacc"
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
#line 451 "sql.yacc"
    {
		(yyval.ptr)=0;
	}
    break;

  case 4:

/* Line 1455 of yacc.c  */
#line 454 "sql.yacc"
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
#line 471 "sql.yacc"
    {
		(yyval.ptr)=A4GL_new_select_list_item_expr((yyvsp[(2) - (2)].s_select_list_item));
	}
    break;

  case 6:

/* Line 1455 of yacc.c  */
#line 476 "sql.yacc"
    {
		(yyval.ptr)=0;
	}
    break;

  case 7:

/* Line 1455 of yacc.c  */
#line 479 "sql.yacc"
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
#line 496 "sql.yacc"
    {
		 (yyval.ptr)=A4GL_new_select_list_item_expr((yyvsp[(2) - (2)].s_select_list_item));
	}
    break;

  case 9:

/* Line 1455 of yacc.c  */
#line 502 "sql.yacc"
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
#line 511 "sql.yacc"
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
#line 520 "sql.yacc"
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
#line 529 "sql.yacc"
    {
		(yyval.update_cmd)=(yyvsp[(2) - (2)].update_cmd);
		add_feature("UPDATE_COLUMN_EQ_VALUE_LIST");
    }
    break;

  case 13:

/* Line 1455 of yacc.c  */
#line 536 "sql.yacc"
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
#line 551 "sql.yacc"
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
#line 606 "sql.yacc"
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
#line 613 "sql.yacc"
    {
		(yyval.update_cmd)=(yyvsp[(1) - (3)].update_cmd);
		add_str_list((yyval.update_cmd)->column_list, (yyvsp[(3) - (3)].upd_pair)->column_name);
		local_add_select_list_item_list((yyval.update_cmd)->value_list, (yyvsp[(3) - (3)].upd_pair)->value);
	}
    break;

  case 17:

/* Line 1455 of yacc.c  */
#line 624 "sql.yacc"
    {
                strcpy((yyval.str),(yyvsp[(1) - (1)].str));
        }
    break;

  case 18:

/* Line 1455 of yacc.c  */
#line 627 "sql.yacc"
    {
                strcpy((yyval.str),(yyvsp[(2) - (2)].str));
        }
    break;

  case 19:

/* Line 1455 of yacc.c  */
#line 632 "sql.yacc"
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
#line 639 "sql.yacc"
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
#line 656 "sql.yacc"
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
#line 673 "sql.yacc"
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
#line 694 "sql.yacc"
    {
		(yyval.upd_pair)=malloc(sizeof(struct s_update_pair));
		(yyval.upd_pair)->column_name=acl_strdup((yyvsp[(1) - (3)].str));
		(yyval.upd_pair)->value=(yyvsp[(3) - (3)].s_select_list_item);
	}
    break;

  case 24:

/* Line 1455 of yacc.c  */
#line 703 "sql.yacc"
    {
			(yyval.str_list)=new_str_list((yyvsp[(1) - (1)].str));
		}
    break;

  case 25:

/* Line 1455 of yacc.c  */
#line 706 "sql.yacc"
    {
			(yyval.str_list)=add_str_list((yyvsp[(1) - (3)].str_list), (yyvsp[(3) - (3)].str));
		}
    break;

  case 26:

/* Line 1455 of yacc.c  */
#line 714 "sql.yacc"
    { 
		(yyval.s_select_list_item_list)=local_new_select_list_item_list((yyvsp[(1) - (1)].s_select_list_item));
	}
    break;

  case 27:

/* Line 1455 of yacc.c  */
#line 717 "sql.yacc"
    { 
		(yyval.s_select_list_item_list)=local_add_select_list_item_list((yyvsp[(1) - (3)].s_select_list_item_list),(yyvsp[(3) - (3)].s_select_list_item));
	}
    break;

  case 28:

/* Line 1455 of yacc.c  */
#line 725 "sql.yacc"
    {(yyval.s_select_list_item)=(yyvsp[(1) - (1)].s_select_list_item);}
    break;

  case 29:

/* Line 1455 of yacc.c  */
#line 726 "sql.yacc"
    {(yyval.s_select_list_item)=new_select_list_item_builtin_const(E_SLI_BUILTIN_CONST_NULL); }
    break;

  case 30:

/* Line 1455 of yacc.c  */
#line 733 "sql.yacc"
    { (yyval.sql_string)=make_sql_string_and_free(acl_strdup((yyvsp[(1) - (1)].str)), NULL);}
    break;

  case 31:

/* Line 1455 of yacc.c  */
#line 736 "sql.yacc"
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
#line 744 "sql.yacc"
    {SPRINTF2((yyval.str),"%s %s ",(yyvsp[(1) - (2)].str),(yyvsp[(2) - (2)].str));
			add_feature("DROP_VIEW");
}
    break;

  case 33:

/* Line 1455 of yacc.c  */
#line 747 "sql.yacc"
    {SPRINTF2((yyval.str),"%s %s",(yyvsp[(1) - (2)].str),(yyvsp[(2) - (2)].str));
		if (strchr((yyvsp[(2) - (2)].str),'@') || strchr((yyvsp[(2) - (2)].str),':')) add_feature("DROP_INDEX_QUALIFIED_PATH");
			add_feature("DROP_INDEX");
}
    break;

  case 34:

/* Line 1455 of yacc.c  */
#line 751 "sql.yacc"
    {SPRINTF2((yyval.str),"%s %s",(yyvsp[(1) - (2)].str),(yyvsp[(2) - (2)].str));
			add_feature("DROP_TRIGGER");
}
    break;

  case 35:

/* Line 1455 of yacc.c  */
#line 757 "sql.yacc"
    {(yyval.sql_string)=acl_strdup((yyvsp[(1) - (1)].str));}
    break;

  case 36:

/* Line 1455 of yacc.c  */
#line 758 "sql.yacc"
    {(yyval.sql_string)=(yyvsp[(1) - (1)].sql_string);}
    break;

  case 37:

/* Line 1455 of yacc.c  */
#line 762 "sql.yacc"
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
#line 772 "sql.yacc"
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
#line 786 "sql.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 40:

/* Line 1455 of yacc.c  */
#line 787 "sql.yacc"
    {strcpy((yyval.str),(yyvsp[(1) - (1)].str));}
    break;

  case 42:

/* Line 1455 of yacc.c  */
#line 792 "sql.yacc"
    {SPRINTF2((yyval.str),"%s%s",(yyvsp[(1) - (2)].str),(yyvsp[(2) - (2)].str)); }
    break;

  case 43:

/* Line 1455 of yacc.c  */
#line 797 "sql.yacc"
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
#line 805 "sql.yacc"
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
#line 813 "sql.yacc"
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
#line 821 "sql.yacc"
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
#line 829 "sql.yacc"
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
#line 841 "sql.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 50:

/* Line 1455 of yacc.c  */
#line 841 "sql.yacc"
    {strcpy((yyval.str),(yyvsp[(1) - (1)].str));}
    break;

  case 52:

/* Line 1455 of yacc.c  */
#line 845 "sql.yacc"
    {SPRINTF2((yyval.str),"%s%s",(yyvsp[(1) - (2)].str),(yyvsp[(2) - (2)].str));}
    break;

  case 53:

/* Line 1455 of yacc.c  */
#line 849 "sql.yacc"
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
#line 856 "sql.yacc"
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
#line 863 "sql.yacc"
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
#line 870 "sql.yacc"
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
#line 879 "sql.yacc"
    { strcpy(last_tmp_name,(yyvsp[(1) - (1)].str)); }
    break;

  case 58:

/* Line 1455 of yacc.c  */
#line 883 "sql.yacc"
    {SPRINTF7((yyval.str),"CREATE UNIQUE INDEX %s %s %s %s %s %s %s",(yyvsp[(2) - (8)].str),(yyvsp[(3) - (8)].str),(yyvsp[(4) - (8)].str),(yyvsp[(5) - (8)].str),(yyvsp[(6) - (8)].str),(yyvsp[(7) - (8)].str),(yyvsp[(8) - (8)].str));
		add_feature("CREATE_INDEX");
		add_feature("CREATE_INDEX_UNIQUE");
		if (strchr((yyvsp[(2) - (8)].str),'@') || strchr((yyvsp[(2) - (8)].str),':')) add_feature("CREATE_INDEX_QUALIFIED_PATH");
		if (strchr((yyvsp[(6) - (8)].str),',')) { add_feature("CREATE_INDEX_COMPOSITE"); }
	
}
    break;

  case 59:

/* Line 1455 of yacc.c  */
#line 890 "sql.yacc"
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
#line 902 "sql.yacc"
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
#line 913 "sql.yacc"
    {
		if (strchr((yyvsp[(2) - (8)].str),'@') || strchr((yyvsp[(2) - (8)].str),':')) add_feature("CREATE_INDEX_QUALIFIED_PATH");
		if (strchr((yyvsp[(6) - (8)].str),',')) { add_feature("CREATE_INDEX_COMPOSITE"); }
			add_feature("CREATE_INDEX");
			SPRINTF7((yyval.str)," CREATE INDEX %s %s %s %s %s %s %s",(yyvsp[(2) - (8)].str),(yyvsp[(3) - (8)].str),(yyvsp[(4) - (8)].str),(yyvsp[(5) - (8)].str),(yyvsp[(6) - (8)].str),(yyvsp[(7) - (8)].str),(yyvsp[(8) - (8)].str));
	}
    break;

  case 62:

/* Line 1455 of yacc.c  */
#line 919 "sql.yacc"
    {
		add_feature("CREATE_DATABASE");
		a4gl_yyerror("You cannot create a database from within Aubit4gl - if the target database allows - prepare and execute it manually");
	}
    break;

  case 63:

/* Line 1455 of yacc.c  */
#line 923 "sql.yacc"
    {
		add_feature("DROP_DATABASE");
		a4gl_yyerror("You cannot drop a database from within Aubit4gl - if the target database allows - prepare and execute it manually");
	}
    break;

  case 64:

/* Line 1455 of yacc.c  */
#line 927 "sql.yacc"
    { 
		if (strchr((yyvsp[(2) - (4)].str),'@') || strchr((yyvsp[(2) - (4)].str),':')) add_feature("CREATE_SYNONYM_QUALIFIED_PATH");
			add_feature("CREATE_SYNONYM");
			SPRINTF3((yyval.str),"%s %s FOR %s",(yyvsp[(1) - (4)].str),(yyvsp[(2) - (4)].str),(yyvsp[(4) - (4)].str)); 
	}
    break;

  case 65:

/* Line 1455 of yacc.c  */
#line 932 "sql.yacc"
    { 
		add_feature("CREATE_AUDIT");
		SPRINTF2((yyval.str),"CREATE AUDIT FOR %s IN '%s'",(yyvsp[(2) - (4)].str),A4GL_strip_quotes((yyvsp[(4) - (4)].str))); 
	}
    break;

  case 66:

/* Line 1455 of yacc.c  */
#line 936 "sql.yacc"
    { 
		add_feature("DROP_AUDIT");
		SPRINTF1((yyval.str),"DROP AUDIT FOR %s",(yyvsp[(2) - (2)].str)); }
    break;

  case 67:

/* Line 1455 of yacc.c  */
#line 939 "sql.yacc"
    { 
		if (strchr((yyvsp[(2) - (2)].str),'@') || strchr((yyvsp[(2) - (2)].str),':')) add_feature("DROP_SYNONYM_QUALIFIED_PATH");
		add_feature("DROP_SYNONYM");
		SPRINTF2((yyval.str),"%s %s",(yyvsp[(1) - (2)].str),(yyvsp[(2) - (2)].str)); }
    break;

  case 68:

/* Line 1455 of yacc.c  */
#line 943 "sql.yacc"
    { 
		add_feature("RECOVER_TABLE");
		SPRINTF1((yyval.str),"RECOVER TABLE %s",(yyvsp[(2) - (2)].str)); }
    break;

  case 69:

/* Line 1455 of yacc.c  */
#line 946 "sql.yacc"
    { 
		add_feature("ROLLFORWARD_DATABASE");
		SPRINTF1((yyval.str),"ROLLFORWARD DATABASE %s",(yyvsp[(2) - (2)].str)); }
    break;

  case 70:

/* Line 1455 of yacc.c  */
#line 953 "sql.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 71:

/* Line 1455 of yacc.c  */
#line 954 "sql.yacc"
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
#line 964 "sql.yacc"
    {(yyval.integer_val)=0;}
    break;

  case 73:

/* Line 1455 of yacc.c  */
#line 965 "sql.yacc"
    { (yyval.integer_val)=1;}
    break;

  case 75:

/* Line 1455 of yacc.c  */
#line 970 "sql.yacc"
    {SPRINTF2((yyval.str),"%s,%s",(yyvsp[(1) - (3)].str),(yyvsp[(3) - (3)].str));}
    break;

  case 76:

/* Line 1455 of yacc.c  */
#line 974 "sql.yacc"
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
#line 983 "sql.yacc"
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
#line 992 "sql.yacc"
    {
		strcpy((yyval.str),A4GL_confirm_colname(last_tmp_name,(yyvsp[(1) - (1)].str)));
}
    break;

  case 79:

/* Line 1455 of yacc.c  */
#line 999 "sql.yacc"
    {
		(yyval.sql_string)=(yyvsp[(1) - (1)].sql_string);
	}
    break;

  case 80:

/* Line 1455 of yacc.c  */
#line 1002 "sql.yacc"
    {
		(yyval.sql_string)=make_sql_string_and_free((yyvsp[(1) - (3)].sql_string),kw_comma,strdup("\n"),(yyvsp[(3) - (3)].sql_string),NULL);
	}
    break;

  case 81:

/* Line 1455 of yacc.c  */
#line 1008 "sql.yacc"
    {
		(yyval.sql_string)=make_sql_string_and_free(strdup("   "),(yyvsp[(1) - (1)].sql_string),NULL);
	}
    break;

  case 82:

/* Line 1455 of yacc.c  */
#line 1011 "sql.yacc"
    {
		(yyval.sql_string)=make_sql_string_and_free(strdup("   "),(yyvsp[(1) - (1)].sql_string),NULL);
	}
    break;

  case 83:

/* Line 1455 of yacc.c  */
#line 1022 "sql.yacc"
    {
		add_feature("ALTER_TABLE");
	(yyval.sql_string)=make_sql_string_and_free(acl_strdup((yyvsp[(1) - (3)].str)),kw_space,acl_strdup((yyvsp[(2) - (3)].str)),kw_space,(yyvsp[(3) - (3)].sql_string),NULL);
	}
    break;

  case 84:

/* Line 1455 of yacc.c  */
#line 1026 "sql.yacc"
    {
		add_feature("CLUSTER_INDEX");
		add_feature("ALTER_INDEX_CLUSTER");
		(yyval.sql_string)=make_sql_string_and_free(acl_strdup("ALTER INDEX "),acl_strdup((yyvsp[(2) - (3)].str)),acl_strdup(" TO CLUSTER"),NULL);
		}
    break;

  case 85:

/* Line 1455 of yacc.c  */
#line 1031 "sql.yacc"
    {
		add_feature("ALTER_INDEX_NOT_CLUSTER");
		(yyval.sql_string)=make_sql_string_and_free(acl_strdup("ALTER INDEX "),acl_strdup((yyvsp[(2) - (3)].str)),acl_strdup(" TO NOT CLUSTER"),NULL);
		}
    break;

  case 86:

/* Line 1455 of yacc.c  */
#line 1038 "sql.yacc"
    {
		(yyval.sql_string)=(yyvsp[(1) - (1)].sql_string);
	}
    break;

  case 87:

/* Line 1455 of yacc.c  */
#line 1041 "sql.yacc"
    {
		(yyval.sql_string)=make_sql_string_and_free((yyvsp[(1) - (3)].sql_string),kw_comma,(yyvsp[(3) - (3)].sql_string),NULL);
	}
    break;

  case 88:

/* Line 1455 of yacc.c  */
#line 1050 "sql.yacc"
    {
		(yyval.sql_string)=(yyvsp[(1) - (1)].sql_string);
	}
    break;

  case 89:

/* Line 1455 of yacc.c  */
#line 1053 "sql.yacc"
    {
	add_feature("ALTER_TABLE_DROP");
		(yyval.sql_string)=acl_strdup((yyvsp[(1) - (1)].str));
	}
    break;

  case 90:

/* Line 1455 of yacc.c  */
#line 1057 "sql.yacc"
    {
	add_feature("ALTER_TABLE_MODIFY");
		(yyval.sql_string)=(yyvsp[(1) - (1)].sql_string);
	}
    break;

  case 91:

/* Line 1455 of yacc.c  */
#line 1061 "sql.yacc"
    {
		add_feature("ALTER_TABLE_ADD_CONSTRAINT");
		(yyval.sql_string)=acl_strdup((yyvsp[(1) - (1)].str));
	}
    break;

  case 92:

/* Line 1455 of yacc.c  */
#line 1065 "sql.yacc"
    {
		add_feature("ALTER_TABLE_DROP_CONSTRAINT");
		(yyval.sql_string)=acl_strdup((yyvsp[(1) - (1)].str));
	}
    break;

  case 93:

/* Line 1455 of yacc.c  */
#line 1069 "sql.yacc"
    {
		add_feature("ALTER_TABLE_MODIFY_NEXT");
		(yyval.sql_string)=acl_strdup((yyvsp[(1) - (1)].str));
	}
    break;

  case 94:

/* Line 1455 of yacc.c  */
#line 1073 "sql.yacc"
    {
		add_feature("ALTER_TABLE_LOCK_MODE");
		(yyval.sql_string)=acl_strdup((yyvsp[(1) - (1)].str));
	}
    break;

  case 95:

/* Line 1455 of yacc.c  */
#line 1081 "sql.yacc"
    {
		add_feature("ALTER_TABLE_ADD");
		(yyval.sql_string)=make_sql_string_and_free(acl_strdup("ADD "),(yyvsp[(2) - (2)].sql_string),NULL);
	}
    break;

  case 96:

/* Line 1455 of yacc.c  */
#line 1085 "sql.yacc"
    {
		add_feature("ALTER_TABLE_ADD");
		(yyval.sql_string)=make_sql_string_and_free(acl_strdup("ADD "),kw_ob,(yyvsp[(3) - (4)].sql_string),kw_cb,NULL);
	}
    break;

  case 97:

/* Line 1455 of yacc.c  */
#line 1093 "sql.yacc"
    {
		(yyval.sql_string)=(yyvsp[(1) - (1)].sql_string);
	}
    break;

  case 98:

/* Line 1455 of yacc.c  */
#line 1096 "sql.yacc"
    {
		add_feature("ALTER_TABLE_ADD_BEFORE");
		(yyval.sql_string)=make_sql_string_and_free((yyvsp[(1) - (3)].sql_string),acl_strdup(" BEFORE "),acl_strdup((yyvsp[(3) - (3)].str)),NULL);
	}
    break;

  case 99:

/* Line 1455 of yacc.c  */
#line 1103 "sql.yacc"
    {
		(yyval.sql_string)=(yyvsp[(1) - (1)].sql_string);
	}
    break;

  case 100:

/* Line 1455 of yacc.c  */
#line 1106 "sql.yacc"
    {
		(yyval.sql_string)=make_sql_string_and_free((yyvsp[(1) - (3)].sql_string),kw_comma,(yyvsp[(3) - (3)].sql_string),NULL);
	}
    break;

  case 101:

/* Line 1455 of yacc.c  */
#line 1113 "sql.yacc"
    {
		SPRINTF1((yyval.str),"DROP %s",(yyvsp[(2) - (2)].str));
	}
    break;

  case 102:

/* Line 1455 of yacc.c  */
#line 1116 "sql.yacc"
    {
		SPRINTF1((yyval.str),"DROP (%s)",(yyvsp[(3) - (4)].str));
	}
    break;

  case 104:

/* Line 1455 of yacc.c  */
#line 1124 "sql.yacc"
    {
		SPRINTF2((yyval.str),"%s,%s",(yyvsp[(1) - (3)].str),(yyvsp[(3) - (3)].str));
	}
    break;

  case 106:

/* Line 1455 of yacc.c  */
#line 1133 "sql.yacc"
    {
		(yyval.sql_string)=make_sql_string_and_free(acl_strdup("MODIFY "),(yyvsp[(2) - (2)].sql_string),NULL);
	}
    break;

  case 107:

/* Line 1455 of yacc.c  */
#line 1136 "sql.yacc"
    {
		(yyval.sql_string)=make_sql_string_and_free(acl_strdup("MODIFY "),kw_ob,(yyvsp[(3) - (4)].sql_string),kw_cb,NULL);
	}
    break;

  case 108:

/* Line 1455 of yacc.c  */
#line 1142 "sql.yacc"
    {
		(yyval.sql_string)=(yyvsp[(1) - (1)].sql_string);
	}
    break;

  case 109:

/* Line 1455 of yacc.c  */
#line 1145 "sql.yacc"
    {
		(yyval.sql_string)=make_sql_string_and_free((yyvsp[(1) - (3)].sql_string),kw_comma,(yyvsp[(3) - (3)].sql_string),NULL);
	}
    break;

  case 110:

/* Line 1455 of yacc.c  */
#line 1151 "sql.yacc"
    {
		(yyval.sql_string)=(yyvsp[(1) - (1)].sql_string);
	}
    break;

  case 111:

/* Line 1455 of yacc.c  */
#line 1158 "sql.yacc"
    {strcpy((yyval.str),"LOCK MODE (PAGE)");}
    break;

  case 112:

/* Line 1455 of yacc.c  */
#line 1159 "sql.yacc"
    {strcpy((yyval.str),"LOCK MODE (ROW)");}
    break;

  case 113:

/* Line 1455 of yacc.c  */
#line 1163 "sql.yacc"
    {
		add_feature("DDL_NEXT_SIZE");
		SPRINTF1((yyval.str),"MODIFY NEXT SIZE %d",atoi((yyvsp[(2) - (2)].str)));
	}
    break;

  case 114:

/* Line 1455 of yacc.c  */
#line 1171 "sql.yacc"
    {
		add_feature("DDL_CONSTRAINT");
		SPRINTF2((yyval.str),"ADD CONSTRAINT %s%s",(yyvsp[(2) - (3)].sql_string),(yyvsp[(3) - (3)].str));
	}
    break;

  case 115:

/* Line 1455 of yacc.c  */
#line 1175 "sql.yacc"
    {
		add_feature("ADD_CONSTRAINT");
		SPRINTF1((yyval.str),"ADD CONSTRAINT (%s)",(yyvsp[(3) - (4)].sql_string));
	}
    break;

  case 116:

/* Line 1455 of yacc.c  */
#line 1182 "sql.yacc"
    {
		(yyval.sql_string)=make_sql_string_and_free((yyvsp[(1) - (2)].sql_string),acl_strdup((yyvsp[(2) - (2)].str)),NULL);
}
    break;

  case 117:

/* Line 1455 of yacc.c  */
#line 1184 "sql.yacc"
    {
	(yyval.sql_string)=make_sql_string_and_free((yyvsp[(1) - (4)].sql_string),kw_comma,(yyvsp[(3) - (4)].sql_string),acl_strdup((yyvsp[(4) - (4)].str)), NULL);
}
    break;

  case 118:

/* Line 1455 of yacc.c  */
#line 1189 "sql.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 119:

/* Line 1455 of yacc.c  */
#line 1190 "sql.yacc"
    {SPRINTF2((yyval.str)," %s %s",(yyvsp[(1) - (2)].str),(yyvsp[(2) - (2)].str)); add_feature("DDL_CONSTRAINT");}
    break;

  case 120:

/* Line 1455 of yacc.c  */
#line 1195 "sql.yacc"
    { SPRINTF1((yyval.str),"DROP CONSTRAINT %s",(yyvsp[(2) - (2)].str)); add_feature("DROP_CONSTRAINT"); }
    break;

  case 121:

/* Line 1455 of yacc.c  */
#line 1196 "sql.yacc"
    {add_feature("DROP_CONSTRAINT");
		SPRINTF1((yyval.str),"DROP CONSTRAINT (%s)",(yyvsp[(3) - (4)].str));
	}
    break;

  case 122:

/* Line 1455 of yacc.c  */
#line 1202 "sql.yacc"
    {strcpy((yyval.str),(yyvsp[(1) - (1)].str));}
    break;

  case 123:

/* Line 1455 of yacc.c  */
#line 1203 "sql.yacc"
    {SPRINTF2((yyval.str),"%s,%s",(yyvsp[(1) - (3)].str),(yyvsp[(3) - (3)].str));}
    break;

  case 125:

/* Line 1455 of yacc.c  */
#line 1217 "sql.yacc"
    {  add_feature("ROLLBACK_WORK"); }
    break;

  case 126:

/* Line 1455 of yacc.c  */
#line 1223 "sql.yacc"
    { insql=1;}
    break;

  case 127:

/* Line 1455 of yacc.c  */
#line 1223 "sql.yacc"
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
#line 1232 "sql.yacc"
    {insql=1;}
    break;

  case 129:

/* Line 1455 of yacc.c  */
#line 1232 "sql.yacc"
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
#line 1241 "sql.yacc"
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
#line 1266 "sql.yacc"
    {
			(yyval.str_list)=0;
	}
    break;

  case 132:

/* Line 1455 of yacc.c  */
#line 1269 "sql.yacc"
    {
			(yyval.str_list)=(yyvsp[(2) - (3)].str_list);
			 add_feature("INSERT_COLUMNLIST_EQ_VALUELIST");
	}
    break;

  case 133:

/* Line 1455 of yacc.c  */
#line 1277 "sql.yacc"
    {
                        (yyval.str_list)=new_str_list((yyvsp[(1) - (1)].str));
	}
    break;

  case 134:

/* Line 1455 of yacc.c  */
#line 1280 "sql.yacc"
    {
                        (yyval.str_list)=add_str_list((yyvsp[(1) - (3)].str_list), (yyvsp[(3) - (3)].str));
	}
    break;

  case 135:

/* Line 1455 of yacc.c  */
#line 1287 "sql.yacc"
    {	
			strcpy((yyval.str),(yyvsp[(1) - (1)].str));
	}
    break;

  case 136:

/* Line 1455 of yacc.c  */
#line 1290 "sql.yacc"
    { 
			/* with a table prefix - on an insert ? We'll just silently drop it... */
			strcpy((yyval.str),(yyvsp[(3) - (3)].str));
			A4GL_warn("Dropped table prefix from INSERT column name");
	}
    break;

  case 137:

/* Line 1455 of yacc.c  */
#line 1298 "sql.yacc"
    { (yyval.s_select_list_item_list)=local_new_select_list_item_list((yyvsp[(1) - (1)].s_select_list_item));}
    break;

  case 138:

/* Line 1455 of yacc.c  */
#line 1299 "sql.yacc"
    {
		(yyval.s_select_list_item_list)=local_add_select_list_item_list((yyvsp[(1) - (3)].s_select_list_item_list),(yyvsp[(3) - (3)].s_select_list_item));
	}
    break;

  case 139:

/* Line 1455 of yacc.c  */
#line 1305 "sql.yacc"
    {(yyval.s_select_list_item)=(yyvsp[(1) - (1)].s_select_list_item);}
    break;

  case 140:

/* Line 1455 of yacc.c  */
#line 1306 "sql.yacc"
    {(yyval.s_select_list_item)=new_select_list_item_builtin_const(E_SLI_BUILTIN_CONST_NULL); }
    break;

  case 141:

/* Line 1455 of yacc.c  */
#line 1314 "sql.yacc"
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
#line 1332 "sql.yacc"
    { add_feature("BEGIN_WORK"); }
    break;

  case 143:

/* Line 1455 of yacc.c  */
#line 1336 "sql.yacc"
    { add_feature("COMMIT_WORK"); }
    break;

  case 144:

/* Line 1455 of yacc.c  */
#line 1341 "sql.yacc"
    {(yyval.e_boolean)=EB_FALSE;}
    break;

  case 145:

/* Line 1455 of yacc.c  */
#line 1342 "sql.yacc"
    {
		add_feature("DATABASE_EXCLUSIVE");
		{(yyval.e_boolean)=EB_TRUE;}
	}
    break;

  case 146:

/* Line 1455 of yacc.c  */
#line 1352 "sql.yacc"
    {
	char buff[256];
	(yyval.sql_string)=make_sql_string_and_free(acl_strdup((yyvsp[(1) - (1)].str)),NULL);
	SPRINTF1(buff,"Warning: Informix specific SQL @ line %d\n",yylineno);
	ansi_violation(buff,1);
	}
    break;

  case 147:

/* Line 1455 of yacc.c  */
#line 1361 "sql.yacc"
    {
			add_feature("START_DATABASE_WITH_LOG_MODE_ANSI");
			sprintf((yyval.str),"START DATABASE %s WITH LOG IN %s MODE ANSI", (yyvsp[(2) - (5)].str),(yyvsp[(4) - (5)].str));
	}
    break;

  case 148:

/* Line 1455 of yacc.c  */
#line 1365 "sql.yacc"
    {
			add_feature("START_DATABASE_WITH_LOG");
			sprintf((yyval.str),"START DATABASE %s WITH LOG IN %s", (yyvsp[(2) - (4)].str),(yyvsp[(4) - (4)].str));
	}
    break;

  case 149:

/* Line 1455 of yacc.c  */
#line 1370 "sql.yacc"
    {
			add_feature("SET_CONSTRAINTS_ALL_IMMEDIATE");
			SPRINTF1((yyval.str),"%s",(yyvsp[(1) - (1)].str)); 
	}
    break;

  case 150:

/* Line 1455 of yacc.c  */
#line 1374 "sql.yacc"
    {
		add_feature("SET_BUFFERED_LOG");
			SPRINTF1((yyval.str),"%s",(yyvsp[(1) - (1)].str)); 
	}
    break;

  case 151:

/* Line 1455 of yacc.c  */
#line 1378 "sql.yacc"
    {
		add_feature("SET_LOG");
			SPRINTF1((yyval.str),"%s",(yyvsp[(1) - (1)].str)); 
	}
    break;

  case 152:

/* Line 1455 of yacc.c  */
#line 1382 "sql.yacc"
    {
			SPRINTF2((yyval.str),"%s %s",(yyvsp[(1) - (2)].str),(yyvsp[(2) - (2)].str)); add_feature("UPDATE_STATISTICS_TABLE");
	}
    break;

  case 153:

/* Line 1455 of yacc.c  */
#line 1385 "sql.yacc"
    {
		add_feature("UPDATE_STATISTICS");
			SPRINTF1((yyval.str),"%s",(yyvsp[(1) - (1)].str)); 
	}
    break;

  case 154:

/* Line 1455 of yacc.c  */
#line 1392 "sql.yacc"
    { (yyval.integer_val)=1; }
    break;

  case 155:

/* Line 1455 of yacc.c  */
#line 1393 "sql.yacc"
    { (yyval.integer_val)=-1; }
    break;

  case 156:

/* Line 1455 of yacc.c  */
#line 1394 "sql.yacc"
    { (yyval.integer_val)=0; }
    break;

  case 157:

/* Line 1455 of yacc.c  */
#line 1398 "sql.yacc"
    { (yyval.sql_string)=(yyvsp[(1) - (1)].sql_string); }
    break;

  case 158:

/* Line 1455 of yacc.c  */
#line 1399 "sql.yacc"
    { (yyval.sql_string)=(yyvsp[(1) - (1)].sql_string); }
    break;

  case 159:

/* Line 1455 of yacc.c  */
#line 1400 "sql.yacc"
    { (yyval.sql_string)=(yyvsp[(1) - (1)].sql_string); }
    break;

  case 160:

/* Line 1455 of yacc.c  */
#line 1401 "sql.yacc"
    { (yyval.sql_string)=(yyvsp[(1) - (1)].sql_string); }
    break;

  case 161:

/* Line 1455 of yacc.c  */
#line 1402 "sql.yacc"
    { (yyval.sql_string)=(yyvsp[(1) - (1)].sql_string); }
    break;

  case 162:

/* Line 1455 of yacc.c  */
#line 1403 "sql.yacc"
    { (yyval.sql_string)=(yyvsp[(1) - (1)].sql_string); }
    break;

  case 163:

/* Line 1455 of yacc.c  */
#line 1404 "sql.yacc"
    { (yyval.sql_string)=(yyvsp[(1) - (1)].sql_string); }
    break;

  case 164:

/* Line 1455 of yacc.c  */
#line 1412 "sql.yacc"
    {SPRINTF7((yyval.str),"%s %s %s %s %s %s %s",(yyvsp[(1) - (7)].str),(yyvsp[(2) - (7)].str),(yyvsp[(3) - (7)].str),(yyvsp[(4) - (7)].str),(yyvsp[(5) - (7)].str),(yyvsp[(6) - (7)].str),(yyvsp[(7) - (7)].str));  add_feature("GRANT"); }
    break;

  case 165:

/* Line 1455 of yacc.c  */
#line 1413 "sql.yacc"
    {SPRINTF6((yyval.str),"%s %s %s %s %s %s",(yyvsp[(1) - (6)].str),(yyvsp[(2) - (6)].str),(yyvsp[(3) - (6)].str),(yyvsp[(4) - (6)].str),(yyvsp[(5) - (6)].str),(yyvsp[(6) - (6)].str));  add_feature("REVOKE"); }
    break;

  case 166:

/* Line 1455 of yacc.c  */
#line 1414 "sql.yacc"
    {SPRINTF4((yyval.str),"%s %s %s %s ",(yyvsp[(1) - (4)].str),(yyvsp[(2) - (4)].str),(yyvsp[(3) - (4)].str),(yyvsp[(4) - (4)].str)); add_feature("GRANT"); }
    break;

  case 167:

/* Line 1455 of yacc.c  */
#line 1415 "sql.yacc"
    {SPRINTF4((yyval.str),"%s %s %s %s ",(yyvsp[(1) - (4)].str),(yyvsp[(2) - (4)].str),(yyvsp[(3) - (4)].str),(yyvsp[(4) - (4)].str));  add_feature("REVOKE"); }
    break;

  case 171:

/* Line 1455 of yacc.c  */
#line 1425 "sql.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 172:

/* Line 1455 of yacc.c  */
#line 1426 "sql.yacc"
    {SPRINTF1((yyval.str)," %s ",(yyvsp[(1) - (1)].str));}
    break;

  case 173:

/* Line 1455 of yacc.c  */
#line 1427 "sql.yacc"
    {SPRINTF2((yyval.str)," %s %s",(yyvsp[(1) - (2)].str),(yyvsp[(2) - (2)].str));}
    break;

  case 174:

/* Line 1455 of yacc.c  */
#line 1431 "sql.yacc"
    {SPRINTF1((yyval.str)," %s ",(yyvsp[(1) - (1)].str));}
    break;

  case 175:

/* Line 1455 of yacc.c  */
#line 1432 "sql.yacc"
    {SPRINTF1((yyval.str)," %s ",(yyvsp[(1) - (1)].str));}
    break;

  case 178:

/* Line 1455 of yacc.c  */
#line 1439 "sql.yacc"
    {SPRINTF3((yyval.str)," %s %s %s",(yyvsp[(1) - (3)].str),(yyvsp[(2) - (3)].str),(yyvsp[(3) - (3)].str));}
    break;

  case 179:

/* Line 1455 of yacc.c  */
#line 1442 "sql.yacc"
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
#line 1451 "sql.yacc"
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
#line 1462 "sql.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 186:

/* Line 1455 of yacc.c  */
#line 1464 "sql.yacc"
    {SPRINTF3((yyval.str)," %s %s %s",(yyvsp[(1) - (3)].str),(yyvsp[(2) - (3)].str),(yyvsp[(3) - (3)].str));}
    break;

  case 188:

/* Line 1455 of yacc.c  */
#line 1470 "sql.yacc"
    {SPRINTF3((yyval.str)," %s %s %s",(yyvsp[(1) - (3)].str),(yyvsp[(2) - (3)].str),(yyvsp[(3) - (3)].str));}
    break;

  case 190:

/* Line 1455 of yacc.c  */
#line 1476 "sql.yacc"
    {SPRINTF3((yyval.str)," %s %s %s",(yyvsp[(1) - (3)].str),(yyvsp[(2) - (3)].str),(yyvsp[(3) - (3)].str));}
    break;

  case 193:

/* Line 1455 of yacc.c  */
#line 1486 "sql.yacc"
    {
		add_feature("CREATE_VIEW_AS_SELECT");
		(yyval.sql_string)=make_sql_string_and_free(acl_strdup((yyvsp[(1) - (6)].str)),kw_space,acl_strdup((yyvsp[(2) - (6)].str)),kw_space,acl_strdup((yyvsp[(3) - (6)].str)),kw_space,acl_strdup((yyvsp[(4) - (6)].str)),kw_space,(yyvsp[(5) - (6)].sql_string),kw_space,acl_strdup((yyvsp[(6) - (6)].str)),NULL);
	
}
    break;

  case 194:

/* Line 1455 of yacc.c  */
#line 1493 "sql.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 195:

/* Line 1455 of yacc.c  */
#line 1495 "sql.yacc"
    {SPRINTF3((yyval.str)," %s %s %s",(yyvsp[(1) - (3)].str),(yyvsp[(2) - (3)].str),(yyvsp[(3) - (3)].str));}
    break;

  case 197:

/* Line 1455 of yacc.c  */
#line 1501 "sql.yacc"
    {SPRINTF3((yyval.str)," %s %s %s",(yyvsp[(1) - (3)].str),(yyvsp[(2) - (3)].str),(yyvsp[(3) - (3)].str));}
    break;

  case 198:

/* Line 1455 of yacc.c  */
#line 1504 "sql.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 199:

/* Line 1455 of yacc.c  */
#line 1505 "sql.yacc"
    {
		add_feature("CREATE_VIEW_SELECT_WITH_CHECK");
	}
    break;

  case 200:

/* Line 1455 of yacc.c  */
#line 1512 "sql.yacc"
    {
		(yyval.sql_string)=make_sql_string_and_free(strdup("CHECK ("),(yyvsp[(3) - (4)].sql_string),kw_cb,NULL);
		add_feature("DDL_CHECK");
	}
    break;

  case 201:

/* Line 1455 of yacc.c  */
#line 1521 "sql.yacc"
    {SPRINTF5((yyval.str)," %s %s %s %s %s",(yyvsp[(1) - (5)].str),(yyvsp[(2) - (5)].str),(yyvsp[(3) - (5)].str),(yyvsp[(4) - (5)].str),(yyvsp[(5) - (5)].str));
	add_feature("DDL_FOREIGN_KEY");
}
    break;

  case 202:

/* Line 1455 of yacc.c  */
#line 1528 "sql.yacc"
    {SPRINTF2((yyval.str)," %s %s",(yyvsp[(1) - (2)].str),(yyvsp[(2) - (2)].str));
add_feature("DDL_REFERENCES");
}
    break;

  case 205:

/* Line 1455 of yacc.c  */
#line 1540 "sql.yacc"
    {SPRINTF4((yyval.str)," %s %s %s %s",(yyvsp[(1) - (4)].str),(yyvsp[(2) - (4)].str),(yyvsp[(3) - (4)].str),(yyvsp[(4) - (4)].str));}
    break;

  case 207:

/* Line 1455 of yacc.c  */
#line 1546 "sql.yacc"
    {SPRINTF3((yyval.str)," %s %s %s",(yyvsp[(1) - (3)].str),(yyvsp[(2) - (3)].str),(yyvsp[(3) - (3)].str));}
    break;

  case 208:

/* Line 1455 of yacc.c  */
#line 1551 "sql.yacc"
    {
		SPRINTF3((yyval.str)," UNIQUE %s %s %s",(yyvsp[(2) - (4)].str),(yyvsp[(3) - (4)].str),(yyvsp[(4) - (4)].str));
add_feature("DDL_UNIQUE");
	}
    break;

  case 209:

/* Line 1455 of yacc.c  */
#line 1555 "sql.yacc"
    {
		ansi_violation("Use UNIQUE not DISTINCT",0);
		SPRINTF3((yyval.str)," UNIQUE %s %s %s",(yyvsp[(2) - (4)].str),(yyvsp[(3) - (4)].str),(yyvsp[(4) - (4)].str));
add_feature("DDL_DISTINCT");
	}
    break;

  case 210:

/* Line 1455 of yacc.c  */
#line 1561 "sql.yacc"
    {SPRINTF4((yyval.str)," %s %s %s %s",(yyvsp[(1) - (4)].str),(yyvsp[(2) - (4)].str),(yyvsp[(3) - (4)].str),(yyvsp[(4) - (4)].str));
add_feature("DDL_PRIMARY_KEY");
}
    break;

  case 212:

/* Line 1455 of yacc.c  */
#line 1569 "sql.yacc"
    {SPRINTF3((yyval.str)," %s %s %s",(yyvsp[(1) - (3)].str),(yyvsp[(2) - (3)].str),(yyvsp[(3) - (3)].str));}
    break;

  case 213:

/* Line 1455 of yacc.c  */
#line 1574 "sql.yacc"
    {
		(yyval.sql_string)=acl_strdup((yyvsp[(1) - (1)].str));
	}
    break;

  case 214:

/* Line 1455 of yacc.c  */
#line 1577 "sql.yacc"
    {
		(yyval.sql_string)=acl_strdup((yyvsp[(1) - (1)].str));
	}
    break;

  case 215:

/* Line 1455 of yacc.c  */
#line 1580 "sql.yacc"
    {
		(yyval.sql_string)=(yyvsp[(1) - (1)].sql_string);
	}
    break;

  case 216:

/* Line 1455 of yacc.c  */
#line 1587 "sql.yacc"
    {SPRINTF2((yyval.str)," %s %s",(yyvsp[(1) - (2)].str),(yyvsp[(2) - (2)].str)); add_feature("DDL_DEFAULT_VALUE"); }
    break;

  case 217:

/* Line 1455 of yacc.c  */
#line 1588 "sql.yacc"
    {SPRINTF1((yyval.str)," DEFAULT %s", A4GLSQLCV_get_sqlconst("USER")); add_feature("DDL_DEFAULT_VALUE"); }
    break;

  case 218:

/* Line 1455 of yacc.c  */
#line 1589 "sql.yacc"
    {SPRINTF1((yyval.str)," DEFAULT %s", A4GLSQLCV_get_sqlconst("TODAY")); add_feature("DDL_DEFAULT_VALUE"); }
    break;

  case 219:

/* Line 1455 of yacc.c  */
#line 1590 "sql.yacc"
    { SPRINTF1((yyval.str)," %s",(yyvsp[(1) - (1)].str)); add_feature("DDL_DEFAULT_VALUE"); }
    break;

  case 220:

/* Line 1455 of yacc.c  */
#line 1596 "sql.yacc"
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
#line 1617 "sql.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 223:

/* Line 1455 of yacc.c  */
#line 1621 "sql.yacc"
    {
		(yyval.sql_string)=acl_strdup("");
	}
    break;

  case 224:

/* Line 1455 of yacc.c  */
#line 1623 "sql.yacc"
    {
		(yyval.sql_string)=(yyvsp[(1) - (1)].sql_string);
	}
    break;

  case 225:

/* Line 1455 of yacc.c  */
#line 1630 "sql.yacc"
    {
		(yyval.sql_string)=(yyvsp[(1) - (1)].sql_string);
	}
    break;

  case 226:

/* Line 1455 of yacc.c  */
#line 1633 "sql.yacc"
    {
		(yyval.sql_string)=make_sql_string_and_free((yyvsp[(1) - (2)].sql_string),kw_space,(yyvsp[(2) - (2)].sql_string),NULL);
	}
    break;

  case 227:

/* Line 1455 of yacc.c  */
#line 1639 "sql.yacc"
    {
		(yyval.sql_string)=make_sql_string_and_free((yyvsp[(1) - (2)].sql_string),acl_strdup((yyvsp[(2) - (2)].str)),NULL);
	}
    break;

  case 228:

/* Line 1455 of yacc.c  */
#line 1647 "sql.yacc"
    {
		SPRINTF1((yyval.str)," %s ",(yyvsp[(1) - (1)].str));
		(yyval.sql_string)=acl_strdup((yyval.str));
		add_feature("DDL_NOT_NULL");
	}
    break;

  case 229:

/* Line 1455 of yacc.c  */
#line 1652 "sql.yacc"
    {
		SPRINTF0((yyval.str)," NOT NULL UNIQUE ");
		(yyval.sql_string)=acl_strdup((yyval.str));
		add_feature("DDL_NOT_NULL");
		add_feature("DDL_UNIQUE");
	}
    break;

  case 230:

/* Line 1455 of yacc.c  */
#line 1658 "sql.yacc"
    {
		SPRINTF0((yyval.str)," UNIQUE ");
		(yyval.sql_string)=acl_strdup((yyval.str));
		add_feature("DDL_UNIQUE");
	}
    break;

  case 231:

/* Line 1455 of yacc.c  */
#line 1663 "sql.yacc"
    {
		ansi_violation("Use UNIQUE not DISTINCT",0);
		SPRINTF0((yyval.str)," UNIQUE ");
		(yyval.sql_string)=acl_strdup((yyval.str));
		add_feature("DDL_DISTINCT");
	}
    break;

  case 232:

/* Line 1455 of yacc.c  */
#line 1669 "sql.yacc"
    {
		(yyval.sql_string)=acl_strdup((yyvsp[(1) - (1)].str));
	}
    break;

  case 233:

/* Line 1455 of yacc.c  */
#line 1672 "sql.yacc"
    {
		(yyval.sql_string)=make_sql_string_and_free(acl_strdup("CHECK ("),(yyvsp[(3) - (4)].sql_string),kw_cb,NULL);
		add_feature("DDL_CHECK");
		
	}
    break;

  case 234:

/* Line 1455 of yacc.c  */
#line 1677 "sql.yacc"
    {
		(yyval.sql_string)=make_sql_string_and_free(acl_strdup(" PRIMARY KEY "),NULL);
		add_feature("DDL_PRIMARY_KEY");
	}
    break;

  case 235:

/* Line 1455 of yacc.c  */
#line 1686 "sql.yacc"
    {
		add_feature("CREATE_SCHEMA");

(yyval.sql_string)=make_sql_string_and_free(acl_strdup((yyvsp[(1) - (3)].str)),kw_space,acl_strdup((yyvsp[(2) - (3)].str)),kw_space,acl_strdup((yyvsp[(3) - (3)].str)),NULL);
}
    break;

  case 236:

/* Line 1455 of yacc.c  */
#line 1695 "sql.yacc"
    {SPRINTF1((yyval.str)," %s",(yyvsp[(1) - (1)].str));}
    break;

  case 239:

/* Line 1455 of yacc.c  */
#line 1704 "sql.yacc"
    {
		(yyval.sql_string)=make_sql_string_and_free((yyvsp[(1) - (2)].sql_string),kw_space,(yyvsp[(2) - (2)].sql_string),NULL);
	}
    break;

  case 240:

/* Line 1455 of yacc.c  */
#line 1710 "sql.yacc"
    {
		(yyval.sql_string)=(yyvsp[(1) - (1)].sql_string);
	}
    break;

  case 241:

/* Line 1455 of yacc.c  */
#line 1713 "sql.yacc"
    {
		(yyval.sql_string)=acl_strdup((yyvsp[(1) - (1)].str));
	}
    break;

  case 242:

/* Line 1455 of yacc.c  */
#line 1724 "sql.yacc"
    {
		 add_feature("HAVING"); 
		(yyval.s_select_list_item)=(yyvsp[(2) - (2)].s_select_list_item);
	}
    break;

  case 243:

/* Line 1455 of yacc.c  */
#line 1733 "sql.yacc"
    {
		 (yyval.s_select_list_item)=(yyvsp[(2) - (2)].s_select_list_item);
	}
    break;

  case 244:

/* Line 1455 of yacc.c  */
#line 1740 "sql.yacc"
    {
		(yyval.u_table)=(yyvsp[(2) - (2)].u_table);
	}
    break;

  case 245:

/* Line 1455 of yacc.c  */
#line 1746 "sql.yacc"
    {(yyval.u_table)=(yyvsp[(1) - (1)].u_table);}
    break;

  case 246:

/* Line 1455 of yacc.c  */
#line 1747 "sql.yacc"
    {
		(yyval.u_table)=A4GLSQLPARSE_append_tablename((yyvsp[(1) - (3)].u_table),(yyvsp[(3) - (3)].u_table),E_OUTER_NONE,NULL);
	}
    break;

  case 247:

/* Line 1455 of yacc.c  */
#line 1750 "sql.yacc"
    {
		(yyval.u_table)=A4GLSQLPARSE_append_tablename((yyvsp[(1) - (4)].u_table),(yyvsp[(4) - (4)].u_table),E_OUTER_NORMAL,NULL);
		A4GL_warn("OUTER join *may* not be portable to non-informix database");
		add_feature("SELECT_OUTER");
	}
    break;

  case 248:

/* Line 1455 of yacc.c  */
#line 1755 "sql.yacc"
    {
		(yyval.u_table)=A4GLSQLPARSE_append_tablename((yyvsp[(1) - (6)].u_table),(yyvsp[(5) - (6)].u_table),E_OUTER_NORMAL,NULL);
		A4GL_warn("OUTER join *may* not be portable to non-informix database");
		add_feature("SELECT_OUTER");
	}
    break;

  case 249:

/* Line 1455 of yacc.c  */
#line 1766 "sql.yacc"
    {
		(yyval.u_table)=A4GLSQLPARSE_append_tablename((yyvsp[(1) - (5)].u_table),(yyvsp[(3) - (5)].u_table),E_OUTER_LEFT_OUTER, (yyvsp[(5) - (5)].s_select_list_item));
		add_feature("SELECT_OUTER");
	}
    break;

  case 250:

/* Line 1455 of yacc.c  */
#line 1770 "sql.yacc"
    {
		(yyval.u_table)=A4GLSQLPARSE_append_tablename((yyvsp[(1) - (5)].u_table),(yyvsp[(3) - (5)].u_table),E_INNER, (yyvsp[(5) - (5)].s_select_list_item));
		add_feature("SELECT_INNER");
	}
    break;

  case 252:

/* Line 1455 of yacc.c  */
#line 1778 "sql.yacc"
    {(yyval.u_table)=(yyvsp[(2) - (3)].u_table);}
    break;

  case 253:

/* Line 1455 of yacc.c  */
#line 1782 "sql.yacc"
    { 
			//A4GL_add_crud("SELECT",$<str>1);
			(yyval.u_table)=A4GLSQLPARSE_new_tablename((yyvsp[(1) - (1)].str),NULL);
	}
    break;

  case 254:

/* Line 1455 of yacc.c  */
#line 1786 "sql.yacc"
    { 
			//A4GL_add_crud("SELECT",$<str>1);
			(yyval.u_table)=A4GLSQLPARSE_new_tablename((yyvsp[(1) - (2)].str),(yyvsp[(2) - (2)].str));
	}
    break;

  case 255:

/* Line 1455 of yacc.c  */
#line 1790 "sql.yacc"
    { 
			//A4GL_add_crud("SELECT",$<str>1);
			(yyval.u_table)=A4GLSQLPARSE_new_tablename((yyvsp[(1) - (3)].str),(yyvsp[(3) - (3)].str));
	}
    break;

  case 256:

/* Line 1455 of yacc.c  */
#line 1797 "sql.yacc"
    {
			/* No from or where etc.. */
			/* eg.. select user ; */
			(yyval.s_select)=new_empty_select();
		}
    break;

  case 257:

/* Line 1455 of yacc.c  */
#line 1802 "sql.yacc"
    {
		(yyval.s_select)=(yyvsp[(2) - (2)].s_select);
		(yyval.s_select)->first=(yyvsp[(1) - (2)].u_table);
			A4GL_set_associated_mem( (yyval.s_select), (yyval.s_select)->first);
}
    break;

  case 258:

/* Line 1455 of yacc.c  */
#line 1810 "sql.yacc"
    {
		(yyval.s_select)=(yyvsp[(1) - (1)].s_select);
	}
    break;

  case 259:

/* Line 1455 of yacc.c  */
#line 1813 "sql.yacc"
    {
		(yyval.s_select)=(yyvsp[(2) - (2)].s_select);
		(yyval.s_select)->where_clause=(yyvsp[(1) - (2)].s_select_list_item);
	}
    break;

  case 260:

/* Line 1455 of yacc.c  */
#line 1819 "sql.yacc"
    {
		(yyval.s_select)=new_empty_select();
	}
    break;

  case 261:

/* Line 1455 of yacc.c  */
#line 1822 "sql.yacc"
    {
		(yyval.s_select)=new_empty_select();
		(yyval.s_select)->group_by=(yyvsp[(1) - (1)].s_select_list_item_list);
		(yyval.s_select)->having=0;
	}
    break;

  case 262:

/* Line 1455 of yacc.c  */
#line 1827 "sql.yacc"
    {
		(yyval.s_select)=new_empty_select();
		(yyval.s_select)->group_by=(yyvsp[(1) - (2)].s_select_list_item_list);
		(yyval.s_select)->having=(yyvsp[(2) - (2)].s_select_list_item);
	}
    break;

  case 263:

/* Line 1455 of yacc.c  */
#line 1832 "sql.yacc"
    {
		(yyval.s_select)=new_empty_select();
		(yyval.s_select)->group_by=0;
		(yyval.s_select)->having=(yyvsp[(1) - (1)].s_select_list_item);

	}
    break;

  case 264:

/* Line 1455 of yacc.c  */
#line 1845 "sql.yacc"
    {
		(yyval.s_select_list_item)=(yyvsp[(1) - (1)].s_select_list_item);
	}
    break;

  case 265:

/* Line 1455 of yacc.c  */
#line 1848 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_op_expr((yyvsp[(1) - (3)].s_select_list_item),(yyvsp[(3) - (3)].s_select_list_item)," OR ");
	}
    break;

  case 266:

/* Line 1455 of yacc.c  */
#line 1854 "sql.yacc"
    {
		(yyval.s_select_list_item)=(yyvsp[(1) - (1)].s_select_list_item);
	}
    break;

  case 267:

/* Line 1455 of yacc.c  */
#line 1857 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_op_expr((yyvsp[(1) - (3)].s_select_list_item),(yyvsp[(3) - (3)].s_select_list_item)," AND ");
	}
    break;

  case 268:

/* Line 1455 of yacc.c  */
#line 1863 "sql.yacc"
    {
		(yyval.s_select_list_item)=(yyvsp[(1) - (1)].s_select_list_item);
	}
    break;

  case 269:

/* Line 1455 of yacc.c  */
#line 1866 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_simple_expr(E_SLI_NOT,(yyvsp[(2) - (2)].s_select_list_item));
	}
    break;

  case 270:

/* Line 1455 of yacc.c  */
#line 1872 "sql.yacc"
    {
		(yyval.s_select_list_item)=(yyvsp[(1) - (1)].s_select_list_item);
	}
    break;

  case 271:

/* Line 1455 of yacc.c  */
#line 1875 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_simple_expr(E_SLI_BRACKET_EXPR,(yyvsp[(2) - (3)].s_select_list_item));
	}
    break;

  case 272:

/* Line 1455 of yacc.c  */
#line 1882 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_sq(E_SQE_EXISTS, (yyvsp[(2) - (2)].s_select_list_item));
		add_feature("WHERE_EXISTS");
	}
    break;

  case 273:

/* Line 1455 of yacc.c  */
#line 1886 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_sq(E_SQE_NOT_EXISTS, (yyvsp[(2) - (2)].s_select_list_item));
		add_feature("WHERE_EXISTS");
	}
    break;

  case 274:

/* Line 1455 of yacc.c  */
#line 1897 "sql.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 275:

/* Line 1455 of yacc.c  */
#line 1897 "sql.yacc"
    {SPRINTF1((yyval.str)," ESCAPE %s",(yyvsp[(2) - (2)].str));add_feature("WHERE_MATCHES_ESCAPE");}
    break;

  case 276:

/* Line 1455 of yacc.c  */
#line 1898 "sql.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 277:

/* Line 1455 of yacc.c  */
#line 1898 "sql.yacc"
    {SPRINTF1((yyval.str)," ESCAPE %s",(yyvsp[(2) - (2)].str));add_feature("WHERE_ILIKE_ESCAPE");}
    break;

  case 278:

/* Line 1455 of yacc.c  */
#line 1899 "sql.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 279:

/* Line 1455 of yacc.c  */
#line 1899 "sql.yacc"
    {SPRINTF1((yyval.str)," ESCAPE %s",(yyvsp[(2) - (2)].str));add_feature("WHERE_LIKE_ESCAPE");}
    break;

  case 280:

/* Line 1455 of yacc.c  */
#line 1902 "sql.yacc"
    {
		 (yyval.s_select_list_item)=(yyvsp[(1) - (1)].s_select_list_item);
	}
    break;

  case 282:

/* Line 1455 of yacc.c  */
#line 1912 "sql.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 283:

/* Line 1455 of yacc.c  */
#line 1913 "sql.yacc"
    {strcpy((yyval.str)," NOT ");}
    break;

  case 284:

/* Line 1455 of yacc.c  */
#line 1918 "sql.yacc"
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
#line 1927 "sql.yacc"
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
#line 1935 "sql.yacc"
    { 
			(yyval.s_select_list_item)=new_select_list_item_op_expr((yyvsp[(1) - (3)].s_select_list_item),(yyvsp[(3) - (3)].s_select_list_item),(yyvsp[(2) - (3)].str));
	}
    break;

  case 287:

/* Line 1455 of yacc.c  */
#line 1938 "sql.yacc"
    { 
			(yyval.s_select_list_item)=new_select_list_item_op_expr((yyvsp[(1) - (3)].s_select_list_item),(yyvsp[(3) - (3)].s_select_list_item),"=");
	}
    break;

  case 288:

/* Line 1455 of yacc.c  */
#line 1941 "sql.yacc"
    { 
			FPRINTF(stderr,"Warning: Corrected =NULL to IS NULL line %d\n",yylineno);
			(yyval.s_select_list_item)=new_select_list_item_simple_expr(E_SLI_ISNULL,(yyvsp[(1) - (3)].s_select_list_item));
	}
    break;

  case 289:

/* Line 1455 of yacc.c  */
#line 1945 "sql.yacc"
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
#line 1952 "sql.yacc"
    { 
			(yyval.s_select_list_item)=new_select_list_item_regex(E_SLI_REGEX_LIKE,(yyvsp[(1) - (4)].s_select_list_item),(yyvsp[(3) - (4)].s_select_list_item),(yyvsp[(4) - (4)].str));
	}
    break;

  case 291:

/* Line 1455 of yacc.c  */
#line 1955 "sql.yacc"
    { 
			(yyval.s_select_list_item)=new_select_list_item_regex(E_SLI_REGEX_NOT_LIKE,(yyvsp[(1) - (4)].s_select_list_item),(yyvsp[(3) - (4)].s_select_list_item),(yyvsp[(4) - (4)].str));

	}
    break;

  case 292:

/* Line 1455 of yacc.c  */
#line 1959 "sql.yacc"
    { 
			(yyval.s_select_list_item)=new_select_list_item_regex(E_SLI_REGEX_ILIKE,(yyvsp[(1) - (4)].s_select_list_item),(yyvsp[(3) - (4)].s_select_list_item),(yyvsp[(4) - (4)].str));
	}
    break;

  case 293:

/* Line 1455 of yacc.c  */
#line 1962 "sql.yacc"
    { 
			(yyval.s_select_list_item)=new_select_list_item_regex(E_SLI_REGEX_NOT_ILIKE,(yyvsp[(1) - (4)].s_select_list_item),(yyvsp[(3) - (4)].s_select_list_item),(yyvsp[(4) - (4)].str));
	}
    break;

  case 294:

/* Line 1455 of yacc.c  */
#line 1965 "sql.yacc"
    { 
			(yyval.s_select_list_item)=new_select_list_item_regex(E_SLI_REGEX_MATCHES,(yyvsp[(1) - (4)].s_select_list_item),(yyvsp[(3) - (4)].s_select_list_item),(yyvsp[(4) - (4)].str));
	}
    break;

  case 295:

/* Line 1455 of yacc.c  */
#line 1968 "sql.yacc"
    { 
			(yyval.s_select_list_item)=new_select_list_item_regex(E_SLI_REGEX_NOT_MATCHES,(yyvsp[(1) - (4)].s_select_list_item),(yyvsp[(3) - (4)].s_select_list_item),(yyvsp[(4) - (4)].str));
	}
    break;

  case 296:

/* Line 1455 of yacc.c  */
#line 1974 "sql.yacc"
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
#line 1981 "sql.yacc"
    {
			strcpy((yyval.str)," < ");
	}
    break;

  case 298:

/* Line 1455 of yacc.c  */
#line 1984 "sql.yacc"
    {
			strcpy((yyval.str)," > ");
	}
    break;

  case 299:

/* Line 1455 of yacc.c  */
#line 1987 "sql.yacc"
    {
			strcpy((yyval.str)," ~ ");
	}
    break;

  case 300:

/* Line 1455 of yacc.c  */
#line 1990 "sql.yacc"
    {strcpy((yyval.str)," <= ");}
    break;

  case 301:

/* Line 1455 of yacc.c  */
#line 1991 "sql.yacc"
    {strcpy((yyval.str)," >= ");}
    break;

  case 302:

/* Line 1455 of yacc.c  */
#line 1996 "sql.yacc"
    {
		(yyval.s_select_list_item)=(yyvsp[(1) - (1)].s_select_list_item);
	}
    break;

  case 303:

/* Line 1455 of yacc.c  */
#line 1999 "sql.yacc"
    {
		(yyval.s_select_list_item)=(yyvsp[(1) - (1)].s_select_list_item);
	}
    break;

  case 304:

/* Line 1455 of yacc.c  */
#line 2002 "sql.yacc"
    {
		(yyval.s_select_list_item)=(yyvsp[(1) - (1)].s_select_list_item);
	}
    break;

  case 305:

/* Line 1455 of yacc.c  */
#line 2005 "sql.yacc"
    {
                 (yyval.s_select_list_item)=(yyvsp[(1) - (1)].s_select_list_item);
        }
    break;

  case 306:

/* Line 1455 of yacc.c  */
#line 2012 "sql.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 307:

/* Line 1455 of yacc.c  */
#line 2013 "sql.yacc"
    {strcpy((yyval.str)," ALL "); add_feature("AGG_ALL");}
    break;

  case 308:

/* Line 1455 of yacc.c  */
#line 2014 "sql.yacc"
    {
		strcpy((yyval.str)," DISTINCT ");
		add_feature("AGG_DISTINCT");
	}
    break;

  case 309:

/* Line 1455 of yacc.c  */
#line 2018 "sql.yacc"
    {
		ansi_violation("Use DISTINCT not UNIQUE",0);
		strcpy((yyval.str)," DISTINCT ");
		add_feature("AGG_DISTINCT");
	}
    break;

  case 310:

/* Line 1455 of yacc.c  */
#line 2025 "sql.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 311:

/* Line 1455 of yacc.c  */
#line 2026 "sql.yacc"
    {strcpy((yyval.str)," ALL "); add_feature("UNION_ALL");}
    break;

  case 312:

/* Line 1455 of yacc.c  */
#line 2027 "sql.yacc"
    {
		strcpy((yyval.str)," DISTINCT ");
		add_feature("UNION_DISTINCT");
	}
    break;

  case 313:

/* Line 1455 of yacc.c  */
#line 2031 "sql.yacc"
    {
		ansi_violation("Use DISTINCT not UNIQUE",0);
		add_feature("UNION_DISTINCT");
		strcpy((yyval.str)," DISTINCT ");
	}
    break;

  case 314:

/* Line 1455 of yacc.c  */
#line 2045 "sql.yacc"
    {
		strcpy((yyval.str),A4GLSQLCV_dtype_alias((yyvsp[(1) - (1)].str)));
	}
    break;

  case 319:

/* Line 1455 of yacc.c  */
#line 2060 "sql.yacc"
    {SPRINTF4((yyval.str)," %s %s%s%s",(yyvsp[(1) - (4)].str),(yyvsp[(2) - (4)].str),(yyvsp[(3) - (4)].str),(yyvsp[(4) - (4)].str));}
    break;

  case 320:

/* Line 1455 of yacc.c  */
#line 2064 "sql.yacc"
    {strcpy((yyval.str),"SERIAL"); add_feature("DDL_SERIAL"); }
    break;

  case 321:

/* Line 1455 of yacc.c  */
#line 2065 "sql.yacc"
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
#line 2074 "sql.yacc"
    {strcpy((yyval.str),"SERIAL8"); add_feature("DDL_SERIAL8"); }
    break;

  case 323:

/* Line 1455 of yacc.c  */
#line 2076 "sql.yacc"
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
#line 2085 "sql.yacc"
    {
 			add_feature("DDL_DECIMAL");
	}
    break;

  case 325:

/* Line 1455 of yacc.c  */
#line 2088 "sql.yacc"
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
#line 2096 "sql.yacc"
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
#line 2106 "sql.yacc"
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
#line 2114 "sql.yacc"
    {strcpy((yyval.str),"DATE");
 			add_feature("DDL_DATE"); }
    break;

  case 329:

/* Line 1455 of yacc.c  */
#line 2116 "sql.yacc"
    {strcpy((yyval.str),"INTEGER");}
    break;

  case 330:

/* Line 1455 of yacc.c  */
#line 2117 "sql.yacc"
    {strcpy((yyval.str),"SMALLINT");}
    break;

  case 331:

/* Line 1455 of yacc.c  */
#line 2118 "sql.yacc"
    {strcpy((yyval.str),"NCHAR"); add_feature("DDL_NCHAR");}
    break;

  case 332:

/* Line 1455 of yacc.c  */
#line 2119 "sql.yacc"
    {SPRINTF1((yyval.str),"NCHAR(%s)",(yyvsp[(3) - (4)].str)); add_feature("DDL_NCHAR");}
    break;

  case 333:

/* Line 1455 of yacc.c  */
#line 2120 "sql.yacc"
    {add_feature("DDL_NVARCHAR");}
    break;

  case 334:

/* Line 1455 of yacc.c  */
#line 2121 "sql.yacc"
    {SPRINTF1((yyval.str),"NVARCHAR(%s)",(yyvsp[(3) - (4)].str)); add_feature("DDL_NVARCHAR");}
    break;

  case 335:

/* Line 1455 of yacc.c  */
#line 2122 "sql.yacc"
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
#line 2130 "sql.yacc"
    {SPRINTF2((yyval.str),"DATETIME %s TO %s",(yyvsp[(2) - (4)].str),(yyvsp[(4) - (4)].str)); add_feature("DDL_DATETIME");}
    break;

  case 337:

/* Line 1455 of yacc.c  */
#line 2131 "sql.yacc"
    {add_feature("DDL_DATETIME");}
    break;

  case 338:

/* Line 1455 of yacc.c  */
#line 2132 "sql.yacc"
    {SPRINTF2((yyval.str),"INTERVAL %s TO %s",(yyvsp[(2) - (4)].str),(yyvsp[(4) - (4)].str)); add_feature("DDL_INTERVAL");}
    break;

  case 339:

/* Line 1455 of yacc.c  */
#line 2133 "sql.yacc"
    {strcpy((yyval.str),(yyvsp[(1) - (1)].str));}
    break;

  case 340:

/* Line 1455 of yacc.c  */
#line 2134 "sql.yacc"
    {add_feature("DDL_INTERVAL");}
    break;

  case 341:

/* Line 1455 of yacc.c  */
#line 2135 "sql.yacc"
    {SPRINTF3((yyval.str),"INTERVAL %s(%s) TO %s",(yyvsp[(2) - (7)].str),(yyvsp[(4) - (7)].str),(yyvsp[(7) - (7)].str)); add_feature("DDL_INTERVAL");}
    break;

  case 342:

/* Line 1455 of yacc.c  */
#line 2136 "sql.yacc"
    {add_feature("DDL_TEXT");}
    break;

  case 343:

/* Line 1455 of yacc.c  */
#line 2137 "sql.yacc"
    {add_feature("DDL_BYTE");}
    break;

  case 344:

/* Line 1455 of yacc.c  */
#line 2138 "sql.yacc"
    {add_feature("DDL_VARCHAR");}
    break;

  case 345:

/* Line 1455 of yacc.c  */
#line 2139 "sql.yacc"
    {SPRINTF1((yyval.str),"VARCHAR(%s)",(yyvsp[(3) - (4)].str));add_feature("DDL_VARCHAR");}
    break;

  case 346:

/* Line 1455 of yacc.c  */
#line 2140 "sql.yacc"
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
#line 2150 "sql.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 348:

/* Line 1455 of yacc.c  */
#line 2151 "sql.yacc"
    {
		SPRINTF1((yyval.str),",%s",(yyvsp[(2) - (2)].str));
}
    break;

  case 349:

/* Line 1455 of yacc.c  */
#line 2158 "sql.yacc"
    {SPRINTF4((yyval.str)," %s %s %s %s",(yyvsp[(1) - (4)].str),(yyvsp[(2) - (4)].str),(yyvsp[(3) - (4)].str),(yyvsp[(4) - (4)].str));}
    break;

  case 353:

/* Line 1455 of yacc.c  */
#line 2162 "sql.yacc"
    {add_feature("DDL_DOUBLE_PRECISION"); SPRINTF1((yyval.str)," %s",(yyvsp[(1) - (1)].str));}
    break;

  case 359:

/* Line 1455 of yacc.c  */
#line 2187 "sql.yacc"
    {(yyval.int_list.i0)=0;}
    break;

  case 360:

/* Line 1455 of yacc.c  */
#line 2188 "sql.yacc"
    {
		(yyval.int_list.i0)=1;
		(yyval.int_list.i1)=atoi((yyvsp[(2) - (3)].str));
	}
    break;

  case 361:

/* Line 1455 of yacc.c  */
#line 2192 "sql.yacc"
    {
		(yyval.int_list.i0)=2;
		(yyval.int_list.i1)=atoi((yyvsp[(2) - (5)].str));
		(yyval.int_list.i2)=atoi((yyvsp[(4) - (5)].str));
	}
    break;

  case 362:

/* Line 1455 of yacc.c  */
#line 2200 "sql.yacc"
    {
		strcpy((yyval.str),(yyvsp[(1) - (1)].str));
	}
    break;

  case 363:

/* Line 1455 of yacc.c  */
#line 2203 "sql.yacc"
    {
		strcpy((yyval.str),(yyvsp[(2) - (2)].str));
	}
    break;

  case 364:

/* Line 1455 of yacc.c  */
#line 2210 "sql.yacc"
    {
		(yyval.s_select_list_item)= (yyvsp[(1) - (1)].s_select_list_item);
	}
    break;

  case 365:

/* Line 1455 of yacc.c  */
#line 2213 "sql.yacc"
    {
		(yyval.s_select_list_item)= (yyvsp[(2) - (2)].s_select_list_item);
	}
    break;

  case 366:

/* Line 1455 of yacc.c  */
#line 2223 "sql.yacc"
    { 
		(yyval.s_select_list_item)=new_select_list_item_col(0,(yyvsp[(1) - (2)].str),&(yyvsp[(2) - (2)].int_list));
	}
    break;

  case 367:

/* Line 1455 of yacc.c  */
#line 2226 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_col((yyvsp[(1) - (4)].str),(yyvsp[(3) - (4)].str),&(yyvsp[(4) - (4)].int_list));
	}
    break;

  case 368:

/* Line 1455 of yacc.c  */
#line 2229 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_col((yyvsp[(1) - (3)].str),"*",0);
	}
    break;

  case 369:

/* Line 1455 of yacc.c  */
#line 2232 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_col(0,"rowid",0);
	}
    break;

  case 370:

/* Line 1455 of yacc.c  */
#line 2239 "sql.yacc"
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
#line 2246 "sql.yacc"
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
#line 2254 "sql.yacc"
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
#line 2263 "sql.yacc"
    {
		SPRINTF1((yyval.str),"%s",A4GLSQLCV_check_colname((yyvsp[(1) - (3)].str),"*"));
		ADDMAP("Use Column",(yyval.str));
	}
    break;

  case 375:

/* Line 1455 of yacc.c  */
#line 2274 "sql.yacc"
    { strcpy((yyval.str),(yyvsp[(1) - (1)].str)); A4GL_debug("Set $<str>$ to %s\n",(yyval.str)); }
    break;

  case 379:

/* Line 1455 of yacc.c  */
#line 2282 "sql.yacc"
    { strcpy((yyval.str),A4GLSQLCV_generate_current(0,0)); 
}
    break;

  case 380:

/* Line 1455 of yacc.c  */
#line 2284 "sql.yacc"
    {
		strcpy((yyval.str),A4GLSQLCV_generate_current((yyvsp[(1) - (3)].str),(yyvsp[(3) - (3)].str)));
	}
    break;

  case 395:

/* Line 1455 of yacc.c  */
#line 2294 "sql.yacc"
    {SPRINTF1((yyval.str),"FRACTION(%s)",(yyvsp[(3) - (4)].str));}
    break;

  case 396:

/* Line 1455 of yacc.c  */
#line 2339 "sql.yacc"
    { (yyval.sql_string)=make_sql_string_and_free(acl_strdup((yyvsp[(1) - (1)].str)), NULL);}
    break;

  case 397:

/* Line 1455 of yacc.c  */
#line 2340 "sql.yacc"
    { (yyval.sql_string)=make_sql_string_and_free(acl_strdup((yyvsp[(1) - (1)].str)), NULL);}
    break;

  case 398:

/* Line 1455 of yacc.c  */
#line 2341 "sql.yacc"
    { (yyval.sql_string)=make_sql_string_and_free(acl_strdup((yyvsp[(1) - (1)].str)), NULL);}
    break;

  case 399:

/* Line 1455 of yacc.c  */
#line 2346 "sql.yacc"
    { add_feature("RENAME_TABLE"); strcpy((yyval.str),A4GLSQLCV_rentab((yyvsp[(2) - (4)].str),(yyvsp[(4) - (4)].str))); }
    break;

  case 400:

/* Line 1455 of yacc.c  */
#line 2347 "sql.yacc"
    { add_feature("RENAME_COLUMN"); strcpy((yyval.str),A4GLSQLCV_rencol((yyvsp[(2) - (6)].str),(yyvsp[(4) - (6)].str),(yyvsp[(6) - (6)].str)) ); }
    break;

  case 403:

/* Line 1455 of yacc.c  */
#line 2355 "sql.yacc"
    {
		add_feature("UNLOCK_TABLE");
		SPRINTF2((yyval.str),"%s %s",(yyvsp[(1) - (2)].str),(yyvsp[(2) - (2)].str));
	}
    break;

  case 404:

/* Line 1455 of yacc.c  */
#line 2362 "sql.yacc"
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
#line 2373 "sql.yacc"
    { add_feature("LOCK_TABLE_SHARED");}
    break;

  case 406:

/* Line 1455 of yacc.c  */
#line 2374 "sql.yacc"
    {add_feature("LOCK_TABLE_EXCLUSIVE");}
    break;

  case 407:

/* Line 1455 of yacc.c  */
#line 2387 "sql.yacc"
    {strcpy((yyval.str),A4GLSQLCV_datetime_value((yyvsp[(1) - (1)].str)));}
    break;

  case 408:

/* Line 1455 of yacc.c  */
#line 2388 "sql.yacc"
    {strcpy((yyval.str),A4GLSQLCV_make_dtime_extend((yyvsp[(1) - (4)].str),(yyvsp[(2) - (4)].str),(yyvsp[(4) - (4)].str),0));}
    break;

  case 409:

/* Line 1455 of yacc.c  */
#line 2392 "sql.yacc"
    {strcpy((yyval.str),(yyvsp[(1) - (1)].str));}
    break;

  case 410:

/* Line 1455 of yacc.c  */
#line 2396 "sql.yacc"
    {strcpy((yyval.str),A4GLSQLCV_interval_value((yyvsp[(1) - (1)].str)));}
    break;

  case 411:

/* Line 1455 of yacc.c  */
#line 2397 "sql.yacc"
    {
			strcpy((yyval.str),A4GLSQLCV_make_ival_extend((yyvsp[(1) - (7)].str),(yyvsp[(2) - (7)].str),(yyvsp[(4) - (7)].str),(yyvsp[(7) - (7)].str),0));
		}
    break;

  case 412:

/* Line 1455 of yacc.c  */
#line 2400 "sql.yacc"
    {
		strcpy((yyval.str),A4GLSQLCV_make_ival_extend((yyvsp[(1) - (4)].str),(yyvsp[(2) - (4)].str),(char *)0, (yyvsp[(4) - (4)].str),0));
	}
    break;

  case 413:

/* Line 1455 of yacc.c  */
#line 2406 "sql.yacc"
    {SPRINTF1((yyval.str),"%s",(yyvsp[(1) - (1)].str));}
    break;

  case 414:

/* Line 1455 of yacc.c  */
#line 2410 "sql.yacc"
    {
	strcpy((yyval.str),(yyvsp[(2) - (2)].str));
}
    break;

  case 415:

/* Line 1455 of yacc.c  */
#line 2433 "sql.yacc"
    {
		(yyval.s_select_list_item_list)=(yyvsp[(3) - (3)].s_select_list_item_list);
		add_feature("ORDER_BY");
	}
    break;

  case 416:

/* Line 1455 of yacc.c  */
#line 2443 "sql.yacc"
    {
			(yyval.s_select_list_item_list)=local_new_select_list_item_list((yyvsp[(1) - (1)].s_select_list_item));
	}
    break;

  case 417:

/* Line 1455 of yacc.c  */
#line 2446 "sql.yacc"
    {
			(yyval.s_select_list_item_list)=local_add_select_list_item_list((yyvsp[(1) - (3)].s_select_list_item_list),(yyvsp[(3) - (3)].s_select_list_item));
	}
    break;

  case 418:

/* Line 1455 of yacc.c  */
#line 2452 "sql.yacc"
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
#line 2461 "sql.yacc"
    { 
		add_feature("ORDER_BY_NUMBER");
		(yyval.s_select_list_item)=new_select_list_item_literal((yyvsp[(1) - (1)].str));
	}
    break;

  case 420:

/* Line 1455 of yacc.c  */
#line 2465 "sql.yacc"
    {
		(yyval.s_select_list_item)=(yyvsp[(1) - (1)].s_select_list_item);
		(yyval.s_select_list_item)->data.type=E_SLI_COLUMN_ORDERBY;
	}
    break;

  case 421:

/* Line 1455 of yacc.c  */
#line 2472 "sql.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 422:

/* Line 1455 of yacc.c  */
#line 2474 "sql.yacc"
    {add_feature("ORDER_BY_ASC"); strcpy((yyval.str),"ASC");}
    break;

  case 423:

/* Line 1455 of yacc.c  */
#line 2476 "sql.yacc"
    {add_feature("ORDER_BY_DESC"); strcpy((yyval.str),"DESC");}
    break;

  case 424:

/* Line 1455 of yacc.c  */
#line 2480 "sql.yacc"
    {
		(yyval.s_select_list_item_list)=(yyvsp[(2) - (2)].s_select_list_item_list);
	}
    break;

  case 425:

/* Line 1455 of yacc.c  */
#line 2486 "sql.yacc"
    {
			(yyval.s_select_list_item_list)=local_new_select_list_item_list((yyvsp[(1) - (1)].s_select_list_item));
	}
    break;

  case 426:

/* Line 1455 of yacc.c  */
#line 2489 "sql.yacc"
    {
			(yyval.s_select_list_item_list)=local_add_select_list_item_list((yyvsp[(1) - (3)].s_select_list_item_list),(yyvsp[(3) - (3)].s_select_list_item));
	}
    break;

  case 427:

/* Line 1455 of yacc.c  */
#line 2495 "sql.yacc"
    { (yyval.s_select_list_item)=(yyvsp[(1) - (1)].s_select_list_item); }
    break;

  case 428:

/* Line 1455 of yacc.c  */
#line 2496 "sql.yacc"
    { (yyval.s_select_list_item)=new_select_list_item_literal((yyvsp[(1) - (1)].str)); }
    break;

  case 429:

/* Line 1455 of yacc.c  */
#line 2503 "sql.yacc"
    {
	(yyval.sql_string)=get_select_list_item(0,(yyvsp[(1) - (1)].s_select_list_item));
}
    break;

  case 430:

/* Line 1455 of yacc.c  */
#line 2516 "sql.yacc"
    {
		A4GL_set_sql_lineno(yylineno);
		(yyval.sql_string)=make_select_stmt_v2(current_upd_table, (yyvsp[(1) - (1)].s_select),"");
		map_select_stmt("SELECT",(yyvsp[(1) - (1)].s_select));
		A4GL_free_select_stmt((yyvsp[(1) - (1)].s_select));
}
    break;

  case 431:

/* Line 1455 of yacc.c  */
#line 2526 "sql.yacc"
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
#line 2533 "sql.yacc"
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
#line 2550 "sql.yacc"
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
#line 2557 "sql.yacc"
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
#line 2582 "sql.yacc"
    { 
		//start_bind('i',0);
		 set_ignore_indicators();}
    break;

  case 436:

/* Line 1455 of yacc.c  */
#line 2584 "sql.yacc"
    { clr_ignore_indicators();}
    break;

  case 437:

/* Line 1455 of yacc.c  */
#line 2586 "sql.yacc"
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
#line 2607 "sql.yacc"
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
#line 2650 "sql.yacc"
    { (yyval.s_select)=0;}
    break;

  case 440:

/* Line 1455 of yacc.c  */
#line 2651 "sql.yacc"
    { 
		(yyval.s_select)=(yyvsp[(3) - (3)].s_select);
		(yyval.s_select)->union_op=acl_strdup((yyvsp[(2) - (3)].str));
		A4GL_set_associated_mem((yyval.s_select), (yyval.s_select)->union_op);
		add_feature("SELECT_UNION"); 
	}
    break;

  case 441:

/* Line 1455 of yacc.c  */
#line 2665 "sql.yacc"
    {
		(yyval.s_select_finish)=0;
	}
    break;

  case 442:

/* Line 1455 of yacc.c  */
#line 2668 "sql.yacc"
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
#line 2675 "sql.yacc"
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
#line 2685 "sql.yacc"
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
#line 2703 "sql.yacc"
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
#line 2716 "sql.yacc"
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
#line 2731 "sql.yacc"
    {(yyval.integer_val)=-1;}
    break;

  case 449:

/* Line 1455 of yacc.c  */
#line 2733 "sql.yacc"
    {
		(yyval.integer_val)=atol((yyvsp[(2) - (2)].str));
	}
    break;

  case 450:

/* Line 1455 of yacc.c  */
#line 2739 "sql.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 451:

/* Line 1455 of yacc.c  */
#line 2740 "sql.yacc"
    {strcpy((yyval.str),"ALL"); add_feature("SELECT_ALL");}
    break;

  case 452:

/* Line 1455 of yacc.c  */
#line 2741 "sql.yacc"
    {strcpy((yyval.str),"DISTINCT"); add_feature("SELECT_DISTINCT");}
    break;

  case 453:

/* Line 1455 of yacc.c  */
#line 2742 "sql.yacc"
    {strcpy((yyval.str),"DISTINCT");
		add_feature("SELECT_UNIQUE");
		ansi_violation("Use DISTINCT not UNIQUE",0);
		strcpy((yyval.str),"DISTINCT");
	}
    break;

  case 454:

/* Line 1455 of yacc.c  */
#line 2752 "sql.yacc"
    { 
		 (yyval.s_select_list_item_list)=local_new_select_list_item_list((yyvsp[(1) - (1)].s_select_list_item));
	}
    break;

  case 455:

/* Line 1455 of yacc.c  */
#line 2755 "sql.yacc"
    { 
		(yyval.s_select_list_item_list)=local_add_select_list_item_list((yyvsp[(1) - (3)].s_select_list_item_list),(yyvsp[(3) - (3)].s_select_list_item));
	}
    break;

  case 456:

/* Line 1455 of yacc.c  */
#line 2761 "sql.yacc"
    {
		(yyval.s_select_list_item)=(yyvsp[(1) - (1)].s_select_list_item);
	}
    break;

  case 457:

/* Line 1455 of yacc.c  */
#line 2764 "sql.yacc"
    {
		(yyval.s_select_list_item)=(yyvsp[(1) - (2)].s_select_list_item);
		(yyval.s_select_list_item)->alias=acl_strdup((yyvsp[(2) - (2)].str));
		A4GL_set_associated_mem((yyval.s_select_list_item), (yyval.s_select_list_item)->alias);
	}
    break;

  case 458:

/* Line 1455 of yacc.c  */
#line 2769 "sql.yacc"
    {
		(yyval.s_select_list_item)=(yyvsp[(1) - (3)].s_select_list_item);
		(yyval.s_select_list_item)->alias=acl_strdup((yyvsp[(3) - (3)].str));
		A4GL_set_associated_mem((yyval.s_select_list_item), (yyval.s_select_list_item)->alias);
	}
    break;

  case 459:

/* Line 1455 of yacc.c  */
#line 2778 "sql.yacc"
    {
		(yyval.s_select_list_item)=(yyvsp[(1) - (1)].s_select_list_item); /* A4GLSQLCV_check_expr($<sql_string>1) */
	}
    break;

  case 460:

/* Line 1455 of yacc.c  */
#line 2781 "sql.yacc"
    {
		(yyval.s_select_list_item)=(yyvsp[(2) - (2)].s_select_list_item);
		(yyval.s_select_list_item)->sign='-';
	}
    break;

  case 461:

/* Line 1455 of yacc.c  */
#line 2785 "sql.yacc"
    {
		(yyval.s_select_list_item)=(yyvsp[(2) - (2)].s_select_list_item);
	}
    break;

  case 462:

/* Line 1455 of yacc.c  */
#line 2792 "sql.yacc"
    {
			(yyval.s_select_list_item)=new_select_list_item_op_expr ((yyvsp[(1) - (3)].s_select_list_item), (yyvsp[(3) - (3)].s_select_list_item), "/");
	}
    break;

  case 463:

/* Line 1455 of yacc.c  */
#line 2795 "sql.yacc"
    {
			(yyval.s_select_list_item)=new_select_list_item_simple_expr((enum e_sli)(yyvsp[(2) - (2)].integer_val), (yyvsp[(1) - (2)].s_select_list_item));
	}
    break;

  case 464:

/* Line 1455 of yacc.c  */
#line 2798 "sql.yacc"
    {
			(yyval.s_select_list_item)=new_select_list_item_op_expr ((yyvsp[(1) - (3)].s_select_list_item), (yyvsp[(3) - (3)].s_select_list_item), "*");
	}
    break;

  case 465:

/* Line 1455 of yacc.c  */
#line 2801 "sql.yacc"
    {
			(yyval.s_select_list_item)=new_select_list_item_op_expr ((yyvsp[(1) - (3)].s_select_list_item), (yyvsp[(3) - (3)].s_select_list_item), "+");
	}
    break;

  case 466:

/* Line 1455 of yacc.c  */
#line 2804 "sql.yacc"
    {
			(yyval.s_select_list_item)=new_select_list_item_op_expr ((yyvsp[(1) - (3)].s_select_list_item), (yyvsp[(3) - (3)].s_select_list_item), "-");
	}
    break;

  case 467:

/* Line 1455 of yacc.c  */
#line 2807 "sql.yacc"
    { (yyval.s_select_list_item)=new_select_list_item_literal((yyvsp[(1) - (1)].str)); }
    break;

  case 468:

/* Line 1455 of yacc.c  */
#line 2808 "sql.yacc"
    { (yyval.s_select_list_item)=new_select_list_item_builtin_const(E_SLI_BUILTIN_CONST_TRUE); }
    break;

  case 469:

/* Line 1455 of yacc.c  */
#line 2809 "sql.yacc"
    { (yyval.s_select_list_item)=new_select_list_item_builtin_const(E_SLI_BUILTIN_CONST_FALSE); }
    break;

  case 470:

/* Line 1455 of yacc.c  */
#line 2810 "sql.yacc"
    { (yyval.s_select_list_item)=new_select_list_item_builtin_const(E_SLI_BUILTIN_CONST_USER); }
    break;

  case 471:

/* Line 1455 of yacc.c  */
#line 2811 "sql.yacc"
    { (yyval.s_select_list_item)=new_select_list_item_builtin_const(E_SLI_BUILTIN_CONST_TODAY); }
    break;

  case 472:

/* Line 1455 of yacc.c  */
#line 2812 "sql.yacc"
    { (yyval.s_select_list_item)=new_select_list_item_builtin_const(E_SLI_BUILTIN_CONST_ROWID); }
    break;

  case 473:

/* Line 1455 of yacc.c  */
#line 2813 "sql.yacc"
    { (yyval.s_select_list_item)=new_select_list_item_builtin_const(E_SLI_BUILTIN_CONST_TIME); }
    break;

  case 474:

/* Line 1455 of yacc.c  */
#line 2814 "sql.yacc"
    { (yyval.s_select_list_item)=new_select_list_item_builtin_const(E_SLI_BUILTIN_CONST_STAR); }
    break;

  case 475:

/* Line 1455 of yacc.c  */
#line 2815 "sql.yacc"
    { (yyval.s_select_list_item)=new_select_list_item_builtin_const(E_SLI_BUILTIN_CONST_COUNT_STAR); }
    break;

  case 476:

/* Line 1455 of yacc.c  */
#line 2817 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_agg1(E_SLI_BUILTIN_AGG_AVG,(yyvsp[(3) - (5)].str),(yyvsp[(4) - (5)].s_select_list_item));
		add_feature("SELECT_AVG");
	}
    break;

  case 477:

/* Line 1455 of yacc.c  */
#line 2821 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_agg1(E_SLI_BUILTIN_AGG_MAX,(yyvsp[(3) - (5)].str),(yyvsp[(4) - (5)].s_select_list_item));
		add_feature("SELECT_MAX");
	}
    break;

  case 478:

/* Line 1455 of yacc.c  */
#line 2825 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_agg1(E_SLI_BUILTIN_AGG_MIN,(yyvsp[(3) - (5)].str),(yyvsp[(4) - (5)].s_select_list_item));
		add_feature("SELECT_MIN");
	}
    break;

  case 479:

/* Line 1455 of yacc.c  */
#line 2829 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_agg1(E_SLI_BUILTIN_AGG_SUM,(yyvsp[(3) - (5)].str),(yyvsp[(4) - (5)].s_select_list_item));
		add_feature("SELECT_SUM");
	}
    break;

  case 480:

/* Line 1455 of yacc.c  */
#line 2833 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_agg1(E_SLI_BUILTIN_AGG_COUNT,(yyvsp[(3) - (5)].str),(yyvsp[(4) - (5)].s_select_list_item));
		add_feature("SELECT_COUNT");
	}
    break;

  case 481:

/* Line 1455 of yacc.c  */
#line 2837 "sql.yacc"
    {
		add_sql_function((yyvsp[(1) - (3)].str));
		(yyval.s_select_list_item)=new_select_list_item_fcall((yyvsp[(1) - (3)].str),0);
	}
    break;

  case 482:

/* Line 1455 of yacc.c  */
#line 2841 "sql.yacc"
    {
		add_sql_function((yyvsp[(1) - (4)].str));
		(yyval.s_select_list_item)=new_select_list_item_fcall((yyvsp[(1) - (4)].str),(yyvsp[(3) - (4)].s_select_list_item_list));
	}
    break;

  case 483:

/* Line 1455 of yacc.c  */
#line 2845 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_builtin_fcall(E_SLI_BUILTIN_FUNC_YEAR,(yyvsp[(3) - (4)].s_select_list_item_list));
	}
    break;

  case 484:

/* Line 1455 of yacc.c  */
#line 2848 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_builtin_fcall(E_SLI_BUILTIN_FUNC_MONTH,(yyvsp[(3) - (4)].s_select_list_item_list));
	}
    break;

  case 485:

/* Line 1455 of yacc.c  */
#line 2851 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_builtin_fcall(E_SLI_BUILTIN_FUNC_DAY,(yyvsp[(3) - (4)].s_select_list_item_list));
	}
    break;

  case 486:

/* Line 1455 of yacc.c  */
#line 2854 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_builtin_fcall(E_SLI_BUILTIN_FUNC_MDY,(yyvsp[(3) - (4)].s_select_list_item_list));
	}
    break;

  case 487:

/* Line 1455 of yacc.c  */
#line 2857 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_builtin_fcall(E_SLI_BUILTIN_FUNC_WEEKDAY,(yyvsp[(3) - (4)].s_select_list_item_list));
	}
    break;

  case 488:

/* Line 1455 of yacc.c  */
#line 2860 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_builtin_fcall(E_SLI_BUILTIN_FUNC_DOW,(yyvsp[(3) - (4)].s_select_list_item_list));
	}
    break;

  case 489:

/* Line 1455 of yacc.c  */
#line 2863 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_builtin_fcall(E_SLI_BUILTIN_FUNC_DATE,(yyvsp[(3) - (4)].s_select_list_item_list));
	}
    break;

  case 490:

/* Line 1455 of yacc.c  */
#line 2866 "sql.yacc"
    {
		  (yyval.s_select_list_item)=new_select_list_item_simple_expr(E_SLI_BRACKET_EXPR,(yyvsp[(2) - (3)].s_select_list_item));
	}
    break;

  case 491:

/* Line 1455 of yacc.c  */
#line 2869 "sql.yacc"
    { 
		add_feature("EXTEND"); 
		(yyval.s_select_list_item)=(yyvsp[(3) - (4)].s_select_list_item);
	}
    break;

  case 492:

/* Line 1455 of yacc.c  */
#line 2873 "sql.yacc"
    { 
		(yyval.s_select_list_item)=new_select_list_item_datetime((yyvsp[(1) - (1)].str));
		add_feature("FUNC_DATETIME");
	}
    break;

  case 493:

/* Line 1455 of yacc.c  */
#line 2877 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_interval((yyvsp[(1) - (1)].str));
		add_feature("FUNC_INTERVAL");
	}
    break;

  case 494:

/* Line 1455 of yacc.c  */
#line 2881 "sql.yacc"
    {
		(yyval.s_select_list_item)=(yyvsp[(2) - (3)].s_select_list_item);
	}
    break;

  case 495:

/* Line 1455 of yacc.c  */
#line 2889 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_case((yyvsp[(1) - (1)].s_select_list_item));
	}
    break;

  case 496:

/* Line 1455 of yacc.c  */
#line 2892 "sql.yacc"
    {
		(yyval.s_select_list_item)=append_select_list_item_case(
							(yyvsp[(1) - (2)].s_select_list_item),
							(yyvsp[(2) - (2)].s_select_list_item));
	}
    break;

  case 497:

/* Line 1455 of yacc.c  */
#line 2901 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_case_element(
				(yyvsp[(2) - (4)].s_select_list_item),
				(yyvsp[(4) - (4)].s_select_list_item));

	}
    break;

  case 498:

/* Line 1455 of yacc.c  */
#line 2907 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_case_element( 0, (yyvsp[(2) - (2)].s_select_list_item));
	}
    break;

  case 499:

/* Line 1455 of yacc.c  */
#line 2914 "sql.yacc"
    {
		(yyval.s_select_list_item_list)=local_new_select_list_item_list((yyvsp[(1) - (1)].s_select_list_item));
	}
    break;

  case 500:

/* Line 1455 of yacc.c  */
#line 2917 "sql.yacc"
    {
			(yyval.s_select_list_item_list)=local_add_select_list_item_list((yyvsp[(1) - (3)].s_select_list_item_list),(yyvsp[(3) - (3)].s_select_list_item));
	}
    break;

  case 501:

/* Line 1455 of yacc.c  */
#line 2945 "sql.yacc"
    {
			(yyval.s_select_list_item)=new_select_list_item_extend(new_select_list_item_builtin_const(E_SLI_BUILTIN_CONST_CURRENT),(yyvsp[(3) - (5)].str),(yyvsp[(5) - (5)].str));
	}
    break;

  case 502:

/* Line 1455 of yacc.c  */
#line 2948 "sql.yacc"
    {
			(yyval.s_select_list_item)=new_select_list_item_extend((yyvsp[(1) - (5)].s_select_list_item),(yyvsp[(3) - (5)].str),(yyvsp[(5) - (5)].str));
	}
    break;

  case 503:

/* Line 1455 of yacc.c  */
#line 2951 "sql.yacc"
    {
			(yyval.s_select_list_item)=new_select_list_item_extend(new_select_list_item_builtin_const(E_SLI_BUILTIN_CONST_CURRENT),(yyvsp[(2) - (4)].str),(yyvsp[(4) - (4)].str));
	}
    break;

  case 504:

/* Line 1455 of yacc.c  */
#line 2954 "sql.yacc"
    {
			(yyval.s_select_list_item)=new_select_list_item_extend((yyvsp[(1) - (5)].s_select_list_item),(yyvsp[(3) - (5)].str),(yyvsp[(5) - (5)].str));
	}
    break;

  case 505:

/* Line 1455 of yacc.c  */
#line 2960 "sql.yacc"
    {(yyval.integer_val)=E_SLI_UNITS_YEAR;}
    break;

  case 506:

/* Line 1455 of yacc.c  */
#line 2961 "sql.yacc"
    {(yyval.integer_val)=E_SLI_UNITS_MONTH;}
    break;

  case 507:

/* Line 1455 of yacc.c  */
#line 2962 "sql.yacc"
    {(yyval.integer_val)=E_SLI_UNITS_DAY;}
    break;

  case 508:

/* Line 1455 of yacc.c  */
#line 2963 "sql.yacc"
    {(yyval.integer_val)=E_SLI_UNITS_HOUR;}
    break;

  case 509:

/* Line 1455 of yacc.c  */
#line 2964 "sql.yacc"
    {(yyval.integer_val)=E_SLI_UNITS_MINUTE;}
    break;

  case 510:

/* Line 1455 of yacc.c  */
#line 2965 "sql.yacc"
    {(yyval.integer_val)=E_SLI_UNITS_SECOND;}
    break;

  case 511:

/* Line 1455 of yacc.c  */
#line 2970 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_op_slil((yyvsp[(1) - (5)].s_select_list_item),(yyvsp[(4) - (5)].s_select_list_item_list),E_SLI_IN_VALUES);
                add_feature("WHERE_IN");
        }
    break;

  case 512:

/* Line 1455 of yacc.c  */
#line 2974 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_op_sli((yyvsp[(1) - (3)].s_select_list_item),(yyvsp[(3) - (3)].s_select_list_item),E_SLI_IN_SELECT);
                add_feature("WHERE_IN_SELECT");
        }
    break;

  case 513:

/* Line 1455 of yacc.c  */
#line 2978 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_op_slil((yyvsp[(1) - (5)].s_select_list_item),(yyvsp[(4) - (5)].s_select_list_item_list),E_SLI_NOT_IN_VALUES);
                add_feature("WHERE_IN");
        }
    break;

  case 514:

/* Line 1455 of yacc.c  */
#line 2982 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_op_sli((yyvsp[(1) - (3)].s_select_list_item),(yyvsp[(3) - (3)].s_select_list_item),E_SLI_NOT_IN_SELECT);
                add_feature("WHERE_IN_SELECT");
        }
    break;

  case 515:

/* Line 1455 of yacc.c  */
#line 2989 "sql.yacc"
    {
		(yyval.s_select_list_item_list)=local_new_select_list_item_list((yyvsp[(1) - (1)].s_select_list_item));
	}
    break;

  case 516:

/* Line 1455 of yacc.c  */
#line 2992 "sql.yacc"
    {
                (yyval.s_select_list_item_list)=local_add_select_list_item_list((yyvsp[(1) - (3)].s_select_list_item_list),(yyvsp[(3) - (3)].s_select_list_item));
	}
    break;

  case 517:

/* Line 1455 of yacc.c  */
#line 2997 "sql.yacc"
    { (yyval.s_select_list_item)=(yyvsp[(1) - (1)].s_select_list_item);}
    break;

  case 518:

/* Line 1455 of yacc.c  */
#line 2998 "sql.yacc"
    { (yyval.s_select_list_item)=new_select_list_item_literal((yyvsp[(1) - (1)].str)); }
    break;

  case 519:

/* Line 1455 of yacc.c  */
#line 2999 "sql.yacc"
    { 
		char buff[256]; SPRINTF1(buff," -%s",(yyvsp[(2) - (2)].str)); (yyval.s_select_list_item)=new_select_list_item_literal(buff); }
    break;

  case 520:

/* Line 1455 of yacc.c  */
#line 3001 "sql.yacc"
    { char buff[256]; SPRINTF1(buff," -%s",(yyvsp[(2) - (2)].str)); (yyval.s_select_list_item)=new_select_list_item_literal(buff); }
    break;

  case 521:

/* Line 1455 of yacc.c  */
#line 3007 "sql.yacc"
    {
                if (strstr((yyvsp[(1) - (1)].str),"systables")!=0) { add_feature("IFX_SYSTABLES"); }
                if (strstr((yyvsp[(1) - (1)].str),"syscolumns")!=0) { add_feature("IFX_SYSCOLUMNS"); }
                if (strstr((yyvsp[(1) - (1)].str),"sysindexes")!=0) { add_feature("IFX_SYSINDEXES"); }
                strcpy((yyval.str),A4GLSQLCV_check_tablename((yyvsp[(1) - (1)].str)));
                }
    break;

  case 522:

/* Line 1455 of yacc.c  */
#line 3017 "sql.yacc"
    {
	     SPRINTF1((yyval.str),"%s", A4GLSQLCV_ownerize_tablename(NULL, A4GL_strip_quotes((yyvsp[(1) - (1)].str))));
             ADDMAP("Use Table",(yyval.str));
        }
    break;

  case 523:

/* Line 1455 of yacc.c  */
#line 3021 "sql.yacc"
    {
	     SPRINTF1((yyval.str),"%s", A4GLSQLCV_ownerize_tablename((yyvsp[(1) - (3)].str), (yyvsp[(3) - (3)].str)));
	     ADDMAP("Use Table",(yyval.str));
        }
    break;

  case 524:

/* Line 1455 of yacc.c  */
#line 3025 "sql.yacc"
    {
	     SPRINTF1((yyval.str),"%s", A4GLSQLCV_ownerize_tablename(NULL, (yyvsp[(1) - (1)].str)));
	     ADDMAP("Use Table",(yyval.str));
	}
    break;

  case 525:

/* Line 1455 of yacc.c  */
#line 3029 "sql.yacc"
    {
	     SPRINTF1((yyval.str),"%s", A4GLSQLCV_db_tablename((yyvsp[(1) - (3)].str), NULL, A4GLSQLCV_ownerize_tablename(NULL, (yyvsp[(3) - (3)].str))));
	     ADDMAP("Use Table",(yyval.str));
	}
    break;

  case 526:

/* Line 1455 of yacc.c  */
#line 3033 "sql.yacc"
    {
	     SPRINTF1((yyval.str),"%s", A4GLSQLCV_db_tablename((yyvsp[(1) - (5)].str), NULL, A4GLSQLCV_ownerize_tablename((yyvsp[(3) - (5)].str),(yyvsp[(5) - (5)].str))));
	     ADDMAP("Use Table",(yyval.str));
        }
    break;

  case 527:

/* Line 1455 of yacc.c  */
#line 3037 "sql.yacc"
    {
	     SPRINTF1((yyval.str),"%s", A4GLSQLCV_db_tablename(NULL,(yyvsp[(1) - (3)].str), A4GLSQLCV_ownerize_tablename(NULL, (yyvsp[(3) - (3)].str))));
	     ADDMAP("Use Table",(yyval.str));
	}
    break;

  case 528:

/* Line 1455 of yacc.c  */
#line 3041 "sql.yacc"
    {
	     SPRINTF1((yyval.str),"%s", A4GLSQLCV_db_tablename((yyvsp[(1) - (5)].str), (yyvsp[(3) - (5)].str), A4GLSQLCV_ownerize_tablename(NULL, (yyvsp[(5) - (5)].str))));
	     ADDMAP("Use Table",(yyval.str));
	}
    break;

  case 529:

/* Line 1455 of yacc.c  */
#line 3045 "sql.yacc"
    {
	     SPRINTF1((yyval.str),"%s", A4GLSQLCV_db_tablename((yyvsp[(1) - (7)].str), (yyvsp[(3) - (7)].str), A4GLSQLCV_ownerize_tablename((yyvsp[(5) - (7)].str), (yyvsp[(7) - (7)].str))));
	     ADDMAP("Use Table",(yyval.str));
        }
    break;

  case 530:

/* Line 1455 of yacc.c  */
#line 3053 "sql.yacc"
    {
                if (strstr((yyvsp[(1) - (1)].str),"systables")!=0) { add_feature("IFX_SYSTABLES"); }
                if (strstr((yyvsp[(1) - (1)].str),"syscolumns")!=0) { add_feature("IFX_SYSCOLUMNS"); }
                if (strstr((yyvsp[(1) - (1)].str),"sysindexes")!=0) { add_feature("IFX_SYSINDEXES"); }
                strcpy((yyval.str),A4GLSQLCV_check_tablename((yyvsp[(1) - (1)].str)));
                }
    break;

  case 531:

/* Line 1455 of yacc.c  */
#line 3063 "sql.yacc"
    {

	     SPRINTF1((yyval.str),"%s", A4GLSQLCV_ownerize_tablename((yyvsp[(1) - (3)].str), (yyvsp[(3) - (3)].str)));
	     ADDMAP("Use Table",(yyval.str));
        }
    break;

  case 532:

/* Line 1455 of yacc.c  */
#line 3068 "sql.yacc"
    {
	     SPRINTF1((yyval.str),"%s", A4GLSQLCV_ownerize_tablename((yyvsp[(1) - (3)].str), (yyvsp[(3) - (3)].str)));
	     ADDMAP("Use Table",(yyval.str));
        }
    break;

  case 533:

/* Line 1455 of yacc.c  */
#line 3072 "sql.yacc"
    {
	     SPRINTF1((yyval.str),"%s", A4GLSQLCV_ownerize_tablename(NULL, A4GL_strip_quotes((yyvsp[(1) - (1)].str))));
	     ADDMAP("Use Table",(yyval.str));
        }
    break;

  case 534:

/* Line 1455 of yacc.c  */
#line 3076 "sql.yacc"
    {
             SPRINTF1((yyval.str),"%s", A4GLSQLCV_ownerize_tablename(NULL, (yyvsp[(1) - (1)].str)));
	     ADDMAP("Use Table",(yyval.str));
	}
    break;

  case 535:

/* Line 1455 of yacc.c  */
#line 3080 "sql.yacc"
    {
             SPRINTF1((yyval.str),"%s", A4GLSQLCV_db_tablename((yyvsp[(1) - (3)].str),NULL, A4GLSQLCV_ownerize_tablename(NULL, (yyvsp[(3) - (3)].str))));
	     ADDMAP("Use Table",(yyval.str));
	}
    break;

  case 536:

/* Line 1455 of yacc.c  */
#line 3084 "sql.yacc"
    {
	     SPRINTF1((yyval.str),"%s", A4GLSQLCV_db_tablename((yyvsp[(1) - (5)].str), NULL,A4GLSQLCV_ownerize_tablename((yyvsp[(3) - (5)].str), (yyvsp[(5) - (5)].str))));
	     ADDMAP("Use Table",(yyval.str));
        }
    break;

  case 537:

/* Line 1455 of yacc.c  */
#line 3089 "sql.yacc"
    {
             SPRINTF1((yyval.str),"%s", A4GLSQLCV_db_tablename(NULL, (yyvsp[(1) - (3)].str), A4GLSQLCV_ownerize_tablename(NULL, (yyvsp[(3) - (3)].str))));
	     ADDMAP("Use Table",(yyval.str));
	}
    break;

  case 538:

/* Line 1455 of yacc.c  */
#line 3093 "sql.yacc"
    {
            SPRINTF1((yyval.str),"%s", A4GLSQLCV_db_tablename( (yyvsp[(1) - (5)].str), (yyvsp[(3) - (5)].str), A4GLSQLCV_ownerize_tablename(NULL, (yyvsp[(5) - (5)].str))));
	    ADDMAP("Use Table",(yyval.str));
	}
    break;

  case 539:

/* Line 1455 of yacc.c  */
#line 3097 "sql.yacc"
    {
	     SPRINTF1((yyval.str),"%s", A4GLSQLCV_db_tablename((yyvsp[(1) - (7)].str), (yyvsp[(3) - (7)].str), A4GLSQLCV_ownerize_tablename((yyvsp[(5) - (7)].str), (yyvsp[(7) - (7)].str))));
	     ADDMAP("Use Table",(yyval.str));
        }
    break;

  case 540:

/* Line 1455 of yacc.c  */
#line 3105 "sql.yacc"
    {
	     SPRINTF1((yyval.str),"%s", A4GLSQLCV_ownerize_tablename((yyvsp[(1) - (3)].str), (yyvsp[(3) - (3)].str)));
        }
    break;

  case 541:

/* Line 1455 of yacc.c  */
#line 3108 "sql.yacc"
    {
	        SPRINTF1((yyval.str),"%s", A4GLSQLCV_ownerize_tablename(NULL, (yyvsp[(1) - (1)].str)));
                ADDMAP("Use Index",(yyval.str));
        }
    break;

  case 542:

/* Line 1455 of yacc.c  */
#line 3113 "sql.yacc"
    {strcpy((yyval.str),(yyvsp[(1) - (1)].str)); ADDMAP("Use Index",(yyvsp[(1) - (1)].str)); }
    break;

  case 543:

/* Line 1455 of yacc.c  */
#line 3114 "sql.yacc"
    { SPRINTF3((yyval.str),"%s%s%s",(yyvsp[(1) - (3)].str),(yyvsp[(2) - (3)].str),(yyvsp[(3) - (3)].str)); ADDMAP("Use Index",(yyval.str)); }
    break;

  case 544:

/* Line 1455 of yacc.c  */
#line 3115 "sql.yacc"
    {
	     SPRINTF2((yyval.str),"%s:%s", (yyvsp[(1) - (5)].str), A4GLSQLCV_ownerize_tablename((yyvsp[(3) - (5)].str), (yyvsp[(5) - (5)].str)));
             ADDMAP("Use Index",(yyval.str));
        }
    break;

  case 545:

/* Line 1455 of yacc.c  */
#line 3120 "sql.yacc"
    {strcpy((yyval.str),(yyvsp[(1) - (3)].str)); ADDMAP("Use Index",(yyvsp[(1) - (3)].str)); }
    break;

  case 546:

/* Line 1455 of yacc.c  */
#line 3121 "sql.yacc"
    { SPRINTF4((yyval.str),"%s@%s%s%s",(yyvsp[(1) - (5)].str),(yyvsp[(3) - (5)].str),(yyvsp[(4) - (5)].str),(yyvsp[(5) - (5)].str)); ADDMAP("Use Index",(yyval.str)); }
    break;

  case 547:

/* Line 1455 of yacc.c  */
#line 3122 "sql.yacc"
    {
	     SPRINTF3((yyval.str),"%s@%s:%s", (yyvsp[(1) - (7)].str), (yyvsp[(3) - (7)].str), A4GLSQLCV_ownerize_tablename((yyvsp[(5) - (7)].str), (yyvsp[(7) - (7)].str)));
             ADDMAP("Use Index",(yyval.str));
        }
    break;

  case 549:

/* Line 1455 of yacc.c  */
#line 3133 "sql.yacc"
    {
                      (yyval.ptr)=A4GL_new_expr_simple_string(A4GL_get_clobbered_from((yyval.str)), ET_EXPR_IDENTIFIER);
	}
    break;

  case 551:

/* Line 1455 of yacc.c  */
#line 3139 "sql.yacc"
    { sprintf((yyval.str),".%s",(yyvsp[(2) - (2)].str)); }
    break;

  case 553:

/* Line 1455 of yacc.c  */
#line 3144 "sql.yacc"
    {strcpy((yyval.str), A4GL_strip_quotes ((yyvsp[(1) - (1)].str)));}
    break;

  case 558:

/* Line 1455 of yacc.c  */
#line 3195 "sql.yacc"
    {
			int converted;
			(yyval.sql_string)=get_insert_cmd((yyvsp[(1) - (1)].insert_cmd),&converted);
			A4GL_free_associated_mem((yyvsp[(1) - (1)].insert_cmd));
			acl_free((yyvsp[(1) - (1)].insert_cmd));

		}
    break;

  case 559:

/* Line 1455 of yacc.c  */
#line 3202 "sql.yacc"
    {
			int converted;
			(yyval.sql_string)=get_update_cmd((yyvsp[(1) - (1)].update_cmd),&converted);
			A4GL_free_associated_mem((yyvsp[(1) - (1)].update_cmd));
			acl_free((yyvsp[(1) - (1)].update_cmd));
		}
    break;

  case 560:

/* Line 1455 of yacc.c  */
#line 3208 "sql.yacc"
    {
			int converted;
			(yyval.sql_string)=get_delete_cmd((yyvsp[(1) - (1)].delete_cmd),&converted);
			A4GL_free_associated_mem((yyvsp[(1) - (1)].delete_cmd));
			acl_free((yyvsp[(1) - (1)].delete_cmd));
		}
    break;

  case 563:

/* Line 1455 of yacc.c  */
#line 3223 "sql.yacc"
    { print_exec_select((yyvsp[(1) - (1)].sql_string));  }
    break;

  case 564:

/* Line 1455 of yacc.c  */
#line 3224 "sql.yacc"
    { print_exec_select((yyvsp[(1) - (1)].sql_string));  }
    break;

  case 566:

/* Line 1455 of yacc.c  */
#line 3226 "sql.yacc"
    { print_exec_select((yyvsp[(1) - (1)].sql_string));  }
    break;

  case 567:

/* Line 1455 of yacc.c  */
#line 3228 "sql.yacc"
    {
			print_sql_commit ((yyvsp[(1) - (1)].integer_val));
	}
    break;

  case 568:

/* Line 1455 of yacc.c  */
#line 3231 "sql.yacc"
    {print_unable_to_parse();}
    break;

  case 569:

/* Line 1455 of yacc.c  */
#line 3235 "sql.yacc"
    { (yyval.sql_string)=make_sql_string_and_free((yyvsp[(1) - (2)].sql_string),acl_strdup((yyvsp[(2) - (2)].str)),0);
}
    break;

  case 571:

/* Line 1455 of yacc.c  */
#line 3244 "sql.yacc"
    {
			(yyval.sql_string)=make_select_stmt_v2("", (yyvsp[(1) - (1)].s_select),"");
			A4GL_free_select_stmt((yyvsp[(1) - (1)].s_select));
		}
    break;

  case 572:

/* Line 1455 of yacc.c  */
#line 3250 "sql.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 573:

/* Line 1455 of yacc.c  */
#line 3251 "sql.yacc"
    {
			strcpy((yyval.str),A4GLSQLCV_get_forupdate(NULL));
		}
    break;

  case 574:

/* Line 1455 of yacc.c  */
#line 3254 "sql.yacc"
    {
			strcpy((yyval.str),A4GLSQLCV_get_forupdate((yyvsp[(2) - (2)].str)));
		}
    break;

  case 575:

/* Line 1455 of yacc.c  */
#line 3259 "sql.yacc"
    { strcpy((yyval.str),(yyvsp[(1) - (1)].str)); }
    break;

  case 576:

/* Line 1455 of yacc.c  */
#line 3260 "sql.yacc"
    { sprintf((yyval.str),"%s,%s",(yyvsp[(1) - (3)].str),(yyvsp[(3) - (3)].str)); }
    break;

  case 578:

/* Line 1455 of yacc.c  */
#line 3264 "sql.yacc"
    {sprintf((yyval.str),"%s.%s",A4GLSQLCV_ownerize_tablename(NULL, (yyvsp[(1) - (3)].str)),(yyvsp[(3) - (3)].str));}
    break;

  case 579:

/* Line 1455 of yacc.c  */
#line 3265 "sql.yacc"
    {
        sprintf((yyval.str),"%s.%s", A4GLSQLCV_ownerize_tablename((yyvsp[(1) - (5)].str), (yyvsp[(3) - (5)].str)), (yyvsp[(5) - (5)].str));
}
    break;

  case 580:

/* Line 1455 of yacc.c  */
#line 3275 "sql.yacc"
    { print_exec_sql(acl_strdup((yyvsp[(1) - (1)].str))); }
    break;

  case 581:

/* Line 1455 of yacc.c  */
#line 3276 "sql.yacc"
    { print_exec_sql(acl_strdup((yyvsp[(1) - (1)].str))); }
    break;

  case 582:

/* Line 1455 of yacc.c  */
#line 3277 "sql.yacc"
    { sprintf((yyval.str),"%s %s",(yyvsp[(1) - (2)].str),(yyvsp[(2) - (2)].str)); print_exec_sql(acl_strdup((yyval.str))); }
    break;

  case 583:

/* Line 1455 of yacc.c  */
#line 3278 "sql.yacc"
    { print_exec_sql(acl_strdup((yyvsp[(1) - (1)].str))); }
    break;

  case 584:

/* Line 1455 of yacc.c  */
#line 3279 "sql.yacc"
    { print_exec_sql(acl_strdup((yyvsp[(1) - (1)].str))); }
    break;

  case 585:

/* Line 1455 of yacc.c  */
#line 3280 "sql.yacc"
    { print_exec_sql(acl_strdup((yyvsp[(1) - (1)].str))); }
    break;

  case 586:

/* Line 1455 of yacc.c  */
#line 3281 "sql.yacc"
    { print_exec_sql(acl_strdup((yyvsp[(1) - (1)].str))); }
    break;

  case 587:

/* Line 1455 of yacc.c  */
#line 3282 "sql.yacc"
    { print_exec_sql(acl_strdup((yyvsp[(1) - (1)].str))); }
    break;

  case 588:

/* Line 1455 of yacc.c  */
#line 3286 "sql.yacc"
    { 
	char *s;
	s=acl_strdup((yyvsp[(1) - (1)].str));
	(yyval.s_select_list_item)=new_select_list_item_column_from_transform(s);
	acl_free(s);
	}
    break;

  case 589:

/* Line 1455 of yacc.c  */
#line 3292 "sql.yacc"
    {  
		(yyval.s_select_list_item)=new_select_list_item_builtin_const(E_SLI_QUERY_PLACEHOLDER);}
    break;

  case 590:

/* Line 1455 of yacc.c  */
#line 3294 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_replace_var((yyvsp[(1) - (1)].sql_string));
	}
    break;

  case 591:

/* Line 1455 of yacc.c  */
#line 3313 "sql.yacc"
    {
        add_feature("DATABASE_USED");
       conn_db((yyvsp[(2) - (3)].str));
}
    break;

  case 592:

/* Line 1455 of yacc.c  */
#line 3321 "sql.yacc"
    {
		(yyval.sql_string)=acl_strdup((yyvsp[(2) - (3)].str));
}
    break;

  case 593:

/* Line 1455 of yacc.c  */
#line 3328 "sql.yacc"
    {sprintf((yyval.str),"(%s)",(yyvsp[(2) - (3)].str));}
    break;

  case 594:

/* Line 1455 of yacc.c  */
#line 3329 "sql.yacc"
    { sprintf((yyval.str),"%s%s%s",(yyvsp[(1) - (3)].str),(yyvsp[(2) - (3)].str),(yyvsp[(3) - (3)].str));}
    break;

  case 595:

/* Line 1455 of yacc.c  */
#line 3330 "sql.yacc"
    {sprintf((yyval.str),"%d",atoi((yyvsp[(1) - (1)].str)));}
    break;

  case 596:

/* Line 1455 of yacc.c  */
#line 3331 "sql.yacc"
    {sprintf((yyval.str),"(%s%s)",(yyvsp[(1) - (2)].str),(yyvsp[(2) - (2)].str));}
    break;

  case 597:

/* Line 1455 of yacc.c  */
#line 3336 "sql.yacc"
    {strcpy((yyval.str),"+");}
    break;

  case 598:

/* Line 1455 of yacc.c  */
#line 3337 "sql.yacc"
    {strcpy((yyval.str),"-");}
    break;

  case 599:

/* Line 1455 of yacc.c  */
#line 3338 "sql.yacc"
    {strcpy((yyval.str),"*");}
    break;

  case 600:

/* Line 1455 of yacc.c  */
#line 3339 "sql.yacc"
    {strcpy((yyval.str),"/");}
    break;

  case 601:

/* Line 1455 of yacc.c  */
#line 3340 "sql.yacc"
    {strcpy((yyval.str),"%");}
    break;

  case 602:

/* Line 1455 of yacc.c  */
#line 3345 "sql.yacc"
    {strcpy((yyval.str),"+");}
    break;

  case 603:

/* Line 1455 of yacc.c  */
#line 3346 "sql.yacc"
    {strcpy((yyval.str),"-");}
    break;

  case 604:

/* Line 1455 of yacc.c  */
#line 3362 "sql.yacc"
    {sprintf((yyval.str),"%s", A4GLSQLCV_check_tablename((yyvsp[(1) - (1)].str)));}
    break;

  case 605:

/* Line 1455 of yacc.c  */
#line 3363 "sql.yacc"
    {sprintf((yyval.str),"%s.*", A4GLSQLCV_ownerize_tablename(NULL,(yyvsp[(1) - (3)].str)));}
    break;

  case 606:

/* Line 1455 of yacc.c  */
#line 3364 "sql.yacc"
    {sprintf((yyval.str),"%s.%s", (yyvsp[(1) - (3)].str),A4GLSQLCV_get_sqlconst ("rowid"));}
    break;

  case 607:

/* Line 1455 of yacc.c  */
#line 3365 "sql.yacc"
    {sprintf((yyval.str),"%s.%s", A4GLSQLCV_ownerize_tablename(NULL,(yyvsp[(1) - (3)].str)),(yyvsp[(3) - (3)].str));}
    break;

  case 608:

/* Line 1455 of yacc.c  */
#line 3366 "sql.yacc"
    {sprintf((yyval.str),"%s.%s", A4GLSQLCV_ownerize_tablename((yyvsp[(1) - (5)].str),(yyvsp[(3) - (5)].str)),(yyvsp[(5) - (5)].str));}
    break;

  case 609:

/* Line 1455 of yacc.c  */
#line 3367 "sql.yacc"
    {sprintf((yyval.str),"%s.%s", A4GLSQLCV_ownerize_tablename((yyvsp[(1) - (5)].str),(yyvsp[(3) - (5)].str)),(yyvsp[(5) - (5)].str));}
    break;

  case 610:

/* Line 1455 of yacc.c  */
#line 3368 "sql.yacc"
    {sprintf((yyval.str),"%s", (yyvsp[(1) - (4)].str)); strcpy((yyval.str), A4GLSQLCV_make_substr_s((yyvsp[(1) - (4)].str), 1,(yyvsp[(3) - (4)].str),0));}
    break;

  case 611:

/* Line 1455 of yacc.c  */
#line 3369 "sql.yacc"
    {char buff[256]; sprintf(buff,"%s.%s", A4GLSQLCV_ownerize_tablename(NULL,(yyvsp[(1) - (6)].str)),(yyvsp[(3) - (6)].str)); strcpy((yyval.str), A4GLSQLCV_make_substr_s(buff,1,(yyvsp[(5) - (6)].str),0));}
    break;

  case 612:

/* Line 1455 of yacc.c  */
#line 3370 "sql.yacc"
    {char buff[256]; sprintf(buff,"%s.%s", A4GLSQLCV_ownerize_tablename((yyvsp[(1) - (8)].str),(yyvsp[(3) - (8)].str)), (yyvsp[(5) - (8)].str)); strcpy((yyval.str), A4GLSQLCV_make_substr_s(buff,1,(yyvsp[(7) - (8)].str),0));  }
    break;

  case 613:

/* Line 1455 of yacc.c  */
#line 3371 "sql.yacc"
    {char buff[256]; sprintf(buff,"%s.%s", A4GLSQLCV_ownerize_tablename((yyvsp[(1) - (8)].str),(yyvsp[(3) - (8)].str)), (yyvsp[(5) - (8)].str));  strcpy((yyval.str), A4GLSQLCV_make_substr_s(buff,1,(yyvsp[(7) - (8)].str),0)); }
    break;

  case 614:

/* Line 1455 of yacc.c  */
#line 3373 "sql.yacc"
    {sprintf((yyval.str),"%s", (yyvsp[(1) - (6)].str)); strcpy((yyval.str), A4GLSQLCV_make_substr_s((yyvsp[(1) - (6)].str), 2,(yyvsp[(3) - (6)].str),(yyvsp[(5) - (6)].str)));}
    break;

  case 615:

/* Line 1455 of yacc.c  */
#line 3374 "sql.yacc"
    {char buff[256]; sprintf(buff,"%s.%s", A4GLSQLCV_ownerize_tablename(NULL,(yyvsp[(1) - (8)].str)),(yyvsp[(3) - (8)].str)); strcpy((yyval.str), A4GLSQLCV_make_substr_s(buff,2,(yyvsp[(5) - (8)].str),(yyvsp[(7) - (8)].str)));}
    break;

  case 616:

/* Line 1455 of yacc.c  */
#line 3375 "sql.yacc"
    {char buff[256]; sprintf(buff,"%s.%s", A4GLSQLCV_ownerize_tablename((yyvsp[(1) - (10)].str),(yyvsp[(3) - (10)].str)), (yyvsp[(5) - (10)].str)); strcpy((yyval.str), A4GLSQLCV_make_substr_s(buff,2,(yyvsp[(7) - (10)].str),(yyvsp[(9) - (10)].str)));  }
    break;

  case 617:

/* Line 1455 of yacc.c  */
#line 3376 "sql.yacc"
    {char buff[256]; sprintf(buff,"%s.%s", A4GLSQLCV_ownerize_tablename((yyvsp[(1) - (10)].str),(yyvsp[(3) - (10)].str)), (yyvsp[(5) - (10)].str));  strcpy((yyval.str), A4GLSQLCV_make_substr_s(buff,2,(yyvsp[(7) - (10)].str),(yyvsp[(9) - (10)].str))); }
    break;

  case 618:

/* Line 1455 of yacc.c  */
#line 3381 "sql.yacc"
    {
                (yyval.s_select_list_item)=(yyvsp[(1) - (1)].s_select_list_item);
        }
    break;

  case 619:

/* Line 1455 of yacc.c  */
#line 3384 "sql.yacc"
    {
                (yyval.s_select_list_item)=new_select_list_item_cast((yyvsp[(1) - (3)].s_select_list_item), (yyvsp[(3) - (3)].str));
        }
    break;

  case 620:

/* Line 1455 of yacc.c  */
#line 3393 "sql.yacc"
    { (yyvsp[(1) - (1)].s_select_list_item)=(yyvsp[(1) - (1)].s_select_list_item); }
    break;

  case 621:

/* Line 1455 of yacc.c  */
#line 3394 "sql.yacc"
    {(yyvsp[(1) - (1)].s_select_list_item)=(yyvsp[(1) - (1)].s_select_list_item);}
    break;

  case 622:

/* Line 1455 of yacc.c  */
#line 3395 "sql.yacc"
    {  (yyval.s_select_list_item)=new_select_list_item_sq(E_SQE_DONT_CARE,(yyvsp[(1) - (1)].s_select_list_item)); }
    break;

  case 623:

/* Line 1455 of yacc.c  */
#line 3396 "sql.yacc"
    { (yyval.s_select_list_item)=new_select_list_item_sq(E_SQE_ALL,(yyvsp[(2) - (2)].s_select_list_item)); }
    break;

  case 624:

/* Line 1455 of yacc.c  */
#line 3397 "sql.yacc"
    { (yyval.s_select_list_item)=new_select_list_item_sq(E_SQE_ANY,(yyvsp[(2) - (2)].s_select_list_item)); }
    break;

  case 625:

/* Line 1455 of yacc.c  */
#line 3398 "sql.yacc"
    { (yyval.s_select_list_item)=new_select_list_item_sq(E_SQE_SOME,(yyvsp[(2) - (2)].s_select_list_item)); }
    break;

  case 626:

/* Line 1455 of yacc.c  */
#line 3402 "sql.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 627:

/* Line 1455 of yacc.c  */
#line 3403 "sql.yacc"
    {strcpy((yyval.str),(yyvsp[(1) - (1)].str));}
    break;



/* Line 1455 of yacc.c  */
#line 8875 "y.tab.c"
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
#line 3409 "sql.yacc"


#if LEX_YY_PREGEN
#include "../../tools/no_yacc/cygwin/compilers/sql/lex.sqlparse_yy.c"
#else
#include "lex.yy.c"
#endif
#include "util.c"
#include "cmds.c"

