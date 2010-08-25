/* A Bison parser, made by GNU Bison 2.4.2.  */

/* Skeleton interface for Bison's Yacc-like parsers in C
   
      Copyright (C) 1984, 1989-1990, 2000-2006, 2009-2010 Free Software
   Foundation, Inc.
   
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
     XSET_MULTIPLY_EQUAL_OPEN_BRACKET = 1171,
     XSET_ident_DOT_MULTIPLY_EQUAL_OPEN_BRACKET = 1172,
     XSET_ident_DOT_MULTIPLY_EQUAL = 1173,
     XSET_MULTIPLY_EQUAL = 1174,
     XSET_OPEN_BRACKET = 1175,
     CREATE_DATABASE = 1178,
     DROP_DATABASE = 1179,
     ADD_CONSTRAINT = 1181,
     DROP_CONSTRAINT = 1182,
     DROP_SYNONYM = 1183,
     CONSTRAINT = 1184,
     NOT_FIELD_TOUCHED_CURRENT = 1187,
     FIELD_TOUCHED_CURRENT = 1188,
     OBJECT_FUNCTION = 1190,
     DOUBLE_PRECISION = 1196,
     COUNT_MULTIPLY = 1197,
     MODIFY_NEXT_SIZE = 1217,
     LOCK_MODE_PAGE = 1218,
     LOCK_MODE_ROW = 1219,
     UNITS_YEAR = 1226,
     UNITS_MONTH = 1227,
     UNITS_DAY = 1228,
     UNITS_HOUR = 1229,
     UNITS_MINUTE = 1230,
     UNITS_SECOND = 1231,
     TO_CLUSTER = 1236,
     TO_NOT_CLUSTER = 1237,
     CREATE_UC_IDX = 1239,
     CREATE_U_IDX = 1240,
     CREATE_C_IDX = 1241,
     CREATE_IDX = 1242,
     DOUBLE_COLON = 1252,
     SQLSICS = 1258,
     CREATE_SCHEMA = 1259,
     SQLSIRR = 1260,
     UPDATESTATS_T = 1261,
     SQLSICR = 1262,
     SQLSIDR = 1273,
     CREATE_TEMP_TABLE = 1274,
     WITH_CHECK_OPTION = 1282,
     WITH_GRANT_OPTION = 1283,
     SQLSLMNW = 1284,
     WHERE_CURRENT_OF = 1290,
     NOT_NULL_UNIQUE = 1298,
     SQLSLMW = 1305,
     ALL_PRIVILEGES = 1307,
     CREATE_SYNONYM = 1311,
     DROP_TABLE = 1312,
     INEXCLUSIVE = 1314,
     UPDATESTATS = 1319,
     CREATE_TABLE = 1345,
     DEFAULT_NULL = 1346,
     DEFAULT_TODAY = 1347,
     DEFAULT_USER = 1348,
     EXIT_TODO = 1355,
     CONTINUE_TODO = 1356,
     UNLOCK_TABLE = 1363,
     ROLLBACK_W = 1371,
     SQLSEON = 1373,
     SQLSEOFF = 1374,
     CREATE_VIEW = 1378,
     DELETE_FROM = 1379,
     EXTENT_SIZE = 1386,
     FOREIGN_KEY = 1387,
     INSERT_INTO = 1390,
     IS_NOT_NULL = 1392,
     NOT_MATCHES = 1395,
     PRIMARY_KEY = 1401,
     WITH_NO_LOG = 1408,
     INSHARE = 1411,
     BEGIN_WORK = 1417,
     DROP_INDEX = 1422,
     FOR_UPDATE_OF = 1428,
     FOR_UPDATE = 1429,
     LOCK_TABLE = 1434,
     NOT_EXISTS = 1436,
     REFERENCES = 1438,
     RENCOL = 1439,
     SMALLFLOAT = 1441,
     COMMIT_W = 1452,
     RENTAB = 1459,
     KW_CHAR = 1462,
     NCHAR = 1463,
     NVARCHAR = 1464,
     DELIMITER = 1466,
     DROP_VIEW = 1468,
     EXCLUSIVE = 1471,
     GREATER_THAN_EQ = 1475,
     INTO_TEMP = 1477,
     DATABASE = 1501,
     DATETIME = 1502,
     DISTINCT = 1504,
     FRACTION = 1511,
     GROUP_BY = 1513,
     INTERVAL = 1514,
     NOT_LIKE = 1516,
     NOT_ILIKE = 1517,
     NOT_NULL = 1518,
     RESOURCE = 1524,
     SMALLINT = 1525,
     IS_NULL = 1531,
     LESS_THAN_EQ = 1532,
     BETWEEN = 1534,
     CLOSE_BRACKET = 1537,
     CONNECT = 1540,
     KW_CURRENT = 1541,
     KW_DECIMAL = 1543,
     DEFAULT = 1545,
     INTEGER = 1553,
     SERIAL8 = 1555,
     MATCHES = 1558,
     VARCHAR = 1571,
     CLOSE_SQUARE = 1574,
     GREATER_THAN = 1575,
     KW_FALSE = 1576,
     NOT_IN = 1577,
     OPEN_BRACKET = 1579,
     KW_DELETE = 1587,
     KW_ESCAPE = 1590,
     EXISTS = 1591,
     EXTEND = 1592,
     HAVING = 1596,
     KW_INSERT = 1598,
     MINUTE = 1602,
     MODIFY = 1603,
     EQUAL = 1605,
     NOT_EQUAL = 1606,
     OPEN_SQUARE = 1608,
     PUBLIC = 1612,
     KW_RETURN_KEY = 1615,
     REVOKE = 1617,
     SECOND = 1621,
     KW_SELECT = 1625,
     SERIAL = 1626,
     UNIQUE = 1629,
     KW_UPDATE = 1631,
     VALUES = 1632,
     KW_NULL = 1635,
     KW_TRUE = 1636,
     ALTER = 1638,
     CHECK = 1644,
     COUNT = 1648,
     KW_FIRST = 1653,
     KW_FLOAT = 1654,
     GRANT = 1657,
     INDEX = 1660,
     LESS_THAN = 1663,
     MONEY = 1665,
     MONTH = 1666,
     KW_MULTIPLY = 1668,
     ORDER = 1669,
     OUTER = 1670,
     UNION = 1679,
     WHERE = 1682,
     KW_BYTE = 1689,
     CASE = 1691,
     KW_DATE = 1693,
     DESC = 1694,
     KW_DIVIDE = 1695,
     DROP = 1698,
     ELSE = 1699,
     FROM = 1703,
     HOUR = 1709,
     INTO = 1710,
     LIKE = 1713,
     REAL = 1722,
     SOME = 1727,
     KW_TEXT = 1731,
     KW_THEN = 1732,
     USER = 1733,
     WHEN = 1735,
     YEAR = 1738,
     KW_DOW = 1739,
     XSET = 1741,
     ADD = 1742,
     ALL = 1743,
     KW_AND = 1744,
     ANY = 1745,
     ASC = 1746,
     AVG = 1747,
     COLON = 1748,
     KW_COMMA = 1749,
     DAY = 1750,
     DBA = 1751,
     KW_FOR = 1755,
     XMAX = 1760,
     XMIN = 1761,
     KW_MINUS = 1762,
     KW_MOD = 1763,
     KW_NOT = 1764,
     KW_SUM = 1771,
     ATSIGN = 1774,
     KW_PLUS = 1775,
     KW_AS = 1781,
     KW_BY = 1783,
     KW_DOT = 1784,
     KW_IN = 1787,
     KW_ON = 1789,
     KW_OR = 1790,
     KW_TO = 1791,
     BEFORE = 1829,
     END = 1833,
     TILDE = 1840,
     ILIKE = 1841,
     FILLFACTOR = 1844,
     TIME = 1849,
     KW_TODAY = 1856,
     KW_ROWID = 1857,
     TIMESTAMP = 2205,
     SET_TEXT_FORMAT = 2217,
     KW_TAG = 2227,
     LINTMODULEISLIBRARY = 2228,
     KW_PUBLIC = 2229,
     KW_PRIVATE = 2230,
     COPYBACK = 2231,
     REFERENCES_BLOBTYPE_DEFAULT_NULL = 2232,
     REFERENCES_BLOBTYPE = 2233,
     SORT = 2234,
     KWPIPE = 2235,
     KW_DONE = 2236,
     END_TODO = 2237,
     KW_TODO = 2238,
     KW_ALWAYS = 2239,
     PROGRAM_TIMEOUT = 2240,
     USING_SQLTYPE = 2241,
     KW_OBJECT = 2242
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
#define XSET_MULTIPLY_EQUAL_OPEN_BRACKET 1171
#define XSET_ident_DOT_MULTIPLY_EQUAL_OPEN_BRACKET 1172
#define XSET_ident_DOT_MULTIPLY_EQUAL 1173
#define XSET_MULTIPLY_EQUAL 1174
#define XSET_OPEN_BRACKET 1175
#define CREATE_DATABASE 1178
#define DROP_DATABASE 1179
#define ADD_CONSTRAINT 1181
#define DROP_CONSTRAINT 1182
#define DROP_SYNONYM 1183
#define CONSTRAINT 1184
#define NOT_FIELD_TOUCHED_CURRENT 1187
#define FIELD_TOUCHED_CURRENT 1188
#define OBJECT_FUNCTION 1190
#define DOUBLE_PRECISION 1196
#define COUNT_MULTIPLY 1197
#define MODIFY_NEXT_SIZE 1217
#define LOCK_MODE_PAGE 1218
#define LOCK_MODE_ROW 1219
#define UNITS_YEAR 1226
#define UNITS_MONTH 1227
#define UNITS_DAY 1228
#define UNITS_HOUR 1229
#define UNITS_MINUTE 1230
#define UNITS_SECOND 1231
#define TO_CLUSTER 1236
#define TO_NOT_CLUSTER 1237
#define CREATE_UC_IDX 1239
#define CREATE_U_IDX 1240
#define CREATE_C_IDX 1241
#define CREATE_IDX 1242
#define DOUBLE_COLON 1252
#define SQLSICS 1258
#define CREATE_SCHEMA 1259
#define SQLSIRR 1260
#define UPDATESTATS_T 1261
#define SQLSICR 1262
#define SQLSIDR 1273
#define CREATE_TEMP_TABLE 1274
#define WITH_CHECK_OPTION 1282
#define WITH_GRANT_OPTION 1283
#define SQLSLMNW 1284
#define WHERE_CURRENT_OF 1290
#define NOT_NULL_UNIQUE 1298
#define SQLSLMW 1305
#define ALL_PRIVILEGES 1307
#define CREATE_SYNONYM 1311
#define DROP_TABLE 1312
#define INEXCLUSIVE 1314
#define UPDATESTATS 1319
#define CREATE_TABLE 1345
#define DEFAULT_NULL 1346
#define DEFAULT_TODAY 1347
#define DEFAULT_USER 1348
#define EXIT_TODO 1355
#define CONTINUE_TODO 1356
#define UNLOCK_TABLE 1363
#define ROLLBACK_W 1371
#define SQLSEON 1373
#define SQLSEOFF 1374
#define CREATE_VIEW 1378
#define DELETE_FROM 1379
#define EXTENT_SIZE 1386
#define FOREIGN_KEY 1387
#define INSERT_INTO 1390
#define IS_NOT_NULL 1392
#define NOT_MATCHES 1395
#define PRIMARY_KEY 1401
#define WITH_NO_LOG 1408
#define INSHARE 1411
#define BEGIN_WORK 1417
#define DROP_INDEX 1422
#define FOR_UPDATE_OF 1428
#define FOR_UPDATE 1429
#define LOCK_TABLE 1434
#define NOT_EXISTS 1436
#define REFERENCES 1438
#define RENCOL 1439
#define SMALLFLOAT 1441
#define COMMIT_W 1452
#define RENTAB 1459
#define KW_CHAR 1462
#define NCHAR 1463
#define NVARCHAR 1464
#define DELIMITER 1466
#define DROP_VIEW 1468
#define EXCLUSIVE 1471
#define GREATER_THAN_EQ 1475
#define INTO_TEMP 1477
#define DATABASE 1501
#define DATETIME 1502
#define DISTINCT 1504
#define FRACTION 1511
#define GROUP_BY 1513
#define INTERVAL 1514
#define NOT_LIKE 1516
#define NOT_ILIKE 1517
#define NOT_NULL 1518
#define RESOURCE 1524
#define SMALLINT 1525
#define IS_NULL 1531
#define LESS_THAN_EQ 1532
#define BETWEEN 1534
#define CLOSE_BRACKET 1537
#define CONNECT 1540
#define KW_CURRENT 1541
#define KW_DECIMAL 1543
#define DEFAULT 1545
#define INTEGER 1553
#define SERIAL8 1555
#define MATCHES 1558
#define VARCHAR 1571
#define CLOSE_SQUARE 1574
#define GREATER_THAN 1575
#define KW_FALSE 1576
#define NOT_IN 1577
#define OPEN_BRACKET 1579
#define KW_DELETE 1587
#define KW_ESCAPE 1590
#define EXISTS 1591
#define EXTEND 1592
#define HAVING 1596
#define KW_INSERT 1598
#define MINUTE 1602
#define MODIFY 1603
#define EQUAL 1605
#define NOT_EQUAL 1606
#define OPEN_SQUARE 1608
#define PUBLIC 1612
#define KW_RETURN_KEY 1615
#define REVOKE 1617
#define SECOND 1621
#define KW_SELECT 1625
#define SERIAL 1626
#define UNIQUE 1629
#define KW_UPDATE 1631
#define VALUES 1632
#define KW_NULL 1635
#define KW_TRUE 1636
#define ALTER 1638
#define CHECK 1644
#define COUNT 1648
#define KW_FIRST 1653
#define KW_FLOAT 1654
#define GRANT 1657
#define INDEX 1660
#define LESS_THAN 1663
#define MONEY 1665
#define MONTH 1666
#define KW_MULTIPLY 1668
#define ORDER 1669
#define OUTER 1670
#define UNION 1679
#define WHERE 1682
#define KW_BYTE 1689
#define CASE 1691
#define KW_DATE 1693
#define DESC 1694
#define KW_DIVIDE 1695
#define DROP 1698
#define ELSE 1699
#define FROM 1703
#define HOUR 1709
#define INTO 1710
#define LIKE 1713
#define REAL 1722
#define SOME 1727
#define KW_TEXT 1731
#define KW_THEN 1732
#define USER 1733
#define WHEN 1735
#define YEAR 1738
#define KW_DOW 1739
#define XSET 1741
#define ADD 1742
#define ALL 1743
#define KW_AND 1744
#define ANY 1745
#define ASC 1746
#define AVG 1747
#define COLON 1748
#define KW_COMMA 1749
#define DAY 1750
#define DBA 1751
#define KW_FOR 1755
#define XMAX 1760
#define XMIN 1761
#define KW_MINUS 1762
#define KW_MOD 1763
#define KW_NOT 1764
#define KW_SUM 1771
#define ATSIGN 1774
#define KW_PLUS 1775
#define KW_AS 1781
#define KW_BY 1783
#define KW_DOT 1784
#define KW_IN 1787
#define KW_ON 1789
#define KW_OR 1790
#define KW_TO 1791
#define BEFORE 1829
#define END 1833
#define TILDE 1840
#define ILIKE 1841
#define FILLFACTOR 1844
#define TIME 1849
#define KW_TODAY 1856
#define KW_ROWID 1857
#define TIMESTAMP 2205
#define SET_TEXT_FORMAT 2217
#define KW_TAG 2227
#define LINTMODULEISLIBRARY 2228
#define KW_PUBLIC 2229
#define KW_PRIVATE 2230
#define COPYBACK 2231
#define REFERENCES_BLOBTYPE_DEFAULT_NULL 2232
#define REFERENCES_BLOBTYPE 2233
#define SORT 2234
#define KWPIPE 2235
#define KW_DONE 2236
#define END_TODO 2237
#define KW_TODO 2238
#define KW_ALWAYS 2239
#define PROGRAM_TIMEOUT 2240
#define USING_SQLTYPE 2241
#define KW_OBJECT 2242




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
#line 660 "y.tab.h"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE sqlparse_yylval;


