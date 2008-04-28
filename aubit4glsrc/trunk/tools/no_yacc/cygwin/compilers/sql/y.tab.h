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
     INT_VALUE = 2162,
     NAMED = 2163,
     NAMED_GEN = 2164,
     CHAR_VALUE = 2165,
     NOT_USED_1 = 2166,
     NOT_USED_2 = 2167,
     NOT_USED_3 = 2168,
     NOT_USED_4 = 2169,
     NOT_USED_5 = 2170,
     NOT_USED_6 = 2171,
     NOT_USED_7 = 2172,
     NOT_USED_8 = 2173,
     NUMBER_VALUE = 2174,
     SEMICOLON = 2175,
     QUESTION_MARK = 2176,
     CLINE = 2177,
     CH = 2178,
     MARK_VAR = 2179,
     END_MARK_VAR = 2180,
     LEFT_JOIN = 1001,
     WITH_CONVERSIONS = 1007,
     WITHOUT_CONVERSIONS = 1008,
     USING_BTREE = 1015,
     USING_RTREE = 1016,
     SET_BUFFERED_LOG = 1040,
     SET_LOG = 1041,
     MDY = 1043,
     WEEKDAY = 1044,
     MODE_ANSI = 1047,
     START_DATABASE = 1048,
     WITH_LOG_IN = 1049,
     SET_CONSTRAINTS_ALL_IMMEDIATE = 1050,
     DATETIME_VALUE = 1063,
     INTERVAL_VALUE = 1064,
     RECOVER_TABLE = 1065,
     ROLLFORWARD_DATABASE = 1066,
     DROP_TRIGGER = 1082,
     DROP_AUDIT_FOR = 1083,
     CREATE_AUDIT_FOR = 1084,
     EXECUTE_PROCEDURE = 1088,
     ALTER_TABLE = 1095,
     ALTER_INDEX = 1096,
     NEXT_SIZE = 1097,
     XSET_MULTIPLY_EQUAL_OPEN_BRACKET = 1134,
     XSET_ident_DOT_MULTIPLY_EQUAL_OPEN_BRACKET = 1135,
     XSET_ident_DOT_MULTIPLY_EQUAL = 1136,
     XSET_MULTIPLY_EQUAL = 1137,
     XSET_OPEN_BRACKET = 1138,
     CREATE_DATABASE = 1141,
     DROP_DATABASE = 1142,
     ADD_CONSTRAINT = 1144,
     DROP_CONSTRAINT = 1145,
     DROP_SYNONYM = 1146,
     CONSTRAINT = 1147,
     LOCAL_REPORT = 1151,
     LOCAL_PDF_REPORT = 1152,
     DOUBLE_PRECISION = 1156,
     COUNT_MULTIPLY = 1157,
     MODIFY_NEXT_SIZE = 1177,
     LOCK_MODE_PAGE = 1178,
     LOCK_MODE_ROW = 1179,
     UNITS_YEAR = 1186,
     UNITS_MONTH = 1187,
     UNITS_DAY = 1188,
     UNITS_HOUR = 1189,
     UNITS_MINUTE = 1190,
     UNITS_SECOND = 1191,
     TO_CLUSTER = 1196,
     TO_NOT_CLUSTER = 1197,
     CREATE_UC_IDX = 1199,
     CREATE_U_IDX = 1200,
     CREATE_C_IDX = 1201,
     CREATE_IDX = 1202,
     DOUBLE_COLON = 1211,
     SQLSICS = 1217,
     CREATE_SCHEMA = 1218,
     SQLSIRR = 1219,
     UPDATESTATS_T = 1220,
     SQLSICR = 1221,
     SQLSIDR = 1232,
     CREATE_TEMP_TABLE = 1233,
     WITH_CHECK_OPTION = 1241,
     WITH_GRANT_OPTION = 1242,
     SQLSLMNW = 1243,
     WHERE_CURRENT_OF = 1249,
     NOT_NULL_UNIQUE = 1257,
     SQLSLMW = 1264,
     ALL_PRIVILEGES = 1266,
     CREATE_SYNONYM = 1270,
     DROP_TABLE = 1271,
     INEXCLUSIVE = 1273,
     UPDATESTATS = 1278,
     CREATE_TABLE = 1304,
     DEFAULT_NULL = 1305,
     DEFAULT_TODAY = 1306,
     DEFAULT_USER = 1307,
     UNLOCK_TABLE = 1320,
     ROLLBACK_W = 1328,
     SQLSEON = 1330,
     SQLSEOFF = 1331,
     CREATE_VIEW = 1335,
     DELETE_FROM = 1336,
     EXTENT_SIZE = 1343,
     FOREIGN_KEY = 1344,
     INSERT_INTO = 1347,
     IS_NOT_NULL = 1349,
     NOT_MATCHES = 1352,
     PRIMARY_KEY = 1358,
     USE_SESSION = 1365,
     WITH_NO_LOG = 1366,
     INSHARE = 1369,
     BEGIN_WORK = 1375,
     DROP_INDEX = 1380,
     FOR_UPDATE_OF = 1386,
     FOR_UPDATE = 1387,
     LOCK_TABLE = 1391,
     NOT_EXISTS = 1393,
     REFERENCES = 1395,
     RENCOL = 1396,
     SMALLFLOAT = 1398,
     COMMIT_W = 1409,
     RENTAB = 1416,
     KW_CHAR = 1419,
     NCHAR = 1420,
     NVARCHAR = 1421,
     DELIMITER = 1423,
     DROP_VIEW = 1425,
     EXCLUSIVE = 1428,
     GREATER_THAN_EQ = 1432,
     INTO_TEMP = 1434,
     LOAD_FROM = 1438,
     UNLOAD_TO = 1449,
     DATABASE = 1458,
     DATETIME = 1459,
     DISTINCT = 1461,
     FRACTION = 1468,
     GROUP_BY = 1470,
     INTERVAL = 1471,
     NOT_LIKE = 1473,
     NOT_ILIKE = 1474,
     NOT_NULL = 1475,
     RESOURCE = 1481,
     SMALLINT = 1482,
     IS_NULL = 1488,
     LESS_THAN_EQ = 1489,
     BETWEEN = 1491,
     CLOSE_BRACKET = 1494,
     CONNECT = 1497,
     KW_CURRENT = 1498,
     KW_DECIMAL = 1500,
     DEFAULT = 1502,
     INTEGER = 1510,
     SERIAL8 = 1512,
     MATCHES = 1515,
     VARCHAR = 1528,
     CLOSE_SQUARE = 1531,
     GREATER_THAN = 1532,
     KW_FALSE = 1533,
     NOT_IN = 1534,
     OPEN_BRACKET = 1536,
     KW_DELETE = 1544,
     KW_ESCAPE = 1547,
     EXISTS = 1548,
     EXTEND = 1549,
     HAVING = 1553,
     KW_INSERT = 1555,
     MINUTE = 1559,
     MODIFY = 1560,
     EQUAL = 1562,
     NOT_EQUAL = 1563,
     OPEN_SQUARE = 1565,
     PUBLIC = 1569,
     REVOKE = 1572,
     SECOND = 1576,
     KW_SELECT = 1580,
     SERIAL = 1581,
     UNIQUE = 1584,
     KW_UPDATE = 1586,
     VALUES = 1587,
     KW_NULL = 1591,
     KW_TRUE = 1592,
     ALTER = 1594,
     CHECK = 1600,
     COUNT = 1604,
     KW_FIRST = 1609,
     KW_FLOAT = 1610,
     GRANT = 1613,
     INDEX = 1616,
     LESS_THAN = 1619,
     MONEY = 1621,
     MONTH = 1622,
     KW_MULTIPLY = 1624,
     ORDER = 1625,
     OUTER = 1626,
     UNION = 1635,
     WHERE = 1637,
     KW_BYTE = 1644,
     CASE = 1646,
     KW_DATE = 1648,
     DESC = 1649,
     KW_DIVIDE = 1650,
     DROP = 1653,
     ELSE = 1654,
     FROM = 1658,
     HOUR = 1664,
     INTO = 1665,
     LIKE = 1668,
     REAL = 1677,
     SOME = 1682,
     KW_TEXT = 1686,
     KW_THEN = 1687,
     USER = 1688,
     WHEN = 1690,
     YEAR = 1693,
     KW_DOW = 1694,
     XSET = 1696,
     ADD = 1697,
     ALL = 1698,
     KW_AND = 1699,
     ANY = 1700,
     ASC = 1701,
     AVG = 1702,
     COLON = 1703,
     KW_COMMA = 1704,
     DAY = 1705,
     DBA = 1706,
     KW_FOR = 1710,
     XMAX = 1715,
     XMIN = 1716,
     KW_MINUS = 1717,
     KW_MOD = 1718,
     KW_NOT = 1719,
     KW_ROW = 1723,
     KW_SUM = 1726,
     ATSIGN = 1729,
     KW_PLUS = 1730,
     KW_AS_USER = 1735,
     KW_AS = 1736,
     KW_BY = 1738,
     KW_DOT = 1739,
     KW_IN = 1742,
     KW_ON = 1744,
     KW_OR = 1745,
     KW_TO = 1746,
     BEFORE = 1784,
     END = 1788,
     TILDE = 1795,
     ILIKE = 1796,
     FILLFACTOR = 1799,
     KW_EXTENDS = 1802,
     TIME = 1804,
     KW_TODAY = 1811,
     KW_ROWID = 1812,
     CURSOR_NAME_FUNCTION = 2159,
     TIMESTAMP = 2160
   };
#endif
/* Tokens.  */
#define INT_VALUE 2162
#define NAMED 2163
#define NAMED_GEN 2164
#define CHAR_VALUE 2165
#define NOT_USED_1 2166
#define NOT_USED_2 2167
#define NOT_USED_3 2168
#define NOT_USED_4 2169
#define NOT_USED_5 2170
#define NOT_USED_6 2171
#define NOT_USED_7 2172
#define NOT_USED_8 2173
#define NUMBER_VALUE 2174
#define SEMICOLON 2175
#define QUESTION_MARK 2176
#define CLINE 2177
#define CH 2178
#define MARK_VAR 2179
#define END_MARK_VAR 2180
#define LEFT_JOIN 1001
#define WITH_CONVERSIONS 1007
#define WITHOUT_CONVERSIONS 1008
#define USING_BTREE 1015
#define USING_RTREE 1016
#define SET_BUFFERED_LOG 1040
#define SET_LOG 1041
#define MDY 1043
#define WEEKDAY 1044
#define MODE_ANSI 1047
#define START_DATABASE 1048
#define WITH_LOG_IN 1049
#define SET_CONSTRAINTS_ALL_IMMEDIATE 1050
#define DATETIME_VALUE 1063
#define INTERVAL_VALUE 1064
#define RECOVER_TABLE 1065
#define ROLLFORWARD_DATABASE 1066
#define DROP_TRIGGER 1082
#define DROP_AUDIT_FOR 1083
#define CREATE_AUDIT_FOR 1084
#define EXECUTE_PROCEDURE 1088
#define ALTER_TABLE 1095
#define ALTER_INDEX 1096
#define NEXT_SIZE 1097
#define XSET_MULTIPLY_EQUAL_OPEN_BRACKET 1134
#define XSET_ident_DOT_MULTIPLY_EQUAL_OPEN_BRACKET 1135
#define XSET_ident_DOT_MULTIPLY_EQUAL 1136
#define XSET_MULTIPLY_EQUAL 1137
#define XSET_OPEN_BRACKET 1138
#define CREATE_DATABASE 1141
#define DROP_DATABASE 1142
#define ADD_CONSTRAINT 1144
#define DROP_CONSTRAINT 1145
#define DROP_SYNONYM 1146
#define CONSTRAINT 1147
#define LOCAL_REPORT 1151
#define LOCAL_PDF_REPORT 1152
#define DOUBLE_PRECISION 1156
#define COUNT_MULTIPLY 1157
#define MODIFY_NEXT_SIZE 1177
#define LOCK_MODE_PAGE 1178
#define LOCK_MODE_ROW 1179
#define UNITS_YEAR 1186
#define UNITS_MONTH 1187
#define UNITS_DAY 1188
#define UNITS_HOUR 1189
#define UNITS_MINUTE 1190
#define UNITS_SECOND 1191
#define TO_CLUSTER 1196
#define TO_NOT_CLUSTER 1197
#define CREATE_UC_IDX 1199
#define CREATE_U_IDX 1200
#define CREATE_C_IDX 1201
#define CREATE_IDX 1202
#define DOUBLE_COLON 1211
#define SQLSICS 1217
#define CREATE_SCHEMA 1218
#define SQLSIRR 1219
#define UPDATESTATS_T 1220
#define SQLSICR 1221
#define SQLSIDR 1232
#define CREATE_TEMP_TABLE 1233
#define WITH_CHECK_OPTION 1241
#define WITH_GRANT_OPTION 1242
#define SQLSLMNW 1243
#define WHERE_CURRENT_OF 1249
#define NOT_NULL_UNIQUE 1257
#define SQLSLMW 1264
#define ALL_PRIVILEGES 1266
#define CREATE_SYNONYM 1270
#define DROP_TABLE 1271
#define INEXCLUSIVE 1273
#define UPDATESTATS 1278
#define CREATE_TABLE 1304
#define DEFAULT_NULL 1305
#define DEFAULT_TODAY 1306
#define DEFAULT_USER 1307
#define UNLOCK_TABLE 1320
#define ROLLBACK_W 1328
#define SQLSEON 1330
#define SQLSEOFF 1331
#define CREATE_VIEW 1335
#define DELETE_FROM 1336
#define EXTENT_SIZE 1343
#define FOREIGN_KEY 1344
#define INSERT_INTO 1347
#define IS_NOT_NULL 1349
#define NOT_MATCHES 1352
#define PRIMARY_KEY 1358
#define USE_SESSION 1365
#define WITH_NO_LOG 1366
#define INSHARE 1369
#define BEGIN_WORK 1375
#define DROP_INDEX 1380
#define FOR_UPDATE_OF 1386
#define FOR_UPDATE 1387
#define LOCK_TABLE 1391
#define NOT_EXISTS 1393
#define REFERENCES 1395
#define RENCOL 1396
#define SMALLFLOAT 1398
#define COMMIT_W 1409
#define RENTAB 1416
#define KW_CHAR 1419
#define NCHAR 1420
#define NVARCHAR 1421
#define DELIMITER 1423
#define DROP_VIEW 1425
#define EXCLUSIVE 1428
#define GREATER_THAN_EQ 1432
#define INTO_TEMP 1434
#define LOAD_FROM 1438
#define UNLOAD_TO 1449
#define DATABASE 1458
#define DATETIME 1459
#define DISTINCT 1461
#define FRACTION 1468
#define GROUP_BY 1470
#define INTERVAL 1471
#define NOT_LIKE 1473
#define NOT_ILIKE 1474
#define NOT_NULL 1475
#define RESOURCE 1481
#define SMALLINT 1482
#define IS_NULL 1488
#define LESS_THAN_EQ 1489
#define BETWEEN 1491
#define CLOSE_BRACKET 1494
#define CONNECT 1497
#define KW_CURRENT 1498
#define KW_DECIMAL 1500
#define DEFAULT 1502
#define INTEGER 1510
#define SERIAL8 1512
#define MATCHES 1515
#define VARCHAR 1528
#define CLOSE_SQUARE 1531
#define GREATER_THAN 1532
#define KW_FALSE 1533
#define NOT_IN 1534
#define OPEN_BRACKET 1536
#define KW_DELETE 1544
#define KW_ESCAPE 1547
#define EXISTS 1548
#define EXTEND 1549
#define HAVING 1553
#define KW_INSERT 1555
#define MINUTE 1559
#define MODIFY 1560
#define EQUAL 1562
#define NOT_EQUAL 1563
#define OPEN_SQUARE 1565
#define PUBLIC 1569
#define REVOKE 1572
#define SECOND 1576
#define KW_SELECT 1580
#define SERIAL 1581
#define UNIQUE 1584
#define KW_UPDATE 1586
#define VALUES 1587
#define KW_NULL 1591
#define KW_TRUE 1592
#define ALTER 1594
#define CHECK 1600
#define COUNT 1604
#define KW_FIRST 1609
#define KW_FLOAT 1610
#define GRANT 1613
#define INDEX 1616
#define LESS_THAN 1619
#define MONEY 1621
#define MONTH 1622
#define KW_MULTIPLY 1624
#define ORDER 1625
#define OUTER 1626
#define UNION 1635
#define WHERE 1637
#define KW_BYTE 1644
#define CASE 1646
#define KW_DATE 1648
#define DESC 1649
#define KW_DIVIDE 1650
#define DROP 1653
#define ELSE 1654
#define FROM 1658
#define HOUR 1664
#define INTO 1665
#define LIKE 1668
#define REAL 1677
#define SOME 1682
#define KW_TEXT 1686
#define KW_THEN 1687
#define USER 1688
#define WHEN 1690
#define YEAR 1693
#define KW_DOW 1694
#define XSET 1696
#define ADD 1697
#define ALL 1698
#define KW_AND 1699
#define ANY 1700
#define ASC 1701
#define AVG 1702
#define COLON 1703
#define KW_COMMA 1704
#define DAY 1705
#define DBA 1706
#define KW_FOR 1710
#define XMAX 1715
#define XMIN 1716
#define KW_MINUS 1717
#define KW_MOD 1718
#define KW_NOT 1719
#define KW_ROW 1723
#define KW_SUM 1726
#define ATSIGN 1729
#define KW_PLUS 1730
#define KW_AS_USER 1735
#define KW_AS 1736
#define KW_BY 1738
#define KW_DOT 1739
#define KW_IN 1742
#define KW_ON 1744
#define KW_OR 1745
#define KW_TO 1746
#define BEFORE 1784
#define END 1788
#define TILDE 1795
#define ILIKE 1796
#define FILLFACTOR 1799
#define KW_EXTENDS 1802
#define TIME 1804
#define KW_TODAY 1811
#define KW_ROWID 1812
#define CURSOR_NAME_FUNCTION 2159
#define TIMESTAMP 2160




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
#line 586 "y.tab.h"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE sqlparse_yylval;

