
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
#line 589 "y.tab.h"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE sqlparse_yylval;


