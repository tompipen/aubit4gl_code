
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
     INT_VALUE = 2203,
     NAMED = 2204,
     NAMED_GEN = 2205,
     CHAR_VALUE = 2206,
     NOT_USED_1 = 2207,
     NOT_USED_2 = 2208,
     NOT_USED_3 = 2209,
     NOT_USED_4 = 2210,
     NOT_USED_5 = 2211,
     NOT_USED_6 = 2212,
     NOT_USED_7 = 2213,
     NOT_USED_8 = 2214,
     NUMBER_VALUE = 2215,
     SEMICOLON = 2216,
     QUESTION_MARK = 2217,
     CLINE = 2218,
     CH = 2219,
     MARK_VAR = 2220,
     END_MARK_VAR = 2221,
     LEFT_JOIN = 1002,
     INNER_JOIN = 1005,
     USING_BTREE = 1028,
     USING_RTREE = 1029,
     SET_BUFFERED_LOG = 1054,
     SET_LOG = 1057,
     MDY = 1059,
     WEEKDAY = 1060,
     MODE_ANSI = 1063,
     START_DATABASE = 1064,
     WITH_LOG_IN = 1065,
     SET_CONSTRAINTS_ALL_IMMEDIATE = 1066,
     DATETIME_VALUE = 1079,
     INTERVAL_VALUE = 1080,
     RECOVER_TABLE = 1081,
     ROLLFORWARD_DATABASE = 1082,
     DROP_TRIGGER = 1098,
     DROP_AUDIT_FOR = 1099,
     CREATE_AUDIT_FOR = 1100,
     EXECUTE_PROCEDURE = 1104,
     ALTER_TABLE = 1111,
     ALTER_INDEX = 1112,
     NEXT_SIZE = 1113,
     XSET_MULTIPLY_EQUAL_OPEN_BRACKET = 1150,
     XSET_ident_DOT_MULTIPLY_EQUAL_OPEN_BRACKET = 1151,
     XSET_ident_DOT_MULTIPLY_EQUAL = 1152,
     XSET_MULTIPLY_EQUAL = 1153,
     XSET_OPEN_BRACKET = 1154,
     CREATE_DATABASE = 1157,
     DROP_DATABASE = 1158,
     ADD_CONSTRAINT = 1160,
     DROP_CONSTRAINT = 1161,
     DROP_SYNONYM = 1162,
     CONSTRAINT = 1163,
     DOUBLE_PRECISION = 1172,
     COUNT_MULTIPLY = 1173,
     MODIFY_NEXT_SIZE = 1193,
     LOCK_MODE_PAGE = 1194,
     LOCK_MODE_ROW = 1195,
     UNITS_YEAR = 1202,
     UNITS_MONTH = 1203,
     UNITS_DAY = 1204,
     UNITS_HOUR = 1205,
     UNITS_MINUTE = 1206,
     UNITS_SECOND = 1207,
     TO_CLUSTER = 1212,
     TO_NOT_CLUSTER = 1213,
     CREATE_UC_IDX = 1215,
     CREATE_U_IDX = 1216,
     CREATE_C_IDX = 1217,
     CREATE_IDX = 1218,
     DOUBLE_COLON = 1228,
     SQLSICS = 1234,
     CREATE_SCHEMA = 1235,
     SQLSIRR = 1236,
     UPDATESTATS_T = 1237,
     SQLSICR = 1238,
     SQLSIDR = 1249,
     CREATE_TEMP_TABLE = 1250,
     WITH_CHECK_OPTION = 1258,
     WITH_GRANT_OPTION = 1259,
     SQLSLMNW = 1260,
     WHERE_CURRENT_OF = 1266,
     NOT_NULL_UNIQUE = 1274,
     SQLSLMW = 1281,
     ALL_PRIVILEGES = 1283,
     CREATE_SYNONYM = 1287,
     DROP_TABLE = 1288,
     INEXCLUSIVE = 1290,
     UPDATESTATS = 1295,
     CREATE_TABLE = 1321,
     DEFAULT_NULL = 1322,
     DEFAULT_TODAY = 1323,
     DEFAULT_USER = 1324,
     UNLOCK_TABLE = 1337,
     ROLLBACK_W = 1345,
     SQLSEON = 1347,
     SQLSEOFF = 1348,
     CREATE_VIEW = 1352,
     DELETE_FROM = 1353,
     EXTENT_SIZE = 1360,
     FOREIGN_KEY = 1361,
     INSERT_INTO = 1364,
     IS_NOT_NULL = 1366,
     NOT_MATCHES = 1369,
     PRIMARY_KEY = 1375,
     USE_SESSION = 1382,
     WITH_NO_LOG = 1383,
     INSHARE = 1386,
     BEGIN_WORK = 1392,
     DROP_INDEX = 1397,
     FOR_UPDATE_OF = 1403,
     FOR_UPDATE = 1404,
     LOCK_TABLE = 1409,
     NOT_EXISTS = 1411,
     REFERENCES = 1413,
     RENCOL = 1414,
     SMALLFLOAT = 1416,
     COMMIT_W = 1427,
     RENTAB = 1434,
     KW_CHAR = 1437,
     NCHAR = 1438,
     NVARCHAR = 1439,
     DELIMITER = 1441,
     DROP_VIEW = 1443,
     EXCLUSIVE = 1446,
     GREATER_THAN_EQ = 1450,
     INTO_TEMP = 1452,
     DATABASE = 1476,
     DATETIME = 1477,
     DISTINCT = 1479,
     FRACTION = 1486,
     GROUP_BY = 1488,
     INTERVAL = 1489,
     NOT_LIKE = 1491,
     NOT_ILIKE = 1492,
     NOT_NULL = 1493,
     RESOURCE = 1499,
     SMALLINT = 1500,
     IS_NULL = 1506,
     LESS_THAN_EQ = 1507,
     BETWEEN = 1509,
     CLOSE_BRACKET = 1512,
     CONNECT = 1515,
     KW_CURRENT = 1516,
     KW_DECIMAL = 1518,
     DEFAULT = 1520,
     INTEGER = 1528,
     SERIAL8 = 1530,
     MATCHES = 1533,
     VARCHAR = 1546,
     CLOSE_SQUARE = 1549,
     GREATER_THAN = 1550,
     KW_FALSE = 1551,
     NOT_IN = 1552,
     OPEN_BRACKET = 1554,
     KW_DELETE = 1562,
     KW_ESCAPE = 1565,
     EXISTS = 1566,
     EXTEND = 1567,
     HAVING = 1571,
     KW_INSERT = 1573,
     MINUTE = 1577,
     MODIFY = 1578,
     EQUAL = 1580,
     NOT_EQUAL = 1581,
     OPEN_SQUARE = 1583,
     PUBLIC = 1587,
     REVOKE = 1591,
     SECOND = 1595,
     KW_SELECT = 1599,
     SERIAL = 1600,
     UNIQUE = 1603,
     KW_UPDATE = 1605,
     VALUES = 1606,
     KW_NULL = 1609,
     KW_TRUE = 1610,
     ALTER = 1612,
     CHECK = 1618,
     COUNT = 1622,
     KW_FIRST = 1627,
     KW_FLOAT = 1628,
     GRANT = 1631,
     INDEX = 1634,
     LESS_THAN = 1637,
     MONEY = 1639,
     MONTH = 1640,
     KW_MULTIPLY = 1642,
     ORDER = 1643,
     OUTER = 1644,
     UNION = 1653,
     WHERE = 1656,
     KW_BYTE = 1663,
     CASE = 1665,
     KW_DATE = 1667,
     DESC = 1668,
     KW_DIVIDE = 1669,
     DROP = 1672,
     ELSE = 1673,
     FROM = 1677,
     HOUR = 1683,
     INTO = 1684,
     LIKE = 1687,
     REAL = 1696,
     SOME = 1701,
     KW_TEXT = 1705,
     KW_THEN = 1706,
     USER = 1707,
     WHEN = 1709,
     YEAR = 1712,
     KW_DOW = 1713,
     XSET = 1715,
     ADD = 1716,
     ALL = 1717,
     KW_AND = 1718,
     ANY = 1719,
     ASC = 1720,
     AVG = 1721,
     COLON = 1722,
     KW_COMMA = 1723,
     DAY = 1724,
     DBA = 1725,
     KW_FOR = 1729,
     XMAX = 1734,
     XMIN = 1735,
     KW_MINUS = 1736,
     KW_MOD = 1737,
     KW_NOT = 1738,
     KW_SUM = 1745,
     ATSIGN = 1748,
     KW_PLUS = 1749,
     KW_AS = 1755,
     KW_BY = 1757,
     KW_DOT = 1758,
     KW_IN = 1761,
     KW_ON = 1763,
     KW_OR = 1764,
     KW_TO = 1765,
     BEFORE = 1803,
     END = 1807,
     TILDE = 1814,
     ILIKE = 1815,
     FILLFACTOR = 1818,
     TIME = 1823,
     KW_TODAY = 1830,
     KW_ROWID = 1831,
     TIMESTAMP = 2179,
     KW_TAG = 2200,
     LINTMODULEISLIBRARY = 2201
   };
#endif
/* Tokens.  */
#define INT_VALUE 2203
#define NAMED 2204
#define NAMED_GEN 2205
#define CHAR_VALUE 2206
#define NOT_USED_1 2207
#define NOT_USED_2 2208
#define NOT_USED_3 2209
#define NOT_USED_4 2210
#define NOT_USED_5 2211
#define NOT_USED_6 2212
#define NOT_USED_7 2213
#define NOT_USED_8 2214
#define NUMBER_VALUE 2215
#define SEMICOLON 2216
#define QUESTION_MARK 2217
#define CLINE 2218
#define CH 2219
#define MARK_VAR 2220
#define END_MARK_VAR 2221
#define LEFT_JOIN 1002
#define INNER_JOIN 1005
#define USING_BTREE 1028
#define USING_RTREE 1029
#define SET_BUFFERED_LOG 1054
#define SET_LOG 1057
#define MDY 1059
#define WEEKDAY 1060
#define MODE_ANSI 1063
#define START_DATABASE 1064
#define WITH_LOG_IN 1065
#define SET_CONSTRAINTS_ALL_IMMEDIATE 1066
#define DATETIME_VALUE 1079
#define INTERVAL_VALUE 1080
#define RECOVER_TABLE 1081
#define ROLLFORWARD_DATABASE 1082
#define DROP_TRIGGER 1098
#define DROP_AUDIT_FOR 1099
#define CREATE_AUDIT_FOR 1100
#define EXECUTE_PROCEDURE 1104
#define ALTER_TABLE 1111
#define ALTER_INDEX 1112
#define NEXT_SIZE 1113
#define XSET_MULTIPLY_EQUAL_OPEN_BRACKET 1150
#define XSET_ident_DOT_MULTIPLY_EQUAL_OPEN_BRACKET 1151
#define XSET_ident_DOT_MULTIPLY_EQUAL 1152
#define XSET_MULTIPLY_EQUAL 1153
#define XSET_OPEN_BRACKET 1154
#define CREATE_DATABASE 1157
#define DROP_DATABASE 1158
#define ADD_CONSTRAINT 1160
#define DROP_CONSTRAINT 1161
#define DROP_SYNONYM 1162
#define CONSTRAINT 1163
#define DOUBLE_PRECISION 1172
#define COUNT_MULTIPLY 1173
#define MODIFY_NEXT_SIZE 1193
#define LOCK_MODE_PAGE 1194
#define LOCK_MODE_ROW 1195
#define UNITS_YEAR 1202
#define UNITS_MONTH 1203
#define UNITS_DAY 1204
#define UNITS_HOUR 1205
#define UNITS_MINUTE 1206
#define UNITS_SECOND 1207
#define TO_CLUSTER 1212
#define TO_NOT_CLUSTER 1213
#define CREATE_UC_IDX 1215
#define CREATE_U_IDX 1216
#define CREATE_C_IDX 1217
#define CREATE_IDX 1218
#define DOUBLE_COLON 1228
#define SQLSICS 1234
#define CREATE_SCHEMA 1235
#define SQLSIRR 1236
#define UPDATESTATS_T 1237
#define SQLSICR 1238
#define SQLSIDR 1249
#define CREATE_TEMP_TABLE 1250
#define WITH_CHECK_OPTION 1258
#define WITH_GRANT_OPTION 1259
#define SQLSLMNW 1260
#define WHERE_CURRENT_OF 1266
#define NOT_NULL_UNIQUE 1274
#define SQLSLMW 1281
#define ALL_PRIVILEGES 1283
#define CREATE_SYNONYM 1287
#define DROP_TABLE 1288
#define INEXCLUSIVE 1290
#define UPDATESTATS 1295
#define CREATE_TABLE 1321
#define DEFAULT_NULL 1322
#define DEFAULT_TODAY 1323
#define DEFAULT_USER 1324
#define UNLOCK_TABLE 1337
#define ROLLBACK_W 1345
#define SQLSEON 1347
#define SQLSEOFF 1348
#define CREATE_VIEW 1352
#define DELETE_FROM 1353
#define EXTENT_SIZE 1360
#define FOREIGN_KEY 1361
#define INSERT_INTO 1364
#define IS_NOT_NULL 1366
#define NOT_MATCHES 1369
#define PRIMARY_KEY 1375
#define USE_SESSION 1382
#define WITH_NO_LOG 1383
#define INSHARE 1386
#define BEGIN_WORK 1392
#define DROP_INDEX 1397
#define FOR_UPDATE_OF 1403
#define FOR_UPDATE 1404
#define LOCK_TABLE 1409
#define NOT_EXISTS 1411
#define REFERENCES 1413
#define RENCOL 1414
#define SMALLFLOAT 1416
#define COMMIT_W 1427
#define RENTAB 1434
#define KW_CHAR 1437
#define NCHAR 1438
#define NVARCHAR 1439
#define DELIMITER 1441
#define DROP_VIEW 1443
#define EXCLUSIVE 1446
#define GREATER_THAN_EQ 1450
#define INTO_TEMP 1452
#define DATABASE 1476
#define DATETIME 1477
#define DISTINCT 1479
#define FRACTION 1486
#define GROUP_BY 1488
#define INTERVAL 1489
#define NOT_LIKE 1491
#define NOT_ILIKE 1492
#define NOT_NULL 1493
#define RESOURCE 1499
#define SMALLINT 1500
#define IS_NULL 1506
#define LESS_THAN_EQ 1507
#define BETWEEN 1509
#define CLOSE_BRACKET 1512
#define CONNECT 1515
#define KW_CURRENT 1516
#define KW_DECIMAL 1518
#define DEFAULT 1520
#define INTEGER 1528
#define SERIAL8 1530
#define MATCHES 1533
#define VARCHAR 1546
#define CLOSE_SQUARE 1549
#define GREATER_THAN 1550
#define KW_FALSE 1551
#define NOT_IN 1552
#define OPEN_BRACKET 1554
#define KW_DELETE 1562
#define KW_ESCAPE 1565
#define EXISTS 1566
#define EXTEND 1567
#define HAVING 1571
#define KW_INSERT 1573
#define MINUTE 1577
#define MODIFY 1578
#define EQUAL 1580
#define NOT_EQUAL 1581
#define OPEN_SQUARE 1583
#define PUBLIC 1587
#define REVOKE 1591
#define SECOND 1595
#define KW_SELECT 1599
#define SERIAL 1600
#define UNIQUE 1603
#define KW_UPDATE 1605
#define VALUES 1606
#define KW_NULL 1609
#define KW_TRUE 1610
#define ALTER 1612
#define CHECK 1618
#define COUNT 1622
#define KW_FIRST 1627
#define KW_FLOAT 1628
#define GRANT 1631
#define INDEX 1634
#define LESS_THAN 1637
#define MONEY 1639
#define MONTH 1640
#define KW_MULTIPLY 1642
#define ORDER 1643
#define OUTER 1644
#define UNION 1653
#define WHERE 1656
#define KW_BYTE 1663
#define CASE 1665
#define KW_DATE 1667
#define DESC 1668
#define KW_DIVIDE 1669
#define DROP 1672
#define ELSE 1673
#define FROM 1677
#define HOUR 1683
#define INTO 1684
#define LIKE 1687
#define REAL 1696
#define SOME 1701
#define KW_TEXT 1705
#define KW_THEN 1706
#define USER 1707
#define WHEN 1709
#define YEAR 1712
#define KW_DOW 1713
#define XSET 1715
#define ADD 1716
#define ALL 1717
#define KW_AND 1718
#define ANY 1719
#define ASC 1720
#define AVG 1721
#define COLON 1722
#define KW_COMMA 1723
#define DAY 1724
#define DBA 1725
#define KW_FOR 1729
#define XMAX 1734
#define XMIN 1735
#define KW_MINUS 1736
#define KW_MOD 1737
#define KW_NOT 1738
#define KW_SUM 1745
#define ATSIGN 1748
#define KW_PLUS 1749
#define KW_AS 1755
#define KW_BY 1757
#define KW_DOT 1758
#define KW_IN 1761
#define KW_ON 1763
#define KW_OR 1764
#define KW_TO 1765
#define BEFORE 1803
#define END 1807
#define TILDE 1814
#define ILIKE 1815
#define FILLFACTOR 1818
#define TIME 1823
#define KW_TODAY 1830
#define KW_ROWID 1831
#define TIMESTAMP 2179
#define KW_TAG 2200
#define LINTMODULEISLIBRARY 2201




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
#line 760 "y.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 772 "y.tab.c"

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
#define YYLAST   2531

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  251
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  227
/* YYNRULES -- Number of rules.  */
#define YYNRULES  630
/* YYNRULES -- Number of states.  */
#define YYNSTATES  1122

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   2221

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
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
       2,     2,    22,     2,     2,    23,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    24,    25,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,    26,     2,     2,    27,     2,    28,
      29,     2,     2,    30,    31,    32,    33,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    34,
      35,    36,    37,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    38,    39,
      40,     2,     2,     2,    41,     2,     2,     2,     2,     2,
       2,    42,    43,    44,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      45,    46,    47,    48,    49,     2,     2,    50,    51,     2,
      52,    53,    54,    55,     2,     2,     2,     2,     2,     2,
       2,     2,    56,    57,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    58,    59,    60,     2,     2,     2,     2,
       2,     2,    61,    62,    63,    64,    65,    66,     2,     2,
       2,     2,    67,    68,     2,    69,    70,    71,    72,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    73,     2,
       2,     2,     2,     2,    74,    75,    76,    77,    78,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    79,
      80,     2,     2,     2,     2,     2,     2,     2,    81,    82,
      83,     2,     2,     2,     2,     2,    84,     2,     2,     2,
       2,     2,     2,     2,    85,     2,     2,     2,     2,     2,
       2,    86,     2,    87,     2,     2,     2,    88,    89,     2,
      90,     2,     2,     2,     2,    91,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    92,    93,    94,    95,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,    96,     2,     2,
       2,     2,     2,     2,     2,    97,     2,    98,    99,     2,
       2,     2,   100,   101,     2,     2,     2,     2,     2,     2,
     102,   103,     2,     2,   104,     2,   105,     2,     2,   106,
       2,     2,     2,     2,     2,   107,     2,     2,     2,     2,
       2,     2,   108,   109,     2,     2,   110,     2,     2,     2,
       2,     2,   111,     2,     2,     2,     2,   112,     2,     2,
       2,     2,     2,   113,   114,     2,     2,     2,     2,   115,
       2,   116,     2,   117,   118,     2,   119,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,   120,     2,     2,
       2,     2,     2,     2,   121,     2,     2,   122,   123,   124,
       2,   125,     2,   126,     2,     2,   127,     2,     2,     2,
     128,     2,   129,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,   130,   131,     2,   132,
       2,     2,     2,     2,     2,     2,   133,     2,   134,   135,
       2,   136,   137,   138,     2,     2,     2,     2,     2,   139,
     140,     2,     2,     2,     2,     2,   141,   142,     2,   143,
       2,     2,   144,     2,     2,   145,   146,     2,   147,     2,
     148,     2,     2,     2,     2,     2,     2,     2,   149,     2,
     150,     2,     2,   151,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,   152,     2,     2,   153,
     154,   155,   156,     2,   157,     2,     2,     2,     2,     2,
       2,     2,   158,     2,     2,   159,   160,   161,     2,     2,
       2,   162,     2,   163,     2,     2,     2,   164,   165,     2,
     166,   167,     2,   168,     2,     2,     2,   169,     2,     2,
       2,   170,     2,     2,     2,   171,     2,     2,     2,   172,
     173,     2,     2,   174,     2,   175,   176,     2,     2,   177,
     178,     2,   179,     2,     2,     2,     2,     2,   180,     2,
       2,     2,   181,     2,     2,     2,     2,   182,   183,     2,
       2,   184,     2,     2,   185,     2,     2,   186,     2,   187,
     188,     2,   189,   190,   191,     2,     2,     2,     2,     2,
       2,     2,     2,   192,     2,     2,   193,     2,     2,     2,
       2,     2,     2,   194,     2,   195,     2,   196,   197,   198,
       2,     2,   199,   200,     2,     2,     2,   201,     2,     2,
       2,     2,     2,   202,   203,     2,     2,   204,     2,     2,
       2,     2,     2,     2,     2,     2,   205,     2,     2,     2,
       2,   206,     2,     2,     2,   207,   208,   209,     2,   210,
       2,     2,   211,   212,     2,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,     2,     2,     2,   224,
       2,     2,     2,     2,   225,   226,   227,   228,   229,     2,
       2,     2,     2,     2,     2,   230,     2,     2,   231,   232,
       2,     2,     2,     2,     2,   233,     2,   234,   235,     2,
       2,   236,     2,   237,   238,   239,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   240,     2,     2,     2,   241,     2,     2,
       2,     2,     2,     2,   242,   243,     2,     2,   244,     2,
       2,     2,     2,   245,     2,     2,     2,     2,     2,     2,
     246,   247,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,   248,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     249,   250,     2,     3,     4,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21
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
     458,     0,    -1,   175,   449,   255,   253,    -1,    -1,    84,
     453,    -1,   193,   364,    -1,    -1,    84,   453,    -1,   193,
     364,    -1,    49,   260,   144,   166,   157,   261,   144,    -1,
      45,   261,   144,    -1,    46,   261,   144,    -1,   213,   256,
      -1,    48,   261,    -1,    47,   261,    -1,   259,    -1,   256,
     221,   259,    -1,   258,    -1,   231,   258,    -1,   452,   390,
      -1,   452,   235,   452,   390,    -1,   452,   235,   452,   235,
     452,   390,    -1,   452,   235,   189,    -1,   257,   166,   262,
      -1,   257,    -1,   260,   221,   257,    -1,   262,    -1,   261,
     221,   262,    -1,   437,    -1,   177,    -1,   264,    -1,    89,
     449,    -1,   126,   449,    -1,   112,   451,    -1,    38,   452,
      -1,   275,    -1,   266,    -1,    92,   449,   157,   280,   144,
     267,    -1,    80,   449,   157,   280,   144,   276,   267,   276,
      -1,    -1,   268,    -1,   269,    -1,   268,   269,    -1,   236,
     270,    -1,   102,     3,    -1,    44,     3,    -1,    59,    -1,
      60,    -1,     4,    -1,    -1,   272,    -1,   273,    -1,   272,
     273,    -1,   236,   270,    -1,   244,     3,    -1,    24,    -1,
      25,    -1,   449,    -1,    70,   451,   237,   274,   157,   278,
     144,   271,    -1,    69,   451,   237,   274,   157,   278,   144,
     271,    -1,    71,   451,   237,   274,   157,   278,   144,   271,
      -1,    72,   451,   237,   274,   157,   278,   144,   271,    -1,
      50,   462,    -1,    51,   462,    -1,    88,   449,   224,   449,
      -1,    40,   449,   236,     6,    -1,    39,   449,    -1,    54,
     449,    -1,    36,   449,    -1,    37,   452,    -1,    -1,   109,
      -1,    -1,   109,    -1,   279,    -1,   278,   221,   279,    -1,
     452,   218,    -1,   452,   197,    -1,   452,    -1,   281,    -1,
     280,   221,   281,    -1,   344,    -1,   342,    -1,    42,   452,
     283,    -1,    43,   451,    67,    -1,    43,   451,    68,    -1,
     284,    -1,   283,   221,   284,    -1,   285,    -1,   288,    -1,
     291,    -1,   296,    -1,   299,    -1,   295,    -1,   294,    -1,
     214,   286,    -1,   214,   157,   287,   144,    -1,   281,    -1,
     281,   240,   452,    -1,   286,    -1,   287,   221,   286,    -1,
     199,   290,    -1,   199,   157,   289,   144,    -1,   290,    -1,
     289,   221,   290,    -1,   452,    -1,   165,   293,    -1,   165,
     157,   292,   144,    -1,   293,    -1,   292,   221,   293,    -1,
     281,    -1,    59,    -1,    60,    -1,    58,     3,    -1,    52,
     342,   298,    -1,    52,   157,   297,   144,    -1,   342,   298,
      -1,   297,   221,   342,   298,    -1,    -1,    55,   452,    -1,
      53,   300,    -1,    53,   157,   300,   144,    -1,   301,    -1,
     300,   221,   301,    -1,   452,    -1,    97,    -1,    -1,   104,
     304,   449,   307,   305,    -1,    -1,   176,   306,   157,   310,
     144,    -1,   431,    -1,    -1,   157,   308,   144,    -1,   309,
      -1,   308,   221,   309,    -1,   452,    -1,   452,   235,   452,
      -1,   311,    -1,   310,   221,   311,    -1,   437,    -1,   177,
      -1,   101,   449,   254,    -1,   111,    -1,   120,    -1,    -1,
     127,    -1,   317,    -1,    31,   452,    32,     6,    30,    -1,
      31,   452,    32,     6,    -1,    33,    -1,    26,    -1,    27,
      -1,    77,   452,    -1,    91,    -1,   314,    -1,   313,    -1,
     302,    -1,   316,    -1,   350,    -1,   354,    -1,   401,    -1,
     263,    -1,   265,    -1,   282,    -1,   184,   323,   237,   449,
     239,   328,   322,    -1,   170,   323,   237,   449,   201,   328,
      -1,   184,   321,   239,   328,    -1,   170,   321,   201,   328,
      -1,   145,    -1,   139,    -1,   223,    -1,    -1,    82,    -1,
     233,   389,    -1,    87,    -1,   215,    -1,   324,    -1,   325,
      -1,   324,   221,   325,    -1,   172,   326,    -1,   163,    -1,
     158,    -1,   175,   326,    -1,   179,    -1,   185,    -1,    -1,
     157,   327,   144,    -1,   391,    -1,   327,   221,   391,    -1,
     329,    -1,   328,   221,   329,    -1,   169,    -1,   389,    -1,
     100,   449,   331,   233,   422,   333,    -1,    -1,   157,   332,
     144,    -1,   391,    -1,   332,   221,   391,    -1,    -1,    81,
      -1,   180,   157,   421,   144,    -1,   103,   157,   337,   144,
     336,    -1,   117,   338,    -1,   339,    -1,   449,    -1,   449,
     157,   339,   144,    -1,   391,    -1,   339,   221,   391,    -1,
     174,   157,   341,   144,    -1,   132,   157,   341,   144,    -1,
     107,   157,   341,   144,    -1,   391,    -1,   341,   221,   391,
      -1,   340,    -1,   335,    -1,   334,    -1,   148,   396,    -1,
      95,    -1,    94,    -1,    93,    -1,   452,   380,   345,   346,
      -1,    -1,   343,    -1,    -1,   347,    -1,   348,    -1,   347,
     348,    -1,   349,   298,    -1,   138,    -1,    85,    -1,   174,
      -1,   132,    -1,   336,    -1,   180,   157,   421,   144,    -1,
     107,    -1,    75,   351,   353,    -1,   352,    -1,   389,    -1,
     354,    -1,   353,   354,    -1,   330,    -1,   320,    -1,   162,
     364,    -1,   193,   364,    -1,   201,   358,    -1,   360,    -1,
     358,   221,   360,    -1,   358,   221,   191,   360,    -1,   358,
     221,   191,   157,   358,   144,    -1,   358,    22,   359,   237,
     364,    -1,   358,    23,   359,   237,   364,    -1,   358,    -1,
     157,   358,   144,    -1,   449,    -1,   449,   395,    -1,   449,
     233,   395,    -1,    -1,   357,   362,    -1,   363,    -1,   356,
     363,    -1,    -1,   418,    -1,   418,   355,    -1,   355,    -1,
     365,    -1,   364,   238,   365,    -1,   366,    -1,   365,   216,
     366,    -1,   367,    -1,   229,   367,    -1,   377,    -1,   157,
     364,   144,    -1,   160,   432,    -1,   116,   432,    -1,    -1,
     159,   373,    -1,    -1,   159,   373,    -1,    -1,   159,   373,
      -1,   475,    -1,   396,    -1,    -1,   229,    -1,   437,   374,
     141,    -1,   437,   374,   105,    -1,   437,   376,   437,    -1,
     437,   166,   437,    -1,   437,   166,   177,    -1,   437,   374,
     143,   437,   216,   437,    -1,   437,   204,   372,   371,    -1,
     437,   136,   372,   371,    -1,   437,   243,   372,   370,    -1,
     437,   137,   372,   370,    -1,   437,   151,   372,   369,    -1,
     437,   106,   372,   369,    -1,   167,    -1,   186,    -1,   154,
      -1,   242,    -1,   142,    -1,   128,    -1,   375,    -1,   444,
      -1,   368,    -1,   437,    -1,    -1,   215,    -1,   132,    -1,
     174,    -1,    -1,   215,    -1,   132,    -1,   174,    -1,   381,
      -1,   382,    -1,   383,    -1,   385,    -1,   122,    -1,   122,
     157,   386,   144,    -1,   173,    -1,   173,   157,     3,   144,
      -1,   150,    -1,   150,   157,     3,   144,    -1,   147,    -1,
     147,   157,   387,   384,   144,    -1,   187,   157,   387,   384,
     144,    -1,   187,    -1,   196,    -1,   149,    -1,   140,    -1,
     123,    -1,   123,   157,   386,   144,    -1,   124,    -1,   124,
     157,     3,   144,    -1,   124,   157,     3,   221,     3,   144,
      -1,   131,   398,   239,   399,    -1,   131,    -1,   135,   398,
     239,   399,    -1,   423,    -1,   135,    -1,   135,   398,   157,
       3,   144,   239,   399,    -1,   207,    -1,   194,    -1,   152,
      -1,   152,   157,     3,   144,    -1,   152,   157,     3,   221,
       3,   144,    -1,    -1,   221,   388,    -1,   183,   157,   387,
     144,    -1,   205,    -1,   119,    -1,   183,    -1,    56,    -1,
       3,    -1,     3,    -1,     3,    -1,   452,    -1,     6,    -1,
      -1,   168,     3,   153,    -1,   168,     3,   221,     3,   153,
      -1,   394,    -1,   231,   394,    -1,   393,    -1,   231,   393,
      -1,   452,   390,    -1,   447,   235,   452,   390,    -1,   447,
     235,   189,    -1,   247,    -1,   452,   390,    -1,   447,   235,
     452,   390,    -1,   452,   235,   452,   235,   452,   390,    -1,
     447,   235,   189,    -1,   452,    -1,     6,    -1,   454,    -1,
       3,    -1,   412,    -1,    -1,   398,   239,   399,    -1,   211,
      -1,   188,    -1,   222,    -1,   202,    -1,   164,    -1,   171,
      -1,   133,    -1,   211,    -1,   188,    -1,   222,    -1,   202,
      -1,   164,    -1,   171,    -1,   133,    -1,   133,   157,     3,
     144,    -1,    41,   452,   157,   144,    -1,    41,   452,   157,
     441,   144,    -1,   406,    -1,   405,    -1,   402,    -1,   400,
      -1,   121,   403,   239,   403,    -1,   118,   447,   235,   404,
     239,   404,    -1,   452,    -1,   452,    -1,    96,   449,    -1,
     115,   449,   407,    -1,   110,    -1,    90,    -1,   409,    -1,
     409,   398,   239,   399,    -1,    34,    -1,   411,    -1,   411,
     398,   157,     3,   144,   239,   399,    -1,   411,   398,   239,
     399,    -1,    35,    -1,   146,   397,    -1,   190,   234,   414,
      -1,   415,    -1,   414,   221,   415,    -1,   416,   417,    -1,
       3,    -1,   392,    -1,    -1,   218,    -1,   197,    -1,   134,
     419,    -1,   420,    -1,   419,   221,   420,    -1,   392,    -1,
       3,    -1,   364,    -1,   431,    -1,   245,    -1,   245,   157,
       3,   144,    -1,   248,    -1,   248,   157,     3,   144,    -1,
      -1,    -1,   172,   433,   434,   425,   435,   426,   456,   361,
     428,   429,    -1,   172,   433,   434,   435,   361,   428,    -1,
      -1,   192,   379,   427,    -1,    -1,   413,    -1,   413,   129,
     430,   277,    -1,   129,   430,   277,    -1,   452,    -1,   172,
     433,   434,   435,   361,    -1,   157,   172,   433,   434,   435,
     361,   144,    -1,    -1,   182,     3,    -1,    -1,   215,    -1,
     132,    -1,   174,    -1,   436,    -1,   435,   221,   436,    -1,
     437,    -1,   437,   452,    -1,   437,   233,   452,    -1,   475,
      -1,   227,   475,    -1,   232,   475,    -1,   475,   198,   437,
      -1,   475,   443,    -1,   475,   189,   437,    -1,   475,   232,
     437,    -1,   475,   227,   437,    -1,   396,    -1,   178,    -1,
     155,    -1,   209,    -1,   246,    -1,   247,    -1,   245,    -1,
     189,    -1,    57,    -1,   219,   157,   378,   437,   144,    -1,
     225,   157,   378,   437,   144,    -1,   226,   157,   378,   437,
     144,    -1,   230,   157,   378,   437,   144,    -1,   181,   157,
     378,   437,   144,    -1,     4,   157,   144,    -1,     4,   157,
     441,   144,    -1,   211,   157,   441,   144,    -1,   188,   157,
     441,   144,    -1,   222,   157,   441,   144,    -1,    28,   157,
     441,   144,    -1,    29,   157,   441,   144,    -1,   212,   157,
     441,   144,    -1,   196,   157,   441,   144,    -1,   157,   437,
     144,    -1,   161,   157,   442,   144,    -1,   408,    -1,   410,
      -1,   195,   439,   241,    -1,   440,    -1,   439,   440,    -1,
     210,   364,   208,   437,    -1,   200,   437,    -1,   437,    -1,
     441,   221,   437,    -1,   146,   221,   398,   239,   399,    -1,
     468,   221,   398,   239,   399,    -1,   146,   398,   239,   399,
      -1,   437,   221,   398,   239,   399,    -1,    61,    -1,    62,
      -1,    63,    -1,    64,    -1,    65,    -1,    66,    -1,   437,
     236,   157,   445,   144,    -1,   437,   236,   432,    -1,   437,
     156,   157,   445,   144,    -1,   437,   156,   432,    -1,   446,
      -1,   445,   221,   446,    -1,   468,    -1,   396,    -1,   227,
       3,    -1,   227,   454,    -1,   448,    -1,     6,    -1,     6,
     235,   452,    -1,   452,    -1,   452,   220,   452,    -1,   452,
     220,     6,   235,   452,    -1,   452,   231,   452,    -1,   452,
     231,   452,   220,   452,    -1,   452,   231,   452,   220,     6,
     235,   452,    -1,   450,    -1,     6,   235,   452,    -1,   452,
     235,   452,    -1,     6,    -1,   452,    -1,   452,   220,   452,
      -1,   452,   220,     6,   235,   452,    -1,   452,   231,   452,
      -1,   452,   231,   452,   220,   452,    -1,   452,   231,   452,
     220,     6,   235,   452,    -1,     6,   235,   452,    -1,     6,
      -1,   452,    -1,   452,   220,   452,    -1,   452,   220,     6,
     235,   452,    -1,   452,   231,   452,    -1,   452,   231,   452,
     220,   452,    -1,   452,   231,   452,   220,     6,   235,   452,
      -1,     4,    -1,     4,    -1,    15,    -1,   235,     3,    -1,
       4,    -1,     6,    -1,    -1,   452,    -1,   460,    -1,   458,
      16,   460,    -1,   303,    -1,   252,    -1,   312,    -1,    -1,
     469,    -1,   319,    -1,   461,    -1,   467,    -1,   459,    -1,
     318,    -1,     1,    -1,   463,   464,    -1,   457,    -1,   424,
      -1,    -1,   114,    -1,   113,   465,    -1,   466,    -1,   465,
     221,   466,    -1,   452,    -1,   452,   235,   452,    -1,     6,
     235,   452,   235,   452,    -1,    99,    -1,    98,    -1,    86,
     477,    -1,    83,    -1,    79,    -1,    76,    -1,    74,    -1,
      78,    -1,   474,    -1,    17,    -1,   470,    -1,   130,   455,
     315,    -1,    20,     6,    21,    -1,   157,   471,   144,    -1,
     471,   472,   471,    -1,     3,    -1,   473,     3,    -1,   232,
      -1,   227,    -1,   189,    -1,   198,    -1,   228,    -1,   232,
      -1,   227,    -1,   452,    -1,   452,   235,   189,    -1,   452,
     235,   247,    -1,   452,   235,   452,    -1,   452,   235,   452,
     235,   452,    -1,     6,   235,   452,   235,   452,    -1,   452,
     168,   471,   153,    -1,   452,   235,   452,   168,   471,   153,
      -1,   452,   235,   452,   235,   452,   168,   471,   153,    -1,
       6,   235,   452,   235,   452,   168,   471,   153,    -1,   452,
     168,   471,   221,   471,   153,    -1,   452,   235,   452,   168,
     471,   221,   471,   153,    -1,   452,   235,   452,   235,   452,
     168,   471,   221,   471,   153,    -1,     6,   235,   452,   235,
     452,   168,   471,   221,   471,   153,    -1,   476,    -1,   476,
      73,   380,    -1,   438,    -1,   468,    -1,   432,    -1,   215,
     432,    -1,   217,   432,    -1,   206,   432,    -1,    -1,     3,
      -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   400,   400,   426,   429,   446,   451,   454,   471,   477,
     486,   495,   504,   511,   526,   581,   588,   599,   602,   607,
     614,   631,   648,   669,   678,   681,   689,   692,   700,   701,
     708,   711,   719,   722,   726,   732,   733,   737,   747,   761,
     762,   766,   767,   772,   780,   788,   796,   804,   814,   816,
     816,   819,   820,   824,   831,   838,   845,   854,   858,   865,
     877,   888,   894,   898,   902,   907,   911,   914,   918,   921,
     928,   929,   939,   940,   944,   945,   949,   958,   967,   974,
     977,   983,   986,   997,  1001,  1006,  1013,  1016,  1025,  1028,
    1032,  1036,  1040,  1044,  1048,  1056,  1060,  1068,  1071,  1078,
    1081,  1088,  1091,  1098,  1099,  1104,  1108,  1111,  1117,  1120,
    1126,  1133,  1134,  1138,  1146,  1150,  1157,  1159,  1164,  1165,
    1169,  1171,  1177,  1178,  1181,  1192,  1198,  1198,  1207,  1207,
    1216,  1241,  1244,  1252,  1255,  1262,  1265,  1273,  1274,  1280,
    1281,  1289,  1307,  1311,  1316,  1317,  1327,  1336,  1340,  1344,
    1349,  1353,  1357,  1360,  1367,  1368,  1369,  1373,  1374,  1375,
    1376,  1377,  1378,  1379,  1387,  1388,  1389,  1390,  1395,  1396,
    1397,  1400,  1401,  1402,  1406,  1407,  1408,  1412,  1413,  1417,
    1424,  1425,  1426,  1433,  1434,  1437,  1438,  1443,  1444,  1449,
    1450,  1455,  1456,  1461,  1468,  1469,  1474,  1475,  1479,  1480,
    1487,  1495,  1502,  1509,  1513,  1514,  1519,  1520,  1526,  1530,
    1535,  1542,  1543,  1549,  1552,  1555,  1562,  1563,  1564,  1565,
    1571,  1592,  1593,  1596,  1598,  1605,  1608,  1614,  1622,  1627,
    1633,  1638,  1644,  1647,  1652,  1660,  1669,  1674,  1678,  1679,
    1685,  1688,  1699,  1708,  1715,  1721,  1722,  1725,  1730,  1741,
    1745,  1752,  1753,  1757,  1761,  1765,  1772,  1777,  1785,  1788,
    1794,  1797,  1802,  1807,  1820,  1823,  1829,  1832,  1838,  1841,
    1847,  1850,  1857,  1861,  1872,  1872,  1873,  1873,  1874,  1874,
    1877,  1882,  1887,  1888,  1893,  1902,  1910,  1913,  1916,  1920,
    1927,  1930,  1934,  1937,  1940,  1943,  1949,  1956,  1959,  1962,
    1965,  1966,  1971,  1974,  1977,  1980,  1987,  1988,  1989,  1993,
    2000,  2001,  2002,  2006,  2020,  2027,  2028,  2029,  2033,  2034,
    2039,  2040,  2049,  2051,  2060,  2063,  2071,  2081,  2089,  2091,
    2092,  2093,  2094,  2095,  2096,  2097,  2105,  2106,  2107,  2108,
    2109,  2110,  2111,  2112,  2113,  2114,  2115,  2125,  2126,  2132,
    2134,  2135,  2136,  2137,  2141,  2145,  2149,  2156,  2157,  2162,
    2163,  2167,  2175,  2178,  2185,  2188,  2198,  2201,  2204,  2207,
    2214,  2221,  2229,  2238,  2245,  2249,  2250,  2251,  2252,  2257,
    2259,  2268,  2268,  2268,  2268,  2268,  2268,  2268,  2269,  2269,
    2269,  2269,  2269,  2269,  2269,  2269,  2284,  2292,  2304,  2305,
    2306,  2307,  2312,  2313,  2316,  2317,  2321,  2328,  2339,  2340,
    2353,  2354,  2358,  2362,  2363,  2366,  2372,  2376,  2399,  2409,
    2412,  2418,  2427,  2431,  2438,  2439,  2441,  2446,  2452,  2455,
    2461,  2462,  2469,  2482,  2492,  2499,  2516,  2523,  2548,  2550,
    2548,  2572,  2616,  2617,  2631,  2634,  2641,  2651,  2663,  2669,
    2682,  2697,  2699,  2705,  2706,  2707,  2708,  2718,  2721,  2727,
    2730,  2735,  2744,  2747,  2751,  2758,  2761,  2764,  2767,  2770,
    2773,  2774,  2775,  2776,  2777,  2778,  2779,  2780,  2781,  2783,
    2787,  2791,  2795,  2799,  2803,  2807,  2811,  2814,  2817,  2820,
    2823,  2826,  2829,  2832,  2835,  2839,  2843,  2847,  2855,  2858,
    2867,  2873,  2880,  2883,  2911,  2914,  2917,  2920,  2926,  2927,
    2928,  2929,  2930,  2931,  2936,  2940,  2944,  2948,  2955,  2958,
    2963,  2964,  2965,  2967,  2973,  2983,  2987,  2991,  2995,  2999,
    3003,  3007,  3011,  3019,  3029,  3034,  3038,  3042,  3046,  3050,
    3055,  3059,  3063,  3071,  3074,  3079,  3080,  3081,  3086,  3087,
    3088,  3096,  3099,  3104,  3105,  3109,  3110,  3115,  3139,  3156,
    3157,  3161,  3168,  3174,  3184,  3186,  3189,  3190,  3191,  3192,
    3194,  3197,  3201,  3206,  3210,  3216,  3217,  3220,  3225,  3226,
    3229,  3230,  3231,  3241,  3242,  3243,  3244,  3245,  3246,  3247,
    3248,  3252,  3258,  3260,  3279,  3287,  3294,  3295,  3296,  3297,
    3302,  3303,  3304,  3305,  3306,  3311,  3312,  3328,  3329,  3330,
    3331,  3332,  3333,  3334,  3335,  3336,  3337,  3339,  3340,  3341,
    3342,  3347,  3350,  3359,  3360,  3361,  3362,  3363,  3364,  3368,
    3369
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
  "LEFT_JOIN", "INNER_JOIN", "USING_BTREE", "USING_RTREE",
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
  "DOUBLE_PRECISION", "COUNT_MULTIPLY", "MODIFY_NEXT_SIZE",
  "LOCK_MODE_PAGE", "LOCK_MODE_ROW", "UNITS_YEAR", "UNITS_MONTH",
  "UNITS_DAY", "UNITS_HOUR", "UNITS_MINUTE", "UNITS_SECOND", "TO_CLUSTER",
  "TO_NOT_CLUSTER", "CREATE_UC_IDX", "CREATE_U_IDX", "CREATE_C_IDX",
  "CREATE_IDX", "DOUBLE_COLON", "SQLSICS", "CREATE_SCHEMA", "SQLSIRR",
  "UPDATESTATS_T", "SQLSICR", "SQLSIDR", "CREATE_TEMP_TABLE",
  "WITH_CHECK_OPTION", "WITH_GRANT_OPTION", "SQLSLMNW", "WHERE_CURRENT_OF",
  "NOT_NULL_UNIQUE", "SQLSLMW", "ALL_PRIVILEGES", "CREATE_SYNONYM",
  "DROP_TABLE", "INEXCLUSIVE", "UPDATESTATS", "CREATE_TABLE",
  "DEFAULT_NULL", "DEFAULT_TODAY", "DEFAULT_USER", "UNLOCK_TABLE",
  "ROLLBACK_W", "SQLSEON", "SQLSEOFF", "CREATE_VIEW", "DELETE_FROM",
  "EXTENT_SIZE", "FOREIGN_KEY", "INSERT_INTO", "IS_NOT_NULL",
  "NOT_MATCHES", "PRIMARY_KEY", "USE_SESSION", "WITH_NO_LOG", "INSHARE",
  "BEGIN_WORK", "DROP_INDEX", "FOR_UPDATE_OF", "FOR_UPDATE", "LOCK_TABLE",
  "NOT_EXISTS", "REFERENCES", "RENCOL", "SMALLFLOAT", "COMMIT_W", "RENTAB",
  "KW_CHAR", "NCHAR", "NVARCHAR", "DELIMITER", "DROP_VIEW", "EXCLUSIVE",
  "GREATER_THAN_EQ", "INTO_TEMP", "DATABASE", "DATETIME", "DISTINCT",
  "FRACTION", "GROUP_BY", "INTERVAL", "NOT_LIKE", "NOT_ILIKE", "NOT_NULL",
  "RESOURCE", "SMALLINT", "IS_NULL", "LESS_THAN_EQ", "BETWEEN",
  "CLOSE_BRACKET", "CONNECT", "KW_CURRENT", "KW_DECIMAL", "DEFAULT",
  "INTEGER", "SERIAL8", "MATCHES", "VARCHAR", "CLOSE_SQUARE",
  "GREATER_THAN", "KW_FALSE", "NOT_IN", "OPEN_BRACKET", "KW_DELETE",
  "KW_ESCAPE", "EXISTS", "EXTEND", "HAVING", "KW_INSERT", "MINUTE",
  "MODIFY", "EQUAL", "NOT_EQUAL", "OPEN_SQUARE", "PUBLIC", "REVOKE",
  "SECOND", "KW_SELECT", "SERIAL", "UNIQUE", "KW_UPDATE", "VALUES",
  "KW_NULL", "KW_TRUE", "ALTER", "CHECK", "COUNT", "KW_FIRST", "KW_FLOAT",
  "GRANT", "INDEX", "LESS_THAN", "MONEY", "MONTH", "KW_MULTIPLY", "ORDER",
  "OUTER", "UNION", "WHERE", "KW_BYTE", "CASE", "KW_DATE", "DESC",
  "KW_DIVIDE", "DROP", "ELSE", "FROM", "HOUR", "INTO", "LIKE", "REAL",
  "SOME", "KW_TEXT", "KW_THEN", "USER", "WHEN", "YEAR", "KW_DOW", "XSET",
  "ADD", "ALL", "KW_AND", "ANY", "ASC", "AVG", "COLON", "KW_COMMA", "DAY",
  "DBA", "KW_FOR", "XMAX", "XMIN", "KW_MINUS", "KW_MOD", "KW_NOT",
  "KW_SUM", "ATSIGN", "KW_PLUS", "KW_AS", "KW_BY", "KW_DOT", "KW_IN",
  "KW_ON", "KW_OR", "KW_TO", "BEFORE", "END", "TILDE", "ILIKE",
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
       0,   256,  2202,  2203,  2204,  2205,  2206,  2207,  2208,  2209,
    2210,  2211,  2212,  2213,  2214,  2215,  2216,  2217,  2218,  2219,
    2220,  2221,  1002,  1005,  1028,  1029,  1054,  1057,  1059,  1060,
    1063,  1064,  1065,  1066,  1079,  1080,  1081,  1082,  1098,  1099,
    1100,  1104,  1111,  1112,  1113,  1150,  1151,  1152,  1153,  1154,
    1157,  1158,  1160,  1161,  1162,  1163,  1172,  1173,  1193,  1194,
    1195,  1202,  1203,  1204,  1205,  1206,  1207,  1212,  1213,  1215,
    1216,  1217,  1218,  1228,  1234,  1235,  1236,  1237,  1238,  1249,
    1250,  1258,  1259,  1260,  1266,  1274,  1281,  1283,  1287,  1288,
    1290,  1295,  1321,  1322,  1323,  1324,  1337,  1345,  1347,  1348,
    1352,  1353,  1360,  1361,  1364,  1366,  1369,  1375,  1382,  1383,
    1386,  1392,  1397,  1403,  1404,  1409,  1411,  1413,  1414,  1416,
    1427,  1434,  1437,  1438,  1439,  1441,  1443,  1446,  1450,  1452,
    1476,  1477,  1479,  1486,  1488,  1489,  1491,  1492,  1493,  1499,
    1500,  1506,  1507,  1509,  1512,  1515,  1516,  1518,  1520,  1528,
    1530,  1533,  1546,  1549,  1550,  1551,  1552,  1554,  1562,  1565,
    1566,  1567,  1571,  1573,  1577,  1578,  1580,  1581,  1583,  1587,
    1591,  1595,  1599,  1600,  1603,  1605,  1606,  1609,  1610,  1612,
    1618,  1622,  1627,  1628,  1631,  1634,  1637,  1639,  1640,  1642,
    1643,  1644,  1653,  1656,  1663,  1665,  1667,  1668,  1669,  1672,
    1673,  1677,  1683,  1684,  1687,  1696,  1701,  1705,  1706,  1707,
    1709,  1712,  1713,  1715,  1716,  1717,  1718,  1719,  1720,  1721,
    1722,  1723,  1724,  1725,  1729,  1734,  1735,  1736,  1737,  1738,
    1745,  1748,  1749,  1755,  1757,  1758,  1761,  1763,  1764,  1765,
    1803,  1807,  1814,  1815,  1818,  1823,  1830,  1831,  2179,  2200,
    2201
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint16 yyr1[] =
{
       0,   251,   252,   253,   253,   253,   254,   254,   254,   255,
     255,   255,   255,   255,   255,   256,   256,   257,   257,   258,
     258,   258,   258,   259,   260,   260,   261,   261,   262,   262,
     263,   264,   264,   264,   264,   265,   265,   266,   266,   267,
     267,   268,   268,   269,   269,   269,   269,   269,   270,   271,
     271,   272,   272,   273,   273,   273,   273,   274,   275,   275,
     275,   275,   275,   275,   275,   275,   275,   275,   275,   275,
     276,   276,   277,   277,   278,   278,   279,   279,   279,   280,
     280,   281,   281,   282,   282,   282,   283,   283,   284,   284,
     284,   284,   284,   284,   284,   285,   285,   286,   286,   287,
     287,   288,   288,   289,   289,   290,   291,   291,   292,   292,
     293,   294,   294,   295,   296,   296,   297,   297,   298,   298,
     299,   299,   300,   300,   301,   302,   304,   303,   306,   305,
     305,   307,   307,   308,   308,   309,   309,   310,   310,   311,
     311,   312,   313,   314,   315,   315,   316,   317,   317,   317,
     317,   317,   317,   317,   318,   318,   318,   319,   319,   319,
     319,   319,   319,   319,   320,   320,   320,   320,   321,   321,
     321,   322,   322,   322,   323,   323,   323,   324,   324,   325,
     325,   325,   325,   325,   325,   326,   326,   327,   327,   328,
     328,   329,   329,   330,   331,   331,   332,   332,   333,   333,
     334,   335,   336,   337,   338,   338,   339,   339,   340,   340,
     340,   341,   341,   342,   342,   342,   343,   343,   343,   343,
     344,   345,   345,   346,   346,   347,   347,   348,   349,   349,
     349,   349,   349,   349,   349,   350,   351,   352,   353,   353,
     354,   354,   355,   356,   357,   358,   358,   358,   358,   358,
     358,   359,   359,   360,   360,   360,   361,   361,   362,   362,
     363,   363,   363,   363,   364,   364,   365,   365,   366,   366,
     367,   367,   368,   368,   369,   369,   370,   370,   371,   371,
     372,   373,   374,   374,   375,   375,   375,   375,   375,   375,
     375,   375,   375,   375,   375,   375,   376,   376,   376,   376,
     376,   376,   377,   377,   377,   377,   378,   378,   378,   378,
     379,   379,   379,   379,   380,   381,   381,   381,   382,   382,
     383,   383,   383,   383,   383,   383,   383,   383,   383,   383,
     383,   383,   383,   383,   383,   383,   383,   383,   383,   383,
     383,   383,   383,   383,   383,   383,   383,   384,   384,   385,
     385,   385,   385,   385,   386,   387,   388,   389,   389,   390,
     390,   390,   391,   391,   392,   392,   393,   393,   393,   393,
     394,   394,   394,   394,   395,   396,   396,   396,   396,   397,
     397,   398,   398,   398,   398,   398,   398,   398,   399,   399,
     399,   399,   399,   399,   399,   399,   400,   400,   401,   401,
     401,   401,   402,   402,   403,   404,   405,   406,   407,   407,
     408,   408,   409,   410,   410,   410,   411,   412,   413,   414,
     414,   415,   416,   416,   417,   417,   417,   418,   419,   419,
     420,   420,   421,   422,   423,   423,   423,   423,   425,   426,
     424,   427,   428,   428,   429,   429,   429,   429,   430,   431,
     432,   433,   433,   434,   434,   434,   434,   435,   435,   436,
     436,   436,   437,   437,   437,   438,   438,   438,   438,   438,
     438,   438,   438,   438,   438,   438,   438,   438,   438,   438,
     438,   438,   438,   438,   438,   438,   438,   438,   438,   438,
     438,   438,   438,   438,   438,   438,   438,   438,   439,   439,
     440,   440,   441,   441,   442,   442,   442,   442,   443,   443,
     443,   443,   443,   443,   444,   444,   444,   444,   445,   445,
     446,   446,   446,   446,   447,   448,   448,   448,   448,   448,
     448,   448,   448,   449,   450,   450,   450,   450,   450,   450,
     450,   450,   450,   451,   451,   451,   451,   451,   451,   451,
     451,   452,   453,   454,   454,   455,   455,   456,   457,   458,
     458,   459,   459,   459,   460,   460,   460,   460,   460,   460,
     460,   460,   461,   462,   463,   464,   464,   464,   465,   465,
     466,   466,   466,   467,   467,   467,   467,   467,   467,   467,
     467,   468,   468,   468,   469,   470,   471,   471,   471,   471,
     472,   472,   472,   472,   472,   473,   473,   474,   474,   474,
     474,   474,   474,   474,   474,   474,   474,   474,   474,   474,
     474,   475,   475,   476,   476,   476,   476,   476,   476,   477,
     477
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
#define YYPACT_NINF -960
static const yytype_int16 yypact[] =
{
    2347,  -960,  -960,  -960,   132,  -960,   598,   132,   132,   598,
     598,   132,   132,   605,   132,   132,   598,   605,   605,   605,
     605,  -960,   637,  -960,   132,  -960,  -960,   598,  -960,   148,
     598,   598,  -960,   598,   598,  -960,  -960,  -960,   598,   598,
    -960,  -960,   605,   598,   657,  -960,   132,   598,   680,   477,
      56,   598,   477,  -960,  -960,  -960,  -960,  -960,  -960,  -960,
    -960,  -960,  -960,  -960,  -960,  -960,  -960,  -960,  -960,  -960,
    -960,  -960,  -960,  -960,  -960,  -960,  -960,  -960,  -960,   372,
    -960,  -960,  -960,   219,  -960,  -960,  -960,   224,   124,  -960,
    -960,   215,  -960,  -960,  -960,   165,   256,   480,   163,   270,
     328,  -960,  -960,  -960,  -960,  -960,   201,   208,   223,   226,
    -960,    98,  -960,  -960,  -960,  -960,   259,  -960,  -960,   252,
    -960,   360,  -960,   364,    12,   598,  -960,   176,   289,   310,
    -960,   329,   303,  -960,  -960,  -960,  -960,   444,  -960,  -960,
    -960,  -960,  -960,   438,   438,  -960,  -960,  -960,  -960,   395,
     362,   397,  -960,   618,    10,   129,   398,   451,  -960,  2347,
     687,  -960,  -960,   695,   132,   693,   132,   132,   698,  1192,
     599,    85,   707,  -960,  -960,   279,    93,   440,   521,  -960,
    -960,  -960,  -960,  -960,  -960,  -960,  -960,   132,  -960,  -960,
     701,   132,   598,   598,   598,   598,    98,  -960,   274,   598,
     274,    99,   510,   745,   944,  -960,   604,  -960,  -960,  -960,
     132,   132,   711,   132,   132,  -960,  -960,    99,  -960,  -960,
     175,   598,   738,  -960,  -960,  -960,  -960,  -960,  1311,  1311,
    1311,  1311,    65,    65,    25,   175,   598,  -960,   530,   531,
     548,  -960,   760,  -960,   540,  -960,   571,  -960,  -960,  -960,
     639,   559,  -960,  -960,   795,   646,   650,  -960,  -960,  -960,
    -960,   436,  -960,  1425,   652,  -960,   658,   661,  -960,   288,
     666,   670,  -960,   671,   674,   670,   670,   675,   676,   678,
     679,  2124,   681,  2124,   811,  -960,  -960,  -960,  -960,  -960,
     436,  -960,   436,  -960,  -960,  -960,  -960,    26,   -36,  -960,
    -960,  -960,  -960,   428,   771,   688,   700,   703,   516,   704,
     717,  -960,  -960,  -960,   821,   132,   629,  -960,  -960,  -960,
     274,  -960,  -960,  -960,  -960,   463,   132,  -960,  -960,   274,
     638,  -960,   480,  -960,   654,  -960,   667,   724,  -960,   733,
     735,   737,  -960,    92,  -960,  -960,   115,   657,   128,  -960,
    -960,   660,   569,   728,  -960,  -960,   670,   710,   670,  1078,
     664,   696,  -960,  -960,  -960,  -960,  -960,   885,  -960,   132,
     -68,  -960,   672,  -960,   668,  -960,   689,  -960,   130,  -960,
    -960,   697,  -960,  -960,   713,  -960,  1891,  -960,   143,  -960,
    -960,   147,   699,   699,   132,  -960,  -960,   162,    36,   705,
     762,  -960,   745,   944,  -960,   697,   691,   132,   132,   687,
    -960,   132,   751,  1544,   132,   910,  1891,  1891,  -960,  -960,
    -960,  -960,  -960,  -960,  -960,  -960,   694,    56,   790,  2010,
      50,  1891,  1891,   944,   295,  -960,  1891,   766,  -960,  1891,
    1891,  -960,  -960,    50,  1891,    50,    50,   428,    50,   428,
    -960,   702,   -37,  -960,  1891,    58,    51,  -960,  -960,  -960,
    -960,  -960,  -960,  1891,  1891,  1891,  1891,  -960,   463,    99,
      99,    99,   179,   821,    99,   944,   132,  -960,   202,   132,
     209,  -960,  -960,  -960,   787,   789,   792,   436,   436,  -960,
     794,  -960,   803,   805,   808,   810,   814,  -960,  -960,  -960,
    -960,   818,   819,   665,  -960,  -960,  -960,  -960,  -960,   211,
    -960,  -960,   212,   132,  -960,   132,   772,   132,   132,   132,
     132,   859,   274,   332,  -960,  -960,    99,    69,   974,   132,
    -960,    56,   902,  -960,  -960,   -58,   626,  -960,  -960,   944,
     944,  2124,  -960,  2124,  2124,  -960,  2124,  -960,   828,  1658,
    -960,  -960,  2124,  -960,   830,  -960,  2124,   523,  1891,   235,
    -960,   759,  -960,  -960,  -960,   132,   132,   777,  -960,    99,
     175,   175,   774,  -960,    67,  -960,  1311,  -960,  -960,   832,
      65,    75,  -960,    65,  1311,  -960,   664,   175,   761,  -960,
    -960,  -960,   764,  -960,  -960,   240,   765,  -960,   241,   250,
     501,    10,  -960,   600,   788,   864,   791,  -960,  -960,  -960,
    1891,   276,  -960,     3,  -960,  -960,   278,   283,   299,  1891,
     307,  1891,  1891,  1891,   501,  1007,   501,  -960,  -960,    58,
    -960,  -960,   453,  1008,  -960,  -960,    53,  -960,  -960,  -960,
    -960,  -960,   871,   796,  -960,   313,  -960,   314,  -960,   516,
    -960,   320,   664,   872,  -960,  -960,  -960,  -960,   274,  1015,
    1015,  1016,   781,   -17,  1020,  1021,  1022,  1031,  1020,  1020,
    1032,  1035,  -960,  -960,  -960,   131,  -960,   370,  -960,   132,
    -960,   274,  -960,  -960,   807,  -960,   325,  -960,    30,   330,
     336,   337,  -960,   332,  -960,  1037,  -960,  -960,  1040,  1043,
    -960,   332,  -960,  -960,  -960,   876,   -18,   815,    10,  -960,
    -960,  -960,   696,  -960,   896,   428,   898,   900,   896,   354,
    -960,  -960,  -960,   898,   354,  -960,   900,  -960,  -960,  1891,
    -960,  -960,   132,   132,   904,  -960,  -960,   827,  -960,  -960,
    -960,   697,  1891,  -960,   132,  -960,  -960,   906,  -960,  -960,
     207,  -960,  -960,    -7,   132,   132,  -960,   132,  -960,  -960,
     908,  -960,  -960,  -960,  -960,  -960,  -960,  -960,  1891,   436,
     831,   436,  -960,   436,   922,  -960,  1891,  -960,  -960,  -960,
     923,  -960,   925,   930,   931,  -960,   932,  -960,   251,  -960,
    -960,  -960,    58,  -960,  -960,  -960,    58,  -960,    58,   132,
     960,    99,  -960,    99,  -960,   821,  -960,  -960,  -960,  -960,
     934,   939,   352,   501,  1084,   501,  -960,   867,   947,   357,
     948,   950,   867,   952,   953,  -960,  -960,  -960,  -960,   598,
    -960,  -960,  -960,   943,  -960,  -960,   370,  -960,   821,  -960,
    -960,   132,   104,   132,  -960,  -960,   104,   104,   104,   859,
    -960,  -960,  -960,  -960,  -960,  -960,  -960,  1099,   132,  1891,
     131,  -960,   131,  -960,   131,  -960,  -960,    49,  -960,   363,
    -960,  -960,  -960,   408,  -960,   887,  -960,  -960,  1777,   132,
    -960,   909,  -960,  1311,   132,  -960,  -960,   637,  -960,  -960,
    -960,   941,  1108,   146,   877,   501,   878,   879,  -960,  -960,
    -960,  -960,  -960,  -960,   880,  -960,   621,   520,   455,   955,
    -960,  -960,  -960,  -960,  -960,  -960,  -960,  1112,  -960,   976,
    -960,  1121,   982,  -960,  -960,  1126,  -960,  -960,   986,  -960,
    -960,  -960,   977,   944,  -960,  -960,  -960,  -960,  -960,  1043,
    1128,  -960,   104,  -960,  -960,  -960,  -960,  -960,  -960,   983,
     876,   146,  -960,  -960,  -960,  -960,  -960,  -960,  -960,   135,
    -960,  1891,  -960,   409,  -960,  -960,  -960,   598,   533,   945,
     411,   876,  -960,    58,   994,   997,   501,   998,   501,   501,
     501,  -960,  -960,    58,    58,   999,   905,  -960,  -960,  -960,
    1001,  -960,    99,  1002,  -960,  -960,  -960,  -960,  -960,  -960,
    -960,  -960,  -960,  1777,   142,  -960,    72,    77,   944,   944,
    -960,   -52,  -960,  -960,   985,    60,    29,  -960,  -960,   619,
    -960,  -960,  -960,  -960,  -960,  -960,   645,   631,  -960,   501,
    -960,   412,  -960,  -960,   112,   112,   127,   132,  -960,  -960,
    -960,    54,  -960,  -960,  -960,   927,  -960,   914,   673,   664,
     664,  -960,  -960,  -960,  -960,  -960,   979,   132,   918,  1025,
    -960,  -960,    58,  -960,  -960,    58,  -960,  -960,   598,   142,
     920,   921,   153,  -960,  -960,  -960,    77,    81,  -960,    56,
    -960,  1051,  -960,    84,   132,   726,   754,    91,   944,   944,
     598,  -960,  -960,  -960,   876,    10,  -960,  -960,  -960,  -960,
     946,  -960,   123,  1051,  -960,  -960,  -960,   664,   664,   100,
    -960,  1891,    84,  -960,  -960,  -960,  -960,  -960,   146,  -960,
     945,  -960
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -960,  -960,  -960,  -960,  -960,  -960,  -181,   768,   581,  -960,
    -185,  -333,  -960,  -960,  -960,  -960,   472,  -960,   467,   233,
    -127,  -960,   236,   541,  -960,   326,    74,   267,   338,   980,
    -144,  -960,  -960,   850,  -960,  -272,  -960,  -960,  -960,  -277,
    -960,  -960,  -261,  -960,  -960,  -960,  -960,  -451,  -960,   868,
     706,  -960,  -960,  -960,  -960,  -960,  -960,  -960,   452,  -960,
     183,  -960,  -960,  -960,  -960,  -960,  -960,  -960,  -960,  -960,
    1135,  -960,  1136,  -960,   970,  1049,  -960,  -198,   627,  -960,
    -960,  -960,  -960,  -960,  -960,   399,  -960,  -960,   210,  -960,
    -326,  -139,  -960,  -960,  -960,  -960,  -960,   365,  -960,  -960,
    -960,  -960,  -960,    16,   186,  -960,  -960,  -867,   168,  -763,
    -821,  -960,   193,  -203,   669,   677,   846,  -960,   488,   484,
     490,   502,  -193,  -960,  -960,  -960,  -960,   145,  -960,   743,
    -960,  -960,  -960,   392,  -960,   555,   -94,  -960,    -3,  -370,
    -176,  -959,   177,   869,   182,  -607,  -960,  -242,  -561,  -960,
    -960,  -960,  1009,   663,  -960,  -960,  -960,  -960,  -960,  -960,
    -960,  -960,  -960,  -960,   110,  -960,  -960,  -960,  -960,   149,
     296,  -960,  -960,  -960,  -960,  -960,  -960,   111,  -960,   150,
     860,  -209,  -406,  -565,  -715,   494,  -137,  -960,  -960,   798,
     553,  -960,  -960,  -960,   513,   281,   -27,  -960,    68,  -960,
     987,    -4,   839,   375,  -960,  -960,  -960,  -960,  -960,  1085,
    -960,  1228,  -960,  -960,  -960,   836,  -960,  -405,  -960,  -960,
    -559,  -960,  -960,  -960,  -115,  -960,  -960
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
     452,   395,   956,   893,   344,    86,   344,   511,    86,   481,
     128,   628,   438,   785,   252,   787,   441,   442,   826,    86,
     788,    86,   975,    86,    89,   886,    86,    94,    95,    86,
    1040,    86,  1007,   128,   105,    86,   711,  1098,    86,    86,
     128,   390,   390,   390,   390,   116,   203,    86,   119,   120,
    1004,   121,   122,    86,   531,   128,   123,   124,   562,   402,
    1008,   127,   868,  1034,  1035,   134,    86,   868,    88,   155,
     625,    91,  1034,  1035,  1099,   708,   428,   197,   937,   938,
     999,    86,   455,    88,   249,   856,    86,   825,   249,    86,
     814,   251,   224,   859,   951,   647,   252,   534,   651,   537,
     252,   117,   253,  1099,   535,   254,   239,    86,  1057,    88,
     243,   245,   246,   247,  1034,  1035,   447,   318,   449,   473,
     453,   325,   328,   325,   228,   229,   230,   231,   232,    86,
     539,   110,   607,   333,   225,   330,   335,   336,    91,    91,
      91,    91,  1053,   206,   325,    91,   325,   352,    38,   456,
     586,  1087,   626,   857,   528,   204,   371,   373,   375,   376,
     133,   776,   342,   352,   570,   629,   114,    91,   403,  1058,
     536,   798,   815,  1109,   608,   226,   887,   844,   398,   398,
     613,   114,    91,   906,  1054,  1106,   521,   907,   153,   908,
     634,   539,   315,   746,  1117,   662,   663,   454,   845,   574,
     326,   752,   918,   953,   920,   953,   163,   953,   704,   523,
     338,   338,   338,   338,   749,   609,   207,   345,    49,  1068,
    1093,   581,   525,  1073,   568,  1055,   295,   261,    86,   295,
     295,   261,    52,    86,   284,   630,   208,   575,   799,   384,
     631,   577,   604,   644,   295,   612,   394,  1120,   635,   295,
     744,  1042,   295,   295,   406,  1037,   579,   295,  1041,  1091,
    1090,   318,  1036,   522,   871,  1041,   325,   627,  1072,   871,
    1113,  1036,   328,   648,  1042,   325,   637,   638,   639,   640,
     347,  1042,   160,   161,   977,   855,   522,   188,   189,   720,
     939,  1114,   233,   352,   380,   725,   655,   967,   940,   526,
     703,   569,   868,   657,   913,   678,   680,   249,    86,   164,
     251,   770,   867,  1036,   576,   561,   284,   742,   576,   252,
     284,   253,   158,   741,   254,   528,   695,   305,   694,   731,
     885,   306,   305,   580,   756,   758,   306,   935,   159,   753,
     398,   696,   697,   739,   759,   905,  1118,   808,   187,   748,
     649,   168,   839,   588,   589,   239,   307,   591,   593,   840,
     596,   307,   722,   169,  1019,  1022,   198,  1023,  1024,  1025,
     775,   730,   777,   479,  1026,  1027,   715,   778,   715,   715,
     658,   715,   679,   681,   698,   165,   320,   715,   192,   390,
     790,   715,   884,   779,    86,   193,   166,   390,   309,   791,
     167,   781,   636,   309,   310,   827,   732,   802,   804,   310,
     194,   454,   454,   195,   806,   352,   352,   352,  1066,   842,
     352,   454,   654,   774,   846,   318,   199,   828,   793,   794,
     847,   848,   780,   795,   782,   783,   784,   829,   432,   457,
     458,   459,   460,   461,   462,   432,   916,   454,   433,   454,
     261,   924,   830,  1085,   454,   433,  1086,   958,   831,   682,
     805,   683,   685,   688,   688,   688,   688,   200,   325,   482,
     454,   201,   352,   705,   210,   707,   427,   894,   454,   896,
    1111,   897,   170,   171,   803,   803,   614,   330,   172,   173,
     174,   803,   214,   305,   832,   211,   843,   306,   190,   212,
     833,   843,   960,  1002,   871,  1017,  1067,   843,   843,   191,
     213,   373,   736,   738,   138,   352,   114,   114,   699,   418,
     745,   215,   307,   917,   821,   822,   398,   750,   925,   398,
     998,   867,   483,   114,   959,   484,   485,   486,   619,   284,
     621,   622,   875,   623,   487,   217,   220,   329,   488,   221,
     419,  1018,    86,   489,    88,   574,   789,   420,   982,    86,
     490,    98,   491,   492,   309,   493,   139,   463,   222,   305,
     310,   223,   140,   306,   421,   911,   464,   912,   727,   959,
    1003,   574,   576,   801,   760,   141,   494,   235,   422,   899,
     142,    86,   790,   110,   790,   175,   495,   423,   307,   143,
     496,   791,   144,   791,   325,   465,   145,   497,   424,   498,
     466,    86,   146,   128,   728,   761,   729,  1007,   499,   954,
     500,   955,   762,  1095,   792,   328,   983,   325,  1078,   176,
     793,   794,   793,   794,   135,   795,   136,   795,   236,   763,
     309,    86,   147,   238,   177,  1008,   310,    86,   970,   244,
     148,   242,   305,   764,   248,    86,   306,   334,   501,   790,
     319,   502,   765,   249,   250,    86,   251,   374,   791,   945,
     946,   947,   574,   766,  1110,   252,  1009,   253,   561,   877,
     254,   307,   541,   418,   339,   340,   341,   528,   255,   256,
     882,   965,   332,   353,   257,   258,   390,   793,   794,   354,
     889,   890,   795,   891,   542,    86,   308,   592,   672,   673,
     674,   369,   543,   544,   419,   407,   408,   259,   545,   409,
     602,   420,  1061,   309,   981,   411,    86,   546,   684,   310,
     547,    86,   548,   737,  1064,   689,   690,   691,   421,   212,
     410,   412,   549,   550,   414,   909,   413,   352,  1063,   352,
     213,   415,   422,   416,   529,  1049,  1050,   417,   790,   429,
     790,   423,   551,   675,   450,   430,   644,   791,   431,   791,
     790,   769,   424,   436,  1001,    91,   356,   437,   439,   791,
     552,   440,   443,   444,   790,   445,   446,   936,   448,   688,
    1062,   528,  -305,   791,   468,   469,   793,   794,   793,   794,
     479,   795,  1065,   795,   950,   553,   261,   470,   793,   794,
     471,   474,   554,   795,  -305,   262,   965,   357,   555,   556,
     358,   264,   793,   794,   475,   966,   476,   795,   513,  1104,
     971,   517,   427,   114,   972,  1107,  1108,   516,   265,   515,
     518,   266,   519,   212,   520,   527,   141,   932,   267,   268,
     531,   142,   539,   566,   213,   269,   270,  1105,  -527,   567,
     143,   565,   540,   144,   571,   790,   271,   145,   570,   272,
     576,   273,   274,   146,   791,   275,   583,   276,   584,   277,
     587,   597,   278,   600,   602,   279,   280,   281,   427,   359,
     282,   624,   283,   790,   659,   284,   660,   249,   250,   661,
     251,   664,   791,   793,   794,   285,   286,   287,   795,   252,
     665,   253,   666,    91,   254,   667,   595,   668,   692,   598,
     599,   669,   255,   256,   574,   670,   671,   706,   257,   258,
    1047,   793,   794,   709,   611,   719,   795,   724,   352,   616,
    -282,   541,   617,   618,   733,   742,   754,   620,   747,   755,
     757,   259,  1039,  1048,   106,   107,   108,   109,   772,   771,
     786,   797,   773,   542,  1047,   800,   807,   801,   809,   812,
     813,   543,   544,   816,   818,   819,  -282,   545,  -282,   126,
      91,    91,    91,  1039,   820,   823,   546,  1048,   824,   547,
     850,   548,   841,   851,   528,   716,   717,   852,   718,  1047,
     858,   549,   550,  1082,   723,   860,  1047,   862,   726,   864,
     356,   878,   879,   883,    91,   892,   898,   900,    91,   901,
     895,   551,  1048,  1094,   902,   903,   904,   829,   914,  1048,
    1082,   249,   250,   915,   251,  1047,    91,   919,   921,   552,
     261,   923,   926,   252,   927,   253,   929,   930,   254,   262,
     933,   357,   949,   961,   358,   264,   255,   256,  1048,   973,
     967,   974,   257,   258,   553,   985,   976,   978,   979,   980,
     986,   554,   265,   984,   987,   266,   989,   555,   556,   990,
     991,   995,   267,   268,   992,   259,   997,  1015,  1020,   269,
     270,  1021,  -506,  1028,  1029,  1030,  1032,  1008,  1076,  1077,
     271,  1079,  1083,   272,  1084,   273,   274,  1088,  1089,   275,
    1096,   276,   578,   277,   751,   849,   278,  1112,   854,   279,
     280,   281,   994,   359,   282,   948,   283,  1116,   996,   284,
     346,   944,   514,   478,   876,   656,  1033,   156,   157,   285,
     286,   287,   385,   219,   356,   249,   250,   740,   251,   910,
    1052,   934,  1031,  1071,  1051,   538,   866,   252,   712,   253,
     874,   641,   254,   872,   928,   811,   524,   713,  1075,  1074,
     255,   256,  1119,   377,   261,  1092,   257,   258,   735,   993,
     564,  1121,   615,   262,  1103,   357,   880,   873,   358,   264,
    1000,   585,   957,   104,   237,   590,     0,     0,     0,   259,
       0,     0,     0,     0,     0,     0,   265,     0,     0,   266,
       0,     0,     0,     0,     0,     0,   267,   268,     0,     0,
       0,     0,     0,   269,   270,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   271,     0,     0,   272,     0,   273,
     274,     0,     0,   275,     0,   276,     0,   277,     0,     0,
     278,     0,     0,   279,   280,   281,     0,     0,   282,     0,
     283,     0,     0,   284,   249,   250,     0,   251,     0,     0,
       0,     0,     0,   285,   286,   287,   252,     0,   253,     0,
       0,   254,     0,     0,     0,     0,   260,     0,   261,   255,
     256,     0,     0,     0,     0,   257,   258,   262,     0,   263,
       0,     0,     0,   264,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   259,     0,
     265,     0,     0,   266,     0,     0,     0,     0,     0,     0,
     267,   268,     0,     0,     0,     0,     0,   269,   270,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   271,     0,
       0,   272,     0,   273,   274,     0,     0,   275,     0,   276,
       0,   277,     0,     0,   278,     0,     0,   279,   280,   281,
       0,     0,   282,     0,   283,     0,     0,   284,   249,   250,
       0,   251,     0,     0,     0,     0,     0,   285,   286,   287,
     252,     0,   253,     0,     0,   254,     0,     0,     0,     0,
       0,     0,     0,   255,   256,     0,     0,   261,     0,   257,
     258,     0,     0,     0,     0,     0,   262,     0,   263,     0,
       0,     0,   264,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   259,     0,     0,     0,     0,     0,   387,   265,
       0,     0,   266,     0,     0,     0,     0,     0,     0,   267,
     268,     0,     0,     0,     0,     0,   269,   270,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   271,     0,     0,
     272,     0,   273,   274,     0,     0,   275,     0,   276,     0,
     277,     0,     0,   278,     0,     0,   279,   280,   281,     0,
       0,   282,     0,   283,     0,     0,   284,   249,   250,     0,
     251,     0,     0,     0,     0,     0,   285,   286,   287,   252,
       0,   253,     0,     0,   254,     0,     0,     0,     0,     0,
       0,   261,   255,   256,     0,     0,     0,     0,   257,   258,
     262,     0,   263,     0,     0,     0,   264,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   427,     0,     0,
       0,   259,     0,   265,     0,     0,   266,     0,     0,     0,
       0,     0,     0,   267,   268,     0,     0,     0,     0,     0,
     269,   270,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   271,     0,     0,   272,     0,   273,   274,     0,     0,
     275,     0,   276,     0,   277,     0,     0,   278,     0,     0,
     279,   280,   281,     0,     0,   282,     0,   283,     0,     0,
     284,   249,   250,     0,   251,     0,     0,     0,     0,     0,
     285,   286,   287,   252,     0,   253,     0,     0,   254,     0,
       0,     0,     0,     0,     0,     0,   255,   256,   594,     0,
     261,     0,   257,   258,     0,     0,     0,     0,     0,   262,
       0,   263,     0,     0,     0,   264,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   259,     0,     0,     0,     0,
       0,     0,   265,     0,     0,   266,     0,     0,     0,     0,
       0,     0,   267,   268,     0,     0,     0,     0,     0,   269,
     270,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     271,     0,     0,   272,     0,   273,   274,     0,     0,   275,
       0,   276,     0,   277,     0,     0,   278,     0,     0,   279,
     280,   281,     0,     0,   282,     0,   283,     0,     0,   284,
     249,   250,     0,   251,     0,     0,     0,     0,     0,   285,
     286,   287,   252,     0,   253,     0,     0,   254,     0,     0,
       0,     0,     0,     0,   261,   255,   256,     0,     0,     0,
       0,   257,   258,   262,     0,   263,     0,     0,     0,   264,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   259,   721,   265,     0,     0,   266,
       0,     0,     0,     0,     0,     0,   267,   268,     0,     0,
       0,     0,     0,   269,   270,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   271,     0,     0,   272,     0,   273,
     274,     0,     0,   275,     0,   276,     0,   277,     0,     0,
     278,     0,     0,   279,   280,   281,     0,     0,   282,     0,
     283,     0,     0,   284,   249,   250,     0,   251,     0,     0,
       0,     0,     0,   285,   286,   287,   252,     0,   253,     0,
       0,   254,     0,     0,     0,     0,     0,     0,     0,   255,
     256,     0,     0,   261,     0,   257,   258,     0,     0,     0,
       0,     0,   262,     0,   263,     0,     0,     0,   264,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   259,     0,
       0,     0,     0,     0,   962,   265,     0,     0,   266,     0,
       0,     0,     0,     0,     0,   267,   268,     0,     0,     0,
       0,     0,   269,   270,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   271,     0,     0,   272,     0,   273,   274,
       0,     0,   275,     0,   276,     0,   277,     0,     0,   278,
       0,     0,   279,   280,   281,     0,     0,   282,     0,   283,
       0,     0,   284,   249,   250,     0,   251,     0,     0,     0,
       0,     0,   285,   286,   287,   252,     0,   253,     0,     0,
     254,     0,     0,     0,     0,     0,     0,   261,   255,   256,
       0,     0,     0,     0,   257,   258,   262,     0,   263,     0,
       0,     0,   264,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   259,     0,   265,
       0,     0,   266,     0,     0,     0,     0,     0,     0,   267,
     268,     0,     0,     0,     0,     0,   269,   270,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   271,     0,     0,
     272,     0,   273,   274,     0,     0,   275,     0,   276,     0,
     277,     0,     0,   278,     0,     0,   279,   280,   281,     0,
       0,   282,     0,   283,     0,     0,   284,   249,   250,     0,
     251,     0,     0,     0,     0,     0,   285,   286,   287,   252,
       0,   253,     0,     0,   254,     0,     0,     0,     0,     0,
       0,     0,   255,   256,     0,     0,   603,     0,   257,   258,
       0,     0,     0,     0,     0,   262,     0,   263,     0,     0,
       0,   264,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   259,     0,     0,     0,     0,     0,     0,   265,     0,
       0,   266,     0,     0,     0,     0,     0,     0,   267,   268,
       0,     0,     0,     0,     0,   269,   270,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   271,     0,     0,   272,
       0,   273,   274,     0,     0,   275,     0,   276,     0,   277,
       0,     0,   278,     0,     0,   279,   280,   281,     0,     0,
     282,     0,   283,     0,     0,   284,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   285,   286,   287,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     261,     0,     0,     0,     0,     0,     0,     0,     0,   262,
       0,   263,     0,     0,     0,   264,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   265,     0,     0,   266,     0,     0,     0,     0,
       0,     0,   267,   268,     0,     0,     0,     0,     0,   269,
     270,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     271,     0,     0,   272,     0,   273,   274,     0,     0,   275,
       0,   276,     0,   277,     0,     0,   278,  -564,     1,   279,
     280,     0,     0,     0,   282,     0,     0,     0,     0,   284,
       0,     0,     0,  -564,     0,     0,     0,     0,     0,   285,
     286,   287,     0,     2,     3,     0,     0,     0,     4,     0,
       5,     0,     0,     6,     7,     8,     9,    10,    11,    12,
      13,     0,     0,     0,     0,     0,     0,    14,    15,     0,
       0,    16,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    17,    18,    19,    20,
       0,    21,    22,    23,    24,    25,    26,    27,     0,     0,
      28,     0,     0,    29,     0,    30,    31,     0,    32,    33,
       0,     0,     0,    34,    35,    36,    37,    38,    39,     0,
       0,    40,     0,     0,     0,     0,     0,     0,    41,    42,
       0,     0,    43,     0,     0,    44,     0,    45,    46,     0,
       0,     0,     0,    47,     0,     0,     0,    48,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    49,     0,    50,
       0,     0,    51,     0,     0,     0,     0,     0,     0,     0,
       0,    52
};

static const yytype_int16 yycheck[] =
{
       4,   204,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    44,    22,    22,
      24,   427,   473,    27,   429,   201,    30,    31,   398,    33,
      34,   170,   169,   177,    38,    39,   601,   235,    42,    43,
      44,   217,    46,    47,   229,   230,   231,    51,   290,   326,
     292,   232,     3,   768,   198,     4,   200,   329,     4,   320,
       6,     3,   271,   624,    15,   626,   275,   276,   675,     4,
     629,     4,   893,     4,     6,    82,     4,     9,    10,     4,
       3,     4,   134,     6,    16,     4,   144,     3,     4,     4,
       6,   228,   229,   230,   231,    27,    84,     4,    30,    31,
     967,    33,    34,     4,   172,     6,    38,    39,   176,    84,
     162,    43,   719,    22,    23,    47,     4,   724,     6,    51,
     157,   125,    22,    23,  1083,   531,   263,   111,    24,    25,
     951,     4,   168,     6,     3,   153,     4,     6,     3,     4,
     157,     6,   132,   708,   859,   471,    15,   356,   474,   358,
      15,     3,    17,  1112,   357,    20,   160,     4,   129,     6,
     164,   165,   166,   167,    22,    23,   281,   171,   283,   308,
     144,   175,   176,   177,    45,    46,    47,    48,    49,     4,
     238,     6,   132,   187,   174,   329,   190,   191,   192,   193,
     194,   195,   132,   125,   198,   199,   200,   201,   100,   235,
     403,  1068,   239,   221,   168,   193,   210,   211,   212,   213,
     214,   208,   196,   217,   221,   157,   220,   221,   193,   190,
     357,   168,   239,  1090,   174,   215,   233,   197,   232,   233,
     433,   235,   236,   792,   174,   144,   144,   796,   182,   798,
     189,   238,   157,   576,   144,   487,   488,   221,   218,   386,
     157,   584,   813,   860,   815,   862,    32,   864,   189,   144,
     192,   193,   194,   195,   189,   215,    90,   199,   170,   157,
     189,   235,   144,  1036,   144,   215,   413,   146,     4,   416,
     417,   146,   184,     4,   235,   227,   110,   144,   235,   221,
     232,   144,   429,   469,   431,   432,   231,  1118,   247,   436,
     233,   247,   439,   440,   236,   233,   144,   444,   231,  1072,
     157,   315,   221,   221,   719,   231,   320,   454,   191,   724,
     197,   221,   326,   144,   247,   329,   463,   464,   465,   466,
     231,   247,   113,   114,   895,   705,   221,    67,    68,   548,
     236,   218,   213,   347,   169,   554,   144,   201,   244,   221,
     526,   221,   959,   144,   805,   144,   144,     3,     4,   235,
       6,   603,   227,   221,   221,   369,   235,   221,   221,    15,
     235,    17,     0,   571,    20,   168,    44,   103,   522,   144,
     750,   107,   103,   221,   144,   144,   107,   838,    16,   587,
     394,    59,    60,   569,   144,   144,  1111,   658,   235,   580,
     221,   236,   679,   407,   408,   409,   132,   411,   412,   681,
     414,   132,   549,   157,   973,   976,   157,   978,   979,   980,
     144,   558,   144,   221,   983,   984,   541,   144,   543,   544,
     221,   546,   221,   221,   102,   220,   157,   552,   237,   576,
     189,   556,   235,   144,     4,   237,   231,   584,   174,   198,
     235,   144,   456,   174,   180,    85,   221,   144,   144,   180,
     237,   221,   221,   237,   144,   469,   470,   471,  1029,   144,
     474,   221,   476,   610,   144,   479,   224,   107,   227,   228,
     144,   144,   619,   232,   621,   622,   623,   117,   200,    61,
      62,    63,    64,    65,    66,   200,   144,   221,   210,   221,
     146,   144,   132,  1062,   221,   210,  1065,   144,   138,   513,
     649,   515,   516,   517,   518,   519,   520,   157,   522,    56,
     221,   157,   526,   527,   235,   529,   172,   769,   221,   771,
    1095,   773,    52,    53,   221,   221,   241,   681,    58,    59,
      60,   221,   239,   103,   174,   235,   221,   107,   220,   220,
     180,   221,   144,   144,   959,   144,   144,   221,   221,   231,
     231,   565,   566,   567,    87,   569,   570,   571,   236,   133,
     574,   127,   132,   221,   668,   669,   580,   581,   221,   583,
     950,   227,   119,   587,   221,   122,   123,   124,   443,   235,
     445,   446,   729,   448,   131,   157,   201,   157,   135,   237,
     164,   971,     4,   140,     6,   742,   153,   171,   153,     4,
     147,     6,   149,   150,   174,   152,   139,   189,   221,   103,
     180,     3,   145,   107,   188,   801,   198,   803,   105,   221,
     221,   768,   221,   221,   133,   158,   173,   239,   202,   776,
     163,     4,   189,     6,   189,   165,   183,   211,   132,   172,
     187,   198,   175,   198,   658,   227,   179,   194,   222,   196,
     232,     4,   185,     6,   141,   164,   143,   134,   205,   862,
     207,   864,   171,  1079,   221,   679,   221,   681,  1048,   199,
     227,   228,   227,   228,     4,   232,     6,   232,   237,   188,
     174,     4,   215,     6,   214,   162,   180,     4,   883,     6,
     223,     6,   103,   202,     6,     4,   107,     6,   245,   189,
       3,   248,   211,     3,     4,     4,     6,     6,   198,   846,
     847,   848,   859,   222,  1094,    15,   193,    17,   732,   733,
      20,   132,   106,   133,   193,   194,   195,   168,    28,    29,
     744,   878,   221,   233,    34,    35,   883,   227,   228,     4,
     754,   755,   232,   757,   128,     4,   157,     6,    93,    94,
      95,   157,   136,   137,   164,   235,   235,    57,   142,   221,
     144,   171,   153,   174,   153,   235,     4,   151,     6,   180,
     154,     4,   156,     6,   153,   518,   519,   520,   188,   220,
      30,   220,   166,   167,   235,   799,   157,   801,   153,   803,
     231,     6,   202,   157,   235,  1008,  1009,   157,   189,   157,
     189,   211,   186,   148,     3,   157,   992,   198,   157,   198,
     189,   221,   222,   157,   961,   829,   116,   157,   157,   198,
     204,   157,   157,   157,   189,   157,   157,   841,   157,   843,
     221,   168,   216,   198,    73,   157,   227,   228,   227,   228,
     221,   232,   221,   232,   858,   229,   146,   157,   227,   228,
     157,   157,   236,   232,   238,   155,  1003,   157,   242,   243,
     160,   161,   227,   228,   157,   879,    55,   232,   240,   153,
     884,   157,   172,   887,   887,  1088,  1089,   220,   178,   235,
     157,   181,   157,   220,   157,   235,   158,   829,   188,   189,
     172,   163,   238,   235,   231,   195,   196,   153,   235,   220,
     172,   239,   216,   175,   201,   189,   206,   179,   221,   209,
     221,   211,   212,   185,   198,   215,   221,   217,   166,   219,
     239,    21,   222,   239,   144,   225,   226,   227,   172,   229,
     230,   239,   232,   189,   157,   235,   157,     3,     4,   157,
       6,   157,   198,   227,   228,   245,   246,   247,   232,    15,
     157,    17,   157,   967,    20,   157,   413,   157,   109,   416,
     417,   157,    28,    29,  1111,   157,   157,     3,    34,    35,
    1007,   227,   228,    81,   431,   157,   232,   157,   992,   436,
     105,   106,   439,   440,   235,   221,   235,   444,   166,   235,
     235,    57,  1006,  1007,    17,    18,    19,    20,   144,   221,
       3,     3,   221,   128,  1041,   144,   144,   221,     3,     3,
     239,   136,   137,     3,     3,     3,   141,   142,   143,    42,
    1034,  1035,  1036,  1037,     3,     3,   151,  1041,     3,   154,
       3,   156,   235,     3,   168,   543,   544,     4,   546,  1076,
     235,   166,   167,  1057,   552,   159,  1083,   159,   556,   159,
     116,   157,   235,   157,  1068,   157,   144,   144,  1072,   144,
     239,   186,  1076,  1077,   144,   144,   144,   117,   144,  1083,
    1084,     3,     4,   144,     6,  1112,  1090,     3,   221,   204,
     146,   144,   144,    15,   144,    17,   144,   144,    20,   155,
     157,   157,     3,   216,   160,   161,    28,    29,  1112,   168,
     201,     3,    34,    35,   229,     3,   239,   239,   239,   239,
     144,   236,   178,   168,     3,   181,   144,   242,   243,     3,
     144,     3,   188,   189,   157,    57,   153,   192,   144,   195,
     196,   144,   144,   144,   239,   144,   144,   162,   221,   235,
     206,   172,   234,   209,   129,   211,   212,   237,   237,   215,
     109,   217,   394,   219,   583,   693,   222,   221,   701,   225,
     226,   227,   939,   229,   230,   849,   232,  1103,   942,   235,
     200,   843,   332,   315,   732,   479,  1003,    52,    52,   245,
     246,   247,   222,   144,   116,     3,     4,   570,     6,   800,
    1014,   836,   992,  1035,  1011,   359,   718,    15,   539,    17,
     726,   468,    20,   723,   822,   660,   347,   540,  1041,  1037,
      28,    29,  1112,   214,   146,  1076,    34,    35,   565,   933,
     370,  1120,   434,   155,  1084,   157,   742,   724,   160,   161,
     959,   402,   867,    15,   159,   409,    -1,    -1,    -1,    57,
      -1,    -1,    -1,    -1,    -1,    -1,   178,    -1,    -1,   181,
      -1,    -1,    -1,    -1,    -1,    -1,   188,   189,    -1,    -1,
      -1,    -1,    -1,   195,   196,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   206,    -1,    -1,   209,    -1,   211,
     212,    -1,    -1,   215,    -1,   217,    -1,   219,    -1,    -1,
     222,    -1,    -1,   225,   226,   227,    -1,    -1,   230,    -1,
     232,    -1,    -1,   235,     3,     4,    -1,     6,    -1,    -1,
      -1,    -1,    -1,   245,   246,   247,    15,    -1,    17,    -1,
      -1,    20,    -1,    -1,    -1,    -1,   144,    -1,   146,    28,
      29,    -1,    -1,    -1,    -1,    34,    35,   155,    -1,   157,
      -1,    -1,    -1,   161,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    57,    -1,
     178,    -1,    -1,   181,    -1,    -1,    -1,    -1,    -1,    -1,
     188,   189,    -1,    -1,    -1,    -1,    -1,   195,   196,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   206,    -1,
      -1,   209,    -1,   211,   212,    -1,    -1,   215,    -1,   217,
      -1,   219,    -1,    -1,   222,    -1,    -1,   225,   226,   227,
      -1,    -1,   230,    -1,   232,    -1,    -1,   235,     3,     4,
      -1,     6,    -1,    -1,    -1,    -1,    -1,   245,   246,   247,
      15,    -1,    17,    -1,    -1,    20,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    28,    29,    -1,    -1,   146,    -1,    34,
      35,    -1,    -1,    -1,    -1,    -1,   155,    -1,   157,    -1,
      -1,    -1,   161,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    57,    -1,    -1,    -1,    -1,    -1,   177,   178,
      -1,    -1,   181,    -1,    -1,    -1,    -1,    -1,    -1,   188,
     189,    -1,    -1,    -1,    -1,    -1,   195,   196,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   206,    -1,    -1,
     209,    -1,   211,   212,    -1,    -1,   215,    -1,   217,    -1,
     219,    -1,    -1,   222,    -1,    -1,   225,   226,   227,    -1,
      -1,   230,    -1,   232,    -1,    -1,   235,     3,     4,    -1,
       6,    -1,    -1,    -1,    -1,    -1,   245,   246,   247,    15,
      -1,    17,    -1,    -1,    20,    -1,    -1,    -1,    -1,    -1,
      -1,   146,    28,    29,    -1,    -1,    -1,    -1,    34,    35,
     155,    -1,   157,    -1,    -1,    -1,   161,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   172,    -1,    -1,
      -1,    57,    -1,   178,    -1,    -1,   181,    -1,    -1,    -1,
      -1,    -1,    -1,   188,   189,    -1,    -1,    -1,    -1,    -1,
     195,   196,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   206,    -1,    -1,   209,    -1,   211,   212,    -1,    -1,
     215,    -1,   217,    -1,   219,    -1,    -1,   222,    -1,    -1,
     225,   226,   227,    -1,    -1,   230,    -1,   232,    -1,    -1,
     235,     3,     4,    -1,     6,    -1,    -1,    -1,    -1,    -1,
     245,   246,   247,    15,    -1,    17,    -1,    -1,    20,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    28,    29,   144,    -1,
     146,    -1,    34,    35,    -1,    -1,    -1,    -1,    -1,   155,
      -1,   157,    -1,    -1,    -1,   161,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    57,    -1,    -1,    -1,    -1,
      -1,    -1,   178,    -1,    -1,   181,    -1,    -1,    -1,    -1,
      -1,    -1,   188,   189,    -1,    -1,    -1,    -1,    -1,   195,
     196,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     206,    -1,    -1,   209,    -1,   211,   212,    -1,    -1,   215,
      -1,   217,    -1,   219,    -1,    -1,   222,    -1,    -1,   225,
     226,   227,    -1,    -1,   230,    -1,   232,    -1,    -1,   235,
       3,     4,    -1,     6,    -1,    -1,    -1,    -1,    -1,   245,
     246,   247,    15,    -1,    17,    -1,    -1,    20,    -1,    -1,
      -1,    -1,    -1,    -1,   146,    28,    29,    -1,    -1,    -1,
      -1,    34,    35,   155,    -1,   157,    -1,    -1,    -1,   161,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    57,   177,   178,    -1,    -1,   181,
      -1,    -1,    -1,    -1,    -1,    -1,   188,   189,    -1,    -1,
      -1,    -1,    -1,   195,   196,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   206,    -1,    -1,   209,    -1,   211,
     212,    -1,    -1,   215,    -1,   217,    -1,   219,    -1,    -1,
     222,    -1,    -1,   225,   226,   227,    -1,    -1,   230,    -1,
     232,    -1,    -1,   235,     3,     4,    -1,     6,    -1,    -1,
      -1,    -1,    -1,   245,   246,   247,    15,    -1,    17,    -1,
      -1,    20,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    28,
      29,    -1,    -1,   146,    -1,    34,    35,    -1,    -1,    -1,
      -1,    -1,   155,    -1,   157,    -1,    -1,    -1,   161,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    57,    -1,
      -1,    -1,    -1,    -1,   177,   178,    -1,    -1,   181,    -1,
      -1,    -1,    -1,    -1,    -1,   188,   189,    -1,    -1,    -1,
      -1,    -1,   195,   196,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   206,    -1,    -1,   209,    -1,   211,   212,
      -1,    -1,   215,    -1,   217,    -1,   219,    -1,    -1,   222,
      -1,    -1,   225,   226,   227,    -1,    -1,   230,    -1,   232,
      -1,    -1,   235,     3,     4,    -1,     6,    -1,    -1,    -1,
      -1,    -1,   245,   246,   247,    15,    -1,    17,    -1,    -1,
      20,    -1,    -1,    -1,    -1,    -1,    -1,   146,    28,    29,
      -1,    -1,    -1,    -1,    34,    35,   155,    -1,   157,    -1,
      -1,    -1,   161,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    57,    -1,   178,
      -1,    -1,   181,    -1,    -1,    -1,    -1,    -1,    -1,   188,
     189,    -1,    -1,    -1,    -1,    -1,   195,   196,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   206,    -1,    -1,
     209,    -1,   211,   212,    -1,    -1,   215,    -1,   217,    -1,
     219,    -1,    -1,   222,    -1,    -1,   225,   226,   227,    -1,
      -1,   230,    -1,   232,    -1,    -1,   235,     3,     4,    -1,
       6,    -1,    -1,    -1,    -1,    -1,   245,   246,   247,    15,
      -1,    17,    -1,    -1,    20,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    28,    29,    -1,    -1,   146,    -1,    34,    35,
      -1,    -1,    -1,    -1,    -1,   155,    -1,   157,    -1,    -1,
      -1,   161,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    57,    -1,    -1,    -1,    -1,    -1,    -1,   178,    -1,
      -1,   181,    -1,    -1,    -1,    -1,    -1,    -1,   188,   189,
      -1,    -1,    -1,    -1,    -1,   195,   196,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   206,    -1,    -1,   209,
      -1,   211,   212,    -1,    -1,   215,    -1,   217,    -1,   219,
      -1,    -1,   222,    -1,    -1,   225,   226,   227,    -1,    -1,
     230,    -1,   232,    -1,    -1,   235,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   245,   246,   247,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     146,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   155,
      -1,   157,    -1,    -1,    -1,   161,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   178,    -1,    -1,   181,    -1,    -1,    -1,    -1,
      -1,    -1,   188,   189,    -1,    -1,    -1,    -1,    -1,   195,
     196,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     206,    -1,    -1,   209,    -1,   211,   212,    -1,    -1,   215,
      -1,   217,    -1,   219,    -1,    -1,   222,     0,     1,   225,
     226,    -1,    -1,    -1,   230,    -1,    -1,    -1,    -1,   235,
      -1,    -1,    -1,    16,    -1,    -1,    -1,    -1,    -1,   245,
     246,   247,    -1,    26,    27,    -1,    -1,    -1,    31,    -1,
      33,    -1,    -1,    36,    37,    38,    39,    40,    41,    42,
      43,    -1,    -1,    -1,    -1,    -1,    -1,    50,    51,    -1,
      -1,    54,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    69,    70,    71,    72,
      -1,    74,    75,    76,    77,    78,    79,    80,    -1,    -1,
      83,    -1,    -1,    86,    -1,    88,    89,    -1,    91,    92,
      -1,    -1,    -1,    96,    97,    98,    99,   100,   101,    -1,
      -1,   104,    -1,    -1,    -1,    -1,    -1,    -1,   111,   112,
      -1,    -1,   115,    -1,    -1,   118,    -1,   120,   121,    -1,
      -1,    -1,    -1,   126,    -1,    -1,    -1,   130,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   170,    -1,   172,
      -1,    -1,   175,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   184
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
{
       0,     1,    26,    27,    31,    33,    36,    37,    38,    39,
      40,    41,    42,    43,    50,    51,    54,    69,    70,    71,
      72,    74,    75,    76,    77,    78,    79,    80,    83,    86,
      88,    89,    91,    92,    96,    97,    98,    99,   100,   101,
     104,   111,   112,   115,   118,   120,   121,   126,   130,   170,
     172,   175,   184,   252,   263,   264,   265,   266,   275,   282,
     302,   303,   312,   313,   314,   316,   317,   318,   319,   320,
     330,   350,   354,   400,   401,   402,   405,   406,   424,   458,
     459,   460,   461,   463,   467,   469,     4,   452,     6,   449,
     450,   452,   452,   452,   449,   449,   452,   452,     6,   451,
     452,   452,   457,   462,   462,   449,   451,   451,   451,   451,
       6,   351,   352,   389,   452,   452,   449,     3,   477,   449,
     449,   449,   449,   449,   449,   304,   451,   449,     6,   447,
     448,   452,   403,   452,   449,     4,     6,   455,    87,   139,
     145,   158,   163,   172,   175,   179,   185,   215,   223,   321,
     323,   324,   325,   182,   433,   449,   321,   323,     0,    16,
     113,   114,   464,    32,   235,   220,   231,   235,   236,   157,
      52,    53,    58,    59,    60,   165,   199,   214,   283,   284,
     285,   288,   291,   294,   295,   296,   299,   235,    67,    68,
     220,   231,   237,   237,   237,   237,   353,   354,   157,   224,
     157,   157,   331,    84,   193,   254,   449,    90,   110,   407,
     235,   235,   220,   231,   239,   127,   315,   157,   326,   326,
     201,   237,   221,     3,   132,   174,   215,   434,    45,    46,
      47,    48,    49,   213,   255,   239,   237,   460,     6,   452,
     465,   466,     6,   452,     6,   452,   452,   452,     6,     3,
       4,     6,    15,    17,    20,    28,    29,    34,    35,    57,
     144,   146,   155,   157,   161,   178,   181,   188,   189,   195,
     196,   206,   209,   211,   212,   215,   217,   219,   222,   225,
     226,   227,   230,   232,   235,   245,   246,   247,   396,   408,
     409,   410,   411,   412,   432,   437,   438,   441,   452,   454,
     468,   470,   474,   475,   476,   103,   107,   132,   157,   174,
     180,   334,   335,   340,   342,   157,   300,   301,   452,     3,
     157,   281,   293,   342,   344,   452,   157,   290,   452,   157,
     281,   286,   221,   452,     6,   452,   452,   274,   449,   274,
     274,   274,   354,   280,   281,   449,   280,   231,   332,   391,
     394,   447,   452,   233,     4,   453,   116,   157,   160,   229,
     364,   365,   366,   367,   368,   375,   377,   437,   444,   157,
     307,   452,   404,   452,     6,   452,   452,   403,   327,   391,
     169,   328,   329,   389,   449,   325,   425,   177,   261,   262,
     437,   261,   261,   261,   231,   257,   258,   260,   452,   256,
     257,   259,    84,   193,   253,   328,   449,   235,   235,   221,
      30,   235,   220,   157,   235,     6,   157,   157,   133,   164,
     171,   188,   202,   211,   222,   397,   398,   172,   437,   157,
     157,   157,   200,   210,   439,   440,   157,   157,   432,   157,
     157,   432,   432,   157,   157,   157,   157,   475,   157,   475,
       3,   398,   398,   144,   221,   168,   235,    61,    62,    63,
      64,    65,    66,   189,   198,   227,   232,   443,    73,   157,
     157,   157,   297,   342,   157,   157,    55,   298,   300,   221,
     292,   293,    56,   119,   122,   123,   124,   131,   135,   140,
     147,   149,   150,   152,   173,   183,   187,   194,   196,   205,
     207,   245,   248,   380,   381,   382,   383,   385,   423,   289,
     290,   286,   287,   240,   284,   235,   220,   157,   157,   157,
     157,   144,   221,   144,   394,   144,   221,   235,   168,   235,
     390,   172,   422,   431,   432,   364,   437,   432,   367,   238,
     216,   106,   128,   136,   137,   142,   151,   154,   156,   166,
     167,   186,   204,   229,   236,   242,   243,   374,   376,   308,
     309,   452,   176,   305,   431,   239,   235,   220,   144,   221,
     221,   201,   435,   436,   437,   144,   221,   144,   258,   144,
     221,   235,   390,   221,   166,   453,   364,   239,   452,   452,
     466,   452,     6,   452,   144,   441,   452,    21,   441,   441,
     239,   433,   144,   146,   437,   442,   468,   132,   174,   215,
     378,   441,   437,   364,   241,   440,   441,   441,   441,   378,
     441,   378,   378,   378,   239,   157,   239,   437,     3,   157,
     227,   232,   471,   473,   189,   247,   452,   437,   437,   437,
     437,   380,   337,   339,   391,   341,   391,   341,   144,   221,
     298,   341,   364,   421,   452,   144,   301,   144,   221,   157,
     157,   157,   398,   398,   157,   157,   157,   157,   157,   157,
     157,   157,    93,    94,    95,   148,   343,   345,   144,   221,
     144,   221,   452,   452,     6,   452,   278,   279,   452,   278,
     278,   278,   109,   276,   281,    44,    59,    60,   102,   236,
     267,   268,   269,   391,   189,   452,     3,   452,   433,    81,
     333,   144,   365,   366,   372,   475,   372,   372,   372,   157,
     432,   177,   437,   372,   157,   432,   372,   105,   141,   143,
     437,   144,   221,   235,   306,   404,   452,     6,   452,   391,
     329,   328,   221,   426,   233,   452,   262,   166,   257,   189,
     452,   259,   262,   328,   235,   235,   144,   235,   144,   144,
     133,   164,   171,   188,   202,   211,   222,   399,   434,   221,
     398,   221,   144,   221,   437,   144,   208,   144,   144,   144,
     437,   144,   437,   437,   437,   399,     3,   399,   471,   153,
     189,   198,   221,   227,   228,   232,   472,     3,   168,   235,
     144,   221,   144,   221,   144,   342,   144,   144,   293,     3,
     386,   386,     3,   239,   157,   239,     3,   387,     3,     3,
       3,   387,   387,     3,     3,     6,   396,    85,   107,   117,
     132,   138,   174,   180,   336,   346,   347,   348,   349,   290,
     286,   235,   144,   221,   197,   218,   144,   144,   144,   267,
       3,     3,     4,   270,   269,   390,   153,   221,   235,   434,
     159,   369,   159,   371,   159,   370,   369,   227,   396,   445,
     446,   468,   371,   445,   370,   437,   309,   452,   157,   235,
     436,   456,   452,   157,   235,   390,    82,   233,   322,   452,
     452,   452,   157,   435,   398,   239,   398,   398,   144,   437,
     144,   144,   144,   144,   144,   144,   471,   471,   471,   452,
     336,   391,   391,   298,   144,   144,   144,   221,   399,     3,
     399,   221,   384,   144,   144,   221,   144,   144,   384,   144,
     144,   338,   449,   157,   348,   298,   452,    24,    25,   236,
     244,   271,   272,   273,   279,   271,   271,   271,   276,     3,
     452,   435,   373,   396,   373,   373,     3,   454,   144,   221,
     144,   216,   177,   310,   311,   437,   452,   201,   357,   361,
     261,   452,   389,   168,     3,   361,   239,   399,   239,   239,
     239,   153,   153,   221,   168,     3,   144,     3,   388,   144,
       3,   144,   157,   421,   270,     3,   273,   153,   390,   361,
     446,   437,   144,   221,   358,   360,   449,   134,   162,   193,
     355,   356,   362,   363,   418,   192,   428,   144,   390,   471,
     144,   144,   399,   399,   399,   399,   471,   471,   144,   239,
     144,   339,   144,   311,    22,    23,   221,   233,   395,   452,
       3,   231,   247,   392,   393,   419,   420,   447,   452,   364,
     364,   363,   355,   132,   174,   215,   379,   129,   190,   413,
     429,   153,   221,   153,   153,   221,   399,   144,   157,   358,
     359,   359,   191,   360,   395,   393,   221,   235,   390,   172,
     427,   430,   452,   234,   129,   471,   471,   358,   237,   237,
     157,   360,   420,   189,   452,   433,   109,   277,     3,   392,
     414,   415,   416,   430,   153,   153,   144,   364,   364,   358,
     390,   434,   221,   197,   218,   417,   277,   144,   435,   415,
     361,   428
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
#line 400 "sql.yacc"
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
#line 426 "sql.yacc"
    {
		(yyval.ptr)=0;
	}
    break;

  case 4:

/* Line 1455 of yacc.c  */
#line 429 "sql.yacc"
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
#line 446 "sql.yacc"
    {
		(yyval.ptr)=A4GL_new_select_list_item_expr((yyvsp[(2) - (2)].s_select_list_item));
	}
    break;

  case 6:

/* Line 1455 of yacc.c  */
#line 451 "sql.yacc"
    {
		(yyval.ptr)=0;
	}
    break;

  case 7:

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
		add_feature("DELETE_WHERE_CURRENT_OF");
		}
	}
    break;

  case 8:

/* Line 1455 of yacc.c  */
#line 471 "sql.yacc"
    {
		 (yyval.ptr)=A4GL_new_select_list_item_expr((yyvsp[(2) - (2)].s_select_list_item));
	}
    break;

  case 9:

/* Line 1455 of yacc.c  */
#line 477 "sql.yacc"
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
#line 486 "sql.yacc"
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
#line 495 "sql.yacc"
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
#line 504 "sql.yacc"
    {
		(yyval.update_cmd)=(yyvsp[(2) - (2)].update_cmd);
		add_feature("UPDATE_COLUMN_EQ_VALUE_LIST");
    }
    break;

  case 13:

/* Line 1455 of yacc.c  */
#line 511 "sql.yacc"
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
#line 526 "sql.yacc"
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
#line 581 "sql.yacc"
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
#line 588 "sql.yacc"
    {
		(yyval.update_cmd)=(yyvsp[(1) - (3)].update_cmd);
		add_str_list((yyval.update_cmd)->column_list, (yyvsp[(3) - (3)].upd_pair)->column_name);
		local_add_select_list_item_list((yyval.update_cmd)->value_list, (yyvsp[(3) - (3)].upd_pair)->value);
	}
    break;

  case 17:

/* Line 1455 of yacc.c  */
#line 599 "sql.yacc"
    {
                strcpy((yyval.str),(yyvsp[(1) - (1)].str));
        }
    break;

  case 18:

/* Line 1455 of yacc.c  */
#line 602 "sql.yacc"
    {
                strcpy((yyval.str),(yyvsp[(2) - (2)].str));
        }
    break;

  case 19:

/* Line 1455 of yacc.c  */
#line 607 "sql.yacc"
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
#line 614 "sql.yacc"
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
#line 631 "sql.yacc"
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
#line 648 "sql.yacc"
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
#line 669 "sql.yacc"
    {
		(yyval.upd_pair)=malloc(sizeof(struct s_update_pair));
		(yyval.upd_pair)->column_name=acl_strdup((yyvsp[(1) - (3)].str));
		(yyval.upd_pair)->value=(yyvsp[(3) - (3)].s_select_list_item);
	}
    break;

  case 24:

/* Line 1455 of yacc.c  */
#line 678 "sql.yacc"
    {
			(yyval.str_list)=new_str_list((yyvsp[(1) - (1)].str));
		}
    break;

  case 25:

/* Line 1455 of yacc.c  */
#line 681 "sql.yacc"
    {
			(yyval.str_list)=add_str_list((yyvsp[(1) - (3)].str_list), (yyvsp[(3) - (3)].str));
		}
    break;

  case 26:

/* Line 1455 of yacc.c  */
#line 689 "sql.yacc"
    { 
		(yyval.s_select_list_item_list)=local_new_select_list_item_list((yyvsp[(1) - (1)].s_select_list_item));
	}
    break;

  case 27:

/* Line 1455 of yacc.c  */
#line 692 "sql.yacc"
    { 
		(yyval.s_select_list_item_list)=local_add_select_list_item_list((yyvsp[(1) - (3)].s_select_list_item_list),(yyvsp[(3) - (3)].s_select_list_item));
	}
    break;

  case 28:

/* Line 1455 of yacc.c  */
#line 700 "sql.yacc"
    {(yyval.s_select_list_item)=(yyvsp[(1) - (1)].s_select_list_item);}
    break;

  case 29:

/* Line 1455 of yacc.c  */
#line 701 "sql.yacc"
    {(yyval.s_select_list_item)=new_select_list_item_builtin_const(E_SLI_BUILTIN_CONST_NULL); }
    break;

  case 30:

/* Line 1455 of yacc.c  */
#line 708 "sql.yacc"
    { (yyval.sql_string)=make_sql_string_and_free(acl_strdup((yyvsp[(1) - (1)].str)), NULL);}
    break;

  case 31:

/* Line 1455 of yacc.c  */
#line 711 "sql.yacc"
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
#line 719 "sql.yacc"
    {SPRINTF2((yyval.str),"%s %s ",(yyvsp[(1) - (2)].str),(yyvsp[(2) - (2)].str));
			add_feature("DROP_VIEW");
}
    break;

  case 33:

/* Line 1455 of yacc.c  */
#line 722 "sql.yacc"
    {SPRINTF2((yyval.str),"%s %s",(yyvsp[(1) - (2)].str),(yyvsp[(2) - (2)].str));
		if (strchr((yyvsp[(2) - (2)].str),'@') || strchr((yyvsp[(2) - (2)].str),':')) add_feature("DROP_INDEX_QUALIFIED_PATH");
			add_feature("DROP_INDEX");
}
    break;

  case 34:

/* Line 1455 of yacc.c  */
#line 726 "sql.yacc"
    {SPRINTF2((yyval.str),"%s %s",(yyvsp[(1) - (2)].str),(yyvsp[(2) - (2)].str));
			add_feature("DROP_TRIGGER");
}
    break;

  case 35:

/* Line 1455 of yacc.c  */
#line 732 "sql.yacc"
    {(yyval.sql_string)=acl_strdup((yyvsp[(1) - (1)].str));}
    break;

  case 36:

/* Line 1455 of yacc.c  */
#line 733 "sql.yacc"
    {(yyval.sql_string)=(yyvsp[(1) - (1)].sql_string);}
    break;

  case 37:

/* Line 1455 of yacc.c  */
#line 737 "sql.yacc"
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
#line 747 "sql.yacc"
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
#line 761 "sql.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 40:

/* Line 1455 of yacc.c  */
#line 762 "sql.yacc"
    {strcpy((yyval.str),(yyvsp[(1) - (1)].str));}
    break;

  case 42:

/* Line 1455 of yacc.c  */
#line 767 "sql.yacc"
    {SPRINTF2((yyval.str),"%s%s",(yyvsp[(1) - (2)].str),(yyvsp[(2) - (2)].str)); }
    break;

  case 43:

/* Line 1455 of yacc.c  */
#line 772 "sql.yacc"
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
#line 780 "sql.yacc"
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
#line 788 "sql.yacc"
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
#line 796 "sql.yacc"
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
#line 804 "sql.yacc"
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
#line 816 "sql.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 50:

/* Line 1455 of yacc.c  */
#line 816 "sql.yacc"
    {strcpy((yyval.str),(yyvsp[(1) - (1)].str));}
    break;

  case 52:

/* Line 1455 of yacc.c  */
#line 820 "sql.yacc"
    {SPRINTF2((yyval.str),"%s%s",(yyvsp[(1) - (2)].str),(yyvsp[(2) - (2)].str));}
    break;

  case 53:

/* Line 1455 of yacc.c  */
#line 824 "sql.yacc"
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
#line 831 "sql.yacc"
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
#line 838 "sql.yacc"
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
#line 845 "sql.yacc"
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
#line 854 "sql.yacc"
    { strcpy(last_tmp_name,(yyvsp[(1) - (1)].str)); }
    break;

  case 58:

/* Line 1455 of yacc.c  */
#line 858 "sql.yacc"
    {SPRINTF7((yyval.str),"CREATE UNIQUE INDEX %s %s %s %s %s %s %s",(yyvsp[(2) - (8)].str),(yyvsp[(3) - (8)].str),(yyvsp[(4) - (8)].str),(yyvsp[(5) - (8)].str),(yyvsp[(6) - (8)].str),(yyvsp[(7) - (8)].str),(yyvsp[(8) - (8)].str));
		add_feature("CREATE_INDEX");
		add_feature("CREATE_INDEX_UNIQUE");
		if (strchr((yyvsp[(2) - (8)].str),'@') || strchr((yyvsp[(2) - (8)].str),':')) add_feature("CREATE_INDEX_QUALIFIED_PATH");
		if (strchr((yyvsp[(6) - (8)].str),',')) { add_feature("CREATE_INDEX_COMPOSITE"); }
	
}
    break;

  case 59:

/* Line 1455 of yacc.c  */
#line 865 "sql.yacc"
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
#line 877 "sql.yacc"
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
#line 888 "sql.yacc"
    {
		if (strchr((yyvsp[(2) - (8)].str),'@') || strchr((yyvsp[(2) - (8)].str),':')) add_feature("CREATE_INDEX_QUALIFIED_PATH");
		if (strchr((yyvsp[(6) - (8)].str),',')) { add_feature("CREATE_INDEX_COMPOSITE"); }
			add_feature("CREATE_INDEX");
			SPRINTF7((yyval.str)," CREATE INDEX %s %s %s %s %s %s %s",(yyvsp[(2) - (8)].str),(yyvsp[(3) - (8)].str),(yyvsp[(4) - (8)].str),(yyvsp[(5) - (8)].str),(yyvsp[(6) - (8)].str),(yyvsp[(7) - (8)].str),(yyvsp[(8) - (8)].str));
	}
    break;

  case 62:

/* Line 1455 of yacc.c  */
#line 894 "sql.yacc"
    {
		add_feature("CREATE_DATABASE");
		a4gl_yyerror("You cannot create a database from within Aubit4gl - if the target database allows - prepare and execute it manually");
	}
    break;

  case 63:

/* Line 1455 of yacc.c  */
#line 898 "sql.yacc"
    {
		add_feature("DROP_DATABASE");
		a4gl_yyerror("You cannot drop a database from within Aubit4gl - if the target database allows - prepare and execute it manually");
	}
    break;

  case 64:

/* Line 1455 of yacc.c  */
#line 902 "sql.yacc"
    { 
		if (strchr((yyvsp[(2) - (4)].str),'@') || strchr((yyvsp[(2) - (4)].str),':')) add_feature("CREATE_SYNONYM_QUALIFIED_PATH");
			add_feature("CREATE_SYNONYM");
			SPRINTF3((yyval.str),"%s %s FOR %s",(yyvsp[(1) - (4)].str),(yyvsp[(2) - (4)].str),(yyvsp[(4) - (4)].str)); 
	}
    break;

  case 65:

/* Line 1455 of yacc.c  */
#line 907 "sql.yacc"
    { 
		add_feature("CREATE_AUDIT");
		SPRINTF2((yyval.str),"CREATE AUDIT FOR %s IN '%s'",(yyvsp[(2) - (4)].str),A4GL_strip_quotes((yyvsp[(4) - (4)].str))); 
	}
    break;

  case 66:

/* Line 1455 of yacc.c  */
#line 911 "sql.yacc"
    { 
		add_feature("DROP_AUDIT");
		SPRINTF1((yyval.str),"DROP AUDIT FOR %s",(yyvsp[(2) - (2)].str)); }
    break;

  case 67:

/* Line 1455 of yacc.c  */
#line 914 "sql.yacc"
    { 
		if (strchr((yyvsp[(2) - (2)].str),'@') || strchr((yyvsp[(2) - (2)].str),':')) add_feature("DROP_SYNONYM_QUALIFIED_PATH");
		add_feature("DROP_SYNONYM");
		SPRINTF2((yyval.str),"%s %s",(yyvsp[(1) - (2)].str),(yyvsp[(2) - (2)].str)); }
    break;

  case 68:

/* Line 1455 of yacc.c  */
#line 918 "sql.yacc"
    { 
		add_feature("RECOVER_TABLE");
		SPRINTF1((yyval.str),"RECOVER TABLE %s",(yyvsp[(2) - (2)].str)); }
    break;

  case 69:

/* Line 1455 of yacc.c  */
#line 921 "sql.yacc"
    { 
		add_feature("ROLLFORWARD_DATABASE");
		SPRINTF1((yyval.str),"ROLLFORWARD DATABASE %s",(yyvsp[(2) - (2)].str)); }
    break;

  case 70:

/* Line 1455 of yacc.c  */
#line 928 "sql.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 71:

/* Line 1455 of yacc.c  */
#line 929 "sql.yacc"
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
#line 939 "sql.yacc"
    {(yyval.integer_val)=0;}
    break;

  case 73:

/* Line 1455 of yacc.c  */
#line 940 "sql.yacc"
    { (yyval.integer_val)=1;}
    break;

  case 75:

/* Line 1455 of yacc.c  */
#line 945 "sql.yacc"
    {SPRINTF2((yyval.str),"%s,%s",(yyvsp[(1) - (3)].str),(yyvsp[(3) - (3)].str));}
    break;

  case 76:

/* Line 1455 of yacc.c  */
#line 949 "sql.yacc"
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
#line 958 "sql.yacc"
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
#line 967 "sql.yacc"
    {
		strcpy((yyval.str),A4GL_confirm_colname(last_tmp_name,(yyvsp[(1) - (1)].str)));
}
    break;

  case 79:

/* Line 1455 of yacc.c  */
#line 974 "sql.yacc"
    {
		(yyval.sql_string)=(yyvsp[(1) - (1)].sql_string);
	}
    break;

  case 80:

/* Line 1455 of yacc.c  */
#line 977 "sql.yacc"
    {
		(yyval.sql_string)=make_sql_string_and_free((yyvsp[(1) - (3)].sql_string),kw_comma,strdup("\n"),(yyvsp[(3) - (3)].sql_string),NULL);
	}
    break;

  case 81:

/* Line 1455 of yacc.c  */
#line 983 "sql.yacc"
    {
		(yyval.sql_string)=make_sql_string_and_free(strdup("   "),(yyvsp[(1) - (1)].sql_string),NULL);
	}
    break;

  case 82:

/* Line 1455 of yacc.c  */
#line 986 "sql.yacc"
    {
		(yyval.sql_string)=make_sql_string_and_free(strdup("   "),(yyvsp[(1) - (1)].sql_string),NULL);
	}
    break;

  case 83:

/* Line 1455 of yacc.c  */
#line 997 "sql.yacc"
    {
		add_feature("ALTER_TABLE");
	(yyval.sql_string)=make_sql_string_and_free(acl_strdup((yyvsp[(1) - (3)].str)),kw_space,acl_strdup((yyvsp[(2) - (3)].str)),kw_space,(yyvsp[(3) - (3)].sql_string),NULL);
	}
    break;

  case 84:

/* Line 1455 of yacc.c  */
#line 1001 "sql.yacc"
    {
		add_feature("CLUSTER_INDEX");
		add_feature("ALTER_INDEX_CLUSTER");
		(yyval.sql_string)=make_sql_string_and_free(acl_strdup("ALTER INDEX "),acl_strdup((yyvsp[(2) - (3)].str)),acl_strdup(" TO CLUSTER"),NULL);
		}
    break;

  case 85:

/* Line 1455 of yacc.c  */
#line 1006 "sql.yacc"
    {
		add_feature("ALTER_INDEX_NOT_CLUSTER");
		(yyval.sql_string)=make_sql_string_and_free(acl_strdup("ALTER INDEX "),acl_strdup((yyvsp[(2) - (3)].str)),acl_strdup(" TO NOT CLUSTER"),NULL);
		}
    break;

  case 86:

/* Line 1455 of yacc.c  */
#line 1013 "sql.yacc"
    {
		(yyval.sql_string)=(yyvsp[(1) - (1)].sql_string);
	}
    break;

  case 87:

/* Line 1455 of yacc.c  */
#line 1016 "sql.yacc"
    {
		(yyval.sql_string)=make_sql_string_and_free((yyvsp[(1) - (3)].sql_string),kw_comma,(yyvsp[(3) - (3)].sql_string),NULL);
	}
    break;

  case 88:

/* Line 1455 of yacc.c  */
#line 1025 "sql.yacc"
    {
		(yyval.sql_string)=(yyvsp[(1) - (1)].sql_string);
	}
    break;

  case 89:

/* Line 1455 of yacc.c  */
#line 1028 "sql.yacc"
    {
	add_feature("ALTER_TABLE_DROP");
		(yyval.sql_string)=acl_strdup((yyvsp[(1) - (1)].str));
	}
    break;

  case 90:

/* Line 1455 of yacc.c  */
#line 1032 "sql.yacc"
    {
	add_feature("ALTER_TABLE_MODIFY");
		(yyval.sql_string)=(yyvsp[(1) - (1)].sql_string);
	}
    break;

  case 91:

/* Line 1455 of yacc.c  */
#line 1036 "sql.yacc"
    {
		add_feature("ALTER_TABLE_ADD_CONSTRAINT");
		(yyval.sql_string)=acl_strdup((yyvsp[(1) - (1)].str));
	}
    break;

  case 92:

/* Line 1455 of yacc.c  */
#line 1040 "sql.yacc"
    {
		add_feature("ALTER_TABLE_DROP_CONSTRAINT");
		(yyval.sql_string)=acl_strdup((yyvsp[(1) - (1)].str));
	}
    break;

  case 93:

/* Line 1455 of yacc.c  */
#line 1044 "sql.yacc"
    {
		add_feature("ALTER_TABLE_MODIFY_NEXT");
		(yyval.sql_string)=acl_strdup((yyvsp[(1) - (1)].str));
	}
    break;

  case 94:

/* Line 1455 of yacc.c  */
#line 1048 "sql.yacc"
    {
		add_feature("ALTER_TABLE_LOCK_MODE");
		(yyval.sql_string)=acl_strdup((yyvsp[(1) - (1)].str));
	}
    break;

  case 95:

/* Line 1455 of yacc.c  */
#line 1056 "sql.yacc"
    {
		add_feature("ALTER_TABLE_ADD");
		(yyval.sql_string)=make_sql_string_and_free(acl_strdup("ADD "),(yyvsp[(2) - (2)].sql_string),NULL);
	}
    break;

  case 96:

/* Line 1455 of yacc.c  */
#line 1060 "sql.yacc"
    {
		add_feature("ALTER_TABLE_ADD");
		(yyval.sql_string)=make_sql_string_and_free(acl_strdup("ADD "),kw_ob,(yyvsp[(3) - (4)].sql_string),kw_cb,NULL);
	}
    break;

  case 97:

/* Line 1455 of yacc.c  */
#line 1068 "sql.yacc"
    {
		(yyval.sql_string)=(yyvsp[(1) - (1)].sql_string);
	}
    break;

  case 98:

/* Line 1455 of yacc.c  */
#line 1071 "sql.yacc"
    {
		add_feature("ALTER_TABLE_ADD_BEFORE");
		(yyval.sql_string)=make_sql_string_and_free((yyvsp[(1) - (3)].sql_string),acl_strdup(" BEFORE "),acl_strdup((yyvsp[(3) - (3)].str)),NULL);
	}
    break;

  case 99:

/* Line 1455 of yacc.c  */
#line 1078 "sql.yacc"
    {
		(yyval.sql_string)=(yyvsp[(1) - (1)].sql_string);
	}
    break;

  case 100:

/* Line 1455 of yacc.c  */
#line 1081 "sql.yacc"
    {
		(yyval.sql_string)=make_sql_string_and_free((yyvsp[(1) - (3)].sql_string),kw_comma,(yyvsp[(3) - (3)].sql_string),NULL);
	}
    break;

  case 101:

/* Line 1455 of yacc.c  */
#line 1088 "sql.yacc"
    {
		SPRINTF1((yyval.str),"DROP %s",(yyvsp[(2) - (2)].str));
	}
    break;

  case 102:

/* Line 1455 of yacc.c  */
#line 1091 "sql.yacc"
    {
		SPRINTF1((yyval.str),"DROP (%s)",(yyvsp[(3) - (4)].str));
	}
    break;

  case 104:

/* Line 1455 of yacc.c  */
#line 1099 "sql.yacc"
    {
		SPRINTF2((yyval.str),"%s,%s",(yyvsp[(1) - (3)].str),(yyvsp[(3) - (3)].str));
	}
    break;

  case 106:

/* Line 1455 of yacc.c  */
#line 1108 "sql.yacc"
    {
		(yyval.sql_string)=make_sql_string_and_free(acl_strdup("MODIFY "),(yyvsp[(2) - (2)].sql_string),NULL);
	}
    break;

  case 107:

/* Line 1455 of yacc.c  */
#line 1111 "sql.yacc"
    {
		(yyval.sql_string)=make_sql_string_and_free(acl_strdup("MODIFY "),kw_ob,(yyvsp[(3) - (4)].sql_string),kw_cb,NULL);
	}
    break;

  case 108:

/* Line 1455 of yacc.c  */
#line 1117 "sql.yacc"
    {
		(yyval.sql_string)=(yyvsp[(1) - (1)].sql_string);
	}
    break;

  case 109:

/* Line 1455 of yacc.c  */
#line 1120 "sql.yacc"
    {
		(yyval.sql_string)=make_sql_string_and_free((yyvsp[(1) - (3)].sql_string),kw_comma,(yyvsp[(3) - (3)].sql_string),NULL);
	}
    break;

  case 110:

/* Line 1455 of yacc.c  */
#line 1126 "sql.yacc"
    {
		(yyval.sql_string)=(yyvsp[(1) - (1)].sql_string);
	}
    break;

  case 111:

/* Line 1455 of yacc.c  */
#line 1133 "sql.yacc"
    {strcpy((yyval.str),"LOCK MODE (PAGE)");}
    break;

  case 112:

/* Line 1455 of yacc.c  */
#line 1134 "sql.yacc"
    {strcpy((yyval.str),"LOCK MODE (ROW)");}
    break;

  case 113:

/* Line 1455 of yacc.c  */
#line 1138 "sql.yacc"
    {
		add_feature("DDL_NEXT_SIZE");
		SPRINTF1((yyval.str),"MODIFY NEXT SIZE %d",atoi((yyvsp[(2) - (2)].str)));
	}
    break;

  case 114:

/* Line 1455 of yacc.c  */
#line 1146 "sql.yacc"
    {
		add_feature("DDL_CONSTRAINT");
		SPRINTF2((yyval.str),"ADD CONSTRAINT %s%s",(yyvsp[(2) - (3)].sql_string),(yyvsp[(3) - (3)].str));
	}
    break;

  case 115:

/* Line 1455 of yacc.c  */
#line 1150 "sql.yacc"
    {
		add_feature("ADD_CONSTRAINT");
		SPRINTF1((yyval.str),"ADD CONSTRAINT (%s)",(yyvsp[(3) - (4)].sql_string));
	}
    break;

  case 116:

/* Line 1455 of yacc.c  */
#line 1157 "sql.yacc"
    {
		(yyval.sql_string)=make_sql_string_and_free((yyvsp[(1) - (2)].sql_string),acl_strdup((yyvsp[(2) - (2)].str)),NULL);
}
    break;

  case 117:

/* Line 1455 of yacc.c  */
#line 1159 "sql.yacc"
    {
	(yyval.sql_string)=make_sql_string_and_free((yyvsp[(1) - (4)].sql_string),kw_comma,(yyvsp[(3) - (4)].sql_string),acl_strdup((yyvsp[(4) - (4)].str)), NULL);
}
    break;

  case 118:

/* Line 1455 of yacc.c  */
#line 1164 "sql.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 119:

/* Line 1455 of yacc.c  */
#line 1165 "sql.yacc"
    {SPRINTF2((yyval.str)," %s %s",(yyvsp[(1) - (2)].str),(yyvsp[(2) - (2)].str)); add_feature("DDL_CONSTRAINT");}
    break;

  case 120:

/* Line 1455 of yacc.c  */
#line 1170 "sql.yacc"
    { SPRINTF1((yyval.str),"DROP CONSTRAINT %s",(yyvsp[(2) - (2)].str)); add_feature("DROP_CONSTRAINT"); }
    break;

  case 121:

/* Line 1455 of yacc.c  */
#line 1171 "sql.yacc"
    {add_feature("DROP_CONSTRAINT");
		SPRINTF1((yyval.str),"DROP CONSTRAINT (%s)",(yyvsp[(3) - (4)].str));
	}
    break;

  case 122:

/* Line 1455 of yacc.c  */
#line 1177 "sql.yacc"
    {strcpy((yyval.str),(yyvsp[(1) - (1)].str));}
    break;

  case 123:

/* Line 1455 of yacc.c  */
#line 1178 "sql.yacc"
    {SPRINTF2((yyval.str),"%s,%s",(yyvsp[(1) - (3)].str),(yyvsp[(3) - (3)].str));}
    break;

  case 125:

/* Line 1455 of yacc.c  */
#line 1192 "sql.yacc"
    {  add_feature("ROLLBACK_WORK"); }
    break;

  case 126:

/* Line 1455 of yacc.c  */
#line 1198 "sql.yacc"
    { insql=1;}
    break;

  case 127:

/* Line 1455 of yacc.c  */
#line 1198 "sql.yacc"
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
#line 1207 "sql.yacc"
    {insql=1;}
    break;

  case 129:

/* Line 1455 of yacc.c  */
#line 1207 "sql.yacc"
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
#line 1216 "sql.yacc"
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
#line 1241 "sql.yacc"
    {
			(yyval.str_list)=0;
	}
    break;

  case 132:

/* Line 1455 of yacc.c  */
#line 1244 "sql.yacc"
    {
			(yyval.str_list)=(yyvsp[(2) - (3)].str_list);
			 add_feature("INSERT_COLUMNLIST_EQ_VALUELIST");
	}
    break;

  case 133:

/* Line 1455 of yacc.c  */
#line 1252 "sql.yacc"
    {
                        (yyval.str_list)=new_str_list((yyvsp[(1) - (1)].str));
	}
    break;

  case 134:

/* Line 1455 of yacc.c  */
#line 1255 "sql.yacc"
    {
                        (yyval.str_list)=add_str_list((yyvsp[(1) - (3)].str_list), (yyvsp[(3) - (3)].str));
	}
    break;

  case 135:

/* Line 1455 of yacc.c  */
#line 1262 "sql.yacc"
    {	
			strcpy((yyval.str),(yyvsp[(1) - (1)].str));
	}
    break;

  case 136:

/* Line 1455 of yacc.c  */
#line 1265 "sql.yacc"
    { 
			/* with a table prefix - on an insert ? We'll just silently drop it... */
			strcpy((yyval.str),(yyvsp[(3) - (3)].str));
			A4GL_warn("Dropped table prefix from INSERT column name");
	}
    break;

  case 137:

/* Line 1455 of yacc.c  */
#line 1273 "sql.yacc"
    { (yyval.s_select_list_item_list)=local_new_select_list_item_list((yyvsp[(1) - (1)].s_select_list_item));}
    break;

  case 138:

/* Line 1455 of yacc.c  */
#line 1274 "sql.yacc"
    {
		(yyval.s_select_list_item_list)=local_add_select_list_item_list((yyvsp[(1) - (3)].s_select_list_item_list),(yyvsp[(3) - (3)].s_select_list_item));
	}
    break;

  case 139:

/* Line 1455 of yacc.c  */
#line 1280 "sql.yacc"
    {(yyval.s_select_list_item)=(yyvsp[(1) - (1)].s_select_list_item);}
    break;

  case 140:

/* Line 1455 of yacc.c  */
#line 1281 "sql.yacc"
    {(yyval.s_select_list_item)=new_select_list_item_builtin_const(E_SLI_BUILTIN_CONST_NULL); }
    break;

  case 141:

/* Line 1455 of yacc.c  */
#line 1289 "sql.yacc"
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
#line 1307 "sql.yacc"
    { add_feature("BEGIN_WORK"); }
    break;

  case 143:

/* Line 1455 of yacc.c  */
#line 1311 "sql.yacc"
    { add_feature("COMMIT_WORK"); }
    break;

  case 144:

/* Line 1455 of yacc.c  */
#line 1316 "sql.yacc"
    {(yyval.e_boolean)=EB_FALSE;}
    break;

  case 145:

/* Line 1455 of yacc.c  */
#line 1317 "sql.yacc"
    {
		add_feature("DATABASE_EXCLUSIVE");
		{(yyval.e_boolean)=EB_TRUE;}
	}
    break;

  case 146:

/* Line 1455 of yacc.c  */
#line 1327 "sql.yacc"
    {
	char buff[256];
	(yyval.sql_string)=make_sql_string_and_free(acl_strdup((yyvsp[(1) - (1)].str)),NULL);
	SPRINTF1(buff,"Warning: Informix specific SQL @ line %d\n",yylineno);
	ansi_violation(buff,1);
	}
    break;

  case 147:

/* Line 1455 of yacc.c  */
#line 1336 "sql.yacc"
    {
			add_feature("START_DATABASE_WITH_LOG_MODE_ANSI");
			sprintf((yyval.str),"START DATABASE %s WITH LOG IN %s MODE ANSI", (yyvsp[(2) - (5)].str),(yyvsp[(4) - (5)].str));
	}
    break;

  case 148:

/* Line 1455 of yacc.c  */
#line 1340 "sql.yacc"
    {
			add_feature("START_DATABASE_WITH_LOG");
			sprintf((yyval.str),"START DATABASE %s WITH LOG IN %s", (yyvsp[(2) - (4)].str),(yyvsp[(4) - (4)].str));
	}
    break;

  case 149:

/* Line 1455 of yacc.c  */
#line 1345 "sql.yacc"
    {
			add_feature("SET_CONSTRAINTS_ALL_IMMEDIATE");
			SPRINTF1((yyval.str),"%s",(yyvsp[(1) - (1)].str)); 
	}
    break;

  case 150:

/* Line 1455 of yacc.c  */
#line 1349 "sql.yacc"
    {
		add_feature("SET_BUFFERED_LOG");
			SPRINTF1((yyval.str),"%s",(yyvsp[(1) - (1)].str)); 
	}
    break;

  case 151:

/* Line 1455 of yacc.c  */
#line 1353 "sql.yacc"
    {
		add_feature("SET_LOG");
			SPRINTF1((yyval.str),"%s",(yyvsp[(1) - (1)].str)); 
	}
    break;

  case 152:

/* Line 1455 of yacc.c  */
#line 1357 "sql.yacc"
    {
			SPRINTF2((yyval.str),"%s %s",(yyvsp[(1) - (2)].str),(yyvsp[(2) - (2)].str)); add_feature("UPDATE_STATISTICS_TABLE");
	}
    break;

  case 153:

/* Line 1455 of yacc.c  */
#line 1360 "sql.yacc"
    {
		add_feature("UPDATE_STATISTICS");
			SPRINTF1((yyval.str),"%s",(yyvsp[(1) - (1)].str)); 
	}
    break;

  case 154:

/* Line 1455 of yacc.c  */
#line 1367 "sql.yacc"
    { (yyval.integer_val)=1; }
    break;

  case 155:

/* Line 1455 of yacc.c  */
#line 1368 "sql.yacc"
    { (yyval.integer_val)=-1; }
    break;

  case 156:

/* Line 1455 of yacc.c  */
#line 1369 "sql.yacc"
    { (yyval.integer_val)=0; }
    break;

  case 157:

/* Line 1455 of yacc.c  */
#line 1373 "sql.yacc"
    { (yyval.sql_string)=(yyvsp[(1) - (1)].sql_string); }
    break;

  case 158:

/* Line 1455 of yacc.c  */
#line 1374 "sql.yacc"
    { (yyval.sql_string)=(yyvsp[(1) - (1)].sql_string); }
    break;

  case 159:

/* Line 1455 of yacc.c  */
#line 1375 "sql.yacc"
    { (yyval.sql_string)=(yyvsp[(1) - (1)].sql_string); }
    break;

  case 160:

/* Line 1455 of yacc.c  */
#line 1376 "sql.yacc"
    { (yyval.sql_string)=(yyvsp[(1) - (1)].sql_string); }
    break;

  case 161:

/* Line 1455 of yacc.c  */
#line 1377 "sql.yacc"
    { (yyval.sql_string)=(yyvsp[(1) - (1)].sql_string); }
    break;

  case 162:

/* Line 1455 of yacc.c  */
#line 1378 "sql.yacc"
    { (yyval.sql_string)=(yyvsp[(1) - (1)].sql_string); }
    break;

  case 163:

/* Line 1455 of yacc.c  */
#line 1379 "sql.yacc"
    { (yyval.sql_string)=(yyvsp[(1) - (1)].sql_string); }
    break;

  case 164:

/* Line 1455 of yacc.c  */
#line 1387 "sql.yacc"
    {SPRINTF7((yyval.str),"%s %s %s %s %s %s %s",(yyvsp[(1) - (7)].str),(yyvsp[(2) - (7)].str),(yyvsp[(3) - (7)].str),(yyvsp[(4) - (7)].str),(yyvsp[(5) - (7)].str),(yyvsp[(6) - (7)].str),(yyvsp[(7) - (7)].str));  add_feature("GRANT"); }
    break;

  case 165:

/* Line 1455 of yacc.c  */
#line 1388 "sql.yacc"
    {SPRINTF6((yyval.str),"%s %s %s %s %s %s",(yyvsp[(1) - (6)].str),(yyvsp[(2) - (6)].str),(yyvsp[(3) - (6)].str),(yyvsp[(4) - (6)].str),(yyvsp[(5) - (6)].str),(yyvsp[(6) - (6)].str));  add_feature("REVOKE"); }
    break;

  case 166:

/* Line 1455 of yacc.c  */
#line 1389 "sql.yacc"
    {SPRINTF4((yyval.str),"%s %s %s %s ",(yyvsp[(1) - (4)].str),(yyvsp[(2) - (4)].str),(yyvsp[(3) - (4)].str),(yyvsp[(4) - (4)].str)); add_feature("GRANT"); }
    break;

  case 167:

/* Line 1455 of yacc.c  */
#line 1390 "sql.yacc"
    {SPRINTF4((yyval.str),"%s %s %s %s ",(yyvsp[(1) - (4)].str),(yyvsp[(2) - (4)].str),(yyvsp[(3) - (4)].str),(yyvsp[(4) - (4)].str));  add_feature("REVOKE"); }
    break;

  case 171:

/* Line 1455 of yacc.c  */
#line 1400 "sql.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 172:

/* Line 1455 of yacc.c  */
#line 1401 "sql.yacc"
    {SPRINTF1((yyval.str)," %s ",(yyvsp[(1) - (1)].str));}
    break;

  case 173:

/* Line 1455 of yacc.c  */
#line 1402 "sql.yacc"
    {SPRINTF2((yyval.str)," %s %s",(yyvsp[(1) - (2)].str),(yyvsp[(2) - (2)].str));}
    break;

  case 174:

/* Line 1455 of yacc.c  */
#line 1406 "sql.yacc"
    {SPRINTF1((yyval.str)," %s ",(yyvsp[(1) - (1)].str));}
    break;

  case 175:

/* Line 1455 of yacc.c  */
#line 1407 "sql.yacc"
    {SPRINTF1((yyval.str)," %s ",(yyvsp[(1) - (1)].str));}
    break;

  case 178:

/* Line 1455 of yacc.c  */
#line 1414 "sql.yacc"
    {SPRINTF3((yyval.str)," %s %s %s",(yyvsp[(1) - (3)].str),(yyvsp[(2) - (3)].str),(yyvsp[(3) - (3)].str));}
    break;

  case 179:

/* Line 1455 of yacc.c  */
#line 1417 "sql.yacc"
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
#line 1426 "sql.yacc"
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
#line 1437 "sql.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 186:

/* Line 1455 of yacc.c  */
#line 1439 "sql.yacc"
    {SPRINTF3((yyval.str)," %s %s %s",(yyvsp[(1) - (3)].str),(yyvsp[(2) - (3)].str),(yyvsp[(3) - (3)].str));}
    break;

  case 188:

/* Line 1455 of yacc.c  */
#line 1445 "sql.yacc"
    {SPRINTF3((yyval.str)," %s %s %s",(yyvsp[(1) - (3)].str),(yyvsp[(2) - (3)].str),(yyvsp[(3) - (3)].str));}
    break;

  case 190:

/* Line 1455 of yacc.c  */
#line 1451 "sql.yacc"
    {SPRINTF3((yyval.str)," %s %s %s",(yyvsp[(1) - (3)].str),(yyvsp[(2) - (3)].str),(yyvsp[(3) - (3)].str));}
    break;

  case 193:

/* Line 1455 of yacc.c  */
#line 1461 "sql.yacc"
    {
		add_feature("CREATE_VIEW_AS_SELECT");
		(yyval.sql_string)=make_sql_string_and_free(acl_strdup((yyvsp[(1) - (6)].str)),kw_space,acl_strdup((yyvsp[(2) - (6)].str)),kw_space,acl_strdup((yyvsp[(3) - (6)].str)),kw_space,acl_strdup((yyvsp[(4) - (6)].str)),kw_space,(yyvsp[(5) - (6)].sql_string),kw_space,acl_strdup((yyvsp[(6) - (6)].str)),NULL);
	
}
    break;

  case 194:

/* Line 1455 of yacc.c  */
#line 1468 "sql.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 195:

/* Line 1455 of yacc.c  */
#line 1470 "sql.yacc"
    {SPRINTF3((yyval.str)," %s %s %s",(yyvsp[(1) - (3)].str),(yyvsp[(2) - (3)].str),(yyvsp[(3) - (3)].str));}
    break;

  case 197:

/* Line 1455 of yacc.c  */
#line 1476 "sql.yacc"
    {SPRINTF3((yyval.str)," %s %s %s",(yyvsp[(1) - (3)].str),(yyvsp[(2) - (3)].str),(yyvsp[(3) - (3)].str));}
    break;

  case 198:

/* Line 1455 of yacc.c  */
#line 1479 "sql.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 199:

/* Line 1455 of yacc.c  */
#line 1480 "sql.yacc"
    {
		add_feature("CREATE_VIEW_SELECT_WITH_CHECK");
	}
    break;

  case 200:

/* Line 1455 of yacc.c  */
#line 1487 "sql.yacc"
    {
		(yyval.sql_string)=make_sql_string_and_free(strdup("CHECK ("),(yyvsp[(3) - (4)].sql_string),kw_cb,NULL);
		add_feature("DDL_CHECK");
	}
    break;

  case 201:

/* Line 1455 of yacc.c  */
#line 1496 "sql.yacc"
    {SPRINTF5((yyval.str)," %s %s %s %s %s",(yyvsp[(1) - (5)].str),(yyvsp[(2) - (5)].str),(yyvsp[(3) - (5)].str),(yyvsp[(4) - (5)].str),(yyvsp[(5) - (5)].str));
	add_feature("DDL_FOREIGN_KEY");
}
    break;

  case 202:

/* Line 1455 of yacc.c  */
#line 1503 "sql.yacc"
    {SPRINTF2((yyval.str)," %s %s",(yyvsp[(1) - (2)].str),(yyvsp[(2) - (2)].str));
add_feature("DDL_REFERENCES");
}
    break;

  case 205:

/* Line 1455 of yacc.c  */
#line 1515 "sql.yacc"
    {SPRINTF4((yyval.str)," %s %s %s %s",(yyvsp[(1) - (4)].str),(yyvsp[(2) - (4)].str),(yyvsp[(3) - (4)].str),(yyvsp[(4) - (4)].str));}
    break;

  case 207:

/* Line 1455 of yacc.c  */
#line 1521 "sql.yacc"
    {SPRINTF3((yyval.str)," %s %s %s",(yyvsp[(1) - (3)].str),(yyvsp[(2) - (3)].str),(yyvsp[(3) - (3)].str));}
    break;

  case 208:

/* Line 1455 of yacc.c  */
#line 1526 "sql.yacc"
    {
		SPRINTF3((yyval.str)," UNIQUE %s %s %s",(yyvsp[(2) - (4)].str),(yyvsp[(3) - (4)].str),(yyvsp[(4) - (4)].str));
add_feature("DDL_UNIQUE");
	}
    break;

  case 209:

/* Line 1455 of yacc.c  */
#line 1530 "sql.yacc"
    {
		ansi_violation("Use UNIQUE not DISTINCT",0);
		SPRINTF3((yyval.str)," UNIQUE %s %s %s",(yyvsp[(2) - (4)].str),(yyvsp[(3) - (4)].str),(yyvsp[(4) - (4)].str));
add_feature("DDL_DISTINCT");
	}
    break;

  case 210:

/* Line 1455 of yacc.c  */
#line 1536 "sql.yacc"
    {SPRINTF4((yyval.str)," %s %s %s %s",(yyvsp[(1) - (4)].str),(yyvsp[(2) - (4)].str),(yyvsp[(3) - (4)].str),(yyvsp[(4) - (4)].str));
add_feature("DDL_PRIMARY_KEY");
}
    break;

  case 212:

/* Line 1455 of yacc.c  */
#line 1544 "sql.yacc"
    {SPRINTF3((yyval.str)," %s %s %s",(yyvsp[(1) - (3)].str),(yyvsp[(2) - (3)].str),(yyvsp[(3) - (3)].str));}
    break;

  case 213:

/* Line 1455 of yacc.c  */
#line 1549 "sql.yacc"
    {
		(yyval.sql_string)=acl_strdup((yyvsp[(1) - (1)].str));
	}
    break;

  case 214:

/* Line 1455 of yacc.c  */
#line 1552 "sql.yacc"
    {
		(yyval.sql_string)=acl_strdup((yyvsp[(1) - (1)].str));
	}
    break;

  case 215:

/* Line 1455 of yacc.c  */
#line 1555 "sql.yacc"
    {
		(yyval.sql_string)=(yyvsp[(1) - (1)].sql_string);
	}
    break;

  case 216:

/* Line 1455 of yacc.c  */
#line 1562 "sql.yacc"
    {SPRINTF2((yyval.str)," %s %s",(yyvsp[(1) - (2)].str),(yyvsp[(2) - (2)].str)); add_feature("DDL_DEFAULT_VALUE"); }
    break;

  case 217:

/* Line 1455 of yacc.c  */
#line 1563 "sql.yacc"
    {SPRINTF1((yyval.str)," DEFAULT %s", A4GLSQLCV_get_sqlconst("USER")); add_feature("DDL_DEFAULT_VALUE"); }
    break;

  case 218:

/* Line 1455 of yacc.c  */
#line 1564 "sql.yacc"
    {SPRINTF1((yyval.str)," DEFAULT %s", A4GLSQLCV_get_sqlconst("TODAY")); add_feature("DDL_DEFAULT_VALUE"); }
    break;

  case 219:

/* Line 1455 of yacc.c  */
#line 1565 "sql.yacc"
    { SPRINTF1((yyval.str)," %s",(yyvsp[(1) - (1)].str)); add_feature("DDL_DEFAULT_VALUE"); }
    break;

  case 220:

/* Line 1455 of yacc.c  */
#line 1571 "sql.yacc"
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
#line 1592 "sql.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 223:

/* Line 1455 of yacc.c  */
#line 1596 "sql.yacc"
    {
		(yyval.sql_string)=acl_strdup("");
	}
    break;

  case 224:

/* Line 1455 of yacc.c  */
#line 1598 "sql.yacc"
    {
		(yyval.sql_string)=(yyvsp[(1) - (1)].sql_string);
	}
    break;

  case 225:

/* Line 1455 of yacc.c  */
#line 1605 "sql.yacc"
    {
		(yyval.sql_string)=(yyvsp[(1) - (1)].sql_string);
	}
    break;

  case 226:

/* Line 1455 of yacc.c  */
#line 1608 "sql.yacc"
    {
		(yyval.sql_string)=make_sql_string_and_free((yyvsp[(1) - (2)].sql_string),kw_space,(yyvsp[(2) - (2)].sql_string),NULL);
	}
    break;

  case 227:

/* Line 1455 of yacc.c  */
#line 1614 "sql.yacc"
    {
		(yyval.sql_string)=make_sql_string_and_free((yyvsp[(1) - (2)].sql_string),acl_strdup((yyvsp[(2) - (2)].str)),NULL);
	}
    break;

  case 228:

/* Line 1455 of yacc.c  */
#line 1622 "sql.yacc"
    {
		SPRINTF1((yyval.str)," %s ",(yyvsp[(1) - (1)].str));
		(yyval.sql_string)=acl_strdup((yyval.str));
		add_feature("DDL_NOT_NULL");
	}
    break;

  case 229:

/* Line 1455 of yacc.c  */
#line 1627 "sql.yacc"
    {
		SPRINTF0((yyval.str)," NOT NULL UNIQUE ");
		(yyval.sql_string)=acl_strdup((yyval.str));
		add_feature("DDL_NOT_NULL");
		add_feature("DDL_UNIQUE");
	}
    break;

  case 230:

/* Line 1455 of yacc.c  */
#line 1633 "sql.yacc"
    {
		SPRINTF0((yyval.str)," UNIQUE ");
		(yyval.sql_string)=acl_strdup((yyval.str));
		add_feature("DDL_UNIQUE");
	}
    break;

  case 231:

/* Line 1455 of yacc.c  */
#line 1638 "sql.yacc"
    {
		ansi_violation("Use UNIQUE not DISTINCT",0);
		SPRINTF0((yyval.str)," UNIQUE ");
		(yyval.sql_string)=acl_strdup((yyval.str));
		add_feature("DDL_DISTINCT");
	}
    break;

  case 232:

/* Line 1455 of yacc.c  */
#line 1644 "sql.yacc"
    {
		(yyval.sql_string)=acl_strdup((yyvsp[(1) - (1)].str));
	}
    break;

  case 233:

/* Line 1455 of yacc.c  */
#line 1647 "sql.yacc"
    {
		(yyval.sql_string)=make_sql_string_and_free(acl_strdup("CHECK ("),(yyvsp[(3) - (4)].sql_string),kw_cb,NULL);
		add_feature("DDL_CHECK");
		
	}
    break;

  case 234:

/* Line 1455 of yacc.c  */
#line 1652 "sql.yacc"
    {
		(yyval.sql_string)=make_sql_string_and_free(acl_strdup(" PRIMARY KEY "),NULL);
		add_feature("DDL_PRIMARY_KEY");
	}
    break;

  case 235:

/* Line 1455 of yacc.c  */
#line 1661 "sql.yacc"
    {
		add_feature("CREATE_SCHEMA");

(yyval.sql_string)=make_sql_string_and_free(acl_strdup((yyvsp[(1) - (3)].str)),kw_space,acl_strdup((yyvsp[(2) - (3)].str)),kw_space,acl_strdup((yyvsp[(3) - (3)].str)),NULL);
}
    break;

  case 236:

/* Line 1455 of yacc.c  */
#line 1670 "sql.yacc"
    {SPRINTF1((yyval.str)," %s",(yyvsp[(1) - (1)].str));}
    break;

  case 239:

/* Line 1455 of yacc.c  */
#line 1679 "sql.yacc"
    {
		(yyval.sql_string)=make_sql_string_and_free((yyvsp[(1) - (2)].sql_string),kw_space,(yyvsp[(2) - (2)].sql_string),NULL);
	}
    break;

  case 240:

/* Line 1455 of yacc.c  */
#line 1685 "sql.yacc"
    {
		(yyval.sql_string)=(yyvsp[(1) - (1)].sql_string);
	}
    break;

  case 241:

/* Line 1455 of yacc.c  */
#line 1688 "sql.yacc"
    {
		(yyval.sql_string)=acl_strdup((yyvsp[(1) - (1)].str));
	}
    break;

  case 242:

/* Line 1455 of yacc.c  */
#line 1699 "sql.yacc"
    {
		 add_feature("HAVING"); 
		(yyval.s_select_list_item)=(yyvsp[(2) - (2)].s_select_list_item);
	}
    break;

  case 243:

/* Line 1455 of yacc.c  */
#line 1708 "sql.yacc"
    {
		 (yyval.s_select_list_item)=(yyvsp[(2) - (2)].s_select_list_item);
	}
    break;

  case 244:

/* Line 1455 of yacc.c  */
#line 1715 "sql.yacc"
    {
		(yyval.u_table)=(yyvsp[(2) - (2)].u_table);
	}
    break;

  case 245:

/* Line 1455 of yacc.c  */
#line 1721 "sql.yacc"
    {(yyval.u_table)=(yyvsp[(1) - (1)].u_table);}
    break;

  case 246:

/* Line 1455 of yacc.c  */
#line 1722 "sql.yacc"
    {
		(yyval.u_table)=A4GLSQLPARSE_append_tablename((yyvsp[(1) - (3)].u_table),(yyvsp[(3) - (3)].u_table),E_OUTER_NONE,NULL);
	}
    break;

  case 247:

/* Line 1455 of yacc.c  */
#line 1725 "sql.yacc"
    {
		(yyval.u_table)=A4GLSQLPARSE_append_tablename((yyvsp[(1) - (4)].u_table),(yyvsp[(4) - (4)].u_table),E_OUTER_NORMAL,NULL);
		A4GL_warn("OUTER join *may* not be portable to non-informix database");
		add_feature("SELECT_OUTER");
	}
    break;

  case 248:

/* Line 1455 of yacc.c  */
#line 1730 "sql.yacc"
    {
		(yyval.u_table)=A4GLSQLPARSE_append_tablename((yyvsp[(1) - (6)].u_table),(yyvsp[(5) - (6)].u_table),E_OUTER_NORMAL,NULL);
		A4GL_warn("OUTER join *may* not be portable to non-informix database");
		add_feature("SELECT_OUTER");
	}
    break;

  case 249:

/* Line 1455 of yacc.c  */
#line 1741 "sql.yacc"
    {
		(yyval.u_table)=A4GLSQLPARSE_append_tablename((yyvsp[(1) - (5)].u_table),(yyvsp[(3) - (5)].u_table),E_OUTER_LEFT_OUTER, (yyvsp[(5) - (5)].s_select_list_item));
		add_feature("SELECT_OUTER");
	}
    break;

  case 250:

/* Line 1455 of yacc.c  */
#line 1745 "sql.yacc"
    {
		(yyval.u_table)=A4GLSQLPARSE_append_tablename((yyvsp[(1) - (5)].u_table),(yyvsp[(3) - (5)].u_table),E_INNER, (yyvsp[(5) - (5)].s_select_list_item));
		add_feature("SELECT_INNER");
	}
    break;

  case 252:

/* Line 1455 of yacc.c  */
#line 1753 "sql.yacc"
    {(yyval.u_table)=(yyvsp[(2) - (3)].u_table);}
    break;

  case 253:

/* Line 1455 of yacc.c  */
#line 1757 "sql.yacc"
    { 
			//A4GL_add_crud("SELECT",$<str>1);
			(yyval.u_table)=A4GLSQLPARSE_new_tablename((yyvsp[(1) - (1)].str),NULL);
	}
    break;

  case 254:

/* Line 1455 of yacc.c  */
#line 1761 "sql.yacc"
    { 
			//A4GL_add_crud("SELECT",$<str>1);
			(yyval.u_table)=A4GLSQLPARSE_new_tablename((yyvsp[(1) - (2)].str),(yyvsp[(2) - (2)].str));
	}
    break;

  case 255:

/* Line 1455 of yacc.c  */
#line 1765 "sql.yacc"
    { 
			//A4GL_add_crud("SELECT",$<str>1);
			(yyval.u_table)=A4GLSQLPARSE_new_tablename((yyvsp[(1) - (3)].str),(yyvsp[(3) - (3)].str));
	}
    break;

  case 256:

/* Line 1455 of yacc.c  */
#line 1772 "sql.yacc"
    {
			/* No from or where etc.. */
			/* eg.. select user ; */
			(yyval.s_select)=new_empty_select();
		}
    break;

  case 257:

/* Line 1455 of yacc.c  */
#line 1777 "sql.yacc"
    {
		(yyval.s_select)=(yyvsp[(2) - (2)].s_select);
		(yyval.s_select)->first=(yyvsp[(1) - (2)].u_table);
			A4GL_set_associated_mem( (yyval.s_select), (yyval.s_select)->first);
}
    break;

  case 258:

/* Line 1455 of yacc.c  */
#line 1785 "sql.yacc"
    {
		(yyval.s_select)=(yyvsp[(1) - (1)].s_select);
	}
    break;

  case 259:

/* Line 1455 of yacc.c  */
#line 1788 "sql.yacc"
    {
		(yyval.s_select)=(yyvsp[(2) - (2)].s_select);
		(yyval.s_select)->where_clause=(yyvsp[(1) - (2)].s_select_list_item);
	}
    break;

  case 260:

/* Line 1455 of yacc.c  */
#line 1794 "sql.yacc"
    {
		(yyval.s_select)=new_empty_select();
	}
    break;

  case 261:

/* Line 1455 of yacc.c  */
#line 1797 "sql.yacc"
    {
		(yyval.s_select)=new_empty_select();
		(yyval.s_select)->group_by=(yyvsp[(1) - (1)].s_select_list_item_list);
		(yyval.s_select)->having=0;
	}
    break;

  case 262:

/* Line 1455 of yacc.c  */
#line 1802 "sql.yacc"
    {
		(yyval.s_select)=new_empty_select();
		(yyval.s_select)->group_by=(yyvsp[(1) - (2)].s_select_list_item_list);
		(yyval.s_select)->having=(yyvsp[(2) - (2)].s_select_list_item);
	}
    break;

  case 263:

/* Line 1455 of yacc.c  */
#line 1807 "sql.yacc"
    {
		(yyval.s_select)=new_empty_select();
		(yyval.s_select)->group_by=0;
		(yyval.s_select)->having=(yyvsp[(1) - (1)].s_select_list_item);

	}
    break;

  case 264:

/* Line 1455 of yacc.c  */
#line 1820 "sql.yacc"
    {
		(yyval.s_select_list_item)=(yyvsp[(1) - (1)].s_select_list_item);
	}
    break;

  case 265:

/* Line 1455 of yacc.c  */
#line 1823 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_op_expr((yyvsp[(1) - (3)].s_select_list_item),(yyvsp[(3) - (3)].s_select_list_item)," OR ");
	}
    break;

  case 266:

/* Line 1455 of yacc.c  */
#line 1829 "sql.yacc"
    {
		(yyval.s_select_list_item)=(yyvsp[(1) - (1)].s_select_list_item);
	}
    break;

  case 267:

/* Line 1455 of yacc.c  */
#line 1832 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_op_expr((yyvsp[(1) - (3)].s_select_list_item),(yyvsp[(3) - (3)].s_select_list_item)," AND ");
	}
    break;

  case 268:

/* Line 1455 of yacc.c  */
#line 1838 "sql.yacc"
    {
		(yyval.s_select_list_item)=(yyvsp[(1) - (1)].s_select_list_item);
	}
    break;

  case 269:

/* Line 1455 of yacc.c  */
#line 1841 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_simple_expr(E_SLI_NOT,(yyvsp[(2) - (2)].s_select_list_item));
	}
    break;

  case 270:

/* Line 1455 of yacc.c  */
#line 1847 "sql.yacc"
    {
		(yyval.s_select_list_item)=(yyvsp[(1) - (1)].s_select_list_item);
	}
    break;

  case 271:

/* Line 1455 of yacc.c  */
#line 1850 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_simple_expr(E_SLI_BRACKET_EXPR,(yyvsp[(2) - (3)].s_select_list_item));
	}
    break;

  case 272:

/* Line 1455 of yacc.c  */
#line 1857 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_sq(E_SQE_EXISTS, (yyvsp[(2) - (2)].s_select_list_item));
		add_feature("WHERE_EXISTS");
	}
    break;

  case 273:

/* Line 1455 of yacc.c  */
#line 1861 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_sq(E_SQE_NOT_EXISTS, (yyvsp[(2) - (2)].s_select_list_item));
		add_feature("WHERE_EXISTS");
	}
    break;

  case 274:

/* Line 1455 of yacc.c  */
#line 1872 "sql.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 275:

/* Line 1455 of yacc.c  */
#line 1872 "sql.yacc"
    {SPRINTF1((yyval.str)," ESCAPE %s",(yyvsp[(2) - (2)].str));add_feature("WHERE_MATCHES_ESCAPE");}
    break;

  case 276:

/* Line 1455 of yacc.c  */
#line 1873 "sql.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 277:

/* Line 1455 of yacc.c  */
#line 1873 "sql.yacc"
    {SPRINTF1((yyval.str)," ESCAPE %s",(yyvsp[(2) - (2)].str));add_feature("WHERE_ILIKE_ESCAPE");}
    break;

  case 278:

/* Line 1455 of yacc.c  */
#line 1874 "sql.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 279:

/* Line 1455 of yacc.c  */
#line 1874 "sql.yacc"
    {SPRINTF1((yyval.str)," ESCAPE %s",(yyvsp[(2) - (2)].str));add_feature("WHERE_LIKE_ESCAPE");}
    break;

  case 280:

/* Line 1455 of yacc.c  */
#line 1877 "sql.yacc"
    {
		 (yyval.s_select_list_item)=(yyvsp[(1) - (1)].s_select_list_item);
	}
    break;

  case 282:

/* Line 1455 of yacc.c  */
#line 1887 "sql.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 283:

/* Line 1455 of yacc.c  */
#line 1888 "sql.yacc"
    {strcpy((yyval.str)," NOT ");}
    break;

  case 284:

/* Line 1455 of yacc.c  */
#line 1893 "sql.yacc"
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
#line 1902 "sql.yacc"
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
#line 1910 "sql.yacc"
    { 
			(yyval.s_select_list_item)=new_select_list_item_op_expr((yyvsp[(1) - (3)].s_select_list_item),(yyvsp[(3) - (3)].s_select_list_item),(yyvsp[(2) - (3)].str));
	}
    break;

  case 287:

/* Line 1455 of yacc.c  */
#line 1913 "sql.yacc"
    { 
			(yyval.s_select_list_item)=new_select_list_item_op_expr((yyvsp[(1) - (3)].s_select_list_item),(yyvsp[(3) - (3)].s_select_list_item),"=");
	}
    break;

  case 288:

/* Line 1455 of yacc.c  */
#line 1916 "sql.yacc"
    { 
			FPRINTF(stderr,"Warning: Corrected =NULL to IS NULL line %d\n",yylineno);
			(yyval.s_select_list_item)=new_select_list_item_simple_expr(E_SLI_ISNULL,(yyvsp[(1) - (3)].s_select_list_item));
	}
    break;

  case 289:

/* Line 1455 of yacc.c  */
#line 1920 "sql.yacc"
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
#line 1927 "sql.yacc"
    { 
			(yyval.s_select_list_item)=new_select_list_item_regex(E_SLI_REGEX_LIKE,(yyvsp[(1) - (4)].s_select_list_item),(yyvsp[(3) - (4)].s_select_list_item),(yyvsp[(4) - (4)].str));
	}
    break;

  case 291:

/* Line 1455 of yacc.c  */
#line 1930 "sql.yacc"
    { 
			(yyval.s_select_list_item)=new_select_list_item_regex(E_SLI_REGEX_NOT_LIKE,(yyvsp[(1) - (4)].s_select_list_item),(yyvsp[(3) - (4)].s_select_list_item),(yyvsp[(4) - (4)].str));

	}
    break;

  case 292:

/* Line 1455 of yacc.c  */
#line 1934 "sql.yacc"
    { 
			(yyval.s_select_list_item)=new_select_list_item_regex(E_SLI_REGEX_ILIKE,(yyvsp[(1) - (4)].s_select_list_item),(yyvsp[(3) - (4)].s_select_list_item),(yyvsp[(4) - (4)].str));
	}
    break;

  case 293:

/* Line 1455 of yacc.c  */
#line 1937 "sql.yacc"
    { 
			(yyval.s_select_list_item)=new_select_list_item_regex(E_SLI_REGEX_NOT_ILIKE,(yyvsp[(1) - (4)].s_select_list_item),(yyvsp[(3) - (4)].s_select_list_item),(yyvsp[(4) - (4)].str));
	}
    break;

  case 294:

/* Line 1455 of yacc.c  */
#line 1940 "sql.yacc"
    { 
			(yyval.s_select_list_item)=new_select_list_item_regex(E_SLI_REGEX_MATCHES,(yyvsp[(1) - (4)].s_select_list_item),(yyvsp[(3) - (4)].s_select_list_item),(yyvsp[(4) - (4)].str));
	}
    break;

  case 295:

/* Line 1455 of yacc.c  */
#line 1943 "sql.yacc"
    { 
			(yyval.s_select_list_item)=new_select_list_item_regex(E_SLI_REGEX_NOT_MATCHES,(yyvsp[(1) - (4)].s_select_list_item),(yyvsp[(3) - (4)].s_select_list_item),(yyvsp[(4) - (4)].str));
	}
    break;

  case 296:

/* Line 1455 of yacc.c  */
#line 1949 "sql.yacc"
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
#line 1956 "sql.yacc"
    {
			strcpy((yyval.str)," < ");
	}
    break;

  case 298:

/* Line 1455 of yacc.c  */
#line 1959 "sql.yacc"
    {
			strcpy((yyval.str)," > ");
	}
    break;

  case 299:

/* Line 1455 of yacc.c  */
#line 1962 "sql.yacc"
    {
			strcpy((yyval.str)," ~ ");
	}
    break;

  case 300:

/* Line 1455 of yacc.c  */
#line 1965 "sql.yacc"
    {strcpy((yyval.str)," <= ");}
    break;

  case 301:

/* Line 1455 of yacc.c  */
#line 1966 "sql.yacc"
    {strcpy((yyval.str)," >= ");}
    break;

  case 302:

/* Line 1455 of yacc.c  */
#line 1971 "sql.yacc"
    {
		(yyval.s_select_list_item)=(yyvsp[(1) - (1)].s_select_list_item);
	}
    break;

  case 303:

/* Line 1455 of yacc.c  */
#line 1974 "sql.yacc"
    {
		(yyval.s_select_list_item)=(yyvsp[(1) - (1)].s_select_list_item);
	}
    break;

  case 304:

/* Line 1455 of yacc.c  */
#line 1977 "sql.yacc"
    {
		(yyval.s_select_list_item)=(yyvsp[(1) - (1)].s_select_list_item);
	}
    break;

  case 305:

/* Line 1455 of yacc.c  */
#line 1980 "sql.yacc"
    {
                 (yyval.s_select_list_item)=(yyvsp[(1) - (1)].s_select_list_item);
        }
    break;

  case 306:

/* Line 1455 of yacc.c  */
#line 1987 "sql.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 307:

/* Line 1455 of yacc.c  */
#line 1988 "sql.yacc"
    {strcpy((yyval.str)," ALL "); add_feature("AGG_ALL");}
    break;

  case 308:

/* Line 1455 of yacc.c  */
#line 1989 "sql.yacc"
    {
		strcpy((yyval.str)," DISTINCT ");
		add_feature("AGG_DISTINCT");
	}
    break;

  case 309:

/* Line 1455 of yacc.c  */
#line 1993 "sql.yacc"
    {
		ansi_violation("Use DISTINCT not UNIQUE",0);
		strcpy((yyval.str)," DISTINCT ");
		add_feature("AGG_DISTINCT");
	}
    break;

  case 310:

/* Line 1455 of yacc.c  */
#line 2000 "sql.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 311:

/* Line 1455 of yacc.c  */
#line 2001 "sql.yacc"
    {strcpy((yyval.str)," ALL "); add_feature("UNION_ALL");}
    break;

  case 312:

/* Line 1455 of yacc.c  */
#line 2002 "sql.yacc"
    {
		strcpy((yyval.str)," DISTINCT ");
		add_feature("UNION_DISTINCT");
	}
    break;

  case 313:

/* Line 1455 of yacc.c  */
#line 2006 "sql.yacc"
    {
		ansi_violation("Use DISTINCT not UNIQUE",0);
		add_feature("UNION_DISTINCT");
		strcpy((yyval.str)," DISTINCT ");
	}
    break;

  case 314:

/* Line 1455 of yacc.c  */
#line 2020 "sql.yacc"
    {
		strcpy((yyval.str),A4GLSQLCV_dtype_alias((yyvsp[(1) - (1)].str)));
	}
    break;

  case 319:

/* Line 1455 of yacc.c  */
#line 2035 "sql.yacc"
    {SPRINTF4((yyval.str)," %s %s%s%s",(yyvsp[(1) - (4)].str),(yyvsp[(2) - (4)].str),(yyvsp[(3) - (4)].str),(yyvsp[(4) - (4)].str));}
    break;

  case 320:

/* Line 1455 of yacc.c  */
#line 2039 "sql.yacc"
    {strcpy((yyval.str),"SERIAL"); add_feature("DDL_SERIAL"); }
    break;

  case 321:

/* Line 1455 of yacc.c  */
#line 2040 "sql.yacc"
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
#line 2049 "sql.yacc"
    {strcpy((yyval.str),"SERIAL8"); add_feature("DDL_SERIAL8"); }
    break;

  case 323:

/* Line 1455 of yacc.c  */
#line 2051 "sql.yacc"
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
#line 2060 "sql.yacc"
    {
 			add_feature("DDL_DECIMAL");
	}
    break;

  case 325:

/* Line 1455 of yacc.c  */
#line 2063 "sql.yacc"
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
#line 2071 "sql.yacc"
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
#line 2081 "sql.yacc"
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
#line 2089 "sql.yacc"
    {strcpy((yyval.str),"DATE");
 			add_feature("DDL_DATE"); }
    break;

  case 329:

/* Line 1455 of yacc.c  */
#line 2091 "sql.yacc"
    {strcpy((yyval.str),"INTEGER");}
    break;

  case 330:

/* Line 1455 of yacc.c  */
#line 2092 "sql.yacc"
    {strcpy((yyval.str),"SMALLINT");}
    break;

  case 331:

/* Line 1455 of yacc.c  */
#line 2093 "sql.yacc"
    {strcpy((yyval.str),"NCHAR"); add_feature("DDL_NCHAR");}
    break;

  case 332:

/* Line 1455 of yacc.c  */
#line 2094 "sql.yacc"
    {SPRINTF1((yyval.str),"NCHAR(%s)",(yyvsp[(3) - (4)].str)); add_feature("DDL_NCHAR");}
    break;

  case 333:

/* Line 1455 of yacc.c  */
#line 2095 "sql.yacc"
    {add_feature("DDL_NVARCHAR");}
    break;

  case 334:

/* Line 1455 of yacc.c  */
#line 2096 "sql.yacc"
    {SPRINTF1((yyval.str),"NVARCHAR(%s)",(yyvsp[(3) - (4)].str)); add_feature("DDL_NVARCHAR");}
    break;

  case 335:

/* Line 1455 of yacc.c  */
#line 2097 "sql.yacc"
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
#line 2105 "sql.yacc"
    {SPRINTF2((yyval.str),"DATETIME %s TO %s",(yyvsp[(2) - (4)].str),(yyvsp[(4) - (4)].str)); add_feature("DDL_DATETIME");}
    break;

  case 337:

/* Line 1455 of yacc.c  */
#line 2106 "sql.yacc"
    {add_feature("DDL_DATETIME");}
    break;

  case 338:

/* Line 1455 of yacc.c  */
#line 2107 "sql.yacc"
    {SPRINTF2((yyval.str),"INTERVAL %s TO %s",(yyvsp[(2) - (4)].str),(yyvsp[(4) - (4)].str)); add_feature("DDL_INTERVAL");}
    break;

  case 339:

/* Line 1455 of yacc.c  */
#line 2108 "sql.yacc"
    {strcpy((yyval.str),(yyvsp[(1) - (1)].str));}
    break;

  case 340:

/* Line 1455 of yacc.c  */
#line 2109 "sql.yacc"
    {add_feature("DDL_INTERVAL");}
    break;

  case 341:

/* Line 1455 of yacc.c  */
#line 2110 "sql.yacc"
    {SPRINTF3((yyval.str),"INTERVAL %s(%s) TO %s",(yyvsp[(2) - (7)].str),(yyvsp[(4) - (7)].str),(yyvsp[(7) - (7)].str)); add_feature("DDL_INTERVAL");}
    break;

  case 342:

/* Line 1455 of yacc.c  */
#line 2111 "sql.yacc"
    {add_feature("DDL_TEXT");}
    break;

  case 343:

/* Line 1455 of yacc.c  */
#line 2112 "sql.yacc"
    {add_feature("DDL_BYTE");}
    break;

  case 344:

/* Line 1455 of yacc.c  */
#line 2113 "sql.yacc"
    {add_feature("DDL_VARCHAR");}
    break;

  case 345:

/* Line 1455 of yacc.c  */
#line 2114 "sql.yacc"
    {SPRINTF1((yyval.str),"VARCHAR(%s)",(yyvsp[(3) - (4)].str));add_feature("DDL_VARCHAR");}
    break;

  case 346:

/* Line 1455 of yacc.c  */
#line 2115 "sql.yacc"
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
#line 2125 "sql.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 348:

/* Line 1455 of yacc.c  */
#line 2126 "sql.yacc"
    {
		SPRINTF1((yyval.str),",%s",(yyvsp[(2) - (2)].str));
}
    break;

  case 349:

/* Line 1455 of yacc.c  */
#line 2133 "sql.yacc"
    {SPRINTF4((yyval.str)," %s %s %s %s",(yyvsp[(1) - (4)].str),(yyvsp[(2) - (4)].str),(yyvsp[(3) - (4)].str),(yyvsp[(4) - (4)].str));}
    break;

  case 353:

/* Line 1455 of yacc.c  */
#line 2137 "sql.yacc"
    {add_feature("DDL_DOUBLE_PRECISION"); SPRINTF1((yyval.str)," %s",(yyvsp[(1) - (1)].str));}
    break;

  case 359:

/* Line 1455 of yacc.c  */
#line 2162 "sql.yacc"
    {(yyval.int_list.i0)=0;}
    break;

  case 360:

/* Line 1455 of yacc.c  */
#line 2163 "sql.yacc"
    {
		(yyval.int_list.i0)=1;
		(yyval.int_list.i1)=atoi((yyvsp[(2) - (3)].str));
	}
    break;

  case 361:

/* Line 1455 of yacc.c  */
#line 2167 "sql.yacc"
    {
		(yyval.int_list.i0)=2;
		(yyval.int_list.i1)=atoi((yyvsp[(2) - (5)].str));
		(yyval.int_list.i2)=atoi((yyvsp[(4) - (5)].str));
	}
    break;

  case 362:

/* Line 1455 of yacc.c  */
#line 2175 "sql.yacc"
    {
		strcpy((yyval.str),(yyvsp[(1) - (1)].str));
	}
    break;

  case 363:

/* Line 1455 of yacc.c  */
#line 2178 "sql.yacc"
    {
		strcpy((yyval.str),(yyvsp[(2) - (2)].str));
	}
    break;

  case 364:

/* Line 1455 of yacc.c  */
#line 2185 "sql.yacc"
    {
		(yyval.s_select_list_item)= (yyvsp[(1) - (1)].s_select_list_item);
	}
    break;

  case 365:

/* Line 1455 of yacc.c  */
#line 2188 "sql.yacc"
    {
		(yyval.s_select_list_item)= (yyvsp[(2) - (2)].s_select_list_item);
	}
    break;

  case 366:

/* Line 1455 of yacc.c  */
#line 2198 "sql.yacc"
    { 
		(yyval.s_select_list_item)=new_select_list_item_col(0,(yyvsp[(1) - (2)].str),&(yyvsp[(2) - (2)].int_list));
	}
    break;

  case 367:

/* Line 1455 of yacc.c  */
#line 2201 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_col((yyvsp[(1) - (4)].str),(yyvsp[(3) - (4)].str),&(yyvsp[(4) - (4)].int_list));
	}
    break;

  case 368:

/* Line 1455 of yacc.c  */
#line 2204 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_col((yyvsp[(1) - (3)].str),"*",0);
	}
    break;

  case 369:

/* Line 1455 of yacc.c  */
#line 2207 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_col(0,"rowid",0);
	}
    break;

  case 370:

/* Line 1455 of yacc.c  */
#line 2214 "sql.yacc"
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
#line 2221 "sql.yacc"
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
#line 2229 "sql.yacc"
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
#line 2238 "sql.yacc"
    {
		SPRINTF1((yyval.str),"%s",A4GLSQLCV_check_colname((yyvsp[(1) - (3)].str),"*"));
		ADDMAP("Use Column",(yyval.str));
	}
    break;

  case 375:

/* Line 1455 of yacc.c  */
#line 2249 "sql.yacc"
    { strcpy((yyval.str),(yyvsp[(1) - (1)].str)); A4GL_debug("Set $<str>$ to %s\n",(yyval.str)); }
    break;

  case 379:

/* Line 1455 of yacc.c  */
#line 2257 "sql.yacc"
    { strcpy((yyval.str),A4GLSQLCV_generate_current(0,0)); 
}
    break;

  case 380:

/* Line 1455 of yacc.c  */
#line 2259 "sql.yacc"
    {
		strcpy((yyval.str),A4GLSQLCV_generate_current((yyvsp[(1) - (3)].str),(yyvsp[(3) - (3)].str)));
	}
    break;

  case 395:

/* Line 1455 of yacc.c  */
#line 2269 "sql.yacc"
    {SPRINTF1((yyval.str),"FRACTION(%s)",(yyvsp[(3) - (4)].str));}
    break;

  case 396:

/* Line 1455 of yacc.c  */
#line 2284 "sql.yacc"
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
#line 2292 "sql.yacc"
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
#line 2304 "sql.yacc"
    { (yyval.sql_string)=make_sql_string_and_free(acl_strdup((yyvsp[(1) - (1)].str)), NULL);}
    break;

  case 399:

/* Line 1455 of yacc.c  */
#line 2305 "sql.yacc"
    { (yyval.sql_string)=make_sql_string_and_free(acl_strdup((yyvsp[(1) - (1)].str)), NULL);}
    break;

  case 400:

/* Line 1455 of yacc.c  */
#line 2306 "sql.yacc"
    { (yyval.sql_string)=make_sql_string_and_free(acl_strdup((yyvsp[(1) - (1)].str)), NULL);}
    break;

  case 401:

/* Line 1455 of yacc.c  */
#line 2307 "sql.yacc"
    { (yyval.sql_string)=make_sql_string_and_free(acl_strdup((yyvsp[(1) - (1)].str)), NULL);}
    break;

  case 402:

/* Line 1455 of yacc.c  */
#line 2312 "sql.yacc"
    { add_feature("RENAME_TABLE"); strcpy((yyval.str),A4GLSQLCV_rentab((yyvsp[(2) - (4)].str),(yyvsp[(4) - (4)].str))); }
    break;

  case 403:

/* Line 1455 of yacc.c  */
#line 2313 "sql.yacc"
    { add_feature("RENAME_COLUMN"); strcpy((yyval.str),A4GLSQLCV_rencol((yyvsp[(2) - (6)].str),(yyvsp[(4) - (6)].str),(yyvsp[(6) - (6)].str)) ); }
    break;

  case 406:

/* Line 1455 of yacc.c  */
#line 2321 "sql.yacc"
    {
		add_feature("UNLOCK_TABLE");
		SPRINTF2((yyval.str),"%s %s",(yyvsp[(1) - (2)].str),(yyvsp[(2) - (2)].str));
	}
    break;

  case 407:

/* Line 1455 of yacc.c  */
#line 2328 "sql.yacc"
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
#line 2339 "sql.yacc"
    { add_feature("LOCK_TABLE_SHARED");}
    break;

  case 409:

/* Line 1455 of yacc.c  */
#line 2340 "sql.yacc"
    {add_feature("LOCK_TABLE_EXCLUSIVE");}
    break;

  case 410:

/* Line 1455 of yacc.c  */
#line 2353 "sql.yacc"
    {strcpy((yyval.str),A4GLSQLCV_datetime_value((yyvsp[(1) - (1)].str)));}
    break;

  case 411:

/* Line 1455 of yacc.c  */
#line 2354 "sql.yacc"
    {strcpy((yyval.str),A4GLSQLCV_make_dtime_extend((yyvsp[(1) - (4)].str),(yyvsp[(2) - (4)].str),(yyvsp[(4) - (4)].str),0));}
    break;

  case 412:

/* Line 1455 of yacc.c  */
#line 2358 "sql.yacc"
    {strcpy((yyval.str),(yyvsp[(1) - (1)].str));}
    break;

  case 413:

/* Line 1455 of yacc.c  */
#line 2362 "sql.yacc"
    {strcpy((yyval.str),A4GLSQLCV_interval_value((yyvsp[(1) - (1)].str)));}
    break;

  case 414:

/* Line 1455 of yacc.c  */
#line 2363 "sql.yacc"
    {
			strcpy((yyval.str),A4GLSQLCV_make_ival_extend((yyvsp[(1) - (7)].str),(yyvsp[(2) - (7)].str),(yyvsp[(4) - (7)].str),(yyvsp[(7) - (7)].str),0));
		}
    break;

  case 415:

/* Line 1455 of yacc.c  */
#line 2366 "sql.yacc"
    {
		strcpy((yyval.str),A4GLSQLCV_make_ival_extend((yyvsp[(1) - (4)].str),(yyvsp[(2) - (4)].str),(char *)0, (yyvsp[(4) - (4)].str),0));
	}
    break;

  case 416:

/* Line 1455 of yacc.c  */
#line 2372 "sql.yacc"
    {SPRINTF1((yyval.str),"%s",(yyvsp[(1) - (1)].str));}
    break;

  case 417:

/* Line 1455 of yacc.c  */
#line 2376 "sql.yacc"
    {
	strcpy((yyval.str),(yyvsp[(2) - (2)].str));
}
    break;

  case 418:

/* Line 1455 of yacc.c  */
#line 2399 "sql.yacc"
    {
		(yyval.s_select_list_item_list)=(yyvsp[(3) - (3)].s_select_list_item_list);
		add_feature("ORDER_BY");
	}
    break;

  case 419:

/* Line 1455 of yacc.c  */
#line 2409 "sql.yacc"
    {
			(yyval.s_select_list_item_list)=local_new_select_list_item_list((yyvsp[(1) - (1)].s_select_list_item));
	}
    break;

  case 420:

/* Line 1455 of yacc.c  */
#line 2412 "sql.yacc"
    {
			(yyval.s_select_list_item_list)=local_add_select_list_item_list((yyvsp[(1) - (3)].s_select_list_item_list),(yyvsp[(3) - (3)].s_select_list_item));
	}
    break;

  case 421:

/* Line 1455 of yacc.c  */
#line 2418 "sql.yacc"
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
#line 2427 "sql.yacc"
    { 
		add_feature("ORDER_BY_NUMBER");
		(yyval.s_select_list_item)=new_select_list_item_literal((yyvsp[(1) - (1)].str));
	}
    break;

  case 423:

/* Line 1455 of yacc.c  */
#line 2431 "sql.yacc"
    {
		(yyval.s_select_list_item)=(yyvsp[(1) - (1)].s_select_list_item);
		(yyval.s_select_list_item)->data.type=E_SLI_COLUMN_ORDERBY;
	}
    break;

  case 424:

/* Line 1455 of yacc.c  */
#line 2438 "sql.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 425:

/* Line 1455 of yacc.c  */
#line 2440 "sql.yacc"
    {add_feature("ORDER_BY_ASC"); strcpy((yyval.str),"ASC");}
    break;

  case 426:

/* Line 1455 of yacc.c  */
#line 2442 "sql.yacc"
    {add_feature("ORDER_BY_DESC"); strcpy((yyval.str),"DESC");}
    break;

  case 427:

/* Line 1455 of yacc.c  */
#line 2446 "sql.yacc"
    {
		(yyval.s_select_list_item_list)=(yyvsp[(2) - (2)].s_select_list_item_list);
	}
    break;

  case 428:

/* Line 1455 of yacc.c  */
#line 2452 "sql.yacc"
    {
			(yyval.s_select_list_item_list)=local_new_select_list_item_list((yyvsp[(1) - (1)].s_select_list_item));
	}
    break;

  case 429:

/* Line 1455 of yacc.c  */
#line 2455 "sql.yacc"
    {
			(yyval.s_select_list_item_list)=local_add_select_list_item_list((yyvsp[(1) - (3)].s_select_list_item_list),(yyvsp[(3) - (3)].s_select_list_item));
	}
    break;

  case 430:

/* Line 1455 of yacc.c  */
#line 2461 "sql.yacc"
    { (yyval.s_select_list_item)=(yyvsp[(1) - (1)].s_select_list_item); }
    break;

  case 431:

/* Line 1455 of yacc.c  */
#line 2462 "sql.yacc"
    { (yyval.s_select_list_item)=new_select_list_item_literal((yyvsp[(1) - (1)].str)); }
    break;

  case 432:

/* Line 1455 of yacc.c  */
#line 2469 "sql.yacc"
    {
	(yyval.sql_string)=get_select_list_item(0,(yyvsp[(1) - (1)].s_select_list_item));
}
    break;

  case 433:

/* Line 1455 of yacc.c  */
#line 2482 "sql.yacc"
    {
		A4GL_set_sql_lineno(yylineno);
		(yyval.sql_string)=make_select_stmt_v2(current_upd_table, (yyvsp[(1) - (1)].s_select),"");
		map_select_stmt("SELECT",(yyvsp[(1) - (1)].s_select));
		A4GL_free_select_stmt((yyvsp[(1) - (1)].s_select));
}
    break;

  case 434:

/* Line 1455 of yacc.c  */
#line 2492 "sql.yacc"
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
#line 2499 "sql.yacc"
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
#line 2516 "sql.yacc"
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
#line 2523 "sql.yacc"
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
#line 2548 "sql.yacc"
    { 
		//start_bind('i',0);
		 set_ignore_indicators();}
    break;

  case 439:

/* Line 1455 of yacc.c  */
#line 2550 "sql.yacc"
    { clr_ignore_indicators();}
    break;

  case 440:

/* Line 1455 of yacc.c  */
#line 2552 "sql.yacc"
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
#line 2573 "sql.yacc"
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
#line 2616 "sql.yacc"
    { (yyval.s_select)=0;}
    break;

  case 443:

/* Line 1455 of yacc.c  */
#line 2617 "sql.yacc"
    { 
		(yyval.s_select)=(yyvsp[(3) - (3)].s_select);
		(yyval.s_select)->union_op=acl_strdup((yyvsp[(2) - (3)].str));
		A4GL_set_associated_mem((yyval.s_select), (yyval.s_select)->union_op);
		add_feature("SELECT_UNION"); 
	}
    break;

  case 444:

/* Line 1455 of yacc.c  */
#line 2631 "sql.yacc"
    {
		(yyval.s_select_finish)=0;
	}
    break;

  case 445:

/* Line 1455 of yacc.c  */
#line 2634 "sql.yacc"
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
#line 2641 "sql.yacc"
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
#line 2651 "sql.yacc"
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
#line 2669 "sql.yacc"
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
#line 2682 "sql.yacc"
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
#line 2697 "sql.yacc"
    {(yyval.integer_val)=-1;}
    break;

  case 452:

/* Line 1455 of yacc.c  */
#line 2699 "sql.yacc"
    {
		(yyval.integer_val)=atol((yyvsp[(2) - (2)].str));
	}
    break;

  case 453:

/* Line 1455 of yacc.c  */
#line 2705 "sql.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 454:

/* Line 1455 of yacc.c  */
#line 2706 "sql.yacc"
    {strcpy((yyval.str),"ALL"); add_feature("SELECT_ALL");}
    break;

  case 455:

/* Line 1455 of yacc.c  */
#line 2707 "sql.yacc"
    {strcpy((yyval.str),"DISTINCT"); add_feature("SELECT_DISTINCT");}
    break;

  case 456:

/* Line 1455 of yacc.c  */
#line 2708 "sql.yacc"
    {strcpy((yyval.str),"DISTINCT");
		add_feature("SELECT_UNIQUE");
		ansi_violation("Use DISTINCT not UNIQUE",0);
		strcpy((yyval.str),"DISTINCT");
	}
    break;

  case 457:

/* Line 1455 of yacc.c  */
#line 2718 "sql.yacc"
    { 
		 (yyval.s_select_list_item_list)=local_new_select_list_item_list((yyvsp[(1) - (1)].s_select_list_item));
	}
    break;

  case 458:

/* Line 1455 of yacc.c  */
#line 2721 "sql.yacc"
    { 
		(yyval.s_select_list_item_list)=local_add_select_list_item_list((yyvsp[(1) - (3)].s_select_list_item_list),(yyvsp[(3) - (3)].s_select_list_item));
	}
    break;

  case 459:

/* Line 1455 of yacc.c  */
#line 2727 "sql.yacc"
    {
		(yyval.s_select_list_item)=(yyvsp[(1) - (1)].s_select_list_item);
	}
    break;

  case 460:

/* Line 1455 of yacc.c  */
#line 2730 "sql.yacc"
    {
		(yyval.s_select_list_item)=(yyvsp[(1) - (2)].s_select_list_item);
		(yyval.s_select_list_item)->alias=acl_strdup((yyvsp[(2) - (2)].str));
		A4GL_set_associated_mem((yyval.s_select_list_item), (yyval.s_select_list_item)->alias);
	}
    break;

  case 461:

/* Line 1455 of yacc.c  */
#line 2735 "sql.yacc"
    {
		(yyval.s_select_list_item)=(yyvsp[(1) - (3)].s_select_list_item);
		(yyval.s_select_list_item)->alias=acl_strdup((yyvsp[(3) - (3)].str));
		A4GL_set_associated_mem((yyval.s_select_list_item), (yyval.s_select_list_item)->alias);
	}
    break;

  case 462:

/* Line 1455 of yacc.c  */
#line 2744 "sql.yacc"
    {
		(yyval.s_select_list_item)=(yyvsp[(1) - (1)].s_select_list_item); /* A4GLSQLCV_check_expr($<sql_string>1) */
	}
    break;

  case 463:

/* Line 1455 of yacc.c  */
#line 2747 "sql.yacc"
    {
		(yyval.s_select_list_item)=(yyvsp[(2) - (2)].s_select_list_item);
		(yyval.s_select_list_item)->sign='-';
	}
    break;

  case 464:

/* Line 1455 of yacc.c  */
#line 2751 "sql.yacc"
    {
		(yyval.s_select_list_item)=(yyvsp[(2) - (2)].s_select_list_item);
	}
    break;

  case 465:

/* Line 1455 of yacc.c  */
#line 2758 "sql.yacc"
    {
			(yyval.s_select_list_item)=new_select_list_item_op_expr ((yyvsp[(1) - (3)].s_select_list_item), (yyvsp[(3) - (3)].s_select_list_item), "/");
	}
    break;

  case 466:

/* Line 1455 of yacc.c  */
#line 2761 "sql.yacc"
    {
			(yyval.s_select_list_item)=new_select_list_item_simple_expr((enum e_sli)(yyvsp[(2) - (2)].integer_val), (yyvsp[(1) - (2)].s_select_list_item));
	}
    break;

  case 467:

/* Line 1455 of yacc.c  */
#line 2764 "sql.yacc"
    {
			(yyval.s_select_list_item)=new_select_list_item_op_expr ((yyvsp[(1) - (3)].s_select_list_item), (yyvsp[(3) - (3)].s_select_list_item), "*");
	}
    break;

  case 468:

/* Line 1455 of yacc.c  */
#line 2767 "sql.yacc"
    {
			(yyval.s_select_list_item)=new_select_list_item_op_expr ((yyvsp[(1) - (3)].s_select_list_item), (yyvsp[(3) - (3)].s_select_list_item), "+");
	}
    break;

  case 469:

/* Line 1455 of yacc.c  */
#line 2770 "sql.yacc"
    {
			(yyval.s_select_list_item)=new_select_list_item_op_expr ((yyvsp[(1) - (3)].s_select_list_item), (yyvsp[(3) - (3)].s_select_list_item), "-");
	}
    break;

  case 470:

/* Line 1455 of yacc.c  */
#line 2773 "sql.yacc"
    { (yyval.s_select_list_item)=new_select_list_item_literal((yyvsp[(1) - (1)].str)); }
    break;

  case 471:

/* Line 1455 of yacc.c  */
#line 2774 "sql.yacc"
    { (yyval.s_select_list_item)=new_select_list_item_builtin_const(E_SLI_BUILTIN_CONST_TRUE); }
    break;

  case 472:

/* Line 1455 of yacc.c  */
#line 2775 "sql.yacc"
    { (yyval.s_select_list_item)=new_select_list_item_builtin_const(E_SLI_BUILTIN_CONST_FALSE); }
    break;

  case 473:

/* Line 1455 of yacc.c  */
#line 2776 "sql.yacc"
    { (yyval.s_select_list_item)=new_select_list_item_builtin_const(E_SLI_BUILTIN_CONST_USER); }
    break;

  case 474:

/* Line 1455 of yacc.c  */
#line 2777 "sql.yacc"
    { (yyval.s_select_list_item)=new_select_list_item_builtin_const(E_SLI_BUILTIN_CONST_TODAY); }
    break;

  case 475:

/* Line 1455 of yacc.c  */
#line 2778 "sql.yacc"
    { (yyval.s_select_list_item)=new_select_list_item_builtin_const(E_SLI_BUILTIN_CONST_ROWID); }
    break;

  case 476:

/* Line 1455 of yacc.c  */
#line 2779 "sql.yacc"
    { (yyval.s_select_list_item)=new_select_list_item_builtin_const(E_SLI_BUILTIN_CONST_TIME); }
    break;

  case 477:

/* Line 1455 of yacc.c  */
#line 2780 "sql.yacc"
    { (yyval.s_select_list_item)=new_select_list_item_builtin_const(E_SLI_BUILTIN_CONST_STAR); }
    break;

  case 478:

/* Line 1455 of yacc.c  */
#line 2781 "sql.yacc"
    { (yyval.s_select_list_item)=new_select_list_item_builtin_const(E_SLI_BUILTIN_CONST_COUNT_STAR); }
    break;

  case 479:

/* Line 1455 of yacc.c  */
#line 2783 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_agg1(E_SLI_BUILTIN_AGG_AVG,(yyvsp[(3) - (5)].str),(yyvsp[(4) - (5)].s_select_list_item));
		add_feature("SELECT_AVG");
	}
    break;

  case 480:

/* Line 1455 of yacc.c  */
#line 2787 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_agg1(E_SLI_BUILTIN_AGG_MAX,(yyvsp[(3) - (5)].str),(yyvsp[(4) - (5)].s_select_list_item));
		add_feature("SELECT_MAX");
	}
    break;

  case 481:

/* Line 1455 of yacc.c  */
#line 2791 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_agg1(E_SLI_BUILTIN_AGG_MIN,(yyvsp[(3) - (5)].str),(yyvsp[(4) - (5)].s_select_list_item));
		add_feature("SELECT_MIN");
	}
    break;

  case 482:

/* Line 1455 of yacc.c  */
#line 2795 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_agg1(E_SLI_BUILTIN_AGG_SUM,(yyvsp[(3) - (5)].str),(yyvsp[(4) - (5)].s_select_list_item));
		add_feature("SELECT_SUM");
	}
    break;

  case 483:

/* Line 1455 of yacc.c  */
#line 2799 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_agg1(E_SLI_BUILTIN_AGG_COUNT,(yyvsp[(3) - (5)].str),(yyvsp[(4) - (5)].s_select_list_item));
		add_feature("SELECT_COUNT");
	}
    break;

  case 484:

/* Line 1455 of yacc.c  */
#line 2803 "sql.yacc"
    {
		add_sql_function((yyvsp[(1) - (3)].str));
		(yyval.s_select_list_item)=new_select_list_item_fcall((yyvsp[(1) - (3)].str),0);
	}
    break;

  case 485:

/* Line 1455 of yacc.c  */
#line 2807 "sql.yacc"
    {
		add_sql_function((yyvsp[(1) - (4)].str));
		(yyval.s_select_list_item)=new_select_list_item_fcall((yyvsp[(1) - (4)].str),(yyvsp[(3) - (4)].s_select_list_item_list));
	}
    break;

  case 486:

/* Line 1455 of yacc.c  */
#line 2811 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_builtin_fcall(E_SLI_BUILTIN_FUNC_YEAR,(yyvsp[(3) - (4)].s_select_list_item_list));
	}
    break;

  case 487:

/* Line 1455 of yacc.c  */
#line 2814 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_builtin_fcall(E_SLI_BUILTIN_FUNC_MONTH,(yyvsp[(3) - (4)].s_select_list_item_list));
	}
    break;

  case 488:

/* Line 1455 of yacc.c  */
#line 2817 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_builtin_fcall(E_SLI_BUILTIN_FUNC_DAY,(yyvsp[(3) - (4)].s_select_list_item_list));
	}
    break;

  case 489:

/* Line 1455 of yacc.c  */
#line 2820 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_builtin_fcall(E_SLI_BUILTIN_FUNC_MDY,(yyvsp[(3) - (4)].s_select_list_item_list));
	}
    break;

  case 490:

/* Line 1455 of yacc.c  */
#line 2823 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_builtin_fcall(E_SLI_BUILTIN_FUNC_WEEKDAY,(yyvsp[(3) - (4)].s_select_list_item_list));
	}
    break;

  case 491:

/* Line 1455 of yacc.c  */
#line 2826 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_builtin_fcall(E_SLI_BUILTIN_FUNC_DOW,(yyvsp[(3) - (4)].s_select_list_item_list));
	}
    break;

  case 492:

/* Line 1455 of yacc.c  */
#line 2829 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_builtin_fcall(E_SLI_BUILTIN_FUNC_DATE,(yyvsp[(3) - (4)].s_select_list_item_list));
	}
    break;

  case 493:

/* Line 1455 of yacc.c  */
#line 2832 "sql.yacc"
    {
		  (yyval.s_select_list_item)=new_select_list_item_simple_expr(E_SLI_BRACKET_EXPR,(yyvsp[(2) - (3)].s_select_list_item));
	}
    break;

  case 494:

/* Line 1455 of yacc.c  */
#line 2835 "sql.yacc"
    { 
		add_feature("EXTEND"); 
		(yyval.s_select_list_item)=(yyvsp[(3) - (4)].s_select_list_item);
	}
    break;

  case 495:

/* Line 1455 of yacc.c  */
#line 2839 "sql.yacc"
    { 
		(yyval.s_select_list_item)=new_select_list_item_datetime((yyvsp[(1) - (1)].str));
		add_feature("FUNC_DATETIME");
	}
    break;

  case 496:

/* Line 1455 of yacc.c  */
#line 2843 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_interval((yyvsp[(1) - (1)].str));
		add_feature("FUNC_INTERVAL");
	}
    break;

  case 497:

/* Line 1455 of yacc.c  */
#line 2847 "sql.yacc"
    {
		(yyval.s_select_list_item)=(yyvsp[(2) - (3)].s_select_list_item);
	}
    break;

  case 498:

/* Line 1455 of yacc.c  */
#line 2855 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_case((yyvsp[(1) - (1)].s_select_list_item));
	}
    break;

  case 499:

/* Line 1455 of yacc.c  */
#line 2858 "sql.yacc"
    {
		(yyval.s_select_list_item)=append_select_list_item_case(
							(yyvsp[(1) - (2)].s_select_list_item),
							(yyvsp[(2) - (2)].s_select_list_item));
	}
    break;

  case 500:

/* Line 1455 of yacc.c  */
#line 2867 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_case_element(
				(yyvsp[(2) - (4)].s_select_list_item),
				(yyvsp[(4) - (4)].s_select_list_item));

	}
    break;

  case 501:

/* Line 1455 of yacc.c  */
#line 2873 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_case_element( 0, (yyvsp[(2) - (2)].s_select_list_item));
	}
    break;

  case 502:

/* Line 1455 of yacc.c  */
#line 2880 "sql.yacc"
    {
		(yyval.s_select_list_item_list)=local_new_select_list_item_list((yyvsp[(1) - (1)].s_select_list_item));
	}
    break;

  case 503:

/* Line 1455 of yacc.c  */
#line 2883 "sql.yacc"
    {
			(yyval.s_select_list_item_list)=local_add_select_list_item_list((yyvsp[(1) - (3)].s_select_list_item_list),(yyvsp[(3) - (3)].s_select_list_item));
	}
    break;

  case 504:

/* Line 1455 of yacc.c  */
#line 2911 "sql.yacc"
    {
			(yyval.s_select_list_item)=new_select_list_item_extend(new_select_list_item_builtin_const(E_SLI_BUILTIN_CONST_CURRENT),(yyvsp[(3) - (5)].str),(yyvsp[(5) - (5)].str));
	}
    break;

  case 505:

/* Line 1455 of yacc.c  */
#line 2914 "sql.yacc"
    {
			(yyval.s_select_list_item)=new_select_list_item_extend((yyvsp[(1) - (5)].s_select_list_item),(yyvsp[(3) - (5)].str),(yyvsp[(5) - (5)].str));
	}
    break;

  case 506:

/* Line 1455 of yacc.c  */
#line 2917 "sql.yacc"
    {
			(yyval.s_select_list_item)=new_select_list_item_extend(new_select_list_item_builtin_const(E_SLI_BUILTIN_CONST_CURRENT),(yyvsp[(2) - (4)].str),(yyvsp[(4) - (4)].str));
	}
    break;

  case 507:

/* Line 1455 of yacc.c  */
#line 2920 "sql.yacc"
    {
			(yyval.s_select_list_item)=new_select_list_item_extend((yyvsp[(1) - (5)].s_select_list_item),(yyvsp[(3) - (5)].str),(yyvsp[(5) - (5)].str));
	}
    break;

  case 508:

/* Line 1455 of yacc.c  */
#line 2926 "sql.yacc"
    {(yyval.integer_val)=E_SLI_UNITS_YEAR;}
    break;

  case 509:

/* Line 1455 of yacc.c  */
#line 2927 "sql.yacc"
    {(yyval.integer_val)=E_SLI_UNITS_MONTH;}
    break;

  case 510:

/* Line 1455 of yacc.c  */
#line 2928 "sql.yacc"
    {(yyval.integer_val)=E_SLI_UNITS_DAY;}
    break;

  case 511:

/* Line 1455 of yacc.c  */
#line 2929 "sql.yacc"
    {(yyval.integer_val)=E_SLI_UNITS_HOUR;}
    break;

  case 512:

/* Line 1455 of yacc.c  */
#line 2930 "sql.yacc"
    {(yyval.integer_val)=E_SLI_UNITS_MINUTE;}
    break;

  case 513:

/* Line 1455 of yacc.c  */
#line 2931 "sql.yacc"
    {(yyval.integer_val)=E_SLI_UNITS_SECOND;}
    break;

  case 514:

/* Line 1455 of yacc.c  */
#line 2936 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_op_slil((yyvsp[(1) - (5)].s_select_list_item),(yyvsp[(4) - (5)].s_select_list_item_list),E_SLI_IN_VALUES);
                add_feature("WHERE_IN");
        }
    break;

  case 515:

/* Line 1455 of yacc.c  */
#line 2940 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_op_sli((yyvsp[(1) - (3)].s_select_list_item),(yyvsp[(3) - (3)].s_select_list_item),E_SLI_IN_SELECT);
                add_feature("WHERE_IN_SELECT");
        }
    break;

  case 516:

/* Line 1455 of yacc.c  */
#line 2944 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_op_slil((yyvsp[(1) - (5)].s_select_list_item),(yyvsp[(4) - (5)].s_select_list_item_list),E_SLI_NOT_IN_VALUES);
                add_feature("WHERE_IN");
        }
    break;

  case 517:

/* Line 1455 of yacc.c  */
#line 2948 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_op_sli((yyvsp[(1) - (3)].s_select_list_item),(yyvsp[(3) - (3)].s_select_list_item),E_SLI_NOT_IN_SELECT);
                add_feature("WHERE_IN_SELECT");
        }
    break;

  case 518:

/* Line 1455 of yacc.c  */
#line 2955 "sql.yacc"
    {
		(yyval.s_select_list_item_list)=local_new_select_list_item_list((yyvsp[(1) - (1)].s_select_list_item));
	}
    break;

  case 519:

/* Line 1455 of yacc.c  */
#line 2958 "sql.yacc"
    {
                (yyval.s_select_list_item_list)=local_add_select_list_item_list((yyvsp[(1) - (3)].s_select_list_item_list),(yyvsp[(3) - (3)].s_select_list_item));
	}
    break;

  case 520:

/* Line 1455 of yacc.c  */
#line 2963 "sql.yacc"
    { (yyval.s_select_list_item)=(yyvsp[(1) - (1)].s_select_list_item);}
    break;

  case 521:

/* Line 1455 of yacc.c  */
#line 2964 "sql.yacc"
    { (yyval.s_select_list_item)=new_select_list_item_literal((yyvsp[(1) - (1)].str)); }
    break;

  case 522:

/* Line 1455 of yacc.c  */
#line 2965 "sql.yacc"
    { 
		char buff[256]; SPRINTF1(buff," -%s",(yyvsp[(2) - (2)].str)); (yyval.s_select_list_item)=new_select_list_item_literal(buff); }
    break;

  case 523:

/* Line 1455 of yacc.c  */
#line 2967 "sql.yacc"
    { char buff[256]; SPRINTF1(buff," -%s",(yyvsp[(2) - (2)].str)); (yyval.s_select_list_item)=new_select_list_item_literal(buff); }
    break;

  case 524:

/* Line 1455 of yacc.c  */
#line 2973 "sql.yacc"
    {
                if (strstr((yyvsp[(1) - (1)].str),"systables")!=0) { add_feature("IFX_SYSTABLES"); }
                if (strstr((yyvsp[(1) - (1)].str),"syscolumns")!=0) { add_feature("IFX_SYSCOLUMNS"); }
                if (strstr((yyvsp[(1) - (1)].str),"sysindexes")!=0) { add_feature("IFX_SYSINDEXES"); }
                strcpy((yyval.str),A4GLSQLCV_check_tablename((yyvsp[(1) - (1)].str)));
                }
    break;

  case 525:

/* Line 1455 of yacc.c  */
#line 2983 "sql.yacc"
    {
	     SPRINTF1((yyval.str),"%s", A4GLSQLCV_ownerize_tablename(NULL, A4GL_strip_quotes((yyvsp[(1) - (1)].str))));
             ADDMAP("Use Table",(yyval.str));
        }
    break;

  case 526:

/* Line 1455 of yacc.c  */
#line 2987 "sql.yacc"
    {
	     SPRINTF1((yyval.str),"%s", A4GLSQLCV_ownerize_tablename((yyvsp[(1) - (3)].str), (yyvsp[(3) - (3)].str)));
	     ADDMAP("Use Table",(yyval.str));
        }
    break;

  case 527:

/* Line 1455 of yacc.c  */
#line 2991 "sql.yacc"
    {
	     SPRINTF1((yyval.str),"%s", A4GLSQLCV_ownerize_tablename(NULL, (yyvsp[(1) - (1)].str)));
	     ADDMAP("Use Table",(yyval.str));
	}
    break;

  case 528:

/* Line 1455 of yacc.c  */
#line 2995 "sql.yacc"
    {
	     SPRINTF1((yyval.str),"%s", A4GLSQLCV_db_tablename((yyvsp[(1) - (3)].str), NULL, A4GLSQLCV_ownerize_tablename(NULL, (yyvsp[(3) - (3)].str))));
	     ADDMAP("Use Table",(yyval.str));
	}
    break;

  case 529:

/* Line 1455 of yacc.c  */
#line 2999 "sql.yacc"
    {
	     SPRINTF1((yyval.str),"%s", A4GLSQLCV_db_tablename((yyvsp[(1) - (5)].str), NULL, A4GLSQLCV_ownerize_tablename((yyvsp[(3) - (5)].str),(yyvsp[(5) - (5)].str))));
	     ADDMAP("Use Table",(yyval.str));
        }
    break;

  case 530:

/* Line 1455 of yacc.c  */
#line 3003 "sql.yacc"
    {
	     SPRINTF1((yyval.str),"%s", A4GLSQLCV_db_tablename(NULL,(yyvsp[(1) - (3)].str), A4GLSQLCV_ownerize_tablename(NULL, (yyvsp[(3) - (3)].str))));
	     ADDMAP("Use Table",(yyval.str));
	}
    break;

  case 531:

/* Line 1455 of yacc.c  */
#line 3007 "sql.yacc"
    {
	     SPRINTF1((yyval.str),"%s", A4GLSQLCV_db_tablename((yyvsp[(1) - (5)].str), (yyvsp[(3) - (5)].str), A4GLSQLCV_ownerize_tablename(NULL, (yyvsp[(5) - (5)].str))));
	     ADDMAP("Use Table",(yyval.str));
	}
    break;

  case 532:

/* Line 1455 of yacc.c  */
#line 3011 "sql.yacc"
    {
	     SPRINTF1((yyval.str),"%s", A4GLSQLCV_db_tablename((yyvsp[(1) - (7)].str), (yyvsp[(3) - (7)].str), A4GLSQLCV_ownerize_tablename((yyvsp[(5) - (7)].str), (yyvsp[(7) - (7)].str))));
	     ADDMAP("Use Table",(yyval.str));
        }
    break;

  case 533:

/* Line 1455 of yacc.c  */
#line 3019 "sql.yacc"
    {
                if (strstr((yyvsp[(1) - (1)].str),"systables")!=0) { add_feature("IFX_SYSTABLES"); }
                if (strstr((yyvsp[(1) - (1)].str),"syscolumns")!=0) { add_feature("IFX_SYSCOLUMNS"); }
                if (strstr((yyvsp[(1) - (1)].str),"sysindexes")!=0) { add_feature("IFX_SYSINDEXES"); }
                strcpy((yyval.str),A4GLSQLCV_check_tablename((yyvsp[(1) - (1)].str)));
                }
    break;

  case 534:

/* Line 1455 of yacc.c  */
#line 3029 "sql.yacc"
    {

	     SPRINTF1((yyval.str),"%s", A4GLSQLCV_ownerize_tablename((yyvsp[(1) - (3)].str), (yyvsp[(3) - (3)].str)));
	     ADDMAP("Use Table",(yyval.str));
        }
    break;

  case 535:

/* Line 1455 of yacc.c  */
#line 3034 "sql.yacc"
    {
	     SPRINTF1((yyval.str),"%s", A4GLSQLCV_ownerize_tablename((yyvsp[(1) - (3)].str), (yyvsp[(3) - (3)].str)));
	     ADDMAP("Use Table",(yyval.str));
        }
    break;

  case 536:

/* Line 1455 of yacc.c  */
#line 3038 "sql.yacc"
    {
	     SPRINTF1((yyval.str),"%s", A4GLSQLCV_ownerize_tablename(NULL, A4GL_strip_quotes((yyvsp[(1) - (1)].str))));
	     ADDMAP("Use Table",(yyval.str));
        }
    break;

  case 537:

/* Line 1455 of yacc.c  */
#line 3042 "sql.yacc"
    {
             SPRINTF1((yyval.str),"%s", A4GLSQLCV_ownerize_tablename(NULL, (yyvsp[(1) - (1)].str)));
	     ADDMAP("Use Table",(yyval.str));
	}
    break;

  case 538:

/* Line 1455 of yacc.c  */
#line 3046 "sql.yacc"
    {
             SPRINTF1((yyval.str),"%s", A4GLSQLCV_db_tablename((yyvsp[(1) - (3)].str),NULL, A4GLSQLCV_ownerize_tablename(NULL, (yyvsp[(3) - (3)].str))));
	     ADDMAP("Use Table",(yyval.str));
	}
    break;

  case 539:

/* Line 1455 of yacc.c  */
#line 3050 "sql.yacc"
    {
	     SPRINTF1((yyval.str),"%s", A4GLSQLCV_db_tablename((yyvsp[(1) - (5)].str), NULL,A4GLSQLCV_ownerize_tablename((yyvsp[(3) - (5)].str), (yyvsp[(5) - (5)].str))));
	     ADDMAP("Use Table",(yyval.str));
        }
    break;

  case 540:

/* Line 1455 of yacc.c  */
#line 3055 "sql.yacc"
    {
             SPRINTF1((yyval.str),"%s", A4GLSQLCV_db_tablename(NULL, (yyvsp[(1) - (3)].str), A4GLSQLCV_ownerize_tablename(NULL, (yyvsp[(3) - (3)].str))));
	     ADDMAP("Use Table",(yyval.str));
	}
    break;

  case 541:

/* Line 1455 of yacc.c  */
#line 3059 "sql.yacc"
    {
            SPRINTF1((yyval.str),"%s", A4GLSQLCV_db_tablename( (yyvsp[(1) - (5)].str), (yyvsp[(3) - (5)].str), A4GLSQLCV_ownerize_tablename(NULL, (yyvsp[(5) - (5)].str))));
	    ADDMAP("Use Table",(yyval.str));
	}
    break;

  case 542:

/* Line 1455 of yacc.c  */
#line 3063 "sql.yacc"
    {
	     SPRINTF1((yyval.str),"%s", A4GLSQLCV_db_tablename((yyvsp[(1) - (7)].str), (yyvsp[(3) - (7)].str), A4GLSQLCV_ownerize_tablename((yyvsp[(5) - (7)].str), (yyvsp[(7) - (7)].str))));
	     ADDMAP("Use Table",(yyval.str));
        }
    break;

  case 543:

/* Line 1455 of yacc.c  */
#line 3071 "sql.yacc"
    {
	     SPRINTF1((yyval.str),"%s", A4GLSQLCV_ownerize_tablename((yyvsp[(1) - (3)].str), (yyvsp[(3) - (3)].str)));
        }
    break;

  case 544:

/* Line 1455 of yacc.c  */
#line 3074 "sql.yacc"
    {
	        SPRINTF1((yyval.str),"%s", A4GLSQLCV_ownerize_tablename(NULL, (yyvsp[(1) - (1)].str)));
                ADDMAP("Use Index",(yyval.str));
        }
    break;

  case 545:

/* Line 1455 of yacc.c  */
#line 3079 "sql.yacc"
    {strcpy((yyval.str),(yyvsp[(1) - (1)].str)); ADDMAP("Use Index",(yyvsp[(1) - (1)].str)); }
    break;

  case 546:

/* Line 1455 of yacc.c  */
#line 3080 "sql.yacc"
    { SPRINTF3((yyval.str),"%s%s%s",(yyvsp[(1) - (3)].str),(yyvsp[(2) - (3)].str),(yyvsp[(3) - (3)].str)); ADDMAP("Use Index",(yyval.str)); }
    break;

  case 547:

/* Line 1455 of yacc.c  */
#line 3081 "sql.yacc"
    {
	     SPRINTF2((yyval.str),"%s:%s", (yyvsp[(1) - (5)].str), A4GLSQLCV_ownerize_tablename((yyvsp[(3) - (5)].str), (yyvsp[(5) - (5)].str)));
             ADDMAP("Use Index",(yyval.str));
        }
    break;

  case 548:

/* Line 1455 of yacc.c  */
#line 3086 "sql.yacc"
    {strcpy((yyval.str),(yyvsp[(1) - (3)].str)); ADDMAP("Use Index",(yyvsp[(1) - (3)].str)); }
    break;

  case 549:

/* Line 1455 of yacc.c  */
#line 3087 "sql.yacc"
    { SPRINTF4((yyval.str),"%s@%s%s%s",(yyvsp[(1) - (5)].str),(yyvsp[(3) - (5)].str),(yyvsp[(4) - (5)].str),(yyvsp[(5) - (5)].str)); ADDMAP("Use Index",(yyval.str)); }
    break;

  case 550:

/* Line 1455 of yacc.c  */
#line 3088 "sql.yacc"
    {
	     SPRINTF3((yyval.str),"%s@%s:%s", (yyvsp[(1) - (7)].str), (yyvsp[(3) - (7)].str), A4GLSQLCV_ownerize_tablename((yyvsp[(5) - (7)].str), (yyvsp[(7) - (7)].str)));
             ADDMAP("Use Index",(yyval.str));
        }
    break;

  case 552:

/* Line 1455 of yacc.c  */
#line 3099 "sql.yacc"
    {
                      (yyval.ptr)=A4GL_new_expr_simple_string(A4GL_get_clobbered_from((yyval.str)), ET_EXPR_IDENTIFIER);
	}
    break;

  case 554:

/* Line 1455 of yacc.c  */
#line 3105 "sql.yacc"
    { sprintf((yyval.str),".%s",(yyvsp[(2) - (2)].str)); }
    break;

  case 556:

/* Line 1455 of yacc.c  */
#line 3110 "sql.yacc"
    {strcpy((yyval.str), A4GL_strip_quotes ((yyvsp[(1) - (1)].str)));}
    break;

  case 561:

/* Line 1455 of yacc.c  */
#line 3161 "sql.yacc"
    {
			int converted;
			(yyval.sql_string)=get_insert_cmd((yyvsp[(1) - (1)].insert_cmd),&converted);
			A4GL_free_associated_mem((yyvsp[(1) - (1)].insert_cmd));
			acl_free((yyvsp[(1) - (1)].insert_cmd));

		}
    break;

  case 562:

/* Line 1455 of yacc.c  */
#line 3168 "sql.yacc"
    {
			int converted;
			(yyval.sql_string)=get_update_cmd((yyvsp[(1) - (1)].update_cmd),&converted);
			A4GL_free_associated_mem((yyvsp[(1) - (1)].update_cmd));
			acl_free((yyvsp[(1) - (1)].update_cmd));
		}
    break;

  case 563:

/* Line 1455 of yacc.c  */
#line 3174 "sql.yacc"
    {
			int converted;
			(yyval.sql_string)=get_delete_cmd((yyvsp[(1) - (1)].delete_cmd),&converted);
			A4GL_free_associated_mem((yyvsp[(1) - (1)].delete_cmd));
			acl_free((yyvsp[(1) - (1)].delete_cmd));
		}
    break;

  case 566:

/* Line 1455 of yacc.c  */
#line 3189 "sql.yacc"
    { print_exec_select((yyvsp[(1) - (1)].sql_string));  }
    break;

  case 567:

/* Line 1455 of yacc.c  */
#line 3190 "sql.yacc"
    { print_exec_select((yyvsp[(1) - (1)].sql_string));  }
    break;

  case 569:

/* Line 1455 of yacc.c  */
#line 3192 "sql.yacc"
    { print_exec_select((yyvsp[(1) - (1)].sql_string));  }
    break;

  case 570:

/* Line 1455 of yacc.c  */
#line 3194 "sql.yacc"
    {
			print_sql_commit ((yyvsp[(1) - (1)].integer_val));
	}
    break;

  case 571:

/* Line 1455 of yacc.c  */
#line 3197 "sql.yacc"
    {print_unable_to_parse();}
    break;

  case 572:

/* Line 1455 of yacc.c  */
#line 3201 "sql.yacc"
    { (yyval.sql_string)=make_sql_string_and_free((yyvsp[(1) - (2)].sql_string),acl_strdup((yyvsp[(2) - (2)].str)),0);
}
    break;

  case 574:

/* Line 1455 of yacc.c  */
#line 3210 "sql.yacc"
    {
			(yyval.sql_string)=make_select_stmt_v2("", (yyvsp[(1) - (1)].s_select),"");
			A4GL_free_select_stmt((yyvsp[(1) - (1)].s_select));
		}
    break;

  case 575:

/* Line 1455 of yacc.c  */
#line 3216 "sql.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 576:

/* Line 1455 of yacc.c  */
#line 3217 "sql.yacc"
    {
			strcpy((yyval.str),A4GLSQLCV_get_forupdate(NULL));
		}
    break;

  case 577:

/* Line 1455 of yacc.c  */
#line 3220 "sql.yacc"
    {
			strcpy((yyval.str),A4GLSQLCV_get_forupdate((yyvsp[(2) - (2)].str)));
		}
    break;

  case 578:

/* Line 1455 of yacc.c  */
#line 3225 "sql.yacc"
    { strcpy((yyval.str),(yyvsp[(1) - (1)].str)); }
    break;

  case 579:

/* Line 1455 of yacc.c  */
#line 3226 "sql.yacc"
    { sprintf((yyval.str),"%s,%s",(yyvsp[(1) - (3)].str),(yyvsp[(3) - (3)].str)); }
    break;

  case 581:

/* Line 1455 of yacc.c  */
#line 3230 "sql.yacc"
    {sprintf((yyval.str),"%s.%s",A4GLSQLCV_ownerize_tablename(NULL, (yyvsp[(1) - (3)].str)),(yyvsp[(3) - (3)].str));}
    break;

  case 582:

/* Line 1455 of yacc.c  */
#line 3231 "sql.yacc"
    {
        sprintf((yyval.str),"%s.%s", A4GLSQLCV_ownerize_tablename((yyvsp[(1) - (5)].str), (yyvsp[(3) - (5)].str)), (yyvsp[(5) - (5)].str));
}
    break;

  case 583:

/* Line 1455 of yacc.c  */
#line 3241 "sql.yacc"
    { print_exec_sql(acl_strdup((yyvsp[(1) - (1)].str))); }
    break;

  case 584:

/* Line 1455 of yacc.c  */
#line 3242 "sql.yacc"
    { print_exec_sql(acl_strdup((yyvsp[(1) - (1)].str))); }
    break;

  case 585:

/* Line 1455 of yacc.c  */
#line 3243 "sql.yacc"
    { sprintf((yyval.str),"%s %s",(yyvsp[(1) - (2)].str),(yyvsp[(2) - (2)].str)); print_exec_sql(acl_strdup((yyval.str))); }
    break;

  case 586:

/* Line 1455 of yacc.c  */
#line 3244 "sql.yacc"
    { print_exec_sql(acl_strdup((yyvsp[(1) - (1)].str))); }
    break;

  case 587:

/* Line 1455 of yacc.c  */
#line 3245 "sql.yacc"
    { print_exec_sql(acl_strdup((yyvsp[(1) - (1)].str))); }
    break;

  case 588:

/* Line 1455 of yacc.c  */
#line 3246 "sql.yacc"
    { print_exec_sql(acl_strdup((yyvsp[(1) - (1)].str))); }
    break;

  case 589:

/* Line 1455 of yacc.c  */
#line 3247 "sql.yacc"
    { print_exec_sql(acl_strdup((yyvsp[(1) - (1)].str))); }
    break;

  case 590:

/* Line 1455 of yacc.c  */
#line 3248 "sql.yacc"
    { print_exec_sql(acl_strdup((yyvsp[(1) - (1)].str))); }
    break;

  case 591:

/* Line 1455 of yacc.c  */
#line 3252 "sql.yacc"
    { 
	char *s;
	s=acl_strdup((yyvsp[(1) - (1)].str));
	(yyval.s_select_list_item)=new_select_list_item_column_from_transform(s);
	acl_free(s);
	}
    break;

  case 592:

/* Line 1455 of yacc.c  */
#line 3258 "sql.yacc"
    {  
		(yyval.s_select_list_item)=new_select_list_item_builtin_const(E_SLI_QUERY_PLACEHOLDER);}
    break;

  case 593:

/* Line 1455 of yacc.c  */
#line 3260 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_replace_var((yyvsp[(1) - (1)].sql_string));
	}
    break;

  case 594:

/* Line 1455 of yacc.c  */
#line 3279 "sql.yacc"
    {
        add_feature("DATABASE_USED");
       conn_db((yyvsp[(2) - (3)].str));
}
    break;

  case 595:

/* Line 1455 of yacc.c  */
#line 3287 "sql.yacc"
    {
		(yyval.sql_string)=acl_strdup((yyvsp[(2) - (3)].str));
}
    break;

  case 596:

/* Line 1455 of yacc.c  */
#line 3294 "sql.yacc"
    {sprintf((yyval.str),"(%s)",(yyvsp[(2) - (3)].str));}
    break;

  case 597:

/* Line 1455 of yacc.c  */
#line 3295 "sql.yacc"
    { sprintf((yyval.str),"%s%s%s",(yyvsp[(1) - (3)].str),(yyvsp[(2) - (3)].str),(yyvsp[(3) - (3)].str));}
    break;

  case 598:

/* Line 1455 of yacc.c  */
#line 3296 "sql.yacc"
    {sprintf((yyval.str),"%d",atoi((yyvsp[(1) - (1)].str)));}
    break;

  case 599:

/* Line 1455 of yacc.c  */
#line 3297 "sql.yacc"
    {sprintf((yyval.str),"(%s%s)",(yyvsp[(1) - (2)].str),(yyvsp[(2) - (2)].str));}
    break;

  case 600:

/* Line 1455 of yacc.c  */
#line 3302 "sql.yacc"
    {strcpy((yyval.str),"+");}
    break;

  case 601:

/* Line 1455 of yacc.c  */
#line 3303 "sql.yacc"
    {strcpy((yyval.str),"-");}
    break;

  case 602:

/* Line 1455 of yacc.c  */
#line 3304 "sql.yacc"
    {strcpy((yyval.str),"*");}
    break;

  case 603:

/* Line 1455 of yacc.c  */
#line 3305 "sql.yacc"
    {strcpy((yyval.str),"/");}
    break;

  case 604:

/* Line 1455 of yacc.c  */
#line 3306 "sql.yacc"
    {strcpy((yyval.str),"%");}
    break;

  case 605:

/* Line 1455 of yacc.c  */
#line 3311 "sql.yacc"
    {strcpy((yyval.str),"+");}
    break;

  case 606:

/* Line 1455 of yacc.c  */
#line 3312 "sql.yacc"
    {strcpy((yyval.str),"-");}
    break;

  case 607:

/* Line 1455 of yacc.c  */
#line 3328 "sql.yacc"
    {sprintf((yyval.str),"%s", A4GLSQLCV_check_tablename((yyvsp[(1) - (1)].str)));}
    break;

  case 608:

/* Line 1455 of yacc.c  */
#line 3329 "sql.yacc"
    {sprintf((yyval.str),"%s.*", A4GLSQLCV_ownerize_tablename(NULL,(yyvsp[(1) - (3)].str)));}
    break;

  case 609:

/* Line 1455 of yacc.c  */
#line 3330 "sql.yacc"
    {sprintf((yyval.str),"%s.%s", (yyvsp[(1) - (3)].str),A4GLSQLCV_get_sqlconst ("rowid"));}
    break;

  case 610:

/* Line 1455 of yacc.c  */
#line 3331 "sql.yacc"
    {sprintf((yyval.str),"%s.%s", A4GLSQLCV_ownerize_tablename(NULL,(yyvsp[(1) - (3)].str)),(yyvsp[(3) - (3)].str));}
    break;

  case 611:

/* Line 1455 of yacc.c  */
#line 3332 "sql.yacc"
    {sprintf((yyval.str),"%s.%s", A4GLSQLCV_ownerize_tablename((yyvsp[(1) - (5)].str),(yyvsp[(3) - (5)].str)),(yyvsp[(5) - (5)].str));}
    break;

  case 612:

/* Line 1455 of yacc.c  */
#line 3333 "sql.yacc"
    {sprintf((yyval.str),"%s.%s", A4GLSQLCV_ownerize_tablename((yyvsp[(1) - (5)].str),(yyvsp[(3) - (5)].str)),(yyvsp[(5) - (5)].str));}
    break;

  case 613:

/* Line 1455 of yacc.c  */
#line 3334 "sql.yacc"
    {sprintf((yyval.str),"%s", (yyvsp[(1) - (4)].str)); strcpy((yyval.str), A4GLSQLCV_make_substr_s((yyvsp[(1) - (4)].str), 1,(yyvsp[(3) - (4)].str),0));}
    break;

  case 614:

/* Line 1455 of yacc.c  */
#line 3335 "sql.yacc"
    {char buff[256]; sprintf(buff,"%s.%s", A4GLSQLCV_ownerize_tablename(NULL,(yyvsp[(1) - (6)].str)),(yyvsp[(3) - (6)].str)); strcpy((yyval.str), A4GLSQLCV_make_substr_s(buff,1,(yyvsp[(5) - (6)].str),0));}
    break;

  case 615:

/* Line 1455 of yacc.c  */
#line 3336 "sql.yacc"
    {char buff[256]; sprintf(buff,"%s.%s", A4GLSQLCV_ownerize_tablename((yyvsp[(1) - (8)].str),(yyvsp[(3) - (8)].str)), (yyvsp[(5) - (8)].str)); strcpy((yyval.str), A4GLSQLCV_make_substr_s(buff,1,(yyvsp[(7) - (8)].str),0));  }
    break;

  case 616:

/* Line 1455 of yacc.c  */
#line 3337 "sql.yacc"
    {char buff[256]; sprintf(buff,"%s.%s", A4GLSQLCV_ownerize_tablename((yyvsp[(1) - (8)].str),(yyvsp[(3) - (8)].str)), (yyvsp[(5) - (8)].str));  strcpy((yyval.str), A4GLSQLCV_make_substr_s(buff,1,(yyvsp[(7) - (8)].str),0)); }
    break;

  case 617:

/* Line 1455 of yacc.c  */
#line 3339 "sql.yacc"
    {sprintf((yyval.str),"%s", (yyvsp[(1) - (6)].str)); strcpy((yyval.str), A4GLSQLCV_make_substr_s((yyvsp[(1) - (6)].str), 2,(yyvsp[(3) - (6)].str),(yyvsp[(5) - (6)].str)));}
    break;

  case 618:

/* Line 1455 of yacc.c  */
#line 3340 "sql.yacc"
    {char buff[256]; sprintf(buff,"%s.%s", A4GLSQLCV_ownerize_tablename(NULL,(yyvsp[(1) - (8)].str)),(yyvsp[(3) - (8)].str)); strcpy((yyval.str), A4GLSQLCV_make_substr_s(buff,2,(yyvsp[(5) - (8)].str),(yyvsp[(7) - (8)].str)));}
    break;

  case 619:

/* Line 1455 of yacc.c  */
#line 3341 "sql.yacc"
    {char buff[256]; sprintf(buff,"%s.%s", A4GLSQLCV_ownerize_tablename((yyvsp[(1) - (10)].str),(yyvsp[(3) - (10)].str)), (yyvsp[(5) - (10)].str)); strcpy((yyval.str), A4GLSQLCV_make_substr_s(buff,2,(yyvsp[(7) - (10)].str),(yyvsp[(9) - (10)].str)));  }
    break;

  case 620:

/* Line 1455 of yacc.c  */
#line 3342 "sql.yacc"
    {char buff[256]; sprintf(buff,"%s.%s", A4GLSQLCV_ownerize_tablename((yyvsp[(1) - (10)].str),(yyvsp[(3) - (10)].str)), (yyvsp[(5) - (10)].str));  strcpy((yyval.str), A4GLSQLCV_make_substr_s(buff,2,(yyvsp[(7) - (10)].str),(yyvsp[(9) - (10)].str))); }
    break;

  case 621:

/* Line 1455 of yacc.c  */
#line 3347 "sql.yacc"
    {
                (yyval.s_select_list_item)=(yyvsp[(1) - (1)].s_select_list_item);
        }
    break;

  case 622:

/* Line 1455 of yacc.c  */
#line 3350 "sql.yacc"
    {
                (yyval.s_select_list_item)=new_select_list_item_cast((yyvsp[(1) - (3)].s_select_list_item), (yyvsp[(3) - (3)].str));
        }
    break;

  case 623:

/* Line 1455 of yacc.c  */
#line 3359 "sql.yacc"
    { (yyvsp[(1) - (1)].s_select_list_item)=(yyvsp[(1) - (1)].s_select_list_item); }
    break;

  case 624:

/* Line 1455 of yacc.c  */
#line 3360 "sql.yacc"
    {(yyvsp[(1) - (1)].s_select_list_item)=(yyvsp[(1) - (1)].s_select_list_item);}
    break;

  case 625:

/* Line 1455 of yacc.c  */
#line 3361 "sql.yacc"
    {  (yyval.s_select_list_item)=new_select_list_item_sq(E_SQE_DONT_CARE,(yyvsp[(1) - (1)].s_select_list_item)); }
    break;

  case 626:

/* Line 1455 of yacc.c  */
#line 3362 "sql.yacc"
    { (yyval.s_select_list_item)=new_select_list_item_sq(E_SQE_ALL,(yyvsp[(2) - (2)].s_select_list_item)); }
    break;

  case 627:

/* Line 1455 of yacc.c  */
#line 3363 "sql.yacc"
    { (yyval.s_select_list_item)=new_select_list_item_sq(E_SQE_ANY,(yyvsp[(2) - (2)].s_select_list_item)); }
    break;

  case 628:

/* Line 1455 of yacc.c  */
#line 3364 "sql.yacc"
    { (yyval.s_select_list_item)=new_select_list_item_sq(E_SQE_SOME,(yyvsp[(2) - (2)].s_select_list_item)); }
    break;

  case 629:

/* Line 1455 of yacc.c  */
#line 3368 "sql.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 630:

/* Line 1455 of yacc.c  */
#line 3369 "sql.yacc"
    {strcpy((yyval.str),(yyvsp[(1) - (1)].str));}
    break;



/* Line 1455 of yacc.c  */
#line 8847 "y.tab.c"
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
#line 3374 "sql.yacc"


#if LEX_YY_PREGEN
#include "../../tools/no_yacc/cygwin/compilers/sql/lex.sqlparse_yy.c"
#else
#include "lex.yy.c"
#endif
#include "util.c"
#include "cmds.c"

