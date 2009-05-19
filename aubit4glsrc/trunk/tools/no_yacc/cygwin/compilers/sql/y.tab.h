
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
     INT_VALUE = 2205,
     NAMED = 2206,
     NAMED_GEN = 2207,
     CHAR_VALUE = 2208,
     NOT_USED_1 = 2209,
     NOT_USED_2 = 2210,
     NOT_USED_3 = 2211,
     NOT_USED_4 = 2212,
     NOT_USED_5 = 2213,
     NOT_USED_6 = 2214,
     NOT_USED_7 = 2215,
     NOT_USED_8 = 2216,
     NUMBER_VALUE = 2217,
     SEMICOLON = 2218,
     QUESTION_MARK = 2219,
     CLINE = 2220,
     CH = 2221,
     MARK_VAR = 2222,
     END_MARK_VAR = 2223,
     LEFT_JOIN = 1002,
     INNER_JOIN = 1005,
     USING_BTREE = 1028,
     USING_RTREE = 1029,
     SET_BUFFERED_LOG = 1054,
     SET_LOG = 1057,
     MDY = 1059,
     WEEKDAY = 1060,
     MODE_ANSI = 1063,
     START_DATABASE = 1064,
     WITH_LOG_IN = 1065,
     SET_CONSTRAINTS_ALL_IMMEDIATE = 1066,
     DATETIME_VALUE = 1079,
     INTERVAL_VALUE = 1080,
     RECOVER_TABLE = 1081,
     ROLLFORWARD_DATABASE = 1082,
     DROP_TRIGGER = 1098,
     DROP_AUDIT_FOR = 1099,
     CREATE_AUDIT_FOR = 1100,
     EXECUTE_PROCEDURE = 1104,
     ALTER_TABLE = 1111,
     ALTER_INDEX = 1112,
     NEXT_SIZE = 1113,
     XSET_MULTIPLY_EQUAL_OPEN_BRACKET = 1150,
     XSET_ident_DOT_MULTIPLY_EQUAL_OPEN_BRACKET = 1151,
     XSET_ident_DOT_MULTIPLY_EQUAL = 1152,
     XSET_MULTIPLY_EQUAL = 1153,
     XSET_OPEN_BRACKET = 1154,
     CREATE_DATABASE = 1157,
     DROP_DATABASE = 1158,
     ADD_CONSTRAINT = 1160,
     DROP_CONSTRAINT = 1161,
     DROP_SYNONYM = 1162,
     CONSTRAINT = 1163,
     NOT_FIELD_TOUCHED_CURRENT = 1166,
     FIELD_TOUCHED_CURRENT = 1167,
     DOUBLE_PRECISION = 1174,
     COUNT_MULTIPLY = 1175,
     MODIFY_NEXT_SIZE = 1195,
     LOCK_MODE_PAGE = 1196,
     LOCK_MODE_ROW = 1197,
     UNITS_YEAR = 1204,
     UNITS_MONTH = 1205,
     UNITS_DAY = 1206,
     UNITS_HOUR = 1207,
     UNITS_MINUTE = 1208,
     UNITS_SECOND = 1209,
     TO_CLUSTER = 1214,
     TO_NOT_CLUSTER = 1215,
     CREATE_UC_IDX = 1217,
     CREATE_U_IDX = 1218,
     CREATE_C_IDX = 1219,
     CREATE_IDX = 1220,
     DOUBLE_COLON = 1230,
     SQLSICS = 1236,
     CREATE_SCHEMA = 1237,
     SQLSIRR = 1238,
     UPDATESTATS_T = 1239,
     SQLSICR = 1240,
     SQLSIDR = 1251,
     CREATE_TEMP_TABLE = 1252,
     WITH_CHECK_OPTION = 1260,
     WITH_GRANT_OPTION = 1261,
     SQLSLMNW = 1262,
     WHERE_CURRENT_OF = 1268,
     NOT_NULL_UNIQUE = 1276,
     SQLSLMW = 1283,
     ALL_PRIVILEGES = 1285,
     CREATE_SYNONYM = 1289,
     DROP_TABLE = 1290,
     INEXCLUSIVE = 1292,
     UPDATESTATS = 1297,
     CREATE_TABLE = 1323,
     DEFAULT_NULL = 1324,
     DEFAULT_TODAY = 1325,
     DEFAULT_USER = 1326,
     UNLOCK_TABLE = 1339,
     ROLLBACK_W = 1347,
     SQLSEON = 1349,
     SQLSEOFF = 1350,
     CREATE_VIEW = 1354,
     DELETE_FROM = 1355,
     EXTENT_SIZE = 1362,
     FOREIGN_KEY = 1363,
     INSERT_INTO = 1366,
     IS_NOT_NULL = 1368,
     NOT_MATCHES = 1371,
     PRIMARY_KEY = 1377,
     USE_SESSION = 1384,
     WITH_NO_LOG = 1385,
     INSHARE = 1388,
     BEGIN_WORK = 1394,
     DROP_INDEX = 1399,
     FOR_UPDATE_OF = 1405,
     FOR_UPDATE = 1406,
     LOCK_TABLE = 1411,
     NOT_EXISTS = 1413,
     REFERENCES = 1415,
     RENCOL = 1416,
     SMALLFLOAT = 1418,
     COMMIT_W = 1429,
     RENTAB = 1436,
     KW_CHAR = 1439,
     NCHAR = 1440,
     NVARCHAR = 1441,
     DELIMITER = 1443,
     DROP_VIEW = 1445,
     EXCLUSIVE = 1448,
     GREATER_THAN_EQ = 1452,
     INTO_TEMP = 1454,
     DATABASE = 1478,
     DATETIME = 1479,
     DISTINCT = 1481,
     FRACTION = 1488,
     GROUP_BY = 1490,
     INTERVAL = 1491,
     NOT_LIKE = 1493,
     NOT_ILIKE = 1494,
     NOT_NULL = 1495,
     RESOURCE = 1501,
     SMALLINT = 1502,
     IS_NULL = 1508,
     LESS_THAN_EQ = 1509,
     BETWEEN = 1511,
     CLOSE_BRACKET = 1514,
     CONNECT = 1517,
     KW_CURRENT = 1518,
     KW_DECIMAL = 1520,
     DEFAULT = 1522,
     INTEGER = 1530,
     SERIAL8 = 1532,
     MATCHES = 1535,
     VARCHAR = 1548,
     CLOSE_SQUARE = 1551,
     GREATER_THAN = 1552,
     KW_FALSE = 1553,
     NOT_IN = 1554,
     OPEN_BRACKET = 1556,
     KW_DELETE = 1564,
     KW_ESCAPE = 1567,
     EXISTS = 1568,
     EXTEND = 1569,
     HAVING = 1573,
     KW_INSERT = 1575,
     MINUTE = 1579,
     MODIFY = 1580,
     EQUAL = 1582,
     NOT_EQUAL = 1583,
     OPEN_SQUARE = 1585,
     PUBLIC = 1589,
     REVOKE = 1593,
     SECOND = 1597,
     KW_SELECT = 1601,
     SERIAL = 1602,
     UNIQUE = 1605,
     KW_UPDATE = 1607,
     VALUES = 1608,
     KW_NULL = 1611,
     KW_TRUE = 1612,
     ALTER = 1614,
     CHECK = 1620,
     COUNT = 1624,
     KW_FIRST = 1629,
     KW_FLOAT = 1630,
     GRANT = 1633,
     INDEX = 1636,
     LESS_THAN = 1639,
     MONEY = 1641,
     MONTH = 1642,
     KW_MULTIPLY = 1644,
     ORDER = 1645,
     OUTER = 1646,
     UNION = 1655,
     WHERE = 1658,
     KW_BYTE = 1665,
     CASE = 1667,
     KW_DATE = 1669,
     DESC = 1670,
     KW_DIVIDE = 1671,
     DROP = 1674,
     ELSE = 1675,
     FROM = 1679,
     HOUR = 1685,
     INTO = 1686,
     LIKE = 1689,
     REAL = 1698,
     SOME = 1703,
     KW_TEXT = 1707,
     KW_THEN = 1708,
     USER = 1709,
     WHEN = 1711,
     YEAR = 1714,
     KW_DOW = 1715,
     XSET = 1717,
     ADD = 1718,
     ALL = 1719,
     KW_AND = 1720,
     ANY = 1721,
     ASC = 1722,
     AVG = 1723,
     COLON = 1724,
     KW_COMMA = 1725,
     DAY = 1726,
     DBA = 1727,
     KW_FOR = 1731,
     XMAX = 1736,
     XMIN = 1737,
     KW_MINUS = 1738,
     KW_MOD = 1739,
     KW_NOT = 1740,
     KW_SUM = 1747,
     ATSIGN = 1750,
     KW_PLUS = 1751,
     KW_AS = 1757,
     KW_BY = 1759,
     KW_DOT = 1760,
     KW_IN = 1763,
     KW_ON = 1765,
     KW_OR = 1766,
     KW_TO = 1767,
     BEFORE = 1805,
     END = 1809,
     TILDE = 1816,
     ILIKE = 1817,
     FILLFACTOR = 1820,
     TIME = 1825,
     KW_TODAY = 1832,
     KW_ROWID = 1833,
     TIMESTAMP = 2181,
     KW_TAG = 2202,
     LINTMODULEISLIBRARY = 2203
   };
#endif
/* Tokens.  */
#define INT_VALUE 2205
#define NAMED 2206
#define NAMED_GEN 2207
#define CHAR_VALUE 2208
#define NOT_USED_1 2209
#define NOT_USED_2 2210
#define NOT_USED_3 2211
#define NOT_USED_4 2212
#define NOT_USED_5 2213
#define NOT_USED_6 2214
#define NOT_USED_7 2215
#define NOT_USED_8 2216
#define NUMBER_VALUE 2217
#define SEMICOLON 2218
#define QUESTION_MARK 2219
#define CLINE 2220
#define CH 2221
#define MARK_VAR 2222
#define END_MARK_VAR 2223
#define LEFT_JOIN 1002
#define INNER_JOIN 1005
#define USING_BTREE 1028
#define USING_RTREE 1029
#define SET_BUFFERED_LOG 1054
#define SET_LOG 1057
#define MDY 1059
#define WEEKDAY 1060
#define MODE_ANSI 1063
#define START_DATABASE 1064
#define WITH_LOG_IN 1065
#define SET_CONSTRAINTS_ALL_IMMEDIATE 1066
#define DATETIME_VALUE 1079
#define INTERVAL_VALUE 1080
#define RECOVER_TABLE 1081
#define ROLLFORWARD_DATABASE 1082
#define DROP_TRIGGER 1098
#define DROP_AUDIT_FOR 1099
#define CREATE_AUDIT_FOR 1100
#define EXECUTE_PROCEDURE 1104
#define ALTER_TABLE 1111
#define ALTER_INDEX 1112
#define NEXT_SIZE 1113
#define XSET_MULTIPLY_EQUAL_OPEN_BRACKET 1150
#define XSET_ident_DOT_MULTIPLY_EQUAL_OPEN_BRACKET 1151
#define XSET_ident_DOT_MULTIPLY_EQUAL 1152
#define XSET_MULTIPLY_EQUAL 1153
#define XSET_OPEN_BRACKET 1154
#define CREATE_DATABASE 1157
#define DROP_DATABASE 1158
#define ADD_CONSTRAINT 1160
#define DROP_CONSTRAINT 1161
#define DROP_SYNONYM 1162
#define CONSTRAINT 1163
#define NOT_FIELD_TOUCHED_CURRENT 1166
#define FIELD_TOUCHED_CURRENT 1167
#define DOUBLE_PRECISION 1174
#define COUNT_MULTIPLY 1175
#define MODIFY_NEXT_SIZE 1195
#define LOCK_MODE_PAGE 1196
#define LOCK_MODE_ROW 1197
#define UNITS_YEAR 1204
#define UNITS_MONTH 1205
#define UNITS_DAY 1206
#define UNITS_HOUR 1207
#define UNITS_MINUTE 1208
#define UNITS_SECOND 1209
#define TO_CLUSTER 1214
#define TO_NOT_CLUSTER 1215
#define CREATE_UC_IDX 1217
#define CREATE_U_IDX 1218
#define CREATE_C_IDX 1219
#define CREATE_IDX 1220
#define DOUBLE_COLON 1230
#define SQLSICS 1236
#define CREATE_SCHEMA 1237
#define SQLSIRR 1238
#define UPDATESTATS_T 1239
#define SQLSICR 1240
#define SQLSIDR 1251
#define CREATE_TEMP_TABLE 1252
#define WITH_CHECK_OPTION 1260
#define WITH_GRANT_OPTION 1261
#define SQLSLMNW 1262
#define WHERE_CURRENT_OF 1268
#define NOT_NULL_UNIQUE 1276
#define SQLSLMW 1283
#define ALL_PRIVILEGES 1285
#define CREATE_SYNONYM 1289
#define DROP_TABLE 1290
#define INEXCLUSIVE 1292
#define UPDATESTATS 1297
#define CREATE_TABLE 1323
#define DEFAULT_NULL 1324
#define DEFAULT_TODAY 1325
#define DEFAULT_USER 1326
#define UNLOCK_TABLE 1339
#define ROLLBACK_W 1347
#define SQLSEON 1349
#define SQLSEOFF 1350
#define CREATE_VIEW 1354
#define DELETE_FROM 1355
#define EXTENT_SIZE 1362
#define FOREIGN_KEY 1363
#define INSERT_INTO 1366
#define IS_NOT_NULL 1368
#define NOT_MATCHES 1371
#define PRIMARY_KEY 1377
#define USE_SESSION 1384
#define WITH_NO_LOG 1385
#define INSHARE 1388
#define BEGIN_WORK 1394
#define DROP_INDEX 1399
#define FOR_UPDATE_OF 1405
#define FOR_UPDATE 1406
#define LOCK_TABLE 1411
#define NOT_EXISTS 1413
#define REFERENCES 1415
#define RENCOL 1416
#define SMALLFLOAT 1418
#define COMMIT_W 1429
#define RENTAB 1436
#define KW_CHAR 1439
#define NCHAR 1440
#define NVARCHAR 1441
#define DELIMITER 1443
#define DROP_VIEW 1445
#define EXCLUSIVE 1448
#define GREATER_THAN_EQ 1452
#define INTO_TEMP 1454
#define DATABASE 1478
#define DATETIME 1479
#define DISTINCT 1481
#define FRACTION 1488
#define GROUP_BY 1490
#define INTERVAL 1491
#define NOT_LIKE 1493
#define NOT_ILIKE 1494
#define NOT_NULL 1495
#define RESOURCE 1501
#define SMALLINT 1502
#define IS_NULL 1508
#define LESS_THAN_EQ 1509
#define BETWEEN 1511
#define CLOSE_BRACKET 1514
#define CONNECT 1517
#define KW_CURRENT 1518
#define KW_DECIMAL 1520
#define DEFAULT 1522
#define INTEGER 1530
#define SERIAL8 1532
#define MATCHES 1535
#define VARCHAR 1548
#define CLOSE_SQUARE 1551
#define GREATER_THAN 1552
#define KW_FALSE 1553
#define NOT_IN 1554
#define OPEN_BRACKET 1556
#define KW_DELETE 1564
#define KW_ESCAPE 1567
#define EXISTS 1568
#define EXTEND 1569
#define HAVING 1573
#define KW_INSERT 1575
#define MINUTE 1579
#define MODIFY 1580
#define EQUAL 1582
#define NOT_EQUAL 1583
#define OPEN_SQUARE 1585
#define PUBLIC 1589
#define REVOKE 1593
#define SECOND 1597
#define KW_SELECT 1601
#define SERIAL 1602
#define UNIQUE 1605
#define KW_UPDATE 1607
#define VALUES 1608
#define KW_NULL 1611
#define KW_TRUE 1612
#define ALTER 1614
#define CHECK 1620
#define COUNT 1624
#define KW_FIRST 1629
#define KW_FLOAT 1630
#define GRANT 1633
#define INDEX 1636
#define LESS_THAN 1639
#define MONEY 1641
#define MONTH 1642
#define KW_MULTIPLY 1644
#define ORDER 1645
#define OUTER 1646
#define UNION 1655
#define WHERE 1658
#define KW_BYTE 1665
#define CASE 1667
#define KW_DATE 1669
#define DESC 1670
#define KW_DIVIDE 1671
#define DROP 1674
#define ELSE 1675
#define FROM 1679
#define HOUR 1685
#define INTO 1686
#define LIKE 1689
#define REAL 1698
#define SOME 1703
#define KW_TEXT 1707
#define KW_THEN 1708
#define USER 1709
#define WHEN 1711
#define YEAR 1714
#define KW_DOW 1715
#define XSET 1717
#define ADD 1718
#define ALL 1719
#define KW_AND 1720
#define ANY 1721
#define ASC 1722
#define AVG 1723
#define COLON 1724
#define KW_COMMA 1725
#define DAY 1726
#define DBA 1727
#define KW_FOR 1731
#define XMAX 1736
#define XMIN 1737
#define KW_MINUS 1738
#define KW_MOD 1739
#define KW_NOT 1740
#define KW_SUM 1747
#define ATSIGN 1750
#define KW_PLUS 1751
#define KW_AS 1757
#define KW_BY 1759
#define KW_DOT 1760
#define KW_IN 1763
#define KW_ON 1765
#define KW_OR 1766
#define KW_TO 1767
#define BEFORE 1805
#define END 1809
#define TILDE 1816
#define ILIKE 1817
#define FILLFACTOR 1820
#define TIME 1825
#define KW_TODAY 1832
#define KW_ROWID 1833
#define TIMESTAMP 2181
#define KW_TAG 2202
#define LINTMODULEISLIBRARY 2203




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
#line 581 "y.tab.h"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE sqlparse_yylval;


