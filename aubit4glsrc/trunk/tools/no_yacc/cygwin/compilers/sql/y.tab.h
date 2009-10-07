
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton interface for Bison's Yacc-like parsers in C
   
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


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     INT_VALUE = 2217,
     NAMED = 2218,
     NAMED_GEN = 2219,
     CHAR_VALUE = 2220,
     NOT_USED_1 = 2221,
     NOT_USED_2 = 2222,
     NOT_USED_3 = 2223,
     NOT_USED_4 = 2224,
     NOT_USED_5 = 2225,
     NOT_USED_6 = 2226,
     NOT_USED_7 = 2227,
     NOT_USED_8 = 2228,
     NUMBER_VALUE = 2229,
     SEMICOLON = 2230,
     QUESTION_MARK = 2231,
     CLINE = 2232,
     CH = 2233,
     MARK_VAR = 2234,
     END_MARK_VAR = 2235,
     USE_SESSION = 1001,
     KW_RUN_CLIENT = 1002,
     LEFT_JOIN = 1004,
     IGNORE_ERRORS = 1007,
     SQLERRMESSAGE = 1008,
     DISPLAY_NULL_TO = 1009,
     UNBUFFERED = 1010,
     KW_PICTURE = 1011,
     ON_CHANGE = 1012,
     INNER_JOIN = 1013,
     UI_INTERFACE_DOT_FRONTCALL = 1016,
     UICOMBOBOX = 1020,
     UIFORM = 1023,
     USING_BTREE = 1039,
     USING_RTREE = 1040,
     SET_BUFFERED_LOG = 1065,
     SET_LOG = 1068,
     MDY = 1070,
     WEEKDAY = 1071,
     MODE_ANSI = 1074,
     START_DATABASE = 1075,
     WITH_LOG_IN = 1076,
     SET_CONSTRAINTS_ALL_IMMEDIATE = 1077,
     DATETIME_VALUE = 1090,
     INTERVAL_VALUE = 1091,
     RECOVER_TABLE = 1092,
     ROLLFORWARD_DATABASE = 1093,
     DROP_TRIGGER = 1109,
     DROP_AUDIT_FOR = 1110,
     CREATE_AUDIT_FOR = 1111,
     EXECUTE_PROCEDURE = 1115,
     ALTER_TABLE = 1122,
     ALTER_INDEX = 1123,
     NEXT_SIZE = 1124,
     XSET_MULTIPLY_EQUAL_OPEN_BRACKET = 1161,
     XSET_ident_DOT_MULTIPLY_EQUAL_OPEN_BRACKET = 1162,
     XSET_ident_DOT_MULTIPLY_EQUAL = 1163,
     XSET_MULTIPLY_EQUAL = 1164,
     XSET_OPEN_BRACKET = 1165,
     CREATE_DATABASE = 1168,
     DROP_DATABASE = 1169,
     ADD_CONSTRAINT = 1171,
     DROP_CONSTRAINT = 1172,
     DROP_SYNONYM = 1173,
     CONSTRAINT = 1174,
     NOT_FIELD_TOUCHED_CURRENT = 1177,
     FIELD_TOUCHED_CURRENT = 1178,
     DOUBLE_PRECISION = 1185,
     COUNT_MULTIPLY = 1186,
     MODIFY_NEXT_SIZE = 1206,
     LOCK_MODE_PAGE = 1207,
     LOCK_MODE_ROW = 1208,
     UNITS_YEAR = 1215,
     UNITS_MONTH = 1216,
     UNITS_DAY = 1217,
     UNITS_HOUR = 1218,
     UNITS_MINUTE = 1219,
     UNITS_SECOND = 1220,
     TO_CLUSTER = 1225,
     TO_NOT_CLUSTER = 1226,
     CREATE_UC_IDX = 1228,
     CREATE_U_IDX = 1229,
     CREATE_C_IDX = 1230,
     CREATE_IDX = 1231,
     DOUBLE_COLON = 1241,
     SQLSICS = 1247,
     CREATE_SCHEMA = 1248,
     SQLSIRR = 1249,
     UPDATESTATS_T = 1250,
     SQLSICR = 1251,
     SQLSIDR = 1262,
     CREATE_TEMP_TABLE = 1263,
     WITH_CHECK_OPTION = 1271,
     WITH_GRANT_OPTION = 1272,
     SQLSLMNW = 1273,
     WHERE_CURRENT_OF = 1279,
     NOT_NULL_UNIQUE = 1287,
     SQLSLMW = 1294,
     ALL_PRIVILEGES = 1296,
     CREATE_SYNONYM = 1300,
     DROP_TABLE = 1301,
     INEXCLUSIVE = 1303,
     UPDATESTATS = 1308,
     CREATE_TABLE = 1334,
     DEFAULT_NULL = 1335,
     DEFAULT_TODAY = 1336,
     DEFAULT_USER = 1337,
     UNLOCK_TABLE = 1350,
     ROLLBACK_W = 1358,
     SQLSEON = 1360,
     SQLSEOFF = 1361,
     CREATE_VIEW = 1365,
     DELETE_FROM = 1366,
     EXTENT_SIZE = 1373,
     FOREIGN_KEY = 1374,
     INSERT_INTO = 1377,
     IS_NOT_NULL = 1379,
     NOT_MATCHES = 1382,
     PRIMARY_KEY = 1388,
     WITH_NO_LOG = 1395,
     INSHARE = 1398,
     BEGIN_WORK = 1404,
     DROP_INDEX = 1409,
     FOR_UPDATE_OF = 1415,
     FOR_UPDATE = 1416,
     LOCK_TABLE = 1421,
     NOT_EXISTS = 1423,
     REFERENCES = 1425,
     RENCOL = 1426,
     SMALLFLOAT = 1428,
     COMMIT_W = 1439,
     RENTAB = 1446,
     KW_CHAR = 1449,
     NCHAR = 1450,
     NVARCHAR = 1451,
     DELIMITER = 1453,
     DROP_VIEW = 1455,
     EXCLUSIVE = 1458,
     GREATER_THAN_EQ = 1462,
     INTO_TEMP = 1464,
     DATABASE = 1488,
     DATETIME = 1489,
     DISTINCT = 1491,
     FRACTION = 1498,
     GROUP_BY = 1500,
     INTERVAL = 1501,
     NOT_LIKE = 1503,
     NOT_ILIKE = 1504,
     NOT_NULL = 1505,
     RESOURCE = 1511,
     SMALLINT = 1512,
     IS_NULL = 1518,
     LESS_THAN_EQ = 1519,
     BETWEEN = 1521,
     CLOSE_BRACKET = 1524,
     CONNECT = 1527,
     KW_CURRENT = 1528,
     KW_DECIMAL = 1530,
     DEFAULT = 1532,
     INTEGER = 1540,
     SERIAL8 = 1542,
     MATCHES = 1545,
     VARCHAR = 1558,
     CLOSE_SQUARE = 1561,
     GREATER_THAN = 1562,
     KW_FALSE = 1563,
     NOT_IN = 1564,
     OPEN_BRACKET = 1566,
     KW_DELETE = 1574,
     KW_ESCAPE = 1577,
     EXISTS = 1578,
     EXTEND = 1579,
     HAVING = 1583,
     KW_INSERT = 1585,
     MINUTE = 1589,
     MODIFY = 1590,
     EQUAL = 1592,
     NOT_EQUAL = 1593,
     OPEN_SQUARE = 1595,
     PUBLIC = 1599,
     REVOKE = 1603,
     SECOND = 1607,
     KW_SELECT = 1611,
     SERIAL = 1612,
     UNIQUE = 1615,
     KW_UPDATE = 1617,
     VALUES = 1618,
     KW_NULL = 1621,
     KW_TRUE = 1622,
     ALTER = 1624,
     CHECK = 1630,
     COUNT = 1634,
     KW_FIRST = 1639,
     KW_FLOAT = 1640,
     GRANT = 1643,
     INDEX = 1646,
     LESS_THAN = 1649,
     MONEY = 1651,
     MONTH = 1652,
     KW_MULTIPLY = 1654,
     ORDER = 1655,
     OUTER = 1656,
     UNION = 1665,
     WHERE = 1668,
     KW_BYTE = 1675,
     CASE = 1677,
     KW_DATE = 1679,
     DESC = 1680,
     KW_DIVIDE = 1681,
     DROP = 1684,
     ELSE = 1685,
     FROM = 1689,
     HOUR = 1695,
     INTO = 1696,
     LIKE = 1699,
     REAL = 1708,
     SOME = 1713,
     KW_TEXT = 1717,
     KW_THEN = 1718,
     USER = 1719,
     WHEN = 1721,
     YEAR = 1724,
     KW_DOW = 1725,
     XSET = 1727,
     ADD = 1728,
     ALL = 1729,
     KW_AND = 1730,
     ANY = 1731,
     ASC = 1732,
     AVG = 1733,
     COLON = 1734,
     KW_COMMA = 1735,
     DAY = 1736,
     DBA = 1737,
     KW_FOR = 1741,
     XMAX = 1746,
     XMIN = 1747,
     KW_MINUS = 1748,
     KW_MOD = 1749,
     KW_NOT = 1750,
     KW_SUM = 1757,
     ATSIGN = 1760,
     KW_PLUS = 1761,
     KW_AS = 1767,
     KW_BY = 1769,
     KW_DOT = 1770,
     KW_IN = 1773,
     KW_ON = 1775,
     KW_OR = 1776,
     KW_TO = 1777,
     BEFORE = 1815,
     END = 1819,
     TILDE = 1826,
     ILIKE = 1827,
     FILLFACTOR = 1830,
     TIME = 1835,
     KW_TODAY = 1842,
     KW_ROWID = 1843,
     TIMESTAMP = 2191,
     KW_TAG = 2212,
     LINTMODULEISLIBRARY = 2213,
     KW_PUBLIC = 2214,
     KW_PRIVATE = 2215
   };
#endif
/* Tokens.  */
#define INT_VALUE 2217
#define NAMED 2218
#define NAMED_GEN 2219
#define CHAR_VALUE 2220
#define NOT_USED_1 2221
#define NOT_USED_2 2222
#define NOT_USED_3 2223
#define NOT_USED_4 2224
#define NOT_USED_5 2225
#define NOT_USED_6 2226
#define NOT_USED_7 2227
#define NOT_USED_8 2228
#define NUMBER_VALUE 2229
#define SEMICOLON 2230
#define QUESTION_MARK 2231
#define CLINE 2232
#define CH 2233
#define MARK_VAR 2234
#define END_MARK_VAR 2235
#define USE_SESSION 1001
#define KW_RUN_CLIENT 1002
#define LEFT_JOIN 1004
#define IGNORE_ERRORS 1007
#define SQLERRMESSAGE 1008
#define DISPLAY_NULL_TO 1009
#define UNBUFFERED 1010
#define KW_PICTURE 1011
#define ON_CHANGE 1012
#define INNER_JOIN 1013
#define UI_INTERFACE_DOT_FRONTCALL 1016
#define UICOMBOBOX 1020
#define UIFORM 1023
#define USING_BTREE 1039
#define USING_RTREE 1040
#define SET_BUFFERED_LOG 1065
#define SET_LOG 1068
#define MDY 1070
#define WEEKDAY 1071
#define MODE_ANSI 1074
#define START_DATABASE 1075
#define WITH_LOG_IN 1076
#define SET_CONSTRAINTS_ALL_IMMEDIATE 1077
#define DATETIME_VALUE 1090
#define INTERVAL_VALUE 1091
#define RECOVER_TABLE 1092
#define ROLLFORWARD_DATABASE 1093
#define DROP_TRIGGER 1109
#define DROP_AUDIT_FOR 1110
#define CREATE_AUDIT_FOR 1111
#define EXECUTE_PROCEDURE 1115
#define ALTER_TABLE 1122
#define ALTER_INDEX 1123
#define NEXT_SIZE 1124
#define XSET_MULTIPLY_EQUAL_OPEN_BRACKET 1161
#define XSET_ident_DOT_MULTIPLY_EQUAL_OPEN_BRACKET 1162
#define XSET_ident_DOT_MULTIPLY_EQUAL 1163
#define XSET_MULTIPLY_EQUAL 1164
#define XSET_OPEN_BRACKET 1165
#define CREATE_DATABASE 1168
#define DROP_DATABASE 1169
#define ADD_CONSTRAINT 1171
#define DROP_CONSTRAINT 1172
#define DROP_SYNONYM 1173
#define CONSTRAINT 1174
#define NOT_FIELD_TOUCHED_CURRENT 1177
#define FIELD_TOUCHED_CURRENT 1178
#define DOUBLE_PRECISION 1185
#define COUNT_MULTIPLY 1186
#define MODIFY_NEXT_SIZE 1206
#define LOCK_MODE_PAGE 1207
#define LOCK_MODE_ROW 1208
#define UNITS_YEAR 1215
#define UNITS_MONTH 1216
#define UNITS_DAY 1217
#define UNITS_HOUR 1218
#define UNITS_MINUTE 1219
#define UNITS_SECOND 1220
#define TO_CLUSTER 1225
#define TO_NOT_CLUSTER 1226
#define CREATE_UC_IDX 1228
#define CREATE_U_IDX 1229
#define CREATE_C_IDX 1230
#define CREATE_IDX 1231
#define DOUBLE_COLON 1241
#define SQLSICS 1247
#define CREATE_SCHEMA 1248
#define SQLSIRR 1249
#define UPDATESTATS_T 1250
#define SQLSICR 1251
#define SQLSIDR 1262
#define CREATE_TEMP_TABLE 1263
#define WITH_CHECK_OPTION 1271
#define WITH_GRANT_OPTION 1272
#define SQLSLMNW 1273
#define WHERE_CURRENT_OF 1279
#define NOT_NULL_UNIQUE 1287
#define SQLSLMW 1294
#define ALL_PRIVILEGES 1296
#define CREATE_SYNONYM 1300
#define DROP_TABLE 1301
#define INEXCLUSIVE 1303
#define UPDATESTATS 1308
#define CREATE_TABLE 1334
#define DEFAULT_NULL 1335
#define DEFAULT_TODAY 1336
#define DEFAULT_USER 1337
#define UNLOCK_TABLE 1350
#define ROLLBACK_W 1358
#define SQLSEON 1360
#define SQLSEOFF 1361
#define CREATE_VIEW 1365
#define DELETE_FROM 1366
#define EXTENT_SIZE 1373
#define FOREIGN_KEY 1374
#define INSERT_INTO 1377
#define IS_NOT_NULL 1379
#define NOT_MATCHES 1382
#define PRIMARY_KEY 1388
#define WITH_NO_LOG 1395
#define INSHARE 1398
#define BEGIN_WORK 1404
#define DROP_INDEX 1409
#define FOR_UPDATE_OF 1415
#define FOR_UPDATE 1416
#define LOCK_TABLE 1421
#define NOT_EXISTS 1423
#define REFERENCES 1425
#define RENCOL 1426
#define SMALLFLOAT 1428
#define COMMIT_W 1439
#define RENTAB 1446
#define KW_CHAR 1449
#define NCHAR 1450
#define NVARCHAR 1451
#define DELIMITER 1453
#define DROP_VIEW 1455
#define EXCLUSIVE 1458
#define GREATER_THAN_EQ 1462
#define INTO_TEMP 1464
#define DATABASE 1488
#define DATETIME 1489
#define DISTINCT 1491
#define FRACTION 1498
#define GROUP_BY 1500
#define INTERVAL 1501
#define NOT_LIKE 1503
#define NOT_ILIKE 1504
#define NOT_NULL 1505
#define RESOURCE 1511
#define SMALLINT 1512
#define IS_NULL 1518
#define LESS_THAN_EQ 1519
#define BETWEEN 1521
#define CLOSE_BRACKET 1524
#define CONNECT 1527
#define KW_CURRENT 1528
#define KW_DECIMAL 1530
#define DEFAULT 1532
#define INTEGER 1540
#define SERIAL8 1542
#define MATCHES 1545
#define VARCHAR 1558
#define CLOSE_SQUARE 1561
#define GREATER_THAN 1562
#define KW_FALSE 1563
#define NOT_IN 1564
#define OPEN_BRACKET 1566
#define KW_DELETE 1574
#define KW_ESCAPE 1577
#define EXISTS 1578
#define EXTEND 1579
#define HAVING 1583
#define KW_INSERT 1585
#define MINUTE 1589
#define MODIFY 1590
#define EQUAL 1592
#define NOT_EQUAL 1593
#define OPEN_SQUARE 1595
#define PUBLIC 1599
#define REVOKE 1603
#define SECOND 1607
#define KW_SELECT 1611
#define SERIAL 1612
#define UNIQUE 1615
#define KW_UPDATE 1617
#define VALUES 1618
#define KW_NULL 1621
#define KW_TRUE 1622
#define ALTER 1624
#define CHECK 1630
#define COUNT 1634
#define KW_FIRST 1639
#define KW_FLOAT 1640
#define GRANT 1643
#define INDEX 1646
#define LESS_THAN 1649
#define MONEY 1651
#define MONTH 1652
#define KW_MULTIPLY 1654
#define ORDER 1655
#define OUTER 1656
#define UNION 1665
#define WHERE 1668
#define KW_BYTE 1675
#define CASE 1677
#define KW_DATE 1679
#define DESC 1680
#define KW_DIVIDE 1681
#define DROP 1684
#define ELSE 1685
#define FROM 1689
#define HOUR 1695
#define INTO 1696
#define LIKE 1699
#define REAL 1708
#define SOME 1713
#define KW_TEXT 1717
#define KW_THEN 1718
#define USER 1719
#define WHEN 1721
#define YEAR 1724
#define KW_DOW 1725
#define XSET 1727
#define ADD 1728
#define ALL 1729
#define KW_AND 1730
#define ANY 1731
#define ASC 1732
#define AVG 1733
#define COLON 1734
#define KW_COMMA 1735
#define DAY 1736
#define DBA 1737
#define KW_FOR 1741
#define XMAX 1746
#define XMIN 1747
#define KW_MINUS 1748
#define KW_MOD 1749
#define KW_NOT 1750
#define KW_SUM 1757
#define ATSIGN 1760
#define KW_PLUS 1761
#define KW_AS 1767
#define KW_BY 1769
#define KW_DOT 1770
#define KW_IN 1773
#define KW_ON 1775
#define KW_OR 1776
#define KW_TO 1777
#define BEFORE 1815
#define END 1819
#define TILDE 1826
#define ILIKE 1827
#define FILLFACTOR 1830
#define TIME 1835
#define KW_TODAY 1842
#define KW_ROWID 1843
#define TIMESTAMP 2191
#define KW_TAG 2212
#define LINTMODULEISLIBRARY 2213
#define KW_PUBLIC 2214
#define KW_PRIVATE 2215




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 1676 of yacc.c  */
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





/* Line 1676 of yacc.c  */
#line 605 "y.tab.h"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE sqlparse_yylval;


