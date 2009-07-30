
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
     INT_VALUE = 2215,
     NAMED = 2216,
     NAMED_GEN = 2217,
     CHAR_VALUE = 2218,
     NOT_USED_1 = 2219,
     NOT_USED_2 = 2220,
     NOT_USED_3 = 2221,
     NOT_USED_4 = 2222,
     NOT_USED_5 = 2223,
     NOT_USED_6 = 2224,
     NOT_USED_7 = 2225,
     NOT_USED_8 = 2226,
     NUMBER_VALUE = 2227,
     SEMICOLON = 2228,
     QUESTION_MARK = 2229,
     CLINE = 2230,
     CH = 2231,
     MARK_VAR = 2232,
     END_MARK_VAR = 2233,
     KW_RUN_CLIENT = 1001,
     LEFT_JOIN = 1003,
     DISPLAY_NULL_TO = 1006,
     UNBUFFERED = 1007,
     KW_PICTURE = 1008,
     ON_CHANGE = 1009,
     INNER_JOIN = 1010,
     UI_INTERFACE_DOT_FRONTCALL = 1013,
     UICOMBOBOX = 1017,
     UIFORM = 1020,
     USING_BTREE = 1036,
     USING_RTREE = 1037,
     SET_BUFFERED_LOG = 1062,
     SET_LOG = 1065,
     MDY = 1067,
     WEEKDAY = 1068,
     MODE_ANSI = 1071,
     START_DATABASE = 1072,
     WITH_LOG_IN = 1073,
     SET_CONSTRAINTS_ALL_IMMEDIATE = 1074,
     DATETIME_VALUE = 1087,
     INTERVAL_VALUE = 1088,
     RECOVER_TABLE = 1089,
     ROLLFORWARD_DATABASE = 1090,
     DROP_TRIGGER = 1106,
     DROP_AUDIT_FOR = 1107,
     CREATE_AUDIT_FOR = 1108,
     EXECUTE_PROCEDURE = 1112,
     ALTER_TABLE = 1119,
     ALTER_INDEX = 1120,
     NEXT_SIZE = 1121,
     XSET_MULTIPLY_EQUAL_OPEN_BRACKET = 1158,
     XSET_ident_DOT_MULTIPLY_EQUAL_OPEN_BRACKET = 1159,
     XSET_ident_DOT_MULTIPLY_EQUAL = 1160,
     XSET_MULTIPLY_EQUAL = 1161,
     XSET_OPEN_BRACKET = 1162,
     CREATE_DATABASE = 1165,
     DROP_DATABASE = 1166,
     ADD_CONSTRAINT = 1168,
     DROP_CONSTRAINT = 1169,
     DROP_SYNONYM = 1170,
     CONSTRAINT = 1171,
     NOT_FIELD_TOUCHED_CURRENT = 1174,
     FIELD_TOUCHED_CURRENT = 1175,
     DOUBLE_PRECISION = 1182,
     COUNT_MULTIPLY = 1183,
     MODIFY_NEXT_SIZE = 1203,
     LOCK_MODE_PAGE = 1204,
     LOCK_MODE_ROW = 1205,
     UNITS_YEAR = 1212,
     UNITS_MONTH = 1213,
     UNITS_DAY = 1214,
     UNITS_HOUR = 1215,
     UNITS_MINUTE = 1216,
     UNITS_SECOND = 1217,
     TO_CLUSTER = 1222,
     TO_NOT_CLUSTER = 1223,
     CREATE_UC_IDX = 1225,
     CREATE_U_IDX = 1226,
     CREATE_C_IDX = 1227,
     CREATE_IDX = 1228,
     DOUBLE_COLON = 1238,
     SQLSICS = 1244,
     CREATE_SCHEMA = 1245,
     SQLSIRR = 1246,
     UPDATESTATS_T = 1247,
     SQLSICR = 1248,
     SQLSIDR = 1259,
     CREATE_TEMP_TABLE = 1260,
     WITH_CHECK_OPTION = 1268,
     WITH_GRANT_OPTION = 1269,
     SQLSLMNW = 1270,
     WHERE_CURRENT_OF = 1276,
     NOT_NULL_UNIQUE = 1284,
     SQLSLMW = 1291,
     ALL_PRIVILEGES = 1293,
     CREATE_SYNONYM = 1297,
     DROP_TABLE = 1298,
     INEXCLUSIVE = 1300,
     UPDATESTATS = 1305,
     CREATE_TABLE = 1331,
     DEFAULT_NULL = 1332,
     DEFAULT_TODAY = 1333,
     DEFAULT_USER = 1334,
     UNLOCK_TABLE = 1347,
     ROLLBACK_W = 1355,
     SQLSEON = 1357,
     SQLSEOFF = 1358,
     CREATE_VIEW = 1362,
     DELETE_FROM = 1363,
     EXTENT_SIZE = 1370,
     FOREIGN_KEY = 1371,
     INSERT_INTO = 1374,
     IS_NOT_NULL = 1376,
     NOT_MATCHES = 1379,
     PRIMARY_KEY = 1385,
     USE_SESSION = 1392,
     WITH_NO_LOG = 1393,
     INSHARE = 1396,
     BEGIN_WORK = 1402,
     DROP_INDEX = 1407,
     FOR_UPDATE_OF = 1413,
     FOR_UPDATE = 1414,
     LOCK_TABLE = 1419,
     NOT_EXISTS = 1421,
     REFERENCES = 1423,
     RENCOL = 1424,
     SMALLFLOAT = 1426,
     COMMIT_W = 1437,
     RENTAB = 1444,
     KW_CHAR = 1447,
     NCHAR = 1448,
     NVARCHAR = 1449,
     DELIMITER = 1451,
     DROP_VIEW = 1453,
     EXCLUSIVE = 1456,
     GREATER_THAN_EQ = 1460,
     INTO_TEMP = 1462,
     DATABASE = 1486,
     DATETIME = 1487,
     DISTINCT = 1489,
     FRACTION = 1496,
     GROUP_BY = 1498,
     INTERVAL = 1499,
     NOT_LIKE = 1501,
     NOT_ILIKE = 1502,
     NOT_NULL = 1503,
     RESOURCE = 1509,
     SMALLINT = 1510,
     IS_NULL = 1516,
     LESS_THAN_EQ = 1517,
     BETWEEN = 1519,
     CLOSE_BRACKET = 1522,
     CONNECT = 1525,
     KW_CURRENT = 1526,
     KW_DECIMAL = 1528,
     DEFAULT = 1530,
     INTEGER = 1538,
     SERIAL8 = 1540,
     MATCHES = 1543,
     VARCHAR = 1556,
     CLOSE_SQUARE = 1559,
     GREATER_THAN = 1560,
     KW_FALSE = 1561,
     NOT_IN = 1562,
     OPEN_BRACKET = 1564,
     KW_DELETE = 1572,
     KW_ESCAPE = 1575,
     EXISTS = 1576,
     EXTEND = 1577,
     HAVING = 1581,
     KW_INSERT = 1583,
     MINUTE = 1587,
     MODIFY = 1588,
     EQUAL = 1590,
     NOT_EQUAL = 1591,
     OPEN_SQUARE = 1593,
     PUBLIC = 1597,
     REVOKE = 1601,
     SECOND = 1605,
     KW_SELECT = 1609,
     SERIAL = 1610,
     UNIQUE = 1613,
     KW_UPDATE = 1615,
     VALUES = 1616,
     KW_NULL = 1619,
     KW_TRUE = 1620,
     ALTER = 1622,
     CHECK = 1628,
     COUNT = 1632,
     KW_FIRST = 1637,
     KW_FLOAT = 1638,
     GRANT = 1641,
     INDEX = 1644,
     LESS_THAN = 1647,
     MONEY = 1649,
     MONTH = 1650,
     KW_MULTIPLY = 1652,
     ORDER = 1653,
     OUTER = 1654,
     UNION = 1663,
     WHERE = 1666,
     KW_BYTE = 1673,
     CASE = 1675,
     KW_DATE = 1677,
     DESC = 1678,
     KW_DIVIDE = 1679,
     DROP = 1682,
     ELSE = 1683,
     FROM = 1687,
     HOUR = 1693,
     INTO = 1694,
     LIKE = 1697,
     REAL = 1706,
     SOME = 1711,
     KW_TEXT = 1715,
     KW_THEN = 1716,
     USER = 1717,
     WHEN = 1719,
     YEAR = 1722,
     KW_DOW = 1723,
     XSET = 1725,
     ADD = 1726,
     ALL = 1727,
     KW_AND = 1728,
     ANY = 1729,
     ASC = 1730,
     AVG = 1731,
     COLON = 1732,
     KW_COMMA = 1733,
     DAY = 1734,
     DBA = 1735,
     KW_FOR = 1739,
     XMAX = 1744,
     XMIN = 1745,
     KW_MINUS = 1746,
     KW_MOD = 1747,
     KW_NOT = 1748,
     KW_SUM = 1755,
     ATSIGN = 1758,
     KW_PLUS = 1759,
     KW_AS = 1765,
     KW_BY = 1767,
     KW_DOT = 1768,
     KW_IN = 1771,
     KW_ON = 1773,
     KW_OR = 1774,
     KW_TO = 1775,
     BEFORE = 1813,
     END = 1817,
     TILDE = 1824,
     ILIKE = 1825,
     FILLFACTOR = 1828,
     TIME = 1833,
     KW_TODAY = 1840,
     KW_ROWID = 1841,
     TIMESTAMP = 2189,
     KW_TAG = 2210,
     LINTMODULEISLIBRARY = 2211,
     KW_PUBLIC = 2212,
     KW_PRIVATE = 2213
   };
#endif
/* Tokens.  */
#define INT_VALUE 2215
#define NAMED 2216
#define NAMED_GEN 2217
#define CHAR_VALUE 2218
#define NOT_USED_1 2219
#define NOT_USED_2 2220
#define NOT_USED_3 2221
#define NOT_USED_4 2222
#define NOT_USED_5 2223
#define NOT_USED_6 2224
#define NOT_USED_7 2225
#define NOT_USED_8 2226
#define NUMBER_VALUE 2227
#define SEMICOLON 2228
#define QUESTION_MARK 2229
#define CLINE 2230
#define CH 2231
#define MARK_VAR 2232
#define END_MARK_VAR 2233
#define KW_RUN_CLIENT 1001
#define LEFT_JOIN 1003
#define DISPLAY_NULL_TO 1006
#define UNBUFFERED 1007
#define KW_PICTURE 1008
#define ON_CHANGE 1009
#define INNER_JOIN 1010
#define UI_INTERFACE_DOT_FRONTCALL 1013
#define UICOMBOBOX 1017
#define UIFORM 1020
#define USING_BTREE 1036
#define USING_RTREE 1037
#define SET_BUFFERED_LOG 1062
#define SET_LOG 1065
#define MDY 1067
#define WEEKDAY 1068
#define MODE_ANSI 1071
#define START_DATABASE 1072
#define WITH_LOG_IN 1073
#define SET_CONSTRAINTS_ALL_IMMEDIATE 1074
#define DATETIME_VALUE 1087
#define INTERVAL_VALUE 1088
#define RECOVER_TABLE 1089
#define ROLLFORWARD_DATABASE 1090
#define DROP_TRIGGER 1106
#define DROP_AUDIT_FOR 1107
#define CREATE_AUDIT_FOR 1108
#define EXECUTE_PROCEDURE 1112
#define ALTER_TABLE 1119
#define ALTER_INDEX 1120
#define NEXT_SIZE 1121
#define XSET_MULTIPLY_EQUAL_OPEN_BRACKET 1158
#define XSET_ident_DOT_MULTIPLY_EQUAL_OPEN_BRACKET 1159
#define XSET_ident_DOT_MULTIPLY_EQUAL 1160
#define XSET_MULTIPLY_EQUAL 1161
#define XSET_OPEN_BRACKET 1162
#define CREATE_DATABASE 1165
#define DROP_DATABASE 1166
#define ADD_CONSTRAINT 1168
#define DROP_CONSTRAINT 1169
#define DROP_SYNONYM 1170
#define CONSTRAINT 1171
#define NOT_FIELD_TOUCHED_CURRENT 1174
#define FIELD_TOUCHED_CURRENT 1175
#define DOUBLE_PRECISION 1182
#define COUNT_MULTIPLY 1183
#define MODIFY_NEXT_SIZE 1203
#define LOCK_MODE_PAGE 1204
#define LOCK_MODE_ROW 1205
#define UNITS_YEAR 1212
#define UNITS_MONTH 1213
#define UNITS_DAY 1214
#define UNITS_HOUR 1215
#define UNITS_MINUTE 1216
#define UNITS_SECOND 1217
#define TO_CLUSTER 1222
#define TO_NOT_CLUSTER 1223
#define CREATE_UC_IDX 1225
#define CREATE_U_IDX 1226
#define CREATE_C_IDX 1227
#define CREATE_IDX 1228
#define DOUBLE_COLON 1238
#define SQLSICS 1244
#define CREATE_SCHEMA 1245
#define SQLSIRR 1246
#define UPDATESTATS_T 1247
#define SQLSICR 1248
#define SQLSIDR 1259
#define CREATE_TEMP_TABLE 1260
#define WITH_CHECK_OPTION 1268
#define WITH_GRANT_OPTION 1269
#define SQLSLMNW 1270
#define WHERE_CURRENT_OF 1276
#define NOT_NULL_UNIQUE 1284
#define SQLSLMW 1291
#define ALL_PRIVILEGES 1293
#define CREATE_SYNONYM 1297
#define DROP_TABLE 1298
#define INEXCLUSIVE 1300
#define UPDATESTATS 1305
#define CREATE_TABLE 1331
#define DEFAULT_NULL 1332
#define DEFAULT_TODAY 1333
#define DEFAULT_USER 1334
#define UNLOCK_TABLE 1347
#define ROLLBACK_W 1355
#define SQLSEON 1357
#define SQLSEOFF 1358
#define CREATE_VIEW 1362
#define DELETE_FROM 1363
#define EXTENT_SIZE 1370
#define FOREIGN_KEY 1371
#define INSERT_INTO 1374
#define IS_NOT_NULL 1376
#define NOT_MATCHES 1379
#define PRIMARY_KEY 1385
#define USE_SESSION 1392
#define WITH_NO_LOG 1393
#define INSHARE 1396
#define BEGIN_WORK 1402
#define DROP_INDEX 1407
#define FOR_UPDATE_OF 1413
#define FOR_UPDATE 1414
#define LOCK_TABLE 1419
#define NOT_EXISTS 1421
#define REFERENCES 1423
#define RENCOL 1424
#define SMALLFLOAT 1426
#define COMMIT_W 1437
#define RENTAB 1444
#define KW_CHAR 1447
#define NCHAR 1448
#define NVARCHAR 1449
#define DELIMITER 1451
#define DROP_VIEW 1453
#define EXCLUSIVE 1456
#define GREATER_THAN_EQ 1460
#define INTO_TEMP 1462
#define DATABASE 1486
#define DATETIME 1487
#define DISTINCT 1489
#define FRACTION 1496
#define GROUP_BY 1498
#define INTERVAL 1499
#define NOT_LIKE 1501
#define NOT_ILIKE 1502
#define NOT_NULL 1503
#define RESOURCE 1509
#define SMALLINT 1510
#define IS_NULL 1516
#define LESS_THAN_EQ 1517
#define BETWEEN 1519
#define CLOSE_BRACKET 1522
#define CONNECT 1525
#define KW_CURRENT 1526
#define KW_DECIMAL 1528
#define DEFAULT 1530
#define INTEGER 1538
#define SERIAL8 1540
#define MATCHES 1543
#define VARCHAR 1556
#define CLOSE_SQUARE 1559
#define GREATER_THAN 1560
#define KW_FALSE 1561
#define NOT_IN 1562
#define OPEN_BRACKET 1564
#define KW_DELETE 1572
#define KW_ESCAPE 1575
#define EXISTS 1576
#define EXTEND 1577
#define HAVING 1581
#define KW_INSERT 1583
#define MINUTE 1587
#define MODIFY 1588
#define EQUAL 1590
#define NOT_EQUAL 1591
#define OPEN_SQUARE 1593
#define PUBLIC 1597
#define REVOKE 1601
#define SECOND 1605
#define KW_SELECT 1609
#define SERIAL 1610
#define UNIQUE 1613
#define KW_UPDATE 1615
#define VALUES 1616
#define KW_NULL 1619
#define KW_TRUE 1620
#define ALTER 1622
#define CHECK 1628
#define COUNT 1632
#define KW_FIRST 1637
#define KW_FLOAT 1638
#define GRANT 1641
#define INDEX 1644
#define LESS_THAN 1647
#define MONEY 1649
#define MONTH 1650
#define KW_MULTIPLY 1652
#define ORDER 1653
#define OUTER 1654
#define UNION 1663
#define WHERE 1666
#define KW_BYTE 1673
#define CASE 1675
#define KW_DATE 1677
#define DESC 1678
#define KW_DIVIDE 1679
#define DROP 1682
#define ELSE 1683
#define FROM 1687
#define HOUR 1693
#define INTO 1694
#define LIKE 1697
#define REAL 1706
#define SOME 1711
#define KW_TEXT 1715
#define KW_THEN 1716
#define USER 1717
#define WHEN 1719
#define YEAR 1722
#define KW_DOW 1723
#define XSET 1725
#define ADD 1726
#define ALL 1727
#define KW_AND 1728
#define ANY 1729
#define ASC 1730
#define AVG 1731
#define COLON 1732
#define KW_COMMA 1733
#define DAY 1734
#define DBA 1735
#define KW_FOR 1739
#define XMAX 1744
#define XMIN 1745
#define KW_MINUS 1746
#define KW_MOD 1747
#define KW_NOT 1748
#define KW_SUM 1755
#define ATSIGN 1758
#define KW_PLUS 1759
#define KW_AS 1765
#define KW_BY 1767
#define KW_DOT 1768
#define KW_IN 1771
#define KW_ON 1773
#define KW_OR 1774
#define KW_TO 1775
#define BEFORE 1813
#define END 1817
#define TILDE 1824
#define ILIKE 1825
#define FILLFACTOR 1828
#define TIME 1833
#define KW_TODAY 1840
#define KW_ROWID 1841
#define TIMESTAMP 2189
#define KW_TAG 2210
#define LINTMODULEISLIBRARY 2211
#define KW_PUBLIC 2212
#define KW_PRIVATE 2213




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
#line 601 "y.tab.h"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE sqlparse_yylval;


