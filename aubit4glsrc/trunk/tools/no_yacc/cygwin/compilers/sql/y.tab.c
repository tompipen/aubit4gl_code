
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
     INT_VALUE = 2214,
     NAMED = 2215,
     NAMED_GEN = 2216,
     CHAR_VALUE = 2217,
     NOT_USED_1 = 2218,
     NOT_USED_2 = 2219,
     NOT_USED_3 = 2220,
     NOT_USED_4 = 2221,
     NOT_USED_5 = 2222,
     NOT_USED_6 = 2223,
     NOT_USED_7 = 2224,
     NOT_USED_8 = 2225,
     NUMBER_VALUE = 2226,
     SEMICOLON = 2227,
     QUESTION_MARK = 2228,
     CLINE = 2229,
     CH = 2230,
     MARK_VAR = 2231,
     END_MARK_VAR = 2232,
     LEFT_JOIN = 1002,
     DISPLAY_NULL_TO = 1005,
     UNBUFFERED = 1006,
     KW_PICTURE = 1007,
     ON_CHANGE = 1008,
     INNER_JOIN = 1009,
     UI_INTERFACE_DOT_FRONTCALL = 1012,
     UICOMBOBOX = 1016,
     UIFORM = 1019,
     USING_BTREE = 1035,
     USING_RTREE = 1036,
     SET_BUFFERED_LOG = 1061,
     SET_LOG = 1064,
     MDY = 1066,
     WEEKDAY = 1067,
     MODE_ANSI = 1070,
     START_DATABASE = 1071,
     WITH_LOG_IN = 1072,
     SET_CONSTRAINTS_ALL_IMMEDIATE = 1073,
     DATETIME_VALUE = 1086,
     INTERVAL_VALUE = 1087,
     RECOVER_TABLE = 1088,
     ROLLFORWARD_DATABASE = 1089,
     DROP_TRIGGER = 1105,
     DROP_AUDIT_FOR = 1106,
     CREATE_AUDIT_FOR = 1107,
     EXECUTE_PROCEDURE = 1111,
     ALTER_TABLE = 1118,
     ALTER_INDEX = 1119,
     NEXT_SIZE = 1120,
     XSET_MULTIPLY_EQUAL_OPEN_BRACKET = 1157,
     XSET_ident_DOT_MULTIPLY_EQUAL_OPEN_BRACKET = 1158,
     XSET_ident_DOT_MULTIPLY_EQUAL = 1159,
     XSET_MULTIPLY_EQUAL = 1160,
     XSET_OPEN_BRACKET = 1161,
     CREATE_DATABASE = 1164,
     DROP_DATABASE = 1165,
     ADD_CONSTRAINT = 1167,
     DROP_CONSTRAINT = 1168,
     DROP_SYNONYM = 1169,
     CONSTRAINT = 1170,
     NOT_FIELD_TOUCHED_CURRENT = 1173,
     FIELD_TOUCHED_CURRENT = 1174,
     DOUBLE_PRECISION = 1181,
     COUNT_MULTIPLY = 1182,
     MODIFY_NEXT_SIZE = 1202,
     LOCK_MODE_PAGE = 1203,
     LOCK_MODE_ROW = 1204,
     UNITS_YEAR = 1211,
     UNITS_MONTH = 1212,
     UNITS_DAY = 1213,
     UNITS_HOUR = 1214,
     UNITS_MINUTE = 1215,
     UNITS_SECOND = 1216,
     TO_CLUSTER = 1221,
     TO_NOT_CLUSTER = 1222,
     CREATE_UC_IDX = 1224,
     CREATE_U_IDX = 1225,
     CREATE_C_IDX = 1226,
     CREATE_IDX = 1227,
     DOUBLE_COLON = 1237,
     SQLSICS = 1243,
     CREATE_SCHEMA = 1244,
     SQLSIRR = 1245,
     UPDATESTATS_T = 1246,
     SQLSICR = 1247,
     SQLSIDR = 1258,
     CREATE_TEMP_TABLE = 1259,
     WITH_CHECK_OPTION = 1267,
     WITH_GRANT_OPTION = 1268,
     SQLSLMNW = 1269,
     WHERE_CURRENT_OF = 1275,
     NOT_NULL_UNIQUE = 1283,
     SQLSLMW = 1290,
     ALL_PRIVILEGES = 1292,
     CREATE_SYNONYM = 1296,
     DROP_TABLE = 1297,
     INEXCLUSIVE = 1299,
     UPDATESTATS = 1304,
     CREATE_TABLE = 1330,
     DEFAULT_NULL = 1331,
     DEFAULT_TODAY = 1332,
     DEFAULT_USER = 1333,
     UNLOCK_TABLE = 1346,
     ROLLBACK_W = 1354,
     SQLSEON = 1356,
     SQLSEOFF = 1357,
     CREATE_VIEW = 1361,
     DELETE_FROM = 1362,
     EXTENT_SIZE = 1369,
     FOREIGN_KEY = 1370,
     INSERT_INTO = 1373,
     IS_NOT_NULL = 1375,
     NOT_MATCHES = 1378,
     PRIMARY_KEY = 1384,
     USE_SESSION = 1391,
     WITH_NO_LOG = 1392,
     INSHARE = 1395,
     BEGIN_WORK = 1401,
     DROP_INDEX = 1406,
     FOR_UPDATE_OF = 1412,
     FOR_UPDATE = 1413,
     LOCK_TABLE = 1418,
     NOT_EXISTS = 1420,
     REFERENCES = 1422,
     RENCOL = 1423,
     SMALLFLOAT = 1425,
     COMMIT_W = 1436,
     RENTAB = 1443,
     KW_CHAR = 1446,
     NCHAR = 1447,
     NVARCHAR = 1448,
     DELIMITER = 1450,
     DROP_VIEW = 1452,
     EXCLUSIVE = 1455,
     GREATER_THAN_EQ = 1459,
     INTO_TEMP = 1461,
     DATABASE = 1485,
     DATETIME = 1486,
     DISTINCT = 1488,
     FRACTION = 1495,
     GROUP_BY = 1497,
     INTERVAL = 1498,
     NOT_LIKE = 1500,
     NOT_ILIKE = 1501,
     NOT_NULL = 1502,
     RESOURCE = 1508,
     SMALLINT = 1509,
     IS_NULL = 1515,
     LESS_THAN_EQ = 1516,
     BETWEEN = 1518,
     CLOSE_BRACKET = 1521,
     CONNECT = 1524,
     KW_CURRENT = 1525,
     KW_DECIMAL = 1527,
     DEFAULT = 1529,
     INTEGER = 1537,
     SERIAL8 = 1539,
     MATCHES = 1542,
     VARCHAR = 1555,
     CLOSE_SQUARE = 1558,
     GREATER_THAN = 1559,
     KW_FALSE = 1560,
     NOT_IN = 1561,
     OPEN_BRACKET = 1563,
     KW_DELETE = 1571,
     KW_ESCAPE = 1574,
     EXISTS = 1575,
     EXTEND = 1576,
     HAVING = 1580,
     KW_INSERT = 1582,
     MINUTE = 1586,
     MODIFY = 1587,
     EQUAL = 1589,
     NOT_EQUAL = 1590,
     OPEN_SQUARE = 1592,
     PUBLIC = 1596,
     REVOKE = 1600,
     SECOND = 1604,
     KW_SELECT = 1608,
     SERIAL = 1609,
     UNIQUE = 1612,
     KW_UPDATE = 1614,
     VALUES = 1615,
     KW_NULL = 1618,
     KW_TRUE = 1619,
     ALTER = 1621,
     CHECK = 1627,
     COUNT = 1631,
     KW_FIRST = 1636,
     KW_FLOAT = 1637,
     GRANT = 1640,
     INDEX = 1643,
     LESS_THAN = 1646,
     MONEY = 1648,
     MONTH = 1649,
     KW_MULTIPLY = 1651,
     ORDER = 1652,
     OUTER = 1653,
     UNION = 1662,
     WHERE = 1665,
     KW_BYTE = 1672,
     CASE = 1674,
     KW_DATE = 1676,
     DESC = 1677,
     KW_DIVIDE = 1678,
     DROP = 1681,
     ELSE = 1682,
     FROM = 1686,
     HOUR = 1692,
     INTO = 1693,
     LIKE = 1696,
     REAL = 1705,
     SOME = 1710,
     KW_TEXT = 1714,
     KW_THEN = 1715,
     USER = 1716,
     WHEN = 1718,
     YEAR = 1721,
     KW_DOW = 1722,
     XSET = 1724,
     ADD = 1725,
     ALL = 1726,
     KW_AND = 1727,
     ANY = 1728,
     ASC = 1729,
     AVG = 1730,
     COLON = 1731,
     KW_COMMA = 1732,
     DAY = 1733,
     DBA = 1734,
     KW_FOR = 1738,
     XMAX = 1743,
     XMIN = 1744,
     KW_MINUS = 1745,
     KW_MOD = 1746,
     KW_NOT = 1747,
     KW_SUM = 1754,
     ATSIGN = 1757,
     KW_PLUS = 1758,
     KW_AS = 1764,
     KW_BY = 1766,
     KW_DOT = 1767,
     KW_IN = 1770,
     KW_ON = 1772,
     KW_OR = 1773,
     KW_TO = 1774,
     BEFORE = 1812,
     END = 1816,
     TILDE = 1823,
     ILIKE = 1824,
     FILLFACTOR = 1827,
     TIME = 1832,
     KW_TODAY = 1839,
     KW_ROWID = 1840,
     TIMESTAMP = 2188,
     KW_TAG = 2209,
     LINTMODULEISLIBRARY = 2210,
     KW_PUBLIC = 2211,
     KW_PRIVATE = 2212
   };
#endif
/* Tokens.  */
#define INT_VALUE 2214
#define NAMED 2215
#define NAMED_GEN 2216
#define CHAR_VALUE 2217
#define NOT_USED_1 2218
#define NOT_USED_2 2219
#define NOT_USED_3 2220
#define NOT_USED_4 2221
#define NOT_USED_5 2222
#define NOT_USED_6 2223
#define NOT_USED_7 2224
#define NOT_USED_8 2225
#define NUMBER_VALUE 2226
#define SEMICOLON 2227
#define QUESTION_MARK 2228
#define CLINE 2229
#define CH 2230
#define MARK_VAR 2231
#define END_MARK_VAR 2232
#define LEFT_JOIN 1002
#define DISPLAY_NULL_TO 1005
#define UNBUFFERED 1006
#define KW_PICTURE 1007
#define ON_CHANGE 1008
#define INNER_JOIN 1009
#define UI_INTERFACE_DOT_FRONTCALL 1012
#define UICOMBOBOX 1016
#define UIFORM 1019
#define USING_BTREE 1035
#define USING_RTREE 1036
#define SET_BUFFERED_LOG 1061
#define SET_LOG 1064
#define MDY 1066
#define WEEKDAY 1067
#define MODE_ANSI 1070
#define START_DATABASE 1071
#define WITH_LOG_IN 1072
#define SET_CONSTRAINTS_ALL_IMMEDIATE 1073
#define DATETIME_VALUE 1086
#define INTERVAL_VALUE 1087
#define RECOVER_TABLE 1088
#define ROLLFORWARD_DATABASE 1089
#define DROP_TRIGGER 1105
#define DROP_AUDIT_FOR 1106
#define CREATE_AUDIT_FOR 1107
#define EXECUTE_PROCEDURE 1111
#define ALTER_TABLE 1118
#define ALTER_INDEX 1119
#define NEXT_SIZE 1120
#define XSET_MULTIPLY_EQUAL_OPEN_BRACKET 1157
#define XSET_ident_DOT_MULTIPLY_EQUAL_OPEN_BRACKET 1158
#define XSET_ident_DOT_MULTIPLY_EQUAL 1159
#define XSET_MULTIPLY_EQUAL 1160
#define XSET_OPEN_BRACKET 1161
#define CREATE_DATABASE 1164
#define DROP_DATABASE 1165
#define ADD_CONSTRAINT 1167
#define DROP_CONSTRAINT 1168
#define DROP_SYNONYM 1169
#define CONSTRAINT 1170
#define NOT_FIELD_TOUCHED_CURRENT 1173
#define FIELD_TOUCHED_CURRENT 1174
#define DOUBLE_PRECISION 1181
#define COUNT_MULTIPLY 1182
#define MODIFY_NEXT_SIZE 1202
#define LOCK_MODE_PAGE 1203
#define LOCK_MODE_ROW 1204
#define UNITS_YEAR 1211
#define UNITS_MONTH 1212
#define UNITS_DAY 1213
#define UNITS_HOUR 1214
#define UNITS_MINUTE 1215
#define UNITS_SECOND 1216
#define TO_CLUSTER 1221
#define TO_NOT_CLUSTER 1222
#define CREATE_UC_IDX 1224
#define CREATE_U_IDX 1225
#define CREATE_C_IDX 1226
#define CREATE_IDX 1227
#define DOUBLE_COLON 1237
#define SQLSICS 1243
#define CREATE_SCHEMA 1244
#define SQLSIRR 1245
#define UPDATESTATS_T 1246
#define SQLSICR 1247
#define SQLSIDR 1258
#define CREATE_TEMP_TABLE 1259
#define WITH_CHECK_OPTION 1267
#define WITH_GRANT_OPTION 1268
#define SQLSLMNW 1269
#define WHERE_CURRENT_OF 1275
#define NOT_NULL_UNIQUE 1283
#define SQLSLMW 1290
#define ALL_PRIVILEGES 1292
#define CREATE_SYNONYM 1296
#define DROP_TABLE 1297
#define INEXCLUSIVE 1299
#define UPDATESTATS 1304
#define CREATE_TABLE 1330
#define DEFAULT_NULL 1331
#define DEFAULT_TODAY 1332
#define DEFAULT_USER 1333
#define UNLOCK_TABLE 1346
#define ROLLBACK_W 1354
#define SQLSEON 1356
#define SQLSEOFF 1357
#define CREATE_VIEW 1361
#define DELETE_FROM 1362
#define EXTENT_SIZE 1369
#define FOREIGN_KEY 1370
#define INSERT_INTO 1373
#define IS_NOT_NULL 1375
#define NOT_MATCHES 1378
#define PRIMARY_KEY 1384
#define USE_SESSION 1391
#define WITH_NO_LOG 1392
#define INSHARE 1395
#define BEGIN_WORK 1401
#define DROP_INDEX 1406
#define FOR_UPDATE_OF 1412
#define FOR_UPDATE 1413
#define LOCK_TABLE 1418
#define NOT_EXISTS 1420
#define REFERENCES 1422
#define RENCOL 1423
#define SMALLFLOAT 1425
#define COMMIT_W 1436
#define RENTAB 1443
#define KW_CHAR 1446
#define NCHAR 1447
#define NVARCHAR 1448
#define DELIMITER 1450
#define DROP_VIEW 1452
#define EXCLUSIVE 1455
#define GREATER_THAN_EQ 1459
#define INTO_TEMP 1461
#define DATABASE 1485
#define DATETIME 1486
#define DISTINCT 1488
#define FRACTION 1495
#define GROUP_BY 1497
#define INTERVAL 1498
#define NOT_LIKE 1500
#define NOT_ILIKE 1501
#define NOT_NULL 1502
#define RESOURCE 1508
#define SMALLINT 1509
#define IS_NULL 1515
#define LESS_THAN_EQ 1516
#define BETWEEN 1518
#define CLOSE_BRACKET 1521
#define CONNECT 1524
#define KW_CURRENT 1525
#define KW_DECIMAL 1527
#define DEFAULT 1529
#define INTEGER 1537
#define SERIAL8 1539
#define MATCHES 1542
#define VARCHAR 1555
#define CLOSE_SQUARE 1558
#define GREATER_THAN 1559
#define KW_FALSE 1560
#define NOT_IN 1561
#define OPEN_BRACKET 1563
#define KW_DELETE 1571
#define KW_ESCAPE 1574
#define EXISTS 1575
#define EXTEND 1576
#define HAVING 1580
#define KW_INSERT 1582
#define MINUTE 1586
#define MODIFY 1587
#define EQUAL 1589
#define NOT_EQUAL 1590
#define OPEN_SQUARE 1592
#define PUBLIC 1596
#define REVOKE 1600
#define SECOND 1604
#define KW_SELECT 1608
#define SERIAL 1609
#define UNIQUE 1612
#define KW_UPDATE 1614
#define VALUES 1615
#define KW_NULL 1618
#define KW_TRUE 1619
#define ALTER 1621
#define CHECK 1627
#define COUNT 1631
#define KW_FIRST 1636
#define KW_FLOAT 1637
#define GRANT 1640
#define INDEX 1643
#define LESS_THAN 1646
#define MONEY 1648
#define MONTH 1649
#define KW_MULTIPLY 1651
#define ORDER 1652
#define OUTER 1653
#define UNION 1662
#define WHERE 1665
#define KW_BYTE 1672
#define CASE 1674
#define KW_DATE 1676
#define DESC 1677
#define KW_DIVIDE 1678
#define DROP 1681
#define ELSE 1682
#define FROM 1686
#define HOUR 1692
#define INTO 1693
#define LIKE 1696
#define REAL 1705
#define SOME 1710
#define KW_TEXT 1714
#define KW_THEN 1715
#define USER 1716
#define WHEN 1718
#define YEAR 1721
#define KW_DOW 1722
#define XSET 1724
#define ADD 1725
#define ALL 1726
#define KW_AND 1727
#define ANY 1728
#define ASC 1729
#define AVG 1730
#define COLON 1731
#define KW_COMMA 1732
#define DAY 1733
#define DBA 1734
#define KW_FOR 1738
#define XMAX 1743
#define XMIN 1744
#define KW_MINUS 1745
#define KW_MOD 1746
#define KW_NOT 1747
#define KW_SUM 1754
#define ATSIGN 1757
#define KW_PLUS 1758
#define KW_AS 1764
#define KW_BY 1766
#define KW_DOT 1767
#define KW_IN 1770
#define KW_ON 1772
#define KW_OR 1773
#define KW_TO 1774
#define BEFORE 1812
#define END 1816
#define TILDE 1823
#define ILIKE 1824
#define FILLFACTOR 1827
#define TIME 1832
#define KW_TODAY 1839
#define KW_ROWID 1840
#define TIMESTAMP 2188
#define KW_TAG 2209
#define LINTMODULEISLIBRARY 2210
#define KW_PUBLIC 2211
#define KW_PRIVATE 2212




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
#line 782 "y.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 794 "y.tab.c"

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
#define YYLAST   2409

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  262
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  227
/* YYNRULES -- Number of rules.  */
#define YYNRULES  630
/* YYNRULES -- Number of states.  */
#define YYNSTATES  1122

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   2232

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
       2,     2,    22,     2,     2,    23,    24,    25,    26,    27,
       2,     2,    28,     2,     2,     2,    29,     2,     2,    30,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,    31,    32,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    33,     2,     2,    34,     2,    35,    36,     2,     2,
      37,    38,    39,    40,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,    41,    42,    43,    44,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,    45,    46,    47,     2,     2,
       2,    48,     2,     2,     2,     2,     2,     2,    49,    50,
      51,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,    52,    53,    54,
      55,    56,     2,     2,    57,    58,     2,    59,    60,    61,
      62,     2,     2,    63,    64,     2,     2,     2,     2,     2,
       2,    65,    66,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,    67,    68,    69,     2,     2,     2,     2,     2,
       2,    70,    71,    72,    73,    74,    75,     2,     2,     2,
       2,    76,    77,     2,    78,    79,    80,    81,     2,     2,
       2,     2,     2,     2,     2,     2,     2,    82,     2,     2,
       2,     2,     2,    83,    84,    85,    86,    87,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    88,    89,
       2,     2,     2,     2,     2,     2,     2,    90,    91,    92,
       2,     2,     2,     2,     2,    93,     2,     2,     2,     2,
       2,     2,     2,    94,     2,     2,     2,     2,     2,     2,
      95,     2,    96,     2,     2,     2,    97,    98,     2,    99,
       2,     2,     2,     2,   100,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     101,   102,   103,   104,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,   105,     2,     2,     2,
       2,     2,     2,     2,   106,     2,   107,   108,     2,     2,
       2,   109,   110,     2,     2,     2,     2,     2,     2,   111,
     112,     2,     2,   113,     2,   114,     2,     2,   115,     2,
       2,     2,     2,     2,   116,     2,     2,     2,     2,     2,
       2,   117,   118,     2,     2,   119,     2,     2,     2,     2,
       2,   120,     2,     2,     2,     2,   121,     2,     2,     2,
       2,     2,   122,   123,     2,     2,     2,     2,   124,     2,
     125,     2,   126,   127,     2,   128,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,   129,     2,     2,     2,
       2,     2,     2,   130,     2,     2,   131,   132,   133,     2,
     134,     2,   135,     2,     2,   136,     2,     2,     2,   137,
       2,   138,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,   139,   140,     2,   141,     2,
       2,     2,     2,     2,     2,   142,     2,   143,   144,     2,
     145,   146,   147,     2,     2,     2,     2,     2,   148,   149,
       2,     2,     2,     2,     2,   150,   151,     2,   152,     2,
       2,   153,     2,     2,   154,   155,     2,   156,     2,   157,
       2,     2,     2,     2,     2,     2,     2,   158,     2,   159,
       2,     2,   160,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,   161,     2,     2,   162,   163,
     164,   165,     2,   166,     2,     2,     2,     2,     2,     2,
       2,   167,     2,     2,   168,   169,   170,     2,     2,     2,
     171,     2,   172,     2,     2,     2,   173,   174,     2,   175,
     176,     2,   177,     2,     2,     2,   178,     2,     2,     2,
     179,     2,     2,     2,   180,     2,     2,     2,   181,   182,
       2,     2,   183,     2,   184,   185,     2,     2,   186,   187,
       2,   188,     2,     2,     2,     2,     2,   189,     2,     2,
       2,   190,     2,     2,     2,     2,   191,   192,     2,     2,
     193,     2,     2,   194,     2,     2,   195,     2,   196,   197,
       2,   198,   199,   200,     2,     2,     2,     2,     2,     2,
       2,     2,   201,     2,     2,   202,     2,     2,     2,     2,
       2,     2,   203,     2,   204,     2,   205,   206,   207,     2,
       2,   208,   209,     2,     2,     2,   210,     2,     2,     2,
       2,     2,   211,   212,     2,     2,   213,     2,     2,     2,
       2,     2,     2,     2,     2,   214,     2,     2,     2,     2,
     215,     2,     2,     2,   216,   217,   218,     2,   219,     2,
       2,   220,   221,     2,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,     2,     2,     2,   233,     2,
       2,     2,     2,   234,   235,   236,   237,   238,     2,     2,
       2,     2,     2,     2,   239,     2,     2,   240,   241,     2,
       2,     2,     2,     2,   242,     2,   243,   244,     2,     2,
     245,     2,   246,   247,   248,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,   249,     2,     2,     2,   250,     2,     2,     2,
       2,     2,     2,   251,   252,     2,     2,   253,     2,     2,
       2,     2,   254,     2,     2,     2,     2,     2,     2,   255,
     256,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,   257,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,   258,
     259,   260,   261,     2,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21
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
     469,     0,    -1,   184,   460,   266,   264,    -1,    -1,    93,
     464,    -1,   202,   375,    -1,    -1,    93,   464,    -1,   202,
     375,    -1,    56,   271,   153,   175,   166,   272,   153,    -1,
      52,   272,   153,    -1,    53,   272,   153,    -1,   222,   267,
      -1,    55,   272,    -1,    54,   272,    -1,   270,    -1,   267,
     230,   270,    -1,   269,    -1,   240,   269,    -1,   463,   401,
      -1,   463,   244,   463,   401,    -1,   463,   244,   463,   244,
     463,   401,    -1,   463,   244,   198,    -1,   268,   175,   273,
      -1,   268,    -1,   271,   230,   268,    -1,   273,    -1,   272,
     230,   273,    -1,   448,    -1,   186,    -1,   275,    -1,    98,
     460,    -1,   135,   460,    -1,   121,   462,    -1,    45,   463,
      -1,   286,    -1,   277,    -1,   101,   460,   166,   291,   153,
     278,    -1,    89,   460,   166,   291,   153,   287,   278,   287,
      -1,    -1,   279,    -1,   280,    -1,   279,   280,    -1,   245,
     281,    -1,   111,     3,    -1,    51,     3,    -1,    68,    -1,
      69,    -1,     4,    -1,    -1,   283,    -1,   284,    -1,   283,
     284,    -1,   245,   281,    -1,   253,     3,    -1,    31,    -1,
      32,    -1,   460,    -1,    79,   462,   246,   285,   166,   289,
     153,   282,    -1,    78,   462,   246,   285,   166,   289,   153,
     282,    -1,    80,   462,   246,   285,   166,   289,   153,   282,
      -1,    81,   462,   246,   285,   166,   289,   153,   282,    -1,
      57,   473,    -1,    58,   473,    -1,    97,   460,   233,   460,
      -1,    47,   460,   245,     6,    -1,    46,   460,    -1,    61,
     460,    -1,    43,   460,    -1,    44,   463,    -1,    -1,   118,
      -1,    -1,   118,    -1,   290,    -1,   289,   230,   290,    -1,
     463,   227,    -1,   463,   206,    -1,   463,    -1,   292,    -1,
     291,   230,   292,    -1,   355,    -1,   353,    -1,    49,   463,
     294,    -1,    50,   462,    76,    -1,    50,   462,    77,    -1,
     295,    -1,   294,   230,   295,    -1,   296,    -1,   299,    -1,
     302,    -1,   307,    -1,   310,    -1,   306,    -1,   305,    -1,
     223,   297,    -1,   223,   166,   298,   153,    -1,   292,    -1,
     292,   249,   463,    -1,   297,    -1,   298,   230,   297,    -1,
     208,   301,    -1,   208,   166,   300,   153,    -1,   301,    -1,
     300,   230,   301,    -1,   463,    -1,   174,   304,    -1,   174,
     166,   303,   153,    -1,   304,    -1,   303,   230,   304,    -1,
     292,    -1,    68,    -1,    69,    -1,    67,     3,    -1,    59,
     353,   309,    -1,    59,   166,   308,   153,    -1,   353,   309,
      -1,   308,   230,   353,   309,    -1,    -1,    62,   463,    -1,
      60,   311,    -1,    60,   166,   311,   153,    -1,   312,    -1,
     311,   230,   312,    -1,   463,    -1,   106,    -1,    -1,   113,
     315,   460,   318,   316,    -1,    -1,   185,   317,   166,   321,
     153,    -1,   442,    -1,    -1,   166,   319,   153,    -1,   320,
      -1,   319,   230,   320,    -1,   463,    -1,   463,   244,   463,
      -1,   322,    -1,   321,   230,   322,    -1,   448,    -1,   186,
      -1,   110,   460,   265,    -1,   120,    -1,   129,    -1,    -1,
     136,    -1,   328,    -1,    38,   463,    39,     6,    37,    -1,
      38,   463,    39,     6,    -1,    40,    -1,    33,    -1,    34,
      -1,    86,   463,    -1,   100,    -1,   325,    -1,   324,    -1,
     313,    -1,   327,    -1,   361,    -1,   365,    -1,   412,    -1,
     274,    -1,   276,    -1,   293,    -1,   193,   334,   246,   460,
     248,   339,   333,    -1,   179,   334,   246,   460,   210,   339,
      -1,   193,   332,   248,   339,    -1,   179,   332,   210,   339,
      -1,   154,    -1,   148,    -1,   232,    -1,    -1,    91,    -1,
     242,   400,    -1,    96,    -1,   224,    -1,   335,    -1,   336,
      -1,   335,   230,   336,    -1,   181,   337,    -1,   172,    -1,
     167,    -1,   184,   337,    -1,   188,    -1,   194,    -1,    -1,
     166,   338,   153,    -1,   402,    -1,   338,   230,   402,    -1,
     340,    -1,   339,   230,   340,    -1,   178,    -1,   400,    -1,
     109,   460,   342,   242,   433,   344,    -1,    -1,   166,   343,
     153,    -1,   402,    -1,   343,   230,   402,    -1,    -1,    90,
      -1,   189,   166,   432,   153,    -1,   112,   166,   348,   153,
     347,    -1,   126,   349,    -1,   350,    -1,   460,    -1,   460,
     166,   350,   153,    -1,   402,    -1,   350,   230,   402,    -1,
     183,   166,   352,   153,    -1,   141,   166,   352,   153,    -1,
     116,   166,   352,   153,    -1,   402,    -1,   352,   230,   402,
      -1,   351,    -1,   346,    -1,   345,    -1,   157,   407,    -1,
     104,    -1,   103,    -1,   102,    -1,   463,   391,   356,   357,
      -1,    -1,   354,    -1,    -1,   358,    -1,   359,    -1,   358,
     359,    -1,   360,   309,    -1,   147,    -1,    94,    -1,   183,
      -1,   141,    -1,   347,    -1,   189,   166,   432,   153,    -1,
     116,    -1,    84,   362,   364,    -1,   363,    -1,   400,    -1,
     365,    -1,   364,   365,    -1,   341,    -1,   331,    -1,   171,
     375,    -1,   202,   375,    -1,   210,   369,    -1,   371,    -1,
     369,   230,   371,    -1,   369,   230,   200,   371,    -1,   369,
     230,   200,   166,   369,   153,    -1,   369,    22,   370,   246,
     375,    -1,   369,    27,   370,   246,   375,    -1,   369,    -1,
     166,   369,   153,    -1,   460,    -1,   460,   406,    -1,   460,
     242,   406,    -1,    -1,   368,   373,    -1,   374,    -1,   367,
     374,    -1,    -1,   429,    -1,   429,   366,    -1,   366,    -1,
     376,    -1,   375,   247,   376,    -1,   377,    -1,   376,   225,
     377,    -1,   378,    -1,   238,   378,    -1,   388,    -1,   166,
     375,   153,    -1,   169,   443,    -1,   125,   443,    -1,    -1,
     168,   384,    -1,    -1,   168,   384,    -1,    -1,   168,   384,
      -1,   486,    -1,   407,    -1,    -1,   238,    -1,   448,   385,
     150,    -1,   448,   385,   114,    -1,   448,   387,   448,    -1,
     448,   175,   448,    -1,   448,   175,   186,    -1,   448,   385,
     152,   448,   225,   448,    -1,   448,   213,   383,   382,    -1,
     448,   145,   383,   382,    -1,   448,   252,   383,   381,    -1,
     448,   146,   383,   381,    -1,   448,   160,   383,   380,    -1,
     448,   115,   383,   380,    -1,   176,    -1,   195,    -1,   163,
      -1,   251,    -1,   151,    -1,   137,    -1,   386,    -1,   455,
      -1,   379,    -1,   448,    -1,    -1,   224,    -1,   141,    -1,
     183,    -1,    -1,   224,    -1,   141,    -1,   183,    -1,   392,
      -1,   393,    -1,   394,    -1,   396,    -1,   131,    -1,   131,
     166,   397,   153,    -1,   182,    -1,   182,   166,     3,   153,
      -1,   159,    -1,   159,   166,     3,   153,    -1,   156,    -1,
     156,   166,   398,   395,   153,    -1,   196,   166,   398,   395,
     153,    -1,   196,    -1,   205,    -1,   158,    -1,   149,    -1,
     132,    -1,   132,   166,   397,   153,    -1,   133,    -1,   133,
     166,     3,   153,    -1,   133,   166,     3,   230,     3,   153,
      -1,   140,   409,   248,   410,    -1,   140,    -1,   144,   409,
     248,   410,    -1,   434,    -1,   144,    -1,   144,   409,   166,
       3,   153,   248,   410,    -1,   216,    -1,   203,    -1,   161,
      -1,   161,   166,     3,   153,    -1,   161,   166,     3,   230,
       3,   153,    -1,    -1,   230,   399,    -1,   192,   166,   398,
     153,    -1,   214,    -1,   128,    -1,   192,    -1,    65,    -1,
       3,    -1,     3,    -1,     3,    -1,   463,    -1,     6,    -1,
      -1,   177,     3,   162,    -1,   177,     3,   230,     3,   162,
      -1,   405,    -1,   240,   405,    -1,   404,    -1,   240,   404,
      -1,   463,   401,    -1,   458,   244,   463,   401,    -1,   458,
     244,   198,    -1,   256,    -1,   463,   401,    -1,   458,   244,
     463,   401,    -1,   463,   244,   463,   244,   463,   401,    -1,
     458,   244,   198,    -1,   463,    -1,     6,    -1,   465,    -1,
       3,    -1,   423,    -1,    -1,   409,   248,   410,    -1,   220,
      -1,   197,    -1,   231,    -1,   211,    -1,   173,    -1,   180,
      -1,   142,    -1,   220,    -1,   197,    -1,   231,    -1,   211,
      -1,   173,    -1,   180,    -1,   142,    -1,   142,   166,     3,
     153,    -1,    48,   463,   166,   153,    -1,    48,   463,   166,
     452,   153,    -1,   417,    -1,   416,    -1,   413,    -1,   411,
      -1,   130,   414,   248,   414,    -1,   127,   458,   244,   415,
     248,   415,    -1,   463,    -1,   463,    -1,   105,   460,    -1,
     124,   460,   418,    -1,   119,    -1,    99,    -1,   420,    -1,
     420,   409,   248,   410,    -1,    41,    -1,   422,    -1,   422,
     409,   166,     3,   153,   248,   410,    -1,   422,   409,   248,
     410,    -1,    42,    -1,   155,   408,    -1,   199,   243,   425,
      -1,   426,    -1,   425,   230,   426,    -1,   427,   428,    -1,
       3,    -1,   403,    -1,    -1,   227,    -1,   206,    -1,   143,
     430,    -1,   431,    -1,   430,   230,   431,    -1,   403,    -1,
       3,    -1,   375,    -1,   442,    -1,   254,    -1,   254,   166,
       3,   153,    -1,   257,    -1,   257,   166,     3,   153,    -1,
      -1,    -1,   181,   444,   445,   436,   446,   437,   467,   372,
     439,   440,    -1,   181,   444,   445,   446,   372,   439,    -1,
      -1,   201,   390,   438,    -1,    -1,   424,    -1,   424,   138,
     441,   288,    -1,   138,   441,   288,    -1,   463,    -1,   181,
     444,   445,   446,   372,    -1,   166,   181,   444,   445,   446,
     372,   153,    -1,    -1,   191,     3,    -1,    -1,   224,    -1,
     141,    -1,   183,    -1,   447,    -1,   446,   230,   447,    -1,
     448,    -1,   448,   463,    -1,   448,   242,   463,    -1,   486,
      -1,   236,   486,    -1,   241,   486,    -1,   486,   207,   448,
      -1,   486,   454,    -1,   486,   198,   448,    -1,   486,   241,
     448,    -1,   486,   236,   448,    -1,   407,    -1,   187,    -1,
     164,    -1,   218,    -1,   255,    -1,   256,    -1,   254,    -1,
     198,    -1,    66,    -1,   228,   166,   389,   448,   153,    -1,
     234,   166,   389,   448,   153,    -1,   235,   166,   389,   448,
     153,    -1,   239,   166,   389,   448,   153,    -1,   190,   166,
     389,   448,   153,    -1,     4,   166,   153,    -1,     4,   166,
     452,   153,    -1,   220,   166,   452,   153,    -1,   197,   166,
     452,   153,    -1,   231,   166,   452,   153,    -1,    35,   166,
     452,   153,    -1,    36,   166,   452,   153,    -1,   221,   166,
     452,   153,    -1,   205,   166,   452,   153,    -1,   166,   448,
     153,    -1,   170,   166,   453,   153,    -1,   419,    -1,   421,
      -1,   204,   450,   250,    -1,   451,    -1,   450,   451,    -1,
     219,   375,   217,   448,    -1,   209,   448,    -1,   448,    -1,
     452,   230,   448,    -1,   155,   230,   409,   248,   410,    -1,
     479,   230,   409,   248,   410,    -1,   155,   409,   248,   410,
      -1,   448,   230,   409,   248,   410,    -1,    70,    -1,    71,
      -1,    72,    -1,    73,    -1,    74,    -1,    75,    -1,   448,
     245,   166,   456,   153,    -1,   448,   245,   443,    -1,   448,
     165,   166,   456,   153,    -1,   448,   165,   443,    -1,   457,
      -1,   456,   230,   457,    -1,   479,    -1,   407,    -1,   236,
       3,    -1,   236,   465,    -1,   459,    -1,     6,    -1,     6,
     244,   463,    -1,   463,    -1,   463,   229,   463,    -1,   463,
     229,     6,   244,   463,    -1,   463,   240,   463,    -1,   463,
     240,   463,   229,   463,    -1,   463,   240,   463,   229,     6,
     244,   463,    -1,   461,    -1,     6,   244,   463,    -1,   463,
     244,   463,    -1,     6,    -1,   463,    -1,   463,   229,   463,
      -1,   463,   229,     6,   244,   463,    -1,   463,   240,   463,
      -1,   463,   240,   463,   229,   463,    -1,   463,   240,   463,
     229,     6,   244,   463,    -1,     6,   244,   463,    -1,     6,
      -1,   463,    -1,   463,   229,   463,    -1,   463,   229,     6,
     244,   463,    -1,   463,   240,   463,    -1,   463,   240,   463,
     229,   463,    -1,   463,   240,   463,   229,     6,   244,   463,
      -1,     4,    -1,     4,    -1,    15,    -1,   244,     3,    -1,
       4,    -1,     6,    -1,    -1,   463,    -1,   471,    -1,   469,
      16,   471,    -1,   314,    -1,   263,    -1,   323,    -1,    -1,
     480,    -1,   330,    -1,   472,    -1,   478,    -1,   470,    -1,
     329,    -1,     1,    -1,   474,   475,    -1,   468,    -1,   435,
      -1,    -1,   123,    -1,   122,   476,    -1,   477,    -1,   476,
     230,   477,    -1,   463,    -1,   463,   244,   463,    -1,     6,
     244,   463,   244,   463,    -1,   108,    -1,   107,    -1,    95,
     488,    -1,    92,    -1,    88,    -1,    85,    -1,    83,    -1,
      87,    -1,   485,    -1,    17,    -1,   481,    -1,   139,   466,
     326,    -1,    20,     6,    21,    -1,   166,   482,   153,    -1,
     482,   483,   482,    -1,     3,    -1,   484,     3,    -1,   241,
      -1,   236,    -1,   198,    -1,   207,    -1,   237,    -1,   241,
      -1,   236,    -1,   463,    -1,   463,   244,   198,    -1,   463,
     244,   256,    -1,   463,   244,   463,    -1,   463,   244,   463,
     244,   463,    -1,     6,   244,   463,   244,   463,    -1,   463,
     177,   482,   162,    -1,   463,   244,   463,   177,   482,   162,
      -1,   463,   244,   463,   244,   463,   177,   482,   162,    -1,
       6,   244,   463,   244,   463,   177,   482,   162,    -1,   463,
     177,   482,   230,   482,   162,    -1,   463,   244,   463,   177,
     482,   230,   482,   162,    -1,   463,   244,   463,   244,   463,
     177,   482,   230,   482,   162,    -1,     6,   244,   463,   244,
     463,   177,   482,   230,   482,   162,    -1,   487,    -1,   487,
      82,   391,    -1,   449,    -1,   479,    -1,   443,    -1,   224,
     443,    -1,   226,   443,    -1,   215,   443,    -1,    -1,     3,
      -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   411,   411,   437,   440,   457,   462,   465,   482,   488,
     497,   506,   515,   522,   537,   592,   599,   610,   613,   618,
     625,   642,   659,   680,   689,   692,   700,   703,   711,   712,
     719,   722,   730,   733,   737,   743,   744,   748,   758,   772,
     773,   777,   778,   783,   791,   799,   807,   815,   825,   827,
     827,   830,   831,   835,   842,   849,   856,   865,   869,   876,
     888,   899,   905,   909,   913,   918,   922,   925,   929,   932,
     939,   940,   950,   951,   955,   956,   960,   969,   978,   985,
     988,   994,   997,  1008,  1012,  1017,  1024,  1027,  1036,  1039,
    1043,  1047,  1051,  1055,  1059,  1067,  1071,  1079,  1082,  1089,
    1092,  1099,  1102,  1109,  1110,  1115,  1119,  1122,  1128,  1131,
    1137,  1144,  1145,  1149,  1157,  1161,  1168,  1170,  1175,  1176,
    1180,  1182,  1188,  1189,  1192,  1203,  1209,  1209,  1218,  1218,
    1227,  1252,  1255,  1263,  1266,  1273,  1276,  1284,  1285,  1291,
    1292,  1300,  1318,  1322,  1327,  1328,  1338,  1347,  1351,  1355,
    1360,  1364,  1368,  1371,  1378,  1379,  1380,  1384,  1385,  1386,
    1387,  1388,  1389,  1390,  1398,  1399,  1400,  1401,  1406,  1407,
    1408,  1411,  1412,  1413,  1417,  1418,  1419,  1423,  1424,  1428,
    1435,  1436,  1437,  1444,  1445,  1448,  1449,  1454,  1455,  1460,
    1461,  1466,  1467,  1472,  1479,  1480,  1485,  1486,  1490,  1491,
    1498,  1506,  1513,  1520,  1524,  1525,  1530,  1531,  1537,  1541,
    1546,  1553,  1554,  1560,  1563,  1566,  1573,  1574,  1575,  1576,
    1582,  1603,  1604,  1607,  1609,  1616,  1619,  1625,  1633,  1638,
    1644,  1649,  1655,  1658,  1663,  1671,  1680,  1685,  1689,  1690,
    1696,  1699,  1710,  1719,  1726,  1732,  1733,  1736,  1741,  1752,
    1756,  1763,  1764,  1768,  1772,  1776,  1783,  1788,  1796,  1799,
    1805,  1808,  1813,  1818,  1831,  1834,  1840,  1843,  1849,  1852,
    1858,  1861,  1868,  1872,  1883,  1883,  1884,  1884,  1885,  1885,
    1888,  1893,  1898,  1899,  1904,  1913,  1921,  1924,  1927,  1931,
    1938,  1941,  1945,  1948,  1951,  1954,  1960,  1967,  1970,  1973,
    1976,  1977,  1982,  1985,  1988,  1991,  1998,  1999,  2000,  2004,
    2011,  2012,  2013,  2017,  2031,  2038,  2039,  2040,  2044,  2045,
    2050,  2051,  2060,  2062,  2071,  2074,  2082,  2092,  2100,  2102,
    2103,  2104,  2105,  2106,  2107,  2108,  2116,  2117,  2118,  2119,
    2120,  2121,  2122,  2123,  2124,  2125,  2126,  2136,  2137,  2143,
    2145,  2146,  2147,  2148,  2152,  2156,  2160,  2167,  2168,  2173,
    2174,  2178,  2186,  2189,  2196,  2199,  2209,  2212,  2215,  2218,
    2225,  2232,  2240,  2249,  2256,  2260,  2261,  2262,  2263,  2268,
    2270,  2279,  2279,  2279,  2279,  2279,  2279,  2279,  2280,  2280,
    2280,  2280,  2280,  2280,  2280,  2280,  2295,  2303,  2315,  2316,
    2317,  2318,  2323,  2324,  2327,  2328,  2332,  2339,  2350,  2351,
    2364,  2365,  2369,  2373,  2374,  2377,  2383,  2387,  2410,  2420,
    2423,  2429,  2438,  2442,  2449,  2450,  2452,  2457,  2463,  2466,
    2472,  2473,  2480,  2493,  2503,  2510,  2527,  2534,  2559,  2561,
    2559,  2583,  2627,  2628,  2642,  2645,  2652,  2662,  2674,  2680,
    2693,  2708,  2710,  2716,  2717,  2718,  2719,  2729,  2732,  2738,
    2741,  2746,  2755,  2758,  2762,  2769,  2772,  2775,  2778,  2781,
    2784,  2785,  2786,  2787,  2788,  2789,  2790,  2791,  2792,  2794,
    2798,  2802,  2806,  2810,  2814,  2818,  2822,  2825,  2828,  2831,
    2834,  2837,  2840,  2843,  2846,  2850,  2854,  2858,  2866,  2869,
    2878,  2884,  2891,  2894,  2922,  2925,  2928,  2931,  2937,  2938,
    2939,  2940,  2941,  2942,  2947,  2951,  2955,  2959,  2966,  2969,
    2974,  2975,  2976,  2978,  2984,  2994,  2998,  3002,  3006,  3010,
    3014,  3018,  3022,  3030,  3040,  3045,  3049,  3053,  3057,  3061,
    3066,  3070,  3074,  3082,  3085,  3090,  3091,  3092,  3097,  3098,
    3099,  3107,  3110,  3115,  3116,  3120,  3121,  3126,  3150,  3167,
    3168,  3172,  3179,  3185,  3195,  3197,  3200,  3201,  3202,  3203,
    3205,  3208,  3212,  3217,  3221,  3227,  3228,  3231,  3236,  3237,
    3240,  3241,  3242,  3252,  3253,  3254,  3255,  3256,  3257,  3258,
    3259,  3263,  3269,  3271,  3290,  3298,  3305,  3306,  3307,  3308,
    3313,  3314,  3315,  3316,  3317,  3322,  3323,  3339,  3340,  3341,
    3342,  3343,  3344,  3345,  3346,  3347,  3348,  3350,  3351,  3352,
    3353,  3358,  3361,  3370,  3371,  3372,  3373,  3374,  3375,  3379,
    3380
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
  "LEFT_JOIN", "DISPLAY_NULL_TO", "UNBUFFERED", "KW_PICTURE", "ON_CHANGE",
  "INNER_JOIN", "UI_INTERFACE_DOT_FRONTCALL", "UICOMBOBOX", "UIFORM",
  "USING_BTREE", "USING_RTREE", "SET_BUFFERED_LOG", "SET_LOG", "MDY",
  "WEEKDAY", "MODE_ANSI", "START_DATABASE", "WITH_LOG_IN",
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
  "LINTMODULEISLIBRARY", "KW_PUBLIC", "KW_PRIVATE", "$accept",
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
       0,   256,  2213,  2214,  2215,  2216,  2217,  2218,  2219,  2220,
    2221,  2222,  2223,  2224,  2225,  2226,  2227,  2228,  2229,  2230,
    2231,  2232,  1002,  1005,  1006,  1007,  1008,  1009,  1012,  1016,
    1019,  1035,  1036,  1061,  1064,  1066,  1067,  1070,  1071,  1072,
    1073,  1086,  1087,  1088,  1089,  1105,  1106,  1107,  1111,  1118,
    1119,  1120,  1157,  1158,  1159,  1160,  1161,  1164,  1165,  1167,
    1168,  1169,  1170,  1173,  1174,  1181,  1182,  1202,  1203,  1204,
    1211,  1212,  1213,  1214,  1215,  1216,  1221,  1222,  1224,  1225,
    1226,  1227,  1237,  1243,  1244,  1245,  1246,  1247,  1258,  1259,
    1267,  1268,  1269,  1275,  1283,  1290,  1292,  1296,  1297,  1299,
    1304,  1330,  1331,  1332,  1333,  1346,  1354,  1356,  1357,  1361,
    1362,  1369,  1370,  1373,  1375,  1378,  1384,  1391,  1392,  1395,
    1401,  1406,  1412,  1413,  1418,  1420,  1422,  1423,  1425,  1436,
    1443,  1446,  1447,  1448,  1450,  1452,  1455,  1459,  1461,  1485,
    1486,  1488,  1495,  1497,  1498,  1500,  1501,  1502,  1508,  1509,
    1515,  1516,  1518,  1521,  1524,  1525,  1527,  1529,  1537,  1539,
    1542,  1555,  1558,  1559,  1560,  1561,  1563,  1571,  1574,  1575,
    1576,  1580,  1582,  1586,  1587,  1589,  1590,  1592,  1596,  1600,
    1604,  1608,  1609,  1612,  1614,  1615,  1618,  1619,  1621,  1627,
    1631,  1636,  1637,  1640,  1643,  1646,  1648,  1649,  1651,  1652,
    1653,  1662,  1665,  1672,  1674,  1676,  1677,  1678,  1681,  1682,
    1686,  1692,  1693,  1696,  1705,  1710,  1714,  1715,  1716,  1718,
    1721,  1722,  1724,  1725,  1726,  1727,  1728,  1729,  1730,  1731,
    1732,  1733,  1734,  1738,  1743,  1744,  1745,  1746,  1747,  1754,
    1757,  1758,  1764,  1766,  1767,  1770,  1772,  1773,  1774,  1812,
    1816,  1823,  1824,  1827,  1832,  1839,  1840,  2188,  2209,  2210,
    2211,  2212
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint16 yyr1[] =
{
       0,   262,   263,   264,   264,   264,   265,   265,   265,   266,
     266,   266,   266,   266,   266,   267,   267,   268,   268,   269,
     269,   269,   269,   270,   271,   271,   272,   272,   273,   273,
     274,   275,   275,   275,   275,   276,   276,   277,   277,   278,
     278,   279,   279,   280,   280,   280,   280,   280,   281,   282,
     282,   283,   283,   284,   284,   284,   284,   285,   286,   286,
     286,   286,   286,   286,   286,   286,   286,   286,   286,   286,
     287,   287,   288,   288,   289,   289,   290,   290,   290,   291,
     291,   292,   292,   293,   293,   293,   294,   294,   295,   295,
     295,   295,   295,   295,   295,   296,   296,   297,   297,   298,
     298,   299,   299,   300,   300,   301,   302,   302,   303,   303,
     304,   305,   305,   306,   307,   307,   308,   308,   309,   309,
     310,   310,   311,   311,   312,   313,   315,   314,   317,   316,
     316,   318,   318,   319,   319,   320,   320,   321,   321,   322,
     322,   323,   324,   325,   326,   326,   327,   328,   328,   328,
     328,   328,   328,   328,   329,   329,   329,   330,   330,   330,
     330,   330,   330,   330,   331,   331,   331,   331,   332,   332,
     332,   333,   333,   333,   334,   334,   334,   335,   335,   336,
     336,   336,   336,   336,   336,   337,   337,   338,   338,   339,
     339,   340,   340,   341,   342,   342,   343,   343,   344,   344,
     345,   346,   347,   348,   349,   349,   350,   350,   351,   351,
     351,   352,   352,   353,   353,   353,   354,   354,   354,   354,
     355,   356,   356,   357,   357,   358,   358,   359,   360,   360,
     360,   360,   360,   360,   360,   361,   362,   363,   364,   364,
     365,   365,   366,   367,   368,   369,   369,   369,   369,   369,
     369,   370,   370,   371,   371,   371,   372,   372,   373,   373,
     374,   374,   374,   374,   375,   375,   376,   376,   377,   377,
     378,   378,   379,   379,   380,   380,   381,   381,   382,   382,
     383,   384,   385,   385,   386,   386,   386,   386,   386,   386,
     386,   386,   386,   386,   386,   386,   387,   387,   387,   387,
     387,   387,   388,   388,   388,   388,   389,   389,   389,   389,
     390,   390,   390,   390,   391,   392,   392,   392,   393,   393,
     394,   394,   394,   394,   394,   394,   394,   394,   394,   394,
     394,   394,   394,   394,   394,   394,   394,   394,   394,   394,
     394,   394,   394,   394,   394,   394,   394,   395,   395,   396,
     396,   396,   396,   396,   397,   398,   399,   400,   400,   401,
     401,   401,   402,   402,   403,   403,   404,   404,   404,   404,
     405,   405,   405,   405,   406,   407,   407,   407,   407,   408,
     408,   409,   409,   409,   409,   409,   409,   409,   410,   410,
     410,   410,   410,   410,   410,   410,   411,   411,   412,   412,
     412,   412,   413,   413,   414,   415,   416,   417,   418,   418,
     419,   419,   420,   421,   421,   421,   422,   423,   424,   425,
     425,   426,   427,   427,   428,   428,   428,   429,   430,   430,
     431,   431,   432,   433,   434,   434,   434,   434,   436,   437,
     435,   438,   439,   439,   440,   440,   440,   440,   441,   442,
     443,   444,   444,   445,   445,   445,   445,   446,   446,   447,
     447,   447,   448,   448,   448,   449,   449,   449,   449,   449,
     449,   449,   449,   449,   449,   449,   449,   449,   449,   449,
     449,   449,   449,   449,   449,   449,   449,   449,   449,   449,
     449,   449,   449,   449,   449,   449,   449,   449,   450,   450,
     451,   451,   452,   452,   453,   453,   453,   453,   454,   454,
     454,   454,   454,   454,   455,   455,   455,   455,   456,   456,
     457,   457,   457,   457,   458,   459,   459,   459,   459,   459,
     459,   459,   459,   460,   461,   461,   461,   461,   461,   461,
     461,   461,   461,   462,   462,   462,   462,   462,   462,   462,
     462,   463,   464,   465,   465,   466,   466,   467,   468,   469,
     469,   470,   470,   470,   471,   471,   471,   471,   471,   471,
     471,   471,   472,   473,   474,   475,   475,   475,   476,   476,
     477,   477,   477,   478,   478,   478,   478,   478,   478,   478,
     478,   479,   479,   479,   480,   481,   482,   482,   482,   482,
     483,   483,   483,   483,   483,   484,   484,   485,   485,   485,
     485,   485,   485,   485,   485,   485,   485,   485,   485,   485,
     485,   486,   486,   487,   487,   487,   487,   487,   487,   488,
     488
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
#define YYPACT_NINF -899
static const yytype_int16 yypact[] =
{
    2216,  -899,  -899,  -899,   109,  -899,   343,   109,   109,   343,
     343,   109,   109,   483,   109,   109,   343,   483,   483,   483,
     483,  -899,   600,  -899,   109,  -899,  -899,   343,  -899,   181,
     343,   343,  -899,   343,   343,  -899,  -899,  -899,   343,   343,
    -899,  -899,   483,   343,   615,  -899,   109,   343,   636,   495,
      52,   343,   495,  -899,  -899,  -899,  -899,  -899,  -899,  -899,
    -899,  -899,  -899,  -899,  -899,  -899,  -899,  -899,  -899,  -899,
    -899,  -899,  -899,  -899,  -899,  -899,  -899,  -899,  -899,   268,
    -899,  -899,  -899,     5,  -899,  -899,  -899,   324,    43,  -899,
    -899,   416,  -899,  -899,  -899,    55,   254,   473,    53,   255,
     108,  -899,  -899,  -899,  -899,  -899,   124,   177,   209,   234,
    -899,    33,  -899,  -899,  -899,  -899,   295,  -899,  -899,   250,
    -899,   336,  -899,   339,   -38,   343,  -899,   379,   264,   308,
    -899,   367,   386,  -899,  -899,  -899,  -899,   433,  -899,  -899,
    -899,  -899,  -899,   406,   406,  -899,  -899,  -899,  -899,   389,
     398,   457,  -899,   661,   168,   218,   426,   438,  -899,  2216,
     665,  -899,  -899,   693,   109,   719,   109,   109,   696,  1115,
     514,    57,   710,  -899,  -899,   434,    81,   452,   484,  -899,
    -899,  -899,  -899,  -899,  -899,  -899,  -899,   109,  -899,  -899,
     767,   109,   343,   343,   343,   343,    33,  -899,   244,   343,
     244,    75,   475,   716,   956,  -899,   560,  -899,  -899,  -899,
     109,   109,   775,   109,   109,  -899,  -899,    75,  -899,  -899,
     104,   343,   736,  -899,  -899,  -899,  -899,  -899,  1252,  1252,
    1252,  1252,    48,    48,     3,   104,   343,  -899,   486,   491,
     517,  -899,   707,  -899,   508,  -899,   527,  -899,  -899,  -899,
     598,   521,  -899,  -899,   770,   632,   638,  -899,  -899,  -899,
    -899,   417,  -899,  1357,   643,  -899,   649,   662,  -899,    15,
     669,   672,  -899,   677,   678,   672,   672,   691,   694,   695,
     708,  1987,   712,  1987,   791,  -899,  -899,  -899,  -899,  -899,
     417,  -899,   417,  -899,  -899,  -899,  -899,     6,   -19,  -899,
    -899,  -899,  -899,   422,   745,   713,   727,   728,   265,   729,
     730,  -899,  -899,  -899,   814,   109,   647,  -899,  -899,  -899,
     244,  -899,  -899,  -899,  -899,   454,   109,  -899,  -899,   244,
     651,  -899,   473,  -899,   657,  -899,   673,   746,  -899,   747,
     748,   757,  -899,    12,  -899,  -899,    21,   615,    66,  -899,
    -899,   663,   505,   750,  -899,  -899,   672,   701,   672,  1009,
     679,   703,  -899,  -899,  -899,  -899,  -899,  1071,  -899,   109,
     261,  -899,   685,  -899,   690,  -899,   709,  -899,   111,  -899,
    -899,   714,  -899,  -899,   731,  -899,  1777,  -899,   116,  -899,
    -899,   128,   720,   720,   109,  -899,  -899,   202,    89,   721,
     768,  -899,   716,   956,  -899,   714,   698,   109,   109,   665,
    -899,   109,   784,  1462,   109,   928,  1777,  1777,  -899,  -899,
    -899,  -899,  -899,  -899,  -899,  -899,   705,    52,   801,  1882,
     189,  1777,  1777,   956,   241,  -899,  1777,   777,  -899,  1777,
    1777,  -899,  -899,   189,  1777,   189,   189,   422,   189,   422,
    -899,   717,   -66,  -899,  1777,    72,    67,  -899,  -899,  -899,
    -899,  -899,  -899,  1777,  1777,  1777,  1777,  -899,   454,    75,
      75,    75,   204,   814,    75,   956,   109,  -899,   215,   109,
     223,  -899,  -899,  -899,   795,   798,   802,   417,   417,  -899,
     804,  -899,   806,   811,   817,   818,   819,  -899,  -899,  -899,
    -899,   820,   821,   549,  -899,  -899,  -899,  -899,  -899,   233,
    -899,  -899,   258,   109,  -899,   109,   797,   109,   109,   109,
     109,   871,   244,   190,  -899,  -899,    75,    79,   987,   109,
    -899,    52,   903,  -899,  -899,   -49,   617,  -899,  -899,   956,
     956,  1987,  -899,  1987,  1987,  -899,  1987,  -899,   828,  1567,
    -899,  -899,  1987,  -899,   829,  -899,  1987,   248,  1777,   290,
    -899,   755,  -899,  -899,  -899,   109,   109,   846,  -899,    75,
     104,   104,   776,  -899,    76,  -899,  1252,  -899,  -899,   825,
      48,    85,  -899,    48,  1252,  -899,   679,   104,   763,  -899,
    -899,  -899,   764,  -899,  -899,   291,   766,  -899,   298,   304,
     558,   168,  -899,   327,   781,   863,   787,  -899,  -899,  -899,
    1777,   306,  -899,   232,  -899,  -899,   309,   318,   321,  1777,
     323,  1777,  1777,  1777,   558,  1015,   558,  -899,  -899,    72,
    -899,  -899,   319,  1016,  -899,  -899,    98,  -899,  -899,  -899,
    -899,  -899,   867,   793,  -899,   351,  -899,   392,  -899,   265,
    -899,   431,   679,   868,  -899,  -899,  -899,  -899,   244,  1022,
    1022,  1024,   780,   -13,  1031,  1032,  1033,  1035,  1031,  1031,
    1036,  1037,  -899,  -899,  -899,   130,  -899,   275,  -899,   109,
    -899,   244,  -899,  -899,   799,  -899,   435,  -899,  -103,   436,
     442,   455,  -899,   190,  -899,  1038,  -899,  -899,  1039,  1042,
    -899,   190,  -899,  -899,  -899,   870,   -53,   808,   168,  -899,
    -899,  -899,   703,  -899,   880,   422,   886,   887,   880,   131,
    -899,  -899,  -899,   886,   131,  -899,   887,  -899,  -899,  1777,
    -899,  -899,   109,   109,   891,  -899,  -899,   815,  -899,  -899,
    -899,   714,  1777,  -899,   109,  -899,  -899,   892,  -899,  -899,
     144,  -899,  -899,    14,   109,   109,  -899,   109,  -899,  -899,
     894,  -899,  -899,  -899,  -899,  -899,  -899,  -899,  1777,   417,
     813,   417,  -899,   417,   909,  -899,  1777,  -899,  -899,  -899,
     910,  -899,   912,   913,   914,  -899,   916,  -899,   337,  -899,
    -899,  -899,    72,  -899,  -899,  -899,    72,  -899,    72,   109,
     944,    75,  -899,    75,  -899,   814,  -899,  -899,  -899,  -899,
     918,   921,   456,   558,  1073,   558,  -899,   847,   925,   458,
     929,   930,   847,   931,   934,  -899,  -899,  -899,  -899,   343,
    -899,  -899,  -899,   922,  -899,  -899,   275,  -899,   814,  -899,
    -899,   109,    91,   109,  -899,  -899,    91,    91,    91,   871,
    -899,  -899,  -899,  -899,  -899,  -899,  -899,  1086,   109,  1777,
     130,  -899,   130,  -899,   130,  -899,  -899,    61,  -899,   463,
    -899,  -899,  -899,   471,  -899,   865,  -899,  -899,  1672,   109,
    -899,   881,  -899,  1252,   109,  -899,  -899,   600,  -899,  -899,
    -899,   915,  1090,   -90,   848,   558,   849,   850,  -899,  -899,
    -899,  -899,  -899,  -899,   851,  -899,   550,   622,   577,   917,
    -899,  -899,  -899,  -899,  -899,  -899,  -899,  1092,  -899,   947,
    -899,  1098,   949,  -899,  -899,  1100,  -899,  -899,   951,  -899,
    -899,  -899,   939,   956,  -899,  -899,  -899,  -899,  -899,  1042,
    1103,  -899,    91,  -899,  -899,  -899,  -899,  -899,  -899,   945,
     870,   -90,  -899,  -899,  -899,  -899,  -899,  -899,  -899,   135,
    -899,  1777,  -899,   479,  -899,  -899,  -899,   343,   400,   908,
     480,   870,  -899,    72,   957,   959,   558,   960,   558,   558,
     558,  -899,  -899,    72,    72,   961,   869,  -899,  -899,  -899,
     962,  -899,    75,   963,  -899,  -899,  -899,  -899,  -899,  -899,
    -899,  -899,  -899,  1672,   154,  -899,    78,    84,   956,   956,
    -899,   -57,  -899,  -899,   952,   253,    41,  -899,  -899,   604,
    -899,  -899,  -899,  -899,  -899,  -899,   610,   674,  -899,   558,
    -899,   485,  -899,  -899,   112,   112,   195,   109,  -899,  -899,
    -899,    54,  -899,  -899,  -899,   897,  -899,   884,   556,   679,
     679,  -899,  -899,  -899,  -899,  -899,   943,   109,   888,   991,
    -899,  -899,    72,  -899,  -899,    72,  -899,  -899,   343,   154,
     890,   893,   198,  -899,  -899,  -899,    84,    93,  -899,    52,
    -899,  1019,  -899,   126,   109,   612,   711,   153,   956,   956,
     343,  -899,  -899,  -899,   870,   168,  -899,  -899,  -899,  -899,
     911,  -899,   132,  1019,  -899,  -899,  -899,   679,   679,   200,
    -899,  1777,   126,  -899,  -899,  -899,  -899,  -899,   -90,  -899,
     908,  -899
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -899,  -899,  -899,  -899,  -899,  -899,  -181,   739,   555,  -899,
    -185,  -373,  -899,  -899,  -899,  -899,   447,  -899,   441,   205,
    -156,  -899,   203,   628,  -899,   299,    44,   313,   312,   958,
    -144,  -899,  -899,   827,  -899,  -272,  -899,  -899,  -899,  -277,
    -899,  -899,  -261,  -899,  -899,  -899,  -899,  -451,  -899,   834,
     683,  -899,  -899,  -899,  -899,  -899,  -899,  -899,   420,  -899,
     160,  -899,  -899,  -899,  -899,  -899,  -899,  -899,  -899,  -899,
    1113,  -899,  1114,  -899,   946,  1023,  -899,  -198,   599,  -899,
    -899,  -899,  -899,  -899,  -899,   370,  -899,  -899,   180,  -899,
    -256,  -139,  -899,  -899,  -899,  -899,  -899,   347,  -899,  -899,
    -899,  -899,  -899,   -39,   174,  -899,  -899,  -898,   158,  -858,
    -820,  -899,   178,  -203,   659,   664,   842,  -899,   487,   476,
     492,   423,  -363,  -899,  -899,  -899,  -899,   444,  -899,   735,
    -899,  -899,  -899,   387,  -899,   559,    26,  -899,    -3,  -370,
    -176,  -862,   179,   878,   191,  -607,  -899,  -242,  -561,  -899,
    -899,  -899,  1004,   667,  -899,  -899,  -899,  -899,  -899,  -899,
    -899,  -899,  -899,  -899,   114,  -899,  -899,  -899,  -899,   162,
     316,  -899,  -899,  -899,  -899,  -899,  -899,   119,  -899,   157,
     872,  -209,  -406,  -565,  -715,   509,  -137,  -899,  -899,   823,
     565,  -899,  -899,  -899,   528,   300,   -27,  -899,    68,  -899,
     741,    -4,   852,   393,  -899,  -899,  -899,  -899,  -899,  1102,
    -899,  1247,  -899,  -899,  -899,   862,  -899,  -405,  -899,  -899,
    -559,  -899,  -899,  -899,  -115,  -899,  -899
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
     452,   395,    86,   893,   344,   203,   344,   511,    86,   481,
     128,    86,   438,   785,   956,   787,   441,   442,   826,  1004,
     788,    86,   197,   975,    89,   628,   252,    94,    95,    86,
      86,   128,    86,    86,   105,    86,  1007,  1040,    86,    86,
     128,   390,   390,   390,   390,   116,   402,    86,   119,   120,
     625,   121,   122,   844,   711,   886,   123,   124,    86,   856,
     110,   127,   868,    86,  1008,   134,    86,   868,    88,   155,
     967,    91,   937,   938,   845,   708,   428,   160,   161,  1098,
      86,   999,   128,   249,   249,    86,   825,   251,   249,    86,
     742,   251,    38,   859,   951,   252,   252,   534,   253,   537,
     252,   254,   253,   814,   535,   254,   239,   342,   455,   453,
     243,   245,   246,   247,   204,   521,   447,   318,   449,   473,
    1087,   325,   328,   325,   523,  1034,  1034,   857,  1073,  1057,
    1035,  1035,   626,   333,   117,   330,   335,   336,    91,    91,
      91,    91,  1109,   206,   325,    91,   325,   352,   539,    86,
     586,    88,    86,   746,    88,   403,   371,   373,   375,   376,
     133,   752,    49,   352,  1091,   647,   114,    91,   651,   525,
     536,  1099,  1034,   315,   432,   456,    52,  1035,   398,   398,
     613,   114,    91,   906,   433,   815,   454,   907,   629,   908,
    1058,   695,   522,   153,   570,   662,   663,   326,    86,   574,
    1099,   522,   918,   953,   920,   953,   887,   953,   696,   697,
     338,   338,   338,   338,   568,   634,   528,   345,   158,   575,
     228,   229,   230,   231,   232,   798,   295,   704,  1068,   295,
     295,   577,   380,   749,   159,   261,   261,   164,   394,   384,
     261,  1093,   604,   644,   295,   612,   526,   187,  1120,   295,
     168,   698,   295,   295,   406,   284,  1106,   295,   630,   224,
    1042,   318,   427,   631,   871,   347,   325,   627,   744,   871,
    1037,   528,   328,   635,  1041,   325,   637,   638,   639,   640,
     607,   188,   189,   581,   977,   855,   939,   190,  1113,   720,
    1042,   569,   799,   352,   940,   725,   576,    86,   191,    88,
     703,   225,   868,  1117,   913,   579,   305,   648,   576,  1114,
     306,   770,   727,   163,  1090,   561,  1041,   867,   655,   827,
     192,   867,   608,   741,   284,   284,   657,   305,   694,   284,
     885,   306,  1042,  1036,  1036,   307,   678,   935,   884,   753,
     398,   828,   226,   739,  1053,  1072,  1118,   808,   728,   748,
     729,   829,   839,   588,   589,   239,   307,   591,   593,   840,
     596,   680,   722,   609,  1019,  1022,   830,  1023,  1024,  1025,
     169,   730,   831,   193,  1026,  1027,   715,   309,   715,   715,
    1036,   715,   580,   310,   649,   699,  1054,   715,    86,   390,
     233,   715,   531,   731,   756,   479,   562,   390,   309,   776,
     432,   758,   636,   658,   310,   194,    86,   759,   832,   775,
     433,   198,   777,   679,   833,   352,   352,   352,  1066,   418,
     352,   778,   654,   774,   779,   318,   781,  1055,   207,   539,
     195,   789,   780,   199,   782,   783,   784,    86,   681,    98,
     905,   614,   457,   458,   459,   460,   461,   462,   208,   954,
     419,   955,   200,  1085,   802,   201,  1086,   420,   210,   682,
     805,   683,   685,   688,   688,   688,   688,   790,   325,   482,
     732,   454,   352,   705,   421,   707,   791,   894,   454,   896,
    1111,   897,   170,   171,   454,   790,   454,   330,   422,   454,
     172,   173,   174,  1007,   791,   804,   305,   423,   454,   792,
     306,   454,   211,   454,   871,   793,   794,   769,   424,   418,
     795,   373,   736,   738,   305,   352,   114,   114,   306,   215,
     745,  1008,   217,   793,   794,   307,   398,   750,   795,   398,
     998,   803,   483,   114,   806,   484,   485,   486,   842,   846,
     419,   138,   875,   307,   487,   847,   212,   420,   488,   220,
     320,  1018,  1009,   489,    86,   574,   110,   213,   848,   916,
     490,   924,   491,   492,   421,   493,   958,   309,   329,    86,
     463,   128,   803,   310,   960,   911,   305,   912,   422,   464,
     306,   574,  1002,  1017,   214,   309,   494,   423,  1067,   899,
     135,   310,   136,   139,   221,   165,   495,   175,   424,   140,
     496,   672,   673,   674,   325,   307,   166,   497,   465,   498,
     167,   803,   141,   466,   223,   843,   843,   142,   499,    86,
     500,   238,   843,  1095,   235,   328,   143,   325,  1078,   144,
     308,   176,   528,   145,   236,   843,   917,   222,   925,   146,
     945,   946,   947,   959,   821,   822,   177,   309,   970,   242,
     760,   959,   248,   310,   249,   250,   675,   251,   501,  1003,
     576,   502,   981,   319,   332,   801,   252,   353,   253,   147,
     354,   254,   574,    86,  1110,   244,   369,   148,   561,   877,
     407,   761,   541,   528,   212,   408,   255,   256,   762,   982,
     882,   965,   257,   258,   410,   213,   390,   409,   790,   529,
     889,   890,   411,   891,   542,   763,   412,   791,   106,   107,
     108,   109,   543,   544,   413,   414,  1061,   259,   545,   764,
     602,    86,  1063,   334,  1104,   790,   415,   546,   765,    86,
     547,   374,   548,   126,   791,   212,   793,   794,    86,   766,
     592,   795,   549,   550,   450,   909,   213,   352,   416,   352,
    -527,    86,   790,   684,   417,  1049,  1050,   983,   790,   429,
     790,   791,   551,   793,   794,   430,   644,   791,   795,   791,
     790,   339,   340,   341,  1001,    91,   356,   468,   431,   791,
     552,   689,   690,   691,  1062,   436,  1064,   936,   437,   688,
     793,   794,  -305,   439,   440,   795,   793,   794,   793,   794,
      86,   795,   737,   795,   950,   553,   261,   443,   793,   794,
     444,   445,   554,   795,  -305,   262,   965,   357,   555,   556,
     358,   264,   790,  1105,   446,   966,   476,   479,   448,   469,
     971,   791,   427,   114,   972,  1107,  1108,   619,   265,   621,
     622,   266,   623,   470,   471,   474,   475,   932,   267,   268,
     513,   515,   516,   141,  1065,   269,   270,   527,   142,   790,
     793,   794,   517,   518,   519,   795,   271,   143,   791,   272,
     144,   273,   274,   520,   145,   275,   539,   276,   540,   277,
     146,   531,   278,   565,   566,   279,   280,   281,   567,   359,
     282,   571,   283,   584,   570,   284,   587,   793,   794,   597,
     576,   583,   795,   600,   602,   285,   286,   287,   427,   249,
     250,   659,   251,    91,   660,   624,   716,   717,   661,   718,
     664,   252,   665,   253,   574,   723,   254,   666,   595,   726,
    1047,   598,   599,   667,   668,   669,   670,   671,   352,   692,
     706,   255,   256,   709,   719,   724,   611,   257,   258,   733,
     747,   616,  1039,  1048,   617,   618,   742,   754,   755,   620,
     757,   771,   249,   250,  1047,   251,   772,   773,   786,   797,
     800,   807,   259,   801,   252,   809,   253,   812,   813,   254,
      91,    91,    91,  1039,   816,   818,   819,  1048,   820,   823,
     824,   850,   851,   841,   255,   256,   852,   528,   860,  1047,
     257,   258,   858,  1082,   862,   864,  1047,   878,   883,   879,
     892,   895,   898,   900,    91,   901,   902,   903,    91,   904,
     829,   914,  1048,  1094,   915,   259,   919,   921,   923,  1048,
    1082,   356,   926,   927,   929,  1047,    91,   930,   933,   949,
     961,   967,   973,   974,   984,   985,   976,   978,   979,   980,
     986,   987,   989,   990,   991,   992,   995,   997,  1048,  1015,
    1020,   261,  1021,  -506,  1028,  1030,  1032,  1029,   249,   250,
     262,   251,   357,  1008,  1079,   358,   264,  1076,  1077,  1084,
     252,  1083,   253,   578,   356,   254,  1088,  1096,   751,  1089,
     849,  1112,   854,   265,   994,   996,   266,  1116,   948,   478,
     255,   256,   876,   267,   268,   944,   257,   258,   346,   514,
     269,   270,   656,  1033,   261,   156,   157,   219,   385,   740,
     910,   271,  1031,   262,   272,   357,   273,   274,   358,   264,
     275,   259,   276,   934,   277,  -282,   541,   278,  1052,  1051,
     279,   280,   281,  1071,   359,   282,   265,   283,   712,   266,
     284,   538,   874,   641,   713,   866,   267,   268,   542,   928,
     285,   286,   287,   269,   270,   872,   543,   544,   377,   811,
    1075,  -282,   545,  -282,   271,   524,  1119,   272,  1074,   273,
     274,   546,   735,   275,   547,   276,   548,   277,  1092,  1121,
     278,  1103,   564,   279,   280,   281,   549,   550,   282,   993,
     283,   880,   873,   284,   585,   249,   250,   615,   251,  1000,
     957,   237,   104,   285,   286,   287,   551,   252,   260,   253,
     261,   590,   254,     0,     0,     0,     0,     0,     0,   262,
       0,   263,     0,     0,   552,   264,     0,   255,   256,     0,
       0,     0,     0,   257,   258,     0,     0,     0,     0,     0,
       0,     0,   265,     0,     0,   266,     0,     0,     0,   553,
       0,     0,   267,   268,     0,     0,   554,     0,   259,   269,
     270,     0,   555,   556,     0,     0,     0,     0,     0,     0,
     271,     0,     0,   272,     0,   273,   274,     0,     0,   275,
       0,   276,     0,   277,     0,     0,   278,     0,     0,   279,
     280,   281,     0,     0,   282,     0,   283,     0,     0,   284,
     249,   250,     0,   251,     0,     0,     0,     0,     0,   285,
     286,   287,   252,     0,   253,     0,     0,   254,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   255,   256,     0,     0,     0,     0,   257,   258,
       0,     0,     0,     0,     0,     0,     0,   261,     0,     0,
       0,     0,     0,     0,     0,     0,   262,     0,   263,     0,
       0,     0,   264,   259,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   387,   265,
       0,     0,   266,     0,     0,     0,     0,     0,     0,   267,
     268,     0,     0,     0,     0,     0,   269,   270,     0,     0,
       0,     0,     0,     0,     0,   249,   250,   271,   251,     0,
     272,     0,   273,   274,     0,     0,   275,   252,   276,   253,
     277,     0,   254,   278,     0,     0,   279,   280,   281,     0,
       0,   282,     0,   283,     0,     0,   284,   255,   256,     0,
       0,     0,     0,   257,   258,     0,   285,   286,   287,     0,
       0,     0,   261,     0,     0,     0,     0,     0,     0,     0,
       0,   262,     0,   263,     0,     0,     0,   264,   259,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   427,     0,
       0,     0,     0,     0,   265,     0,     0,   266,     0,     0,
       0,     0,     0,     0,   267,   268,     0,     0,     0,     0,
       0,   269,   270,     0,     0,     0,     0,     0,     0,     0,
     249,   250,   271,   251,     0,   272,     0,   273,   274,     0,
       0,   275,   252,   276,   253,   277,     0,   254,   278,     0,
       0,   279,   280,   281,     0,     0,   282,     0,   283,     0,
       0,   284,   255,   256,     0,     0,     0,     0,   257,   258,
       0,   285,   286,   287,     0,   594,     0,   261,     0,     0,
       0,     0,     0,     0,     0,     0,   262,     0,   263,     0,
       0,     0,   264,   259,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   265,
       0,     0,   266,     0,     0,     0,     0,     0,     0,   267,
     268,     0,     0,     0,     0,     0,   269,   270,     0,     0,
       0,     0,     0,     0,     0,   249,   250,   271,   251,     0,
     272,     0,   273,   274,     0,     0,   275,   252,   276,   253,
     277,     0,   254,   278,     0,     0,   279,   280,   281,     0,
       0,   282,     0,   283,     0,     0,   284,   255,   256,     0,
       0,     0,     0,   257,   258,     0,   285,   286,   287,     0,
       0,     0,   261,     0,     0,     0,     0,     0,     0,     0,
       0,   262,     0,   263,     0,     0,     0,   264,   259,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   721,   265,     0,     0,   266,     0,     0,
       0,     0,     0,     0,   267,   268,     0,     0,     0,     0,
       0,   269,   270,     0,     0,     0,     0,     0,     0,     0,
     249,   250,   271,   251,     0,   272,     0,   273,   274,     0,
       0,   275,   252,   276,   253,   277,     0,   254,   278,     0,
       0,   279,   280,   281,     0,     0,   282,     0,   283,     0,
       0,   284,   255,   256,     0,     0,     0,     0,   257,   258,
       0,   285,   286,   287,     0,     0,     0,   261,     0,     0,
       0,     0,     0,     0,     0,     0,   262,     0,   263,     0,
       0,     0,   264,   259,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   962,   265,
       0,     0,   266,     0,     0,     0,     0,     0,     0,   267,
     268,     0,     0,     0,     0,     0,   269,   270,     0,     0,
       0,     0,     0,     0,     0,   249,   250,   271,   251,     0,
     272,     0,   273,   274,     0,     0,   275,   252,   276,   253,
     277,     0,   254,   278,     0,     0,   279,   280,   281,     0,
       0,   282,     0,   283,     0,     0,   284,   255,   256,     0,
       0,     0,     0,   257,   258,     0,   285,   286,   287,     0,
       0,     0,   261,     0,     0,     0,     0,     0,     0,     0,
       0,   262,     0,   263,     0,     0,     0,   264,   259,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   265,     0,     0,   266,     0,     0,
       0,     0,     0,     0,   267,   268,     0,     0,     0,     0,
       0,   269,   270,     0,     0,     0,     0,     0,     0,     0,
     249,   250,   271,   251,     0,   272,     0,   273,   274,     0,
       0,   275,   252,   276,   253,   277,     0,   254,   278,     0,
       0,   279,   280,   281,     0,     0,   282,     0,   283,     0,
       0,   284,   255,   256,     0,     0,     0,     0,   257,   258,
       0,   285,   286,   287,     0,     0,     0,   603,     0,     0,
       0,     0,     0,     0,     0,     0,   262,     0,   263,     0,
       0,     0,   264,   259,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   265,
       0,     0,   266,     0,     0,     0,     0,     0,     0,   267,
     268,     0,     0,     0,     0,     0,   269,   270,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   271,     0,     0,
     272,     0,   273,   274,     0,     0,   275,     0,   276,     0,
     277,     0,     0,   278,     0,     0,   279,   280,   281,     0,
       0,   282,     0,   283,     0,     0,   284,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   285,   286,   287,     0,
       0,     0,   261,     0,     0,     0,     0,     0,     0,     0,
       0,   262,     0,   263,     0,     0,     0,   264,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   265,     0,     0,   266,     0,     0,
       0,     0,     0,     0,   267,   268,     0,     0,     0,     0,
       0,   269,   270,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   271,     0,     0,   272,     0,   273,   274,     0,
       0,   275,     0,   276,     0,   277,  -564,     1,   278,     0,
       0,   279,   280,     0,     0,     0,   282,     0,     0,     0,
       0,   284,  -564,     0,     0,     0,     0,     0,     0,     0,
       0,   285,   286,   287,     0,     0,     0,     0,     0,     2,
       3,     0,     0,     0,     4,     0,     5,     0,     0,     6,
       7,     8,     9,    10,    11,    12,    13,     0,     0,     0,
       0,     0,     0,    14,    15,     0,     0,    16,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    17,    18,    19,    20,     0,    21,
      22,    23,    24,    25,    26,    27,     0,     0,    28,     0,
       0,    29,     0,    30,    31,     0,    32,    33,     0,     0,
       0,    34,    35,    36,    37,    38,    39,     0,     0,    40,
       0,     0,     0,     0,     0,     0,    41,    42,     0,     0,
      43,     0,     0,    44,     0,    45,    46,     0,     0,     0,
       0,    47,     0,     0,     0,    48,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    49,     0,    50,     0,     0,
      51,     0,     0,     0,     0,     0,     0,     0,     0,    52
};

static const yytype_int16 yycheck[] =
{
       4,   204,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    44,    22,    22,
      24,   427,   473,    27,   429,   201,    30,    31,   398,    33,
      34,   170,   169,   177,    38,    39,   601,   235,    42,    43,
      44,   217,    46,    47,   229,   230,   231,    51,   290,   326,
     292,   232,     4,   768,   198,    93,   200,   329,     4,   320,
       6,     4,   271,   624,     3,   626,   275,   276,   675,   967,
     629,     4,   111,   893,     6,     3,    15,     9,    10,     4,
       4,     6,     4,     4,    16,     4,   143,     3,     4,     4,
       6,   228,   229,   230,   231,    27,    93,     4,    30,    31,
     166,    33,    34,   206,   153,    91,    38,    39,     4,   162,
       6,    43,   719,     4,   171,    47,     4,   724,     6,    51,
     210,   125,    31,    32,   227,   531,   263,   122,   123,     3,
       4,   951,     6,     3,     3,     4,     6,     6,     3,     4,
     230,     6,   109,   708,   859,    15,    15,   356,    17,   358,
      15,    20,    17,   166,   357,    20,   160,   196,   177,   153,
     164,   165,   166,   167,   202,   153,   281,   171,   283,   308,
    1068,   175,   176,   177,   153,    22,    22,   230,  1036,   138,
      27,    27,   248,   187,     3,   329,   190,   191,   192,   193,
     194,   195,  1090,   125,   198,   199,   200,   201,   247,     4,
     403,     6,     4,   576,     6,   202,   210,   211,   212,   213,
     214,   584,   179,   217,  1072,   471,   220,   221,   474,   153,
     357,  1083,    22,   166,   209,   244,   193,    27,   232,   233,
     433,   235,   236,   792,   219,   248,   230,   796,   166,   798,
     199,    51,   230,   191,   230,   487,   488,   166,     4,   386,
    1112,   230,   813,   860,   815,   862,   242,   864,    68,    69,
     192,   193,   194,   195,   153,   198,   177,   199,     0,   153,
      52,    53,    54,    55,    56,   177,   413,   198,   166,   416,
     417,   153,   178,   198,    16,   155,   155,   244,   240,   221,
     155,   198,   429,   469,   431,   432,   230,   244,  1118,   436,
     245,   111,   439,   440,   236,   244,   153,   444,   236,   141,
     256,   315,   181,   241,   719,   240,   320,   454,   242,   724,
     242,   177,   326,   256,   240,   329,   463,   464,   465,   466,
     141,    76,    77,   244,   895,   705,   245,   229,   206,   548,
     256,   230,   244,   347,   253,   554,   230,     4,   240,     6,
     526,   183,   959,   153,   805,   153,   112,   153,   230,   227,
     116,   603,   114,    39,   166,   369,   240,   236,   153,    94,
     246,   236,   183,   571,   244,   244,   153,   112,   522,   244,
     750,   116,   256,   230,   230,   141,   153,   838,   244,   587,
     394,   116,   224,   569,   141,   200,  1111,   658,   150,   580,
     152,   126,   679,   407,   408,   409,   141,   411,   412,   681,
     414,   153,   549,   224,   973,   976,   141,   978,   979,   980,
     166,   558,   147,   246,   983,   984,   541,   183,   543,   544,
     230,   546,   230,   189,   230,   245,   183,   552,     4,   576,
     222,   556,   181,   153,   153,   230,   185,   584,   183,   217,
     209,   153,   456,   230,   189,   246,     4,   153,   183,   153,
     219,   166,   153,   230,   189,   469,   470,   471,  1029,   142,
     474,   153,   476,   610,   153,   479,   153,   224,    99,   247,
     246,   162,   619,   233,   621,   622,   623,     4,   230,     6,
     153,   250,    70,    71,    72,    73,    74,    75,   119,   862,
     173,   864,   166,  1062,   153,   166,  1065,   180,   244,   513,
     649,   515,   516,   517,   518,   519,   520,   198,   522,    65,
     230,   230,   526,   527,   197,   529,   207,   769,   230,   771,
    1095,   773,    59,    60,   230,   198,   230,   681,   211,   230,
      67,    68,    69,   143,   207,   153,   112,   220,   230,   230,
     116,   230,   244,   230,   959,   236,   237,   230,   231,   142,
     241,   565,   566,   567,   112,   569,   570,   571,   116,   136,
     574,   171,   166,   236,   237,   141,   580,   581,   241,   583,
     950,   230,   128,   587,   153,   131,   132,   133,   153,   153,
     173,    96,   729,   141,   140,   153,   229,   180,   144,   210,
     166,   971,   202,   149,     4,   742,     6,   240,   153,   153,
     156,   153,   158,   159,   197,   161,   153,   183,   166,     4,
     198,     6,   230,   189,   153,   801,   112,   803,   211,   207,
     116,   768,   153,   153,   248,   183,   182,   220,   153,   776,
       4,   189,     6,   148,   246,   229,   192,   174,   231,   154,
     196,   102,   103,   104,   658,   141,   240,   203,   236,   205,
     244,   230,   167,   241,     3,   230,   230,   172,   214,     4,
     216,     6,   230,  1079,   248,   679,   181,   681,  1048,   184,
     166,   208,   177,   188,   246,   230,   230,   230,   230,   194,
     846,   847,   848,   230,   668,   669,   223,   183,   883,     6,
     142,   230,     6,   189,     3,     4,   157,     6,   254,   230,
     230,   257,   162,     3,   230,   230,    15,   242,    17,   224,
       4,    20,   859,     4,  1094,     6,   166,   232,   732,   733,
     244,   173,   115,   177,   229,   244,    35,    36,   180,   162,
     744,   878,    41,    42,    37,   240,   883,   230,   198,   244,
     754,   755,   244,   757,   137,   197,   229,   207,    17,    18,
      19,    20,   145,   146,   166,   244,   162,    66,   151,   211,
     153,     4,   162,     6,   162,   198,     6,   160,   220,     4,
     163,     6,   165,    42,   207,   229,   236,   237,     4,   231,
       6,   241,   175,   176,     3,   799,   240,   801,   166,   803,
     244,     4,   198,     6,   166,  1008,  1009,   230,   198,   166,
     198,   207,   195,   236,   237,   166,   992,   207,   241,   207,
     198,   193,   194,   195,   961,   829,   125,    82,   166,   207,
     213,   518,   519,   520,   230,   166,   162,   841,   166,   843,
     236,   237,   225,   166,   166,   241,   236,   237,   236,   237,
       4,   241,     6,   241,   858,   238,   155,   166,   236,   237,
     166,   166,   245,   241,   247,   164,  1003,   166,   251,   252,
     169,   170,   198,   162,   166,   879,    62,   230,   166,   166,
     884,   207,   181,   887,   887,  1088,  1089,   443,   187,   445,
     446,   190,   448,   166,   166,   166,   166,   829,   197,   198,
     249,   244,   229,   167,   230,   204,   205,   244,   172,   198,
     236,   237,   166,   166,   166,   241,   215,   181,   207,   218,
     184,   220,   221,   166,   188,   224,   247,   226,   225,   228,
     194,   181,   231,   248,   244,   234,   235,   236,   229,   238,
     239,   210,   241,   175,   230,   244,   248,   236,   237,    21,
     230,   230,   241,   248,   153,   254,   255,   256,   181,     3,
       4,   166,     6,   967,   166,   248,   543,   544,   166,   546,
     166,    15,   166,    17,  1111,   552,    20,   166,   413,   556,
    1007,   416,   417,   166,   166,   166,   166,   166,   992,   118,
       3,    35,    36,    90,   166,   166,   431,    41,    42,   244,
     175,   436,  1006,  1007,   439,   440,   230,   244,   244,   444,
     244,   230,     3,     4,  1041,     6,   153,   230,     3,     3,
     153,   153,    66,   230,    15,     3,    17,     3,   248,    20,
    1034,  1035,  1036,  1037,     3,     3,     3,  1041,     3,     3,
       3,     3,     3,   244,    35,    36,     4,   177,   168,  1076,
      41,    42,   244,  1057,   168,   168,  1083,   166,   166,   244,
     166,   248,   153,   153,  1068,   153,   153,   153,  1072,   153,
     126,   153,  1076,  1077,   153,    66,     3,   230,   153,  1083,
    1084,   125,   153,   153,   153,  1112,  1090,   153,   166,     3,
     225,   210,   177,     3,   177,     3,   248,   248,   248,   248,
     153,     3,   153,     3,   153,   166,     3,   162,  1112,   201,
     153,   155,   153,   153,   153,   153,   153,   248,     3,     4,
     164,     6,   166,   171,   181,   169,   170,   230,   244,   138,
      15,   243,    17,   394,   125,    20,   246,   118,   583,   246,
     693,   230,   701,   187,   939,   942,   190,  1103,   849,   315,
      35,    36,   732,   197,   198,   843,    41,    42,   200,   332,
     204,   205,   479,  1003,   155,    52,    52,   144,   222,   570,
     800,   215,   992,   164,   218,   166,   220,   221,   169,   170,
     224,    66,   226,   836,   228,   114,   115,   231,  1014,  1011,
     234,   235,   236,  1035,   238,   239,   187,   241,   539,   190,
     244,   359,   726,   468,   540,   718,   197,   198,   137,   822,
     254,   255,   256,   204,   205,   723,   145,   146,   214,   660,
    1041,   150,   151,   152,   215,   347,  1112,   218,  1037,   220,
     221,   160,   565,   224,   163,   226,   165,   228,  1076,  1120,
     231,  1084,   370,   234,   235,   236,   175,   176,   239,   933,
     241,   742,   724,   244,   402,     3,     4,   434,     6,   959,
     867,   159,    15,   254,   255,   256,   195,    15,   153,    17,
     155,   409,    20,    -1,    -1,    -1,    -1,    -1,    -1,   164,
      -1,   166,    -1,    -1,   213,   170,    -1,    35,    36,    -1,
      -1,    -1,    -1,    41,    42,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   187,    -1,    -1,   190,    -1,    -1,    -1,   238,
      -1,    -1,   197,   198,    -1,    -1,   245,    -1,    66,   204,
     205,    -1,   251,   252,    -1,    -1,    -1,    -1,    -1,    -1,
     215,    -1,    -1,   218,    -1,   220,   221,    -1,    -1,   224,
      -1,   226,    -1,   228,    -1,    -1,   231,    -1,    -1,   234,
     235,   236,    -1,    -1,   239,    -1,   241,    -1,    -1,   244,
       3,     4,    -1,     6,    -1,    -1,    -1,    -1,    -1,   254,
     255,   256,    15,    -1,    17,    -1,    -1,    20,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    35,    36,    -1,    -1,    -1,    -1,    41,    42,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   155,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   164,    -1,   166,    -1,
      -1,    -1,   170,    66,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   186,   187,
      -1,    -1,   190,    -1,    -1,    -1,    -1,    -1,    -1,   197,
     198,    -1,    -1,    -1,    -1,    -1,   204,   205,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,     3,     4,   215,     6,    -1,
     218,    -1,   220,   221,    -1,    -1,   224,    15,   226,    17,
     228,    -1,    20,   231,    -1,    -1,   234,   235,   236,    -1,
      -1,   239,    -1,   241,    -1,    -1,   244,    35,    36,    -1,
      -1,    -1,    -1,    41,    42,    -1,   254,   255,   256,    -1,
      -1,    -1,   155,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   164,    -1,   166,    -1,    -1,    -1,   170,    66,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   181,    -1,
      -1,    -1,    -1,    -1,   187,    -1,    -1,   190,    -1,    -1,
      -1,    -1,    -1,    -1,   197,   198,    -1,    -1,    -1,    -1,
      -1,   204,   205,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
       3,     4,   215,     6,    -1,   218,    -1,   220,   221,    -1,
      -1,   224,    15,   226,    17,   228,    -1,    20,   231,    -1,
      -1,   234,   235,   236,    -1,    -1,   239,    -1,   241,    -1,
      -1,   244,    35,    36,    -1,    -1,    -1,    -1,    41,    42,
      -1,   254,   255,   256,    -1,   153,    -1,   155,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   164,    -1,   166,    -1,
      -1,    -1,   170,    66,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   187,
      -1,    -1,   190,    -1,    -1,    -1,    -1,    -1,    -1,   197,
     198,    -1,    -1,    -1,    -1,    -1,   204,   205,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,     3,     4,   215,     6,    -1,
     218,    -1,   220,   221,    -1,    -1,   224,    15,   226,    17,
     228,    -1,    20,   231,    -1,    -1,   234,   235,   236,    -1,
      -1,   239,    -1,   241,    -1,    -1,   244,    35,    36,    -1,
      -1,    -1,    -1,    41,    42,    -1,   254,   255,   256,    -1,
      -1,    -1,   155,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   164,    -1,   166,    -1,    -1,    -1,   170,    66,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   186,   187,    -1,    -1,   190,    -1,    -1,
      -1,    -1,    -1,    -1,   197,   198,    -1,    -1,    -1,    -1,
      -1,   204,   205,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
       3,     4,   215,     6,    -1,   218,    -1,   220,   221,    -1,
      -1,   224,    15,   226,    17,   228,    -1,    20,   231,    -1,
      -1,   234,   235,   236,    -1,    -1,   239,    -1,   241,    -1,
      -1,   244,    35,    36,    -1,    -1,    -1,    -1,    41,    42,
      -1,   254,   255,   256,    -1,    -1,    -1,   155,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   164,    -1,   166,    -1,
      -1,    -1,   170,    66,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   186,   187,
      -1,    -1,   190,    -1,    -1,    -1,    -1,    -1,    -1,   197,
     198,    -1,    -1,    -1,    -1,    -1,   204,   205,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,     3,     4,   215,     6,    -1,
     218,    -1,   220,   221,    -1,    -1,   224,    15,   226,    17,
     228,    -1,    20,   231,    -1,    -1,   234,   235,   236,    -1,
      -1,   239,    -1,   241,    -1,    -1,   244,    35,    36,    -1,
      -1,    -1,    -1,    41,    42,    -1,   254,   255,   256,    -1,
      -1,    -1,   155,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   164,    -1,   166,    -1,    -1,    -1,   170,    66,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   187,    -1,    -1,   190,    -1,    -1,
      -1,    -1,    -1,    -1,   197,   198,    -1,    -1,    -1,    -1,
      -1,   204,   205,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
       3,     4,   215,     6,    -1,   218,    -1,   220,   221,    -1,
      -1,   224,    15,   226,    17,   228,    -1,    20,   231,    -1,
      -1,   234,   235,   236,    -1,    -1,   239,    -1,   241,    -1,
      -1,   244,    35,    36,    -1,    -1,    -1,    -1,    41,    42,
      -1,   254,   255,   256,    -1,    -1,    -1,   155,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   164,    -1,   166,    -1,
      -1,    -1,   170,    66,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   187,
      -1,    -1,   190,    -1,    -1,    -1,    -1,    -1,    -1,   197,
     198,    -1,    -1,    -1,    -1,    -1,   204,   205,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   215,    -1,    -1,
     218,    -1,   220,   221,    -1,    -1,   224,    -1,   226,    -1,
     228,    -1,    -1,   231,    -1,    -1,   234,   235,   236,    -1,
      -1,   239,    -1,   241,    -1,    -1,   244,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   254,   255,   256,    -1,
      -1,    -1,   155,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   164,    -1,   166,    -1,    -1,    -1,   170,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   187,    -1,    -1,   190,    -1,    -1,
      -1,    -1,    -1,    -1,   197,   198,    -1,    -1,    -1,    -1,
      -1,   204,   205,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   215,    -1,    -1,   218,    -1,   220,   221,    -1,
      -1,   224,    -1,   226,    -1,   228,     0,     1,   231,    -1,
      -1,   234,   235,    -1,    -1,    -1,   239,    -1,    -1,    -1,
      -1,   244,    16,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   254,   255,   256,    -1,    -1,    -1,    -1,    -1,    33,
      34,    -1,    -1,    -1,    38,    -1,    40,    -1,    -1,    43,
      44,    45,    46,    47,    48,    49,    50,    -1,    -1,    -1,
      -1,    -1,    -1,    57,    58,    -1,    -1,    61,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    78,    79,    80,    81,    -1,    83,
      84,    85,    86,    87,    88,    89,    -1,    -1,    92,    -1,
      -1,    95,    -1,    97,    98,    -1,   100,   101,    -1,    -1,
      -1,   105,   106,   107,   108,   109,   110,    -1,    -1,   113,
      -1,    -1,    -1,    -1,    -1,    -1,   120,   121,    -1,    -1,
     124,    -1,    -1,   127,    -1,   129,   130,    -1,    -1,    -1,
      -1,   135,    -1,    -1,    -1,   139,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   179,    -1,   181,    -1,    -1,
     184,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   193
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
{
       0,     1,    33,    34,    38,    40,    43,    44,    45,    46,
      47,    48,    49,    50,    57,    58,    61,    78,    79,    80,
      81,    83,    84,    85,    86,    87,    88,    89,    92,    95,
      97,    98,   100,   101,   105,   106,   107,   108,   109,   110,
     113,   120,   121,   124,   127,   129,   130,   135,   139,   179,
     181,   184,   193,   263,   274,   275,   276,   277,   286,   293,
     313,   314,   323,   324,   325,   327,   328,   329,   330,   331,
     341,   361,   365,   411,   412,   413,   416,   417,   435,   469,
     470,   471,   472,   474,   478,   480,     4,   463,     6,   460,
     461,   463,   463,   463,   460,   460,   463,   463,     6,   462,
     463,   463,   468,   473,   473,   460,   462,   462,   462,   462,
       6,   362,   363,   400,   463,   463,   460,     3,   488,   460,
     460,   460,   460,   460,   460,   315,   462,   460,     6,   458,
     459,   463,   414,   463,   460,     4,     6,   466,    96,   148,
     154,   167,   172,   181,   184,   188,   194,   224,   232,   332,
     334,   335,   336,   191,   444,   460,   332,   334,     0,    16,
     122,   123,   475,    39,   244,   229,   240,   244,   245,   166,
      59,    60,    67,    68,    69,   174,   208,   223,   294,   295,
     296,   299,   302,   305,   306,   307,   310,   244,    76,    77,
     229,   240,   246,   246,   246,   246,   364,   365,   166,   233,
     166,   166,   342,    93,   202,   265,   460,    99,   119,   418,
     244,   244,   229,   240,   248,   136,   326,   166,   337,   337,
     210,   246,   230,     3,   141,   183,   224,   445,    52,    53,
      54,    55,    56,   222,   266,   248,   246,   471,     6,   463,
     476,   477,     6,   463,     6,   463,   463,   463,     6,     3,
       4,     6,    15,    17,    20,    35,    36,    41,    42,    66,
     153,   155,   164,   166,   170,   187,   190,   197,   198,   204,
     205,   215,   218,   220,   221,   224,   226,   228,   231,   234,
     235,   236,   239,   241,   244,   254,   255,   256,   407,   419,
     420,   421,   422,   423,   443,   448,   449,   452,   463,   465,
     479,   481,   485,   486,   487,   112,   116,   141,   166,   183,
     189,   345,   346,   351,   353,   166,   311,   312,   463,     3,
     166,   292,   304,   353,   355,   463,   166,   301,   463,   166,
     292,   297,   230,   463,     6,   463,   463,   285,   460,   285,
     285,   285,   365,   291,   292,   460,   291,   240,   343,   402,
     405,   458,   463,   242,     4,   464,   125,   166,   169,   238,
     375,   376,   377,   378,   379,   386,   388,   448,   455,   166,
     318,   463,   415,   463,     6,   463,   463,   414,   338,   402,
     178,   339,   340,   400,   460,   336,   436,   186,   272,   273,
     448,   272,   272,   272,   240,   268,   269,   271,   463,   267,
     268,   270,    93,   202,   264,   339,   460,   244,   244,   230,
      37,   244,   229,   166,   244,     6,   166,   166,   142,   173,
     180,   197,   211,   220,   231,   408,   409,   181,   448,   166,
     166,   166,   209,   219,   450,   451,   166,   166,   443,   166,
     166,   443,   443,   166,   166,   166,   166,   486,   166,   486,
       3,   409,   409,   153,   230,   177,   244,    70,    71,    72,
      73,    74,    75,   198,   207,   236,   241,   454,    82,   166,
     166,   166,   308,   353,   166,   166,    62,   309,   311,   230,
     303,   304,    65,   128,   131,   132,   133,   140,   144,   149,
     156,   158,   159,   161,   182,   192,   196,   203,   205,   214,
     216,   254,   257,   391,   392,   393,   394,   396,   434,   300,
     301,   297,   298,   249,   295,   244,   229,   166,   166,   166,
     166,   153,   230,   153,   405,   153,   230,   244,   177,   244,
     401,   181,   433,   442,   443,   375,   448,   443,   378,   247,
     225,   115,   137,   145,   146,   151,   160,   163,   165,   175,
     176,   195,   213,   238,   245,   251,   252,   385,   387,   319,
     320,   463,   185,   316,   442,   248,   244,   229,   153,   230,
     230,   210,   446,   447,   448,   153,   230,   153,   269,   153,
     230,   244,   401,   230,   175,   464,   375,   248,   463,   463,
     477,   463,     6,   463,   153,   452,   463,    21,   452,   452,
     248,   444,   153,   155,   448,   453,   479,   141,   183,   224,
     389,   452,   448,   375,   250,   451,   452,   452,   452,   389,
     452,   389,   389,   389,   248,   166,   248,   448,     3,   166,
     236,   241,   482,   484,   198,   256,   463,   448,   448,   448,
     448,   391,   348,   350,   402,   352,   402,   352,   153,   230,
     309,   352,   375,   432,   463,   153,   312,   153,   230,   166,
     166,   166,   409,   409,   166,   166,   166,   166,   166,   166,
     166,   166,   102,   103,   104,   157,   354,   356,   153,   230,
     153,   230,   463,   463,     6,   463,   289,   290,   463,   289,
     289,   289,   118,   287,   292,    51,    68,    69,   111,   245,
     278,   279,   280,   402,   198,   463,     3,   463,   444,    90,
     344,   153,   376,   377,   383,   486,   383,   383,   383,   166,
     443,   186,   448,   383,   166,   443,   383,   114,   150,   152,
     448,   153,   230,   244,   317,   415,   463,     6,   463,   402,
     340,   339,   230,   437,   242,   463,   273,   175,   268,   198,
     463,   270,   273,   339,   244,   244,   153,   244,   153,   153,
     142,   173,   180,   197,   211,   220,   231,   410,   445,   230,
     409,   230,   153,   230,   448,   153,   217,   153,   153,   153,
     448,   153,   448,   448,   448,   410,     3,   410,   482,   162,
     198,   207,   230,   236,   237,   241,   483,     3,   177,   244,
     153,   230,   153,   230,   153,   353,   153,   153,   304,     3,
     397,   397,     3,   248,   166,   248,     3,   398,     3,     3,
       3,   398,   398,     3,     3,     6,   407,    94,   116,   126,
     141,   147,   183,   189,   347,   357,   358,   359,   360,   301,
     297,   244,   153,   230,   206,   227,   153,   153,   153,   278,
       3,     3,     4,   281,   280,   401,   162,   230,   244,   445,
     168,   380,   168,   382,   168,   381,   380,   236,   407,   456,
     457,   479,   382,   456,   381,   448,   320,   463,   166,   244,
     447,   467,   463,   166,   244,   401,    91,   242,   333,   463,
     463,   463,   166,   446,   409,   248,   409,   409,   153,   448,
     153,   153,   153,   153,   153,   153,   482,   482,   482,   463,
     347,   402,   402,   309,   153,   153,   153,   230,   410,     3,
     410,   230,   395,   153,   153,   230,   153,   153,   395,   153,
     153,   349,   460,   166,   359,   309,   463,    31,    32,   245,
     253,   282,   283,   284,   290,   282,   282,   282,   287,     3,
     463,   446,   384,   407,   384,   384,     3,   465,   153,   230,
     153,   225,   186,   321,   322,   448,   463,   210,   368,   372,
     272,   463,   400,   177,     3,   372,   248,   410,   248,   248,
     248,   162,   162,   230,   177,     3,   153,     3,   399,   153,
       3,   153,   166,   432,   281,     3,   284,   162,   401,   372,
     457,   448,   153,   230,   369,   371,   460,   143,   171,   202,
     366,   367,   373,   374,   429,   201,   439,   153,   401,   482,
     153,   153,   410,   410,   410,   410,   482,   482,   153,   248,
     153,   350,   153,   322,    22,    27,   230,   242,   406,   463,
       3,   240,   256,   403,   404,   430,   431,   458,   463,   375,
     375,   374,   366,   141,   183,   224,   390,   138,   199,   424,
     440,   162,   230,   162,   162,   230,   410,   153,   166,   369,
     370,   370,   200,   371,   406,   404,   230,   244,   401,   181,
     438,   441,   463,   243,   138,   482,   482,   369,   246,   246,
     166,   371,   431,   198,   463,   444,   118,   288,     3,   403,
     425,   426,   427,   441,   162,   162,   153,   375,   375,   369,
     401,   445,   230,   206,   227,   428,   288,   153,   446,   426,
     372,   439
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
#line 411 "sql.yacc"
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
#line 437 "sql.yacc"
    {
		(yyval.ptr)=0;
	}
    break;

  case 4:

/* Line 1455 of yacc.c  */
#line 440 "sql.yacc"
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
#line 457 "sql.yacc"
    {
		(yyval.ptr)=A4GL_new_select_list_item_expr((yyvsp[(2) - (2)].s_select_list_item));
	}
    break;

  case 6:

/* Line 1455 of yacc.c  */
#line 462 "sql.yacc"
    {
		(yyval.ptr)=0;
	}
    break;

  case 7:

/* Line 1455 of yacc.c  */
#line 465 "sql.yacc"
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
#line 482 "sql.yacc"
    {
		 (yyval.ptr)=A4GL_new_select_list_item_expr((yyvsp[(2) - (2)].s_select_list_item));
	}
    break;

  case 9:

/* Line 1455 of yacc.c  */
#line 488 "sql.yacc"
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
#line 497 "sql.yacc"
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
#line 506 "sql.yacc"
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
#line 515 "sql.yacc"
    {
		(yyval.update_cmd)=(yyvsp[(2) - (2)].update_cmd);
		add_feature("UPDATE_COLUMN_EQ_VALUE_LIST");
    }
    break;

  case 13:

/* Line 1455 of yacc.c  */
#line 522 "sql.yacc"
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
		//$<update_cmd>$->value_list=make_select_list_item_list_from_variable_record(buff); 
		(yyval.update_cmd)->where_clause=0;
#endif
	}
    break;

  case 15:

/* Line 1455 of yacc.c  */
#line 592 "sql.yacc"
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
#line 599 "sql.yacc"
    {
		(yyval.update_cmd)=(yyvsp[(1) - (3)].update_cmd);
		add_str_list((yyval.update_cmd)->column_list, (yyvsp[(3) - (3)].upd_pair)->column_name);
		local_add_select_list_item_list((yyval.update_cmd)->value_list, (yyvsp[(3) - (3)].upd_pair)->value);
	}
    break;

  case 17:

/* Line 1455 of yacc.c  */
#line 610 "sql.yacc"
    {
                strcpy((yyval.str),(yyvsp[(1) - (1)].str));
        }
    break;

  case 18:

/* Line 1455 of yacc.c  */
#line 613 "sql.yacc"
    {
                strcpy((yyval.str),(yyvsp[(2) - (2)].str));
        }
    break;

  case 19:

/* Line 1455 of yacc.c  */
#line 618 "sql.yacc"
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
#line 625 "sql.yacc"
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
#line 642 "sql.yacc"
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
#line 659 "sql.yacc"
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
#line 680 "sql.yacc"
    {
		(yyval.upd_pair)=malloc(sizeof(struct s_update_pair));
		(yyval.upd_pair)->column_name=acl_strdup((yyvsp[(1) - (3)].str));
		(yyval.upd_pair)->value=(yyvsp[(3) - (3)].s_select_list_item);
	}
    break;

  case 24:

/* Line 1455 of yacc.c  */
#line 689 "sql.yacc"
    {
			(yyval.str_list)=new_str_list((yyvsp[(1) - (1)].str));
		}
    break;

  case 25:

/* Line 1455 of yacc.c  */
#line 692 "sql.yacc"
    {
			(yyval.str_list)=add_str_list((yyvsp[(1) - (3)].str_list), (yyvsp[(3) - (3)].str));
		}
    break;

  case 26:

/* Line 1455 of yacc.c  */
#line 700 "sql.yacc"
    { 
		(yyval.s_select_list_item_list)=local_new_select_list_item_list((yyvsp[(1) - (1)].s_select_list_item));
	}
    break;

  case 27:

/* Line 1455 of yacc.c  */
#line 703 "sql.yacc"
    { 
		(yyval.s_select_list_item_list)=local_add_select_list_item_list((yyvsp[(1) - (3)].s_select_list_item_list),(yyvsp[(3) - (3)].s_select_list_item));
	}
    break;

  case 28:

/* Line 1455 of yacc.c  */
#line 711 "sql.yacc"
    {(yyval.s_select_list_item)=(yyvsp[(1) - (1)].s_select_list_item);}
    break;

  case 29:

/* Line 1455 of yacc.c  */
#line 712 "sql.yacc"
    {(yyval.s_select_list_item)=new_select_list_item_builtin_const(E_SLI_BUILTIN_CONST_NULL); }
    break;

  case 30:

/* Line 1455 of yacc.c  */
#line 719 "sql.yacc"
    { (yyval.sql_string)=make_sql_string_and_free(acl_strdup((yyvsp[(1) - (1)].str)), NULL);}
    break;

  case 31:

/* Line 1455 of yacc.c  */
#line 722 "sql.yacc"
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
#line 730 "sql.yacc"
    {SPRINTF2((yyval.str),"%s %s ",(yyvsp[(1) - (2)].str),(yyvsp[(2) - (2)].str));
			add_feature("DROP_VIEW");
}
    break;

  case 33:

/* Line 1455 of yacc.c  */
#line 733 "sql.yacc"
    {SPRINTF2((yyval.str),"%s %s",(yyvsp[(1) - (2)].str),(yyvsp[(2) - (2)].str));
		if (strchr((yyvsp[(2) - (2)].str),'@') || strchr((yyvsp[(2) - (2)].str),':')) add_feature("DROP_INDEX_QUALIFIED_PATH");
			add_feature("DROP_INDEX");
}
    break;

  case 34:

/* Line 1455 of yacc.c  */
#line 737 "sql.yacc"
    {SPRINTF2((yyval.str),"%s %s",(yyvsp[(1) - (2)].str),(yyvsp[(2) - (2)].str));
			add_feature("DROP_TRIGGER");
}
    break;

  case 35:

/* Line 1455 of yacc.c  */
#line 743 "sql.yacc"
    {(yyval.sql_string)=acl_strdup((yyvsp[(1) - (1)].str));}
    break;

  case 36:

/* Line 1455 of yacc.c  */
#line 744 "sql.yacc"
    {(yyval.sql_string)=(yyvsp[(1) - (1)].sql_string);}
    break;

  case 37:

/* Line 1455 of yacc.c  */
#line 748 "sql.yacc"
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
#line 758 "sql.yacc"
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
#line 772 "sql.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 40:

/* Line 1455 of yacc.c  */
#line 773 "sql.yacc"
    {strcpy((yyval.str),(yyvsp[(1) - (1)].str));}
    break;

  case 42:

/* Line 1455 of yacc.c  */
#line 778 "sql.yacc"
    {SPRINTF2((yyval.str),"%s%s",(yyvsp[(1) - (2)].str),(yyvsp[(2) - (2)].str)); }
    break;

  case 43:

/* Line 1455 of yacc.c  */
#line 783 "sql.yacc"
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
#line 791 "sql.yacc"
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
#line 799 "sql.yacc"
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
#line 807 "sql.yacc"
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
#line 815 "sql.yacc"
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
#line 827 "sql.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 50:

/* Line 1455 of yacc.c  */
#line 827 "sql.yacc"
    {strcpy((yyval.str),(yyvsp[(1) - (1)].str));}
    break;

  case 52:

/* Line 1455 of yacc.c  */
#line 831 "sql.yacc"
    {SPRINTF2((yyval.str),"%s%s",(yyvsp[(1) - (2)].str),(yyvsp[(2) - (2)].str));}
    break;

  case 53:

/* Line 1455 of yacc.c  */
#line 835 "sql.yacc"
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
#line 842 "sql.yacc"
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
#line 849 "sql.yacc"
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
#line 856 "sql.yacc"
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
#line 865 "sql.yacc"
    { strcpy(last_tmp_name,(yyvsp[(1) - (1)].str)); }
    break;

  case 58:

/* Line 1455 of yacc.c  */
#line 869 "sql.yacc"
    {SPRINTF7((yyval.str),"CREATE UNIQUE INDEX %s %s %s %s %s %s %s",(yyvsp[(2) - (8)].str),(yyvsp[(3) - (8)].str),(yyvsp[(4) - (8)].str),(yyvsp[(5) - (8)].str),(yyvsp[(6) - (8)].str),(yyvsp[(7) - (8)].str),(yyvsp[(8) - (8)].str));
		add_feature("CREATE_INDEX");
		add_feature("CREATE_INDEX_UNIQUE");
		if (strchr((yyvsp[(2) - (8)].str),'@') || strchr((yyvsp[(2) - (8)].str),':')) add_feature("CREATE_INDEX_QUALIFIED_PATH");
		if (strchr((yyvsp[(6) - (8)].str),',')) { add_feature("CREATE_INDEX_COMPOSITE"); }
	
}
    break;

  case 59:

/* Line 1455 of yacc.c  */
#line 876 "sql.yacc"
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
#line 888 "sql.yacc"
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
#line 899 "sql.yacc"
    {
		if (strchr((yyvsp[(2) - (8)].str),'@') || strchr((yyvsp[(2) - (8)].str),':')) add_feature("CREATE_INDEX_QUALIFIED_PATH");
		if (strchr((yyvsp[(6) - (8)].str),',')) { add_feature("CREATE_INDEX_COMPOSITE"); }
			add_feature("CREATE_INDEX");
			SPRINTF7((yyval.str)," CREATE INDEX %s %s %s %s %s %s %s",(yyvsp[(2) - (8)].str),(yyvsp[(3) - (8)].str),(yyvsp[(4) - (8)].str),(yyvsp[(5) - (8)].str),(yyvsp[(6) - (8)].str),(yyvsp[(7) - (8)].str),(yyvsp[(8) - (8)].str));
	}
    break;

  case 62:

/* Line 1455 of yacc.c  */
#line 905 "sql.yacc"
    {
		add_feature("CREATE_DATABASE");
		a4gl_yyerror("You cannot create a database from within Aubit4gl - if the target database allows - prepare and execute it manually");
	}
    break;

  case 63:

/* Line 1455 of yacc.c  */
#line 909 "sql.yacc"
    {
		add_feature("DROP_DATABASE");
		a4gl_yyerror("You cannot drop a database from within Aubit4gl - if the target database allows - prepare and execute it manually");
	}
    break;

  case 64:

/* Line 1455 of yacc.c  */
#line 913 "sql.yacc"
    { 
		if (strchr((yyvsp[(2) - (4)].str),'@') || strchr((yyvsp[(2) - (4)].str),':')) add_feature("CREATE_SYNONYM_QUALIFIED_PATH");
			add_feature("CREATE_SYNONYM");
			SPRINTF3((yyval.str),"%s %s FOR %s",(yyvsp[(1) - (4)].str),(yyvsp[(2) - (4)].str),(yyvsp[(4) - (4)].str)); 
	}
    break;

  case 65:

/* Line 1455 of yacc.c  */
#line 918 "sql.yacc"
    { 
		add_feature("CREATE_AUDIT");
		SPRINTF2((yyval.str),"CREATE AUDIT FOR %s IN '%s'",(yyvsp[(2) - (4)].str),A4GL_strip_quotes((yyvsp[(4) - (4)].str))); 
	}
    break;

  case 66:

/* Line 1455 of yacc.c  */
#line 922 "sql.yacc"
    { 
		add_feature("DROP_AUDIT");
		SPRINTF1((yyval.str),"DROP AUDIT FOR %s",(yyvsp[(2) - (2)].str)); }
    break;

  case 67:

/* Line 1455 of yacc.c  */
#line 925 "sql.yacc"
    { 
		if (strchr((yyvsp[(2) - (2)].str),'@') || strchr((yyvsp[(2) - (2)].str),':')) add_feature("DROP_SYNONYM_QUALIFIED_PATH");
		add_feature("DROP_SYNONYM");
		SPRINTF2((yyval.str),"%s %s",(yyvsp[(1) - (2)].str),(yyvsp[(2) - (2)].str)); }
    break;

  case 68:

/* Line 1455 of yacc.c  */
#line 929 "sql.yacc"
    { 
		add_feature("RECOVER_TABLE");
		SPRINTF1((yyval.str),"RECOVER TABLE %s",(yyvsp[(2) - (2)].str)); }
    break;

  case 69:

/* Line 1455 of yacc.c  */
#line 932 "sql.yacc"
    { 
		add_feature("ROLLFORWARD_DATABASE");
		SPRINTF1((yyval.str),"ROLLFORWARD DATABASE %s",(yyvsp[(2) - (2)].str)); }
    break;

  case 70:

/* Line 1455 of yacc.c  */
#line 939 "sql.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 71:

/* Line 1455 of yacc.c  */
#line 940 "sql.yacc"
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
#line 950 "sql.yacc"
    {(yyval.integer_val)=0;}
    break;

  case 73:

/* Line 1455 of yacc.c  */
#line 951 "sql.yacc"
    { (yyval.integer_val)=1;}
    break;

  case 75:

/* Line 1455 of yacc.c  */
#line 956 "sql.yacc"
    {SPRINTF2((yyval.str),"%s,%s",(yyvsp[(1) - (3)].str),(yyvsp[(3) - (3)].str));}
    break;

  case 76:

/* Line 1455 of yacc.c  */
#line 960 "sql.yacc"
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
#line 969 "sql.yacc"
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
#line 978 "sql.yacc"
    {
		strcpy((yyval.str),A4GL_confirm_colname(last_tmp_name,(yyvsp[(1) - (1)].str)));
}
    break;

  case 79:

/* Line 1455 of yacc.c  */
#line 985 "sql.yacc"
    {
		(yyval.sql_string)=(yyvsp[(1) - (1)].sql_string);
	}
    break;

  case 80:

/* Line 1455 of yacc.c  */
#line 988 "sql.yacc"
    {
		(yyval.sql_string)=make_sql_string_and_free((yyvsp[(1) - (3)].sql_string),kw_comma,strdup("\n"),(yyvsp[(3) - (3)].sql_string),NULL);
	}
    break;

  case 81:

/* Line 1455 of yacc.c  */
#line 994 "sql.yacc"
    {
		(yyval.sql_string)=make_sql_string_and_free(strdup("   "),(yyvsp[(1) - (1)].sql_string),NULL);
	}
    break;

  case 82:

/* Line 1455 of yacc.c  */
#line 997 "sql.yacc"
    {
		(yyval.sql_string)=make_sql_string_and_free(strdup("   "),(yyvsp[(1) - (1)].sql_string),NULL);
	}
    break;

  case 83:

/* Line 1455 of yacc.c  */
#line 1008 "sql.yacc"
    {
		add_feature("ALTER_TABLE");
	(yyval.sql_string)=make_sql_string_and_free(acl_strdup((yyvsp[(1) - (3)].str)),kw_space,acl_strdup((yyvsp[(2) - (3)].str)),kw_space,(yyvsp[(3) - (3)].sql_string),NULL);
	}
    break;

  case 84:

/* Line 1455 of yacc.c  */
#line 1012 "sql.yacc"
    {
		add_feature("CLUSTER_INDEX");
		add_feature("ALTER_INDEX_CLUSTER");
		(yyval.sql_string)=make_sql_string_and_free(acl_strdup("ALTER INDEX "),acl_strdup((yyvsp[(2) - (3)].str)),acl_strdup(" TO CLUSTER"),NULL);
		}
    break;

  case 85:

/* Line 1455 of yacc.c  */
#line 1017 "sql.yacc"
    {
		add_feature("ALTER_INDEX_NOT_CLUSTER");
		(yyval.sql_string)=make_sql_string_and_free(acl_strdup("ALTER INDEX "),acl_strdup((yyvsp[(2) - (3)].str)),acl_strdup(" TO NOT CLUSTER"),NULL);
		}
    break;

  case 86:

/* Line 1455 of yacc.c  */
#line 1024 "sql.yacc"
    {
		(yyval.sql_string)=(yyvsp[(1) - (1)].sql_string);
	}
    break;

  case 87:

/* Line 1455 of yacc.c  */
#line 1027 "sql.yacc"
    {
		(yyval.sql_string)=make_sql_string_and_free((yyvsp[(1) - (3)].sql_string),kw_comma,(yyvsp[(3) - (3)].sql_string),NULL);
	}
    break;

  case 88:

/* Line 1455 of yacc.c  */
#line 1036 "sql.yacc"
    {
		(yyval.sql_string)=(yyvsp[(1) - (1)].sql_string);
	}
    break;

  case 89:

/* Line 1455 of yacc.c  */
#line 1039 "sql.yacc"
    {
	add_feature("ALTER_TABLE_DROP");
		(yyval.sql_string)=acl_strdup((yyvsp[(1) - (1)].str));
	}
    break;

  case 90:

/* Line 1455 of yacc.c  */
#line 1043 "sql.yacc"
    {
	add_feature("ALTER_TABLE_MODIFY");
		(yyval.sql_string)=(yyvsp[(1) - (1)].sql_string);
	}
    break;

  case 91:

/* Line 1455 of yacc.c  */
#line 1047 "sql.yacc"
    {
		add_feature("ALTER_TABLE_ADD_CONSTRAINT");
		(yyval.sql_string)=acl_strdup((yyvsp[(1) - (1)].str));
	}
    break;

  case 92:

/* Line 1455 of yacc.c  */
#line 1051 "sql.yacc"
    {
		add_feature("ALTER_TABLE_DROP_CONSTRAINT");
		(yyval.sql_string)=acl_strdup((yyvsp[(1) - (1)].str));
	}
    break;

  case 93:

/* Line 1455 of yacc.c  */
#line 1055 "sql.yacc"
    {
		add_feature("ALTER_TABLE_MODIFY_NEXT");
		(yyval.sql_string)=acl_strdup((yyvsp[(1) - (1)].str));
	}
    break;

  case 94:

/* Line 1455 of yacc.c  */
#line 1059 "sql.yacc"
    {
		add_feature("ALTER_TABLE_LOCK_MODE");
		(yyval.sql_string)=acl_strdup((yyvsp[(1) - (1)].str));
	}
    break;

  case 95:

/* Line 1455 of yacc.c  */
#line 1067 "sql.yacc"
    {
		add_feature("ALTER_TABLE_ADD");
		(yyval.sql_string)=make_sql_string_and_free(acl_strdup("ADD "),(yyvsp[(2) - (2)].sql_string),NULL);
	}
    break;

  case 96:

/* Line 1455 of yacc.c  */
#line 1071 "sql.yacc"
    {
		add_feature("ALTER_TABLE_ADD");
		(yyval.sql_string)=make_sql_string_and_free(acl_strdup("ADD "),kw_ob,(yyvsp[(3) - (4)].sql_string),kw_cb,NULL);
	}
    break;

  case 97:

/* Line 1455 of yacc.c  */
#line 1079 "sql.yacc"
    {
		(yyval.sql_string)=(yyvsp[(1) - (1)].sql_string);
	}
    break;

  case 98:

/* Line 1455 of yacc.c  */
#line 1082 "sql.yacc"
    {
		add_feature("ALTER_TABLE_ADD_BEFORE");
		(yyval.sql_string)=make_sql_string_and_free((yyvsp[(1) - (3)].sql_string),acl_strdup(" BEFORE "),acl_strdup((yyvsp[(3) - (3)].str)),NULL);
	}
    break;

  case 99:

/* Line 1455 of yacc.c  */
#line 1089 "sql.yacc"
    {
		(yyval.sql_string)=(yyvsp[(1) - (1)].sql_string);
	}
    break;

  case 100:

/* Line 1455 of yacc.c  */
#line 1092 "sql.yacc"
    {
		(yyval.sql_string)=make_sql_string_and_free((yyvsp[(1) - (3)].sql_string),kw_comma,(yyvsp[(3) - (3)].sql_string),NULL);
	}
    break;

  case 101:

/* Line 1455 of yacc.c  */
#line 1099 "sql.yacc"
    {
		SPRINTF1((yyval.str),"DROP %s",(yyvsp[(2) - (2)].str));
	}
    break;

  case 102:

/* Line 1455 of yacc.c  */
#line 1102 "sql.yacc"
    {
		SPRINTF1((yyval.str),"DROP (%s)",(yyvsp[(3) - (4)].str));
	}
    break;

  case 104:

/* Line 1455 of yacc.c  */
#line 1110 "sql.yacc"
    {
		SPRINTF2((yyval.str),"%s,%s",(yyvsp[(1) - (3)].str),(yyvsp[(3) - (3)].str));
	}
    break;

  case 106:

/* Line 1455 of yacc.c  */
#line 1119 "sql.yacc"
    {
		(yyval.sql_string)=make_sql_string_and_free(acl_strdup("MODIFY "),(yyvsp[(2) - (2)].sql_string),NULL);
	}
    break;

  case 107:

/* Line 1455 of yacc.c  */
#line 1122 "sql.yacc"
    {
		(yyval.sql_string)=make_sql_string_and_free(acl_strdup("MODIFY "),kw_ob,(yyvsp[(3) - (4)].sql_string),kw_cb,NULL);
	}
    break;

  case 108:

/* Line 1455 of yacc.c  */
#line 1128 "sql.yacc"
    {
		(yyval.sql_string)=(yyvsp[(1) - (1)].sql_string);
	}
    break;

  case 109:

/* Line 1455 of yacc.c  */
#line 1131 "sql.yacc"
    {
		(yyval.sql_string)=make_sql_string_and_free((yyvsp[(1) - (3)].sql_string),kw_comma,(yyvsp[(3) - (3)].sql_string),NULL);
	}
    break;

  case 110:

/* Line 1455 of yacc.c  */
#line 1137 "sql.yacc"
    {
		(yyval.sql_string)=(yyvsp[(1) - (1)].sql_string);
	}
    break;

  case 111:

/* Line 1455 of yacc.c  */
#line 1144 "sql.yacc"
    {strcpy((yyval.str),"LOCK MODE (PAGE)");}
    break;

  case 112:

/* Line 1455 of yacc.c  */
#line 1145 "sql.yacc"
    {strcpy((yyval.str),"LOCK MODE (ROW)");}
    break;

  case 113:

/* Line 1455 of yacc.c  */
#line 1149 "sql.yacc"
    {
		add_feature("DDL_NEXT_SIZE");
		SPRINTF1((yyval.str),"MODIFY NEXT SIZE %d",atoi((yyvsp[(2) - (2)].str)));
	}
    break;

  case 114:

/* Line 1455 of yacc.c  */
#line 1157 "sql.yacc"
    {
		add_feature("DDL_CONSTRAINT");
		SPRINTF2((yyval.str),"ADD CONSTRAINT %s%s",(yyvsp[(2) - (3)].sql_string),(yyvsp[(3) - (3)].str));
	}
    break;

  case 115:

/* Line 1455 of yacc.c  */
#line 1161 "sql.yacc"
    {
		add_feature("ADD_CONSTRAINT");
		SPRINTF1((yyval.str),"ADD CONSTRAINT (%s)",(yyvsp[(3) - (4)].sql_string));
	}
    break;

  case 116:

/* Line 1455 of yacc.c  */
#line 1168 "sql.yacc"
    {
		(yyval.sql_string)=make_sql_string_and_free((yyvsp[(1) - (2)].sql_string),acl_strdup((yyvsp[(2) - (2)].str)),NULL);
}
    break;

  case 117:

/* Line 1455 of yacc.c  */
#line 1170 "sql.yacc"
    {
	(yyval.sql_string)=make_sql_string_and_free((yyvsp[(1) - (4)].sql_string),kw_comma,(yyvsp[(3) - (4)].sql_string),acl_strdup((yyvsp[(4) - (4)].str)), NULL);
}
    break;

  case 118:

/* Line 1455 of yacc.c  */
#line 1175 "sql.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 119:

/* Line 1455 of yacc.c  */
#line 1176 "sql.yacc"
    {SPRINTF2((yyval.str)," %s %s",(yyvsp[(1) - (2)].str),(yyvsp[(2) - (2)].str)); add_feature("DDL_CONSTRAINT");}
    break;

  case 120:

/* Line 1455 of yacc.c  */
#line 1181 "sql.yacc"
    { SPRINTF1((yyval.str),"DROP CONSTRAINT %s",(yyvsp[(2) - (2)].str)); add_feature("DROP_CONSTRAINT"); }
    break;

  case 121:

/* Line 1455 of yacc.c  */
#line 1182 "sql.yacc"
    {add_feature("DROP_CONSTRAINT");
		SPRINTF1((yyval.str),"DROP CONSTRAINT (%s)",(yyvsp[(3) - (4)].str));
	}
    break;

  case 122:

/* Line 1455 of yacc.c  */
#line 1188 "sql.yacc"
    {strcpy((yyval.str),(yyvsp[(1) - (1)].str));}
    break;

  case 123:

/* Line 1455 of yacc.c  */
#line 1189 "sql.yacc"
    {SPRINTF2((yyval.str),"%s,%s",(yyvsp[(1) - (3)].str),(yyvsp[(3) - (3)].str));}
    break;

  case 125:

/* Line 1455 of yacc.c  */
#line 1203 "sql.yacc"
    {  add_feature("ROLLBACK_WORK"); }
    break;

  case 126:

/* Line 1455 of yacc.c  */
#line 1209 "sql.yacc"
    { insql=1;}
    break;

  case 127:

/* Line 1455 of yacc.c  */
#line 1209 "sql.yacc"
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
#line 1218 "sql.yacc"
    {insql=1;}
    break;

  case 129:

/* Line 1455 of yacc.c  */
#line 1218 "sql.yacc"
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
#line 1227 "sql.yacc"
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
#line 1252 "sql.yacc"
    {
			(yyval.str_list)=0;
	}
    break;

  case 132:

/* Line 1455 of yacc.c  */
#line 1255 "sql.yacc"
    {
			(yyval.str_list)=(yyvsp[(2) - (3)].str_list);
			 add_feature("INSERT_COLUMNLIST_EQ_VALUELIST");
	}
    break;

  case 133:

/* Line 1455 of yacc.c  */
#line 1263 "sql.yacc"
    {
                        (yyval.str_list)=new_str_list((yyvsp[(1) - (1)].str));
	}
    break;

  case 134:

/* Line 1455 of yacc.c  */
#line 1266 "sql.yacc"
    {
                        (yyval.str_list)=add_str_list((yyvsp[(1) - (3)].str_list), (yyvsp[(3) - (3)].str));
	}
    break;

  case 135:

/* Line 1455 of yacc.c  */
#line 1273 "sql.yacc"
    {	
			strcpy((yyval.str),(yyvsp[(1) - (1)].str));
	}
    break;

  case 136:

/* Line 1455 of yacc.c  */
#line 1276 "sql.yacc"
    { 
			/* with a table prefix - on an insert ? We'll just silently drop it... */
			strcpy((yyval.str),(yyvsp[(3) - (3)].str));
			A4GL_warn("Dropped table prefix from INSERT column name");
	}
    break;

  case 137:

/* Line 1455 of yacc.c  */
#line 1284 "sql.yacc"
    { (yyval.s_select_list_item_list)=local_new_select_list_item_list((yyvsp[(1) - (1)].s_select_list_item));}
    break;

  case 138:

/* Line 1455 of yacc.c  */
#line 1285 "sql.yacc"
    {
		(yyval.s_select_list_item_list)=local_add_select_list_item_list((yyvsp[(1) - (3)].s_select_list_item_list),(yyvsp[(3) - (3)].s_select_list_item));
	}
    break;

  case 139:

/* Line 1455 of yacc.c  */
#line 1291 "sql.yacc"
    {(yyval.s_select_list_item)=(yyvsp[(1) - (1)].s_select_list_item);}
    break;

  case 140:

/* Line 1455 of yacc.c  */
#line 1292 "sql.yacc"
    {(yyval.s_select_list_item)=new_select_list_item_builtin_const(E_SLI_BUILTIN_CONST_NULL); }
    break;

  case 141:

/* Line 1455 of yacc.c  */
#line 1300 "sql.yacc"
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
#line 1318 "sql.yacc"
    { add_feature("BEGIN_WORK"); }
    break;

  case 143:

/* Line 1455 of yacc.c  */
#line 1322 "sql.yacc"
    { add_feature("COMMIT_WORK"); }
    break;

  case 144:

/* Line 1455 of yacc.c  */
#line 1327 "sql.yacc"
    {(yyval.e_boolean)=EB_FALSE;}
    break;

  case 145:

/* Line 1455 of yacc.c  */
#line 1328 "sql.yacc"
    {
		add_feature("DATABASE_EXCLUSIVE");
		{(yyval.e_boolean)=EB_TRUE;}
	}
    break;

  case 146:

/* Line 1455 of yacc.c  */
#line 1338 "sql.yacc"
    {
	char buff[256];
	(yyval.sql_string)=make_sql_string_and_free(acl_strdup((yyvsp[(1) - (1)].str)),NULL);
	SPRINTF1(buff,"Warning: Informix specific SQL @ line %d\n",yylineno);
	ansi_violation(buff,1);
	}
    break;

  case 147:

/* Line 1455 of yacc.c  */
#line 1347 "sql.yacc"
    {
			add_feature("START_DATABASE_WITH_LOG_MODE_ANSI");
			sprintf((yyval.str),"START DATABASE %s WITH LOG IN %s MODE ANSI", (yyvsp[(2) - (5)].str),(yyvsp[(4) - (5)].str));
	}
    break;

  case 148:

/* Line 1455 of yacc.c  */
#line 1351 "sql.yacc"
    {
			add_feature("START_DATABASE_WITH_LOG");
			sprintf((yyval.str),"START DATABASE %s WITH LOG IN %s", (yyvsp[(2) - (4)].str),(yyvsp[(4) - (4)].str));
	}
    break;

  case 149:

/* Line 1455 of yacc.c  */
#line 1356 "sql.yacc"
    {
			add_feature("SET_CONSTRAINTS_ALL_IMMEDIATE");
			SPRINTF1((yyval.str),"%s",(yyvsp[(1) - (1)].str)); 
	}
    break;

  case 150:

/* Line 1455 of yacc.c  */
#line 1360 "sql.yacc"
    {
		add_feature("SET_BUFFERED_LOG");
			SPRINTF1((yyval.str),"%s",(yyvsp[(1) - (1)].str)); 
	}
    break;

  case 151:

/* Line 1455 of yacc.c  */
#line 1364 "sql.yacc"
    {
		add_feature("SET_LOG");
			SPRINTF1((yyval.str),"%s",(yyvsp[(1) - (1)].str)); 
	}
    break;

  case 152:

/* Line 1455 of yacc.c  */
#line 1368 "sql.yacc"
    {
			SPRINTF2((yyval.str),"%s %s",(yyvsp[(1) - (2)].str),(yyvsp[(2) - (2)].str)); add_feature("UPDATE_STATISTICS_TABLE");
	}
    break;

  case 153:

/* Line 1455 of yacc.c  */
#line 1371 "sql.yacc"
    {
		add_feature("UPDATE_STATISTICS");
			SPRINTF1((yyval.str),"%s",(yyvsp[(1) - (1)].str)); 
	}
    break;

  case 154:

/* Line 1455 of yacc.c  */
#line 1378 "sql.yacc"
    { (yyval.integer_val)=1; }
    break;

  case 155:

/* Line 1455 of yacc.c  */
#line 1379 "sql.yacc"
    { (yyval.integer_val)=-1; }
    break;

  case 156:

/* Line 1455 of yacc.c  */
#line 1380 "sql.yacc"
    { (yyval.integer_val)=0; }
    break;

  case 157:

/* Line 1455 of yacc.c  */
#line 1384 "sql.yacc"
    { (yyval.sql_string)=(yyvsp[(1) - (1)].sql_string); }
    break;

  case 158:

/* Line 1455 of yacc.c  */
#line 1385 "sql.yacc"
    { (yyval.sql_string)=(yyvsp[(1) - (1)].sql_string); }
    break;

  case 159:

/* Line 1455 of yacc.c  */
#line 1386 "sql.yacc"
    { (yyval.sql_string)=(yyvsp[(1) - (1)].sql_string); }
    break;

  case 160:

/* Line 1455 of yacc.c  */
#line 1387 "sql.yacc"
    { (yyval.sql_string)=(yyvsp[(1) - (1)].sql_string); }
    break;

  case 161:

/* Line 1455 of yacc.c  */
#line 1388 "sql.yacc"
    { (yyval.sql_string)=(yyvsp[(1) - (1)].sql_string); }
    break;

  case 162:

/* Line 1455 of yacc.c  */
#line 1389 "sql.yacc"
    { (yyval.sql_string)=(yyvsp[(1) - (1)].sql_string); }
    break;

  case 163:

/* Line 1455 of yacc.c  */
#line 1390 "sql.yacc"
    { (yyval.sql_string)=(yyvsp[(1) - (1)].sql_string); }
    break;

  case 164:

/* Line 1455 of yacc.c  */
#line 1398 "sql.yacc"
    {SPRINTF7((yyval.str),"%s %s %s %s %s %s %s",(yyvsp[(1) - (7)].str),(yyvsp[(2) - (7)].str),(yyvsp[(3) - (7)].str),(yyvsp[(4) - (7)].str),(yyvsp[(5) - (7)].str),(yyvsp[(6) - (7)].str),(yyvsp[(7) - (7)].str));  add_feature("GRANT"); }
    break;

  case 165:

/* Line 1455 of yacc.c  */
#line 1399 "sql.yacc"
    {SPRINTF6((yyval.str),"%s %s %s %s %s %s",(yyvsp[(1) - (6)].str),(yyvsp[(2) - (6)].str),(yyvsp[(3) - (6)].str),(yyvsp[(4) - (6)].str),(yyvsp[(5) - (6)].str),(yyvsp[(6) - (6)].str));  add_feature("REVOKE"); }
    break;

  case 166:

/* Line 1455 of yacc.c  */
#line 1400 "sql.yacc"
    {SPRINTF4((yyval.str),"%s %s %s %s ",(yyvsp[(1) - (4)].str),(yyvsp[(2) - (4)].str),(yyvsp[(3) - (4)].str),(yyvsp[(4) - (4)].str)); add_feature("GRANT"); }
    break;

  case 167:

/* Line 1455 of yacc.c  */
#line 1401 "sql.yacc"
    {SPRINTF4((yyval.str),"%s %s %s %s ",(yyvsp[(1) - (4)].str),(yyvsp[(2) - (4)].str),(yyvsp[(3) - (4)].str),(yyvsp[(4) - (4)].str));  add_feature("REVOKE"); }
    break;

  case 171:

/* Line 1455 of yacc.c  */
#line 1411 "sql.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 172:

/* Line 1455 of yacc.c  */
#line 1412 "sql.yacc"
    {SPRINTF1((yyval.str)," %s ",(yyvsp[(1) - (1)].str));}
    break;

  case 173:

/* Line 1455 of yacc.c  */
#line 1413 "sql.yacc"
    {SPRINTF2((yyval.str)," %s %s",(yyvsp[(1) - (2)].str),(yyvsp[(2) - (2)].str));}
    break;

  case 174:

/* Line 1455 of yacc.c  */
#line 1417 "sql.yacc"
    {SPRINTF1((yyval.str)," %s ",(yyvsp[(1) - (1)].str));}
    break;

  case 175:

/* Line 1455 of yacc.c  */
#line 1418 "sql.yacc"
    {SPRINTF1((yyval.str)," %s ",(yyvsp[(1) - (1)].str));}
    break;

  case 178:

/* Line 1455 of yacc.c  */
#line 1425 "sql.yacc"
    {SPRINTF3((yyval.str)," %s %s %s",(yyvsp[(1) - (3)].str),(yyvsp[(2) - (3)].str),(yyvsp[(3) - (3)].str));}
    break;

  case 179:

/* Line 1455 of yacc.c  */
#line 1428 "sql.yacc"
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
#line 1437 "sql.yacc"
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
#line 1448 "sql.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 186:

/* Line 1455 of yacc.c  */
#line 1450 "sql.yacc"
    {SPRINTF3((yyval.str)," %s %s %s",(yyvsp[(1) - (3)].str),(yyvsp[(2) - (3)].str),(yyvsp[(3) - (3)].str));}
    break;

  case 188:

/* Line 1455 of yacc.c  */
#line 1456 "sql.yacc"
    {SPRINTF3((yyval.str)," %s %s %s",(yyvsp[(1) - (3)].str),(yyvsp[(2) - (3)].str),(yyvsp[(3) - (3)].str));}
    break;

  case 190:

/* Line 1455 of yacc.c  */
#line 1462 "sql.yacc"
    {SPRINTF3((yyval.str)," %s %s %s",(yyvsp[(1) - (3)].str),(yyvsp[(2) - (3)].str),(yyvsp[(3) - (3)].str));}
    break;

  case 193:

/* Line 1455 of yacc.c  */
#line 1472 "sql.yacc"
    {
		add_feature("CREATE_VIEW_AS_SELECT");
		(yyval.sql_string)=make_sql_string_and_free(acl_strdup((yyvsp[(1) - (6)].str)),kw_space,acl_strdup((yyvsp[(2) - (6)].str)),kw_space,acl_strdup((yyvsp[(3) - (6)].str)),kw_space,acl_strdup((yyvsp[(4) - (6)].str)),kw_space,(yyvsp[(5) - (6)].sql_string),kw_space,acl_strdup((yyvsp[(6) - (6)].str)),NULL);
	
}
    break;

  case 194:

/* Line 1455 of yacc.c  */
#line 1479 "sql.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 195:

/* Line 1455 of yacc.c  */
#line 1481 "sql.yacc"
    {SPRINTF3((yyval.str)," %s %s %s",(yyvsp[(1) - (3)].str),(yyvsp[(2) - (3)].str),(yyvsp[(3) - (3)].str));}
    break;

  case 197:

/* Line 1455 of yacc.c  */
#line 1487 "sql.yacc"
    {SPRINTF3((yyval.str)," %s %s %s",(yyvsp[(1) - (3)].str),(yyvsp[(2) - (3)].str),(yyvsp[(3) - (3)].str));}
    break;

  case 198:

/* Line 1455 of yacc.c  */
#line 1490 "sql.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 199:

/* Line 1455 of yacc.c  */
#line 1491 "sql.yacc"
    {
		add_feature("CREATE_VIEW_SELECT_WITH_CHECK");
	}
    break;

  case 200:

/* Line 1455 of yacc.c  */
#line 1498 "sql.yacc"
    {
		(yyval.sql_string)=make_sql_string_and_free(strdup("CHECK ("),(yyvsp[(3) - (4)].sql_string),kw_cb,NULL);
		add_feature("DDL_CHECK");
	}
    break;

  case 201:

/* Line 1455 of yacc.c  */
#line 1507 "sql.yacc"
    {SPRINTF5((yyval.str)," %s %s %s %s %s",(yyvsp[(1) - (5)].str),(yyvsp[(2) - (5)].str),(yyvsp[(3) - (5)].str),(yyvsp[(4) - (5)].str),(yyvsp[(5) - (5)].str));
	add_feature("DDL_FOREIGN_KEY");
}
    break;

  case 202:

/* Line 1455 of yacc.c  */
#line 1514 "sql.yacc"
    {SPRINTF2((yyval.str)," %s %s",(yyvsp[(1) - (2)].str),(yyvsp[(2) - (2)].str));
add_feature("DDL_REFERENCES");
}
    break;

  case 205:

/* Line 1455 of yacc.c  */
#line 1526 "sql.yacc"
    {SPRINTF4((yyval.str)," %s %s %s %s",(yyvsp[(1) - (4)].str),(yyvsp[(2) - (4)].str),(yyvsp[(3) - (4)].str),(yyvsp[(4) - (4)].str));}
    break;

  case 207:

/* Line 1455 of yacc.c  */
#line 1532 "sql.yacc"
    {SPRINTF3((yyval.str)," %s %s %s",(yyvsp[(1) - (3)].str),(yyvsp[(2) - (3)].str),(yyvsp[(3) - (3)].str));}
    break;

  case 208:

/* Line 1455 of yacc.c  */
#line 1537 "sql.yacc"
    {
		SPRINTF3((yyval.str)," UNIQUE %s %s %s",(yyvsp[(2) - (4)].str),(yyvsp[(3) - (4)].str),(yyvsp[(4) - (4)].str));
add_feature("DDL_UNIQUE");
	}
    break;

  case 209:

/* Line 1455 of yacc.c  */
#line 1541 "sql.yacc"
    {
		ansi_violation("Use UNIQUE not DISTINCT",0);
		SPRINTF3((yyval.str)," UNIQUE %s %s %s",(yyvsp[(2) - (4)].str),(yyvsp[(3) - (4)].str),(yyvsp[(4) - (4)].str));
add_feature("DDL_DISTINCT");
	}
    break;

  case 210:

/* Line 1455 of yacc.c  */
#line 1547 "sql.yacc"
    {SPRINTF4((yyval.str)," %s %s %s %s",(yyvsp[(1) - (4)].str),(yyvsp[(2) - (4)].str),(yyvsp[(3) - (4)].str),(yyvsp[(4) - (4)].str));
add_feature("DDL_PRIMARY_KEY");
}
    break;

  case 212:

/* Line 1455 of yacc.c  */
#line 1555 "sql.yacc"
    {SPRINTF3((yyval.str)," %s %s %s",(yyvsp[(1) - (3)].str),(yyvsp[(2) - (3)].str),(yyvsp[(3) - (3)].str));}
    break;

  case 213:

/* Line 1455 of yacc.c  */
#line 1560 "sql.yacc"
    {
		(yyval.sql_string)=acl_strdup((yyvsp[(1) - (1)].str));
	}
    break;

  case 214:

/* Line 1455 of yacc.c  */
#line 1563 "sql.yacc"
    {
		(yyval.sql_string)=acl_strdup((yyvsp[(1) - (1)].str));
	}
    break;

  case 215:

/* Line 1455 of yacc.c  */
#line 1566 "sql.yacc"
    {
		(yyval.sql_string)=(yyvsp[(1) - (1)].sql_string);
	}
    break;

  case 216:

/* Line 1455 of yacc.c  */
#line 1573 "sql.yacc"
    {SPRINTF2((yyval.str)," %s %s",(yyvsp[(1) - (2)].str),(yyvsp[(2) - (2)].str)); add_feature("DDL_DEFAULT_VALUE"); }
    break;

  case 217:

/* Line 1455 of yacc.c  */
#line 1574 "sql.yacc"
    {SPRINTF1((yyval.str)," DEFAULT %s", A4GLSQLCV_get_sqlconst("USER")); add_feature("DDL_DEFAULT_VALUE"); }
    break;

  case 218:

/* Line 1455 of yacc.c  */
#line 1575 "sql.yacc"
    {SPRINTF1((yyval.str)," DEFAULT %s", A4GLSQLCV_get_sqlconst("TODAY")); add_feature("DDL_DEFAULT_VALUE"); }
    break;

  case 219:

/* Line 1455 of yacc.c  */
#line 1576 "sql.yacc"
    { SPRINTF1((yyval.str)," %s",(yyvsp[(1) - (1)].str)); add_feature("DDL_DEFAULT_VALUE"); }
    break;

  case 220:

/* Line 1455 of yacc.c  */
#line 1582 "sql.yacc"
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
#line 1603 "sql.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 223:

/* Line 1455 of yacc.c  */
#line 1607 "sql.yacc"
    {
		(yyval.sql_string)=acl_strdup("");
	}
    break;

  case 224:

/* Line 1455 of yacc.c  */
#line 1609 "sql.yacc"
    {
		(yyval.sql_string)=(yyvsp[(1) - (1)].sql_string);
	}
    break;

  case 225:

/* Line 1455 of yacc.c  */
#line 1616 "sql.yacc"
    {
		(yyval.sql_string)=(yyvsp[(1) - (1)].sql_string);
	}
    break;

  case 226:

/* Line 1455 of yacc.c  */
#line 1619 "sql.yacc"
    {
		(yyval.sql_string)=make_sql_string_and_free((yyvsp[(1) - (2)].sql_string),kw_space,(yyvsp[(2) - (2)].sql_string),NULL);
	}
    break;

  case 227:

/* Line 1455 of yacc.c  */
#line 1625 "sql.yacc"
    {
		(yyval.sql_string)=make_sql_string_and_free((yyvsp[(1) - (2)].sql_string),acl_strdup((yyvsp[(2) - (2)].str)),NULL);
	}
    break;

  case 228:

/* Line 1455 of yacc.c  */
#line 1633 "sql.yacc"
    {
		SPRINTF1((yyval.str)," %s ",(yyvsp[(1) - (1)].str));
		(yyval.sql_string)=acl_strdup((yyval.str));
		add_feature("DDL_NOT_NULL");
	}
    break;

  case 229:

/* Line 1455 of yacc.c  */
#line 1638 "sql.yacc"
    {
		SPRINTF0((yyval.str)," NOT NULL UNIQUE ");
		(yyval.sql_string)=acl_strdup((yyval.str));
		add_feature("DDL_NOT_NULL");
		add_feature("DDL_UNIQUE");
	}
    break;

  case 230:

/* Line 1455 of yacc.c  */
#line 1644 "sql.yacc"
    {
		SPRINTF0((yyval.str)," UNIQUE ");
		(yyval.sql_string)=acl_strdup((yyval.str));
		add_feature("DDL_UNIQUE");
	}
    break;

  case 231:

/* Line 1455 of yacc.c  */
#line 1649 "sql.yacc"
    {
		ansi_violation("Use UNIQUE not DISTINCT",0);
		SPRINTF0((yyval.str)," UNIQUE ");
		(yyval.sql_string)=acl_strdup((yyval.str));
		add_feature("DDL_DISTINCT");
	}
    break;

  case 232:

/* Line 1455 of yacc.c  */
#line 1655 "sql.yacc"
    {
		(yyval.sql_string)=acl_strdup((yyvsp[(1) - (1)].str));
	}
    break;

  case 233:

/* Line 1455 of yacc.c  */
#line 1658 "sql.yacc"
    {
		(yyval.sql_string)=make_sql_string_and_free(acl_strdup("CHECK ("),(yyvsp[(3) - (4)].sql_string),kw_cb,NULL);
		add_feature("DDL_CHECK");
		
	}
    break;

  case 234:

/* Line 1455 of yacc.c  */
#line 1663 "sql.yacc"
    {
		(yyval.sql_string)=make_sql_string_and_free(acl_strdup(" PRIMARY KEY "),NULL);
		add_feature("DDL_PRIMARY_KEY");
	}
    break;

  case 235:

/* Line 1455 of yacc.c  */
#line 1672 "sql.yacc"
    {
		add_feature("CREATE_SCHEMA");

(yyval.sql_string)=make_sql_string_and_free(acl_strdup((yyvsp[(1) - (3)].str)),kw_space,acl_strdup((yyvsp[(2) - (3)].str)),kw_space,acl_strdup((yyvsp[(3) - (3)].str)),NULL);
}
    break;

  case 236:

/* Line 1455 of yacc.c  */
#line 1681 "sql.yacc"
    {SPRINTF1((yyval.str)," %s",(yyvsp[(1) - (1)].str));}
    break;

  case 239:

/* Line 1455 of yacc.c  */
#line 1690 "sql.yacc"
    {
		(yyval.sql_string)=make_sql_string_and_free((yyvsp[(1) - (2)].sql_string),kw_space,(yyvsp[(2) - (2)].sql_string),NULL);
	}
    break;

  case 240:

/* Line 1455 of yacc.c  */
#line 1696 "sql.yacc"
    {
		(yyval.sql_string)=(yyvsp[(1) - (1)].sql_string);
	}
    break;

  case 241:

/* Line 1455 of yacc.c  */
#line 1699 "sql.yacc"
    {
		(yyval.sql_string)=acl_strdup((yyvsp[(1) - (1)].str));
	}
    break;

  case 242:

/* Line 1455 of yacc.c  */
#line 1710 "sql.yacc"
    {
		 add_feature("HAVING"); 
		(yyval.s_select_list_item)=(yyvsp[(2) - (2)].s_select_list_item);
	}
    break;

  case 243:

/* Line 1455 of yacc.c  */
#line 1719 "sql.yacc"
    {
		 (yyval.s_select_list_item)=(yyvsp[(2) - (2)].s_select_list_item);
	}
    break;

  case 244:

/* Line 1455 of yacc.c  */
#line 1726 "sql.yacc"
    {
		(yyval.u_table)=(yyvsp[(2) - (2)].u_table);
	}
    break;

  case 245:

/* Line 1455 of yacc.c  */
#line 1732 "sql.yacc"
    {(yyval.u_table)=(yyvsp[(1) - (1)].u_table);}
    break;

  case 246:

/* Line 1455 of yacc.c  */
#line 1733 "sql.yacc"
    {
		(yyval.u_table)=A4GLSQLPARSE_append_tablename((yyvsp[(1) - (3)].u_table),(yyvsp[(3) - (3)].u_table),E_OUTER_NONE,NULL);
	}
    break;

  case 247:

/* Line 1455 of yacc.c  */
#line 1736 "sql.yacc"
    {
		(yyval.u_table)=A4GLSQLPARSE_append_tablename((yyvsp[(1) - (4)].u_table),(yyvsp[(4) - (4)].u_table),E_OUTER_NORMAL,NULL);
		A4GL_warn("OUTER join *may* not be portable to non-informix database");
		add_feature("SELECT_OUTER");
	}
    break;

  case 248:

/* Line 1455 of yacc.c  */
#line 1741 "sql.yacc"
    {
		(yyval.u_table)=A4GLSQLPARSE_append_tablename((yyvsp[(1) - (6)].u_table),(yyvsp[(5) - (6)].u_table),E_OUTER_NORMAL,NULL);
		A4GL_warn("OUTER join *may* not be portable to non-informix database");
		add_feature("SELECT_OUTER");
	}
    break;

  case 249:

/* Line 1455 of yacc.c  */
#line 1752 "sql.yacc"
    {
		(yyval.u_table)=A4GLSQLPARSE_append_tablename((yyvsp[(1) - (5)].u_table),(yyvsp[(3) - (5)].u_table),E_OUTER_LEFT_OUTER, (yyvsp[(5) - (5)].s_select_list_item));
		add_feature("SELECT_OUTER");
	}
    break;

  case 250:

/* Line 1455 of yacc.c  */
#line 1756 "sql.yacc"
    {
		(yyval.u_table)=A4GLSQLPARSE_append_tablename((yyvsp[(1) - (5)].u_table),(yyvsp[(3) - (5)].u_table),E_INNER, (yyvsp[(5) - (5)].s_select_list_item));
		add_feature("SELECT_INNER");
	}
    break;

  case 252:

/* Line 1455 of yacc.c  */
#line 1764 "sql.yacc"
    {(yyval.u_table)=(yyvsp[(2) - (3)].u_table);}
    break;

  case 253:

/* Line 1455 of yacc.c  */
#line 1768 "sql.yacc"
    { 
			//A4GL_add_crud("SELECT",$<str>1);
			(yyval.u_table)=A4GLSQLPARSE_new_tablename((yyvsp[(1) - (1)].str),NULL);
	}
    break;

  case 254:

/* Line 1455 of yacc.c  */
#line 1772 "sql.yacc"
    { 
			//A4GL_add_crud("SELECT",$<str>1);
			(yyval.u_table)=A4GLSQLPARSE_new_tablename((yyvsp[(1) - (2)].str),(yyvsp[(2) - (2)].str));
	}
    break;

  case 255:

/* Line 1455 of yacc.c  */
#line 1776 "sql.yacc"
    { 
			//A4GL_add_crud("SELECT",$<str>1);
			(yyval.u_table)=A4GLSQLPARSE_new_tablename((yyvsp[(1) - (3)].str),(yyvsp[(3) - (3)].str));
	}
    break;

  case 256:

/* Line 1455 of yacc.c  */
#line 1783 "sql.yacc"
    {
			/* No from or where etc.. */
			/* eg.. select user ; */
			(yyval.s_select)=new_empty_select();
		}
    break;

  case 257:

/* Line 1455 of yacc.c  */
#line 1788 "sql.yacc"
    {
		(yyval.s_select)=(yyvsp[(2) - (2)].s_select);
		(yyval.s_select)->first=(yyvsp[(1) - (2)].u_table);
			A4GL_set_associated_mem( (yyval.s_select), (yyval.s_select)->first);
}
    break;

  case 258:

/* Line 1455 of yacc.c  */
#line 1796 "sql.yacc"
    {
		(yyval.s_select)=(yyvsp[(1) - (1)].s_select);
	}
    break;

  case 259:

/* Line 1455 of yacc.c  */
#line 1799 "sql.yacc"
    {
		(yyval.s_select)=(yyvsp[(2) - (2)].s_select);
		(yyval.s_select)->where_clause=(yyvsp[(1) - (2)].s_select_list_item);
	}
    break;

  case 260:

/* Line 1455 of yacc.c  */
#line 1805 "sql.yacc"
    {
		(yyval.s_select)=new_empty_select();
	}
    break;

  case 261:

/* Line 1455 of yacc.c  */
#line 1808 "sql.yacc"
    {
		(yyval.s_select)=new_empty_select();
		(yyval.s_select)->group_by=(yyvsp[(1) - (1)].s_select_list_item_list);
		(yyval.s_select)->having=0;
	}
    break;

  case 262:

/* Line 1455 of yacc.c  */
#line 1813 "sql.yacc"
    {
		(yyval.s_select)=new_empty_select();
		(yyval.s_select)->group_by=(yyvsp[(1) - (2)].s_select_list_item_list);
		(yyval.s_select)->having=(yyvsp[(2) - (2)].s_select_list_item);
	}
    break;

  case 263:

/* Line 1455 of yacc.c  */
#line 1818 "sql.yacc"
    {
		(yyval.s_select)=new_empty_select();
		(yyval.s_select)->group_by=0;
		(yyval.s_select)->having=(yyvsp[(1) - (1)].s_select_list_item);

	}
    break;

  case 264:

/* Line 1455 of yacc.c  */
#line 1831 "sql.yacc"
    {
		(yyval.s_select_list_item)=(yyvsp[(1) - (1)].s_select_list_item);
	}
    break;

  case 265:

/* Line 1455 of yacc.c  */
#line 1834 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_op_expr((yyvsp[(1) - (3)].s_select_list_item),(yyvsp[(3) - (3)].s_select_list_item)," OR ");
	}
    break;

  case 266:

/* Line 1455 of yacc.c  */
#line 1840 "sql.yacc"
    {
		(yyval.s_select_list_item)=(yyvsp[(1) - (1)].s_select_list_item);
	}
    break;

  case 267:

/* Line 1455 of yacc.c  */
#line 1843 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_op_expr((yyvsp[(1) - (3)].s_select_list_item),(yyvsp[(3) - (3)].s_select_list_item)," AND ");
	}
    break;

  case 268:

/* Line 1455 of yacc.c  */
#line 1849 "sql.yacc"
    {
		(yyval.s_select_list_item)=(yyvsp[(1) - (1)].s_select_list_item);
	}
    break;

  case 269:

/* Line 1455 of yacc.c  */
#line 1852 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_simple_expr(E_SLI_NOT,(yyvsp[(2) - (2)].s_select_list_item));
	}
    break;

  case 270:

/* Line 1455 of yacc.c  */
#line 1858 "sql.yacc"
    {
		(yyval.s_select_list_item)=(yyvsp[(1) - (1)].s_select_list_item);
	}
    break;

  case 271:

/* Line 1455 of yacc.c  */
#line 1861 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_simple_expr(E_SLI_BRACKET_EXPR,(yyvsp[(2) - (3)].s_select_list_item));
	}
    break;

  case 272:

/* Line 1455 of yacc.c  */
#line 1868 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_sq(E_SQE_EXISTS, (yyvsp[(2) - (2)].s_select_list_item));
		add_feature("WHERE_EXISTS");
	}
    break;

  case 273:

/* Line 1455 of yacc.c  */
#line 1872 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_sq(E_SQE_NOT_EXISTS, (yyvsp[(2) - (2)].s_select_list_item));
		add_feature("WHERE_EXISTS");
	}
    break;

  case 274:

/* Line 1455 of yacc.c  */
#line 1883 "sql.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 275:

/* Line 1455 of yacc.c  */
#line 1883 "sql.yacc"
    {SPRINTF1((yyval.str)," ESCAPE %s",(yyvsp[(2) - (2)].str));add_feature("WHERE_MATCHES_ESCAPE");}
    break;

  case 276:

/* Line 1455 of yacc.c  */
#line 1884 "sql.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 277:

/* Line 1455 of yacc.c  */
#line 1884 "sql.yacc"
    {SPRINTF1((yyval.str)," ESCAPE %s",(yyvsp[(2) - (2)].str));add_feature("WHERE_ILIKE_ESCAPE");}
    break;

  case 278:

/* Line 1455 of yacc.c  */
#line 1885 "sql.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 279:

/* Line 1455 of yacc.c  */
#line 1885 "sql.yacc"
    {SPRINTF1((yyval.str)," ESCAPE %s",(yyvsp[(2) - (2)].str));add_feature("WHERE_LIKE_ESCAPE");}
    break;

  case 280:

/* Line 1455 of yacc.c  */
#line 1888 "sql.yacc"
    {
		 (yyval.s_select_list_item)=(yyvsp[(1) - (1)].s_select_list_item);
	}
    break;

  case 282:

/* Line 1455 of yacc.c  */
#line 1898 "sql.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 283:

/* Line 1455 of yacc.c  */
#line 1899 "sql.yacc"
    {strcpy((yyval.str)," NOT ");}
    break;

  case 284:

/* Line 1455 of yacc.c  */
#line 1904 "sql.yacc"
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
#line 1913 "sql.yacc"
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
#line 1921 "sql.yacc"
    { 
			(yyval.s_select_list_item)=new_select_list_item_op_expr((yyvsp[(1) - (3)].s_select_list_item),(yyvsp[(3) - (3)].s_select_list_item),(yyvsp[(2) - (3)].str));
	}
    break;

  case 287:

/* Line 1455 of yacc.c  */
#line 1924 "sql.yacc"
    { 
			(yyval.s_select_list_item)=new_select_list_item_op_expr((yyvsp[(1) - (3)].s_select_list_item),(yyvsp[(3) - (3)].s_select_list_item),"=");
	}
    break;

  case 288:

/* Line 1455 of yacc.c  */
#line 1927 "sql.yacc"
    { 
			FPRINTF(stderr,"Warning: Corrected =NULL to IS NULL line %d\n",yylineno);
			(yyval.s_select_list_item)=new_select_list_item_simple_expr(E_SLI_ISNULL,(yyvsp[(1) - (3)].s_select_list_item));
	}
    break;

  case 289:

/* Line 1455 of yacc.c  */
#line 1931 "sql.yacc"
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
#line 1938 "sql.yacc"
    { 
			(yyval.s_select_list_item)=new_select_list_item_regex(E_SLI_REGEX_LIKE,(yyvsp[(1) - (4)].s_select_list_item),(yyvsp[(3) - (4)].s_select_list_item),(yyvsp[(4) - (4)].str));
	}
    break;

  case 291:

/* Line 1455 of yacc.c  */
#line 1941 "sql.yacc"
    { 
			(yyval.s_select_list_item)=new_select_list_item_regex(E_SLI_REGEX_NOT_LIKE,(yyvsp[(1) - (4)].s_select_list_item),(yyvsp[(3) - (4)].s_select_list_item),(yyvsp[(4) - (4)].str));

	}
    break;

  case 292:

/* Line 1455 of yacc.c  */
#line 1945 "sql.yacc"
    { 
			(yyval.s_select_list_item)=new_select_list_item_regex(E_SLI_REGEX_ILIKE,(yyvsp[(1) - (4)].s_select_list_item),(yyvsp[(3) - (4)].s_select_list_item),(yyvsp[(4) - (4)].str));
	}
    break;

  case 293:

/* Line 1455 of yacc.c  */
#line 1948 "sql.yacc"
    { 
			(yyval.s_select_list_item)=new_select_list_item_regex(E_SLI_REGEX_NOT_ILIKE,(yyvsp[(1) - (4)].s_select_list_item),(yyvsp[(3) - (4)].s_select_list_item),(yyvsp[(4) - (4)].str));
	}
    break;

  case 294:

/* Line 1455 of yacc.c  */
#line 1951 "sql.yacc"
    { 
			(yyval.s_select_list_item)=new_select_list_item_regex(E_SLI_REGEX_MATCHES,(yyvsp[(1) - (4)].s_select_list_item),(yyvsp[(3) - (4)].s_select_list_item),(yyvsp[(4) - (4)].str));
	}
    break;

  case 295:

/* Line 1455 of yacc.c  */
#line 1954 "sql.yacc"
    { 
			(yyval.s_select_list_item)=new_select_list_item_regex(E_SLI_REGEX_NOT_MATCHES,(yyvsp[(1) - (4)].s_select_list_item),(yyvsp[(3) - (4)].s_select_list_item),(yyvsp[(4) - (4)].str));
	}
    break;

  case 296:

/* Line 1455 of yacc.c  */
#line 1960 "sql.yacc"
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
#line 1967 "sql.yacc"
    {
			strcpy((yyval.str)," < ");
	}
    break;

  case 298:

/* Line 1455 of yacc.c  */
#line 1970 "sql.yacc"
    {
			strcpy((yyval.str)," > ");
	}
    break;

  case 299:

/* Line 1455 of yacc.c  */
#line 1973 "sql.yacc"
    {
			strcpy((yyval.str)," ~ ");
	}
    break;

  case 300:

/* Line 1455 of yacc.c  */
#line 1976 "sql.yacc"
    {strcpy((yyval.str)," <= ");}
    break;

  case 301:

/* Line 1455 of yacc.c  */
#line 1977 "sql.yacc"
    {strcpy((yyval.str)," >= ");}
    break;

  case 302:

/* Line 1455 of yacc.c  */
#line 1982 "sql.yacc"
    {
		(yyval.s_select_list_item)=(yyvsp[(1) - (1)].s_select_list_item);
	}
    break;

  case 303:

/* Line 1455 of yacc.c  */
#line 1985 "sql.yacc"
    {
		(yyval.s_select_list_item)=(yyvsp[(1) - (1)].s_select_list_item);
	}
    break;

  case 304:

/* Line 1455 of yacc.c  */
#line 1988 "sql.yacc"
    {
		(yyval.s_select_list_item)=(yyvsp[(1) - (1)].s_select_list_item);
	}
    break;

  case 305:

/* Line 1455 of yacc.c  */
#line 1991 "sql.yacc"
    {
                 (yyval.s_select_list_item)=(yyvsp[(1) - (1)].s_select_list_item);
        }
    break;

  case 306:

/* Line 1455 of yacc.c  */
#line 1998 "sql.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 307:

/* Line 1455 of yacc.c  */
#line 1999 "sql.yacc"
    {strcpy((yyval.str)," ALL "); add_feature("AGG_ALL");}
    break;

  case 308:

/* Line 1455 of yacc.c  */
#line 2000 "sql.yacc"
    {
		strcpy((yyval.str)," DISTINCT ");
		add_feature("AGG_DISTINCT");
	}
    break;

  case 309:

/* Line 1455 of yacc.c  */
#line 2004 "sql.yacc"
    {
		ansi_violation("Use DISTINCT not UNIQUE",0);
		strcpy((yyval.str)," DISTINCT ");
		add_feature("AGG_DISTINCT");
	}
    break;

  case 310:

/* Line 1455 of yacc.c  */
#line 2011 "sql.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 311:

/* Line 1455 of yacc.c  */
#line 2012 "sql.yacc"
    {strcpy((yyval.str)," ALL "); add_feature("UNION_ALL");}
    break;

  case 312:

/* Line 1455 of yacc.c  */
#line 2013 "sql.yacc"
    {
		strcpy((yyval.str)," DISTINCT ");
		add_feature("UNION_DISTINCT");
	}
    break;

  case 313:

/* Line 1455 of yacc.c  */
#line 2017 "sql.yacc"
    {
		ansi_violation("Use DISTINCT not UNIQUE",0);
		add_feature("UNION_DISTINCT");
		strcpy((yyval.str)," DISTINCT ");
	}
    break;

  case 314:

/* Line 1455 of yacc.c  */
#line 2031 "sql.yacc"
    {
		strcpy((yyval.str),A4GLSQLCV_dtype_alias((yyvsp[(1) - (1)].str)));
	}
    break;

  case 319:

/* Line 1455 of yacc.c  */
#line 2046 "sql.yacc"
    {SPRINTF4((yyval.str)," %s %s%s%s",(yyvsp[(1) - (4)].str),(yyvsp[(2) - (4)].str),(yyvsp[(3) - (4)].str),(yyvsp[(4) - (4)].str));}
    break;

  case 320:

/* Line 1455 of yacc.c  */
#line 2050 "sql.yacc"
    {strcpy((yyval.str),"SERIAL"); add_feature("DDL_SERIAL"); }
    break;

  case 321:

/* Line 1455 of yacc.c  */
#line 2051 "sql.yacc"
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
#line 2060 "sql.yacc"
    {strcpy((yyval.str),"SERIAL8"); add_feature("DDL_SERIAL8"); }
    break;

  case 323:

/* Line 1455 of yacc.c  */
#line 2062 "sql.yacc"
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
#line 2071 "sql.yacc"
    {
 			add_feature("DDL_DECIMAL");
	}
    break;

  case 325:

/* Line 1455 of yacc.c  */
#line 2074 "sql.yacc"
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
#line 2082 "sql.yacc"
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
#line 2092 "sql.yacc"
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
#line 2100 "sql.yacc"
    {strcpy((yyval.str),"DATE");
 			add_feature("DDL_DATE"); }
    break;

  case 329:

/* Line 1455 of yacc.c  */
#line 2102 "sql.yacc"
    {strcpy((yyval.str),"INTEGER");}
    break;

  case 330:

/* Line 1455 of yacc.c  */
#line 2103 "sql.yacc"
    {strcpy((yyval.str),"SMALLINT");}
    break;

  case 331:

/* Line 1455 of yacc.c  */
#line 2104 "sql.yacc"
    {strcpy((yyval.str),"NCHAR"); add_feature("DDL_NCHAR");}
    break;

  case 332:

/* Line 1455 of yacc.c  */
#line 2105 "sql.yacc"
    {SPRINTF1((yyval.str),"NCHAR(%s)",(yyvsp[(3) - (4)].str)); add_feature("DDL_NCHAR");}
    break;

  case 333:

/* Line 1455 of yacc.c  */
#line 2106 "sql.yacc"
    {add_feature("DDL_NVARCHAR");}
    break;

  case 334:

/* Line 1455 of yacc.c  */
#line 2107 "sql.yacc"
    {SPRINTF1((yyval.str),"NVARCHAR(%s)",(yyvsp[(3) - (4)].str)); add_feature("DDL_NVARCHAR");}
    break;

  case 335:

/* Line 1455 of yacc.c  */
#line 2108 "sql.yacc"
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
#line 2116 "sql.yacc"
    {SPRINTF2((yyval.str),"DATETIME %s TO %s",(yyvsp[(2) - (4)].str),(yyvsp[(4) - (4)].str)); add_feature("DDL_DATETIME");}
    break;

  case 337:

/* Line 1455 of yacc.c  */
#line 2117 "sql.yacc"
    {add_feature("DDL_DATETIME");}
    break;

  case 338:

/* Line 1455 of yacc.c  */
#line 2118 "sql.yacc"
    {SPRINTF2((yyval.str),"INTERVAL %s TO %s",(yyvsp[(2) - (4)].str),(yyvsp[(4) - (4)].str)); add_feature("DDL_INTERVAL");}
    break;

  case 339:

/* Line 1455 of yacc.c  */
#line 2119 "sql.yacc"
    {strcpy((yyval.str),(yyvsp[(1) - (1)].str));}
    break;

  case 340:

/* Line 1455 of yacc.c  */
#line 2120 "sql.yacc"
    {add_feature("DDL_INTERVAL");}
    break;

  case 341:

/* Line 1455 of yacc.c  */
#line 2121 "sql.yacc"
    {SPRINTF3((yyval.str),"INTERVAL %s(%s) TO %s",(yyvsp[(2) - (7)].str),(yyvsp[(4) - (7)].str),(yyvsp[(7) - (7)].str)); add_feature("DDL_INTERVAL");}
    break;

  case 342:

/* Line 1455 of yacc.c  */
#line 2122 "sql.yacc"
    {add_feature("DDL_TEXT");}
    break;

  case 343:

/* Line 1455 of yacc.c  */
#line 2123 "sql.yacc"
    {add_feature("DDL_BYTE");}
    break;

  case 344:

/* Line 1455 of yacc.c  */
#line 2124 "sql.yacc"
    {add_feature("DDL_VARCHAR");}
    break;

  case 345:

/* Line 1455 of yacc.c  */
#line 2125 "sql.yacc"
    {SPRINTF1((yyval.str),"VARCHAR(%s)",(yyvsp[(3) - (4)].str));add_feature("DDL_VARCHAR");}
    break;

  case 346:

/* Line 1455 of yacc.c  */
#line 2126 "sql.yacc"
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
#line 2136 "sql.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 348:

/* Line 1455 of yacc.c  */
#line 2137 "sql.yacc"
    {
		SPRINTF1((yyval.str),",%s",(yyvsp[(2) - (2)].str));
}
    break;

  case 349:

/* Line 1455 of yacc.c  */
#line 2144 "sql.yacc"
    {SPRINTF4((yyval.str)," %s %s %s %s",(yyvsp[(1) - (4)].str),(yyvsp[(2) - (4)].str),(yyvsp[(3) - (4)].str),(yyvsp[(4) - (4)].str));}
    break;

  case 353:

/* Line 1455 of yacc.c  */
#line 2148 "sql.yacc"
    {add_feature("DDL_DOUBLE_PRECISION"); SPRINTF1((yyval.str)," %s",(yyvsp[(1) - (1)].str));}
    break;

  case 359:

/* Line 1455 of yacc.c  */
#line 2173 "sql.yacc"
    {(yyval.int_list.i0)=0;}
    break;

  case 360:

/* Line 1455 of yacc.c  */
#line 2174 "sql.yacc"
    {
		(yyval.int_list.i0)=1;
		(yyval.int_list.i1)=atoi((yyvsp[(2) - (3)].str));
	}
    break;

  case 361:

/* Line 1455 of yacc.c  */
#line 2178 "sql.yacc"
    {
		(yyval.int_list.i0)=2;
		(yyval.int_list.i1)=atoi((yyvsp[(2) - (5)].str));
		(yyval.int_list.i2)=atoi((yyvsp[(4) - (5)].str));
	}
    break;

  case 362:

/* Line 1455 of yacc.c  */
#line 2186 "sql.yacc"
    {
		strcpy((yyval.str),(yyvsp[(1) - (1)].str));
	}
    break;

  case 363:

/* Line 1455 of yacc.c  */
#line 2189 "sql.yacc"
    {
		strcpy((yyval.str),(yyvsp[(2) - (2)].str));
	}
    break;

  case 364:

/* Line 1455 of yacc.c  */
#line 2196 "sql.yacc"
    {
		(yyval.s_select_list_item)= (yyvsp[(1) - (1)].s_select_list_item);
	}
    break;

  case 365:

/* Line 1455 of yacc.c  */
#line 2199 "sql.yacc"
    {
		(yyval.s_select_list_item)= (yyvsp[(2) - (2)].s_select_list_item);
	}
    break;

  case 366:

/* Line 1455 of yacc.c  */
#line 2209 "sql.yacc"
    { 
		(yyval.s_select_list_item)=new_select_list_item_col(0,(yyvsp[(1) - (2)].str),&(yyvsp[(2) - (2)].int_list));
	}
    break;

  case 367:

/* Line 1455 of yacc.c  */
#line 2212 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_col((yyvsp[(1) - (4)].str),(yyvsp[(3) - (4)].str),&(yyvsp[(4) - (4)].int_list));
	}
    break;

  case 368:

/* Line 1455 of yacc.c  */
#line 2215 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_col((yyvsp[(1) - (3)].str),"*",0);
	}
    break;

  case 369:

/* Line 1455 of yacc.c  */
#line 2218 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_col(0,"rowid",0);
	}
    break;

  case 370:

/* Line 1455 of yacc.c  */
#line 2225 "sql.yacc"
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
#line 2232 "sql.yacc"
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
#line 2240 "sql.yacc"
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
#line 2249 "sql.yacc"
    {
		SPRINTF1((yyval.str),"%s",A4GLSQLCV_check_colname((yyvsp[(1) - (3)].str),"*"));
		ADDMAP("Use Column",(yyval.str));
	}
    break;

  case 375:

/* Line 1455 of yacc.c  */
#line 2260 "sql.yacc"
    { strcpy((yyval.str),(yyvsp[(1) - (1)].str)); A4GL_debug("Set $<str>$ to %s\n",(yyval.str)); }
    break;

  case 379:

/* Line 1455 of yacc.c  */
#line 2268 "sql.yacc"
    { strcpy((yyval.str),A4GLSQLCV_generate_current(0,0)); 
}
    break;

  case 380:

/* Line 1455 of yacc.c  */
#line 2270 "sql.yacc"
    {
		strcpy((yyval.str),A4GLSQLCV_generate_current((yyvsp[(1) - (3)].str),(yyvsp[(3) - (3)].str)));
	}
    break;

  case 395:

/* Line 1455 of yacc.c  */
#line 2280 "sql.yacc"
    {SPRINTF1((yyval.str),"FRACTION(%s)",(yyvsp[(3) - (4)].str));}
    break;

  case 396:

/* Line 1455 of yacc.c  */
#line 2295 "sql.yacc"
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
#line 2303 "sql.yacc"
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
#line 2315 "sql.yacc"
    { (yyval.sql_string)=make_sql_string_and_free(acl_strdup((yyvsp[(1) - (1)].str)), NULL);}
    break;

  case 399:

/* Line 1455 of yacc.c  */
#line 2316 "sql.yacc"
    { (yyval.sql_string)=make_sql_string_and_free(acl_strdup((yyvsp[(1) - (1)].str)), NULL);}
    break;

  case 400:

/* Line 1455 of yacc.c  */
#line 2317 "sql.yacc"
    { (yyval.sql_string)=make_sql_string_and_free(acl_strdup((yyvsp[(1) - (1)].str)), NULL);}
    break;

  case 401:

/* Line 1455 of yacc.c  */
#line 2318 "sql.yacc"
    { (yyval.sql_string)=make_sql_string_and_free(acl_strdup((yyvsp[(1) - (1)].str)), NULL);}
    break;

  case 402:

/* Line 1455 of yacc.c  */
#line 2323 "sql.yacc"
    { add_feature("RENAME_TABLE"); strcpy((yyval.str),A4GLSQLCV_rentab((yyvsp[(2) - (4)].str),(yyvsp[(4) - (4)].str))); }
    break;

  case 403:

/* Line 1455 of yacc.c  */
#line 2324 "sql.yacc"
    { add_feature("RENAME_COLUMN"); strcpy((yyval.str),A4GLSQLCV_rencol((yyvsp[(2) - (6)].str),(yyvsp[(4) - (6)].str),(yyvsp[(6) - (6)].str)) ); }
    break;

  case 406:

/* Line 1455 of yacc.c  */
#line 2332 "sql.yacc"
    {
		add_feature("UNLOCK_TABLE");
		SPRINTF2((yyval.str),"%s %s",(yyvsp[(1) - (2)].str),(yyvsp[(2) - (2)].str));
	}
    break;

  case 407:

/* Line 1455 of yacc.c  */
#line 2339 "sql.yacc"
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
#line 2350 "sql.yacc"
    { add_feature("LOCK_TABLE_SHARED");}
    break;

  case 409:

/* Line 1455 of yacc.c  */
#line 2351 "sql.yacc"
    {add_feature("LOCK_TABLE_EXCLUSIVE");}
    break;

  case 410:

/* Line 1455 of yacc.c  */
#line 2364 "sql.yacc"
    {strcpy((yyval.str),A4GLSQLCV_datetime_value((yyvsp[(1) - (1)].str)));}
    break;

  case 411:

/* Line 1455 of yacc.c  */
#line 2365 "sql.yacc"
    {strcpy((yyval.str),A4GLSQLCV_make_dtime_extend((yyvsp[(1) - (4)].str),(yyvsp[(2) - (4)].str),(yyvsp[(4) - (4)].str),0));}
    break;

  case 412:

/* Line 1455 of yacc.c  */
#line 2369 "sql.yacc"
    {strcpy((yyval.str),(yyvsp[(1) - (1)].str));}
    break;

  case 413:

/* Line 1455 of yacc.c  */
#line 2373 "sql.yacc"
    {strcpy((yyval.str),A4GLSQLCV_interval_value((yyvsp[(1) - (1)].str)));}
    break;

  case 414:

/* Line 1455 of yacc.c  */
#line 2374 "sql.yacc"
    {
			strcpy((yyval.str),A4GLSQLCV_make_ival_extend((yyvsp[(1) - (7)].str),(yyvsp[(2) - (7)].str),(yyvsp[(4) - (7)].str),(yyvsp[(7) - (7)].str),0));
		}
    break;

  case 415:

/* Line 1455 of yacc.c  */
#line 2377 "sql.yacc"
    {
		strcpy((yyval.str),A4GLSQLCV_make_ival_extend((yyvsp[(1) - (4)].str),(yyvsp[(2) - (4)].str),(char *)0, (yyvsp[(4) - (4)].str),0));
	}
    break;

  case 416:

/* Line 1455 of yacc.c  */
#line 2383 "sql.yacc"
    {SPRINTF1((yyval.str),"%s",(yyvsp[(1) - (1)].str));}
    break;

  case 417:

/* Line 1455 of yacc.c  */
#line 2387 "sql.yacc"
    {
	strcpy((yyval.str),(yyvsp[(2) - (2)].str));
}
    break;

  case 418:

/* Line 1455 of yacc.c  */
#line 2410 "sql.yacc"
    {
		(yyval.s_select_list_item_list)=(yyvsp[(3) - (3)].s_select_list_item_list);
		add_feature("ORDER_BY");
	}
    break;

  case 419:

/* Line 1455 of yacc.c  */
#line 2420 "sql.yacc"
    {
			(yyval.s_select_list_item_list)=local_new_select_list_item_list((yyvsp[(1) - (1)].s_select_list_item));
	}
    break;

  case 420:

/* Line 1455 of yacc.c  */
#line 2423 "sql.yacc"
    {
			(yyval.s_select_list_item_list)=local_add_select_list_item_list((yyvsp[(1) - (3)].s_select_list_item_list),(yyvsp[(3) - (3)].s_select_list_item));
	}
    break;

  case 421:

/* Line 1455 of yacc.c  */
#line 2429 "sql.yacc"
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
#line 2438 "sql.yacc"
    { 
		add_feature("ORDER_BY_NUMBER");
		(yyval.s_select_list_item)=new_select_list_item_literal((yyvsp[(1) - (1)].str));
	}
    break;

  case 423:

/* Line 1455 of yacc.c  */
#line 2442 "sql.yacc"
    {
		(yyval.s_select_list_item)=(yyvsp[(1) - (1)].s_select_list_item);
		(yyval.s_select_list_item)->data.type=E_SLI_COLUMN_ORDERBY;
	}
    break;

  case 424:

/* Line 1455 of yacc.c  */
#line 2449 "sql.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 425:

/* Line 1455 of yacc.c  */
#line 2451 "sql.yacc"
    {add_feature("ORDER_BY_ASC"); strcpy((yyval.str),"ASC");}
    break;

  case 426:

/* Line 1455 of yacc.c  */
#line 2453 "sql.yacc"
    {add_feature("ORDER_BY_DESC"); strcpy((yyval.str),"DESC");}
    break;

  case 427:

/* Line 1455 of yacc.c  */
#line 2457 "sql.yacc"
    {
		(yyval.s_select_list_item_list)=(yyvsp[(2) - (2)].s_select_list_item_list);
	}
    break;

  case 428:

/* Line 1455 of yacc.c  */
#line 2463 "sql.yacc"
    {
			(yyval.s_select_list_item_list)=local_new_select_list_item_list((yyvsp[(1) - (1)].s_select_list_item));
	}
    break;

  case 429:

/* Line 1455 of yacc.c  */
#line 2466 "sql.yacc"
    {
			(yyval.s_select_list_item_list)=local_add_select_list_item_list((yyvsp[(1) - (3)].s_select_list_item_list),(yyvsp[(3) - (3)].s_select_list_item));
	}
    break;

  case 430:

/* Line 1455 of yacc.c  */
#line 2472 "sql.yacc"
    { (yyval.s_select_list_item)=(yyvsp[(1) - (1)].s_select_list_item); }
    break;

  case 431:

/* Line 1455 of yacc.c  */
#line 2473 "sql.yacc"
    { (yyval.s_select_list_item)=new_select_list_item_literal((yyvsp[(1) - (1)].str)); }
    break;

  case 432:

/* Line 1455 of yacc.c  */
#line 2480 "sql.yacc"
    {
	(yyval.sql_string)=get_select_list_item(0,(yyvsp[(1) - (1)].s_select_list_item));
}
    break;

  case 433:

/* Line 1455 of yacc.c  */
#line 2493 "sql.yacc"
    {
		A4GL_set_sql_lineno(yylineno);
		(yyval.sql_string)=make_select_stmt_v2(current_upd_table, (yyvsp[(1) - (1)].s_select),"");
		map_select_stmt("SELECT",(yyvsp[(1) - (1)].s_select));
		A4GL_free_select_stmt((yyvsp[(1) - (1)].s_select));
}
    break;

  case 434:

/* Line 1455 of yacc.c  */
#line 2503 "sql.yacc"
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
#line 2510 "sql.yacc"
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
#line 2527 "sql.yacc"
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
#line 2534 "sql.yacc"
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
#line 2559 "sql.yacc"
    { 
		//start_bind('i',0);
		 set_ignore_indicators();}
    break;

  case 439:

/* Line 1455 of yacc.c  */
#line 2561 "sql.yacc"
    { clr_ignore_indicators();}
    break;

  case 440:

/* Line 1455 of yacc.c  */
#line 2563 "sql.yacc"
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
#line 2584 "sql.yacc"
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
#line 2627 "sql.yacc"
    { (yyval.s_select)=0;}
    break;

  case 443:

/* Line 1455 of yacc.c  */
#line 2628 "sql.yacc"
    { 
		(yyval.s_select)=(yyvsp[(3) - (3)].s_select);
		(yyval.s_select)->union_op=acl_strdup((yyvsp[(2) - (3)].str));
		A4GL_set_associated_mem((yyval.s_select), (yyval.s_select)->union_op);
		add_feature("SELECT_UNION"); 
	}
    break;

  case 444:

/* Line 1455 of yacc.c  */
#line 2642 "sql.yacc"
    {
		(yyval.s_select_finish)=0;
	}
    break;

  case 445:

/* Line 1455 of yacc.c  */
#line 2645 "sql.yacc"
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
#line 2652 "sql.yacc"
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
#line 2662 "sql.yacc"
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
#line 2680 "sql.yacc"
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
#line 2693 "sql.yacc"
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
#line 2708 "sql.yacc"
    {(yyval.integer_val)=-1;}
    break;

  case 452:

/* Line 1455 of yacc.c  */
#line 2710 "sql.yacc"
    {
		(yyval.integer_val)=atol((yyvsp[(2) - (2)].str));
	}
    break;

  case 453:

/* Line 1455 of yacc.c  */
#line 2716 "sql.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 454:

/* Line 1455 of yacc.c  */
#line 2717 "sql.yacc"
    {strcpy((yyval.str),"ALL"); add_feature("SELECT_ALL");}
    break;

  case 455:

/* Line 1455 of yacc.c  */
#line 2718 "sql.yacc"
    {strcpy((yyval.str),"DISTINCT"); add_feature("SELECT_DISTINCT");}
    break;

  case 456:

/* Line 1455 of yacc.c  */
#line 2719 "sql.yacc"
    {strcpy((yyval.str),"DISTINCT");
		add_feature("SELECT_UNIQUE");
		ansi_violation("Use DISTINCT not UNIQUE",0);
		strcpy((yyval.str),"DISTINCT");
	}
    break;

  case 457:

/* Line 1455 of yacc.c  */
#line 2729 "sql.yacc"
    { 
		 (yyval.s_select_list_item_list)=local_new_select_list_item_list((yyvsp[(1) - (1)].s_select_list_item));
	}
    break;

  case 458:

/* Line 1455 of yacc.c  */
#line 2732 "sql.yacc"
    { 
		(yyval.s_select_list_item_list)=local_add_select_list_item_list((yyvsp[(1) - (3)].s_select_list_item_list),(yyvsp[(3) - (3)].s_select_list_item));
	}
    break;

  case 459:

/* Line 1455 of yacc.c  */
#line 2738 "sql.yacc"
    {
		(yyval.s_select_list_item)=(yyvsp[(1) - (1)].s_select_list_item);
	}
    break;

  case 460:

/* Line 1455 of yacc.c  */
#line 2741 "sql.yacc"
    {
		(yyval.s_select_list_item)=(yyvsp[(1) - (2)].s_select_list_item);
		(yyval.s_select_list_item)->alias=acl_strdup((yyvsp[(2) - (2)].str));
		A4GL_set_associated_mem((yyval.s_select_list_item), (yyval.s_select_list_item)->alias);
	}
    break;

  case 461:

/* Line 1455 of yacc.c  */
#line 2746 "sql.yacc"
    {
		(yyval.s_select_list_item)=(yyvsp[(1) - (3)].s_select_list_item);
		(yyval.s_select_list_item)->alias=acl_strdup((yyvsp[(3) - (3)].str));
		A4GL_set_associated_mem((yyval.s_select_list_item), (yyval.s_select_list_item)->alias);
	}
    break;

  case 462:

/* Line 1455 of yacc.c  */
#line 2755 "sql.yacc"
    {
		(yyval.s_select_list_item)=(yyvsp[(1) - (1)].s_select_list_item); /* A4GLSQLCV_check_expr($<sql_string>1) */
	}
    break;

  case 463:

/* Line 1455 of yacc.c  */
#line 2758 "sql.yacc"
    {
		(yyval.s_select_list_item)=(yyvsp[(2) - (2)].s_select_list_item);
		(yyval.s_select_list_item)->sign='-';
	}
    break;

  case 464:

/* Line 1455 of yacc.c  */
#line 2762 "sql.yacc"
    {
		(yyval.s_select_list_item)=(yyvsp[(2) - (2)].s_select_list_item);
	}
    break;

  case 465:

/* Line 1455 of yacc.c  */
#line 2769 "sql.yacc"
    {
			(yyval.s_select_list_item)=new_select_list_item_op_expr ((yyvsp[(1) - (3)].s_select_list_item), (yyvsp[(3) - (3)].s_select_list_item), "/");
	}
    break;

  case 466:

/* Line 1455 of yacc.c  */
#line 2772 "sql.yacc"
    {
			(yyval.s_select_list_item)=new_select_list_item_simple_expr((enum e_sli)(yyvsp[(2) - (2)].integer_val), (yyvsp[(1) - (2)].s_select_list_item));
	}
    break;

  case 467:

/* Line 1455 of yacc.c  */
#line 2775 "sql.yacc"
    {
			(yyval.s_select_list_item)=new_select_list_item_op_expr ((yyvsp[(1) - (3)].s_select_list_item), (yyvsp[(3) - (3)].s_select_list_item), "*");
	}
    break;

  case 468:

/* Line 1455 of yacc.c  */
#line 2778 "sql.yacc"
    {
			(yyval.s_select_list_item)=new_select_list_item_op_expr ((yyvsp[(1) - (3)].s_select_list_item), (yyvsp[(3) - (3)].s_select_list_item), "+");
	}
    break;

  case 469:

/* Line 1455 of yacc.c  */
#line 2781 "sql.yacc"
    {
			(yyval.s_select_list_item)=new_select_list_item_op_expr ((yyvsp[(1) - (3)].s_select_list_item), (yyvsp[(3) - (3)].s_select_list_item), "-");
	}
    break;

  case 470:

/* Line 1455 of yacc.c  */
#line 2784 "sql.yacc"
    { (yyval.s_select_list_item)=new_select_list_item_literal((yyvsp[(1) - (1)].str)); }
    break;

  case 471:

/* Line 1455 of yacc.c  */
#line 2785 "sql.yacc"
    { (yyval.s_select_list_item)=new_select_list_item_builtin_const(E_SLI_BUILTIN_CONST_TRUE); }
    break;

  case 472:

/* Line 1455 of yacc.c  */
#line 2786 "sql.yacc"
    { (yyval.s_select_list_item)=new_select_list_item_builtin_const(E_SLI_BUILTIN_CONST_FALSE); }
    break;

  case 473:

/* Line 1455 of yacc.c  */
#line 2787 "sql.yacc"
    { (yyval.s_select_list_item)=new_select_list_item_builtin_const(E_SLI_BUILTIN_CONST_USER); }
    break;

  case 474:

/* Line 1455 of yacc.c  */
#line 2788 "sql.yacc"
    { (yyval.s_select_list_item)=new_select_list_item_builtin_const(E_SLI_BUILTIN_CONST_TODAY); }
    break;

  case 475:

/* Line 1455 of yacc.c  */
#line 2789 "sql.yacc"
    { (yyval.s_select_list_item)=new_select_list_item_builtin_const(E_SLI_BUILTIN_CONST_ROWID); }
    break;

  case 476:

/* Line 1455 of yacc.c  */
#line 2790 "sql.yacc"
    { (yyval.s_select_list_item)=new_select_list_item_builtin_const(E_SLI_BUILTIN_CONST_TIME); }
    break;

  case 477:

/* Line 1455 of yacc.c  */
#line 2791 "sql.yacc"
    { (yyval.s_select_list_item)=new_select_list_item_builtin_const(E_SLI_BUILTIN_CONST_STAR); }
    break;

  case 478:

/* Line 1455 of yacc.c  */
#line 2792 "sql.yacc"
    { (yyval.s_select_list_item)=new_select_list_item_builtin_const(E_SLI_BUILTIN_CONST_COUNT_STAR); }
    break;

  case 479:

/* Line 1455 of yacc.c  */
#line 2794 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_agg1(E_SLI_BUILTIN_AGG_AVG,(yyvsp[(3) - (5)].str),(yyvsp[(4) - (5)].s_select_list_item));
		add_feature("SELECT_AVG");
	}
    break;

  case 480:

/* Line 1455 of yacc.c  */
#line 2798 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_agg1(E_SLI_BUILTIN_AGG_MAX,(yyvsp[(3) - (5)].str),(yyvsp[(4) - (5)].s_select_list_item));
		add_feature("SELECT_MAX");
	}
    break;

  case 481:

/* Line 1455 of yacc.c  */
#line 2802 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_agg1(E_SLI_BUILTIN_AGG_MIN,(yyvsp[(3) - (5)].str),(yyvsp[(4) - (5)].s_select_list_item));
		add_feature("SELECT_MIN");
	}
    break;

  case 482:

/* Line 1455 of yacc.c  */
#line 2806 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_agg1(E_SLI_BUILTIN_AGG_SUM,(yyvsp[(3) - (5)].str),(yyvsp[(4) - (5)].s_select_list_item));
		add_feature("SELECT_SUM");
	}
    break;

  case 483:

/* Line 1455 of yacc.c  */
#line 2810 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_agg1(E_SLI_BUILTIN_AGG_COUNT,(yyvsp[(3) - (5)].str),(yyvsp[(4) - (5)].s_select_list_item));
		add_feature("SELECT_COUNT");
	}
    break;

  case 484:

/* Line 1455 of yacc.c  */
#line 2814 "sql.yacc"
    {
		add_sql_function((yyvsp[(1) - (3)].str));
		(yyval.s_select_list_item)=new_select_list_item_fcall((yyvsp[(1) - (3)].str),0);
	}
    break;

  case 485:

/* Line 1455 of yacc.c  */
#line 2818 "sql.yacc"
    {
		add_sql_function((yyvsp[(1) - (4)].str));
		(yyval.s_select_list_item)=new_select_list_item_fcall((yyvsp[(1) - (4)].str),(yyvsp[(3) - (4)].s_select_list_item_list));
	}
    break;

  case 486:

/* Line 1455 of yacc.c  */
#line 2822 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_builtin_fcall(E_SLI_BUILTIN_FUNC_YEAR,(yyvsp[(3) - (4)].s_select_list_item_list));
	}
    break;

  case 487:

/* Line 1455 of yacc.c  */
#line 2825 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_builtin_fcall(E_SLI_BUILTIN_FUNC_MONTH,(yyvsp[(3) - (4)].s_select_list_item_list));
	}
    break;

  case 488:

/* Line 1455 of yacc.c  */
#line 2828 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_builtin_fcall(E_SLI_BUILTIN_FUNC_DAY,(yyvsp[(3) - (4)].s_select_list_item_list));
	}
    break;

  case 489:

/* Line 1455 of yacc.c  */
#line 2831 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_builtin_fcall(E_SLI_BUILTIN_FUNC_MDY,(yyvsp[(3) - (4)].s_select_list_item_list));
	}
    break;

  case 490:

/* Line 1455 of yacc.c  */
#line 2834 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_builtin_fcall(E_SLI_BUILTIN_FUNC_WEEKDAY,(yyvsp[(3) - (4)].s_select_list_item_list));
	}
    break;

  case 491:

/* Line 1455 of yacc.c  */
#line 2837 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_builtin_fcall(E_SLI_BUILTIN_FUNC_DOW,(yyvsp[(3) - (4)].s_select_list_item_list));
	}
    break;

  case 492:

/* Line 1455 of yacc.c  */
#line 2840 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_builtin_fcall(E_SLI_BUILTIN_FUNC_DATE,(yyvsp[(3) - (4)].s_select_list_item_list));
	}
    break;

  case 493:

/* Line 1455 of yacc.c  */
#line 2843 "sql.yacc"
    {
		  (yyval.s_select_list_item)=new_select_list_item_simple_expr(E_SLI_BRACKET_EXPR,(yyvsp[(2) - (3)].s_select_list_item));
	}
    break;

  case 494:

/* Line 1455 of yacc.c  */
#line 2846 "sql.yacc"
    { 
		add_feature("EXTEND"); 
		(yyval.s_select_list_item)=(yyvsp[(3) - (4)].s_select_list_item);
	}
    break;

  case 495:

/* Line 1455 of yacc.c  */
#line 2850 "sql.yacc"
    { 
		(yyval.s_select_list_item)=new_select_list_item_datetime((yyvsp[(1) - (1)].str));
		add_feature("FUNC_DATETIME");
	}
    break;

  case 496:

/* Line 1455 of yacc.c  */
#line 2854 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_interval((yyvsp[(1) - (1)].str));
		add_feature("FUNC_INTERVAL");
	}
    break;

  case 497:

/* Line 1455 of yacc.c  */
#line 2858 "sql.yacc"
    {
		(yyval.s_select_list_item)=(yyvsp[(2) - (3)].s_select_list_item);
	}
    break;

  case 498:

/* Line 1455 of yacc.c  */
#line 2866 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_case((yyvsp[(1) - (1)].s_select_list_item));
	}
    break;

  case 499:

/* Line 1455 of yacc.c  */
#line 2869 "sql.yacc"
    {
		(yyval.s_select_list_item)=append_select_list_item_case(
							(yyvsp[(1) - (2)].s_select_list_item),
							(yyvsp[(2) - (2)].s_select_list_item));
	}
    break;

  case 500:

/* Line 1455 of yacc.c  */
#line 2878 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_case_element(
				(yyvsp[(2) - (4)].s_select_list_item),
				(yyvsp[(4) - (4)].s_select_list_item));

	}
    break;

  case 501:

/* Line 1455 of yacc.c  */
#line 2884 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_case_element( 0, (yyvsp[(2) - (2)].s_select_list_item));
	}
    break;

  case 502:

/* Line 1455 of yacc.c  */
#line 2891 "sql.yacc"
    {
		(yyval.s_select_list_item_list)=local_new_select_list_item_list((yyvsp[(1) - (1)].s_select_list_item));
	}
    break;

  case 503:

/* Line 1455 of yacc.c  */
#line 2894 "sql.yacc"
    {
			(yyval.s_select_list_item_list)=local_add_select_list_item_list((yyvsp[(1) - (3)].s_select_list_item_list),(yyvsp[(3) - (3)].s_select_list_item));
	}
    break;

  case 504:

/* Line 1455 of yacc.c  */
#line 2922 "sql.yacc"
    {
			(yyval.s_select_list_item)=new_select_list_item_extend(new_select_list_item_builtin_const(E_SLI_BUILTIN_CONST_CURRENT),(yyvsp[(3) - (5)].str),(yyvsp[(5) - (5)].str));
	}
    break;

  case 505:

/* Line 1455 of yacc.c  */
#line 2925 "sql.yacc"
    {
			(yyval.s_select_list_item)=new_select_list_item_extend((yyvsp[(1) - (5)].s_select_list_item),(yyvsp[(3) - (5)].str),(yyvsp[(5) - (5)].str));
	}
    break;

  case 506:

/* Line 1455 of yacc.c  */
#line 2928 "sql.yacc"
    {
			(yyval.s_select_list_item)=new_select_list_item_extend(new_select_list_item_builtin_const(E_SLI_BUILTIN_CONST_CURRENT),(yyvsp[(2) - (4)].str),(yyvsp[(4) - (4)].str));
	}
    break;

  case 507:

/* Line 1455 of yacc.c  */
#line 2931 "sql.yacc"
    {
			(yyval.s_select_list_item)=new_select_list_item_extend((yyvsp[(1) - (5)].s_select_list_item),(yyvsp[(3) - (5)].str),(yyvsp[(5) - (5)].str));
	}
    break;

  case 508:

/* Line 1455 of yacc.c  */
#line 2937 "sql.yacc"
    {(yyval.integer_val)=E_SLI_UNITS_YEAR;}
    break;

  case 509:

/* Line 1455 of yacc.c  */
#line 2938 "sql.yacc"
    {(yyval.integer_val)=E_SLI_UNITS_MONTH;}
    break;

  case 510:

/* Line 1455 of yacc.c  */
#line 2939 "sql.yacc"
    {(yyval.integer_val)=E_SLI_UNITS_DAY;}
    break;

  case 511:

/* Line 1455 of yacc.c  */
#line 2940 "sql.yacc"
    {(yyval.integer_val)=E_SLI_UNITS_HOUR;}
    break;

  case 512:

/* Line 1455 of yacc.c  */
#line 2941 "sql.yacc"
    {(yyval.integer_val)=E_SLI_UNITS_MINUTE;}
    break;

  case 513:

/* Line 1455 of yacc.c  */
#line 2942 "sql.yacc"
    {(yyval.integer_val)=E_SLI_UNITS_SECOND;}
    break;

  case 514:

/* Line 1455 of yacc.c  */
#line 2947 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_op_slil((yyvsp[(1) - (5)].s_select_list_item),(yyvsp[(4) - (5)].s_select_list_item_list),E_SLI_IN_VALUES);
                add_feature("WHERE_IN");
        }
    break;

  case 515:

/* Line 1455 of yacc.c  */
#line 2951 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_op_sli((yyvsp[(1) - (3)].s_select_list_item),(yyvsp[(3) - (3)].s_select_list_item),E_SLI_IN_SELECT);
                add_feature("WHERE_IN_SELECT");
        }
    break;

  case 516:

/* Line 1455 of yacc.c  */
#line 2955 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_op_slil((yyvsp[(1) - (5)].s_select_list_item),(yyvsp[(4) - (5)].s_select_list_item_list),E_SLI_NOT_IN_VALUES);
                add_feature("WHERE_IN");
        }
    break;

  case 517:

/* Line 1455 of yacc.c  */
#line 2959 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_op_sli((yyvsp[(1) - (3)].s_select_list_item),(yyvsp[(3) - (3)].s_select_list_item),E_SLI_NOT_IN_SELECT);
                add_feature("WHERE_IN_SELECT");
        }
    break;

  case 518:

/* Line 1455 of yacc.c  */
#line 2966 "sql.yacc"
    {
		(yyval.s_select_list_item_list)=local_new_select_list_item_list((yyvsp[(1) - (1)].s_select_list_item));
	}
    break;

  case 519:

/* Line 1455 of yacc.c  */
#line 2969 "sql.yacc"
    {
                (yyval.s_select_list_item_list)=local_add_select_list_item_list((yyvsp[(1) - (3)].s_select_list_item_list),(yyvsp[(3) - (3)].s_select_list_item));
	}
    break;

  case 520:

/* Line 1455 of yacc.c  */
#line 2974 "sql.yacc"
    { (yyval.s_select_list_item)=(yyvsp[(1) - (1)].s_select_list_item);}
    break;

  case 521:

/* Line 1455 of yacc.c  */
#line 2975 "sql.yacc"
    { (yyval.s_select_list_item)=new_select_list_item_literal((yyvsp[(1) - (1)].str)); }
    break;

  case 522:

/* Line 1455 of yacc.c  */
#line 2976 "sql.yacc"
    { 
		char buff[256]; SPRINTF1(buff," -%s",(yyvsp[(2) - (2)].str)); (yyval.s_select_list_item)=new_select_list_item_literal(buff); }
    break;

  case 523:

/* Line 1455 of yacc.c  */
#line 2978 "sql.yacc"
    { char buff[256]; SPRINTF1(buff," -%s",(yyvsp[(2) - (2)].str)); (yyval.s_select_list_item)=new_select_list_item_literal(buff); }
    break;

  case 524:

/* Line 1455 of yacc.c  */
#line 2984 "sql.yacc"
    {
                if (strstr((yyvsp[(1) - (1)].str),"systables")!=0) { add_feature("IFX_SYSTABLES"); }
                if (strstr((yyvsp[(1) - (1)].str),"syscolumns")!=0) { add_feature("IFX_SYSCOLUMNS"); }
                if (strstr((yyvsp[(1) - (1)].str),"sysindexes")!=0) { add_feature("IFX_SYSINDEXES"); }
                strcpy((yyval.str),A4GLSQLCV_check_tablename((yyvsp[(1) - (1)].str)));
                }
    break;

  case 525:

/* Line 1455 of yacc.c  */
#line 2994 "sql.yacc"
    {
	     SPRINTF1((yyval.str),"%s", A4GLSQLCV_ownerize_tablename(NULL, A4GL_strip_quotes((yyvsp[(1) - (1)].str))));
             ADDMAP("Use Table",(yyval.str));
        }
    break;

  case 526:

/* Line 1455 of yacc.c  */
#line 2998 "sql.yacc"
    {
	     SPRINTF1((yyval.str),"%s", A4GLSQLCV_ownerize_tablename((yyvsp[(1) - (3)].str), (yyvsp[(3) - (3)].str)));
	     ADDMAP("Use Table",(yyval.str));
        }
    break;

  case 527:

/* Line 1455 of yacc.c  */
#line 3002 "sql.yacc"
    {
	     SPRINTF1((yyval.str),"%s", A4GLSQLCV_ownerize_tablename(NULL, (yyvsp[(1) - (1)].str)));
	     ADDMAP("Use Table",(yyval.str));
	}
    break;

  case 528:

/* Line 1455 of yacc.c  */
#line 3006 "sql.yacc"
    {
	     SPRINTF1((yyval.str),"%s", A4GLSQLCV_db_tablename((yyvsp[(1) - (3)].str), NULL, A4GLSQLCV_ownerize_tablename(NULL, (yyvsp[(3) - (3)].str))));
	     ADDMAP("Use Table",(yyval.str));
	}
    break;

  case 529:

/* Line 1455 of yacc.c  */
#line 3010 "sql.yacc"
    {
	     SPRINTF1((yyval.str),"%s", A4GLSQLCV_db_tablename((yyvsp[(1) - (5)].str), NULL, A4GLSQLCV_ownerize_tablename((yyvsp[(3) - (5)].str),(yyvsp[(5) - (5)].str))));
	     ADDMAP("Use Table",(yyval.str));
        }
    break;

  case 530:

/* Line 1455 of yacc.c  */
#line 3014 "sql.yacc"
    {
	     SPRINTF1((yyval.str),"%s", A4GLSQLCV_db_tablename(NULL,(yyvsp[(1) - (3)].str), A4GLSQLCV_ownerize_tablename(NULL, (yyvsp[(3) - (3)].str))));
	     ADDMAP("Use Table",(yyval.str));
	}
    break;

  case 531:

/* Line 1455 of yacc.c  */
#line 3018 "sql.yacc"
    {
	     SPRINTF1((yyval.str),"%s", A4GLSQLCV_db_tablename((yyvsp[(1) - (5)].str), (yyvsp[(3) - (5)].str), A4GLSQLCV_ownerize_tablename(NULL, (yyvsp[(5) - (5)].str))));
	     ADDMAP("Use Table",(yyval.str));
	}
    break;

  case 532:

/* Line 1455 of yacc.c  */
#line 3022 "sql.yacc"
    {
	     SPRINTF1((yyval.str),"%s", A4GLSQLCV_db_tablename((yyvsp[(1) - (7)].str), (yyvsp[(3) - (7)].str), A4GLSQLCV_ownerize_tablename((yyvsp[(5) - (7)].str), (yyvsp[(7) - (7)].str))));
	     ADDMAP("Use Table",(yyval.str));
        }
    break;

  case 533:

/* Line 1455 of yacc.c  */
#line 3030 "sql.yacc"
    {
                if (strstr((yyvsp[(1) - (1)].str),"systables")!=0) { add_feature("IFX_SYSTABLES"); }
                if (strstr((yyvsp[(1) - (1)].str),"syscolumns")!=0) { add_feature("IFX_SYSCOLUMNS"); }
                if (strstr((yyvsp[(1) - (1)].str),"sysindexes")!=0) { add_feature("IFX_SYSINDEXES"); }
                strcpy((yyval.str),A4GLSQLCV_check_tablename((yyvsp[(1) - (1)].str)));
                }
    break;

  case 534:

/* Line 1455 of yacc.c  */
#line 3040 "sql.yacc"
    {

	     SPRINTF1((yyval.str),"%s", A4GLSQLCV_ownerize_tablename((yyvsp[(1) - (3)].str), (yyvsp[(3) - (3)].str)));
	     ADDMAP("Use Table",(yyval.str));
        }
    break;

  case 535:

/* Line 1455 of yacc.c  */
#line 3045 "sql.yacc"
    {
	     SPRINTF1((yyval.str),"%s", A4GLSQLCV_ownerize_tablename((yyvsp[(1) - (3)].str), (yyvsp[(3) - (3)].str)));
	     ADDMAP("Use Table",(yyval.str));
        }
    break;

  case 536:

/* Line 1455 of yacc.c  */
#line 3049 "sql.yacc"
    {
	     SPRINTF1((yyval.str),"%s", A4GLSQLCV_ownerize_tablename(NULL, A4GL_strip_quotes((yyvsp[(1) - (1)].str))));
	     ADDMAP("Use Table",(yyval.str));
        }
    break;

  case 537:

/* Line 1455 of yacc.c  */
#line 3053 "sql.yacc"
    {
             SPRINTF1((yyval.str),"%s", A4GLSQLCV_ownerize_tablename(NULL, (yyvsp[(1) - (1)].str)));
	     ADDMAP("Use Table",(yyval.str));
	}
    break;

  case 538:

/* Line 1455 of yacc.c  */
#line 3057 "sql.yacc"
    {
             SPRINTF1((yyval.str),"%s", A4GLSQLCV_db_tablename((yyvsp[(1) - (3)].str),NULL, A4GLSQLCV_ownerize_tablename(NULL, (yyvsp[(3) - (3)].str))));
	     ADDMAP("Use Table",(yyval.str));
	}
    break;

  case 539:

/* Line 1455 of yacc.c  */
#line 3061 "sql.yacc"
    {
	     SPRINTF1((yyval.str),"%s", A4GLSQLCV_db_tablename((yyvsp[(1) - (5)].str), NULL,A4GLSQLCV_ownerize_tablename((yyvsp[(3) - (5)].str), (yyvsp[(5) - (5)].str))));
	     ADDMAP("Use Table",(yyval.str));
        }
    break;

  case 540:

/* Line 1455 of yacc.c  */
#line 3066 "sql.yacc"
    {
             SPRINTF1((yyval.str),"%s", A4GLSQLCV_db_tablename(NULL, (yyvsp[(1) - (3)].str), A4GLSQLCV_ownerize_tablename(NULL, (yyvsp[(3) - (3)].str))));
	     ADDMAP("Use Table",(yyval.str));
	}
    break;

  case 541:

/* Line 1455 of yacc.c  */
#line 3070 "sql.yacc"
    {
            SPRINTF1((yyval.str),"%s", A4GLSQLCV_db_tablename( (yyvsp[(1) - (5)].str), (yyvsp[(3) - (5)].str), A4GLSQLCV_ownerize_tablename(NULL, (yyvsp[(5) - (5)].str))));
	    ADDMAP("Use Table",(yyval.str));
	}
    break;

  case 542:

/* Line 1455 of yacc.c  */
#line 3074 "sql.yacc"
    {
	     SPRINTF1((yyval.str),"%s", A4GLSQLCV_db_tablename((yyvsp[(1) - (7)].str), (yyvsp[(3) - (7)].str), A4GLSQLCV_ownerize_tablename((yyvsp[(5) - (7)].str), (yyvsp[(7) - (7)].str))));
	     ADDMAP("Use Table",(yyval.str));
        }
    break;

  case 543:

/* Line 1455 of yacc.c  */
#line 3082 "sql.yacc"
    {
	     SPRINTF1((yyval.str),"%s", A4GLSQLCV_ownerize_tablename((yyvsp[(1) - (3)].str), (yyvsp[(3) - (3)].str)));
        }
    break;

  case 544:

/* Line 1455 of yacc.c  */
#line 3085 "sql.yacc"
    {
	        SPRINTF1((yyval.str),"%s", A4GLSQLCV_ownerize_tablename(NULL, (yyvsp[(1) - (1)].str)));
                ADDMAP("Use Index",(yyval.str));
        }
    break;

  case 545:

/* Line 1455 of yacc.c  */
#line 3090 "sql.yacc"
    {strcpy((yyval.str),(yyvsp[(1) - (1)].str)); ADDMAP("Use Index",(yyvsp[(1) - (1)].str)); }
    break;

  case 546:

/* Line 1455 of yacc.c  */
#line 3091 "sql.yacc"
    { SPRINTF3((yyval.str),"%s%s%s",(yyvsp[(1) - (3)].str),(yyvsp[(2) - (3)].str),(yyvsp[(3) - (3)].str)); ADDMAP("Use Index",(yyval.str)); }
    break;

  case 547:

/* Line 1455 of yacc.c  */
#line 3092 "sql.yacc"
    {
	     SPRINTF2((yyval.str),"%s:%s", (yyvsp[(1) - (5)].str), A4GLSQLCV_ownerize_tablename((yyvsp[(3) - (5)].str), (yyvsp[(5) - (5)].str)));
             ADDMAP("Use Index",(yyval.str));
        }
    break;

  case 548:

/* Line 1455 of yacc.c  */
#line 3097 "sql.yacc"
    {strcpy((yyval.str),(yyvsp[(1) - (3)].str)); ADDMAP("Use Index",(yyvsp[(1) - (3)].str)); }
    break;

  case 549:

/* Line 1455 of yacc.c  */
#line 3098 "sql.yacc"
    { SPRINTF4((yyval.str),"%s@%s%s%s",(yyvsp[(1) - (5)].str),(yyvsp[(3) - (5)].str),(yyvsp[(4) - (5)].str),(yyvsp[(5) - (5)].str)); ADDMAP("Use Index",(yyval.str)); }
    break;

  case 550:

/* Line 1455 of yacc.c  */
#line 3099 "sql.yacc"
    {
	     SPRINTF3((yyval.str),"%s@%s:%s", (yyvsp[(1) - (7)].str), (yyvsp[(3) - (7)].str), A4GLSQLCV_ownerize_tablename((yyvsp[(5) - (7)].str), (yyvsp[(7) - (7)].str)));
             ADDMAP("Use Index",(yyval.str));
        }
    break;

  case 552:

/* Line 1455 of yacc.c  */
#line 3110 "sql.yacc"
    {
                      (yyval.ptr)=A4GL_new_expr_simple_string(A4GL_get_clobbered_from((yyval.str)), ET_EXPR_IDENTIFIER);
	}
    break;

  case 554:

/* Line 1455 of yacc.c  */
#line 3116 "sql.yacc"
    { sprintf((yyval.str),".%s",(yyvsp[(2) - (2)].str)); }
    break;

  case 556:

/* Line 1455 of yacc.c  */
#line 3121 "sql.yacc"
    {strcpy((yyval.str), A4GL_strip_quotes ((yyvsp[(1) - (1)].str)));}
    break;

  case 561:

/* Line 1455 of yacc.c  */
#line 3172 "sql.yacc"
    {
			int converted;
			(yyval.sql_string)=get_insert_cmd((yyvsp[(1) - (1)].insert_cmd),&converted);
			A4GL_free_associated_mem((yyvsp[(1) - (1)].insert_cmd));
			acl_free((yyvsp[(1) - (1)].insert_cmd));

		}
    break;

  case 562:

/* Line 1455 of yacc.c  */
#line 3179 "sql.yacc"
    {
			int converted;
			(yyval.sql_string)=get_update_cmd((yyvsp[(1) - (1)].update_cmd),&converted);
			A4GL_free_associated_mem((yyvsp[(1) - (1)].update_cmd));
			acl_free((yyvsp[(1) - (1)].update_cmd));
		}
    break;

  case 563:

/* Line 1455 of yacc.c  */
#line 3185 "sql.yacc"
    {
			int converted;
			(yyval.sql_string)=get_delete_cmd((yyvsp[(1) - (1)].delete_cmd),&converted);
			A4GL_free_associated_mem((yyvsp[(1) - (1)].delete_cmd));
			acl_free((yyvsp[(1) - (1)].delete_cmd));
		}
    break;

  case 566:

/* Line 1455 of yacc.c  */
#line 3200 "sql.yacc"
    { print_exec_select((yyvsp[(1) - (1)].sql_string));  }
    break;

  case 567:

/* Line 1455 of yacc.c  */
#line 3201 "sql.yacc"
    { print_exec_select((yyvsp[(1) - (1)].sql_string));  }
    break;

  case 569:

/* Line 1455 of yacc.c  */
#line 3203 "sql.yacc"
    { print_exec_select((yyvsp[(1) - (1)].sql_string));  }
    break;

  case 570:

/* Line 1455 of yacc.c  */
#line 3205 "sql.yacc"
    {
			print_sql_commit ((yyvsp[(1) - (1)].integer_val));
	}
    break;

  case 571:

/* Line 1455 of yacc.c  */
#line 3208 "sql.yacc"
    {print_unable_to_parse();}
    break;

  case 572:

/* Line 1455 of yacc.c  */
#line 3212 "sql.yacc"
    { (yyval.sql_string)=make_sql_string_and_free((yyvsp[(1) - (2)].sql_string),acl_strdup((yyvsp[(2) - (2)].str)),0);
}
    break;

  case 574:

/* Line 1455 of yacc.c  */
#line 3221 "sql.yacc"
    {
			(yyval.sql_string)=make_select_stmt_v2("", (yyvsp[(1) - (1)].s_select),"");
			A4GL_free_select_stmt((yyvsp[(1) - (1)].s_select));
		}
    break;

  case 575:

/* Line 1455 of yacc.c  */
#line 3227 "sql.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 576:

/* Line 1455 of yacc.c  */
#line 3228 "sql.yacc"
    {
			strcpy((yyval.str),A4GLSQLCV_get_forupdate(NULL));
		}
    break;

  case 577:

/* Line 1455 of yacc.c  */
#line 3231 "sql.yacc"
    {
			strcpy((yyval.str),A4GLSQLCV_get_forupdate((yyvsp[(2) - (2)].str)));
		}
    break;

  case 578:

/* Line 1455 of yacc.c  */
#line 3236 "sql.yacc"
    { strcpy((yyval.str),(yyvsp[(1) - (1)].str)); }
    break;

  case 579:

/* Line 1455 of yacc.c  */
#line 3237 "sql.yacc"
    { sprintf((yyval.str),"%s,%s",(yyvsp[(1) - (3)].str),(yyvsp[(3) - (3)].str)); }
    break;

  case 581:

/* Line 1455 of yacc.c  */
#line 3241 "sql.yacc"
    {sprintf((yyval.str),"%s.%s",A4GLSQLCV_ownerize_tablename(NULL, (yyvsp[(1) - (3)].str)),(yyvsp[(3) - (3)].str));}
    break;

  case 582:

/* Line 1455 of yacc.c  */
#line 3242 "sql.yacc"
    {
        sprintf((yyval.str),"%s.%s", A4GLSQLCV_ownerize_tablename((yyvsp[(1) - (5)].str), (yyvsp[(3) - (5)].str)), (yyvsp[(5) - (5)].str));
}
    break;

  case 583:

/* Line 1455 of yacc.c  */
#line 3252 "sql.yacc"
    { print_exec_sql(acl_strdup((yyvsp[(1) - (1)].str))); }
    break;

  case 584:

/* Line 1455 of yacc.c  */
#line 3253 "sql.yacc"
    { print_exec_sql(acl_strdup((yyvsp[(1) - (1)].str))); }
    break;

  case 585:

/* Line 1455 of yacc.c  */
#line 3254 "sql.yacc"
    { sprintf((yyval.str),"%s %s",(yyvsp[(1) - (2)].str),(yyvsp[(2) - (2)].str)); print_exec_sql(acl_strdup((yyval.str))); }
    break;

  case 586:

/* Line 1455 of yacc.c  */
#line 3255 "sql.yacc"
    { print_exec_sql(acl_strdup((yyvsp[(1) - (1)].str))); }
    break;

  case 587:

/* Line 1455 of yacc.c  */
#line 3256 "sql.yacc"
    { print_exec_sql(acl_strdup((yyvsp[(1) - (1)].str))); }
    break;

  case 588:

/* Line 1455 of yacc.c  */
#line 3257 "sql.yacc"
    { print_exec_sql(acl_strdup((yyvsp[(1) - (1)].str))); }
    break;

  case 589:

/* Line 1455 of yacc.c  */
#line 3258 "sql.yacc"
    { print_exec_sql(acl_strdup((yyvsp[(1) - (1)].str))); }
    break;

  case 590:

/* Line 1455 of yacc.c  */
#line 3259 "sql.yacc"
    { print_exec_sql(acl_strdup((yyvsp[(1) - (1)].str))); }
    break;

  case 591:

/* Line 1455 of yacc.c  */
#line 3263 "sql.yacc"
    { 
	char *s;
	s=acl_strdup((yyvsp[(1) - (1)].str));
	(yyval.s_select_list_item)=new_select_list_item_column_from_transform(s);
	acl_free(s);
	}
    break;

  case 592:

/* Line 1455 of yacc.c  */
#line 3269 "sql.yacc"
    {  
		(yyval.s_select_list_item)=new_select_list_item_builtin_const(E_SLI_QUERY_PLACEHOLDER);}
    break;

  case 593:

/* Line 1455 of yacc.c  */
#line 3271 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_replace_var((yyvsp[(1) - (1)].sql_string));
	}
    break;

  case 594:

/* Line 1455 of yacc.c  */
#line 3290 "sql.yacc"
    {
        add_feature("DATABASE_USED");
       conn_db((yyvsp[(2) - (3)].str));
}
    break;

  case 595:

/* Line 1455 of yacc.c  */
#line 3298 "sql.yacc"
    {
		(yyval.sql_string)=acl_strdup((yyvsp[(2) - (3)].str));
}
    break;

  case 596:

/* Line 1455 of yacc.c  */
#line 3305 "sql.yacc"
    {sprintf((yyval.str),"(%s)",(yyvsp[(2) - (3)].str));}
    break;

  case 597:

/* Line 1455 of yacc.c  */
#line 3306 "sql.yacc"
    { sprintf((yyval.str),"%s%s%s",(yyvsp[(1) - (3)].str),(yyvsp[(2) - (3)].str),(yyvsp[(3) - (3)].str));}
    break;

  case 598:

/* Line 1455 of yacc.c  */
#line 3307 "sql.yacc"
    {sprintf((yyval.str),"%d",atoi((yyvsp[(1) - (1)].str)));}
    break;

  case 599:

/* Line 1455 of yacc.c  */
#line 3308 "sql.yacc"
    {sprintf((yyval.str),"(%s%s)",(yyvsp[(1) - (2)].str),(yyvsp[(2) - (2)].str));}
    break;

  case 600:

/* Line 1455 of yacc.c  */
#line 3313 "sql.yacc"
    {strcpy((yyval.str),"+");}
    break;

  case 601:

/* Line 1455 of yacc.c  */
#line 3314 "sql.yacc"
    {strcpy((yyval.str),"-");}
    break;

  case 602:

/* Line 1455 of yacc.c  */
#line 3315 "sql.yacc"
    {strcpy((yyval.str),"*");}
    break;

  case 603:

/* Line 1455 of yacc.c  */
#line 3316 "sql.yacc"
    {strcpy((yyval.str),"/");}
    break;

  case 604:

/* Line 1455 of yacc.c  */
#line 3317 "sql.yacc"
    {strcpy((yyval.str),"%");}
    break;

  case 605:

/* Line 1455 of yacc.c  */
#line 3322 "sql.yacc"
    {strcpy((yyval.str),"+");}
    break;

  case 606:

/* Line 1455 of yacc.c  */
#line 3323 "sql.yacc"
    {strcpy((yyval.str),"-");}
    break;

  case 607:

/* Line 1455 of yacc.c  */
#line 3339 "sql.yacc"
    {sprintf((yyval.str),"%s", A4GLSQLCV_check_tablename((yyvsp[(1) - (1)].str)));}
    break;

  case 608:

/* Line 1455 of yacc.c  */
#line 3340 "sql.yacc"
    {sprintf((yyval.str),"%s.*", A4GLSQLCV_ownerize_tablename(NULL,(yyvsp[(1) - (3)].str)));}
    break;

  case 609:

/* Line 1455 of yacc.c  */
#line 3341 "sql.yacc"
    {sprintf((yyval.str),"%s.%s", (yyvsp[(1) - (3)].str),A4GLSQLCV_get_sqlconst ("rowid"));}
    break;

  case 610:

/* Line 1455 of yacc.c  */
#line 3342 "sql.yacc"
    {sprintf((yyval.str),"%s.%s", A4GLSQLCV_ownerize_tablename(NULL,(yyvsp[(1) - (3)].str)),(yyvsp[(3) - (3)].str));}
    break;

  case 611:

/* Line 1455 of yacc.c  */
#line 3343 "sql.yacc"
    {sprintf((yyval.str),"%s.%s", A4GLSQLCV_ownerize_tablename((yyvsp[(1) - (5)].str),(yyvsp[(3) - (5)].str)),(yyvsp[(5) - (5)].str));}
    break;

  case 612:

/* Line 1455 of yacc.c  */
#line 3344 "sql.yacc"
    {sprintf((yyval.str),"%s.%s", A4GLSQLCV_ownerize_tablename((yyvsp[(1) - (5)].str),(yyvsp[(3) - (5)].str)),(yyvsp[(5) - (5)].str));}
    break;

  case 613:

/* Line 1455 of yacc.c  */
#line 3345 "sql.yacc"
    {sprintf((yyval.str),"%s", (yyvsp[(1) - (4)].str)); strcpy((yyval.str), A4GLSQLCV_make_substr_s((yyvsp[(1) - (4)].str), 1,(yyvsp[(3) - (4)].str),0));}
    break;

  case 614:

/* Line 1455 of yacc.c  */
#line 3346 "sql.yacc"
    {char buff[256]; sprintf(buff,"%s.%s", A4GLSQLCV_ownerize_tablename(NULL,(yyvsp[(1) - (6)].str)),(yyvsp[(3) - (6)].str)); strcpy((yyval.str), A4GLSQLCV_make_substr_s(buff,1,(yyvsp[(5) - (6)].str),0));}
    break;

  case 615:

/* Line 1455 of yacc.c  */
#line 3347 "sql.yacc"
    {char buff[256]; sprintf(buff,"%s.%s", A4GLSQLCV_ownerize_tablename((yyvsp[(1) - (8)].str),(yyvsp[(3) - (8)].str)), (yyvsp[(5) - (8)].str)); strcpy((yyval.str), A4GLSQLCV_make_substr_s(buff,1,(yyvsp[(7) - (8)].str),0));  }
    break;

  case 616:

/* Line 1455 of yacc.c  */
#line 3348 "sql.yacc"
    {char buff[256]; sprintf(buff,"%s.%s", A4GLSQLCV_ownerize_tablename((yyvsp[(1) - (8)].str),(yyvsp[(3) - (8)].str)), (yyvsp[(5) - (8)].str));  strcpy((yyval.str), A4GLSQLCV_make_substr_s(buff,1,(yyvsp[(7) - (8)].str),0)); }
    break;

  case 617:

/* Line 1455 of yacc.c  */
#line 3350 "sql.yacc"
    {sprintf((yyval.str),"%s", (yyvsp[(1) - (6)].str)); strcpy((yyval.str), A4GLSQLCV_make_substr_s((yyvsp[(1) - (6)].str), 2,(yyvsp[(3) - (6)].str),(yyvsp[(5) - (6)].str)));}
    break;

  case 618:

/* Line 1455 of yacc.c  */
#line 3351 "sql.yacc"
    {char buff[256]; sprintf(buff,"%s.%s", A4GLSQLCV_ownerize_tablename(NULL,(yyvsp[(1) - (8)].str)),(yyvsp[(3) - (8)].str)); strcpy((yyval.str), A4GLSQLCV_make_substr_s(buff,2,(yyvsp[(5) - (8)].str),(yyvsp[(7) - (8)].str)));}
    break;

  case 619:

/* Line 1455 of yacc.c  */
#line 3352 "sql.yacc"
    {char buff[256]; sprintf(buff,"%s.%s", A4GLSQLCV_ownerize_tablename((yyvsp[(1) - (10)].str),(yyvsp[(3) - (10)].str)), (yyvsp[(5) - (10)].str)); strcpy((yyval.str), A4GLSQLCV_make_substr_s(buff,2,(yyvsp[(7) - (10)].str),(yyvsp[(9) - (10)].str)));  }
    break;

  case 620:

/* Line 1455 of yacc.c  */
#line 3353 "sql.yacc"
    {char buff[256]; sprintf(buff,"%s.%s", A4GLSQLCV_ownerize_tablename((yyvsp[(1) - (10)].str),(yyvsp[(3) - (10)].str)), (yyvsp[(5) - (10)].str));  strcpy((yyval.str), A4GLSQLCV_make_substr_s(buff,2,(yyvsp[(7) - (10)].str),(yyvsp[(9) - (10)].str))); }
    break;

  case 621:

/* Line 1455 of yacc.c  */
#line 3358 "sql.yacc"
    {
                (yyval.s_select_list_item)=(yyvsp[(1) - (1)].s_select_list_item);
        }
    break;

  case 622:

/* Line 1455 of yacc.c  */
#line 3361 "sql.yacc"
    {
                (yyval.s_select_list_item)=new_select_list_item_cast((yyvsp[(1) - (3)].s_select_list_item), (yyvsp[(3) - (3)].str));
        }
    break;

  case 623:

/* Line 1455 of yacc.c  */
#line 3370 "sql.yacc"
    { (yyvsp[(1) - (1)].s_select_list_item)=(yyvsp[(1) - (1)].s_select_list_item); }
    break;

  case 624:

/* Line 1455 of yacc.c  */
#line 3371 "sql.yacc"
    {(yyvsp[(1) - (1)].s_select_list_item)=(yyvsp[(1) - (1)].s_select_list_item);}
    break;

  case 625:

/* Line 1455 of yacc.c  */
#line 3372 "sql.yacc"
    {  (yyval.s_select_list_item)=new_select_list_item_sq(E_SQE_DONT_CARE,(yyvsp[(1) - (1)].s_select_list_item)); }
    break;

  case 626:

/* Line 1455 of yacc.c  */
#line 3373 "sql.yacc"
    { (yyval.s_select_list_item)=new_select_list_item_sq(E_SQE_ALL,(yyvsp[(2) - (2)].s_select_list_item)); }
    break;

  case 627:

/* Line 1455 of yacc.c  */
#line 3374 "sql.yacc"
    { (yyval.s_select_list_item)=new_select_list_item_sq(E_SQE_ANY,(yyvsp[(2) - (2)].s_select_list_item)); }
    break;

  case 628:

/* Line 1455 of yacc.c  */
#line 3375 "sql.yacc"
    { (yyval.s_select_list_item)=new_select_list_item_sq(E_SQE_SOME,(yyvsp[(2) - (2)].s_select_list_item)); }
    break;

  case 629:

/* Line 1455 of yacc.c  */
#line 3379 "sql.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 630:

/* Line 1455 of yacc.c  */
#line 3380 "sql.yacc"
    {strcpy((yyval.str),(yyvsp[(1) - (1)].str));}
    break;



/* Line 1455 of yacc.c  */
#line 8846 "y.tab.c"
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
#line 3385 "sql.yacc"


#if LEX_YY_PREGEN
#include "../../tools/no_yacc/cygwin/compilers/sql/lex.sqlparse_yy.c"
#else
#include "lex.yy.c"
#endif
#include "util.c"
#include "cmds.c"

