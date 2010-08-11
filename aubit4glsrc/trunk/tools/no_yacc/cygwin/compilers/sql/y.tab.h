/* A Bison parser, made by GNU Bison 2.4.2.  */

/* Skeleton interface for Bison's Yacc-like parsers in C
   
      Copyright (C) 1984, 1989-1990, 2000-2006, 2009-2010 Free Software
   Foundation, Inc.
   
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
     INT_VALUE = 2241,
     NAMED = 2242,
     NAMED_GEN = 2243,
     CHAR_VALUE = 2244,
     NOT_USED_1 = 2245,
     NOT_USED_2 = 2246,
     NOT_USED_3 = 2247,
     NOT_USED_4 = 2248,
     NOT_USED_5 = 2249,
     NOT_USED_6 = 2250,
     NOT_USED_7 = 2251,
     NOT_USED_8 = 2252,
     NUMBER_VALUE = 2253,
     SEMICOLON = 2254,
     QUESTION_MARK = 2255,
     CLINE = 2256,
     CH = 2257,
     MARK_VAR = 2258,
     END_MARK_VAR = 2259,
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
     UIFORM = 1039,
     USING_BTREE = 1055,
     USING_RTREE = 1056,
     SET_BUFFERED_LOG = 1075,
     SET_LOG = 1078,
     MDY = 1080,
     WEEKDAY = 1081,
     MODE_ANSI = 1084,
     START_DATABASE = 1085,
     WITH_LOG_IN = 1086,
     SET_CONSTRAINTS_ALL_IMMEDIATE = 1087,
     DATETIME_VALUE = 1100,
     INTERVAL_VALUE = 1101,
     RECOVER_TABLE = 1102,
     ROLLFORWARD_DATABASE = 1103,
     CONCAT_PIPES = 1117,
     DROP_TRIGGER = 1119,
     DROP_AUDIT_FOR = 1120,
     CREATE_AUDIT_FOR = 1121,
     EXECUTE_PROCEDURE = 1125,
     ALTER_TABLE = 1132,
     ALTER_INDEX = 1133,
     NEXT_SIZE = 1134,
     XSET_MULTIPLY_EQUAL_OPEN_BRACKET = 1171,
     XSET_ident_DOT_MULTIPLY_EQUAL_OPEN_BRACKET = 1172,
     XSET_ident_DOT_MULTIPLY_EQUAL = 1173,
     XSET_MULTIPLY_EQUAL = 1174,
     XSET_OPEN_BRACKET = 1175,
     CREATE_DATABASE = 1178,
     DROP_DATABASE = 1179,
     ADD_CONSTRAINT = 1181,
     DROP_CONSTRAINT = 1182,
     DROP_SYNONYM = 1183,
     CONSTRAINT = 1184,
     NOT_FIELD_TOUCHED_CURRENT = 1187,
     FIELD_TOUCHED_CURRENT = 1188,
     DOUBLE_PRECISION = 1195,
     COUNT_MULTIPLY = 1196,
     MODIFY_NEXT_SIZE = 1216,
     LOCK_MODE_PAGE = 1217,
     LOCK_MODE_ROW = 1218,
     UNITS_YEAR = 1225,
     UNITS_MONTH = 1226,
     UNITS_DAY = 1227,
     UNITS_HOUR = 1228,
     UNITS_MINUTE = 1229,
     UNITS_SECOND = 1230,
     TO_CLUSTER = 1235,
     TO_NOT_CLUSTER = 1236,
     CREATE_UC_IDX = 1238,
     CREATE_U_IDX = 1239,
     CREATE_C_IDX = 1240,
     CREATE_IDX = 1241,
     DOUBLE_COLON = 1251,
     SQLSICS = 1257,
     CREATE_SCHEMA = 1258,
     SQLSIRR = 1259,
     UPDATESTATS_T = 1260,
     SQLSICR = 1261,
     SQLSIDR = 1272,
     CREATE_TEMP_TABLE = 1273,
     WITH_CHECK_OPTION = 1281,
     WITH_GRANT_OPTION = 1282,
     SQLSLMNW = 1283,
     WHERE_CURRENT_OF = 1289,
     NOT_NULL_UNIQUE = 1297,
     SQLSLMW = 1304,
     ALL_PRIVILEGES = 1306,
     CREATE_SYNONYM = 1310,
     DROP_TABLE = 1311,
     INEXCLUSIVE = 1313,
     UPDATESTATS = 1318,
     CREATE_TABLE = 1344,
     DEFAULT_NULL = 1345,
     DEFAULT_TODAY = 1346,
     DEFAULT_USER = 1347,
     EXIT_TODO = 1354,
     CONTINUE_TODO = 1355,
     UNLOCK_TABLE = 1362,
     ROLLBACK_W = 1370,
     SQLSEON = 1372,
     SQLSEOFF = 1373,
     CREATE_VIEW = 1377,
     DELETE_FROM = 1378,
     EXTENT_SIZE = 1385,
     FOREIGN_KEY = 1386,
     INSERT_INTO = 1389,
     IS_NOT_NULL = 1391,
     NOT_MATCHES = 1394,
     PRIMARY_KEY = 1400,
     WITH_NO_LOG = 1407,
     INSHARE = 1410,
     BEGIN_WORK = 1416,
     DROP_INDEX = 1421,
     FOR_UPDATE_OF = 1427,
     FOR_UPDATE = 1428,
     LOCK_TABLE = 1433,
     NOT_EXISTS = 1435,
     REFERENCES = 1437,
     RENCOL = 1438,
     SMALLFLOAT = 1440,
     COMMIT_W = 1451,
     RENTAB = 1458,
     KW_CHAR = 1461,
     NCHAR = 1462,
     NVARCHAR = 1463,
     DELIMITER = 1465,
     DROP_VIEW = 1467,
     EXCLUSIVE = 1470,
     GREATER_THAN_EQ = 1474,
     INTO_TEMP = 1476,
     DATABASE = 1500,
     DATETIME = 1501,
     DISTINCT = 1503,
     FRACTION = 1510,
     GROUP_BY = 1512,
     INTERVAL = 1513,
     NOT_LIKE = 1515,
     NOT_ILIKE = 1516,
     NOT_NULL = 1517,
     RESOURCE = 1523,
     SMALLINT = 1524,
     IS_NULL = 1530,
     LESS_THAN_EQ = 1531,
     BETWEEN = 1533,
     CLOSE_BRACKET = 1536,
     CONNECT = 1539,
     KW_CURRENT = 1540,
     KW_DECIMAL = 1542,
     DEFAULT = 1544,
     INTEGER = 1552,
     SERIAL8 = 1554,
     MATCHES = 1557,
     VARCHAR = 1570,
     CLOSE_SQUARE = 1573,
     GREATER_THAN = 1574,
     KW_FALSE = 1575,
     NOT_IN = 1576,
     OPEN_BRACKET = 1578,
     KW_DELETE = 1586,
     KW_ESCAPE = 1589,
     EXISTS = 1590,
     EXTEND = 1591,
     HAVING = 1595,
     KW_INSERT = 1597,
     MINUTE = 1601,
     MODIFY = 1602,
     EQUAL = 1604,
     NOT_EQUAL = 1605,
     OPEN_SQUARE = 1607,
     PUBLIC = 1611,
     KW_RETURN_KEY = 1614,
     REVOKE = 1616,
     SECOND = 1620,
     KW_SELECT = 1624,
     SERIAL = 1625,
     UNIQUE = 1628,
     KW_UPDATE = 1630,
     VALUES = 1631,
     KW_NULL = 1634,
     KW_TRUE = 1635,
     ALTER = 1637,
     CHECK = 1643,
     COUNT = 1647,
     KW_FIRST = 1652,
     KW_FLOAT = 1653,
     GRANT = 1656,
     INDEX = 1659,
     LESS_THAN = 1662,
     MONEY = 1664,
     MONTH = 1665,
     KW_MULTIPLY = 1667,
     ORDER = 1668,
     OUTER = 1669,
     UNION = 1678,
     WHERE = 1681,
     KW_BYTE = 1688,
     CASE = 1690,
     KW_DATE = 1692,
     DESC = 1693,
     KW_DIVIDE = 1694,
     DROP = 1697,
     ELSE = 1698,
     FROM = 1702,
     HOUR = 1708,
     INTO = 1709,
     LIKE = 1712,
     REAL = 1721,
     SOME = 1726,
     KW_TEXT = 1730,
     KW_THEN = 1731,
     USER = 1732,
     WHEN = 1734,
     YEAR = 1737,
     KW_DOW = 1738,
     XSET = 1740,
     ADD = 1741,
     ALL = 1742,
     KW_AND = 1743,
     ANY = 1744,
     ASC = 1745,
     AVG = 1746,
     COLON = 1747,
     KW_COMMA = 1748,
     DAY = 1749,
     DBA = 1750,
     KW_FOR = 1754,
     XMAX = 1759,
     XMIN = 1760,
     KW_MINUS = 1761,
     KW_MOD = 1762,
     KW_NOT = 1763,
     KW_SUM = 1770,
     ATSIGN = 1773,
     KW_PLUS = 1774,
     KW_AS = 1780,
     KW_BY = 1782,
     KW_DOT = 1783,
     KW_IN = 1786,
     KW_ON = 1788,
     KW_OR = 1789,
     KW_TO = 1790,
     BEFORE = 1828,
     END = 1832,
     TILDE = 1839,
     ILIKE = 1840,
     FILLFACTOR = 1843,
     TIME = 1848,
     KW_TODAY = 1855,
     KW_ROWID = 1856,
     TIMESTAMP = 2204,
     SET_TEXT_FORMAT = 2216,
     KW_TAG = 2226,
     LINTMODULEISLIBRARY = 2227,
     KW_PUBLIC = 2228,
     KW_PRIVATE = 2229,
     COPYBACK = 2230,
     REFERENCES_BLOBTYPE_DEFAULT_NULL = 2231,
     REFERENCES_BLOBTYPE = 2232,
     SORT = 2233,
     KWPIPE = 2234,
     KW_DONE = 2235,
     END_TODO = 2236,
     KW_TODO = 2237,
     KW_ALWAYS = 2238,
     PROGRAM_TIMEOUT = 2239
   };
#endif
/* Tokens.  */
#define INT_VALUE 2241
#define NAMED 2242
#define NAMED_GEN 2243
#define CHAR_VALUE 2244
#define NOT_USED_1 2245
#define NOT_USED_2 2246
#define NOT_USED_3 2247
#define NOT_USED_4 2248
#define NOT_USED_5 2249
#define NOT_USED_6 2250
#define NOT_USED_7 2251
#define NOT_USED_8 2252
#define NUMBER_VALUE 2253
#define SEMICOLON 2254
#define QUESTION_MARK 2255
#define CLINE 2256
#define CH 2257
#define MARK_VAR 2258
#define END_MARK_VAR 2259
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
#define UIFORM 1039
#define USING_BTREE 1055
#define USING_RTREE 1056
#define SET_BUFFERED_LOG 1075
#define SET_LOG 1078
#define MDY 1080
#define WEEKDAY 1081
#define MODE_ANSI 1084
#define START_DATABASE 1085
#define WITH_LOG_IN 1086
#define SET_CONSTRAINTS_ALL_IMMEDIATE 1087
#define DATETIME_VALUE 1100
#define INTERVAL_VALUE 1101
#define RECOVER_TABLE 1102
#define ROLLFORWARD_DATABASE 1103
#define CONCAT_PIPES 1117
#define DROP_TRIGGER 1119
#define DROP_AUDIT_FOR 1120
#define CREATE_AUDIT_FOR 1121
#define EXECUTE_PROCEDURE 1125
#define ALTER_TABLE 1132
#define ALTER_INDEX 1133
#define NEXT_SIZE 1134
#define XSET_MULTIPLY_EQUAL_OPEN_BRACKET 1171
#define XSET_ident_DOT_MULTIPLY_EQUAL_OPEN_BRACKET 1172
#define XSET_ident_DOT_MULTIPLY_EQUAL 1173
#define XSET_MULTIPLY_EQUAL 1174
#define XSET_OPEN_BRACKET 1175
#define CREATE_DATABASE 1178
#define DROP_DATABASE 1179
#define ADD_CONSTRAINT 1181
#define DROP_CONSTRAINT 1182
#define DROP_SYNONYM 1183
#define CONSTRAINT 1184
#define NOT_FIELD_TOUCHED_CURRENT 1187
#define FIELD_TOUCHED_CURRENT 1188
#define DOUBLE_PRECISION 1195
#define COUNT_MULTIPLY 1196
#define MODIFY_NEXT_SIZE 1216
#define LOCK_MODE_PAGE 1217
#define LOCK_MODE_ROW 1218
#define UNITS_YEAR 1225
#define UNITS_MONTH 1226
#define UNITS_DAY 1227
#define UNITS_HOUR 1228
#define UNITS_MINUTE 1229
#define UNITS_SECOND 1230
#define TO_CLUSTER 1235
#define TO_NOT_CLUSTER 1236
#define CREATE_UC_IDX 1238
#define CREATE_U_IDX 1239
#define CREATE_C_IDX 1240
#define CREATE_IDX 1241
#define DOUBLE_COLON 1251
#define SQLSICS 1257
#define CREATE_SCHEMA 1258
#define SQLSIRR 1259
#define UPDATESTATS_T 1260
#define SQLSICR 1261
#define SQLSIDR 1272
#define CREATE_TEMP_TABLE 1273
#define WITH_CHECK_OPTION 1281
#define WITH_GRANT_OPTION 1282
#define SQLSLMNW 1283
#define WHERE_CURRENT_OF 1289
#define NOT_NULL_UNIQUE 1297
#define SQLSLMW 1304
#define ALL_PRIVILEGES 1306
#define CREATE_SYNONYM 1310
#define DROP_TABLE 1311
#define INEXCLUSIVE 1313
#define UPDATESTATS 1318
#define CREATE_TABLE 1344
#define DEFAULT_NULL 1345
#define DEFAULT_TODAY 1346
#define DEFAULT_USER 1347
#define EXIT_TODO 1354
#define CONTINUE_TODO 1355
#define UNLOCK_TABLE 1362
#define ROLLBACK_W 1370
#define SQLSEON 1372
#define SQLSEOFF 1373
#define CREATE_VIEW 1377
#define DELETE_FROM 1378
#define EXTENT_SIZE 1385
#define FOREIGN_KEY 1386
#define INSERT_INTO 1389
#define IS_NOT_NULL 1391
#define NOT_MATCHES 1394
#define PRIMARY_KEY 1400
#define WITH_NO_LOG 1407
#define INSHARE 1410
#define BEGIN_WORK 1416
#define DROP_INDEX 1421
#define FOR_UPDATE_OF 1427
#define FOR_UPDATE 1428
#define LOCK_TABLE 1433
#define NOT_EXISTS 1435
#define REFERENCES 1437
#define RENCOL 1438
#define SMALLFLOAT 1440
#define COMMIT_W 1451
#define RENTAB 1458
#define KW_CHAR 1461
#define NCHAR 1462
#define NVARCHAR 1463
#define DELIMITER 1465
#define DROP_VIEW 1467
#define EXCLUSIVE 1470
#define GREATER_THAN_EQ 1474
#define INTO_TEMP 1476
#define DATABASE 1500
#define DATETIME 1501
#define DISTINCT 1503
#define FRACTION 1510
#define GROUP_BY 1512
#define INTERVAL 1513
#define NOT_LIKE 1515
#define NOT_ILIKE 1516
#define NOT_NULL 1517
#define RESOURCE 1523
#define SMALLINT 1524
#define IS_NULL 1530
#define LESS_THAN_EQ 1531
#define BETWEEN 1533
#define CLOSE_BRACKET 1536
#define CONNECT 1539
#define KW_CURRENT 1540
#define KW_DECIMAL 1542
#define DEFAULT 1544
#define INTEGER 1552
#define SERIAL8 1554
#define MATCHES 1557
#define VARCHAR 1570
#define CLOSE_SQUARE 1573
#define GREATER_THAN 1574
#define KW_FALSE 1575
#define NOT_IN 1576
#define OPEN_BRACKET 1578
#define KW_DELETE 1586
#define KW_ESCAPE 1589
#define EXISTS 1590
#define EXTEND 1591
#define HAVING 1595
#define KW_INSERT 1597
#define MINUTE 1601
#define MODIFY 1602
#define EQUAL 1604
#define NOT_EQUAL 1605
#define OPEN_SQUARE 1607
#define PUBLIC 1611
#define KW_RETURN_KEY 1614
#define REVOKE 1616
#define SECOND 1620
#define KW_SELECT 1624
#define SERIAL 1625
#define UNIQUE 1628
#define KW_UPDATE 1630
#define VALUES 1631
#define KW_NULL 1634
#define KW_TRUE 1635
#define ALTER 1637
#define CHECK 1643
#define COUNT 1647
#define KW_FIRST 1652
#define KW_FLOAT 1653
#define GRANT 1656
#define INDEX 1659
#define LESS_THAN 1662
#define MONEY 1664
#define MONTH 1665
#define KW_MULTIPLY 1667
#define ORDER 1668
#define OUTER 1669
#define UNION 1678
#define WHERE 1681
#define KW_BYTE 1688
#define CASE 1690
#define KW_DATE 1692
#define DESC 1693
#define KW_DIVIDE 1694
#define DROP 1697
#define ELSE 1698
#define FROM 1702
#define HOUR 1708
#define INTO 1709
#define LIKE 1712
#define REAL 1721
#define SOME 1726
#define KW_TEXT 1730
#define KW_THEN 1731
#define USER 1732
#define WHEN 1734
#define YEAR 1737
#define KW_DOW 1738
#define XSET 1740
#define ADD 1741
#define ALL 1742
#define KW_AND 1743
#define ANY 1744
#define ASC 1745
#define AVG 1746
#define COLON 1747
#define KW_COMMA 1748
#define DAY 1749
#define DBA 1750
#define KW_FOR 1754
#define XMAX 1759
#define XMIN 1760
#define KW_MINUS 1761
#define KW_MOD 1762
#define KW_NOT 1763
#define KW_SUM 1770
#define ATSIGN 1773
#define KW_PLUS 1774
#define KW_AS 1780
#define KW_BY 1782
#define KW_DOT 1783
#define KW_IN 1786
#define KW_ON 1788
#define KW_OR 1789
#define KW_TO 1790
#define BEFORE 1828
#define END 1832
#define TILDE 1839
#define ILIKE 1840
#define FILLFACTOR 1843
#define TIME 1848
#define KW_TODAY 1855
#define KW_ROWID 1856
#define TIMESTAMP 2204
#define SET_TEXT_FORMAT 2216
#define KW_TAG 2226
#define LINTMODULEISLIBRARY 2227
#define KW_PUBLIC 2228
#define KW_PRIVATE 2229
#define COPYBACK 2230
#define REFERENCES_BLOBTYPE_DEFAULT_NULL 2231
#define REFERENCES_BLOBTYPE 2232
#define SORT 2233
#define KWPIPE 2234
#define KW_DONE 2235
#define END_TODO 2236
#define KW_TODO 2237
#define KW_ALWAYS 2238
#define PROGRAM_TIMEOUT 2239




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
#line 654 "y.tab.h"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE sqlparse_yylval;


