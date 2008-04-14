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
     INT_VALUE = 2156,
     NAMED = 2157,
     NAMED_GEN = 2158,
     CHAR_VALUE = 2159,
     NOT_USED_1 = 2160,
     NOT_USED_2 = 2161,
     NOT_USED_3 = 2162,
     NOT_USED_4 = 2163,
     NOT_USED_5 = 2164,
     NOT_USED_6 = 2165,
     NOT_USED_7 = 2166,
     NOT_USED_8 = 2167,
     NUMBER_VALUE = 2168,
     SEMICOLON = 2169,
     QUESTION_MARK = 2170,
     CLINE = 2171,
     CH = 2172,
     MARK_VAR = 2173,
     END_MARK_VAR = 2174,
     LEFT_JOIN = 1001,
     USING_BTREE = 1013,
     USING_RTREE = 1014,
     SET_BUFFERED_LOG = 1038,
     SET_LOG = 1039,
     MDY = 1041,
     WEEKDAY = 1042,
     MISC_INFX_SQL = 1045,
     DATETIME_VALUE = 1058,
     INTERVAL_VALUE = 1059,
     RECOVER_TABLE = 1060,
     ROLLFORWARD_DATABASE = 1061,
     DROP_TRIGGER = 1077,
     DROP_AUDIT_FOR = 1078,
     CREATE_AUDIT_FOR = 1079,
     EXECUTE_PROCEDURE = 1083,
     ALTER_TABLE = 1090,
     ALTER_INDEX = 1091,
     NEXT_SIZE = 1092,
     XSET_MULTIPLY_EQUAL_OPEN_BRACKET = 1129,
     XSET_ident_DOT_MULTIPLY_EQUAL_OPEN_BRACKET = 1130,
     XSET_ident_DOT_MULTIPLY_EQUAL = 1131,
     XSET_MULTIPLY_EQUAL = 1132,
     XSET_OPEN_BRACKET = 1133,
     CREATE_DATABASE = 1136,
     DROP_DATABASE = 1137,
     ADD_CONSTRAINT = 1139,
     DROP_CONSTRAINT = 1140,
     DROP_SYNONYM = 1141,
     CONSTRAINT = 1142,
     LOCAL_REPORT = 1146,
     LOCAL_PDF_REPORT = 1147,
     DOUBLE_PRECISION = 1151,
     COUNT_MULTIPLY = 1152,
     MODIFY_NEXT_SIZE = 1172,
     LOCK_MODE_PAGE = 1173,
     LOCK_MODE_ROW = 1174,
     UNITS_YEAR = 1181,
     UNITS_MONTH = 1182,
     UNITS_DAY = 1183,
     UNITS_HOUR = 1184,
     UNITS_MINUTE = 1185,
     UNITS_SECOND = 1186,
     TO_CLUSTER = 1191,
     TO_NOT_CLUSTER = 1192,
     CREATE_UC_IDX = 1194,
     CREATE_U_IDX = 1195,
     CREATE_C_IDX = 1196,
     CREATE_IDX = 1197,
     SQLSICS = 1212,
     CREATE_SCHEMA = 1213,
     SQLSIRR = 1214,
     UPDATESTATS_T = 1215,
     SQLSICR = 1216,
     SQLSIDR = 1227,
     CREATE_TEMP_TABLE = 1228,
     WITH_CHECK_OPTION = 1236,
     WITH_GRANT_OPTION = 1237,
     SQLSLMNW = 1238,
     WHERE_CURRENT_OF = 1244,
     NOT_NULL_UNIQUE = 1252,
     SQLSLMW = 1259,
     ALL_PRIVILEGES = 1261,
     CREATE_SYNONYM = 1265,
     DROP_TABLE = 1266,
     INEXCLUSIVE = 1268,
     UPDATESTATS = 1273,
     CREATE_TABLE = 1299,
     DEFAULT_NULL = 1300,
     DEFAULT_TODAY = 1301,
     DEFAULT_USER = 1302,
     UNLOCK_TABLE = 1315,
     ROLLBACK_W = 1323,
     SQLSEON = 1325,
     SQLSEOFF = 1326,
     CREATE_VIEW = 1330,
     DELETE_FROM = 1331,
     EXTENT_SIZE = 1338,
     FOREIGN_KEY = 1339,
     INSERT_INTO = 1342,
     IS_NOT_NULL = 1344,
     NOT_MATCHES = 1347,
     PRIMARY_KEY = 1353,
     USE_SESSION = 1360,
     WITH_NO_LOG = 1361,
     INSHARE = 1364,
     BEGIN_WORK = 1370,
     DROP_INDEX = 1375,
     FOR_UPDATE_OF = 1381,
     FOR_UPDATE = 1382,
     LOCK_TABLE = 1386,
     NOT_EXISTS = 1388,
     REFERENCES = 1390,
     RENCOL = 1391,
     SMALLFLOAT = 1393,
     COMMIT_W = 1404,
     RENTAB = 1411,
     KW_CHAR = 1414,
     NCHAR = 1415,
     NVARCHAR = 1416,
     DELIMITER = 1418,
     DROP_VIEW = 1420,
     EXCLUSIVE = 1423,
     GREATER_THAN_EQ = 1427,
     INTO_TEMP = 1429,
     LOAD_FROM = 1433,
     UNLOAD_TO = 1444,
     DATABASE = 1453,
     DATETIME = 1454,
     DISTINCT = 1456,
     FRACTION = 1463,
     GROUP_BY = 1465,
     INTERVAL = 1466,
     NOT_LIKE = 1468,
     NOT_ILIKE = 1469,
     NOT_NULL = 1470,
     RESOURCE = 1476,
     SMALLINT = 1477,
     IS_NULL = 1483,
     LESS_THAN_EQ = 1484,
     BETWEEN = 1486,
     CLOSE_BRACKET = 1489,
     CONNECT = 1492,
     KW_CURRENT = 1493,
     KW_DECIMAL = 1495,
     DEFAULT = 1497,
     INTEGER = 1505,
     SERIAL8 = 1507,
     MATCHES = 1510,
     VARCHAR = 1523,
     CLOSE_SQUARE = 1526,
     GREATER_THAN = 1527,
     KW_FALSE = 1528,
     NOT_IN = 1529,
     OPEN_BRACKET = 1531,
     KW_DELETE = 1539,
     KW_ESCAPE = 1542,
     EXISTS = 1543,
     EXTEND = 1544,
     HAVING = 1548,
     KW_INSERT = 1550,
     MINUTE = 1554,
     MODIFY = 1555,
     EQUAL = 1557,
     NOT_EQUAL = 1558,
     OPEN_SQUARE = 1560,
     PUBLIC = 1564,
     REVOKE = 1567,
     SECOND = 1571,
     KW_SELECT = 1575,
     SERIAL = 1576,
     UNIQUE = 1579,
     KW_UPDATE = 1581,
     VALUES = 1582,
     KW_NULL = 1586,
     KW_TRUE = 1587,
     ALTER = 1589,
     CHECK = 1595,
     COUNT = 1599,
     KW_FIRST = 1604,
     KW_FLOAT = 1605,
     GRANT = 1608,
     INDEX = 1611,
     LESS_THAN = 1614,
     MONEY = 1616,
     MONTH = 1617,
     KW_MULTIPLY = 1619,
     ORDER = 1620,
     OUTER = 1621,
     UNION = 1630,
     WHERE = 1632,
     KW_BYTE = 1639,
     CASE = 1641,
     KW_DATE = 1643,
     DESC = 1644,
     KW_DIVIDE = 1645,
     DROP = 1648,
     ELSE = 1649,
     FROM = 1653,
     HOUR = 1659,
     INTO = 1660,
     LIKE = 1663,
     REAL = 1672,
     SOME = 1677,
     KW_TEXT = 1681,
     KW_THEN = 1682,
     USER = 1683,
     WHEN = 1685,
     YEAR = 1688,
     KW_DOW = 1689,
     XSET = 1691,
     ADD = 1692,
     ALL = 1693,
     KW_AND = 1694,
     ANY = 1695,
     ASC = 1696,
     AVG = 1697,
     COLON = 1698,
     KW_COMMA = 1699,
     DAY = 1700,
     DBA = 1701,
     KW_FOR = 1705,
     XMAX = 1710,
     XMIN = 1711,
     KW_MINUS = 1712,
     KW_MOD = 1713,
     KW_NOT = 1714,
     KW_ROW = 1718,
     KW_SUM = 1721,
     ATSIGN = 1724,
     KW_PLUS = 1725,
     KW_AS_USER = 1730,
     KW_AS = 1731,
     KW_BY = 1733,
     KW_DOT = 1734,
     KW_IN = 1737,
     KW_ON = 1739,
     KW_OR = 1740,
     KW_TO = 1741,
     BEFORE = 1779,
     END = 1783,
     TILDE = 1790,
     ILIKE = 1791,
     FILLFACTOR = 1794,
     KW_EXTENDS = 1797,
     TIME = 1799,
     KW_TODAY = 1806,
     KW_ROWID = 1807,
     CURSOR_NAME_FUNCTION = 2154
   };
#endif
/* Tokens.  */
#define INT_VALUE 2156
#define NAMED 2157
#define NAMED_GEN 2158
#define CHAR_VALUE 2159
#define NOT_USED_1 2160
#define NOT_USED_2 2161
#define NOT_USED_3 2162
#define NOT_USED_4 2163
#define NOT_USED_5 2164
#define NOT_USED_6 2165
#define NOT_USED_7 2166
#define NOT_USED_8 2167
#define NUMBER_VALUE 2168
#define SEMICOLON 2169
#define QUESTION_MARK 2170
#define CLINE 2171
#define CH 2172
#define MARK_VAR 2173
#define END_MARK_VAR 2174
#define LEFT_JOIN 1001
#define USING_BTREE 1013
#define USING_RTREE 1014
#define SET_BUFFERED_LOG 1038
#define SET_LOG 1039
#define MDY 1041
#define WEEKDAY 1042
#define MISC_INFX_SQL 1045
#define DATETIME_VALUE 1058
#define INTERVAL_VALUE 1059
#define RECOVER_TABLE 1060
#define ROLLFORWARD_DATABASE 1061
#define DROP_TRIGGER 1077
#define DROP_AUDIT_FOR 1078
#define CREATE_AUDIT_FOR 1079
#define EXECUTE_PROCEDURE 1083
#define ALTER_TABLE 1090
#define ALTER_INDEX 1091
#define NEXT_SIZE 1092
#define XSET_MULTIPLY_EQUAL_OPEN_BRACKET 1129
#define XSET_ident_DOT_MULTIPLY_EQUAL_OPEN_BRACKET 1130
#define XSET_ident_DOT_MULTIPLY_EQUAL 1131
#define XSET_MULTIPLY_EQUAL 1132
#define XSET_OPEN_BRACKET 1133
#define CREATE_DATABASE 1136
#define DROP_DATABASE 1137
#define ADD_CONSTRAINT 1139
#define DROP_CONSTRAINT 1140
#define DROP_SYNONYM 1141
#define CONSTRAINT 1142
#define LOCAL_REPORT 1146
#define LOCAL_PDF_REPORT 1147
#define DOUBLE_PRECISION 1151
#define COUNT_MULTIPLY 1152
#define MODIFY_NEXT_SIZE 1172
#define LOCK_MODE_PAGE 1173
#define LOCK_MODE_ROW 1174
#define UNITS_YEAR 1181
#define UNITS_MONTH 1182
#define UNITS_DAY 1183
#define UNITS_HOUR 1184
#define UNITS_MINUTE 1185
#define UNITS_SECOND 1186
#define TO_CLUSTER 1191
#define TO_NOT_CLUSTER 1192
#define CREATE_UC_IDX 1194
#define CREATE_U_IDX 1195
#define CREATE_C_IDX 1196
#define CREATE_IDX 1197
#define SQLSICS 1212
#define CREATE_SCHEMA 1213
#define SQLSIRR 1214
#define UPDATESTATS_T 1215
#define SQLSICR 1216
#define SQLSIDR 1227
#define CREATE_TEMP_TABLE 1228
#define WITH_CHECK_OPTION 1236
#define WITH_GRANT_OPTION 1237
#define SQLSLMNW 1238
#define WHERE_CURRENT_OF 1244
#define NOT_NULL_UNIQUE 1252
#define SQLSLMW 1259
#define ALL_PRIVILEGES 1261
#define CREATE_SYNONYM 1265
#define DROP_TABLE 1266
#define INEXCLUSIVE 1268
#define UPDATESTATS 1273
#define CREATE_TABLE 1299
#define DEFAULT_NULL 1300
#define DEFAULT_TODAY 1301
#define DEFAULT_USER 1302
#define UNLOCK_TABLE 1315
#define ROLLBACK_W 1323
#define SQLSEON 1325
#define SQLSEOFF 1326
#define CREATE_VIEW 1330
#define DELETE_FROM 1331
#define EXTENT_SIZE 1338
#define FOREIGN_KEY 1339
#define INSERT_INTO 1342
#define IS_NOT_NULL 1344
#define NOT_MATCHES 1347
#define PRIMARY_KEY 1353
#define USE_SESSION 1360
#define WITH_NO_LOG 1361
#define INSHARE 1364
#define BEGIN_WORK 1370
#define DROP_INDEX 1375
#define FOR_UPDATE_OF 1381
#define FOR_UPDATE 1382
#define LOCK_TABLE 1386
#define NOT_EXISTS 1388
#define REFERENCES 1390
#define RENCOL 1391
#define SMALLFLOAT 1393
#define COMMIT_W 1404
#define RENTAB 1411
#define KW_CHAR 1414
#define NCHAR 1415
#define NVARCHAR 1416
#define DELIMITER 1418
#define DROP_VIEW 1420
#define EXCLUSIVE 1423
#define GREATER_THAN_EQ 1427
#define INTO_TEMP 1429
#define LOAD_FROM 1433
#define UNLOAD_TO 1444
#define DATABASE 1453
#define DATETIME 1454
#define DISTINCT 1456
#define FRACTION 1463
#define GROUP_BY 1465
#define INTERVAL 1466
#define NOT_LIKE 1468
#define NOT_ILIKE 1469
#define NOT_NULL 1470
#define RESOURCE 1476
#define SMALLINT 1477
#define IS_NULL 1483
#define LESS_THAN_EQ 1484
#define BETWEEN 1486
#define CLOSE_BRACKET 1489
#define CONNECT 1492
#define KW_CURRENT 1493
#define KW_DECIMAL 1495
#define DEFAULT 1497
#define INTEGER 1505
#define SERIAL8 1507
#define MATCHES 1510
#define VARCHAR 1523
#define CLOSE_SQUARE 1526
#define GREATER_THAN 1527
#define KW_FALSE 1528
#define NOT_IN 1529
#define OPEN_BRACKET 1531
#define KW_DELETE 1539
#define KW_ESCAPE 1542
#define EXISTS 1543
#define EXTEND 1544
#define HAVING 1548
#define KW_INSERT 1550
#define MINUTE 1554
#define MODIFY 1555
#define EQUAL 1557
#define NOT_EQUAL 1558
#define OPEN_SQUARE 1560
#define PUBLIC 1564
#define REVOKE 1567
#define SECOND 1571
#define KW_SELECT 1575
#define SERIAL 1576
#define UNIQUE 1579
#define KW_UPDATE 1581
#define VALUES 1582
#define KW_NULL 1586
#define KW_TRUE 1587
#define ALTER 1589
#define CHECK 1595
#define COUNT 1599
#define KW_FIRST 1604
#define KW_FLOAT 1605
#define GRANT 1608
#define INDEX 1611
#define LESS_THAN 1614
#define MONEY 1616
#define MONTH 1617
#define KW_MULTIPLY 1619
#define ORDER 1620
#define OUTER 1621
#define UNION 1630
#define WHERE 1632
#define KW_BYTE 1639
#define CASE 1641
#define KW_DATE 1643
#define DESC 1644
#define KW_DIVIDE 1645
#define DROP 1648
#define ELSE 1649
#define FROM 1653
#define HOUR 1659
#define INTO 1660
#define LIKE 1663
#define REAL 1672
#define SOME 1677
#define KW_TEXT 1681
#define KW_THEN 1682
#define USER 1683
#define WHEN 1685
#define YEAR 1688
#define KW_DOW 1689
#define XSET 1691
#define ADD 1692
#define ALL 1693
#define KW_AND 1694
#define ANY 1695
#define ASC 1696
#define AVG 1697
#define COLON 1698
#define KW_COMMA 1699
#define DAY 1700
#define DBA 1701
#define KW_FOR 1705
#define XMAX 1710
#define XMIN 1711
#define KW_MINUS 1712
#define KW_MOD 1713
#define KW_NOT 1714
#define KW_ROW 1718
#define KW_SUM 1721
#define ATSIGN 1724
#define KW_PLUS 1725
#define KW_AS_USER 1730
#define KW_AS 1731
#define KW_BY 1733
#define KW_DOT 1734
#define KW_IN 1737
#define KW_ON 1739
#define KW_OR 1740
#define KW_TO 1741
#define BEFORE 1779
#define END 1783
#define TILDE 1790
#define ILIKE 1791
#define FILLFACTOR 1794
#define KW_EXTENDS 1797
#define TIME 1799
#define KW_TODAY 1806
#define KW_ROWID 1807
#define CURSOR_NAME_FUNCTION 2154




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
#line 572 "y.tab.h"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE sqlparse_yylval;

