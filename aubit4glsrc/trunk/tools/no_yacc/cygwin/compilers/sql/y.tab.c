
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
     INT_VALUE = 2210,
     NAMED = 2211,
     NAMED_GEN = 2212,
     CHAR_VALUE = 2213,
     NOT_USED_1 = 2214,
     NOT_USED_2 = 2215,
     NOT_USED_3 = 2216,
     NOT_USED_4 = 2217,
     NOT_USED_5 = 2218,
     NOT_USED_6 = 2219,
     NOT_USED_7 = 2220,
     NOT_USED_8 = 2221,
     NUMBER_VALUE = 2222,
     SEMICOLON = 2223,
     QUESTION_MARK = 2224,
     CLINE = 2225,
     CH = 2226,
     MARK_VAR = 2227,
     END_MARK_VAR = 2228,
     LEFT_JOIN = 1002,
     DISPLAY_NULL_TO = 1005,
     ON_CHANGE = 1006,
     INNER_JOIN = 1007,
     UI_INTERFACE_DOT_FRONTCALL = 1010,
     UICOMBOBOX = 1014,
     UIFORM = 1015,
     USING_BTREE = 1033,
     USING_RTREE = 1034,
     SET_BUFFERED_LOG = 1059,
     SET_LOG = 1062,
     MDY = 1064,
     WEEKDAY = 1065,
     MODE_ANSI = 1068,
     START_DATABASE = 1069,
     WITH_LOG_IN = 1070,
     SET_CONSTRAINTS_ALL_IMMEDIATE = 1071,
     DATETIME_VALUE = 1084,
     INTERVAL_VALUE = 1085,
     RECOVER_TABLE = 1086,
     ROLLFORWARD_DATABASE = 1087,
     DROP_TRIGGER = 1103,
     DROP_AUDIT_FOR = 1104,
     CREATE_AUDIT_FOR = 1105,
     EXECUTE_PROCEDURE = 1109,
     ALTER_TABLE = 1116,
     ALTER_INDEX = 1117,
     NEXT_SIZE = 1118,
     XSET_MULTIPLY_EQUAL_OPEN_BRACKET = 1155,
     XSET_ident_DOT_MULTIPLY_EQUAL_OPEN_BRACKET = 1156,
     XSET_ident_DOT_MULTIPLY_EQUAL = 1157,
     XSET_MULTIPLY_EQUAL = 1158,
     XSET_OPEN_BRACKET = 1159,
     CREATE_DATABASE = 1162,
     DROP_DATABASE = 1163,
     ADD_CONSTRAINT = 1165,
     DROP_CONSTRAINT = 1166,
     DROP_SYNONYM = 1167,
     CONSTRAINT = 1168,
     NOT_FIELD_TOUCHED_CURRENT = 1171,
     FIELD_TOUCHED_CURRENT = 1172,
     DOUBLE_PRECISION = 1179,
     COUNT_MULTIPLY = 1180,
     MODIFY_NEXT_SIZE = 1200,
     LOCK_MODE_PAGE = 1201,
     LOCK_MODE_ROW = 1202,
     UNITS_YEAR = 1209,
     UNITS_MONTH = 1210,
     UNITS_DAY = 1211,
     UNITS_HOUR = 1212,
     UNITS_MINUTE = 1213,
     UNITS_SECOND = 1214,
     TO_CLUSTER = 1219,
     TO_NOT_CLUSTER = 1220,
     CREATE_UC_IDX = 1222,
     CREATE_U_IDX = 1223,
     CREATE_C_IDX = 1224,
     CREATE_IDX = 1225,
     DOUBLE_COLON = 1235,
     SQLSICS = 1241,
     CREATE_SCHEMA = 1242,
     SQLSIRR = 1243,
     UPDATESTATS_T = 1244,
     SQLSICR = 1245,
     SQLSIDR = 1256,
     CREATE_TEMP_TABLE = 1257,
     WITH_CHECK_OPTION = 1265,
     WITH_GRANT_OPTION = 1266,
     SQLSLMNW = 1267,
     WHERE_CURRENT_OF = 1273,
     NOT_NULL_UNIQUE = 1281,
     SQLSLMW = 1288,
     ALL_PRIVILEGES = 1290,
     CREATE_SYNONYM = 1294,
     DROP_TABLE = 1295,
     INEXCLUSIVE = 1297,
     UPDATESTATS = 1302,
     CREATE_TABLE = 1328,
     DEFAULT_NULL = 1329,
     DEFAULT_TODAY = 1330,
     DEFAULT_USER = 1331,
     UNLOCK_TABLE = 1344,
     ROLLBACK_W = 1352,
     SQLSEON = 1354,
     SQLSEOFF = 1355,
     CREATE_VIEW = 1359,
     DELETE_FROM = 1360,
     EXTENT_SIZE = 1367,
     FOREIGN_KEY = 1368,
     INSERT_INTO = 1371,
     IS_NOT_NULL = 1373,
     NOT_MATCHES = 1376,
     PRIMARY_KEY = 1382,
     USE_SESSION = 1389,
     WITH_NO_LOG = 1390,
     INSHARE = 1393,
     BEGIN_WORK = 1399,
     DROP_INDEX = 1404,
     FOR_UPDATE_OF = 1410,
     FOR_UPDATE = 1411,
     LOCK_TABLE = 1416,
     NOT_EXISTS = 1418,
     REFERENCES = 1420,
     RENCOL = 1421,
     SMALLFLOAT = 1423,
     COMMIT_W = 1434,
     RENTAB = 1441,
     KW_CHAR = 1444,
     NCHAR = 1445,
     NVARCHAR = 1446,
     DELIMITER = 1448,
     DROP_VIEW = 1450,
     EXCLUSIVE = 1453,
     GREATER_THAN_EQ = 1457,
     INTO_TEMP = 1459,
     DATABASE = 1483,
     DATETIME = 1484,
     DISTINCT = 1486,
     FRACTION = 1493,
     GROUP_BY = 1495,
     INTERVAL = 1496,
     NOT_LIKE = 1498,
     NOT_ILIKE = 1499,
     NOT_NULL = 1500,
     RESOURCE = 1506,
     SMALLINT = 1507,
     IS_NULL = 1513,
     LESS_THAN_EQ = 1514,
     BETWEEN = 1516,
     CLOSE_BRACKET = 1519,
     CONNECT = 1522,
     KW_CURRENT = 1523,
     KW_DECIMAL = 1525,
     DEFAULT = 1527,
     INTEGER = 1535,
     SERIAL8 = 1537,
     MATCHES = 1540,
     VARCHAR = 1553,
     CLOSE_SQUARE = 1556,
     GREATER_THAN = 1557,
     KW_FALSE = 1558,
     NOT_IN = 1559,
     OPEN_BRACKET = 1561,
     KW_DELETE = 1569,
     KW_ESCAPE = 1572,
     EXISTS = 1573,
     EXTEND = 1574,
     HAVING = 1578,
     KW_INSERT = 1580,
     MINUTE = 1584,
     MODIFY = 1585,
     EQUAL = 1587,
     NOT_EQUAL = 1588,
     OPEN_SQUARE = 1590,
     PUBLIC = 1594,
     REVOKE = 1598,
     SECOND = 1602,
     KW_SELECT = 1606,
     SERIAL = 1607,
     UNIQUE = 1610,
     KW_UPDATE = 1612,
     VALUES = 1613,
     KW_NULL = 1616,
     KW_TRUE = 1617,
     ALTER = 1619,
     CHECK = 1625,
     COUNT = 1629,
     KW_FIRST = 1634,
     KW_FLOAT = 1635,
     GRANT = 1638,
     INDEX = 1641,
     LESS_THAN = 1644,
     MONEY = 1646,
     MONTH = 1647,
     KW_MULTIPLY = 1649,
     ORDER = 1650,
     OUTER = 1651,
     UNION = 1660,
     WHERE = 1663,
     KW_BYTE = 1670,
     CASE = 1672,
     KW_DATE = 1674,
     DESC = 1675,
     KW_DIVIDE = 1676,
     DROP = 1679,
     ELSE = 1680,
     FROM = 1684,
     HOUR = 1690,
     INTO = 1691,
     LIKE = 1694,
     REAL = 1703,
     SOME = 1708,
     KW_TEXT = 1712,
     KW_THEN = 1713,
     USER = 1714,
     WHEN = 1716,
     YEAR = 1719,
     KW_DOW = 1720,
     XSET = 1722,
     ADD = 1723,
     ALL = 1724,
     KW_AND = 1725,
     ANY = 1726,
     ASC = 1727,
     AVG = 1728,
     COLON = 1729,
     KW_COMMA = 1730,
     DAY = 1731,
     DBA = 1732,
     KW_FOR = 1736,
     XMAX = 1741,
     XMIN = 1742,
     KW_MINUS = 1743,
     KW_MOD = 1744,
     KW_NOT = 1745,
     KW_SUM = 1752,
     ATSIGN = 1755,
     KW_PLUS = 1756,
     KW_AS = 1762,
     KW_BY = 1764,
     KW_DOT = 1765,
     KW_IN = 1768,
     KW_ON = 1770,
     KW_OR = 1771,
     KW_TO = 1772,
     BEFORE = 1810,
     END = 1814,
     TILDE = 1821,
     ILIKE = 1822,
     FILLFACTOR = 1825,
     TIME = 1830,
     KW_TODAY = 1837,
     KW_ROWID = 1838,
     TIMESTAMP = 2186,
     KW_TAG = 2207,
     LINTMODULEISLIBRARY = 2208
   };
#endif
/* Tokens.  */
#define INT_VALUE 2210
#define NAMED 2211
#define NAMED_GEN 2212
#define CHAR_VALUE 2213
#define NOT_USED_1 2214
#define NOT_USED_2 2215
#define NOT_USED_3 2216
#define NOT_USED_4 2217
#define NOT_USED_5 2218
#define NOT_USED_6 2219
#define NOT_USED_7 2220
#define NOT_USED_8 2221
#define NUMBER_VALUE 2222
#define SEMICOLON 2223
#define QUESTION_MARK 2224
#define CLINE 2225
#define CH 2226
#define MARK_VAR 2227
#define END_MARK_VAR 2228
#define LEFT_JOIN 1002
#define DISPLAY_NULL_TO 1005
#define ON_CHANGE 1006
#define INNER_JOIN 1007
#define UI_INTERFACE_DOT_FRONTCALL 1010
#define UICOMBOBOX 1014
#define UIFORM 1015
#define USING_BTREE 1033
#define USING_RTREE 1034
#define SET_BUFFERED_LOG 1059
#define SET_LOG 1062
#define MDY 1064
#define WEEKDAY 1065
#define MODE_ANSI 1068
#define START_DATABASE 1069
#define WITH_LOG_IN 1070
#define SET_CONSTRAINTS_ALL_IMMEDIATE 1071
#define DATETIME_VALUE 1084
#define INTERVAL_VALUE 1085
#define RECOVER_TABLE 1086
#define ROLLFORWARD_DATABASE 1087
#define DROP_TRIGGER 1103
#define DROP_AUDIT_FOR 1104
#define CREATE_AUDIT_FOR 1105
#define EXECUTE_PROCEDURE 1109
#define ALTER_TABLE 1116
#define ALTER_INDEX 1117
#define NEXT_SIZE 1118
#define XSET_MULTIPLY_EQUAL_OPEN_BRACKET 1155
#define XSET_ident_DOT_MULTIPLY_EQUAL_OPEN_BRACKET 1156
#define XSET_ident_DOT_MULTIPLY_EQUAL 1157
#define XSET_MULTIPLY_EQUAL 1158
#define XSET_OPEN_BRACKET 1159
#define CREATE_DATABASE 1162
#define DROP_DATABASE 1163
#define ADD_CONSTRAINT 1165
#define DROP_CONSTRAINT 1166
#define DROP_SYNONYM 1167
#define CONSTRAINT 1168
#define NOT_FIELD_TOUCHED_CURRENT 1171
#define FIELD_TOUCHED_CURRENT 1172
#define DOUBLE_PRECISION 1179
#define COUNT_MULTIPLY 1180
#define MODIFY_NEXT_SIZE 1200
#define LOCK_MODE_PAGE 1201
#define LOCK_MODE_ROW 1202
#define UNITS_YEAR 1209
#define UNITS_MONTH 1210
#define UNITS_DAY 1211
#define UNITS_HOUR 1212
#define UNITS_MINUTE 1213
#define UNITS_SECOND 1214
#define TO_CLUSTER 1219
#define TO_NOT_CLUSTER 1220
#define CREATE_UC_IDX 1222
#define CREATE_U_IDX 1223
#define CREATE_C_IDX 1224
#define CREATE_IDX 1225
#define DOUBLE_COLON 1235
#define SQLSICS 1241
#define CREATE_SCHEMA 1242
#define SQLSIRR 1243
#define UPDATESTATS_T 1244
#define SQLSICR 1245
#define SQLSIDR 1256
#define CREATE_TEMP_TABLE 1257
#define WITH_CHECK_OPTION 1265
#define WITH_GRANT_OPTION 1266
#define SQLSLMNW 1267
#define WHERE_CURRENT_OF 1273
#define NOT_NULL_UNIQUE 1281
#define SQLSLMW 1288
#define ALL_PRIVILEGES 1290
#define CREATE_SYNONYM 1294
#define DROP_TABLE 1295
#define INEXCLUSIVE 1297
#define UPDATESTATS 1302
#define CREATE_TABLE 1328
#define DEFAULT_NULL 1329
#define DEFAULT_TODAY 1330
#define DEFAULT_USER 1331
#define UNLOCK_TABLE 1344
#define ROLLBACK_W 1352
#define SQLSEON 1354
#define SQLSEOFF 1355
#define CREATE_VIEW 1359
#define DELETE_FROM 1360
#define EXTENT_SIZE 1367
#define FOREIGN_KEY 1368
#define INSERT_INTO 1371
#define IS_NOT_NULL 1373
#define NOT_MATCHES 1376
#define PRIMARY_KEY 1382
#define USE_SESSION 1389
#define WITH_NO_LOG 1390
#define INSHARE 1393
#define BEGIN_WORK 1399
#define DROP_INDEX 1404
#define FOR_UPDATE_OF 1410
#define FOR_UPDATE 1411
#define LOCK_TABLE 1416
#define NOT_EXISTS 1418
#define REFERENCES 1420
#define RENCOL 1421
#define SMALLFLOAT 1423
#define COMMIT_W 1434
#define RENTAB 1441
#define KW_CHAR 1444
#define NCHAR 1445
#define NVARCHAR 1446
#define DELIMITER 1448
#define DROP_VIEW 1450
#define EXCLUSIVE 1453
#define GREATER_THAN_EQ 1457
#define INTO_TEMP 1459
#define DATABASE 1483
#define DATETIME 1484
#define DISTINCT 1486
#define FRACTION 1493
#define GROUP_BY 1495
#define INTERVAL 1496
#define NOT_LIKE 1498
#define NOT_ILIKE 1499
#define NOT_NULL 1500
#define RESOURCE 1506
#define SMALLINT 1507
#define IS_NULL 1513
#define LESS_THAN_EQ 1514
#define BETWEEN 1516
#define CLOSE_BRACKET 1519
#define CONNECT 1522
#define KW_CURRENT 1523
#define KW_DECIMAL 1525
#define DEFAULT 1527
#define INTEGER 1535
#define SERIAL8 1537
#define MATCHES 1540
#define VARCHAR 1553
#define CLOSE_SQUARE 1556
#define GREATER_THAN 1557
#define KW_FALSE 1558
#define NOT_IN 1559
#define OPEN_BRACKET 1561
#define KW_DELETE 1569
#define KW_ESCAPE 1572
#define EXISTS 1573
#define EXTEND 1574
#define HAVING 1578
#define KW_INSERT 1580
#define MINUTE 1584
#define MODIFY 1585
#define EQUAL 1587
#define NOT_EQUAL 1588
#define OPEN_SQUARE 1590
#define PUBLIC 1594
#define REVOKE 1598
#define SECOND 1602
#define KW_SELECT 1606
#define SERIAL 1607
#define UNIQUE 1610
#define KW_UPDATE 1612
#define VALUES 1613
#define KW_NULL 1616
#define KW_TRUE 1617
#define ALTER 1619
#define CHECK 1625
#define COUNT 1629
#define KW_FIRST 1634
#define KW_FLOAT 1635
#define GRANT 1638
#define INDEX 1641
#define LESS_THAN 1644
#define MONEY 1646
#define MONTH 1647
#define KW_MULTIPLY 1649
#define ORDER 1650
#define OUTER 1651
#define UNION 1660
#define WHERE 1663
#define KW_BYTE 1670
#define CASE 1672
#define KW_DATE 1674
#define DESC 1675
#define KW_DIVIDE 1676
#define DROP 1679
#define ELSE 1680
#define FROM 1684
#define HOUR 1690
#define INTO 1691
#define LIKE 1694
#define REAL 1703
#define SOME 1708
#define KW_TEXT 1712
#define KW_THEN 1713
#define USER 1714
#define WHEN 1716
#define YEAR 1719
#define KW_DOW 1720
#define XSET 1722
#define ADD 1723
#define ALL 1724
#define KW_AND 1725
#define ANY 1726
#define ASC 1727
#define AVG 1728
#define COLON 1729
#define KW_COMMA 1730
#define DAY 1731
#define DBA 1732
#define KW_FOR 1736
#define XMAX 1741
#define XMIN 1742
#define KW_MINUS 1743
#define KW_MOD 1744
#define KW_NOT 1745
#define KW_SUM 1752
#define ATSIGN 1755
#define KW_PLUS 1756
#define KW_AS 1762
#define KW_BY 1764
#define KW_DOT 1765
#define KW_IN 1768
#define KW_ON 1770
#define KW_OR 1771
#define KW_TO 1772
#define BEFORE 1810
#define END 1814
#define TILDE 1821
#define ILIKE 1822
#define FILLFACTOR 1825
#define TIME 1830
#define KW_TODAY 1837
#define KW_ROWID 1838
#define TIMESTAMP 2186
#define KW_TAG 2207
#define LINTMODULEISLIBRARY 2208




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
#line 774 "y.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 786 "y.tab.c"

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
#define YYLAST   2581

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  258
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  227
/* YYNRULES -- Number of rules.  */
#define YYNRULES  630
/* YYNRULES -- Number of states.  */
#define YYNSTATES  1122

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   2228

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
      26,     2,     2,     2,    27,    28,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    29,    30,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    31,
       2,     2,    32,     2,    33,    34,     2,     2,    35,    36,
      37,    38,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,    39,    40,    41,    42,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    43,    44,    45,     2,     2,     2,    46,
       2,     2,     2,     2,     2,     2,    47,    48,    49,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,    50,    51,    52,    53,    54,
       2,     2,    55,    56,     2,    57,    58,    59,    60,     2,
       2,    61,    62,     2,     2,     2,     2,     2,     2,    63,
      64,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      65,    66,    67,     2,     2,     2,     2,     2,     2,    68,
      69,    70,    71,    72,    73,     2,     2,     2,     2,    74,
      75,     2,    76,    77,    78,    79,     2,     2,     2,     2,
       2,     2,     2,     2,     2,    80,     2,     2,     2,     2,
       2,    81,    82,    83,    84,    85,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,    86,    87,     2,     2,
       2,     2,     2,     2,     2,    88,    89,    90,     2,     2,
       2,     2,     2,    91,     2,     2,     2,     2,     2,     2,
       2,    92,     2,     2,     2,     2,     2,     2,    93,     2,
      94,     2,     2,     2,    95,    96,     2,    97,     2,     2,
       2,     2,    98,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    99,   100,
     101,   102,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,   103,     2,     2,     2,     2,     2,
       2,     2,   104,     2,   105,   106,     2,     2,     2,   107,
     108,     2,     2,     2,     2,     2,     2,   109,   110,     2,
       2,   111,     2,   112,     2,     2,   113,     2,     2,     2,
       2,     2,   114,     2,     2,     2,     2,     2,     2,   115,
     116,     2,     2,   117,     2,     2,     2,     2,     2,   118,
       2,     2,     2,     2,   119,     2,     2,     2,     2,     2,
     120,   121,     2,     2,     2,     2,   122,     2,   123,     2,
     124,   125,     2,   126,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,   127,     2,     2,     2,     2,     2,
       2,   128,     2,     2,   129,   130,   131,     2,   132,     2,
     133,     2,     2,   134,     2,     2,     2,   135,     2,   136,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   137,   138,     2,   139,     2,     2,     2,
       2,     2,     2,   140,     2,   141,   142,     2,   143,   144,
     145,     2,     2,     2,     2,     2,   146,   147,     2,     2,
       2,     2,     2,   148,   149,     2,   150,     2,     2,   151,
       2,     2,   152,   153,     2,   154,     2,   155,     2,     2,
       2,     2,     2,     2,     2,   156,     2,   157,     2,     2,
     158,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   159,     2,     2,   160,   161,   162,   163,
       2,   164,     2,     2,     2,     2,     2,     2,     2,   165,
       2,     2,   166,   167,   168,     2,     2,     2,   169,     2,
     170,     2,     2,     2,   171,   172,     2,   173,   174,     2,
     175,     2,     2,     2,   176,     2,     2,     2,   177,     2,
       2,     2,   178,     2,     2,     2,   179,   180,     2,     2,
     181,     2,   182,   183,     2,     2,   184,   185,     2,   186,
       2,     2,     2,     2,     2,   187,     2,     2,     2,   188,
       2,     2,     2,     2,   189,   190,     2,     2,   191,     2,
       2,   192,     2,     2,   193,     2,   194,   195,     2,   196,
     197,   198,     2,     2,     2,     2,     2,     2,     2,     2,
     199,     2,     2,   200,     2,     2,     2,     2,     2,     2,
     201,     2,   202,     2,   203,   204,   205,     2,     2,   206,
     207,     2,     2,     2,   208,     2,     2,     2,     2,     2,
     209,   210,     2,     2,   211,     2,     2,     2,     2,     2,
       2,     2,     2,   212,     2,     2,     2,     2,   213,     2,
       2,     2,   214,   215,   216,     2,   217,     2,     2,   218,
     219,     2,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,     2,     2,     2,   231,     2,     2,     2,
       2,   232,   233,   234,   235,   236,     2,     2,     2,     2,
       2,     2,   237,     2,     2,   238,   239,     2,     2,     2,
       2,     2,   240,     2,   241,   242,     2,     2,   243,     2,
     244,   245,   246,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     247,     2,     2,     2,   248,     2,     2,     2,     2,     2,
       2,   249,   250,     2,     2,   251,     2,     2,     2,     2,
     252,     2,     2,     2,     2,     2,     2,   253,   254,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,   255,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,   256,   257,     2,
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
     465,     0,    -1,   182,   456,   262,   260,    -1,    -1,    91,
     460,    -1,   200,   371,    -1,    -1,    91,   460,    -1,   200,
     371,    -1,    54,   267,   151,   173,   164,   268,   151,    -1,
      50,   268,   151,    -1,    51,   268,   151,    -1,   220,   263,
      -1,    53,   268,    -1,    52,   268,    -1,   266,    -1,   263,
     228,   266,    -1,   265,    -1,   238,   265,    -1,   459,   397,
      -1,   459,   242,   459,   397,    -1,   459,   242,   459,   242,
     459,   397,    -1,   459,   242,   196,    -1,   264,   173,   269,
      -1,   264,    -1,   267,   228,   264,    -1,   269,    -1,   268,
     228,   269,    -1,   444,    -1,   184,    -1,   271,    -1,    96,
     456,    -1,   133,   456,    -1,   119,   458,    -1,    43,   459,
      -1,   282,    -1,   273,    -1,    99,   456,   164,   287,   151,
     274,    -1,    87,   456,   164,   287,   151,   283,   274,   283,
      -1,    -1,   275,    -1,   276,    -1,   275,   276,    -1,   243,
     277,    -1,   109,     3,    -1,    49,     3,    -1,    66,    -1,
      67,    -1,     4,    -1,    -1,   279,    -1,   280,    -1,   279,
     280,    -1,   243,   277,    -1,   251,     3,    -1,    29,    -1,
      30,    -1,   456,    -1,    77,   458,   244,   281,   164,   285,
     151,   278,    -1,    76,   458,   244,   281,   164,   285,   151,
     278,    -1,    78,   458,   244,   281,   164,   285,   151,   278,
      -1,    79,   458,   244,   281,   164,   285,   151,   278,    -1,
      55,   469,    -1,    56,   469,    -1,    95,   456,   231,   456,
      -1,    45,   456,   243,     6,    -1,    44,   456,    -1,    59,
     456,    -1,    41,   456,    -1,    42,   459,    -1,    -1,   116,
      -1,    -1,   116,    -1,   286,    -1,   285,   228,   286,    -1,
     459,   225,    -1,   459,   204,    -1,   459,    -1,   288,    -1,
     287,   228,   288,    -1,   351,    -1,   349,    -1,    47,   459,
     290,    -1,    48,   458,    74,    -1,    48,   458,    75,    -1,
     291,    -1,   290,   228,   291,    -1,   292,    -1,   295,    -1,
     298,    -1,   303,    -1,   306,    -1,   302,    -1,   301,    -1,
     221,   293,    -1,   221,   164,   294,   151,    -1,   288,    -1,
     288,   247,   459,    -1,   293,    -1,   294,   228,   293,    -1,
     206,   297,    -1,   206,   164,   296,   151,    -1,   297,    -1,
     296,   228,   297,    -1,   459,    -1,   172,   300,    -1,   172,
     164,   299,   151,    -1,   300,    -1,   299,   228,   300,    -1,
     288,    -1,    66,    -1,    67,    -1,    65,     3,    -1,    57,
     349,   305,    -1,    57,   164,   304,   151,    -1,   349,   305,
      -1,   304,   228,   349,   305,    -1,    -1,    60,   459,    -1,
      58,   307,    -1,    58,   164,   307,   151,    -1,   308,    -1,
     307,   228,   308,    -1,   459,    -1,   104,    -1,    -1,   111,
     311,   456,   314,   312,    -1,    -1,   183,   313,   164,   317,
     151,    -1,   438,    -1,    -1,   164,   315,   151,    -1,   316,
      -1,   315,   228,   316,    -1,   459,    -1,   459,   242,   459,
      -1,   318,    -1,   317,   228,   318,    -1,   444,    -1,   184,
      -1,   108,   456,   261,    -1,   118,    -1,   127,    -1,    -1,
     134,    -1,   324,    -1,    36,   459,    37,     6,    35,    -1,
      36,   459,    37,     6,    -1,    38,    -1,    31,    -1,    32,
      -1,    84,   459,    -1,    98,    -1,   321,    -1,   320,    -1,
     309,    -1,   323,    -1,   357,    -1,   361,    -1,   408,    -1,
     270,    -1,   272,    -1,   289,    -1,   191,   330,   244,   456,
     246,   335,   329,    -1,   177,   330,   244,   456,   208,   335,
      -1,   191,   328,   246,   335,    -1,   177,   328,   208,   335,
      -1,   152,    -1,   146,    -1,   230,    -1,    -1,    89,    -1,
     240,   396,    -1,    94,    -1,   222,    -1,   331,    -1,   332,
      -1,   331,   228,   332,    -1,   179,   333,    -1,   170,    -1,
     165,    -1,   182,   333,    -1,   186,    -1,   192,    -1,    -1,
     164,   334,   151,    -1,   398,    -1,   334,   228,   398,    -1,
     336,    -1,   335,   228,   336,    -1,   176,    -1,   396,    -1,
     107,   456,   338,   240,   429,   340,    -1,    -1,   164,   339,
     151,    -1,   398,    -1,   339,   228,   398,    -1,    -1,    88,
      -1,   187,   164,   428,   151,    -1,   110,   164,   344,   151,
     343,    -1,   124,   345,    -1,   346,    -1,   456,    -1,   456,
     164,   346,   151,    -1,   398,    -1,   346,   228,   398,    -1,
     181,   164,   348,   151,    -1,   139,   164,   348,   151,    -1,
     114,   164,   348,   151,    -1,   398,    -1,   348,   228,   398,
      -1,   347,    -1,   342,    -1,   341,    -1,   155,   403,    -1,
     102,    -1,   101,    -1,   100,    -1,   459,   387,   352,   353,
      -1,    -1,   350,    -1,    -1,   354,    -1,   355,    -1,   354,
     355,    -1,   356,   305,    -1,   145,    -1,    92,    -1,   181,
      -1,   139,    -1,   343,    -1,   187,   164,   428,   151,    -1,
     114,    -1,    82,   358,   360,    -1,   359,    -1,   396,    -1,
     361,    -1,   360,   361,    -1,   337,    -1,   327,    -1,   169,
     371,    -1,   200,   371,    -1,   208,   365,    -1,   367,    -1,
     365,   228,   367,    -1,   365,   228,   198,   367,    -1,   365,
     228,   198,   164,   365,   151,    -1,   365,    22,   366,   244,
     371,    -1,   365,    25,   366,   244,   371,    -1,   365,    -1,
     164,   365,   151,    -1,   456,    -1,   456,   402,    -1,   456,
     240,   402,    -1,    -1,   364,   369,    -1,   370,    -1,   363,
     370,    -1,    -1,   425,    -1,   425,   362,    -1,   362,    -1,
     372,    -1,   371,   245,   372,    -1,   373,    -1,   372,   223,
     373,    -1,   374,    -1,   236,   374,    -1,   384,    -1,   164,
     371,   151,    -1,   167,   439,    -1,   123,   439,    -1,    -1,
     166,   380,    -1,    -1,   166,   380,    -1,    -1,   166,   380,
      -1,   482,    -1,   403,    -1,    -1,   236,    -1,   444,   381,
     148,    -1,   444,   381,   112,    -1,   444,   383,   444,    -1,
     444,   173,   444,    -1,   444,   173,   184,    -1,   444,   381,
     150,   444,   223,   444,    -1,   444,   211,   379,   378,    -1,
     444,   143,   379,   378,    -1,   444,   250,   379,   377,    -1,
     444,   144,   379,   377,    -1,   444,   158,   379,   376,    -1,
     444,   113,   379,   376,    -1,   174,    -1,   193,    -1,   161,
      -1,   249,    -1,   149,    -1,   135,    -1,   382,    -1,   451,
      -1,   375,    -1,   444,    -1,    -1,   222,    -1,   139,    -1,
     181,    -1,    -1,   222,    -1,   139,    -1,   181,    -1,   388,
      -1,   389,    -1,   390,    -1,   392,    -1,   129,    -1,   129,
     164,   393,   151,    -1,   180,    -1,   180,   164,     3,   151,
      -1,   157,    -1,   157,   164,     3,   151,    -1,   154,    -1,
     154,   164,   394,   391,   151,    -1,   194,   164,   394,   391,
     151,    -1,   194,    -1,   203,    -1,   156,    -1,   147,    -1,
     130,    -1,   130,   164,   393,   151,    -1,   131,    -1,   131,
     164,     3,   151,    -1,   131,   164,     3,   228,     3,   151,
      -1,   138,   405,   246,   406,    -1,   138,    -1,   142,   405,
     246,   406,    -1,   430,    -1,   142,    -1,   142,   405,   164,
       3,   151,   246,   406,    -1,   214,    -1,   201,    -1,   159,
      -1,   159,   164,     3,   151,    -1,   159,   164,     3,   228,
       3,   151,    -1,    -1,   228,   395,    -1,   190,   164,   394,
     151,    -1,   212,    -1,   126,    -1,   190,    -1,    63,    -1,
       3,    -1,     3,    -1,     3,    -1,   459,    -1,     6,    -1,
      -1,   175,     3,   160,    -1,   175,     3,   228,     3,   160,
      -1,   401,    -1,   238,   401,    -1,   400,    -1,   238,   400,
      -1,   459,   397,    -1,   454,   242,   459,   397,    -1,   454,
     242,   196,    -1,   254,    -1,   459,   397,    -1,   454,   242,
     459,   397,    -1,   459,   242,   459,   242,   459,   397,    -1,
     454,   242,   196,    -1,   459,    -1,     6,    -1,   461,    -1,
       3,    -1,   419,    -1,    -1,   405,   246,   406,    -1,   218,
      -1,   195,    -1,   229,    -1,   209,    -1,   171,    -1,   178,
      -1,   140,    -1,   218,    -1,   195,    -1,   229,    -1,   209,
      -1,   171,    -1,   178,    -1,   140,    -1,   140,   164,     3,
     151,    -1,    46,   459,   164,   151,    -1,    46,   459,   164,
     448,   151,    -1,   413,    -1,   412,    -1,   409,    -1,   407,
      -1,   128,   410,   246,   410,    -1,   125,   454,   242,   411,
     246,   411,    -1,   459,    -1,   459,    -1,   103,   456,    -1,
     122,   456,   414,    -1,   117,    -1,    97,    -1,   416,    -1,
     416,   405,   246,   406,    -1,    39,    -1,   418,    -1,   418,
     405,   164,     3,   151,   246,   406,    -1,   418,   405,   246,
     406,    -1,    40,    -1,   153,   404,    -1,   197,   241,   421,
      -1,   422,    -1,   421,   228,   422,    -1,   423,   424,    -1,
       3,    -1,   399,    -1,    -1,   225,    -1,   204,    -1,   141,
     426,    -1,   427,    -1,   426,   228,   427,    -1,   399,    -1,
       3,    -1,   371,    -1,   438,    -1,   252,    -1,   252,   164,
       3,   151,    -1,   255,    -1,   255,   164,     3,   151,    -1,
      -1,    -1,   179,   440,   441,   432,   442,   433,   463,   368,
     435,   436,    -1,   179,   440,   441,   442,   368,   435,    -1,
      -1,   199,   386,   434,    -1,    -1,   420,    -1,   420,   136,
     437,   284,    -1,   136,   437,   284,    -1,   459,    -1,   179,
     440,   441,   442,   368,    -1,   164,   179,   440,   441,   442,
     368,   151,    -1,    -1,   189,     3,    -1,    -1,   222,    -1,
     139,    -1,   181,    -1,   443,    -1,   442,   228,   443,    -1,
     444,    -1,   444,   459,    -1,   444,   240,   459,    -1,   482,
      -1,   234,   482,    -1,   239,   482,    -1,   482,   205,   444,
      -1,   482,   450,    -1,   482,   196,   444,    -1,   482,   239,
     444,    -1,   482,   234,   444,    -1,   403,    -1,   185,    -1,
     162,    -1,   216,    -1,   253,    -1,   254,    -1,   252,    -1,
     196,    -1,    64,    -1,   226,   164,   385,   444,   151,    -1,
     232,   164,   385,   444,   151,    -1,   233,   164,   385,   444,
     151,    -1,   237,   164,   385,   444,   151,    -1,   188,   164,
     385,   444,   151,    -1,     4,   164,   151,    -1,     4,   164,
     448,   151,    -1,   218,   164,   448,   151,    -1,   195,   164,
     448,   151,    -1,   229,   164,   448,   151,    -1,    33,   164,
     448,   151,    -1,    34,   164,   448,   151,    -1,   219,   164,
     448,   151,    -1,   203,   164,   448,   151,    -1,   164,   444,
     151,    -1,   168,   164,   449,   151,    -1,   415,    -1,   417,
      -1,   202,   446,   248,    -1,   447,    -1,   446,   447,    -1,
     217,   371,   215,   444,    -1,   207,   444,    -1,   444,    -1,
     448,   228,   444,    -1,   153,   228,   405,   246,   406,    -1,
     475,   228,   405,   246,   406,    -1,   153,   405,   246,   406,
      -1,   444,   228,   405,   246,   406,    -1,    68,    -1,    69,
      -1,    70,    -1,    71,    -1,    72,    -1,    73,    -1,   444,
     243,   164,   452,   151,    -1,   444,   243,   439,    -1,   444,
     163,   164,   452,   151,    -1,   444,   163,   439,    -1,   453,
      -1,   452,   228,   453,    -1,   475,    -1,   403,    -1,   234,
       3,    -1,   234,   461,    -1,   455,    -1,     6,    -1,     6,
     242,   459,    -1,   459,    -1,   459,   227,   459,    -1,   459,
     227,     6,   242,   459,    -1,   459,   238,   459,    -1,   459,
     238,   459,   227,   459,    -1,   459,   238,   459,   227,     6,
     242,   459,    -1,   457,    -1,     6,   242,   459,    -1,   459,
     242,   459,    -1,     6,    -1,   459,    -1,   459,   227,   459,
      -1,   459,   227,     6,   242,   459,    -1,   459,   238,   459,
      -1,   459,   238,   459,   227,   459,    -1,   459,   238,   459,
     227,     6,   242,   459,    -1,     6,   242,   459,    -1,     6,
      -1,   459,    -1,   459,   227,   459,    -1,   459,   227,     6,
     242,   459,    -1,   459,   238,   459,    -1,   459,   238,   459,
     227,   459,    -1,   459,   238,   459,   227,     6,   242,   459,
      -1,     4,    -1,     4,    -1,    15,    -1,   242,     3,    -1,
       4,    -1,     6,    -1,    -1,   459,    -1,   467,    -1,   465,
      16,   467,    -1,   310,    -1,   259,    -1,   319,    -1,    -1,
     476,    -1,   326,    -1,   468,    -1,   474,    -1,   466,    -1,
     325,    -1,     1,    -1,   470,   471,    -1,   464,    -1,   431,
      -1,    -1,   121,    -1,   120,   472,    -1,   473,    -1,   472,
     228,   473,    -1,   459,    -1,   459,   242,   459,    -1,     6,
     242,   459,   242,   459,    -1,   106,    -1,   105,    -1,    93,
     484,    -1,    90,    -1,    86,    -1,    83,    -1,    81,    -1,
      85,    -1,   481,    -1,    17,    -1,   477,    -1,   137,   462,
     322,    -1,    20,     6,    21,    -1,   164,   478,   151,    -1,
     478,   479,   478,    -1,     3,    -1,   480,     3,    -1,   239,
      -1,   234,    -1,   196,    -1,   205,    -1,   235,    -1,   239,
      -1,   234,    -1,   459,    -1,   459,   242,   196,    -1,   459,
     242,   254,    -1,   459,   242,   459,    -1,   459,   242,   459,
     242,   459,    -1,     6,   242,   459,   242,   459,    -1,   459,
     175,   478,   160,    -1,   459,   242,   459,   175,   478,   160,
      -1,   459,   242,   459,   242,   459,   175,   478,   160,    -1,
       6,   242,   459,   242,   459,   175,   478,   160,    -1,   459,
     175,   478,   228,   478,   160,    -1,   459,   242,   459,   175,
     478,   228,   478,   160,    -1,   459,   242,   459,   242,   459,
     175,   478,   228,   478,   160,    -1,     6,   242,   459,   242,
     459,   175,   478,   228,   478,   160,    -1,   483,    -1,   483,
      80,   387,    -1,   445,    -1,   475,    -1,   439,    -1,   222,
     439,    -1,   224,   439,    -1,   213,   439,    -1,    -1,     3,
      -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   407,   407,   433,   436,   453,   458,   461,   478,   484,
     493,   502,   511,   518,   533,   588,   595,   606,   609,   614,
     621,   638,   655,   676,   685,   688,   696,   699,   707,   708,
     715,   718,   726,   729,   733,   739,   740,   744,   754,   768,
     769,   773,   774,   779,   787,   795,   803,   811,   821,   823,
     823,   826,   827,   831,   838,   845,   852,   861,   865,   872,
     884,   895,   901,   905,   909,   914,   918,   921,   925,   928,
     935,   936,   946,   947,   951,   952,   956,   965,   974,   981,
     984,   990,   993,  1004,  1008,  1013,  1020,  1023,  1032,  1035,
    1039,  1043,  1047,  1051,  1055,  1063,  1067,  1075,  1078,  1085,
    1088,  1095,  1098,  1105,  1106,  1111,  1115,  1118,  1124,  1127,
    1133,  1140,  1141,  1145,  1153,  1157,  1164,  1166,  1171,  1172,
    1176,  1178,  1184,  1185,  1188,  1199,  1205,  1205,  1214,  1214,
    1223,  1248,  1251,  1259,  1262,  1269,  1272,  1280,  1281,  1287,
    1288,  1296,  1314,  1318,  1323,  1324,  1334,  1343,  1347,  1351,
    1356,  1360,  1364,  1367,  1374,  1375,  1376,  1380,  1381,  1382,
    1383,  1384,  1385,  1386,  1394,  1395,  1396,  1397,  1402,  1403,
    1404,  1407,  1408,  1409,  1413,  1414,  1415,  1419,  1420,  1424,
    1431,  1432,  1433,  1440,  1441,  1444,  1445,  1450,  1451,  1456,
    1457,  1462,  1463,  1468,  1475,  1476,  1481,  1482,  1486,  1487,
    1494,  1502,  1509,  1516,  1520,  1521,  1526,  1527,  1533,  1537,
    1542,  1549,  1550,  1556,  1559,  1562,  1569,  1570,  1571,  1572,
    1578,  1599,  1600,  1603,  1605,  1612,  1615,  1621,  1629,  1634,
    1640,  1645,  1651,  1654,  1659,  1667,  1676,  1681,  1685,  1686,
    1692,  1695,  1706,  1715,  1722,  1728,  1729,  1732,  1737,  1748,
    1752,  1759,  1760,  1764,  1768,  1772,  1779,  1784,  1792,  1795,
    1801,  1804,  1809,  1814,  1827,  1830,  1836,  1839,  1845,  1848,
    1854,  1857,  1864,  1868,  1879,  1879,  1880,  1880,  1881,  1881,
    1884,  1889,  1894,  1895,  1900,  1909,  1917,  1920,  1923,  1927,
    1934,  1937,  1941,  1944,  1947,  1950,  1956,  1963,  1966,  1969,
    1972,  1973,  1978,  1981,  1984,  1987,  1994,  1995,  1996,  2000,
    2007,  2008,  2009,  2013,  2027,  2034,  2035,  2036,  2040,  2041,
    2046,  2047,  2056,  2058,  2067,  2070,  2078,  2088,  2096,  2098,
    2099,  2100,  2101,  2102,  2103,  2104,  2112,  2113,  2114,  2115,
    2116,  2117,  2118,  2119,  2120,  2121,  2122,  2132,  2133,  2139,
    2141,  2142,  2143,  2144,  2148,  2152,  2156,  2163,  2164,  2169,
    2170,  2174,  2182,  2185,  2192,  2195,  2205,  2208,  2211,  2214,
    2221,  2228,  2236,  2245,  2252,  2256,  2257,  2258,  2259,  2264,
    2266,  2275,  2275,  2275,  2275,  2275,  2275,  2275,  2276,  2276,
    2276,  2276,  2276,  2276,  2276,  2276,  2291,  2299,  2311,  2312,
    2313,  2314,  2319,  2320,  2323,  2324,  2328,  2335,  2346,  2347,
    2360,  2361,  2365,  2369,  2370,  2373,  2379,  2383,  2406,  2416,
    2419,  2425,  2434,  2438,  2445,  2446,  2448,  2453,  2459,  2462,
    2468,  2469,  2476,  2489,  2499,  2506,  2523,  2530,  2555,  2557,
    2555,  2579,  2623,  2624,  2638,  2641,  2648,  2658,  2670,  2676,
    2689,  2704,  2706,  2712,  2713,  2714,  2715,  2725,  2728,  2734,
    2737,  2742,  2751,  2754,  2758,  2765,  2768,  2771,  2774,  2777,
    2780,  2781,  2782,  2783,  2784,  2785,  2786,  2787,  2788,  2790,
    2794,  2798,  2802,  2806,  2810,  2814,  2818,  2821,  2824,  2827,
    2830,  2833,  2836,  2839,  2842,  2846,  2850,  2854,  2862,  2865,
    2874,  2880,  2887,  2890,  2918,  2921,  2924,  2927,  2933,  2934,
    2935,  2936,  2937,  2938,  2943,  2947,  2951,  2955,  2962,  2965,
    2970,  2971,  2972,  2974,  2980,  2990,  2994,  2998,  3002,  3006,
    3010,  3014,  3018,  3026,  3036,  3041,  3045,  3049,  3053,  3057,
    3062,  3066,  3070,  3078,  3081,  3086,  3087,  3088,  3093,  3094,
    3095,  3103,  3106,  3111,  3112,  3116,  3117,  3122,  3146,  3163,
    3164,  3168,  3175,  3181,  3191,  3193,  3196,  3197,  3198,  3199,
    3201,  3204,  3208,  3213,  3217,  3223,  3224,  3227,  3232,  3233,
    3236,  3237,  3238,  3248,  3249,  3250,  3251,  3252,  3253,  3254,
    3255,  3259,  3265,  3267,  3286,  3294,  3301,  3302,  3303,  3304,
    3309,  3310,  3311,  3312,  3313,  3318,  3319,  3335,  3336,  3337,
    3338,  3339,  3340,  3341,  3342,  3343,  3344,  3346,  3347,  3348,
    3349,  3354,  3357,  3366,  3367,  3368,  3369,  3370,  3371,  3375,
    3376
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
       0,   256,  2209,  2210,  2211,  2212,  2213,  2214,  2215,  2216,
    2217,  2218,  2219,  2220,  2221,  2222,  2223,  2224,  2225,  2226,
    2227,  2228,  1002,  1005,  1006,  1007,  1010,  1014,  1015,  1033,
    1034,  1059,  1062,  1064,  1065,  1068,  1069,  1070,  1071,  1084,
    1085,  1086,  1087,  1103,  1104,  1105,  1109,  1116,  1117,  1118,
    1155,  1156,  1157,  1158,  1159,  1162,  1163,  1165,  1166,  1167,
    1168,  1171,  1172,  1179,  1180,  1200,  1201,  1202,  1209,  1210,
    1211,  1212,  1213,  1214,  1219,  1220,  1222,  1223,  1224,  1225,
    1235,  1241,  1242,  1243,  1244,  1245,  1256,  1257,  1265,  1266,
    1267,  1273,  1281,  1288,  1290,  1294,  1295,  1297,  1302,  1328,
    1329,  1330,  1331,  1344,  1352,  1354,  1355,  1359,  1360,  1367,
    1368,  1371,  1373,  1376,  1382,  1389,  1390,  1393,  1399,  1404,
    1410,  1411,  1416,  1418,  1420,  1421,  1423,  1434,  1441,  1444,
    1445,  1446,  1448,  1450,  1453,  1457,  1459,  1483,  1484,  1486,
    1493,  1495,  1496,  1498,  1499,  1500,  1506,  1507,  1513,  1514,
    1516,  1519,  1522,  1523,  1525,  1527,  1535,  1537,  1540,  1553,
    1556,  1557,  1558,  1559,  1561,  1569,  1572,  1573,  1574,  1578,
    1580,  1584,  1585,  1587,  1588,  1590,  1594,  1598,  1602,  1606,
    1607,  1610,  1612,  1613,  1616,  1617,  1619,  1625,  1629,  1634,
    1635,  1638,  1641,  1644,  1646,  1647,  1649,  1650,  1651,  1660,
    1663,  1670,  1672,  1674,  1675,  1676,  1679,  1680,  1684,  1690,
    1691,  1694,  1703,  1708,  1712,  1713,  1714,  1716,  1719,  1720,
    1722,  1723,  1724,  1725,  1726,  1727,  1728,  1729,  1730,  1731,
    1732,  1736,  1741,  1742,  1743,  1744,  1745,  1752,  1755,  1756,
    1762,  1764,  1765,  1768,  1770,  1771,  1772,  1810,  1814,  1821,
    1822,  1825,  1830,  1837,  1838,  2186,  2207,  2208
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint16 yyr1[] =
{
       0,   258,   259,   260,   260,   260,   261,   261,   261,   262,
     262,   262,   262,   262,   262,   263,   263,   264,   264,   265,
     265,   265,   265,   266,   267,   267,   268,   268,   269,   269,
     270,   271,   271,   271,   271,   272,   272,   273,   273,   274,
     274,   275,   275,   276,   276,   276,   276,   276,   277,   278,
     278,   279,   279,   280,   280,   280,   280,   281,   282,   282,
     282,   282,   282,   282,   282,   282,   282,   282,   282,   282,
     283,   283,   284,   284,   285,   285,   286,   286,   286,   287,
     287,   288,   288,   289,   289,   289,   290,   290,   291,   291,
     291,   291,   291,   291,   291,   292,   292,   293,   293,   294,
     294,   295,   295,   296,   296,   297,   298,   298,   299,   299,
     300,   301,   301,   302,   303,   303,   304,   304,   305,   305,
     306,   306,   307,   307,   308,   309,   311,   310,   313,   312,
     312,   314,   314,   315,   315,   316,   316,   317,   317,   318,
     318,   319,   320,   321,   322,   322,   323,   324,   324,   324,
     324,   324,   324,   324,   325,   325,   325,   326,   326,   326,
     326,   326,   326,   326,   327,   327,   327,   327,   328,   328,
     328,   329,   329,   329,   330,   330,   330,   331,   331,   332,
     332,   332,   332,   332,   332,   333,   333,   334,   334,   335,
     335,   336,   336,   337,   338,   338,   339,   339,   340,   340,
     341,   342,   343,   344,   345,   345,   346,   346,   347,   347,
     347,   348,   348,   349,   349,   349,   350,   350,   350,   350,
     351,   352,   352,   353,   353,   354,   354,   355,   356,   356,
     356,   356,   356,   356,   356,   357,   358,   359,   360,   360,
     361,   361,   362,   363,   364,   365,   365,   365,   365,   365,
     365,   366,   366,   367,   367,   367,   368,   368,   369,   369,
     370,   370,   370,   370,   371,   371,   372,   372,   373,   373,
     374,   374,   375,   375,   376,   376,   377,   377,   378,   378,
     379,   380,   381,   381,   382,   382,   382,   382,   382,   382,
     382,   382,   382,   382,   382,   382,   383,   383,   383,   383,
     383,   383,   384,   384,   384,   384,   385,   385,   385,   385,
     386,   386,   386,   386,   387,   388,   388,   388,   389,   389,
     390,   390,   390,   390,   390,   390,   390,   390,   390,   390,
     390,   390,   390,   390,   390,   390,   390,   390,   390,   390,
     390,   390,   390,   390,   390,   390,   390,   391,   391,   392,
     392,   392,   392,   392,   393,   394,   395,   396,   396,   397,
     397,   397,   398,   398,   399,   399,   400,   400,   400,   400,
     401,   401,   401,   401,   402,   403,   403,   403,   403,   404,
     404,   405,   405,   405,   405,   405,   405,   405,   406,   406,
     406,   406,   406,   406,   406,   406,   407,   407,   408,   408,
     408,   408,   409,   409,   410,   411,   412,   413,   414,   414,
     415,   415,   416,   417,   417,   417,   418,   419,   420,   421,
     421,   422,   423,   423,   424,   424,   424,   425,   426,   426,
     427,   427,   428,   429,   430,   430,   430,   430,   432,   433,
     431,   434,   435,   435,   436,   436,   436,   436,   437,   438,
     439,   440,   440,   441,   441,   441,   441,   442,   442,   443,
     443,   443,   444,   444,   444,   445,   445,   445,   445,   445,
     445,   445,   445,   445,   445,   445,   445,   445,   445,   445,
     445,   445,   445,   445,   445,   445,   445,   445,   445,   445,
     445,   445,   445,   445,   445,   445,   445,   445,   446,   446,
     447,   447,   448,   448,   449,   449,   449,   449,   450,   450,
     450,   450,   450,   450,   451,   451,   451,   451,   452,   452,
     453,   453,   453,   453,   454,   455,   455,   455,   455,   455,
     455,   455,   455,   456,   457,   457,   457,   457,   457,   457,
     457,   457,   457,   458,   458,   458,   458,   458,   458,   458,
     458,   459,   460,   461,   461,   462,   462,   463,   464,   465,
     465,   466,   466,   466,   467,   467,   467,   467,   467,   467,
     467,   467,   468,   469,   470,   471,   471,   471,   472,   472,
     473,   473,   473,   474,   474,   474,   474,   474,   474,   474,
     474,   475,   475,   475,   476,   477,   478,   478,   478,   478,
     479,   479,   479,   479,   479,   480,   480,   481,   481,   481,
     481,   481,   481,   481,   481,   481,   481,   481,   481,   481,
     481,   482,   482,   483,   483,   483,   483,   483,   483,   484,
     484
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
#define YYPACT_NINF -823
static const yytype_int16 yypact[] =
{
    2390,  -823,  -823,  -823,    75,  -823,   444,    75,    75,   444,
     444,    75,    75,   494,    75,    75,   444,   494,   494,   494,
     494,  -823,   626,  -823,    75,  -823,  -823,   444,  -823,   115,
     444,   444,  -823,   444,   444,  -823,  -823,  -823,   444,   444,
    -823,  -823,   494,   444,   657,  -823,    75,   444,   665,   470,
     -76,   444,   470,  -823,  -823,  -823,  -823,  -823,  -823,  -823,
    -823,  -823,  -823,  -823,  -823,  -823,  -823,  -823,  -823,  -823,
    -823,  -823,  -823,  -823,  -823,  -823,  -823,  -823,  -823,   258,
    -823,  -823,  -823,   427,  -823,  -823,  -823,    94,   -67,  -823,
    -823,   294,  -823,  -823,  -823,   -21,   109,   378,    42,   659,
      21,  -823,  -823,  -823,  -823,  -823,    80,   132,   150,   194,
    -823,    -7,  -823,  -823,  -823,  -823,   166,  -823,  -823,   189,
    -823,   200,  -823,   296,    18,   444,  -823,   173,   232,   263,
    -823,    45,   271,  -823,  -823,  -823,  -823,   354,  -823,  -823,
    -823,  -823,  -823,   371,   371,  -823,  -823,  -823,  -823,   351,
     308,   363,  -823,   599,   220,   151,   360,   367,  -823,  2390,
     689,  -823,  -823,   615,    75,   711,    75,    75,   639,  1199,
     574,    92,   686,  -823,  -823,   387,   100,   394,   471,  -823,
    -823,  -823,  -823,  -823,  -823,  -823,  -823,    75,  -823,  -823,
     743,    75,   444,   444,   444,   444,    -7,  -823,   246,   444,
     246,    99,   462,   710,   958,  -823,   557,  -823,  -823,  -823,
      75,    75,   772,    75,    75,  -823,  -823,    99,  -823,  -823,
     175,   444,   708,  -823,  -823,  -823,  -823,  -823,  1325,  1325,
    1325,  1325,    71,    71,    19,   175,   444,  -823,   502,   510,
     528,  -823,   724,  -823,   518,  -823,   546,  -823,  -823,  -823,
     621,   537,  -823,  -823,   794,   640,   645,  -823,  -823,  -823,
    -823,   429,  -823,  1440,   651,  -823,   669,   671,  -823,   215,
     674,   679,  -823,   680,   688,   679,   679,   693,   695,   712,
     713,  2163,   715,  2163,   820,  -823,  -823,  -823,  -823,  -823,
     429,  -823,   429,  -823,  -823,  -823,  -823,   -54,   -16,  -823,
    -823,  -823,  -823,   421,   770,   725,   731,   732,   272,   748,
     749,  -823,  -823,  -823,   814,    75,   690,  -823,  -823,  -823,
     246,  -823,  -823,  -823,  -823,   456,    75,  -823,  -823,   246,
     667,  -823,   378,  -823,   675,  -823,   701,   766,  -823,   767,
     769,   777,  -823,    14,  -823,  -823,    41,   657,    70,  -823,
    -823,   692,   459,   765,  -823,  -823,   679,   703,   679,  1084,
     704,   727,  -823,  -823,  -823,  -823,  -823,   846,  -823,    75,
     341,  -823,   702,  -823,   718,  -823,   726,  -823,    93,  -823,
    -823,   737,  -823,  -823,   744,  -823,  1922,  -823,   127,  -823,
    -823,   140,   738,   738,    75,  -823,  -823,   155,    91,   739,
     781,  -823,   710,   958,  -823,   737,   722,    75,    75,   689,
    -823,    75,   784,  1566,    75,   948,  1922,  1922,  -823,  -823,
    -823,  -823,  -823,  -823,  -823,  -823,   730,   -76,   819,  2048,
     242,  1922,  1922,   958,   426,  -823,  1922,   792,  -823,  1922,
    1922,  -823,  -823,   242,  1922,   242,   242,   421,   242,   421,
    -823,   733,   -12,  -823,  1922,    79,    51,  -823,  -823,  -823,
    -823,  -823,  -823,  1922,  1922,  1922,  1922,  -823,   456,    99,
      99,    99,   202,   814,    99,   958,    75,  -823,   206,    75,
     212,  -823,  -823,  -823,   808,   813,   818,   429,   429,  -823,
     821,  -823,   822,   823,   829,   835,   836,  -823,  -823,  -823,
    -823,   837,   841,    22,  -823,  -823,  -823,  -823,  -823,   218,
    -823,  -823,   226,    75,  -823,    75,   790,    75,    75,    75,
      75,   867,   246,    67,  -823,  -823,    99,    72,   981,    75,
    -823,   -76,   918,  -823,  -823,   -10,   619,  -823,  -823,   958,
     958,  2163,  -823,  2163,  2163,  -823,  2163,  -823,   844,  1681,
    -823,  -823,  2163,  -823,   847,  -823,  2163,   633,  1922,   228,
    -823,   768,  -823,  -823,  -823,    75,    75,   797,  -823,    99,
     175,   175,   788,  -823,    48,  -823,  1325,  -823,  -823,   845,
      71,    85,  -823,    71,  1325,  -823,   704,   175,   775,  -823,
    -823,  -823,   782,  -823,  -823,   233,   785,  -823,   241,   249,
     501,   220,  -823,   400,   795,   875,   800,  -823,  -823,  -823,
    1922,   255,  -823,   143,  -823,  -823,   300,   306,   311,  1922,
     325,  1922,  1922,  1922,   501,  1026,   501,  -823,  -823,    79,
    -823,  -823,   448,  1031,  -823,  -823,   102,  -823,  -823,  -823,
    -823,  -823,   885,   807,  -823,   327,  -823,   328,  -823,   272,
    -823,   329,   704,   887,  -823,  -823,  -823,  -823,   246,  1037,
    1037,  1038,   796,    -6,  1040,  1041,  1042,  1043,  1040,  1040,
    1044,  1045,  -823,  -823,  -823,    58,  -823,   357,  -823,    75,
    -823,   246,  -823,  -823,   809,  -823,   344,  -823,   -74,   391,
     392,   395,  -823,    67,  -823,  1047,  -823,  -823,  1049,  1050,
    -823,    67,  -823,  -823,  -823,   880,    -5,   816,   220,  -823,
    -823,  -823,   727,  -823,   893,   421,   894,   895,   893,   133,
    -823,  -823,  -823,   894,   133,  -823,   895,  -823,  -823,  1922,
    -823,  -823,    75,    75,   898,  -823,  -823,   824,  -823,  -823,
    -823,   737,  1922,  -823,    75,  -823,  -823,   899,  -823,  -823,
     171,  -823,  -823,    57,    75,    75,  -823,    75,  -823,  -823,
     901,  -823,  -823,  -823,  -823,  -823,  -823,  -823,  1922,   429,
     825,   429,  -823,   429,   916,  -823,  1922,  -823,  -823,  -823,
     919,  -823,   923,   924,   925,  -823,   926,  -823,   446,  -823,
    -823,  -823,    79,  -823,  -823,  -823,    79,  -823,    79,    75,
     945,    99,  -823,    99,  -823,   814,  -823,  -823,  -823,  -823,
     927,   932,   409,   501,  1081,   501,  -823,   863,   941,   437,
     942,   943,   863,   946,   947,  -823,  -823,  -823,  -823,   444,
    -823,  -823,  -823,   936,  -823,  -823,   357,  -823,   814,  -823,
    -823,    75,    98,    75,  -823,  -823,    98,    98,    98,   867,
    -823,  -823,  -823,  -823,  -823,  -823,  -823,  1099,    75,  1922,
      58,  -823,    58,  -823,    58,  -823,  -823,   105,  -823,   438,
    -823,  -823,  -823,   439,  -823,   882,  -823,  -823,  1807,    75,
    -823,   902,  -823,  1325,    75,  -823,  -823,   626,  -823,  -823,
    -823,   928,  1103,   279,   861,   501,   866,   868,  -823,  -823,
    -823,  -823,  -823,  -823,   869,  -823,   552,   593,   530,   934,
    -823,  -823,  -823,  -823,  -823,  -823,  -823,  1110,  -823,   965,
    -823,  1116,   970,  -823,  -823,  1124,  -823,  -823,   977,  -823,
    -823,  -823,   966,   958,  -823,  -823,  -823,  -823,  -823,  1050,
    1126,  -823,    98,  -823,  -823,  -823,  -823,  -823,  -823,   971,
     880,   279,  -823,  -823,  -823,  -823,  -823,  -823,  -823,   221,
    -823,  1922,  -823,   463,  -823,  -823,  -823,   444,   404,   933,
     497,   880,  -823,    79,   982,   983,   501,   984,   501,   501,
     501,  -823,  -823,    79,    79,   985,   891,  -823,  -823,  -823,
     987,  -823,    99,   988,  -823,  -823,  -823,  -823,  -823,  -823,
    -823,  -823,  -823,  1807,   110,  -823,    83,    77,   958,   958,
    -823,   201,  -823,  -823,   972,   277,   165,  -823,  -823,   579,
    -823,  -823,  -823,  -823,  -823,  -823,   612,   606,  -823,   501,
    -823,   543,  -823,  -823,   176,   176,   134,    75,  -823,  -823,
    -823,    54,  -823,  -823,  -823,   912,  -823,   900,   489,   704,
     704,  -823,  -823,  -823,  -823,  -823,   968,    75,   903,  1009,
    -823,  -823,    79,  -823,  -823,    79,  -823,  -823,   444,   110,
     905,   906,   208,  -823,  -823,  -823,    77,    86,  -823,   -76,
    -823,  1035,  -823,    82,    75,   614,   676,    47,   958,   958,
     444,  -823,  -823,  -823,   880,   220,  -823,  -823,  -823,  -823,
     929,  -823,   -47,  1035,  -823,  -823,  -823,   704,   704,   120,
    -823,  1922,    82,  -823,  -823,  -823,  -823,  -823,   279,  -823,
     933,  -823
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -823,  -823,  -823,  -823,  -823,  -823,  -181,   758,   572,  -823,
    -185,   -35,  -823,  -823,  -823,  -823,   465,  -823,   455,   223,
    -143,  -823,   217,   627,  -823,   314,    61,   389,   322,   967,
    -144,  -823,  -823,   834,  -823,  -272,  -823,  -823,  -823,  -277,
    -823,  -823,  -261,  -823,  -823,  -823,  -823,  -451,  -823,   853,
     691,  -823,  -823,  -823,  -823,  -823,  -823,  -823,   440,  -823,
     170,  -823,  -823,  -823,  -823,  -823,  -823,  -823,  -823,  -823,
    1117,  -823,  1123,  -823,   956,  1039,  -823,  -198,   609,  -823,
    -823,  -823,  -823,  -823,  -823,   381,  -823,  -823,   193,  -823,
     122,  -139,  -823,  -823,  -823,  -823,  -823,   350,  -823,  -823,
    -823,  -823,  -823,     3,   174,  -823,  -823,  -803,   154,  -821,
    -822,  -823,   182,  -203,   660,   656,   839,  -823,   483,   478,
     485,   469,   -33,  -823,  -823,  -823,  -823,   415,  -823,   741,
    -823,  -823,  -823,   384,  -823,   553,   224,  -823,    -3,  -370,
    -176,  -717,   177,   870,   178,  -607,  -823,  -242,  -561,  -823,
    -823,  -823,  1006,   658,  -823,  -823,  -823,  -823,  -823,  -823,
    -823,  -823,  -823,  -823,   112,  -823,  -823,  -823,  -823,   145,
     289,  -823,  -823,  -823,  -823,  -823,  -823,   106,  -823,   141,
     857,  -209,  -406,  -565,  -715,   486,  -137,  -823,  -823,   801,
     507,  -823,  -823,  -823,   505,   275,   -27,  -823,    68,  -823,
     884,    -4,   828,   364,  -823,  -823,  -823,  -823,  -823,  1077,
    -823,  1225,  -823,  -823,  -823,   832,  -823,  -405,  -823,  -823,
    -559,  -823,  -823,  -823,  -115,  -823,  -823
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
     452,   395,    86,   893,   344,    86,   344,   511,    86,   481,
     128,   249,   438,   785,   825,   787,   441,   442,   826,  1034,
     788,   975,  1035,   252,    89,    86,    86,    94,    95,    86,
    1040,    86,   628,   128,   105,  1098,    86,    86,   128,    86,
      86,   390,   390,   390,   390,   116,    86,   453,   119,   120,
      38,   121,   122,    86,    86,   128,   123,   124,   956,   203,
     402,   127,   868,   153,   197,   134,   695,   868,   117,   155,
     252,    91,   672,   673,   674,   708,   428,   937,   938,   999,
     844,   163,  1034,   696,   697,  1035,   249,    86,    86,   251,
      88,   711,  1034,   859,   951,  1035,   886,   534,   252,   537,
     253,   845,   625,   254,   535,   856,   239,  1113,   814,   455,
     243,   245,   246,   247,  1004,   521,   447,   318,   449,   473,
      49,   325,   328,   325,   454,   164,   698,   675,  1114,    86,
      86,   110,    88,   333,    52,   330,   335,   336,    91,    91,
      91,    91,   523,   206,   325,    91,   325,   352,  1106,   342,
     586,   228,   229,   230,   231,   232,   371,   373,   375,   376,
     133,   261,    86,   352,    88,  1073,   114,    91,   204,   403,
     536,   525,   168,   857,   249,    86,   456,   251,   398,   398,
     613,   114,    91,   906,   626,   539,   252,   907,   253,   908,
     815,   254,   522,   629,   568,   662,   663,   634,   190,   574,
      86,  1091,   918,   953,   920,   953,   315,   953,   158,   191,
     338,   338,   338,   338,   326,  1087,   528,   345,   704,   522,
     207,  1117,   212,   169,   159,  1036,   295,   798,   575,   295,
     295,   749,  1093,   213,   187,   570,   261,  1109,   744,   384,
     208,   577,   604,   644,   295,   612,  1120,   887,   526,   295,
     284,  1057,   295,   295,   406,   635,   579,   295,  1042,   394,
     699,   318,   427,   630,   871,  1041,   325,   627,   631,   871,
    1041,   569,   328,  1037,   192,   325,   637,   638,   639,   640,
     198,  1042,  1072,   581,   977,   855,  1042,   347,  1036,   720,
    1068,   939,  1007,   352,   799,   725,   528,   284,  1036,   940,
     703,   380,   868,   648,   913,   576,   305,   655,   776,   224,
     306,   770,  1058,   657,   200,   561,  1099,   867,   576,   678,
    1008,   233,  1090,   741,   261,   284,   193,   680,   694,   731,
     885,   607,   305,   580,   756,   307,   306,   935,   539,   753,
     398,    86,   758,   739,   194,  1099,  1118,   808,    86,   748,
     759,   225,   839,   588,   589,   239,   775,   591,   593,   840,
     596,   307,   722,   884,  1019,  1022,  1053,  1023,  1024,  1025,
     199,   730,   432,   608,  1026,  1027,   715,   309,   715,   715,
     649,   715,   433,   310,   479,   170,   171,   715,   195,   390,
     658,   715,   226,   172,   173,   174,   679,   390,    86,   827,
      88,   777,   636,   309,   681,   867,   732,   778,  1054,   310,
     201,   454,   779,   284,   609,   352,   352,   352,  1066,   454,
     352,   828,   654,   774,   210,   318,   781,   454,   802,   804,
     806,   829,   780,   454,   782,   783,   784,   967,   215,   457,
     458,   459,   460,   461,   462,   842,   830,   305,    86,  1055,
      98,   306,   831,  1085,   305,   211,  1086,   742,   306,   682,
     805,   683,   685,   688,   688,   688,   688,   214,   325,   482,
     531,   165,   352,   705,   562,   707,   307,   894,   454,   896,
    1111,   897,   166,   307,   454,   217,   167,   330,   832,   454,
     418,   746,   846,   847,   833,  1007,   848,   160,   161,   752,
     175,   320,   221,   454,   871,   803,   803,   803,   329,   220,
     916,   373,   736,   738,   138,   352,   114,   114,   309,   418,
     745,   419,   843,  1008,   310,   309,   398,   750,   420,   398,
     998,   310,   483,   114,   176,   484,   485,   486,   924,   958,
     960,   222,   875,   647,   487,   421,   651,   905,   488,   177,
     419,  1018,   223,   489,  1009,   574,   235,   420,   789,   422,
     490,   236,   491,   492,  1002,   493,   139,   463,   423,   843,
     843,   242,   140,   843,   421,   911,   464,   912,   769,   424,
      86,   574,   110,   432,   528,   141,   494,   917,   422,   899,
     142,   760,   790,   433,   790,   248,   495,   423,  1017,   143,
     496,   791,   144,   791,   325,   465,   145,   497,   424,   498,
     466,    86,   146,   128,   528,   925,   959,   959,   499,   135,
     500,   136,   761,  1095,   614,   328,   792,   325,  1078,   762,
     793,   794,   793,   794,   305,   795,   212,   795,   306,   319,
     982,  1003,   147,    86,  1067,   238,   763,   213,   970,   332,
     148,   529,   353,   945,   946,   947,   249,   250,   501,   251,
     764,   502,   981,   307,   354,    86,   212,   244,   252,   765,
     253,   369,   574,   254,  1110,   576,   790,   213,   561,   877,
     766,  -527,   541,   188,   189,   791,   255,   256,   308,  1061,
     882,   965,   257,   258,   407,   727,   390,    86,   790,   334,
     889,   890,   408,   891,   542,   309,   409,   791,   983,   410,
     411,   310,   543,   544,   793,   794,  1064,   259,   545,   795,
     602,   801,  1063,   412,  1104,   790,    86,   546,   374,   414,
     547,   728,   548,   729,   791,   413,   793,   794,    86,   790,
     592,   795,   549,   550,    86,   909,   684,   352,   791,   352,
     415,    86,   790,   737,   416,  1049,  1050,  1062,   790,   417,
     790,   791,   551,   793,   794,   429,   644,   791,   795,   791,
     339,   340,   341,   450,  1001,    91,   356,   793,   794,   954,
     552,   955,   795,   430,  1065,   431,  1105,   936,   436,   688,
     793,   794,  -305,   437,   439,   795,   793,   794,   793,   794,
     468,   795,   440,   795,   950,   553,   261,   443,   619,   444,
     621,   622,   554,   623,  -305,   262,   965,   357,   555,   556,
     358,   264,   790,   141,   476,   966,   445,   446,   142,   448,
     971,   791,   427,   114,   972,  1107,  1108,   143,   265,   469,
     144,   266,   821,   822,   145,   470,   471,   932,   267,   268,
     146,   106,   107,   108,   109,   269,   270,   689,   690,   691,
     793,   794,   474,   475,   513,   795,   271,   515,   479,   272,
     595,   273,   274,   598,   599,   275,   126,   276,   516,   277,
     517,   518,   278,   519,   527,   279,   280,   281,   611,   359,
     282,   520,   283,   616,   531,   284,   617,   618,   565,   539,
     540,   620,   571,   567,   584,   285,   286,   287,  -282,   541,
     566,   249,   250,    91,   251,   570,   576,   583,   587,   597,
     602,   427,   659,   252,   574,   253,   600,   660,   254,   624,
    1047,   542,   661,   692,   706,   664,   665,   666,   352,   543,
     544,   255,   256,   667,  -282,   545,  -282,   257,   258,   668,
     669,   670,  1039,  1048,   546,   671,   709,   547,   719,   548,
     733,   724,   716,   717,  1047,   718,   742,   754,   747,   549,
     550,   723,   259,   771,   755,   726,   772,   757,   773,   786,
      91,    91,    91,  1039,   797,   801,   800,  1048,   807,   551,
     809,   812,   813,   816,   818,   819,   820,   823,   824,  1047,
     850,   841,   851,  1082,   852,   528,  1047,   552,   858,   860,
     862,   864,   878,   883,    91,   892,   879,   898,    91,   829,
     900,   895,  1048,  1094,   901,   902,   903,   904,   914,  1048,
    1082,   356,   553,   915,   919,  1047,    91,   249,   250,   554,
     251,   921,   923,   926,   927,   555,   556,   929,   930,   252,
     933,   253,   949,   973,   254,   961,   974,   976,  1048,   984,
     967,   261,   978,   985,   979,   980,   986,   255,   256,   987,
     262,   989,   357,   257,   258,   358,   264,   990,   991,   995,
     992,   997,  1015,  1020,  1021,  -506,  1028,  1029,  1030,  1032,
    1076,  1008,  1077,   265,  1083,  1084,   266,  1079,   259,  1088,
    1089,  1096,   578,   267,   268,   751,   854,  1112,   849,   996,
     269,   270,   994,   948,  1116,   944,   514,   346,   478,   156,
     656,   271,   876,  1033,   272,   157,   273,   274,   385,   740,
     275,   910,   276,   219,   277,  1031,   934,   278,  1052,  1071,
     279,   280,   281,  1051,   359,   282,   713,   283,   538,   712,
     284,   866,   249,   250,   874,   251,   928,   356,   872,   641,
     285,   286,   287,   811,   252,  1074,   253,   524,  1075,   254,
     377,  1092,   993,   735,  1119,  1103,  1121,   564,   880,   873,
     585,   957,   255,   256,  1000,   615,   237,   261,   257,   258,
     104,   590,     0,     0,     0,     0,   262,     0,   357,     0,
       0,   358,   264,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   259,     0,     0,     0,     0,     0,   265,
       0,     0,   266,     0,     0,     0,     0,     0,     0,   267,
     268,     0,     0,     0,     0,     0,   269,   270,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   271,     0,     0,
     272,     0,   273,   274,     0,     0,   275,     0,   276,     0,
     277,     0,     0,   278,     0,     0,   279,   280,   281,     0,
       0,   282,     0,   283,     0,     0,   284,     0,   249,   250,
       0,   251,     0,     0,     0,     0,   285,   286,   287,     0,
     252,     0,   253,     0,     0,   254,     0,     0,     0,     0,
     260,     0,   261,     0,     0,     0,     0,     0,   255,   256,
       0,   262,     0,   263,   257,   258,     0,   264,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   265,     0,     0,   266,     0,   259,
       0,     0,     0,     0,   267,   268,     0,     0,     0,     0,
       0,   269,   270,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   271,     0,     0,   272,     0,   273,   274,     0,
       0,   275,     0,   276,     0,   277,     0,     0,   278,     0,
       0,   279,   280,   281,     0,     0,   282,     0,   283,     0,
       0,   284,     0,   249,   250,     0,   251,     0,     0,     0,
       0,   285,   286,   287,     0,   252,     0,   253,     0,     0,
     254,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   255,   256,     0,     0,     0,   261,   257,
     258,     0,     0,     0,     0,     0,     0,   262,     0,   263,
       0,     0,     0,   264,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   259,     0,     0,     0,     0,   387,
     265,     0,     0,   266,     0,     0,     0,     0,     0,     0,
     267,   268,     0,     0,     0,     0,     0,   269,   270,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   271,     0,
       0,   272,     0,   273,   274,     0,     0,   275,     0,   276,
       0,   277,     0,     0,   278,     0,     0,   279,   280,   281,
       0,     0,   282,     0,   283,     0,     0,   284,     0,   249,
     250,     0,   251,     0,     0,     0,     0,   285,   286,   287,
       0,   252,     0,   253,     0,     0,   254,     0,     0,     0,
       0,     0,     0,   261,     0,     0,     0,     0,     0,   255,
     256,     0,   262,     0,   263,   257,   258,     0,   264,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   427,
       0,     0,     0,     0,     0,   265,     0,     0,   266,     0,
     259,     0,     0,     0,     0,   267,   268,     0,     0,     0,
       0,     0,   269,   270,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   271,     0,     0,   272,     0,   273,   274,
       0,     0,   275,     0,   276,     0,   277,     0,     0,   278,
       0,     0,   279,   280,   281,     0,     0,   282,     0,   283,
       0,     0,   284,     0,   249,   250,     0,   251,     0,     0,
       0,     0,   285,   286,   287,     0,   252,     0,   253,     0,
       0,   254,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   255,   256,     0,   594,     0,   261,
     257,   258,     0,     0,     0,     0,     0,     0,   262,     0,
     263,     0,     0,     0,   264,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   259,     0,     0,     0,     0,
       0,   265,     0,     0,   266,     0,     0,     0,     0,     0,
       0,   267,   268,     0,     0,     0,     0,     0,   269,   270,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   271,
       0,     0,   272,     0,   273,   274,     0,     0,   275,     0,
     276,     0,   277,     0,     0,   278,     0,     0,   279,   280,
     281,     0,     0,   282,     0,   283,     0,     0,   284,     0,
     249,   250,     0,   251,     0,     0,     0,     0,   285,   286,
     287,     0,   252,     0,   253,     0,     0,   254,     0,     0,
       0,     0,     0,     0,   261,     0,     0,     0,     0,     0,
     255,   256,     0,   262,     0,   263,   257,   258,     0,   264,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   721,   265,     0,     0,   266,
       0,   259,     0,     0,     0,     0,   267,   268,     0,     0,
       0,     0,     0,   269,   270,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   271,     0,     0,   272,     0,   273,
     274,     0,     0,   275,     0,   276,     0,   277,     0,     0,
     278,     0,     0,   279,   280,   281,     0,     0,   282,     0,
     283,     0,     0,   284,     0,   249,   250,     0,   251,     0,
       0,     0,     0,   285,   286,   287,     0,   252,     0,   253,
       0,     0,   254,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   255,   256,     0,     0,     0,
     261,   257,   258,     0,     0,     0,     0,     0,     0,   262,
       0,   263,     0,     0,     0,   264,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   259,     0,     0,     0,
       0,   962,   265,     0,     0,   266,     0,     0,     0,     0,
       0,     0,   267,   268,     0,     0,     0,     0,     0,   269,
     270,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     271,     0,     0,   272,     0,   273,   274,     0,     0,   275,
       0,   276,     0,   277,     0,     0,   278,     0,     0,   279,
     280,   281,     0,     0,   282,     0,   283,     0,     0,   284,
       0,   249,   250,     0,   251,     0,     0,     0,     0,   285,
     286,   287,     0,   252,     0,   253,     0,     0,   254,     0,
       0,     0,     0,     0,     0,   261,     0,     0,     0,     0,
       0,   255,   256,     0,   262,     0,   263,   257,   258,     0,
     264,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   265,     0,     0,
     266,     0,   259,     0,     0,     0,     0,   267,   268,     0,
       0,     0,     0,     0,   269,   270,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   271,     0,     0,   272,     0,
     273,   274,     0,     0,   275,     0,   276,     0,   277,     0,
       0,   278,     0,     0,   279,   280,   281,     0,     0,   282,
       0,   283,     0,     0,   284,     0,   249,   250,     0,   251,
       0,     0,     0,     0,   285,   286,   287,     0,   252,     0,
     253,     0,     0,   254,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   255,   256,     0,     0,
       0,   603,   257,   258,     0,     0,     0,     0,     0,     0,
     262,     0,   263,     0,     0,     0,   264,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   259,     0,     0,
       0,     0,     0,   265,     0,     0,   266,     0,     0,     0,
       0,     0,     0,   267,   268,     0,     0,     0,     0,     0,
     269,   270,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   271,     0,     0,   272,     0,   273,   274,     0,     0,
     275,     0,   276,     0,   277,     0,     0,   278,     0,     0,
     279,   280,   281,     0,     0,   282,     0,   283,     0,     0,
     284,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     285,   286,   287,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   261,     0,     0,     0,
       0,     0,     0,     0,     0,   262,     0,   263,     0,     0,
       0,   264,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   265,     0,
       0,   266,     0,     0,     0,     0,     0,     0,   267,   268,
       0,     0,     0,     0,     0,   269,   270,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   271,     0,     0,   272,
       0,   273,   274,     0,     0,   275,     0,   276,     0,   277,
    -564,     1,   278,     0,     0,   279,   280,     0,     0,     0,
     282,     0,     0,     0,     0,   284,  -564,     0,     0,     0,
       0,     0,     0,     0,     0,   285,   286,   287,     0,     0,
       0,     2,     3,     0,     0,     0,     4,     0,     5,     0,
       0,     6,     7,     8,     9,    10,    11,    12,    13,     0,
       0,     0,     0,     0,     0,    14,    15,     0,     0,    16,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
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
     292,   232,     4,   768,   198,     4,   200,   329,     4,   320,
       6,     3,   271,   624,     6,   626,   275,   276,   675,    22,
     629,   893,    25,    15,     6,     4,     4,     9,    10,     4,
       3,     4,     3,     6,    16,     3,     4,     4,     6,     4,
       4,   228,   229,   230,   231,    27,     4,   151,    30,    31,
     107,    33,    34,     4,     4,     6,    38,    39,     3,    91,
      91,    43,   719,   189,   111,    47,    49,   724,     3,    51,
      15,   125,   100,   101,   102,   531,   263,    29,    30,   951,
     204,    37,    22,    66,    67,    25,     3,     4,     4,     6,
       6,   151,    22,   708,   859,    25,    89,   356,    15,   358,
      17,   225,   164,    20,   357,   160,   160,   204,   164,   175,
     164,   165,   166,   167,   967,   151,   281,   171,   283,   308,
     177,   175,   176,   177,   228,   242,   109,   155,   225,     4,
       4,     6,     6,   187,   191,   329,   190,   191,   192,   193,
     194,   195,   151,   125,   198,   199,   200,   201,   151,   196,
     403,    50,    51,    52,    53,    54,   210,   211,   212,   213,
     214,   153,     4,   217,     6,  1036,   220,   221,   200,   200,
     357,   151,   243,   228,     3,     4,   242,     6,   232,   233,
     433,   235,   236,   792,   246,   245,    15,   796,    17,   798,
     246,    20,   228,   164,   151,   487,   488,   196,   227,   386,
       4,  1072,   813,   860,   815,   862,   164,   864,     0,   238,
     192,   193,   194,   195,   164,  1068,   175,   199,   196,   228,
      97,   151,   227,   164,    16,   228,   413,   175,   151,   416,
     417,   196,   196,   238,   242,   228,   153,  1090,   240,   221,
     117,   151,   429,   469,   431,   432,  1118,   240,   228,   436,
     242,   136,   439,   440,   236,   254,   151,   444,   254,   238,
     243,   315,   179,   234,   719,   238,   320,   454,   239,   724,
     238,   228,   326,   240,   244,   329,   463,   464,   465,   466,
     164,   254,   198,   242,   895,   705,   254,   238,   228,   548,
     164,   243,   141,   347,   242,   554,   175,   242,   228,   251,
     526,   176,   959,   151,   805,   228,   110,   151,   215,   139,
     114,   603,   197,   151,   164,   369,  1083,   234,   228,   151,
     169,   220,   164,   571,   153,   242,   244,   151,   522,   151,
     750,   139,   110,   228,   151,   139,   114,   838,   245,   587,
     394,     4,   151,   569,   244,  1112,  1111,   658,     4,   580,
     151,   181,   679,   407,   408,   409,   151,   411,   412,   681,
     414,   139,   549,   242,   973,   976,   139,   978,   979,   980,
     231,   558,   207,   181,   983,   984,   541,   181,   543,   544,
     228,   546,   217,   187,   228,    57,    58,   552,   244,   576,
     228,   556,   222,    65,    66,    67,   228,   584,     4,    92,
       6,   151,   456,   181,   228,   234,   228,   151,   181,   187,
     164,   228,   151,   242,   222,   469,   470,   471,  1029,   228,
     474,   114,   476,   610,   242,   479,   151,   228,   151,   151,
     151,   124,   619,   228,   621,   622,   623,   208,   134,    68,
      69,    70,    71,    72,    73,   151,   139,   110,     4,   222,
       6,   114,   145,  1062,   110,   242,  1065,   228,   114,   513,
     649,   515,   516,   517,   518,   519,   520,   246,   522,    63,
     179,   227,   526,   527,   183,   529,   139,   769,   228,   771,
    1095,   773,   238,   139,   228,   164,   242,   681,   181,   228,
     140,   576,   151,   151,   187,   141,   151,   120,   121,   584,
     172,   164,   244,   228,   959,   228,   228,   228,   164,   208,
     151,   565,   566,   567,    94,   569,   570,   571,   181,   140,
     574,   171,   228,   169,   187,   181,   580,   581,   178,   583,
     950,   187,   126,   587,   206,   129,   130,   131,   151,   151,
     151,   228,   729,   471,   138,   195,   474,   151,   142,   221,
     171,   971,     3,   147,   200,   742,   246,   178,   160,   209,
     154,   244,   156,   157,   151,   159,   146,   196,   218,   228,
     228,     6,   152,   228,   195,   801,   205,   803,   228,   229,
       4,   768,     6,   207,   175,   165,   180,   228,   209,   776,
     170,   140,   196,   217,   196,     6,   190,   218,   151,   179,
     194,   205,   182,   205,   658,   234,   186,   201,   229,   203,
     239,     4,   192,     6,   175,   228,   228,   228,   212,     4,
     214,     6,   171,  1079,   248,   679,   228,   681,  1048,   178,
     234,   235,   234,   235,   110,   239,   227,   239,   114,     3,
     160,   228,   222,     4,   151,     6,   195,   238,   883,   228,
     230,   242,   240,   846,   847,   848,     3,     4,   252,     6,
     209,   255,   160,   139,     4,     4,   227,     6,    15,   218,
      17,   164,   859,    20,  1094,   228,   196,   238,   732,   733,
     229,   242,   113,    74,    75,   205,    33,    34,   164,   160,
     744,   878,    39,    40,   242,   112,   883,     4,   196,     6,
     754,   755,   242,   757,   135,   181,   228,   205,   228,    35,
     242,   187,   143,   144,   234,   235,   160,    64,   149,   239,
     151,   228,   160,   227,   160,   196,     4,   158,     6,   242,
     161,   148,   163,   150,   205,   164,   234,   235,     4,   196,
       6,   239,   173,   174,     4,   799,     6,   801,   205,   803,
       6,     4,   196,     6,   164,  1008,  1009,   228,   196,   164,
     196,   205,   193,   234,   235,   164,   992,   205,   239,   205,
     193,   194,   195,     3,   961,   829,   123,   234,   235,   862,
     211,   864,   239,   164,   228,   164,   160,   841,   164,   843,
     234,   235,   223,   164,   164,   239,   234,   235,   234,   235,
      80,   239,   164,   239,   858,   236,   153,   164,   443,   164,
     445,   446,   243,   448,   245,   162,  1003,   164,   249,   250,
     167,   168,   196,   165,    60,   879,   164,   164,   170,   164,
     884,   205,   179,   887,   887,  1088,  1089,   179,   185,   164,
     182,   188,   668,   669,   186,   164,   164,   829,   195,   196,
     192,    17,    18,    19,    20,   202,   203,   518,   519,   520,
     234,   235,   164,   164,   247,   239,   213,   242,   228,   216,
     413,   218,   219,   416,   417,   222,    42,   224,   227,   226,
     164,   164,   229,   164,   242,   232,   233,   234,   431,   236,
     237,   164,   239,   436,   179,   242,   439,   440,   246,   245,
     223,   444,   208,   227,   173,   252,   253,   254,   112,   113,
     242,     3,     4,   967,     6,   228,   228,   228,   246,    21,
     151,   179,   164,    15,  1111,    17,   246,   164,    20,   246,
    1007,   135,   164,   116,     3,   164,   164,   164,   992,   143,
     144,    33,    34,   164,   148,   149,   150,    39,    40,   164,
     164,   164,  1006,  1007,   158,   164,    88,   161,   164,   163,
     242,   164,   543,   544,  1041,   546,   228,   242,   173,   173,
     174,   552,    64,   228,   242,   556,   151,   242,   228,     3,
    1034,  1035,  1036,  1037,     3,   228,   151,  1041,   151,   193,
       3,     3,   246,     3,     3,     3,     3,     3,     3,  1076,
       3,   242,     3,  1057,     4,   175,  1083,   211,   242,   166,
     166,   166,   164,   164,  1068,   164,   242,   151,  1072,   124,
     151,   246,  1076,  1077,   151,   151,   151,   151,   151,  1083,
    1084,   123,   236,   151,     3,  1112,  1090,     3,     4,   243,
       6,   228,   151,   151,   151,   249,   250,   151,   151,    15,
     164,    17,     3,   175,    20,   223,     3,   246,  1112,   175,
     208,   153,   246,     3,   246,   246,   151,    33,    34,     3,
     162,   151,   164,    39,    40,   167,   168,     3,   151,     3,
     164,   160,   199,   151,   151,   151,   151,   246,   151,   151,
     228,   169,   242,   185,   241,   136,   188,   179,    64,   244,
     244,   116,   394,   195,   196,   583,   701,   228,   693,   942,
     202,   203,   939,   849,  1103,   843,   332,   200,   315,    52,
     479,   213,   732,  1003,   216,    52,   218,   219,   222,   570,
     222,   800,   224,   144,   226,   992,   836,   229,  1014,  1035,
     232,   233,   234,  1011,   236,   237,   540,   239,   359,   539,
     242,   718,     3,     4,   726,     6,   822,   123,   723,   468,
     252,   253,   254,   660,    15,  1037,    17,   347,  1041,    20,
     214,  1076,   933,   565,  1112,  1084,  1120,   370,   742,   724,
     402,   867,    33,    34,   959,   434,   159,   153,    39,    40,
      15,   409,    -1,    -1,    -1,    -1,   162,    -1,   164,    -1,
      -1,   167,   168,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    64,    -1,    -1,    -1,    -1,    -1,   185,
      -1,    -1,   188,    -1,    -1,    -1,    -1,    -1,    -1,   195,
     196,    -1,    -1,    -1,    -1,    -1,   202,   203,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   213,    -1,    -1,
     216,    -1,   218,   219,    -1,    -1,   222,    -1,   224,    -1,
     226,    -1,    -1,   229,    -1,    -1,   232,   233,   234,    -1,
      -1,   237,    -1,   239,    -1,    -1,   242,    -1,     3,     4,
      -1,     6,    -1,    -1,    -1,    -1,   252,   253,   254,    -1,
      15,    -1,    17,    -1,    -1,    20,    -1,    -1,    -1,    -1,
     151,    -1,   153,    -1,    -1,    -1,    -1,    -1,    33,    34,
      -1,   162,    -1,   164,    39,    40,    -1,   168,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   185,    -1,    -1,   188,    -1,    64,
      -1,    -1,    -1,    -1,   195,   196,    -1,    -1,    -1,    -1,
      -1,   202,   203,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   213,    -1,    -1,   216,    -1,   218,   219,    -1,
      -1,   222,    -1,   224,    -1,   226,    -1,    -1,   229,    -1,
      -1,   232,   233,   234,    -1,    -1,   237,    -1,   239,    -1,
      -1,   242,    -1,     3,     4,    -1,     6,    -1,    -1,    -1,
      -1,   252,   253,   254,    -1,    15,    -1,    17,    -1,    -1,
      20,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    33,    34,    -1,    -1,    -1,   153,    39,
      40,    -1,    -1,    -1,    -1,    -1,    -1,   162,    -1,   164,
      -1,    -1,    -1,   168,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    64,    -1,    -1,    -1,    -1,   184,
     185,    -1,    -1,   188,    -1,    -1,    -1,    -1,    -1,    -1,
     195,   196,    -1,    -1,    -1,    -1,    -1,   202,   203,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   213,    -1,
      -1,   216,    -1,   218,   219,    -1,    -1,   222,    -1,   224,
      -1,   226,    -1,    -1,   229,    -1,    -1,   232,   233,   234,
      -1,    -1,   237,    -1,   239,    -1,    -1,   242,    -1,     3,
       4,    -1,     6,    -1,    -1,    -1,    -1,   252,   253,   254,
      -1,    15,    -1,    17,    -1,    -1,    20,    -1,    -1,    -1,
      -1,    -1,    -1,   153,    -1,    -1,    -1,    -1,    -1,    33,
      34,    -1,   162,    -1,   164,    39,    40,    -1,   168,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   179,
      -1,    -1,    -1,    -1,    -1,   185,    -1,    -1,   188,    -1,
      64,    -1,    -1,    -1,    -1,   195,   196,    -1,    -1,    -1,
      -1,    -1,   202,   203,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   213,    -1,    -1,   216,    -1,   218,   219,
      -1,    -1,   222,    -1,   224,    -1,   226,    -1,    -1,   229,
      -1,    -1,   232,   233,   234,    -1,    -1,   237,    -1,   239,
      -1,    -1,   242,    -1,     3,     4,    -1,     6,    -1,    -1,
      -1,    -1,   252,   253,   254,    -1,    15,    -1,    17,    -1,
      -1,    20,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    33,    34,    -1,   151,    -1,   153,
      39,    40,    -1,    -1,    -1,    -1,    -1,    -1,   162,    -1,
     164,    -1,    -1,    -1,   168,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    64,    -1,    -1,    -1,    -1,
      -1,   185,    -1,    -1,   188,    -1,    -1,    -1,    -1,    -1,
      -1,   195,   196,    -1,    -1,    -1,    -1,    -1,   202,   203,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   213,
      -1,    -1,   216,    -1,   218,   219,    -1,    -1,   222,    -1,
     224,    -1,   226,    -1,    -1,   229,    -1,    -1,   232,   233,
     234,    -1,    -1,   237,    -1,   239,    -1,    -1,   242,    -1,
       3,     4,    -1,     6,    -1,    -1,    -1,    -1,   252,   253,
     254,    -1,    15,    -1,    17,    -1,    -1,    20,    -1,    -1,
      -1,    -1,    -1,    -1,   153,    -1,    -1,    -1,    -1,    -1,
      33,    34,    -1,   162,    -1,   164,    39,    40,    -1,   168,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   184,   185,    -1,    -1,   188,
      -1,    64,    -1,    -1,    -1,    -1,   195,   196,    -1,    -1,
      -1,    -1,    -1,   202,   203,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   213,    -1,    -1,   216,    -1,   218,
     219,    -1,    -1,   222,    -1,   224,    -1,   226,    -1,    -1,
     229,    -1,    -1,   232,   233,   234,    -1,    -1,   237,    -1,
     239,    -1,    -1,   242,    -1,     3,     4,    -1,     6,    -1,
      -1,    -1,    -1,   252,   253,   254,    -1,    15,    -1,    17,
      -1,    -1,    20,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    33,    34,    -1,    -1,    -1,
     153,    39,    40,    -1,    -1,    -1,    -1,    -1,    -1,   162,
      -1,   164,    -1,    -1,    -1,   168,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    64,    -1,    -1,    -1,
      -1,   184,   185,    -1,    -1,   188,    -1,    -1,    -1,    -1,
      -1,    -1,   195,   196,    -1,    -1,    -1,    -1,    -1,   202,
     203,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     213,    -1,    -1,   216,    -1,   218,   219,    -1,    -1,   222,
      -1,   224,    -1,   226,    -1,    -1,   229,    -1,    -1,   232,
     233,   234,    -1,    -1,   237,    -1,   239,    -1,    -1,   242,
      -1,     3,     4,    -1,     6,    -1,    -1,    -1,    -1,   252,
     253,   254,    -1,    15,    -1,    17,    -1,    -1,    20,    -1,
      -1,    -1,    -1,    -1,    -1,   153,    -1,    -1,    -1,    -1,
      -1,    33,    34,    -1,   162,    -1,   164,    39,    40,    -1,
     168,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   185,    -1,    -1,
     188,    -1,    64,    -1,    -1,    -1,    -1,   195,   196,    -1,
      -1,    -1,    -1,    -1,   202,   203,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   213,    -1,    -1,   216,    -1,
     218,   219,    -1,    -1,   222,    -1,   224,    -1,   226,    -1,
      -1,   229,    -1,    -1,   232,   233,   234,    -1,    -1,   237,
      -1,   239,    -1,    -1,   242,    -1,     3,     4,    -1,     6,
      -1,    -1,    -1,    -1,   252,   253,   254,    -1,    15,    -1,
      17,    -1,    -1,    20,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    33,    34,    -1,    -1,
      -1,   153,    39,    40,    -1,    -1,    -1,    -1,    -1,    -1,
     162,    -1,   164,    -1,    -1,    -1,   168,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    64,    -1,    -1,
      -1,    -1,    -1,   185,    -1,    -1,   188,    -1,    -1,    -1,
      -1,    -1,    -1,   195,   196,    -1,    -1,    -1,    -1,    -1,
     202,   203,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   213,    -1,    -1,   216,    -1,   218,   219,    -1,    -1,
     222,    -1,   224,    -1,   226,    -1,    -1,   229,    -1,    -1,
     232,   233,   234,    -1,    -1,   237,    -1,   239,    -1,    -1,
     242,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     252,   253,   254,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   153,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   162,    -1,   164,    -1,    -1,
      -1,   168,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   185,    -1,
      -1,   188,    -1,    -1,    -1,    -1,    -1,    -1,   195,   196,
      -1,    -1,    -1,    -1,    -1,   202,   203,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   213,    -1,    -1,   216,
      -1,   218,   219,    -1,    -1,   222,    -1,   224,    -1,   226,
       0,     1,   229,    -1,    -1,   232,   233,    -1,    -1,    -1,
     237,    -1,    -1,    -1,    -1,   242,    16,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   252,   253,   254,    -1,    -1,
      -1,    31,    32,    -1,    -1,    -1,    36,    -1,    38,    -1,
      -1,    41,    42,    43,    44,    45,    46,    47,    48,    -1,
      -1,    -1,    -1,    -1,    -1,    55,    56,    -1,    -1,    59,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    76,    77,    78,    79,
      -1,    81,    82,    83,    84,    85,    86,    87,    -1,    -1,
      90,    -1,    -1,    93,    -1,    95,    96,    -1,    98,    99,
      -1,    -1,    -1,   103,   104,   105,   106,   107,   108,    -1,
      -1,   111,    -1,    -1,    -1,    -1,    -1,    -1,   118,   119,
      -1,    -1,   122,    -1,    -1,   125,    -1,   127,   128,    -1,
      -1,    -1,    -1,   133,    -1,    -1,    -1,   137,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   177,    -1,   179,
      -1,    -1,   182,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   191
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
{
       0,     1,    31,    32,    36,    38,    41,    42,    43,    44,
      45,    46,    47,    48,    55,    56,    59,    76,    77,    78,
      79,    81,    82,    83,    84,    85,    86,    87,    90,    93,
      95,    96,    98,    99,   103,   104,   105,   106,   107,   108,
     111,   118,   119,   122,   125,   127,   128,   133,   137,   177,
     179,   182,   191,   259,   270,   271,   272,   273,   282,   289,
     309,   310,   319,   320,   321,   323,   324,   325,   326,   327,
     337,   357,   361,   407,   408,   409,   412,   413,   431,   465,
     466,   467,   468,   470,   474,   476,     4,   459,     6,   456,
     457,   459,   459,   459,   456,   456,   459,   459,     6,   458,
     459,   459,   464,   469,   469,   456,   458,   458,   458,   458,
       6,   358,   359,   396,   459,   459,   456,     3,   484,   456,
     456,   456,   456,   456,   456,   311,   458,   456,     6,   454,
     455,   459,   410,   459,   456,     4,     6,   462,    94,   146,
     152,   165,   170,   179,   182,   186,   192,   222,   230,   328,
     330,   331,   332,   189,   440,   456,   328,   330,     0,    16,
     120,   121,   471,    37,   242,   227,   238,   242,   243,   164,
      57,    58,    65,    66,    67,   172,   206,   221,   290,   291,
     292,   295,   298,   301,   302,   303,   306,   242,    74,    75,
     227,   238,   244,   244,   244,   244,   360,   361,   164,   231,
     164,   164,   338,    91,   200,   261,   456,    97,   117,   414,
     242,   242,   227,   238,   246,   134,   322,   164,   333,   333,
     208,   244,   228,     3,   139,   181,   222,   441,    50,    51,
      52,    53,    54,   220,   262,   246,   244,   467,     6,   459,
     472,   473,     6,   459,     6,   459,   459,   459,     6,     3,
       4,     6,    15,    17,    20,    33,    34,    39,    40,    64,
     151,   153,   162,   164,   168,   185,   188,   195,   196,   202,
     203,   213,   216,   218,   219,   222,   224,   226,   229,   232,
     233,   234,   237,   239,   242,   252,   253,   254,   403,   415,
     416,   417,   418,   419,   439,   444,   445,   448,   459,   461,
     475,   477,   481,   482,   483,   110,   114,   139,   164,   181,
     187,   341,   342,   347,   349,   164,   307,   308,   459,     3,
     164,   288,   300,   349,   351,   459,   164,   297,   459,   164,
     288,   293,   228,   459,     6,   459,   459,   281,   456,   281,
     281,   281,   361,   287,   288,   456,   287,   238,   339,   398,
     401,   454,   459,   240,     4,   460,   123,   164,   167,   236,
     371,   372,   373,   374,   375,   382,   384,   444,   451,   164,
     314,   459,   411,   459,     6,   459,   459,   410,   334,   398,
     176,   335,   336,   396,   456,   332,   432,   184,   268,   269,
     444,   268,   268,   268,   238,   264,   265,   267,   459,   263,
     264,   266,    91,   200,   260,   335,   456,   242,   242,   228,
      35,   242,   227,   164,   242,     6,   164,   164,   140,   171,
     178,   195,   209,   218,   229,   404,   405,   179,   444,   164,
     164,   164,   207,   217,   446,   447,   164,   164,   439,   164,
     164,   439,   439,   164,   164,   164,   164,   482,   164,   482,
       3,   405,   405,   151,   228,   175,   242,    68,    69,    70,
      71,    72,    73,   196,   205,   234,   239,   450,    80,   164,
     164,   164,   304,   349,   164,   164,    60,   305,   307,   228,
     299,   300,    63,   126,   129,   130,   131,   138,   142,   147,
     154,   156,   157,   159,   180,   190,   194,   201,   203,   212,
     214,   252,   255,   387,   388,   389,   390,   392,   430,   296,
     297,   293,   294,   247,   291,   242,   227,   164,   164,   164,
     164,   151,   228,   151,   401,   151,   228,   242,   175,   242,
     397,   179,   429,   438,   439,   371,   444,   439,   374,   245,
     223,   113,   135,   143,   144,   149,   158,   161,   163,   173,
     174,   193,   211,   236,   243,   249,   250,   381,   383,   315,
     316,   459,   183,   312,   438,   246,   242,   227,   151,   228,
     228,   208,   442,   443,   444,   151,   228,   151,   265,   151,
     228,   242,   397,   228,   173,   460,   371,   246,   459,   459,
     473,   459,     6,   459,   151,   448,   459,    21,   448,   448,
     246,   440,   151,   153,   444,   449,   475,   139,   181,   222,
     385,   448,   444,   371,   248,   447,   448,   448,   448,   385,
     448,   385,   385,   385,   246,   164,   246,   444,     3,   164,
     234,   239,   478,   480,   196,   254,   459,   444,   444,   444,
     444,   387,   344,   346,   398,   348,   398,   348,   151,   228,
     305,   348,   371,   428,   459,   151,   308,   151,   228,   164,
     164,   164,   405,   405,   164,   164,   164,   164,   164,   164,
     164,   164,   100,   101,   102,   155,   350,   352,   151,   228,
     151,   228,   459,   459,     6,   459,   285,   286,   459,   285,
     285,   285,   116,   283,   288,    49,    66,    67,   109,   243,
     274,   275,   276,   398,   196,   459,     3,   459,   440,    88,
     340,   151,   372,   373,   379,   482,   379,   379,   379,   164,
     439,   184,   444,   379,   164,   439,   379,   112,   148,   150,
     444,   151,   228,   242,   313,   411,   459,     6,   459,   398,
     336,   335,   228,   433,   240,   459,   269,   173,   264,   196,
     459,   266,   269,   335,   242,   242,   151,   242,   151,   151,
     140,   171,   178,   195,   209,   218,   229,   406,   441,   228,
     405,   228,   151,   228,   444,   151,   215,   151,   151,   151,
     444,   151,   444,   444,   444,   406,     3,   406,   478,   160,
     196,   205,   228,   234,   235,   239,   479,     3,   175,   242,
     151,   228,   151,   228,   151,   349,   151,   151,   300,     3,
     393,   393,     3,   246,   164,   246,     3,   394,     3,     3,
       3,   394,   394,     3,     3,     6,   403,    92,   114,   124,
     139,   145,   181,   187,   343,   353,   354,   355,   356,   297,
     293,   242,   151,   228,   204,   225,   151,   151,   151,   274,
       3,     3,     4,   277,   276,   397,   160,   228,   242,   441,
     166,   376,   166,   378,   166,   377,   376,   234,   403,   452,
     453,   475,   378,   452,   377,   444,   316,   459,   164,   242,
     443,   463,   459,   164,   242,   397,    89,   240,   329,   459,
     459,   459,   164,   442,   405,   246,   405,   405,   151,   444,
     151,   151,   151,   151,   151,   151,   478,   478,   478,   459,
     343,   398,   398,   305,   151,   151,   151,   228,   406,     3,
     406,   228,   391,   151,   151,   228,   151,   151,   391,   151,
     151,   345,   456,   164,   355,   305,   459,    29,    30,   243,
     251,   278,   279,   280,   286,   278,   278,   278,   283,     3,
     459,   442,   380,   403,   380,   380,     3,   461,   151,   228,
     151,   223,   184,   317,   318,   444,   459,   208,   364,   368,
     268,   459,   396,   175,     3,   368,   246,   406,   246,   246,
     246,   160,   160,   228,   175,     3,   151,     3,   395,   151,
       3,   151,   164,   428,   277,     3,   280,   160,   397,   368,
     453,   444,   151,   228,   365,   367,   456,   141,   169,   200,
     362,   363,   369,   370,   425,   199,   435,   151,   397,   478,
     151,   151,   406,   406,   406,   406,   478,   478,   151,   246,
     151,   346,   151,   318,    22,    25,   228,   240,   402,   459,
       3,   238,   254,   399,   400,   426,   427,   454,   459,   371,
     371,   370,   362,   139,   181,   222,   386,   136,   197,   420,
     436,   160,   228,   160,   160,   228,   406,   151,   164,   365,
     366,   366,   198,   367,   402,   400,   228,   242,   397,   179,
     434,   437,   459,   241,   136,   478,   478,   365,   244,   244,
     164,   367,   427,   196,   459,   440,   116,   284,     3,   399,
     421,   422,   423,   437,   160,   160,   151,   371,   371,   365,
     397,   441,   228,   204,   225,   424,   284,   151,   442,   422,
     368,   435
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
#line 407 "sql.yacc"
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
#line 433 "sql.yacc"
    {
		(yyval.ptr)=0;
	}
    break;

  case 4:

/* Line 1455 of yacc.c  */
#line 436 "sql.yacc"
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
#line 453 "sql.yacc"
    {
		(yyval.ptr)=A4GL_new_select_list_item_expr((yyvsp[(2) - (2)].s_select_list_item));
	}
    break;

  case 6:

/* Line 1455 of yacc.c  */
#line 458 "sql.yacc"
    {
		(yyval.ptr)=0;
	}
    break;

  case 7:

/* Line 1455 of yacc.c  */
#line 461 "sql.yacc"
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
#line 478 "sql.yacc"
    {
		 (yyval.ptr)=A4GL_new_select_list_item_expr((yyvsp[(2) - (2)].s_select_list_item));
	}
    break;

  case 9:

/* Line 1455 of yacc.c  */
#line 484 "sql.yacc"
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
#line 493 "sql.yacc"
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
#line 502 "sql.yacc"
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
#line 511 "sql.yacc"
    {
		(yyval.update_cmd)=(yyvsp[(2) - (2)].update_cmd);
		add_feature("UPDATE_COLUMN_EQ_VALUE_LIST");
    }
    break;

  case 13:

/* Line 1455 of yacc.c  */
#line 518 "sql.yacc"
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
#line 533 "sql.yacc"
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
#line 588 "sql.yacc"
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
#line 595 "sql.yacc"
    {
		(yyval.update_cmd)=(yyvsp[(1) - (3)].update_cmd);
		add_str_list((yyval.update_cmd)->column_list, (yyvsp[(3) - (3)].upd_pair)->column_name);
		local_add_select_list_item_list((yyval.update_cmd)->value_list, (yyvsp[(3) - (3)].upd_pair)->value);
	}
    break;

  case 17:

/* Line 1455 of yacc.c  */
#line 606 "sql.yacc"
    {
                strcpy((yyval.str),(yyvsp[(1) - (1)].str));
        }
    break;

  case 18:

/* Line 1455 of yacc.c  */
#line 609 "sql.yacc"
    {
                strcpy((yyval.str),(yyvsp[(2) - (2)].str));
        }
    break;

  case 19:

/* Line 1455 of yacc.c  */
#line 614 "sql.yacc"
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
#line 621 "sql.yacc"
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
#line 638 "sql.yacc"
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
#line 655 "sql.yacc"
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
#line 676 "sql.yacc"
    {
		(yyval.upd_pair)=malloc(sizeof(struct s_update_pair));
		(yyval.upd_pair)->column_name=acl_strdup((yyvsp[(1) - (3)].str));
		(yyval.upd_pair)->value=(yyvsp[(3) - (3)].s_select_list_item);
	}
    break;

  case 24:

/* Line 1455 of yacc.c  */
#line 685 "sql.yacc"
    {
			(yyval.str_list)=new_str_list((yyvsp[(1) - (1)].str));
		}
    break;

  case 25:

/* Line 1455 of yacc.c  */
#line 688 "sql.yacc"
    {
			(yyval.str_list)=add_str_list((yyvsp[(1) - (3)].str_list), (yyvsp[(3) - (3)].str));
		}
    break;

  case 26:

/* Line 1455 of yacc.c  */
#line 696 "sql.yacc"
    { 
		(yyval.s_select_list_item_list)=local_new_select_list_item_list((yyvsp[(1) - (1)].s_select_list_item));
	}
    break;

  case 27:

/* Line 1455 of yacc.c  */
#line 699 "sql.yacc"
    { 
		(yyval.s_select_list_item_list)=local_add_select_list_item_list((yyvsp[(1) - (3)].s_select_list_item_list),(yyvsp[(3) - (3)].s_select_list_item));
	}
    break;

  case 28:

/* Line 1455 of yacc.c  */
#line 707 "sql.yacc"
    {(yyval.s_select_list_item)=(yyvsp[(1) - (1)].s_select_list_item);}
    break;

  case 29:

/* Line 1455 of yacc.c  */
#line 708 "sql.yacc"
    {(yyval.s_select_list_item)=new_select_list_item_builtin_const(E_SLI_BUILTIN_CONST_NULL); }
    break;

  case 30:

/* Line 1455 of yacc.c  */
#line 715 "sql.yacc"
    { (yyval.sql_string)=make_sql_string_and_free(acl_strdup((yyvsp[(1) - (1)].str)), NULL);}
    break;

  case 31:

/* Line 1455 of yacc.c  */
#line 718 "sql.yacc"
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
#line 726 "sql.yacc"
    {SPRINTF2((yyval.str),"%s %s ",(yyvsp[(1) - (2)].str),(yyvsp[(2) - (2)].str));
			add_feature("DROP_VIEW");
}
    break;

  case 33:

/* Line 1455 of yacc.c  */
#line 729 "sql.yacc"
    {SPRINTF2((yyval.str),"%s %s",(yyvsp[(1) - (2)].str),(yyvsp[(2) - (2)].str));
		if (strchr((yyvsp[(2) - (2)].str),'@') || strchr((yyvsp[(2) - (2)].str),':')) add_feature("DROP_INDEX_QUALIFIED_PATH");
			add_feature("DROP_INDEX");
}
    break;

  case 34:

/* Line 1455 of yacc.c  */
#line 733 "sql.yacc"
    {SPRINTF2((yyval.str),"%s %s",(yyvsp[(1) - (2)].str),(yyvsp[(2) - (2)].str));
			add_feature("DROP_TRIGGER");
}
    break;

  case 35:

/* Line 1455 of yacc.c  */
#line 739 "sql.yacc"
    {(yyval.sql_string)=acl_strdup((yyvsp[(1) - (1)].str));}
    break;

  case 36:

/* Line 1455 of yacc.c  */
#line 740 "sql.yacc"
    {(yyval.sql_string)=(yyvsp[(1) - (1)].sql_string);}
    break;

  case 37:

/* Line 1455 of yacc.c  */
#line 744 "sql.yacc"
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
#line 754 "sql.yacc"
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
#line 768 "sql.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 40:

/* Line 1455 of yacc.c  */
#line 769 "sql.yacc"
    {strcpy((yyval.str),(yyvsp[(1) - (1)].str));}
    break;

  case 42:

/* Line 1455 of yacc.c  */
#line 774 "sql.yacc"
    {SPRINTF2((yyval.str),"%s%s",(yyvsp[(1) - (2)].str),(yyvsp[(2) - (2)].str)); }
    break;

  case 43:

/* Line 1455 of yacc.c  */
#line 779 "sql.yacc"
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
#line 787 "sql.yacc"
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
#line 795 "sql.yacc"
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
#line 803 "sql.yacc"
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
#line 811 "sql.yacc"
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
#line 823 "sql.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 50:

/* Line 1455 of yacc.c  */
#line 823 "sql.yacc"
    {strcpy((yyval.str),(yyvsp[(1) - (1)].str));}
    break;

  case 52:

/* Line 1455 of yacc.c  */
#line 827 "sql.yacc"
    {SPRINTF2((yyval.str),"%s%s",(yyvsp[(1) - (2)].str),(yyvsp[(2) - (2)].str));}
    break;

  case 53:

/* Line 1455 of yacc.c  */
#line 831 "sql.yacc"
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
#line 838 "sql.yacc"
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
#line 845 "sql.yacc"
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
#line 852 "sql.yacc"
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
#line 861 "sql.yacc"
    { strcpy(last_tmp_name,(yyvsp[(1) - (1)].str)); }
    break;

  case 58:

/* Line 1455 of yacc.c  */
#line 865 "sql.yacc"
    {SPRINTF7((yyval.str),"CREATE UNIQUE INDEX %s %s %s %s %s %s %s",(yyvsp[(2) - (8)].str),(yyvsp[(3) - (8)].str),(yyvsp[(4) - (8)].str),(yyvsp[(5) - (8)].str),(yyvsp[(6) - (8)].str),(yyvsp[(7) - (8)].str),(yyvsp[(8) - (8)].str));
		add_feature("CREATE_INDEX");
		add_feature("CREATE_INDEX_UNIQUE");
		if (strchr((yyvsp[(2) - (8)].str),'@') || strchr((yyvsp[(2) - (8)].str),':')) add_feature("CREATE_INDEX_QUALIFIED_PATH");
		if (strchr((yyvsp[(6) - (8)].str),',')) { add_feature("CREATE_INDEX_COMPOSITE"); }
	
}
    break;

  case 59:

/* Line 1455 of yacc.c  */
#line 872 "sql.yacc"
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
#line 884 "sql.yacc"
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
#line 895 "sql.yacc"
    {
		if (strchr((yyvsp[(2) - (8)].str),'@') || strchr((yyvsp[(2) - (8)].str),':')) add_feature("CREATE_INDEX_QUALIFIED_PATH");
		if (strchr((yyvsp[(6) - (8)].str),',')) { add_feature("CREATE_INDEX_COMPOSITE"); }
			add_feature("CREATE_INDEX");
			SPRINTF7((yyval.str)," CREATE INDEX %s %s %s %s %s %s %s",(yyvsp[(2) - (8)].str),(yyvsp[(3) - (8)].str),(yyvsp[(4) - (8)].str),(yyvsp[(5) - (8)].str),(yyvsp[(6) - (8)].str),(yyvsp[(7) - (8)].str),(yyvsp[(8) - (8)].str));
	}
    break;

  case 62:

/* Line 1455 of yacc.c  */
#line 901 "sql.yacc"
    {
		add_feature("CREATE_DATABASE");
		a4gl_yyerror("You cannot create a database from within Aubit4gl - if the target database allows - prepare and execute it manually");
	}
    break;

  case 63:

/* Line 1455 of yacc.c  */
#line 905 "sql.yacc"
    {
		add_feature("DROP_DATABASE");
		a4gl_yyerror("You cannot drop a database from within Aubit4gl - if the target database allows - prepare and execute it manually");
	}
    break;

  case 64:

/* Line 1455 of yacc.c  */
#line 909 "sql.yacc"
    { 
		if (strchr((yyvsp[(2) - (4)].str),'@') || strchr((yyvsp[(2) - (4)].str),':')) add_feature("CREATE_SYNONYM_QUALIFIED_PATH");
			add_feature("CREATE_SYNONYM");
			SPRINTF3((yyval.str),"%s %s FOR %s",(yyvsp[(1) - (4)].str),(yyvsp[(2) - (4)].str),(yyvsp[(4) - (4)].str)); 
	}
    break;

  case 65:

/* Line 1455 of yacc.c  */
#line 914 "sql.yacc"
    { 
		add_feature("CREATE_AUDIT");
		SPRINTF2((yyval.str),"CREATE AUDIT FOR %s IN '%s'",(yyvsp[(2) - (4)].str),A4GL_strip_quotes((yyvsp[(4) - (4)].str))); 
	}
    break;

  case 66:

/* Line 1455 of yacc.c  */
#line 918 "sql.yacc"
    { 
		add_feature("DROP_AUDIT");
		SPRINTF1((yyval.str),"DROP AUDIT FOR %s",(yyvsp[(2) - (2)].str)); }
    break;

  case 67:

/* Line 1455 of yacc.c  */
#line 921 "sql.yacc"
    { 
		if (strchr((yyvsp[(2) - (2)].str),'@') || strchr((yyvsp[(2) - (2)].str),':')) add_feature("DROP_SYNONYM_QUALIFIED_PATH");
		add_feature("DROP_SYNONYM");
		SPRINTF2((yyval.str),"%s %s",(yyvsp[(1) - (2)].str),(yyvsp[(2) - (2)].str)); }
    break;

  case 68:

/* Line 1455 of yacc.c  */
#line 925 "sql.yacc"
    { 
		add_feature("RECOVER_TABLE");
		SPRINTF1((yyval.str),"RECOVER TABLE %s",(yyvsp[(2) - (2)].str)); }
    break;

  case 69:

/* Line 1455 of yacc.c  */
#line 928 "sql.yacc"
    { 
		add_feature("ROLLFORWARD_DATABASE");
		SPRINTF1((yyval.str),"ROLLFORWARD DATABASE %s",(yyvsp[(2) - (2)].str)); }
    break;

  case 70:

/* Line 1455 of yacc.c  */
#line 935 "sql.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 71:

/* Line 1455 of yacc.c  */
#line 936 "sql.yacc"
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
#line 946 "sql.yacc"
    {(yyval.integer_val)=0;}
    break;

  case 73:

/* Line 1455 of yacc.c  */
#line 947 "sql.yacc"
    { (yyval.integer_val)=1;}
    break;

  case 75:

/* Line 1455 of yacc.c  */
#line 952 "sql.yacc"
    {SPRINTF2((yyval.str),"%s,%s",(yyvsp[(1) - (3)].str),(yyvsp[(3) - (3)].str));}
    break;

  case 76:

/* Line 1455 of yacc.c  */
#line 956 "sql.yacc"
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
#line 965 "sql.yacc"
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
#line 974 "sql.yacc"
    {
		strcpy((yyval.str),A4GL_confirm_colname(last_tmp_name,(yyvsp[(1) - (1)].str)));
}
    break;

  case 79:

/* Line 1455 of yacc.c  */
#line 981 "sql.yacc"
    {
		(yyval.sql_string)=(yyvsp[(1) - (1)].sql_string);
	}
    break;

  case 80:

/* Line 1455 of yacc.c  */
#line 984 "sql.yacc"
    {
		(yyval.sql_string)=make_sql_string_and_free((yyvsp[(1) - (3)].sql_string),kw_comma,strdup("\n"),(yyvsp[(3) - (3)].sql_string),NULL);
	}
    break;

  case 81:

/* Line 1455 of yacc.c  */
#line 990 "sql.yacc"
    {
		(yyval.sql_string)=make_sql_string_and_free(strdup("   "),(yyvsp[(1) - (1)].sql_string),NULL);
	}
    break;

  case 82:

/* Line 1455 of yacc.c  */
#line 993 "sql.yacc"
    {
		(yyval.sql_string)=make_sql_string_and_free(strdup("   "),(yyvsp[(1) - (1)].sql_string),NULL);
	}
    break;

  case 83:

/* Line 1455 of yacc.c  */
#line 1004 "sql.yacc"
    {
		add_feature("ALTER_TABLE");
	(yyval.sql_string)=make_sql_string_and_free(acl_strdup((yyvsp[(1) - (3)].str)),kw_space,acl_strdup((yyvsp[(2) - (3)].str)),kw_space,(yyvsp[(3) - (3)].sql_string),NULL);
	}
    break;

  case 84:

/* Line 1455 of yacc.c  */
#line 1008 "sql.yacc"
    {
		add_feature("CLUSTER_INDEX");
		add_feature("ALTER_INDEX_CLUSTER");
		(yyval.sql_string)=make_sql_string_and_free(acl_strdup("ALTER INDEX "),acl_strdup((yyvsp[(2) - (3)].str)),acl_strdup(" TO CLUSTER"),NULL);
		}
    break;

  case 85:

/* Line 1455 of yacc.c  */
#line 1013 "sql.yacc"
    {
		add_feature("ALTER_INDEX_NOT_CLUSTER");
		(yyval.sql_string)=make_sql_string_and_free(acl_strdup("ALTER INDEX "),acl_strdup((yyvsp[(2) - (3)].str)),acl_strdup(" TO NOT CLUSTER"),NULL);
		}
    break;

  case 86:

/* Line 1455 of yacc.c  */
#line 1020 "sql.yacc"
    {
		(yyval.sql_string)=(yyvsp[(1) - (1)].sql_string);
	}
    break;

  case 87:

/* Line 1455 of yacc.c  */
#line 1023 "sql.yacc"
    {
		(yyval.sql_string)=make_sql_string_and_free((yyvsp[(1) - (3)].sql_string),kw_comma,(yyvsp[(3) - (3)].sql_string),NULL);
	}
    break;

  case 88:

/* Line 1455 of yacc.c  */
#line 1032 "sql.yacc"
    {
		(yyval.sql_string)=(yyvsp[(1) - (1)].sql_string);
	}
    break;

  case 89:

/* Line 1455 of yacc.c  */
#line 1035 "sql.yacc"
    {
	add_feature("ALTER_TABLE_DROP");
		(yyval.sql_string)=acl_strdup((yyvsp[(1) - (1)].str));
	}
    break;

  case 90:

/* Line 1455 of yacc.c  */
#line 1039 "sql.yacc"
    {
	add_feature("ALTER_TABLE_MODIFY");
		(yyval.sql_string)=(yyvsp[(1) - (1)].sql_string);
	}
    break;

  case 91:

/* Line 1455 of yacc.c  */
#line 1043 "sql.yacc"
    {
		add_feature("ALTER_TABLE_ADD_CONSTRAINT");
		(yyval.sql_string)=acl_strdup((yyvsp[(1) - (1)].str));
	}
    break;

  case 92:

/* Line 1455 of yacc.c  */
#line 1047 "sql.yacc"
    {
		add_feature("ALTER_TABLE_DROP_CONSTRAINT");
		(yyval.sql_string)=acl_strdup((yyvsp[(1) - (1)].str));
	}
    break;

  case 93:

/* Line 1455 of yacc.c  */
#line 1051 "sql.yacc"
    {
		add_feature("ALTER_TABLE_MODIFY_NEXT");
		(yyval.sql_string)=acl_strdup((yyvsp[(1) - (1)].str));
	}
    break;

  case 94:

/* Line 1455 of yacc.c  */
#line 1055 "sql.yacc"
    {
		add_feature("ALTER_TABLE_LOCK_MODE");
		(yyval.sql_string)=acl_strdup((yyvsp[(1) - (1)].str));
	}
    break;

  case 95:

/* Line 1455 of yacc.c  */
#line 1063 "sql.yacc"
    {
		add_feature("ALTER_TABLE_ADD");
		(yyval.sql_string)=make_sql_string_and_free(acl_strdup("ADD "),(yyvsp[(2) - (2)].sql_string),NULL);
	}
    break;

  case 96:

/* Line 1455 of yacc.c  */
#line 1067 "sql.yacc"
    {
		add_feature("ALTER_TABLE_ADD");
		(yyval.sql_string)=make_sql_string_and_free(acl_strdup("ADD "),kw_ob,(yyvsp[(3) - (4)].sql_string),kw_cb,NULL);
	}
    break;

  case 97:

/* Line 1455 of yacc.c  */
#line 1075 "sql.yacc"
    {
		(yyval.sql_string)=(yyvsp[(1) - (1)].sql_string);
	}
    break;

  case 98:

/* Line 1455 of yacc.c  */
#line 1078 "sql.yacc"
    {
		add_feature("ALTER_TABLE_ADD_BEFORE");
		(yyval.sql_string)=make_sql_string_and_free((yyvsp[(1) - (3)].sql_string),acl_strdup(" BEFORE "),acl_strdup((yyvsp[(3) - (3)].str)),NULL);
	}
    break;

  case 99:

/* Line 1455 of yacc.c  */
#line 1085 "sql.yacc"
    {
		(yyval.sql_string)=(yyvsp[(1) - (1)].sql_string);
	}
    break;

  case 100:

/* Line 1455 of yacc.c  */
#line 1088 "sql.yacc"
    {
		(yyval.sql_string)=make_sql_string_and_free((yyvsp[(1) - (3)].sql_string),kw_comma,(yyvsp[(3) - (3)].sql_string),NULL);
	}
    break;

  case 101:

/* Line 1455 of yacc.c  */
#line 1095 "sql.yacc"
    {
		SPRINTF1((yyval.str),"DROP %s",(yyvsp[(2) - (2)].str));
	}
    break;

  case 102:

/* Line 1455 of yacc.c  */
#line 1098 "sql.yacc"
    {
		SPRINTF1((yyval.str),"DROP (%s)",(yyvsp[(3) - (4)].str));
	}
    break;

  case 104:

/* Line 1455 of yacc.c  */
#line 1106 "sql.yacc"
    {
		SPRINTF2((yyval.str),"%s,%s",(yyvsp[(1) - (3)].str),(yyvsp[(3) - (3)].str));
	}
    break;

  case 106:

/* Line 1455 of yacc.c  */
#line 1115 "sql.yacc"
    {
		(yyval.sql_string)=make_sql_string_and_free(acl_strdup("MODIFY "),(yyvsp[(2) - (2)].sql_string),NULL);
	}
    break;

  case 107:

/* Line 1455 of yacc.c  */
#line 1118 "sql.yacc"
    {
		(yyval.sql_string)=make_sql_string_and_free(acl_strdup("MODIFY "),kw_ob,(yyvsp[(3) - (4)].sql_string),kw_cb,NULL);
	}
    break;

  case 108:

/* Line 1455 of yacc.c  */
#line 1124 "sql.yacc"
    {
		(yyval.sql_string)=(yyvsp[(1) - (1)].sql_string);
	}
    break;

  case 109:

/* Line 1455 of yacc.c  */
#line 1127 "sql.yacc"
    {
		(yyval.sql_string)=make_sql_string_and_free((yyvsp[(1) - (3)].sql_string),kw_comma,(yyvsp[(3) - (3)].sql_string),NULL);
	}
    break;

  case 110:

/* Line 1455 of yacc.c  */
#line 1133 "sql.yacc"
    {
		(yyval.sql_string)=(yyvsp[(1) - (1)].sql_string);
	}
    break;

  case 111:

/* Line 1455 of yacc.c  */
#line 1140 "sql.yacc"
    {strcpy((yyval.str),"LOCK MODE (PAGE)");}
    break;

  case 112:

/* Line 1455 of yacc.c  */
#line 1141 "sql.yacc"
    {strcpy((yyval.str),"LOCK MODE (ROW)");}
    break;

  case 113:

/* Line 1455 of yacc.c  */
#line 1145 "sql.yacc"
    {
		add_feature("DDL_NEXT_SIZE");
		SPRINTF1((yyval.str),"MODIFY NEXT SIZE %d",atoi((yyvsp[(2) - (2)].str)));
	}
    break;

  case 114:

/* Line 1455 of yacc.c  */
#line 1153 "sql.yacc"
    {
		add_feature("DDL_CONSTRAINT");
		SPRINTF2((yyval.str),"ADD CONSTRAINT %s%s",(yyvsp[(2) - (3)].sql_string),(yyvsp[(3) - (3)].str));
	}
    break;

  case 115:

/* Line 1455 of yacc.c  */
#line 1157 "sql.yacc"
    {
		add_feature("ADD_CONSTRAINT");
		SPRINTF1((yyval.str),"ADD CONSTRAINT (%s)",(yyvsp[(3) - (4)].sql_string));
	}
    break;

  case 116:

/* Line 1455 of yacc.c  */
#line 1164 "sql.yacc"
    {
		(yyval.sql_string)=make_sql_string_and_free((yyvsp[(1) - (2)].sql_string),acl_strdup((yyvsp[(2) - (2)].str)),NULL);
}
    break;

  case 117:

/* Line 1455 of yacc.c  */
#line 1166 "sql.yacc"
    {
	(yyval.sql_string)=make_sql_string_and_free((yyvsp[(1) - (4)].sql_string),kw_comma,(yyvsp[(3) - (4)].sql_string),acl_strdup((yyvsp[(4) - (4)].str)), NULL);
}
    break;

  case 118:

/* Line 1455 of yacc.c  */
#line 1171 "sql.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 119:

/* Line 1455 of yacc.c  */
#line 1172 "sql.yacc"
    {SPRINTF2((yyval.str)," %s %s",(yyvsp[(1) - (2)].str),(yyvsp[(2) - (2)].str)); add_feature("DDL_CONSTRAINT");}
    break;

  case 120:

/* Line 1455 of yacc.c  */
#line 1177 "sql.yacc"
    { SPRINTF1((yyval.str),"DROP CONSTRAINT %s",(yyvsp[(2) - (2)].str)); add_feature("DROP_CONSTRAINT"); }
    break;

  case 121:

/* Line 1455 of yacc.c  */
#line 1178 "sql.yacc"
    {add_feature("DROP_CONSTRAINT");
		SPRINTF1((yyval.str),"DROP CONSTRAINT (%s)",(yyvsp[(3) - (4)].str));
	}
    break;

  case 122:

/* Line 1455 of yacc.c  */
#line 1184 "sql.yacc"
    {strcpy((yyval.str),(yyvsp[(1) - (1)].str));}
    break;

  case 123:

/* Line 1455 of yacc.c  */
#line 1185 "sql.yacc"
    {SPRINTF2((yyval.str),"%s,%s",(yyvsp[(1) - (3)].str),(yyvsp[(3) - (3)].str));}
    break;

  case 125:

/* Line 1455 of yacc.c  */
#line 1199 "sql.yacc"
    {  add_feature("ROLLBACK_WORK"); }
    break;

  case 126:

/* Line 1455 of yacc.c  */
#line 1205 "sql.yacc"
    { insql=1;}
    break;

  case 127:

/* Line 1455 of yacc.c  */
#line 1205 "sql.yacc"
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
#line 1214 "sql.yacc"
    {insql=1;}
    break;

  case 129:

/* Line 1455 of yacc.c  */
#line 1214 "sql.yacc"
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
#line 1223 "sql.yacc"
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
#line 1248 "sql.yacc"
    {
			(yyval.str_list)=0;
	}
    break;

  case 132:

/* Line 1455 of yacc.c  */
#line 1251 "sql.yacc"
    {
			(yyval.str_list)=(yyvsp[(2) - (3)].str_list);
			 add_feature("INSERT_COLUMNLIST_EQ_VALUELIST");
	}
    break;

  case 133:

/* Line 1455 of yacc.c  */
#line 1259 "sql.yacc"
    {
                        (yyval.str_list)=new_str_list((yyvsp[(1) - (1)].str));
	}
    break;

  case 134:

/* Line 1455 of yacc.c  */
#line 1262 "sql.yacc"
    {
                        (yyval.str_list)=add_str_list((yyvsp[(1) - (3)].str_list), (yyvsp[(3) - (3)].str));
	}
    break;

  case 135:

/* Line 1455 of yacc.c  */
#line 1269 "sql.yacc"
    {	
			strcpy((yyval.str),(yyvsp[(1) - (1)].str));
	}
    break;

  case 136:

/* Line 1455 of yacc.c  */
#line 1272 "sql.yacc"
    { 
			/* with a table prefix - on an insert ? We'll just silently drop it... */
			strcpy((yyval.str),(yyvsp[(3) - (3)].str));
			A4GL_warn("Dropped table prefix from INSERT column name");
	}
    break;

  case 137:

/* Line 1455 of yacc.c  */
#line 1280 "sql.yacc"
    { (yyval.s_select_list_item_list)=local_new_select_list_item_list((yyvsp[(1) - (1)].s_select_list_item));}
    break;

  case 138:

/* Line 1455 of yacc.c  */
#line 1281 "sql.yacc"
    {
		(yyval.s_select_list_item_list)=local_add_select_list_item_list((yyvsp[(1) - (3)].s_select_list_item_list),(yyvsp[(3) - (3)].s_select_list_item));
	}
    break;

  case 139:

/* Line 1455 of yacc.c  */
#line 1287 "sql.yacc"
    {(yyval.s_select_list_item)=(yyvsp[(1) - (1)].s_select_list_item);}
    break;

  case 140:

/* Line 1455 of yacc.c  */
#line 1288 "sql.yacc"
    {(yyval.s_select_list_item)=new_select_list_item_builtin_const(E_SLI_BUILTIN_CONST_NULL); }
    break;

  case 141:

/* Line 1455 of yacc.c  */
#line 1296 "sql.yacc"
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
#line 1314 "sql.yacc"
    { add_feature("BEGIN_WORK"); }
    break;

  case 143:

/* Line 1455 of yacc.c  */
#line 1318 "sql.yacc"
    { add_feature("COMMIT_WORK"); }
    break;

  case 144:

/* Line 1455 of yacc.c  */
#line 1323 "sql.yacc"
    {(yyval.e_boolean)=EB_FALSE;}
    break;

  case 145:

/* Line 1455 of yacc.c  */
#line 1324 "sql.yacc"
    {
		add_feature("DATABASE_EXCLUSIVE");
		{(yyval.e_boolean)=EB_TRUE;}
	}
    break;

  case 146:

/* Line 1455 of yacc.c  */
#line 1334 "sql.yacc"
    {
	char buff[256];
	(yyval.sql_string)=make_sql_string_and_free(acl_strdup((yyvsp[(1) - (1)].str)),NULL);
	SPRINTF1(buff,"Warning: Informix specific SQL @ line %d\n",yylineno);
	ansi_violation(buff,1);
	}
    break;

  case 147:

/* Line 1455 of yacc.c  */
#line 1343 "sql.yacc"
    {
			add_feature("START_DATABASE_WITH_LOG_MODE_ANSI");
			sprintf((yyval.str),"START DATABASE %s WITH LOG IN %s MODE ANSI", (yyvsp[(2) - (5)].str),(yyvsp[(4) - (5)].str));
	}
    break;

  case 148:

/* Line 1455 of yacc.c  */
#line 1347 "sql.yacc"
    {
			add_feature("START_DATABASE_WITH_LOG");
			sprintf((yyval.str),"START DATABASE %s WITH LOG IN %s", (yyvsp[(2) - (4)].str),(yyvsp[(4) - (4)].str));
	}
    break;

  case 149:

/* Line 1455 of yacc.c  */
#line 1352 "sql.yacc"
    {
			add_feature("SET_CONSTRAINTS_ALL_IMMEDIATE");
			SPRINTF1((yyval.str),"%s",(yyvsp[(1) - (1)].str)); 
	}
    break;

  case 150:

/* Line 1455 of yacc.c  */
#line 1356 "sql.yacc"
    {
		add_feature("SET_BUFFERED_LOG");
			SPRINTF1((yyval.str),"%s",(yyvsp[(1) - (1)].str)); 
	}
    break;

  case 151:

/* Line 1455 of yacc.c  */
#line 1360 "sql.yacc"
    {
		add_feature("SET_LOG");
			SPRINTF1((yyval.str),"%s",(yyvsp[(1) - (1)].str)); 
	}
    break;

  case 152:

/* Line 1455 of yacc.c  */
#line 1364 "sql.yacc"
    {
			SPRINTF2((yyval.str),"%s %s",(yyvsp[(1) - (2)].str),(yyvsp[(2) - (2)].str)); add_feature("UPDATE_STATISTICS_TABLE");
	}
    break;

  case 153:

/* Line 1455 of yacc.c  */
#line 1367 "sql.yacc"
    {
		add_feature("UPDATE_STATISTICS");
			SPRINTF1((yyval.str),"%s",(yyvsp[(1) - (1)].str)); 
	}
    break;

  case 154:

/* Line 1455 of yacc.c  */
#line 1374 "sql.yacc"
    { (yyval.integer_val)=1; }
    break;

  case 155:

/* Line 1455 of yacc.c  */
#line 1375 "sql.yacc"
    { (yyval.integer_val)=-1; }
    break;

  case 156:

/* Line 1455 of yacc.c  */
#line 1376 "sql.yacc"
    { (yyval.integer_val)=0; }
    break;

  case 157:

/* Line 1455 of yacc.c  */
#line 1380 "sql.yacc"
    { (yyval.sql_string)=(yyvsp[(1) - (1)].sql_string); }
    break;

  case 158:

/* Line 1455 of yacc.c  */
#line 1381 "sql.yacc"
    { (yyval.sql_string)=(yyvsp[(1) - (1)].sql_string); }
    break;

  case 159:

/* Line 1455 of yacc.c  */
#line 1382 "sql.yacc"
    { (yyval.sql_string)=(yyvsp[(1) - (1)].sql_string); }
    break;

  case 160:

/* Line 1455 of yacc.c  */
#line 1383 "sql.yacc"
    { (yyval.sql_string)=(yyvsp[(1) - (1)].sql_string); }
    break;

  case 161:

/* Line 1455 of yacc.c  */
#line 1384 "sql.yacc"
    { (yyval.sql_string)=(yyvsp[(1) - (1)].sql_string); }
    break;

  case 162:

/* Line 1455 of yacc.c  */
#line 1385 "sql.yacc"
    { (yyval.sql_string)=(yyvsp[(1) - (1)].sql_string); }
    break;

  case 163:

/* Line 1455 of yacc.c  */
#line 1386 "sql.yacc"
    { (yyval.sql_string)=(yyvsp[(1) - (1)].sql_string); }
    break;

  case 164:

/* Line 1455 of yacc.c  */
#line 1394 "sql.yacc"
    {SPRINTF7((yyval.str),"%s %s %s %s %s %s %s",(yyvsp[(1) - (7)].str),(yyvsp[(2) - (7)].str),(yyvsp[(3) - (7)].str),(yyvsp[(4) - (7)].str),(yyvsp[(5) - (7)].str),(yyvsp[(6) - (7)].str),(yyvsp[(7) - (7)].str));  add_feature("GRANT"); }
    break;

  case 165:

/* Line 1455 of yacc.c  */
#line 1395 "sql.yacc"
    {SPRINTF6((yyval.str),"%s %s %s %s %s %s",(yyvsp[(1) - (6)].str),(yyvsp[(2) - (6)].str),(yyvsp[(3) - (6)].str),(yyvsp[(4) - (6)].str),(yyvsp[(5) - (6)].str),(yyvsp[(6) - (6)].str));  add_feature("REVOKE"); }
    break;

  case 166:

/* Line 1455 of yacc.c  */
#line 1396 "sql.yacc"
    {SPRINTF4((yyval.str),"%s %s %s %s ",(yyvsp[(1) - (4)].str),(yyvsp[(2) - (4)].str),(yyvsp[(3) - (4)].str),(yyvsp[(4) - (4)].str)); add_feature("GRANT"); }
    break;

  case 167:

/* Line 1455 of yacc.c  */
#line 1397 "sql.yacc"
    {SPRINTF4((yyval.str),"%s %s %s %s ",(yyvsp[(1) - (4)].str),(yyvsp[(2) - (4)].str),(yyvsp[(3) - (4)].str),(yyvsp[(4) - (4)].str));  add_feature("REVOKE"); }
    break;

  case 171:

/* Line 1455 of yacc.c  */
#line 1407 "sql.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 172:

/* Line 1455 of yacc.c  */
#line 1408 "sql.yacc"
    {SPRINTF1((yyval.str)," %s ",(yyvsp[(1) - (1)].str));}
    break;

  case 173:

/* Line 1455 of yacc.c  */
#line 1409 "sql.yacc"
    {SPRINTF2((yyval.str)," %s %s",(yyvsp[(1) - (2)].str),(yyvsp[(2) - (2)].str));}
    break;

  case 174:

/* Line 1455 of yacc.c  */
#line 1413 "sql.yacc"
    {SPRINTF1((yyval.str)," %s ",(yyvsp[(1) - (1)].str));}
    break;

  case 175:

/* Line 1455 of yacc.c  */
#line 1414 "sql.yacc"
    {SPRINTF1((yyval.str)," %s ",(yyvsp[(1) - (1)].str));}
    break;

  case 178:

/* Line 1455 of yacc.c  */
#line 1421 "sql.yacc"
    {SPRINTF3((yyval.str)," %s %s %s",(yyvsp[(1) - (3)].str),(yyvsp[(2) - (3)].str),(yyvsp[(3) - (3)].str));}
    break;

  case 179:

/* Line 1455 of yacc.c  */
#line 1424 "sql.yacc"
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
#line 1433 "sql.yacc"
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
#line 1444 "sql.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 186:

/* Line 1455 of yacc.c  */
#line 1446 "sql.yacc"
    {SPRINTF3((yyval.str)," %s %s %s",(yyvsp[(1) - (3)].str),(yyvsp[(2) - (3)].str),(yyvsp[(3) - (3)].str));}
    break;

  case 188:

/* Line 1455 of yacc.c  */
#line 1452 "sql.yacc"
    {SPRINTF3((yyval.str)," %s %s %s",(yyvsp[(1) - (3)].str),(yyvsp[(2) - (3)].str),(yyvsp[(3) - (3)].str));}
    break;

  case 190:

/* Line 1455 of yacc.c  */
#line 1458 "sql.yacc"
    {SPRINTF3((yyval.str)," %s %s %s",(yyvsp[(1) - (3)].str),(yyvsp[(2) - (3)].str),(yyvsp[(3) - (3)].str));}
    break;

  case 193:

/* Line 1455 of yacc.c  */
#line 1468 "sql.yacc"
    {
		add_feature("CREATE_VIEW_AS_SELECT");
		(yyval.sql_string)=make_sql_string_and_free(acl_strdup((yyvsp[(1) - (6)].str)),kw_space,acl_strdup((yyvsp[(2) - (6)].str)),kw_space,acl_strdup((yyvsp[(3) - (6)].str)),kw_space,acl_strdup((yyvsp[(4) - (6)].str)),kw_space,(yyvsp[(5) - (6)].sql_string),kw_space,acl_strdup((yyvsp[(6) - (6)].str)),NULL);
	
}
    break;

  case 194:

/* Line 1455 of yacc.c  */
#line 1475 "sql.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 195:

/* Line 1455 of yacc.c  */
#line 1477 "sql.yacc"
    {SPRINTF3((yyval.str)," %s %s %s",(yyvsp[(1) - (3)].str),(yyvsp[(2) - (3)].str),(yyvsp[(3) - (3)].str));}
    break;

  case 197:

/* Line 1455 of yacc.c  */
#line 1483 "sql.yacc"
    {SPRINTF3((yyval.str)," %s %s %s",(yyvsp[(1) - (3)].str),(yyvsp[(2) - (3)].str),(yyvsp[(3) - (3)].str));}
    break;

  case 198:

/* Line 1455 of yacc.c  */
#line 1486 "sql.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 199:

/* Line 1455 of yacc.c  */
#line 1487 "sql.yacc"
    {
		add_feature("CREATE_VIEW_SELECT_WITH_CHECK");
	}
    break;

  case 200:

/* Line 1455 of yacc.c  */
#line 1494 "sql.yacc"
    {
		(yyval.sql_string)=make_sql_string_and_free(strdup("CHECK ("),(yyvsp[(3) - (4)].sql_string),kw_cb,NULL);
		add_feature("DDL_CHECK");
	}
    break;

  case 201:

/* Line 1455 of yacc.c  */
#line 1503 "sql.yacc"
    {SPRINTF5((yyval.str)," %s %s %s %s %s",(yyvsp[(1) - (5)].str),(yyvsp[(2) - (5)].str),(yyvsp[(3) - (5)].str),(yyvsp[(4) - (5)].str),(yyvsp[(5) - (5)].str));
	add_feature("DDL_FOREIGN_KEY");
}
    break;

  case 202:

/* Line 1455 of yacc.c  */
#line 1510 "sql.yacc"
    {SPRINTF2((yyval.str)," %s %s",(yyvsp[(1) - (2)].str),(yyvsp[(2) - (2)].str));
add_feature("DDL_REFERENCES");
}
    break;

  case 205:

/* Line 1455 of yacc.c  */
#line 1522 "sql.yacc"
    {SPRINTF4((yyval.str)," %s %s %s %s",(yyvsp[(1) - (4)].str),(yyvsp[(2) - (4)].str),(yyvsp[(3) - (4)].str),(yyvsp[(4) - (4)].str));}
    break;

  case 207:

/* Line 1455 of yacc.c  */
#line 1528 "sql.yacc"
    {SPRINTF3((yyval.str)," %s %s %s",(yyvsp[(1) - (3)].str),(yyvsp[(2) - (3)].str),(yyvsp[(3) - (3)].str));}
    break;

  case 208:

/* Line 1455 of yacc.c  */
#line 1533 "sql.yacc"
    {
		SPRINTF3((yyval.str)," UNIQUE %s %s %s",(yyvsp[(2) - (4)].str),(yyvsp[(3) - (4)].str),(yyvsp[(4) - (4)].str));
add_feature("DDL_UNIQUE");
	}
    break;

  case 209:

/* Line 1455 of yacc.c  */
#line 1537 "sql.yacc"
    {
		ansi_violation("Use UNIQUE not DISTINCT",0);
		SPRINTF3((yyval.str)," UNIQUE %s %s %s",(yyvsp[(2) - (4)].str),(yyvsp[(3) - (4)].str),(yyvsp[(4) - (4)].str));
add_feature("DDL_DISTINCT");
	}
    break;

  case 210:

/* Line 1455 of yacc.c  */
#line 1543 "sql.yacc"
    {SPRINTF4((yyval.str)," %s %s %s %s",(yyvsp[(1) - (4)].str),(yyvsp[(2) - (4)].str),(yyvsp[(3) - (4)].str),(yyvsp[(4) - (4)].str));
add_feature("DDL_PRIMARY_KEY");
}
    break;

  case 212:

/* Line 1455 of yacc.c  */
#line 1551 "sql.yacc"
    {SPRINTF3((yyval.str)," %s %s %s",(yyvsp[(1) - (3)].str),(yyvsp[(2) - (3)].str),(yyvsp[(3) - (3)].str));}
    break;

  case 213:

/* Line 1455 of yacc.c  */
#line 1556 "sql.yacc"
    {
		(yyval.sql_string)=acl_strdup((yyvsp[(1) - (1)].str));
	}
    break;

  case 214:

/* Line 1455 of yacc.c  */
#line 1559 "sql.yacc"
    {
		(yyval.sql_string)=acl_strdup((yyvsp[(1) - (1)].str));
	}
    break;

  case 215:

/* Line 1455 of yacc.c  */
#line 1562 "sql.yacc"
    {
		(yyval.sql_string)=(yyvsp[(1) - (1)].sql_string);
	}
    break;

  case 216:

/* Line 1455 of yacc.c  */
#line 1569 "sql.yacc"
    {SPRINTF2((yyval.str)," %s %s",(yyvsp[(1) - (2)].str),(yyvsp[(2) - (2)].str)); add_feature("DDL_DEFAULT_VALUE"); }
    break;

  case 217:

/* Line 1455 of yacc.c  */
#line 1570 "sql.yacc"
    {SPRINTF1((yyval.str)," DEFAULT %s", A4GLSQLCV_get_sqlconst("USER")); add_feature("DDL_DEFAULT_VALUE"); }
    break;

  case 218:

/* Line 1455 of yacc.c  */
#line 1571 "sql.yacc"
    {SPRINTF1((yyval.str)," DEFAULT %s", A4GLSQLCV_get_sqlconst("TODAY")); add_feature("DDL_DEFAULT_VALUE"); }
    break;

  case 219:

/* Line 1455 of yacc.c  */
#line 1572 "sql.yacc"
    { SPRINTF1((yyval.str)," %s",(yyvsp[(1) - (1)].str)); add_feature("DDL_DEFAULT_VALUE"); }
    break;

  case 220:

/* Line 1455 of yacc.c  */
#line 1578 "sql.yacc"
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
#line 1599 "sql.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 223:

/* Line 1455 of yacc.c  */
#line 1603 "sql.yacc"
    {
		(yyval.sql_string)=acl_strdup("");
	}
    break;

  case 224:

/* Line 1455 of yacc.c  */
#line 1605 "sql.yacc"
    {
		(yyval.sql_string)=(yyvsp[(1) - (1)].sql_string);
	}
    break;

  case 225:

/* Line 1455 of yacc.c  */
#line 1612 "sql.yacc"
    {
		(yyval.sql_string)=(yyvsp[(1) - (1)].sql_string);
	}
    break;

  case 226:

/* Line 1455 of yacc.c  */
#line 1615 "sql.yacc"
    {
		(yyval.sql_string)=make_sql_string_and_free((yyvsp[(1) - (2)].sql_string),kw_space,(yyvsp[(2) - (2)].sql_string),NULL);
	}
    break;

  case 227:

/* Line 1455 of yacc.c  */
#line 1621 "sql.yacc"
    {
		(yyval.sql_string)=make_sql_string_and_free((yyvsp[(1) - (2)].sql_string),acl_strdup((yyvsp[(2) - (2)].str)),NULL);
	}
    break;

  case 228:

/* Line 1455 of yacc.c  */
#line 1629 "sql.yacc"
    {
		SPRINTF1((yyval.str)," %s ",(yyvsp[(1) - (1)].str));
		(yyval.sql_string)=acl_strdup((yyval.str));
		add_feature("DDL_NOT_NULL");
	}
    break;

  case 229:

/* Line 1455 of yacc.c  */
#line 1634 "sql.yacc"
    {
		SPRINTF0((yyval.str)," NOT NULL UNIQUE ");
		(yyval.sql_string)=acl_strdup((yyval.str));
		add_feature("DDL_NOT_NULL");
		add_feature("DDL_UNIQUE");
	}
    break;

  case 230:

/* Line 1455 of yacc.c  */
#line 1640 "sql.yacc"
    {
		SPRINTF0((yyval.str)," UNIQUE ");
		(yyval.sql_string)=acl_strdup((yyval.str));
		add_feature("DDL_UNIQUE");
	}
    break;

  case 231:

/* Line 1455 of yacc.c  */
#line 1645 "sql.yacc"
    {
		ansi_violation("Use UNIQUE not DISTINCT",0);
		SPRINTF0((yyval.str)," UNIQUE ");
		(yyval.sql_string)=acl_strdup((yyval.str));
		add_feature("DDL_DISTINCT");
	}
    break;

  case 232:

/* Line 1455 of yacc.c  */
#line 1651 "sql.yacc"
    {
		(yyval.sql_string)=acl_strdup((yyvsp[(1) - (1)].str));
	}
    break;

  case 233:

/* Line 1455 of yacc.c  */
#line 1654 "sql.yacc"
    {
		(yyval.sql_string)=make_sql_string_and_free(acl_strdup("CHECK ("),(yyvsp[(3) - (4)].sql_string),kw_cb,NULL);
		add_feature("DDL_CHECK");
		
	}
    break;

  case 234:

/* Line 1455 of yacc.c  */
#line 1659 "sql.yacc"
    {
		(yyval.sql_string)=make_sql_string_and_free(acl_strdup(" PRIMARY KEY "),NULL);
		add_feature("DDL_PRIMARY_KEY");
	}
    break;

  case 235:

/* Line 1455 of yacc.c  */
#line 1668 "sql.yacc"
    {
		add_feature("CREATE_SCHEMA");

(yyval.sql_string)=make_sql_string_and_free(acl_strdup((yyvsp[(1) - (3)].str)),kw_space,acl_strdup((yyvsp[(2) - (3)].str)),kw_space,acl_strdup((yyvsp[(3) - (3)].str)),NULL);
}
    break;

  case 236:

/* Line 1455 of yacc.c  */
#line 1677 "sql.yacc"
    {SPRINTF1((yyval.str)," %s",(yyvsp[(1) - (1)].str));}
    break;

  case 239:

/* Line 1455 of yacc.c  */
#line 1686 "sql.yacc"
    {
		(yyval.sql_string)=make_sql_string_and_free((yyvsp[(1) - (2)].sql_string),kw_space,(yyvsp[(2) - (2)].sql_string),NULL);
	}
    break;

  case 240:

/* Line 1455 of yacc.c  */
#line 1692 "sql.yacc"
    {
		(yyval.sql_string)=(yyvsp[(1) - (1)].sql_string);
	}
    break;

  case 241:

/* Line 1455 of yacc.c  */
#line 1695 "sql.yacc"
    {
		(yyval.sql_string)=acl_strdup((yyvsp[(1) - (1)].str));
	}
    break;

  case 242:

/* Line 1455 of yacc.c  */
#line 1706 "sql.yacc"
    {
		 add_feature("HAVING"); 
		(yyval.s_select_list_item)=(yyvsp[(2) - (2)].s_select_list_item);
	}
    break;

  case 243:

/* Line 1455 of yacc.c  */
#line 1715 "sql.yacc"
    {
		 (yyval.s_select_list_item)=(yyvsp[(2) - (2)].s_select_list_item);
	}
    break;

  case 244:

/* Line 1455 of yacc.c  */
#line 1722 "sql.yacc"
    {
		(yyval.u_table)=(yyvsp[(2) - (2)].u_table);
	}
    break;

  case 245:

/* Line 1455 of yacc.c  */
#line 1728 "sql.yacc"
    {(yyval.u_table)=(yyvsp[(1) - (1)].u_table);}
    break;

  case 246:

/* Line 1455 of yacc.c  */
#line 1729 "sql.yacc"
    {
		(yyval.u_table)=A4GLSQLPARSE_append_tablename((yyvsp[(1) - (3)].u_table),(yyvsp[(3) - (3)].u_table),E_OUTER_NONE,NULL);
	}
    break;

  case 247:

/* Line 1455 of yacc.c  */
#line 1732 "sql.yacc"
    {
		(yyval.u_table)=A4GLSQLPARSE_append_tablename((yyvsp[(1) - (4)].u_table),(yyvsp[(4) - (4)].u_table),E_OUTER_NORMAL,NULL);
		A4GL_warn("OUTER join *may* not be portable to non-informix database");
		add_feature("SELECT_OUTER");
	}
    break;

  case 248:

/* Line 1455 of yacc.c  */
#line 1737 "sql.yacc"
    {
		(yyval.u_table)=A4GLSQLPARSE_append_tablename((yyvsp[(1) - (6)].u_table),(yyvsp[(5) - (6)].u_table),E_OUTER_NORMAL,NULL);
		A4GL_warn("OUTER join *may* not be portable to non-informix database");
		add_feature("SELECT_OUTER");
	}
    break;

  case 249:

/* Line 1455 of yacc.c  */
#line 1748 "sql.yacc"
    {
		(yyval.u_table)=A4GLSQLPARSE_append_tablename((yyvsp[(1) - (5)].u_table),(yyvsp[(3) - (5)].u_table),E_OUTER_LEFT_OUTER, (yyvsp[(5) - (5)].s_select_list_item));
		add_feature("SELECT_OUTER");
	}
    break;

  case 250:

/* Line 1455 of yacc.c  */
#line 1752 "sql.yacc"
    {
		(yyval.u_table)=A4GLSQLPARSE_append_tablename((yyvsp[(1) - (5)].u_table),(yyvsp[(3) - (5)].u_table),E_INNER, (yyvsp[(5) - (5)].s_select_list_item));
		add_feature("SELECT_INNER");
	}
    break;

  case 252:

/* Line 1455 of yacc.c  */
#line 1760 "sql.yacc"
    {(yyval.u_table)=(yyvsp[(2) - (3)].u_table);}
    break;

  case 253:

/* Line 1455 of yacc.c  */
#line 1764 "sql.yacc"
    { 
			//A4GL_add_crud("SELECT",$<str>1);
			(yyval.u_table)=A4GLSQLPARSE_new_tablename((yyvsp[(1) - (1)].str),NULL);
	}
    break;

  case 254:

/* Line 1455 of yacc.c  */
#line 1768 "sql.yacc"
    { 
			//A4GL_add_crud("SELECT",$<str>1);
			(yyval.u_table)=A4GLSQLPARSE_new_tablename((yyvsp[(1) - (2)].str),(yyvsp[(2) - (2)].str));
	}
    break;

  case 255:

/* Line 1455 of yacc.c  */
#line 1772 "sql.yacc"
    { 
			//A4GL_add_crud("SELECT",$<str>1);
			(yyval.u_table)=A4GLSQLPARSE_new_tablename((yyvsp[(1) - (3)].str),(yyvsp[(3) - (3)].str));
	}
    break;

  case 256:

/* Line 1455 of yacc.c  */
#line 1779 "sql.yacc"
    {
			/* No from or where etc.. */
			/* eg.. select user ; */
			(yyval.s_select)=new_empty_select();
		}
    break;

  case 257:

/* Line 1455 of yacc.c  */
#line 1784 "sql.yacc"
    {
		(yyval.s_select)=(yyvsp[(2) - (2)].s_select);
		(yyval.s_select)->first=(yyvsp[(1) - (2)].u_table);
			A4GL_set_associated_mem( (yyval.s_select), (yyval.s_select)->first);
}
    break;

  case 258:

/* Line 1455 of yacc.c  */
#line 1792 "sql.yacc"
    {
		(yyval.s_select)=(yyvsp[(1) - (1)].s_select);
	}
    break;

  case 259:

/* Line 1455 of yacc.c  */
#line 1795 "sql.yacc"
    {
		(yyval.s_select)=(yyvsp[(2) - (2)].s_select);
		(yyval.s_select)->where_clause=(yyvsp[(1) - (2)].s_select_list_item);
	}
    break;

  case 260:

/* Line 1455 of yacc.c  */
#line 1801 "sql.yacc"
    {
		(yyval.s_select)=new_empty_select();
	}
    break;

  case 261:

/* Line 1455 of yacc.c  */
#line 1804 "sql.yacc"
    {
		(yyval.s_select)=new_empty_select();
		(yyval.s_select)->group_by=(yyvsp[(1) - (1)].s_select_list_item_list);
		(yyval.s_select)->having=0;
	}
    break;

  case 262:

/* Line 1455 of yacc.c  */
#line 1809 "sql.yacc"
    {
		(yyval.s_select)=new_empty_select();
		(yyval.s_select)->group_by=(yyvsp[(1) - (2)].s_select_list_item_list);
		(yyval.s_select)->having=(yyvsp[(2) - (2)].s_select_list_item);
	}
    break;

  case 263:

/* Line 1455 of yacc.c  */
#line 1814 "sql.yacc"
    {
		(yyval.s_select)=new_empty_select();
		(yyval.s_select)->group_by=0;
		(yyval.s_select)->having=(yyvsp[(1) - (1)].s_select_list_item);

	}
    break;

  case 264:

/* Line 1455 of yacc.c  */
#line 1827 "sql.yacc"
    {
		(yyval.s_select_list_item)=(yyvsp[(1) - (1)].s_select_list_item);
	}
    break;

  case 265:

/* Line 1455 of yacc.c  */
#line 1830 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_op_expr((yyvsp[(1) - (3)].s_select_list_item),(yyvsp[(3) - (3)].s_select_list_item)," OR ");
	}
    break;

  case 266:

/* Line 1455 of yacc.c  */
#line 1836 "sql.yacc"
    {
		(yyval.s_select_list_item)=(yyvsp[(1) - (1)].s_select_list_item);
	}
    break;

  case 267:

/* Line 1455 of yacc.c  */
#line 1839 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_op_expr((yyvsp[(1) - (3)].s_select_list_item),(yyvsp[(3) - (3)].s_select_list_item)," AND ");
	}
    break;

  case 268:

/* Line 1455 of yacc.c  */
#line 1845 "sql.yacc"
    {
		(yyval.s_select_list_item)=(yyvsp[(1) - (1)].s_select_list_item);
	}
    break;

  case 269:

/* Line 1455 of yacc.c  */
#line 1848 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_simple_expr(E_SLI_NOT,(yyvsp[(2) - (2)].s_select_list_item));
	}
    break;

  case 270:

/* Line 1455 of yacc.c  */
#line 1854 "sql.yacc"
    {
		(yyval.s_select_list_item)=(yyvsp[(1) - (1)].s_select_list_item);
	}
    break;

  case 271:

/* Line 1455 of yacc.c  */
#line 1857 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_simple_expr(E_SLI_BRACKET_EXPR,(yyvsp[(2) - (3)].s_select_list_item));
	}
    break;

  case 272:

/* Line 1455 of yacc.c  */
#line 1864 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_sq(E_SQE_EXISTS, (yyvsp[(2) - (2)].s_select_list_item));
		add_feature("WHERE_EXISTS");
	}
    break;

  case 273:

/* Line 1455 of yacc.c  */
#line 1868 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_sq(E_SQE_NOT_EXISTS, (yyvsp[(2) - (2)].s_select_list_item));
		add_feature("WHERE_EXISTS");
	}
    break;

  case 274:

/* Line 1455 of yacc.c  */
#line 1879 "sql.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 275:

/* Line 1455 of yacc.c  */
#line 1879 "sql.yacc"
    {SPRINTF1((yyval.str)," ESCAPE %s",(yyvsp[(2) - (2)].str));add_feature("WHERE_MATCHES_ESCAPE");}
    break;

  case 276:

/* Line 1455 of yacc.c  */
#line 1880 "sql.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 277:

/* Line 1455 of yacc.c  */
#line 1880 "sql.yacc"
    {SPRINTF1((yyval.str)," ESCAPE %s",(yyvsp[(2) - (2)].str));add_feature("WHERE_ILIKE_ESCAPE");}
    break;

  case 278:

/* Line 1455 of yacc.c  */
#line 1881 "sql.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 279:

/* Line 1455 of yacc.c  */
#line 1881 "sql.yacc"
    {SPRINTF1((yyval.str)," ESCAPE %s",(yyvsp[(2) - (2)].str));add_feature("WHERE_LIKE_ESCAPE");}
    break;

  case 280:

/* Line 1455 of yacc.c  */
#line 1884 "sql.yacc"
    {
		 (yyval.s_select_list_item)=(yyvsp[(1) - (1)].s_select_list_item);
	}
    break;

  case 282:

/* Line 1455 of yacc.c  */
#line 1894 "sql.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 283:

/* Line 1455 of yacc.c  */
#line 1895 "sql.yacc"
    {strcpy((yyval.str)," NOT ");}
    break;

  case 284:

/* Line 1455 of yacc.c  */
#line 1900 "sql.yacc"
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
#line 1909 "sql.yacc"
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
#line 1917 "sql.yacc"
    { 
			(yyval.s_select_list_item)=new_select_list_item_op_expr((yyvsp[(1) - (3)].s_select_list_item),(yyvsp[(3) - (3)].s_select_list_item),(yyvsp[(2) - (3)].str));
	}
    break;

  case 287:

/* Line 1455 of yacc.c  */
#line 1920 "sql.yacc"
    { 
			(yyval.s_select_list_item)=new_select_list_item_op_expr((yyvsp[(1) - (3)].s_select_list_item),(yyvsp[(3) - (3)].s_select_list_item),"=");
	}
    break;

  case 288:

/* Line 1455 of yacc.c  */
#line 1923 "sql.yacc"
    { 
			FPRINTF(stderr,"Warning: Corrected =NULL to IS NULL line %d\n",yylineno);
			(yyval.s_select_list_item)=new_select_list_item_simple_expr(E_SLI_ISNULL,(yyvsp[(1) - (3)].s_select_list_item));
	}
    break;

  case 289:

/* Line 1455 of yacc.c  */
#line 1927 "sql.yacc"
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
#line 1934 "sql.yacc"
    { 
			(yyval.s_select_list_item)=new_select_list_item_regex(E_SLI_REGEX_LIKE,(yyvsp[(1) - (4)].s_select_list_item),(yyvsp[(3) - (4)].s_select_list_item),(yyvsp[(4) - (4)].str));
	}
    break;

  case 291:

/* Line 1455 of yacc.c  */
#line 1937 "sql.yacc"
    { 
			(yyval.s_select_list_item)=new_select_list_item_regex(E_SLI_REGEX_NOT_LIKE,(yyvsp[(1) - (4)].s_select_list_item),(yyvsp[(3) - (4)].s_select_list_item),(yyvsp[(4) - (4)].str));

	}
    break;

  case 292:

/* Line 1455 of yacc.c  */
#line 1941 "sql.yacc"
    { 
			(yyval.s_select_list_item)=new_select_list_item_regex(E_SLI_REGEX_ILIKE,(yyvsp[(1) - (4)].s_select_list_item),(yyvsp[(3) - (4)].s_select_list_item),(yyvsp[(4) - (4)].str));
	}
    break;

  case 293:

/* Line 1455 of yacc.c  */
#line 1944 "sql.yacc"
    { 
			(yyval.s_select_list_item)=new_select_list_item_regex(E_SLI_REGEX_NOT_ILIKE,(yyvsp[(1) - (4)].s_select_list_item),(yyvsp[(3) - (4)].s_select_list_item),(yyvsp[(4) - (4)].str));
	}
    break;

  case 294:

/* Line 1455 of yacc.c  */
#line 1947 "sql.yacc"
    { 
			(yyval.s_select_list_item)=new_select_list_item_regex(E_SLI_REGEX_MATCHES,(yyvsp[(1) - (4)].s_select_list_item),(yyvsp[(3) - (4)].s_select_list_item),(yyvsp[(4) - (4)].str));
	}
    break;

  case 295:

/* Line 1455 of yacc.c  */
#line 1950 "sql.yacc"
    { 
			(yyval.s_select_list_item)=new_select_list_item_regex(E_SLI_REGEX_NOT_MATCHES,(yyvsp[(1) - (4)].s_select_list_item),(yyvsp[(3) - (4)].s_select_list_item),(yyvsp[(4) - (4)].str));
	}
    break;

  case 296:

/* Line 1455 of yacc.c  */
#line 1956 "sql.yacc"
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
#line 1963 "sql.yacc"
    {
			strcpy((yyval.str)," < ");
	}
    break;

  case 298:

/* Line 1455 of yacc.c  */
#line 1966 "sql.yacc"
    {
			strcpy((yyval.str)," > ");
	}
    break;

  case 299:

/* Line 1455 of yacc.c  */
#line 1969 "sql.yacc"
    {
			strcpy((yyval.str)," ~ ");
	}
    break;

  case 300:

/* Line 1455 of yacc.c  */
#line 1972 "sql.yacc"
    {strcpy((yyval.str)," <= ");}
    break;

  case 301:

/* Line 1455 of yacc.c  */
#line 1973 "sql.yacc"
    {strcpy((yyval.str)," >= ");}
    break;

  case 302:

/* Line 1455 of yacc.c  */
#line 1978 "sql.yacc"
    {
		(yyval.s_select_list_item)=(yyvsp[(1) - (1)].s_select_list_item);
	}
    break;

  case 303:

/* Line 1455 of yacc.c  */
#line 1981 "sql.yacc"
    {
		(yyval.s_select_list_item)=(yyvsp[(1) - (1)].s_select_list_item);
	}
    break;

  case 304:

/* Line 1455 of yacc.c  */
#line 1984 "sql.yacc"
    {
		(yyval.s_select_list_item)=(yyvsp[(1) - (1)].s_select_list_item);
	}
    break;

  case 305:

/* Line 1455 of yacc.c  */
#line 1987 "sql.yacc"
    {
                 (yyval.s_select_list_item)=(yyvsp[(1) - (1)].s_select_list_item);
        }
    break;

  case 306:

/* Line 1455 of yacc.c  */
#line 1994 "sql.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 307:

/* Line 1455 of yacc.c  */
#line 1995 "sql.yacc"
    {strcpy((yyval.str)," ALL "); add_feature("AGG_ALL");}
    break;

  case 308:

/* Line 1455 of yacc.c  */
#line 1996 "sql.yacc"
    {
		strcpy((yyval.str)," DISTINCT ");
		add_feature("AGG_DISTINCT");
	}
    break;

  case 309:

/* Line 1455 of yacc.c  */
#line 2000 "sql.yacc"
    {
		ansi_violation("Use DISTINCT not UNIQUE",0);
		strcpy((yyval.str)," DISTINCT ");
		add_feature("AGG_DISTINCT");
	}
    break;

  case 310:

/* Line 1455 of yacc.c  */
#line 2007 "sql.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 311:

/* Line 1455 of yacc.c  */
#line 2008 "sql.yacc"
    {strcpy((yyval.str)," ALL "); add_feature("UNION_ALL");}
    break;

  case 312:

/* Line 1455 of yacc.c  */
#line 2009 "sql.yacc"
    {
		strcpy((yyval.str)," DISTINCT ");
		add_feature("UNION_DISTINCT");
	}
    break;

  case 313:

/* Line 1455 of yacc.c  */
#line 2013 "sql.yacc"
    {
		ansi_violation("Use DISTINCT not UNIQUE",0);
		add_feature("UNION_DISTINCT");
		strcpy((yyval.str)," DISTINCT ");
	}
    break;

  case 314:

/* Line 1455 of yacc.c  */
#line 2027 "sql.yacc"
    {
		strcpy((yyval.str),A4GLSQLCV_dtype_alias((yyvsp[(1) - (1)].str)));
	}
    break;

  case 319:

/* Line 1455 of yacc.c  */
#line 2042 "sql.yacc"
    {SPRINTF4((yyval.str)," %s %s%s%s",(yyvsp[(1) - (4)].str),(yyvsp[(2) - (4)].str),(yyvsp[(3) - (4)].str),(yyvsp[(4) - (4)].str));}
    break;

  case 320:

/* Line 1455 of yacc.c  */
#line 2046 "sql.yacc"
    {strcpy((yyval.str),"SERIAL"); add_feature("DDL_SERIAL"); }
    break;

  case 321:

/* Line 1455 of yacc.c  */
#line 2047 "sql.yacc"
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
#line 2056 "sql.yacc"
    {strcpy((yyval.str),"SERIAL8"); add_feature("DDL_SERIAL8"); }
    break;

  case 323:

/* Line 1455 of yacc.c  */
#line 2058 "sql.yacc"
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
#line 2067 "sql.yacc"
    {
 			add_feature("DDL_DECIMAL");
	}
    break;

  case 325:

/* Line 1455 of yacc.c  */
#line 2070 "sql.yacc"
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
#line 2078 "sql.yacc"
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
#line 2088 "sql.yacc"
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
#line 2096 "sql.yacc"
    {strcpy((yyval.str),"DATE");
 			add_feature("DDL_DATE"); }
    break;

  case 329:

/* Line 1455 of yacc.c  */
#line 2098 "sql.yacc"
    {strcpy((yyval.str),"INTEGER");}
    break;

  case 330:

/* Line 1455 of yacc.c  */
#line 2099 "sql.yacc"
    {strcpy((yyval.str),"SMALLINT");}
    break;

  case 331:

/* Line 1455 of yacc.c  */
#line 2100 "sql.yacc"
    {strcpy((yyval.str),"NCHAR"); add_feature("DDL_NCHAR");}
    break;

  case 332:

/* Line 1455 of yacc.c  */
#line 2101 "sql.yacc"
    {SPRINTF1((yyval.str),"NCHAR(%s)",(yyvsp[(3) - (4)].str)); add_feature("DDL_NCHAR");}
    break;

  case 333:

/* Line 1455 of yacc.c  */
#line 2102 "sql.yacc"
    {add_feature("DDL_NVARCHAR");}
    break;

  case 334:

/* Line 1455 of yacc.c  */
#line 2103 "sql.yacc"
    {SPRINTF1((yyval.str),"NVARCHAR(%s)",(yyvsp[(3) - (4)].str)); add_feature("DDL_NVARCHAR");}
    break;

  case 335:

/* Line 1455 of yacc.c  */
#line 2104 "sql.yacc"
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
#line 2112 "sql.yacc"
    {SPRINTF2((yyval.str),"DATETIME %s TO %s",(yyvsp[(2) - (4)].str),(yyvsp[(4) - (4)].str)); add_feature("DDL_DATETIME");}
    break;

  case 337:

/* Line 1455 of yacc.c  */
#line 2113 "sql.yacc"
    {add_feature("DDL_DATETIME");}
    break;

  case 338:

/* Line 1455 of yacc.c  */
#line 2114 "sql.yacc"
    {SPRINTF2((yyval.str),"INTERVAL %s TO %s",(yyvsp[(2) - (4)].str),(yyvsp[(4) - (4)].str)); add_feature("DDL_INTERVAL");}
    break;

  case 339:

/* Line 1455 of yacc.c  */
#line 2115 "sql.yacc"
    {strcpy((yyval.str),(yyvsp[(1) - (1)].str));}
    break;

  case 340:

/* Line 1455 of yacc.c  */
#line 2116 "sql.yacc"
    {add_feature("DDL_INTERVAL");}
    break;

  case 341:

/* Line 1455 of yacc.c  */
#line 2117 "sql.yacc"
    {SPRINTF3((yyval.str),"INTERVAL %s(%s) TO %s",(yyvsp[(2) - (7)].str),(yyvsp[(4) - (7)].str),(yyvsp[(7) - (7)].str)); add_feature("DDL_INTERVAL");}
    break;

  case 342:

/* Line 1455 of yacc.c  */
#line 2118 "sql.yacc"
    {add_feature("DDL_TEXT");}
    break;

  case 343:

/* Line 1455 of yacc.c  */
#line 2119 "sql.yacc"
    {add_feature("DDL_BYTE");}
    break;

  case 344:

/* Line 1455 of yacc.c  */
#line 2120 "sql.yacc"
    {add_feature("DDL_VARCHAR");}
    break;

  case 345:

/* Line 1455 of yacc.c  */
#line 2121 "sql.yacc"
    {SPRINTF1((yyval.str),"VARCHAR(%s)",(yyvsp[(3) - (4)].str));add_feature("DDL_VARCHAR");}
    break;

  case 346:

/* Line 1455 of yacc.c  */
#line 2122 "sql.yacc"
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
#line 2132 "sql.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 348:

/* Line 1455 of yacc.c  */
#line 2133 "sql.yacc"
    {
		SPRINTF1((yyval.str),",%s",(yyvsp[(2) - (2)].str));
}
    break;

  case 349:

/* Line 1455 of yacc.c  */
#line 2140 "sql.yacc"
    {SPRINTF4((yyval.str)," %s %s %s %s",(yyvsp[(1) - (4)].str),(yyvsp[(2) - (4)].str),(yyvsp[(3) - (4)].str),(yyvsp[(4) - (4)].str));}
    break;

  case 353:

/* Line 1455 of yacc.c  */
#line 2144 "sql.yacc"
    {add_feature("DDL_DOUBLE_PRECISION"); SPRINTF1((yyval.str)," %s",(yyvsp[(1) - (1)].str));}
    break;

  case 359:

/* Line 1455 of yacc.c  */
#line 2169 "sql.yacc"
    {(yyval.int_list.i0)=0;}
    break;

  case 360:

/* Line 1455 of yacc.c  */
#line 2170 "sql.yacc"
    {
		(yyval.int_list.i0)=1;
		(yyval.int_list.i1)=atoi((yyvsp[(2) - (3)].str));
	}
    break;

  case 361:

/* Line 1455 of yacc.c  */
#line 2174 "sql.yacc"
    {
		(yyval.int_list.i0)=2;
		(yyval.int_list.i1)=atoi((yyvsp[(2) - (5)].str));
		(yyval.int_list.i2)=atoi((yyvsp[(4) - (5)].str));
	}
    break;

  case 362:

/* Line 1455 of yacc.c  */
#line 2182 "sql.yacc"
    {
		strcpy((yyval.str),(yyvsp[(1) - (1)].str));
	}
    break;

  case 363:

/* Line 1455 of yacc.c  */
#line 2185 "sql.yacc"
    {
		strcpy((yyval.str),(yyvsp[(2) - (2)].str));
	}
    break;

  case 364:

/* Line 1455 of yacc.c  */
#line 2192 "sql.yacc"
    {
		(yyval.s_select_list_item)= (yyvsp[(1) - (1)].s_select_list_item);
	}
    break;

  case 365:

/* Line 1455 of yacc.c  */
#line 2195 "sql.yacc"
    {
		(yyval.s_select_list_item)= (yyvsp[(2) - (2)].s_select_list_item);
	}
    break;

  case 366:

/* Line 1455 of yacc.c  */
#line 2205 "sql.yacc"
    { 
		(yyval.s_select_list_item)=new_select_list_item_col(0,(yyvsp[(1) - (2)].str),&(yyvsp[(2) - (2)].int_list));
	}
    break;

  case 367:

/* Line 1455 of yacc.c  */
#line 2208 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_col((yyvsp[(1) - (4)].str),(yyvsp[(3) - (4)].str),&(yyvsp[(4) - (4)].int_list));
	}
    break;

  case 368:

/* Line 1455 of yacc.c  */
#line 2211 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_col((yyvsp[(1) - (3)].str),"*",0);
	}
    break;

  case 369:

/* Line 1455 of yacc.c  */
#line 2214 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_col(0,"rowid",0);
	}
    break;

  case 370:

/* Line 1455 of yacc.c  */
#line 2221 "sql.yacc"
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
#line 2228 "sql.yacc"
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
#line 2236 "sql.yacc"
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
#line 2245 "sql.yacc"
    {
		SPRINTF1((yyval.str),"%s",A4GLSQLCV_check_colname((yyvsp[(1) - (3)].str),"*"));
		ADDMAP("Use Column",(yyval.str));
	}
    break;

  case 375:

/* Line 1455 of yacc.c  */
#line 2256 "sql.yacc"
    { strcpy((yyval.str),(yyvsp[(1) - (1)].str)); A4GL_debug("Set $<str>$ to %s\n",(yyval.str)); }
    break;

  case 379:

/* Line 1455 of yacc.c  */
#line 2264 "sql.yacc"
    { strcpy((yyval.str),A4GLSQLCV_generate_current(0,0)); 
}
    break;

  case 380:

/* Line 1455 of yacc.c  */
#line 2266 "sql.yacc"
    {
		strcpy((yyval.str),A4GLSQLCV_generate_current((yyvsp[(1) - (3)].str),(yyvsp[(3) - (3)].str)));
	}
    break;

  case 395:

/* Line 1455 of yacc.c  */
#line 2276 "sql.yacc"
    {SPRINTF1((yyval.str),"FRACTION(%s)",(yyvsp[(3) - (4)].str));}
    break;

  case 396:

/* Line 1455 of yacc.c  */
#line 2291 "sql.yacc"
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
#line 2299 "sql.yacc"
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
#line 2311 "sql.yacc"
    { (yyval.sql_string)=make_sql_string_and_free(acl_strdup((yyvsp[(1) - (1)].str)), NULL);}
    break;

  case 399:

/* Line 1455 of yacc.c  */
#line 2312 "sql.yacc"
    { (yyval.sql_string)=make_sql_string_and_free(acl_strdup((yyvsp[(1) - (1)].str)), NULL);}
    break;

  case 400:

/* Line 1455 of yacc.c  */
#line 2313 "sql.yacc"
    { (yyval.sql_string)=make_sql_string_and_free(acl_strdup((yyvsp[(1) - (1)].str)), NULL);}
    break;

  case 401:

/* Line 1455 of yacc.c  */
#line 2314 "sql.yacc"
    { (yyval.sql_string)=make_sql_string_and_free(acl_strdup((yyvsp[(1) - (1)].str)), NULL);}
    break;

  case 402:

/* Line 1455 of yacc.c  */
#line 2319 "sql.yacc"
    { add_feature("RENAME_TABLE"); strcpy((yyval.str),A4GLSQLCV_rentab((yyvsp[(2) - (4)].str),(yyvsp[(4) - (4)].str))); }
    break;

  case 403:

/* Line 1455 of yacc.c  */
#line 2320 "sql.yacc"
    { add_feature("RENAME_COLUMN"); strcpy((yyval.str),A4GLSQLCV_rencol((yyvsp[(2) - (6)].str),(yyvsp[(4) - (6)].str),(yyvsp[(6) - (6)].str)) ); }
    break;

  case 406:

/* Line 1455 of yacc.c  */
#line 2328 "sql.yacc"
    {
		add_feature("UNLOCK_TABLE");
		SPRINTF2((yyval.str),"%s %s",(yyvsp[(1) - (2)].str),(yyvsp[(2) - (2)].str));
	}
    break;

  case 407:

/* Line 1455 of yacc.c  */
#line 2335 "sql.yacc"
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
#line 2346 "sql.yacc"
    { add_feature("LOCK_TABLE_SHARED");}
    break;

  case 409:

/* Line 1455 of yacc.c  */
#line 2347 "sql.yacc"
    {add_feature("LOCK_TABLE_EXCLUSIVE");}
    break;

  case 410:

/* Line 1455 of yacc.c  */
#line 2360 "sql.yacc"
    {strcpy((yyval.str),A4GLSQLCV_datetime_value((yyvsp[(1) - (1)].str)));}
    break;

  case 411:

/* Line 1455 of yacc.c  */
#line 2361 "sql.yacc"
    {strcpy((yyval.str),A4GLSQLCV_make_dtime_extend((yyvsp[(1) - (4)].str),(yyvsp[(2) - (4)].str),(yyvsp[(4) - (4)].str),0));}
    break;

  case 412:

/* Line 1455 of yacc.c  */
#line 2365 "sql.yacc"
    {strcpy((yyval.str),(yyvsp[(1) - (1)].str));}
    break;

  case 413:

/* Line 1455 of yacc.c  */
#line 2369 "sql.yacc"
    {strcpy((yyval.str),A4GLSQLCV_interval_value((yyvsp[(1) - (1)].str)));}
    break;

  case 414:

/* Line 1455 of yacc.c  */
#line 2370 "sql.yacc"
    {
			strcpy((yyval.str),A4GLSQLCV_make_ival_extend((yyvsp[(1) - (7)].str),(yyvsp[(2) - (7)].str),(yyvsp[(4) - (7)].str),(yyvsp[(7) - (7)].str),0));
		}
    break;

  case 415:

/* Line 1455 of yacc.c  */
#line 2373 "sql.yacc"
    {
		strcpy((yyval.str),A4GLSQLCV_make_ival_extend((yyvsp[(1) - (4)].str),(yyvsp[(2) - (4)].str),(char *)0, (yyvsp[(4) - (4)].str),0));
	}
    break;

  case 416:

/* Line 1455 of yacc.c  */
#line 2379 "sql.yacc"
    {SPRINTF1((yyval.str),"%s",(yyvsp[(1) - (1)].str));}
    break;

  case 417:

/* Line 1455 of yacc.c  */
#line 2383 "sql.yacc"
    {
	strcpy((yyval.str),(yyvsp[(2) - (2)].str));
}
    break;

  case 418:

/* Line 1455 of yacc.c  */
#line 2406 "sql.yacc"
    {
		(yyval.s_select_list_item_list)=(yyvsp[(3) - (3)].s_select_list_item_list);
		add_feature("ORDER_BY");
	}
    break;

  case 419:

/* Line 1455 of yacc.c  */
#line 2416 "sql.yacc"
    {
			(yyval.s_select_list_item_list)=local_new_select_list_item_list((yyvsp[(1) - (1)].s_select_list_item));
	}
    break;

  case 420:

/* Line 1455 of yacc.c  */
#line 2419 "sql.yacc"
    {
			(yyval.s_select_list_item_list)=local_add_select_list_item_list((yyvsp[(1) - (3)].s_select_list_item_list),(yyvsp[(3) - (3)].s_select_list_item));
	}
    break;

  case 421:

/* Line 1455 of yacc.c  */
#line 2425 "sql.yacc"
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
#line 2434 "sql.yacc"
    { 
		add_feature("ORDER_BY_NUMBER");
		(yyval.s_select_list_item)=new_select_list_item_literal((yyvsp[(1) - (1)].str));
	}
    break;

  case 423:

/* Line 1455 of yacc.c  */
#line 2438 "sql.yacc"
    {
		(yyval.s_select_list_item)=(yyvsp[(1) - (1)].s_select_list_item);
		(yyval.s_select_list_item)->data.type=E_SLI_COLUMN_ORDERBY;
	}
    break;

  case 424:

/* Line 1455 of yacc.c  */
#line 2445 "sql.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 425:

/* Line 1455 of yacc.c  */
#line 2447 "sql.yacc"
    {add_feature("ORDER_BY_ASC"); strcpy((yyval.str),"ASC");}
    break;

  case 426:

/* Line 1455 of yacc.c  */
#line 2449 "sql.yacc"
    {add_feature("ORDER_BY_DESC"); strcpy((yyval.str),"DESC");}
    break;

  case 427:

/* Line 1455 of yacc.c  */
#line 2453 "sql.yacc"
    {
		(yyval.s_select_list_item_list)=(yyvsp[(2) - (2)].s_select_list_item_list);
	}
    break;

  case 428:

/* Line 1455 of yacc.c  */
#line 2459 "sql.yacc"
    {
			(yyval.s_select_list_item_list)=local_new_select_list_item_list((yyvsp[(1) - (1)].s_select_list_item));
	}
    break;

  case 429:

/* Line 1455 of yacc.c  */
#line 2462 "sql.yacc"
    {
			(yyval.s_select_list_item_list)=local_add_select_list_item_list((yyvsp[(1) - (3)].s_select_list_item_list),(yyvsp[(3) - (3)].s_select_list_item));
	}
    break;

  case 430:

/* Line 1455 of yacc.c  */
#line 2468 "sql.yacc"
    { (yyval.s_select_list_item)=(yyvsp[(1) - (1)].s_select_list_item); }
    break;

  case 431:

/* Line 1455 of yacc.c  */
#line 2469 "sql.yacc"
    { (yyval.s_select_list_item)=new_select_list_item_literal((yyvsp[(1) - (1)].str)); }
    break;

  case 432:

/* Line 1455 of yacc.c  */
#line 2476 "sql.yacc"
    {
	(yyval.sql_string)=get_select_list_item(0,(yyvsp[(1) - (1)].s_select_list_item));
}
    break;

  case 433:

/* Line 1455 of yacc.c  */
#line 2489 "sql.yacc"
    {
		A4GL_set_sql_lineno(yylineno);
		(yyval.sql_string)=make_select_stmt_v2(current_upd_table, (yyvsp[(1) - (1)].s_select),"");
		map_select_stmt("SELECT",(yyvsp[(1) - (1)].s_select));
		A4GL_free_select_stmt((yyvsp[(1) - (1)].s_select));
}
    break;

  case 434:

/* Line 1455 of yacc.c  */
#line 2499 "sql.yacc"
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
#line 2506 "sql.yacc"
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
#line 2523 "sql.yacc"
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
#line 2530 "sql.yacc"
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
#line 2555 "sql.yacc"
    { 
		//start_bind('i',0);
		 set_ignore_indicators();}
    break;

  case 439:

/* Line 1455 of yacc.c  */
#line 2557 "sql.yacc"
    { clr_ignore_indicators();}
    break;

  case 440:

/* Line 1455 of yacc.c  */
#line 2559 "sql.yacc"
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
#line 2580 "sql.yacc"
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
#line 2623 "sql.yacc"
    { (yyval.s_select)=0;}
    break;

  case 443:

/* Line 1455 of yacc.c  */
#line 2624 "sql.yacc"
    { 
		(yyval.s_select)=(yyvsp[(3) - (3)].s_select);
		(yyval.s_select)->union_op=acl_strdup((yyvsp[(2) - (3)].str));
		A4GL_set_associated_mem((yyval.s_select), (yyval.s_select)->union_op);
		add_feature("SELECT_UNION"); 
	}
    break;

  case 444:

/* Line 1455 of yacc.c  */
#line 2638 "sql.yacc"
    {
		(yyval.s_select_finish)=0;
	}
    break;

  case 445:

/* Line 1455 of yacc.c  */
#line 2641 "sql.yacc"
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
#line 2648 "sql.yacc"
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
#line 2658 "sql.yacc"
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
#line 2676 "sql.yacc"
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
#line 2689 "sql.yacc"
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
#line 2704 "sql.yacc"
    {(yyval.integer_val)=-1;}
    break;

  case 452:

/* Line 1455 of yacc.c  */
#line 2706 "sql.yacc"
    {
		(yyval.integer_val)=atol((yyvsp[(2) - (2)].str));
	}
    break;

  case 453:

/* Line 1455 of yacc.c  */
#line 2712 "sql.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 454:

/* Line 1455 of yacc.c  */
#line 2713 "sql.yacc"
    {strcpy((yyval.str),"ALL"); add_feature("SELECT_ALL");}
    break;

  case 455:

/* Line 1455 of yacc.c  */
#line 2714 "sql.yacc"
    {strcpy((yyval.str),"DISTINCT"); add_feature("SELECT_DISTINCT");}
    break;

  case 456:

/* Line 1455 of yacc.c  */
#line 2715 "sql.yacc"
    {strcpy((yyval.str),"DISTINCT");
		add_feature("SELECT_UNIQUE");
		ansi_violation("Use DISTINCT not UNIQUE",0);
		strcpy((yyval.str),"DISTINCT");
	}
    break;

  case 457:

/* Line 1455 of yacc.c  */
#line 2725 "sql.yacc"
    { 
		 (yyval.s_select_list_item_list)=local_new_select_list_item_list((yyvsp[(1) - (1)].s_select_list_item));
	}
    break;

  case 458:

/* Line 1455 of yacc.c  */
#line 2728 "sql.yacc"
    { 
		(yyval.s_select_list_item_list)=local_add_select_list_item_list((yyvsp[(1) - (3)].s_select_list_item_list),(yyvsp[(3) - (3)].s_select_list_item));
	}
    break;

  case 459:

/* Line 1455 of yacc.c  */
#line 2734 "sql.yacc"
    {
		(yyval.s_select_list_item)=(yyvsp[(1) - (1)].s_select_list_item);
	}
    break;

  case 460:

/* Line 1455 of yacc.c  */
#line 2737 "sql.yacc"
    {
		(yyval.s_select_list_item)=(yyvsp[(1) - (2)].s_select_list_item);
		(yyval.s_select_list_item)->alias=acl_strdup((yyvsp[(2) - (2)].str));
		A4GL_set_associated_mem((yyval.s_select_list_item), (yyval.s_select_list_item)->alias);
	}
    break;

  case 461:

/* Line 1455 of yacc.c  */
#line 2742 "sql.yacc"
    {
		(yyval.s_select_list_item)=(yyvsp[(1) - (3)].s_select_list_item);
		(yyval.s_select_list_item)->alias=acl_strdup((yyvsp[(3) - (3)].str));
		A4GL_set_associated_mem((yyval.s_select_list_item), (yyval.s_select_list_item)->alias);
	}
    break;

  case 462:

/* Line 1455 of yacc.c  */
#line 2751 "sql.yacc"
    {
		(yyval.s_select_list_item)=(yyvsp[(1) - (1)].s_select_list_item); /* A4GLSQLCV_check_expr($<sql_string>1) */
	}
    break;

  case 463:

/* Line 1455 of yacc.c  */
#line 2754 "sql.yacc"
    {
		(yyval.s_select_list_item)=(yyvsp[(2) - (2)].s_select_list_item);
		(yyval.s_select_list_item)->sign='-';
	}
    break;

  case 464:

/* Line 1455 of yacc.c  */
#line 2758 "sql.yacc"
    {
		(yyval.s_select_list_item)=(yyvsp[(2) - (2)].s_select_list_item);
	}
    break;

  case 465:

/* Line 1455 of yacc.c  */
#line 2765 "sql.yacc"
    {
			(yyval.s_select_list_item)=new_select_list_item_op_expr ((yyvsp[(1) - (3)].s_select_list_item), (yyvsp[(3) - (3)].s_select_list_item), "/");
	}
    break;

  case 466:

/* Line 1455 of yacc.c  */
#line 2768 "sql.yacc"
    {
			(yyval.s_select_list_item)=new_select_list_item_simple_expr((enum e_sli)(yyvsp[(2) - (2)].integer_val), (yyvsp[(1) - (2)].s_select_list_item));
	}
    break;

  case 467:

/* Line 1455 of yacc.c  */
#line 2771 "sql.yacc"
    {
			(yyval.s_select_list_item)=new_select_list_item_op_expr ((yyvsp[(1) - (3)].s_select_list_item), (yyvsp[(3) - (3)].s_select_list_item), "*");
	}
    break;

  case 468:

/* Line 1455 of yacc.c  */
#line 2774 "sql.yacc"
    {
			(yyval.s_select_list_item)=new_select_list_item_op_expr ((yyvsp[(1) - (3)].s_select_list_item), (yyvsp[(3) - (3)].s_select_list_item), "+");
	}
    break;

  case 469:

/* Line 1455 of yacc.c  */
#line 2777 "sql.yacc"
    {
			(yyval.s_select_list_item)=new_select_list_item_op_expr ((yyvsp[(1) - (3)].s_select_list_item), (yyvsp[(3) - (3)].s_select_list_item), "-");
	}
    break;

  case 470:

/* Line 1455 of yacc.c  */
#line 2780 "sql.yacc"
    { (yyval.s_select_list_item)=new_select_list_item_literal((yyvsp[(1) - (1)].str)); }
    break;

  case 471:

/* Line 1455 of yacc.c  */
#line 2781 "sql.yacc"
    { (yyval.s_select_list_item)=new_select_list_item_builtin_const(E_SLI_BUILTIN_CONST_TRUE); }
    break;

  case 472:

/* Line 1455 of yacc.c  */
#line 2782 "sql.yacc"
    { (yyval.s_select_list_item)=new_select_list_item_builtin_const(E_SLI_BUILTIN_CONST_FALSE); }
    break;

  case 473:

/* Line 1455 of yacc.c  */
#line 2783 "sql.yacc"
    { (yyval.s_select_list_item)=new_select_list_item_builtin_const(E_SLI_BUILTIN_CONST_USER); }
    break;

  case 474:

/* Line 1455 of yacc.c  */
#line 2784 "sql.yacc"
    { (yyval.s_select_list_item)=new_select_list_item_builtin_const(E_SLI_BUILTIN_CONST_TODAY); }
    break;

  case 475:

/* Line 1455 of yacc.c  */
#line 2785 "sql.yacc"
    { (yyval.s_select_list_item)=new_select_list_item_builtin_const(E_SLI_BUILTIN_CONST_ROWID); }
    break;

  case 476:

/* Line 1455 of yacc.c  */
#line 2786 "sql.yacc"
    { (yyval.s_select_list_item)=new_select_list_item_builtin_const(E_SLI_BUILTIN_CONST_TIME); }
    break;

  case 477:

/* Line 1455 of yacc.c  */
#line 2787 "sql.yacc"
    { (yyval.s_select_list_item)=new_select_list_item_builtin_const(E_SLI_BUILTIN_CONST_STAR); }
    break;

  case 478:

/* Line 1455 of yacc.c  */
#line 2788 "sql.yacc"
    { (yyval.s_select_list_item)=new_select_list_item_builtin_const(E_SLI_BUILTIN_CONST_COUNT_STAR); }
    break;

  case 479:

/* Line 1455 of yacc.c  */
#line 2790 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_agg1(E_SLI_BUILTIN_AGG_AVG,(yyvsp[(3) - (5)].str),(yyvsp[(4) - (5)].s_select_list_item));
		add_feature("SELECT_AVG");
	}
    break;

  case 480:

/* Line 1455 of yacc.c  */
#line 2794 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_agg1(E_SLI_BUILTIN_AGG_MAX,(yyvsp[(3) - (5)].str),(yyvsp[(4) - (5)].s_select_list_item));
		add_feature("SELECT_MAX");
	}
    break;

  case 481:

/* Line 1455 of yacc.c  */
#line 2798 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_agg1(E_SLI_BUILTIN_AGG_MIN,(yyvsp[(3) - (5)].str),(yyvsp[(4) - (5)].s_select_list_item));
		add_feature("SELECT_MIN");
	}
    break;

  case 482:

/* Line 1455 of yacc.c  */
#line 2802 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_agg1(E_SLI_BUILTIN_AGG_SUM,(yyvsp[(3) - (5)].str),(yyvsp[(4) - (5)].s_select_list_item));
		add_feature("SELECT_SUM");
	}
    break;

  case 483:

/* Line 1455 of yacc.c  */
#line 2806 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_agg1(E_SLI_BUILTIN_AGG_COUNT,(yyvsp[(3) - (5)].str),(yyvsp[(4) - (5)].s_select_list_item));
		add_feature("SELECT_COUNT");
	}
    break;

  case 484:

/* Line 1455 of yacc.c  */
#line 2810 "sql.yacc"
    {
		add_sql_function((yyvsp[(1) - (3)].str));
		(yyval.s_select_list_item)=new_select_list_item_fcall((yyvsp[(1) - (3)].str),0);
	}
    break;

  case 485:

/* Line 1455 of yacc.c  */
#line 2814 "sql.yacc"
    {
		add_sql_function((yyvsp[(1) - (4)].str));
		(yyval.s_select_list_item)=new_select_list_item_fcall((yyvsp[(1) - (4)].str),(yyvsp[(3) - (4)].s_select_list_item_list));
	}
    break;

  case 486:

/* Line 1455 of yacc.c  */
#line 2818 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_builtin_fcall(E_SLI_BUILTIN_FUNC_YEAR,(yyvsp[(3) - (4)].s_select_list_item_list));
	}
    break;

  case 487:

/* Line 1455 of yacc.c  */
#line 2821 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_builtin_fcall(E_SLI_BUILTIN_FUNC_MONTH,(yyvsp[(3) - (4)].s_select_list_item_list));
	}
    break;

  case 488:

/* Line 1455 of yacc.c  */
#line 2824 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_builtin_fcall(E_SLI_BUILTIN_FUNC_DAY,(yyvsp[(3) - (4)].s_select_list_item_list));
	}
    break;

  case 489:

/* Line 1455 of yacc.c  */
#line 2827 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_builtin_fcall(E_SLI_BUILTIN_FUNC_MDY,(yyvsp[(3) - (4)].s_select_list_item_list));
	}
    break;

  case 490:

/* Line 1455 of yacc.c  */
#line 2830 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_builtin_fcall(E_SLI_BUILTIN_FUNC_WEEKDAY,(yyvsp[(3) - (4)].s_select_list_item_list));
	}
    break;

  case 491:

/* Line 1455 of yacc.c  */
#line 2833 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_builtin_fcall(E_SLI_BUILTIN_FUNC_DOW,(yyvsp[(3) - (4)].s_select_list_item_list));
	}
    break;

  case 492:

/* Line 1455 of yacc.c  */
#line 2836 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_builtin_fcall(E_SLI_BUILTIN_FUNC_DATE,(yyvsp[(3) - (4)].s_select_list_item_list));
	}
    break;

  case 493:

/* Line 1455 of yacc.c  */
#line 2839 "sql.yacc"
    {
		  (yyval.s_select_list_item)=new_select_list_item_simple_expr(E_SLI_BRACKET_EXPR,(yyvsp[(2) - (3)].s_select_list_item));
	}
    break;

  case 494:

/* Line 1455 of yacc.c  */
#line 2842 "sql.yacc"
    { 
		add_feature("EXTEND"); 
		(yyval.s_select_list_item)=(yyvsp[(3) - (4)].s_select_list_item);
	}
    break;

  case 495:

/* Line 1455 of yacc.c  */
#line 2846 "sql.yacc"
    { 
		(yyval.s_select_list_item)=new_select_list_item_datetime((yyvsp[(1) - (1)].str));
		add_feature("FUNC_DATETIME");
	}
    break;

  case 496:

/* Line 1455 of yacc.c  */
#line 2850 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_interval((yyvsp[(1) - (1)].str));
		add_feature("FUNC_INTERVAL");
	}
    break;

  case 497:

/* Line 1455 of yacc.c  */
#line 2854 "sql.yacc"
    {
		(yyval.s_select_list_item)=(yyvsp[(2) - (3)].s_select_list_item);
	}
    break;

  case 498:

/* Line 1455 of yacc.c  */
#line 2862 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_case((yyvsp[(1) - (1)].s_select_list_item));
	}
    break;

  case 499:

/* Line 1455 of yacc.c  */
#line 2865 "sql.yacc"
    {
		(yyval.s_select_list_item)=append_select_list_item_case(
							(yyvsp[(1) - (2)].s_select_list_item),
							(yyvsp[(2) - (2)].s_select_list_item));
	}
    break;

  case 500:

/* Line 1455 of yacc.c  */
#line 2874 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_case_element(
				(yyvsp[(2) - (4)].s_select_list_item),
				(yyvsp[(4) - (4)].s_select_list_item));

	}
    break;

  case 501:

/* Line 1455 of yacc.c  */
#line 2880 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_case_element( 0, (yyvsp[(2) - (2)].s_select_list_item));
	}
    break;

  case 502:

/* Line 1455 of yacc.c  */
#line 2887 "sql.yacc"
    {
		(yyval.s_select_list_item_list)=local_new_select_list_item_list((yyvsp[(1) - (1)].s_select_list_item));
	}
    break;

  case 503:

/* Line 1455 of yacc.c  */
#line 2890 "sql.yacc"
    {
			(yyval.s_select_list_item_list)=local_add_select_list_item_list((yyvsp[(1) - (3)].s_select_list_item_list),(yyvsp[(3) - (3)].s_select_list_item));
	}
    break;

  case 504:

/* Line 1455 of yacc.c  */
#line 2918 "sql.yacc"
    {
			(yyval.s_select_list_item)=new_select_list_item_extend(new_select_list_item_builtin_const(E_SLI_BUILTIN_CONST_CURRENT),(yyvsp[(3) - (5)].str),(yyvsp[(5) - (5)].str));
	}
    break;

  case 505:

/* Line 1455 of yacc.c  */
#line 2921 "sql.yacc"
    {
			(yyval.s_select_list_item)=new_select_list_item_extend((yyvsp[(1) - (5)].s_select_list_item),(yyvsp[(3) - (5)].str),(yyvsp[(5) - (5)].str));
	}
    break;

  case 506:

/* Line 1455 of yacc.c  */
#line 2924 "sql.yacc"
    {
			(yyval.s_select_list_item)=new_select_list_item_extend(new_select_list_item_builtin_const(E_SLI_BUILTIN_CONST_CURRENT),(yyvsp[(2) - (4)].str),(yyvsp[(4) - (4)].str));
	}
    break;

  case 507:

/* Line 1455 of yacc.c  */
#line 2927 "sql.yacc"
    {
			(yyval.s_select_list_item)=new_select_list_item_extend((yyvsp[(1) - (5)].s_select_list_item),(yyvsp[(3) - (5)].str),(yyvsp[(5) - (5)].str));
	}
    break;

  case 508:

/* Line 1455 of yacc.c  */
#line 2933 "sql.yacc"
    {(yyval.integer_val)=E_SLI_UNITS_YEAR;}
    break;

  case 509:

/* Line 1455 of yacc.c  */
#line 2934 "sql.yacc"
    {(yyval.integer_val)=E_SLI_UNITS_MONTH;}
    break;

  case 510:

/* Line 1455 of yacc.c  */
#line 2935 "sql.yacc"
    {(yyval.integer_val)=E_SLI_UNITS_DAY;}
    break;

  case 511:

/* Line 1455 of yacc.c  */
#line 2936 "sql.yacc"
    {(yyval.integer_val)=E_SLI_UNITS_HOUR;}
    break;

  case 512:

/* Line 1455 of yacc.c  */
#line 2937 "sql.yacc"
    {(yyval.integer_val)=E_SLI_UNITS_MINUTE;}
    break;

  case 513:

/* Line 1455 of yacc.c  */
#line 2938 "sql.yacc"
    {(yyval.integer_val)=E_SLI_UNITS_SECOND;}
    break;

  case 514:

/* Line 1455 of yacc.c  */
#line 2943 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_op_slil((yyvsp[(1) - (5)].s_select_list_item),(yyvsp[(4) - (5)].s_select_list_item_list),E_SLI_IN_VALUES);
                add_feature("WHERE_IN");
        }
    break;

  case 515:

/* Line 1455 of yacc.c  */
#line 2947 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_op_sli((yyvsp[(1) - (3)].s_select_list_item),(yyvsp[(3) - (3)].s_select_list_item),E_SLI_IN_SELECT);
                add_feature("WHERE_IN_SELECT");
        }
    break;

  case 516:

/* Line 1455 of yacc.c  */
#line 2951 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_op_slil((yyvsp[(1) - (5)].s_select_list_item),(yyvsp[(4) - (5)].s_select_list_item_list),E_SLI_NOT_IN_VALUES);
                add_feature("WHERE_IN");
        }
    break;

  case 517:

/* Line 1455 of yacc.c  */
#line 2955 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_op_sli((yyvsp[(1) - (3)].s_select_list_item),(yyvsp[(3) - (3)].s_select_list_item),E_SLI_NOT_IN_SELECT);
                add_feature("WHERE_IN_SELECT");
        }
    break;

  case 518:

/* Line 1455 of yacc.c  */
#line 2962 "sql.yacc"
    {
		(yyval.s_select_list_item_list)=local_new_select_list_item_list((yyvsp[(1) - (1)].s_select_list_item));
	}
    break;

  case 519:

/* Line 1455 of yacc.c  */
#line 2965 "sql.yacc"
    {
                (yyval.s_select_list_item_list)=local_add_select_list_item_list((yyvsp[(1) - (3)].s_select_list_item_list),(yyvsp[(3) - (3)].s_select_list_item));
	}
    break;

  case 520:

/* Line 1455 of yacc.c  */
#line 2970 "sql.yacc"
    { (yyval.s_select_list_item)=(yyvsp[(1) - (1)].s_select_list_item);}
    break;

  case 521:

/* Line 1455 of yacc.c  */
#line 2971 "sql.yacc"
    { (yyval.s_select_list_item)=new_select_list_item_literal((yyvsp[(1) - (1)].str)); }
    break;

  case 522:

/* Line 1455 of yacc.c  */
#line 2972 "sql.yacc"
    { 
		char buff[256]; SPRINTF1(buff," -%s",(yyvsp[(2) - (2)].str)); (yyval.s_select_list_item)=new_select_list_item_literal(buff); }
    break;

  case 523:

/* Line 1455 of yacc.c  */
#line 2974 "sql.yacc"
    { char buff[256]; SPRINTF1(buff," -%s",(yyvsp[(2) - (2)].str)); (yyval.s_select_list_item)=new_select_list_item_literal(buff); }
    break;

  case 524:

/* Line 1455 of yacc.c  */
#line 2980 "sql.yacc"
    {
                if (strstr((yyvsp[(1) - (1)].str),"systables")!=0) { add_feature("IFX_SYSTABLES"); }
                if (strstr((yyvsp[(1) - (1)].str),"syscolumns")!=0) { add_feature("IFX_SYSCOLUMNS"); }
                if (strstr((yyvsp[(1) - (1)].str),"sysindexes")!=0) { add_feature("IFX_SYSINDEXES"); }
                strcpy((yyval.str),A4GLSQLCV_check_tablename((yyvsp[(1) - (1)].str)));
                }
    break;

  case 525:

/* Line 1455 of yacc.c  */
#line 2990 "sql.yacc"
    {
	     SPRINTF1((yyval.str),"%s", A4GLSQLCV_ownerize_tablename(NULL, A4GL_strip_quotes((yyvsp[(1) - (1)].str))));
             ADDMAP("Use Table",(yyval.str));
        }
    break;

  case 526:

/* Line 1455 of yacc.c  */
#line 2994 "sql.yacc"
    {
	     SPRINTF1((yyval.str),"%s", A4GLSQLCV_ownerize_tablename((yyvsp[(1) - (3)].str), (yyvsp[(3) - (3)].str)));
	     ADDMAP("Use Table",(yyval.str));
        }
    break;

  case 527:

/* Line 1455 of yacc.c  */
#line 2998 "sql.yacc"
    {
	     SPRINTF1((yyval.str),"%s", A4GLSQLCV_ownerize_tablename(NULL, (yyvsp[(1) - (1)].str)));
	     ADDMAP("Use Table",(yyval.str));
	}
    break;

  case 528:

/* Line 1455 of yacc.c  */
#line 3002 "sql.yacc"
    {
	     SPRINTF1((yyval.str),"%s", A4GLSQLCV_db_tablename((yyvsp[(1) - (3)].str), NULL, A4GLSQLCV_ownerize_tablename(NULL, (yyvsp[(3) - (3)].str))));
	     ADDMAP("Use Table",(yyval.str));
	}
    break;

  case 529:

/* Line 1455 of yacc.c  */
#line 3006 "sql.yacc"
    {
	     SPRINTF1((yyval.str),"%s", A4GLSQLCV_db_tablename((yyvsp[(1) - (5)].str), NULL, A4GLSQLCV_ownerize_tablename((yyvsp[(3) - (5)].str),(yyvsp[(5) - (5)].str))));
	     ADDMAP("Use Table",(yyval.str));
        }
    break;

  case 530:

/* Line 1455 of yacc.c  */
#line 3010 "sql.yacc"
    {
	     SPRINTF1((yyval.str),"%s", A4GLSQLCV_db_tablename(NULL,(yyvsp[(1) - (3)].str), A4GLSQLCV_ownerize_tablename(NULL, (yyvsp[(3) - (3)].str))));
	     ADDMAP("Use Table",(yyval.str));
	}
    break;

  case 531:

/* Line 1455 of yacc.c  */
#line 3014 "sql.yacc"
    {
	     SPRINTF1((yyval.str),"%s", A4GLSQLCV_db_tablename((yyvsp[(1) - (5)].str), (yyvsp[(3) - (5)].str), A4GLSQLCV_ownerize_tablename(NULL, (yyvsp[(5) - (5)].str))));
	     ADDMAP("Use Table",(yyval.str));
	}
    break;

  case 532:

/* Line 1455 of yacc.c  */
#line 3018 "sql.yacc"
    {
	     SPRINTF1((yyval.str),"%s", A4GLSQLCV_db_tablename((yyvsp[(1) - (7)].str), (yyvsp[(3) - (7)].str), A4GLSQLCV_ownerize_tablename((yyvsp[(5) - (7)].str), (yyvsp[(7) - (7)].str))));
	     ADDMAP("Use Table",(yyval.str));
        }
    break;

  case 533:

/* Line 1455 of yacc.c  */
#line 3026 "sql.yacc"
    {
                if (strstr((yyvsp[(1) - (1)].str),"systables")!=0) { add_feature("IFX_SYSTABLES"); }
                if (strstr((yyvsp[(1) - (1)].str),"syscolumns")!=0) { add_feature("IFX_SYSCOLUMNS"); }
                if (strstr((yyvsp[(1) - (1)].str),"sysindexes")!=0) { add_feature("IFX_SYSINDEXES"); }
                strcpy((yyval.str),A4GLSQLCV_check_tablename((yyvsp[(1) - (1)].str)));
                }
    break;

  case 534:

/* Line 1455 of yacc.c  */
#line 3036 "sql.yacc"
    {

	     SPRINTF1((yyval.str),"%s", A4GLSQLCV_ownerize_tablename((yyvsp[(1) - (3)].str), (yyvsp[(3) - (3)].str)));
	     ADDMAP("Use Table",(yyval.str));
        }
    break;

  case 535:

/* Line 1455 of yacc.c  */
#line 3041 "sql.yacc"
    {
	     SPRINTF1((yyval.str),"%s", A4GLSQLCV_ownerize_tablename((yyvsp[(1) - (3)].str), (yyvsp[(3) - (3)].str)));
	     ADDMAP("Use Table",(yyval.str));
        }
    break;

  case 536:

/* Line 1455 of yacc.c  */
#line 3045 "sql.yacc"
    {
	     SPRINTF1((yyval.str),"%s", A4GLSQLCV_ownerize_tablename(NULL, A4GL_strip_quotes((yyvsp[(1) - (1)].str))));
	     ADDMAP("Use Table",(yyval.str));
        }
    break;

  case 537:

/* Line 1455 of yacc.c  */
#line 3049 "sql.yacc"
    {
             SPRINTF1((yyval.str),"%s", A4GLSQLCV_ownerize_tablename(NULL, (yyvsp[(1) - (1)].str)));
	     ADDMAP("Use Table",(yyval.str));
	}
    break;

  case 538:

/* Line 1455 of yacc.c  */
#line 3053 "sql.yacc"
    {
             SPRINTF1((yyval.str),"%s", A4GLSQLCV_db_tablename((yyvsp[(1) - (3)].str),NULL, A4GLSQLCV_ownerize_tablename(NULL, (yyvsp[(3) - (3)].str))));
	     ADDMAP("Use Table",(yyval.str));
	}
    break;

  case 539:

/* Line 1455 of yacc.c  */
#line 3057 "sql.yacc"
    {
	     SPRINTF1((yyval.str),"%s", A4GLSQLCV_db_tablename((yyvsp[(1) - (5)].str), NULL,A4GLSQLCV_ownerize_tablename((yyvsp[(3) - (5)].str), (yyvsp[(5) - (5)].str))));
	     ADDMAP("Use Table",(yyval.str));
        }
    break;

  case 540:

/* Line 1455 of yacc.c  */
#line 3062 "sql.yacc"
    {
             SPRINTF1((yyval.str),"%s", A4GLSQLCV_db_tablename(NULL, (yyvsp[(1) - (3)].str), A4GLSQLCV_ownerize_tablename(NULL, (yyvsp[(3) - (3)].str))));
	     ADDMAP("Use Table",(yyval.str));
	}
    break;

  case 541:

/* Line 1455 of yacc.c  */
#line 3066 "sql.yacc"
    {
            SPRINTF1((yyval.str),"%s", A4GLSQLCV_db_tablename( (yyvsp[(1) - (5)].str), (yyvsp[(3) - (5)].str), A4GLSQLCV_ownerize_tablename(NULL, (yyvsp[(5) - (5)].str))));
	    ADDMAP("Use Table",(yyval.str));
	}
    break;

  case 542:

/* Line 1455 of yacc.c  */
#line 3070 "sql.yacc"
    {
	     SPRINTF1((yyval.str),"%s", A4GLSQLCV_db_tablename((yyvsp[(1) - (7)].str), (yyvsp[(3) - (7)].str), A4GLSQLCV_ownerize_tablename((yyvsp[(5) - (7)].str), (yyvsp[(7) - (7)].str))));
	     ADDMAP("Use Table",(yyval.str));
        }
    break;

  case 543:

/* Line 1455 of yacc.c  */
#line 3078 "sql.yacc"
    {
	     SPRINTF1((yyval.str),"%s", A4GLSQLCV_ownerize_tablename((yyvsp[(1) - (3)].str), (yyvsp[(3) - (3)].str)));
        }
    break;

  case 544:

/* Line 1455 of yacc.c  */
#line 3081 "sql.yacc"
    {
	        SPRINTF1((yyval.str),"%s", A4GLSQLCV_ownerize_tablename(NULL, (yyvsp[(1) - (1)].str)));
                ADDMAP("Use Index",(yyval.str));
        }
    break;

  case 545:

/* Line 1455 of yacc.c  */
#line 3086 "sql.yacc"
    {strcpy((yyval.str),(yyvsp[(1) - (1)].str)); ADDMAP("Use Index",(yyvsp[(1) - (1)].str)); }
    break;

  case 546:

/* Line 1455 of yacc.c  */
#line 3087 "sql.yacc"
    { SPRINTF3((yyval.str),"%s%s%s",(yyvsp[(1) - (3)].str),(yyvsp[(2) - (3)].str),(yyvsp[(3) - (3)].str)); ADDMAP("Use Index",(yyval.str)); }
    break;

  case 547:

/* Line 1455 of yacc.c  */
#line 3088 "sql.yacc"
    {
	     SPRINTF2((yyval.str),"%s:%s", (yyvsp[(1) - (5)].str), A4GLSQLCV_ownerize_tablename((yyvsp[(3) - (5)].str), (yyvsp[(5) - (5)].str)));
             ADDMAP("Use Index",(yyval.str));
        }
    break;

  case 548:

/* Line 1455 of yacc.c  */
#line 3093 "sql.yacc"
    {strcpy((yyval.str),(yyvsp[(1) - (3)].str)); ADDMAP("Use Index",(yyvsp[(1) - (3)].str)); }
    break;

  case 549:

/* Line 1455 of yacc.c  */
#line 3094 "sql.yacc"
    { SPRINTF4((yyval.str),"%s@%s%s%s",(yyvsp[(1) - (5)].str),(yyvsp[(3) - (5)].str),(yyvsp[(4) - (5)].str),(yyvsp[(5) - (5)].str)); ADDMAP("Use Index",(yyval.str)); }
    break;

  case 550:

/* Line 1455 of yacc.c  */
#line 3095 "sql.yacc"
    {
	     SPRINTF3((yyval.str),"%s@%s:%s", (yyvsp[(1) - (7)].str), (yyvsp[(3) - (7)].str), A4GLSQLCV_ownerize_tablename((yyvsp[(5) - (7)].str), (yyvsp[(7) - (7)].str)));
             ADDMAP("Use Index",(yyval.str));
        }
    break;

  case 552:

/* Line 1455 of yacc.c  */
#line 3106 "sql.yacc"
    {
                      (yyval.ptr)=A4GL_new_expr_simple_string(A4GL_get_clobbered_from((yyval.str)), ET_EXPR_IDENTIFIER);
	}
    break;

  case 554:

/* Line 1455 of yacc.c  */
#line 3112 "sql.yacc"
    { sprintf((yyval.str),".%s",(yyvsp[(2) - (2)].str)); }
    break;

  case 556:

/* Line 1455 of yacc.c  */
#line 3117 "sql.yacc"
    {strcpy((yyval.str), A4GL_strip_quotes ((yyvsp[(1) - (1)].str)));}
    break;

  case 561:

/* Line 1455 of yacc.c  */
#line 3168 "sql.yacc"
    {
			int converted;
			(yyval.sql_string)=get_insert_cmd((yyvsp[(1) - (1)].insert_cmd),&converted);
			A4GL_free_associated_mem((yyvsp[(1) - (1)].insert_cmd));
			acl_free((yyvsp[(1) - (1)].insert_cmd));

		}
    break;

  case 562:

/* Line 1455 of yacc.c  */
#line 3175 "sql.yacc"
    {
			int converted;
			(yyval.sql_string)=get_update_cmd((yyvsp[(1) - (1)].update_cmd),&converted);
			A4GL_free_associated_mem((yyvsp[(1) - (1)].update_cmd));
			acl_free((yyvsp[(1) - (1)].update_cmd));
		}
    break;

  case 563:

/* Line 1455 of yacc.c  */
#line 3181 "sql.yacc"
    {
			int converted;
			(yyval.sql_string)=get_delete_cmd((yyvsp[(1) - (1)].delete_cmd),&converted);
			A4GL_free_associated_mem((yyvsp[(1) - (1)].delete_cmd));
			acl_free((yyvsp[(1) - (1)].delete_cmd));
		}
    break;

  case 566:

/* Line 1455 of yacc.c  */
#line 3196 "sql.yacc"
    { print_exec_select((yyvsp[(1) - (1)].sql_string));  }
    break;

  case 567:

/* Line 1455 of yacc.c  */
#line 3197 "sql.yacc"
    { print_exec_select((yyvsp[(1) - (1)].sql_string));  }
    break;

  case 569:

/* Line 1455 of yacc.c  */
#line 3199 "sql.yacc"
    { print_exec_select((yyvsp[(1) - (1)].sql_string));  }
    break;

  case 570:

/* Line 1455 of yacc.c  */
#line 3201 "sql.yacc"
    {
			print_sql_commit ((yyvsp[(1) - (1)].integer_val));
	}
    break;

  case 571:

/* Line 1455 of yacc.c  */
#line 3204 "sql.yacc"
    {print_unable_to_parse();}
    break;

  case 572:

/* Line 1455 of yacc.c  */
#line 3208 "sql.yacc"
    { (yyval.sql_string)=make_sql_string_and_free((yyvsp[(1) - (2)].sql_string),acl_strdup((yyvsp[(2) - (2)].str)),0);
}
    break;

  case 574:

/* Line 1455 of yacc.c  */
#line 3217 "sql.yacc"
    {
			(yyval.sql_string)=make_select_stmt_v2("", (yyvsp[(1) - (1)].s_select),"");
			A4GL_free_select_stmt((yyvsp[(1) - (1)].s_select));
		}
    break;

  case 575:

/* Line 1455 of yacc.c  */
#line 3223 "sql.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 576:

/* Line 1455 of yacc.c  */
#line 3224 "sql.yacc"
    {
			strcpy((yyval.str),A4GLSQLCV_get_forupdate(NULL));
		}
    break;

  case 577:

/* Line 1455 of yacc.c  */
#line 3227 "sql.yacc"
    {
			strcpy((yyval.str),A4GLSQLCV_get_forupdate((yyvsp[(2) - (2)].str)));
		}
    break;

  case 578:

/* Line 1455 of yacc.c  */
#line 3232 "sql.yacc"
    { strcpy((yyval.str),(yyvsp[(1) - (1)].str)); }
    break;

  case 579:

/* Line 1455 of yacc.c  */
#line 3233 "sql.yacc"
    { sprintf((yyval.str),"%s,%s",(yyvsp[(1) - (3)].str),(yyvsp[(3) - (3)].str)); }
    break;

  case 581:

/* Line 1455 of yacc.c  */
#line 3237 "sql.yacc"
    {sprintf((yyval.str),"%s.%s",A4GLSQLCV_ownerize_tablename(NULL, (yyvsp[(1) - (3)].str)),(yyvsp[(3) - (3)].str));}
    break;

  case 582:

/* Line 1455 of yacc.c  */
#line 3238 "sql.yacc"
    {
        sprintf((yyval.str),"%s.%s", A4GLSQLCV_ownerize_tablename((yyvsp[(1) - (5)].str), (yyvsp[(3) - (5)].str)), (yyvsp[(5) - (5)].str));
}
    break;

  case 583:

/* Line 1455 of yacc.c  */
#line 3248 "sql.yacc"
    { print_exec_sql(acl_strdup((yyvsp[(1) - (1)].str))); }
    break;

  case 584:

/* Line 1455 of yacc.c  */
#line 3249 "sql.yacc"
    { print_exec_sql(acl_strdup((yyvsp[(1) - (1)].str))); }
    break;

  case 585:

/* Line 1455 of yacc.c  */
#line 3250 "sql.yacc"
    { sprintf((yyval.str),"%s %s",(yyvsp[(1) - (2)].str),(yyvsp[(2) - (2)].str)); print_exec_sql(acl_strdup((yyval.str))); }
    break;

  case 586:

/* Line 1455 of yacc.c  */
#line 3251 "sql.yacc"
    { print_exec_sql(acl_strdup((yyvsp[(1) - (1)].str))); }
    break;

  case 587:

/* Line 1455 of yacc.c  */
#line 3252 "sql.yacc"
    { print_exec_sql(acl_strdup((yyvsp[(1) - (1)].str))); }
    break;

  case 588:

/* Line 1455 of yacc.c  */
#line 3253 "sql.yacc"
    { print_exec_sql(acl_strdup((yyvsp[(1) - (1)].str))); }
    break;

  case 589:

/* Line 1455 of yacc.c  */
#line 3254 "sql.yacc"
    { print_exec_sql(acl_strdup((yyvsp[(1) - (1)].str))); }
    break;

  case 590:

/* Line 1455 of yacc.c  */
#line 3255 "sql.yacc"
    { print_exec_sql(acl_strdup((yyvsp[(1) - (1)].str))); }
    break;

  case 591:

/* Line 1455 of yacc.c  */
#line 3259 "sql.yacc"
    { 
	char *s;
	s=acl_strdup((yyvsp[(1) - (1)].str));
	(yyval.s_select_list_item)=new_select_list_item_column_from_transform(s);
	acl_free(s);
	}
    break;

  case 592:

/* Line 1455 of yacc.c  */
#line 3265 "sql.yacc"
    {  
		(yyval.s_select_list_item)=new_select_list_item_builtin_const(E_SLI_QUERY_PLACEHOLDER);}
    break;

  case 593:

/* Line 1455 of yacc.c  */
#line 3267 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_replace_var((yyvsp[(1) - (1)].sql_string));
	}
    break;

  case 594:

/* Line 1455 of yacc.c  */
#line 3286 "sql.yacc"
    {
        add_feature("DATABASE_USED");
       conn_db((yyvsp[(2) - (3)].str));
}
    break;

  case 595:

/* Line 1455 of yacc.c  */
#line 3294 "sql.yacc"
    {
		(yyval.sql_string)=acl_strdup((yyvsp[(2) - (3)].str));
}
    break;

  case 596:

/* Line 1455 of yacc.c  */
#line 3301 "sql.yacc"
    {sprintf((yyval.str),"(%s)",(yyvsp[(2) - (3)].str));}
    break;

  case 597:

/* Line 1455 of yacc.c  */
#line 3302 "sql.yacc"
    { sprintf((yyval.str),"%s%s%s",(yyvsp[(1) - (3)].str),(yyvsp[(2) - (3)].str),(yyvsp[(3) - (3)].str));}
    break;

  case 598:

/* Line 1455 of yacc.c  */
#line 3303 "sql.yacc"
    {sprintf((yyval.str),"%d",atoi((yyvsp[(1) - (1)].str)));}
    break;

  case 599:

/* Line 1455 of yacc.c  */
#line 3304 "sql.yacc"
    {sprintf((yyval.str),"(%s%s)",(yyvsp[(1) - (2)].str),(yyvsp[(2) - (2)].str));}
    break;

  case 600:

/* Line 1455 of yacc.c  */
#line 3309 "sql.yacc"
    {strcpy((yyval.str),"+");}
    break;

  case 601:

/* Line 1455 of yacc.c  */
#line 3310 "sql.yacc"
    {strcpy((yyval.str),"-");}
    break;

  case 602:

/* Line 1455 of yacc.c  */
#line 3311 "sql.yacc"
    {strcpy((yyval.str),"*");}
    break;

  case 603:

/* Line 1455 of yacc.c  */
#line 3312 "sql.yacc"
    {strcpy((yyval.str),"/");}
    break;

  case 604:

/* Line 1455 of yacc.c  */
#line 3313 "sql.yacc"
    {strcpy((yyval.str),"%");}
    break;

  case 605:

/* Line 1455 of yacc.c  */
#line 3318 "sql.yacc"
    {strcpy((yyval.str),"+");}
    break;

  case 606:

/* Line 1455 of yacc.c  */
#line 3319 "sql.yacc"
    {strcpy((yyval.str),"-");}
    break;

  case 607:

/* Line 1455 of yacc.c  */
#line 3335 "sql.yacc"
    {sprintf((yyval.str),"%s", A4GLSQLCV_check_tablename((yyvsp[(1) - (1)].str)));}
    break;

  case 608:

/* Line 1455 of yacc.c  */
#line 3336 "sql.yacc"
    {sprintf((yyval.str),"%s.*", A4GLSQLCV_ownerize_tablename(NULL,(yyvsp[(1) - (3)].str)));}
    break;

  case 609:

/* Line 1455 of yacc.c  */
#line 3337 "sql.yacc"
    {sprintf((yyval.str),"%s.%s", (yyvsp[(1) - (3)].str),A4GLSQLCV_get_sqlconst ("rowid"));}
    break;

  case 610:

/* Line 1455 of yacc.c  */
#line 3338 "sql.yacc"
    {sprintf((yyval.str),"%s.%s", A4GLSQLCV_ownerize_tablename(NULL,(yyvsp[(1) - (3)].str)),(yyvsp[(3) - (3)].str));}
    break;

  case 611:

/* Line 1455 of yacc.c  */
#line 3339 "sql.yacc"
    {sprintf((yyval.str),"%s.%s", A4GLSQLCV_ownerize_tablename((yyvsp[(1) - (5)].str),(yyvsp[(3) - (5)].str)),(yyvsp[(5) - (5)].str));}
    break;

  case 612:

/* Line 1455 of yacc.c  */
#line 3340 "sql.yacc"
    {sprintf((yyval.str),"%s.%s", A4GLSQLCV_ownerize_tablename((yyvsp[(1) - (5)].str),(yyvsp[(3) - (5)].str)),(yyvsp[(5) - (5)].str));}
    break;

  case 613:

/* Line 1455 of yacc.c  */
#line 3341 "sql.yacc"
    {sprintf((yyval.str),"%s", (yyvsp[(1) - (4)].str)); strcpy((yyval.str), A4GLSQLCV_make_substr_s((yyvsp[(1) - (4)].str), 1,(yyvsp[(3) - (4)].str),0));}
    break;

  case 614:

/* Line 1455 of yacc.c  */
#line 3342 "sql.yacc"
    {char buff[256]; sprintf(buff,"%s.%s", A4GLSQLCV_ownerize_tablename(NULL,(yyvsp[(1) - (6)].str)),(yyvsp[(3) - (6)].str)); strcpy((yyval.str), A4GLSQLCV_make_substr_s(buff,1,(yyvsp[(5) - (6)].str),0));}
    break;

  case 615:

/* Line 1455 of yacc.c  */
#line 3343 "sql.yacc"
    {char buff[256]; sprintf(buff,"%s.%s", A4GLSQLCV_ownerize_tablename((yyvsp[(1) - (8)].str),(yyvsp[(3) - (8)].str)), (yyvsp[(5) - (8)].str)); strcpy((yyval.str), A4GLSQLCV_make_substr_s(buff,1,(yyvsp[(7) - (8)].str),0));  }
    break;

  case 616:

/* Line 1455 of yacc.c  */
#line 3344 "sql.yacc"
    {char buff[256]; sprintf(buff,"%s.%s", A4GLSQLCV_ownerize_tablename((yyvsp[(1) - (8)].str),(yyvsp[(3) - (8)].str)), (yyvsp[(5) - (8)].str));  strcpy((yyval.str), A4GLSQLCV_make_substr_s(buff,1,(yyvsp[(7) - (8)].str),0)); }
    break;

  case 617:

/* Line 1455 of yacc.c  */
#line 3346 "sql.yacc"
    {sprintf((yyval.str),"%s", (yyvsp[(1) - (6)].str)); strcpy((yyval.str), A4GLSQLCV_make_substr_s((yyvsp[(1) - (6)].str), 2,(yyvsp[(3) - (6)].str),(yyvsp[(5) - (6)].str)));}
    break;

  case 618:

/* Line 1455 of yacc.c  */
#line 3347 "sql.yacc"
    {char buff[256]; sprintf(buff,"%s.%s", A4GLSQLCV_ownerize_tablename(NULL,(yyvsp[(1) - (8)].str)),(yyvsp[(3) - (8)].str)); strcpy((yyval.str), A4GLSQLCV_make_substr_s(buff,2,(yyvsp[(5) - (8)].str),(yyvsp[(7) - (8)].str)));}
    break;

  case 619:

/* Line 1455 of yacc.c  */
#line 3348 "sql.yacc"
    {char buff[256]; sprintf(buff,"%s.%s", A4GLSQLCV_ownerize_tablename((yyvsp[(1) - (10)].str),(yyvsp[(3) - (10)].str)), (yyvsp[(5) - (10)].str)); strcpy((yyval.str), A4GLSQLCV_make_substr_s(buff,2,(yyvsp[(7) - (10)].str),(yyvsp[(9) - (10)].str)));  }
    break;

  case 620:

/* Line 1455 of yacc.c  */
#line 3349 "sql.yacc"
    {char buff[256]; sprintf(buff,"%s.%s", A4GLSQLCV_ownerize_tablename((yyvsp[(1) - (10)].str),(yyvsp[(3) - (10)].str)), (yyvsp[(5) - (10)].str));  strcpy((yyval.str), A4GLSQLCV_make_substr_s(buff,2,(yyvsp[(7) - (10)].str),(yyvsp[(9) - (10)].str))); }
    break;

  case 621:

/* Line 1455 of yacc.c  */
#line 3354 "sql.yacc"
    {
                (yyval.s_select_list_item)=(yyvsp[(1) - (1)].s_select_list_item);
        }
    break;

  case 622:

/* Line 1455 of yacc.c  */
#line 3357 "sql.yacc"
    {
                (yyval.s_select_list_item)=new_select_list_item_cast((yyvsp[(1) - (3)].s_select_list_item), (yyvsp[(3) - (3)].str));
        }
    break;

  case 623:

/* Line 1455 of yacc.c  */
#line 3366 "sql.yacc"
    { (yyvsp[(1) - (1)].s_select_list_item)=(yyvsp[(1) - (1)].s_select_list_item); }
    break;

  case 624:

/* Line 1455 of yacc.c  */
#line 3367 "sql.yacc"
    {(yyvsp[(1) - (1)].s_select_list_item)=(yyvsp[(1) - (1)].s_select_list_item);}
    break;

  case 625:

/* Line 1455 of yacc.c  */
#line 3368 "sql.yacc"
    {  (yyval.s_select_list_item)=new_select_list_item_sq(E_SQE_DONT_CARE,(yyvsp[(1) - (1)].s_select_list_item)); }
    break;

  case 626:

/* Line 1455 of yacc.c  */
#line 3369 "sql.yacc"
    { (yyval.s_select_list_item)=new_select_list_item_sq(E_SQE_ALL,(yyvsp[(2) - (2)].s_select_list_item)); }
    break;

  case 627:

/* Line 1455 of yacc.c  */
#line 3370 "sql.yacc"
    { (yyval.s_select_list_item)=new_select_list_item_sq(E_SQE_ANY,(yyvsp[(2) - (2)].s_select_list_item)); }
    break;

  case 628:

/* Line 1455 of yacc.c  */
#line 3371 "sql.yacc"
    { (yyval.s_select_list_item)=new_select_list_item_sq(E_SQE_SOME,(yyvsp[(2) - (2)].s_select_list_item)); }
    break;

  case 629:

/* Line 1455 of yacc.c  */
#line 3375 "sql.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 630:

/* Line 1455 of yacc.c  */
#line 3376 "sql.yacc"
    {strcpy((yyval.str),(yyvsp[(1) - (1)].str));}
    break;



/* Line 1455 of yacc.c  */
#line 8872 "y.tab.c"
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
#line 3381 "sql.yacc"


#if LEX_YY_PREGEN
#include "../../tools/no_yacc/cygwin/compilers/sql/lex.sqlparse_yy.c"
#else
#include "lex.yy.c"
#endif
#include "util.c"
#include "cmds.c"

