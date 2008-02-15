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
     INT_VALUE = 1808,
     NAMED = 1809,
     NAMED_GEN = 1810,
     CHAR_VALUE = 1811,
     NOT_USED_1 = 1812,
     NOT_USED_2 = 1813,
     NOT_USED_3 = 1814,
     NOT_USED_4 = 1815,
     NOT_USED_5 = 1816,
     NOT_USED_6 = 1817,
     NOT_USED_7 = 1818,
     NOT_USED_8 = 1819,
     NUMBER_VALUE = 1820,
     SEMICOLON = 1821,
     QUESTION_MARK = 1822,
     CLINE = 1823,
     CH = 1824,
     MARK_VAR = 1825,
     END_MARK_VAR = 1826,
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
     LOCAL_REPORT = 1145,
     LOCAL_PDF_REPORT = 1146,
     DOUBLE_PRECISION = 1150,
     COUNT_MULTIPLY = 1151,
     MODIFY_NEXT_SIZE = 1171,
     LOCK_MODE_PAGE = 1172,
     LOCK_MODE_ROW = 1173,
     UNITS_YEAR = 1180,
     UNITS_MONTH = 1181,
     UNITS_DAY = 1182,
     UNITS_HOUR = 1183,
     UNITS_MINUTE = 1184,
     UNITS_SECOND = 1185,
     TO_CLUSTER = 1190,
     TO_NOT_CLUSTER = 1191,
     CREATE_UC_IDX = 1193,
     CREATE_U_IDX = 1194,
     CREATE_C_IDX = 1195,
     CREATE_IDX = 1196,
     SQLSICS = 1211,
     CREATE_SCHEMA = 1212,
     SQLSIRR = 1213,
     UPDATESTATS_T = 1214,
     SQLSICR = 1215,
     SQLSIDR = 1226,
     CREATE_TEMP_TABLE = 1227,
     WITH_CHECK_OPTION = 1235,
     WITH_GRANT_OPTION = 1236,
     SQLSLMNW = 1237,
     WHERE_CURRENT_OF = 1243,
     NOT_NULL_UNIQUE = 1251,
     SQLSLMW = 1258,
     ALL_PRIVILEGES = 1260,
     CREATE_SYNONYM = 1264,
     DROP_TABLE = 1265,
     INEXCLUSIVE = 1267,
     UPDATESTATS = 1272,
     CREATE_TABLE = 1298,
     DEFAULT_NULL = 1299,
     DEFAULT_TODAY = 1300,
     DEFAULT_USER = 1301,
     UNLOCK_TABLE = 1314,
     ROLLBACK_W = 1322,
     SQLSEON = 1324,
     SQLSEOFF = 1325,
     CREATE_VIEW = 1329,
     DELETE_FROM = 1330,
     EXTENT_SIZE = 1337,
     FOREIGN_KEY = 1338,
     INSERT_INTO = 1341,
     IS_NOT_NULL = 1343,
     NOT_MATCHES = 1346,
     PRIMARY_KEY = 1352,
     USE_SESSION = 1359,
     WITH_NO_LOG = 1360,
     INSHARE = 1363,
     BEGIN_WORK = 1369,
     DROP_INDEX = 1374,
     FOR_UPDATE_OF = 1380,
     FOR_UPDATE = 1381,
     LOCK_TABLE = 1385,
     NOT_EXISTS = 1387,
     REFERENCES = 1389,
     RENCOL = 1390,
     SMALLFLOAT = 1392,
     COMMIT_W = 1403,
     RENTAB = 1410,
     KW_CHAR = 1413,
     NCHAR = 1414,
     NVARCHAR = 1415,
     DELIMITER = 1417,
     DROP_VIEW = 1419,
     EXCLUSIVE = 1422,
     GREATER_THAN_EQ = 1426,
     INTO_TEMP = 1428,
     LOAD_FROM = 1432,
     UNLOAD_TO = 1443,
     DATABASE = 1452,
     DATETIME = 1453,
     DISTINCT = 1455,
     FRACTION = 1462,
     GROUP_BY = 1464,
     INTERVAL = 1465,
     NOT_LIKE = 1467,
     NOT_ILIKE = 1468,
     NOT_NULL = 1469,
     RESOURCE = 1475,
     SMALLINT = 1476,
     IS_NULL = 1482,
     LESS_THAN_EQ = 1483,
     BETWEEN = 1485,
     CLOSE_BRACKET = 1488,
     CONNECT = 1491,
     KW_CURRENT = 1492,
     KW_DECIMAL = 1494,
     DEFAULT = 1496,
     INTEGER = 1504,
     SERIAL8 = 1506,
     MATCHES = 1509,
     VARCHAR = 1522,
     CLOSE_SQUARE = 1525,
     GREATER_THAN = 1526,
     KW_FALSE = 1527,
     NOT_IN = 1528,
     OPEN_BRACKET = 1530,
     KW_DELETE = 1538,
     KW_ESCAPE = 1541,
     EXISTS = 1542,
     EXTEND = 1543,
     HAVING = 1547,
     KW_INSERT = 1549,
     MINUTE = 1553,
     MODIFY = 1554,
     EQUAL = 1556,
     NOT_EQUAL = 1557,
     OPEN_SQUARE = 1559,
     PUBLIC = 1563,
     REVOKE = 1566,
     SECOND = 1570,
     KW_SELECT = 1574,
     SERIAL = 1575,
     UNIQUE = 1578,
     KW_UPDATE = 1580,
     VALUES = 1581,
     KW_NULL = 1585,
     KW_TRUE = 1586,
     ALTER = 1588,
     CHECK = 1594,
     COUNT = 1598,
     KW_FIRST = 1603,
     KW_FLOAT = 1604,
     GRANT = 1607,
     INDEX = 1610,
     LESS_THAN = 1613,
     MONEY = 1615,
     MONTH = 1616,
     KW_MULTIPLY = 1618,
     ORDER = 1619,
     OUTER = 1620,
     UNION = 1629,
     WHERE = 1631,
     KW_BYTE = 1638,
     CASE = 1640,
     KW_DATE = 1642,
     DESC = 1643,
     KW_DIVIDE = 1644,
     DROP = 1647,
     ELSE = 1648,
     FROM = 1652,
     HOUR = 1658,
     INTO = 1659,
     LIKE = 1662,
     REAL = 1671,
     SOME = 1676,
     KW_TEXT = 1680,
     KW_THEN = 1681,
     USER = 1682,
     WHEN = 1684,
     YEAR = 1687,
     KW_DOW = 1688,
     XSET = 1690,
     ADD = 1691,
     ALL = 1692,
     KW_AND = 1693,
     ANY = 1694,
     ASC = 1695,
     AVG = 1696,
     COLON = 1697,
     KW_COMMA = 1698,
     DAY = 1699,
     DBA = 1700,
     KW_FOR = 1704,
     XMAX = 1709,
     XMIN = 1710,
     KW_MINUS = 1711,
     KW_MOD = 1712,
     KW_NOT = 1713,
     KW_ROW = 1717,
     KW_SUM = 1720,
     ATSIGN = 1723,
     KW_PLUS = 1724,
     KW_AS_USER = 1729,
     KW_AS = 1730,
     KW_BY = 1732,
     KW_DOT = 1733,
     KW_IN = 1736,
     KW_ON = 1738,
     KW_OR = 1739,
     KW_TO = 1740,
     BEFORE = 1778,
     END = 1782,
     TILDE = 1789,
     ILIKE = 1790,
     FILLFACTOR = 1793,
     KW_EXTENDS = 1796,
     TIME = 1798,
     KW_TODAY = 1805,
     KW_ROWID = 1806
   };
#endif
/* Tokens.  */
#define INT_VALUE 1808
#define NAMED 1809
#define NAMED_GEN 1810
#define CHAR_VALUE 1811
#define NOT_USED_1 1812
#define NOT_USED_2 1813
#define NOT_USED_3 1814
#define NOT_USED_4 1815
#define NOT_USED_5 1816
#define NOT_USED_6 1817
#define NOT_USED_7 1818
#define NOT_USED_8 1819
#define NUMBER_VALUE 1820
#define SEMICOLON 1821
#define QUESTION_MARK 1822
#define CLINE 1823
#define CH 1824
#define MARK_VAR 1825
#define END_MARK_VAR 1826
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
#define LOCAL_REPORT 1145
#define LOCAL_PDF_REPORT 1146
#define DOUBLE_PRECISION 1150
#define COUNT_MULTIPLY 1151
#define MODIFY_NEXT_SIZE 1171
#define LOCK_MODE_PAGE 1172
#define LOCK_MODE_ROW 1173
#define UNITS_YEAR 1180
#define UNITS_MONTH 1181
#define UNITS_DAY 1182
#define UNITS_HOUR 1183
#define UNITS_MINUTE 1184
#define UNITS_SECOND 1185
#define TO_CLUSTER 1190
#define TO_NOT_CLUSTER 1191
#define CREATE_UC_IDX 1193
#define CREATE_U_IDX 1194
#define CREATE_C_IDX 1195
#define CREATE_IDX 1196
#define SQLSICS 1211
#define CREATE_SCHEMA 1212
#define SQLSIRR 1213
#define UPDATESTATS_T 1214
#define SQLSICR 1215
#define SQLSIDR 1226
#define CREATE_TEMP_TABLE 1227
#define WITH_CHECK_OPTION 1235
#define WITH_GRANT_OPTION 1236
#define SQLSLMNW 1237
#define WHERE_CURRENT_OF 1243
#define NOT_NULL_UNIQUE 1251
#define SQLSLMW 1258
#define ALL_PRIVILEGES 1260
#define CREATE_SYNONYM 1264
#define DROP_TABLE 1265
#define INEXCLUSIVE 1267
#define UPDATESTATS 1272
#define CREATE_TABLE 1298
#define DEFAULT_NULL 1299
#define DEFAULT_TODAY 1300
#define DEFAULT_USER 1301
#define UNLOCK_TABLE 1314
#define ROLLBACK_W 1322
#define SQLSEON 1324
#define SQLSEOFF 1325
#define CREATE_VIEW 1329
#define DELETE_FROM 1330
#define EXTENT_SIZE 1337
#define FOREIGN_KEY 1338
#define INSERT_INTO 1341
#define IS_NOT_NULL 1343
#define NOT_MATCHES 1346
#define PRIMARY_KEY 1352
#define USE_SESSION 1359
#define WITH_NO_LOG 1360
#define INSHARE 1363
#define BEGIN_WORK 1369
#define DROP_INDEX 1374
#define FOR_UPDATE_OF 1380
#define FOR_UPDATE 1381
#define LOCK_TABLE 1385
#define NOT_EXISTS 1387
#define REFERENCES 1389
#define RENCOL 1390
#define SMALLFLOAT 1392
#define COMMIT_W 1403
#define RENTAB 1410
#define KW_CHAR 1413
#define NCHAR 1414
#define NVARCHAR 1415
#define DELIMITER 1417
#define DROP_VIEW 1419
#define EXCLUSIVE 1422
#define GREATER_THAN_EQ 1426
#define INTO_TEMP 1428
#define LOAD_FROM 1432
#define UNLOAD_TO 1443
#define DATABASE 1452
#define DATETIME 1453
#define DISTINCT 1455
#define FRACTION 1462
#define GROUP_BY 1464
#define INTERVAL 1465
#define NOT_LIKE 1467
#define NOT_ILIKE 1468
#define NOT_NULL 1469
#define RESOURCE 1475
#define SMALLINT 1476
#define IS_NULL 1482
#define LESS_THAN_EQ 1483
#define BETWEEN 1485
#define CLOSE_BRACKET 1488
#define CONNECT 1491
#define KW_CURRENT 1492
#define KW_DECIMAL 1494
#define DEFAULT 1496
#define INTEGER 1504
#define SERIAL8 1506
#define MATCHES 1509
#define VARCHAR 1522
#define CLOSE_SQUARE 1525
#define GREATER_THAN 1526
#define KW_FALSE 1527
#define NOT_IN 1528
#define OPEN_BRACKET 1530
#define KW_DELETE 1538
#define KW_ESCAPE 1541
#define EXISTS 1542
#define EXTEND 1543
#define HAVING 1547
#define KW_INSERT 1549
#define MINUTE 1553
#define MODIFY 1554
#define EQUAL 1556
#define NOT_EQUAL 1557
#define OPEN_SQUARE 1559
#define PUBLIC 1563
#define REVOKE 1566
#define SECOND 1570
#define KW_SELECT 1574
#define SERIAL 1575
#define UNIQUE 1578
#define KW_UPDATE 1580
#define VALUES 1581
#define KW_NULL 1585
#define KW_TRUE 1586
#define ALTER 1588
#define CHECK 1594
#define COUNT 1598
#define KW_FIRST 1603
#define KW_FLOAT 1604
#define GRANT 1607
#define INDEX 1610
#define LESS_THAN 1613
#define MONEY 1615
#define MONTH 1616
#define KW_MULTIPLY 1618
#define ORDER 1619
#define OUTER 1620
#define UNION 1629
#define WHERE 1631
#define KW_BYTE 1638
#define CASE 1640
#define KW_DATE 1642
#define DESC 1643
#define KW_DIVIDE 1644
#define DROP 1647
#define ELSE 1648
#define FROM 1652
#define HOUR 1658
#define INTO 1659
#define LIKE 1662
#define REAL 1671
#define SOME 1676
#define KW_TEXT 1680
#define KW_THEN 1681
#define USER 1682
#define WHEN 1684
#define YEAR 1687
#define KW_DOW 1688
#define XSET 1690
#define ADD 1691
#define ALL 1692
#define KW_AND 1693
#define ANY 1694
#define ASC 1695
#define AVG 1696
#define COLON 1697
#define KW_COMMA 1698
#define DAY 1699
#define DBA 1700
#define KW_FOR 1704
#define XMAX 1709
#define XMIN 1710
#define KW_MINUS 1711
#define KW_MOD 1712
#define KW_NOT 1713
#define KW_ROW 1717
#define KW_SUM 1720
#define ATSIGN 1723
#define KW_PLUS 1724
#define KW_AS_USER 1729
#define KW_AS 1730
#define KW_BY 1732
#define KW_DOT 1733
#define KW_IN 1736
#define KW_ON 1738
#define KW_OR 1739
#define KW_TO 1740
#define BEFORE 1778
#define END 1782
#define TILDE 1789
#define ILIKE 1790
#define FILLFACTOR 1793
#define KW_EXTENDS 1796
#define TIME 1798
#define KW_TODAY 1805
#define KW_ROWID 1806




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 186 "sql.yacc"
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
	enum e_boolean e_boolean;
	 struct expr_str_list *ptr_list;
	        struct struct_update_cmd *update_cmd;
        struct struct_insert_cmd *insert_cmd;
        struct struct_delete_cmd *delete_cmd;
        struct s_update_pair *upd_pair;
        struct expr_str *ptr;
        struct str_list *str_list;


}
/* Line 1489 of yacc.c.  */
#line 568 "y.tab.h"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE sqlparse_yylval;

