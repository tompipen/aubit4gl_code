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
     INT_VALUE = 2164,
     NAMED = 2165,
     NAMED_GEN = 2166,
     CHAR_VALUE = 2167,
     NOT_USED_1 = 2168,
     NOT_USED_2 = 2169,
     NOT_USED_3 = 2170,
     NOT_USED_4 = 2171,
     NOT_USED_5 = 2172,
     NOT_USED_6 = 2173,
     NOT_USED_7 = 2174,
     NOT_USED_8 = 2175,
     NUMBER_VALUE = 2176,
     SEMICOLON = 2177,
     QUESTION_MARK = 2178,
     CLINE = 2179,
     CH = 2180,
     MARK_VAR = 2181,
     END_MARK_VAR = 2182,
     LEFT_JOIN = 1001,
     WITH_CONVERSIONS = 1007,
     WITHOUT_CONVERSIONS = 1008,
     USING_BTREE = 1015,
     USING_RTREE = 1016,
     ASCOPY = 1033,
     SET_BUFFERED_LOG = 1041,
     SET_LOG = 1042,
     MDY = 1044,
     WEEKDAY = 1045,
     MODE_ANSI = 1048,
     START_DATABASE = 1049,
     WITH_LOG_IN = 1050,
     SET_CONSTRAINTS_ALL_IMMEDIATE = 1051,
     DATETIME_VALUE = 1064,
     INTERVAL_VALUE = 1065,
     RECOVER_TABLE = 1066,
     ROLLFORWARD_DATABASE = 1067,
     DROP_TRIGGER = 1083,
     DROP_AUDIT_FOR = 1084,
     CREATE_AUDIT_FOR = 1085,
     EXECUTE_PROCEDURE = 1089,
     ALTER_TABLE = 1096,
     ALTER_INDEX = 1097,
     NEXT_SIZE = 1098,
     XSET_MULTIPLY_EQUAL_OPEN_BRACKET = 1135,
     XSET_ident_DOT_MULTIPLY_EQUAL_OPEN_BRACKET = 1136,
     XSET_ident_DOT_MULTIPLY_EQUAL = 1137,
     XSET_MULTIPLY_EQUAL = 1138,
     XSET_OPEN_BRACKET = 1139,
     CREATE_DATABASE = 1142,
     DROP_DATABASE = 1143,
     ADD_CONSTRAINT = 1145,
     DROP_CONSTRAINT = 1146,
     DROP_SYNONYM = 1147,
     CONSTRAINT = 1148,
     LOCAL_REPORT = 1152,
     LOCAL_PDF_REPORT = 1153,
     DOUBLE_PRECISION = 1157,
     COUNT_MULTIPLY = 1158,
     MODIFY_NEXT_SIZE = 1178,
     LOCK_MODE_PAGE = 1179,
     LOCK_MODE_ROW = 1180,
     UNITS_YEAR = 1187,
     UNITS_MONTH = 1188,
     UNITS_DAY = 1189,
     UNITS_HOUR = 1190,
     UNITS_MINUTE = 1191,
     UNITS_SECOND = 1192,
     TO_CLUSTER = 1197,
     TO_NOT_CLUSTER = 1198,
     CREATE_UC_IDX = 1200,
     CREATE_U_IDX = 1201,
     CREATE_C_IDX = 1202,
     CREATE_IDX = 1203,
     DOUBLE_COLON = 1212,
     SQLSICS = 1218,
     CREATE_SCHEMA = 1219,
     SQLSIRR = 1220,
     UPDATESTATS_T = 1221,
     SQLSICR = 1222,
     SQLSIDR = 1233,
     CREATE_TEMP_TABLE = 1234,
     WITH_CHECK_OPTION = 1242,
     WITH_GRANT_OPTION = 1243,
     SQLSLMNW = 1244,
     WHERE_CURRENT_OF = 1250,
     NOT_NULL_UNIQUE = 1258,
     SQLSLMW = 1265,
     ALL_PRIVILEGES = 1267,
     CREATE_SYNONYM = 1271,
     DROP_TABLE = 1272,
     INEXCLUSIVE = 1274,
     UPDATESTATS = 1279,
     CREATE_TABLE = 1305,
     DEFAULT_NULL = 1306,
     DEFAULT_TODAY = 1307,
     DEFAULT_USER = 1308,
     UNLOCK_TABLE = 1321,
     ROLLBACK_W = 1329,
     SQLSEON = 1331,
     SQLSEOFF = 1332,
     CREATE_VIEW = 1336,
     DELETE_FROM = 1337,
     EXTENT_SIZE = 1344,
     FOREIGN_KEY = 1345,
     INSERT_INTO = 1348,
     IS_NOT_NULL = 1350,
     NOT_MATCHES = 1353,
     PRIMARY_KEY = 1359,
     USE_SESSION = 1366,
     WITH_NO_LOG = 1367,
     INSHARE = 1370,
     BEGIN_WORK = 1376,
     DROP_INDEX = 1381,
     FOR_UPDATE_OF = 1387,
     FOR_UPDATE = 1388,
     REFERENCE = 1390,
     LOCK_TABLE = 1393,
     NOT_EXISTS = 1395,
     REFERENCES = 1397,
     RENCOL = 1398,
     SMALLFLOAT = 1400,
     COMMIT_W = 1411,
     RENTAB = 1418,
     KW_CHAR = 1421,
     NCHAR = 1422,
     NVARCHAR = 1423,
     DELIMITER = 1425,
     DROP_VIEW = 1427,
     EXCLUSIVE = 1430,
     GREATER_THAN_EQ = 1434,
     INTO_TEMP = 1436,
     LOAD_FROM = 1440,
     UNLOAD_TO = 1451,
     DATABASE = 1460,
     DATETIME = 1461,
     DISTINCT = 1463,
     FRACTION = 1470,
     GROUP_BY = 1472,
     INTERVAL = 1473,
     NOT_LIKE = 1475,
     NOT_ILIKE = 1476,
     NOT_NULL = 1477,
     RESOURCE = 1483,
     SMALLINT = 1484,
     IS_NULL = 1490,
     LESS_THAN_EQ = 1491,
     BETWEEN = 1493,
     CLOSE_BRACKET = 1496,
     CONNECT = 1499,
     KW_CURRENT = 1500,
     KW_DECIMAL = 1502,
     DEFAULT = 1504,
     INTEGER = 1512,
     SERIAL8 = 1514,
     MATCHES = 1517,
     VARCHAR = 1530,
     CLOSE_SQUARE = 1533,
     GREATER_THAN = 1534,
     KW_FALSE = 1535,
     NOT_IN = 1536,
     OPEN_BRACKET = 1538,
     KW_DELETE = 1546,
     KW_ESCAPE = 1549,
     EXISTS = 1550,
     EXTEND = 1551,
     HAVING = 1555,
     KW_INSERT = 1557,
     MINUTE = 1561,
     MODIFY = 1562,
     EQUAL = 1564,
     NOT_EQUAL = 1565,
     OPEN_SQUARE = 1567,
     PUBLIC = 1571,
     REVOKE = 1574,
     SECOND = 1578,
     KW_SELECT = 1582,
     SERIAL = 1583,
     UNIQUE = 1586,
     KW_UPDATE = 1588,
     VALUES = 1589,
     KW_NULL = 1593,
     KW_TRUE = 1594,
     ALTER = 1596,
     CHECK = 1602,
     COUNT = 1606,
     KW_FIRST = 1611,
     KW_FLOAT = 1612,
     GRANT = 1615,
     INDEX = 1618,
     LESS_THAN = 1621,
     MONEY = 1623,
     MONTH = 1624,
     KW_MULTIPLY = 1626,
     ORDER = 1627,
     OUTER = 1628,
     UNION = 1637,
     WHERE = 1639,
     KW_BYTE = 1646,
     CASE = 1648,
     KW_DATE = 1650,
     DESC = 1651,
     KW_DIVIDE = 1652,
     DROP = 1655,
     ELSE = 1656,
     FROM = 1660,
     HOUR = 1666,
     INTO = 1667,
     LIKE = 1670,
     REAL = 1679,
     SOME = 1684,
     KW_TEXT = 1688,
     KW_THEN = 1689,
     USER = 1690,
     WHEN = 1692,
     YEAR = 1695,
     KW_DOW = 1696,
     XSET = 1698,
     ADD = 1699,
     ALL = 1700,
     KW_AND = 1701,
     ANY = 1702,
     ASC = 1703,
     AVG = 1704,
     COLON = 1705,
     KW_COMMA = 1706,
     DAY = 1707,
     DBA = 1708,
     KW_FOR = 1712,
     XMAX = 1717,
     XMIN = 1718,
     KW_MINUS = 1719,
     KW_MOD = 1720,
     KW_NOT = 1721,
     KW_ROW = 1725,
     KW_SUM = 1728,
     ATSIGN = 1731,
     KW_PLUS = 1732,
     KW_AS_USER = 1737,
     KW_AS = 1738,
     KW_BY = 1740,
     KW_DOT = 1741,
     KW_IN = 1744,
     KW_ON = 1746,
     KW_OR = 1747,
     KW_TO = 1748,
     BEFORE = 1786,
     END = 1790,
     TILDE = 1797,
     ILIKE = 1798,
     FILLFACTOR = 1801,
     KW_EXTENDS = 1804,
     TIME = 1806,
     KW_TODAY = 1813,
     KW_ROWID = 1814,
     CURSOR_NAME_FUNCTION = 2161,
     TIMESTAMP = 2162
   };
#endif
/* Tokens.  */
#define INT_VALUE 2164
#define NAMED 2165
#define NAMED_GEN 2166
#define CHAR_VALUE 2167
#define NOT_USED_1 2168
#define NOT_USED_2 2169
#define NOT_USED_3 2170
#define NOT_USED_4 2171
#define NOT_USED_5 2172
#define NOT_USED_6 2173
#define NOT_USED_7 2174
#define NOT_USED_8 2175
#define NUMBER_VALUE 2176
#define SEMICOLON 2177
#define QUESTION_MARK 2178
#define CLINE 2179
#define CH 2180
#define MARK_VAR 2181
#define END_MARK_VAR 2182
#define LEFT_JOIN 1001
#define WITH_CONVERSIONS 1007
#define WITHOUT_CONVERSIONS 1008
#define USING_BTREE 1015
#define USING_RTREE 1016
#define ASCOPY 1033
#define SET_BUFFERED_LOG 1041
#define SET_LOG 1042
#define MDY 1044
#define WEEKDAY 1045
#define MODE_ANSI 1048
#define START_DATABASE 1049
#define WITH_LOG_IN 1050
#define SET_CONSTRAINTS_ALL_IMMEDIATE 1051
#define DATETIME_VALUE 1064
#define INTERVAL_VALUE 1065
#define RECOVER_TABLE 1066
#define ROLLFORWARD_DATABASE 1067
#define DROP_TRIGGER 1083
#define DROP_AUDIT_FOR 1084
#define CREATE_AUDIT_FOR 1085
#define EXECUTE_PROCEDURE 1089
#define ALTER_TABLE 1096
#define ALTER_INDEX 1097
#define NEXT_SIZE 1098
#define XSET_MULTIPLY_EQUAL_OPEN_BRACKET 1135
#define XSET_ident_DOT_MULTIPLY_EQUAL_OPEN_BRACKET 1136
#define XSET_ident_DOT_MULTIPLY_EQUAL 1137
#define XSET_MULTIPLY_EQUAL 1138
#define XSET_OPEN_BRACKET 1139
#define CREATE_DATABASE 1142
#define DROP_DATABASE 1143
#define ADD_CONSTRAINT 1145
#define DROP_CONSTRAINT 1146
#define DROP_SYNONYM 1147
#define CONSTRAINT 1148
#define LOCAL_REPORT 1152
#define LOCAL_PDF_REPORT 1153
#define DOUBLE_PRECISION 1157
#define COUNT_MULTIPLY 1158
#define MODIFY_NEXT_SIZE 1178
#define LOCK_MODE_PAGE 1179
#define LOCK_MODE_ROW 1180
#define UNITS_YEAR 1187
#define UNITS_MONTH 1188
#define UNITS_DAY 1189
#define UNITS_HOUR 1190
#define UNITS_MINUTE 1191
#define UNITS_SECOND 1192
#define TO_CLUSTER 1197
#define TO_NOT_CLUSTER 1198
#define CREATE_UC_IDX 1200
#define CREATE_U_IDX 1201
#define CREATE_C_IDX 1202
#define CREATE_IDX 1203
#define DOUBLE_COLON 1212
#define SQLSICS 1218
#define CREATE_SCHEMA 1219
#define SQLSIRR 1220
#define UPDATESTATS_T 1221
#define SQLSICR 1222
#define SQLSIDR 1233
#define CREATE_TEMP_TABLE 1234
#define WITH_CHECK_OPTION 1242
#define WITH_GRANT_OPTION 1243
#define SQLSLMNW 1244
#define WHERE_CURRENT_OF 1250
#define NOT_NULL_UNIQUE 1258
#define SQLSLMW 1265
#define ALL_PRIVILEGES 1267
#define CREATE_SYNONYM 1271
#define DROP_TABLE 1272
#define INEXCLUSIVE 1274
#define UPDATESTATS 1279
#define CREATE_TABLE 1305
#define DEFAULT_NULL 1306
#define DEFAULT_TODAY 1307
#define DEFAULT_USER 1308
#define UNLOCK_TABLE 1321
#define ROLLBACK_W 1329
#define SQLSEON 1331
#define SQLSEOFF 1332
#define CREATE_VIEW 1336
#define DELETE_FROM 1337
#define EXTENT_SIZE 1344
#define FOREIGN_KEY 1345
#define INSERT_INTO 1348
#define IS_NOT_NULL 1350
#define NOT_MATCHES 1353
#define PRIMARY_KEY 1359
#define USE_SESSION 1366
#define WITH_NO_LOG 1367
#define INSHARE 1370
#define BEGIN_WORK 1376
#define DROP_INDEX 1381
#define FOR_UPDATE_OF 1387
#define FOR_UPDATE 1388
#define REFERENCE 1390
#define LOCK_TABLE 1393
#define NOT_EXISTS 1395
#define REFERENCES 1397
#define RENCOL 1398
#define SMALLFLOAT 1400
#define COMMIT_W 1411
#define RENTAB 1418
#define KW_CHAR 1421
#define NCHAR 1422
#define NVARCHAR 1423
#define DELIMITER 1425
#define DROP_VIEW 1427
#define EXCLUSIVE 1430
#define GREATER_THAN_EQ 1434
#define INTO_TEMP 1436
#define LOAD_FROM 1440
#define UNLOAD_TO 1451
#define DATABASE 1460
#define DATETIME 1461
#define DISTINCT 1463
#define FRACTION 1470
#define GROUP_BY 1472
#define INTERVAL 1473
#define NOT_LIKE 1475
#define NOT_ILIKE 1476
#define NOT_NULL 1477
#define RESOURCE 1483
#define SMALLINT 1484
#define IS_NULL 1490
#define LESS_THAN_EQ 1491
#define BETWEEN 1493
#define CLOSE_BRACKET 1496
#define CONNECT 1499
#define KW_CURRENT 1500
#define KW_DECIMAL 1502
#define DEFAULT 1504
#define INTEGER 1512
#define SERIAL8 1514
#define MATCHES 1517
#define VARCHAR 1530
#define CLOSE_SQUARE 1533
#define GREATER_THAN 1534
#define KW_FALSE 1535
#define NOT_IN 1536
#define OPEN_BRACKET 1538
#define KW_DELETE 1546
#define KW_ESCAPE 1549
#define EXISTS 1550
#define EXTEND 1551
#define HAVING 1555
#define KW_INSERT 1557
#define MINUTE 1561
#define MODIFY 1562
#define EQUAL 1564
#define NOT_EQUAL 1565
#define OPEN_SQUARE 1567
#define PUBLIC 1571
#define REVOKE 1574
#define SECOND 1578
#define KW_SELECT 1582
#define SERIAL 1583
#define UNIQUE 1586
#define KW_UPDATE 1588
#define VALUES 1589
#define KW_NULL 1593
#define KW_TRUE 1594
#define ALTER 1596
#define CHECK 1602
#define COUNT 1606
#define KW_FIRST 1611
#define KW_FLOAT 1612
#define GRANT 1615
#define INDEX 1618
#define LESS_THAN 1621
#define MONEY 1623
#define MONTH 1624
#define KW_MULTIPLY 1626
#define ORDER 1627
#define OUTER 1628
#define UNION 1637
#define WHERE 1639
#define KW_BYTE 1646
#define CASE 1648
#define KW_DATE 1650
#define DESC 1651
#define KW_DIVIDE 1652
#define DROP 1655
#define ELSE 1656
#define FROM 1660
#define HOUR 1666
#define INTO 1667
#define LIKE 1670
#define REAL 1679
#define SOME 1684
#define KW_TEXT 1688
#define KW_THEN 1689
#define USER 1690
#define WHEN 1692
#define YEAR 1695
#define KW_DOW 1696
#define XSET 1698
#define ADD 1699
#define ALL 1700
#define KW_AND 1701
#define ANY 1702
#define ASC 1703
#define AVG 1704
#define COLON 1705
#define KW_COMMA 1706
#define DAY 1707
#define DBA 1708
#define KW_FOR 1712
#define XMAX 1717
#define XMIN 1718
#define KW_MINUS 1719
#define KW_MOD 1720
#define KW_NOT 1721
#define KW_ROW 1725
#define KW_SUM 1728
#define ATSIGN 1731
#define KW_PLUS 1732
#define KW_AS_USER 1737
#define KW_AS 1738
#define KW_BY 1740
#define KW_DOT 1741
#define KW_IN 1744
#define KW_ON 1746
#define KW_OR 1747
#define KW_TO 1748
#define BEFORE 1786
#define END 1790
#define TILDE 1797
#define ILIKE 1798
#define FILLFACTOR 1801
#define KW_EXTENDS 1804
#define TIME 1806
#define KW_TODAY 1813
#define KW_ROWID 1814
#define CURSOR_NAME_FUNCTION 2161
#define TIMESTAMP 2162




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
#line 590 "y.tab.h"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE sqlparse_yylval;

