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
     INT_VALUE = 2240,
     NAMED = 2241,
     NAMED_GEN = 2242,
     CHAR_VALUE = 2243,
     NOT_USED_1 = 2244,
     NOT_USED_2 = 2245,
     NOT_USED_3 = 2246,
     NOT_USED_4 = 2247,
     NOT_USED_5 = 2248,
     NOT_USED_6 = 2249,
     NOT_USED_7 = 2250,
     NOT_USED_8 = 2251,
     NUMBER_VALUE = 2252,
     SEMICOLON = 2253,
     QUESTION_MARK = 2254,
     CLINE = 2255,
     CH = 2256,
     MARK_VAR = 2257,
     END_MARK_VAR = 2258,
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
     EXIT_TODO = 1353,
     CONTINUE_TODO = 1354,
     UNLOCK_TABLE = 1361,
     ROLLBACK_W = 1369,
     SQLSEON = 1371,
     SQLSEOFF = 1372,
     CREATE_VIEW = 1376,
     DELETE_FROM = 1377,
     EXTENT_SIZE = 1384,
     FOREIGN_KEY = 1385,
     INSERT_INTO = 1388,
     IS_NOT_NULL = 1390,
     NOT_MATCHES = 1393,
     PRIMARY_KEY = 1399,
     WITH_NO_LOG = 1406,
     INSHARE = 1409,
     BEGIN_WORK = 1415,
     DROP_INDEX = 1420,
     FOR_UPDATE_OF = 1426,
     FOR_UPDATE = 1427,
     LOCK_TABLE = 1432,
     NOT_EXISTS = 1434,
     REFERENCES = 1436,
     RENCOL = 1437,
     SMALLFLOAT = 1439,
     COMMIT_W = 1450,
     RENTAB = 1457,
     KW_CHAR = 1460,
     NCHAR = 1461,
     NVARCHAR = 1462,
     DELIMITER = 1464,
     DROP_VIEW = 1466,
     EXCLUSIVE = 1469,
     GREATER_THAN_EQ = 1473,
     INTO_TEMP = 1475,
     DATABASE = 1499,
     DATETIME = 1500,
     DISTINCT = 1502,
     FRACTION = 1509,
     GROUP_BY = 1511,
     INTERVAL = 1512,
     NOT_LIKE = 1514,
     NOT_ILIKE = 1515,
     NOT_NULL = 1516,
     RESOURCE = 1522,
     SMALLINT = 1523,
     IS_NULL = 1529,
     LESS_THAN_EQ = 1530,
     BETWEEN = 1532,
     CLOSE_BRACKET = 1535,
     CONNECT = 1538,
     KW_CURRENT = 1539,
     KW_DECIMAL = 1541,
     DEFAULT = 1543,
     INTEGER = 1551,
     SERIAL8 = 1553,
     MATCHES = 1556,
     VARCHAR = 1569,
     CLOSE_SQUARE = 1572,
     GREATER_THAN = 1573,
     KW_FALSE = 1574,
     NOT_IN = 1575,
     OPEN_BRACKET = 1577,
     KW_DELETE = 1585,
     KW_ESCAPE = 1588,
     EXISTS = 1589,
     EXTEND = 1590,
     HAVING = 1594,
     KW_INSERT = 1596,
     MINUTE = 1600,
     MODIFY = 1601,
     EQUAL = 1603,
     NOT_EQUAL = 1604,
     OPEN_SQUARE = 1606,
     PUBLIC = 1610,
     KW_RETURN_KEY = 1613,
     REVOKE = 1615,
     SECOND = 1619,
     KW_SELECT = 1623,
     SERIAL = 1624,
     UNIQUE = 1627,
     KW_UPDATE = 1629,
     VALUES = 1630,
     KW_NULL = 1633,
     KW_TRUE = 1634,
     ALTER = 1636,
     CHECK = 1642,
     COUNT = 1646,
     KW_FIRST = 1651,
     KW_FLOAT = 1652,
     GRANT = 1655,
     INDEX = 1658,
     LESS_THAN = 1661,
     MONEY = 1663,
     MONTH = 1664,
     KW_MULTIPLY = 1666,
     ORDER = 1667,
     OUTER = 1668,
     UNION = 1677,
     WHERE = 1680,
     KW_BYTE = 1687,
     CASE = 1689,
     KW_DATE = 1691,
     DESC = 1692,
     KW_DIVIDE = 1693,
     DROP = 1696,
     ELSE = 1697,
     FROM = 1701,
     HOUR = 1707,
     INTO = 1708,
     LIKE = 1711,
     REAL = 1720,
     SOME = 1725,
     KW_TEXT = 1729,
     KW_THEN = 1730,
     USER = 1731,
     WHEN = 1733,
     YEAR = 1736,
     KW_DOW = 1737,
     XSET = 1739,
     ADD = 1740,
     ALL = 1741,
     KW_AND = 1742,
     ANY = 1743,
     ASC = 1744,
     AVG = 1745,
     COLON = 1746,
     KW_COMMA = 1747,
     DAY = 1748,
     DBA = 1749,
     KW_FOR = 1753,
     XMAX = 1758,
     XMIN = 1759,
     KW_MINUS = 1760,
     KW_MOD = 1761,
     KW_NOT = 1762,
     KW_SUM = 1769,
     ATSIGN = 1772,
     KW_PLUS = 1773,
     KW_AS = 1779,
     KW_BY = 1781,
     KW_DOT = 1782,
     KW_IN = 1785,
     KW_ON = 1787,
     KW_OR = 1788,
     KW_TO = 1789,
     BEFORE = 1827,
     END = 1831,
     TILDE = 1838,
     ILIKE = 1839,
     FILLFACTOR = 1842,
     TIME = 1847,
     KW_TODAY = 1854,
     KW_ROWID = 1855,
     TIMESTAMP = 2203,
     SET_TEXT_FORMAT = 2209,
     KW_TAG = 2225,
     LINTMODULEISLIBRARY = 2226,
     KW_PUBLIC = 2227,
     KW_PRIVATE = 2228,
     COPYBACK = 2229,
     REFERENCES_BLOBTYPE_DEFAULT_NULL = 2230,
     REFERENCES_BLOBTYPE = 2231,
     SORT = 2232,
     KWPIPE = 2233,
     KW_DONE = 2234,
     END_TODO = 2235,
     KW_TODO = 2236,
     KW_ALWAYS = 2237,
     PROGRAM_TIMEOUT = 2238
   };
#endif
/* Tokens.  */
#define INT_VALUE 2240
#define NAMED 2241
#define NAMED_GEN 2242
#define CHAR_VALUE 2243
#define NOT_USED_1 2244
#define NOT_USED_2 2245
#define NOT_USED_3 2246
#define NOT_USED_4 2247
#define NOT_USED_5 2248
#define NOT_USED_6 2249
#define NOT_USED_7 2250
#define NOT_USED_8 2251
#define NUMBER_VALUE 2252
#define SEMICOLON 2253
#define QUESTION_MARK 2254
#define CLINE 2255
#define CH 2256
#define MARK_VAR 2257
#define END_MARK_VAR 2258
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
#define EXIT_TODO 1353
#define CONTINUE_TODO 1354
#define UNLOCK_TABLE 1361
#define ROLLBACK_W 1369
#define SQLSEON 1371
#define SQLSEOFF 1372
#define CREATE_VIEW 1376
#define DELETE_FROM 1377
#define EXTENT_SIZE 1384
#define FOREIGN_KEY 1385
#define INSERT_INTO 1388
#define IS_NOT_NULL 1390
#define NOT_MATCHES 1393
#define PRIMARY_KEY 1399
#define WITH_NO_LOG 1406
#define INSHARE 1409
#define BEGIN_WORK 1415
#define DROP_INDEX 1420
#define FOR_UPDATE_OF 1426
#define FOR_UPDATE 1427
#define LOCK_TABLE 1432
#define NOT_EXISTS 1434
#define REFERENCES 1436
#define RENCOL 1437
#define SMALLFLOAT 1439
#define COMMIT_W 1450
#define RENTAB 1457
#define KW_CHAR 1460
#define NCHAR 1461
#define NVARCHAR 1462
#define DELIMITER 1464
#define DROP_VIEW 1466
#define EXCLUSIVE 1469
#define GREATER_THAN_EQ 1473
#define INTO_TEMP 1475
#define DATABASE 1499
#define DATETIME 1500
#define DISTINCT 1502
#define FRACTION 1509
#define GROUP_BY 1511
#define INTERVAL 1512
#define NOT_LIKE 1514
#define NOT_ILIKE 1515
#define NOT_NULL 1516
#define RESOURCE 1522
#define SMALLINT 1523
#define IS_NULL 1529
#define LESS_THAN_EQ 1530
#define BETWEEN 1532
#define CLOSE_BRACKET 1535
#define CONNECT 1538
#define KW_CURRENT 1539
#define KW_DECIMAL 1541
#define DEFAULT 1543
#define INTEGER 1551
#define SERIAL8 1553
#define MATCHES 1556
#define VARCHAR 1569
#define CLOSE_SQUARE 1572
#define GREATER_THAN 1573
#define KW_FALSE 1574
#define NOT_IN 1575
#define OPEN_BRACKET 1577
#define KW_DELETE 1585
#define KW_ESCAPE 1588
#define EXISTS 1589
#define EXTEND 1590
#define HAVING 1594
#define KW_INSERT 1596
#define MINUTE 1600
#define MODIFY 1601
#define EQUAL 1603
#define NOT_EQUAL 1604
#define OPEN_SQUARE 1606
#define PUBLIC 1610
#define KW_RETURN_KEY 1613
#define REVOKE 1615
#define SECOND 1619
#define KW_SELECT 1623
#define SERIAL 1624
#define UNIQUE 1627
#define KW_UPDATE 1629
#define VALUES 1630
#define KW_NULL 1633
#define KW_TRUE 1634
#define ALTER 1636
#define CHECK 1642
#define COUNT 1646
#define KW_FIRST 1651
#define KW_FLOAT 1652
#define GRANT 1655
#define INDEX 1658
#define LESS_THAN 1661
#define MONEY 1663
#define MONTH 1664
#define KW_MULTIPLY 1666
#define ORDER 1667
#define OUTER 1668
#define UNION 1677
#define WHERE 1680
#define KW_BYTE 1687
#define CASE 1689
#define KW_DATE 1691
#define DESC 1692
#define KW_DIVIDE 1693
#define DROP 1696
#define ELSE 1697
#define FROM 1701
#define HOUR 1707
#define INTO 1708
#define LIKE 1711
#define REAL 1720
#define SOME 1725
#define KW_TEXT 1729
#define KW_THEN 1730
#define USER 1731
#define WHEN 1733
#define YEAR 1736
#define KW_DOW 1737
#define XSET 1739
#define ADD 1740
#define ALL 1741
#define KW_AND 1742
#define ANY 1743
#define ASC 1744
#define AVG 1745
#define COLON 1746
#define KW_COMMA 1747
#define DAY 1748
#define DBA 1749
#define KW_FOR 1753
#define XMAX 1758
#define XMIN 1759
#define KW_MINUS 1760
#define KW_MOD 1761
#define KW_NOT 1762
#define KW_SUM 1769
#define ATSIGN 1772
#define KW_PLUS 1773
#define KW_AS 1779
#define KW_BY 1781
#define KW_DOT 1782
#define KW_IN 1785
#define KW_ON 1787
#define KW_OR 1788
#define KW_TO 1789
#define BEFORE 1827
#define END 1831
#define TILDE 1838
#define ILIKE 1839
#define FILLFACTOR 1842
#define TIME 1847
#define KW_TODAY 1854
#define KW_ROWID 1855
#define TIMESTAMP 2203
#define SET_TEXT_FORMAT 2209
#define KW_TAG 2225
#define LINTMODULEISLIBRARY 2226
#define KW_PUBLIC 2227
#define KW_PRIVATE 2228
#define COPYBACK 2229
#define REFERENCES_BLOBTYPE_DEFAULT_NULL 2230
#define REFERENCES_BLOBTYPE 2231
#define SORT 2232
#define KWPIPE 2233
#define KW_DONE 2234
#define END_TODO 2235
#define KW_TODO 2236
#define KW_ALWAYS 2237
#define PROGRAM_TIMEOUT 2238




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
#line 652 "y.tab.h"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE sqlparse_yylval;


