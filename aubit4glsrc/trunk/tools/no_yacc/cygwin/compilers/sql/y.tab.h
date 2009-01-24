
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
     INT_VALUE = 2197,
     NAMED = 2198,
     NAMED_GEN = 2199,
     CHAR_VALUE = 2200,
     NOT_USED_1 = 2201,
     NOT_USED_2 = 2202,
     NOT_USED_3 = 2203,
     NOT_USED_4 = 2204,
     NOT_USED_5 = 2205,
     NOT_USED_6 = 2206,
     NOT_USED_7 = 2207,
     NOT_USED_8 = 2208,
     NUMBER_VALUE = 2209,
     SEMICOLON = 2210,
     QUESTION_MARK = 2211,
     CLINE = 2212,
     CH = 2213,
     MARK_VAR = 2214,
     END_MARK_VAR = 2215,
     KW_DOC4GLCOMMENT = 1000,
     LEFT_JOIN = 1002,
     LINT_IGNORE = 1003,
     LINT_EXPECT = 1004,
     INNER_JOIN = 1005,
     WITH_CONVERSIONS = 1011,
     WITHOUT_CONVERSIONS = 1012,
     BARCODE = 1013,
     BARCODE_NO_TEXT = 1014,
     BARCODETYPE = 1015,
     BLUEBAR_COLOR_EQUAL = 1016,
     BLUEBAR_STYLE_EQUAL_RECTANGLE_COLOR_EQUAL = 1017,
     BLUEBAR_STYLE_EQUAL_RECTANGLE = 1018,
     BLUEBAR_STYLE_EQUAL_LINE_COLOR_EQUAL = 1019,
     BLUEBAR_STYLE_EQUAL_LINE = 1020,
     BLUEBAR = 1021,
     USING_BTREE = 1028,
     USING_RTREE = 1029,
     ASCOPY = 1046,
     SET_BUFFERED_LOG = 1054,
     SET_FILL_COLOR = 1055,
     SET_PARAMETER = 1056,
     SET_LOG = 1057,
     MDY = 1059,
     WEEKDAY = 1060,
     MODE_ANSI = 1063,
     START_DATABASE = 1064,
     WITH_LOG_IN = 1065,
     SET_CONSTRAINTS_ALL_IMMEDIATE = 1066,
     DATETIME_VALUE = 1079,
     INTERVAL_VALUE = 1080,
     RECOVER_TABLE = 1081,
     ROLLFORWARD_DATABASE = 1082,
     DROP_TRIGGER = 1098,
     DROP_AUDIT_FOR = 1099,
     CREATE_AUDIT_FOR = 1100,
     EXECUTE_PROCEDURE = 1104,
     ALTER_TABLE = 1111,
     ALTER_INDEX = 1112,
     NEXT_SIZE = 1113,
     XSET_MULTIPLY_EQUAL_OPEN_BRACKET = 1150,
     XSET_ident_DOT_MULTIPLY_EQUAL_OPEN_BRACKET = 1151,
     XSET_ident_DOT_MULTIPLY_EQUAL = 1152,
     XSET_MULTIPLY_EQUAL = 1153,
     XSET_OPEN_BRACKET = 1154,
     CREATE_DATABASE = 1157,
     DROP_DATABASE = 1158,
     ADD_CONSTRAINT = 1160,
     DROP_CONSTRAINT = 1161,
     DROP_SYNONYM = 1162,
     CONSTRAINT = 1163,
     LOCAL_REPORT = 1167,
     LOCAL_PDF_REPORT = 1168,
     DOUBLE_PRECISION = 1172,
     COUNT_MULTIPLY = 1173,
     MODIFY_NEXT_SIZE = 1193,
     LOCK_MODE_PAGE = 1194,
     LOCK_MODE_ROW = 1195,
     UNITS_YEAR = 1202,
     UNITS_MONTH = 1203,
     UNITS_DAY = 1204,
     UNITS_HOUR = 1205,
     UNITS_MINUTE = 1206,
     UNITS_SECOND = 1207,
     TO_CLUSTER = 1212,
     TO_NOT_CLUSTER = 1213,
     CREATE_UC_IDX = 1215,
     CREATE_U_IDX = 1216,
     CREATE_C_IDX = 1217,
     CREATE_IDX = 1218,
     CM = 1225,
     DOUBLE_COLON = 1228,
     SQLSICS = 1234,
     CREATE_SCHEMA = 1235,
     SQLSIRR = 1236,
     UPDATESTATS_T = 1237,
     SQLSICR = 1238,
     SQLSIDR = 1249,
     CREATE_TEMP_TABLE = 1250,
     WITH_CHECK_OPTION = 1258,
     WITH_GRANT_OPTION = 1259,
     SQLSLMNW = 1260,
     WHERE_CURRENT_OF = 1266,
     NOT_NULL_UNIQUE = 1274,
     SQLSLMW = 1281,
     ALL_PRIVILEGES = 1283,
     CREATE_SYNONYM = 1287,
     DROP_TABLE = 1288,
     INEXCLUSIVE = 1290,
     UPDATESTATS = 1295,
     CREATE_TABLE = 1321,
     DEFAULT_NULL = 1322,
     DEFAULT_TODAY = 1323,
     DEFAULT_USER = 1324,
     UNLOCK_TABLE = 1337,
     ROLLBACK_W = 1345,
     SQLSEON = 1347,
     SQLSEOFF = 1348,
     CREATE_VIEW = 1352,
     DELETE_FROM = 1353,
     EXTENT_SIZE = 1360,
     FOREIGN_KEY = 1361,
     INSERT_INTO = 1364,
     IS_NOT_NULL = 1366,
     NOT_MATCHES = 1369,
     PRIMARY_KEY = 1375,
     USE_SESSION = 1382,
     WITH_NO_LOG = 1383,
     INSHARE = 1386,
     BEGIN_WORK = 1392,
     DROP_INDEX = 1397,
     FOR_UPDATE_OF = 1403,
     FOR_UPDATE = 1404,
     REFERENCE = 1406,
     LOCK_TABLE = 1409,
     NOT_EXISTS = 1411,
     REFERENCES = 1413,
     RENCOL = 1414,
     SMALLFLOAT = 1416,
     COMMIT_W = 1427,
     RENTAB = 1434,
     KW_CHAR = 1437,
     NCHAR = 1438,
     NVARCHAR = 1439,
     DELIMITER = 1441,
     DROP_VIEW = 1443,
     EXCLUSIVE = 1446,
     GREATER_THAN_EQ = 1450,
     INTO_TEMP = 1452,
     LOAD_FROM = 1456,
     UNLOAD_TO = 1467,
     DATABASE = 1476,
     DATETIME = 1477,
     DISTINCT = 1479,
     FRACTION = 1486,
     GROUP_BY = 1488,
     INTERVAL = 1489,
     NOT_LIKE = 1491,
     NOT_ILIKE = 1492,
     NOT_NULL = 1493,
     RESOURCE = 1499,
     SMALLINT = 1500,
     IS_NULL = 1506,
     LESS_THAN_EQ = 1507,
     BETWEEN = 1509,
     CLOSE_BRACKET = 1512,
     CONNECT = 1515,
     KW_CURRENT = 1516,
     KW_DECIMAL = 1518,
     DEFAULT = 1520,
     INTEGER = 1528,
     SERIAL8 = 1530,
     MATCHES = 1533,
     VARCHAR = 1546,
     CLOSE_SQUARE = 1549,
     GREATER_THAN = 1550,
     KW_FALSE = 1551,
     NOT_IN = 1552,
     OPEN_BRACKET = 1554,
     KW_DELETE = 1562,
     KW_ESCAPE = 1565,
     EXISTS = 1566,
     EXTEND = 1567,
     HAVING = 1571,
     KW_INSERT = 1573,
     MINUTE = 1577,
     MODIFY = 1578,
     EQUAL = 1580,
     NOT_EQUAL = 1581,
     OPEN_SQUARE = 1583,
     PUBLIC = 1587,
     REVOKE = 1590,
     SECOND = 1594,
     KW_SELECT = 1598,
     SERIAL = 1599,
     UNIQUE = 1602,
     KW_UPDATE = 1604,
     VALUES = 1605,
     KW_NULL = 1608,
     KW_TRUE = 1609,
     ALTER = 1611,
     CHECK = 1617,
     COUNT = 1621,
     KW_FIRST = 1626,
     KW_FLOAT = 1627,
     GRANT = 1630,
     INDEX = 1633,
     LESS_THAN = 1636,
     MONEY = 1638,
     MONTH = 1639,
     KW_MULTIPLY = 1641,
     ORDER = 1642,
     OUTER = 1643,
     UNION = 1652,
     KW_USING_FILTER = 1653,
     WHERE = 1655,
     KW_BYTE = 1662,
     CASE = 1664,
     KW_DATE = 1666,
     DESC = 1667,
     KW_DIVIDE = 1668,
     DROP = 1671,
     ELSE = 1672,
     FROM = 1676,
     HOUR = 1682,
     INTO = 1683,
     LIKE = 1686,
     REAL = 1695,
     SOME = 1700,
     KW_TEXT = 1704,
     KW_THEN = 1705,
     USER = 1706,
     WHEN = 1708,
     YEAR = 1711,
     KW_DOW = 1712,
     XSET = 1714,
     ADD = 1715,
     ALL = 1716,
     KW_AND = 1717,
     ANY = 1718,
     ASC = 1719,
     AVG = 1720,
     COLON = 1721,
     KW_COMMA = 1722,
     DAY = 1723,
     DBA = 1724,
     KW_FOR = 1728,
     XMAX = 1733,
     XMIN = 1734,
     KW_MINUS = 1735,
     KW_MOD = 1736,
     KW_NOT = 1737,
     KW_ROW = 1741,
     KW_SUM = 1744,
     ATSIGN = 1747,
     KW_PLUS = 1748,
     KW_AS_USER = 1753,
     KW_AS = 1754,
     KW_BY = 1756,
     KW_DOT = 1757,
     KW_IN = 1760,
     KW_ON = 1762,
     KW_OR = 1763,
     KW_TO = 1764,
     BEFORE = 1802,
     END = 1806,
     TILDE = 1813,
     ILIKE = 1814,
     FILLFACTOR = 1817,
     KW_EXTENDS = 1820,
     TIME = 1822,
     KW_TODAY = 1829,
     KW_ROWID = 1830,
     CURSOR_NAME_FUNCTION = 2177,
     TIMESTAMP = 2178,
     MOVE_TO_TOP = 2179,
     LINETO_TOP = 2180,
     KW_HEIGHT = 2181,
     SET_STROKE_COLOR = 2182,
     SET_FONT_SIZE = 2183,
     SET_COLOR = 2184,
     MOVE_TO = 2185,
     FILL_STROKE = 2186,
     STROKE = 2187,
     LINE_TO = 2188,
     SET_FONT_NAME = 2189,
     BOOKMARK = 2190,
     KW_FILL = 2191,
     KW_WIDTH = 2192,
     ERRORHOOK = 2194,
     KW_CAST = 2195
   };
#endif
/* Tokens.  */
#define INT_VALUE 2197
#define NAMED 2198
#define NAMED_GEN 2199
#define CHAR_VALUE 2200
#define NOT_USED_1 2201
#define NOT_USED_2 2202
#define NOT_USED_3 2203
#define NOT_USED_4 2204
#define NOT_USED_5 2205
#define NOT_USED_6 2206
#define NOT_USED_7 2207
#define NOT_USED_8 2208
#define NUMBER_VALUE 2209
#define SEMICOLON 2210
#define QUESTION_MARK 2211
#define CLINE 2212
#define CH 2213
#define MARK_VAR 2214
#define END_MARK_VAR 2215
#define KW_DOC4GLCOMMENT 1000
#define LEFT_JOIN 1002
#define LINT_IGNORE 1003
#define LINT_EXPECT 1004
#define INNER_JOIN 1005
#define WITH_CONVERSIONS 1011
#define WITHOUT_CONVERSIONS 1012
#define BARCODE 1013
#define BARCODE_NO_TEXT 1014
#define BARCODETYPE 1015
#define BLUEBAR_COLOR_EQUAL 1016
#define BLUEBAR_STYLE_EQUAL_RECTANGLE_COLOR_EQUAL 1017
#define BLUEBAR_STYLE_EQUAL_RECTANGLE 1018
#define BLUEBAR_STYLE_EQUAL_LINE_COLOR_EQUAL 1019
#define BLUEBAR_STYLE_EQUAL_LINE 1020
#define BLUEBAR 1021
#define USING_BTREE 1028
#define USING_RTREE 1029
#define ASCOPY 1046
#define SET_BUFFERED_LOG 1054
#define SET_FILL_COLOR 1055
#define SET_PARAMETER 1056
#define SET_LOG 1057
#define MDY 1059
#define WEEKDAY 1060
#define MODE_ANSI 1063
#define START_DATABASE 1064
#define WITH_LOG_IN 1065
#define SET_CONSTRAINTS_ALL_IMMEDIATE 1066
#define DATETIME_VALUE 1079
#define INTERVAL_VALUE 1080
#define RECOVER_TABLE 1081
#define ROLLFORWARD_DATABASE 1082
#define DROP_TRIGGER 1098
#define DROP_AUDIT_FOR 1099
#define CREATE_AUDIT_FOR 1100
#define EXECUTE_PROCEDURE 1104
#define ALTER_TABLE 1111
#define ALTER_INDEX 1112
#define NEXT_SIZE 1113
#define XSET_MULTIPLY_EQUAL_OPEN_BRACKET 1150
#define XSET_ident_DOT_MULTIPLY_EQUAL_OPEN_BRACKET 1151
#define XSET_ident_DOT_MULTIPLY_EQUAL 1152
#define XSET_MULTIPLY_EQUAL 1153
#define XSET_OPEN_BRACKET 1154
#define CREATE_DATABASE 1157
#define DROP_DATABASE 1158
#define ADD_CONSTRAINT 1160
#define DROP_CONSTRAINT 1161
#define DROP_SYNONYM 1162
#define CONSTRAINT 1163
#define LOCAL_REPORT 1167
#define LOCAL_PDF_REPORT 1168
#define DOUBLE_PRECISION 1172
#define COUNT_MULTIPLY 1173
#define MODIFY_NEXT_SIZE 1193
#define LOCK_MODE_PAGE 1194
#define LOCK_MODE_ROW 1195
#define UNITS_YEAR 1202
#define UNITS_MONTH 1203
#define UNITS_DAY 1204
#define UNITS_HOUR 1205
#define UNITS_MINUTE 1206
#define UNITS_SECOND 1207
#define TO_CLUSTER 1212
#define TO_NOT_CLUSTER 1213
#define CREATE_UC_IDX 1215
#define CREATE_U_IDX 1216
#define CREATE_C_IDX 1217
#define CREATE_IDX 1218
#define CM 1225
#define DOUBLE_COLON 1228
#define SQLSICS 1234
#define CREATE_SCHEMA 1235
#define SQLSIRR 1236
#define UPDATESTATS_T 1237
#define SQLSICR 1238
#define SQLSIDR 1249
#define CREATE_TEMP_TABLE 1250
#define WITH_CHECK_OPTION 1258
#define WITH_GRANT_OPTION 1259
#define SQLSLMNW 1260
#define WHERE_CURRENT_OF 1266
#define NOT_NULL_UNIQUE 1274
#define SQLSLMW 1281
#define ALL_PRIVILEGES 1283
#define CREATE_SYNONYM 1287
#define DROP_TABLE 1288
#define INEXCLUSIVE 1290
#define UPDATESTATS 1295
#define CREATE_TABLE 1321
#define DEFAULT_NULL 1322
#define DEFAULT_TODAY 1323
#define DEFAULT_USER 1324
#define UNLOCK_TABLE 1337
#define ROLLBACK_W 1345
#define SQLSEON 1347
#define SQLSEOFF 1348
#define CREATE_VIEW 1352
#define DELETE_FROM 1353
#define EXTENT_SIZE 1360
#define FOREIGN_KEY 1361
#define INSERT_INTO 1364
#define IS_NOT_NULL 1366
#define NOT_MATCHES 1369
#define PRIMARY_KEY 1375
#define USE_SESSION 1382
#define WITH_NO_LOG 1383
#define INSHARE 1386
#define BEGIN_WORK 1392
#define DROP_INDEX 1397
#define FOR_UPDATE_OF 1403
#define FOR_UPDATE 1404
#define REFERENCE 1406
#define LOCK_TABLE 1409
#define NOT_EXISTS 1411
#define REFERENCES 1413
#define RENCOL 1414
#define SMALLFLOAT 1416
#define COMMIT_W 1427
#define RENTAB 1434
#define KW_CHAR 1437
#define NCHAR 1438
#define NVARCHAR 1439
#define DELIMITER 1441
#define DROP_VIEW 1443
#define EXCLUSIVE 1446
#define GREATER_THAN_EQ 1450
#define INTO_TEMP 1452
#define LOAD_FROM 1456
#define UNLOAD_TO 1467
#define DATABASE 1476
#define DATETIME 1477
#define DISTINCT 1479
#define FRACTION 1486
#define GROUP_BY 1488
#define INTERVAL 1489
#define NOT_LIKE 1491
#define NOT_ILIKE 1492
#define NOT_NULL 1493
#define RESOURCE 1499
#define SMALLINT 1500
#define IS_NULL 1506
#define LESS_THAN_EQ 1507
#define BETWEEN 1509
#define CLOSE_BRACKET 1512
#define CONNECT 1515
#define KW_CURRENT 1516
#define KW_DECIMAL 1518
#define DEFAULT 1520
#define INTEGER 1528
#define SERIAL8 1530
#define MATCHES 1533
#define VARCHAR 1546
#define CLOSE_SQUARE 1549
#define GREATER_THAN 1550
#define KW_FALSE 1551
#define NOT_IN 1552
#define OPEN_BRACKET 1554
#define KW_DELETE 1562
#define KW_ESCAPE 1565
#define EXISTS 1566
#define EXTEND 1567
#define HAVING 1571
#define KW_INSERT 1573
#define MINUTE 1577
#define MODIFY 1578
#define EQUAL 1580
#define NOT_EQUAL 1581
#define OPEN_SQUARE 1583
#define PUBLIC 1587
#define REVOKE 1590
#define SECOND 1594
#define KW_SELECT 1598
#define SERIAL 1599
#define UNIQUE 1602
#define KW_UPDATE 1604
#define VALUES 1605
#define KW_NULL 1608
#define KW_TRUE 1609
#define ALTER 1611
#define CHECK 1617
#define COUNT 1621
#define KW_FIRST 1626
#define KW_FLOAT 1627
#define GRANT 1630
#define INDEX 1633
#define LESS_THAN 1636
#define MONEY 1638
#define MONTH 1639
#define KW_MULTIPLY 1641
#define ORDER 1642
#define OUTER 1643
#define UNION 1652
#define KW_USING_FILTER 1653
#define WHERE 1655
#define KW_BYTE 1662
#define CASE 1664
#define KW_DATE 1666
#define DESC 1667
#define KW_DIVIDE 1668
#define DROP 1671
#define ELSE 1672
#define FROM 1676
#define HOUR 1682
#define INTO 1683
#define LIKE 1686
#define REAL 1695
#define SOME 1700
#define KW_TEXT 1704
#define KW_THEN 1705
#define USER 1706
#define WHEN 1708
#define YEAR 1711
#define KW_DOW 1712
#define XSET 1714
#define ADD 1715
#define ALL 1716
#define KW_AND 1717
#define ANY 1718
#define ASC 1719
#define AVG 1720
#define COLON 1721
#define KW_COMMA 1722
#define DAY 1723
#define DBA 1724
#define KW_FOR 1728
#define XMAX 1733
#define XMIN 1734
#define KW_MINUS 1735
#define KW_MOD 1736
#define KW_NOT 1737
#define KW_ROW 1741
#define KW_SUM 1744
#define ATSIGN 1747
#define KW_PLUS 1748
#define KW_AS_USER 1753
#define KW_AS 1754
#define KW_BY 1756
#define KW_DOT 1757
#define KW_IN 1760
#define KW_ON 1762
#define KW_OR 1763
#define KW_TO 1764
#define BEFORE 1802
#define END 1806
#define TILDE 1813
#define ILIKE 1814
#define FILLFACTOR 1817
#define KW_EXTENDS 1820
#define TIME 1822
#define KW_TODAY 1829
#define KW_ROWID 1830
#define CURSOR_NAME_FUNCTION 2177
#define TIMESTAMP 2178
#define MOVE_TO_TOP 2179
#define LINETO_TOP 2180
#define KW_HEIGHT 2181
#define SET_STROKE_COLOR 2182
#define SET_FONT_SIZE 2183
#define SET_COLOR 2184
#define MOVE_TO 2185
#define FILL_STROKE 2186
#define STROKE 2187
#define LINE_TO 2188
#define SET_FONT_NAME 2189
#define BOOKMARK 2190
#define KW_FILL 2191
#define KW_WIDTH 2192
#define ERRORHOOK 2194
#define KW_CAST 2195




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 1676 of yacc.c  */
#line 186 "sql.yacc"

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
#line 661 "y.tab.h"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE sqlparse_yylval;


