/* A Bison parser, made by GNU Bison 1.875d.  */

/* Skeleton parser for Yacc-like parsing with Bison,
   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004 Free Software Foundation, Inc.

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
     INT_VALUE = 2121,
     NAMED = 2122,
     NAMED_GEN = 2123,
     CHAR_VALUE = 2124,
     NOT_USED_1 = 2125,
     NOT_USED_2 = 2126,
     NOT_USED_3 = 2127,
     NOT_USED_4 = 2128,
     NOT_USED_5 = 2129,
     NOT_USED_6 = 2130,
     NOT_USED_7 = 2131,
     NOT_USED_8 = 2132,
     NUMBER_VALUE = 2133,
     SEMICOLON = 2134,
     QUESTION_MARK = 2135,
     CLINE = 2136,
     CH = 2137,
     REPLACE_STRING = 1012,
     STOP_REPLACE_STRING = 1013,
     IGNORE_FUNCTION = 1014,
     SET_BUFFERED_LOG = 1017,
     SET_LOG = 1018,
     MDY = 1020,
     WEEKDAY = 1021,
     MISC_INFX_SQL = 1024,
     DATETIME_VALUE = 1036,
     INTERVAL_VALUE = 1037,
     RECOVER_TABLE = 1038,
     ROLLFORWARD_DATABASE = 1039,
     DROP_TRIGGER = 1054,
     DROP_AUDIT_FOR = 1055,
     CREATE_AUDIT_FOR = 1056,
     EXECUTE_PROCEDURE = 1060,
     ALTER_TABLE = 1067,
     ALTER_INDEX = 1068,
     NEXT_SIZE = 1069,
     XSET_MULTIPLY_EQUAL_OPEN_BRACKET = 1106,
     XSET_ident_DOT_MULTIPLY_EQUAL_OPEN_BRACKET = 1107,
     XSET_ident_DOT_MULTIPLY_EQUAL = 1108,
     XSET_MULTIPLY_EQUAL = 1109,
     XSET_OPEN_BRACKET = 1110,
     CREATE_DATABASE = 1113,
     DROP_DATABASE = 1114,
     ADD_CONSTRAINT = 1116,
     DROP_CONSTRAINT = 1117,
     DROP_SYNONYM = 1118,
     CONSTRAINT = 1119,
     KW_ARG_VAL = 1125,
     DOUBLE_PRECISION = 1126,
     COUNT_MULTIPLY = 1127,
     MODIFY_NEXT_SIZE = 1147,
     LOCK_MODE_PAGE = 1148,
     LOCK_MODE_ROW = 1149,
     UNITS_YEAR = 1156,
     UNITS_MONTH = 1157,
     UNITS_DAY = 1158,
     UNITS_HOUR = 1159,
     UNITS_MINUTE = 1160,
     UNITS_SECOND = 1161,
     TO_CLUSTER = 1166,
     TO_NOT_CLUSTER = 1167,
     CREATE_UC_IDX = 1169,
     CREATE_U_IDX = 1170,
     CREATE_C_IDX = 1171,
     CREATE_IDX = 1172,
     SQLSICS = 1185,
     CREATE_SCHEMA = 1186,
     SQLSIRR = 1187,
     UPDATESTATS_T = 1188,
     SQLSICR = 1189,
     SQLSIDR = 1200,
     CREATE_TEMP_TABLE = 1201,
     WITH_CHECK_OPTION = 1209,
     WITH_GRANT_OPTION = 1210,
     SQLSLMNW = 1211,
     WHERE_CURRENT_OF = 1217,
     NOT_NULL_UNIQUE = 1225,
     SQLSLMW = 1232,
     ALL_PRIVILEGES = 1234,
     CREATE_SYNONYM = 1238,
     DROP_TABLE = 1239,
     INEXCLUSIVE = 1241,
     UPDATESTATS = 1246,
     CREATE_TABLE = 1272,
     DEFAULT_NULL = 1273,
     DEFAULT_TODAY = 1274,
     DEFAULT_USER = 1275,
     UNLOCK_TABLE = 1288,
     ROLLBACK_W = 1296,
     SQLSEON = 1298,
     SQLSEOFF = 1299,
     CREATE_VIEW = 1303,
     DELETE_FROM = 1304,
     EXTENT_SIZE = 1311,
     FOREIGN_KEY = 1312,
     INSERT_INTO = 1315,
     IS_NOT_NULL = 1317,
     NOT_MATCHES = 1320,
     PRIMARY_KEY = 1326,
     USE_SESSION = 1333,
     WITH_NO_LOG = 1334,
     INSHARE = 1337,
     BEGIN_WORK = 1343,
     DROP_INDEX = 1348,
     FOR_UPDATE_OF = 1354,
     FOR_UPDATE = 1355,
     LOCK_TABLE = 1359,
     NOT_EXISTS = 1361,
     REFERENCES = 1363,
     RENCOL = 1364,
     SMALLFLOAT = 1366,
     COMMIT_W = 1377,
     RENTAB = 1384,
     KW_CHAR = 1387,
     NCHAR = 1388,
     NVARCHAR = 1389,
     DELIMITER = 1391,
     DROP_VIEW = 1393,
     EXCLUSIVE = 1396,
     GREATER_THAN_EQ = 1400,
     INTO_TEMP = 1402,
     LOAD_FROM = 1406,
     UNLOAD_TO = 1417,
     VARIABLE_ATTRIBUTES = 1420,
     DATABASE = 1427,
     DATETIME = 1428,
     DISTINCT = 1430,
     FRACTION = 1437,
     GROUP_BY = 1439,
     INTERVAL = 1440,
     NOT_LIKE = 1442,
     NOT_ILIKE = 1443,
     NOT_NULL = 1444,
     RESOURCE = 1450,
     SMALLINT = 1451,
     IS_NULL = 1457,
     LESS_THAN_EQ = 1458,
     BETWEEN = 1460,
     CLOSE_BRACKET = 1463,
     CONNECT = 1466,
     KW_CURRENT = 1467,
     KW_DECIMAL = 1469,
     DEFAULT = 1471,
     INTEGER = 1479,
     MATCHES = 1482,
     VARCHAR = 1495,
     CLOSE_SQUARE = 1498,
     GREATER_THAN = 1499,
     KW_FALSE = 1500,
     NOT_IN = 1501,
     OPEN_BRACKET = 1503,
     KW_DELETE = 1511,
     KW_ESCAPE = 1514,
     EXISTS = 1515,
     EXTEND = 1516,
     HAVING = 1520,
     KW_INSERT = 1522,
     MINUTE = 1526,
     MODIFY = 1527,
     EQUAL = 1529,
     NOT_EQUAL = 1530,
     OPEN_SQUARE = 1532,
     PUBLIC = 1536,
     REVOKE = 1539,
     SECOND = 1543,
     IDLE_SECONDS = 1544,
     IDLE_MINUTES = 1545,
     IDLE_HOURS = 1546,
     KW_SELECT = 1547,
     SERIAL = 1548,
     UNIQUE = 1551,
     KW_UPDATE = 1553,
     VALUES = 1554,
     KW_NULL = 1558,
     KW_TRUE = 1559,
     ALTER = 1561,
     CHECK = 1567,
     COUNT = 1571,
     KW_FIRST = 1576,
     KW_FLOAT = 1577,
     GRANT = 1580,
     INDEX = 1583,
     LESS_THAN = 1586,
     MONEY = 1588,
     MONTH = 1589,
     MULTIPLY = 1591,
     ORDER = 1592,
     OUTER = 1593,
     UNION = 1603,
     WHERE = 1605,
     KW_BYTE = 1612,
     CASE = 1614,
     KW_DATE = 1616,
     DESC = 1617,
     DIVIDE = 1618,
     DROP = 1621,
     ELSE = 1622,
     FROM = 1626,
     HOUR = 1632,
     INTO = 1633,
     LIKE = 1636,
     REAL = 1645,
     SOME = 1650,
     KW_TEXT = 1654,
     THEN = 1655,
     USER = 1656,
     WHEN = 1658,
     YEAR = 1661,
     KW_DOW = 1662,
     XSET = 1664,
     ADD = 1665,
     ALL = 1666,
     KW_AND = 1667,
     ANY = 1668,
     ASC = 1669,
     AVG = 1670,
     COLON = 1671,
     KW_COMMA = 1672,
     DAY = 1673,
     DBA = 1674,
     FOR = 1678,
     XMAX = 1683,
     XMIN = 1684,
     MINUS = 1685,
     NOT = 1687,
     SUM = 1694,
     ATSIGN = 1697,
     PLUS = 1698,
     AS = 1703,
     BY = 1705,
     DOT = 1706,
     KW_IN = 1709,
     KW_ON = 1711,
     KW_OR = 1712,
     TO = 1713,
     BEFORE = 1751,
     END = 1754,
     TILDE = 1761,
     ILIKE = 1762,
     FILLFACTOR = 1765,
     KW_TODAY = 1777,
     KW_IDLE = 2117,
     CANCEL_INSERT = 2118,
     CANCEL_DELETE = 2119
   };
#endif
#define INT_VALUE 2121
#define NAMED 2122
#define NAMED_GEN 2123
#define CHAR_VALUE 2124
#define NOT_USED_1 2125
#define NOT_USED_2 2126
#define NOT_USED_3 2127
#define NOT_USED_4 2128
#define NOT_USED_5 2129
#define NOT_USED_6 2130
#define NOT_USED_7 2131
#define NOT_USED_8 2132
#define NUMBER_VALUE 2133
#define SEMICOLON 2134
#define QUESTION_MARK 2135
#define CLINE 2136
#define CH 2137
#define REPLACE_STRING 1012
#define STOP_REPLACE_STRING 1013
#define IGNORE_FUNCTION 1014
#define SET_BUFFERED_LOG 1017
#define SET_LOG 1018
#define MDY 1020
#define WEEKDAY 1021
#define MISC_INFX_SQL 1024
#define DATETIME_VALUE 1036
#define INTERVAL_VALUE 1037
#define RECOVER_TABLE 1038
#define ROLLFORWARD_DATABASE 1039
#define DROP_TRIGGER 1054
#define DROP_AUDIT_FOR 1055
#define CREATE_AUDIT_FOR 1056
#define EXECUTE_PROCEDURE 1060
#define ALTER_TABLE 1067
#define ALTER_INDEX 1068
#define NEXT_SIZE 1069
#define XSET_MULTIPLY_EQUAL_OPEN_BRACKET 1106
#define XSET_ident_DOT_MULTIPLY_EQUAL_OPEN_BRACKET 1107
#define XSET_ident_DOT_MULTIPLY_EQUAL 1108
#define XSET_MULTIPLY_EQUAL 1109
#define XSET_OPEN_BRACKET 1110
#define CREATE_DATABASE 1113
#define DROP_DATABASE 1114
#define ADD_CONSTRAINT 1116
#define DROP_CONSTRAINT 1117
#define DROP_SYNONYM 1118
#define CONSTRAINT 1119
#define KW_ARG_VAL 1125
#define DOUBLE_PRECISION 1126
#define COUNT_MULTIPLY 1127
#define MODIFY_NEXT_SIZE 1147
#define LOCK_MODE_PAGE 1148
#define LOCK_MODE_ROW 1149
#define UNITS_YEAR 1156
#define UNITS_MONTH 1157
#define UNITS_DAY 1158
#define UNITS_HOUR 1159
#define UNITS_MINUTE 1160
#define UNITS_SECOND 1161
#define TO_CLUSTER 1166
#define TO_NOT_CLUSTER 1167
#define CREATE_UC_IDX 1169
#define CREATE_U_IDX 1170
#define CREATE_C_IDX 1171
#define CREATE_IDX 1172
#define SQLSICS 1185
#define CREATE_SCHEMA 1186
#define SQLSIRR 1187
#define UPDATESTATS_T 1188
#define SQLSICR 1189
#define SQLSIDR 1200
#define CREATE_TEMP_TABLE 1201
#define WITH_CHECK_OPTION 1209
#define WITH_GRANT_OPTION 1210
#define SQLSLMNW 1211
#define WHERE_CURRENT_OF 1217
#define NOT_NULL_UNIQUE 1225
#define SQLSLMW 1232
#define ALL_PRIVILEGES 1234
#define CREATE_SYNONYM 1238
#define DROP_TABLE 1239
#define INEXCLUSIVE 1241
#define UPDATESTATS 1246
#define CREATE_TABLE 1272
#define DEFAULT_NULL 1273
#define DEFAULT_TODAY 1274
#define DEFAULT_USER 1275
#define UNLOCK_TABLE 1288
#define ROLLBACK_W 1296
#define SQLSEON 1298
#define SQLSEOFF 1299
#define CREATE_VIEW 1303
#define DELETE_FROM 1304
#define EXTENT_SIZE 1311
#define FOREIGN_KEY 1312
#define INSERT_INTO 1315
#define IS_NOT_NULL 1317
#define NOT_MATCHES 1320
#define PRIMARY_KEY 1326
#define USE_SESSION 1333
#define WITH_NO_LOG 1334
#define INSHARE 1337
#define BEGIN_WORK 1343
#define DROP_INDEX 1348
#define FOR_UPDATE_OF 1354
#define FOR_UPDATE 1355
#define LOCK_TABLE 1359
#define NOT_EXISTS 1361
#define REFERENCES 1363
#define RENCOL 1364
#define SMALLFLOAT 1366
#define COMMIT_W 1377
#define RENTAB 1384
#define KW_CHAR 1387
#define NCHAR 1388
#define NVARCHAR 1389
#define DELIMITER 1391
#define DROP_VIEW 1393
#define EXCLUSIVE 1396
#define GREATER_THAN_EQ 1400
#define INTO_TEMP 1402
#define LOAD_FROM 1406
#define UNLOAD_TO 1417
#define VARIABLE_ATTRIBUTES 1420
#define DATABASE 1427
#define DATETIME 1428
#define DISTINCT 1430
#define FRACTION 1437
#define GROUP_BY 1439
#define INTERVAL 1440
#define NOT_LIKE 1442
#define NOT_ILIKE 1443
#define NOT_NULL 1444
#define RESOURCE 1450
#define SMALLINT 1451
#define IS_NULL 1457
#define LESS_THAN_EQ 1458
#define BETWEEN 1460
#define CLOSE_BRACKET 1463
#define CONNECT 1466
#define KW_CURRENT 1467
#define KW_DECIMAL 1469
#define DEFAULT 1471
#define INTEGER 1479
#define MATCHES 1482
#define VARCHAR 1495
#define CLOSE_SQUARE 1498
#define GREATER_THAN 1499
#define KW_FALSE 1500
#define NOT_IN 1501
#define OPEN_BRACKET 1503
#define KW_DELETE 1511
#define KW_ESCAPE 1514
#define EXISTS 1515
#define EXTEND 1516
#define HAVING 1520
#define KW_INSERT 1522
#define MINUTE 1526
#define MODIFY 1527
#define EQUAL 1529
#define NOT_EQUAL 1530
#define OPEN_SQUARE 1532
#define PUBLIC 1536
#define REVOKE 1539
#define SECOND 1543
#define IDLE_SECONDS 1544
#define IDLE_MINUTES 1545
#define IDLE_HOURS 1546
#define KW_SELECT 1547
#define SERIAL 1548
#define UNIQUE 1551
#define KW_UPDATE 1553
#define VALUES 1554
#define KW_NULL 1558
#define KW_TRUE 1559
#define ALTER 1561
#define CHECK 1567
#define COUNT 1571
#define KW_FIRST 1576
#define KW_FLOAT 1577
#define GRANT 1580
#define INDEX 1583
#define LESS_THAN 1586
#define MONEY 1588
#define MONTH 1589
#define MULTIPLY 1591
#define ORDER 1592
#define OUTER 1593
#define UNION 1603
#define WHERE 1605
#define KW_BYTE 1612
#define CASE 1614
#define KW_DATE 1616
#define DESC 1617
#define DIVIDE 1618
#define DROP 1621
#define ELSE 1622
#define FROM 1626
#define HOUR 1632
#define INTO 1633
#define LIKE 1636
#define REAL 1645
#define SOME 1650
#define KW_TEXT 1654
#define THEN 1655
#define USER 1656
#define WHEN 1658
#define YEAR 1661
#define KW_DOW 1662
#define XSET 1664
#define ADD 1665
#define ALL 1666
#define KW_AND 1667
#define ANY 1668
#define ASC 1669
#define AVG 1670
#define COLON 1671
#define KW_COMMA 1672
#define DAY 1673
#define DBA 1674
#define FOR 1678
#define XMAX 1683
#define XMIN 1684
#define MINUS 1685
#define NOT 1687
#define SUM 1694
#define ATSIGN 1697
#define PLUS 1698
#define AS 1703
#define BY 1705
#define DOT 1706
#define KW_IN 1709
#define KW_ON 1711
#define KW_OR 1712
#define TO 1713
#define BEFORE 1751
#define END 1754
#define TILDE 1761
#define ILIKE 1762
#define FILLFACTOR 1765
#define KW_TODAY 1777
#define KW_IDLE 2117
#define CANCEL_INSERT 2118
#define CANCEL_DELETE 2119




#if ! defined (YYSTYPE) && ! defined (YYSTYPE_IS_DECLARED)
#line 173 "sql.yacc"
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
/* Line 1285 of yacc.c.  */
#line 544 "y.tab.h"
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE sqlparse_yylval;



