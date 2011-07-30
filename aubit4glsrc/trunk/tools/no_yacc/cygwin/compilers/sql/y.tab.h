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
     INT_VALUE = 2243,
     NAMED = 2244,
     NAMED_GEN = 2245,
     CHAR_VALUE = 2246,
     NOT_USED_1 = 2247,
     NOT_USED_2 = 2248,
     NOT_USED_3 = 2249,
     NOT_USED_4 = 2250,
     NOT_USED_5 = 2251,
     NOT_USED_6 = 2252,
     NOT_USED_7 = 2253,
     NOT_USED_8 = 2254,
     NUMBER_VALUE = 2255,
     SEMICOLON = 2256,
     QUESTION_MARK = 2257,
     CLINE = 2258,
     CH = 2259,
     MARK_VAR = 2260,
     END_MARK_VAR = 2261,
     WITH_LISTING_IN = 1001,
     SET_POSTGRESQL_SEARCH_PATH = 1002,
     SET_CONSTRAINTS_ALL_DEFERRED = 1003,
     KW_LIMIT = 1004,
     DOCUMENT = 1005,
     ON_EXCEPTION = 1007,
     SET_DEBUG_FILE_TO = 1008,
     CREATE_DBA_PROCEDURE = 1013,
     CREATE_FUNCTION = 1014,
     CREATE_DBA_FUNCTION = 1015,
     USE_SESSION = 1017,
     KW_RUN_CLIENT = 1018,
     LEFT_JOIN = 1020,
     IGNORE_ERRORS = 1023,
     SQLERRMESSAGE = 1024,
     DISPLAY_NULL_TO = 1025,
     UNBUFFERED = 1026,
     KW_PICTURE = 1027,
     ON_CHANGE = 1028,
     INNER_JOIN = 1029,
     UI_INTERFACE_DOT_FRONTCALL = 1032,
     UICOMBOBOX = 1036,
     UIFORM = 1039,
     USING_BTREE = 1055,
     USING_RTREE = 1056,
     SET_BUFFERED_LOG = 1075,
     SET_LOG = 1078,
     MDY = 1080,
     WEEKDAY = 1081,
     MODE_ANSI = 1084,
     START_DATABASE = 1085,
     WITH_LOG_IN = 1086,
     SET_CONSTRAINTS_ALL_IMMEDIATE = 1087,
     DATETIME_VALUE = 1100,
     INTERVAL_VALUE = 1101,
     RECOVER_TABLE = 1102,
     ROLLFORWARD_DATABASE = 1103,
     CONCAT_PIPES = 1117,
     DROP_TRIGGER = 1119,
     DROP_AUDIT_FOR = 1120,
     CREATE_AUDIT_FOR = 1121,
     EXECUTE_PROCEDURE = 1125,
     ALTER_TABLE = 1132,
     ALTER_INDEX = 1133,
     NEXT_SIZE = 1134,
     KW_WHENEVER_SIGNAL = 1171,
     KW_SIGNAL_TOKEN = 1172,
     XSET_MULTIPLY_EQUAL_OPEN_BRACKET = 1173,
     XSET_ident_DOT_MULTIPLY_EQUAL_OPEN_BRACKET = 1174,
     XSET_ident_DOT_MULTIPLY_EQUAL = 1175,
     XSET_MULTIPLY_EQUAL = 1176,
     XSET_OPEN_BRACKET = 1177,
     CREATE_DATABASE = 1180,
     DROP_DATABASE = 1181,
     ADD_CONSTRAINT = 1183,
     DROP_CONSTRAINT = 1184,
     DROP_SYNONYM = 1185,
     CONSTRAINT = 1186,
     NOT_FIELD_TOUCHED_CURRENT = 1189,
     FIELD_TOUCHED_CURRENT = 1190,
     OBJECT_FUNCTION = 1192,
     DOUBLE_PRECISION = 1198,
     COUNT_MULTIPLY = 1199,
     KW_ASCII_OPEN_BRACKET = 1208,
     MODIFY_NEXT_SIZE = 1220,
     LOCK_MODE_PAGE = 1221,
     LOCK_MODE_ROW = 1222,
     TO_UI = 1227,
     UNITS_YEAR = 1230,
     UNITS_MONTH = 1231,
     UNITS_DAY = 1232,
     UNITS_HOUR = 1233,
     UNITS_MINUTE = 1234,
     UNITS_SECOND = 1235,
     TO_CLUSTER = 1240,
     TO_NOT_CLUSTER = 1241,
     CREATE_UC_IDX = 1243,
     CREATE_U_IDX = 1244,
     CREATE_C_IDX = 1245,
     CREATE_IDX = 1246,
     DOUBLE_COLON = 1256,
     SQLSICS = 1262,
     CREATE_SCHEMA = 1263,
     SQLSIRR = 1264,
     UPDATESTATS_T = 1265,
     SQLSICR = 1266,
     SQLSIDR = 1277,
     CREATE_TEMP_TABLE = 1278,
     WITH_CHECK_OPTION = 1286,
     WITH_GRANT_OPTION = 1287,
     SQLSLMNW = 1288,
     WHERE_CURRENT_OF = 1294,
     NOT_NULL_UNIQUE = 1302,
     SQLSLMW = 1309,
     ALL_PRIVILEGES = 1311,
     CREATE_SYNONYM = 1315,
     DROP_TABLE = 1316,
     INEXCLUSIVE = 1318,
     REPORT_TO_UI = 1319,
     UPDATESTATS = 1324,
     CREATE_TABLE = 1350,
     DEFAULT_NULL = 1351,
     DEFAULT_TODAY = 1352,
     DEFAULT_USER = 1353,
     EXIT_TODO = 1360,
     CONTINUE_TODO = 1361,
     UNLOCK_TABLE = 1368,
     ROLLBACK_W = 1376,
     SQLSEON = 1378,
     SQLSEOFF = 1379,
     CREATE_VIEW = 1383,
     DELETE_FROM = 1384,
     EXTENT_SIZE = 1391,
     FOREIGN_KEY = 1392,
     INSERT_INTO = 1395,
     IS_NOT_NULL = 1397,
     NOT_MATCHES = 1400,
     PRIMARY_KEY = 1406,
     WITH_NO_LOG = 1413,
     INSHARE = 1416,
     BEGIN_WORK = 1422,
     DROP_INDEX = 1427,
     FOR_UPDATE_OF = 1433,
     FOR_UPDATE = 1434,
     LOCK_TABLE = 1439,
     NOT_EXISTS = 1441,
     REFERENCES = 1443,
     RENCOL = 1444,
     SMALLFLOAT = 1446,
     COMMIT_W = 1457,
     RENTAB = 1464,
     KW_CHAR = 1467,
     NCHAR = 1468,
     NVARCHAR = 1469,
     DELIMITER = 1471,
     DROP_VIEW = 1473,
     EXCLUSIVE = 1476,
     GREATER_THAN_EQ = 1480,
     INTO_TEMP = 1482,
     DATABASE = 1506,
     DATETIME = 1507,
     DISTINCT = 1509,
     FRACTION = 1516,
     GROUP_BY = 1518,
     INTERVAL = 1519,
     NOT_LIKE = 1521,
     NOT_ILIKE = 1522,
     NOT_NULL = 1523,
     RESOURCE = 1529,
     SMALLINT = 1530,
     IS_NULL = 1536,
     LESS_THAN_EQ = 1537,
     BETWEEN = 1539,
     CLOSE_BRACKET = 1542,
     CONNECT = 1545,
     KW_CURRENT = 1546,
     KW_DECIMAL = 1548,
     KW_DEFAULT = 1550,
     INTEGER = 1558,
     SERIAL8 = 1560,
     MATCHES = 1563,
     VARCHAR = 1576,
     CLOSE_SQUARE = 1579,
     GREATER_THAN = 1580,
     KW_FALSE = 1581,
     NOT_IN = 1582,
     OPEN_BRACKET_SELECT = 1584,
     OPEN_BRACKET = 1585,
     KW_DELETE = 1593,
     KW_ESCAPE = 1596,
     EXISTS = 1597,
     EXTEND = 1598,
     HAVING = 1602,
     KW_INSERT = 1604,
     MINUTE = 1608,
     MODIFY = 1609,
     EQUAL = 1611,
     NOT_EQUAL = 1612,
     OPEN_SQUARE = 1614,
     PUBLIC = 1618,
     KW_RETURN_KEY = 1621,
     REVOKE = 1623,
     SECOND = 1627,
     KW_SELECT = 1631,
     SERIAL = 1632,
     UNIQUE = 1635,
     KW_UPDATE = 1637,
     VALUES = 1638,
     KW_NULL = 1641,
     KW_TRUE = 1642,
     ALTER = 1644,
     CHECK = 1650,
     COUNT = 1654,
     KW_FIRST = 1659,
     KW_FLOAT = 1660,
     GRANT = 1663,
     INDEX = 1666,
     LESS_THAN = 1669,
     MONEY = 1671,
     MONTH = 1672,
     KW_MULTIPLY = 1674,
     ORDER = 1675,
     OUTER = 1676,
     UNION = 1685,
     WHERE = 1688,
     KW_BYTE = 1695,
     CASE = 1697,
     KW_DATE = 1699,
     DESC = 1700,
     KW_DIVIDE = 1701,
     DROP = 1704,
     ELSE = 1705,
     FROM = 1709,
     HOUR = 1715,
     INTO = 1716,
     LIKE = 1719,
     REAL = 1728,
     SOME = 1733,
     KW_TEXT = 1737,
     KW_THEN = 1738,
     USER = 1739,
     WHEN = 1741,
     YEAR = 1744,
     KW_DOW = 1745,
     XSET = 1747,
     ADD = 1748,
     ALL = 1749,
     KW_AND = 1750,
     ANY = 1751,
     ASC = 1752,
     AVG = 1753,
     COLON = 1754,
     KW_COMMA = 1755,
     DAY = 1756,
     DBA = 1757,
     KW_FOR = 1761,
     XMAX = 1766,
     XMIN = 1767,
     KW_MINUS = 1768,
     KW_MOD = 1769,
     KW_NOT = 1770,
     KW_SUM = 1777,
     ATSIGN = 1780,
     KW_PLUS = 1781,
     KW_AS = 1787,
     KW_BY = 1789,
     KW_DOT = 1790,
     KW_IN = 1793,
     KW_ON = 1795,
     KW_OR = 1796,
     KW_TO = 1797,
     BEFORE = 1835,
     END = 1839,
     TILDE = 1846,
     ILIKE = 1847,
     FILLFACTOR = 1850,
     TIME = 1855,
     KW_TODAY = 1862,
     KW_ROWID = 1863,
     TIMESTAMP = 2211,
     KWPIPE = 2241
   };
#endif
/* Tokens.  */
#define INT_VALUE 2243
#define NAMED 2244
#define NAMED_GEN 2245
#define CHAR_VALUE 2246
#define NOT_USED_1 2247
#define NOT_USED_2 2248
#define NOT_USED_3 2249
#define NOT_USED_4 2250
#define NOT_USED_5 2251
#define NOT_USED_6 2252
#define NOT_USED_7 2253
#define NOT_USED_8 2254
#define NUMBER_VALUE 2255
#define SEMICOLON 2256
#define QUESTION_MARK 2257
#define CLINE 2258
#define CH 2259
#define MARK_VAR 2260
#define END_MARK_VAR 2261
#define WITH_LISTING_IN 1001
#define SET_POSTGRESQL_SEARCH_PATH 1002
#define SET_CONSTRAINTS_ALL_DEFERRED 1003
#define KW_LIMIT 1004
#define DOCUMENT 1005
#define ON_EXCEPTION 1007
#define SET_DEBUG_FILE_TO 1008
#define CREATE_DBA_PROCEDURE 1013
#define CREATE_FUNCTION 1014
#define CREATE_DBA_FUNCTION 1015
#define USE_SESSION 1017
#define KW_RUN_CLIENT 1018
#define LEFT_JOIN 1020
#define IGNORE_ERRORS 1023
#define SQLERRMESSAGE 1024
#define DISPLAY_NULL_TO 1025
#define UNBUFFERED 1026
#define KW_PICTURE 1027
#define ON_CHANGE 1028
#define INNER_JOIN 1029
#define UI_INTERFACE_DOT_FRONTCALL 1032
#define UICOMBOBOX 1036
#define UIFORM 1039
#define USING_BTREE 1055
#define USING_RTREE 1056
#define SET_BUFFERED_LOG 1075
#define SET_LOG 1078
#define MDY 1080
#define WEEKDAY 1081
#define MODE_ANSI 1084
#define START_DATABASE 1085
#define WITH_LOG_IN 1086
#define SET_CONSTRAINTS_ALL_IMMEDIATE 1087
#define DATETIME_VALUE 1100
#define INTERVAL_VALUE 1101
#define RECOVER_TABLE 1102
#define ROLLFORWARD_DATABASE 1103
#define CONCAT_PIPES 1117
#define DROP_TRIGGER 1119
#define DROP_AUDIT_FOR 1120
#define CREATE_AUDIT_FOR 1121
#define EXECUTE_PROCEDURE 1125
#define ALTER_TABLE 1132
#define ALTER_INDEX 1133
#define NEXT_SIZE 1134
#define KW_WHENEVER_SIGNAL 1171
#define KW_SIGNAL_TOKEN 1172
#define XSET_MULTIPLY_EQUAL_OPEN_BRACKET 1173
#define XSET_ident_DOT_MULTIPLY_EQUAL_OPEN_BRACKET 1174
#define XSET_ident_DOT_MULTIPLY_EQUAL 1175
#define XSET_MULTIPLY_EQUAL 1176
#define XSET_OPEN_BRACKET 1177
#define CREATE_DATABASE 1180
#define DROP_DATABASE 1181
#define ADD_CONSTRAINT 1183
#define DROP_CONSTRAINT 1184
#define DROP_SYNONYM 1185
#define CONSTRAINT 1186
#define NOT_FIELD_TOUCHED_CURRENT 1189
#define FIELD_TOUCHED_CURRENT 1190
#define OBJECT_FUNCTION 1192
#define DOUBLE_PRECISION 1198
#define COUNT_MULTIPLY 1199
#define KW_ASCII_OPEN_BRACKET 1208
#define MODIFY_NEXT_SIZE 1220
#define LOCK_MODE_PAGE 1221
#define LOCK_MODE_ROW 1222
#define TO_UI 1227
#define UNITS_YEAR 1230
#define UNITS_MONTH 1231
#define UNITS_DAY 1232
#define UNITS_HOUR 1233
#define UNITS_MINUTE 1234
#define UNITS_SECOND 1235
#define TO_CLUSTER 1240
#define TO_NOT_CLUSTER 1241
#define CREATE_UC_IDX 1243
#define CREATE_U_IDX 1244
#define CREATE_C_IDX 1245
#define CREATE_IDX 1246
#define DOUBLE_COLON 1256
#define SQLSICS 1262
#define CREATE_SCHEMA 1263
#define SQLSIRR 1264
#define UPDATESTATS_T 1265
#define SQLSICR 1266
#define SQLSIDR 1277
#define CREATE_TEMP_TABLE 1278
#define WITH_CHECK_OPTION 1286
#define WITH_GRANT_OPTION 1287
#define SQLSLMNW 1288
#define WHERE_CURRENT_OF 1294
#define NOT_NULL_UNIQUE 1302
#define SQLSLMW 1309
#define ALL_PRIVILEGES 1311
#define CREATE_SYNONYM 1315
#define DROP_TABLE 1316
#define INEXCLUSIVE 1318
#define REPORT_TO_UI 1319
#define UPDATESTATS 1324
#define CREATE_TABLE 1350
#define DEFAULT_NULL 1351
#define DEFAULT_TODAY 1352
#define DEFAULT_USER 1353
#define EXIT_TODO 1360
#define CONTINUE_TODO 1361
#define UNLOCK_TABLE 1368
#define ROLLBACK_W 1376
#define SQLSEON 1378
#define SQLSEOFF 1379
#define CREATE_VIEW 1383
#define DELETE_FROM 1384
#define EXTENT_SIZE 1391
#define FOREIGN_KEY 1392
#define INSERT_INTO 1395
#define IS_NOT_NULL 1397
#define NOT_MATCHES 1400
#define PRIMARY_KEY 1406
#define WITH_NO_LOG 1413
#define INSHARE 1416
#define BEGIN_WORK 1422
#define DROP_INDEX 1427
#define FOR_UPDATE_OF 1433
#define FOR_UPDATE 1434
#define LOCK_TABLE 1439
#define NOT_EXISTS 1441
#define REFERENCES 1443
#define RENCOL 1444
#define SMALLFLOAT 1446
#define COMMIT_W 1457
#define RENTAB 1464
#define KW_CHAR 1467
#define NCHAR 1468
#define NVARCHAR 1469
#define DELIMITER 1471
#define DROP_VIEW 1473
#define EXCLUSIVE 1476
#define GREATER_THAN_EQ 1480
#define INTO_TEMP 1482
#define DATABASE 1506
#define DATETIME 1507
#define DISTINCT 1509
#define FRACTION 1516
#define GROUP_BY 1518
#define INTERVAL 1519
#define NOT_LIKE 1521
#define NOT_ILIKE 1522
#define NOT_NULL 1523
#define RESOURCE 1529
#define SMALLINT 1530
#define IS_NULL 1536
#define LESS_THAN_EQ 1537
#define BETWEEN 1539
#define CLOSE_BRACKET 1542
#define CONNECT 1545
#define KW_CURRENT 1546
#define KW_DECIMAL 1548
#define KW_DEFAULT 1550
#define INTEGER 1558
#define SERIAL8 1560
#define MATCHES 1563
#define VARCHAR 1576
#define CLOSE_SQUARE 1579
#define GREATER_THAN 1580
#define KW_FALSE 1581
#define NOT_IN 1582
#define OPEN_BRACKET_SELECT 1584
#define OPEN_BRACKET 1585
#define KW_DELETE 1593
#define KW_ESCAPE 1596
#define EXISTS 1597
#define EXTEND 1598
#define HAVING 1602
#define KW_INSERT 1604
#define MINUTE 1608
#define MODIFY 1609
#define EQUAL 1611
#define NOT_EQUAL 1612
#define OPEN_SQUARE 1614
#define PUBLIC 1618
#define KW_RETURN_KEY 1621
#define REVOKE 1623
#define SECOND 1627
#define KW_SELECT 1631
#define SERIAL 1632
#define UNIQUE 1635
#define KW_UPDATE 1637
#define VALUES 1638
#define KW_NULL 1641
#define KW_TRUE 1642
#define ALTER 1644
#define CHECK 1650
#define COUNT 1654
#define KW_FIRST 1659
#define KW_FLOAT 1660
#define GRANT 1663
#define INDEX 1666
#define LESS_THAN 1669
#define MONEY 1671
#define MONTH 1672
#define KW_MULTIPLY 1674
#define ORDER 1675
#define OUTER 1676
#define UNION 1685
#define WHERE 1688
#define KW_BYTE 1695
#define CASE 1697
#define KW_DATE 1699
#define DESC 1700
#define KW_DIVIDE 1701
#define DROP 1704
#define ELSE 1705
#define FROM 1709
#define HOUR 1715
#define INTO 1716
#define LIKE 1719
#define REAL 1728
#define SOME 1733
#define KW_TEXT 1737
#define KW_THEN 1738
#define USER 1739
#define WHEN 1741
#define YEAR 1744
#define KW_DOW 1745
#define XSET 1747
#define ADD 1748
#define ALL 1749
#define KW_AND 1750
#define ANY 1751
#define ASC 1752
#define AVG 1753
#define COLON 1754
#define KW_COMMA 1755
#define DAY 1756
#define DBA 1757
#define KW_FOR 1761
#define XMAX 1766
#define XMIN 1767
#define KW_MINUS 1768
#define KW_MOD 1769
#define KW_NOT 1770
#define KW_SUM 1777
#define ATSIGN 1780
#define KW_PLUS 1781
#define KW_AS 1787
#define KW_BY 1789
#define KW_DOT 1790
#define KW_IN 1793
#define KW_ON 1795
#define KW_OR 1796
#define KW_TO 1797
#define BEFORE 1835
#define END 1839
#define TILDE 1846
#define ILIKE 1847
#define FILLFACTOR 1850
#define TIME 1855
#define KW_TODAY 1862
#define KW_ROWID 1863
#define TIMESTAMP 2211
#define KWPIPE 2241




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
#line 640 "y.tab.h"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE sqlparse_yylval;


