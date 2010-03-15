
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
     INT_VALUE = 2231,
     NAMED = 2232,
     NAMED_GEN = 2233,
     CHAR_VALUE = 2234,
     NOT_USED_1 = 2235,
     NOT_USED_2 = 2236,
     NOT_USED_3 = 2237,
     NOT_USED_4 = 2238,
     NOT_USED_5 = 2239,
     NOT_USED_6 = 2240,
     NOT_USED_7 = 2241,
     NOT_USED_8 = 2242,
     NUMBER_VALUE = 2243,
     SEMICOLON = 2244,
     QUESTION_MARK = 2245,
     CLINE = 2246,
     CH = 2247,
     MARK_VAR = 2248,
     END_MARK_VAR = 2249,
     WITH_LISTING_IN = 1001,
     SET_CONSTRAINTS_ALL_DEFERRED = 1002,
     KW_LIMIT = 1003,
     DOCUMENT = 1004,
     ON_EXCEPTION = 1006,
     SET_DEBUG_FILE_TO = 1007,
     CREATE_DBA_PROCEDURE = 1012,
     CREATE_FUNCTION = 1013,
     CREATE_DBA_FUNCTION = 1014,
     USE_SESSION = 1016,
     KW_RUN_CLIENT = 1017,
     LEFT_JOIN = 1019,
     IGNORE_ERRORS = 1022,
     SQLERRMESSAGE = 1023,
     DISPLAY_NULL_TO = 1024,
     UNBUFFERED = 1025,
     KW_PICTURE = 1026,
     ON_CHANGE = 1027,
     INNER_JOIN = 1028,
     UI_INTERFACE_DOT_FRONTCALL = 1031,
     UICOMBOBOX = 1035,
     UIFORM = 1038,
     USING_BTREE = 1054,
     USING_RTREE = 1055,
     SET_BUFFERED_LOG = 1074,
     SET_LOG = 1077,
     MDY = 1079,
     WEEKDAY = 1080,
     MODE_ANSI = 1083,
     START_DATABASE = 1084,
     WITH_LOG_IN = 1085,
     SET_CONSTRAINTS_ALL_IMMEDIATE = 1086,
     DATETIME_VALUE = 1099,
     INTERVAL_VALUE = 1100,
     RECOVER_TABLE = 1101,
     ROLLFORWARD_DATABASE = 1102,
     CONCAT_PIPES = 1116,
     DROP_TRIGGER = 1118,
     DROP_AUDIT_FOR = 1119,
     CREATE_AUDIT_FOR = 1120,
     EXECUTE_PROCEDURE = 1124,
     ALTER_TABLE = 1131,
     ALTER_INDEX = 1132,
     NEXT_SIZE = 1133,
     XSET_MULTIPLY_EQUAL_OPEN_BRACKET = 1170,
     XSET_ident_DOT_MULTIPLY_EQUAL_OPEN_BRACKET = 1171,
     XSET_ident_DOT_MULTIPLY_EQUAL = 1172,
     XSET_MULTIPLY_EQUAL = 1173,
     XSET_OPEN_BRACKET = 1174,
     CREATE_DATABASE = 1177,
     DROP_DATABASE = 1178,
     ADD_CONSTRAINT = 1180,
     DROP_CONSTRAINT = 1181,
     DROP_SYNONYM = 1182,
     CONSTRAINT = 1183,
     NOT_FIELD_TOUCHED_CURRENT = 1186,
     FIELD_TOUCHED_CURRENT = 1187,
     DOUBLE_PRECISION = 1194,
     COUNT_MULTIPLY = 1195,
     MODIFY_NEXT_SIZE = 1215,
     LOCK_MODE_PAGE = 1216,
     LOCK_MODE_ROW = 1217,
     UNITS_YEAR = 1224,
     UNITS_MONTH = 1225,
     UNITS_DAY = 1226,
     UNITS_HOUR = 1227,
     UNITS_MINUTE = 1228,
     UNITS_SECOND = 1229,
     TO_CLUSTER = 1234,
     TO_NOT_CLUSTER = 1235,
     CREATE_UC_IDX = 1237,
     CREATE_U_IDX = 1238,
     CREATE_C_IDX = 1239,
     CREATE_IDX = 1240,
     DOUBLE_COLON = 1250,
     SQLSICS = 1256,
     CREATE_SCHEMA = 1257,
     SQLSIRR = 1258,
     UPDATESTATS_T = 1259,
     SQLSICR = 1260,
     SQLSIDR = 1271,
     CREATE_TEMP_TABLE = 1272,
     WITH_CHECK_OPTION = 1280,
     WITH_GRANT_OPTION = 1281,
     SQLSLMNW = 1282,
     WHERE_CURRENT_OF = 1288,
     NOT_NULL_UNIQUE = 1296,
     SQLSLMW = 1303,
     ALL_PRIVILEGES = 1305,
     CREATE_SYNONYM = 1309,
     DROP_TABLE = 1310,
     INEXCLUSIVE = 1312,
     UPDATESTATS = 1317,
     CREATE_TABLE = 1343,
     DEFAULT_NULL = 1344,
     DEFAULT_TODAY = 1345,
     DEFAULT_USER = 1346,
     UNLOCK_TABLE = 1359,
     ROLLBACK_W = 1367,
     SQLSEON = 1369,
     SQLSEOFF = 1370,
     CREATE_VIEW = 1374,
     DELETE_FROM = 1375,
     EXTENT_SIZE = 1382,
     FOREIGN_KEY = 1383,
     INSERT_INTO = 1386,
     IS_NOT_NULL = 1388,
     NOT_MATCHES = 1391,
     PRIMARY_KEY = 1397,
     WITH_NO_LOG = 1404,
     INSHARE = 1407,
     BEGIN_WORK = 1413,
     DROP_INDEX = 1418,
     FOR_UPDATE_OF = 1424,
     FOR_UPDATE = 1425,
     LOCK_TABLE = 1430,
     NOT_EXISTS = 1432,
     REFERENCES = 1434,
     RENCOL = 1435,
     SMALLFLOAT = 1437,
     COMMIT_W = 1448,
     RENTAB = 1455,
     KW_CHAR = 1458,
     NCHAR = 1459,
     NVARCHAR = 1460,
     DELIMITER = 1462,
     DROP_VIEW = 1464,
     EXCLUSIVE = 1467,
     GREATER_THAN_EQ = 1471,
     INTO_TEMP = 1473,
     DATABASE = 1497,
     DATETIME = 1498,
     DISTINCT = 1500,
     FRACTION = 1507,
     GROUP_BY = 1509,
     INTERVAL = 1510,
     NOT_LIKE = 1512,
     NOT_ILIKE = 1513,
     NOT_NULL = 1514,
     RESOURCE = 1520,
     SMALLINT = 1521,
     IS_NULL = 1527,
     LESS_THAN_EQ = 1528,
     BETWEEN = 1530,
     CLOSE_BRACKET = 1533,
     CONNECT = 1536,
     KW_CURRENT = 1537,
     KW_DECIMAL = 1539,
     DEFAULT = 1541,
     INTEGER = 1549,
     SERIAL8 = 1551,
     MATCHES = 1554,
     VARCHAR = 1567,
     CLOSE_SQUARE = 1570,
     GREATER_THAN = 1571,
     KW_FALSE = 1572,
     NOT_IN = 1573,
     OPEN_BRACKET = 1575,
     KW_DELETE = 1583,
     KW_ESCAPE = 1586,
     EXISTS = 1587,
     EXTEND = 1588,
     HAVING = 1592,
     KW_INSERT = 1594,
     MINUTE = 1598,
     MODIFY = 1599,
     EQUAL = 1601,
     NOT_EQUAL = 1602,
     OPEN_SQUARE = 1604,
     PUBLIC = 1608,
     REVOKE = 1612,
     SECOND = 1616,
     KW_SELECT = 1620,
     SERIAL = 1621,
     UNIQUE = 1624,
     KW_UPDATE = 1626,
     VALUES = 1627,
     KW_NULL = 1630,
     KW_TRUE = 1631,
     ALTER = 1633,
     CHECK = 1639,
     COUNT = 1643,
     KW_FIRST = 1648,
     KW_FLOAT = 1649,
     GRANT = 1652,
     INDEX = 1655,
     LESS_THAN = 1658,
     MONEY = 1660,
     MONTH = 1661,
     KW_MULTIPLY = 1663,
     ORDER = 1664,
     OUTER = 1665,
     UNION = 1674,
     WHERE = 1677,
     KW_BYTE = 1684,
     CASE = 1686,
     KW_DATE = 1688,
     DESC = 1689,
     KW_DIVIDE = 1690,
     DROP = 1693,
     ELSE = 1694,
     FROM = 1698,
     HOUR = 1704,
     INTO = 1705,
     LIKE = 1708,
     REAL = 1717,
     SOME = 1722,
     KW_TEXT = 1726,
     KW_THEN = 1727,
     USER = 1728,
     WHEN = 1730,
     YEAR = 1733,
     KW_DOW = 1734,
     XSET = 1736,
     ADD = 1737,
     ALL = 1738,
     KW_AND = 1739,
     ANY = 1740,
     ASC = 1741,
     AVG = 1742,
     COLON = 1743,
     KW_COMMA = 1744,
     DAY = 1745,
     DBA = 1746,
     KW_FOR = 1750,
     XMAX = 1755,
     XMIN = 1756,
     KW_MINUS = 1757,
     KW_MOD = 1758,
     KW_NOT = 1759,
     KW_SUM = 1766,
     ATSIGN = 1769,
     KW_PLUS = 1770,
     KW_AS = 1776,
     KW_BY = 1778,
     KW_DOT = 1779,
     KW_IN = 1782,
     KW_ON = 1784,
     KW_OR = 1785,
     KW_TO = 1786,
     BEFORE = 1824,
     END = 1828,
     TILDE = 1835,
     ILIKE = 1836,
     FILLFACTOR = 1839,
     TIME = 1844,
     KW_TODAY = 1851,
     KW_ROWID = 1852,
     TIMESTAMP = 2200,
     KW_TAG = 2221,
     LINTMODULEISLIBRARY = 2222,
     KW_PUBLIC = 2223,
     KW_PRIVATE = 2224,
     COPYBACK = 2225,
     REFERENCES_BLOBTYPE_DEFAULT_NULL = 2226,
     REFERENCES_BLOBTYPE = 2227,
     SORT = 2228,
     KWPIPE = 2229
   };
#endif
/* Tokens.  */
#define INT_VALUE 2231
#define NAMED 2232
#define NAMED_GEN 2233
#define CHAR_VALUE 2234
#define NOT_USED_1 2235
#define NOT_USED_2 2236
#define NOT_USED_3 2237
#define NOT_USED_4 2238
#define NOT_USED_5 2239
#define NOT_USED_6 2240
#define NOT_USED_7 2241
#define NOT_USED_8 2242
#define NUMBER_VALUE 2243
#define SEMICOLON 2244
#define QUESTION_MARK 2245
#define CLINE 2246
#define CH 2247
#define MARK_VAR 2248
#define END_MARK_VAR 2249
#define WITH_LISTING_IN 1001
#define SET_CONSTRAINTS_ALL_DEFERRED 1002
#define KW_LIMIT 1003
#define DOCUMENT 1004
#define ON_EXCEPTION 1006
#define SET_DEBUG_FILE_TO 1007
#define CREATE_DBA_PROCEDURE 1012
#define CREATE_FUNCTION 1013
#define CREATE_DBA_FUNCTION 1014
#define USE_SESSION 1016
#define KW_RUN_CLIENT 1017
#define LEFT_JOIN 1019
#define IGNORE_ERRORS 1022
#define SQLERRMESSAGE 1023
#define DISPLAY_NULL_TO 1024
#define UNBUFFERED 1025
#define KW_PICTURE 1026
#define ON_CHANGE 1027
#define INNER_JOIN 1028
#define UI_INTERFACE_DOT_FRONTCALL 1031
#define UICOMBOBOX 1035
#define UIFORM 1038
#define USING_BTREE 1054
#define USING_RTREE 1055
#define SET_BUFFERED_LOG 1074
#define SET_LOG 1077
#define MDY 1079
#define WEEKDAY 1080
#define MODE_ANSI 1083
#define START_DATABASE 1084
#define WITH_LOG_IN 1085
#define SET_CONSTRAINTS_ALL_IMMEDIATE 1086
#define DATETIME_VALUE 1099
#define INTERVAL_VALUE 1100
#define RECOVER_TABLE 1101
#define ROLLFORWARD_DATABASE 1102
#define CONCAT_PIPES 1116
#define DROP_TRIGGER 1118
#define DROP_AUDIT_FOR 1119
#define CREATE_AUDIT_FOR 1120
#define EXECUTE_PROCEDURE 1124
#define ALTER_TABLE 1131
#define ALTER_INDEX 1132
#define NEXT_SIZE 1133
#define XSET_MULTIPLY_EQUAL_OPEN_BRACKET 1170
#define XSET_ident_DOT_MULTIPLY_EQUAL_OPEN_BRACKET 1171
#define XSET_ident_DOT_MULTIPLY_EQUAL 1172
#define XSET_MULTIPLY_EQUAL 1173
#define XSET_OPEN_BRACKET 1174
#define CREATE_DATABASE 1177
#define DROP_DATABASE 1178
#define ADD_CONSTRAINT 1180
#define DROP_CONSTRAINT 1181
#define DROP_SYNONYM 1182
#define CONSTRAINT 1183
#define NOT_FIELD_TOUCHED_CURRENT 1186
#define FIELD_TOUCHED_CURRENT 1187
#define DOUBLE_PRECISION 1194
#define COUNT_MULTIPLY 1195
#define MODIFY_NEXT_SIZE 1215
#define LOCK_MODE_PAGE 1216
#define LOCK_MODE_ROW 1217
#define UNITS_YEAR 1224
#define UNITS_MONTH 1225
#define UNITS_DAY 1226
#define UNITS_HOUR 1227
#define UNITS_MINUTE 1228
#define UNITS_SECOND 1229
#define TO_CLUSTER 1234
#define TO_NOT_CLUSTER 1235
#define CREATE_UC_IDX 1237
#define CREATE_U_IDX 1238
#define CREATE_C_IDX 1239
#define CREATE_IDX 1240
#define DOUBLE_COLON 1250
#define SQLSICS 1256
#define CREATE_SCHEMA 1257
#define SQLSIRR 1258
#define UPDATESTATS_T 1259
#define SQLSICR 1260
#define SQLSIDR 1271
#define CREATE_TEMP_TABLE 1272
#define WITH_CHECK_OPTION 1280
#define WITH_GRANT_OPTION 1281
#define SQLSLMNW 1282
#define WHERE_CURRENT_OF 1288
#define NOT_NULL_UNIQUE 1296
#define SQLSLMW 1303
#define ALL_PRIVILEGES 1305
#define CREATE_SYNONYM 1309
#define DROP_TABLE 1310
#define INEXCLUSIVE 1312
#define UPDATESTATS 1317
#define CREATE_TABLE 1343
#define DEFAULT_NULL 1344
#define DEFAULT_TODAY 1345
#define DEFAULT_USER 1346
#define UNLOCK_TABLE 1359
#define ROLLBACK_W 1367
#define SQLSEON 1369
#define SQLSEOFF 1370
#define CREATE_VIEW 1374
#define DELETE_FROM 1375
#define EXTENT_SIZE 1382
#define FOREIGN_KEY 1383
#define INSERT_INTO 1386
#define IS_NOT_NULL 1388
#define NOT_MATCHES 1391
#define PRIMARY_KEY 1397
#define WITH_NO_LOG 1404
#define INSHARE 1407
#define BEGIN_WORK 1413
#define DROP_INDEX 1418
#define FOR_UPDATE_OF 1424
#define FOR_UPDATE 1425
#define LOCK_TABLE 1430
#define NOT_EXISTS 1432
#define REFERENCES 1434
#define RENCOL 1435
#define SMALLFLOAT 1437
#define COMMIT_W 1448
#define RENTAB 1455
#define KW_CHAR 1458
#define NCHAR 1459
#define NVARCHAR 1460
#define DELIMITER 1462
#define DROP_VIEW 1464
#define EXCLUSIVE 1467
#define GREATER_THAN_EQ 1471
#define INTO_TEMP 1473
#define DATABASE 1497
#define DATETIME 1498
#define DISTINCT 1500
#define FRACTION 1507
#define GROUP_BY 1509
#define INTERVAL 1510
#define NOT_LIKE 1512
#define NOT_ILIKE 1513
#define NOT_NULL 1514
#define RESOURCE 1520
#define SMALLINT 1521
#define IS_NULL 1527
#define LESS_THAN_EQ 1528
#define BETWEEN 1530
#define CLOSE_BRACKET 1533
#define CONNECT 1536
#define KW_CURRENT 1537
#define KW_DECIMAL 1539
#define DEFAULT 1541
#define INTEGER 1549
#define SERIAL8 1551
#define MATCHES 1554
#define VARCHAR 1567
#define CLOSE_SQUARE 1570
#define GREATER_THAN 1571
#define KW_FALSE 1572
#define NOT_IN 1573
#define OPEN_BRACKET 1575
#define KW_DELETE 1583
#define KW_ESCAPE 1586
#define EXISTS 1587
#define EXTEND 1588
#define HAVING 1592
#define KW_INSERT 1594
#define MINUTE 1598
#define MODIFY 1599
#define EQUAL 1601
#define NOT_EQUAL 1602
#define OPEN_SQUARE 1604
#define PUBLIC 1608
#define REVOKE 1612
#define SECOND 1616
#define KW_SELECT 1620
#define SERIAL 1621
#define UNIQUE 1624
#define KW_UPDATE 1626
#define VALUES 1627
#define KW_NULL 1630
#define KW_TRUE 1631
#define ALTER 1633
#define CHECK 1639
#define COUNT 1643
#define KW_FIRST 1648
#define KW_FLOAT 1649
#define GRANT 1652
#define INDEX 1655
#define LESS_THAN 1658
#define MONEY 1660
#define MONTH 1661
#define KW_MULTIPLY 1663
#define ORDER 1664
#define OUTER 1665
#define UNION 1674
#define WHERE 1677
#define KW_BYTE 1684
#define CASE 1686
#define KW_DATE 1688
#define DESC 1689
#define KW_DIVIDE 1690
#define DROP 1693
#define ELSE 1694
#define FROM 1698
#define HOUR 1704
#define INTO 1705
#define LIKE 1708
#define REAL 1717
#define SOME 1722
#define KW_TEXT 1726
#define KW_THEN 1727
#define USER 1728
#define WHEN 1730
#define YEAR 1733
#define KW_DOW 1734
#define XSET 1736
#define ADD 1737
#define ALL 1738
#define KW_AND 1739
#define ANY 1740
#define ASC 1741
#define AVG 1742
#define COLON 1743
#define KW_COMMA 1744
#define DAY 1745
#define DBA 1746
#define KW_FOR 1750
#define XMAX 1755
#define XMIN 1756
#define KW_MINUS 1757
#define KW_MOD 1758
#define KW_NOT 1759
#define KW_SUM 1766
#define ATSIGN 1769
#define KW_PLUS 1770
#define KW_AS 1776
#define KW_BY 1778
#define KW_DOT 1779
#define KW_IN 1782
#define KW_ON 1784
#define KW_OR 1785
#define KW_TO 1786
#define BEFORE 1824
#define END 1828
#define TILDE 1835
#define ILIKE 1836
#define FILLFACTOR 1839
#define TIME 1844
#define KW_TODAY 1851
#define KW_ROWID 1852
#define TIMESTAMP 2200
#define KW_TAG 2221
#define LINTMODULEISLIBRARY 2222
#define KW_PUBLIC 2223
#define KW_PRIVATE 2224
#define COPYBACK 2225
#define REFERENCES_BLOBTYPE_DEFAULT_NULL 2226
#define REFERENCES_BLOBTYPE 2227
#define SORT 2228
#define KWPIPE 2229




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 1676 of yacc.c  */
#line 144 "sql.yacc"

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
#line 635 "y.tab.h"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE sqlparse_yylval;


