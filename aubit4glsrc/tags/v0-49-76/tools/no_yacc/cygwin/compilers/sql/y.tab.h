/* A Bison parser, made by GNU Bison 1.875.  */

/* Skeleton parser for Yacc-like parsing with Bison,
   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002 Free Software Foundation, Inc.

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
   Foundation, Inc., 59 Temple Place - Suite 330,
   Boston, MA 02111-1307, USA.  */

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
     INT_VALUE = 1766,
     NAMED = 1767,
     NAMED_GEN = 1768,
     CHAR_VALUE = 1769,
     NOT_USED_1 = 1770,
     NOT_USED_2 = 1771,
     NOT_USED_3 = 1772,
     NOT_USED_4 = 1773,
     NOT_USED_5 = 1774,
     NOT_USED_6 = 1775,
     NOT_USED_7 = 1776,
     NOT_USED_8 = 1777,
     NUMBER_VALUE = 1778,
     SEMICOLON = 1779,
     QUESTION_MARK = 1780,
     CLINE = 1781,
     CH = 1782,
     EMULATE_INSERT_CURSOR_FOR = 1012,
     MISC_INFX_SQL = 1014,
     PRAGMA = 1015,
     MDY = 1016,
     WEEKDAY = 1017,
     SYSTEM_4GL = 1018,
     SQL_FEATURE = 1019,
     DATETIME_VALUE = 1031,
     INTERVAL_VALUE = 1032,
     RECOVER_TABLE = 1033,
     ROLLFORWARD_DATABASE = 1034,
     FGL_ADDRESSOF = 1038,
     DROP_TRIGGER = 1049,
     DROP_AUDIT_FOR = 1050,
     CREATE_AUDIT_FOR = 1051,
     ALTER_TABLE = 1061,
     ALTER_INDEX = 1062,
     NEXT_SIZE = 1063,
     XSET_MULTIPLY_EQUAL_OPEN_BRACKET = 1100,
     XSET_ident_DOT_MULTIPLY_EQUAL_OPEN_BRACKET = 1101,
     XSET_ident_DOT_MULTIPLY_EQUAL = 1102,
     XSET_MULTIPLY_EQUAL = 1103,
     XSET_OPEN_BRACKET = 1104,
     CREATE_DATABASE = 1107,
     DROP_DATABASE = 1108,
     ADD_CONSTRAINT = 1110,
     DROP_CONSTRAINT = 1111,
     DROP_SYNONYM = 1112,
     CONSTRAINT = 1113,
     DOUBLE_PRECISION = 1119,
     COUNT_MULTIPLY = 1120,
     MODIFY_NEXT_SIZE = 1140,
     LOCK_MODE_PAGE = 1141,
     LOCK_MODE_ROW = 1142,
     UNITS_YEAR = 1149,
     UNITS_MONTH = 1150,
     UNITS_DAY = 1151,
     UNITS_HOUR = 1152,
     UNITS_MINUTE = 1153,
     UNITS_SECOND = 1154,
     TO_CLUSTER = 1159,
     TO_NOT_CLUSTER = 1160,
     CREATE_UC_IDX = 1162,
     CREATE_U_IDX = 1163,
     CREATE_C_IDX = 1164,
     CREATE_IDX = 1165,
     SQLSICS = 1178,
     CREATE_SCHEMA = 1179,
     SQLSIRR = 1180,
     UPDATESTATS_T = 1181,
     SQLSICR = 1182,
     SQLSIDR = 1193,
     CREATE_TEMP_TABLE = 1194,
     WITH_CHECK_OPTION = 1202,
     WITH_GRANT_OPTION = 1203,
     SQLSLMNW = 1204,
     WHERE_CURRENT_OF = 1210,
     NOT_NULL_UNIQUE = 1218,
     SQLSLMW = 1225,
     ALL_PRIVILEGES = 1227,
     CREATE_SYNONYM = 1231,
     DROP_TABLE = 1232,
     INEXCLUSIVE = 1234,
     UPDATESTATS = 1239,
     CREATE_TABLE = 1265,
     DEFAULT_NULL = 1266,
     DEFAULT_TODAY = 1267,
     DEFAULT_USER = 1268,
     UNLOCK_TABLE = 1281,
     ROLLBACK_W = 1289,
     SQLSEOFF = 1291,
     CREATE_VIEW = 1295,
     DELETE_FROM = 1296,
     EXTENT_SIZE = 1303,
     FOREIGN_KEY = 1304,
     INSERT_INTO = 1307,
     IS_NOT_NULL = 1308,
     PRIMARY_KEY = 1317,
     USE_SESSION = 1325,
     WITH_NO_LOG = 1326,
     INSHARE = 1329,
     BEGIN_WORK = 1334,
     DROP_INDEX = 1339,
     FOR_UPDATE_OF = 1345,
     FOR_UPDATE = 1346,
     LOCK_TABLE = 1350,
     NOT_EXISTS = 1352,
     REFERENCES = 1354,
     RENCOL = 1355,
     SMALLFLOAT = 1357,
     COMMIT_W = 1367,
     RENTAB = 1374,
     KW_CHAR = 1377,
     NCHAR = 1378,
     NVARCHAR = 1379,
     DELIMITER = 1381,
     DROP_VIEW = 1383,
     EXCLUSIVE = 1386,
     GREATER_THAN_EQ = 1390,
     INTO_TEMP = 1392,
     LOAD_FROM = 1396,
     UNLOAD_TO = 1407,
     DATABASE = 1416,
     DATETIME = 1417,
     DISTINCT = 1419,
     FRACTION = 1426,
     GROUP_BY = 1428,
     INTERVAL = 1429,
     NOT_LIKE = 1431,
     NOT_ILIKE = 1432,
     NOT_NULL = 1433,
     RESOURCE = 1439,
     SMALLINT = 1440,
     IS_NULL = 1446,
     LESS_THAN_EQ = 1447,
     BETWEEN = 1449,
     CLOSE_BRACKET = 1452,
     CONNECT = 1455,
     CURRENT = 1456,
     KW_DECIMAL = 1458,
     DEFAULT = 1460,
     INTEGER = 1468,
     MATCHES = 1471,
     VARCHAR = 1484,
     CLOSE_SQUARE = 1487,
     GREATER_THAN = 1488,
     KW_FALSE = 1489,
     NOT_IN = 1490,
     OPEN_BRACKET = 1492,
     DELETE = 1500,
     ESCAPE = 1503,
     EXISTS = 1504,
     EXTEND = 1505,
     HAVING = 1509,
     INSERT = 1511,
     MINUTE = 1515,
     MODIFY = 1516,
     NOT_EQUAL = 1519,
     OPEN_SQUARE = 1521,
     PUBLIC = 1525,
     REVOKE = 1528,
     SECOND = 1532,
     SELECT = 1533,
     SERIAL = 1534,
     UNIQUE = 1537,
     UPDATE = 1539,
     VALUES = 1540,
     KW_NULL = 1544,
     KW_TRUE = 1545,
     ALTER = 1547,
     CHECK = 1553,
     COUNT = 1557,
     KW_FLOAT = 1563,
     GRANT = 1566,
     INDEX = 1569,
     LESS_THAN = 1572,
     MONEY = 1574,
     MONTH = 1575,
     MULTIPLY = 1577,
     ORDER = 1578,
     OUTER = 1579,
     UNION = 1589,
     WHERE = 1591,
     KW_BYTE = 1598,
     KW_DATE = 1602,
     DESC = 1603,
     DIVIDE = 1604,
     DROP = 1607,
     FROM = 1612,
     HOUR = 1618,
     INTO = 1619,
     LIKE = 1622,
     REAL = 1631,
     SOME = 1636,
     TEXT = 1640,
     USER = 1642,
     YEAR = 1647,
     KW_DOW = 1648,
     EQUAL = 1649,
     XSET = 1651,
     ADD = 1652,
     ALL = 1653,
     KW_AND = 1654,
     ANY = 1655,
     ASC = 1656,
     AVG = 1657,
     COLON = 1658,
     KW_COMMA = 1659,
     DAY = 1660,
     DBA = 1661,
     FOR = 1665,
     XMAX = 1670,
     XMIN = 1671,
     MINUS = 1672,
     NOT = 1674,
     SUM = 1681,
     ATSIGN = 1684,
     PLUS = 1685,
     AS = 1690,
     BY = 1692,
     DOT = 1693,
     IN = 1696,
     ON = 1698,
     KW_OR = 1699,
     TO = 1700,
     BEFORE = 1738,
     TILDE = 1748,
     ILIKE = 1749,
     FILLFACTOR = 1752,
     KW_TODAY = 1764
   };
#endif
#define INT_VALUE 1766
#define NAMED 1767
#define NAMED_GEN 1768
#define CHAR_VALUE 1769
#define NOT_USED_1 1770
#define NOT_USED_2 1771
#define NOT_USED_3 1772
#define NOT_USED_4 1773
#define NOT_USED_5 1774
#define NOT_USED_6 1775
#define NOT_USED_7 1776
#define NOT_USED_8 1777
#define NUMBER_VALUE 1778
#define SEMICOLON 1779
#define QUESTION_MARK 1780
#define CLINE 1781
#define CH 1782
#define EMULATE_INSERT_CURSOR_FOR 1012
#define MISC_INFX_SQL 1014
#define PRAGMA 1015
#define MDY 1016
#define WEEKDAY 1017
#define SYSTEM_4GL 1018
#define SQL_FEATURE 1019
#define DATETIME_VALUE 1031
#define INTERVAL_VALUE 1032
#define RECOVER_TABLE 1033
#define ROLLFORWARD_DATABASE 1034
#define FGL_ADDRESSOF 1038
#define DROP_TRIGGER 1049
#define DROP_AUDIT_FOR 1050
#define CREATE_AUDIT_FOR 1051
#define ALTER_TABLE 1061
#define ALTER_INDEX 1062
#define NEXT_SIZE 1063
#define XSET_MULTIPLY_EQUAL_OPEN_BRACKET 1100
#define XSET_ident_DOT_MULTIPLY_EQUAL_OPEN_BRACKET 1101
#define XSET_ident_DOT_MULTIPLY_EQUAL 1102
#define XSET_MULTIPLY_EQUAL 1103
#define XSET_OPEN_BRACKET 1104
#define CREATE_DATABASE 1107
#define DROP_DATABASE 1108
#define ADD_CONSTRAINT 1110
#define DROP_CONSTRAINT 1111
#define DROP_SYNONYM 1112
#define CONSTRAINT 1113
#define DOUBLE_PRECISION 1119
#define COUNT_MULTIPLY 1120
#define MODIFY_NEXT_SIZE 1140
#define LOCK_MODE_PAGE 1141
#define LOCK_MODE_ROW 1142
#define UNITS_YEAR 1149
#define UNITS_MONTH 1150
#define UNITS_DAY 1151
#define UNITS_HOUR 1152
#define UNITS_MINUTE 1153
#define UNITS_SECOND 1154
#define TO_CLUSTER 1159
#define TO_NOT_CLUSTER 1160
#define CREATE_UC_IDX 1162
#define CREATE_U_IDX 1163
#define CREATE_C_IDX 1164
#define CREATE_IDX 1165
#define SQLSICS 1178
#define CREATE_SCHEMA 1179
#define SQLSIRR 1180
#define UPDATESTATS_T 1181
#define SQLSICR 1182
#define SQLSIDR 1193
#define CREATE_TEMP_TABLE 1194
#define WITH_CHECK_OPTION 1202
#define WITH_GRANT_OPTION 1203
#define SQLSLMNW 1204
#define WHERE_CURRENT_OF 1210
#define NOT_NULL_UNIQUE 1218
#define SQLSLMW 1225
#define ALL_PRIVILEGES 1227
#define CREATE_SYNONYM 1231
#define DROP_TABLE 1232
#define INEXCLUSIVE 1234
#define UPDATESTATS 1239
#define CREATE_TABLE 1265
#define DEFAULT_NULL 1266
#define DEFAULT_TODAY 1267
#define DEFAULT_USER 1268
#define UNLOCK_TABLE 1281
#define ROLLBACK_W 1289
#define SQLSEOFF 1291
#define CREATE_VIEW 1295
#define DELETE_FROM 1296
#define EXTENT_SIZE 1303
#define FOREIGN_KEY 1304
#define INSERT_INTO 1307
#define IS_NOT_NULL 1308
#define PRIMARY_KEY 1317
#define USE_SESSION 1325
#define WITH_NO_LOG 1326
#define INSHARE 1329
#define BEGIN_WORK 1334
#define DROP_INDEX 1339
#define FOR_UPDATE_OF 1345
#define FOR_UPDATE 1346
#define LOCK_TABLE 1350
#define NOT_EXISTS 1352
#define REFERENCES 1354
#define RENCOL 1355
#define SMALLFLOAT 1357
#define COMMIT_W 1367
#define RENTAB 1374
#define KW_CHAR 1377
#define NCHAR 1378
#define NVARCHAR 1379
#define DELIMITER 1381
#define DROP_VIEW 1383
#define EXCLUSIVE 1386
#define GREATER_THAN_EQ 1390
#define INTO_TEMP 1392
#define LOAD_FROM 1396
#define UNLOAD_TO 1407
#define DATABASE 1416
#define DATETIME 1417
#define DISTINCT 1419
#define FRACTION 1426
#define GROUP_BY 1428
#define INTERVAL 1429
#define NOT_LIKE 1431
#define NOT_ILIKE 1432
#define NOT_NULL 1433
#define RESOURCE 1439
#define SMALLINT 1440
#define IS_NULL 1446
#define LESS_THAN_EQ 1447
#define BETWEEN 1449
#define CLOSE_BRACKET 1452
#define CONNECT 1455
#define CURRENT 1456
#define KW_DECIMAL 1458
#define DEFAULT 1460
#define INTEGER 1468
#define MATCHES 1471
#define VARCHAR 1484
#define CLOSE_SQUARE 1487
#define GREATER_THAN 1488
#define KW_FALSE 1489
#define NOT_IN 1490
#define OPEN_BRACKET 1492
#define DELETE 1500
#define ESCAPE 1503
#define EXISTS 1504
#define EXTEND 1505
#define HAVING 1509
#define INSERT 1511
#define MINUTE 1515
#define MODIFY 1516
#define NOT_EQUAL 1519
#define OPEN_SQUARE 1521
#define PUBLIC 1525
#define REVOKE 1528
#define SECOND 1532
#define SELECT 1533
#define SERIAL 1534
#define UNIQUE 1537
#define UPDATE 1539
#define VALUES 1540
#define KW_NULL 1544
#define KW_TRUE 1545
#define ALTER 1547
#define CHECK 1553
#define COUNT 1557
#define KW_FLOAT 1563
#define GRANT 1566
#define INDEX 1569
#define LESS_THAN 1572
#define MONEY 1574
#define MONTH 1575
#define MULTIPLY 1577
#define ORDER 1578
#define OUTER 1579
#define UNION 1589
#define WHERE 1591
#define KW_BYTE 1598
#define KW_DATE 1602
#define DESC 1603
#define DIVIDE 1604
#define DROP 1607
#define FROM 1612
#define HOUR 1618
#define INTO 1619
#define LIKE 1622
#define REAL 1631
#define SOME 1636
#define TEXT 1640
#define USER 1642
#define YEAR 1647
#define KW_DOW 1648
#define EQUAL 1649
#define XSET 1651
#define ADD 1652
#define ALL 1653
#define KW_AND 1654
#define ANY 1655
#define ASC 1656
#define AVG 1657
#define COLON 1658
#define KW_COMMA 1659
#define DAY 1660
#define DBA 1661
#define FOR 1665
#define XMAX 1670
#define XMIN 1671
#define MINUS 1672
#define NOT 1674
#define SUM 1681
#define ATSIGN 1684
#define PLUS 1685
#define AS 1690
#define BY 1692
#define DOT 1693
#define IN 1696
#define ON 1698
#define KW_OR 1699
#define TO 1700
#define BEFORE 1738
#define TILDE 1748
#define ILIKE 1749
#define FILLFACTOR 1752
#define KW_TODAY 1764




#if ! defined (YYSTYPE) && ! defined (YYSTYPE_IS_DECLARED)
#line 151 "sql.yacc"
typedef union YYSTYPE {
        char    str[1024];
   char *sql_string;
	struct  ilist int_list;

} YYSTYPE;
/* Line 1248 of yacc.c.  */
#line 501 "y.tab.h"
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE sqlparse_yylval;



