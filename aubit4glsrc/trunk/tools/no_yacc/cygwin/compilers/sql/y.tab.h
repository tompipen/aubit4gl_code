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
     INT_VALUE = 2145,
     NAMED = 2146,
     NAMED_GEN = 2147,
     CHAR_VALUE = 2148,
     NOT_USED_1 = 2149,
     NOT_USED_2 = 2150,
     NOT_USED_3 = 2151,
     NOT_USED_4 = 2152,
     NOT_USED_5 = 2153,
     NOT_USED_6 = 2154,
     NOT_USED_7 = 2155,
     NOT_USED_8 = 2156,
     NUMBER_VALUE = 2157,
     SEMICOLON = 2158,
     QUESTION_MARK = 2159,
     CLINE = 2160,
     CH = 2161,
     MARK_VAR = 2162,
     END_MARK_VAR = 2163,
     ON_CLOSE_APPLICATION_STOP = 1000,
     DIALOGSETCURRLINE = 1001,
     DIALOGKEYSETLABEL = 1002,
     UI_INTERFACE_DOT = 1003,
     UI_WINDOW_DOT = 1004,
     UIWINDOW = 1005,
     OMDOMNODE = 1006,
     OMNODELIST = 1007,
     USING_BTREE = 1008,
     USING_RTREE = 1009,
     BASECHANNEL = 1010,
     UI_DOT_FORM_DOT = 1011,
     DIALOG_DOT = 1012,
     STRING = 1013,
     KW_COMMENT = 1014,
     KW_IMAGE = 1015,
     DEBUG_FILE = 1016,
     REPLACE_STRING = 1028,
     STOP_REPLACE_STRING = 1029,
     IGNORE_FUNCTION = 1030,
     SET_BUFFERED_LOG = 1033,
     SET_LOG = 1034,
     MDY = 1036,
     WEEKDAY = 1037,
     MISC_INFX_SQL = 1040,
     CONVERTING_VIA = 1041,
     AS_CONVERTIBLE = 1048,
     DATETIME_VALUE = 1053,
     INTERVAL_VALUE = 1054,
     RECOVER_TABLE = 1055,
     ROLLFORWARD_DATABASE = 1056,
     DROP_TRIGGER = 1072,
     DROP_AUDIT_FOR = 1073,
     CREATE_AUDIT_FOR = 1074,
     EXECUTE_PROCEDURE = 1078,
     ALTER_TABLE = 1085,
     ALTER_INDEX = 1086,
     NEXT_SIZE = 1087,
     XSET_MULTIPLY_EQUAL_OPEN_BRACKET = 1124,
     XSET_ident_DOT_MULTIPLY_EQUAL_OPEN_BRACKET = 1125,
     XSET_ident_DOT_MULTIPLY_EQUAL = 1126,
     XSET_MULTIPLY_EQUAL = 1127,
     XSET_OPEN_BRACKET = 1128,
     CREATE_DATABASE = 1131,
     DROP_DATABASE = 1132,
     ADD_CONSTRAINT = 1134,
     DROP_CONSTRAINT = 1135,
     DROP_SYNONYM = 1136,
     CONSTRAINT = 1137,
     KW_ARG_VAL = 1143,
     DOUBLE_PRECISION = 1144,
     COUNT_MULTIPLY = 1145,
     MODIFY_NEXT_SIZE = 1165,
     LOCK_MODE_PAGE = 1166,
     LOCK_MODE_ROW = 1167,
     UNITS_YEAR = 1174,
     UNITS_MONTH = 1175,
     UNITS_DAY = 1176,
     UNITS_HOUR = 1177,
     UNITS_MINUTE = 1178,
     UNITS_SECOND = 1179,
     TO_CLUSTER = 1184,
     TO_NOT_CLUSTER = 1185,
     CREATE_UC_IDX = 1187,
     CREATE_U_IDX = 1188,
     CREATE_C_IDX = 1189,
     CREATE_IDX = 1190,
     USE_MEMBER_FUNCTION = 1200,
     USE_MEMBER_OF = 1201,
     SQLSICS = 1205,
     CREATE_SCHEMA = 1206,
     SQLSIRR = 1207,
     UPDATESTATS_T = 1208,
     SQLSICR = 1209,
     SQLSIDR = 1220,
     CREATE_TEMP_TABLE = 1221,
     WITH_CHECK_OPTION = 1229,
     WITH_GRANT_OPTION = 1230,
     SQLSLMNW = 1231,
     WHERE_CURRENT_OF = 1237,
     NOT_NULL_UNIQUE = 1245,
     SQLSLMW = 1252,
     ALL_PRIVILEGES = 1254,
     CREATE_SYNONYM = 1258,
     DROP_TABLE = 1259,
     INEXCLUSIVE = 1261,
     UPDATESTATS = 1266,
     CREATE_TABLE = 1292,
     DEFAULT_NULL = 1293,
     DEFAULT_TODAY = 1294,
     DEFAULT_USER = 1295,
     UNLOCK_TABLE = 1308,
     ROLLBACK_W = 1316,
     SQLSEON = 1318,
     SQLSEOFF = 1319,
     CREATE_VIEW = 1323,
     DELETE_FROM = 1324,
     EXTENT_SIZE = 1331,
     FOREIGN_KEY = 1332,
     INSERT_INTO = 1335,
     IS_NOT_NULL = 1337,
     NOT_MATCHES = 1340,
     PRIMARY_KEY = 1346,
     USE_SESSION = 1353,
     WITH_NO_LOG = 1354,
     INSHARE = 1357,
     BEGIN_WORK = 1363,
     DROP_INDEX = 1368,
     FOR_UPDATE_OF = 1374,
     FOR_UPDATE = 1375,
     LOCK_TABLE = 1379,
     NOT_EXISTS = 1381,
     REFERENCES = 1383,
     RENCOL = 1384,
     SMALLFLOAT = 1386,
     COMMIT_W = 1397,
     RENTAB = 1404,
     KW_CHAR = 1407,
     NCHAR = 1408,
     NVARCHAR = 1409,
     DELIMITER = 1411,
     DROP_VIEW = 1413,
     EXCLUSIVE = 1416,
     GREATER_THAN_EQ = 1420,
     INTO_TEMP = 1422,
     LOAD_FROM = 1426,
     UNLOAD_TO = 1437,
     VARIABLE_ATTRIBUTES = 1440,
     DATABASE = 1447,
     DATETIME = 1448,
     DISTINCT = 1450,
     FRACTION = 1457,
     GROUP_BY = 1459,
     INTERVAL = 1460,
     NOT_LIKE = 1462,
     NOT_ILIKE = 1463,
     NOT_NULL = 1464,
     RESOURCE = 1470,
     SMALLINT = 1471,
     KW_WORDWRAP = 1474,
     IS_NULL = 1477,
     LESS_THAN_EQ = 1478,
     BETWEEN = 1480,
     KW_CLIPPED = 1482,
     CLOSE_BRACKET = 1483,
     CONNECT = 1486,
     KW_CURRENT = 1487,
     KW_DECIMAL = 1489,
     DEFAULT = 1491,
     INTEGER = 1499,
     MATCHES = 1502,
     VARCHAR = 1515,
     CLOSE_SQUARE = 1518,
     GREATER_THAN = 1519,
     KW_FALSE = 1520,
     NOT_IN = 1521,
     OPEN_BRACKET = 1523,
     KW_DELETE = 1531,
     KW_ESCAPE = 1534,
     EXISTS = 1535,
     EXTEND = 1536,
     HAVING = 1540,
     KW_INSERT = 1542,
     MINUTE = 1546,
     MODIFY = 1547,
     EQUAL = 1549,
     NOT_EQUAL = 1550,
     OPEN_SQUARE = 1552,
     PUBLIC = 1556,
     REVOKE = 1559,
     SECOND = 1563,
     KW_SELECT = 1567,
     SERIAL = 1568,
     KW_SPACES = 1570,
     UNIQUE = 1571,
     KW_UPDATE = 1573,
     VALUES = 1574,
     KW_NULL = 1578,
     KW_TRUE = 1579,
     ALTER = 1581,
     KW_ASCII = 1583,
     CHECK = 1587,
     COUNT = 1591,
     KW_FIRST = 1596,
     KW_FLOAT = 1597,
     GRANT = 1600,
     INDEX = 1603,
     LESS_THAN = 1606,
     MONEY = 1608,
     MONTH = 1609,
     KW_POWER = 1610,
     KW_MULTIPLY = 1611,
     ORDER = 1612,
     OUTER = 1613,
     UNION = 1622,
     WHERE = 1624,
     KW_BYTE = 1631,
     CASE = 1633,
     KW_DATE = 1635,
     DESC = 1636,
     KW_DIVIDE = 1637,
     DROP = 1640,
     ELSE = 1641,
     FROM = 1645,
     HOUR = 1651,
     INTO = 1652,
     LIKE = 1655,
     REAL = 1664,
     SOME = 1669,
     KW_TEXT = 1673,
     KW_THEN = 1674,
     USER = 1675,
     WHEN = 1677,
     YEAR = 1680,
     KW_DOW = 1681,
     XSET = 1683,
     ADD = 1684,
     ALL = 1685,
     KW_AND = 1686,
     ANY = 1687,
     ASC = 1688,
     AVG = 1689,
     COLON = 1690,
     KW_COMMA = 1691,
     DAY = 1692,
     DBA = 1693,
     KW_FOR = 1697,
     KW_KEY = 1698,
     KW_LET = 1700,
     XMAX = 1702,
     XMIN = 1703,
     KW_MINUS = 1704,
     KW_MOD = 1705,
     KW_NOT = 1706,
     KW_PAD = 1707,
     KW_PUT = 1708,
     KW_RED = 1709,
     KW_ROW = 1710,
     KW_SQL = 1712,
     KW_SUM = 1713,
     KW_TOP = 1714,
     KW_USE = 1715,
     ATSIGN = 1716,
     KW_PLUS = 1717,
     KW_AS = 1722,
     KW_AT = 1723,
     KW_BY = 1724,
     KW_DOT = 1725,
     KW_GO = 1726,
     KW_IF = 1727,
     KW_IN = 1728,
     KW_OF = 1729,
     KW_ON = 1730,
     KW_OR = 1731,
     KW_TO = 1732,
     BEFORE = 1770,
     KW_INPUT_ARRAY = 1771,
     END = 1774,
     TILDE = 1781,
     ILIKE = 1782,
     FILLFACTOR = 1785,
     TIME = 1790,
     KW_TODAY = 1797,
     KW_IDLE = 2137,
     CANCEL_INSERT = 2138,
     CANCEL_DELETE = 2139,
     FORCE_UI = 2140,
     FGL_MODULE = 2141,
     VIA = 2142,
     SLICE = 2143
   };
#endif
/* Tokens.  */
#define INT_VALUE 2145
#define NAMED 2146
#define NAMED_GEN 2147
#define CHAR_VALUE 2148
#define NOT_USED_1 2149
#define NOT_USED_2 2150
#define NOT_USED_3 2151
#define NOT_USED_4 2152
#define NOT_USED_5 2153
#define NOT_USED_6 2154
#define NOT_USED_7 2155
#define NOT_USED_8 2156
#define NUMBER_VALUE 2157
#define SEMICOLON 2158
#define QUESTION_MARK 2159
#define CLINE 2160
#define CH 2161
#define MARK_VAR 2162
#define END_MARK_VAR 2163
#define ON_CLOSE_APPLICATION_STOP 1000
#define DIALOGSETCURRLINE 1001
#define DIALOGKEYSETLABEL 1002
#define UI_INTERFACE_DOT 1003
#define UI_WINDOW_DOT 1004
#define UIWINDOW 1005
#define OMDOMNODE 1006
#define OMNODELIST 1007
#define USING_BTREE 1008
#define USING_RTREE 1009
#define BASECHANNEL 1010
#define UI_DOT_FORM_DOT 1011
#define DIALOG_DOT 1012
#define STRING 1013
#define KW_COMMENT 1014
#define KW_IMAGE 1015
#define DEBUG_FILE 1016
#define REPLACE_STRING 1028
#define STOP_REPLACE_STRING 1029
#define IGNORE_FUNCTION 1030
#define SET_BUFFERED_LOG 1033
#define SET_LOG 1034
#define MDY 1036
#define WEEKDAY 1037
#define MISC_INFX_SQL 1040
#define CONVERTING_VIA 1041
#define AS_CONVERTIBLE 1048
#define DATETIME_VALUE 1053
#define INTERVAL_VALUE 1054
#define RECOVER_TABLE 1055
#define ROLLFORWARD_DATABASE 1056
#define DROP_TRIGGER 1072
#define DROP_AUDIT_FOR 1073
#define CREATE_AUDIT_FOR 1074
#define EXECUTE_PROCEDURE 1078
#define ALTER_TABLE 1085
#define ALTER_INDEX 1086
#define NEXT_SIZE 1087
#define XSET_MULTIPLY_EQUAL_OPEN_BRACKET 1124
#define XSET_ident_DOT_MULTIPLY_EQUAL_OPEN_BRACKET 1125
#define XSET_ident_DOT_MULTIPLY_EQUAL 1126
#define XSET_MULTIPLY_EQUAL 1127
#define XSET_OPEN_BRACKET 1128
#define CREATE_DATABASE 1131
#define DROP_DATABASE 1132
#define ADD_CONSTRAINT 1134
#define DROP_CONSTRAINT 1135
#define DROP_SYNONYM 1136
#define CONSTRAINT 1137
#define KW_ARG_VAL 1143
#define DOUBLE_PRECISION 1144
#define COUNT_MULTIPLY 1145
#define MODIFY_NEXT_SIZE 1165
#define LOCK_MODE_PAGE 1166
#define LOCK_MODE_ROW 1167
#define UNITS_YEAR 1174
#define UNITS_MONTH 1175
#define UNITS_DAY 1176
#define UNITS_HOUR 1177
#define UNITS_MINUTE 1178
#define UNITS_SECOND 1179
#define TO_CLUSTER 1184
#define TO_NOT_CLUSTER 1185
#define CREATE_UC_IDX 1187
#define CREATE_U_IDX 1188
#define CREATE_C_IDX 1189
#define CREATE_IDX 1190
#define USE_MEMBER_FUNCTION 1200
#define USE_MEMBER_OF 1201
#define SQLSICS 1205
#define CREATE_SCHEMA 1206
#define SQLSIRR 1207
#define UPDATESTATS_T 1208
#define SQLSICR 1209
#define SQLSIDR 1220
#define CREATE_TEMP_TABLE 1221
#define WITH_CHECK_OPTION 1229
#define WITH_GRANT_OPTION 1230
#define SQLSLMNW 1231
#define WHERE_CURRENT_OF 1237
#define NOT_NULL_UNIQUE 1245
#define SQLSLMW 1252
#define ALL_PRIVILEGES 1254
#define CREATE_SYNONYM 1258
#define DROP_TABLE 1259
#define INEXCLUSIVE 1261
#define UPDATESTATS 1266
#define CREATE_TABLE 1292
#define DEFAULT_NULL 1293
#define DEFAULT_TODAY 1294
#define DEFAULT_USER 1295
#define UNLOCK_TABLE 1308
#define ROLLBACK_W 1316
#define SQLSEON 1318
#define SQLSEOFF 1319
#define CREATE_VIEW 1323
#define DELETE_FROM 1324
#define EXTENT_SIZE 1331
#define FOREIGN_KEY 1332
#define INSERT_INTO 1335
#define IS_NOT_NULL 1337
#define NOT_MATCHES 1340
#define PRIMARY_KEY 1346
#define USE_SESSION 1353
#define WITH_NO_LOG 1354
#define INSHARE 1357
#define BEGIN_WORK 1363
#define DROP_INDEX 1368
#define FOR_UPDATE_OF 1374
#define FOR_UPDATE 1375
#define LOCK_TABLE 1379
#define NOT_EXISTS 1381
#define REFERENCES 1383
#define RENCOL 1384
#define SMALLFLOAT 1386
#define COMMIT_W 1397
#define RENTAB 1404
#define KW_CHAR 1407
#define NCHAR 1408
#define NVARCHAR 1409
#define DELIMITER 1411
#define DROP_VIEW 1413
#define EXCLUSIVE 1416
#define GREATER_THAN_EQ 1420
#define INTO_TEMP 1422
#define LOAD_FROM 1426
#define UNLOAD_TO 1437
#define VARIABLE_ATTRIBUTES 1440
#define DATABASE 1447
#define DATETIME 1448
#define DISTINCT 1450
#define FRACTION 1457
#define GROUP_BY 1459
#define INTERVAL 1460
#define NOT_LIKE 1462
#define NOT_ILIKE 1463
#define NOT_NULL 1464
#define RESOURCE 1470
#define SMALLINT 1471
#define KW_WORDWRAP 1474
#define IS_NULL 1477
#define LESS_THAN_EQ 1478
#define BETWEEN 1480
#define KW_CLIPPED 1482
#define CLOSE_BRACKET 1483
#define CONNECT 1486
#define KW_CURRENT 1487
#define KW_DECIMAL 1489
#define DEFAULT 1491
#define INTEGER 1499
#define MATCHES 1502
#define VARCHAR 1515
#define CLOSE_SQUARE 1518
#define GREATER_THAN 1519
#define KW_FALSE 1520
#define NOT_IN 1521
#define OPEN_BRACKET 1523
#define KW_DELETE 1531
#define KW_ESCAPE 1534
#define EXISTS 1535
#define EXTEND 1536
#define HAVING 1540
#define KW_INSERT 1542
#define MINUTE 1546
#define MODIFY 1547
#define EQUAL 1549
#define NOT_EQUAL 1550
#define OPEN_SQUARE 1552
#define PUBLIC 1556
#define REVOKE 1559
#define SECOND 1563
#define KW_SELECT 1567
#define SERIAL 1568
#define KW_SPACES 1570
#define UNIQUE 1571
#define KW_UPDATE 1573
#define VALUES 1574
#define KW_NULL 1578
#define KW_TRUE 1579
#define ALTER 1581
#define KW_ASCII 1583
#define CHECK 1587
#define COUNT 1591
#define KW_FIRST 1596
#define KW_FLOAT 1597
#define GRANT 1600
#define INDEX 1603
#define LESS_THAN 1606
#define MONEY 1608
#define MONTH 1609
#define KW_POWER 1610
#define KW_MULTIPLY 1611
#define ORDER 1612
#define OUTER 1613
#define UNION 1622
#define WHERE 1624
#define KW_BYTE 1631
#define CASE 1633
#define KW_DATE 1635
#define DESC 1636
#define KW_DIVIDE 1637
#define DROP 1640
#define ELSE 1641
#define FROM 1645
#define HOUR 1651
#define INTO 1652
#define LIKE 1655
#define REAL 1664
#define SOME 1669
#define KW_TEXT 1673
#define KW_THEN 1674
#define USER 1675
#define WHEN 1677
#define YEAR 1680
#define KW_DOW 1681
#define XSET 1683
#define ADD 1684
#define ALL 1685
#define KW_AND 1686
#define ANY 1687
#define ASC 1688
#define AVG 1689
#define COLON 1690
#define KW_COMMA 1691
#define DAY 1692
#define DBA 1693
#define KW_FOR 1697
#define KW_KEY 1698
#define KW_LET 1700
#define XMAX 1702
#define XMIN 1703
#define KW_MINUS 1704
#define KW_MOD 1705
#define KW_NOT 1706
#define KW_PAD 1707
#define KW_PUT 1708
#define KW_RED 1709
#define KW_ROW 1710
#define KW_SQL 1712
#define KW_SUM 1713
#define KW_TOP 1714
#define KW_USE 1715
#define ATSIGN 1716
#define KW_PLUS 1717
#define KW_AS 1722
#define KW_AT 1723
#define KW_BY 1724
#define KW_DOT 1725
#define KW_GO 1726
#define KW_IF 1727
#define KW_IN 1728
#define KW_OF 1729
#define KW_ON 1730
#define KW_OR 1731
#define KW_TO 1732
#define BEFORE 1770
#define KW_INPUT_ARRAY 1771
#define END 1774
#define TILDE 1781
#define ILIKE 1782
#define FILLFACTOR 1785
#define TIME 1790
#define KW_TODAY 1797
#define KW_IDLE 2137
#define CANCEL_INSERT 2138
#define CANCEL_DELETE 2139
#define FORCE_UI 2140
#define FGL_MODULE 2141
#define VIA 2142
#define SLICE 2143




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
#line 646 "y.tab.h"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE sqlparse_yylval;

