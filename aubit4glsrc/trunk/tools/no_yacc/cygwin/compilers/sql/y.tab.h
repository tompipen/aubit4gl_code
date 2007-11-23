/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton interface for Bison's Yacc-like parsers in C

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

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
     INT_VALUE = 1805,
     NAMED = 1806,
     NAMED_GEN = 1807,
     CHAR_VALUE = 1808,
     NOT_USED_1 = 1809,
     NOT_USED_2 = 1810,
     NOT_USED_3 = 1811,
     NOT_USED_4 = 1812,
     NOT_USED_5 = 1813,
     NOT_USED_6 = 1814,
     NOT_USED_7 = 1815,
     NOT_USED_8 = 1816,
     NUMBER_VALUE = 1817,
     SEMICOLON = 1818,
     QUESTION_MARK = 1819,
     CLINE = 1820,
     CH = 1821,
     MARK_VAR = 1822,
     END_MARK_VAR = 1823,
     USING_BTREE = 1012,
     USING_RTREE = 1013,
     SET_BUFFERED_LOG = 1037,
     SET_LOG = 1038,
     MDY = 1040,
     WEEKDAY = 1041,
     MISC_INFX_SQL = 1044,
     DATETIME_VALUE = 1057,
     INTERVAL_VALUE = 1058,
     RECOVER_TABLE = 1059,
     ROLLFORWARD_DATABASE = 1060,
     DROP_TRIGGER = 1076,
     DROP_AUDIT_FOR = 1077,
     CREATE_AUDIT_FOR = 1078,
     EXECUTE_PROCEDURE = 1082,
     ALTER_TABLE = 1089,
     ALTER_INDEX = 1090,
     NEXT_SIZE = 1091,
     XSET_MULTIPLY_EQUAL_OPEN_BRACKET = 1128,
     XSET_ident_DOT_MULTIPLY_EQUAL_OPEN_BRACKET = 1129,
     XSET_ident_DOT_MULTIPLY_EQUAL = 1130,
     XSET_MULTIPLY_EQUAL = 1131,
     XSET_OPEN_BRACKET = 1132,
     CREATE_DATABASE = 1135,
     DROP_DATABASE = 1136,
     ADD_CONSTRAINT = 1138,
     DROP_CONSTRAINT = 1139,
     DROP_SYNONYM = 1140,
     CONSTRAINT = 1141,
     DOUBLE_PRECISION = 1148,
     COUNT_MULTIPLY = 1149,
     MODIFY_NEXT_SIZE = 1169,
     LOCK_MODE_PAGE = 1170,
     LOCK_MODE_ROW = 1171,
     UNITS_YEAR = 1178,
     UNITS_MONTH = 1179,
     UNITS_DAY = 1180,
     UNITS_HOUR = 1181,
     UNITS_MINUTE = 1182,
     UNITS_SECOND = 1183,
     TO_CLUSTER = 1188,
     TO_NOT_CLUSTER = 1189,
     CREATE_UC_IDX = 1191,
     CREATE_U_IDX = 1192,
     CREATE_C_IDX = 1193,
     CREATE_IDX = 1194,
     SQLSICS = 1209,
     CREATE_SCHEMA = 1210,
     SQLSIRR = 1211,
     UPDATESTATS_T = 1212,
     SQLSICR = 1213,
     SQLSIDR = 1224,
     CREATE_TEMP_TABLE = 1225,
     WITH_CHECK_OPTION = 1233,
     WITH_GRANT_OPTION = 1234,
     SQLSLMNW = 1235,
     WHERE_CURRENT_OF = 1241,
     NOT_NULL_UNIQUE = 1249,
     SQLSLMW = 1256,
     ALL_PRIVILEGES = 1258,
     CREATE_SYNONYM = 1262,
     DROP_TABLE = 1263,
     INEXCLUSIVE = 1265,
     UPDATESTATS = 1270,
     CREATE_TABLE = 1296,
     DEFAULT_NULL = 1297,
     DEFAULT_TODAY = 1298,
     DEFAULT_USER = 1299,
     UNLOCK_TABLE = 1312,
     ROLLBACK_W = 1320,
     SQLSEON = 1322,
     SQLSEOFF = 1323,
     CREATE_VIEW = 1327,
     DELETE_FROM = 1328,
     EXTENT_SIZE = 1335,
     FOREIGN_KEY = 1336,
     INSERT_INTO = 1339,
     IS_NOT_NULL = 1341,
     NOT_MATCHES = 1344,
     PRIMARY_KEY = 1350,
     USE_SESSION = 1357,
     WITH_NO_LOG = 1358,
     INSHARE = 1361,
     BEGIN_WORK = 1367,
     DROP_INDEX = 1372,
     FOR_UPDATE_OF = 1378,
     FOR_UPDATE = 1379,
     LOCK_TABLE = 1383,
     NOT_EXISTS = 1385,
     REFERENCES = 1387,
     RENCOL = 1388,
     SMALLFLOAT = 1390,
     COMMIT_W = 1401,
     RENTAB = 1408,
     KW_CHAR = 1411,
     NCHAR = 1412,
     NVARCHAR = 1413,
     DELIMITER = 1415,
     DROP_VIEW = 1417,
     EXCLUSIVE = 1420,
     GREATER_THAN_EQ = 1424,
     INTO_TEMP = 1426,
     LOAD_FROM = 1430,
     UNLOAD_TO = 1441,
     DATABASE = 1450,
     DATETIME = 1451,
     DISTINCT = 1453,
     FRACTION = 1460,
     GROUP_BY = 1462,
     INTERVAL = 1463,
     NOT_LIKE = 1465,
     NOT_ILIKE = 1466,
     NOT_NULL = 1467,
     RESOURCE = 1473,
     SMALLINT = 1474,
     IS_NULL = 1480,
     LESS_THAN_EQ = 1481,
     BETWEEN = 1483,
     CLOSE_BRACKET = 1486,
     CONNECT = 1489,
     KW_CURRENT = 1490,
     KW_DECIMAL = 1492,
     DEFAULT = 1494,
     INTEGER = 1502,
     SERIAL8 = 1504,
     MATCHES = 1507,
     VARCHAR = 1520,
     CLOSE_SQUARE = 1523,
     GREATER_THAN = 1524,
     KW_FALSE = 1525,
     NOT_IN = 1526,
     OPEN_BRACKET = 1528,
     KW_DELETE = 1536,
     KW_ESCAPE = 1539,
     EXISTS = 1540,
     EXTEND = 1541,
     HAVING = 1545,
     KW_INSERT = 1547,
     MINUTE = 1551,
     MODIFY = 1552,
     EQUAL = 1554,
     NOT_EQUAL = 1555,
     OPEN_SQUARE = 1557,
     PUBLIC = 1561,
     REVOKE = 1564,
     SECOND = 1568,
     KW_SELECT = 1572,
     SERIAL = 1573,
     UNIQUE = 1576,
     KW_UPDATE = 1578,
     VALUES = 1579,
     KW_NULL = 1583,
     KW_TRUE = 1584,
     ALTER = 1586,
     CHECK = 1592,
     COUNT = 1596,
     KW_FIRST = 1601,
     KW_FLOAT = 1602,
     GRANT = 1605,
     INDEX = 1608,
     LESS_THAN = 1611,
     MONEY = 1613,
     MONTH = 1614,
     KW_MULTIPLY = 1616,
     ORDER = 1617,
     OUTER = 1618,
     UNION = 1627,
     WHERE = 1629,
     KW_BYTE = 1636,
     CASE = 1638,
     KW_DATE = 1640,
     DESC = 1641,
     KW_DIVIDE = 1642,
     DROP = 1645,
     ELSE = 1646,
     FROM = 1650,
     HOUR = 1656,
     INTO = 1657,
     LIKE = 1660,
     REAL = 1669,
     SOME = 1674,
     KW_TEXT = 1678,
     KW_THEN = 1679,
     USER = 1680,
     WHEN = 1682,
     YEAR = 1685,
     KW_DOW = 1686,
     XSET = 1688,
     ADD = 1689,
     ALL = 1690,
     KW_AND = 1691,
     ANY = 1692,
     ASC = 1693,
     AVG = 1694,
     COLON = 1695,
     KW_COMMA = 1696,
     DAY = 1697,
     DBA = 1698,
     KW_FOR = 1702,
     XMAX = 1707,
     XMIN = 1708,
     KW_MINUS = 1709,
     KW_MOD = 1710,
     KW_NOT = 1711,
     KW_ROW = 1715,
     KW_SUM = 1718,
     ATSIGN = 1721,
     KW_PLUS = 1722,
     KW_AS = 1727,
     KW_BY = 1729,
     KW_DOT = 1730,
     KW_IN = 1733,
     KW_ON = 1735,
     KW_OR = 1736,
     KW_TO = 1737,
     BEFORE = 1775,
     END = 1779,
     TILDE = 1786,
     ILIKE = 1787,
     FILLFACTOR = 1790,
     TIME = 1795,
     KW_TODAY = 1802,
     KW_ROWID = 1803
   };
#endif
/* Tokens.  */
#define INT_VALUE 1805
#define NAMED 1806
#define NAMED_GEN 1807
#define CHAR_VALUE 1808
#define NOT_USED_1 1809
#define NOT_USED_2 1810
#define NOT_USED_3 1811
#define NOT_USED_4 1812
#define NOT_USED_5 1813
#define NOT_USED_6 1814
#define NOT_USED_7 1815
#define NOT_USED_8 1816
#define NUMBER_VALUE 1817
#define SEMICOLON 1818
#define QUESTION_MARK 1819
#define CLINE 1820
#define CH 1821
#define MARK_VAR 1822
#define END_MARK_VAR 1823
#define USING_BTREE 1012
#define USING_RTREE 1013
#define SET_BUFFERED_LOG 1037
#define SET_LOG 1038
#define MDY 1040
#define WEEKDAY 1041
#define MISC_INFX_SQL 1044
#define DATETIME_VALUE 1057
#define INTERVAL_VALUE 1058
#define RECOVER_TABLE 1059
#define ROLLFORWARD_DATABASE 1060
#define DROP_TRIGGER 1076
#define DROP_AUDIT_FOR 1077
#define CREATE_AUDIT_FOR 1078
#define EXECUTE_PROCEDURE 1082
#define ALTER_TABLE 1089
#define ALTER_INDEX 1090
#define NEXT_SIZE 1091
#define XSET_MULTIPLY_EQUAL_OPEN_BRACKET 1128
#define XSET_ident_DOT_MULTIPLY_EQUAL_OPEN_BRACKET 1129
#define XSET_ident_DOT_MULTIPLY_EQUAL 1130
#define XSET_MULTIPLY_EQUAL 1131
#define XSET_OPEN_BRACKET 1132
#define CREATE_DATABASE 1135
#define DROP_DATABASE 1136
#define ADD_CONSTRAINT 1138
#define DROP_CONSTRAINT 1139
#define DROP_SYNONYM 1140
#define CONSTRAINT 1141
#define DOUBLE_PRECISION 1148
#define COUNT_MULTIPLY 1149
#define MODIFY_NEXT_SIZE 1169
#define LOCK_MODE_PAGE 1170
#define LOCK_MODE_ROW 1171
#define UNITS_YEAR 1178
#define UNITS_MONTH 1179
#define UNITS_DAY 1180
#define UNITS_HOUR 1181
#define UNITS_MINUTE 1182
#define UNITS_SECOND 1183
#define TO_CLUSTER 1188
#define TO_NOT_CLUSTER 1189
#define CREATE_UC_IDX 1191
#define CREATE_U_IDX 1192
#define CREATE_C_IDX 1193
#define CREATE_IDX 1194
#define SQLSICS 1209
#define CREATE_SCHEMA 1210
#define SQLSIRR 1211
#define UPDATESTATS_T 1212
#define SQLSICR 1213
#define SQLSIDR 1224
#define CREATE_TEMP_TABLE 1225
#define WITH_CHECK_OPTION 1233
#define WITH_GRANT_OPTION 1234
#define SQLSLMNW 1235
#define WHERE_CURRENT_OF 1241
#define NOT_NULL_UNIQUE 1249
#define SQLSLMW 1256
#define ALL_PRIVILEGES 1258
#define CREATE_SYNONYM 1262
#define DROP_TABLE 1263
#define INEXCLUSIVE 1265
#define UPDATESTATS 1270
#define CREATE_TABLE 1296
#define DEFAULT_NULL 1297
#define DEFAULT_TODAY 1298
#define DEFAULT_USER 1299
#define UNLOCK_TABLE 1312
#define ROLLBACK_W 1320
#define SQLSEON 1322
#define SQLSEOFF 1323
#define CREATE_VIEW 1327
#define DELETE_FROM 1328
#define EXTENT_SIZE 1335
#define FOREIGN_KEY 1336
#define INSERT_INTO 1339
#define IS_NOT_NULL 1341
#define NOT_MATCHES 1344
#define PRIMARY_KEY 1350
#define USE_SESSION 1357
#define WITH_NO_LOG 1358
#define INSHARE 1361
#define BEGIN_WORK 1367
#define DROP_INDEX 1372
#define FOR_UPDATE_OF 1378
#define FOR_UPDATE 1379
#define LOCK_TABLE 1383
#define NOT_EXISTS 1385
#define REFERENCES 1387
#define RENCOL 1388
#define SMALLFLOAT 1390
#define COMMIT_W 1401
#define RENTAB 1408
#define KW_CHAR 1411
#define NCHAR 1412
#define NVARCHAR 1413
#define DELIMITER 1415
#define DROP_VIEW 1417
#define EXCLUSIVE 1420
#define GREATER_THAN_EQ 1424
#define INTO_TEMP 1426
#define LOAD_FROM 1430
#define UNLOAD_TO 1441
#define DATABASE 1450
#define DATETIME 1451
#define DISTINCT 1453
#define FRACTION 1460
#define GROUP_BY 1462
#define INTERVAL 1463
#define NOT_LIKE 1465
#define NOT_ILIKE 1466
#define NOT_NULL 1467
#define RESOURCE 1473
#define SMALLINT 1474
#define IS_NULL 1480
#define LESS_THAN_EQ 1481
#define BETWEEN 1483
#define CLOSE_BRACKET 1486
#define CONNECT 1489
#define KW_CURRENT 1490
#define KW_DECIMAL 1492
#define DEFAULT 1494
#define INTEGER 1502
#define SERIAL8 1504
#define MATCHES 1507
#define VARCHAR 1520
#define CLOSE_SQUARE 1523
#define GREATER_THAN 1524
#define KW_FALSE 1525
#define NOT_IN 1526
#define OPEN_BRACKET 1528
#define KW_DELETE 1536
#define KW_ESCAPE 1539
#define EXISTS 1540
#define EXTEND 1541
#define HAVING 1545
#define KW_INSERT 1547
#define MINUTE 1551
#define MODIFY 1552
#define EQUAL 1554
#define NOT_EQUAL 1555
#define OPEN_SQUARE 1557
#define PUBLIC 1561
#define REVOKE 1564
#define SECOND 1568
#define KW_SELECT 1572
#define SERIAL 1573
#define UNIQUE 1576
#define KW_UPDATE 1578
#define VALUES 1579
#define KW_NULL 1583
#define KW_TRUE 1584
#define ALTER 1586
#define CHECK 1592
#define COUNT 1596
#define KW_FIRST 1601
#define KW_FLOAT 1602
#define GRANT 1605
#define INDEX 1608
#define LESS_THAN 1611
#define MONEY 1613
#define MONTH 1614
#define KW_MULTIPLY 1616
#define ORDER 1617
#define OUTER 1618
#define UNION 1627
#define WHERE 1629
#define KW_BYTE 1636
#define CASE 1638
#define KW_DATE 1640
#define DESC 1641
#define KW_DIVIDE 1642
#define DROP 1645
#define ELSE 1646
#define FROM 1650
#define HOUR 1656
#define INTO 1657
#define LIKE 1660
#define REAL 1669
#define SOME 1674
#define KW_TEXT 1678
#define KW_THEN 1679
#define USER 1680
#define WHEN 1682
#define YEAR 1685
#define KW_DOW 1686
#define XSET 1688
#define ADD 1689
#define ALL 1690
#define KW_AND 1691
#define ANY 1692
#define ASC 1693
#define AVG 1694
#define COLON 1695
#define KW_COMMA 1696
#define DAY 1697
#define DBA 1698
#define KW_FOR 1702
#define XMAX 1707
#define XMIN 1708
#define KW_MINUS 1709
#define KW_MOD 1710
#define KW_NOT 1711
#define KW_ROW 1715
#define KW_SUM 1718
#define ATSIGN 1721
#define KW_PLUS 1722
#define KW_AS 1727
#define KW_BY 1729
#define KW_DOT 1730
#define KW_IN 1733
#define KW_ON 1735
#define KW_OR 1736
#define KW_TO 1737
#define BEFORE 1775
#define END 1779
#define TILDE 1786
#define ILIKE 1787
#define FILLFACTOR 1790
#define TIME 1795
#define KW_TODAY 1802
#define KW_ROWID 1803




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 176 "sql.yacc"
{
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


}
/* Line 1489 of yacc.c.  */
#line 552 "y.tab.h"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE sqlparse_yylval;

