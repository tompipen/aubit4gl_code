/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

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

#ifndef YY_SQLPARSE_YY_Y_TAB_H_INCLUDED
# define YY_SQLPARSE_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif
#if YYDEBUG
extern int sqlparse_yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    INT_VALUE = 2286,
    NAMED = 2287,
    NAMED_GEN = 2288,
    CHAR_VALUE = 2289,
    NOT_USED_1 = 2290,
    NOT_USED_2 = 2291,
    NOT_USED_3 = 2292,
    NOT_USED_4 = 2293,
    NOT_USED_5 = 2294,
    NOT_USED_6 = 2295,
    NOT_USED_7 = 2296,
    NOT_USED_8 = 2297,
    NUMBER_VALUE = 2298,
    SEMICOLON = 2299,
    QUESTION_MARK = 2300,
    CLINE = 2301,
    CH = 2302,
    MARK_VAR = 2303,
    END_MARK_VAR = 2304,
    END_DIALOG = 1000,
    ACCEPT_DIALOG = 1001,
    EXIT_DIALOG = 1002,
    CONTINUE_DIALOG = 1003,
    AFTER_DIALOG = 1004,
    BEFORE_DIALOG = 1005,
    COUNT_OB = 1007,
    SUM_OB = 1008,
    XMAX_OB = 1009,
    XMIN_OB = 1010,
    AVG_OB = 1011,
    PERCENT_OB = 1012,
    WITH_LISTING_IN = 1013,
    BACKQUOTE = 1014,
    SET_UNDERLINE_ON = 1015,
    SET_UNDERLINE_OFF = 1016,
    SET_POSTGRESQL_SEARCH_PATH = 1017,
    SET_CONSTRAINTS_ALL_DEFERRED = 1018,
    KW_LIMIT = 1019,
    DOCUMENT = 1020,
    ON_EXCEPTION = 1022,
    SET_DEBUG_FILE_TO = 1023,
    CREATE_DBA_PROCEDURE = 1028,
    CREATE_FUNCTION = 1029,
    CREATE_DBA_FUNCTION = 1030,
    USE_SESSION = 1032,
    KW_RUN_CLIENT = 1033,
    LEFT_JOIN = 1035,
    IGNORE_ERRORS = 1038,
    SQLERRMESSAGE = 1039,
    DISPLAY_NULL_TO = 1040,
    UNBUFFERED = 1041,
    KW_PICTURE = 1042,
    ON_CHANGE = 1043,
    INNER_JOIN = 1044,
    UI_INTERFACE_DOT_FRONTCALL = 1047,
    UICOMBOBOX = 1051,
    UIBROWSER = 1052,
    UIPROGRESS = 1053,
    UIGANTT = 1054,
    UIFORM = 1057,
    USING_BTREE = 1073,
    USING_RTREE = 1074,
    RESUME_PAGE = 1085,
    FOR_EVERY_PAGE = 1086,
    SET_BUFFERED_LOG = 1095,
    SET_LOG = 1098,
    MDY = 1100,
    WEEKDAY = 1101,
    MODE_ANSI = 1104,
    START_DATABASE = 1105,
    WITH_LOG_IN = 1106,
    SET_CONSTRAINTS_ALL_IMMEDIATE = 1107,
    DATETIME_VALUE = 1120,
    INTERVAL_VALUE = 1121,
    RECOVER_TABLE = 1122,
    ROLLFORWARD_DATABASE = 1123,
    CONCAT_PIPES = 1137,
    DROP_TRIGGER = 1139,
    DROP_AUDIT_FOR = 1140,
    CREATE_AUDIT_FOR = 1141,
    EXECUTE_PROCEDURE = 1145,
    CURRENT_FIELD_DISPLAY_EQUAL = 1150,
    CURRENT_FIELD_DISPLAY = 1151,
    CURRENT_ROW_DISPLAY = 1152,
    ALTER_TABLE = 1155,
    ALTER_INDEX = 1156,
    NEXT_SIZE = 1157,
    KW_WHENEVER_SIGNAL = 1194,
    KW_SIGNAL_TOKEN = 1195,
    XSET_MULTIPLY_EQUAL_OPEN_BRACKET = 1196,
    XSET_ident_DOT_MULTIPLY_EQUAL_OPEN_BRACKET = 1197,
    XSET_ident_DOT_MULTIPLY_EQUAL = 1198,
    XSET_MULTIPLY_EQUAL = 1199,
    XSET_OPEN_BRACKET = 1200,
    CREATE_DATABASE = 1203,
    DROP_DATABASE = 1204,
    ADD_CONSTRAINT = 1206,
    DROP_CONSTRAINT = 1207,
    DROP_SYNONYM = 1208,
    CONSTRAINT = 1209,
    NOT_FIELD_TOUCHED_CURRENT = 1212,
    FIELD_TOUCHED_CURRENT = 1213,
    OBJECT_FUNCTION = 1215,
    DOUBLE_PRECISION = 1221,
    COUNT_MULTIPLY = 1222,
    KW_ASCII_OPEN_BRACKET = 1231,
    MODIFY_NEXT_SIZE = 1243,
    LOCK_MODE_PAGE = 1244,
    LOCK_MODE_ROW = 1245,
    TO_UI = 1250,
    UNITS_YEAR = 1253,
    UNITS_MONTH = 1254,
    UNITS_DAY = 1255,
    UNITS_HOUR = 1256,
    UNITS_MINUTE = 1257,
    UNITS_SECOND = 1258,
    TO_CLUSTER = 1263,
    TO_NOT_CLUSTER = 1264,
    CREATE_UC_IDX = 1266,
    CREATE_U_IDX = 1267,
    CREATE_C_IDX = 1268,
    CREATE_IDX = 1269,
    DOUBLE_COLON = 1279,
    SQLSICS = 1285,
    CREATE_SCHEMA = 1286,
    SQLSIRR = 1287,
    UPDATESTATS_T = 1288,
    SQLSICR = 1289,
    SQLSIDR = 1300,
    CREATE_TEMP_TABLE = 1301,
    WITH_CHECK_OPTION = 1309,
    WITH_GRANT_OPTION = 1310,
    SQLSLMNW = 1311,
    WHERE_CURRENT_OF = 1317,
    NOT_NULL_UNIQUE = 1325,
    SQLSLMW = 1332,
    ALL_PRIVILEGES = 1334,
    CREATE_SYNONYM = 1338,
    DROP_TABLE = 1339,
    INEXCLUSIVE = 1341,
    REPORT_TO_FILE = 1342,
    REPORT_TO_UI = 1343,
    UPDATESTATS = 1348,
    CREATE_TABLE = 1374,
    DEFAULT_NULL = 1375,
    DEFAULT_TODAY = 1376,
    DEFAULT_USER = 1377,
    EXIT_TODO = 1384,
    CONTINUE_TODO = 1385,
    UNLOCK_TABLE = 1392,
    ROLLBACK_W = 1400,
    SQLSEON = 1402,
    SQLSEOFF = 1403,
    CREATE_VIEW = 1407,
    DELETE_FROM = 1408,
    EXTENT_SIZE = 1415,
    FOREIGN_KEY = 1416,
    INSERT_INTO = 1419,
    IS_NOT_NULL = 1421,
    NOT_MATCHES = 1424,
    PRIMARY_KEY = 1430,
    WITH_NO_LOG = 1437,
    INSHARE = 1440,
    BEGIN_WORK = 1446,
    DROP_INDEX = 1451,
    FOR_UPDATE_OF = 1457,
    FOR_UPDATE = 1458,
    LOCK_TABLE = 1463,
    NOT_EXISTS = 1465,
    REFERENCES = 1467,
    RENCOL = 1468,
    SMALLFLOAT = 1470,
    COMMIT_W = 1481,
    RENTAB = 1488,
    KW_CHAR = 1491,
    NCHAR = 1492,
    NVARCHAR = 1493,
    LVARCHAR = 1494,
    DELIMITER = 1496,
    DROP_VIEW = 1498,
    EXCLUSIVE = 1501,
    GREATER_THAN_EQ = 1505,
    INTO_TEMP = 1507,
    DATABASE = 1531,
    DATETIME = 1532,
    DISTINCT = 1534,
    FRACTION = 1541,
    GROUP_BY = 1543,
    INTERVAL = 1544,
    NOT_LIKE = 1546,
    NOT_ILIKE = 1547,
    NOT_NULL = 1548,
    RESOURCE = 1554,
    SMALLINT = 1555,
    IS_NULL = 1561,
    LESS_THAN_EQ = 1562,
    BETWEEN = 1564,
    CLOSE_BRACKET = 1567,
    CONNECT = 1570,
    KW_CURRENT = 1571,
    KW_DECIMAL = 1573,
    KW_DEFAULT = 1575,
    FGL_SYNCFIELDS = 1583,
    INTEGER = 1584,
    SERIAL8 = 1586,
    MATCHES = 1589,
    VARCHAR = 1602,
    CLOSE_SQUARE = 1605,
    GREATER_THAN = 1606,
    KW_FALSE = 1607,
    NOT_IN = 1608,
    OPEN_BRACKET_SELECT = 1610,
    OPEN_BRACKET = 1611,
    KW_DELETE = 1619,
    KW_ESCAPE = 1622,
    EXISTS = 1623,
    EXTEND = 1624,
    HAVING = 1628,
    KW_INSERT = 1630,
    MINUTE = 1634,
    MODIFY = 1635,
    EQUAL = 1637,
    NOT_EQUAL = 1638,
    OPEN_SQUARE = 1640,
    PUBLIC = 1644,
    KW_RETURN_KEY = 1647,
    REVOKE = 1649,
    SECOND = 1653,
    KW_SELECT = 1657,
    SERIAL = 1658,
    UNIQUE = 1661,
    KW_UPDATE = 1663,
    VALUES = 1664,
    KW_NULL = 1667,
    KW_TRUE = 1668,
    ALTER = 1670,
    CHECK = 1676,
    KW_FIRST = 1684,
    KW_FLOAT = 1685,
    GRANT = 1688,
    INDEX = 1691,
    LESS_THAN = 1694,
    MONEY = 1696,
    MONTH = 1697,
    KW_MULTIPLY = 1699,
    ORDER = 1700,
    OUTER = 1701,
    UNION = 1710,
    WHERE = 1713,
    KW_BYTE = 1720,
    CASE = 1722,
    KW_DATE = 1724,
    DESC = 1725,
    KW_DIVIDE = 1726,
    DROP = 1729,
    ELSE = 1730,
    FROM = 1734,
    HOUR = 1740,
    INTO = 1741,
    LIKE = 1744,
    REAL = 1753,
    SOME = 1758,
    KW_TEXT = 1762,
    KW_THEN = 1763,
    USER = 1764,
    WHEN = 1766,
    YEAR = 1769,
    KW_DOW = 1770,
    XSET = 1772,
    ADD = 1773,
    ALL = 1774,
    KW_AND = 1775,
    ANY = 1776,
    ASC = 1777,
    AVG = 1778,
    COLON = 1779,
    KW_COMMA = 1780,
    DAY = 1781,
    DBA = 1782,
    KW_FOR = 1786,
    XMAX = 1791,
    XMIN = 1792,
    KW_MINUS = 1793,
    KW_MOD = 1794,
    KW_NOT = 1795,
    KW_SUM = 1802,
    ATSIGN = 1805,
    KW_PLUS = 1806,
    KW_AS = 1812,
    KW_BY = 1814,
    KW_DOT = 1815,
    KW_IN = 1818,
    KW_ON = 1820,
    KW_OR = 1821,
    KW_TO = 1822,
    BEFORE = 1860,
    END = 1864,
    TILDE = 1871,
    ILIKE = 1872,
    FILLFACTOR = 1875,
    TIME = 1880,
    KW_TODAY = 1887,
    KW_ROWID = 1888,
    TIMESTAMP = 2236,
    KWPIPE = 2266,
    COUNT = 2279,
    DIALOG = 2280,
    SUBDIALOG = 2281,
    PDF_XY = 2282,
    SET_VALUE = 2283,
    KW_EMBEDDED = 2284
  };
#endif
/* Tokens.  */
#define INT_VALUE 2286
#define NAMED 2287
#define NAMED_GEN 2288
#define CHAR_VALUE 2289
#define NOT_USED_1 2290
#define NOT_USED_2 2291
#define NOT_USED_3 2292
#define NOT_USED_4 2293
#define NOT_USED_5 2294
#define NOT_USED_6 2295
#define NOT_USED_7 2296
#define NOT_USED_8 2297
#define NUMBER_VALUE 2298
#define SEMICOLON 2299
#define QUESTION_MARK 2300
#define CLINE 2301
#define CH 2302
#define MARK_VAR 2303
#define END_MARK_VAR 2304
#define END_DIALOG 1000
#define ACCEPT_DIALOG 1001
#define EXIT_DIALOG 1002
#define CONTINUE_DIALOG 1003
#define AFTER_DIALOG 1004
#define BEFORE_DIALOG 1005
#define COUNT_OB 1007
#define SUM_OB 1008
#define XMAX_OB 1009
#define XMIN_OB 1010
#define AVG_OB 1011
#define PERCENT_OB 1012
#define WITH_LISTING_IN 1013
#define BACKQUOTE 1014
#define SET_UNDERLINE_ON 1015
#define SET_UNDERLINE_OFF 1016
#define SET_POSTGRESQL_SEARCH_PATH 1017
#define SET_CONSTRAINTS_ALL_DEFERRED 1018
#define KW_LIMIT 1019
#define DOCUMENT 1020
#define ON_EXCEPTION 1022
#define SET_DEBUG_FILE_TO 1023
#define CREATE_DBA_PROCEDURE 1028
#define CREATE_FUNCTION 1029
#define CREATE_DBA_FUNCTION 1030
#define USE_SESSION 1032
#define KW_RUN_CLIENT 1033
#define LEFT_JOIN 1035
#define IGNORE_ERRORS 1038
#define SQLERRMESSAGE 1039
#define DISPLAY_NULL_TO 1040
#define UNBUFFERED 1041
#define KW_PICTURE 1042
#define ON_CHANGE 1043
#define INNER_JOIN 1044
#define UI_INTERFACE_DOT_FRONTCALL 1047
#define UICOMBOBOX 1051
#define UIBROWSER 1052
#define UIPROGRESS 1053
#define UIGANTT 1054
#define UIFORM 1057
#define USING_BTREE 1073
#define USING_RTREE 1074
#define RESUME_PAGE 1085
#define FOR_EVERY_PAGE 1086
#define SET_BUFFERED_LOG 1095
#define SET_LOG 1098
#define MDY 1100
#define WEEKDAY 1101
#define MODE_ANSI 1104
#define START_DATABASE 1105
#define WITH_LOG_IN 1106
#define SET_CONSTRAINTS_ALL_IMMEDIATE 1107
#define DATETIME_VALUE 1120
#define INTERVAL_VALUE 1121
#define RECOVER_TABLE 1122
#define ROLLFORWARD_DATABASE 1123
#define CONCAT_PIPES 1137
#define DROP_TRIGGER 1139
#define DROP_AUDIT_FOR 1140
#define CREATE_AUDIT_FOR 1141
#define EXECUTE_PROCEDURE 1145
#define CURRENT_FIELD_DISPLAY_EQUAL 1150
#define CURRENT_FIELD_DISPLAY 1151
#define CURRENT_ROW_DISPLAY 1152
#define ALTER_TABLE 1155
#define ALTER_INDEX 1156
#define NEXT_SIZE 1157
#define KW_WHENEVER_SIGNAL 1194
#define KW_SIGNAL_TOKEN 1195
#define XSET_MULTIPLY_EQUAL_OPEN_BRACKET 1196
#define XSET_ident_DOT_MULTIPLY_EQUAL_OPEN_BRACKET 1197
#define XSET_ident_DOT_MULTIPLY_EQUAL 1198
#define XSET_MULTIPLY_EQUAL 1199
#define XSET_OPEN_BRACKET 1200
#define CREATE_DATABASE 1203
#define DROP_DATABASE 1204
#define ADD_CONSTRAINT 1206
#define DROP_CONSTRAINT 1207
#define DROP_SYNONYM 1208
#define CONSTRAINT 1209
#define NOT_FIELD_TOUCHED_CURRENT 1212
#define FIELD_TOUCHED_CURRENT 1213
#define OBJECT_FUNCTION 1215
#define DOUBLE_PRECISION 1221
#define COUNT_MULTIPLY 1222
#define KW_ASCII_OPEN_BRACKET 1231
#define MODIFY_NEXT_SIZE 1243
#define LOCK_MODE_PAGE 1244
#define LOCK_MODE_ROW 1245
#define TO_UI 1250
#define UNITS_YEAR 1253
#define UNITS_MONTH 1254
#define UNITS_DAY 1255
#define UNITS_HOUR 1256
#define UNITS_MINUTE 1257
#define UNITS_SECOND 1258
#define TO_CLUSTER 1263
#define TO_NOT_CLUSTER 1264
#define CREATE_UC_IDX 1266
#define CREATE_U_IDX 1267
#define CREATE_C_IDX 1268
#define CREATE_IDX 1269
#define DOUBLE_COLON 1279
#define SQLSICS 1285
#define CREATE_SCHEMA 1286
#define SQLSIRR 1287
#define UPDATESTATS_T 1288
#define SQLSICR 1289
#define SQLSIDR 1300
#define CREATE_TEMP_TABLE 1301
#define WITH_CHECK_OPTION 1309
#define WITH_GRANT_OPTION 1310
#define SQLSLMNW 1311
#define WHERE_CURRENT_OF 1317
#define NOT_NULL_UNIQUE 1325
#define SQLSLMW 1332
#define ALL_PRIVILEGES 1334
#define CREATE_SYNONYM 1338
#define DROP_TABLE 1339
#define INEXCLUSIVE 1341
#define REPORT_TO_FILE 1342
#define REPORT_TO_UI 1343
#define UPDATESTATS 1348
#define CREATE_TABLE 1374
#define DEFAULT_NULL 1375
#define DEFAULT_TODAY 1376
#define DEFAULT_USER 1377
#define EXIT_TODO 1384
#define CONTINUE_TODO 1385
#define UNLOCK_TABLE 1392
#define ROLLBACK_W 1400
#define SQLSEON 1402
#define SQLSEOFF 1403
#define CREATE_VIEW 1407
#define DELETE_FROM 1408
#define EXTENT_SIZE 1415
#define FOREIGN_KEY 1416
#define INSERT_INTO 1419
#define IS_NOT_NULL 1421
#define NOT_MATCHES 1424
#define PRIMARY_KEY 1430
#define WITH_NO_LOG 1437
#define INSHARE 1440
#define BEGIN_WORK 1446
#define DROP_INDEX 1451
#define FOR_UPDATE_OF 1457
#define FOR_UPDATE 1458
#define LOCK_TABLE 1463
#define NOT_EXISTS 1465
#define REFERENCES 1467
#define RENCOL 1468
#define SMALLFLOAT 1470
#define COMMIT_W 1481
#define RENTAB 1488
#define KW_CHAR 1491
#define NCHAR 1492
#define NVARCHAR 1493
#define LVARCHAR 1494
#define DELIMITER 1496
#define DROP_VIEW 1498
#define EXCLUSIVE 1501
#define GREATER_THAN_EQ 1505
#define INTO_TEMP 1507
#define DATABASE 1531
#define DATETIME 1532
#define DISTINCT 1534
#define FRACTION 1541
#define GROUP_BY 1543
#define INTERVAL 1544
#define NOT_LIKE 1546
#define NOT_ILIKE 1547
#define NOT_NULL 1548
#define RESOURCE 1554
#define SMALLINT 1555
#define IS_NULL 1561
#define LESS_THAN_EQ 1562
#define BETWEEN 1564
#define CLOSE_BRACKET 1567
#define CONNECT 1570
#define KW_CURRENT 1571
#define KW_DECIMAL 1573
#define KW_DEFAULT 1575
#define FGL_SYNCFIELDS 1583
#define INTEGER 1584
#define SERIAL8 1586
#define MATCHES 1589
#define VARCHAR 1602
#define CLOSE_SQUARE 1605
#define GREATER_THAN 1606
#define KW_FALSE 1607
#define NOT_IN 1608
#define OPEN_BRACKET_SELECT 1610
#define OPEN_BRACKET 1611
#define KW_DELETE 1619
#define KW_ESCAPE 1622
#define EXISTS 1623
#define EXTEND 1624
#define HAVING 1628
#define KW_INSERT 1630
#define MINUTE 1634
#define MODIFY 1635
#define EQUAL 1637
#define NOT_EQUAL 1638
#define OPEN_SQUARE 1640
#define PUBLIC 1644
#define KW_RETURN_KEY 1647
#define REVOKE 1649
#define SECOND 1653
#define KW_SELECT 1657
#define SERIAL 1658
#define UNIQUE 1661
#define KW_UPDATE 1663
#define VALUES 1664
#define KW_NULL 1667
#define KW_TRUE 1668
#define ALTER 1670
#define CHECK 1676
#define KW_FIRST 1684
#define KW_FLOAT 1685
#define GRANT 1688
#define INDEX 1691
#define LESS_THAN 1694
#define MONEY 1696
#define MONTH 1697
#define KW_MULTIPLY 1699
#define ORDER 1700
#define OUTER 1701
#define UNION 1710
#define WHERE 1713
#define KW_BYTE 1720
#define CASE 1722
#define KW_DATE 1724
#define DESC 1725
#define KW_DIVIDE 1726
#define DROP 1729
#define ELSE 1730
#define FROM 1734
#define HOUR 1740
#define INTO 1741
#define LIKE 1744
#define REAL 1753
#define SOME 1758
#define KW_TEXT 1762
#define KW_THEN 1763
#define USER 1764
#define WHEN 1766
#define YEAR 1769
#define KW_DOW 1770
#define XSET 1772
#define ADD 1773
#define ALL 1774
#define KW_AND 1775
#define ANY 1776
#define ASC 1777
#define AVG 1778
#define COLON 1779
#define KW_COMMA 1780
#define DAY 1781
#define DBA 1782
#define KW_FOR 1786
#define XMAX 1791
#define XMIN 1792
#define KW_MINUS 1793
#define KW_MOD 1794
#define KW_NOT 1795
#define KW_SUM 1802
#define ATSIGN 1805
#define KW_PLUS 1806
#define KW_AS 1812
#define KW_BY 1814
#define KW_DOT 1815
#define KW_IN 1818
#define KW_ON 1820
#define KW_OR 1821
#define KW_TO 1822
#define BEFORE 1860
#define END 1864
#define TILDE 1871
#define ILIKE 1872
#define FILLFACTOR 1875
#define TIME 1880
#define KW_TODAY 1887
#define KW_ROWID 1888
#define TIMESTAMP 2236
#define KWPIPE 2266
#define COUNT 2279
#define DIALOG 2280
#define SUBDIALOG 2281
#define PDF_XY 2282
#define SET_VALUE 2283
#define KW_EMBEDDED 2284

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 145 "sql.yacc" /* yacc.c:1909  */

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



#line 703 "y.tab.h" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE sqlparse_yylval;

int sqlparse_yyparse (void);

#endif /* !YY_SQLPARSE_YY_Y_TAB_H_INCLUDED  */
