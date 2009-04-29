
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
     INT_VALUE = 2181,
     NAMED = 2182,
     NAMED_GEN = 2183,
     CHAR_VALUE = 2184,
     NOT_USED_1 = 2185,
     NOT_USED_2 = 2186,
     NOT_USED_3 = 2187,
     NOT_USED_4 = 2188,
     NOT_USED_5 = 2189,
     NOT_USED_6 = 2190,
     NOT_USED_7 = 2191,
     NOT_USED_8 = 2192,
     NUMBER_VALUE = 2193,
     SEMICOLON = 2194,
     QUESTION_MARK = 2195,
     CLINE = 2196,
     CH = 2197,
     MARK_VAR = 2198,
     END_MARK_VAR = 2199,
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
     DOUBLE_PRECISION = 1172,
     COUNT_MULTIPLY = 1173,
     MODIFY_NEXT_SIZE = 1193,
     LOCK_MODE_PAGE = 1194,
     LOCK_MODE_ROW = 1195,
     UNITS_YEAR = 1202,
     UNITS_MONTH = 1203,
     UNITS_DAY = 1204,
     UNITS_HOUR = 1205,
     UNITS_MINUTE = 1206,
     UNITS_SECOND = 1207,
     TO_CLUSTER = 1212,
     TO_NOT_CLUSTER = 1213,
     CREATE_UC_IDX = 1215,
     CREATE_U_IDX = 1216,
     CREATE_C_IDX = 1217,
     CREATE_IDX = 1218,
     DOUBLE_COLON = 1228,
     SQLSICS = 1234,
     CREATE_SCHEMA = 1235,
     SQLSIRR = 1236,
     UPDATESTATS_T = 1237,
     SQLSICR = 1238,
     SQLSIDR = 1249,
     CREATE_TEMP_TABLE = 1250,
     WITH_CHECK_OPTION = 1258,
     WITH_GRANT_OPTION = 1259,
     SQLSLMNW = 1260,
     WHERE_CURRENT_OF = 1266,
     NOT_NULL_UNIQUE = 1274,
     SQLSLMW = 1281,
     ALL_PRIVILEGES = 1283,
     CREATE_SYNONYM = 1287,
     DROP_TABLE = 1288,
     INEXCLUSIVE = 1290,
     UPDATESTATS = 1295,
     CREATE_TABLE = 1321,
     DEFAULT_NULL = 1322,
     DEFAULT_TODAY = 1323,
     DEFAULT_USER = 1324,
     UNLOCK_TABLE = 1337,
     ROLLBACK_W = 1345,
     SQLSEON = 1347,
     SQLSEOFF = 1348,
     CREATE_VIEW = 1352,
     DELETE_FROM = 1353,
     EXTENT_SIZE = 1360,
     FOREIGN_KEY = 1361,
     INSERT_INTO = 1364,
     IS_NOT_NULL = 1366,
     NOT_MATCHES = 1369,
     PRIMARY_KEY = 1375,
     USE_SESSION = 1382,
     WITH_NO_LOG = 1383,
     INSHARE = 1386,
     BEGIN_WORK = 1392,
     DROP_INDEX = 1397,
     FOR_UPDATE_OF = 1403,
     FOR_UPDATE = 1404,
     LOCK_TABLE = 1409,
     NOT_EXISTS = 1411,
     REFERENCES = 1413,
     RENCOL = 1414,
     SMALLFLOAT = 1416,
     COMMIT_W = 1427,
     RENTAB = 1434,
     KW_CHAR = 1437,
     NCHAR = 1438,
     NVARCHAR = 1439,
     DELIMITER = 1441,
     DROP_VIEW = 1443,
     EXCLUSIVE = 1446,
     GREATER_THAN_EQ = 1450,
     INTO_TEMP = 1452,
     DATABASE = 1476,
     DATETIME = 1477,
     DISTINCT = 1479,
     FRACTION = 1486,
     GROUP_BY = 1488,
     INTERVAL = 1489,
     NOT_LIKE = 1491,
     NOT_ILIKE = 1492,
     NOT_NULL = 1493,
     RESOURCE = 1499,
     SMALLINT = 1500,
     IS_NULL = 1506,
     LESS_THAN_EQ = 1507,
     BETWEEN = 1509,
     CLOSE_BRACKET = 1512,
     CONNECT = 1515,
     KW_CURRENT = 1516,
     KW_DECIMAL = 1518,
     DEFAULT = 1520,
     INTEGER = 1528,
     SERIAL8 = 1530,
     MATCHES = 1533,
     VARCHAR = 1546,
     CLOSE_SQUARE = 1549,
     GREATER_THAN = 1550,
     KW_FALSE = 1551,
     NOT_IN = 1552,
     OPEN_BRACKET = 1554,
     KW_DELETE = 1562,
     KW_ESCAPE = 1565,
     EXISTS = 1566,
     EXTEND = 1567,
     HAVING = 1571,
     KW_INSERT = 1573,
     MINUTE = 1577,
     MODIFY = 1578,
     EQUAL = 1580,
     NOT_EQUAL = 1581,
     OPEN_SQUARE = 1583,
     PUBLIC = 1587,
     REVOKE = 1591,
     SECOND = 1595,
     KW_SELECT = 1599,
     SERIAL = 1600,
     UNIQUE = 1603,
     KW_UPDATE = 1605,
     VALUES = 1606,
     KW_NULL = 1609,
     KW_TRUE = 1610,
     ALTER = 1612,
     CHECK = 1618,
     COUNT = 1622,
     KW_FIRST = 1627,
     KW_FLOAT = 1628,
     GRANT = 1631,
     INDEX = 1634,
     LESS_THAN = 1637,
     MONEY = 1639,
     MONTH = 1640,
     KW_MULTIPLY = 1642,
     ORDER = 1643,
     OUTER = 1644,
     UNION = 1653,
     WHERE = 1656,
     KW_BYTE = 1663,
     CASE = 1665,
     KW_DATE = 1667,
     DESC = 1668,
     KW_DIVIDE = 1669,
     DROP = 1672,
     ELSE = 1673,
     FROM = 1677,
     HOUR = 1683,
     INTO = 1684,
     LIKE = 1687,
     REAL = 1696,
     SOME = 1701,
     KW_TEXT = 1705,
     KW_THEN = 1706,
     USER = 1707,
     WHEN = 1709,
     YEAR = 1712,
     KW_DOW = 1713,
     XSET = 1715,
     ADD = 1716,
     ALL = 1717,
     KW_AND = 1718,
     ANY = 1719,
     ASC = 1720,
     AVG = 1721,
     COLON = 1722,
     KW_COMMA = 1723,
     DAY = 1724,
     DBA = 1725,
     KW_FOR = 1729,
     XMAX = 1734,
     XMIN = 1735,
     KW_MINUS = 1736,
     KW_MOD = 1737,
     KW_NOT = 1738,
     KW_SUM = 1745,
     ATSIGN = 1748,
     KW_PLUS = 1749,
     KW_AS = 1755,
     KW_BY = 1757,
     KW_DOT = 1758,
     KW_IN = 1761,
     KW_ON = 1763,
     KW_OR = 1764,
     KW_TO = 1765,
     BEFORE = 1803,
     END = 1807,
     TILDE = 1814,
     ILIKE = 1815,
     FILLFACTOR = 1818,
     TIME = 1823,
     KW_TODAY = 1830,
     KW_ROWID = 1831,
     TIMESTAMP = 2179
   };
#endif
/* Tokens.  */
#define INT_VALUE 2181
#define NAMED 2182
#define NAMED_GEN 2183
#define CHAR_VALUE 2184
#define NOT_USED_1 2185
#define NOT_USED_2 2186
#define NOT_USED_3 2187
#define NOT_USED_4 2188
#define NOT_USED_5 2189
#define NOT_USED_6 2190
#define NOT_USED_7 2191
#define NOT_USED_8 2192
#define NUMBER_VALUE 2193
#define SEMICOLON 2194
#define QUESTION_MARK 2195
#define CLINE 2196
#define CH 2197
#define MARK_VAR 2198
#define END_MARK_VAR 2199
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
#define DOUBLE_PRECISION 1172
#define COUNT_MULTIPLY 1173
#define MODIFY_NEXT_SIZE 1193
#define LOCK_MODE_PAGE 1194
#define LOCK_MODE_ROW 1195
#define UNITS_YEAR 1202
#define UNITS_MONTH 1203
#define UNITS_DAY 1204
#define UNITS_HOUR 1205
#define UNITS_MINUTE 1206
#define UNITS_SECOND 1207
#define TO_CLUSTER 1212
#define TO_NOT_CLUSTER 1213
#define CREATE_UC_IDX 1215
#define CREATE_U_IDX 1216
#define CREATE_C_IDX 1217
#define CREATE_IDX 1218
#define DOUBLE_COLON 1228
#define SQLSICS 1234
#define CREATE_SCHEMA 1235
#define SQLSIRR 1236
#define UPDATESTATS_T 1237
#define SQLSICR 1238
#define SQLSIDR 1249
#define CREATE_TEMP_TABLE 1250
#define WITH_CHECK_OPTION 1258
#define WITH_GRANT_OPTION 1259
#define SQLSLMNW 1260
#define WHERE_CURRENT_OF 1266
#define NOT_NULL_UNIQUE 1274
#define SQLSLMW 1281
#define ALL_PRIVILEGES 1283
#define CREATE_SYNONYM 1287
#define DROP_TABLE 1288
#define INEXCLUSIVE 1290
#define UPDATESTATS 1295
#define CREATE_TABLE 1321
#define DEFAULT_NULL 1322
#define DEFAULT_TODAY 1323
#define DEFAULT_USER 1324
#define UNLOCK_TABLE 1337
#define ROLLBACK_W 1345
#define SQLSEON 1347
#define SQLSEOFF 1348
#define CREATE_VIEW 1352
#define DELETE_FROM 1353
#define EXTENT_SIZE 1360
#define FOREIGN_KEY 1361
#define INSERT_INTO 1364
#define IS_NOT_NULL 1366
#define NOT_MATCHES 1369
#define PRIMARY_KEY 1375
#define USE_SESSION 1382
#define WITH_NO_LOG 1383
#define INSHARE 1386
#define BEGIN_WORK 1392
#define DROP_INDEX 1397
#define FOR_UPDATE_OF 1403
#define FOR_UPDATE 1404
#define LOCK_TABLE 1409
#define NOT_EXISTS 1411
#define REFERENCES 1413
#define RENCOL 1414
#define SMALLFLOAT 1416
#define COMMIT_W 1427
#define RENTAB 1434
#define KW_CHAR 1437
#define NCHAR 1438
#define NVARCHAR 1439
#define DELIMITER 1441
#define DROP_VIEW 1443
#define EXCLUSIVE 1446
#define GREATER_THAN_EQ 1450
#define INTO_TEMP 1452
#define DATABASE 1476
#define DATETIME 1477
#define DISTINCT 1479
#define FRACTION 1486
#define GROUP_BY 1488
#define INTERVAL 1489
#define NOT_LIKE 1491
#define NOT_ILIKE 1492
#define NOT_NULL 1493
#define RESOURCE 1499
#define SMALLINT 1500
#define IS_NULL 1506
#define LESS_THAN_EQ 1507
#define BETWEEN 1509
#define CLOSE_BRACKET 1512
#define CONNECT 1515
#define KW_CURRENT 1516
#define KW_DECIMAL 1518
#define DEFAULT 1520
#define INTEGER 1528
#define SERIAL8 1530
#define MATCHES 1533
#define VARCHAR 1546
#define CLOSE_SQUARE 1549
#define GREATER_THAN 1550
#define KW_FALSE 1551
#define NOT_IN 1552
#define OPEN_BRACKET 1554
#define KW_DELETE 1562
#define KW_ESCAPE 1565
#define EXISTS 1566
#define EXTEND 1567
#define HAVING 1571
#define KW_INSERT 1573
#define MINUTE 1577
#define MODIFY 1578
#define EQUAL 1580
#define NOT_EQUAL 1581
#define OPEN_SQUARE 1583
#define PUBLIC 1587
#define REVOKE 1591
#define SECOND 1595
#define KW_SELECT 1599
#define SERIAL 1600
#define UNIQUE 1603
#define KW_UPDATE 1605
#define VALUES 1606
#define KW_NULL 1609
#define KW_TRUE 1610
#define ALTER 1612
#define CHECK 1618
#define COUNT 1622
#define KW_FIRST 1627
#define KW_FLOAT 1628
#define GRANT 1631
#define INDEX 1634
#define LESS_THAN 1637
#define MONEY 1639
#define MONTH 1640
#define KW_MULTIPLY 1642
#define ORDER 1643
#define OUTER 1644
#define UNION 1653
#define WHERE 1656
#define KW_BYTE 1663
#define CASE 1665
#define KW_DATE 1667
#define DESC 1668
#define KW_DIVIDE 1669
#define DROP 1672
#define ELSE 1673
#define FROM 1677
#define HOUR 1683
#define INTO 1684
#define LIKE 1687
#define REAL 1696
#define SOME 1701
#define KW_TEXT 1705
#define KW_THEN 1706
#define USER 1707
#define WHEN 1709
#define YEAR 1712
#define KW_DOW 1713
#define XSET 1715
#define ADD 1716
#define ALL 1717
#define KW_AND 1718
#define ANY 1719
#define ASC 1720
#define AVG 1721
#define COLON 1722
#define KW_COMMA 1723
#define DAY 1724
#define DBA 1725
#define KW_FOR 1729
#define XMAX 1734
#define XMIN 1735
#define KW_MINUS 1736
#define KW_MOD 1737
#define KW_NOT 1738
#define KW_SUM 1745
#define ATSIGN 1748
#define KW_PLUS 1749
#define KW_AS 1755
#define KW_BY 1757
#define KW_DOT 1758
#define KW_IN 1761
#define KW_ON 1763
#define KW_OR 1764
#define KW_TO 1765
#define BEFORE 1803
#define END 1807
#define TILDE 1814
#define ILIKE 1815
#define FILLFACTOR 1818
#define TIME 1823
#define KW_TODAY 1830
#define KW_ROWID 1831
#define TIMESTAMP 2179




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
#line 573 "y.tab.h"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE sqlparse_yylval;


