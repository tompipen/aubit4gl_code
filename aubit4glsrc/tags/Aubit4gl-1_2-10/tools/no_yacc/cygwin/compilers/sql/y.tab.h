
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
     INT_VALUE = 2229,
     NAMED = 2230,
     NAMED_GEN = 2231,
     CHAR_VALUE = 2232,
     NOT_USED_1 = 2233,
     NOT_USED_2 = 2234,
     NOT_USED_3 = 2235,
     NOT_USED_4 = 2236,
     NOT_USED_5 = 2237,
     NOT_USED_6 = 2238,
     NOT_USED_7 = 2239,
     NOT_USED_8 = 2240,
     NUMBER_VALUE = 2241,
     SEMICOLON = 2242,
     QUESTION_MARK = 2243,
     CLINE = 2244,
     CH = 2245,
     MARK_VAR = 2246,
     END_MARK_VAR = 2247,
     WITH_LISTING_IN = 1001,
     SET_CONSTRAINTS_ALL_DEFERRED = 1002,
     DOCUMENT = 1003,
     ON_EXCEPTION = 1005,
     SET_DEBUG_FILE_TO = 1006,
     CREATE_DBA_PROCEDURE = 1011,
     CREATE_FUNCTION = 1012,
     CREATE_DBA_FUNCTION = 1013,
     USE_SESSION = 1015,
     KW_RUN_CLIENT = 1016,
     LEFT_JOIN = 1018,
     IGNORE_ERRORS = 1021,
     SQLERRMESSAGE = 1022,
     DISPLAY_NULL_TO = 1023,
     UNBUFFERED = 1024,
     KW_PICTURE = 1025,
     ON_CHANGE = 1026,
     INNER_JOIN = 1027,
     UI_INTERFACE_DOT_FRONTCALL = 1030,
     UICOMBOBOX = 1034,
     UIFORM = 1037,
     USING_BTREE = 1053,
     USING_RTREE = 1054,
     SET_BUFFERED_LOG = 1073,
     SET_LOG = 1076,
     MDY = 1078,
     WEEKDAY = 1079,
     MODE_ANSI = 1082,
     START_DATABASE = 1083,
     WITH_LOG_IN = 1084,
     SET_CONSTRAINTS_ALL_IMMEDIATE = 1085,
     DATETIME_VALUE = 1098,
     INTERVAL_VALUE = 1099,
     RECOVER_TABLE = 1100,
     ROLLFORWARD_DATABASE = 1101,
     DROP_TRIGGER = 1117,
     DROP_AUDIT_FOR = 1118,
     CREATE_AUDIT_FOR = 1119,
     EXECUTE_PROCEDURE = 1123,
     ALTER_TABLE = 1130,
     ALTER_INDEX = 1131,
     NEXT_SIZE = 1132,
     XSET_MULTIPLY_EQUAL_OPEN_BRACKET = 1169,
     XSET_ident_DOT_MULTIPLY_EQUAL_OPEN_BRACKET = 1170,
     XSET_ident_DOT_MULTIPLY_EQUAL = 1171,
     XSET_MULTIPLY_EQUAL = 1172,
     XSET_OPEN_BRACKET = 1173,
     CREATE_DATABASE = 1176,
     DROP_DATABASE = 1177,
     ADD_CONSTRAINT = 1179,
     DROP_CONSTRAINT = 1180,
     DROP_SYNONYM = 1181,
     CONSTRAINT = 1182,
     NOT_FIELD_TOUCHED_CURRENT = 1185,
     FIELD_TOUCHED_CURRENT = 1186,
     DOUBLE_PRECISION = 1193,
     COUNT_MULTIPLY = 1194,
     MODIFY_NEXT_SIZE = 1214,
     LOCK_MODE_PAGE = 1215,
     LOCK_MODE_ROW = 1216,
     UNITS_YEAR = 1223,
     UNITS_MONTH = 1224,
     UNITS_DAY = 1225,
     UNITS_HOUR = 1226,
     UNITS_MINUTE = 1227,
     UNITS_SECOND = 1228,
     TO_CLUSTER = 1233,
     TO_NOT_CLUSTER = 1234,
     CREATE_UC_IDX = 1236,
     CREATE_U_IDX = 1237,
     CREATE_C_IDX = 1238,
     CREATE_IDX = 1239,
     DOUBLE_COLON = 1249,
     SQLSICS = 1255,
     CREATE_SCHEMA = 1256,
     SQLSIRR = 1257,
     UPDATESTATS_T = 1258,
     SQLSICR = 1259,
     SQLSIDR = 1270,
     CREATE_TEMP_TABLE = 1271,
     WITH_CHECK_OPTION = 1279,
     WITH_GRANT_OPTION = 1280,
     SQLSLMNW = 1281,
     WHERE_CURRENT_OF = 1287,
     NOT_NULL_UNIQUE = 1295,
     SQLSLMW = 1302,
     ALL_PRIVILEGES = 1304,
     CREATE_SYNONYM = 1308,
     DROP_TABLE = 1309,
     INEXCLUSIVE = 1311,
     UPDATESTATS = 1316,
     CREATE_TABLE = 1342,
     DEFAULT_NULL = 1343,
     DEFAULT_TODAY = 1344,
     DEFAULT_USER = 1345,
     UNLOCK_TABLE = 1358,
     ROLLBACK_W = 1366,
     SQLSEON = 1368,
     SQLSEOFF = 1369,
     CREATE_VIEW = 1373,
     DELETE_FROM = 1374,
     EXTENT_SIZE = 1381,
     FOREIGN_KEY = 1382,
     INSERT_INTO = 1385,
     IS_NOT_NULL = 1387,
     NOT_MATCHES = 1390,
     PRIMARY_KEY = 1396,
     WITH_NO_LOG = 1403,
     INSHARE = 1406,
     BEGIN_WORK = 1412,
     DROP_INDEX = 1417,
     FOR_UPDATE_OF = 1423,
     FOR_UPDATE = 1424,
     LOCK_TABLE = 1429,
     NOT_EXISTS = 1431,
     REFERENCES = 1433,
     RENCOL = 1434,
     SMALLFLOAT = 1436,
     COMMIT_W = 1447,
     RENTAB = 1454,
     KW_CHAR = 1457,
     NCHAR = 1458,
     NVARCHAR = 1459,
     DELIMITER = 1461,
     DROP_VIEW = 1463,
     EXCLUSIVE = 1466,
     GREATER_THAN_EQ = 1470,
     INTO_TEMP = 1472,
     DATABASE = 1496,
     DATETIME = 1497,
     DISTINCT = 1499,
     FRACTION = 1506,
     GROUP_BY = 1508,
     INTERVAL = 1509,
     NOT_LIKE = 1511,
     NOT_ILIKE = 1512,
     NOT_NULL = 1513,
     RESOURCE = 1519,
     SMALLINT = 1520,
     IS_NULL = 1526,
     LESS_THAN_EQ = 1527,
     BETWEEN = 1529,
     CLOSE_BRACKET = 1532,
     CONNECT = 1535,
     KW_CURRENT = 1536,
     KW_DECIMAL = 1538,
     DEFAULT = 1540,
     INTEGER = 1548,
     SERIAL8 = 1550,
     MATCHES = 1553,
     VARCHAR = 1566,
     CLOSE_SQUARE = 1569,
     GREATER_THAN = 1570,
     KW_FALSE = 1571,
     NOT_IN = 1572,
     OPEN_BRACKET = 1574,
     KW_DELETE = 1582,
     KW_ESCAPE = 1585,
     EXISTS = 1586,
     EXTEND = 1587,
     HAVING = 1591,
     KW_INSERT = 1593,
     MINUTE = 1597,
     MODIFY = 1598,
     EQUAL = 1600,
     NOT_EQUAL = 1601,
     OPEN_SQUARE = 1603,
     PUBLIC = 1607,
     REVOKE = 1611,
     SECOND = 1615,
     KW_SELECT = 1619,
     SERIAL = 1620,
     UNIQUE = 1623,
     KW_UPDATE = 1625,
     VALUES = 1626,
     KW_NULL = 1629,
     KW_TRUE = 1630,
     ALTER = 1632,
     CHECK = 1638,
     COUNT = 1642,
     KW_FIRST = 1647,
     KW_FLOAT = 1648,
     GRANT = 1651,
     INDEX = 1654,
     LESS_THAN = 1657,
     MONEY = 1659,
     MONTH = 1660,
     KW_MULTIPLY = 1662,
     ORDER = 1663,
     OUTER = 1664,
     UNION = 1673,
     WHERE = 1676,
     KW_BYTE = 1683,
     CASE = 1685,
     KW_DATE = 1687,
     DESC = 1688,
     KW_DIVIDE = 1689,
     DROP = 1692,
     ELSE = 1693,
     FROM = 1697,
     HOUR = 1703,
     INTO = 1704,
     LIKE = 1707,
     REAL = 1716,
     SOME = 1721,
     KW_TEXT = 1725,
     KW_THEN = 1726,
     USER = 1727,
     WHEN = 1729,
     YEAR = 1732,
     KW_DOW = 1733,
     XSET = 1735,
     ADD = 1736,
     ALL = 1737,
     KW_AND = 1738,
     ANY = 1739,
     ASC = 1740,
     AVG = 1741,
     COLON = 1742,
     KW_COMMA = 1743,
     DAY = 1744,
     DBA = 1745,
     KW_FOR = 1749,
     XMAX = 1754,
     XMIN = 1755,
     KW_MINUS = 1756,
     KW_MOD = 1757,
     KW_NOT = 1758,
     KW_SUM = 1765,
     ATSIGN = 1768,
     KW_PLUS = 1769,
     KW_AS = 1775,
     KW_BY = 1777,
     KW_DOT = 1778,
     KW_IN = 1781,
     KW_ON = 1783,
     KW_OR = 1784,
     KW_TO = 1785,
     BEFORE = 1823,
     END = 1827,
     TILDE = 1834,
     ILIKE = 1835,
     FILLFACTOR = 1838,
     TIME = 1843,
     KW_TODAY = 1850,
     KW_ROWID = 1851,
     TIMESTAMP = 2199,
     KW_TAG = 2220,
     LINTMODULEISLIBRARY = 2221,
     KW_PUBLIC = 2222,
     KW_PRIVATE = 2223,
     COPYBACK = 2224,
     REFERENCES_BLOBTYPE_DEFAULT_NULL = 2225,
     REFERENCES_BLOBTYPE = 2226,
     SORT = 2227
   };
#endif
/* Tokens.  */
#define INT_VALUE 2229
#define NAMED 2230
#define NAMED_GEN 2231
#define CHAR_VALUE 2232
#define NOT_USED_1 2233
#define NOT_USED_2 2234
#define NOT_USED_3 2235
#define NOT_USED_4 2236
#define NOT_USED_5 2237
#define NOT_USED_6 2238
#define NOT_USED_7 2239
#define NOT_USED_8 2240
#define NUMBER_VALUE 2241
#define SEMICOLON 2242
#define QUESTION_MARK 2243
#define CLINE 2244
#define CH 2245
#define MARK_VAR 2246
#define END_MARK_VAR 2247
#define WITH_LISTING_IN 1001
#define SET_CONSTRAINTS_ALL_DEFERRED 1002
#define DOCUMENT 1003
#define ON_EXCEPTION 1005
#define SET_DEBUG_FILE_TO 1006
#define CREATE_DBA_PROCEDURE 1011
#define CREATE_FUNCTION 1012
#define CREATE_DBA_FUNCTION 1013
#define USE_SESSION 1015
#define KW_RUN_CLIENT 1016
#define LEFT_JOIN 1018
#define IGNORE_ERRORS 1021
#define SQLERRMESSAGE 1022
#define DISPLAY_NULL_TO 1023
#define UNBUFFERED 1024
#define KW_PICTURE 1025
#define ON_CHANGE 1026
#define INNER_JOIN 1027
#define UI_INTERFACE_DOT_FRONTCALL 1030
#define UICOMBOBOX 1034
#define UIFORM 1037
#define USING_BTREE 1053
#define USING_RTREE 1054
#define SET_BUFFERED_LOG 1073
#define SET_LOG 1076
#define MDY 1078
#define WEEKDAY 1079
#define MODE_ANSI 1082
#define START_DATABASE 1083
#define WITH_LOG_IN 1084
#define SET_CONSTRAINTS_ALL_IMMEDIATE 1085
#define DATETIME_VALUE 1098
#define INTERVAL_VALUE 1099
#define RECOVER_TABLE 1100
#define ROLLFORWARD_DATABASE 1101
#define DROP_TRIGGER 1117
#define DROP_AUDIT_FOR 1118
#define CREATE_AUDIT_FOR 1119
#define EXECUTE_PROCEDURE 1123
#define ALTER_TABLE 1130
#define ALTER_INDEX 1131
#define NEXT_SIZE 1132
#define XSET_MULTIPLY_EQUAL_OPEN_BRACKET 1169
#define XSET_ident_DOT_MULTIPLY_EQUAL_OPEN_BRACKET 1170
#define XSET_ident_DOT_MULTIPLY_EQUAL 1171
#define XSET_MULTIPLY_EQUAL 1172
#define XSET_OPEN_BRACKET 1173
#define CREATE_DATABASE 1176
#define DROP_DATABASE 1177
#define ADD_CONSTRAINT 1179
#define DROP_CONSTRAINT 1180
#define DROP_SYNONYM 1181
#define CONSTRAINT 1182
#define NOT_FIELD_TOUCHED_CURRENT 1185
#define FIELD_TOUCHED_CURRENT 1186
#define DOUBLE_PRECISION 1193
#define COUNT_MULTIPLY 1194
#define MODIFY_NEXT_SIZE 1214
#define LOCK_MODE_PAGE 1215
#define LOCK_MODE_ROW 1216
#define UNITS_YEAR 1223
#define UNITS_MONTH 1224
#define UNITS_DAY 1225
#define UNITS_HOUR 1226
#define UNITS_MINUTE 1227
#define UNITS_SECOND 1228
#define TO_CLUSTER 1233
#define TO_NOT_CLUSTER 1234
#define CREATE_UC_IDX 1236
#define CREATE_U_IDX 1237
#define CREATE_C_IDX 1238
#define CREATE_IDX 1239
#define DOUBLE_COLON 1249
#define SQLSICS 1255
#define CREATE_SCHEMA 1256
#define SQLSIRR 1257
#define UPDATESTATS_T 1258
#define SQLSICR 1259
#define SQLSIDR 1270
#define CREATE_TEMP_TABLE 1271
#define WITH_CHECK_OPTION 1279
#define WITH_GRANT_OPTION 1280
#define SQLSLMNW 1281
#define WHERE_CURRENT_OF 1287
#define NOT_NULL_UNIQUE 1295
#define SQLSLMW 1302
#define ALL_PRIVILEGES 1304
#define CREATE_SYNONYM 1308
#define DROP_TABLE 1309
#define INEXCLUSIVE 1311
#define UPDATESTATS 1316
#define CREATE_TABLE 1342
#define DEFAULT_NULL 1343
#define DEFAULT_TODAY 1344
#define DEFAULT_USER 1345
#define UNLOCK_TABLE 1358
#define ROLLBACK_W 1366
#define SQLSEON 1368
#define SQLSEOFF 1369
#define CREATE_VIEW 1373
#define DELETE_FROM 1374
#define EXTENT_SIZE 1381
#define FOREIGN_KEY 1382
#define INSERT_INTO 1385
#define IS_NOT_NULL 1387
#define NOT_MATCHES 1390
#define PRIMARY_KEY 1396
#define WITH_NO_LOG 1403
#define INSHARE 1406
#define BEGIN_WORK 1412
#define DROP_INDEX 1417
#define FOR_UPDATE_OF 1423
#define FOR_UPDATE 1424
#define LOCK_TABLE 1429
#define NOT_EXISTS 1431
#define REFERENCES 1433
#define RENCOL 1434
#define SMALLFLOAT 1436
#define COMMIT_W 1447
#define RENTAB 1454
#define KW_CHAR 1457
#define NCHAR 1458
#define NVARCHAR 1459
#define DELIMITER 1461
#define DROP_VIEW 1463
#define EXCLUSIVE 1466
#define GREATER_THAN_EQ 1470
#define INTO_TEMP 1472
#define DATABASE 1496
#define DATETIME 1497
#define DISTINCT 1499
#define FRACTION 1506
#define GROUP_BY 1508
#define INTERVAL 1509
#define NOT_LIKE 1511
#define NOT_ILIKE 1512
#define NOT_NULL 1513
#define RESOURCE 1519
#define SMALLINT 1520
#define IS_NULL 1526
#define LESS_THAN_EQ 1527
#define BETWEEN 1529
#define CLOSE_BRACKET 1532
#define CONNECT 1535
#define KW_CURRENT 1536
#define KW_DECIMAL 1538
#define DEFAULT 1540
#define INTEGER 1548
#define SERIAL8 1550
#define MATCHES 1553
#define VARCHAR 1566
#define CLOSE_SQUARE 1569
#define GREATER_THAN 1570
#define KW_FALSE 1571
#define NOT_IN 1572
#define OPEN_BRACKET 1574
#define KW_DELETE 1582
#define KW_ESCAPE 1585
#define EXISTS 1586
#define EXTEND 1587
#define HAVING 1591
#define KW_INSERT 1593
#define MINUTE 1597
#define MODIFY 1598
#define EQUAL 1600
#define NOT_EQUAL 1601
#define OPEN_SQUARE 1603
#define PUBLIC 1607
#define REVOKE 1611
#define SECOND 1615
#define KW_SELECT 1619
#define SERIAL 1620
#define UNIQUE 1623
#define KW_UPDATE 1625
#define VALUES 1626
#define KW_NULL 1629
#define KW_TRUE 1630
#define ALTER 1632
#define CHECK 1638
#define COUNT 1642
#define KW_FIRST 1647
#define KW_FLOAT 1648
#define GRANT 1651
#define INDEX 1654
#define LESS_THAN 1657
#define MONEY 1659
#define MONTH 1660
#define KW_MULTIPLY 1662
#define ORDER 1663
#define OUTER 1664
#define UNION 1673
#define WHERE 1676
#define KW_BYTE 1683
#define CASE 1685
#define KW_DATE 1687
#define DESC 1688
#define KW_DIVIDE 1689
#define DROP 1692
#define ELSE 1693
#define FROM 1697
#define HOUR 1703
#define INTO 1704
#define LIKE 1707
#define REAL 1716
#define SOME 1721
#define KW_TEXT 1725
#define KW_THEN 1726
#define USER 1727
#define WHEN 1729
#define YEAR 1732
#define KW_DOW 1733
#define XSET 1735
#define ADD 1736
#define ALL 1737
#define KW_AND 1738
#define ANY 1739
#define ASC 1740
#define AVG 1741
#define COLON 1742
#define KW_COMMA 1743
#define DAY 1744
#define DBA 1745
#define KW_FOR 1749
#define XMAX 1754
#define XMIN 1755
#define KW_MINUS 1756
#define KW_MOD 1757
#define KW_NOT 1758
#define KW_SUM 1765
#define ATSIGN 1768
#define KW_PLUS 1769
#define KW_AS 1775
#define KW_BY 1777
#define KW_DOT 1778
#define KW_IN 1781
#define KW_ON 1783
#define KW_OR 1784
#define KW_TO 1785
#define BEFORE 1823
#define END 1827
#define TILDE 1834
#define ILIKE 1835
#define FILLFACTOR 1838
#define TIME 1843
#define KW_TODAY 1850
#define KW_ROWID 1851
#define TIMESTAMP 2199
#define KW_TAG 2220
#define LINTMODULEISLIBRARY 2221
#define KW_PUBLIC 2222
#define KW_PRIVATE 2223
#define COPYBACK 2224
#define REFERENCES_BLOBTYPE_DEFAULT_NULL 2225
#define REFERENCES_BLOBTYPE 2226
#define SORT 2227




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 1676 of yacc.c  */
#line 119 "sql.yacc"

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
#line 629 "y.tab.h"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE sqlparse_yylval;


