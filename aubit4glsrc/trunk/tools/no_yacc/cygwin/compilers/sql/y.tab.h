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
     INT_VALUE = 2248,
     NAMED = 2249,
     NAMED_GEN = 2250,
     CHAR_VALUE = 2251,
     NOT_USED_1 = 2252,
     NOT_USED_2 = 2253,
     NOT_USED_3 = 2254,
     NOT_USED_4 = 2255,
     NOT_USED_5 = 2256,
     NOT_USED_6 = 2257,
     NOT_USED_7 = 2258,
     NOT_USED_8 = 2259,
     NUMBER_VALUE = 2260,
     SEMICOLON = 2261,
     QUESTION_MARK = 2262,
     CLINE = 2263,
     CH = 2264,
     MARK_VAR = 2265,
     END_MARK_VAR = 2266,
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
     UIBROWSER = 1037,
     UIPROGRESS = 1038,
     UIGANTT = 1039,
     UIFORM = 1042,
     USING_BTREE = 1058,
     USING_RTREE = 1059,
     SET_BUFFERED_LOG = 1078,
     SET_LOG = 1081,
     MDY = 1083,
     WEEKDAY = 1084,
     MODE_ANSI = 1087,
     START_DATABASE = 1088,
     WITH_LOG_IN = 1089,
     SET_CONSTRAINTS_ALL_IMMEDIATE = 1090,
     DATETIME_VALUE = 1103,
     INTERVAL_VALUE = 1104,
     RECOVER_TABLE = 1105,
     ROLLFORWARD_DATABASE = 1106,
     CONCAT_PIPES = 1120,
     DROP_TRIGGER = 1122,
     DROP_AUDIT_FOR = 1123,
     CREATE_AUDIT_FOR = 1124,
     EXECUTE_PROCEDURE = 1128,
     ALTER_TABLE = 1135,
     ALTER_INDEX = 1136,
     NEXT_SIZE = 1137,
     KW_WHENEVER_SIGNAL = 1174,
     KW_SIGNAL_TOKEN = 1175,
     XSET_MULTIPLY_EQUAL_OPEN_BRACKET = 1176,
     XSET_ident_DOT_MULTIPLY_EQUAL_OPEN_BRACKET = 1177,
     XSET_ident_DOT_MULTIPLY_EQUAL = 1178,
     XSET_MULTIPLY_EQUAL = 1179,
     XSET_OPEN_BRACKET = 1180,
     CREATE_DATABASE = 1183,
     DROP_DATABASE = 1184,
     ADD_CONSTRAINT = 1186,
     DROP_CONSTRAINT = 1187,
     DROP_SYNONYM = 1188,
     CONSTRAINT = 1189,
     NOT_FIELD_TOUCHED_CURRENT = 1192,
     FIELD_TOUCHED_CURRENT = 1193,
     OBJECT_FUNCTION = 1195,
     DOUBLE_PRECISION = 1201,
     COUNT_MULTIPLY = 1202,
     KW_ASCII_OPEN_BRACKET = 1211,
     MODIFY_NEXT_SIZE = 1223,
     LOCK_MODE_PAGE = 1224,
     LOCK_MODE_ROW = 1225,
     TO_UI = 1230,
     UNITS_YEAR = 1233,
     UNITS_MONTH = 1234,
     UNITS_DAY = 1235,
     UNITS_HOUR = 1236,
     UNITS_MINUTE = 1237,
     UNITS_SECOND = 1238,
     TO_CLUSTER = 1243,
     TO_NOT_CLUSTER = 1244,
     CREATE_UC_IDX = 1246,
     CREATE_U_IDX = 1247,
     CREATE_C_IDX = 1248,
     CREATE_IDX = 1249,
     DOUBLE_COLON = 1259,
     SQLSICS = 1265,
     CREATE_SCHEMA = 1266,
     SQLSIRR = 1267,
     UPDATESTATS_T = 1268,
     SQLSICR = 1269,
     SQLSIDR = 1280,
     CREATE_TEMP_TABLE = 1281,
     WITH_CHECK_OPTION = 1289,
     WITH_GRANT_OPTION = 1290,
     SQLSLMNW = 1291,
     WHERE_CURRENT_OF = 1297,
     NOT_NULL_UNIQUE = 1305,
     SQLSLMW = 1312,
     ALL_PRIVILEGES = 1314,
     CREATE_SYNONYM = 1318,
     DROP_TABLE = 1319,
     INEXCLUSIVE = 1321,
     REPORT_TO_FILE = 1322,
     REPORT_TO_UI = 1323,
     UPDATESTATS = 1328,
     CREATE_TABLE = 1354,
     DEFAULT_NULL = 1355,
     DEFAULT_TODAY = 1356,
     DEFAULT_USER = 1357,
     EXIT_TODO = 1364,
     CONTINUE_TODO = 1365,
     UNLOCK_TABLE = 1372,
     ROLLBACK_W = 1380,
     SQLSEON = 1382,
     SQLSEOFF = 1383,
     CREATE_VIEW = 1387,
     DELETE_FROM = 1388,
     EXTENT_SIZE = 1395,
     FOREIGN_KEY = 1396,
     INSERT_INTO = 1399,
     IS_NOT_NULL = 1401,
     NOT_MATCHES = 1404,
     PRIMARY_KEY = 1410,
     WITH_NO_LOG = 1417,
     INSHARE = 1420,
     BEGIN_WORK = 1426,
     DROP_INDEX = 1431,
     FOR_UPDATE_OF = 1437,
     FOR_UPDATE = 1438,
     LOCK_TABLE = 1443,
     NOT_EXISTS = 1445,
     REFERENCES = 1447,
     RENCOL = 1448,
     SMALLFLOAT = 1450,
     COMMIT_W = 1461,
     RENTAB = 1468,
     KW_CHAR = 1471,
     NCHAR = 1472,
     NVARCHAR = 1473,
     DELIMITER = 1475,
     DROP_VIEW = 1477,
     EXCLUSIVE = 1480,
     GREATER_THAN_EQ = 1484,
     INTO_TEMP = 1486,
     DATABASE = 1510,
     DATETIME = 1511,
     DISTINCT = 1513,
     FRACTION = 1520,
     GROUP_BY = 1522,
     INTERVAL = 1523,
     NOT_LIKE = 1525,
     NOT_ILIKE = 1526,
     NOT_NULL = 1527,
     RESOURCE = 1533,
     SMALLINT = 1534,
     IS_NULL = 1540,
     LESS_THAN_EQ = 1541,
     BETWEEN = 1543,
     CLOSE_BRACKET = 1546,
     CONNECT = 1549,
     KW_CURRENT = 1550,
     KW_DECIMAL = 1552,
     KW_DEFAULT = 1554,
     FGL_SYNCFIELDS = 1562,
     INTEGER = 1563,
     SERIAL8 = 1565,
     MATCHES = 1568,
     VARCHAR = 1581,
     CLOSE_SQUARE = 1584,
     GREATER_THAN = 1585,
     KW_FALSE = 1586,
     NOT_IN = 1587,
     OPEN_BRACKET_SELECT = 1589,
     OPEN_BRACKET = 1590,
     KW_DELETE = 1598,
     KW_ESCAPE = 1601,
     EXISTS = 1602,
     EXTEND = 1603,
     HAVING = 1607,
     KW_INSERT = 1609,
     MINUTE = 1613,
     MODIFY = 1614,
     EQUAL = 1616,
     NOT_EQUAL = 1617,
     OPEN_SQUARE = 1619,
     PUBLIC = 1623,
     KW_RETURN_KEY = 1626,
     REVOKE = 1628,
     SECOND = 1632,
     KW_SELECT = 1636,
     SERIAL = 1637,
     UNIQUE = 1640,
     KW_UPDATE = 1642,
     VALUES = 1643,
     KW_NULL = 1646,
     KW_TRUE = 1647,
     ALTER = 1649,
     CHECK = 1655,
     COUNT = 1659,
     KW_FIRST = 1664,
     KW_FLOAT = 1665,
     GRANT = 1668,
     INDEX = 1671,
     LESS_THAN = 1674,
     MONEY = 1676,
     MONTH = 1677,
     KW_MULTIPLY = 1679,
     ORDER = 1680,
     OUTER = 1681,
     UNION = 1690,
     WHERE = 1693,
     KW_BYTE = 1700,
     CASE = 1702,
     KW_DATE = 1704,
     DESC = 1705,
     KW_DIVIDE = 1706,
     DROP = 1709,
     ELSE = 1710,
     FROM = 1714,
     HOUR = 1720,
     INTO = 1721,
     LIKE = 1724,
     REAL = 1733,
     SOME = 1738,
     KW_TEXT = 1742,
     KW_THEN = 1743,
     USER = 1744,
     WHEN = 1746,
     YEAR = 1749,
     KW_DOW = 1750,
     XSET = 1752,
     ADD = 1753,
     ALL = 1754,
     KW_AND = 1755,
     ANY = 1756,
     ASC = 1757,
     AVG = 1758,
     COLON = 1759,
     KW_COMMA = 1760,
     DAY = 1761,
     DBA = 1762,
     KW_FOR = 1766,
     XMAX = 1771,
     XMIN = 1772,
     KW_MINUS = 1773,
     KW_MOD = 1774,
     KW_NOT = 1775,
     KW_SUM = 1782,
     ATSIGN = 1785,
     KW_PLUS = 1786,
     KW_AS = 1792,
     KW_BY = 1794,
     KW_DOT = 1795,
     KW_IN = 1798,
     KW_ON = 1800,
     KW_OR = 1801,
     KW_TO = 1802,
     BEFORE = 1840,
     END = 1844,
     TILDE = 1851,
     ILIKE = 1852,
     FILLFACTOR = 1855,
     TIME = 1860,
     KW_TODAY = 1867,
     KW_ROWID = 1868,
     TIMESTAMP = 2216,
     KWPIPE = 2246
   };
#endif
/* Tokens.  */
#define INT_VALUE 2248
#define NAMED 2249
#define NAMED_GEN 2250
#define CHAR_VALUE 2251
#define NOT_USED_1 2252
#define NOT_USED_2 2253
#define NOT_USED_3 2254
#define NOT_USED_4 2255
#define NOT_USED_5 2256
#define NOT_USED_6 2257
#define NOT_USED_7 2258
#define NOT_USED_8 2259
#define NUMBER_VALUE 2260
#define SEMICOLON 2261
#define QUESTION_MARK 2262
#define CLINE 2263
#define CH 2264
#define MARK_VAR 2265
#define END_MARK_VAR 2266
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
#define UIBROWSER 1037
#define UIPROGRESS 1038
#define UIGANTT 1039
#define UIFORM 1042
#define USING_BTREE 1058
#define USING_RTREE 1059
#define SET_BUFFERED_LOG 1078
#define SET_LOG 1081
#define MDY 1083
#define WEEKDAY 1084
#define MODE_ANSI 1087
#define START_DATABASE 1088
#define WITH_LOG_IN 1089
#define SET_CONSTRAINTS_ALL_IMMEDIATE 1090
#define DATETIME_VALUE 1103
#define INTERVAL_VALUE 1104
#define RECOVER_TABLE 1105
#define ROLLFORWARD_DATABASE 1106
#define CONCAT_PIPES 1120
#define DROP_TRIGGER 1122
#define DROP_AUDIT_FOR 1123
#define CREATE_AUDIT_FOR 1124
#define EXECUTE_PROCEDURE 1128
#define ALTER_TABLE 1135
#define ALTER_INDEX 1136
#define NEXT_SIZE 1137
#define KW_WHENEVER_SIGNAL 1174
#define KW_SIGNAL_TOKEN 1175
#define XSET_MULTIPLY_EQUAL_OPEN_BRACKET 1176
#define XSET_ident_DOT_MULTIPLY_EQUAL_OPEN_BRACKET 1177
#define XSET_ident_DOT_MULTIPLY_EQUAL 1178
#define XSET_MULTIPLY_EQUAL 1179
#define XSET_OPEN_BRACKET 1180
#define CREATE_DATABASE 1183
#define DROP_DATABASE 1184
#define ADD_CONSTRAINT 1186
#define DROP_CONSTRAINT 1187
#define DROP_SYNONYM 1188
#define CONSTRAINT 1189
#define NOT_FIELD_TOUCHED_CURRENT 1192
#define FIELD_TOUCHED_CURRENT 1193
#define OBJECT_FUNCTION 1195
#define DOUBLE_PRECISION 1201
#define COUNT_MULTIPLY 1202
#define KW_ASCII_OPEN_BRACKET 1211
#define MODIFY_NEXT_SIZE 1223
#define LOCK_MODE_PAGE 1224
#define LOCK_MODE_ROW 1225
#define TO_UI 1230
#define UNITS_YEAR 1233
#define UNITS_MONTH 1234
#define UNITS_DAY 1235
#define UNITS_HOUR 1236
#define UNITS_MINUTE 1237
#define UNITS_SECOND 1238
#define TO_CLUSTER 1243
#define TO_NOT_CLUSTER 1244
#define CREATE_UC_IDX 1246
#define CREATE_U_IDX 1247
#define CREATE_C_IDX 1248
#define CREATE_IDX 1249
#define DOUBLE_COLON 1259
#define SQLSICS 1265
#define CREATE_SCHEMA 1266
#define SQLSIRR 1267
#define UPDATESTATS_T 1268
#define SQLSICR 1269
#define SQLSIDR 1280
#define CREATE_TEMP_TABLE 1281
#define WITH_CHECK_OPTION 1289
#define WITH_GRANT_OPTION 1290
#define SQLSLMNW 1291
#define WHERE_CURRENT_OF 1297
#define NOT_NULL_UNIQUE 1305
#define SQLSLMW 1312
#define ALL_PRIVILEGES 1314
#define CREATE_SYNONYM 1318
#define DROP_TABLE 1319
#define INEXCLUSIVE 1321
#define REPORT_TO_FILE 1322
#define REPORT_TO_UI 1323
#define UPDATESTATS 1328
#define CREATE_TABLE 1354
#define DEFAULT_NULL 1355
#define DEFAULT_TODAY 1356
#define DEFAULT_USER 1357
#define EXIT_TODO 1364
#define CONTINUE_TODO 1365
#define UNLOCK_TABLE 1372
#define ROLLBACK_W 1380
#define SQLSEON 1382
#define SQLSEOFF 1383
#define CREATE_VIEW 1387
#define DELETE_FROM 1388
#define EXTENT_SIZE 1395
#define FOREIGN_KEY 1396
#define INSERT_INTO 1399
#define IS_NOT_NULL 1401
#define NOT_MATCHES 1404
#define PRIMARY_KEY 1410
#define WITH_NO_LOG 1417
#define INSHARE 1420
#define BEGIN_WORK 1426
#define DROP_INDEX 1431
#define FOR_UPDATE_OF 1437
#define FOR_UPDATE 1438
#define LOCK_TABLE 1443
#define NOT_EXISTS 1445
#define REFERENCES 1447
#define RENCOL 1448
#define SMALLFLOAT 1450
#define COMMIT_W 1461
#define RENTAB 1468
#define KW_CHAR 1471
#define NCHAR 1472
#define NVARCHAR 1473
#define DELIMITER 1475
#define DROP_VIEW 1477
#define EXCLUSIVE 1480
#define GREATER_THAN_EQ 1484
#define INTO_TEMP 1486
#define DATABASE 1510
#define DATETIME 1511
#define DISTINCT 1513
#define FRACTION 1520
#define GROUP_BY 1522
#define INTERVAL 1523
#define NOT_LIKE 1525
#define NOT_ILIKE 1526
#define NOT_NULL 1527
#define RESOURCE 1533
#define SMALLINT 1534
#define IS_NULL 1540
#define LESS_THAN_EQ 1541
#define BETWEEN 1543
#define CLOSE_BRACKET 1546
#define CONNECT 1549
#define KW_CURRENT 1550
#define KW_DECIMAL 1552
#define KW_DEFAULT 1554
#define FGL_SYNCFIELDS 1562
#define INTEGER 1563
#define SERIAL8 1565
#define MATCHES 1568
#define VARCHAR 1581
#define CLOSE_SQUARE 1584
#define GREATER_THAN 1585
#define KW_FALSE 1586
#define NOT_IN 1587
#define OPEN_BRACKET_SELECT 1589
#define OPEN_BRACKET 1590
#define KW_DELETE 1598
#define KW_ESCAPE 1601
#define EXISTS 1602
#define EXTEND 1603
#define HAVING 1607
#define KW_INSERT 1609
#define MINUTE 1613
#define MODIFY 1614
#define EQUAL 1616
#define NOT_EQUAL 1617
#define OPEN_SQUARE 1619
#define PUBLIC 1623
#define KW_RETURN_KEY 1626
#define REVOKE 1628
#define SECOND 1632
#define KW_SELECT 1636
#define SERIAL 1637
#define UNIQUE 1640
#define KW_UPDATE 1642
#define VALUES 1643
#define KW_NULL 1646
#define KW_TRUE 1647
#define ALTER 1649
#define CHECK 1655
#define COUNT 1659
#define KW_FIRST 1664
#define KW_FLOAT 1665
#define GRANT 1668
#define INDEX 1671
#define LESS_THAN 1674
#define MONEY 1676
#define MONTH 1677
#define KW_MULTIPLY 1679
#define ORDER 1680
#define OUTER 1681
#define UNION 1690
#define WHERE 1693
#define KW_BYTE 1700
#define CASE 1702
#define KW_DATE 1704
#define DESC 1705
#define KW_DIVIDE 1706
#define DROP 1709
#define ELSE 1710
#define FROM 1714
#define HOUR 1720
#define INTO 1721
#define LIKE 1724
#define REAL 1733
#define SOME 1738
#define KW_TEXT 1742
#define KW_THEN 1743
#define USER 1744
#define WHEN 1746
#define YEAR 1749
#define KW_DOW 1750
#define XSET 1752
#define ADD 1753
#define ALL 1754
#define KW_AND 1755
#define ANY 1756
#define ASC 1757
#define AVG 1758
#define COLON 1759
#define KW_COMMA 1760
#define DAY 1761
#define DBA 1762
#define KW_FOR 1766
#define XMAX 1771
#define XMIN 1772
#define KW_MINUS 1773
#define KW_MOD 1774
#define KW_NOT 1775
#define KW_SUM 1782
#define ATSIGN 1785
#define KW_PLUS 1786
#define KW_AS 1792
#define KW_BY 1794
#define KW_DOT 1795
#define KW_IN 1798
#define KW_ON 1800
#define KW_OR 1801
#define KW_TO 1802
#define BEFORE 1840
#define END 1844
#define TILDE 1851
#define ILIKE 1852
#define FILLFACTOR 1855
#define TIME 1860
#define KW_TODAY 1867
#define KW_ROWID 1868
#define TIMESTAMP 2216
#define KWPIPE 2246




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
#line 650 "y.tab.h"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE sqlparse_yylval;


