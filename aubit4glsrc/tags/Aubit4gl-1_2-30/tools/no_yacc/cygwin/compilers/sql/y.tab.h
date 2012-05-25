/* A Bison parser, made by GNU Bison 2.4.3.  */

/* Skeleton interface for Bison's Yacc-like parsers in C
   
      Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006,
   2009, 2010 Free Software Foundation, Inc.
   
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
     INT_VALUE = 2245,
     NAMED = 2246,
     NAMED_GEN = 2247,
     CHAR_VALUE = 2248,
     NOT_USED_1 = 2249,
     NOT_USED_2 = 2250,
     NOT_USED_3 = 2251,
     NOT_USED_4 = 2252,
     NOT_USED_5 = 2253,
     NOT_USED_6 = 2254,
     NOT_USED_7 = 2255,
     NOT_USED_8 = 2256,
     NUMBER_VALUE = 2257,
     SEMICOLON = 2258,
     QUESTION_MARK = 2259,
     CLINE = 2260,
     CH = 2261,
     MARK_VAR = 2262,
     END_MARK_VAR = 2263,
     WITH_LISTING_IN = 1001,
     SET_POSTGRESQL_SEARCH_PATH = 1002,
     SET_CONSTRAINTS_ALL_DEFERRED = 1003,
     KW_LIMIT = 1004,
     DOCUMENT = 1005,
     ON_EXCEPTION = 1007,
     SET_DEBUG_FILE_TO = 1008,
     CREATE_DBA_PROCEDURE = 1013,
     CREATE_FUNCTION = 1014,
     CREATE_DBA_FUNCTION = 1015,
     USE_SESSION = 1017,
     KW_RUN_CLIENT = 1018,
     LEFT_JOIN = 1020,
     IGNORE_ERRORS = 1023,
     SQLERRMESSAGE = 1024,
     DISPLAY_NULL_TO = 1025,
     UNBUFFERED = 1026,
     KW_PICTURE = 1027,
     ON_CHANGE = 1028,
     INNER_JOIN = 1029,
     UI_INTERFACE_DOT_FRONTCALL = 1032,
     UICOMBOBOX = 1036,
     UIBROWSER = 1037,
     UIFORM = 1040,
     USING_BTREE = 1056,
     USING_RTREE = 1057,
     SET_BUFFERED_LOG = 1076,
     SET_LOG = 1079,
     MDY = 1081,
     WEEKDAY = 1082,
     MODE_ANSI = 1085,
     START_DATABASE = 1086,
     WITH_LOG_IN = 1087,
     SET_CONSTRAINTS_ALL_IMMEDIATE = 1088,
     DATETIME_VALUE = 1101,
     INTERVAL_VALUE = 1102,
     RECOVER_TABLE = 1103,
     ROLLFORWARD_DATABASE = 1104,
     CONCAT_PIPES = 1118,
     DROP_TRIGGER = 1120,
     DROP_AUDIT_FOR = 1121,
     CREATE_AUDIT_FOR = 1122,
     EXECUTE_PROCEDURE = 1126,
     ALTER_TABLE = 1133,
     ALTER_INDEX = 1134,
     NEXT_SIZE = 1135,
     KW_WHENEVER_SIGNAL = 1172,
     KW_SIGNAL_TOKEN = 1173,
     XSET_MULTIPLY_EQUAL_OPEN_BRACKET = 1174,
     XSET_ident_DOT_MULTIPLY_EQUAL_OPEN_BRACKET = 1175,
     XSET_ident_DOT_MULTIPLY_EQUAL = 1176,
     XSET_MULTIPLY_EQUAL = 1177,
     XSET_OPEN_BRACKET = 1178,
     CREATE_DATABASE = 1181,
     DROP_DATABASE = 1182,
     ADD_CONSTRAINT = 1184,
     DROP_CONSTRAINT = 1185,
     DROP_SYNONYM = 1186,
     CONSTRAINT = 1187,
     NOT_FIELD_TOUCHED_CURRENT = 1190,
     FIELD_TOUCHED_CURRENT = 1191,
     OBJECT_FUNCTION = 1193,
     DOUBLE_PRECISION = 1199,
     COUNT_MULTIPLY = 1200,
     KW_ASCII_OPEN_BRACKET = 1209,
     MODIFY_NEXT_SIZE = 1221,
     LOCK_MODE_PAGE = 1222,
     LOCK_MODE_ROW = 1223,
     TO_UI = 1228,
     UNITS_YEAR = 1231,
     UNITS_MONTH = 1232,
     UNITS_DAY = 1233,
     UNITS_HOUR = 1234,
     UNITS_MINUTE = 1235,
     UNITS_SECOND = 1236,
     TO_CLUSTER = 1241,
     TO_NOT_CLUSTER = 1242,
     CREATE_UC_IDX = 1244,
     CREATE_U_IDX = 1245,
     CREATE_C_IDX = 1246,
     CREATE_IDX = 1247,
     DOUBLE_COLON = 1257,
     SQLSICS = 1263,
     CREATE_SCHEMA = 1264,
     SQLSIRR = 1265,
     UPDATESTATS_T = 1266,
     SQLSICR = 1267,
     SQLSIDR = 1278,
     CREATE_TEMP_TABLE = 1279,
     WITH_CHECK_OPTION = 1287,
     WITH_GRANT_OPTION = 1288,
     SQLSLMNW = 1289,
     WHERE_CURRENT_OF = 1295,
     NOT_NULL_UNIQUE = 1303,
     SQLSLMW = 1310,
     ALL_PRIVILEGES = 1312,
     CREATE_SYNONYM = 1316,
     DROP_TABLE = 1317,
     INEXCLUSIVE = 1319,
     REPORT_TO_FILE = 1320,
     REPORT_TO_UI = 1321,
     UPDATESTATS = 1326,
     CREATE_TABLE = 1352,
     DEFAULT_NULL = 1353,
     DEFAULT_TODAY = 1354,
     DEFAULT_USER = 1355,
     EXIT_TODO = 1362,
     CONTINUE_TODO = 1363,
     UNLOCK_TABLE = 1370,
     ROLLBACK_W = 1378,
     SQLSEON = 1380,
     SQLSEOFF = 1381,
     CREATE_VIEW = 1385,
     DELETE_FROM = 1386,
     EXTENT_SIZE = 1393,
     FOREIGN_KEY = 1394,
     INSERT_INTO = 1397,
     IS_NOT_NULL = 1399,
     NOT_MATCHES = 1402,
     PRIMARY_KEY = 1408,
     WITH_NO_LOG = 1415,
     INSHARE = 1418,
     BEGIN_WORK = 1424,
     DROP_INDEX = 1429,
     FOR_UPDATE_OF = 1435,
     FOR_UPDATE = 1436,
     LOCK_TABLE = 1441,
     NOT_EXISTS = 1443,
     REFERENCES = 1445,
     RENCOL = 1446,
     SMALLFLOAT = 1448,
     COMMIT_W = 1459,
     RENTAB = 1466,
     KW_CHAR = 1469,
     NCHAR = 1470,
     NVARCHAR = 1471,
     DELIMITER = 1473,
     DROP_VIEW = 1475,
     EXCLUSIVE = 1478,
     GREATER_THAN_EQ = 1482,
     INTO_TEMP = 1484,
     DATABASE = 1508,
     DATETIME = 1509,
     DISTINCT = 1511,
     FRACTION = 1518,
     GROUP_BY = 1520,
     INTERVAL = 1521,
     NOT_LIKE = 1523,
     NOT_ILIKE = 1524,
     NOT_NULL = 1525,
     RESOURCE = 1531,
     SMALLINT = 1532,
     IS_NULL = 1538,
     LESS_THAN_EQ = 1539,
     BETWEEN = 1541,
     CLOSE_BRACKET = 1544,
     CONNECT = 1547,
     KW_CURRENT = 1548,
     KW_DECIMAL = 1550,
     KW_DEFAULT = 1552,
     INTEGER = 1560,
     SERIAL8 = 1562,
     MATCHES = 1565,
     VARCHAR = 1578,
     CLOSE_SQUARE = 1581,
     GREATER_THAN = 1582,
     KW_FALSE = 1583,
     NOT_IN = 1584,
     OPEN_BRACKET_SELECT = 1586,
     OPEN_BRACKET = 1587,
     KW_DELETE = 1595,
     KW_ESCAPE = 1598,
     EXISTS = 1599,
     EXTEND = 1600,
     HAVING = 1604,
     KW_INSERT = 1606,
     MINUTE = 1610,
     MODIFY = 1611,
     EQUAL = 1613,
     NOT_EQUAL = 1614,
     OPEN_SQUARE = 1616,
     PUBLIC = 1620,
     KW_RETURN_KEY = 1623,
     REVOKE = 1625,
     SECOND = 1629,
     KW_SELECT = 1633,
     SERIAL = 1634,
     UNIQUE = 1637,
     KW_UPDATE = 1639,
     VALUES = 1640,
     KW_NULL = 1643,
     KW_TRUE = 1644,
     ALTER = 1646,
     CHECK = 1652,
     COUNT = 1656,
     KW_FIRST = 1661,
     KW_FLOAT = 1662,
     GRANT = 1665,
     INDEX = 1668,
     LESS_THAN = 1671,
     MONEY = 1673,
     MONTH = 1674,
     KW_MULTIPLY = 1676,
     ORDER = 1677,
     OUTER = 1678,
     UNION = 1687,
     WHERE = 1690,
     KW_BYTE = 1697,
     CASE = 1699,
     KW_DATE = 1701,
     DESC = 1702,
     KW_DIVIDE = 1703,
     DROP = 1706,
     ELSE = 1707,
     FROM = 1711,
     HOUR = 1717,
     INTO = 1718,
     LIKE = 1721,
     REAL = 1730,
     SOME = 1735,
     KW_TEXT = 1739,
     KW_THEN = 1740,
     USER = 1741,
     WHEN = 1743,
     YEAR = 1746,
     KW_DOW = 1747,
     XSET = 1749,
     ADD = 1750,
     ALL = 1751,
     KW_AND = 1752,
     ANY = 1753,
     ASC = 1754,
     AVG = 1755,
     COLON = 1756,
     KW_COMMA = 1757,
     DAY = 1758,
     DBA = 1759,
     KW_FOR = 1763,
     XMAX = 1768,
     XMIN = 1769,
     KW_MINUS = 1770,
     KW_MOD = 1771,
     KW_NOT = 1772,
     KW_SUM = 1779,
     ATSIGN = 1782,
     KW_PLUS = 1783,
     KW_AS = 1789,
     KW_BY = 1791,
     KW_DOT = 1792,
     KW_IN = 1795,
     KW_ON = 1797,
     KW_OR = 1798,
     KW_TO = 1799,
     BEFORE = 1837,
     END = 1841,
     TILDE = 1848,
     ILIKE = 1849,
     FILLFACTOR = 1852,
     TIME = 1857,
     KW_TODAY = 1864,
     KW_ROWID = 1865,
     TIMESTAMP = 2213,
     KWPIPE = 2243
   };
#endif
/* Tokens.  */
#define INT_VALUE 2245
#define NAMED 2246
#define NAMED_GEN 2247
#define CHAR_VALUE 2248
#define NOT_USED_1 2249
#define NOT_USED_2 2250
#define NOT_USED_3 2251
#define NOT_USED_4 2252
#define NOT_USED_5 2253
#define NOT_USED_6 2254
#define NOT_USED_7 2255
#define NOT_USED_8 2256
#define NUMBER_VALUE 2257
#define SEMICOLON 2258
#define QUESTION_MARK 2259
#define CLINE 2260
#define CH 2261
#define MARK_VAR 2262
#define END_MARK_VAR 2263
#define WITH_LISTING_IN 1001
#define SET_POSTGRESQL_SEARCH_PATH 1002
#define SET_CONSTRAINTS_ALL_DEFERRED 1003
#define KW_LIMIT 1004
#define DOCUMENT 1005
#define ON_EXCEPTION 1007
#define SET_DEBUG_FILE_TO 1008
#define CREATE_DBA_PROCEDURE 1013
#define CREATE_FUNCTION 1014
#define CREATE_DBA_FUNCTION 1015
#define USE_SESSION 1017
#define KW_RUN_CLIENT 1018
#define LEFT_JOIN 1020
#define IGNORE_ERRORS 1023
#define SQLERRMESSAGE 1024
#define DISPLAY_NULL_TO 1025
#define UNBUFFERED 1026
#define KW_PICTURE 1027
#define ON_CHANGE 1028
#define INNER_JOIN 1029
#define UI_INTERFACE_DOT_FRONTCALL 1032
#define UICOMBOBOX 1036
#define UIBROWSER 1037
#define UIFORM 1040
#define USING_BTREE 1056
#define USING_RTREE 1057
#define SET_BUFFERED_LOG 1076
#define SET_LOG 1079
#define MDY 1081
#define WEEKDAY 1082
#define MODE_ANSI 1085
#define START_DATABASE 1086
#define WITH_LOG_IN 1087
#define SET_CONSTRAINTS_ALL_IMMEDIATE 1088
#define DATETIME_VALUE 1101
#define INTERVAL_VALUE 1102
#define RECOVER_TABLE 1103
#define ROLLFORWARD_DATABASE 1104
#define CONCAT_PIPES 1118
#define DROP_TRIGGER 1120
#define DROP_AUDIT_FOR 1121
#define CREATE_AUDIT_FOR 1122
#define EXECUTE_PROCEDURE 1126
#define ALTER_TABLE 1133
#define ALTER_INDEX 1134
#define NEXT_SIZE 1135
#define KW_WHENEVER_SIGNAL 1172
#define KW_SIGNAL_TOKEN 1173
#define XSET_MULTIPLY_EQUAL_OPEN_BRACKET 1174
#define XSET_ident_DOT_MULTIPLY_EQUAL_OPEN_BRACKET 1175
#define XSET_ident_DOT_MULTIPLY_EQUAL 1176
#define XSET_MULTIPLY_EQUAL 1177
#define XSET_OPEN_BRACKET 1178
#define CREATE_DATABASE 1181
#define DROP_DATABASE 1182
#define ADD_CONSTRAINT 1184
#define DROP_CONSTRAINT 1185
#define DROP_SYNONYM 1186
#define CONSTRAINT 1187
#define NOT_FIELD_TOUCHED_CURRENT 1190
#define FIELD_TOUCHED_CURRENT 1191
#define OBJECT_FUNCTION 1193
#define DOUBLE_PRECISION 1199
#define COUNT_MULTIPLY 1200
#define KW_ASCII_OPEN_BRACKET 1209
#define MODIFY_NEXT_SIZE 1221
#define LOCK_MODE_PAGE 1222
#define LOCK_MODE_ROW 1223
#define TO_UI 1228
#define UNITS_YEAR 1231
#define UNITS_MONTH 1232
#define UNITS_DAY 1233
#define UNITS_HOUR 1234
#define UNITS_MINUTE 1235
#define UNITS_SECOND 1236
#define TO_CLUSTER 1241
#define TO_NOT_CLUSTER 1242
#define CREATE_UC_IDX 1244
#define CREATE_U_IDX 1245
#define CREATE_C_IDX 1246
#define CREATE_IDX 1247
#define DOUBLE_COLON 1257
#define SQLSICS 1263
#define CREATE_SCHEMA 1264
#define SQLSIRR 1265
#define UPDATESTATS_T 1266
#define SQLSICR 1267
#define SQLSIDR 1278
#define CREATE_TEMP_TABLE 1279
#define WITH_CHECK_OPTION 1287
#define WITH_GRANT_OPTION 1288
#define SQLSLMNW 1289
#define WHERE_CURRENT_OF 1295
#define NOT_NULL_UNIQUE 1303
#define SQLSLMW 1310
#define ALL_PRIVILEGES 1312
#define CREATE_SYNONYM 1316
#define DROP_TABLE 1317
#define INEXCLUSIVE 1319
#define REPORT_TO_FILE 1320
#define REPORT_TO_UI 1321
#define UPDATESTATS 1326
#define CREATE_TABLE 1352
#define DEFAULT_NULL 1353
#define DEFAULT_TODAY 1354
#define DEFAULT_USER 1355
#define EXIT_TODO 1362
#define CONTINUE_TODO 1363
#define UNLOCK_TABLE 1370
#define ROLLBACK_W 1378
#define SQLSEON 1380
#define SQLSEOFF 1381
#define CREATE_VIEW 1385
#define DELETE_FROM 1386
#define EXTENT_SIZE 1393
#define FOREIGN_KEY 1394
#define INSERT_INTO 1397
#define IS_NOT_NULL 1399
#define NOT_MATCHES 1402
#define PRIMARY_KEY 1408
#define WITH_NO_LOG 1415
#define INSHARE 1418
#define BEGIN_WORK 1424
#define DROP_INDEX 1429
#define FOR_UPDATE_OF 1435
#define FOR_UPDATE 1436
#define LOCK_TABLE 1441
#define NOT_EXISTS 1443
#define REFERENCES 1445
#define RENCOL 1446
#define SMALLFLOAT 1448
#define COMMIT_W 1459
#define RENTAB 1466
#define KW_CHAR 1469
#define NCHAR 1470
#define NVARCHAR 1471
#define DELIMITER 1473
#define DROP_VIEW 1475
#define EXCLUSIVE 1478
#define GREATER_THAN_EQ 1482
#define INTO_TEMP 1484
#define DATABASE 1508
#define DATETIME 1509
#define DISTINCT 1511
#define FRACTION 1518
#define GROUP_BY 1520
#define INTERVAL 1521
#define NOT_LIKE 1523
#define NOT_ILIKE 1524
#define NOT_NULL 1525
#define RESOURCE 1531
#define SMALLINT 1532
#define IS_NULL 1538
#define LESS_THAN_EQ 1539
#define BETWEEN 1541
#define CLOSE_BRACKET 1544
#define CONNECT 1547
#define KW_CURRENT 1548
#define KW_DECIMAL 1550
#define KW_DEFAULT 1552
#define INTEGER 1560
#define SERIAL8 1562
#define MATCHES 1565
#define VARCHAR 1578
#define CLOSE_SQUARE 1581
#define GREATER_THAN 1582
#define KW_FALSE 1583
#define NOT_IN 1584
#define OPEN_BRACKET_SELECT 1586
#define OPEN_BRACKET 1587
#define KW_DELETE 1595
#define KW_ESCAPE 1598
#define EXISTS 1599
#define EXTEND 1600
#define HAVING 1604
#define KW_INSERT 1606
#define MINUTE 1610
#define MODIFY 1611
#define EQUAL 1613
#define NOT_EQUAL 1614
#define OPEN_SQUARE 1616
#define PUBLIC 1620
#define KW_RETURN_KEY 1623
#define REVOKE 1625
#define SECOND 1629
#define KW_SELECT 1633
#define SERIAL 1634
#define UNIQUE 1637
#define KW_UPDATE 1639
#define VALUES 1640
#define KW_NULL 1643
#define KW_TRUE 1644
#define ALTER 1646
#define CHECK 1652
#define COUNT 1656
#define KW_FIRST 1661
#define KW_FLOAT 1662
#define GRANT 1665
#define INDEX 1668
#define LESS_THAN 1671
#define MONEY 1673
#define MONTH 1674
#define KW_MULTIPLY 1676
#define ORDER 1677
#define OUTER 1678
#define UNION 1687
#define WHERE 1690
#define KW_BYTE 1697
#define CASE 1699
#define KW_DATE 1701
#define DESC 1702
#define KW_DIVIDE 1703
#define DROP 1706
#define ELSE 1707
#define FROM 1711
#define HOUR 1717
#define INTO 1718
#define LIKE 1721
#define REAL 1730
#define SOME 1735
#define KW_TEXT 1739
#define KW_THEN 1740
#define USER 1741
#define WHEN 1743
#define YEAR 1746
#define KW_DOW 1747
#define XSET 1749
#define ADD 1750
#define ALL 1751
#define KW_AND 1752
#define ANY 1753
#define ASC 1754
#define AVG 1755
#define COLON 1756
#define KW_COMMA 1757
#define DAY 1758
#define DBA 1759
#define KW_FOR 1763
#define XMAX 1768
#define XMIN 1769
#define KW_MINUS 1770
#define KW_MOD 1771
#define KW_NOT 1772
#define KW_SUM 1779
#define ATSIGN 1782
#define KW_PLUS 1783
#define KW_AS 1789
#define KW_BY 1791
#define KW_DOT 1792
#define KW_IN 1795
#define KW_ON 1797
#define KW_OR 1798
#define KW_TO 1799
#define BEFORE 1837
#define END 1841
#define TILDE 1848
#define ILIKE 1849
#define FILLFACTOR 1852
#define TIME 1857
#define KW_TODAY 1864
#define KW_ROWID 1865
#define TIMESTAMP 2213
#define KWPIPE 2243




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 1685 of yacc.c  */
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





/* Line 1685 of yacc.c  */
#line 644 "y.tab.h"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE sqlparse_yylval;


