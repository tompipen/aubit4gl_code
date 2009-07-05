
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
     INT_VALUE = 2212,
     NAMED = 2213,
     NAMED_GEN = 2214,
     CHAR_VALUE = 2215,
     NOT_USED_1 = 2216,
     NOT_USED_2 = 2217,
     NOT_USED_3 = 2218,
     NOT_USED_4 = 2219,
     NOT_USED_5 = 2220,
     NOT_USED_6 = 2221,
     NOT_USED_7 = 2222,
     NOT_USED_8 = 2223,
     NUMBER_VALUE = 2224,
     SEMICOLON = 2225,
     QUESTION_MARK = 2226,
     CLINE = 2227,
     CH = 2228,
     MARK_VAR = 2229,
     END_MARK_VAR = 2230,
     LEFT_JOIN = 1002,
     DISPLAY_NULL_TO = 1005,
     UNBUFFERED = 1006,
     KW_PICTURE = 1007,
     ON_CHANGE = 1008,
     INNER_JOIN = 1009,
     UI_INTERFACE_DOT_FRONTCALL = 1012,
     UICOMBOBOX = 1016,
     UIFORM = 1019,
     USING_BTREE = 1035,
     USING_RTREE = 1036,
     SET_BUFFERED_LOG = 1061,
     SET_LOG = 1064,
     MDY = 1066,
     WEEKDAY = 1067,
     MODE_ANSI = 1070,
     START_DATABASE = 1071,
     WITH_LOG_IN = 1072,
     SET_CONSTRAINTS_ALL_IMMEDIATE = 1073,
     DATETIME_VALUE = 1086,
     INTERVAL_VALUE = 1087,
     RECOVER_TABLE = 1088,
     ROLLFORWARD_DATABASE = 1089,
     DROP_TRIGGER = 1105,
     DROP_AUDIT_FOR = 1106,
     CREATE_AUDIT_FOR = 1107,
     EXECUTE_PROCEDURE = 1111,
     ALTER_TABLE = 1118,
     ALTER_INDEX = 1119,
     NEXT_SIZE = 1120,
     XSET_MULTIPLY_EQUAL_OPEN_BRACKET = 1157,
     XSET_ident_DOT_MULTIPLY_EQUAL_OPEN_BRACKET = 1158,
     XSET_ident_DOT_MULTIPLY_EQUAL = 1159,
     XSET_MULTIPLY_EQUAL = 1160,
     XSET_OPEN_BRACKET = 1161,
     CREATE_DATABASE = 1164,
     DROP_DATABASE = 1165,
     ADD_CONSTRAINT = 1167,
     DROP_CONSTRAINT = 1168,
     DROP_SYNONYM = 1169,
     CONSTRAINT = 1170,
     NOT_FIELD_TOUCHED_CURRENT = 1173,
     FIELD_TOUCHED_CURRENT = 1174,
     DOUBLE_PRECISION = 1181,
     COUNT_MULTIPLY = 1182,
     MODIFY_NEXT_SIZE = 1202,
     LOCK_MODE_PAGE = 1203,
     LOCK_MODE_ROW = 1204,
     UNITS_YEAR = 1211,
     UNITS_MONTH = 1212,
     UNITS_DAY = 1213,
     UNITS_HOUR = 1214,
     UNITS_MINUTE = 1215,
     UNITS_SECOND = 1216,
     TO_CLUSTER = 1221,
     TO_NOT_CLUSTER = 1222,
     CREATE_UC_IDX = 1224,
     CREATE_U_IDX = 1225,
     CREATE_C_IDX = 1226,
     CREATE_IDX = 1227,
     DOUBLE_COLON = 1237,
     SQLSICS = 1243,
     CREATE_SCHEMA = 1244,
     SQLSIRR = 1245,
     UPDATESTATS_T = 1246,
     SQLSICR = 1247,
     SQLSIDR = 1258,
     CREATE_TEMP_TABLE = 1259,
     WITH_CHECK_OPTION = 1267,
     WITH_GRANT_OPTION = 1268,
     SQLSLMNW = 1269,
     WHERE_CURRENT_OF = 1275,
     NOT_NULL_UNIQUE = 1283,
     SQLSLMW = 1290,
     ALL_PRIVILEGES = 1292,
     CREATE_SYNONYM = 1296,
     DROP_TABLE = 1297,
     INEXCLUSIVE = 1299,
     UPDATESTATS = 1304,
     CREATE_TABLE = 1330,
     DEFAULT_NULL = 1331,
     DEFAULT_TODAY = 1332,
     DEFAULT_USER = 1333,
     UNLOCK_TABLE = 1346,
     ROLLBACK_W = 1354,
     SQLSEON = 1356,
     SQLSEOFF = 1357,
     CREATE_VIEW = 1361,
     DELETE_FROM = 1362,
     EXTENT_SIZE = 1369,
     FOREIGN_KEY = 1370,
     INSERT_INTO = 1373,
     IS_NOT_NULL = 1375,
     NOT_MATCHES = 1378,
     PRIMARY_KEY = 1384,
     USE_SESSION = 1391,
     WITH_NO_LOG = 1392,
     INSHARE = 1395,
     BEGIN_WORK = 1401,
     DROP_INDEX = 1406,
     FOR_UPDATE_OF = 1412,
     FOR_UPDATE = 1413,
     LOCK_TABLE = 1418,
     NOT_EXISTS = 1420,
     REFERENCES = 1422,
     RENCOL = 1423,
     SMALLFLOAT = 1425,
     COMMIT_W = 1436,
     RENTAB = 1443,
     KW_CHAR = 1446,
     NCHAR = 1447,
     NVARCHAR = 1448,
     DELIMITER = 1450,
     DROP_VIEW = 1452,
     EXCLUSIVE = 1455,
     GREATER_THAN_EQ = 1459,
     INTO_TEMP = 1461,
     DATABASE = 1485,
     DATETIME = 1486,
     DISTINCT = 1488,
     FRACTION = 1495,
     GROUP_BY = 1497,
     INTERVAL = 1498,
     NOT_LIKE = 1500,
     NOT_ILIKE = 1501,
     NOT_NULL = 1502,
     RESOURCE = 1508,
     SMALLINT = 1509,
     IS_NULL = 1515,
     LESS_THAN_EQ = 1516,
     BETWEEN = 1518,
     CLOSE_BRACKET = 1521,
     CONNECT = 1524,
     KW_CURRENT = 1525,
     KW_DECIMAL = 1527,
     DEFAULT = 1529,
     INTEGER = 1537,
     SERIAL8 = 1539,
     MATCHES = 1542,
     VARCHAR = 1555,
     CLOSE_SQUARE = 1558,
     GREATER_THAN = 1559,
     KW_FALSE = 1560,
     NOT_IN = 1561,
     OPEN_BRACKET = 1563,
     KW_DELETE = 1571,
     KW_ESCAPE = 1574,
     EXISTS = 1575,
     EXTEND = 1576,
     HAVING = 1580,
     KW_INSERT = 1582,
     MINUTE = 1586,
     MODIFY = 1587,
     EQUAL = 1589,
     NOT_EQUAL = 1590,
     OPEN_SQUARE = 1592,
     PUBLIC = 1596,
     REVOKE = 1600,
     SECOND = 1604,
     KW_SELECT = 1608,
     SERIAL = 1609,
     UNIQUE = 1612,
     KW_UPDATE = 1614,
     VALUES = 1615,
     KW_NULL = 1618,
     KW_TRUE = 1619,
     ALTER = 1621,
     CHECK = 1627,
     COUNT = 1631,
     KW_FIRST = 1636,
     KW_FLOAT = 1637,
     GRANT = 1640,
     INDEX = 1643,
     LESS_THAN = 1646,
     MONEY = 1648,
     MONTH = 1649,
     KW_MULTIPLY = 1651,
     ORDER = 1652,
     OUTER = 1653,
     UNION = 1662,
     WHERE = 1665,
     KW_BYTE = 1672,
     CASE = 1674,
     KW_DATE = 1676,
     DESC = 1677,
     KW_DIVIDE = 1678,
     DROP = 1681,
     ELSE = 1682,
     FROM = 1686,
     HOUR = 1692,
     INTO = 1693,
     LIKE = 1696,
     REAL = 1705,
     SOME = 1710,
     KW_TEXT = 1714,
     KW_THEN = 1715,
     USER = 1716,
     WHEN = 1718,
     YEAR = 1721,
     KW_DOW = 1722,
     XSET = 1724,
     ADD = 1725,
     ALL = 1726,
     KW_AND = 1727,
     ANY = 1728,
     ASC = 1729,
     AVG = 1730,
     COLON = 1731,
     KW_COMMA = 1732,
     DAY = 1733,
     DBA = 1734,
     KW_FOR = 1738,
     XMAX = 1743,
     XMIN = 1744,
     KW_MINUS = 1745,
     KW_MOD = 1746,
     KW_NOT = 1747,
     KW_SUM = 1754,
     ATSIGN = 1757,
     KW_PLUS = 1758,
     KW_AS = 1764,
     KW_BY = 1766,
     KW_DOT = 1767,
     KW_IN = 1770,
     KW_ON = 1772,
     KW_OR = 1773,
     KW_TO = 1774,
     BEFORE = 1812,
     END = 1816,
     TILDE = 1823,
     ILIKE = 1824,
     FILLFACTOR = 1827,
     TIME = 1832,
     KW_TODAY = 1839,
     KW_ROWID = 1840,
     TIMESTAMP = 2188,
     KW_TAG = 2209,
     LINTMODULEISLIBRARY = 2210
   };
#endif
/* Tokens.  */
#define INT_VALUE 2212
#define NAMED 2213
#define NAMED_GEN 2214
#define CHAR_VALUE 2215
#define NOT_USED_1 2216
#define NOT_USED_2 2217
#define NOT_USED_3 2218
#define NOT_USED_4 2219
#define NOT_USED_5 2220
#define NOT_USED_6 2221
#define NOT_USED_7 2222
#define NOT_USED_8 2223
#define NUMBER_VALUE 2224
#define SEMICOLON 2225
#define QUESTION_MARK 2226
#define CLINE 2227
#define CH 2228
#define MARK_VAR 2229
#define END_MARK_VAR 2230
#define LEFT_JOIN 1002
#define DISPLAY_NULL_TO 1005
#define UNBUFFERED 1006
#define KW_PICTURE 1007
#define ON_CHANGE 1008
#define INNER_JOIN 1009
#define UI_INTERFACE_DOT_FRONTCALL 1012
#define UICOMBOBOX 1016
#define UIFORM 1019
#define USING_BTREE 1035
#define USING_RTREE 1036
#define SET_BUFFERED_LOG 1061
#define SET_LOG 1064
#define MDY 1066
#define WEEKDAY 1067
#define MODE_ANSI 1070
#define START_DATABASE 1071
#define WITH_LOG_IN 1072
#define SET_CONSTRAINTS_ALL_IMMEDIATE 1073
#define DATETIME_VALUE 1086
#define INTERVAL_VALUE 1087
#define RECOVER_TABLE 1088
#define ROLLFORWARD_DATABASE 1089
#define DROP_TRIGGER 1105
#define DROP_AUDIT_FOR 1106
#define CREATE_AUDIT_FOR 1107
#define EXECUTE_PROCEDURE 1111
#define ALTER_TABLE 1118
#define ALTER_INDEX 1119
#define NEXT_SIZE 1120
#define XSET_MULTIPLY_EQUAL_OPEN_BRACKET 1157
#define XSET_ident_DOT_MULTIPLY_EQUAL_OPEN_BRACKET 1158
#define XSET_ident_DOT_MULTIPLY_EQUAL 1159
#define XSET_MULTIPLY_EQUAL 1160
#define XSET_OPEN_BRACKET 1161
#define CREATE_DATABASE 1164
#define DROP_DATABASE 1165
#define ADD_CONSTRAINT 1167
#define DROP_CONSTRAINT 1168
#define DROP_SYNONYM 1169
#define CONSTRAINT 1170
#define NOT_FIELD_TOUCHED_CURRENT 1173
#define FIELD_TOUCHED_CURRENT 1174
#define DOUBLE_PRECISION 1181
#define COUNT_MULTIPLY 1182
#define MODIFY_NEXT_SIZE 1202
#define LOCK_MODE_PAGE 1203
#define LOCK_MODE_ROW 1204
#define UNITS_YEAR 1211
#define UNITS_MONTH 1212
#define UNITS_DAY 1213
#define UNITS_HOUR 1214
#define UNITS_MINUTE 1215
#define UNITS_SECOND 1216
#define TO_CLUSTER 1221
#define TO_NOT_CLUSTER 1222
#define CREATE_UC_IDX 1224
#define CREATE_U_IDX 1225
#define CREATE_C_IDX 1226
#define CREATE_IDX 1227
#define DOUBLE_COLON 1237
#define SQLSICS 1243
#define CREATE_SCHEMA 1244
#define SQLSIRR 1245
#define UPDATESTATS_T 1246
#define SQLSICR 1247
#define SQLSIDR 1258
#define CREATE_TEMP_TABLE 1259
#define WITH_CHECK_OPTION 1267
#define WITH_GRANT_OPTION 1268
#define SQLSLMNW 1269
#define WHERE_CURRENT_OF 1275
#define NOT_NULL_UNIQUE 1283
#define SQLSLMW 1290
#define ALL_PRIVILEGES 1292
#define CREATE_SYNONYM 1296
#define DROP_TABLE 1297
#define INEXCLUSIVE 1299
#define UPDATESTATS 1304
#define CREATE_TABLE 1330
#define DEFAULT_NULL 1331
#define DEFAULT_TODAY 1332
#define DEFAULT_USER 1333
#define UNLOCK_TABLE 1346
#define ROLLBACK_W 1354
#define SQLSEON 1356
#define SQLSEOFF 1357
#define CREATE_VIEW 1361
#define DELETE_FROM 1362
#define EXTENT_SIZE 1369
#define FOREIGN_KEY 1370
#define INSERT_INTO 1373
#define IS_NOT_NULL 1375
#define NOT_MATCHES 1378
#define PRIMARY_KEY 1384
#define USE_SESSION 1391
#define WITH_NO_LOG 1392
#define INSHARE 1395
#define BEGIN_WORK 1401
#define DROP_INDEX 1406
#define FOR_UPDATE_OF 1412
#define FOR_UPDATE 1413
#define LOCK_TABLE 1418
#define NOT_EXISTS 1420
#define REFERENCES 1422
#define RENCOL 1423
#define SMALLFLOAT 1425
#define COMMIT_W 1436
#define RENTAB 1443
#define KW_CHAR 1446
#define NCHAR 1447
#define NVARCHAR 1448
#define DELIMITER 1450
#define DROP_VIEW 1452
#define EXCLUSIVE 1455
#define GREATER_THAN_EQ 1459
#define INTO_TEMP 1461
#define DATABASE 1485
#define DATETIME 1486
#define DISTINCT 1488
#define FRACTION 1495
#define GROUP_BY 1497
#define INTERVAL 1498
#define NOT_LIKE 1500
#define NOT_ILIKE 1501
#define NOT_NULL 1502
#define RESOURCE 1508
#define SMALLINT 1509
#define IS_NULL 1515
#define LESS_THAN_EQ 1516
#define BETWEEN 1518
#define CLOSE_BRACKET 1521
#define CONNECT 1524
#define KW_CURRENT 1525
#define KW_DECIMAL 1527
#define DEFAULT 1529
#define INTEGER 1537
#define SERIAL8 1539
#define MATCHES 1542
#define VARCHAR 1555
#define CLOSE_SQUARE 1558
#define GREATER_THAN 1559
#define KW_FALSE 1560
#define NOT_IN 1561
#define OPEN_BRACKET 1563
#define KW_DELETE 1571
#define KW_ESCAPE 1574
#define EXISTS 1575
#define EXTEND 1576
#define HAVING 1580
#define KW_INSERT 1582
#define MINUTE 1586
#define MODIFY 1587
#define EQUAL 1589
#define NOT_EQUAL 1590
#define OPEN_SQUARE 1592
#define PUBLIC 1596
#define REVOKE 1600
#define SECOND 1604
#define KW_SELECT 1608
#define SERIAL 1609
#define UNIQUE 1612
#define KW_UPDATE 1614
#define VALUES 1615
#define KW_NULL 1618
#define KW_TRUE 1619
#define ALTER 1621
#define CHECK 1627
#define COUNT 1631
#define KW_FIRST 1636
#define KW_FLOAT 1637
#define GRANT 1640
#define INDEX 1643
#define LESS_THAN 1646
#define MONEY 1648
#define MONTH 1649
#define KW_MULTIPLY 1651
#define ORDER 1652
#define OUTER 1653
#define UNION 1662
#define WHERE 1665
#define KW_BYTE 1672
#define CASE 1674
#define KW_DATE 1676
#define DESC 1677
#define KW_DIVIDE 1678
#define DROP 1681
#define ELSE 1682
#define FROM 1686
#define HOUR 1692
#define INTO 1693
#define LIKE 1696
#define REAL 1705
#define SOME 1710
#define KW_TEXT 1714
#define KW_THEN 1715
#define USER 1716
#define WHEN 1718
#define YEAR 1721
#define KW_DOW 1722
#define XSET 1724
#define ADD 1725
#define ALL 1726
#define KW_AND 1727
#define ANY 1728
#define ASC 1729
#define AVG 1730
#define COLON 1731
#define KW_COMMA 1732
#define DAY 1733
#define DBA 1734
#define KW_FOR 1738
#define XMAX 1743
#define XMIN 1744
#define KW_MINUS 1745
#define KW_MOD 1746
#define KW_NOT 1747
#define KW_SUM 1754
#define ATSIGN 1757
#define KW_PLUS 1758
#define KW_AS 1764
#define KW_BY 1766
#define KW_DOT 1767
#define KW_IN 1770
#define KW_ON 1772
#define KW_OR 1773
#define KW_TO 1774
#define BEFORE 1812
#define END 1816
#define TILDE 1823
#define ILIKE 1824
#define FILLFACTOR 1827
#define TIME 1832
#define KW_TODAY 1839
#define KW_ROWID 1840
#define TIMESTAMP 2188
#define KW_TAG 2209
#define LINTMODULEISLIBRARY 2210




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
#line 595 "y.tab.h"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE sqlparse_yylval;


