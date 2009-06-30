
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
     INT_VALUE = 2208,
     NAMED = 2209,
     NAMED_GEN = 2210,
     CHAR_VALUE = 2211,
     NOT_USED_1 = 2212,
     NOT_USED_2 = 2213,
     NOT_USED_3 = 2214,
     NOT_USED_4 = 2215,
     NOT_USED_5 = 2216,
     NOT_USED_6 = 2217,
     NOT_USED_7 = 2218,
     NOT_USED_8 = 2219,
     NUMBER_VALUE = 2220,
     SEMICOLON = 2221,
     QUESTION_MARK = 2222,
     CLINE = 2223,
     CH = 2224,
     MARK_VAR = 2225,
     END_MARK_VAR = 2226,
     LEFT_JOIN = 1002,
     DISPLAY_NULL_TO = 1005,
     ON_CHANGE = 1006,
     INNER_JOIN = 1007,
     UI_INTERFACE_DOT_FRONTCALL = 1010,
     USING_BTREE = 1031,
     USING_RTREE = 1032,
     SET_BUFFERED_LOG = 1057,
     SET_LOG = 1060,
     MDY = 1062,
     WEEKDAY = 1063,
     MODE_ANSI = 1066,
     START_DATABASE = 1067,
     WITH_LOG_IN = 1068,
     SET_CONSTRAINTS_ALL_IMMEDIATE = 1069,
     DATETIME_VALUE = 1082,
     INTERVAL_VALUE = 1083,
     RECOVER_TABLE = 1084,
     ROLLFORWARD_DATABASE = 1085,
     DROP_TRIGGER = 1101,
     DROP_AUDIT_FOR = 1102,
     CREATE_AUDIT_FOR = 1103,
     EXECUTE_PROCEDURE = 1107,
     ALTER_TABLE = 1114,
     ALTER_INDEX = 1115,
     NEXT_SIZE = 1116,
     XSET_MULTIPLY_EQUAL_OPEN_BRACKET = 1153,
     XSET_ident_DOT_MULTIPLY_EQUAL_OPEN_BRACKET = 1154,
     XSET_ident_DOT_MULTIPLY_EQUAL = 1155,
     XSET_MULTIPLY_EQUAL = 1156,
     XSET_OPEN_BRACKET = 1157,
     CREATE_DATABASE = 1160,
     DROP_DATABASE = 1161,
     ADD_CONSTRAINT = 1163,
     DROP_CONSTRAINT = 1164,
     DROP_SYNONYM = 1165,
     CONSTRAINT = 1166,
     NOT_FIELD_TOUCHED_CURRENT = 1169,
     FIELD_TOUCHED_CURRENT = 1170,
     DOUBLE_PRECISION = 1177,
     COUNT_MULTIPLY = 1178,
     MODIFY_NEXT_SIZE = 1198,
     LOCK_MODE_PAGE = 1199,
     LOCK_MODE_ROW = 1200,
     UNITS_YEAR = 1207,
     UNITS_MONTH = 1208,
     UNITS_DAY = 1209,
     UNITS_HOUR = 1210,
     UNITS_MINUTE = 1211,
     UNITS_SECOND = 1212,
     TO_CLUSTER = 1217,
     TO_NOT_CLUSTER = 1218,
     CREATE_UC_IDX = 1220,
     CREATE_U_IDX = 1221,
     CREATE_C_IDX = 1222,
     CREATE_IDX = 1223,
     DOUBLE_COLON = 1233,
     SQLSICS = 1239,
     CREATE_SCHEMA = 1240,
     SQLSIRR = 1241,
     UPDATESTATS_T = 1242,
     SQLSICR = 1243,
     SQLSIDR = 1254,
     CREATE_TEMP_TABLE = 1255,
     WITH_CHECK_OPTION = 1263,
     WITH_GRANT_OPTION = 1264,
     SQLSLMNW = 1265,
     WHERE_CURRENT_OF = 1271,
     NOT_NULL_UNIQUE = 1279,
     SQLSLMW = 1286,
     ALL_PRIVILEGES = 1288,
     CREATE_SYNONYM = 1292,
     DROP_TABLE = 1293,
     INEXCLUSIVE = 1295,
     UPDATESTATS = 1300,
     CREATE_TABLE = 1326,
     DEFAULT_NULL = 1327,
     DEFAULT_TODAY = 1328,
     DEFAULT_USER = 1329,
     UNLOCK_TABLE = 1342,
     ROLLBACK_W = 1350,
     SQLSEON = 1352,
     SQLSEOFF = 1353,
     CREATE_VIEW = 1357,
     DELETE_FROM = 1358,
     EXTENT_SIZE = 1365,
     FOREIGN_KEY = 1366,
     INSERT_INTO = 1369,
     IS_NOT_NULL = 1371,
     NOT_MATCHES = 1374,
     PRIMARY_KEY = 1380,
     USE_SESSION = 1387,
     WITH_NO_LOG = 1388,
     INSHARE = 1391,
     BEGIN_WORK = 1397,
     DROP_INDEX = 1402,
     FOR_UPDATE_OF = 1408,
     FOR_UPDATE = 1409,
     LOCK_TABLE = 1414,
     NOT_EXISTS = 1416,
     REFERENCES = 1418,
     RENCOL = 1419,
     SMALLFLOAT = 1421,
     COMMIT_W = 1432,
     RENTAB = 1439,
     KW_CHAR = 1442,
     NCHAR = 1443,
     NVARCHAR = 1444,
     DELIMITER = 1446,
     DROP_VIEW = 1448,
     EXCLUSIVE = 1451,
     GREATER_THAN_EQ = 1455,
     INTO_TEMP = 1457,
     DATABASE = 1481,
     DATETIME = 1482,
     DISTINCT = 1484,
     FRACTION = 1491,
     GROUP_BY = 1493,
     INTERVAL = 1494,
     NOT_LIKE = 1496,
     NOT_ILIKE = 1497,
     NOT_NULL = 1498,
     RESOURCE = 1504,
     SMALLINT = 1505,
     IS_NULL = 1511,
     LESS_THAN_EQ = 1512,
     BETWEEN = 1514,
     CLOSE_BRACKET = 1517,
     CONNECT = 1520,
     KW_CURRENT = 1521,
     KW_DECIMAL = 1523,
     DEFAULT = 1525,
     INTEGER = 1533,
     SERIAL8 = 1535,
     MATCHES = 1538,
     VARCHAR = 1551,
     CLOSE_SQUARE = 1554,
     GREATER_THAN = 1555,
     KW_FALSE = 1556,
     NOT_IN = 1557,
     OPEN_BRACKET = 1559,
     KW_DELETE = 1567,
     KW_ESCAPE = 1570,
     EXISTS = 1571,
     EXTEND = 1572,
     HAVING = 1576,
     KW_INSERT = 1578,
     MINUTE = 1582,
     MODIFY = 1583,
     EQUAL = 1585,
     NOT_EQUAL = 1586,
     OPEN_SQUARE = 1588,
     PUBLIC = 1592,
     REVOKE = 1596,
     SECOND = 1600,
     KW_SELECT = 1604,
     SERIAL = 1605,
     UNIQUE = 1608,
     KW_UPDATE = 1610,
     VALUES = 1611,
     KW_NULL = 1614,
     KW_TRUE = 1615,
     ALTER = 1617,
     CHECK = 1623,
     COUNT = 1627,
     KW_FIRST = 1632,
     KW_FLOAT = 1633,
     GRANT = 1636,
     INDEX = 1639,
     LESS_THAN = 1642,
     MONEY = 1644,
     MONTH = 1645,
     KW_MULTIPLY = 1647,
     ORDER = 1648,
     OUTER = 1649,
     UNION = 1658,
     WHERE = 1661,
     KW_BYTE = 1668,
     CASE = 1670,
     KW_DATE = 1672,
     DESC = 1673,
     KW_DIVIDE = 1674,
     DROP = 1677,
     ELSE = 1678,
     FROM = 1682,
     HOUR = 1688,
     INTO = 1689,
     LIKE = 1692,
     REAL = 1701,
     SOME = 1706,
     KW_TEXT = 1710,
     KW_THEN = 1711,
     USER = 1712,
     WHEN = 1714,
     YEAR = 1717,
     KW_DOW = 1718,
     XSET = 1720,
     ADD = 1721,
     ALL = 1722,
     KW_AND = 1723,
     ANY = 1724,
     ASC = 1725,
     AVG = 1726,
     COLON = 1727,
     KW_COMMA = 1728,
     DAY = 1729,
     DBA = 1730,
     KW_FOR = 1734,
     XMAX = 1739,
     XMIN = 1740,
     KW_MINUS = 1741,
     KW_MOD = 1742,
     KW_NOT = 1743,
     KW_SUM = 1750,
     ATSIGN = 1753,
     KW_PLUS = 1754,
     KW_AS = 1760,
     KW_BY = 1762,
     KW_DOT = 1763,
     KW_IN = 1766,
     KW_ON = 1768,
     KW_OR = 1769,
     KW_TO = 1770,
     BEFORE = 1808,
     END = 1812,
     TILDE = 1819,
     ILIKE = 1820,
     FILLFACTOR = 1823,
     TIME = 1828,
     KW_TODAY = 1835,
     KW_ROWID = 1836,
     TIMESTAMP = 2184,
     KW_TAG = 2205,
     LINTMODULEISLIBRARY = 2206
   };
#endif
/* Tokens.  */
#define INT_VALUE 2208
#define NAMED 2209
#define NAMED_GEN 2210
#define CHAR_VALUE 2211
#define NOT_USED_1 2212
#define NOT_USED_2 2213
#define NOT_USED_3 2214
#define NOT_USED_4 2215
#define NOT_USED_5 2216
#define NOT_USED_6 2217
#define NOT_USED_7 2218
#define NOT_USED_8 2219
#define NUMBER_VALUE 2220
#define SEMICOLON 2221
#define QUESTION_MARK 2222
#define CLINE 2223
#define CH 2224
#define MARK_VAR 2225
#define END_MARK_VAR 2226
#define LEFT_JOIN 1002
#define DISPLAY_NULL_TO 1005
#define ON_CHANGE 1006
#define INNER_JOIN 1007
#define UI_INTERFACE_DOT_FRONTCALL 1010
#define USING_BTREE 1031
#define USING_RTREE 1032
#define SET_BUFFERED_LOG 1057
#define SET_LOG 1060
#define MDY 1062
#define WEEKDAY 1063
#define MODE_ANSI 1066
#define START_DATABASE 1067
#define WITH_LOG_IN 1068
#define SET_CONSTRAINTS_ALL_IMMEDIATE 1069
#define DATETIME_VALUE 1082
#define INTERVAL_VALUE 1083
#define RECOVER_TABLE 1084
#define ROLLFORWARD_DATABASE 1085
#define DROP_TRIGGER 1101
#define DROP_AUDIT_FOR 1102
#define CREATE_AUDIT_FOR 1103
#define EXECUTE_PROCEDURE 1107
#define ALTER_TABLE 1114
#define ALTER_INDEX 1115
#define NEXT_SIZE 1116
#define XSET_MULTIPLY_EQUAL_OPEN_BRACKET 1153
#define XSET_ident_DOT_MULTIPLY_EQUAL_OPEN_BRACKET 1154
#define XSET_ident_DOT_MULTIPLY_EQUAL 1155
#define XSET_MULTIPLY_EQUAL 1156
#define XSET_OPEN_BRACKET 1157
#define CREATE_DATABASE 1160
#define DROP_DATABASE 1161
#define ADD_CONSTRAINT 1163
#define DROP_CONSTRAINT 1164
#define DROP_SYNONYM 1165
#define CONSTRAINT 1166
#define NOT_FIELD_TOUCHED_CURRENT 1169
#define FIELD_TOUCHED_CURRENT 1170
#define DOUBLE_PRECISION 1177
#define COUNT_MULTIPLY 1178
#define MODIFY_NEXT_SIZE 1198
#define LOCK_MODE_PAGE 1199
#define LOCK_MODE_ROW 1200
#define UNITS_YEAR 1207
#define UNITS_MONTH 1208
#define UNITS_DAY 1209
#define UNITS_HOUR 1210
#define UNITS_MINUTE 1211
#define UNITS_SECOND 1212
#define TO_CLUSTER 1217
#define TO_NOT_CLUSTER 1218
#define CREATE_UC_IDX 1220
#define CREATE_U_IDX 1221
#define CREATE_C_IDX 1222
#define CREATE_IDX 1223
#define DOUBLE_COLON 1233
#define SQLSICS 1239
#define CREATE_SCHEMA 1240
#define SQLSIRR 1241
#define UPDATESTATS_T 1242
#define SQLSICR 1243
#define SQLSIDR 1254
#define CREATE_TEMP_TABLE 1255
#define WITH_CHECK_OPTION 1263
#define WITH_GRANT_OPTION 1264
#define SQLSLMNW 1265
#define WHERE_CURRENT_OF 1271
#define NOT_NULL_UNIQUE 1279
#define SQLSLMW 1286
#define ALL_PRIVILEGES 1288
#define CREATE_SYNONYM 1292
#define DROP_TABLE 1293
#define INEXCLUSIVE 1295
#define UPDATESTATS 1300
#define CREATE_TABLE 1326
#define DEFAULT_NULL 1327
#define DEFAULT_TODAY 1328
#define DEFAULT_USER 1329
#define UNLOCK_TABLE 1342
#define ROLLBACK_W 1350
#define SQLSEON 1352
#define SQLSEOFF 1353
#define CREATE_VIEW 1357
#define DELETE_FROM 1358
#define EXTENT_SIZE 1365
#define FOREIGN_KEY 1366
#define INSERT_INTO 1369
#define IS_NOT_NULL 1371
#define NOT_MATCHES 1374
#define PRIMARY_KEY 1380
#define USE_SESSION 1387
#define WITH_NO_LOG 1388
#define INSHARE 1391
#define BEGIN_WORK 1397
#define DROP_INDEX 1402
#define FOR_UPDATE_OF 1408
#define FOR_UPDATE 1409
#define LOCK_TABLE 1414
#define NOT_EXISTS 1416
#define REFERENCES 1418
#define RENCOL 1419
#define SMALLFLOAT 1421
#define COMMIT_W 1432
#define RENTAB 1439
#define KW_CHAR 1442
#define NCHAR 1443
#define NVARCHAR 1444
#define DELIMITER 1446
#define DROP_VIEW 1448
#define EXCLUSIVE 1451
#define GREATER_THAN_EQ 1455
#define INTO_TEMP 1457
#define DATABASE 1481
#define DATETIME 1482
#define DISTINCT 1484
#define FRACTION 1491
#define GROUP_BY 1493
#define INTERVAL 1494
#define NOT_LIKE 1496
#define NOT_ILIKE 1497
#define NOT_NULL 1498
#define RESOURCE 1504
#define SMALLINT 1505
#define IS_NULL 1511
#define LESS_THAN_EQ 1512
#define BETWEEN 1514
#define CLOSE_BRACKET 1517
#define CONNECT 1520
#define KW_CURRENT 1521
#define KW_DECIMAL 1523
#define DEFAULT 1525
#define INTEGER 1533
#define SERIAL8 1535
#define MATCHES 1538
#define VARCHAR 1551
#define CLOSE_SQUARE 1554
#define GREATER_THAN 1555
#define KW_FALSE 1556
#define NOT_IN 1557
#define OPEN_BRACKET 1559
#define KW_DELETE 1567
#define KW_ESCAPE 1570
#define EXISTS 1571
#define EXTEND 1572
#define HAVING 1576
#define KW_INSERT 1578
#define MINUTE 1582
#define MODIFY 1583
#define EQUAL 1585
#define NOT_EQUAL 1586
#define OPEN_SQUARE 1588
#define PUBLIC 1592
#define REVOKE 1596
#define SECOND 1600
#define KW_SELECT 1604
#define SERIAL 1605
#define UNIQUE 1608
#define KW_UPDATE 1610
#define VALUES 1611
#define KW_NULL 1614
#define KW_TRUE 1615
#define ALTER 1617
#define CHECK 1623
#define COUNT 1627
#define KW_FIRST 1632
#define KW_FLOAT 1633
#define GRANT 1636
#define INDEX 1639
#define LESS_THAN 1642
#define MONEY 1644
#define MONTH 1645
#define KW_MULTIPLY 1647
#define ORDER 1648
#define OUTER 1649
#define UNION 1658
#define WHERE 1661
#define KW_BYTE 1668
#define CASE 1670
#define KW_DATE 1672
#define DESC 1673
#define KW_DIVIDE 1674
#define DROP 1677
#define ELSE 1678
#define FROM 1682
#define HOUR 1688
#define INTO 1689
#define LIKE 1692
#define REAL 1701
#define SOME 1706
#define KW_TEXT 1710
#define KW_THEN 1711
#define USER 1712
#define WHEN 1714
#define YEAR 1717
#define KW_DOW 1718
#define XSET 1720
#define ADD 1721
#define ALL 1722
#define KW_AND 1723
#define ANY 1724
#define ASC 1725
#define AVG 1726
#define COLON 1727
#define KW_COMMA 1728
#define DAY 1729
#define DBA 1730
#define KW_FOR 1734
#define XMAX 1739
#define XMIN 1740
#define KW_MINUS 1741
#define KW_MOD 1742
#define KW_NOT 1743
#define KW_SUM 1750
#define ATSIGN 1753
#define KW_PLUS 1754
#define KW_AS 1760
#define KW_BY 1762
#define KW_DOT 1763
#define KW_IN 1766
#define KW_ON 1768
#define KW_OR 1769
#define KW_TO 1770
#define BEFORE 1808
#define END 1812
#define TILDE 1819
#define ILIKE 1820
#define FILLFACTOR 1823
#define TIME 1828
#define KW_TODAY 1835
#define KW_ROWID 1836
#define TIMESTAMP 2184
#define KW_TAG 2205
#define LINTMODULEISLIBRARY 2206




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
#line 587 "y.tab.h"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE sqlparse_yylval;


