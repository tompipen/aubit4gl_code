
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
     INT_VALUE = 2210,
     NAMED = 2211,
     NAMED_GEN = 2212,
     CHAR_VALUE = 2213,
     NOT_USED_1 = 2214,
     NOT_USED_2 = 2215,
     NOT_USED_3 = 2216,
     NOT_USED_4 = 2217,
     NOT_USED_5 = 2218,
     NOT_USED_6 = 2219,
     NOT_USED_7 = 2220,
     NOT_USED_8 = 2221,
     NUMBER_VALUE = 2222,
     SEMICOLON = 2223,
     QUESTION_MARK = 2224,
     CLINE = 2225,
     CH = 2226,
     MARK_VAR = 2227,
     END_MARK_VAR = 2228,
     LEFT_JOIN = 1002,
     DISPLAY_NULL_TO = 1005,
     ON_CHANGE = 1006,
     INNER_JOIN = 1007,
     UI_INTERFACE_DOT_FRONTCALL = 1010,
     UICOMBOBOX = 1014,
     UIFORM = 1015,
     USING_BTREE = 1033,
     USING_RTREE = 1034,
     SET_BUFFERED_LOG = 1059,
     SET_LOG = 1062,
     MDY = 1064,
     WEEKDAY = 1065,
     MODE_ANSI = 1068,
     START_DATABASE = 1069,
     WITH_LOG_IN = 1070,
     SET_CONSTRAINTS_ALL_IMMEDIATE = 1071,
     DATETIME_VALUE = 1084,
     INTERVAL_VALUE = 1085,
     RECOVER_TABLE = 1086,
     ROLLFORWARD_DATABASE = 1087,
     DROP_TRIGGER = 1103,
     DROP_AUDIT_FOR = 1104,
     CREATE_AUDIT_FOR = 1105,
     EXECUTE_PROCEDURE = 1109,
     ALTER_TABLE = 1116,
     ALTER_INDEX = 1117,
     NEXT_SIZE = 1118,
     XSET_MULTIPLY_EQUAL_OPEN_BRACKET = 1155,
     XSET_ident_DOT_MULTIPLY_EQUAL_OPEN_BRACKET = 1156,
     XSET_ident_DOT_MULTIPLY_EQUAL = 1157,
     XSET_MULTIPLY_EQUAL = 1158,
     XSET_OPEN_BRACKET = 1159,
     CREATE_DATABASE = 1162,
     DROP_DATABASE = 1163,
     ADD_CONSTRAINT = 1165,
     DROP_CONSTRAINT = 1166,
     DROP_SYNONYM = 1167,
     CONSTRAINT = 1168,
     NOT_FIELD_TOUCHED_CURRENT = 1171,
     FIELD_TOUCHED_CURRENT = 1172,
     DOUBLE_PRECISION = 1179,
     COUNT_MULTIPLY = 1180,
     MODIFY_NEXT_SIZE = 1200,
     LOCK_MODE_PAGE = 1201,
     LOCK_MODE_ROW = 1202,
     UNITS_YEAR = 1209,
     UNITS_MONTH = 1210,
     UNITS_DAY = 1211,
     UNITS_HOUR = 1212,
     UNITS_MINUTE = 1213,
     UNITS_SECOND = 1214,
     TO_CLUSTER = 1219,
     TO_NOT_CLUSTER = 1220,
     CREATE_UC_IDX = 1222,
     CREATE_U_IDX = 1223,
     CREATE_C_IDX = 1224,
     CREATE_IDX = 1225,
     DOUBLE_COLON = 1235,
     SQLSICS = 1241,
     CREATE_SCHEMA = 1242,
     SQLSIRR = 1243,
     UPDATESTATS_T = 1244,
     SQLSICR = 1245,
     SQLSIDR = 1256,
     CREATE_TEMP_TABLE = 1257,
     WITH_CHECK_OPTION = 1265,
     WITH_GRANT_OPTION = 1266,
     SQLSLMNW = 1267,
     WHERE_CURRENT_OF = 1273,
     NOT_NULL_UNIQUE = 1281,
     SQLSLMW = 1288,
     ALL_PRIVILEGES = 1290,
     CREATE_SYNONYM = 1294,
     DROP_TABLE = 1295,
     INEXCLUSIVE = 1297,
     UPDATESTATS = 1302,
     CREATE_TABLE = 1328,
     DEFAULT_NULL = 1329,
     DEFAULT_TODAY = 1330,
     DEFAULT_USER = 1331,
     UNLOCK_TABLE = 1344,
     ROLLBACK_W = 1352,
     SQLSEON = 1354,
     SQLSEOFF = 1355,
     CREATE_VIEW = 1359,
     DELETE_FROM = 1360,
     EXTENT_SIZE = 1367,
     FOREIGN_KEY = 1368,
     INSERT_INTO = 1371,
     IS_NOT_NULL = 1373,
     NOT_MATCHES = 1376,
     PRIMARY_KEY = 1382,
     USE_SESSION = 1389,
     WITH_NO_LOG = 1390,
     INSHARE = 1393,
     BEGIN_WORK = 1399,
     DROP_INDEX = 1404,
     FOR_UPDATE_OF = 1410,
     FOR_UPDATE = 1411,
     LOCK_TABLE = 1416,
     NOT_EXISTS = 1418,
     REFERENCES = 1420,
     RENCOL = 1421,
     SMALLFLOAT = 1423,
     COMMIT_W = 1434,
     RENTAB = 1441,
     KW_CHAR = 1444,
     NCHAR = 1445,
     NVARCHAR = 1446,
     DELIMITER = 1448,
     DROP_VIEW = 1450,
     EXCLUSIVE = 1453,
     GREATER_THAN_EQ = 1457,
     INTO_TEMP = 1459,
     DATABASE = 1483,
     DATETIME = 1484,
     DISTINCT = 1486,
     FRACTION = 1493,
     GROUP_BY = 1495,
     INTERVAL = 1496,
     NOT_LIKE = 1498,
     NOT_ILIKE = 1499,
     NOT_NULL = 1500,
     RESOURCE = 1506,
     SMALLINT = 1507,
     IS_NULL = 1513,
     LESS_THAN_EQ = 1514,
     BETWEEN = 1516,
     CLOSE_BRACKET = 1519,
     CONNECT = 1522,
     KW_CURRENT = 1523,
     KW_DECIMAL = 1525,
     DEFAULT = 1527,
     INTEGER = 1535,
     SERIAL8 = 1537,
     MATCHES = 1540,
     VARCHAR = 1553,
     CLOSE_SQUARE = 1556,
     GREATER_THAN = 1557,
     KW_FALSE = 1558,
     NOT_IN = 1559,
     OPEN_BRACKET = 1561,
     KW_DELETE = 1569,
     KW_ESCAPE = 1572,
     EXISTS = 1573,
     EXTEND = 1574,
     HAVING = 1578,
     KW_INSERT = 1580,
     MINUTE = 1584,
     MODIFY = 1585,
     EQUAL = 1587,
     NOT_EQUAL = 1588,
     OPEN_SQUARE = 1590,
     PUBLIC = 1594,
     REVOKE = 1598,
     SECOND = 1602,
     KW_SELECT = 1606,
     SERIAL = 1607,
     UNIQUE = 1610,
     KW_UPDATE = 1612,
     VALUES = 1613,
     KW_NULL = 1616,
     KW_TRUE = 1617,
     ALTER = 1619,
     CHECK = 1625,
     COUNT = 1629,
     KW_FIRST = 1634,
     KW_FLOAT = 1635,
     GRANT = 1638,
     INDEX = 1641,
     LESS_THAN = 1644,
     MONEY = 1646,
     MONTH = 1647,
     KW_MULTIPLY = 1649,
     ORDER = 1650,
     OUTER = 1651,
     UNION = 1660,
     WHERE = 1663,
     KW_BYTE = 1670,
     CASE = 1672,
     KW_DATE = 1674,
     DESC = 1675,
     KW_DIVIDE = 1676,
     DROP = 1679,
     ELSE = 1680,
     FROM = 1684,
     HOUR = 1690,
     INTO = 1691,
     LIKE = 1694,
     REAL = 1703,
     SOME = 1708,
     KW_TEXT = 1712,
     KW_THEN = 1713,
     USER = 1714,
     WHEN = 1716,
     YEAR = 1719,
     KW_DOW = 1720,
     XSET = 1722,
     ADD = 1723,
     ALL = 1724,
     KW_AND = 1725,
     ANY = 1726,
     ASC = 1727,
     AVG = 1728,
     COLON = 1729,
     KW_COMMA = 1730,
     DAY = 1731,
     DBA = 1732,
     KW_FOR = 1736,
     XMAX = 1741,
     XMIN = 1742,
     KW_MINUS = 1743,
     KW_MOD = 1744,
     KW_NOT = 1745,
     KW_SUM = 1752,
     ATSIGN = 1755,
     KW_PLUS = 1756,
     KW_AS = 1762,
     KW_BY = 1764,
     KW_DOT = 1765,
     KW_IN = 1768,
     KW_ON = 1770,
     KW_OR = 1771,
     KW_TO = 1772,
     BEFORE = 1810,
     END = 1814,
     TILDE = 1821,
     ILIKE = 1822,
     FILLFACTOR = 1825,
     TIME = 1830,
     KW_TODAY = 1837,
     KW_ROWID = 1838,
     TIMESTAMP = 2186,
     KW_TAG = 2207,
     LINTMODULEISLIBRARY = 2208
   };
#endif
/* Tokens.  */
#define INT_VALUE 2210
#define NAMED 2211
#define NAMED_GEN 2212
#define CHAR_VALUE 2213
#define NOT_USED_1 2214
#define NOT_USED_2 2215
#define NOT_USED_3 2216
#define NOT_USED_4 2217
#define NOT_USED_5 2218
#define NOT_USED_6 2219
#define NOT_USED_7 2220
#define NOT_USED_8 2221
#define NUMBER_VALUE 2222
#define SEMICOLON 2223
#define QUESTION_MARK 2224
#define CLINE 2225
#define CH 2226
#define MARK_VAR 2227
#define END_MARK_VAR 2228
#define LEFT_JOIN 1002
#define DISPLAY_NULL_TO 1005
#define ON_CHANGE 1006
#define INNER_JOIN 1007
#define UI_INTERFACE_DOT_FRONTCALL 1010
#define UICOMBOBOX 1014
#define UIFORM 1015
#define USING_BTREE 1033
#define USING_RTREE 1034
#define SET_BUFFERED_LOG 1059
#define SET_LOG 1062
#define MDY 1064
#define WEEKDAY 1065
#define MODE_ANSI 1068
#define START_DATABASE 1069
#define WITH_LOG_IN 1070
#define SET_CONSTRAINTS_ALL_IMMEDIATE 1071
#define DATETIME_VALUE 1084
#define INTERVAL_VALUE 1085
#define RECOVER_TABLE 1086
#define ROLLFORWARD_DATABASE 1087
#define DROP_TRIGGER 1103
#define DROP_AUDIT_FOR 1104
#define CREATE_AUDIT_FOR 1105
#define EXECUTE_PROCEDURE 1109
#define ALTER_TABLE 1116
#define ALTER_INDEX 1117
#define NEXT_SIZE 1118
#define XSET_MULTIPLY_EQUAL_OPEN_BRACKET 1155
#define XSET_ident_DOT_MULTIPLY_EQUAL_OPEN_BRACKET 1156
#define XSET_ident_DOT_MULTIPLY_EQUAL 1157
#define XSET_MULTIPLY_EQUAL 1158
#define XSET_OPEN_BRACKET 1159
#define CREATE_DATABASE 1162
#define DROP_DATABASE 1163
#define ADD_CONSTRAINT 1165
#define DROP_CONSTRAINT 1166
#define DROP_SYNONYM 1167
#define CONSTRAINT 1168
#define NOT_FIELD_TOUCHED_CURRENT 1171
#define FIELD_TOUCHED_CURRENT 1172
#define DOUBLE_PRECISION 1179
#define COUNT_MULTIPLY 1180
#define MODIFY_NEXT_SIZE 1200
#define LOCK_MODE_PAGE 1201
#define LOCK_MODE_ROW 1202
#define UNITS_YEAR 1209
#define UNITS_MONTH 1210
#define UNITS_DAY 1211
#define UNITS_HOUR 1212
#define UNITS_MINUTE 1213
#define UNITS_SECOND 1214
#define TO_CLUSTER 1219
#define TO_NOT_CLUSTER 1220
#define CREATE_UC_IDX 1222
#define CREATE_U_IDX 1223
#define CREATE_C_IDX 1224
#define CREATE_IDX 1225
#define DOUBLE_COLON 1235
#define SQLSICS 1241
#define CREATE_SCHEMA 1242
#define SQLSIRR 1243
#define UPDATESTATS_T 1244
#define SQLSICR 1245
#define SQLSIDR 1256
#define CREATE_TEMP_TABLE 1257
#define WITH_CHECK_OPTION 1265
#define WITH_GRANT_OPTION 1266
#define SQLSLMNW 1267
#define WHERE_CURRENT_OF 1273
#define NOT_NULL_UNIQUE 1281
#define SQLSLMW 1288
#define ALL_PRIVILEGES 1290
#define CREATE_SYNONYM 1294
#define DROP_TABLE 1295
#define INEXCLUSIVE 1297
#define UPDATESTATS 1302
#define CREATE_TABLE 1328
#define DEFAULT_NULL 1329
#define DEFAULT_TODAY 1330
#define DEFAULT_USER 1331
#define UNLOCK_TABLE 1344
#define ROLLBACK_W 1352
#define SQLSEON 1354
#define SQLSEOFF 1355
#define CREATE_VIEW 1359
#define DELETE_FROM 1360
#define EXTENT_SIZE 1367
#define FOREIGN_KEY 1368
#define INSERT_INTO 1371
#define IS_NOT_NULL 1373
#define NOT_MATCHES 1376
#define PRIMARY_KEY 1382
#define USE_SESSION 1389
#define WITH_NO_LOG 1390
#define INSHARE 1393
#define BEGIN_WORK 1399
#define DROP_INDEX 1404
#define FOR_UPDATE_OF 1410
#define FOR_UPDATE 1411
#define LOCK_TABLE 1416
#define NOT_EXISTS 1418
#define REFERENCES 1420
#define RENCOL 1421
#define SMALLFLOAT 1423
#define COMMIT_W 1434
#define RENTAB 1441
#define KW_CHAR 1444
#define NCHAR 1445
#define NVARCHAR 1446
#define DELIMITER 1448
#define DROP_VIEW 1450
#define EXCLUSIVE 1453
#define GREATER_THAN_EQ 1457
#define INTO_TEMP 1459
#define DATABASE 1483
#define DATETIME 1484
#define DISTINCT 1486
#define FRACTION 1493
#define GROUP_BY 1495
#define INTERVAL 1496
#define NOT_LIKE 1498
#define NOT_ILIKE 1499
#define NOT_NULL 1500
#define RESOURCE 1506
#define SMALLINT 1507
#define IS_NULL 1513
#define LESS_THAN_EQ 1514
#define BETWEEN 1516
#define CLOSE_BRACKET 1519
#define CONNECT 1522
#define KW_CURRENT 1523
#define KW_DECIMAL 1525
#define DEFAULT 1527
#define INTEGER 1535
#define SERIAL8 1537
#define MATCHES 1540
#define VARCHAR 1553
#define CLOSE_SQUARE 1556
#define GREATER_THAN 1557
#define KW_FALSE 1558
#define NOT_IN 1559
#define OPEN_BRACKET 1561
#define KW_DELETE 1569
#define KW_ESCAPE 1572
#define EXISTS 1573
#define EXTEND 1574
#define HAVING 1578
#define KW_INSERT 1580
#define MINUTE 1584
#define MODIFY 1585
#define EQUAL 1587
#define NOT_EQUAL 1588
#define OPEN_SQUARE 1590
#define PUBLIC 1594
#define REVOKE 1598
#define SECOND 1602
#define KW_SELECT 1606
#define SERIAL 1607
#define UNIQUE 1610
#define KW_UPDATE 1612
#define VALUES 1613
#define KW_NULL 1616
#define KW_TRUE 1617
#define ALTER 1619
#define CHECK 1625
#define COUNT 1629
#define KW_FIRST 1634
#define KW_FLOAT 1635
#define GRANT 1638
#define INDEX 1641
#define LESS_THAN 1644
#define MONEY 1646
#define MONTH 1647
#define KW_MULTIPLY 1649
#define ORDER 1650
#define OUTER 1651
#define UNION 1660
#define WHERE 1663
#define KW_BYTE 1670
#define CASE 1672
#define KW_DATE 1674
#define DESC 1675
#define KW_DIVIDE 1676
#define DROP 1679
#define ELSE 1680
#define FROM 1684
#define HOUR 1690
#define INTO 1691
#define LIKE 1694
#define REAL 1703
#define SOME 1708
#define KW_TEXT 1712
#define KW_THEN 1713
#define USER 1714
#define WHEN 1716
#define YEAR 1719
#define KW_DOW 1720
#define XSET 1722
#define ADD 1723
#define ALL 1724
#define KW_AND 1725
#define ANY 1726
#define ASC 1727
#define AVG 1728
#define COLON 1729
#define KW_COMMA 1730
#define DAY 1731
#define DBA 1732
#define KW_FOR 1736
#define XMAX 1741
#define XMIN 1742
#define KW_MINUS 1743
#define KW_MOD 1744
#define KW_NOT 1745
#define KW_SUM 1752
#define ATSIGN 1755
#define KW_PLUS 1756
#define KW_AS 1762
#define KW_BY 1764
#define KW_DOT 1765
#define KW_IN 1768
#define KW_ON 1770
#define KW_OR 1771
#define KW_TO 1772
#define BEFORE 1810
#define END 1814
#define TILDE 1821
#define ILIKE 1822
#define FILLFACTOR 1825
#define TIME 1830
#define KW_TODAY 1837
#define KW_ROWID 1838
#define TIMESTAMP 2186
#define KW_TAG 2207
#define LINTMODULEISLIBRARY 2208




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
#line 591 "y.tab.h"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE sqlparse_yylval;


