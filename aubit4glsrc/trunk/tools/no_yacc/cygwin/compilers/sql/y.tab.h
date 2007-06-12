/* A Bison parser, made by GNU Bison 2.2.  */

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
     INT_VALUE = 2151,
     NAMED = 2152,
     NAMED_GEN = 2153,
     CHAR_VALUE = 2154,
     NOT_USED_1 = 2155,
     NOT_USED_2 = 2156,
     NOT_USED_3 = 2157,
     NOT_USED_4 = 2158,
     NOT_USED_5 = 2159,
     NOT_USED_6 = 2160,
     NOT_USED_7 = 2161,
     NOT_USED_8 = 2162,
     NUMBER_VALUE = 2163,
     SEMICOLON = 2164,
     QUESTION_MARK = 2165,
     CLINE = 2166,
     CH = 2167,
     MARK_VAR = 2168,
     END_MARK_VAR = 2169,
     ON_CLOSE_APPLICATION_STOP = 1000,
     DIALOGSETCURRLINE = 1001,
     DIALOGKEYSETLABEL = 1002,
     UI_INTERFACE_DOT = 1003,
     UI_WINDOW_DOT = 1004,
     UIWINDOW = 1005,
     NOSQLCLOBBER = 1006,
     NOCLOBBER = 1007,
     ALWAYSSQLCLOBBER = 1008,
     ALWAYSCLOBBER = 1009,
     OMDOMNODE = 1010,
     OMNODELIST = 1011,
     USING_BTREE = 1012,
     USING_RTREE = 1013,
     BASECHANNEL = 1014,
     UI_DOT_FORM_DOT = 1015,
     DIALOG_DOT = 1016,
     STRING = 1017,
     KW_COMMENT = 1018,
     KW_IMAGE = 1019,
     DEBUG_FILE = 1020,
     REPLACE_STRING = 1032,
     STOP_REPLACE_STRING = 1033,
     IGNORE_FUNCTION = 1034,
     SET_BUFFERED_LOG = 1037,
     SET_LOG = 1038,
     MDY = 1040,
     WEEKDAY = 1041,
     MISC_INFX_SQL = 1044,
     CONVERTING_VIA = 1045,
     AS_CONVERTIBLE = 1052,
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
     KW_ARG_VAL = 1147,
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
     USE_MEMBER_FUNCTION = 1204,
     USE_MEMBER_OF = 1205,
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
     VARIABLE_ATTRIBUTES = 1444,
     DATABASE = 1451,
     DATETIME = 1452,
     DISTINCT = 1454,
     FRACTION = 1461,
     GROUP_BY = 1463,
     INTERVAL = 1464,
     NOT_LIKE = 1466,
     NOT_ILIKE = 1467,
     NOT_NULL = 1468,
     RESOURCE = 1474,
     SMALLINT = 1475,
     KW_WORDWRAP = 1478,
     IS_NULL = 1481,
     LESS_THAN_EQ = 1482,
     BETWEEN = 1484,
     KW_CLIPPED = 1486,
     CLOSE_BRACKET = 1487,
     CONNECT = 1490,
     KW_CURRENT = 1491,
     KW_DECIMAL = 1493,
     DEFAULT = 1495,
     INTEGER = 1503,
     INTEGER8 = 1504,
     SERIAL8 = 1505,
     MATCHES = 1508,
     VARCHAR = 1521,
     CLOSE_SQUARE = 1524,
     GREATER_THAN = 1525,
     KW_FALSE = 1526,
     NOT_IN = 1527,
     OPEN_BRACKET = 1529,
     KW_DELETE = 1537,
     KW_ESCAPE = 1540,
     EXISTS = 1541,
     EXTEND = 1542,
     HAVING = 1546,
     KW_INSERT = 1548,
     MINUTE = 1552,
     MODIFY = 1553,
     EQUAL = 1555,
     NOT_EQUAL = 1556,
     OPEN_SQUARE = 1558,
     PUBLIC = 1562,
     REVOKE = 1565,
     SECOND = 1569,
     KW_SELECT = 1573,
     SERIAL = 1574,
     KW_SPACES = 1576,
     UNIQUE = 1577,
     KW_UPDATE = 1579,
     VALUES = 1580,
     KW_NULL = 1584,
     KW_TRUE = 1585,
     ALTER = 1587,
     KW_ASCII = 1589,
     CHECK = 1593,
     COUNT = 1597,
     KW_FIRST = 1602,
     KW_FLOAT = 1603,
     GRANT = 1606,
     INDEX = 1609,
     LESS_THAN = 1612,
     MONEY = 1614,
     MONTH = 1615,
     KW_POWER = 1616,
     KW_MULTIPLY = 1617,
     ORDER = 1618,
     OUTER = 1619,
     UNION = 1628,
     WHERE = 1630,
     KW_BYTE = 1637,
     CASE = 1639,
     KW_DATE = 1641,
     DESC = 1642,
     KW_DIVIDE = 1643,
     DROP = 1646,
     ELSE = 1647,
     FROM = 1651,
     HOUR = 1657,
     INTO = 1658,
     LIKE = 1661,
     REAL = 1670,
     SOME = 1675,
     KW_TEXT = 1679,
     KW_THEN = 1680,
     USER = 1681,
     WHEN = 1683,
     YEAR = 1686,
     KW_DOW = 1687,
     XSET = 1689,
     ADD = 1690,
     ALL = 1691,
     KW_AND = 1692,
     ANY = 1693,
     ASC = 1694,
     AVG = 1695,
     COLON = 1696,
     KW_COMMA = 1697,
     DAY = 1698,
     DBA = 1699,
     KW_FOR = 1703,
     KW_KEY = 1704,
     KW_LET = 1706,
     XMAX = 1708,
     XMIN = 1709,
     KW_MINUS = 1710,
     KW_MOD = 1711,
     KW_NOT = 1712,
     KW_PAD = 1713,
     KW_PUT = 1714,
     KW_RED = 1715,
     KW_ROW = 1716,
     KW_SQL = 1718,
     KW_SUM = 1719,
     KW_TOP = 1720,
     KW_USE = 1721,
     ATSIGN = 1722,
     KW_PLUS = 1723,
     KW_AS = 1728,
     KW_AT = 1729,
     KW_BY = 1730,
     KW_DOT = 1731,
     KW_GO = 1732,
     KW_IF = 1733,
     KW_IN = 1734,
     KW_OF = 1735,
     KW_ON = 1736,
     KW_OR = 1737,
     KW_TO = 1738,
     BEFORE = 1776,
     KW_INPUT_ARRAY = 1777,
     END = 1780,
     TILDE = 1787,
     ILIKE = 1788,
     FILLFACTOR = 1791,
     TIME = 1796,
     KW_TODAY = 1803,
     KW_IDLE = 2143,
     CANCEL_INSERT = 2144,
     CANCEL_DELETE = 2145,
     FORCE_UI = 2146,
     FGL_MODULE = 2147,
     VIA = 2148,
     SLICE = 2149
   };
#endif
/* Tokens.  */
#define INT_VALUE 2151
#define NAMED 2152
#define NAMED_GEN 2153
#define CHAR_VALUE 2154
#define NOT_USED_1 2155
#define NOT_USED_2 2156
#define NOT_USED_3 2157
#define NOT_USED_4 2158
#define NOT_USED_5 2159
#define NOT_USED_6 2160
#define NOT_USED_7 2161
#define NOT_USED_8 2162
#define NUMBER_VALUE 2163
#define SEMICOLON 2164
#define QUESTION_MARK 2165
#define CLINE 2166
#define CH 2167
#define MARK_VAR 2168
#define END_MARK_VAR 2169
#define ON_CLOSE_APPLICATION_STOP 1000
#define DIALOGSETCURRLINE 1001
#define DIALOGKEYSETLABEL 1002
#define UI_INTERFACE_DOT 1003
#define UI_WINDOW_DOT 1004
#define UIWINDOW 1005
#define NOSQLCLOBBER 1006
#define NOCLOBBER 1007
#define ALWAYSSQLCLOBBER 1008
#define ALWAYSCLOBBER 1009
#define OMDOMNODE 1010
#define OMNODELIST 1011
#define USING_BTREE 1012
#define USING_RTREE 1013
#define BASECHANNEL 1014
#define UI_DOT_FORM_DOT 1015
#define DIALOG_DOT 1016
#define STRING 1017
#define KW_COMMENT 1018
#define KW_IMAGE 1019
#define DEBUG_FILE 1020
#define REPLACE_STRING 1032
#define STOP_REPLACE_STRING 1033
#define IGNORE_FUNCTION 1034
#define SET_BUFFERED_LOG 1037
#define SET_LOG 1038
#define MDY 1040
#define WEEKDAY 1041
#define MISC_INFX_SQL 1044
#define CONVERTING_VIA 1045
#define AS_CONVERTIBLE 1052
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
#define KW_ARG_VAL 1147
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
#define USE_MEMBER_FUNCTION 1204
#define USE_MEMBER_OF 1205
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
#define VARIABLE_ATTRIBUTES 1444
#define DATABASE 1451
#define DATETIME 1452
#define DISTINCT 1454
#define FRACTION 1461
#define GROUP_BY 1463
#define INTERVAL 1464
#define NOT_LIKE 1466
#define NOT_ILIKE 1467
#define NOT_NULL 1468
#define RESOURCE 1474
#define SMALLINT 1475
#define KW_WORDWRAP 1478
#define IS_NULL 1481
#define LESS_THAN_EQ 1482
#define BETWEEN 1484
#define KW_CLIPPED 1486
#define CLOSE_BRACKET 1487
#define CONNECT 1490
#define KW_CURRENT 1491
#define KW_DECIMAL 1493
#define DEFAULT 1495
#define INTEGER 1503
#define INTEGER8 1504
#define SERIAL8 1505
#define MATCHES 1508
#define VARCHAR 1521
#define CLOSE_SQUARE 1524
#define GREATER_THAN 1525
#define KW_FALSE 1526
#define NOT_IN 1527
#define OPEN_BRACKET 1529
#define KW_DELETE 1537
#define KW_ESCAPE 1540
#define EXISTS 1541
#define EXTEND 1542
#define HAVING 1546
#define KW_INSERT 1548
#define MINUTE 1552
#define MODIFY 1553
#define EQUAL 1555
#define NOT_EQUAL 1556
#define OPEN_SQUARE 1558
#define PUBLIC 1562
#define REVOKE 1565
#define SECOND 1569
#define KW_SELECT 1573
#define SERIAL 1574
#define KW_SPACES 1576
#define UNIQUE 1577
#define KW_UPDATE 1579
#define VALUES 1580
#define KW_NULL 1584
#define KW_TRUE 1585
#define ALTER 1587
#define KW_ASCII 1589
#define CHECK 1593
#define COUNT 1597
#define KW_FIRST 1602
#define KW_FLOAT 1603
#define GRANT 1606
#define INDEX 1609
#define LESS_THAN 1612
#define MONEY 1614
#define MONTH 1615
#define KW_POWER 1616
#define KW_MULTIPLY 1617
#define ORDER 1618
#define OUTER 1619
#define UNION 1628
#define WHERE 1630
#define KW_BYTE 1637
#define CASE 1639
#define KW_DATE 1641
#define DESC 1642
#define KW_DIVIDE 1643
#define DROP 1646
#define ELSE 1647
#define FROM 1651
#define HOUR 1657
#define INTO 1658
#define LIKE 1661
#define REAL 1670
#define SOME 1675
#define KW_TEXT 1679
#define KW_THEN 1680
#define USER 1681
#define WHEN 1683
#define YEAR 1686
#define KW_DOW 1687
#define XSET 1689
#define ADD 1690
#define ALL 1691
#define KW_AND 1692
#define ANY 1693
#define ASC 1694
#define AVG 1695
#define COLON 1696
#define KW_COMMA 1697
#define DAY 1698
#define DBA 1699
#define KW_FOR 1703
#define KW_KEY 1704
#define KW_LET 1706
#define XMAX 1708
#define XMIN 1709
#define KW_MINUS 1710
#define KW_MOD 1711
#define KW_NOT 1712
#define KW_PAD 1713
#define KW_PUT 1714
#define KW_RED 1715
#define KW_ROW 1716
#define KW_SQL 1718
#define KW_SUM 1719
#define KW_TOP 1720
#define KW_USE 1721
#define ATSIGN 1722
#define KW_PLUS 1723
#define KW_AS 1728
#define KW_AT 1729
#define KW_BY 1730
#define KW_DOT 1731
#define KW_GO 1732
#define KW_IF 1733
#define KW_IN 1734
#define KW_OF 1735
#define KW_ON 1736
#define KW_OR 1737
#define KW_TO 1738
#define BEFORE 1776
#define KW_INPUT_ARRAY 1777
#define END 1780
#define TILDE 1787
#define ILIKE 1788
#define FILLFACTOR 1791
#define TIME 1796
#define KW_TODAY 1803
#define KW_IDLE 2143
#define CANCEL_INSERT 2144
#define CANCEL_DELETE 2145
#define FORCE_UI 2146
#define FGL_MODULE 2147
#define VIA 2148
#define SLICE 2149




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 175 "sql.yacc"
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
/* Line 1488 of yacc.c.  */
#line 658 "y.tab.h"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE sqlparse_yylval;

