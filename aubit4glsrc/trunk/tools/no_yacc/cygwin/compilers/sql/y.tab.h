
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
     INT_VALUE = 2216,
     NAMED = 2217,
     NAMED_GEN = 2218,
     CHAR_VALUE = 2219,
     NOT_USED_1 = 2220,
     NOT_USED_2 = 2221,
     NOT_USED_3 = 2222,
     NOT_USED_4 = 2223,
     NOT_USED_5 = 2224,
     NOT_USED_6 = 2225,
     NOT_USED_7 = 2226,
     NOT_USED_8 = 2227,
     NUMBER_VALUE = 2228,
     SEMICOLON = 2229,
     QUESTION_MARK = 2230,
     CLINE = 2231,
     CH = 2232,
     MARK_VAR = 2233,
     END_MARK_VAR = 2234,
     KW_RUN_CLIENT = 1001,
     LEFT_JOIN = 1003,
     SQLERRMESSAGE = 1006,
     DISPLAY_NULL_TO = 1007,
     UNBUFFERED = 1008,
     KW_PICTURE = 1009,
     ON_CHANGE = 1010,
     INNER_JOIN = 1011,
     UI_INTERFACE_DOT_FRONTCALL = 1014,
     UICOMBOBOX = 1018,
     UIFORM = 1021,
     USING_BTREE = 1037,
     USING_RTREE = 1038,
     SET_BUFFERED_LOG = 1063,
     SET_LOG = 1066,
     MDY = 1068,
     WEEKDAY = 1069,
     MODE_ANSI = 1072,
     START_DATABASE = 1073,
     WITH_LOG_IN = 1074,
     SET_CONSTRAINTS_ALL_IMMEDIATE = 1075,
     DATETIME_VALUE = 1088,
     INTERVAL_VALUE = 1089,
     RECOVER_TABLE = 1090,
     ROLLFORWARD_DATABASE = 1091,
     DROP_TRIGGER = 1107,
     DROP_AUDIT_FOR = 1108,
     CREATE_AUDIT_FOR = 1109,
     EXECUTE_PROCEDURE = 1113,
     ALTER_TABLE = 1120,
     ALTER_INDEX = 1121,
     NEXT_SIZE = 1122,
     XSET_MULTIPLY_EQUAL_OPEN_BRACKET = 1159,
     XSET_ident_DOT_MULTIPLY_EQUAL_OPEN_BRACKET = 1160,
     XSET_ident_DOT_MULTIPLY_EQUAL = 1161,
     XSET_MULTIPLY_EQUAL = 1162,
     XSET_OPEN_BRACKET = 1163,
     CREATE_DATABASE = 1166,
     DROP_DATABASE = 1167,
     ADD_CONSTRAINT = 1169,
     DROP_CONSTRAINT = 1170,
     DROP_SYNONYM = 1171,
     CONSTRAINT = 1172,
     NOT_FIELD_TOUCHED_CURRENT = 1175,
     FIELD_TOUCHED_CURRENT = 1176,
     DOUBLE_PRECISION = 1183,
     COUNT_MULTIPLY = 1184,
     MODIFY_NEXT_SIZE = 1204,
     LOCK_MODE_PAGE = 1205,
     LOCK_MODE_ROW = 1206,
     UNITS_YEAR = 1213,
     UNITS_MONTH = 1214,
     UNITS_DAY = 1215,
     UNITS_HOUR = 1216,
     UNITS_MINUTE = 1217,
     UNITS_SECOND = 1218,
     TO_CLUSTER = 1223,
     TO_NOT_CLUSTER = 1224,
     CREATE_UC_IDX = 1226,
     CREATE_U_IDX = 1227,
     CREATE_C_IDX = 1228,
     CREATE_IDX = 1229,
     DOUBLE_COLON = 1239,
     SQLSICS = 1245,
     CREATE_SCHEMA = 1246,
     SQLSIRR = 1247,
     UPDATESTATS_T = 1248,
     SQLSICR = 1249,
     SQLSIDR = 1260,
     CREATE_TEMP_TABLE = 1261,
     WITH_CHECK_OPTION = 1269,
     WITH_GRANT_OPTION = 1270,
     SQLSLMNW = 1271,
     WHERE_CURRENT_OF = 1277,
     NOT_NULL_UNIQUE = 1285,
     SQLSLMW = 1292,
     ALL_PRIVILEGES = 1294,
     CREATE_SYNONYM = 1298,
     DROP_TABLE = 1299,
     INEXCLUSIVE = 1301,
     UPDATESTATS = 1306,
     CREATE_TABLE = 1332,
     DEFAULT_NULL = 1333,
     DEFAULT_TODAY = 1334,
     DEFAULT_USER = 1335,
     UNLOCK_TABLE = 1348,
     ROLLBACK_W = 1356,
     SQLSEON = 1358,
     SQLSEOFF = 1359,
     CREATE_VIEW = 1363,
     DELETE_FROM = 1364,
     EXTENT_SIZE = 1371,
     FOREIGN_KEY = 1372,
     INSERT_INTO = 1375,
     IS_NOT_NULL = 1377,
     NOT_MATCHES = 1380,
     PRIMARY_KEY = 1386,
     USE_SESSION = 1393,
     WITH_NO_LOG = 1394,
     INSHARE = 1397,
     BEGIN_WORK = 1403,
     DROP_INDEX = 1408,
     FOR_UPDATE_OF = 1414,
     FOR_UPDATE = 1415,
     LOCK_TABLE = 1420,
     NOT_EXISTS = 1422,
     REFERENCES = 1424,
     RENCOL = 1425,
     SMALLFLOAT = 1427,
     COMMIT_W = 1438,
     RENTAB = 1445,
     KW_CHAR = 1448,
     NCHAR = 1449,
     NVARCHAR = 1450,
     DELIMITER = 1452,
     DROP_VIEW = 1454,
     EXCLUSIVE = 1457,
     GREATER_THAN_EQ = 1461,
     INTO_TEMP = 1463,
     DATABASE = 1487,
     DATETIME = 1488,
     DISTINCT = 1490,
     FRACTION = 1497,
     GROUP_BY = 1499,
     INTERVAL = 1500,
     NOT_LIKE = 1502,
     NOT_ILIKE = 1503,
     NOT_NULL = 1504,
     RESOURCE = 1510,
     SMALLINT = 1511,
     IS_NULL = 1517,
     LESS_THAN_EQ = 1518,
     BETWEEN = 1520,
     CLOSE_BRACKET = 1523,
     CONNECT = 1526,
     KW_CURRENT = 1527,
     KW_DECIMAL = 1529,
     DEFAULT = 1531,
     INTEGER = 1539,
     SERIAL8 = 1541,
     MATCHES = 1544,
     VARCHAR = 1557,
     CLOSE_SQUARE = 1560,
     GREATER_THAN = 1561,
     KW_FALSE = 1562,
     NOT_IN = 1563,
     OPEN_BRACKET = 1565,
     KW_DELETE = 1573,
     KW_ESCAPE = 1576,
     EXISTS = 1577,
     EXTEND = 1578,
     HAVING = 1582,
     KW_INSERT = 1584,
     MINUTE = 1588,
     MODIFY = 1589,
     EQUAL = 1591,
     NOT_EQUAL = 1592,
     OPEN_SQUARE = 1594,
     PUBLIC = 1598,
     REVOKE = 1602,
     SECOND = 1606,
     KW_SELECT = 1610,
     SERIAL = 1611,
     UNIQUE = 1614,
     KW_UPDATE = 1616,
     VALUES = 1617,
     KW_NULL = 1620,
     KW_TRUE = 1621,
     ALTER = 1623,
     CHECK = 1629,
     COUNT = 1633,
     KW_FIRST = 1638,
     KW_FLOAT = 1639,
     GRANT = 1642,
     INDEX = 1645,
     LESS_THAN = 1648,
     MONEY = 1650,
     MONTH = 1651,
     KW_MULTIPLY = 1653,
     ORDER = 1654,
     OUTER = 1655,
     UNION = 1664,
     WHERE = 1667,
     KW_BYTE = 1674,
     CASE = 1676,
     KW_DATE = 1678,
     DESC = 1679,
     KW_DIVIDE = 1680,
     DROP = 1683,
     ELSE = 1684,
     FROM = 1688,
     HOUR = 1694,
     INTO = 1695,
     LIKE = 1698,
     REAL = 1707,
     SOME = 1712,
     KW_TEXT = 1716,
     KW_THEN = 1717,
     USER = 1718,
     WHEN = 1720,
     YEAR = 1723,
     KW_DOW = 1724,
     XSET = 1726,
     ADD = 1727,
     ALL = 1728,
     KW_AND = 1729,
     ANY = 1730,
     ASC = 1731,
     AVG = 1732,
     COLON = 1733,
     KW_COMMA = 1734,
     DAY = 1735,
     DBA = 1736,
     KW_FOR = 1740,
     XMAX = 1745,
     XMIN = 1746,
     KW_MINUS = 1747,
     KW_MOD = 1748,
     KW_NOT = 1749,
     KW_SUM = 1756,
     ATSIGN = 1759,
     KW_PLUS = 1760,
     KW_AS = 1766,
     KW_BY = 1768,
     KW_DOT = 1769,
     KW_IN = 1772,
     KW_ON = 1774,
     KW_OR = 1775,
     KW_TO = 1776,
     BEFORE = 1814,
     END = 1818,
     TILDE = 1825,
     ILIKE = 1826,
     FILLFACTOR = 1829,
     TIME = 1834,
     KW_TODAY = 1841,
     KW_ROWID = 1842,
     TIMESTAMP = 2190,
     KW_TAG = 2211,
     LINTMODULEISLIBRARY = 2212,
     KW_PUBLIC = 2213,
     KW_PRIVATE = 2214
   };
#endif
/* Tokens.  */
#define INT_VALUE 2216
#define NAMED 2217
#define NAMED_GEN 2218
#define CHAR_VALUE 2219
#define NOT_USED_1 2220
#define NOT_USED_2 2221
#define NOT_USED_3 2222
#define NOT_USED_4 2223
#define NOT_USED_5 2224
#define NOT_USED_6 2225
#define NOT_USED_7 2226
#define NOT_USED_8 2227
#define NUMBER_VALUE 2228
#define SEMICOLON 2229
#define QUESTION_MARK 2230
#define CLINE 2231
#define CH 2232
#define MARK_VAR 2233
#define END_MARK_VAR 2234
#define KW_RUN_CLIENT 1001
#define LEFT_JOIN 1003
#define SQLERRMESSAGE 1006
#define DISPLAY_NULL_TO 1007
#define UNBUFFERED 1008
#define KW_PICTURE 1009
#define ON_CHANGE 1010
#define INNER_JOIN 1011
#define UI_INTERFACE_DOT_FRONTCALL 1014
#define UICOMBOBOX 1018
#define UIFORM 1021
#define USING_BTREE 1037
#define USING_RTREE 1038
#define SET_BUFFERED_LOG 1063
#define SET_LOG 1066
#define MDY 1068
#define WEEKDAY 1069
#define MODE_ANSI 1072
#define START_DATABASE 1073
#define WITH_LOG_IN 1074
#define SET_CONSTRAINTS_ALL_IMMEDIATE 1075
#define DATETIME_VALUE 1088
#define INTERVAL_VALUE 1089
#define RECOVER_TABLE 1090
#define ROLLFORWARD_DATABASE 1091
#define DROP_TRIGGER 1107
#define DROP_AUDIT_FOR 1108
#define CREATE_AUDIT_FOR 1109
#define EXECUTE_PROCEDURE 1113
#define ALTER_TABLE 1120
#define ALTER_INDEX 1121
#define NEXT_SIZE 1122
#define XSET_MULTIPLY_EQUAL_OPEN_BRACKET 1159
#define XSET_ident_DOT_MULTIPLY_EQUAL_OPEN_BRACKET 1160
#define XSET_ident_DOT_MULTIPLY_EQUAL 1161
#define XSET_MULTIPLY_EQUAL 1162
#define XSET_OPEN_BRACKET 1163
#define CREATE_DATABASE 1166
#define DROP_DATABASE 1167
#define ADD_CONSTRAINT 1169
#define DROP_CONSTRAINT 1170
#define DROP_SYNONYM 1171
#define CONSTRAINT 1172
#define NOT_FIELD_TOUCHED_CURRENT 1175
#define FIELD_TOUCHED_CURRENT 1176
#define DOUBLE_PRECISION 1183
#define COUNT_MULTIPLY 1184
#define MODIFY_NEXT_SIZE 1204
#define LOCK_MODE_PAGE 1205
#define LOCK_MODE_ROW 1206
#define UNITS_YEAR 1213
#define UNITS_MONTH 1214
#define UNITS_DAY 1215
#define UNITS_HOUR 1216
#define UNITS_MINUTE 1217
#define UNITS_SECOND 1218
#define TO_CLUSTER 1223
#define TO_NOT_CLUSTER 1224
#define CREATE_UC_IDX 1226
#define CREATE_U_IDX 1227
#define CREATE_C_IDX 1228
#define CREATE_IDX 1229
#define DOUBLE_COLON 1239
#define SQLSICS 1245
#define CREATE_SCHEMA 1246
#define SQLSIRR 1247
#define UPDATESTATS_T 1248
#define SQLSICR 1249
#define SQLSIDR 1260
#define CREATE_TEMP_TABLE 1261
#define WITH_CHECK_OPTION 1269
#define WITH_GRANT_OPTION 1270
#define SQLSLMNW 1271
#define WHERE_CURRENT_OF 1277
#define NOT_NULL_UNIQUE 1285
#define SQLSLMW 1292
#define ALL_PRIVILEGES 1294
#define CREATE_SYNONYM 1298
#define DROP_TABLE 1299
#define INEXCLUSIVE 1301
#define UPDATESTATS 1306
#define CREATE_TABLE 1332
#define DEFAULT_NULL 1333
#define DEFAULT_TODAY 1334
#define DEFAULT_USER 1335
#define UNLOCK_TABLE 1348
#define ROLLBACK_W 1356
#define SQLSEON 1358
#define SQLSEOFF 1359
#define CREATE_VIEW 1363
#define DELETE_FROM 1364
#define EXTENT_SIZE 1371
#define FOREIGN_KEY 1372
#define INSERT_INTO 1375
#define IS_NOT_NULL 1377
#define NOT_MATCHES 1380
#define PRIMARY_KEY 1386
#define USE_SESSION 1393
#define WITH_NO_LOG 1394
#define INSHARE 1397
#define BEGIN_WORK 1403
#define DROP_INDEX 1408
#define FOR_UPDATE_OF 1414
#define FOR_UPDATE 1415
#define LOCK_TABLE 1420
#define NOT_EXISTS 1422
#define REFERENCES 1424
#define RENCOL 1425
#define SMALLFLOAT 1427
#define COMMIT_W 1438
#define RENTAB 1445
#define KW_CHAR 1448
#define NCHAR 1449
#define NVARCHAR 1450
#define DELIMITER 1452
#define DROP_VIEW 1454
#define EXCLUSIVE 1457
#define GREATER_THAN_EQ 1461
#define INTO_TEMP 1463
#define DATABASE 1487
#define DATETIME 1488
#define DISTINCT 1490
#define FRACTION 1497
#define GROUP_BY 1499
#define INTERVAL 1500
#define NOT_LIKE 1502
#define NOT_ILIKE 1503
#define NOT_NULL 1504
#define RESOURCE 1510
#define SMALLINT 1511
#define IS_NULL 1517
#define LESS_THAN_EQ 1518
#define BETWEEN 1520
#define CLOSE_BRACKET 1523
#define CONNECT 1526
#define KW_CURRENT 1527
#define KW_DECIMAL 1529
#define DEFAULT 1531
#define INTEGER 1539
#define SERIAL8 1541
#define MATCHES 1544
#define VARCHAR 1557
#define CLOSE_SQUARE 1560
#define GREATER_THAN 1561
#define KW_FALSE 1562
#define NOT_IN 1563
#define OPEN_BRACKET 1565
#define KW_DELETE 1573
#define KW_ESCAPE 1576
#define EXISTS 1577
#define EXTEND 1578
#define HAVING 1582
#define KW_INSERT 1584
#define MINUTE 1588
#define MODIFY 1589
#define EQUAL 1591
#define NOT_EQUAL 1592
#define OPEN_SQUARE 1594
#define PUBLIC 1598
#define REVOKE 1602
#define SECOND 1606
#define KW_SELECT 1610
#define SERIAL 1611
#define UNIQUE 1614
#define KW_UPDATE 1616
#define VALUES 1617
#define KW_NULL 1620
#define KW_TRUE 1621
#define ALTER 1623
#define CHECK 1629
#define COUNT 1633
#define KW_FIRST 1638
#define KW_FLOAT 1639
#define GRANT 1642
#define INDEX 1645
#define LESS_THAN 1648
#define MONEY 1650
#define MONTH 1651
#define KW_MULTIPLY 1653
#define ORDER 1654
#define OUTER 1655
#define UNION 1664
#define WHERE 1667
#define KW_BYTE 1674
#define CASE 1676
#define KW_DATE 1678
#define DESC 1679
#define KW_DIVIDE 1680
#define DROP 1683
#define ELSE 1684
#define FROM 1688
#define HOUR 1694
#define INTO 1695
#define LIKE 1698
#define REAL 1707
#define SOME 1712
#define KW_TEXT 1716
#define KW_THEN 1717
#define USER 1718
#define WHEN 1720
#define YEAR 1723
#define KW_DOW 1724
#define XSET 1726
#define ADD 1727
#define ALL 1728
#define KW_AND 1729
#define ANY 1730
#define ASC 1731
#define AVG 1732
#define COLON 1733
#define KW_COMMA 1734
#define DAY 1735
#define DBA 1736
#define KW_FOR 1740
#define XMAX 1745
#define XMIN 1746
#define KW_MINUS 1747
#define KW_MOD 1748
#define KW_NOT 1749
#define KW_SUM 1756
#define ATSIGN 1759
#define KW_PLUS 1760
#define KW_AS 1766
#define KW_BY 1768
#define KW_DOT 1769
#define KW_IN 1772
#define KW_ON 1774
#define KW_OR 1775
#define KW_TO 1776
#define BEFORE 1814
#define END 1818
#define TILDE 1825
#define ILIKE 1826
#define FILLFACTOR 1829
#define TIME 1834
#define KW_TODAY 1841
#define KW_ROWID 1842
#define TIMESTAMP 2190
#define KW_TAG 2211
#define LINTMODULEISLIBRARY 2212
#define KW_PUBLIC 2213
#define KW_PRIVATE 2214




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
#line 603 "y.tab.h"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE sqlparse_yylval;


