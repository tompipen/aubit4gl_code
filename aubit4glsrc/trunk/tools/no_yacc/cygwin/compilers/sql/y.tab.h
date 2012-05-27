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
     INT_VALUE = 2247,
     NAMED = 2248,
     NAMED_GEN = 2249,
     CHAR_VALUE = 2250,
     NOT_USED_1 = 2251,
     NOT_USED_2 = 2252,
     NOT_USED_3 = 2253,
     NOT_USED_4 = 2254,
     NOT_USED_5 = 2255,
     NOT_USED_6 = 2256,
     NOT_USED_7 = 2257,
     NOT_USED_8 = 2258,
     NUMBER_VALUE = 2259,
     SEMICOLON = 2260,
     QUESTION_MARK = 2261,
     CLINE = 2262,
     CH = 2263,
     MARK_VAR = 2264,
     END_MARK_VAR = 2265,
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
     UIGANTT = 1038,
     UIFORM = 1041,
     USING_BTREE = 1057,
     USING_RTREE = 1058,
     SET_BUFFERED_LOG = 1077,
     SET_LOG = 1080,
     MDY = 1082,
     WEEKDAY = 1083,
     MODE_ANSI = 1086,
     START_DATABASE = 1087,
     WITH_LOG_IN = 1088,
     SET_CONSTRAINTS_ALL_IMMEDIATE = 1089,
     DATETIME_VALUE = 1102,
     INTERVAL_VALUE = 1103,
     RECOVER_TABLE = 1104,
     ROLLFORWARD_DATABASE = 1105,
     CONCAT_PIPES = 1119,
     DROP_TRIGGER = 1121,
     DROP_AUDIT_FOR = 1122,
     CREATE_AUDIT_FOR = 1123,
     EXECUTE_PROCEDURE = 1127,
     ALTER_TABLE = 1134,
     ALTER_INDEX = 1135,
     NEXT_SIZE = 1136,
     KW_WHENEVER_SIGNAL = 1173,
     KW_SIGNAL_TOKEN = 1174,
     XSET_MULTIPLY_EQUAL_OPEN_BRACKET = 1175,
     XSET_ident_DOT_MULTIPLY_EQUAL_OPEN_BRACKET = 1176,
     XSET_ident_DOT_MULTIPLY_EQUAL = 1177,
     XSET_MULTIPLY_EQUAL = 1178,
     XSET_OPEN_BRACKET = 1179,
     CREATE_DATABASE = 1182,
     DROP_DATABASE = 1183,
     ADD_CONSTRAINT = 1185,
     DROP_CONSTRAINT = 1186,
     DROP_SYNONYM = 1187,
     CONSTRAINT = 1188,
     NOT_FIELD_TOUCHED_CURRENT = 1191,
     FIELD_TOUCHED_CURRENT = 1192,
     OBJECT_FUNCTION = 1194,
     DOUBLE_PRECISION = 1200,
     COUNT_MULTIPLY = 1201,
     KW_ASCII_OPEN_BRACKET = 1210,
     MODIFY_NEXT_SIZE = 1222,
     LOCK_MODE_PAGE = 1223,
     LOCK_MODE_ROW = 1224,
     TO_UI = 1229,
     UNITS_YEAR = 1232,
     UNITS_MONTH = 1233,
     UNITS_DAY = 1234,
     UNITS_HOUR = 1235,
     UNITS_MINUTE = 1236,
     UNITS_SECOND = 1237,
     TO_CLUSTER = 1242,
     TO_NOT_CLUSTER = 1243,
     CREATE_UC_IDX = 1245,
     CREATE_U_IDX = 1246,
     CREATE_C_IDX = 1247,
     CREATE_IDX = 1248,
     DOUBLE_COLON = 1258,
     SQLSICS = 1264,
     CREATE_SCHEMA = 1265,
     SQLSIRR = 1266,
     UPDATESTATS_T = 1267,
     SQLSICR = 1268,
     SQLSIDR = 1279,
     CREATE_TEMP_TABLE = 1280,
     WITH_CHECK_OPTION = 1288,
     WITH_GRANT_OPTION = 1289,
     SQLSLMNW = 1290,
     WHERE_CURRENT_OF = 1296,
     NOT_NULL_UNIQUE = 1304,
     SQLSLMW = 1311,
     ALL_PRIVILEGES = 1313,
     CREATE_SYNONYM = 1317,
     DROP_TABLE = 1318,
     INEXCLUSIVE = 1320,
     REPORT_TO_FILE = 1321,
     REPORT_TO_UI = 1322,
     UPDATESTATS = 1327,
     CREATE_TABLE = 1353,
     DEFAULT_NULL = 1354,
     DEFAULT_TODAY = 1355,
     DEFAULT_USER = 1356,
     EXIT_TODO = 1363,
     CONTINUE_TODO = 1364,
     UNLOCK_TABLE = 1371,
     ROLLBACK_W = 1379,
     SQLSEON = 1381,
     SQLSEOFF = 1382,
     CREATE_VIEW = 1386,
     DELETE_FROM = 1387,
     EXTENT_SIZE = 1394,
     FOREIGN_KEY = 1395,
     INSERT_INTO = 1398,
     IS_NOT_NULL = 1400,
     NOT_MATCHES = 1403,
     PRIMARY_KEY = 1409,
     WITH_NO_LOG = 1416,
     INSHARE = 1419,
     BEGIN_WORK = 1425,
     DROP_INDEX = 1430,
     FOR_UPDATE_OF = 1436,
     FOR_UPDATE = 1437,
     LOCK_TABLE = 1442,
     NOT_EXISTS = 1444,
     REFERENCES = 1446,
     RENCOL = 1447,
     SMALLFLOAT = 1449,
     COMMIT_W = 1460,
     RENTAB = 1467,
     KW_CHAR = 1470,
     NCHAR = 1471,
     NVARCHAR = 1472,
     DELIMITER = 1474,
     DROP_VIEW = 1476,
     EXCLUSIVE = 1479,
     GREATER_THAN_EQ = 1483,
     INTO_TEMP = 1485,
     DATABASE = 1509,
     DATETIME = 1510,
     DISTINCT = 1512,
     FRACTION = 1519,
     GROUP_BY = 1521,
     INTERVAL = 1522,
     NOT_LIKE = 1524,
     NOT_ILIKE = 1525,
     NOT_NULL = 1526,
     RESOURCE = 1532,
     SMALLINT = 1533,
     IS_NULL = 1539,
     LESS_THAN_EQ = 1540,
     BETWEEN = 1542,
     CLOSE_BRACKET = 1545,
     CONNECT = 1548,
     KW_CURRENT = 1549,
     KW_DECIMAL = 1551,
     KW_DEFAULT = 1553,
     FGL_SYNCFIELDS = 1561,
     INTEGER = 1562,
     SERIAL8 = 1564,
     MATCHES = 1567,
     VARCHAR = 1580,
     CLOSE_SQUARE = 1583,
     GREATER_THAN = 1584,
     KW_FALSE = 1585,
     NOT_IN = 1586,
     OPEN_BRACKET_SELECT = 1588,
     OPEN_BRACKET = 1589,
     KW_DELETE = 1597,
     KW_ESCAPE = 1600,
     EXISTS = 1601,
     EXTEND = 1602,
     HAVING = 1606,
     KW_INSERT = 1608,
     MINUTE = 1612,
     MODIFY = 1613,
     EQUAL = 1615,
     NOT_EQUAL = 1616,
     OPEN_SQUARE = 1618,
     PUBLIC = 1622,
     KW_RETURN_KEY = 1625,
     REVOKE = 1627,
     SECOND = 1631,
     KW_SELECT = 1635,
     SERIAL = 1636,
     UNIQUE = 1639,
     KW_UPDATE = 1641,
     VALUES = 1642,
     KW_NULL = 1645,
     KW_TRUE = 1646,
     ALTER = 1648,
     CHECK = 1654,
     COUNT = 1658,
     KW_FIRST = 1663,
     KW_FLOAT = 1664,
     GRANT = 1667,
     INDEX = 1670,
     LESS_THAN = 1673,
     MONEY = 1675,
     MONTH = 1676,
     KW_MULTIPLY = 1678,
     ORDER = 1679,
     OUTER = 1680,
     UNION = 1689,
     WHERE = 1692,
     KW_BYTE = 1699,
     CASE = 1701,
     KW_DATE = 1703,
     DESC = 1704,
     KW_DIVIDE = 1705,
     DROP = 1708,
     ELSE = 1709,
     FROM = 1713,
     HOUR = 1719,
     INTO = 1720,
     LIKE = 1723,
     REAL = 1732,
     SOME = 1737,
     KW_TEXT = 1741,
     KW_THEN = 1742,
     USER = 1743,
     WHEN = 1745,
     YEAR = 1748,
     KW_DOW = 1749,
     XSET = 1751,
     ADD = 1752,
     ALL = 1753,
     KW_AND = 1754,
     ANY = 1755,
     ASC = 1756,
     AVG = 1757,
     COLON = 1758,
     KW_COMMA = 1759,
     DAY = 1760,
     DBA = 1761,
     KW_FOR = 1765,
     XMAX = 1770,
     XMIN = 1771,
     KW_MINUS = 1772,
     KW_MOD = 1773,
     KW_NOT = 1774,
     KW_SUM = 1781,
     ATSIGN = 1784,
     KW_PLUS = 1785,
     KW_AS = 1791,
     KW_BY = 1793,
     KW_DOT = 1794,
     KW_IN = 1797,
     KW_ON = 1799,
     KW_OR = 1800,
     KW_TO = 1801,
     BEFORE = 1839,
     END = 1843,
     TILDE = 1850,
     ILIKE = 1851,
     FILLFACTOR = 1854,
     TIME = 1859,
     KW_TODAY = 1866,
     KW_ROWID = 1867,
     TIMESTAMP = 2215,
     KWPIPE = 2245
   };
#endif
/* Tokens.  */
#define INT_VALUE 2247
#define NAMED 2248
#define NAMED_GEN 2249
#define CHAR_VALUE 2250
#define NOT_USED_1 2251
#define NOT_USED_2 2252
#define NOT_USED_3 2253
#define NOT_USED_4 2254
#define NOT_USED_5 2255
#define NOT_USED_6 2256
#define NOT_USED_7 2257
#define NOT_USED_8 2258
#define NUMBER_VALUE 2259
#define SEMICOLON 2260
#define QUESTION_MARK 2261
#define CLINE 2262
#define CH 2263
#define MARK_VAR 2264
#define END_MARK_VAR 2265
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
#define UIGANTT 1038
#define UIFORM 1041
#define USING_BTREE 1057
#define USING_RTREE 1058
#define SET_BUFFERED_LOG 1077
#define SET_LOG 1080
#define MDY 1082
#define WEEKDAY 1083
#define MODE_ANSI 1086
#define START_DATABASE 1087
#define WITH_LOG_IN 1088
#define SET_CONSTRAINTS_ALL_IMMEDIATE 1089
#define DATETIME_VALUE 1102
#define INTERVAL_VALUE 1103
#define RECOVER_TABLE 1104
#define ROLLFORWARD_DATABASE 1105
#define CONCAT_PIPES 1119
#define DROP_TRIGGER 1121
#define DROP_AUDIT_FOR 1122
#define CREATE_AUDIT_FOR 1123
#define EXECUTE_PROCEDURE 1127
#define ALTER_TABLE 1134
#define ALTER_INDEX 1135
#define NEXT_SIZE 1136
#define KW_WHENEVER_SIGNAL 1173
#define KW_SIGNAL_TOKEN 1174
#define XSET_MULTIPLY_EQUAL_OPEN_BRACKET 1175
#define XSET_ident_DOT_MULTIPLY_EQUAL_OPEN_BRACKET 1176
#define XSET_ident_DOT_MULTIPLY_EQUAL 1177
#define XSET_MULTIPLY_EQUAL 1178
#define XSET_OPEN_BRACKET 1179
#define CREATE_DATABASE 1182
#define DROP_DATABASE 1183
#define ADD_CONSTRAINT 1185
#define DROP_CONSTRAINT 1186
#define DROP_SYNONYM 1187
#define CONSTRAINT 1188
#define NOT_FIELD_TOUCHED_CURRENT 1191
#define FIELD_TOUCHED_CURRENT 1192
#define OBJECT_FUNCTION 1194
#define DOUBLE_PRECISION 1200
#define COUNT_MULTIPLY 1201
#define KW_ASCII_OPEN_BRACKET 1210
#define MODIFY_NEXT_SIZE 1222
#define LOCK_MODE_PAGE 1223
#define LOCK_MODE_ROW 1224
#define TO_UI 1229
#define UNITS_YEAR 1232
#define UNITS_MONTH 1233
#define UNITS_DAY 1234
#define UNITS_HOUR 1235
#define UNITS_MINUTE 1236
#define UNITS_SECOND 1237
#define TO_CLUSTER 1242
#define TO_NOT_CLUSTER 1243
#define CREATE_UC_IDX 1245
#define CREATE_U_IDX 1246
#define CREATE_C_IDX 1247
#define CREATE_IDX 1248
#define DOUBLE_COLON 1258
#define SQLSICS 1264
#define CREATE_SCHEMA 1265
#define SQLSIRR 1266
#define UPDATESTATS_T 1267
#define SQLSICR 1268
#define SQLSIDR 1279
#define CREATE_TEMP_TABLE 1280
#define WITH_CHECK_OPTION 1288
#define WITH_GRANT_OPTION 1289
#define SQLSLMNW 1290
#define WHERE_CURRENT_OF 1296
#define NOT_NULL_UNIQUE 1304
#define SQLSLMW 1311
#define ALL_PRIVILEGES 1313
#define CREATE_SYNONYM 1317
#define DROP_TABLE 1318
#define INEXCLUSIVE 1320
#define REPORT_TO_FILE 1321
#define REPORT_TO_UI 1322
#define UPDATESTATS 1327
#define CREATE_TABLE 1353
#define DEFAULT_NULL 1354
#define DEFAULT_TODAY 1355
#define DEFAULT_USER 1356
#define EXIT_TODO 1363
#define CONTINUE_TODO 1364
#define UNLOCK_TABLE 1371
#define ROLLBACK_W 1379
#define SQLSEON 1381
#define SQLSEOFF 1382
#define CREATE_VIEW 1386
#define DELETE_FROM 1387
#define EXTENT_SIZE 1394
#define FOREIGN_KEY 1395
#define INSERT_INTO 1398
#define IS_NOT_NULL 1400
#define NOT_MATCHES 1403
#define PRIMARY_KEY 1409
#define WITH_NO_LOG 1416
#define INSHARE 1419
#define BEGIN_WORK 1425
#define DROP_INDEX 1430
#define FOR_UPDATE_OF 1436
#define FOR_UPDATE 1437
#define LOCK_TABLE 1442
#define NOT_EXISTS 1444
#define REFERENCES 1446
#define RENCOL 1447
#define SMALLFLOAT 1449
#define COMMIT_W 1460
#define RENTAB 1467
#define KW_CHAR 1470
#define NCHAR 1471
#define NVARCHAR 1472
#define DELIMITER 1474
#define DROP_VIEW 1476
#define EXCLUSIVE 1479
#define GREATER_THAN_EQ 1483
#define INTO_TEMP 1485
#define DATABASE 1509
#define DATETIME 1510
#define DISTINCT 1512
#define FRACTION 1519
#define GROUP_BY 1521
#define INTERVAL 1522
#define NOT_LIKE 1524
#define NOT_ILIKE 1525
#define NOT_NULL 1526
#define RESOURCE 1532
#define SMALLINT 1533
#define IS_NULL 1539
#define LESS_THAN_EQ 1540
#define BETWEEN 1542
#define CLOSE_BRACKET 1545
#define CONNECT 1548
#define KW_CURRENT 1549
#define KW_DECIMAL 1551
#define KW_DEFAULT 1553
#define FGL_SYNCFIELDS 1561
#define INTEGER 1562
#define SERIAL8 1564
#define MATCHES 1567
#define VARCHAR 1580
#define CLOSE_SQUARE 1583
#define GREATER_THAN 1584
#define KW_FALSE 1585
#define NOT_IN 1586
#define OPEN_BRACKET_SELECT 1588
#define OPEN_BRACKET 1589
#define KW_DELETE 1597
#define KW_ESCAPE 1600
#define EXISTS 1601
#define EXTEND 1602
#define HAVING 1606
#define KW_INSERT 1608
#define MINUTE 1612
#define MODIFY 1613
#define EQUAL 1615
#define NOT_EQUAL 1616
#define OPEN_SQUARE 1618
#define PUBLIC 1622
#define KW_RETURN_KEY 1625
#define REVOKE 1627
#define SECOND 1631
#define KW_SELECT 1635
#define SERIAL 1636
#define UNIQUE 1639
#define KW_UPDATE 1641
#define VALUES 1642
#define KW_NULL 1645
#define KW_TRUE 1646
#define ALTER 1648
#define CHECK 1654
#define COUNT 1658
#define KW_FIRST 1663
#define KW_FLOAT 1664
#define GRANT 1667
#define INDEX 1670
#define LESS_THAN 1673
#define MONEY 1675
#define MONTH 1676
#define KW_MULTIPLY 1678
#define ORDER 1679
#define OUTER 1680
#define UNION 1689
#define WHERE 1692
#define KW_BYTE 1699
#define CASE 1701
#define KW_DATE 1703
#define DESC 1704
#define KW_DIVIDE 1705
#define DROP 1708
#define ELSE 1709
#define FROM 1713
#define HOUR 1719
#define INTO 1720
#define LIKE 1723
#define REAL 1732
#define SOME 1737
#define KW_TEXT 1741
#define KW_THEN 1742
#define USER 1743
#define WHEN 1745
#define YEAR 1748
#define KW_DOW 1749
#define XSET 1751
#define ADD 1752
#define ALL 1753
#define KW_AND 1754
#define ANY 1755
#define ASC 1756
#define AVG 1757
#define COLON 1758
#define KW_COMMA 1759
#define DAY 1760
#define DBA 1761
#define KW_FOR 1765
#define XMAX 1770
#define XMIN 1771
#define KW_MINUS 1772
#define KW_MOD 1773
#define KW_NOT 1774
#define KW_SUM 1781
#define ATSIGN 1784
#define KW_PLUS 1785
#define KW_AS 1791
#define KW_BY 1793
#define KW_DOT 1794
#define KW_IN 1797
#define KW_ON 1799
#define KW_OR 1800
#define KW_TO 1801
#define BEFORE 1839
#define END 1843
#define TILDE 1850
#define ILIKE 1851
#define FILLFACTOR 1854
#define TIME 1859
#define KW_TODAY 1866
#define KW_ROWID 1867
#define TIMESTAMP 2215
#define KWPIPE 2245




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
#line 648 "y.tab.h"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE sqlparse_yylval;


