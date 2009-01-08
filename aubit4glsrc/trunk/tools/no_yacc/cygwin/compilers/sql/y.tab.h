
/* A Bison parser, made by GNU Bison 2.4.  */

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
     INT_VALUE = 2196,
     NAMED = 2197,
     NAMED_GEN = 2198,
     CHAR_VALUE = 2199,
     NOT_USED_1 = 2200,
     NOT_USED_2 = 2201,
     NOT_USED_3 = 2202,
     NOT_USED_4 = 2203,
     NOT_USED_5 = 2204,
     NOT_USED_6 = 2205,
     NOT_USED_7 = 2206,
     NOT_USED_8 = 2207,
     NUMBER_VALUE = 2208,
     SEMICOLON = 2209,
     QUESTION_MARK = 2210,
     CLINE = 2211,
     CH = 2212,
     MARK_VAR = 2213,
     END_MARK_VAR = 2214,
     LEFT_JOIN = 1001,
     LINT_IGNORE = 1002,
     LINT_EXPECT = 1003,
     INNER_JOIN = 1004,
     WITH_CONVERSIONS = 1010,
     WITHOUT_CONVERSIONS = 1011,
     BARCODE = 1012,
     BARCODE_NO_TEXT = 1013,
     BARCODETYPE = 1014,
     BLUEBAR_COLOR_EQUAL = 1015,
     BLUEBAR_STYLE_EQUAL_RECTANGLE_COLOR_EQUAL = 1016,
     BLUEBAR_STYLE_EQUAL_RECTANGLE = 1017,
     BLUEBAR_STYLE_EQUAL_LINE_COLOR_EQUAL = 1018,
     BLUEBAR_STYLE_EQUAL_LINE = 1019,
     BLUEBAR = 1020,
     USING_BTREE = 1027,
     USING_RTREE = 1028,
     ASCOPY = 1045,
     SET_BUFFERED_LOG = 1053,
     SET_FILL_COLOR = 1054,
     SET_PARAMETER = 1055,
     SET_LOG = 1056,
     MDY = 1058,
     WEEKDAY = 1059,
     MODE_ANSI = 1062,
     START_DATABASE = 1063,
     WITH_LOG_IN = 1064,
     SET_CONSTRAINTS_ALL_IMMEDIATE = 1065,
     DATETIME_VALUE = 1078,
     INTERVAL_VALUE = 1079,
     RECOVER_TABLE = 1080,
     ROLLFORWARD_DATABASE = 1081,
     DROP_TRIGGER = 1097,
     DROP_AUDIT_FOR = 1098,
     CREATE_AUDIT_FOR = 1099,
     EXECUTE_PROCEDURE = 1103,
     ALTER_TABLE = 1110,
     ALTER_INDEX = 1111,
     NEXT_SIZE = 1112,
     XSET_MULTIPLY_EQUAL_OPEN_BRACKET = 1149,
     XSET_ident_DOT_MULTIPLY_EQUAL_OPEN_BRACKET = 1150,
     XSET_ident_DOT_MULTIPLY_EQUAL = 1151,
     XSET_MULTIPLY_EQUAL = 1152,
     XSET_OPEN_BRACKET = 1153,
     CREATE_DATABASE = 1156,
     DROP_DATABASE = 1157,
     ADD_CONSTRAINT = 1159,
     DROP_CONSTRAINT = 1160,
     DROP_SYNONYM = 1161,
     CONSTRAINT = 1162,
     LOCAL_REPORT = 1166,
     LOCAL_PDF_REPORT = 1167,
     DOUBLE_PRECISION = 1171,
     COUNT_MULTIPLY = 1172,
     MODIFY_NEXT_SIZE = 1192,
     LOCK_MODE_PAGE = 1193,
     LOCK_MODE_ROW = 1194,
     UNITS_YEAR = 1201,
     UNITS_MONTH = 1202,
     UNITS_DAY = 1203,
     UNITS_HOUR = 1204,
     UNITS_MINUTE = 1205,
     UNITS_SECOND = 1206,
     TO_CLUSTER = 1211,
     TO_NOT_CLUSTER = 1212,
     CREATE_UC_IDX = 1214,
     CREATE_U_IDX = 1215,
     CREATE_C_IDX = 1216,
     CREATE_IDX = 1217,
     CM = 1224,
     DOUBLE_COLON = 1227,
     SQLSICS = 1233,
     CREATE_SCHEMA = 1234,
     SQLSIRR = 1235,
     UPDATESTATS_T = 1236,
     SQLSICR = 1237,
     SQLSIDR = 1248,
     CREATE_TEMP_TABLE = 1249,
     WITH_CHECK_OPTION = 1257,
     WITH_GRANT_OPTION = 1258,
     SQLSLMNW = 1259,
     WHERE_CURRENT_OF = 1265,
     NOT_NULL_UNIQUE = 1273,
     SQLSLMW = 1280,
     ALL_PRIVILEGES = 1282,
     CREATE_SYNONYM = 1286,
     DROP_TABLE = 1287,
     INEXCLUSIVE = 1289,
     UPDATESTATS = 1294,
     CREATE_TABLE = 1320,
     DEFAULT_NULL = 1321,
     DEFAULT_TODAY = 1322,
     DEFAULT_USER = 1323,
     UNLOCK_TABLE = 1336,
     ROLLBACK_W = 1344,
     SQLSEON = 1346,
     SQLSEOFF = 1347,
     CREATE_VIEW = 1351,
     DELETE_FROM = 1352,
     EXTENT_SIZE = 1359,
     FOREIGN_KEY = 1360,
     INSERT_INTO = 1363,
     IS_NOT_NULL = 1365,
     NOT_MATCHES = 1368,
     PRIMARY_KEY = 1374,
     USE_SESSION = 1381,
     WITH_NO_LOG = 1382,
     INSHARE = 1385,
     BEGIN_WORK = 1391,
     DROP_INDEX = 1396,
     FOR_UPDATE_OF = 1402,
     FOR_UPDATE = 1403,
     REFERENCE = 1405,
     LOCK_TABLE = 1408,
     NOT_EXISTS = 1410,
     REFERENCES = 1412,
     RENCOL = 1413,
     SMALLFLOAT = 1415,
     COMMIT_W = 1426,
     RENTAB = 1433,
     KW_CHAR = 1436,
     NCHAR = 1437,
     NVARCHAR = 1438,
     DELIMITER = 1440,
     DROP_VIEW = 1442,
     EXCLUSIVE = 1445,
     GREATER_THAN_EQ = 1449,
     INTO_TEMP = 1451,
     LOAD_FROM = 1455,
     UNLOAD_TO = 1466,
     DATABASE = 1475,
     DATETIME = 1476,
     DISTINCT = 1478,
     FRACTION = 1485,
     GROUP_BY = 1487,
     INTERVAL = 1488,
     NOT_LIKE = 1490,
     NOT_ILIKE = 1491,
     NOT_NULL = 1492,
     RESOURCE = 1498,
     SMALLINT = 1499,
     IS_NULL = 1505,
     LESS_THAN_EQ = 1506,
     BETWEEN = 1508,
     CLOSE_BRACKET = 1511,
     CONNECT = 1514,
     KW_CURRENT = 1515,
     KW_DECIMAL = 1517,
     DEFAULT = 1519,
     INTEGER = 1527,
     SERIAL8 = 1529,
     MATCHES = 1532,
     VARCHAR = 1545,
     CLOSE_SQUARE = 1548,
     GREATER_THAN = 1549,
     KW_FALSE = 1550,
     NOT_IN = 1551,
     OPEN_BRACKET = 1553,
     KW_DELETE = 1561,
     KW_ESCAPE = 1564,
     EXISTS = 1565,
     EXTEND = 1566,
     HAVING = 1570,
     KW_INSERT = 1572,
     MINUTE = 1576,
     MODIFY = 1577,
     EQUAL = 1579,
     NOT_EQUAL = 1580,
     OPEN_SQUARE = 1582,
     PUBLIC = 1586,
     REVOKE = 1589,
     SECOND = 1593,
     KW_SELECT = 1597,
     SERIAL = 1598,
     UNIQUE = 1601,
     KW_UPDATE = 1603,
     VALUES = 1604,
     KW_NULL = 1607,
     KW_TRUE = 1608,
     ALTER = 1610,
     CHECK = 1616,
     COUNT = 1620,
     KW_FIRST = 1625,
     KW_FLOAT = 1626,
     GRANT = 1629,
     INDEX = 1632,
     LESS_THAN = 1635,
     MONEY = 1637,
     MONTH = 1638,
     KW_MULTIPLY = 1640,
     ORDER = 1641,
     OUTER = 1642,
     UNION = 1651,
     KW_USING_FILTER = 1652,
     WHERE = 1654,
     KW_BYTE = 1661,
     CASE = 1663,
     KW_DATE = 1665,
     DESC = 1666,
     KW_DIVIDE = 1667,
     DROP = 1670,
     ELSE = 1671,
     FROM = 1675,
     HOUR = 1681,
     INTO = 1682,
     LIKE = 1685,
     REAL = 1694,
     SOME = 1699,
     KW_TEXT = 1703,
     KW_THEN = 1704,
     USER = 1705,
     WHEN = 1707,
     YEAR = 1710,
     KW_DOW = 1711,
     XSET = 1713,
     ADD = 1714,
     ALL = 1715,
     KW_AND = 1716,
     ANY = 1717,
     ASC = 1718,
     AVG = 1719,
     COLON = 1720,
     KW_COMMA = 1721,
     DAY = 1722,
     DBA = 1723,
     KW_FOR = 1727,
     XMAX = 1732,
     XMIN = 1733,
     KW_MINUS = 1734,
     KW_MOD = 1735,
     KW_NOT = 1736,
     KW_ROW = 1740,
     KW_SUM = 1743,
     ATSIGN = 1746,
     KW_PLUS = 1747,
     KW_AS_USER = 1752,
     KW_AS = 1753,
     KW_BY = 1755,
     KW_DOT = 1756,
     KW_IN = 1759,
     KW_ON = 1761,
     KW_OR = 1762,
     KW_TO = 1763,
     BEFORE = 1801,
     END = 1805,
     TILDE = 1812,
     ILIKE = 1813,
     FILLFACTOR = 1816,
     KW_EXTENDS = 1819,
     TIME = 1821,
     KW_TODAY = 1828,
     KW_ROWID = 1829,
     CURSOR_NAME_FUNCTION = 2176,
     TIMESTAMP = 2177,
     MOVE_TO_TOP = 2178,
     LINETO_TOP = 2179,
     KW_HEIGHT = 2180,
     SET_STROKE_COLOR = 2181,
     SET_FONT_SIZE = 2182,
     SET_COLOR = 2183,
     MOVE_TO = 2184,
     FILL_STROKE = 2185,
     STROKE = 2186,
     LINE_TO = 2187,
     SET_FONT_NAME = 2188,
     BOOKMARK = 2189,
     KW_FILL = 2190,
     KW_WIDTH = 2191,
     ERRORHOOK = 2193,
     KW_CAST = 2194
   };
#endif
/* Tokens.  */
#define INT_VALUE 2196
#define NAMED 2197
#define NAMED_GEN 2198
#define CHAR_VALUE 2199
#define NOT_USED_1 2200
#define NOT_USED_2 2201
#define NOT_USED_3 2202
#define NOT_USED_4 2203
#define NOT_USED_5 2204
#define NOT_USED_6 2205
#define NOT_USED_7 2206
#define NOT_USED_8 2207
#define NUMBER_VALUE 2208
#define SEMICOLON 2209
#define QUESTION_MARK 2210
#define CLINE 2211
#define CH 2212
#define MARK_VAR 2213
#define END_MARK_VAR 2214
#define LEFT_JOIN 1001
#define LINT_IGNORE 1002
#define LINT_EXPECT 1003
#define INNER_JOIN 1004
#define WITH_CONVERSIONS 1010
#define WITHOUT_CONVERSIONS 1011
#define BARCODE 1012
#define BARCODE_NO_TEXT 1013
#define BARCODETYPE 1014
#define BLUEBAR_COLOR_EQUAL 1015
#define BLUEBAR_STYLE_EQUAL_RECTANGLE_COLOR_EQUAL 1016
#define BLUEBAR_STYLE_EQUAL_RECTANGLE 1017
#define BLUEBAR_STYLE_EQUAL_LINE_COLOR_EQUAL 1018
#define BLUEBAR_STYLE_EQUAL_LINE 1019
#define BLUEBAR 1020
#define USING_BTREE 1027
#define USING_RTREE 1028
#define ASCOPY 1045
#define SET_BUFFERED_LOG 1053
#define SET_FILL_COLOR 1054
#define SET_PARAMETER 1055
#define SET_LOG 1056
#define MDY 1058
#define WEEKDAY 1059
#define MODE_ANSI 1062
#define START_DATABASE 1063
#define WITH_LOG_IN 1064
#define SET_CONSTRAINTS_ALL_IMMEDIATE 1065
#define DATETIME_VALUE 1078
#define INTERVAL_VALUE 1079
#define RECOVER_TABLE 1080
#define ROLLFORWARD_DATABASE 1081
#define DROP_TRIGGER 1097
#define DROP_AUDIT_FOR 1098
#define CREATE_AUDIT_FOR 1099
#define EXECUTE_PROCEDURE 1103
#define ALTER_TABLE 1110
#define ALTER_INDEX 1111
#define NEXT_SIZE 1112
#define XSET_MULTIPLY_EQUAL_OPEN_BRACKET 1149
#define XSET_ident_DOT_MULTIPLY_EQUAL_OPEN_BRACKET 1150
#define XSET_ident_DOT_MULTIPLY_EQUAL 1151
#define XSET_MULTIPLY_EQUAL 1152
#define XSET_OPEN_BRACKET 1153
#define CREATE_DATABASE 1156
#define DROP_DATABASE 1157
#define ADD_CONSTRAINT 1159
#define DROP_CONSTRAINT 1160
#define DROP_SYNONYM 1161
#define CONSTRAINT 1162
#define LOCAL_REPORT 1166
#define LOCAL_PDF_REPORT 1167
#define DOUBLE_PRECISION 1171
#define COUNT_MULTIPLY 1172
#define MODIFY_NEXT_SIZE 1192
#define LOCK_MODE_PAGE 1193
#define LOCK_MODE_ROW 1194
#define UNITS_YEAR 1201
#define UNITS_MONTH 1202
#define UNITS_DAY 1203
#define UNITS_HOUR 1204
#define UNITS_MINUTE 1205
#define UNITS_SECOND 1206
#define TO_CLUSTER 1211
#define TO_NOT_CLUSTER 1212
#define CREATE_UC_IDX 1214
#define CREATE_U_IDX 1215
#define CREATE_C_IDX 1216
#define CREATE_IDX 1217
#define CM 1224
#define DOUBLE_COLON 1227
#define SQLSICS 1233
#define CREATE_SCHEMA 1234
#define SQLSIRR 1235
#define UPDATESTATS_T 1236
#define SQLSICR 1237
#define SQLSIDR 1248
#define CREATE_TEMP_TABLE 1249
#define WITH_CHECK_OPTION 1257
#define WITH_GRANT_OPTION 1258
#define SQLSLMNW 1259
#define WHERE_CURRENT_OF 1265
#define NOT_NULL_UNIQUE 1273
#define SQLSLMW 1280
#define ALL_PRIVILEGES 1282
#define CREATE_SYNONYM 1286
#define DROP_TABLE 1287
#define INEXCLUSIVE 1289
#define UPDATESTATS 1294
#define CREATE_TABLE 1320
#define DEFAULT_NULL 1321
#define DEFAULT_TODAY 1322
#define DEFAULT_USER 1323
#define UNLOCK_TABLE 1336
#define ROLLBACK_W 1344
#define SQLSEON 1346
#define SQLSEOFF 1347
#define CREATE_VIEW 1351
#define DELETE_FROM 1352
#define EXTENT_SIZE 1359
#define FOREIGN_KEY 1360
#define INSERT_INTO 1363
#define IS_NOT_NULL 1365
#define NOT_MATCHES 1368
#define PRIMARY_KEY 1374
#define USE_SESSION 1381
#define WITH_NO_LOG 1382
#define INSHARE 1385
#define BEGIN_WORK 1391
#define DROP_INDEX 1396
#define FOR_UPDATE_OF 1402
#define FOR_UPDATE 1403
#define REFERENCE 1405
#define LOCK_TABLE 1408
#define NOT_EXISTS 1410
#define REFERENCES 1412
#define RENCOL 1413
#define SMALLFLOAT 1415
#define COMMIT_W 1426
#define RENTAB 1433
#define KW_CHAR 1436
#define NCHAR 1437
#define NVARCHAR 1438
#define DELIMITER 1440
#define DROP_VIEW 1442
#define EXCLUSIVE 1445
#define GREATER_THAN_EQ 1449
#define INTO_TEMP 1451
#define LOAD_FROM 1455
#define UNLOAD_TO 1466
#define DATABASE 1475
#define DATETIME 1476
#define DISTINCT 1478
#define FRACTION 1485
#define GROUP_BY 1487
#define INTERVAL 1488
#define NOT_LIKE 1490
#define NOT_ILIKE 1491
#define NOT_NULL 1492
#define RESOURCE 1498
#define SMALLINT 1499
#define IS_NULL 1505
#define LESS_THAN_EQ 1506
#define BETWEEN 1508
#define CLOSE_BRACKET 1511
#define CONNECT 1514
#define KW_CURRENT 1515
#define KW_DECIMAL 1517
#define DEFAULT 1519
#define INTEGER 1527
#define SERIAL8 1529
#define MATCHES 1532
#define VARCHAR 1545
#define CLOSE_SQUARE 1548
#define GREATER_THAN 1549
#define KW_FALSE 1550
#define NOT_IN 1551
#define OPEN_BRACKET 1553
#define KW_DELETE 1561
#define KW_ESCAPE 1564
#define EXISTS 1565
#define EXTEND 1566
#define HAVING 1570
#define KW_INSERT 1572
#define MINUTE 1576
#define MODIFY 1577
#define EQUAL 1579
#define NOT_EQUAL 1580
#define OPEN_SQUARE 1582
#define PUBLIC 1586
#define REVOKE 1589
#define SECOND 1593
#define KW_SELECT 1597
#define SERIAL 1598
#define UNIQUE 1601
#define KW_UPDATE 1603
#define VALUES 1604
#define KW_NULL 1607
#define KW_TRUE 1608
#define ALTER 1610
#define CHECK 1616
#define COUNT 1620
#define KW_FIRST 1625
#define KW_FLOAT 1626
#define GRANT 1629
#define INDEX 1632
#define LESS_THAN 1635
#define MONEY 1637
#define MONTH 1638
#define KW_MULTIPLY 1640
#define ORDER 1641
#define OUTER 1642
#define UNION 1651
#define KW_USING_FILTER 1652
#define WHERE 1654
#define KW_BYTE 1661
#define CASE 1663
#define KW_DATE 1665
#define DESC 1666
#define KW_DIVIDE 1667
#define DROP 1670
#define ELSE 1671
#define FROM 1675
#define HOUR 1681
#define INTO 1682
#define LIKE 1685
#define REAL 1694
#define SOME 1699
#define KW_TEXT 1703
#define KW_THEN 1704
#define USER 1705
#define WHEN 1707
#define YEAR 1710
#define KW_DOW 1711
#define XSET 1713
#define ADD 1714
#define ALL 1715
#define KW_AND 1716
#define ANY 1717
#define ASC 1718
#define AVG 1719
#define COLON 1720
#define KW_COMMA 1721
#define DAY 1722
#define DBA 1723
#define KW_FOR 1727
#define XMAX 1732
#define XMIN 1733
#define KW_MINUS 1734
#define KW_MOD 1735
#define KW_NOT 1736
#define KW_ROW 1740
#define KW_SUM 1743
#define ATSIGN 1746
#define KW_PLUS 1747
#define KW_AS_USER 1752
#define KW_AS 1753
#define KW_BY 1755
#define KW_DOT 1756
#define KW_IN 1759
#define KW_ON 1761
#define KW_OR 1762
#define KW_TO 1763
#define BEFORE 1801
#define END 1805
#define TILDE 1812
#define ILIKE 1813
#define FILLFACTOR 1816
#define KW_EXTENDS 1819
#define TIME 1821
#define KW_TODAY 1828
#define KW_ROWID 1829
#define CURSOR_NAME_FUNCTION 2176
#define TIMESTAMP 2177
#define MOVE_TO_TOP 2178
#define LINETO_TOP 2179
#define KW_HEIGHT 2180
#define SET_STROKE_COLOR 2181
#define SET_FONT_SIZE 2182
#define SET_COLOR 2183
#define MOVE_TO 2184
#define FILL_STROKE 2185
#define STROKE 2186
#define LINE_TO 2187
#define SET_FONT_NAME 2188
#define BOOKMARK 2189
#define KW_FILL 2190
#define KW_WIDTH 2191
#define ERRORHOOK 2193
#define KW_CAST 2194




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
#line 659 "y.tab.h"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE sqlparse_yylval;


