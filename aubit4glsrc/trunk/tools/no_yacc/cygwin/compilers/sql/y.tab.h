/* A Bison parser, made by GNU Bison 2.1.  */

/* Skeleton parser for Yacc-like parsing with Bison,
   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005 Free Software Foundation, Inc.

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

/* As a special exception, when this file is copied by Bison into a
   Bison output file, you may use that output file without restriction.
   This special exception was added by the Free Software Foundation
   in version 1.24 of Bison.  */

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     INT_VALUE = 2124,
     NAMED = 2125,
     NAMED_GEN = 2126,
     CHAR_VALUE = 2127,
     NOT_USED_1 = 2128,
     NOT_USED_2 = 2129,
     NOT_USED_3 = 2130,
     NOT_USED_4 = 2131,
     NOT_USED_5 = 2132,
     NOT_USED_6 = 2133,
     NOT_USED_7 = 2134,
     NOT_USED_8 = 2135,
     NUMBER_VALUE = 2136,
     SEMICOLON = 2137,
     QUESTION_MARK = 2138,
     CLINE = 2139,
     CH = 2140,
     MARK_VAR = 2141,
     END_MARK_VAR = 2142,
     DIALOGSETCURRLINE = 1001,
     DIALOGKEYSETLABEL = 1002,
     DIALOGX = 1003,
     REPLACE_STRING = 1015,
     STOP_REPLACE_STRING = 1016,
     IGNORE_FUNCTION = 1017,
     SET_BUFFERED_LOG = 1020,
     SET_LOG = 1021,
     MDY = 1023,
     WEEKDAY = 1024,
     MISC_INFX_SQL = 1027,
     DATETIME_VALUE = 1039,
     INTERVAL_VALUE = 1040,
     RECOVER_TABLE = 1041,
     ROLLFORWARD_DATABASE = 1042,
     DROP_TRIGGER = 1057,
     DROP_AUDIT_FOR = 1058,
     CREATE_AUDIT_FOR = 1059,
     EXECUTE_PROCEDURE = 1063,
     ALTER_TABLE = 1070,
     ALTER_INDEX = 1071,
     NEXT_SIZE = 1072,
     XSET_MULTIPLY_EQUAL_OPEN_BRACKET = 1109,
     XSET_ident_DOT_MULTIPLY_EQUAL_OPEN_BRACKET = 1110,
     XSET_ident_DOT_MULTIPLY_EQUAL = 1111,
     XSET_MULTIPLY_EQUAL = 1112,
     XSET_OPEN_BRACKET = 1113,
     CREATE_DATABASE = 1116,
     DROP_DATABASE = 1117,
     ADD_CONSTRAINT = 1119,
     DROP_CONSTRAINT = 1120,
     DROP_SYNONYM = 1121,
     CONSTRAINT = 1122,
     KW_ARG_VAL = 1128,
     DOUBLE_PRECISION = 1129,
     COUNT_MULTIPLY = 1130,
     MODIFY_NEXT_SIZE = 1150,
     LOCK_MODE_PAGE = 1151,
     LOCK_MODE_ROW = 1152,
     UNITS_YEAR = 1159,
     UNITS_MONTH = 1160,
     UNITS_DAY = 1161,
     UNITS_HOUR = 1162,
     UNITS_MINUTE = 1163,
     UNITS_SECOND = 1164,
     TO_CLUSTER = 1169,
     TO_NOT_CLUSTER = 1170,
     CREATE_UC_IDX = 1172,
     CREATE_U_IDX = 1173,
     CREATE_C_IDX = 1174,
     CREATE_IDX = 1175,
     SQLSICS = 1188,
     CREATE_SCHEMA = 1189,
     SQLSIRR = 1190,
     UPDATESTATS_T = 1191,
     SQLSICR = 1192,
     SQLSIDR = 1203,
     CREATE_TEMP_TABLE = 1204,
     WITH_CHECK_OPTION = 1212,
     WITH_GRANT_OPTION = 1213,
     SQLSLMNW = 1214,
     WHERE_CURRENT_OF = 1220,
     NOT_NULL_UNIQUE = 1228,
     SQLSLMW = 1235,
     ALL_PRIVILEGES = 1237,
     CREATE_SYNONYM = 1241,
     DROP_TABLE = 1242,
     INEXCLUSIVE = 1244,
     UPDATESTATS = 1249,
     CREATE_TABLE = 1275,
     DEFAULT_NULL = 1276,
     DEFAULT_TODAY = 1277,
     DEFAULT_USER = 1278,
     UNLOCK_TABLE = 1291,
     ROLLBACK_W = 1299,
     SQLSEON = 1301,
     SQLSEOFF = 1302,
     CREATE_VIEW = 1306,
     DELETE_FROM = 1307,
     EXTENT_SIZE = 1314,
     FOREIGN_KEY = 1315,
     INSERT_INTO = 1318,
     IS_NOT_NULL = 1320,
     NOT_MATCHES = 1323,
     PRIMARY_KEY = 1329,
     USE_SESSION = 1336,
     WITH_NO_LOG = 1337,
     INSHARE = 1340,
     BEGIN_WORK = 1346,
     DROP_INDEX = 1351,
     FOR_UPDATE_OF = 1357,
     FOR_UPDATE = 1358,
     LOCK_TABLE = 1362,
     NOT_EXISTS = 1364,
     REFERENCES = 1366,
     RENCOL = 1367,
     SMALLFLOAT = 1369,
     COMMIT_W = 1380,
     RENTAB = 1387,
     KW_CHAR = 1390,
     NCHAR = 1391,
     NVARCHAR = 1392,
     DELIMITER = 1394,
     DROP_VIEW = 1396,
     EXCLUSIVE = 1399,
     GREATER_THAN_EQ = 1403,
     INTO_TEMP = 1405,
     LOAD_FROM = 1409,
     UNLOAD_TO = 1420,
     VARIABLE_ATTRIBUTES = 1423,
     DATABASE = 1430,
     DATETIME = 1431,
     DISTINCT = 1433,
     FRACTION = 1440,
     GROUP_BY = 1442,
     INTERVAL = 1443,
     NOT_LIKE = 1445,
     NOT_ILIKE = 1446,
     NOT_NULL = 1447,
     RESOURCE = 1453,
     SMALLINT = 1454,
     IS_NULL = 1460,
     LESS_THAN_EQ = 1461,
     BETWEEN = 1463,
     CLOSE_BRACKET = 1466,
     CONNECT = 1469,
     KW_CURRENT = 1470,
     KW_DECIMAL = 1472,
     DEFAULT = 1474,
     INTEGER = 1482,
     MATCHES = 1485,
     VARCHAR = 1498,
     CLOSE_SQUARE = 1501,
     GREATER_THAN = 1502,
     KW_FALSE = 1503,
     NOT_IN = 1504,
     OPEN_BRACKET = 1506,
     KW_DELETE = 1514,
     KW_ESCAPE = 1517,
     EXISTS = 1518,
     EXTEND = 1519,
     HAVING = 1523,
     KW_INSERT = 1525,
     MINUTE = 1529,
     MODIFY = 1530,
     EQUAL = 1532,
     NOT_EQUAL = 1533,
     OPEN_SQUARE = 1535,
     PUBLIC = 1539,
     REVOKE = 1542,
     SECOND = 1546,
     KW_SELECT = 1550,
     SERIAL = 1551,
     UNIQUE = 1554,
     KW_UPDATE = 1556,
     VALUES = 1557,
     KW_NULL = 1561,
     KW_TRUE = 1562,
     ALTER = 1564,
     CHECK = 1570,
     COUNT = 1574,
     KW_FIRST = 1579,
     KW_FLOAT = 1580,
     GRANT = 1583,
     INDEX = 1586,
     LESS_THAN = 1589,
     MONEY = 1591,
     MONTH = 1592,
     MULTIPLY = 1594,
     ORDER = 1595,
     OUTER = 1596,
     UNION = 1606,
     WHERE = 1608,
     KW_BYTE = 1615,
     CASE = 1617,
     KW_DATE = 1619,
     DESC = 1620,
     DIVIDE = 1621,
     DROP = 1624,
     ELSE = 1625,
     FROM = 1629,
     HOUR = 1635,
     INTO = 1636,
     LIKE = 1639,
     REAL = 1648,
     SOME = 1653,
     KW_TEXT = 1657,
     THEN = 1658,
     USER = 1659,
     WHEN = 1661,
     YEAR = 1664,
     KW_DOW = 1665,
     XSET = 1667,
     ADD = 1668,
     ALL = 1669,
     KW_AND = 1670,
     ANY = 1671,
     ASC = 1672,
     AVG = 1673,
     COLON = 1674,
     KW_COMMA = 1675,
     DAY = 1676,
     DBA = 1677,
     FOR = 1681,
     XMAX = 1686,
     XMIN = 1687,
     MINUS = 1688,
     NOT = 1690,
     SUM = 1697,
     ATSIGN = 1700,
     PLUS = 1701,
     AS = 1706,
     BY = 1708,
     DOT = 1709,
     KW_IN = 1712,
     KW_ON = 1714,
     KW_OR = 1715,
     TO = 1716,
     BEFORE = 1754,
     END = 1757,
     TILDE = 1764,
     ILIKE = 1765,
     FILLFACTOR = 1768,
     TIME = 1773,
     KW_TODAY = 1780,
     KW_IDLE = 2120,
     CANCEL_INSERT = 2121,
     CANCEL_DELETE = 2122
   };
#endif
/* Tokens.  */
#define INT_VALUE 2124
#define NAMED 2125
#define NAMED_GEN 2126
#define CHAR_VALUE 2127
#define NOT_USED_1 2128
#define NOT_USED_2 2129
#define NOT_USED_3 2130
#define NOT_USED_4 2131
#define NOT_USED_5 2132
#define NOT_USED_6 2133
#define NOT_USED_7 2134
#define NOT_USED_8 2135
#define NUMBER_VALUE 2136
#define SEMICOLON 2137
#define QUESTION_MARK 2138
#define CLINE 2139
#define CH 2140
#define MARK_VAR 2141
#define END_MARK_VAR 2142
#define DIALOGSETCURRLINE 1001
#define DIALOGKEYSETLABEL 1002
#define DIALOGX 1003
#define REPLACE_STRING 1015
#define STOP_REPLACE_STRING 1016
#define IGNORE_FUNCTION 1017
#define SET_BUFFERED_LOG 1020
#define SET_LOG 1021
#define MDY 1023
#define WEEKDAY 1024
#define MISC_INFX_SQL 1027
#define DATETIME_VALUE 1039
#define INTERVAL_VALUE 1040
#define RECOVER_TABLE 1041
#define ROLLFORWARD_DATABASE 1042
#define DROP_TRIGGER 1057
#define DROP_AUDIT_FOR 1058
#define CREATE_AUDIT_FOR 1059
#define EXECUTE_PROCEDURE 1063
#define ALTER_TABLE 1070
#define ALTER_INDEX 1071
#define NEXT_SIZE 1072
#define XSET_MULTIPLY_EQUAL_OPEN_BRACKET 1109
#define XSET_ident_DOT_MULTIPLY_EQUAL_OPEN_BRACKET 1110
#define XSET_ident_DOT_MULTIPLY_EQUAL 1111
#define XSET_MULTIPLY_EQUAL 1112
#define XSET_OPEN_BRACKET 1113
#define CREATE_DATABASE 1116
#define DROP_DATABASE 1117
#define ADD_CONSTRAINT 1119
#define DROP_CONSTRAINT 1120
#define DROP_SYNONYM 1121
#define CONSTRAINT 1122
#define KW_ARG_VAL 1128
#define DOUBLE_PRECISION 1129
#define COUNT_MULTIPLY 1130
#define MODIFY_NEXT_SIZE 1150
#define LOCK_MODE_PAGE 1151
#define LOCK_MODE_ROW 1152
#define UNITS_YEAR 1159
#define UNITS_MONTH 1160
#define UNITS_DAY 1161
#define UNITS_HOUR 1162
#define UNITS_MINUTE 1163
#define UNITS_SECOND 1164
#define TO_CLUSTER 1169
#define TO_NOT_CLUSTER 1170
#define CREATE_UC_IDX 1172
#define CREATE_U_IDX 1173
#define CREATE_C_IDX 1174
#define CREATE_IDX 1175
#define SQLSICS 1188
#define CREATE_SCHEMA 1189
#define SQLSIRR 1190
#define UPDATESTATS_T 1191
#define SQLSICR 1192
#define SQLSIDR 1203
#define CREATE_TEMP_TABLE 1204
#define WITH_CHECK_OPTION 1212
#define WITH_GRANT_OPTION 1213
#define SQLSLMNW 1214
#define WHERE_CURRENT_OF 1220
#define NOT_NULL_UNIQUE 1228
#define SQLSLMW 1235
#define ALL_PRIVILEGES 1237
#define CREATE_SYNONYM 1241
#define DROP_TABLE 1242
#define INEXCLUSIVE 1244
#define UPDATESTATS 1249
#define CREATE_TABLE 1275
#define DEFAULT_NULL 1276
#define DEFAULT_TODAY 1277
#define DEFAULT_USER 1278
#define UNLOCK_TABLE 1291
#define ROLLBACK_W 1299
#define SQLSEON 1301
#define SQLSEOFF 1302
#define CREATE_VIEW 1306
#define DELETE_FROM 1307
#define EXTENT_SIZE 1314
#define FOREIGN_KEY 1315
#define INSERT_INTO 1318
#define IS_NOT_NULL 1320
#define NOT_MATCHES 1323
#define PRIMARY_KEY 1329
#define USE_SESSION 1336
#define WITH_NO_LOG 1337
#define INSHARE 1340
#define BEGIN_WORK 1346
#define DROP_INDEX 1351
#define FOR_UPDATE_OF 1357
#define FOR_UPDATE 1358
#define LOCK_TABLE 1362
#define NOT_EXISTS 1364
#define REFERENCES 1366
#define RENCOL 1367
#define SMALLFLOAT 1369
#define COMMIT_W 1380
#define RENTAB 1387
#define KW_CHAR 1390
#define NCHAR 1391
#define NVARCHAR 1392
#define DELIMITER 1394
#define DROP_VIEW 1396
#define EXCLUSIVE 1399
#define GREATER_THAN_EQ 1403
#define INTO_TEMP 1405
#define LOAD_FROM 1409
#define UNLOAD_TO 1420
#define VARIABLE_ATTRIBUTES 1423
#define DATABASE 1430
#define DATETIME 1431
#define DISTINCT 1433
#define FRACTION 1440
#define GROUP_BY 1442
#define INTERVAL 1443
#define NOT_LIKE 1445
#define NOT_ILIKE 1446
#define NOT_NULL 1447
#define RESOURCE 1453
#define SMALLINT 1454
#define IS_NULL 1460
#define LESS_THAN_EQ 1461
#define BETWEEN 1463
#define CLOSE_BRACKET 1466
#define CONNECT 1469
#define KW_CURRENT 1470
#define KW_DECIMAL 1472
#define DEFAULT 1474
#define INTEGER 1482
#define MATCHES 1485
#define VARCHAR 1498
#define CLOSE_SQUARE 1501
#define GREATER_THAN 1502
#define KW_FALSE 1503
#define NOT_IN 1504
#define OPEN_BRACKET 1506
#define KW_DELETE 1514
#define KW_ESCAPE 1517
#define EXISTS 1518
#define EXTEND 1519
#define HAVING 1523
#define KW_INSERT 1525
#define MINUTE 1529
#define MODIFY 1530
#define EQUAL 1532
#define NOT_EQUAL 1533
#define OPEN_SQUARE 1535
#define PUBLIC 1539
#define REVOKE 1542
#define SECOND 1546
#define KW_SELECT 1550
#define SERIAL 1551
#define UNIQUE 1554
#define KW_UPDATE 1556
#define VALUES 1557
#define KW_NULL 1561
#define KW_TRUE 1562
#define ALTER 1564
#define CHECK 1570
#define COUNT 1574
#define KW_FIRST 1579
#define KW_FLOAT 1580
#define GRANT 1583
#define INDEX 1586
#define LESS_THAN 1589
#define MONEY 1591
#define MONTH 1592
#define MULTIPLY 1594
#define ORDER 1595
#define OUTER 1596
#define UNION 1606
#define WHERE 1608
#define KW_BYTE 1615
#define CASE 1617
#define KW_DATE 1619
#define DESC 1620
#define DIVIDE 1621
#define DROP 1624
#define ELSE 1625
#define FROM 1629
#define HOUR 1635
#define INTO 1636
#define LIKE 1639
#define REAL 1648
#define SOME 1653
#define KW_TEXT 1657
#define THEN 1658
#define USER 1659
#define WHEN 1661
#define YEAR 1664
#define KW_DOW 1665
#define XSET 1667
#define ADD 1668
#define ALL 1669
#define KW_AND 1670
#define ANY 1671
#define ASC 1672
#define AVG 1673
#define COLON 1674
#define KW_COMMA 1675
#define DAY 1676
#define DBA 1677
#define FOR 1681
#define XMAX 1686
#define XMIN 1687
#define MINUS 1688
#define NOT 1690
#define SUM 1697
#define ATSIGN 1700
#define PLUS 1701
#define AS 1706
#define BY 1708
#define DOT 1709
#define KW_IN 1712
#define KW_ON 1714
#define KW_OR 1715
#define TO 1716
#define BEFORE 1754
#define END 1757
#define TILDE 1764
#define ILIKE 1765
#define FILLFACTOR 1768
#define TIME 1773
#define KW_TODAY 1780
#define KW_IDLE 2120
#define CANCEL_INSERT 2121
#define CANCEL_DELETE 2122




#if ! defined (YYSTYPE) && ! defined (YYSTYPE_IS_DECLARED)
#line 174 "sql.yacc"
typedef union YYSTYPE {
        char    str[1024];
   char *sql_string;
	struct  ilist int_list;
	struct s_table *u_table;
	struct s_select_finish *s_select_finish;
        struct s_select_list_item_list *s_select_list_item_list;
        struct s_select_list_item *s_select_list_item;
        struct s_select *s_select;
        int     integer_val;
        float   float_val;


} YYSTYPE;
/* Line 1447 of yacc.c.  */
#line 551 "y.tab.h"
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE sqlparse_yylval;



