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
     INT_VALUE = 2244,
     NAMED = 2245,
     NAMED_GEN = 2246,
     CHAR_VALUE = 2247,
     NOT_USED_1 = 2248,
     NOT_USED_2 = 2249,
     NOT_USED_3 = 2250,
     NOT_USED_4 = 2251,
     NOT_USED_5 = 2252,
     NOT_USED_6 = 2253,
     NOT_USED_7 = 2254,
     NOT_USED_8 = 2255,
     NUMBER_VALUE = 2256,
     SEMICOLON = 2257,
     QUESTION_MARK = 2258,
     CLINE = 2259,
     CH = 2260,
     MARK_VAR = 2261,
     END_MARK_VAR = 2262,
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
     REPORT_TO_FILE = 1319,
     REPORT_TO_UI = 1320,
     UPDATESTATS = 1325,
     CREATE_TABLE = 1351,
     DEFAULT_NULL = 1352,
     DEFAULT_TODAY = 1353,
     DEFAULT_USER = 1354,
     EXIT_TODO = 1361,
     CONTINUE_TODO = 1362,
     UNLOCK_TABLE = 1369,
     ROLLBACK_W = 1377,
     SQLSEON = 1379,
     SQLSEOFF = 1380,
     CREATE_VIEW = 1384,
     DELETE_FROM = 1385,
     EXTENT_SIZE = 1392,
     FOREIGN_KEY = 1393,
     INSERT_INTO = 1396,
     IS_NOT_NULL = 1398,
     NOT_MATCHES = 1401,
     PRIMARY_KEY = 1407,
     WITH_NO_LOG = 1414,
     INSHARE = 1417,
     BEGIN_WORK = 1423,
     DROP_INDEX = 1428,
     FOR_UPDATE_OF = 1434,
     FOR_UPDATE = 1435,
     LOCK_TABLE = 1440,
     NOT_EXISTS = 1442,
     REFERENCES = 1444,
     RENCOL = 1445,
     SMALLFLOAT = 1447,
     COMMIT_W = 1458,
     RENTAB = 1465,
     KW_CHAR = 1468,
     NCHAR = 1469,
     NVARCHAR = 1470,
     DELIMITER = 1472,
     DROP_VIEW = 1474,
     EXCLUSIVE = 1477,
     GREATER_THAN_EQ = 1481,
     INTO_TEMP = 1483,
     DATABASE = 1507,
     DATETIME = 1508,
     DISTINCT = 1510,
     FRACTION = 1517,
     GROUP_BY = 1519,
     INTERVAL = 1520,
     NOT_LIKE = 1522,
     NOT_ILIKE = 1523,
     NOT_NULL = 1524,
     RESOURCE = 1530,
     SMALLINT = 1531,
     IS_NULL = 1537,
     LESS_THAN_EQ = 1538,
     BETWEEN = 1540,
     CLOSE_BRACKET = 1543,
     CONNECT = 1546,
     KW_CURRENT = 1547,
     KW_DECIMAL = 1549,
     KW_DEFAULT = 1551,
     INTEGER = 1559,
     SERIAL8 = 1561,
     MATCHES = 1564,
     VARCHAR = 1577,
     CLOSE_SQUARE = 1580,
     GREATER_THAN = 1581,
     KW_FALSE = 1582,
     NOT_IN = 1583,
     OPEN_BRACKET_SELECT = 1585,
     OPEN_BRACKET = 1586,
     KW_DELETE = 1594,
     KW_ESCAPE = 1597,
     EXISTS = 1598,
     EXTEND = 1599,
     HAVING = 1603,
     KW_INSERT = 1605,
     MINUTE = 1609,
     MODIFY = 1610,
     EQUAL = 1612,
     NOT_EQUAL = 1613,
     OPEN_SQUARE = 1615,
     PUBLIC = 1619,
     KW_RETURN_KEY = 1622,
     REVOKE = 1624,
     SECOND = 1628,
     KW_SELECT = 1632,
     SERIAL = 1633,
     UNIQUE = 1636,
     KW_UPDATE = 1638,
     VALUES = 1639,
     KW_NULL = 1642,
     KW_TRUE = 1643,
     ALTER = 1645,
     CHECK = 1651,
     COUNT = 1655,
     KW_FIRST = 1660,
     KW_FLOAT = 1661,
     GRANT = 1664,
     INDEX = 1667,
     LESS_THAN = 1670,
     MONEY = 1672,
     MONTH = 1673,
     KW_MULTIPLY = 1675,
     ORDER = 1676,
     OUTER = 1677,
     UNION = 1686,
     WHERE = 1689,
     KW_BYTE = 1696,
     CASE = 1698,
     KW_DATE = 1700,
     DESC = 1701,
     KW_DIVIDE = 1702,
     DROP = 1705,
     ELSE = 1706,
     FROM = 1710,
     HOUR = 1716,
     INTO = 1717,
     LIKE = 1720,
     REAL = 1729,
     SOME = 1734,
     KW_TEXT = 1738,
     KW_THEN = 1739,
     USER = 1740,
     WHEN = 1742,
     YEAR = 1745,
     KW_DOW = 1746,
     XSET = 1748,
     ADD = 1749,
     ALL = 1750,
     KW_AND = 1751,
     ANY = 1752,
     ASC = 1753,
     AVG = 1754,
     COLON = 1755,
     KW_COMMA = 1756,
     DAY = 1757,
     DBA = 1758,
     KW_FOR = 1762,
     XMAX = 1767,
     XMIN = 1768,
     KW_MINUS = 1769,
     KW_MOD = 1770,
     KW_NOT = 1771,
     KW_SUM = 1778,
     ATSIGN = 1781,
     KW_PLUS = 1782,
     KW_AS = 1788,
     KW_BY = 1790,
     KW_DOT = 1791,
     KW_IN = 1794,
     KW_ON = 1796,
     KW_OR = 1797,
     KW_TO = 1798,
     BEFORE = 1836,
     END = 1840,
     TILDE = 1847,
     ILIKE = 1848,
     FILLFACTOR = 1851,
     TIME = 1856,
     KW_TODAY = 1863,
     KW_ROWID = 1864,
     TIMESTAMP = 2212,
     KWPIPE = 2242
   };
#endif
/* Tokens.  */
#define INT_VALUE 2244
#define NAMED 2245
#define NAMED_GEN 2246
#define CHAR_VALUE 2247
#define NOT_USED_1 2248
#define NOT_USED_2 2249
#define NOT_USED_3 2250
#define NOT_USED_4 2251
#define NOT_USED_5 2252
#define NOT_USED_6 2253
#define NOT_USED_7 2254
#define NOT_USED_8 2255
#define NUMBER_VALUE 2256
#define SEMICOLON 2257
#define QUESTION_MARK 2258
#define CLINE 2259
#define CH 2260
#define MARK_VAR 2261
#define END_MARK_VAR 2262
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
#define REPORT_TO_FILE 1319
#define REPORT_TO_UI 1320
#define UPDATESTATS 1325
#define CREATE_TABLE 1351
#define DEFAULT_NULL 1352
#define DEFAULT_TODAY 1353
#define DEFAULT_USER 1354
#define EXIT_TODO 1361
#define CONTINUE_TODO 1362
#define UNLOCK_TABLE 1369
#define ROLLBACK_W 1377
#define SQLSEON 1379
#define SQLSEOFF 1380
#define CREATE_VIEW 1384
#define DELETE_FROM 1385
#define EXTENT_SIZE 1392
#define FOREIGN_KEY 1393
#define INSERT_INTO 1396
#define IS_NOT_NULL 1398
#define NOT_MATCHES 1401
#define PRIMARY_KEY 1407
#define WITH_NO_LOG 1414
#define INSHARE 1417
#define BEGIN_WORK 1423
#define DROP_INDEX 1428
#define FOR_UPDATE_OF 1434
#define FOR_UPDATE 1435
#define LOCK_TABLE 1440
#define NOT_EXISTS 1442
#define REFERENCES 1444
#define RENCOL 1445
#define SMALLFLOAT 1447
#define COMMIT_W 1458
#define RENTAB 1465
#define KW_CHAR 1468
#define NCHAR 1469
#define NVARCHAR 1470
#define DELIMITER 1472
#define DROP_VIEW 1474
#define EXCLUSIVE 1477
#define GREATER_THAN_EQ 1481
#define INTO_TEMP 1483
#define DATABASE 1507
#define DATETIME 1508
#define DISTINCT 1510
#define FRACTION 1517
#define GROUP_BY 1519
#define INTERVAL 1520
#define NOT_LIKE 1522
#define NOT_ILIKE 1523
#define NOT_NULL 1524
#define RESOURCE 1530
#define SMALLINT 1531
#define IS_NULL 1537
#define LESS_THAN_EQ 1538
#define BETWEEN 1540
#define CLOSE_BRACKET 1543
#define CONNECT 1546
#define KW_CURRENT 1547
#define KW_DECIMAL 1549
#define KW_DEFAULT 1551
#define INTEGER 1559
#define SERIAL8 1561
#define MATCHES 1564
#define VARCHAR 1577
#define CLOSE_SQUARE 1580
#define GREATER_THAN 1581
#define KW_FALSE 1582
#define NOT_IN 1583
#define OPEN_BRACKET_SELECT 1585
#define OPEN_BRACKET 1586
#define KW_DELETE 1594
#define KW_ESCAPE 1597
#define EXISTS 1598
#define EXTEND 1599
#define HAVING 1603
#define KW_INSERT 1605
#define MINUTE 1609
#define MODIFY 1610
#define EQUAL 1612
#define NOT_EQUAL 1613
#define OPEN_SQUARE 1615
#define PUBLIC 1619
#define KW_RETURN_KEY 1622
#define REVOKE 1624
#define SECOND 1628
#define KW_SELECT 1632
#define SERIAL 1633
#define UNIQUE 1636
#define KW_UPDATE 1638
#define VALUES 1639
#define KW_NULL 1642
#define KW_TRUE 1643
#define ALTER 1645
#define CHECK 1651
#define COUNT 1655
#define KW_FIRST 1660
#define KW_FLOAT 1661
#define GRANT 1664
#define INDEX 1667
#define LESS_THAN 1670
#define MONEY 1672
#define MONTH 1673
#define KW_MULTIPLY 1675
#define ORDER 1676
#define OUTER 1677
#define UNION 1686
#define WHERE 1689
#define KW_BYTE 1696
#define CASE 1698
#define KW_DATE 1700
#define DESC 1701
#define KW_DIVIDE 1702
#define DROP 1705
#define ELSE 1706
#define FROM 1710
#define HOUR 1716
#define INTO 1717
#define LIKE 1720
#define REAL 1729
#define SOME 1734
#define KW_TEXT 1738
#define KW_THEN 1739
#define USER 1740
#define WHEN 1742
#define YEAR 1745
#define KW_DOW 1746
#define XSET 1748
#define ADD 1749
#define ALL 1750
#define KW_AND 1751
#define ANY 1752
#define ASC 1753
#define AVG 1754
#define COLON 1755
#define KW_COMMA 1756
#define DAY 1757
#define DBA 1758
#define KW_FOR 1762
#define XMAX 1767
#define XMIN 1768
#define KW_MINUS 1769
#define KW_MOD 1770
#define KW_NOT 1771
#define KW_SUM 1778
#define ATSIGN 1781
#define KW_PLUS 1782
#define KW_AS 1788
#define KW_BY 1790
#define KW_DOT 1791
#define KW_IN 1794
#define KW_ON 1796
#define KW_OR 1797
#define KW_TO 1798
#define BEFORE 1836
#define END 1840
#define TILDE 1847
#define ILIKE 1848
#define FILLFACTOR 1851
#define TIME 1856
#define KW_TODAY 1863
#define KW_ROWID 1864
#define TIMESTAMP 2212
#define KWPIPE 2242




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
#line 642 "y.tab.h"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE sqlparse_yylval;


