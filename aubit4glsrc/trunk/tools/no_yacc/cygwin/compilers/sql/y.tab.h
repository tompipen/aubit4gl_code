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
     INT_VALUE = 2157,
     NAMED = 2158,
     NAMED_GEN = 2159,
     CHAR_VALUE = 2160,
     NOT_USED_1 = 2161,
     NOT_USED_2 = 2162,
     NOT_USED_3 = 2163,
     NOT_USED_4 = 2164,
     NOT_USED_5 = 2165,
     NOT_USED_6 = 2166,
     NOT_USED_7 = 2167,
     NOT_USED_8 = 2168,
     NUMBER_VALUE = 2169,
     SEMICOLON = 2170,
     QUESTION_MARK = 2171,
     CLINE = 2172,
     CH = 2173,
     MARK_VAR = 2174,
     END_MARK_VAR = 2175,
     LEFT_JOIN = 1001,
     USING_BTREE = 1013,
     USING_RTREE = 1014,
     SET_BUFFERED_LOG = 1038,
     SET_LOG = 1039,
     MDY = 1041,
     WEEKDAY = 1042,
     MISC_INFX_SQL = 1045,
     DATETIME_VALUE = 1058,
     INTERVAL_VALUE = 1059,
     RECOVER_TABLE = 1060,
     ROLLFORWARD_DATABASE = 1061,
     DROP_TRIGGER = 1077,
     DROP_AUDIT_FOR = 1078,
     CREATE_AUDIT_FOR = 1079,
     EXECUTE_PROCEDURE = 1083,
     ALTER_TABLE = 1090,
     ALTER_INDEX = 1091,
     NEXT_SIZE = 1092,
     XSET_MULTIPLY_EQUAL_OPEN_BRACKET = 1129,
     XSET_ident_DOT_MULTIPLY_EQUAL_OPEN_BRACKET = 1130,
     XSET_ident_DOT_MULTIPLY_EQUAL = 1131,
     XSET_MULTIPLY_EQUAL = 1132,
     XSET_OPEN_BRACKET = 1133,
     CREATE_DATABASE = 1136,
     DROP_DATABASE = 1137,
     ADD_CONSTRAINT = 1139,
     DROP_CONSTRAINT = 1140,
     DROP_SYNONYM = 1141,
     CONSTRAINT = 1142,
     LOCAL_REPORT = 1146,
     LOCAL_PDF_REPORT = 1147,
     DOUBLE_PRECISION = 1151,
     COUNT_MULTIPLY = 1152,
     MODIFY_NEXT_SIZE = 1172,
     LOCK_MODE_PAGE = 1173,
     LOCK_MODE_ROW = 1174,
     UNITS_YEAR = 1181,
     UNITS_MONTH = 1182,
     UNITS_DAY = 1183,
     UNITS_HOUR = 1184,
     UNITS_MINUTE = 1185,
     UNITS_SECOND = 1186,
     TO_CLUSTER = 1191,
     TO_NOT_CLUSTER = 1192,
     CREATE_UC_IDX = 1194,
     CREATE_U_IDX = 1195,
     CREATE_C_IDX = 1196,
     CREATE_IDX = 1197,
     TYPECAST = 1206,
     SQLSICS = 1213,
     CREATE_SCHEMA = 1214,
     SQLSIRR = 1215,
     UPDATESTATS_T = 1216,
     SQLSICR = 1217,
     SQLSIDR = 1228,
     CREATE_TEMP_TABLE = 1229,
     WITH_CHECK_OPTION = 1237,
     WITH_GRANT_OPTION = 1238,
     SQLSLMNW = 1239,
     WHERE_CURRENT_OF = 1245,
     NOT_NULL_UNIQUE = 1253,
     SQLSLMW = 1260,
     ALL_PRIVILEGES = 1262,
     CREATE_SYNONYM = 1266,
     DROP_TABLE = 1267,
     INEXCLUSIVE = 1269,
     UPDATESTATS = 1274,
     CREATE_TABLE = 1300,
     DEFAULT_NULL = 1301,
     DEFAULT_TODAY = 1302,
     DEFAULT_USER = 1303,
     UNLOCK_TABLE = 1316,
     ROLLBACK_W = 1324,
     SQLSEON = 1326,
     SQLSEOFF = 1327,
     CREATE_VIEW = 1331,
     DELETE_FROM = 1332,
     EXTENT_SIZE = 1339,
     FOREIGN_KEY = 1340,
     INSERT_INTO = 1343,
     IS_NOT_NULL = 1345,
     NOT_MATCHES = 1348,
     PRIMARY_KEY = 1354,
     USE_SESSION = 1361,
     WITH_NO_LOG = 1362,
     INSHARE = 1365,
     BEGIN_WORK = 1371,
     DROP_INDEX = 1376,
     FOR_UPDATE_OF = 1382,
     FOR_UPDATE = 1383,
     LOCK_TABLE = 1387,
     NOT_EXISTS = 1389,
     REFERENCES = 1391,
     RENCOL = 1392,
     SMALLFLOAT = 1394,
     COMMIT_W = 1405,
     RENTAB = 1412,
     KW_CHAR = 1415,
     NCHAR = 1416,
     NVARCHAR = 1417,
     DELIMITER = 1419,
     DROP_VIEW = 1421,
     EXCLUSIVE = 1424,
     GREATER_THAN_EQ = 1428,
     INTO_TEMP = 1430,
     LOAD_FROM = 1434,
     UNLOAD_TO = 1445,
     DATABASE = 1454,
     DATETIME = 1455,
     DISTINCT = 1457,
     FRACTION = 1464,
     GROUP_BY = 1466,
     INTERVAL = 1467,
     NOT_LIKE = 1469,
     NOT_ILIKE = 1470,
     NOT_NULL = 1471,
     RESOURCE = 1477,
     SMALLINT = 1478,
     IS_NULL = 1484,
     LESS_THAN_EQ = 1485,
     BETWEEN = 1487,
     CLOSE_BRACKET = 1490,
     CONNECT = 1493,
     KW_CURRENT = 1494,
     KW_DECIMAL = 1496,
     DEFAULT = 1498,
     INTEGER = 1506,
     SERIAL8 = 1508,
     MATCHES = 1511,
     VARCHAR = 1524,
     CLOSE_SQUARE = 1527,
     GREATER_THAN = 1528,
     KW_FALSE = 1529,
     NOT_IN = 1530,
     OPEN_BRACKET = 1532,
     KW_DELETE = 1540,
     KW_ESCAPE = 1543,
     EXISTS = 1544,
     EXTEND = 1545,
     HAVING = 1549,
     KW_INSERT = 1551,
     MINUTE = 1555,
     MODIFY = 1556,
     EQUAL = 1558,
     NOT_EQUAL = 1559,
     OPEN_SQUARE = 1561,
     PUBLIC = 1565,
     REVOKE = 1568,
     SECOND = 1572,
     KW_SELECT = 1576,
     SERIAL = 1577,
     UNIQUE = 1580,
     KW_UPDATE = 1582,
     VALUES = 1583,
     KW_NULL = 1587,
     KW_TRUE = 1588,
     ALTER = 1590,
     CHECK = 1596,
     COUNT = 1600,
     KW_FIRST = 1605,
     KW_FLOAT = 1606,
     GRANT = 1609,
     INDEX = 1612,
     LESS_THAN = 1615,
     MONEY = 1617,
     MONTH = 1618,
     KW_MULTIPLY = 1620,
     ORDER = 1621,
     OUTER = 1622,
     UNION = 1631,
     WHERE = 1633,
     KW_BYTE = 1640,
     CASE = 1642,
     KW_DATE = 1644,
     DESC = 1645,
     KW_DIVIDE = 1646,
     DROP = 1649,
     ELSE = 1650,
     FROM = 1654,
     HOUR = 1660,
     INTO = 1661,
     LIKE = 1664,
     REAL = 1673,
     SOME = 1678,
     KW_TEXT = 1682,
     KW_THEN = 1683,
     USER = 1684,
     WHEN = 1686,
     YEAR = 1689,
     KW_DOW = 1690,
     XSET = 1692,
     ADD = 1693,
     ALL = 1694,
     KW_AND = 1695,
     ANY = 1696,
     ASC = 1697,
     AVG = 1698,
     COLON = 1699,
     KW_COMMA = 1700,
     DAY = 1701,
     DBA = 1702,
     KW_FOR = 1706,
     XMAX = 1711,
     XMIN = 1712,
     KW_MINUS = 1713,
     KW_MOD = 1714,
     KW_NOT = 1715,
     KW_ROW = 1719,
     KW_SUM = 1722,
     ATSIGN = 1725,
     KW_PLUS = 1726,
     KW_AS_USER = 1731,
     KW_AS = 1732,
     KW_BY = 1734,
     KW_DOT = 1735,
     KW_IN = 1738,
     KW_ON = 1740,
     KW_OR = 1741,
     KW_TO = 1742,
     BEFORE = 1780,
     END = 1784,
     TILDE = 1791,
     ILIKE = 1792,
     FILLFACTOR = 1795,
     KW_EXTENDS = 1798,
     TIME = 1800,
     KW_TODAY = 1807,
     KW_ROWID = 1808,
     CURSOR_NAME_FUNCTION = 2155
   };
#endif
/* Tokens.  */
#define INT_VALUE 2157
#define NAMED 2158
#define NAMED_GEN 2159
#define CHAR_VALUE 2160
#define NOT_USED_1 2161
#define NOT_USED_2 2162
#define NOT_USED_3 2163
#define NOT_USED_4 2164
#define NOT_USED_5 2165
#define NOT_USED_6 2166
#define NOT_USED_7 2167
#define NOT_USED_8 2168
#define NUMBER_VALUE 2169
#define SEMICOLON 2170
#define QUESTION_MARK 2171
#define CLINE 2172
#define CH 2173
#define MARK_VAR 2174
#define END_MARK_VAR 2175
#define LEFT_JOIN 1001
#define USING_BTREE 1013
#define USING_RTREE 1014
#define SET_BUFFERED_LOG 1038
#define SET_LOG 1039
#define MDY 1041
#define WEEKDAY 1042
#define MISC_INFX_SQL 1045
#define DATETIME_VALUE 1058
#define INTERVAL_VALUE 1059
#define RECOVER_TABLE 1060
#define ROLLFORWARD_DATABASE 1061
#define DROP_TRIGGER 1077
#define DROP_AUDIT_FOR 1078
#define CREATE_AUDIT_FOR 1079
#define EXECUTE_PROCEDURE 1083
#define ALTER_TABLE 1090
#define ALTER_INDEX 1091
#define NEXT_SIZE 1092
#define XSET_MULTIPLY_EQUAL_OPEN_BRACKET 1129
#define XSET_ident_DOT_MULTIPLY_EQUAL_OPEN_BRACKET 1130
#define XSET_ident_DOT_MULTIPLY_EQUAL 1131
#define XSET_MULTIPLY_EQUAL 1132
#define XSET_OPEN_BRACKET 1133
#define CREATE_DATABASE 1136
#define DROP_DATABASE 1137
#define ADD_CONSTRAINT 1139
#define DROP_CONSTRAINT 1140
#define DROP_SYNONYM 1141
#define CONSTRAINT 1142
#define LOCAL_REPORT 1146
#define LOCAL_PDF_REPORT 1147
#define DOUBLE_PRECISION 1151
#define COUNT_MULTIPLY 1152
#define MODIFY_NEXT_SIZE 1172
#define LOCK_MODE_PAGE 1173
#define LOCK_MODE_ROW 1174
#define UNITS_YEAR 1181
#define UNITS_MONTH 1182
#define UNITS_DAY 1183
#define UNITS_HOUR 1184
#define UNITS_MINUTE 1185
#define UNITS_SECOND 1186
#define TO_CLUSTER 1191
#define TO_NOT_CLUSTER 1192
#define CREATE_UC_IDX 1194
#define CREATE_U_IDX 1195
#define CREATE_C_IDX 1196
#define CREATE_IDX 1197
#define TYPECAST 1206
#define SQLSICS 1213
#define CREATE_SCHEMA 1214
#define SQLSIRR 1215
#define UPDATESTATS_T 1216
#define SQLSICR 1217
#define SQLSIDR 1228
#define CREATE_TEMP_TABLE 1229
#define WITH_CHECK_OPTION 1237
#define WITH_GRANT_OPTION 1238
#define SQLSLMNW 1239
#define WHERE_CURRENT_OF 1245
#define NOT_NULL_UNIQUE 1253
#define SQLSLMW 1260
#define ALL_PRIVILEGES 1262
#define CREATE_SYNONYM 1266
#define DROP_TABLE 1267
#define INEXCLUSIVE 1269
#define UPDATESTATS 1274
#define CREATE_TABLE 1300
#define DEFAULT_NULL 1301
#define DEFAULT_TODAY 1302
#define DEFAULT_USER 1303
#define UNLOCK_TABLE 1316
#define ROLLBACK_W 1324
#define SQLSEON 1326
#define SQLSEOFF 1327
#define CREATE_VIEW 1331
#define DELETE_FROM 1332
#define EXTENT_SIZE 1339
#define FOREIGN_KEY 1340
#define INSERT_INTO 1343
#define IS_NOT_NULL 1345
#define NOT_MATCHES 1348
#define PRIMARY_KEY 1354
#define USE_SESSION 1361
#define WITH_NO_LOG 1362
#define INSHARE 1365
#define BEGIN_WORK 1371
#define DROP_INDEX 1376
#define FOR_UPDATE_OF 1382
#define FOR_UPDATE 1383
#define LOCK_TABLE 1387
#define NOT_EXISTS 1389
#define REFERENCES 1391
#define RENCOL 1392
#define SMALLFLOAT 1394
#define COMMIT_W 1405
#define RENTAB 1412
#define KW_CHAR 1415
#define NCHAR 1416
#define NVARCHAR 1417
#define DELIMITER 1419
#define DROP_VIEW 1421
#define EXCLUSIVE 1424
#define GREATER_THAN_EQ 1428
#define INTO_TEMP 1430
#define LOAD_FROM 1434
#define UNLOAD_TO 1445
#define DATABASE 1454
#define DATETIME 1455
#define DISTINCT 1457
#define FRACTION 1464
#define GROUP_BY 1466
#define INTERVAL 1467
#define NOT_LIKE 1469
#define NOT_ILIKE 1470
#define NOT_NULL 1471
#define RESOURCE 1477
#define SMALLINT 1478
#define IS_NULL 1484
#define LESS_THAN_EQ 1485
#define BETWEEN 1487
#define CLOSE_BRACKET 1490
#define CONNECT 1493
#define KW_CURRENT 1494
#define KW_DECIMAL 1496
#define DEFAULT 1498
#define INTEGER 1506
#define SERIAL8 1508
#define MATCHES 1511
#define VARCHAR 1524
#define CLOSE_SQUARE 1527
#define GREATER_THAN 1528
#define KW_FALSE 1529
#define NOT_IN 1530
#define OPEN_BRACKET 1532
#define KW_DELETE 1540
#define KW_ESCAPE 1543
#define EXISTS 1544
#define EXTEND 1545
#define HAVING 1549
#define KW_INSERT 1551
#define MINUTE 1555
#define MODIFY 1556
#define EQUAL 1558
#define NOT_EQUAL 1559
#define OPEN_SQUARE 1561
#define PUBLIC 1565
#define REVOKE 1568
#define SECOND 1572
#define KW_SELECT 1576
#define SERIAL 1577
#define UNIQUE 1580
#define KW_UPDATE 1582
#define VALUES 1583
#define KW_NULL 1587
#define KW_TRUE 1588
#define ALTER 1590
#define CHECK 1596
#define COUNT 1600
#define KW_FIRST 1605
#define KW_FLOAT 1606
#define GRANT 1609
#define INDEX 1612
#define LESS_THAN 1615
#define MONEY 1617
#define MONTH 1618
#define KW_MULTIPLY 1620
#define ORDER 1621
#define OUTER 1622
#define UNION 1631
#define WHERE 1633
#define KW_BYTE 1640
#define CASE 1642
#define KW_DATE 1644
#define DESC 1645
#define KW_DIVIDE 1646
#define DROP 1649
#define ELSE 1650
#define FROM 1654
#define HOUR 1660
#define INTO 1661
#define LIKE 1664
#define REAL 1673
#define SOME 1678
#define KW_TEXT 1682
#define KW_THEN 1683
#define USER 1684
#define WHEN 1686
#define YEAR 1689
#define KW_DOW 1690
#define XSET 1692
#define ADD 1693
#define ALL 1694
#define KW_AND 1695
#define ANY 1696
#define ASC 1697
#define AVG 1698
#define COLON 1699
#define KW_COMMA 1700
#define DAY 1701
#define DBA 1702
#define KW_FOR 1706
#define XMAX 1711
#define XMIN 1712
#define KW_MINUS 1713
#define KW_MOD 1714
#define KW_NOT 1715
#define KW_ROW 1719
#define KW_SUM 1722
#define ATSIGN 1725
#define KW_PLUS 1726
#define KW_AS_USER 1731
#define KW_AS 1732
#define KW_BY 1734
#define KW_DOT 1735
#define KW_IN 1738
#define KW_ON 1740
#define KW_OR 1741
#define KW_TO 1742
#define BEFORE 1780
#define END 1784
#define TILDE 1791
#define ILIKE 1792
#define FILLFACTOR 1795
#define KW_EXTENDS 1798
#define TIME 1800
#define KW_TODAY 1807
#define KW_ROWID 1808
#define CURSOR_NAME_FUNCTION 2155




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
#line 574 "y.tab.h"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE sqlparse_yylval;

