/* A Bison parser, made by GNU Bison 2.4.3.  */

/* Skeleton interface for Bison's Yacc-like parsers in C
   
      Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006,
   2009, 2010 Free Software Foundation, Inc.
   
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
     INT_VALUE = 2249,
     NAMED = 2250,
     NAMED_GEN = 2251,
     CHAR_VALUE = 2252,
     NOT_USED_1 = 2253,
     NOT_USED_2 = 2254,
     NOT_USED_3 = 2255,
     NOT_USED_4 = 2256,
     NOT_USED_5 = 2257,
     NOT_USED_6 = 2258,
     NOT_USED_7 = 2259,
     NOT_USED_8 = 2260,
     NUMBER_VALUE = 2261,
     SEMICOLON = 2262,
     QUESTION_MARK = 2263,
     CLINE = 2264,
     CH = 2265,
     MARK_VAR = 2266,
     END_MARK_VAR = 2267,
     WITH_LISTING_IN = 1001,
     BACKQUOTE = 1002,
     SET_POSTGRESQL_SEARCH_PATH = 1003,
     SET_CONSTRAINTS_ALL_DEFERRED = 1004,
     KW_LIMIT = 1005,
     DOCUMENT = 1006,
     ON_EXCEPTION = 1008,
     SET_DEBUG_FILE_TO = 1009,
     CREATE_DBA_PROCEDURE = 1014,
     CREATE_FUNCTION = 1015,
     CREATE_DBA_FUNCTION = 1016,
     USE_SESSION = 1018,
     KW_RUN_CLIENT = 1019,
     LEFT_JOIN = 1021,
     IGNORE_ERRORS = 1024,
     SQLERRMESSAGE = 1025,
     DISPLAY_NULL_TO = 1026,
     UNBUFFERED = 1027,
     KW_PICTURE = 1028,
     ON_CHANGE = 1029,
     INNER_JOIN = 1030,
     UI_INTERFACE_DOT_FRONTCALL = 1033,
     UICOMBOBOX = 1037,
     UIBROWSER = 1038,
     UIPROGRESS = 1039,
     UIGANTT = 1040,
     UIFORM = 1043,
     USING_BTREE = 1059,
     USING_RTREE = 1060,
     SET_BUFFERED_LOG = 1079,
     SET_LOG = 1082,
     MDY = 1084,
     WEEKDAY = 1085,
     MODE_ANSI = 1088,
     START_DATABASE = 1089,
     WITH_LOG_IN = 1090,
     SET_CONSTRAINTS_ALL_IMMEDIATE = 1091,
     DATETIME_VALUE = 1104,
     INTERVAL_VALUE = 1105,
     RECOVER_TABLE = 1106,
     ROLLFORWARD_DATABASE = 1107,
     CONCAT_PIPES = 1121,
     DROP_TRIGGER = 1123,
     DROP_AUDIT_FOR = 1124,
     CREATE_AUDIT_FOR = 1125,
     EXECUTE_PROCEDURE = 1129,
     ALTER_TABLE = 1136,
     ALTER_INDEX = 1137,
     NEXT_SIZE = 1138,
     KW_WHENEVER_SIGNAL = 1175,
     KW_SIGNAL_TOKEN = 1176,
     XSET_MULTIPLY_EQUAL_OPEN_BRACKET = 1177,
     XSET_ident_DOT_MULTIPLY_EQUAL_OPEN_BRACKET = 1178,
     XSET_ident_DOT_MULTIPLY_EQUAL = 1179,
     XSET_MULTIPLY_EQUAL = 1180,
     XSET_OPEN_BRACKET = 1181,
     CREATE_DATABASE = 1184,
     DROP_DATABASE = 1185,
     ADD_CONSTRAINT = 1187,
     DROP_CONSTRAINT = 1188,
     DROP_SYNONYM = 1189,
     CONSTRAINT = 1190,
     NOT_FIELD_TOUCHED_CURRENT = 1193,
     FIELD_TOUCHED_CURRENT = 1194,
     OBJECT_FUNCTION = 1196,
     DOUBLE_PRECISION = 1202,
     COUNT_MULTIPLY = 1203,
     KW_ASCII_OPEN_BRACKET = 1212,
     MODIFY_NEXT_SIZE = 1224,
     LOCK_MODE_PAGE = 1225,
     LOCK_MODE_ROW = 1226,
     TO_UI = 1231,
     UNITS_YEAR = 1234,
     UNITS_MONTH = 1235,
     UNITS_DAY = 1236,
     UNITS_HOUR = 1237,
     UNITS_MINUTE = 1238,
     UNITS_SECOND = 1239,
     TO_CLUSTER = 1244,
     TO_NOT_CLUSTER = 1245,
     CREATE_UC_IDX = 1247,
     CREATE_U_IDX = 1248,
     CREATE_C_IDX = 1249,
     CREATE_IDX = 1250,
     DOUBLE_COLON = 1260,
     SQLSICS = 1266,
     CREATE_SCHEMA = 1267,
     SQLSIRR = 1268,
     UPDATESTATS_T = 1269,
     SQLSICR = 1270,
     SQLSIDR = 1281,
     CREATE_TEMP_TABLE = 1282,
     WITH_CHECK_OPTION = 1290,
     WITH_GRANT_OPTION = 1291,
     SQLSLMNW = 1292,
     WHERE_CURRENT_OF = 1298,
     NOT_NULL_UNIQUE = 1306,
     SQLSLMW = 1313,
     ALL_PRIVILEGES = 1315,
     CREATE_SYNONYM = 1319,
     DROP_TABLE = 1320,
     INEXCLUSIVE = 1322,
     REPORT_TO_FILE = 1323,
     REPORT_TO_UI = 1324,
     UPDATESTATS = 1329,
     CREATE_TABLE = 1355,
     DEFAULT_NULL = 1356,
     DEFAULT_TODAY = 1357,
     DEFAULT_USER = 1358,
     EXIT_TODO = 1365,
     CONTINUE_TODO = 1366,
     UNLOCK_TABLE = 1373,
     ROLLBACK_W = 1381,
     SQLSEON = 1383,
     SQLSEOFF = 1384,
     CREATE_VIEW = 1388,
     DELETE_FROM = 1389,
     EXTENT_SIZE = 1396,
     FOREIGN_KEY = 1397,
     INSERT_INTO = 1400,
     IS_NOT_NULL = 1402,
     NOT_MATCHES = 1405,
     PRIMARY_KEY = 1411,
     WITH_NO_LOG = 1418,
     INSHARE = 1421,
     BEGIN_WORK = 1427,
     DROP_INDEX = 1432,
     FOR_UPDATE_OF = 1438,
     FOR_UPDATE = 1439,
     LOCK_TABLE = 1444,
     NOT_EXISTS = 1446,
     REFERENCES = 1448,
     RENCOL = 1449,
     SMALLFLOAT = 1451,
     COMMIT_W = 1462,
     RENTAB = 1469,
     KW_CHAR = 1472,
     NCHAR = 1473,
     NVARCHAR = 1474,
     DELIMITER = 1476,
     DROP_VIEW = 1478,
     EXCLUSIVE = 1481,
     GREATER_THAN_EQ = 1485,
     INTO_TEMP = 1487,
     DATABASE = 1511,
     DATETIME = 1512,
     DISTINCT = 1514,
     FRACTION = 1521,
     GROUP_BY = 1523,
     INTERVAL = 1524,
     NOT_LIKE = 1526,
     NOT_ILIKE = 1527,
     NOT_NULL = 1528,
     RESOURCE = 1534,
     SMALLINT = 1535,
     IS_NULL = 1541,
     LESS_THAN_EQ = 1542,
     BETWEEN = 1544,
     CLOSE_BRACKET = 1547,
     CONNECT = 1550,
     KW_CURRENT = 1551,
     KW_DECIMAL = 1553,
     KW_DEFAULT = 1555,
     FGL_SYNCFIELDS = 1563,
     INTEGER = 1564,
     SERIAL8 = 1566,
     MATCHES = 1569,
     VARCHAR = 1582,
     CLOSE_SQUARE = 1585,
     GREATER_THAN = 1586,
     KW_FALSE = 1587,
     NOT_IN = 1588,
     OPEN_BRACKET_SELECT = 1590,
     OPEN_BRACKET = 1591,
     KW_DELETE = 1599,
     KW_ESCAPE = 1602,
     EXISTS = 1603,
     EXTEND = 1604,
     HAVING = 1608,
     KW_INSERT = 1610,
     MINUTE = 1614,
     MODIFY = 1615,
     EQUAL = 1617,
     NOT_EQUAL = 1618,
     OPEN_SQUARE = 1620,
     PUBLIC = 1624,
     KW_RETURN_KEY = 1627,
     REVOKE = 1629,
     SECOND = 1633,
     KW_SELECT = 1637,
     SERIAL = 1638,
     UNIQUE = 1641,
     KW_UPDATE = 1643,
     VALUES = 1644,
     KW_NULL = 1647,
     KW_TRUE = 1648,
     ALTER = 1650,
     CHECK = 1656,
     COUNT = 1660,
     KW_FIRST = 1665,
     KW_FLOAT = 1666,
     GRANT = 1669,
     INDEX = 1672,
     LESS_THAN = 1675,
     MONEY = 1677,
     MONTH = 1678,
     KW_MULTIPLY = 1680,
     ORDER = 1681,
     OUTER = 1682,
     UNION = 1691,
     WHERE = 1694,
     KW_BYTE = 1701,
     CASE = 1703,
     KW_DATE = 1705,
     DESC = 1706,
     KW_DIVIDE = 1707,
     DROP = 1710,
     ELSE = 1711,
     FROM = 1715,
     HOUR = 1721,
     INTO = 1722,
     LIKE = 1725,
     REAL = 1734,
     SOME = 1739,
     KW_TEXT = 1743,
     KW_THEN = 1744,
     USER = 1745,
     WHEN = 1747,
     YEAR = 1750,
     KW_DOW = 1751,
     XSET = 1753,
     ADD = 1754,
     ALL = 1755,
     KW_AND = 1756,
     ANY = 1757,
     ASC = 1758,
     AVG = 1759,
     COLON = 1760,
     KW_COMMA = 1761,
     DAY = 1762,
     DBA = 1763,
     KW_FOR = 1767,
     XMAX = 1772,
     XMIN = 1773,
     KW_MINUS = 1774,
     KW_MOD = 1775,
     KW_NOT = 1776,
     KW_SUM = 1783,
     ATSIGN = 1786,
     KW_PLUS = 1787,
     KW_AS = 1793,
     KW_BY = 1795,
     KW_DOT = 1796,
     KW_IN = 1799,
     KW_ON = 1801,
     KW_OR = 1802,
     KW_TO = 1803,
     BEFORE = 1841,
     END = 1845,
     TILDE = 1852,
     ILIKE = 1853,
     FILLFACTOR = 1856,
     TIME = 1861,
     KW_TODAY = 1868,
     KW_ROWID = 1869,
     TIMESTAMP = 2217,
     KWPIPE = 2247
   };
#endif
/* Tokens.  */
#define INT_VALUE 2249
#define NAMED 2250
#define NAMED_GEN 2251
#define CHAR_VALUE 2252
#define NOT_USED_1 2253
#define NOT_USED_2 2254
#define NOT_USED_3 2255
#define NOT_USED_4 2256
#define NOT_USED_5 2257
#define NOT_USED_6 2258
#define NOT_USED_7 2259
#define NOT_USED_8 2260
#define NUMBER_VALUE 2261
#define SEMICOLON 2262
#define QUESTION_MARK 2263
#define CLINE 2264
#define CH 2265
#define MARK_VAR 2266
#define END_MARK_VAR 2267
#define WITH_LISTING_IN 1001
#define BACKQUOTE 1002
#define SET_POSTGRESQL_SEARCH_PATH 1003
#define SET_CONSTRAINTS_ALL_DEFERRED 1004
#define KW_LIMIT 1005
#define DOCUMENT 1006
#define ON_EXCEPTION 1008
#define SET_DEBUG_FILE_TO 1009
#define CREATE_DBA_PROCEDURE 1014
#define CREATE_FUNCTION 1015
#define CREATE_DBA_FUNCTION 1016
#define USE_SESSION 1018
#define KW_RUN_CLIENT 1019
#define LEFT_JOIN 1021
#define IGNORE_ERRORS 1024
#define SQLERRMESSAGE 1025
#define DISPLAY_NULL_TO 1026
#define UNBUFFERED 1027
#define KW_PICTURE 1028
#define ON_CHANGE 1029
#define INNER_JOIN 1030
#define UI_INTERFACE_DOT_FRONTCALL 1033
#define UICOMBOBOX 1037
#define UIBROWSER 1038
#define UIPROGRESS 1039
#define UIGANTT 1040
#define UIFORM 1043
#define USING_BTREE 1059
#define USING_RTREE 1060
#define SET_BUFFERED_LOG 1079
#define SET_LOG 1082
#define MDY 1084
#define WEEKDAY 1085
#define MODE_ANSI 1088
#define START_DATABASE 1089
#define WITH_LOG_IN 1090
#define SET_CONSTRAINTS_ALL_IMMEDIATE 1091
#define DATETIME_VALUE 1104
#define INTERVAL_VALUE 1105
#define RECOVER_TABLE 1106
#define ROLLFORWARD_DATABASE 1107
#define CONCAT_PIPES 1121
#define DROP_TRIGGER 1123
#define DROP_AUDIT_FOR 1124
#define CREATE_AUDIT_FOR 1125
#define EXECUTE_PROCEDURE 1129
#define ALTER_TABLE 1136
#define ALTER_INDEX 1137
#define NEXT_SIZE 1138
#define KW_WHENEVER_SIGNAL 1175
#define KW_SIGNAL_TOKEN 1176
#define XSET_MULTIPLY_EQUAL_OPEN_BRACKET 1177
#define XSET_ident_DOT_MULTIPLY_EQUAL_OPEN_BRACKET 1178
#define XSET_ident_DOT_MULTIPLY_EQUAL 1179
#define XSET_MULTIPLY_EQUAL 1180
#define XSET_OPEN_BRACKET 1181
#define CREATE_DATABASE 1184
#define DROP_DATABASE 1185
#define ADD_CONSTRAINT 1187
#define DROP_CONSTRAINT 1188
#define DROP_SYNONYM 1189
#define CONSTRAINT 1190
#define NOT_FIELD_TOUCHED_CURRENT 1193
#define FIELD_TOUCHED_CURRENT 1194
#define OBJECT_FUNCTION 1196
#define DOUBLE_PRECISION 1202
#define COUNT_MULTIPLY 1203
#define KW_ASCII_OPEN_BRACKET 1212
#define MODIFY_NEXT_SIZE 1224
#define LOCK_MODE_PAGE 1225
#define LOCK_MODE_ROW 1226
#define TO_UI 1231
#define UNITS_YEAR 1234
#define UNITS_MONTH 1235
#define UNITS_DAY 1236
#define UNITS_HOUR 1237
#define UNITS_MINUTE 1238
#define UNITS_SECOND 1239
#define TO_CLUSTER 1244
#define TO_NOT_CLUSTER 1245
#define CREATE_UC_IDX 1247
#define CREATE_U_IDX 1248
#define CREATE_C_IDX 1249
#define CREATE_IDX 1250
#define DOUBLE_COLON 1260
#define SQLSICS 1266
#define CREATE_SCHEMA 1267
#define SQLSIRR 1268
#define UPDATESTATS_T 1269
#define SQLSICR 1270
#define SQLSIDR 1281
#define CREATE_TEMP_TABLE 1282
#define WITH_CHECK_OPTION 1290
#define WITH_GRANT_OPTION 1291
#define SQLSLMNW 1292
#define WHERE_CURRENT_OF 1298
#define NOT_NULL_UNIQUE 1306
#define SQLSLMW 1313
#define ALL_PRIVILEGES 1315
#define CREATE_SYNONYM 1319
#define DROP_TABLE 1320
#define INEXCLUSIVE 1322
#define REPORT_TO_FILE 1323
#define REPORT_TO_UI 1324
#define UPDATESTATS 1329
#define CREATE_TABLE 1355
#define DEFAULT_NULL 1356
#define DEFAULT_TODAY 1357
#define DEFAULT_USER 1358
#define EXIT_TODO 1365
#define CONTINUE_TODO 1366
#define UNLOCK_TABLE 1373
#define ROLLBACK_W 1381
#define SQLSEON 1383
#define SQLSEOFF 1384
#define CREATE_VIEW 1388
#define DELETE_FROM 1389
#define EXTENT_SIZE 1396
#define FOREIGN_KEY 1397
#define INSERT_INTO 1400
#define IS_NOT_NULL 1402
#define NOT_MATCHES 1405
#define PRIMARY_KEY 1411
#define WITH_NO_LOG 1418
#define INSHARE 1421
#define BEGIN_WORK 1427
#define DROP_INDEX 1432
#define FOR_UPDATE_OF 1438
#define FOR_UPDATE 1439
#define LOCK_TABLE 1444
#define NOT_EXISTS 1446
#define REFERENCES 1448
#define RENCOL 1449
#define SMALLFLOAT 1451
#define COMMIT_W 1462
#define RENTAB 1469
#define KW_CHAR 1472
#define NCHAR 1473
#define NVARCHAR 1474
#define DELIMITER 1476
#define DROP_VIEW 1478
#define EXCLUSIVE 1481
#define GREATER_THAN_EQ 1485
#define INTO_TEMP 1487
#define DATABASE 1511
#define DATETIME 1512
#define DISTINCT 1514
#define FRACTION 1521
#define GROUP_BY 1523
#define INTERVAL 1524
#define NOT_LIKE 1526
#define NOT_ILIKE 1527
#define NOT_NULL 1528
#define RESOURCE 1534
#define SMALLINT 1535
#define IS_NULL 1541
#define LESS_THAN_EQ 1542
#define BETWEEN 1544
#define CLOSE_BRACKET 1547
#define CONNECT 1550
#define KW_CURRENT 1551
#define KW_DECIMAL 1553
#define KW_DEFAULT 1555
#define FGL_SYNCFIELDS 1563
#define INTEGER 1564
#define SERIAL8 1566
#define MATCHES 1569
#define VARCHAR 1582
#define CLOSE_SQUARE 1585
#define GREATER_THAN 1586
#define KW_FALSE 1587
#define NOT_IN 1588
#define OPEN_BRACKET_SELECT 1590
#define OPEN_BRACKET 1591
#define KW_DELETE 1599
#define KW_ESCAPE 1602
#define EXISTS 1603
#define EXTEND 1604
#define HAVING 1608
#define KW_INSERT 1610
#define MINUTE 1614
#define MODIFY 1615
#define EQUAL 1617
#define NOT_EQUAL 1618
#define OPEN_SQUARE 1620
#define PUBLIC 1624
#define KW_RETURN_KEY 1627
#define REVOKE 1629
#define SECOND 1633
#define KW_SELECT 1637
#define SERIAL 1638
#define UNIQUE 1641
#define KW_UPDATE 1643
#define VALUES 1644
#define KW_NULL 1647
#define KW_TRUE 1648
#define ALTER 1650
#define CHECK 1656
#define COUNT 1660
#define KW_FIRST 1665
#define KW_FLOAT 1666
#define GRANT 1669
#define INDEX 1672
#define LESS_THAN 1675
#define MONEY 1677
#define MONTH 1678
#define KW_MULTIPLY 1680
#define ORDER 1681
#define OUTER 1682
#define UNION 1691
#define WHERE 1694
#define KW_BYTE 1701
#define CASE 1703
#define KW_DATE 1705
#define DESC 1706
#define KW_DIVIDE 1707
#define DROP 1710
#define ELSE 1711
#define FROM 1715
#define HOUR 1721
#define INTO 1722
#define LIKE 1725
#define REAL 1734
#define SOME 1739
#define KW_TEXT 1743
#define KW_THEN 1744
#define USER 1745
#define WHEN 1747
#define YEAR 1750
#define KW_DOW 1751
#define XSET 1753
#define ADD 1754
#define ALL 1755
#define KW_AND 1756
#define ANY 1757
#define ASC 1758
#define AVG 1759
#define COLON 1760
#define KW_COMMA 1761
#define DAY 1762
#define DBA 1763
#define KW_FOR 1767
#define XMAX 1772
#define XMIN 1773
#define KW_MINUS 1774
#define KW_MOD 1775
#define KW_NOT 1776
#define KW_SUM 1783
#define ATSIGN 1786
#define KW_PLUS 1787
#define KW_AS 1793
#define KW_BY 1795
#define KW_DOT 1796
#define KW_IN 1799
#define KW_ON 1801
#define KW_OR 1802
#define KW_TO 1803
#define BEFORE 1841
#define END 1845
#define TILDE 1852
#define ILIKE 1853
#define FILLFACTOR 1856
#define TIME 1861
#define KW_TODAY 1868
#define KW_ROWID 1869
#define TIMESTAMP 2217
#define KWPIPE 2247




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 1685 of yacc.c  */
#line 144 "sql.yacc"

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





/* Line 1685 of yacc.c  */
#line 652 "y.tab.h"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE sqlparse_yylval;


