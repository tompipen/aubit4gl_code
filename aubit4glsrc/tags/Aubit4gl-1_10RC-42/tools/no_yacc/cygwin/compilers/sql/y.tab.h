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
     INT_VALUE = 2193,
     NAMED = 2194,
     NAMED_GEN = 2195,
     CHAR_VALUE = 2196,
     NOT_USED_1 = 2197,
     NOT_USED_2 = 2198,
     NOT_USED_3 = 2199,
     NOT_USED_4 = 2200,
     NOT_USED_5 = 2201,
     NOT_USED_6 = 2202,
     NOT_USED_7 = 2203,
     NOT_USED_8 = 2204,
     NUMBER_VALUE = 2205,
     SEMICOLON = 2206,
     QUESTION_MARK = 2207,
     CLINE = 2208,
     CH = 2209,
     MARK_VAR = 2210,
     END_MARK_VAR = 2211,
     LEFT_JOIN = 1001,
     INNER_JOIN = 1002,
     WITH_CONVERSIONS = 1008,
     WITHOUT_CONVERSIONS = 1009,
     BARCODE = 1010,
     BARCODE_NO_TEXT = 1011,
     BARCODETYPE = 1012,
     BLUEBAR_COLOR_EQUAL = 1013,
     BLUEBAR_STYLE_EQUAL_RECTANGLE_COLOR_EQUAL = 1014,
     BLUEBAR_STYLE_EQUAL_RECTANGLE = 1015,
     BLUEBAR_STYLE_EQUAL_LINE_COLOR_EQUAL = 1016,
     BLUEBAR_STYLE_EQUAL_LINE = 1017,
     BLUEBAR = 1018,
     USING_BTREE = 1025,
     USING_RTREE = 1026,
     ASCOPY = 1043,
     SET_BUFFERED_LOG = 1051,
     SET_FILL_COLOR = 1052,
     SET_PARAMETER = 1053,
     SET_LOG = 1054,
     MDY = 1056,
     WEEKDAY = 1057,
     MODE_ANSI = 1060,
     START_DATABASE = 1061,
     WITH_LOG_IN = 1062,
     SET_CONSTRAINTS_ALL_IMMEDIATE = 1063,
     DATETIME_VALUE = 1076,
     INTERVAL_VALUE = 1077,
     RECOVER_TABLE = 1078,
     ROLLFORWARD_DATABASE = 1079,
     DROP_TRIGGER = 1095,
     DROP_AUDIT_FOR = 1096,
     CREATE_AUDIT_FOR = 1097,
     EXECUTE_PROCEDURE = 1101,
     ALTER_TABLE = 1108,
     ALTER_INDEX = 1109,
     NEXT_SIZE = 1110,
     XSET_MULTIPLY_EQUAL_OPEN_BRACKET = 1147,
     XSET_ident_DOT_MULTIPLY_EQUAL_OPEN_BRACKET = 1148,
     XSET_ident_DOT_MULTIPLY_EQUAL = 1149,
     XSET_MULTIPLY_EQUAL = 1150,
     XSET_OPEN_BRACKET = 1151,
     CREATE_DATABASE = 1154,
     DROP_DATABASE = 1155,
     ADD_CONSTRAINT = 1157,
     DROP_CONSTRAINT = 1158,
     DROP_SYNONYM = 1159,
     CONSTRAINT = 1160,
     LOCAL_REPORT = 1164,
     LOCAL_PDF_REPORT = 1165,
     DOUBLE_PRECISION = 1169,
     COUNT_MULTIPLY = 1170,
     MODIFY_NEXT_SIZE = 1190,
     LOCK_MODE_PAGE = 1191,
     LOCK_MODE_ROW = 1192,
     UNITS_YEAR = 1199,
     UNITS_MONTH = 1200,
     UNITS_DAY = 1201,
     UNITS_HOUR = 1202,
     UNITS_MINUTE = 1203,
     UNITS_SECOND = 1204,
     TO_CLUSTER = 1209,
     TO_NOT_CLUSTER = 1210,
     CREATE_UC_IDX = 1212,
     CREATE_U_IDX = 1213,
     CREATE_C_IDX = 1214,
     CREATE_IDX = 1215,
     CM = 1222,
     DOUBLE_COLON = 1225,
     SQLSICS = 1231,
     CREATE_SCHEMA = 1232,
     SQLSIRR = 1233,
     UPDATESTATS_T = 1234,
     SQLSICR = 1235,
     SQLSIDR = 1246,
     CREATE_TEMP_TABLE = 1247,
     WITH_CHECK_OPTION = 1255,
     WITH_GRANT_OPTION = 1256,
     SQLSLMNW = 1257,
     WHERE_CURRENT_OF = 1263,
     NOT_NULL_UNIQUE = 1271,
     SQLSLMW = 1278,
     ALL_PRIVILEGES = 1280,
     CREATE_SYNONYM = 1284,
     DROP_TABLE = 1285,
     INEXCLUSIVE = 1287,
     UPDATESTATS = 1292,
     CREATE_TABLE = 1318,
     DEFAULT_NULL = 1319,
     DEFAULT_TODAY = 1320,
     DEFAULT_USER = 1321,
     UNLOCK_TABLE = 1334,
     ROLLBACK_W = 1342,
     SQLSEON = 1344,
     SQLSEOFF = 1345,
     CREATE_VIEW = 1349,
     DELETE_FROM = 1350,
     EXTENT_SIZE = 1357,
     FOREIGN_KEY = 1358,
     INSERT_INTO = 1361,
     IS_NOT_NULL = 1363,
     NOT_MATCHES = 1366,
     PRIMARY_KEY = 1372,
     USE_SESSION = 1379,
     WITH_NO_LOG = 1380,
     INSHARE = 1383,
     BEGIN_WORK = 1389,
     DROP_INDEX = 1394,
     FOR_UPDATE_OF = 1400,
     FOR_UPDATE = 1401,
     REFERENCE = 1403,
     LOCK_TABLE = 1406,
     NOT_EXISTS = 1408,
     REFERENCES = 1410,
     RENCOL = 1411,
     SMALLFLOAT = 1413,
     COMMIT_W = 1424,
     RENTAB = 1431,
     KW_CHAR = 1434,
     NCHAR = 1435,
     NVARCHAR = 1436,
     DELIMITER = 1438,
     DROP_VIEW = 1440,
     EXCLUSIVE = 1443,
     GREATER_THAN_EQ = 1447,
     INTO_TEMP = 1449,
     LOAD_FROM = 1453,
     UNLOAD_TO = 1464,
     DATABASE = 1473,
     DATETIME = 1474,
     DISTINCT = 1476,
     FRACTION = 1483,
     GROUP_BY = 1485,
     INTERVAL = 1486,
     NOT_LIKE = 1488,
     NOT_ILIKE = 1489,
     NOT_NULL = 1490,
     RESOURCE = 1496,
     SMALLINT = 1497,
     IS_NULL = 1503,
     LESS_THAN_EQ = 1504,
     BETWEEN = 1506,
     CLOSE_BRACKET = 1509,
     CONNECT = 1512,
     KW_CURRENT = 1513,
     KW_DECIMAL = 1515,
     DEFAULT = 1517,
     INTEGER = 1525,
     SERIAL8 = 1527,
     MATCHES = 1530,
     VARCHAR = 1543,
     CLOSE_SQUARE = 1546,
     GREATER_THAN = 1547,
     KW_FALSE = 1548,
     NOT_IN = 1549,
     OPEN_BRACKET = 1551,
     KW_DELETE = 1559,
     KW_ESCAPE = 1562,
     EXISTS = 1563,
     EXTEND = 1564,
     HAVING = 1568,
     KW_INSERT = 1570,
     MINUTE = 1574,
     MODIFY = 1575,
     EQUAL = 1577,
     NOT_EQUAL = 1578,
     OPEN_SQUARE = 1580,
     PUBLIC = 1584,
     REVOKE = 1587,
     SECOND = 1591,
     KW_SELECT = 1595,
     SERIAL = 1596,
     UNIQUE = 1599,
     KW_UPDATE = 1601,
     VALUES = 1602,
     KW_NULL = 1605,
     KW_TRUE = 1606,
     ALTER = 1608,
     CHECK = 1614,
     COUNT = 1618,
     KW_FIRST = 1623,
     KW_FLOAT = 1624,
     GRANT = 1627,
     INDEX = 1630,
     LESS_THAN = 1633,
     MONEY = 1635,
     MONTH = 1636,
     KW_MULTIPLY = 1638,
     ORDER = 1639,
     OUTER = 1640,
     UNION = 1649,
     KW_USING_FILTER = 1650,
     WHERE = 1652,
     KW_BYTE = 1659,
     CASE = 1661,
     KW_DATE = 1663,
     DESC = 1664,
     KW_DIVIDE = 1665,
     DROP = 1668,
     ELSE = 1669,
     FROM = 1673,
     HOUR = 1679,
     INTO = 1680,
     LIKE = 1683,
     REAL = 1692,
     SOME = 1697,
     KW_TEXT = 1701,
     KW_THEN = 1702,
     USER = 1703,
     WHEN = 1705,
     YEAR = 1708,
     KW_DOW = 1709,
     XSET = 1711,
     ADD = 1712,
     ALL = 1713,
     KW_AND = 1714,
     ANY = 1715,
     ASC = 1716,
     AVG = 1717,
     COLON = 1718,
     KW_COMMA = 1719,
     DAY = 1720,
     DBA = 1721,
     KW_FOR = 1725,
     XMAX = 1730,
     XMIN = 1731,
     KW_MINUS = 1732,
     KW_MOD = 1733,
     KW_NOT = 1734,
     KW_ROW = 1738,
     KW_SUM = 1741,
     ATSIGN = 1744,
     KW_PLUS = 1745,
     KW_AS_USER = 1750,
     KW_AS = 1751,
     KW_BY = 1753,
     KW_DOT = 1754,
     KW_IN = 1757,
     KW_ON = 1759,
     KW_OR = 1760,
     KW_TO = 1761,
     BEFORE = 1799,
     END = 1803,
     TILDE = 1810,
     ILIKE = 1811,
     FILLFACTOR = 1814,
     KW_EXTENDS = 1817,
     TIME = 1819,
     KW_TODAY = 1826,
     KW_ROWID = 1827,
     CURSOR_NAME_FUNCTION = 2174,
     TIMESTAMP = 2175,
     MOVE_TO_TOP = 2176,
     LINETO_TOP = 2177,
     KW_HEIGHT = 2178,
     SET_STROKE_COLOR = 2179,
     SET_FONT_SIZE = 2180,
     SET_COLOR = 2181,
     MOVE_TO = 2182,
     FILL_STROKE = 2183,
     STROKE = 2184,
     LINE_TO = 2185,
     SET_FONT_NAME = 2186,
     BOOKMARK = 2187,
     KW_FILL = 2188,
     KW_WIDTH = 2189,
     ERRORHOOK = 2191
   };
#endif
/* Tokens.  */
#define INT_VALUE 2193
#define NAMED 2194
#define NAMED_GEN 2195
#define CHAR_VALUE 2196
#define NOT_USED_1 2197
#define NOT_USED_2 2198
#define NOT_USED_3 2199
#define NOT_USED_4 2200
#define NOT_USED_5 2201
#define NOT_USED_6 2202
#define NOT_USED_7 2203
#define NOT_USED_8 2204
#define NUMBER_VALUE 2205
#define SEMICOLON 2206
#define QUESTION_MARK 2207
#define CLINE 2208
#define CH 2209
#define MARK_VAR 2210
#define END_MARK_VAR 2211
#define LEFT_JOIN 1001
#define INNER_JOIN 1002
#define WITH_CONVERSIONS 1008
#define WITHOUT_CONVERSIONS 1009
#define BARCODE 1010
#define BARCODE_NO_TEXT 1011
#define BARCODETYPE 1012
#define BLUEBAR_COLOR_EQUAL 1013
#define BLUEBAR_STYLE_EQUAL_RECTANGLE_COLOR_EQUAL 1014
#define BLUEBAR_STYLE_EQUAL_RECTANGLE 1015
#define BLUEBAR_STYLE_EQUAL_LINE_COLOR_EQUAL 1016
#define BLUEBAR_STYLE_EQUAL_LINE 1017
#define BLUEBAR 1018
#define USING_BTREE 1025
#define USING_RTREE 1026
#define ASCOPY 1043
#define SET_BUFFERED_LOG 1051
#define SET_FILL_COLOR 1052
#define SET_PARAMETER 1053
#define SET_LOG 1054
#define MDY 1056
#define WEEKDAY 1057
#define MODE_ANSI 1060
#define START_DATABASE 1061
#define WITH_LOG_IN 1062
#define SET_CONSTRAINTS_ALL_IMMEDIATE 1063
#define DATETIME_VALUE 1076
#define INTERVAL_VALUE 1077
#define RECOVER_TABLE 1078
#define ROLLFORWARD_DATABASE 1079
#define DROP_TRIGGER 1095
#define DROP_AUDIT_FOR 1096
#define CREATE_AUDIT_FOR 1097
#define EXECUTE_PROCEDURE 1101
#define ALTER_TABLE 1108
#define ALTER_INDEX 1109
#define NEXT_SIZE 1110
#define XSET_MULTIPLY_EQUAL_OPEN_BRACKET 1147
#define XSET_ident_DOT_MULTIPLY_EQUAL_OPEN_BRACKET 1148
#define XSET_ident_DOT_MULTIPLY_EQUAL 1149
#define XSET_MULTIPLY_EQUAL 1150
#define XSET_OPEN_BRACKET 1151
#define CREATE_DATABASE 1154
#define DROP_DATABASE 1155
#define ADD_CONSTRAINT 1157
#define DROP_CONSTRAINT 1158
#define DROP_SYNONYM 1159
#define CONSTRAINT 1160
#define LOCAL_REPORT 1164
#define LOCAL_PDF_REPORT 1165
#define DOUBLE_PRECISION 1169
#define COUNT_MULTIPLY 1170
#define MODIFY_NEXT_SIZE 1190
#define LOCK_MODE_PAGE 1191
#define LOCK_MODE_ROW 1192
#define UNITS_YEAR 1199
#define UNITS_MONTH 1200
#define UNITS_DAY 1201
#define UNITS_HOUR 1202
#define UNITS_MINUTE 1203
#define UNITS_SECOND 1204
#define TO_CLUSTER 1209
#define TO_NOT_CLUSTER 1210
#define CREATE_UC_IDX 1212
#define CREATE_U_IDX 1213
#define CREATE_C_IDX 1214
#define CREATE_IDX 1215
#define CM 1222
#define DOUBLE_COLON 1225
#define SQLSICS 1231
#define CREATE_SCHEMA 1232
#define SQLSIRR 1233
#define UPDATESTATS_T 1234
#define SQLSICR 1235
#define SQLSIDR 1246
#define CREATE_TEMP_TABLE 1247
#define WITH_CHECK_OPTION 1255
#define WITH_GRANT_OPTION 1256
#define SQLSLMNW 1257
#define WHERE_CURRENT_OF 1263
#define NOT_NULL_UNIQUE 1271
#define SQLSLMW 1278
#define ALL_PRIVILEGES 1280
#define CREATE_SYNONYM 1284
#define DROP_TABLE 1285
#define INEXCLUSIVE 1287
#define UPDATESTATS 1292
#define CREATE_TABLE 1318
#define DEFAULT_NULL 1319
#define DEFAULT_TODAY 1320
#define DEFAULT_USER 1321
#define UNLOCK_TABLE 1334
#define ROLLBACK_W 1342
#define SQLSEON 1344
#define SQLSEOFF 1345
#define CREATE_VIEW 1349
#define DELETE_FROM 1350
#define EXTENT_SIZE 1357
#define FOREIGN_KEY 1358
#define INSERT_INTO 1361
#define IS_NOT_NULL 1363
#define NOT_MATCHES 1366
#define PRIMARY_KEY 1372
#define USE_SESSION 1379
#define WITH_NO_LOG 1380
#define INSHARE 1383
#define BEGIN_WORK 1389
#define DROP_INDEX 1394
#define FOR_UPDATE_OF 1400
#define FOR_UPDATE 1401
#define REFERENCE 1403
#define LOCK_TABLE 1406
#define NOT_EXISTS 1408
#define REFERENCES 1410
#define RENCOL 1411
#define SMALLFLOAT 1413
#define COMMIT_W 1424
#define RENTAB 1431
#define KW_CHAR 1434
#define NCHAR 1435
#define NVARCHAR 1436
#define DELIMITER 1438
#define DROP_VIEW 1440
#define EXCLUSIVE 1443
#define GREATER_THAN_EQ 1447
#define INTO_TEMP 1449
#define LOAD_FROM 1453
#define UNLOAD_TO 1464
#define DATABASE 1473
#define DATETIME 1474
#define DISTINCT 1476
#define FRACTION 1483
#define GROUP_BY 1485
#define INTERVAL 1486
#define NOT_LIKE 1488
#define NOT_ILIKE 1489
#define NOT_NULL 1490
#define RESOURCE 1496
#define SMALLINT 1497
#define IS_NULL 1503
#define LESS_THAN_EQ 1504
#define BETWEEN 1506
#define CLOSE_BRACKET 1509
#define CONNECT 1512
#define KW_CURRENT 1513
#define KW_DECIMAL 1515
#define DEFAULT 1517
#define INTEGER 1525
#define SERIAL8 1527
#define MATCHES 1530
#define VARCHAR 1543
#define CLOSE_SQUARE 1546
#define GREATER_THAN 1547
#define KW_FALSE 1548
#define NOT_IN 1549
#define OPEN_BRACKET 1551
#define KW_DELETE 1559
#define KW_ESCAPE 1562
#define EXISTS 1563
#define EXTEND 1564
#define HAVING 1568
#define KW_INSERT 1570
#define MINUTE 1574
#define MODIFY 1575
#define EQUAL 1577
#define NOT_EQUAL 1578
#define OPEN_SQUARE 1580
#define PUBLIC 1584
#define REVOKE 1587
#define SECOND 1591
#define KW_SELECT 1595
#define SERIAL 1596
#define UNIQUE 1599
#define KW_UPDATE 1601
#define VALUES 1602
#define KW_NULL 1605
#define KW_TRUE 1606
#define ALTER 1608
#define CHECK 1614
#define COUNT 1618
#define KW_FIRST 1623
#define KW_FLOAT 1624
#define GRANT 1627
#define INDEX 1630
#define LESS_THAN 1633
#define MONEY 1635
#define MONTH 1636
#define KW_MULTIPLY 1638
#define ORDER 1639
#define OUTER 1640
#define UNION 1649
#define KW_USING_FILTER 1650
#define WHERE 1652
#define KW_BYTE 1659
#define CASE 1661
#define KW_DATE 1663
#define DESC 1664
#define KW_DIVIDE 1665
#define DROP 1668
#define ELSE 1669
#define FROM 1673
#define HOUR 1679
#define INTO 1680
#define LIKE 1683
#define REAL 1692
#define SOME 1697
#define KW_TEXT 1701
#define KW_THEN 1702
#define USER 1703
#define WHEN 1705
#define YEAR 1708
#define KW_DOW 1709
#define XSET 1711
#define ADD 1712
#define ALL 1713
#define KW_AND 1714
#define ANY 1715
#define ASC 1716
#define AVG 1717
#define COLON 1718
#define KW_COMMA 1719
#define DAY 1720
#define DBA 1721
#define KW_FOR 1725
#define XMAX 1730
#define XMIN 1731
#define KW_MINUS 1732
#define KW_MOD 1733
#define KW_NOT 1734
#define KW_ROW 1738
#define KW_SUM 1741
#define ATSIGN 1744
#define KW_PLUS 1745
#define KW_AS_USER 1750
#define KW_AS 1751
#define KW_BY 1753
#define KW_DOT 1754
#define KW_IN 1757
#define KW_ON 1759
#define KW_OR 1760
#define KW_TO 1761
#define BEFORE 1799
#define END 1803
#define TILDE 1810
#define ILIKE 1811
#define FILLFACTOR 1814
#define KW_EXTENDS 1817
#define TIME 1819
#define KW_TODAY 1826
#define KW_ROWID 1827
#define CURSOR_NAME_FUNCTION 2174
#define TIMESTAMP 2175
#define MOVE_TO_TOP 2176
#define LINETO_TOP 2177
#define KW_HEIGHT 2178
#define SET_STROKE_COLOR 2179
#define SET_FONT_SIZE 2180
#define SET_COLOR 2181
#define MOVE_TO 2182
#define FILL_STROKE 2183
#define STROKE 2184
#define LINE_TO 2185
#define SET_FONT_NAME 2186
#define BOOKMARK 2187
#define KW_FILL 2188
#define KW_WIDTH 2189
#define ERRORHOOK 2191




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
#line 648 "y.tab.h"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE sqlparse_yylval;
