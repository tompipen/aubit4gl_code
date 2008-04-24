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
     INT_VALUE = 2159,
     NAMED = 2160,
     NAMED_GEN = 2161,
     CHAR_VALUE = 2162,
     NOT_USED_1 = 2163,
     NOT_USED_2 = 2164,
     NOT_USED_3 = 2165,
     NOT_USED_4 = 2166,
     NOT_USED_5 = 2167,
     NOT_USED_6 = 2168,
     NOT_USED_7 = 2169,
     NOT_USED_8 = 2170,
     NUMBER_VALUE = 2171,
     SEMICOLON = 2172,
     QUESTION_MARK = 2173,
     CLINE = 2174,
     CH = 2175,
     MARK_VAR = 2176,
     END_MARK_VAR = 2177,
     LEFT_JOIN = 1001,
     USING_BTREE = 1013,
     USING_RTREE = 1014,
     SET_BUFFERED_LOG = 1038,
     SET_LOG = 1039,
     MDY = 1041,
     WEEKDAY = 1042,
     MODE_ANSI = 1045,
     START_DATABASE = 1046,
     WITH_LOG_IN = 1047,
     SET_CONSTRAINTS_ALL_IMMEDIATE = 1048,
     DATETIME_VALUE = 1061,
     INTERVAL_VALUE = 1062,
     RECOVER_TABLE = 1063,
     ROLLFORWARD_DATABASE = 1064,
     DROP_TRIGGER = 1080,
     DROP_AUDIT_FOR = 1081,
     CREATE_AUDIT_FOR = 1082,
     EXECUTE_PROCEDURE = 1086,
     ALTER_TABLE = 1093,
     ALTER_INDEX = 1094,
     NEXT_SIZE = 1095,
     XSET_MULTIPLY_EQUAL_OPEN_BRACKET = 1132,
     XSET_ident_DOT_MULTIPLY_EQUAL_OPEN_BRACKET = 1133,
     XSET_ident_DOT_MULTIPLY_EQUAL = 1134,
     XSET_MULTIPLY_EQUAL = 1135,
     XSET_OPEN_BRACKET = 1136,
     CREATE_DATABASE = 1139,
     DROP_DATABASE = 1140,
     ADD_CONSTRAINT = 1142,
     DROP_CONSTRAINT = 1143,
     DROP_SYNONYM = 1144,
     CONSTRAINT = 1145,
     LOCAL_REPORT = 1149,
     LOCAL_PDF_REPORT = 1150,
     DOUBLE_PRECISION = 1154,
     COUNT_MULTIPLY = 1155,
     MODIFY_NEXT_SIZE = 1175,
     LOCK_MODE_PAGE = 1176,
     LOCK_MODE_ROW = 1177,
     UNITS_YEAR = 1184,
     UNITS_MONTH = 1185,
     UNITS_DAY = 1186,
     UNITS_HOUR = 1187,
     UNITS_MINUTE = 1188,
     UNITS_SECOND = 1189,
     TO_CLUSTER = 1194,
     TO_NOT_CLUSTER = 1195,
     CREATE_UC_IDX = 1197,
     CREATE_U_IDX = 1198,
     CREATE_C_IDX = 1199,
     CREATE_IDX = 1200,
     DOUBLE_COLON = 1209,
     SQLSICS = 1215,
     CREATE_SCHEMA = 1216,
     SQLSIRR = 1217,
     UPDATESTATS_T = 1218,
     SQLSICR = 1219,
     SQLSIDR = 1230,
     CREATE_TEMP_TABLE = 1231,
     WITH_CHECK_OPTION = 1239,
     WITH_GRANT_OPTION = 1240,
     SQLSLMNW = 1241,
     WHERE_CURRENT_OF = 1247,
     NOT_NULL_UNIQUE = 1255,
     SQLSLMW = 1262,
     ALL_PRIVILEGES = 1264,
     CREATE_SYNONYM = 1268,
     DROP_TABLE = 1269,
     INEXCLUSIVE = 1271,
     UPDATESTATS = 1276,
     CREATE_TABLE = 1302,
     DEFAULT_NULL = 1303,
     DEFAULT_TODAY = 1304,
     DEFAULT_USER = 1305,
     UNLOCK_TABLE = 1318,
     ROLLBACK_W = 1326,
     SQLSEON = 1328,
     SQLSEOFF = 1329,
     CREATE_VIEW = 1333,
     DELETE_FROM = 1334,
     EXTENT_SIZE = 1341,
     FOREIGN_KEY = 1342,
     INSERT_INTO = 1345,
     IS_NOT_NULL = 1347,
     NOT_MATCHES = 1350,
     PRIMARY_KEY = 1356,
     USE_SESSION = 1363,
     WITH_NO_LOG = 1364,
     INSHARE = 1367,
     BEGIN_WORK = 1373,
     DROP_INDEX = 1378,
     FOR_UPDATE_OF = 1384,
     FOR_UPDATE = 1385,
     LOCK_TABLE = 1389,
     NOT_EXISTS = 1391,
     REFERENCES = 1393,
     RENCOL = 1394,
     SMALLFLOAT = 1396,
     COMMIT_W = 1407,
     RENTAB = 1414,
     KW_CHAR = 1417,
     NCHAR = 1418,
     NVARCHAR = 1419,
     DELIMITER = 1421,
     DROP_VIEW = 1423,
     EXCLUSIVE = 1426,
     GREATER_THAN_EQ = 1430,
     INTO_TEMP = 1432,
     LOAD_FROM = 1436,
     UNLOAD_TO = 1447,
     DATABASE = 1456,
     DATETIME = 1457,
     DISTINCT = 1459,
     FRACTION = 1466,
     GROUP_BY = 1468,
     INTERVAL = 1469,
     NOT_LIKE = 1471,
     NOT_ILIKE = 1472,
     NOT_NULL = 1473,
     RESOURCE = 1479,
     SMALLINT = 1480,
     IS_NULL = 1486,
     LESS_THAN_EQ = 1487,
     BETWEEN = 1489,
     CLOSE_BRACKET = 1492,
     CONNECT = 1495,
     KW_CURRENT = 1496,
     KW_DECIMAL = 1498,
     DEFAULT = 1500,
     INTEGER = 1508,
     SERIAL8 = 1510,
     MATCHES = 1513,
     VARCHAR = 1526,
     CLOSE_SQUARE = 1529,
     GREATER_THAN = 1530,
     KW_FALSE = 1531,
     NOT_IN = 1532,
     OPEN_BRACKET = 1534,
     KW_DELETE = 1542,
     KW_ESCAPE = 1545,
     EXISTS = 1546,
     EXTEND = 1547,
     HAVING = 1551,
     KW_INSERT = 1553,
     MINUTE = 1557,
     MODIFY = 1558,
     EQUAL = 1560,
     NOT_EQUAL = 1561,
     OPEN_SQUARE = 1563,
     PUBLIC = 1567,
     REVOKE = 1570,
     SECOND = 1574,
     KW_SELECT = 1578,
     SERIAL = 1579,
     UNIQUE = 1582,
     KW_UPDATE = 1584,
     VALUES = 1585,
     KW_NULL = 1589,
     KW_TRUE = 1590,
     ALTER = 1592,
     CHECK = 1598,
     COUNT = 1602,
     KW_FIRST = 1607,
     KW_FLOAT = 1608,
     GRANT = 1611,
     INDEX = 1614,
     LESS_THAN = 1617,
     MONEY = 1619,
     MONTH = 1620,
     KW_MULTIPLY = 1622,
     ORDER = 1623,
     OUTER = 1624,
     UNION = 1633,
     WHERE = 1635,
     KW_BYTE = 1642,
     CASE = 1644,
     KW_DATE = 1646,
     DESC = 1647,
     KW_DIVIDE = 1648,
     DROP = 1651,
     ELSE = 1652,
     FROM = 1656,
     HOUR = 1662,
     INTO = 1663,
     LIKE = 1666,
     REAL = 1675,
     SOME = 1680,
     KW_TEXT = 1684,
     KW_THEN = 1685,
     USER = 1686,
     WHEN = 1688,
     YEAR = 1691,
     KW_DOW = 1692,
     XSET = 1694,
     ADD = 1695,
     ALL = 1696,
     KW_AND = 1697,
     ANY = 1698,
     ASC = 1699,
     AVG = 1700,
     COLON = 1701,
     KW_COMMA = 1702,
     DAY = 1703,
     DBA = 1704,
     KW_FOR = 1708,
     XMAX = 1713,
     XMIN = 1714,
     KW_MINUS = 1715,
     KW_MOD = 1716,
     KW_NOT = 1717,
     KW_ROW = 1721,
     KW_SUM = 1724,
     ATSIGN = 1727,
     KW_PLUS = 1728,
     KW_AS_USER = 1733,
     KW_AS = 1734,
     KW_BY = 1736,
     KW_DOT = 1737,
     KW_IN = 1740,
     KW_ON = 1742,
     KW_OR = 1743,
     KW_TO = 1744,
     BEFORE = 1782,
     END = 1786,
     TILDE = 1793,
     ILIKE = 1794,
     FILLFACTOR = 1797,
     KW_EXTENDS = 1800,
     TIME = 1802,
     KW_TODAY = 1809,
     KW_ROWID = 1810,
     CURSOR_NAME_FUNCTION = 2157
   };
#endif
/* Tokens.  */
#define INT_VALUE 2159
#define NAMED 2160
#define NAMED_GEN 2161
#define CHAR_VALUE 2162
#define NOT_USED_1 2163
#define NOT_USED_2 2164
#define NOT_USED_3 2165
#define NOT_USED_4 2166
#define NOT_USED_5 2167
#define NOT_USED_6 2168
#define NOT_USED_7 2169
#define NOT_USED_8 2170
#define NUMBER_VALUE 2171
#define SEMICOLON 2172
#define QUESTION_MARK 2173
#define CLINE 2174
#define CH 2175
#define MARK_VAR 2176
#define END_MARK_VAR 2177
#define LEFT_JOIN 1001
#define USING_BTREE 1013
#define USING_RTREE 1014
#define SET_BUFFERED_LOG 1038
#define SET_LOG 1039
#define MDY 1041
#define WEEKDAY 1042
#define MODE_ANSI 1045
#define START_DATABASE 1046
#define WITH_LOG_IN 1047
#define SET_CONSTRAINTS_ALL_IMMEDIATE 1048
#define DATETIME_VALUE 1061
#define INTERVAL_VALUE 1062
#define RECOVER_TABLE 1063
#define ROLLFORWARD_DATABASE 1064
#define DROP_TRIGGER 1080
#define DROP_AUDIT_FOR 1081
#define CREATE_AUDIT_FOR 1082
#define EXECUTE_PROCEDURE 1086
#define ALTER_TABLE 1093
#define ALTER_INDEX 1094
#define NEXT_SIZE 1095
#define XSET_MULTIPLY_EQUAL_OPEN_BRACKET 1132
#define XSET_ident_DOT_MULTIPLY_EQUAL_OPEN_BRACKET 1133
#define XSET_ident_DOT_MULTIPLY_EQUAL 1134
#define XSET_MULTIPLY_EQUAL 1135
#define XSET_OPEN_BRACKET 1136
#define CREATE_DATABASE 1139
#define DROP_DATABASE 1140
#define ADD_CONSTRAINT 1142
#define DROP_CONSTRAINT 1143
#define DROP_SYNONYM 1144
#define CONSTRAINT 1145
#define LOCAL_REPORT 1149
#define LOCAL_PDF_REPORT 1150
#define DOUBLE_PRECISION 1154
#define COUNT_MULTIPLY 1155
#define MODIFY_NEXT_SIZE 1175
#define LOCK_MODE_PAGE 1176
#define LOCK_MODE_ROW 1177
#define UNITS_YEAR 1184
#define UNITS_MONTH 1185
#define UNITS_DAY 1186
#define UNITS_HOUR 1187
#define UNITS_MINUTE 1188
#define UNITS_SECOND 1189
#define TO_CLUSTER 1194
#define TO_NOT_CLUSTER 1195
#define CREATE_UC_IDX 1197
#define CREATE_U_IDX 1198
#define CREATE_C_IDX 1199
#define CREATE_IDX 1200
#define DOUBLE_COLON 1209
#define SQLSICS 1215
#define CREATE_SCHEMA 1216
#define SQLSIRR 1217
#define UPDATESTATS_T 1218
#define SQLSICR 1219
#define SQLSIDR 1230
#define CREATE_TEMP_TABLE 1231
#define WITH_CHECK_OPTION 1239
#define WITH_GRANT_OPTION 1240
#define SQLSLMNW 1241
#define WHERE_CURRENT_OF 1247
#define NOT_NULL_UNIQUE 1255
#define SQLSLMW 1262
#define ALL_PRIVILEGES 1264
#define CREATE_SYNONYM 1268
#define DROP_TABLE 1269
#define INEXCLUSIVE 1271
#define UPDATESTATS 1276
#define CREATE_TABLE 1302
#define DEFAULT_NULL 1303
#define DEFAULT_TODAY 1304
#define DEFAULT_USER 1305
#define UNLOCK_TABLE 1318
#define ROLLBACK_W 1326
#define SQLSEON 1328
#define SQLSEOFF 1329
#define CREATE_VIEW 1333
#define DELETE_FROM 1334
#define EXTENT_SIZE 1341
#define FOREIGN_KEY 1342
#define INSERT_INTO 1345
#define IS_NOT_NULL 1347
#define NOT_MATCHES 1350
#define PRIMARY_KEY 1356
#define USE_SESSION 1363
#define WITH_NO_LOG 1364
#define INSHARE 1367
#define BEGIN_WORK 1373
#define DROP_INDEX 1378
#define FOR_UPDATE_OF 1384
#define FOR_UPDATE 1385
#define LOCK_TABLE 1389
#define NOT_EXISTS 1391
#define REFERENCES 1393
#define RENCOL 1394
#define SMALLFLOAT 1396
#define COMMIT_W 1407
#define RENTAB 1414
#define KW_CHAR 1417
#define NCHAR 1418
#define NVARCHAR 1419
#define DELIMITER 1421
#define DROP_VIEW 1423
#define EXCLUSIVE 1426
#define GREATER_THAN_EQ 1430
#define INTO_TEMP 1432
#define LOAD_FROM 1436
#define UNLOAD_TO 1447
#define DATABASE 1456
#define DATETIME 1457
#define DISTINCT 1459
#define FRACTION 1466
#define GROUP_BY 1468
#define INTERVAL 1469
#define NOT_LIKE 1471
#define NOT_ILIKE 1472
#define NOT_NULL 1473
#define RESOURCE 1479
#define SMALLINT 1480
#define IS_NULL 1486
#define LESS_THAN_EQ 1487
#define BETWEEN 1489
#define CLOSE_BRACKET 1492
#define CONNECT 1495
#define KW_CURRENT 1496
#define KW_DECIMAL 1498
#define DEFAULT 1500
#define INTEGER 1508
#define SERIAL8 1510
#define MATCHES 1513
#define VARCHAR 1526
#define CLOSE_SQUARE 1529
#define GREATER_THAN 1530
#define KW_FALSE 1531
#define NOT_IN 1532
#define OPEN_BRACKET 1534
#define KW_DELETE 1542
#define KW_ESCAPE 1545
#define EXISTS 1546
#define EXTEND 1547
#define HAVING 1551
#define KW_INSERT 1553
#define MINUTE 1557
#define MODIFY 1558
#define EQUAL 1560
#define NOT_EQUAL 1561
#define OPEN_SQUARE 1563
#define PUBLIC 1567
#define REVOKE 1570
#define SECOND 1574
#define KW_SELECT 1578
#define SERIAL 1579
#define UNIQUE 1582
#define KW_UPDATE 1584
#define VALUES 1585
#define KW_NULL 1589
#define KW_TRUE 1590
#define ALTER 1592
#define CHECK 1598
#define COUNT 1602
#define KW_FIRST 1607
#define KW_FLOAT 1608
#define GRANT 1611
#define INDEX 1614
#define LESS_THAN 1617
#define MONEY 1619
#define MONTH 1620
#define KW_MULTIPLY 1622
#define ORDER 1623
#define OUTER 1624
#define UNION 1633
#define WHERE 1635
#define KW_BYTE 1642
#define CASE 1644
#define KW_DATE 1646
#define DESC 1647
#define KW_DIVIDE 1648
#define DROP 1651
#define ELSE 1652
#define FROM 1656
#define HOUR 1662
#define INTO 1663
#define LIKE 1666
#define REAL 1675
#define SOME 1680
#define KW_TEXT 1684
#define KW_THEN 1685
#define USER 1686
#define WHEN 1688
#define YEAR 1691
#define KW_DOW 1692
#define XSET 1694
#define ADD 1695
#define ALL 1696
#define KW_AND 1697
#define ANY 1698
#define ASC 1699
#define AVG 1700
#define COLON 1701
#define KW_COMMA 1702
#define DAY 1703
#define DBA 1704
#define KW_FOR 1708
#define XMAX 1713
#define XMIN 1714
#define KW_MINUS 1715
#define KW_MOD 1716
#define KW_NOT 1717
#define KW_ROW 1721
#define KW_SUM 1724
#define ATSIGN 1727
#define KW_PLUS 1728
#define KW_AS_USER 1733
#define KW_AS 1734
#define KW_BY 1736
#define KW_DOT 1737
#define KW_IN 1740
#define KW_ON 1742
#define KW_OR 1743
#define KW_TO 1744
#define BEFORE 1782
#define END 1786
#define TILDE 1793
#define ILIKE 1794
#define FILLFACTOR 1797
#define KW_EXTENDS 1800
#define TIME 1802
#define KW_TODAY 1809
#define KW_ROWID 1810
#define CURSOR_NAME_FUNCTION 2157




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
#line 580 "y.tab.h"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE sqlparse_yylval;

