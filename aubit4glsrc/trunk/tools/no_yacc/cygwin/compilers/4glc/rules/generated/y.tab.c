/* A Bison parser, made by GNU Bison 1.875.  */

/* Skeleton parser for Yacc-like parsing with Bison,
   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002 Free Software Foundation, Inc.

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
   Foundation, Inc., 59 Temple Place - Suite 330,
   Boston, MA 02111-1307, USA.  */

/* As a special exception, when this file is copied by Bison into a
   Bison output file, you may use that output file without restriction.
   This special exception was added by the Free Software Foundation
   in version 1.24 of Bison.  */

/* Written by Richard Stallman by simplifying the original so called
   ``semantic'' parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 1

/* Using locations.  */
#define YYLSP_NEEDED 0

/* If NAME_PREFIX is specified substitute the variables and functions
   names.  */
#define yyparse a4gl_yyparse
#define yylex   a4gl_yylex
#define yyerror a4gl_yyerror
#define yylval  a4gl_yylval
#define yychar  a4gl_yychar
#define yydebug a4gl_yydebug
#define yynerrs a4gl_yynerrs


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     NAME = 1667,
     UMINUS = 1668,
     COMMA = 1574,
     KW_OR = 1614,
     KW_AND = 1569,
     KW_USING = 1506,
     NOT = 1589,
     MATCHES = 1385,
     POWER = 1492,
     LESS_THAN = 1488,
     GREATER_THAN = 1403,
     EQUAL = 1564,
     GREATER_THAN_EQ = 1301,
     LESS_THAN_EQ = 1360,
     NOT_EQUAL = 1434,
     PLUS = 1600,
     MINUS = 1587,
     MULTIPLY = 1493,
     DIVIDE = 1520,
     MOD = 1588,
     COMMAND = 1367,
     NUMBER_VALUE = 1669,
     CHAR_VALUE = 1670,
     INT_VALUE = 1671,
     NAMED_GEN = 1672,
     CLINE = 1673,
     SQLLINE = 1674,
     KW_CSTART = 1675,
     KW_CEND = 1676,
     USER_DTYPE = 1677,
     SQL_TEXT = 1678,
     DYNAMIC_ARRAY = 1000,
     RESIZE_ARRAY = 1001,
     ALLOCATE_ARRAY = 1002,
     DEALLOCATE_ARRAY = 1003,
     BEFORE_INSERT = 1004,
     CONCAT_PIPES = 1005,
     BEFORE_DELETE = 1006,
     AFTER_INSERT = 1007,
     AFTER_DELETE = 1008,
     EXECUTE_IMMEDIATE = 1009,
     DELETE_ROW_EQUAL_TRUE = 1010,
     INSERT_ROW_EQUAL_TRUE = 1011,
     DELETE_ROW_EQUAL_FALSE = 1012,
     INSERT_ROW_EQUAL_FALSE = 1013,
     CURRENT_ROW_DISPLAY_EQUAL = 1014,
     MAXCOUNT = 1015,
     ALTER_TABLE = 1016,
     WHENEVER_ERROR_CONTINUE = 1017,
     WHENEVER_WARNING_CONTINUE = 1018,
     XSET_MULTIPLY_EQUAL_OPEN_BRACKET = 1019,
     XSET_ident_DOT_MULTIPLY_EQUAL_OPEN_BRACKET = 1020,
     XSET_ident_DOT_MULTIPLY_EQUAL = 1021,
     XSET_MULTIPLY_EQUAL = 1022,
     XSET_OPEN_BRACKET = 1023,
     NEWFORMATSHARED = 1024,
     CREATE_DATABASE = 1025,
     IMPORT_LEGACY_FUNCTION = 1026,
     ADD_CONSTRAINT = 1027,
     DROP_CONSTRAINT = 1028,
     AS_STATIC = 1029,
     NOT_FIELD_TOUCHED = 1030,
     LOCAL_FUNCTION = 1031,
     EVERY_ROW = 1032,
     ELIF = 1033,
     DOUBLE_PRECISION = 1034,
     COUNT_MULTIPLY = 1035,
     WAIT_FOR_KEY = 1036,
     AT_TERMINATION_CALL = 1037,
     TERMINATE_REPORT = 1038,
     TO_MAIN_CAPTION = 1039,
     CLEARSTAT = 1040,
     TO_MENUITEM = 1041,
     ID_TO_INT = 1042,
     TO_STATUSBOX = 1043,
     ASCII_HEIGHT_ALL = 1044,
     ASCII_WIDTH_ALL = 1045,
     IMPORT_DATATYPE = 1046,
     PAGE_TRAILER_SIZE = 1047,
     PAGE_HEADER_SIZE = 1048,
     FIRST_PAGE_HEADER_SIZE = 1049,
     BYTES_USE_AS_IMAGE = 1050,
     BYTES_USE_AS_ASCII = 1051,
     KWUP_BY = 1052,
     KWDOWN_BY = 1053,
     CLOSE_STATUSBOX = 1054,
     MODIFY_NEXT_SIZE = 1055,
     LOCK_MODE_PAGE = 1056,
     LOCK_MODE_ROW = 1057,
     TO_PIPE = 1058,
     TO_PRINTER = 1059,
     STATUSBOX = 1060,
     CONNECT_TO = 1061,
     FORMHANDLER_INPUT = 1062,
     UNITS_YEAR = 1063,
     UNITS_MONTH = 1064,
     UNITS_DAY = 1065,
     UNITS_HOUR = 1066,
     UNITS_MINUTE = 1067,
     UNITS_SECOND = 1068,
     NO_NEW_LINES = 1069,
     FIELDTOWIDGET = 1070,
     WITH_HOLD = 1071,
     SHOW_MENU = 1072,
     CWIS = 1073,
     CREATE_IDX = 1074,
     FORM_IS_COMPILED = 1075,
     PDF_REPORT = 1076,
     IMPORT_FUNCTION = 1077,
     PROMPT_MANY = 1078,
     POINTS = 1079,
     MM = 1080,
     INCHES = 1081,
     PREPEND = 1082,
     MEMBER_OF = 1083,
     MEMBER_FUNCTION = 1084,
     APPEND = 1085,
     TEMPLATE = 1086,
     END_TEMPLATE = 1087,
     SQLSICS = 1088,
     CREATE_SCHEMA = 1089,
     SQLSIRR = 1090,
     UPDATESTATS_T = 1091,
     SQLSICR = 1092,
     WHENEVER_SQLSUCCESS = 1093,
     WHENEVER_SQLWARNING = 1094,
     START_EXTERN = 1095,
     WHENEVER_ANY_ERROR = 1096,
     WHENEVER_NOT_FOUND = 1097,
     CONTINUE_CONSTRUCT = 1098,
     FOUNCONSTR = 1099,
     SQLSIDR = 1100,
     WHENEVER_SQLERROR = 1101,
     CREATE_TEMP_TABLE = 1102,
     CURRENT_WINDOW_IS = 1103,
     FIRST_PAGE_HEADER = 1104,
     ORDER_EXTERNAL_BY = 1105,
     SCROLL_CURSOR_FOR = 1106,
     SCROLL_CURSOR = 1107,
     SQL_INTERRUPT_OFF = 1108,
     STOP_ALL_EXTERNAL = 1109,
     WITH_CHECK_OPTION = 1110,
     WITH_GRANT_OPTION = 1111,
     SQLSLMNW = 1112,
     ADDCONSTUNIQ = 1113,
     CONTINUE_DISPLAY = 1114,
     CONTINUE_FOREACH = 1115,
     OUTPUT_TO_REPORT = 1116,
     SQL_INTERRUPT_ON = 1117,
     WHENEVER_SUCCESS = 1118,
     WHENEVER_WARNING = 1119,
     WHERE_CURRENT_OF = 1120,
     WITHOUT_DEFAULTS = 1121,
     FOCONSTR = 1122,
     SCALED_BY = 1123,
     CONTINUE_PROMPT = 1124,
     PDF_FUNCTION = 1125,
     DEFER_INTERRUPT = 1126,
     DISPLAY_BY_NAME = 1127,
     NOT_NULL_UNIQUE = 1128,
     SKIP_TO_TOP = 1129,
     TOP_OF_PAGE = 1130,
     SKIP_TO = 1131,
     SKIP_BY = 1132,
     WITHOUT_WAITING = 1133,
     BEFCONSTRUCT = 1134,
     SQLSLMW = 1135,
     WHENEVER_ERROR = 1136,
     AFTCONSTRUCT = 1137,
     ALL_PRIVILEGES = 1138,
     CLOSE_DATABASE = 1139,
     CONTINUE_INPUT = 1140,
     CONTINUE_WHILE = 1141,
     CREATE_SYNONYM = 1142,
     DROP_TABLE = 1143,
     EXIT_CONSTRUCT = 1144,
     INEXCLUSIVE = 1145,
     REPORT_TO_PRINTER = 1146,
     REPORT_TO_PIPE = 1147,
     RETURN = 1148,
     SET_SESSION_TO = 1149,
     UPDATESTATS = 1150,
     WITHOUT_HEAD = 1151,
     CLEARSCR = 1152,
     WITH_B_LOG = 1153,
     AUTHORIZATION = 1154,
     BOTTOM_MARGIN = 1155,
     CLOSE_SESSION = 1156,
     CONTINUE_CASE = 1157,
     CONTINUE_MENU = 1158,
     DISPLAY_ARRAY = 1159,
     END_SQL = 1160,
     DOLLAR = 1161,
     END_CONSTRUCT = 1162,
     FIELD_TOUCHED = 1163,
     FINISH_REPORT = 1164,
     INFACC = 1165,
     INPUT_NO_WRAP = 1166,
     LOCKMODEPAGE = 1167,
     SETPMOFF = 1168,
     UNCONSTRAINED = 1169,
     PAGE_TRAILER = 1170,
     SETPMON = 1171,
     BEFGROUP = 1172,
     CLOSE_WINDOW = 1173,
     COMMENT_LINE = 1174,
     CONTINUE_FOR = 1175,
     CREATE_DB = 1176,
     CREATE_TABLE = 1177,
     DEFAULT_NULL = 1178,
     DELETE_USING = 1179,
     DISPLAY_FORM = 1180,
     END_FUNCTION = 1181,
     EXIT_DISPLAY = 1182,
     EXIT_FOREACH = 1183,
     EXIT_PROGRAM = 1184,
     INFCOLS = 1185,
     LOCKMODEROW = 1186,
     ON_EVERY_ROW = 1187,
     OPEN_SESSION = 1188,
     RIGHT_MARGIN = 1189,
     SELECT_USING = 1190,
     START_REPORT = 1191,
     UNLOCK_TABLE = 1192,
     UPDATE_USING = 1193,
     ACL_BUILTIN = 1194,
     AFTGROUP = 1195,
     INFIDX = 1196,
     INFSTAT = 1197,
     LEFT_MARGIN = 1198,
     PAGE_HEADER = 1199,
     ROLLBACK_W = 1200,
     SET_SESSION = 1201,
     SQLSEOFF = 1202,
     WITH_A_LOG = 1203,
     BEFDISP = 1204,
     BEFORE_MENU = 1205,
     CREATE_VIEW = 1206,
     DEFINE_TYPE = 1207,
     DELETE_FROM = 1208,
     END_DISPLAY = 1209,
     END_REPORT = 1210,
     END_FOREACH = 1211,
     END_FOR = 1212,
     END_GLOBALS = 1213,
     EXIT_PROMPT = 1214,
     EXTENT_SIZE = 1215,
     FOREIGN_KEY = 1216,
     HIDE_OPTION = 1217,
     HIDE_WINDOW = 1218,
     INSERT_INTO = 1219,
     IS_NOT_NULL = 1220,
     MOVE_WINDOW = 1221,
     NEXT_OPTION = 1222,
     NOT_MATCHES = 1223,
     ON_LAST_ROW = 1224,
     OPEN_WINDOW = 1225,
     OPEN_STATUSBOX = 1226,
     PAGE_LENGTH = 1227,
     PAGE_WIDTH = 1228,
     PRIMARY_KEY = 1229,
     PROMPT_LINE = 1230,
     RECORD_LIKE = 1231,
     ROLLFORWARD = 1232,
     SETBL = 1233,
     SHOW_OPTION = 1234,
     SHOW_WINDOW = 1235,
     SQLSEON = 1236,
     TO_DATABASE = 1237,
     USE_SESSION = 1238,
     WITH_NO_LOG = 1239,
     AFTDISP = 1240,
     BEFFIELD = 1241,
     INSHARE = 1242,
     UNLOCKTAB = 1243,
     AFTFIELD = 1244,
     ATTRIBUTES = 1245,
     BEFINP = 1246,
     BEGIN_WORK = 1247,
     CLEARWIN = 1248,
     CLOSE_FORM = 1249,
     DEFER_QUIT = 1250,
     DESCENDING = 1251,
     DROP_INDEX = 1252,
     END_PROMPT = 1253,
     END_RECORD = 1254,
     ERROR_LINE = 1255,
     EXIT_INPUT = 1256,
     EXIT_WHILE = 1257,
     FOR_UPDATE_OF = 1258,
     FOR_UPDATE = 1259,
     GET_FLDBUF = 1260,
     INITIALIZE = 1261,
     INPUT_WRAP = 1262,
     LOCK_TABLE = 1263,
     MSG_LINE = 1264,
     NOT_EXISTS = 1265,
     ON_ANY_KEY = 1266,
     REFERENCES = 1267,
     RENCOL = 1268,
     SET_CURSOR = 1269,
     SMALLFLOAT = 1270,
     SQLSUCCESS = 1271,
     TOP_MARGIN = 1272,
     WITH_ARRAY = 1273,
     ACCEPTKEY = 1274,
     ACCEPT = 1275,
     AFTINP = 1276,
     CLEARFORMTODEFAULTS = 1277,
     CLEARFORM = 1278,
     CLEAR_X_FORM = 1279,
     COMMIT_W = 1280,
     NEXTPAGE = 1281,
     PREVPAGE = 1282,
     CTRL_KEY = 1283,
     INFTABS = 1284,
     NEXTFIELD = 1285,
     NEXTFORM = 1286,
     RENTAB = 1287,
     ASCENDING = 1288,
     ASSOCIATE = 1289,
     CHAR = 1290,
     CONSTRUCT = 1291,
     DELIMITER = 1292,
     DOWNSHIFT = 1293,
     DROP_VIEW = 1294,
     END_INPUT = 1295,
     END_WHILE = 1296,
     EXCLUSIVE = 1297,
     EXIT_CASE = 1298,
     EXIT_MENU = 1299,
     FORM_LINE = 1300,
     INTERRUPT = 1302,
     INTO_TEMP = 1303,
     INVISIBLE = 1304,
     IN_MEMORY = 1305,
     LINKED_TO = 1306,
     LOAD_FROM = 1307,
     LOCKTAB = 1308,
     MENU_LINE = 1309,
     OPEN_FORM = 1310,
     OTHERWISE = 1311,
     PRECISION = 1312,
     PRIOR = 1313,
     PROCEDURE = 1314,
     REPORT_TO = 1315,
     RETURNING = 1316,
     UNDERLINE = 1317,
     UNLOAD_TO = 1318,
     BEFROW = 1319,
     UNLOAD_T = 1320,
     VARIABLE = 1321,
     ABSOLUTE = 1322,
     AFTROW = 1323,
     BUFFERED = 1324,
     CONSTANT = 1325,
     CONST = 1326,
     CONTINUE = 1327,
     DATABASE = 1328,
     DATETIME = 1329,
     DEFAULTS = 1330,
     DISTINCT = 1331,
     END_CASE = 1332,
     END_MAIN = 1333,
     END_MENU = 1334,
     END_TYPE = 1335,
     EXIT_FOR = 1336,
     EXTERNAL = 1337,
     FRACTION = 1338,
     FUNCTION = 1339,
     GROUP_BY = 1340,
     INTERVAL = 1341,
     KWMESSAGE = 1342,
     NOT_LIKE = 1343,
     NOT_ILIKE = 1344,
     NOT_NULL = 1345,
     PASSWORD = 1346,
     PREVIOUS = 1347,
     READONLY = 1348,
     REGISTER = 1349,
     RELATIVE = 1350,
     RESOURCE = 1351,
     SMALLINT = 1352,
     VALIDATE = 1353,
     WHENEVER = 1354,
     WITH_LOG = 1355,
     WORDWRAP = 1356,
     BY_NAME = 1357,
     IN_FILE = 1358,
     IS_NULL = 1359,
     AVERAGE = 1361,
     BETWEEN = 1362,
     CAPTION = 1363,
     CLIPPED = 1364,
     CLOSE_BRACKET = 1365,
     COLUMNS = 1366,
     COMMENT = 1368,
     CONNECT = 1369,
     CURRENT = 1370,
     DBYNAME = 1371,
     DECIMAL = 1372,
     DECLARE = 1373,
     DEFAULT = 1374,
     DISPLAY = 1375,
     ENDCODE = 1376,
     EXECUTE = 1377,
     FOREACH = 1378,
     FOREIGN = 1379,
     GLOBALS = 1380,
     INFIELD = 1381,
     INTEGER = 1382,
     KWWINDOW = 1383,
     MAGENTA = 1384,
     NUMERIC = 1386,
     OPTIONS = 1387,
     PERCENT = 1388,
     PREPARE = 1389,
     PROGRAM = 1390,
     RECOVER = 1391,
     REVERSE = 1392,
     SECTION = 1393,
     SESSION = 1394,
     SYNONYM = 1395,
     THRU = 1396,
     TRAILER = 1397,
     UPSHIFT = 1398,
     VARCHAR = 1399,
     WAITING = 1400,
     CLOSE_SHEV = 1401,
     CLOSE_SQUARE = 1402,
     KW_FALSE = 1404,
     NOT_IN = 1405,
     ONKEY = 1406,
     OPEN_BRACKET = 1407,
     BORDER = 1408,
     BOTTOM = 1409,
     COLUMN = 1410,
     COMMIT = 1411,
     CREATE = 1412,
     CURSOR = 1413,
     DEFINE = 1414,
     DELETE = 1415,
     DOUBLE = 1416,
     END_IF = 1417,
     ESCAPE = 1418,
     EXISTS = 1419,
     EXTEND = 1420,
     EXTENT = 1421,
     FINISH = 1422,
     FORMAT = 1423,
     HAVING = 1424,
     HEADER = 1425,
     INSERT = 1426,
     LOCATE = 1427,
     MARGIN = 1428,
     MEMORY = 1429,
     MINUTE = 1430,
     MODIFY = 1431,
     NORMAL = 1432,
     EQUAL_EQUAL = 1433,
     OPEN_SHEV = 1435,
     OPEN_SQUARE = 1436,
     OPTION = 1437,
     OUTPUT = 1438,
     PROMPT = 1439,
     PUBLIC = 1440,
     RECORD = 1441,
     REPORT = 1442,
     REVOKE = 1443,
     SCHEMA = 1444,
     SCROLL_USING = 1445,
     SCROLL = 1446,
     SECOND = 1447,
     SELECT = 1448,
     SERIAL = 1449,
     SETL = 1450,
     SHARED = 1451,
     SPACES = 1452,
     UNIQUE = 1453,
     UNLOCK = 1454,
     UPDATE = 1455,
     VALUES = 1456,
     YELLOW = 1457,
     AFTER = 1458,
     KWLINE = 1459,
     KW_NULL = 1460,
     KW_TRUE = 1461,
     SINGLE_KEY = 1462,
     ALTER = 1463,
     ARRAY = 1464,
     ASCII = 1465,
     AUDIT = 1466,
     BLACK = 1467,
     BLINK = 1468,
     CHECK = 1469,
     CLEAR = 1470,
     CLOSE = 1471,
     CODE_C = 1472,
     COUNT = 1473,
     DEFER = 1474,
     ERROR = 1475,
     EVERY = 1476,
     FETCH = 1477,
     FIRST = 1478,
     FLOAT = 1479,
     FLUSH = 1480,
     FOUND = 1481,
     GRANT = 1482,
     GREEN = 1483,
     GROUP = 1484,
     INDEX = 1485,
     KWFORM = 1486,
     LABEL = 1487,
     LOCAL = 1489,
     MONEY = 1490,
     MONTH = 1491,
     ORDER = 1494,
     OUTER = 1495,
     PAUSE = 1496,
     PRINT_IMAGE = 1497,
     PRINT_FILE = 1498,
     PRINT = 1499,
     RIGHT = 1500,
     DOUBLE_COLON = 1501,
     SEMICOLON = 1502,
     SLEEP = 1503,
     TUPLE = 1504,
     UNION = 1505,
     WHERE = 1507,
     WHILE = 1508,
     WHITE = 1509,
     CCODE = 1510,
     ANSI = 1511,
     BLUE = 1512,
     BOLD = 1513,
     BYTE = 1514,
     FCALL = 1515,
     CASE = 1516,
     CYAN = 1517,
     DATE = 1518,
     DESC = 1519,
     KWDOWN = 1521,
     TAB = 1522,
     DROP = 1523,
     ELSE = 1524,
     EXEC = 1525,
     EXIT = 1526,
     FREE = 1527,
     FROM = 1528,
     GOTO = 1529,
     HELP_FILE = 1530,
     LANG_FILE = 1531,
     HELP = 1532,
     HIDE = 1533,
     HOUR = 1534,
     INTO = 1535,
     LAST = 1536,
     LEFT = 1537,
     LIKE = 1538,
     MAIN = 1539,
     MENU = 1540,
     MODE = 1541,
     NEED = 1542,
     NEXT = 1543,
     NOCR = 1544,
     OPEN = 1545,
     QUIT = 1546,
     REAL = 1547,
     ROWS = 1548,
     SHOW = 1549,
     SIZE = 1550,
     SKIP = 1551,
     SOME = 1552,
     STEP = 1553,
     STOP = 1554,
     TEMP = 1555,
     TEXT = 1556,
     THEN = 1557,
     USER = 1558,
     WAIT = 1559,
     WHEN = 1560,
     WITH = 1561,
     WORK = 1562,
     YEAR = 1563,
     KW_IS = 1565,
     XSET = 1566,
     ADD = 1567,
     ALL = 1568,
     ANY = 1570,
     ASC = 1571,
     AVG = 1572,
     COLON = 1573,
     DAY = 1575,
     DBA = 1576,
     DEC = 1577,
     DIM = 1578,
     FKEY = 1579,
     FOR = 1580,
     KEY = 1581,
     KWNO = 1582,
     LET = 1583,
     LOG = 1584,
     XMAX = 1585,
     XMIN = 1586,
     PAD = 1590,
     PUT = 1591,
     RED = 1592,
     ROW = 1593,
     RUN = 1594,
     SQL = 1595,
     SUM = 1596,
     TOP = 1597,
     USE = 1598,
     ATSIGN = 1599,
     AS_TIFF = 1601,
     AS_GIF = 1602,
     AS_PNG = 1603,
     AS_JPEG = 1604,
     AS = 1605,
     AT = 1606,
     BY = 1607,
     DOT = 1608,
     GO = 1609,
     IF = 1610,
     IN = 1611,
     OF = 1612,
     ON = 1613,
     TO = 1615,
     KWUP = 1616,
     FONT_NAME = 1617,
     FONT_SIZE = 1618,
     PAPER_SIZE_IS_LETTER = 1619,
     PAPER_SIZE_IS_LEGAL = 1620,
     PAPER_SIZE_IS_A5 = 1621,
     PAPER_SIZE_IS_A4 = 1622,
     PAPER_SIZE_IS_LETTER_L = 1623,
     PAPER_SIZE_IS_LEGAL_L = 1624,
     PAPER_SIZE_IS_A5_L = 1625,
     PAPER_SIZE_IS_A4_L = 1626,
     FORMHANDLER = 1627,
     END_FORMHANDLER = 1628,
     BEFORE_EVENT = 1629,
     BEFORE_OPEN_FORM = 1630,
     AFTER_EVENT = 1631,
     BEFORE_CLOSE_FORM = 1632,
     BEFORE_ANY = 1633,
     AFTER_ANY = 1634,
     MENUHANDLER = 1635,
     END_MENUHANDLER = 1636,
     BEFORE_SHOW_MENU = 1637,
     DISABLE_PROGRAM = 1638,
     DISABLE_ALL = 1639,
     BUTTONS = 1640,
     CHECK_MENUITEM = 1641,
     DISABLE_FORM = 1642,
     DISABLE_MENUITEMS = 1643,
     DISABLE = 1644,
     ENABLE_FORM = 1645,
     ENABLE_MENUITEMS = 1646,
     ENABLE = 1647,
     KWFIELD = 1648,
     ICON = 1649,
     MESSAGEBOX = 1650,
     TO_DEFAULTS = 1651,
     UNCHECK_MENUITEM = 1652,
     BEFORE = 1653,
     INPUT = 1654,
     END = 1655,
     INT_TO_ID = 1656,
     TIMEOUT = 1657,
     OFF = 1658,
     WITH_1_DIMENSION = 1659,
     WITH_2_DIMENSION = 1660,
     WITH_3_DIMENSION = 1661,
     TILDE = 1662,
     ILIKE = 1663,
     FGL_ISDYNARR_ALLOCATED = 1664,
     FGL_DYNARR_EXTENTSIZE = 1665
   };
#endif
#define NAME 1667
#define UMINUS 1668
#define COMMA 1574
#define KW_OR 1614
#define KW_AND 1569
#define KW_USING 1506
#define NOT 1589
#define MATCHES 1385
#define POWER 1492
#define LESS_THAN 1488
#define GREATER_THAN 1403
#define EQUAL 1564
#define GREATER_THAN_EQ 1301
#define LESS_THAN_EQ 1360
#define NOT_EQUAL 1434
#define PLUS 1600
#define MINUS 1587
#define MULTIPLY 1493
#define DIVIDE 1520
#define MOD 1588
#define COMMAND 1367
#define NUMBER_VALUE 1669
#define CHAR_VALUE 1670
#define INT_VALUE 1671
#define NAMED_GEN 1672
#define CLINE 1673
#define SQLLINE 1674
#define KW_CSTART 1675
#define KW_CEND 1676
#define USER_DTYPE 1677
#define SQL_TEXT 1678
#define DYNAMIC_ARRAY 1000
#define RESIZE_ARRAY 1001
#define ALLOCATE_ARRAY 1002
#define DEALLOCATE_ARRAY 1003
#define BEFORE_INSERT 1004
#define CONCAT_PIPES 1005
#define BEFORE_DELETE 1006
#define AFTER_INSERT 1007
#define AFTER_DELETE 1008
#define EXECUTE_IMMEDIATE 1009
#define DELETE_ROW_EQUAL_TRUE 1010
#define INSERT_ROW_EQUAL_TRUE 1011
#define DELETE_ROW_EQUAL_FALSE 1012
#define INSERT_ROW_EQUAL_FALSE 1013
#define CURRENT_ROW_DISPLAY_EQUAL 1014
#define MAXCOUNT 1015
#define ALTER_TABLE 1016
#define WHENEVER_ERROR_CONTINUE 1017
#define WHENEVER_WARNING_CONTINUE 1018
#define XSET_MULTIPLY_EQUAL_OPEN_BRACKET 1019
#define XSET_ident_DOT_MULTIPLY_EQUAL_OPEN_BRACKET 1020
#define XSET_ident_DOT_MULTIPLY_EQUAL 1021
#define XSET_MULTIPLY_EQUAL 1022
#define XSET_OPEN_BRACKET 1023
#define NEWFORMATSHARED 1024
#define CREATE_DATABASE 1025
#define IMPORT_LEGACY_FUNCTION 1026
#define ADD_CONSTRAINT 1027
#define DROP_CONSTRAINT 1028
#define AS_STATIC 1029
#define NOT_FIELD_TOUCHED 1030
#define LOCAL_FUNCTION 1031
#define EVERY_ROW 1032
#define ELIF 1033
#define DOUBLE_PRECISION 1034
#define COUNT_MULTIPLY 1035
#define WAIT_FOR_KEY 1036
#define AT_TERMINATION_CALL 1037
#define TERMINATE_REPORT 1038
#define TO_MAIN_CAPTION 1039
#define CLEARSTAT 1040
#define TO_MENUITEM 1041
#define ID_TO_INT 1042
#define TO_STATUSBOX 1043
#define ASCII_HEIGHT_ALL 1044
#define ASCII_WIDTH_ALL 1045
#define IMPORT_DATATYPE 1046
#define PAGE_TRAILER_SIZE 1047
#define PAGE_HEADER_SIZE 1048
#define FIRST_PAGE_HEADER_SIZE 1049
#define BYTES_USE_AS_IMAGE 1050
#define BYTES_USE_AS_ASCII 1051
#define KWUP_BY 1052
#define KWDOWN_BY 1053
#define CLOSE_STATUSBOX 1054
#define MODIFY_NEXT_SIZE 1055
#define LOCK_MODE_PAGE 1056
#define LOCK_MODE_ROW 1057
#define TO_PIPE 1058
#define TO_PRINTER 1059
#define STATUSBOX 1060
#define CONNECT_TO 1061
#define FORMHANDLER_INPUT 1062
#define UNITS_YEAR 1063
#define UNITS_MONTH 1064
#define UNITS_DAY 1065
#define UNITS_HOUR 1066
#define UNITS_MINUTE 1067
#define UNITS_SECOND 1068
#define NO_NEW_LINES 1069
#define FIELDTOWIDGET 1070
#define WITH_HOLD 1071
#define SHOW_MENU 1072
#define CWIS 1073
#define CREATE_IDX 1074
#define FORM_IS_COMPILED 1075
#define PDF_REPORT 1076
#define IMPORT_FUNCTION 1077
#define PROMPT_MANY 1078
#define POINTS 1079
#define MM 1080
#define INCHES 1081
#define PREPEND 1082
#define MEMBER_OF 1083
#define MEMBER_FUNCTION 1084
#define APPEND 1085
#define TEMPLATE 1086
#define END_TEMPLATE 1087
#define SQLSICS 1088
#define CREATE_SCHEMA 1089
#define SQLSIRR 1090
#define UPDATESTATS_T 1091
#define SQLSICR 1092
#define WHENEVER_SQLSUCCESS 1093
#define WHENEVER_SQLWARNING 1094
#define START_EXTERN 1095
#define WHENEVER_ANY_ERROR 1096
#define WHENEVER_NOT_FOUND 1097
#define CONTINUE_CONSTRUCT 1098
#define FOUNCONSTR 1099
#define SQLSIDR 1100
#define WHENEVER_SQLERROR 1101
#define CREATE_TEMP_TABLE 1102
#define CURRENT_WINDOW_IS 1103
#define FIRST_PAGE_HEADER 1104
#define ORDER_EXTERNAL_BY 1105
#define SCROLL_CURSOR_FOR 1106
#define SCROLL_CURSOR 1107
#define SQL_INTERRUPT_OFF 1108
#define STOP_ALL_EXTERNAL 1109
#define WITH_CHECK_OPTION 1110
#define WITH_GRANT_OPTION 1111
#define SQLSLMNW 1112
#define ADDCONSTUNIQ 1113
#define CONTINUE_DISPLAY 1114
#define CONTINUE_FOREACH 1115
#define OUTPUT_TO_REPORT 1116
#define SQL_INTERRUPT_ON 1117
#define WHENEVER_SUCCESS 1118
#define WHENEVER_WARNING 1119
#define WHERE_CURRENT_OF 1120
#define WITHOUT_DEFAULTS 1121
#define FOCONSTR 1122
#define SCALED_BY 1123
#define CONTINUE_PROMPT 1124
#define PDF_FUNCTION 1125
#define DEFER_INTERRUPT 1126
#define DISPLAY_BY_NAME 1127
#define NOT_NULL_UNIQUE 1128
#define SKIP_TO_TOP 1129
#define TOP_OF_PAGE 1130
#define SKIP_TO 1131
#define SKIP_BY 1132
#define WITHOUT_WAITING 1133
#define BEFCONSTRUCT 1134
#define SQLSLMW 1135
#define WHENEVER_ERROR 1136
#define AFTCONSTRUCT 1137
#define ALL_PRIVILEGES 1138
#define CLOSE_DATABASE 1139
#define CONTINUE_INPUT 1140
#define CONTINUE_WHILE 1141
#define CREATE_SYNONYM 1142
#define DROP_TABLE 1143
#define EXIT_CONSTRUCT 1144
#define INEXCLUSIVE 1145
#define REPORT_TO_PRINTER 1146
#define REPORT_TO_PIPE 1147
#define RETURN 1148
#define SET_SESSION_TO 1149
#define UPDATESTATS 1150
#define WITHOUT_HEAD 1151
#define CLEARSCR 1152
#define WITH_B_LOG 1153
#define AUTHORIZATION 1154
#define BOTTOM_MARGIN 1155
#define CLOSE_SESSION 1156
#define CONTINUE_CASE 1157
#define CONTINUE_MENU 1158
#define DISPLAY_ARRAY 1159
#define END_SQL 1160
#define DOLLAR 1161
#define END_CONSTRUCT 1162
#define FIELD_TOUCHED 1163
#define FINISH_REPORT 1164
#define INFACC 1165
#define INPUT_NO_WRAP 1166
#define LOCKMODEPAGE 1167
#define SETPMOFF 1168
#define UNCONSTRAINED 1169
#define PAGE_TRAILER 1170
#define SETPMON 1171
#define BEFGROUP 1172
#define CLOSE_WINDOW 1173
#define COMMENT_LINE 1174
#define CONTINUE_FOR 1175
#define CREATE_DB 1176
#define CREATE_TABLE 1177
#define DEFAULT_NULL 1178
#define DELETE_USING 1179
#define DISPLAY_FORM 1180
#define END_FUNCTION 1181
#define EXIT_DISPLAY 1182
#define EXIT_FOREACH 1183
#define EXIT_PROGRAM 1184
#define INFCOLS 1185
#define LOCKMODEROW 1186
#define ON_EVERY_ROW 1187
#define OPEN_SESSION 1188
#define RIGHT_MARGIN 1189
#define SELECT_USING 1190
#define START_REPORT 1191
#define UNLOCK_TABLE 1192
#define UPDATE_USING 1193
#define ACL_BUILTIN 1194
#define AFTGROUP 1195
#define INFIDX 1196
#define INFSTAT 1197
#define LEFT_MARGIN 1198
#define PAGE_HEADER 1199
#define ROLLBACK_W 1200
#define SET_SESSION 1201
#define SQLSEOFF 1202
#define WITH_A_LOG 1203
#define BEFDISP 1204
#define BEFORE_MENU 1205
#define CREATE_VIEW 1206
#define DEFINE_TYPE 1207
#define DELETE_FROM 1208
#define END_DISPLAY 1209
#define END_REPORT 1210
#define END_FOREACH 1211
#define END_FOR 1212
#define END_GLOBALS 1213
#define EXIT_PROMPT 1214
#define EXTENT_SIZE 1215
#define FOREIGN_KEY 1216
#define HIDE_OPTION 1217
#define HIDE_WINDOW 1218
#define INSERT_INTO 1219
#define IS_NOT_NULL 1220
#define MOVE_WINDOW 1221
#define NEXT_OPTION 1222
#define NOT_MATCHES 1223
#define ON_LAST_ROW 1224
#define OPEN_WINDOW 1225
#define OPEN_STATUSBOX 1226
#define PAGE_LENGTH 1227
#define PAGE_WIDTH 1228
#define PRIMARY_KEY 1229
#define PROMPT_LINE 1230
#define RECORD_LIKE 1231
#define ROLLFORWARD 1232
#define SETBL 1233
#define SHOW_OPTION 1234
#define SHOW_WINDOW 1235
#define SQLSEON 1236
#define TO_DATABASE 1237
#define USE_SESSION 1238
#define WITH_NO_LOG 1239
#define AFTDISP 1240
#define BEFFIELD 1241
#define INSHARE 1242
#define UNLOCKTAB 1243
#define AFTFIELD 1244
#define ATTRIBUTES 1245
#define BEFINP 1246
#define BEGIN_WORK 1247
#define CLEARWIN 1248
#define CLOSE_FORM 1249
#define DEFER_QUIT 1250
#define DESCENDING 1251
#define DROP_INDEX 1252
#define END_PROMPT 1253
#define END_RECORD 1254
#define ERROR_LINE 1255
#define EXIT_INPUT 1256
#define EXIT_WHILE 1257
#define FOR_UPDATE_OF 1258
#define FOR_UPDATE 1259
#define GET_FLDBUF 1260
#define INITIALIZE 1261
#define INPUT_WRAP 1262
#define LOCK_TABLE 1263
#define MSG_LINE 1264
#define NOT_EXISTS 1265
#define ON_ANY_KEY 1266
#define REFERENCES 1267
#define RENCOL 1268
#define SET_CURSOR 1269
#define SMALLFLOAT 1270
#define SQLSUCCESS 1271
#define TOP_MARGIN 1272
#define WITH_ARRAY 1273
#define ACCEPTKEY 1274
#define ACCEPT 1275
#define AFTINP 1276
#define CLEARFORMTODEFAULTS 1277
#define CLEARFORM 1278
#define CLEAR_X_FORM 1279
#define COMMIT_W 1280
#define NEXTPAGE 1281
#define PREVPAGE 1282
#define CTRL_KEY 1283
#define INFTABS 1284
#define NEXTFIELD 1285
#define NEXTFORM 1286
#define RENTAB 1287
#define ASCENDING 1288
#define ASSOCIATE 1289
#define CHAR 1290
#define CONSTRUCT 1291
#define DELIMITER 1292
#define DOWNSHIFT 1293
#define DROP_VIEW 1294
#define END_INPUT 1295
#define END_WHILE 1296
#define EXCLUSIVE 1297
#define EXIT_CASE 1298
#define EXIT_MENU 1299
#define FORM_LINE 1300
#define INTERRUPT 1302
#define INTO_TEMP 1303
#define INVISIBLE 1304
#define IN_MEMORY 1305
#define LINKED_TO 1306
#define LOAD_FROM 1307
#define LOCKTAB 1308
#define MENU_LINE 1309
#define OPEN_FORM 1310
#define OTHERWISE 1311
#define PRECISION 1312
#define PRIOR 1313
#define PROCEDURE 1314
#define REPORT_TO 1315
#define RETURNING 1316
#define UNDERLINE 1317
#define UNLOAD_TO 1318
#define BEFROW 1319
#define UNLOAD_T 1320
#define VARIABLE 1321
#define ABSOLUTE 1322
#define AFTROW 1323
#define BUFFERED 1324
#define CONSTANT 1325
#define CONST 1326
#define CONTINUE 1327
#define DATABASE 1328
#define DATETIME 1329
#define DEFAULTS 1330
#define DISTINCT 1331
#define END_CASE 1332
#define END_MAIN 1333
#define END_MENU 1334
#define END_TYPE 1335
#define EXIT_FOR 1336
#define EXTERNAL 1337
#define FRACTION 1338
#define FUNCTION 1339
#define GROUP_BY 1340
#define INTERVAL 1341
#define KWMESSAGE 1342
#define NOT_LIKE 1343
#define NOT_ILIKE 1344
#define NOT_NULL 1345
#define PASSWORD 1346
#define PREVIOUS 1347
#define READONLY 1348
#define REGISTER 1349
#define RELATIVE 1350
#define RESOURCE 1351
#define SMALLINT 1352
#define VALIDATE 1353
#define WHENEVER 1354
#define WITH_LOG 1355
#define WORDWRAP 1356
#define BY_NAME 1357
#define IN_FILE 1358
#define IS_NULL 1359
#define AVERAGE 1361
#define BETWEEN 1362
#define CAPTION 1363
#define CLIPPED 1364
#define CLOSE_BRACKET 1365
#define COLUMNS 1366
#define COMMENT 1368
#define CONNECT 1369
#define CURRENT 1370
#define DBYNAME 1371
#define DECIMAL 1372
#define DECLARE 1373
#define DEFAULT 1374
#define DISPLAY 1375
#define ENDCODE 1376
#define EXECUTE 1377
#define FOREACH 1378
#define FOREIGN 1379
#define GLOBALS 1380
#define INFIELD 1381
#define INTEGER 1382
#define KWWINDOW 1383
#define MAGENTA 1384
#define NUMERIC 1386
#define OPTIONS 1387
#define PERCENT 1388
#define PREPARE 1389
#define PROGRAM 1390
#define RECOVER 1391
#define REVERSE 1392
#define SECTION 1393
#define SESSION 1394
#define SYNONYM 1395
#define THRU 1396
#define TRAILER 1397
#define UPSHIFT 1398
#define VARCHAR 1399
#define WAITING 1400
#define CLOSE_SHEV 1401
#define CLOSE_SQUARE 1402
#define KW_FALSE 1404
#define NOT_IN 1405
#define ONKEY 1406
#define OPEN_BRACKET 1407
#define BORDER 1408
#define BOTTOM 1409
#define COLUMN 1410
#define COMMIT 1411
#define CREATE 1412
#define CURSOR 1413
#define DEFINE 1414
#define DELETE 1415
#define DOUBLE 1416
#define END_IF 1417
#define ESCAPE 1418
#define EXISTS 1419
#define EXTEND 1420
#define EXTENT 1421
#define FINISH 1422
#define FORMAT 1423
#define HAVING 1424
#define HEADER 1425
#define INSERT 1426
#define LOCATE 1427
#define MARGIN 1428
#define MEMORY 1429
#define MINUTE 1430
#define MODIFY 1431
#define NORMAL 1432
#define EQUAL_EQUAL 1433
#define OPEN_SHEV 1435
#define OPEN_SQUARE 1436
#define OPTION 1437
#define OUTPUT 1438
#define PROMPT 1439
#define PUBLIC 1440
#define RECORD 1441
#define REPORT 1442
#define REVOKE 1443
#define SCHEMA 1444
#define SCROLL_USING 1445
#define SCROLL 1446
#define SECOND 1447
#define SELECT 1448
#define SERIAL 1449
#define SETL 1450
#define SHARED 1451
#define SPACES 1452
#define UNIQUE 1453
#define UNLOCK 1454
#define UPDATE 1455
#define VALUES 1456
#define YELLOW 1457
#define AFTER 1458
#define KWLINE 1459
#define KW_NULL 1460
#define KW_TRUE 1461
#define SINGLE_KEY 1462
#define ALTER 1463
#define ARRAY 1464
#define ASCII 1465
#define AUDIT 1466
#define BLACK 1467
#define BLINK 1468
#define CHECK 1469
#define CLEAR 1470
#define CLOSE 1471
#define CODE_C 1472
#define COUNT 1473
#define DEFER 1474
#define ERROR 1475
#define EVERY 1476
#define FETCH 1477
#define FIRST 1478
#define FLOAT 1479
#define FLUSH 1480
#define FOUND 1481
#define GRANT 1482
#define GREEN 1483
#define GROUP 1484
#define INDEX 1485
#define KWFORM 1486
#define LABEL 1487
#define LOCAL 1489
#define MONEY 1490
#define MONTH 1491
#define ORDER 1494
#define OUTER 1495
#define PAUSE 1496
#define PRINT_IMAGE 1497
#define PRINT_FILE 1498
#define PRINT 1499
#define RIGHT 1500
#define DOUBLE_COLON 1501
#define SEMICOLON 1502
#define SLEEP 1503
#define TUPLE 1504
#define UNION 1505
#define WHERE 1507
#define WHILE 1508
#define WHITE 1509
#define CCODE 1510
#define ANSI 1511
#define BLUE 1512
#define BOLD 1513
#define BYTE 1514
#define FCALL 1515
#define CASE 1516
#define CYAN 1517
#define DATE 1518
#define DESC 1519
#define KWDOWN 1521
#define TAB 1522
#define DROP 1523
#define ELSE 1524
#define EXEC 1525
#define EXIT 1526
#define FREE 1527
#define FROM 1528
#define GOTO 1529
#define HELP_FILE 1530
#define LANG_FILE 1531
#define HELP 1532
#define HIDE 1533
#define HOUR 1534
#define INTO 1535
#define LAST 1536
#define LEFT 1537
#define LIKE 1538
#define MAIN 1539
#define MENU 1540
#define MODE 1541
#define NEED 1542
#define NEXT 1543
#define NOCR 1544
#define OPEN 1545
#define QUIT 1546
#define REAL 1547
#define ROWS 1548
#define SHOW 1549
#define SIZE 1550
#define SKIP 1551
#define SOME 1552
#define STEP 1553
#define STOP 1554
#define TEMP 1555
#define TEXT 1556
#define THEN 1557
#define USER 1558
#define WAIT 1559
#define WHEN 1560
#define WITH 1561
#define WORK 1562
#define YEAR 1563
#define KW_IS 1565
#define XSET 1566
#define ADD 1567
#define ALL 1568
#define ANY 1570
#define ASC 1571
#define AVG 1572
#define COLON 1573
#define DAY 1575
#define DBA 1576
#define DEC 1577
#define DIM 1578
#define FKEY 1579
#define FOR 1580
#define KEY 1581
#define KWNO 1582
#define LET 1583
#define LOG 1584
#define XMAX 1585
#define XMIN 1586
#define PAD 1590
#define PUT 1591
#define RED 1592
#define ROW 1593
#define RUN 1594
#define SQL 1595
#define SUM 1596
#define TOP 1597
#define USE 1598
#define ATSIGN 1599
#define AS_TIFF 1601
#define AS_GIF 1602
#define AS_PNG 1603
#define AS_JPEG 1604
#define AS 1605
#define AT 1606
#define BY 1607
#define DOT 1608
#define GO 1609
#define IF 1610
#define IN 1611
#define OF 1612
#define ON 1613
#define TO 1615
#define KWUP 1616
#define FONT_NAME 1617
#define FONT_SIZE 1618
#define PAPER_SIZE_IS_LETTER 1619
#define PAPER_SIZE_IS_LEGAL 1620
#define PAPER_SIZE_IS_A5 1621
#define PAPER_SIZE_IS_A4 1622
#define PAPER_SIZE_IS_LETTER_L 1623
#define PAPER_SIZE_IS_LEGAL_L 1624
#define PAPER_SIZE_IS_A5_L 1625
#define PAPER_SIZE_IS_A4_L 1626
#define FORMHANDLER 1627
#define END_FORMHANDLER 1628
#define BEFORE_EVENT 1629
#define BEFORE_OPEN_FORM 1630
#define AFTER_EVENT 1631
#define BEFORE_CLOSE_FORM 1632
#define BEFORE_ANY 1633
#define AFTER_ANY 1634
#define MENUHANDLER 1635
#define END_MENUHANDLER 1636
#define BEFORE_SHOW_MENU 1637
#define DISABLE_PROGRAM 1638
#define DISABLE_ALL 1639
#define BUTTONS 1640
#define CHECK_MENUITEM 1641
#define DISABLE_FORM 1642
#define DISABLE_MENUITEMS 1643
#define DISABLE 1644
#define ENABLE_FORM 1645
#define ENABLE_MENUITEMS 1646
#define ENABLE 1647
#define KWFIELD 1648
#define ICON 1649
#define MESSAGEBOX 1650
#define TO_DEFAULTS 1651
#define UNCHECK_MENUITEM 1652
#define BEFORE 1653
#define INPUT 1654
#define END 1655
#define INT_TO_ID 1656
#define TIMEOUT 1657
#define OFF 1658
#define WITH_1_DIMENSION 1659
#define WITH_2_DIMENSION 1660
#define WITH_3_DIMENSION 1661
#define TILDE 1662
#define ILIKE 1663
#define FGL_ISDYNARR_ALLOCATED 1664
#define FGL_DYNARR_EXTENTSIZE 1665




/* Copy the first part of user declarations.  */
#line 66 "fgl.yacc"


/*
=====================================================================
                    Constants definitions
=====================================================================
*/


#ifdef YYPURE
#undef YYPURE
#endif
#define YYPURE 1
#define YYLEX_PARAM yystate,yyssa,yyssp
#define INCASE 		0
#define INCONSTRUCT 1
#define INDISPLAY 	2
#define INFOR 		3
#define INFOREACH 	4
#define ININPUT 	5
#define INMENU 		6
#define INPROMPT 	7
#define INWHILE 	8
#define INIF 		9

#define UPDCOL 		0
#define UPDVAL 		1
#define SELINTO 	2
#define PUTVAL 		3
#define UPDVAL2 	4

// Hehe - This one is pretty cool if you have a fairly recent version of bison
#define YYERROR_VERBOSE

#define YYDEBUG 1


/* prevent warning for redundant declaration of yyparse: */
#define _BISON_SIMPLE_INCL_

#define _NO_Y_TAB_H_
#define _NO_WINDOWS_H_

/*
=====================================================================
		                    Includes
=====================================================================
*/

#include "a4gl_4glc_int.h"
#include "variables.h"

/*
=====================================================================
		                    Variables definitions
=====================================================================
*/

extern int 	lineno;
extern int 	read_glob_var;
extern int 	modlevel;
extern int 	charno;
extern int 	last_var_found;
extern int 	varcnt;
extern int 	in_record;
extern int 	rep_type;
extern int 	yylineno;
extern int compiling_system_4gl;

int sql_mode=0;

char 		menuhandler[256];
char 		last_var [256];
char 		larr[4096]="";
char 		larr2[4096]="";
char 		clobber[64]="";
char 		dtypelist[2048];
char 		curr_func[256]="Module";
char 		where_having[1024];
char		menu[2048];
char 		varstring[100];
char 		infilename[132]="";
char 		hdr_dbname[64]="";
char 		current_upd_table[64]="";

int 		is_schema=0;
int 		in_define=0;
int 		rordcnt;
int 		racnt=0;
int 		ccode=0;
int 		errbomb=0;
int 		glob_only=0;
int 		inp_flags=0;
int 		lcnt;
int 		vcnt;
int 		rcnt;
int 		lastlineno=0;
int 		cnt;
int 		mcnt=0;
int 		inrec=0;
int 		iskey=0;
int 		insql=0;
int 		menu_cnt=0;
int 		chk4var=0;
int 		menu_cmd_cnt[20]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
int 		menu_blk[20]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
int 		in_sql=0;
int 		continue_cmd[]={0,1,1,1,1,1,1,1,1,0};
int 		in_cmd[]={0,0,0,0,0,0,0,0,0,0};
int 		fcall_cnt=0;
int 		doing_declare=0;
int 		message_cnt=0;

struct 		rep_structure rep_struct;
struct 		pdf_rep_structure pdf_rep_struct;
struct 		form_attr form_attrib;
char *		make_sql_string(char *first,...);
void copy_gen (int a, int b);
char *get_namespace (char *s);
void set_yytext (char *s);
int isin_command (char *cmd_type);
int a4gl_yylex (void *pyylval, int yystate, void *yys1, void *yys2);
char *do_clobbering(char *f,char *s);
struct input_array_attribs curr_input_array_attribs;

int if_print_stack[100][2];
int if_print_stack_cnt=0;
int if_print_section[100]={0,0,0,0};

#include "../generic.h"


/*
=====================================================================
                    Functions prototypes
=====================================================================
*/




/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

#if ! defined (YYSTYPE) && ! defined (YYSTYPE_IS_DECLARED)
#line 210 "fgl.yacc"
typedef union YYSTYPE {



	//char	str[3100];  /* This would core dump in CygWin on call to */
	char	str[1024];  /* This would core dump in CygWin on call to */
						/* yyparse in y.tab.c - 3100 in maximum. */
						/* Was: char	str[20000]; */

	struct expr_str *ptr;
	char *sql_string;
	struct generic_entry_list *list;
	struct generic_entry *entry;
	struct generic_entry_ident *ident;
	struct generic_entry_variable *variable;
	struct generic_entry_literal *literal;
	int 	integer_val;
	float 	float_val;
	} YYSTYPE;
/* Line 191 of yacc.c.  */
#line 1605 "y.tab.c"
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 214 of yacc.c.  */
#line 1617 "y.tab.c"

#if ! defined (yyoverflow) || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# if YYSTACK_USE_ALLOCA
#  define YYSTACK_ALLOC alloca
# else
#  ifndef YYSTACK_USE_ALLOCA
#   if defined (alloca) || defined (_ALLOCA_H)
#    define YYSTACK_ALLOC alloca
#   else
#    ifdef __GNUC__
#     define YYSTACK_ALLOC __builtin_alloca
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning. */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
# else
#  if defined (__STDC__) || defined (__cplusplus)
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   define YYSIZE_T size_t
#  endif
#  define YYSTACK_ALLOC malloc
#  define YYSTACK_FREE free
# endif
#endif /* ! defined (yyoverflow) || YYERROR_VERBOSE */


#if (! defined (yyoverflow) \
     && (! defined (__cplusplus) \
	 || (YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  short yyss;
  YYSTYPE yyvs;
  };

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (short) + sizeof (YYSTYPE))				\
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  register YYSIZE_T yyi;		\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (0)
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack)					\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack, Stack, yysize);				\
	Stack = &yyptr->Stack;						\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (0)

#endif

#if defined (__STDC__) || defined (__cplusplus)
   typedef signed char yysigned_char;
#else
   typedef short yysigned_char;
#endif

/* YYFINAL -- State number of the termination state. */
#define YYFINAL  67
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   10154

/* YYNTOKENS -- Number of terminals. */
#define YYNTOKENS  681
/* YYNNTS -- Number of nonterminals. */
#define YYNNTS  839
/* YYNRULES -- Number of rules. */
#define YYNRULES  2252
/* YYNRULES -- Number of states. */
#define YYNSTATES  3542

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   1678

#define YYTRANSLATE(YYX) 						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const unsigned short yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    93,
      94,    95,    96,    97,    98,    99,   100,   101,   102,   103,
     104,   105,   106,   107,   108,   109,   110,   111,   112,   113,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   131,   132,   133,
     134,   135,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,   146,   147,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
     174,   175,   176,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   192,   193,
     194,   195,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,   256,   257,   258,   259,   260,   261,   262,   263,
     264,   265,   266,   267,   268,   269,   270,   271,   272,   273,
     274,   275,   276,   277,   278,   279,   280,   281,   282,   283,
     284,   285,   286,   287,   288,   289,   290,   291,   292,   293,
     294,   295,   296,   297,   298,   299,   300,   301,   302,   303,
     304,   305,   306,   307,   308,   309,   310,   311,   312,   313,
     314,   315,   316,   317,   318,   319,   320,   321,   322,   323,
     324,   325,   326,   327,   328,   329,   330,   331,   332,   333,
     334,    15,   335,   336,   337,   338,   339,   340,   341,   342,
     343,   344,   345,   346,   347,   348,   349,   350,   351,   352,
     353,   354,   355,   356,   357,   358,   359,   360,   361,   362,
     363,   364,   365,   366,   367,   368,   369,   370,   371,   372,
     373,   374,   375,   376,   377,   378,   379,   380,   381,   382,
     383,   384,   385,   386,   387,   388,   389,   390,   391,   392,
      16,   393,   394,   395,   396,   397,   398,    23,   399,   400,
     401,   402,   403,   404,   405,   406,   407,   408,   409,   410,
     411,   412,   413,   414,   415,    10,   416,   417,   418,   419,
     420,   421,   422,   423,   424,   425,   426,   427,   428,   429,
     430,   431,   432,    13,   433,   434,   435,   436,   437,   438,
     439,   440,   441,   442,   443,   444,   445,   446,   447,   448,
     449,   450,   451,   452,   453,   454,   455,   456,   457,   458,
     459,   460,   461,   462,    17,   463,   464,   465,   466,   467,
     468,   469,   470,   471,   472,   473,   474,   475,   476,   477,
     478,   479,   480,   481,   482,   483,   484,   485,   486,   487,
     488,   489,   490,   491,   492,   493,   494,   495,   496,   497,
     498,   499,   500,   501,   502,   503,   504,   505,   506,   507,
     508,   509,   510,   511,   512,   513,   514,   515,    12,   516,
     517,   518,    11,    20,   519,   520,   521,   522,   523,   524,
     525,   526,   527,   528,   529,   530,     8,   531,   532,   533,
     534,   535,   536,   537,   538,   539,   540,   541,   542,   543,
      21,   544,   545,   546,   547,   548,   549,   550,   551,   552,
     553,   554,   555,   556,   557,   558,   559,   560,   561,   562,
     563,   564,   565,   566,   567,   568,   569,   570,   571,   572,
     573,   574,   575,   576,   577,   578,   579,   580,   581,   582,
     583,   584,   585,   586,    14,   587,   588,   589,   590,     7,
     591,   592,   593,   594,     5,   595,   596,   597,   598,   599,
     600,   601,   602,   603,   604,   605,   606,    19,    22,     9,
     607,   608,   609,   610,   611,   612,   613,   614,   615,   616,
      18,   617,   618,   619,   620,   621,   622,   623,   624,   625,
     626,   627,   628,   629,     6,   630,   631,   632,   633,   634,
     635,   636,   637,   638,   639,   640,   641,   642,   643,   644,
     645,   646,   647,   648,   649,   650,   651,   652,   653,   654,
     655,   656,   657,   658,   659,   660,   661,   662,   663,   664,
     665,   666,   667,   668,   669,   670,   671,   672,   673,   674,
     675,   676,   677,   678,   679,   680,     2,     3,     4,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const unsigned short yyprhs[] =
{
       0,     0,     3,     5,     7,    13,    15,    17,    19,    21,
      25,    27,    31,    35,    37,    40,    42,    44,    46,    48,
      50,    52,    54,    56,    58,    59,    61,    62,    68,    75,
      77,    81,    83,    85,    87,    89,    91,    93,    95,    97,
      99,   101,   103,   105,   107,   109,   111,   113,   115,   116,
     118,   119,   125,   127,   131,   133,   135,   138,   141,   144,
     147,   150,   153,   156,   159,   163,   164,   172,   181,   188,
     190,   197,   198,   199,   209,   210,   211,   212,   221,   222,
     223,   234,   235,   236,   246,   247,   248,   249,   264,   265,
     268,   269,   272,   274,   275,   277,   279,   283,   285,   287,
     289,   291,   295,   296,   303,   304,   310,   312,   315,   317,
     320,   322,   323,   324,   328,   329,   330,   334,   335,   340,
     341,   346,   349,   352,   355,   357,   360,   363,   367,   369,
     371,   373,   376,   378,   380,   383,   385,   387,   388,   389,
     395,   403,   412,   413,   416,   418,   422,   424,   428,   432,
     434,   437,   438,   443,   444,   449,   450,   454,   455,   459,
     460,   464,   466,   470,   472,   476,   478,   480,   482,   484,
     486,   488,   493,   494,   499,   501,   503,   504,   506,   508,
     511,   512,   513,   519,   521,   523,   525,   529,   530,   533,
     538,   543,   548,   553,   556,   557,   562,   564,   566,   568,
     571,   573,   575,   579,   580,   582,   583,   585,   587,   589,
     590,   598,   599,   605,   606,   619,   621,   623,   625,   627,
     629,   635,   639,   641,   643,   644,   649,   650,   656,   657,
     665,   667,   671,   673,   675,   676,   678,   679,   680,   685,
     687,   689,   691,   696,   701,   708,   710,   713,   715,   717,
     719,   721,   726,   733,   735,   740,   747,   749,   751,   753,
     755,   757,   759,   761,   764,   767,   769,   771,   776,   778,
     780,   781,   785,   789,   790,   793,   795,   797,   799,   801,
     803,   805,   808,   809,   812,   813,   817,   818,   822,   824,
     825,   829,   831,   833,   835,   837,   839,   841,   844,   846,
     847,   849,   850,   856,   858,   860,   862,   867,   872,   879,
     881,   883,   885,   887,   892,   899,   901,   906,   913,   915,
     917,   919,   921,   923,   926,   929,   931,   936,   937,   945,
     946,   959,   960,   965,   966,   972,   974,   978,   981,   983,
     987,   989,   990,   993,   996,   998,  1001,  1007,  1012,  1015,
    1020,  1026,  1030,  1031,  1032,  1044,  1045,  1048,  1050,  1051,
    1054,  1056,  1058,  1061,  1062,  1066,  1067,  1071,  1072,  1076,
    1079,  1082,  1085,  1090,  1096,  1098,  1100,  1102,  1104,  1106,
    1108,  1110,  1112,  1114,  1116,  1118,  1120,  1122,  1124,  1126,
    1128,  1130,  1132,  1135,  1137,  1139,  1141,  1143,  1146,  1148,
    1150,  1152,  1155,  1158,  1160,  1162,  1164,  1166,  1168,  1170,
    1172,  1174,  1176,  1178,  1181,  1183,  1186,  1188,  1190,  1192,
    1196,  1198,  1202,  1204,  1208,  1210,  1212,  1214,  1217,  1219,
    1221,  1225,  1230,  1235,  1238,  1241,  1243,  1245,  1247,  1249,
    1251,  1255,  1257,  1260,  1263,  1265,  1266,  1270,  1273,  1276,
    1278,  1282,  1287,  1292,  1298,  1304,  1306,  1308,  1311,  1314,
    1319,  1324,  1327,  1330,  1335,  1340,  1342,  1345,  1348,  1351,
    1354,  1357,  1360,  1363,  1366,  1369,  1372,  1375,  1378,  1381,
    1384,  1385,  1386,  1387,  1394,  1395,  1396,  1405,  1406,  1407,
    1414,  1415,  1416,  1423,  1424,  1425,  1432,  1433,  1434,  1441,
    1447,  1453,  1459,  1467,  1472,  1479,  1480,  1484,  1486,  1488,
    1493,  1498,  1503,  1508,  1513,  1518,  1520,  1522,  1524,  1526,
    1531,  1536,  1539,  1542,  1545,  1548,  1551,  1553,  1555,  1558,
    1560,  1562,  1564,  1567,  1572,  1579,  1586,  1590,  1596,  1602,
    1606,  1608,  1610,  1614,  1616,  1620,  1621,  1622,  1634,  1635,
    1638,  1639,  1640,  1641,  1651,  1652,  1656,  1657,  1658,  1669,
    1670,  1672,  1673,  1675,  1677,  1680,  1681,  1685,  1686,  1690,
    1691,  1693,  1695,  1698,  1699,  1703,  1704,  1708,  1712,  1714,
    1719,  1723,  1725,  1729,  1731,  1735,  1737,  1741,  1743,  1746,
    1747,  1751,  1752,  1756,  1757,  1762,  1763,  1768,  1769,  1774,
    1777,  1781,  1783,  1787,  1789,  1791,  1793,  1795,  1797,  1799,
    1801,  1805,  1807,  1809,  1814,  1821,  1826,  1830,  1837,  1841,
    1848,  1850,  1852,  1854,  1856,  1858,  1860,  1861,  1864,  1866,
    1868,  1870,  1875,  1877,  1879,  1881,  1886,  1890,  1897,  1901,
    1908,  1910,  1912,  1915,  1918,  1921,  1923,  1927,  1929,  1932,
    1935,  1938,  1943,  1946,  1949,  1954,  1955,  1964,  1965,  1967,
    1969,  1971,  1972,  1974,  1977,  1978,  1980,  1983,  1984,  1986,
    1989,  1990,  1992,  1996,  1997,  2000,  2001,  2002,  2011,  2012,
    2013,  2017,  2018,  2019,  2027,  2033,  2036,  2039,  2040,  2046,
    2051,  2053,  2057,  2061,  2065,  2066,  2069,  2071,  2072,  2074,
    2076,  2079,  2080,  2085,  2086,  2091,  2092,  2096,  2097,  2101,
    2102,  2106,  2107,  2111,  2112,  2116,  2117,  2121,  2122,  2126,
    2127,  2131,  2132,  2136,  2138,  2142,  2144,  2148,  2151,  2156,
    2158,  2160,  2162,  2163,  2168,  2174,  2181,  2182,  2193,  2197,
    2200,  2203,  2205,  2207,  2208,  2211,  2213,  2216,  2220,  2224,
    2228,  2232,  2234,  2236,  2238,  2240,  2241,  2245,  2247,  2248,
    2252,  2255,  2258,  2260,  2264,  2266,  2270,  2272,  2274,  2276,
    2278,  2280,  2282,  2284,  2286,  2288,  2290,  2292,  2294,  2296,
    2298,  2300,  2302,  2304,  2306,  2308,  2310,  2311,  2312,  2320,
    2322,  2324,  2327,  2330,  2333,  2337,  2342,  2343,  2347,  2348,
    2350,  2352,  2355,  2357,  2359,  2361,  2363,  2364,  2366,  2368,
    2371,  2374,  2376,  2378,  2380,  2382,  2384,  2386,  2388,  2390,
    2392,  2394,  2396,  2398,  2400,  2401,  2403,  2405,  2407,  2409,
    2411,  2412,  2413,  2414,  2415,  2429,  2431,  2432,  2433,  2440,
    2443,  2445,  2448,  2451,  2454,  2456,  2458,  2461,  2463,  2465,
    2467,  2468,  2472,  2475,  2477,  2478,  2479,  2480,  2495,  2496,
    2502,  2504,  2505,  2509,  2510,  2518,  2519,  2525,  2527,  2530,
    2531,  2533,  2535,  2537,  2538,  2540,  2542,  2545,  2548,  2551,
    2553,  2555,  2557,  2559,  2563,  2565,  2567,  2568,  2569,  2577,
    2579,  2582,  2583,  2587,  2588,  2593,  2596,  2597,  2600,  2602,
    2604,  2606,  2608,  2610,  2612,  2614,  2618,  2619,  2621,  2623,
    2625,  2627,  2630,  2633,  2636,  2642,  2651,  2653,  2655,  2657,
    2662,  2667,  2669,  2671,  2673,  2675,  2678,  2681,  2685,  2692,
    2694,  2698,  2700,  2702,  2704,  2708,  2715,  2725,  2727,  2729,
    2731,  2733,  2736,  2737,  2739,  2741,  2745,  2747,  2751,  2753,
    2757,  2759,  2763,  2765,  2767,  2769,  2771,  2775,  2777,  2781,
    2783,  2787,  2789,  2791,  2793,  2797,  2800,  2801,  2803,  2805,
    2810,  2812,  2816,  2818,  2822,  2830,  2831,  2839,  2840,  2847,
    2851,  2853,  2857,  2859,  2862,  2868,  2869,  2877,  2878,  2881,
    2882,  2884,  2890,  2893,  2899,  2900,  2906,  2913,  2918,  2919,
    2921,  2923,  2928,  2929,  2932,  2933,  2939,  2944,  2947,  2949,
    2953,  2956,  2959,  2962,  2965,  2968,  2971,  2973,  2976,  2979,
    2982,  2985,  2988,  2991,  2994,  2997,  3000,  3002,  3004,  3006,
    3008,  3010,  3012,  3018,  3020,  3022,  3025,  3030,  3033,  3035,
    3036,  3048,  3049,  3052,  3058,  3059,  3061,  3062,  3065,  3067,
    3070,  3071,  3075,  3077,  3078,  3083,  3084,  3087,  3089,  3093,
    3095,  3097,  3101,  3106,  3111,  3114,  3116,  3118,  3120,  3121,
    3123,  3131,  3134,  3137,  3140,  3143,  3146,  3148,  3151,  3152,
    3156,  3157,  3161,  3162,  3166,  3167,  3171,  3172,  3176,  3177,
    3182,  3183,  3188,  3190,  3192,  3194,  3196,  3198,  3200,  3201,
    3206,  3207,  3209,  3210,  3215,  3217,  3220,  3223,  3226,  3227,
    3229,  3231,  3234,  3237,  3238,  3241,  3245,  3249,  3255,  3256,
    3259,  3264,  3266,  3268,  3270,  3272,  3274,  3275,  3277,  3279,
    3283,  3286,  3292,  3295,  3301,  3307,  3313,  3319,  3325,  3331,
    3332,  3335,  3337,  3340,  3343,  3346,  3349,  3352,  3355,  3357,
    3360,  3363,  3366,  3369,  3371,  3374,  3377,  3380,  3383,  3385,
    3387,  3389,  3390,  3393,  3396,  3399,  3402,  3405,  3408,  3411,
    3414,  3417,  3419,  3421,  3423,  3425,  3427,  3429,  3431,  3433,
    3436,  3439,  3442,  3445,  3448,  3450,  3452,  3454,  3455,  3459,
    3462,  3463,  3464,  3465,  3466,  3467,  3468,  3484,  3485,  3488,
    3491,  3492,  3494,  3495,  3496,  3497,  3498,  3499,  3500,  3516,
    3519,  3520,  3521,  3522,  3533,  3534,  3536,  3540,  3544,  3547,
    3552,  3556,  3560,  3564,  3566,  3568,  3570,  3572,  3574,  3576,
    3577,  3578,  3586,  3587,  3588,  3597,  3601,  3604,  3605,  3607,
    3609,  3613,  3616,  3619,  3621,  3623,  3627,  3629,  3631,  3634,
    3636,  3640,  3642,  3646,  3648,  3650,  3652,  3654,  3656,  3658,
    3660,  3663,  3668,  3670,  3674,  3676,  3680,  3683,  3688,  3690,
    3694,  3696,  3699,  3704,  3706,  3710,  3712,  3714,  3716,  3719,
    3722,  3727,  3730,  3735,  3737,  3741,  3743,  3745,  3747,  3750,
    3752,  3754,  3756,  3758,  3760,  3763,  3770,  3777,  3778,  3780,
    3781,  3783,  3786,  3788,  3789,  3795,  3796,  3802,  3804,  3805,
    3809,  3811,  3815,  3817,  3821,  3823,  3825,  3826,  3827,  3833,
    3835,  3838,  3840,  3841,  3842,  3846,  3847,  3848,  3852,  3854,
    3856,  3858,  3860,  3862,  3864,  3867,  3870,  3875,  3879,  3883,
    3885,  3889,  3892,  3894,  3896,  3897,  3899,  3901,  3903,  3905,
    3906,  3908,  3912,  3914,  3918,  3920,  3921,  3925,  3927,  3929,
    3931,  3933,  3935,  3937,  3939,  3941,  3943,  3945,  3947,  3949,
    3957,  3958,  3960,  3962,  3964,  3966,  3970,  3972,  3974,  3976,
    3979,  3980,  3984,  3986,  3990,  3992,  3996,  3998,  4000,  4007,
    4008,  4012,  4014,  4018,  4019,  4021,  4026,  4032,  4035,  4037,
    4039,  4044,  4046,  4050,  4055,  4060,  4062,  4066,  4068,  4070,
    4072,  4075,  4077,  4082,  4083,  4085,  4086,  4088,  4090,  4093,
    4095,  4097,  4099,  4101,  4106,  4110,  4112,  4114,  4116,  4119,
    4121,  4123,  4126,  4129,  4131,  4135,  4138,  4141,  4143,  4147,
    4149,  4152,  4157,  4159,  4162,  4164,  4168,  4173,  4174,  4176,
    4177,  4179,  4180,  4182,  4184,  4188,  4190,  4194,  4196,  4199,
    4201,  4205,  4208,  4211,  4212,  4215,  4217,  4219,  4225,  4229,
    4235,  4239,  4241,  4245,  4247,  4249,  4250,  4252,  4256,  4260,
    4264,  4271,  4276,  4281,  4286,  4291,  4297,  4299,  4301,  4303,
    4305,  4307,  4309,  4311,  4313,  4315,  4317,  4319,  4321,  4322,
    4324,  4326,  4328,  4330,  4332,  4334,  4336,  4341,  4347,  4349,
    4355,  4361,  4363,  4365,  4367,  4372,  4374,  4379,  4381,  4389,
    4391,  4393,  4395,  4400,  4407,  4408,  4411,  4416,  4418,  4420,
    4422,  4424,  4426,  4428,  4430,  4434,  4436,  4438,  4442,  4444,
    4445,  4449,  4455,  4457,  4460,  4463,  4468,  4472,  4474,  4476,
    4478,  4480,  4482,  4484,  4487,  4490,  4491,  4495,  4496,  4500,
    4502,  4504,  4506,  4508,  4510,  4512,  4514,  4519,  4521,  4523,
    4525,  4527,  4529,  4531,  4533,  4538,  4540,  4542,  4544,  4546,
    4548,  4550,  4552,  4554,  4556,  4558,  4560,  4562,  4564,  4566,
    4571,  4573,  4577,  4579,  4583,  4584,  4592,  4593,  4602,  4603,
    4610,  4611,  4620,  4621,  4623,  4626,  4628,  4632,  4634,  4638,
    4644,  4646,  4648,  4650,  4652,  4654,  4655,  4656,  4666,  4672,
    4674,  4676,  4683,  4684,  4688,  4690,  4694,  4699,  4701,  4702,
    4705,  4710,  4717,  4718,  4720,  4722,  4724,  4726,  4730,  4732,
    4735,  4737,  4739,  4742,  4745,  4747,  4749,  4751,  4754,  4759,
    4763,  4766,  4770,  4774,  4778,  4780,  4782,  4784,  4786,  4788,
    4790,  4796,  4802,  4808,  4814,  4820,  4825,  4830,  4834,  4839,
    4841,  4845,  4847,  4853,  4861,  4867,  4868,  4871,  4873,  4875,
    4876,  4880,  4882,  4886,  4888,  4890,  4892,  4893,  4897,  4899,
    4901,  4903,  4905,  4910,  4917,  4919,  4921,  4924,  4928,  4930,
    4932,  4934,  4936,  4938,  4940,  4942,  4944,  4950,  4956,  4961,
    4962,  4967,  4969,  4972,  4974,  4976,  4978,  4980,  4982,  4984,
    4986,  4988,  4990,  4992,  4994,  4996,  4998,  5000,  5002,  5004,
    5006,  5008,  5010,  5012,  5014,  5016,  5018,  5020,  5022,  5024,
    5026,  5028,  5030,  5032,  5034,  5036,  5038,  5040,  5042,  5044,
    5046,  5048,  5050,  5052,  5054,  5056,  5058,  5060,  5062,  5064,
    5066,  5068,  5070,  5072,  5074,  5076,  5078,  5080,  5082,  5084,
    5086,  5088,  5090,  5092,  5094,  5096,  5098,  5100,  5102,  5104,
    5106,  5108,  5110,  5112,  5114,  5116,  5118,  5120,  5122,  5124,
    5126,  5128,  5130,  5132,  5134,  5136,  5138,  5140,  5142,  5144,
    5146,  5148,  5150,  5152,  5154,  5156,  5158,  5160,  5162,  5164,
    5166,  5168,  5170,  5172,  5174,  5176,  5178,  5180,  5182,  5184,
    5186,  5188,  5190,  5192,  5194,  5196,  5198,  5200,  5202,  5204,
    5206,  5208,  5210,  5212,  5214,  5216,  5218,  5220,  5222,  5224,
    5226,  5228,  5230,  5232,  5234,  5236,  5238,  5240,  5242,  5244,
    5246,  5248,  5250,  5252,  5254,  5256,  5258,  5260,  5262,  5264,
    5266,  5268,  5270,  5272,  5274,  5276,  5278,  5280,  5282,  5284,
    5286,  5288,  5290,  5292,  5294,  5296,  5298,  5300,  5302,  5304,
    5306,  5308,  5310,  5312,  5314,  5316,  5318,  5320,  5322,  5324,
    5326,  5328,  5330,  5332,  5334,  5336,  5338,  5340,  5342,  5344,
    5346,  5348,  5350,  5352,  5354,  5356,  5358,  5360,  5362,  5364,
    5366,  5368,  5370,  5372,  5374,  5376,  5378,  5380,  5382,  5384,
    5386,  5388,  5390,  5392,  5394,  5396,  5398,  5400,  5402,  5404,
    5406,  5408,  5410,  5412,  5414,  5416,  5418,  5420,  5422,  5424,
    5426,  5428,  5430,  5432,  5434,  5436,  5438,  5440,  5442,  5444,
    5446,  5448,  5450,  5452,  5454,  5456,  5458,  5460,  5462,  5464,
    5466,  5468,  5470,  5472,  5474,  5476,  5478,  5480,  5482,  5484,
    5486,  5488,  5490,  5492,  5494,  5496,  5498,  5500,  5502,  5504,
    5506,  5508,  5510,  5512,  5514,  5516,  5518,  5520,  5522,  5524,
    5526,  5528,  5530,  5532,  5534,  5536,  5538,  5540,  5542,  5544,
    5546,  5548,  5550,  5552,  5554,  5556,  5558,  5560,  5562,  5564,
    5566,  5568,  5570,  5572,  5574,  5576,  5578,  5580,  5582,  5584,
    5586,  5588,  5590,  5592,  5594,  5596,  5598,  5600,  5602,  5604,
    5606,  5608,  5610,  5612,  5614,  5616,  5617,  5621,  5622,  5626,
    5627,  5628,  5635,  5636,  5639,  5642,  5650,  5654,  5658,  5661,
    5664,  5667,  5669,  5673,  5675,  5679,  5681,  5685,  5687,  5691,
    5693,  5695,  5697,  5700,  5703,  5705,  5707,  5710,  5715,  5717,
    5719,  5721,  5723,  5725,  5727,  5731,  5734,  5738,  5742,  5746,
    5752,  5758,  5764,  5770,  5776,  5781,  5786,  5790,  5795,  5797,
    5799,  5803,  5804,  5810,  5812,  5816,  5820,  5824,  5826,  5829,
    5831,  5833,  5835,  5839,  5845,  5847,  5849,  5851,  5853,  5857,
    5860,  5863,  5866,  5868,  5871,  5874,  5876,  5879,  5882,  5885,
    5887,  5891,  5894,  5896,  5899,  5901,  5904,  5906,  5907,  5908,
    5915,  5916,  5919,  5920,  5922,  5924,  5927,  5930,  5932,  5934,
    5939,  5943,  5945,  5949,  5951,  5954,  5960,  5963,  5966,  5972,
    5973,  5976,  5978,  5980,  5983,  5990,  5997,  5999,  6000,  6002,
    6005,  6007,  6010,  6011,  6014,  6016,  6018,  6020,  6022,  6024,
    6026,  6028,  6030,  6032,  6034,  6036,  6038,  6040,  6042,  6044,
    6046,  6048,  6050,  6052,  6054,  6056,  6058,  6060,  6062,  6064,
    6066,  6068,  6070,  6072,  6074,  6076,  6078,  6080,  6082,  6084,
    6086,  6088,  6090,  6092,  6094,  6096,  6098,  6100,  6102,  6104,
    6106,  6108,  6110,  6112,  6114,  6116,  6118,  6120,  6122,  6124,
    6126,  6128,  6130,  6132,  6134,  6136,  6138,  6140,  6142,  6144,
    6146,  6148,  6150,  6152,  6154,  6156,  6158,  6160,  6162,  6164,
    6166,  6168,  6170,  6172,  6174,  6176,  6178,  6180,  6182,  6184,
    6186,  6188,  6190
};

/* YYRHS -- A `-1'-separated list of the rules' RHS. */
static const short yyrhs[] =
{
    1044,     0,    -1,   205,    -1,   202,    -1,   129,   686,   432,
     600,   687,    -1,   143,    -1,  1109,    -1,    26,    -1,   688,
      -1,   687,     5,   688,    -1,   956,    -1,   436,   689,   397,
      -1,   689,   690,   689,    -1,    26,    -1,   691,    26,    -1,
    1109,    -1,   898,    -1,    18,    -1,    19,    -1,    20,    -1,
      21,    -1,    22,    -1,    18,    -1,    19,    -1,    -1,   693,
      -1,    -1,   279,   436,   694,   695,   397,    -1,   573,   436,
      26,     5,    26,   397,    -1,   696,    -1,   695,     5,   696,
      -1,   495,    -1,   536,    -1,   541,    -1,   511,    -1,   415,
      -1,   609,    -1,   533,    -1,   485,    -1,   422,    -1,   496,
      -1,   350,    -1,   537,    -1,   461,    -1,   337,    -1,   598,
      -1,   103,    -1,  1023,    -1,    -1,   698,    -1,    -1,   279,
     436,   699,   700,   397,    -1,   701,    -1,   700,     5,   701,
      -1,   696,    -1,   437,    -1,   607,    25,    -1,   208,   943,
      -1,   334,   943,    -1,   289,   943,    -1,   342,   943,    -1,
     298,   943,    -1,   264,   943,    -1,   539,   703,    -1,   887,
     349,  1109,    -1,    -1,   294,   436,  1504,   397,   349,   704,
    1128,    -1,   109,   436,   956,     5,    25,     5,    25,   397,
      -1,   412,   436,   948,   397,   349,  1109,    -1,  1247,    -1,
     197,   436,   906,   397,   349,  1109,    -1,    -1,    -1,  1109,
     594,   956,   436,   705,   719,   397,   706,   717,    -1,    -1,
      -1,    -1,   956,   436,   707,   719,   708,   397,   709,   717,
      -1,    -1,    -1,   479,  1445,   627,  1445,   436,   710,   719,
     711,   397,   717,    -1,    -1,    -1,   956,   526,   956,   436,
     712,   719,   713,   397,   717,    -1,    -1,    -1,    -1,   370,
     722,   594,   723,   464,   686,   432,   436,   714,   719,   715,
     397,   716,   718,    -1,    -1,   349,  1128,    -1,    -1,   349,
    1128,    -1,   167,    -1,    -1,   720,    -1,   721,    -1,   720,
       5,   721,    -1,   856,    -1,    25,    -1,   956,    -1,   956,
      -1,   956,   624,   956,    -1,    -1,   540,   863,   725,   728,
     732,   729,    -1,    -1,   540,   726,   727,   730,   729,    -1,
     734,    -1,   727,   734,    -1,   736,    -1,   728,   736,    -1,
     365,    -1,    -1,    -1,   344,   731,  1514,    -1,    -1,    -1,
     344,   733,  1514,    -1,    -1,   583,   863,   735,  1514,    -1,
      -1,   583,   863,   737,  1514,    -1,   283,   953,    -1,   207,
     951,    -1,    88,   951,    -1,   173,    -1,   190,  1451,    -1,
     499,   950,    -1,    30,   740,    31,    -1,   741,    -1,   743,
      -1,   742,    -1,   741,   742,    -1,    29,    -1,   744,    -1,
     743,   744,    -1,    28,    -1,   399,    -1,    -1,    -1,   325,
     747,   749,   748,   750,    -1,   390,  1109,   629,   751,   997,
    1022,   692,    -1,  1109,   629,   751,   997,   551,  1504,  1022,
     692,    -1,    -1,   753,   196,    -1,   752,    -1,   751,     5,
     752,    -1,   956,    -1,   956,   624,   956,    -1,   956,   624,
      20,    -1,   754,    -1,   753,   754,    -1,    -1,   275,   760,
     755,  1514,    -1,    -1,   278,   761,   756,  1514,    -1,    -1,
    1025,   757,  1514,    -1,    -1,   171,   758,  1514,    -1,    -1,
     168,   759,  1514,    -1,   960,    -1,   760,     5,   960,    -1,
     960,    -1,   761,     5,   960,    -1,    97,    -1,    98,    -1,
      99,    -1,   100,    -1,   101,    -1,   102,    -1,   436,   856,
     764,   397,    -1,    -1,     5,   807,   630,   810,    -1,   160,
      -1,   284,    -1,    -1,   767,    -1,   768,    -1,   767,   768,
      -1,    -1,    -1,   443,   769,   771,   770,  1216,    -1,   820,
      -1,  1494,    -1,   774,    -1,   771,     5,   774,    -1,    -1,
     773,   956,    -1,   358,   772,   819,    25,    -1,   358,   772,
     819,   956,    -1,   358,   772,   819,   962,    -1,   358,   772,
     819,    26,    -1,   778,   796,    -1,    -1,   772,   358,   775,
     776,    -1,    26,    -1,    25,    -1,   962,    -1,    19,    26,
      -1,   772,    -1,   777,    -1,   778,     5,   777,    -1,    -1,
     324,    -1,    -1,   674,    -1,   675,    -1,   676,    -1,    -1,
     492,   464,   788,   432,   782,   628,   796,    -1,    -1,    34,
     780,   783,   628,   796,    -1,    -1,   323,   779,   785,    26,
     786,   307,   464,   787,   432,   784,   628,   796,    -1,   436,
      -1,   463,    -1,   397,    -1,   431,    -1,    26,    -1,   789,
       5,   789,     5,   789,    -1,   789,     5,   789,    -1,   789,
      -1,    26,    -1,    -1,   469,   791,   771,   288,    -1,    -1,
     265,   792,   772,   624,    20,    -1,    -1,   339,   793,   772,
     263,   436,   794,   397,    -1,   795,    -1,   794,     5,   795,
      -1,   772,    -1,   798,    -1,    -1,    63,    -1,    -1,    -1,
     799,   801,   800,   797,    -1,   781,    -1,   790,    -1,   324,
      -1,   324,   436,    26,   397,    -1,   429,   436,    26,   397,
      -1,   429,   436,    26,     5,    26,   397,    -1,   413,    -1,
     621,   772,    -1,   385,    -1,   514,    -1,    94,    -1,   403,
      -1,   403,   436,    26,   397,    -1,   403,   436,    26,     5,
      26,   397,    -1,   517,    -1,   517,   436,    26,   397,    -1,
     517,   436,    26,     5,    26,   397,    -1,   507,    -1,   304,
      -1,   542,    -1,   538,    -1,    84,    -1,    85,    -1,   579,
      -1,   362,   805,    -1,   374,   806,    -1,   802,    -1,    32,
      -1,   561,   803,   624,   804,    -1,   772,    -1,   772,    -1,
      -1,   807,   630,   810,    -1,   815,   630,   818,    -1,    -1,
     808,   809,    -1,   586,    -1,   518,    -1,   595,    -1,   557,
      -1,   459,    -1,   475,    -1,   371,   812,    -1,    -1,   811,
     809,    -1,    -1,   436,   814,   397,    -1,    -1,   436,    26,
     397,    -1,    26,    -1,    -1,   816,   817,   813,    -1,   586,
      -1,   518,    -1,   595,    -1,   557,    -1,   459,    -1,   475,
      -1,   371,   812,    -1,   817,    -1,    -1,    14,    -1,    -1,
     241,   956,   821,   621,   822,    -1,   824,    -1,   827,    -1,
     324,    -1,   324,   436,    26,   397,    -1,   429,   436,    26,
     397,    -1,   429,   436,    26,     5,    26,   397,    -1,   413,
      -1,   385,    -1,   514,    -1,   403,    -1,   403,   436,    26,
     397,    -1,   403,   436,    26,     5,    26,   397,    -1,   517,
      -1,   517,   436,    26,   397,    -1,   517,   436,    26,     5,
      26,   397,    -1,   507,    -1,   304,    -1,   542,    -1,   538,
      -1,   579,    -1,   362,   805,    -1,   374,   806,    -1,   823,
      -1,   561,   803,   624,   804,    -1,    -1,   492,   464,   788,
     432,   825,   628,   822,    -1,    -1,   323,   779,   785,    26,
     786,   307,   464,   787,   432,   826,   628,   822,    -1,    -1,
     469,   828,   830,   288,    -1,    -1,   265,   829,   956,   624,
      20,    -1,   831,    -1,   830,     5,   831,    -1,   832,   822,
      -1,   833,    -1,   832,     5,   833,    -1,   956,    -1,    -1,
     622,   947,    -1,    75,   956,    -1,    73,    -1,   630,  1504,
      -1,   630,   514,   956,   663,  1504,    -1,   630,   514,   956,
     395,    -1,    77,   956,    -1,   161,   881,  1128,   842,    -1,
     406,   881,   861,   834,   842,    -1,   214,   953,   842,    -1,
      -1,    -1,   193,   839,  1135,   630,   956,   624,    20,   841,
     692,   840,   843,    -1,    -1,   473,   948,    -1,   692,    -1,
      -1,   844,   243,    -1,   243,    -1,   845,    -1,   844,   845,
      -1,    -1,   356,   846,  1514,    -1,    -1,   352,   847,  1514,
      -1,    -1,  1025,   848,  1514,    -1,    36,  1109,    -1,    37,
    1109,    -1,    35,  1109,    -1,   503,   881,   862,   692,    -1,
     503,   881,   862,   692,    70,    -1,   291,    -1,   290,    -1,
     217,    -1,   369,    -1,   178,    -1,   216,    -1,   333,    -1,
     332,    -1,   248,    -1,   175,    -1,   174,    -1,   149,    -1,
     209,    -1,   132,    -1,   148,    -1,   192,    -1,   158,    -1,
     218,    -1,   218,   863,    -1,   866,    -1,   865,    -1,   870,
      -1,   898,    -1,   856,   857,    -1,   899,    -1,   901,    -1,
     867,    -1,    19,   856,    -1,    18,   856,    -1,   872,    -1,
     880,    -1,   874,    -1,   480,    -1,   762,    -1,   875,    -1,
     876,    -1,   877,    -1,   878,    -1,   879,    -1,    39,   856,
      -1,   881,    -1,   881,   860,    -1,   863,    -1,   488,    -1,
     859,    -1,   860,     5,   859,    -1,   863,    -1,   861,     5,
     863,    -1,   863,    -1,   862,     5,   863,    -1,   856,    -1,
      18,    -1,    19,    -1,     9,   856,    -1,   489,    -1,   433,
      -1,   436,   856,   397,    -1,   448,   436,  1425,   397,    -1,
     299,   436,  1425,   397,    -1,   864,   962,    -1,   864,    26,
      -1,    25,    -1,   962,    -1,    26,    -1,   869,    -1,  1109,
      -1,  1109,   426,  1109,    -1,   868,    -1,   439,   856,    -1,
     398,   856,    -1,  1219,    -1,    -1,   512,   871,  1219,    -1,
       7,   856,    -1,     6,   856,    -1,   856,    -1,   873,     5,
     856,    -1,   627,   436,  1425,   397,    -1,   434,   436,  1425,
     397,    -1,   627,   436,   881,   873,   397,    -1,   434,   436,
     881,   873,   397,    -1,   392,    -1,   254,    -1,    10,   856,
      -1,   257,   856,    -1,    10,   856,   447,    25,    -1,   257,
     856,   447,    25,    -1,   561,   856,    -1,   376,   856,    -1,
     561,   856,   447,    25,    -1,   376,   856,   447,    25,    -1,
     396,    -1,     8,   856,    -1,    18,   856,    -1,    19,   856,
      -1,    20,   856,    -1,    21,   856,    -1,    22,   856,    -1,
      11,   856,    -1,    14,   856,    -1,   462,   856,    -1,    12,
     856,    -1,    13,   856,    -1,    17,   856,    -1,    16,   856,
      -1,    15,   856,    -1,    -1,    -1,    -1,   956,   436,   883,
     719,   884,   397,    -1,    -1,    -1,   956,   526,   956,   436,
     885,   719,   886,   397,    -1,    -1,    -1,   542,   436,   888,
     856,   889,   397,    -1,    -1,    -1,   518,   436,   890,   856,
     891,   397,    -1,    -1,    -1,   595,   436,   892,   856,   893,
     397,    -1,    -1,    -1,   586,   436,   894,   856,   895,   397,
      -1,   374,   436,   902,   397,   897,    -1,   362,   436,    25,
     397,   896,    -1,   362,   436,    26,   397,   896,    -1,   362,
     436,    26,   594,    26,   397,   896,    -1,   679,   436,  1109,
     397,    -1,   680,   436,  1109,     5,    26,   397,    -1,    -1,
    1405,   630,  1406,    -1,   806,    -1,   887,    -1,   294,   436,
    1504,   397,    -1,   104,   436,   948,   397,    -1,    76,   436,
     948,   397,    -1,   412,   436,  1504,   397,    -1,   197,   436,
    1504,   397,    -1,    64,   436,  1504,   397,    -1,   900,    -1,
     882,    -1,  1401,    -1,   542,    -1,   428,   436,   856,   397,
      -1,   327,   436,   856,   397,    -1,   493,   856,    -1,   449,
     763,    -1,   856,   113,    -1,   856,   114,    -1,   856,   115,
      -1,    25,    -1,   903,    -1,    19,   903,    -1,   905,    -1,
     904,    -1,    26,    -1,    26,    26,    -1,    26,    26,   594,
      26,    -1,    26,    26,   594,    26,   594,    26,    -1,    26,
      26,   594,    26,   594,    24,    -1,    26,   594,    26,    -1,
      26,   594,    26,   594,    26,    -1,    26,   594,    26,   594,
      24,    -1,    26,   594,    24,    -1,    24,    -1,    26,    -1,
      26,    19,    26,    -1,   948,    -1,   906,     5,   948,    -1,
      -1,    -1,   600,  1109,    14,   863,   630,   863,   910,   908,
    1514,   909,   246,    -1,    -1,   576,   863,    -1,    -1,    -1,
      -1,   409,   912,   950,   913,   915,  1306,   914,  1514,   245,
      -1,    -1,     8,   881,   861,    -1,    -1,    -1,   642,   956,
     917,   766,   918,  1054,   920,   919,   925,   643,    -1,    -1,
     930,    -1,    -1,   921,    -1,   922,    -1,   921,   922,    -1,
      -1,   644,   923,  1514,    -1,    -1,   645,   924,  1514,    -1,
      -1,   926,    -1,   927,    -1,   926,   927,    -1,    -1,   646,
     928,  1514,    -1,    -1,   647,   929,  1514,    -1,   931,   935,
     329,    -1,    96,    -1,    96,   932,   551,   933,    -1,    96,
     390,   934,    -1,  1109,    -1,   932,     5,  1109,    -1,   956,
      -1,   933,     5,   956,    -1,  1109,    -1,   934,     5,  1109,
      -1,   936,    -1,   935,   936,    -1,    -1,   648,   937,  1514,
      -1,    -1,   649,   938,  1514,    -1,    -1,   668,   933,   939,
    1514,    -1,    -1,   486,   933,   940,  1514,    -1,    -1,   629,
     933,   941,  1514,    -1,   550,   949,    -1,   559,    19,    26,
      -1,   559,    -1,   506,    18,    26,    -1,   506,    -1,    26,
      -1,  1109,    -1,   673,    -1,    25,    -1,   961,    -1,   863,
      -1,   945,     5,   945,    -1,   946,    -1,   956,    -1,   671,
     436,   956,   397,    -1,   956,   624,   671,   436,   956,   397,
      -1,   956,   464,   689,   432,    -1,   956,   624,    20,    -1,
     956,   464,   689,   432,   624,    20,    -1,   956,   624,   956,
      -1,   956,   464,   689,   432,   624,   956,    -1,   957,    -1,
     957,    -1,   957,    -1,   957,    -1,   957,    -1,   957,    -1,
      -1,   555,    26,    -1,  1513,    -1,   958,    -1,  1513,    -1,
     354,   436,   959,   397,    -1,  1112,    -1,    25,    -1,   956,
      -1,   956,   464,   689,   432,    -1,   956,   624,    20,    -1,
     956,   464,   689,   432,   624,    20,    -1,   956,   624,   956,
      -1,   956,   464,   689,   432,   624,   956,    -1,  1109,    -1,
      24,    -1,   624,    26,    -1,   552,  1496,    -1,   656,   965,
      -1,   966,    -1,   965,     5,   966,    -1,   956,    -1,   667,
     965,    -1,   658,   965,    -1,   659,  1504,    -1,   657,   953,
     663,  1504,    -1,   661,   965,    -1,   662,  1504,    -1,   660,
     953,   663,  1504,    -1,    -1,   665,   971,   861,   976,   978,
     980,   972,   974,    -1,    -1,   973,    -1,   653,    -1,   654,
      -1,    -1,   975,    -1,   349,  1109,    -1,    -1,   977,    -1,
     395,   861,    -1,    -1,   979,    -1,   664,    26,    -1,    -1,
     981,    -1,   655,    26,   982,    -1,    -1,   405,    26,    -1,
      -1,    -1,   626,   863,   580,   984,  1514,   985,   986,   446,
      -1,    -1,    -1,   547,   987,  1514,    -1,    -1,    -1,    67,
     988,   863,   580,   989,  1514,   986,    -1,   111,   956,   436,
      26,   397,    -1,    60,   956,    -1,    80,   956,    -1,    -1,
     295,  1140,   993,   630,   488,    -1,   295,  1140,   561,   994,
      -1,   995,    -1,   994,     5,   995,    -1,   803,   624,  1397,
      -1,   803,   624,    20,    -1,    -1,   998,   329,    -1,   329,
      -1,    -1,   155,    -1,   999,    -1,   998,   999,    -1,    -1,
     275,  1011,  1000,  1514,    -1,    -1,   278,  1012,  1001,  1514,
      -1,    -1,   356,  1002,  1514,    -1,    -1,   352,  1003,  1514,
      -1,    -1,  1025,  1004,  1514,    -1,    -1,   310,  1005,  1514,
      -1,    -1,   280,  1006,  1514,    -1,    -1,    40,  1007,  1514,
      -1,    -1,    38,  1008,  1514,    -1,    -1,    42,  1009,  1514,
      -1,    -1,    41,  1010,  1514,    -1,   948,    -1,  1011,     5,
     948,    -1,   948,    -1,  1012,     5,   948,    -1,   319,  1015,
      -1,   320,   956,   663,  1015,    -1,   566,    -1,   380,    -1,
     948,    -1,    -1,   669,  1018,  1017,   996,    -1,   390,  1128,
     997,   955,   692,    -1,  1128,   997,   551,  1504,   955,   692,
      -1,    -1,   492,  1135,   997,   551,   956,   624,    20,   955,
    1019,   692,    -1,   474,  1504,  1021,    -1,    86,    26,    -1,
      87,    26,    -1,   631,    -1,   544,    -1,    -1,   555,    26,
      -1,  1024,    -1,    48,    25,    -1,   501,    14,    26,    -1,
     501,    14,  1109,    -1,    49,    14,    26,    -1,    49,    14,
    1109,    -1,    45,    -1,    47,    -1,    44,    -1,    46,    -1,
      -1,   435,  1026,  1031,    -1,   300,    -1,    -1,   601,  1028,
    1031,    -1,   308,  1033,    -1,   601,  1031,    -1,  1033,    -1,
     436,  1032,   397,    -1,  1033,    -1,  1032,     5,  1033,    -1,
    1034,    -1,   599,    -1,   317,    -1,   335,    -1,   309,    -1,
     490,    -1,   447,    -1,   631,    -1,   555,    -1,   544,    -1,
     182,    -1,   444,    -1,   455,    -1,   545,    -1,   560,    -1,
     525,    -1,   315,    -1,   316,    -1,    25,    -1,   515,    -1,
      -1,    -1,   603,  1037,  1133,  1038,    14,   881,  1039,    -1,
     488,    -1,   862,    -1,   224,  1109,    -1,   213,  1109,    -1,
     227,  1109,    -1,   456,  1109,   338,    -1,   456,  1109,   391,
     944,    -1,    -1,  1046,  1045,  1049,    -1,    -1,  1047,    -1,
    1048,    -1,  1047,  1048,    -1,   991,    -1,  1053,    -1,  1069,
      -1,  1055,    -1,    -1,  1050,    -1,  1052,    -1,  1050,  1052,
      -1,    71,   956,    -1,  1057,    -1,  1063,    -1,  1075,    -1,
    1229,    -1,  1239,    -1,  1096,    -1,  1494,    -1,   916,    -1,
     739,    -1,   990,    -1,   745,    -1,   739,    -1,  1494,    -1,
      -1,   739,    -1,  1494,    -1,   767,    -1,   372,    -1,    65,
      -1,    -1,    -1,    -1,    -1,  1056,  1058,   956,   436,  1059,
    1126,   397,  1060,   766,  1061,  1054,  1514,  1062,    -1,   215,
      -1,    -1,    -1,   562,  1064,   766,  1065,  1514,   366,    -1,
     182,   858,    -1,   881,    -1,   881,   861,    -1,   361,  1409,
      -1,   472,  1409,    -1,  1070,    -1,  1071,    -1,  1070,  1071,
      -1,  1072,    -1,  1053,    -1,  1068,    -1,    -1,   411,  1073,
    1074,    -1,   766,   247,    -1,   944,    -1,    -1,    -1,    -1,
     118,   956,   117,   956,   436,  1076,  1126,   397,  1077,   766,
    1078,  1054,  1514,  1062,    -1,    -1,   563,  1080,  1095,  1086,
    1081,    -1,   367,    -1,    -1,   239,  1083,  1514,    -1,    -1,
      23,  1087,  1088,  1089,   955,  1084,  1514,    -1,    -1,    23,
    1087,   955,  1085,  1514,    -1,  1082,    -1,  1086,  1082,    -1,
      -1,  1027,    -1,    25,    -1,  1109,    -1,    -1,  1109,    -1,
      25,    -1,   256,  1093,    -1,   268,  1094,    -1,   251,  1094,
      -1,   590,    -1,    25,    -1,  1109,    -1,  1093,    -1,  1094,
       5,  1093,    -1,  1109,    -1,    25,    -1,    -1,    -1,   650,
     956,  1097,   766,  1098,  1099,   651,    -1,  1100,    -1,  1099,
    1100,    -1,    -1,   652,  1101,  1514,    -1,    -1,   629,   956,
    1102,  1514,    -1,  1106,  1104,    -1,    -1,   693,  1107,    -1,
    1108,    -1,  1105,    -1,   977,    -1,   979,    -1,   981,    -1,
     973,    -1,   975,    -1,   375,   881,   861,    -1,    -1,    70,
      -1,    70,    -1,  1110,    -1,  1112,    -1,   195,  1112,    -1,
    1112,   624,    -1,  1111,  1116,    -1,  1111,   956,   464,  1120,
     432,    -1,  1111,   956,   464,  1120,   432,   464,  1120,   432,
      -1,  1117,    -1,   956,    -1,  1113,    -1,   956,   463,  1115,
     431,    -1,   956,   463,  1115,   431,    -1,  1109,    -1,    25,
      -1,    20,    -1,   956,    -1,   956,  1119,    -1,   956,  1119,
      -1,   464,  1120,   432,    -1,   464,  1120,   432,   464,  1120,
     432,    -1,  1121,    -1,  1120,     5,  1121,    -1,   689,    -1,
    1123,    -1,  1125,    -1,  1123,   624,  1124,    -1,  1123,   624,
     956,   464,  1120,   432,    -1,  1123,   624,   956,   464,  1120,
     432,   464,  1120,   432,    -1,   956,    -1,  1114,    -1,    20,
      -1,   956,    -1,   956,  1119,    -1,    -1,  1127,    -1,  1129,
      -1,  1127,     5,  1129,    -1,  1130,    -1,  1128,     5,  1130,
      -1,   956,    -1,   956,   624,   956,    -1,  1109,    -1,  1109,
     426,  1109,    -1,    25,    -1,   962,    -1,    26,    -1,  1132,
      -1,  1131,     5,  1132,    -1,  1109,    -1,  1109,   426,  1109,
      -1,  1134,    -1,  1133,     5,  1134,    -1,  1122,    -1,  1109,
      -1,  1137,    -1,  1136,     5,  1137,    -1,  1109,  1138,    -1,
      -1,   592,    -1,   543,    -1,   956,   464,  1120,   432,    -1,
    1141,    -1,  1140,     5,  1141,    -1,  1109,    -1,  1109,   426,
    1109,    -1,   259,   952,   622,   946,   584,  1506,   697,    -1,
      -1,   622,   436,   863,     5,   863,   397,  1144,    -1,    -1,
     573,   436,   863,     5,   863,   397,    -1,   260,   956,  1143,
      -1,   956,    -1,   343,   954,  1148,    -1,  1149,    -1,   551,
     863,    -1,  1150,  1151,  1156,     8,  1146,    -1,    -1,   622,
    1152,   436,   863,     5,   863,   397,    -1,    -1,   561,   957,
      -1,    -1,   355,    -1,   222,  1451,   271,  1489,  1155,    -1,
     568,   949,    -1,   568,   949,     8,   881,   861,    -1,    -1,
     621,   581,  1445,   379,  1445,    -1,   621,   581,  1445,     5,
     379,  1445,    -1,   621,  1445,     5,  1445,    -1,    -1,   653,
      -1,   654,    -1,    95,  1489,  1158,  1159,    -1,    -1,   621,
    1489,    -1,    -1,   621,   581,  1445,     8,  1445,    -1,   581,
    1445,     8,  1445,    -1,   417,  1161,    -1,  1162,    -1,  1161,
       5,  1162,    -1,   208,   943,    -1,   289,   943,    -1,   334,
     943,    -1,   342,   943,    -1,   298,   943,    -1,   264,   943,
      -1,  1029,    -1,   444,  1030,    -1,   455,  1030,    -1,   566,
    1030,    -1,   380,  1030,    -1,   555,  1030,    -1,   553,   944,
      -1,   554,   944,    -1,   406,   693,    -1,   669,   693,    -1,
     296,    -1,   200,    -1,   156,    -1,   133,    -1,   151,    -1,
     142,    -1,  1450,   419,  1166,   551,  1164,    -1,  1109,    -1,
      25,    -1,   408,  1166,    -1,   408,  1166,     8,  1128,    -1,
      43,  1164,    -1,   957,    -1,    -1,   467,  1176,   692,   600,
    1171,  1109,  1169,   955,   692,  1168,  1172,    -1,    -1,   672,
      26,    -1,   467,  1176,   692,   349,  1109,    -1,    -1,   324,
      -1,    -1,  1173,   287,    -1,  1174,    -1,  1173,  1174,    -1,
      -1,  1025,  1175,  1514,    -1,   862,    -1,    -1,   608,   949,
    1178,  1179,    -1,    -1,   551,  1180,    -1,  1181,    -1,  1180,
       5,  1181,    -1,  1437,    -1,   488,    -1,   225,  1184,    93,
      -1,   225,  1184,   630,  1183,    -1,   225,  1184,    92,  1183,
      -1,   225,  1184,    -1,    25,    -1,   961,    -1,   956,    -1,
      -1,   484,    -1,   150,  1184,  1185,   436,   881,  1067,   397,
      -1,   198,  1184,    -1,    72,  1184,    -1,  1220,  1228,    -1,
     452,    66,    -1,   452,  1191,    -1,  1192,    -1,  1191,  1192,
      -1,    -1,   138,  1193,  1514,    -1,    -1,   204,  1194,  1514,
      -1,    -1,   233,  1195,  1514,    -1,    -1,   221,  1196,  1514,
      -1,    -1,   258,  1197,  1514,    -1,    -1,   206,  1109,  1198,
    1514,    -1,    -1,   229,  1109,  1199,  1514,    -1,  1210,    -1,
    1212,    -1,  1211,    -1,  1201,    -1,  1237,    -1,  1204,    -1,
      -1,   565,   863,  1202,   487,    -1,    -1,   487,    -1,    -1,
     574,    26,  1205,  1203,    -1,   163,    -1,   633,  1224,    -1,
     166,  1224,    -1,   165,  1224,    -1,    -1,  1207,    -1,  1208,
      -1,  1207,  1208,    -1,  1217,  1209,    -1,    -1,   622,  1224,
      -1,   524,  1206,  1216,    -1,   523,  1445,  1216,    -1,   522,
    1215,  1214,  1213,  1216,    -1,    -1,   157,   856,    -1,   157,
     856,     5,   856,    -1,   617,    -1,   618,    -1,   619,    -1,
     620,    -1,  1109,    -1,    -1,   527,    -1,  1218,    -1,  1217,
       5,  1218,    -1,   863,  1251,    -1,   613,   436,   856,   397,
    1236,    -1,    69,  1236,    -1,   501,   436,    20,   397,  1236,
      -1,   418,   436,    20,   397,  1236,    -1,   393,   436,   856,
     397,  1236,    -1,   593,   436,   856,   397,  1236,    -1,   606,
     436,   856,   397,  1236,    -1,   605,   436,   856,   397,  1236,
      -1,    -1,   466,  1221,    -1,  1222,    -1,  1221,  1222,    -1,
     232,    26,    -1,   223,    26,    -1,   306,    26,    -1,   189,
      26,    -1,   261,    26,    -1,   180,    -1,   348,    25,    -1,
     348,  1109,    -1,   181,    25,    -1,   164,    25,    -1,  1227,
      -1,  1223,  1227,    -1,  1225,   113,    -1,  1225,   115,    -1,
    1225,   114,    -1,  1225,    -1,   962,    -1,    26,    -1,    -1,
     466,  1223,    -1,   232,  1224,    -1,   223,  1224,    -1,   306,
    1224,    -1,   189,  1224,    -1,   261,  1224,    -1,   262,  1224,
      -1,   632,    25,    -1,   633,  1224,    -1,   637,    -1,   634,
      -1,   635,    -1,   636,    -1,   641,    -1,   638,    -1,   639,
      -1,   640,    -1,    81,  1224,    -1,    82,  1224,    -1,    83,
    1224,    -1,   348,    25,    -1,   181,    25,    -1,   405,    -1,
      78,    -1,    79,    -1,    -1,   519,   623,  1136,    -1,   139,
    1136,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   470,  1230,
     956,   436,  1231,  1126,   397,  1232,   766,  1233,  1189,  1234,
    1190,  1235,   244,    -1,    -1,   531,   856,    -1,   521,  1238,
      -1,    -1,  1164,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     110,  1240,   956,   436,  1241,  1126,   397,  1242,   766,  1243,
    1246,  1244,  1190,  1245,   244,    -1,  1226,  1228,    -1,    -1,
      -1,    -1,   159,   436,    25,     5,  1248,   719,  1249,   397,
    1250,   717,    -1,    -1,   389,    -1,   389,   223,    26,    -1,
     389,   223,  1109,    -1,   611,   863,    -1,   611,   863,   349,
    1109,    -1,   611,   863,   167,    -1,   611,   863,   582,    -1,
     611,   863,   549,    -1,  1254,    -1,   177,    -1,   328,    -1,
     286,    -1,  1261,    -1,  1256,    -1,    -1,    -1,   211,  1257,
    1394,   436,  1258,  1265,   397,    -1,    -1,    -1,   136,  1259,
    1394,   436,  1260,  1265,   397,  1262,    -1,   108,  1263,   397,
      -1,    59,   957,    -1,    -1,   273,    -1,  1264,    -1,  1263,
       5,  1264,    -1,   956,   592,    -1,   956,   543,    -1,   956,
      -1,  1266,    -1,  1265,     5,  1266,    -1,  1347,    -1,  1345,
      -1,   125,   956,    -1,   184,    -1,    50,   956,  1269,    -1,
    1270,    -1,  1269,     5,  1270,    -1,  1271,    -1,  1274,    -1,
    1277,    -1,  1282,    -1,  1283,    -1,  1281,    -1,  1280,    -1,
     589,  1272,    -1,   589,   436,  1273,   397,    -1,  1266,    -1,
    1266,   668,   956,    -1,  1272,    -1,  1273,     5,  1272,    -1,
     546,  1276,    -1,   546,   436,  1275,   397,    -1,  1276,    -1,
    1275,     5,  1276,    -1,   956,    -1,   460,  1279,    -1,   460,
     436,  1278,   397,    -1,  1279,    -1,  1278,     5,  1279,    -1,
    1266,    -1,    90,    -1,    91,    -1,    89,    26,    -1,    61,
    1351,    -1,    61,   436,  1284,   397,    -1,    62,  1285,    -1,
      62,   436,  1284,   397,    -1,  1351,    -1,  1284,     5,  1351,
      -1,   956,    -1,   270,    -1,   236,    -1,   169,  1288,    -1,
     146,    -1,   134,    -1,   124,    -1,   122,    -1,   126,    -1,
     183,  1451,    -1,   235,  1287,   465,  1445,   630,  1445,    -1,
     303,   949,   465,  1445,   630,  1445,    -1,    -1,  1451,    -1,
      -1,   863,    -1,   528,   863,    -1,   234,    -1,    -1,   253,
    1292,  1394,  1295,  1293,    -1,    -1,   484,  1294,   436,  1297,
     397,    -1,  1431,    -1,    -1,   436,  1296,   397,    -1,  1397,
      -1,  1296,     5,  1397,    -1,  1298,    -1,  1297,     5,  1298,
      -1,  1437,    -1,   488,    -1,    -1,    -1,   505,  1300,  1303,
    1301,  1304,    -1,   957,    -1,  1308,   950,    -1,   950,    -1,
      -1,    -1,   558,  1305,  1131,    -1,    -1,    -1,   558,  1307,
    1131,    -1,   506,    -1,   559,    -1,   566,    -1,   380,    -1,
     346,    -1,   401,    -1,   383,   863,    -1,   355,   863,    -1,
     242,  1394,   154,   950,    -1,   242,  1394,  1367,    -1,   519,
     623,  1312,    -1,  1313,    -1,  1312,     5,  1313,    -1,  1314,
    1315,    -1,    26,    -1,  1397,    -1,    -1,   592,    -1,   543,
      -1,   281,    -1,   314,    -1,    -1,   331,    -1,   361,  1320,
    1318,    -1,  1489,    -1,  1489,   616,   956,    -1,    25,    -1,
      -1,  1450,  1322,  1323,    -1,  1352,    -1,  1356,    -1,  1317,
      -1,  1452,    -1,  1316,    -1,  1309,    -1,  1310,    -1,  1299,
      -1,  1291,    -1,  1290,    -1,  1421,    -1,  1469,    -1,   510,
    1326,   629,  1394,   630,  1331,  1325,    -1,    -1,   145,    -1,
     172,    -1,  1327,    -1,  1328,    -1,  1327,     5,  1328,    -1,
     476,    -1,   455,    -1,   444,    -1,   483,  1329,    -1,    -1,
     436,  1330,   397,    -1,  1397,    -1,  1330,     5,  1397,    -1,
    1332,    -1,  1331,     5,  1332,    -1,   468,    -1,  1395,    -1,
     240,  1394,  1334,   621,  1431,  1336,    -1,    -1,   436,  1335,
     397,    -1,  1397,    -1,  1335,     5,  1397,    -1,    -1,   144,
      -1,   497,   436,  1370,   397,    -1,   250,   436,  1340,   397,
    1339,    -1,   301,  1341,    -1,  1342,    -1,  1394,    -1,  1394,
     436,  1342,   397,    -1,  1397,    -1,  1342,     5,  1397,    -1,
     481,   436,  1344,   397,    -1,   263,   436,  1344,   397,    -1,
    1397,    -1,  1344,     5,  1397,    -1,  1343,    -1,  1338,    -1,
    1337,    -1,   405,  1400,    -1,   212,    -1,   956,  1386,  1348,
    1349,    -1,    -1,  1346,    -1,    -1,  1350,    -1,  1351,    -1,
    1350,  1351,    -1,   378,    -1,   162,    -1,   481,    -1,  1339,
      -1,   497,   436,  1370,   397,    -1,   123,  1353,  1355,    -1,
    1354,    -1,  1395,    -1,  1356,    -1,  1355,  1356,    -1,  1333,
      -1,  1324,    -1,   453,  1370,    -1,   373,  1359,    -1,  1436,
      -1,  1359,     5,  1436,    -1,   531,  1370,    -1,   551,  1362,
      -1,  1363,    -1,  1362,     5,  1363,    -1,  1364,    -1,   520,
    1364,    -1,   520,   436,  1365,   397,    -1,  1394,    -1,  1394,
    1399,    -1,  1363,    -1,  1365,     5,  1363,    -1,  1361,  1367,
    1368,  1369,    -1,    -1,  1360,    -1,    -1,  1358,    -1,    -1,
    1357,    -1,  1371,    -1,  1370,     6,  1371,    -1,  1372,    -1,
    1371,     7,  1372,    -1,  1373,    -1,     9,  1373,    -1,  1384,
      -1,   436,  1370,   397,    -1,   448,  1432,    -1,   299,  1432,
      -1,    -1,   447,  1377,    -1,  1438,    -1,  1441,    -1,  1437,
     627,   436,  1379,   397,    -1,  1437,   627,  1432,    -1,  1437,
     434,   436,  1379,   397,    -1,  1437,   434,  1432,    -1,  1380,
      -1,  1379,     5,  1380,    -1,  1493,    -1,  1400,    -1,    -1,
       9,    -1,  1437,  1381,   392,    -1,  1437,  1381,   254,    -1,
    1437,  1383,  1437,    -1,  1437,  1381,   394,  1437,     7,  1437,
      -1,  1437,   561,  1376,  1375,    -1,  1437,   376,  1376,  1375,
      -1,  1437,   678,  1376,  1375,    -1,  1437,   377,  1376,  1375,
      -1,  1437,  1381,    10,  1376,  1375,    -1,    14,    -1,    17,
      -1,    12,    -1,    13,    -1,   257,    -1,    10,    -1,   677,
      -1,    16,    -1,    15,    -1,  1382,    -1,  1378,    -1,  1374,
      -1,    -1,   590,    -1,   364,    -1,   481,    -1,  1387,    -1,
    1388,    -1,  1390,    -1,   324,    -1,   324,   436,  1391,   397,
      -1,   416,   436,  1392,  1389,   397,    -1,   477,    -1,   403,
     436,  1392,  1389,   397,    -1,   517,   436,  1392,  1389,   397,
      -1,   542,    -1,   413,    -1,   385,    -1,   362,  1407,   630,
    1408,    -1,   362,    -1,   374,  1407,   630,  1408,    -1,   374,
      -1,   374,  1407,   436,    26,   397,   630,  1408,    -1,   579,
      -1,   538,    -1,   429,    -1,   429,   436,    26,   397,    -1,
     429,   436,    26,     5,    26,   397,    -1,    -1,     5,  1393,
      -1,   507,   436,  1392,   397,    -1,   570,    -1,   304,    -1,
     507,    -1,    68,    -1,    26,    -1,    26,    -1,    26,    -1,
      25,   624,   956,    -1,    25,    -1,   956,    -1,   956,   594,
     956,    -1,   956,    -1,    -1,   464,    26,   432,    -1,   464,
      26,     5,    26,   432,    -1,  1398,    -1,   616,  1398,    -1,
     956,  1396,    -1,  1394,   624,   956,  1396,    -1,  1394,   624,
      20,    -1,   956,    -1,    25,    -1,   416,    -1,   962,    -1,
      26,    -1,  1402,    -1,   401,  1404,    -1,   401,  1403,    -1,
      -1,  1407,   630,  1408,    -1,    -1,  1405,   630,  1405,    -1,
     586,    -1,   518,    -1,   595,    -1,   557,    -1,   459,    -1,
     475,    -1,   371,    -1,   371,   436,    26,   397,    -1,   586,
      -1,   518,    -1,   595,    -1,   557,    -1,   459,    -1,   475,
      -1,   371,    -1,   371,   436,    26,   397,    -1,   586,    -1,
     518,    -1,   595,    -1,   557,    -1,   459,    -1,   475,    -1,
     371,    -1,   586,    -1,   518,    -1,   595,    -1,   557,    -1,
     459,    -1,   475,    -1,   371,    -1,   371,   436,    26,   397,
      -1,   956,    -1,   956,   616,   956,    -1,    25,    -1,  1450,
     508,   950,    -1,    -1,  1450,   404,  1302,   442,   600,  1419,
    1412,    -1,    -1,  1450,   404,  1302,   442,   105,   600,  1420,
    1413,    -1,    -1,  1450,   404,  1302,   140,  1420,  1414,    -1,
      -1,  1450,   404,  1302,   141,   105,   600,  1420,  1415,    -1,
      -1,   293,    -1,   292,  1417,    -1,  1418,    -1,  1417,     5,
    1418,    -1,   956,    -1,   956,   624,   956,    -1,    25,   624,
     956,   624,   956,    -1,  1420,    -1,  1291,    -1,  1166,    -1,
    1422,    -1,  1422,    -1,    -1,    -1,   476,  1433,  1423,  1434,
    1424,  1430,  1366,  1428,  1416,    -1,   476,  1433,  1434,  1366,
    1428,    -1,  1427,    -1,  1445,    -1,   476,  1433,  1434,  1430,
    1366,  1428,    -1,    -1,   530,  1385,  1426,    -1,  1311,    -1,
     336,  1429,  1262,    -1,  1311,   336,  1429,  1262,    -1,   956,
      -1,    -1,   558,  1131,    -1,   476,  1433,  1434,  1366,    -1,
     436,   476,  1433,  1434,  1366,   397,    -1,    -1,   590,    -1,
     364,    -1,   481,    -1,  1435,    -1,  1434,     5,  1435,    -1,
    1437,    -1,  1437,   956,    -1,  1437,    -1,  1438,    -1,    19,
    1438,    -1,    18,  1438,    -1,  1439,    -1,  1493,    -1,  1432,
      -1,   616,   956,    -1,   616,   956,   624,   956,    -1,  1438,
      21,  1437,    -1,  1438,  1459,    -1,  1438,    20,  1437,    -1,
    1438,    18,  1437,    -1,  1438,    19,  1437,    -1,  1400,    -1,
     489,    -1,   433,    -1,   581,    -1,    20,    -1,    69,    -1,
     593,   436,  1385,  1437,   397,    -1,   605,   436,  1385,  1437,
     397,    -1,   606,   436,  1385,  1437,   397,    -1,   613,   436,
    1385,  1437,   397,    -1,   501,   436,  1385,  1437,   397,    -1,
     956,   436,  1440,   397,    -1,   542,   436,  1440,   397,    -1,
     436,  1437,   397,    -1,   449,   436,  1460,   397,    -1,  1437,
      -1,  1440,     5,  1437,    -1,  1400,    -1,  1450,   351,  1449,
    1444,  1426,    -1,  1450,   340,  1449,  1444,   253,  1394,  1446,
      -1,  1450,   340,  1449,  1444,  1109,    -1,    -1,   326,  1445,
      -1,    25,    -1,  1109,    -1,    -1,   436,  1447,   397,    -1,
    1448,    -1,  1447,     5,  1448,    -1,   956,    -1,    25,    -1,
    1109,    -1,    -1,   272,  1451,   600,    -1,   957,    -1,  1457,
      -1,  1456,    -1,  1453,    -1,   321,  1454,   630,  1454,    -1,
     302,  1454,   624,  1455,   630,  1455,    -1,   956,    -1,   956,
      -1,   226,   803,    -1,   297,   803,  1458,    -1,   276,    -1,
     179,    -1,    97,    -1,    98,    -1,    99,    -1,   100,    -1,
     101,    -1,   102,    -1,   401,     5,  1407,   630,  1408,    -1,
    1493,     5,  1407,   630,  1408,    -1,   401,  1407,   630,  1408,
      -1,    -1,   612,  1462,  1463,   194,    -1,  1464,    -1,  1463,
    1464,    -1,    33,    -1,  1465,    -1,  1467,    -1,   355,    -1,
     309,    -1,   228,    -1,   589,    -1,   486,    -1,   590,    -1,
     491,    -1,   535,    -1,   591,    -1,   119,    -1,   492,    -1,
     621,    -1,   592,    -1,   322,    -1,   493,    -1,   323,    -1,
     622,    -1,   616,    -1,   279,    -1,   494,    -1,   188,    -1,
     393,    -1,   593,    -1,   668,    -1,   394,    -1,   495,    -1,
     496,    -1,   536,    -1,   537,    -1,   437,    -1,   438,    -1,
     357,    -1,   655,    -1,   623,    -1,   538,    -1,   395,    -1,
     540,    -1,   534,    -1,   324,    -1,   497,    -1,   498,    -1,
     396,    -1,   499,    -1,   397,    -1,   432,    -1,   500,    -1,
     594,    -1,   439,    -1,   398,    -1,     5,    -1,    23,    -1,
     399,    -1,   440,    -1,   400,    -1,   359,    -1,   358,    -1,
     325,    -1,   360,    -1,   501,    -1,   441,    -1,   401,    -1,
     442,    -1,   541,    -1,   361,    -1,   542,    -1,   362,    -1,
     595,    -1,   596,    -1,   402,    -1,   597,    -1,   403,    -1,
     404,    -1,   405,    -1,   363,    -1,   502,    -1,   443,    -1,
     444,    -1,   326,    -1,   543,    -1,   285,    -1,   598,    -1,
     659,    -1,   406,    -1,   364,    -1,    21,    -1,   624,    -1,
     445,    -1,   327,    -1,   546,    -1,    67,    -1,   547,    -1,
     662,    -1,   407,    -1,    14,    -1,   503,    -1,   447,    -1,
     504,    -1,   331,    -1,   548,    -1,   408,    -1,   448,    -1,
     549,    -1,   449,    -1,   450,    -1,   370,    -1,   539,    -1,
     505,    -1,   104,    -1,   197,    -1,   451,    -1,   506,    -1,
     599,    -1,   507,    -1,   508,    -1,   600,    -1,   409,    -1,
     410,    -1,   452,    -1,   642,    -1,    96,    -1,   109,    -1,
     509,    -1,   371,    -1,   550,    -1,   551,    -1,   372,    -1,
     294,    -1,   411,    -1,   625,    -1,   552,    -1,   510,    -1,
      13,    -1,   511,    -1,   512,    -1,   453,    -1,   454,    -1,
     555,    -1,   556,    -1,   557,    -1,   664,    -1,    76,    -1,
     626,    -1,   627,    -1,   115,    -1,   513,    -1,   412,    -1,
     295,    -1,   669,    -1,   455,    -1,   413,    -1,   335,    -1,
     374,    -1,   671,    -1,   337,    -1,   601,    -1,   544,    -1,
     663,    -1,   514,    -1,   487,    -1,   375,    -1,   602,    -1,
     631,    -1,   414,    -1,     7,    -1,   433,    -1,   587,    -1,
     488,    -1,     6,    -1,   489,    -1,     8,    -1,   559,    -1,
     560,    -1,    12,    -1,   603,    -1,   561,    -1,   516,    -1,
     456,    -1,   604,    -1,   415,    -1,   562,    -1,   457,    -1,
      10,    -1,    49,    -1,   458,    -1,   563,    -1,   650,    -1,
     665,    -1,    19,    -1,   459,    -1,   114,    -1,    22,    -1,
     564,    -1,   460,    -1,   517,    -1,   518,    -1,    20,    -1,
     565,    -1,   566,    -1,   315,    -1,   567,    -1,   461,    -1,
       9,    -1,   416,    -1,   628,    -1,   673,    -1,   629,    -1,
     568,    -1,   436,    -1,   464,    -1,   465,    -1,   417,    -1,
     519,    -1,   344,    -1,   520,    -1,   466,    -1,   607,    -1,
     379,    -1,   521,    -1,   159,    -1,   110,    -1,   418,    -1,
      18,    -1,   113,    -1,   345,    -1,   419,    -1,   116,    -1,
     380,    -1,   316,    -1,   524,    -1,   346,    -1,   347,    -1,
     420,    -1,   467,    -1,   468,    -1,   608,    -1,   569,    -1,
     381,    -1,   570,    -1,   469,    -1,   421,    -1,   609,    -1,
     301,    -1,   382,    -1,   383,    -1,   470,    -1,   384,    -1,
     182,    -1,   349,    -1,   422,    -1,   471,    -1,   525,    -1,
     266,    -1,   610,    -1,   571,    -1,   611,    -1,   472,    -1,
     474,    -1,   475,    -1,   423,    -1,   476,    -1,   527,    -1,
     477,    -1,   424,    -1,   479,    -1,   572,    -1,   490,    -1,
     573,    -1,   574,    -1,   528,    -1,   304,    -1,   385,    -1,
     575,    -1,   480,    -1,   612,    -1,   305,    -1,    94,    -1,
     576,    -1,   577,    -1,   613,    -1,   425,    -1,   545,    -1,
     578,    -1,   120,    -1,   579,    -1,   580,    -1,   426,    -1,
     672,    -1,   630,    -1,   614,    -1,   427,    -1,   529,    -1,
     203,    -1,   350,    -1,   530,    -1,   481,    -1,   482,    -1,
     483,    -1,   428,    -1,   615,    -1,   581,    -1,   386,    -1,
     484,    -1,   429,    -1,   354,    -1,   582,    -1,   430,    -1,
     583,    -1,   387,    -1,   531,    -1,   532,    -1,   533,    -1,
     584,    -1,   389,    -1,   585,    -1,   605,    -1,   606,    -1,
     588,    -1,   586,    -1,   485,    -1,    -1,   195,  1466,  1493,
      -1,    -1,   558,  1468,  1131,    -1,    -1,    -1,   483,  1394,
    1470,  1473,  1471,  1472,    -1,    -1,   154,   950,    -1,   531,
    1370,    -1,    57,  1477,   397,    14,   436,  1478,   397,    -1,
      53,  1478,   397,    -1,    54,  1478,   397,    -1,   588,  1474,
      -1,    56,  1478,    -1,    55,  1478,    -1,  1476,    -1,  1474,
       5,  1476,    -1,  1397,    -1,  1475,    14,  1479,    -1,  1475,
      -1,  1477,     5,  1475,    -1,  1479,    -1,  1478,     5,  1479,
      -1,   488,    -1,  1480,    -1,  1481,    -1,    19,  1481,    -1,
      18,  1481,    -1,  1483,    -1,  1432,    -1,   616,   956,    -1,
     616,   956,   624,   956,    -1,  1482,    -1,  1400,    -1,   489,
      -1,   433,    -1,   581,    -1,    69,    -1,  1481,    21,  1480,
      -1,  1481,  1459,    -1,  1481,    20,  1480,    -1,  1481,    18,
    1480,    -1,  1481,    19,  1480,    -1,   593,   436,  1385,  1480,
     397,    -1,   605,   436,  1385,  1480,   397,    -1,   606,   436,
    1385,  1480,   397,    -1,   613,   436,  1385,  1480,   397,    -1,
     501,   436,  1385,  1480,   397,    -1,   956,   436,  1484,   397,
      -1,   542,   436,  1484,   397,    -1,   436,  1480,   397,    -1,
     449,   436,  1460,   397,    -1,  1493,    -1,  1480,    -1,  1484,
       5,  1480,    -1,    -1,   386,  1140,   561,  1486,  1487,    -1,
    1488,    -1,  1487,     5,  1488,    -1,   803,   624,  1397,    -1,
     803,   624,    20,    -1,  1490,    -1,   195,  1491,    -1,  1491,
      -1,  1118,    -1,   956,    -1,  1491,   624,  1492,    -1,    25,
     624,  1491,   624,  1492,    -1,    20,    -1,  1139,    -1,   956,
      -1,  1490,    -1,  1490,   426,  1490,    -1,   131,  1495,    -1,
     135,  1495,    -1,   130,  1495,    -1,    51,    -1,   170,  1495,
      -1,   128,  1495,    -1,    52,    -1,   153,  1495,    -1,   152,
    1495,    -1,   127,  1495,    -1,   360,    -1,   625,   630,  1496,
      -1,   552,  1496,    -1,   577,    -1,   539,  1497,    -1,   956,
      -1,   594,   956,    -1,   956,    -1,    -1,    -1,   532,  1499,
     863,  1500,  1514,   330,    -1,    -1,   663,  1504,    -1,    -1,
     666,    -1,   186,    -1,   282,   951,    -1,    74,   951,    -1,
     312,    -1,   311,    -1,   313,   953,  1501,  1502,    -1,   498,
    1504,  1502,    -1,   948,    -1,  1504,     5,   948,    -1,   107,
      -1,   137,   951,    -1,   863,   571,     5,   863,   398,    -1,
     514,   863,    -1,   269,   951,    -1,   106,  1509,     8,  1510,
    1508,    -1,    -1,   551,   863,    -1,   956,    -1,   956,    -1,
     252,   951,    -1,   255,   951,   630,   863,     5,   863,    -1,
     255,   951,   623,   863,     5,   863,    -1,    27,    -1,    -1,
    1516,    -1,  1517,  1216,    -1,  1515,    -1,  1516,  1515,    -1,
      -1,  1518,  1519,    -1,   682,    -1,   683,    -1,   684,    -1,
     685,    -1,   702,    -1,   724,    -1,   738,    -1,   739,    -1,
     745,    -1,   746,    -1,   765,    -1,   835,    -1,   836,    -1,
     837,    -1,   838,    -1,   849,    -1,   850,    -1,   851,    -1,
     852,    -1,   853,    -1,   854,    -1,   855,    -1,   907,    -1,
     911,    -1,   942,    -1,   963,    -1,   964,    -1,   967,    -1,
     968,    -1,   969,    -1,   970,    -1,   983,    -1,   992,    -1,
    1013,    -1,  1014,    -1,  1016,    -1,  1020,    -1,  1035,    -1,
    1036,    -1,  1040,    -1,  1041,    -1,  1042,    -1,  1043,    -1,
    1051,    -1,  1066,    -1,  1079,    -1,  1090,    -1,  1091,    -1,
    1092,    -1,  1103,    -1,  1142,    -1,  1145,    -1,  1147,    -1,
    1153,    -1,  1154,    -1,  1157,    -1,  1160,    -1,  1163,    -1,
    1165,    -1,  1167,    -1,  1170,    -1,  1177,    -1,  1182,    -1,
    1186,    -1,  1187,    -1,  1188,    -1,  1200,    -1,  1252,    -1,
    1253,    -1,  1255,    -1,  1267,    -1,  1268,    -1,  1286,    -1,
    1289,    -1,  1319,    -1,  1321,    -1,  1410,    -1,  1411,    -1,
    1442,    -1,  1443,    -1,  1461,    -1,  1485,    -1,  1494,    -1,
    1498,    -1,  1503,    -1,  1505,    -1,  1507,    -1,  1511,    -1,
    1512,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const unsigned short yyrline[] =
{
       0,   944,   944,   947,   950,   956,   962,   969,   973,   973,
     979,  1002,  1003,  1004,  1005,  1006,  1017,  1026,  1027,  1028,
    1029,  1030,  1035,  1036,  1047,  1050,  1053,  1053,  1057,  1060,
    1061,  1067,  1068,  1069,  1070,  1071,  1072,  1073,  1074,  1075,
    1076,  1077,  1078,  1079,  1080,  1081,  1082,  1083,  1086,  1087,
    1090,  1090,  1105,  1106,  1109,  1115,  1117,  1128,  1130,  1132,
    1134,  1138,  1140,  1202,  1206,  1210,  1210,  1220,  1224,  1227,
    1228,  1235,  1241,  1235,  1254,  1259,  1263,  1254,  1275,  1279,
    1275,  1287,  1292,  1287,  1311,  1318,  1322,  1310,  1348,  1348,
    1352,  1353,  1354,  1359,  1362,  1367,  1371,  1379,  1382,  1382,
    1388,  1392,  1407,  1405,  1423,  1423,  1438,  1438,  1441,  1441,
    1445,  1448,  1448,  1448,  1455,  1456,  1455,  1463,  1463,  1474,
    1474,  1493,  1496,  1499,  1502,  1505,  1508,  1521,  1526,  1526,
    1527,  1527,  1530,  1535,  1535,  1539,  1549,  1563,  1567,  1562,
    1577,  1583,  1591,  1592,  1595,  1595,  1598,  1602,  1607,  1614,
    1614,  1618,  1618,  1625,  1625,  1630,  1630,  1635,  1635,  1640,
    1640,  1653,  1654,  1662,  1663,  1680,  1683,  1686,  1689,  1692,
    1695,  1701,  1712,  1717,  1730,  1734,  1749,  1750,  1754,  1754,
    1758,  1758,  1758,  1759,  1760,  1765,  1765,  1768,  1768,  1777,
    1778,  1779,  1782,  1786,  1787,  1787,  1804,  1804,  1804,  1804,
    1808,  1815,  1816,  1819,  1819,  1823,  1824,  1825,  1826,  1831,
    1831,  1837,  1837,  1846,  1843,  1859,  1859,  1861,  1861,  1863,
    1865,  1867,  1869,  1872,  1876,  1876,  1877,  1877,  1881,  1881,
    1893,  1893,  1898,  1902,  1904,  1905,  1908,  1908,  1908,  1912,
    1913,  1914,  1915,  1922,  1923,  1924,  1925,  1928,  1929,  1930,
    1931,  1935,  1940,  1945,  1949,  1952,  1956,  1957,  1958,  1959,
    1960,  1961,  1962,  1963,  1966,  1967,  1968,  2000,  2004,  2006,
    2008,  2008,  2015,  2019,  2019,  2023,  2024,  2025,  2026,  2027,
    2028,  2029,  2035,  2035,  2038,  2040,  2046,  2048,  2054,  2062,
    2062,  2065,  2066,  2067,  2068,  2069,  2070,  2071,  2077,  2080,
    2080,  2093,  2093,  2100,  2101,  2102,  2104,  2105,  2107,  2109,
    2110,  2111,  2112,  2117,  2123,  2129,  2130,  2132,  2134,  2135,
    2136,  2137,  2138,  2139,  2142,  2143,  2150,  2158,  2158,  2166,
    2163,  2178,  2178,  2180,  2180,  2188,  2188,  2191,  2194,  2195,
    2200,  2212,  2216,  2219,  2222,  2223,  2224,  2225,  2226,  2231,
    2238,  2244,  2249,  2254,  2249,  2265,  2267,  2272,  2277,  2277,
    2277,  2281,  2281,  2284,  2284,  2290,  2290,  2296,  2296,  2306,
    2324,  2330,  2354,  2357,  2371,  2373,  2375,  2377,  2379,  2381,
    2383,  2389,  2391,  2395,  2397,  2399,  2401,  2403,  2405,  2407,
    2413,  2428,  2431,  2444,  2445,  2446,  2447,  2448,  2452,  2453,
    2454,  2458,  2463,  2470,  2471,  2472,  2473,  2474,  2475,  2476,
    2477,  2478,  2479,  2480,  2487,  2487,  2492,  2492,  2495,  2501,
    2509,  2515,  2525,  2526,  2534,  2541,  2545,  2555,  2559,  2564,
    2569,  2571,  2581,  2594,  2602,  2615,  2620,  2626,  2631,  2636,
    2637,  2643,  2714,  2720,  2725,  2733,  2733,  2748,  2752,  2759,
    2762,  2770,  2781,  2791,  2797,  2806,  2811,  2819,  2822,  2825,
    2830,  2837,  2842,  2847,  2852,  2862,  2870,  2878,  2883,  2887,
    2892,  2896,  2900,  2907,  2910,  2913,  2917,  2921,  2925,  2929,
    2937,  2947,  2952,  2945,  2968,  2973,  2968,  2990,  2990,  2990,
    2993,  2993,  2993,  2997,  2997,  2997,  3001,  3001,  3001,  3005,
    3011,  3017,  3023,  3029,  3035,  3045,  3045,  3049,  3053,  3054,
    3065,  3066,  3072,  3082,  3092,  3102,  3103,  3106,  3111,  3117,
    3121,  3125,  3128,  3134,  3137,  3140,  3157,  3160,  3166,  3167,
    3168,  3172,  3173,  3174,  3175,  3176,  3178,  3179,  3180,  3182,
    3183,  3187,  3188,  3193,  3194,  3206,  3210,  3205,  3218,  3221,
    3235,  3239,  3245,  3234,  3258,  3259,  3271,  3277,  3271,  3291,
    3291,  3293,  3294,  3298,  3298,  3302,  3302,  3307,  3307,  3314,
    3315,  3319,  3319,  3323,  3323,  3328,  3328,  3335,  3339,  3340,
    3341,  3346,  3346,  3349,  3349,  3353,  3353,  3357,  3357,  3361,
    3361,  3366,  3366,  3371,  3371,  3376,  3376,  3381,  3381,  3397,
    3414,  3415,  3416,  3417,  3418,  3419,  3420,  3423,  3423,  3426,
    3428,  3431,  3434,  3436,  3437,  3438,  3440,  3442,  3444,  3446,
    3450,  3457,  3459,  3465,  3470,  3475,  3480,  3480,  3483,  3489,
    3494,  3497,  3504,  3504,  3506,  3507,  3509,  3511,  3513,  3515,
    3519,  3528,  3528,  3590,  3602,  3609,  3609,  3613,  3618,  3624,
    3628,  3632,  3638,  3642,  3646,  3652,  3652,  3660,  3661,  3665,
    3665,  3669,  3670,  3673,  3676,  3676,  3679,  3681,  3681,  3684,
    3686,  3686,  3687,  3689,  3689,  3698,  3705,  3696,  3727,  3727,
    3727,  3730,  3732,  3730,  3739,  3742,  3748,  3759,  3759,  3763,
    3769,  3769,  3773,  3774,  3785,  3786,  3787,  3790,  3792,  3797,
    3797,  3801,  3800,  3807,  3806,  3812,  3812,  3817,  3817,  3823,
    3823,  3828,  3828,  3833,  3833,  3838,  3838,  3841,  3841,  3844,
    3844,  3847,  3847,  3889,  3890,  3898,  3899,  3908,  3913,  3918,
    3919,  3920,  3924,  3923,  3934,  3939,  3944,  3944,  3960,  3966,
    3967,  3968,  3969,  3972,  3972,  3975,  3982,  3983,  3984,  3985,
    3986,  3987,  3988,  3989,  3990,  3995,  3995,  3997,  4000,  4000,
    4002,  4006,  4009,  4010,  4013,  4013,  4018,  4021,  4022,  4023,
    4024,  4025,  4026,  4027,  4028,  4029,  4030,  4031,  4032,  4033,
    4034,  4035,  4036,  4037,  4038,  4042,  4060,  4060,  4060,  4087,
    4098,  4105,  4111,  4117,  4123,  4134,  4157,  4156,  4173,  4173,
    4177,  4178,  4186,  4187,  4188,  4189,  4196,  4197,  4199,  4200,
    4204,  4209,  4210,  4211,  4212,  4213,  4214,  4215,  4216,  4217,
    4218,  4219,  4222,  4222,  4224,  4224,  4224,  4226,  4230,  4230,
    4239,  4244,  4260,  4266,  4238,  4280,  4294,  4304,  4293,  4317,
    4324,  4324,  4329,  4335,  4343,  4348,  4349,  4352,  4352,  4352,
    4355,  4355,  4363,  4369,  4383,  4387,  4400,  4382,  4418,  4418,
    4432,  4443,  4442,  4454,  4450,  4467,  4464,  4477,  4477,  4479,
    4480,  4482,  4483,  4486,  4487,  4488,  4490,  4495,  4500,  4506,
    4508,  4509,  4512,  4513,  4516,  4518,  4527,  4533,  4527,  4544,
    4545,  4549,  4549,  4559,  4559,  4571,  4574,  4577,  4580,  4584,
    4588,  4589,  4590,  4591,  4592,  4596,  4601,  4601,  4604,  4630,
    4689,  4689,  4692,  4696,  4700,  4743,  4785,  4786,  4787,  4790,
    4804,  4816,  4816,  4821,  4822,  4828,  4888,  4945,  4950,  4957,
    4962,  4970,  4976,  5010,  5013,  5014,  5055,  5098,  5099,  5103,
    5104,  5108,  5161,  5165,  5168,  5174,  5185,  5192,  5200,  5200,
    5203,  5204,  5205,  5206,  5207,  5210,  5213,  5219,  5222,  5226,
    5231,  5239,  5244,  5251,  5254,  5260,  5262,  5262,  5262,  5266,
    5286,  5293,  5300,  5303,  5317,  5324,  5325,  5328,  5329,  5333,
    5339,  5344,  5350,  5351,  5356,  5360,  5360,  5364,  5365,  5368,
    5369,  5373,  5381,  5384,  5390,  5391,  5393,  5395,  5399,  5399,
    5400,  5405,  5413,  5414,  5419,  5420,  5422,  5435,  5437,  5438,
    5440,  5443,  5446,  5449,  5453,  5456,  5459,  5463,  5467,  5471,
    5474,  5478,  5481,  5482,  5483,  5486,  5489,  5492,  5495,  5498,
    5501,  5504,  5520,  5528,  5528,  5530,  5537,  5541,  5546,  5561,
    5559,  5578,  5579,  5583,  5588,  5589,  5593,  5594,  5596,  5597,
    5599,  5599,  5607,  5616,  5616,  5626,  5627,  5632,  5633,  5636,
    5649,  5663,  5668,  5673,  5678,  5688,  5688,  5692,  5695,  5695,
    5697,  5707,  5716,  5723,  5725,  5729,  5732,  5732,  5736,  5735,
    5743,  5742,  5753,  5752,  5759,  5758,  5762,  5761,  5764,  5764,
    5780,  5779,  5801,  5802,  5803,  5804,  5805,  5806,  5809,  5809,
    5815,  5815,  5818,  5818,  5834,  5835,  5836,  5845,  5857,  5858,
    5861,  5862,  5865,  5868,  5868,  5873,  5893,  5898,  5904,  5905,
    5906,  5910,  5911,  5912,  5913,  5917,  5927,  5929,  5934,  5937,
    5942,  5948,  5955,  5962,  5971,  5978,  5985,  5992,  5999,  6008,
    6008,  6010,  6010,  6013,  6014,  6015,  6016,  6017,  6018,  6019,
    6020,  6021,  6022,  6025,  6025,  6028,  6029,  6030,  6031,  6034,
    6034,  6037,  6037,  6040,  6041,  6042,  6043,  6044,  6045,  6046,
    6047,  6049,  6050,  6051,  6052,  6054,  6055,  6056,  6057,  6059,
    6060,  6061,  6062,  6063,  6064,  6065,  6066,  6070,  6077,  6086,
    6098,  6107,  6118,  6122,  6126,  6132,  6097,  6145,  6148,  6156,
    6168,  6170,  6175,  6183,  6193,  6196,  6200,  6208,  6174,  6217,
    6221,  6225,  6229,  6221,  6239,  6240,  6241,  6242,  6247,  6249,
    6252,  6256,  6259,  6266,  6271,  6272,  6273,  6278,  6279,  6285,
    6285,  6285,  6290,  6290,  6290,  6301,  6302,  6308,  6309,  6321,
    6322,  6327,  6328,  6329,  6333,  6336,  6342,  6345,  6353,  6354,
    6360,  6367,  6370,  6379,  6382,  6385,  6388,  6391,  6394,  6397,
    6404,  6407,  6414,  6417,  6423,  6426,  6433,  6436,  6443,  6444,
    6449,  6453,  6456,  6462,  6465,  6471,  6478,  6479,  6483,  6489,
    6492,  6499,  6500,  6507,  6510,  6515,  6526,  6527,  6528,  6529,
    6530,  6531,  6532,  6533,  6534,  6537,  6540,  6546,  6546,  6552,
    6552,  6563,  6576,  6586,  6586,  6591,  6591,  6595,  6599,  6600,
    6606,  6607,  6612,  6616,  6623,  6626,  6633,  6637,  6632,  6646,
    6650,  6654,  6661,  6665,  6665,  6678,  6682,  6682,  6697,  6699,
    6701,  6703,  6705,  6707,  6709,  6711,  6717,  6727,  6734,  6739,
    6740,  6744,  6747,  6748,  6751,  6752,  6753,  6756,  6761,  6768,
    6769,  6775,  6787,  6788,  6789,  6792,  6792,  6797,  6802,  6807,
    6808,  6811,  6812,  6817,  6822,  6826,  6831,  6832,  6836,  6843,
    6847,  6848,  6853,  6855,  6859,  6860,  6864,  6865,  6866,  6867,
    6871,  6872,  6877,  6878,  6883,  6884,  6889,  6890,  6895,  6900,
    6901,  6906,  6907,  6911,  6912,  6917,  6924,  6929,  6934,  6938,
    6939,  6944,  6945,  6951,  6953,  6958,  6959,  6965,  6968,  6971,
    6978,  6980,  6994,  6999,  7000,  7003,  7005,  7012,  7015,  7021,
    7025,  7029,  7033,  7036,  7043,  7050,  7055,  7059,  7060,  7066,
    7069,  7080,  7087,  7093,  7096,  7103,  7110,  7116,  7117,  7123,
    7124,  7125,  7128,  7129,  7134,  7134,  7138,  7146,  7147,  7150,
    7153,  7158,  7159,  7164,  7167,  7173,  7176,  7182,  7185,  7191,
    7194,  7201,  7202,  7231,  7232,  7237,  7245,  7250,  7253,  7256,
    7259,  7265,  7266,  7270,  7273,  7276,  7277,  7282,  7285,  7288,
    7291,  7294,  7297,  7300,  7303,  7308,  7314,  7315,  7316,  7317,
    7318,  7320,  7321,  7323,  7324,  7329,  7332,  7336,  7342,  7343,
    7344,  7345,  7357,  7358,  7359,  7363,  7364,  7369,  7371,  7372,
    7373,  7375,  7376,  7377,  7378,  7380,  7381,  7383,  7384,  7386,
    7387,  7388,  7389,  7391,  7395,  7396,  7402,  7404,  7405,  7406,
    7407,  7412,  7416,  7420,  7424,  7425,  7429,  7430,  7440,  7449,
    7450,  7451,  7455,  7458,  7463,  7468,  7473,  7481,  7485,  7489,
    7490,  7491,  7496,  7499,  7502,  7516,  7530,  7543,  7544,  7548,
    7548,  7548,  7548,  7548,  7548,  7549,  7552,  7557,  7557,  7557,
    7557,  7557,  7557,  7559,  7562,  7568,  7568,  7568,  7568,  7568,
    7568,  7568,  7569,  7569,  7569,  7569,  7569,  7569,  7569,  7569,
    7572,  7573,  7574,  7577,  7586,  7586,  7592,  7592,  7599,  7599,
    7605,  7605,  7613,  7614,  7615,  7618,  7618,  7621,  7622,  7623,
    7628,  7631,  7637,  7642,  7649,  7662,  7663,  7660,  7681,  7691,
    7694,  7699,  7711,  7714,  7718,  7721,  7722,  7728,  7731,  7732,
    7741,  7750,  7755,  7756,  7757,  7758,  7765,  7768,  7774,  7777,
    7787,  7796,  7799,  7802,  7808,  7814,  7817,  7820,  7823,  7829,
    7831,  7833,  7835,  7837,  7839,  7840,  7841,  7842,  7843,  7844,
    7845,  7847,  7849,  7851,  7853,  7855,  7857,  7859,  7860,  7865,
    7866,  7873,  7876,  7885,  7889,  7896,  7896,  7900,  7900,  7905,
    7905,  7909,  7909,  7913,  7919,  7919,  7922,  7922,  7928,  7935,
    7936,  7937,  7941,  7942,  7945,  7946,  7950,  7956,  7966,  7967,
    7975,  7976,  7977,  7978,  7979,  7980,  7984,  7985,  7986,  7990,
    7990,  8002,  8003,  8007,  8008,  8009,  8010,  8011,  8012,  8013,
    8014,  8015,  8016,  8017,  8018,  8019,  8020,  8021,  8022,  8023,
    8024,  8025,  8026,  8027,  8028,  8029,  8030,  8031,  8032,  8033,
    8034,  8035,  8036,  8037,  8038,  8039,  8040,  8041,  8042,  8043,
    8044,  8045,  8046,  8047,  8048,  8049,  8050,  8051,  8052,  8053,
    8054,  8055,  8056,  8057,  8058,  8059,  8060,  8061,  8062,  8063,
    8064,  8065,  8066,  8067,  8068,  8069,  8070,  8071,  8072,  8073,
    8074,  8075,  8076,  8077,  8078,  8079,  8080,  8081,  8082,  8083,
    8084,  8085,  8086,  8087,  8088,  8089,  8090,  8091,  8092,  8093,
    8094,  8095,  8096,  8097,  8098,  8099,  8100,  8101,  8102,  8103,
    8104,  8105,  8106,  8107,  8108,  8109,  8110,  8111,  8112,  8113,
    8114,  8115,  8116,  8117,  8118,  8119,  8120,  8121,  8122,  8123,
    8124,  8125,  8126,  8127,  8128,  8129,  8130,  8131,  8132,  8133,
    8134,  8135,  8136,  8137,  8138,  8139,  8140,  8141,  8142,  8143,
    8144,  8145,  8146,  8147,  8148,  8149,  8150,  8151,  8152,  8153,
    8154,  8155,  8156,  8157,  8158,  8159,  8160,  8161,  8162,  8163,
    8164,  8165,  8166,  8167,  8168,  8169,  8170,  8171,  8172,  8173,
    8174,  8175,  8176,  8177,  8178,  8179,  8180,  8181,  8182,  8183,
    8184,  8185,  8186,  8187,  8188,  8189,  8190,  8191,  8192,  8193,
    8194,  8195,  8196,  8197,  8198,  8199,  8200,  8201,  8202,  8203,
    8204,  8205,  8206,  8207,  8208,  8209,  8210,  8211,  8212,  8213,
    8214,  8215,  8216,  8217,  8218,  8219,  8220,  8221,  8222,  8223,
    8224,  8225,  8226,  8227,  8228,  8229,  8230,  8231,  8232,  8233,
    8234,  8235,  8236,  8237,  8238,  8239,  8240,  8241,  8242,  8243,
    8244,  8245,  8246,  8247,  8248,  8249,  8250,  8251,  8252,  8253,
    8254,  8255,  8256,  8257,  8258,  8259,  8260,  8261,  8262,  8263,
    8264,  8265,  8266,  8267,  8268,  8269,  8270,  8271,  8272,  8273,
    8274,  8275,  8276,  8277,  8278,  8279,  8280,  8281,  8282,  8283,
    8284,  8285,  8286,  8287,  8288,  8289,  8290,  8291,  8292,  8293,
    8294,  8295,  8296,  8297,  8298,  8299,  8300,  8301,  8302,  8303,
    8304,  8305,  8306,  8307,  8308,  8309,  8310,  8311,  8312,  8313,
    8314,  8315,  8316,  8317,  8318,  8319,  8320,  8321,  8322,  8323,
    8324,  8325,  8326,  8327,  8328,  8336,  8336,  8343,  8343,  8431,
    8435,  8431,  8444,  8448,  8454,  8462,  8472,  8482,  8494,  8497,
    8516,  8542,  8545,  8551,  8554,  8559,  8562,  8570,  8578,  8591,
    8594,  8602,  8605,  8608,  8616,  8620,  8623,  8626,  8629,  8633,
    8634,  8635,  8636,  8637,  8643,  8644,  8645,  8646,  8647,  8648,
    8649,  8650,  8651,  8652,  8653,  8654,  8655,  8656,  8660,  8666,
    8667,  8675,  8675,  8683,  8683,  8687,  8691,  8706,  8727,  8727,
    8731,  8732,  8733,  8734,  8738,  8739,  8740,  8745,  8771,  8836,
    8838,  8840,  8842,  8846,  8851,  8853,  8856,  8858,  8860,  8864,
    8867,  8872,  8877,  8881,  8890,  8891,  8895,  8907,  8910,  8906,
    8929,  8929,  8933,  8934,  8937,  8938,  8939,  8940,  8941,  8942,
    8943,  8948,  8949,  8953,  8956,  8961,  8965,  8970,  8974,  8979,
    8983,  8986,  8990,  8993,  8998,  9002,  9013,  9019,  9019,  9020,
    9021,  9028,  9037,  9037,  9039,  9040,  9041,  9042,  9043,  9044,
    9045,  9046,  9047,  9048,  9049,  9050,  9051,  9052,  9053,  9054,
    9055,  9056,  9057,  9058,  9059,  9060,  9061,  9062,  9063,  9064,
    9065,  9066,  9067,  9068,  9069,  9070,  9071,  9072,  9073,  9074,
    9075,  9076,  9077,  9078,  9079,  9080,  9081,  9082,  9083,  9084,
    9085,  9086,  9087,  9088,  9089,  9090,  9091,  9092,  9093,  9094,
    9095,  9096,  9097,  9098,  9099,  9100,  9101,  9102,  9103,  9104,
    9105,  9106,  9107,  9108,  9109,  9110,  9111,  9112,  9113,  9114,
    9115,  9116,  9117,  9118,  9119,  9120,  9121,  9122,  9123,  9124,
    9125,  9126,  9127
};
#endif

#if YYDEBUG || YYERROR_VERBOSE
/* YYTNME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals. */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "NAME", "UMINUS", "COMMA", "KW_OR", 
  "KW_AND", "KW_USING", "NOT", "MATCHES", "POWER", "LESS_THAN", 
  "GREATER_THAN", "EQUAL", "GREATER_THAN_EQ", "LESS_THAN_EQ", "NOT_EQUAL", 
  "PLUS", "MINUS", "MULTIPLY", "DIVIDE", "MOD", "COMMAND", "NUMBER_VALUE", 
  "CHAR_VALUE", "INT_VALUE", "NAMED_GEN", "CLINE", "SQLLINE", "KW_CSTART", 
  "KW_CEND", "USER_DTYPE", "SQL_TEXT", "DYNAMIC_ARRAY", "RESIZE_ARRAY", 
  "ALLOCATE_ARRAY", "DEALLOCATE_ARRAY", "BEFORE_INSERT", "CONCAT_PIPES", 
  "BEFORE_DELETE", "AFTER_INSERT", "AFTER_DELETE", "EXECUTE_IMMEDIATE", 
  "DELETE_ROW_EQUAL_TRUE", "INSERT_ROW_EQUAL_TRUE", 
  "DELETE_ROW_EQUAL_FALSE", "INSERT_ROW_EQUAL_FALSE", 
  "CURRENT_ROW_DISPLAY_EQUAL", "MAXCOUNT", "ALTER_TABLE", 
  "WHENEVER_ERROR_CONTINUE", "WHENEVER_WARNING_CONTINUE", 
  "XSET_MULTIPLY_EQUAL_OPEN_BRACKET", 
  "XSET_ident_DOT_MULTIPLY_EQUAL_OPEN_BRACKET", 
  "XSET_ident_DOT_MULTIPLY_EQUAL", "XSET_MULTIPLY_EQUAL", 
  "XSET_OPEN_BRACKET", "NEWFORMATSHARED", "CREATE_DATABASE", 
  "IMPORT_LEGACY_FUNCTION", "ADD_CONSTRAINT", "DROP_CONSTRAINT", 
  "AS_STATIC", "NOT_FIELD_TOUCHED", "LOCAL_FUNCTION", "EVERY_ROW", "ELIF", 
  "DOUBLE_PRECISION", "COUNT_MULTIPLY", "WAIT_FOR_KEY", 
  "AT_TERMINATION_CALL", "TERMINATE_REPORT", "TO_MAIN_CAPTION", 
  "CLEARSTAT", "TO_MENUITEM", "ID_TO_INT", "TO_STATUSBOX", 
  "ASCII_HEIGHT_ALL", "ASCII_WIDTH_ALL", "IMPORT_DATATYPE", 
  "PAGE_TRAILER_SIZE", "PAGE_HEADER_SIZE", "FIRST_PAGE_HEADER_SIZE", 
  "BYTES_USE_AS_IMAGE", "BYTES_USE_AS_ASCII", "KWUP_BY", "KWDOWN_BY", 
  "CLOSE_STATUSBOX", "MODIFY_NEXT_SIZE", "LOCK_MODE_PAGE", 
  "LOCK_MODE_ROW", "TO_PIPE", "TO_PRINTER", "STATUSBOX", "CONNECT_TO", 
  "FORMHANDLER_INPUT", "UNITS_YEAR", "UNITS_MONTH", "UNITS_DAY", 
  "UNITS_HOUR", "UNITS_MINUTE", "UNITS_SECOND", "NO_NEW_LINES", 
  "FIELDTOWIDGET", "WITH_HOLD", "SHOW_MENU", "CWIS", "CREATE_IDX", 
  "FORM_IS_COMPILED", "PDF_REPORT", "IMPORT_FUNCTION", "PROMPT_MANY", 
  "POINTS", "MM", "INCHES", "PREPEND", "MEMBER_OF", "MEMBER_FUNCTION", 
  "APPEND", "TEMPLATE", "END_TEMPLATE", "SQLSICS", "CREATE_SCHEMA", 
  "SQLSIRR", "UPDATESTATS_T", "SQLSICR", "WHENEVER_SQLSUCCESS", 
  "WHENEVER_SQLWARNING", "START_EXTERN", "WHENEVER_ANY_ERROR", 
  "WHENEVER_NOT_FOUND", "CONTINUE_CONSTRUCT", "FOUNCONSTR", "SQLSIDR", 
  "WHENEVER_SQLERROR", "CREATE_TEMP_TABLE", "CURRENT_WINDOW_IS", 
  "FIRST_PAGE_HEADER", "ORDER_EXTERNAL_BY", "SCROLL_CURSOR_FOR", 
  "SCROLL_CURSOR", "SQL_INTERRUPT_OFF", "STOP_ALL_EXTERNAL", 
  "WITH_CHECK_OPTION", "WITH_GRANT_OPTION", "SQLSLMNW", "ADDCONSTUNIQ", 
  "CONTINUE_DISPLAY", "CONTINUE_FOREACH", "OUTPUT_TO_REPORT", 
  "SQL_INTERRUPT_ON", "WHENEVER_SUCCESS", "WHENEVER_WARNING", 
  "WHERE_CURRENT_OF", "WITHOUT_DEFAULTS", "FOCONSTR", "SCALED_BY", 
  "CONTINUE_PROMPT", "PDF_FUNCTION", "DEFER_INTERRUPT", "DISPLAY_BY_NAME", 
  "NOT_NULL_UNIQUE", "SKIP_TO_TOP", "TOP_OF_PAGE", "SKIP_TO", "SKIP_BY", 
  "WITHOUT_WAITING", "BEFCONSTRUCT", "SQLSLMW", "WHENEVER_ERROR", 
  "AFTCONSTRUCT", "ALL_PRIVILEGES", "CLOSE_DATABASE", "CONTINUE_INPUT", 
  "CONTINUE_WHILE", "CREATE_SYNONYM", "DROP_TABLE", "EXIT_CONSTRUCT", 
  "INEXCLUSIVE", "REPORT_TO_PRINTER", "REPORT_TO_PIPE", "RETURN", 
  "SET_SESSION_TO", "UPDATESTATS", "WITHOUT_HEAD", "CLEARSCR", 
  "WITH_B_LOG", "AUTHORIZATION", "BOTTOM_MARGIN", "CLOSE_SESSION", 
  "CONTINUE_CASE", "CONTINUE_MENU", "DISPLAY_ARRAY", "END_SQL", "DOLLAR", 
  "END_CONSTRUCT", "FIELD_TOUCHED", "FINISH_REPORT", "INFACC", 
  "INPUT_NO_WRAP", "LOCKMODEPAGE", "SETPMOFF", "UNCONSTRAINED", 
  "PAGE_TRAILER", "SETPMON", "BEFGROUP", "CLOSE_WINDOW", "COMMENT_LINE", 
  "CONTINUE_FOR", "CREATE_DB", "CREATE_TABLE", "DEFAULT_NULL", 
  "DELETE_USING", "DISPLAY_FORM", "END_FUNCTION", "EXIT_DISPLAY", 
  "EXIT_FOREACH", "EXIT_PROGRAM", "INFCOLS", "LOCKMODEROW", 
  "ON_EVERY_ROW", "OPEN_SESSION", "RIGHT_MARGIN", "SELECT_USING", 
  "START_REPORT", "UNLOCK_TABLE", "UPDATE_USING", "ACL_BUILTIN", 
  "AFTGROUP", "INFIDX", "INFSTAT", "LEFT_MARGIN", "PAGE_HEADER", 
  "ROLLBACK_W", "SET_SESSION", "SQLSEOFF", "WITH_A_LOG", "BEFDISP", 
  "BEFORE_MENU", "CREATE_VIEW", "DEFINE_TYPE", "DELETE_FROM", 
  "END_DISPLAY", "END_REPORT", "END_FOREACH", "END_FOR", "END_GLOBALS", 
  "EXIT_PROMPT", "EXTENT_SIZE", "FOREIGN_KEY", "HIDE_OPTION", 
  "HIDE_WINDOW", "INSERT_INTO", "IS_NOT_NULL", "MOVE_WINDOW", 
  "NEXT_OPTION", "NOT_MATCHES", "ON_LAST_ROW", "OPEN_WINDOW", 
  "OPEN_STATUSBOX", "PAGE_LENGTH", "PAGE_WIDTH", "PRIMARY_KEY", 
  "PROMPT_LINE", "RECORD_LIKE", "ROLLFORWARD", "SETBL", "SHOW_OPTION", 
  "SHOW_WINDOW", "SQLSEON", "TO_DATABASE", "USE_SESSION", "WITH_NO_LOG", 
  "AFTDISP", "BEFFIELD", "INSHARE", "UNLOCKTAB", "AFTFIELD", "ATTRIBUTES", 
  "BEFINP", "BEGIN_WORK", "CLEARWIN", "CLOSE_FORM", "DEFER_QUIT", 
  "DESCENDING", "DROP_INDEX", "END_PROMPT", "END_RECORD", "ERROR_LINE", 
  "EXIT_INPUT", "EXIT_WHILE", "FOR_UPDATE_OF", "FOR_UPDATE", "GET_FLDBUF", 
  "INITIALIZE", "INPUT_WRAP", "LOCK_TABLE", "MSG_LINE", "NOT_EXISTS", 
  "ON_ANY_KEY", "REFERENCES", "RENCOL", "SET_CURSOR", "SMALLFLOAT", 
  "SQLSUCCESS", "TOP_MARGIN", "WITH_ARRAY", "ACCEPTKEY", "ACCEPT", 
  "AFTINP", "CLEARFORMTODEFAULTS", "CLEARFORM", "CLEAR_X_FORM", 
  "COMMIT_W", "NEXTPAGE", "PREVPAGE", "CTRL_KEY", "INFTABS", "NEXTFIELD", 
  "NEXTFORM", "RENTAB", "ASCENDING", "ASSOCIATE", "CHAR", "CONSTRUCT", 
  "DELIMITER", "DOWNSHIFT", "DROP_VIEW", "END_INPUT", "END_WHILE", 
  "EXCLUSIVE", "EXIT_CASE", "EXIT_MENU", "FORM_LINE", "INTERRUPT", 
  "INTO_TEMP", "INVISIBLE", "IN_MEMORY", "LINKED_TO", "LOAD_FROM", 
  "LOCKTAB", "MENU_LINE", "OPEN_FORM", "OTHERWISE", "PRECISION", "PRIOR", 
  "PROCEDURE", "REPORT_TO", "RETURNING", "UNDERLINE", "UNLOAD_TO", 
  "BEFROW", "UNLOAD_T", "VARIABLE", "ABSOLUTE", "AFTROW", "BUFFERED", 
  "CONSTANT", "CONST", "CONTINUE", "DATABASE", "DATETIME", "DEFAULTS", 
  "DISTINCT", "END_CASE", "END_MAIN", "END_MENU", "END_TYPE", "EXIT_FOR", 
  "EXTERNAL", "FRACTION", "FUNCTION", "GROUP_BY", "INTERVAL", "KWMESSAGE", 
  "NOT_LIKE", "NOT_ILIKE", "NOT_NULL", "PASSWORD", "PREVIOUS", "READONLY", 
  "REGISTER", "RELATIVE", "RESOURCE", "SMALLINT", "VALIDATE", "WHENEVER", 
  "WITH_LOG", "WORDWRAP", "BY_NAME", "IN_FILE", "IS_NULL", "AVERAGE", 
  "BETWEEN", "CAPTION", "CLIPPED", "CLOSE_BRACKET", "COLUMNS", "COMMENT", 
  "CONNECT", "CURRENT", "DBYNAME", "DECIMAL", "DECLARE", "DEFAULT", 
  "DISPLAY", "ENDCODE", "EXECUTE", "FOREACH", "FOREIGN", "GLOBALS", 
  "INFIELD", "INTEGER", "KWWINDOW", "MAGENTA", "NUMERIC", "OPTIONS", 
  "PERCENT", "PREPARE", "PROGRAM", "RECOVER", "REVERSE", "SECTION", 
  "SESSION", "SYNONYM", "THRU", "TRAILER", "UPSHIFT", "VARCHAR", 
  "WAITING", "CLOSE_SHEV", "CLOSE_SQUARE", "KW_FALSE", "NOT_IN", "ONKEY", 
  "OPEN_BRACKET", "BORDER", "BOTTOM", "COLUMN", "COMMIT", "CREATE", 
  "CURSOR", "DEFINE", "DELETE", "DOUBLE", "END_IF", "ESCAPE", "EXISTS", 
  "EXTEND", "EXTENT", "FINISH", "FORMAT", "HAVING", "HEADER", "INSERT", 
  "LOCATE", "MARGIN", "MEMORY", "MINUTE", "MODIFY", "NORMAL", 
  "EQUAL_EQUAL", "OPEN_SHEV", "OPEN_SQUARE", "OPTION", "OUTPUT", "PROMPT", 
  "PUBLIC", "RECORD", "REPORT", "REVOKE", "SCHEMA", "SCROLL_USING", 
  "SCROLL", "SECOND", "SELECT", "SERIAL", "SETL", "SHARED", "SPACES", 
  "UNIQUE", "UNLOCK", "UPDATE", "VALUES", "YELLOW", "AFTER", "KWLINE", 
  "KW_NULL", "KW_TRUE", "SINGLE_KEY", "ALTER", "ARRAY", "ASCII", "AUDIT", 
  "BLACK", "BLINK", "CHECK", "CLEAR", "CLOSE", "CODE_C", "COUNT", "DEFER", 
  "ERROR", "EVERY", "FETCH", "FIRST", "FLOAT", "FLUSH", "FOUND", "GRANT", 
  "GREEN", "GROUP", "INDEX", "KWFORM", "LABEL", "LOCAL", "MONEY", "MONTH", 
  "ORDER", "OUTER", "PAUSE", "PRINT_IMAGE", "PRINT_FILE", "PRINT", 
  "RIGHT", "DOUBLE_COLON", "SEMICOLON", "SLEEP", "TUPLE", "UNION", 
  "WHERE", "WHILE", "WHITE", "CCODE", "ANSI", "BLUE", "BOLD", "BYTE", 
  "FCALL", "CASE", "CYAN", "DATE", "DESC", "KWDOWN", "TAB", "DROP", 
  "ELSE", "EXEC", "EXIT", "FREE", "FROM", "GOTO", "HELP_FILE", 
  "LANG_FILE", "HELP", "HIDE", "HOUR", "INTO", "LAST", "LEFT", "LIKE", 
  "MAIN", "MENU", "MODE", "NEED", "NEXT", "NOCR", "OPEN", "QUIT", "REAL", 
  "ROWS", "SHOW", "SIZE", "SKIP", "SOME", "STEP", "STOP", "TEMP", "TEXT", 
  "THEN", "USER", "WAIT", "WHEN", "WITH", "WORK", "YEAR", "KW_IS", "XSET", 
  "ADD", "ALL", "ANY", "ASC", "AVG", "COLON", "DAY", "DBA", "DEC", "DIM", 
  "FKEY", "FOR", "KEY", "KWNO", "LET", "LOG", "XMAX", "XMIN", "PAD", 
  "PUT", "RED", "ROW", "RUN", "SQL", "SUM", "TOP", "USE", "ATSIGN", 
  "AS_TIFF", "AS_GIF", "AS_PNG", "AS_JPEG", "AS", "AT", "BY", "DOT", "GO", 
  "IF", "IN", "OF", "ON", "TO", "KWUP", "FONT_NAME", "FONT_SIZE", 
  "PAPER_SIZE_IS_LETTER", "PAPER_SIZE_IS_LEGAL", "PAPER_SIZE_IS_A5", 
  "PAPER_SIZE_IS_A4", "PAPER_SIZE_IS_LETTER_L", "PAPER_SIZE_IS_LEGAL_L", 
  "PAPER_SIZE_IS_A5_L", "PAPER_SIZE_IS_A4_L", "FORMHANDLER", 
  "END_FORMHANDLER", "BEFORE_EVENT", "BEFORE_OPEN_FORM", "AFTER_EVENT", 
  "BEFORE_CLOSE_FORM", "BEFORE_ANY", "AFTER_ANY", "MENUHANDLER", 
  "END_MENUHANDLER", "BEFORE_SHOW_MENU", "DISABLE_PROGRAM", "DISABLE_ALL", 
  "BUTTONS", "CHECK_MENUITEM", "DISABLE_FORM", "DISABLE_MENUITEMS", 
  "DISABLE", "ENABLE_FORM", "ENABLE_MENUITEMS", "ENABLE", "KWFIELD", 
  "ICON", "MESSAGEBOX", "TO_DEFAULTS", "UNCHECK_MENUITEM", "BEFORE", 
  "INPUT", "END", "INT_TO_ID", "TIMEOUT", "OFF", "WITH_1_DIMENSION", 
  "WITH_2_DIMENSION", "WITH_3_DIMENSION", "TILDE", "ILIKE", 
  "FGL_ISDYNARR_ALLOCATED", "FGL_DYNARR_EXTENTSIZE", "$accept", 
  "pause_screen_on_cmd", "pause_screen_off_cmd", "start_rpc_cmd", 
  "stop_rpc_cmd", "valid_port", "remote_func_list", "remote_func", 
  "arr_expr", "arr_next_math", "arr_int_sign", "opt_attributes", 
  "attributes_def", "@1", "attribs_sec", "attribute", "win_attributes", 
  "win_attributes_def", "@2", "wattribs_sec", "wattribute", "call_cmd", 
  "call_ext", "@3", "@4", "@5", "@6", "@7", "@8", "@9", "@10", "@11", 
  "@12", "@13", "@14", "@15", "opt_return", "opt_return_remote", 
  "opt_func_call_args", "func_call_args", "func_arg", "remote_host_name", 
  "remote_func_name", "case_cmd", "@16", "@17", "when_unit", 
  "when_unit_expr", "end_case_command", "op_otherwise_command", "@18", 
  "op_otherwise_command_expr", "@19", "when_command", "@20", 
  "when_command_expr", "@21", "close_cmd", "code_cmd", "emb_code", 
  "sql_code", "sql_code_part", "c_code", "c_code_part", "comment_cmd", 
  "construct_cmd", "@22", "@23", "constr_rest", "end_constr", 
  "constr_col_list", "constr_col", "constr_extra_commands", 
  "constr_extra_command", "@24", "@25", "@26", "@27", "@28", 
  "bef_c_field_list", "aft_c_field_list", "interval_expr", 
  "extend_parameters", "op_datetime_qual", "defer_cmd", "define_section", 
  "define_multiple", "define_set", "@29", "@30", "def_part", 
  "define_ident", "@31", "def_part2", "@32", "constant_value", 
  "var_def_name", "var_def_list", "op_char", "ranking", "array_variable", 
  "@33", "@34", "@35", "assoc_open_bracket", "assoc_close_bracket", 
  "number_arr_assoc", "number_arr_list", "number_value_arr", 
  "record_variable", "@36", "@37", "@38", "link_to_pk_list", "link_to_pk", 
  "dtype_ident", "op_as_static", "dtype2", "@39", "@40", "dtype", 
  "like_var", "tab_name", "col_name", "datetime_qual", "interval_qual", 
  "dtime_start", "@41", "dtime_val", "dtime_end", "@42", "opt_frac", 
  "opt_unit_size", "dtfrac", "int_start", "@43", "int_start_unit", 
  "int_end", "op_equal", "dim_section", "@44", "dim_dtype", 
  "dim_like_var", "dim_array_variable", "@45", "@46", 
  "dim_record_variable", "@47", "@48", "dim_def_part", "dim_def_part2", 
  "dim_var_def_list", "dim_var_def_name", "opt_at", "display_b_n_cmd", 
  "display_cmd", "display_form_cmd", "display_array_cmd", "@49", "@50", 
  "opt_scroll", "display_attr", "disp_rest", "disp_field_commands", 
  "disp_field_command", "@51", "@52", "@53", "alloc_arr_cmd", 
  "dealloc_arr_cmd", "resize_arr_cmd", "error_cmd", "ext_cmd", 
  "continue_cmd", "exit_prog_cmd", "fgl_expr_c", "fgl_next", 
  "op_fgl_expr_ret_list", "fgl_expr_ret", "fgl_expr_ret_list", 
  "fgl_expr_list", "fgl_expr_concat", "fgl_expr", "int_sign", 
  "boolean_expr", "initial_expr", "literal_expr", "variable_entry_2", 
  "variable_entry", "report_only_expr", "@54", "and_or_expr", 
  "inexpr_list", "in_expr", "null_expr", "string_match_expr", "clip_expr", 
  "using_expr", "math_expr", "comparison_expr", "reset_cnt", 
  "function_call_expr2", "@55", "@56", "@57", "@58", "function_callb", 
  "@59", "@60", "@61", "@62", "@63", "@64", "@65", "@66", "op_extend_d", 
  "op_extend_i", "function_call_expr", "builtin_expr", "builtin_funcs", 
  "pdf_expr", "interval_func_params", "numeric_time_interval", 
  "numeric_time_unit_small", "numeric_time_unit_big", "field_name_list", 
  "for_cmd", "@67", "@68", "for_step", "foreach_cmd", "@69", "@70", "@71", 
  "opt_foreach_using_part", "formhandler_def", "@72", "@73", 
  "op_input_section", "op_bef_ev_list", "bef_ev_list", "bef_ev", "@74", 
  "@75", "op_aft_ev_list", "aft_ev_list", "aft_ev", "@76", "@77", 
  "input_section", "input_sub_section", "in_variable_list", "in_id_list", 
  "in_bn_variable_list", "field_ops", "field_op", "@78", "@79", "@80", 
  "@81", "@82", "free_cmd", "line_no", "file_name", "a_number", "coords", 
  "display_coords", "field_name", "cursor_name", "fetch_cursor_name", 
  "win_name", "open_win_name", "form_name", "open_form_name", 
  "opt_help_no", "identifier", "ident_or_var", "ident_p2", 
  "var_or_string", "field_name2", "cvariable", "real_number", "goto_cmd", 
  "check_menu_cmd", "menu_item_list", "menu_item", "uncheck_menu_cmd", 
  "disable_cmd", "enable_cmd", "msg_box_cmd", "@83", "op_disable_msg", 
  "gm_disable_msg", "op_returning_msg", "gm_returning_msg", "op_caption", 
  "gm_caption", "op_icon", "gm_icon", "op_buttons", "gm_buttons", 
  "op_def_but", "if_cmd", "@84", "@85", "op_else", "@86", "@87", "@88", 
  "import_m", "module_import", "init_cmd", "@89", "init_tab_list", 
  "init_tab", "end_input", "opt_defs", "field_commands", "field_command", 
  "@90", "@91", "@92", "@93", "@94", "@95", "@96", "@97", "@98", "@99", 
  "@100", "bef_field_list", "aft_field_list", "next_field_cmd", 
  "next_form_cmd", "next_field", "input_cmd", "@101", "inp_rest", "@102", 
  "scroll_cmd", "up_or_down", "op_help", "input_array_attributes", 
  "input_array_attributes_int", "on_key_command", "@103", "key_val", 
  "@104", "accept_key", "single_key_val", "key_do", "key_value_list", 
  "key_value", "key_value_1", "label_cmd", "let_cmd", "@105", "@106", 
  "op_expr_null", "linked_cmd", "linked_del_cmd", "linked_upd_cmd", 
  "locate_cmd", "module", "@107", "op_module_header", "module_header", 
  "module_entry", "func_main_def", "func_or_main2", "at_term_cmd", 
  "func_or_main", "module_code", "op_code", "module_define_section", 
  "ldeffunction", "func_def", "@108", "@109", "@110", "@111", 
  "end_func_command", "main_def", "@112", "@113", "return_cmd", 
  "op_fgl_expr_list", "db_section", "module_globals_section", 
  "actual_globals_section", "xglobals_entry", "globals_entry", "@114", 
  "glob_section", "mem_func_def", "@115", "@116", "@117", "menu_cmd", 
  "@118", "end_menu_command", "menu_block_command", "@119", "@120", 
  "@121", "menu_commands", "opt_key", "menu_opt_name", 
  "menu_optional_desc", "next_option_cmd", "show_option_cmd", 
  "hide_option_cmd", "opt_name", "opt_name_list", "menu_title", 
  "menu_def", "@122", "@123", "menu_handler_elements", 
  "menu_handler_element", "@124", "@125", "message_cmd", "msg_next", 
  "gui_message", "msg_start", "op_msg_wait", "msg_wait", "variable", 
  "var_int", "varsetidentdot", "var", "assoc_var_read", "assoc_var_write", 
  "assoc_sub", "dot_part_var", "array_r_variable", 
  "array_r_variable_or_ident", "arr_subscripts", "num_list", 
  "num_list_element", "let_variable", "let_var", "let_var_dot", 
  "let_array_r_variable", "op_param_var_list", "fparam_var_list", 
  "ibind_var_list", "func_def_var", "ibind_var", "obind_var_list", 
  "obind_var", "obind_var_let_list", "obind_let_var", "use_arr_var", 
  "obind_var_list_ord", "obind_var_ord", "optional_asc_desc", 
  "array_r_varid", "init_bind_var_list", "init_bind_var", 
  "open_window_cmd", "op_at_statusbox", "op_size_statusbox", 
  "open_statusbox_cmd", "formhandler_name", "open_form_cmd", 
  "open_form_rest", "open_form_gui", "op_at_gui", "op_like_gui", 
  "op_absolute", "open_session_cmd", "open_cursor_cmd", "user_details", 
  "op_disable", "connect_cmd", "op_connect_as", "con_user_details", 
  "options_cmd", "opt_options", "opt_allopts", "prepare_cmd", 
  "var_or_char", "execute_cmd", "stmt_id", "prompt_cmd", "@126", 
  "opt_timeout", "gui_prompt_cmd", "opt_char", "prompt_key_sec", 
  "prompt_key_clause", "on_key_command_prompt", "@127", "prompt_title", 
  "put_cmd", "@128", "put_from", "put_val_list", "put_val", "start_cmd", 
  "rout", "rep_name", "op_values", "output_cmd", "finish_cmd", 
  "term_rep_cmd", "report_section", "format_section", "format_actions", 
  "format_action", "@129", "@130", "@131", "@132", "@133", "@134", "@135", 
  "report_cmd", "need_command", "@136", "op_lines", "skip_command", 
  "@137", "opt_rep_expr_list", "xrep_expr_list", "xxrep_expr_list", 
  "opt_print_at", "print_command", "print_file_command", 
  "print_img_command", "opt_scaling", "img_types", "blob_var", "opt_semi", 
  "rep_expr_list", "rep_expr", "rep_agg", "op_output_section", 
  "output_commands", "output_command", "pdf_output_commands", "nval", 
  "nval_number", "pdf_op_output_section", "pdf_output_command", 
  "op_rep_order_by", "report_def", "@138", "@139", "@140", "@141", "@142", 
  "@143", "rep_where", "pause_command", "pause_msg", "pdf_report_def", 
  "@144", "@145", "@146", "@147", "@148", "@149", "pdf_report_section", 
  "pdf_functions", "@150", "@151", "@152", "op_wordwrap", "run_cmd", 
  "drops_cmd", "drops_c", "create_cmd", "create_c_2_ss", "@153", "@154", 
  "@155", "@156", "create_c_1", "op_no_log", "idx_column_list", 
  "idx_column", "table_element_list_ss", "table_element_ss", 
  "upd_stats_cmd", "alter_cmd", "alter_clauses_ss", "alter_clause_ss", 
  "alter_add_clause_ss", "add_column_clause_ss", "add_column_clauses_ss", 
  "alter_drop_clause", "drop_column_list", "drop_column", 
  "alter_modify_clause", "modify_column_clauses_ss", 
  "modify_column_clause_ss", "alter_lock_mode", "alter_modify_next", 
  "alter_add_constraint_clause", "alter_drop_contraint_clause", 
  "column_constraints_ss", "constraint_name", "set_cmd", "op_conn_id", 
  "op_fgl_expr", "sleep_cmd", "rollback_statement", "insert_statement_ss", 
  "@157", "ins_2_ss", "@158", "op_insert_column_list", 
  "insert_column_list", "insert_value_list_ss", "insert_value_ss", 
  "fetch_statement", "@159", "@160", "declare_cursor_name", "fetch_part", 
  "opt_into_fetch_part", "@161", "opt_foreach_into_fetch_part", "@162", 
  "fetch_place", "delete_statement_position", 
  "delete_statement_search_ss", "order_by_clause", 
  "sort_specification_list", "sort_specification", "sort_spec", 
  "op_asc_desc", "begin_statement", "commit_statement", "op_exclusive", 
  "set_database_cmd", "var_ident_qchar", "sql_cmd", "@163", 
  "sql_commands", "privilege_definition", "op_with_grant_option", 
  "privileges", "action_list", "action", "op_grant_column_list", 
  "grant_column_list", "grantee_list", "grantee", "view_definition_ss", 
  "op_view_column_list", "view_column_list", "op_with_check_option", 
  "check_constraint_definition_ss", "referential_constraint_definition", 
  "references_specification", "references_columns", 
  "referenced_table_and_columns", "references_column_list", 
  "unique_constraint_definition", "unique_column_list", 
  "table_constraint_definition_ss", "default_clause", 
  "ct_column_definiton_ss", "op_default_clause", 
  "op_column_constraint_list_ss", "column_constraint_list_ss", 
  "column_constraint_ss", "schema_ss", "schema_authorization_clause", 
  "schema_authorization_identifier", "schema_element_list_ss", 
  "schema_element_ss", "having_clause_ss", "group_by_clause_ss", 
  "column_specification_list_ss", "where_clause_ss", "from_clause", 
  "table_reference_list", "table_reference", "tname", "tname_list", 
  "table_expression_ss", "op_where_clause_ss", "op_group_by_clause_ss", 
  "op_having_clause_ss", "search_condition_ss", "boolean_term_ss", 
  "boolean_factor_ss", "boolean_primary_ss", "exists_predicate_ss", 
  "op_escape", "pattern_ss", "escape_character", "in_predicate_ss", 
  "in_value_list", "in_value_specification", "op_not", 
  "comparison_predicate_ss", "comp_op", "predicate_ss", "op_all", 
  "data_type", "char_string_type", "exact_numeric_type", "op_scale", 
  "approx_numeric_type", "length", "precision", "scale", "table_name", 
  "authorization_identifier", "col_arr", "column_name", 
  "column_name_specific", "correlation_name", "literal", "curr_v_clause", 
  "curr_clause", "cur_part", "cur_v_part", "s_curr_v", "e_curr_v", 
  "s_curr", "e_curr", "dbase_name", "flush_cmd", "declare_cmd", "@164", 
  "@165", "@166", "@167", "curs_forupdate", "cur_update_list", "colident", 
  "cursor_specification_all_ss", "cursor_specification_sel_ss", 
  "select_statement_full_ss", "select_statement_ss", "@168", "@169", 
  "in_select_statement_ss", "select_statement2_ss", 
  "select_statement21_ss", "sel_p2_ss", "tmp_tabname", "opt_into_sel_ss", 
  "query_specification_ss", "subquery_ss", "op_ad", "select_list_ss", 
  "value_expression_pls_ss", "column_specification_ss", 
  "value_expression_ss", "value_expression_initial_ss", 
  "value_expression_complex_ss", "value_expr_list_ss", 
  "value_specification", "unload_cmd", "load_cmd", "opt_delim", 
  "char_or_var", "opt_col_list", "col_list", "simple_column_name", 
  "ufile", "opt_use", "conn_id", "misc_sql", "rename_stmt", "rentabname", 
  "rencolname", "unlock_stmt", "lock_stmt", "share_or_exclusive", 
  "units_qual", "extend_qual_ss", "sql_block_cmd", "@170", "sql_block", 
  "sql_block_entry", "in_var", "@171", "sql_block_into", "@172", 
  "update_statement_ss", "@173", "@174", "where_upd_ss", 
  "set_clause_list_ss", "upd_columns_ss", "upd_column_name", "col_1_ss", 
  "upd_col_list", "upd_val_list_ss", "upd_val_ss", 
  "upd_value_expression_ss", "upd_value_expression_initial_ss", 
  "upd_value_expression_complex_ss", "upd_var_ident_ibind_ss", 
  "upd_value_expr_list_ss", "validate_cmd", "@175", "validate_tab_list", 
  "validate_tab", "var_ident", "var2", "var3", "aft_dot", 
  "var_ident_ibind_ss", "whenever_cmd", "when_do", "label_goto", 
  "function_name_when", "while_cmd", "@176", "@177", "op_clr_fields", 
  "op_to_defs", "clear_cmd", "fld_list", "current_win_cmd", "window_type", 
  "show_cmd", "op_mnfile", "menu_name", "menu_handler", "hide_cmd", 
  "move_cmd", "NAMED", "commands", "all_commands", "command1", 
  "commands_all", "@178", "commands_all1", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const unsigned short yytoknum[] =
{
       0,   256,  1666,  1667,  1668,  1574,  1614,  1569,  1506,  1589,
    1385,  1492,  1488,  1403,  1564,  1301,  1360,  1434,  1600,  1587,
    1493,  1520,  1588,  1367,  1669,  1670,  1671,  1672,  1673,  1674,
    1675,  1676,  1677,  1678,  1000,  1001,  1002,  1003,  1004,  1005,
    1006,  1007,  1008,  1009,  1010,  1011,  1012,  1013,  1014,  1015,
    1016,  1017,  1018,  1019,  1020,  1021,  1022,  1023,  1024,  1025,
    1026,  1027,  1028,  1029,  1030,  1031,  1032,  1033,  1034,  1035,
    1036,  1037,  1038,  1039,  1040,  1041,  1042,  1043,  1044,  1045,
    1046,  1047,  1048,  1049,  1050,  1051,  1052,  1053,  1054,  1055,
    1056,  1057,  1058,  1059,  1060,  1061,  1062,  1063,  1064,  1065,
    1066,  1067,  1068,  1069,  1070,  1071,  1072,  1073,  1074,  1075,
    1076,  1077,  1078,  1079,  1080,  1081,  1082,  1083,  1084,  1085,
    1086,  1087,  1088,  1089,  1090,  1091,  1092,  1093,  1094,  1095,
    1096,  1097,  1098,  1099,  1100,  1101,  1102,  1103,  1104,  1105,
    1106,  1107,  1108,  1109,  1110,  1111,  1112,  1113,  1114,  1115,
    1116,  1117,  1118,  1119,  1120,  1121,  1122,  1123,  1124,  1125,
    1126,  1127,  1128,  1129,  1130,  1131,  1132,  1133,  1134,  1135,
    1136,  1137,  1138,  1139,  1140,  1141,  1142,  1143,  1144,  1145,
    1146,  1147,  1148,  1149,  1150,  1151,  1152,  1153,  1154,  1155,
    1156,  1157,  1158,  1159,  1160,  1161,  1162,  1163,  1164,  1165,
    1166,  1167,  1168,  1169,  1170,  1171,  1172,  1173,  1174,  1175,
    1176,  1177,  1178,  1179,  1180,  1181,  1182,  1183,  1184,  1185,
    1186,  1187,  1188,  1189,  1190,  1191,  1192,  1193,  1194,  1195,
    1196,  1197,  1198,  1199,  1200,  1201,  1202,  1203,  1204,  1205,
    1206,  1207,  1208,  1209,  1210,  1211,  1212,  1213,  1214,  1215,
    1216,  1217,  1218,  1219,  1220,  1221,  1222,  1223,  1224,  1225,
    1226,  1227,  1228,  1229,  1230,  1231,  1232,  1233,  1234,  1235,
    1236,  1237,  1238,  1239,  1240,  1241,  1242,  1243,  1244,  1245,
    1246,  1247,  1248,  1249,  1250,  1251,  1252,  1253,  1254,  1255,
    1256,  1257,  1258,  1259,  1260,  1261,  1262,  1263,  1264,  1265,
    1266,  1267,  1268,  1269,  1270,  1271,  1272,  1273,  1274,  1275,
    1276,  1277,  1278,  1279,  1280,  1281,  1282,  1283,  1284,  1285,
    1286,  1287,  1288,  1289,  1290,  1291,  1292,  1293,  1294,  1295,
    1296,  1297,  1298,  1299,  1300,  1302,  1303,  1304,  1305,  1306,
    1307,  1308,  1309,  1310,  1311,  1312,  1313,  1314,  1315,  1316,
    1317,  1318,  1319,  1320,  1321,  1322,  1323,  1324,  1325,  1326,
    1327,  1328,  1329,  1330,  1331,  1332,  1333,  1334,  1335,  1336,
    1337,  1338,  1339,  1340,  1341,  1342,  1343,  1344,  1345,  1346,
    1347,  1348,  1349,  1350,  1351,  1352,  1353,  1354,  1355,  1356,
    1357,  1358,  1359,  1361,  1362,  1363,  1364,  1365,  1366,  1368,
    1369,  1370,  1371,  1372,  1373,  1374,  1375,  1376,  1377,  1378,
    1379,  1380,  1381,  1382,  1383,  1384,  1386,  1387,  1388,  1389,
    1390,  1391,  1392,  1393,  1394,  1395,  1396,  1397,  1398,  1399,
    1400,  1401,  1402,  1404,  1405,  1406,  1407,  1408,  1409,  1410,
    1411,  1412,  1413,  1414,  1415,  1416,  1417,  1418,  1419,  1420,
    1421,  1422,  1423,  1424,  1425,  1426,  1427,  1428,  1429,  1430,
    1431,  1432,  1433,  1435,  1436,  1437,  1438,  1439,  1440,  1441,
    1442,  1443,  1444,  1445,  1446,  1447,  1448,  1449,  1450,  1451,
    1452,  1453,  1454,  1455,  1456,  1457,  1458,  1459,  1460,  1461,
    1462,  1463,  1464,  1465,  1466,  1467,  1468,  1469,  1470,  1471,
    1472,  1473,  1474,  1475,  1476,  1477,  1478,  1479,  1480,  1481,
    1482,  1483,  1484,  1485,  1486,  1487,  1489,  1490,  1491,  1494,
    1495,  1496,  1497,  1498,  1499,  1500,  1501,  1502,  1503,  1504,
    1505,  1507,  1508,  1509,  1510,  1511,  1512,  1513,  1514,  1515,
    1516,  1517,  1518,  1519,  1521,  1522,  1523,  1524,  1525,  1526,
    1527,  1528,  1529,  1530,  1531,  1532,  1533,  1534,  1535,  1536,
    1537,  1538,  1539,  1540,  1541,  1542,  1543,  1544,  1545,  1546,
    1547,  1548,  1549,  1550,  1551,  1552,  1553,  1554,  1555,  1556,
    1557,  1558,  1559,  1560,  1561,  1562,  1563,  1565,  1566,  1567,
    1568,  1570,  1571,  1572,  1573,  1575,  1576,  1577,  1578,  1579,
    1580,  1581,  1582,  1583,  1584,  1585,  1586,  1590,  1591,  1592,
    1593,  1594,  1595,  1596,  1597,  1598,  1599,  1601,  1602,  1603,
    1604,  1605,  1606,  1607,  1608,  1609,  1610,  1611,  1612,  1613,
    1615,  1616,  1617,  1618,  1619,  1620,  1621,  1622,  1623,  1624,
    1625,  1626,  1627,  1628,  1629,  1630,  1631,  1632,  1633,  1634,
    1635,  1636,  1637,  1638,  1639,  1640,  1641,  1642,  1643,  1644,
    1645,  1646,  1647,  1648,  1649,  1650,  1651,  1652,  1653,  1654,
    1655,  1656,  1657,  1658,  1659,  1660,  1661,  1662,  1663,  1664,
    1665
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const unsigned short yyr1[] =
{
       0,   681,   682,   683,   684,   685,   686,   686,   687,   687,
     688,   689,   689,   689,   689,   689,   689,   690,   690,   690,
     690,   690,   691,   691,   692,   692,   694,   693,   693,   695,
     695,   696,   696,   696,   696,   696,   696,   696,   696,   696,
     696,   696,   696,   696,   696,   696,   696,   696,   697,   697,
     699,   698,   700,   700,   701,   701,   701,   701,   701,   701,
     701,   701,   701,   702,   703,   704,   703,   703,   703,   703,
     703,   705,   706,   703,   707,   708,   709,   703,   710,   711,
     703,   712,   713,   703,   714,   715,   716,   703,   717,   717,
     718,   718,   718,   719,   719,   720,   720,   721,   722,   722,
     723,   723,   725,   724,   726,   724,   727,   727,   728,   728,
     729,   730,   731,   730,   732,   733,   732,   735,   734,   737,
     736,   738,   738,   738,   738,   738,   738,   739,   740,   740,
     741,   741,   742,   743,   743,   744,   745,   747,   748,   746,
     749,   749,   750,   750,   751,   751,   752,   752,   752,   753,
     753,   755,   754,   756,   754,   757,   754,   758,   754,   759,
     754,   760,   760,   761,   761,   762,   762,   762,   762,   762,
     762,   763,   764,   764,   765,   765,   766,   766,   767,   767,
     769,   770,   768,   768,   768,   771,   771,   773,   772,   774,
     774,   774,   774,   774,   775,   774,   776,   776,   776,   776,
     777,   778,   778,   779,   779,   780,   780,   780,   780,   782,
     781,   783,   781,   784,   781,   785,   785,   786,   786,   787,
     788,   788,   788,   789,   791,   790,   792,   790,   793,   790,
     794,   794,   795,   796,   797,   797,   799,   800,   798,   801,
     801,   801,   801,   801,   801,   801,   801,   801,   801,   801,
     801,   801,   801,   801,   801,   801,   801,   801,   801,   801,
     801,   801,   801,   801,   801,   801,   801,   802,   803,   804,
     805,   805,   806,   808,   807,   809,   809,   809,   809,   809,
     809,   809,   811,   810,   812,   812,   813,   813,   814,   816,
     815,   817,   817,   817,   817,   817,   817,   817,   818,   819,
     819,   821,   820,   822,   822,   822,   822,   822,   822,   822,
     822,   822,   822,   822,   822,   822,   822,   822,   822,   822,
     822,   822,   822,   822,   822,   822,   823,   825,   824,   826,
     824,   828,   827,   829,   827,   830,   830,   831,   832,   832,
     833,   834,   834,   834,   834,   834,   834,   834,   834,   835,
     836,   837,   839,   840,   838,   841,   841,   842,   843,   843,
     843,   844,   844,   846,   845,   847,   845,   848,   845,   849,
     850,   851,   852,   852,   853,   853,   853,   853,   853,   853,
     853,   853,   853,   854,   854,   854,   854,   854,   854,   854,
     854,   855,   855,   856,   856,   856,   856,   856,   856,   856,
     856,   856,   856,   857,   857,   857,   857,   857,   857,   857,
     857,   857,   857,   857,   858,   858,   859,   859,   860,   860,
     861,   861,   862,   862,   863,   864,   864,   865,   865,   865,
     865,   865,   865,   866,   866,   867,   867,   867,   867,   868,
     868,   869,   870,   870,   870,   871,   870,   872,   872,   873,
     873,   874,   874,   874,   874,   875,   875,   876,   876,   876,
     876,   876,   876,   876,   876,   877,   878,   879,   879,   879,
     879,   879,   879,   880,   880,   880,   880,   880,   880,   880,
     881,   883,   884,   882,   885,   886,   882,   888,   889,   887,
     890,   891,   887,   892,   893,   887,   894,   895,   887,   887,
     887,   887,   887,   887,   887,   896,   896,   897,   898,   898,
     898,   898,   898,   898,   898,   898,   898,   899,   899,   900,
     900,   900,   900,   901,   901,   901,   902,   902,   903,   903,
     903,   904,   904,   904,   904,   904,   904,   904,   904,   904,
     904,   905,   905,   906,   906,   908,   909,   907,   910,   910,
     912,   913,   914,   911,   915,   915,   917,   918,   916,   919,
     919,   920,   920,   921,   921,   923,   922,   924,   922,   925,
     925,   926,   926,   928,   927,   929,   927,   930,   931,   931,
     931,   932,   932,   933,   933,   934,   934,   935,   935,   937,
     936,   938,   936,   939,   936,   940,   936,   941,   936,   942,
     943,   943,   943,   943,   943,   943,   943,   944,   944,   945,
     946,   947,   948,   948,   948,   948,   948,   948,   948,   948,
     949,   950,   951,   952,   953,   954,   955,   955,   956,   957,
     958,   958,   959,   959,   960,   960,   960,   960,   960,   960,
     961,   962,   962,   963,   964,   965,   965,   966,   967,   968,
     968,   968,   969,   969,   969,   971,   970,   972,   972,   973,
     973,   974,   974,   975,   976,   976,   977,   978,   978,   979,
     980,   980,   981,   982,   982,   984,   985,   983,   986,   987,
     986,   988,   989,   986,   990,   990,   991,   993,   992,   992,
     994,   994,   995,   995,   996,   996,   996,   997,   997,   998,
     998,  1000,   999,  1001,   999,  1002,   999,  1003,   999,  1004,
     999,  1005,   999,  1006,   999,  1007,   999,  1008,   999,  1009,
     999,  1010,   999,  1011,  1011,  1012,  1012,  1013,  1014,  1015,
    1015,  1015,  1017,  1016,  1018,  1018,  1019,  1018,  1020,  1021,
    1021,  1021,  1021,  1022,  1022,  1023,  1024,  1024,  1024,  1024,
    1024,  1024,  1024,  1024,  1024,  1026,  1025,  1025,  1028,  1027,
    1029,  1030,  1031,  1031,  1032,  1032,  1033,  1034,  1034,  1034,
    1034,  1034,  1034,  1034,  1034,  1034,  1034,  1034,  1034,  1034,
    1034,  1034,  1034,  1034,  1034,  1035,  1037,  1038,  1036,  1039,
    1039,  1040,  1041,  1042,  1043,  1043,  1045,  1044,  1046,  1046,
    1047,  1047,  1048,  1048,  1048,  1048,  1049,  1049,  1050,  1050,
    1051,  1052,  1052,  1052,  1052,  1052,  1052,  1052,  1052,  1052,
    1052,  1052,  1053,  1053,  1054,  1054,  1054,  1055,  1056,  1056,
    1058,  1059,  1060,  1061,  1057,  1062,  1064,  1065,  1063,  1066,
    1067,  1067,  1068,  1068,  1069,  1070,  1070,  1071,  1071,  1071,
    1073,  1072,  1074,  1074,  1076,  1077,  1078,  1075,  1080,  1079,
    1081,  1083,  1082,  1084,  1082,  1085,  1082,  1086,  1086,  1087,
    1087,  1088,  1088,  1089,  1089,  1089,  1090,  1091,  1092,  1093,
    1093,  1093,  1094,  1094,  1095,  1095,  1097,  1098,  1096,  1099,
    1099,  1101,  1100,  1102,  1100,  1103,  1104,  1104,  1104,  1104,
    1105,  1105,  1105,  1105,  1105,  1106,  1107,  1107,  1108,  1109,
    1110,  1110,  1111,  1112,  1112,  1112,  1112,  1112,  1112,  1113,
    1114,  1115,  1115,  1116,  1116,  1117,  1118,  1119,  1119,  1120,
    1120,  1121,  1122,  1123,  1123,  1123,  1123,  1123,  1123,  1124,
    1124,  1125,  1126,  1126,  1127,  1127,  1128,  1128,  1129,  1129,
    1130,  1130,  1130,  1130,  1130,  1131,  1131,  1132,  1132,  1133,
    1133,  1134,  1135,  1136,  1136,  1137,  1138,  1138,  1138,  1139,
    1140,  1140,  1141,  1141,  1142,  1143,  1143,  1144,  1144,  1145,
    1146,  1147,  1148,  1148,  1149,  1150,  1150,  1151,  1151,  1152,
    1152,  1153,  1154,  1154,  1155,  1155,  1155,  1155,  1156,  1156,
    1156,  1157,  1158,  1158,  1159,  1159,  1159,  1160,  1161,  1161,
    1162,  1162,  1162,  1162,  1162,  1162,  1162,  1162,  1162,  1162,
    1162,  1162,  1162,  1162,  1162,  1162,  1162,  1162,  1162,  1162,
    1162,  1162,  1163,  1164,  1164,  1165,  1165,  1165,  1166,  1168,
    1167,  1169,  1169,  1170,  1171,  1171,  1172,  1172,  1173,  1173,
    1175,  1174,  1176,  1178,  1177,  1179,  1179,  1180,  1180,  1181,
    1181,  1182,  1182,  1182,  1182,  1183,  1183,  1184,  1185,  1185,
    1186,  1187,  1188,  1189,  1190,  1190,  1191,  1191,  1193,  1192,
    1194,  1192,  1195,  1192,  1196,  1192,  1197,  1192,  1198,  1192,
    1199,  1192,  1200,  1200,  1200,  1200,  1200,  1200,  1202,  1201,
    1203,  1203,  1205,  1204,  1204,  1204,  1204,  1204,  1206,  1206,
    1207,  1207,  1208,  1209,  1209,  1210,  1211,  1212,  1213,  1213,
    1213,  1214,  1214,  1214,  1214,  1215,  1216,  1216,  1217,  1217,
    1218,  1219,  1219,  1219,  1219,  1219,  1219,  1219,  1219,  1220,
    1220,  1221,  1221,  1222,  1222,  1222,  1222,  1222,  1222,  1222,
    1222,  1222,  1222,  1223,  1223,  1224,  1224,  1224,  1224,  1225,
    1225,  1226,  1226,  1227,  1227,  1227,  1227,  1227,  1227,  1227,
    1227,  1227,  1227,  1227,  1227,  1227,  1227,  1227,  1227,  1227,
    1227,  1227,  1227,  1227,  1227,  1227,  1227,  1228,  1228,  1228,
    1230,  1231,  1232,  1233,  1234,  1235,  1229,  1236,  1236,  1237,
    1238,  1238,  1240,  1241,  1242,  1243,  1244,  1245,  1239,  1246,
    1248,  1249,  1250,  1247,  1251,  1251,  1251,  1251,  1252,  1252,
    1252,  1252,  1252,  1253,  1254,  1254,  1254,  1255,  1255,  1257,
    1258,  1256,  1259,  1260,  1256,  1261,  1261,  1262,  1262,  1263,
    1263,  1264,  1264,  1264,  1265,  1265,  1266,  1266,  1267,  1267,
    1268,  1269,  1269,  1270,  1270,  1270,  1270,  1270,  1270,  1270,
    1271,  1271,  1272,  1272,  1273,  1273,  1274,  1274,  1275,  1275,
    1276,  1277,  1277,  1278,  1278,  1279,  1280,  1280,  1281,  1282,
    1282,  1283,  1283,  1284,  1284,  1285,  1286,  1286,  1286,  1286,
    1286,  1286,  1286,  1286,  1286,  1286,  1286,  1287,  1287,  1288,
    1288,  1289,  1290,  1292,  1291,  1294,  1293,  1293,  1295,  1295,
    1296,  1296,  1297,  1297,  1298,  1298,  1300,  1301,  1299,  1302,
    1303,  1303,  1304,  1305,  1304,  1306,  1307,  1306,  1308,  1308,
    1308,  1308,  1308,  1308,  1308,  1308,  1309,  1310,  1311,  1312,
    1312,  1313,  1314,  1314,  1315,  1315,  1315,  1316,  1317,  1318,
    1318,  1319,  1320,  1320,  1320,  1322,  1321,  1323,  1323,  1323,
    1323,  1323,  1323,  1323,  1323,  1323,  1323,  1323,  1323,  1324,
    1325,  1325,  1326,  1326,  1327,  1327,  1328,  1328,  1328,  1328,
    1329,  1329,  1330,  1330,  1331,  1331,  1332,  1332,  1333,  1334,
    1334,  1335,  1335,  1336,  1336,  1337,  1338,  1339,  1340,  1341,
    1341,  1342,  1342,  1343,  1343,  1344,  1344,  1345,  1345,  1345,
    1346,  1346,  1347,  1348,  1348,  1349,  1349,  1350,  1350,  1351,
    1351,  1351,  1351,  1351,  1352,  1353,  1354,  1355,  1355,  1356,
    1356,  1357,  1358,  1359,  1359,  1360,  1361,  1362,  1362,  1363,
    1363,  1363,  1364,  1364,  1365,  1365,  1366,  1367,  1367,  1368,
    1368,  1369,  1369,  1370,  1370,  1371,  1371,  1372,  1372,  1373,
    1373,  1374,  1374,  1375,  1375,  1376,  1377,  1378,  1378,  1378,
    1378,  1379,  1379,  1380,  1380,  1381,  1381,  1382,  1382,  1382,
    1382,  1382,  1382,  1382,  1382,  1382,  1383,  1383,  1383,  1383,
    1383,  1383,  1383,  1383,  1383,  1384,  1384,  1384,  1385,  1385,
    1385,  1385,  1386,  1386,  1386,  1387,  1387,  1388,  1388,  1388,
    1388,  1388,  1388,  1388,  1388,  1388,  1388,  1388,  1388,  1388,
    1388,  1388,  1388,  1388,  1389,  1389,  1390,  1390,  1390,  1390,
    1390,  1391,  1392,  1393,  1394,  1394,  1394,  1394,  1395,  1396,
    1396,  1396,  1397,  1397,  1398,  1398,  1398,  1399,  1400,  1400,
    1400,  1400,  1400,  1401,  1402,  1403,  1403,  1404,  1404,  1405,
    1405,  1405,  1405,  1405,  1405,  1405,  1405,  1406,  1406,  1406,
    1406,  1406,  1406,  1406,  1406,  1407,  1407,  1407,  1407,  1407,
    1407,  1407,  1408,  1408,  1408,  1408,  1408,  1408,  1408,  1408,
    1409,  1409,  1409,  1410,  1412,  1411,  1413,  1411,  1414,  1411,
    1415,  1411,  1416,  1416,  1416,  1417,  1417,  1418,  1418,  1418,
    1419,  1419,  1420,  1420,  1421,  1423,  1424,  1422,  1425,  1426,
    1426,  1427,  1428,  1428,  1428,  1428,  1428,  1429,  1430,  1430,
    1431,  1432,  1433,  1433,  1433,  1433,  1434,  1434,  1435,  1435,
    1436,  1437,  1437,  1437,  1438,  1438,  1438,  1438,  1438,  1439,
    1439,  1439,  1439,  1439,  1439,  1439,  1439,  1439,  1439,  1439,
    1439,  1439,  1439,  1439,  1439,  1439,  1439,  1439,  1439,  1440,
    1440,  1441,  1442,  1443,  1443,  1444,  1444,  1445,  1445,  1446,
    1446,  1447,  1447,  1448,  1449,  1449,  1450,  1450,  1451,  1452,
    1452,  1452,  1453,  1453,  1454,  1455,  1456,  1457,  1458,  1458,
    1459,  1459,  1459,  1459,  1459,  1459,  1460,  1460,  1460,  1462,
    1461,  1463,  1463,  1464,  1464,  1464,  1464,  1464,  1464,  1464,
    1464,  1464,  1464,  1464,  1464,  1464,  1464,  1464,  1464,  1464,
    1464,  1464,  1464,  1464,  1464,  1464,  1464,  1464,  1464,  1464,
    1464,  1464,  1464,  1464,  1464,  1464,  1464,  1464,  1464,  1464,
    1464,  1464,  1464,  1464,  1464,  1464,  1464,  1464,  1464,  1464,
    1464,  1464,  1464,  1464,  1464,  1464,  1464,  1464,  1464,  1464,
    1464,  1464,  1464,  1464,  1464,  1464,  1464,  1464,  1464,  1464,
    1464,  1464,  1464,  1464,  1464,  1464,  1464,  1464,  1464,  1464,
    1464,  1464,  1464,  1464,  1464,  1464,  1464,  1464,  1464,  1464,
    1464,  1464,  1464,  1464,  1464,  1464,  1464,  1464,  1464,  1464,
    1464,  1464,  1464,  1464,  1464,  1464,  1464,  1464,  1464,  1464,
    1464,  1464,  1464,  1464,  1464,  1464,  1464,  1464,  1464,  1464,
    1464,  1464,  1464,  1464,  1464,  1464,  1464,  1464,  1464,  1464,
    1464,  1464,  1464,  1464,  1464,  1464,  1464,  1464,  1464,  1464,
    1464,  1464,  1464,  1464,  1464,  1464,  1464,  1464,  1464,  1464,
    1464,  1464,  1464,  1464,  1464,  1464,  1464,  1464,  1464,  1464,
    1464,  1464,  1464,  1464,  1464,  1464,  1464,  1464,  1464,  1464,
    1464,  1464,  1464,  1464,  1464,  1464,  1464,  1464,  1464,  1464,
    1464,  1464,  1464,  1464,  1464,  1464,  1464,  1464,  1464,  1464,
    1464,  1464,  1464,  1464,  1464,  1464,  1464,  1464,  1464,  1464,
    1464,  1464,  1464,  1464,  1464,  1464,  1464,  1464,  1464,  1464,
    1464,  1464,  1464,  1464,  1464,  1464,  1464,  1464,  1464,  1464,
    1464,  1464,  1464,  1464,  1464,  1464,  1464,  1464,  1464,  1464,
    1464,  1464,  1464,  1464,  1464,  1464,  1464,  1464,  1464,  1464,
    1464,  1464,  1464,  1464,  1464,  1464,  1464,  1464,  1464,  1464,
    1464,  1464,  1464,  1464,  1464,  1464,  1464,  1464,  1464,  1464,
    1464,  1464,  1464,  1464,  1464,  1464,  1464,  1464,  1464,  1464,
    1464,  1464,  1464,  1464,  1464,  1464,  1464,  1464,  1464,  1464,
    1464,  1464,  1464,  1464,  1464,  1464,  1464,  1464,  1464,  1464,
    1464,  1464,  1464,  1464,  1464,  1464,  1464,  1464,  1464,  1464,
    1464,  1464,  1464,  1464,  1464,  1464,  1464,  1464,  1464,  1464,
    1464,  1464,  1464,  1464,  1464,  1464,  1464,  1464,  1464,  1464,
    1464,  1464,  1464,  1464,  1464,  1466,  1465,  1468,  1467,  1470,
    1471,  1469,  1472,  1472,  1472,  1473,  1473,  1473,  1473,  1473,
    1473,  1474,  1474,  1475,  1476,  1477,  1477,  1478,  1478,  1479,
    1479,  1480,  1480,  1480,  1481,  1481,  1481,  1481,  1481,  1481,
    1481,  1481,  1481,  1481,  1482,  1482,  1482,  1482,  1482,  1482,
    1482,  1482,  1482,  1482,  1482,  1482,  1482,  1482,  1483,  1484,
    1484,  1486,  1485,  1487,  1487,  1488,  1488,  1489,  1490,  1490,
    1491,  1491,  1491,  1491,  1492,  1492,  1492,  1493,  1493,  1494,
    1494,  1494,  1494,  1494,  1494,  1494,  1494,  1494,  1494,  1495,
    1495,  1495,  1495,  1495,  1496,  1496,  1497,  1499,  1500,  1498,
    1501,  1501,  1502,  1502,  1503,  1503,  1503,  1503,  1503,  1503,
    1503,  1504,  1504,  1505,  1505,  1506,  1506,  1507,  1507,  1508,
    1508,  1509,  1510,  1511,  1512,  1512,  1513,  1514,  1514,  1515,
    1516,  1516,  1518,  1517,  1519,  1519,  1519,  1519,  1519,  1519,
    1519,  1519,  1519,  1519,  1519,  1519,  1519,  1519,  1519,  1519,
    1519,  1519,  1519,  1519,  1519,  1519,  1519,  1519,  1519,  1519,
    1519,  1519,  1519,  1519,  1519,  1519,  1519,  1519,  1519,  1519,
    1519,  1519,  1519,  1519,  1519,  1519,  1519,  1519,  1519,  1519,
    1519,  1519,  1519,  1519,  1519,  1519,  1519,  1519,  1519,  1519,
    1519,  1519,  1519,  1519,  1519,  1519,  1519,  1519,  1519,  1519,
    1519,  1519,  1519,  1519,  1519,  1519,  1519,  1519,  1519,  1519,
    1519,  1519,  1519,  1519,  1519,  1519,  1519,  1519,  1519,  1519,
    1519,  1519,  1519
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const unsigned char yyr2[] =
{
       0,     2,     1,     1,     5,     1,     1,     1,     1,     3,
       1,     3,     3,     1,     2,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     0,     1,     0,     5,     6,     1,
       3,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     0,     1,
       0,     5,     1,     3,     1,     1,     2,     2,     2,     2,
       2,     2,     2,     2,     3,     0,     7,     8,     6,     1,
       6,     0,     0,     9,     0,     0,     0,     8,     0,     0,
      10,     0,     0,     9,     0,     0,     0,    14,     0,     2,
       0,     2,     1,     0,     1,     1,     3,     1,     1,     1,
       1,     3,     0,     6,     0,     5,     1,     2,     1,     2,
       1,     0,     0,     3,     0,     0,     3,     0,     4,     0,
       4,     2,     2,     2,     1,     2,     2,     3,     1,     1,
       1,     2,     1,     1,     2,     1,     1,     0,     0,     5,
       7,     8,     0,     2,     1,     3,     1,     3,     3,     1,
       2,     0,     4,     0,     4,     0,     3,     0,     3,     0,
       3,     1,     3,     1,     3,     1,     1,     1,     1,     1,
       1,     4,     0,     4,     1,     1,     0,     1,     1,     2,
       0,     0,     5,     1,     1,     1,     3,     0,     2,     4,
       4,     4,     4,     2,     0,     4,     1,     1,     1,     2,
       1,     1,     3,     0,     1,     0,     1,     1,     1,     0,
       7,     0,     5,     0,    12,     1,     1,     1,     1,     1,
       5,     3,     1,     1,     0,     4,     0,     5,     0,     7,
       1,     3,     1,     1,     0,     1,     0,     0,     4,     1,
       1,     1,     4,     4,     6,     1,     2,     1,     1,     1,
       1,     4,     6,     1,     4,     6,     1,     1,     1,     1,
       1,     1,     1,     2,     2,     1,     1,     4,     1,     1,
       0,     3,     3,     0,     2,     1,     1,     1,     1,     1,
       1,     2,     0,     2,     0,     3,     0,     3,     1,     0,
       3,     1,     1,     1,     1,     1,     1,     2,     1,     0,
       1,     0,     5,     1,     1,     1,     4,     4,     6,     1,
       1,     1,     1,     4,     6,     1,     4,     6,     1,     1,
       1,     1,     1,     2,     2,     1,     4,     0,     7,     0,
      12,     0,     4,     0,     5,     1,     3,     2,     1,     3,
       1,     0,     2,     2,     1,     2,     5,     4,     2,     4,
       5,     3,     0,     0,    11,     0,     2,     1,     0,     2,
       1,     1,     2,     0,     3,     0,     3,     0,     3,     2,
       2,     2,     4,     5,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     2,     1,     1,     1,     1,     2,     1,     1,
       1,     2,     2,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     2,     1,     2,     1,     1,     1,     3,
       1,     3,     1,     3,     1,     1,     1,     2,     1,     1,
       3,     4,     4,     2,     2,     1,     1,     1,     1,     1,
       3,     1,     2,     2,     1,     0,     3,     2,     2,     1,
       3,     4,     4,     5,     5,     1,     1,     2,     2,     4,
       4,     2,     2,     4,     4,     1,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       0,     0,     0,     6,     0,     0,     8,     0,     0,     6,
       0,     0,     6,     0,     0,     6,     0,     0,     6,     5,
       5,     5,     7,     4,     6,     0,     3,     1,     1,     4,
       4,     4,     4,     4,     4,     1,     1,     1,     1,     4,
       4,     2,     2,     2,     2,     2,     1,     1,     2,     1,
       1,     1,     2,     4,     6,     6,     3,     5,     5,     3,
       1,     1,     3,     1,     3,     0,     0,    11,     0,     2,
       0,     0,     0,     9,     0,     3,     0,     0,    10,     0,
       1,     0,     1,     1,     2,     0,     3,     0,     3,     0,
       1,     1,     2,     0,     3,     0,     3,     3,     1,     4,
       3,     1,     3,     1,     3,     1,     3,     1,     2,     0,
       3,     0,     3,     0,     4,     0,     4,     0,     4,     2,
       3,     1,     3,     1,     1,     1,     1,     1,     1,     1,
       3,     1,     1,     4,     6,     4,     3,     6,     3,     6,
       1,     1,     1,     1,     1,     1,     0,     2,     1,     1,
       1,     4,     1,     1,     1,     4,     3,     6,     3,     6,
       1,     1,     2,     2,     2,     1,     3,     1,     2,     2,
       2,     4,     2,     2,     4,     0,     8,     0,     1,     1,
       1,     0,     1,     2,     0,     1,     2,     0,     1,     2,
       0,     1,     3,     0,     2,     0,     0,     8,     0,     0,
       3,     0,     0,     7,     5,     2,     2,     0,     5,     4,
       1,     3,     3,     3,     0,     2,     1,     0,     1,     1,
       2,     0,     4,     0,     4,     0,     3,     0,     3,     0,
       3,     0,     3,     0,     3,     0,     3,     0,     3,     0,
       3,     0,     3,     1,     3,     1,     3,     2,     4,     1,
       1,     1,     0,     4,     5,     6,     0,    10,     3,     2,
       2,     1,     1,     0,     2,     1,     2,     3,     3,     3,
       3,     1,     1,     1,     1,     0,     3,     1,     0,     3,
       2,     2,     1,     3,     1,     3,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     0,     0,     7,     1,
       1,     2,     2,     2,     3,     4,     0,     3,     0,     1,
       1,     2,     1,     1,     1,     1,     0,     1,     1,     2,
       2,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     0,     1,     1,     1,     1,     1,
       0,     0,     0,     0,    13,     1,     0,     0,     6,     2,
       1,     2,     2,     2,     1,     1,     2,     1,     1,     1,
       0,     3,     2,     1,     0,     0,     0,    14,     0,     5,
       1,     0,     3,     0,     7,     0,     5,     1,     2,     0,
       1,     1,     1,     0,     1,     1,     2,     2,     2,     1,
       1,     1,     1,     3,     1,     1,     0,     0,     7,     1,
       2,     0,     3,     0,     4,     2,     0,     2,     1,     1,
       1,     1,     1,     1,     1,     3,     0,     1,     1,     1,
       1,     2,     2,     2,     5,     8,     1,     1,     1,     4,
       4,     1,     1,     1,     1,     2,     2,     3,     6,     1,
       3,     1,     1,     1,     3,     6,     9,     1,     1,     1,
       1,     2,     0,     1,     1,     3,     1,     3,     1,     3,
       1,     3,     1,     1,     1,     1,     3,     1,     3,     1,
       3,     1,     1,     1,     3,     2,     0,     1,     1,     4,
       1,     3,     1,     3,     7,     0,     7,     0,     6,     3,
       1,     3,     1,     2,     5,     0,     7,     0,     2,     0,
       1,     5,     2,     5,     0,     5,     6,     4,     0,     1,
       1,     4,     0,     2,     0,     5,     4,     2,     1,     3,
       2,     2,     2,     2,     2,     2,     1,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     1,     1,     1,
       1,     1,     5,     1,     1,     2,     4,     2,     1,     0,
      11,     0,     2,     5,     0,     1,     0,     2,     1,     2,
       0,     3,     1,     0,     4,     0,     2,     1,     3,     1,
       1,     3,     4,     4,     2,     1,     1,     1,     0,     1,
       7,     2,     2,     2,     2,     2,     1,     2,     0,     3,
       0,     3,     0,     3,     0,     3,     0,     3,     0,     4,
       0,     4,     1,     1,     1,     1,     1,     1,     0,     4,
       0,     1,     0,     4,     1,     2,     2,     2,     0,     1,
       1,     2,     2,     0,     2,     3,     3,     5,     0,     2,
       4,     1,     1,     1,     1,     1,     0,     1,     1,     3,
       2,     5,     2,     5,     5,     5,     5,     5,     5,     0,
       2,     1,     2,     2,     2,     2,     2,     2,     1,     2,
       2,     2,     2,     1,     2,     2,     2,     2,     1,     1,
       1,     0,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     1,     1,     1,     1,     1,     1,     1,     1,     2,
       2,     2,     2,     2,     1,     1,     1,     0,     3,     2,
       0,     0,     0,     0,     0,     0,    15,     0,     2,     2,
       0,     1,     0,     0,     0,     0,     0,     0,    15,     2,
       0,     0,     0,    10,     0,     1,     3,     3,     2,     4,
       3,     3,     3,     1,     1,     1,     1,     1,     1,     0,
       0,     7,     0,     0,     8,     3,     2,     0,     1,     1,
       3,     2,     2,     1,     1,     3,     1,     1,     2,     1,
       3,     1,     3,     1,     1,     1,     1,     1,     1,     1,
       2,     4,     1,     3,     1,     3,     2,     4,     1,     3,
       1,     2,     4,     1,     3,     1,     1,     1,     2,     2,
       4,     2,     4,     1,     3,     1,     1,     1,     2,     1,
       1,     1,     1,     1,     2,     6,     6,     0,     1,     0,
       1,     2,     1,     0,     5,     0,     5,     1,     0,     3,
       1,     3,     1,     3,     1,     1,     0,     0,     5,     1,
       2,     1,     0,     0,     3,     0,     0,     3,     1,     1,
       1,     1,     1,     1,     2,     2,     4,     3,     3,     1,
       3,     2,     1,     1,     0,     1,     1,     1,     1,     0,
       1,     3,     1,     3,     1,     0,     3,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     7,
       0,     1,     1,     1,     1,     3,     1,     1,     1,     2,
       0,     3,     1,     3,     1,     3,     1,     1,     6,     0,
       3,     1,     3,     0,     1,     4,     5,     2,     1,     1,
       4,     1,     3,     4,     4,     1,     3,     1,     1,     1,
       2,     1,     4,     0,     1,     0,     1,     1,     2,     1,
       1,     1,     1,     4,     3,     1,     1,     1,     2,     1,
       1,     2,     2,     1,     3,     2,     2,     1,     3,     1,
       2,     4,     1,     2,     1,     3,     4,     0,     1,     0,
       1,     0,     1,     1,     3,     1,     3,     1,     2,     1,
       3,     2,     2,     0,     2,     1,     1,     5,     3,     5,
       3,     1,     3,     1,     1,     0,     1,     3,     3,     3,
       6,     4,     4,     4,     4,     5,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     0,     1,
       1,     1,     1,     1,     1,     1,     4,     5,     1,     5,
       5,     1,     1,     1,     4,     1,     4,     1,     7,     1,
       1,     1,     4,     6,     0,     2,     4,     1,     1,     1,
       1,     1,     1,     1,     3,     1,     1,     3,     1,     0,
       3,     5,     1,     2,     2,     4,     3,     1,     1,     1,
       1,     1,     1,     2,     2,     0,     3,     0,     3,     1,
       1,     1,     1,     1,     1,     1,     4,     1,     1,     1,
       1,     1,     1,     1,     4,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     4,
       1,     3,     1,     3,     0,     7,     0,     8,     0,     6,
       0,     8,     0,     1,     2,     1,     3,     1,     3,     5,
       1,     1,     1,     1,     1,     0,     0,     9,     5,     1,
       1,     6,     0,     3,     1,     3,     4,     1,     0,     2,
       4,     6,     0,     1,     1,     1,     1,     3,     1,     2,
       1,     1,     2,     2,     1,     1,     1,     2,     4,     3,
       2,     3,     3,     3,     1,     1,     1,     1,     1,     1,
       5,     5,     5,     5,     5,     4,     4,     3,     4,     1,
       3,     1,     5,     7,     5,     0,     2,     1,     1,     0,
       3,     1,     3,     1,     1,     1,     0,     3,     1,     1,
       1,     1,     4,     6,     1,     1,     2,     3,     1,     1,
       1,     1,     1,     1,     1,     1,     5,     5,     4,     0,
       4,     1,     2,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     0,     3,     0,     3,     0,
       0,     6,     0,     2,     2,     7,     3,     3,     2,     2,
       2,     1,     3,     1,     3,     1,     3,     1,     3,     1,
       1,     1,     2,     2,     1,     1,     2,     4,     1,     1,
       1,     1,     1,     1,     3,     2,     3,     3,     3,     5,
       5,     5,     5,     5,     4,     4,     3,     4,     1,     1,
       3,     0,     5,     1,     3,     3,     3,     1,     2,     1,
       1,     1,     3,     5,     1,     1,     1,     1,     3,     2,
       2,     2,     1,     2,     2,     1,     2,     2,     2,     1,
       3,     2,     1,     2,     1,     2,     1,     0,     0,     6,
       0,     2,     0,     1,     1,     2,     2,     1,     1,     4,
       3,     1,     3,     1,     2,     5,     2,     2,     5,     0,
       2,     1,     1,     2,     6,     6,     1,     0,     1,     2,
       1,     2,     0,     2,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const unsigned short yydefact[] =
{
     798,     0,  2112,  2115,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   850,   180,     0,   822,   827,
     178,   183,   802,     0,   796,   799,   800,   803,   805,   849,
     804,   844,   845,   847,   184,   135,   132,     0,   128,   130,
     129,   133,  2156,   686,   628,  2119,     0,     0,  2122,     0,
    2118,  2114,  2111,  2109,  2110,  2117,  2116,  2113,   301,  1592,
    1590,   842,   176,   187,   843,   179,   184,     1,   806,   801,
     848,   846,   823,   127,   131,   134,  2126,  2123,     0,  2124,
    2121,     0,     0,     0,   607,     0,     0,   177,   853,   917,
     608,   851,   640,   909,     0,   910,   918,   916,   187,   181,
     200,     0,   185,   201,   236,     0,   829,  1202,     0,     0,
     828,   136,  1190,   836,     0,     0,   819,   821,   818,   820,
     797,   807,   808,   830,   811,   812,   813,   816,   814,   815,
     817,  2125,  2120,     0,  1591,   911,   852,     0,     0,   925,
     923,   924,   913,   912,   299,   187,  1126,   194,   188,   187,
     193,   233,     0,   685,     0,     0,     0,     0,   176,   556,
     886,   809,     0,   333,   319,   203,   305,   270,   289,   310,
     312,   309,     0,   331,     0,   318,   311,   315,   321,   320,
     187,   322,   302,   325,   303,   304,   922,   921,     0,    22,
      23,    13,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   931,     0,   516,   508,    16,   515,   917,    15,     0,
     929,     0,   300,     0,   186,  1127,   182,     0,   200,   202,
     266,   205,   260,   261,   249,   226,   257,   203,   241,   228,
     270,   289,   247,   250,   245,     0,   224,     0,   256,   248,
     253,   259,   258,   187,   262,   187,   239,   240,   237,   265,
       0,     0,     0,     0,   837,   176,   176,     0,     0,   204,
       0,     0,   323,     0,     0,   324,     0,     0,     0,     0,
       0,     0,     0,   268,     0,   919,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   522,     0,
       0,     0,   641,   435,   437,  1197,     0,     0,     0,  1557,
       0,   429,     0,     0,     0,   428,     0,   445,   518,     0,
       0,     0,     0,     0,   521,     0,   394,   393,   400,   441,
     438,   395,   396,   398,   399,   436,   439,   444,   517,   490,
     487,   496,   493,     0,     0,    17,    18,    19,    20,    21,
       0,    14,   481,     0,     0,   927,     0,   189,   192,   190,
     191,     0,   197,   196,   195,   198,   206,   207,   208,   211,
     187,     0,     0,   187,   263,   264,     0,     0,   187,     0,
       0,     0,   246,   234,  1203,     0,     0,  1191,  2162,   557,
     887,   831,     0,   215,   216,     0,     0,   282,   284,   279,
     280,   276,   278,   275,   277,   274,     0,   284,   295,   296,
     292,   294,   291,   293,   286,     0,     0,     0,   335,     0,
     338,   340,   223,     0,   222,     0,   187,     0,  2141,   612,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   540,
     526,   531,     0,   527,   530,   529,     0,     0,    11,   172,
     427,   402,   401,     0,  1132,     0,     0,   443,  1565,  1563,
    1564,  1560,  1562,  1559,  1561,  1553,     0,     0,     0,   442,
       0,     0,     0,     0,     0,     0,     0,   642,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   165,   166,   167,   168,   169,
     170,   523,   524,   525,   456,     0,     0,   455,   465,     0,
       0,   406,     0,     0,   407,   397,   403,   405,   408,   409,
     410,   411,   412,   404,   434,   433,     0,     0,     0,     0,
       0,     0,     0,    12,    93,     0,   930,     0,   914,   199,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     187,   235,   238,   942,   684,   854,   942,     0,  2160,  2162,
    1126,  1686,   824,     0,   942,     0,     0,   306,   271,     0,
       0,   281,   298,   272,   297,     0,   290,     0,   313,     0,
     307,     0,   332,     0,   337,   327,     0,     0,   316,   269,
     326,     0,     0,     0,     0,   514,   511,   510,   513,   509,
     520,   505,   505,     0,   528,     0,   532,     0,   289,   512,
     519,   273,     0,  1198,  1632,     0,     0,     0,     0,     0,
     430,     0,     0,   446,     0,     0,     0,     0,   448,   447,
     466,   457,   472,   475,   476,   473,   479,   478,   477,   467,
     468,   469,   470,   471,   413,   458,   462,   480,   474,   461,
     480,   440,   491,   488,   497,   494,   503,     0,   482,    94,
      95,    97,   484,     0,     0,   236,     0,     0,   242,     0,
       0,   251,     0,   243,   225,   209,     0,   254,   267,   948,
       0,   943,   944,   942,     0,   838,  2161,  2159,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    2143,     0,  1292,  1291,     0,  1293,     0,   387,  1290,  1232,
       0,     5,  1289,   388,   385,     0,   390,   174,   480,  1104,
       0,     0,  1299,   124,   384,   383,  1224,   378,   480,     0,
    1249,  2134,     0,   389,   352,     0,     3,     2,     0,   386,
    1229,     0,     0,   379,   376,   391,     0,     0,     0,     0,
    1297,  1287,   382,     0,     0,     0,     0,     0,     0,     0,
       0,  1286,     0,     0,     0,   175,  1226,   375,   374,     0,
       0,  2138,  2137,     0,     0,     0,   137,  1225,   381,   380,
       0,     0,   377,   480,     0,   480,     0,   550,     0,     0,
       0,     0,     0,     0,   480,   785,  1200,     0,     0,  1108,
       0,  2127,     0,   104,     0,     0,   858,     0,     0,     0,
       0,   786,     0,     0,  1709,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   655,     0,     0,  2164,  2165,  2166,
    2167,  2168,  2169,  2170,  2171,  2172,  2173,  2174,  2175,  2176,
    2177,  2178,  2179,  2180,  2181,  2182,  2183,  2184,  2185,  2186,
    2187,  2188,  2189,  2190,  2191,  2192,  2193,  2194,  2195,  2196,
    2197,  2198,  2199,  2200,  2201,  2202,  2203,  2204,  2205,  2206,
    2207,  2208,  2209,  2210,  2211,  2212,  2213,   896,  2214,  2215,
    2216,  2217,  2218,  2219,  2220,  2221,  2222,  2223,  2224,  2225,
    2226,  2227,  2228,  2229,  2230,  1095,  1097,  1092,  1094,  1093,
    1096,  2231,  2232,  1223,  2233,  1228,  1227,  2234,  2235,  2236,
    2237,  2238,  2239,  2240,  2241,  2242,  2243,  1355,  2244,  2245,
    2246,  2247,  2248,  2249,  2250,  2251,  2252,  2163,   825,   561,
     826,     0,   891,     0,   889,     0,   334,   217,   218,     0,
     283,   288,     0,     0,     0,     0,   336,   339,     0,   221,
       0,     0,     0,   616,     0,   618,  2142,   500,     0,   501,
       0,   542,     0,   539,   536,   507,   499,     0,   171,  1634,
    1635,  1633,     0,   432,  1197,     0,  1558,  1197,   431,  1197,
    1197,  1197,  1197,  1197,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    93,
     928,     0,   212,   227,     0,   187,     0,     0,     0,     0,
       0,  1204,     0,     0,  1192,   371,   369,   370,  1034,  1033,
    1037,     0,     0,  1236,   629,   630,   810,  1067,  1072,  2136,
     622,   123,     0,     0,  2101,  2100,  1002,  2097,  2099,  2151,
       0,  1243,     0,  1239,  1248,     7,     0,     6,     0,  2144,
    1068,     0,  1160,  1159,  1107,  1158,  1106,   424,  1300,  1288,
     839,   414,  1688,  1294,   125,     0,  1071,   122,     0,   792,
      24,   624,   392,     0,   791,  1064,   793,     0,  1298,   880,
     879,   882,   878,   881,  2153,     0,   876,     0,   623,   975,
     877,  2147,     0,  2135,   121,   972,   687,   970,     0,   620,
    2130,   730,   729,   731,   727,     0,     0,   985,   625,  1354,
    1349,  1352,     0,     0,     0,  1038,  1035,     0,  1029,  1031,
    1030,  1028,  1027,     0,     0,     0,  1026,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1016,  1007,  1008,     0,  1052,   422,    24,     0,  2132,   126,
     621,     0,  1201,  1199,  1125,     0,  1677,  1678,  1126,  1214,
    1126,  1109,  1110,  1113,  1128,  1301,     0,     0,     0,     0,
       0,     0,     0,     0,    63,     0,   917,     0,    69,     0,
     102,   599,   643,     0,  1098,   992,  1102,     0,     0,  1053,
    1218,     0,     0,  1105,   647,   644,   645,     0,   649,   650,
       0,   652,   653,     0,   648,   952,   954,     0,     0,   953,
     732,   950,   697,   946,   908,     0,     0,     0,     0,   659,
     660,     0,     0,   906,   903,   904,   900,   901,   902,   895,
     899,   898,     0,     0,     0,     0,     0,     0,   565,   567,
     559,   562,   563,   893,  2162,   888,   890,   832,     0,   285,
     287,   314,   308,     0,     0,   317,   613,   615,     0,     0,
     505,   533,     0,   282,     0,     0,  1658,  1548,  1551,  1659,
    1555,  1549,  1656,     0,     0,  1655,     0,     0,  1657,     0,
       0,     0,     0,     0,  2101,  1550,  1654,  1552,  1646,     0,
    1636,  1638,  1641,  1644,  2107,  1645,  1135,  1566,  1134,  1133,
    1136,  1138,  1137,  1131,   459,   460,   464,   449,     0,   452,
     463,     0,   451,   492,   489,   498,   495,   504,   483,    96,
     485,   915,     0,   232,     0,   230,   252,   244,   236,   255,
     949,   176,   945,   855,   176,     0,     0,     0,  1276,  1277,
       0,     0,     0,  1250,  1251,  1253,  1254,  1255,  1259,  1258,
    1256,  1257,     0,     0,  2098,   926,     0,  1004,     0,     0,
    1242,  1241,     0,  1235,     0,  1535,  1536,     0,  1069,     0,
      24,  1155,  1157,  1156,   417,   418,   415,   416,   962,     0,
       0,   357,    25,   351,     0,     0,  1061,     0,     0,     0,
       0,     0,     0,     0,   979,  1687,     0,     0,   187,     0,
       0,     0,  2132,     0,     0,   138,     0,     0,   989,   981,
     982,   987,  1350,  1351,     0,   905,   420,  2091,   341,     0,
     551,   604,   603,   601,   606,  1010,   605,  1015,  1011,  1014,
     784,   776,   770,   782,   783,   768,   769,   777,   772,   778,
     771,   781,   775,   779,   774,   780,   767,   773,   760,   766,
    1012,  1013,     0,  1020,  1024,  1017,  1018,  1022,  1023,  1021,
    1019,  1025,     0,   794,     0,     0,     0,     0,     0,   742,
     741,   738,  2133,  2140,    24,  1121,  1122,  1123,  1124,  1118,
    1116,  1215,  1130,  1115,  1111,     0,     0,  1112,  2128,     0,
       0,     0,     0,    98,     0,    99,     0,     0,     0,    74,
       0,     0,     0,   111,   106,     0,   885,     0,   884,     0,
     480,  1100,     0,   937,   938,   961,   932,   933,   787,   959,
    1055,  1220,     0,  1222,  1221,  1765,  1883,  1879,  1885,  1917,
    1897,  1888,  1847,  1809,  1937,  1903,  1911,  1800,  1906,  1766,
    1713,  1898,  1805,  1856,  1991,  1835,  1823,  1836,  1935,  1938,
    1905,  1859,  1941,  1725,  1998,  1934,  1962,  1736,  2035,  1824,
    2007,  1718,  1967,  1734,  1795,  1842,  1862,  1957,  1985,  1990,
    1717,  1914,  1943,  1729,  1731,  1754,  1772,  1793,  1803,  1813,
    1866,  1869,  1928,  1939,  1945,  1946,  1963,  2008,  2019,  1716,
    1747,  1771,  1770,  1773,  1779,  1781,  1789,  1799,  1820,  1838,
    1841,  1867,  1875,  1932,  1942,  1952,  1958,  1959,  1961,  1986,
    2016,  2023,  2028,  1737,  1740,  1751,  1757,  1759,  1764,  1767,
    1769,  1776,  1784,  1786,  1787,  1788,  1798,  1808,  1815,  1831,
    1832,  1843,  1861,  1865,  1878,  1894,  1918,  1926,  1936,  1940,
    1947,  1955,  1964,  1974,  1978,  1995,  2001,  2005,  2013,  2018,
    2021,  1760,  1880,  1923,  1745,  1746,  1763,  1768,  1775,  1777,
    1791,  1792,  1802,  1811,  1816,  1818,  1819,  1825,  1833,  1850,
    1851,  1864,  1892,  1896,  1899,  1904,  1908,  1916,  1924,  1925,
    1930,  1948,  1949,  1954,  1960,  1965,  1971,  1972,  1973,  1975,
    1977,  1979,  1988,  2010,  2011,  2012,  2017,  2034,  1720,  1874,
    1882,  1884,  1981,  1722,  1726,  1730,  1735,  1741,  1742,  1755,
    1756,  1758,  1761,  1774,  1790,  1810,  1812,  1822,  1826,  1828,
    1829,  1837,  1846,  1848,  1849,  1860,  1873,  1891,  1909,  1910,
    1927,  1929,  1933,  1944,  1966,  1976,  1984,  2006,  2009,  2024,
    2025,  2026,  1753,  1723,  1743,  1744,  1750,  1821,  1752,  1778,
    1780,  1794,  1871,  1996,  1804,  1806,  1814,  1817,  1839,  1840,
    1845,  1852,  1853,  1854,  2037,  1886,  1887,  1890,  1895,  1900,
    1907,  1912,  1913,  1915,  1922,  1951,  1953,  1969,  1980,  1982,
    1983,  1987,  1992,  1993,  1997,  1999,  2000,  2015,  2020,  2022,
    2027,  2029,  2033,  1881,  2032,  1719,  1721,  1724,  1728,  1738,
    1762,  1782,  1783,  1785,  1796,  1827,  1830,  1870,  1876,  1889,
    1893,  2030,  2031,  1931,  1950,  1956,  1968,  1970,  1989,  1994,
    2004,  2014,  1733,  1727,  1732,  1749,  1801,  1844,  1857,  1858,
    1919,  1921,  2003,  1877,  1834,  1901,  1748,  1797,  1807,  1872,
    1855,  1902,  1739,  1863,  1868,  2002,  1920,     0,  1711,  1714,
    1715,   675,     0,     0,     0,   664,   697,   697,   694,     0,
       0,   698,     0,    26,   663,   666,     0,   673,   669,   907,
     897,  1684,  1685,  1675,  1675,  1319,     0,     0,  1593,     0,
     187,  1302,     0,     0,  1303,  1347,   187,     0,  1348,     0,
    1632,     0,  1316,     0,  1366,  1365,  1364,  1362,  1363,  1361,
    1359,  1356,  1430,  1429,  1357,  1358,  1367,  1614,  1360,  1691,
    1690,  1689,  1368,  2162,  2162,   578,   569,   560,     0,   564,
    2162,   892,   176,     0,   328,   220,     0,     0,  1573,  1571,
    1572,  1568,  1570,  1567,  1569,   506,   502,     0,   538,   537,
     173,  1643,  1642,  1581,  1579,  1580,  1576,  1578,  1575,  1577,
    1554,     0,  1632,     0,     0,  1498,     0,  1498,  1498,  1498,
    1498,  1647,     0,     0,     0,  1447,  1622,  1639,     0,     0,
       0,     0,  1700,  1701,  1702,  1703,  1704,  1705,  1650,     0,
       0,   454,   453,     0,     0,   187,   229,   210,  1205,   176,
    1193,  1420,     0,  1419,     0,  1421,     0,  1422,  1279,     0,
    1285,  1281,  1278,     0,     0,     0,     0,     0,     0,  1275,
    1271,  1409,  1408,  1407,  1247,  1246,     0,  1270,  1266,     0,
    1262,  1260,     0,   633,     0,   632,     0,  1003,     0,     0,
    1001,  2104,  2106,  2105,  2102,  2152,  2149,  1240,     0,     0,
       0,  1233,   480,   349,     0,     0,  1230,   994,  1065,  1066,
    1063,  1062,     0,   883,     0,     0,   609,     0,     0,     0,
     973,   971,     0,   689,   690,     0,     0,  2131,  2139,   728,
       0,   142,     0,   983,   990,     0,     0,   998,  1353,     0,
     187,   344,     0,     0,     0,     0,    24,  1036,   554,     0,
       0,     0,   761,   762,  1009,   795,   423,     0,  1044,   739,
     740,   372,     0,  1126,     0,  1129,  1114,  2162,     0,     0,
       0,   543,     0,     0,     0,     0,    64,    93,     0,     0,
     117,   112,     0,   107,     0,   114,   108,   869,   861,   867,
       0,  1099,     0,  1101,  1103,     0,     0,   941,     0,     0,
       0,     0,  1054,  1219,     0,     0,  1710,  1712,  2162,   646,
     651,   654,   667,   665,   626,     0,   717,   715,   721,   719,
       0,     0,   713,   757,   711,   696,   707,   705,   755,   733,
       0,   699,   709,   951,   947,     0,     0,     0,     0,   672,
       0,     0,     0,     0,     0,     0,     0,  1538,     0,  1425,
    1426,  1696,  1389,  1447,     0,     0,  1694,     0,     0,  1615,
    2039,     0,  1372,  1378,  1377,  1376,  1380,     0,  1373,  1374,
     566,   568,     0,     0,   581,   573,   575,     0,   570,   571,
       0,     0,   589,   591,     0,     0,   587,   894,   833,   219,
       0,   617,   619,   614,     0,   535,   534,     0,     0,  1667,
       0,     0,     0,  1500,  1501,  1499,     0,  1669,     0,     0,
       0,     0,     0,     0,     0,  1637,     0,  1436,  1437,  1439,
    1442,     0,  1448,  1449,     0,     0,  1498,  1624,  1618,  1652,
    1653,  1651,  1649,  2108,   450,   486,     0,   231,  1161,   856,
    1139,  1397,  1399,     0,  1283,     0,     0,     0,     0,     0,
    1273,     0,     0,  1530,  1528,  1505,  1515,  1517,  1513,     0,
    1512,     0,  1521,  1508,  1529,     0,  1520,  1511,  1527,  1519,
    1413,  1502,  1503,  1504,     0,  1268,  1264,     0,     0,  1252,
     631,     0,     0,     0,     0,     0,  2148,     4,     8,    10,
    1534,  1537,     0,   480,   419,     0,     0,     0,   991,     0,
       0,     0,     0,     0,     0,     0,   187,   688,     0,     0,
     159,   157,     0,     0,   139,     0,   149,   155,   697,   144,
     146,     0,   988,   999,  1000,     0,   421,     0,  2092,  2093,
     343,   348,   611,   342,     0,   345,   350,   480,  1325,   602,
     600,     0,   764,  1043,  1045,     0,   373,  1119,  1117,  1216,
    1217,     0,     0,  1210,     0,     0,     0,     0,   100,     0,
       0,    75,    81,    71,  2162,  2162,   110,   105,   119,   115,
       0,   109,   758,   870,   626,  2162,   860,   859,   868,   993,
       0,     0,   939,   940,   934,   960,   480,  1060,  1056,  1057,
    1059,  2036,   957,  2038,   955,   676,   670,   668,     0,    24,
       0,  2162,  2162,  2162,  2162,   723,   701,   725,   703,  2162,
    2162,  2162,  2162,     0,   695,   700,  2162,   626,   753,   751,
     754,   752,     0,     0,    46,    44,    41,    35,    39,    43,
      38,    31,    40,     0,    34,    37,    32,    42,    33,    45,
      36,     0,    29,    47,   745,     0,   674,  1676,     0,  1674,
    1632,  1672,  1619,  1620,  1612,  1598,  1613,     0,     0,     0,
    1032,  1424,  1427,     0,     0,     0,  1337,  1308,  1699,  1698,
    1697,     0,     0,     0,     0,  1332,     0,  1331,     0,  1333,
    1328,  1329,  1330,  1321,  1317,     0,     0,  1379,     0,     0,
     580,   585,     0,     0,  2162,  2162,   558,   572,   595,   583,
     597,  2162,  2162,   593,   577,   588,   824,   329,     0,  1588,
    1586,  1587,  1583,  1585,  1582,  1584,  1556,     0,     0,     0,
    1668,     0,     0,     0,  1666,     0,     0,     0,     0,  1648,
    1665,     0,  1440,     0,  1547,  1443,     0,     0,     0,     0,
    1435,  1453,  1455,  1457,  1497,  1496,  1495,  1459,  1475,     0,
    1450,  1451,  1627,  1237,     0,     0,     0,   213,     0,  1187,
    1206,   824,     0,  1194,  1187,     0,     0,  1280,     0,  1282,
       0,  1539,     0,  1398,     0,  1401,  1542,     0,  1405,     0,
    1272,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1411,     0,  1414,  1415,     0,  1267,     0,  1261,  1263,
    2103,     0,     0,     0,  2150,     0,     0,  1244,   840,     0,
       0,     0,     0,     0,  1295,  2155,  2154,   610,     0,     0,
      48,     0,   693,   692,   691,  1296,   697,  2162,  2162,   151,
     634,   161,   153,   163,   143,   150,  2162,     0,     0,     0,
       0,     0,     0,   187,     0,     0,  1326,   552,     0,   763,
    1041,     0,  2129,     0,    93,   544,     0,    65,     0,     0,
       0,    78,     0,    93,    93,   118,   113,  2162,  2162,   103,
       0,   871,   865,   873,   872,   862,   548,   920,     0,     0,
       0,     0,     0,   678,   657,   671,   627,   734,     0,   718,
     716,   722,   720,     0,  2162,     0,  2162,   714,   712,   708,
     706,   756,   710,    24,   746,     0,     0,     0,    27,     0,
    1679,     0,  1599,     0,     0,  1611,  1594,  1610,  1428,     0,
    1391,     0,  1336,     0,     0,  1695,     0,  1692,  1616,     0,
       0,     0,     0,     0,     0,  2040,  1335,  1334,  1322,  1320,
       0,  1382,     0,  1375,     0,   582,   579,   574,   576,     0,
    2162,  2162,   590,   592,  2162,  2162,     0,  1574,     0,     0,
       0,     0,     0,  1664,  1670,  1660,  1661,  1662,  1663,  1444,
       0,  1438,  1458,     0,  1462,     0,  1475,  1461,     0,     0,
    1476,  1491,  1488,  1489,  1486,  1494,  1493,  1487,  1490,     0,
       0,     0,     0,     0,  1492,     0,     0,     0,  1432,  1433,
    1640,     0,  1452,  1446,  1238,  1625,  1342,  1338,  1339,  1344,
    1343,  1623,  1237,     0,  1185,  1186,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1184,     0,     0,
    1172,  1173,  1174,  1171,  1176,  1177,  1178,  1175,  1162,  1153,
       0,     0,  1209,     0,  2162,     0,  1148,     0,     0,     0,
       0,     0,     0,     0,  1140,  1141,     0,  1073,     0,  1284,
    1423,  1543,     0,  1544,     0,     0,     0,     0,  1404,  1274,
    1403,  1395,  1531,     0,     0,     0,     0,  1532,  1524,  1524,
       0,     0,  1524,  1548,  1410,  1412,  1416,  1417,  1269,  1265,
    1006,     0,   969,     9,     0,  1237,   841,  1070,   355,  1231,
       0,     0,  2146,     0,     0,   974,    49,     0,   743,   160,
     158,     0,  2162,     0,     0,     0,  2162,   156,   145,     0,
     148,   147,     0,   980,   984,  2096,  2095,  2094,   347,     0,
     555,     0,  2162,   765,     0,   626,  1120,     0,  1211,    70,
       0,     0,   101,    68,    93,    76,    82,     0,   120,   116,
     759,  2162,   875,   626,   874,     0,   545,     0,   789,   790,
     788,  1058,   958,   956,   681,   679,     0,   661,   658,     0,
     724,   702,   726,   704,   735,   749,   750,   747,   748,    30,
      28,     0,  1673,  1628,  1600,  1596,  1595,     0,  1390,  1632,
    1393,     0,  1310,  1305,  1304,  1307,     0,  1628,     0,     0,
    2073,  2071,     0,     0,  2059,  2070,     0,     0,  2072,     0,
       0,     0,     0,     0,  2101,  2069,  2065,     0,  2057,  2060,
    2061,  2068,  2064,  2088,     0,  2050,  2049,  2053,  2055,     0,
    2048,     0,  2051,  2042,  1323,  1318,     0,  1381,     0,   586,
     584,   596,   598,   594,     0,     0,     0,  1631,     0,  1708,
       0,     0,  1441,  1460,  1454,  1456,  1463,  1465,  1463,     0,
    1470,  1463,     0,  1468,  1463,     0,  1478,  1477,     0,  1479,
       0,  1431,     0,  1346,  1345,  1341,  1626,   236,  1179,  1180,
    1181,  1183,  1166,  1164,  1163,  1167,  1168,  1165,  1182,  1169,
    1170,  1154,   966,  1189,   963,     0,     0,  1207,     0,  1152,
    1151,  1146,  1144,  1143,  1147,  1145,  1149,  1150,  1142,  1195,
    1400,     0,  1396,  1402,  1546,  1539,  1406,  1506,  1514,     0,
    1516,     0,     0,     0,     0,  1522,  1526,     0,  1418,  1005,
    1245,  1234,     0,    24,     0,     0,   997,     0,    50,   977,
       0,    24,   162,   152,     0,   636,   638,   164,   154,   743,
       0,   346,  1327,     0,  1042,    24,     0,     0,    66,     0,
      79,    88,     0,    72,   866,   863,   549,  2162,   935,     0,
    2162,   677,   656,   662,   626,  1683,     0,  1681,     0,     0,
    1601,  1597,  1392,     0,  1394,  1388,     0,  1309,     0,  1693,
       0,  2063,  2062,     0,     0,  1498,     0,  1498,  1498,  1498,
    1498,  2066,     0,     0,  2046,     0,     0,     0,     0,  2075,
    2047,     0,     0,     0,     0,     0,     0,  2041,     0,  1383,
    1386,  1370,  1384,  1387,   835,   834,   330,  1589,  1706,  1707,
    1445,     0,  1482,  1484,     0,  1471,  1474,  1473,  1481,     0,
    1483,  1463,     0,  1434,  1340,   214,   968,   967,   965,     0,
    1188,  1074,  1078,  1080,     0,  1084,     0,  1082,  1086,  1075,
    1076,     0,   857,     0,     0,  1540,  1545,     0,  1533,  1525,
    1509,  1507,     0,  1510,   356,   353,     0,   995,     0,     0,
       0,   976,   744,   140,   635,    24,   986,   553,  1039,    67,
    1212,    84,     0,     0,    77,    88,    88,  2162,   546,     0,
       0,   680,   736,     0,  1680,  1629,  1622,     0,  1311,     0,
    1622,  2086,     0,     0,  2089,     0,     0,     0,     0,     0,
       0,     0,  2058,  2077,  2078,  2076,  2074,  2056,     0,  2052,
    2054,  2043,  2044,  1324,     0,  1371,  1369,  1464,  1671,  1466,
       0,  1469,  1467,  1485,     0,   964,  2162,  2162,  1088,  2162,
    1090,  2162,  2162,  1077,  1208,  1196,     0,     0,  1523,   358,
     996,  2145,     0,     0,     0,     0,     0,     0,    55,     0,
      54,     0,    52,     0,     0,   141,  1046,    88,    93,    88,
      89,    83,    73,   864,     0,     0,   682,    24,  1682,  1621,
    1630,  1315,     0,  1312,  1314,  1602,  2087,     0,     0,  2085,
       0,     0,     0,     0,  2067,  2084,     0,  1385,  1472,  1480,
    1079,  1081,  2162,  1085,  2162,  1083,  1087,  1541,  1518,   360,
     365,   363,   354,     0,   361,   367,    57,    62,    59,    61,
      58,    60,    56,     0,    51,     0,   637,   639,  1050,  1040,
       0,  1048,  1213,    85,    80,   547,   936,  2162,   737,     0,
    1306,     0,  1603,  1617,  2083,  2090,  2079,  2080,  2081,  2082,
       0,  1089,  1091,  2162,  2162,   359,   362,  2162,    53,     0,
    2162,  1047,  1049,     0,   678,  1313,     0,  1607,  1604,  1605,
    2045,   366,   364,   368,     0,  1051,    86,   683,     0,     0,
       0,   978,    90,     0,  1608,  1606,    92,     0,    87,     0,
      91,  1609
};

/* YYDEFGOTO[NTERM-NUM]. */
static const short yydefgoto[] =
{
      -1,   827,   828,   829,   830,  1046,  2327,  2328,   211,   350,
     212,  1381,  1382,  2176,  2481,  3410,  2945,  2946,  3319,  3411,
    3412,   831,  1174,  2980,  2704,  3336,  2117,  2702,  3201,  2984,
    3332,  2703,  3202,  3418,  3513,  3532,  3334,  3538,   658,   659,
     660,  1494,  2397,   832,  1505,  1179,  1503,  2125,  2407,  2122,
    2405,  2410,  2708,  1504,  2404,  2126,  2707,   833,    18,    37,
      38,    39,    40,    41,   117,   836,  1106,  2071,  1405,  2354,
    2358,  2359,  2355,  2356,  2952,  2956,  2676,  2668,  2667,  2669,
    2672,   514,   298,   612,   837,    86,    87,    20,    63,   146,
      99,   283,   101,   102,   227,   364,   103,   104,   270,   369,
     256,  1008,   540,  2853,   395,   939,  2230,   423,   424,   257,
     378,   370,   373,  1324,  1325,   150,   552,   151,   152,   383,
     258,   259,  2062,   590,   272,   275,   273,   274,   405,   568,
     569,   571,   576,   942,   276,   277,   414,   573,   223,    21,
      82,   182,   183,   184,   948,  2796,   185,   280,   268,   417,
     418,   419,   420,  2086,   838,   839,   840,   841,  1065,  3399,
    3173,  1383,  3462,  3463,  3464,  3504,  3503,  3507,   842,   843,
     844,   845,   846,   847,   848,  1057,   515,  1060,  1375,  1376,
    1415,  1144,  1416,   325,   326,   327,   328,   329,   330,   331,
     472,   516,  1308,   517,   518,   519,   520,   521,   522,   523,
     987,   213,   534,   997,   999,  1983,   214,   528,   993,   527,
     992,   530,   995,   529,   994,   957,   966,   332,   333,   216,
     334,   442,   443,   444,   445,  2110,   849,  3207,  3424,  2996,
     850,  1117,  2088,  2972,  2378,   118,   265,   562,  1916,  1240,
    1241,  1242,  1913,  1914,  2217,  2218,  2219,  2534,  2535,  1917,
    1918,  2213,  2538,  2530,  2225,  2226,  2541,  2542,  2794,  2790,
    2791,   851,  1425,    88,  2057,  2058,  2373,   428,  1098,  1149,
    1029,  1087,  1070,  1107,  2439,   217,  1030,  1024,  2024,  2671,
      90,   335,   852,   853,  1195,  1196,   854,   855,   856,   857,
    1203,  3007,  1224,  3212,  1225,  2152,  1226,  2436,  1227,  2724,
    1228,  2179,   858,  2148,  2723,  3006,  3210,  3209,  3487,   119,
      22,   859,  1399,  2063,  2064,  2169,  1862,  2170,  2171,  2734,
    2736,  2452,  2451,  2456,  2450,  2449,  2442,  2441,  2444,  2443,
    2446,  2448,   860,   861,  1104,   862,  1858,  1210,  3427,   863,
    1471,  3181,  2483,  2484,  2172,  2453,  2413,  2710,  1140,  1453,
    2092,  2381,  2093,  1449,   864,   865,  1188,  2140,  3000,   866,
     867,   868,   869,    23,    68,    24,    25,    26,   120,   121,
     870,   122,    27,   929,    28,   123,   124,   162,   564,  1922,
    2546,  3265,   125,   158,   388,   871,  2649,    29,    30,    31,
      32,    33,    62,    91,   126,   683,  1989,  2601,   872,  1183,
    2417,  2129,  2415,  3337,  2991,  2130,  2414,  2713,  2993,   873,
     874,   875,  1081,  1082,  1507,   127,   266,   563,   933,   934,
    1244,  1920,   876,  1229,  1230,   877,  1870,  1231,   336,    93,
      94,    95,    96,  1514,   188,   142,    97,  1035,   139,   219,
     220,  1515,  1516,  2424,  1517,   680,   681,  1212,   682,  1213,
    2433,  2434,  1518,  1519,  1379,  3133,  3134,  3288,  2033,  1096,
    1097,   878,  1394,  3321,   879,  2964,   880,  1409,  1410,  1411,
    2077,  2075,   881,   882,  2338,  2365,   883,  1357,  2030,   884,
    1141,  1142,   885,  1020,   886,  2494,   887,  3416,  2975,   888,
    2385,  3479,  3480,  3481,  3510,  1146,   889,  1520,  2142,  2428,
    2429,   890,  2050,  1028,  1369,   891,   892,   893,  2603,  3137,
    3299,  3300,  3386,  3387,  3391,  3389,  3392,  3452,  3454,   894,
     895,  1509,  2134,   896,  1511,  1160,  1161,  1162,  1487,   897,
     898,   899,  2103,  1479,  1155,   226,  1163,  1164,   337,  2604,
    2894,  2895,  2878,  1054,  1055,  2599,  2879,  2882,   128,   157,
     556,  1334,  2280,  2896,  3303,   454,   900,  1153,   129,   154,
     553,  1331,  2278,  2883,  3301,  2600,  1178,  2694,  3197,  3417,
    1482,   901,   902,   903,   904,   905,  1068,  2336,  1048,  2332,
     906,  2845,  1042,  1043,  2646,  2009,   907,   908,  1343,  1344,
    1345,  2021,  2317,  1346,  2314,  2018,  1347,  2289,  2010,  1348,
    1349,  1350,  1351,  2283,  2001,   909,  1077,  1059,   910,  1894,
    1895,  2194,  3034,  3228,  2764,  3031,  3432,  3433,  1896,  2201,
    2778,  1876,  2524,  3075,  3258,  2687,  2971,  2525,  1897,  1898,
    2267,  2847,  2848,  2849,  3115,  1899,  1900,  1413,   911,  1110,
     912,  1237,  1901,  1902,  3376,  2207,  2208,  2209,  2527,  2780,
    3261,  3262,  1903,  2504,  2759,  3225,  2011,  2012,  1997,  2612,
    2281,  2613,  2013,  2617,  2014,  2633,  2015,  2634,  2925,  2926,
    2284,  1904,  2188,  2189,  2501,  1905,  2842,  2590,  2838,  2262,
    1965,  2257,  2258,  2259,  2810,  1966,  2263,  2591,  2843,  2580,
    2581,  2582,  2583,  2584,  3272,  3096,  3377,  2585,  3274,  3275,
    2836,  2586,  2837,  2587,  2246,  2310,  2311,  2312,  3162,  2313,
    2913,  2918,  3309,  2614,  3263,  2903,  3067,  2616,  2575,  1286,
     338,  1287,  1950,   465,   958,  1935,  1951,  2556,    61,   913,
     914,  3026,  3221,  2752,  3220,  3493,  3518,  3519,  2756,  2495,
    1906,  2496,  2513,  3037,   615,  2491,  2492,  2268,  2593,  3219,
    3030,  1288,   972,  1289,  1290,  2839,  2588,  1292,  1293,  2248,
    3379,   915,   916,  2181,  2493,  3022,  3216,  3217,  1873,   917,
    1063,  1908,  1909,  2197,  2766,  1910,  1911,  2510,  1978,  2241,
     918,  1191,  1847,  1848,  1849,  2144,  1850,  2145,  1912,  2514,
    3073,  3257,  2775,  3070,  3071,  3072,  3069,  3057,  3058,  3059,
    3060,  3061,  3062,  3355,   919,  2080,  2368,  2369,  1036,  1294,
    1038,  2034,  1295,    66,    50,    80,    77,   921,  1166,  2107,
    1402,  1473,   922,   430,   923,  2660,   924,  2326,  1040,  2036,
     925,   926,    44,   557,   558,   559,   560,   561,   927
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -2811
static const short yypact[] =
{
    1676,   771, -2811, -2811,   317,   659,   659,   659,   659,   659,
     659,   659,   659,   317,  1033, -2811, -2811,  1033, -2811,  1546,
   -2811, -2811, -2811,   314, -2811,  1676, -2811, -2811, -2811, -2811,
   -2811,  1018, -2811, -2811, -2811, -2811, -2811,   325,   305, -2811,
     364, -2811, -2811, -2811, -2811, -2811,   317,    51, -2811,  -250,
   -2811, -2811, -2811, -2811, -2811, -2811, -2811, -2811, -2811, -2811,
    -214, -2811,  1064,   140, -2811, -2811, -2811, -2811,  1530, -2811,
   -2811, -2811, -2811, -2811, -2811, -2811, -2811, -2811,   317, -2811,
   -2811,    51,  -141,   317, -2811,   317,   345,  1546, -2811,   536,
   -2811, -2811, -2811, -2811,   915,   -70, -2811, -2811, -2811,   624,
     476,   317, -2811, -2811,   842,   317, -2811, -2811,   317,   317,
   -2811, -2811, -2811, -2811,   317,   317, -2811, -2811, -2811, -2811,
   -2811,  1530, -2811, -2811, -2811, -2811, -2811, -2811, -2811, -2811,
   -2811, -2811, -2811,  5423, -2811,   -70, -2811,   885,  1677, -2811,
   -2811,   395, -2811, -2811,   851,   140,   361, -2811, -2811, -2811,
   -2811, -2811,  9306, -2811,   317,   511,   806,   317,  1546, -2811,
   -2811, -2811,   317, -2811, -2811,   634,   545,  1023, -2811, -2811,
     551, -2811,   592, -2811,   586, -2811, -2811,   630, -2811, -2811,
   -2811, -2811, -2811, -2811, -2811, -2811, -2811, -2811,   652, -2811,
   -2811, -2811,   661,   673,   694,   697,   707,   719,   741,   750,
     761,   770,  1677,   779,  4457,   816,   831,   844,   868,   874,
     889,  1672,   950, -2811, -2811, -2811, -2811,   610, -2811,   133,
   -2811,  1677, -2811,   102, -2811, -2811, -2811,   190, -2811, -2811,
   -2811,   977, -2811, -2811, -2811, -2811, -2811,   634,   892, -2811,
    1023, -2811, -2811,   898, -2811,   927, -2811,   663, -2811, -2811,
     933, -2811, -2811, -2811, -2811, -2811, -2811, -2811, -2811, -2811,
     938,  1316,   317,   954, -2811,  1546,  1546,   970,   317, -2811,
     -18,  1360, -2811,   796,  1060, -2811,   803,  1248,  1417,  1433,
     317,  1469,  1494, -2811,   909, -2811,    35,    35,    35,    35,
      35,  4457,  1198,  1428,    35,  4457,   564,  4457, -2811,  4457,
    4457,  4457, -2811, -2811, -2811,  1022,  1101,  1139,  4457,  1295,
    1143, -2811,  4457,  4457,  1160, -2811,  1177, -2811,   831,  1180,
    1194,  1196,  1199,  1588,  8486,   106, -2811, -2811, -2811, -2811,
   -2811, -2811, -2811, -2811, -2811, -2811,  1208, -2811, -2811, -2811,
   -2811, -2811, -2811,   360,   360, -2811, -2811, -2811, -2811, -2811,
    1677, -2811, -2811,   317,  1677,  1179,   137, -2811, -2811, -2811,
   -2811,  1621, -2811, -2811, -2811, -2811, -2811, -2811, -2811, -2811,
   -2811,   -18,  1623, -2811, -2811, -2811,  1633,  1636,   140,  1469,
    1637,  1043, -2811,  1605, -2811,  1273,  1235, -2811,  1306, -2811,
   -2811, -2811,  1051, -2811, -2811,  1652,  1282, -2811,  1252, -2811,
   -2811, -2811, -2811, -2811, -2811, -2811,  1248,  1252, -2811, -2811,
   -2811, -2811, -2811, -2811,  1266,   167,   181,   288, -2811,  5071,
   -2811, -2811, -2811,  1265,  1703,   261, -2811,  1277, -2811,  -185,
     268,  1312,  1317,   276,   302,  5327,  1318,  -103,  1283, -2811,
   -2811,   130,  1322, -2811, -2811, -2811,   332,  5366, -2811,  4110,
    8517,  1523,  1523,  4457, -2811,  1241,  4457,  8486,  1290, -2811,
   -2811, -2811, -2811, -2811, -2811, -2811,  1099,  1714,  7306,  8486,
    1241,  1715,   257,  4457,  4457,  4457,  4457, -2811,  4457,  4457,
    4457,  4457,  4457,  4457,  4457,  4457,  4457,  4457,  4457,  4457,
    4457,  4457,  4457,  4457,  4457, -2811, -2811, -2811, -2811, -2811,
   -2811, -2811, -2811, -2811, -2811,  4457,  4457, -2811, -2811,  1300,
    4457, -2811,  4457,  1304, -2811, -2811, -2811, -2811, -2811, -2811,
   -2811, -2811, -2811, -2811, -2811, -2811,   360,  4457,  4457,  4457,
    4457,  1349,  1743,  1672,  4457,  1314, -2811,  1677,  1288, -2811,
    1129,  1144,  1741,  1374,  1509,   370,   377,   303,  1341,   378,
   -2811, -2811, -2811,   317, -2811, -2811,   317,  1410, -2811,  4876,
     361,  6972,  2291,  -192,   317,  1759,   -55, -2811, -2811,  1060,
    1756, -2811, -2811, -2811, -2811,  1760, -2811,  1762, -2811,  1763,
   -2811,   317, -2811,   317, -2811, -2811,  1469,  1765, -2811, -2811,
   -2811,   317,  1677,    36,    35, -2811, -2811, -2811, -2811, -2811,
   -2811,  1295,  1295,  1766, -2811,  1774,  1191,   400, -2811, -2811,
   -2811, -2811,  1411,  8486,   544,  1412,  7636,  1784,  1295,  1418,
   -2811,  1419,  1422, -2811,  7700,  7810,  7863,  7980,  4697,  8318,
    8517,  8687,  8855,  8908,  8972,  9017,  4891,  9072,  2913,  1523,
    1523,  9178,  9178,  4055,  8486,  8029,  8202,  1241,  8486,  8372,
    1241, -2811,  8486,  8486,  8486,  8486, -2811,  1794, -2811,  1816,
   -2811,  8486, -2811,   225,  1677, -2811,  1802,   -55, -2811,  1387,
    1799, -2811,  1800, -2811, -2811, -2811,  1801, -2811, -2811,  1206,
    1434,  1827, -2811,   317,  1436, -2811, -2811, -2811,   360,   360,
     360,  1006,   317,   253,   317,   317,   253,   253,  1050,   317,
   -2811,   317, -2811, -2811,   317, -2811,   895, -2811, -2811, -2811,
     253, -2811, -2811, -2811, -2811,   317, -2811, -2811, -2811, -2811,
     122,   122,  4457, -2811, -2811, -2811, -2811, -2811, -2811,   253,
   -2811, -2811,   253, -2811, -2811,   317, -2811, -2811,   253, -2811,
   -2811,   360,   253, -2811, -2811,  4457,   253,   360,   317,   360,
     253, -2811, -2811,   179,   253,   253,   179,   253,   317,   179,
     253, -2811,   253,   253,   253, -2811, -2811, -2811, -2811,   360,
     253, -2811, -2811,   253,    37,   317, -2811, -2811, -2811, -2811,
     253,  1054, -2811, -2811,   360, -2811,   253, -2811,  7217,   360,
    4457,    35,    35,   253, -2811, -2811,  1006,   360,  1067,  4457,
    4457, -2811,    53,  4457,   253,    51, -2811,  4457,   253,  1810,
     360, -2811,   253,  4457, -2811,  4457,   122,   317,   253,   317,
      35,   253,   317,    35, -2811,   317,   236, -2811, -2811, -2811,
   -2811, -2811, -2811, -2811, -2811, -2811, -2811, -2811, -2811, -2811,
   -2811, -2811, -2811, -2811, -2811, -2811, -2811, -2811, -2811, -2811,
   -2811, -2811, -2811, -2811, -2811, -2811, -2811, -2811, -2811, -2811,
   -2811, -2811, -2811, -2811, -2811, -2811, -2811, -2811, -2811, -2811,
   -2811, -2811, -2811, -2811, -2811, -2811, -2811,   239, -2811, -2811,
   -2811, -2811, -2811, -2811, -2811, -2811, -2811, -2811, -2811, -2811,
   -2811, -2811, -2811, -2811, -2811, -2811, -2811, -2811, -2811, -2811,
   -2811, -2811, -2811, -2811, -2811, -2811, -2811, -2811, -2811, -2811,
   -2811, -2811, -2811, -2811, -2811, -2811, -2811,   849, -2811, -2811,
   -2811, -2811, -2811, -2811, -2811, -2811, -2811, -2811, -2811,   596,
   -2811,   317, -2811,   854, -2811,  1440, -2811, -2811, -2811,  1531,
   -2811, -2811,  1443,  1444,  1445,  1447, -2811, -2811,  1223,  1842,
    1456,  1457,   448, -2811,  1425, -2811, -2811, -2811,  1228, -2811,
    1466, -2811,  1839, -2811,  1274, -2811, -2811,  1236, -2811, -2811,
   -2811, -2811,  9026, -2811,  1022,  1470, -2811,  1022, -2811,  1022,
    1022,  1022,  1022,  1022,  1845,  1846,  1851,  4457,  1480,  1859,
    4457,  1489,  1492,  1495,  1496,  1499,  1500,  1503,  4457,  4457,
   -2811,   307, -2811, -2811,  1581, -2811,  1504,  1506,  1263,  1507,
     317, -2811,   317,  1508, -2811, -2811, -2811, -2811, -2811, -2811,
   -2811,   425,  1471, -2811, -2811, -2811, -2811, -2811, -2811, -2811,
   -2811, -2811,  1284,  1068,  1446, -2811,  1292, -2811,  1285, -2811,
    1912,   -36,   381, -2811, -2811, -2811,  1493, -2811,  1392, -2811,
    1439,   227, -2811, -2811, -2811,  1487, -2811,  8486, -2811, -2811,
   -2811,  1138, -2811, -2811, -2811,   360, -2811, -2811,  1392, -2811,
     291, -2811, -2811,  1650, -2811,    71, -2811,  1459, -2811, -2811,
   -2811, -2811,  1921, -2811, -2811,   543, -2811,  1305, -2811,  1308,
    1921, -2811,  1331, -2811, -2811,  1518,    81, -2811,  1468, -2811,
    1276, -2811, -2811, -2811, -2811,  1293,   372,  -201, -2811,  1284,
    1604,  1333,  4457,    83,  4457, -2811,  1943,   253, -2811, -2811,
   -2811, -2811, -2811,    45,    45,    45, -2811,    45,  2179,    45,
      45,  1352,   291,  1352,  1352,  1134,  1134,  1352,  1352,   291,
   -2811,  1956, -2811,    39,  1957, -2811,   291,   107,    50, -2811,
   -2811,  4457, -2811, -2811, -2811,  1178, -2811, -2811,   361,  1579,
     361,  4457, -2811,    87, -2811, -2811,  4457,  1533,  1534,  1536,
    1537,  1421,  1538,  1067, -2811,  1627,   881,  1383, -2811,  1396,
   -2811, -2811, -2811,  1219, -2811,  1974, -2811,  1969,   317, -2811,
     223,  6332,  1406, -2811, -2811,  1982, -2811,  1327,  1982,  1987,
    1332,  1982,  1987,  4457,  1982, -2811, -2811,   227,   360, -2811,
   -2811,  1568,   326, -2811, -2811,  1561,   360,  4457,  1562, -2811,
   -2811,  1973,  1980,  1937, -2811, -2811, -2811, -2811, -2811, -2811,
   -2811, -2811,  1247,  1247,   253,   253,   253,  2368, -2811, -2811,
    1914,   596, -2811, -2811,   857, -2811, -2811, -2811,  1544, -2811,
   -2811, -2811, -2811,  5423,  1469, -2811, -2811,  1389,   317,  1398,
    1295,  1451,  1467, -2811,  5292,  5292, -2811,  1284, -2811, -2811,
    1423, -2811, -2811,  3342,  1575, -2811,  1612,  1616, -2811,  1618,
    1619,  1624,  1626,   317,    77, -2811, -2811, -2811, -2811,    90,
   -2811,   317,  2178, -2811,  1614, -2811, -2811, -2811, -2811, -2811,
   -2811, -2811, -2811, -2811, -2811, -2811, -2811,  8486,   392, -2811,
   -2811,   393, -2811, -2811, -2811, -2811, -2811, -2811, -2811, -2811,
   -2811, -2811,  1601, -2811,   398, -2811, -2811, -2811, -2811, -2811,
   -2811,  1546, -2811, -2811,  1546,   937,   178,  2040, -2811, -2811,
     409,   194,   574,  2062, -2811, -2811, -2811, -2811, -2811, -2811,
   -2811, -2811,  1474,  1068,  1285, -2811,  1050,   -98,  1212,   317,
   -2811, -2811,   317, -2811,  1472,  1450,  1476,  1635, -2811,  1640,
     150, -2811, -2811, -2811, -2811, -2811,  2072, -2811, -2811,  1452,
    1647, -2811, -2811, -2811,  1050,  1261, -2811,  1261,  1067,   179,
    4457,  4457,  4457,  1649, -2811, -2811,   360,   360, -2811,  1458,
    1067,    35,  1420,    37,   360, -2811,  1461,  4457,  1736, -2811,
   -2811,  1535, -2811, -2811,   317,  2089, -2811, -2811,   126,   227,
   -2811, -2811,  2077,  2078, -2811, -2811, -2811, -2811, -2811, -2811,
   -2811, -2811, -2811, -2811, -2811, -2811, -2811, -2811, -2811, -2811,
   -2811, -2811, -2811, -2811, -2811, -2811, -2811, -2811, -2811, -2811,
   -2811, -2811,  3237, -2811, -2811, -2811, -2811, -2811, -2811, -2811,
   -2811, -2811,  7217, -2811,  1134,  4457,   -39,  2073,  2075, -2811,
   -2811, -2811, -2811, -2811,   180, -2811, -2811, -2811, -2811,  1945,
   -2811,  1880, -2811, -2811, -2811,  4457,   122, -2811, -2811,   317,
    2079,    35,    35, -2811,  1514, -2811,    35,  1485,   360, -2811,
     317,   317,  4457,   -26, -2811,  1524, -2811,   254, -2811,  1628,
   -2811,  1629,  4457,   948, -2811, -2811,  1486, -2811,  2112, -2811,
    1567, -2811,   360, -2811, -2811, -2811, -2811, -2811, -2811, -2811,
   -2811, -2811, -2811, -2811, -2811, -2811, -2811, -2811, -2811, -2811,
   -2811, -2811, -2811, -2811, -2811, -2811, -2811, -2811, -2811, -2811,
   -2811, -2811, -2811, -2811, -2811, -2811, -2811, -2811, -2811, -2811,
   -2811, -2811, -2811, -2811, -2811, -2811, -2811, -2811, -2811, -2811,
   -2811, -2811, -2811, -2811, -2811, -2811, -2811, -2811, -2811, -2811,
   -2811, -2811, -2811, -2811, -2811, -2811, -2811, -2811, -2811, -2811,
   -2811, -2811, -2811, -2811, -2811, -2811, -2811, -2811, -2811, -2811,
   -2811, -2811, -2811, -2811, -2811, -2811, -2811, -2811, -2811, -2811,
   -2811, -2811, -2811, -2811, -2811, -2811, -2811, -2811, -2811, -2811,
   -2811, -2811, -2811, -2811, -2811, -2811, -2811, -2811, -2811, -2811,
   -2811, -2811, -2811, -2811, -2811, -2811, -2811, -2811, -2811, -2811,
   -2811, -2811, -2811, -2811, -2811, -2811, -2811, -2811, -2811, -2811,
   -2811, -2811, -2811, -2811, -2811, -2811, -2811, -2811, -2811, -2811,
   -2811, -2811, -2811, -2811, -2811, -2811, -2811, -2811, -2811, -2811,
   -2811, -2811, -2811, -2811, -2811, -2811, -2811, -2811, -2811, -2811,
   -2811, -2811, -2811, -2811, -2811, -2811, -2811, -2811, -2811, -2811,
   -2811, -2811, -2811, -2811, -2811, -2811, -2811, -2811, -2811, -2811,
   -2811, -2811, -2811, -2811, -2811, -2811, -2811, -2811, -2811, -2811,
   -2811, -2811, -2811, -2811, -2811, -2811, -2811, -2811, -2811, -2811,
   -2811, -2811, -2811, -2811, -2811, -2811, -2811, -2811, -2811, -2811,
   -2811, -2811, -2811, -2811, -2811, -2811, -2811, -2811, -2811, -2811,
   -2811, -2811, -2811, -2811, -2811, -2811, -2811, -2811, -2811, -2811,
   -2811, -2811, -2811, -2811, -2811, -2811, -2811, -2811, -2811, -2811,
   -2811, -2811, -2811, -2811, -2811, -2811, -2811, -2811, -2811, -2811,
   -2811, -2811, -2811, -2811, -2811, -2811, -2811, -2811, -2811, -2811,
   -2811, -2811, -2811, -2811, -2811, -2811, -2811, -2811, -2811, -2811,
   -2811, -2811, -2811, -2811, -2811, -2811, -2811, -2811, -2811, -2811,
   -2811, -2811, -2811, -2811, -2811, -2811, -2811, -2811, -2811, -2811,
   -2811, -2811, -2811, -2811, -2811, -2811, -2811, -2811, -2811, -2811,
   -2811, -2811, -2811, -2811, -2811, -2811, -2811, -2811, -2811, -2811,
   -2811, -2811, -2811, -2811, -2811, -2811, -2811, -2811, -2811, -2811,
   -2811, -2811, -2811, -2811, -2811, -2811, -2811,  5663, -2811, -2811,
   -2811, -2811,   317,    35,    35,   260,   326,  1965,  1046,   360,
     227, -2811,  1570, -2811, -2811,  2089,  2096,  1718, -2811, -2811,
   -2811, -2811, -2811,  1798,  1798, -2811,   189,  1574, -2811,   317,
   -2811, -2811,  1392,  1392, -2811, -2811, -2811,   317, -2811,   317,
     544,  1392, -2811,   508, -2811, -2811, -2811, -2811, -2811, -2811,
   -2811, -2811, -2811, -2811, -2811, -2811, -2811, -2811, -2811, -2811,
   -2811, -2811, -2811,   228,   228,   467,   833, -2811,   787, -2811,
     857, -2811,  1546,  2101, -2811, -2811,  1237,  1732,  1694, -2811,
   -2811, -2811, -2811, -2811, -2811, -2811, -2811,  1491, -2811, -2811,
   -2811,  2265,  2265, -2811, -2811, -2811, -2811, -2811, -2811, -2811,
   -2811,  1501,   544,  1739,   311,   637,  9026,   637,   637,   637,
     637,  1515,  9026,  9026,   156,  1602,   598, -2811,  9026,  9026,
    9026,  9026, -2811, -2811, -2811, -2811, -2811, -2811, -2811,  1050,
    4457, -2811, -2811,  1745,  2101, -2811, -2811, -2811, -2811,  1546,
   -2811, -2811,  1392, -2811,   679, -2811,  1708, -2811, -2811,   679,
   -2811, -2811, -2811,  1709,  1711,   279,  1713,  1717,   834, -2811,
   -2811, -2811, -2811, -2811, -2811, -2811,   317, -2811, -2811,   279,
    1490, -2811,   425, -2811,  1754,   -70,  1539, -2811,  1067,  1573,
   -2811, -2811,  1696, -2811, -2811, -2811,  1610, -2811,   317,   317,
     317, -2811, -2811, -2811,  1138,   317, -2811,  1543, -2811, -2811,
   -2811, -2811,  1545, -2811,  2160,  2161, -2811,  2163,  1589,  4457,
   -2811, -2811,  1550,  2174, -2811,  1693,  1555,  1987, -2811, -2811,
    1559,   935,   317, -2811, -2811,  1750,   253,   785, -2811,  4457,
   -2811, -2811,   317,   317,  4457,    34,   291,  2186,  2185,  2175,
    2177,  2179, -2811, -2811, -2811, -2811, -2811,   360,  1876, -2811,
   -2811,  2145,  4457,   361,  1010, -2811, -2811,  1891,  2218,  2220,
     399, -2811,   406,   317,  1830,  1067, -2811,  4457,  1792,  1793,
   -2811, -2811,  1865, -2811,  4457,   249, -2811,  1630, -2811, -2811,
     552, -2811,  4457, -2811, -2811,  1603,   885, -2811,  1286,   317,
    2222,  8227, -2811, -2811,  1050,   360, -2811, -2811,    74, -2811,
    1987,  1987,  1576, -2811,  1682,  1681, -2811, -2811, -2811, -2811,
      35,    35, -2811, -2811, -2811, -2811, -2811, -2811, -2811, -2811,
    1254, -2811, -2811, -2811, -2811,    35,  4092,  2233,  2213, -2811,
    1067,   940,   193,   148,  2136,    13,  1006, -2811,   323, -2811,
   -2811, -2811,  1807,    75,  1392,   144, -2811,  1620,  1625, -2811,
   -2811,   427, -2811, -2811, -2811, -2811,  1814,  1622,  2248, -2811,
   -2811, -2811,   360,    98, -2811, -2811, -2811,  1611,   833, -2811,
     317,   317, -2811, -2811,   317,   354, -2811, -2811, -2811, -2811,
    1826, -2811, -2811, -2811,  2235, -2811, -2811,  1557,  9026, -2811,
     266,  1862,  2260, -2811, -2811, -2811,  9026, -2811,   407,  9026,
    9026,  9026,  9026,   317,   411, -2811,   197,  2261, -2811, -2811,
     317,  3129, -2811,  1894,   317,  1646,   637,  1934, -2811, -2811,
   -2811, -2811, -2811, -2811,  8486, -2811,  1841, -2811,  1805, -2811,
    1808, -2811,  1853,   414, -2811,  3129,   420,    88,    88,   423,
   -2811,    88,  3129, -2811, -2811,  1854,  1423,  1423, -2811,  1855,
   -2811,  1856,  1858, -2811,  1861,  1863, -2811, -2811, -2811, -2811,
     169, -2811, -2811, -2811,   429, -2811, -2811,   433,   317, -2811,
   -2811,  1212,  2274,  1067,  1677,  4457, -2811,  2290, -2811, -2811,
   -2811, -2811,   279, -2811, -2811,  1674,   279,   183, -2811,  1067,
    4457,  4457,  4457,  3427,  2295,    82, -2811, -2811,  1067,   317,
   -2811, -2811,   317,   317, -2811,   943, -2811, -2811,   506, -2811,
    1678,  4457, -2811, -2811, -2811,  2293, -2811,  1679,  2299, -2811,
   -2811, -2811, -2811, -2811,   317,  1987, -2811, -2811,  1747, -2811,
   -2811,   456, -2811, -2811, -2811,   360, -2811,  5177, -2811, -2811,
   -2811,  1977,  2283, -2811,    35,  1961,  1962,  1848,  1689,  1966,
    1882, -2811, -2811, -2811,   524,  1951, -2811, -2811, -2811, -2811,
    1865, -2811, -2811, -2811,   247,   588, -2811, -2811, -2811,  2089,
    4457,  1892, -2811,  1860, -2811, -2811, -2811, -2811,  2320, -2811,
   -2811, -2811,  1900,  2322, -2811, -2811,  1675, -2811,  2303,   291,
     317,  1483,  1483,  1483,  1483, -2811,  2326, -2811,  2329,  1483,
    1483,  1483,  1483,  3237, -2811, -2811,  1483,   112, -2811, -2811,
   -2811, -2811,  2311,  2323, -2811, -2811, -2811, -2811, -2811, -2811,
   -2811, -2811, -2811,  2324, -2811, -2811, -2811, -2811, -2811, -2811,
   -2811,   457, -2811, -2811, -2811,  2314, -2811, -2811,  1392, -2811,
     544, -2811, -2811, -2811, -2811, -2811, -2811,  1746,  1755,   243,
   -2811,   323, -2811,    88,  1726,   253, -2811,  1918, -2811, -2811,
   -2811,   317,   317,  9026,   394, -2811,  4457, -2811,  4457, -2811,
   -2811, -2811, -2811, -2811, -2811,   253,    88, -2811,  1392,   906,
    2345, -2811,   360,   317,   926,   926, -2811, -2811,  2353, -2811,
    2353,   622,   622,  2353, -2811, -2811,  2291, -2811,  1963,  1923,
   -2811, -2811, -2811, -2811, -2811, -2811, -2811,    90,  1423,  1748,
   -2811,  1423,  1983,  9026, -2811,  1986,  1988,  1989,  1991, -2811,
   -2811,   156, -2811,   156, -2811, -2811,  3745,  1941,  2373,  1941,
    2378,  2372, -2811, -2811, -2811, -2811, -2811, -2811,   287,  9026,
   -2811,  1936, -2811,  2121,   163,   193,   317, -2811,  6955,   103,
   -2811,  2291,  2003, -2811,   103,    88,   679, -2811,   171, -2811,
    1392,  -142,  1998,  2396,  1780, -2811, -2811,   479, -2811,   279,
   -2811,   484,   241,  2383,  1781,   -90,  2386,  2386,  2387,  2386,
    2386, -2811,   231, -2811,   679,   317, -2811,   279, -2811, -2811,
    1796,  1067,  2415,   308, -2811,   317,   487, -2811,  4457,  2030,
    2408,   494,  1067,  2432, -2811, -2811, -2811, -2811,  4457,  1867,
    2162,  4457, -2811, -2811, -2811, -2811,   506,  1087,  1087,  2434,
    -153, -2811,  2435, -2811, -2811, -2811,  1087,   317,  1895,  1303,
    2440,   317,   141, -2811,   -97,  4457, -2811, -2811,  2179, -2811,
    1775,  4457, -2811,  2443,  4457, -2811,   360, -2811,   895,   317,
     360, -2811,  2052,  4457,  4457, -2811, -2811,   524,  1951, -2811,
    3237, -2811, -2811,  1272, -2811, -2811,  1874, -2811,  1677,  3906,
    8227,   360,   360,    68,   850, -2811, -2811, -2811,  1831, -2811,
   -2811, -2811, -2811,    35,  1483,    35,  1483, -2811, -2811, -2811,
   -2811, -2811, -2811,   291, -2811,  1125,  1250,  4092, -2811,  2059,
    2022,  9026, -2811,   148,   148, -2811, -2811, -2811, -2811,   504,
   -2811,  1984, -2811,    88,   521, -2811,  1829, -2811,  2457,  2895,
    2895,  2895,  2895,    88,    88, -2811, -2811, -2811,  1905, -2811,
     507, -2811,  1834, -2811,   360, -2811,  2353, -2811, -2811,   317,
     622,   622, -2811, -2811,   622,  2250,  1838, -2811,  2442,  2074,
    1843,  1557,  1844, -2811, -2811, -2811, -2811, -2811, -2811, -2811,
     512, -2811, -2811,  1994, -2811,   269,   222, -2811,  3129,  3129,
   -2811, -2811, -2811, -2811, -2811, -2811, -2811, -2811, -2811,  5292,
    5292,  2036,  5292,  2041, -2811,  5292,   828,  9026,  2474, -2811,
   -2811,  3129, -2811, -2811, -2811, -2811, -2811,  2475, -2811,   352,
   -2811, -2811,  2121,  1864, -2811, -2811,   122,   122,   122,  2458,
     122,   122,   122,   122,   122,   122,  2461, -2811,  2462,   122,
   -2811, -2811, -2811, -2811, -2811, -2811, -2811, -2811,  6955, -2811,
     360,  1866, -2811,  2046,  2250,  2476, -2811,  2477,  2478,  2479,
    2480,  2484,  2485,  1289,  2003, -2811,  2046, -2811,   514, -2811,
   -2811, -2811,  2486, -2811,  2202,    88,  1320,    88, -2811, -2811,
   -2811, -2811, -2811,  2123,  1557,  2497,  1557, -2811,  2520,  2520,
     516,  2129,  2520, -2811, -2811, -2811,   679, -2811, -2811, -2811,
   -2811,  1067, -2811, -2811,   279,  2121,  2089, -2811,  2054, -2811,
     273,  1067, -2811,  2531,  2102, -2811, -2811,  2140,  1990, -2811,
   -2811,   317,  1087,  1677,  1339,   317,  1087, -2811, -2811,    35,
   -2811, -2811,  4457, -2811, -2811, -2811, -2811, -2811, -2811,    35,
    2089,   360,  2294, -2811,  2515,  1682,  8486,  2518, -2811, -2811,
     227,  2110, -2811, -2811,  4457, -2811, -2811,  2149, -2811, -2811,
   -2811,   588, -2811,  1682, -2811,  4457, -2811,   310, -2811,  1957,
   -2811, -2811, -2811, -2811, -2811, -2811,  2103,  2198, -2811,  2528,
   -2811, -2811, -2811, -2811, -2811, -2811, -2811, -2811, -2811, -2811,
   -2811,   317, -2811,    95, -2811, -2811, -2811,    88, -2811,   544,
    2406,   519, -2811, -2811, -2811, -2811,   317,  1993,  9285,  9285,
   -2811, -2811,  9165,  2116, -2811, -2811,  2118,  2119, -2811,  2120,
    2122,  2124,  2126,   317,   604, -2811, -2811,   520, -2811, -2811,
    2433, -2811, -2811, -2811,   523,  2552,  2552, -2811, -2811,   528,
    2558,  2550, -2811,   105, -2811, -2811,    88, -2811,   142, -2811,
   -2811, -2811, -2811, -2811,  2351,  5423,  2180, -2811,  1557, -2811,
    1557,   156, -2811, -2811,  2372, -2811,  2128,  2178,  2128,   201,
   -2811,  2128,   201, -2811,  2128,  5292, -2811, -2811,  9026, -2811,
    9026,  2378,   163, -2811, -2811, -2811, -2811, -2811, -2811, -2811,
   -2811, -2811, -2811, -2811, -2811, -2811, -2811, -2811, -2811, -2811,
   -2811, -2811,   426,  2566, -2811,   360,  1840, -2811,  2351, -2811,
   -2811, -2811, -2811, -2811, -2811, -2811, -2811, -2811, -2811, -2811,
   -2811,   315, -2811, -2811, -2811,  2114, -2811, -2811, -2811,  2183,
   -2811,  2560,  2187,  2190,  2562, -2811, -2811,  2192, -2811, -2811,
   -2811, -2811,    35,   291,  2197,  1067, -2811,  4457, -2811,  2020,
    2569,   291, -2811, -2811,   454, -2811, -2811, -2811, -2811,   115,
    2200,  1987,  2322,  2354, -2811,   291,  2203,  2206,  2186,  2168,
   -2811,  2256,  2210, -2811, -2811, -2811, -2811,  2363,  2147,  4457,
    2166, -2811, -2811, -2811,  1682, -2811,   529, -2811,   360,  2063,
   -2811, -2811, -2811,  9026, -2811, -2811,    88, -2811,  2181, -2811,
    2063,  2332,  2332,  2216,   311,   637,  9187,   637,   637,   637,
     637,  1992,  9187,  2895, -2811,  9187,  9187,  9187,  9187, -2811,
   -2811,    88,  2604,    88,  2895,   253,  3129, -2811,   360, -2811,
   -2811,   390, -2811, -2811, -2811, -2811, -2811, -2811, -2811, -2811,
   -2811,   231, -2811, -2811,   532, -2811, -2811, -2811, -2811,   533,
   -2811,  2128,  2612, -2811, -2811, -2811, -2811, -2811, -2811,   360,
    2566, -2811, -2811, -2811,   360, -2811,   360, -2811, -2811,  1526,
   -2811,  2380, -2811,  2381,  2596, -2811, -2811,  1997, -2811, -2811,
   -2811, -2811,  2231, -2811, -2811, -2811,  1067, -2811,  2232,  9545,
    2193, -2811, -2811, -2811,  2008,   291, -2811, -2811, -2811, -2811,
   -2811, -2811,  2238,   227, -2811,  2256,  2256,   588, -2811,  1677,
    2058, -2811, -2811,   317, -2811,  2322,   598,    90, -2811,  8956,
     598, -2811,  2242,  9187, -2811,   534,  9187,  9187,  9187,  9187,
     317,   540, -2811, -2811, -2811, -2811, -2811, -2811,  2204, -2811,
   -2811, -2811,  2378,  2322,   142, -2811, -2811, -2811, -2811, -2811,
     219, -2811, -2811, -2811,  9026, -2811,  1516,  1516, -2811,  1516,
   -2811,  1516,  1516, -2811, -2811, -2811,  2211,  1557, -2811,   798,
   -2811, -2811,    45,    45,    45,    45,    45,    45, -2811,  2617,
   -2811,   541, -2811,  4457,  1344, -2811,    21,  2256,  4457,  2256,
    2186, -2811, -2811, -2811,  2398,   336, -2811,   291, -2811, -2811,
   -2811, -2811,   542, -2811, -2811,  1256, -2811,  2249,  9187, -2811,
    2253,  2254,  2255,  2259, -2811, -2811,  2895, -2811, -2811, -2811,
   -2811, -2811,  1516, -2811,  1516, -2811, -2811, -2811, -2811, -2811,
   -2811, -2811, -2811,   966, -2811, -2811, -2811, -2811, -2811, -2811,
   -2811, -2811, -2811,  9545, -2811,  2640, -2811, -2811, -2811, -2811,
     670, -2811, -2811, -2811, -2811, -2811, -2811,    74, -2811,  8956,
   -2811,  1513, -2811, -2811, -2811, -2811, -2811, -2811, -2811, -2811,
     548, -2811, -2811,  1039,  1039, -2811, -2811,  1039, -2811,  4457,
     709, -2811, -2811,  2262,    68, -2811,  2023,  2029,  2652, -2811,
   -2811, -2811, -2811, -2811,  2263, -2811, -2811, -2811,   317,   317,
    1513, -2811,   128,  2034, -2811, -2811, -2811,   227, -2811,   317,
    2186, -2811
};

/* YYPGOTO[NTERM-NUM].  */
static const short yypgoto[] =
{
   -2811, -2811, -2811, -2811, -2811,   -37, -2811,    17,  -198, -2811,
   -2811, -1131,   -10, -2811, -2811, -2107, -2811, -2811, -2811, -2811,
    -810, -2811, -2811, -2811, -2811, -2811, -2811, -2811, -2811, -2811,
   -2811, -2811, -2811, -2811, -2811, -2811, -1968, -2811,  -993, -2811,
    1666, -2811, -2811, -2811, -2811, -2811, -2811, -2811,   256, -2811,
   -2811, -2811, -2811,  1164, -2811,   546, -2811, -2811,   -61, -2811,
   -2811,  2636, -2811,  2639,  2115, -2811, -2811, -2811, -2811, -2811,
     331,     9, -2811,   333, -2811, -2811, -2811, -2811, -2811, -2811,
   -2811, -2811, -2811, -2811, -2811,  -144,   453,   306, -2811, -2811,
    2312,    62, -2811,  2548, -2811, -2811,  2551, -2811,  2460, -2811,
   -2811, -2811, -2811, -2811,  2328,  2035,   721,  2327,  -532, -2811,
   -2811, -2811, -2811, -2811,   722,  -660, -2811, -2811, -2811, -2811,
   -2811, -2811,  -168,  2164,  2470,     0,  2104, -2811,  2143,  1462,
   -2811,  2306, -2811, -2811, -2811, -2811,  2315, -2811, -2811, -2811,
   -2811,  -417, -2811, -2811, -2811, -2811, -2811, -2811, -2811, -2811,
    2139, -2811,  2144, -2811, -2811, -2811, -2811, -2811, -2811, -2811,
   -2811, -1325, -2811, -2811,  -741, -2811, -2811, -2811, -2811, -2811,
   -2811, -2811, -2811, -2811, -2811,  -121, -2811, -2811,   682, -2811,
   -1080, -1135,  -656, -2811, -2811, -2811, -2811, -2811, -2811, -2811,
   -2811, -2811,  1738, -2811, -2811, -2811, -2811, -2811, -2811, -2811,
    -612, -2811, -2811, -2811, -2811, -2811,  1928, -2811, -2811, -2811,
   -2811, -2811, -2811, -2811, -2811,  -545, -2811,  -137, -2811, -2811,
   -2811, -2811,  2297, -2811, -2811, -2811, -2811, -2811, -2811, -2811,
   -2811, -2811, -2811, -2811, -2811, -2811, -2811, -2811, -2811, -2811,
   -2811,  1502, -2811, -2811, -2811, -2811,   515, -2811, -2811, -2811,
   -2811, -2811, -1873, -2811, -2811,   525, -2811, -2811, -2811, -2811,
   -2811, -2811, -1031,  -678,   402,   648, -2811,  -266,   481, -1100,
     792, -2811,   693, -2811, -2375,    -4,   292, -2811, -2811, -2277,
     176,  1217, -2811, -2811,   691,   884, -2811, -2811, -2811, -2811,
   -2811, -2811,    16, -2811,  -270, -2811,   890, -2811,   594, -2811,
     312, -2811, -2811, -2811, -2811,  -765, -2811, -2811, -2811, -2811,
   -2811, -2811, -2811, -2811,   405, -2811, -1808, -2811,   582, -2811,
   -2811, -2811, -2811, -2811, -2811, -2811, -2811, -2811, -2811, -2811,
   -2811, -2811, -2811, -2811,  1350, -2811, -2811, -2811, -2811, -2811,
   -2811,  -435, -2811, -2811, -2039, -2811, -2811, -2811, -2811,   470,
   -2220, -2811, -1103, -2811, -2811, -2811, -2811, -2811, -2811, -2811,
   -2811, -2811, -2811, -2811, -2811, -2811, -2811,  2731, -2811, -2811,
   -2811,  2637,  2729, -1704, -2811, -2811, -2811, -2811, -2811, -2811,
   -2811,  -377, -2811, -2811, -2811, -2811, -2811, -2811, -2811, -2811,
    2732, -2811, -2811, -2811, -2811, -2811, -2811, -2811, -2811, -2811,
   -2811,   632, -2811, -2811, -2811, -2811, -2811, -2811, -2811, -2811,
   -2811, -2811,  -697,  2005, -2811, -2811, -2811, -2811, -2811,  1849,
   -2811, -2811, -2811, -2811, -2811, -2811, -2811, -2811,  2517, -2811,
   -2811,   -77, -2811, -2811,   635, -2811, -2811, -2811, -1016,  -218,
    2418, -2811, -2811, -2811, -2811,   495, -2811, -1040,  1761,   916,
   -2205,    55, -2811,   636,  1571,  -354,  -506, -2811, -2811,  2000,
    1390, -2811, -2811, -2811, -2811, -2811, -2811, -2811, -2811, -2811,
   -2811, -2811, -2811, -2811, -2811, -2811, -2811, -2811, -2811, -2811,
   -2811,  1324, -2811,  -759, -2811,  -662, -2811, -2811, -2811, -2811,
   -2811, -2811, -2811,  -692, -2811, -2811, -2811, -2811, -2811, -2811,
      70, -2811,  1405,   297, -2811, -2811, -2811, -2811, -2811,  -102,
   -2811,  -504, -2811, -2811, -2811, -2811, -2811, -2811, -2811, -2811,
   -2811, -2811, -2811, -2811, -2811, -2811, -2811,  1632, -2811, -2811,
   -2811, -2811, -2811, -2811, -2811,  -533, -2811,  1311,  2330, -2811,
   -2811,   -96, -2811,  -651, -2811, -2811,   -79,   196, -2811, -2811,
   -2811, -2811, -2811, -2811, -2811,  1040, -2811, -2811, -2811, -2811,
   -2811, -2811, -2811, -2811, -2811, -2811, -2811, -2811, -2811, -2811,
   -2811, -2811, -2811, -2811, -2811, -2811, -2811, -2811, -2811, -2811,
   -2811, -2525, -2811,  1441,   465, -1306, -2811, -2811, -2811,   782,
   -2811, -1944, -2811, -2811, -2811, -1925, -2811, -2811, -1938, -2811,
   -2811, -2811, -2811,   808, -2811, -2811, -2811, -2811, -2811, -2811,
     309, -2811, -2811, -2811, -2811, -2811, -2811,  -684, -2811, -2811,
   -2811, -2811, -2811, -2811, -2811, -2811, -2811, -2811, -2811, -2811,
   -2811, -2811,  -301, -2811, -2811, -2811, -2811, -2811, -2811, -2811,
   -2811, -2811, -2811, -2811, -2811, -2811, -2811,   283, -2811, -2811,
   -2811,  -561, -2811, -2811, -2811, -2811, -2811, -2811,   -86, -2811,
   -2811,   214, -2811,   538, -2811, -2811, -2811, -2811, -2811, -2811,
   -1315, -2811, -2811, -2811, -2811, -1965, -2811, -2811, -2811, -2811,
   -2811, -2811, -2371,   567, -2811, -2516,   627, -2811, -2811, -2245,
       6,     8,   258, -2811, -2109, -1857, -2811, -2811,  -272,  -548,
   -2811, -2811, -2811, -2811, -1762, -2811, -2811, -2811, -1899, -2811,
   -2811, -1329, -2811,  -929,   956,  -319, -2000,   229, -2811,   348,
   -2811, -2811, -2811, -2811,   -60, -2811, -1280, -2647,  2821, -2811,
   -2811, -2811, -2811, -2811, -2811, -2811, -2811,  -690, -2811, -1612,
   -2811,  1606, -2811, -2811,   327,   246, -2811, -2307,   250,  -195,
      84,  -355, -1844, -2208,   882,  -263,  -788, -1241, -2811,   888,
   -2811, -2811, -2811,   978,  -772, -2811, -2811,  -489,  1631, -2811,
     883, -2811, -2811, -1816,  -181, -2811, -2811, -2811, -2768,  -378,
   -2811, -2811, -2811,  1011, -2811, -2811, -2811, -2811, -2811, -2811,
   -2811, -2811, -2811, -2811, -2628,  -396, -2811, -2719, -2810,  -840,
   -1481, -2811, -2811,  -383, -2811, -2811, -2811,   182,  -713,  -667,
    -744,   547, -1300,    19,  2019,   -46, -2811, -2811, -2811, -2811,
   -2811,  1464, -2811,  -261, -2811, -2811, -2811, -2811, -2811, -2811,
   -2811, -2811,   186,  1437,  2310, -2811, -2811, -2811, -2811
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -2159
static const short yytable[] =
{
      43,   215,   584,   356,   296,  1002,  1320,   116,   135,    58,
      60,  1370,   284,    60,   264,  1466,  1474,  1420,  1355,    34,
    1998,   431,   432,  1941,  1942,  1448,  1158,   687,   433,   434,
    2557,  1037,  2357,   446,  1418,   132,  2020,  1152,   990,  2712,
    2608,  2799,    76,    79,    34,  2043,  2199,  2622,  2154,  2155,
      72,  3064,  3065,  3066,   949,   594,   953,   959,    89,  1086,
     116,    42,    42,    42,    42,   215,  1058,  2290,  1111,  2482,
    1056,  1421,    42,  2198,   131,  2316,  2673,    79,    42,   134,
      42,    89,  2743,   324,   215,   381,  1397,   130,  1397,  1072,
     141,  2315,  1485,  1427,  1428,  1963,  1429,   148,  1450,  1451,
    1963,   153,  2662,  2532,   155,   156,  1051,  1365,  2238,    42,
     159,   160,   594,  1365,  1037,    42,  1061,   594,  2498,  1367,
     594,   389,   390,  1855,  1116,   100,   302,   357,   358,    42,
     302,  2079,   524,    89,  1145,  3004,  1878,  1865,   354,  1380,
     130, -2157,   354,  1159,  1165,  3068,   302,  1180,  1052,   605,
     260,  1184,   533,   263,  3089,  1860,   606,  1190,   267,  1192,
     144,  2965,  1167,  1385,  1386,  1193,  1365,  1856,    42,    42,
     435,  1112,   577,  1114,   447,    42,   449,  2818,   450,   451,
     452,  1365,  1151,    42,  1291,  1465,   579,   457,  1365,  2846,
      42,   468,   469,  1467,  1468,  2249,  2250,  2251,  2252,  2081,
    2809,  2082,  2811,  2083,  1079,    42,    42,   100,  1156,   361,
      42,   228,  1168,   215,   302,   362,   363,   215,  1156,   359,
      42,    42,  1365,  2502,    42,   302,  1267,  1268,    42,  2505,
     354,  2820,  2821,  2741,  2822,  2823,  2824,  2825,  2826,  2827,
      85,   375,  2880,   302,  1267,  1268,    42,  2818,    85,   466,
    1169,   302,  1205,  1206,    42,   302,  2923,  1268,   386,  3255,
     302,  1205,  1206,    42,   392,  2079,   587,  3158,  1355,  3160,
      42,  2558,  2711,   594,    42,  2818,   421,  2127,  3174,   592,
      42,   594,   429,   429,   429,   429,   429,  2615,  2618,  1354,
     429,  2618,  3249,   581,   602,  3536,  2820,  2821,  2968,  2822,
    2823,  2824,  2825,  2826,  2827,  2768,    42,   594,   145,  1214,
    2097,  2953,   354,   354,    67,   354,  2357,   382,  2121,   663,
    3304,  2163,  2902,  2508, -2157,    65,   305,  3116,   956,  2183,
    2184,  1860,   613,  2815,    36,   616,  1032,   594,    42,    89,
      89,   354,   937,  2101,    42,  2663,  2915,  1170,  2540,   535,
    1407,  2543,   624,   625,   626,   627,    73,   628,   629,   630,
     631,   632,   633,   634,   635,   636,   637,   638,   639,   640,
     641,   642,   643,   644,    85,   670,   938,  1463,    85,  2087,
      81,  2631,   672,   676,   645,   646,  1362,    42,    85,   648,
    1521,   649,    35,    65,   952,  3374,  1033,  1980,  1980,    42,
     215,  1497,    83,  1985,  2394,  1377,   652,   653,   654,   655,
    3171,   594,  2563,   661,  1033,   198,  2563,  1101,   393,  2606,
    2509,  1408,    85,  1171,   963,  2606,   964,   199,  2619,  1215,
    1464,    85,   541,  3362,  2635,   544,    42,   931,  2637,   593,
     100,  3268,    85,  3269,  3370,   394,  1001,  2769,  2770,  2771,
    2772,  2773,  2040,    19,    42,   215,  2168,  1457,  1458,  1215,
     932,  2688,  2747,  3249,  3249,  1172,   345,   346,   347,   348,
     349,  2954,   345,   346,   347,   348,   349,  3537,    19,  2828,
     133,  1861, -1536,  2028,  2907,  1953,  1335,  1336,   589,  2907,
    2990,   603,  2934,  2128,    42,  1145,  1884,  2137,    98,  2934,
     834,   928,  1022,  2760,  2595,  1159,  1033,  1360,  1103,  3027,
    1488,  2677,  3076,  1962,  1337,  1338,  1339,  3091,  1215,  2905,
   -2157,  3164,    89,  2029,  3226,  3243,  2781,   215,  3243,  2003,
    1147,  1148,  1173,  3251,  3343,  3375,  2758,  3380,  3380,  3438,
    2916,   138,  2004,  3023,  2828,  3438,  3473,  3489,  2374,   679,
    2678,  1422,   679,  3243,   143,    85,  1361,  1502,   976,  1199,
     679,  2098,  1202,  1882,   578,   355,  2969,    85,  2900,   538,
    1215,   205,  1522,  1877,  2632,  2127,   582,   421,   580,   421,
     920,   930,   345,   346,   347,   348,   349,   951,  1216,   955,
     429,   674,   136,  2409,  2850,   206,  3111,  1022,  2829,  2830,
    3195,    42,  1270,  1102,  1423,  2615,  2261,  1022,   965,  2026,
    3260, -2157,   589,  2499,  1999,  3005,  2052,  1271,  3205,  2239,
    1270, -2157,  2881,  3367,  1890,  1480,  1207,  1483,  2066,   145,
    2016,  2185,  1270,  2571,  1217,  1271,  3256,  1943,  2911,   207,
    3019,  1964,  1398,  2027,  1417,    78,  2751,  1271,   208,  2533,
     307,  1469,  3175,  3218,  2242,  1217,  2831,  1000,   588,  2003,
    2786,  1861,    85,  2829,  2830,   595,  3093,  2438,  1987,  2490,
    3180,  2047,  2004,   598,  3182,   310,  2256,  1952,  3187,   679,
    2202,  2909,  2966,  2544,    89,    89,    89,    89,  1021,  1037,
    1026,  1027,  2053,  2929,  1034,  1039,  2767,  1041,  2610,   599,
    1044,  1387,    89,  3346,  2610,   427,   427,   954,   427,  1486,
    2928,  1027,  2240,  2020,  3350,  1936,  1472,  1037,  1424,  1890,
    3270,  2831,  1925,  1218,   607,  1944,   323,  3500,  1208,   609,
     323,  1027,   209,   210,  2054,  2055,  2056,    89,  1470,  1321,
    2932,  1945,  3208,    89,  1027,    89,   323,  3305,  2084,    89,
    3458,  2073,    89,  1218,  1089,    89,  2085,  2610,   316,  1182,
    2006,  2376,  1404,  3032,  2652,    89,  3192,   671,  3486,  1080,
     429,  1105,  1523,  2515,   673,   677,  2007,  1034,  1363,  2610,
      89,  1022,  2516,  2832,  1946,    89,  2095,   429,   429,  1981,
    1982,  2128,    89,    89,    89,  1986,  2395,   621,  1176,    35,
      36,    79,  2438,  2396,  2564,  1524,    89,  2517,  2570,  2096,
    2518,  2607,  1218,  1194,   323,  1194,   429,  2609,  1194,   429,
    2620,  1194,    89,  1947,  2003,   323,  2636, -2157,  2519,  1159,
    2638,  3430,  2124,  1893,   147,  2106,  1924,  2004,  3105,  3342,
    2220,  1991,  2795,   323,  2431,  2005,  2120,   149,  2832,  2833,
     319,   323,  1948,  2689,  2748,   323,  2135,  2212,  2948,   221,
     323,  1949,   320,   321,  1218,   222,  1307,  1223, -2157,  1307,
     322, -2157, -2157, -2157, -2157, -2157,  2908,   661,   661,  1025,
    1257,  2910,  1025,  1025,  2935,  1340,  3324,  2757,   225, -2157,
    2006,  2939,  1219,  1220,  1221,  3113,  1025,  2884,  2132,  2834,
    2835,  3028,  2293,  1222,  3077,  3153,  2007,  3156,   969,  3092,
     186,  3150,    42,  3165,  2833,  1025,  3227,  3244,  1025,  2416,
    3250,  1045,    42,   262,  1025,  3252,  3344,  1243,  1025,  3381,
    3382,  3439,  1025,  2520,  2264,   140,  1025,  3445,  3474,  3490,
    1025,  1025,    42,  1025,  3114,  3520,  1025,   261,  1025,  1025,
    1025, -2157,  2203,  2192,  2193, -2157,  1025,  3511,   269,  1025,
    2559,   448,  2200,  2204,  2834,  2835,  1025,    42,  1284,  3286,
    2163,  1341,  1025,  3098,   988,  3101,   351,   991,  3104,  1025,
    1992,   271,  2774,  2221,  2205,  1023,  2521,   278,  2382,  3273,
    1025,  2206,  3278,  2522,  1025,  3280, -2157,  3029,  1025,   137,
     138,  2243,  2222,  2223,  1025,  3033,  1330,  1025,   679, -2157,
    2019,  3372,  1050,  3345,  1342,  3347,  2624,  2625,  3287,    45,
    3163,  1062,  2224,  3167,  1062,   970,  2647,  3222,   279,  1034,
    2647,  1018,  1066,    42,  1071,  2260,  2389,    42,  1062,  3429,
    3242,  3459,  1062,  3435,  1366,  1075,   352,    89,     1,  1088,
     281,   684,  2419,  3373,  1062,  2006,  1071,  1993,    59,   935,
      42,    89,  1099,  2282,  1366,  1071,   282,  1323,   138,     2,
       3,  2007,  1108,   137,   138,  1032,  3259,    42,  1115,  1109,
      85,    42,  3106,   285,  2156,  1150,  2157,  2158,  2159,    84,
      85,    42,  1156,  1032,    42,    42,  1099,   286,  2163,  1991,
    1099,  2523,    89,  2350,  1099,  2168,  2351, -2157, -2157,   287,
    1071,  2350,  2850,  1071,  2351,     2,     3,  2265,  2244,    89,
      89,    89,  1454,    89,  2401,    89,    89,   379,  2266,  1461,
     288,    89,    89,   289,   971,    85,   353,  1103,  2294,  2674,
    2067,  3024,  3025,   290, -2157,     5,     6,   299,     7,     8,
    3460,  3015,    42,     9,  3461,   291,   300,   301,  2295,    84,
    1995,    42,   302,   303,   304,    42,  1390,  1495,  2247,    89,
      10,    11,  3383,  1391,  2247,  1291,  1996,   292,  1013,    89,
    2269,  2270,  2271,  2272,  1513,  3223,   293,  1988,    12,  1232,
    1990,     5,     6,  2488,     7,     8,  2296,   294,    46,     9,
    1233,    85,   192,    89,    89,    85,   295,   305,  2297,  3505,
    2352,    47,    89,  2353,   193,   297,    10,    11,  2352,  2298,
    3107,  2353,  3108,   436,   437,  2111,  3348,  2245,    89,    89,
    2114,  2112,  2031,  2168,    12,  2163,    48,  2299,  1992,    42,
    1238,  1239,   194,  2163,  1506,  1033,    42,  2300,  3281,  1033,
    2301, -2157,   339,  1234,  1927, -2157,  2322,  2231, -2157,    85,
    1284,  1284,    85,  2302,    42,  2507,  2163,   340,  1235,  1284,
   -2157, -2157,  1871,  2220,    42,  2025,  3017,    42,  2800,  1961,
     341,  2802, -2157, -2157,    49,  1181,  2048,  1967,    42,  1185,
   -2157,  2899,  2156,  1189,  2157,  2158,  2159,  2992,  2919,    42,
    2921,  2922,   438,  1025,   342,    13,  2422,   439,  2727,   441,
     343,  2303,  2273,    42,  3146,  1993,    42,  1499,  3460,  2927,
      85,  2160,  3461,  2960,  2161,   344,  2162,  2260,   372,    85,
      42,  2020,  2000,    85,   376,   195,  2008,  2017,  2008, -2157,
    3154,  2304,   385,  2400,   137,   138,  2163,    42,    89,  1034,
    2203,  2305,  1034,  2430,  2032,  2035,  2164,  1236,  1041,  3185,
    3465,  2204, -2157,   377,  3476, -2157,    42,  3421,  3422,   380,
    2168,    42,  2306,  1994,   384,  2165,  2307,  3478,  2168,    14,
    1034,    89,  2205,    89,    89,    89,   396, -2157,  1377,  2206,
     387, -2157,    89,    89,  -273, -2157,    89,   429,  2166,   429,
      89,  2168,  2167,  2344,  2308,  2762,   391,  1500,  2487,  1150,
    2078,  2136,   138,  2309,    85,    89,  2221,  1365,  1995,    42,
    1025,  1025,  1025,  2366,  3465,  2779,   397,  2500,  2056,    15,
    2333,   398,   196,   406,  1996,  2222,  2223,   306,  2363,  2364,
     360,  3478,    85,   415,   365,    85,  1493,   438,    42,  3482,
    1291,  3484,   439,   440,   441,  2224,    85,  1094,  2562,   416,
      89,  2565,  2566,  2567,  2568,   197,  1100,    85,  2408,  3063,
    3063,  3063,  3063,  3353, -2157,  3356,  3357,  3358,  3359,  2215,
    2216,  2168,  -273,   931,    85,  2108, -2157,   429,   429,  1031,
      17,  1938,   429,  1939,    89,   422,  2118,  2119,  -273,  2023,
     198,    42,  1049,  1219,  1220,  1245,   932,    16, -2157, -2157,
    1198,  1197,   199,  1201,  1200,  2235,  1204,  2236,    89,   399,
     425, -2157, -2157, -2157, -2157, -2157,  1875,  1115,  1150,  2160,
    1067,   307,  2161,   426,  2162,   400,   308,   455,  3516,   309,
      42,  -273,   525,   491,   492,   493,  1084,  1085,  3491,  3492,
     200,  2642,  1091,   453,  2163,  1093,   310,  3231,  3232,  2750,
       1,  2049,   494,  2049,  2164,  2653,   201,  2654,  2936, -2157,
    2388,   311, -2157, -2157,   312,   456,  2665,   313,   401,   467,
    -273,     2,     3,  2454,  2999,  2973,   314,   203,  3097,  3097,
     105,  3097,  2150,  2151,  3097,   106,   470,     2,     3,  2782,
    1371,  1372,  1373,  1455,  1456,  2970,  2166,  1459,  1460,  -273,
    2167,  3168,  3014,   471,   477,  1064,   473,   402,  -273,   407,
     495,   496,   497,   498,   499,   500,  1374,   315,  3170,  1073,
     474,   204,   475,  1078,   526,   476,   501,   502,   503,   316,
     107,   108,  2260,   537,  2260,  1092,   403,   539,   109,   543,
     317,   366,   367,   368, -2157,   404,   205,     5,     6,   545,
       7,     8,   546,   549,  3292,     9,   458,   550,   551,  2644,
     554,   555, -2157,     5,     6,   565,     7,     8,   566,   567,
     318,     9,    10,    11,  2655,  2656,  2056,  2659,   570,  2168,
     345,   346,   347,   348,   349,   189,   190,   585,    10,    11,
      12,  2978,   575,   191,    42,  2680,     1,   408,   586,   596,
    2986,  2987,  2191,   591,   597,   601,    12,   614,  2195,   608,
   -2157,  2648, -2157,   409,   207,  1291,   617,     2,     3,   618,
    3293,   319,  3294,   208,   619,   622,   647, -2157,  3063,  3063,
     650,   192,  3063,   320,   321, -2157,   656,  3295,   657, -2157,
     662,   322,   664,   193,   459,  3296,     4,   665, -2157,  3297,
   -2157, -2157,   323, -2157,  2716,  2685,   410,   667,   666,  1928,
     460,   668,   669,   675, -2157,  2804,   685,   504,  2228,   936,
     505,   194,   941, -2157,  3298,   962,   943,    13,   944,   945,
    2816,   950,   960, -2157,  1943,  1475,  1476,  1477,  1478,  3277,
     961,  2840,  3277,     5,     6,   411,     7,     8,   968,   973,
     975,     9, -2157,   461,  2719,   977,   978,   209,   210,   979,
     996,   998,  1003,  1005,  2375,  1006,  1007,  1009,    10,    11,
    1010,  1011,  1012,  1014,   412, -2157,  1186,  1247,  1248, -2157,
    1249,  1250,  1251,   413,  1252,  2279,    12,  1254,  1194,   429,
     429,  1253,   462,  1255,  1256,    89,    89,  1929,  1259,  2274,
    2776,  1258,  2777,  1260,  3097,  1261,  1263,  1297,  1262,  2930,
    1304,  1305,    85,  1930,   195,  2187,  1306,  1309,  1366,  1366,
    2940,   463,  1944,  2196,  1310,  2196,  1312,  1366,  1322,  1313,
     464,  1328,  1314,  1315,  2445,  2447,  1316,  1317,  1945,   506,
    1318,  1326,   110,  1327,  1329,  1333,  3291,  1352,  1353,  1358,
     138,    89,  2367,  1356,  2457,   507,  1931,    13, -2157,   508,
    1359,  1384,  2232,  1368,  1388,  1364,  1389,  1392,  2549,   111,
    1393,  1395,  2430,  1400,  2242,  1412,  3063,  1053,  1053,  1401,
    3198,  1946,  3063,  3063,  1396,  3063,  3063,  3063,  3063,  1414,
    1034,  1419,  1284,  1452,  3063,  1932,  1403,   509,  1284,  1284,
    1366,  1462,  1465,  1291,  1284,  1284,  1284,  1284,  1481,  1489,
    1490,   196,  1491,  1492,  1496,  1034,  1498,  1501,  3292,  1502,
    1947,  2387,  1510,  1512,  1933,   510,  1851,  1852,  1366,    16,
    1853,  3200,   594,  1934,  1859,  1854,   661,  1863,  1866,  1867,
     112,  2008,  2942,   511,   197,  2947,  1868,  1869,  1923,  1948,
    1915,  1954,  2017,  1926,  1296,  2008,  2550,  1298,  1949,  1299,
    1300,  1301,  1302,  1303,    89,    51,    52,    53,    54,    55,
      56,    57,  2551,  1053,  2329,  2330,  2331,    14,  1355,   198,
    1979,  2335,  3315,  1209,  3293,  1937,  3294,  1323,  1955,  3109,
    3323,   199,  1956,  3063,  1957,  1958,  3063,  3063,  3063,  3063,
    1959,  3295,  1960,  1145,  3328,  1984,  2002,  2022,  2360,  3296,
    2040,  2041,  2038,  3297,  2039,  2552,  2042,  2044,  2370,  2371,
    3277,   429,  2045,  2046,   512,  2059,  1472,    15,  2065,   200,
    2072,  2074,   113,    89,  2079,  2089,  2076,  2090,  3298,  2099,
      89,  2100,  2102,  2104,  2109,   201,  2643,  2124,  2113,  2398,
    2138,    89,  2115,   202,  2553,  2131,  2133,  2139,  2141,    16,
    1861,  2175,  2177,  2178,  2180,  2186,   203,  2229,  2695,  2233,
    2234,  2237,    89,  2261,  2423,  1513,  2239,  1284,  3063,  2253,
    1034,    89,  2275,  2554,  2285,  2287,  3063,  2288,    17,  2291,
     513,  2320,  2555,  2292,  2323,  3371,   429,   429,  2318,  3169,
    2324,  2325,  2260,  2321,  2337,  2340,  2341,  2885,  2342,  3176,
     204,   429,   114,  2343,  2345,  2339,    89,    89,    89,  2346,
     115,  2347,    89,  2886,  2887,  2348,  2361,   215,  2349,  1285,
    1366,  1860,  2888,  2377,  3415,   205,  1968,  1969,  1970,  1971,
    2384,  2379,  3233,  2380,  1430,  3118,  3119,  3120,    89,  3122,
    3123,  3124,  3125,  3126,  3127,  2386,  2539,  2539,  3130,   206,
    2539, -2157,  2814,  2392,  2817,  2393,  2889,  2399,  2402,  2403,
    2406,  2412,  2440,  2420,  1284,  2890,  2426,  2438,  2485,  2486,
    1222,  2497,  1284,  2503,  2511,  1284,  1284,  1284,  1284,  2569,
    2526,  2528,  1366,  2529,  2536,  2512,  2574,  1284,  2547,  2560,
    2592,  2548,  1025,   207,  2891,  2561,  2573,  2589,  1209,  2594,
    2596,  2598,   208,  2597,  2602,  1972,  1973,  1974,  1975,  1976,
    1977,  1284,  2641,  2611,  2611,  1970,  1971,  2611,  1284,  2605,
    2623,  2626,  2627,  3420,  2628,  2645,  3488,  2629,  2650,  2630,
    2661,  2681,  2679,  2682,  2683,  2686,  3190,  2692,  2693,  2892,
    2696,  2697,  2698,  2699,  2639,  2700, -2157,  2032,  2701,    89,
    3282,     1,  2840,  2717,  2718,  2720,  2721,  2722,  2008,  2726,
    1221,  2733,  2008,    89,  2735,    89,  2744,  2745,  2746,  3206,
    2749,  2611,     2,     3,    89,  2360,  2753,  2761,  2670,  2670,
    2784,  2893,  3247,  3248,  2763,  2754,   209,   210,  2789,  2798,
    2797,  1431,  1972,  1973,  1974,  1975,  1976,  1977,  2362,  1025,
    2684,  3466,  3467,  3468,  3469,  3470,  3471,  2813,  2801,  2819,
    2803,    89,  2576,  2805,  2818,  2806,  2807,  1025,  2808,  2841,
     429,  1264,  1265,  1266,  2844,  2904,  3354,   302,  1267,  1268,
      42,  2905,  3354,  3317,  2906,  3363,  3364,  3365,  3366,  2912,
      89,  2914,  2917,  2920,  3056,  3056,  3056,  3056,     5,     6,
   -2102,     7,     8,  2931,  1209,  3483,     9,  2937,  2938,  1972,
    1973,  1974,  1975,  1976,  1977,  1291,  2728,  2941,  2943,  2951,
    2955,  2944,  1269,    10,    11,  2962,  2959,  2974,  2977,  2985,
    2995,  3245,  3246,  3247,  3248,  3009,  3020,  3285,  3021,  3036,
    3029,    12,  1963,  3074,  3078, -2157,  3085,  3010,  3086,  3012,
    1952,  3087,  3099,  3088,  3090,  1115,  3100,  3102,  3103,  3110,
    3112,  1285,  1285,  3121,  1366,   928,  3128,  3129,  1432,  3135,
    1285,  1879,  3117,  1150,  1433,  1434,  1435,  3540,  3136,  2611,
    2997,  3139,  3140,  1992,  3141,  3142,  3143,  2765,  2196,  1284,
    3144,  3145,  3151,  3437,  1436,  2367,  3440,  3441,  3442,  3443,
    3157,  3318,  2611,  3159,  1366,  3161,  3166,  3172,    89,  2539,
    1972,  1973,  1974,  1975,  1976,  1977,  3177,  3179,  3178, -2157,
     928,  3194,  3199,  3196,  3400,  3180,  3203,  1216,  3214,  3211,
    3224,  3218,  3234,  3340,  3235,  3236,  3237,  3243,  3238,  1284,
    3239,  3434,  3240,  3253,  3254,   930,  3264,  1366,  1033,  1366,
    2976,  3289,  1284,   661,  1284,  3271,  3316,  3267,  2902,    92,
    3307,   215,   661,   661,  3310,  1284,  3308,  3311,  3312,  3313,
    2611,    89,  2592,  3320,  1880,  3322,  3449,  3326,  3495,  3327,
    3329,  2611,  1881,  3330,  3331,  3333,  2611,  3335,  1882, -2157,
    1883,  3339, -2157,  3351,  1964,  2008,  3360,  3349,  3368,  3384,
     930,  1884,  3396,  1437,  3394,  3395,  1438,  3397,  3398,  3413,
    3401,  2017,  3414,  2008,  1439,  3419,  1209,    89,  3426,  3436,
    3446,  2329,  3472,  3457,  3485,  3509,  3494,  3528,    89,  1885,
    3496,  3497,  3498,  3529,   187,   218,  3499,  3530,  3539,  3526,
    3531,  2981,  2933,  3508,  1319,  1886,  2709,  2123,  3266,  1440,
    1887,  2411,  2577,  2360,    74,  2961,   835,  2963,  2611,    75,
    2666,  1921,  1888,  3056,  3056,  1025,  2958,  3056,  2675,  1889,
     547,  1025,    89,   224,    89,  2982,    89,   371,  3189,   542,
     229,  3434,  1004,  1053,  1441,  2276,   548,  2277,  3191,    89,
     374,  1025,   940,   574,   678,   967,  1284,    89,    89,   218,
     946,   572,  3506,  1442,  1443,  1940,  2334,   947,  1311,   429,
    1175,   429,  2372,  2537,  1444,   604,  2149,  3213,   218,  1445,
    3008,    89,    89,  1919,  2657,  2153,  2437,  1284,  2725,  3527,
    2545,  2664,  2455,  2069,  3325,  3184,    69,  3475,   161,  2611,
      70,  3302,  2418,    71,  1090,  3054,  3054,  3054,  3054,  2611,
    2611,  2421,   536,  1332,  1270,  2425,  2174,  3003,  1446,  1857,
      89,  3290,  1246,  3385,  1113,  3080,  2094,  2061,  3512,  1271,
    3001,  1115,  2051,  1484,  3149,  3393,  2105,  1150,  3148,  3131,
    2897,  2651,   623,  2037,  2319,  3515,  1272,  2286,  2755,  2578,
    1447,  3284,  2783,  3447,  1284,  1284,   215,  1150,  3152,  2898,
    2506,  2579,  1274,  2572,  3094,  1284,  1284,  3095,  1284,  2621,
    3279,  1284,  3448,  1284,  2812,  2190,  3306,  1284,    64,  2901,
    3535,  2851,  3230,  1907,  1890,  2255,  2852,  3283,  3035,  1952,
    2254,  1891,  2182,  3524,  3428,  3229,  3352,  3369,  2147,  3361,
     531,   532,  1275,   661,  1874,  2967,  2068,   218,  2640,   686,
       0,   218,     0,  1892,  1276,     0,    89,     0,  1893,     0,
       0,  3056,     0,     0,     0,     0,     0,  3056,  3056,    89,
    3056,  3056,  3056,  3056,     0,     0,     0,     0,     0,  3056,
       0,  2611,  3155,  2611,     0,     0,  3314,     0,     0,     0,
       0,     0,     0,  3038,  3039,  1277,     0,     0,     0,   302,
    1267,  1268,    42,     0,     0,     0,     0,    89,     0,     0,
    2008,   489,   490,   491,   492,   493,     0,    89,     0,  1025,
    1025,     0,     0,     0,     0,     0,     0,  2670,     0,     0,
    3186,  2670,   494,     0,  1278,   429,     0,     0,     0,     0,
       0,     0,     0,     0,  3040,   429,  1279,    89,     0,     0,
       0,     0,     0,     0,     0,     0,    89,     0,  1280,  1281,
    2924,     0,     0,     0,     0,     0,  1282,     0,     0,  1283,
       0,     0,     0,     0,     0,     0,     0,   323,  3056,     0,
       0,  3056,  3056,  3056,  3056,     0,     0,     0,     0,     0,
     495,   496,   497,   498,   499,   500,     0,  3215,     0,     0,
       0,     0,     0,  2611,     0,     0,   501,   502,   503,     0,
       0,     0,  2765,     0,  3054,  3054,     0,     0,  3054,     0,
       0,     0,     0,   651,     0,  1115,  1115,     0,     0,  3241,
       0,     0,     0,     0,   218,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  2611,     0,  2187,     0,     0,  1209,     0,     0,
       0,     0,     0,  3056,     0,     0,     0,  1366,     0,     0,
    1033,  3056,     0,     0,     0,  1034,     0,     0,  1034,     0,
       0,  1284,     0,     0,  1284,     0,  1284,     0,  2611,   218,
       0,     0,     0,     0,     0,     0,     0,  3055,  3055,  3055,
    3055,  3425,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    89,     0,     0,     0,     0,     0,     0,  2576,     0,
       0,     0,     0,     0,     0,     0,     0,  1264,  1265,  1266,
       0,     0,     0,   302,  1267,  1268,    42,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   504,   429,     0,
     505,    89,     0,  1285,     0,     0,     0,     0,     0,  1285,
    1285,   218,     0,     0,     0,  1285,  1285,  1285,  1285,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1269,     0,
       0,     0,   215,     0,     0,  1015,  1016,  1017,  1019,     0,
       0,     0,     0,     0,    89,     0,     0,     0,     0,  1284,
       0,     0,  2611,  1047,     0,     0,     0,     0,     0,     0,
    1034,     0,  3054,     0,     0,     0,     0,     0,  3054,  3054,
       0,  3054,  3054,  3054,  3054,     0,     0,  2611,     0,  2611,
    3054,     0,  1284,     0,    89,     0,     0,     0,  1069,     0,
       0,     0,  1430,     0,  1074,     0,  1076,     0,     0,     0,
    1083,     0,     0,  1083,     0,     0,  1083,     0,     0,     0,
       0,     0,     0,     0,     0,    89,  1095,     0,     0,   506,
      89,     0,    89,     0,     0,     0,  1270,   661,     0,     0,
       0,  1095,     0,     0,     0,   507,  1143,     0,     0,   508,
       0,  1271,    89,  1019,  1154,  1157,     0,     0,     0,  1177,
       0,     0,     0,     0,  1033,     0,     0,  1187,  3041,    89,
       0,  3042,     0,     0,     0,     0,     0,     0,     0,  3215,
       0,     0,     0,  1211,  3043,  1284,     0,   509,     0,  3054,
    2210,  2211,  3054,  3054,  3054,  3054,  3444,  2227,  1285,     0,
    1264,  1265,  1266,     0,     0,     0,   302,  1267,  1268,    42,
    2187,     0,     0,     0,     0,   510,  1034,     0,     0,     0,
    1284,     0,     0,  3044,  3045,     0,  3055,  3055,     0,     0,
    3055,     0,     0,   511,     0,     0,  3046,     0,    89,    89,
      89,    89,    89,    89,     0,     0,     0,     0,     0,     0,
    3477,  1269,     0,     0,     0,     0,     0,     0,     0,  1431,
       0,     0,     0,     0,     0,     0,     0,     0,  2577,     0,
       0,     0,     0,     0,  3054,     0,   299,  3047,     0,     0,
       0,  1025,  3054,     0,     0,   300,   301,  3276,     0,     0,
    3276,   302,   303,   304,    42,  1285,     0,     0,     0,     0,
       0,     0,     0,  1285,     0,     0,  1285,  1285,  1285,  1285,
       0,     0,     0,     0,   512,     0,  3048,     0,  1285,     0,
       0,     0,     0,     0,     0,  1284,     0,  3517,  3049,     0,
       0,   192,     0,     0,     0,     0,   305,     0,     0,     0,
    3050,  3051,  1285,   193,     0,     0,     0,     0,  3052,  1285,
       0,  3053,     0,     0,     0,     0,     0,     0,     0,   323,
       0,     0,     0,     0,  3533,  3534,  3517,     0,     0,     0,
    1270,   194,     0,    89,     0,  3541,     0,  1033,     0,     0,
     513,     0,     0,     0,  2391,  1271,  1432,  1150,     0,     0,
       0,     0,  1433,  1434,  1435,     0,     0,     0,     0,     0,
       0,     0,  1272,     0,     0,  2578,     0,     0,  1211,     0,
       0,     0,  1436,     0,     0,     0,     0,  2579,  1274,     0,
       0,     0,  1378,     0,  3055,  2435,     0,     0,     0,     0,
    3055,  3055,     0,  3055,  3055,  3055,  3055,     0,     0,     0,
       0,     0,  3055,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1275,  3378,
       0,     0,    85,  1406,   195,     0,     0,     0,     0,     0,
    1276,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1426,  1426,  1426,     0,  1426,     0,  1426,  1426,     0,     0,
       0,     0,    92,    92,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1277,     0,  2091,     0,     0,     0,     0,     0,     0,
       0,  1437,     0,     0,  1438,     0,     0,     0,     0,     0,
    1157,     0,  1439,     0,     0,     0,     0,     0,     0,     0,
    1508,  3055,     0,     0,  3055,  3055,  3055,  3055,     0,     0,
    1278,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   196,  1279,     0,  1211,  1378,   306,  1440,  3276,     0,
    1285,     0,     0,  1864,  1280,  1281,     0,     0,     0,     0,
       0,     0,  1282,  1270,     0,  1283,     0,     0,     0,  1872,
    1872,     0,     0,   323,   197,     0,     0,     0,  1271,     0,
       0,     0,  1441,  1264,  1265,  1266,     0,     0,     0,   302,
    1267,  1268,    42,     0,     0,  1272,     0,     0,  1273,     0,
    1285,  1442,  1443,     0,     0,     0,  3055,     0,     0,   198,
       0,  1274,  1444,  1285,  3055,  1285,     0,  1445,     0,     0,
       0,   199,     0,     0,     0,     0,  1285,     0,     0,     0,
       0,     0,     0,     0,  1269,     0,     0,     0,  1952,     0,
     307,     0,     0,     0,     0,   308,     0,     0,   309,     0,
       0,  1275,     0,     0,     0,     0,  1446,     0,     0,   200,
       0,  2705,  2706,  1276,     0,   310,     0,     0,     0,  1285,
       0,     0,  2715,     0,     0,   201,     0,     0,     0,     0,
     311,     0,     0,   312,     0,     0,   313,     0,  1447,     0,
       0,     0,     0,     0,     0,   314,   203,     0,  2729,  2730,
    2731,  2732,     0,     0,  1277,     0,  2737,  2738,  2739,  2740,
       0,     0,     0,  2742,     0,     0,     0,     0,     0,     0,
       0,     0,    92,     0,    92,  1157,  1083,     0,     0,     0,
       0,     0,     0,  2060,  1095,   299,   315,  1157,     0,     0,
     204,  2070,     0,  1278,   300,   301,     0,     0,   316,     0,
     302,   303,   304,    42,     0,  1279,  1211,  1285,     0,   317,
    1033,  2658,     0,     0,     0,   205,     0,  1280,  1281,     0,
       0,     0,     0,     0,     0,  1282,     0,     0,  1283,     0,
       0,     0,     0,     0,     0,     0,   323,     0,  1285,   318,
     192,  2787,  2788,     0,     0,   305,     0,     0,  2792,  2793,
       0,    92,   193,     0,     0,     0,  1285,  1285,  1285,  1285,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     194,     0,     0,   207,     0,  2116,     0,     0,     0,     0,
     319,     0,   208,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   320,   321,     0,  1285,  1285,     0,     0,  2143,
     322,     0,     0,     0,  2577,     0,  1285,  1285,     0,  1285,
       0,   323,  1285,     0,  1285,     0,     0,     0,  1285,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1053,  1053,  1053,     0,  1053,  1053,  1053,
    1053,  1053,  1053,     0,     0,     0,  1053,     0,     0,     0,
       0,     0,     0,     0,   494,     0,     0,     0,     0,     0,
       0,    85,     0,   195,  2949,  2950,   209,   210,     0,     0,
       0,     0,     0,  2957,     0,   611,   478,   479,   480,     0,
     481,   482,   483,   484,   485,   486,   487,   488,   489,   490,
     491,   492,   493,     0,     0,     0,  2458,  2459,  2460,  2461,
    2462,  2463,     0,     0,  2988,  2989,  1270,     0,     0,   494,
       0,     0,   495,   496,   497,   498,   499,   500,     0,     0,
       0,  1271,     0,     0,     0,     0,     0,     0,   501,   502,
     503,  3011,     0,  3013,     0,     0,     0,     0,  1272,     0,
       0,  2578,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  2579,  1274,  2464,     0,  1209,     0,     0,
     196,     0,     0,     0,     0,   306,     0,   495,   496,   497,
     498,   499,   500,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   501,   502,   503,     0,  3081,  3082,     0,
       0,  3083,  3084,   197,  1275,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1276,     0,     0,     0,
       0,     0,     0,     0,     0,  1285,  1285,     0,     0,  1285,
       0,     0,     0,     0,     0,     0,     0,     0,   198,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     199,     0,     0,     0,     0,     0,     0,  1277,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   307,
       0,     0,     0,     0,   308,     0,     0,   309,     0,   504,
       0,     0,   505,     0,     0,     0,  1285,     0,   200,  1285,
       0,  3138,  1285,     0,   310,  1285,  1278,  1285,     0,     0,
       0,     0,     0,     0,   201,     0,     0,     0,  1279,   311,
       0,     0,   312,     0,     0,   313,     0,     0,     0,     0,
    1280,  1281,     0,     0,   314,   203,     0,     0,  1282,     0,
       0,  1283,     0,     0,   504,     0,     0,   505,     0,   323,
       0,     0,     0,     0,     0,     0,  2173,  1211,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  3183,
       0,     0,     0,  3188,  2998,   315,     0,     0,     0,   204,
       0,     0,     0,     0,     0,     0,     0,   316,     0,  3193,
       0,     0,     0,     0,     0,     0,     0,     0,   317,     0,
       0,     0,     0,     0,   205,     0,     0,     0,  3204,  2465,
       0,   506,  2214,     0,     0,     0,     0,     0,     0,     0,
    1285,     0,  2466,     0,     0,     0,     0,   507,   318,     0,
       0,   508,     0,  1285,     0,     0,     0,     0,     0,  1285,
    1285,     0,  1285,  1285,  1285,  1285,   299,     0,     0,     0,
       0,  1285,     0,  1285,     0,   300,   301,     0,     0,     0,
       0,   302,   303,   304,    42,     0,   506,     0,  1285,   509,
       0,     0,   207,     0,     0,     0,     0,     0,     0,   319,
       0,   208,   507,     0,     0,     0,   508,  2467,     0,     0,
       0,   320,   321,     0,  2468,     0,     0,   510,     0,   322,
       0,   192,     0,     0,     0,     0,   305,     0,     0,     0,
     323,     0,     0,   193,     0,   511,     0,     0,     0,     0,
       0,     0,     0,     0,   509,  1157,     0,     0,     0,     0,
    1209,     0,     0,  2469,     0,     0,     0,     0,     0,     0,
       0,   194,     0,     0,     0,     0,  1285,     0,     0,     0,
    1285,     0,   510,  1285,  1285,  1285,  1285,  2470,     0,     0,
       0,     0,     0,     0,     0,   209,   210,  2471,  2472,     0,
     511,     0,     0,  2473,     0,     0,     0,  1285,     0,     0,
       0,  1285,     0,  2474,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  2383,     0,   512,     0,     0,     0,
       0,  2390,     0,     0,     0,  2475,     0,     0,  2476,  2477,
       0,     0,  1157,  2478,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  3338,     0,     0,  3341,     0,     0,
       0,     0,    85,   187,   195,  1285,     0,     0,     0,     0,
       0,     0,  2432,  1285,     0,     0,     0,     0,     0,     0,
       0,   512,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   513,     0,     0,     0,     0,     0,     0,     0,
    2479,     0,     0,     0,     0,     0,     0,  1157,  2489,  1157,
       0,  2480,     0,  1019,   479,   480,  1285,   481,   482,   483,
     484,   485,   486,   487,   488,   489,   490,   491,   492,   493,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  2531,
       0,     0,     0,     0,     0,     0,   494,   513,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   196,     0,     0,  1209,     0,   306,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  3423,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   197,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   495,   496,   497,   498,   499,   500,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     501,   502,   503,     0,     0,     0,     0,     0,     0,   198,
       0,     0,     0,  3450,  3451,     0,  3453,     0,  3455,  3456,
       0,   199,     0,     0,     0,     0,     0,     0,     0,     0,
    1157,   218,     0,     0,     0,     0,     0,     0,     0,     0,
     307,     0,     0,     0,  1157,   308,  1157,     0,   309,     0,
       0,     0,     0,     0,     0,  1157,     0,     0,     0,   200,
       0,     0,     0,     0,     0,   310,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   201,     0,     0,     0,  3501,
     311,  3502,     0,   312,     0,     0,   313,     0,     0, -2158,
       0,     0,  2690,     0,     0,   314,   203,   487,   488,   489,
     490,   491,   492,   493, -2158,     0, -2158, -2158, -2158,     0,
       0,     0,     0,     0,  3514,     0,     0,     0,     0,     0,
     494,  2714,     0,     0,     0,     0,     0,     0,     0,     0,
    3521,  3522,     0, -2158,  3523,     0,   315,  3525,     0,     0,
     204,   504,     0,     0,   505,     0,     0,     0,   316,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   317,
       0,     0, -2158,     0,     0,   205,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   495,   496,
     497,   498,   499,   500,     0,     0,     0,     0,     0,   318,
       0,     0,     0,     0,   501,   502,   503,     0,     0,     0,
       0,     0,     0,     0, -2158,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   207, -2158,     0,     0, -2158,     0,  2785,
     319,     0,   208,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   320,   321,     0,     0,     0,     0,     0,     0,
     322,     0, -2158,   506,     0,     0,   583,     0,     0,     0,
   -2158,   323, -2158,     0,     0,     0,     0,     0,     0,   507,
       0, -2158,     0,   508,     0,     0,     0, -2158,     0,     0,
       0,     0,     0,     0,     0, -2158,     0,     0,     0, -2158,
       0,     0,  1157,     0,     0, -2158,     0,     0,     0, -2158,
   -2158, -2158, -2158,     0,     0,     0,     0,     0,     0,     0,
       0,   509,     0,     0, -2158,     0,   209,   210,     0,     0,
       0,     0,     0,     0,     0,   504,     0,     0,   505,     0,
       0, -2158,     0,     0, -2158,     0, -2158,     0,  1157,   510,
       0,     0,     0, -2158,     0,     0,     0,     0,     0,  1157,
       0,     0,     0,     0,     0,     0, -2158,   511,     0,     0,
       0,     0,  2691,   478,   479,   480, -2158,   481,   482,   483,
     484,   485,   486,   487,   488,   489,   490,   491,   492,   493,
       0,     0,     0,     0,     0, -2158, -2158,     0,     0,     0,
       0,     0,     0,  2979,     0,  1047,   494,  2983,     0,     0,
   -2158,     0,     0,     0,     0,     0,     0,     0, -2158,     0,
    2994,     0, -2158,     0,     0,   218,     0,     0,  3002,  2432,
       0, -2158, -2158, -2158,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   512,     0,
       0,     0,  3016,  3018,     0,     0,     0,   506,     0,     0,
       0,     0,     0,     0,   495,   496,   497,   498,   499,   500,
       0,     0,     0,   507,     0,     0,     0,   508,     0,     0,
     501,   502,   503,     0,     0,     0,     0,     0,     0,     0,
       0,  3079,     0,     0,     0,     0,     0,     0,     0,     0,
       0, -2158,  1266,     0,     0,     0,   302,  1267,  1268,    42,
       0,     0, -2158,     0,   513,   509,     0,     0,     0,     0,
       0,     0,     0,   478,   479,   480,   163,   481,   482,   483,
     484,   485,   486,   487,   488,   489,   490,   491,   492,   493,
       0,     0,     0,   510,     0,     0,     0,     0,     0,     0,
       0,  1269, -2158,     0,     0,     0,   494,     0,     0,     0,
       0,   511,   478,   479,   480,   164,   481,   482,   483,   484,
     485,   486,   487,   488,   489,   490,   491,   492,   493,     0,
       0,     0,     0,     0,   165,   166,     0,  3132,     0,     0,
       0,     0,     0,     0,     0,   494,     0,     0,     0,     0,
    3147,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0, -2158,   495,   496,   497,   498,   499,   500,
       0,   504,     0,   167,   505,     0,     0,     0,     0,     0,
     501,   502,   503,     0,     0,   168,     0,     0,  1157,     0,
       0,     0,   512,     0,     0,     0,   169,     0,  1157, -2158,
       0,     0,     0,   495,   496,   497,   498,   499,   500,     0,
     218,     0,     0,     0,   170,     0,     0,     0,     0,   501,
     502,   503,     0,     0,   171,     0,     0,  1033,  2432,     0,
       0,     0,     0,     0,     0,     0,     0,  1211,     0,     0,
     172,     0,     0,     0,     0, -2158,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   513, -2158,
   -2158, -2158, -2158, -2158, -2158, -2158,     0, -2158, -2158,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     173,     0,     0,     0, -2158,     0,     0,     0,     0,     0,
       0,     0,     0,   506,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   174,     0,     0,     0,     0,     0,   507,
       0,     0,     0,   508,     0,     0,     0,     0,   175,     0,
       0,   504,     0,     0,   505,   176,     0,     0,   177,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   178,
       0,   509,     0,   179,     0,     0,     0,     0,     0,     0,
     504,     0,     0,   505,     0,     0,     0,     0,     0,     0,
       0,     0,   180,     0,     0,     0,     0,     0,     0,   510,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     181,     0,  3132,     0,     0,     0,     0,   511,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1525,  1526,
    1527,  1528,  1529,  1530,     0,  1531,  1532,  1533,     0,     0,
       0,  1534,  1535,  1536,  1537,  1538,  1539,     0,   163,     0,
       0,     0,  1157,  1270,     0,     0,  1540,     0,     0,     0,
       0,     0,     0,   506,     0,     0,     0,     0,  1271,     0,
       0,     0,  1541,     0,     0,     0,     0,     0,     0,   507,
       0,     0,     0,   508,   600,  1272,     0,   164,  1273,     0,
    1542,     0,     0,     0,     0,  2432,     0,     0,   512,  1543,
       0,  1274,   506,     0,     0,     0,   165,   166,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1544,   507,  1545,
       0,   509,   508,   610,     0,     0,     0,  1546,     0,     0,
       0,     0,  1547,  1548,     0,  2432,  1549,  1550,  1551,  1552,
       0,  1275,  1553,  1554,     0,   167,     0,     0,     0,   510,
       0,     0,     0,  1276,     0,     0,     0,   168,     0,     0,
     509,     0,     0,     0,   513,     0,  3132,   511,   169,     0,
       0,  3388,     0,  3390,     0,     0,     0,     0,     0,     0,
       0,     0,  1555,     0,     0,     0,   170,     0,   510,     0,
       0,     0,     0,  1157,  1277,     0,   171,     0,     0,     0,
       0,     0,     0,     0,     0,  1556,   511,     0,     0,     0,
    1211,  1557,   172,     0,     0,     0,   218,  2146,  1558,     0,
    1559,     0,     0,     0,     0,     0,  1560,     0,     0,     0,
       0,     0,     0,  1278,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1279,     0,     0,   512,     0,
       0,  1561,   173,     0,     0,     0,     0,  1280,  1281,     0,
       0,     0,     0,     0,     0,  1282,     0,     0,  1283,     0,
       0,     0,     0,     0,     0,   174,   323,     0,     0,  1426,
    1426,  1426,  1426,  1426,  1426,     0,     0,   512,     0,  1562,
     175,     0,     0,     0,     0,     0,     0,   176,     0,     0,
     177,     0,  1563,     0,     0,     0,     0,     0,  1564,     0,
       0,     0,     0,     0,   513,     0,     0,  1565,  1566,     0,
       0,   178,     0,     0,  1567,   179,     0,  1568,  1569,     0,
       0,     0,  1570,     0,     0,     0,     0,     0,  1571,  1572,
       0,     0,     0,     0,   180,  1573,  1574,  1575,  1576,  1577,
    1578,     0,     0,   513,  1579,     0,     0,     0,  1580,     0,
    1581,     0,   181,     0,     0,     0,     0,  1582,  1583,  1584,
    1585,     0,  1586,  1587,     0,     0,     0,  1588,  1589,     0,
    1590,  1591,  1592,  1593,  1594,  1595,  1596,  1597,     0,     0,
       0,     0,     0,  1598,  1599,  1600,     0,  1601,  1602,     0,
       0,     0,  1603,  1604,  1605,  1606,  1607,  1608,  1609,  1610,
    1611,     0,  1612,     0,  1211,     0,  1613,  1614,  1615,  1616,
    1617,  1618,  1619,  1620,  1621,  1622,  1623,  1624,  1625,  1626,
    1627,  1628,  1629,  1630,  1631,  1632,  1633,  1634,  1635,  1636,
    1637,  1638,  1639,  1640,  1641,  1642,  1643,  1644,  1645,  1646,
    1647,  1648,  1649,  1650,     0,  1651,  1652,     0,     0,  1653,
    1654,  1655,  1656,  1657,  1658,  1659,  1660,  1661,  1662,     0,
    1663,  1664,  1665,  1666,  1667,  1668,  1669,  1670,  1671,  1672,
    1673,  1674,  1675,  1676,  1677,     0,     0,  1678,  1679,  1680,
    1681,  1682,  1683,  1684,  1685,  1686,     0,  1687,  1688,  1689,
    1690,     0,  1691,  1692,  1693,  1694,  1695,  1696,  1697,  1698,
    1699,  1700,  1701,  1702,  1703,  1704,  1705,  1706,  1707,  1708,
    1709,  1710,  1711,  1712,  1713,  1714,  1715,  1716,  1717,  1718,
    1719,  1720,  1721,  1722,  1723,  1724,  1725,  1726,     0,  1727,
    1728,  1729,  1730,  1731,  1732,     0,     0,  1733,  1734,     0,
    1735,  1736,  1737,  1738,  1739,  1740,  1741,  1742,  1743,  1744,
    1745,  1746,  1747,  1748,  1749,  1750,  1751,  1752,  1753,  1754,
    1755,  1756,  1757,  1758,  1759,  1760,     0,     0,  1761,  1762,
    1763,  1764,  1765,  1766,  1767,  1768,  1769,  1770,  1771,  1772,
    1773,  1774,  1775,  1776,  1777,  1778,  1779,  1780,  1781,  1782,
    1783,  1784,  1785,  1786,  1787,  1788,  1789,  1790,  1791,  1792,
    1793,  1794,  1795,  1796,  1797,  1798,  1799,  1800,  1801,  1802,
    1803,  1804,  1805,  1806,  1807,  1808,  1809,  1810,  1811,  1812,
    1813,  1814,  1815,  1816,  1817,  1818,  1819,  1820,  1821,  1822,
       0,     0,     0,     0,  1823,  1824,  1825,  1826,  1827,  1828,
    1829,  1830,  1831,  1832,  1833,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1834,     0,     0,     0,     0,
       0,     0,     0,  1835,     0,     0,     0,     0,  1836,     0,
       0,     0,  1837,     0,     0,  1838,  1839,  1840,  1841,     0,
       0,  1842,  1843,     0,  1844,  1845,  1846,  1525,  1526,  1527,
    1528,  1529,  1530,     0,  1531,  1532,  1533,     0,     0,     0,
    1534,  1535,  1536,  1537,  1538,  1539,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1540,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1541,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1542,
       0,     0,     0,     0,     0,     0,     0,     0,  1543,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1544,     0,  1545,     0,
       0,     0,     0,     0,     0,     0,  1546,     0,     0,     0,
       0,  1547,  1548,     0,     0,  1549,  1550,  1551,  1552,     0,
       0,  1553,  1554,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1555,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1556,     0,     0,     0,     0,     0,
    1557,     0,     0,     0,     0,     0,     0,  1558,     0,  1559,
       0,     0,     0,     0,     0,  1560,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1561,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1562,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1563,     0,     0,     0,     0,     0,  1564,     0,     0,
       0,     0,     0,     0,     0,     0,  1565,  1566,     0,     0,
       0,     0,     0,  1567,     0,     0,  1568,  1569,     0,     0,
       0,  1570,     0,     0,     0,     0,     0,  1571,  1572,     0,
       0,     0,     0,     0,  1573,  1574,  1575,  1576,  1577,  1578,
       0,     0,     0,  1579,     0,     0,     0,  1580,     0,  1581,
       0,     0,     0,     0,     0,     0,  1582,  1583,  1584,  1585,
       0,  1586,  1587,     0,     0,     0,  1588,  1589,     0,  1590,
    1591,  1592,  1593,  1594,  1595,  1596,  1597,     0,     0,     0,
       0,     0,  1598,  1599,  1600,     0,  1601,  1602,     0,     0,
       0,  1603,  1604,  1605,  1606,  1607,  1608,  1609,  1610,  1611,
       0,  1612,     0,     0,     0,  1613,  1614,  1615,  1616,  1617,
    1618,  1619,  1620,  1621,  1622,  1623,  1624,  1625,  1626,  1627,
    1628,  1629,  1630,  1631,  1632,  1633,  1634,  1635,  1636,  1637,
    1638,  1639,  1640,  1641,  1642,  1643,  1644,  1645,  1646,  1647,
    1648,  1649,  1650,     0,  1651,  1652,     0,     0,  1653,  1654,
    1655,  1656,  1657,  1658,  1659,  1660,  1661,  1662,     0,  1663,
    1664,  1665,  1666,  1667,  1668,  1669,  1670,  1671,  1672,  1673,
    1674,  1675,  1676,  1677,     0,     0,  1678,  1679,  1680,  1681,
    1682,  1683,  1684,  1685,  1686,     0,  1687,  1688,  1689,  1690,
       0,  1691,  1692,  1693,  1694,  1695,  1696,  1697,  1698,  1699,
    1700,  1701,  1702,  1703,  1704,  1705,  1706,  1707,  1708,  1709,
    1710,  1711,  1712,  1713,  1714,  1715,  1716,  1717,  1718,  1719,
    1720,  1721,  1722,  1723,  1724,  1725,  1726,     0,  1727,  1728,
    1729,  1730,  1731,  1732,     0,     0,  1733,  1734,     0,  1735,
    1736,  1737,  1738,  1739,  1740,  1741,  1742,  1743,  1744,  1745,
    1746,  1747,  1748,  1749,  1750,  1751,  1752,  1753,  1754,  1755,
    1756,  1757,  1758,  1759,  1760,     0,     0,  1761,  1762,  1763,
    1764,  1765,  1766,  1767,  1768,  1769,  1770,  1771,  1772,  1773,
    1774,  1775,  1776,  1777,  1778,  1779,  1780,  1781,  1782,  1783,
    1784,  1785,  1786,  1787,  1788,  1789,  1790,  1791,  1792,  1793,
    1794,  1795,  1796,  1797,  1798,  1799,  1800,  1801,  1802,  1803,
    1804,  1805,  1806,  1807,  1808,  1809,  1810,  1811,  1812,  1813,
    1814,  1815,  1816,  1817,  1818,  1819,  1820,  1821,  1822,     0,
       0,     0,     0,  1823,  1824,  1825,  1826,  1827,  1828,  1829,
    1830,  1831,  1832,  1833,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1834,     0,     0,     0,     0,     0,
       0,     0,  1835,     0,     0,     0,     0,  1836,     0,     0,
       0,  1837,     0,     0,  1838,  1839,  1840,  1841,     0,     0,
    1842,  1843,     1,  1844,  1845,  1846,     0,   688,   689,   690,
       0,     0,     0,     0,     0,   691,     0,     0,     0,     0,
       0,     0,   692,     2,     3,     0,     0,     0,     0,     0,
       0,   693,     0,  2854,  2855,     0,  2856,  2857,  2858,     0,
       0,     0,     0,   694,   695,     0,   696,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     697,     0,     0,     0,     0,     0,     0,   698,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   699,   700,
     701,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   702,     0,   703,   704,   705,     5,
       6,   706,     7,     8,   707,     0,   708,     9,   709,   710,
       0,     0,     0,     0,     0,   711,     0,     0,   712,     0,
     713,   714,   715,     0,    10,    11,     0,     0,     0,     0,
     716,     0,   717,   718,     0,   719,  2859,   720,   721,     0,
       0,   722,    12,     0,  2860,   723,   724,   725,     0,   726,
     727,     0,     0,     0,   728,   729,   730,     0,   731,     0,
       0,     0,   732,     0,   733,   734,     0,     0,     0,     0,
     735,     0,     0,     0,   736,     0,     0,   737,  2861,   738,
       0,   739,     0,   740,     0,   741,   742,  2862,   743,   744,
     745,     0,     0,     0,   746,     0,   747,   748,     0,   749,
       0,     0,     0,     0,     0,     0,     0,   750,   751,     0,
       0,     0,     0,     0,     0,     0,  2863,  2864,     0,     0,
     752,     0,     0,   753,   754,     0,     0,   755,   756,     0,
       0,   757,   758,     0,     0,     0,     0,     0,     0,     0,
     759,   760,   761,     0,   762,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   763,   764,   765,     0,   766,     0,
       0,  2865,   767,   768,     0,     0,     0,   769,     0,     0,
       0,     0,     0,     0,     0,   770,     0,     0,     0,     0,
       0,     0,     0,   771,   772,   773,     0,     0,     0,     0,
       0,   774,   775,     0,     0,     0,     0,   776,     0,     0,
     777,     0,     0,  2866,   778,   779,     0,     0,     0,     0,
       0,     0,   478,   479,   480,   780,   481,   482,   483,   484,
     485,   486,   487,   488,   489,   490,   491,   492,   493,     0,
       0,     0,     0,   781,     0,     0,     0,     0,     0,     0,
       0,   782,     0,     0,     0,   494,     0,   783,     0,     0,
    1118,     0,     0,     0,     0,     0,     0,     0,   784,  1119,
    2867,     0,     0,     0,     0,     0,     0,     0,  1120,     0,
       0,   111,     0,  1121,     0,     0,     0,     0,   785,     0,
     786,   787,     0,     0,     0,     0,     0,     0,     0,   788,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   495,   496,   497,   498,   499,   500,     0,
       0,     0,     0,     0,     0,     0,     0,  1122,     0,   501,
     502,   503,     0,     0,     0,  1123,     0,     0,   789,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   790,
       0,     0,     0,     0,     0,     0,   791,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     792,   793,     0,     0,     0,   794,     0,     0,     0,     0,
       0,  1124,     0,     0,     0,     0,     0,   795,     0,     0,
       0,     0,     0,   796,   797,   798,   799,     0,     0,     0,
     800,     0,     0,     0,   801,     0,  1125,     0,     0,     0,
       0,   802,   803,  1126,     0,  1127,     0,     0,     0,     0,
       0,     0,   804,     0,   805,  1128,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   806,     0,   807,     0,     0,
     808,     0,     0,     0,     0,     0,   809,     0,     0,     0,
       0,  1129,     0,     0,     0,     0,     0,     0,     0,  1130,
     504,     0,     0,   505,     0,     0,     0,     0,     0,     0,
       0,     0,   810,     0,     0,   811,     0,     0,     0,     0,
     812,     0,     0,   813,   814,     0,     0,  2868,  2869,  2870,
    2871,  2872,  2873,  2874,  2875,  2876,  2877,  1131,   815,     0,
       0,     0,     0,     0,     0,   816,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1132,     0,     0,     0,     0,   817,   818,
     819,   820,   821,   822,   823,     0,     0,   824,     0,   825,
       0,   826,   478,   479,   480,     0,   481,   482,   483,   484,
     485,   486,   487,   488,   489,   490,   491,   492,   493,     0,
       0,  1133,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1134,     0,     0,   494,     0,     0,     0,     0,
       0,     0,   506,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   507,     0,
       0,     0,   508,   620,     0,     0,   478,   479,   480,     0,
     481,   482,   483,   484,   485,   486,   487,   488,   489,   490,
     491,   492,   493,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   495,   496,   497,   498,   499,   500,   494,
     509,     0,     0,     0,     0,     0,     0,     0,     0,   501,
     502,   503,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   510,     0,
    1135,  1136,  1137,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1138,     0,     0,   511,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   495,   496,   497,
     498,   499,   500,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   501,   502,   503,   478,   479,   480,     0,
     481,   482,   483,   484,   485,   486,   487,   488,   489,   490,
     491,   492,   493,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   494,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   512,     0,   478,
     479,   480,     0,   481,   482,   483,   484,   485,   486,   487,
     488,   489,   490,   491,   492,   493,  1139,     0,     0,     0,
     504,     0,     0,   505,     0,     0,     0,     0,     0,     0,
       0,     0,   494,     0,     0,     0,     0,   495,   496,   497,
     498,   499,   500,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   501,   502,   503,     0,     0,     0,     0,
       0,     0,     0,   513,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   504,     0,     0,   505,     0,     0,
     495,   496,   497,   498,   499,   500,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   501,   502,   503,     0,
       0,     0,     0,     0,     0,     0,   478,   479,   480,     0,
     481,   482,   483,   484,   485,   486,   487,   488,   489,   490,
     491,   492,   493,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   506,     0,     0,     0,     0,     0,     0,   494,
       0,     0,     0,     0,     0,     0,     0,     0,   507,     0,
       0,     0,   508,   974,     0,   478,   479,   480,     0,   481,
     482,   483,   484,   485,   486,   487,   488,   489,   490,   491,
     492,   493,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   504,     0,     0,   505,   494,     0,
     509,     0,     0,     0,     0,     0,   506,   495,   496,   497,
     498,   499,   500,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   507,   501,   502,   503,   508,   980,   510,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   511,   504,     0,     0,
     505,     0,     0,     0,     0,     0,   495,   496,   497,   498,
     499,   500,     0,     0,   509,     0,     0,     0,     0,     0,
       0,     0,   501,   502,   503,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   510,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     511,     0,     0,     0,     0,     0,   506,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   512,     0,     0,
       0,     0,   507,     0,     0,     0,   508,   981,   478,   479,
     480,     0,   481,   482,   483,   484,   485,   486,   487,   488,
     489,   490,   491,   492,   493,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   504,     0,     0,   505,     0,   506,
       0,   494,     0,     0,   509,  1264,  1265,  1266,     0,     0,
       0,   302,  1267,  1268,    42,   507,     0,     0,     0,   508,
     982,   512,     0,   513,     0,     0,     0,     0,     0,     0,
       0,     0,   510,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   504,     0,     0,   505,     0,     0,     0,
     511,     0,     0,     0,     0,     0,  1269,   509,     0,   495,
     496,   497,   498,   499,   500,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   501,   502,   503,     0,     0,
       0,     0,     0,     0,     0,   510,   480,   513,   481,   482,
     483,   484,   485,   486,   487,   488,   489,   490,   491,   492,
     493,     0,     0,   511,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   506,   494,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   512,   507,     0,     0,     0,   508,   983,   478,   479,
     480,     0,   481,   482,   483,   484,   485,   486,   487,   488,
     489,   490,   491,   492,   493,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   506,     0,     0,     0,     0,
       0,   494,     0,     0,   509,   495,   496,   497,   498,   499,
     500,   507,  1033,     0,   512,   508,     0,     0,     0,     0,
       0,   501,   502,   503,     0,     0,     0,   513,     0,     0,
       0,     0,   510,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   504,     0,     0,   505,
     511,     0,     0,   509,     0,     0,     0,     0,     0,   495,
     496,   497,   498,   499,   500,     0,   985,     0,     0,     0,
       0,     0,     0,     0,     0,   501,   502,   503,     0,     0,
     513,   510,   478,   479,   480,     0,   481,   482,   483,   484,
     485,   486,   487,   488,   489,   490,   491,   492,   493,   511,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   494,     0,   481,   482,   483,
     484,   485,   486,   487,   488,   489,   490,   491,   492,   493,
       0,   512,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   494,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   504,     0,     0,   505,     0,     0,   506,     0,
       0,     0,     0,   495,   496,   497,   498,   499,   500,     0,
     512,     0,     0,     0,   507,     0,     0,     0,   508,   501,
     502,   503,     0,     0,     0,     0,     0,   513,     0,     0,
       0,     0,     0,     0,   495,   496,   497,   498,   499,   500,
       0,     0,     0,     0,     0,     0,   504,     0,  1270,   505,
     501,   502,   503,     0,     0,     0,   509,     0,     0,     0,
       0,     0,     0,  1271,     0,     0,     0,     0,     0,   986,
       0,     0,     0,     0,     0,     0,   513,     0,     0,     0,
    1272,     0,     0,  1273,   510,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1274,     0,     0,     0,
       0,     0,   511,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   506,     0,     0,     0,   482,   483,
     484,   485,   486,   487,   488,   489,   490,   491,   492,   493,
     507,     0,     0,     0,   508,  2427,  1275,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   494,     0,  1276,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     504,     0,     0,   505,     0,     0,     0,     0,   506,     0,
       0,     0,   509,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   512,   507,     0,     0,     0,   508,  1277,
       0,   504,     0,     0,   505,     0,     0,     0,     0,     0,
     510,     0,     0,     0,   495,   496,   497,   498,   499,   500,
       0,     0,     0,     0,     0,     0,     0,     0,   511,     0,
     501,   502,   503,     0,     0,     0,   509,     0,  1278,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   989,
    1279,     0,     0,     0,     0,     0,     0,     0,     0,   513,
       0,     0,  1280,  1281,   510,     0,     0,     0,     0,     0,
    1282,     0,     0,  1283,     0,     0,     0,     0,     0,     0,
       0,   323,   511,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   506,     0,     0,     0,     0,   483,   484,   485,
     486,   487,   488,   489,   490,   491,   492,   493,   507,   512,
       0,     0,   508,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   506,   494,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   507,
       0,     0,     0,   508,     0,     0,     0,     0,     0,     0,
     509,   484,   485,   486,   487,   488,   489,   490,   491,   492,
     493,     0,     0,   512,     0,     0,     0,     0,     0,     0,
       0,   504,     0,     0,   505,   513,     0,   494,   510,     0,
       0,   509,   495,   496,   497,   498,   499,   500,     0,     0,
       0,     0,     0,     0,     0,     0,   511,     0,   501,   502,
     503,     0,     0,     0,  1264,  1265,  1266,     0,     0,   510,
     302,  1267,  1268,    42,     0,     0,   485,   486,   487,   488,
     489,   490,   491,   492,   493,     0,     0,   511,     0,   513,
       0,     0,     0,     0,     0,   495,   496,   497,   498,   499,
     500,   494,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   501,   502,   503,     0,  1269,     0,     0,     0,     0,
       0,     0,   486,   487,   488,   489,   490,   491,   492,   493,
       0,     0,     0,     0,  1264,  1265,  1266,   512,     0,     0,
     302,  1267,  1268,    42,     0,     0,   494,     0,     0,     0,
       0,     0,     0,   506,     0,     0,     0,     0,     0,   495,
     496,   497,   498,   499,   500,     0,     0,     0,   512,   507,
       0,     0,     0,   508,     0,   501,   502,   503,     0,   488,
     489,   490,   491,   492,   493,  1269,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   504,
       0,   494,   505,   513,   495,   496,   497,   498,   499,   500,
       0,   509,     0,     0,     0,     0,     0,     0,     0,     0,
     501,   502,   503,     0,   984,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   513,     0,     0,     0,     0,   510,
       0,  1033,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   504,     0,     0,   505,     0,   511,     0,   495,
     496,   497,   498,   499,   500,     0,     0,     0,     0,     0,
       0,     0,     0,  3038,  3039,   501,   502,   503,     0,   302,
    1267,  1268,    42,     0,     0,     0,     0,     0,     0,     0,
     493,     0,     0,     0,     0,  3038,  3039,     0,     0,     0,
       0,   302,  1267,  1268,    42,     0,     0,   494,     0,     0,
       0,  1033,     0,     0,     0,     0,   504,     0,     0,   505,
       0,   506,     0,     0,  3040,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   507,   512,     0,
       0,   508,     0,     0,     0,     0,  3040,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   504,     0,     0,   505,   495,   496,   497,   498,   499,
     500,     0,     0,     0,   506,     0,     0,     0,     0,   509,
       0,   501,   502,   503,     0,     0,     0,     0,     0,     0,
     507,     0,     0,     0,   508,     0,     0,     0,     0,   302,
    1267,  1268,    42,     0,   513,     0,     0,   510,     0,     0,
       0,     0,     0,     0,     0,     0,   504,     0,     0,   505,
       0,     0,     0,     0,     0,   511,     0,     0,   230,     0,
     231,     0,   509,     0,     0,     0,     0,     0,   506,     0,
       0,     0,     0,     0,  3040,     0,     0,  1270,     0,     0,
    1033,     0,     0,     0,   507,     0,     0,     0,   508,     0,
     510,     0,  1271,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1033,     0,     0,     0,     0,     0,   511,  1272,
     232,   233,  1273,   506,     0,     0,     0,     0,     0,     0,
     234,     0,     0,     0,     0,  1274,   509,     0,     0,   507,
       0,     0,     0,   508,     0,     0,   512,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1270,     0,     0,
       0,     0,   504,     0,   510,   505,     0,     0,     0,     0,
       0,     0,  1271,     0,  3431,  1275,     0,     0,   506,     0,
       0,   509,   511,     0,     0,     0,     0,  1276,     0,  1272,
       0,     0,  1273,     0,   507,     0,     0,     0,   508,   512,
       0,     0,     0,     0,     0,  1274,     0,     0,     0,   510,
    1033,     0,   513,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   511,  1277,     0,
       0,     0,     0,     0,     0,     0,   509,     0,     0,     0,
       0,     0,     0,     0,     0,  1275,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1276,     0,     0,
       0,     0,     0,   512,   510,   513,     0,  1278,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1279,
       0,     0,   511,     0,   506,     0,     0,     0,     0,     0,
       0,  1280,  1281,     0,     0,     0,  1270,     0,  1277,  1282,
     507,   235,  1283,     0,   508,     0,     0,     0,   512,     0,
     323,  1271,     0,     0,     0,     0,     0,     0,  1270,  2458,
    2459,  2460,  2461,  2462,  2463,     0,     0,     0,  3041,   513,
       0,  3042,     0,  1271,     0,     0,     0,  1278,     0,     0,
     236,     0,   509,     0,  3043,     0,     0,     0,     0,  1279,
    3041,     0,     0,  3042,     0,     0,     0,     0,     0,   237,
     238,  1280,  1281,   512,     0,     0,  3043,     0,     0,  1282,
     510,  1952,  1283,     0,   513,   239,     0,     0,  2464,     0,
     323,     0,     0,     0,  3045,     0,     0,     0,   511,     0,
       0,     0,     0,     0,     0,     0,  3046,     0,   240,     0,
       0,     0,     0,     0,     0,     0,  3045,     0,     0,     0,
     241,     0,     0,     0,     0,     0,  1270,     0,  3046,     0,
       0,   242,     0,     0,     0,     0,     0,     0,     0,   513,
       0,  1271,     0,     0,     0,     0,     0,  3047,     0,   243,
       0,     0,     0,     0,     0,     0,     0,     0,  3041,   244,
       0,  3042,     0,     0,     0,     0,     0,     0,     0,  3047,
       0,     0,     0,     0,  3043,   245,     0,     0,     0,   512,
       0,     0,     0,     0,     0,     0,  3048,     0,     0,     0,
       0,     0,     0,  3402,     0,     0,     0,     0,  3049,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  3048,     0,
    3050,  3051,     0,     0,  3045,   246,     0,     0,  3052,     0,
    3049,  3053,     0,     0,     0,     0,  3046,     0,     0,   323,
       0,     0,  3050,  3051,     0,     0,     0,     0,   247,     0,
    3052,     0,     0,  3053,     0,   513,     0,     0,     0,  3403,
       0,   323,     0,   248,     0,     0,     0,     0,     0,     0,
     249,     0,     0,   250,     0,     0,     0,  3047,     0,     0,
       0,     0,     0,     0,  3404,     0,     0,     0,     0,     0,
       0,     0,     0,  3405,   251,     0,     0,     0,   252,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  3048,   253,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  3049,  3406,
       0,     0,  2465,     0,     0,   254,     0,  3407,     0,     0,
    3050,  3051,     0,     0,     0,  2466,     0,     0,  3052,     0,
       0,  3053,     0,     0,     0,     0,     0,     0,     0,   323,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   255,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    2467,     0,     0,     0,     0,     0,     0,  2468,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  3408,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  2469,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    2470,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    2471,  2472,     0,     0,     0,     0,  2473,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  2474,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  2475,     0,
       0,  2476,  2477,     0,     0,     0,  2478,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  2479,     0,     0,     0,     0,     0,     0,
       0,     0,  3409,     0,  2480
};

static const short yycheck[] =
{
       4,   138,   419,   221,   202,   665,   999,    68,    85,    13,
      14,  1051,   180,    17,   158,  1146,  1151,  1117,  1034,     0,
    1335,   287,   288,  1264,  1265,  1128,   798,   560,   289,   290,
    2238,   698,  2071,   294,  1114,    81,  1342,   796,   650,  2414,
    2285,  2557,    46,    47,    25,  1370,  1890,  2292,  1856,  1857,
      31,  2770,  2771,  2772,   586,     5,    20,   602,    62,   756,
     121,    27,    27,    27,    27,   202,   722,  2005,   781,  2176,
     721,    26,    27,  1889,    78,  2019,  2353,    81,    27,    83,
      27,    85,  2457,   204,   221,   253,     5,    68,     5,   745,
      94,  2016,     5,  1124,  1125,     5,  1127,   101,  1129,  1130,
       5,   105,    20,     5,   108,   109,   718,    25,  1952,    27,
     114,   115,     5,    25,   781,    27,   728,     5,   105,  1048,
       5,   265,   266,  1203,   786,    63,    24,    25,    26,    27,
      24,     5,    26,   137,   790,    67,  1236,  1217,     5,  1068,
     121,    67,     5,   799,   800,  2773,    24,   803,    26,    19,
     154,   807,   350,   157,  2801,     5,    26,   813,   162,   815,
      98,    20,   109,    92,    93,   816,    25,  1207,    27,    27,
     291,   783,     5,   785,   295,    27,   297,     6,   299,   300,
     301,    25,   794,    27,   972,     5,     5,   308,    25,    26,
      27,   312,   313,    86,    87,  1957,  1958,  1959,  1960,    73,
    2571,    75,  2573,    77,    25,    27,    27,   145,    25,    19,
      27,   149,   159,   350,    24,    25,    26,   354,    25,   223,
      27,    27,    25,  2188,    27,    24,    25,    26,    27,   154,
       5,     9,    10,  2453,    12,    13,    14,    15,    16,    17,
     195,   241,   139,    24,    25,    26,    27,     6,   195,   309,
     197,    24,    25,    26,    27,    24,    25,    26,   262,   154,
      24,    25,    26,    27,   268,     5,     5,  2914,  1284,  2916,
      27,     5,    25,     5,    27,     6,   280,    23,     5,   464,
      27,     5,   286,   287,   288,   289,   290,  2287,  2288,  1033,
     294,  2291,  3060,     5,   397,   167,     9,    10,   395,    12,
      13,    14,    15,    16,    17,  2513,    27,     5,     5,    70,
     349,   464,     5,     5,     0,     5,  2355,   255,   344,   537,
       5,   300,   464,   179,    96,    19,    69,  2852,   594,   140,
     141,     5,   453,  2578,    29,   456,    25,     5,    27,   343,
     344,     5,   397,  1474,    27,  2345,   436,   294,  2221,   353,
     551,  2224,   473,   474,   475,   476,    31,   478,   479,   480,
     481,   482,   483,   484,   485,   486,   487,   488,   489,   490,
     491,   492,   493,   494,   195,     5,   431,   338,   195,  1419,
     630,   212,     5,     5,   505,   506,     5,    27,   195,   510,
     167,   512,    28,    87,   592,     5,   195,     5,     5,    27,
     537,  1173,   616,     5,     5,  1061,   527,   528,   529,   530,
    2935,     5,     5,   534,   195,   362,     5,   380,   436,     5,
     276,   622,   195,   370,    24,     5,    26,   374,     5,   279,
     391,   195,   370,  3243,     5,   373,    27,   629,     5,   624,
     378,  3088,   195,  3090,  3254,   463,   664,    53,    54,    55,
      56,    57,   594,     0,    27,   592,   435,  1135,  1136,   279,
     652,     5,     5,  3231,  3232,   412,    18,    19,    20,    21,
      22,   624,    18,    19,    20,    21,    22,   349,    25,   257,
     621,   155,   624,   581,     5,  1273,    61,    62,   426,     5,
    2710,   594,     5,   239,    27,  1151,   253,  1513,   358,     5,
     561,   562,   354,  2503,  2266,  1161,   195,   543,   774,     5,
    1166,     5,     5,   436,    89,    90,    91,     5,   279,     5,
     446,     5,   526,   621,     5,     5,  2526,   664,     5,   250,
     791,   792,   479,     5,     5,   145,  2501,     5,     5,     5,
     630,   464,   263,  2751,   257,     5,     5,     5,   514,   553,
    2358,   506,   556,     5,   624,   195,   592,   583,   618,   820,
     564,   600,   823,   240,   397,   432,   663,   195,   397,   432,
     279,   518,   349,  1235,   405,    23,   288,   581,   397,   583,
     561,   562,    18,    19,    20,    21,    22,   591,   349,   593,
     594,   288,   247,   344,  2594,   542,  2841,   354,   376,   377,
    2975,    27,   401,   566,   559,  2605,   531,   354,   608,  1353,
     468,    23,   550,   600,   436,   547,  1388,   416,  2993,   397,
     401,   547,   519,  3251,   476,  1158,   390,  1160,  1400,     5,
     436,   442,   401,   436,   395,   416,   531,   371,   397,   586,
    2747,   551,   561,  1356,   561,   594,  2490,   416,   595,   551,
     393,   544,   379,   558,  1954,   395,   434,   432,   397,   250,
    2533,   155,   195,   376,   377,   397,   397,   555,  1328,   476,
     555,  1384,   263,   397,  2951,   418,   520,   476,  2955,   683,
     172,  2619,  2682,   329,   688,   689,   690,   691,   692,  1356,
     694,   695,  1389,  2637,   698,   699,  2512,   701,   616,   397,
     704,   630,   706,  3219,   616,   671,   671,   671,   671,   622,
    2635,   715,   401,  2019,  3230,  1260,   666,  1384,   673,   476,
    3091,   434,  1254,   573,   594,   459,   624,  3446,   492,   397,
     624,   735,   679,   680,  1390,  1391,  1392,   741,   631,   432,
     432,   475,   432,   747,   748,   749,   624,   432,   622,   753,
    3397,  1407,   756,   573,   758,   759,   630,   616,   501,   805,
     481,  2086,   390,  2763,   581,   769,  2971,   397,   432,   590,
     774,   775,   549,   346,   397,   397,   497,   781,   397,   616,
     784,   354,   355,   561,   518,   789,  1464,   791,   792,   397,
     397,   239,   796,   797,   798,   397,   397,   470,   802,    28,
      29,   805,   555,   397,   397,   582,   810,   380,   397,  1465,
     383,   397,   573,   817,   624,   819,   820,   397,   822,   823,
     397,   825,   826,   557,   250,   624,   397,   239,   401,  1485,
     397,  3347,   583,   510,   358,  1486,  1253,   263,    10,  3214,
     486,   162,  2546,   624,  2144,   436,  1502,     5,   561,   627,
     593,   624,   586,   397,   397,   624,  1512,   390,  2666,   464,
     624,   595,   605,   606,   573,    14,   987,   877,   344,   990,
     613,   643,   644,   645,   646,   647,   397,   998,   999,   693,
     432,   397,   696,   697,   397,   460,   432,  2499,   527,   365,
     481,   397,   653,   654,   655,   543,   710,  2601,  1510,   677,
     678,   397,    68,   664,   397,  2905,   497,  2907,   364,   397,
      25,   397,    27,   397,   627,   729,   397,   397,   732,   367,
     397,    26,    27,   117,   738,   397,   397,   931,   742,   397,
     397,   397,   746,   506,   336,    20,   750,   397,   397,   397,
     754,   755,    27,   757,   592,   397,   760,   436,   762,   763,
     764,   329,   444,  1882,  1883,   367,   770,   287,   324,   773,
    2240,   397,  1891,   455,   677,   678,   780,    27,   972,   543,
     300,   546,   786,  2830,   647,  2832,    26,   650,  2835,   793,
     301,   436,   588,   629,   476,   693,   559,   436,  2091,  3098,
     804,   483,  3101,   566,   808,  3104,   287,   476,   812,   463,
     464,   364,   648,   649,   818,   484,  1010,   821,  1012,   300,
     436,  3256,   715,  3218,   589,  3223,  2296,  2297,   592,   360,
    2919,   729,   668,  2922,   732,   481,  2332,  3027,   436,  1033,
    2336,    25,   735,    27,   742,  1964,    26,    27,   746,  3346,
     436,   243,   750,  3350,  1048,   748,   436,  1051,    30,   757,
     464,   556,  2132,  3258,   762,   481,   764,   378,    25,   564,
      27,  1065,   770,  1992,  1068,   773,   436,  1005,   464,    51,
      52,   497,   780,   463,   464,    25,  3076,    27,   786,    25,
     195,    27,   254,   431,    38,   793,    40,    41,    42,    25,
     195,    27,    25,    25,    27,    27,   804,   436,   300,   162,
     808,  2201,  1106,   168,   812,   435,   171,   583,   486,   436,
     818,   168,  3112,   821,   171,    51,    52,   519,   481,  1123,
    1124,  1125,  1132,  1127,  2117,  1129,  1130,   464,   530,  1139,
     436,  1135,  1136,   436,   590,   195,   526,  1403,   304,   196,
    1401,  2753,  2754,   436,   435,   127,   128,     9,   130,   131,
     352,    26,    27,   135,   356,   436,    18,    19,   324,    25,
     481,    27,    24,    25,    26,    27,   623,  1171,  1956,  1173,
     152,   153,  3281,   630,  1962,  1963,   497,   436,   683,  1183,
    1968,  1969,  1970,  1971,  1188,  3029,   436,  1331,   170,   340,
    1334,   127,   128,   253,   130,   131,   362,   436,   539,   135,
     351,   195,    64,  1207,  1208,   195,   436,    69,   374,   243,
     275,   552,  1216,   278,    76,   436,   152,   153,   275,   385,
     392,   278,   394,    25,    26,  1491,  3226,   590,  1232,  1233,
    1496,  1492,    20,   435,   170,   300,   577,   403,   301,    27,
     644,   645,   104,   300,    25,   195,    27,   413,  3105,   195,
     416,   629,   436,   404,  1258,   168,  2028,    20,   171,   195,
    1264,  1265,   195,   429,    27,  2194,   300,   436,   419,  1273,
     648,   649,    25,   486,    27,  1352,    26,    27,  2558,  1283,
     436,  2561,   243,   196,   625,   804,    25,  1291,    27,   808,
     668,  2606,    38,   812,    40,    41,    42,    25,  2627,    27,
    2629,  2630,    19,  1117,   436,   241,    20,    24,  2439,    26,
     436,   477,  1979,    27,    25,   378,    27,   436,   352,  2634,
     195,   275,   356,    20,   278,   436,   280,  2256,   436,   195,
      27,  2637,  1336,   195,   436,   197,  1340,  1341,  1342,   300,
      20,   507,    26,  2115,   463,   464,   300,    27,  1352,  1353,
     444,   517,  1356,  2141,  1358,  1359,   310,   508,  1362,    20,
    3399,   455,   275,   436,    20,   278,    27,  3335,  3336,   436,
     435,    27,   538,   436,   436,   329,   542,  3416,   435,   361,
    1384,  1385,   476,  1387,  1388,  1389,    26,   300,  2044,   483,
     436,   352,  1396,  1397,   371,   356,  1400,  1401,   352,  1403,
    1404,   435,   356,  2059,   570,  2505,   436,   526,  2180,  1117,
    1414,   463,   464,   579,   195,  1419,   629,    25,   481,    27,
    1234,  1235,  1236,  2079,  3463,  2525,   630,  2186,  2084,   411,
    2042,   371,   294,   630,   497,   648,   649,   299,   653,   654,
     223,  3480,   195,    26,   227,   195,    25,    19,    27,  3417,
    2238,  3419,    24,    25,    26,   668,   195,   764,  2246,    26,
    1464,  2249,  2250,  2251,  2252,   327,   773,   195,  2124,  2769,
    2770,  2771,  2772,  3235,   435,  3237,  3238,  3239,  3240,   646,
     647,   435,   459,   629,   195,  1489,   629,  1491,  1492,   697,
     472,    24,  1496,    26,  1498,    26,  1500,  1501,   475,    25,
     362,    27,   710,   653,   654,   651,   652,   443,   651,   652,
     819,   818,   374,   822,   821,    24,   825,    26,  1522,   459,
      26,    38,   435,    40,    41,    42,  1234,  1235,  1236,   275,
     738,   393,   278,   624,   280,   475,   398,   436,    25,   401,
      27,   518,   325,    20,    21,    22,   754,   755,   292,   293,
     412,  2323,   760,   531,   300,   763,   418,  3038,  3039,  2488,
      30,  1385,    39,  1387,   310,  2337,   428,  2339,  2648,   643,
    2103,   433,   646,   647,   436,   436,  2348,   439,   518,   436,
     557,    51,    52,   329,  2719,  2688,   448,   449,  2829,  2830,
      60,  2832,  1853,  1854,  2835,    65,   436,    51,    52,  2528,
     113,   114,   115,  1133,  1134,  2685,   352,  1137,  1138,   586,
     356,  2926,  2743,   436,    26,   732,   436,   557,   595,   371,
      97,    98,    99,   100,   101,   102,   488,   489,  2934,   746,
     436,   493,   436,   750,   426,   436,   113,   114,   115,   501,
     110,   111,  2571,   464,  2573,   762,   586,    26,   118,    26,
     512,   674,   675,   676,   138,   595,   518,   127,   128,    26,
     130,   131,    26,    26,   138,   135,   371,   624,    63,  2325,
     397,   436,   366,   127,   128,   624,   130,   131,    26,   397,
     542,   135,   152,   153,  2340,  2341,  2342,  2343,   436,   435,
      18,    19,    20,    21,    22,    18,    19,   432,   152,   153,
     170,  2694,   436,    26,    27,  2361,    30,   459,     5,   397,
    2703,  2704,  1880,   436,   397,   397,   170,   476,  1886,   397,
     204,  2333,   206,   475,   586,  2513,   436,    51,    52,   630,
     204,   593,   206,   595,    20,    20,   436,   221,  3038,  3039,
     436,    64,  3042,   605,   606,   229,   397,   221,     5,   233,
     436,   613,   464,    76,   459,   229,    80,   628,   275,   233,
     244,   278,   624,   280,  2420,  2377,   518,    26,   624,   371,
     475,   397,   263,   432,   258,  2563,   366,   254,  1922,    20,
     257,   104,    26,   300,   258,   594,    26,   241,    26,    26,
    2578,    26,    26,   310,   371,   617,   618,   619,   620,  3099,
      26,  2589,  3102,   127,   128,   557,   130,   131,   397,   397,
      26,   135,   329,   518,  2426,   397,   397,   679,   680,   397,
      26,     5,    20,   436,  2085,    26,    26,    26,   152,   153,
     624,   397,     5,   397,   586,   352,    26,   397,   307,   356,
     397,   397,   397,   595,   397,  1989,   170,     5,  1852,  1853,
    1854,   628,   557,   397,   397,  1859,  1860,   459,   630,  1980,
    2516,   436,  2518,   397,  3105,    26,   630,   397,   594,  2641,
      25,    25,   195,   475,   197,  1879,    25,   397,  1882,  1883,
    2652,   586,   459,  1887,    25,  1889,   397,  1891,   307,   397,
     595,   628,   397,   397,  2160,  2161,   397,   397,   475,   376,
     397,   397,   372,   397,   397,   397,    66,   436,   624,   624,
     464,  1915,  2080,   621,  2175,   392,   518,   241,   435,   396,
       8,   271,  1926,   484,   465,   432,     5,   622,   371,   399,
     622,   600,  2720,   465,  3234,   331,  3236,   720,   721,   663,
    2980,   518,  3242,  3243,   426,  3245,  3246,  3247,  3248,   616,
    1954,     8,  1956,   601,  3254,   557,   663,   434,  1962,  1963,
    1964,     5,     5,  2751,  1968,  1969,  1970,  1971,   389,   436,
     436,   294,   436,   436,   436,  1979,   349,   594,   138,   583,
     557,  2102,     8,    14,   586,   462,   580,     5,  1992,   443,
     663,  2984,     5,   595,   426,   663,  2117,   436,   436,    26,
     470,  2005,  2658,   480,   327,  2661,    26,    70,   464,   586,
      96,   436,  2016,   624,   974,  2019,   459,   977,   595,   979,
     980,   981,   982,   983,  2028,     6,     7,     8,     9,    10,
      11,    12,   475,   816,  2038,  2039,  2040,   361,  3054,   362,
     426,  2045,  3173,   826,   204,   594,   206,  1985,   436,  2837,
    3181,   374,   436,  3353,   436,   436,  3356,  3357,  3358,  3359,
     436,   221,   436,  2719,  3195,   464,    26,     5,  2072,   229,
     594,   436,   600,   233,   624,   518,   436,     5,  2082,  2083,
    3380,  2085,   630,   436,   561,   436,   666,   411,   630,   412,
     629,   355,   562,  2097,     5,    18,   561,    19,   258,    26,
    2104,    26,   157,   223,    25,   428,  2324,   583,   594,  2113,
     624,  2115,   627,   436,   557,   487,   487,     5,   551,   443,
     155,   551,    26,   405,   326,   551,   449,    26,  2394,   397,
     436,   630,  2136,   531,  2138,  2139,   397,  2141,  3438,   624,
    2144,  2145,   397,   586,   436,   436,  3446,   436,   472,   436,
     627,   397,   595,   436,   581,  3255,  2160,  2161,   668,  2931,
     464,   551,  3091,   624,   621,     5,     5,   164,     5,  2941,
     493,  2175,   642,   584,   624,   630,  2180,  2181,  2182,     5,
     650,   488,  2186,   180,   181,   630,   436,  2324,   629,   972,
    2194,     5,   189,     8,  3325,   518,    18,    19,    20,    21,
     324,    26,  3042,    26,    25,  2856,  2857,  2858,  2212,  2860,
    2861,  2862,  2863,  2864,  2865,    70,  2220,  2221,  2869,   542,
    2224,   330,  2577,     5,  2579,     5,   223,   397,   436,   436,
     365,   601,   551,   630,  2238,   232,    14,   555,     5,    26,
     664,   105,  2246,   436,   624,  2249,  2250,  2251,  2252,  2253,
     436,   629,  2256,     5,   643,   630,  2260,  2261,   432,   397,
    2264,    26,  2076,   586,   261,     5,     5,   373,  1051,   623,
     336,   466,   595,   432,   466,    97,    98,    99,   100,   101,
     102,  2285,     8,  2287,  2288,    20,    21,  2291,  2292,   436,
     436,   436,   436,  3333,   436,     5,  3427,   436,   624,   436,
       5,     8,   624,   624,     5,   558,  2962,   330,    25,   306,
     349,   349,   464,   624,  2318,   349,   365,  2321,   436,  2323,
    3108,    30,  3110,   431,   464,     5,   426,     5,  2332,    26,
     655,     5,  2336,  2337,     5,  2339,    25,    14,    14,  2995,
      26,  2345,    51,    52,  2348,  2349,   600,   621,  2352,  2353,
       5,   348,    20,    21,   436,   600,   679,   680,     5,   436,
     397,   182,    97,    98,    99,   100,   101,   102,  2076,  2183,
    2374,  3402,  3403,  3404,  3405,  3406,  3407,   436,   630,     7,
     397,  2385,     9,   397,     6,   397,   397,  2201,   397,   453,
    2394,    18,    19,    20,   273,   397,  3236,    24,    25,    26,
      27,     5,  3242,  3175,   624,  3245,  3246,  3247,  3248,    26,
    2414,   630,    26,    26,  2769,  2770,  2771,  2772,   127,   128,
     624,   130,   131,     8,  1207,  3418,   135,   397,    20,    97,
      98,    99,   100,   101,   102,  3223,  2440,     5,   571,     5,
       5,   279,    69,   152,   153,     5,   551,   672,     5,   397,
     576,    18,    19,    20,    21,   624,   397,  3117,   436,   630,
     476,   170,     5,   558,   630,   215,   628,  2733,    26,  2735,
     476,   397,   436,   630,   630,  2183,  2831,   436,  2833,     5,
       5,  1264,  1265,    25,  2488,  2546,    25,    25,   309,   623,
    1273,   123,   628,  2201,   315,   316,   317,  3537,   452,  2503,
    2718,    25,    25,   301,    26,    26,    26,  2511,  2512,  2513,
      26,    26,    26,  3353,   335,  2683,  3356,  3357,  3358,  3359,
     397,  3177,  2526,    26,  2528,     5,   397,   473,  2532,  2533,
      97,    98,    99,   100,   101,   102,     5,   397,   436,   245,
    2601,    26,   432,    25,  3316,   555,   397,   349,    20,   446,
     144,   558,   436,  3209,   436,   436,   436,     5,   436,  2563,
     436,  3349,   436,     5,    14,  2546,   215,  2571,   195,  2573,
    2691,     5,  2576,  2694,  2578,   447,   379,   397,   464,    62,
     397,  2718,  2703,  2704,   397,  2589,    26,   397,    26,   397,
    2594,  2595,  2596,   573,   226,    26,  3384,   397,  3438,   245,
     397,  2605,   234,   397,   436,   349,  2610,   397,   240,   246,
     242,   464,   446,   397,   551,  2619,   624,   436,    14,     7,
    2601,   253,    26,   444,   244,   244,   447,   630,   397,   436,
     398,  2635,   624,  2637,   455,   397,  1419,  2641,   580,   397,
     436,  2645,    25,   432,   246,     5,   397,   624,  2652,   281,
     397,   397,   397,   624,   137,   138,   397,     5,   624,   397,
     397,  2698,  2645,  3473,   998,   297,  2410,  1503,  3085,   490,
     302,  2125,   299,  2677,    38,  2679,   561,  2681,  2682,    40,
    2349,  1244,   314,  3038,  3039,  2499,  2677,  3042,  2355,   321,
     378,  2505,  2696,   145,  2698,  2699,  2700,   237,  2959,   371,
     149,  3489,   667,  1486,   525,  1984,   379,  1985,  2969,  2713,
     240,  2525,   569,   407,   550,   611,  2720,  2721,  2722,   202,
     581,   406,  3463,   544,   545,  1263,  2044,   583,   990,  2733,
     802,  2735,  2084,  2218,   555,   438,  1852,  3007,   221,   560,
    2724,  2745,  2746,  1241,  2342,  1855,  2152,  2751,  2436,  3514,
    2225,  2346,  2170,  1403,  3189,  2953,    25,  3413,   121,  2763,
      31,  3138,  2130,    31,   759,  2769,  2770,  2771,  2772,  2773,
    2774,  2136,   354,  1012,   401,  2139,  1860,  2722,   599,  1208,
    2784,  3135,   933,  3289,   784,  2789,  1462,  1397,  3480,   416,
    2720,  2499,  1387,  1161,  2896,  3299,  1485,  2505,  2894,  2878,
    2604,  2336,   472,  1362,  2022,  3489,   433,  1999,  2499,   436,
     631,  3112,  2529,  3374,  2818,  2819,  2953,  2525,  2904,  2605,
    2193,   448,   449,  2256,  2818,  2829,  2830,  2819,  2832,  2291,
    3102,  2835,  3380,  2837,  2576,  1879,  3155,  2841,    17,  2610,
    3530,  2595,  3037,  1237,   476,  1963,  2596,  3110,  2764,   476,
    1962,   483,  1874,  3509,  3343,  3036,  3234,  3253,  1847,  3242,
     343,   344,   489,  2984,  1233,  2683,  1402,   350,  2321,   559,
      -1,   354,    -1,   505,   501,    -1,  2880,    -1,   510,    -1,
      -1,  3236,    -1,    -1,    -1,    -1,    -1,  3242,  3243,  2893,
    3245,  3246,  3247,  3248,    -1,    -1,    -1,    -1,    -1,  3254,
      -1,  2905,  2906,  2907,    -1,    -1,  3172,    -1,    -1,    -1,
      -1,    -1,    -1,    18,    19,   542,    -1,    -1,    -1,    24,
      25,    26,    27,    -1,    -1,    -1,    -1,  2931,    -1,    -1,
    2934,    18,    19,    20,    21,    22,    -1,  2941,    -1,  2753,
    2754,    -1,    -1,    -1,    -1,    -1,    -1,  2951,    -1,    -1,
    2954,  2955,    39,    -1,   581,  2959,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    69,  2969,   593,  2971,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  2980,    -1,   605,   606,
    2632,    -1,    -1,    -1,    -1,    -1,   613,    -1,    -1,   616,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   624,  3353,    -1,
      -1,  3356,  3357,  3358,  3359,    -1,    -1,    -1,    -1,    -1,
      97,    98,    99,   100,   101,   102,    -1,  3021,    -1,    -1,
      -1,    -1,    -1,  3027,    -1,    -1,   113,   114,   115,    -1,
      -1,    -1,  3036,    -1,  3038,  3039,    -1,    -1,  3042,    -1,
      -1,    -1,    -1,   526,    -1,  2753,  2754,    -1,    -1,  3053,
      -1,    -1,    -1,    -1,   537,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  3076,    -1,  3078,    -1,    -1,  1860,    -1,    -1,
      -1,    -1,    -1,  3438,    -1,    -1,    -1,  3091,    -1,    -1,
     195,  3446,    -1,    -1,    -1,  3099,    -1,    -1,  3102,    -1,
      -1,  3105,    -1,    -1,  3108,    -1,  3110,    -1,  3112,   592,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  2769,  2770,  2771,
    2772,  3339,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  3135,    -1,    -1,    -1,    -1,    -1,    -1,     9,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    18,    19,    20,
      -1,    -1,    -1,    24,    25,    26,    27,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   254,  3172,    -1,
     257,  3175,    -1,  1956,    -1,    -1,    -1,    -1,    -1,  1962,
    1963,   664,    -1,    -1,    -1,  1968,  1969,  1970,  1971,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    69,    -1,
      -1,    -1,  3339,    -1,    -1,   688,   689,   690,   691,    -1,
      -1,    -1,    -1,    -1,  3218,    -1,    -1,    -1,    -1,  3223,
      -1,    -1,  3226,   706,    -1,    -1,    -1,    -1,    -1,    -1,
    3234,    -1,  3236,    -1,    -1,    -1,    -1,    -1,  3242,  3243,
      -1,  3245,  3246,  3247,  3248,    -1,    -1,  3251,    -1,  3253,
    3254,    -1,  3256,    -1,  3258,    -1,    -1,    -1,   741,    -1,
      -1,    -1,    25,    -1,   747,    -1,   749,    -1,    -1,    -1,
     753,    -1,    -1,   756,    -1,    -1,   759,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  3289,   769,    -1,    -1,   376,
    3294,    -1,  3296,    -1,    -1,    -1,   401,  3418,    -1,    -1,
      -1,   784,    -1,    -1,    -1,   392,   789,    -1,    -1,   396,
      -1,   416,  3316,   796,   797,   798,    -1,    -1,    -1,   802,
      -1,    -1,    -1,    -1,   195,    -1,    -1,   810,   433,  3333,
      -1,   436,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  3343,
      -1,    -1,    -1,   826,   449,  3349,    -1,   434,    -1,  3353,
    1913,  1914,  3356,  3357,  3358,  3359,  3360,  1920,  2141,    -1,
      18,    19,    20,    -1,    -1,    -1,    24,    25,    26,    27,
    3374,    -1,    -1,    -1,    -1,   462,  3380,    -1,    -1,    -1,
    3384,    -1,    -1,   488,   489,    -1,  3038,  3039,    -1,    -1,
    3042,    -1,    -1,   480,    -1,    -1,   501,    -1,  3402,  3403,
    3404,  3405,  3406,  3407,    -1,    -1,    -1,    -1,    -1,    -1,
    3414,    69,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   182,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   299,    -1,
      -1,    -1,    -1,    -1,  3438,    -1,     9,   542,    -1,    -1,
      -1,  3255,  3446,    -1,    -1,    18,    19,  3099,    -1,    -1,
    3102,    24,    25,    26,    27,  2238,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  2246,    -1,    -1,  2249,  2250,  2251,  2252,
      -1,    -1,    -1,    -1,   561,    -1,   581,    -1,  2261,    -1,
      -1,    -1,    -1,    -1,    -1,  3489,    -1,  3491,   593,    -1,
      -1,    64,    -1,    -1,    -1,    -1,    69,    -1,    -1,    -1,
     605,   606,  2285,    76,    -1,    -1,    -1,    -1,   613,  2292,
      -1,   616,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   624,
      -1,    -1,    -1,    -1,  3528,  3529,  3530,    -1,    -1,    -1,
     401,   104,    -1,  3537,    -1,  3539,    -1,   195,    -1,    -1,
     627,    -1,    -1,    -1,  2107,   416,   309,  3255,    -1,    -1,
      -1,    -1,   315,   316,   317,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   433,    -1,    -1,   436,    -1,    -1,  1051,    -1,
      -1,    -1,   335,    -1,    -1,    -1,    -1,   448,   449,    -1,
      -1,    -1,  1065,    -1,  3236,  2148,    -1,    -1,    -1,    -1,
    3242,  3243,    -1,  3245,  3246,  3247,  3248,    -1,    -1,    -1,
      -1,    -1,  3254,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   489,  3271,
      -1,    -1,   195,  1106,   197,    -1,    -1,    -1,    -1,    -1,
     501,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1123,  1124,  1125,    -1,  1127,    -1,  1129,  1130,    -1,    -1,
      -1,    -1,  1135,  1136,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   542,    -1,   436,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   444,    -1,    -1,   447,    -1,    -1,    -1,    -1,    -1,
    1173,    -1,   455,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1183,  3353,    -1,    -1,  3356,  3357,  3358,  3359,    -1,    -1,
     581,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   294,   593,    -1,  1207,  1208,   299,   490,  3380,    -1,
    2513,    -1,    -1,  1216,   605,   606,    -1,    -1,    -1,    -1,
      -1,    -1,   613,   401,    -1,   616,    -1,    -1,    -1,  1232,
    1233,    -1,    -1,   624,   327,    -1,    -1,    -1,   416,    -1,
      -1,    -1,   525,    18,    19,    20,    -1,    -1,    -1,    24,
      25,    26,    27,    -1,    -1,   433,    -1,    -1,   436,    -1,
    2563,   544,   545,    -1,    -1,    -1,  3438,    -1,    -1,   362,
      -1,   449,   555,  2576,  3446,  2578,    -1,   560,    -1,    -1,
      -1,   374,    -1,    -1,    -1,    -1,  2589,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    69,    -1,    -1,    -1,   476,    -1,
     393,    -1,    -1,    -1,    -1,   398,    -1,    -1,   401,    -1,
      -1,   489,    -1,    -1,    -1,    -1,   599,    -1,    -1,   412,
      -1,  2404,  2405,   501,    -1,   418,    -1,    -1,    -1,  2632,
      -1,    -1,  2415,    -1,    -1,   428,    -1,    -1,    -1,    -1,
     433,    -1,    -1,   436,    -1,    -1,   439,    -1,   631,    -1,
      -1,    -1,    -1,    -1,    -1,   448,   449,    -1,  2441,  2442,
    2443,  2444,    -1,    -1,   542,    -1,  2449,  2450,  2451,  2452,
      -1,    -1,    -1,  2456,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1385,    -1,  1387,  1388,  1389,    -1,    -1,    -1,
      -1,    -1,    -1,  1396,  1397,     9,   489,  1400,    -1,    -1,
     493,  1404,    -1,   581,    18,    19,    -1,    -1,   501,    -1,
      24,    25,    26,    27,    -1,   593,  1419,  2720,    -1,   512,
     195,   514,    -1,    -1,    -1,   518,    -1,   605,   606,    -1,
      -1,    -1,    -1,    -1,    -1,   613,    -1,    -1,   616,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   624,    -1,  2751,   542,
      64,  2534,  2535,    -1,    -1,    69,    -1,    -1,  2541,  2542,
      -1,  1464,    76,    -1,    -1,    -1,  2769,  2770,  2771,  2772,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     104,    -1,    -1,   586,    -1,  1498,    -1,    -1,    -1,    -1,
     593,    -1,   595,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   605,   606,    -1,  2818,  2819,    -1,    -1,  1522,
     613,    -1,    -1,    -1,   299,    -1,  2829,  2830,    -1,  2832,
      -1,   624,  2835,    -1,  2837,    -1,    -1,    -1,  2841,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  2856,  2857,  2858,    -1,  2860,  2861,  2862,
    2863,  2864,  2865,    -1,    -1,    -1,  2869,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    39,    -1,    -1,    -1,    -1,    -1,
      -1,   195,    -1,   197,  2667,  2668,   679,   680,    -1,    -1,
      -1,    -1,    -1,  2676,    -1,     5,     6,     7,     8,    -1,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    -1,    -1,    -1,    44,    45,    46,    47,
      48,    49,    -1,    -1,  2707,  2708,   401,    -1,    -1,    39,
      -1,    -1,    97,    98,    99,   100,   101,   102,    -1,    -1,
      -1,   416,    -1,    -1,    -1,    -1,    -1,    -1,   113,   114,
     115,  2734,    -1,  2736,    -1,    -1,    -1,    -1,   433,    -1,
      -1,   436,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   448,   449,   103,    -1,  2980,    -1,    -1,
     294,    -1,    -1,    -1,    -1,   299,    -1,    97,    98,    99,
     100,   101,   102,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   113,   114,   115,    -1,  2790,  2791,    -1,
      -1,  2794,  2795,   327,   489,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   501,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  3038,  3039,    -1,    -1,  3042,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   362,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     374,    -1,    -1,    -1,    -1,    -1,    -1,   542,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   393,
      -1,    -1,    -1,    -1,   398,    -1,    -1,   401,    -1,   254,
      -1,    -1,   257,    -1,    -1,    -1,  3099,    -1,   412,  3102,
      -1,  2884,  3105,    -1,   418,  3108,   581,  3110,    -1,    -1,
      -1,    -1,    -1,    -1,   428,    -1,    -1,    -1,   593,   433,
      -1,    -1,   436,    -1,    -1,   439,    -1,    -1,    -1,    -1,
     605,   606,    -1,    -1,   448,   449,    -1,    -1,   613,    -1,
      -1,   616,    -1,    -1,   254,    -1,    -1,   257,    -1,   624,
      -1,    -1,    -1,    -1,    -1,    -1,  1859,  1860,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2952,
      -1,    -1,    -1,  2956,   488,   489,    -1,    -1,    -1,   493,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   501,    -1,  2972,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   512,    -1,
      -1,    -1,    -1,    -1,   518,    -1,    -1,    -1,  2991,   337,
      -1,   376,  1915,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    3223,    -1,   350,    -1,    -1,    -1,    -1,   392,   542,    -1,
      -1,   396,    -1,  3236,    -1,    -1,    -1,    -1,    -1,  3242,
    3243,    -1,  3245,  3246,  3247,  3248,     9,    -1,    -1,    -1,
      -1,  3254,    -1,  3256,    -1,    18,    19,    -1,    -1,    -1,
      -1,    24,    25,    26,    27,    -1,   376,    -1,  3271,   434,
      -1,    -1,   586,    -1,    -1,    -1,    -1,    -1,    -1,   593,
      -1,   595,   392,    -1,    -1,    -1,   396,   415,    -1,    -1,
      -1,   605,   606,    -1,   422,    -1,    -1,   462,    -1,   613,
      -1,    64,    -1,    -1,    -1,    -1,    69,    -1,    -1,    -1,
     624,    -1,    -1,    76,    -1,   480,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   434,  2028,    -1,    -1,    -1,    -1,
    3333,    -1,    -1,   461,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   104,    -1,    -1,    -1,    -1,  3349,    -1,    -1,    -1,
    3353,    -1,   462,  3356,  3357,  3358,  3359,   485,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   679,   680,   495,   496,    -1,
     480,    -1,    -1,   501,    -1,    -1,    -1,  3380,    -1,    -1,
      -1,  3384,    -1,   511,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  2097,    -1,   561,    -1,    -1,    -1,
      -1,  2104,    -1,    -1,    -1,   533,    -1,    -1,   536,   537,
      -1,    -1,  2115,   541,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  3207,    -1,    -1,  3210,    -1,    -1,
      -1,    -1,   195,  2136,   197,  3438,    -1,    -1,    -1,    -1,
      -1,    -1,  2145,  3446,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   561,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   627,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     598,    -1,    -1,    -1,    -1,    -1,    -1,  2180,  2181,  2182,
      -1,   609,    -1,  2186,     7,     8,  3489,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2212,
      -1,    -1,    -1,    -1,    -1,    -1,    39,   627,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   294,    -1,    -1,  3537,    -1,   299,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  3337,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   327,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    97,    98,    99,   100,   101,   102,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     113,   114,   115,    -1,    -1,    -1,    -1,    -1,    -1,   362,
      -1,    -1,    -1,  3386,  3387,    -1,  3389,    -1,  3391,  3392,
      -1,   374,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    2323,  2324,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     393,    -1,    -1,    -1,  2337,   398,  2339,    -1,   401,    -1,
      -1,    -1,    -1,    -1,    -1,  2348,    -1,    -1,    -1,   412,
      -1,    -1,    -1,    -1,    -1,   418,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   428,    -1,    -1,    -1,  3452,
     433,  3454,    -1,   436,    -1,    -1,   439,    -1,    -1,    23,
      -1,    -1,  2385,    -1,    -1,   448,   449,    16,    17,    18,
      19,    20,    21,    22,    38,    -1,    40,    41,    42,    -1,
      -1,    -1,    -1,    -1,  3487,    -1,    -1,    -1,    -1,    -1,
      39,  2414,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    3503,  3504,    -1,    67,  3507,    -1,   489,  3510,    -1,    -1,
     493,   254,    -1,    -1,   257,    -1,    -1,    -1,   501,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   512,
      -1,    -1,    96,    -1,    -1,   518,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    97,    98,
      99,   100,   101,   102,    -1,    -1,    -1,    -1,    -1,   542,
      -1,    -1,    -1,    -1,   113,   114,   115,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   138,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   586,   168,    -1,    -1,   171,    -1,  2532,
     593,    -1,   595,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   605,   606,    -1,    -1,    -1,    -1,    -1,    -1,
     613,    -1,   196,   376,    -1,    -1,     5,    -1,    -1,    -1,
     204,   624,   206,    -1,    -1,    -1,    -1,    -1,    -1,   392,
      -1,   215,    -1,   396,    -1,    -1,    -1,   221,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   229,    -1,    -1,    -1,   233,
      -1,    -1,  2595,    -1,    -1,   239,    -1,    -1,    -1,   243,
     244,   245,   246,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   434,    -1,    -1,   258,    -1,   679,   680,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   254,    -1,    -1,   257,    -1,
      -1,   275,    -1,    -1,   278,    -1,   280,    -1,  2641,   462,
      -1,    -1,    -1,   287,    -1,    -1,    -1,    -1,    -1,  2652,
      -1,    -1,    -1,    -1,    -1,    -1,   300,   480,    -1,    -1,
      -1,    -1,     5,     6,     7,     8,   310,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      -1,    -1,    -1,    -1,    -1,   329,   330,    -1,    -1,    -1,
      -1,    -1,    -1,  2696,    -1,  2698,    39,  2700,    -1,    -1,
     344,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   352,    -1,
    2713,    -1,   356,    -1,    -1,  2718,    -1,    -1,  2721,  2722,
      -1,   365,   366,   367,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   561,    -1,
      -1,    -1,  2745,  2746,    -1,    -1,    -1,   376,    -1,    -1,
      -1,    -1,    -1,    -1,    97,    98,    99,   100,   101,   102,
      -1,    -1,    -1,   392,    -1,    -1,    -1,   396,    -1,    -1,
     113,   114,   115,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  2784,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   435,    20,    -1,    -1,    -1,    24,    25,    26,    27,
      -1,    -1,   446,    -1,   627,   434,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,     6,     7,     8,   265,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      -1,    -1,    -1,   462,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    69,   486,    -1,    -1,    -1,    39,    -1,    -1,    -1,
      -1,   480,     6,     7,     8,   304,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    -1,
      -1,    -1,    -1,    -1,   323,   324,    -1,  2880,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    39,    -1,    -1,    -1,    -1,
    2893,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   547,    97,    98,    99,   100,   101,   102,
      -1,   254,    -1,   362,   257,    -1,    -1,    -1,    -1,    -1,
     113,   114,   115,    -1,    -1,   374,    -1,    -1,  2931,    -1,
      -1,    -1,   561,    -1,    -1,    -1,   385,    -1,  2941,   583,
      -1,    -1,    -1,    97,    98,    99,   100,   101,   102,    -1,
    2953,    -1,    -1,    -1,   403,    -1,    -1,    -1,    -1,   113,
     114,   115,    -1,    -1,   413,    -1,    -1,   195,  2971,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  2980,    -1,    -1,
     429,    -1,    -1,    -1,    -1,   629,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   627,   643,
     644,   645,   646,   647,   648,   649,    -1,   651,   652,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     469,    -1,    -1,    -1,   668,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   376,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   492,    -1,    -1,    -1,    -1,    -1,   392,
      -1,    -1,    -1,   396,    -1,    -1,    -1,    -1,   507,    -1,
      -1,   254,    -1,    -1,   257,   514,    -1,    -1,   517,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   538,
      -1,   434,    -1,   542,    -1,    -1,    -1,    -1,    -1,    -1,
     254,    -1,    -1,   257,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   561,    -1,    -1,    -1,    -1,    -1,    -1,   462,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     579,    -1,  3135,    -1,    -1,    -1,    -1,   480,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     5,     6,
       7,     8,     9,    10,    -1,    12,    13,    14,    -1,    -1,
      -1,    18,    19,    20,    21,    22,    23,    -1,   265,    -1,
      -1,    -1,  3175,   401,    -1,    -1,    33,    -1,    -1,    -1,
      -1,    -1,    -1,   376,    -1,    -1,    -1,    -1,   416,    -1,
      -1,    -1,    49,    -1,    -1,    -1,    -1,    -1,    -1,   392,
      -1,    -1,    -1,   396,   397,   433,    -1,   304,   436,    -1,
      67,    -1,    -1,    -1,    -1,  3218,    -1,    -1,   561,    76,
      -1,   449,   376,    -1,    -1,    -1,   323,   324,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    94,   392,    96,
      -1,   434,   396,   397,    -1,    -1,    -1,   104,    -1,    -1,
      -1,    -1,   109,   110,    -1,  3258,   113,   114,   115,   116,
      -1,   489,   119,   120,    -1,   362,    -1,    -1,    -1,   462,
      -1,    -1,    -1,   501,    -1,    -1,    -1,   374,    -1,    -1,
     434,    -1,    -1,    -1,   627,    -1,  3289,   480,   385,    -1,
      -1,  3294,    -1,  3296,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   159,    -1,    -1,    -1,   403,    -1,   462,    -1,
      -1,    -1,    -1,  3316,   542,    -1,   413,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   182,   480,    -1,    -1,    -1,
    3333,   188,   429,    -1,    -1,    -1,  3339,   194,   195,    -1,
     197,    -1,    -1,    -1,    -1,    -1,   203,    -1,    -1,    -1,
      -1,    -1,    -1,   581,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   593,    -1,    -1,   561,    -1,
      -1,   228,   469,    -1,    -1,    -1,    -1,   605,   606,    -1,
      -1,    -1,    -1,    -1,    -1,   613,    -1,    -1,   616,    -1,
      -1,    -1,    -1,    -1,    -1,   492,   624,    -1,    -1,  3402,
    3403,  3404,  3405,  3406,  3407,    -1,    -1,   561,    -1,   266,
     507,    -1,    -1,    -1,    -1,    -1,    -1,   514,    -1,    -1,
     517,    -1,   279,    -1,    -1,    -1,    -1,    -1,   285,    -1,
      -1,    -1,    -1,    -1,   627,    -1,    -1,   294,   295,    -1,
      -1,   538,    -1,    -1,   301,   542,    -1,   304,   305,    -1,
      -1,    -1,   309,    -1,    -1,    -1,    -1,    -1,   315,   316,
      -1,    -1,    -1,    -1,   561,   322,   323,   324,   325,   326,
     327,    -1,    -1,   627,   331,    -1,    -1,    -1,   335,    -1,
     337,    -1,   579,    -1,    -1,    -1,    -1,   344,   345,   346,
     347,    -1,   349,   350,    -1,    -1,    -1,   354,   355,    -1,
     357,   358,   359,   360,   361,   362,   363,   364,    -1,    -1,
      -1,    -1,    -1,   370,   371,   372,    -1,   374,   375,    -1,
      -1,    -1,   379,   380,   381,   382,   383,   384,   385,   386,
     387,    -1,   389,    -1,  3537,    -1,   393,   394,   395,   396,
     397,   398,   399,   400,   401,   402,   403,   404,   405,   406,
     407,   408,   409,   410,   411,   412,   413,   414,   415,   416,
     417,   418,   419,   420,   421,   422,   423,   424,   425,   426,
     427,   428,   429,   430,    -1,   432,   433,    -1,    -1,   436,
     437,   438,   439,   440,   441,   442,   443,   444,   445,    -1,
     447,   448,   449,   450,   451,   452,   453,   454,   455,   456,
     457,   458,   459,   460,   461,    -1,    -1,   464,   465,   466,
     467,   468,   469,   470,   471,   472,    -1,   474,   475,   476,
     477,    -1,   479,   480,   481,   482,   483,   484,   485,   486,
     487,   488,   489,   490,   491,   492,   493,   494,   495,   496,
     497,   498,   499,   500,   501,   502,   503,   504,   505,   506,
     507,   508,   509,   510,   511,   512,   513,   514,    -1,   516,
     517,   518,   519,   520,   521,    -1,    -1,   524,   525,    -1,
     527,   528,   529,   530,   531,   532,   533,   534,   535,   536,
     537,   538,   539,   540,   541,   542,   543,   544,   545,   546,
     547,   548,   549,   550,   551,   552,    -1,    -1,   555,   556,
     557,   558,   559,   560,   561,   562,   563,   564,   565,   566,
     567,   568,   569,   570,   571,   572,   573,   574,   575,   576,
     577,   578,   579,   580,   581,   582,   583,   584,   585,   586,
     587,   588,   589,   590,   591,   592,   593,   594,   595,   596,
     597,   598,   599,   600,   601,   602,   603,   604,   605,   606,
     607,   608,   609,   610,   611,   612,   613,   614,   615,   616,
      -1,    -1,    -1,    -1,   621,   622,   623,   624,   625,   626,
     627,   628,   629,   630,   631,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   642,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   650,    -1,    -1,    -1,    -1,   655,    -1,
      -1,    -1,   659,    -1,    -1,   662,   663,   664,   665,    -1,
      -1,   668,   669,    -1,   671,   672,   673,     5,     6,     7,
       8,     9,    10,    -1,    12,    13,    14,    -1,    -1,    -1,
      18,    19,    20,    21,    22,    23,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    33,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    49,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    67,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    76,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    94,    -1,    96,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   104,    -1,    -1,    -1,
      -1,   109,   110,    -1,    -1,   113,   114,   115,   116,    -1,
      -1,   119,   120,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   159,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   182,    -1,    -1,    -1,    -1,    -1,
     188,    -1,    -1,    -1,    -1,    -1,    -1,   195,    -1,   197,
      -1,    -1,    -1,    -1,    -1,   203,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     228,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   266,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   279,    -1,    -1,    -1,    -1,    -1,   285,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   294,   295,    -1,    -1,
      -1,    -1,    -1,   301,    -1,    -1,   304,   305,    -1,    -1,
      -1,   309,    -1,    -1,    -1,    -1,    -1,   315,   316,    -1,
      -1,    -1,    -1,    -1,   322,   323,   324,   325,   326,   327,
      -1,    -1,    -1,   331,    -1,    -1,    -1,   335,    -1,   337,
      -1,    -1,    -1,    -1,    -1,    -1,   344,   345,   346,   347,
      -1,   349,   350,    -1,    -1,    -1,   354,   355,    -1,   357,
     358,   359,   360,   361,   362,   363,   364,    -1,    -1,    -1,
      -1,    -1,   370,   371,   372,    -1,   374,   375,    -1,    -1,
      -1,   379,   380,   381,   382,   383,   384,   385,   386,   387,
      -1,   389,    -1,    -1,    -1,   393,   394,   395,   396,   397,
     398,   399,   400,   401,   402,   403,   404,   405,   406,   407,
     408,   409,   410,   411,   412,   413,   414,   415,   416,   417,
     418,   419,   420,   421,   422,   423,   424,   425,   426,   427,
     428,   429,   430,    -1,   432,   433,    -1,    -1,   436,   437,
     438,   439,   440,   441,   442,   443,   444,   445,    -1,   447,
     448,   449,   450,   451,   452,   453,   454,   455,   456,   457,
     458,   459,   460,   461,    -1,    -1,   464,   465,   466,   467,
     468,   469,   470,   471,   472,    -1,   474,   475,   476,   477,
      -1,   479,   480,   481,   482,   483,   484,   485,   486,   487,
     488,   489,   490,   491,   492,   493,   494,   495,   496,   497,
     498,   499,   500,   501,   502,   503,   504,   505,   506,   507,
     508,   509,   510,   511,   512,   513,   514,    -1,   516,   517,
     518,   519,   520,   521,    -1,    -1,   524,   525,    -1,   527,
     528,   529,   530,   531,   532,   533,   534,   535,   536,   537,
     538,   539,   540,   541,   542,   543,   544,   545,   546,   547,
     548,   549,   550,   551,   552,    -1,    -1,   555,   556,   557,
     558,   559,   560,   561,   562,   563,   564,   565,   566,   567,
     568,   569,   570,   571,   572,   573,   574,   575,   576,   577,
     578,   579,   580,   581,   582,   583,   584,   585,   586,   587,
     588,   589,   590,   591,   592,   593,   594,   595,   596,   597,
     598,   599,   600,   601,   602,   603,   604,   605,   606,   607,
     608,   609,   610,   611,   612,   613,   614,   615,   616,    -1,
      -1,    -1,    -1,   621,   622,   623,   624,   625,   626,   627,
     628,   629,   630,   631,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   642,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   650,    -1,    -1,    -1,    -1,   655,    -1,    -1,
      -1,   659,    -1,    -1,   662,   663,   664,   665,    -1,    -1,
     668,   669,    30,   671,   672,   673,    -1,    35,    36,    37,
      -1,    -1,    -1,    -1,    -1,    43,    -1,    -1,    -1,    -1,
      -1,    -1,    50,    51,    52,    -1,    -1,    -1,    -1,    -1,
      -1,    59,    -1,    78,    79,    -1,    81,    82,    83,    -1,
      -1,    -1,    -1,    71,    72,    -1,    74,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      88,    -1,    -1,    -1,    -1,    -1,    -1,    95,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   106,   107,
     108,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   122,    -1,   124,   125,   126,   127,
     128,   129,   130,   131,   132,    -1,   134,   135,   136,   137,
      -1,    -1,    -1,    -1,    -1,   143,    -1,    -1,   146,    -1,
     148,   149,   150,    -1,   152,   153,    -1,    -1,    -1,    -1,
     158,    -1,   160,   161,    -1,   163,   181,   165,   166,    -1,
      -1,   169,   170,    -1,   189,   173,   174,   175,    -1,   177,
     178,    -1,    -1,    -1,   182,   183,   184,    -1,   186,    -1,
      -1,    -1,   190,    -1,   192,   193,    -1,    -1,    -1,    -1,
     198,    -1,    -1,    -1,   202,    -1,    -1,   205,   223,   207,
      -1,   209,    -1,   211,    -1,   213,   214,   232,   216,   217,
     218,    -1,    -1,    -1,   222,    -1,   224,   225,    -1,   227,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   235,   236,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   261,   262,    -1,    -1,
     248,    -1,    -1,   251,   252,    -1,    -1,   255,   256,    -1,
      -1,   259,   260,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     268,   269,   270,    -1,   272,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   282,   283,   284,    -1,   286,    -1,
      -1,   306,   290,   291,    -1,    -1,    -1,   295,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   303,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   311,   312,   313,    -1,    -1,    -1,    -1,
      -1,   319,   320,    -1,    -1,    -1,    -1,   325,    -1,    -1,
     328,    -1,    -1,   348,   332,   333,    -1,    -1,    -1,    -1,
      -1,    -1,     6,     7,     8,   343,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    -1,
      -1,    -1,    -1,   361,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   369,    -1,    -1,    -1,    39,    -1,   375,    -1,    -1,
     133,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   386,   142,
     405,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   151,    -1,
      -1,   399,    -1,   156,    -1,    -1,    -1,    -1,   406,    -1,
     408,   409,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   417,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    97,    98,    99,   100,   101,   102,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   200,    -1,   113,
     114,   115,    -1,    -1,    -1,   208,    -1,    -1,   456,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   467,
      -1,    -1,    -1,    -1,    -1,    -1,   474,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     498,   499,    -1,    -1,    -1,   503,    -1,    -1,    -1,    -1,
      -1,   264,    -1,    -1,    -1,    -1,    -1,   515,    -1,    -1,
      -1,    -1,    -1,   521,   522,   523,   524,    -1,    -1,    -1,
     528,    -1,    -1,    -1,   532,    -1,   289,    -1,    -1,    -1,
      -1,   539,   540,   296,    -1,   298,    -1,    -1,    -1,    -1,
      -1,    -1,   550,    -1,   552,   308,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   563,    -1,   565,    -1,    -1,
     568,    -1,    -1,    -1,    -1,    -1,   574,    -1,    -1,    -1,
      -1,   334,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   342,
     254,    -1,    -1,   257,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   600,    -1,    -1,   603,    -1,    -1,    -1,    -1,
     608,    -1,    -1,   611,   612,    -1,    -1,   632,   633,   634,
     635,   636,   637,   638,   639,   640,   641,   380,   626,    -1,
      -1,    -1,    -1,    -1,    -1,   633,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   406,    -1,    -1,    -1,    -1,   656,   657,
     658,   659,   660,   661,   662,    -1,    -1,   665,    -1,   667,
      -1,   669,     6,     7,     8,    -1,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    -1,
      -1,   444,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   455,    -1,    -1,    39,    -1,    -1,    -1,    -1,
      -1,    -1,   376,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   392,    -1,
      -1,    -1,   396,   397,    -1,    -1,     6,     7,     8,    -1,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    97,    98,    99,   100,   101,   102,    39,
     434,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   113,
     114,   115,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   462,    -1,
     553,   554,   555,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   566,    -1,    -1,   480,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    97,    98,    99,
     100,   101,   102,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   113,   114,   115,     6,     7,     8,    -1,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    39,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   561,    -1,     6,
       7,     8,    -1,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,   669,    -1,    -1,    -1,
     254,    -1,    -1,   257,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    39,    -1,    -1,    -1,    -1,    97,    98,    99,
     100,   101,   102,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   113,   114,   115,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   627,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   254,    -1,    -1,   257,    -1,    -1,
      97,    98,    99,   100,   101,   102,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   113,   114,   115,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,     6,     7,     8,    -1,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   376,    -1,    -1,    -1,    -1,    -1,    -1,    39,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   392,    -1,
      -1,    -1,   396,   397,    -1,     6,     7,     8,    -1,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   254,    -1,    -1,   257,    39,    -1,
     434,    -1,    -1,    -1,    -1,    -1,   376,    97,    98,    99,
     100,   101,   102,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   392,   113,   114,   115,   396,   397,   462,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   480,   254,    -1,    -1,
     257,    -1,    -1,    -1,    -1,    -1,    97,    98,    99,   100,
     101,   102,    -1,    -1,   434,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   113,   114,   115,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   462,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     480,    -1,    -1,    -1,    -1,    -1,   376,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   561,    -1,    -1,
      -1,    -1,   392,    -1,    -1,    -1,   396,   397,     6,     7,
       8,    -1,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   254,    -1,    -1,   257,    -1,   376,
      -1,    39,    -1,    -1,   434,    18,    19,    20,    -1,    -1,
      -1,    24,    25,    26,    27,   392,    -1,    -1,    -1,   396,
     397,   561,    -1,   627,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   462,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   254,    -1,    -1,   257,    -1,    -1,    -1,
     480,    -1,    -1,    -1,    -1,    -1,    69,   434,    -1,    97,
      98,    99,   100,   101,   102,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   113,   114,   115,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   462,     8,   627,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    -1,    -1,   480,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   376,    39,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   561,   392,    -1,    -1,    -1,   396,   397,     6,     7,
       8,    -1,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   376,    -1,    -1,    -1,    -1,
      -1,    39,    -1,    -1,   434,    97,    98,    99,   100,   101,
     102,   392,   195,    -1,   561,   396,    -1,    -1,    -1,    -1,
      -1,   113,   114,   115,    -1,    -1,    -1,   627,    -1,    -1,
      -1,    -1,   462,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   254,    -1,    -1,   257,
     480,    -1,    -1,   434,    -1,    -1,    -1,    -1,    -1,    97,
      98,    99,   100,   101,   102,    -1,   447,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   113,   114,   115,    -1,    -1,
     627,   462,     6,     7,     8,    -1,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,   480,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    39,    -1,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      -1,   561,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    39,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   254,    -1,    -1,   257,    -1,    -1,   376,    -1,
      -1,    -1,    -1,    97,    98,    99,   100,   101,   102,    -1,
     561,    -1,    -1,    -1,   392,    -1,    -1,    -1,   396,   113,
     114,   115,    -1,    -1,    -1,    -1,    -1,   627,    -1,    -1,
      -1,    -1,    -1,    -1,    97,    98,    99,   100,   101,   102,
      -1,    -1,    -1,    -1,    -1,    -1,   254,    -1,   401,   257,
     113,   114,   115,    -1,    -1,    -1,   434,    -1,    -1,    -1,
      -1,    -1,    -1,   416,    -1,    -1,    -1,    -1,    -1,   447,
      -1,    -1,    -1,    -1,    -1,    -1,   627,    -1,    -1,    -1,
     433,    -1,    -1,   436,   462,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   449,    -1,    -1,    -1,
      -1,    -1,   480,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   376,    -1,    -1,    -1,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
     392,    -1,    -1,    -1,   396,   488,   489,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    39,    -1,   501,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     254,    -1,    -1,   257,    -1,    -1,    -1,    -1,   376,    -1,
      -1,    -1,   434,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   561,   392,    -1,    -1,    -1,   396,   542,
      -1,   254,    -1,    -1,   257,    -1,    -1,    -1,    -1,    -1,
     462,    -1,    -1,    -1,    97,    98,    99,   100,   101,   102,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   480,    -1,
     113,   114,   115,    -1,    -1,    -1,   434,    -1,   581,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   447,
     593,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   627,
      -1,    -1,   605,   606,   462,    -1,    -1,    -1,    -1,    -1,
     613,    -1,    -1,   616,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   624,   480,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   376,    -1,    -1,    -1,    -1,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,   392,   561,
      -1,    -1,   396,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   376,    39,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   392,
      -1,    -1,    -1,   396,    -1,    -1,    -1,    -1,    -1,    -1,
     434,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    -1,    -1,   561,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   254,    -1,    -1,   257,   627,    -1,    39,   462,    -1,
      -1,   434,    97,    98,    99,   100,   101,   102,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   480,    -1,   113,   114,
     115,    -1,    -1,    -1,    18,    19,    20,    -1,    -1,   462,
      24,    25,    26,    27,    -1,    -1,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    -1,    -1,   480,    -1,   627,
      -1,    -1,    -1,    -1,    -1,    97,    98,    99,   100,   101,
     102,    39,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   113,   114,   115,    -1,    69,    -1,    -1,    -1,    -1,
      -1,    -1,    15,    16,    17,    18,    19,    20,    21,    22,
      -1,    -1,    -1,    -1,    18,    19,    20,   561,    -1,    -1,
      24,    25,    26,    27,    -1,    -1,    39,    -1,    -1,    -1,
      -1,    -1,    -1,   376,    -1,    -1,    -1,    -1,    -1,    97,
      98,    99,   100,   101,   102,    -1,    -1,    -1,   561,   392,
      -1,    -1,    -1,   396,    -1,   113,   114,   115,    -1,    17,
      18,    19,    20,    21,    22,    69,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   254,
      -1,    39,   257,   627,    97,    98,    99,   100,   101,   102,
      -1,   434,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     113,   114,   115,    -1,   447,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   627,    -1,    -1,    -1,    -1,   462,
      -1,   195,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   254,    -1,    -1,   257,    -1,   480,    -1,    97,
      98,    99,   100,   101,   102,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    18,    19,   113,   114,   115,    -1,    24,
      25,    26,    27,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      22,    -1,    -1,    -1,    -1,    18,    19,    -1,    -1,    -1,
      -1,    24,    25,    26,    27,    -1,    -1,    39,    -1,    -1,
      -1,   195,    -1,    -1,    -1,    -1,   254,    -1,    -1,   257,
      -1,   376,    -1,    -1,    69,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   392,   561,    -1,
      -1,   396,    -1,    -1,    -1,    -1,    69,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   254,    -1,    -1,   257,    97,    98,    99,   100,   101,
     102,    -1,    -1,    -1,   376,    -1,    -1,    -1,    -1,   434,
      -1,   113,   114,   115,    -1,    -1,    -1,    -1,    -1,    -1,
     392,    -1,    -1,    -1,   396,    -1,    -1,    -1,    -1,    24,
      25,    26,    27,    -1,   627,    -1,    -1,   462,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   254,    -1,    -1,   257,
      -1,    -1,    -1,    -1,    -1,   480,    -1,    -1,    32,    -1,
      34,    -1,   434,    -1,    -1,    -1,    -1,    -1,   376,    -1,
      -1,    -1,    -1,    -1,    69,    -1,    -1,   401,    -1,    -1,
     195,    -1,    -1,    -1,   392,    -1,    -1,    -1,   396,    -1,
     462,    -1,   416,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   195,    -1,    -1,    -1,    -1,    -1,   480,   433,
      84,    85,   436,   376,    -1,    -1,    -1,    -1,    -1,    -1,
      94,    -1,    -1,    -1,    -1,   449,   434,    -1,    -1,   392,
      -1,    -1,    -1,   396,    -1,    -1,   561,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   401,    -1,    -1,
      -1,    -1,   254,    -1,   462,   257,    -1,    -1,    -1,    -1,
      -1,    -1,   416,    -1,   488,   489,    -1,    -1,   376,    -1,
      -1,   434,   480,    -1,    -1,    -1,    -1,   501,    -1,   433,
      -1,    -1,   436,    -1,   392,    -1,    -1,    -1,   396,   561,
      -1,    -1,    -1,    -1,    -1,   449,    -1,    -1,    -1,   462,
     195,    -1,   627,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   480,   542,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   434,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   489,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   501,    -1,    -1,
      -1,    -1,    -1,   561,   462,   627,    -1,   581,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   593,
      -1,    -1,   480,    -1,   376,    -1,    -1,    -1,    -1,    -1,
      -1,   605,   606,    -1,    -1,    -1,   401,    -1,   542,   613,
     392,   265,   616,    -1,   396,    -1,    -1,    -1,   561,    -1,
     624,   416,    -1,    -1,    -1,    -1,    -1,    -1,   401,    44,
      45,    46,    47,    48,    49,    -1,    -1,    -1,   433,   627,
      -1,   436,    -1,   416,    -1,    -1,    -1,   581,    -1,    -1,
     304,    -1,   434,    -1,   449,    -1,    -1,    -1,    -1,   593,
     433,    -1,    -1,   436,    -1,    -1,    -1,    -1,    -1,   323,
     324,   605,   606,   561,    -1,    -1,   449,    -1,    -1,   613,
     462,   476,   616,    -1,   627,   339,    -1,    -1,   103,    -1,
     624,    -1,    -1,    -1,   489,    -1,    -1,    -1,   480,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   501,    -1,   362,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   489,    -1,    -1,    -1,
     374,    -1,    -1,    -1,    -1,    -1,   401,    -1,   501,    -1,
      -1,   385,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   627,
      -1,   416,    -1,    -1,    -1,    -1,    -1,   542,    -1,   403,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   433,   413,
      -1,   436,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   542,
      -1,    -1,    -1,    -1,   449,   429,    -1,    -1,    -1,   561,
      -1,    -1,    -1,    -1,    -1,    -1,   581,    -1,    -1,    -1,
      -1,    -1,    -1,   208,    -1,    -1,    -1,    -1,   593,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   581,    -1,
     605,   606,    -1,    -1,   489,   469,    -1,    -1,   613,    -1,
     593,   616,    -1,    -1,    -1,    -1,   501,    -1,    -1,   624,
      -1,    -1,   605,   606,    -1,    -1,    -1,    -1,   492,    -1,
     613,    -1,    -1,   616,    -1,   627,    -1,    -1,    -1,   264,
      -1,   624,    -1,   507,    -1,    -1,    -1,    -1,    -1,    -1,
     514,    -1,    -1,   517,    -1,    -1,    -1,   542,    -1,    -1,
      -1,    -1,    -1,    -1,   289,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   298,   538,    -1,    -1,    -1,   542,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   581,   561,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   593,   334,
      -1,    -1,   337,    -1,    -1,   579,    -1,   342,    -1,    -1,
     605,   606,    -1,    -1,    -1,   350,    -1,    -1,   613,    -1,
      -1,   616,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   624,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   621,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     415,    -1,    -1,    -1,    -1,    -1,    -1,   422,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   437,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   461,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     485,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     495,   496,    -1,    -1,    -1,    -1,   501,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   511,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   533,    -1,
      -1,   536,   537,    -1,    -1,    -1,   541,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   598,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   607,    -1,   609
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const unsigned short yystos[] =
{
       0,    30,    51,    52,    80,   127,   128,   130,   131,   135,
     152,   153,   170,   241,   361,   411,   443,   472,   739,   767,
     768,   820,   991,  1044,  1046,  1047,  1048,  1053,  1055,  1068,
    1069,  1070,  1071,  1072,  1494,    28,    29,   740,   741,   742,
     743,   744,    27,   956,  1513,   360,   539,   552,   577,   625,
    1495,  1495,  1495,  1495,  1495,  1495,  1495,  1495,   956,    25,
     956,  1409,  1073,   769,  1409,   768,  1494,     0,  1045,  1048,
    1053,  1071,  1494,    31,   742,   744,   956,  1497,   594,   956,
    1496,   630,   821,   616,    25,   195,   766,   767,   944,   956,
     961,  1074,  1109,  1110,  1111,  1112,  1113,  1117,   358,   771,
     772,   773,   774,   777,   778,    60,    65,   110,   111,   118,
     372,   399,   470,   562,   642,   650,   739,   745,   916,   990,
    1049,  1050,  1052,  1056,  1057,  1063,  1075,  1096,  1229,  1239,
    1494,   956,  1496,   621,   956,  1112,   247,   463,   464,  1119,
      20,   956,  1116,   624,   772,     5,   770,   358,   956,     5,
     796,   798,   799,   956,  1240,   956,   956,  1230,  1064,   956,
     956,  1052,  1058,   265,   304,   323,   324,   362,   374,   385,
     403,   413,   429,   469,   492,   507,   514,   517,   538,   542,
     561,   579,   822,   823,   824,   827,    25,  1109,  1115,    18,
      19,    26,    64,    76,   104,   197,   294,   327,   362,   374,
     412,   428,   436,   449,   493,   518,   542,   586,   595,   679,
     680,   689,   691,   882,   887,   898,   900,   956,  1109,  1120,
    1121,   464,    14,   819,   774,   527,  1216,   775,   772,   777,
      32,    34,    84,    85,    94,   265,   304,   323,   324,   339,
     362,   374,   385,   403,   413,   429,   469,   492,   507,   514,
     517,   538,   542,   561,   579,   621,   781,   790,   801,   802,
     956,   436,   117,   956,   766,   917,  1097,   956,   829,   324,
     779,   436,   805,   807,   808,   806,   815,   816,   436,   436,
     828,   464,   436,   772,   803,   431,   436,   436,   436,   436,
     436,   436,   436,   436,   436,   436,   689,   436,   763,     9,
      18,    19,    24,    25,    26,    69,   299,   393,   398,   401,
     418,   433,   436,   439,   448,   489,   501,   512,   542,   593,
     605,   606,   613,   624,   856,   864,   865,   866,   867,   868,
     869,   870,   898,   899,   901,   962,  1109,  1219,  1401,   436,
     436,   436,   436,   436,   436,    18,    19,    20,    21,    22,
     690,    26,   436,   526,     5,   432,  1120,    25,    26,   956,
     962,    19,    25,    26,   776,   962,   674,   675,   676,   780,
     792,   779,   436,   793,   805,   806,   436,   436,   791,   464,
     436,   803,   772,   800,   436,    26,   956,   436,  1065,   766,
     766,   436,   956,   436,   463,   785,    26,   630,   371,   459,
     475,   518,   557,   586,   595,   809,   630,   371,   459,   475,
     518,   557,   586,   595,   817,    26,    26,   830,   831,   832,
     833,   956,    26,   788,   789,    26,   624,   671,   948,   956,
    1504,   948,   948,  1504,  1504,   856,    25,    26,    19,    24,
      25,    26,   902,   903,   904,   905,  1504,   856,   397,   856,
     856,   856,   856,   531,  1236,   436,   436,   856,   371,   459,
     475,   518,   557,   586,   595,  1404,  1405,   436,   856,   856,
     436,   436,   871,   436,   436,   436,   436,    26,     6,     7,
       8,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    39,    97,    98,    99,   100,   101,
     102,   113,   114,   115,   254,   257,   376,   392,   396,   434,
     462,   480,   561,   627,   762,   857,   872,   874,   875,   876,
     877,   878,   879,   880,    26,   962,   426,   890,   888,   894,
     892,  1109,  1109,   689,   883,   956,  1121,   464,   432,    26,
     783,   772,   785,    26,   772,    26,    26,   771,   788,    26,
     624,    63,   797,  1241,   397,   436,  1231,  1514,  1515,  1516,
    1517,  1518,   918,  1098,  1059,   624,    26,   397,   810,   811,
     436,   812,   817,   818,   812,   436,   813,     5,   397,     5,
     397,     5,   288,     5,   822,   432,     5,     5,   397,   772,
     804,   436,   464,   624,     5,   397,   397,   397,   397,   397,
     397,   397,   397,   594,   903,    19,    26,   594,   397,   397,
     397,     5,   764,   856,   476,  1425,   856,   436,   630,    20,
     397,  1425,    20,  1219,   856,   856,   856,   856,   856,   856,
     856,   856,   856,   856,   856,   856,   856,   856,   856,   856,
     856,   856,   856,   856,   856,   856,   856,   436,   856,   856,
     436,  1109,   856,   856,   856,   856,   397,     5,   719,   720,
     721,   856,   436,  1120,   464,   628,   624,    26,   397,   263,
       5,   397,     5,   397,   288,   432,     5,   397,   804,   956,
    1126,  1127,  1129,  1076,  1126,   366,  1515,  1216,    35,    36,
      37,    43,    50,    59,    71,    72,    74,    88,    95,   106,
     107,   108,   122,   124,   125,   126,   129,   132,   134,   136,
     137,   143,   146,   148,   149,   150,   158,   160,   161,   163,
     165,   166,   169,   173,   174,   175,   177,   178,   182,   183,
     184,   186,   190,   192,   193,   198,   202,   205,   207,   209,
     211,   213,   214,   216,   217,   218,   222,   224,   225,   227,
     235,   236,   248,   251,   252,   255,   256,   259,   260,   268,
     269,   270,   272,   282,   283,   284,   286,   290,   291,   295,
     303,   311,   312,   313,   319,   320,   325,   328,   332,   333,
     343,   361,   369,   375,   386,   406,   408,   409,   417,   456,
     467,   474,   498,   499,   503,   515,   521,   522,   523,   524,
     528,   532,   539,   540,   550,   552,   563,   565,   568,   574,
     600,   603,   608,   611,   612,   626,   633,   656,   657,   658,
     659,   660,   661,   662,   665,   667,   669,   682,   683,   684,
     685,   702,   724,   738,   739,   745,   746,   765,   835,   836,
     837,   838,   849,   850,   851,   852,   853,   854,   855,   907,
     911,   942,   963,   964,   967,   968,   969,   970,   983,   992,
    1013,  1014,  1016,  1020,  1035,  1036,  1040,  1041,  1042,  1043,
    1051,  1066,  1079,  1090,  1091,  1092,  1103,  1106,  1142,  1145,
    1147,  1153,  1154,  1157,  1160,  1163,  1165,  1167,  1170,  1177,
    1182,  1186,  1187,  1188,  1200,  1201,  1204,  1210,  1211,  1212,
    1237,  1252,  1253,  1254,  1255,  1256,  1261,  1267,  1268,  1286,
    1289,  1319,  1321,  1410,  1411,  1442,  1443,  1450,  1461,  1485,
    1494,  1498,  1503,  1505,  1507,  1511,  1512,  1519,   739,  1054,
    1494,   629,   652,  1099,  1100,  1126,    20,   397,   431,   786,
     809,    26,   814,    26,    26,    26,   831,   833,   825,   789,
      26,   956,   689,    20,   671,   956,   948,   896,  1405,   896,
      26,    26,   594,    24,    26,   806,   897,   807,   397,   364,
     481,   590,  1433,   397,   397,    26,  1405,   397,   397,   397,
     397,   397,   397,   397,   447,   447,   447,   881,  1425,   447,
     881,  1425,   891,   889,   895,   893,    26,   884,     5,   885,
     432,  1120,   796,    20,   786,   436,    26,    26,   782,    26,
     624,   397,     5,  1126,   397,  1109,  1109,  1109,    25,  1109,
    1164,   956,   354,   957,   958,  1513,   956,   956,  1184,   951,
     957,   951,    25,   195,   956,  1118,  1489,  1490,  1491,   956,
    1509,   956,  1263,  1264,   956,    26,   686,  1109,  1259,   951,
    1184,   881,    26,   962,  1224,  1225,  1224,   856,   863,  1288,
     858,   881,   957,  1451,  1451,   839,  1184,   951,  1257,  1109,
     953,   957,   863,  1451,  1109,  1184,  1109,  1287,  1451,    25,
     590,  1093,  1094,  1109,   951,   951,  1093,   952,   957,   956,
    1094,   951,  1451,   951,   953,  1109,  1140,  1141,   949,   957,
     953,   380,   566,   948,  1015,   956,   747,   954,   957,    25,
    1320,  1489,   881,  1140,   881,   957,  1166,   912,   133,   142,
     151,   156,   200,   208,   264,   289,   296,   298,   308,   334,
     342,   380,   406,   444,   455,   553,   554,   555,   566,   669,
    1029,  1161,  1162,  1109,   862,   863,  1176,  1504,  1504,   950,
     957,   881,  1164,  1238,  1109,  1215,    25,  1109,  1445,   863,
    1206,  1207,  1208,  1217,  1218,   863,  1499,   109,   159,   197,
     294,   370,   412,   479,   703,   887,   956,  1109,  1247,   726,
     863,   949,  1496,  1080,   863,   949,    26,  1109,  1037,   949,
     863,  1462,   863,  1224,   956,   965,   966,   953,   965,  1504,
     953,   965,  1504,   971,   965,    25,    26,   390,   492,   962,
    1018,  1109,  1128,  1130,    70,   279,   349,   395,   573,   653,
     654,   655,   664,   693,   973,   975,   977,   979,   981,  1104,
    1105,  1108,   340,   351,   404,   419,   508,  1322,   644,   645,
     920,   921,   922,   956,  1101,   651,  1100,   397,   307,   397,
     397,   397,   397,   628,     5,   397,   397,   432,   436,   630,
     397,    26,   594,   630,    18,    19,    20,    25,    26,    69,
     401,   416,   433,   436,   449,   489,   501,   542,   581,   593,
     605,   606,   613,   616,   956,   962,  1400,  1402,  1432,  1434,
    1435,  1437,  1438,  1439,  1490,  1493,  1236,   397,  1236,  1236,
    1236,  1236,  1236,  1236,    25,    25,    25,   856,   873,   397,
      25,   873,   397,   397,   397,   397,   397,   397,   397,   721,
     719,   432,   307,   772,   794,   795,   397,   397,   628,   397,
     956,  1242,  1129,   397,  1232,    61,    62,    89,    90,    91,
     460,   546,   589,  1269,  1270,  1271,  1274,  1277,  1280,  1281,
    1282,  1283,   436,   624,  1491,  1119,   621,  1158,   624,     8,
     543,   592,     5,   397,   432,    25,   956,  1394,   484,  1185,
    1128,   113,   114,   115,   488,   859,   860,   863,  1109,  1135,
    1394,   692,   693,   842,   271,    92,    93,   630,   465,     5,
     623,   630,   622,   622,  1143,   600,   426,     5,   561,   993,
     465,   663,  1501,   663,   390,   749,  1109,   551,   622,  1148,
    1149,  1150,   331,  1318,   616,   861,   863,   561,   861,     8,
     950,    26,   506,   559,   673,   943,  1109,   943,   943,   943,
      25,   182,   309,   315,   316,   317,   335,   444,   447,   455,
     490,   525,   544,   545,   555,   560,   599,   631,  1033,  1034,
     943,   943,   601,  1030,   693,  1030,  1030,   944,   944,  1030,
    1030,   693,     5,   338,   391,     5,   692,    86,    87,   544,
     631,  1021,   666,  1502,   862,   617,   618,   619,   620,  1214,
    1216,   389,  1251,  1216,  1208,     5,   622,  1209,   863,   436,
     436,   436,   436,    25,   722,   956,   436,  1445,   349,   436,
     526,   594,   583,   727,   734,   725,    25,  1095,  1109,  1202,
       8,  1205,    14,   956,  1114,  1122,  1123,  1125,  1133,  1134,
    1178,   167,   349,   549,   582,     5,     6,     7,     8,     9,
      10,    12,    13,    14,    18,    19,    20,    21,    22,    23,
      33,    49,    67,    76,    94,    96,   104,   109,   110,   113,
     114,   115,   116,   119,   120,   159,   182,   188,   195,   197,
     203,   228,   266,   279,   285,   294,   295,   301,   304,   305,
     309,   315,   316,   322,   323,   324,   325,   326,   327,   331,
     335,   337,   344,   345,   346,   347,   349,   350,   354,   355,
     357,   358,   359,   360,   361,   362,   363,   364,   370,   371,
     372,   374,   375,   379,   380,   381,   382,   383,   384,   385,
     386,   387,   389,   393,   394,   395,   396,   397,   398,   399,
     400,   401,   402,   403,   404,   405,   406,   407,   408,   409,
     410,   411,   412,   413,   414,   415,   416,   417,   418,   419,
     420,   421,   422,   423,   424,   425,   426,   427,   428,   429,
     430,   432,   433,   436,   437,   438,   439,   440,   441,   442,
     443,   444,   445,   447,   448,   449,   450,   451,   452,   453,
     454,   455,   456,   457,   458,   459,   460,   461,   464,   465,
     466,   467,   468,   469,   470,   471,   472,   474,   475,   476,
     477,   479,   480,   481,   482,   483,   484,   485,   486,   487,
     488,   489,   490,   491,   492,   493,   494,   495,   496,   497,
     498,   499,   500,   501,   502,   503,   504,   505,   506,   507,
     508,   509,   510,   511,   512,   513,   514,   516,   517,   518,
     519,   520,   521,   524,   525,   527,   528,   529,   530,   531,
     532,   533,   534,   535,   536,   537,   538,   539,   540,   541,
     542,   543,   544,   545,   546,   547,   548,   549,   550,   551,
     552,   555,   556,   557,   558,   559,   560,   561,   562,   563,
     564,   565,   566,   567,   568,   569,   570,   571,   572,   573,
     574,   575,   576,   577,   578,   579,   580,   581,   582,   583,
     584,   585,   586,   587,   588,   589,   590,   591,   592,   593,
     594,   595,   596,   597,   598,   599,   600,   601,   602,   603,
     604,   605,   606,   607,   608,   609,   610,   611,   612,   613,
     614,   615,   616,   621,   622,   623,   624,   625,   626,   627,
     628,   629,   630,   631,   642,   650,   655,   659,   662,   663,
     664,   665,   668,   669,   671,   672,   673,  1463,  1464,  1465,
    1467,   580,     5,   663,   663,   861,  1128,  1135,  1017,   426,
       5,   155,   997,   436,  1109,   861,   436,    26,    26,    70,
    1107,    25,  1109,  1449,  1449,   957,  1302,  1166,   950,   123,
     226,   234,   240,   242,   253,   281,   297,   302,   314,   321,
     476,   483,   505,   510,  1290,  1291,  1299,  1309,  1310,  1316,
    1317,  1323,  1324,  1333,  1352,  1356,  1421,  1422,  1452,  1453,
    1456,  1457,  1469,   923,   924,    96,   919,   930,   931,   922,
    1102,  1514,  1060,   464,   822,   789,   624,   956,   371,   459,
     475,   518,   557,   586,   595,  1406,   896,   594,    24,    26,
     810,  1438,  1438,   371,   459,   475,   518,   557,   586,   595,
    1403,  1407,   476,  1437,   436,   436,   436,   436,   436,   436,
     436,   956,   436,     5,   551,  1361,  1366,   956,    18,    19,
      20,    21,    97,    98,    99,   100,   101,   102,  1459,   426,
       5,   397,   397,   886,   464,     5,   397,   796,   766,  1077,
     766,   162,   301,   378,   436,   481,   497,  1339,  1351,   436,
     956,  1285,    26,   250,   263,   436,   481,   497,   956,  1266,
    1279,  1337,  1338,  1343,  1345,  1347,   436,   956,  1276,   436,
    1266,  1272,     5,    25,   959,  1112,  1491,  1489,   581,   621,
    1159,    20,   956,  1139,  1492,   956,  1510,  1264,   600,   624,
     594,   436,   436,   842,     5,   630,   436,  1489,    25,   961,
    1183,  1183,  1445,  1093,   863,   863,   863,   945,   946,   436,
    1109,  1141,   803,   994,   995,   630,  1445,  1504,  1502,  1015,
    1109,   748,   629,   863,   355,  1152,   561,  1151,   956,     5,
    1486,    73,    75,    77,   622,   630,   834,  1128,   913,    18,
      19,   436,  1031,  1033,  1162,   944,   863,   349,   600,    26,
      26,   692,   157,  1213,   223,  1218,  1224,  1500,   956,    25,
     906,   948,  1504,   594,   948,   627,  1109,   707,   956,   956,
     863,   344,   730,   734,   583,   728,   736,    23,   239,  1082,
    1086,   487,   881,   487,  1203,   863,   463,  1119,   624,     5,
    1038,   551,  1179,  1109,  1466,  1468,   194,  1464,   984,   966,
    1504,  1504,   976,   977,   997,   997,    38,    40,    41,    42,
     275,   278,   280,   300,   310,   329,   352,   356,   435,   996,
     998,   999,  1025,  1109,  1130,   551,   694,    26,   405,   982,
     326,  1444,  1444,   140,   141,   442,   551,   956,  1353,  1354,
    1395,   803,  1394,  1394,  1292,   803,   956,  1454,  1454,  1433,
    1394,  1300,   172,   444,   455,   476,   483,  1326,  1327,  1328,
    1514,  1514,   390,   932,  1109,   646,   647,   925,   926,   927,
     486,   629,   648,   649,   668,   935,   936,  1514,   766,    26,
     787,    20,   956,   397,   436,    24,    26,   630,  1433,   397,
     401,  1460,  1493,   364,   481,   590,  1385,  1437,  1440,  1385,
    1385,  1385,  1385,   624,  1440,  1435,   520,  1362,  1363,  1364,
    1394,   531,  1360,  1367,   336,   519,   530,  1311,  1428,  1437,
    1437,  1437,  1437,  1490,   856,   397,   787,   795,  1243,   766,
    1233,  1341,  1394,  1284,  1351,   436,  1284,   436,   436,  1278,
    1279,   436,   436,    68,   304,   324,   362,   374,   385,   403,
     413,   416,   429,   477,   507,   517,   538,   542,   570,   579,
    1386,  1387,  1388,  1390,  1275,  1276,  1272,  1273,   668,  1270,
     397,   624,  1445,   581,   464,   551,  1508,   687,   688,   956,
     956,   956,  1260,   881,   859,   956,  1258,   621,  1155,   630,
       5,     5,     5,   584,   863,   624,     5,   488,   630,   629,
     168,   171,   275,   278,   750,   753,   754,  1025,   751,   752,
     956,   436,   957,   653,   654,  1156,   863,   803,  1487,  1488,
     956,   956,   946,   947,   514,  1504,   842,     8,   915,    26,
      26,  1032,  1033,  1109,   324,  1171,    70,   856,  1216,    26,
    1109,  1514,     5,     5,     5,   397,   397,   723,   956,   397,
    1445,   719,   436,   436,   735,   731,   365,   729,   863,   344,
     732,   736,   601,  1027,  1087,  1083,   367,  1081,  1082,   861,
     630,  1115,    20,   956,  1124,  1134,    14,   488,  1180,  1181,
    1437,  1493,  1109,  1131,  1132,  1514,   978,   979,   555,   955,
     551,  1008,  1007,  1010,  1009,   948,  1011,   948,  1012,  1006,
    1005,  1003,  1002,  1026,   329,   999,  1004,  1504,    44,    45,
      46,    47,    48,    49,   103,   337,   350,   415,   422,   461,
     485,   495,   496,   501,   511,   533,   536,   537,   541,   598,
     609,   695,   696,  1023,  1024,     5,    26,  1445,   253,  1109,
     476,  1426,  1427,  1445,  1166,  1420,  1422,   105,   105,   600,
    1164,  1355,  1356,   436,  1334,   154,  1367,  1394,   179,   276,
    1458,   624,   630,  1423,  1470,   346,   355,   380,   383,   401,
     506,   559,   566,   950,  1303,  1308,   436,  1329,   629,     5,
     934,  1109,     5,   551,   928,   929,   643,   927,   933,   956,
     933,   937,   938,   933,   329,   936,  1061,   432,    26,   371,
     459,   475,   518,   557,   586,   595,  1408,  1434,     5,  1407,
     397,     5,  1437,     5,   397,  1437,  1437,  1437,  1437,   956,
     397,   436,  1364,     5,   956,  1399,     9,   299,   436,   448,
    1370,  1371,  1372,  1373,  1374,  1378,  1382,  1384,  1437,   373,
    1358,  1368,   956,  1429,   623,  1385,   336,   432,   466,  1226,
    1246,  1078,   466,  1189,  1220,   436,     5,   397,  1370,   397,
     616,   956,  1340,  1342,  1394,  1397,  1398,  1344,  1397,     5,
     397,  1344,  1370,   436,  1407,  1407,   436,   436,   436,   436,
     436,   212,   405,  1346,  1348,     5,   397,     5,   397,   956,
    1492,     8,  1445,  1120,   863,     5,  1265,  1266,   881,  1067,
     624,  1265,   581,  1445,  1445,   863,   863,   945,   514,   863,
    1506,     5,    20,  1397,   995,  1445,   751,   759,   758,   760,
     956,   960,   761,   960,   196,   754,   757,     5,   997,   624,
     863,     8,   624,     5,   956,   881,   558,  1306,     5,   397,
    1109,     5,   330,    25,  1248,   948,   349,   349,   464,   624,
     349,   436,   708,   712,   705,  1514,  1514,   737,   733,   729,
    1028,    25,   955,  1088,  1109,  1514,   863,   431,   464,   881,
       5,   426,     5,   985,   980,   981,    26,   692,   956,  1514,
    1514,  1514,  1514,     5,  1000,     5,  1001,  1514,  1514,  1514,
    1514,  1031,  1514,   955,    25,    14,    14,     5,   397,    26,
    1394,  1433,  1414,   600,   600,  1291,  1419,  1420,  1356,  1335,
    1397,   621,   950,   436,  1295,   956,  1455,  1454,  1434,    53,
      54,    55,    56,    57,   588,  1473,   863,   863,  1301,   950,
    1330,  1397,  1394,  1328,     5,  1109,   933,  1514,  1514,     5,
     940,   941,  1514,  1514,   939,  1054,   826,   397,   436,  1366,
    1407,   630,  1407,   397,  1437,   397,   397,   397,   397,  1363,
    1365,  1363,  1373,   436,  1432,  1370,  1437,  1432,     6,     7,
       9,    10,    12,    13,    14,    15,    16,    17,   257,   376,
     377,   434,   561,   627,   677,   678,  1381,  1383,  1359,  1436,
    1437,   453,  1357,  1369,   273,  1262,    26,  1312,  1313,  1314,
    1397,  1426,  1429,   784,    78,    79,    81,    82,    83,   181,
     189,   223,   232,   261,   262,   306,   348,   405,   632,   633,
     634,   635,   636,   637,   638,   639,   640,   641,  1223,  1227,
     139,   519,  1228,  1244,  1054,   164,   180,   181,   189,   223,
     232,   261,   306,   348,  1221,  1222,  1234,  1228,  1342,  1351,
     397,  1398,   464,  1396,   397,     5,   624,     5,   397,  1279,
     397,   397,    26,  1391,   630,   436,   630,    26,  1392,  1392,
      26,  1392,  1392,    25,  1400,  1349,  1350,  1351,  1276,  1272,
    1445,     8,   432,   688,     5,   397,   861,   397,    20,   397,
    1445,     5,   863,   571,   279,   697,   698,   863,   997,  1514,
    1514,     5,   755,   464,   624,     5,   756,  1514,   752,   551,
      20,   956,     5,   956,  1146,    20,  1397,  1488,   395,   663,
     861,  1307,   914,  1033,   672,  1169,   856,     5,   719,  1109,
     704,   686,   956,  1109,   710,   397,   719,   719,  1514,  1514,
    1031,  1085,    25,  1089,  1109,   576,   910,  1120,   488,   862,
    1039,  1181,  1109,  1132,    67,   547,   986,   972,   973,   624,
     948,  1514,   948,  1514,   692,    26,  1109,    26,  1109,   696,
     397,   436,  1446,  1434,  1420,  1420,  1412,     5,   397,   476,
    1431,  1296,  1397,   484,  1293,  1431,   630,  1424,    18,    19,
      69,   433,   436,   449,   488,   489,   501,   542,   581,   593,
     605,   606,   613,   616,   956,  1400,  1432,  1478,  1479,  1480,
    1481,  1482,  1483,  1493,  1478,  1478,  1478,  1397,  1475,  1477,
    1474,  1475,  1476,  1471,   558,  1304,     5,   397,   630,  1109,
     956,  1514,  1514,  1514,  1514,   628,    26,   397,   630,  1408,
     630,     5,   397,   397,  1371,  1372,  1376,  1438,  1376,   436,
    1432,  1376,   436,  1432,  1376,    10,   254,   392,   394,  1437,
       5,  1370,     5,   543,   592,  1315,  1262,   628,  1224,  1224,
    1224,    25,  1224,  1224,  1224,  1224,  1224,  1224,    25,    25,
    1224,  1227,  1109,  1136,  1137,   623,   452,  1190,  1514,    25,
      25,    26,    26,    26,    26,    26,    25,  1109,  1222,  1190,
     397,    26,  1339,  1397,    20,   956,  1397,   397,  1408,    26,
    1408,     5,  1389,  1389,     5,   397,   397,  1389,  1351,  1445,
    1266,  1262,   473,   841,     5,   379,  1445,     5,   436,   397,
     555,  1022,   960,  1514,   689,    20,   956,   960,  1514,  1504,
     863,  1504,  1131,  1514,    26,   955,    25,  1249,  1128,   432,
     719,   709,   713,   397,  1514,   955,   863,   908,   432,   988,
     987,   446,   974,   975,    20,   956,  1447,  1448,   558,  1430,
    1415,  1413,  1397,  1433,   144,  1336,     5,   397,  1294,  1455,
    1430,  1481,  1481,  1480,   436,   436,   436,   436,   436,   436,
     436,   956,   436,     5,   397,    18,    19,    20,    21,  1459,
     397,     5,   397,     5,    14,   154,   531,  1472,  1305,  1397,
     468,  1331,  1332,  1395,   215,  1062,   822,   397,  1408,  1408,
    1363,   447,  1375,  1375,  1379,  1380,  1400,  1493,  1375,  1379,
    1375,  1376,  1437,  1436,  1313,   796,   543,   592,  1138,     5,
    1136,    66,   138,   204,   206,   221,   229,   233,   258,  1191,
    1192,  1245,  1062,  1235,     5,   432,  1396,   397,    26,  1393,
     397,   397,    26,   397,   948,   692,   379,  1445,   863,   699,
     573,  1144,    26,   692,   432,  1022,   397,   245,   692,   397,
     397,   436,   711,   349,   717,   397,   706,  1084,  1514,   464,
     863,  1514,   955,     5,   397,  1131,  1366,  1434,  1397,   436,
    1366,   397,  1460,  1385,  1480,  1484,  1385,  1385,  1385,  1385,
     624,  1484,  1479,  1480,  1480,  1480,  1480,  1475,    14,  1476,
    1479,   950,  1370,  1131,     5,   145,  1325,  1377,  1400,  1441,
       5,   397,   397,  1375,     7,  1137,  1193,  1194,  1109,  1196,
    1109,  1195,  1197,  1192,   244,   244,    26,   630,   397,   840,
    1445,   398,   208,   264,   289,   298,   334,   342,   437,   607,
     696,   700,   701,   436,   624,   692,  1168,  1250,   714,   397,
    1128,   717,   717,  1514,   909,  1120,   580,  1019,  1448,  1428,
    1366,   488,  1297,  1298,  1437,  1428,   397,  1480,     5,   397,
    1480,  1480,  1480,  1480,   956,   397,   436,  1332,  1380,  1437,
    1514,  1514,  1198,  1514,  1199,  1514,  1514,   432,  1408,   243,
     352,   356,   843,   844,   845,  1025,   943,   943,   943,   943,
     943,   943,    25,     5,   397,   863,    20,   956,  1025,  1172,
    1173,  1174,   717,   719,   717,   246,   432,   989,   692,     5,
     397,   292,   293,  1416,   397,  1480,   397,   397,   397,   397,
    1478,  1514,  1514,   847,   846,   243,   845,   848,   701,     5,
    1175,   287,  1174,   715,  1514,  1298,    25,   956,  1417,  1418,
     397,  1514,  1514,  1514,   863,  1514,   397,   986,   624,   624,
       5,   397,   716,   956,   956,  1418,   167,   349,   718,   624,
    1128,   956
};

#if ! defined (YYSIZE_T) && defined (__SIZE_TYPE__)
# define YYSIZE_T __SIZE_TYPE__
#endif
#if ! defined (YYSIZE_T) && defined (size_t)
# define YYSIZE_T size_t
#endif
#if ! defined (YYSIZE_T)
# if defined (__STDC__) || defined (__cplusplus)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# endif
#endif
#if ! defined (YYSIZE_T)
# define YYSIZE_T unsigned int
#endif

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrlab1

/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK;						\
      goto yybackup;						\
    }								\
  else								\
    { 								\
      yyerror ("syntax error: cannot back up");\
      YYERROR;							\
    }								\
while (0)

#define YYTERROR	1
#define YYERRCODE	256

/* YYLLOC_DEFAULT -- Compute the default location (before the actions
   are run).  */

#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)         \
  Current.first_line   = Rhs[1].first_line;      \
  Current.first_column = Rhs[1].first_column;    \
  Current.last_line    = Rhs[N].last_line;       \
  Current.last_column  = Rhs[N].last_column;
#endif

/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (&yylval, YYLEX_PARAM)
#else
# define YYLEX yylex (&yylval)
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (0)

# define YYDSYMPRINT(Args)			\
do {						\
  if (yydebug)					\
    yysymprint Args;				\
} while (0)

# define YYDSYMPRINTF(Title, Token, Value, Location)		\
do {								\
  if (yydebug)							\
    {								\
      YYFPRINTF (stderr, "%s ", Title);				\
      yysymprint (stderr, 					\
                  Token, Value);	\
      YYFPRINTF (stderr, "\n");					\
    }								\
} while (0)

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (cinluded).                                                   |
`------------------------------------------------------------------*/

#if defined (__STDC__) || defined (__cplusplus)
static void
yy_stack_print (short *bottom, short *top)
#else
static void
yy_stack_print (bottom, top)
    short *bottom;
    short *top;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (/* Nothing. */; bottom <= top; ++bottom)
    YYFPRINTF (stderr, " %d", *bottom);
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if defined (__STDC__) || defined (__cplusplus)
static void
yy_reduce_print (int yyrule)
#else
static void
yy_reduce_print (yyrule)
    int yyrule;
#endif
{
  int yyi;
  unsigned int yylineno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %u), ",
             yyrule - 1, yylineno);
  /* Print the symbols being reduced, and their result.  */
  for (yyi = yyprhs[yyrule]; 0 <= yyrhs[yyi]; yyi++)
    YYFPRINTF (stderr, "%s ", yytname [yyrhs[yyi]]);
  YYFPRINTF (stderr, "-> %s\n", yytname [yyr1[yyrule]]);
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (Rule);		\
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YYDSYMPRINT(Args)
# define YYDSYMPRINTF(Title, Token, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   SIZE_MAX < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#if YYMAXDEPTH == 0
# undef YYMAXDEPTH
#endif

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif



#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined (__GLIBC__) && defined (_STRING_H)
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
#   if defined (__STDC__) || defined (__cplusplus)
yystrlen (const char *yystr)
#   else
yystrlen (yystr)
     const char *yystr;
#   endif
{
  register const char *yys = yystr;

  while (*yys++ != '\0')
    continue;

  return yys - yystr - 1;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined (__GLIBC__) && defined (_STRING_H) && defined (_GNU_SOURCE)
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
#   if defined (__STDC__) || defined (__cplusplus)
yystpcpy (char *yydest, const char *yysrc)
#   else
yystpcpy (yydest, yysrc)
     char *yydest;
     const char *yysrc;
#   endif
{
  register char *yyd = yydest;
  register const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

#endif /* !YYERROR_VERBOSE */



#if YYDEBUG
/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if defined (__STDC__) || defined (__cplusplus)
static void
yysymprint (FILE *yyoutput, int yytype, YYSTYPE *yyvaluep)
#else
static void
yysymprint (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  /* Pacify ``unused variable'' warnings.  */
  (void) yyvaluep;

  if (yytype < YYNTOKENS)
    {
      YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
# ifdef YYPRINT
      YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
    }
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  switch (yytype)
    {
      default:
        break;
    }
  YYFPRINTF (yyoutput, ")");
}

#endif /* ! YYDEBUG */
/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

#if defined (__STDC__) || defined (__cplusplus)
static void
yydestruct (int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yytype, yyvaluep)
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  /* Pacify ``unused variable'' warnings.  */
  (void) yyvaluep;

  switch (yytype)
    {

      default:
        break;
    }
}


/* Prevent warnings from -Wmissing-prototypes.  */

#ifdef YYPARSE_PARAM
# if defined (__STDC__) || defined (__cplusplus)
int yyparse (void *YYPARSE_PARAM);
# else
int yyparse ();
# endif
#else /* ! YYPARSE_PARAM */
#if defined (__STDC__) || defined (__cplusplus)
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */






/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
# if defined (__STDC__) || defined (__cplusplus)
int yyparse (void *YYPARSE_PARAM)
# else
int yyparse (YYPARSE_PARAM)
  void *YYPARSE_PARAM;
# endif
#else /* ! YYPARSE_PARAM */
#if defined (__STDC__) || defined (__cplusplus)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
  /* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;

  register int yystate;
  register int yyn;
  int yyresult;
  /* Number of tokens to shift before error messages enabled.  */
  int yyerrstatus;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;

  /* Three stacks and their tools:
     `yyss': related to states,
     `yyvs': related to semantic values,
     `yyls': related to locations.

     Refer to the stacks thru separate pointers, to allow yyoverflow
     to reallocate them elsewhere.  */

  /* The state stack.  */
  short	yyssa[YYINITDEPTH];
  short *yyss = yyssa;
  register short *yyssp;

  /* The semantic value stack.  */
  YYSTYPE yyvsa[YYINITDEPTH];
  YYSTYPE *yyvs = yyvsa;
  register YYSTYPE *yyvsp;



#define YYPOPSTACK   (yyvsp--, yyssp--)

  YYSIZE_T yystacksize = YYINITDEPTH;

  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;


  /* When reducing, the number of symbols on the RHS of the reduced
     rule.  */
  int yylen;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */

  yyssp = yyss;
  yyvsp = yyvs;

  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed. so pushing a state here evens the stacks.
     */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack. Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	short *yyss1 = yyss;


	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow ("parser stack overflow",
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),

		    &yystacksize);

	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyoverflowlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyoverflowlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	short *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyoverflowlab;
	YYSTACK_RELOCATE (yyss);
	YYSTACK_RELOCATE (yyvs);

#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;


      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

/* Do appropriate processing given the current state.  */
/* Read a lookahead token if we need one and don't already have one.  */
/* yyresume: */

  /* First try to decide what to do without reference to lookahead token.  */

  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YYDSYMPRINTF ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yyn == 0 || yyn == YYTABLE_NINF)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Shift the lookahead token.  */
  YYDPRINTF ((stderr, "Shifting token %s, ", yytname[yytoken]));

  /* Discard the token being shifted unless it is eof.  */
  if (yychar != YYEOF)
    yychar = YYEMPTY;

  *++yyvsp = yylval;


  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  yystate = yyn;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 944 "fgl.yacc"
    { print_screen_mode(0);}
    break;

  case 3:
#line 947 "fgl.yacc"
    { print_screen_mode(1);}
    break;

  case 4:
#line 951 "fgl.yacc"
    {
		print_start_server(yyvsp[-3].str,yyvsp[0].str);
	}
    break;

  case 5:
#line 957 "fgl.yacc"
    {
	print_stop_external();
	}
    break;

  case 6:
#line 962 "fgl.yacc"
    {
		if (scan_variable(yyvsp[0].str)!=2) {
		char buff[256];
			strcpy(buff,"START EXTERNAL ..ON must be an integer");
			a4gl_yyerror(buff);
			YYERROR;
		}
	}
    break;

  case 9:
#line 974 "fgl.yacc"
    {
	sprintf(yyval.str,"%s%s",yyvsp[-2].str,yyvsp[0].str);
	}
    break;

  case 10:
#line 979 "fgl.yacc"
    {
	print_remote_func(yyvsp[0].str);
	sprintf(yyval.str,
		"A4GL_unregister_func(\"%s\",%s%s);\n",
			yyvsp[0].str,
			(char *)get_namespace(yyvsp[0].str),
			yyvsp[0].str
	);
	addmap("Call Remote",yyvsp[0].str,curr_func,yylineno,infilename);
	}
    break;

  case 11:
#line 1002 "fgl.yacc"
    {sprintf(yyval.str,"(%s)",yyvsp[-1].str);}
    break;

  case 12:
#line 1003 "fgl.yacc"
    { sprintf(yyval.str,"%s%s%s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 13:
#line 1004 "fgl.yacc"
    {sprintf(yyval.str,"%d",atoi(yyvsp[0].str));}
    break;

  case 14:
#line 1005 "fgl.yacc"
    {sprintf(yyval.str,"(%s%s)",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 15:
#line 1006 "fgl.yacc"
    {
  int a;
  a=scan_variable(yyvsp[0].str)&15;
  if (a!=1&&a!=2) {
    
    a4gl_yyerror("Only INTEGER/SMALLINT variables may be used as subscripts");
    YYERROR;
    /* error processing */;
  }
  sprintf(yyval.str,"%s",fgl_add_scope(yyvsp[0].str,0));
}
    break;

  case 16:
#line 1017 "fgl.yacc"
    {
	struct expr_str *ptr;
	char buff2[1024];
	char buff[1024];
	sprintf(yyval.str,print_arr_expr_fcall(yyvsp[0].ptr));
}
    break;

  case 17:
#line 1026 "fgl.yacc"
    {strcpy(yyval.str,"+");}
    break;

  case 18:
#line 1027 "fgl.yacc"
    {strcpy(yyval.str,"-");}
    break;

  case 19:
#line 1028 "fgl.yacc"
    {strcpy(yyval.str,"*");}
    break;

  case 20:
#line 1029 "fgl.yacc"
    {strcpy(yyval.str,"/");}
    break;

  case 21:
#line 1030 "fgl.yacc"
    {strcpy(yyval.str,"%");}
    break;

  case 22:
#line 1035 "fgl.yacc"
    {strcpy(yyval.str,"+");}
    break;

  case 23:
#line 1036 "fgl.yacc"
    {strcpy(yyval.str,"-");}
    break;

  case 24:
#line 1047 "fgl.yacc"
    {
	 A4GL_debug("Using default attribute of WHITE");
		sprintf(yyval.str,"%d",0);}
    break;

  case 25:
#line 1050 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 26:
#line 1053 "fgl.yacc"
    {start_state("attribute",1);}
    break;

  case 27:
#line 1053 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[-1].str);
A4GL_debug("Got Attributes : %s",yyvsp[-1].str);
start_state("attribute",0);
}
    break;

  case 29:
#line 1060 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 30:
#line 1061 "fgl.yacc"
    {
sprintf(yyval.str,"%d",atoi(yyvsp[-2].str)|atoi(yyvsp[0].str));
}
    break;

  case 31:
#line 1067 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("BLACK"));}
    break;

  case 32:
#line 1068 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("BLUE"));}
    break;

  case 33:
#line 1069 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("CYAN"));}
    break;

  case 34:
#line 1070 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("GREEN"));}
    break;

  case 35:
#line 1071 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("MAGENTA"));}
    break;

  case 36:
#line 1072 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("RED"));}
    break;

  case 37:
#line 1073 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("WHITE"));}
    break;

  case 38:
#line 1074 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("YELLOW"));}
    break;

  case 39:
#line 1075 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("REVERSE"));}
    break;

  case 40:
#line 1076 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("BLINK"));}
    break;

  case 41:
#line 1077 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("UNDERLINE"));}
    break;

  case 42:
#line 1078 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("BOLD"));}
    break;

  case 43:
#line 1079 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("NORMAL"));}
    break;

  case 44:
#line 1080 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("INVISIBLE"));}
    break;

  case 45:
#line 1081 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("DIM"));}
    break;

  case 46:
#line 1082 "fgl.yacc"
    {inp_flags=inp_flags | 0x1; strcpy(yyval.str,"0");}
    break;

  case 47:
#line 1083 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 50:
#line 1090 "fgl.yacc"
    {
A4GL_debug("win_attributes_def");
start_state("attribute",1);
A4GL_debug("Started states");
form_attrib.attrib=0;
form_attrib.comment_line=0xff;
form_attrib.form_line=0xff;
form_attrib.error_line=0xff;
form_attrib.menu_line=0xff;
form_attrib.message_line=0xff;
form_attrib.prompt_line=0xff;
}
    break;

  case 51:
#line 1101 "fgl.yacc"
    {start_state("attribute",0);strcpy(yyval.str,"");
}
    break;

  case 52:
#line 1105 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 53:
#line 1106 "fgl.yacc"
    {sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 54:
#line 1110 "fgl.yacc"
    { 
/*printf("Window attribute = %s\n",$<str>1);*/
form_attrib.attrib      =form_attrib.attrib|atoi(yyvsp[0].str);
/*printf("Window attribute = %d\n",form_attrib.attrib);*/
}
    break;

  case 55:
#line 1116 "fgl.yacc"
    { form_attrib.border      =1;}
    break;

  case 56:
#line 1118 "fgl.yacc"
    {int a;
char *buff;
a=form_attrib.attrib&255;
if (strlen(yyvsp[0].str) > 2) {
buff=yyvsp[0].str;
form_attrib.attrib=form_attrib.attrib+buff[1];
} else  {
form_attrib.attrib=form_attrib.attrib+' ';
      }
}
    break;

  case 57:
#line 1129 "fgl.yacc"
    { form_attrib.comment_line=atoi(yyvsp[0].str); }
    break;

  case 58:
#line 1131 "fgl.yacc"
    { form_attrib.form_line   =atoi(yyvsp[0].str); }
    break;

  case 59:
#line 1133 "fgl.yacc"
    { form_attrib.error_line  =atoi(yyvsp[0].str); }
    break;

  case 60:
#line 1135 "fgl.yacc"
    { form_attrib.menu_line   =atoi(yyvsp[0].str); 
A4GL_debug("Set menu line to %s",yyvsp[0].str);
}
    break;

  case 61:
#line 1139 "fgl.yacc"
    { form_attrib.message_line=atoi(yyvsp[0].str); }
    break;

  case 62:
#line 1141 "fgl.yacc"
    { form_attrib.prompt_line =atoi(yyvsp[0].str); }
    break;

  case 63:
#line 1202 "fgl.yacc"
    {strcpy(yyval.str,"CALL");}
    break;

  case 64:
#line 1206 "fgl.yacc"
    { A4GL_debug("print_expr (3)"); 
		print_expr(yyvsp[-2].ptr);
		print_pop_variable(yyvsp[0].str);
	}
    break;

  case 65:
#line 1210 "fgl.yacc"
    {
        if (!isin_command("INPUT")&&!isin_command("CONSTRUCT")) {
                a4gl_yyerror("get_fldbuf can only be used in an input or construct");
                YYERROR;
        }
	print_getfldbuf(yyvsp[-2].str);
	}
    break;

  case 66:
#line 1217 "fgl.yacc"
    {
		print_returning();
	}
    break;

  case 67:
#line 1220 "fgl.yacc"
    {
	print_form_is_compiled(yyvsp[-5].str,yyvsp[-3].str,yyvsp[-1].str);
	}
    break;

  case 68:
#line 1224 "fgl.yacc"
    {
		print_field_func('I',yyvsp[-3].str,yyvsp[0].str);
   }
    break;

  case 70:
#line 1228 "fgl.yacc"
    { 
        if (!isin_command("INPUT")&&!isin_command("CONSTRUCT")) {
                a4gl_yyerror("get_fldbuf can only be used in an input or construct");
                YYERROR;
        }
	print_field_func('T',yyvsp[-3].str,yyvsp[0].str);
   }
    break;

  case 71:
#line 1235 "fgl.yacc"
    {
	new_counter();
   	addmap("Call",yyvsp[-3].str,curr_func,yylineno,infilename);
   }
    break;

  case 72:
#line 1241 "fgl.yacc"
    {
	int a;
	dump_expr(yyvsp[-1].ptr);
	a=get_counter_val();
	drop_counter();
 A4GL_debug("Printing call_func_call...");
  	print_class_func_call(yyvsp[-6].str,yyvsp[-4].str,yyvsp[-1].ptr,a);
   }
    break;

  case 73:
#line 1250 "fgl.yacc"
    {
	print_returning();
	strcpy(yyval.str,yyvsp[-4].str); /* ? */
   }
    break;

  case 74:
#line 1254 "fgl.yacc"
    {
	new_counter();
   	addmap("Call",yyvsp[-1].str,curr_func,yylineno,infilename);
   }
    break;

  case 75:
#line 1259 "fgl.yacc"
    {
 A4GL_debug("Got args");
   }
    break;

  case 76:
#line 1263 "fgl.yacc"
    {
	int a;
	dump_expr(yyvsp[-2].ptr);
	a=get_counter_val();
	drop_counter();
  	print_func_call(yyvsp[-5].str,yyvsp[-2].ptr,a);
   }
    break;

  case 77:
#line 1271 "fgl.yacc"
    {
	print_returning();
	strcpy(yyval.str,yyvsp[-3].str); /* ? */
   }
    break;

  case 78:
#line 1275 "fgl.yacc"
    {
	A4GLSQL_set_status(0,0);
	new_counter();
	}
    break;

  case 79:
#line 1279 "fgl.yacc"
    {
   sprintf(yyval.str,"%d",get_counter_val());drop_counter();
}
    break;

  case 80:
#line 1281 "fgl.yacc"
    {
        print_expr ((struct expr_str *)yyvsp[-3].ptr);  
	print_call_shared(yyvsp[-6].str,yyvsp[-8].str,atoi(yyvsp[-2].str));
	print_returning();
	print_end_call_shared();
}
    break;

  case 81:
#line 1287 "fgl.yacc"
    {
	sprintf(yyval.str,"\"%s\",\"%s\"",yyvsp[-3].str,yyvsp[-1].str);
	A4GLSQL_set_status(0,0);
	new_counter();
	}
    break;

  case 82:
#line 1292 "fgl.yacc"
    {
   	sprintf(yyval.str,"%d",get_counter_val());drop_counter();
}
    break;

  case 83:
#line 1295 "fgl.yacc"
    {
	char buff[256];
	char *ptr;
 A4GL_debug("STR6 = %s",yyvsp[-4].str);
	strcpy(buff,yyvsp[-4].str);
	ptr=strchr(buff,',');
	*ptr=0;
	ptr++;
        print_expr ((struct expr_str *)yyvsp[-3].ptr);  
	print_call_shared(buff,ptr,atoi(yyvsp[-2].str));
	print_returning();
	print_end_call_shared();
}
    break;

  case 84:
#line 1311 "fgl.yacc"
    {
   char buff[256];
   new_counter();
   sprintf(buff,"%s:%s(%p)",yyvsp[-6].str,yyvsp[-4].str,yyvsp[-2].str);
   addmap("External",buff,curr_func,yylineno,infilename);
   }
    break;

  case 85:
#line 1318 "fgl.yacc"
    {
   sprintf(yyval.str,"%d",get_counter_val());drop_counter();
   }
    break;

  case 86:
#line 1322 "fgl.yacc"
    {
	 A4GL_debug("print_expr (6)");print_expr(yyvsp[-2].ptr);
   }
    break;

  case 87:
#line 1326 "fgl.yacc"
    { 
   	/* int cnt; */
	char fname[64];
	
   if (strcmp(yyvsp[0].str,"WITHOUT WAITING")==0) {	
	strcpy(fname,"1,");
	strcat(fname,yyvsp[-10].str);
   } else {
	strcpy(fname,"0,");
	strcat(fname,yyvsp[-10].str);
   }
	
   print_call_external(yyvsp[-12].str,fname,yyvsp[-8].str,atoi(yyvsp[-3].str));

   if (strcmp(yyvsp[0].str,"WITHOUT WAITING")!=0) {	
	print_returning();
   }
   print_end_call_external();
  }
    break;

  case 88:
#line 1348 "fgl.yacc"
    {start_bind('i',0);strcpy(yyval.str,"0");}
    break;

  case 89:
#line 1348 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);
}
    break;

  case 90:
#line 1352 "fgl.yacc"
    {start_bind('i',0);strcpy(yyval.str,"0");}
    break;

  case 91:
#line 1353 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 92:
#line 1354 "fgl.yacc"
    {strcpy(yyval.str,"WITHOUT WAITING"); }
    break;

  case 93:
#line 1359 "fgl.yacc"
    {
			yyval.ptr=A4GL_new_expr("");
		}
    break;

  case 94:
#line 1362 "fgl.yacc"
    {
			yyval.ptr=yyvsp[0].ptr;
		}
    break;

  case 95:
#line 1368 "fgl.yacc"
    {
	yyval.ptr=yyvsp[0].ptr;
}
    break;

  case 96:
#line 1371 "fgl.yacc"
    {
		yyval.ptr=A4GL_append_expr_expr(yyvsp[-2].ptr,yyvsp[0].ptr);
}
    break;

  case 99:
#line 1383 "fgl.yacc"
    {
sprintf(yyval.str,"\"%s\"",yyvsp[0].str);
}
    break;

  case 100:
#line 1389 "fgl.yacc"
    {
sprintf(yyval.str,"\"%s\"",yyvsp[0].str);
}
    break;

  case 101:
#line 1392 "fgl.yacc"
    { sprintf(yyval.str,"\"%s.%s\"",yyvsp[-2].str,yyvsp[0].str); }
    break;

  case 102:
#line 1407 "fgl.yacc"
    {
push_blockcommand("CASE");
setinc(1);
A4GL_incprint();
print_case(1);
setinc(1);
}
    break;

  case 103:
#line 1417 "fgl.yacc"
    {
print_after_when(0);
pop_blockcommand("CASE");
}
    break;

  case 104:
#line 1423 "fgl.yacc"
    {  push_blockcommand("CASE"); 
setinc(1);
A4GL_incprint(); 
print_case(0);
setinc(1);
}
    break;

  case 105:
#line 1432 "fgl.yacc"
    {
print_after_when(0);
pop_blockcommand("CASE");
}
    break;

  case 110:
#line 1445 "fgl.yacc"
    {setinc(-1);A4GL_incprint();}
    break;

  case 112:
#line 1448 "fgl.yacc"
    {
A4GL_incprint();
}
    break;

  case 113:
#line 1450 "fgl.yacc"
    {A4GL_incprint();
print_after_when(0);
}
    break;

  case 115:
#line 1456 "fgl.yacc"
    {A4GL_incprint();}
    break;

  case 116:
#line 1458 "fgl.yacc"
    {A4GL_incprint();
print_after_when(0);
}
    break;

  case 117:
#line 1463 "fgl.yacc"
    {
print_when(0);

A4GL_incprint();
}
    break;

  case 118:
#line 1468 "fgl.yacc"
    {A4GL_incprint();
print_after_when(1);
setinc(-1);}
    break;

  case 119:
#line 1474 "fgl.yacc"
    {
A4GL_incprint();
print_when(1);
}
    break;

  case 120:
#line 1478 "fgl.yacc"
    {A4GL_incprint();
print_after_when(1);
setinc(-1);}
    break;

  case 121:
#line 1493 "fgl.yacc"
    {
  print_close('F',yyvsp[0].str);
 }
    break;

  case 122:
#line 1496 "fgl.yacc"
    {
  print_close('W',yyvsp[0].str);
}
    break;

  case 123:
#line 1499 "fgl.yacc"
    {
  print_close('W',yyvsp[0].str);
}
    break;

  case 124:
#line 1502 "fgl.yacc"
    {
  print_close('D',0);
}
    break;

  case 125:
#line 1505 "fgl.yacc"
    {
  print_close('S',yyvsp[0].str);
}
    break;

  case 126:
#line 1508 "fgl.yacc"
    {
  print_close('C',yyvsp[0].str);
}
    break;

  case 132:
#line 1530 "fgl.yacc"
    {
			A4GL_lex_printc("%s",yyvsp[0].str);
}
    break;

  case 135:
#line 1539 "fgl.yacc"
    {
			A4GL_lex_printc("%s\n",yyvsp[0].str);
}
    break;

  case 136:
#line 1549 "fgl.yacc"
    {
/* This aint used - its filtered by the lexer first... */
	A4GL_lex_printc("FIXME : Comment : %s\n");
}
    break;

  case 137:
#line 1563 "fgl.yacc"
    {
push_blockcommand("CONSTRUCT");
}
    break;

  case 138:
#line 1567 "fgl.yacc"
    {
	print_construct_1();
}
    break;

  case 139:
#line 1570 "fgl.yacc"
    {
	print_construct_2(yyvsp[-2].str);
}
    break;

  case 140:
#line 1578 "fgl.yacc"
    {
	print_construct_3(1,yyvsp[-5].str,0,yyvsp[0].str,atoi(yyvsp[0].str));
	strcpy(yyval.str,"A4GL_form_loop(&_sio[0],_forminit)"); /* FIXME */
	reset_constr();
}
    break;

  case 141:
#line 1584 "fgl.yacc"
    {
	print_construct_3(0,yyvsp[-7].str,yyvsp[-2].str,yyvsp[0].str,atoi(yyvsp[0].str));
	strcpy(yyval.str,"A4GL_form_loop(&_sio[0],_forminit)"); /* FIXME */
	reset_constr();
}
    break;

  case 146:
#line 1599 "fgl.yacc"
    {
                push_construct("",yyval.str);
             }
    break;

  case 147:
#line 1603 "fgl.yacc"
    {
                sprintf(yyval.str,"%s.%s",yyvsp[-2].str,yyvsp[0].str);
                push_construct(yyvsp[-2].str,yyvsp[0].str); 
             }
    break;

  case 148:
#line 1608 "fgl.yacc"
    {
                push_construct(yyvsp[-2].str,"*");
             }
    break;

  case 151:
#line 1618 "fgl.yacc"
    {
		print_befaft_field_1(yyvsp[0].str);
	}
    break;

  case 152:
#line 1621 "fgl.yacc"
    {
		print_befaft_field_2();

	}
    break;

  case 153:
#line 1625 "fgl.yacc"
    {
		print_befaft_field_1(yyvsp[0].str);
	}
    break;

  case 154:
#line 1627 "fgl.yacc"
    {
		print_befaft_field_2();
	}
    break;

  case 155:
#line 1630 "fgl.yacc"
    {
		print_onkey_1(yyvsp[0].str);
	}
    break;

  case 156:
#line 1632 "fgl.yacc"
    {
		print_onkey_2();
	}
    break;

  case 157:
#line 1635 "fgl.yacc"
    {
		print_befaft_field_1("AFTER_INP");
	}
    break;

  case 158:
#line 1637 "fgl.yacc"
    {
		print_befaft_field_2();
	}
    break;

  case 159:
#line 1640 "fgl.yacc"
    {
		print_befaft_field_1("BEFORE_INP");
		}
    break;

  case 160:
#line 1643 "fgl.yacc"
    {
		print_befaft_field_2();
	}
    break;

  case 161:
#line 1653 "fgl.yacc"
    {sprintf(yyval.str,"BEF_FIELD_CHK(%s)",yyvsp[0].str);}
    break;

  case 162:
#line 1654 "fgl.yacc"
    {
	  char buff[80];
	  sprintf(buff,"BEF_FIELD_CHK(%s)",yyvsp[0].str);
	  A4GL_generate_or(yyval.str,yyvsp[-2].str,buff);
	}
    break;

  case 163:
#line 1662 "fgl.yacc"
    {sprintf(yyval.str,"AFT_FIELD_CHK(%s)",yyvsp[0].str);}
    break;

  case 164:
#line 1663 "fgl.yacc"
    {
	  char buff[80];
	  sprintf(buff,"AFT_FIELD_CHK(%s)",yyvsp[0].str);
	  A4GL_generate_or(yyval.str,yyvsp[-2].str,buff);
	}
    break;

  case 165:
#line 1680 "fgl.yacc"
    {
        	yyval.ptr=A4GL_new_expr("A4GL_pushop(OP_YEAR);");
	}
    break;

  case 166:
#line 1683 "fgl.yacc"
    {
        	yyval.ptr=A4GL_new_expr("A4GL_pushop(OP_MONTH);");
	}
    break;

  case 167:
#line 1686 "fgl.yacc"
    {
        	yyval.ptr=A4GL_new_expr("A4GL_pushop(OP_DAY);");
	}
    break;

  case 168:
#line 1689 "fgl.yacc"
    {
        	yyval.ptr=A4GL_new_expr("A4GL_pushop(OP_HOUR);");
	}
    break;

  case 169:
#line 1692 "fgl.yacc"
    {
        	yyval.ptr=A4GL_new_expr("A4GL_pushop(OP_MINUTE);");
	}
    break;

  case 170:
#line 1695 "fgl.yacc"
    {
        	yyval.ptr=A4GL_new_expr("A4GL_pushop(OP_SECOND);");
	}
    break;

  case 171:
#line 1704 "fgl.yacc"
    {
			yyval.ptr=A4GL_append_expr_expr(yyvsp[-2].ptr,yyvsp[-1].ptr);
		}
    break;

  case 172:
#line 1712 "fgl.yacc"
    { 
	char buff[50];
	sprintf(buff,"A4GL_push_int(%d);",(19*16)+10); 
	yyval.ptr=A4GL_new_expr(buff);
}
    break;

  case 173:
#line 1717 "fgl.yacc"
    { 
	char buff[50];
	sprintf(buff,"A4GL_push_int(%d);",(atoi(yyvsp[-2].str)*16) +atoi(yyvsp[0].str)  ); 
	yyval.ptr=A4GL_new_expr(buff);
}
    break;

  case 174:
#line 1730 "fgl.yacc"
    {
				print_defer(0);
			}
    break;

  case 175:
#line 1734 "fgl.yacc"
    {
				print_defer(1);
			}
    break;

  case 176:
#line 1749 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 177:
#line 1750 "fgl.yacc"
    {strcpy(yyval.str,"");lastlineno=yylineno;}
    break;

  case 180:
#line 1758 "fgl.yacc"
    {dtypelist[0]=0;A4GL_lex_printcomment("/* define */\n");}
    break;

  case 181:
#line 1758 "fgl.yacc"
    {A4GL_lex_printcomment("/*end def */\n");}
    break;

  case 187:
#line 1768 "fgl.yacc"
    {in_define=1;}
    break;

  case 188:
#line 1768 "fgl.yacc"
    {in_define=0;strcpy(yyval.str,yyvsp[0].str);
                        set_yytext(yyval.str);
                        if (A4GL_bad_identifiers(yyval.str)) {
                                a4gl_yyerror("You can't use this identifier as it is a reserved word in the target language");
                        }
}
    break;

  case 189:
#line 1777 "fgl.yacc"
    { add_constant('c',yyvsp[0].str,yyvsp[-2].str); addmap("Constant",yyvsp[-2].str,curr_func,yylineno,infilename); }
    break;

  case 190:
#line 1778 "fgl.yacc"
    { add_constant('C',yyvsp[0].str,yyvsp[-2].str); addmap("Constant",yyvsp[-2].str,curr_func,yylineno,infilename); }
    break;

  case 191:
#line 1779 "fgl.yacc"
    { add_constant('f',yyvsp[0].str,yyvsp[-2].str);
addmap("Constant",yyvsp[-2].str,curr_func,yylineno,infilename);
 }
    break;

  case 192:
#line 1782 "fgl.yacc"
    { 
add_constant('i',yyvsp[0].str,yyvsp[-2].str);
addmap("Constant",yyvsp[-2].str,curr_func,yylineno,infilename);
 }
    break;

  case 194:
#line 1787 "fgl.yacc"
    { }
    break;

  case 195:
#line 1787 "fgl.yacc"
    {
char buff[20];
strncpy(buff,yyvsp[0].str,3);
if (buff[0]=='"') {
	add_constant('c',yyvsp[0].str,yyvsp[-3].str);
}  else {
	if (strchr(yyvsp[0].str,'.')) 
		add_constant('f',yyvsp[0].str,yyvsp[-3].str);
	else
		add_constant('i',yyvsp[0].str,yyvsp[-3].str);
}

addmap("Constant",yyvsp[-3].str,curr_func,yylineno,infilename);
}
    break;

  case 199:
#line 1804 "fgl.yacc"
    {
		sprintf(yyval.str,"-%p",yyvsp[0].str);}
    break;

  case 200:
#line 1808 "fgl.yacc"
    {
/*AF CygWin FIX */
push_name(yyval.str,0);
addmap("Define",yyvsp[0].str,curr_func,yylineno,infilename);
}
    break;

  case 205:
#line 1823 "fgl.yacc"
    {strcpy(yyval.str,"-1");}
    break;

  case 206:
#line 1824 "fgl.yacc"
    {strcpy(yyval.str,"-1");}
    break;

  case 207:
#line 1825 "fgl.yacc"
    {strcpy(yyval.str,"-2");}
    break;

  case 208:
#line 1826 "fgl.yacc"
    {strcpy(yyval.str,"-3");}
    break;

  case 209:
#line 1831 "fgl.yacc"
    {
 A4GL_debug("defines array %s",yyvsp[-1].str);
	push_type(0,0,yyvsp[-1].str);
}
    break;

  case 211:
#line 1837 "fgl.yacc"
    {
 A4GL_debug("defines array %s",yyvsp[0].str);
	push_type(0,0,yyvsp[0].str);
}
    break;

  case 213:
#line 1846 "fgl.yacc"
    {
	push_associate(yyvsp[-5].str,yyvsp[-1].str);
	push_type(0,0,yyvsp[-1].str);
}
    break;

  case 214:
#line 1850 "fgl.yacc"
    {
    /* void pop_associate (char *a); */
	pop_associate(0);

}
    break;

  case 220:
#line 1866 "fgl.yacc"
    {sprintf(yyval.str,"%s][%s][%s",yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str); A4GL_debug("Triplet");}
    break;

  case 221:
#line 1868 "fgl.yacc"
    {sprintf(yyval.str,"%s][%s",yyvsp[-2].str,yyvsp[0].str); A4GL_debug("double");}
    break;

  case 222:
#line 1869 "fgl.yacc"
    {A4GL_debug("Single");}
    break;

  case 224:
#line 1876 "fgl.yacc"
    {push_record();in_record++;}
    break;

  case 225:
#line 1876 "fgl.yacc"
    {pop_record();in_record--;}
    break;

  case 226:
#line 1877 "fgl.yacc"
    {in_record++;push_record();A4GL_debug("Like\n");}
    break;

  case 227:
#line 1878 "fgl.yacc"
    {A4GL_debug("Link Table : %s\n",yyvsp[-2].str);
                  push_rectab(yyvsp[-2].str);
                  pop_record();in_record--;}
    break;

  case 228:
#line 1881 "fgl.yacc"
    {
		push_record();A4GL_debug("Like\n");}
    break;

  case 229:
#line 1883 "fgl.yacc"
    {
		  A4GL_debug("Table:%s\n",yyvsp[-4].str);
		  add_link_to(yyvsp[-4].str,yyvsp[-1].str);
	          A4GL_debug("Push record...\n");
                  push_rectab(yyvsp[-4].str);
                  pop_record();
}
    break;

  case 231:
#line 1893 "fgl.yacc"
    {
	sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 236:
#line 1908 "fgl.yacc"
    {start_state("dtype",1);}
    break;

  case 237:
#line 1908 "fgl.yacc"
    {start_state("dtype",0);}
    break;

  case 241:
#line 1914 "fgl.yacc"
    {push_type("char","1",0);}
    break;

  case 242:
#line 1915 "fgl.yacc"
    {
/* char buff[80]; */
if (atoi(yyvsp[-1].str)==4) {
	addmap("size=4","----",curr_func,yylineno,infilename);
}
push_type("char",yyvsp[-1].str,0);
}
    break;

  case 243:
#line 1922 "fgl.yacc"
    {push_type("char",yyvsp[-1].str,0);}
    break;

  case 244:
#line 1923 "fgl.yacc"
    {push_type("char",yyvsp[-3].str,0);}
    break;

  case 245:
#line 1924 "fgl.yacc"
    {push_type("long",0,0);}
    break;

  case 246:
#line 1925 "fgl.yacc"
    {
A4GL_debug("Using specified type...");
push_dim(yyvsp[0].str);}
    break;

  case 247:
#line 1928 "fgl.yacc"
    {push_type("int",0,0);}
    break;

  case 248:
#line 1929 "fgl.yacc"
    {push_type("form",0,0);}
    break;

  case 249:
#line 1930 "fgl.yacc"
    {push_type("form",0,0);}
    break;

  case 250:
#line 1931 "fgl.yacc"
    { char buff[256];
				sprintf(buff,"%d",16*256+2);
				push_type("fgldecimal",buff,0);
				}
    break;

  case 251:
#line 1935 "fgl.yacc"
    {
				char buff[256];
				sprintf(buff,"%d",atoi(yyvsp[-1].str)*256+2);
				push_type("fgldecimal",buff,0);
}
    break;

  case 252:
#line 1940 "fgl.yacc"
    {
char buff[256];
sprintf(buff,"%d",atoi(yyvsp[-3].str)*256+atoi(yyvsp[-1].str));
push_type("fgldecimal",buff,0);
}
    break;

  case 253:
#line 1945 "fgl.yacc"
    {
			char buff[256];
			sprintf(buff,"%d",16*256+2);
			push_type("fglmoney",buff,0);}
    break;

  case 254:
#line 1949 "fgl.yacc"
    {
		char buff[256];sprintf(buff,"%d",atoi(yyvsp[-1].str)*256+2);
			push_type("fglmoney",buff,0);}
    break;

  case 255:
#line 1952 "fgl.yacc"
    {
char buff[256];
sprintf(buff,"%d",atoi(yyvsp[-3].str)*256+atoi(yyvsp[-1].str));
push_type("fglmoney",buff,0);}
    break;

  case 256:
#line 1956 "fgl.yacc"
    {push_type("double",0,0);}
    break;

  case 257:
#line 1957 "fgl.yacc"
    {push_type("float",0,0);}
    break;

  case 258:
#line 1958 "fgl.yacc"
    {push_type("fgldate",0,0);}
    break;

  case 259:
#line 1959 "fgl.yacc"
    {push_type("fglbyte",0,0);}
    break;

  case 260:
#line 1960 "fgl.yacc"
    {push_type("fglbyte",0,0);}
    break;

  case 261:
#line 1961 "fgl.yacc"
    {push_type("fgltext",0,0);}
    break;

  case 262:
#line 1962 "fgl.yacc"
    {push_type("fgltext",0,0);}
    break;

  case 263:
#line 1963 "fgl.yacc"
    {
push_type("struct_dtime",yyvsp[0].str,0);
}
    break;

  case 264:
#line 1966 "fgl.yacc"
    {push_type("struct_ival",yyvsp[0].str,0);}
    break;

  case 265:
#line 1967 "fgl.yacc"
    {push_like(yyvsp[0].str);A4GL_lex_printcomment("/*added(XXXXX)\n */");}
    break;

  case 266:
#line 1968 "fgl.yacc"
    {
			char buff[256];
			strcpy(buff,yyvsp[0].str);
		 A4GL_debug("Got a rogue datatype");

			if (A4GL_find_datatype(upshift(buff))) 
			{
				char *(*function) (void);
			 A4GL_debug("Checking ...");
				function=A4GL_get_datatype_function_n(upshift(buff),"OUTPUT");
			 A4GL_debug("Got function as %p",function);

                /*  warning: comparison between pointer and integer */
				if ((int)function != -1 && (int)function != 0)
				{
				 A4GL_debug("call returns %s\n",function());
					strcpy(buff,function());
				 A4GL_debug("Set up buff as %s");
					push_type(function(),0,0);
				 A4GL_debug("Pushed type : %s\n",function());
				}
			} else {
				/* yyerror("Unknown datatype : %s",$<str>1); */
                a4gl_yyerror("Unknown datatype.");
			}
		}
    break;

  case 267:
#line 2000 "fgl.yacc"
    {
A4GL_lex_printcomment("/*column like(ZZZ)\n*/"); sprintf(yyval.str,"%s.%s",yyvsp[-2].str,yyvsp[0].str); A4GL_lex_printcomment ("/*set col...(ZZZ)\n*/");}
    break;

  case 268:
#line 2004 "fgl.yacc"
    {A4GL_debug("--->%s\n",yyvsp[0].str);strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 269:
#line 2006 "fgl.yacc"
    {A4GL_debug("--->%s\n",yyvsp[0].str);strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 270:
#line 2008 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 271:
#line 2010 "fgl.yacc"
    {
A4GL_debug("Real datetime %s to %s\n",yyvsp[-2].str,yyvsp[0].str);
sprintf(yyval.str,"%d",(atoi(yyvsp[-2].str)*16)+atoi(yyvsp[0].str)); }
    break;

  case 272:
#line 2015 "fgl.yacc"
    {
	sprintf(yyval.str,"%d",(atoi(yyvsp[-2].str)*16)+atoi(yyvsp[0].str)); 
}
    break;

  case 273:
#line 2019 "fgl.yacc"
    {start_state("dtime_val",1);}
    break;

  case 274:
#line 2019 "fgl.yacc"
    {start_state("dtime_val",0); strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 275:
#line 2023 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 276:
#line 2024 "fgl.yacc"
    {strcpy(yyval.str,"2");}
    break;

  case 277:
#line 2025 "fgl.yacc"
    {strcpy(yyval.str,"3");}
    break;

  case 278:
#line 2026 "fgl.yacc"
    {strcpy(yyval.str,"4");}
    break;

  case 279:
#line 2027 "fgl.yacc"
    {strcpy(yyval.str,"5");}
    break;

  case 280:
#line 2028 "fgl.yacc"
    {strcpy(yyval.str,"6");}
    break;

  case 281:
#line 2030 "fgl.yacc"
    {
A4GL_debug("opt_frac returns %s",yyvsp[0].str);
sprintf(yyval.str,"%d",atoi(yyvsp[0].str)+6); }
    break;

  case 282:
#line 2035 "fgl.yacc"
    {start_state("dtime_val",1);}
    break;

  case 283:
#line 2035 "fgl.yacc"
    { A4GL_debug ("Got end");start_state("dtime_val",0);  strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 284:
#line 2038 "fgl.yacc"
    {
A4GL_debug("Nothing in fraction - assume 2");
strcpy(yyval.str,"2");}
    break;

  case 285:
#line 2040 "fgl.yacc"
    {
A4GL_debug("Read fraction .. ");
A4GL_debug("    %s",yyvsp[-1].str);
strcpy(yyval.str,yyvsp[-1].str);
}
    break;

  case 286:
#line 2046 "fgl.yacc"
    {
A4GL_debug("Nothing in fraction - assume 2");
strcpy(yyval.str,"2");}
    break;

  case 287:
#line 2048 "fgl.yacc"
    {
A4GL_debug("    %s",yyvsp[-1].str);
strcpy(yyval.str,yyvsp[-1].str);
}
    break;

  case 288:
#line 2054 "fgl.yacc"
    {
if (atoi(yyvsp[0].str)>5) {
a4gl_yyerror("Fraction values are between 0 and 5");
YYERROR;
}
}
    break;

  case 289:
#line 2062 "fgl.yacc"
    {start_state("interval_val",1);}
    break;

  case 290:
#line 2062 "fgl.yacc"
    {start_state("interval_val",0); sprintf(yyval.str,"%d",atoi(yyvsp[0].str)*16+atoi(yyvsp[-1].str));}
    break;

  case 291:
#line 2065 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 292:
#line 2066 "fgl.yacc"
    {strcpy(yyval.str,"2");}
    break;

  case 293:
#line 2067 "fgl.yacc"
    {strcpy(yyval.str,"3");}
    break;

  case 294:
#line 2068 "fgl.yacc"
    {strcpy(yyval.str,"4");}
    break;

  case 295:
#line 2069 "fgl.yacc"
    {strcpy(yyval.str,"5");}
    break;

  case 296:
#line 2070 "fgl.yacc"
    {strcpy(yyval.str,"6");}
    break;

  case 297:
#line 2072 "fgl.yacc"
    {
A4GL_debug("opt_frac returns %s",yyvsp[0].str);
sprintf(yyval.str,"%d",atoi(yyvsp[0].str)+6); }
    break;

  case 301:
#line 2093 "fgl.yacc"
    {
              	dim_set_name(yyvsp[0].str);
              }
    break;

  case 305:
#line 2102 "fgl.yacc"
    {dim_push_type("char","1",0);}
    break;

  case 306:
#line 2104 "fgl.yacc"
    {dim_push_type("char",yyvsp[-1].str,0);}
    break;

  case 307:
#line 2106 "fgl.yacc"
    {dim_push_type("char",yyvsp[-1].str,0);}
    break;

  case 308:
#line 2108 "fgl.yacc"
    {dim_push_type("char",yyvsp[-3].str,0);}
    break;

  case 309:
#line 2109 "fgl.yacc"
    {dim_push_type("long",0,0);}
    break;

  case 310:
#line 2110 "fgl.yacc"
    {dim_push_type("integer",0,0);}
    break;

  case 311:
#line 2111 "fgl.yacc"
    {dim_push_type("FORM",0,0);}
    break;

  case 312:
#line 2112 "fgl.yacc"
    {
char buff[256];
sprintf(buff,"%d",16*256+2);
dim_push_type("fgldecimal",buff,0);
}
    break;

  case 313:
#line 2117 "fgl.yacc"
    {

char buff[256];
sprintf(buff,"%d",atoi(yyvsp[-1].str)*256+2);
dim_push_type("fgldecimal",buff,0);
}
    break;

  case 314:
#line 2124 "fgl.yacc"
    {
char buff[256];
sprintf(buff,"%d",atoi(yyvsp[-3].str)*256+atoi(yyvsp[-1].str));
dim_push_type("fgldecimal",buff,0);
}
    break;

  case 315:
#line 2129 "fgl.yacc"
    {dim_push_type("fglmoney",0,0);}
    break;

  case 316:
#line 2131 "fgl.yacc"
    {dim_push_type("fglmoney",0,0);}
    break;

  case 317:
#line 2133 "fgl.yacc"
    {dim_push_type("fglmoney",0,0);}
    break;

  case 318:
#line 2134 "fgl.yacc"
    {dim_push_type("double",0,0);}
    break;

  case 319:
#line 2135 "fgl.yacc"
    {dim_push_type("float",0,0);}
    break;

  case 320:
#line 2136 "fgl.yacc"
    {dim_push_type("fgldate",0,0);}
    break;

  case 321:
#line 2137 "fgl.yacc"
    {dim_push_type("fglbyte",0,0);}
    break;

  case 322:
#line 2138 "fgl.yacc"
    {dim_push_type("fgltext",0,0);}
    break;

  case 323:
#line 2139 "fgl.yacc"
    {
dim_push_type("struct_dtime",yyvsp[0].str,0);
}
    break;

  case 324:
#line 2142 "fgl.yacc"
    {dim_push_type("struct_ival",0,0);}
    break;

  case 325:
#line 2144 "fgl.yacc"
    {dim_push_like(yyvsp[0].str);A4GL_lex_printcomment("/*added(XXXXX)\n */");}
    break;

  case 326:
#line 2150 "fgl.yacc"
    {
A4GL_lex_printcomment("/*column like(ZZZ)\n*/");
sprintf(yyval.str,"%s.%s",yyvsp[-2].str,yyvsp[0].str)
; A4GL_lex_printcomment ("/*set col...(ZZZ)\n*/");}
    break;

  case 327:
#line 2158 "fgl.yacc"
    {
dim_push_type(0,0,yyvsp[-1].str);
}
    break;

  case 329:
#line 2166 "fgl.yacc"
    {
dim_push_associate(yyvsp[-5].str,yyvsp[-1].str);
dim_push_type(0,0,yyvsp[-1].str);
}
    break;

  case 330:
#line 2170 "fgl.yacc"
    {
	/* void dim_pop_associate (char *a); */
	dim_pop_associate(0);
}
    break;

  case 331:
#line 2178 "fgl.yacc"
    {dim_push_record();}
    break;

  case 332:
#line 2179 "fgl.yacc"
    {dim_pop_record();}
    break;

  case 333:
#line 2180 "fgl.yacc"
    {dim_push_record();A4GL_debug("Like\n");}
    break;

  case 334:
#line 2181 "fgl.yacc"
    {A4GL_debug("Table:%s\n",yyvsp[-2].str);
                                  dim_push_rectab(yyvsp[-2].str);
                                  dim_pop_record();}
    break;

  case 340:
#line 2200 "fgl.yacc"
    { dim_push_name(yyval.str,0); }
    break;

  case 341:
#line 2212 "fgl.yacc"
    {
	print_display_line();
		strcpy(yyval.str,A4GL_get_display_str(0,0,0));
	}
    break;

  case 342:
#line 2216 "fgl.yacc"
    {
		strcpy(yyval.str,A4GL_get_display_str(1,0,0)); /* FIXME */
	}
    break;

  case 343:
#line 2219 "fgl.yacc"
    { 
	strcpy(yyval.str,"#error not implemented yet");
	}
    break;

  case 344:
#line 2222 "fgl.yacc"
    { strcpy(yyval.str, A4GL_get_display_str(4,0,0)); }
    break;

  case 345:
#line 2223 "fgl.yacc"
    { strcpy(yyval.str, A4GL_get_display_str(2,yyvsp[0].str,0)); }
    break;

  case 346:
#line 2224 "fgl.yacc"
    { strcpy(yyval.str, A4GL_get_display_str(3,yyvsp[0].str,yyvsp[-2].str)); }
    break;

  case 347:
#line 2225 "fgl.yacc"
    { strcpy(yyval.str, A4GL_get_display_str(5,yyvsp[-1].str,0)); }
    break;

  case 348:
#line 2226 "fgl.yacc"
    { 
	strcpy(yyval.str,"#error not implemented yet");
 }
    break;

  case 349:
#line 2232 "fgl.yacc"
    {
		print_display_by_name(yyvsp[0].str);
                }
    break;

  case 350:
#line 2239 "fgl.yacc"
    { 
				print_display(yyvsp[-1].str,yyvsp[-2].str,yyvsp[0].str);
		}
    break;

  case 351:
#line 2244 "fgl.yacc"
    {
		print_display_form(yyvsp[-1].str,yyvsp[0].str);
	}
    break;

  case 352:
#line 2249 "fgl.yacc"
    {
		push_blockcommand("DISPLAY");
		curr_input_array_attribs.curr_row_display=0;
		}
    break;

  case 353:
#line 2254 "fgl.yacc"
    {
		print_display_array_p1(fgl_add_scope(yyvsp[-6].str,0),yyvsp[-4].str,yyvsp[-1].str,yyvsp[0].str,&curr_input_array_attribs);
		}
    break;

  case 354:
#line 2257 "fgl.yacc"
    {
		add_continue_blockcommand ("DISPLAY");  
		print_display_array_p2();
		pop_blockcommand("DISPLAY");
}
    break;

  case 355:
#line 2265 "fgl.yacc"
    {
strcpy(yyval.str,"0,0");
}
    break;

  case 356:
#line 2267 "fgl.yacc"
    {
	strcpy(yyval.str,yyvsp[0].str);
}
    break;

  case 357:
#line 2272 "fgl.yacc"
    {
				sprintf(yyval.str,"0x%lx",atol(yyvsp[0].str));
			}
    break;

  case 363:
#line 2284 "fgl.yacc"
    {
		print_befaft_field_1("AFT_ROW");
		}
    break;

  case 364:
#line 2287 "fgl.yacc"
    {
		print_befaft_field_2();
	}
    break;

  case 365:
#line 2290 "fgl.yacc"
    {
		print_befaft_field_1("BEF_ROW");
		}
    break;

  case 366:
#line 2293 "fgl.yacc"
    {
		print_befaft_field_2();
	}
    break;

  case 367:
#line 2296 "fgl.yacc"
    {
		print_onkey_1(yyvsp[0].str);
		}
    break;

  case 368:
#line 2299 "fgl.yacc"
    {
		print_onkey_2();
	}
    break;

  case 369:
#line 2306 "fgl.yacc"
    {
		char buff[256];
		char *s;
		strcpy(buff,yyvsp[0].str);
		s=strchr(buff,'[');
		if (!s) {
			a4gl_yyerror("Expecting an array and size");
			YYERROR;
		}
		*s=0;
		s++;

		print_alloc_arr(buff,s);
	}
    break;

  case 370:
#line 2324 "fgl.yacc"
    {
		print_dealloc_arr(yyvsp[0].str);
	}
    break;

  case 371:
#line 2330 "fgl.yacc"
    {
		char buff[256];
		char *s;
		strcpy(buff,yyvsp[0].str);
		s=strchr(buff,'[');
		if (!s) {
			a4gl_yyerror("Expecting an array and size");
			YYERROR;
		}
		*s=0;
		s++;

		print_realloc_arr(buff,s);
	}
    break;

  case 372:
#line 2354 "fgl.yacc"
    {
			print_error(yyvsp[0].str,0);
		}
    break;

  case 373:
#line 2357 "fgl.yacc"
    { 
			print_error(yyvsp[-1].str,1);
	}
    break;

  case 374:
#line 2372 "fgl.yacc"
    { if (in_command("WHILE")) { exit_loop("WHILE"); } else { YYERROR;} }
    break;

  case 375:
#line 2374 "fgl.yacc"
    { if (in_command("INPUT")) { exit_loop("INPUT"); } else { YYERROR;} }
    break;

  case 376:
#line 2376 "fgl.yacc"
    { if (in_command("FOREACH")) { exit_loop("FOREACH"); } else { YYERROR;} }
    break;

  case 377:
#line 2378 "fgl.yacc"
    { if (in_command("FOR")) { exit_loop("FOR"); } else { YYERROR;} }
    break;

  case 378:
#line 2380 "fgl.yacc"
    { if (in_command("CONSTRUCT")) { exit_loop("CONSTRUCT"); } else { YYERROR;} }
    break;

  case 379:
#line 2382 "fgl.yacc"
    { if (in_command("DISPLAY")) { exit_loop("DISPLAY"); } else { YYERROR;} }
    break;

  case 380:
#line 2383 "fgl.yacc"
    {
	if (in_command("MENU")) {
		exit_loop("MENU");
		/* A4GL_lex_printc("cmd_no=-3;continue;\n"); */
	} 
              else YYERROR;}
    break;

  case 381:
#line 2390 "fgl.yacc"
    { if (in_command("CASE")) { exit_loop("CASE"); } else { YYERROR;} }
    break;

  case 382:
#line 2392 "fgl.yacc"
    { if (in_command("PROMPT")) { exit_loop("PROMPT"); } else { YYERROR;} }
    break;

  case 383:
#line 2396 "fgl.yacc"
    { if (in_command("WHILE")) { continue_loop("WHILE");  } else { YYERROR;} }
    break;

  case 384:
#line 2398 "fgl.yacc"
    { if (in_command("INPUT")) { continue_loop("INPUT"); } else { YYERROR;} }
    break;

  case 385:
#line 2400 "fgl.yacc"
    { if (in_command("FOREACH")) { continue_loop("FOREACH");} else { YYERROR;} }
    break;

  case 386:
#line 2402 "fgl.yacc"
    { if (in_command("FOR")) { continue_loop("FOR"); } else { YYERROR;} }
    break;

  case 387:
#line 2404 "fgl.yacc"
    { if (in_command("CONSTRUCT")) { continue_loop("CONSTRUCT"); } else { YYERROR;} }
    break;

  case 388:
#line 2406 "fgl.yacc"
    { if (in_command("DISPLAY")) { continue_loop("DISPLAY"); } else { YYERROR;} }
    break;

  case 389:
#line 2408 "fgl.yacc"
    { if (in_command("MENU")) {  continue_loop("MENU");  } else { YYERROR;} }
    break;

  case 390:
#line 2414 "fgl.yacc"
    { if (in_command("PROMPT")) { continue_loop("PROMPT"); } else { YYERROR;} }
    break;

  case 391:
#line 2428 "fgl.yacc"
    {
	print_exit_program(0);
}
    break;

  case 392:
#line 2431 "fgl.yacc"
    {
	print_exit_program(1);
}
    break;

  case 397:
#line 2448 "fgl.yacc"
    {
	dec_counter();
	yyval.ptr=A4GL_append_expr_expr(yyvsp[-1].ptr,yyvsp[0].ptr);
}
    break;

  case 400:
#line 2454 "fgl.yacc"
    {
	A4GL_debug("Got literal ptr=%p",yyvsp[0].ptr);
}
    break;

  case 401:
#line 2458 "fgl.yacc"
    {
	yyval.ptr=A4GL_new_expr("A4GL_push_int(0);");
	yyval.ptr=A4GL_append_expr_expr(yyval.ptr,yyvsp[0].ptr);
	yyval.ptr=A4GL_append_expr(yyval.ptr,"A4GL_pushop(OP_SUB);");
}
    break;

  case 402:
#line 2463 "fgl.yacc"
    {
	yyval.ptr=yyvsp[0].ptr;
}
    break;

  case 406:
#line 2473 "fgl.yacc"
    { yyval.ptr=A4GL_new_expr("A4GL_add_spaces();"); }
    break;

  case 407:
#line 2474 "fgl.yacc"
    {inc_counter();}
    break;

  case 413:
#line 2480 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_CONCAT);");
}
    break;

  case 414:
#line 2487 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 415:
#line 2487 "fgl.yacc"
    {
strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 417:
#line 2492 "fgl.yacc"
    {yyval.ptr=A4GL_new_expr("A4GL_push_null(2,0)");}
    break;

  case 418:
#line 2496 "fgl.yacc"
    {
	/*set_counter(0);*/
	sprintf(yyval.str,"%d",get_counter_val());
	A4GL_lex_printcomment("/*L1 %s*/\n",yyval.str);
}
    break;

  case 419:
#line 2502 "fgl.yacc"
    {
	sprintf(yyval.str,"%d",get_counter_val());
	A4GL_lex_printcomment("/*L2 %s*/\n",yyval.str);
}
    break;

  case 420:
#line 2510 "fgl.yacc"
    {
	/*set_counter(0);*/
	sprintf(yyval.str,"%d",get_counter_val());
	A4GL_lex_printcomment("/*L1 %s*/\n",yyval.str);
}
    break;

  case 421:
#line 2516 "fgl.yacc"
    {
	sprintf(yyval.str,"%d",get_counter_val());
	A4GL_lex_printcomment("/*L2 %s*/\n",yyval.str);
}
    break;

  case 422:
#line 2525 "fgl.yacc"
    {sprintf(yyval.str,"%d",get_counter_val());}
    break;

  case 423:
#line 2527 "fgl.yacc"
    {
	print_op("OP_CONCAT");
	dec_counter();sprintf(yyval.str,"%d",get_counter_val());
}
    break;

  case 424:
#line 2534 "fgl.yacc"
    {
	A4GL_debug("Print expr (2)");
	print_expr(yyvsp[0].ptr);
}
    break;

  case 425:
#line 2542 "fgl.yacc"
    {
	strcpy(yyval.str,"+");
}
    break;

  case 426:
#line 2546 "fgl.yacc"
    {
	strcpy(yyval.str,"-");
}
    break;

  case 427:
#line 2555 "fgl.yacc"
    {
	
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_NOT);");
}
    break;

  case 428:
#line 2560 "fgl.yacc"
    {
	yyval.ptr=A4GL_new_expr("A4GL_push_int(1);");
        inc_counter();
}
    break;

  case 429:
#line 2565 "fgl.yacc"
    {
	inc_counter();
	yyval.ptr=A4GL_new_expr("A4GL_push_int(0);");
}
    break;

  case 430:
#line 2569 "fgl.yacc"
    { yyval.ptr=yyvsp[-1].ptr; }
    break;

  case 431:
#line 2571 "fgl.yacc"
    {
	char buff[256];
	int n;
	yyval.ptr=A4GL_new_expr(yyvsp[-1].sql_string);
	A4GL_append_expr(yyval.ptr,"{");
	n=print_bind_expr(yyval.ptr,'i');
	sprintf(buff,"A4GL_push_binding(ibind,%d);}",n);
	A4GL_append_expr(yyval.ptr,buff);
	A4GL_append_expr(yyval.ptr,"A4GL_pushop(OP_EXISTS);");
}
    break;

  case 432:
#line 2581 "fgl.yacc"
    {
	char buff[256];
	int n;
	yyval.ptr=A4GL_new_expr(yyvsp[-1].sql_string);
	A4GL_append_expr(yyval.ptr,"{");
	n=print_bind_expr(yyval.ptr,'i');
	sprintf(buff,"A4GL_push_binding(ibind,%d);}",n);
	A4GL_append_expr(yyval.ptr,buff);
	A4GL_append_expr(yyval.ptr,"A4GL_pushop(OP_NOTEXISTS);");
}
    break;

  case 433:
#line 2595 "fgl.yacc"
    {
	A4GL_debug("init expr %s %s",yyvsp[-1].str,yyvsp[0].str);
	sprintf(yyval.str,"%s%p",yyvsp[-1].str,yyvsp[0].str);
	sprintf(yyval.str,"%s",A4GL_get_push_literal('D',yyval.str));
	yyval.ptr=A4GL_new_expr(yyval.str);
        inc_counter();
}
    break;

  case 434:
#line 2603 "fgl.yacc"
    {
	A4GL_debug("init expr int %s %d",yyvsp[-1].str,atoi(yyvsp[0].str));
	sprintf(yyval.str,"%s%p",yyvsp[-1].str,yyvsp[0].str);
	sprintf(yyval.str,"%s",A4GL_get_push_literal('L',yyval.str));
	yyval.ptr=A4GL_new_expr(yyval.str);
	inc_counter();
}
    break;

  case 435:
#line 2615 "fgl.yacc"
    {
	sprintf(yyval.str,"%s",A4GL_get_push_literal('S',yyvsp[0].str));
	yyval.ptr=A4GL_new_expr(yyval.str);
	inc_counter();
}
    break;

  case 436:
#line 2621 "fgl.yacc"
    {
	sprintf(yyval.str,"%s",A4GL_get_push_literal('D',yyvsp[0].str));
	yyval.ptr=A4GL_new_expr(yyval.str);
	inc_counter();
}
    break;

  case 437:
#line 2627 "fgl.yacc"
    {
	sprintf(yyval.str,"%s",A4GL_get_push_literal('L',yyvsp[0].str));
	yyval.ptr=A4GL_new_expr(yyval.str);
	inc_counter();
}
    break;

  case 440:
#line 2637 "fgl.yacc"
    {
		sprintf(yyval.str,"%s\n%s",yyvsp[-2].str,yyvsp[0].str);
	}
    break;

  case 441:
#line 2643 "fgl.yacc"
    {
   		int a;
   		int incvcnt;
   		int flg=0;
		void *p1;

		if (strchr(yyvsp[0].str,'\n')==0) {
			//printf("Finding %s",$<str>1);
   			a=scan_variable(yyvsp[0].str);
			//printf(" a=%d\n",a);
		} else {
			printf("Its a thru - setting a to -2\n");
			a=-2;
		}

   		if (a>=0) {
          		if (A4GL_aubit_strcasecmp(yyvsp[0].str,"today")==0) {
               		flg=1;
               		strcpy(yyval.str,"A4GL_push_today();");
          		}
		
          		if (A4GL_aubit_strcasecmp(yyvsp[0].str,"time")==0) {
               		flg=1;
               		strcpy(yyval.str,"A4GL_push_time();");
          		}
		
          		if (A4GL_aubit_strcasecmp(yyvsp[0].str,"pageno")==0) {
               		flg=1;
               		strcpy(yyval.str,"A4GL_push_variable(&rep.page_no,2);");
                  		}
          		if (A4GL_aubit_strcasecmp(yyvsp[0].str,"lineno")==0) {
               		flg=1;
               		strcpy(yyval.str,"A4GL_push_variable(&rep.line_no,2);");
          		}

         		if (flg==0) {
         				sprintf(yyval.str,"A4GL_push_variable(&%s,0x%x);",yyvsp[0].str,(int)scan_variable(yyvsp[0].str));
         		}
      			p1=A4GL_new_expr(yyval.str);
       			yyval.ptr=p1;
			inc_counter();
   		}



        	if (a==-1)
        	{
                	sprintf(yyval.str,"A4GL_push_char(%s);",yyvsp[0].str);inc_counter();
      			p1=A4GL_new_expr(yyval.str);
       			yyval.ptr=p1;
			inc_counter();
        	}


        	if (a==-2)
        	{
			p1=A4GL_new_expr("");
	        	incvcnt=print_push_rec(yyvsp[0].str,&p1);
	        	inc_counter_by(incvcnt);
			yyval.ptr=p1;
        	}




	}
    break;

  case 442:
#line 2715 "fgl.yacc"
    {
	sprintf(yyval.str,"A4GL_%sset_column(&rep);",ispdf());
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,yyval.str);
}
    break;

  case 443:
#line 2721 "fgl.yacc"
    {
sprintf(yyval.str,"A4GL_%sset_column(&rep);",ispdf());
yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,yyval.str);
}
    break;

  case 444:
#line 2725 "fgl.yacc"
    {
   if (!isin_command("REPORT")) {
   a4gl_yyerror("This can only be done in a report!");
   YYERROR;
} 
insql=0;
	yyval.ptr=A4GL_new_expr(yyvsp[0].str);
}
    break;

  case 445:
#line 2733 "fgl.yacc"
    {insql=1;set_ingroup();}
    break;

  case 446:
#line 2733 "fgl.yacc"
    {
	char buff[256];
      if (!isin_command("REPORT")) {
        a4gl_yyerror("This can only be done in a report!");YYERROR;
      } insql=0; 
	A4GL_lex_printcomment("/* rep_Agg = %s\n*/",yyvsp[0].str);
        strcpy(buff,yyvsp[0].str);
	A4GL_debug("report aggregate :  %s",buff);
	yyval.ptr=A4GL_new_expr(buff);
      }
    break;

  case 447:
#line 2749 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_AND);");
}
    break;

  case 448:
#line 2753 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_OR);");
}
    break;

  case 449:
#line 2759 "fgl.yacc"
    {
	yyval.ptr=yyvsp[0].ptr;
	}
    break;

  case 450:
#line 2762 "fgl.yacc"
    {
		A4GL_debug("Adding to list...");
		yyval.ptr=A4GL_append_expr_expr(yyvsp[-2].ptr,yyvsp[0].ptr);
	}
    break;

  case 451:
#line 2770 "fgl.yacc"
    {
	char buff[256];
	int n;
	yyval.ptr=A4GL_new_expr(yyvsp[-1].sql_string);
	A4GL_append_expr(yyval.ptr,"{");
	n=print_bind_expr(yyval.ptr,'i');
	sprintf(buff,"A4GL_push_binding(ibind,%d);}",n);
	A4GL_append_expr(yyval.ptr,buff);
	A4GL_append_expr(yyval.ptr,"A4GL_pushop(OP_IN_SELECT);");
}
    break;

  case 452:
#line 2781 "fgl.yacc"
    {
	char buff[256];
	int n;
	yyval.ptr=A4GL_new_expr(yyvsp[-1].sql_string);
	A4GL_append_expr(yyval.ptr,"{");
	n=print_bind_expr(yyval.ptr,'i');
	sprintf(buff,"A4GL_push_binding(ibind,%d);}",n);
	A4GL_append_expr(yyval.ptr,buff);
	A4GL_append_expr(yyval.ptr,"A4GL_pushop(OP_NOTIN_SELECT);");
}
    break;

  case 453:
#line 2791 "fgl.yacc"
    {
	char buff[256];
	sprintf(buff,"A4GL_push_int(%d);",length_expr(yyvsp[-1].ptr));
	yyval.ptr=A4GL_append_expr(yyvsp[-1].ptr,buff);
	A4GL_append_expr(yyval.ptr,"A4GL_pushop(OP_IN);");
}
    break;

  case 454:
#line 2797 "fgl.yacc"
    {
	char buff[256];
	sprintf(buff,"A4GL_push_int(%d);",length_expr(yyvsp[-1].ptr));
	yyval.ptr=A4GL_append_expr(yyvsp[-1].ptr,buff);
	A4GL_append_expr(yyval.ptr,"A4GL_pushop(OP_NOTIN);");
}
    break;

  case 455:
#line 2807 "fgl.yacc"
    { 
	strcpy(yyval.str,"A4GL_pushop(OP_ISNULL);");
	yyval.ptr=A4GL_new_expr(yyval.str);
}
    break;

  case 456:
#line 2812 "fgl.yacc"
    {
	strcpy(yyval.str,"A4GL_pushop(OP_ISNOTNULL);");
	yyval.ptr=A4GL_new_expr(yyval.str);
}
    break;

  case 457:
#line 2819 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_push_char(\"\\\\\");A4GL_pushop(OP_MATCHES);");
 }
    break;

  case 458:
#line 2822 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_push_char(\"\\\\\");A4GL_pushop(OP_MATCHES);A4GL_pushop(OP_NOT);");
}
    break;

  case 459:
#line 2825 "fgl.yacc"
    {
	char buff[40];
	sprintf(buff,"A4GL_push_char(%s);A4GL_pushop(OP_MATCHES);",yyvsp[0].str);
	yyval.ptr=A4GL_append_expr(yyvsp[-2].ptr,buff);
 }
    break;

  case 460:
#line 2830 "fgl.yacc"
    {
	char buff[40];
	sprintf(buff,"A4GL_push_char(%s);A4GL_pushop(OP_MATCHES);A4GL_pushop(OP_NOT);",yyvsp[0].str);
	yyval.ptr=A4GL_append_expr(yyvsp[-2].ptr,buff);
}
    break;

  case 461:
#line 2837 "fgl.yacc"
    {
	char buff[40];
	sprintf(buff,"A4GL_push_char(\"\\\\\");A4GL_pushop(OP_LIKE);");
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,buff);
}
    break;

  case 462:
#line 2842 "fgl.yacc"
    {
	char buff[40];
	sprintf(buff,"A4GL_push_char(\"\\\\\");A4GL_pushop(OP_LIKE);A4GL_pushop(OP_NOT);");
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,buff);
}
    break;

  case 463:
#line 2847 "fgl.yacc"
    {
	char buff[40];
	sprintf(buff,"A4GL_push_char(%s);A4GL_pushop(OP_LIKE);",yyvsp[0].str);
	yyval.ptr=A4GL_append_expr(yyvsp[-2].ptr,buff);
}
    break;

  case 464:
#line 2852 "fgl.yacc"
    {
	char buff[40];
	sprintf(buff,"A4GL_push_char(%s);A4GL_pushop(OP_LIKE);A4GL_pushop(OP_NOT);",yyvsp[0].str);
	yyval.ptr=A4GL_append_expr(yyvsp[-2].ptr,buff);
}
    break;

  case 465:
#line 2863 "fgl.yacc"
    {
	strcpy(yyval.str,"A4GL_pushop(OP_CLIP);");
	yyval.ptr=A4GL_new_expr(yyval.str);
	inc_counter();
}
    break;

  case 466:
#line 2871 "fgl.yacc"
    {
	sprintf(yyval.str,"%s A4GL_pushop(OP_USING);",yyvsp[0].str);
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_USING);");
}
    break;

  case 467:
#line 2879 "fgl.yacc"
    {
	A4GL_debug("PLUS in math_expr $<ptr>2 = %p",yyvsp[0].ptr);
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_ADD);");
}
    break;

  case 468:
#line 2884 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_SUB);");
}
    break;

  case 469:
#line 2888 "fgl.yacc"
    {
      sprintf(yyval.str,"%s A4GL_A4GL_pushop(OP_MULT);",yyvsp[0].str);
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_MULT);");
}
    break;

  case 470:
#line 2893 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_DIV);");
}
    break;

  case 471:
#line 2897 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_MOD);");
}
    break;

  case 472:
#line 2901 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_POWER);");
}
    break;

  case 473:
#line 2907 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_EQUAL);");
}
    break;

  case 474:
#line 2910 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_EQUAL);");
}
    break;

  case 475:
#line 2914 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_LESS_THAN);");
}
    break;

  case 476:
#line 2918 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_GREATER_THAN);");
}
    break;

  case 477:
#line 2922 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_NOT_EQUAL);");
}
    break;

  case 478:
#line 2926 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_LESS_THAN_EQ);");
}
    break;

  case 479:
#line 2930 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_GREATER_THAN_EQ);");
}
    break;

  case 480:
#line 2937 "fgl.yacc"
    {
	reset_counter();
}
    break;

  case 481:
#line 2947 "fgl.yacc"
    { 
		addmap("Call",yyvsp[-1].str,curr_func,yylineno,infilename);
		new_counter(); 
		}
    break;

  case 482:
#line 2952 "fgl.yacc"
    { 
		sprintf(yyval.str,"%d",get_counter_val()); 
		A4GL_lex_printcomment("/*function_call_expr2 %s*/\n",yyval.str);
		drop_counter(); 
		}
    break;

  case 483:
#line 2958 "fgl.yacc"
    {
		int cnt;
		cnt=1;
		A4GL_debug("Print expr (1)");
		/* print_expr($<ptr>4); */

		strcpy(yyval.str,A4GL_expr_for_call(yyvsp[-5].str,yyvsp[-1].str,lastlineno,infilename));
		yyval.ptr=A4GL_append_expr(yyvsp[-2].ptr,yyval.str);
		inc_counter();
		}
    break;

  case 484:
#line 2968 "fgl.yacc"
    {
        sprintf(yyval.str,"\"%s\",\"%s\"",yyvsp[-3].str,yyvsp[-1].str);
	A4GL_debug("NEWFORMAT : %s\n",yyval.str);
        A4GLSQL_set_status(0,0);
        new_counter();
}
    break;

  case 485:
#line 2973 "fgl.yacc"
    {
	sprintf(yyval.str,"%d",get_counter_val());  
	drop_counter();
}
    break;

  case 486:
#line 2976 "fgl.yacc"
    {
	char buff[256];
        char *ptr;
        strcpy(buff,yyvsp[-3].str);
        ptr=strchr(buff,',');
        *ptr=0;
        ptr++;
	sprintf(yyval.str,"{int _retvars;\n_retvars=A4GL_call_4gl_dll(%s,%s,%d); {\nif (_retvars!= 1 ) {A4GLSQL_set_status(-3001,0);A4GL_chk_err(%d,\"%s\");A4GL_pop_args(_retvars);A4GL_push_null(2,0);}\n}\n}\n", buff,ptr,atoi(yyvsp[-1].str), lastlineno,infilename);
	yyval.ptr=A4GL_append_expr(yyvsp[-2].ptr,yyval.str);
}
    break;

  case 487:
#line 2990 "fgl.yacc"
    {chk4var=1;}
    break;

  case 488:
#line 2990 "fgl.yacc"
    {chk4var=0;}
    break;

  case 489:
#line 2990 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[-2].ptr,"aclfgl_date(1);");
}
    break;

  case 490:
#line 2993 "fgl.yacc"
    {chk4var=1;}
    break;

  case 491:
#line 2993 "fgl.yacc"
    {chk4var=0;}
    break;

  case 492:
#line 2993 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[-2].ptr,"aclfgl_month(1);");
	/* consumes and replaces a fgl_expr_c - so we don't need to dec or inc_counter */
}
    break;

  case 493:
#line 2997 "fgl.yacc"
    {chk4var=1;}
    break;

  case 494:
#line 2997 "fgl.yacc"
    {chk4var=0;}
    break;

  case 495:
#line 2997 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[-2].ptr,"aclfgl_day(1);");
	/* consumes and replaces a fgl_expr_c - so we don't need to dec or inc_counter */
}
    break;

  case 496:
#line 3001 "fgl.yacc"
    {chk4var=1;}
    break;

  case 497:
#line 3001 "fgl.yacc"
    {chk4var=0;}
    break;

  case 498:
#line 3001 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[-2].ptr,"aclfgl_year(1);");
	/* consumes and replaces a fgl_expr_c - so we don't need to dec or inc_counter */
}
    break;

  case 499:
#line 3005 "fgl.yacc"
    {
	char buff[256];
	sprintf(buff,"acli_interval(%s,%s);",yyvsp[-2].str,yyvsp[0].str);
	yyval.ptr=A4GL_new_expr(buff);
	inc_counter();
}
    break;

  case 500:
#line 3011 "fgl.yacc"
    {
	char buff[256];
	sprintf(buff,"acli_datetime(%s,%s);",yyvsp[-2].str,yyvsp[0].str);
	yyval.ptr=A4GL_new_expr(buff);
	inc_counter();
}
    break;

  case 501:
#line 3017 "fgl.yacc"
    {
	char buff[256];
	sprintf(buff,"acli_datetime(\"%s\",%s);",yyvsp[-2].str,yyvsp[0].str);
	yyval.ptr=A4GL_new_expr(buff);
	inc_counter();
}
    break;

  case 502:
#line 3023 "fgl.yacc"
    {
	char buff[256];
	sprintf(buff,"acli_datetime(\"%s:%s\",%s);",yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str);
	yyval.ptr=A4GL_new_expr(buff);
	inc_counter();
}
    break;

  case 503:
#line 3029 "fgl.yacc"
    {
	char buff[256];
	sprintf(buff,"A4GL_isdynarr_allocated(&%s);",yyvsp[-1].str);
        yyval.ptr=A4GL_new_expr(buff);
        inc_counter();
}
    break;

  case 504:
#line 3035 "fgl.yacc"
    { 
        char buff[256];
        sprintf(buff,"A4GL_dynarr_extent(&%s,%d);",yyvsp[-3].str,atoi(yyvsp[-1].str));
        yyval.ptr=A4GL_new_expr(buff);
        inc_counter();
}
    break;

  case 505:
#line 3045 "fgl.yacc"
    {strcpy(yyval.str,"-1");}
    break;

  case 506:
#line 3046 "fgl.yacc"
    {sprintf(yyval.str,"%d",atoi(yyvsp[-2].str)*16+atoi(yyvsp[0].str));}
    break;

  case 509:
#line 3054 "fgl.yacc"
    {
	if (!isin_command("INPUT")&&!isin_command("CONSTRUCT")) { 
   		a4gl_yyerror("get_fldbuf can only be used in an input or construct");
   		YYERROR;
	}
sprintf(yyval.str,"{int _retvars;\n_retvars=A4GL_fgl_getfldbuf(_sio,_inp_io_type,%s,0,0);\nif (_retvars != 1 ) {A4GLSQL_set_status(-3001,0);A4GL_chk_err(%d,\"%s\");}\n}\n",
	yyvsp[-1].str, lastlineno,infilename); 
	yyval.ptr=A4GL_new_expr(yyval.str);	
	inc_counter();

}
    break;

  case 510:
#line 3065 "fgl.yacc"
    {sprintf(yyval.str,"A4GL_push_int(A4GL_fgl_fieldnametoid(\"\",%s));",yyvsp[-1].str); yyval.ptr=A4GL_new_expr(yyval.str); }
    break;

  case 511:
#line 3066 "fgl.yacc"
    {
sprintf(yyval.str,"A4GL_push_int(A4GL_fgl_fieldnametoid(\"\",%s));",yyvsp[-1].str); yyval.ptr=A4GL_new_expr(yyval.str); 
addmap("Get Field",yyvsp[-1].str,curr_func,yylineno,infilename);
	inc_counter();
}
    break;

  case 512:
#line 3072 "fgl.yacc"
    {
/* Informix allows this outside of a input/construct... */
	if (isin_command("INPUT")&&!isin_command("CONSTRUCT")) { 
		sprintf(yyval.str,"A4GL_push_int(A4GL_fgl_infield(_sio,_inp_io_type,%s,0,0));",yyvsp[-1].str); 
	} else {
		sprintf(yyval.str,"A4GL_push_int(A4GL_fgl_infield(0,0,%s,0,0));",yyvsp[-1].str); 
	}
	yyval.ptr=A4GL_new_expr(yyval.str);
	inc_counter();
}
    break;

  case 513:
#line 3083 "fgl.yacc"
    { 
	if (!isin_command("INPUT")&&!isin_command("CONSTRUCT")) { 
   		a4gl_yyerror("field_touched can only be used in an input or construct");
   		YYERROR;
	}
	sprintf(yyval.str,"A4GL_push_int(A4GL_fgl_fieldtouched(_sio,_inp_io_type,%s,0,0));",yyvsp[-1].str); 
	yyval.ptr=A4GL_new_expr(yyval.str);
	inc_counter();
}
    break;

  case 514:
#line 3093 "fgl.yacc"
    { 
	if (!isin_command("INPUT")&&!isin_command("CONSTRUCT")) { 
   		a4gl_yyerror("field_touched can only be used in an input or construct");
   		YYERROR;
	}
	sprintf(yyval.str,"A4GL_push_int(!A4GL_fgl_fieldtouched(_sio,_inp_io_type,%s,0,0));",yyvsp[-1].str); 
	yyval.ptr=A4GL_new_expr(yyval.str);
	inc_counter();
}
    break;

  case 517:
#line 3106 "fgl.yacc"
    {
		inc_counter();
               sprintf(yyval.str,"A4GL_push_current(%s);",yyvsp[0].str);
		yyval.ptr=A4GL_new_expr(yyval.str);
          	}
    break;

  case 518:
#line 3111 "fgl.yacc"
    { inc_counter(); strcpy(yyval.str,"A4GL_push_today();");
		yyval.ptr=A4GL_new_expr(yyval.str);
		}
    break;

  case 519:
#line 3118 "fgl.yacc"
    { 
	yyval.ptr=A4GL_append_expr(yyvsp[-1].ptr,"A4GL_upshift_stk();");
}
    break;

  case 520:
#line 3122 "fgl.yacc"
    { 
	yyval.ptr=A4GL_append_expr(yyvsp[-1].ptr,"A4GL_downshift_stk();");
}
    break;

  case 521:
#line 3125 "fgl.yacc"
    { 
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_push_ascii();");
}
    break;

  case 522:
#line 3128 "fgl.yacc"
    { 
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"aclfgli_extend();"); }
    break;

  case 523:
#line 3134 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[-1].ptr,"A4GL_push_double(-1);A4GL_pushop(OP_MULT);");
}
    break;

  case 524:
#line 3137 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[-1].ptr,"A4GL_push_double(-28.3465);A4GL_pushop(OP_MULT);");
}
    break;

  case 525:
#line 3140 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[-1].ptr,"A4GL_push_double(-72.0);A4GL_pushop(OP_MULT);");
}
    break;

  case 526:
#line 3157 "fgl.yacc"
    {
	strcpy(yyval.str,yyvsp[0].str);
}
    break;

  case 527:
#line 3160 "fgl.yacc"
    {
	strcpy(yyval.str,yyvsp[0].str);
}
    break;

  case 528:
#line 3166 "fgl.yacc"
    {sprintf(yyval.str,"-%s",yyvsp[0].str);}
    break;

  case 529:
#line 3167 "fgl.yacc"
    {sprintf(yyval.str,"\"%s\"",yyvsp[0].str);}
    break;

  case 530:
#line 3168 "fgl.yacc"
    {sprintf(yyval.str,"\"%s\"",yyvsp[0].str);}
    break;

  case 532:
#line 3173 "fgl.yacc"
    {sprintf(yyval.str,"%s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 533:
#line 3174 "fgl.yacc"
    {sprintf(yyval.str,"%s %s:%s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 534:
#line 3175 "fgl.yacc"
    {sprintf(yyval.str,"%s %s:%s:%s",yyvsp[-5].str,yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 535:
#line 3176 "fgl.yacc"
    {sprintf(yyval.str,"%s %s:%s:%s",yyvsp[-5].str,yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 536:
#line 3178 "fgl.yacc"
    {sprintf(yyval.str,"%s:%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 537:
#line 3179 "fgl.yacc"
    {sprintf(yyval.str,"%s:%s:%s",yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 538:
#line 3180 "fgl.yacc"
    {sprintf(yyval.str,"%s:%s:%s",yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 539:
#line 3182 "fgl.yacc"
    {sprintf(yyval.str,"%s:%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 540:
#line 3183 "fgl.yacc"
    {sprintf(yyval.str,"%s",yyvsp[0].str);}
    break;

  case 542:
#line 3189 "fgl.yacc"
    {sprintf(yyval.str,"%s-%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 544:
#line 3194 "fgl.yacc"
    {
	sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);
	}
    break;

  case 545:
#line 3206 "fgl.yacc"
    {
print_for_start(yyvsp[-5].str);
push_blockcommand("FOR");
}
    break;

  case 546:
#line 3210 "fgl.yacc"
    {A4GL_debug("For_cmds\n");}
    break;

  case 547:
#line 3211 "fgl.yacc"
    {

pop_blockcommand("FOR");
print_for_end();
A4GL_lex_printcomment(" /*END FOR*/\n");}
    break;

  case 548:
#line 3218 "fgl.yacc"
    {
		print_for_default_step();
	}
    break;

  case 550:
#line 3235 "fgl.yacc"
    {
push_blockcommand("FOREACH");
}
    break;

  case 551:
#line 3239 "fgl.yacc"
    {
print_foreach_start();
A4GL_lex_printcomment(" /* foreach */\n");
}
    break;

  case 552:
#line 3245 "fgl.yacc"
    {
print_foreach_next(yyvsp[-3].str,yyvsp[-1].str,yyvsp[0].str);
}
    break;

  case 553:
#line 3249 "fgl.yacc"
    {
add_continue_blockcommand ("FOREACH");
print_foreach_end(yyvsp[-6].str);
pop_blockcommand("FOREACH"); 
print_foreach_close(yyvsp[-6].str);
}
    break;

  case 554:
#line 3258 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 555:
#line 3259 "fgl.yacc"
    {
		strcpy(yyval.str,yyvsp[0].str);
	}
    break;

  case 556:
#line 3271 "fgl.yacc"
    {
		sprintf(curr_func,"%s",yyvsp[0].str); 
		print_formhandler(yyvsp[0].str);
		start_state("formhandler",1);
	push_blockcommand("FORMHANDLER");
        }
    break;

  case 557:
#line 3277 "fgl.yacc"
    {
		print_variables();
		print_getwin();
	}
    break;

  case 558:
#line 3285 "fgl.yacc"
    {
pop_blockcommand("FORMHANDLER");
print_end_formhandler(); 
start_state("formhandler",0);}
    break;

  case 565:
#line 3302 "fgl.yacc"
    {
		print_event('B');
        }
    break;

  case 566:
#line 3304 "fgl.yacc"
    {
		print_event_2();
        }
    break;

  case 567:
#line 3307 "fgl.yacc"
    {
		print_event('b');
        }
    break;

  case 568:
#line 3309 "fgl.yacc"
    {
		print_event_2();
        }
    break;

  case 573:
#line 3323 "fgl.yacc"
    {
		print_event('A');
        }
    break;

  case 574:
#line 3325 "fgl.yacc"
    {
		print_event_2();
        }
    break;

  case 575:
#line 3328 "fgl.yacc"
    {
		print_event('a');
        }
    break;

  case 576:
#line 3330 "fgl.yacc"
    {
		print_event_2();
        }
    break;

  case 589:
#line 3361 "fgl.yacc"
    { 
			print_gtk_field('B',0);
		}
    break;

  case 590:
#line 3363 "fgl.yacc"
    {
			print_gtk_field_2();
		}
    break;

  case 591:
#line 3366 "fgl.yacc"
    { 
			print_gtk_field('A',0);
		}
    break;

  case 592:
#line 3368 "fgl.yacc"
    {
			print_gtk_field_2();
		}
    break;

  case 593:
#line 3371 "fgl.yacc"
    {
			print_gtk_field('b',yyvsp[0].str);
		}
    break;

  case 594:
#line 3373 "fgl.yacc"
    { 
			print_gtk_field_2();
		}
    break;

  case 595:
#line 3376 "fgl.yacc"
    {
			print_gtk_field('a',yyvsp[0].str);
		}
    break;

  case 596:
#line 3378 "fgl.yacc"
    { 
			print_gtk_field_2();
		}
    break;

  case 597:
#line 3381 "fgl.yacc"
    { 
			print_gtk_field('o',yyvsp[0].str);
		}
    break;

  case 598:
#line 3383 "fgl.yacc"
    { 
			print_gtk_field_2();
		}
    break;

  case 599:
#line 3398 "fgl.yacc"
    {
		//print_niy("Free Cursor");
		A4GL_lex_printcomment(" /* FIXME: Not implemented: Free Cursor */\n");;

		strcpy(yyval.str,"");
		}
    break;

  case 600:
#line 3414 "fgl.yacc"
    {sprintf(yyval.str,"%d",-1-(atoi(yyvsp[0].str)));}
    break;

  case 601:
#line 3415 "fgl.yacc"
    {strcpy(yyval.str,"-1");}
    break;

  case 602:
#line 3416 "fgl.yacc"
    {sprintf (yyval.str,"%d",atoi(yyvsp[0].str)+1);}
    break;

  case 603:
#line 3417 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 604:
#line 3418 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 605:
#line 3419 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 606:
#line 3420 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 610:
#line 3428 "fgl.yacc"
    {sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str); }
    break;

  case 612:
#line 3434 "fgl.yacc"
    {
			sprintf(yyval.str,"\"%s\",1",yyvsp[0].str);}
    break;

  case 613:
#line 3436 "fgl.yacc"
    { sprintf(yyval.str,"int_to_id(%s)",yyvsp[-1].str); }
    break;

  case 614:
#line 3437 "fgl.yacc"
    { sprintf(yyval.str,"int_to_id(%s.%s)",yyvsp[-5].str,yyvsp[-1].str); }
    break;

  case 615:
#line 3439 "fgl.yacc"
    {sprintf(yyval.str,"\"%s\",%s",yyvsp[-3].str,yyvsp[-1].str);}
    break;

  case 616:
#line 3441 "fgl.yacc"
    {sprintf(yyval.str,"\"%s.*\",1",yyvsp[-2].str);}
    break;

  case 617:
#line 3443 "fgl.yacc"
    {sprintf(yyval.str,"\"%s.*\",%s",yyvsp[-5].str,yyvsp[-3].str);}
    break;

  case 618:
#line 3445 "fgl.yacc"
    {sprintf(yyval.str,"\"%s.%s\",1",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 619:
#line 3447 "fgl.yacc"
    {sprintf(yyval.str,"\"%s.%s\",%s",yyvsp[-5].str,yyvsp[0].str,yyvsp[-3].str);}
    break;

  case 620:
#line 3450 "fgl.yacc"
    {
				print_pushchar(yyvsp[0].str);
				addmap("Cursor",last_var,curr_func,yylineno,infilename);
			}
    break;

  case 621:
#line 3457 "fgl.yacc"
    {sprintf(yyval.str,"%s",yyvsp[0].str);}
    break;

  case 622:
#line 3459 "fgl.yacc"
    {sprintf(yyval.str,"%s",yyvsp[0].str);
addmap("Window",last_var,curr_func,yylineno,infilename);
}
    break;

  case 623:
#line 3465 "fgl.yacc"
    {sprintf(yyval.str,"%s",yyvsp[0].str);
addmap("Open Window",last_var,curr_func,yylineno,infilename);
}
    break;

  case 624:
#line 3470 "fgl.yacc"
    {sprintf(yyval.str,"%s",yyvsp[0].str);
addmap("Form",last_var,curr_func,yylineno,infilename);
}
    break;

  case 625:
#line 3475 "fgl.yacc"
    {sprintf(yyval.str,"%s",yyvsp[0].str);
addmap("Open Form",last_var,curr_func,yylineno,infilename);
}
    break;

  case 626:
#line 3480 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 627:
#line 3480 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 628:
#line 3483 "fgl.yacc"
    { 
			strcpy(yyval.str,downshift(yyvsp[0].str)) ;
}
    break;

  case 629:
#line 3489 "fgl.yacc"
    {
			sprintf(yyval.str,"%s",downshift(yyvsp[0].str)) ;
			}
    break;

  case 630:
#line 3494 "fgl.yacc"
    {
	strcpy(yyval.str,do_clobbering(clobber,downshift(yyvsp[0].str))) ;
	strcpy(last_var,downshift(yyvsp[0].str));
}
    break;

  case 631:
#line 3498 "fgl.yacc"
    {
		sprintf(yyval.str,"aclfgli_str_to_id(%s)",yyvsp[-1].str);
		sprintf(last_var,"->%s",yyvsp[-1].str);
	}
    break;

  case 634:
#line 3506 "fgl.yacc"
    {sprintf(yyval.str,"\"%s\",1",yyvsp[0].str);}
    break;

  case 635:
#line 3508 "fgl.yacc"
    {sprintf(yyval.str,"\"%s\",%s",yyvsp[-3].str,yyvsp[-1].str);}
    break;

  case 636:
#line 3510 "fgl.yacc"
    {sprintf(yyval.str,"\"%s.*\",1",yyvsp[-2].str);}
    break;

  case 637:
#line 3512 "fgl.yacc"
    {sprintf(yyval.str,"\"%s.*\",%s",yyvsp[-5].str,yyvsp[-3].str);}
    break;

  case 638:
#line 3514 "fgl.yacc"
    {sprintf(yyval.str,"\"%s.%s\",1",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 639:
#line 3516 "fgl.yacc"
    {sprintf(yyval.str,"\"%s.%s\",%s",yyvsp[-5].str,yyvsp[0].str,yyvsp[-3].str);}
    break;

  case 640:
#line 3519 "fgl.yacc"
    {
A4GL_debug("Scanvar=%d",scan_variable(yyvsp[0].str)&15);
if ((scan_variable(yyvsp[0].str)&15)!=0) {
a4gl_yyerror("Only a character variable can be used for this");
YYERROR;
}
}
    break;

  case 642:
#line 3528 "fgl.yacc"
    {
		sprintf(yyval.str,".%s",yyvsp[0].str);
}
    break;

  case 643:
#line 3590 "fgl.yacc"
    {
	print_goto(yyvsp[0].str);
}
    break;

  case 644:
#line 3603 "fgl.yacc"
    {
print_gui_do_menuitems(yyvsp[0].str,'C');
}
    break;

  case 646:
#line 3610 "fgl.yacc"
    {sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 647:
#line 3613 "fgl.yacc"
    {
        sprintf(yyval.str,"\"%s\"",yyvsp[0].str);
}
    break;

  case 648:
#line 3619 "fgl.yacc"
    {
print_gui_do_menuitems(yyvsp[0].str,'U');
}
    break;

  case 649:
#line 3625 "fgl.yacc"
    {
print_gui_do_menuitems(yyvsp[0].str,'D');
}
    break;

  case 650:
#line 3629 "fgl.yacc"
    {
print_gui_do_fields(yyvsp[0].str,'D');
}
    break;

  case 651:
#line 3633 "fgl.yacc"
    {
print_gui_do_form(yyvsp[-2].str,yyvsp[0].str,'D');
}
    break;

  case 652:
#line 3639 "fgl.yacc"
    {
print_gui_do_menuitems(yyvsp[0].str,'E');
}
    break;

  case 653:
#line 3643 "fgl.yacc"
    {
print_gui_do_fields(yyvsp[0].str,'E');
}
    break;

  case 654:
#line 3647 "fgl.yacc"
    {
print_gui_do_form(yyvsp[-2].str,yyvsp[0].str,'E');
}
    break;

  case 655:
#line 3652 "fgl.yacc"
    {start_state("messagebox",1);}
    break;

  case 656:
#line 3657 "fgl.yacc"
    {start_state("messagebox",0);}
    break;

  case 675:
#line 3698 "fgl.yacc"
    {
		if_print_stack_cnt++;
		if_print_stack[if_print_stack_cnt][0]=0;
		if_print_stack[if_print_stack_cnt][1]=0;
		if_print_section[if_print_stack_cnt]=0;
		print_if_start();
	}
    break;

  case 676:
#line 3705 "fgl.yacc"
    {
		int a;
		if_print_section[if_print_stack_cnt]=1;
	}
    break;

  case 677:
#line 3708 "fgl.yacc"
    {
		char wt;
		print_if_end();
	        wt=get_curr_report_stack_whytype();
		//if (wt=='P'||wt=='p'||wt=='T') {
		if (wt=='T') {
			if (if_print_stack[if_print_stack_cnt][0]!=if_print_stack[if_print_stack_cnt][0]) {
				a4gl_yyerror("Number of lines printed in an IF.. THEN must be the same for TRUE and FALSE");
				YYERROR;
			}
			
			if (if_print_stack_cnt>=1) {
				if_print_stack[if_print_stack_cnt-1][if_print_section[if_print_stack_cnt-1]]+=if_print_stack[if_print_stack_cnt][0];
			}
		}
		if_print_stack_cnt--;
	}
    break;

  case 679:
#line 3727 "fgl.yacc"
    {
		print_if_else();
	}
    break;

  case 681:
#line 3730 "fgl.yacc"
    {
		print_if_else();
		}
    break;

  case 682:
#line 3732 "fgl.yacc"
    {

		print_if_start();
	}
    break;

  case 683:
#line 3735 "fgl.yacc"
    {
		print_if_end();
	}
    break;

  case 684:
#line 3739 "fgl.yacc"
    {
		print_import(yyvsp[-3].str,atoi(yyvsp[-1].str));
	}
    break;

  case 685:
#line 3742 "fgl.yacc"
    {
		print_import_legacy(yyvsp[0].str);
	}
    break;

  case 686:
#line 3748 "fgl.yacc"
    { add_ex_dtype(yyvsp[0].str); }
    break;

  case 687:
#line 3759 "fgl.yacc"
    {A4GL_debug("init to\n");}
    break;

  case 688:
#line 3760 "fgl.yacc"
    {
	print_init();
 }
    break;

  case 689:
#line 3763 "fgl.yacc"
    {
	print_init_table(yyvsp[0].str);
}
    break;

  case 691:
#line 3769 "fgl.yacc"
    {sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 692:
#line 3773 "fgl.yacc"
    {setrecord(yyval.str,yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 693:
#line 3774 "fgl.yacc"
    {setrecord(yyval.str,yyvsp[-2].str,0);}
    break;

  case 697:
#line 3790 "fgl.yacc"
    {
sprintf(yyval.str,"0");
}
    break;

  case 698:
#line 3792 "fgl.yacc"
    {
sprintf(yyval.str,"1");
}
    break;

  case 701:
#line 3801 "fgl.yacc"
    {
		print_befaft_field_1(yyvsp[0].str);
}
    break;

  case 702:
#line 3803 "fgl.yacc"
    {
	print_befaft_field_2();
}
    break;

  case 703:
#line 3807 "fgl.yacc"
    {
		print_befaft_field_1(yyvsp[0].str);
}
    break;

  case 704:
#line 3809 "fgl.yacc"
    {
	print_befaft_field_2();
}
    break;

  case 705:
#line 3812 "fgl.yacc"
    {
		print_befaft_field_1("AFT_ROW");
}
    break;

  case 706:
#line 3814 "fgl.yacc"
    {
	print_befaft_field_2();
}
    break;

  case 707:
#line 3817 "fgl.yacc"
    {
		A4GL_lex_printcomment("/* before row */ \n");
		print_befaft_field_1("BEF_ROW");
}
    break;

  case 708:
#line 3820 "fgl.yacc"
    {
	print_befaft_field_2();
		}
    break;

  case 709:
#line 3823 "fgl.yacc"
    {
	print_onkey_1(yyvsp[0].str);
}
    break;

  case 710:
#line 3825 "fgl.yacc"
    {
	print_onkey_2();
}
    break;

  case 711:
#line 3828 "fgl.yacc"
    {
		print_befaft_field_1("AFTER_INP");
}
    break;

  case 712:
#line 3830 "fgl.yacc"
    {
	print_befaft_field_2();
}
    break;

  case 713:
#line 3833 "fgl.yacc"
    {
		print_befaft_field_1("BEFORE_INP");
}
    break;

  case 714:
#line 3835 "fgl.yacc"
    {
	print_befaft_field_2();
}
    break;

  case 715:
#line 3838 "fgl.yacc"
    {
		print_befaft_field_1("DO_BEFORE_DELETE");
	}
    break;

  case 716:
#line 3840 "fgl.yacc"
    { print_befaft_field_2(); }
    break;

  case 717:
#line 3841 "fgl.yacc"
    {
		print_befaft_field_1("DO_BEFORE_INSERT");
	}
    break;

  case 718:
#line 3843 "fgl.yacc"
    { print_befaft_field_2(); }
    break;

  case 719:
#line 3844 "fgl.yacc"
    {
		print_befaft_field_1("DO_AFTER_DELETE");
	}
    break;

  case 720:
#line 3846 "fgl.yacc"
    { print_befaft_field_2(); }
    break;

  case 721:
#line 3847 "fgl.yacc"
    {
		print_befaft_field_1("DO_AFTER_INSERT");
	}
    break;

  case 722:
#line 3849 "fgl.yacc"
    { print_befaft_field_2(); }
    break;

  case 723:
#line 3889 "fgl.yacc"
    {sprintf(yyval.str,"BEF_FIELD_CHK(%s)",yyvsp[0].str);}
    break;

  case 724:
#line 3890 "fgl.yacc"
    {
	char buff[80];
	sprintf(buff,"BEF_FIELD_CHK(%s)",yyvsp[0].str);
	A4GL_generate_or(yyval.str,yyvsp[-2].str,buff);
	}
    break;

  case 725:
#line 3898 "fgl.yacc"
    {sprintf(yyval.str,"AFT_FIELD_CHK(%s)",yyvsp[0].str);}
    break;

  case 726:
#line 3899 "fgl.yacc"
    {
	char buff[80];
	sprintf(buff,"AFT_FIELD_CHK(%s)",yyvsp[0].str);
	A4GL_generate_or(yyval.str,yyvsp[-2].str,buff);
	}
    break;

  case 727:
#line 3908 "fgl.yacc"
    {
print_next_field(yyvsp[0].str);
}
    break;

  case 728:
#line 3913 "fgl.yacc"
    {
print_next_form_field(yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 729:
#line 3918 "fgl.yacc"
    {sprintf(yyval.str,"\"+\"");}
    break;

  case 730:
#line 3919 "fgl.yacc"
    {sprintf(yyval.str,"\"-\"");}
    break;

  case 732:
#line 3924 "fgl.yacc"
    {
print_input_1();
}
    break;

  case 733:
#line 3927 "fgl.yacc"
    {
print_input_2(yyvsp[-2].str);
}
    break;

  case 734:
#line 3935 "fgl.yacc"
    {
print_input(1,yyvsp[-2].str,yyvsp[-1].str,0,atoi(yyvsp[0].str));
strcpy(yyval.str,A4GL_get_formloop_str(0));
}
    break;

  case 735:
#line 3940 "fgl.yacc"
    {
print_input(0,yyvsp[-4].str,yyvsp[-1].str,yyvsp[-2].str,atoi(yyvsp[0].str));
strcpy(yyval.str,A4GL_get_formloop_str(0));
}
    break;

  case 736:
#line 3944 "fgl.yacc"
    {
curr_input_array_attribs.maxcount=0;
curr_input_array_attribs.count=0;
curr_input_array_attribs.allow_insert=1;
curr_input_array_attribs.allow_delete=1;
curr_input_array_attribs.curr_row_display=0;
inp_flags=0;}
    break;

  case 737:
#line 3951 "fgl.yacc"
    {
strcpy(yyval.str,print_input_array(fgl_add_scope(yyvsp[-8].str,0),yyvsp[-2].str,yyvsp[-7].str,yyvsp[-5].str,yyvsp[0].str,&curr_input_array_attribs));
}
    break;

  case 738:
#line 3960 "fgl.yacc"
    {
		print_scroll(yyvsp[-1].str,yyvsp[0].str);
	}
    break;

  case 739:
#line 3966 "fgl.yacc"
    {sprintf(yyval.str,"%s",yyvsp[0].str);}
    break;

  case 740:
#line 3967 "fgl.yacc"
    {sprintf(yyval.str,"-%s",yyvsp[0].str);}
    break;

  case 741:
#line 3968 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 742:
#line 3969 "fgl.yacc"
    {strcpy(yyval.str,"-1");}
    break;

  case 743:
#line 3972 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 745:
#line 3975 "fgl.yacc"
    {
	strcpy(yyval.str,"");
}
    break;

  case 746:
#line 3982 "fgl.yacc"
    { curr_input_array_attribs.curr_row_display=strdup(yyvsp[0].str); }
    break;

  case 747:
#line 3983 "fgl.yacc"
    { curr_input_array_attribs.count=strdup(yyvsp[0].str); }
    break;

  case 748:
#line 3984 "fgl.yacc"
    { curr_input_array_attribs.count=strdup(yyvsp[0].str); }
    break;

  case 749:
#line 3985 "fgl.yacc"
    { curr_input_array_attribs.maxcount=strdup(yyvsp[0].str); }
    break;

  case 750:
#line 3986 "fgl.yacc"
    { curr_input_array_attribs.maxcount=strdup(yyvsp[0].str); }
    break;

  case 751:
#line 3987 "fgl.yacc"
    { curr_input_array_attribs.allow_insert=1; }
    break;

  case 752:
#line 3988 "fgl.yacc"
    { curr_input_array_attribs.allow_insert=0; }
    break;

  case 753:
#line 3989 "fgl.yacc"
    { curr_input_array_attribs.allow_delete=1; }
    break;

  case 754:
#line 3990 "fgl.yacc"
    { curr_input_array_attribs.allow_delete=0; }
    break;

  case 755:
#line 3995 "fgl.yacc"
    {iskey=1;}
    break;

  case 756:
#line 3995 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);iskey=0;}
    break;

  case 757:
#line 3997 "fgl.yacc"
    {strcpy(yyval.str,"->ANY");}
    break;

  case 758:
#line 4000 "fgl.yacc"
    {iskey=1;}
    break;

  case 759:
#line 4000 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);iskey=0;}
    break;

  case 760:
#line 4002 "fgl.yacc"
    {sprintf(yyval.str,"A4GL_key_val(\"%s\")",yyvsp[0].str);iskey=0;}
    break;

  case 761:
#line 4006 "fgl.yacc"
    {sprintf(yyval.str,"A4GL_key_val(\"%s\")",yyvsp[0].str);iskey=0;}
    break;

  case 762:
#line 4009 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 763:
#line 4010 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[-1].str);}
    break;

  case 765:
#line 4013 "fgl.yacc"
    {
	sprintf(yyval.str,"%s||%s",yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 771:
#line 4025 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 772:
#line 4026 "fgl.yacc"
    {strcpy(yyval.str,"escape");}
    break;

  case 773:
#line 4027 "fgl.yacc"
    {strcpy(yyval.str,"up");}
    break;

  case 774:
#line 4028 "fgl.yacc"
    {strcpy(yyval.str,"help");}
    break;

  case 775:
#line 4029 "fgl.yacc"
    {strcpy(yyval.str,"down");}
    break;

  case 776:
#line 4030 "fgl.yacc"
    {strcpy(yyval.str,"return");}
    break;

  case 777:
#line 4031 "fgl.yacc"
    {strcpy(yyval.str,"delete");}
    break;

  case 778:
#line 4032 "fgl.yacc"
    {strcpy(yyval.str,"insert");}
    break;

  case 779:
#line 4033 "fgl.yacc"
    {strcpy(yyval.str,"tab");}
    break;

  case 780:
#line 4034 "fgl.yacc"
    {strcpy(yyval.str,"left");}
    break;

  case 781:
#line 4035 "fgl.yacc"
    {strcpy(yyval.str,"right");}
    break;

  case 782:
#line 4036 "fgl.yacc"
    {strcpy(yyval.str,"nextpage");}
    break;

  case 783:
#line 4037 "fgl.yacc"
    {strcpy(yyval.str,"prevpage");}
    break;

  case 784:
#line 4038 "fgl.yacc"
    { rm_quotes(yyvsp[0].str); strcpy(yyval.str,yyvsp[0].str); }
    break;

  case 785:
#line 4042 "fgl.yacc"
    {
char buff[256];
A4GL_debug("Label : %s\n",get_idents(0));
strcpy(buff,get_idents(0));
A4GL_convlower(buff);
print_label(buff);
}
    break;

  case 786:
#line 4060 "fgl.yacc"
    {chk4var=1;}
    break;

  case 787:
#line 4060 "fgl.yacc"
    {chk4var=0;
expand_obind();
A4GL_lex_printcomment("/*let3*/\n");}
    break;

  case 788:
#line 4063 "fgl.yacc"
    {
int to_vars;
	
	A4GL_debug("/*processing let*/\n");
	expand_obind();
	to_vars=how_many_in_bind('o');
	if (to_vars>=1)
	{

		if (!print_let_manyvars(yyvsp[0].str))
		{
	    		a4gl_yyerror("Number of variables in let not equal to number of values\n");YYERROR;
		}

	}
	else
	{
	    print_bind_pop1('o');
		start_bind('o',0);
	}

}
    break;

  case 789:
#line 4087 "fgl.yacc"
    { 
int to_vars;
int cnt;
expand_obind();
to_vars=how_many_in_bind('o');
for (cnt=0;cnt<=to_vars;cnt++) {
	print_push_null(); 
}
sprintf(yyval.str,"%d",to_vars+1);

}
    break;

  case 791:
#line 4105 "fgl.yacc"
    {
		if (!print_linked_cmd('S',yyvsp[0].str)) a4gl_yyerror("Not a linked variable");
	}
    break;

  case 792:
#line 4111 "fgl.yacc"
    {
		 if (!print_linked_cmd('D',yyvsp[0].str)) a4gl_yyerror("Not a linked variable");
	}
    break;

  case 793:
#line 4117 "fgl.yacc"
    {
		 if (!print_linked_cmd('U',yyvsp[0].str)) a4gl_yyerror("Not a linked variable");
}
    break;

  case 794:
#line 4123 "fgl.yacc"
    {
int vtype;
vtype=scan_variable(yyvsp[-1].str);
if (vtype!=11&&vtype!=12) {
a4gl_yyerror("Only Byte & Text may be located...");
YYERROR;
}
print_locate('M',yyvsp[-1].str,"0");


}
    break;

  case 795:
#line 4134 "fgl.yacc"
    {
int vtype;
vtype=scan_variable(yyvsp[-2].str);
if (vtype!=11&&vtype!=12) {
a4gl_yyerror("Only Byte & Text may be located...");
YYERROR;
}

print_locate('F',yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 796:
#line 4157 "fgl.yacc"
    {
		if (glob_only==1) {
       			A4GL_debug("Read globals section so Im done\n");
       			YYACCEPT;
		}
	
		set_4gl_vars();

		set_current_variable_scope('g'); print_variables (); set_current_variable_scope('G'); print_variables (); set_current_variable_scope('m'); print_variables ();
print_module_variable_init();
		set_current_variable_scope('m');
	}
    break;

  case 799:
#line 4173 "fgl.yacc"
    {
	}
    break;

  case 806:
#line 4196 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 810:
#line 4204 "fgl.yacc"
    {
		print_at_termination(yyvsp[0].str);
	}
    break;

  case 828:
#line 4230 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 829:
#line 4231 "fgl.yacc"
    {
strcpy(yyval.str,"static ");
}
    break;

  case 830:
#line 4239 "fgl.yacc"
    {
  clr_variable(); lastlineno=yylineno;
  clr_function_constants (); 
}
    break;

  case 831:
#line 4244 "fgl.yacc"
    { 
if (is_builtin_func(yyvsp[-1].str)&&!compiling_system_4gl) {
	a4gl_yyerror("You can't use this name - this is the name of a builtin Aubit4GL function");
}

if (strcmp(yyvsp[-3].str,"static ")!=0) {
	// We don't export static functions
	variable_action(-1,yyvsp[-1].str,"","","add_function");
}
  sprintf(curr_func,"%s",yyvsp[-1].str);
  addmap("Declare Function",curr_func,"MODULE",yylineno,infilename);
  print_func_start(yyvsp[-3].str,yyvsp[-1].str,0);
  printDeclareFunctionStack(yyvsp[-1].str);
  cnt=0;
}
    break;

  case 832:
#line 4260 "fgl.yacc"
    {
  A4GL_lex_printcomment("/* new function %s parameters*/\n",yyvsp[-1].str);
  push_blockcommand("FUNC");
  A4GL_lex_printcomment("/* define section */\n");
}
    break;

  case 833:
#line 4266 "fgl.yacc"
    {
  int c;
  A4GL_lex_printcomment("/*end of define section */\n");
	print_variables();
  c=print_param('f');
  printPushFunction();
  print_func_args(c);
}
    break;

  case 835:
#line 4281 "fgl.yacc"
    {
    printPopFunction();
    print_func_defret0();
    pop_blockcommand("FUNC");
    print_func_end();
    clr_function_constants ();
    A4GL_lex_printcomment("/*end function*/\n");
  }
    break;

  case 836:
#line 4294 "fgl.yacc"
    { 
    lastlineno=yylineno;
    variable_action(-1,yyvsp[0].str,"","","add_function");
    sprintf(curr_func,"MAIN");
    clr_variable(); 
    push_blockcommand("MAIN"); 
    addmap("MAIN",curr_func,"MODULE",yylineno,infilename);
    print_main_1();
  }
    break;

  case 837:
#line 4304 "fgl.yacc"
    {
	print_variables();
    printDeclareFunctionStack("MAIN");
    print_fgllib_start(hdr_dbname);
    printInitFunctionStack();
    printPushFunction();
  }
    break;

  case 838:
#line 4311 "fgl.yacc"
    {
pop_blockcommand("MAIN");
print_main_end();
A4GL_lex_printcomment("/*end main */\n");}
    break;

  case 839:
#line 4318 "fgl.yacc"
    {
    printPopFunction();
    print_return(atoi(yyvsp[0].str));
  }
    break;

  case 840:
#line 4324 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 841:
#line 4324 "fgl.yacc"
    {
A4GL_lex_printcomment("/* Got expr list */");
sprintf(yyval.str,"%s",yyvsp[0].str);}
    break;

  case 842:
#line 4329 "fgl.yacc"
    {
					open_db(yyvsp[0].str);
					strcpy(hdr_dbname,yyvsp[0].str);
					lastlineno=yylineno;
					is_schema=0;
			}
    break;

  case 843:
#line 4335 "fgl.yacc"
    {
					open_db(yyvsp[0].str);
					strcpy(hdr_dbname,yyvsp[0].str);
					lastlineno=yylineno;
					is_schema=1;
			}
    break;

  case 844:
#line 4343 "fgl.yacc"
    {
}
    break;

  case 850:
#line 4355 "fgl.yacc"
    {
strcpy(curr_func,"[Globals]");
set_current_variable_scope('g');
A4GL_lex_printcomment("/* start of globals */\n");
}
    break;

  case 852:
#line 4363 "fgl.yacc"
    {
 A4GL_lex_printcomment("/* end of globals */");
	A4GL_debug("end of globals\n");
	lastlineno=yylineno;
	set_current_variable_scope('m');
}
    break;

  case 853:
#line 4369 "fgl.yacc"
    {
char b[256];
	lastlineno=yylineno;
	strcpy(b,yyvsp[0].str);
	set_current_variable_scope('G');
	tr_glob_fname(b);
	A4GL_debug("Reading globals file %s\n",b);
	rm_quote(b);
	read_glob(b);
	set_current_variable_scope('m');
}
    break;

  case 854:
#line 4383 "fgl.yacc"
    {
  addmap("Define Member Function",curr_func,"MODULE",yylineno,infilename);
}
    break;

  case 855:
#line 4387 "fgl.yacc"
    {
  char buff[80];
  sprintf(buff,"%s_%s_%d",yyvsp[-4].str,yyvsp[-6].str,atoi(yyvsp[-1].str));
  sprintf(curr_func,"%s",buff);
  print_func_start("",buff,1);
  printDeclareFunctionStack(buff);

  cnt=0;
  A4GL_lex_printcomment("/* new function %s parameters*/\n",yyvsp[-1].str);
  push_blockcommand("FUNC");
  A4GL_lex_printcomment("/* define section */\n");
}
    break;

  case 856:
#line 4400 "fgl.yacc"
    {
	print_variables();
  A4GL_lex_printcomment("/*end of define section */\n");
  print_param('f');
  printPushFunction();
  print_func_args(atoi(yyvsp[-3].str));
}
    break;

  case 858:
#line 4418 "fgl.yacc"
    {
	start_state("menu",1);
   	menu_cnt=npush_menu();
   	menu_cmd_cnt[menu_cnt]=1;
   	push_blockcommand("MENU");
        menu_blk[menu_cnt]=get_blk_no();
	do_print_menu_1();
	}
    break;

  case 859:
#line 4426 "fgl.yacc"
    {
	start_state("menu",0);
	}
    break;

  case 860:
#line 4432 "fgl.yacc"
    {
   print_end_menu_1(menu_blk[menu_cnt]);
   add_continue_blockcommand ("MENU");
print_end_menu_2(menu_blk[menu_cnt]);
   pop_blockcommand("MENU");
   pop_menu();
}
    break;

  case 861:
#line 4443 "fgl.yacc"
    {
	 A4GL_lex_printcomment("/* Block%d_m2 (Before menu) */",menu_cnt);
		print_menu_block(menu_blk[menu_cnt],-2) ;
                  }
    break;

  case 862:
#line 4447 "fgl.yacc"
    {
		do_print_menu_block_end();
	}
    break;

  case 863:
#line 4454 "fgl.yacc"
    {
A4GL_debug("Menu=%d menu cnt=%d",menu_cnt,menu_cmd_cnt[menu_cnt]);
		push_command(menu_cnt,menu_cmd_cnt[menu_cnt],yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);
	 A4GL_lex_printcomment("/* Block%d_%d */",menu_cnt,menu_cmd_cnt[menu_cnt]-1);
		print_menu_block(menu_blk[menu_cnt],menu_cmd_cnt[menu_cnt]-1);
		menu_cmd_cnt[menu_cnt]++;
		}
    break;

  case 864:
#line 4461 "fgl.yacc"
    {
		do_print_menu_block_end();
}
    break;

  case 865:
#line 4467 "fgl.yacc"
    {
		push_command(menu_cnt,menu_cmd_cnt[menu_cnt],yyvsp[-1].str,"\"\"","\"\"",0);
		print_menu_block(menu_blk[menu_cnt],menu_cmd_cnt[menu_cnt]-1);
		menu_cmd_cnt[menu_cnt]++;
		}
    break;

  case 866:
#line 4472 "fgl.yacc"
    {
		do_print_menu_block_end();
}
    break;

  case 869:
#line 4479 "fgl.yacc"
    {strcpy(yyval.str,"\"EMPTY\"");}
    break;

  case 870:
#line 4480 "fgl.yacc"
    {sprintf(yyval.str,"\"%s\"",yyvsp[0].str);}
    break;

  case 871:
#line 4482 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str); }
    break;

  case 872:
#line 4483 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 873:
#line 4486 "fgl.yacc"
    {strcpy(yyval.str,"\"\"");}
    break;

  case 874:
#line 4487 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 875:
#line 4488 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 876:
#line 4490 "fgl.yacc"
    {
	print_option_op('N',yyvsp[0].str,menu_blk[menu_cnt]);
}
    break;

  case 877:
#line 4495 "fgl.yacc"
    {
	print_option_op('S',yyvsp[0].str,menu_blk[menu_cnt]);
}
    break;

  case 878:
#line 4500 "fgl.yacc"
    {
	print_option_op('H',yyvsp[0].str,menu_blk[menu_cnt]);
}
    break;

  case 879:
#line 4507 "fgl.yacc"
    {sprintf(yyval.str,"MENU_ALL");}
    break;

  case 883:
#line 4514 "fgl.yacc"
    {sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 884:
#line 4516 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);  
push_menu_title(yyval.str);}
    break;

  case 885:
#line 4518 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str); 
push_menu_title(yyval.str);}
    break;

  case 886:
#line 4527 "fgl.yacc"
    {
                strcpy(menuhandler,yyvsp[0].str);
	sprintf(curr_func,"%s",yyvsp[0].str); 
	print_gtk_menuhandler_1(yyvsp[0].str);
                push_blockcommand("MENUH");
}
    break;

  case 887:
#line 4533 "fgl.yacc"
    {
		print_variables();
        }
    break;

  case 888:
#line 4537 "fgl.yacc"
    {
                        pop_blockcommand("MENUH");
			print_gtk_menuhandler_end();
                }
    break;

  case 891:
#line 4549 "fgl.yacc"
    {

		print_gtk_menuhandler_bsm();

                push_blockcommand("BSM");
        }
    break;

  case 892:
#line 4554 "fgl.yacc"
    {
                pop_blockcommand("BSM");
		print_gtk_menuhandler_bsm_end();

        }
    break;

  case 893:
#line 4559 "fgl.yacc"
    {
print_gtk_menuhandler_on(yyvsp[0].str);
                push_blockcommand("ON");
        }
    break;

  case 894:
#line 4562 "fgl.yacc"
    {
                pop_blockcommand("ON");
		print_gtk_menuhandler_on_end();
}
    break;

  case 896:
#line 4574 "fgl.yacc"
    {
		print_message(0,"0",0,message_cnt);
	   }
    break;

  case 897:
#line 4577 "fgl.yacc"
    { 
		print_message(0,yyvsp[-1].str,atoi(yyvsp[0].str),message_cnt);
	  }
    break;

  case 898:
#line 4580 "fgl.yacc"
    { 
		print_message(0,"0",atoi(yyvsp[0].str),message_cnt);
	  }
    break;

  case 905:
#line 4596 "fgl.yacc"
    {
		strcpy(yyval.str,yyvsp[0].str);
		message_cnt=atoi(yyvsp[0].str);
		}
    break;

  case 906:
#line 4601 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 907:
#line 4601 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 908:
#line 4604 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 909:
#line 4631 "fgl.yacc"
    {
char buff[256];
char buff2[256];
char c;
int n;

if (strcmp(yyvsp[0].str,"status")==0) { strcpy(yyvsp[0].str,"a4gl_status"); }
if (strncmp(yyvsp[0].str,"sqlca.",6)==0) { 
	char xbuff[256];
	char xbuff2[256];
	strcpy(xbuff,"a4gl_sqlca.");
	strcpy(xbuff2,yyvsp[0].str);
	strcat(xbuff,&xbuff2[6]);
	strcpy(yyvsp[0].str,xbuff);
}
strcpy(buff,yyvsp[0].str);
A4GL_lex_printcomment("/* .. var %s*/",buff);
if (buff[0]!=' ') addmap("Use Variable",buff,curr_func,yylineno,infilename);

if (strncmp(buff," ASSOCIATE_",11)!=0) {
 A4GL_convlower(buff);
}

strcpy(yyval.str,buff);
A4GL_debug("Checking variable '%s'",buff);
strcpy(buff2,buff);
n=scan_variable(buff2);

  A4GL_debug("scan variable returns -> %d\n",n);

  if (n == -1&&buff[0]!=' ') {
           sprintf(buff2,"'%s' does not represent a defined variable (1)",buff);
           a4gl_yyerror(buff2);
           exit (0);
  }

  strcpy(buff2,yyvsp[0].str);


  if (strstr(buff,".*") && n!=-2) {
		char *ptr;
		strcpy(buff,yyvsp[0].str);
		printf("WARNING : Using a .* on a non-record - %s\n",yyvsp[0].str);
		ptr=strstr(buff,".*");
		*ptr=0;
                
		sprintf(yyval.str,"%s",fgl_add_scope(buff,0));
  } else {
                	sprintf(yyval.str,"%s",fgl_add_scope(yyvsp[0].str,0));
  }

 
  mcnt = 0;
}
    break;

  case 911:
#line 4689 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 913:
#line 4696 "fgl.yacc"
    { 
         sprintf (yyval.str, "%s.%s", yyvsp[-1].str, yyvsp[0].str); 
         A4GL_lex_printcomment("/* record building -> %s */\n",yyval.str);
         }
    break;

  case 914:
#line 4700 "fgl.yacc"
    {

         int type,arrsize,size,level;
         char buff[256];
         char buff2[256];
         char arrbuff[256];

         A4GL_lex_printcomment("/* OPEN_SQUARE.. */\n");

	if (strcmp(yyvsp[-4].str,"sqlca")==0) {
		strcpy(yyvsp[-4].str,"a4gl_sqlca");
	}
         sprintf(buff,"%s.%s",yyvsp[-4].str,yyvsp[-3].str);
         if (scan_variable(buff)==-1) {
	
           sprintf(buff2,"'%s' does not represent a defined variable (2)",buff);
           a4gl_yyerror(buff2);
           YYERROR;
         }

         A4GL_lex_printcomment("/*variable with [...]*/");
         get_variable_dets (buff,&type,&arrsize,&size,&level,arrbuff);
         A4GL_lex_printcomment("/* Arrsize = %d size = %d*/",arrsize,size);
	 
         if (arrsize>0)
         {
             A4GL_debug("Is array...");
             sprintf (yyval.str, "%s[%s]", buff, change_arr_elem(yyvsp[-1].str));
             A4GL_lex_printcomment ("/* array variable %s num_arr_elem=%d arrbuff=%d*/\n", yyval.str,num_arr_elem(yyvsp[-1].str),num_arr_elem(arrbuff));
         }
         else
         {
             A4GL_debug ("Is string...");
             sprintf (yyval.str, " a4gl_substr(%s , %d , %s , 0 ) /*1*/", fgl_add_scope(buff,0), (int)scan_variable (buff), yyvsp[-1].str);
      		dec_counter();

             addmap("Use Variable",buff,curr_func,yylineno,infilename);
             A4GL_lex_printcomment ("/*character variable %s*/\n", yyval.str);
         }

         mcnt++;
}
    break;

  case 915:
#line 4743 "fgl.yacc"
    {

         int type,arrsize,size,level;
         char buff[256];
         char buff2[256];
         char arrbuff[256];

         A4GL_lex_printcomment("/* OPEN_SQUARE.. */\n");

	if (strcmp(yyvsp[-7].str,"sqlca")==0) {
		strcpy(yyvsp[-7].str,"a4gl_sqlca");
	}
         sprintf(buff,"%s.%s",yyvsp[-7].str,yyvsp[-6].str);
         if (scan_variable(buff)==-1) {
           sprintf(buff2,"'%s' does not represent a defined variable (2)",buff);
           a4gl_yyerror(buff2);
           YYERROR;
         }

         A4GL_lex_printcomment("/*variable with [...]*/");
         get_variable_dets (buff,&type,&arrsize,&size,&level,arrbuff);
         A4GL_lex_printcomment("/* Arrsize = %d size = %d*/",arrsize,size);
	 
         if (arrsize>0)
         {
		char buff2[256];
             A4GL_debug("Is array...");
             sprintf (buff2, "%s[%s]", buff, change_arr_elem(yyvsp[-4].str));
             sprintf (yyval.str, " a4gl_substr(%s , %d , %s , 0 ) /*1*/", fgl_add_scope(buff2,0), (int)scan_variable (buff2), yyvsp[-4].str);
             A4GL_lex_printcomment ("/* array variable %s num_arr_elem=%d arrbuff=%d*/\n", yyval.str,num_arr_elem(yyvsp[-4].str),num_arr_elem(arrbuff));
      	dec_counter();
         }
         else
         {
		a4gl_yyerror("Expecting an array of chars...");
		YYERROR;

         }

         mcnt++;
}
    break;

  case 919:
#line 4791 "fgl.yacc"
    {
char buff2[256];
         if (scan_variable(yyvsp[-3].str)==-1) {
           sprintf(buff2,"'%s' does not represent a defined variable (3)",yyvsp[-3].str);
           a4gl_yyerror(buff2); 
           YYERROR;
         }

A4GL_lex_printcomment("/*Associative Variable : %s*/\n",yyvsp[-1].str);
sprintf(yyval.str," ASSOCIATE_%s(%s,1)",upshift(yyvsp[-3].str),yyvsp[-1].str);
}
    break;

  case 920:
#line 4805 "fgl.yacc"
    {
char buff2[256];
         if (scan_variable(yyvsp[-3].str)==-1) {
           sprintf(buff2,"'%s' does not represent a defined variable (4)",yyvsp[-3].str);
           a4gl_yyerror(buff2); 
           YYERROR;
         }
A4GL_lex_printcomment("/*Associative Variable : %s*/\n",yyvsp[-1].str);
sprintf(yyval.str," ASSOCIATE_%s(%s,0)",upshift(yyvsp[-3].str),yyvsp[-1].str);
}
    break;

  case 925:
#line 4829 "fgl.yacc"
    {
int type,arrsize,size,level;
char buff2[256];
char arrbuff[256];

  A4GL_debug("ARRAY (array_r_variable) : %s %s",yyvsp[-1].str,yyvsp[0].str);
  //printf("ARRAY (array_r_variable) : %s %s",$<str>1,$<str>2);
  A4GL_lex_printcomment("/*array variable nnn */");
  get_variable_dets (yyvsp[-1].str,&type,&arrsize,&size,&level,arrbuff);
  A4GL_lex_printcomment("/*here %s %x */",yyvsp[-1].str,type);
  if (scan_variable(yyvsp[-1].str)==-1) {
           sprintf(buff2,"'%s' does not represent a defined variable (7)",yyvsp[-1].str);
           a4gl_yyerror(buff2); 
           YYERROR;

	}


  A4GL_debug("Type=%d (%d) arrsize=%d",type,type&0xffff,arrsize);

  if (strchr(yyvsp[0].str,':'))  {
	char lbuff[256];
	char rbuff[256];
	char tmpbuff[256];
	char *ptr;
	strcpy(lbuff,yyvsp[0].str);
	strcpy(rbuff,strchr(yyvsp[0].str,':')+1);
	ptr=strchr(lbuff,':');
	*ptr=0;
        sprintf (tmpbuff, "%s[%s]", yyvsp[-1].str, change_arr_elem(lbuff));
        sprintf (yyval.str, " a4gl_substr(%s , 0x%x , %s , 0 ) /*1.1*/", fgl_add_scope(tmpbuff,0), (int)scan_variable (tmpbuff), rbuff);
      	dec_counter();
  } else {
 
  if (((type & 0xffff) != 0) || (arrsize>0))
    {
		A4GL_debug("MJA Path 1");
      A4GL_lex_printcomment("/* changing optbase for array: %s */\n",yyvsp[0].str);
      sprintf (yyval.str, "%s[%s]", yyvsp[-1].str, change_arr_elem(yyvsp[0].str));
      A4GL_lex_printcomment ("/* array variable %s*/\n", yyval.str);
    }
  else
    {
             sprintf (yyval.str, " a4gl_substr(%s , %d , %s , 0 ) /*1.2*/", fgl_add_scope(yyvsp[-1].str,0), (int)scan_variable (yyvsp[-1].str), yyvsp[0].str);
             addmap("Use Variable",yyvsp[-1].str,curr_func,yylineno,infilename);
      A4GL_lex_printcomment ("/*character variable %s*/\n", yyval.str);
      	dec_counter();
      	mcnt--;
    }
}

  mcnt++;
}
    break;

  case 926:
#line 4889 "fgl.yacc"
    {
  int type,arrsize,size,level;
  //char buff2[256];
  char arrbuff[256];
//printf("ARRAY (array_r_variable) : %s %s",$<str>1,$<str>2);
  A4GL_lex_printcomment("/*array variable nnn */");
  get_variable_dets (yyvsp[-1].str,&type,&arrsize,&size,&level,arrbuff);
  A4GL_lex_printcomment("/*here %s %x */",yyvsp[-1].str,type);
  if (scan_variable(yyvsp[-1].str)==-1) {
	sprintf(yyval.str,"%s[%s]",yyvsp[-1].str,yyvsp[0].str);
  } else {


  A4GL_debug("Type=%d (%d) arrsize=%d",type,type&0xffff,arrsize);

  if (strchr(yyvsp[0].str,':'))  {
	char lbuff[256];
	char rbuff[256];
	char tmpbuff[256];
	char *ptr;
	strcpy(lbuff,yyvsp[0].str);
	strcpy(rbuff,strchr(yyvsp[0].str,':')+1);
	ptr=strchr(lbuff,':');
	*ptr=0;
        sprintf (tmpbuff, "%s[%s]", yyvsp[-1].str, change_arr_elem(lbuff));
             sprintf (yyval.str, " a4gl_substr(%s , %d , %s , 0 ) /*1.3*/", fgl_add_scope(tmpbuff,0), (int)scan_variable (tmpbuff), rbuff);
      	dec_counter();
  } else {
 
  if (((type & 0xffff) != 0) || (arrsize>0))
    {
      A4GL_lex_printcomment("/* changing optbase for array: %s */\n",yyvsp[0].str);
      sprintf (yyval.str, "%s[%s]", yyvsp[-1].str, change_arr_elem(yyvsp[0].str));
      A4GL_lex_printcomment ("/* array variable %s*/\n", yyval.str);
    }
  else
    {
             sprintf (yyval.str, " a4gl_substr(%s , %d , %s , 0 ) /*1.4*/", fgl_add_scope(yyvsp[-1].str,0), (int)scan_variable (yyvsp[-1].str), yyvsp[0].str);
             addmap("Use Variable",yyvsp[-1].str,curr_func,yylineno,infilename);
      A4GL_lex_printcomment ("/*character variable %s*/\n", yyval.str);
      	dec_counter();
      	mcnt--;
    }
  }
}

  mcnt++;
}
    break;

  case 927:
#line 4945 "fgl.yacc"
    {
	 A4GL_debug("---> Subscript or substring");
		strcpy(yyval.str,yyvsp[-1].str);
	}
    break;

  case 928:
#line 4950 "fgl.yacc"
    {
	 A4GL_debug("---> Subscript & substring");
		sprintf(yyval.str,"%s:%s",yyvsp[-4].str,yyvsp[-1].str);
	}
    break;

  case 929:
#line 4958 "fgl.yacc"
    {
A4GL_debug("List element");
  sprintf (yyval.str, "%s", yyvsp[0].str);
}
    break;

  case 930:
#line 4963 "fgl.yacc"
    {
A4GL_debug("List element continues");
  sprintf (yyval.str, "%s,%s", yyvsp[-2].str, yyvsp[0].str); 
}
    break;

  case 931:
#line 4971 "fgl.yacc"
    {
  sprintf (yyval.str, "%s", yyvsp[0].str);
}
    break;

  case 932:
#line 4977 "fgl.yacc"
    {
char buff[256];
char c;
if (strcmp(yyvsp[0].str,"status")==0) { strcpy(yyvsp[0].str,"a4gl_status"); }
if (strncmp(yyvsp[0].str,"sqlca.",6)==0) {
        char xbuff[256];
        char xbuff2[256];
        strcpy(xbuff,"a4gl_sqlca.");
        strcpy(xbuff2,yyvsp[0].str);
        strcat(xbuff,&xbuff2[6]);
        strcpy(yyvsp[0].str,xbuff);
}
strcpy(buff,yyvsp[0].str);
addmap("Let Variable",buff,curr_func,yylineno,infilename);
if (strncmp(buff," ASSOCIATE_",11)!=0) {
A4GL_convlower(buff);
}
strcpy(yyval.str,buff);
A4GL_lex_printcomment("/* %s */\n",yyvsp[0].str);


  if (scan_variable (buff) == -1&&buff[0]!=' ')
    {
      A4GL_lex_printcomment ("/*NOt a variable*/");
      sprintf(buff,"%s is not a variable",yyvsp[0].str);
      a4gl_yyerror(buff);
    }


  sprintf(yyval.str,"%s",fgl_add_scope(yyvsp[0].str,0));
  mcnt = 0;
}
    break;

  case 933:
#line 5010 "fgl.yacc"
    {
	 A4GL_debug("Array..");
}
    break;

  case 934:
#line 5013 "fgl.yacc"
    { sprintf (yyval.str, "%s.%s", yyvsp[-2].str, yyvsp[0].str); }
    break;

  case 935:
#line 5015 "fgl.yacc"
    {
  int a;
  int b;
  char buff[256];
  char buff2[256];
  A4GL_lex_printcomment("/*array variable .let. */");
  if (strcmp(yyvsp[-5].str,"status")==0) { strcpy(yyvsp[-5].str,"a4gl_status"); }
  if (strcmp(yyvsp[-5].str,"sqlca")==0) {
        strcpy(yyvsp[-5].str,"a4gl_sqlca");
  }
  sprintf(yyval.str,"%s.%s",yyvsp[-5].str,yyvsp[-3].str);

         if (scan_variable(yyval.str)==-1) {
           sprintf(buff2,"'%s' does not represent a defined variable (5)",yyval.str);
           a4gl_yyerror(buff2); 
           YYERROR;
         }

  A4GL_debug("?1arrvar=%s",yyval.str);
  b = isarrvariable (yyval.str);
  a = scan_variable (yyval.str);

  A4GL_lex_printcomment("/*a=%x b=%x */\n",a,b);

  if (b != 0)
    {
      sprintf (yyval.str, "%s.%s[%s-1] ", yyvsp[-5].str, yyvsp[-3].str,yyvsp[-1].str);
      A4GL_lex_printcomment ("/* array variable %s*/\n", yyval.str);
    }
  else
    {
      sprintf(buff,"%s.%s",yyvsp[-5].str,yyvsp[-3].str);
      sprintf (yyval.str, " a4gl_let_substr(%s,%d,%s,0) /* M4 */", fgl_add_scope(buff,0), a, yyvsp[-1].str);
      addmap("Let Variable",buff,curr_func,yylineno,infilename);
      A4GL_lex_printcomment ("/*character variable %s*/\n", yyval.str);
    }

  mcnt++;

}
    break;

  case 936:
#line 5056 "fgl.yacc"
    {
  int a;
  int b;
  char buff[256];
  char buff2[256];
  A4GL_lex_printcomment("/*array variable .let. */");
  if (strcmp(yyvsp[-8].str,"status")==0) { strcpy(yyvsp[-8].str,"a4gl_status"); }
  if (strcmp(yyvsp[-8].str,"sqlca")==0) {
        strcpy(yyvsp[-8].str,"a4gl_sqlca");
  }
  sprintf(yyval.str,"%s.%s",yyvsp[-8].str,yyvsp[-6].str);

         if (scan_variable(yyval.str)==-1) {
           sprintf(buff2,"'%s' does not represent a defined variable (5)",yyval.str);
           a4gl_yyerror(buff2); 
           YYERROR;
         }

  A4GL_debug("?1arrvar=%s",yyval.str);
  b = isarrvariable (yyval.str);
  a = scan_variable (yyval.str);

  A4GL_lex_printcomment("/*a=%x b=%x */\n",a,b);

  if (b != 0)
    {
      sprintf (buff, "%s.%s[%s-1] ", yyvsp[-8].str, yyvsp[-6].str,yyvsp[-4].str);
      sprintf (yyval.str, " a4gl_let_substr(%s,%x,%s,0) /* M1 */", fgl_add_scope(buff,0), a, yyvsp[-1].str);
      A4GL_lex_printcomment ("/* subscript on array variable %s*/\n", yyval.str);
    }
  else
    {
		a4gl_yyerror("I was really hoping for an array");
		YYERROR;

    }

  mcnt++;

}
    break;

  case 941:
#line 5109 "fgl.yacc"
    {
/*OPEN_SQUARE num_list CLOSE_SQUARE*/
  int a;
  int b;
  char buff2[256];
  A4GL_lex_printcomment("/*.let. array variable */");

  A4GL_debug("?2 arrvar=%s",yyvsp[-1].str);
  if (strchr(yyvsp[0].str,':'))  {
	char lbuff[256];
	char rbuff[256];
	char tmpbuff[256];
	char *ptr;
	strcpy(lbuff,yyvsp[0].str);
	strcpy(rbuff,strchr(yyvsp[0].str,':')+1);
	ptr=strchr(lbuff,':');
	*ptr=0;
        sprintf (tmpbuff, "%s[%s]", yyvsp[-1].str, change_arr_elem(lbuff));
        sprintf (yyval.str, " a4gl_let_substr(%s,%d,%s,0) /* M2 */", fgl_add_scope(tmpbuff,0), (int)scan_variable (tmpbuff), rbuff);
  } else {
  	b = isarrvariable (yyvsp[-1].str);
  	a = scan_variable (yyvsp[-1].str);

         if (a==-1) {
           sprintf(buff2,"'%s' does not represent a defined variable (6)",yyvsp[-1].str);
           a4gl_yyerror(buff2); 
           YYERROR;
         }


  A4GL_debug("/*a=%d b=%d*/\n",a,b);

  if (b != 0)
    {
      sprintf (yyval.str, "%s[%s]", yyvsp[-1].str, A4GL_decode_array_string(yyvsp[0].str));
      A4GL_debug ("/* array variable %s*/\n", yyval.str);
    }
  else
    {
      sprintf (yyval.str, " a4gl_let_substr(%s,%d,%s,0) /* M3 */", fgl_add_scope(yyvsp[-1].str,0), (int)scan_variable (yyvsp[-1].str), yyvsp[0].str);

      addmap("Let Variable",yyvsp[-1].str,curr_func,yylineno,infilename);
      A4GL_debug ("/*character variable %s*/\n", yyval.str);
    }
 }
  mcnt++;

}
    break;

  case 942:
#line 5161 "fgl.yacc"
    {
start_bind('f',0);
start_bind('O',0);
strcpy(yyval.str,"0");}
    break;

  case 944:
#line 5168 "fgl.yacc"
    {
start_bind('f',yyvsp[0].str);
start_bind('O',yyvsp[0].str);
sprintf(yyval.str,"1");
}
    break;

  case 945:
#line 5174 "fgl.yacc"
    {
int c;
c=add_bind('f',yyvsp[0].str);
c=add_bind('O',yyvsp[0].str);
sprintf(yyval.str,"%d",c); 
}
    break;

  case 946:
#line 5185 "fgl.yacc"
    {
A4GL_lex_printcomment("/*STarted bind %s*/\n",yyvsp[0].str);
start_bind('i',yyvsp[0].str);
A4GL_lex_printcomment("/*STarted bind 2*/\n");
strcpy(yyval.str,"");
}
    break;

  case 947:
#line 5192 "fgl.yacc"
    {
A4GL_lex_printcomment("/* Added */\n");
add_bind('i',yyvsp[0].str);
strcpy(yyval.str,"");
}
    break;

  case 949:
#line 5200 "fgl.yacc"
    {sprintf(yyval.str,"%s.%s",yyvsp[-2].str,yyvsp[-1].str);}
    break;

  case 950:
#line 5203 "fgl.yacc"
    {A4GL_lex_printcomment("/* Variable */\n");}
    break;

  case 951:
#line 5204 "fgl.yacc"
    { A4GL_debug("Got an ibind thru..."); sprintf(yyval.str,"%s\n%s",yyvsp[-2].str,yyvsp[0].str); }
    break;

  case 953:
#line 5206 "fgl.yacc"
    {sprintf(yyval.str,"\"%s\"",yyvsp[0].str);}
    break;

  case 954:
#line 5207 "fgl.yacc"
    {sprintf(yyval.str,"\"%s\"",yyvsp[0].str);}
    break;

  case 955:
#line 5210 "fgl.yacc"
    {
start_bind('o',yyvsp[0].str);
}
    break;

  case 956:
#line 5213 "fgl.yacc"
    {
add_bind('o',yyvsp[0].str);
strcpy(yyval.str,"");
}
    break;

  case 957:
#line 5219 "fgl.yacc"
    {
	addmap("OBIND",yyvsp[0].str,curr_func,yylineno,infilename);
	}
    break;

  case 958:
#line 5222 "fgl.yacc"
    { A4GL_debug("Got an obind thru..."); sprintf(yyval.str,"%s\n%s",yyvsp[-2].str,yyvsp[0].str); }
    break;

  case 959:
#line 5226 "fgl.yacc"
    {
A4GL_lex_printcomment("/* start obind with  %s*/\n",yyvsp[0].str);
A4GL_debug("obind_var_let_list ---> %s\n",yyvsp[0].str);
start_bind('o',yyvsp[0].str);
}
    break;

  case 960:
#line 5231 "fgl.yacc"
    {
A4GL_lex_printcomment("/* add to obind %s */\n",yyvsp[0].str);
add_bind('o',yyvsp[0].str);
A4GL_debug("obind_var_let_list ---> %s\n",yyvsp[0].str);
strcpy(yyval.str,"");
}
    break;

  case 961:
#line 5239 "fgl.yacc"
    {
A4GL_lex_printcomment("/* Read variable %s*/\n",yyvsp[0].str);
}
    break;

  case 962:
#line 5244 "fgl.yacc"
    {
    A4GL_lex_printcomment("/* use_arr_var */\n");
    start_arr_bind('o',yyvsp[0].str);
    A4GL_lex_printcomment("/* use_arr_var complete */\n");
}
    break;

  case 963:
#line 5251 "fgl.yacc"
    {
start_bind('O',yyvsp[0].str);
}
    break;

  case 964:
#line 5254 "fgl.yacc"
    {
               add_bind('O',yyvsp[0].str);
               strcpy(yyval.str,"");
}
    break;

  case 969:
#line 5267 "fgl.yacc"
    {
  int type,arrsize,size,level;
  char arrbuff[256];
  A4GL_lex_printcomment("/*..array_r_varid..*/");

//printf("Got array %s %s\n",$<str>1,$<str>3);
if (get_variable_dets (yyvsp[-3].str,&type,&arrsize,&size,&level,arrbuff)>=0) {
	// Its a variable
	//printf("gvd = true\n");
  sprintf(yyval.str,"%s[%s]",yyvsp[-3].str,subtract_one(yyvsp[-1].str));
} else {
	// Its an sql identifier or similar
	//printf("gvd = false\n");
  sprintf(yyval.str,"%s[%s]",yyvsp[-3].str,yyvsp[-1].str);
}
//printf("All done - ARRAY (array_r_varid) : %s\n",$<str>$);
}
    break;

  case 970:
#line 5286 "fgl.yacc"
    {
A4GL_lex_printcomment("/*STarted bind %s*/\n",yyvsp[0].str);
start_bind('N',yyvsp[0].str);
A4GL_lex_printcomment("/*STarted bind 2*/\n");
strcpy(yyval.str,"");
}
    break;

  case 971:
#line 5293 "fgl.yacc"
    {
A4GL_lex_printcomment("/* Added */\n");
add_bind('N',yyvsp[0].str);
strcpy(yyval.str,"");
}
    break;

  case 972:
#line 5300 "fgl.yacc"
    {
		strcpy(yyval.str,yyvsp[0].str);
	}
    break;

  case 973:
#line 5303 "fgl.yacc"
    {
			sprintf(yyval.str,"%s\n%s",yyvsp[-2].str,yyvsp[0].str);
		}
    break;

  case 974:
#line 5317 "fgl.yacc"
    {
form_attrib.iswindow=1;
print_open_window(yyvsp[-5].str,yyvsp[-1].str);
sprintf(yyval.str,"open window");
}
    break;

  case 979:
#line 5334 "fgl.yacc"
    {
	print_niy("OPEN_STATUSBOX");
}
    break;

  case 980:
#line 5339 "fgl.yacc"
    {
addmap("Call Formhandler",yyvsp[0].str,curr_func,yylineno,infilename); 
}
    break;

  case 981:
#line 5345 "fgl.yacc"
    {
		print_open_form(yyvsp[0].str,yyvsp[-1].str,yyvsp[-1].str);
		}
    break;

  case 983:
#line 5352 "fgl.yacc"
    { form_attrib.iswindow=0;strcpy(yyval.str,"A4GL_open_form(%s);"); }
    break;

  case 984:
#line 5357 "fgl.yacc"
    {sprintf(yyval.str,"A4GL_open_gui_form(%%s,%s,%s,%s,hnd_e_%s,hnd_c_%s);",yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[0].str,yyvsp[0].str);}
    break;

  case 985:
#line 5360 "fgl.yacc"
    {strcpy(yyval.str,"0,0");}
    break;

  case 986:
#line 5361 "fgl.yacc"
    {sprintf(yyval.str,"%s,2",yyvsp[-5].str);}
    break;

  case 987:
#line 5364 "fgl.yacc"
    {strcpy(yyval.str,"\"\"");}
    break;

  case 988:
#line 5365 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 989:
#line 5368 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 990:
#line 5369 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 991:
#line 5374 "fgl.yacc"
    {
print_open_session(yyvsp[-3].str,yyvsp[-1].str,yyvsp[0].str);

}
    break;

  case 992:
#line 5381 "fgl.yacc"
    {
	print_open_cursor(yyvsp[0].str,"0");
}
    break;

  case 993:
#line 5384 "fgl.yacc"
    {
	print_open_cursor(yyvsp[-3].str,yyvsp[0].str); /* CHANGED from $<str>4 */
}
    break;

  case 994:
#line 5390 "fgl.yacc"
    {sprintf(yyval.str,"0,0");}
    break;

  case 995:
#line 5392 "fgl.yacc"
    {sprintf(yyval.str,"%s, %s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 996:
#line 5394 "fgl.yacc"
    {sprintf(yyval.str,"%s, %s",yyvsp[-3].str,yyvsp[0].str);}
    break;

  case 997:
#line 5396 "fgl.yacc"
    {sprintf(yyval.str,"%s, %s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 998:
#line 5399 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 999:
#line 5399 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 1000:
#line 5400 "fgl.yacc"
    {strcpy(yyval.str,"2");}
    break;

  case 1001:
#line 5405 "fgl.yacc"
    {
	print_open_session(yyvsp[-1].str,yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 1002:
#line 5413 "fgl.yacc"
    {strcpy(yyval.str,"\"default_conn\"");}
    break;

  case 1003:
#line 5414 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1004:
#line 5419 "fgl.yacc"
    {sprintf(yyval.str,"0,0");}
    break;

  case 1005:
#line 5421 "fgl.yacc"
    {sprintf(yyval.str,"%s, %s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1006:
#line 5423 "fgl.yacc"
    {sprintf(yyval.str,"%s, %s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1010:
#line 5440 "fgl.yacc"
    {
print_options('C',yyvsp[0].str);
}
    break;

  case 1011:
#line 5443 "fgl.yacc"
    {
print_options('E',yyvsp[0].str);
}
    break;

  case 1012:
#line 5446 "fgl.yacc"
    {
print_options('F',yyvsp[0].str);
}
    break;

  case 1013:
#line 5449 "fgl.yacc"
    {
//A4GL_lex_printc("A4GL_set_option_value('M',%s);\n",$<str>2);
print_options('M',yyvsp[0].str);
}
    break;

  case 1014:
#line 5453 "fgl.yacc"
    {
print_options('m',yyvsp[0].str);
}
    break;

  case 1015:
#line 5456 "fgl.yacc"
    {
print_options('P',yyvsp[0].str);
}
    break;

  case 1016:
#line 5459 "fgl.yacc"
    {
print_options('A',yyvsp[0].str);
iskey=0;
}
    break;

  case 1017:
#line 5463 "fgl.yacc"
    {
print_options('D',yyvsp[0].str);
iskey=0;
}
    break;

  case 1018:
#line 5467 "fgl.yacc"
    {
print_options('I',yyvsp[0].str);
iskey=0;
}
    break;

  case 1019:
#line 5471 "fgl.yacc"
    {
print_options('N',yyvsp[0].str);
}
    break;

  case 1020:
#line 5474 "fgl.yacc"
    {
print_options('p',yyvsp[0].str);
iskey=0;
}
    break;

  case 1021:
#line 5478 "fgl.yacc"
    {
print_options('H',yyvsp[0].str);
}
    break;

  case 1022:
#line 5481 "fgl.yacc"
    { print_set_helpfile(yyvsp[0].str); }
    break;

  case 1023:
#line 5482 "fgl.yacc"
    { print_set_langfile(yyvsp[0].str); }
    break;

  case 1024:
#line 5483 "fgl.yacc"
    {
print_options('d',yyvsp[0].str);
}
    break;

  case 1025:
#line 5486 "fgl.yacc"
    {
print_options('i',yyvsp[0].str);
}
    break;

  case 1026:
#line 5489 "fgl.yacc"
    {
print_options('W',"1");
}
    break;

  case 1027:
#line 5492 "fgl.yacc"
    {
print_options('W',"0");
}
    break;

  case 1028:
#line 5495 "fgl.yacc"
    {
print_options('f',"1");
}
    break;

  case 1029:
#line 5498 "fgl.yacc"
    {
print_options('f',"0");
}
    break;

  case 1030:
#line 5501 "fgl.yacc"
    {
print_options('S',"1");
}
    break;

  case 1031:
#line 5504 "fgl.yacc"
    {
print_options('S',"0");
}
    break;

  case 1032:
#line 5521 "fgl.yacc"
    {
	print_prepare(yyvsp[-2].str,yyvsp[0].str);
	addmap("Prepare",yyvsp[-2].str,curr_func,yylineno,infilename);
	print_undo_use(yyvsp[-4].str);
}
    break;

  case 1035:
#line 5531 "fgl.yacc"
    {

print_execute(yyvsp[0].str,0);

addmap("Execute",yyvsp[0].str,curr_func,yylineno,infilename);
}
    break;

  case 1036:
#line 5537 "fgl.yacc"
    {
	addmap("Execute",yyvsp[-2].str,curr_func,yylineno,infilename);
	print_execute(yyvsp[-2].str,1);
	}
    break;

  case 1037:
#line 5541 "fgl.yacc"
    {
		print_execute_immediate(yyvsp[0].str);
	}
    break;

  case 1039:
#line 5561 "fgl.yacc"
    {
                push_blockcommand("PROMPT");

	print_prompt_1(yyvsp[-6].str,yyvsp[-4].str,yyvsp[-1].str,yyvsp[0].str,atoi(yyvsp[-2].str)) ;
}
    break;

  case 1040:
#line 5566 "fgl.yacc"
    {
		if (strcmp(yyvsp[-6].str,"1")==0) {
			print_prompt_forchar();
                }
		add_continue_blockcommand ("PROMPT");
		print_prompt_end(yyvsp[-5].str);
                pop_blockcommand("PROMPT");
                A4GL_lex_printcomment("/* END OF PROMPT */");
                }
    break;

  case 1041:
#line 5578 "fgl.yacc"
    {sprintf(yyval.str,"0");}
    break;

  case 1042:
#line 5579 "fgl.yacc"
    {sprintf(yyval.str,yyvsp[0].str);}
    break;

  case 1043:
#line 5583 "fgl.yacc"
    {
		print_niy("GUI PROMPT");
	}
    break;

  case 1044:
#line 5588 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 1045:
#line 5589 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 1046:
#line 5593 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1050:
#line 5599 "fgl.yacc"
    {
	print_onkey_1(yyvsp[0].str);
}
    break;

  case 1051:
#line 5601 "fgl.yacc"
    {
	print_onkey_2_prompt();
}
    break;

  case 1053:
#line 5616 "fgl.yacc"
    {
		start_bind('i',0);
		}
    break;

  case 1054:
#line 5620 "fgl.yacc"
    {
		print_put(yyvsp[-2].str,yyvsp[0].str);
	}
    break;

  case 1055:
#line 5626 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1056:
#line 5627 "fgl.yacc"
    { strcpy(yyval.str,yyvsp[0].str);
A4GL_debug("putlist = %s\n",yyval.str);
}
    break;

  case 1057:
#line 5632 "fgl.yacc"
    {push_gen(PUTVAL,yyvsp[0].str);}
    break;

  case 1058:
#line 5633 "fgl.yacc"
    {push_gen(PUTVAL,yyvsp[0].str); sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1059:
#line 5636 "fgl.yacc"
    {
	char buff[256];	
	strcpy(buff,yyvsp[0].sql_string);
	A4GL_debug("put buff=%s\n",buff);
	if (buff[0]!='\''&&strncmp(buff,"?",1)!=0&&strncmp(buff," :",2)!=0) {
		A4GL_debug("Got : %s - expecting '..', : or ?",buff);
 		a4gl_yyerror("Put values must be variables, strings or 'NULL'");
		YYERROR;
	}

	A4GL_add_put_string(buff);
	strcpy(yyval.str,buff);

}
    break;

  case 1061:
#line 5664 "fgl.yacc"
    {
addmap("Start Report",yyvsp[-1].str,curr_func,yylineno,infilename);
print_start_report("P","acl_getenv(\"DBPRINT\")",yyvsp[-1].str);
}
    break;

  case 1062:
#line 5669 "fgl.yacc"
    {
addmap("Start Report",yyvsp[-2].str,curr_func,yylineno,infilename);
print_start_report("F",yyvsp[0].str,yyvsp[-2].str);
}
    break;

  case 1063:
#line 5674 "fgl.yacc"
    {
addmap("Start Report",yyvsp[-2].str,curr_func,yylineno,infilename);
print_start_report("P",yyvsp[0].str,yyvsp[-2].str);
}
    break;

  case 1064:
#line 5679 "fgl.yacc"
    {
addmap("Start Report",yyvsp[0].str,curr_func,yylineno,infilename);
print_start_report("","\"\"",yyvsp[0].str);
}
    break;

  case 1070:
#line 5701 "fgl.yacc"
    {
addmap("Output to report",yyvsp[-5].str,curr_func,yylineno,infilename);
print_output_to_report(yyvsp[-5].str,yyvsp[-1].str); 
}
    break;

  case 1071:
#line 5708 "fgl.yacc"
    {
addmap("Finish Report",yyvsp[0].str,curr_func,yylineno,infilename);
print_finish_report(yyvsp[0].str);
}
    break;

  case 1072:
#line 5717 "fgl.yacc"
    {
addmap("Finish Report",yyvsp[0].str,curr_func,yylineno,infilename);
print_terminate_report(yyvsp[0].str);
}
    break;

  case 1073:
#line 5723 "fgl.yacc"
    { strcpy(yyval.str,yyvsp[0].str); }
    break;

  case 1074:
#line 5725 "fgl.yacc"
    {
	print_format_every_row();
}
    break;

  case 1078:
#line 5736 "fgl.yacc"
    { push_report_block("FIRST",'P');}
    break;

  case 1079:
#line 5737 "fgl.yacc"
    {
rep_struct.lines_in_first_header=if_print_stack[0][0];
pdf_rep_struct.lines_in_first_header=if_print_stack[0][0];
print_rep_ret(0);
}
    break;

  case 1080:
#line 5743 "fgl.yacc"
    { push_report_block("TRAILER",'T');
if_print_stack[0][0]=0;
if_print_stack[0][1]=0;
}
    break;

  case 1081:
#line 5747 "fgl.yacc"
    {
rep_struct.lines_in_trailer=if_print_stack[0][0];
pdf_rep_struct.lines_in_trailer=if_print_stack[0][0];
print_rep_ret(0);
}
    break;

  case 1082:
#line 5753 "fgl.yacc"
    { push_report_block("HEADER",'p');}
    break;

  case 1083:
#line 5754 "fgl.yacc"
    {
rep_struct.lines_in_header=if_print_stack[0][0];
pdf_rep_struct.lines_in_header=if_print_stack[0][0];
print_rep_ret(0);}
    break;

  case 1084:
#line 5759 "fgl.yacc"
    { push_report_block("EVERY",'E');}
    break;

  case 1085:
#line 5760 "fgl.yacc"
    {print_rep_ret(0);}
    break;

  case 1086:
#line 5762 "fgl.yacc"
    { push_report_block("LAST",'L');}
    break;

  case 1087:
#line 5763 "fgl.yacc"
    {print_rep_ret(0);}
    break;

  case 1088:
#line 5764 "fgl.yacc"
    {
int a;
char buff[80];
A4GL_debug("rordcnt=%d",rordcnt);
a=scan_orderby(yyvsp[0].str,rordcnt);
if (a<0) {
   sprintf(buff,"%s is not in the order by list",yyvsp[0].str);
   a4gl_yyerror(buff);
	YYERROR;
}
sprintf(buff,"%d",a+1);
push_report_block(buff,'B');
set_curr_block(a+1);
}
    break;

  case 1089:
#line 5778 "fgl.yacc"
    {print_rep_ret(0);}
    break;

  case 1090:
#line 5780 "fgl.yacc"
    { 
int a;
char buff[80];

A4GL_debug("rordcnt=%d",rordcnt);
a=scan_orderby(yyvsp[0].str,rordcnt);
if (a<0) {
   sprintf(buff,"%s is not in the order by list",yyvsp[0].str);
   a4gl_yyerror(buff);
	YYERROR;
}

sprintf(buff,"%d",a+1);
push_report_block(buff,'A');
set_curr_block(a+1);

}
    break;

  case 1091:
#line 5797 "fgl.yacc"
    {print_rep_ret(0);}
    break;

  case 1098:
#line 5809 "fgl.yacc"
    {start_state("skip",1);}
    break;

  case 1099:
#line 5809 "fgl.yacc"
    {
	print_need_lines();
	start_state("skip",0);
}
    break;

  case 1100:
#line 5815 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 1101:
#line 5815 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 1102:
#line 5818 "fgl.yacc"
    {start_state("KWLINE",1);}
    break;

  case 1103:
#line 5818 "fgl.yacc"
    {
double n;
char buff[256];
strcpy(buff,yyvsp[0].str);
n=atof(yyvsp[-2].str);
if (buff[0]=='1') {
	print_skip_lines(n);
	if (if_print_stack_cnt==0) if_print_section[0]=0;
	if (get_curr_report_stack_whytype()=='T') {
		if_print_stack[if_print_stack_cnt][if_print_section[if_print_stack_cnt]]+=(int)n;
	}
} else {
	if (rep_type!=REP_TYPE_PDF) { a4gl_yyerror("SKIP BY is only in PDF reports"); YYERROR; } print_skip_by(n);
}
start_state("KWLINE",0); 
}
    break;

  case 1104:
#line 5834 "fgl.yacc"
    { print_skip_top(); }
    break;

  case 1105:
#line 5835 "fgl.yacc"
    { print_niy("FONT SIZE"); }
    break;

  case 1106:
#line 5836 "fgl.yacc"
    {
		double n;
			n=atof(yyvsp[0].str);
			if (rep_type!=REP_TYPE_PDF) {
				a4gl_yyerror("SKIP BY is only in PDF reports");
				YYERROR;
			}
			print_skip_by(n);
		}
    break;

  case 1107:
#line 5845 "fgl.yacc"
    {
			if (rep_type!=REP_TYPE_PDF) {
				a4gl_yyerror("SKIP TO is only in PDF reports");
				YYERROR;
			}
			print_skip_to(yyvsp[0].str);
		}
    break;

  case 1108:
#line 5857 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1114:
#line 5868 "fgl.yacc"
    {
	print_niy("PRINT AT...");
}
    break;

  case 1115:
#line 5873 "fgl.yacc"
    {
	char wt;
	print_report_print(0,yyvsp[0].str,0);
	wt=get_curr_report_stack_whytype();
	if (strcmp(yyvsp[0].str,"0")==0) {
		if (wt=='P'||wt=='p'||wt=='T') { /* Page header or trailer */
			if (isin_command("WHILE")||isin_command("FOR")) {
				a4gl_yyerror("You can't print within a loop in a PAGE HEADER or PAGE TRAILER");
				YYERROR;
			}
		}
	}
	if (strcmp(yyvsp[0].str,"0")==0) {
			if (if_print_stack_cnt==0) if_print_section[0]=0;
		if (get_curr_report_stack_whytype()=='T') {
			if_print_stack[if_print_stack_cnt][if_print_section[if_print_stack_cnt]]+=1;
		}
	}
}
    break;

  case 1116:
#line 5893 "fgl.yacc"
    { 
	print_report_print_file(yyvsp[-1].str,yyvsp[0].str);
}
    break;

  case 1117:
#line 5898 "fgl.yacc"
    { 
	print_report_print_img(yyvsp[-1].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 1118:
#line 5904 "fgl.yacc"
    { strcpy(yyval.str,A4GL_get_default_scaling());}
    break;

  case 1119:
#line 5905 "fgl.yacc"
    { strcpy(yyval.str,yyvsp[0].str); strcat(yyval.str,yyvsp[0].str); }
    break;

  case 1120:
#line 5906 "fgl.yacc"
    {sprintf(yyval.str,"%s %s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1121:
#line 5910 "fgl.yacc"
    {strcpy(yyval.str,"tiff");}
    break;

  case 1122:
#line 5911 "fgl.yacc"
    {strcpy(yyval.str,"gif");}
    break;

  case 1123:
#line 5912 "fgl.yacc"
    {strcpy(yyval.str,"png");}
    break;

  case 1124:
#line 5913 "fgl.yacc"
    {strcpy(yyval.str,"jpeg");}
    break;

  case 1125:
#line 5917 "fgl.yacc"
    {
	int vtype;
	vtype=scan_variable(yyvsp[0].str);
	if (vtype!=11&&vtype!=12) {
	a4gl_yyerror("Only Blobs may be printed...");
	YYERROR;
	}
}
    break;

  case 1126:
#line 5927 "fgl.yacc"
    {
strcpy(yyval.str,"0");
}
    break;

  case 1127:
#line 5929 "fgl.yacc"
    {
strcpy(yyval.str,"1");
}
    break;

  case 1128:
#line 5934 "fgl.yacc"
    {
	print_report_print(1,0,yyvsp[0].str);
	}
    break;

  case 1129:
#line 5937 "fgl.yacc"
    {
	print_report_print(1,0,yyvsp[0].str); /* changed from $<str>1 */
}
    break;

  case 1130:
#line 5942 "fgl.yacc"
    {
	strcpy(yyval.str,yyvsp[0].str); 
	}
    break;

  case 1131:
#line 5949 "fgl.yacc"
    {
int a;
a=add_report_agg('S',yyvsp[-2].ptr,yyvsp[0].ptr,racnt);
sprintf(yyval.str,"A4GL_push_double(_g%d);\n",racnt);
racnt+=a;
}
    break;

  case 1132:
#line 5956 "fgl.yacc"
    {
int a;
a=add_report_agg('C',0,yyvsp[0].ptr,racnt);
sprintf(yyval.str,"A4GL_push_int(_g%d);\n",racnt);
racnt+=a;
}
    break;

  case 1133:
#line 5963 "fgl.yacc"
    {
int a;
a=add_report_agg('C',0,yyvsp[0].ptr,racnt);
sprintf(yyval.str,"A4GL_push_int(_g%d);\n",racnt);
racnt+=a;
}
    break;

  case 1134:
#line 5972 "fgl.yacc"
    {
int a;
a=add_report_agg('P',yyvsp[-2].ptr,yyvsp[0].ptr,racnt);
sprintf(yyval.str,"A4GL_push_double((double)_g%d/(double)_g%d);\n",racnt,racnt+1);
racnt+=a;
}
    break;

  case 1135:
#line 5979 "fgl.yacc"
    {
int a;
a=add_report_agg('A',yyvsp[-2].ptr,yyvsp[0].ptr,racnt);
sprintf(yyval.str,"A4GL_push_double(_g%d/(double)_g%d);\n",racnt,racnt+1);
racnt+=a;
}
    break;

  case 1136:
#line 5986 "fgl.yacc"
    {
int a;
a=add_report_agg('A',yyvsp[-2].ptr,yyvsp[0].ptr,racnt);
sprintf(yyval.str,"A4GL_push_double(_g%d/_g%d);\n",racnt,racnt+1);
racnt+=a;
}
    break;

  case 1137:
#line 5993 "fgl.yacc"
    {
int a;
a=add_report_agg('N',yyvsp[-2].ptr,yyvsp[0].ptr,racnt);
sprintf(yyval.str,"A4GL_push_double(_g%d);\n",racnt);
racnt+=a;
}
    break;

  case 1138:
#line 6000 "fgl.yacc"
    {
int a;
a=add_report_agg('X',yyvsp[-2].ptr,yyvsp[0].ptr,racnt);
sprintf(yyval.str,"A4GL_push_double(_g%d);\n",racnt);
racnt+=a;
}
    break;

  case 1143:
#line 6013 "fgl.yacc"
    {rep_struct.left_margin=atoi(yyvsp[0].str);}
    break;

  case 1144:
#line 6014 "fgl.yacc"
    {rep_struct.right_margin=atoi(yyvsp[0].str);}
    break;

  case 1145:
#line 6015 "fgl.yacc"
    {rep_struct.top_margin=atoi(yyvsp[0].str);}
    break;

  case 1146:
#line 6016 "fgl.yacc"
    {rep_struct.bottom_margin=atoi(yyvsp[0].str);}
    break;

  case 1147:
#line 6017 "fgl.yacc"
    {rep_struct.page_length=atoi(yyvsp[0].str);}
    break;

  case 1148:
#line 6018 "fgl.yacc"
    { rep_struct.output_mode='P';strcpy(rep_struct.output_loc,"acl_getenv(\"DBPRINT\")");}
    break;

  case 1149:
#line 6019 "fgl.yacc"
    {rep_struct.output_mode='F';strcpy(rep_struct.output_loc,yyvsp[0].str);}
    break;

  case 1150:
#line 6020 "fgl.yacc"
    {rep_struct.output_mode='F';strcpy(rep_struct.output_loc,yyvsp[0].str);}
    break;

  case 1151:
#line 6021 "fgl.yacc"
    {rep_struct.output_mode='P';strcpy(rep_struct.output_loc,yyvsp[0].str);}
    break;

  case 1152:
#line 6022 "fgl.yacc"
    {strcpy(rep_struct.top_of_page,yyvsp[0].str);}
    break;

  case 1155:
#line 6028 "fgl.yacc"
    {sprintf(yyval.str,"-%f",atof(yyvsp[-1].str));}
    break;

  case 1156:
#line 6029 "fgl.yacc"
    {sprintf(yyval.str,"-%f",atof(yyvsp[-1].str)*72.0); }
    break;

  case 1157:
#line 6030 "fgl.yacc"
    {sprintf(yyval.str,"-%f",atof(yyvsp[-1].str)*2.83465);}
    break;

  case 1158:
#line 6031 "fgl.yacc"
    {sprintf(yyval.str,"%f",atof(yyvsp[0].str));}
    break;

  case 1163:
#line 6040 "fgl.yacc"
    {pdf_rep_struct.left_margin=atof(yyvsp[0].str);A4GL_debug("Left margin=%s\n",yyvsp[0].str);}
    break;

  case 1164:
#line 6041 "fgl.yacc"
    {pdf_rep_struct.right_margin=atof(yyvsp[0].str);}
    break;

  case 1165:
#line 6042 "fgl.yacc"
    {pdf_rep_struct.top_margin=atof(yyvsp[0].str);}
    break;

  case 1166:
#line 6043 "fgl.yacc"
    {pdf_rep_struct.bottom_margin=atof(yyvsp[0].str);}
    break;

  case 1167:
#line 6044 "fgl.yacc"
    {pdf_rep_struct.page_length=atof(yyvsp[0].str);}
    break;

  case 1168:
#line 6045 "fgl.yacc"
    {pdf_rep_struct.page_width=atof(yyvsp[0].str);}
    break;

  case 1169:
#line 6046 "fgl.yacc"
    {strcpy(pdf_rep_struct.font_name,yyvsp[0].str);}
    break;

  case 1170:
#line 6047 "fgl.yacc"
    {pdf_rep_struct.font_size=atof(yyvsp[0].str);}
    break;

  case 1171:
#line 6049 "fgl.yacc"
    {pdf_rep_struct.paper_size=1;}
    break;

  case 1172:
#line 6050 "fgl.yacc"
    {pdf_rep_struct.paper_size=2;}
    break;

  case 1173:
#line 6051 "fgl.yacc"
    {pdf_rep_struct.paper_size=3;}
    break;

  case 1174:
#line 6052 "fgl.yacc"
    {pdf_rep_struct.paper_size=5;}
    break;

  case 1175:
#line 6054 "fgl.yacc"
    {pdf_rep_struct.paper_size=-1;}
    break;

  case 1176:
#line 6055 "fgl.yacc"
    {pdf_rep_struct.paper_size=-2;}
    break;

  case 1177:
#line 6056 "fgl.yacc"
    {pdf_rep_struct.paper_size=-3;}
    break;

  case 1178:
#line 6057 "fgl.yacc"
    {pdf_rep_struct.paper_size=-5;}
    break;

  case 1182:
#line 6062 "fgl.yacc"
    {pdf_rep_struct.output_mode='F';strcpy(pdf_rep_struct.output_loc,yyvsp[0].str);}
    break;

  case 1183:
#line 6063 "fgl.yacc"
    {pdf_rep_struct.output_mode='P';strcpy(pdf_rep_struct.output_loc,yyvsp[0].str);}
    break;

  case 1187:
#line 6070 "fgl.yacc"
    {
int a;
set_rep_no_orderby(1);
a=print_bind('O');
print_order_by_type(2,-1);
sprintf(yyval.str,"%d",a);
}
    break;

  case 1188:
#line 6078 "fgl.yacc"
    {
int a;
set_rep_no_orderby(0);
a=print_bind('O');
print_order_by_type(1,a);
sprintf(yyval.str,"%d",a);
A4GL_debug("Order by Gives :%d\n",a);
}
    break;

  case 1189:
#line 6086 "fgl.yacc"
    {
int a;
set_rep_no_orderby(0);
a=print_bind('O');
print_order_by_type(2,a);
sprintf(yyval.str,"%d",a);
A4GL_debug("Order by Gives :%d\n",a);
}
    break;

  case 1190:
#line 6098 "fgl.yacc"
    { 
		rep_type=REP_TYPE_NORMAL; 
		clr_function_constants (); 
		clr_variable(); 
		lastlineno=yylineno; 
		init_report_structure(&rep_struct); 
		}
    break;

  case 1191:
#line 6107 "fgl.yacc"
    {
		inc_report_cnt();
		sprintf(curr_func,"%s",yyvsp[-1].str);
		addmap("Define Report",curr_func,"MODULE",yylineno,infilename);
		variable_action(-1,yyvsp[-1].str,"","","add_function");
		set_curr_rep_name(yyvsp[-1].str);
		print_report_1(yyvsp[-1].str);
		push_blockcommand("REPORT");
		}
    break;

  case 1192:
#line 6118 "fgl.yacc"
    {
		lastlineno=yylineno;
		}
    break;

  case 1193:
#line 6122 "fgl.yacc"
    {
		print_variables();
		}
    break;

  case 1194:
#line 6126 "fgl.yacc"
    {
		print_report_2(0,yyvsp[0].str);
		rordcnt=atoi(yyvsp[0].str);
	 A4GL_debug("SET rordcnt=%d %s",rordcnt,yyvsp[0].str);
		}
    break;

  case 1195:
#line 6132 "fgl.yacc"
    {
		print_report_ctrl();
		}
    break;

  case 1196:
#line 6137 "fgl.yacc"
    {
		pop_blockcommand("REPORT");
		print_report_end() ;
		}
    break;

  case 1197:
#line 6145 "fgl.yacc"
    { strcpy(yyval.str,"");
	yyval.ptr=0;
}
    break;

  case 1198:
#line 6148 "fgl.yacc"
    {
	yyval.ptr=yyvsp[0].ptr;
//sprintf($<str>$,"%s", $<str>2);
}
    break;

  case 1199:
#line 6157 "fgl.yacc"
    {
if (!in_command("REPORT")) {
	a4gl_yyerror("PAUSE can only be used in reportes");
	YYERROR;
        }

print_pause(yyvsp[0].str) ;
}
    break;

  case 1200:
#line 6168 "fgl.yacc"
    {strcpy(yyval.str,"\"\"");}
    break;

  case 1202:
#line 6175 "fgl.yacc"
    {
rep_type=REP_TYPE_PDF;
clr_function_constants();
clr_variable(); 
lastlineno=yylineno; 
pdf_init_report_structure(&pdf_rep_struct);
}
    break;

  case 1203:
#line 6183 "fgl.yacc"
    {
inc_report_cnt();
variable_action(-1,yyvsp[-1].str,"","","add_function");
sprintf(curr_func,"%s",yyvsp[-1].str);
addmap("Define PDF Report",curr_func,"MODULE",yylineno,infilename);
set_curr_rep_name(yyvsp[-1].str);
print_report_1(yyvsp[-1].str);
push_blockcommand("REPORT");
}
    break;

  case 1204:
#line 6193 "fgl.yacc"
    {
lastlineno=yylineno;
}
    break;

  case 1205:
#line 6196 "fgl.yacc"
    {
	print_variables();
}
    break;

  case 1206:
#line 6200 "fgl.yacc"
    {
//print_variables();
resize_paper(&pdf_rep_struct);
	print_report_2(1,yyvsp[0].str);
A4GL_debug("SET rordcnt=%d (%s)",rordcnt,yyvsp[0].str);
	rordcnt=atoi(yyvsp[0].str);
}
    break;

  case 1207:
#line 6208 "fgl.yacc"
    {
print_report_ctrl();
}
    break;

  case 1208:
#line 6211 "fgl.yacc"
    {
	pop_blockcommand("REPORT");
	print_report_end();
}
    break;

  case 1209:
#line 6217 "fgl.yacc"
    { strcpy(yyval.str,yyvsp[0].str); }
    break;

  case 1210:
#line 6221 "fgl.yacc"
    {new_counter();
   		addmap("CALL",yyvsp[-1].str,curr_func,yylineno,infilename);
   		}
    break;

  case 1211:
#line 6225 "fgl.yacc"
    {
		sprintf(yyval.str,"%d",get_counter_val());drop_counter();
		}
    break;

  case 1212:
#line 6229 "fgl.yacc"
    {
		print_pdf_call(yyvsp[-5].str,yyvsp[-2].ptr,yyvsp[-1].str);
   		}
    break;

  case 1213:
#line 6233 "fgl.yacc"
    {
	print_returning();
   }
    break;

  case 1214:
#line 6239 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 1215:
#line 6240 "fgl.yacc"
    { strcpy(yyval.str,"rep.right_margin"); }
    break;

  case 1216:
#line 6241 "fgl.yacc"
    { sprintf(yyval.str,"%s",yyvsp[0].str); }
    break;

  case 1217:
#line 6242 "fgl.yacc"
    { sprintf(yyval.str,"%s",yyvsp[0].str); }
    break;

  case 1218:
#line 6247 "fgl.yacc"
    {
print_system_run(0,0);
}
    break;

  case 1219:
#line 6249 "fgl.yacc"
    {
print_system_run(1,yyvsp[0].str);
}
    break;

  case 1220:
#line 6252 "fgl.yacc"
    {
print_system_run(2,0);
}
    break;

  case 1221:
#line 6256 "fgl.yacc"
    {
print_system_run(0,0);
}
    break;

  case 1222:
#line 6259 "fgl.yacc"
    {
print_system_run(0,0);
/* FIXME */
}
    break;

  case 1223:
#line 6266 "fgl.yacc"
    {
	print_exec_sql(yyvsp[0].str);
}
    break;

  case 1224:
#line 6271 "fgl.yacc"
    {sprintf(yyval.str, "%s",yyvsp[0].str);}
    break;

  case 1225:
#line 6272 "fgl.yacc"
    {sprintf(yyval.str,  "%s",yyvsp[0].str);}
    break;

  case 1226:
#line 6273 "fgl.yacc"
    {sprintf(yyval.str,"%s",yyvsp[0].str);}
    break;

  case 1227:
#line 6278 "fgl.yacc"
    { print_exec_sql(yyvsp[0].str); }
    break;

  case 1228:
#line 6279 "fgl.yacc"
    { print_exec_sql(yyvsp[0].sql_string); 
	free(yyvsp[0].sql_string);
}
    break;

  case 1229:
#line 6285 "fgl.yacc"
    {insql=1;}
    break;

  case 1230:
#line 6285 "fgl.yacc"
    {insql=0;}
    break;

  case 1231:
#line 6285 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-6].str," ",yyvsp[-4].str," ",yyvsp[-3].str,yyvsp[-1].sql_string,yyvsp[0].str,0);
		free(yyvsp[-1].sql_string);
	}
    break;

  case 1232:
#line 6290 "fgl.yacc"
    {insql=1;}
    break;

  case 1233:
#line 6290 "fgl.yacc"
    {insql=0;}
    break;

  case 1234:
#line 6290 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-7].str," ",yyvsp[-5].str," ",yyvsp[-4].str,yyvsp[-2].sql_string,yyvsp[-1].str, " ",yyvsp[0].str,0);
		free(yyvsp[-2].sql_string);

}
    break;

  case 1235:
#line 6301 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1236:
#line 6302 "fgl.yacc"
    {
		a4gl_yyerror("You cannot create a database from within Aubit4gl....");
	}
    break;

  case 1237:
#line 6308 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1238:
#line 6310 "fgl.yacc"
    {
if (A4GL_isyes(acl_getenv("A4GL_OMIT_NO_LOG"))) {
	strcpy(yyval.str,"");
} else {
	sprintf(yyval.str," %s ",yyvsp[0].str);
}
}
    break;

  case 1240:
#line 6323 "fgl.yacc"
    {sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1241:
#line 6327 "fgl.yacc"
    {sprintf(yyval.str,"%s ASC",yyvsp[-1].str);}
    break;

  case 1242:
#line 6328 "fgl.yacc"
    {sprintf(yyval.str,"%s DESC",yyvsp[-1].str);}
    break;

  case 1244:
#line 6333 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1245:
#line 6336 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",",yyvsp[0].sql_string,0);
	}
    break;

  case 1246:
#line 6342 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1247:
#line 6345 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1248:
#line 6353 "fgl.yacc"
    {sprintf(yyval.str,"%s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1250:
#line 6360 "fgl.yacc"
    {
	yyval.sql_string=make_sql_string(yyvsp[-2].str," ",yyvsp[-1].str," ",yyvsp[0].sql_string,0);
	print_exec_sql(yyval.sql_string); 
}
    break;

  case 1251:
#line 6367 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1252:
#line 6370 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",",yyvsp[0].sql_string,0);
	}
    break;

  case 1253:
#line 6379 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1254:
#line 6382 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1255:
#line 6385 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1256:
#line 6388 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1257:
#line 6391 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1258:
#line 6394 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1259:
#line 6397 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1260:
#line 6404 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("ADD ",yyvsp[0].sql_string,0);
	}
    break;

  case 1261:
#line 6407 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("ADD (",yyvsp[-1].sql_string,")",0);
	}
    break;

  case 1262:
#line 6414 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1263:
#line 6417 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string," BEFORE ",yyvsp[0].str,0);
	}
    break;

  case 1264:
#line 6423 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1265:
#line 6426 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",",yyvsp[0].sql_string,0);
	}
    break;

  case 1266:
#line 6433 "fgl.yacc"
    {
		sprintf(yyval.str,"DROP %s",yyvsp[0].str);
	}
    break;

  case 1267:
#line 6436 "fgl.yacc"
    {
		sprintf(yyval.str,"DROP (%s)",yyvsp[-1].str);
	}
    break;

  case 1269:
#line 6444 "fgl.yacc"
    {
		sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);
	}
    break;

  case 1271:
#line 6453 "fgl.yacc"
    {
		sprintf(yyval.str,"MODIFY %s",yyvsp[0].sql_string);
	}
    break;

  case 1272:
#line 6456 "fgl.yacc"
    {
		sprintf(yyval.str,"MODIFY (%s)",yyvsp[-1].sql_string);
	}
    break;

  case 1273:
#line 6462 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1274:
#line 6465 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",",yyvsp[0].sql_string,0);
	}
    break;

  case 1275:
#line 6471 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1276:
#line 6478 "fgl.yacc"
    {strcpy(yyval.str,"LOCK MODE PAGE");}
    break;

  case 1277:
#line 6479 "fgl.yacc"
    {strcpy(yyval.str,"LOCK MODE ROW");}
    break;

  case 1278:
#line 6483 "fgl.yacc"
    {
		sprintf(yyval.str,"MODIFT NEXT SIZE %d",atoi(yyvsp[0].str));
	}
    break;

  case 1279:
#line 6489 "fgl.yacc"
    {
		sprintf(yyval.str,"ADD CONSTRAINT %s",yyvsp[0].sql_string);
	}
    break;

  case 1280:
#line 6492 "fgl.yacc"
    {
		sprintf(yyval.str,"ADD CONSTRAINT (%s)",yyvsp[-1].sql_string);
	}
    break;

  case 1282:
#line 6500 "fgl.yacc"
    {
		sprintf(yyval.str,"ADD CONSTRAINT (%s)",yyvsp[-1].sql_string);
	}
    break;

  case 1283:
#line 6507 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1284:
#line 6510 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",",yyvsp[0].sql_string,0);
	}
    break;

  case 1288:
#line 6528 "fgl.yacc"
    {sprintf(yyval.str,"%s %s /*FIXME */",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1294:
#line 6534 "fgl.yacc"
    { 
	print_set_conn(yyvsp[0].str);
}
    break;

  case 1295:
#line 6537 "fgl.yacc"
    {
	print_set_options("conn",yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 1296:
#line 6540 "fgl.yacc"
    {
	print_set_options("stmt",yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 1297:
#line 6546 "fgl.yacc"
    {strcpy(yyval.str,"\"default\"");}
    break;

  case 1299:
#line 6552 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1301:
#line 6563 "fgl.yacc"
    {
		print_sleep();
	}
    break;

  case 1302:
#line 6577 "fgl.yacc"
    {
		print_sql_commit(0);
		}
    break;

  case 1303:
#line 6586 "fgl.yacc"
    { insql=1;start_bind('i',0);}
    break;

  case 1304:
#line 6586 "fgl.yacc"
    {
	yyval.sql_string=make_sql_string(yyvsp[-4].str," ",yyvsp[-2].str," ",yyvsp[-1].str," ",yyvsp[0].sql_string,0);
}
    break;

  case 1305:
#line 6591 "fgl.yacc"
    {insql=1;}
    break;

  case 1306:
#line 6591 "fgl.yacc"
    {
insql=0;
	//printf("Value = %s\n",$<sql_string>4);
yyval.sql_string=make_sql_string(yyvsp[-4].str," (",yyvsp[-1].sql_string,")",0);}
    break;

  case 1307:
#line 6596 "fgl.yacc"
    {yyval.sql_string=yyvsp[0].sql_string;}
    break;

  case 1308:
#line 6599 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1309:
#line 6601 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1311:
#line 6608 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1312:
#line 6612 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	//printf(" 1. Value = %s\n",$<sql_string>$);
	}
    break;

  case 1313:
#line 6616 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",", yyvsp[0].sql_string,0);
	//printf(" 2. Value = %s\n",$<sql_string>$);
	}
    break;

  case 1314:
#line 6623 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1315:
#line 6626 "fgl.yacc"
    {
		yyval.sql_string=strdup("NULL");
	}
    break;

  case 1316:
#line 6633 "fgl.yacc"
    {
      print_fetch_1();
    }
    break;

  case 1317:
#line 6637 "fgl.yacc"
    {
      print_fetch_2();
    }
    break;

  case 1318:
#line 6641 "fgl.yacc"
    {
      print_fetch_3(yyvsp[-2].str,yyvsp[0].str);
    }
    break;

  case 1319:
#line 6646 "fgl.yacc"
    {sprintf(yyval.str,"%s",yyvsp[0].str);doing_declare=1;}
    break;

  case 1320:
#line 6651 "fgl.yacc"
    {sprintf(yyval.str,"%s, %s",yyvsp[0].str,yyvsp[-1].str);
addmap("Fetch Cursor",yyvsp[0].str,curr_func,yylineno,infilename);
}
    break;

  case 1321:
#line 6655 "fgl.yacc"
    {sprintf(yyval.str,"%s, %d, 1",yyvsp[0].str,FETCH_RELATIVE);

addmap("Fetch Cursor",yyvsp[0].str,curr_func,yylineno,infilename);
}
    break;

  case 1322:
#line 6661 "fgl.yacc"
    {
A4GL_debug("no into\n");
strcpy(yyval.str,"0,0");
}
    break;

  case 1323:
#line 6665 "fgl.yacc"
    {
 A4GL_debug("FETCH INTO  ...");
	/* start_bind('i',0,-1); */
    start_bind('o',0);
}
    break;

  case 1324:
#line 6671 "fgl.yacc"
    {
	int no;
	no=print_bind('o');
	sprintf(yyval.str,"%d,obind",no);
}
    break;

  case 1325:
#line 6678 "fgl.yacc"
    {
A4GL_debug("no into\n");
strcpy(yyval.str,"0,0");
}
    break;

  case 1326:
#line 6682 "fgl.yacc"
    {
 A4GL_debug("FETCH INTO  ...");
	/* start_bind('i',0,-1); */
    start_bind('o',0);
}
    break;

  case 1327:
#line 6687 "fgl.yacc"
    {
/*
int ni;
ni=print_bind('i');
sprintf($<str>$,"%d,ibind",ni);
*/
}
    break;

  case 1328:
#line 6697 "fgl.yacc"
    {
		sprintf(yyval.str,"%d,1",FETCH_ABSOLUTE);}
    break;

  case 1329:
#line 6700 "fgl.yacc"
    {sprintf(yyval.str,"%d,-1",FETCH_ABSOLUTE);}
    break;

  case 1330:
#line 6702 "fgl.yacc"
    {sprintf(yyval.str,"%d,1",FETCH_RELATIVE);}
    break;

  case 1331:
#line 6704 "fgl.yacc"
    {sprintf(yyval.str,"%d,-1",FETCH_RELATIVE);}
    break;

  case 1332:
#line 6706 "fgl.yacc"
    {sprintf(yyval.str,"%d,-1",FETCH_RELATIVE);}
    break;

  case 1333:
#line 6708 "fgl.yacc"
    {sprintf(yyval.str,"%d,0",FETCH_RELATIVE);}
    break;

  case 1334:
#line 6710 "fgl.yacc"
    {sprintf(yyval.str,"%d,A4GL_pop_int()",FETCH_RELATIVE);}
    break;

  case 1335:
#line 6712 "fgl.yacc"
    {sprintf(yyval.str,"%d,A4GL_pop_int()",FETCH_ABSOLUTE);}
    break;

  case 1336:
#line 6718 "fgl.yacc"
    {
 
rm_quotes(yyvsp[0].str);
sprintf(yyval.str," %s %s %s %s ",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str
);}
    break;

  case 1337:
#line 6728 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].str," ",yyvsp[-1].str," ",yyvsp[0].sql_string,0);
		}
    break;

  case 1338:
#line 6735 "fgl.yacc"
    {sprintf(yyval.str,"%s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1340:
#line 6741 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1341:
#line 6744 "fgl.yacc"
    {sprintf(yyval.str,"%s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1344:
#line 6751 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1347:
#line 6756 "fgl.yacc"
    {
print_sql_commit(-1);
}
    break;

  case 1348:
#line 6761 "fgl.yacc"
    {
		print_sql_commit(1);
	}
    break;

  case 1349:
#line 6768 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1350:
#line 6769 "fgl.yacc"
    {
		strcpy(yyval.str,"EXCLUSIVE");
	}
    break;

  case 1351:
#line 6776 "fgl.yacc"
    {
if (strcmp(yyvsp[-1].str,"?")==0) {
	print_init_conn(0);
} else {
	print_init_conn(yyvsp[-1].str);
}
}
    break;

  case 1352:
#line 6787 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1353:
#line 6788 "fgl.yacc"
    {sprintf(yyval.str,"%s@%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1354:
#line 6789 "fgl.yacc"
    {strcpy(yyval.str, A4GL_strip_quotes (yyvsp[0].str));}
    break;

  case 1355:
#line 6792 "fgl.yacc"
    {insql=1;}
    break;

  case 1356:
#line 6792 "fgl.yacc"
    {
print_undo_use(yyvsp[-2].str);
insql=0;strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1357:
#line 6797 "fgl.yacc"
    {
		 A4GL_lex_printcomment("/*  schema */\n");
			print_exec_sql(yyvsp[0].sql_string);
			strcpy(yyval.str,"Schema");
	}
    break;

  case 1358:
#line 6802 "fgl.yacc"
    {
	 A4GL_lex_printcomment("/*  schema  2*/\n");
		print_exec_sql(yyvsp[0].sql_string);
		strcpy(yyval.str,"Schema Element");
	}
    break;

  case 1360:
#line 6808 "fgl.yacc"
    {
		print_exec_sql(yyvsp[0].str);
 	}
    break;

  case 1362:
#line 6812 "fgl.yacc"
    {
	 A4GL_lex_printcomment("/*  delete 1 */\n");
		print_exec_sql_bound(yyvsp[0].str);
		strcpy(yyval.str,"Delete where current...");
	}
    break;

  case 1363:
#line 6817 "fgl.yacc"
    {
	 A4GL_lex_printcomment("/*  delete 2 */\n");
		print_exec_sql_bound(yyvsp[0].sql_string);
		strcpy(yyval.str,"Delete where ...");
	}
    break;

  case 1364:
#line 6822 "fgl.yacc"
    {
		strcpy(yyval.str,"Fetch");
	 A4GL_lex_printcomment("/*  fetch */\n");
	}
    break;

  case 1365:
#line 6826 "fgl.yacc"
    {
	 A4GL_lex_printcomment("/*  insert */\n");
		print_exec_sql_bound(yyvsp[0].sql_string);
		strcpy(yyval.str,"insert");
	}
    break;

  case 1367:
#line 6832 "fgl.yacc"
    {
		print_do_select(yyvsp[0].sql_string);
		strcpy(yyval.str,"select");
	}
    break;

  case 1368:
#line 6836 "fgl.yacc"
    {
		print_exec_sql_bound(yyvsp[0].sql_string);
		strcpy(yyval.str,"update");
	}
    break;

  case 1369:
#line 6844 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s %s %s %s",yyvsp[-6].str,yyvsp[-5].str,yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1370:
#line 6847 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1371:
#line 6849 "fgl.yacc"
    {sprintf(yyval.str," %s ",yyvsp[0].str);}
    break;

  case 1372:
#line 6854 "fgl.yacc"
    {sprintf(yyval.str," %s ",yyvsp[0].str);}
    break;

  case 1375:
#line 6861 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1379:
#line 6868 "fgl.yacc"
    {sprintf(yyval.str," %s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1380:
#line 6871 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1381:
#line 6873 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1383:
#line 6879 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1385:
#line 6885 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1388:
#line 6895 "fgl.yacc"
    {
yyval.sql_string=make_sql_string(yyvsp[-5].str," ",yyvsp[-4].str," ",yyvsp[-3].str," ",yyvsp[-2].str," ",yyvsp[-1].sql_string," ",yyvsp[0].str,0);
}
    break;

  case 1389:
#line 6900 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1390:
#line 6902 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1392:
#line 6908 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1393:
#line 6911 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1395:
#line 6917 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("CHECK(",yyvsp[-1].sql_string,")",0);
	}
    break;

  case 1396:
#line 6925 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s %s",yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1397:
#line 6930 "fgl.yacc"
    {sprintf(yyval.str," %s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1400:
#line 6940 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1402:
#line 6946 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1403:
#line 6952 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1404:
#line 6954 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1406:
#line 6960 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1407:
#line 6965 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1408:
#line 6968 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1409:
#line 6971 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1410:
#line 6979 "fgl.yacc"
    {sprintf(yyval.str," %s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1411:
#line 6981 "fgl.yacc"
    {sprintf(yyval.str," %s",yyvsp[0].str);}
    break;

  case 1412:
#line 6994 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-3].str," ",yyvsp[-2].str," ",yyvsp[-1].str," ",yyvsp[0].sql_string,0);
	}
    break;

  case 1413:
#line 6999 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1415:
#line 7003 "fgl.yacc"
    {
		yyval.sql_string=strdup("");
	}
    break;

  case 1416:
#line 7005 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1417:
#line 7012 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1418:
#line 7015 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-1].sql_string,yyvsp[0].sql_string,0);
	}
    break;

  case 1419:
#line 7021 "fgl.yacc"
    {
		sprintf(yyval.str," %s ",yyvsp[0].str);
		yyval.sql_string=strdup(yyval.str);
	}
    break;

  case 1420:
#line 7025 "fgl.yacc"
    {
		sprintf(yyval.str," %s ",yyvsp[0].str);
		yyval.sql_string=strdup(yyval.str);
	}
    break;

  case 1421:
#line 7029 "fgl.yacc"
    {
		sprintf(yyval.str," %s ",yyvsp[0].str);
		yyval.sql_string=strdup(yyval.str);
	}
    break;

  case 1422:
#line 7033 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1423:
#line 7036 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-3].str," ",yyvsp[-2].str," ",yyvsp[-1].sql_string," ",yyvsp[0].str,0);
	}
    break;

  case 1424:
#line 7044 "fgl.yacc"
    {
yyval.sql_string=make_sql_string(yyvsp[-2].str," ",yyvsp[-1].str," ",yyvsp[0].str,0);
}
    break;

  case 1425:
#line 7051 "fgl.yacc"
    {sprintf(yyval.str," %s",yyvsp[0].str);}
    break;

  case 1428:
#line 7060 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-1].sql_string," ",yyvsp[0].sql_string,0);
	}
    break;

  case 1429:
#line 7066 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1430:
#line 7069 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1431:
#line 7080 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-1].str," ",yyvsp[0].sql_string,0);
	}
    break;

  case 1432:
#line 7087 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("GROUP BY ",yyvsp[0].sql_string,0);
	}
    break;

  case 1433:
#line 7093 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1434:
#line 7096 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",",yyvsp[0].sql_string,0);
	}
    break;

  case 1435:
#line 7103 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("WHERE ",yyvsp[0].sql_string,0);
	}
    break;

  case 1436:
#line 7110 "fgl.yacc"
    {
		sprintf(yyval.str,"%s %s",yyvsp[-1].str,yyvsp[0].str);
	}
    break;

  case 1438:
#line 7117 "fgl.yacc"
    {
		sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);
	}
    break;

  case 1439:
#line 7123 "fgl.yacc"
    {sprintf(yyval.str," %s ", yyvsp[0].str);}
    break;

  case 1440:
#line 7124 "fgl.yacc"
    {sprintf(yyval.str," %s %s ",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1441:
#line 7125 "fgl.yacc"
    {sprintf(yyval.str," %s (%s) ",yyvsp[-3].str,yyvsp[-1].str);}
    break;

  case 1443:
#line 7129 "fgl.yacc"
    {sprintf(yyval.str,"%s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1445:
#line 7134 "fgl.yacc"
    { sprintf(yyval.str," %s,%s ",yyvsp[-2].str,yyvsp[0].str);  }
    break;

  case 1446:
#line 7141 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-3].str," ",yyvsp[-2].sql_string," ",yyvsp[-1].sql_string," ",yyvsp[0].sql_string,0);
	}
    break;

  case 1447:
#line 7146 "fgl.yacc"
    { yyval.sql_string=strdup("");}
    break;

  case 1448:
#line 7147 "fgl.yacc"
    {yyval.sql_string=yyvsp[0].sql_string;}
    break;

  case 1449:
#line 7150 "fgl.yacc"
    {
	yyval.sql_string=strdup("");
}
    break;

  case 1450:
#line 7153 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
}
    break;

  case 1451:
#line 7158 "fgl.yacc"
    {yyval.sql_string=strdup("");}
    break;

  case 1452:
#line 7159 "fgl.yacc"
    {yyval.sql_string=yyvsp[0].sql_string;}
    break;

  case 1453:
#line 7164 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1454:
#line 7167 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string," OR ",yyvsp[0].sql_string,0);
	}
    break;

  case 1455:
#line 7173 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1456:
#line 7176 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string," AND ",yyvsp[0].sql_string,0);
	}
    break;

  case 1457:
#line 7182 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1458:
#line 7185 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-1].str," ",yyvsp[0].sql_string,0);
	}
    break;

  case 1459:
#line 7191 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1460:
#line 7194 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].str,yyvsp[-1].sql_string,yyvsp[0].str,0);
	}
    break;

  case 1461:
#line 7201 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-1].str," ",yyvsp[0].sql_string,0);}
    break;

  case 1462:
#line 7202 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-1].str," ",yyvsp[0].sql_string,0);}
    break;

  case 1463:
#line 7231 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1464:
#line 7233 "fgl.yacc"
    {sprintf(yyval.str," %s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1465:
#line 7237 "fgl.yacc"
    {yyval.sql_string=yyvsp[0].sql_string;}
    break;

  case 1467:
#line 7250 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-4].sql_string," IN (",yyvsp[-1].str,")",0);
	}
    break;

  case 1468:
#line 7253 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string," ",yyvsp[-1].str," ",yyvsp[0].sql_string,0);
	}
    break;

  case 1469:
#line 7256 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-4].sql_string," NOT IN (",yyvsp[-1].str,")",0);
	}
    break;

  case 1470:
#line 7259 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string," ",yyvsp[-1].str," ",yyvsp[0].sql_string,0);
	}
    break;

  case 1472:
#line 7267 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1473:
#line 7270 "fgl.yacc"
    {
		strcpy(yyval.str,yyvsp[0].sql_string);
	}
    break;

  case 1475:
#line 7276 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1477:
#line 7282 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string," ",yyvsp[-1].str," IS NULL",0);
	}
    break;

  case 1478:
#line 7285 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string," ",yyvsp[-1].str," IS NOT NULL",0);
	}
    break;

  case 1479:
#line 7288 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string," ",yyvsp[-1].str," ",yyvsp[0].sql_string,0);
	}
    break;

  case 1480:
#line 7291 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-5].sql_string," ",yyvsp[-4].str," BETWEEN ",yyvsp[-2].sql_string," AND ",yyvsp[0].sql_string,0);
	}
    break;

  case 1481:
#line 7294 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-3].sql_string," ",yyvsp[-2].str," ",yyvsp[-1].sql_string,yyvsp[0].str,0);
	}
    break;

  case 1482:
#line 7297 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-3].sql_string," ",yyvsp[-2].str," ",yyvsp[-1].sql_string,yyvsp[0].str,0);
	}
    break;

  case 1483:
#line 7300 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-3].sql_string," ",yyvsp[-2].str," ",yyvsp[-1].sql_string,yyvsp[0].str,0);
	}
    break;

  case 1484:
#line 7303 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-3].sql_string," ",yyvsp[-2].str," ",yyvsp[-1].sql_string,yyvsp[0].str,0);
	}
    break;

  case 1485:
#line 7308 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-4].sql_string," ",yyvsp[-3].str," MATCHES ",yyvsp[-1].sql_string,yyvsp[0].str,0);
	}
    break;

  case 1487:
#line 7315 "fgl.yacc"
    {strcpy(yyval.str,"!=");}
    break;

  case 1493:
#line 7323 "fgl.yacc"
    {strcpy(yyval.str,"<=");}
    break;

  case 1494:
#line 7324 "fgl.yacc"
    {strcpy(yyval.str,">=");}
    break;

  case 1495:
#line 7329 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1496:
#line 7332 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1497:
#line 7336 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1498:
#line 7342 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1499:
#line 7343 "fgl.yacc"
    {strcpy(yyval.str," ALL ");}
    break;

  case 1500:
#line 7344 "fgl.yacc"
    {strcpy(yyval.str," DISTINCT ");}
    break;

  case 1501:
#line 7345 "fgl.yacc"
    {
		ansi_violation("Use DISTINCT not UNIQUE",0);
		strcpy(yyval.str," DISTINCT ");
	}
    break;

  case 1506:
#line 7365 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1507:
#line 7370 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s %s",yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1508:
#line 7371 "fgl.yacc"
    {strcpy(yyval.str,"SERIAL");}
    break;

  case 1510:
#line 7374 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s %s",yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1514:
#line 7379 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1516:
#line 7382 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1518:
#line 7385 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s %s %s %s",yyvsp[-6].str,yyvsp[-5].str,yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1522:
#line 7390 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1523:
#line 7392 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s %s %s",yyvsp[-5].str,yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1524:
#line 7395 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1525:
#line 7396 "fgl.yacc"
    {
		sprintf(yyval.str,",%s",yyvsp[0].str);
}
    break;

  case 1526:
#line 7403 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1530:
#line 7408 "fgl.yacc"
    {sprintf(yyval.str," %s",yyvsp[0].str);}
    break;

  case 1534:
#line 7424 "fgl.yacc"
    { sprintf(yyval.str,"\\\"%s\\\"%s%s", A4GL_strip_quotes (yyvsp[-2].str),yyvsp[-1].str,yyvsp[0].str); addmap("Use Table",yyval.str,curr_func,yylineno,infilename); }
    break;

  case 1535:
#line 7425 "fgl.yacc"
    {
		sprintf(yyval.str," %s", A4GL_strip_quotes (yyvsp[0].str));
		addmap("Use Table",yyval.str,curr_func,yylineno,infilename);
	}
    break;

  case 1536:
#line 7429 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str); addmap("Use Table",yyvsp[0].str,curr_func,yylineno,infilename); }
    break;

  case 1537:
#line 7430 "fgl.yacc"
    { sprintf(yyval.str," %s%s%s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str); addmap("Use Table",yyval.str,curr_func,yylineno,infilename); }
    break;

  case 1539:
#line 7449 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1540:
#line 7450 "fgl.yacc"
    {sprintf(yyval.str,"[%s]",yyvsp[-1].str);}
    break;

  case 1541:
#line 7451 "fgl.yacc"
    {sprintf(yyval.str,"[%s,%s]",yyvsp[-3].str,yyvsp[-1].str);}
    break;

  case 1542:
#line 7455 "fgl.yacc"
    {
		strcpy(yyval.str,yyvsp[0].str);
	}
    break;

  case 1543:
#line 7458 "fgl.yacc"
    {
		strcpy(yyval.str,yyvsp[0].str);
	}
    break;

  case 1544:
#line 7464 "fgl.yacc"
    { 
addmap("Use Column",yyvsp[-1].str,curr_func,yylineno,infilename);
sprintf(yyval.str,"%s%s",yyvsp[-1].str,yyvsp[0].str);
}
    break;

  case 1545:
#line 7469 "fgl.yacc"
    {
sprintf(yyval.str,"%s.%s%s",yyvsp[-3].str,yyvsp[-1].str,yyvsp[0].str);
addmap("Use Column",yyval.str,curr_func,yylineno,infilename);
}
    break;

  case 1546:
#line 7474 "fgl.yacc"
    {
sprintf(yyval.str,"%s.%s",yyvsp[-2].str,yyvsp[0].str);
addmap("Use Column",yyval.str,curr_func,yylineno,infilename);
}
    break;

  case 1548:
#line 7485 "fgl.yacc"
    {
	strcpy(yyval.str,convstrsql(yyvsp[0].str));
 A4GL_debug("Set $<str>$ to %s\n",yyval.str);
}
    break;

  case 1553:
#line 7500 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1554:
#line 7503 "fgl.yacc"
    {
char *ptr;
ptr=acl_getenv("SQL_CURRENT_FUNCTION");
if (ptr!=0) { if (strlen(ptr)==0) ptr=0; }

if (ptr) {
	sprintf(yyval.str," %s(%s) ",ptr,yyvsp[0].str);
} else {
	sprintf(yyval.str," %s %s ",yyvsp[-1].str,yyvsp[0].str);
}
}
    break;

  case 1555:
#line 7516 "fgl.yacc"
    {
//char *ptr;

//ptr=acl_getenv("SQL_CURRENT_FUNCTION");

//if (ptr!=0) { if (strlen(ptr)==0) ptr=0; }

//if (ptr) {
	sprintf(yyval.str,"'%s','%s'","YEAR","SECOND");
//} else {
	strcpy(yyval.str," YEAR TO SECOND ");
//}
	strcpy(yyval.str,"");
}
    break;

  case 1556:
#line 7531 "fgl.yacc"
    {
char *ptr;
ptr=acl_getenv("SQL_CURRENT_FUNCTION");
if (ptr!=0) { if (strlen(ptr)==0) ptr=0; }
if (ptr) {
	sprintf(yyval.str,"'%s','%s'",yyvsp[-2].str,yyvsp[0].str);
} else {
	sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);
}
}
    break;

  case 1557:
#line 7543 "fgl.yacc"
    {strcpy(yyval.str,"1,10");}
    break;

  case 1558:
#line 7545 "fgl.yacc"
    {sprintf(yyval.str," %s ,%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1559:
#line 7548 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 1560:
#line 7548 "fgl.yacc"
    {strcpy(yyval.str,"2");}
    break;

  case 1561:
#line 7548 "fgl.yacc"
    {strcpy(yyval.str,"3");}
    break;

  case 1562:
#line 7548 "fgl.yacc"
    {strcpy(yyval.str,"4");}
    break;

  case 1563:
#line 7548 "fgl.yacc"
    {strcpy(yyval.str,"5");}
    break;

  case 1564:
#line 7548 "fgl.yacc"
    {strcpy(yyval.str,"6");}
    break;

  case 1565:
#line 7549 "fgl.yacc"
    {
sprintf(yyval.str,"%d",6+2);
}
    break;

  case 1566:
#line 7552 "fgl.yacc"
    {
sprintf(yyval.str,"%d",atoi(yyvsp[-1].str)+6);
}
    break;

  case 1567:
#line 7557 "fgl.yacc"
    {strcpy(yyval.str,"4");}
    break;

  case 1568:
#line 7557 "fgl.yacc"
    {strcpy(yyval.str,"7");}
    break;

  case 1569:
#line 7557 "fgl.yacc"
    {strcpy(yyval.str,"10");}
    break;

  case 1570:
#line 7557 "fgl.yacc"
    {strcpy(yyval.str,"13");}
    break;

  case 1571:
#line 7557 "fgl.yacc"
    {strcpy(yyval.str,"16");}
    break;

  case 1572:
#line 7557 "fgl.yacc"
    {strcpy(yyval.str,"19");}
    break;

  case 1573:
#line 7559 "fgl.yacc"
    {
strcpy(yyval.str,"25");
}
    break;

  case 1574:
#line 7562 "fgl.yacc"
    {
strcpy(yyval.str,"25");
}
    break;

  case 1589:
#line 7569 "fgl.yacc"
    {sprintf(yyval.str,"FRACTION(%s)",yyvsp[-1].str);}
    break;

  case 1590:
#line 7572 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1591:
#line 7573 "fgl.yacc"
    {sprintf(yyval.str,"%s@%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1592:
#line 7574 "fgl.yacc"
    {strcpy(yyval.str, A4GL_strip_quotes (yyvsp[0].str));}
    break;

  case 1593:
#line 7578 "fgl.yacc"
    {
	print_flush_cursor(yyvsp[0].str);
		addmap("Flush Cursor",yyvsp[0].str,curr_func,yylineno,infilename);
print_undo_use(yyvsp[-2].str);
		}
    break;

  case 1594:
#line 7586 "fgl.yacc"
    {insql=0;chk4var=0;}
    break;

  case 1595:
#line 7586 "fgl.yacc"
    {
		print_declare("",yyvsp[-1].sql_string,yyvsp[-4].str,0,0);
		addmap("Declare Cursor",yyvsp[-4].str,curr_func,yylineno,infilename);
		print_undo_use(yyvsp[-6].str);
		doing_declare=0;
	}
    break;

  case 1596:
#line 7592 "fgl.yacc"
    {insql=0;chk4var=0;}
    break;

  case 1597:
#line 7592 "fgl.yacc"
    {
		print_declare("",yyvsp[-1].sql_string,yyvsp[-5].str,2,0); 
		addmap("Declare Cursor",yyvsp[-5].str,curr_func,yylineno,infilename);
		print_undo_use(yyvsp[-7].str);
		doing_declare=0;
	}
    break;

  case 1598:
#line 7599 "fgl.yacc"
    {insql=0;chk4var=0;}
    break;

  case 1599:
#line 7599 "fgl.yacc"
    {
		print_declare("",yyvsp[-1].sql_string,yyvsp[-3].str,0,1); 
		addmap("Declare Cursor",yyvsp[-3].str,curr_func,yylineno,infilename);
		print_undo_use(yyvsp[-5].str);
		doing_declare=0;
	}
    break;

  case 1600:
#line 7605 "fgl.yacc"
    {insql=0;chk4var=0;}
    break;

  case 1601:
#line 7605 "fgl.yacc"
    {
		print_declare("",yyvsp[-1].sql_string,yyvsp[-5].str,2,1); 
		addmap("Declare Cursor",yyvsp[-5].str,curr_func,yylineno,infilename);
		print_undo_use(yyvsp[-7].str);
		doing_declare=0;
	}
    break;

  case 1602:
#line 7613 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1603:
#line 7614 "fgl.yacc"
    {strcpy(yyval.str," FOR UPDATE");}
    break;

  case 1604:
#line 7615 "fgl.yacc"
    {sprintf(yyval.str," FOR UPDATE OF %s",yyvsp[0].str);}
    break;

  case 1605:
#line 7618 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1606:
#line 7618 "fgl.yacc"
    {sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1608:
#line 7622 "fgl.yacc"
    {sprintf(yyval.str,"%s.%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1609:
#line 7623 "fgl.yacc"
    {sprintf(yyval.str,"\\\"%s\\\".%s.%s", A4GL_strip_quotes (yyvsp[-4].str),yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1610:
#line 7628 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1611:
#line 7631 "fgl.yacc"
    { 
		yyval.sql_string=make_sql_string(print_curr_spec(1,yyvsp[0].sql_string),0);
	}
    break;

  case 1612:
#line 7637 "fgl.yacc"
    {
		start_bind('i',0);
		start_bind('o',0);
		yyval.sql_string=make_sql_string(print_curr_spec(2,yyvsp[0].str) ,0);
	}
    break;

  case 1613:
#line 7642 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1614:
#line 7650 "fgl.yacc"
    {
	yyval.sql_string=yyvsp[0].sql_string;
	if (strstr(yyvsp[0].str,"FOR UPDATE")) {
		printf("Warning SELECT ... FOR UPDATE when not declaring a cursor currently has no locking effect\n");
	}
}
    break;

  case 1615:
#line 7662 "fgl.yacc"
    { start_bind('i',0); }
    break;

  case 1616:
#line 7663 "fgl.yacc"
    {A4GL_debug("Got select list...\n");}
    break;

  case 1617:
#line 7666 "fgl.yacc"
    {
		char *ptr;
                ptr=make_sql_string("SELECT ",yyvsp[-7].str, yyvsp[-5].sql_string," ", yyvsp[-3].sql_string, " ",yyvsp[-2].sql_string," ",yyvsp[-1].sql_string,yyvsp[0].str,0);

		yyval.sql_string=strdup(print_select_all(ptr));
		free(ptr);
		free(yyvsp[-5].sql_string);
		free(yyvsp[-3].sql_string);
		free(yyvsp[-2].sql_string);
		free(yyvsp[-1].sql_string);
}
    break;

  case 1618:
#line 7681 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("A4GL_push_char(\"", yyvsp[-4].str, " ",yyvsp[-3].str," ", yyvsp[-2].sql_string, " ",yyvsp[-1].sql_string, " ",yyvsp[0].sql_string, "\");",0);
	free(yyvsp[-2].sql_string);
	free(yyvsp[-1].sql_string);
	free(yyvsp[0].sql_string);
}
    break;

  case 1619:
#line 7691 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	 }
    break;

  case 1620:
#line 7694 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1621:
#line 7702 "fgl.yacc"
    {
	yyval.sql_string=make_sql_string(yyvsp[-5].str, " ",yyvsp[-4].str," ",yyvsp[-3].sql_string," ", yyvsp[-2].sql_string," ", yyvsp[-1].sql_string, " ",yyvsp[0].sql_string,0);
	free(yyvsp[-3].sql_string);
	free(yyvsp[-1].sql_string);
	free(yyvsp[0].sql_string);
}
    break;

  case 1622:
#line 7711 "fgl.yacc"
    {
		yyval.sql_string=strdup("");
		}
    break;

  case 1623:
#line 7714 "fgl.yacc"
    {
       A4GL_lex_printcomment("/* UNION */");
	yyval.sql_string=make_sql_string(yyvsp[-2].str," ",yyvsp[-1].str," ",yyvsp[0].sql_string,0);
       }
    break;

  case 1624:
#line 7718 "fgl.yacc"
    {
	yyval.sql_string=strdup(yyvsp[0].str);
}
    break;

  case 1625:
#line 7721 "fgl.yacc"
    { yyval.sql_string=make_sql_string(yyvsp[-2].str," ",yyvsp[-1].str," ",yyvsp[0].str,0); }
    break;

  case 1626:
#line 7722 "fgl.yacc"
    { 
	yyval.sql_string=make_sql_string(yyvsp[-3].str," ",yyvsp[-2].str," ",yyvsp[-1].str," ",yyvsp[0].str,0);
}
    break;

  case 1628:
#line 7731 "fgl.yacc"
    { start_bind('o',0);yyval.sql_string=make_sql_string("",0); }
    break;

  case 1629:
#line 7732 "fgl.yacc"
    { 
		yyval.sql_string=make_sql_string(A4GL_get_into_part(doing_declare,get_bind_cnt('o')),0 ); 

	}
    break;

  case 1630:
#line 7741 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-3].str," ",yyvsp[-2].str," ", yyvsp[-1].sql_string," ",yyvsp[0].sql_string,0);
		free(yyvsp[-1].sql_string);
		//free($<sql_string>4);

	}
    break;

  case 1631:
#line 7750 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("(",yyvsp[-4].str," ",yyvsp[-3].str," ",yyvsp[-2].sql_string," ",yyvsp[-1].sql_string,")",0);
	}
    break;

  case 1632:
#line 7755 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1633:
#line 7756 "fgl.yacc"
    {strcpy(yyval.str,"ALL ");}
    break;

  case 1634:
#line 7757 "fgl.yacc"
    {strcpy(yyval.str," DISTINCT ");}
    break;

  case 1635:
#line 7758 "fgl.yacc"
    {strcpy(yyval.str," DISTINCT ");
		ansi_violation("Use DISTINCT not UNIQUE",0);
		strcpy(yyval.str," DISTINCT ");
}
    break;

  case 1636:
#line 7765 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1637:
#line 7768 "fgl.yacc"
    { 
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",",yyvsp[0].sql_string,0);
	}
    break;

  case 1638:
#line 7774 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1639:
#line 7777 "fgl.yacc"
    {
		if (A4GL_isyes(acl_getenv("A4GL_USE_ALIAS_AS"))) {
			yyval.sql_string=make_sql_string(yyvsp[-1].sql_string," AS ",yyvsp[0].str,0);
		} else {
			yyval.sql_string=make_sql_string(yyvsp[-1].sql_string," ",yyvsp[0].str,0);
		}
	}
    break;

  case 1640:
#line 7787 "fgl.yacc"
    {
	yyval.sql_string=yyvsp[0].sql_string;
}
    break;

  case 1641:
#line 7796 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1642:
#line 7799 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("-",yyvsp[0].sql_string,0);
	}
    break;

  case 1643:
#line 7802 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("+",yyvsp[0].sql_string,0);
	}
    break;

  case 1644:
#line 7808 "fgl.yacc"
    {
			if (strlen(current_upd_table)) {
				push_gen(UPDVAL,yyvsp[0].sql_string);
			}
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1645:
#line 7814 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1646:
#line 7817 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1647:
#line 7820 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1648:
#line 7823 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].str,".",yyvsp[0].str);
	}
    break;

  case 1649:
#line 7830 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,"/",yyvsp[0].sql_string,0);}
    break;

  case 1650:
#line 7832 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-1].sql_string," ",yyvsp[0].str,0);}
    break;

  case 1651:
#line 7834 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,"*",yyvsp[0].sql_string,0);}
    break;

  case 1652:
#line 7836 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,"+",yyvsp[0].sql_string,0);}
    break;

  case 1653:
#line 7838 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,"-",yyvsp[0].sql_string,0);}
    break;

  case 1654:
#line 7839 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[0].str,0);}
    break;

  case 1655:
#line 7840 "fgl.yacc"
    {yyval.sql_string=make_sql_string("1",0);}
    break;

  case 1656:
#line 7841 "fgl.yacc"
    {yyval.sql_string=make_sql_string("0",0);}
    break;

  case 1657:
#line 7842 "fgl.yacc"
    {yyval.sql_string=make_sql_string("USER",0);}
    break;

  case 1658:
#line 7843 "fgl.yacc"
    {yyval.sql_string=make_sql_string("*",0);}
    break;

  case 1659:
#line 7844 "fgl.yacc"
    {yyval.sql_string=make_sql_string("COUNT(*)",0);}
    break;

  case 1660:
#line 7846 "fgl.yacc"
    {yyval.sql_string=make_sql_string("AVG(",yyvsp[-2].str,yyvsp[-1].sql_string,")",0);}
    break;

  case 1661:
#line 7848 "fgl.yacc"
    {yyval.sql_string=make_sql_string("MAX(",yyvsp[-2].str,yyvsp[-1].sql_string,")",0);}
    break;

  case 1662:
#line 7850 "fgl.yacc"
    {yyval.sql_string=make_sql_string("MIN(",yyvsp[-2].str,yyvsp[-1].sql_string,")",0);}
    break;

  case 1663:
#line 7852 "fgl.yacc"
    {yyval.sql_string=make_sql_string("SUM(",yyvsp[-2].str,yyvsp[-1].sql_string,")",0);}
    break;

  case 1664:
#line 7854 "fgl.yacc"
    {yyval.sql_string=make_sql_string("COUNT(",yyvsp[-2].str,yyvsp[-1].sql_string,")",0);}
    break;

  case 1665:
#line 7856 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-3].str,"(",yyvsp[-1].sql_string,")",0);}
    break;

  case 1666:
#line 7858 "fgl.yacc"
    {yyval.sql_string=make_sql_string("DATE(",yyvsp[-1].sql_string,")",0);}
    break;

  case 1667:
#line 7859 "fgl.yacc"
    {yyval.sql_string=make_sql_string("(",yyvsp[-1].sql_string,")",0);}
    break;

  case 1668:
#line 7861 "fgl.yacc"
    {yyval.sql_string=make_sql_string("EXTEND(",yyvsp[-1].sql_string,")",0);}
    break;

  case 1669:
#line 7865 "fgl.yacc"
    {yyval.sql_string=yyvsp[0].sql_string;}
    break;

  case 1670:
#line 7866 "fgl.yacc"
    {
	yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",",yyvsp[0].sql_string,0);
}
    break;

  case 1672:
#line 7876 "fgl.yacc"
    {

print_unload(yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].sql_string);
print_undo_use(yyvsp[-4].str);
}
    break;

  case 1673:
#line 7885 "fgl.yacc"
    {
print_load(yyvsp[-4].str,yyvsp[-3].str,yyvsp[-1].str,yyvsp[0].str);
print_undo_use(yyvsp[-6].str);
}
    break;

  case 1674:
#line 7889 "fgl.yacc"
    {
print_load_str(yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);
print_undo_use(yyvsp[-4].str);
}
    break;

  case 1675:
#line 7896 "fgl.yacc"
    {strcpy(yyval.str,"\"|\"");}
    break;

  case 1676:
#line 7896 "fgl.yacc"
    {
strcpy(yyval.str,yyvsp[0].str);
}
    break;

  case 1678:
#line 7900 "fgl.yacc"
    {
if ((scan_variable(yyvsp[0].str)&15)!=0) {a4gl_yyerror("Variable must be of type char for a delimiter..");YYERROR;}
}
    break;

  case 1679:
#line 7905 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 1680:
#line 7905 "fgl.yacc"
    {
sprintf(yyval.str,"%s,0",yyvsp[-1].str);
}
    break;

  case 1682:
#line 7909 "fgl.yacc"
    {
    sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 1683:
#line 7913 "fgl.yacc"
    {
     sprintf(yyval.str,"\"%s\"",yyvsp[0].str);
}
    break;

  case 1686:
#line 7922 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1687:
#line 7922 "fgl.yacc"
    {
print_use_session(yyvsp[0].str);
strcpy(yyval.str,A4GL_get_undo_use());
}
    break;

  case 1692:
#line 7941 "fgl.yacc"
    { sprintf(yyval.str,"%s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str); }
    break;

  case 1693:
#line 7942 "fgl.yacc"
    { sprintf(yyval.str,"%s %s %s %s",yyvsp[-5].str,yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str); }
    break;

  case 1696:
#line 7950 "fgl.yacc"
    {
		sprintf(yyval.str,"%s %s",yyvsp[-1].str,yyvsp[0].str);
	}
    break;

  case 1697:
#line 7956 "fgl.yacc"
    {
		sprintf(yyval.str,"%s %s %s",
					yyvsp[-2].str,
					yyvsp[-1].str,
					yyvsp[0].str
					);
		}
    break;

  case 1700:
#line 7975 "fgl.yacc"
    {strcpy(yyval.str,"UNITS YEAR");}
    break;

  case 1701:
#line 7976 "fgl.yacc"
    {strcpy(yyval.str,"UNITS MONTH"); }
    break;

  case 1702:
#line 7977 "fgl.yacc"
    {strcpy(yyval.str,"UNITS DAY"); }
    break;

  case 1703:
#line 7978 "fgl.yacc"
    {strcpy(yyval.str,"UNITS HOUR"); }
    break;

  case 1704:
#line 7979 "fgl.yacc"
    {strcpy(yyval.str,"UNITS MINUTE"); }
    break;

  case 1705:
#line 7980 "fgl.yacc"
    {strcpy(yyval.str,"UNITS SECOND"); }
    break;

  case 1706:
#line 7984 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str," ",yyvsp[-1].str," ",yyvsp[0].str,0);}
    break;

  case 1707:
#line 7985 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-4].sql_string,yyvsp[-3].str,yyvsp[-2].str," ",yyvsp[-1].str," ",yyvsp[0].str,0);}
    break;

  case 1708:
#line 7986 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-3].str,yyvsp[-2].str," ",yyvsp[-1].str," ",yyvsp[0].str,0);}
    break;

  case 1709:
#line 7990 "fgl.yacc"
    {
		sql_mode=1;
		start_bind('i',0);
		start_bind('o',0);
	}
    break;

  case 1710:
#line 7994 "fgl.yacc"
    {
			sql_mode=0;
			print_sql_block_cmd(yyvsp[-1].str);
	}
    break;

  case 1712:
#line 8003 "fgl.yacc"
    {sprintf(yyval.str,"%s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1714:
#line 8008 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1715:
#line 8009 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 2035:
#line 8336 "fgl.yacc"
    {sql_mode=0;}
    break;

  case 2036:
#line 8336 "fgl.yacc"
    {
		strcpy(yyval.str,yyvsp[0].sql_string);
		sql_mode=1;
	}
    break;

  case 2037:
#line 8343 "fgl.yacc"
    {sql_mode=0;}
    break;

  case 2038:
#line 8343 "fgl.yacc"
    {
 		strcpy(yyval.str,A4GL_get_into_part(doing_declare,get_bind_cnt('o')));
		sql_mode=1;
	}
    break;

  case 2039:
#line 8431 "fgl.yacc"
    {
		strcpy(current_upd_table,yyvsp[0].str);
		pop_all_gen(UPDCOL,"!"); pop_all_gen(UPDVAL,"!"); pop_all_gen(UPDVAL2,"!");
		yyval.sql_string=strdup("");
	}
    break;

  case 2040:
#line 8435 "fgl.yacc"
    {
		strcpy(current_upd_table,"");
	}
    break;

  case 2041:
#line 8437 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-5].str," ",yyvsp[-4].str," ",yyvsp[-2].sql_string," ",yyvsp[0].sql_string,0);
	}
    break;

  case 2042:
#line 8444 "fgl.yacc"
    {
		pop_all_gen(UPDCOL,"!"); pop_all_gen(UPDVAL,"!"); pop_all_gen(UPDVAL2,"!");
		yyval.sql_string=strdup("");
	}
    break;

  case 2043:
#line 8448 "fgl.yacc"
    { 
		pop_all_gen(UPDCOL,"!"); pop_all_gen(UPDVAL,"!"); pop_all_gen(UPDVAL2,"!");
		rm_quotes(yyvsp[0].str);
		sprintf(yyval.str,"%s %s",yyvsp[-1].str,yyvsp[0].str);
		yyval.sql_string=make_sql_string(yyval.str,0);
	}
    break;

  case 2044:
#line 8454 "fgl.yacc"
    {
		pop_all_gen(UPDCOL,"!"); pop_all_gen(UPDVAL,"!"); pop_all_gen(UPDVAL2,"!");
		yyval.sql_string=make_sql_string("WHERE ",yyvsp[0].sql_string,0);
	}
    break;

  case 2045:
#line 8462 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("SET (",yyvsp[-5].str,")=(",yyvsp[-1].sql_string,")",0);

		if (A4GL_isyes(acl_getenv("FIXUPDATE"))) { 
			yyval.sql_string=strdup(fix_update_expr(0)); 
			ansi_violation("Update (..)=(..)",0);
		}  else {
			ansi_violation("Update (..)=(..)",1);
		}
    }
    break;

  case 2046:
#line 8472 "fgl.yacc"
    {	
		yyval.sql_string=make_sql_string("SET *=(",yyvsp[-1].sql_string,")",0);
		push_gen(UPDCOL,"*");
		if (A4GL_isyes(acl_getenv("FIXUPDATE"))||1) { 
			yyval.sql_string=strdup(fix_update_expr(1));
			ansi_violation("Update (..)=(..)",0);
		} else {
			ansi_violation("Update (..)=(..)",1);
		}
    }
    break;

  case 2047:
#line 8482 "fgl.yacc"
    {	
		yyval.sql_string=make_sql_string("SET *=(",yyvsp[-1].sql_string,")",0);
		push_gen(UPDCOL,"*");
		if (A4GL_isyes(acl_getenv("FIXUPDATE"))||1) { 
			yyval.sql_string=strdup(fix_update_expr(1));
			ansi_violation("Update (..)=(..)",0);
		} else {
			ansi_violation("Update (..)=(..)",1);
		}
    }
    break;

  case 2048:
#line 8494 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("SET ",yyvsp[0].sql_string,0);
    }
    break;

  case 2049:
#line 8497 "fgl.yacc"
    {
		char *ptr;

		ptr=yyvsp[0].sql_string;
		push_gen(UPDCOL,"*");

		if (ptr[0]=='(') {
			yyval.sql_string=make_sql_string("SET *= ",yyvsp[0].sql_string,0);
		} else {
			yyval.sql_string=make_sql_string("SET *=(",yyvsp[0].sql_string,")",0);
		}

		if (A4GL_isyes(acl_getenv("FIXUPDATE"))||1) { 
			yyval.sql_string=strdup(fix_update_expr(1));
			ansi_violation("Update (..)=(..)",0);
		} else {
			ansi_violation("Update (..)=(..)",1);
		}
	}
    break;

  case 2050:
#line 8516 "fgl.yacc"
    {
		char *ptr;

		ptr=yyvsp[0].sql_string;
		push_gen(UPDCOL,"*");

		if (ptr[0]=='(') {
			yyval.sql_string=make_sql_string("SET *= ",yyvsp[0].sql_string,0);
		} else {
			yyval.sql_string=make_sql_string("SET *=(",yyvsp[0].sql_string,")",0);
		}

		if (A4GL_isyes(acl_getenv("FIXUPDATE"))||1) { 
			yyval.sql_string=strdup(fix_update_expr(1));
			ansi_violation("Update (..)=(..)",0);
		} else {
			ansi_violation("Update (..)=(..)",1);
		}
	}
    break;

  case 2051:
#line 8542 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 2052:
#line 8545 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",",yyvsp[0].sql_string,0);
	}
    break;

  case 2054:
#line 8554 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].str,"=",yyvsp[0].sql_string,0);
	}
    break;

  case 2055:
#line 8559 "fgl.yacc"
    {
			push_gen(UPDCOL,yyvsp[0].str); strcpy(yyval.str,yyvsp[0].str);
		}
    break;

  case 2056:
#line 8562 "fgl.yacc"
    {
			push_gen(UPDCOL,yyvsp[0].str); sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);
		}
    break;

  case 2057:
#line 8570 "fgl.yacc"
    { 
		yyval.sql_string=yyvsp[0].sql_string; 
		if (gen_cnt(UPDVAL2)) {
			copy_gen(UPDVAL,UPDVAL2);
		} else {
                	push_gen(UPDVAL,yyvsp[0].sql_string);
		}
	}
    break;

  case 2058:
#line 8578 "fgl.yacc"
    { 
		if (gen_cnt(UPDVAL2)) {
			copy_gen(UPDVAL,UPDVAL2);
		} else {
                	push_gen(UPDVAL,yyvsp[0].sql_string);
		}
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",",yyvsp[0].sql_string,0); 
	}
    break;

  case 2059:
#line 8591 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 2060:
#line 8594 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 2061:
#line 8602 "fgl.yacc"
    {
                yyval.sql_string=yyvsp[0].sql_string;
        }
    break;

  case 2062:
#line 8605 "fgl.yacc"
    {
                yyval.sql_string=make_sql_string("-",yyvsp[0].sql_string,0);
        }
    break;

  case 2063:
#line 8608 "fgl.yacc"
    {
                yyval.sql_string=make_sql_string("+",yyvsp[0].sql_string,0);
        }
    break;

  case 2064:
#line 8616 "fgl.yacc"
    {
                yyval.sql_string=yyvsp[0].sql_string;

        }
    break;

  case 2065:
#line 8620 "fgl.yacc"
    {
                yyval.sql_string=yyvsp[0].sql_string;
        }
    break;

  case 2066:
#line 8623 "fgl.yacc"
    {
                yyval.sql_string=strdup(yyvsp[0].str);
        }
    break;

  case 2067:
#line 8626 "fgl.yacc"
    {
                yyval.sql_string=make_sql_string(yyvsp[-2].str,".",yyvsp[0].str);
        }
    break;

  case 2068:
#line 8629 "fgl.yacc"
    { 
		yyval.sql_string=yyvsp[0].sql_string; 
		pop_all_gen(UPDVAL2,"!");
	}
    break;

  case 2069:
#line 8633 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[0].str,0);}
    break;

  case 2070:
#line 8634 "fgl.yacc"
    {yyval.sql_string=make_sql_string("TRUE",0);}
    break;

  case 2071:
#line 8635 "fgl.yacc"
    {yyval.sql_string=make_sql_string("FALSE",0);}
    break;

  case 2072:
#line 8636 "fgl.yacc"
    {yyval.sql_string=make_sql_string("USER",0);}
    break;

  case 2073:
#line 8637 "fgl.yacc"
    {yyval.sql_string=make_sql_string("COUNT(*)",0);}
    break;

  case 2074:
#line 8643 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,"/",yyvsp[0].sql_string,0);}
    break;

  case 2075:
#line 8644 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-1].sql_string,yyvsp[0].str,0);}
    break;

  case 2076:
#line 8645 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,"*",yyvsp[0].sql_string,0);}
    break;

  case 2077:
#line 8646 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,"+",yyvsp[0].sql_string,0);}
    break;

  case 2078:
#line 8647 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,"-",yyvsp[0].sql_string,0);}
    break;

  case 2079:
#line 8648 "fgl.yacc"
    {yyval.sql_string=make_sql_string("AVERAGE(",yyvsp[-2].str,yyvsp[-1].sql_string,")",0);}
    break;

  case 2080:
#line 8649 "fgl.yacc"
    {yyval.sql_string=make_sql_string("MAX(",yyvsp[-2].str,yyvsp[-1].sql_string,")",0);}
    break;

  case 2081:
#line 8650 "fgl.yacc"
    {yyval.sql_string=make_sql_string("MIN(",yyvsp[-2].str,yyvsp[-1].sql_string,")",0);}
    break;

  case 2082:
#line 8651 "fgl.yacc"
    {yyval.sql_string=make_sql_string("SUM(",yyvsp[-2].str,yyvsp[-1].sql_string,")",0);}
    break;

  case 2083:
#line 8652 "fgl.yacc"
    {yyval.sql_string=make_sql_string("COUNT(",yyvsp[-2].str,yyvsp[-1].sql_string,")",0);}
    break;

  case 2084:
#line 8653 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-3].str,"(",yyvsp[-1].sql_string,")",0);}
    break;

  case 2085:
#line 8654 "fgl.yacc"
    {yyval.sql_string=make_sql_string("DATE(",yyvsp[-1].sql_string,")",0);}
    break;

  case 2086:
#line 8655 "fgl.yacc"
    {yyval.sql_string=make_sql_string("(",yyvsp[-1].sql_string,")",0);}
    break;

  case 2087:
#line 8656 "fgl.yacc"
    {yyval.sql_string=make_sql_string("EXTEND(",yyvsp[-1].sql_string,")",0);}
    break;

  case 2088:
#line 8660 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
}
    break;

  case 2089:
#line 8666 "fgl.yacc"
    {yyval.sql_string=yyvsp[0].sql_string;}
    break;

  case 2090:
#line 8667 "fgl.yacc"
    {
        yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",",yyvsp[0].sql_string,0);
}
    break;

  case 2091:
#line 8675 "fgl.yacc"
    {
	clr_validate_list();
}
    break;

  case 2092:
#line 8677 "fgl.yacc"
    {
	print_validate();
}
    break;

  case 2094:
#line 8683 "fgl.yacc"
    {sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 2095:
#line 8687 "fgl.yacc"
    {
		sprintf(yyval.str,"%s.%s",yyvsp[-2].str,yyvsp[0].str);
		push_validate(yyval.str);
	}
    break;

  case 2096:
#line 8691 "fgl.yacc"
    {
		sprintf(yyval.str,"%s.*",yyvsp[-2].str);
		push_validate(yyval.str);
	}
    break;

  case 2097:
#line 8707 "fgl.yacc"
    {
	if (scan_variable(yyvsp[0].str)!=-1)
	{
		char c;
		char buff[1024];
			sprintf(buff,"%s",fgl_add_scope(yyvsp[0].str,0));

		print_push_variable(buff);

		strcpy(yyval.str,"?");

	} else {
		strcpy(yyval.str,yyvsp[0].str);
	}

}
    break;

  case 2098:
#line 8727 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 2102:
#line 8733 "fgl.yacc"
    {sprintf(yyval.str,"%s.%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 2103:
#line 8734 "fgl.yacc"
    {sprintf(yyval.str,"\\\"%s\\\".%s.%s", A4GL_strip_quotes (yyvsp[-4].str),yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 2107:
#line 8746 "fgl.yacc"
    {
	int sv_val;
	//printf("var_ident_ibind_ss : %s\n",$<str>1);
	sv_val=scan_variable(yyvsp[0].str);

	if (strncmp(yyvsp[0].str," a4gl_sub",9)==0) {
		// Its a substring of a variable
		sv_val=1;
	}

	if (sv_val!=-1&&(!system_var(yyvsp[0].str)))
	{
		// Its a variable
		int z = 0,a = 0;
		//printf("add as bind\n");
		a=get_bind_cnt('i');
		z=add_bind('i',yyvsp[0].str);
		z-=a;
		yyval.sql_string=strdup(A4GL_set_var_sql(doing_declare,z));

	} else { 
		// Its a column
		yyval.sql_string=strdup(get_column_transform(yyvsp[0].str));
	}
}
    break;

  case 2108:
#line 8772 "fgl.yacc"
    {
char r1[256];
//char r2[256];
char buff[256];
char was_str[40000];
//char *ptr1;
//char *ptr2;
//int aa;
int z = 0,a = 0;
struct variable *v_r;
struct variable *v_1;
struct variable *v_2;
struct variable *v_loop;
strcpy(was_str,"");
printf("THRU : %s %s\n",yyvsp[-2].str,yyvsp[0].str);

A4GL_debug("Starting THRU");

sprintf(buff,"%s\n%s",yyvsp[-2].str,yyvsp[0].str);
a=get_bind_cnt('i');
printf("get_bind_cnt=%d\n",a);
z=add_bind('i',buff);
z-=a;
for (a=0;a<z;a++)  {
         if (strlen(was_str)) {strcat(was_str,",");}
         strcat(was_str,"?");
}


	/* split_record(buff,&v_r,&v_1,&v_2);

	v_loop=v_1;

	while (1) {
                //strcpy(kp,was_str);
                sprintf(buff,"%s.%s",r1,v_loop->names.name);

		if (scan_variable(buff)!=-1&&(!system_var(buff))) {
			a=get_bind_cnt('i');
			z=add_bind('i',buff);
			z-=a;
        	}

		for (a=0;a<z;a++)  {
			if (strlen(was_str)) {strcat(was_str,",");}
         		strcat(was_str,"?");
		}
		v_loop=get_next_variable(v_r,v_loop,v_2);
	}
*/
	yyval.sql_string=strdup(was_str);
}
    break;

  case 2109:
#line 8837 "fgl.yacc"
    {set_whenever(WHEN_NOTFOUND|atoi(yyvsp[0].str),0);}
    break;

  case 2110:
#line 8839 "fgl.yacc"
    {set_whenever(WHEN_SQLERROR|atoi(yyvsp[0].str),0);}
    break;

  case 2111:
#line 8841 "fgl.yacc"
    {set_whenever(WHEN_ANYERROR|atoi(yyvsp[0].str),0);}
    break;

  case 2112:
#line 8842 "fgl.yacc"
    {
 		set_whento("");
		set_whenever(WHEN_ERROR+WHEN_CONTINUE,0);
}
    break;

  case 2113:
#line 8847 "fgl.yacc"
    {
A4GL_debug("Whenever error...%d %d",WHEN_ERROR,atoi(yyvsp[0].str));
set_whenever(WHEN_ERROR+atoi(yyvsp[0].str),0);
}
    break;

  case 2114:
#line 8852 "fgl.yacc"
    {set_whenever(WHEN_SQLWARNING|atoi(yyvsp[0].str),0);}
    break;

  case 2115:
#line 8853 "fgl.yacc"
    {
set_whenever(WHEN_WARNING+WHEN_CONTINUE,0);
}
    break;

  case 2116:
#line 8857 "fgl.yacc"
    {set_whenever(WHEN_WARNING|atoi(yyvsp[0].str),0);}
    break;

  case 2117:
#line 8859 "fgl.yacc"
    {set_whenever(WHEN_SUCCESS|atoi(yyvsp[0].str),0);}
    break;

  case 2118:
#line 8861 "fgl.yacc"
    {set_whenever(WHEN_SQLSUCCESS|atoi(yyvsp[0].str),0);}
    break;

  case 2119:
#line 8864 "fgl.yacc"
    {
 set_whento("");
			sprintf(yyval.str,"%d",WHEN_CONTINUE); }
    break;

  case 2120:
#line 8868 "fgl.yacc"
    {
set_whento(yyvsp[0].str);
sprintf(yyval.str,"%d",WHEN_GOTO);
 }
    break;

  case 2121:
#line 8873 "fgl.yacc"
    {
set_whento(yyvsp[0].str); 
sprintf(yyval.str,"%d",WHEN_GOTO);
}
    break;

  case 2122:
#line 8878 "fgl.yacc"
    { set_whento(""); 
sprintf(yyval.str,"%d",WHEN_STOP);
}
    break;

  case 2123:
#line 8882 "fgl.yacc"
    {
set_whento(yyvsp[0].str);
sprintf(yyval.str,"%d",WHEN_CALL);
}
    break;

  case 2125:
#line 8892 "fgl.yacc"
    {sprintf(yyval.str,"%s",yyvsp[0].str);}
    break;

  case 2127:
#line 8907 "fgl.yacc"
    {
print_while_1();
push_blockcommand("WHILE");
}
    break;

  case 2128:
#line 8910 "fgl.yacc"
    {
print_while_2();
}
    break;

  case 2129:
#line 8914 "fgl.yacc"
    {
print_while_3();
pop_blockcommand("WHILE");
}
    break;

  case 2132:
#line 8933 "fgl.yacc"
    { strcpy(yyval.str,"0"); }
    break;

  case 2133:
#line 8934 "fgl.yacc"
    { strcpy(yyval.str,"1"); }
    break;

  case 2134:
#line 8937 "fgl.yacc"
    { print_clr_window("\"screen\""); }
    break;

  case 2135:
#line 8938 "fgl.yacc"
    { print_clr_window(yyvsp[0].str); }
    break;

  case 2136:
#line 8939 "fgl.yacc"
    { print_clr_window(yyvsp[0].str); }
    break;

  case 2137:
#line 8940 "fgl.yacc"
    { print_clr_form(0,0,"0"); }
    break;

  case 2138:
#line 8941 "fgl.yacc"
    { print_clr_form(0,0,"1"); }
    break;

  case 2139:
#line 8942 "fgl.yacc"
    { print_clr_form(yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str); }
    break;

  case 2140:
#line 8943 "fgl.yacc"
    {
	print_clr_fields(yyvsp[-1].str,yyvsp[0].str);
}
    break;

  case 2141:
#line 8948 "fgl.yacc"
    {sprintf(yyval.str,"%s",yyvsp[0].str);}
    break;

  case 2142:
#line 8949 "fgl.yacc"
    {sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 2143:
#line 8953 "fgl.yacc"
    {
	print_current_window("\"screen\"");
}
    break;

  case 2144:
#line 8957 "fgl.yacc"
    {
	print_current_window(yyvsp[0].str);
}
    break;

  case 2145:
#line 8961 "fgl.yacc"
    {
sprintf(yyval.str,"A4GL_cr_window");
reset_attrib(&form_attrib);
}
    break;

  case 2146:
#line 8965 "fgl.yacc"
    {
sprintf(yyval.str,"A4GL_cr_window_form");
reset_attrib(&form_attrib);
}
    break;

  case 2147:
#line 8970 "fgl.yacc"
    {
	print_show_window(yyvsp[0].str);
	addmap("Show Window",yyvsp[0].str,curr_func,yylineno,infilename); 
}
    break;

  case 2148:
#line 8974 "fgl.yacc"
    {
	print_show_menu(yyvsp[-3].str,yyvsp[-1].str);
	addmap("Call Menuhandler",yyvsp[-1].str,curr_func,yylineno,infilename); 
}
    break;

  case 2149:
#line 8979 "fgl.yacc"
    {

print_def_mn_file();

}
    break;

  case 2151:
#line 8987 "fgl.yacc"
    {addmap("Use Menu",yyvsp[0].str,curr_func,yylineno,infilename); }
    break;

  case 2153:
#line 8993 "fgl.yacc"
    {
	print_hide_window(yyvsp[0].str);
}
    break;

  case 2154:
#line 8999 "fgl.yacc"
    {
print_move_window(yyvsp[-4].str,0);
}
    break;

  case 2155:
#line 9003 "fgl.yacc"
    {
print_move_window(yyvsp[-4].str,1);
}
    break;

  case 2160:
#line 9021 "fgl.yacc"
    {
chk4var=0;A4GL_lex_printcomment("/* [Comm:%s] */\n",yyval.str);
if (A4GL_isyes(acl_getenv("INCLINES")))
A4GL_lex_printc("{A4GL_debug(\"Line %d %s:%s\");}",lastlineno,infilename,convstrsql(larr));
	A4GL_prchkerr(lastlineno,infilename);
	lastlineno=yylineno;
}
    break;

  case 2161:
#line 9028 "fgl.yacc"
    {
A4GL_lex_printcomment("/* [COMM:%s] */\n",yyvsp[0].str);chk4var=0;
if (A4GL_isyes(acl_getenv("INCLINES")))
A4GL_lex_printc("{A4GL_debug(\"Line %d %s:%s\");}",lastlineno,infilename,convstrsql(larr));
if (A4GL_aubit_strcasecmp(yyval.str,"whenever")!=0) A4GL_prchkerr(lastlineno,infilename);
lastlineno=yylineno;
}
    break;

  case 2162:
#line 9037 "fgl.yacc"
    {print_cmd_start();}
    break;

  case 2163:
#line 9037 "fgl.yacc"
    {print_cmd_end();}
    break;


    }

/* Line 991 of yacc.c.  */
#line 18165 "y.tab.c"

  yyvsp -= yylen;
  yyssp -= yylen;


  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;


  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if YYERROR_VERBOSE
      yyn = yypact[yystate];

      if (YYPACT_NINF < yyn && yyn < YYLAST)
	{
	  YYSIZE_T yysize = 0;
	  int yytype = YYTRANSLATE (yychar);
	  char *yymsg;
	  int yyx, yycount;

	  yycount = 0;
	  /* Start YYX at -YYN if negative to avoid negative indexes in
	     YYCHECK.  */
	  for (yyx = yyn < 0 ? -yyn : 0;
	       yyx < (int) (sizeof (yytname) / sizeof (char *)); yyx++)
	    if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	      yysize += yystrlen (yytname[yyx]) + 15, yycount++;
	  yysize += yystrlen ("syntax error, unexpected ") + 1;
	  yysize += yystrlen (yytname[yytype]);
	  yymsg = (char *) YYSTACK_ALLOC (yysize);
	  if (yymsg != 0)
	    {
	      char *yyp = yystpcpy (yymsg, "syntax error, unexpected ");
	      yyp = yystpcpy (yyp, yytname[yytype]);

	      if (yycount < 5)
		{
		  yycount = 0;
		  for (yyx = yyn < 0 ? -yyn : 0;
		       yyx < (int) (sizeof (yytname) / sizeof (char *));
		       yyx++)
		    if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
		      {
			const char *yyq = ! yycount ? ", expecting " : " or ";
			yyp = yystpcpy (yyp, yyq);
			yyp = yystpcpy (yyp, yytname[yyx]);
			yycount++;
		      }
		}
	      yyerror (yymsg);
	      YYSTACK_FREE (yymsg);
	    }
	  else
	    yyerror ("syntax error; also virtual memory exhausted");
	}
      else
#endif /* YYERROR_VERBOSE */
	yyerror ("syntax error");
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
	 error, discard it.  */

      /* Return failure if at end of input.  */
      if (yychar == YYEOF)
        {
	  /* Pop the error token.  */
          YYPOPSTACK;
	  /* Pop the rest of the stack.  */
	  while (yyss < yyssp)
	    {
	      YYDSYMPRINTF ("Error: popping", yystos[*yyssp], yyvsp, yylsp);
	      yydestruct (yystos[*yyssp], yyvsp);
	      YYPOPSTACK;
	    }
	  YYABORT;
        }

      YYDSYMPRINTF ("Error: discarding", yytoken, &yylval, &yylloc);
      yydestruct (yytoken, &yylval);
      yychar = YYEMPTY;

    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab2;


/*----------------------------------------------------.
| yyerrlab1 -- error raised explicitly by an action.  |
`----------------------------------------------------*/
yyerrlab1:

  /* Suppress GCC warning that yyerrlab1 is unused when no action
     invokes YYERROR.  */
#if defined (__GNUC_MINOR__) && 2093 <= (__GNUC__ * 1000 + __GNUC_MINOR__)
  __attribute__ ((__unused__))
#endif


  goto yyerrlab2;


/*---------------------------------------------------------------.
| yyerrlab2 -- pop states until the error token can be shifted.  |
`---------------------------------------------------------------*/
yyerrlab2:
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
	{
	  yyn += YYTERROR;
	  if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
	    {
	      yyn = yytable[yyn];
	      if (0 < yyn)
		break;
	    }
	}

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
	YYABORT;

      YYDSYMPRINTF ("Error: popping", yystos[*yyssp], yyvsp, yylsp);
      yydestruct (yystos[yystate], yyvsp);
      yyvsp--;
      yystate = *--yyssp;

      YY_STACK_PRINT (yyss, yyssp);
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  YYDPRINTF ((stderr, "Shifting error token, "));

  *++yyvsp = yylval;


  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#ifndef yyoverflow
/*----------------------------------------------.
| yyoverflowlab -- parser overflow comes here.  |
`----------------------------------------------*/
yyoverflowlab:
  yyerror ("parser stack overflow");
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
  return yyresult;
}


#line 9136 "fgl.yacc"

/* programmer routines */
/*
# include "lex.yy.c"
# include "lexify.c"
*/

void
set_clobber(char *c)
{
	char *ptr;
	//char *ptr2;
	ptr=strrchr(c,'/');
	if (ptr) { strcpy(clobber,ptr+1); return; }

/* Do dos mode ? */
	ptr=strrchr(c,'\\');
	if (ptr) { strcpy(clobber,ptr+1); return; }

	strcpy(clobber,c);
}

char *
get_hdrdbname(void)
{
	return hdr_dbname;
}

void
set_hdrdbname(char *s)
{
	strcpy(hdr_dbname,s);
}

//use this set_str() if YYPURE and YYLEX_PARAM are not set
//void
//set_str(char *s)
//	strcpy(yylval.str,s);
//}

//use this set_str() if YYPURE and YYLEX_PARAM are set
void
set_str(void *p, char *s)
{
	YYSTYPE *y;
	y = (YYSTYPE *) p;
	strcpy( y->str, s );
}


/* ====================== last.reqd =============================== */


/* ===================== EOF (fgl.yacc) =========================== */



