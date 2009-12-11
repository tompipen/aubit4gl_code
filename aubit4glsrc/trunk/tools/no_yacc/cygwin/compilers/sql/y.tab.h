
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
     INT_VALUE = 2228,
     NAMED = 2229,
     NAMED_GEN = 2230,
     CHAR_VALUE = 2231,
     NOT_USED_1 = 2232,
     NOT_USED_2 = 2233,
     NOT_USED_3 = 2234,
     NOT_USED_4 = 2235,
     NOT_USED_5 = 2236,
     NOT_USED_6 = 2237,
     NOT_USED_7 = 2238,
     NOT_USED_8 = 2239,
     NUMBER_VALUE = 2240,
     SEMICOLON = 2241,
     QUESTION_MARK = 2242,
     CLINE = 2243,
     CH = 2244,
     MARK_VAR = 2245,
     END_MARK_VAR = 2246,
     WITH_LISTING_IN = 1001,
     DOCUMENT = 1002,
     ON_EXCEPTION = 1004,
     SET_DEBUG_FILE_TO = 1005,
     CREATE_DBA_PROCEDURE = 1010,
     CREATE_FUNCTION = 1011,
     CREATE_DBA_FUNCTION = 1012,
     USE_SESSION = 1014,
     KW_RUN_CLIENT = 1015,
     LEFT_JOIN = 1017,
     IGNORE_ERRORS = 1020,
     SQLERRMESSAGE = 1021,
     DISPLAY_NULL_TO = 1022,
     UNBUFFERED = 1023,
     KW_PICTURE = 1024,
     ON_CHANGE = 1025,
     INNER_JOIN = 1026,
     UI_INTERFACE_DOT_FRONTCALL = 1029,
     UICOMBOBOX = 1033,
     UIFORM = 1036,
     USING_BTREE = 1052,
     USING_RTREE = 1053,
     SET_BUFFERED_LOG = 1072,
     SET_LOG = 1075,
     MDY = 1077,
     WEEKDAY = 1078,
     MODE_ANSI = 1081,
     START_DATABASE = 1082,
     WITH_LOG_IN = 1083,
     SET_CONSTRAINTS_ALL_IMMEDIATE = 1084,
     DATETIME_VALUE = 1097,
     INTERVAL_VALUE = 1098,
     RECOVER_TABLE = 1099,
     ROLLFORWARD_DATABASE = 1100,
     DROP_TRIGGER = 1116,
     DROP_AUDIT_FOR = 1117,
     CREATE_AUDIT_FOR = 1118,
     EXECUTE_PROCEDURE = 1122,
     ALTER_TABLE = 1129,
     ALTER_INDEX = 1130,
     NEXT_SIZE = 1131,
     XSET_MULTIPLY_EQUAL_OPEN_BRACKET = 1168,
     XSET_ident_DOT_MULTIPLY_EQUAL_OPEN_BRACKET = 1169,
     XSET_ident_DOT_MULTIPLY_EQUAL = 1170,
     XSET_MULTIPLY_EQUAL = 1171,
     XSET_OPEN_BRACKET = 1172,
     CREATE_DATABASE = 1175,
     DROP_DATABASE = 1176,
     ADD_CONSTRAINT = 1178,
     DROP_CONSTRAINT = 1179,
     DROP_SYNONYM = 1180,
     CONSTRAINT = 1181,
     NOT_FIELD_TOUCHED_CURRENT = 1184,
     FIELD_TOUCHED_CURRENT = 1185,
     DOUBLE_PRECISION = 1192,
     COUNT_MULTIPLY = 1193,
     MODIFY_NEXT_SIZE = 1213,
     LOCK_MODE_PAGE = 1214,
     LOCK_MODE_ROW = 1215,
     UNITS_YEAR = 1222,
     UNITS_MONTH = 1223,
     UNITS_DAY = 1224,
     UNITS_HOUR = 1225,
     UNITS_MINUTE = 1226,
     UNITS_SECOND = 1227,
     TO_CLUSTER = 1232,
     TO_NOT_CLUSTER = 1233,
     CREATE_UC_IDX = 1235,
     CREATE_U_IDX = 1236,
     CREATE_C_IDX = 1237,
     CREATE_IDX = 1238,
     DOUBLE_COLON = 1248,
     SQLSICS = 1254,
     CREATE_SCHEMA = 1255,
     SQLSIRR = 1256,
     UPDATESTATS_T = 1257,
     SQLSICR = 1258,
     SQLSIDR = 1269,
     CREATE_TEMP_TABLE = 1270,
     WITH_CHECK_OPTION = 1278,
     WITH_GRANT_OPTION = 1279,
     SQLSLMNW = 1280,
     WHERE_CURRENT_OF = 1286,
     NOT_NULL_UNIQUE = 1294,
     SQLSLMW = 1301,
     ALL_PRIVILEGES = 1303,
     CREATE_SYNONYM = 1307,
     DROP_TABLE = 1308,
     INEXCLUSIVE = 1310,
     UPDATESTATS = 1315,
     CREATE_TABLE = 1341,
     DEFAULT_NULL = 1342,
     DEFAULT_TODAY = 1343,
     DEFAULT_USER = 1344,
     UNLOCK_TABLE = 1357,
     ROLLBACK_W = 1365,
     SQLSEON = 1367,
     SQLSEOFF = 1368,
     CREATE_VIEW = 1372,
     DELETE_FROM = 1373,
     EXTENT_SIZE = 1380,
     FOREIGN_KEY = 1381,
     INSERT_INTO = 1384,
     IS_NOT_NULL = 1386,
     NOT_MATCHES = 1389,
     PRIMARY_KEY = 1395,
     WITH_NO_LOG = 1402,
     INSHARE = 1405,
     BEGIN_WORK = 1411,
     DROP_INDEX = 1416,
     FOR_UPDATE_OF = 1422,
     FOR_UPDATE = 1423,
     LOCK_TABLE = 1428,
     NOT_EXISTS = 1430,
     REFERENCES = 1432,
     RENCOL = 1433,
     SMALLFLOAT = 1435,
     COMMIT_W = 1446,
     RENTAB = 1453,
     KW_CHAR = 1456,
     NCHAR = 1457,
     NVARCHAR = 1458,
     DELIMITER = 1460,
     DROP_VIEW = 1462,
     EXCLUSIVE = 1465,
     GREATER_THAN_EQ = 1469,
     INTO_TEMP = 1471,
     DATABASE = 1495,
     DATETIME = 1496,
     DISTINCT = 1498,
     FRACTION = 1505,
     GROUP_BY = 1507,
     INTERVAL = 1508,
     NOT_LIKE = 1510,
     NOT_ILIKE = 1511,
     NOT_NULL = 1512,
     RESOURCE = 1518,
     SMALLINT = 1519,
     IS_NULL = 1525,
     LESS_THAN_EQ = 1526,
     BETWEEN = 1528,
     CLOSE_BRACKET = 1531,
     CONNECT = 1534,
     KW_CURRENT = 1535,
     KW_DECIMAL = 1537,
     DEFAULT = 1539,
     INTEGER = 1547,
     SERIAL8 = 1549,
     MATCHES = 1552,
     VARCHAR = 1565,
     CLOSE_SQUARE = 1568,
     GREATER_THAN = 1569,
     KW_FALSE = 1570,
     NOT_IN = 1571,
     OPEN_BRACKET = 1573,
     KW_DELETE = 1581,
     KW_ESCAPE = 1584,
     EXISTS = 1585,
     EXTEND = 1586,
     HAVING = 1590,
     KW_INSERT = 1592,
     MINUTE = 1596,
     MODIFY = 1597,
     EQUAL = 1599,
     NOT_EQUAL = 1600,
     OPEN_SQUARE = 1602,
     PUBLIC = 1606,
     REVOKE = 1610,
     SECOND = 1614,
     KW_SELECT = 1618,
     SERIAL = 1619,
     UNIQUE = 1622,
     KW_UPDATE = 1624,
     VALUES = 1625,
     KW_NULL = 1628,
     KW_TRUE = 1629,
     ALTER = 1631,
     CHECK = 1637,
     COUNT = 1641,
     KW_FIRST = 1646,
     KW_FLOAT = 1647,
     GRANT = 1650,
     INDEX = 1653,
     LESS_THAN = 1656,
     MONEY = 1658,
     MONTH = 1659,
     KW_MULTIPLY = 1661,
     ORDER = 1662,
     OUTER = 1663,
     UNION = 1672,
     WHERE = 1675,
     KW_BYTE = 1682,
     CASE = 1684,
     KW_DATE = 1686,
     DESC = 1687,
     KW_DIVIDE = 1688,
     DROP = 1691,
     ELSE = 1692,
     FROM = 1696,
     HOUR = 1702,
     INTO = 1703,
     LIKE = 1706,
     REAL = 1715,
     SOME = 1720,
     KW_TEXT = 1724,
     KW_THEN = 1725,
     USER = 1726,
     WHEN = 1728,
     YEAR = 1731,
     KW_DOW = 1732,
     XSET = 1734,
     ADD = 1735,
     ALL = 1736,
     KW_AND = 1737,
     ANY = 1738,
     ASC = 1739,
     AVG = 1740,
     COLON = 1741,
     KW_COMMA = 1742,
     DAY = 1743,
     DBA = 1744,
     KW_FOR = 1748,
     XMAX = 1753,
     XMIN = 1754,
     KW_MINUS = 1755,
     KW_MOD = 1756,
     KW_NOT = 1757,
     KW_SUM = 1764,
     ATSIGN = 1767,
     KW_PLUS = 1768,
     KW_AS = 1774,
     KW_BY = 1776,
     KW_DOT = 1777,
     KW_IN = 1780,
     KW_ON = 1782,
     KW_OR = 1783,
     KW_TO = 1784,
     BEFORE = 1822,
     END = 1826,
     TILDE = 1833,
     ILIKE = 1834,
     FILLFACTOR = 1837,
     TIME = 1842,
     KW_TODAY = 1849,
     KW_ROWID = 1850,
     TIMESTAMP = 2198,
     KW_TAG = 2219,
     LINTMODULEISLIBRARY = 2220,
     KW_PUBLIC = 2221,
     KW_PRIVATE = 2222,
     COPYBACK = 2223,
     REFERENCES_BLOBTYPE_DEFAULT_NULL = 2224,
     REFERENCES_BLOBTYPE = 2225,
     BEGIN = 2226
   };
#endif
/* Tokens.  */
#define INT_VALUE 2228
#define NAMED 2229
#define NAMED_GEN 2230
#define CHAR_VALUE 2231
#define NOT_USED_1 2232
#define NOT_USED_2 2233
#define NOT_USED_3 2234
#define NOT_USED_4 2235
#define NOT_USED_5 2236
#define NOT_USED_6 2237
#define NOT_USED_7 2238
#define NOT_USED_8 2239
#define NUMBER_VALUE 2240
#define SEMICOLON 2241
#define QUESTION_MARK 2242
#define CLINE 2243
#define CH 2244
#define MARK_VAR 2245
#define END_MARK_VAR 2246
#define WITH_LISTING_IN 1001
#define DOCUMENT 1002
#define ON_EXCEPTION 1004
#define SET_DEBUG_FILE_TO 1005
#define CREATE_DBA_PROCEDURE 1010
#define CREATE_FUNCTION 1011
#define CREATE_DBA_FUNCTION 1012
#define USE_SESSION 1014
#define KW_RUN_CLIENT 1015
#define LEFT_JOIN 1017
#define IGNORE_ERRORS 1020
#define SQLERRMESSAGE 1021
#define DISPLAY_NULL_TO 1022
#define UNBUFFERED 1023
#define KW_PICTURE 1024
#define ON_CHANGE 1025
#define INNER_JOIN 1026
#define UI_INTERFACE_DOT_FRONTCALL 1029
#define UICOMBOBOX 1033
#define UIFORM 1036
#define USING_BTREE 1052
#define USING_RTREE 1053
#define SET_BUFFERED_LOG 1072
#define SET_LOG 1075
#define MDY 1077
#define WEEKDAY 1078
#define MODE_ANSI 1081
#define START_DATABASE 1082
#define WITH_LOG_IN 1083
#define SET_CONSTRAINTS_ALL_IMMEDIATE 1084
#define DATETIME_VALUE 1097
#define INTERVAL_VALUE 1098
#define RECOVER_TABLE 1099
#define ROLLFORWARD_DATABASE 1100
#define DROP_TRIGGER 1116
#define DROP_AUDIT_FOR 1117
#define CREATE_AUDIT_FOR 1118
#define EXECUTE_PROCEDURE 1122
#define ALTER_TABLE 1129
#define ALTER_INDEX 1130
#define NEXT_SIZE 1131
#define XSET_MULTIPLY_EQUAL_OPEN_BRACKET 1168
#define XSET_ident_DOT_MULTIPLY_EQUAL_OPEN_BRACKET 1169
#define XSET_ident_DOT_MULTIPLY_EQUAL 1170
#define XSET_MULTIPLY_EQUAL 1171
#define XSET_OPEN_BRACKET 1172
#define CREATE_DATABASE 1175
#define DROP_DATABASE 1176
#define ADD_CONSTRAINT 1178
#define DROP_CONSTRAINT 1179
#define DROP_SYNONYM 1180
#define CONSTRAINT 1181
#define NOT_FIELD_TOUCHED_CURRENT 1184
#define FIELD_TOUCHED_CURRENT 1185
#define DOUBLE_PRECISION 1192
#define COUNT_MULTIPLY 1193
#define MODIFY_NEXT_SIZE 1213
#define LOCK_MODE_PAGE 1214
#define LOCK_MODE_ROW 1215
#define UNITS_YEAR 1222
#define UNITS_MONTH 1223
#define UNITS_DAY 1224
#define UNITS_HOUR 1225
#define UNITS_MINUTE 1226
#define UNITS_SECOND 1227
#define TO_CLUSTER 1232
#define TO_NOT_CLUSTER 1233
#define CREATE_UC_IDX 1235
#define CREATE_U_IDX 1236
#define CREATE_C_IDX 1237
#define CREATE_IDX 1238
#define DOUBLE_COLON 1248
#define SQLSICS 1254
#define CREATE_SCHEMA 1255
#define SQLSIRR 1256
#define UPDATESTATS_T 1257
#define SQLSICR 1258
#define SQLSIDR 1269
#define CREATE_TEMP_TABLE 1270
#define WITH_CHECK_OPTION 1278
#define WITH_GRANT_OPTION 1279
#define SQLSLMNW 1280
#define WHERE_CURRENT_OF 1286
#define NOT_NULL_UNIQUE 1294
#define SQLSLMW 1301
#define ALL_PRIVILEGES 1303
#define CREATE_SYNONYM 1307
#define DROP_TABLE 1308
#define INEXCLUSIVE 1310
#define UPDATESTATS 1315
#define CREATE_TABLE 1341
#define DEFAULT_NULL 1342
#define DEFAULT_TODAY 1343
#define DEFAULT_USER 1344
#define UNLOCK_TABLE 1357
#define ROLLBACK_W 1365
#define SQLSEON 1367
#define SQLSEOFF 1368
#define CREATE_VIEW 1372
#define DELETE_FROM 1373
#define EXTENT_SIZE 1380
#define FOREIGN_KEY 1381
#define INSERT_INTO 1384
#define IS_NOT_NULL 1386
#define NOT_MATCHES 1389
#define PRIMARY_KEY 1395
#define WITH_NO_LOG 1402
#define INSHARE 1405
#define BEGIN_WORK 1411
#define DROP_INDEX 1416
#define FOR_UPDATE_OF 1422
#define FOR_UPDATE 1423
#define LOCK_TABLE 1428
#define NOT_EXISTS 1430
#define REFERENCES 1432
#define RENCOL 1433
#define SMALLFLOAT 1435
#define COMMIT_W 1446
#define RENTAB 1453
#define KW_CHAR 1456
#define NCHAR 1457
#define NVARCHAR 1458
#define DELIMITER 1460
#define DROP_VIEW 1462
#define EXCLUSIVE 1465
#define GREATER_THAN_EQ 1469
#define INTO_TEMP 1471
#define DATABASE 1495
#define DATETIME 1496
#define DISTINCT 1498
#define FRACTION 1505
#define GROUP_BY 1507
#define INTERVAL 1508
#define NOT_LIKE 1510
#define NOT_ILIKE 1511
#define NOT_NULL 1512
#define RESOURCE 1518
#define SMALLINT 1519
#define IS_NULL 1525
#define LESS_THAN_EQ 1526
#define BETWEEN 1528
#define CLOSE_BRACKET 1531
#define CONNECT 1534
#define KW_CURRENT 1535
#define KW_DECIMAL 1537
#define DEFAULT 1539
#define INTEGER 1547
#define SERIAL8 1549
#define MATCHES 1552
#define VARCHAR 1565
#define CLOSE_SQUARE 1568
#define GREATER_THAN 1569
#define KW_FALSE 1570
#define NOT_IN 1571
#define OPEN_BRACKET 1573
#define KW_DELETE 1581
#define KW_ESCAPE 1584
#define EXISTS 1585
#define EXTEND 1586
#define HAVING 1590
#define KW_INSERT 1592
#define MINUTE 1596
#define MODIFY 1597
#define EQUAL 1599
#define NOT_EQUAL 1600
#define OPEN_SQUARE 1602
#define PUBLIC 1606
#define REVOKE 1610
#define SECOND 1614
#define KW_SELECT 1618
#define SERIAL 1619
#define UNIQUE 1622
#define KW_UPDATE 1624
#define VALUES 1625
#define KW_NULL 1628
#define KW_TRUE 1629
#define ALTER 1631
#define CHECK 1637
#define COUNT 1641
#define KW_FIRST 1646
#define KW_FLOAT 1647
#define GRANT 1650
#define INDEX 1653
#define LESS_THAN 1656
#define MONEY 1658
#define MONTH 1659
#define KW_MULTIPLY 1661
#define ORDER 1662
#define OUTER 1663
#define UNION 1672
#define WHERE 1675
#define KW_BYTE 1682
#define CASE 1684
#define KW_DATE 1686
#define DESC 1687
#define KW_DIVIDE 1688
#define DROP 1691
#define ELSE 1692
#define FROM 1696
#define HOUR 1702
#define INTO 1703
#define LIKE 1706
#define REAL 1715
#define SOME 1720
#define KW_TEXT 1724
#define KW_THEN 1725
#define USER 1726
#define WHEN 1728
#define YEAR 1731
#define KW_DOW 1732
#define XSET 1734
#define ADD 1735
#define ALL 1736
#define KW_AND 1737
#define ANY 1738
#define ASC 1739
#define AVG 1740
#define COLON 1741
#define KW_COMMA 1742
#define DAY 1743
#define DBA 1744
#define KW_FOR 1748
#define XMAX 1753
#define XMIN 1754
#define KW_MINUS 1755
#define KW_MOD 1756
#define KW_NOT 1757
#define KW_SUM 1764
#define ATSIGN 1767
#define KW_PLUS 1768
#define KW_AS 1774
#define KW_BY 1776
#define KW_DOT 1777
#define KW_IN 1780
#define KW_ON 1782
#define KW_OR 1783
#define KW_TO 1784
#define BEFORE 1822
#define END 1826
#define TILDE 1833
#define ILIKE 1834
#define FILLFACTOR 1837
#define TIME 1842
#define KW_TODAY 1849
#define KW_ROWID 1850
#define TIMESTAMP 2198
#define KW_TAG 2219
#define LINTMODULEISLIBRARY 2220
#define KW_PUBLIC 2221
#define KW_PRIVATE 2222
#define COPYBACK 2223
#define REFERENCES_BLOBTYPE_DEFAULT_NULL 2224
#define REFERENCES_BLOBTYPE 2225
#define BEGIN 2226




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
#line 627 "y.tab.h"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE sqlparse_yylval;


