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
     INT_VALUE = 2184,
     NAMED = 2185,
     NAMED_GEN = 2186,
     CHAR_VALUE = 2187,
     NOT_USED_1 = 2188,
     NOT_USED_2 = 2189,
     NOT_USED_3 = 2190,
     NOT_USED_4 = 2191,
     NOT_USED_5 = 2192,
     NOT_USED_6 = 2193,
     NOT_USED_7 = 2194,
     NOT_USED_8 = 2195,
     NUMBER_VALUE = 2196,
     SEMICOLON = 2197,
     QUESTION_MARK = 2198,
     CLINE = 2199,
     CH = 2200,
     MARK_VAR = 2201,
     END_MARK_VAR = 2202,
     LEFT_JOIN = 1001,
     WITH_CONVERSIONS = 1007,
     WITHOUT_CONVERSIONS = 1008,
     BARCODE = 1009,
     BARCODE_NO_TEXT = 1010,
     BARCODETYPE = 1011,
     USING_BTREE = 1018,
     USING_RTREE = 1019,
     ASCOPY = 1036,
     SET_BUFFERED_LOG = 1044,
     SET_LOG = 1045,
     MDY = 1047,
     WEEKDAY = 1048,
     MODE_ANSI = 1051,
     START_DATABASE = 1052,
     WITH_LOG_IN = 1053,
     SET_CONSTRAINTS_ALL_IMMEDIATE = 1054,
     DATETIME_VALUE = 1067,
     INTERVAL_VALUE = 1068,
     RECOVER_TABLE = 1069,
     ROLLFORWARD_DATABASE = 1070,
     DROP_TRIGGER = 1086,
     DROP_AUDIT_FOR = 1087,
     CREATE_AUDIT_FOR = 1088,
     EXECUTE_PROCEDURE = 1092,
     ALTER_TABLE = 1099,
     ALTER_INDEX = 1100,
     NEXT_SIZE = 1101,
     XSET_MULTIPLY_EQUAL_OPEN_BRACKET = 1138,
     XSET_ident_DOT_MULTIPLY_EQUAL_OPEN_BRACKET = 1139,
     XSET_ident_DOT_MULTIPLY_EQUAL = 1140,
     XSET_MULTIPLY_EQUAL = 1141,
     XSET_OPEN_BRACKET = 1142,
     CREATE_DATABASE = 1145,
     DROP_DATABASE = 1146,
     ADD_CONSTRAINT = 1148,
     DROP_CONSTRAINT = 1149,
     DROP_SYNONYM = 1150,
     CONSTRAINT = 1151,
     LOCAL_REPORT = 1155,
     LOCAL_PDF_REPORT = 1156,
     DOUBLE_PRECISION = 1160,
     COUNT_MULTIPLY = 1161,
     MODIFY_NEXT_SIZE = 1181,
     LOCK_MODE_PAGE = 1182,
     LOCK_MODE_ROW = 1183,
     UNITS_YEAR = 1190,
     UNITS_MONTH = 1191,
     UNITS_DAY = 1192,
     UNITS_HOUR = 1193,
     UNITS_MINUTE = 1194,
     UNITS_SECOND = 1195,
     TO_CLUSTER = 1200,
     TO_NOT_CLUSTER = 1201,
     CREATE_UC_IDX = 1203,
     CREATE_U_IDX = 1204,
     CREATE_C_IDX = 1205,
     CREATE_IDX = 1206,
     CM = 1213,
     DOUBLE_COLON = 1216,
     SQLSICS = 1222,
     CREATE_SCHEMA = 1223,
     SQLSIRR = 1224,
     UPDATESTATS_T = 1225,
     SQLSICR = 1226,
     SQLSIDR = 1237,
     CREATE_TEMP_TABLE = 1238,
     WITH_CHECK_OPTION = 1246,
     WITH_GRANT_OPTION = 1247,
     SQLSLMNW = 1248,
     WHERE_CURRENT_OF = 1254,
     NOT_NULL_UNIQUE = 1262,
     SQLSLMW = 1269,
     ALL_PRIVILEGES = 1271,
     CREATE_SYNONYM = 1275,
     DROP_TABLE = 1276,
     INEXCLUSIVE = 1278,
     UPDATESTATS = 1283,
     CREATE_TABLE = 1309,
     DEFAULT_NULL = 1310,
     DEFAULT_TODAY = 1311,
     DEFAULT_USER = 1312,
     UNLOCK_TABLE = 1325,
     ROLLBACK_W = 1333,
     SQLSEON = 1335,
     SQLSEOFF = 1336,
     CREATE_VIEW = 1340,
     DELETE_FROM = 1341,
     EXTENT_SIZE = 1348,
     FOREIGN_KEY = 1349,
     INSERT_INTO = 1352,
     IS_NOT_NULL = 1354,
     NOT_MATCHES = 1357,
     PRIMARY_KEY = 1363,
     USE_SESSION = 1370,
     WITH_NO_LOG = 1371,
     INSHARE = 1374,
     BEGIN_WORK = 1380,
     DROP_INDEX = 1385,
     FOR_UPDATE_OF = 1391,
     FOR_UPDATE = 1392,
     REFERENCE = 1394,
     LOCK_TABLE = 1397,
     NOT_EXISTS = 1399,
     REFERENCES = 1401,
     RENCOL = 1402,
     SMALLFLOAT = 1404,
     COMMIT_W = 1415,
     RENTAB = 1422,
     KW_CHAR = 1425,
     NCHAR = 1426,
     NVARCHAR = 1427,
     DELIMITER = 1429,
     DROP_VIEW = 1431,
     EXCLUSIVE = 1434,
     GREATER_THAN_EQ = 1438,
     INTO_TEMP = 1440,
     LOAD_FROM = 1444,
     UNLOAD_TO = 1455,
     DATABASE = 1464,
     DATETIME = 1465,
     DISTINCT = 1467,
     FRACTION = 1474,
     GROUP_BY = 1476,
     INTERVAL = 1477,
     NOT_LIKE = 1479,
     NOT_ILIKE = 1480,
     NOT_NULL = 1481,
     RESOURCE = 1487,
     SMALLINT = 1488,
     IS_NULL = 1494,
     LESS_THAN_EQ = 1495,
     BETWEEN = 1497,
     CLOSE_BRACKET = 1500,
     CONNECT = 1503,
     KW_CURRENT = 1504,
     KW_DECIMAL = 1506,
     DEFAULT = 1508,
     INTEGER = 1516,
     SERIAL8 = 1518,
     MATCHES = 1521,
     VARCHAR = 1534,
     CLOSE_SQUARE = 1537,
     GREATER_THAN = 1538,
     KW_FALSE = 1539,
     NOT_IN = 1540,
     OPEN_BRACKET = 1542,
     KW_DELETE = 1550,
     KW_ESCAPE = 1553,
     EXISTS = 1554,
     EXTEND = 1555,
     HAVING = 1559,
     KW_INSERT = 1561,
     MINUTE = 1565,
     MODIFY = 1566,
     EQUAL = 1568,
     NOT_EQUAL = 1569,
     OPEN_SQUARE = 1571,
     PUBLIC = 1575,
     REVOKE = 1578,
     SECOND = 1582,
     KW_SELECT = 1586,
     SERIAL = 1587,
     UNIQUE = 1590,
     KW_UPDATE = 1592,
     VALUES = 1593,
     KW_NULL = 1597,
     KW_TRUE = 1598,
     ALTER = 1600,
     CHECK = 1606,
     COUNT = 1610,
     KW_FIRST = 1615,
     KW_FLOAT = 1616,
     GRANT = 1619,
     INDEX = 1622,
     LESS_THAN = 1625,
     MONEY = 1627,
     MONTH = 1628,
     KW_MULTIPLY = 1630,
     ORDER = 1631,
     OUTER = 1632,
     UNION = 1641,
     WHERE = 1643,
     KW_BYTE = 1650,
     CASE = 1652,
     KW_DATE = 1654,
     DESC = 1655,
     KW_DIVIDE = 1656,
     DROP = 1659,
     ELSE = 1660,
     FROM = 1664,
     HOUR = 1670,
     INTO = 1671,
     LIKE = 1674,
     REAL = 1683,
     SOME = 1688,
     KW_TEXT = 1692,
     KW_THEN = 1693,
     USER = 1694,
     WHEN = 1696,
     YEAR = 1699,
     KW_DOW = 1700,
     XSET = 1702,
     ADD = 1703,
     ALL = 1704,
     KW_AND = 1705,
     ANY = 1706,
     ASC = 1707,
     AVG = 1708,
     COLON = 1709,
     KW_COMMA = 1710,
     DAY = 1711,
     DBA = 1712,
     KW_FOR = 1716,
     XMAX = 1721,
     XMIN = 1722,
     KW_MINUS = 1723,
     KW_MOD = 1724,
     KW_NOT = 1725,
     KW_ROW = 1729,
     KW_SUM = 1732,
     ATSIGN = 1735,
     KW_PLUS = 1736,
     KW_AS_USER = 1741,
     KW_AS = 1742,
     KW_BY = 1744,
     KW_DOT = 1745,
     KW_IN = 1748,
     KW_ON = 1750,
     KW_OR = 1751,
     KW_TO = 1752,
     BEFORE = 1790,
     END = 1794,
     TILDE = 1801,
     ILIKE = 1802,
     FILLFACTOR = 1805,
     KW_EXTENDS = 1808,
     TIME = 1810,
     KW_TODAY = 1817,
     KW_ROWID = 1818,
     CURSOR_NAME_FUNCTION = 2165,
     TIMESTAMP = 2166,
     MOVE_TO_TOP = 2167,
     LINETO_TOP = 2168,
     KW_HEIGHT = 2169,
     SET_STROKE_COLOR = 2170,
     SET_FONT_SIZE = 2171,
     SET_COLOR = 2172,
     MOVE_TO = 2173,
     FILL_STROKE = 2174,
     STROKE = 2175,
     LINE_TO = 2176,
     SET_FONT_NAME = 2177,
     BOOKMARK = 2178,
     KW_FILL = 2179,
     KW_WIDTH = 2180,
     SET_FILL_COLOR = 2181,
     SET_PARAMETER = 2182
   };
#endif
/* Tokens.  */
#define INT_VALUE 2184
#define NAMED 2185
#define NAMED_GEN 2186
#define CHAR_VALUE 2187
#define NOT_USED_1 2188
#define NOT_USED_2 2189
#define NOT_USED_3 2190
#define NOT_USED_4 2191
#define NOT_USED_5 2192
#define NOT_USED_6 2193
#define NOT_USED_7 2194
#define NOT_USED_8 2195
#define NUMBER_VALUE 2196
#define SEMICOLON 2197
#define QUESTION_MARK 2198
#define CLINE 2199
#define CH 2200
#define MARK_VAR 2201
#define END_MARK_VAR 2202
#define LEFT_JOIN 1001
#define WITH_CONVERSIONS 1007
#define WITHOUT_CONVERSIONS 1008
#define BARCODE 1009
#define BARCODE_NO_TEXT 1010
#define BARCODETYPE 1011
#define USING_BTREE 1018
#define USING_RTREE 1019
#define ASCOPY 1036
#define SET_BUFFERED_LOG 1044
#define SET_LOG 1045
#define MDY 1047
#define WEEKDAY 1048
#define MODE_ANSI 1051
#define START_DATABASE 1052
#define WITH_LOG_IN 1053
#define SET_CONSTRAINTS_ALL_IMMEDIATE 1054
#define DATETIME_VALUE 1067
#define INTERVAL_VALUE 1068
#define RECOVER_TABLE 1069
#define ROLLFORWARD_DATABASE 1070
#define DROP_TRIGGER 1086
#define DROP_AUDIT_FOR 1087
#define CREATE_AUDIT_FOR 1088
#define EXECUTE_PROCEDURE 1092
#define ALTER_TABLE 1099
#define ALTER_INDEX 1100
#define NEXT_SIZE 1101
#define XSET_MULTIPLY_EQUAL_OPEN_BRACKET 1138
#define XSET_ident_DOT_MULTIPLY_EQUAL_OPEN_BRACKET 1139
#define XSET_ident_DOT_MULTIPLY_EQUAL 1140
#define XSET_MULTIPLY_EQUAL 1141
#define XSET_OPEN_BRACKET 1142
#define CREATE_DATABASE 1145
#define DROP_DATABASE 1146
#define ADD_CONSTRAINT 1148
#define DROP_CONSTRAINT 1149
#define DROP_SYNONYM 1150
#define CONSTRAINT 1151
#define LOCAL_REPORT 1155
#define LOCAL_PDF_REPORT 1156
#define DOUBLE_PRECISION 1160
#define COUNT_MULTIPLY 1161
#define MODIFY_NEXT_SIZE 1181
#define LOCK_MODE_PAGE 1182
#define LOCK_MODE_ROW 1183
#define UNITS_YEAR 1190
#define UNITS_MONTH 1191
#define UNITS_DAY 1192
#define UNITS_HOUR 1193
#define UNITS_MINUTE 1194
#define UNITS_SECOND 1195
#define TO_CLUSTER 1200
#define TO_NOT_CLUSTER 1201
#define CREATE_UC_IDX 1203
#define CREATE_U_IDX 1204
#define CREATE_C_IDX 1205
#define CREATE_IDX 1206
#define CM 1213
#define DOUBLE_COLON 1216
#define SQLSICS 1222
#define CREATE_SCHEMA 1223
#define SQLSIRR 1224
#define UPDATESTATS_T 1225
#define SQLSICR 1226
#define SQLSIDR 1237
#define CREATE_TEMP_TABLE 1238
#define WITH_CHECK_OPTION 1246
#define WITH_GRANT_OPTION 1247
#define SQLSLMNW 1248
#define WHERE_CURRENT_OF 1254
#define NOT_NULL_UNIQUE 1262
#define SQLSLMW 1269
#define ALL_PRIVILEGES 1271
#define CREATE_SYNONYM 1275
#define DROP_TABLE 1276
#define INEXCLUSIVE 1278
#define UPDATESTATS 1283
#define CREATE_TABLE 1309
#define DEFAULT_NULL 1310
#define DEFAULT_TODAY 1311
#define DEFAULT_USER 1312
#define UNLOCK_TABLE 1325
#define ROLLBACK_W 1333
#define SQLSEON 1335
#define SQLSEOFF 1336
#define CREATE_VIEW 1340
#define DELETE_FROM 1341
#define EXTENT_SIZE 1348
#define FOREIGN_KEY 1349
#define INSERT_INTO 1352
#define IS_NOT_NULL 1354
#define NOT_MATCHES 1357
#define PRIMARY_KEY 1363
#define USE_SESSION 1370
#define WITH_NO_LOG 1371
#define INSHARE 1374
#define BEGIN_WORK 1380
#define DROP_INDEX 1385
#define FOR_UPDATE_OF 1391
#define FOR_UPDATE 1392
#define REFERENCE 1394
#define LOCK_TABLE 1397
#define NOT_EXISTS 1399
#define REFERENCES 1401
#define RENCOL 1402
#define SMALLFLOAT 1404
#define COMMIT_W 1415
#define RENTAB 1422
#define KW_CHAR 1425
#define NCHAR 1426
#define NVARCHAR 1427
#define DELIMITER 1429
#define DROP_VIEW 1431
#define EXCLUSIVE 1434
#define GREATER_THAN_EQ 1438
#define INTO_TEMP 1440
#define LOAD_FROM 1444
#define UNLOAD_TO 1455
#define DATABASE 1464
#define DATETIME 1465
#define DISTINCT 1467
#define FRACTION 1474
#define GROUP_BY 1476
#define INTERVAL 1477
#define NOT_LIKE 1479
#define NOT_ILIKE 1480
#define NOT_NULL 1481
#define RESOURCE 1487
#define SMALLINT 1488
#define IS_NULL 1494
#define LESS_THAN_EQ 1495
#define BETWEEN 1497
#define CLOSE_BRACKET 1500
#define CONNECT 1503
#define KW_CURRENT 1504
#define KW_DECIMAL 1506
#define DEFAULT 1508
#define INTEGER 1516
#define SERIAL8 1518
#define MATCHES 1521
#define VARCHAR 1534
#define CLOSE_SQUARE 1537
#define GREATER_THAN 1538
#define KW_FALSE 1539
#define NOT_IN 1540
#define OPEN_BRACKET 1542
#define KW_DELETE 1550
#define KW_ESCAPE 1553
#define EXISTS 1554
#define EXTEND 1555
#define HAVING 1559
#define KW_INSERT 1561
#define MINUTE 1565
#define MODIFY 1566
#define EQUAL 1568
#define NOT_EQUAL 1569
#define OPEN_SQUARE 1571
#define PUBLIC 1575
#define REVOKE 1578
#define SECOND 1582
#define KW_SELECT 1586
#define SERIAL 1587
#define UNIQUE 1590
#define KW_UPDATE 1592
#define VALUES 1593
#define KW_NULL 1597
#define KW_TRUE 1598
#define ALTER 1600
#define CHECK 1606
#define COUNT 1610
#define KW_FIRST 1615
#define KW_FLOAT 1616
#define GRANT 1619
#define INDEX 1622
#define LESS_THAN 1625
#define MONEY 1627
#define MONTH 1628
#define KW_MULTIPLY 1630
#define ORDER 1631
#define OUTER 1632
#define UNION 1641
#define WHERE 1643
#define KW_BYTE 1650
#define CASE 1652
#define KW_DATE 1654
#define DESC 1655
#define KW_DIVIDE 1656
#define DROP 1659
#define ELSE 1660
#define FROM 1664
#define HOUR 1670
#define INTO 1671
#define LIKE 1674
#define REAL 1683
#define SOME 1688
#define KW_TEXT 1692
#define KW_THEN 1693
#define USER 1694
#define WHEN 1696
#define YEAR 1699
#define KW_DOW 1700
#define XSET 1702
#define ADD 1703
#define ALL 1704
#define KW_AND 1705
#define ANY 1706
#define ASC 1707
#define AVG 1708
#define COLON 1709
#define KW_COMMA 1710
#define DAY 1711
#define DBA 1712
#define KW_FOR 1716
#define XMAX 1721
#define XMIN 1722
#define KW_MINUS 1723
#define KW_MOD 1724
#define KW_NOT 1725
#define KW_ROW 1729
#define KW_SUM 1732
#define ATSIGN 1735
#define KW_PLUS 1736
#define KW_AS_USER 1741
#define KW_AS 1742
#define KW_BY 1744
#define KW_DOT 1745
#define KW_IN 1748
#define KW_ON 1750
#define KW_OR 1751
#define KW_TO 1752
#define BEFORE 1790
#define END 1794
#define TILDE 1801
#define ILIKE 1802
#define FILLFACTOR 1805
#define KW_EXTENDS 1808
#define TIME 1810
#define KW_TODAY 1817
#define KW_ROWID 1818
#define CURSOR_NAME_FUNCTION 2165
#define TIMESTAMP 2166
#define MOVE_TO_TOP 2167
#define LINETO_TOP 2168
#define KW_HEIGHT 2169
#define SET_STROKE_COLOR 2170
#define SET_FONT_SIZE 2171
#define SET_COLOR 2172
#define MOVE_TO 2173
#define FILL_STROKE 2174
#define STROKE 2175
#define LINE_TO 2176
#define SET_FONT_NAME 2177
#define BOOKMARK 2178
#define KW_FILL 2179
#define KW_WIDTH 2180
#define SET_FILL_COLOR 2181
#define SET_PARAMETER 2182




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
#line 630 "y.tab.h"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE sqlparse_yylval;

