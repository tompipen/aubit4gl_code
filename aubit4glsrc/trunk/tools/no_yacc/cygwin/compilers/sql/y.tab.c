
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
     INT_VALUE = 2209,
     NAMED = 2210,
     NAMED_GEN = 2211,
     CHAR_VALUE = 2212,
     NOT_USED_1 = 2213,
     NOT_USED_2 = 2214,
     NOT_USED_3 = 2215,
     NOT_USED_4 = 2216,
     NOT_USED_5 = 2217,
     NOT_USED_6 = 2218,
     NOT_USED_7 = 2219,
     NOT_USED_8 = 2220,
     NUMBER_VALUE = 2221,
     SEMICOLON = 2222,
     QUESTION_MARK = 2223,
     CLINE = 2224,
     CH = 2225,
     MARK_VAR = 2226,
     END_MARK_VAR = 2227,
     LEFT_JOIN = 1002,
     DISPLAY_NULL_TO = 1005,
     ON_CHANGE = 1006,
     INNER_JOIN = 1007,
     UI_INTERFACE_DOT_FRONTCALL = 1010,
     UIFORM = 1014,
     USING_BTREE = 1032,
     USING_RTREE = 1033,
     SET_BUFFERED_LOG = 1058,
     SET_LOG = 1061,
     MDY = 1063,
     WEEKDAY = 1064,
     MODE_ANSI = 1067,
     START_DATABASE = 1068,
     WITH_LOG_IN = 1069,
     SET_CONSTRAINTS_ALL_IMMEDIATE = 1070,
     DATETIME_VALUE = 1083,
     INTERVAL_VALUE = 1084,
     RECOVER_TABLE = 1085,
     ROLLFORWARD_DATABASE = 1086,
     DROP_TRIGGER = 1102,
     DROP_AUDIT_FOR = 1103,
     CREATE_AUDIT_FOR = 1104,
     EXECUTE_PROCEDURE = 1108,
     ALTER_TABLE = 1115,
     ALTER_INDEX = 1116,
     NEXT_SIZE = 1117,
     XSET_MULTIPLY_EQUAL_OPEN_BRACKET = 1154,
     XSET_ident_DOT_MULTIPLY_EQUAL_OPEN_BRACKET = 1155,
     XSET_ident_DOT_MULTIPLY_EQUAL = 1156,
     XSET_MULTIPLY_EQUAL = 1157,
     XSET_OPEN_BRACKET = 1158,
     CREATE_DATABASE = 1161,
     DROP_DATABASE = 1162,
     ADD_CONSTRAINT = 1164,
     DROP_CONSTRAINT = 1165,
     DROP_SYNONYM = 1166,
     CONSTRAINT = 1167,
     NOT_FIELD_TOUCHED_CURRENT = 1170,
     FIELD_TOUCHED_CURRENT = 1171,
     DOUBLE_PRECISION = 1178,
     COUNT_MULTIPLY = 1179,
     MODIFY_NEXT_SIZE = 1199,
     LOCK_MODE_PAGE = 1200,
     LOCK_MODE_ROW = 1201,
     UNITS_YEAR = 1208,
     UNITS_MONTH = 1209,
     UNITS_DAY = 1210,
     UNITS_HOUR = 1211,
     UNITS_MINUTE = 1212,
     UNITS_SECOND = 1213,
     TO_CLUSTER = 1218,
     TO_NOT_CLUSTER = 1219,
     CREATE_UC_IDX = 1221,
     CREATE_U_IDX = 1222,
     CREATE_C_IDX = 1223,
     CREATE_IDX = 1224,
     DOUBLE_COLON = 1234,
     SQLSICS = 1240,
     CREATE_SCHEMA = 1241,
     SQLSIRR = 1242,
     UPDATESTATS_T = 1243,
     SQLSICR = 1244,
     SQLSIDR = 1255,
     CREATE_TEMP_TABLE = 1256,
     WITH_CHECK_OPTION = 1264,
     WITH_GRANT_OPTION = 1265,
     SQLSLMNW = 1266,
     WHERE_CURRENT_OF = 1272,
     NOT_NULL_UNIQUE = 1280,
     SQLSLMW = 1287,
     ALL_PRIVILEGES = 1289,
     CREATE_SYNONYM = 1293,
     DROP_TABLE = 1294,
     INEXCLUSIVE = 1296,
     UPDATESTATS = 1301,
     CREATE_TABLE = 1327,
     DEFAULT_NULL = 1328,
     DEFAULT_TODAY = 1329,
     DEFAULT_USER = 1330,
     UNLOCK_TABLE = 1343,
     ROLLBACK_W = 1351,
     SQLSEON = 1353,
     SQLSEOFF = 1354,
     CREATE_VIEW = 1358,
     DELETE_FROM = 1359,
     EXTENT_SIZE = 1366,
     FOREIGN_KEY = 1367,
     INSERT_INTO = 1370,
     IS_NOT_NULL = 1372,
     NOT_MATCHES = 1375,
     PRIMARY_KEY = 1381,
     USE_SESSION = 1388,
     WITH_NO_LOG = 1389,
     INSHARE = 1392,
     BEGIN_WORK = 1398,
     DROP_INDEX = 1403,
     FOR_UPDATE_OF = 1409,
     FOR_UPDATE = 1410,
     LOCK_TABLE = 1415,
     NOT_EXISTS = 1417,
     REFERENCES = 1419,
     RENCOL = 1420,
     SMALLFLOAT = 1422,
     COMMIT_W = 1433,
     RENTAB = 1440,
     KW_CHAR = 1443,
     NCHAR = 1444,
     NVARCHAR = 1445,
     DELIMITER = 1447,
     DROP_VIEW = 1449,
     EXCLUSIVE = 1452,
     GREATER_THAN_EQ = 1456,
     INTO_TEMP = 1458,
     DATABASE = 1482,
     DATETIME = 1483,
     DISTINCT = 1485,
     FRACTION = 1492,
     GROUP_BY = 1494,
     INTERVAL = 1495,
     NOT_LIKE = 1497,
     NOT_ILIKE = 1498,
     NOT_NULL = 1499,
     RESOURCE = 1505,
     SMALLINT = 1506,
     IS_NULL = 1512,
     LESS_THAN_EQ = 1513,
     BETWEEN = 1515,
     CLOSE_BRACKET = 1518,
     CONNECT = 1521,
     KW_CURRENT = 1522,
     KW_DECIMAL = 1524,
     DEFAULT = 1526,
     INTEGER = 1534,
     SERIAL8 = 1536,
     MATCHES = 1539,
     VARCHAR = 1552,
     CLOSE_SQUARE = 1555,
     GREATER_THAN = 1556,
     KW_FALSE = 1557,
     NOT_IN = 1558,
     OPEN_BRACKET = 1560,
     KW_DELETE = 1568,
     KW_ESCAPE = 1571,
     EXISTS = 1572,
     EXTEND = 1573,
     HAVING = 1577,
     KW_INSERT = 1579,
     MINUTE = 1583,
     MODIFY = 1584,
     EQUAL = 1586,
     NOT_EQUAL = 1587,
     OPEN_SQUARE = 1589,
     PUBLIC = 1593,
     REVOKE = 1597,
     SECOND = 1601,
     KW_SELECT = 1605,
     SERIAL = 1606,
     UNIQUE = 1609,
     KW_UPDATE = 1611,
     VALUES = 1612,
     KW_NULL = 1615,
     KW_TRUE = 1616,
     ALTER = 1618,
     CHECK = 1624,
     COUNT = 1628,
     KW_FIRST = 1633,
     KW_FLOAT = 1634,
     GRANT = 1637,
     INDEX = 1640,
     LESS_THAN = 1643,
     MONEY = 1645,
     MONTH = 1646,
     KW_MULTIPLY = 1648,
     ORDER = 1649,
     OUTER = 1650,
     UNION = 1659,
     WHERE = 1662,
     KW_BYTE = 1669,
     CASE = 1671,
     KW_DATE = 1673,
     DESC = 1674,
     KW_DIVIDE = 1675,
     DROP = 1678,
     ELSE = 1679,
     FROM = 1683,
     HOUR = 1689,
     INTO = 1690,
     LIKE = 1693,
     REAL = 1702,
     SOME = 1707,
     KW_TEXT = 1711,
     KW_THEN = 1712,
     USER = 1713,
     WHEN = 1715,
     YEAR = 1718,
     KW_DOW = 1719,
     XSET = 1721,
     ADD = 1722,
     ALL = 1723,
     KW_AND = 1724,
     ANY = 1725,
     ASC = 1726,
     AVG = 1727,
     COLON = 1728,
     KW_COMMA = 1729,
     DAY = 1730,
     DBA = 1731,
     KW_FOR = 1735,
     XMAX = 1740,
     XMIN = 1741,
     KW_MINUS = 1742,
     KW_MOD = 1743,
     KW_NOT = 1744,
     KW_SUM = 1751,
     ATSIGN = 1754,
     KW_PLUS = 1755,
     KW_AS = 1761,
     KW_BY = 1763,
     KW_DOT = 1764,
     KW_IN = 1767,
     KW_ON = 1769,
     KW_OR = 1770,
     KW_TO = 1771,
     BEFORE = 1809,
     END = 1813,
     TILDE = 1820,
     ILIKE = 1821,
     FILLFACTOR = 1824,
     TIME = 1829,
     KW_TODAY = 1836,
     KW_ROWID = 1837,
     TIMESTAMP = 2185,
     KW_TAG = 2206,
     LINTMODULEISLIBRARY = 2207
   };
#endif
/* Tokens.  */
#define INT_VALUE 2209
#define NAMED 2210
#define NAMED_GEN 2211
#define CHAR_VALUE 2212
#define NOT_USED_1 2213
#define NOT_USED_2 2214
#define NOT_USED_3 2215
#define NOT_USED_4 2216
#define NOT_USED_5 2217
#define NOT_USED_6 2218
#define NOT_USED_7 2219
#define NOT_USED_8 2220
#define NUMBER_VALUE 2221
#define SEMICOLON 2222
#define QUESTION_MARK 2223
#define CLINE 2224
#define CH 2225
#define MARK_VAR 2226
#define END_MARK_VAR 2227
#define LEFT_JOIN 1002
#define DISPLAY_NULL_TO 1005
#define ON_CHANGE 1006
#define INNER_JOIN 1007
#define UI_INTERFACE_DOT_FRONTCALL 1010
#define UIFORM 1014
#define USING_BTREE 1032
#define USING_RTREE 1033
#define SET_BUFFERED_LOG 1058
#define SET_LOG 1061
#define MDY 1063
#define WEEKDAY 1064
#define MODE_ANSI 1067
#define START_DATABASE 1068
#define WITH_LOG_IN 1069
#define SET_CONSTRAINTS_ALL_IMMEDIATE 1070
#define DATETIME_VALUE 1083
#define INTERVAL_VALUE 1084
#define RECOVER_TABLE 1085
#define ROLLFORWARD_DATABASE 1086
#define DROP_TRIGGER 1102
#define DROP_AUDIT_FOR 1103
#define CREATE_AUDIT_FOR 1104
#define EXECUTE_PROCEDURE 1108
#define ALTER_TABLE 1115
#define ALTER_INDEX 1116
#define NEXT_SIZE 1117
#define XSET_MULTIPLY_EQUAL_OPEN_BRACKET 1154
#define XSET_ident_DOT_MULTIPLY_EQUAL_OPEN_BRACKET 1155
#define XSET_ident_DOT_MULTIPLY_EQUAL 1156
#define XSET_MULTIPLY_EQUAL 1157
#define XSET_OPEN_BRACKET 1158
#define CREATE_DATABASE 1161
#define DROP_DATABASE 1162
#define ADD_CONSTRAINT 1164
#define DROP_CONSTRAINT 1165
#define DROP_SYNONYM 1166
#define CONSTRAINT 1167
#define NOT_FIELD_TOUCHED_CURRENT 1170
#define FIELD_TOUCHED_CURRENT 1171
#define DOUBLE_PRECISION 1178
#define COUNT_MULTIPLY 1179
#define MODIFY_NEXT_SIZE 1199
#define LOCK_MODE_PAGE 1200
#define LOCK_MODE_ROW 1201
#define UNITS_YEAR 1208
#define UNITS_MONTH 1209
#define UNITS_DAY 1210
#define UNITS_HOUR 1211
#define UNITS_MINUTE 1212
#define UNITS_SECOND 1213
#define TO_CLUSTER 1218
#define TO_NOT_CLUSTER 1219
#define CREATE_UC_IDX 1221
#define CREATE_U_IDX 1222
#define CREATE_C_IDX 1223
#define CREATE_IDX 1224
#define DOUBLE_COLON 1234
#define SQLSICS 1240
#define CREATE_SCHEMA 1241
#define SQLSIRR 1242
#define UPDATESTATS_T 1243
#define SQLSICR 1244
#define SQLSIDR 1255
#define CREATE_TEMP_TABLE 1256
#define WITH_CHECK_OPTION 1264
#define WITH_GRANT_OPTION 1265
#define SQLSLMNW 1266
#define WHERE_CURRENT_OF 1272
#define NOT_NULL_UNIQUE 1280
#define SQLSLMW 1287
#define ALL_PRIVILEGES 1289
#define CREATE_SYNONYM 1293
#define DROP_TABLE 1294
#define INEXCLUSIVE 1296
#define UPDATESTATS 1301
#define CREATE_TABLE 1327
#define DEFAULT_NULL 1328
#define DEFAULT_TODAY 1329
#define DEFAULT_USER 1330
#define UNLOCK_TABLE 1343
#define ROLLBACK_W 1351
#define SQLSEON 1353
#define SQLSEOFF 1354
#define CREATE_VIEW 1358
#define DELETE_FROM 1359
#define EXTENT_SIZE 1366
#define FOREIGN_KEY 1367
#define INSERT_INTO 1370
#define IS_NOT_NULL 1372
#define NOT_MATCHES 1375
#define PRIMARY_KEY 1381
#define USE_SESSION 1388
#define WITH_NO_LOG 1389
#define INSHARE 1392
#define BEGIN_WORK 1398
#define DROP_INDEX 1403
#define FOR_UPDATE_OF 1409
#define FOR_UPDATE 1410
#define LOCK_TABLE 1415
#define NOT_EXISTS 1417
#define REFERENCES 1419
#define RENCOL 1420
#define SMALLFLOAT 1422
#define COMMIT_W 1433
#define RENTAB 1440
#define KW_CHAR 1443
#define NCHAR 1444
#define NVARCHAR 1445
#define DELIMITER 1447
#define DROP_VIEW 1449
#define EXCLUSIVE 1452
#define GREATER_THAN_EQ 1456
#define INTO_TEMP 1458
#define DATABASE 1482
#define DATETIME 1483
#define DISTINCT 1485
#define FRACTION 1492
#define GROUP_BY 1494
#define INTERVAL 1495
#define NOT_LIKE 1497
#define NOT_ILIKE 1498
#define NOT_NULL 1499
#define RESOURCE 1505
#define SMALLINT 1506
#define IS_NULL 1512
#define LESS_THAN_EQ 1513
#define BETWEEN 1515
#define CLOSE_BRACKET 1518
#define CONNECT 1521
#define KW_CURRENT 1522
#define KW_DECIMAL 1524
#define DEFAULT 1526
#define INTEGER 1534
#define SERIAL8 1536
#define MATCHES 1539
#define VARCHAR 1552
#define CLOSE_SQUARE 1555
#define GREATER_THAN 1556
#define KW_FALSE 1557
#define NOT_IN 1558
#define OPEN_BRACKET 1560
#define KW_DELETE 1568
#define KW_ESCAPE 1571
#define EXISTS 1572
#define EXTEND 1573
#define HAVING 1577
#define KW_INSERT 1579
#define MINUTE 1583
#define MODIFY 1584
#define EQUAL 1586
#define NOT_EQUAL 1587
#define OPEN_SQUARE 1589
#define PUBLIC 1593
#define REVOKE 1597
#define SECOND 1601
#define KW_SELECT 1605
#define SERIAL 1606
#define UNIQUE 1609
#define KW_UPDATE 1611
#define VALUES 1612
#define KW_NULL 1615
#define KW_TRUE 1616
#define ALTER 1618
#define CHECK 1624
#define COUNT 1628
#define KW_FIRST 1633
#define KW_FLOAT 1634
#define GRANT 1637
#define INDEX 1640
#define LESS_THAN 1643
#define MONEY 1645
#define MONTH 1646
#define KW_MULTIPLY 1648
#define ORDER 1649
#define OUTER 1650
#define UNION 1659
#define WHERE 1662
#define KW_BYTE 1669
#define CASE 1671
#define KW_DATE 1673
#define DESC 1674
#define KW_DIVIDE 1675
#define DROP 1678
#define ELSE 1679
#define FROM 1683
#define HOUR 1689
#define INTO 1690
#define LIKE 1693
#define REAL 1702
#define SOME 1707
#define KW_TEXT 1711
#define KW_THEN 1712
#define USER 1713
#define WHEN 1715
#define YEAR 1718
#define KW_DOW 1719
#define XSET 1721
#define ADD 1722
#define ALL 1723
#define KW_AND 1724
#define ANY 1725
#define ASC 1726
#define AVG 1727
#define COLON 1728
#define KW_COMMA 1729
#define DAY 1730
#define DBA 1731
#define KW_FOR 1735
#define XMAX 1740
#define XMIN 1741
#define KW_MINUS 1742
#define KW_MOD 1743
#define KW_NOT 1744
#define KW_SUM 1751
#define ATSIGN 1754
#define KW_PLUS 1755
#define KW_AS 1761
#define KW_BY 1763
#define KW_DOT 1764
#define KW_IN 1767
#define KW_ON 1769
#define KW_OR 1770
#define KW_TO 1771
#define BEFORE 1809
#define END 1813
#define TILDE 1820
#define ILIKE 1821
#define FILLFACTOR 1824
#define TIME 1829
#define KW_TODAY 1836
#define KW_ROWID 1837
#define TIMESTAMP 2185
#define KW_TAG 2206
#define LINTMODULEISLIBRARY 2207




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
#line 772 "y.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 784 "y.tab.c"

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
#define YYFINAL  158
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   2617

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  257
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  227
/* YYNRULES -- Number of rules.  */
#define YYNRULES  630
/* YYNRULES -- Number of states.  */
#define YYNSTATES  1122

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   2227

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
       2,     2,    22,     2,     2,    23,    24,    25,     2,     2,
      26,     2,     2,     2,    27,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,    28,    29,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    30,     2,
       2,    31,     2,    32,    33,     2,     2,    34,    35,    36,
      37,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    38,    39,    40,    41,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,    42,    43,    44,     2,     2,     2,    45,     2,
       2,     2,     2,     2,     2,    46,    47,    48,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,    49,    50,    51,    52,    53,     2,
       2,    54,    55,     2,    56,    57,    58,    59,     2,     2,
      60,    61,     2,     2,     2,     2,     2,     2,    62,    63,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    64,
      65,    66,     2,     2,     2,     2,     2,     2,    67,    68,
      69,    70,    71,    72,     2,     2,     2,     2,    73,    74,
       2,    75,    76,    77,    78,     2,     2,     2,     2,     2,
       2,     2,     2,     2,    79,     2,     2,     2,     2,     2,
      80,    81,    82,    83,    84,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,    85,    86,     2,     2,     2,
       2,     2,     2,     2,    87,    88,    89,     2,     2,     2,
       2,     2,    90,     2,     2,     2,     2,     2,     2,     2,
      91,     2,     2,     2,     2,     2,     2,    92,     2,    93,
       2,     2,     2,    94,    95,     2,    96,     2,     2,     2,
       2,    97,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,    98,    99,   100,
     101,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   102,     2,     2,     2,     2,     2,     2,
       2,   103,     2,   104,   105,     2,     2,     2,   106,   107,
       2,     2,     2,     2,     2,     2,   108,   109,     2,     2,
     110,     2,   111,     2,     2,   112,     2,     2,     2,     2,
       2,   113,     2,     2,     2,     2,     2,     2,   114,   115,
       2,     2,   116,     2,     2,     2,     2,     2,   117,     2,
       2,     2,     2,   118,     2,     2,     2,     2,     2,   119,
     120,     2,     2,     2,     2,   121,     2,   122,     2,   123,
     124,     2,   125,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   126,     2,     2,     2,     2,     2,     2,
     127,     2,     2,   128,   129,   130,     2,   131,     2,   132,
       2,     2,   133,     2,     2,     2,   134,     2,   135,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,   136,   137,     2,   138,     2,     2,     2,     2,
       2,     2,   139,     2,   140,   141,     2,   142,   143,   144,
       2,     2,     2,     2,     2,   145,   146,     2,     2,     2,
       2,     2,   147,   148,     2,   149,     2,     2,   150,     2,
       2,   151,   152,     2,   153,     2,   154,     2,     2,     2,
       2,     2,     2,     2,   155,     2,   156,     2,     2,   157,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,   158,     2,     2,   159,   160,   161,   162,     2,
     163,     2,     2,     2,     2,     2,     2,     2,   164,     2,
       2,   165,   166,   167,     2,     2,     2,   168,     2,   169,
       2,     2,     2,   170,   171,     2,   172,   173,     2,   174,
       2,     2,     2,   175,     2,     2,     2,   176,     2,     2,
       2,   177,     2,     2,     2,   178,   179,     2,     2,   180,
       2,   181,   182,     2,     2,   183,   184,     2,   185,     2,
       2,     2,     2,     2,   186,     2,     2,     2,   187,     2,
       2,     2,     2,   188,   189,     2,     2,   190,     2,     2,
     191,     2,     2,   192,     2,   193,   194,     2,   195,   196,
     197,     2,     2,     2,     2,     2,     2,     2,     2,   198,
       2,     2,   199,     2,     2,     2,     2,     2,     2,   200,
       2,   201,     2,   202,   203,   204,     2,     2,   205,   206,
       2,     2,     2,   207,     2,     2,     2,     2,     2,   208,
     209,     2,     2,   210,     2,     2,     2,     2,     2,     2,
       2,     2,   211,     2,     2,     2,     2,   212,     2,     2,
       2,   213,   214,   215,     2,   216,     2,     2,   217,   218,
       2,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,     2,     2,     2,   230,     2,     2,     2,     2,
     231,   232,   233,   234,   235,     2,     2,     2,     2,     2,
       2,   236,     2,     2,   237,   238,     2,     2,     2,     2,
       2,   239,     2,   240,   241,     2,     2,   242,     2,   243,
     244,   245,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,   246,
       2,     2,     2,   247,     2,     2,     2,     2,     2,     2,
     248,   249,     2,     2,   250,     2,     2,     2,     2,   251,
       2,     2,     2,     2,     2,     2,   252,   253,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,   254,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,   255,   256,     2,     3,
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
    1157,  1159,  1161,  1163,  1165,  1167,  1172,  1177,  1183,  1185,
    1187,  1189,  1191,  1196,  1203,  1205,  1207,  1210,  1214,  1216,
    1218,  1220,  1225,  1227,  1229,  1237,  1242,  1244,  1247,  1251,
    1253,  1257,  1260,  1262,  1264,  1265,  1267,  1269,  1272,  1274,
    1278,  1280,  1282,  1284,  1286,  1288,  1293,  1295,  1300,  1301,
    1302,  1313,  1320,  1321,  1325,  1326,  1328,  1333,  1337,  1339,
    1345,  1353,  1354,  1357,  1358,  1360,  1362,  1364,  1366,  1370,
    1372,  1375,  1379,  1381,  1384,  1387,  1391,  1394,  1398,  1402,
    1406,  1408,  1410,  1412,  1414,  1416,  1418,  1420,  1422,  1424,
    1430,  1436,  1442,  1448,  1454,  1458,  1463,  1468,  1473,  1478,
    1483,  1488,  1493,  1498,  1502,  1507,  1509,  1511,  1515,  1517,
    1520,  1525,  1528,  1530,  1534,  1540,  1546,  1551,  1557,  1559,
    1561,  1563,  1565,  1567,  1569,  1575,  1579,  1585,  1589,  1591,
    1595,  1597,  1599,  1602,  1605,  1607,  1609,  1613,  1615,  1619,
    1625,  1629,  1635,  1643,  1645,  1649,  1653,  1655,  1657,  1661,
    1667,  1671,  1677,  1685,  1689,  1691,  1693,  1697,  1703,  1707,
    1713,  1721,  1723,  1725,  1727,  1730,  1732,  1734,  1735,  1737,
    1739,  1743,  1745,  1747,  1749,  1750,  1752,  1754,  1756,  1758,
    1760,  1762,  1764,  1767,  1769,  1771,  1772,  1774,  1777,  1779,
    1783,  1785,  1789,  1795,  1797,  1799,  1802,  1804,  1806,  1808,
    1810,  1812,  1814,  1816,  1818,  1822,  1826,  1830,  1834,  1836,
    1839,  1841,  1843,  1845,  1847,  1849,  1851,  1853,  1855,  1859,
    1863,  1867,  1873,  1879,  1884,  1891,  1900,  1909,  1916,  1925,
    1936,  1947,  1949,  1953,  1955,  1957,  1959,  1962,  1965,  1968,
    1969
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     464,     0,    -1,   181,   455,   261,   259,    -1,    -1,    90,
     459,    -1,   199,   370,    -1,    -1,    90,   459,    -1,   199,
     370,    -1,    53,   266,   150,   172,   163,   267,   150,    -1,
      49,   267,   150,    -1,    50,   267,   150,    -1,   219,   262,
      -1,    52,   267,    -1,    51,   267,    -1,   265,    -1,   262,
     227,   265,    -1,   264,    -1,   237,   264,    -1,   458,   396,
      -1,   458,   241,   458,   396,    -1,   458,   241,   458,   241,
     458,   396,    -1,   458,   241,   195,    -1,   263,   172,   268,
      -1,   263,    -1,   266,   227,   263,    -1,   268,    -1,   267,
     227,   268,    -1,   443,    -1,   183,    -1,   270,    -1,    95,
     455,    -1,   132,   455,    -1,   118,   457,    -1,    42,   458,
      -1,   281,    -1,   272,    -1,    98,   455,   163,   286,   150,
     273,    -1,    86,   455,   163,   286,   150,   282,   273,   282,
      -1,    -1,   274,    -1,   275,    -1,   274,   275,    -1,   242,
     276,    -1,   108,     3,    -1,    48,     3,    -1,    65,    -1,
      66,    -1,     4,    -1,    -1,   278,    -1,   279,    -1,   278,
     279,    -1,   242,   276,    -1,   250,     3,    -1,    28,    -1,
      29,    -1,   455,    -1,    76,   457,   243,   280,   163,   284,
     150,   277,    -1,    75,   457,   243,   280,   163,   284,   150,
     277,    -1,    77,   457,   243,   280,   163,   284,   150,   277,
      -1,    78,   457,   243,   280,   163,   284,   150,   277,    -1,
      54,   468,    -1,    55,   468,    -1,    94,   455,   230,   455,
      -1,    44,   455,   242,     6,    -1,    43,   455,    -1,    58,
     455,    -1,    40,   455,    -1,    41,   458,    -1,    -1,   115,
      -1,    -1,   115,    -1,   285,    -1,   284,   227,   285,    -1,
     458,   224,    -1,   458,   203,    -1,   458,    -1,   287,    -1,
     286,   227,   287,    -1,   350,    -1,   348,    -1,    46,   458,
     289,    -1,    47,   457,    73,    -1,    47,   457,    74,    -1,
     290,    -1,   289,   227,   290,    -1,   291,    -1,   294,    -1,
     297,    -1,   302,    -1,   305,    -1,   301,    -1,   300,    -1,
     220,   292,    -1,   220,   163,   293,   150,    -1,   287,    -1,
     287,   246,   458,    -1,   292,    -1,   293,   227,   292,    -1,
     205,   296,    -1,   205,   163,   295,   150,    -1,   296,    -1,
     295,   227,   296,    -1,   458,    -1,   171,   299,    -1,   171,
     163,   298,   150,    -1,   299,    -1,   298,   227,   299,    -1,
     287,    -1,    65,    -1,    66,    -1,    64,     3,    -1,    56,
     348,   304,    -1,    56,   163,   303,   150,    -1,   348,   304,
      -1,   303,   227,   348,   304,    -1,    -1,    59,   458,    -1,
      57,   306,    -1,    57,   163,   306,   150,    -1,   307,    -1,
     306,   227,   307,    -1,   458,    -1,   103,    -1,    -1,   110,
     310,   455,   313,   311,    -1,    -1,   182,   312,   163,   316,
     150,    -1,   437,    -1,    -1,   163,   314,   150,    -1,   315,
      -1,   314,   227,   315,    -1,   458,    -1,   458,   241,   458,
      -1,   317,    -1,   316,   227,   317,    -1,   443,    -1,   183,
      -1,   107,   455,   260,    -1,   117,    -1,   126,    -1,    -1,
     133,    -1,   323,    -1,    35,   458,    36,     6,    34,    -1,
      35,   458,    36,     6,    -1,    37,    -1,    30,    -1,    31,
      -1,    83,   458,    -1,    97,    -1,   320,    -1,   319,    -1,
     308,    -1,   322,    -1,   356,    -1,   360,    -1,   407,    -1,
     269,    -1,   271,    -1,   288,    -1,   190,   329,   243,   455,
     245,   334,   328,    -1,   176,   329,   243,   455,   207,   334,
      -1,   190,   327,   245,   334,    -1,   176,   327,   207,   334,
      -1,   151,    -1,   145,    -1,   229,    -1,    -1,    88,    -1,
     239,   395,    -1,    93,    -1,   221,    -1,   330,    -1,   331,
      -1,   330,   227,   331,    -1,   178,   332,    -1,   169,    -1,
     164,    -1,   181,   332,    -1,   185,    -1,   191,    -1,    -1,
     163,   333,   150,    -1,   397,    -1,   333,   227,   397,    -1,
     335,    -1,   334,   227,   335,    -1,   175,    -1,   395,    -1,
     106,   455,   337,   239,   428,   339,    -1,    -1,   163,   338,
     150,    -1,   397,    -1,   338,   227,   397,    -1,    -1,    87,
      -1,   186,   163,   427,   150,    -1,   109,   163,   343,   150,
     342,    -1,   123,   344,    -1,   345,    -1,   455,    -1,   455,
     163,   345,   150,    -1,   397,    -1,   345,   227,   397,    -1,
     180,   163,   347,   150,    -1,   138,   163,   347,   150,    -1,
     113,   163,   347,   150,    -1,   397,    -1,   347,   227,   397,
      -1,   346,    -1,   341,    -1,   340,    -1,   154,   402,    -1,
     101,    -1,   100,    -1,    99,    -1,   458,   386,   351,   352,
      -1,    -1,   349,    -1,    -1,   353,    -1,   354,    -1,   353,
     354,    -1,   355,   304,    -1,   144,    -1,    91,    -1,   180,
      -1,   138,    -1,   342,    -1,   186,   163,   427,   150,    -1,
     113,    -1,    81,   357,   359,    -1,   358,    -1,   395,    -1,
     360,    -1,   359,   360,    -1,   336,    -1,   326,    -1,   168,
     370,    -1,   199,   370,    -1,   207,   364,    -1,   366,    -1,
     364,   227,   366,    -1,   364,   227,   197,   366,    -1,   364,
     227,   197,   163,   364,   150,    -1,   364,    22,   365,   243,
     370,    -1,   364,    25,   365,   243,   370,    -1,   364,    -1,
     163,   364,   150,    -1,   455,    -1,   455,   401,    -1,   455,
     239,   401,    -1,    -1,   363,   368,    -1,   369,    -1,   362,
     369,    -1,    -1,   424,    -1,   424,   361,    -1,   361,    -1,
     371,    -1,   370,   244,   371,    -1,   372,    -1,   371,   222,
     372,    -1,   373,    -1,   235,   373,    -1,   383,    -1,   163,
     370,   150,    -1,   166,   438,    -1,   122,   438,    -1,    -1,
     165,   379,    -1,    -1,   165,   379,    -1,    -1,   165,   379,
      -1,   481,    -1,   402,    -1,    -1,   235,    -1,   443,   380,
     147,    -1,   443,   380,   111,    -1,   443,   382,   443,    -1,
     443,   172,   443,    -1,   443,   172,   183,    -1,   443,   380,
     149,   443,   222,   443,    -1,   443,   210,   378,   377,    -1,
     443,   142,   378,   377,    -1,   443,   249,   378,   376,    -1,
     443,   143,   378,   376,    -1,   443,   157,   378,   375,    -1,
     443,   112,   378,   375,    -1,   173,    -1,   192,    -1,   160,
      -1,   248,    -1,   148,    -1,   134,    -1,   381,    -1,   450,
      -1,   374,    -1,   443,    -1,    -1,   221,    -1,   138,    -1,
     180,    -1,    -1,   221,    -1,   138,    -1,   180,    -1,   387,
      -1,   388,    -1,   389,    -1,   391,    -1,   128,    -1,   128,
     163,   392,   150,    -1,   179,    -1,   179,   163,     3,   150,
      -1,   156,    -1,   156,   163,     3,   150,    -1,   153,    -1,
     153,   163,   393,   390,   150,    -1,   193,   163,   393,   390,
     150,    -1,   193,    -1,   202,    -1,   155,    -1,   146,    -1,
     129,    -1,   129,   163,   392,   150,    -1,   130,    -1,   130,
     163,     3,   150,    -1,   130,   163,     3,   227,     3,   150,
      -1,   137,   404,   245,   405,    -1,   137,    -1,   141,   404,
     245,   405,    -1,   429,    -1,   141,    -1,   141,   404,   163,
       3,   150,   245,   405,    -1,   213,    -1,   200,    -1,   158,
      -1,   158,   163,     3,   150,    -1,   158,   163,     3,   227,
       3,   150,    -1,    -1,   227,   394,    -1,   189,   163,   393,
     150,    -1,   211,    -1,   125,    -1,   189,    -1,    62,    -1,
       3,    -1,     3,    -1,     3,    -1,   458,    -1,     6,    -1,
      -1,   174,     3,   159,    -1,   174,     3,   227,     3,   159,
      -1,   400,    -1,   237,   400,    -1,   399,    -1,   237,   399,
      -1,   458,   396,    -1,   453,   241,   458,   396,    -1,   453,
     241,   195,    -1,   253,    -1,   458,   396,    -1,   453,   241,
     458,   396,    -1,   458,   241,   458,   241,   458,   396,    -1,
     453,   241,   195,    -1,   458,    -1,     6,    -1,   460,    -1,
       3,    -1,   418,    -1,    -1,   404,   245,   405,    -1,   217,
      -1,   194,    -1,   228,    -1,   208,    -1,   170,    -1,   177,
      -1,   139,    -1,   217,    -1,   194,    -1,   228,    -1,   208,
      -1,   170,    -1,   177,    -1,   139,    -1,   139,   163,     3,
     150,    -1,    45,   458,   163,   150,    -1,    45,   458,   163,
     447,   150,    -1,   412,    -1,   411,    -1,   408,    -1,   406,
      -1,   127,   409,   245,   409,    -1,   124,   453,   241,   410,
     245,   410,    -1,   458,    -1,   458,    -1,   102,   455,    -1,
     121,   455,   413,    -1,   116,    -1,    96,    -1,   415,    -1,
     415,   404,   245,   405,    -1,    38,    -1,   417,    -1,   417,
     404,   163,     3,   150,   245,   405,    -1,   417,   404,   245,
     405,    -1,    39,    -1,   152,   403,    -1,   196,   240,   420,
      -1,   421,    -1,   420,   227,   421,    -1,   422,   423,    -1,
       3,    -1,   398,    -1,    -1,   224,    -1,   203,    -1,   140,
     425,    -1,   426,    -1,   425,   227,   426,    -1,   398,    -1,
       3,    -1,   370,    -1,   437,    -1,   251,    -1,   251,   163,
       3,   150,    -1,   254,    -1,   254,   163,     3,   150,    -1,
      -1,    -1,   178,   439,   440,   431,   441,   432,   462,   367,
     434,   435,    -1,   178,   439,   440,   441,   367,   434,    -1,
      -1,   198,   385,   433,    -1,    -1,   419,    -1,   419,   135,
     436,   283,    -1,   135,   436,   283,    -1,   458,    -1,   178,
     439,   440,   441,   367,    -1,   163,   178,   439,   440,   441,
     367,   150,    -1,    -1,   188,     3,    -1,    -1,   221,    -1,
     138,    -1,   180,    -1,   442,    -1,   441,   227,   442,    -1,
     443,    -1,   443,   458,    -1,   443,   239,   458,    -1,   481,
      -1,   233,   481,    -1,   238,   481,    -1,   481,   204,   443,
      -1,   481,   449,    -1,   481,   195,   443,    -1,   481,   238,
     443,    -1,   481,   233,   443,    -1,   402,    -1,   184,    -1,
     161,    -1,   215,    -1,   252,    -1,   253,    -1,   251,    -1,
     195,    -1,    63,    -1,   225,   163,   384,   443,   150,    -1,
     231,   163,   384,   443,   150,    -1,   232,   163,   384,   443,
     150,    -1,   236,   163,   384,   443,   150,    -1,   187,   163,
     384,   443,   150,    -1,     4,   163,   150,    -1,     4,   163,
     447,   150,    -1,   217,   163,   447,   150,    -1,   194,   163,
     447,   150,    -1,   228,   163,   447,   150,    -1,    32,   163,
     447,   150,    -1,    33,   163,   447,   150,    -1,   218,   163,
     447,   150,    -1,   202,   163,   447,   150,    -1,   163,   443,
     150,    -1,   167,   163,   448,   150,    -1,   414,    -1,   416,
      -1,   201,   445,   247,    -1,   446,    -1,   445,   446,    -1,
     216,   370,   214,   443,    -1,   206,   443,    -1,   443,    -1,
     447,   227,   443,    -1,   152,   227,   404,   245,   405,    -1,
     474,   227,   404,   245,   405,    -1,   152,   404,   245,   405,
      -1,   443,   227,   404,   245,   405,    -1,    67,    -1,    68,
      -1,    69,    -1,    70,    -1,    71,    -1,    72,    -1,   443,
     242,   163,   451,   150,    -1,   443,   242,   438,    -1,   443,
     162,   163,   451,   150,    -1,   443,   162,   438,    -1,   452,
      -1,   451,   227,   452,    -1,   474,    -1,   402,    -1,   233,
       3,    -1,   233,   460,    -1,   454,    -1,     6,    -1,     6,
     241,   458,    -1,   458,    -1,   458,   226,   458,    -1,   458,
     226,     6,   241,   458,    -1,   458,   237,   458,    -1,   458,
     237,   458,   226,   458,    -1,   458,   237,   458,   226,     6,
     241,   458,    -1,   456,    -1,     6,   241,   458,    -1,   458,
     241,   458,    -1,     6,    -1,   458,    -1,   458,   226,   458,
      -1,   458,   226,     6,   241,   458,    -1,   458,   237,   458,
      -1,   458,   237,   458,   226,   458,    -1,   458,   237,   458,
     226,     6,   241,   458,    -1,     6,   241,   458,    -1,     6,
      -1,   458,    -1,   458,   226,   458,    -1,   458,   226,     6,
     241,   458,    -1,   458,   237,   458,    -1,   458,   237,   458,
     226,   458,    -1,   458,   237,   458,   226,     6,   241,   458,
      -1,     4,    -1,     4,    -1,    15,    -1,   241,     3,    -1,
       4,    -1,     6,    -1,    -1,   458,    -1,   466,    -1,   464,
      16,   466,    -1,   309,    -1,   258,    -1,   318,    -1,    -1,
     475,    -1,   325,    -1,   467,    -1,   473,    -1,   465,    -1,
     324,    -1,     1,    -1,   469,   470,    -1,   463,    -1,   430,
      -1,    -1,   120,    -1,   119,   471,    -1,   472,    -1,   471,
     227,   472,    -1,   458,    -1,   458,   241,   458,    -1,     6,
     241,   458,   241,   458,    -1,   105,    -1,   104,    -1,    92,
     483,    -1,    89,    -1,    85,    -1,    82,    -1,    80,    -1,
      84,    -1,   480,    -1,    17,    -1,   476,    -1,   136,   461,
     321,    -1,    20,     6,    21,    -1,   163,   477,   150,    -1,
     477,   478,   477,    -1,     3,    -1,   479,     3,    -1,   238,
      -1,   233,    -1,   195,    -1,   204,    -1,   234,    -1,   238,
      -1,   233,    -1,   458,    -1,   458,   241,   195,    -1,   458,
     241,   253,    -1,   458,   241,   458,    -1,   458,   241,   458,
     241,   458,    -1,     6,   241,   458,   241,   458,    -1,   458,
     174,   477,   159,    -1,   458,   241,   458,   174,   477,   159,
      -1,   458,   241,   458,   241,   458,   174,   477,   159,    -1,
       6,   241,   458,   241,   458,   174,   477,   159,    -1,   458,
     174,   477,   227,   477,   159,    -1,   458,   241,   458,   174,
     477,   227,   477,   159,    -1,   458,   241,   458,   241,   458,
     174,   477,   227,   477,   159,    -1,     6,   241,   458,   241,
     458,   174,   477,   227,   477,   159,    -1,   482,    -1,   482,
      79,   386,    -1,   444,    -1,   474,    -1,   438,    -1,   221,
     438,    -1,   223,   438,    -1,   212,   438,    -1,    -1,     3,
      -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   406,   406,   432,   435,   452,   457,   460,   477,   483,
     492,   501,   510,   517,   532,   587,   594,   605,   608,   613,
     620,   637,   654,   675,   684,   687,   695,   698,   706,   707,
     714,   717,   725,   728,   732,   738,   739,   743,   753,   767,
     768,   772,   773,   778,   786,   794,   802,   810,   820,   822,
     822,   825,   826,   830,   837,   844,   851,   860,   864,   871,
     883,   894,   900,   904,   908,   913,   917,   920,   924,   927,
     934,   935,   945,   946,   950,   951,   955,   964,   973,   980,
     983,   989,   992,  1003,  1007,  1012,  1019,  1022,  1031,  1034,
    1038,  1042,  1046,  1050,  1054,  1062,  1066,  1074,  1077,  1084,
    1087,  1094,  1097,  1104,  1105,  1110,  1114,  1117,  1123,  1126,
    1132,  1139,  1140,  1144,  1152,  1156,  1163,  1165,  1170,  1171,
    1175,  1177,  1183,  1184,  1187,  1198,  1204,  1204,  1213,  1213,
    1222,  1247,  1250,  1258,  1261,  1268,  1271,  1279,  1280,  1286,
    1287,  1295,  1313,  1317,  1322,  1323,  1333,  1342,  1346,  1350,
    1355,  1359,  1363,  1366,  1373,  1374,  1375,  1379,  1380,  1381,
    1382,  1383,  1384,  1385,  1393,  1394,  1395,  1396,  1401,  1402,
    1403,  1406,  1407,  1408,  1412,  1413,  1414,  1418,  1419,  1423,
    1430,  1431,  1432,  1439,  1440,  1443,  1444,  1449,  1450,  1455,
    1456,  1461,  1462,  1467,  1474,  1475,  1480,  1481,  1485,  1486,
    1493,  1501,  1508,  1515,  1519,  1520,  1525,  1526,  1532,  1536,
    1541,  1548,  1549,  1555,  1558,  1561,  1568,  1569,  1570,  1571,
    1577,  1598,  1599,  1602,  1604,  1611,  1614,  1620,  1628,  1633,
    1639,  1644,  1650,  1653,  1658,  1666,  1675,  1680,  1684,  1685,
    1691,  1694,  1705,  1714,  1721,  1727,  1728,  1731,  1736,  1747,
    1751,  1758,  1759,  1763,  1767,  1771,  1778,  1783,  1791,  1794,
    1800,  1803,  1808,  1813,  1826,  1829,  1835,  1838,  1844,  1847,
    1853,  1856,  1863,  1867,  1878,  1878,  1879,  1879,  1880,  1880,
    1883,  1888,  1893,  1894,  1899,  1908,  1916,  1919,  1922,  1926,
    1933,  1936,  1940,  1943,  1946,  1949,  1955,  1962,  1965,  1968,
    1971,  1972,  1977,  1980,  1983,  1986,  1993,  1994,  1995,  1999,
    2006,  2007,  2008,  2012,  2026,  2033,  2034,  2035,  2039,  2040,
    2045,  2046,  2055,  2057,  2066,  2069,  2077,  2087,  2095,  2097,
    2098,  2099,  2100,  2101,  2102,  2103,  2111,  2112,  2113,  2114,
    2115,  2116,  2117,  2118,  2119,  2120,  2121,  2131,  2132,  2138,
    2140,  2141,  2142,  2143,  2147,  2151,  2155,  2162,  2163,  2168,
    2169,  2173,  2181,  2184,  2191,  2194,  2204,  2207,  2210,  2213,
    2220,  2227,  2235,  2244,  2251,  2255,  2256,  2257,  2258,  2263,
    2265,  2274,  2274,  2274,  2274,  2274,  2274,  2274,  2275,  2275,
    2275,  2275,  2275,  2275,  2275,  2275,  2290,  2298,  2310,  2311,
    2312,  2313,  2318,  2319,  2322,  2323,  2327,  2334,  2345,  2346,
    2359,  2360,  2364,  2368,  2369,  2372,  2378,  2382,  2405,  2415,
    2418,  2424,  2433,  2437,  2444,  2445,  2447,  2452,  2458,  2461,
    2467,  2468,  2475,  2488,  2498,  2505,  2522,  2529,  2554,  2556,
    2554,  2578,  2622,  2623,  2637,  2640,  2647,  2657,  2669,  2675,
    2688,  2703,  2705,  2711,  2712,  2713,  2714,  2724,  2727,  2733,
    2736,  2741,  2750,  2753,  2757,  2764,  2767,  2770,  2773,  2776,
    2779,  2780,  2781,  2782,  2783,  2784,  2785,  2786,  2787,  2789,
    2793,  2797,  2801,  2805,  2809,  2813,  2817,  2820,  2823,  2826,
    2829,  2832,  2835,  2838,  2841,  2845,  2849,  2853,  2861,  2864,
    2873,  2879,  2886,  2889,  2917,  2920,  2923,  2926,  2932,  2933,
    2934,  2935,  2936,  2937,  2942,  2946,  2950,  2954,  2961,  2964,
    2969,  2970,  2971,  2973,  2979,  2989,  2993,  2997,  3001,  3005,
    3009,  3013,  3017,  3025,  3035,  3040,  3044,  3048,  3052,  3056,
    3061,  3065,  3069,  3077,  3080,  3085,  3086,  3087,  3092,  3093,
    3094,  3102,  3105,  3110,  3111,  3115,  3116,  3121,  3145,  3162,
    3163,  3167,  3174,  3180,  3190,  3192,  3195,  3196,  3197,  3198,
    3200,  3203,  3207,  3212,  3216,  3222,  3223,  3226,  3231,  3232,
    3235,  3236,  3237,  3247,  3248,  3249,  3250,  3251,  3252,  3253,
    3254,  3258,  3264,  3266,  3285,  3293,  3300,  3301,  3302,  3303,
    3308,  3309,  3310,  3311,  3312,  3317,  3318,  3334,  3335,  3336,
    3337,  3338,  3339,  3340,  3341,  3342,  3343,  3345,  3346,  3347,
    3348,  3353,  3356,  3365,  3366,  3367,  3368,  3369,  3370,  3374,
    3375
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
  "LEFT_JOIN", "DISPLAY_NULL_TO", "ON_CHANGE", "INNER_JOIN",
  "UI_INTERFACE_DOT_FRONTCALL", "UIFORM", "USING_BTREE", "USING_RTREE",
  "SET_BUFFERED_LOG", "SET_LOG", "MDY", "WEEKDAY", "MODE_ANSI",
  "START_DATABASE", "WITH_LOG_IN", "SET_CONSTRAINTS_ALL_IMMEDIATE",
  "DATETIME_VALUE", "INTERVAL_VALUE", "RECOVER_TABLE",
  "ROLLFORWARD_DATABASE", "DROP_TRIGGER", "DROP_AUDIT_FOR",
  "CREATE_AUDIT_FOR", "EXECUTE_PROCEDURE", "ALTER_TABLE", "ALTER_INDEX",
  "NEXT_SIZE", "XSET_MULTIPLY_EQUAL_OPEN_BRACKET",
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
  "USE_SESSION", "WITH_NO_LOG", "INSHARE", "BEGIN_WORK", "DROP_INDEX",
  "FOR_UPDATE_OF", "FOR_UPDATE", "LOCK_TABLE", "NOT_EXISTS", "REFERENCES",
  "RENCOL", "SMALLFLOAT", "COMMIT_W", "RENTAB", "KW_CHAR", "NCHAR",
  "NVARCHAR", "DELIMITER", "DROP_VIEW", "EXCLUSIVE", "GREATER_THAN_EQ",
  "INTO_TEMP", "DATABASE", "DATETIME", "DISTINCT", "FRACTION", "GROUP_BY",
  "INTERVAL", "NOT_LIKE", "NOT_ILIKE", "NOT_NULL", "RESOURCE", "SMALLINT",
  "IS_NULL", "LESS_THAN_EQ", "BETWEEN", "CLOSE_BRACKET", "CONNECT",
  "KW_CURRENT", "KW_DECIMAL", "DEFAULT", "INTEGER", "SERIAL8", "MATCHES",
  "VARCHAR", "CLOSE_SQUARE", "GREATER_THAN", "KW_FALSE", "NOT_IN",
  "OPEN_BRACKET", "KW_DELETE", "KW_ESCAPE", "EXISTS", "EXTEND", "HAVING",
  "KW_INSERT", "MINUTE", "MODIFY", "EQUAL", "NOT_EQUAL", "OPEN_SQUARE",
  "PUBLIC", "REVOKE", "SECOND", "KW_SELECT", "SERIAL", "UNIQUE",
  "KW_UPDATE", "VALUES", "KW_NULL", "KW_TRUE", "ALTER", "CHECK", "COUNT",
  "KW_FIRST", "KW_FLOAT", "GRANT", "INDEX", "LESS_THAN", "MONEY", "MONTH",
  "KW_MULTIPLY", "ORDER", "OUTER", "UNION", "WHERE", "KW_BYTE", "CASE",
  "KW_DATE", "DESC", "KW_DIVIDE", "DROP", "ELSE", "FROM", "HOUR", "INTO",
  "LIKE", "REAL", "SOME", "KW_TEXT", "KW_THEN", "USER", "WHEN", "YEAR",
  "KW_DOW", "XSET", "ADD", "ALL", "KW_AND", "ANY", "ASC", "AVG", "COLON",
  "KW_COMMA", "DAY", "DBA", "KW_FOR", "XMAX", "XMIN", "KW_MINUS", "KW_MOD",
  "KW_NOT", "KW_SUM", "ATSIGN", "KW_PLUS", "KW_AS", "KW_BY", "KW_DOT",
  "KW_IN", "KW_ON", "KW_OR", "KW_TO", "BEFORE", "END", "TILDE", "ILIKE",
  "FILLFACTOR", "TIME", "KW_TODAY", "KW_ROWID", "TIMESTAMP", "KW_TAG",
  "LINTMODULEISLIBRARY", "$accept", "update_statement_c", "where_upd_p",
  "where_del_p", "set_clause_list_uc", "upd_columns_uc", "upd_column_name",
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
  "s_curr", "e_curr", "execute_procedure", "misc_sql", "rename_stmt",
  "rentabname", "rencolname", "unlock_stmt", "lock_stmt",
  "share_or_exclusive", "datetime_value_qualified", "datetime_value",
  "interval_value_qualified", "interval_value", "curr_clause",
  "order_by_clause_slil", "sort_specification_list_slil",
  "sort_specification_sli", "sort_spec_sli", "op_asc_desc",
  "group_by_clause_slil", "gr_column_specification_list_slil",
  "gr_column_specification_sli", "search_condition_sli_as_string",
  "query_specification_ss_converted", "sql_time_dtypes",
  "select_statement_ss_select", "$@3", "$@4", "union_select_statement2_ss",
  "sel_p2_select", "sel_finish_sf", "tmp_tabname",
  "query_specification_select", "subquery_sli", "op_first", "op_ad",
  "select_list_slil", "value_expression_pls_sli", "value_expression_sli",
  "value_expression_complex_sli", "sql_case_stmt", "sql_case_stmt_element",
  "value_expr_list_slil", "extend_qual_sli", "units_qual_i",
  "in_predicate_sli", "in_value_list_slil", "in_value_specification_sli",
  "table_name", "table_name_i", "table_name_not_for_column_prefix",
  "table_name_not_for_column_prefix_i", "idx_name", "identifier",
  "fetch_cursor_name_p", "real_number", "var_ident_qchar", "opt_into_sel",
  "var_ident", "sql_statement", "sql_bound_commands",
  "individual_sql_statement", "select_statement_ss_str_cfu",
  "var_ident_vl", "select_statement_ss_str_converted", "curs_forupdate",
  "cur_update_list", "colident", "set_cmd", "var_ident_ibind_sli",
  "set_database_cmd", "replace_with_variable", "arr_expr", "arr_next_math",
  "arr_int_sign", "column_name_x", "value_expression_initial_sli",
  "value_expression_initial_sli_nocast", "op_fgl_expr", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,  2208,  2209,  2210,  2211,  2212,  2213,  2214,  2215,
    2216,  2217,  2218,  2219,  2220,  2221,  2222,  2223,  2224,  2225,
    2226,  2227,  1002,  1005,  1006,  1007,  1010,  1014,  1032,  1033,
    1058,  1061,  1063,  1064,  1067,  1068,  1069,  1070,  1083,  1084,
    1085,  1086,  1102,  1103,  1104,  1108,  1115,  1116,  1117,  1154,
    1155,  1156,  1157,  1158,  1161,  1162,  1164,  1165,  1166,  1167,
    1170,  1171,  1178,  1179,  1199,  1200,  1201,  1208,  1209,  1210,
    1211,  1212,  1213,  1218,  1219,  1221,  1222,  1223,  1224,  1234,
    1240,  1241,  1242,  1243,  1244,  1255,  1256,  1264,  1265,  1266,
    1272,  1280,  1287,  1289,  1293,  1294,  1296,  1301,  1327,  1328,
    1329,  1330,  1343,  1351,  1353,  1354,  1358,  1359,  1366,  1367,
    1370,  1372,  1375,  1381,  1388,  1389,  1392,  1398,  1403,  1409,
    1410,  1415,  1417,  1419,  1420,  1422,  1433,  1440,  1443,  1444,
    1445,  1447,  1449,  1452,  1456,  1458,  1482,  1483,  1485,  1492,
    1494,  1495,  1497,  1498,  1499,  1505,  1506,  1512,  1513,  1515,
    1518,  1521,  1522,  1524,  1526,  1534,  1536,  1539,  1552,  1555,
    1556,  1557,  1558,  1560,  1568,  1571,  1572,  1573,  1577,  1579,
    1583,  1584,  1586,  1587,  1589,  1593,  1597,  1601,  1605,  1606,
    1609,  1611,  1612,  1615,  1616,  1618,  1624,  1628,  1633,  1634,
    1637,  1640,  1643,  1645,  1646,  1648,  1649,  1650,  1659,  1662,
    1669,  1671,  1673,  1674,  1675,  1678,  1679,  1683,  1689,  1690,
    1693,  1702,  1707,  1711,  1712,  1713,  1715,  1718,  1719,  1721,
    1722,  1723,  1724,  1725,  1726,  1727,  1728,  1729,  1730,  1731,
    1735,  1740,  1741,  1742,  1743,  1744,  1751,  1754,  1755,  1761,
    1763,  1764,  1767,  1769,  1770,  1771,  1809,  1813,  1820,  1821,
    1824,  1829,  1836,  1837,  2185,  2206,  2207
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint16 yyr1[] =
{
       0,   257,   258,   259,   259,   259,   260,   260,   260,   261,
     261,   261,   261,   261,   261,   262,   262,   263,   263,   264,
     264,   264,   264,   265,   266,   266,   267,   267,   268,   268,
     269,   270,   270,   270,   270,   271,   271,   272,   272,   273,
     273,   274,   274,   275,   275,   275,   275,   275,   276,   277,
     277,   278,   278,   279,   279,   279,   279,   280,   281,   281,
     281,   281,   281,   281,   281,   281,   281,   281,   281,   281,
     282,   282,   283,   283,   284,   284,   285,   285,   285,   286,
     286,   287,   287,   288,   288,   288,   289,   289,   290,   290,
     290,   290,   290,   290,   290,   291,   291,   292,   292,   293,
     293,   294,   294,   295,   295,   296,   297,   297,   298,   298,
     299,   300,   300,   301,   302,   302,   303,   303,   304,   304,
     305,   305,   306,   306,   307,   308,   310,   309,   312,   311,
     311,   313,   313,   314,   314,   315,   315,   316,   316,   317,
     317,   318,   319,   320,   321,   321,   322,   323,   323,   323,
     323,   323,   323,   323,   324,   324,   324,   325,   325,   325,
     325,   325,   325,   325,   326,   326,   326,   326,   327,   327,
     327,   328,   328,   328,   329,   329,   329,   330,   330,   331,
     331,   331,   331,   331,   331,   332,   332,   333,   333,   334,
     334,   335,   335,   336,   337,   337,   338,   338,   339,   339,
     340,   341,   342,   343,   344,   344,   345,   345,   346,   346,
     346,   347,   347,   348,   348,   348,   349,   349,   349,   349,
     350,   351,   351,   352,   352,   353,   353,   354,   355,   355,
     355,   355,   355,   355,   355,   356,   357,   358,   359,   359,
     360,   360,   361,   362,   363,   364,   364,   364,   364,   364,
     364,   365,   365,   366,   366,   366,   367,   367,   368,   368,
     369,   369,   369,   369,   370,   370,   371,   371,   372,   372,
     373,   373,   374,   374,   375,   375,   376,   376,   377,   377,
     378,   379,   380,   380,   381,   381,   381,   381,   381,   381,
     381,   381,   381,   381,   381,   381,   382,   382,   382,   382,
     382,   382,   383,   383,   383,   383,   384,   384,   384,   384,
     385,   385,   385,   385,   386,   387,   387,   387,   388,   388,
     389,   389,   389,   389,   389,   389,   389,   389,   389,   389,
     389,   389,   389,   389,   389,   389,   389,   389,   389,   389,
     389,   389,   389,   389,   389,   389,   389,   390,   390,   391,
     391,   391,   391,   391,   392,   393,   394,   395,   395,   396,
     396,   396,   397,   397,   398,   398,   399,   399,   399,   399,
     400,   400,   400,   400,   401,   402,   402,   402,   402,   403,
     403,   404,   404,   404,   404,   404,   404,   404,   405,   405,
     405,   405,   405,   405,   405,   405,   406,   406,   407,   407,
     407,   407,   408,   408,   409,   410,   411,   412,   413,   413,
     414,   414,   415,   416,   416,   416,   417,   418,   419,   420,
     420,   421,   422,   422,   423,   423,   423,   424,   425,   425,
     426,   426,   427,   428,   429,   429,   429,   429,   431,   432,
     430,   433,   434,   434,   435,   435,   435,   435,   436,   437,
     438,   439,   439,   440,   440,   440,   440,   441,   441,   442,
     442,   442,   443,   443,   443,   444,   444,   444,   444,   444,
     444,   444,   444,   444,   444,   444,   444,   444,   444,   444,
     444,   444,   444,   444,   444,   444,   444,   444,   444,   444,
     444,   444,   444,   444,   444,   444,   444,   444,   445,   445,
     446,   446,   447,   447,   448,   448,   448,   448,   449,   449,
     449,   449,   449,   449,   450,   450,   450,   450,   451,   451,
     452,   452,   452,   452,   453,   454,   454,   454,   454,   454,
     454,   454,   454,   455,   456,   456,   456,   456,   456,   456,
     456,   456,   456,   457,   457,   457,   457,   457,   457,   457,
     457,   458,   459,   460,   460,   461,   461,   462,   463,   464,
     464,   465,   465,   465,   466,   466,   466,   466,   466,   466,
     466,   466,   467,   468,   469,   470,   470,   470,   471,   471,
     472,   472,   472,   473,   473,   473,   473,   473,   473,   473,
     473,   474,   474,   474,   475,   476,   477,   477,   477,   477,
     478,   478,   478,   478,   478,   479,   479,   480,   480,   480,
     480,   480,   480,   480,   480,   480,   480,   480,   480,   480,
     480,   481,   481,   482,   482,   482,   482,   482,   482,   483,
     483
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
       1,     1,     1,     1,     1,     4,     4,     5,     1,     1,
       1,     1,     4,     6,     1,     1,     2,     3,     1,     1,
       1,     4,     1,     1,     7,     4,     1,     2,     3,     1,
       3,     2,     1,     1,     0,     1,     1,     2,     1,     3,
       1,     1,     1,     1,     1,     4,     1,     4,     0,     0,
      10,     6,     0,     3,     0,     1,     4,     3,     1,     5,
       7,     0,     2,     0,     1,     1,     1,     1,     3,     1,
       2,     3,     1,     2,     2,     3,     2,     3,     3,     3,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     5,
       5,     5,     5,     5,     3,     4,     4,     4,     4,     4,
       4,     4,     4,     3,     4,     1,     1,     3,     1,     2,
       4,     2,     1,     3,     5,     5,     4,     5,     1,     1,
       1,     1,     1,     1,     5,     3,     5,     3,     1,     3,
       1,     1,     2,     2,     1,     1,     3,     1,     3,     5,
       3,     5,     7,     1,     3,     3,     1,     1,     3,     5,
       3,     5,     7,     3,     1,     1,     3,     5,     3,     5,
       7,     1,     1,     1,     2,     1,     1,     0,     1,     1,
       3,     1,     1,     1,     0,     1,     1,     1,     1,     1,
       1,     1,     2,     1,     1,     0,     1,     2,     1,     3,
       1,     3,     5,     1,     1,     2,     1,     1,     1,     1,
       1,     1,     1,     1,     3,     3,     3,     3,     1,     2,
       1,     1,     1,     1,     1,     1,     1,     1,     3,     3,
       3,     5,     5,     4,     6,     8,     8,     6,     8,    10,
      10,     1,     3,     1,     1,     1,     2,     2,     2,     0,
       1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       0,   571,   150,   151,     0,   149,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   589,     0,   588,     0,   590,   587,     0,   586,   629,
       0,     0,   153,     0,     0,   125,   584,   583,     0,     0,
     126,   142,     0,     0,     0,   143,     0,     0,     0,     0,
     451,     0,     0,   562,   161,    30,   162,    36,    35,   163,
     156,   561,   563,   155,   154,   157,   146,   570,   566,   241,
     240,   158,   159,   401,   160,   400,   399,   398,   574,     0,
     569,   559,   567,   575,   568,   565,   551,     0,   536,    68,
     533,   537,    69,    34,    66,     0,     0,     0,   544,     0,
     545,   558,   573,    62,    63,    67,     0,     0,     0,     0,
     358,     0,   236,   237,   357,   152,     0,   630,   585,     0,
      31,     0,   406,   194,     6,     0,    33,     0,     0,     0,
     524,   527,     0,   404,    32,   555,   556,   144,   174,   169,
     168,   181,   180,   185,   185,   183,   184,   175,   170,     0,
       0,   176,   177,     0,   453,     0,     0,     0,     1,     0,
       0,   576,   572,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   111,   112,     0,     0,     0,    83,    86,
      88,    89,    90,    94,    93,    91,    92,     0,    84,    85,
       0,     0,     0,     0,     0,     0,   235,   238,     0,     0,
       0,     0,     0,     0,     0,   141,   131,   409,   408,   407,
       0,     0,     0,     0,     0,   145,   594,     0,   179,   182,
       0,     0,     0,   452,   455,   456,   454,   438,     0,     0,
       0,     0,     0,     0,     3,     0,     0,   560,     0,   580,
     577,   578,   148,   534,     0,   538,   540,   535,    65,   377,
     551,   375,   553,   592,     0,     0,     0,   412,   416,   478,
     396,   379,   472,     0,     0,   471,     0,     0,   477,     0,
       0,     0,   473,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   476,   474,   475,   470,   495,
     410,   496,   413,   378,   625,   502,   623,     0,   607,   376,
     624,   593,   591,   462,   621,     0,     0,     0,     0,     0,
       0,   215,   214,   213,   118,     0,   120,   122,   124,   113,
       0,   110,   106,    82,    81,     0,     0,   101,   105,     0,
      97,    95,     0,   543,     0,   546,   548,     0,    57,     0,
       0,     0,   239,     0,    79,    64,     0,     0,     0,   196,
     362,     0,   359,     0,   552,     7,     0,     0,     0,     0,
       8,   264,   266,   268,   304,   302,   270,   305,   303,     0,
       0,   526,     0,   405,     0,   528,   530,   402,     0,   187,
     191,   167,   189,   192,     0,   178,     0,    29,     0,    26,
      28,     0,    14,    13,     0,    24,    17,     0,   359,    12,
       0,    15,     0,     0,     2,   166,     0,     0,     0,     0,
     147,     0,     0,     0,     0,     0,     0,     0,   387,   385,
     386,   382,   384,   381,   383,   417,     0,   451,     0,     0,
     306,     0,     0,     0,     0,   498,     0,     0,   628,     0,
       0,   626,   627,   306,     0,   306,   306,   463,   306,   464,
     554,     0,     0,   397,     0,     0,     0,   508,   509,   510,
     511,   512,   513,     0,     0,     0,     0,   466,     0,     0,
       0,     0,     0,   118,     0,     0,     0,   114,     0,     0,
       0,   108,   353,   351,   318,   331,   333,   337,   340,   330,
     324,   329,   322,   344,   320,   352,   327,   343,   328,   350,
     342,   434,   436,   221,   314,   315,   316,   317,   339,     0,
     103,    99,     0,     0,    87,     0,     0,     0,     0,     0,
       0,    70,     0,    39,   363,   195,     0,     0,     0,     0,
     370,   451,   198,   433,   273,     0,   282,   272,   269,     0,
       0,     0,   301,     0,     0,   300,     0,   298,     0,     0,
     296,   297,     0,   283,     0,   299,     0,     0,     0,     0,
     133,   135,   128,   127,   130,     0,     0,     0,   186,     0,
       0,     0,   439,   457,   459,    10,     0,    11,    18,     0,
       0,     0,    19,     0,     0,     4,     5,     0,     0,   581,
     579,   539,     0,   541,   484,     0,     0,   595,     0,     0,
       0,   453,   493,   379,     0,     0,   624,   308,   309,   307,
       0,     0,   501,     0,   497,   499,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   503,   598,     0,
     606,   605,     0,     0,   608,   609,   610,   467,   465,   469,
     468,   622,     0,   203,   206,     0,   211,     0,   115,     0,
     116,     0,   432,     0,   119,   121,   123,   107,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   219,   218,   217,     0,   222,   223,   102,     0,
      96,     0,    98,   547,     0,   549,     0,    74,    78,     0,
       0,     0,    71,    39,    80,     0,    46,    47,     0,     0,
      37,    40,    41,   197,   373,   359,     0,     0,   453,   199,
     193,   271,   265,   267,   274,   280,   278,   276,   274,     0,
     517,   288,   287,   278,     0,   515,   276,   285,   284,     0,
     286,   132,     0,     0,     0,   403,   529,     0,   531,   188,
     190,   165,     0,   557,     0,   460,    27,     0,    25,    22,
     359,    16,    23,   171,     0,     0,   485,     0,   489,   490,
     394,   392,   393,   389,   391,   388,   390,   380,     0,     0,
       0,     0,   494,     0,     0,   487,     0,   492,   486,   491,
       0,   488,     0,     0,     0,   411,     0,   415,     0,   613,
     602,   603,     0,   601,   604,   600,     0,   599,     0,     0,
       0,     0,   210,     0,   209,   118,   208,   200,   109,   354,
       0,     0,     0,     0,     0,     0,   355,   347,     0,     0,
       0,     0,   347,     0,     0,   375,   216,   229,   234,     0,
     231,   228,   230,     0,   232,   220,   224,   225,   118,   104,
     100,     0,    49,     0,    77,    76,    49,    49,    49,    70,
      45,    44,    48,    43,    42,   371,   360,     0,     0,     0,
       0,   295,     0,   291,     0,   293,   294,     0,   521,     0,
     518,   520,   290,     0,   292,     0,   134,   136,     0,     0,
     458,   256,   461,     0,     0,    20,   172,     0,   164,   582,
     542,   612,     0,   256,     0,     0,     0,     0,   483,   500,
     479,   480,   481,   482,     0,   596,     0,   597,     0,   611,
     201,   207,   212,   117,   319,   332,   334,     0,   336,     0,
     338,     0,     0,   323,   345,     0,   321,   349,     0,   435,
     437,   202,   204,     0,   226,   227,   550,    55,    56,     0,
       0,    59,    50,    51,    75,    58,    60,    61,    38,     0,
     359,   256,   275,   281,   279,   277,   522,   523,   516,     0,
     514,     0,   140,     0,   137,   139,   532,     0,   260,   442,
       0,   359,   173,     0,     0,     0,     0,   380,     0,     0,
       0,   617,   614,     0,     0,     0,     0,   356,   348,   325,
       0,   326,     0,     0,    53,    54,    52,   361,   372,   449,
     519,   289,   129,     0,   244,   245,   253,     0,     0,     0,
     263,   260,   257,   258,   261,   310,   444,     9,    21,     0,
     395,   450,   504,   507,   505,   414,     0,     0,   335,     0,
     346,     0,   233,   138,     0,     0,     0,     0,   254,   374,
     431,     0,   369,   430,   364,   427,   428,     0,   359,   242,
     243,   259,   262,   312,   313,   311,     0,     0,     0,   445,
     440,   616,     0,   618,   615,     0,   341,   205,     0,   251,
       0,     0,     0,   246,   255,   365,     0,     0,   366,   451,
     443,    72,   448,     0,     0,     0,     0,     0,     0,     0,
       0,   247,   429,   368,   359,   453,    73,   447,   422,   423,
     418,   419,   424,    72,   620,   619,   252,   249,   250,     0,
     367,     0,     0,   426,   425,   421,   446,   248,   256,   420,
     442,   441
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    53,   404,   205,   234,   399,   400,   396,   401,   397,
     388,   389,    54,    55,    56,    57,   700,   701,   702,   853,
     941,   942,   943,   337,    58,   693,  1097,   686,   687,   343,
     321,    59,   178,   179,   180,   331,   512,   181,   509,   327,
     182,   480,   322,   183,   184,   185,   472,   477,   186,   316,
     317,    60,    61,   125,   563,   734,   370,   559,   560,   963,
     964,    62,    63,    64,   216,    65,    66,    67,    68,    69,
     149,   888,   150,   151,   152,   218,   378,   381,   382,    70,
     202,   348,   710,   311,   312,   834,   642,   931,   643,   313,
     645,   323,   676,   324,   677,   835,   836,   837,   838,    71,
     111,   112,   196,    72,  1010,  1011,   968,  1069,  1070,  1005,
     969,  1012,  1013,   652,   361,   362,   363,   364,   861,   865,
     863,   714,   952,   557,   365,   558,   366,   610,  1056,   503,
     504,   505,   506,   922,   507,   810,   817,   988,   383,   530,
     646,  1043,  1044,   350,  1038,   288,   425,   426,   767,    73,
      74,    75,   132,   372,    76,    77,   209,   289,   290,   291,
     292,   293,  1059,  1100,  1101,  1102,  1115,  1014,  1045,  1046,
     653,   532,   508,    78,   386,   743,  1080,  1016,  1060,  1081,
     533,   294,   154,   227,   572,   573,   367,   296,   434,   435,
     297,   605,   467,   368,   869,   870,   351,   130,  1006,    90,
      99,   298,   355,   299,   137,   881,   102,    79,    80,    81,
      82,   103,    83,   162,   240,   241,    84,   300,    85,   301,
     632,   796,   633,   302,   303,   304,   118
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -941
static const yytype_int16 yypact[] =
{
    2372,  -941,  -941,  -941,   222,  -941,   498,   222,   222,   498,
     498,   222,   222,   536,   222,   222,   498,   536,   536,   536,
     536,  -941,   713,  -941,   222,  -941,  -941,   498,  -941,   152,
     498,   498,  -941,   498,   498,  -941,  -941,  -941,   498,   498,
    -941,  -941,   536,   498,   727,  -941,   222,   498,   748,   471,
     -14,   498,   471,  -941,  -941,  -941,  -941,  -941,  -941,  -941,
    -941,  -941,  -941,  -941,  -941,  -941,  -941,  -941,  -941,  -941,
    -941,  -941,  -941,  -941,  -941,  -941,  -941,  -941,  -941,   324,
    -941,  -941,  -941,   212,  -941,  -941,  -941,   239,    29,  -941,
    -941,   468,  -941,  -941,  -941,    46,   143,   424,   135,   375,
     -96,  -941,  -941,  -941,  -941,  -941,    70,   163,   180,   189,
    -941,   191,  -941,  -941,  -941,  -941,   275,  -941,  -941,   107,
    -941,   311,  -941,   328,    19,   498,  -941,   140,   350,   355,
    -941,   151,   168,  -941,  -941,  -941,  -941,   237,  -941,  -941,
    -941,  -941,  -941,   389,   389,  -941,  -941,  -941,  -941,   392,
     357,   380,  -941,   605,    61,   172,   383,   391,  -941,  2372,
     785,  -941,  -941,   641,   222,   790,   222,   222,   665,  1204,
     446,    72,   671,  -941,  -941,   370,    96,   388,   472,  -941,
    -941,  -941,  -941,  -941,  -941,  -941,  -941,   222,  -941,  -941,
     823,   222,   498,   498,   498,   498,   191,  -941,   247,   498,
     247,    75,   451,   699,   961,  -941,   541,  -941,  -941,  -941,
     222,   222,   824,   222,   222,  -941,  -941,    75,  -941,  -941,
     174,   498,   710,  -941,  -941,  -941,  -941,  -941,  1319,  1319,
    1319,  1319,    54,    54,    28,   174,   498,  -941,   507,   508,
     529,  -941,   725,  -941,   524,  -941,   546,  -941,  -941,  -941,
     610,   537,  -941,  -941,   773,   625,   640,  -941,  -941,  -941,
    -941,   478,  -941,  1445,   645,  -941,   648,   649,  -941,    -2,
     652,   660,  -941,   679,   686,   660,   660,   689,   690,   693,
     700,  2169,   704,  2169,   801,  -941,  -941,  -941,  -941,  -941,
     478,  -941,   478,  -941,  -941,  -941,  -941,   -26,   -66,  -941,
    -941,  -941,  -941,   386,   782,   705,   715,   718,   480,   719,
     726,  -941,  -941,  -941,   803,   222,   666,  -941,  -941,  -941,
     247,  -941,  -941,  -941,  -941,   457,   222,  -941,  -941,   247,
     646,  -941,   424,  -941,   653,  -941,   672,   736,  -941,   737,
     739,   740,  -941,    15,  -941,  -941,    20,   727,    88,  -941,
    -941,   663,   404,   729,  -941,  -941,   660,   754,   660,  1078,
     661,   691,  -941,  -941,  -941,  -941,  -941,   698,  -941,   222,
     354,  -941,   669,  -941,   670,  -941,   697,  -941,    94,  -941,
    -941,   701,  -941,  -941,   709,  -941,  1928,  -941,   119,  -941,
    -941,   121,   702,   702,   222,  -941,  -941,   207,   170,   707,
     747,  -941,   699,   961,  -941,   701,   682,   222,   222,   785,
    -941,   222,   827,  1561,   222,   903,  1928,  1928,  -941,  -941,
    -941,  -941,  -941,  -941,  -941,  -941,   694,   -14,   781,  2043,
     162,  1928,  1928,   961,   437,  -941,  1928,   757,  -941,  1928,
    1928,  -941,  -941,   162,  1928,   162,   162,   386,   162,   386,
    -941,   706,   -53,  -941,  1928,    52,    48,  -941,  -941,  -941,
    -941,  -941,  -941,  1928,  1928,  1928,  1928,  -941,   457,    75,
      75,    75,   209,   803,    75,   961,   222,  -941,   219,   222,
     232,  -941,  -941,  -941,   774,   779,   780,   478,   478,  -941,
     787,  -941,   789,   791,   794,   795,   796,  -941,  -941,  -941,
    -941,   797,   798,   613,  -941,  -941,  -941,  -941,  -941,   234,
    -941,  -941,   236,   222,  -941,   222,   832,   222,   222,   222,
     222,   821,   247,   111,  -941,  -941,    75,    78,   941,   222,
    -941,   -14,   858,  -941,  -941,   -46,  2368,  -941,  -941,   961,
     961,  2169,  -941,  2169,  2169,  -941,  2169,  -941,   799,  1687,
    -941,  -941,  2169,  -941,   805,  -941,  2169,   571,  1928,   244,
    -941,   712,  -941,  -941,  -941,   222,   222,   844,  -941,    75,
     174,   174,   743,  -941,    69,  -941,  1319,  -941,  -941,   811,
      54,    79,  -941,    54,  1319,  -941,   661,   174,   732,  -941,
    -941,  -941,   750,  -941,  -941,   250,   755,  -941,   251,   272,
     499,    61,  -941,   330,   770,   834,   771,  -941,  -941,  -941,
    1928,   290,  -941,   -92,  -941,  -941,   293,   294,   314,  1928,
     326,  1928,  1928,  1928,   499,   998,   499,  -941,  -941,    52,
    -941,  -941,   301,  1001,  -941,  -941,   194,  -941,  -941,  -941,
    -941,  -941,   859,   783,  -941,   342,  -941,   344,  -941,   480,
    -941,   345,   661,   861,  -941,  -941,  -941,  -941,   247,  1005,
    1005,  1009,   768,   -43,  1012,  1014,  1015,  1018,  1012,  1012,
    1019,  1020,  -941,  -941,  -941,    82,  -941,   307,  -941,   222,
    -941,   247,  -941,  -941,   784,  -941,   348,  -941,   127,   393,
     394,   396,  -941,   111,  -941,  1023,  -941,  -941,  1024,  1025,
    -941,   111,  -941,  -941,  -941,   854,    23,   800,    61,  -941,
    -941,  -941,   691,  -941,   870,   386,   871,   873,   870,   131,
    -941,  -941,  -941,   871,   131,  -941,   873,  -941,  -941,  1928,
    -941,  -941,   222,   222,   877,  -941,  -941,   804,  -941,  -941,
    -941,   701,  1928,  -941,   222,  -941,  -941,   881,  -941,  -941,
     221,  -941,  -941,    45,   222,   222,  -941,   222,  -941,  -941,
     883,  -941,  -941,  -941,  -941,  -941,  -941,  -941,  1928,   478,
     806,   478,  -941,   478,   898,  -941,  1928,  -941,  -941,  -941,
     900,  -941,   902,   904,   905,  -941,   907,  -941,   447,  -941,
    -941,  -941,    52,  -941,  -941,  -941,    52,  -941,    52,   222,
     935,    75,  -941,    75,  -941,   803,  -941,  -941,  -941,  -941,
     909,   910,   410,   499,  1058,   499,  -941,   835,   913,   438,
     915,   916,   835,   917,   919,  -941,  -941,  -941,  -941,   498,
    -941,  -941,  -941,   908,  -941,  -941,   307,  -941,   803,  -941,
    -941,   222,   129,   222,  -941,  -941,   129,   129,   129,   821,
    -941,  -941,  -941,  -941,  -941,  -941,  -941,  1067,   222,  1928,
      82,  -941,    82,  -941,    82,  -941,  -941,    57,  -941,   452,
    -941,  -941,  -941,   456,  -941,   852,  -941,  -941,  1802,   222,
    -941,   868,  -941,  1319,   222,  -941,  -941,   713,  -941,  -941,
    -941,   914,  1073,    41,   833,   499,   842,   845,  -941,  -941,
    -941,  -941,  -941,  -941,   846,  -941,   530,   463,   528,   918,
    -941,  -941,  -941,  -941,  -941,  -941,  -941,  1074,  -941,   939,
    -941,  1091,   946,  -941,  -941,  1094,  -941,  -941,   949,  -941,
    -941,  -941,   937,   961,  -941,  -941,  -941,  -941,  -941,  1025,
    1098,  -941,   129,  -941,  -941,  -941,  -941,  -941,  -941,   943,
     854,    41,  -941,  -941,  -941,  -941,  -941,  -941,  -941,   125,
    -941,  1928,  -941,   461,  -941,  -941,  -941,   498,   405,   906,
     464,   854,  -941,    52,   953,   955,   499,   956,   499,   499,
     499,  -941,  -941,    52,    52,   957,   864,  -941,  -941,  -941,
     962,  -941,    75,   964,  -941,  -941,  -941,  -941,  -941,  -941,
    -941,  -941,  -941,  1802,    39,  -941,    71,    83,   961,   961,
    -941,   118,  -941,  -941,   947,   195,   -12,  -941,  -941,   543,
    -941,  -941,  -941,  -941,  -941,  -941,   631,   580,  -941,   499,
    -941,   483,  -941,  -941,   175,   175,    99,   222,  -941,  -941,
    -941,    65,  -941,  -941,  -941,   891,  -941,   878,   489,   661,
     661,  -941,  -941,  -941,  -941,  -941,   942,   222,   885,   986,
    -941,  -941,    52,  -941,  -941,    52,  -941,  -941,   498,    39,
     880,   886,   199,  -941,  -941,  -941,    83,    86,  -941,   -14,
    -941,  1011,  -941,   110,   222,   639,   692,   114,   961,   961,
     498,  -941,  -941,  -941,   854,    61,  -941,  -941,  -941,  -941,
     911,  -941,   518,  1011,  -941,  -941,  -941,   661,   661,   128,
    -941,  1928,   110,  -941,  -941,  -941,  -941,  -941,    41,  -941,
     906,  -941
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -941,  -941,  -941,  -941,  -941,  -941,  -181,   738,   547,  -941,
    -185,  -134,  -941,  -941,  -941,  -941,   440,  -941,   430,   196,
    -111,  -941,   192,   550,  -941,   287,    34,   282,   296,   940,
    -144,  -941,  -941,   810,  -941,  -272,  -941,  -941,  -941,  -277,
    -941,  -941,  -261,  -941,  -941,  -941,  -941,  -451,  -941,   828,
     667,  -941,  -941,  -941,  -941,  -941,  -941,  -941,   412,  -941,
     144,  -941,  -941,  -941,  -941,  -941,  -941,  -941,  -941,  -941,
    1097,  -941,  1099,  -941,   928,  1008,  -941,  -198,   583,  -941,
    -941,  -941,  -941,  -941,  -941,   358,  -941,  -941,   165,  -941,
     190,  -139,  -941,  -941,  -941,  -941,  -941,   318,  -941,  -941,
    -941,  -941,  -941,    16,   145,  -941,  -941,  -803,   126,  -940,
    -813,  -941,   149,  -203,   626,   624,   807,  -941,   449,   442,
     448,   366,    -5,  -941,  -941,  -941,  -941,   337,  -941,   717,
    -941,  -941,  -941,   347,  -941,   510,  -120,  -941,    -3,  -370,
    -176,  -872,   133,   825,   138,  -607,  -941,  -242,  -561,  -941,
    -941,  -941,   963,   615,  -941,  -941,  -941,  -941,  -941,  -941,
    -941,  -941,  -941,  -941,    76,  -941,  -941,  -941,  -941,   105,
     254,  -941,  -941,  -941,  -941,  -941,  -941,    63,  -941,   106,
     831,  -209,  -406,  -565,  -715,   453,  -137,  -941,  -941,   764,
     603,  -941,  -941,  -941,   467,   245,   -27,  -941,    68,  -941,
     802,    -4,   809,   336,  -941,  -941,  -941,  -941,  -941,  1046,
    -941,  1191,  -941,  -941,  -941,   808,  -941,  -405,  -941,  -941,
    -559,  -941,  -941,  -941,  -115,  -941,  -941
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -565
static const yytype_int16 yytable[] =
{
      87,   360,    91,    92,    93,    91,    91,    96,    97,   100,
     101,   101,    91,   100,   100,   100,   100,   129,   114,   113,
     115,   601,   650,    91,   606,   349,    91,    91,   582,    91,
      91,   314,   295,   330,    91,    91,   768,   405,   100,    91,
     131,   379,   133,    91,   391,   392,   393,    91,   451,   510,
     452,   395,    86,   893,   344,   628,   344,   511,    86,   481,
     956,  1034,   438,   785,  1035,   787,   441,   442,   826,    86,
     788,   128,   252,    86,    89,    86,    86,    94,    95,    86,
     975,   128,    86,    86,   105,   249,  1040,    86,   825,   128,
      86,   390,   390,   390,   390,   116,  1073,   252,   119,   120,
      86,   121,   122,    86,   711,    88,   123,   124,   455,   203,
     625,   127,   868,  1098,    86,   134,   128,   868,   402,   155,
     814,    91,   776,  1057,   453,   708,   428,   197,   249,    86,
     190,   251,  1091,   886,   249,    86,  1034,   251,   999,  1035,
     252,   191,   253,   859,   951,   254,   252,   534,   253,   537,
    1034,   254,   539,  1035,   535,   117,   239,   937,   938,   695,
     243,   245,   246,   247,  1004,   521,   447,   318,   449,   473,
     523,   325,   328,   325,   153,   456,   696,   697,    86,    86,
     110,    88,   856,   333,  1058,   330,   335,   336,    91,    91,
      91,    91,   626,   206,   325,    91,   325,   352,   539,   224,
     586,   454,   815,    86,   432,    88,   371,   373,   375,   376,
     133,  1099,   342,   352,   433,   629,   114,    91,   204,   698,
     536,   228,   229,   230,   231,   232,    86,   403,   398,   398,
     613,   114,    91,   906,   261,   315,   207,   907,   525,   908,
    1099,   225,   522,   634,   568,   662,   663,   522,   967,   574,
     857,    86,   918,   953,   920,   953,   208,   953,  1007,   326,
     338,   338,   338,   338,  1106,  1087,  1036,   345,   742,   575,
     164,   577,   570,   704,   749,   163,   295,   261,  1117,   295,
     295,  1093,   226,   261,   887,   630,  1008,  1109,   168,   384,
     631,   394,   604,   644,   295,   612,  1072,    38,   284,   295,
     607,   635,   295,   295,   406,  1120,   169,   295,   744,   427,
    1037,   318,   347,   192,   871,   526,   325,   627,  1042,   871,
    1041,   569,   328,   284,   158,   325,   637,   638,   639,   640,
     844,   160,   161,  1053,   977,   855,  1042,   199,  1068,   720,
     159,  1036,   608,   352,   528,   725,   576,  1041,   576,   380,
     703,   845,   868,   699,   913,  1036,   305,   579,   867,   648,
     306,   770,  1090,  1042,   867,   561,   284,    49,   798,   655,
     215,   939,   284,   741,    86,  1054,   187,   212,   694,   940,
     885,    52,   657,   609,   678,   307,   680,   935,   213,   753,
     398,   233,    86,   739,   731,   528,  1118,   808,   827,   748,
     756,   758,   839,   588,   589,   239,   193,   591,   593,   840,
     596,   581,   722,   214,  1019,  1022,  1055,  1023,  1024,  1025,
     828,   730,   759,   194,  1026,  1027,   715,   309,   715,   715,
     829,   715,   195,   310,   580,   799,   649,   715,   198,   390,
     775,   715,   746,   777,   778,   830,   479,   390,   188,   189,
     752,   831,   636,   457,   458,   459,   460,   461,   462,   658,
     789,   679,   884,   681,   779,   352,   352,   352,  1066,   418,
     352,   732,   654,   774,   200,   318,   781,   454,   454,   305,
     170,   171,   780,   306,   782,   783,   784,   832,   172,   173,
     174,   201,   802,   833,   804,   806,   790,   305,   842,   454,
     419,   306,    86,  1085,    88,   791,  1086,   420,   307,   682,
     805,   683,   685,   688,   688,   688,   688,   454,   325,   482,
     454,   454,   352,   705,   421,   707,   307,   894,   792,   896,
    1111,   897,   531,   320,   793,   794,   562,   330,   422,   795,
      86,   454,    98,   846,   847,  1007,   848,   423,   821,   822,
     309,   329,   217,   454,   871,   305,   310,   769,   424,   306,
     916,   373,   736,   738,   138,   352,   114,   114,   309,   803,
     745,   803,   803,  1008,   310,   843,   398,   750,   528,   398,
     998,   463,   483,   114,   307,   484,   485,   486,   924,   305,
     464,   210,   875,   306,   487,   175,   211,   905,   488,   220,
     221,  1018,   958,   489,  1009,   574,   960,   222,   223,   308,
     490,  1002,   491,   492,  1017,   493,   139,   418,   307,   465,
     843,   843,   140,   843,   466,   911,   309,   912,   235,   176,
     212,   574,   310,  1067,   236,   141,   494,   917,   760,   899,
     142,   213,   790,   432,   177,   529,   495,   242,   419,   143,
     496,   791,   144,   433,   325,   420,   145,   497,   790,   498,
     309,   647,   146,   528,   651,   925,   310,   791,   499,   761,
     500,   248,   421,  1095,   319,   328,   762,   325,  1078,   959,
     793,   794,   727,   959,   614,   795,   422,   982,  1003,   981,
     353,   576,   147,   763,   165,   423,   793,   794,   970,   332,
     148,   795,  1061,   354,   369,   166,   424,   764,   501,   167,
     801,   502,   672,   673,   674,   212,   765,    86,   728,   110,
     729,  1113,   574,   790,  1110,   790,   213,   766,   561,   877,
    -527,    86,   791,   128,   791,   945,   946,   947,   790,  1064,
     882,   965,  1114,   339,   340,   341,   390,   791,   407,   408,
     889,   890,   135,   891,   136,   983,   409,   249,   250,   410,
     251,   793,   794,   793,   794,   411,   795,   675,   795,   252,
    1062,   253,   412,   413,   254,   790,   793,   794,   414,   415,
     619,   795,   621,   622,   791,   623,   255,   256,   416,    86,
    1063,   238,   257,   258,    86,   909,   244,   352,  1104,   352,
     689,   690,   691,   417,   450,  1049,  1050,  1065,   429,  -282,
     541,   430,   431,   793,   794,   436,   644,   259,   795,   106,
     107,   108,   109,   437,  1001,    91,   790,    86,    86,   334,
     374,    86,   542,   592,   790,   791,    86,   936,   684,   688,
     543,   544,   439,   791,   126,  -282,   545,  -282,    86,   440,
     737,  1105,   443,   444,   950,   546,   445,   954,   547,   955,
     548,   468,   476,   446,   793,   794,   965,   448,   469,   795,
     549,   550,   793,   794,   141,   966,   356,   795,   470,   142,
     971,   471,   474,   114,   972,  1107,  1108,   790,   143,   475,
     551,   144,   513,   479,   515,   145,   791,   932,   516,   517,
     518,   146,   519,   520,   527,   539,   261,   531,   552,   716,
     717,   566,   718,   540,   565,   262,   571,   357,   723,   584,
     358,   264,   726,   567,   597,   793,   794,   587,   570,   576,
     795,   602,   427,   553,   583,   427,   692,   659,   265,   600,
     554,   266,   660,   661,   706,   709,   555,   556,   267,   268,
     664,   624,   665,   733,   666,   269,   270,   667,   668,   669,
     670,   671,   719,    91,   249,   250,   271,   251,   724,   272,
     742,   273,   274,   754,   574,   275,   252,   276,   253,   277,
    1047,   254,   278,   747,   772,   279,   280,   281,   352,   359,
     282,   755,   283,   255,   256,   284,   757,   771,   773,   257,
     258,   786,  1039,  1048,   797,   285,   286,   287,   809,   800,
     801,   807,   812,   813,  1047,   816,   595,   818,   819,   598,
     599,   820,   823,   824,   259,   841,   850,   851,   528,   852,
      91,    91,    91,  1039,   611,   860,   862,  1048,   864,   616,
     878,   858,   617,   618,   883,   879,   892,   620,   898,  1047,
     900,   895,   901,  1082,   902,   903,  1047,   904,   829,   914,
     915,   919,   921,   923,    91,   926,   927,   929,    91,   930,
     949,   933,  1048,  1094,   961,   967,   974,   985,   976,  1048,
    1082,   249,   250,   356,   251,  1047,    91,   978,   973,   986,
     979,   980,   984,   252,   987,   253,   989,   990,   254,   991,
     992,   995,   997,  1020,  1015,  1021,  -506,  1028,  1048,  1029,
     255,   256,  1030,   261,  1032,  1008,   257,   258,  1076,  1077,
    1079,  1084,   262,  1088,   357,  1083,  1096,   358,   264,  1089,
     751,   854,   578,   849,   996,   994,   948,  1116,  1112,   944,
     346,   259,   514,   478,   876,   265,   656,  1033,   266,   156,
     385,   157,   219,   740,   934,   267,   268,  1031,   910,  1052,
    1051,  1071,   269,   270,   713,   712,   538,   866,   874,   928,
     811,   872,   524,   271,  1075,  1074,   272,   377,   273,   274,
     735,  1092,   275,  1121,   276,   641,   277,   993,  1119,   278,
    1103,   873,   279,   280,   281,   880,   359,   282,   615,   283,
     356,   564,   284,   957,  1000,   237,   104,   249,   250,     0,
     251,   585,   285,   286,   287,     0,     0,   590,     0,   252,
       0,   253,     0,     0,   254,     0,     0,     0,     0,     0,
     261,     0,     0,     0,     0,     0,   255,   256,     0,   262,
       0,   357,   257,   258,   358,   264,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   265,     0,     0,   266,     0,   259,     0,     0,
       0,     0,   267,   268,     0,     0,     0,     0,     0,   269,
     270,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     271,     0,     0,   272,     0,   273,   274,     0,     0,   275,
       0,   276,     0,   277,     0,     0,   278,     0,     0,   279,
     280,   281,     0,     0,   282,     0,   283,     0,     0,   284,
       0,     0,   249,   250,     0,   251,     0,     0,     0,   285,
     286,   287,     0,     0,   252,     0,   253,     0,     0,   254,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   255,   256,     0,   260,     0,   261,   257,   258,     0,
       0,     0,     0,     0,     0,   262,     0,   263,     0,     0,
       0,   264,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   259,     0,     0,     0,     0,     0,   265,     0,
       0,   266,     0,     0,     0,     0,     0,     0,   267,   268,
       0,     0,     0,     0,     0,   269,   270,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   271,     0,     0,   272,
       0,   273,   274,     0,     0,   275,     0,   276,     0,   277,
       0,     0,   278,     0,     0,   279,   280,   281,     0,     0,
     282,     0,   283,     0,     0,   284,     0,     0,   249,   250,
       0,   251,     0,     0,     0,   285,   286,   287,     0,     0,
     252,     0,   253,     0,     0,   254,     0,     0,     0,     0,
       0,   261,     0,     0,     0,     0,     0,   255,   256,     0,
     262,     0,   263,   257,   258,     0,   264,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   387,   265,     0,     0,   266,     0,   259,     0,
       0,     0,     0,   267,   268,     0,     0,     0,     0,     0,
     269,   270,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   271,     0,     0,   272,     0,   273,   274,     0,     0,
     275,     0,   276,     0,   277,     0,     0,   278,     0,     0,
     279,   280,   281,     0,     0,   282,     0,   283,     0,     0,
     284,     0,     0,     0,   249,   250,     0,   251,     0,     0,
     285,   286,   287,     0,     0,     0,   252,     0,   253,     0,
       0,   254,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   255,   256,     0,     0,   261,     0,   257,
     258,     0,     0,     0,     0,     0,   262,     0,   263,     0,
       0,     0,   264,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   427,   259,     0,     0,     0,     0,   265,
       0,     0,   266,     0,     0,     0,     0,     0,     0,   267,
     268,     0,     0,     0,     0,     0,   269,   270,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   271,     0,     0,
     272,     0,   273,   274,     0,     0,   275,     0,   276,     0,
     277,     0,     0,   278,     0,     0,   279,   280,   281,     0,
       0,   282,     0,   283,     0,     0,   284,     0,     0,     0,
     249,   250,     0,   251,     0,     0,   285,   286,   287,     0,
       0,     0,   252,     0,   253,     0,     0,   254,     0,     0,
       0,   594,     0,   261,     0,     0,     0,     0,     0,   255,
     256,     0,   262,     0,   263,   257,   258,     0,   264,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   265,     0,     0,   266,     0,
     259,     0,     0,     0,     0,   267,   268,     0,     0,     0,
       0,     0,   269,   270,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   271,     0,     0,   272,     0,   273,   274,
       0,     0,   275,     0,   276,     0,   277,     0,     0,   278,
       0,     0,   279,   280,   281,     0,     0,   282,     0,   283,
       0,     0,   284,     0,     0,   249,   250,     0,   251,     0,
       0,     0,   285,   286,   287,     0,     0,   252,     0,   253,
       0,     0,   254,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   255,   256,     0,     0,     0,   261,
     257,   258,     0,     0,     0,     0,     0,     0,   262,     0,
     263,     0,     0,     0,   264,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   259,     0,     0,     0,     0,
     721,   265,     0,     0,   266,     0,     0,     0,     0,     0,
       0,   267,   268,     0,     0,     0,     0,     0,   269,   270,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   271,
       0,     0,   272,     0,   273,   274,     0,     0,   275,     0,
     276,     0,   277,     0,     0,   278,     0,     0,   279,   280,
     281,     0,     0,   282,     0,   283,     0,     0,   284,     0,
       0,   249,   250,     0,   251,     0,     0,     0,   285,   286,
     287,     0,     0,   252,     0,   253,     0,     0,   254,     0,
       0,     0,     0,     0,   261,     0,     0,     0,     0,     0,
     255,   256,     0,   262,     0,   263,   257,   258,     0,   264,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   962,   265,     0,     0,   266,
       0,   259,     0,     0,     0,     0,   267,   268,     0,     0,
       0,     0,     0,   269,   270,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   271,     0,     0,   272,     0,   273,
     274,     0,     0,   275,     0,   276,     0,   277,     0,     0,
     278,     0,     0,   279,   280,   281,     0,     0,   282,     0,
     283,     0,     0,   284,     0,     0,   249,   250,     0,   251,
       0,     0,     0,   285,   286,   287,     0,     0,   252,     0,
     253,     0,     0,   254,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   255,   256,     0,     0,     0,
     261,   257,   258,     0,     0,     0,     0,     0,     0,   262,
       0,   263,     0,     0,     0,   264,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   259,     0,     0,     0,
       0,     0,   265,     0,     0,   266,     0,     0,     0,     0,
       0,     0,   267,   268,     0,     0,     0,     0,     0,   269,
     270,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     271,     0,     0,   272,     0,   273,   274,     0,     0,   275,
       0,   276,     0,   277,     0,     0,   278,     0,     0,   279,
     280,   281,     0,     0,   282,     0,   283,     0,     0,   284,
       0,     0,   249,   250,     0,   251,     0,     0,     0,   285,
     286,   287,     0,     0,   252,     0,   253,     0,     0,   254,
       0,     0,     0,     0,     0,   603,     0,     0,     0,     0,
       0,   255,   256,     0,   262,     0,   263,   257,   258,     0,
     264,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   265,     0,     0,
     266,     0,   259,     0,     0,     0,     0,   267,   268,     0,
       0,     0,     0,     0,   269,   270,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   271,     0,     0,   272,     0,
     273,   274,     0,     0,   275,     0,   276,     0,   277,     0,
       0,   278,     0,     0,   279,   280,   281,     0,     0,   282,
       0,   283,     0,     0,   284,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   285,   286,   287,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   261,     0,     0,     0,     0,     0,     0,     0,     0,
     262,     0,   263,     0,     0,     0,   264,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   265,     0,     0,   266,     0,     0,     0,
       0,     0,     0,   267,   268,     0,     0,     0,     0,     0,
     269,   270,  -564,     1,     0,     0,     0,     0,     0,     0,
       0,   271,     0,     0,   272,     0,   273,   274,  -564,     0,
     275,     0,   276,     0,   277,     0,     0,   278,     0,     0,
     279,   280,     2,     3,     0,   282,     0,     4,     0,     5,
     284,     0,     6,     7,     8,     9,    10,    11,    12,    13,
     285,   286,   287,     0,     0,     0,    14,    15,     0,     0,
      16,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    17,    18,    19,
      20,     0,    21,    22,    23,    24,    25,    26,    27,     0,
       0,    28,     0,     0,    29,     0,    30,    31,     0,    32,
      33,     0,     0,     0,    34,    35,    36,    37,    38,    39,
     541,     0,    40,     0,     0,     0,     0,     0,     0,    41,
      42,     0,     0,    43,     0,     0,    44,     0,    45,    46,
       0,     0,   542,     0,    47,     0,     0,     0,    48,     0,
     543,   544,     0,     0,     0,     0,   545,     0,   602,     0,
       0,     0,     0,     0,     0,   546,     0,     0,   547,     0,
     548,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     549,   550,     0,     0,     0,     0,     0,     0,    49,     0,
      50,     0,     0,    51,     0,     0,     0,     0,     0,     0,
     551,     0,    52,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   552,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    -305,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   553,     0,     0,     0,     0,     0,     0,
     554,     0,  -305,     0,     0,     0,   555,   556
};

static const yytype_int16 yycheck[] =
{
       4,   204,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    44,    22,    22,
      24,   427,   473,    27,   429,   201,    30,    31,   398,    33,
      34,   170,   169,   177,    38,    39,   601,   235,    42,    43,
      44,   217,    46,    47,   229,   230,   231,    51,   290,   326,
     292,   232,     4,   768,   198,     3,   200,   329,     4,   320,
       3,    22,   271,   624,    25,   626,   275,   276,   675,     4,
     629,     6,    15,     4,     6,     4,     4,     9,    10,     4,
     893,     6,     4,     4,    16,     3,     3,     4,     6,     6,
       4,   228,   229,   230,   231,    27,  1036,    15,    30,    31,
       4,    33,    34,     4,   150,     6,    38,    39,   174,    90,
     163,    43,   719,     3,     4,    47,     6,   724,    90,    51,
     163,   125,   214,   135,   150,   531,   263,   111,     3,     4,
     226,     6,  1072,    88,     3,     4,    22,     6,   951,    25,
      15,   237,    17,   708,   859,    20,    15,   356,    17,   358,
      22,    20,   244,    25,   357,     3,   160,    28,    29,    48,
     164,   165,   166,   167,   967,   150,   281,   171,   283,   308,
     150,   175,   176,   177,   188,   241,    65,    66,     4,     4,
       6,     6,   159,   187,   196,   329,   190,   191,   192,   193,
     194,   195,   245,   125,   198,   199,   200,   201,   244,   138,
     403,   227,   245,     4,   206,     6,   210,   211,   212,   213,
     214,  1083,   196,   217,   216,   163,   220,   221,   199,   108,
     357,    49,    50,    51,    52,    53,     4,   199,   232,   233,
     433,   235,   236,   792,   152,   163,    96,   796,   150,   798,
    1112,   180,   227,   195,   150,   487,   488,   227,   207,   386,
     227,     4,   813,   860,   815,   862,   116,   864,   140,   163,
     192,   193,   194,   195,   150,  1068,   227,   199,   227,   150,
     241,   150,   227,   195,   195,    36,   413,   152,   150,   416,
     417,   195,   221,   152,   239,   233,   168,  1090,   242,   221,
     238,   237,   429,   469,   431,   432,   197,   106,   241,   436,
     138,   253,   439,   440,   236,  1118,   163,   444,   239,   178,
     239,   315,   237,   243,   719,   227,   320,   454,   253,   724,
     237,   227,   326,   241,     0,   329,   463,   464,   465,   466,
     203,   119,   120,   138,   895,   705,   253,   230,   163,   548,
      16,   227,   180,   347,   174,   554,   227,   237,   227,   175,
     526,   224,   959,   242,   805,   227,   109,   150,   233,   150,
     113,   603,   163,   253,   233,   369,   241,   176,   174,   150,
     133,   242,   241,   571,     4,   180,   241,   226,   522,   250,
     750,   190,   150,   221,   150,   138,   150,   838,   237,   587,
     394,   219,     4,   569,   150,   174,  1111,   658,    91,   580,
     150,   150,   679,   407,   408,   409,   243,   411,   412,   681,
     414,   241,   549,   245,   973,   976,   221,   978,   979,   980,
     113,   558,   150,   243,   983,   984,   541,   180,   543,   544,
     123,   546,   243,   186,   227,   241,   227,   552,   163,   576,
     150,   556,   576,   150,   150,   138,   227,   584,    73,    74,
     584,   144,   456,    67,    68,    69,    70,    71,    72,   227,
     159,   227,   241,   227,   150,   469,   470,   471,  1029,   139,
     474,   227,   476,   610,   163,   479,   150,   227,   227,   109,
      56,    57,   619,   113,   621,   622,   623,   180,    64,    65,
      66,   163,   150,   186,   150,   150,   195,   109,   150,   227,
     170,   113,     4,  1062,     6,   204,  1065,   177,   138,   513,
     649,   515,   516,   517,   518,   519,   520,   227,   522,    62,
     227,   227,   526,   527,   194,   529,   138,   769,   227,   771,
    1095,   773,   178,   163,   233,   234,   182,   681,   208,   238,
       4,   227,     6,   150,   150,   140,   150,   217,   668,   669,
     180,   163,   163,   227,   959,   109,   186,   227,   228,   113,
     150,   565,   566,   567,    93,   569,   570,   571,   180,   227,
     574,   227,   227,   168,   186,   227,   580,   581,   174,   583,
     950,   195,   125,   587,   138,   128,   129,   130,   150,   109,
     204,   241,   729,   113,   137,   171,   241,   150,   141,   207,
     243,   971,   150,   146,   199,   742,   150,   227,     3,   163,
     153,   150,   155,   156,   150,   158,   145,   139,   138,   233,
     227,   227,   151,   227,   238,   801,   180,   803,   245,   205,
     226,   768,   186,   150,   243,   164,   179,   227,   139,   776,
     169,   237,   195,   206,   220,   241,   189,     6,   170,   178,
     193,   204,   181,   216,   658,   177,   185,   200,   195,   202,
     180,   471,   191,   174,   474,   227,   186,   204,   211,   170,
     213,     6,   194,  1079,     3,   679,   177,   681,  1048,   227,
     233,   234,   111,   227,   247,   238,   208,   159,   227,   159,
     239,   227,   221,   194,   226,   217,   233,   234,   883,   227,
     229,   238,   159,     4,   163,   237,   228,   208,   251,   241,
     227,   254,    99,   100,   101,   226,   217,     4,   147,     6,
     149,   203,   859,   195,  1094,   195,   237,   228,   732,   733,
     241,     4,   204,     6,   204,   846,   847,   848,   195,   159,
     744,   878,   224,   193,   194,   195,   883,   204,   241,   241,
     754,   755,     4,   757,     6,   227,   227,     3,     4,    34,
       6,   233,   234,   233,   234,   241,   238,   154,   238,    15,
     227,    17,   226,   163,    20,   195,   233,   234,   241,     6,
     443,   238,   445,   446,   204,   448,    32,    33,   163,     4,
     159,     6,    38,    39,     4,   799,     6,   801,   159,   803,
     518,   519,   520,   163,     3,  1008,  1009,   227,   163,   111,
     112,   163,   163,   233,   234,   163,   992,    63,   238,    17,
      18,    19,    20,   163,   961,   829,   195,     4,     4,     6,
       6,     4,   134,     6,   195,   204,     4,   841,     6,   843,
     142,   143,   163,   204,    42,   147,   148,   149,     4,   163,
       6,   159,   163,   163,   858,   157,   163,   862,   160,   864,
     162,    79,    59,   163,   233,   234,  1003,   163,   163,   238,
     172,   173,   233,   234,   164,   879,   122,   238,   163,   169,
     884,   163,   163,   887,   887,  1088,  1089,   195,   178,   163,
     192,   181,   246,   227,   241,   185,   204,   829,   226,   163,
     163,   191,   163,   163,   241,   244,   152,   178,   210,   543,
     544,   241,   546,   222,   245,   161,   207,   163,   552,   172,
     166,   167,   556,   226,    21,   233,   234,   245,   227,   227,
     238,   150,   178,   235,   227,   178,   115,   163,   184,   245,
     242,   187,   163,   163,     3,    87,   248,   249,   194,   195,
     163,   245,   163,   241,   163,   201,   202,   163,   163,   163,
     163,   163,   163,   967,     3,     4,   212,     6,   163,   215,
     227,   217,   218,   241,  1111,   221,    15,   223,    17,   225,
    1007,    20,   228,   172,   150,   231,   232,   233,   992,   235,
     236,   241,   238,    32,    33,   241,   241,   227,   227,    38,
      39,     3,  1006,  1007,     3,   251,   252,   253,     3,   150,
     227,   150,     3,   245,  1041,     3,   413,     3,     3,   416,
     417,     3,     3,     3,    63,   241,     3,     3,   174,     4,
    1034,  1035,  1036,  1037,   431,   165,   165,  1041,   165,   436,
     163,   241,   439,   440,   163,   241,   163,   444,   150,  1076,
     150,   245,   150,  1057,   150,   150,  1083,   150,   123,   150,
     150,     3,   227,   150,  1068,   150,   150,   150,  1072,   150,
       3,   163,  1076,  1077,   222,   207,     3,     3,   245,  1083,
    1084,     3,     4,   122,     6,  1112,  1090,   245,   174,   150,
     245,   245,   174,    15,     3,    17,   150,     3,    20,   150,
     163,     3,   159,   150,   198,   150,   150,   150,  1112,   245,
      32,    33,   150,   152,   150,   168,    38,    39,   227,   241,
     178,   135,   161,   243,   163,   240,   115,   166,   167,   243,
     583,   701,   394,   693,   942,   939,   849,  1103,   227,   843,
     200,    63,   332,   315,   732,   184,   479,  1003,   187,    52,
     222,    52,   144,   570,   836,   194,   195,   992,   800,  1014,
    1011,  1035,   201,   202,   540,   539,   359,   718,   726,   822,
     660,   723,   347,   212,  1041,  1037,   215,   214,   217,   218,
     565,  1076,   221,  1120,   223,   468,   225,   933,  1112,   228,
    1084,   724,   231,   232,   233,   742,   235,   236,   434,   238,
     122,   370,   241,   867,   959,   159,    15,     3,     4,    -1,
       6,   402,   251,   252,   253,    -1,    -1,   409,    -1,    15,
      -1,    17,    -1,    -1,    20,    -1,    -1,    -1,    -1,    -1,
     152,    -1,    -1,    -1,    -1,    -1,    32,    33,    -1,   161,
      -1,   163,    38,    39,   166,   167,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   184,    -1,    -1,   187,    -1,    63,    -1,    -1,
      -1,    -1,   194,   195,    -1,    -1,    -1,    -1,    -1,   201,
     202,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     212,    -1,    -1,   215,    -1,   217,   218,    -1,    -1,   221,
      -1,   223,    -1,   225,    -1,    -1,   228,    -1,    -1,   231,
     232,   233,    -1,    -1,   236,    -1,   238,    -1,    -1,   241,
      -1,    -1,     3,     4,    -1,     6,    -1,    -1,    -1,   251,
     252,   253,    -1,    -1,    15,    -1,    17,    -1,    -1,    20,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    32,    33,    -1,   150,    -1,   152,    38,    39,    -1,
      -1,    -1,    -1,    -1,    -1,   161,    -1,   163,    -1,    -1,
      -1,   167,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    63,    -1,    -1,    -1,    -1,    -1,   184,    -1,
      -1,   187,    -1,    -1,    -1,    -1,    -1,    -1,   194,   195,
      -1,    -1,    -1,    -1,    -1,   201,   202,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   212,    -1,    -1,   215,
      -1,   217,   218,    -1,    -1,   221,    -1,   223,    -1,   225,
      -1,    -1,   228,    -1,    -1,   231,   232,   233,    -1,    -1,
     236,    -1,   238,    -1,    -1,   241,    -1,    -1,     3,     4,
      -1,     6,    -1,    -1,    -1,   251,   252,   253,    -1,    -1,
      15,    -1,    17,    -1,    -1,    20,    -1,    -1,    -1,    -1,
      -1,   152,    -1,    -1,    -1,    -1,    -1,    32,    33,    -1,
     161,    -1,   163,    38,    39,    -1,   167,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   183,   184,    -1,    -1,   187,    -1,    63,    -1,
      -1,    -1,    -1,   194,   195,    -1,    -1,    -1,    -1,    -1,
     201,   202,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   212,    -1,    -1,   215,    -1,   217,   218,    -1,    -1,
     221,    -1,   223,    -1,   225,    -1,    -1,   228,    -1,    -1,
     231,   232,   233,    -1,    -1,   236,    -1,   238,    -1,    -1,
     241,    -1,    -1,    -1,     3,     4,    -1,     6,    -1,    -1,
     251,   252,   253,    -1,    -1,    -1,    15,    -1,    17,    -1,
      -1,    20,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    32,    33,    -1,    -1,   152,    -1,    38,
      39,    -1,    -1,    -1,    -1,    -1,   161,    -1,   163,    -1,
      -1,    -1,   167,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   178,    63,    -1,    -1,    -1,    -1,   184,
      -1,    -1,   187,    -1,    -1,    -1,    -1,    -1,    -1,   194,
     195,    -1,    -1,    -1,    -1,    -1,   201,   202,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   212,    -1,    -1,
     215,    -1,   217,   218,    -1,    -1,   221,    -1,   223,    -1,
     225,    -1,    -1,   228,    -1,    -1,   231,   232,   233,    -1,
      -1,   236,    -1,   238,    -1,    -1,   241,    -1,    -1,    -1,
       3,     4,    -1,     6,    -1,    -1,   251,   252,   253,    -1,
      -1,    -1,    15,    -1,    17,    -1,    -1,    20,    -1,    -1,
      -1,   150,    -1,   152,    -1,    -1,    -1,    -1,    -1,    32,
      33,    -1,   161,    -1,   163,    38,    39,    -1,   167,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   184,    -1,    -1,   187,    -1,
      63,    -1,    -1,    -1,    -1,   194,   195,    -1,    -1,    -1,
      -1,    -1,   201,   202,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   212,    -1,    -1,   215,    -1,   217,   218,
      -1,    -1,   221,    -1,   223,    -1,   225,    -1,    -1,   228,
      -1,    -1,   231,   232,   233,    -1,    -1,   236,    -1,   238,
      -1,    -1,   241,    -1,    -1,     3,     4,    -1,     6,    -1,
      -1,    -1,   251,   252,   253,    -1,    -1,    15,    -1,    17,
      -1,    -1,    20,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    32,    33,    -1,    -1,    -1,   152,
      38,    39,    -1,    -1,    -1,    -1,    -1,    -1,   161,    -1,
     163,    -1,    -1,    -1,   167,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    63,    -1,    -1,    -1,    -1,
     183,   184,    -1,    -1,   187,    -1,    -1,    -1,    -1,    -1,
      -1,   194,   195,    -1,    -1,    -1,    -1,    -1,   201,   202,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   212,
      -1,    -1,   215,    -1,   217,   218,    -1,    -1,   221,    -1,
     223,    -1,   225,    -1,    -1,   228,    -1,    -1,   231,   232,
     233,    -1,    -1,   236,    -1,   238,    -1,    -1,   241,    -1,
      -1,     3,     4,    -1,     6,    -1,    -1,    -1,   251,   252,
     253,    -1,    -1,    15,    -1,    17,    -1,    -1,    20,    -1,
      -1,    -1,    -1,    -1,   152,    -1,    -1,    -1,    -1,    -1,
      32,    33,    -1,   161,    -1,   163,    38,    39,    -1,   167,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   183,   184,    -1,    -1,   187,
      -1,    63,    -1,    -1,    -1,    -1,   194,   195,    -1,    -1,
      -1,    -1,    -1,   201,   202,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   212,    -1,    -1,   215,    -1,   217,
     218,    -1,    -1,   221,    -1,   223,    -1,   225,    -1,    -1,
     228,    -1,    -1,   231,   232,   233,    -1,    -1,   236,    -1,
     238,    -1,    -1,   241,    -1,    -1,     3,     4,    -1,     6,
      -1,    -1,    -1,   251,   252,   253,    -1,    -1,    15,    -1,
      17,    -1,    -1,    20,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    32,    33,    -1,    -1,    -1,
     152,    38,    39,    -1,    -1,    -1,    -1,    -1,    -1,   161,
      -1,   163,    -1,    -1,    -1,   167,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    63,    -1,    -1,    -1,
      -1,    -1,   184,    -1,    -1,   187,    -1,    -1,    -1,    -1,
      -1,    -1,   194,   195,    -1,    -1,    -1,    -1,    -1,   201,
     202,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     212,    -1,    -1,   215,    -1,   217,   218,    -1,    -1,   221,
      -1,   223,    -1,   225,    -1,    -1,   228,    -1,    -1,   231,
     232,   233,    -1,    -1,   236,    -1,   238,    -1,    -1,   241,
      -1,    -1,     3,     4,    -1,     6,    -1,    -1,    -1,   251,
     252,   253,    -1,    -1,    15,    -1,    17,    -1,    -1,    20,
      -1,    -1,    -1,    -1,    -1,   152,    -1,    -1,    -1,    -1,
      -1,    32,    33,    -1,   161,    -1,   163,    38,    39,    -1,
     167,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   184,    -1,    -1,
     187,    -1,    63,    -1,    -1,    -1,    -1,   194,   195,    -1,
      -1,    -1,    -1,    -1,   201,   202,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   212,    -1,    -1,   215,    -1,
     217,   218,    -1,    -1,   221,    -1,   223,    -1,   225,    -1,
      -1,   228,    -1,    -1,   231,   232,   233,    -1,    -1,   236,
      -1,   238,    -1,    -1,   241,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   251,   252,   253,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   152,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     161,    -1,   163,    -1,    -1,    -1,   167,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   184,    -1,    -1,   187,    -1,    -1,    -1,
      -1,    -1,    -1,   194,   195,    -1,    -1,    -1,    -1,    -1,
     201,   202,     0,     1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   212,    -1,    -1,   215,    -1,   217,   218,    16,    -1,
     221,    -1,   223,    -1,   225,    -1,    -1,   228,    -1,    -1,
     231,   232,    30,    31,    -1,   236,    -1,    35,    -1,    37,
     241,    -1,    40,    41,    42,    43,    44,    45,    46,    47,
     251,   252,   253,    -1,    -1,    -1,    54,    55,    -1,    -1,
      58,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    75,    76,    77,
      78,    -1,    80,    81,    82,    83,    84,    85,    86,    -1,
      -1,    89,    -1,    -1,    92,    -1,    94,    95,    -1,    97,
      98,    -1,    -1,    -1,   102,   103,   104,   105,   106,   107,
     112,    -1,   110,    -1,    -1,    -1,    -1,    -1,    -1,   117,
     118,    -1,    -1,   121,    -1,    -1,   124,    -1,   126,   127,
      -1,    -1,   134,    -1,   132,    -1,    -1,    -1,   136,    -1,
     142,   143,    -1,    -1,    -1,    -1,   148,    -1,   150,    -1,
      -1,    -1,    -1,    -1,    -1,   157,    -1,    -1,   160,    -1,
     162,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     172,   173,    -1,    -1,    -1,    -1,    -1,    -1,   176,    -1,
     178,    -1,    -1,   181,    -1,    -1,    -1,    -1,    -1,    -1,
     192,    -1,   190,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   210,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     222,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   235,    -1,    -1,    -1,    -1,    -1,    -1,
     242,    -1,   244,    -1,    -1,    -1,   248,   249
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
{
       0,     1,    30,    31,    35,    37,    40,    41,    42,    43,
      44,    45,    46,    47,    54,    55,    58,    75,    76,    77,
      78,    80,    81,    82,    83,    84,    85,    86,    89,    92,
      94,    95,    97,    98,   102,   103,   104,   105,   106,   107,
     110,   117,   118,   121,   124,   126,   127,   132,   136,   176,
     178,   181,   190,   258,   269,   270,   271,   272,   281,   288,
     308,   309,   318,   319,   320,   322,   323,   324,   325,   326,
     336,   356,   360,   406,   407,   408,   411,   412,   430,   464,
     465,   466,   467,   469,   473,   475,     4,   458,     6,   455,
     456,   458,   458,   458,   455,   455,   458,   458,     6,   457,
     458,   458,   463,   468,   468,   455,   457,   457,   457,   457,
       6,   357,   358,   395,   458,   458,   455,     3,   483,   455,
     455,   455,   455,   455,   455,   310,   457,   455,     6,   453,
     454,   458,   409,   458,   455,     4,     6,   461,    93,   145,
     151,   164,   169,   178,   181,   185,   191,   221,   229,   327,
     329,   330,   331,   188,   439,   455,   327,   329,     0,    16,
     119,   120,   470,    36,   241,   226,   237,   241,   242,   163,
      56,    57,    64,    65,    66,   171,   205,   220,   289,   290,
     291,   294,   297,   300,   301,   302,   305,   241,    73,    74,
     226,   237,   243,   243,   243,   243,   359,   360,   163,   230,
     163,   163,   337,    90,   199,   260,   455,    96,   116,   413,
     241,   241,   226,   237,   245,   133,   321,   163,   332,   332,
     207,   243,   227,     3,   138,   180,   221,   440,    49,    50,
      51,    52,    53,   219,   261,   245,   243,   466,     6,   458,
     471,   472,     6,   458,     6,   458,   458,   458,     6,     3,
       4,     6,    15,    17,    20,    32,    33,    38,    39,    63,
     150,   152,   161,   163,   167,   184,   187,   194,   195,   201,
     202,   212,   215,   217,   218,   221,   223,   225,   228,   231,
     232,   233,   236,   238,   241,   251,   252,   253,   402,   414,
     415,   416,   417,   418,   438,   443,   444,   447,   458,   460,
     474,   476,   480,   481,   482,   109,   113,   138,   163,   180,
     186,   340,   341,   346,   348,   163,   306,   307,   458,     3,
     163,   287,   299,   348,   350,   458,   163,   296,   458,   163,
     287,   292,   227,   458,     6,   458,   458,   280,   455,   280,
     280,   280,   360,   286,   287,   455,   286,   237,   338,   397,
     400,   453,   458,   239,     4,   459,   122,   163,   166,   235,
     370,   371,   372,   373,   374,   381,   383,   443,   450,   163,
     313,   458,   410,   458,     6,   458,   458,   409,   333,   397,
     175,   334,   335,   395,   455,   331,   431,   183,   267,   268,
     443,   267,   267,   267,   237,   263,   264,   266,   458,   262,
     263,   265,    90,   199,   259,   334,   455,   241,   241,   227,
      34,   241,   226,   163,   241,     6,   163,   163,   139,   170,
     177,   194,   208,   217,   228,   403,   404,   178,   443,   163,
     163,   163,   206,   216,   445,   446,   163,   163,   438,   163,
     163,   438,   438,   163,   163,   163,   163,   481,   163,   481,
       3,   404,   404,   150,   227,   174,   241,    67,    68,    69,
      70,    71,    72,   195,   204,   233,   238,   449,    79,   163,
     163,   163,   303,   348,   163,   163,    59,   304,   306,   227,
     298,   299,    62,   125,   128,   129,   130,   137,   141,   146,
     153,   155,   156,   158,   179,   189,   193,   200,   202,   211,
     213,   251,   254,   386,   387,   388,   389,   391,   429,   295,
     296,   292,   293,   246,   290,   241,   226,   163,   163,   163,
     163,   150,   227,   150,   400,   150,   227,   241,   174,   241,
     396,   178,   428,   437,   438,   370,   443,   438,   373,   244,
     222,   112,   134,   142,   143,   148,   157,   160,   162,   172,
     173,   192,   210,   235,   242,   248,   249,   380,   382,   314,
     315,   458,   182,   311,   437,   245,   241,   226,   150,   227,
     227,   207,   441,   442,   443,   150,   227,   150,   264,   150,
     227,   241,   396,   227,   172,   459,   370,   245,   458,   458,
     472,   458,     6,   458,   150,   447,   458,    21,   447,   447,
     245,   439,   150,   152,   443,   448,   474,   138,   180,   221,
     384,   447,   443,   370,   247,   446,   447,   447,   447,   384,
     447,   384,   384,   384,   245,   163,   245,   443,     3,   163,
     233,   238,   477,   479,   195,   253,   458,   443,   443,   443,
     443,   386,   343,   345,   397,   347,   397,   347,   150,   227,
     304,   347,   370,   427,   458,   150,   307,   150,   227,   163,
     163,   163,   404,   404,   163,   163,   163,   163,   163,   163,
     163,   163,    99,   100,   101,   154,   349,   351,   150,   227,
     150,   227,   458,   458,     6,   458,   284,   285,   458,   284,
     284,   284,   115,   282,   287,    48,    65,    66,   108,   242,
     273,   274,   275,   397,   195,   458,     3,   458,   439,    87,
     339,   150,   371,   372,   378,   481,   378,   378,   378,   163,
     438,   183,   443,   378,   163,   438,   378,   111,   147,   149,
     443,   150,   227,   241,   312,   410,   458,     6,   458,   397,
     335,   334,   227,   432,   239,   458,   268,   172,   263,   195,
     458,   265,   268,   334,   241,   241,   150,   241,   150,   150,
     139,   170,   177,   194,   208,   217,   228,   405,   440,   227,
     404,   227,   150,   227,   443,   150,   214,   150,   150,   150,
     443,   150,   443,   443,   443,   405,     3,   405,   477,   159,
     195,   204,   227,   233,   234,   238,   478,     3,   174,   241,
     150,   227,   150,   227,   150,   348,   150,   150,   299,     3,
     392,   392,     3,   245,   163,   245,     3,   393,     3,     3,
       3,   393,   393,     3,     3,     6,   402,    91,   113,   123,
     138,   144,   180,   186,   342,   352,   353,   354,   355,   296,
     292,   241,   150,   227,   203,   224,   150,   150,   150,   273,
       3,     3,     4,   276,   275,   396,   159,   227,   241,   440,
     165,   375,   165,   377,   165,   376,   375,   233,   402,   451,
     452,   474,   377,   451,   376,   443,   315,   458,   163,   241,
     442,   462,   458,   163,   241,   396,    88,   239,   328,   458,
     458,   458,   163,   441,   404,   245,   404,   404,   150,   443,
     150,   150,   150,   150,   150,   150,   477,   477,   477,   458,
     342,   397,   397,   304,   150,   150,   150,   227,   405,     3,
     405,   227,   390,   150,   150,   227,   150,   150,   390,   150,
     150,   344,   455,   163,   354,   304,   458,    28,    29,   242,
     250,   277,   278,   279,   285,   277,   277,   277,   282,     3,
     458,   441,   379,   402,   379,   379,     3,   460,   150,   227,
     150,   222,   183,   316,   317,   443,   458,   207,   363,   367,
     267,   458,   395,   174,     3,   367,   245,   405,   245,   245,
     245,   159,   159,   227,   174,     3,   150,     3,   394,   150,
       3,   150,   163,   427,   276,     3,   279,   159,   396,   367,
     452,   443,   150,   227,   364,   366,   455,   140,   168,   199,
     361,   362,   368,   369,   424,   198,   434,   150,   396,   477,
     150,   150,   405,   405,   405,   405,   477,   477,   150,   245,
     150,   345,   150,   317,    22,    25,   227,   239,   401,   458,
       3,   237,   253,   398,   399,   425,   426,   453,   458,   370,
     370,   369,   361,   138,   180,   221,   385,   135,   196,   419,
     435,   159,   227,   159,   159,   227,   405,   150,   163,   364,
     365,   365,   197,   366,   401,   399,   227,   241,   396,   178,
     433,   436,   458,   240,   135,   477,   477,   364,   243,   243,
     163,   366,   426,   195,   458,   439,   115,   283,     3,   398,
     420,   421,   422,   436,   159,   159,   150,   370,   370,   364,
     396,   440,   227,   203,   224,   423,   283,   150,   441,   421,
     367,   434
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
#line 406 "sql.yacc"
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
#line 432 "sql.yacc"
    {
		(yyval.ptr)=0;
	}
    break;

  case 4:

/* Line 1455 of yacc.c  */
#line 435 "sql.yacc"
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
#line 452 "sql.yacc"
    {
		(yyval.ptr)=A4GL_new_select_list_item_expr((yyvsp[(2) - (2)].s_select_list_item));
	}
    break;

  case 6:

/* Line 1455 of yacc.c  */
#line 457 "sql.yacc"
    {
		(yyval.ptr)=0;
	}
    break;

  case 7:

/* Line 1455 of yacc.c  */
#line 460 "sql.yacc"
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
#line 477 "sql.yacc"
    {
		 (yyval.ptr)=A4GL_new_select_list_item_expr((yyvsp[(2) - (2)].s_select_list_item));
	}
    break;

  case 9:

/* Line 1455 of yacc.c  */
#line 483 "sql.yacc"
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
#line 492 "sql.yacc"
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
#line 501 "sql.yacc"
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
#line 510 "sql.yacc"
    {
		(yyval.update_cmd)=(yyvsp[(2) - (2)].update_cmd);
		add_feature("UPDATE_COLUMN_EQ_VALUE_LIST");
    }
    break;

  case 13:

/* Line 1455 of yacc.c  */
#line 517 "sql.yacc"
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
#line 532 "sql.yacc"
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
#line 587 "sql.yacc"
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
#line 594 "sql.yacc"
    {
		(yyval.update_cmd)=(yyvsp[(1) - (3)].update_cmd);
		add_str_list((yyval.update_cmd)->column_list, (yyvsp[(3) - (3)].upd_pair)->column_name);
		local_add_select_list_item_list((yyval.update_cmd)->value_list, (yyvsp[(3) - (3)].upd_pair)->value);
	}
    break;

  case 17:

/* Line 1455 of yacc.c  */
#line 605 "sql.yacc"
    {
                strcpy((yyval.str),(yyvsp[(1) - (1)].str));
        }
    break;

  case 18:

/* Line 1455 of yacc.c  */
#line 608 "sql.yacc"
    {
                strcpy((yyval.str),(yyvsp[(2) - (2)].str));
        }
    break;

  case 19:

/* Line 1455 of yacc.c  */
#line 613 "sql.yacc"
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
#line 620 "sql.yacc"
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
#line 637 "sql.yacc"
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
#line 654 "sql.yacc"
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
#line 675 "sql.yacc"
    {
		(yyval.upd_pair)=malloc(sizeof(struct s_update_pair));
		(yyval.upd_pair)->column_name=acl_strdup((yyvsp[(1) - (3)].str));
		(yyval.upd_pair)->value=(yyvsp[(3) - (3)].s_select_list_item);
	}
    break;

  case 24:

/* Line 1455 of yacc.c  */
#line 684 "sql.yacc"
    {
			(yyval.str_list)=new_str_list((yyvsp[(1) - (1)].str));
		}
    break;

  case 25:

/* Line 1455 of yacc.c  */
#line 687 "sql.yacc"
    {
			(yyval.str_list)=add_str_list((yyvsp[(1) - (3)].str_list), (yyvsp[(3) - (3)].str));
		}
    break;

  case 26:

/* Line 1455 of yacc.c  */
#line 695 "sql.yacc"
    { 
		(yyval.s_select_list_item_list)=local_new_select_list_item_list((yyvsp[(1) - (1)].s_select_list_item));
	}
    break;

  case 27:

/* Line 1455 of yacc.c  */
#line 698 "sql.yacc"
    { 
		(yyval.s_select_list_item_list)=local_add_select_list_item_list((yyvsp[(1) - (3)].s_select_list_item_list),(yyvsp[(3) - (3)].s_select_list_item));
	}
    break;

  case 28:

/* Line 1455 of yacc.c  */
#line 706 "sql.yacc"
    {(yyval.s_select_list_item)=(yyvsp[(1) - (1)].s_select_list_item);}
    break;

  case 29:

/* Line 1455 of yacc.c  */
#line 707 "sql.yacc"
    {(yyval.s_select_list_item)=new_select_list_item_builtin_const(E_SLI_BUILTIN_CONST_NULL); }
    break;

  case 30:

/* Line 1455 of yacc.c  */
#line 714 "sql.yacc"
    { (yyval.sql_string)=make_sql_string_and_free(acl_strdup((yyvsp[(1) - (1)].str)), NULL);}
    break;

  case 31:

/* Line 1455 of yacc.c  */
#line 717 "sql.yacc"
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
#line 725 "sql.yacc"
    {SPRINTF2((yyval.str),"%s %s ",(yyvsp[(1) - (2)].str),(yyvsp[(2) - (2)].str));
			add_feature("DROP_VIEW");
}
    break;

  case 33:

/* Line 1455 of yacc.c  */
#line 728 "sql.yacc"
    {SPRINTF2((yyval.str),"%s %s",(yyvsp[(1) - (2)].str),(yyvsp[(2) - (2)].str));
		if (strchr((yyvsp[(2) - (2)].str),'@') || strchr((yyvsp[(2) - (2)].str),':')) add_feature("DROP_INDEX_QUALIFIED_PATH");
			add_feature("DROP_INDEX");
}
    break;

  case 34:

/* Line 1455 of yacc.c  */
#line 732 "sql.yacc"
    {SPRINTF2((yyval.str),"%s %s",(yyvsp[(1) - (2)].str),(yyvsp[(2) - (2)].str));
			add_feature("DROP_TRIGGER");
}
    break;

  case 35:

/* Line 1455 of yacc.c  */
#line 738 "sql.yacc"
    {(yyval.sql_string)=acl_strdup((yyvsp[(1) - (1)].str));}
    break;

  case 36:

/* Line 1455 of yacc.c  */
#line 739 "sql.yacc"
    {(yyval.sql_string)=(yyvsp[(1) - (1)].sql_string);}
    break;

  case 37:

/* Line 1455 of yacc.c  */
#line 743 "sql.yacc"
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
#line 753 "sql.yacc"
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
#line 767 "sql.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 40:

/* Line 1455 of yacc.c  */
#line 768 "sql.yacc"
    {strcpy((yyval.str),(yyvsp[(1) - (1)].str));}
    break;

  case 42:

/* Line 1455 of yacc.c  */
#line 773 "sql.yacc"
    {SPRINTF2((yyval.str),"%s%s",(yyvsp[(1) - (2)].str),(yyvsp[(2) - (2)].str)); }
    break;

  case 43:

/* Line 1455 of yacc.c  */
#line 778 "sql.yacc"
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
#line 786 "sql.yacc"
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
#line 794 "sql.yacc"
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
#line 802 "sql.yacc"
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
#line 810 "sql.yacc"
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
#line 822 "sql.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 50:

/* Line 1455 of yacc.c  */
#line 822 "sql.yacc"
    {strcpy((yyval.str),(yyvsp[(1) - (1)].str));}
    break;

  case 52:

/* Line 1455 of yacc.c  */
#line 826 "sql.yacc"
    {SPRINTF2((yyval.str),"%s%s",(yyvsp[(1) - (2)].str),(yyvsp[(2) - (2)].str));}
    break;

  case 53:

/* Line 1455 of yacc.c  */
#line 830 "sql.yacc"
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
#line 837 "sql.yacc"
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
#line 844 "sql.yacc"
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
#line 851 "sql.yacc"
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
#line 860 "sql.yacc"
    { strcpy(last_tmp_name,(yyvsp[(1) - (1)].str)); }
    break;

  case 58:

/* Line 1455 of yacc.c  */
#line 864 "sql.yacc"
    {SPRINTF7((yyval.str),"CREATE UNIQUE INDEX %s %s %s %s %s %s %s",(yyvsp[(2) - (8)].str),(yyvsp[(3) - (8)].str),(yyvsp[(4) - (8)].str),(yyvsp[(5) - (8)].str),(yyvsp[(6) - (8)].str),(yyvsp[(7) - (8)].str),(yyvsp[(8) - (8)].str));
		add_feature("CREATE_INDEX");
		add_feature("CREATE_INDEX_UNIQUE");
		if (strchr((yyvsp[(2) - (8)].str),'@') || strchr((yyvsp[(2) - (8)].str),':')) add_feature("CREATE_INDEX_QUALIFIED_PATH");
		if (strchr((yyvsp[(6) - (8)].str),',')) { add_feature("CREATE_INDEX_COMPOSITE"); }
	
}
    break;

  case 59:

/* Line 1455 of yacc.c  */
#line 871 "sql.yacc"
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
#line 883 "sql.yacc"
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
#line 894 "sql.yacc"
    {
		if (strchr((yyvsp[(2) - (8)].str),'@') || strchr((yyvsp[(2) - (8)].str),':')) add_feature("CREATE_INDEX_QUALIFIED_PATH");
		if (strchr((yyvsp[(6) - (8)].str),',')) { add_feature("CREATE_INDEX_COMPOSITE"); }
			add_feature("CREATE_INDEX");
			SPRINTF7((yyval.str)," CREATE INDEX %s %s %s %s %s %s %s",(yyvsp[(2) - (8)].str),(yyvsp[(3) - (8)].str),(yyvsp[(4) - (8)].str),(yyvsp[(5) - (8)].str),(yyvsp[(6) - (8)].str),(yyvsp[(7) - (8)].str),(yyvsp[(8) - (8)].str));
	}
    break;

  case 62:

/* Line 1455 of yacc.c  */
#line 900 "sql.yacc"
    {
		add_feature("CREATE_DATABASE");
		a4gl_yyerror("You cannot create a database from within Aubit4gl - if the target database allows - prepare and execute it manually");
	}
    break;

  case 63:

/* Line 1455 of yacc.c  */
#line 904 "sql.yacc"
    {
		add_feature("DROP_DATABASE");
		a4gl_yyerror("You cannot drop a database from within Aubit4gl - if the target database allows - prepare and execute it manually");
	}
    break;

  case 64:

/* Line 1455 of yacc.c  */
#line 908 "sql.yacc"
    { 
		if (strchr((yyvsp[(2) - (4)].str),'@') || strchr((yyvsp[(2) - (4)].str),':')) add_feature("CREATE_SYNONYM_QUALIFIED_PATH");
			add_feature("CREATE_SYNONYM");
			SPRINTF3((yyval.str),"%s %s FOR %s",(yyvsp[(1) - (4)].str),(yyvsp[(2) - (4)].str),(yyvsp[(4) - (4)].str)); 
	}
    break;

  case 65:

/* Line 1455 of yacc.c  */
#line 913 "sql.yacc"
    { 
		add_feature("CREATE_AUDIT");
		SPRINTF2((yyval.str),"CREATE AUDIT FOR %s IN '%s'",(yyvsp[(2) - (4)].str),A4GL_strip_quotes((yyvsp[(4) - (4)].str))); 
	}
    break;

  case 66:

/* Line 1455 of yacc.c  */
#line 917 "sql.yacc"
    { 
		add_feature("DROP_AUDIT");
		SPRINTF1((yyval.str),"DROP AUDIT FOR %s",(yyvsp[(2) - (2)].str)); }
    break;

  case 67:

/* Line 1455 of yacc.c  */
#line 920 "sql.yacc"
    { 
		if (strchr((yyvsp[(2) - (2)].str),'@') || strchr((yyvsp[(2) - (2)].str),':')) add_feature("DROP_SYNONYM_QUALIFIED_PATH");
		add_feature("DROP_SYNONYM");
		SPRINTF2((yyval.str),"%s %s",(yyvsp[(1) - (2)].str),(yyvsp[(2) - (2)].str)); }
    break;

  case 68:

/* Line 1455 of yacc.c  */
#line 924 "sql.yacc"
    { 
		add_feature("RECOVER_TABLE");
		SPRINTF1((yyval.str),"RECOVER TABLE %s",(yyvsp[(2) - (2)].str)); }
    break;

  case 69:

/* Line 1455 of yacc.c  */
#line 927 "sql.yacc"
    { 
		add_feature("ROLLFORWARD_DATABASE");
		SPRINTF1((yyval.str),"ROLLFORWARD DATABASE %s",(yyvsp[(2) - (2)].str)); }
    break;

  case 70:

/* Line 1455 of yacc.c  */
#line 934 "sql.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 71:

/* Line 1455 of yacc.c  */
#line 935 "sql.yacc"
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
#line 945 "sql.yacc"
    {(yyval.integer_val)=0;}
    break;

  case 73:

/* Line 1455 of yacc.c  */
#line 946 "sql.yacc"
    { (yyval.integer_val)=1;}
    break;

  case 75:

/* Line 1455 of yacc.c  */
#line 951 "sql.yacc"
    {SPRINTF2((yyval.str),"%s,%s",(yyvsp[(1) - (3)].str),(yyvsp[(3) - (3)].str));}
    break;

  case 76:

/* Line 1455 of yacc.c  */
#line 955 "sql.yacc"
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
#line 964 "sql.yacc"
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
#line 973 "sql.yacc"
    {
		strcpy((yyval.str),A4GL_confirm_colname(last_tmp_name,(yyvsp[(1) - (1)].str)));
}
    break;

  case 79:

/* Line 1455 of yacc.c  */
#line 980 "sql.yacc"
    {
		(yyval.sql_string)=(yyvsp[(1) - (1)].sql_string);
	}
    break;

  case 80:

/* Line 1455 of yacc.c  */
#line 983 "sql.yacc"
    {
		(yyval.sql_string)=make_sql_string_and_free((yyvsp[(1) - (3)].sql_string),kw_comma,strdup("\n"),(yyvsp[(3) - (3)].sql_string),NULL);
	}
    break;

  case 81:

/* Line 1455 of yacc.c  */
#line 989 "sql.yacc"
    {
		(yyval.sql_string)=make_sql_string_and_free(strdup("   "),(yyvsp[(1) - (1)].sql_string),NULL);
	}
    break;

  case 82:

/* Line 1455 of yacc.c  */
#line 992 "sql.yacc"
    {
		(yyval.sql_string)=make_sql_string_and_free(strdup("   "),(yyvsp[(1) - (1)].sql_string),NULL);
	}
    break;

  case 83:

/* Line 1455 of yacc.c  */
#line 1003 "sql.yacc"
    {
		add_feature("ALTER_TABLE");
	(yyval.sql_string)=make_sql_string_and_free(acl_strdup((yyvsp[(1) - (3)].str)),kw_space,acl_strdup((yyvsp[(2) - (3)].str)),kw_space,(yyvsp[(3) - (3)].sql_string),NULL);
	}
    break;

  case 84:

/* Line 1455 of yacc.c  */
#line 1007 "sql.yacc"
    {
		add_feature("CLUSTER_INDEX");
		add_feature("ALTER_INDEX_CLUSTER");
		(yyval.sql_string)=make_sql_string_and_free(acl_strdup("ALTER INDEX "),acl_strdup((yyvsp[(2) - (3)].str)),acl_strdup(" TO CLUSTER"),NULL);
		}
    break;

  case 85:

/* Line 1455 of yacc.c  */
#line 1012 "sql.yacc"
    {
		add_feature("ALTER_INDEX_NOT_CLUSTER");
		(yyval.sql_string)=make_sql_string_and_free(acl_strdup("ALTER INDEX "),acl_strdup((yyvsp[(2) - (3)].str)),acl_strdup(" TO NOT CLUSTER"),NULL);
		}
    break;

  case 86:

/* Line 1455 of yacc.c  */
#line 1019 "sql.yacc"
    {
		(yyval.sql_string)=(yyvsp[(1) - (1)].sql_string);
	}
    break;

  case 87:

/* Line 1455 of yacc.c  */
#line 1022 "sql.yacc"
    {
		(yyval.sql_string)=make_sql_string_and_free((yyvsp[(1) - (3)].sql_string),kw_comma,(yyvsp[(3) - (3)].sql_string),NULL);
	}
    break;

  case 88:

/* Line 1455 of yacc.c  */
#line 1031 "sql.yacc"
    {
		(yyval.sql_string)=(yyvsp[(1) - (1)].sql_string);
	}
    break;

  case 89:

/* Line 1455 of yacc.c  */
#line 1034 "sql.yacc"
    {
	add_feature("ALTER_TABLE_DROP");
		(yyval.sql_string)=acl_strdup((yyvsp[(1) - (1)].str));
	}
    break;

  case 90:

/* Line 1455 of yacc.c  */
#line 1038 "sql.yacc"
    {
	add_feature("ALTER_TABLE_MODIFY");
		(yyval.sql_string)=(yyvsp[(1) - (1)].sql_string);
	}
    break;

  case 91:

/* Line 1455 of yacc.c  */
#line 1042 "sql.yacc"
    {
		add_feature("ALTER_TABLE_ADD_CONSTRAINT");
		(yyval.sql_string)=acl_strdup((yyvsp[(1) - (1)].str));
	}
    break;

  case 92:

/* Line 1455 of yacc.c  */
#line 1046 "sql.yacc"
    {
		add_feature("ALTER_TABLE_DROP_CONSTRAINT");
		(yyval.sql_string)=acl_strdup((yyvsp[(1) - (1)].str));
	}
    break;

  case 93:

/* Line 1455 of yacc.c  */
#line 1050 "sql.yacc"
    {
		add_feature("ALTER_TABLE_MODIFY_NEXT");
		(yyval.sql_string)=acl_strdup((yyvsp[(1) - (1)].str));
	}
    break;

  case 94:

/* Line 1455 of yacc.c  */
#line 1054 "sql.yacc"
    {
		add_feature("ALTER_TABLE_LOCK_MODE");
		(yyval.sql_string)=acl_strdup((yyvsp[(1) - (1)].str));
	}
    break;

  case 95:

/* Line 1455 of yacc.c  */
#line 1062 "sql.yacc"
    {
		add_feature("ALTER_TABLE_ADD");
		(yyval.sql_string)=make_sql_string_and_free(acl_strdup("ADD "),(yyvsp[(2) - (2)].sql_string),NULL);
	}
    break;

  case 96:

/* Line 1455 of yacc.c  */
#line 1066 "sql.yacc"
    {
		add_feature("ALTER_TABLE_ADD");
		(yyval.sql_string)=make_sql_string_and_free(acl_strdup("ADD "),kw_ob,(yyvsp[(3) - (4)].sql_string),kw_cb,NULL);
	}
    break;

  case 97:

/* Line 1455 of yacc.c  */
#line 1074 "sql.yacc"
    {
		(yyval.sql_string)=(yyvsp[(1) - (1)].sql_string);
	}
    break;

  case 98:

/* Line 1455 of yacc.c  */
#line 1077 "sql.yacc"
    {
		add_feature("ALTER_TABLE_ADD_BEFORE");
		(yyval.sql_string)=make_sql_string_and_free((yyvsp[(1) - (3)].sql_string),acl_strdup(" BEFORE "),acl_strdup((yyvsp[(3) - (3)].str)),NULL);
	}
    break;

  case 99:

/* Line 1455 of yacc.c  */
#line 1084 "sql.yacc"
    {
		(yyval.sql_string)=(yyvsp[(1) - (1)].sql_string);
	}
    break;

  case 100:

/* Line 1455 of yacc.c  */
#line 1087 "sql.yacc"
    {
		(yyval.sql_string)=make_sql_string_and_free((yyvsp[(1) - (3)].sql_string),kw_comma,(yyvsp[(3) - (3)].sql_string),NULL);
	}
    break;

  case 101:

/* Line 1455 of yacc.c  */
#line 1094 "sql.yacc"
    {
		SPRINTF1((yyval.str),"DROP %s",(yyvsp[(2) - (2)].str));
	}
    break;

  case 102:

/* Line 1455 of yacc.c  */
#line 1097 "sql.yacc"
    {
		SPRINTF1((yyval.str),"DROP (%s)",(yyvsp[(3) - (4)].str));
	}
    break;

  case 104:

/* Line 1455 of yacc.c  */
#line 1105 "sql.yacc"
    {
		SPRINTF2((yyval.str),"%s,%s",(yyvsp[(1) - (3)].str),(yyvsp[(3) - (3)].str));
	}
    break;

  case 106:

/* Line 1455 of yacc.c  */
#line 1114 "sql.yacc"
    {
		(yyval.sql_string)=make_sql_string_and_free(acl_strdup("MODIFY "),(yyvsp[(2) - (2)].sql_string),NULL);
	}
    break;

  case 107:

/* Line 1455 of yacc.c  */
#line 1117 "sql.yacc"
    {
		(yyval.sql_string)=make_sql_string_and_free(acl_strdup("MODIFY "),kw_ob,(yyvsp[(3) - (4)].sql_string),kw_cb,NULL);
	}
    break;

  case 108:

/* Line 1455 of yacc.c  */
#line 1123 "sql.yacc"
    {
		(yyval.sql_string)=(yyvsp[(1) - (1)].sql_string);
	}
    break;

  case 109:

/* Line 1455 of yacc.c  */
#line 1126 "sql.yacc"
    {
		(yyval.sql_string)=make_sql_string_and_free((yyvsp[(1) - (3)].sql_string),kw_comma,(yyvsp[(3) - (3)].sql_string),NULL);
	}
    break;

  case 110:

/* Line 1455 of yacc.c  */
#line 1132 "sql.yacc"
    {
		(yyval.sql_string)=(yyvsp[(1) - (1)].sql_string);
	}
    break;

  case 111:

/* Line 1455 of yacc.c  */
#line 1139 "sql.yacc"
    {strcpy((yyval.str),"LOCK MODE (PAGE)");}
    break;

  case 112:

/* Line 1455 of yacc.c  */
#line 1140 "sql.yacc"
    {strcpy((yyval.str),"LOCK MODE (ROW)");}
    break;

  case 113:

/* Line 1455 of yacc.c  */
#line 1144 "sql.yacc"
    {
		add_feature("DDL_NEXT_SIZE");
		SPRINTF1((yyval.str),"MODIFY NEXT SIZE %d",atoi((yyvsp[(2) - (2)].str)));
	}
    break;

  case 114:

/* Line 1455 of yacc.c  */
#line 1152 "sql.yacc"
    {
		add_feature("DDL_CONSTRAINT");
		SPRINTF2((yyval.str),"ADD CONSTRAINT %s%s",(yyvsp[(2) - (3)].sql_string),(yyvsp[(3) - (3)].str));
	}
    break;

  case 115:

/* Line 1455 of yacc.c  */
#line 1156 "sql.yacc"
    {
		add_feature("ADD_CONSTRAINT");
		SPRINTF1((yyval.str),"ADD CONSTRAINT (%s)",(yyvsp[(3) - (4)].sql_string));
	}
    break;

  case 116:

/* Line 1455 of yacc.c  */
#line 1163 "sql.yacc"
    {
		(yyval.sql_string)=make_sql_string_and_free((yyvsp[(1) - (2)].sql_string),acl_strdup((yyvsp[(2) - (2)].str)),NULL);
}
    break;

  case 117:

/* Line 1455 of yacc.c  */
#line 1165 "sql.yacc"
    {
	(yyval.sql_string)=make_sql_string_and_free((yyvsp[(1) - (4)].sql_string),kw_comma,(yyvsp[(3) - (4)].sql_string),acl_strdup((yyvsp[(4) - (4)].str)), NULL);
}
    break;

  case 118:

/* Line 1455 of yacc.c  */
#line 1170 "sql.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 119:

/* Line 1455 of yacc.c  */
#line 1171 "sql.yacc"
    {SPRINTF2((yyval.str)," %s %s",(yyvsp[(1) - (2)].str),(yyvsp[(2) - (2)].str)); add_feature("DDL_CONSTRAINT");}
    break;

  case 120:

/* Line 1455 of yacc.c  */
#line 1176 "sql.yacc"
    { SPRINTF1((yyval.str),"DROP CONSTRAINT %s",(yyvsp[(2) - (2)].str)); add_feature("DROP_CONSTRAINT"); }
    break;

  case 121:

/* Line 1455 of yacc.c  */
#line 1177 "sql.yacc"
    {add_feature("DROP_CONSTRAINT");
		SPRINTF1((yyval.str),"DROP CONSTRAINT (%s)",(yyvsp[(3) - (4)].str));
	}
    break;

  case 122:

/* Line 1455 of yacc.c  */
#line 1183 "sql.yacc"
    {strcpy((yyval.str),(yyvsp[(1) - (1)].str));}
    break;

  case 123:

/* Line 1455 of yacc.c  */
#line 1184 "sql.yacc"
    {SPRINTF2((yyval.str),"%s,%s",(yyvsp[(1) - (3)].str),(yyvsp[(3) - (3)].str));}
    break;

  case 125:

/* Line 1455 of yacc.c  */
#line 1198 "sql.yacc"
    {  add_feature("ROLLBACK_WORK"); }
    break;

  case 126:

/* Line 1455 of yacc.c  */
#line 1204 "sql.yacc"
    { insql=1;}
    break;

  case 127:

/* Line 1455 of yacc.c  */
#line 1204 "sql.yacc"
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
#line 1213 "sql.yacc"
    {insql=1;}
    break;

  case 129:

/* Line 1455 of yacc.c  */
#line 1213 "sql.yacc"
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
#line 1222 "sql.yacc"
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
#line 1247 "sql.yacc"
    {
			(yyval.str_list)=0;
	}
    break;

  case 132:

/* Line 1455 of yacc.c  */
#line 1250 "sql.yacc"
    {
			(yyval.str_list)=(yyvsp[(2) - (3)].str_list);
			 add_feature("INSERT_COLUMNLIST_EQ_VALUELIST");
	}
    break;

  case 133:

/* Line 1455 of yacc.c  */
#line 1258 "sql.yacc"
    {
                        (yyval.str_list)=new_str_list((yyvsp[(1) - (1)].str));
	}
    break;

  case 134:

/* Line 1455 of yacc.c  */
#line 1261 "sql.yacc"
    {
                        (yyval.str_list)=add_str_list((yyvsp[(1) - (3)].str_list), (yyvsp[(3) - (3)].str));
	}
    break;

  case 135:

/* Line 1455 of yacc.c  */
#line 1268 "sql.yacc"
    {	
			strcpy((yyval.str),(yyvsp[(1) - (1)].str));
	}
    break;

  case 136:

/* Line 1455 of yacc.c  */
#line 1271 "sql.yacc"
    { 
			/* with a table prefix - on an insert ? We'll just silently drop it... */
			strcpy((yyval.str),(yyvsp[(3) - (3)].str));
			A4GL_warn("Dropped table prefix from INSERT column name");
	}
    break;

  case 137:

/* Line 1455 of yacc.c  */
#line 1279 "sql.yacc"
    { (yyval.s_select_list_item_list)=local_new_select_list_item_list((yyvsp[(1) - (1)].s_select_list_item));}
    break;

  case 138:

/* Line 1455 of yacc.c  */
#line 1280 "sql.yacc"
    {
		(yyval.s_select_list_item_list)=local_add_select_list_item_list((yyvsp[(1) - (3)].s_select_list_item_list),(yyvsp[(3) - (3)].s_select_list_item));
	}
    break;

  case 139:

/* Line 1455 of yacc.c  */
#line 1286 "sql.yacc"
    {(yyval.s_select_list_item)=(yyvsp[(1) - (1)].s_select_list_item);}
    break;

  case 140:

/* Line 1455 of yacc.c  */
#line 1287 "sql.yacc"
    {(yyval.s_select_list_item)=new_select_list_item_builtin_const(E_SLI_BUILTIN_CONST_NULL); }
    break;

  case 141:

/* Line 1455 of yacc.c  */
#line 1295 "sql.yacc"
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
#line 1313 "sql.yacc"
    { add_feature("BEGIN_WORK"); }
    break;

  case 143:

/* Line 1455 of yacc.c  */
#line 1317 "sql.yacc"
    { add_feature("COMMIT_WORK"); }
    break;

  case 144:

/* Line 1455 of yacc.c  */
#line 1322 "sql.yacc"
    {(yyval.e_boolean)=EB_FALSE;}
    break;

  case 145:

/* Line 1455 of yacc.c  */
#line 1323 "sql.yacc"
    {
		add_feature("DATABASE_EXCLUSIVE");
		{(yyval.e_boolean)=EB_TRUE;}
	}
    break;

  case 146:

/* Line 1455 of yacc.c  */
#line 1333 "sql.yacc"
    {
	char buff[256];
	(yyval.sql_string)=make_sql_string_and_free(acl_strdup((yyvsp[(1) - (1)].str)),NULL);
	SPRINTF1(buff,"Warning: Informix specific SQL @ line %d\n",yylineno);
	ansi_violation(buff,1);
	}
    break;

  case 147:

/* Line 1455 of yacc.c  */
#line 1342 "sql.yacc"
    {
			add_feature("START_DATABASE_WITH_LOG_MODE_ANSI");
			sprintf((yyval.str),"START DATABASE %s WITH LOG IN %s MODE ANSI", (yyvsp[(2) - (5)].str),(yyvsp[(4) - (5)].str));
	}
    break;

  case 148:

/* Line 1455 of yacc.c  */
#line 1346 "sql.yacc"
    {
			add_feature("START_DATABASE_WITH_LOG");
			sprintf((yyval.str),"START DATABASE %s WITH LOG IN %s", (yyvsp[(2) - (4)].str),(yyvsp[(4) - (4)].str));
	}
    break;

  case 149:

/* Line 1455 of yacc.c  */
#line 1351 "sql.yacc"
    {
			add_feature("SET_CONSTRAINTS_ALL_IMMEDIATE");
			SPRINTF1((yyval.str),"%s",(yyvsp[(1) - (1)].str)); 
	}
    break;

  case 150:

/* Line 1455 of yacc.c  */
#line 1355 "sql.yacc"
    {
		add_feature("SET_BUFFERED_LOG");
			SPRINTF1((yyval.str),"%s",(yyvsp[(1) - (1)].str)); 
	}
    break;

  case 151:

/* Line 1455 of yacc.c  */
#line 1359 "sql.yacc"
    {
		add_feature("SET_LOG");
			SPRINTF1((yyval.str),"%s",(yyvsp[(1) - (1)].str)); 
	}
    break;

  case 152:

/* Line 1455 of yacc.c  */
#line 1363 "sql.yacc"
    {
			SPRINTF2((yyval.str),"%s %s",(yyvsp[(1) - (2)].str),(yyvsp[(2) - (2)].str)); add_feature("UPDATE_STATISTICS_TABLE");
	}
    break;

  case 153:

/* Line 1455 of yacc.c  */
#line 1366 "sql.yacc"
    {
		add_feature("UPDATE_STATISTICS");
			SPRINTF1((yyval.str),"%s",(yyvsp[(1) - (1)].str)); 
	}
    break;

  case 154:

/* Line 1455 of yacc.c  */
#line 1373 "sql.yacc"
    { (yyval.integer_val)=1; }
    break;

  case 155:

/* Line 1455 of yacc.c  */
#line 1374 "sql.yacc"
    { (yyval.integer_val)=-1; }
    break;

  case 156:

/* Line 1455 of yacc.c  */
#line 1375 "sql.yacc"
    { (yyval.integer_val)=0; }
    break;

  case 157:

/* Line 1455 of yacc.c  */
#line 1379 "sql.yacc"
    { (yyval.sql_string)=(yyvsp[(1) - (1)].sql_string); }
    break;

  case 158:

/* Line 1455 of yacc.c  */
#line 1380 "sql.yacc"
    { (yyval.sql_string)=(yyvsp[(1) - (1)].sql_string); }
    break;

  case 159:

/* Line 1455 of yacc.c  */
#line 1381 "sql.yacc"
    { (yyval.sql_string)=(yyvsp[(1) - (1)].sql_string); }
    break;

  case 160:

/* Line 1455 of yacc.c  */
#line 1382 "sql.yacc"
    { (yyval.sql_string)=(yyvsp[(1) - (1)].sql_string); }
    break;

  case 161:

/* Line 1455 of yacc.c  */
#line 1383 "sql.yacc"
    { (yyval.sql_string)=(yyvsp[(1) - (1)].sql_string); }
    break;

  case 162:

/* Line 1455 of yacc.c  */
#line 1384 "sql.yacc"
    { (yyval.sql_string)=(yyvsp[(1) - (1)].sql_string); }
    break;

  case 163:

/* Line 1455 of yacc.c  */
#line 1385 "sql.yacc"
    { (yyval.sql_string)=(yyvsp[(1) - (1)].sql_string); }
    break;

  case 164:

/* Line 1455 of yacc.c  */
#line 1393 "sql.yacc"
    {SPRINTF7((yyval.str),"%s %s %s %s %s %s %s",(yyvsp[(1) - (7)].str),(yyvsp[(2) - (7)].str),(yyvsp[(3) - (7)].str),(yyvsp[(4) - (7)].str),(yyvsp[(5) - (7)].str),(yyvsp[(6) - (7)].str),(yyvsp[(7) - (7)].str));  add_feature("GRANT"); }
    break;

  case 165:

/* Line 1455 of yacc.c  */
#line 1394 "sql.yacc"
    {SPRINTF6((yyval.str),"%s %s %s %s %s %s",(yyvsp[(1) - (6)].str),(yyvsp[(2) - (6)].str),(yyvsp[(3) - (6)].str),(yyvsp[(4) - (6)].str),(yyvsp[(5) - (6)].str),(yyvsp[(6) - (6)].str));  add_feature("REVOKE"); }
    break;

  case 166:

/* Line 1455 of yacc.c  */
#line 1395 "sql.yacc"
    {SPRINTF4((yyval.str),"%s %s %s %s ",(yyvsp[(1) - (4)].str),(yyvsp[(2) - (4)].str),(yyvsp[(3) - (4)].str),(yyvsp[(4) - (4)].str)); add_feature("GRANT"); }
    break;

  case 167:

/* Line 1455 of yacc.c  */
#line 1396 "sql.yacc"
    {SPRINTF4((yyval.str),"%s %s %s %s ",(yyvsp[(1) - (4)].str),(yyvsp[(2) - (4)].str),(yyvsp[(3) - (4)].str),(yyvsp[(4) - (4)].str));  add_feature("REVOKE"); }
    break;

  case 171:

/* Line 1455 of yacc.c  */
#line 1406 "sql.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 172:

/* Line 1455 of yacc.c  */
#line 1407 "sql.yacc"
    {SPRINTF1((yyval.str)," %s ",(yyvsp[(1) - (1)].str));}
    break;

  case 173:

/* Line 1455 of yacc.c  */
#line 1408 "sql.yacc"
    {SPRINTF2((yyval.str)," %s %s",(yyvsp[(1) - (2)].str),(yyvsp[(2) - (2)].str));}
    break;

  case 174:

/* Line 1455 of yacc.c  */
#line 1412 "sql.yacc"
    {SPRINTF1((yyval.str)," %s ",(yyvsp[(1) - (1)].str));}
    break;

  case 175:

/* Line 1455 of yacc.c  */
#line 1413 "sql.yacc"
    {SPRINTF1((yyval.str)," %s ",(yyvsp[(1) - (1)].str));}
    break;

  case 178:

/* Line 1455 of yacc.c  */
#line 1420 "sql.yacc"
    {SPRINTF3((yyval.str)," %s %s %s",(yyvsp[(1) - (3)].str),(yyvsp[(2) - (3)].str),(yyvsp[(3) - (3)].str));}
    break;

  case 179:

/* Line 1455 of yacc.c  */
#line 1423 "sql.yacc"
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
#line 1432 "sql.yacc"
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
#line 1443 "sql.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 186:

/* Line 1455 of yacc.c  */
#line 1445 "sql.yacc"
    {SPRINTF3((yyval.str)," %s %s %s",(yyvsp[(1) - (3)].str),(yyvsp[(2) - (3)].str),(yyvsp[(3) - (3)].str));}
    break;

  case 188:

/* Line 1455 of yacc.c  */
#line 1451 "sql.yacc"
    {SPRINTF3((yyval.str)," %s %s %s",(yyvsp[(1) - (3)].str),(yyvsp[(2) - (3)].str),(yyvsp[(3) - (3)].str));}
    break;

  case 190:

/* Line 1455 of yacc.c  */
#line 1457 "sql.yacc"
    {SPRINTF3((yyval.str)," %s %s %s",(yyvsp[(1) - (3)].str),(yyvsp[(2) - (3)].str),(yyvsp[(3) - (3)].str));}
    break;

  case 193:

/* Line 1455 of yacc.c  */
#line 1467 "sql.yacc"
    {
		add_feature("CREATE_VIEW_AS_SELECT");
		(yyval.sql_string)=make_sql_string_and_free(acl_strdup((yyvsp[(1) - (6)].str)),kw_space,acl_strdup((yyvsp[(2) - (6)].str)),kw_space,acl_strdup((yyvsp[(3) - (6)].str)),kw_space,acl_strdup((yyvsp[(4) - (6)].str)),kw_space,(yyvsp[(5) - (6)].sql_string),kw_space,acl_strdup((yyvsp[(6) - (6)].str)),NULL);
	
}
    break;

  case 194:

/* Line 1455 of yacc.c  */
#line 1474 "sql.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 195:

/* Line 1455 of yacc.c  */
#line 1476 "sql.yacc"
    {SPRINTF3((yyval.str)," %s %s %s",(yyvsp[(1) - (3)].str),(yyvsp[(2) - (3)].str),(yyvsp[(3) - (3)].str));}
    break;

  case 197:

/* Line 1455 of yacc.c  */
#line 1482 "sql.yacc"
    {SPRINTF3((yyval.str)," %s %s %s",(yyvsp[(1) - (3)].str),(yyvsp[(2) - (3)].str),(yyvsp[(3) - (3)].str));}
    break;

  case 198:

/* Line 1455 of yacc.c  */
#line 1485 "sql.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 199:

/* Line 1455 of yacc.c  */
#line 1486 "sql.yacc"
    {
		add_feature("CREATE_VIEW_SELECT_WITH_CHECK");
	}
    break;

  case 200:

/* Line 1455 of yacc.c  */
#line 1493 "sql.yacc"
    {
		(yyval.sql_string)=make_sql_string_and_free(strdup("CHECK ("),(yyvsp[(3) - (4)].sql_string),kw_cb,NULL);
		add_feature("DDL_CHECK");
	}
    break;

  case 201:

/* Line 1455 of yacc.c  */
#line 1502 "sql.yacc"
    {SPRINTF5((yyval.str)," %s %s %s %s %s",(yyvsp[(1) - (5)].str),(yyvsp[(2) - (5)].str),(yyvsp[(3) - (5)].str),(yyvsp[(4) - (5)].str),(yyvsp[(5) - (5)].str));
	add_feature("DDL_FOREIGN_KEY");
}
    break;

  case 202:

/* Line 1455 of yacc.c  */
#line 1509 "sql.yacc"
    {SPRINTF2((yyval.str)," %s %s",(yyvsp[(1) - (2)].str),(yyvsp[(2) - (2)].str));
add_feature("DDL_REFERENCES");
}
    break;

  case 205:

/* Line 1455 of yacc.c  */
#line 1521 "sql.yacc"
    {SPRINTF4((yyval.str)," %s %s %s %s",(yyvsp[(1) - (4)].str),(yyvsp[(2) - (4)].str),(yyvsp[(3) - (4)].str),(yyvsp[(4) - (4)].str));}
    break;

  case 207:

/* Line 1455 of yacc.c  */
#line 1527 "sql.yacc"
    {SPRINTF3((yyval.str)," %s %s %s",(yyvsp[(1) - (3)].str),(yyvsp[(2) - (3)].str),(yyvsp[(3) - (3)].str));}
    break;

  case 208:

/* Line 1455 of yacc.c  */
#line 1532 "sql.yacc"
    {
		SPRINTF3((yyval.str)," UNIQUE %s %s %s",(yyvsp[(2) - (4)].str),(yyvsp[(3) - (4)].str),(yyvsp[(4) - (4)].str));
add_feature("DDL_UNIQUE");
	}
    break;

  case 209:

/* Line 1455 of yacc.c  */
#line 1536 "sql.yacc"
    {
		ansi_violation("Use UNIQUE not DISTINCT",0);
		SPRINTF3((yyval.str)," UNIQUE %s %s %s",(yyvsp[(2) - (4)].str),(yyvsp[(3) - (4)].str),(yyvsp[(4) - (4)].str));
add_feature("DDL_DISTINCT");
	}
    break;

  case 210:

/* Line 1455 of yacc.c  */
#line 1542 "sql.yacc"
    {SPRINTF4((yyval.str)," %s %s %s %s",(yyvsp[(1) - (4)].str),(yyvsp[(2) - (4)].str),(yyvsp[(3) - (4)].str),(yyvsp[(4) - (4)].str));
add_feature("DDL_PRIMARY_KEY");
}
    break;

  case 212:

/* Line 1455 of yacc.c  */
#line 1550 "sql.yacc"
    {SPRINTF3((yyval.str)," %s %s %s",(yyvsp[(1) - (3)].str),(yyvsp[(2) - (3)].str),(yyvsp[(3) - (3)].str));}
    break;

  case 213:

/* Line 1455 of yacc.c  */
#line 1555 "sql.yacc"
    {
		(yyval.sql_string)=acl_strdup((yyvsp[(1) - (1)].str));
	}
    break;

  case 214:

/* Line 1455 of yacc.c  */
#line 1558 "sql.yacc"
    {
		(yyval.sql_string)=acl_strdup((yyvsp[(1) - (1)].str));
	}
    break;

  case 215:

/* Line 1455 of yacc.c  */
#line 1561 "sql.yacc"
    {
		(yyval.sql_string)=(yyvsp[(1) - (1)].sql_string);
	}
    break;

  case 216:

/* Line 1455 of yacc.c  */
#line 1568 "sql.yacc"
    {SPRINTF2((yyval.str)," %s %s",(yyvsp[(1) - (2)].str),(yyvsp[(2) - (2)].str)); add_feature("DDL_DEFAULT_VALUE"); }
    break;

  case 217:

/* Line 1455 of yacc.c  */
#line 1569 "sql.yacc"
    {SPRINTF1((yyval.str)," DEFAULT %s", A4GLSQLCV_get_sqlconst("USER")); add_feature("DDL_DEFAULT_VALUE"); }
    break;

  case 218:

/* Line 1455 of yacc.c  */
#line 1570 "sql.yacc"
    {SPRINTF1((yyval.str)," DEFAULT %s", A4GLSQLCV_get_sqlconst("TODAY")); add_feature("DDL_DEFAULT_VALUE"); }
    break;

  case 219:

/* Line 1455 of yacc.c  */
#line 1571 "sql.yacc"
    { SPRINTF1((yyval.str)," %s",(yyvsp[(1) - (1)].str)); add_feature("DDL_DEFAULT_VALUE"); }
    break;

  case 220:

/* Line 1455 of yacc.c  */
#line 1577 "sql.yacc"
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
#line 1598 "sql.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 223:

/* Line 1455 of yacc.c  */
#line 1602 "sql.yacc"
    {
		(yyval.sql_string)=acl_strdup("");
	}
    break;

  case 224:

/* Line 1455 of yacc.c  */
#line 1604 "sql.yacc"
    {
		(yyval.sql_string)=(yyvsp[(1) - (1)].sql_string);
	}
    break;

  case 225:

/* Line 1455 of yacc.c  */
#line 1611 "sql.yacc"
    {
		(yyval.sql_string)=(yyvsp[(1) - (1)].sql_string);
	}
    break;

  case 226:

/* Line 1455 of yacc.c  */
#line 1614 "sql.yacc"
    {
		(yyval.sql_string)=make_sql_string_and_free((yyvsp[(1) - (2)].sql_string),kw_space,(yyvsp[(2) - (2)].sql_string),NULL);
	}
    break;

  case 227:

/* Line 1455 of yacc.c  */
#line 1620 "sql.yacc"
    {
		(yyval.sql_string)=make_sql_string_and_free((yyvsp[(1) - (2)].sql_string),acl_strdup((yyvsp[(2) - (2)].str)),NULL);
	}
    break;

  case 228:

/* Line 1455 of yacc.c  */
#line 1628 "sql.yacc"
    {
		SPRINTF1((yyval.str)," %s ",(yyvsp[(1) - (1)].str));
		(yyval.sql_string)=acl_strdup((yyval.str));
		add_feature("DDL_NOT_NULL");
	}
    break;

  case 229:

/* Line 1455 of yacc.c  */
#line 1633 "sql.yacc"
    {
		SPRINTF0((yyval.str)," NOT NULL UNIQUE ");
		(yyval.sql_string)=acl_strdup((yyval.str));
		add_feature("DDL_NOT_NULL");
		add_feature("DDL_UNIQUE");
	}
    break;

  case 230:

/* Line 1455 of yacc.c  */
#line 1639 "sql.yacc"
    {
		SPRINTF0((yyval.str)," UNIQUE ");
		(yyval.sql_string)=acl_strdup((yyval.str));
		add_feature("DDL_UNIQUE");
	}
    break;

  case 231:

/* Line 1455 of yacc.c  */
#line 1644 "sql.yacc"
    {
		ansi_violation("Use UNIQUE not DISTINCT",0);
		SPRINTF0((yyval.str)," UNIQUE ");
		(yyval.sql_string)=acl_strdup((yyval.str));
		add_feature("DDL_DISTINCT");
	}
    break;

  case 232:

/* Line 1455 of yacc.c  */
#line 1650 "sql.yacc"
    {
		(yyval.sql_string)=acl_strdup((yyvsp[(1) - (1)].str));
	}
    break;

  case 233:

/* Line 1455 of yacc.c  */
#line 1653 "sql.yacc"
    {
		(yyval.sql_string)=make_sql_string_and_free(acl_strdup("CHECK ("),(yyvsp[(3) - (4)].sql_string),kw_cb,NULL);
		add_feature("DDL_CHECK");
		
	}
    break;

  case 234:

/* Line 1455 of yacc.c  */
#line 1658 "sql.yacc"
    {
		(yyval.sql_string)=make_sql_string_and_free(acl_strdup(" PRIMARY KEY "),NULL);
		add_feature("DDL_PRIMARY_KEY");
	}
    break;

  case 235:

/* Line 1455 of yacc.c  */
#line 1667 "sql.yacc"
    {
		add_feature("CREATE_SCHEMA");

(yyval.sql_string)=make_sql_string_and_free(acl_strdup((yyvsp[(1) - (3)].str)),kw_space,acl_strdup((yyvsp[(2) - (3)].str)),kw_space,acl_strdup((yyvsp[(3) - (3)].str)),NULL);
}
    break;

  case 236:

/* Line 1455 of yacc.c  */
#line 1676 "sql.yacc"
    {SPRINTF1((yyval.str)," %s",(yyvsp[(1) - (1)].str));}
    break;

  case 239:

/* Line 1455 of yacc.c  */
#line 1685 "sql.yacc"
    {
		(yyval.sql_string)=make_sql_string_and_free((yyvsp[(1) - (2)].sql_string),kw_space,(yyvsp[(2) - (2)].sql_string),NULL);
	}
    break;

  case 240:

/* Line 1455 of yacc.c  */
#line 1691 "sql.yacc"
    {
		(yyval.sql_string)=(yyvsp[(1) - (1)].sql_string);
	}
    break;

  case 241:

/* Line 1455 of yacc.c  */
#line 1694 "sql.yacc"
    {
		(yyval.sql_string)=acl_strdup((yyvsp[(1) - (1)].str));
	}
    break;

  case 242:

/* Line 1455 of yacc.c  */
#line 1705 "sql.yacc"
    {
		 add_feature("HAVING"); 
		(yyval.s_select_list_item)=(yyvsp[(2) - (2)].s_select_list_item);
	}
    break;

  case 243:

/* Line 1455 of yacc.c  */
#line 1714 "sql.yacc"
    {
		 (yyval.s_select_list_item)=(yyvsp[(2) - (2)].s_select_list_item);
	}
    break;

  case 244:

/* Line 1455 of yacc.c  */
#line 1721 "sql.yacc"
    {
		(yyval.u_table)=(yyvsp[(2) - (2)].u_table);
	}
    break;

  case 245:

/* Line 1455 of yacc.c  */
#line 1727 "sql.yacc"
    {(yyval.u_table)=(yyvsp[(1) - (1)].u_table);}
    break;

  case 246:

/* Line 1455 of yacc.c  */
#line 1728 "sql.yacc"
    {
		(yyval.u_table)=A4GLSQLPARSE_append_tablename((yyvsp[(1) - (3)].u_table),(yyvsp[(3) - (3)].u_table),E_OUTER_NONE,NULL);
	}
    break;

  case 247:

/* Line 1455 of yacc.c  */
#line 1731 "sql.yacc"
    {
		(yyval.u_table)=A4GLSQLPARSE_append_tablename((yyvsp[(1) - (4)].u_table),(yyvsp[(4) - (4)].u_table),E_OUTER_NORMAL,NULL);
		A4GL_warn("OUTER join *may* not be portable to non-informix database");
		add_feature("SELECT_OUTER");
	}
    break;

  case 248:

/* Line 1455 of yacc.c  */
#line 1736 "sql.yacc"
    {
		(yyval.u_table)=A4GLSQLPARSE_append_tablename((yyvsp[(1) - (6)].u_table),(yyvsp[(5) - (6)].u_table),E_OUTER_NORMAL,NULL);
		A4GL_warn("OUTER join *may* not be portable to non-informix database");
		add_feature("SELECT_OUTER");
	}
    break;

  case 249:

/* Line 1455 of yacc.c  */
#line 1747 "sql.yacc"
    {
		(yyval.u_table)=A4GLSQLPARSE_append_tablename((yyvsp[(1) - (5)].u_table),(yyvsp[(3) - (5)].u_table),E_OUTER_LEFT_OUTER, (yyvsp[(5) - (5)].s_select_list_item));
		add_feature("SELECT_OUTER");
	}
    break;

  case 250:

/* Line 1455 of yacc.c  */
#line 1751 "sql.yacc"
    {
		(yyval.u_table)=A4GLSQLPARSE_append_tablename((yyvsp[(1) - (5)].u_table),(yyvsp[(3) - (5)].u_table),E_INNER, (yyvsp[(5) - (5)].s_select_list_item));
		add_feature("SELECT_INNER");
	}
    break;

  case 252:

/* Line 1455 of yacc.c  */
#line 1759 "sql.yacc"
    {(yyval.u_table)=(yyvsp[(2) - (3)].u_table);}
    break;

  case 253:

/* Line 1455 of yacc.c  */
#line 1763 "sql.yacc"
    { 
			//A4GL_add_crud("SELECT",$<str>1);
			(yyval.u_table)=A4GLSQLPARSE_new_tablename((yyvsp[(1) - (1)].str),NULL);
	}
    break;

  case 254:

/* Line 1455 of yacc.c  */
#line 1767 "sql.yacc"
    { 
			//A4GL_add_crud("SELECT",$<str>1);
			(yyval.u_table)=A4GLSQLPARSE_new_tablename((yyvsp[(1) - (2)].str),(yyvsp[(2) - (2)].str));
	}
    break;

  case 255:

/* Line 1455 of yacc.c  */
#line 1771 "sql.yacc"
    { 
			//A4GL_add_crud("SELECT",$<str>1);
			(yyval.u_table)=A4GLSQLPARSE_new_tablename((yyvsp[(1) - (3)].str),(yyvsp[(3) - (3)].str));
	}
    break;

  case 256:

/* Line 1455 of yacc.c  */
#line 1778 "sql.yacc"
    {
			/* No from or where etc.. */
			/* eg.. select user ; */
			(yyval.s_select)=new_empty_select();
		}
    break;

  case 257:

/* Line 1455 of yacc.c  */
#line 1783 "sql.yacc"
    {
		(yyval.s_select)=(yyvsp[(2) - (2)].s_select);
		(yyval.s_select)->first=(yyvsp[(1) - (2)].u_table);
			A4GL_set_associated_mem( (yyval.s_select), (yyval.s_select)->first);
}
    break;

  case 258:

/* Line 1455 of yacc.c  */
#line 1791 "sql.yacc"
    {
		(yyval.s_select)=(yyvsp[(1) - (1)].s_select);
	}
    break;

  case 259:

/* Line 1455 of yacc.c  */
#line 1794 "sql.yacc"
    {
		(yyval.s_select)=(yyvsp[(2) - (2)].s_select);
		(yyval.s_select)->where_clause=(yyvsp[(1) - (2)].s_select_list_item);
	}
    break;

  case 260:

/* Line 1455 of yacc.c  */
#line 1800 "sql.yacc"
    {
		(yyval.s_select)=new_empty_select();
	}
    break;

  case 261:

/* Line 1455 of yacc.c  */
#line 1803 "sql.yacc"
    {
		(yyval.s_select)=new_empty_select();
		(yyval.s_select)->group_by=(yyvsp[(1) - (1)].s_select_list_item_list);
		(yyval.s_select)->having=0;
	}
    break;

  case 262:

/* Line 1455 of yacc.c  */
#line 1808 "sql.yacc"
    {
		(yyval.s_select)=new_empty_select();
		(yyval.s_select)->group_by=(yyvsp[(1) - (2)].s_select_list_item_list);
		(yyval.s_select)->having=(yyvsp[(2) - (2)].s_select_list_item);
	}
    break;

  case 263:

/* Line 1455 of yacc.c  */
#line 1813 "sql.yacc"
    {
		(yyval.s_select)=new_empty_select();
		(yyval.s_select)->group_by=0;
		(yyval.s_select)->having=(yyvsp[(1) - (1)].s_select_list_item);

	}
    break;

  case 264:

/* Line 1455 of yacc.c  */
#line 1826 "sql.yacc"
    {
		(yyval.s_select_list_item)=(yyvsp[(1) - (1)].s_select_list_item);
	}
    break;

  case 265:

/* Line 1455 of yacc.c  */
#line 1829 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_op_expr((yyvsp[(1) - (3)].s_select_list_item),(yyvsp[(3) - (3)].s_select_list_item)," OR ");
	}
    break;

  case 266:

/* Line 1455 of yacc.c  */
#line 1835 "sql.yacc"
    {
		(yyval.s_select_list_item)=(yyvsp[(1) - (1)].s_select_list_item);
	}
    break;

  case 267:

/* Line 1455 of yacc.c  */
#line 1838 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_op_expr((yyvsp[(1) - (3)].s_select_list_item),(yyvsp[(3) - (3)].s_select_list_item)," AND ");
	}
    break;

  case 268:

/* Line 1455 of yacc.c  */
#line 1844 "sql.yacc"
    {
		(yyval.s_select_list_item)=(yyvsp[(1) - (1)].s_select_list_item);
	}
    break;

  case 269:

/* Line 1455 of yacc.c  */
#line 1847 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_simple_expr(E_SLI_NOT,(yyvsp[(2) - (2)].s_select_list_item));
	}
    break;

  case 270:

/* Line 1455 of yacc.c  */
#line 1853 "sql.yacc"
    {
		(yyval.s_select_list_item)=(yyvsp[(1) - (1)].s_select_list_item);
	}
    break;

  case 271:

/* Line 1455 of yacc.c  */
#line 1856 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_simple_expr(E_SLI_BRACKET_EXPR,(yyvsp[(2) - (3)].s_select_list_item));
	}
    break;

  case 272:

/* Line 1455 of yacc.c  */
#line 1863 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_sq(E_SQE_EXISTS, (yyvsp[(2) - (2)].s_select_list_item));
		add_feature("WHERE_EXISTS");
	}
    break;

  case 273:

/* Line 1455 of yacc.c  */
#line 1867 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_sq(E_SQE_NOT_EXISTS, (yyvsp[(2) - (2)].s_select_list_item));
		add_feature("WHERE_EXISTS");
	}
    break;

  case 274:

/* Line 1455 of yacc.c  */
#line 1878 "sql.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 275:

/* Line 1455 of yacc.c  */
#line 1878 "sql.yacc"
    {SPRINTF1((yyval.str)," ESCAPE %s",(yyvsp[(2) - (2)].str));add_feature("WHERE_MATCHES_ESCAPE");}
    break;

  case 276:

/* Line 1455 of yacc.c  */
#line 1879 "sql.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 277:

/* Line 1455 of yacc.c  */
#line 1879 "sql.yacc"
    {SPRINTF1((yyval.str)," ESCAPE %s",(yyvsp[(2) - (2)].str));add_feature("WHERE_ILIKE_ESCAPE");}
    break;

  case 278:

/* Line 1455 of yacc.c  */
#line 1880 "sql.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 279:

/* Line 1455 of yacc.c  */
#line 1880 "sql.yacc"
    {SPRINTF1((yyval.str)," ESCAPE %s",(yyvsp[(2) - (2)].str));add_feature("WHERE_LIKE_ESCAPE");}
    break;

  case 280:

/* Line 1455 of yacc.c  */
#line 1883 "sql.yacc"
    {
		 (yyval.s_select_list_item)=(yyvsp[(1) - (1)].s_select_list_item);
	}
    break;

  case 282:

/* Line 1455 of yacc.c  */
#line 1893 "sql.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 283:

/* Line 1455 of yacc.c  */
#line 1894 "sql.yacc"
    {strcpy((yyval.str)," NOT ");}
    break;

  case 284:

/* Line 1455 of yacc.c  */
#line 1899 "sql.yacc"
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
#line 1908 "sql.yacc"
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
#line 1916 "sql.yacc"
    { 
			(yyval.s_select_list_item)=new_select_list_item_op_expr((yyvsp[(1) - (3)].s_select_list_item),(yyvsp[(3) - (3)].s_select_list_item),(yyvsp[(2) - (3)].str));
	}
    break;

  case 287:

/* Line 1455 of yacc.c  */
#line 1919 "sql.yacc"
    { 
			(yyval.s_select_list_item)=new_select_list_item_op_expr((yyvsp[(1) - (3)].s_select_list_item),(yyvsp[(3) - (3)].s_select_list_item),"=");
	}
    break;

  case 288:

/* Line 1455 of yacc.c  */
#line 1922 "sql.yacc"
    { 
			FPRINTF(stderr,"Warning: Corrected =NULL to IS NULL line %d\n",yylineno);
			(yyval.s_select_list_item)=new_select_list_item_simple_expr(E_SLI_ISNULL,(yyvsp[(1) - (3)].s_select_list_item));
	}
    break;

  case 289:

/* Line 1455 of yacc.c  */
#line 1926 "sql.yacc"
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
#line 1933 "sql.yacc"
    { 
			(yyval.s_select_list_item)=new_select_list_item_regex(E_SLI_REGEX_LIKE,(yyvsp[(1) - (4)].s_select_list_item),(yyvsp[(3) - (4)].s_select_list_item),(yyvsp[(4) - (4)].str));
	}
    break;

  case 291:

/* Line 1455 of yacc.c  */
#line 1936 "sql.yacc"
    { 
			(yyval.s_select_list_item)=new_select_list_item_regex(E_SLI_REGEX_NOT_LIKE,(yyvsp[(1) - (4)].s_select_list_item),(yyvsp[(3) - (4)].s_select_list_item),(yyvsp[(4) - (4)].str));

	}
    break;

  case 292:

/* Line 1455 of yacc.c  */
#line 1940 "sql.yacc"
    { 
			(yyval.s_select_list_item)=new_select_list_item_regex(E_SLI_REGEX_ILIKE,(yyvsp[(1) - (4)].s_select_list_item),(yyvsp[(3) - (4)].s_select_list_item),(yyvsp[(4) - (4)].str));
	}
    break;

  case 293:

/* Line 1455 of yacc.c  */
#line 1943 "sql.yacc"
    { 
			(yyval.s_select_list_item)=new_select_list_item_regex(E_SLI_REGEX_NOT_ILIKE,(yyvsp[(1) - (4)].s_select_list_item),(yyvsp[(3) - (4)].s_select_list_item),(yyvsp[(4) - (4)].str));
	}
    break;

  case 294:

/* Line 1455 of yacc.c  */
#line 1946 "sql.yacc"
    { 
			(yyval.s_select_list_item)=new_select_list_item_regex(E_SLI_REGEX_MATCHES,(yyvsp[(1) - (4)].s_select_list_item),(yyvsp[(3) - (4)].s_select_list_item),(yyvsp[(4) - (4)].str));
	}
    break;

  case 295:

/* Line 1455 of yacc.c  */
#line 1949 "sql.yacc"
    { 
			(yyval.s_select_list_item)=new_select_list_item_regex(E_SLI_REGEX_NOT_MATCHES,(yyvsp[(1) - (4)].s_select_list_item),(yyvsp[(3) - (4)].s_select_list_item),(yyvsp[(4) - (4)].str));
	}
    break;

  case 296:

/* Line 1455 of yacc.c  */
#line 1955 "sql.yacc"
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
#line 1962 "sql.yacc"
    {
			strcpy((yyval.str)," < ");
	}
    break;

  case 298:

/* Line 1455 of yacc.c  */
#line 1965 "sql.yacc"
    {
			strcpy((yyval.str)," > ");
	}
    break;

  case 299:

/* Line 1455 of yacc.c  */
#line 1968 "sql.yacc"
    {
			strcpy((yyval.str)," ~ ");
	}
    break;

  case 300:

/* Line 1455 of yacc.c  */
#line 1971 "sql.yacc"
    {strcpy((yyval.str)," <= ");}
    break;

  case 301:

/* Line 1455 of yacc.c  */
#line 1972 "sql.yacc"
    {strcpy((yyval.str)," >= ");}
    break;

  case 302:

/* Line 1455 of yacc.c  */
#line 1977 "sql.yacc"
    {
		(yyval.s_select_list_item)=(yyvsp[(1) - (1)].s_select_list_item);
	}
    break;

  case 303:

/* Line 1455 of yacc.c  */
#line 1980 "sql.yacc"
    {
		(yyval.s_select_list_item)=(yyvsp[(1) - (1)].s_select_list_item);
	}
    break;

  case 304:

/* Line 1455 of yacc.c  */
#line 1983 "sql.yacc"
    {
		(yyval.s_select_list_item)=(yyvsp[(1) - (1)].s_select_list_item);
	}
    break;

  case 305:

/* Line 1455 of yacc.c  */
#line 1986 "sql.yacc"
    {
                 (yyval.s_select_list_item)=(yyvsp[(1) - (1)].s_select_list_item);
        }
    break;

  case 306:

/* Line 1455 of yacc.c  */
#line 1993 "sql.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 307:

/* Line 1455 of yacc.c  */
#line 1994 "sql.yacc"
    {strcpy((yyval.str)," ALL "); add_feature("AGG_ALL");}
    break;

  case 308:

/* Line 1455 of yacc.c  */
#line 1995 "sql.yacc"
    {
		strcpy((yyval.str)," DISTINCT ");
		add_feature("AGG_DISTINCT");
	}
    break;

  case 309:

/* Line 1455 of yacc.c  */
#line 1999 "sql.yacc"
    {
		ansi_violation("Use DISTINCT not UNIQUE",0);
		strcpy((yyval.str)," DISTINCT ");
		add_feature("AGG_DISTINCT");
	}
    break;

  case 310:

/* Line 1455 of yacc.c  */
#line 2006 "sql.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 311:

/* Line 1455 of yacc.c  */
#line 2007 "sql.yacc"
    {strcpy((yyval.str)," ALL "); add_feature("UNION_ALL");}
    break;

  case 312:

/* Line 1455 of yacc.c  */
#line 2008 "sql.yacc"
    {
		strcpy((yyval.str)," DISTINCT ");
		add_feature("UNION_DISTINCT");
	}
    break;

  case 313:

/* Line 1455 of yacc.c  */
#line 2012 "sql.yacc"
    {
		ansi_violation("Use DISTINCT not UNIQUE",0);
		add_feature("UNION_DISTINCT");
		strcpy((yyval.str)," DISTINCT ");
	}
    break;

  case 314:

/* Line 1455 of yacc.c  */
#line 2026 "sql.yacc"
    {
		strcpy((yyval.str),A4GLSQLCV_dtype_alias((yyvsp[(1) - (1)].str)));
	}
    break;

  case 319:

/* Line 1455 of yacc.c  */
#line 2041 "sql.yacc"
    {SPRINTF4((yyval.str)," %s %s%s%s",(yyvsp[(1) - (4)].str),(yyvsp[(2) - (4)].str),(yyvsp[(3) - (4)].str),(yyvsp[(4) - (4)].str));}
    break;

  case 320:

/* Line 1455 of yacc.c  */
#line 2045 "sql.yacc"
    {strcpy((yyval.str),"SERIAL"); add_feature("DDL_SERIAL"); }
    break;

  case 321:

/* Line 1455 of yacc.c  */
#line 2046 "sql.yacc"
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
#line 2055 "sql.yacc"
    {strcpy((yyval.str),"SERIAL8"); add_feature("DDL_SERIAL8"); }
    break;

  case 323:

/* Line 1455 of yacc.c  */
#line 2057 "sql.yacc"
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
#line 2066 "sql.yacc"
    {
 			add_feature("DDL_DECIMAL");
	}
    break;

  case 325:

/* Line 1455 of yacc.c  */
#line 2069 "sql.yacc"
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
#line 2077 "sql.yacc"
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
#line 2087 "sql.yacc"
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
#line 2095 "sql.yacc"
    {strcpy((yyval.str),"DATE");
 			add_feature("DDL_DATE"); }
    break;

  case 329:

/* Line 1455 of yacc.c  */
#line 2097 "sql.yacc"
    {strcpy((yyval.str),"INTEGER");}
    break;

  case 330:

/* Line 1455 of yacc.c  */
#line 2098 "sql.yacc"
    {strcpy((yyval.str),"SMALLINT");}
    break;

  case 331:

/* Line 1455 of yacc.c  */
#line 2099 "sql.yacc"
    {strcpy((yyval.str),"NCHAR"); add_feature("DDL_NCHAR");}
    break;

  case 332:

/* Line 1455 of yacc.c  */
#line 2100 "sql.yacc"
    {SPRINTF1((yyval.str),"NCHAR(%s)",(yyvsp[(3) - (4)].str)); add_feature("DDL_NCHAR");}
    break;

  case 333:

/* Line 1455 of yacc.c  */
#line 2101 "sql.yacc"
    {add_feature("DDL_NVARCHAR");}
    break;

  case 334:

/* Line 1455 of yacc.c  */
#line 2102 "sql.yacc"
    {SPRINTF1((yyval.str),"NVARCHAR(%s)",(yyvsp[(3) - (4)].str)); add_feature("DDL_NVARCHAR");}
    break;

  case 335:

/* Line 1455 of yacc.c  */
#line 2103 "sql.yacc"
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
#line 2111 "sql.yacc"
    {SPRINTF2((yyval.str),"DATETIME %s TO %s",(yyvsp[(2) - (4)].str),(yyvsp[(4) - (4)].str)); add_feature("DDL_DATETIME");}
    break;

  case 337:

/* Line 1455 of yacc.c  */
#line 2112 "sql.yacc"
    {add_feature("DDL_DATETIME");}
    break;

  case 338:

/* Line 1455 of yacc.c  */
#line 2113 "sql.yacc"
    {SPRINTF2((yyval.str),"INTERVAL %s TO %s",(yyvsp[(2) - (4)].str),(yyvsp[(4) - (4)].str)); add_feature("DDL_INTERVAL");}
    break;

  case 339:

/* Line 1455 of yacc.c  */
#line 2114 "sql.yacc"
    {strcpy((yyval.str),(yyvsp[(1) - (1)].str));}
    break;

  case 340:

/* Line 1455 of yacc.c  */
#line 2115 "sql.yacc"
    {add_feature("DDL_INTERVAL");}
    break;

  case 341:

/* Line 1455 of yacc.c  */
#line 2116 "sql.yacc"
    {SPRINTF3((yyval.str),"INTERVAL %s(%s) TO %s",(yyvsp[(2) - (7)].str),(yyvsp[(4) - (7)].str),(yyvsp[(7) - (7)].str)); add_feature("DDL_INTERVAL");}
    break;

  case 342:

/* Line 1455 of yacc.c  */
#line 2117 "sql.yacc"
    {add_feature("DDL_TEXT");}
    break;

  case 343:

/* Line 1455 of yacc.c  */
#line 2118 "sql.yacc"
    {add_feature("DDL_BYTE");}
    break;

  case 344:

/* Line 1455 of yacc.c  */
#line 2119 "sql.yacc"
    {add_feature("DDL_VARCHAR");}
    break;

  case 345:

/* Line 1455 of yacc.c  */
#line 2120 "sql.yacc"
    {SPRINTF1((yyval.str),"VARCHAR(%s)",(yyvsp[(3) - (4)].str));add_feature("DDL_VARCHAR");}
    break;

  case 346:

/* Line 1455 of yacc.c  */
#line 2121 "sql.yacc"
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
#line 2131 "sql.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 348:

/* Line 1455 of yacc.c  */
#line 2132 "sql.yacc"
    {
		SPRINTF1((yyval.str),",%s",(yyvsp[(2) - (2)].str));
}
    break;

  case 349:

/* Line 1455 of yacc.c  */
#line 2139 "sql.yacc"
    {SPRINTF4((yyval.str)," %s %s %s %s",(yyvsp[(1) - (4)].str),(yyvsp[(2) - (4)].str),(yyvsp[(3) - (4)].str),(yyvsp[(4) - (4)].str));}
    break;

  case 353:

/* Line 1455 of yacc.c  */
#line 2143 "sql.yacc"
    {add_feature("DDL_DOUBLE_PRECISION"); SPRINTF1((yyval.str)," %s",(yyvsp[(1) - (1)].str));}
    break;

  case 359:

/* Line 1455 of yacc.c  */
#line 2168 "sql.yacc"
    {(yyval.int_list.i0)=0;}
    break;

  case 360:

/* Line 1455 of yacc.c  */
#line 2169 "sql.yacc"
    {
		(yyval.int_list.i0)=1;
		(yyval.int_list.i1)=atoi((yyvsp[(2) - (3)].str));
	}
    break;

  case 361:

/* Line 1455 of yacc.c  */
#line 2173 "sql.yacc"
    {
		(yyval.int_list.i0)=2;
		(yyval.int_list.i1)=atoi((yyvsp[(2) - (5)].str));
		(yyval.int_list.i2)=atoi((yyvsp[(4) - (5)].str));
	}
    break;

  case 362:

/* Line 1455 of yacc.c  */
#line 2181 "sql.yacc"
    {
		strcpy((yyval.str),(yyvsp[(1) - (1)].str));
	}
    break;

  case 363:

/* Line 1455 of yacc.c  */
#line 2184 "sql.yacc"
    {
		strcpy((yyval.str),(yyvsp[(2) - (2)].str));
	}
    break;

  case 364:

/* Line 1455 of yacc.c  */
#line 2191 "sql.yacc"
    {
		(yyval.s_select_list_item)= (yyvsp[(1) - (1)].s_select_list_item);
	}
    break;

  case 365:

/* Line 1455 of yacc.c  */
#line 2194 "sql.yacc"
    {
		(yyval.s_select_list_item)= (yyvsp[(2) - (2)].s_select_list_item);
	}
    break;

  case 366:

/* Line 1455 of yacc.c  */
#line 2204 "sql.yacc"
    { 
		(yyval.s_select_list_item)=new_select_list_item_col(0,(yyvsp[(1) - (2)].str),&(yyvsp[(2) - (2)].int_list));
	}
    break;

  case 367:

/* Line 1455 of yacc.c  */
#line 2207 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_col((yyvsp[(1) - (4)].str),(yyvsp[(3) - (4)].str),&(yyvsp[(4) - (4)].int_list));
	}
    break;

  case 368:

/* Line 1455 of yacc.c  */
#line 2210 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_col((yyvsp[(1) - (3)].str),"*",0);
	}
    break;

  case 369:

/* Line 1455 of yacc.c  */
#line 2213 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_col(0,"rowid",0);
	}
    break;

  case 370:

/* Line 1455 of yacc.c  */
#line 2220 "sql.yacc"
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
#line 2227 "sql.yacc"
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
#line 2235 "sql.yacc"
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
#line 2244 "sql.yacc"
    {
		SPRINTF1((yyval.str),"%s",A4GLSQLCV_check_colname((yyvsp[(1) - (3)].str),"*"));
		ADDMAP("Use Column",(yyval.str));
	}
    break;

  case 375:

/* Line 1455 of yacc.c  */
#line 2255 "sql.yacc"
    { strcpy((yyval.str),(yyvsp[(1) - (1)].str)); A4GL_debug("Set $<str>$ to %s\n",(yyval.str)); }
    break;

  case 379:

/* Line 1455 of yacc.c  */
#line 2263 "sql.yacc"
    { strcpy((yyval.str),A4GLSQLCV_generate_current(0,0)); 
}
    break;

  case 380:

/* Line 1455 of yacc.c  */
#line 2265 "sql.yacc"
    {
		strcpy((yyval.str),A4GLSQLCV_generate_current((yyvsp[(1) - (3)].str),(yyvsp[(3) - (3)].str)));
	}
    break;

  case 395:

/* Line 1455 of yacc.c  */
#line 2275 "sql.yacc"
    {SPRINTF1((yyval.str),"FRACTION(%s)",(yyvsp[(3) - (4)].str));}
    break;

  case 396:

/* Line 1455 of yacc.c  */
#line 2290 "sql.yacc"
    {
		add_sql_function((yyvsp[(2) - (4)].str));
		if (A4GLSQLCV_check_requirement("EXECUTE_PROCEDURE_AS_EXEC")) {
			SPRINTF1((yyval.str),"EXEC %s",(yyvsp[(2) - (4)].str));
		} else {
			SPRINTF1((yyval.str),"EXECUTE PROCEDURE %s ()",(yyvsp[(2) - (4)].str));
		}
	}
    break;

  case 397:

/* Line 1455 of yacc.c  */
#line 2298 "sql.yacc"
    {
		add_sql_function((yyvsp[(2) - (5)].str));
		if (A4GLSQLCV_check_requirement("EXECUTE_PROCEDURE_AS_EXEC")) {
			SPRINTF2((yyval.str),"EXEC %s %s",(yyvsp[(2) - (5)].str), get_select_list_item_list(0, (yyvsp[(4) - (5)].s_select_list_item_list)));
		} else {
			SPRINTF2((yyval.str),"EXECUTE PROCEDURE %s (%s)",(yyvsp[(2) - (5)].str), get_select_list_item_list(0, (yyvsp[(4) - (5)].s_select_list_item_list)));
		}
	}
    break;

  case 398:

/* Line 1455 of yacc.c  */
#line 2310 "sql.yacc"
    { (yyval.sql_string)=make_sql_string_and_free(acl_strdup((yyvsp[(1) - (1)].str)), NULL);}
    break;

  case 399:

/* Line 1455 of yacc.c  */
#line 2311 "sql.yacc"
    { (yyval.sql_string)=make_sql_string_and_free(acl_strdup((yyvsp[(1) - (1)].str)), NULL);}
    break;

  case 400:

/* Line 1455 of yacc.c  */
#line 2312 "sql.yacc"
    { (yyval.sql_string)=make_sql_string_and_free(acl_strdup((yyvsp[(1) - (1)].str)), NULL);}
    break;

  case 401:

/* Line 1455 of yacc.c  */
#line 2313 "sql.yacc"
    { (yyval.sql_string)=make_sql_string_and_free(acl_strdup((yyvsp[(1) - (1)].str)), NULL);}
    break;

  case 402:

/* Line 1455 of yacc.c  */
#line 2318 "sql.yacc"
    { add_feature("RENAME_TABLE"); strcpy((yyval.str),A4GLSQLCV_rentab((yyvsp[(2) - (4)].str),(yyvsp[(4) - (4)].str))); }
    break;

  case 403:

/* Line 1455 of yacc.c  */
#line 2319 "sql.yacc"
    { add_feature("RENAME_COLUMN"); strcpy((yyval.str),A4GLSQLCV_rencol((yyvsp[(2) - (6)].str),(yyvsp[(4) - (6)].str),(yyvsp[(6) - (6)].str)) ); }
    break;

  case 406:

/* Line 1455 of yacc.c  */
#line 2327 "sql.yacc"
    {
		add_feature("UNLOCK_TABLE");
		SPRINTF2((yyval.str),"%s %s",(yyvsp[(1) - (2)].str),(yyvsp[(2) - (2)].str));
	}
    break;

  case 407:

/* Line 1455 of yacc.c  */
#line 2334 "sql.yacc"
    {
		add_feature("LOCK_TABLE");
		SPRINTF3((yyval.str),"%s %s %s",
					(yyvsp[(1) - (3)].str),
					(yyvsp[(2) - (3)].str),
					(yyvsp[(3) - (3)].str)
					);
		}
    break;

  case 408:

/* Line 1455 of yacc.c  */
#line 2345 "sql.yacc"
    { add_feature("LOCK_TABLE_SHARED");}
    break;

  case 409:

/* Line 1455 of yacc.c  */
#line 2346 "sql.yacc"
    {add_feature("LOCK_TABLE_EXCLUSIVE");}
    break;

  case 410:

/* Line 1455 of yacc.c  */
#line 2359 "sql.yacc"
    {strcpy((yyval.str),A4GLSQLCV_datetime_value((yyvsp[(1) - (1)].str)));}
    break;

  case 411:

/* Line 1455 of yacc.c  */
#line 2360 "sql.yacc"
    {strcpy((yyval.str),A4GLSQLCV_make_dtime_extend((yyvsp[(1) - (4)].str),(yyvsp[(2) - (4)].str),(yyvsp[(4) - (4)].str),0));}
    break;

  case 412:

/* Line 1455 of yacc.c  */
#line 2364 "sql.yacc"
    {strcpy((yyval.str),(yyvsp[(1) - (1)].str));}
    break;

  case 413:

/* Line 1455 of yacc.c  */
#line 2368 "sql.yacc"
    {strcpy((yyval.str),A4GLSQLCV_interval_value((yyvsp[(1) - (1)].str)));}
    break;

  case 414:

/* Line 1455 of yacc.c  */
#line 2369 "sql.yacc"
    {
			strcpy((yyval.str),A4GLSQLCV_make_ival_extend((yyvsp[(1) - (7)].str),(yyvsp[(2) - (7)].str),(yyvsp[(4) - (7)].str),(yyvsp[(7) - (7)].str),0));
		}
    break;

  case 415:

/* Line 1455 of yacc.c  */
#line 2372 "sql.yacc"
    {
		strcpy((yyval.str),A4GLSQLCV_make_ival_extend((yyvsp[(1) - (4)].str),(yyvsp[(2) - (4)].str),(char *)0, (yyvsp[(4) - (4)].str),0));
	}
    break;

  case 416:

/* Line 1455 of yacc.c  */
#line 2378 "sql.yacc"
    {SPRINTF1((yyval.str),"%s",(yyvsp[(1) - (1)].str));}
    break;

  case 417:

/* Line 1455 of yacc.c  */
#line 2382 "sql.yacc"
    {
	strcpy((yyval.str),(yyvsp[(2) - (2)].str));
}
    break;

  case 418:

/* Line 1455 of yacc.c  */
#line 2405 "sql.yacc"
    {
		(yyval.s_select_list_item_list)=(yyvsp[(3) - (3)].s_select_list_item_list);
		add_feature("ORDER_BY");
	}
    break;

  case 419:

/* Line 1455 of yacc.c  */
#line 2415 "sql.yacc"
    {
			(yyval.s_select_list_item_list)=local_new_select_list_item_list((yyvsp[(1) - (1)].s_select_list_item));
	}
    break;

  case 420:

/* Line 1455 of yacc.c  */
#line 2418 "sql.yacc"
    {
			(yyval.s_select_list_item_list)=local_add_select_list_item_list((yyvsp[(1) - (3)].s_select_list_item_list),(yyvsp[(3) - (3)].s_select_list_item));
	}
    break;

  case 421:

/* Line 1455 of yacc.c  */
#line 2424 "sql.yacc"
    {
		if (strcmp((yyvsp[(2) - (2)].str),"DESC")!=0) {
			(yyval.s_select_list_item)=new_select_list_item_simple_expr(E_SLI_ASC,(yyvsp[(1) - (2)].s_select_list_item));
		} else {
			(yyval.s_select_list_item)=new_select_list_item_simple_expr(E_SLI_DESC,(yyvsp[(1) - (2)].s_select_list_item));
		}
	}
    break;

  case 422:

/* Line 1455 of yacc.c  */
#line 2433 "sql.yacc"
    { 
		add_feature("ORDER_BY_NUMBER");
		(yyval.s_select_list_item)=new_select_list_item_literal((yyvsp[(1) - (1)].str));
	}
    break;

  case 423:

/* Line 1455 of yacc.c  */
#line 2437 "sql.yacc"
    {
		(yyval.s_select_list_item)=(yyvsp[(1) - (1)].s_select_list_item);
		(yyval.s_select_list_item)->data.type=E_SLI_COLUMN_ORDERBY;
	}
    break;

  case 424:

/* Line 1455 of yacc.c  */
#line 2444 "sql.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 425:

/* Line 1455 of yacc.c  */
#line 2446 "sql.yacc"
    {add_feature("ORDER_BY_ASC"); strcpy((yyval.str),"ASC");}
    break;

  case 426:

/* Line 1455 of yacc.c  */
#line 2448 "sql.yacc"
    {add_feature("ORDER_BY_DESC"); strcpy((yyval.str),"DESC");}
    break;

  case 427:

/* Line 1455 of yacc.c  */
#line 2452 "sql.yacc"
    {
		(yyval.s_select_list_item_list)=(yyvsp[(2) - (2)].s_select_list_item_list);
	}
    break;

  case 428:

/* Line 1455 of yacc.c  */
#line 2458 "sql.yacc"
    {
			(yyval.s_select_list_item_list)=local_new_select_list_item_list((yyvsp[(1) - (1)].s_select_list_item));
	}
    break;

  case 429:

/* Line 1455 of yacc.c  */
#line 2461 "sql.yacc"
    {
			(yyval.s_select_list_item_list)=local_add_select_list_item_list((yyvsp[(1) - (3)].s_select_list_item_list),(yyvsp[(3) - (3)].s_select_list_item));
	}
    break;

  case 430:

/* Line 1455 of yacc.c  */
#line 2467 "sql.yacc"
    { (yyval.s_select_list_item)=(yyvsp[(1) - (1)].s_select_list_item); }
    break;

  case 431:

/* Line 1455 of yacc.c  */
#line 2468 "sql.yacc"
    { (yyval.s_select_list_item)=new_select_list_item_literal((yyvsp[(1) - (1)].str)); }
    break;

  case 432:

/* Line 1455 of yacc.c  */
#line 2475 "sql.yacc"
    {
	(yyval.sql_string)=get_select_list_item(0,(yyvsp[(1) - (1)].s_select_list_item));
}
    break;

  case 433:

/* Line 1455 of yacc.c  */
#line 2488 "sql.yacc"
    {
		A4GL_set_sql_lineno(yylineno);
		(yyval.sql_string)=make_select_stmt_v2(current_upd_table, (yyvsp[(1) - (1)].s_select),"");
		map_select_stmt("SELECT",(yyvsp[(1) - (1)].s_select));
		A4GL_free_select_stmt((yyvsp[(1) - (1)].s_select));
}
    break;

  case 434:

/* Line 1455 of yacc.c  */
#line 2498 "sql.yacc"
    { 
	if (A4GLSQLCV_check_requirement("ALLOW_TIME_DATATYPE")) {
       		strcpy((yyval.str),"TIME"); break;
	} else {
       		strcpy((yyval.str),"DATETIME HOUR TO FRACTION(2)"); break;
	}
 }
    break;

  case 435:

/* Line 1455 of yacc.c  */
#line 2505 "sql.yacc"
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

  case 436:

/* Line 1455 of yacc.c  */
#line 2522 "sql.yacc"
    {
	if (A4GLSQLCV_check_requirement("ALLOW_TIMESTAMP_DATATYPE")) {
		strcpy((yyval.str),"TIMESTAMP");
	} else {
                strcpy((yyval.str),"DATETIME YEAR TO FRACTION(2)"); 
	}
 }
    break;

  case 437:

/* Line 1455 of yacc.c  */
#line 2529 "sql.yacc"
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

  case 438:

/* Line 1455 of yacc.c  */
#line 2554 "sql.yacc"
    { 
		//start_bind('i',0);
		 set_ignore_indicators();}
    break;

  case 439:

/* Line 1455 of yacc.c  */
#line 2556 "sql.yacc"
    { clr_ignore_indicators();}
    break;

  case 440:

/* Line 1455 of yacc.c  */
#line 2558 "sql.yacc"
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

  case 441:

/* Line 1455 of yacc.c  */
#line 2579 "sql.yacc"
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

  case 442:

/* Line 1455 of yacc.c  */
#line 2622 "sql.yacc"
    { (yyval.s_select)=0;}
    break;

  case 443:

/* Line 1455 of yacc.c  */
#line 2623 "sql.yacc"
    { 
		(yyval.s_select)=(yyvsp[(3) - (3)].s_select);
		(yyval.s_select)->union_op=acl_strdup((yyvsp[(2) - (3)].str));
		A4GL_set_associated_mem((yyval.s_select), (yyval.s_select)->union_op);
		add_feature("SELECT_UNION"); 
	}
    break;

  case 444:

/* Line 1455 of yacc.c  */
#line 2637 "sql.yacc"
    {
		(yyval.s_select_finish)=0;
	}
    break;

  case 445:

/* Line 1455 of yacc.c  */
#line 2640 "sql.yacc"
    {  
		(yyval.s_select_finish)=acl_malloc2(sizeof(struct s_select_finish));
		(yyval.s_select_finish)->order_by=(yyvsp[(1) - (1)].s_select_list_item_list);
		(yyval.s_select_finish)->insert_into=0;
		(yyval.s_select_finish)->into_temp=0;
		(yyval.s_select_finish)->nolog=0;
	}
    break;

  case 446:

/* Line 1455 of yacc.c  */
#line 2647 "sql.yacc"
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

  case 447:

/* Line 1455 of yacc.c  */
#line 2657 "sql.yacc"
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

  case 449:

/* Line 1455 of yacc.c  */
#line 2675 "sql.yacc"
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

  case 450:

/* Line 1455 of yacc.c  */
#line 2688 "sql.yacc"
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

  case 451:

/* Line 1455 of yacc.c  */
#line 2703 "sql.yacc"
    {(yyval.integer_val)=-1;}
    break;

  case 452:

/* Line 1455 of yacc.c  */
#line 2705 "sql.yacc"
    {
		(yyval.integer_val)=atol((yyvsp[(2) - (2)].str));
	}
    break;

  case 453:

/* Line 1455 of yacc.c  */
#line 2711 "sql.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 454:

/* Line 1455 of yacc.c  */
#line 2712 "sql.yacc"
    {strcpy((yyval.str),"ALL"); add_feature("SELECT_ALL");}
    break;

  case 455:

/* Line 1455 of yacc.c  */
#line 2713 "sql.yacc"
    {strcpy((yyval.str),"DISTINCT"); add_feature("SELECT_DISTINCT");}
    break;

  case 456:

/* Line 1455 of yacc.c  */
#line 2714 "sql.yacc"
    {strcpy((yyval.str),"DISTINCT");
		add_feature("SELECT_UNIQUE");
		ansi_violation("Use DISTINCT not UNIQUE",0);
		strcpy((yyval.str),"DISTINCT");
	}
    break;

  case 457:

/* Line 1455 of yacc.c  */
#line 2724 "sql.yacc"
    { 
		 (yyval.s_select_list_item_list)=local_new_select_list_item_list((yyvsp[(1) - (1)].s_select_list_item));
	}
    break;

  case 458:

/* Line 1455 of yacc.c  */
#line 2727 "sql.yacc"
    { 
		(yyval.s_select_list_item_list)=local_add_select_list_item_list((yyvsp[(1) - (3)].s_select_list_item_list),(yyvsp[(3) - (3)].s_select_list_item));
	}
    break;

  case 459:

/* Line 1455 of yacc.c  */
#line 2733 "sql.yacc"
    {
		(yyval.s_select_list_item)=(yyvsp[(1) - (1)].s_select_list_item);
	}
    break;

  case 460:

/* Line 1455 of yacc.c  */
#line 2736 "sql.yacc"
    {
		(yyval.s_select_list_item)=(yyvsp[(1) - (2)].s_select_list_item);
		(yyval.s_select_list_item)->alias=acl_strdup((yyvsp[(2) - (2)].str));
		A4GL_set_associated_mem((yyval.s_select_list_item), (yyval.s_select_list_item)->alias);
	}
    break;

  case 461:

/* Line 1455 of yacc.c  */
#line 2741 "sql.yacc"
    {
		(yyval.s_select_list_item)=(yyvsp[(1) - (3)].s_select_list_item);
		(yyval.s_select_list_item)->alias=acl_strdup((yyvsp[(3) - (3)].str));
		A4GL_set_associated_mem((yyval.s_select_list_item), (yyval.s_select_list_item)->alias);
	}
    break;

  case 462:

/* Line 1455 of yacc.c  */
#line 2750 "sql.yacc"
    {
		(yyval.s_select_list_item)=(yyvsp[(1) - (1)].s_select_list_item); /* A4GLSQLCV_check_expr($<sql_string>1) */
	}
    break;

  case 463:

/* Line 1455 of yacc.c  */
#line 2753 "sql.yacc"
    {
		(yyval.s_select_list_item)=(yyvsp[(2) - (2)].s_select_list_item);
		(yyval.s_select_list_item)->sign='-';
	}
    break;

  case 464:

/* Line 1455 of yacc.c  */
#line 2757 "sql.yacc"
    {
		(yyval.s_select_list_item)=(yyvsp[(2) - (2)].s_select_list_item);
	}
    break;

  case 465:

/* Line 1455 of yacc.c  */
#line 2764 "sql.yacc"
    {
			(yyval.s_select_list_item)=new_select_list_item_op_expr ((yyvsp[(1) - (3)].s_select_list_item), (yyvsp[(3) - (3)].s_select_list_item), "/");
	}
    break;

  case 466:

/* Line 1455 of yacc.c  */
#line 2767 "sql.yacc"
    {
			(yyval.s_select_list_item)=new_select_list_item_simple_expr((enum e_sli)(yyvsp[(2) - (2)].integer_val), (yyvsp[(1) - (2)].s_select_list_item));
	}
    break;

  case 467:

/* Line 1455 of yacc.c  */
#line 2770 "sql.yacc"
    {
			(yyval.s_select_list_item)=new_select_list_item_op_expr ((yyvsp[(1) - (3)].s_select_list_item), (yyvsp[(3) - (3)].s_select_list_item), "*");
	}
    break;

  case 468:

/* Line 1455 of yacc.c  */
#line 2773 "sql.yacc"
    {
			(yyval.s_select_list_item)=new_select_list_item_op_expr ((yyvsp[(1) - (3)].s_select_list_item), (yyvsp[(3) - (3)].s_select_list_item), "+");
	}
    break;

  case 469:

/* Line 1455 of yacc.c  */
#line 2776 "sql.yacc"
    {
			(yyval.s_select_list_item)=new_select_list_item_op_expr ((yyvsp[(1) - (3)].s_select_list_item), (yyvsp[(3) - (3)].s_select_list_item), "-");
	}
    break;

  case 470:

/* Line 1455 of yacc.c  */
#line 2779 "sql.yacc"
    { (yyval.s_select_list_item)=new_select_list_item_literal((yyvsp[(1) - (1)].str)); }
    break;

  case 471:

/* Line 1455 of yacc.c  */
#line 2780 "sql.yacc"
    { (yyval.s_select_list_item)=new_select_list_item_builtin_const(E_SLI_BUILTIN_CONST_TRUE); }
    break;

  case 472:

/* Line 1455 of yacc.c  */
#line 2781 "sql.yacc"
    { (yyval.s_select_list_item)=new_select_list_item_builtin_const(E_SLI_BUILTIN_CONST_FALSE); }
    break;

  case 473:

/* Line 1455 of yacc.c  */
#line 2782 "sql.yacc"
    { (yyval.s_select_list_item)=new_select_list_item_builtin_const(E_SLI_BUILTIN_CONST_USER); }
    break;

  case 474:

/* Line 1455 of yacc.c  */
#line 2783 "sql.yacc"
    { (yyval.s_select_list_item)=new_select_list_item_builtin_const(E_SLI_BUILTIN_CONST_TODAY); }
    break;

  case 475:

/* Line 1455 of yacc.c  */
#line 2784 "sql.yacc"
    { (yyval.s_select_list_item)=new_select_list_item_builtin_const(E_SLI_BUILTIN_CONST_ROWID); }
    break;

  case 476:

/* Line 1455 of yacc.c  */
#line 2785 "sql.yacc"
    { (yyval.s_select_list_item)=new_select_list_item_builtin_const(E_SLI_BUILTIN_CONST_TIME); }
    break;

  case 477:

/* Line 1455 of yacc.c  */
#line 2786 "sql.yacc"
    { (yyval.s_select_list_item)=new_select_list_item_builtin_const(E_SLI_BUILTIN_CONST_STAR); }
    break;

  case 478:

/* Line 1455 of yacc.c  */
#line 2787 "sql.yacc"
    { (yyval.s_select_list_item)=new_select_list_item_builtin_const(E_SLI_BUILTIN_CONST_COUNT_STAR); }
    break;

  case 479:

/* Line 1455 of yacc.c  */
#line 2789 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_agg1(E_SLI_BUILTIN_AGG_AVG,(yyvsp[(3) - (5)].str),(yyvsp[(4) - (5)].s_select_list_item));
		add_feature("SELECT_AVG");
	}
    break;

  case 480:

/* Line 1455 of yacc.c  */
#line 2793 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_agg1(E_SLI_BUILTIN_AGG_MAX,(yyvsp[(3) - (5)].str),(yyvsp[(4) - (5)].s_select_list_item));
		add_feature("SELECT_MAX");
	}
    break;

  case 481:

/* Line 1455 of yacc.c  */
#line 2797 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_agg1(E_SLI_BUILTIN_AGG_MIN,(yyvsp[(3) - (5)].str),(yyvsp[(4) - (5)].s_select_list_item));
		add_feature("SELECT_MIN");
	}
    break;

  case 482:

/* Line 1455 of yacc.c  */
#line 2801 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_agg1(E_SLI_BUILTIN_AGG_SUM,(yyvsp[(3) - (5)].str),(yyvsp[(4) - (5)].s_select_list_item));
		add_feature("SELECT_SUM");
	}
    break;

  case 483:

/* Line 1455 of yacc.c  */
#line 2805 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_agg1(E_SLI_BUILTIN_AGG_COUNT,(yyvsp[(3) - (5)].str),(yyvsp[(4) - (5)].s_select_list_item));
		add_feature("SELECT_COUNT");
	}
    break;

  case 484:

/* Line 1455 of yacc.c  */
#line 2809 "sql.yacc"
    {
		add_sql_function((yyvsp[(1) - (3)].str));
		(yyval.s_select_list_item)=new_select_list_item_fcall((yyvsp[(1) - (3)].str),0);
	}
    break;

  case 485:

/* Line 1455 of yacc.c  */
#line 2813 "sql.yacc"
    {
		add_sql_function((yyvsp[(1) - (4)].str));
		(yyval.s_select_list_item)=new_select_list_item_fcall((yyvsp[(1) - (4)].str),(yyvsp[(3) - (4)].s_select_list_item_list));
	}
    break;

  case 486:

/* Line 1455 of yacc.c  */
#line 2817 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_builtin_fcall(E_SLI_BUILTIN_FUNC_YEAR,(yyvsp[(3) - (4)].s_select_list_item_list));
	}
    break;

  case 487:

/* Line 1455 of yacc.c  */
#line 2820 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_builtin_fcall(E_SLI_BUILTIN_FUNC_MONTH,(yyvsp[(3) - (4)].s_select_list_item_list));
	}
    break;

  case 488:

/* Line 1455 of yacc.c  */
#line 2823 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_builtin_fcall(E_SLI_BUILTIN_FUNC_DAY,(yyvsp[(3) - (4)].s_select_list_item_list));
	}
    break;

  case 489:

/* Line 1455 of yacc.c  */
#line 2826 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_builtin_fcall(E_SLI_BUILTIN_FUNC_MDY,(yyvsp[(3) - (4)].s_select_list_item_list));
	}
    break;

  case 490:

/* Line 1455 of yacc.c  */
#line 2829 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_builtin_fcall(E_SLI_BUILTIN_FUNC_WEEKDAY,(yyvsp[(3) - (4)].s_select_list_item_list));
	}
    break;

  case 491:

/* Line 1455 of yacc.c  */
#line 2832 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_builtin_fcall(E_SLI_BUILTIN_FUNC_DOW,(yyvsp[(3) - (4)].s_select_list_item_list));
	}
    break;

  case 492:

/* Line 1455 of yacc.c  */
#line 2835 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_builtin_fcall(E_SLI_BUILTIN_FUNC_DATE,(yyvsp[(3) - (4)].s_select_list_item_list));
	}
    break;

  case 493:

/* Line 1455 of yacc.c  */
#line 2838 "sql.yacc"
    {
		  (yyval.s_select_list_item)=new_select_list_item_simple_expr(E_SLI_BRACKET_EXPR,(yyvsp[(2) - (3)].s_select_list_item));
	}
    break;

  case 494:

/* Line 1455 of yacc.c  */
#line 2841 "sql.yacc"
    { 
		add_feature("EXTEND"); 
		(yyval.s_select_list_item)=(yyvsp[(3) - (4)].s_select_list_item);
	}
    break;

  case 495:

/* Line 1455 of yacc.c  */
#line 2845 "sql.yacc"
    { 
		(yyval.s_select_list_item)=new_select_list_item_datetime((yyvsp[(1) - (1)].str));
		add_feature("FUNC_DATETIME");
	}
    break;

  case 496:

/* Line 1455 of yacc.c  */
#line 2849 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_interval((yyvsp[(1) - (1)].str));
		add_feature("FUNC_INTERVAL");
	}
    break;

  case 497:

/* Line 1455 of yacc.c  */
#line 2853 "sql.yacc"
    {
		(yyval.s_select_list_item)=(yyvsp[(2) - (3)].s_select_list_item);
	}
    break;

  case 498:

/* Line 1455 of yacc.c  */
#line 2861 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_case((yyvsp[(1) - (1)].s_select_list_item));
	}
    break;

  case 499:

/* Line 1455 of yacc.c  */
#line 2864 "sql.yacc"
    {
		(yyval.s_select_list_item)=append_select_list_item_case(
							(yyvsp[(1) - (2)].s_select_list_item),
							(yyvsp[(2) - (2)].s_select_list_item));
	}
    break;

  case 500:

/* Line 1455 of yacc.c  */
#line 2873 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_case_element(
				(yyvsp[(2) - (4)].s_select_list_item),
				(yyvsp[(4) - (4)].s_select_list_item));

	}
    break;

  case 501:

/* Line 1455 of yacc.c  */
#line 2879 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_case_element( 0, (yyvsp[(2) - (2)].s_select_list_item));
	}
    break;

  case 502:

/* Line 1455 of yacc.c  */
#line 2886 "sql.yacc"
    {
		(yyval.s_select_list_item_list)=local_new_select_list_item_list((yyvsp[(1) - (1)].s_select_list_item));
	}
    break;

  case 503:

/* Line 1455 of yacc.c  */
#line 2889 "sql.yacc"
    {
			(yyval.s_select_list_item_list)=local_add_select_list_item_list((yyvsp[(1) - (3)].s_select_list_item_list),(yyvsp[(3) - (3)].s_select_list_item));
	}
    break;

  case 504:

/* Line 1455 of yacc.c  */
#line 2917 "sql.yacc"
    {
			(yyval.s_select_list_item)=new_select_list_item_extend(new_select_list_item_builtin_const(E_SLI_BUILTIN_CONST_CURRENT),(yyvsp[(3) - (5)].str),(yyvsp[(5) - (5)].str));
	}
    break;

  case 505:

/* Line 1455 of yacc.c  */
#line 2920 "sql.yacc"
    {
			(yyval.s_select_list_item)=new_select_list_item_extend((yyvsp[(1) - (5)].s_select_list_item),(yyvsp[(3) - (5)].str),(yyvsp[(5) - (5)].str));
	}
    break;

  case 506:

/* Line 1455 of yacc.c  */
#line 2923 "sql.yacc"
    {
			(yyval.s_select_list_item)=new_select_list_item_extend(new_select_list_item_builtin_const(E_SLI_BUILTIN_CONST_CURRENT),(yyvsp[(2) - (4)].str),(yyvsp[(4) - (4)].str));
	}
    break;

  case 507:

/* Line 1455 of yacc.c  */
#line 2926 "sql.yacc"
    {
			(yyval.s_select_list_item)=new_select_list_item_extend((yyvsp[(1) - (5)].s_select_list_item),(yyvsp[(3) - (5)].str),(yyvsp[(5) - (5)].str));
	}
    break;

  case 508:

/* Line 1455 of yacc.c  */
#line 2932 "sql.yacc"
    {(yyval.integer_val)=E_SLI_UNITS_YEAR;}
    break;

  case 509:

/* Line 1455 of yacc.c  */
#line 2933 "sql.yacc"
    {(yyval.integer_val)=E_SLI_UNITS_MONTH;}
    break;

  case 510:

/* Line 1455 of yacc.c  */
#line 2934 "sql.yacc"
    {(yyval.integer_val)=E_SLI_UNITS_DAY;}
    break;

  case 511:

/* Line 1455 of yacc.c  */
#line 2935 "sql.yacc"
    {(yyval.integer_val)=E_SLI_UNITS_HOUR;}
    break;

  case 512:

/* Line 1455 of yacc.c  */
#line 2936 "sql.yacc"
    {(yyval.integer_val)=E_SLI_UNITS_MINUTE;}
    break;

  case 513:

/* Line 1455 of yacc.c  */
#line 2937 "sql.yacc"
    {(yyval.integer_val)=E_SLI_UNITS_SECOND;}
    break;

  case 514:

/* Line 1455 of yacc.c  */
#line 2942 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_op_slil((yyvsp[(1) - (5)].s_select_list_item),(yyvsp[(4) - (5)].s_select_list_item_list),E_SLI_IN_VALUES);
                add_feature("WHERE_IN");
        }
    break;

  case 515:

/* Line 1455 of yacc.c  */
#line 2946 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_op_sli((yyvsp[(1) - (3)].s_select_list_item),(yyvsp[(3) - (3)].s_select_list_item),E_SLI_IN_SELECT);
                add_feature("WHERE_IN_SELECT");
        }
    break;

  case 516:

/* Line 1455 of yacc.c  */
#line 2950 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_op_slil((yyvsp[(1) - (5)].s_select_list_item),(yyvsp[(4) - (5)].s_select_list_item_list),E_SLI_NOT_IN_VALUES);
                add_feature("WHERE_IN");
        }
    break;

  case 517:

/* Line 1455 of yacc.c  */
#line 2954 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_op_sli((yyvsp[(1) - (3)].s_select_list_item),(yyvsp[(3) - (3)].s_select_list_item),E_SLI_NOT_IN_SELECT);
                add_feature("WHERE_IN_SELECT");
        }
    break;

  case 518:

/* Line 1455 of yacc.c  */
#line 2961 "sql.yacc"
    {
		(yyval.s_select_list_item_list)=local_new_select_list_item_list((yyvsp[(1) - (1)].s_select_list_item));
	}
    break;

  case 519:

/* Line 1455 of yacc.c  */
#line 2964 "sql.yacc"
    {
                (yyval.s_select_list_item_list)=local_add_select_list_item_list((yyvsp[(1) - (3)].s_select_list_item_list),(yyvsp[(3) - (3)].s_select_list_item));
	}
    break;

  case 520:

/* Line 1455 of yacc.c  */
#line 2969 "sql.yacc"
    { (yyval.s_select_list_item)=(yyvsp[(1) - (1)].s_select_list_item);}
    break;

  case 521:

/* Line 1455 of yacc.c  */
#line 2970 "sql.yacc"
    { (yyval.s_select_list_item)=new_select_list_item_literal((yyvsp[(1) - (1)].str)); }
    break;

  case 522:

/* Line 1455 of yacc.c  */
#line 2971 "sql.yacc"
    { 
		char buff[256]; SPRINTF1(buff," -%s",(yyvsp[(2) - (2)].str)); (yyval.s_select_list_item)=new_select_list_item_literal(buff); }
    break;

  case 523:

/* Line 1455 of yacc.c  */
#line 2973 "sql.yacc"
    { char buff[256]; SPRINTF1(buff," -%s",(yyvsp[(2) - (2)].str)); (yyval.s_select_list_item)=new_select_list_item_literal(buff); }
    break;

  case 524:

/* Line 1455 of yacc.c  */
#line 2979 "sql.yacc"
    {
                if (strstr((yyvsp[(1) - (1)].str),"systables")!=0) { add_feature("IFX_SYSTABLES"); }
                if (strstr((yyvsp[(1) - (1)].str),"syscolumns")!=0) { add_feature("IFX_SYSCOLUMNS"); }
                if (strstr((yyvsp[(1) - (1)].str),"sysindexes")!=0) { add_feature("IFX_SYSINDEXES"); }
                strcpy((yyval.str),A4GLSQLCV_check_tablename((yyvsp[(1) - (1)].str)));
                }
    break;

  case 525:

/* Line 1455 of yacc.c  */
#line 2989 "sql.yacc"
    {
	     SPRINTF1((yyval.str),"%s", A4GLSQLCV_ownerize_tablename(NULL, A4GL_strip_quotes((yyvsp[(1) - (1)].str))));
             ADDMAP("Use Table",(yyval.str));
        }
    break;

  case 526:

/* Line 1455 of yacc.c  */
#line 2993 "sql.yacc"
    {
	     SPRINTF1((yyval.str),"%s", A4GLSQLCV_ownerize_tablename((yyvsp[(1) - (3)].str), (yyvsp[(3) - (3)].str)));
	     ADDMAP("Use Table",(yyval.str));
        }
    break;

  case 527:

/* Line 1455 of yacc.c  */
#line 2997 "sql.yacc"
    {
	     SPRINTF1((yyval.str),"%s", A4GLSQLCV_ownerize_tablename(NULL, (yyvsp[(1) - (1)].str)));
	     ADDMAP("Use Table",(yyval.str));
	}
    break;

  case 528:

/* Line 1455 of yacc.c  */
#line 3001 "sql.yacc"
    {
	     SPRINTF1((yyval.str),"%s", A4GLSQLCV_db_tablename((yyvsp[(1) - (3)].str), NULL, A4GLSQLCV_ownerize_tablename(NULL, (yyvsp[(3) - (3)].str))));
	     ADDMAP("Use Table",(yyval.str));
	}
    break;

  case 529:

/* Line 1455 of yacc.c  */
#line 3005 "sql.yacc"
    {
	     SPRINTF1((yyval.str),"%s", A4GLSQLCV_db_tablename((yyvsp[(1) - (5)].str), NULL, A4GLSQLCV_ownerize_tablename((yyvsp[(3) - (5)].str),(yyvsp[(5) - (5)].str))));
	     ADDMAP("Use Table",(yyval.str));
        }
    break;

  case 530:

/* Line 1455 of yacc.c  */
#line 3009 "sql.yacc"
    {
	     SPRINTF1((yyval.str),"%s", A4GLSQLCV_db_tablename(NULL,(yyvsp[(1) - (3)].str), A4GLSQLCV_ownerize_tablename(NULL, (yyvsp[(3) - (3)].str))));
	     ADDMAP("Use Table",(yyval.str));
	}
    break;

  case 531:

/* Line 1455 of yacc.c  */
#line 3013 "sql.yacc"
    {
	     SPRINTF1((yyval.str),"%s", A4GLSQLCV_db_tablename((yyvsp[(1) - (5)].str), (yyvsp[(3) - (5)].str), A4GLSQLCV_ownerize_tablename(NULL, (yyvsp[(5) - (5)].str))));
	     ADDMAP("Use Table",(yyval.str));
	}
    break;

  case 532:

/* Line 1455 of yacc.c  */
#line 3017 "sql.yacc"
    {
	     SPRINTF1((yyval.str),"%s", A4GLSQLCV_db_tablename((yyvsp[(1) - (7)].str), (yyvsp[(3) - (7)].str), A4GLSQLCV_ownerize_tablename((yyvsp[(5) - (7)].str), (yyvsp[(7) - (7)].str))));
	     ADDMAP("Use Table",(yyval.str));
        }
    break;

  case 533:

/* Line 1455 of yacc.c  */
#line 3025 "sql.yacc"
    {
                if (strstr((yyvsp[(1) - (1)].str),"systables")!=0) { add_feature("IFX_SYSTABLES"); }
                if (strstr((yyvsp[(1) - (1)].str),"syscolumns")!=0) { add_feature("IFX_SYSCOLUMNS"); }
                if (strstr((yyvsp[(1) - (1)].str),"sysindexes")!=0) { add_feature("IFX_SYSINDEXES"); }
                strcpy((yyval.str),A4GLSQLCV_check_tablename((yyvsp[(1) - (1)].str)));
                }
    break;

  case 534:

/* Line 1455 of yacc.c  */
#line 3035 "sql.yacc"
    {

	     SPRINTF1((yyval.str),"%s", A4GLSQLCV_ownerize_tablename((yyvsp[(1) - (3)].str), (yyvsp[(3) - (3)].str)));
	     ADDMAP("Use Table",(yyval.str));
        }
    break;

  case 535:

/* Line 1455 of yacc.c  */
#line 3040 "sql.yacc"
    {
	     SPRINTF1((yyval.str),"%s", A4GLSQLCV_ownerize_tablename((yyvsp[(1) - (3)].str), (yyvsp[(3) - (3)].str)));
	     ADDMAP("Use Table",(yyval.str));
        }
    break;

  case 536:

/* Line 1455 of yacc.c  */
#line 3044 "sql.yacc"
    {
	     SPRINTF1((yyval.str),"%s", A4GLSQLCV_ownerize_tablename(NULL, A4GL_strip_quotes((yyvsp[(1) - (1)].str))));
	     ADDMAP("Use Table",(yyval.str));
        }
    break;

  case 537:

/* Line 1455 of yacc.c  */
#line 3048 "sql.yacc"
    {
             SPRINTF1((yyval.str),"%s", A4GLSQLCV_ownerize_tablename(NULL, (yyvsp[(1) - (1)].str)));
	     ADDMAP("Use Table",(yyval.str));
	}
    break;

  case 538:

/* Line 1455 of yacc.c  */
#line 3052 "sql.yacc"
    {
             SPRINTF1((yyval.str),"%s", A4GLSQLCV_db_tablename((yyvsp[(1) - (3)].str),NULL, A4GLSQLCV_ownerize_tablename(NULL, (yyvsp[(3) - (3)].str))));
	     ADDMAP("Use Table",(yyval.str));
	}
    break;

  case 539:

/* Line 1455 of yacc.c  */
#line 3056 "sql.yacc"
    {
	     SPRINTF1((yyval.str),"%s", A4GLSQLCV_db_tablename((yyvsp[(1) - (5)].str), NULL,A4GLSQLCV_ownerize_tablename((yyvsp[(3) - (5)].str), (yyvsp[(5) - (5)].str))));
	     ADDMAP("Use Table",(yyval.str));
        }
    break;

  case 540:

/* Line 1455 of yacc.c  */
#line 3061 "sql.yacc"
    {
             SPRINTF1((yyval.str),"%s", A4GLSQLCV_db_tablename(NULL, (yyvsp[(1) - (3)].str), A4GLSQLCV_ownerize_tablename(NULL, (yyvsp[(3) - (3)].str))));
	     ADDMAP("Use Table",(yyval.str));
	}
    break;

  case 541:

/* Line 1455 of yacc.c  */
#line 3065 "sql.yacc"
    {
            SPRINTF1((yyval.str),"%s", A4GLSQLCV_db_tablename( (yyvsp[(1) - (5)].str), (yyvsp[(3) - (5)].str), A4GLSQLCV_ownerize_tablename(NULL, (yyvsp[(5) - (5)].str))));
	    ADDMAP("Use Table",(yyval.str));
	}
    break;

  case 542:

/* Line 1455 of yacc.c  */
#line 3069 "sql.yacc"
    {
	     SPRINTF1((yyval.str),"%s", A4GLSQLCV_db_tablename((yyvsp[(1) - (7)].str), (yyvsp[(3) - (7)].str), A4GLSQLCV_ownerize_tablename((yyvsp[(5) - (7)].str), (yyvsp[(7) - (7)].str))));
	     ADDMAP("Use Table",(yyval.str));
        }
    break;

  case 543:

/* Line 1455 of yacc.c  */
#line 3077 "sql.yacc"
    {
	     SPRINTF1((yyval.str),"%s", A4GLSQLCV_ownerize_tablename((yyvsp[(1) - (3)].str), (yyvsp[(3) - (3)].str)));
        }
    break;

  case 544:

/* Line 1455 of yacc.c  */
#line 3080 "sql.yacc"
    {
	        SPRINTF1((yyval.str),"%s", A4GLSQLCV_ownerize_tablename(NULL, (yyvsp[(1) - (1)].str)));
                ADDMAP("Use Index",(yyval.str));
        }
    break;

  case 545:

/* Line 1455 of yacc.c  */
#line 3085 "sql.yacc"
    {strcpy((yyval.str),(yyvsp[(1) - (1)].str)); ADDMAP("Use Index",(yyvsp[(1) - (1)].str)); }
    break;

  case 546:

/* Line 1455 of yacc.c  */
#line 3086 "sql.yacc"
    { SPRINTF3((yyval.str),"%s%s%s",(yyvsp[(1) - (3)].str),(yyvsp[(2) - (3)].str),(yyvsp[(3) - (3)].str)); ADDMAP("Use Index",(yyval.str)); }
    break;

  case 547:

/* Line 1455 of yacc.c  */
#line 3087 "sql.yacc"
    {
	     SPRINTF2((yyval.str),"%s:%s", (yyvsp[(1) - (5)].str), A4GLSQLCV_ownerize_tablename((yyvsp[(3) - (5)].str), (yyvsp[(5) - (5)].str)));
             ADDMAP("Use Index",(yyval.str));
        }
    break;

  case 548:

/* Line 1455 of yacc.c  */
#line 3092 "sql.yacc"
    {strcpy((yyval.str),(yyvsp[(1) - (3)].str)); ADDMAP("Use Index",(yyvsp[(1) - (3)].str)); }
    break;

  case 549:

/* Line 1455 of yacc.c  */
#line 3093 "sql.yacc"
    { SPRINTF4((yyval.str),"%s@%s%s%s",(yyvsp[(1) - (5)].str),(yyvsp[(3) - (5)].str),(yyvsp[(4) - (5)].str),(yyvsp[(5) - (5)].str)); ADDMAP("Use Index",(yyval.str)); }
    break;

  case 550:

/* Line 1455 of yacc.c  */
#line 3094 "sql.yacc"
    {
	     SPRINTF3((yyval.str),"%s@%s:%s", (yyvsp[(1) - (7)].str), (yyvsp[(3) - (7)].str), A4GLSQLCV_ownerize_tablename((yyvsp[(5) - (7)].str), (yyvsp[(7) - (7)].str)));
             ADDMAP("Use Index",(yyval.str));
        }
    break;

  case 552:

/* Line 1455 of yacc.c  */
#line 3105 "sql.yacc"
    {
                      (yyval.ptr)=A4GL_new_expr_simple_string(A4GL_get_clobbered_from((yyval.str)), ET_EXPR_IDENTIFIER);
	}
    break;

  case 554:

/* Line 1455 of yacc.c  */
#line 3111 "sql.yacc"
    { sprintf((yyval.str),".%s",(yyvsp[(2) - (2)].str)); }
    break;

  case 556:

/* Line 1455 of yacc.c  */
#line 3116 "sql.yacc"
    {strcpy((yyval.str), A4GL_strip_quotes ((yyvsp[(1) - (1)].str)));}
    break;

  case 561:

/* Line 1455 of yacc.c  */
#line 3167 "sql.yacc"
    {
			int converted;
			(yyval.sql_string)=get_insert_cmd((yyvsp[(1) - (1)].insert_cmd),&converted);
			A4GL_free_associated_mem((yyvsp[(1) - (1)].insert_cmd));
			acl_free((yyvsp[(1) - (1)].insert_cmd));

		}
    break;

  case 562:

/* Line 1455 of yacc.c  */
#line 3174 "sql.yacc"
    {
			int converted;
			(yyval.sql_string)=get_update_cmd((yyvsp[(1) - (1)].update_cmd),&converted);
			A4GL_free_associated_mem((yyvsp[(1) - (1)].update_cmd));
			acl_free((yyvsp[(1) - (1)].update_cmd));
		}
    break;

  case 563:

/* Line 1455 of yacc.c  */
#line 3180 "sql.yacc"
    {
			int converted;
			(yyval.sql_string)=get_delete_cmd((yyvsp[(1) - (1)].delete_cmd),&converted);
			A4GL_free_associated_mem((yyvsp[(1) - (1)].delete_cmd));
			acl_free((yyvsp[(1) - (1)].delete_cmd));
		}
    break;

  case 566:

/* Line 1455 of yacc.c  */
#line 3195 "sql.yacc"
    { print_exec_select((yyvsp[(1) - (1)].sql_string));  }
    break;

  case 567:

/* Line 1455 of yacc.c  */
#line 3196 "sql.yacc"
    { print_exec_select((yyvsp[(1) - (1)].sql_string));  }
    break;

  case 569:

/* Line 1455 of yacc.c  */
#line 3198 "sql.yacc"
    { print_exec_select((yyvsp[(1) - (1)].sql_string));  }
    break;

  case 570:

/* Line 1455 of yacc.c  */
#line 3200 "sql.yacc"
    {
			print_sql_commit ((yyvsp[(1) - (1)].integer_val));
	}
    break;

  case 571:

/* Line 1455 of yacc.c  */
#line 3203 "sql.yacc"
    {print_unable_to_parse();}
    break;

  case 572:

/* Line 1455 of yacc.c  */
#line 3207 "sql.yacc"
    { (yyval.sql_string)=make_sql_string_and_free((yyvsp[(1) - (2)].sql_string),acl_strdup((yyvsp[(2) - (2)].str)),0);
}
    break;

  case 574:

/* Line 1455 of yacc.c  */
#line 3216 "sql.yacc"
    {
			(yyval.sql_string)=make_select_stmt_v2("", (yyvsp[(1) - (1)].s_select),"");
			A4GL_free_select_stmt((yyvsp[(1) - (1)].s_select));
		}
    break;

  case 575:

/* Line 1455 of yacc.c  */
#line 3222 "sql.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 576:

/* Line 1455 of yacc.c  */
#line 3223 "sql.yacc"
    {
			strcpy((yyval.str),A4GLSQLCV_get_forupdate(NULL));
		}
    break;

  case 577:

/* Line 1455 of yacc.c  */
#line 3226 "sql.yacc"
    {
			strcpy((yyval.str),A4GLSQLCV_get_forupdate((yyvsp[(2) - (2)].str)));
		}
    break;

  case 578:

/* Line 1455 of yacc.c  */
#line 3231 "sql.yacc"
    { strcpy((yyval.str),(yyvsp[(1) - (1)].str)); }
    break;

  case 579:

/* Line 1455 of yacc.c  */
#line 3232 "sql.yacc"
    { sprintf((yyval.str),"%s,%s",(yyvsp[(1) - (3)].str),(yyvsp[(3) - (3)].str)); }
    break;

  case 581:

/* Line 1455 of yacc.c  */
#line 3236 "sql.yacc"
    {sprintf((yyval.str),"%s.%s",A4GLSQLCV_ownerize_tablename(NULL, (yyvsp[(1) - (3)].str)),(yyvsp[(3) - (3)].str));}
    break;

  case 582:

/* Line 1455 of yacc.c  */
#line 3237 "sql.yacc"
    {
        sprintf((yyval.str),"%s.%s", A4GLSQLCV_ownerize_tablename((yyvsp[(1) - (5)].str), (yyvsp[(3) - (5)].str)), (yyvsp[(5) - (5)].str));
}
    break;

  case 583:

/* Line 1455 of yacc.c  */
#line 3247 "sql.yacc"
    { print_exec_sql(acl_strdup((yyvsp[(1) - (1)].str))); }
    break;

  case 584:

/* Line 1455 of yacc.c  */
#line 3248 "sql.yacc"
    { print_exec_sql(acl_strdup((yyvsp[(1) - (1)].str))); }
    break;

  case 585:

/* Line 1455 of yacc.c  */
#line 3249 "sql.yacc"
    { sprintf((yyval.str),"%s %s",(yyvsp[(1) - (2)].str),(yyvsp[(2) - (2)].str)); print_exec_sql(acl_strdup((yyval.str))); }
    break;

  case 586:

/* Line 1455 of yacc.c  */
#line 3250 "sql.yacc"
    { print_exec_sql(acl_strdup((yyvsp[(1) - (1)].str))); }
    break;

  case 587:

/* Line 1455 of yacc.c  */
#line 3251 "sql.yacc"
    { print_exec_sql(acl_strdup((yyvsp[(1) - (1)].str))); }
    break;

  case 588:

/* Line 1455 of yacc.c  */
#line 3252 "sql.yacc"
    { print_exec_sql(acl_strdup((yyvsp[(1) - (1)].str))); }
    break;

  case 589:

/* Line 1455 of yacc.c  */
#line 3253 "sql.yacc"
    { print_exec_sql(acl_strdup((yyvsp[(1) - (1)].str))); }
    break;

  case 590:

/* Line 1455 of yacc.c  */
#line 3254 "sql.yacc"
    { print_exec_sql(acl_strdup((yyvsp[(1) - (1)].str))); }
    break;

  case 591:

/* Line 1455 of yacc.c  */
#line 3258 "sql.yacc"
    { 
	char *s;
	s=acl_strdup((yyvsp[(1) - (1)].str));
	(yyval.s_select_list_item)=new_select_list_item_column_from_transform(s);
	acl_free(s);
	}
    break;

  case 592:

/* Line 1455 of yacc.c  */
#line 3264 "sql.yacc"
    {  
		(yyval.s_select_list_item)=new_select_list_item_builtin_const(E_SLI_QUERY_PLACEHOLDER);}
    break;

  case 593:

/* Line 1455 of yacc.c  */
#line 3266 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_replace_var((yyvsp[(1) - (1)].sql_string));
	}
    break;

  case 594:

/* Line 1455 of yacc.c  */
#line 3285 "sql.yacc"
    {
        add_feature("DATABASE_USED");
       conn_db((yyvsp[(2) - (3)].str));
}
    break;

  case 595:

/* Line 1455 of yacc.c  */
#line 3293 "sql.yacc"
    {
		(yyval.sql_string)=acl_strdup((yyvsp[(2) - (3)].str));
}
    break;

  case 596:

/* Line 1455 of yacc.c  */
#line 3300 "sql.yacc"
    {sprintf((yyval.str),"(%s)",(yyvsp[(2) - (3)].str));}
    break;

  case 597:

/* Line 1455 of yacc.c  */
#line 3301 "sql.yacc"
    { sprintf((yyval.str),"%s%s%s",(yyvsp[(1) - (3)].str),(yyvsp[(2) - (3)].str),(yyvsp[(3) - (3)].str));}
    break;

  case 598:

/* Line 1455 of yacc.c  */
#line 3302 "sql.yacc"
    {sprintf((yyval.str),"%d",atoi((yyvsp[(1) - (1)].str)));}
    break;

  case 599:

/* Line 1455 of yacc.c  */
#line 3303 "sql.yacc"
    {sprintf((yyval.str),"(%s%s)",(yyvsp[(1) - (2)].str),(yyvsp[(2) - (2)].str));}
    break;

  case 600:

/* Line 1455 of yacc.c  */
#line 3308 "sql.yacc"
    {strcpy((yyval.str),"+");}
    break;

  case 601:

/* Line 1455 of yacc.c  */
#line 3309 "sql.yacc"
    {strcpy((yyval.str),"-");}
    break;

  case 602:

/* Line 1455 of yacc.c  */
#line 3310 "sql.yacc"
    {strcpy((yyval.str),"*");}
    break;

  case 603:

/* Line 1455 of yacc.c  */
#line 3311 "sql.yacc"
    {strcpy((yyval.str),"/");}
    break;

  case 604:

/* Line 1455 of yacc.c  */
#line 3312 "sql.yacc"
    {strcpy((yyval.str),"%");}
    break;

  case 605:

/* Line 1455 of yacc.c  */
#line 3317 "sql.yacc"
    {strcpy((yyval.str),"+");}
    break;

  case 606:

/* Line 1455 of yacc.c  */
#line 3318 "sql.yacc"
    {strcpy((yyval.str),"-");}
    break;

  case 607:

/* Line 1455 of yacc.c  */
#line 3334 "sql.yacc"
    {sprintf((yyval.str),"%s", A4GLSQLCV_check_tablename((yyvsp[(1) - (1)].str)));}
    break;

  case 608:

/* Line 1455 of yacc.c  */
#line 3335 "sql.yacc"
    {sprintf((yyval.str),"%s.*", A4GLSQLCV_ownerize_tablename(NULL,(yyvsp[(1) - (3)].str)));}
    break;

  case 609:

/* Line 1455 of yacc.c  */
#line 3336 "sql.yacc"
    {sprintf((yyval.str),"%s.%s", (yyvsp[(1) - (3)].str),A4GLSQLCV_get_sqlconst ("rowid"));}
    break;

  case 610:

/* Line 1455 of yacc.c  */
#line 3337 "sql.yacc"
    {sprintf((yyval.str),"%s.%s", A4GLSQLCV_ownerize_tablename(NULL,(yyvsp[(1) - (3)].str)),(yyvsp[(3) - (3)].str));}
    break;

  case 611:

/* Line 1455 of yacc.c  */
#line 3338 "sql.yacc"
    {sprintf((yyval.str),"%s.%s", A4GLSQLCV_ownerize_tablename((yyvsp[(1) - (5)].str),(yyvsp[(3) - (5)].str)),(yyvsp[(5) - (5)].str));}
    break;

  case 612:

/* Line 1455 of yacc.c  */
#line 3339 "sql.yacc"
    {sprintf((yyval.str),"%s.%s", A4GLSQLCV_ownerize_tablename((yyvsp[(1) - (5)].str),(yyvsp[(3) - (5)].str)),(yyvsp[(5) - (5)].str));}
    break;

  case 613:

/* Line 1455 of yacc.c  */
#line 3340 "sql.yacc"
    {sprintf((yyval.str),"%s", (yyvsp[(1) - (4)].str)); strcpy((yyval.str), A4GLSQLCV_make_substr_s((yyvsp[(1) - (4)].str), 1,(yyvsp[(3) - (4)].str),0));}
    break;

  case 614:

/* Line 1455 of yacc.c  */
#line 3341 "sql.yacc"
    {char buff[256]; sprintf(buff,"%s.%s", A4GLSQLCV_ownerize_tablename(NULL,(yyvsp[(1) - (6)].str)),(yyvsp[(3) - (6)].str)); strcpy((yyval.str), A4GLSQLCV_make_substr_s(buff,1,(yyvsp[(5) - (6)].str),0));}
    break;

  case 615:

/* Line 1455 of yacc.c  */
#line 3342 "sql.yacc"
    {char buff[256]; sprintf(buff,"%s.%s", A4GLSQLCV_ownerize_tablename((yyvsp[(1) - (8)].str),(yyvsp[(3) - (8)].str)), (yyvsp[(5) - (8)].str)); strcpy((yyval.str), A4GLSQLCV_make_substr_s(buff,1,(yyvsp[(7) - (8)].str),0));  }
    break;

  case 616:

/* Line 1455 of yacc.c  */
#line 3343 "sql.yacc"
    {char buff[256]; sprintf(buff,"%s.%s", A4GLSQLCV_ownerize_tablename((yyvsp[(1) - (8)].str),(yyvsp[(3) - (8)].str)), (yyvsp[(5) - (8)].str));  strcpy((yyval.str), A4GLSQLCV_make_substr_s(buff,1,(yyvsp[(7) - (8)].str),0)); }
    break;

  case 617:

/* Line 1455 of yacc.c  */
#line 3345 "sql.yacc"
    {sprintf((yyval.str),"%s", (yyvsp[(1) - (6)].str)); strcpy((yyval.str), A4GLSQLCV_make_substr_s((yyvsp[(1) - (6)].str), 2,(yyvsp[(3) - (6)].str),(yyvsp[(5) - (6)].str)));}
    break;

  case 618:

/* Line 1455 of yacc.c  */
#line 3346 "sql.yacc"
    {char buff[256]; sprintf(buff,"%s.%s", A4GLSQLCV_ownerize_tablename(NULL,(yyvsp[(1) - (8)].str)),(yyvsp[(3) - (8)].str)); strcpy((yyval.str), A4GLSQLCV_make_substr_s(buff,2,(yyvsp[(5) - (8)].str),(yyvsp[(7) - (8)].str)));}
    break;

  case 619:

/* Line 1455 of yacc.c  */
#line 3347 "sql.yacc"
    {char buff[256]; sprintf(buff,"%s.%s", A4GLSQLCV_ownerize_tablename((yyvsp[(1) - (10)].str),(yyvsp[(3) - (10)].str)), (yyvsp[(5) - (10)].str)); strcpy((yyval.str), A4GLSQLCV_make_substr_s(buff,2,(yyvsp[(7) - (10)].str),(yyvsp[(9) - (10)].str)));  }
    break;

  case 620:

/* Line 1455 of yacc.c  */
#line 3348 "sql.yacc"
    {char buff[256]; sprintf(buff,"%s.%s", A4GLSQLCV_ownerize_tablename((yyvsp[(1) - (10)].str),(yyvsp[(3) - (10)].str)), (yyvsp[(5) - (10)].str));  strcpy((yyval.str), A4GLSQLCV_make_substr_s(buff,2,(yyvsp[(7) - (10)].str),(yyvsp[(9) - (10)].str))); }
    break;

  case 621:

/* Line 1455 of yacc.c  */
#line 3353 "sql.yacc"
    {
                (yyval.s_select_list_item)=(yyvsp[(1) - (1)].s_select_list_item);
        }
    break;

  case 622:

/* Line 1455 of yacc.c  */
#line 3356 "sql.yacc"
    {
                (yyval.s_select_list_item)=new_select_list_item_cast((yyvsp[(1) - (3)].s_select_list_item), (yyvsp[(3) - (3)].str));
        }
    break;

  case 623:

/* Line 1455 of yacc.c  */
#line 3365 "sql.yacc"
    { (yyvsp[(1) - (1)].s_select_list_item)=(yyvsp[(1) - (1)].s_select_list_item); }
    break;

  case 624:

/* Line 1455 of yacc.c  */
#line 3366 "sql.yacc"
    {(yyvsp[(1) - (1)].s_select_list_item)=(yyvsp[(1) - (1)].s_select_list_item);}
    break;

  case 625:

/* Line 1455 of yacc.c  */
#line 3367 "sql.yacc"
    {  (yyval.s_select_list_item)=new_select_list_item_sq(E_SQE_DONT_CARE,(yyvsp[(1) - (1)].s_select_list_item)); }
    break;

  case 626:

/* Line 1455 of yacc.c  */
#line 3368 "sql.yacc"
    { (yyval.s_select_list_item)=new_select_list_item_sq(E_SQE_ALL,(yyvsp[(2) - (2)].s_select_list_item)); }
    break;

  case 627:

/* Line 1455 of yacc.c  */
#line 3369 "sql.yacc"
    { (yyval.s_select_list_item)=new_select_list_item_sq(E_SQE_ANY,(yyvsp[(2) - (2)].s_select_list_item)); }
    break;

  case 628:

/* Line 1455 of yacc.c  */
#line 3370 "sql.yacc"
    { (yyval.s_select_list_item)=new_select_list_item_sq(E_SQE_SOME,(yyvsp[(2) - (2)].s_select_list_item)); }
    break;

  case 629:

/* Line 1455 of yacc.c  */
#line 3374 "sql.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 630:

/* Line 1455 of yacc.c  */
#line 3375 "sql.yacc"
    {strcpy((yyval.str),(yyvsp[(1) - (1)].str));}
    break;



/* Line 1455 of yacc.c  */
#line 8876 "y.tab.c"
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
#line 3380 "sql.yacc"


#if LEX_YY_PREGEN
#include "../../tools/no_yacc/cygwin/compilers/sql/lex.sqlparse_yy.c"
#else
#include "lex.yy.c"
#endif
#include "util.c"
#include "cmds.c"

