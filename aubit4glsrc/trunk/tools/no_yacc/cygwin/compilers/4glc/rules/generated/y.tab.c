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
     NAME = 1711,
     UMINUS = 1712,
     COMMA = 1617,
     KW_OR = 1657,
     KW_AND = 1612,
     KW_USING = 1549,
     NOT = 1632,
     MATCHES = 1429,
     POWER = 1535,
     LESS_THAN = 1531,
     GREATER_THAN = 1446,
     EQUAL = 1607,
     GREATER_THAN_EQ = 1348,
     LESS_THAN_EQ = 1405,
     NOT_EQUAL = 1477,
     PLUS = 1643,
     MINUS = 1630,
     MULTIPLY = 1536,
     DIVIDE = 1563,
     MOD = 1631,
     COMMAND = 1412,
     NUMBER_VALUE = 1713,
     CHAR_VALUE = 1714,
     INT_VALUE = 1715,
     NAMED_GEN = 1716,
     CLINE = 1717,
     SQLLINE = 1718,
     KW_CSTART = 1719,
     KW_CEND = 1720,
     USER_DTYPE = 1721,
     SQL_TEXT = 1722,
     KW_WHENEVER_SET = 1723,
     COMMENT = 1724,
     DATETIME_VALUE = 1000,
     INTERVAL_VALUE = 1001,
     DYNAMIC_ARRAY = 1002,
     RESIZE_ARRAY = 1003,
     ALLOCATE_ARRAY = 1004,
     DEALLOCATE_ARRAY = 1005,
     AFTER_INSERT_DELETE = 1006,
     BEFORE_INSERT_DELETE = 1007,
     BEFORE_INSERT = 1008,
     AS_CONVERTABLE = 1009,
     CONCAT_PIPES = 1010,
     BEFORE_DELETE = 1011,
     DROP_TRIGGER = 1012,
     AFTER_INSERT = 1013,
     AFTER_DELETE = 1014,
     EXECUTE_IMMEDIATE = 1015,
     DELETE_ROW_EQUAL_TRUE = 1016,
     INSERT_ROW_EQUAL_TRUE = 1017,
     DELETE_ROW_EQUAL_FALSE = 1018,
     INSERT_ROW_EQUAL_FALSE = 1019,
     CURRENT_ROW_DISPLAY_EQUAL = 1020,
     MAXCOUNT = 1021,
     ALTER_TABLE = 1022,
     ALTER_INDEX = 1023,
     NEXT_SIZE = 1024,
     DISPLAY_ATTR_FORM = 1025,
     DISPLAY_ATTR_WINDOW = 1026,
     INPUT_ATTR_FORM = 1027,
     INPUT_ATTR_WINDOW = 1028,
     WHENEVER_ERROR_CONTINUE = 1029,
     WHENEVER_ANY_ERROR_CONTINUE = 1030,
     WHENEVER_WARNING_CONTINUE = 1031,
     WHENEVER_SQLSUCCESS_CONTINUE = 1032,
     WHENEVER_SQLWARNING_CONTINUE = 1033,
     WHENEVER_NOT_FOUND_CONTINUE = 1034,
     WHENEVER_SQLERROR_CONTINUE = 1035,
     WHENEVER_SUCCESS_CONTINUE = 1036,
     WHENEVER_ERROR_GOTO = 1037,
     WHENEVER_ANY_ERROR_GOTO = 1038,
     WHENEVER_WARNING_GOTO = 1039,
     WHENEVER_SQLSUCCESS_GOTO = 1040,
     WHENEVER_SQLWARNING_GOTO = 1041,
     WHENEVER_NOT_FOUND_GOTO = 1042,
     WHENEVER_SQLERROR_GOTO = 1043,
     WHENEVER_SUCCESS_GOTO = 1044,
     WHENEVER_ERROR_CALL = 1045,
     WHENEVER_ANY_ERROR_CALL = 1046,
     WHENEVER_WARNING_CALL = 1047,
     WHENEVER_SQLSUCCESS_CALL = 1048,
     WHENEVER_SQLWARNING_CALL = 1049,
     WHENEVER_NOT_FOUND_CALL = 1050,
     WHENEVER_SQLERROR_CALL = 1051,
     WHENEVER_SUCCESS_CALL = 1052,
     WHENEVER_ERROR_STOP = 1053,
     WHENEVER_ANY_ERROR_STOP = 1054,
     WHENEVER_WARNING_STOP = 1055,
     WHENEVER_SQLSUCCESS_STOP = 1056,
     WHENEVER_SQLWARNING_STOP = 1057,
     WHENEVER_NOT_FOUND_STOP = 1058,
     WHENEVER_SQLERROR_STOP = 1059,
     WHENEVER_SUCCESS_STOP = 1060,
     XSET_MULTIPLY_EQUAL_OPEN_BRACKET = 1061,
     XSET_ident_DOT_MULTIPLY_EQUAL_OPEN_BRACKET = 1062,
     XSET_ident_DOT_MULTIPLY_EQUAL = 1063,
     XSET_MULTIPLY_EQUAL = 1064,
     XSET_OPEN_BRACKET = 1065,
     NEWFORMATSHARED = 1066,
     CREATE_DATABASE = 1067,
     DROP_DATABASE = 1068,
     IMPORT_LEGACY_FUNCTION = 1069,
     ADD_CONSTRAINT = 1070,
     DROP_CONSTRAINT = 1071,
     DROP_SYNONYM = 1072,
     CONSTRAINT = 1073,
     AS_STATIC = 1074,
     NOT_FIELD_TOUCHED = 1075,
     LOCAL_FUNCTION = 1076,
     EVERY_ROW = 1077,
     ELIF = 1078,
     DOUBLE_PRECISION = 1079,
     COUNT_MULTIPLY = 1080,
     WAIT_FOR_KEY = 1081,
     AT_TERMINATION_CALL = 1082,
     TERMINATE_REPORT = 1083,
     TO_MAIN_CAPTION = 1084,
     CLEARSTAT = 1085,
     TO_MENUITEM = 1086,
     ID_TO_INT = 1087,
     TO_STATUSBOX = 1088,
     ASCII_HEIGHT_ALL = 1089,
     ASCII_WIDTH_ALL = 1090,
     IMPORT_DATATYPE = 1091,
     PAGE_TRAILER_SIZE = 1092,
     PAGE_HEADER_SIZE = 1093,
     FIRST_PAGE_HEADER_SIZE = 1094,
     BYTES_USE_AS_IMAGE = 1095,
     BYTES_USE_AS_ASCII = 1096,
     KWUP_BY = 1097,
     KWDOWN_BY = 1098,
     CLOSE_STATUSBOX = 1099,
     MODIFY_NEXT_SIZE = 1100,
     LOCK_MODE_PAGE = 1101,
     LOCK_MODE_ROW = 1102,
     TO_PIPE = 1103,
     TO_PRINTER = 1104,
     STATUSBOX = 1105,
     FORMHANDLER_INPUT = 1106,
     UNITS_YEAR = 1107,
     UNITS_MONTH = 1108,
     UNITS_DAY = 1109,
     UNITS_HOUR = 1110,
     UNITS_MINUTE = 1111,
     UNITS_SECOND = 1112,
     NO_NEW_LINES = 1113,
     FIELDTOWIDGET = 1114,
     WITH_HOLD = 1115,
     SHOW_MENU = 1116,
     TO_CLUSTER = 1117,
     TO_NOT_CLUSTER = 1118,
     CWIS = 1119,
     CREATE_IDX = 1120,
     FORM_IS_COMPILED = 1121,
     PDF_REPORT = 1122,
     IMPORT_FUNCTION = 1123,
     PROMPT_MANY = 1124,
     POINTS = 1125,
     MM = 1126,
     INCHES = 1127,
     PREPEND = 1128,
     MEMBER_OF = 1129,
     MEMBER_FUNCTION = 1130,
     APPEND = 1131,
     TEMPLATE = 1132,
     END_TEMPLATE = 1133,
     SQLSICS = 1134,
     CREATE_SCHEMA = 1135,
     SQLSIRR = 1136,
     UPDATESTATS_T = 1137,
     SQLSICR = 1138,
     WHENEVER_SQLSUCCESS = 1139,
     WHENEVER_SQLWARNING = 1140,
     WHENEVER_ANY_ERROR = 1141,
     WHENEVER_NOT_FOUND = 1142,
     WHENEVER_SQLERROR = 1143,
     WHENEVER_SUCCESS = 1144,
     WHENEVER_ERROR = 1145,
     START_EXTERN = 1146,
     CONTINUE_CONSTRUCT = 1147,
     FOUNCONSTR = 1148,
     SQLSIDR = 1149,
     CREATE_TEMP_TABLE = 1150,
     CURRENT_WINDOW_IS = 1151,
     FIRST_PAGE_HEADER = 1152,
     ORDER_EXTERNAL_BY = 1153,
     SCROLL_CURSOR_FOR = 1154,
     SCROLL_CURSOR = 1155,
     SQL_INTERRUPT_OFF = 1156,
     STOP_ALL_EXTERNAL = 1157,
     WITH_CHECK_OPTION = 1158,
     WITH_GRANT_OPTION = 1159,
     SQLSLMNW = 1160,
     ADDCONSTUNIQ = 1161,
     CONTINUE_DISPLAY = 1162,
     CONTINUE_FOREACH = 1163,
     OUTPUT_TO_REPORT = 1164,
     SQL_INTERRUPT_ON = 1165,
     WHERE_CURRENT_OF = 1166,
     WITHOUT_DEFAULTS = 1167,
     FOCONSTR = 1168,
     SCALED_BY = 1169,
     CONTINUE_PROMPT = 1170,
     PDF_FUNCTION = 1171,
     DEFER_INTERRUPT = 1172,
     DISPLAY_BY_NAME = 1173,
     NOT_NULL_UNIQUE = 1174,
     SKIP_TO_TOP = 1175,
     TOP_OF_PAGE = 1176,
     SKIP_TO = 1177,
     SKIP_BY = 1178,
     WITHOUT_WAITING = 1179,
     BEFCONSTRUCT = 1180,
     SQLSLMW = 1181,
     AFTCONSTRUCT = 1182,
     ALL_PRIVILEGES = 1183,
     CLOSE_DATABASE = 1184,
     CONTINUE_INPUT = 1185,
     CONTINUE_WHILE = 1186,
     CREATE_SYNONYM = 1187,
     DROP_TABLE = 1188,
     EXIT_CONSTRUCT = 1189,
     INEXCLUSIVE = 1190,
     REPORT_TO_PRINTER = 1191,
     REPORT_TO_PIPE = 1192,
     RETURN = 1193,
     SET_SESSION_TO = 1194,
     UPDATESTATS = 1195,
     WITHOUT_HEAD = 1196,
     CLEARSCR = 1197,
     WITH_B_LOG = 1198,
     AUTHORIZATION = 1199,
     BOTTOM_MARGIN = 1200,
     CLOSE_SESSION = 1201,
     CONTINUE_CASE = 1202,
     CONTINUE_MENU = 1203,
     DISPLAY_ARRAY = 1204,
     END_SQL = 1205,
     DOLLAR = 1206,
     END_CONSTRUCT = 1207,
     FIELD_TOUCHED = 1208,
     FINISH_REPORT = 1209,
     INFACC = 1210,
     INPUT_NO_WRAP = 1211,
     SETPMOFF = 1212,
     UNCONSTRAINED = 1213,
     PAGE_TRAILER = 1214,
     SETPMON = 1215,
     BEFGROUP = 1216,
     CLOSE_WINDOW = 1217,
     COMMENT_LINE = 1218,
     CONTINUE_FOR = 1219,
     CREATE_DB = 1220,
     CREATE_TABLE = 1221,
     DEFAULT_NULL = 1222,
     DEFAULT_TODAY = 1223,
     DEFAULT_USER = 1224,
     DELETE_USING = 1225,
     DISPLAY_FORM = 1226,
     END_FUNCTION = 1227,
     EXIT_DISPLAY = 1228,
     EXIT_FOREACH = 1229,
     EXIT_PROGRAM = 1230,
     INFCOLS = 1231,
     ON_EVERY_ROW = 1232,
     OPEN_SESSION = 1233,
     RIGHT_MARGIN = 1234,
     SELECT_USING = 1235,
     START_REPORT = 1236,
     UNLOCK_TABLE = 1237,
     UPDATE_USING = 1238,
     ACL_BUILTIN = 1239,
     AFTGROUP = 1240,
     INFIDX = 1241,
     INFSTAT = 1242,
     LEFT_MARGIN = 1243,
     PAGE_HEADER = 1244,
     ROLLBACK_W = 1245,
     SET_SESSION = 1246,
     SQLSEOFF = 1247,
     WITH_A_LOG = 1248,
     BEFDISP = 1249,
     BEFORE_MENU = 1250,
     CREATE_VIEW = 1251,
     DEFINE_TYPE = 1252,
     DELETE_FROM = 1253,
     END_DISPLAY = 1254,
     END_REPORT = 1255,
     END_FOREACH = 1256,
     END_FOR = 1257,
     END_GLOBALS = 1258,
     EXIT_PROMPT = 1259,
     EXTENT_SIZE = 1260,
     FOREIGN_KEY = 1261,
     HIDE_OPTION = 1262,
     HIDE_WINDOW = 1263,
     INSERT_INTO = 1264,
     IS_NOT_NULL = 1265,
     MOVE_WINDOW = 1266,
     NEXT_OPTION = 1267,
     NOT_MATCHES = 1268,
     ON_LAST_ROW = 1269,
     OPEN_WINDOW = 1270,
     OPEN_STATUSBOX = 1271,
     PAGE_LENGTH = 1272,
     PAGE_WIDTH = 1273,
     PRIMARY_KEY = 1274,
     PROMPT_LINE = 1275,
     RECORD_LIKE = 1276,
     ROLLFORWARD = 1277,
     SETBL = 1278,
     SHOW_OPTION = 1279,
     SHOW_WINDOW = 1280,
     SQLSEON = 1281,
     TO_DATABASE = 1282,
     USE_SESSION = 1283,
     WITH_NO_LOG = 1284,
     AFTDISP = 1285,
     BEFFIELD = 1286,
     INSHARE = 1287,
     UNLOCKTAB = 1288,
     AFTFIELD = 1289,
     ATTRIBUTES = 1290,
     BEFINP = 1291,
     BEGIN_WORK = 1292,
     CLEARWIN = 1293,
     CLOSE_FORM = 1294,
     DEFER_QUIT = 1295,
     DESCENDING = 1296,
     DROP_INDEX = 1297,
     END_PROMPT = 1298,
     END_RECORD = 1299,
     ERROR_LINE = 1300,
     EXIT_INPUT = 1301,
     EXIT_WHILE = 1302,
     FOR_UPDATE_OF = 1303,
     FOR_UPDATE = 1304,
     GET_FLDBUF = 1305,
     INITIALIZE = 1306,
     INPUT_WRAP = 1307,
     LOCK_TABLE = 1308,
     MSG_LINE = 1309,
     NOT_EXISTS = 1310,
     ON_ANY_KEY = 1311,
     REFERENCES = 1312,
     RENCOL = 1313,
     SET_CURSOR = 1314,
     SMALLFLOAT = 1315,
     SQLSUCCESS = 1316,
     TOP_MARGIN = 1317,
     WITH_ARRAY = 1318,
     ACCEPTKEY = 1319,
     ACCEPT = 1320,
     AFTINP = 1321,
     CLEARFORMTODEFAULTS = 1322,
     CLEARFORM = 1323,
     CLEAR_X_FORM = 1324,
     COMMIT_W = 1325,
     NEXTPAGE = 1326,
     PREVPAGE = 1327,
     CTRL_KEY = 1328,
     INFTABS = 1329,
     NEXTFIELD = 1330,
     NEXTFORM = 1331,
     RENTAB = 1332,
     ASCENDING = 1333,
     ASSOCIATE = 1334,
     CHAR = 1335,
     NCHAR = 1336,
     NVARCHAR = 1337,
     CONSTRUCT = 1338,
     DELIMITER = 1339,
     DOWNSHIFT = 1340,
     DROP_VIEW = 1341,
     END_INPUT = 1342,
     END_WHILE = 1343,
     EXCLUSIVE = 1344,
     EXIT_CASE = 1345,
     EXIT_MENU = 1346,
     FORM_LINE = 1347,
     INTERRUPT = 1349,
     INTO_TEMP = 1350,
     INVISIBLE = 1351,
     IN_MEMORY = 1352,
     LINKED_TO = 1353,
     LOAD_FROM = 1354,
     LOCKTAB = 1355,
     MENU_LINE = 1356,
     OPEN_FORM = 1357,
     OTHERWISE = 1358,
     PRECISION = 1359,
     PRIOR = 1360,
     PROCEDURE = 1361,
     REPORT_TO = 1362,
     RETURNING = 1363,
     UNDERLINE = 1364,
     UNLOAD_TO = 1365,
     BEFROW = 1366,
     UNLOAD_T = 1367,
     VARIABLE = 1368,
     ABSOLUTE = 1369,
     AFTROW = 1370,
     BUFFERED = 1371,
     CONSTANT = 1372,
     CONST = 1373,
     DATABASE = 1374,
     DATETIME = 1375,
     DEFAULTS = 1376,
     DISTINCT = 1377,
     END_CASE = 1378,
     END_MAIN = 1379,
     END_MENU = 1380,
     END_TYPE = 1381,
     EXIT_FOR = 1382,
     EXTERNAL = 1383,
     FRACTION = 1384,
     FUNCTION = 1385,
     GROUP_BY = 1386,
     INTERVAL = 1387,
     KWMESSAGE = 1388,
     NOT_LIKE = 1389,
     NOT_ILIKE = 1390,
     NOT_NULL = 1391,
     PASSWORD = 1392,
     PREVIOUS = 1393,
     READONLY = 1394,
     REGISTER = 1395,
     RELATIVE = 1396,
     RESOURCE = 1397,
     SMALLINT = 1398,
     VALIDATE = 1399,
     WITH_LOG = 1400,
     WORDWRAP = 1401,
     BY_NAME = 1402,
     IN_FILE = 1403,
     IS_NULL = 1404,
     AVERAGE = 1406,
     BETWEEN = 1407,
     CAPTION = 1408,
     CLIPPED = 1409,
     CLOSE_BRACKET = 1410,
     COLUMNS = 1411,
     CONNECT = 1413,
     CURRENT = 1414,
     DBYNAME = 1415,
     DECIMAL = 1416,
     DECLARE = 1417,
     DEFAULT = 1418,
     DISPLAY = 1419,
     ENDCODE = 1420,
     EXECUTE = 1421,
     FOREACH = 1422,
     FOREIGN = 1423,
     GLOBALS = 1424,
     INFIELD = 1425,
     INTEGER = 1426,
     KWWINDOW = 1427,
     MAGENTA = 1428,
     OPTIONS = 1430,
     PERCENT = 1431,
     PREPARE = 1432,
     PROGRAM = 1433,
     RECOVER = 1434,
     REVERSE = 1435,
     SECTION = 1436,
     SESSION = 1437,
     SYNONYM = 1438,
     THRU = 1439,
     TRAILER = 1440,
     UPSHIFT = 1441,
     VARCHAR = 1442,
     WAITING = 1443,
     CLOSE_SHEV = 1444,
     CLOSE_SQUARE = 1445,
     KW_FALSE = 1447,
     NOT_IN = 1448,
     ONKEY = 1449,
     OPEN_BRACKET = 1450,
     BORDER = 1451,
     BOTTOM = 1452,
     COLUMN = 1453,
     COMMIT = 1454,
     CREATE = 1455,
     CURSOR = 1456,
     DEFINE = 1457,
     DELETE = 1458,
     DOUBLE = 1459,
     END_IF = 1460,
     ESCAPE = 1461,
     EXISTS = 1462,
     EXTEND = 1463,
     EXTENT = 1464,
     FINISH = 1465,
     FORMAT = 1466,
     HAVING = 1467,
     HEADER = 1468,
     INSERT = 1469,
     LOCATE = 1470,
     MARGIN = 1471,
     MEMORY = 1472,
     MINUTE = 1473,
     MODIFY = 1474,
     NORMAL = 1475,
     EQUAL_EQUAL = 1476,
     OPEN_SHEV = 1478,
     OPEN_SQUARE = 1479,
     OPTION = 1480,
     OUTPUT = 1481,
     PROMPT = 1482,
     PUBLIC = 1483,
     RECORD = 1484,
     REPORT = 1485,
     REVOKE = 1486,
     SCHEMA = 1487,
     SCROLL_USING = 1488,
     SCROLL = 1489,
     SECOND = 1490,
     SELECT = 1491,
     SERIAL = 1492,
     SETL = 1493,
     SHARED = 1494,
     SPACES = 1495,
     UNIQUE = 1496,
     UNLOCK = 1497,
     UPDATE = 1498,
     VALUES = 1499,
     YELLOW = 1500,
     AFTER = 1501,
     KWLINE = 1502,
     KW_NULL = 1503,
     KW_TRUE = 1504,
     SINGLE_KEY = 1505,
     ALTER = 1506,
     ARRAY = 1507,
     ASCII = 1508,
     AUDIT = 1509,
     BLACK = 1510,
     BLINK = 1511,
     CHECK = 1512,
     CLEAR = 1513,
     CLOSE = 1514,
     CODE_C = 1515,
     COUNT = 1516,
     DEFER = 1517,
     ERROR = 1518,
     EVERY = 1519,
     FETCH = 1520,
     FIRST = 1521,
     FLOAT = 1522,
     FLUSH = 1523,
     FOUND = 1524,
     GRANT = 1525,
     GREEN = 1526,
     GROUP = 1527,
     INDEX = 1528,
     KWFORM = 1529,
     LABEL = 1530,
     LOCAL = 1532,
     MONEY = 1533,
     MONTH = 1534,
     ORDER = 1537,
     OUTER = 1538,
     PAUSE = 1539,
     PRINT_IMAGE = 1540,
     PRINT_FILE = 1541,
     PRINT = 1542,
     RIGHT = 1543,
     DOUBLE_COLON = 1544,
     SEMICOLON = 1545,
     SLEEP = 1546,
     TUPLE = 1547,
     UNION = 1548,
     WHERE = 1550,
     WHILE = 1551,
     WHITE = 1552,
     CCODE = 1553,
     ANSI = 1554,
     BLUE = 1555,
     BOLD = 1556,
     BYTE = 1557,
     FCALL = 1558,
     CASE = 1559,
     CYAN = 1560,
     DATE = 1561,
     DESC = 1562,
     KWDOWN = 1564,
     TAB = 1565,
     DROP = 1566,
     ELSE = 1567,
     EXEC = 1568,
     EXIT = 1569,
     FREE = 1570,
     FROM = 1571,
     GOTO = 1572,
     HELP_FILE = 1573,
     LANG_FILE = 1574,
     HELP = 1575,
     HIDE = 1576,
     HOUR = 1577,
     INTO = 1578,
     LAST = 1579,
     LEFT = 1580,
     LIKE = 1581,
     MAIN = 1582,
     MENU = 1583,
     MODE = 1584,
     NEED = 1585,
     NEXT = 1586,
     NOCR = 1587,
     OPEN = 1588,
     QUIT = 1589,
     REAL = 1590,
     ROWS = 1591,
     SHOW = 1592,
     SIZE = 1593,
     SKIP = 1594,
     SOME = 1595,
     STEP = 1596,
     STOP = 1597,
     TEMP = 1598,
     TEXT = 1599,
     THEN = 1600,
     USER = 1601,
     WAIT = 1602,
     WHEN = 1603,
     WITH = 1604,
     WORK = 1605,
     YEAR = 1606,
     KW_IS = 1608,
     XSET = 1609,
     ADD = 1610,
     ALL = 1611,
     ANY = 1613,
     ASC = 1614,
     AVG = 1615,
     COLON = 1616,
     DAY = 1618,
     DBA = 1619,
     DEC = 1620,
     DIM = 1621,
     FKEY = 1622,
     FOR = 1623,
     KEY = 1624,
     KWNO = 1625,
     LET = 1626,
     LOG = 1627,
     XMAX = 1628,
     XMIN = 1629,
     PAD = 1633,
     PUT = 1634,
     RED = 1635,
     ROW = 1636,
     RUN = 1637,
     SQL = 1638,
     SUM = 1639,
     TOP = 1640,
     USE = 1641,
     ATSIGN = 1642,
     AS_TIFF = 1644,
     AS_GIF = 1645,
     AS_PNG = 1646,
     AS_JPEG = 1647,
     AS = 1648,
     AT = 1649,
     BY = 1650,
     DOT = 1651,
     GO = 1652,
     IF = 1653,
     IN = 1654,
     OF = 1655,
     ON = 1656,
     TO = 1658,
     KWUP = 1659,
     FONT_NAME = 1660,
     FONT_SIZE = 1661,
     PAPER_SIZE_IS_LETTER = 1662,
     PAPER_SIZE_IS_LEGAL = 1663,
     PAPER_SIZE_IS_A5 = 1664,
     PAPER_SIZE_IS_A4 = 1665,
     PAPER_SIZE_IS_LETTER_L = 1666,
     PAPER_SIZE_IS_LEGAL_L = 1667,
     PAPER_SIZE_IS_A5_L = 1668,
     PAPER_SIZE_IS_A4_L = 1669,
     FORMHANDLER = 1670,
     END_FORMHANDLER = 1671,
     BEFORE_EVENT = 1672,
     BEFORE_OPEN_FORM = 1673,
     AFTER_EVENT = 1674,
     BEFORE_CLOSE_FORM = 1675,
     BEFORE_ANY = 1676,
     AFTER_ANY = 1677,
     MENUHANDLER = 1678,
     END_MENUHANDLER = 1679,
     BEFORE_SHOW_MENU = 1680,
     DISABLE_PROGRAM = 1681,
     DISABLE_ALL = 1682,
     BUTTONS = 1683,
     CHECK_MENUITEM = 1684,
     DISABLE_FORM = 1685,
     DISABLE_MENUITEMS = 1686,
     DISABLE = 1687,
     ENABLE_FORM = 1688,
     ENABLE_MENUITEMS = 1689,
     ENABLE = 1690,
     KWFIELD = 1691,
     ICON = 1692,
     MESSAGEBOX = 1693,
     TO_DEFAULTS = 1694,
     UNCHECK_MENUITEM = 1695,
     BEFORE = 1696,
     INPUT = 1697,
     END = 1698,
     INT_TO_ID = 1699,
     TIMEOUT = 1700,
     OFF = 1701,
     WITH_1_DIMENSION = 1702,
     WITH_2_DIMENSION = 1703,
     WITH_3_DIMENSION = 1704,
     TILDE = 1705,
     ILIKE = 1706,
     FGL_ISDYNARR_ALLOCATED = 1707,
     FGL_DYNARR_EXTENTSIZE = 1708,
     FILLFACTOR = 1709
   };
#endif
#define NAME 1711
#define UMINUS 1712
#define COMMA 1617
#define KW_OR 1657
#define KW_AND 1612
#define KW_USING 1549
#define NOT 1632
#define MATCHES 1429
#define POWER 1535
#define LESS_THAN 1531
#define GREATER_THAN 1446
#define EQUAL 1607
#define GREATER_THAN_EQ 1348
#define LESS_THAN_EQ 1405
#define NOT_EQUAL 1477
#define PLUS 1643
#define MINUS 1630
#define MULTIPLY 1536
#define DIVIDE 1563
#define MOD 1631
#define COMMAND 1412
#define NUMBER_VALUE 1713
#define CHAR_VALUE 1714
#define INT_VALUE 1715
#define NAMED_GEN 1716
#define CLINE 1717
#define SQLLINE 1718
#define KW_CSTART 1719
#define KW_CEND 1720
#define USER_DTYPE 1721
#define SQL_TEXT 1722
#define KW_WHENEVER_SET 1723
#define COMMENT 1724
#define DATETIME_VALUE 1000
#define INTERVAL_VALUE 1001
#define DYNAMIC_ARRAY 1002
#define RESIZE_ARRAY 1003
#define ALLOCATE_ARRAY 1004
#define DEALLOCATE_ARRAY 1005
#define AFTER_INSERT_DELETE 1006
#define BEFORE_INSERT_DELETE 1007
#define BEFORE_INSERT 1008
#define AS_CONVERTABLE 1009
#define CONCAT_PIPES 1010
#define BEFORE_DELETE 1011
#define DROP_TRIGGER 1012
#define AFTER_INSERT 1013
#define AFTER_DELETE 1014
#define EXECUTE_IMMEDIATE 1015
#define DELETE_ROW_EQUAL_TRUE 1016
#define INSERT_ROW_EQUAL_TRUE 1017
#define DELETE_ROW_EQUAL_FALSE 1018
#define INSERT_ROW_EQUAL_FALSE 1019
#define CURRENT_ROW_DISPLAY_EQUAL 1020
#define MAXCOUNT 1021
#define ALTER_TABLE 1022
#define ALTER_INDEX 1023
#define NEXT_SIZE 1024
#define DISPLAY_ATTR_FORM 1025
#define DISPLAY_ATTR_WINDOW 1026
#define INPUT_ATTR_FORM 1027
#define INPUT_ATTR_WINDOW 1028
#define WHENEVER_ERROR_CONTINUE 1029
#define WHENEVER_ANY_ERROR_CONTINUE 1030
#define WHENEVER_WARNING_CONTINUE 1031
#define WHENEVER_SQLSUCCESS_CONTINUE 1032
#define WHENEVER_SQLWARNING_CONTINUE 1033
#define WHENEVER_NOT_FOUND_CONTINUE 1034
#define WHENEVER_SQLERROR_CONTINUE 1035
#define WHENEVER_SUCCESS_CONTINUE 1036
#define WHENEVER_ERROR_GOTO 1037
#define WHENEVER_ANY_ERROR_GOTO 1038
#define WHENEVER_WARNING_GOTO 1039
#define WHENEVER_SQLSUCCESS_GOTO 1040
#define WHENEVER_SQLWARNING_GOTO 1041
#define WHENEVER_NOT_FOUND_GOTO 1042
#define WHENEVER_SQLERROR_GOTO 1043
#define WHENEVER_SUCCESS_GOTO 1044
#define WHENEVER_ERROR_CALL 1045
#define WHENEVER_ANY_ERROR_CALL 1046
#define WHENEVER_WARNING_CALL 1047
#define WHENEVER_SQLSUCCESS_CALL 1048
#define WHENEVER_SQLWARNING_CALL 1049
#define WHENEVER_NOT_FOUND_CALL 1050
#define WHENEVER_SQLERROR_CALL 1051
#define WHENEVER_SUCCESS_CALL 1052
#define WHENEVER_ERROR_STOP 1053
#define WHENEVER_ANY_ERROR_STOP 1054
#define WHENEVER_WARNING_STOP 1055
#define WHENEVER_SQLSUCCESS_STOP 1056
#define WHENEVER_SQLWARNING_STOP 1057
#define WHENEVER_NOT_FOUND_STOP 1058
#define WHENEVER_SQLERROR_STOP 1059
#define WHENEVER_SUCCESS_STOP 1060
#define XSET_MULTIPLY_EQUAL_OPEN_BRACKET 1061
#define XSET_ident_DOT_MULTIPLY_EQUAL_OPEN_BRACKET 1062
#define XSET_ident_DOT_MULTIPLY_EQUAL 1063
#define XSET_MULTIPLY_EQUAL 1064
#define XSET_OPEN_BRACKET 1065
#define NEWFORMATSHARED 1066
#define CREATE_DATABASE 1067
#define DROP_DATABASE 1068
#define IMPORT_LEGACY_FUNCTION 1069
#define ADD_CONSTRAINT 1070
#define DROP_CONSTRAINT 1071
#define DROP_SYNONYM 1072
#define CONSTRAINT 1073
#define AS_STATIC 1074
#define NOT_FIELD_TOUCHED 1075
#define LOCAL_FUNCTION 1076
#define EVERY_ROW 1077
#define ELIF 1078
#define DOUBLE_PRECISION 1079
#define COUNT_MULTIPLY 1080
#define WAIT_FOR_KEY 1081
#define AT_TERMINATION_CALL 1082
#define TERMINATE_REPORT 1083
#define TO_MAIN_CAPTION 1084
#define CLEARSTAT 1085
#define TO_MENUITEM 1086
#define ID_TO_INT 1087
#define TO_STATUSBOX 1088
#define ASCII_HEIGHT_ALL 1089
#define ASCII_WIDTH_ALL 1090
#define IMPORT_DATATYPE 1091
#define PAGE_TRAILER_SIZE 1092
#define PAGE_HEADER_SIZE 1093
#define FIRST_PAGE_HEADER_SIZE 1094
#define BYTES_USE_AS_IMAGE 1095
#define BYTES_USE_AS_ASCII 1096
#define KWUP_BY 1097
#define KWDOWN_BY 1098
#define CLOSE_STATUSBOX 1099
#define MODIFY_NEXT_SIZE 1100
#define LOCK_MODE_PAGE 1101
#define LOCK_MODE_ROW 1102
#define TO_PIPE 1103
#define TO_PRINTER 1104
#define STATUSBOX 1105
#define FORMHANDLER_INPUT 1106
#define UNITS_YEAR 1107
#define UNITS_MONTH 1108
#define UNITS_DAY 1109
#define UNITS_HOUR 1110
#define UNITS_MINUTE 1111
#define UNITS_SECOND 1112
#define NO_NEW_LINES 1113
#define FIELDTOWIDGET 1114
#define WITH_HOLD 1115
#define SHOW_MENU 1116
#define TO_CLUSTER 1117
#define TO_NOT_CLUSTER 1118
#define CWIS 1119
#define CREATE_IDX 1120
#define FORM_IS_COMPILED 1121
#define PDF_REPORT 1122
#define IMPORT_FUNCTION 1123
#define PROMPT_MANY 1124
#define POINTS 1125
#define MM 1126
#define INCHES 1127
#define PREPEND 1128
#define MEMBER_OF 1129
#define MEMBER_FUNCTION 1130
#define APPEND 1131
#define TEMPLATE 1132
#define END_TEMPLATE 1133
#define SQLSICS 1134
#define CREATE_SCHEMA 1135
#define SQLSIRR 1136
#define UPDATESTATS_T 1137
#define SQLSICR 1138
#define WHENEVER_SQLSUCCESS 1139
#define WHENEVER_SQLWARNING 1140
#define WHENEVER_ANY_ERROR 1141
#define WHENEVER_NOT_FOUND 1142
#define WHENEVER_SQLERROR 1143
#define WHENEVER_SUCCESS 1144
#define WHENEVER_ERROR 1145
#define START_EXTERN 1146
#define CONTINUE_CONSTRUCT 1147
#define FOUNCONSTR 1148
#define SQLSIDR 1149
#define CREATE_TEMP_TABLE 1150
#define CURRENT_WINDOW_IS 1151
#define FIRST_PAGE_HEADER 1152
#define ORDER_EXTERNAL_BY 1153
#define SCROLL_CURSOR_FOR 1154
#define SCROLL_CURSOR 1155
#define SQL_INTERRUPT_OFF 1156
#define STOP_ALL_EXTERNAL 1157
#define WITH_CHECK_OPTION 1158
#define WITH_GRANT_OPTION 1159
#define SQLSLMNW 1160
#define ADDCONSTUNIQ 1161
#define CONTINUE_DISPLAY 1162
#define CONTINUE_FOREACH 1163
#define OUTPUT_TO_REPORT 1164
#define SQL_INTERRUPT_ON 1165
#define WHERE_CURRENT_OF 1166
#define WITHOUT_DEFAULTS 1167
#define FOCONSTR 1168
#define SCALED_BY 1169
#define CONTINUE_PROMPT 1170
#define PDF_FUNCTION 1171
#define DEFER_INTERRUPT 1172
#define DISPLAY_BY_NAME 1173
#define NOT_NULL_UNIQUE 1174
#define SKIP_TO_TOP 1175
#define TOP_OF_PAGE 1176
#define SKIP_TO 1177
#define SKIP_BY 1178
#define WITHOUT_WAITING 1179
#define BEFCONSTRUCT 1180
#define SQLSLMW 1181
#define AFTCONSTRUCT 1182
#define ALL_PRIVILEGES 1183
#define CLOSE_DATABASE 1184
#define CONTINUE_INPUT 1185
#define CONTINUE_WHILE 1186
#define CREATE_SYNONYM 1187
#define DROP_TABLE 1188
#define EXIT_CONSTRUCT 1189
#define INEXCLUSIVE 1190
#define REPORT_TO_PRINTER 1191
#define REPORT_TO_PIPE 1192
#define RETURN 1193
#define SET_SESSION_TO 1194
#define UPDATESTATS 1195
#define WITHOUT_HEAD 1196
#define CLEARSCR 1197
#define WITH_B_LOG 1198
#define AUTHORIZATION 1199
#define BOTTOM_MARGIN 1200
#define CLOSE_SESSION 1201
#define CONTINUE_CASE 1202
#define CONTINUE_MENU 1203
#define DISPLAY_ARRAY 1204
#define END_SQL 1205
#define DOLLAR 1206
#define END_CONSTRUCT 1207
#define FIELD_TOUCHED 1208
#define FINISH_REPORT 1209
#define INFACC 1210
#define INPUT_NO_WRAP 1211
#define SETPMOFF 1212
#define UNCONSTRAINED 1213
#define PAGE_TRAILER 1214
#define SETPMON 1215
#define BEFGROUP 1216
#define CLOSE_WINDOW 1217
#define COMMENT_LINE 1218
#define CONTINUE_FOR 1219
#define CREATE_DB 1220
#define CREATE_TABLE 1221
#define DEFAULT_NULL 1222
#define DEFAULT_TODAY 1223
#define DEFAULT_USER 1224
#define DELETE_USING 1225
#define DISPLAY_FORM 1226
#define END_FUNCTION 1227
#define EXIT_DISPLAY 1228
#define EXIT_FOREACH 1229
#define EXIT_PROGRAM 1230
#define INFCOLS 1231
#define ON_EVERY_ROW 1232
#define OPEN_SESSION 1233
#define RIGHT_MARGIN 1234
#define SELECT_USING 1235
#define START_REPORT 1236
#define UNLOCK_TABLE 1237
#define UPDATE_USING 1238
#define ACL_BUILTIN 1239
#define AFTGROUP 1240
#define INFIDX 1241
#define INFSTAT 1242
#define LEFT_MARGIN 1243
#define PAGE_HEADER 1244
#define ROLLBACK_W 1245
#define SET_SESSION 1246
#define SQLSEOFF 1247
#define WITH_A_LOG 1248
#define BEFDISP 1249
#define BEFORE_MENU 1250
#define CREATE_VIEW 1251
#define DEFINE_TYPE 1252
#define DELETE_FROM 1253
#define END_DISPLAY 1254
#define END_REPORT 1255
#define END_FOREACH 1256
#define END_FOR 1257
#define END_GLOBALS 1258
#define EXIT_PROMPT 1259
#define EXTENT_SIZE 1260
#define FOREIGN_KEY 1261
#define HIDE_OPTION 1262
#define HIDE_WINDOW 1263
#define INSERT_INTO 1264
#define IS_NOT_NULL 1265
#define MOVE_WINDOW 1266
#define NEXT_OPTION 1267
#define NOT_MATCHES 1268
#define ON_LAST_ROW 1269
#define OPEN_WINDOW 1270
#define OPEN_STATUSBOX 1271
#define PAGE_LENGTH 1272
#define PAGE_WIDTH 1273
#define PRIMARY_KEY 1274
#define PROMPT_LINE 1275
#define RECORD_LIKE 1276
#define ROLLFORWARD 1277
#define SETBL 1278
#define SHOW_OPTION 1279
#define SHOW_WINDOW 1280
#define SQLSEON 1281
#define TO_DATABASE 1282
#define USE_SESSION 1283
#define WITH_NO_LOG 1284
#define AFTDISP 1285
#define BEFFIELD 1286
#define INSHARE 1287
#define UNLOCKTAB 1288
#define AFTFIELD 1289
#define ATTRIBUTES 1290
#define BEFINP 1291
#define BEGIN_WORK 1292
#define CLEARWIN 1293
#define CLOSE_FORM 1294
#define DEFER_QUIT 1295
#define DESCENDING 1296
#define DROP_INDEX 1297
#define END_PROMPT 1298
#define END_RECORD 1299
#define ERROR_LINE 1300
#define EXIT_INPUT 1301
#define EXIT_WHILE 1302
#define FOR_UPDATE_OF 1303
#define FOR_UPDATE 1304
#define GET_FLDBUF 1305
#define INITIALIZE 1306
#define INPUT_WRAP 1307
#define LOCK_TABLE 1308
#define MSG_LINE 1309
#define NOT_EXISTS 1310
#define ON_ANY_KEY 1311
#define REFERENCES 1312
#define RENCOL 1313
#define SET_CURSOR 1314
#define SMALLFLOAT 1315
#define SQLSUCCESS 1316
#define TOP_MARGIN 1317
#define WITH_ARRAY 1318
#define ACCEPTKEY 1319
#define ACCEPT 1320
#define AFTINP 1321
#define CLEARFORMTODEFAULTS 1322
#define CLEARFORM 1323
#define CLEAR_X_FORM 1324
#define COMMIT_W 1325
#define NEXTPAGE 1326
#define PREVPAGE 1327
#define CTRL_KEY 1328
#define INFTABS 1329
#define NEXTFIELD 1330
#define NEXTFORM 1331
#define RENTAB 1332
#define ASCENDING 1333
#define ASSOCIATE 1334
#define CHAR 1335
#define NCHAR 1336
#define NVARCHAR 1337
#define CONSTRUCT 1338
#define DELIMITER 1339
#define DOWNSHIFT 1340
#define DROP_VIEW 1341
#define END_INPUT 1342
#define END_WHILE 1343
#define EXCLUSIVE 1344
#define EXIT_CASE 1345
#define EXIT_MENU 1346
#define FORM_LINE 1347
#define INTERRUPT 1349
#define INTO_TEMP 1350
#define INVISIBLE 1351
#define IN_MEMORY 1352
#define LINKED_TO 1353
#define LOAD_FROM 1354
#define LOCKTAB 1355
#define MENU_LINE 1356
#define OPEN_FORM 1357
#define OTHERWISE 1358
#define PRECISION 1359
#define PRIOR 1360
#define PROCEDURE 1361
#define REPORT_TO 1362
#define RETURNING 1363
#define UNDERLINE 1364
#define UNLOAD_TO 1365
#define BEFROW 1366
#define UNLOAD_T 1367
#define VARIABLE 1368
#define ABSOLUTE 1369
#define AFTROW 1370
#define BUFFERED 1371
#define CONSTANT 1372
#define CONST 1373
#define DATABASE 1374
#define DATETIME 1375
#define DEFAULTS 1376
#define DISTINCT 1377
#define END_CASE 1378
#define END_MAIN 1379
#define END_MENU 1380
#define END_TYPE 1381
#define EXIT_FOR 1382
#define EXTERNAL 1383
#define FRACTION 1384
#define FUNCTION 1385
#define GROUP_BY 1386
#define INTERVAL 1387
#define KWMESSAGE 1388
#define NOT_LIKE 1389
#define NOT_ILIKE 1390
#define NOT_NULL 1391
#define PASSWORD 1392
#define PREVIOUS 1393
#define READONLY 1394
#define REGISTER 1395
#define RELATIVE 1396
#define RESOURCE 1397
#define SMALLINT 1398
#define VALIDATE 1399
#define WITH_LOG 1400
#define WORDWRAP 1401
#define BY_NAME 1402
#define IN_FILE 1403
#define IS_NULL 1404
#define AVERAGE 1406
#define BETWEEN 1407
#define CAPTION 1408
#define CLIPPED 1409
#define CLOSE_BRACKET 1410
#define COLUMNS 1411
#define CONNECT 1413
#define CURRENT 1414
#define DBYNAME 1415
#define DECIMAL 1416
#define DECLARE 1417
#define DEFAULT 1418
#define DISPLAY 1419
#define ENDCODE 1420
#define EXECUTE 1421
#define FOREACH 1422
#define FOREIGN 1423
#define GLOBALS 1424
#define INFIELD 1425
#define INTEGER 1426
#define KWWINDOW 1427
#define MAGENTA 1428
#define OPTIONS 1430
#define PERCENT 1431
#define PREPARE 1432
#define PROGRAM 1433
#define RECOVER 1434
#define REVERSE 1435
#define SECTION 1436
#define SESSION 1437
#define SYNONYM 1438
#define THRU 1439
#define TRAILER 1440
#define UPSHIFT 1441
#define VARCHAR 1442
#define WAITING 1443
#define CLOSE_SHEV 1444
#define CLOSE_SQUARE 1445
#define KW_FALSE 1447
#define NOT_IN 1448
#define ONKEY 1449
#define OPEN_BRACKET 1450
#define BORDER 1451
#define BOTTOM 1452
#define COLUMN 1453
#define COMMIT 1454
#define CREATE 1455
#define CURSOR 1456
#define DEFINE 1457
#define DELETE 1458
#define DOUBLE 1459
#define END_IF 1460
#define ESCAPE 1461
#define EXISTS 1462
#define EXTEND 1463
#define EXTENT 1464
#define FINISH 1465
#define FORMAT 1466
#define HAVING 1467
#define HEADER 1468
#define INSERT 1469
#define LOCATE 1470
#define MARGIN 1471
#define MEMORY 1472
#define MINUTE 1473
#define MODIFY 1474
#define NORMAL 1475
#define EQUAL_EQUAL 1476
#define OPEN_SHEV 1478
#define OPEN_SQUARE 1479
#define OPTION 1480
#define OUTPUT 1481
#define PROMPT 1482
#define PUBLIC 1483
#define RECORD 1484
#define REPORT 1485
#define REVOKE 1486
#define SCHEMA 1487
#define SCROLL_USING 1488
#define SCROLL 1489
#define SECOND 1490
#define SELECT 1491
#define SERIAL 1492
#define SETL 1493
#define SHARED 1494
#define SPACES 1495
#define UNIQUE 1496
#define UNLOCK 1497
#define UPDATE 1498
#define VALUES 1499
#define YELLOW 1500
#define AFTER 1501
#define KWLINE 1502
#define KW_NULL 1503
#define KW_TRUE 1504
#define SINGLE_KEY 1505
#define ALTER 1506
#define ARRAY 1507
#define ASCII 1508
#define AUDIT 1509
#define BLACK 1510
#define BLINK 1511
#define CHECK 1512
#define CLEAR 1513
#define CLOSE 1514
#define CODE_C 1515
#define COUNT 1516
#define DEFER 1517
#define ERROR 1518
#define EVERY 1519
#define FETCH 1520
#define FIRST 1521
#define FLOAT 1522
#define FLUSH 1523
#define FOUND 1524
#define GRANT 1525
#define GREEN 1526
#define GROUP 1527
#define INDEX 1528
#define KWFORM 1529
#define LABEL 1530
#define LOCAL 1532
#define MONEY 1533
#define MONTH 1534
#define ORDER 1537
#define OUTER 1538
#define PAUSE 1539
#define PRINT_IMAGE 1540
#define PRINT_FILE 1541
#define PRINT 1542
#define RIGHT 1543
#define DOUBLE_COLON 1544
#define SEMICOLON 1545
#define SLEEP 1546
#define TUPLE 1547
#define UNION 1548
#define WHERE 1550
#define WHILE 1551
#define WHITE 1552
#define CCODE 1553
#define ANSI 1554
#define BLUE 1555
#define BOLD 1556
#define BYTE 1557
#define FCALL 1558
#define CASE 1559
#define CYAN 1560
#define DATE 1561
#define DESC 1562
#define KWDOWN 1564
#define TAB 1565
#define DROP 1566
#define ELSE 1567
#define EXEC 1568
#define EXIT 1569
#define FREE 1570
#define FROM 1571
#define GOTO 1572
#define HELP_FILE 1573
#define LANG_FILE 1574
#define HELP 1575
#define HIDE 1576
#define HOUR 1577
#define INTO 1578
#define LAST 1579
#define LEFT 1580
#define LIKE 1581
#define MAIN 1582
#define MENU 1583
#define MODE 1584
#define NEED 1585
#define NEXT 1586
#define NOCR 1587
#define OPEN 1588
#define QUIT 1589
#define REAL 1590
#define ROWS 1591
#define SHOW 1592
#define SIZE 1593
#define SKIP 1594
#define SOME 1595
#define STEP 1596
#define STOP 1597
#define TEMP 1598
#define TEXT 1599
#define THEN 1600
#define USER 1601
#define WAIT 1602
#define WHEN 1603
#define WITH 1604
#define WORK 1605
#define YEAR 1606
#define KW_IS 1608
#define XSET 1609
#define ADD 1610
#define ALL 1611
#define ANY 1613
#define ASC 1614
#define AVG 1615
#define COLON 1616
#define DAY 1618
#define DBA 1619
#define DEC 1620
#define DIM 1621
#define FKEY 1622
#define FOR 1623
#define KEY 1624
#define KWNO 1625
#define LET 1626
#define LOG 1627
#define XMAX 1628
#define XMIN 1629
#define PAD 1633
#define PUT 1634
#define RED 1635
#define ROW 1636
#define RUN 1637
#define SQL 1638
#define SUM 1639
#define TOP 1640
#define USE 1641
#define ATSIGN 1642
#define AS_TIFF 1644
#define AS_GIF 1645
#define AS_PNG 1646
#define AS_JPEG 1647
#define AS 1648
#define AT 1649
#define BY 1650
#define DOT 1651
#define GO 1652
#define IF 1653
#define IN 1654
#define OF 1655
#define ON 1656
#define TO 1658
#define KWUP 1659
#define FONT_NAME 1660
#define FONT_SIZE 1661
#define PAPER_SIZE_IS_LETTER 1662
#define PAPER_SIZE_IS_LEGAL 1663
#define PAPER_SIZE_IS_A5 1664
#define PAPER_SIZE_IS_A4 1665
#define PAPER_SIZE_IS_LETTER_L 1666
#define PAPER_SIZE_IS_LEGAL_L 1667
#define PAPER_SIZE_IS_A5_L 1668
#define PAPER_SIZE_IS_A4_L 1669
#define FORMHANDLER 1670
#define END_FORMHANDLER 1671
#define BEFORE_EVENT 1672
#define BEFORE_OPEN_FORM 1673
#define AFTER_EVENT 1674
#define BEFORE_CLOSE_FORM 1675
#define BEFORE_ANY 1676
#define AFTER_ANY 1677
#define MENUHANDLER 1678
#define END_MENUHANDLER 1679
#define BEFORE_SHOW_MENU 1680
#define DISABLE_PROGRAM 1681
#define DISABLE_ALL 1682
#define BUTTONS 1683
#define CHECK_MENUITEM 1684
#define DISABLE_FORM 1685
#define DISABLE_MENUITEMS 1686
#define DISABLE 1687
#define ENABLE_FORM 1688
#define ENABLE_MENUITEMS 1689
#define ENABLE 1690
#define KWFIELD 1691
#define ICON 1692
#define MESSAGEBOX 1693
#define TO_DEFAULTS 1694
#define UNCHECK_MENUITEM 1695
#define BEFORE 1696
#define INPUT 1697
#define END 1698
#define INT_TO_ID 1699
#define TIMEOUT 1700
#define OFF 1701
#define WITH_1_DIMENSION 1702
#define WITH_2_DIMENSION 1703
#define WITH_3_DIMENSION 1704
#define TILDE 1705
#define ILIKE 1706
#define FGL_ISDYNARR_ALLOCATED 1707
#define FGL_DYNARR_EXTENTSIZE 1708
#define FILLFACTOR 1709




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
#include "var_handling.h"

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
int 		doing_a_print=0;

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
#include "../field_handling.h"



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
#line 214 "fgl.yacc"
typedef union YYSTYPE {



	//char	str[3100];  /* This would core dump in CygWin on call to */
	char	str[1024];  /* This would core dump in CygWin on call to */
						/* yyparse in y.tab.c - 3100 in maximum. */
						/* Was: char	str[20000]; */

	struct expr_str *ptr;
	char *sql_string;
	struct fh_field_entry *field_entry;
	struct fh_field_list *field_list;
	struct generic_entry_list *list;
	struct generic_entry *entry;
	struct generic_entry_ident *ident;
	struct generic_entry_variable *variable;
	struct generic_entry_literal *literal;
	struct variable_usage *var_usg;
	struct num_list *num_list;
	struct array_list *array_list;
	int 	integer_val;
	float 	float_val;
	} YYSTYPE;
/* Line 191 of yacc.c.  */
#line 1706 "y.tab.c"
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 214 of yacc.c.  */
#line 1718 "y.tab.c"

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
#define YYFINAL  44
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   11310

/* YYNTOKENS -- Number of terminals. */
#define YYNTOKENS  727
/* YYNNTS -- Number of nonterminals. */
#define YYNNTS  863
/* YYNRULES -- Number of rules. */
#define YYNRULES  2356
/* YYNRULES -- Number of states. */
#define YYNSTATES  3778

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   1724

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
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    93,    94,    95,
      96,    97,    98,    99,   100,   101,   102,   103,   104,   105,
     106,   107,   108,   109,   110,   111,   112,   113,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   131,   132,   133,   134,   135,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
     146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,   158,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,   173,   174,   175,
     176,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,   192,   193,   194,   195,
     196,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
     256,   257,   258,   259,   260,   261,   262,   263,   264,   265,
     266,   267,   268,   269,   270,   271,   272,   273,   274,   275,
     276,   277,   278,   279,   280,   281,   282,   283,   284,   285,
     286,   287,   288,   289,   290,   291,   292,   293,   294,   295,
     296,   297,   298,   299,   300,   301,   302,   303,   304,   305,
     306,   307,   308,   309,   310,   311,   312,   313,   314,   315,
     316,   317,   318,   319,   320,   321,   322,   323,   324,   325,
     326,   327,   328,   329,   330,   331,   332,   333,   334,   335,
     336,   337,   338,   339,   340,   341,   342,   343,   344,   345,
     346,   347,   348,   349,   350,   351,   352,   353,   354,   355,
     356,   357,   358,   359,   360,   361,   362,   363,   364,   365,
     366,   367,   368,   369,   370,   371,   372,   373,   374,   375,
     376,   377,   378,   379,   380,   381,   382,   383,    15,   384,
     385,   386,   387,   388,   389,   390,   391,   392,   393,   394,
     395,   396,   397,   398,   399,   400,   401,   402,   403,   404,
     405,   406,   407,   408,   409,   410,   411,   412,   413,   414,
     415,   416,   417,   418,   419,   420,   421,   422,   423,   424,
     425,   426,   427,   428,   429,   430,   431,   432,   433,   434,
     435,   436,   437,   438,   439,    16,   440,   441,   442,   443,
     444,   445,    23,   446,   447,   448,   449,   450,   451,   452,
     453,   454,   455,   456,   457,   458,   459,   460,   461,    10,
     462,   463,   464,   465,   466,   467,   468,   469,   470,   471,
     472,   473,   474,   475,   476,   477,    13,   478,   479,   480,
     481,   482,   483,   484,   485,   486,   487,   488,   489,   490,
     491,   492,   493,   494,   495,   496,   497,   498,   499,   500,
     501,   502,   503,   504,   505,   506,   507,    17,   508,   509,
     510,   511,   512,   513,   514,   515,   516,   517,   518,   519,
     520,   521,   522,   523,   524,   525,   526,   527,   528,   529,
     530,   531,   532,   533,   534,   535,   536,   537,   538,   539,
     540,   541,   542,   543,   544,   545,   546,   547,   548,   549,
     550,   551,   552,   553,   554,   555,   556,   557,   558,   559,
     560,    12,   561,   562,   563,    11,    20,   564,   565,   566,
     567,   568,   569,   570,   571,   572,   573,   574,   575,     8,
     576,   577,   578,   579,   580,   581,   582,   583,   584,   585,
     586,   587,   588,    21,   589,   590,   591,   592,   593,   594,
     595,   596,   597,   598,   599,   600,   601,   602,   603,   604,
     605,   606,   607,   608,   609,   610,   611,   612,   613,   614,
     615,   616,   617,   618,   619,   620,   621,   622,   623,   624,
     625,   626,   627,   628,   629,   630,   631,    14,   632,   633,
     634,   635,     7,   636,   637,   638,   639,     5,   640,   641,
     642,   643,   644,   645,   646,   647,   648,   649,   650,   651,
      19,    22,     9,   652,   653,   654,   655,   656,   657,   658,
     659,   660,   661,    18,   662,   663,   664,   665,   666,   667,
     668,   669,   670,   671,   672,   673,   674,     6,   675,   676,
     677,   678,   679,   680,   681,   682,   683,   684,   685,   686,
     687,   688,   689,   690,   691,   692,   693,   694,   695,   696,
     697,   698,   699,   700,   701,   702,   703,   704,   705,   706,
     707,   708,   709,   710,   711,   712,   713,   714,   715,   716,
     717,   718,   719,   720,   721,   722,   723,   724,   725,   726,
       2,     3,     4,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35
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
     289,   291,   293,   297,   298,   305,   306,   312,   314,   317,
     319,   322,   324,   325,   326,   330,   331,   332,   336,   337,
     342,   343,   348,   351,   354,   357,   359,   362,   365,   369,
     371,   373,   375,   378,   380,   382,   385,   387,   388,   389,
     395,   403,   412,   413,   416,   418,   422,   424,   428,   432,
     434,   437,   438,   443,   444,   449,   450,   454,   455,   459,
     460,   464,   466,   470,   472,   476,   478,   480,   482,   484,
     486,   488,   493,   494,   499,   501,   503,   504,   506,   508,
     511,   512,   513,   519,   521,   523,   527,   528,   531,   536,
     541,   546,   551,   554,   555,   560,   562,   564,   566,   569,
     571,   573,   577,   578,   580,   581,   583,   585,   587,   588,
     596,   597,   603,   604,   617,   619,   621,   623,   625,   627,
     633,   637,   639,   641,   642,   647,   648,   654,   655,   663,
     665,   669,   671,   673,   674,   676,   677,   678,   683,   685,
     687,   689,   691,   696,   701,   706,   713,   718,   725,   727,
     730,   732,   734,   736,   738,   743,   750,   752,   757,   764,
     765,   769,   770,   774,   775,   779,   781,   783,   785,   787,
     789,   792,   795,   797,   799,   800,   804,   809,   811,   813,
     814,   818,   822,   823,   826,   828,   830,   832,   834,   836,
     838,   841,   842,   845,   846,   850,   851,   855,   857,   858,
     862,   864,   866,   868,   870,   872,   874,   877,   879,   880,
     882,   883,   889,   891,   893,   895,   900,   905,   912,   914,
     916,   918,   920,   925,   932,   934,   939,   946,   948,   950,
     952,   954,   956,   959,   962,   964,   969,   970,   978,   979,
     992,   993,   998,   999,  1005,  1007,  1011,  1014,  1016,  1020,
    1022,  1023,  1026,  1029,  1031,  1034,  1040,  1045,  1048,  1053,
    1059,  1063,  1064,  1065,  1077,  1078,  1081,  1083,  1084,  1087,
    1089,  1091,  1094,  1095,  1099,  1100,  1104,  1105,  1109,  1112,
    1115,  1118,  1123,  1129,  1131,  1133,  1135,  1137,  1139,  1141,
    1143,  1145,  1147,  1149,  1151,  1153,  1155,  1157,  1159,  1161,
    1163,  1165,  1168,  1170,  1172,  1174,  1177,  1179,  1181,  1183,
    1186,  1189,  1191,  1193,  1195,  1197,  1199,  1201,  1203,  1205,
    1207,  1209,  1212,  1214,  1217,  1219,  1221,  1223,  1227,  1229,
    1233,  1235,  1239,  1241,  1244,  1246,  1248,  1252,  1257,  1262,
    1264,  1266,  1268,  1270,  1272,  1276,  1278,  1281,  1284,  1286,
    1287,  1291,  1294,  1297,  1299,  1303,  1308,  1313,  1319,  1325,
    1327,  1329,  1332,  1335,  1340,  1345,  1348,  1351,  1356,  1361,
    1363,  1366,  1369,  1372,  1375,  1378,  1381,  1384,  1387,  1390,
    1393,  1396,  1399,  1402,  1405,  1406,  1407,  1408,  1415,  1416,
    1417,  1426,  1427,  1428,  1435,  1436,  1437,  1444,  1445,  1446,
    1453,  1454,  1455,  1462,  1468,  1474,  1480,  1486,  1494,  1502,
    1512,  1522,  1529,  1538,  1549,  1560,  1568,  1578,  1587,  1598,
    1611,  1626,  1641,  1652,  1665,  1678,  1683,  1690,  1691,  1695,
    1697,  1699,  1704,  1709,  1714,  1719,  1724,  1729,  1731,  1733,
    1735,  1737,  1742,  1747,  1750,  1753,  1756,  1759,  1762,  1764,
    1766,  1769,  1771,  1773,  1775,  1778,  1783,  1790,  1797,  1801,
    1807,  1813,  1817,  1819,  1821,  1825,  1827,  1831,  1833,  1837,
    1838,  1839,  1851,  1852,  1855,  1856,  1857,  1858,  1868,  1869,
    1873,  1874,  1875,  1886,  1887,  1889,  1890,  1892,  1894,  1897,
    1898,  1902,  1903,  1907,  1908,  1910,  1912,  1915,  1916,  1920,
    1921,  1925,  1929,  1931,  1936,  1940,  1942,  1946,  1948,  1952,
    1954,  1958,  1960,  1963,  1964,  1968,  1969,  1973,  1974,  1979,
    1980,  1985,  1986,  1991,  1994,  1998,  2000,  2004,  2006,  2008,
    2010,  2012,  2014,  2016,  2018,  2022,  2024,  2026,  2031,  2038,
    2043,  2047,  2054,  2058,  2065,  2067,  2069,  2071,  2073,  2075,
    2077,  2079,  2081,  2082,  2085,  2087,  2089,  2091,  2096,  2098,
    2100,  2102,  2107,  2111,  2118,  2122,  2129,  2131,  2133,  2136,
    2139,  2141,  2144,  2147,  2149,  2153,  2155,  2158,  2161,  2164,
    2169,  2172,  2175,  2180,  2181,  2190,  2191,  2193,  2195,  2197,
    2198,  2200,  2203,  2204,  2206,  2209,  2210,  2212,  2215,  2216,
    2218,  2222,  2223,  2226,  2227,  2228,  2237,  2238,  2239,  2243,
    2244,  2245,  2253,  2259,  2262,  2265,  2266,  2272,  2277,  2279,
    2283,  2287,  2291,  2293,  2294,  2297,  2299,  2300,  2302,  2304,
    2307,  2308,  2313,  2314,  2319,  2320,  2324,  2325,  2329,  2330,
    2334,  2335,  2339,  2340,  2344,  2345,  2349,  2350,  2354,  2355,
    2359,  2360,  2364,  2365,  2369,  2370,  2374,  2376,  2380,  2382,
    2386,  2389,  2394,  2396,  2398,  2400,  2401,  2406,  2412,  2419,
    2420,  2431,  2435,  2438,  2441,  2443,  2445,  2448,  2451,  2452,
    2455,  2457,  2460,  2464,  2468,  2472,  2476,  2478,  2480,  2482,
    2484,  2485,  2489,  2491,  2492,  2496,  2499,  2502,  2504,  2508,
    2510,  2514,  2516,  2518,  2520,  2522,  2524,  2526,  2528,  2530,
    2532,  2534,  2536,  2538,  2540,  2542,  2544,  2546,  2548,  2550,
    2552,  2554,  2555,  2556,  2564,  2566,  2568,  2571,  2574,  2577,
    2581,  2586,  2587,  2591,  2592,  2594,  2596,  2599,  2601,  2603,
    2605,  2607,  2609,  2611,  2612,  2614,  2616,  2619,  2622,  2624,
    2626,  2628,  2630,  2632,  2634,  2636,  2638,  2640,  2642,  2644,
    2645,  2647,  2649,  2651,  2653,  2654,  2655,  2656,  2657,  2671,
    2673,  2674,  2675,  2682,  2685,  2687,  2690,  2693,  2696,  2698,
    2700,  2703,  2705,  2706,  2710,  2713,  2715,  2717,  2719,  2720,
    2721,  2722,  2737,  2738,  2744,  2746,  2747,  2751,  2752,  2760,
    2761,  2767,  2769,  2772,  2773,  2775,  2777,  2779,  2780,  2782,
    2784,  2787,  2790,  2793,  2795,  2797,  2799,  2801,  2805,  2807,
    2809,  2810,  2811,  2819,  2821,  2824,  2825,  2829,  2830,  2835,
    2838,  2839,  2842,  2844,  2846,  2848,  2850,  2852,  2854,  2856,
    2860,  2861,  2863,  2865,  2867,  2869,  2872,  2875,  2878,  2884,
    2893,  2895,  2897,  2899,  2904,  2909,  2911,  2913,  2915,  2917,
    2920,  2924,  2931,  2933,  2937,  2939,  2941,  2943,  2947,  2954,
    2964,  2966,  2968,  2970,  2972,  2975,  2976,  2978,  2980,  2984,
    2986,  2990,  2992,  2996,  2998,  3002,  3004,  3006,  3008,  3010,
    3014,  3016,  3020,  3022,  3026,  3028,  3030,  3032,  3036,  3039,
    3040,  3042,  3044,  3046,  3050,  3052,  3056,  3064,  3065,  3073,
    3074,  3081,  3085,  3087,  3091,  3093,  3096,  3102,  3103,  3111,
    3112,  3115,  3116,  3118,  3124,  3127,  3133,  3134,  3140,  3147,
    3152,  3153,  3155,  3157,  3163,  3164,  3167,  3168,  3174,  3179,
    3182,  3184,  3188,  3191,  3194,  3197,  3200,  3203,  3206,  3208,
    3211,  3214,  3217,  3220,  3223,  3226,  3229,  3231,  3233,  3235,
    3237,  3240,  3243,  3245,  3247,  3249,  3251,  3253,  3255,  3261,
    3263,  3265,  3268,  3273,  3278,  3285,  3288,  3290,  3291,  3303,
    3304,  3307,  3313,  3314,  3316,  3317,  3320,  3322,  3325,  3326,
    3330,  3332,  3333,  3338,  3339,  3342,  3344,  3348,  3350,  3352,
    3357,  3363,  3369,  3373,  3374,  3376,  3378,  3380,  3382,  3383,
    3385,  3393,  3396,  3399,  3402,  3405,  3408,  3410,  3413,  3414,
    3418,  3419,  3423,  3424,  3428,  3429,  3433,  3434,  3438,  3439,
    3444,  3445,  3450,  3452,  3454,  3456,  3458,  3460,  3462,  3463,
    3468,  3469,  3471,  3472,  3477,  3479,  3482,  3485,  3488,  3489,
    3491,  3493,  3496,  3499,  3500,  3503,  3504,  3509,  3513,  3519,
    3520,  3523,  3528,  3530,  3532,  3534,  3536,  3538,  3539,  3541,
    3543,  3547,  3550,  3556,  3559,  3565,  3571,  3577,  3583,  3589,
    3595,  3596,  3599,  3601,  3604,  3607,  3610,  3613,  3616,  3619,
    3621,  3624,  3627,  3630,  3633,  3635,  3638,  3641,  3644,  3647,
    3649,  3651,  3653,  3654,  3657,  3660,  3663,  3666,  3669,  3672,
    3675,  3678,  3681,  3683,  3685,  3687,  3689,  3691,  3693,  3695,
    3697,  3700,  3703,  3706,  3709,  3712,  3714,  3716,  3718,  3719,
    3723,  3726,  3727,  3728,  3729,  3730,  3731,  3732,  3748,  3749,
    3752,  3755,  3756,  3758,  3759,  3760,  3761,  3762,  3763,  3764,
    3780,  3783,  3784,  3785,  3786,  3797,  3798,  3800,  3804,  3808,
    3811,  3816,  3820,  3824,  3828,  3830,  3833,  3836,  3839,  3842,
    3844,  3846,  3847,  3848,  3857,  3858,  3859,  3869,  3870,  3872,
    3874,  3877,  3880,  3883,  3886,  3888,  3890,  3892,  3893,  3895,
    3897,  3900,  3903,  3906,  3915,  3918,  3921,  3926,  3929,  3930,
    3932,  3934,  3938,  3941,  3944,  3946,  3948,  3952,  3954,  3956,
    3959,  3961,  3965,  3969,  3973,  3975,  3979,  3981,  3983,  3985,
    3987,  3989,  3991,  3993,  3996,  4001,  4003,  4007,  4009,  4013,
    4016,  4021,  4023,  4027,  4029,  4032,  4037,  4039,  4043,  4045,
    4047,  4049,  4052,  4056,  4061,  4064,  4069,  4070,  4073,  4076,
    4081,  4083,  4087,  4089,  4091,  4093,  4096,  4098,  4100,  4102,
    4104,  4106,  4109,  4116,  4123,  4124,  4126,  4127,  4129,  4132,
    4134,  4135,  4141,  4142,  4148,  4150,  4151,  4155,  4157,  4161,
    4163,  4167,  4169,  4171,  4172,  4177,  4179,  4182,  4184,  4185,
    4186,  4190,  4191,  4192,  4196,  4198,  4200,  4202,  4204,  4206,
    4208,  4211,  4214,  4219,  4223,  4227,  4229,  4233,  4236,  4238,
    4240,  4241,  4243,  4245,  4247,  4249,  4250,  4252,  4256,  4258,
    4262,  4264,  4265,  4269,  4271,  4273,  4275,  4277,  4279,  4281,
    4283,  4285,  4287,  4289,  4291,  4293,  4301,  4308,  4313,  4318,
    4320,  4322,  4324,  4325,  4327,  4330,  4332,  4334,  4336,  4338,
    4342,  4345,  4347,  4349,  4352,  4354,  4356,  4357,  4361,  4363,
    4367,  4369,  4373,  4375,  4377,  4384,  4385,  4389,  4391,  4395,
    4396,  4398,  4403,  4409,  4412,  4414,  4416,  4421,  4423,  4427,
    4432,  4437,  4442,  4444,  4448,  4450,  4452,  4454,  4457,  4459,
    4461,  4463,  4468,  4469,  4471,  4472,  4474,  4476,  4479,  4482,
    4484,  4486,  4488,  4490,  4492,  4497,  4499,  4503,  4505,  4507,
    4509,  4512,  4514,  4516,  4519,  4522,  4524,  4528,  4531,  4534,
    4536,  4540,  4542,  4545,  4550,  4552,  4555,  4557,  4561,  4566,
    4567,  4569,  4570,  4572,  4573,  4575,  4577,  4581,  4583,  4587,
    4589,  4592,  4594,  4598,  4601,  4604,  4605,  4608,  4610,  4612,
    4618,  4622,  4628,  4632,  4634,  4638,  4640,  4642,  4643,  4645,
    4649,  4653,  4657,  4664,  4669,  4674,  4679,  4684,  4690,  4692,
    4694,  4696,  4698,  4700,  4702,  4704,  4706,  4708,  4710,  4712,
    4714,  4715,  4717,  4719,  4721,  4723,  4725,  4727,  4729,  4734,
    4735,  4737,  4742,  4744,  4750,  4756,  4758,  4760,  4762,  4764,
    4766,  4771,  4773,  4778,  4785,  4790,  4792,  4797,  4799,  4807,
    4809,  4811,  4813,  4818,  4825,  4826,  4829,  4834,  4836,  4838,
    4840,  4842,  4844,  4846,  4848,  4852,  4854,  4856,  4860,  4866,
    4870,  4876,  4884,  4888,  4890,  4892,  4896,  4902,  4906,  4912,
    4920,  4922,  4923,  4927,  4933,  4935,  4938,  4941,  4946,  4950,
    4952,  4954,  4956,  4958,  4960,  4963,  4966,  4967,  4971,  4972,
    4976,  4978,  4980,  4982,  4984,  4986,  4988,  4990,  4995,  4997,
    4999,  5001,  5003,  5005,  5007,  5009,  5014,  5016,  5018,  5020,
    5022,  5024,  5026,  5028,  5030,  5032,  5034,  5036,  5038,  5040,
    5042,  5047,  5049,  5053,  5055,  5059,  5060,  5068,  5069,  5078,
    5079,  5086,  5087,  5096,  5097,  5099,  5102,  5104,  5108,  5110,
    5114,  5120,  5122,  5124,  5126,  5128,  5130,  5131,  5132,  5142,
    5148,  5150,  5152,  5159,  5160,  5164,  5166,  5170,  5175,  5177,
    5178,  5181,  5186,  5193,  5194,  5196,  5198,  5200,  5202,  5206,
    5208,  5211,  5215,  5217,  5219,  5222,  5225,  5227,  5229,  5231,
    5234,  5237,  5240,  5243,  5248,  5252,  5255,  5259,  5263,  5267,
    5269,  5271,  5273,  5275,  5277,  5279,  5285,  5291,  5297,  5303,
    5309,  5314,  5319,  5323,  5328,  5330,  5332,  5334,  5338,  5340,
    5346,  5354,  5360,  5361,  5364,  5366,  5368,  5369,  5373,  5375,
    5379,  5381,  5383,  5385,  5386,  5390,  5392,  5394,  5396,  5398,
    5403,  5410,  5412,  5414,  5417,  5421,  5423,  5425,  5427,  5429,
    5431,  5433,  5435,  5437,  5443,  5449,  5454,  5460,  5462,  5467,
    5469,  5471,  5479,  5484,  5486,  5487,  5492,  5494,  5497,  5499,
    5501,  5503,  5505,  5507,  5509,  5511,  5513,  5515,  5517,  5519,
    5521,  5523,  5525,  5527,  5529,  5531,  5533,  5535,  5537,  5539,
    5541,  5543,  5545,  5547,  5549,  5551,  5553,  5555,  5557,  5559,
    5561,  5563,  5565,  5567,  5569,  5571,  5573,  5575,  5577,  5579,
    5581,  5583,  5585,  5587,  5589,  5591,  5593,  5595,  5597,  5599,
    5601,  5603,  5605,  5607,  5609,  5611,  5613,  5615,  5617,  5619,
    5621,  5623,  5625,  5627,  5629,  5631,  5633,  5635,  5637,  5639,
    5641,  5643,  5645,  5647,  5649,  5651,  5653,  5655,  5657,  5659,
    5661,  5663,  5665,  5667,  5669,  5671,  5673,  5675,  5677,  5679,
    5681,  5683,  5685,  5687,  5689,  5691,  5693,  5695,  5697,  5699,
    5701,  5703,  5705,  5707,  5709,  5711,  5713,  5715,  5717,  5719,
    5721,  5723,  5725,  5727,  5729,  5731,  5733,  5735,  5737,  5739,
    5741,  5743,  5745,  5747,  5749,  5751,  5753,  5755,  5757,  5759,
    5761,  5763,  5765,  5767,  5769,  5771,  5773,  5775,  5777,  5779,
    5781,  5783,  5785,  5787,  5789,  5791,  5793,  5795,  5797,  5799,
    5801,  5803,  5805,  5807,  5809,  5811,  5813,  5815,  5817,  5819,
    5821,  5823,  5825,  5827,  5829,  5831,  5833,  5835,  5837,  5839,
    5841,  5843,  5845,  5847,  5849,  5851,  5853,  5855,  5857,  5859,
    5861,  5863,  5865,  5867,  5869,  5871,  5873,  5875,  5877,  5879,
    5881,  5883,  5885,  5887,  5889,  5891,  5893,  5895,  5897,  5899,
    5901,  5903,  5905,  5907,  5909,  5911,  5913,  5915,  5917,  5919,
    5921,  5923,  5925,  5927,  5929,  5931,  5933,  5935,  5937,  5939,
    5941,  5943,  5945,  5947,  5949,  5951,  5953,  5955,  5957,  5959,
    5961,  5963,  5965,  5967,  5969,  5971,  5973,  5975,  5977,  5979,
    5981,  5983,  5985,  5987,  5989,  5991,  5993,  5995,  5997,  5999,
    6001,  6003,  6005,  6007,  6009,  6011,  6013,  6015,  6017,  6019,
    6021,  6023,  6025,  6027,  6029,  6031,  6033,  6035,  6037,  6039,
    6041,  6043,  6045,  6047,  6049,  6051,  6053,  6055,  6057,  6059,
    6061,  6063,  6065,  6067,  6069,  6071,  6073,  6075,  6077,  6079,
    6081,  6083,  6085,  6087,  6089,  6091,  6093,  6095,  6097,  6099,
    6101,  6103,  6105,  6107,  6109,  6111,  6113,  6115,  6117,  6119,
    6121,  6123,  6125,  6127,  6129,  6131,  6133,  6134,  6138,  6139,
    6143,  6144,  6145,  6152,  6153,  6156,  6159,  6167,  6171,  6175,
    6178,  6181,  6184,  6186,  6190,  6192,  6196,  6198,  6202,  6204,
    6208,  6210,  6212,  6214,  6217,  6220,  6222,  6224,  6227,  6232,
    6238,  6246,  6254,  6264,  6266,  6268,  6270,  6272,  6274,  6276,
    6280,  6283,  6287,  6291,  6295,  6301,  6307,  6313,  6319,  6325,
    6330,  6335,  6339,  6344,  6346,  6348,  6350,  6352,  6356,  6357,
    6363,  6365,  6369,  6373,  6377,  6379,  6381,  6384,  6386,  6388,
    6392,  6394,  6398,  6402,  6404,  6406,  6408,  6412,  6415,  6419,
    6426,  6428,  6432,  6434,  6436,  6437,  6438,  6445,  6446,  6449,
    6450,  6452,  6454,  6457,  6460,  6462,  6464,  6469,  6473,  6475,
    6478,  6484,  6487,  6490,  6496,  6497,  6500,  6502,  6504,  6507,
    6514,  6521,  6523,  6524,  6526,  6529,  6531,  6534,  6535,  6538,
    6540,  6542,  6544,  6546,  6548,  6550,  6552,  6554,  6556,  6558,
    6560,  6562,  6564,  6566,  6568,  6570,  6572,  6574,  6576,  6578,
    6580,  6582,  6584,  6586,  6588,  6590,  6592,  6594,  6596,  6598,
    6600,  6602,  6604,  6606,  6608,  6610,  6612,  6614,  6616,  6618,
    6620,  6622,  6624,  6626,  6628,  6630,  6632,  6634,  6636,  6638,
    6640,  6642,  6644,  6646,  6648,  6650,  6652,  6654,  6656,  6658,
    6660,  6662,  6664,  6666,  6668,  6670,  6672,  6674,  6676,  6678,
    6680,  6682,  6684,  6686,  6688,  6690,  6692,  6694,  6696,  6698,
    6700,  6702,  6704,  6706,  6708,  6710,  6712
};

/* YYRHS -- A `-1'-separated list of the rules' RHS. */
static const short yyrhs[] =
{
    1097,     0,    -1,   251,    -1,   248,    -1,   182,   732,   477,
     645,   733,    -1,   193,    -1,  1162,    -1,    26,    -1,   734,
      -1,   733,     5,   734,    -1,  1005,    -1,   481,   735,   444,
      -1,   735,   736,   735,    -1,    26,    -1,   737,    26,    -1,
    1162,    -1,   945,    -1,    18,    -1,    19,    -1,    20,    -1,
      21,    -1,    22,    -1,    18,    -1,    19,    -1,    -1,   739,
      -1,    -1,   326,   481,   740,   741,   444,    -1,   618,   481,
      26,     5,    26,   444,    -1,   742,    -1,   741,     5,   742,
      -1,   540,    -1,   581,    -1,   586,    -1,   556,    -1,   461,
      -1,   654,    -1,   578,    -1,   530,    -1,   467,    -1,   541,
      -1,   399,    -1,   582,    -1,   506,    -1,   386,    -1,   643,
      -1,   149,    -1,  1076,    -1,    -1,   744,    -1,    -1,   326,
     481,   745,   746,   444,    -1,   747,    -1,   746,     5,   747,
      -1,   742,    -1,   482,    -1,   652,    25,    -1,   254,   991,
      -1,   383,   991,    -1,   336,   991,    -1,   391,   991,    -1,
     345,   991,    -1,   311,   991,    -1,   584,   749,    -1,   934,
     398,  1162,    -1,    -1,   341,   481,   953,   444,   398,   750,
    1180,    -1,   157,   481,  1005,     5,    25,     5,    25,   444,
      -1,   458,   481,   997,   444,   398,  1162,    -1,  1300,    -1,
     244,   481,   953,   444,   398,  1162,    -1,    -1,    -1,  1162,
     639,  1005,   481,   751,   765,   444,   752,   763,    -1,    -1,
      -1,    -1,  1005,   481,   753,   765,   754,   444,   755,   763,
      -1,    -1,    -1,   524,  1509,   672,  1509,   481,   756,   765,
     757,   444,   763,    -1,    -1,    -1,  1005,   571,  1005,   481,
     758,   765,   759,   444,   763,    -1,    -1,    -1,    -1,   418,
     768,   639,   769,   509,   732,   477,   481,   760,   765,   761,
     444,   762,   764,    -1,    -1,   398,  1180,    -1,    -1,   398,
    1180,    -1,   215,    -1,    -1,   766,    -1,   767,    -1,   766,
       5,   767,    -1,   905,    -1,   533,    -1,    25,    -1,  1005,
      -1,  1005,    -1,  1005,   669,  1005,    -1,    -1,   585,   912,
     771,   774,   778,   775,    -1,    -1,   585,   772,   773,   776,
     775,    -1,   780,    -1,   773,   780,    -1,   782,    -1,   774,
     782,    -1,   413,    -1,    -1,    -1,   393,   777,  1584,    -1,
      -1,    -1,   393,   779,  1584,    -1,    -1,   628,   912,   781,
    1584,    -1,    -1,   628,   912,   783,  1584,    -1,   330,  1002,
      -1,   253,  1000,    -1,   135,  1000,    -1,   220,    -1,   237,
    1515,    -1,   544,   999,    -1,    30,   786,    31,    -1,   787,
      -1,   789,    -1,   788,    -1,   787,   788,    -1,    29,    -1,
     790,    -1,   789,   790,    -1,    28,    -1,    -1,    -1,   374,
     792,   794,   793,   795,    -1,   437,  1162,   674,   796,  1048,
    1075,   738,    -1,  1162,   674,   796,  1048,   596,   953,  1075,
     738,    -1,    -1,   798,   243,    -1,   797,    -1,   796,     5,
     797,    -1,  1005,    -1,  1005,   669,  1005,    -1,  1005,   669,
      20,    -1,   799,    -1,   798,   799,    -1,    -1,   322,   805,
     800,  1584,    -1,    -1,   325,   806,   801,  1584,    -1,    -1,
    1078,   802,  1584,    -1,    -1,   218,   803,  1584,    -1,    -1,
     216,   804,  1584,    -1,  1009,    -1,   805,     5,  1009,    -1,
    1009,    -1,   806,     5,  1009,    -1,   143,    -1,   144,    -1,
     145,    -1,   146,    -1,   147,    -1,   148,    -1,   481,   905,
     809,   444,    -1,    -1,     5,   856,   675,   859,    -1,   208,
      -1,   331,    -1,    -1,   812,    -1,   813,    -1,   812,   813,
      -1,    -1,    -1,   488,   814,   816,   815,  1269,    -1,   869,
      -1,   819,    -1,   816,     5,   819,    -1,    -1,   818,  1005,
      -1,   407,   817,   868,    25,    -1,   407,   817,   868,  1005,
      -1,   407,   817,   868,  1011,    -1,   407,   817,   868,    26,
      -1,   823,   841,    -1,    -1,   817,   407,   820,   821,    -1,
      26,    -1,    25,    -1,  1011,    -1,    19,    26,    -1,   817,
      -1,   822,    -1,   823,     5,   822,    -1,    -1,   371,    -1,
      -1,   719,    -1,   720,    -1,   721,    -1,    -1,   537,   509,
     833,   477,   827,   673,   841,    -1,    -1,    38,   825,   828,
     673,   841,    -1,    -1,   370,   824,   830,    26,   831,   354,
     509,   832,   477,   829,   673,   841,    -1,   481,    -1,   508,
      -1,   444,    -1,   476,    -1,    26,    -1,   834,     5,   834,
       5,   834,    -1,   834,     5,   834,    -1,   834,    -1,    26,
      -1,    -1,   514,   836,   816,   335,    -1,    -1,   312,   837,
     817,   669,    20,    -1,    -1,   388,   838,   817,   310,   481,
     839,   444,    -1,   840,    -1,   839,     5,   840,    -1,   817,
      -1,   843,    -1,    -1,   110,    -1,    -1,    -1,   844,   846,
     845,   842,    -1,   826,    -1,   835,    -1,   371,    -1,   372,
      -1,   371,   481,    26,   444,    -1,   372,   481,    26,   444,
      -1,   474,   481,    26,   444,    -1,   474,   481,    26,     5,
      26,   444,    -1,   373,   481,    26,   444,    -1,   373,   481,
      26,     5,    26,   444,    -1,   459,    -1,   666,   817,    -1,
     433,    -1,   559,    -1,   141,    -1,   449,    -1,   449,   481,
      26,   444,    -1,   449,   481,    26,     5,    26,   444,    -1,
     562,    -1,   562,   481,    26,   444,    -1,   562,   481,    26,
       5,    26,   444,    -1,    -1,   552,   847,   850,    -1,    -1,
     115,   848,   850,    -1,    -1,   351,   849,   850,    -1,   587,
      -1,   583,    -1,   131,    -1,   132,    -1,   624,    -1,   410,
     854,    -1,   422,   855,    -1,   851,    -1,    32,    -1,    -1,
     481,    26,   444,    -1,   606,   852,   669,   853,    -1,   817,
      -1,   817,    -1,    -1,   856,   675,   859,    -1,   864,   675,
     867,    -1,    -1,   857,   858,    -1,   631,    -1,   563,    -1,
     640,    -1,   602,    -1,   504,    -1,   520,    -1,   419,   861,
      -1,    -1,   860,   858,    -1,    -1,   481,   863,   444,    -1,
      -1,   481,    26,   444,    -1,    26,    -1,    -1,   865,   866,
     862,    -1,   631,    -1,   563,    -1,   640,    -1,   602,    -1,
     504,    -1,   520,    -1,   419,   861,    -1,   866,    -1,    -1,
      14,    -1,    -1,   288,  1005,   870,   666,   871,    -1,   873,
      -1,   876,    -1,   371,    -1,   371,   481,    26,   444,    -1,
     474,   481,    26,   444,    -1,   474,   481,    26,     5,    26,
     444,    -1,   459,    -1,   433,    -1,   559,    -1,   449,    -1,
     449,   481,    26,   444,    -1,   449,   481,    26,     5,    26,
     444,    -1,   562,    -1,   562,   481,    26,   444,    -1,   562,
     481,    26,     5,    26,   444,    -1,   552,    -1,   351,    -1,
     587,    -1,   583,    -1,   624,    -1,   410,   854,    -1,   422,
     855,    -1,   872,    -1,   606,   852,   669,   853,    -1,    -1,
     537,   509,   833,   477,   874,   673,   871,    -1,    -1,   370,
     824,   830,    26,   831,   354,   509,   832,   477,   875,   673,
     871,    -1,    -1,   514,   877,   879,   335,    -1,    -1,   312,
     878,  1005,   669,    20,    -1,   880,    -1,   879,     5,   880,
      -1,   881,   871,    -1,   882,    -1,   881,     5,   882,    -1,
    1005,    -1,    -1,   667,   995,    -1,   122,  1005,    -1,   120,
      -1,   675,   953,    -1,   675,   559,  1005,   708,   953,    -1,
     675,   559,  1005,   442,    -1,   124,  1005,    -1,   209,   928,
    1180,   891,    -1,   452,   928,   910,   883,   891,    -1,   262,
    1002,   891,    -1,    -1,    -1,   240,   888,  1187,   675,  1005,
     669,    20,   890,   738,   889,   892,    -1,    -1,   518,   996,
      -1,   738,    -1,    -1,   893,   290,    -1,   290,    -1,   894,
      -1,   893,   894,    -1,    -1,   405,   895,  1584,    -1,    -1,
     401,   896,  1584,    -1,    -1,  1078,   897,  1584,    -1,    40,
    1162,    -1,    41,  1162,    -1,    39,  1162,    -1,   548,   928,
     911,   738,    -1,   548,   928,   911,   738,   117,    -1,   338,
      -1,   337,    -1,   265,    -1,   417,    -1,   225,    -1,   264,
      -1,   382,    -1,   381,    -1,   295,    -1,   222,    -1,   221,
      -1,   199,    -1,   255,    -1,   183,    -1,   198,    -1,   239,
      -1,   206,    -1,   266,    -1,   266,   912,    -1,   913,    -1,
     917,    -1,   945,    -1,   905,   906,    -1,   946,    -1,   948,
      -1,   914,    -1,    19,   905,    -1,    18,   905,    -1,   919,
      -1,   927,    -1,   921,    -1,   525,    -1,   807,    -1,   922,
      -1,   923,    -1,   924,    -1,   925,    -1,   926,    -1,    46,
     905,    -1,   928,    -1,   928,   909,    -1,   912,    -1,   533,
      -1,   908,    -1,   909,     5,   908,    -1,   912,    -1,   910,
       5,   912,    -1,   912,    -1,   911,     5,   912,    -1,   905,
      -1,     9,   905,    -1,   534,    -1,   478,    -1,   481,   905,
     444,    -1,   493,   481,  1489,   444,    -1,   346,   481,  1489,
     444,    -1,    25,    -1,  1011,    -1,    26,    -1,   916,    -1,
    1162,    -1,  1162,   471,  1162,    -1,   915,    -1,   484,   905,
      -1,   445,   905,    -1,  1272,    -1,    -1,   557,   918,  1272,
      -1,     7,   905,    -1,     6,   905,    -1,   905,    -1,   920,
       5,   905,    -1,   672,   481,  1489,   444,    -1,   479,   481,
    1489,   444,    -1,   672,   481,   928,   920,   444,    -1,   479,
     481,   928,   920,   444,    -1,   439,    -1,   301,    -1,    10,
     905,    -1,   304,   905,    -1,    10,   905,   492,    25,    -1,
     304,   905,   492,    25,    -1,   606,   905,    -1,   424,   905,
      -1,   606,   905,   492,    25,    -1,   424,   905,   492,    25,
      -1,   443,    -1,     8,   905,    -1,    18,   905,    -1,    19,
     905,    -1,    20,   905,    -1,    21,   905,    -1,    22,   905,
      -1,    11,   905,    -1,    14,   905,    -1,   507,   905,    -1,
      12,   905,    -1,    13,   905,    -1,    17,   905,    -1,    16,
     905,    -1,    15,   905,    -1,    -1,    -1,    -1,  1005,   481,
     930,   765,   931,   444,    -1,    -1,    -1,  1005,   571,  1005,
     481,   932,   765,   933,   444,    -1,    -1,    -1,   587,   481,
     935,   905,   936,   444,    -1,    -1,    -1,   563,   481,   937,
     905,   938,   444,    -1,    -1,    -1,   640,   481,   939,   905,
     940,   444,    -1,    -1,    -1,   631,   481,   941,   905,   942,
     444,    -1,   422,   481,   949,   444,   944,    -1,   410,   481,
      25,   444,   943,    -1,   410,   481,    26,   444,   943,    -1,
     410,   481,    24,   444,   943,    -1,   410,   481,    26,   639,
      26,   444,   943,    -1,   410,   481,    26,   639,    24,   444,
     943,    -1,   410,   481,    26,   639,    26,   639,    26,   444,
     943,    -1,   410,   481,    26,   639,    26,   639,    24,   444,
     943,    -1,   410,   481,    26,    26,   444,   943,    -1,   410,
     481,    26,    26,   639,    26,   444,   943,    -1,   410,   481,
      26,    26,   639,    26,   639,    26,   444,   943,    -1,   410,
     481,    26,    26,   639,    26,   639,    24,   444,   943,    -1,
     410,   481,    26,    19,    26,   444,   943,    -1,   410,   481,
      26,    19,    26,    19,    26,   444,   943,    -1,   410,   481,
      26,    19,    26,    26,   444,   943,    -1,   410,   481,    26,
      19,    26,    19,    26,    26,   444,   943,    -1,   410,   481,
      26,    19,    26,    19,    26,    26,   639,    26,   444,   943,
      -1,   410,   481,    26,    19,    26,    19,    26,    26,   639,
      26,   639,    26,   444,   943,    -1,   410,   481,    26,    19,
      26,    19,    26,    26,   639,    26,   639,    24,   444,   943,
      -1,   410,   481,    26,    19,    26,    26,   639,    26,   444,
     943,    -1,   410,   481,    26,    19,    26,    26,   639,    26,
     639,    26,   444,   943,    -1,   410,   481,    26,    19,    26,
      26,   639,    26,   639,    24,   444,   943,    -1,   724,   481,
    1162,   444,    -1,   725,   481,  1162,     5,    26,   444,    -1,
      -1,  1469,   675,  1470,    -1,   855,    -1,   934,    -1,   341,
     481,   953,   444,    -1,   150,   481,   996,   444,    -1,   123,
     481,   996,   444,    -1,   458,   481,   954,   444,    -1,   244,
     481,   953,   444,    -1,   111,   481,   953,   444,    -1,   947,
      -1,   929,    -1,  1465,    -1,   587,    -1,   473,   481,   905,
     444,    -1,   376,   481,   905,   444,    -1,   538,   905,    -1,
     494,   808,    -1,   905,   161,    -1,   905,   162,    -1,   905,
     163,    -1,    25,    -1,   950,    -1,    19,   950,    -1,   952,
      -1,   951,    -1,    26,    -1,    26,    26,    -1,    26,    26,
     639,    26,    -1,    26,    26,   639,    26,   639,    26,    -1,
      26,    26,   639,    26,   639,    24,    -1,    26,   639,    26,
      -1,    26,   639,    26,   639,    26,    -1,    26,   639,    26,
     639,    24,    -1,    26,   639,    24,    -1,    24,    -1,    26,
      -1,    26,    19,    26,    -1,   996,    -1,   953,     5,   996,
      -1,   997,    -1,   954,     5,   997,    -1,    -1,    -1,   645,
    1162,    14,   912,   675,   912,   958,   956,  1584,   957,   293,
      -1,    -1,   621,   912,    -1,    -1,    -1,    -1,   455,   960,
     999,   961,   963,  1367,   962,  1584,   292,    -1,    -1,     8,
     928,   910,    -1,    -1,    -1,   687,  1005,   965,   811,   966,
    1107,   968,   967,   973,   688,    -1,    -1,   978,    -1,    -1,
     969,    -1,   970,    -1,   969,   970,    -1,    -1,   689,   971,
    1584,    -1,    -1,   690,   972,  1584,    -1,    -1,   974,    -1,
     975,    -1,   974,   975,    -1,    -1,   691,   976,  1584,    -1,
      -1,   692,   977,  1584,    -1,   979,   983,   378,    -1,   142,
      -1,   142,   980,   596,   981,    -1,   142,   437,   982,    -1,
    1162,    -1,   980,     5,  1162,    -1,  1005,    -1,   981,     5,
    1005,    -1,  1162,    -1,   982,     5,  1162,    -1,   984,    -1,
     983,   984,    -1,    -1,   693,   985,  1584,    -1,    -1,   694,
     986,  1584,    -1,    -1,   713,   981,   987,  1584,    -1,    -1,
     531,   981,   988,  1584,    -1,    -1,   674,   981,   989,  1584,
      -1,   595,   998,    -1,   604,    19,    26,    -1,   604,    -1,
     551,    18,    26,    -1,   551,    -1,    26,    -1,  1162,    -1,
     718,    -1,    25,    -1,  1010,    -1,   912,    -1,   993,     5,
     993,    -1,   994,    -1,  1005,    -1,   716,   481,  1005,   444,
      -1,  1005,   669,   716,   481,  1005,   444,    -1,  1005,   509,
     735,   477,    -1,  1005,   669,    20,    -1,  1005,   509,   735,
     477,   669,    20,    -1,  1005,   669,  1005,    -1,  1005,   509,
     735,   477,   669,  1005,    -1,   996,    -1,    25,    -1,  1006,
      -1,  1006,    -1,  1006,    -1,  1006,    -1,  1006,    -1,  1006,
      -1,    -1,   600,    26,    -1,  1583,    -1,  1007,    -1,  1583,
      -1,   403,   481,  1008,   444,    -1,  1165,    -1,    25,    -1,
    1005,    -1,  1005,   509,   735,   477,    -1,  1005,   669,    20,
      -1,  1005,   509,   735,   477,   669,    20,    -1,  1005,   669,
    1005,    -1,  1005,   509,   735,   477,   669,  1005,    -1,  1162,
      -1,    24,    -1,   669,    26,    -1,   597,  1013,    -1,  1005,
      -1,   639,  1005,    -1,   701,  1015,    -1,  1016,    -1,  1015,
       5,  1016,    -1,  1005,    -1,   712,  1015,    -1,   703,  1015,
      -1,   704,   953,    -1,   702,  1002,   708,   953,    -1,   706,
    1015,    -1,   707,   953,    -1,   705,  1002,   708,   953,    -1,
      -1,   710,  1021,   910,  1026,  1028,  1030,  1022,  1024,    -1,
      -1,  1023,    -1,   698,    -1,   699,    -1,    -1,  1025,    -1,
     398,  1162,    -1,    -1,  1027,    -1,   442,   910,    -1,    -1,
    1029,    -1,   709,    26,    -1,    -1,  1031,    -1,   700,    26,
    1032,    -1,    -1,   451,    26,    -1,    -1,    -1,   671,   912,
     625,  1034,  1584,  1035,  1036,   491,    -1,    -1,    -1,   592,
    1037,  1584,    -1,    -1,    -1,   114,  1038,   912,   625,  1039,
    1584,  1036,    -1,   159,  1005,   481,    26,   444,    -1,   105,
    1005,    -1,   127,  1005,    -1,    -1,   342,  1191,  1043,   675,
     533,    -1,   342,  1191,   606,  1044,    -1,  1045,    -1,  1044,
       5,  1045,    -1,  1046,   669,  1461,    -1,  1046,   669,    20,
      -1,  1457,    -1,    -1,  1049,   378,    -1,   378,    -1,    -1,
     203,    -1,  1050,    -1,  1049,  1050,    -1,    -1,   322,  1064,
    1051,  1584,    -1,    -1,   325,  1065,  1052,  1584,    -1,    -1,
     405,  1053,  1584,    -1,    -1,   401,  1054,  1584,    -1,    -1,
    1078,  1055,  1584,    -1,    -1,   357,  1056,  1584,    -1,    -1,
     327,  1057,  1584,    -1,    -1,    47,  1058,  1584,    -1,    -1,
      44,  1059,  1584,    -1,    -1,    43,  1060,  1584,    -1,    -1,
      42,  1061,  1584,    -1,    -1,    50,  1062,  1584,    -1,    -1,
      49,  1063,  1584,    -1,   996,    -1,  1064,     5,   996,    -1,
     996,    -1,  1065,     5,   996,    -1,   366,  1068,    -1,   367,
    1005,   708,  1068,    -1,   611,    -1,   428,    -1,   996,    -1,
      -1,   714,  1071,  1070,  1047,    -1,   437,  1180,  1048,  1004,
     738,    -1,  1180,  1048,   596,   953,  1004,   738,    -1,    -1,
     537,  1187,  1048,   596,  1005,   669,    20,  1004,  1072,   738,
      -1,   519,   953,  1074,    -1,   133,    26,    -1,   134,    26,
      -1,   676,    -1,   589,    -1,   133,  1162,    -1,   134,  1162,
      -1,    -1,   600,    26,    -1,  1077,    -1,    56,    25,    -1,
     546,    14,    26,    -1,   546,    14,  1162,    -1,    57,    14,
      26,    -1,    57,    14,  1162,    -1,    53,    -1,    55,    -1,
      52,    -1,    54,    -1,    -1,   480,  1079,  1084,    -1,   347,
      -1,    -1,   646,  1081,  1084,    -1,   355,  1086,    -1,   646,
    1084,    -1,  1086,    -1,   481,  1085,   444,    -1,  1086,    -1,
    1085,     5,  1086,    -1,  1087,    -1,   644,    -1,   364,    -1,
     384,    -1,   356,    -1,   535,    -1,   492,    -1,   676,    -1,
     600,    -1,   589,    -1,   229,    -1,   489,    -1,   500,    -1,
     590,    -1,   605,    -1,   570,    -1,   362,    -1,   363,    -1,
      25,    -1,   560,    -1,    -1,    -1,   648,  1090,  1185,  1091,
      14,   928,  1092,    -1,   533,    -1,   911,    -1,   271,  1162,
      -1,   261,  1162,    -1,   274,  1162,    -1,   501,  1183,   387,
      -1,   501,  1183,   438,   992,    -1,    -1,  1099,  1098,  1102,
      -1,    -1,  1100,    -1,  1101,    -1,  1100,  1101,    -1,  1041,
      -1,  1106,    -1,  1568,    -1,  1122,    -1,  1108,    -1,  1121,
      -1,    -1,  1103,    -1,  1105,    -1,  1103,  1105,    -1,   118,
    1005,    -1,  1110,    -1,  1116,    -1,  1128,    -1,  1282,    -1,
    1292,    -1,  1149,    -1,   964,    -1,   785,    -1,  1040,    -1,
    1568,    -1,   785,    -1,    -1,   785,    -1,   812,    -1,   420,
      -1,   112,    -1,    -1,    -1,    -1,    -1,  1109,  1111,  1005,
     481,  1112,  1178,   444,  1113,   811,  1114,  1107,  1584,  1115,
      -1,   263,    -1,    -1,    -1,   607,  1117,   811,  1118,  1584,
     414,    -1,   229,   907,    -1,   928,    -1,   928,   910,    -1,
     409,  1473,    -1,   517,  1473,    -1,  1123,    -1,  1124,    -1,
    1123,  1124,    -1,  1125,    -1,    -1,   457,  1126,  1127,    -1,
     811,   294,    -1,   992,    -1,  1106,    -1,  1121,    -1,    -1,
      -1,    -1,   166,  1005,   165,  1005,   481,  1129,  1178,   444,
    1130,   811,  1131,  1107,  1584,  1115,    -1,    -1,   608,  1133,
    1148,  1139,  1134,    -1,   415,    -1,    -1,   286,  1136,  1584,
      -1,    -1,    23,  1140,  1141,  1142,  1004,  1137,  1584,    -1,
      -1,    23,  1140,  1004,  1138,  1584,    -1,  1135,    -1,  1139,
    1135,    -1,    -1,  1080,    -1,    25,    -1,  1162,    -1,    -1,
    1162,    -1,    25,    -1,   303,  1146,    -1,   315,  1147,    -1,
     298,  1147,    -1,   635,    -1,    25,    -1,  1162,    -1,  1146,
      -1,  1147,     5,  1146,    -1,  1162,    -1,    25,    -1,    -1,
      -1,   695,  1005,  1150,   811,  1151,  1152,   696,    -1,  1153,
      -1,  1152,  1153,    -1,    -1,   697,  1154,  1584,    -1,    -1,
     674,  1005,  1155,  1584,    -1,  1159,  1157,    -1,    -1,   739,
    1160,    -1,  1161,    -1,  1158,    -1,  1027,    -1,  1029,    -1,
    1031,    -1,  1023,    -1,  1025,    -1,   423,   928,   910,    -1,
      -1,   117,    -1,   117,    -1,  1163,    -1,  1165,    -1,   242,
    1165,    -1,  1165,   669,    -1,  1164,  1169,    -1,  1164,  1005,
     509,  1172,   477,    -1,  1164,  1005,   509,  1172,   477,   509,
    1172,   477,    -1,  1170,    -1,  1005,    -1,  1166,    -1,  1005,
     508,  1168,   476,    -1,  1005,   508,  1168,   476,    -1,  1162,
      -1,    25,    -1,    20,    -1,  1005,    -1,  1005,  1171,    -1,
     509,  1172,   477,    -1,   509,  1172,   477,   509,  1172,   477,
      -1,  1173,    -1,  1172,     5,  1173,    -1,   735,    -1,  1175,
      -1,  1177,    -1,  1175,   669,  1176,    -1,  1175,   669,  1005,
     509,  1172,   477,    -1,  1175,   669,  1005,   509,  1172,   477,
     509,  1172,   477,    -1,  1005,    -1,  1167,    -1,    20,    -1,
    1005,    -1,  1005,  1171,    -1,    -1,  1179,    -1,  1181,    -1,
    1179,     5,  1181,    -1,  1182,    -1,  1180,     5,  1182,    -1,
    1005,    -1,  1005,   669,  1005,    -1,  1162,    -1,  1162,   471,
    1162,    -1,    25,    -1,  1011,    -1,    26,    -1,  1184,    -1,
    1183,     5,  1184,    -1,  1162,    -1,  1162,   471,  1162,    -1,
    1186,    -1,  1185,     5,  1186,    -1,  1174,    -1,  1162,    -1,
    1189,    -1,  1188,     5,  1189,    -1,  1162,  1190,    -1,    -1,
     637,    -1,   588,    -1,  1192,    -1,  1191,     5,  1192,    -1,
    1162,    -1,  1162,   471,  1162,    -1,   306,  1001,   667,   994,
     629,  1576,   743,    -1,    -1,   667,   481,   912,     5,   912,
     444,  1195,    -1,    -1,   618,   481,   912,     5,   912,   444,
      -1,   307,  1005,  1194,    -1,  1005,    -1,   392,  1003,  1199,
      -1,  1200,    -1,   596,   912,    -1,  1201,  1202,  1207,     8,
    1197,    -1,    -1,   667,  1203,   481,   912,     5,   912,   444,
      -1,    -1,   606,  1006,    -1,    -1,   404,    -1,   269,  1515,
     318,  1557,  1206,    -1,   613,   998,    -1,   613,   998,     8,
     928,   910,    -1,    -1,   666,   626,  1509,   427,  1509,    -1,
     666,   626,  1509,     5,   427,  1509,    -1,   666,  1509,     5,
    1509,    -1,    -1,   698,    -1,   699,    -1,   446,   675,  1557,
    1209,  1210,    -1,    -1,   666,  1557,    -1,    -1,   666,   626,
    1509,     8,  1509,    -1,   626,  1509,     8,  1509,    -1,   462,
    1212,    -1,  1213,    -1,  1212,     5,  1213,    -1,   254,   991,
      -1,   336,   991,    -1,   383,   991,    -1,   391,   991,    -1,
     345,   991,    -1,   311,   991,    -1,  1082,    -1,   489,  1083,
      -1,   500,  1083,    -1,   611,  1083,    -1,   428,  1083,    -1,
     600,  1083,    -1,   598,   992,    -1,   599,   992,    -1,    61,
      -1,    62,    -1,    63,    -1,    64,    -1,   452,   739,    -1,
     714,   739,    -1,   343,    -1,   247,    -1,   204,    -1,   184,
      -1,   201,    -1,   192,    -1,  1514,   464,  1217,   596,  1215,
      -1,  1162,    -1,    25,    -1,   454,  1217,    -1,   454,  1217,
       8,  1180,    -1,   454,  1217,   603,  1183,    -1,   454,  1217,
     603,  1183,     8,  1180,    -1,    51,  1215,    -1,  1006,    -1,
      -1,   512,  1227,   738,   645,  1222,  1162,  1220,  1004,   738,
    1219,  1223,    -1,    -1,   717,    26,    -1,   512,  1227,   738,
     398,  1162,    -1,    -1,   371,    -1,    -1,  1224,   334,    -1,
    1225,    -1,  1224,  1225,    -1,    -1,  1078,  1226,  1584,    -1,
     911,    -1,    -1,   653,   998,  1229,  1230,    -1,    -1,   596,
    1231,    -1,  1232,    -1,  1231,     5,  1232,    -1,  1501,    -1,
     533,    -1,   272,  1236,   140,  1234,    -1,   272,  1236,   675,
    1235,  1234,    -1,   272,  1236,   139,  1235,  1234,    -1,   272,
    1236,  1234,    -1,    -1,    45,    -1,    25,    -1,  1010,    -1,
    1005,    -1,    -1,   529,    -1,   200,  1236,  1237,   481,   928,
    1120,   444,    -1,   245,  1236,    -1,   119,  1236,    -1,  1273,
    1281,    -1,   497,   113,    -1,   497,  1243,    -1,  1244,    -1,
    1243,  1244,    -1,    -1,   188,  1245,  1584,    -1,    -1,   250,
    1246,  1584,    -1,    -1,   280,  1247,  1584,    -1,    -1,   268,
    1248,  1584,    -1,    -1,   305,  1249,  1584,    -1,    -1,   252,
    1162,  1250,  1584,    -1,    -1,   276,  1162,  1251,  1584,    -1,
    1262,    -1,  1265,    -1,  1264,    -1,  1253,    -1,  1290,    -1,
    1256,    -1,    -1,   610,   912,  1254,   532,    -1,    -1,   532,
      -1,    -1,   619,    26,  1257,  1255,    -1,   211,    -1,   678,
    1277,    -1,   214,  1277,    -1,   213,  1277,    -1,    -1,  1259,
      -1,  1260,    -1,  1259,  1260,    -1,  1270,  1261,    -1,    -1,
     667,  1277,    -1,    -1,   569,  1263,  1258,  1269,    -1,   568,
    1509,  1269,    -1,   567,  1268,  1267,  1266,  1269,    -1,    -1,
     205,   905,    -1,   205,   905,     5,   905,    -1,   662,    -1,
     663,    -1,   664,    -1,   665,    -1,  1162,    -1,    -1,   572,
      -1,  1271,    -1,  1270,     5,  1271,    -1,   912,  1304,    -1,
     658,   481,   905,   444,  1289,    -1,   116,  1289,    -1,   546,
     481,    20,   444,  1289,    -1,   463,   481,    20,   444,  1289,
      -1,   440,   481,   905,   444,  1289,    -1,   638,   481,   905,
     444,  1289,    -1,   651,   481,   905,   444,  1289,    -1,   650,
     481,   905,   444,  1289,    -1,    -1,   511,  1274,    -1,  1275,
      -1,  1274,  1275,    -1,   279,    26,    -1,   270,    26,    -1,
     353,    26,    -1,   236,    26,    -1,   308,    26,    -1,   227,
      -1,   397,    25,    -1,   397,  1162,    -1,   228,    25,    -1,
     212,    25,    -1,  1280,    -1,  1276,  1280,    -1,  1278,   161,
      -1,  1278,   163,    -1,  1278,   162,    -1,  1278,    -1,  1011,
      -1,    26,    -1,    -1,   511,  1276,    -1,   279,  1277,    -1,
     270,  1277,    -1,   353,  1277,    -1,   236,  1277,    -1,   308,
    1277,    -1,   309,  1277,    -1,   677,    25,    -1,   678,  1277,
      -1,   682,    -1,   679,    -1,   680,    -1,   681,    -1,   686,
      -1,   683,    -1,   684,    -1,   685,    -1,   128,  1277,    -1,
     129,  1277,    -1,   130,  1277,    -1,   397,    25,    -1,   228,
      25,    -1,   451,    -1,   125,    -1,   126,    -1,    -1,   564,
     668,  1188,    -1,   189,  1188,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   515,  1283,  1005,   481,  1284,  1178,   444,  1285,
     811,  1286,  1241,  1287,  1242,  1288,   291,    -1,    -1,   576,
     905,    -1,   566,  1291,    -1,    -1,  1215,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   158,  1293,  1005,   481,  1294,  1178,
     444,  1295,   811,  1296,  1299,  1297,  1242,  1298,   291,    -1,
    1279,  1281,    -1,    -1,    -1,    -1,   207,   481,    25,     5,
    1301,   765,  1302,   444,  1303,   763,    -1,    -1,   436,    -1,
     436,   270,    26,    -1,   436,   270,  1162,    -1,   656,   912,
      -1,   656,   912,   398,  1162,    -1,   656,   912,   215,    -1,
     656,   912,   627,    -1,   656,   912,   594,    -1,  1307,    -1,
     224,  1457,    -1,   377,  1457,    -1,   333,  1458,    -1,    48,
    1005,    -1,  1321,    -1,  1309,    -1,    -1,    -1,   257,  1310,
    1457,   481,  1311,  1325,   444,  1314,    -1,    -1,    -1,   186,
    1312,  1457,   481,  1313,  1325,   444,  1314,  1322,    -1,    -1,
    1315,    -1,  1316,    -1,  1315,  1316,    -1,   672,  1317,    -1,
     296,    26,    -1,    60,    26,    -1,   137,    -1,   138,    -1,
    1583,    -1,    -1,  1319,    -1,  1320,    -1,  1319,  1320,    -1,
     672,  1317,    -1,   726,    26,    -1,   156,  1458,   674,  1457,
     481,  1323,   444,  1318,    -1,   103,  1006,    -1,   104,  1006,
      -1,   223,  1457,   645,  1457,    -1,   108,  1457,    -1,    -1,
     320,    -1,  1324,    -1,  1323,     5,  1324,    -1,  1005,   637,
      -1,  1005,   588,    -1,  1005,    -1,  1326,    -1,  1325,     5,
    1326,    -1,  1409,    -1,  1407,    -1,   173,  1005,    -1,   231,
      -1,    58,  1005,  1329,    -1,    59,  1458,   153,    -1,    59,
    1458,   154,    -1,  1330,    -1,  1329,     5,  1330,    -1,  1331,
      -1,  1334,    -1,  1337,    -1,  1342,    -1,  1345,    -1,  1341,
      -1,  1340,    -1,   634,  1332,    -1,   634,   481,  1333,   444,
      -1,  1326,    -1,  1326,   713,  1005,    -1,  1332,    -1,  1333,
       5,  1332,    -1,   591,  1336,    -1,   591,   481,  1335,   444,
      -1,  1336,    -1,  1335,     5,  1336,    -1,  1005,    -1,   505,
    1339,    -1,   505,   481,  1338,   444,    -1,  1339,    -1,  1338,
       5,  1339,    -1,  1326,    -1,   137,    -1,   138,    -1,   136,
      26,    -1,   106,  1407,  1344,    -1,   106,   481,  1343,   444,
      -1,  1407,  1344,    -1,  1343,     5,  1407,  1344,    -1,    -1,
     109,  1005,    -1,   107,  1346,    -1,   107,   481,  1346,   444,
      -1,  1347,    -1,  1346,     5,  1347,    -1,  1005,    -1,   317,
      -1,   283,    -1,   217,  1350,    -1,   196,    -1,   185,    -1,
     172,    -1,   170,    -1,   174,    -1,   230,  1515,    -1,   282,
    1349,   510,  1509,   675,  1509,    -1,   350,   998,   510,  1509,
     675,  1509,    -1,    -1,  1515,    -1,    -1,   912,    -1,   573,
     912,    -1,   281,    -1,    -1,   300,  1354,  1457,  1357,  1355,
      -1,    -1,   529,  1356,   481,  1359,   444,    -1,  1495,    -1,
      -1,   481,  1358,   444,    -1,  1461,    -1,  1358,     5,  1461,
      -1,  1360,    -1,  1359,     5,  1360,    -1,  1501,    -1,   533,
      -1,    -1,   550,  1362,  1364,  1365,    -1,  1006,    -1,  1369,
     999,    -1,   999,    -1,    -1,    -1,   603,  1366,  1183,    -1,
      -1,    -1,   603,  1368,  1183,    -1,   551,    -1,   604,    -1,
     611,    -1,   428,    -1,   395,    -1,   447,    -1,   431,   912,
      -1,   404,   912,    -1,   289,  1457,   202,   999,    -1,   289,
    1457,  1430,    -1,   564,   668,  1373,    -1,  1374,    -1,  1373,
       5,  1374,    -1,  1375,  1376,    -1,    26,    -1,  1461,    -1,
      -1,   637,    -1,   588,    -1,   328,    -1,   361,    -1,    -1,
     380,    -1,   409,  1381,  1379,    -1,  1557,    -1,  1557,   661,
    1005,    -1,    25,    -1,    -1,  1514,  1383,  1384,    -1,  1415,
      -1,  1419,    -1,  1378,    -1,  1516,    -1,  1377,    -1,  1370,
      -1,  1371,    -1,  1361,    -1,  1353,    -1,  1352,    -1,  1485,
      -1,  1537,    -1,   555,  1388,   674,  1457,   675,  1393,  1387,
      -1,   516,  1388,   674,  1457,   596,  1393,    -1,   555,  1386,
     675,  1393,    -1,   516,  1386,   596,  1393,    -1,   446,    -1,
     432,    -1,   641,    -1,    -1,   195,    -1,   666,  1005,    -1,
     219,    -1,   635,    -1,  1389,    -1,  1390,    -1,  1389,     5,
    1390,    -1,   521,  1391,    -1,   500,    -1,   489,    -1,   528,
    1391,    -1,   536,    -1,   558,    -1,    -1,   481,  1392,   444,
      -1,  1461,    -1,  1392,     5,  1461,    -1,  1394,    -1,  1393,
       5,  1394,    -1,   513,    -1,  1459,    -1,   287,  1457,  1396,
     666,  1495,  1398,    -1,    -1,   481,  1397,   444,    -1,  1461,
      -1,  1397,     5,  1461,    -1,    -1,   194,    -1,   542,   481,
    1433,   444,    -1,   297,   481,  1402,   444,  1401,    -1,   348,
    1403,    -1,  1404,    -1,  1457,    -1,  1457,   481,  1404,   444,
      -1,  1461,    -1,  1404,     5,  1461,    -1,   526,   481,  1406,
     444,    -1,   412,   481,  1406,   444,    -1,   310,   481,  1406,
     444,    -1,  1461,    -1,  1406,     5,  1461,    -1,  1405,    -1,
    1400,    -1,  1399,    -1,   451,  1464,    -1,   260,    -1,   259,
      -1,   258,    -1,  1005,  1449,  1410,  1411,    -1,    -1,  1408,
      -1,    -1,  1412,    -1,  1413,    -1,  1412,  1413,    -1,  1414,
    1344,    -1,   426,    -1,   210,    -1,   526,    -1,   412,    -1,
    1401,    -1,   542,   481,  1433,   444,    -1,   310,    -1,   171,
    1416,  1418,    -1,  1417,    -1,  1459,    -1,  1419,    -1,  1418,
    1419,    -1,  1395,    -1,  1385,    -1,   498,  1433,    -1,   421,
    1422,    -1,  1500,    -1,  1422,     5,  1500,    -1,   576,  1433,
      -1,   596,  1425,    -1,  1426,    -1,  1425,     5,  1426,    -1,
    1427,    -1,   565,  1427,    -1,   565,   481,  1428,   444,    -1,
    1457,    -1,  1457,  1463,    -1,  1426,    -1,  1428,     5,  1426,
      -1,  1424,  1430,  1431,  1432,    -1,    -1,  1423,    -1,    -1,
    1421,    -1,    -1,  1420,    -1,  1434,    -1,  1433,     6,  1434,
      -1,  1435,    -1,  1434,     7,  1435,    -1,  1436,    -1,     9,
    1436,    -1,  1447,    -1,   481,  1433,   444,    -1,   493,  1496,
      -1,   346,  1496,    -1,    -1,   492,  1440,    -1,  1502,    -1,
    1505,    -1,  1501,   672,   481,  1442,   444,    -1,  1501,   672,
    1496,    -1,  1501,   479,   481,  1442,   444,    -1,  1501,   479,
    1496,    -1,  1443,    -1,  1442,     5,  1443,    -1,  1563,    -1,
    1464,    -1,    -1,     9,    -1,  1501,  1444,   439,    -1,  1501,
    1444,   301,    -1,  1501,  1446,  1501,    -1,  1501,  1444,   441,
    1501,     7,  1501,    -1,  1501,   606,  1439,  1438,    -1,  1501,
     424,  1439,  1438,    -1,  1501,   723,  1439,  1438,    -1,  1501,
     425,  1439,  1438,    -1,  1501,  1444,    10,  1439,  1438,    -1,
      14,    -1,    17,    -1,    12,    -1,    13,    -1,   304,    -1,
      10,    -1,   722,    -1,    16,    -1,    15,    -1,  1445,    -1,
    1441,    -1,  1437,    -1,    -1,   635,    -1,   412,    -1,   526,
      -1,  1450,    -1,  1451,    -1,  1453,    -1,   371,    -1,   371,
     481,  1454,   444,    -1,    -1,   522,    -1,   522,   481,    26,
     444,    -1,   449,    -1,   449,   481,  1455,  1452,   444,    -1,
     562,   481,  1455,  1452,   444,    -1,   562,    -1,   587,    -1,
     459,    -1,   433,    -1,   372,    -1,   372,   481,  1454,   444,
      -1,   373,    -1,   373,   481,    26,   444,    -1,   373,   481,
      26,     5,    26,   444,    -1,   410,  1471,   675,  1472,    -1,
     410,    -1,   422,  1471,   675,  1472,    -1,   422,    -1,   422,
    1471,   481,    26,   444,   675,  1472,    -1,   624,    -1,   583,
      -1,   474,    -1,   474,   481,    26,   444,    -1,   474,   481,
      26,     5,    26,   444,    -1,    -1,     5,  1456,    -1,   552,
     481,  1455,   444,    -1,   615,    -1,   351,    -1,   552,    -1,
     115,    -1,    26,    -1,    26,    -1,    26,    -1,    25,   669,
    1005,    -1,    25,    -1,  1005,    -1,  1005,   639,  1005,    -1,
    1005,   639,    25,   669,  1005,    -1,  1005,   661,  1005,    -1,
    1005,   661,  1005,   639,  1005,    -1,  1005,   661,  1005,   639,
      25,   669,  1005,    -1,    25,   669,  1005,    -1,    25,    -1,
    1005,    -1,  1005,   639,  1005,    -1,  1005,   639,    25,   669,
    1005,    -1,  1005,   661,  1005,    -1,  1005,   661,  1005,   639,
    1005,    -1,  1005,   661,  1005,   639,    25,   669,  1005,    -1,
    1005,    -1,    -1,   509,    26,   477,    -1,   509,    26,     5,
      26,   477,    -1,  1462,    -1,   661,  1462,    -1,  1005,  1460,
      -1,  1457,   669,  1005,  1460,    -1,  1457,   669,    20,    -1,
    1005,    -1,    25,    -1,  1011,    -1,    26,    -1,  1466,    -1,
     447,  1468,    -1,   447,  1467,    -1,    -1,  1471,   675,  1472,
      -1,    -1,  1469,   675,  1469,    -1,   631,    -1,   563,    -1,
     640,    -1,   602,    -1,   504,    -1,   520,    -1,   419,    -1,
     419,   481,    26,   444,    -1,   631,    -1,   563,    -1,   640,
      -1,   602,    -1,   504,    -1,   520,    -1,   419,    -1,   419,
     481,    26,   444,    -1,   631,    -1,   563,    -1,   640,    -1,
     602,    -1,   504,    -1,   520,    -1,   419,    -1,   631,    -1,
     563,    -1,   640,    -1,   602,    -1,   504,    -1,   520,    -1,
     419,    -1,   419,   481,    26,   444,    -1,  1005,    -1,  1005,
     661,  1005,    -1,    25,    -1,  1514,   553,   999,    -1,    -1,
    1514,   450,  1363,   487,   645,  1483,  1476,    -1,    -1,  1514,
     450,  1363,   487,   151,   645,  1484,  1477,    -1,    -1,  1514,
     450,  1363,   190,  1484,  1478,    -1,    -1,  1514,   450,  1363,
     191,   151,   645,  1484,  1479,    -1,    -1,   340,    -1,   339,
    1481,    -1,  1482,    -1,  1481,     5,  1482,    -1,  1005,    -1,
    1005,   669,  1005,    -1,    25,   669,  1005,   669,  1005,    -1,
    1484,    -1,  1353,    -1,  1217,    -1,  1486,    -1,  1486,    -1,
      -1,    -1,   521,  1497,  1487,  1498,  1488,  1494,  1429,  1492,
    1480,    -1,   521,  1497,  1498,  1429,  1492,    -1,  1491,    -1,
    1509,    -1,   521,  1497,  1498,  1494,  1429,  1492,    -1,    -1,
     575,  1448,  1490,    -1,  1372,    -1,   385,  1493,  1322,    -1,
    1372,   385,  1493,  1322,    -1,  1005,    -1,    -1,   603,  1183,
      -1,   521,  1497,  1498,  1429,    -1,   481,   521,  1497,  1498,
    1429,   444,    -1,    -1,   635,    -1,   412,    -1,   526,    -1,
    1499,    -1,  1498,     5,  1499,    -1,  1501,    -1,  1501,  1005,
      -1,  1501,   666,  1005,    -1,  1501,    -1,  1502,    -1,    19,
    1502,    -1,    18,  1502,    -1,  1503,    -1,  1563,    -1,  1496,
      -1,   635,  1496,    -1,   636,  1496,    -1,   620,  1496,    -1,
     661,  1005,    -1,   661,  1005,   669,  1005,    -1,  1502,    21,
    1501,    -1,  1502,  1523,    -1,  1502,    20,  1501,    -1,  1502,
      18,  1501,    -1,  1502,    19,  1501,    -1,  1464,    -1,   534,
      -1,   478,    -1,   626,    -1,    20,    -1,   116,    -1,   638,
     481,  1448,  1501,   444,    -1,   650,   481,  1448,  1501,   444,
      -1,   651,   481,  1448,  1501,   444,    -1,   658,   481,  1448,
    1501,   444,    -1,   546,   481,  1448,  1501,   444,    -1,  1005,
     481,  1504,   444,    -1,   587,   481,  1504,   444,    -1,   481,
    1501,   444,    -1,   494,   481,  1524,   444,    -1,  1525,    -1,
    1527,    -1,  1501,    -1,  1504,     5,  1501,    -1,  1464,    -1,
    1514,   400,  1513,  1508,  1490,    -1,  1514,   389,  1513,  1508,
     300,  1457,  1510,    -1,  1514,   389,  1513,  1508,  1162,    -1,
      -1,   375,  1509,    -1,    25,    -1,  1162,    -1,    -1,   481,
    1511,   444,    -1,  1512,    -1,  1511,     5,  1512,    -1,  1005,
      -1,    25,    -1,  1162,    -1,    -1,   319,  1515,   645,    -1,
    1006,    -1,  1521,    -1,  1520,    -1,  1517,    -1,   368,  1518,
     675,  1518,    -1,   349,  1457,   669,  1519,   675,  1519,    -1,
    1005,    -1,  1005,    -1,   273,  1457,    -1,   344,  1457,  1522,
      -1,   323,    -1,   226,    -1,   143,    -1,   144,    -1,   145,
      -1,   146,    -1,   147,    -1,   148,    -1,   447,     5,  1471,
     675,  1472,    -1,  1563,     5,  1471,   675,  1472,    -1,   447,
    1471,   675,  1472,    -1,  1501,     5,  1471,   675,  1472,    -1,
    1526,    -1,  1526,  1471,   675,  1472,    -1,    36,    -1,  1528,
      -1,  1528,  1471,   481,    26,   444,   675,  1472,    -1,  1528,
    1471,   675,  1472,    -1,    37,    -1,    -1,   657,  1530,  1531,
     241,    -1,  1532,    -1,  1531,  1532,    -1,    33,    -1,  1533,
      -1,  1535,    -1,   404,    -1,   356,    -1,   275,    -1,   634,
      -1,   531,    -1,   635,    -1,   536,    -1,   580,    -1,   636,
      -1,   167,    -1,   537,    -1,   666,    -1,   637,    -1,   369,
      -1,   538,    -1,   370,    -1,   667,    -1,   661,    -1,   326,
      -1,   539,    -1,   235,    -1,   440,    -1,   638,    -1,   713,
      -1,   441,    -1,   540,    -1,   541,    -1,   581,    -1,   582,
      -1,   482,    -1,   483,    -1,   406,    -1,   700,    -1,   668,
      -1,   583,    -1,   442,    -1,   585,    -1,   579,    -1,   371,
      -1,   542,    -1,   543,    -1,   443,    -1,   544,    -1,   444,
      -1,   477,    -1,   545,    -1,   639,    -1,   484,    -1,   445,
      -1,     5,    -1,    23,    -1,   485,    -1,   446,    -1,   408,
      -1,   407,    -1,   374,    -1,   546,    -1,   486,    -1,   447,
      -1,   487,    -1,   586,    -1,   409,    -1,   587,    -1,   410,
      -1,   640,    -1,   641,    -1,   448,    -1,   642,    -1,   449,
      -1,   450,    -1,   451,    -1,   411,    -1,   547,    -1,   488,
      -1,   489,    -1,   375,    -1,   588,    -1,   332,    -1,   643,
      -1,   704,    -1,   452,    -1,   412,    -1,    21,    -1,   669,
      -1,   490,    -1,   376,    -1,   591,    -1,   114,    -1,   592,
      -1,   707,    -1,   453,    -1,    14,    -1,   548,    -1,   492,
      -1,   549,    -1,   380,    -1,   593,    -1,   454,    -1,   493,
      -1,   594,    -1,   494,    -1,   495,    -1,   418,    -1,   584,
      -1,   550,    -1,   150,    -1,   244,    -1,   496,    -1,   551,
      -1,   644,    -1,   552,    -1,   553,    -1,   645,    -1,   455,
      -1,   456,    -1,   497,    -1,   687,    -1,   142,    -1,   157,
      -1,   554,    -1,   419,    -1,   595,    -1,   596,    -1,   420,
      -1,   341,    -1,   457,    -1,   670,    -1,   597,    -1,   555,
      -1,    13,    -1,   556,    -1,   557,    -1,   498,    -1,   499,
      -1,   600,    -1,   601,    -1,   602,    -1,   709,    -1,   123,
      -1,   671,    -1,   672,    -1,   163,    -1,   558,    -1,   458,
      -1,   342,    -1,   714,    -1,   500,    -1,   459,    -1,   384,
      -1,   422,    -1,   716,    -1,   386,    -1,   646,    -1,   589,
      -1,   708,    -1,   559,    -1,   532,    -1,   423,    -1,   647,
      -1,   676,    -1,   460,    -1,     7,    -1,   478,    -1,   632,
      -1,   533,    -1,     6,    -1,   534,    -1,     8,    -1,   604,
      -1,   605,    -1,    12,    -1,   648,    -1,   606,    -1,   561,
      -1,   501,    -1,   649,    -1,   461,    -1,   607,    -1,   502,
      -1,    10,    -1,    57,    -1,   503,    -1,   608,    -1,   695,
      -1,   710,    -1,    19,    -1,   504,    -1,   162,    -1,    22,
      -1,   609,    -1,   505,    -1,   562,    -1,   563,    -1,    20,
      -1,   610,    -1,   611,    -1,   362,    -1,   612,    -1,   506,
      -1,     9,    -1,   673,    -1,   718,    -1,   674,    -1,   613,
      -1,   481,    -1,   509,    -1,   510,    -1,   462,    -1,   564,
      -1,   393,    -1,   565,    -1,   511,    -1,   652,    -1,   427,
      -1,   566,    -1,   207,    -1,   158,    -1,   463,    -1,    18,
      -1,   161,    -1,   394,    -1,   464,    -1,   164,    -1,   428,
      -1,   363,    -1,   569,    -1,   395,    -1,   396,    -1,   465,
      -1,   512,    -1,   513,    -1,   653,    -1,   614,    -1,   429,
      -1,   615,    -1,   514,    -1,   466,    -1,   654,    -1,   348,
      -1,   430,    -1,   431,    -1,   515,    -1,   432,    -1,   229,
      -1,   398,    -1,   467,    -1,   516,    -1,   570,    -1,   313,
      -1,   655,    -1,   616,    -1,   656,    -1,   517,    -1,   519,
      -1,   520,    -1,   468,    -1,   521,    -1,   572,    -1,   522,
      -1,   469,    -1,   524,    -1,   617,    -1,   535,    -1,   618,
      -1,   619,    -1,   573,    -1,   351,    -1,   433,    -1,   620,
      -1,   525,    -1,   657,    -1,   352,    -1,   141,    -1,   621,
      -1,   622,    -1,   658,    -1,   470,    -1,   590,    -1,   623,
      -1,   168,    -1,   624,    -1,   625,    -1,   471,    -1,   717,
      -1,   675,    -1,   659,    -1,   472,    -1,   574,    -1,   249,
      -1,   399,    -1,   575,    -1,   526,    -1,   527,    -1,   528,
      -1,   473,    -1,   660,    -1,   626,    -1,   434,    -1,   529,
      -1,   474,    -1,   403,    -1,   627,    -1,   475,    -1,   628,
      -1,   576,    -1,   577,    -1,   578,    -1,   629,    -1,   436,
      -1,   630,    -1,   650,    -1,   651,    -1,   633,    -1,   631,
      -1,   530,    -1,    -1,   242,  1534,  1563,    -1,    -1,   603,
    1536,  1183,    -1,    -1,    -1,   528,  1457,  1538,  1541,  1539,
    1540,    -1,    -1,   202,   999,    -1,   576,  1433,    -1,   101,
    1545,   444,    14,   481,  1546,   444,    -1,    97,  1546,   444,
      -1,    98,  1546,   444,    -1,   633,  1542,    -1,   100,  1546,
      -1,    99,  1546,    -1,  1544,    -1,  1542,     5,  1544,    -1,
    1461,    -1,  1543,    14,  1547,    -1,  1543,    -1,  1545,     5,
    1543,    -1,  1547,    -1,  1546,     5,  1547,    -1,   533,    -1,
    1548,    -1,  1549,    -1,    19,  1549,    -1,    18,  1549,    -1,
    1551,    -1,  1496,    -1,   661,  1005,    -1,   661,  1005,   669,
    1005,    -1,   661,  1005,   509,    26,   477,    -1,   661,  1005,
     669,  1005,   509,    26,   477,    -1,   661,  1005,   509,    26,
       5,    26,   477,    -1,   661,  1005,   669,  1005,   509,    26,
       5,    26,   477,    -1,  1550,    -1,  1464,    -1,   534,    -1,
     478,    -1,   626,    -1,   116,    -1,  1549,    21,  1548,    -1,
    1549,  1523,    -1,  1549,    20,  1548,    -1,  1549,    18,  1548,
      -1,  1549,    19,  1548,    -1,   638,   481,  1448,  1548,   444,
      -1,   650,   481,  1448,  1548,   444,    -1,   651,   481,  1448,
    1548,   444,    -1,   658,   481,  1448,  1548,   444,    -1,   546,
     481,  1448,  1548,   444,    -1,  1005,   481,  1552,   444,    -1,
     587,   481,  1552,   444,    -1,   481,  1548,   444,    -1,   494,
     481,  1524,   444,    -1,  1525,    -1,  1527,    -1,  1563,    -1,
    1548,    -1,  1552,     5,  1548,    -1,    -1,   434,  1191,   606,
    1554,  1555,    -1,  1556,    -1,  1555,     5,  1556,    -1,  1457,
     669,  1461,    -1,  1457,   669,    20,    -1,  1559,    -1,  1559,
      -1,   242,  1560,    -1,  1560,    -1,  1561,    -1,    25,   669,
    1561,    -1,  1562,    -1,  1561,   669,  1562,    -1,  1561,   669,
      20,    -1,  1564,    -1,  1005,    -1,  1558,    -1,  1558,   471,
    1558,    -1,  1005,  1565,    -1,   509,  1566,   477,    -1,   509,
    1566,   477,   509,  1566,   477,    -1,  1567,    -1,  1566,     5,
    1567,    -1,   735,    -1,    34,    -1,    -1,    -1,   577,  1570,
     912,  1571,  1584,   379,    -1,    -1,   708,   953,    -1,    -1,
     711,    -1,   233,    -1,   329,  1000,    -1,   121,  1000,    -1,
     359,    -1,   358,    -1,   360,  1002,  1572,  1573,    -1,   543,
     953,  1573,    -1,   155,    -1,   187,  1000,    -1,   912,   616,
       5,   912,   445,    -1,   559,   912,    -1,   316,  1000,    -1,
     152,  1579,     8,  1580,  1578,    -1,    -1,   596,   912,    -1,
    1005,    -1,  1005,    -1,   299,  1000,    -1,   302,  1000,   675,
     912,     5,   912,    -1,   302,  1000,   668,   912,     5,   912,
      -1,    27,    -1,    -1,  1586,    -1,  1587,  1269,    -1,  1585,
      -1,  1586,  1585,    -1,    -1,  1588,  1589,    -1,   728,    -1,
     729,    -1,   730,    -1,   731,    -1,   748,    -1,   770,    -1,
     784,    -1,   785,    -1,   791,    -1,   810,    -1,   884,    -1,
     885,    -1,   886,    -1,   887,    -1,   898,    -1,   899,    -1,
     900,    -1,   901,    -1,   902,    -1,   903,    -1,   904,    -1,
     955,    -1,   959,    -1,   990,    -1,  1012,    -1,  1014,    -1,
    1017,    -1,  1018,    -1,  1019,    -1,  1020,    -1,  1033,    -1,
    1042,    -1,  1066,    -1,  1067,    -1,  1069,    -1,  1073,    -1,
    1088,    -1,  1089,    -1,  1093,    -1,  1094,    -1,  1095,    -1,
    1096,    -1,  1104,    -1,  1119,    -1,  1132,    -1,  1143,    -1,
    1144,    -1,  1145,    -1,  1156,    -1,  1193,    -1,  1196,    -1,
    1198,    -1,  1204,    -1,  1205,    -1,  1208,    -1,  1211,    -1,
    1214,    -1,  1216,    -1,  1218,    -1,  1221,    -1,  1228,    -1,
    1233,    -1,  1238,    -1,  1239,    -1,  1240,    -1,  1252,    -1,
    1305,    -1,  1306,    -1,  1308,    -1,  1327,    -1,  1328,    -1,
    1348,    -1,  1351,    -1,  1380,    -1,  1382,    -1,  1474,    -1,
    1475,    -1,  1506,    -1,  1507,    -1,  1529,    -1,  1553,    -1,
    1568,    -1,  1569,    -1,  1574,    -1,  1575,    -1,  1577,    -1,
    1581,    -1,  1582,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const unsigned short yyrline[] =
{
       0,   999,   999,  1002,  1005,  1011,  1017,  1024,  1028,  1028,
    1034,  1057,  1058,  1059,  1060,  1061,  1072,  1078,  1079,  1080,
    1081,  1082,  1087,  1088,  1099,  1102,  1105,  1105,  1109,  1112,
    1113,  1119,  1120,  1121,  1122,  1123,  1124,  1125,  1126,  1127,
    1128,  1129,  1130,  1131,  1132,  1133,  1134,  1135,  1138,  1139,
    1142,  1142,  1157,  1158,  1161,  1167,  1169,  1180,  1182,  1184,
    1186,  1190,  1192,  1254,  1258,  1262,  1262,  1272,  1276,  1279,
    1280,  1287,  1293,  1287,  1306,  1311,  1315,  1306,  1327,  1331,
    1327,  1339,  1344,  1339,  1363,  1370,  1374,  1362,  1400,  1400,
    1404,  1405,  1406,  1411,  1414,  1419,  1423,  1431,  1432,  1435,
    1435,  1441,  1445,  1460,  1458,  1476,  1476,  1491,  1491,  1494,
    1494,  1498,  1501,  1501,  1501,  1508,  1509,  1508,  1516,  1516,
    1527,  1527,  1546,  1549,  1552,  1555,  1558,  1561,  1574,  1579,
    1579,  1580,  1580,  1583,  1588,  1588,  1592,  1611,  1616,  1610,
    1627,  1633,  1641,  1642,  1645,  1645,  1648,  1652,  1657,  1664,
    1664,  1668,  1668,  1669,  1669,  1670,  1670,  1671,  1671,  1672,
    1672,  1680,  1684,  1690,  1694,  1709,  1712,  1715,  1718,  1721,
    1724,  1730,  1741,  1746,  1759,  1763,  1778,  1779,  1783,  1783,
    1787,  1787,  1787,  1788,  1793,  1793,  1796,  1796,  1805,  1806,
    1807,  1810,  1814,  1815,  1815,  1832,  1832,  1832,  1832,  1836,
    1843,  1844,  1847,  1847,  1851,  1852,  1853,  1854,  1859,  1859,
    1865,  1865,  1874,  1871,  1887,  1887,  1889,  1889,  1891,  1893,
    1895,  1897,  1900,  1904,  1904,  1905,  1905,  1909,  1909,  1921,
    1921,  1926,  1930,  1932,  1933,  1936,  1936,  1936,  1940,  1941,
    1942,  1943,  1944,  1945,  1946,  1947,  1948,  1949,  1950,  1951,
    1954,  1955,  1956,  1957,  1961,  1966,  1971,  1975,  1978,  1982,
    1982,  1983,  1983,  1984,  1984,  1985,  1986,  1987,  1988,  1989,
    1990,  1993,  1994,  1995,  2025,  2025,  2030,  2034,  2036,  2038,
    2038,  2045,  2049,  2049,  2053,  2054,  2055,  2056,  2057,  2058,
    2059,  2065,  2065,  2068,  2070,  2076,  2078,  2084,  2092,  2092,
    2095,  2096,  2097,  2098,  2099,  2100,  2101,  2107,  2110,  2110,
    2123,  2123,  2130,  2131,  2132,  2134,  2135,  2138,  2142,  2143,
    2144,  2145,  2150,  2156,  2162,  2163,  2165,  2167,  2168,  2169,
    2170,  2171,  2172,  2175,  2176,  2183,  2191,  2191,  2199,  2196,
    2211,  2211,  2213,  2213,  2221,  2221,  2224,  2227,  2228,  2233,
    2245,  2249,  2252,  2255,  2256,  2257,  2258,  2259,  2264,  2271,
    2277,  2282,  2287,  2282,  2300,  2302,  2307,  2312,  2312,  2312,
    2316,  2316,  2319,  2319,  2326,  2326,  2333,  2333,  2344,  2362,
    2368,  2392,  2395,  2409,  2411,  2413,  2415,  2417,  2419,  2421,
    2427,  2429,  2433,  2435,  2437,  2439,  2441,  2443,  2445,  2451,
    2466,  2469,  2485,  2486,  2487,  2488,  2492,  2493,  2494,  2498,
    2503,  2510,  2511,  2512,  2513,  2514,  2515,  2516,  2517,  2518,
    2519,  2520,  2527,  2527,  2532,  2532,  2535,  2541,  2549,  2555,
    2565,  2566,  2574,  2595,  2599,  2604,  2609,  2611,  2614,  2632,
    2637,  2643,  2648,  2653,  2654,  2660,  2731,  2742,  2751,  2759,
    2759,  2774,  2778,  2785,  2788,  2796,  2800,  2803,  2809,  2818,
    2823,  2831,  2834,  2837,  2842,  2849,  2854,  2859,  2864,  2874,
    2882,  2890,  2895,  2899,  2904,  2908,  2912,  2919,  2922,  2925,
    2929,  2933,  2937,  2941,  2949,  2959,  2964,  2957,  2980,  2985,
    2980,  3002,  3002,  3002,  3005,  3005,  3005,  3009,  3009,  3009,
    3013,  3013,  3013,  3017,  3023,  3029,  3035,  3043,  3049,  3057,
    3063,  3072,  3078,  3085,  3092,  3101,  3107,  3113,  3120,  3126,
    3132,  3138,  3146,  3152,  3158,  3170,  3176,  3186,  3186,  3190,
    3194,  3195,  3206,  3207,  3213,  3223,  3233,  3243,  3244,  3247,
    3252,  3258,  3262,  3266,  3269,  3275,  3278,  3281,  3298,  3301,
    3307,  3308,  3309,  3313,  3314,  3315,  3316,  3317,  3319,  3320,
    3321,  3323,  3324,  3328,  3329,  3334,  3338,  3343,  3347,  3362,
    3366,  3361,  3374,  3377,  3391,  3395,  3401,  3390,  3414,  3415,
    3427,  3433,  3427,  3447,  3447,  3449,  3450,  3454,  3454,  3458,
    3458,  3463,  3463,  3470,  3471,  3475,  3475,  3479,  3479,  3484,
    3484,  3491,  3495,  3496,  3497,  3502,  3502,  3505,  3505,  3509,
    3509,  3513,  3513,  3517,  3517,  3522,  3522,  3527,  3527,  3532,
    3532,  3537,  3537,  3553,  3570,  3571,  3572,  3573,  3574,  3575,
    3576,  3579,  3579,  3582,  3584,  3587,  3590,  3593,  3598,  3603,
    3606,  3611,  3616,  3621,  3628,  3629,  3636,  3643,  3645,  3651,
    3656,  3661,  3666,  3666,  3669,  3675,  3680,  3683,  3690,  3690,
    3692,  3695,  3698,  3703,  3708,  3713,  3720,  3729,  3729,  3791,
    3799,  3800,  3808,  3815,  3815,  3819,  3824,  3830,  3834,  3838,
    3844,  3848,  3852,  3858,  3858,  3866,  3867,  3871,  3871,  3875,
    3876,  3879,  3882,  3882,  3885,  3887,  3887,  3890,  3892,  3892,
    3893,  3895,  3895,  3904,  3911,  3902,  3932,  3932,  3932,  3935,
    3937,  3935,  3944,  3947,  3953,  3964,  3964,  3968,  3974,  3974,
    3978,  3979,  3983,  3993,  3994,  3995,  3998,  4000,  4005,  4005,
    4009,  4008,  4016,  4015,  4022,  4022,  4028,  4028,  4035,  4035,
    4041,  4041,  4047,  4047,  4053,  4053,  4057,  4057,  4058,  4058,
    4059,  4059,  4060,  4060,  4064,  4064,  4075,  4079,  4085,  4089,
    4094,  4099,  4104,  4105,  4106,  4110,  4109,  4122,  4127,  4132,
    4132,  4148,  4154,  4155,  4156,  4157,  4158,  4168,  4182,  4182,
    4185,  4192,  4193,  4194,  4195,  4196,  4197,  4198,  4199,  4200,
    4205,  4205,  4207,  4210,  4210,  4212,  4216,  4219,  4220,  4223,
    4223,  4228,  4231,  4232,  4233,  4234,  4235,  4236,  4237,  4238,
    4239,  4240,  4241,  4242,  4243,  4244,  4245,  4246,  4247,  4248,
    4252,  4270,  4270,  4270,  4297,  4308,  4315,  4321,  4327,  4333,
    4345,  4370,  4369,  4386,  4386,  4390,  4391,  4399,  4400,  4401,
    4402,  4403,  4404,  4411,  4412,  4414,  4415,  4419,  4424,  4425,
    4426,  4427,  4428,  4429,  4430,  4431,  4432,  4434,  4437,  4439,
    4439,  4441,  4445,  4445,  4454,  4459,  4475,  4481,  4453,  4495,
    4509,  4519,  4508,  4532,  4539,  4539,  4544,  4550,  4558,  4563,
    4564,  4567,  4570,  4570,  4578,  4584,  4595,  4596,  4600,  4604,
    4617,  4599,  4635,  4635,  4649,  4660,  4659,  4671,  4667,  4684,
    4681,  4694,  4694,  4696,  4697,  4699,  4700,  4703,  4704,  4705,
    4707,  4712,  4717,  4723,  4725,  4726,  4729,  4730,  4733,  4735,
    4743,  4749,  4743,  4760,  4761,  4765,  4765,  4772,  4772,  4781,
    4784,  4787,  4790,  4794,  4798,  4799,  4800,  4801,  4802,  4806,
    4811,  4811,  4814,  4841,  4899,  4899,  4902,  4906,  4910,  4953,
    4995,  4996,  4997,  5000,  5014,  5026,  5026,  5031,  5032,  5038,
    5103,  5108,  5115,  5120,  5128,  5134,  5167,  5170,  5171,  5212,
    5255,  5256,  5260,  5261,  5265,  5318,  5323,  5327,  5332,  5343,
    5350,  5358,  5358,  5361,  5362,  5363,  5364,  5365,  5368,  5371,
    5377,  5380,  5384,  5389,  5397,  5402,  5409,  5411,  5417,  5419,
    5419,  5419,  5439,  5446,  5453,  5456,  5470,  5477,  5478,  5481,
    5482,  5486,  5492,  5497,  5503,  5504,  5509,  5513,  5513,  5517,
    5518,  5521,  5522,  5526,  5534,  5537,  5543,  5544,  5546,  5548,
    5552,  5552,  5553,  5558,  5566,  5567,  5572,  5573,  5575,  5588,
    5590,  5591,  5594,  5595,  5596,  5597,  5598,  5599,  5600,  5601,
    5602,  5603,  5604,  5605,  5606,  5607,  5608,  5609,  5610,  5611,
    5612,  5613,  5614,  5615,  5616,  5617,  5618,  5619,  5633,  5641,
    5641,  5643,  5647,  5651,  5655,  5659,  5664,  5679,  5677,  5697,
    5698,  5702,  5707,  5708,  5712,  5713,  5715,  5716,  5718,  5718,
    5727,  5736,  5736,  5746,  5747,  5752,  5753,  5756,  5769,  5783,
    5787,  5791,  5795,  5802,  5803,  5806,  5806,  5810,  5813,  5813,
    5815,  5821,  5829,  5835,  5837,  5841,  5844,  5844,  5847,  5847,
    5852,  5852,  5861,  5861,  5865,  5865,  5866,  5866,  5867,  5867,
    5881,  5881,  5901,  5902,  5903,  5904,  5905,  5906,  5909,  5909,
    5915,  5915,  5918,  5918,  5934,  5935,  5936,  5945,  5957,  5958,
    5961,  5962,  5965,  5968,  5968,  5973,  5973,  5994,  5999,  6005,
    6006,  6007,  6011,  6012,  6013,  6014,  6018,  6028,  6030,  6035,
    6038,  6043,  6049,  6056,  6063,  6072,  6079,  6086,  6093,  6100,
    6109,  6109,  6111,  6111,  6114,  6115,  6116,  6117,  6118,  6119,
    6120,  6121,  6122,  6123,  6126,  6126,  6129,  6130,  6131,  6132,
    6135,  6135,  6138,  6138,  6141,  6142,  6143,  6144,  6145,  6146,
    6147,  6148,  6150,  6151,  6152,  6153,  6155,  6156,  6157,  6158,
    6160,  6161,  6162,  6163,  6164,  6165,  6166,  6167,  6171,  6179,
    6189,  6202,  6211,  6222,  6226,  6230,  6236,  6201,  6249,  6252,
    6260,  6272,  6274,  6279,  6287,  6297,  6300,  6304,  6312,  6278,
    6321,  6325,  6329,  6333,  6325,  6343,  6344,  6345,  6346,  6351,
    6353,  6356,  6360,  6363,  6370,  6375,  6376,  6377,  6378,  6383,
    6384,  6390,  6390,  6390,  6395,  6395,  6395,  6403,  6404,  6408,
    6409,  6414,  6415,  6416,  6417,  6418,  6421,  6423,  6423,  6426,
    6427,  6431,  6432,  6435,  6436,  6439,  6442,  6445,  6451,  6452,
    6464,  6465,  6470,  6471,  6472,  6476,  6479,  6485,  6488,  6496,
    6497,  6503,  6507,  6511,  6517,  6520,  6529,  6532,  6535,  6538,
    6541,  6544,  6547,  6554,  6557,  6564,  6567,  6573,  6576,  6583,
    6586,  6593,  6594,  6599,  6603,  6606,  6612,  6615,  6621,  6628,
    6629,  6633,  6643,  6646,  6652,  6654,  6659,  6660,  6664,  6666,
    6672,  6673,  6686,  6698,  6699,  6700,  6701,  6702,  6703,  6704,
    6705,  6706,  6709,  6712,  6718,  6718,  6724,  6724,  6735,  6748,
    6758,  6758,  6763,  6763,  6767,  6771,  6772,  6778,  6779,  6784,
    6788,  6795,  6798,  6805,  6804,  6815,  6819,  6823,  6830,  6833,
    6833,  6846,  6850,  6850,  6865,  6867,  6869,  6871,  6873,  6875,
    6877,  6879,  6885,  6895,  6902,  6907,  6908,  6912,  6915,  6916,
    6919,  6920,  6921,  6924,  6929,  6936,  6937,  6943,  6955,  6956,
    6957,  6960,  6960,  6965,  6970,  6975,  6976,  6979,  6980,  6985,
    6990,  6994,  6999,  7000,  7004,  7011,  7012,  7013,  7014,  7019,
    7020,  7021,  7024,  7025,  7026,  7030,  7031,  7032,  7036,  7037,
    7041,  7042,  7043,  7044,  7045,  7046,  7049,  7050,  7055,  7056,
    7061,  7062,  7067,  7068,  7073,  7078,  7079,  7084,  7085,  7089,
    7090,  7095,  7102,  7107,  7112,  7116,  7117,  7122,  7123,  7129,
    7130,  7131,  7136,  7137,  7143,  7146,  7149,  7156,  7157,  7158,
    7159,  7173,  7178,  7179,  7182,  7184,  7191,  7194,  7200,  7208,
    7212,  7216,  7220,  7224,  7227,  7230,  7237,  7244,  7249,  7253,
    7254,  7260,  7263,  7274,  7281,  7287,  7290,  7297,  7304,  7310,
    7311,  7317,  7318,  7319,  7322,  7323,  7328,  7328,  7332,  7340,
    7341,  7344,  7347,  7352,  7353,  7358,  7361,  7367,  7370,  7376,
    7379,  7385,  7388,  7395,  7396,  7425,  7426,  7431,  7439,  7444,
    7447,  7450,  7453,  7459,  7460,  7464,  7467,  7470,  7471,  7476,
    7479,  7482,  7485,  7488,  7491,  7494,  7497,  7502,  7508,  7509,
    7510,  7511,  7512,  7514,  7515,  7517,  7518,  7523,  7526,  7530,
    7536,  7537,  7538,  7539,  7551,  7552,  7553,  7557,  7558,  7562,
    7563,  7564,  7565,  7566,  7568,  7570,  7571,  7572,  7573,  7574,
    7575,  7576,  7577,  7579,  7581,  7583,  7584,  7586,  7587,  7589,
    7590,  7591,  7592,  7594,  7598,  7599,  7605,  7607,  7608,  7609,
    7610,  7615,  7619,  7623,  7627,  7634,  7638,  7639,  7640,  7648,
    7649,  7650,  7661,  7668,  7673,  7674,  7675,  7683,  7684,  7685,
    7702,  7711,  7712,  7713,  7717,  7720,  7725,  7730,  7735,  7743,
    7747,  7752,  7753,  7761,  7764,  7767,  7781,  7795,  7808,  7809,
    7813,  7813,  7813,  7813,  7813,  7813,  7814,  7817,  7822,  7822,
    7822,  7822,  7822,  7822,  7824,  7827,  7833,  7833,  7833,  7833,
    7833,  7833,  7833,  7834,  7834,  7834,  7834,  7834,  7834,  7834,
    7834,  7837,  7838,  7839,  7842,  7851,  7851,  7857,  7857,  7864,
    7864,  7870,  7870,  7878,  7879,  7880,  7883,  7883,  7886,  7887,
    7888,  7899,  7902,  7908,  7913,  7920,  7933,  7934,  7931,  7952,
    7963,  7966,  7971,  7983,  7986,  7990,  7993,  7994,  8004,  8007,
    8008,  8017,  8026,  8031,  8032,  8033,  8034,  8041,  8044,  8050,
    8053,  8060,  8072,  8081,  8084,  8087,  8093,  8099,  8102,  8103,
    8104,  8105,  8106,  8109,  8115,  8117,  8119,  8121,  8123,  8125,
    8126,  8127,  8128,  8129,  8130,  8131,  8133,  8135,  8137,  8139,
    8141,  8143,  8145,  8146,  8148,  8149,  8155,  8156,  8163,  8166,
    8174,  8178,  8185,  8185,  8189,  8189,  8194,  8194,  8198,  8198,
    8202,  8208,  8208,  8211,  8211,  8217,  8224,  8225,  8226,  8230,
    8231,  8234,  8235,  8239,  8245,  8255,  8256,  8264,  8265,  8266,
    8267,  8268,  8269,  8273,  8274,  8275,  8276,  8280,  8281,  8285,
    8301,  8302,  8303,  8307,  8321,  8321,  8333,  8334,  8338,  8339,
    8340,  8341,  8342,  8343,  8344,  8345,  8346,  8347,  8348,  8349,
    8350,  8351,  8352,  8353,  8354,  8355,  8356,  8357,  8358,  8359,
    8360,  8361,  8362,  8363,  8364,  8365,  8366,  8367,  8368,  8369,
    8370,  8371,  8372,  8373,  8374,  8375,  8376,  8377,  8378,  8379,
    8380,  8381,  8382,  8383,  8384,  8385,  8386,  8387,  8388,  8389,
    8390,  8391,  8392,  8393,  8394,  8395,  8396,  8397,  8398,  8399,
    8400,  8401,  8402,  8403,  8404,  8405,  8406,  8407,  8408,  8409,
    8410,  8411,  8412,  8413,  8414,  8415,  8416,  8417,  8418,  8419,
    8420,  8421,  8422,  8423,  8424,  8425,  8426,  8427,  8428,  8429,
    8430,  8431,  8432,  8433,  8434,  8435,  8436,  8437,  8438,  8439,
    8440,  8441,  8442,  8443,  8444,  8445,  8446,  8447,  8448,  8449,
    8450,  8451,  8452,  8453,  8454,  8455,  8456,  8457,  8458,  8459,
    8460,  8461,  8462,  8463,  8464,  8465,  8466,  8467,  8468,  8469,
    8470,  8471,  8472,  8473,  8474,  8475,  8476,  8477,  8478,  8479,
    8480,  8481,  8482,  8483,  8484,  8485,  8486,  8487,  8488,  8489,
    8490,  8491,  8492,  8493,  8494,  8495,  8496,  8497,  8498,  8499,
    8500,  8501,  8502,  8503,  8504,  8505,  8506,  8507,  8508,  8509,
    8510,  8511,  8512,  8513,  8514,  8515,  8516,  8517,  8518,  8519,
    8520,  8521,  8522,  8523,  8524,  8525,  8526,  8527,  8528,  8529,
    8530,  8531,  8532,  8533,  8534,  8535,  8536,  8537,  8538,  8539,
    8540,  8542,  8543,  8544,  8545,  8546,  8547,  8548,  8549,  8550,
    8551,  8552,  8553,  8554,  8555,  8556,  8557,  8558,  8559,  8560,
    8561,  8562,  8563,  8564,  8565,  8566,  8567,  8568,  8569,  8570,
    8571,  8572,  8573,  8574,  8575,  8576,  8577,  8578,  8579,  8580,
    8581,  8582,  8583,  8584,  8585,  8586,  8587,  8588,  8589,  8590,
    8591,  8592,  8593,  8594,  8595,  8596,  8597,  8598,  8599,  8600,
    8601,  8602,  8603,  8604,  8605,  8606,  8607,  8608,  8609,  8610,
    8611,  8612,  8613,  8614,  8615,  8616,  8617,  8618,  8619,  8620,
    8621,  8622,  8623,  8624,  8625,  8626,  8627,  8628,  8629,  8630,
    8631,  8632,  8633,  8634,  8635,  8636,  8637,  8638,  8639,  8640,
    8641,  8642,  8643,  8644,  8645,  8646,  8647,  8648,  8649,  8650,
    8651,  8652,  8653,  8654,  8655,  8656,  8664,  8664,  8671,  8671,
    8759,  8763,  8759,  8772,  8776,  8782,  8790,  8800,  8810,  8822,
    8825,  8844,  8870,  8873,  8879,  8882,  8887,  8890,  8898,  8906,
    8919,  8922,  8930,  8933,  8936,  8944,  8948,  8949,  8950,  8951,
    8952,  8953,  8954,  8955,  8959,  8960,  8961,  8962,  8963,  8969,
    8970,  8971,  8972,  8973,  8974,  8975,  8976,  8977,  8978,  8979,
    8980,  8981,  8982,  8983,  8984,  8989,  8995,  8996,  9004,  9004,
    9012,  9012,  9016,  9020,  9035,  9050,  9056,  9058,  9066,  9067,
    9071,  9072,  9075,  9082,  9085,  9114,  9140,  9194,  9230,  9239,
    9250,  9253,  9258,  9272,  9286,  9289,  9285,  9308,  9308,  9314,
    9315,  9318,  9319,  9320,  9321,  9322,  9323,  9324,  9335,  9338,
    9343,  9347,  9352,  9356,  9361,  9365,  9368,  9372,  9375,  9380,
    9384,  9395,  9401,  9401,  9402,  9403,  9410,  9420,  9420,  9422,
    9423,  9424,  9425,  9426,  9427,  9428,  9429,  9430,  9431,  9432,
    9433,  9434,  9435,  9436,  9437,  9438,  9439,  9440,  9441,  9442,
    9443,  9444,  9445,  9446,  9447,  9448,  9449,  9450,  9451,  9452,
    9453,  9454,  9455,  9456,  9457,  9458,  9459,  9460,  9461,  9462,
    9463,  9464,  9465,  9466,  9467,  9468,  9469,  9470,  9471,  9472,
    9473,  9474,  9475,  9476,  9477,  9478,  9479,  9480,  9481,  9482,
    9483,  9484,  9485,  9486,  9487,  9488,  9489,  9490,  9491,  9492,
    9493,  9494,  9495,  9496,  9497,  9498,  9499,  9500,  9501,  9502,
    9503,  9504,  9505,  9506,  9507,  9508,  9509
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
  "KW_CEND", "USER_DTYPE", "SQL_TEXT", "KW_WHENEVER_SET", "COMMENT", 
  "DATETIME_VALUE", "INTERVAL_VALUE", "DYNAMIC_ARRAY", "RESIZE_ARRAY", 
  "ALLOCATE_ARRAY", "DEALLOCATE_ARRAY", "AFTER_INSERT_DELETE", 
  "BEFORE_INSERT_DELETE", "BEFORE_INSERT", "AS_CONVERTABLE", 
  "CONCAT_PIPES", "BEFORE_DELETE", "DROP_TRIGGER", "AFTER_INSERT", 
  "AFTER_DELETE", "EXECUTE_IMMEDIATE", "DELETE_ROW_EQUAL_TRUE", 
  "INSERT_ROW_EQUAL_TRUE", "DELETE_ROW_EQUAL_FALSE", 
  "INSERT_ROW_EQUAL_FALSE", "CURRENT_ROW_DISPLAY_EQUAL", "MAXCOUNT", 
  "ALTER_TABLE", "ALTER_INDEX", "NEXT_SIZE", "DISPLAY_ATTR_FORM", 
  "DISPLAY_ATTR_WINDOW", "INPUT_ATTR_FORM", "INPUT_ATTR_WINDOW", 
  "WHENEVER_ERROR_CONTINUE", "WHENEVER_ANY_ERROR_CONTINUE", 
  "WHENEVER_WARNING_CONTINUE", "WHENEVER_SQLSUCCESS_CONTINUE", 
  "WHENEVER_SQLWARNING_CONTINUE", "WHENEVER_NOT_FOUND_CONTINUE", 
  "WHENEVER_SQLERROR_CONTINUE", "WHENEVER_SUCCESS_CONTINUE", 
  "WHENEVER_ERROR_GOTO", "WHENEVER_ANY_ERROR_GOTO", 
  "WHENEVER_WARNING_GOTO", "WHENEVER_SQLSUCCESS_GOTO", 
  "WHENEVER_SQLWARNING_GOTO", "WHENEVER_NOT_FOUND_GOTO", 
  "WHENEVER_SQLERROR_GOTO", "WHENEVER_SUCCESS_GOTO", 
  "WHENEVER_ERROR_CALL", "WHENEVER_ANY_ERROR_CALL", 
  "WHENEVER_WARNING_CALL", "WHENEVER_SQLSUCCESS_CALL", 
  "WHENEVER_SQLWARNING_CALL", "WHENEVER_NOT_FOUND_CALL", 
  "WHENEVER_SQLERROR_CALL", "WHENEVER_SUCCESS_CALL", 
  "WHENEVER_ERROR_STOP", "WHENEVER_ANY_ERROR_STOP", 
  "WHENEVER_WARNING_STOP", "WHENEVER_SQLSUCCESS_STOP", 
  "WHENEVER_SQLWARNING_STOP", "WHENEVER_NOT_FOUND_STOP", 
  "WHENEVER_SQLERROR_STOP", "WHENEVER_SUCCESS_STOP", 
  "XSET_MULTIPLY_EQUAL_OPEN_BRACKET", 
  "XSET_ident_DOT_MULTIPLY_EQUAL_OPEN_BRACKET", 
  "XSET_ident_DOT_MULTIPLY_EQUAL", "XSET_MULTIPLY_EQUAL", 
  "XSET_OPEN_BRACKET", "NEWFORMATSHARED", "CREATE_DATABASE", 
  "DROP_DATABASE", "IMPORT_LEGACY_FUNCTION", "ADD_CONSTRAINT", 
  "DROP_CONSTRAINT", "DROP_SYNONYM", "CONSTRAINT", "AS_STATIC", 
  "NOT_FIELD_TOUCHED", "LOCAL_FUNCTION", "EVERY_ROW", "ELIF", 
  "DOUBLE_PRECISION", "COUNT_MULTIPLY", "WAIT_FOR_KEY", 
  "AT_TERMINATION_CALL", "TERMINATE_REPORT", "TO_MAIN_CAPTION", 
  "CLEARSTAT", "TO_MENUITEM", "ID_TO_INT", "TO_STATUSBOX", 
  "ASCII_HEIGHT_ALL", "ASCII_WIDTH_ALL", "IMPORT_DATATYPE", 
  "PAGE_TRAILER_SIZE", "PAGE_HEADER_SIZE", "FIRST_PAGE_HEADER_SIZE", 
  "BYTES_USE_AS_IMAGE", "BYTES_USE_AS_ASCII", "KWUP_BY", "KWDOWN_BY", 
  "CLOSE_STATUSBOX", "MODIFY_NEXT_SIZE", "LOCK_MODE_PAGE", 
  "LOCK_MODE_ROW", "TO_PIPE", "TO_PRINTER", "STATUSBOX", 
  "FORMHANDLER_INPUT", "UNITS_YEAR", "UNITS_MONTH", "UNITS_DAY", 
  "UNITS_HOUR", "UNITS_MINUTE", "UNITS_SECOND", "NO_NEW_LINES", 
  "FIELDTOWIDGET", "WITH_HOLD", "SHOW_MENU", "TO_CLUSTER", 
  "TO_NOT_CLUSTER", "CWIS", "CREATE_IDX", "FORM_IS_COMPILED", 
  "PDF_REPORT", "IMPORT_FUNCTION", "PROMPT_MANY", "POINTS", "MM", 
  "INCHES", "PREPEND", "MEMBER_OF", "MEMBER_FUNCTION", "APPEND", 
  "TEMPLATE", "END_TEMPLATE", "SQLSICS", "CREATE_SCHEMA", "SQLSIRR", 
  "UPDATESTATS_T", "SQLSICR", "WHENEVER_SQLSUCCESS", 
  "WHENEVER_SQLWARNING", "WHENEVER_ANY_ERROR", "WHENEVER_NOT_FOUND", 
  "WHENEVER_SQLERROR", "WHENEVER_SUCCESS", "WHENEVER_ERROR", 
  "START_EXTERN", "CONTINUE_CONSTRUCT", "FOUNCONSTR", "SQLSIDR", 
  "CREATE_TEMP_TABLE", "CURRENT_WINDOW_IS", "FIRST_PAGE_HEADER", 
  "ORDER_EXTERNAL_BY", "SCROLL_CURSOR_FOR", "SCROLL_CURSOR", 
  "SQL_INTERRUPT_OFF", "STOP_ALL_EXTERNAL", "WITH_CHECK_OPTION", 
  "WITH_GRANT_OPTION", "SQLSLMNW", "ADDCONSTUNIQ", "CONTINUE_DISPLAY", 
  "CONTINUE_FOREACH", "OUTPUT_TO_REPORT", "SQL_INTERRUPT_ON", 
  "WHERE_CURRENT_OF", "WITHOUT_DEFAULTS", "FOCONSTR", "SCALED_BY", 
  "CONTINUE_PROMPT", "PDF_FUNCTION", "DEFER_INTERRUPT", "DISPLAY_BY_NAME", 
  "NOT_NULL_UNIQUE", "SKIP_TO_TOP", "TOP_OF_PAGE", "SKIP_TO", "SKIP_BY", 
  "WITHOUT_WAITING", "BEFCONSTRUCT", "SQLSLMW", "AFTCONSTRUCT", 
  "ALL_PRIVILEGES", "CLOSE_DATABASE", "CONTINUE_INPUT", "CONTINUE_WHILE", 
  "CREATE_SYNONYM", "DROP_TABLE", "EXIT_CONSTRUCT", "INEXCLUSIVE", 
  "REPORT_TO_PRINTER", "REPORT_TO_PIPE", "RETURN", "SET_SESSION_TO", 
  "UPDATESTATS", "WITHOUT_HEAD", "CLEARSCR", "WITH_B_LOG", 
  "AUTHORIZATION", "BOTTOM_MARGIN", "CLOSE_SESSION", "CONTINUE_CASE", 
  "CONTINUE_MENU", "DISPLAY_ARRAY", "END_SQL", "DOLLAR", "END_CONSTRUCT", 
  "FIELD_TOUCHED", "FINISH_REPORT", "INFACC", "INPUT_NO_WRAP", "SETPMOFF", 
  "UNCONSTRAINED", "PAGE_TRAILER", "SETPMON", "BEFGROUP", "CLOSE_WINDOW", 
  "COMMENT_LINE", "CONTINUE_FOR", "CREATE_DB", "CREATE_TABLE", 
  "DEFAULT_NULL", "DEFAULT_TODAY", "DEFAULT_USER", "DELETE_USING", 
  "DISPLAY_FORM", "END_FUNCTION", "EXIT_DISPLAY", "EXIT_FOREACH", 
  "EXIT_PROGRAM", "INFCOLS", "ON_EVERY_ROW", "OPEN_SESSION", 
  "RIGHT_MARGIN", "SELECT_USING", "START_REPORT", "UNLOCK_TABLE", 
  "UPDATE_USING", "ACL_BUILTIN", "AFTGROUP", "INFIDX", "INFSTAT", 
  "LEFT_MARGIN", "PAGE_HEADER", "ROLLBACK_W", "SET_SESSION", "SQLSEOFF", 
  "WITH_A_LOG", "BEFDISP", "BEFORE_MENU", "CREATE_VIEW", "DEFINE_TYPE", 
  "DELETE_FROM", "END_DISPLAY", "END_REPORT", "END_FOREACH", "END_FOR", 
  "END_GLOBALS", "EXIT_PROMPT", "EXTENT_SIZE", "FOREIGN_KEY", 
  "HIDE_OPTION", "HIDE_WINDOW", "INSERT_INTO", "IS_NOT_NULL", 
  "MOVE_WINDOW", "NEXT_OPTION", "NOT_MATCHES", "ON_LAST_ROW", 
  "OPEN_WINDOW", "OPEN_STATUSBOX", "PAGE_LENGTH", "PAGE_WIDTH", 
  "PRIMARY_KEY", "PROMPT_LINE", "RECORD_LIKE", "ROLLFORWARD", "SETBL", 
  "SHOW_OPTION", "SHOW_WINDOW", "SQLSEON", "TO_DATABASE", "USE_SESSION", 
  "WITH_NO_LOG", "AFTDISP", "BEFFIELD", "INSHARE", "UNLOCKTAB", 
  "AFTFIELD", "ATTRIBUTES", "BEFINP", "BEGIN_WORK", "CLEARWIN", 
  "CLOSE_FORM", "DEFER_QUIT", "DESCENDING", "DROP_INDEX", "END_PROMPT", 
  "END_RECORD", "ERROR_LINE", "EXIT_INPUT", "EXIT_WHILE", "FOR_UPDATE_OF", 
  "FOR_UPDATE", "GET_FLDBUF", "INITIALIZE", "INPUT_WRAP", "LOCK_TABLE", 
  "MSG_LINE", "NOT_EXISTS", "ON_ANY_KEY", "REFERENCES", "RENCOL", 
  "SET_CURSOR", "SMALLFLOAT", "SQLSUCCESS", "TOP_MARGIN", "WITH_ARRAY", 
  "ACCEPTKEY", "ACCEPT", "AFTINP", "CLEARFORMTODEFAULTS", "CLEARFORM", 
  "CLEAR_X_FORM", "COMMIT_W", "NEXTPAGE", "PREVPAGE", "CTRL_KEY", 
  "INFTABS", "NEXTFIELD", "NEXTFORM", "RENTAB", "ASCENDING", "ASSOCIATE", 
  "CHAR", "NCHAR", "NVARCHAR", "CONSTRUCT", "DELIMITER", "DOWNSHIFT", 
  "DROP_VIEW", "END_INPUT", "END_WHILE", "EXCLUSIVE", "EXIT_CASE", 
  "EXIT_MENU", "FORM_LINE", "INTERRUPT", "INTO_TEMP", "INVISIBLE", 
  "IN_MEMORY", "LINKED_TO", "LOAD_FROM", "LOCKTAB", "MENU_LINE", 
  "OPEN_FORM", "OTHERWISE", "PRECISION", "PRIOR", "PROCEDURE", 
  "REPORT_TO", "RETURNING", "UNDERLINE", "UNLOAD_TO", "BEFROW", 
  "UNLOAD_T", "VARIABLE", "ABSOLUTE", "AFTROW", "BUFFERED", "CONSTANT", 
  "CONST", "DATABASE", "DATETIME", "DEFAULTS", "DISTINCT", "END_CASE", 
  "END_MAIN", "END_MENU", "END_TYPE", "EXIT_FOR", "EXTERNAL", "FRACTION", 
  "FUNCTION", "GROUP_BY", "INTERVAL", "KWMESSAGE", "NOT_LIKE", 
  "NOT_ILIKE", "NOT_NULL", "PASSWORD", "PREVIOUS", "READONLY", "REGISTER", 
  "RELATIVE", "RESOURCE", "SMALLINT", "VALIDATE", "WITH_LOG", "WORDWRAP", 
  "BY_NAME", "IN_FILE", "IS_NULL", "AVERAGE", "BETWEEN", "CAPTION", 
  "CLIPPED", "CLOSE_BRACKET", "COLUMNS", "CONNECT", "CURRENT", "DBYNAME", 
  "DECIMAL", "DECLARE", "DEFAULT", "DISPLAY", "ENDCODE", "EXECUTE", 
  "FOREACH", "FOREIGN", "GLOBALS", "INFIELD", "INTEGER", "KWWINDOW", 
  "MAGENTA", "OPTIONS", "PERCENT", "PREPARE", "PROGRAM", "RECOVER", 
  "REVERSE", "SECTION", "SESSION", "SYNONYM", "THRU", "TRAILER", 
  "UPSHIFT", "VARCHAR", "WAITING", "CLOSE_SHEV", "CLOSE_SQUARE", 
  "KW_FALSE", "NOT_IN", "ONKEY", "OPEN_BRACKET", "BORDER", "BOTTOM", 
  "COLUMN", "COMMIT", "CREATE", "CURSOR", "DEFINE", "DELETE", "DOUBLE", 
  "END_IF", "ESCAPE", "EXISTS", "EXTEND", "EXTENT", "FINISH", "FORMAT", 
  "HAVING", "HEADER", "INSERT", "LOCATE", "MARGIN", "MEMORY", "MINUTE", 
  "MODIFY", "NORMAL", "EQUAL_EQUAL", "OPEN_SHEV", "OPEN_SQUARE", "OPTION", 
  "OUTPUT", "PROMPT", "PUBLIC", "RECORD", "REPORT", "REVOKE", "SCHEMA", 
  "SCROLL_USING", "SCROLL", "SECOND", "SELECT", "SERIAL", "SETL", 
  "SHARED", "SPACES", "UNIQUE", "UNLOCK", "UPDATE", "VALUES", "YELLOW", 
  "AFTER", "KWLINE", "KW_NULL", "KW_TRUE", "SINGLE_KEY", "ALTER", "ARRAY", 
  "ASCII", "AUDIT", "BLACK", "BLINK", "CHECK", "CLEAR", "CLOSE", "CODE_C", 
  "COUNT", "DEFER", "ERROR", "EVERY", "FETCH", "FIRST", "FLOAT", "FLUSH", 
  "FOUND", "GRANT", "GREEN", "GROUP", "INDEX", "KWFORM", "LABEL", "LOCAL", 
  "MONEY", "MONTH", "ORDER", "OUTER", "PAUSE", "PRINT_IMAGE", 
  "PRINT_FILE", "PRINT", "RIGHT", "DOUBLE_COLON", "SEMICOLON", "SLEEP", 
  "TUPLE", "UNION", "WHERE", "WHILE", "WHITE", "CCODE", "ANSI", "BLUE", 
  "BOLD", "BYTE", "FCALL", "CASE", "CYAN", "DATE", "DESC", "KWDOWN", 
  "TAB", "DROP", "ELSE", "EXEC", "EXIT", "FREE", "FROM", "GOTO", 
  "HELP_FILE", "LANG_FILE", "HELP", "HIDE", "HOUR", "INTO", "LAST", 
  "LEFT", "LIKE", "MAIN", "MENU", "MODE", "NEED", "NEXT", "NOCR", "OPEN", 
  "QUIT", "REAL", "ROWS", "SHOW", "SIZE", "SKIP", "SOME", "STEP", "STOP", 
  "TEMP", "TEXT", "THEN", "USER", "WAIT", "WHEN", "WITH", "WORK", "YEAR", 
  "KW_IS", "XSET", "ADD", "ALL", "ANY", "ASC", "AVG", "COLON", "DAY", 
  "DBA", "DEC", "DIM", "FKEY", "FOR", "KEY", "KWNO", "LET", "LOG", "XMAX", 
  "XMIN", "PAD", "PUT", "RED", "ROW", "RUN", "SQL", "SUM", "TOP", "USE", 
  "ATSIGN", "AS_TIFF", "AS_GIF", "AS_PNG", "AS_JPEG", "AS", "AT", "BY", 
  "DOT", "GO", "IF", "IN", "OF", "ON", "TO", "KWUP", "FONT_NAME", 
  "FONT_SIZE", "PAPER_SIZE_IS_LETTER", "PAPER_SIZE_IS_LEGAL", 
  "PAPER_SIZE_IS_A5", "PAPER_SIZE_IS_A4", "PAPER_SIZE_IS_LETTER_L", 
  "PAPER_SIZE_IS_LEGAL_L", "PAPER_SIZE_IS_A5_L", "PAPER_SIZE_IS_A4_L", 
  "FORMHANDLER", "END_FORMHANDLER", "BEFORE_EVENT", "BEFORE_OPEN_FORM", 
  "AFTER_EVENT", "BEFORE_CLOSE_FORM", "BEFORE_ANY", "AFTER_ANY", 
  "MENUHANDLER", "END_MENUHANDLER", "BEFORE_SHOW_MENU", "DISABLE_PROGRAM", 
  "DISABLE_ALL", "BUTTONS", "CHECK_MENUITEM", "DISABLE_FORM", 
  "DISABLE_MENUITEMS", "DISABLE", "ENABLE_FORM", "ENABLE_MENUITEMS", 
  "ENABLE", "KWFIELD", "ICON", "MESSAGEBOX", "TO_DEFAULTS", 
  "UNCHECK_MENUITEM", "BEFORE", "INPUT", "END", "INT_TO_ID", "TIMEOUT", 
  "OFF", "WITH_1_DIMENSION", "WITH_2_DIMENSION", "WITH_3_DIMENSION", 
  "TILDE", "ILIKE", "FGL_ISDYNARR_ALLOCATED", "FGL_DYNARR_EXTENTSIZE", 
  "FILLFACTOR", "$accept", "pause_screen_on_cmd", "pause_screen_off_cmd", 
  "start_rpc_cmd", "stop_rpc_cmd", "valid_port", "remote_func_list", 
  "remote_func", "arr_expr", "arr_next_math", "arr_int_sign", 
  "opt_attributes", "attributes_def", "@1", "attribs_sec", "attribute", 
  "win_attributes", "win_attributes_def", "@2", "wattribs_sec", 
  "wattribute", "call_cmd", "call_ext", "@3", "@4", "@5", "@6", "@7", 
  "@8", "@9", "@10", "@11", "@12", "@13", "@14", "@15", "opt_return", 
  "opt_return_remote", "opt_func_call_args", "func_call_args", "func_arg", 
  "remote_host_name", "remote_func_name", "case_cmd", "@16", "@17", 
  "when_unit", "when_unit_expr", "end_case_command", 
  "op_otherwise_command", "@18", "op_otherwise_command_expr", "@19", 
  "when_command", "@20", "when_command_expr", "@21", "close_cmd", 
  "code_cmd", "emb_code", "sql_code", "sql_code_part", "c_code", 
  "c_code_part", "construct_cmd", "@22", "@23", "constr_rest", 
  "end_constr", "constr_col_list", "constr_col", "constr_extra_commands", 
  "constr_extra_command", "@24", "@25", "@26", "@27", "@28", 
  "bef_c_field_list_as_struct", "aft_c_field_list_as_struct", 
  "interval_expr", "extend_parameters", "op_datetime_qual", "defer_cmd", 
  "define_section", "define_multiple", "define_set", "@29", "@30", 
  "def_part", "define_ident", "@31", "def_part2", "@32", "constant_value", 
  "var_def_name", "var_def_list", "op_char", "ranking", "array_variable", 
  "@33", "@34", "@35", "assoc_open_bracket", "assoc_close_bracket", 
  "number_arr_assoc", "number_arr_list", "number_value_arr", 
  "record_variable", "@36", "@37", "@38", "link_to_pk_list", "link_to_pk", 
  "dtype_ident", "op_as_static", "dtype2", "@39", "@40", "dtype", "@41", 
  "@42", "@43", "op_prec", "like_var", "tab_name", "col_name", 
  "datetime_qual", "interval_qual", "dtime_start", "@44", "dtime_val", 
  "dtime_end", "@45", "opt_frac", "opt_unit_size", "dtfrac", "int_start", 
  "@46", "int_start_unit", "int_end", "op_equal", "dim_section", "@47", 
  "dim_dtype", "dim_like_var", "dim_array_variable", "@48", "@49", 
  "dim_record_variable", "@50", "@51", "dim_def_part", "dim_def_part2", 
  "dim_var_def_list", "dim_var_def_name", "opt_at", "display_b_n_cmd", 
  "display_cmd", "display_form_cmd", "display_array_cmd", "@52", "@53", 
  "opt_scroll", "display_attr", "disp_rest", "disp_field_commands", 
  "disp_field_command", "@54", "@55", "@56", "alloc_arr_cmd", 
  "dealloc_arr_cmd", "resize_arr_cmd", "error_cmd", "ext_cmd", 
  "continue_cmd", "exit_prog_cmd", "fgl_expr_c", "fgl_next", 
  "op_fgl_expr_ret_list", "fgl_expr_ret", "fgl_expr_ret_list", 
  "fgl_expr_list", "fgl_expr_concat", "fgl_expr", "boolean_expr", 
  "literal_expr", "variable_entry_2", "variable_entry", 
  "report_only_expr", "@57", "and_or_expr", "inexpr_list", "in_expr", 
  "null_expr", "string_match_expr", "clip_expr", "using_expr", 
  "math_expr", "comparison_expr", "reset_cnt", "function_call_expr2", 
  "@58", "@59", "@60", "@61", "function_callb", "@62", "@63", "@64", 
  "@65", "@66", "@67", "@68", "@69", "op_extend_d", "op_extend_i", 
  "function_call_expr", "builtin_expr", "builtin_funcs", "pdf_expr", 
  "interval_func_params", "numeric_time_interval", 
  "numeric_time_unit_small", "numeric_time_unit_big", 
  "field_name_list_as_struct", "field_name_list_or_char_as_struct", 
  "for_cmd", "@70", "@71", "for_step", "foreach_cmd", "@72", "@73", "@74", 
  "opt_foreach_using_part", "formhandler_def", "@75", "@76", 
  "op_input_section", "op_bef_ev_list", "bef_ev_list", "bef_ev", "@77", 
  "@78", "op_aft_ev_list", "aft_ev_list", "aft_ev", "@79", "@80", 
  "input_section", "input_sub_section", "in_variable_list", "in_id_list", 
  "in_bn_variable_list", "field_ops", "field_op", "@81", "@82", "@83", 
  "@84", "@85", "free_cmd", "line_no", "file_name", "a_number", "coords", 
  "display_coords", "field_name_as_struct", 
  "field_name_or_char_as_struct", "cursor_name", "fetch_cursor_name", 
  "win_name", "open_win_name", "form_name", "open_form_name", 
  "opt_help_no", "identifier", "ident_or_var", "ident_p2", 
  "var_or_string", "field_name2_as_struct", "cvariable", "real_number", 
  "goto_cmd", "label_goto", "check_menu_cmd", "menu_item_list", 
  "menu_item", "uncheck_menu_cmd", "disable_cmd", "enable_cmd", 
  "msg_box_cmd", "@86", "op_disable_msg", "gm_disable_msg", 
  "op_returning_msg", "gm_returning_msg", "op_caption", "gm_caption", 
  "op_icon", "gm_icon", "op_buttons", "gm_buttons", "op_def_but", 
  "if_cmd", "@87", "@88", "op_else", "@89", "@90", "@91", "import_m", 
  "module_import", "init_cmd", "@92", "init_tab_list", "init_tab", 
  "init_table_name", "end_input", "opt_defs", "field_commands", 
  "field_command", "@93", "@94", "@95", "@96", "@97", "@98", "@99", 
  "@100", "@101", "@102", "@103", "@104", "@105", 
  "bef_field_list_as_struct", "aft_field_list_as_struct", 
  "next_field_cmd", "next_form_cmd", "next_field", "input_cmd", "@106", 
  "inp_rest", "@107", "scroll_cmd", "up_or_down", "op_help", 
  "input_array_attributes", "input_array_attributes_int", 
  "on_key_command", "@108", "key_val", "@109", "accept_key", 
  "single_key_val", "key_do", "key_value_list", "key_value", 
  "key_value_1", "label_cmd", "let_cmd", "@110", "@111", "op_expr_null", 
  "linked_cmd", "linked_del_cmd", "linked_upd_cmd", "locate_cmd", 
  "module", "@112", "op_module_header", "module_header", "module_entry", 
  "func_main_def", "func_or_main2", "at_term_cmd", "func_or_main", 
  "module_code", "op_code", "module_define_section", "ldeffunction", 
  "func_def", "@113", "@114", "@115", "@116", "end_func_command", 
  "main_def", "@117", "@118", "return_cmd", "op_fgl_expr_list", 
  "db_section", "module_globals_section", "actual_globals_section", 
  "xglobals_entry", "globals_entry", "@119", "glob_section", 
  "mem_func_def", "@120", "@121", "@122", "menu_cmd", "@123", 
  "end_menu_command", "menu_block_command", "@124", "@125", "@126", 
  "menu_commands", "opt_key", "menu_opt_name", "menu_optional_desc", 
  "next_option_cmd", "show_option_cmd", "hide_option_cmd", "opt_name", 
  "opt_name_list", "menu_title", "menu_def", "@127", "@128", 
  "menu_handler_elements", "menu_handler_element", "@129", "@130", 
  "message_cmd", "msg_next", "gui_message", "msg_start", "op_msg_wait", 
  "msg_wait", "variable", "var_int", "varsetidentdot", "var", 
  "assoc_var_read", "assoc_var_write", "assoc_sub", "dot_part_var", 
  "array_r_variable", "arr_subscripts", "num_list", "num_list_element", 
  "let_variable", "let_var", "let_var_dot", "let_array_r_variable", 
  "op_param_var_list", "fparam_var_list", "ibind_var_list", 
  "func_def_var", "ibind_var", "obind_var_list", "obind_var", 
  "obind_var_let_list", "obind_let_var", "use_arr_var", 
  "obind_var_list_ord", "obind_var_ord", "optional_asc_desc", 
  "init_bind_var_list", "init_bind_var", "open_window_cmd", 
  "op_at_statusbox", "op_size_statusbox", "open_statusbox_cmd", 
  "formhandler_name", "open_form_cmd", "open_form_rest", "open_form_gui", 
  "op_at_gui", "op_like_gui", "op_absolute", "open_session_cmd", 
  "open_cursor_cmd", "user_details", "op_disable", "connect_cmd", 
  "op_connect_as", "con_user_details", "options_cmd", "opt_options", 
  "opt_allopts", "prepare_cmd", "var_or_char", "execute_cmd", "stmt_id", 
  "prompt_cmd", "@131", "opt_timeout", "gui_prompt_cmd", "opt_char", 
  "prompt_key_sec", "prompt_key_clause", "on_key_command_prompt", "@132", 
  "prompt_title", "put_cmd", "@133", "put_from", "put_val_list", 
  "put_val", "start_cmd", "op_convert", "rout", "rep_name", "op_values", 
  "output_cmd", "finish_cmd", "term_rep_cmd", "report_section", 
  "format_section", "format_actions", "format_action", "@134", "@135", 
  "@136", "@137", "@138", "@139", "@140", "report_cmd", "need_command", 
  "@141", "op_lines", "skip_command", "@142", "opt_rep_expr_list", 
  "xrep_expr_list", "xxrep_expr_list", "opt_print_at", "print_command", 
  "@143", "print_file_command", "print_img_command", "opt_scaling", 
  "img_types", "blob_var", "opt_semi", "rep_expr_list", "rep_expr", 
  "rep_agg", "op_output_section", "output_commands", "output_command", 
  "pdf_output_commands", "nval", "nval_number", "pdf_op_output_section", 
  "pdf_output_command", "op_rep_order_by", "report_def", "@144", "@145", 
  "@146", "@147", "@148", "@149", "rep_where", "pause_command", 
  "pause_msg", "pdf_report_def", "@150", "@151", "@152", "@153", "@154", 
  "@155", "pdf_report_section", "pdf_functions", "@156", "@157", "@158", 
  "op_wordwrap", "run_cmd", "drops_cmd", "drops_c", "create_cmd", 
  "create_c_2_ss", "@159", "@160", "@161", "@162", "opt_cr_table_extra", 
  "cr_table_extra", "cr_table_extra_entry", "space_name", 
  "op_cr_index_extra", "cr_index_extra", "cr_index_extra_entry", 
  "create_c_1", "op_no_log", "idx_column_list", "idx_column", 
  "table_element_list_ss", "table_element_ss", "upd_stats_cmd", 
  "alter_cmd", "alter_clauses_ss", "alter_clause_ss", 
  "alter_add_clause_ss", "add_column_clause_ss", "add_column_clauses_ss", 
  "alter_drop_clause", "drop_column_list", "drop_column", 
  "alter_modify_clause_ss", "modify_column_clauses_ss", 
  "modify_column_clause_ss", "alter_lock_mode", "alter_modify_next", 
  "alter_add_constraint_clause", "table_constraint_definition_list_ss", 
  "opt_constraint_name", "alter_drop_constraint_clause", 
  "constraint_names", "constraint_name", "set_cmd", "op_conn_id", 
  "op_fgl_expr", "sleep_cmd", "rollback_statement", "insert_statement_ss", 
  "@163", "ins_2_ss", "@164", "op_insert_column_list", 
  "insert_column_list", "insert_value_list_ss", "insert_value_ss", 
  "fetch_statement", "@165", "declare_cursor_name", "fetch_part", 
  "opt_into_fetch_part", "@166", "opt_foreach_into_fetch_part", "@167", 
  "fetch_place", "delete_statement_position", 
  "delete_statement_search_ss", "order_by_clause", 
  "sort_specification_list", "sort_specification", "sort_spec", 
  "op_asc_desc", "begin_statement", "commit_statement", "op_exclusive", 
  "set_database_cmd", "var_ident_qchar", "sql_cmd", "@168", 
  "sql_commands", "privilege_definition", "db_priv", 
  "op_with_grant_option", "privileges", "action_list", "action", 
  "op_grant_column_list", "grant_column_list", "grantee_list", "grantee", 
  "view_definition_ss", "op_view_column_list", "view_column_list", 
  "op_with_check_option", "check_constraint_definition_ss", 
  "referential_constraint_definition", "references_specification", 
  "references_columns", "referenced_table_and_columns", 
  "references_column_list", "unique_constraint_definition", 
  "unique_column_list", "table_constraint_definition_ss", 
  "default_clause", "ct_column_definiton_ss", "op_default_clause", 
  "op_column_constraint_list_ss", "column_constraint_list_ss", 
  "column_constraint_ss", "column_constraint_ss_1", "schema_ss", 
  "schema_authorization_clause", "schema_authorization_identifier", 
  "schema_element_list_ss", "schema_element_ss", "having_clause_ss", 
  "group_by_clause_ss", "column_specification_list_ss", "where_clause_ss", 
  "from_clause", "table_reference_list", "table_reference", "tname", 
  "tname_list", "table_expression_ss", "op_where_clause_ss", 
  "op_group_by_clause_ss", "op_having_clause_ss", "search_condition_ss", 
  "boolean_term_ss", "boolean_factor_ss", "boolean_primary_ss", 
  "exists_predicate_ss", "op_escape", "pattern_ss", "escape_character", 
  "in_predicate_ss", "in_value_list", "in_value_specification", "op_not", 
  "comparison_predicate_ss", "comp_op", "predicate_ss", "op_all", 
  "data_type", "char_string_type", "exact_numeric_type", "op_scale", 
  "approx_numeric_type", "length", "precision", "scale", "table_name", 
  "idx_name", "authorization_identifier", "col_arr", "column_name", 
  "column_name_specific", "correlation_name", "literal", "curr_v_clause", 
  "curr_clause", "cur_part", "cur_v_part", "s_curr_v", "e_curr_v", 
  "s_curr", "e_curr", "dbase_name", "flush_cmd", "declare_cmd", "@169", 
  "@170", "@171", "@172", "curs_forupdate", "cur_update_list", "colident", 
  "cursor_specification_all_ss", "cursor_specification_sel_ss", 
  "select_statement_full_ss", "select_statement_ss", "@173", "@174", 
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
  "units_qual", "extend_qual_ss", "datetime_value_qualified", 
  "datetime_value", "interval_value_qualified", "interval_value", 
  "sql_block_cmd", "@175", "sql_block", "sql_block_entry", "in_var", 
  "@176", "sql_block_into", "@177", "update_statement_ss", "@178", "@179", 
  "where_upd_ss", "set_clause_list_ss", "upd_columns_ss", 
  "upd_column_name", "col_1_ss", "upd_col_list", "upd_val_list_ss", 
  "upd_val_ss", "upd_value_expression_ss", 
  "upd_value_expression_initial_ss", "upd_value_expression_complex_ss", 
  "upd_var_ident_ibind_ss", "upd_value_expr_list_ss", "validate_cmd", 
  "@180", "validate_tab_list", "validate_tab", "var_ident", 
  "var2_as_string", "var2_vu", "var3_vu", "var4_vu", "var4_item_vu", 
  "var_ident_ibind_ss", "array_r_variable_or_ident_vu", 
  "arr_subscripts_al", "num_list_nl", "num_list_element_nl", 
  "whenever_cmd", "while_cmd", "@181", "@182", "op_clr_fields", 
  "op_to_defs", "clear_cmd", "current_win_cmd", "window_type", "show_cmd", 
  "op_mnfile", "menu_name", "menu_handler", "hide_cmd", "move_cmd", 
  "NAMED", "commands", "all_commands", "command1", "commands_all", "@183", 
  "commands_all1", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const unsigned short yytoknum[] =
{
       0,   256,  1710,  1711,  1712,  1617,  1657,  1612,  1549,  1632,
    1429,  1535,  1531,  1446,  1607,  1348,  1405,  1477,  1643,  1630,
    1536,  1563,  1631,  1412,  1713,  1714,  1715,  1716,  1717,  1718,
    1719,  1720,  1721,  1722,  1723,  1724,  1000,  1001,  1002,  1003,
    1004,  1005,  1006,  1007,  1008,  1009,  1010,  1011,  1012,  1013,
    1014,  1015,  1016,  1017,  1018,  1019,  1020,  1021,  1022,  1023,
    1024,  1025,  1026,  1027,  1028,  1029,  1030,  1031,  1032,  1033,
    1034,  1035,  1036,  1037,  1038,  1039,  1040,  1041,  1042,  1043,
    1044,  1045,  1046,  1047,  1048,  1049,  1050,  1051,  1052,  1053,
    1054,  1055,  1056,  1057,  1058,  1059,  1060,  1061,  1062,  1063,
    1064,  1065,  1066,  1067,  1068,  1069,  1070,  1071,  1072,  1073,
    1074,  1075,  1076,  1077,  1078,  1079,  1080,  1081,  1082,  1083,
    1084,  1085,  1086,  1087,  1088,  1089,  1090,  1091,  1092,  1093,
    1094,  1095,  1096,  1097,  1098,  1099,  1100,  1101,  1102,  1103,
    1104,  1105,  1106,  1107,  1108,  1109,  1110,  1111,  1112,  1113,
    1114,  1115,  1116,  1117,  1118,  1119,  1120,  1121,  1122,  1123,
    1124,  1125,  1126,  1127,  1128,  1129,  1130,  1131,  1132,  1133,
    1134,  1135,  1136,  1137,  1138,  1139,  1140,  1141,  1142,  1143,
    1144,  1145,  1146,  1147,  1148,  1149,  1150,  1151,  1152,  1153,
    1154,  1155,  1156,  1157,  1158,  1159,  1160,  1161,  1162,  1163,
    1164,  1165,  1166,  1167,  1168,  1169,  1170,  1171,  1172,  1173,
    1174,  1175,  1176,  1177,  1178,  1179,  1180,  1181,  1182,  1183,
    1184,  1185,  1186,  1187,  1188,  1189,  1190,  1191,  1192,  1193,
    1194,  1195,  1196,  1197,  1198,  1199,  1200,  1201,  1202,  1203,
    1204,  1205,  1206,  1207,  1208,  1209,  1210,  1211,  1212,  1213,
    1214,  1215,  1216,  1217,  1218,  1219,  1220,  1221,  1222,  1223,
    1224,  1225,  1226,  1227,  1228,  1229,  1230,  1231,  1232,  1233,
    1234,  1235,  1236,  1237,  1238,  1239,  1240,  1241,  1242,  1243,
    1244,  1245,  1246,  1247,  1248,  1249,  1250,  1251,  1252,  1253,
    1254,  1255,  1256,  1257,  1258,  1259,  1260,  1261,  1262,  1263,
    1264,  1265,  1266,  1267,  1268,  1269,  1270,  1271,  1272,  1273,
    1274,  1275,  1276,  1277,  1278,  1279,  1280,  1281,  1282,  1283,
    1284,  1285,  1286,  1287,  1288,  1289,  1290,  1291,  1292,  1293,
    1294,  1295,  1296,  1297,  1298,  1299,  1300,  1301,  1302,  1303,
    1304,  1305,  1306,  1307,  1308,  1309,  1310,  1311,  1312,  1313,
    1314,  1315,  1316,  1317,  1318,  1319,  1320,  1321,  1322,  1323,
    1324,  1325,  1326,  1327,  1328,  1329,  1330,  1331,  1332,  1333,
    1334,  1335,  1336,  1337,  1338,  1339,  1340,  1341,  1342,  1343,
    1344,  1345,  1346,  1347,  1349,  1350,  1351,  1352,  1353,  1354,
    1355,  1356,  1357,  1358,  1359,  1360,  1361,  1362,  1363,  1364,
    1365,  1366,  1367,  1368,  1369,  1370,  1371,  1372,  1373,  1374,
    1375,  1376,  1377,  1378,  1379,  1380,  1381,  1382,  1383,  1384,
    1385,  1386,  1387,  1388,  1389,  1390,  1391,  1392,  1393,  1394,
    1395,  1396,  1397,  1398,  1399,  1400,  1401,  1402,  1403,  1404,
    1406,  1407,  1408,  1409,  1410,  1411,  1413,  1414,  1415,  1416,
    1417,  1418,  1419,  1420,  1421,  1422,  1423,  1424,  1425,  1426,
    1427,  1428,  1430,  1431,  1432,  1433,  1434,  1435,  1436,  1437,
    1438,  1439,  1440,  1441,  1442,  1443,  1444,  1445,  1447,  1448,
    1449,  1450,  1451,  1452,  1453,  1454,  1455,  1456,  1457,  1458,
    1459,  1460,  1461,  1462,  1463,  1464,  1465,  1466,  1467,  1468,
    1469,  1470,  1471,  1472,  1473,  1474,  1475,  1476,  1478,  1479,
    1480,  1481,  1482,  1483,  1484,  1485,  1486,  1487,  1488,  1489,
    1490,  1491,  1492,  1493,  1494,  1495,  1496,  1497,  1498,  1499,
    1500,  1501,  1502,  1503,  1504,  1505,  1506,  1507,  1508,  1509,
    1510,  1511,  1512,  1513,  1514,  1515,  1516,  1517,  1518,  1519,
    1520,  1521,  1522,  1523,  1524,  1525,  1526,  1527,  1528,  1529,
    1530,  1532,  1533,  1534,  1537,  1538,  1539,  1540,  1541,  1542,
    1543,  1544,  1545,  1546,  1547,  1548,  1550,  1551,  1552,  1553,
    1554,  1555,  1556,  1557,  1558,  1559,  1560,  1561,  1562,  1564,
    1565,  1566,  1567,  1568,  1569,  1570,  1571,  1572,  1573,  1574,
    1575,  1576,  1577,  1578,  1579,  1580,  1581,  1582,  1583,  1584,
    1585,  1586,  1587,  1588,  1589,  1590,  1591,  1592,  1593,  1594,
    1595,  1596,  1597,  1598,  1599,  1600,  1601,  1602,  1603,  1604,
    1605,  1606,  1608,  1609,  1610,  1611,  1613,  1614,  1615,  1616,
    1618,  1619,  1620,  1621,  1622,  1623,  1624,  1625,  1626,  1627,
    1628,  1629,  1633,  1634,  1635,  1636,  1637,  1638,  1639,  1640,
    1641,  1642,  1644,  1645,  1646,  1647,  1648,  1649,  1650,  1651,
    1652,  1653,  1654,  1655,  1656,  1658,  1659,  1660,  1661,  1662,
    1663,  1664,  1665,  1666,  1667,  1668,  1669,  1670,  1671,  1672,
    1673,  1674,  1675,  1676,  1677,  1678,  1679,  1680,  1681,  1682,
    1683,  1684,  1685,  1686,  1687,  1688,  1689,  1690,  1691,  1692,
    1693,  1694,  1695,  1696,  1697,  1698,  1699,  1700,  1701,  1702,
    1703,  1704,  1705,  1706,  1707,  1708,  1709
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const unsigned short yyr1[] =
{
       0,   727,   728,   729,   730,   731,   732,   732,   733,   733,
     734,   735,   735,   735,   735,   735,   735,   736,   736,   736,
     736,   736,   737,   737,   738,   738,   740,   739,   739,   741,
     741,   742,   742,   742,   742,   742,   742,   742,   742,   742,
     742,   742,   742,   742,   742,   742,   742,   742,   743,   743,
     745,   744,   746,   746,   747,   747,   747,   747,   747,   747,
     747,   747,   747,   748,   749,   750,   749,   749,   749,   749,
     749,   751,   752,   749,   753,   754,   755,   749,   756,   757,
     749,   758,   759,   749,   760,   761,   762,   749,   763,   763,
     764,   764,   764,   765,   765,   766,   766,   767,   767,   768,
     768,   769,   769,   771,   770,   772,   770,   773,   773,   774,
     774,   775,   776,   777,   776,   778,   779,   778,   781,   780,
     783,   782,   784,   784,   784,   784,   784,   784,   785,   786,
     786,   787,   787,   788,   789,   789,   790,   792,   793,   791,
     794,   794,   795,   795,   796,   796,   797,   797,   797,   798,
     798,   800,   799,   801,   799,   802,   799,   803,   799,   804,
     799,   805,   805,   806,   806,   807,   807,   807,   807,   807,
     807,   808,   809,   809,   810,   810,   811,   811,   812,   812,
     814,   815,   813,   813,   816,   816,   818,   817,   819,   819,
     819,   819,   819,   820,   819,   821,   821,   821,   821,   822,
     823,   823,   824,   824,   825,   825,   825,   825,   827,   826,
     828,   826,   829,   826,   830,   830,   831,   831,   832,   833,
     833,   833,   834,   836,   835,   837,   835,   838,   835,   839,
     839,   840,   841,   842,   842,   844,   845,   843,   846,   846,
     846,   846,   846,   846,   846,   846,   846,   846,   846,   846,
     846,   846,   846,   846,   846,   846,   846,   846,   846,   847,
     846,   848,   846,   849,   846,   846,   846,   846,   846,   846,
     846,   846,   846,   846,   850,   850,   851,   852,   853,   854,
     854,   855,   857,   856,   858,   858,   858,   858,   858,   858,
     858,   860,   859,   861,   861,   862,   862,   863,   865,   864,
     866,   866,   866,   866,   866,   866,   866,   867,   868,   868,
     870,   869,   871,   871,   871,   871,   871,   871,   871,   871,
     871,   871,   871,   871,   871,   871,   871,   871,   871,   871,
     871,   871,   871,   871,   871,   872,   874,   873,   875,   873,
     877,   876,   878,   876,   879,   879,   880,   881,   881,   882,
     883,   883,   883,   883,   883,   883,   883,   883,   884,   885,
     886,   888,   889,   887,   890,   890,   891,   892,   892,   892,
     893,   893,   895,   894,   896,   894,   897,   894,   898,   899,
     900,   901,   901,   902,   902,   902,   902,   902,   902,   902,
     902,   902,   903,   903,   903,   903,   903,   903,   903,   903,
     904,   904,   905,   905,   905,   905,   905,   905,   905,   905,
     905,   906,   906,   906,   906,   906,   906,   906,   906,   906,
     906,   906,   907,   907,   908,   908,   909,   909,   910,   910,
     911,   911,   912,   913,   913,   913,   913,   913,   913,   914,
     914,   914,   914,   915,   915,   916,   917,   917,   917,   918,
     917,   919,   919,   920,   920,   921,   921,   921,   921,   922,
     922,   923,   923,   923,   923,   923,   923,   923,   923,   924,
     925,   926,   926,   926,   926,   926,   926,   927,   927,   927,
     927,   927,   927,   927,   928,   930,   931,   929,   932,   933,
     929,   935,   936,   934,   937,   938,   934,   939,   940,   934,
     941,   942,   934,   934,   934,   934,   934,   934,   934,   934,
     934,   934,   934,   934,   934,   934,   934,   934,   934,   934,
     934,   934,   934,   934,   934,   934,   934,   943,   943,   944,
     945,   945,   945,   945,   945,   945,   945,   945,   945,   946,
     946,   947,   947,   947,   947,   948,   948,   948,   949,   949,
     950,   950,   950,   951,   951,   951,   951,   951,   951,   951,
     951,   951,   951,   952,   952,   953,   953,   954,   954,   956,
     957,   955,   958,   958,   960,   961,   962,   959,   963,   963,
     965,   966,   964,   967,   967,   968,   968,   969,   969,   971,
     970,   972,   970,   973,   973,   974,   974,   976,   975,   977,
     975,   978,   979,   979,   979,   980,   980,   981,   981,   982,
     982,   983,   983,   985,   984,   986,   984,   987,   984,   988,
     984,   989,   984,   990,   991,   991,   991,   991,   991,   991,
     991,   992,   992,   993,   994,   995,   996,   996,   996,   996,
     996,   996,   996,   996,   997,   997,   998,   999,  1000,  1001,
    1002,  1003,  1004,  1004,  1005,  1006,  1007,  1007,  1008,  1008,
    1009,  1009,  1009,  1009,  1009,  1009,  1010,  1011,  1011,  1012,
    1013,  1013,  1014,  1015,  1015,  1016,  1017,  1018,  1018,  1018,
    1019,  1019,  1019,  1021,  1020,  1022,  1022,  1023,  1023,  1024,
    1024,  1025,  1026,  1026,  1027,  1028,  1028,  1029,  1030,  1030,
    1031,  1032,  1032,  1034,  1035,  1033,  1036,  1037,  1036,  1038,
    1039,  1036,  1040,  1040,  1041,  1043,  1042,  1042,  1044,  1044,
    1045,  1045,  1046,  1047,  1047,  1047,  1048,  1048,  1049,  1049,
    1051,  1050,  1052,  1050,  1053,  1050,  1054,  1050,  1055,  1050,
    1056,  1050,  1057,  1050,  1058,  1050,  1059,  1050,  1060,  1050,
    1061,  1050,  1062,  1050,  1063,  1050,  1064,  1064,  1065,  1065,
    1066,  1067,  1068,  1068,  1068,  1070,  1069,  1071,  1071,  1072,
    1071,  1073,  1074,  1074,  1074,  1074,  1074,  1074,  1075,  1075,
    1076,  1077,  1077,  1077,  1077,  1077,  1077,  1077,  1077,  1077,
    1079,  1078,  1078,  1081,  1080,  1082,  1083,  1084,  1084,  1085,
    1085,  1086,  1087,  1087,  1087,  1087,  1087,  1087,  1087,  1087,
    1087,  1087,  1087,  1087,  1087,  1087,  1087,  1087,  1087,  1087,
    1088,  1090,  1091,  1089,  1092,  1092,  1093,  1094,  1095,  1096,
    1096,  1098,  1097,  1099,  1099,  1100,  1100,  1101,  1101,  1101,
    1101,  1101,  1101,  1102,  1102,  1103,  1103,  1104,  1105,  1105,
    1105,  1105,  1105,  1105,  1105,  1105,  1105,  1105,  1106,  1107,
    1107,  1108,  1109,  1109,  1111,  1112,  1113,  1114,  1110,  1115,
    1117,  1118,  1116,  1119,  1120,  1120,  1121,  1121,  1122,  1123,
    1123,  1124,  1126,  1125,  1127,  1127,  1127,  1127,  1129,  1130,
    1131,  1128,  1133,  1132,  1134,  1136,  1135,  1137,  1135,  1138,
    1135,  1139,  1139,  1140,  1140,  1141,  1141,  1142,  1142,  1142,
    1143,  1144,  1145,  1146,  1146,  1146,  1147,  1147,  1148,  1148,
    1150,  1151,  1149,  1152,  1152,  1154,  1153,  1155,  1153,  1156,
    1157,  1157,  1157,  1157,  1158,  1158,  1158,  1158,  1158,  1159,
    1160,  1160,  1161,  1162,  1163,  1163,  1164,  1165,  1165,  1165,
    1165,  1165,  1165,  1166,  1167,  1168,  1168,  1169,  1169,  1170,
    1171,  1171,  1172,  1172,  1173,  1174,  1175,  1175,  1175,  1175,
    1175,  1175,  1176,  1176,  1177,  1178,  1178,  1179,  1179,  1180,
    1180,  1181,  1181,  1182,  1182,  1182,  1182,  1182,  1183,  1183,
    1184,  1184,  1185,  1185,  1186,  1187,  1188,  1188,  1189,  1190,
    1190,  1190,  1191,  1191,  1192,  1192,  1193,  1194,  1194,  1195,
    1195,  1196,  1197,  1198,  1199,  1199,  1200,  1201,  1201,  1202,
    1202,  1203,  1203,  1204,  1205,  1205,  1206,  1206,  1206,  1206,
    1207,  1207,  1207,  1208,  1209,  1209,  1210,  1210,  1210,  1211,
    1212,  1212,  1213,  1213,  1213,  1213,  1213,  1213,  1213,  1213,
    1213,  1213,  1213,  1213,  1213,  1213,  1213,  1213,  1213,  1213,
    1213,  1213,  1213,  1213,  1213,  1213,  1213,  1213,  1214,  1215,
    1215,  1216,  1216,  1216,  1216,  1216,  1217,  1219,  1218,  1220,
    1220,  1221,  1222,  1222,  1223,  1223,  1224,  1224,  1226,  1225,
    1227,  1229,  1228,  1230,  1230,  1231,  1231,  1232,  1232,  1233,
    1233,  1233,  1233,  1234,  1234,  1235,  1235,  1236,  1237,  1237,
    1238,  1239,  1240,  1241,  1242,  1242,  1243,  1243,  1245,  1244,
    1246,  1244,  1247,  1244,  1248,  1244,  1249,  1244,  1250,  1244,
    1251,  1244,  1252,  1252,  1252,  1252,  1252,  1252,  1254,  1253,
    1255,  1255,  1257,  1256,  1256,  1256,  1256,  1256,  1258,  1258,
    1259,  1259,  1260,  1261,  1261,  1263,  1262,  1264,  1265,  1266,
    1266,  1266,  1267,  1267,  1267,  1267,  1268,  1269,  1269,  1270,
    1270,  1271,  1272,  1272,  1272,  1272,  1272,  1272,  1272,  1272,
    1273,  1273,  1274,  1274,  1275,  1275,  1275,  1275,  1275,  1275,
    1275,  1275,  1275,  1275,  1276,  1276,  1277,  1277,  1277,  1277,
    1278,  1278,  1279,  1279,  1280,  1280,  1280,  1280,  1280,  1280,
    1280,  1280,  1280,  1280,  1280,  1280,  1280,  1280,  1280,  1280,
    1280,  1280,  1280,  1280,  1280,  1280,  1280,  1280,  1281,  1281,
    1281,  1283,  1284,  1285,  1286,  1287,  1288,  1282,  1289,  1289,
    1290,  1291,  1291,  1293,  1294,  1295,  1296,  1297,  1298,  1292,
    1299,  1301,  1302,  1303,  1300,  1304,  1304,  1304,  1304,  1305,
    1305,  1305,  1305,  1305,  1306,  1307,  1307,  1307,  1307,  1308,
    1308,  1310,  1311,  1309,  1312,  1313,  1309,  1314,  1314,  1315,
    1315,  1316,  1316,  1316,  1316,  1316,  1317,  1318,  1318,  1319,
    1319,  1320,  1320,  1321,  1321,  1321,  1321,  1321,  1322,  1322,
    1323,  1323,  1324,  1324,  1324,  1325,  1325,  1326,  1326,  1327,
    1327,  1328,  1328,  1328,  1329,  1329,  1330,  1330,  1330,  1330,
    1330,  1330,  1330,  1331,  1331,  1332,  1332,  1333,  1333,  1334,
    1334,  1335,  1335,  1336,  1337,  1337,  1338,  1338,  1339,  1340,
    1340,  1341,  1342,  1342,  1343,  1343,  1344,  1344,  1345,  1345,
    1346,  1346,  1347,  1348,  1348,  1348,  1348,  1348,  1348,  1348,
    1348,  1348,  1348,  1348,  1349,  1349,  1350,  1350,  1351,  1352,
    1354,  1353,  1356,  1355,  1355,  1357,  1357,  1358,  1358,  1359,
    1359,  1360,  1360,  1362,  1361,  1363,  1364,  1364,  1365,  1366,
    1365,  1367,  1368,  1367,  1369,  1369,  1369,  1369,  1369,  1369,
    1369,  1369,  1370,  1371,  1372,  1373,  1373,  1374,  1375,  1375,
    1376,  1376,  1376,  1377,  1378,  1379,  1379,  1380,  1381,  1381,
    1381,  1383,  1382,  1384,  1384,  1384,  1384,  1384,  1384,  1384,
    1384,  1384,  1384,  1384,  1384,  1385,  1385,  1385,  1385,  1386,
    1386,  1386,  1387,  1387,  1387,  1388,  1388,  1388,  1389,  1389,
    1390,  1390,  1390,  1390,  1390,  1390,  1391,  1391,  1392,  1392,
    1393,  1393,  1394,  1394,  1395,  1396,  1396,  1397,  1397,  1398,
    1398,  1399,  1400,  1401,  1402,  1403,  1403,  1404,  1404,  1405,
    1405,  1405,  1406,  1406,  1407,  1407,  1407,  1408,  1408,  1408,
    1408,  1409,  1410,  1410,  1411,  1411,  1412,  1412,  1413,  1414,
    1414,  1414,  1414,  1414,  1414,  1414,  1415,  1416,  1417,  1418,
    1418,  1419,  1419,  1420,  1421,  1422,  1422,  1423,  1424,  1425,
    1425,  1426,  1426,  1426,  1427,  1427,  1428,  1428,  1429,  1430,
    1430,  1431,  1431,  1432,  1432,  1433,  1433,  1434,  1434,  1435,
    1435,  1436,  1436,  1437,  1437,  1438,  1438,  1439,  1440,  1441,
    1441,  1441,  1441,  1442,  1442,  1443,  1443,  1444,  1444,  1445,
    1445,  1445,  1445,  1445,  1445,  1445,  1445,  1445,  1446,  1446,
    1446,  1446,  1446,  1446,  1446,  1446,  1446,  1447,  1447,  1447,
    1448,  1448,  1448,  1448,  1449,  1449,  1449,  1450,  1450,  1451,
    1451,  1451,  1451,  1451,  1451,  1451,  1451,  1451,  1451,  1451,
    1451,  1451,  1451,  1451,  1451,  1451,  1451,  1451,  1451,  1451,
    1451,  1451,  1451,  1451,  1452,  1452,  1453,  1453,  1453,  1453,
    1453,  1454,  1455,  1456,  1457,  1457,  1457,  1457,  1457,  1457,
    1457,  1457,  1458,  1458,  1458,  1458,  1458,  1458,  1458,  1458,
    1459,  1460,  1460,  1460,  1461,  1461,  1462,  1462,  1462,  1463,
    1464,  1464,  1464,  1464,  1465,  1466,  1467,  1467,  1468,  1468,
    1469,  1469,  1469,  1469,  1469,  1469,  1469,  1469,  1470,  1470,
    1470,  1470,  1470,  1470,  1470,  1470,  1471,  1471,  1471,  1471,
    1471,  1471,  1471,  1472,  1472,  1472,  1472,  1472,  1472,  1472,
    1472,  1473,  1473,  1473,  1474,  1476,  1475,  1477,  1475,  1478,
    1475,  1479,  1475,  1480,  1480,  1480,  1481,  1481,  1482,  1482,
    1482,  1483,  1483,  1484,  1484,  1485,  1487,  1488,  1486,  1489,
    1490,  1490,  1491,  1492,  1492,  1492,  1492,  1492,  1493,  1494,
    1494,  1495,  1496,  1497,  1497,  1497,  1497,  1498,  1498,  1499,
    1499,  1499,  1500,  1501,  1501,  1501,  1502,  1502,  1502,  1502,
    1502,  1502,  1502,  1502,  1503,  1503,  1503,  1503,  1503,  1503,
    1503,  1503,  1503,  1503,  1503,  1503,  1503,  1503,  1503,  1503,
    1503,  1503,  1503,  1503,  1503,  1503,  1504,  1504,  1505,  1506,
    1507,  1507,  1508,  1508,  1509,  1509,  1510,  1510,  1511,  1511,
    1512,  1513,  1513,  1514,  1514,  1515,  1516,  1516,  1516,  1517,
    1517,  1518,  1519,  1520,  1521,  1522,  1522,  1523,  1523,  1523,
    1523,  1523,  1523,  1524,  1524,  1524,  1524,  1525,  1525,  1526,
    1527,  1527,  1527,  1528,  1530,  1529,  1531,  1531,  1532,  1532,
    1532,  1532,  1532,  1532,  1532,  1532,  1532,  1532,  1532,  1532,
    1532,  1532,  1532,  1532,  1532,  1532,  1532,  1532,  1532,  1532,
    1532,  1532,  1532,  1532,  1532,  1532,  1532,  1532,  1532,  1532,
    1532,  1532,  1532,  1532,  1532,  1532,  1532,  1532,  1532,  1532,
    1532,  1532,  1532,  1532,  1532,  1532,  1532,  1532,  1532,  1532,
    1532,  1532,  1532,  1532,  1532,  1532,  1532,  1532,  1532,  1532,
    1532,  1532,  1532,  1532,  1532,  1532,  1532,  1532,  1532,  1532,
    1532,  1532,  1532,  1532,  1532,  1532,  1532,  1532,  1532,  1532,
    1532,  1532,  1532,  1532,  1532,  1532,  1532,  1532,  1532,  1532,
    1532,  1532,  1532,  1532,  1532,  1532,  1532,  1532,  1532,  1532,
    1532,  1532,  1532,  1532,  1532,  1532,  1532,  1532,  1532,  1532,
    1532,  1532,  1532,  1532,  1532,  1532,  1532,  1532,  1532,  1532,
    1532,  1532,  1532,  1532,  1532,  1532,  1532,  1532,  1532,  1532,
    1532,  1532,  1532,  1532,  1532,  1532,  1532,  1532,  1532,  1532,
    1532,  1532,  1532,  1532,  1532,  1532,  1532,  1532,  1532,  1532,
    1532,  1532,  1532,  1532,  1532,  1532,  1532,  1532,  1532,  1532,
    1532,  1532,  1532,  1532,  1532,  1532,  1532,  1532,  1532,  1532,
    1532,  1532,  1532,  1532,  1532,  1532,  1532,  1532,  1532,  1532,
    1532,  1532,  1532,  1532,  1532,  1532,  1532,  1532,  1532,  1532,
    1532,  1532,  1532,  1532,  1532,  1532,  1532,  1532,  1532,  1532,
    1532,  1532,  1532,  1532,  1532,  1532,  1532,  1532,  1532,  1532,
    1532,  1532,  1532,  1532,  1532,  1532,  1532,  1532,  1532,  1532,
    1532,  1532,  1532,  1532,  1532,  1532,  1532,  1532,  1532,  1532,
    1532,  1532,  1532,  1532,  1532,  1532,  1532,  1532,  1532,  1532,
    1532,  1532,  1532,  1532,  1532,  1532,  1532,  1532,  1532,  1532,
    1532,  1532,  1532,  1532,  1532,  1532,  1532,  1532,  1532,  1532,
    1532,  1532,  1532,  1532,  1532,  1532,  1532,  1532,  1532,  1532,
    1532,  1532,  1532,  1532,  1532,  1532,  1532,  1532,  1532,  1532,
    1532,  1532,  1532,  1532,  1532,  1532,  1532,  1532,  1532,  1532,
    1532,  1532,  1532,  1532,  1532,  1532,  1532,  1532,  1532,  1532,
    1532,  1532,  1532,  1532,  1532,  1532,  1532,  1532,  1532,  1532,
    1532,  1532,  1532,  1532,  1532,  1532,  1534,  1533,  1536,  1535,
    1538,  1539,  1537,  1540,  1540,  1540,  1541,  1541,  1541,  1541,
    1541,  1541,  1542,  1542,  1543,  1544,  1545,  1545,  1546,  1546,
    1547,  1547,  1548,  1548,  1548,  1549,  1549,  1549,  1549,  1549,
    1549,  1549,  1549,  1549,  1549,  1549,  1549,  1549,  1549,  1550,
    1550,  1550,  1550,  1550,  1550,  1550,  1550,  1550,  1550,  1550,
    1550,  1550,  1550,  1550,  1550,  1551,  1552,  1552,  1554,  1553,
    1555,  1555,  1556,  1556,  1557,  1558,  1559,  1559,  1560,  1560,
    1561,  1561,  1561,  1562,  1562,  1563,  1563,  1564,  1565,  1565,
    1566,  1566,  1567,  1568,  1570,  1571,  1569,  1572,  1572,  1573,
    1573,  1574,  1574,  1574,  1574,  1574,  1574,  1574,  1575,  1575,
    1576,  1576,  1577,  1577,  1578,  1578,  1579,  1580,  1581,  1582,
    1582,  1583,  1584,  1584,  1585,  1586,  1586,  1588,  1587,  1589,
    1589,  1589,  1589,  1589,  1589,  1589,  1589,  1589,  1589,  1589,
    1589,  1589,  1589,  1589,  1589,  1589,  1589,  1589,  1589,  1589,
    1589,  1589,  1589,  1589,  1589,  1589,  1589,  1589,  1589,  1589,
    1589,  1589,  1589,  1589,  1589,  1589,  1589,  1589,  1589,  1589,
    1589,  1589,  1589,  1589,  1589,  1589,  1589,  1589,  1589,  1589,
    1589,  1589,  1589,  1589,  1589,  1589,  1589,  1589,  1589,  1589,
    1589,  1589,  1589,  1589,  1589,  1589,  1589,  1589,  1589,  1589,
    1589,  1589,  1589,  1589,  1589,  1589,  1589,  1589,  1589,  1589,
    1589,  1589,  1589,  1589,  1589,  1589,  1589
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
       1,     1,     3,     0,     6,     0,     5,     1,     2,     1,
       2,     1,     0,     0,     3,     0,     0,     3,     0,     4,
       0,     4,     2,     2,     2,     1,     2,     2,     3,     1,
       1,     1,     2,     1,     1,     2,     1,     0,     0,     5,
       7,     8,     0,     2,     1,     3,     1,     3,     3,     1,
       2,     0,     4,     0,     4,     0,     3,     0,     3,     0,
       3,     1,     3,     1,     3,     1,     1,     1,     1,     1,
       1,     4,     0,     4,     1,     1,     0,     1,     1,     2,
       0,     0,     5,     1,     1,     3,     0,     2,     4,     4,
       4,     4,     2,     0,     4,     1,     1,     1,     2,     1,
       1,     3,     0,     1,     0,     1,     1,     1,     0,     7,
       0,     5,     0,    12,     1,     1,     1,     1,     1,     5,
       3,     1,     1,     0,     4,     0,     5,     0,     7,     1,
       3,     1,     1,     0,     1,     0,     0,     4,     1,     1,
       1,     1,     4,     4,     4,     6,     4,     6,     1,     2,
       1,     1,     1,     1,     4,     6,     1,     4,     6,     0,
       3,     0,     3,     0,     3,     1,     1,     1,     1,     1,
       2,     2,     1,     1,     0,     3,     4,     1,     1,     0,
       3,     3,     0,     2,     1,     1,     1,     1,     1,     1,
       2,     0,     2,     0,     3,     0,     3,     1,     0,     3,
       1,     1,     1,     1,     1,     1,     2,     1,     0,     1,
       0,     5,     1,     1,     1,     4,     4,     6,     1,     1,
       1,     1,     4,     6,     1,     4,     6,     1,     1,     1,
       1,     1,     2,     2,     1,     4,     0,     7,     0,    12,
       0,     4,     0,     5,     1,     3,     2,     1,     3,     1,
       0,     2,     2,     1,     2,     5,     4,     2,     4,     5,
       3,     0,     0,    11,     0,     2,     1,     0,     2,     1,
       1,     2,     0,     3,     0,     3,     0,     3,     2,     2,
       2,     4,     5,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     2,     1,     1,     1,     2,     1,     1,     1,     2,
       2,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     2,     1,     2,     1,     1,     1,     3,     1,     3,
       1,     3,     1,     2,     1,     1,     3,     4,     4,     1,
       1,     1,     1,     1,     3,     1,     2,     2,     1,     0,
       3,     2,     2,     1,     3,     4,     4,     5,     5,     1,
       1,     2,     2,     4,     4,     2,     2,     4,     4,     1,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     0,     0,     0,     6,     0,     0,
       8,     0,     0,     6,     0,     0,     6,     0,     0,     6,
       0,     0,     6,     5,     5,     5,     5,     7,     7,     9,
       9,     6,     8,    10,    10,     7,     9,     8,    10,    12,
      14,    14,    10,    12,    12,     4,     6,     0,     3,     1,
       1,     4,     4,     4,     4,     4,     4,     1,     1,     1,
       1,     4,     4,     2,     2,     2,     2,     2,     1,     1,
       2,     1,     1,     1,     2,     4,     6,     6,     3,     5,
       5,     3,     1,     1,     3,     1,     3,     1,     3,     0,
       0,    11,     0,     2,     0,     0,     0,     9,     0,     3,
       0,     0,    10,     0,     1,     0,     1,     1,     2,     0,
       3,     0,     3,     0,     1,     1,     2,     0,     3,     0,
       3,     3,     1,     4,     3,     1,     3,     1,     3,     1,
       3,     1,     2,     0,     3,     0,     3,     0,     4,     0,
       4,     0,     4,     2,     3,     1,     3,     1,     1,     1,
       1,     1,     1,     1,     3,     1,     1,     4,     6,     4,
       3,     6,     3,     6,     1,     1,     1,     1,     1,     1,
       1,     1,     0,     2,     1,     1,     1,     4,     1,     1,
       1,     4,     3,     6,     3,     6,     1,     1,     2,     2,
       1,     2,     2,     1,     3,     1,     2,     2,     2,     4,
       2,     2,     4,     0,     8,     0,     1,     1,     1,     0,
       1,     2,     0,     1,     2,     0,     1,     2,     0,     1,
       3,     0,     2,     0,     0,     8,     0,     0,     3,     0,
       0,     7,     5,     2,     2,     0,     5,     4,     1,     3,
       3,     3,     1,     0,     2,     1,     0,     1,     1,     2,
       0,     4,     0,     4,     0,     3,     0,     3,     0,     3,
       0,     3,     0,     3,     0,     3,     0,     3,     0,     3,
       0,     3,     0,     3,     0,     3,     1,     3,     1,     3,
       2,     4,     1,     1,     1,     0,     4,     5,     6,     0,
      10,     3,     2,     2,     1,     1,     2,     2,     0,     2,
       1,     2,     3,     3,     3,     3,     1,     1,     1,     1,
       0,     3,     1,     0,     3,     2,     2,     1,     3,     1,
       3,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     0,     0,     7,     1,     1,     2,     2,     2,     3,
       4,     0,     3,     0,     1,     1,     2,     1,     1,     1,
       1,     1,     1,     0,     1,     1,     2,     2,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     0,
       1,     1,     1,     1,     0,     0,     0,     0,    13,     1,
       0,     0,     6,     2,     1,     2,     2,     2,     1,     1,
       2,     1,     0,     3,     2,     1,     1,     1,     0,     0,
       0,    14,     0,     5,     1,     0,     3,     0,     7,     0,
       5,     1,     2,     0,     1,     1,     1,     0,     1,     1,
       2,     2,     2,     1,     1,     1,     1,     3,     1,     1,
       0,     0,     7,     1,     2,     0,     3,     0,     4,     2,
       0,     2,     1,     1,     1,     1,     1,     1,     1,     3,
       0,     1,     1,     1,     1,     2,     2,     2,     5,     8,
       1,     1,     1,     4,     4,     1,     1,     1,     1,     2,
       3,     6,     1,     3,     1,     1,     1,     3,     6,     9,
       1,     1,     1,     1,     2,     0,     1,     1,     3,     1,
       3,     1,     3,     1,     3,     1,     1,     1,     1,     3,
       1,     3,     1,     3,     1,     1,     1,     3,     2,     0,
       1,     1,     1,     3,     1,     3,     7,     0,     7,     0,
       6,     3,     1,     3,     1,     2,     5,     0,     7,     0,
       2,     0,     1,     5,     2,     5,     0,     5,     6,     4,
       0,     1,     1,     5,     0,     2,     0,     5,     4,     2,
       1,     3,     2,     2,     2,     2,     2,     2,     1,     2,
       2,     2,     2,     2,     2,     2,     1,     1,     1,     1,
       2,     2,     1,     1,     1,     1,     1,     1,     5,     1,
       1,     2,     4,     4,     6,     2,     1,     0,    11,     0,
       2,     5,     0,     1,     0,     2,     1,     2,     0,     3,
       1,     0,     4,     0,     2,     1,     3,     1,     1,     4,
       5,     5,     3,     0,     1,     1,     1,     1,     0,     1,
       7,     2,     2,     2,     2,     2,     1,     2,     0,     3,
       0,     3,     0,     3,     0,     3,     0,     3,     0,     4,
       0,     4,     1,     1,     1,     1,     1,     1,     0,     4,
       0,     1,     0,     4,     1,     2,     2,     2,     0,     1,
       1,     2,     2,     0,     2,     0,     4,     3,     5,     0,
       2,     4,     1,     1,     1,     1,     1,     0,     1,     1,
       3,     2,     5,     2,     5,     5,     5,     5,     5,     5,
       0,     2,     1,     2,     2,     2,     2,     2,     2,     1,
       2,     2,     2,     2,     1,     2,     2,     2,     2,     1,
       1,     1,     0,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     1,     1,     1,     1,     1,     1,     1,     1,
       2,     2,     2,     2,     2,     1,     1,     1,     0,     3,
       2,     0,     0,     0,     0,     0,     0,    15,     0,     2,
       2,     0,     1,     0,     0,     0,     0,     0,     0,    15,
       2,     0,     0,     0,    10,     0,     1,     3,     3,     2,
       4,     3,     3,     3,     1,     2,     2,     2,     2,     1,
       1,     0,     0,     8,     0,     0,     9,     0,     1,     1,
       2,     2,     2,     2,     1,     1,     1,     0,     1,     1,
       2,     2,     2,     8,     2,     2,     4,     2,     0,     1,
       1,     3,     2,     2,     1,     1,     3,     1,     1,     2,
       1,     3,     3,     3,     1,     3,     1,     1,     1,     1,
       1,     1,     1,     2,     4,     1,     3,     1,     3,     2,
       4,     1,     3,     1,     2,     4,     1,     3,     1,     1,
       1,     2,     3,     4,     2,     4,     0,     2,     2,     4,
       1,     3,     1,     1,     1,     2,     1,     1,     1,     1,
       1,     2,     6,     6,     0,     1,     0,     1,     2,     1,
       0,     5,     0,     5,     1,     0,     3,     1,     3,     1,
       3,     1,     1,     0,     4,     1,     2,     1,     0,     0,
       3,     0,     0,     3,     1,     1,     1,     1,     1,     1,
       2,     2,     4,     3,     3,     1,     3,     2,     1,     1,
       0,     1,     1,     1,     1,     0,     1,     3,     1,     3,
       1,     0,     3,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     7,     6,     4,     4,     1,
       1,     1,     0,     1,     2,     1,     1,     1,     1,     3,
       2,     1,     1,     2,     1,     1,     0,     3,     1,     3,
       1,     3,     1,     1,     6,     0,     3,     1,     3,     0,
       1,     4,     5,     2,     1,     1,     4,     1,     3,     4,
       4,     4,     1,     3,     1,     1,     1,     2,     1,     1,
       1,     4,     0,     1,     0,     1,     1,     2,     2,     1,
       1,     1,     1,     1,     4,     1,     3,     1,     1,     1,
       2,     1,     1,     2,     2,     1,     3,     2,     2,     1,
       3,     1,     2,     4,     1,     2,     1,     3,     4,     0,
       1,     0,     1,     0,     1,     1,     3,     1,     3,     1,
       2,     1,     3,     2,     2,     0,     2,     1,     1,     5,
       3,     5,     3,     1,     3,     1,     1,     0,     1,     3,
       3,     3,     6,     4,     4,     4,     4,     5,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       0,     1,     1,     1,     1,     1,     1,     1,     4,     0,
       1,     4,     1,     5,     5,     1,     1,     1,     1,     1,
       4,     1,     4,     6,     4,     1,     4,     1,     7,     1,
       1,     1,     4,     6,     0,     2,     4,     1,     1,     1,
       1,     1,     1,     1,     3,     1,     1,     3,     5,     3,
       5,     7,     3,     1,     1,     3,     5,     3,     5,     7,
       1,     0,     3,     5,     1,     2,     2,     4,     3,     1,
       1,     1,     1,     1,     2,     2,     0,     3,     0,     3,
       1,     1,     1,     1,     1,     1,     1,     4,     1,     1,
       1,     1,     1,     1,     1,     4,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       4,     1,     3,     1,     3,     0,     7,     0,     8,     0,
       6,     0,     8,     0,     1,     2,     1,     3,     1,     3,
       5,     1,     1,     1,     1,     1,     0,     0,     9,     5,
       1,     1,     6,     0,     3,     1,     3,     4,     1,     0,
       2,     4,     6,     0,     1,     1,     1,     1,     3,     1,
       2,     3,     1,     1,     2,     2,     1,     1,     1,     2,
       2,     2,     2,     4,     3,     2,     3,     3,     3,     1,
       1,     1,     1,     1,     1,     5,     5,     5,     5,     5,
       4,     4,     3,     4,     1,     1,     1,     3,     1,     5,
       7,     5,     0,     2,     1,     1,     0,     3,     1,     3,
       1,     1,     1,     0,     3,     1,     1,     1,     1,     4,
       6,     1,     1,     2,     3,     1,     1,     1,     1,     1,
       1,     1,     1,     5,     5,     4,     5,     1,     4,     1,
       1,     7,     4,     1,     0,     4,     1,     2,     1,     1,
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
       1,     1,     1,     1,     1,     1,     0,     3,     0,     3,
       0,     0,     6,     0,     2,     2,     7,     3,     3,     2,
       2,     2,     1,     3,     1,     3,     1,     3,     1,     3,
       1,     1,     1,     2,     2,     1,     1,     2,     4,     5,
       7,     7,     9,     1,     1,     1,     1,     1,     1,     3,
       2,     3,     3,     3,     5,     5,     5,     5,     5,     4,
       4,     3,     4,     1,     1,     1,     1,     3,     0,     5,
       1,     3,     3,     3,     1,     1,     2,     1,     1,     3,
       1,     3,     3,     1,     1,     1,     3,     2,     3,     6,
       1,     3,     1,     1,     0,     0,     6,     0,     2,     0,
       1,     1,     2,     2,     1,     1,     4,     3,     1,     2,
       5,     2,     2,     5,     0,     2,     1,     1,     2,     6,
       6,     1,     0,     1,     2,     1,     2,     0,     2,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const unsigned short yydefact[] =
{
     833,     0,  2233,     0,     0,     0,   882,   180,     0,   858,
     861,   178,   183,   837,     0,   831,   834,   835,   838,   841,
     842,   840,   878,   879,   881,   839,   136,   133,     0,   129,
     131,   130,   134,  2261,   714,   654,   310,  1693,  1691,   876,
     176,   186,   877,   179,     1,   843,   836,   880,   128,   132,
     135,     0,     0,   631,     0,     0,   177,   885,   951,   632,
     886,   887,   883,   666,   943,     0,   944,   952,   950,   186,
     181,   199,     0,   184,   200,   235,     0,   863,  1243,     0,
       0,   862,  1231,   870,     0,     0,   855,   854,   856,   832,
     844,   845,   864,   848,   849,   850,   853,   851,   852,   857,
       0,  1692,   945,   884,     0,     0,   959,   957,   958,   947,
     946,   308,   186,  1167,   193,   187,   186,   192,   232,     0,
     713,     0,     0,     0,     0,   176,   580,   920,   846,     0,
     342,   328,   202,   314,   279,   298,   319,   321,   318,     0,
     340,     0,   327,   320,   324,   330,   329,   186,   331,   311,
     334,   312,   313,   956,   955,     0,    22,    23,    13,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   964,     0,
     538,   530,    16,   537,   951,    15,     0,   962,     0,   309,
       0,   185,  1168,   182,     0,   199,   201,   273,   204,   261,
     267,   268,   252,   225,   263,   202,   240,   241,     0,   227,
     279,   298,   250,   253,   248,     0,   223,     0,   259,   251,
     256,   266,   265,   186,   269,   186,   238,   239,   236,   272,
       0,     0,     0,     0,   871,   176,   176,     0,     0,   203,
       0,     0,   332,     0,     0,   333,     0,     0,     0,     0,
       0,     0,     0,   277,     0,   953,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   544,     0,
       0,     0,   667,   439,   441,  1238,     0,     0,     0,  1658,
       0,   435,     0,     0,     0,   434,     0,   449,   540,     0,
       0,     0,     0,     0,   543,   402,   408,   445,   442,   403,
     404,   406,   407,   440,   443,   448,   539,   494,   491,   500,
     497,     0,     0,    17,    18,    19,    20,    21,     0,    14,
     485,     0,     0,   960,     0,   188,   191,   189,   190,     0,
     196,   195,   194,   197,   205,   206,   207,   210,   274,   186,
     274,     0,     0,     0,     0,   186,   270,   271,     0,     0,
     186,     0,   274,     0,     0,   249,   233,  1244,     0,     0,
    1232,  2267,   581,   921,   865,     0,   214,   215,     0,     0,
     291,   293,   288,   289,   285,   287,   284,   286,   283,     0,
     293,   304,   305,   301,   303,   300,   302,   295,     0,     0,
       0,   344,     0,   347,   349,   222,     0,   221,     0,   186,
       0,     0,   565,   636,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   562,   548,   553,     0,   549,   552,   551,
     645,     0,   644,   567,     0,    11,   172,   433,   410,   409,
       0,  1173,     0,     0,   447,  1666,  1664,  1665,  1661,  1663,
    1660,  1662,  1654,     0,     0,     0,   446,     0,     0,     0,
       0,     0,     0,     0,   668,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   165,   166,   167,   168,   169,   170,   545,   546,
     547,   460,     0,     0,   459,   469,     0,     0,   414,     0,
       0,   415,   405,   411,   413,   416,   417,   418,   419,   420,
     412,     0,     0,     0,     0,     0,     0,     0,    12,    93,
       0,   963,     0,   948,   198,     0,     0,   262,     0,   264,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   260,
       0,   186,   234,   237,   975,   712,   888,   975,     0,  2265,
    2267,  1167,  1793,   859,     0,   975,     0,     0,   315,   280,
       0,     0,   290,   307,   281,   306,     0,   299,     0,   322,
       0,   316,     0,   341,     0,   346,   336,     0,     0,   325,
     278,   335,     0,     0,   536,     0,     0,   533,   532,   535,
     531,   542,   527,   527,     0,     0,   527,     0,   550,     0,
     554,     0,   298,     0,   534,   541,   282,     0,  1239,  1733,
       0,     0,     0,     0,     0,   436,     0,     0,   450,     0,
       0,     0,     0,   452,   451,   470,   461,   476,   479,   480,
     477,   483,   482,   481,   471,   472,   473,   474,   475,   421,
     462,   466,   484,   478,   465,   484,   444,   495,   492,   501,
     498,   525,     0,    98,   486,    94,    95,    97,   488,     0,
       0,   235,     0,     0,     0,   242,   243,     0,   246,     0,
       0,   254,     0,   244,   224,   208,     0,   257,   276,   981,
       0,   976,   977,   975,     0,   872,  2266,  2264,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  2248,     0,  1359,  1358,     0,  1360,     0,
     396,  1357,  1274,     0,     5,  1356,   397,   394,     0,   399,
     174,   484,  1144,     0,     0,  1366,   125,   393,   392,     0,
       0,   387,   484,     0,  1310,  2241,     0,   398,   361,     0,
       3,     2,     0,   395,  1271,     0,     0,   388,   385,   400,
       0,     0,     0,     0,  1364,  1354,   391,     0,     0,     0,
       0,     0,     0,     0,     0,  1353,     0,     0,     0,   175,
       0,   384,   383,     0,     0,  2245,  2244,     0,     0,     0,
     137,     0,   390,   389,     0,     0,   386,   484,     0,     0,
     484,     0,   574,     0,     0,     0,     0,     0,     0,   484,
     820,  1241,     0,     0,  1155,     0,  2234,     0,   105,     0,
       0,   892,     0,     0,     0,     0,   821,     0,     0,  1824,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   683,
       0,     0,  2269,  2270,  2271,  2272,  2273,  2274,  2275,  2276,
    2277,  2278,  2279,  2280,  2281,  2282,  2283,  2284,  2285,  2286,
    2287,  2288,  2289,  2290,  2291,  2292,  2293,  2294,  2295,  2296,
    2297,  2298,  2299,  2300,  2301,  2302,  2303,  2304,  2305,  2306,
    2307,  2308,  2309,  2310,  2311,  2312,  2313,  2314,  2315,  2316,
    2317,   930,  2318,  2319,  2320,  2321,  2322,  2323,  2324,  2325,
    2326,  2327,  2328,  2329,  2330,  2331,  2332,  2333,  2334,  1135,
    1137,  1132,  1134,  1133,  1136,  2335,  2336,  1264,  2337,  1270,
    1269,  2338,  2339,  2340,  2341,  2342,  2343,  2344,  2345,  2346,
    2347,  1421,  2348,  2349,  2350,  2351,  2352,  2353,  2354,  2355,
    2356,  2268,   860,   585,     0,   925,     0,   923,     0,   343,
     216,   217,     0,   292,   297,     0,     0,     0,     0,   345,
     348,     0,   220,     0,     0,   566,     0,   640,     0,   642,
     506,     0,   504,     0,   527,     0,   505,     0,     0,   564,
       0,   561,   558,   529,   503,   568,     0,   171,  1735,  1736,
    1734,     0,   438,  1238,     0,  1659,  1238,   437,  1238,  1238,
    1238,  1238,  1238,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    93,   961,
       0,   211,   275,   226,     0,     0,   186,     0,     0,     0,
       0,     0,  1245,     0,     0,  1233,   380,   378,   379,  1268,
    1070,  1069,  1075,     0,  1633,  1634,     0,     0,  1294,   655,
     656,  1295,  1625,  1626,  1297,   847,  1107,  1112,  2243,   648,
     124,  2256,     0,     0,  1309,     7,     0,     6,     0,  2249,
    1108,     0,  1201,  1200,  1147,  1199,  1146,   432,  1367,  1355,
       0,  1265,   873,   422,  1795,  1361,   126,     0,  1111,   123,
       0,   827,    24,   650,   401,     0,   826,  1103,   828,     0,
    1365,   914,   913,   916,   912,   915,  2258,     0,   910,     0,
     649,  1007,   911,  2252,     0,  2242,   122,  1267,  1004,   715,
    1002,     0,   646,  2237,   763,   762,   764,   760,     0,     0,
    1266,  1017,   651,  1420,     0,  2224,  1415,  1418,  2214,  2217,
    2218,  2220,  2223,     0,     0,     0,     0,  1076,  1071,     0,
    1056,  1057,  1058,  1059,  1065,  1067,  1066,  1064,  1063,     0,
       0,     0,  1062,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1048,  1039,  1040,   990,
       0,   988,  1090,   430,    24,     0,  2239,   127,   647,     0,
    1242,  1240,  1166,     0,  1784,  1785,  1167,  1148,  1368,     0,
       0,     0,     0,     0,     0,     0,     0,    63,     0,   951,
       0,    69,     0,   103,   623,     0,   670,   669,     0,  1138,
    1024,  1142,     0,     0,  1091,  1259,     0,     0,  1145,   675,
     672,   673,     0,   677,   678,     0,   680,   681,     0,   676,
     985,   987,     0,     0,   986,   765,   983,   726,   979,   942,
       0,     0,     0,     0,   687,   688,     0,     0,   940,   937,
     938,   934,   935,   936,   929,   933,   932,     0,     0,     0,
       0,     0,     0,   589,   591,   583,   586,   587,   927,  2267,
     922,   924,   866,     0,   294,   296,   323,   317,     0,     0,
     326,   637,   639,     0,     0,     0,     0,   527,   511,     0,
     527,   527,     0,   555,     0,   291,     0,     0,  1763,  1650,
    1652,  1819,  1823,  1764,  1656,  1761,     0,     0,  1760,     0,
       0,     0,  1762,     0,     0,     0,     0,     0,     0,     0,
    2224,  1651,  1759,  1653,  1748,     0,  1737,  1739,  1743,  1746,
    1774,  1817,  1775,  1820,  2225,  2215,  1747,  1176,  1667,  1175,
    1174,  1177,  1179,  1178,  1172,   463,   464,   468,   453,     0,
     456,   467,     0,   455,   496,   493,   502,   499,   526,   487,
      96,   489,   949,     0,   247,   231,     0,   229,   255,   245,
     235,   258,   982,   176,   978,   889,   176,     0,     0,     0,
    1339,  1340,     0,     0,     0,  1311,  1314,  1316,  1317,  1318,
    1322,  1321,  1319,  1320,     0,     0,     0,  1312,  1313,     0,
       0,     0,     0,     0,     0,     0,     0,  1109,     0,    24,
    1196,  1198,  1197,     0,   425,   426,   423,   424,   995,     0,
       0,   366,    25,   360,     0,  1104,     0,  1103,     0,  1102,
       0,     0,     0,     0,     0,     0,  1011,  1794,     0,     0,
       0,     0,     0,     0,  2239,     0,     0,   138,     0,     0,
    1021,  1013,  1014,  1019,     0,     0,  2216,     0,  2227,  1416,
    1417,     0,     0,   939,   428,  2208,  1034,   350,     0,     0,
     575,   628,   627,   625,   630,  1042,   629,  1047,  1043,  1046,
     819,   811,   805,   817,   818,   803,   804,   812,   807,   813,
     806,   816,   810,   814,   809,   815,   802,   808,   795,   801,
    1044,  1045,     0,  1052,  1060,  1049,  1050,  1054,  1055,  1053,
    1051,  1061,     0,     0,     0,   829,     0,     0,     0,     0,
       0,   775,   774,   771,  2240,  2247,    24,  1162,  1163,  1164,
    1165,  1159,  1157,  1255,  1167,  1149,  1150,  1153,  1169,  2235,
       0,     0,     0,     0,    99,     0,   100,     0,     0,     0,
      74,     0,     0,     0,   112,   107,     0,   671,   919,     0,
     918,     0,   484,  1140,     0,   970,   971,   994,   965,   966,
     822,   992,  1093,  1261,     0,  1263,  1262,  1880,  1996,  1992,
    1998,  2030,  2010,  2001,  1960,  1922,  2049,  2016,  2024,  1913,
    2019,  1881,  1828,  2011,  1918,  1969,  2103,  1948,  1936,  1949,
    2047,  2050,  2018,  1972,  2053,  1840,  2110,  2046,  2074,  1851,
    2146,  1937,  2119,  1833,  2079,  1849,  1908,  1955,  1975,  2069,
    2097,  2102,  1832,  2027,  2055,  1844,  1846,  1869,  1886,  1906,
    1916,  1926,  1979,  1982,  2040,  2051,  2057,  2058,  2075,  2120,
    2131,  1831,  1862,  1885,  1884,  1892,  1894,  1902,  1912,  1933,
    1951,  1954,  1980,  1988,  2044,  2054,  2064,  2070,  2071,  2073,
    2098,  2128,  2139,  1852,  1855,  1866,  1872,  1874,  1879,  1883,
    1889,  1897,  1899,  1900,  1901,  1911,  1921,  1928,  1944,  1945,
    1956,  1974,  1978,  1991,  2007,  2038,  2048,  2052,  2059,  2067,
    2076,  2086,  2090,  2107,  2113,  2117,  2125,  2130,  2133,  1875,
    1993,  2035,  1860,  1861,  1878,  1882,  1888,  1890,  1904,  1905,
    1915,  1924,  1929,  1931,  1932,  1938,  1946,  1963,  1964,  1977,
    2005,  2009,  2012,  2017,  2021,  2029,  2036,  2037,  2042,  2060,
    2061,  2066,  2072,  2077,  2083,  2084,  2085,  2087,  2089,  2091,
    2100,  2122,  2123,  2124,  2129,  2145,  1835,  1987,  1995,  1997,
    2093,  1837,  1841,  1845,  1850,  1856,  1857,  1870,  1871,  1873,
    1876,  1887,  1903,  1923,  1925,  1935,  1939,  1941,  1942,  1950,
    1959,  1961,  1962,  1973,  1986,  2004,  2022,  2023,  2039,  2041,
    2045,  2056,  2078,  2088,  2096,  2118,  2121,  2135,  2136,  2137,
    1868,  1838,  1858,  1859,  1865,  1934,  1867,  1891,  1893,  1907,
    1984,  2108,  1917,  1919,  1927,  1930,  1952,  1953,  1958,  1965,
    1966,  1967,  2148,  1999,  2000,  2003,  2008,  2013,  2020,  2025,
    2026,  2028,  2034,  2063,  2065,  2081,  2092,  2094,  2095,  2099,
    2104,  2105,  2109,  2111,  2112,  2127,  2132,  2134,  2138,  2140,
    2144,  1994,  2143,  1834,  1836,  1839,  1843,  1853,  1877,  1895,
    1896,  1898,  1909,  1940,  1943,  1983,  1989,  2002,  2006,  2141,
    2142,  2043,  2062,  2068,  2080,  2082,  2101,  2106,  2116,  2126,
    1848,  1842,  1847,  1864,  1914,  1957,  1970,  1971,  2031,  2033,
    2115,  1990,  1947,  2014,  1863,  1910,  1920,  1985,  1968,  2015,
    1854,  1976,  1981,  2114,  2032,     0,  1826,  1829,  1830,   703,
       0,     0,     0,   692,   726,   726,   723,     0,     0,   727,
       0,    26,   691,   694,     0,   701,   697,   941,   931,  1791,
    1792,  1782,  1782,  1385,     0,     0,  1694,     0,     0,  1369,
       0,     0,  1370,  1413,     0,     0,  1414,     0,     0,  1733,
       0,  1383,     0,  1432,  1431,  1430,  1428,  1429,  1427,  1425,
    1422,  1512,  1511,  1423,  1424,  1433,  1715,  1426,  1798,  1797,
    1796,  1434,  2267,  2267,   602,   593,   584,     0,   588,  2267,
     926,   176,     0,   337,   219,     0,     0,  1674,  1672,  1673,
    1669,  1671,  1668,  1670,   528,     0,   527,     0,   515,   527,
       0,   508,   507,     0,     0,     0,   560,   559,   173,  1745,
    1744,  1682,  1680,  1681,  1677,  1679,  1676,  1678,  1655,     0,
    1733,     0,     0,  1580,     0,     0,  1751,  1749,  1750,  1580,
    1580,  1580,  1580,  1752,     0,     0,     0,  1529,  1723,     0,
    1740,     0,     0,     0,     0,  1807,  1808,  1809,  1810,  1811,
    1812,  1755,     0,     0,     0,     0,   458,   457,     0,     0,
     186,   228,   209,  1246,   176,  1234,     0,     0,     0,     0,
       0,     0,  1486,  1485,  1484,  1346,     0,  1352,  1348,  1350,
    1341,     0,  1589,  1338,  1334,  1308,  1307,     0,  1333,  1329,
       0,  1325,  1323,     0,  1632,     0,  1635,  1637,   659,     0,
     658,  1624,     0,  1627,  1629,  2257,  2254,     0,     0,  1275,
     484,   358,  1296,     0,     0,  1272,  1026,  1105,  1106,  1103,
    1099,  1103,     0,   917,     0,     0,   633,     0,     0,     0,
    1005,  1003,   717,   718,     0,   722,     0,     0,  2238,  2246,
     761,     0,   142,     0,  1015,  1022,     0,     0,  1030,  2219,
    2232,     0,  2230,  1419,  2222,  2221,     0,     0,     0,  1036,
     353,     0,     0,     0,     0,    24,  1072,  1073,   578,     0,
       0,     0,   796,   797,  1041,   991,   989,   830,   431,     0,
    1082,   772,   776,   773,   777,   381,     0,  1167,  1256,  1171,
    1156,  1151,     0,     0,  1152,  2267,     0,     0,     0,     0,
       0,     0,     0,    64,    93,     0,     0,   118,   113,     0,
     108,     0,   115,   109,   903,   895,   901,     0,  1139,     0,
    1141,  1143,     0,     0,   974,     0,     0,     0,     0,  1092,
    1260,     0,     0,  1825,  1827,  2267,   674,   679,   682,   695,
     693,   652,     0,   750,   748,   746,   744,   754,   752,     0,
       0,   742,   792,   740,   725,   736,   734,   790,   766,     0,
     728,   738,   984,   980,     0,     0,     0,     0,   700,     0,
       0,     0,     0,     0,     0,     0,  1640,     0,  1507,  1508,
    1803,  1465,  1529,     0,     0,     0,  1801,     0,  1445,  1440,
    1439,  1452,  1451,  1456,  1456,  1454,  1455,  1446,  1441,     0,
       0,  1447,  1448,  1716,  2150,     0,     0,     0,   590,   592,
       0,     0,   605,   597,   599,     0,   594,   595,     0,     0,
     613,   615,     0,     0,   611,   928,   867,   218,     0,   641,
     643,   638,     0,     0,   527,   517,     0,   512,     0,     0,
     527,   527,   557,   556,     0,     0,  1772,  1656,     0,     0,
    1747,  1582,  1583,  1581,     0,  1776,     0,     0,     0,     0,
       0,     0,     0,  1738,     0,  1518,  1519,  1521,  1524,     0,
    1530,  1531,     0,     0,  1580,  1725,  1719,  1741,  1757,  1758,
    1756,  1754,     0,     0,     0,  2226,   454,   490,     0,   230,
    1202,   890,  1180,     0,     0,     0,     0,  1346,     0,     0,
       0,  1342,     0,     0,     0,  1336,  1620,  1618,  1587,  1599,
    1601,  1605,  1607,  1598,  1592,  1597,  1611,  1590,  1619,  1595,
    1610,  1596,  1617,  1609,  1492,  1584,  1585,  1586,     0,  1331,
    1327,     0,     0,  1315,     0,     0,   657,     0,     0,     0,
    2253,     0,     4,     8,    10,     0,   484,   427,     0,     0,
       0,  1023,  1101,  1100,     0,     0,     0,     0,     0,     0,
       0,     0,   716,     0,     0,   159,   157,     0,     0,   139,
       0,   149,   155,   726,   144,   146,     0,  1020,  1031,  1032,
       0,     0,  2228,   429,     0,  2209,  2210,  1035,     0,     0,
    1033,   352,   357,   635,   351,     0,   354,   359,     0,   484,
    1391,   626,   624,     0,   799,  1081,  1083,     0,   382,  1160,
    1158,     0,  1170,  1154,     0,     0,  1251,     0,     0,     0,
     101,     0,     0,    75,    81,    71,  2267,  2267,   111,   106,
     120,   116,     0,   110,   793,   904,   652,  2267,   894,   893,
     902,  1025,     0,     0,   972,   973,   967,   993,   484,  1098,
    1094,  1095,  1097,  2147,  2149,   704,   698,   696,     0,    24,
       0,  2267,  2267,  2267,  2267,  2267,  2267,   756,   730,   758,
     732,  2267,  2267,  2267,  2267,     0,   724,   729,  2267,   652,
     788,   786,   789,   787,     0,     0,    46,    44,    41,    35,
      39,    43,    38,    31,    40,     0,    34,    37,    32,    42,
      33,    45,    36,     0,    29,    47,   780,     0,   702,  1783,
       0,  1781,  1733,  1779,  1720,  1721,  1713,  1699,  1714,     0,
       0,     0,  1068,  1506,  1509,     0,     0,     0,  1403,  1375,
    1806,  1805,  1804,     0,     0,     0,  1450,  1453,     0,     0,
       0,     0,     0,  1398,     0,  1397,     0,  1399,  1394,  1395,
    1396,  1387,  1388,     0,     0,     0,   604,   609,     0,     0,
    2267,  2267,   582,   596,   619,   607,   621,  2267,  2267,   617,
     601,   612,   859,   338,     0,   527,     0,   516,   527,     0,
     527,   527,   510,   509,  1689,  1687,  1688,  1684,  1686,  1683,
    1685,  1657,     0,     0,     0,     0,  1773,     0,     0,     0,
    1771,     0,     0,     0,     0,  1753,  1770,     0,  1522,     0,
    1649,  1525,     0,     0,     0,     0,  1517,  1535,  1537,  1539,
    1579,  1578,  1577,  1541,  1557,     0,  1532,  1533,  1728,  1298,
       0,     0,     0,  1818,     0,  1822,   212,     0,  1228,  1247,
     859,     0,  1235,  1228,     0,  1641,     0,  1474,     0,  1477,
    1644,     0,  1482,     0,     0,  1343,  1344,     0,     0,  1347,
    1349,  1351,     0,  1335,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1490,  1489,  1488,     0,  1493,  1494,
       0,  1330,     0,  1324,  1326,  1636,     0,  1638,  1628,     0,
    1630,  2255,  1304,     0,  1300,     0,     0,  1305,   874,     0,
       0,     0,     0,     0,  1362,  2260,  2259,   634,     0,     0,
      48,     0,   719,   721,   720,  1363,   726,  2267,  2267,   151,
     660,   161,   153,   163,   143,   150,  2267,     0,     0,     0,
       0,     0,  2231,     0,     0,     0,     0,     0,     0,  1074,
       0,  1392,   576,     0,   798,  1079,     0,  1257,  1258,  2236,
       0,    93,     0,    65,     0,     0,     0,    78,     0,    93,
      93,   119,   114,  2267,  2267,   104,     0,   905,   899,   907,
     906,   896,   572,   954,     0,     0,     0,   706,   685,   699,
     653,   767,     0,   751,   749,   747,   745,   755,   753,     0,
    2267,     0,  2267,   743,   741,   737,   735,   791,   739,    24,
     781,     0,     0,     0,    27,     0,  1786,     0,  1700,     0,
       0,  1712,  1695,  1711,  1510,     0,  1467,     0,  1402,     0,
       0,  1802,     0,  1799,     0,  1458,  1462,  1438,  1460,  1463,
       0,  1449,  1717,     0,     0,     0,     0,     0,     0,  2151,
    1401,  1400,  1389,  1384,  1386,  1437,     0,     0,   606,   603,
     598,   600,     0,  2267,  2267,   614,   616,  2267,  2267,     0,
    1675,   518,     0,   522,     0,     0,   514,   513,     0,     0,
       0,     0,     0,     0,  1769,  1777,  1765,  1766,  1767,  1768,
    1526,     0,  1520,  1540,  1544,     0,  1557,  1543,     0,     0,
    1558,  1573,  1570,  1571,  1568,  1576,  1575,  1569,  1572,     0,
       0,     0,     0,     0,  1574,     0,     0,     0,  1514,  1515,
    1742,     0,  1534,  1528,  1299,  1726,  1408,  1404,  1405,  1410,
    1409,  1724,  1298,     0,     0,  1226,  1227,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1225,     0,
       0,  1213,  1214,  1215,  1212,  1217,  1218,  1219,  1216,  1203,
    1194,     0,     0,  1250,     0,  2267,     0,  1189,     0,     0,
       0,     0,     0,     0,     0,  1181,  1182,     0,  1113,  1645,
       0,  1646,     0,     0,     0,     0,  1481,  1480,  1346,  1479,
    1471,  1337,  1621,     0,     0,     0,     0,     0,     0,  1622,
    1614,     0,     0,     0,  1614,  1650,  1487,  1500,  1505,     0,
    1502,  1499,  1501,     0,  1503,  1491,  1495,  1496,  1346,  1332,
    1328,     0,     0,  1303,  1302,     0,  1287,     9,     0,  1277,
     875,  1110,   364,  1277,     0,     0,  2251,     0,     0,  1006,
      49,     0,   778,   160,   158,     0,  2267,     0,     0,     0,
    2267,   156,   145,     0,   148,   147,     0,  1012,  1016,     0,
    2213,  2212,  2211,     0,     0,   356,     0,   579,     0,  2267,
     800,     0,   652,  1161,     0,  1252,    70,     0,     0,   102,
      68,    93,    76,    82,     0,   121,   117,   794,  2267,   909,
     652,   908,     0,   569,     0,   824,   825,   823,  1096,   709,
     707,     0,   689,   686,     0,   757,   731,   759,   733,   768,
     784,   785,   782,   783,    30,    28,     0,  1780,  1729,  1701,
    1697,  1696,     0,  1466,  1733,  1469,     0,  1377,  1372,  1371,
    1374,     0,     0,  1457,     0,     0,  1729,     0,     0,  2188,
    2186,     0,     0,  2170,  2185,     0,     0,  2187,     0,     0,
       0,     0,     0,  2224,  2184,  2176,  2203,  2204,     0,  2168,
    2171,  2172,  2183,  2175,  2205,     0,  2161,  2160,  2164,  2166,
       0,  2159,     0,  2162,  2153,     0,     0,   610,   608,   620,
     622,   618,     0,     0,   527,     0,   527,   527,     0,  1732,
       0,  1657,     0,     0,     0,  1523,  1542,  1536,  1538,  1545,
    1547,  1545,     0,  1552,  1545,     0,  1550,  1545,     0,  1560,
    1559,     0,  1561,     0,  1513,     0,  1412,  1411,  1407,  1727,
       0,   235,  1220,  1221,  1222,  1224,  1207,  1205,  1204,  1208,
    1209,  1206,  1223,  1210,  1211,  1195,   999,  1230,   996,     0,
       0,  1248,     0,  1193,  1192,  1187,  1185,  1184,  1188,  1186,
    1190,  1191,  1183,  1236,     0,  1472,  1478,  1648,  1641,  1483,
    1345,  1588,  1600,     0,  1602,  1604,     0,  1606,     0,     0,
       0,  1612,  1591,  1616,     0,  1473,  1475,     0,  1497,  1498,
    1639,  1631,  1301,     0,     0,  1293,  1288,  1289,  1306,     0,
    1284,  1285,     0,     0,  1298,  1278,  1279,     0,    24,  1273,
       0,     0,  1029,     0,    50,  1009,     0,    24,   162,   152,
       0,   662,   664,   164,   154,   778,     0,  2229,  1038,     0,
     355,  1393,     0,  1080,    24,     0,     0,    66,     0,    79,
      88,     0,    72,   900,   897,   573,  2267,   968,     0,  2267,
     705,   684,   690,   652,  1790,     0,  1788,     0,     0,  1702,
    1698,  1468,     0,  1470,  1464,     0,  1376,     0,  1800,  1459,
    1461,  1436,     0,  2174,  2173,     0,     0,  1580,     0,  1580,
    1580,  1580,  1580,  2177,     0,     0,  2157,     0,     0,     0,
       0,  2190,  2158,     0,     0,     0,     0,     0,     0,  2152,
    1390,  1442,   869,   868,   339,   519,     0,     0,   524,   523,
    1690,  1813,  1816,  1814,  1527,     0,  1564,  1566,     0,  1553,
    1556,  1555,  1563,     0,  1565,  1545,     0,  1516,  1406,  1821,
     213,  1001,  1000,   998,     0,  1229,  1114,  1118,  1120,     0,
    1124,     0,  1122,  1126,  1115,  1116,     0,   891,     0,     0,
    1642,  1647,     0,     0,  1623,  1615,  1593,     0,  1594,     0,
       0,  1291,  1286,  1292,  1290,  1283,  1282,  1281,  1276,  1280,
     365,   362,     0,  1027,     0,     0,     0,  1008,   779,   140,
     661,    24,  1018,  1037,   577,  1077,    67,  1253,    84,     0,
       0,    77,    88,    88,  2267,   570,     0,     0,   708,   769,
       0,  1787,  1730,  1723,     0,  1378,     0,  1723,  2201,     0,
       0,  2206,     0,     0,     0,     0,     0,     0,     0,     0,
    2169,  2192,  2193,  2191,  2189,  2167,     0,  2163,  2165,  2154,
    2155,  1443,     0,  1435,   527,   527,  1546,  1778,  1548,     0,
    1551,  1549,  1567,     0,   997,  2267,  2267,  1128,  2267,  1130,
    2267,  2267,  1117,  1249,  1237,     0,  1603,     0,  1613,     0,
    1504,   367,  1028,  2250,     0,     0,     0,     0,     0,     0,
      55,     0,    54,     0,    52,     0,     0,   141,  1084,    88,
      93,    88,    89,    83,    73,   898,     0,     0,   710,    24,
    1789,  1722,  1731,  1382,     0,  1379,  1381,  1703,  2202,     0,
       0,  2200,     0,     0,     0,     0,     0,  2178,  2199,     0,
    1444,   521,   520,  1554,  1562,  1119,  1121,  2267,  1125,  2267,
    1123,  1127,  1643,  1608,  1476,   369,   374,   372,   363,     0,
     370,   376,    57,    62,    59,    61,    58,    60,    56,     0,
      51,     0,   663,   665,  1088,  1078,     0,  1086,  1254,    85,
      80,   571,   969,  2267,   770,     0,  1373,     0,  1704,  1718,
    2198,  2207,  2194,  2195,  2196,  2197,     0,  2179,     0,     0,
    1129,  1131,  2267,  2267,   368,   371,  2267,    53,     0,  2267,
    1085,  1087,     0,   706,  1380,     0,  1708,  1705,  1706,     0,
       0,  2156,   375,   373,   377,     0,  1089,    86,   711,     0,
       0,     0,  2181,     0,  2180,  1010,    90,     0,  1709,  1707,
       0,    92,     0,    87,     0,  2182,    91,  1710
};

/* YYDEFGOTO[NTERM-NUM]. */
static const short yydefgoto[] =
{
      -1,   822,   823,   824,   825,  1046,  2422,  2423,   178,   318,
     179,  1411,  1412,  2245,  2583,  3632,  3109,  3110,  3535,  3633,
    3634,   826,  1187,  3147,  2840,  3553,  2184,  2838,  3400,  3151,
    3549,  2839,  3401,  3640,  3742,  3766,  3551,  3773,   644,   645,
     646,  1535,  2499,   827,  1546,  1192,  1544,  2192,  2509,  2189,
    2507,  2512,  2844,  1545,  2506,  2193,  2843,   828,     9,    28,
      29,    30,    31,    32,   830,  1109,  2122,  1437,  2449,  2453,
    2454,  2450,  2451,  3116,  3120,  2806,  2798,  2797,  2799,  2802,
     491,   268,   597,   831,    55,    56,    11,    41,   113,    70,
      71,    72,    73,   194,   332,    74,    75,   240,   337,   226,
    1009,   515,  3004,   368,   932,  2308,   396,   397,   227,   350,
     339,   345,  1356,  1357,   117,   533,   118,   119,   356,   228,
     352,   338,   340,   517,   229,   254,   571,   242,   245,   243,
     244,   378,   549,   550,   552,   557,   935,   246,   247,   387,
     554,   190,    12,    51,   149,   150,   151,   941,  2939,   152,
     250,   238,   390,   391,   392,   393,  2145,   832,   833,   834,
     835,  1067,  3621,  3368,  1413,  3688,  3689,  3690,  3733,  3732,
    3736,   836,   837,   838,   839,   840,   841,   842,  1057,   492,
    1062,  1405,  1406,  1453,  1162,  1454,   295,   296,   297,   298,
     299,   449,   493,  1339,   494,   495,   496,   497,   498,   499,
     500,   986,   180,   509,   996,   998,  2038,   181,   503,   992,
     502,   991,   505,   994,   504,   993,   950,   964,   300,   301,
     183,   302,   416,   417,   418,   419,   401,   421,   843,  3406,
    3646,  3163,   844,  1129,  2148,  3139,  2480,    87,   235,   543,
    1955,  1255,  1256,  1257,  1952,  1953,  2295,  2296,  2297,  2640,
    2641,  1956,  1957,  2291,  2644,  2636,  2303,  2304,  2647,  2648,
    2937,  2933,  2934,   845,  1465,    57,  2107,  2108,  2474,   402,
     423,  1101,  1167,  1038,  1089,  1072,  1111,  2539,   184,  1039,
    1029,  2079,  2801,    59,   303,   846,  1197,   847,  1210,  1211,
     848,   849,   850,   851,  1218,  3172,  1239,  3411,  1240,  2219,
    1241,  2536,  1242,  2858,  1243,  2248,   852,  2215,  2857,  3171,
    3409,  3408,  3713,    88,    13,   853,  1431,  2112,  2113,  2114,
    2238,  1900,  2239,  2240,  2870,  2872,  2554,  2553,  2558,  2552,
    2551,  2544,  2543,  2542,  2541,  2546,  2545,  2548,  2550,   854,
     855,  1107,   856,  1896,  1225,  3649,   857,  1513,  3377,  2585,
    2586,  2241,  2555,  2515,  2846,  1156,  1493,  2152,  2483,  2153,
    1489,   858,   859,  1203,  2207,  3167,   860,   861,   862,   863,
      14,    45,    15,    16,    17,    89,    90,   864,    91,    18,
     923,    19,    92,    93,   129,   545,  1961,  2652,  3463,    94,
     125,   361,   865,  2779,    20,    21,    22,    23,    24,    40,
      62,    95,   673,  2044,  2720,   866,  1198,  2519,  2196,  2517,
    3554,  3158,  2197,  2516,  2849,  3160,   867,   868,   869,  1083,
    1084,  1549,    96,   236,   544,   926,   927,  1259,  1959,   870,
    1244,  1245,   871,  1908,  1246,   304,    64,    65,    66,    67,
    1556,   155,   109,    68,   106,   186,   187,  1557,  1558,  2526,
    1559,   670,   671,  1227,   672,  1228,  1160,  1161,  1560,  1561,
    1409,  3307,  3308,  3493,  1099,  1100,   872,  1426,  3537,   873,
    3128,   874,  1441,  1442,  1443,  2128,  2126,   875,   876,  2431,
    2460,   877,  2139,  2470,   878,  1157,  1158,   879,  1022,   880,
    2596,   881,  3638,  3142,   882,  2487,  3705,  3706,  3707,  3739,
    1164,   883,  1562,  2209,  2530,  2531,   884,  1419,  2099,  1037,
    1398,   885,   886,   887,  2722,  3311,  3504,  3505,  3605,  3606,
    3610,  3608,  3611,  3677,  3679,   888,   889,  1551,  2201,   890,
    1553,  1524,  1525,  1526,  2174,   891,  1177,   892,   893,  2167,
    1521,  1173,   193,  1527,  1528,   305,  2723,  3045,  3046,  3029,
    1054,  1055,  2718,  3030,  3033,    97,   124,   537,  1366,  2372,
    3047,  3508,   431,   894,  1171,    98,   121,   534,  1363,  2370,
    3034,  3506,  2719,  1191,  2831,  3396,  3639,  2169,   895,   896,
     897,   898,   899,  1070,  2429,  1048,  2425,  3364,  3365,  3366,
    3521,  3355,  3356,  3357,   900,  2995,  2773,  2774,  2776,  2063,
     901,   902,  1375,  1376,  1377,  2072,  2411,  1378,  2408,  2069,
    1379,  2384,  2064,  1380,  1381,  1382,  2376,  2381,  1383,  2058,
    2059,   903,  1079,  1059,   904,  1933,  1934,  2263,  3199,  3427,
    2900,  3196,  3654,  3655,  1935,  2285,  1914,  2632,  2923,  3245,
    2822,  3138,  2633,  1936,  1937,  2355,  2997,  2998,  2999,  3288,
    1938,  1939,  1450,   905,  1116,   906,  1252,  1940,  1941,  2279,
    3593,  2280,  2281,  2282,  2616,  2904,  2907,  2908,  1942,  2606,
    2895,  3424,  2052,  2053,  3084,  2726,  3345,  2727,  2054,  2731,
    2065,  2758,  2066,  2759,  3085,  3086,  3087,  3088,  1943,  2257,
    2258,  2603,  1944,  2992,  2706,  2988,  2350,  2017,  2345,  2346,
    2347,  2961,  2018,  2351,  2707,  2993,  2696,  2697,  2698,  2699,
    2700,  3476,  3269,  3596,  2701,  3478,  3479,  2986,  2702,  2987,
    2703,  2334,  2404,  2405,  2406,  3339,  2407,  3063,  3070,  3515,
    2728,  1026,  2909,  3051,  3238,  2730,  2691,  1312,   306,  1313,
    1998,   442,   951,  1974,  1999,  2671,    39,   907,   908,  3191,
    3420,  2888,  3419,  3719,  3747,  3748,  2892,  2597,  1945,  2598,
    2621,  3206,   600,  2593,  2594,  2356,  2709,  3418,  3195,  1314,
     971,  1315,  1316,  2989,  2704,  1318,  1319,  2336,  3598,   909,
     910,  2250,  2595,  3187,  3415,  3416,  1911,   911,  1065,  1947,
    1948,  2267,  2902,  1949,  1950,  2612,  2031,  2329,  1320,  1321,
    1322,  1323,   912,  1206,  1885,  1886,  1887,  2211,  1888,  2212,
    1951,  2622,  3244,  3459,  2919,  3241,  3242,  3243,  3240,  3228,
    3229,  3230,  3231,  3232,  3233,  3572,   913,  2137,  2465,  2466,
    1117,  1324,  1325,  1119,  1120,  1121,  1326,  1122,  1448,  2131,
    2132,    25,   915,  1179,  2175,  1434,  1515,   916,   917,  2790,
     918,  2420,  1042,  2086,   919,   920,    35,   538,   539,   540,
     541,   542,   921
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -2828
static const short yypact[] =
{
     851,  1583, -2828,   317,   317,   537, -2828, -2828,   537, -2828,
     -10, -2828, -2828, -2828,   385, -2828,   851, -2828, -2828, -2828,
   -2828, -2828,   -21, -2828, -2828, -2828, -2828, -2828,   434,   455,
   -2828,   604, -2828, -2828, -2828, -2828, -2828, -2828,  -152, -2828,
     598,   519, -2828, -2828, -2828,   409, -2828, -2828, -2828, -2828,
   -2828,   266,   317, -2828,   317,   701,   -10, -2828,  -202, -2828,
   -2828, -2828, -2828, -2828, -2828,  1357,   432, -2828, -2828, -2828,
     995,   707,   317, -2828, -2828,  1041,   317, -2828, -2828,   317,
     317, -2828, -2828, -2828,   317,   317, -2828, -2828, -2828, -2828,
     409, -2828, -2828, -2828, -2828, -2828, -2828, -2828, -2828, -2828,
    3326, -2828,   432, -2828,   334,  3734, -2828, -2828,   618, -2828,
   -2828,  1138,   519,   619, -2828, -2828, -2828, -2828, -2828, 10535,
   -2828,   317,   724,  1052,   317,   -10, -2828, -2828, -2828,   317,
   -2828, -2828,   885,   757,  1039, -2828, -2828,   830, -2828,   845,
   -2828,   828, -2828, -2828,   883, -2828, -2828, -2828, -2828, -2828,
   -2828, -2828, -2828, -2828, -2828,   826, -2828, -2828, -2828,   893,
     912,   933,   947,   965,   984,   994,  1014,  1069,  1075,  3734,
    1083,  5161,  1088,  1094,  1114,  1123,  1126,  1135,  1720,  1320,
   -2828, -2828, -2828, -2828,   955, -2828,   134, -2828,  3734, -2828,
     166, -2828, -2828, -2828,   159, -2828, -2828, -2828,   801, -2828,
   -2828, -2828, -2828, -2828, -2828,   885,  1147,  1154,  1165, -2828,
    1039, -2828, -2828,  1179, -2828,  1193, -2828,   989, -2828, -2828,
    1196, -2828, -2828, -2828, -2828, -2828, -2828, -2828, -2828, -2828,
    1215,  1560,   317,  1224, -2828,   -10,   -10,  1236,   317, -2828,
     -53,  1593, -2828,   949,  1047, -2828,   964,  1143,  1655,  1707,
     317,  1721,  1730, -2828,  1099, -2828,    47,    47,    47,    47,
      47,  5161,  1647,  1552,    79,  5161,  1098,  5161, -2828,  5161,
    5161,  5161, -2828, -2828, -2828,  1206,  1306,  1309,  5161,  1149,
    1314, -2828,  5161,  5161,  1335, -2828,  1343, -2828,  1094,  1346,
    1365,  1376,  1383,  1841,  9233, -2828, -2828, -2828, -2828, -2828,
   -2828, -2828, -2828, -2828,  1403, -2828, -2828, -2828, -2828, -2828,
   -2828,   780,   780, -2828, -2828, -2828, -2828, -2828,  3734, -2828,
   -2828,   317,  3734,  1370,   144, -2828, -2828, -2828, -2828,  1867,
   -2828, -2828, -2828, -2828, -2828, -2828, -2828, -2828,  1416, -2828,
    1416,   -53,  1878,  1879,  1880, -2828, -2828, -2828,  1884,  1886,
     519,  1721,  1416,  1890,  1250, -2828,  1815, -2828,  1484,  1448,
   -2828,  1516, -2828, -2828, -2828,  1262, -2828, -2828,  1907,  1491,
   -2828,  1458, -2828, -2828, -2828, -2828, -2828, -2828, -2828,  1143,
    1458, -2828, -2828, -2828, -2828, -2828, -2828,  1462,   143,   168,
     452, -2828,  2168, -2828, -2828, -2828,  1468,  1939,   189, -2828,
    1469,   293, -2828,   -90,  1509,  1512,   377,   397,  5760,  1519,
    1520,    86,  1146, -2828, -2828,    96,  1521, -2828, -2828, -2828,
   -2828,   405, -2828, -2828,  8182, -2828,  4429,  9543,  2601,  2601,
    5161, -2828,  1445,  5161,  9233,  1487, -2828, -2828, -2828, -2828,
   -2828, -2828, -2828,  1295,  1951,  8241,  9233,  1445,  1953,   539,
    5161,  5161,  5161,  5161, -2828,  5161,  5161,  5161,  5161,  5161,
    5161,  5161,  5161,  5161,  5161,  5161,  5161,  5161,  5161,  5161,
    5161,  5161, -2828, -2828, -2828, -2828, -2828, -2828, -2828, -2828,
   -2828, -2828,  5161,  5161, -2828, -2828,  1494,  5161, -2828,  5161,
    1506, -2828, -2828, -2828, -2828, -2828, -2828, -2828, -2828, -2828,
   -2828,   780,  5161,  5161,  5161,  5161,  1542,  1983,  1720,  3583,
    1513, -2828,  3734,  1481, -2828,  1323,  1971, -2828,  1329, -2828,
    1974,  1564,  1565,   415,  1692,   421,   425,   528,  1533, -2828,
     429, -2828, -2828, -2828,   317, -2828, -2828,   317,  1610, -2828,
    7420,   619,  7723,  1984,  -275,   317,  2005,   690, -2828, -2828,
    1047,  2002, -2828, -2828, -2828, -2828,  2003, -2828,  2006, -2828,
    2008, -2828,   317, -2828,   317, -2828, -2828,  1721,  2009, -2828,
   -2828, -2828,   317,    47, -2828,  3734,    45, -2828, -2828, -2828,
   -2828, -2828,  1149,  1149,  2011,   -68,  1149,  1326, -2828,  2013,
    1401,  1337, -2828,    79, -2828, -2828, -2828,  1597,  9233,   631,
    1598,  8432,  2018,  1149,  1601, -2828,  1602,  1603, -2828,  8453,
    8490,  8511,  8757,  9156,  9425,  9543,  9591,  9602,  9679,  9753,
    9634,  9813,  9856,  9364,  2601,  2601,  3688,  3688,  3907,  9233,
    8818,  8988,  1445,  9233,  9060,  1445, -2828,  9233,  9233,  9233,
    9233, -2828,  2023, -2828, -2828,  2045, -2828,  9233, -2828,   175,
    3734, -2828,  1607,  2032,   690, -2828, -2828,  2029, -2828,  1575,
    2031, -2828,  2033, -2828, -2828, -2828,  2034, -2828, -2828,  1392,
    1618,  2058, -2828,   317,  1621, -2828, -2828, -2828,   780,   780,
     780,   317,   468,   317,  1454,   186,   186,  1483,   317,   317,
     186,   186,   317, -2828,  1454, -2828, -2828,   317, -2828,   959,
   -2828, -2828, -2828,   186, -2828, -2828, -2828, -2828,   317, -2828,
   -2828, -2828, -2828,   162,   162,  5161, -2828, -2828, -2828,  1483,
    1483, -2828, -2828,   186, -2828, -2828,   186, -2828, -2828,   317,
   -2828, -2828,   186, -2828, -2828,   780,   186, -2828, -2828,  5161,
     186,   780,   317,   780,   186, -2828, -2828,   249,   186,   186,
     249,   186,   317,   249,   186, -2828,   186,   186,   186, -2828,
    1454, -2828, -2828,   780,   186, -2828, -2828,   186,    39,   317,
   -2828,  1483, -2828, -2828,   186,   942, -2828, -2828,   780,  1391,
   -2828,   186, -2828,  1768,   780,  5161,    47,    47,   186, -2828,
   -2828,   468,   780,   956, -2828,  5161, -2828,  1345,  5161,   186,
      72, -2828,  5161,   186,  2046,   780, -2828,   186,  5161, -2828,
    5161,   162,   317,   186,   317,    47,   186,   317,    47, -2828,
     317,   245, -2828, -2828, -2828, -2828, -2828, -2828, -2828, -2828,
   -2828, -2828, -2828, -2828, -2828, -2828, -2828, -2828, -2828, -2828,
   -2828, -2828, -2828, -2828, -2828, -2828, -2828, -2828, -2828, -2828,
   -2828, -2828, -2828, -2828, -2828, -2828, -2828, -2828, -2828, -2828,
   -2828, -2828, -2828, -2828, -2828, -2828, -2828, -2828, -2828, -2828,
   -2828,   761, -2828, -2828, -2828, -2828, -2828, -2828, -2828, -2828,
   -2828, -2828, -2828, -2828, -2828, -2828, -2828, -2828, -2828, -2828,
   -2828, -2828, -2828, -2828, -2828, -2828, -2828, -2828, -2828, -2828,
   -2828, -2828, -2828, -2828, -2828, -2828, -2828, -2828, -2828, -2828,
   -2828,  1158, -2828, -2828, -2828, -2828, -2828, -2828, -2828, -2828,
   -2828, -2828, -2828,   977,   317, -2828,   793, -2828,  1629, -2828,
   -2828, -2828,  1723, -2828, -2828,  1631,  1636,  1638,  1642, -2828,
   -2828,  1414,  2083,  1645,  1646, -2828,   535, -2828,  1611, -2828,
   -2828,  1418, -2828,   427,  1149,  2068, -2828,  1651,     8, -2828,
    2071, -2828,  1459, -2828, -2828, -2828,  1424, -2828, -2828, -2828,
   -2828, 10194, -2828,  1206,  1656, -2828,  1206, -2828,  1206,  1206,
    1206,  1206,  1206,  2076,  2077,  2080,  5161,  1664,  2084,  5161,
    1666,  1668,  1671,  1672,  1673,  1674,  1675,  3583,  3583, -2828,
     184, -2828, -2828, -2828,  1767,  1678, -2828,  1680,  1681,  1453,
    1693,   317, -2828,   317,  1696, -2828, -2828, -2828, -2828, -2828,
   -2828, -2828, -2828,   343,  1486,   183,  1537,  1677, -2828, -2828,
   -2828, -2828,  1493,   327, -2828, -2828, -2828, -2828, -2828, -2828,
   -2828, -2828,  2144,  1479, -2828, -2828,  1659, -2828,  1483, -2828,
    1634,   241, -2828, -2828, -2828,  1649, -2828,  9233, -2828, -2828,
    1522, -2828, -2828,  4256, -2828, -2828, -2828,   780, -2828, -2828,
    1483, -2828,  -100, -2828, -2828,  1847, -2828,   247, -2828,  1658,
   -2828, -2828, -2828, -2828,  2161, -2828, -2828,   735, -2828,  1502,
   -2828,  1503,  2161, -2828,  1526, -2828, -2828, -2828,  1701,    89,
   -2828,  1665, -2828,  1466, -2828, -2828, -2828, -2828,  1470,   640,
   -2828,  -204, -2828,  1507,  1600,  1676,  1800,  1523, -2828, -2828,
    1518, -2828, -2828,  5161,    92,  1017,  5161, -2828,   105,   186,
   -2828, -2828, -2828, -2828, -2828, -2828, -2828, -2828, -2828,   139,
     139,   139, -2828,   139,   641,   139,   139,  1535,  -100,  1535,
    1535,  1153,  1153,  1535,  1535,  -100, -2828,  2177, -2828,  1717,
     281, -2828,  2181, -2828,  -100,   104,    51, -2828, -2828,  5161,
   -2828, -2828, -2828,  1113, -2828, -2828,   619,  5161, -2828,  5161,
    1709,  1710,  1711,  1712,  1632,  1713,   956, -2828,  1797,  1073,
    1559, -2828,  1569, -2828, -2828,   317, -2828, -2828,  1177, -2828,
    2191, -2828,  2187,   317, -2828,   680,  6781,  1582, -2828, -2828,
    2205, -2828,  1508,  2205,  2206,  1510,  2205,  2206,  5161,  2205,
   -2828, -2828,   241,   780, -2828, -2828,  1742,   524, -2828, -2828,
    1734,   780,  5161,  1736, -2828, -2828,  2188,  2195,  2102, -2828,
   -2828, -2828, -2828, -2828, -2828, -2828, -2828,  1197,  1197,   186,
     186,   186,  2749, -2828, -2828,  2089,   977, -2828, -2828,   800,
   -2828, -2828, -2828,  1716, -2828, -2828, -2828, -2828,  3326,  1721,
   -2828, -2828,  1570,   317,  1195,  2207,    53,  1149, -2828,   412,
    1149,  1149,  1699,  1599,  1733, -2828, 10035, 10035, -2828,  1507,
   -2828, -2828, -2828, -2828,  1245, -2828,  9927,  1763, -2828,  1769,
    1773,  1774, -2828,  1774,  1774,  1775,  1780,  1781,  1782,   317,
     -34, -2828, -2828, -2828, -2828,   135, -2828,    58,  1985, -2828,
   -2828,  1245, -2828,  1245,  1794, -2828, -2828, -2828, -2828, -2828,
   -2828, -2828, -2828, -2828, -2828, -2828, -2828, -2828,  9233,   430,
   -2828, -2828,   443, -2828, -2828, -2828, -2828, -2828, -2828, -2828,
   -2828, -2828, -2828,  1757, -2828, -2828,   446, -2828, -2828, -2828,
   -2828, -2828, -2828,   -10, -2828, -2828,   -10,  1023,   176,  2241,
   -2828, -2828,   603,   179,   798,  2265, -2828, -2828, -2828, -2828,
   -2828, -2828, -2828, -2828,   317,  1735,   317, -2828, -2828,  1744,
     317,  1754,   317,   317,  1483,  1633,  1798, -2828,  1802,    91,
   -2828, -2828, -2828,  1483, -2828, -2828,  2279, -2828, -2828,  1613,
    1804, -2828, -2828, -2828,  1017, -2828,  1198,  2244,  1198, -2828,
     956,   249,  5161,  5161,  5161,  1805, -2828, -2828,   780,   780,
    1483,  1616,   956,    47,  1581,    39,   780, -2828,  1620,  5161,
    1893, -2828, -2828,  1694,   317,  1507, -2828,  3734, -2828, -2828,
   -2828,   317,  1389,  2293, -2828, -2828,  1635,   138,   241,   780,
   -2828, -2828,  2285,  2286, -2828, -2828, -2828, -2828, -2828, -2828,
   -2828, -2828, -2828, -2828, -2828, -2828, -2828, -2828, -2828, -2828,
   -2828, -2828, -2828, -2828, -2828, -2828, -2828, -2828, -2828, -2828,
   -2828, -2828,   574, -2828, -2828, -2828, -2828, -2828, -2828, -2828,
   -2828, -2828,  1768,   780,   780, -2828,  1153,  5161,   -87,  1010,
    1105, -2828, -2828, -2828, -2828, -2828,    97, -2828, -2828, -2828,
   -2828,  2099, -2828,  1874,   619,  5161, -2828,    63, -2828, -2828,
     317,  2292,    47,    47, -2828,  1679, -2828,    79,  1652,   780,
   -2828,   317,   317,  5161,   -93, -2828,  1691, -2828, -2828,   236,
   -2828,  1791, -2828,  1793,  5161,  1200, -2828, -2828,  1657, -2828,
    2316, -2828,  1731, -2828,   780, -2828, -2828, -2828, -2828, -2828,
   -2828, -2828, -2828, -2828, -2828, -2828, -2828, -2828, -2828, -2828,
   -2828, -2828, -2828, -2828, -2828, -2828, -2828, -2828, -2828, -2828,
   -2828, -2828, -2828, -2828, -2828, -2828, -2828, -2828, -2828, -2828,
   -2828, -2828, -2828, -2828, -2828, -2828, -2828, -2828, -2828, -2828,
   -2828, -2828, -2828, -2828, -2828, -2828, -2828, -2828, -2828, -2828,
   -2828, -2828, -2828, -2828, -2828, -2828, -2828, -2828, -2828, -2828,
   -2828, -2828, -2828, -2828, -2828, -2828, -2828, -2828, -2828, -2828,
   -2828, -2828, -2828, -2828, -2828, -2828, -2828, -2828, -2828, -2828,
   -2828, -2828, -2828, -2828, -2828, -2828, -2828, -2828, -2828, -2828,
   -2828, -2828, -2828, -2828, -2828, -2828, -2828, -2828, -2828, -2828,
   -2828, -2828, -2828, -2828, -2828, -2828, -2828, -2828, -2828, -2828,
   -2828, -2828, -2828, -2828, -2828, -2828, -2828, -2828, -2828, -2828,
   -2828, -2828, -2828, -2828, -2828, -2828, -2828, -2828, -2828, -2828,
   -2828, -2828, -2828, -2828, -2828, -2828, -2828, -2828, -2828, -2828,
   -2828, -2828, -2828, -2828, -2828, -2828, -2828, -2828, -2828, -2828,
   -2828, -2828, -2828, -2828, -2828, -2828, -2828, -2828, -2828, -2828,
   -2828, -2828, -2828, -2828, -2828, -2828, -2828, -2828, -2828, -2828,
   -2828, -2828, -2828, -2828, -2828, -2828, -2828, -2828, -2828, -2828,
   -2828, -2828, -2828, -2828, -2828, -2828, -2828, -2828, -2828, -2828,
   -2828, -2828, -2828, -2828, -2828, -2828, -2828, -2828, -2828, -2828,
   -2828, -2828, -2828, -2828, -2828, -2828, -2828, -2828, -2828, -2828,
   -2828, -2828, -2828, -2828, -2828, -2828, -2828, -2828, -2828, -2828,
   -2828, -2828, -2828, -2828, -2828, -2828, -2828, -2828, -2828, -2828,
   -2828, -2828, -2828, -2828, -2828, -2828, -2828, -2828, -2828, -2828,
   -2828, -2828, -2828, -2828, -2828, -2828, -2828, -2828, -2828, -2828,
   -2828, -2828, -2828, -2828, -2828, -2828, -2828, -2828, -2828, -2828,
   -2828, -2828, -2828, -2828, -2828, -2828, -2828, -2828, -2828, -2828,
   -2828, -2828, -2828, -2828, -2828, -2828, -2828, -2828, -2828, -2828,
   -2828, -2828, -2828, -2828, -2828, -2828, -2828, -2828, -2828, -2828,
   -2828, -2828, -2828, -2828, -2828, -2828, -2828, -2828, -2828, -2828,
   -2828, -2828, -2828, -2828, -2828, -2828, -2828, -2828, -2828, -2828,
   -2828, -2828, -2828, -2828, -2828,  6067, -2828, -2828, -2828, -2828,
     317,    47,    47,   193,   524,  2125,  1556,   780,   241, -2828,
    1737, -2828, -2828,  2293,  2303,  1881, -2828, -2828, -2828, -2828,
   -2828,  1955,  1955, -2828,   762,  1743, -2828,   317,  1483, -2828,
    1483,  1483, -2828, -2828,  1483,  1483, -2828,   317,   988,   631,
    1483, -2828,   988, -2828, -2828, -2828, -2828, -2828, -2828, -2828,
   -2828, -2828, -2828, -2828, -2828, -2828, -2828, -2828, -2828, -2828,
   -2828, -2828,   283,   283,   779,  1022, -2828,  1009, -2828,   800,
   -2828,   -10,  2314, -2828, -2828,  1467,  1898,  1866, -2828, -2828,
   -2828, -2828, -2828, -2828, -2828,   214,  1149,  2325, -2828,  1149,
    1789, -2828, -2828,  1908,  1909,  1810, -2828, -2828, -2828,  1715,
    1715, -2828, -2828, -2828, -2828, -2828, -2828, -2828, -2828,  1683,
     631,  1910, 10278,   642, 10194,  1835, -2828, -2828, -2828,   642,
     642,   642,   642,  1690, 10194, 10194,   331,  1784,   821,   317,
   -2828, 10194, 10194, 10194, 10194, -2828, -2828, -2828, -2828, -2828,
   -2828, -2828,  1689,  -217,  1017,  5161, -2828, -2828,  1921,  2314,
   -2828, -2828, -2828, -2828,   -10, -2828,  1897,  1901,  1902,   911,
    1903,  1905, -2828, -2828, -2828,  2278,   317, -2828,  2369, -2828,
   -2828,   803,  2732, -2828, -2828, -2828, -2828,   317, -2828, -2828,
     803,  1682, -2828,   343, -2828,  1719, -2828,  1750, -2828,  1946,
     432, -2828,  1724, -2828,  1753, -2828,  1801,  1913,   317, -2828,
   -2828, -2828, -2828,  4256,   317, -2828,  1732, -2828, -2828,  2244,
   -2828,  2244,  1726, -2828,  2394,  2397, -2828,  2399,  1776,  5161,
   -2828, -2828,  2401, -2828,  1738, -2828,  1887,  1746,  2206, -2828,
   -2828,  1739,   951,   317, -2828, -2828,  1936,   186,  1054,  1518,
    1720,   220, -2828, -2828, -2828, -2828,  5161,  1483,  1017,  -226,
   -2828,   317,   317,  5161,    83,  -100,  2418,  1021,  2416,  2402,
    2403,   641, -2828, -2828, -2828, -2828, -2828, -2828, -2828,   780,
    2054, -2828, -2828, -2828, -2828,  2313,  5161,   619,  2162, -2828,
   -2828, -2828,  5161,   162, -2828,  2055,  2428,  2430,   454,   457,
     317,  1992,   956, -2828,  3583,  1958,  1961, -2828, -2828,  2030,
   -2828,  5161,    18, -2828,  1803, -2828, -2828,   865, -2828,  5161,
   -2828, -2828,  1771,   334, -2828,  1505,   317,  2433,  9969, -2828,
   -2828,  1017,   780, -2828, -2828,    56, -2828,  2206,  2206,  1741,
   -2828,  1848,  1855, -2828, -2828, -2828, -2828, -2828, -2828,    47,
      47, -2828, -2828, -2828, -2828, -2828, -2828, -2828, -2828,  1749,
   -2828, -2828, -2828, -2828,    47,  8157,  2447,  2427, -2828,   956,
     219,   130,   148,  2306,   -28,   468, -2828,   -48, -2828, -2828,
   -2828,  1973,    50,  1483,   119,  1792, -2828,  1783, -2828, -2828,
   -2828, -2828, -2828,  1979,  1979, -2828, -2828, -2828, -2828,  1868,
    1788,  2458, -2828, -2828, -2828,   488,  1795,  1799, -2828, -2828,
     780,   145, -2828, -2828, -2828,  1778,  1022, -2828,   317,   317,
   -2828, -2828,   317,   662, -2828, -2828, -2828, -2828,  1990, -2828,
   -2828, -2828,  2445,   632,  1149, -2828,   650, -2828,  2035,  2037,
    1149,  1149, -2828, -2828,  1246, 10194, -2828,   407,  2469,  2039,
    2471, -2828, -2828, -2828, 10194, -2828,   471, 10194, 10194, 10194,
   10194,   317,   481, -2828,   371,  2472, -2828, -2828,   317,  5342,
   -2828,  2057,   317,  1817,   642,  2101, -2828, -2828, -2828, -2828,
   -2828, -2828,  1246,  2461,  1246, -2828,  9233, -2828,  2014, -2828,
    1981, -2828,  1982,   248,   248,   248,   485,  2278,   248,  5342,
     317, -2828,   487,   317,   489, -2828, -2828, -2828,  2015,  2016,
    2017,  1245,  1245, -2828,  2019, -2828,  2020,  2021,  2024,  2025,
   -2828, -2828, -2828, -2828,  1164, -2828, -2828, -2828,   496, -2828,
   -2828,   497,   317, -2828,   317,  1818, -2828,   317,  1843,  5161,
   -2828,   317,  2485, -2828, -2828,   803, -2828, -2828,  1825,   803,
     254, -2828, -2828, -2828,   956,  5161,  5161,  5161,  4892,  2494,
    1483,   194, -2828,   956,   317, -2828, -2828,   317,   317, -2828,
     996, -2828, -2828,   867, -2828,  1838,  5161, -2828, -2828, -2828,
    2500,  3734,  2007, -2828,  1842,  2507, -2828, -2828,   956,  1888,
   -2828, -2828, -2828, -2828, -2828,   317,  2206, -2828,   241, -2828,
    1914, -2828, -2828,   498, -2828, -2828, -2828,   780, -2828,  4816,
   -2828,  1120, -2828, -2828,  2142,  2497, -2828,  2131,  2132,  2026,
    1863,  2135,  2053, -2828, -2828, -2828,    -4,  2123, -2828, -2828,
   -2828, -2828,  2030, -2828, -2828, -2828,   258,   927, -2828, -2828,
   -2828,  2293,  5161,  2065, -2828,  2036, -2828, -2828, -2828, -2828,
    2537, -2828, -2828, -2828,  2538, -2828,  1844, -2828,  2523,  -100,
     317,  2193,  2193,  2193,  2193,  2193,  2193, -2828,  2546, -2828,
    2547,  2193,  2193,  2193,  2193,   574, -2828, -2828,  2193,   114,
   -2828, -2828, -2828, -2828,  2529,  2541, -2828, -2828, -2828, -2828,
   -2828, -2828, -2828, -2828, -2828,  2542, -2828, -2828, -2828, -2828,
   -2828, -2828, -2828,   499, -2828, -2828, -2828,  2531, -2828, -2828,
    1483, -2828,   631, -2828, -2828, -2828, -2828, -2828, -2828,  1916,
    1917,   141, -2828,   -48, -2828,   248,  1892,   186, -2828,  2078,
   -2828, -2828, -2828,   317,   317,   248, -2828, -2828,   118,  1483,
    1344, 10194,   306, -2828,  5161, -2828,  5161, -2828, -2828, -2828,
   -2828, -2828,  1960,   186,   118,  1483,  2559, -2828,   780,   317,
     945,   945, -2828, -2828,  2560, -2828,  2560,   778,   778,  2560,
   -2828, -2828,  1984, -2828,  2122,  1149,  2543, -2828,  1149,  1849,
    1149,  1149, -2828, -2828,  2086, -2828, -2828, -2828, -2828, -2828,
   -2828, -2828,   135,  1245,  1895,  1245, -2828,  1245,  2124, 10194,
   -2828,  2130,  2133,  2137,  2138, -2828, -2828,   331, -2828,   331,
   -2828, -2828,  5702,  1774,  4062,  1774,  2569,  2572, -2828, -2828,
   -2828, -2828, -2828, -2828,   593, 10194, -2828,  2087, -2828,  2256,
     207,   130,   317, -2828,  2140, -2828, -2828,  4075,    52, -2828,
    1984,  1558, -2828,    52,  1483,   666,  2145,  2581,  1919, -2828,
   -2828,   501, -2828,   503,   911, -2828, -2828,   507,   196, -2828,
   -2828, -2828,   803, -2828,  2566,  2566,  2567,  1920,  -186,  2570,
    2571,  2573,  2570,  2570, -2828, -2828, -2828,   127, -2828,   825,
     317, -2828,   803, -2828, -2828, -2828,  1931, -2828, -2828,  1934,
   -2828, -2828,  -193,   511, -2828,   317,   536, -2828,  5161,  2160,
    2585,   538,   956,  2602, -2828, -2828, -2828, -2828,  5161,  1993,
    2280,  5161, -2828, -2828, -2828, -2828,   867,  1051,  1051,  2603,
     411, -2828,  2608, -2828, -2828, -2828,  1051,   317,  2028,  1517,
    2609,   317, -2828,  3734,   203,  1483,  2617,   956,  -220,  2418,
    5161, -2828, -2828,   641, -2828,  1911,  5161, -2828, -2828, -2828,
    2621,  3583,   780, -2828,   959,   317,   780, -2828,  2185,  3583,
    3583, -2828, -2828,    -4,  2123, -2828,   574, -2828, -2828,  1202,
   -2828, -2828,  2022, -2828,  3734,  5031,  9969,    30,  1102, -2828,
   -2828, -2828,  1965, -2828, -2828, -2828, -2828, -2828, -2828,    47,
    2193,    47,  2193, -2828, -2828, -2828, -2828, -2828, -2828,  -100,
   -2828,  1227,  1273,  8157, -2828,  2186,  2156, 10194, -2828,   148,
     148, -2828, -2828, -2828, -2828,   540, -2828,  2117, -2828,   248,
     809, -2828,  1964, -2828,   555, -2828, -2828,  2635, -2828, -2828,
    2049, -2828,  2636,  1922,  1922,  1922,  1922,   248,   248, -2828,
   -2828, -2828, -2828, -2828, -2828,  2635,  1976,   780, -2828,  2560,
   -2828, -2828,   317,   778,   778, -2828, -2828,   778,  2383,  1975,
   -2828, -2828,   714, -2828,  2208,  2212, -2828, -2828,  2623,  2214,
    1986,  1246,  1987,  1988, -2828, -2828, -2828, -2828, -2828, -2828,
   -2828,   567, -2828, -2828, -2828,   278,   195, -2828,  5342,  5342,
   -2828, -2828, -2828, -2828, -2828, -2828, -2828, -2828, -2828, 10035,
   10035,  2178, 10035,  2179, -2828, 10035,   553, 10194,  2659, -2828,
   -2828,  5342, -2828, -2828, -2828, -2828, -2828,  2660, -2828,   -71,
   -2828, -2828,  2256,  1994,  1998, -2828, -2828,   162,   162,   162,
    2642,   162,   162,   162,   162,   162,   162,  2649, -2828,  2656,
     162, -2828, -2828, -2828, -2828, -2828, -2828, -2828, -2828,  4075,
   -2828,   780,  2038, -2828,  2190,  2383,  2658, -2828,  2667,  2668,
    2670,  2671,  2672,  2674,  1208,  1558, -2828,  2190, -2828, -2828,
    2675, -2828,  2337,   248,  1528,   248, -2828, -2828,  2278, -2828,
   -2828, -2828, -2828,  2249,  2266,   575,  1246,  2685,  1246, -2828,
    2707,   583,  2269,  2270,  2707, -2828, -2828, -2828, -2828,  1483,
   -2828, -2828, -2828,  2235, -2828, -2828,   825, -2828,  2278, -2828,
   -2828,   317,   317, -2828, -2828,   317,  -332, -2828,   803,   217,
    2293, -2828,  2199,   217,   222,   956, -2828,  2713,  2238, -2828,
   -2828,  2281,  2126, -2828, -2828,   317,  1051,  3734,  1546,   317,
    1051, -2828, -2828,    47, -2828, -2828,  5161, -2828, -2828,   282,
   -2828, -2828, -2828,   956,  2714, -2828,    47,  2293,   780,  2431,
   -2828,  2698,  1848,  9233,  2703, -2828, -2828,   241,  2252, -2828,
   -2828,  3583, -2828, -2828,  2287, -2828, -2828, -2828,   927, -2828,
    1848, -2828,  5161, -2828,   294, -2828,  2181, -2828, -2828, -2828,
   -2828,  2242,  2336, -2828,  2715, -2828, -2828, -2828, -2828, -2828,
   -2828, -2828, -2828, -2828, -2828, -2828,   317, -2828,   131, -2828,
   -2828, -2828,   248, -2828,   631,  2544,   586, -2828, -2828, -2828,
   -2828,   317,   248, -2828,   118,   118,  2147,  6332,  6332, -2828,
   -2828,  5356,  2259, -2828, -2828,  2260,  2271, -2828,  2272,  2273,
    2277,  2284,   317,   753, -2828, -2828, -2828, -2828,   587, -2828,
   -2828,  2128, -2828, -2828, -2828,   588,  2755,  2755, -2828, -2828,
     589,  2761,  2753, -2828,   267,   780,   118, -2828, -2828, -2828,
   -2828, -2828,  2505,  3326,  1149,  1858,  1149,  1149,  2326, -2828,
    1246,  2327,  1246,  1246,   331, -2828, -2828,  2572, -2828,  2283,
    1985,  2283,   191, -2828,  2283,   191, -2828,  2283, 10035, -2828,
   -2828, 10194, -2828, 10194,  2569,   207, -2828, -2828, -2828, -2828,
    1246, -2828, -2828, -2828, -2828, -2828, -2828, -2828, -2828, -2828,
   -2828, -2828, -2828, -2828, -2828, -2828,   572,  2764, -2828,   780,
    2001, -2828,  2505, -2828, -2828, -2828, -2828, -2828, -2828, -2828,
   -2828, -2828, -2828, -2828,   355, -2828, -2828, -2828,  2264, -2828,
   -2828, -2828, -2828,  2750, -2828, -2828,  2334, -2828,  2754,  2339,
    2758, -2828, -2828, -2828,  2341, -2828,  2300,  5342, -2828, -2828,
   -2828, -2828, -2828,   317,  2760, -2828,  -332, -2828, -2828,  2762,
   -2828, -2828,  2763,   317,  2256,   217, -2828,    47,  -100, -2828,
    2360,   956, -2828,  5161, -2828,  2172,  2765,  -100, -2828, -2828,
     564, -2828, -2828, -2828, -2828,   136,  2349, -2828, -2828,   956,
    2206,  2538,  2502, -2828,  -100,  2351,  2352,  2418,  2317, -2828,
    2404,  2353, -2828, -2828, -2828, -2828,  2506,  2291,  5161,  2310,
   -2828, -2828, -2828,  1848, -2828,   590, -2828,   780,  2209, -2828,
   -2828, -2828, 10194, -2828, -2828,   248, -2828,  2322, -2828, -2828,
   -2828,  2635,  2209,  1834,  1834,  2363, 10278,   642, 10304,   642,
     642,   642,   642,   484, 10304,  1922, -2828, 10304, 10304, 10304,
   10304, -2828, -2828,   248,  2795,   248,  1922,   186,  5342, -2828,
    2538,    87, -2828, -2828, -2828, -2828,  2366,  2371, -2828, -2828,
   -2828, -2828, -2828, -2828, -2828,   127, -2828, -2828,   608, -2828,
   -2828, -2828, -2828,   609, -2828,  2283,  2806, -2828, -2828, -2828,
   -2828, -2828, -2828, -2828,   780,  2764, -2828, -2828, -2828,   780,
   -2828,   780, -2828, -2828,  2105, -2828,  2525, -2828,  2526,  2793,
   -2828, -2828,  2376,  2146, -2828, -2828, -2828,  2378, -2828,   248,
     304, -2828, -2828, -2828, -2828, -2828, -2828, -2828, -2828, -2828,
   -2828, -2828,   956, -2828,  2379, 10656,  2342, -2828, -2828, -2828,
    2158,  -100, -2828, -2828, -2828, -2828, -2828, -2828, -2828,  2384,
     241, -2828,  2404,  2404,   927, -2828,  3734,  2210, -2828, -2828,
     317, -2828,  2538,   821,   135, -2828, 10119,   821, -2828,  2386,
   10304, -2828,   629, 10304, 10304, 10304, 10304,  2808,   317,   639,
   -2828, -2828, -2828, -2828, -2828, -2828,  2355, -2828, -2828, -2828,
    2569, -2828,   317, -2828,  1149,  1149, -2828, -2828, -2828,   224,
   -2828, -2828, -2828, 10194, -2828,  1954,  1954, -2828,  1954, -2828,
    1954,  1954, -2828, -2828, -2828,  2361, -2828,  1246, -2828,   649,
   -2828,  1152, -2828, -2828,   139,   139,   139,   139,   139,   139,
   -2828,  2812, -2828,   654, -2828,  5161,  1574, -2828,   644,  2404,
    3583,  2404,  2418, -2828, -2828, -2828,  2548,   369, -2828,  -100,
   -2828, -2828, -2828, -2828,   659, -2828, -2828,  1500, -2828,  2395,
   10304, -2828,  2396,  2398,  2400,  2405,   370,  2343, -2828,  1922,
   -2828, -2828, -2828, -2828, -2828, -2828, -2828,  1954, -2828,  1954,
   -2828, -2828, -2828, -2828, -2828, -2828, -2828, -2828, -2828,  1284,
   -2828, -2828, -2828, -2828, -2828, -2828, -2828, -2828, -2828, 10656,
   -2828,  2838, -2828, -2828, -2828, -2828,     5, -2828, -2828, -2828,
   -2828, -2828, -2828,    56, -2828, 10119, -2828,  1865, -2828, -2828,
   -2828, -2828, -2828, -2828, -2828, -2828,  2819, -2828,  2822,   682,
   -2828, -2828,  1293,  1293, -2828, -2828,  1293, -2828,  5161,    44,
   -2828, -2828,  2406,    30, -2828,  2182,  2189,  2849, -2828,  2382,
     374, -2828, -2828, -2828, -2828,  2411, -2828, -2828, -2828,   317,
     317,  1865, -2828,  2830, -2828, -2828,   122,  2192, -2828, -2828,
    2385, -2828,   241, -2828,   317, -2828,  2418, -2828
};

/* YYPGOTO[NTERM-NUM].  */
static const short yypgoto[] =
{
   -2828, -2828, -2828, -2828, -2828,    26, -2828,    88,  -159, -2828,
   -2828, -1145,   149, -2828, -2828, -2150, -2828, -2828, -2828, -2828,
    -834, -2828, -2828, -2828, -2828, -2828, -2828, -2828, -2828, -2828,
   -2828, -2828, -2828, -2828, -2828, -2828, -2261, -2828,  -990, -2828,
    1870, -2828, -2828, -2828, -2828, -2828, -2828, -2828,   357, -2828,
   -2828, -2828, -2828,  1327, -2828,   685, -2828, -2828,   -32, -2828,
   -2828,  2843, -2828,  2850, -2828, -2828, -2828, -2828, -2828,   436,
      75, -2828,   433, -2828, -2828, -2828, -2828, -2828, -2828, -2828,
   -2828, -2828, -2828, -2828,  -108,  1226,   950, -2828, -2828,  2535,
     -49, -2828,  2775, -2828, -2828,  2772, -2828,  2684, -2828, -2828,
   -2828, -2828, -2828,  2550,  2239,   853,  2549,  -524, -2828, -2828,
   -2828, -2828, -2828,   854,  -647, -2828, -2828, -2828, -2828, -2828,
   -2828, -2828, -2828,   896, -2828,  2678,  2364,  2687,    80,  2302,
   -2828,  2354,  1622, -2828,  2528, -2828, -2828, -2828, -2828,  2524,
   -2828, -2828, -2828, -2828,  -389, -2828, -2828, -2828, -2828, -2828,
   -2828, -2828, -2828,  2344, -2828,  2357, -2828, -2828, -2828, -2828,
   -2828, -2828, -2828, -2828, -1329, -2828, -2828,  -773, -2828, -2828,
   -2828, -2828, -2828, -2828, -2828, -2828, -2828, -2828,  -136, -2828,
   -2828,   824, -2828, -1094, -1151,  -631, -2828, -2828, -2828, -2828,
   -2828, -2828, -2828,  1929, -2828, -2828, -2828, -2828, -2828, -2828,
   -2828,  -608, -2828, -2828, -2828, -2828, -2828,  2129, -2828, -2828,
   -2828, -2828, -2828, -2828, -2828, -2828,  -577, -2828,   -98, -2828,
   -2828, -2828, -2828,  2510, -2828, -2828,  -237, -2828, -2828, -2828,
   -2828, -2828, -2828, -2828, -2828, -2828, -2828, -2828, -2828, -2828,
   -2828, -2828, -2828,  1663, -2828, -2828, -2828, -2828,   627, -2828,
   -2828, -2828, -2828, -2828, -1937, -2828, -2828,   622, -2828, -2828,
   -2828, -2828, -2828, -2828, -1101,  -863,   490,   785, -2828,  -203,
    -547,   479, -1114,  1235, -2828,   805, -2828, -2459,    -3,  -343,
   -2828, -2828, -2373,   480,  1648, -2828, -2828, -2828,   637,  1040,
   -2828, -2828, -2828, -2828, -2828, -2828,    73, -2828,  -240, -2828,
    1043, -2828,   718, -2828,   402, -2828, -2828, -2828, -2828,  -810,
   -2828, -2828, -2828, -2828, -2828, -2828, -2828, -2828,   500, -2828,
   -2828, -1835, -2828,   700, -2828, -2828, -2828, -2828, -2828, -2828,
   -2828, -2828, -2828, -2828, -2828, -2828, -2828, -2828, -2828, -2828,
   -2828,  1511, -2828, -2828, -2828, -2828, -2828, -2828,  -443, -2828,
   -2828, -2093, -2828, -2828, -2828, -2828,   578, -2217, -2828, -1123,
   -2828, -2828, -2828, -2828, -2828, -2828, -2828, -2828, -2828, -2828,
   -2828, -2828, -2828, -2828,  2929, -2828, -2828, -2828,  2857,  2908,
   -2181, -2828, -2828, -2828, -2828, -2828, -2828, -2828,  -363, -2828,
   -2828, -2828, -2828, -2828,  2910, -2828, -2828,  2930, -2828, -2828,
   -2828, -2828, -2828, -2828, -2828, -2828, -2828, -2828,   754, -2828,
   -2828, -2828, -2828, -2828, -2828, -2828, -2828, -2828, -2828,  -670,
    2200, -2828, -2828, -2828, -2828, -2828,  2041, -2828, -2828, -2828,
   -2828, -2828, -2828, -2828, -2828,  2721, -2828, -2828,   -23, -2828,
   -2828,   751, -2828, -2828,  1400,  -176,  2634, -2828, -2828, -2828,
   -2828,  -244, -2828, -1040,  1944,  1062, -1443,  1457, -2828,   756,
    1740,  -345,  -526, -2828,  2194,  1540, -2828, -2828, -2828, -2828,
   -2828, -2828, -2828, -2828, -2828, -2828, -2828, -2828, -2828, -2828,
   -2828, -2828, -2828, -2828, -2828, -2828,  1471, -2828,  -763, -2828,
    -623, -2828, -2828, -2828, -2828, -2828, -2828, -2828,  -736, -2828,
   -2828, -2828, -2828, -2828, -2828,   115, -2828, -1301,  1557,   602,
   -2828, -2828, -2828, -2828, -2828,   -73, -2828,  -523, -2828, -2828,
   -2828, -2828, -2828, -2828, -2828, -2828, -2828, -2828, -2828, -2828,
   -2828, -2828, -2828,  1455, -2828, -2828, -2828, -2828, -2828, -2828,
   -2828, -2828,  -511, -2828,   806,  2534, -2828, -2828,   -60, -2828,
    -700, -2828, -2828,   -43,   264, -2828, -2828, -2828, -2828, -2828,
   -2828, -2828,   841, -2828, -2828, -2828, -2828, -2828, -2828, -2828,
   -2828, -2828, -2828, -2828, -2828, -2828, -2828, -2828, -2828, -2828,
   -2828, -2828, -2828, -2828, -2828, -2828, -2828,  -114, -2828,  -375,
    -372, -2828, -2828,  -364, -2828, -2766, -2828,  -102,   565, -1350,
   -2828, -2828, -2828,   922, -2828, -1992, -2828, -2828, -2828, -2004,
   -2828, -2828, -1978, -2828, -2828, -2828, -2828, -2330, -2828,   940,
     614, -2828, -2828, -2828, -2828, -2828,   399, -2828, -2828, -2828,
   -2828, -2828, -2828,  -717, -2828, -2828, -2828, -2828, -2828, -2828,
   -2828, -2828, -2828, -2828, -2828, -2828, -2828,  -284, -2828, -2828,
   -2828, -2828, -2828, -2828, -2828, -2828, -2828, -2828, -2828,  1070,
   -2828,  1071, -2828,   386,   731, -2828, -2517,  -197, -2828, -2828,
   -2828, -2828, -2828, -2828,   -44, -2828, -2828,  -510, -2828, -1135,
   -1326, -2828, -2828, -2828, -2828, -2828,   -76, -2828, -2828, -2828,
   -2828, -2828, -2026, -2828, -2828, -2828, -2828, -2828, -2828, -2557,
     667, -2828, -2608,   750, -2828, -2828, -2346,    46,    54,   321,
   -2828, -1952, -1857, -2828, -2828,  -259,  -579, -2828, -2828, -2828,
   -2828, -1849, -2828, -2828, -2828,   -50, -2828,   284,  -901, -2828,
    -407,  -306,  1109,  -301, -2178,   307, -2828, -2671, -2828, -2828,
   -2828, -2828,   -80, -2828, -1230, -2314,  3026, -2828, -2828, -2828,
   -2828, -2828, -2828, -2828, -2828,  -726, -2828, -1735, -2828,  1785,
   -2828, -2828,   655,   335, -2828, -2235,   330,  -161,   147,   -40,
   -1893, -2272,  1033,  -230,  -933, -1261, -2828,  1042, -2828, -2828,
   -2828,  1142,  -714, -2828, -2828,  -505,  1809, -2828,   936, -2828,
   -2828,   444,  -142, -2828, -2828, -2828, -2121,  -376, -2611, -2828,
   -2388, -2828, -2828, -2828, -2828,  1176, -2828, -2828, -2828, -2828,
   -2828, -2828, -2828, -2828, -2828, -2828, -2797,  -393, -2828, -2827,
   -2188, -2090, -1307, -2828, -2828,  -381, -2828, -2828, -2828,   250,
   -1073,  1030,  -741,  1952,  1623,  1617,   342, -2828, -2828,   255,
     610,   111, -2828, -2828, -2828, -2828,  1639, -2828, -2828, -2828,
   -2828, -2828, -2828, -2828, -2828, -2828,   894,   784,  2530, -2828,
   -2828, -2828, -2828
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -2264
static const short yytable[] =
{
      34,    36,    38,   565,  1001,    38,   952,   182,  1351,   956,
     266,  1399,   324,    86,  1056,  1460,  2147,   234,  1516,  1508,
     111,  1488,   406,   407,  2071,  1989,  1990,   989,  1170,  2452,
     677,   102,  1457,  2738,  1118,   294,  2283,    58,  1317,  1467,
    1468,  2055,  1469,   942,  1490,  1491,   965,  2736,  2713,   101,
    2715,    58,  1456,  2672,   404,   405,   573,  2848,    86,  2221,
    2222,   422,   108,  2409,  2949,   947,    33,   195,  2172,   115,
    2091,   182,    33,   120,    33,  2803,   122,   123,  2410,  1176,
    1088,   126,   127,  2385,  1058,    33,  3076,  3235,  3236,  3237,
     182,  2032,  3204,  2033,  1429,  2584,  1898,  1429,   253,    33,
    2879,    58,  1507,  1051,   420,   584,    33,  2325,  1074,   573,
      33,  1208,   585,  1458,  1063,   589,  2100,  2925,   230,   573,
    3239,   233,   590,  2600,  1893,   408,   237,   362,   363,   424,
    2960,   426,  2962,   427,   428,   429,  2015,  1916,  1903,   322,
    2015,   573,   434,  2136,  3169,    33,   445,   446,   558,   322,
    2638,   272,  3075,  1290,  1163,  1174,    99,    33,  1128,   508,
    2337,  2338,  2339,  2340,  1178,  1461,    33,  1193,    33,  1123,
   -2262,  1199,  1126,   560,   253,    33,   355,  1205,   329,  1207,
     322,  1169,  1894,   272,   330,   331,   272,   327,  1052,   322,
     272,   325,   326,    33,   568,  2729,  2732,  2732,  2136,   443,
    2732,    99,  2968,    33,  2970,  2971,    33,  2972,  2973,  2974,
    2975,  2976,  2977,    33,  2793,   272,  1289,  1290,    33,  1032,
     182,    33,  3135,  3130,   182,  2461,  1230,  3370,  1032,   359,
      33,  2604,  1032,  2996,    33,   365,  3289,  1509,  1510,  1920,
    2313,  3031,  3224,  3224,  3224,  3224,    33,   394,   272,  1289,
    1290,    33,  2607,   403,   403,   403,   403,   403,  2140,  2194,
    2141,   403,  2142,  2794,  2363,   272,  1220,  1221,    33,   272,
    1220,  1221,    33,  1032,  1081,    33,    33,  3359,     4,  1174,
    1034,    33,  3591,  2847,  2968,    33,  1504,  2461,  1497,  1498,
     518,   347,  1415,   674,   598,  3067,   524,   601,   573,   322,
    2188,   928,  3226,  3226,  3226,  3226,   104,   105,    58,    58,
    2968,  2159,  1060,  1061,   609,   610,   611,   612,   510,   613,
     614,   615,   616,   617,   618,   619,   620,   621,   622,   623,
     624,   625,   626,   627,   628,   629,   649,  3771,  2877,  3740,
    3353,  2096,  1028,  1031,    33,  2610,   630,   631,  2965,  2912,
     570,   633,  2232,   634,  3360,  3361,  1032,  2452,    33,   153,
    3509,    33,  2646,  2001,  1110,  2649,   637,   638,   639,   640,
     945,  2165,    54,   647,   322,  3726,   954,  1278, -2262,  3763,
    1064,    54,   573,  1064,  1118,    44,  1416,  1417,  1043, -2262,
     422, -2262,  1439,  1073,  3354,  3093,  1032,  1064,    33,   924,
    2468,  1064,   573,  2913,  2914,  2915,  2916,  2917,  1090, -2262,
     593,  2511,  2673,  1064,   182,  1073,   946,  1230,  2146,   575,
     657,  1102,   925,  1230,  1073, -2262,   660,  2896,   366,  1014,
     662,  1112,  1407,  1114,   666,  2035,     6,  2905,  1127,     1,
    2469,  1922,  2611,     2,  3094,  1168,  1275,  2014,  2035,  1367,
    1368,  2040,  1281,  1276,  1097,   367,  1102,   562,  2364,   573,
    1102,    54,   573,  1440,  1102,    48,  1114,  1104,  1928,  3457,
    1073,  2938,  1538,  1073,  1000,  1447,  2679,   182,     7,  1369,
    1370,  1371,   570,    54,    27,  2237,  2679,    54,  3136,  3068,
    2734,    54,  2383,  1020,  2742,    33,    54,  1976,    58,  2978,
      54,  2760,  2762,  2823,  2883,  2711,  3055,  1932,  3055,    52,
     829,   922,  3055,  3362,    76,    33,  3095,  3286,  1233,  2590,
    3772,    77,  2195,   975, -2262,  3227,  3227,  3227,  3227,  1898,
     586,   669,  3000,   112,   669,  1543,  3224,  3224,  1163,  3035,
    3224,  3098,   669,  3098,  1027,  3192,  1523, -2262,  1529,  1165,
    1166,  1027,   182,   313,   314,   315,   316,   317,  2160,   394,
    3202,   394,    37,  3278,    33,  1106,  3287,    78,    79,   944,
     403,   955,  3264,   949,  1294,    80,    54,  2894,  1214,   576,
    3333,  1217,   313,   314,   315,   316,   317,   559,  3340,  1027,
     403,  3425,  3445,  3445,  3453,  3560,  3226,  3226,  3528,  1470,
    3226,  3480,  2970,  2971,  3480,  2972,  2973,  2974,  2975,  2976,
    2977,   323,   561,  3599,  3599,  3188,  3032,  2601,  2808,  2979,
    2980,   513,  3170,    53, -2262,    33,  2349,  1915,     1,  3157,
      33,  2906,    26,   569,  3660,  1232,  3131,  3261,  1294,  2326,
    3060,  1396,  2475,  2157,  3660,  3284,  2191,  1282, -2262,  3371,
    1105,  2592,   999,   914,  3053,   275,  3585,  2056,  2314,  3699,
    2067,  1352,  1929,  1410,  3715,  1522,  1470,    33,  1505,  1929,
     669,  1294,   963,  1118,  2981,    58,    58,    58,  1019,    58,
    1023,  1025,  1222,  3394,  1033,  1035,  1036,  3445,  3431,  1041,
    1462,  1025,  1977,  1511,  1044,  1430,    58,  2462,  1455,  2887,
    1978,  3404,  2929,  1981,  1982,  1036,  2102,  3474,  1459,  1233,
      54,  1195,  2000,  2042,  2538,  1233,  1033,  1033,  2117,  1506,
    2071,  3197,  3266,  2377,  2019,   587,  1036,  1899,  3330,  3461,
    2173,  2016,    58,  3184,  3417,   591,  3376,   574,    58,  1036,
      58,  2639,  3378,  1463,    58,  1964,  3383,    58,  3620,  1091,
      58,  2103,  3335,  3592,  3337,   400,  3089,  1025,  3349,  3387,
      58,   948,  1514,   400,  3061,   403,  1108,  3224,  1033,  2534,
    3090,  3407,  1115,  3224,  3224,    58,  3224,  3224,  3224,  3224,
    1512,    58,  1223,   403,   403,  3224,  1168,   563,    58,    58,
      58,  2104,  2105,  2106,  1189,   400,   293,  1196,  2432,   400,
    2433,  2982,    58,  1471,  3597,  2143,    33,    33,  2124,  1209,
    3563,  1209,   403,  2144,  1209,   403,  2477,  1209,    58,  3227,
    3227,   579,  1385,  3227,  3567,    33,  1991,  3226,   293,    81,
      33,   293,  3510,  3226,  3226,   293,  3226,  3226,  3226,  3226,
      54,   580,  3729,  3458,  1386,  3226,  3712,  3727,  1372,   594,
    1338,  3764,  2687,  1338,  3279,  2724,  1979,  1464,  2538,   658,
     293,   647,   647,   664,  2724,   661,  2893,  2983,  2724,   663,
    1471,  1277,  2807,   667,  2036,  3326,  2158,  3329,  1229,  1963,
    2782,     1,    54,  2623,  1082,     2,     4,  2037,  2194,  3363,
    2041,  1027,  2624,   293,  1523,  1563,  2344,  2978,  2497,  3224,
    2046,  2498,  3224,  3224,  3224,  3224,  1913,  1127,  1168,  2724,
     293,  1992,  2187,  2047,   293,  2680,  2625,  2984,  2985,  2626,
    3117,  1258,  1418,  2202,    82,  2686,    69,  1993,  3480,  2735,
    1472,  2740,   100,  2743,  1373,  2627,  1473,  1474,  1475,  2918,
    2761,  2763,  2824,  2884,  2199,  3056,  3471,  3057,  3472,  3473,
   -2262,  3059,  2252,  2253,  3559,  3096,  3652,  1355,  1476,  3226,
      43,  3112,  3226,  3226,  3226,  3226,  1391,  1113,  1310,    33,
    1994, -2262, -2262, -2262, -2262, -2262,  3489,  1374,     3,   277,
    3099,  1174,  3103,    33,  3193,  1045,    33,  2087,  1392,  3224,
    2181,  2232,  3280,  3577,  3281,   103,  2092,  1472,  3224,  3203,
     112,  3520,   280,  1473,  1474,  1475,    43,     5,  1362,  1995,
     669,  3265,  1272,  2170,  3421,  2048,    83,  2979,  2980,  3334,
    1238,    54,    54,  2115,  3429,  1476,  1504,  3341,  2484,  2478,
    3426,  3446,  3452,  3454,  3561,  3077,  2161,    33,  1996,  2628,
    2650,  3540,  1445,   968,    33,  1033,   116,  1997,    58,  3226,
    3227,  1980,  3600,  3601,  2331,  2151,  3227,  3227,  3226,  3227,
    3227,  3227,  3227,  1477,    58,  2467,  1478,  1033,  3227,  2328,
    1899,  2335,  2981,  3661,  1479,  2777,  2655,  1436,  1564,  2777,
    3118,  2335,  1317,  3668,  2061,   286,     7,  1230,  2358,  2359,
    2360,  2361,  2629,  3684,  2658,  2046,    84,  2674,  3700,  2630,
    2046,   110,   606,  3716,    85,  2521,    58,  3000,  2047,  1480,
    3451,  1115,  3590,  2047,   114,     8,   313,   314,   315,   316,
     317,  3435,  1115,  3271,  2237,  3274,  3751,   188,  3277,  2050,
    1477,  2163,    33,  1478,   930,  3078,    58,    58,    58,     4,
      58,  1479,    58,    58,  1481,  2051,  2827,    33,    58,    58,
    3564,  2195,   189,  3578,  3189,  3190, -2262,   969,  3254,  1231,
    3491,  2747,  2748,  1482,  1483,   412,   931,  2445,  2332,  2446,
     413,  2631,   415,  3079,  1484,  3050,  1480,   289,    53,  1485,
      33,  1536,  3227,    58,  1114,  3227,  3227,  3227,  3227,   290,
     291,   192,  1547,  2298,  2503,    58,  2118,   292,    54,  2982,
    1555,    54,  1548,  1232,    33,   231,  2352,  2268,  2046,  3492,
    2048,  1481,  2445, -2262,  2446,  2048,  2290,   232,  1486,    58,
      58,  2047,  1909,  2097,    33,    33,    10,  3159,    58,    33,
    1482,  1483,  1106,  3320,  3444,    33,   519,  3080,   241,  2804,
    2733,  1484,    10,  2737,    58,    58,  1485,  3565,   529,  2254,
    1487,  3081,    54,  3180,    33,  2043,   239,  3580,  2045,  1114,
       5,  2006,  1447,  2007,  2008,  2983,   970, -2262,  3588, -2262,
    1966,  2656,  3227,  2447,  1565,  2532,  2448,  2333,  1194,  2070,
    2518,  3227,  1200,  1310,  1310,  1486,  1204,   987,  2130,  2659,
     990,  3643,  3644,  1310, -2262,  2178,  2179,  1494,  2232,  3182,
      33,  3422,   255,  3683,  1501,  1391,  2013,  1566,     6, -2262,
    1050,   248,  3451,  3451,  2020,  2984,  2985,  1487,  2447,  3477,
    2046,  2448,  3482,  2048,  2050,  3484,   249,  1392,  3651,  2050,
    3194,  1068,  3657,  2047,   422, -1626,  2299,   251,  3198,     7,
    2051,  2729, -2262,  2232,  1077,  2051,   319,    54,  3571,   182,
     957,  3082,   958,  3255,  3571,  2300,  2301,  3581,  3582,  3583,
    3584,   961,    54,   962,   252,  2057,  2080,  3083,     8,  2062,
    2068,  2062,    33, -2262,   256,  2302, -2262,   107,  3708,  1233,
    3710,  2074,  2076,  2077,    33,  2353,    58,  2081,  2083,  2084,
    2085,  1033,  1317,   257,  2861,    54,  2354,  1118, -2262,  2315,
    1033,  2678,  2317,  1422,  2681,  2682,  2683,  2684,  3058,  2134,
    1423,  1115,  2071,    58,   258,    58,    33,    58,    58,    54,
    2269,  3485,  2754,  2755,  2756,    58,    58,  1033,   259,    58,
     403,  2237,   403,    58,  2270,  2048,   320,  2050,  2819,    54,
      54,  1115,  3685,  2950,    54,  2952,   260,  2953,  2133,  1115,
      54,  1213, -2262,  2051,  1216,    58,    58,  1219,  -282,  1234,
    1235,  1236,  1407,   104,   105,   261,   371,   924,  2502,    54,
    1237, -2262, -2262,  2493, -2262,   262,  2237,  2271,  2439,  1024,
    3659,    33,  2426,  3662,  3663,  3664,  3665,  2309,  2272,  1260,
     925, -2262,  2602,  2898,    33,   263, -2262, -2262,   351,  2232,
      58,    58,  1180,    58,  2049,  2463,    58,    58,  1032,  2273,
      33,  2260,  2106,  2261,  2262,    54,  2274,  2264,  2265,  2924,
     334,   335,   336,  2284,  2275,  2524,   321,  2176,  3691,   403,
     403, -2262,    33,  3602,   403,  2589,    58,  3124,  2185,  2186,
    2298,  1523,   425,  -282,    33,  3704,  2276,  1247,  3327,  2050,
     264,   372,  1181,  3686,  1540,    33,   265,  3687,  1248,  -282,
    2510,    58,   380,  1096,   267,  2051,  3381,   373,   435,   307,
    3721,   412,  1103,    33,  3734,   308,   413,   414,   415,  1030,
    1030,   104,   105, -2262,  1030,  1030,   358,    54,  3570,  1182,
    3573,  3574,  3575,  3576,  3702,   309,  3691,  1030,  2223,  2224,
    2225,    33,  -282,  2226,   310,  2227,  2228,   311,  1249,  2348,
     374,    26,    27,  3704,  1967,  2757,   312,  1030,  1212,   369,
    1030,  1215,  1250,  2277,   370,  1445,  1030,    33,   342,  2278,
    1030,  2232,  2237, -2262,  1030,   343, -2262, -2262,  1030,   379,
   -2262,  -282,  1030,  1030,  1541,  1030,   344,   381,  1030,   375,
    1030,  1030,  1030,   436,  2217,  2218,  2490,  1534,  1030,    33,
     348,  1030,  1066,   382,  1991,  2664,  1253,  1254,  1030,   437,
    -282,   409,   410,   411,   349,  1030,  1075,   353,   376,  -282,
    1080,   388,  1030,  2299,  3100,  3686,  1183,   377,  1317,  3687,
    1387,  1388,  1094,  1030, -2262,  3391,   357,  1030, -2262,  1968,
    3140,  1030,  2300,  2301,  3166,   360,   383,  1030,  2203,   105,
    1030,  1251,   438,  2293,  2294,  1969,  2783,   364,  3270,  3270,
    2784,  3270,  2302,  1983,  3270,  1984,  3137,  1495,  1496,  2795,
    2464,  1499,  1500,   389,  3179,  2023,  2024,  2657,   313,   314,
     315,   316,   317,  2662,  2663,   384,  2955,   395,  3358,  1992,
    2665,   439,  2458,  2459,  2816,   165,   398,  1986,  1970,  1987,
    2075,  2966,    33,  1184,  2237,  1993,  2666,   166,   399,  2078,
    3036,    33,  2990, -2262,   385,  1517,  1518,  1519,  1520,  2082,
     440,    33,   430,   386,  2457,  3037,  3038,   432,  2771,   441,
     433,  2223,  2224,  2225,  3039,   444,  2226,  1971,  2227,  2228,
    1234,  1235,  3460,  1185,  2785,  2786,  2106,  2789,  1994,  2667,
    1400,  1401,  1402,  2318,  1327,  2319,   447,  1329,  2778,  1330,
    1331,  1332,  1333,  1334,   448,  2810,  1972,   450,  3040,  1130,
    1131,  1132,  1133,  2271,  2322,  1973,  2323,  3041,   328,  3717,
    3718,  3145,   333,  2766,  2272,    33,   451,  1995,  2668,  3153,
    3154,  3073,  3074,  2306,  3449,  3450,  2609,   452,  2025,  2026,
    2027,  2028,  2029,  2030,   453,  2273,  3042,   454,  2769,  1186,
      33,  2820,  2274,  2944,   501,  2945,  1996,  2669,  2229,   512,
    2275,  2230,  3466,  2231,  3467,  1997,  2670,  1209,   403,   403,
    3745,  2852,    33,   514,    58,    58,  2098,   516,  2098,  2366,
    3433,  3434,  2276,  2232,   521,   522,   523,  2476,   172,  1127,
     525,  3043,   526,  2233,  2256,  1033,   530,  1033,  1033,   531,
    2855,  1033,  1033,  2532,  2266,   532,  1040,  1033,   535,   536,
   -2262,   546,   173,   547,  2234,   548,  2371,  2348,  1049,   551,
    3207,  3208,  1168,   556,   567,   566,   272,  1289,  1290,    33,
     572,    58,  1134,   577,  1317,  3044,   578,  2235,  1291,  1292,
    1135,  2236,  2310,   582,   583,   592,   599,  1069,   602,  1136,
     603,   604,  1137,   607,  3562,   632,   174,  2025,  2026,  2027,
    2028,  2029,  2030,  1086,  1087,   175,   641,   635,   642,  1093,
     650,  1355,  1095,  2920,   648,  2921,   651,   652,   653,  1310,
     654,  1310,   659,  2021,  2022,  2023,  2024,  2559,   655,   656,
     665,  1310,  1310,  1033,     1,  1138,  2357,  3270,  1310,  1310,
    1310,  1310,  1139,  1030,   675,   929,  2547,  2549,   934,   936,
    2489,  1115,   937,  2115,   938,   943,  2237,   953,  3209,   959,
     960,   967,   972,  1960,   974,   976,   977,   978,   647,   995,
     997,  1002,  1003,  2057,  3282,  1005,  1006,  1007,  2062,  1008,
    1010,  1011,  1012,  1013,  2068,  1015,  1125,  2062,  3104,   176,
     177,  2229,  1201,  1262,  2230,  1264,  2231,  1263,  2941,  1140,
    1265,  2943,  1266,  2946,  2947,  2424,  1267,  1268,  1269,  1270,
    1271,  2428,  1273,  1274,  1279,  1280,  2232,  1283,  1284,  1285,
    1328,  1335,  1336,  3134,  1141,  1337,  2233,  3397,  1340,  1341,
    1343,  1142,  1344,  1143,  3496,  1345,  1346,  1347,  1348,  1349,
    2455,  1353,  1354,  1144,  1358,  1359,  1360,  2556,  2025,  2026,
    2027,  2028,  2029,  2030,  1033,  1115,  1395,  1361,  2471,  2472,
    1365,   403, -2262,  1030,  1030,  1030,  3447,  3448,  3449,  3450,
    2235,  1145,  1393,  1394,  2236,  1384,    58,  3106,  1389,  1146,
    3111,  3399,  1390,  1397,  1114,  1414,  1421,  1403,  1420,  1424,
    1425,  1427,  1428,   564,  1433,  1432,  1444,  2500,  1435,    58,
    1449,  1492,  1502,  2886,  1451,  1447,  1507,  1452,  1503,  3497,
    1530,  1531,  1532,  1533,  1537,  1539,  1147,  1543,  1542,  1552,
      58,  1554,  2525,  1555, -2262,  1310, -2262,  1889,  1115,    58,
    1890,   573,  2910,  1897,  1905,  1901,  1891,  1904,  1892,  1907,
    1148,  1906, -2262,  3531,  1163,  1962,   403,   403,  2926,  2237,
   -2262,  1954,  3539,  1975, -2262, -2262, -2262, -2262,  1985,  1965,
   -2262,   403, -2262, -2262,  2002, -2262,    58,    58,    58,  3545,
    2003,  3498,    58,  3499,  2004,  2005,  2009,  1149,  1127, -2262,
    1033,  2010,  2011,  2012,  1168,  2034,  2039,  2060,  1150,  3500,
    2073,  2025,  2026,  2027,  2028,  2029,  2030,  3501,  2088,  2089,
    2348,  3502,  2348,  2090,  2093,  2095,  2109,    58,  2094,  1415,
    1168,  2116,  1514,  3497,  2123,  2645,  2645,  2125,  2136,  2645,
    2127,  2138,  2130,  2149,  2166,  2150,  3503,  3292,  3293,  3294,
    2168,  3296,  3297,  3298,  3299,  3300,  3301,  2177,  2180,  2191,
    3304,  2206,  1310,  2198,  2182,  2200,  2205,  2208,  1899,  2246,
    2249,  1310,  2247,  2244,  1310,  1310,  1310,  1310,  2685,  2255,
    2307,  1033,  2311,  3589,  2330,  2690,  1310,  2312,  3486,  2708,
    2990,  2316,  2320,  2321,  2326,  3498,  2000,  3499,  2324,  2341,
    2349,  1053,  1053,   182,  2362,  2367,  1151,  1152,  1153,  1294,
    2725,  2725,  2725,  3500,  2383,  2725,  1310,  2739,  2373,  1154,
    2057,  3501,  2374,  2375,  2378,  3502,  2379,  2380,  2414,  2415,
    2416,  3372,  2418,  2417,  2421,  2412,  3637,  2419,  2430,  2435,
    3210,  2434,  2436,  3211,  2437,  2438,  2440,  2441,  2464,  2764,
    3503,  2765,  2767,  2444,  2768,  2770,  3212,  2456,  2772,  3388,
    2442,  2443,  2062,  1898,  2479,  2486,  2062,    58,  2481,  2482,
    2488,    58,  2491,  2495, -2262,  2496,  2501,  1033,  2725,  2504,
      58,  2455,  2505,  2508,  2800,  2800,  2522,  2528,  2538,  2514,
    1237,  2540,  2587,  2588,  2605,  3213,  3214,  2599,  2614,  1053,
    2615,  2613,  2619,  2620,  2618,    58,  2642,  2653,  3215,  1224,
    2634,  2654,  2818,  2635,  2675,    58,  2677,  2689,  2705,  2660,
     130,  2661,  1155,  2676,    58,  2710,  2712,  2714,    58,  1317,
    2775,  2716,  2717,  2721,  2780,  3386,  2744,  2745,  2746,  2791,
    2749,  2750,  2751,  2328,  3714,  2752,  2753,  2809,  2811,  3216,
    3642,  2814,  2815,    58,  2817, -2262,  2813,  2821, -2262,   131,
   -2262,  2829,  2830,  3692,  3693,  3694,  3695,  3696,  3697,  2832,
    2833,  3405,  2835,  2836,  2837,  2834, -2262,  2862,   132,   133,
   -2262,  2853,  2856,  1504,  1236,  2854,  1127,  1127,  3217,  2860,
   -2262,  2869,  2871,  2533,  2880,  2881,  2882,  2885,  2897,  2899,
    3218,  2889,  2890,  2922,  2927,  2932,  2940,  2948,  2954,  2942,
    2951, -2262,  3219,  3220,  2956,  2968,  2994,  2957,   134,  2969,
    3221,  2958,  2959,  3222,  3003,  2991,  3053,  1033,  3054,  3052,
     135,   293,  3062,  3065, -2262,  3066,  3069,  3071, -2262,  3072,
    3091,   136,  2725,  3092,  3101,  3102,  3108,  3105,  3115,  3107,
    2901,  2266,  2725,  3119,  3126,  2256,  1033,   137,  1310,  1311,
     922,   468,   469,   470,  3123,  3133,  3144,   138,  3141,  3152,
    3185,  2256,  1033,  3656,  3174,    58,  2645,  3186,  3194,  3201,
    3204,  2015,   139,  3162,  3490,  3205, -2262,   471,  3253,  3258,
    3709,  3246,  3256,  2964,  2130,  2967,  3257,  3533,  3259,  3272,
    3275,  3260,  3262,  3263,  3283,  3285,  3175,  3295,  3177,  3290,
    3674,  3291,  3346, -2262,  3302,  3543,  1310,  3465,  3164,  3468,
    3469,  3303,   140,  3313,  1033,  3079,  1033,  3310,   922,  1310,
    3143,  1310,  3314,  3331,  3315,   647,  3316,  3317,  3318,  1224,
    3319,  3324,  1310,   647,   647,   141,  3309,  2725,    58,  2708,
    3332,  3336,  3338,  3342,  3343,   182,  3347,  3367,  3373,  3374,
     142,  2725,  3389, -2262,  3393,  3375,  3376,   143,  3395,  3398,
     144,  3402,  3776,  3410,  1231,  3413,  2288,  2289,  3423,  2062,
    3436,  3437,  3534,  2305,   472,   473,   474,   475,   476,   477,
    3417,   145,  3438,  3439,  3440,   146,   182,  2068,  3441,  2062,
    3445,    63,   478,   479,   480,  3442,  3455,  3456,  3462,  3494,
    3470, -1815,  2424,  3050,   147,  3475,  3512,  3557,  3513,    58,
    3514,  3519,  3656,  3516,  3517,  3518,  3523,  3532,  3525,  3526,
    3536,  3538,   148,  3542,  3544,  3546,  3547,  3552,  3548, -2262,
    3556, -2262,  3550,  3566,  2455,  2016,  3125,  3568,  3127,  3586,
    3594,  2725,  1033,  3603,    58,  3595,  3613,  3614,  3622,  3615,
    3616,  3617,  3618,  3635,  3623,   154,   185,  3636,  3641,    58,
    3658,    58,  3149,    58,  3666,  3648,  3669,  3698,  3682,  3720,
    3722,  3711,  3723,  3738,  3724,  3749,    58,  2386,  3750,  3725,
    3757,  3759,  3728,  1310,  3761,  3765,  3770,  2348,  3760,  3762,
    3148,  3774,  3775,  3097,  3464,  3737,   403,  1350,   403,  2845,
    1224,  2190,    49,  3225,  3225,  3225,  3225,  2513,    58,    58,
    2796,    50,  3122,  2805,  1310,   527,  3385,   191,   196,   341,
     185,   520,  2368,  1004,  2369,   668,  2725,   346,   966,  3390,
     528,   354,   481,   553,   933,   482,   939,  1988,   555,   185,
    3223,  3223,  3223,  3223,  2725,  2725,  3735,  2427,  1342,  1958,
    1917,   940,   588,  2643,    58,  2651,  1188,  2787,  2473,  3248,
    2216,  3173,  3412,  3758,  1311,  1311,  2220,  2537,  2859,  2557,
    2792,  3273,  3541,  3276,  1311,    46,  2120,   128,    60,  3507,
      61,  2520,    47,  1092,  2523,  2204,   511,  1364,  3380,  2494,
    2243,  2156,  2527,  1895,  3495,  1310,  1310,  1261,  3604,  2111,
    3741,  3168,  1124,  2154,  3323,  2101,  1310,  1310,  2492,  1310,
    2171,  3612,  1310,   608,  1310,  3322,  3305,  3048,  1310,  3369,
    3529,  3527,  3524,  3352,  2781,  2413,  2382,  2741,  3744,  2535,
    2891,  3488,  2286,  2287,  3701,  2617,  2911,  3430,  3325,  3619,
    3348,  2688,  2608,  2963,  3267,   647,  3483,  3671,  3672,   182,
    3673,  1030,  1918,  3268,  3344,   483,  2259,  3511,    58,  3064,
    1919,  3049,   506,   507,    42,  3769,  1920,  1946,  1921,   185,
     484,    58,  3002,   185,   485,  3432,  3001,  3200,  2343,  1922,
    2725,  3328,  2725,  3487,  2251,  3650,  2342,  1912,  2903,  3428,
    3569,  2214,  3587,  3579,  2365,  3132,  1446,  2129,  3129,  2135,
     676,  2812,     0,  2119,     0,     0,  1033,  1923,     0,     0,
     486,     0,     0,  2387,     0,     0,     0,     0,  3350,  3351,
       0,     0,  2772,  1924,     0,  2062,     0,     0,  1925,     0,
       0,     0,    58,  2388,  2389,  2390,  1224,  3755,   487,     0,
    1926,     0,  2800,     0,  1168,  3382,  2800,  1927,     0,     0,
     403,     0,     0,     0,     0,     0,   488,     0,     0,     0,
      58,     0,     0,   403,     0,    58,     0,     0,     0,     0,
       0,     0,  2391,     0,    58,     0,  1030,     0,     0,     0,
       0,     0,     0,     0,  2392,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  3530,  2393,     0,  3225,  3225,     0,
       0,  3225,     0,     0,     0,     0,     0,     0,     0,  1030,
       0,  2394,     0,  3414,     0,     0,     0,     0,     0,  2725,
       0,  2395,     0,     0,     0,     0,     0,     0,  2901,  2725,
       0,  2256,  2256,     0,  3223,  3223,  2396,   489,  3223,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  3443,
       0,     0,   636,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   185,     0,     0,     0,     0,     0,     0,
       0,     0,    58,  2256,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  2397,  3234,  3234,  3234,  3234,     0,
       0,  1033,     0,     0,     0,  1928,     0,     0,     0,  1115,
    1929,     0,  1115,   490,     0,  1310,     0,  1930,  1310,     0,
    1310,     0,  2725,     0,  2398,     0,     0,     0,     0,     0,
    2841,  2842,     0,     0,  2399,     0,   185,     0,     0,  1931,
       0,  2851,     0,     0,  1932,     0,    58,     0,     0,     0,
       0,     0,     0,     0,     0,  2400,     0,     0,     0,  2401,
       0,     0,     0,     0,     0,  2863,  2864,  2865,  2866,  2867,
    2868,     0,     0,     0,     0,  2873,  2874,  2875,  2876,     0,
       0,     0,  2878,     0,  1310,     0,     0,  2402,     0,     0,
       0,     0,     0,     0,     0,     0,  2403,     0,     0,     0,
       0,     0,     0,     0,   403,     0,     0,     0,    58,     0,
       0,   185,     0,     0,     0,     0,     0,     0,     0,     0,
    3647,     0,     0,     0,     0,     0,    58,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  3225,  1016,
    1017,  1018,     0,  1021,  3225,  3225,     0,  3225,  3225,  3225,
    3225,     0,     0,     0,    58,     0,  3225,     0,     0,  1310,
    1047,     0,  2725,     0,  2930,  2931,     0,     0,     0,     0,
       0,  2935,  2936,  1310,     0,  3223,     0,     0,     0,     0,
       0,  3223,  3223,     0,  3223,  3223,  3223,  3223,     0,     0,
    2725,     0,  2725,  3223,     0,  1310,  1071,     0,   182,     0,
       0,     0,  1076,     0,  1078,     0,     0,     0,  1085,     0,
       0,  1085,     0,     0,  1085,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1098,     0,     0,     0,     0,     0,
       0,    58,     0,     0,     0,  1030,    58,     0,    58,  1098,
       0,  1030,     0,     0,   647,  1159,     0,     0,     0,     0,
       0,     0,  1021,  1172,  1175,     0,  2725,     0,  1190,     0,
       0,     0,     0,     0,     0,     0,  1202,  1030,     0,    58,
    3225,     0,     0,  3225,  3225,  3225,  3225,     0,     0,     0,
       0,     0,  1226,     0,     0,     0,  1224,    58,     0,  3234,
    3234,     0,     0,  3234,     0,     0,     0,  3414,     0,     0,
       0,     0,     0,  1310,     0,     0,     0,  3223,     0,     0,
    3223,  3223,  3223,  3223,     0,  3667,     0,     0,     0,     0,
       0,  3113,  3114,     0,     0,     0,     0,     0,     0,  3670,
    3121,     0,   269,     0,     0,     0,  1115,     0,     0,     0,
    1310,   270,   271,     0,     0,     0,     0,   272,   273,   274,
      33,     0,     0,     0,  3481,     0,     0,  3481,     0,     0,
    3225,    58,    58,    58,    58,    58,    58,  3155,  3156,  3225,
       0,     0,     0,  3703,     0,     0,     0,     0,   130,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1311,     0,  1311,     0,  3176,     0,  3178,  3223,     0,     0,
       0,     0,  1311,  1311,     0,     0,  3223,     0,     0,  1311,
    1311,  1311,  1311,     0,     0,     0,     0,   131,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   159,     0,   132,   133,     0,   275,
       0,     0,     0,     0,     0,     0,   160,     0,     0,     0,
     470,     0,  1310,     0,  3746,     0,     0,  3249,  3250,     0,
       0,  3251,  3252,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   161,   471,     0,   134,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   135,     0,
       0,     0,   156,   157,     0,     0,  3767,  3768,  3746,   136,
     158,    33,     0,     0,     0,     0,     0,     0,     0,    58,
       0,  3777,  1226,     0,     0,   137,     0,     0,  2330,     0,
    3234,     0,     0,  1030,  1030,   138,  3234,  3234,  1408,  3234,
    3234,  3234,  3234,     0,     0,     0,     0,     0,  3234,     0,
     139,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  3312,
       0,  1053,     0,     0,     0,    54,     0,   162,     0,     0,
    1438,   472,   473,   474,   475,   476,   477,     0,     0,     0,
     140,     0,     0,     0,     0,   159,     0,     0,     0,   478,
     479,   480,     0,     0,     0,     0,  1311,   160,     0,     0,
    1466,  1466,  1466,   141,  1466,     0,  1466,  1466,     0,     0,
       0,     0,    63,    63,     0,     0,     0,     0,   142,     0,
       0,     0,     0,     0,   161,   143,     0,     0,   144,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    3379,     0,     0,     0,  3384,     0,     0,  1175,     0,   145,
       0,     0,  3234,   146,     0,  3234,  3234,  3234,  3234,  1550,
       0,     0,     0,  3392,   163,     0,     0,     0,     0,   276,
       0,     0,   147,     0,     0,     0,     0,     0,     0,     0,
       0,  3481,  3403,  1226,  1408,     0,     0,     0,     0,     0,
     148,     0,  1902,   471,     0,     0,     0,     0,     0,   164,
       0,     0,     0,     0,     0,     0,     0,     0,  1910,  1910,
       0,     0,     0,  1311,     0,     0,    54,     0,   162,     0,
       0,     0,  1311,     0,     0,  1311,  1311,  1311,  1311,   481,
       0,     0,   482,   165,     0,     0,     0,  1311,     0,     0,
       0,     0,  3234,     0,     0,   166,     0,     0,     0,     0,
       0,  3234,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   277,     0,     0,     0,  1311,   278,     0,
     279,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   167,     0,     0,     0,     0,   280,     0,     0,     0,
     472,   473,   474,   475,   476,   477,   168,     0,     0,     0,
       0,   281,     0,     0,   282,     0,     0,   283,   478,   479,
     480,  2692,     0,     0,     0,   163,   284,   170,     0,     0,
    1286,  1287,  1288,     0,     0,     0,   272,  1289,  1290,    33,
       0,     0,     0,     0,     0,     0,     0,     0,  1291,  1292,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     164,     0,   483,     0,     0,     0,   643,   285,     0,     0,
       0,   171,     0,     0,     0,     0,  1224,   484,     0,   286,
       0,   485,     0,     0,     0,     0,     0,    63,     0,    63,
     287,  1175,  1085,     0,   165,     0,   172,     0,     0,  2110,
    1098,     0,     0,  1175,     0,     0,   166,  2121,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   486,   185,     0,
     288,     0,     0,     0,     0,     0,     0,     0,  1293,  1226,
    1159,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    3555,     0,   167,  3558,     0,   487,     0,     0,     0,     0,
    3005,  3006,     0,  3007,  3008,  3009,     0,   168,   481,     0,
       0,   482,     0,   488,   174,   169,     0,     0,     0,     0,
       0,   289,     0,   175,  2155,  1159,     0,    63,   170,     0,
    2162,  2164,     0,   290,   291,     0,     0,     0,     0,     0,
       0,   292,     0,     0,     0,     0,     0,  3522,     0,     0,
       0,     0,   293,     0,     0,     0,     0,  3522,     0,     0,
    2183,     0,     0,     0,     0,   269,     0,     0,     0,  1311,
       0,     0,   171,     0,   270,   271,     0,     0,     0,     0,
     272,   273,   274,    33,     0,  2210,     0,     0,     0,     0,
       0,     0,     0,     0,   489,     0,     0,   172,     0,     0,
       0,     0,     0,  3010,  1114,     0,     0,   176,   177,     0,
       0,  3011,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   173,     0,     0,     0,     0,     0,  1311,     0,     0,
       0,   483,     0,     0,     0,     0,     0,     0,  3645,     0,
    1311,     0,  1311,     0,     0,  3012,   484,     0,     0,     0,
     485,  1030,     0,  1311,  3013,     0,     0,     0,     0,     0,
     490,     0,     0,     0,     0,   174,     0,   159,     0,     0,
       0,     0,   275,     0,   175,     0,     0,     0,     0,   160,
       0,     0,     0,  3014,  3015,     0,   486,     0,     0,  3675,
    3676,     0,  3678,     0,  3680,  3681,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1311,   161,     0,  2693,     0,
       0,     0,     0,     0,   487,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  3016,     0,
       0,     0,   488,     0,   596,   455,   456,   457,     0,   458,
     459,   460,   461,   462,   463,   464,   465,   466,   467,   468,
     469,   470,     0,     0,     0,     0,     0,     0,   176,   177,
       0,  3730,     0,  3731,     0,     0,     0,     0,     0,     0,
       0,     0,  3017,     0,     0,   471,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  3743,    54,     0,
     162,     0,     0,     0,  1311,     0,     0,     0,     0,  1294,
       0,     0,     0,   489,     0,     0,  3752,  3753,     0,     0,
    3754,     0,     0,  3756,     0,     0,  3018,     0,     0,     0,
       0,     0,     0,     0,     0,  1311,     0,     0,     0,     0,
    1295,     0,     0,  2694,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  2695,  1297,     0,     0,     0,
       0,  1311,  1311,  1311,  1311,     0,     0,     0,     0,     0,
       0,     0,   472,   473,   474,   475,   476,   477,     0,   490,
       0,     0,     0,  2000,     0,     0,     0,     0,     0,     0,
     478,   479,   480,     0,     0,     0,  1298,   163,     0,     0,
       0,     0,   276,     0,     0,     0,     0,     0,  1299,     0,
       0,     0,     0,     0,     0,     0,  1311,  1311,  2242,  1226,
       0,     0,     0,     0,     0,     0,     0,  1311,  1311,     0,
    1311,     0,   164,  1311,     0,  1311,     0,     0,     0,  1311,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1300,
       0,     0,     0,     0,     0,  1053,  1053,  1053,     0,  1053,
    1053,  1053,  1053,  1053,  1053,     0,   165,     0,  1053,     0,
       0,     0,     0,     0,     0,  2292,     0,     0,   166,     0,
       0,     0,  1301,     0,     0,     0,     0,     0,  1302,     0,
       0,     0,     0,     0,     0,     0,   277,  1303,  1304,     0,
    1305,   278,     0,   279,     0,     0,     0,     0,     0,     0,
       0,     0,  1306,  1307,   167,     0,     0,     0,     0,   280,
    1308,     0,     0,  1309,     0,     0,     0,     0,     0,   168,
     481,   293,     0,   482,   281,     0,     0,   282,     0,     0,
     283,     0,     0,     0,     0,     0,     0,     0,     0,   284,
     170,     0,  3019,  3020,  3021,  3022,  3023,  3024,  3025,  3026,
    3027,  3028,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1404,
     285,     0,     0,     0,   171,  1224,     0,     0,     0,     0,
       0,     0,   286,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   287,     0,     0,     0,     0,     0,   172,
       0,  2826,   455,   456,   457,     0,   458,   459,   460,   461,
     462,   463,   464,   465,   466,   467,   468,   469,   470,     0,
       0,     0,     0,   288,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   483,     0,  1311,  1311,     0,     0,  1311,
       0,     0,   471,     0,     0,     0,     0,     0,   484,     0,
       0,     0,   485,     0,     0,     0,     0,     0,     0,     0,
    2485,     0,     0,     0,     0,     0,     0,   174,     0,     0,
       0,     0,     0,     0,   289,     0,   175,     0,     0,     0,
       0,   269,     0,  1175,     0,     0,   290,   291,   486,     0,
     270,   271,     0,     0,   292,     0,   272,   273,   274,    33,
    1311,     0,     0,  1311,   154,   293,  1311,     0,     0,  1311,
       0,  1311,     0,  1159,     0,     0,   487,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   488,     0,     0,     0,     0,   472,
     473,   474,   475,   476,   477,     0,     0,     0,     0,     0,
    1175,  2591,  1175,     0,     0,     0,  1021,   478,   479,   480,
     176,   177,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1311,     0,     0,     0,     0,
       0,     0,     0,   159,     0,     0,     0,     0,   275,     0,
       0,  2637,     0,     0,     0,   160,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   489,     0,     0,     0,     0,
     269,     0,   161,     0,     0,     0,     0,     0,     0,   270,
     271,     0,     0,     0,     0,   272,   273,   274,    33,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1311,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1311,     0,  1311,     0,     0,     0,
       0,     0,  1311,  1311,     0,  1311,  1311,  1311,  1311,     0,
       0,   490,     0,     0,  1311,     0,  1311,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   481,     0,     0,
     482,     0,     0,  1311,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    54,     0,   162,     0,     0,     0,
       0,     0,   159,     0,     0,     0,     0,   275,     0,     0,
       0,  1175,     0,     0,   160,  1175,     0,     0,     0,     0,
       0,     0,     0,     0,  1175,     0,     0,     0,     0,     0,
     269,     0,     0,     0,     0,     0,     0,     0,     0,   270,
     271,   161,   185,     0,     0,   272,   273,   274,    33,  1175,
       0,     0,     0,     0,     0,     0,     0,     0,  1224,  1226,
       0,     0,     0,     0,     0,     0,     0,     0,  2825,     0,
       0,     0,  2828,     0,  1311,     0,     0,     0,  1311,     0,
       0,  1311,  1311,  1311,  1311,     0,     0,     0,     0,     0,
       0,     0,     0,   163,     0,     0,     0,  2850,   276,     0,
     483,     0,     0,     0,     0,     0,     0,  1311,     0,     0,
       0,  1311,     0,     0,     0,   484,     0,     0,     0,   485,
       0,     0,     0,     0,     0,     0,     0,     0,   164,     0,
       0,     0,   159,    54,     0,   162,     0,   275,     0,     0,
       0,     0,     0,     0,   160,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   486,     0,     0,     0,     0,
       0,     0,   165,     0,     0,     0,     0,     0,  1311,     0,
       0,   161,     0,     0,   166,     0,     0,  1311,     0,     0,
       0,     0,     0,   487,     0,     0,     0,     0,     0,     0,
       0,     0,   277,     0,     0,     0,     0,   278,     0,   279,
       0,   488,     0,     0,     0,     0,     0,     0,     0,     0,
     167,  2692,     0,     0,     0,   280,     0,     0,     0,  2928,
    1286,  1287,  1288,  1311,     0,   168,   272,  1289,  1290,    33,
     281,     0,   163,   282,  3207,  3208,   283,   276,  1291,  1292,
     272,  1289,  1290,    33,     0,   284,   170,     0,     0,     0,
       0,     0,  1291,  1292,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    54,     0,   162,     0,   164,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1224,     0,   489,     0,     0,     0,   285,     0,     0,     0,
     171,     0,  1175,     0,     0,     0,     0,     0,   286,     0,
       0,   165,     0,     0,     0,     0,     0,     0,     0,   287,
       0,  2788,     0,   166,     0,   172,     0,     0,  1293,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   277,  3209,     0,     0,     0,   278,     0,   279,   288,
       0,     0,     0,     0,     0,     0,     0,     0,   490,   167,
       0,     0,     0,     0,   280,     0,     0,     0,     0,     0,
       0,     0,   163,  1175,   168,     0,     0,   276,     0,   281,
       0,     0,   282,     0,     0,   283,     0,     0,     0,     0,
       0,     0,     0,   174,   284,   170,     0,     0,     0,     0,
     289,     0,   175,     0,   185,     0,     0,   164,  1175,     0,
       0,     0,   290,   291,     0,     0,     0,     0,     0,     0,
     292,     0,     0,  3146,     0,  1047,     0,  3150,     0,     0,
       0,   293,     0,     0,  3165,   285,     0,     0,     0,   171,
    3161,   165,     0,     0,     0,   185,     0,   286,     0,     0,
       0,     0,     0,   166,  1114,     0,     0,     0,   287,     0,
       0,     0,     0,     0,   172,     0,     0,     0,  1114,     0,
       0,   277,  3181,  3183,     0,     0,   278,     0,   279,     0,
       0,     0,     0,     0,     0,     0,   176,   177,   288,   167,
       0,     0,     0,     0,   280,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   168,     0,     0,     0,     0,   281,
       0,     0,   282,     0,     0,   283,     0,     0,  3247,     0,
       0,     0,     0,     0,   284,   170,     0,     0,     0,     0,
       0,     0,   174,     0,     0,     0,     0,     0,     0,   289,
       0,   175,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   290,   291,     0,     0,     0,     0,     0,  2693,   292,
       0,     0,     0,     0,     0,   285,     0,     0,     0,   171,
     293,     0,     0,     0,     0,     0,     0,   286,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   287,     0,
    1286,  1287,  1288,     0,   172,     0,   272,  1289,  1290,    33,
       0,     0,     0,     0,     0,     0,     0,     0,  1291,  1292,
       0,     0,     0,     0,     0,     0,     0,     0,   288,     0,
       0,     0,  3306,     0,     0,   176,   177,     0,     0,     0,
       0,     0,     0,     0,     0,  3321,   455,   456,   457,     0,
     458,   459,   460,   461,   462,   463,   464,   465,   466,   467,
     468,   469,   470,     0,     0,     0,     0,     0,     0,  1294,
       0,     0,   174,     0,     0,     0,     0,     0,     0,   289,
       0,   175,     0,  1294,     0,     0,   471,     0,     0,     0,
       0,   290,   291,     0,     0,     0,     0,     0,  1293,   292,
    1295,     0,     0,  2694,     0,     0,  1175,     0,     0,     0,
     293,     0,     0,     0,  3210,  2695,  1297,  3211,   185,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    3212,     0,     0,     0,  1175,     0,     0,     0,     0,  1159,
       0,     0,     0,     0,     0,     0,     0,     0,  1226,     0,
       0,     0,     0,     0,     0,     0,  1298,  2000,     0,     0,
       0,     0,     0,     0,     0,   176,   177,     0,  1299,     0,
    3214,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  3215,   472,   473,   474,   475,   476,   477,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   478,   479,   480,     0,     0,     0,     0,     0,  1300,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  3216,  1114,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1301,     0,     0,     0,  1159,     0,  1302,     0,
       0,     0,     0,     0,     0,     0,     0,  1303,  1304,     0,
    1305,     0,  3217,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1306,  1307,  3218,     0,     0,     0,     0,     0,
    1308,     0,     0,  1309,     0,     0,  3219,  3220,     0,     0,
       0,   293,     0,     0,  3221,     0,     0,  3222,     0,     0,
       0,     0,     0,     0,     0,   293,     0,     0,     0,     0,
    3306,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  2693,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   481,     0,     0,   482,     0,     0,     0,     0,     0,
       0,     0,  1567,  1568,  1569,  1570,  1571,  1572,     0,  1573,
    1574,  1575,     0,     0,     0,  1576,  1577,  1578,  1579,  1580,
    1581,     0,  1175,     0,     0,     0,     0,     0,     0,     0,
    1582,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1175,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1583,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1159,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1294,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1295,  1584,     0,  2694,   483,     0,     0,     0,     0,     0,
    1585,     0,     0,     0,     0,  2695,  1297,     0,     0,   484,
       0,     0,     0,   485,   581,     0,     0,     0,  1586,  1587,
       0,     0,     0,     0,     0,  3306,     0,  1588,     0,     0,
    3607,     0,  3609,     0,  1589,  1590,     0,     0,  1591,  1592,
    1593,  1594,     0,     0,  1595,  1596,  1298,     0,     0,   486,
       0,     0,     0,     0,     0,     0,     0,     0,  1299,     0,
       0,     0,     0,  1175,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   487,     0,     0,
       0,  1226,     0,     0,  1597,     0,     0,   185,     0,     0,
       0,     0,     0,     0,     0,   488,     0,     0,     0,  1300,
       0,     0,     0,     0,     0,     0,  1598,     0,     0,     0,
       0,     0,  1599,     0,     0,     0,     0,     0,  2213,  1600,
       0,  1601,     0,     0,     0,     0,  1602,     0,     0,     0,
       0,     0,  1301,     0,     0,     0,     0,     0,  1302,     0,
       0,     0,     0,     0,     0,     0,     0,  1303,  1304,     0,
    1305,     0,  1603,     0,     0,  1466,  1466,  1466,  1466,  1466,
    1466,     0,  1306,  1307,     0,     0,   272,  1289,  1290,    33,
    1308,     0,     0,  1309,     0,     0,   489,     0,  1291,  1292,
       0,   293,     0,     0,     0,     0,     0,     0,     0,     0,
    1604,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1605,     0,     0,     0,     0,     0,  1606,
       0,     0,     0,     0,     0,     0,     0,     0,  1607,  1608,
       0,     0,     0,     0,     0,  1609,     0,     0,  1610,  1611,
       0,     0,     0,  1612,     0,     0,     0,     0,     0,  1613,
    1614,     0,   490,     0,     0,     0,  1615,  1616,  1617,     0,
       0,  1618,  1619,  1620,     0,     0,     0,  1621,  3209,     0,
       0,  1622,     0,  1623,     0,     0,     0,     0,     0,     0,
    1624,  1625,  1626,  1627,     0,  1628,  1629,     0,     0,     0,
    1630,  1631,     0,  1632,  1633,  1634,  1635,  1636,  1637,  1638,
       0,     0,     0,     0,     0,  1639,  1640,  1641,     0,  1642,
    1643,     0,     0,  1226,  1644,  1645,  1646,  1647,  1648,  1649,
    1650,  1651,     0,  1652,     0,     0,     0,  1653,  1654,  1655,
    1656,  1657,  1658,  1659,  1660,  1661,  1662,  1663,  1664,  1665,
    1666,  1667,  1668,  1669,  1670,  1671,  1672,  1673,  1674,  1675,
    1676,  1677,  1678,  1679,  1680,  1681,  1682,  1683,  1684,  1685,
    1686,  1687,  1688,     0,  1689,  1690,     0,     0,  1691,  1692,
    1693,  1694,  1695,  1696,  1697,  1698,  1699,  1700,     0,  1701,
    1702,  1703,  1704,  1705,  1706,  1707,  1708,  1709,  1710,  1711,
    1712,  1713,  1714,  1715,  1114,     0,  1716,  1717,  1718,  1719,
    1720,  1721,  1722,  1723,  1724,     0,  1725,  1726,  1727,  1728,
       0,  1729,  1730,  1731,  1732,  1733,  1734,  1735,  1736,  1737,
    1738,  1739,  1740,  1741,  1742,  1743,  1744,  1745,  1746,  1747,
    1748,  1749,  1750,  1751,  1752,  1753,  1754,  1755,  1756,  1757,
    1758,  1759,  1760,  1761,  1762,  1763,  1764,     0,  1765,  1766,
    1767,  1768,  1769,  1770,     0,     0,  1771,  1772,     0,  1773,
    1774,  1775,  1776,  1777,  1778,  1779,  1780,  1781,  1782,  1783,
    1784,  1785,  1786,  1787,  1788,  1789,  1790,  1791,  1792,  1793,
    1794,  1795,  1796,  1797,  1798,     0,     0,  1799,  1800,  1801,
    1802,  1803,  1804,  1805,  1806,  1807,  1808,  1809,  1810,  1811,
    1812,  1813,  1814,  1815,  1816,  1817,  1818,  1819,  1820,  1821,
    1822,  1823,  1824,  1825,  1826,  1827,  1828,  1829,  1830,  1831,
    1832,  1833,  1834,  1835,  1836,  1837,  1838,  1839,  1840,  1841,
    1842,  1843,  1844,  1845,  1846,  1847,  1848,  1849,  1850,  1851,
    1852,  1853,  1854,  1855,  1856,  1857,  1858,  1859,  1860,     0,
       0,     0,     0,  1861,  1862,  1863,  1864,  1865,  1866,  1867,
    1868,  1869,  1870,  1871,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1872,     0,     0,     0,     0,     0,
       0,     0,  1873,     0,     0,     0,     0,  1874,     0,     0,
       0,  1875,     0,     0,  1876,  1877,  1878,  1879,     0,  1294,
    1880,  1881,     0,  1882,  1883,  1884,  1567,  1568,  1569,  1570,
    1571,  1572,     0,  1573,  1574,  1575,     0,     0,     0,  1576,
    1577,  1578,  1579,  1580,  1581,     0,     0,     0,     0,     0,
    3210,     0,     0,  3211,  1582,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  3212,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1583,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  3214,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  3215,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1584,     0,     0,     0,     0,
       0,     0,     0,     0,  1585,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  3216,
       0,     0,  1586,  1587,     0,     0,     0,     0,     0,     0,
       0,  1588,     0,     0,     0,     0,     0,     0,  1589,  1590,
       0,     0,  1591,  1592,  1593,  1594,     0,     0,  1595,  1596,
       0,     0,     0,     0,     0,     0,     0,     0,  3217,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    3218,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  3219,  3220,     0,     0,     0,     0,  1597,     0,
    3221,     0,     0,  3222,     0,     0,     0,     0,     0,     0,
       0,   293,     0,     0,     0,     0,     0,     0,     0,     0,
    1598,     0,     0,     0,     0,     0,  1599,     0,     0,     0,
       0,     0,     0,  1600,     0,  1601,     0,     0,     0,     0,
    1602,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1603,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1604,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1605,     0,     0,
       0,     0,     0,  1606,     0,     0,     0,     0,     0,     0,
       0,     0,  1607,  1608,     0,     0,     0,     0,     0,  1609,
       0,     0,  1610,  1611,     0,     0,     0,  1612,     0,     0,
       0,     0,     0,  1613,  1614,     0,     0,     0,     0,     0,
    1615,  1616,  1617,     0,     0,  1618,  1619,  1620,     0,     0,
       0,  1621,     0,     0,     0,  1622,     0,  1623,     0,     0,
       0,     0,     0,     0,  1624,  1625,  1626,  1627,     0,  1628,
    1629,     0,     0,     0,  1630,  1631,     0,  1632,  1633,  1634,
    1635,  1636,  1637,  1638,     0,     0,     0,     0,     0,  1639,
    1640,  1641,     0,  1642,  1643,     0,     0,     0,  1644,  1645,
    1646,  1647,  1648,  1649,  1650,  1651,     0,  1652,     0,     0,
       0,  1653,  1654,  1655,  1656,  1657,  1658,  1659,  1660,  1661,
    1662,  1663,  1664,  1665,  1666,  1667,  1668,  1669,  1670,  1671,
    1672,  1673,  1674,  1675,  1676,  1677,  1678,  1679,  1680,  1681,
    1682,  1683,  1684,  1685,  1686,  1687,  1688,     0,  1689,  1690,
       0,     0,  1691,  1692,  1693,  1694,  1695,  1696,  1697,  1698,
    1699,  1700,     0,  1701,  1702,  1703,  1704,  1705,  1706,  1707,
    1708,  1709,  1710,  1711,  1712,  1713,  1714,  1715,     0,     0,
    1716,  1717,  1718,  1719,  1720,  1721,  1722,  1723,  1724,     0,
    1725,  1726,  1727,  1728,     0,  1729,  1730,  1731,  1732,  1733,
    1734,  1735,  1736,  1737,  1738,  1739,  1740,  1741,  1742,  1743,
    1744,  1745,  1746,  1747,  1748,  1749,  1750,  1751,  1752,  1753,
    1754,  1755,  1756,  1757,  1758,  1759,  1760,  1761,  1762,  1763,
    1764,     0,  1765,  1766,  1767,  1768,  1769,  1770,     0,     0,
    1771,  1772,     0,  1773,  1774,  1775,  1776,  1777,  1778,  1779,
    1780,  1781,  1782,  1783,  1784,  1785,  1786,  1787,  1788,  1789,
    1790,  1791,  1792,  1793,  1794,  1795,  1796,  1797,  1798,     0,
       0,  1799,  1800,  1801,  1802,  1803,  1804,  1805,  1806,  1807,
    1808,  1809,  1810,  1811,  1812,  1813,  1814,  1815,  1816,  1817,
    1818,  1819,  1820,  1821,  1822,  1823,  1824,  1825,  1826,  1827,
    1828,  1829,  1830,  1831,  1832,  1833,  1834,  1835,  1836,  1837,
    1838,  1839,  1840,  1841,  1842,  1843,  1844,  1845,  1846,  1847,
    1848,  1849,  1850,  1851,  1852,  1853,  1854,  1855,  1856,  1857,
    1858,  1859,  1860, -2263,     0,     0,     0,  1861,  1862,  1863,
    1864,  1865,  1866,  1867,  1868,  1869,  1870,  1871,     0,     0,
       0,     0, -2263, -2263, -2263,     0,     0, -2263,  1872, -2263,
   -2263,     0,     0,     0,     0,     0,  1873,     0,     0,     0,
       0,  1874,     0,     0,     0,  1875,     0,     0,  1876,  1877,
    1878,  1879,     0,     0,  1880,  1881,     0,  1882,  1883,  1884,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0, -2263,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0, -2263,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0, -2263,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0, -2263,     0, -2263,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0, -2263,     0,     0,     0,     0,     0,     0,
   -2263,     0, -2263,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0, -2263,     0,     0,     0,     0, -2263,     0,
       0,     0,     0,     0,     0,     0, -2263,     0,     0,     0,
   -2263,     0,     0,     0,     0,     0, -2263,     0,     0,     0,
   -2263, -2263, -2263, -2263,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0, -2263,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0, -2263,     0,     0, -2263,     0, -2263,     0,     0,
       0,     0,     0,     1, -2263,     0,     0,     2,     0,     0,
       0,     0,   678,   679,   680,     0,     0, -2263,     0,     0,
       0,   681,     0,     0,   682,     0,     0, -2263,     0,     0,
       0,   683,   684,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0, -2263, -2263,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0, -2263,     0,     0,     0,     0,     0,     0,
       0, -2263,     0,     0,     0, -2263,   685,   686,     0,     0,
       0,   687,     0, -2263, -2263, -2263,     0,     0,     0,     0,
       0,   688,   689,     0,   690,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   691,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   692,     0,     0,   693,   694,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   695,     0,   696,   697,   698,     0,     0,
   -2263,     0,     0,     0,     0,   699,   700,     0,   701,   702,
     703, -2263,     0,     0,     0,     0,   704,     0,     0,   705,
       0,   706,   707,   708,     0,     0,     0,     0,     0,   709,
       0,   710,   711,     0,   712,     0,   713,   714,     0,     0,
     715,     0,     0,   716,   717,   718,   719,   720,   721,     0,
       0, -2263,   722,   723,   724,     0,   725,     0,     0,     0,
     726,     0,   727,   728,     0,     0,     0,     0,   729,     0,
       0,   730,     0,     0,   731,     0,   732,     0,   733,     0,
     734,     0,     0,     0,   735,   736,     0,   737,   738,   739,
       0,     0,   740,     0,   741,   742,     0,   743,     0,     0,
       0,     0,     0,     0,     0,   744,   745,     0,     0,     0,
       0,     0, -2263,     0,     0,     0,     0,     0,   746,     0,
       0,   747,   748,     0,     0,   749,   750,     0,     0,   751,
     752,     0,     0,     0,     0,     0,     0,     0,   753,   754,
     755,     0,   756,     0,     0,     0,     0,     0, -2263,     0,
       0,     0,   757,   758,   759,     0,   760,     0,     0,     0,
     761,   762,     0,     0,     0,   763,     0,     0,     0,     0,
       0,     0,     0,   764,     0,     0,     0,     0,     0,     0,
       0,   765,   766,   767,     0,     0,     0,     0,     0,   768,
     769,     0,     0,     0, -2263,     0,     0,   770,     0,     0,
     771,     0,     0,     0,   772,   773,     0,     0, -2263, -2263,
   -2263, -2263, -2263, -2263, -2263,   774, -2263, -2263,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   775, -2263,     0,     0,     0,     0,     0,     0,
     776,     0,     0,     0,     0,     0,   777,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   778,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   779,
       0,     0,     0,     0,     0,   780,     0,   781,   782,     0,
       0,     0,     0,     0,     0,   783,     0,     0,   455,   456,
     457,     0,   458,   459,   460,   461,   462,   463,   464,   465,
     466,   467,   468,   469,   470,     0,     0,     0,     0,  2560,
    2561,  2562,  2563,  2564,  2565,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   784,     0,     0,     0,   471,     0,
       0,     0,     0,     0,     0,   785,     0,     0,     0,     0,
       0,     0,   786,     0,     0,     0,     0,   455,   456,   457,
       0,   458,   459,   460,   461,   462,   463,   464,   465,   466,
     467,   468,   469,   470,     0,     0,   787,   788,     0,     0,
       0,   789,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   790,     0,     0,     0,   471,     0,   791,
     792,   793,   794,     0,     0,     0,   795,     0,     0,     0,
     796,     0,     0,     0,     0,     0,  2566,   797,   798,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   799,     0,
     800,     0,     0,     0,     0,   472,   473,   474,   475,   476,
     477,   801,     0,   802,     0,     0,   803,     0,     0,     0,
       0,     0,   804,   478,   479,   480,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   805,     0,
       0,   806,     0,     0,     0,     0,   807,     0,     0,   808,
     809,     0,     0,     0,   472,   473,   474,   475,   476,   477,
       0,     0,     0,     0,   810,     0,     0,     0,     0,     0,
       0,   811,   478,   479,   480,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   812,   813,   814,   815,   816,   817,
     818,     0,     0,   819,     0,   820,     0,   821,   455,   456,
     457,     0,   458,   459,   460,   461,   462,   463,   464,   465,
     466,   467,   468,   469,   470,     0,     0,     0,     0,   455,
     456,   457,     0,   458,   459,   460,   461,   462,   463,   464,
     465,   466,   467,   468,   469,   470,     0,     0,   471,     0,
       0,     0,     0,   481,     0,     0,   482,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   455,   456,   457,   471,
     458,   459,   460,   461,   462,   463,   464,   465,   466,   467,
     468,   469,   470,     0,     0,     0,     0,   455,   456,   457,
       0,   458,   459,   460,   461,   462,   463,   464,   465,   466,
     467,   468,   469,   470,     0,     0,   471,     0,     0,     0,
       0,     0,   481,  2567,     0,   482,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  2568,   471,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   472,   473,   474,   475,   476,
     477,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   478,   479,   480,   472,   473,   474,   475,
     476,   477,     0,     0,     0,     0,   483,     0,     0,     0,
       0,     0,     0,     0,   478,   479,   480,     0,  2569,     0,
       0,   484,     0,     0,  2570,   485,   595,     0,     0,     0,
       0,     0,     0,   472,   473,   474,   475,   476,   477,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   478,   479,   480,   472,   473,   474,   475,   476,   477,
       0,   486,     0,  2571,     0,   483,     0,     0,     0,     0,
       0,     0,   478,   479,   480,     0,     0,     0,     0,     0,
     484,     0,     0,     0,   485,   605,     0,  2572,     0,   487,
       0,     0,     0,     0,     0,     0,     0,  2573,  2574,     0,
       0,     0,     0,  2575,     0,     0,     0,   488,     0,     0,
       0,     0,     0,  2576,     0,     0,     0,     0,     0,     0,
     486,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   481,     0,  2577,   482,     0,  2578,  2579,
       0,     0,     0,  2580,     0,     0,     0,     0,   487,     0,
       0,     0,     0,     0,   481,     0,     0,   482,     0,     0,
       0,     0,     0,   455,   456,   457,   488,   458,   459,   460,
     461,   462,   463,   464,   465,   466,   467,   468,   469,   470,
       0,     0,     0,     0,     0,     0,     0,     0,   489,     0,
       0,   481,     0,     0,   482,     0,     0,     0,     0,     0,
    2581,     0,     0,   471,     0,     0,     0,     0,     0,     0,
       0,  2582,   481,     0,     0,   482,     0,     0,     0,     0,
       0,     0,     0,     0,   455,   456,   457,     0,   458,   459,
     460,   461,   462,   463,   464,   465,   466,   467,   468,   469,
     470,     0,     0,     0,     0,     0,     0,   489,     0,     0,
       0,     0,     0,     0,   490,     0,   483,     0,     0,     0,
       0,     0,     0,     0,   471,     0,     0,     0,     0,     0,
       0,   484,     0,     0,     0,   485,   973,   483,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   484,     0,     0,     0,   485,   979,     0,     0,
     472,   473,   474,   475,   476,   477,     0,     0,     0,     0,
       0,   486,     0,   490,   483,     0,     0,     0,   478,   479,
     480,     0,     0,     0,     0,     0,     0,     0,     0,   484,
       0,     0,   486,   485,   980,   483,     0,     0,     0,   487,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     484,     0,     0,     0,   485,   981,     0,   488,     0,     0,
     487,   472,   473,   474,   475,   476,   477,     0,     0,   486,
       0,     0,     0,     0,     0,     0,     0,     0,   488,   478,
     479,   480,     0,     0,     0,     0,     0,     0,     0,     0,
     486,     0,     0,     0,   455,   456,   457,   487,   458,   459,
     460,   461,   462,   463,   464,   465,   466,   467,   468,   469,
     470,     0,     0,     0,     0,   488,     0,     0,   487,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   471,     0,   488,     0,   489,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   481,   489,
       0,   482,     0,     0,     0,     0,   455,   456,   457,     0,
     458,   459,   460,   461,   462,   463,   464,   465,   466,   467,
     468,   469,   470,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   489,     0,     0,     0,
       0,     0,     0,     0,   490,     0,   471,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   489,     0,   481,
       0,     0,   482,     0,     0,   490,     0,     0,     0,     0,
       0,   472,   473,   474,   475,   476,   477,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   478,
     479,   480,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   490,   456,   457,     0,   458,   459,   460,   461,
     462,   463,   464,   465,   466,   467,   468,   469,   470,     0,
       0,   483,     0,   490,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   484,     0,     0,     0,
     485,   982,   471,   472,   473,   474,   475,   476,   477,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   478,   479,   480,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   486,     0,     0,   455,
     456,   457,   483,   458,   459,   460,   461,   462,   463,   464,
     465,   466,   467,   468,   469,   470,     0,   484,     0,     0,
       0,   485,     0,     0,   487,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   471,
       0,     0,   488,     0,     0,     0,     0,     0,     0,   481,
       0,     0,   482,     0,     0,     0,     0,   486,     0,   472,
     473,   474,   475,   476,   477,     0,     0,     0,     0,     0,
     984,     0,     0,     0,     0,     0,     0,   478,   479,   480,
       0,     0,     0,     0,     0,   487,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   488,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   481,     0,   489,   482,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   472,   473,   474,   475,
     476,   477,   466,   467,   468,   469,   470,     0,     0,     0,
       0,     0,     0,     0,   478,   479,   480,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     471,     0,   483,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   489,     0,     0,   484,     0,   490,
       0,   485,     0,   457,     0,   458,   459,   460,   461,   462,
     463,   464,   465,   466,   467,   468,   469,   470,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   481,     0,     0,
     482,     0,     0,     0,     0,     0,     0,   486,     0,     0,
       0,   471,     0,     0,     0,     0,     0,     0,     0,     0,
     985,     0,     0,     0,   483,     0,     0,     0,     0,     0,
     490,     0,     0,     0,     0,   487,     0,     0,     0,   484,
       0,     0,     0,   485,     0,     0,     0,   472,   473,   474,
     475,   476,   477,   488,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   478,   479,   480,     0,     0,
       0,     0,     0,     0,   481,     0,     0,   482,     0,   486,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   988,   458,   459,   460,   461,   462,   463,   464,
     465,   466,   467,   468,   469,   470,     0,   487,   472,   473,
     474,   475,   476,   477,     0,     0,     0,     0,     0,     0,
     483,     0,     0,     0,     0,   488,   478,   479,   480,   471,
       0,     0,     0,     0,   489,   484,     0,     0,     0,   485,
       0,     0,   459,   460,   461,   462,   463,   464,   465,   466,
     467,   468,   469,   470,   460,   461,   462,   463,   464,   465,
     466,   467,   468,   469,   470,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   486,     0,   471,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   471,   463,
     464,   465,   466,   467,   468,   469,   470,   483,     0,     0,
     490,     0,     0,   487,     0,   481,   489,     0,   482,     0,
       0,     0,   484,     0,     0,     0,   485,     0,     0,     0,
     471,   488,     0,     0,     0,     0,   472,   473,   474,   475,
     476,   477,   461,   462,   463,   464,   465,   466,   467,   468,
     469,   470,     0,     0,   478,   479,   480,     0,     0,     0,
       0,     0,   486,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   471,   481,     0,     0,   482,
       0,     0,   490,     0,   472,   473,   474,   475,   476,   477,
     487,     0,     0,     0,     0,   472,   473,   474,   475,   476,
     477,     0,   478,   479,   480,     0,     0,     0,   488,     0,
       0,     0,   489,   478,   479,   480,     0,   462,   463,   464,
     465,   466,   467,   468,   469,   470,     0,   472,   473,   474,
     475,   476,   477,     0,     0,     0,     0,     0,   483,     0,
       0,     0,     0,     0,     0,   478,   479,   480,     0,   471,
       0,     0,     0,   484,     0,     0,     0,   485,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   472,   473,   474,   475,   476,   477,   490,   464,
     465,   466,   467,   468,   469,   470,     0,     0,     0,   489,
     478,   479,   480,   486,   481,     0,     0,   482,     0,   483,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   471,
       0,     0,     0,     0,   484,     0,     0,     0,   485,     0,
       0,   487,     0,   465,   466,   467,   468,   469,   470,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   488,
       0,     0,   481,     0,     0,   482,   472,   473,   474,   475,
     476,   477,   471,   481,   486,   490,   482,     0,     0,     0,
       0,     0,     0,     0,   478,   479,   480,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   487,     0,     0,   481,     0,     0,   482,     0,
       0,     0,     0,     0,     0,  1286,  1287,  1288,     0,     0,
     488,   272,  1289,  1290,    33,     0,   472,   473,   474,   475,
     476,   477,     0,  1291,  1292,     0,     0,   483,     0,     0,
     489,     0,     0,     0,   478,   479,   480,     0,     0,     0,
     481,     0,   484,   482,     0,     0,   485,  1286,  1287,  1288,
       0,     0,     0,   272,  1289,  1290,    33,     0,     0,   472,
     473,   474,   475,   476,   477,  1291,  1292,     0,     0,     0,
       0,     0,     0,     0,     0,   483,     0,   478,   479,   480,
       0,     0,   486,     0,     0,     0,   483,     0,     0,     0,
     484,   489,     0,     0,   485,     0,   490,     0,     0,     0,
       0,   484,     0,  1293,     0,   485,     0,     0,     0,     0,
     487,     0,     0,     0,   481,  1288,     0,   482,   483,   272,
    1289,  1290,    33,     0,     0,     0,     0,     0,   488,     0,
     486,  1291,  1292,   484,     0,     0,     0,   485,     0,     0,
       0,   486,     0,   983,     0,  1293,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   490,   487,     0,
       0,     0,     0,   483,     0,     0,     0,     0,     0,   487,
       0,     0,     0,   486,   481,     0,   488,   482,   484,     0,
       0,     0,   485,     0,     0,     0,     0,   488,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1286,  1287,  1288,
       0,   487,     0,   272,  1289,  1290,    33,     0,     0,   489,
       0,  1293,     0,     0,     0,  1291,  1292,   481,   486,   488,
     482,     0,     0,     0,     0,     0,     0,     0,     0,  1114,
       0,     0,     0,     0,     0,     0,     0,   483,     0,     0,
       0,     0,     0,     0,     0,     0,   487,     0,     0,     0,
       0,     0,   484,     0,     0,     0,   485,   489,     0,     0,
       0,     0,     0,     0,   488,     0,     0,     0,   489,     0,
       0,  1114,  1286,  1287,  1288,   490,     0,     0,   272,  1289,
    1290,    33,     0,     0,     0,     0,     0,     0,     0,     0,
    1291,  1292,   486,     0,     0,  1293,     0,   483,     0,     0,
     489,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   484,     0,     0,     0,   485,     0,     0,     0,
     487,     0,     0,   490,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   490,     0,     0,  1114,   488,     0,
     483,     0,     0,     0,     0,   489,     0,     0,     0,     0,
       0,     0,   486,     0,     0,   484,  1286,  1287,  1288,   485,
       0,     0,   272,  1289,  1290,    33,   490,     0,     0,     0,
    1293,     0,     0,     0,  1291,  1292,     0,     0,     0,     0,
     487,     0,  3207,  3208,     0,     0,     0,     0,   272,  1289,
    1290,    33,     0,     0,     0,   486,     0,     0,   488,     0,
    1291,  1292,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   490,     0,     0,     0,     0,     0,     0,     0,   489,
       0,  1114,     0,   487,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1294,     0,     0,     0,     0,     0,
       0,   488,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1293,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1295,     0,     0,  1296,     0,
       0,     0,     0,     0,     0,     0,  1294,     0,     0,   489,
    3209,  1297,     0,     0,     0,   490,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1114,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1295,  2000,     0,
    1296,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1298,   489,  1297,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1299,     0,     0,     0,     0,     0,     0,
       0,     0,  1294,     0,     0,   490,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  2529,  1298,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1295,  1300,  1299,  1296,     0,     0,     0,
    1114,     0,     0,     0,     0,     0,     0,     0,   490,  1297,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1114,  1301,     0,     0,
       0,     0,     0,  1302,     0,     0,  1300,     0,     0,     0,
       0,     0,  1303,  1304,     0,  1305,  1294,   197,     0,  1298,
       0,     0,     0,   198,     0,     0,     0,  1306,  1307,     0,
       0,  1299,     0,     0,     0,  1308,     0,     0,  1309,  1301,
       0,     0,     0,     0,     0,  1302,   293,  1295,     0,     0,
    1296,     0,     0,     0,  1303,  1304,     0,  1305,     0,     0,
       0,     0,     0,  1297,     0,     0,     0,     0,     0,  1306,
    1307,     0,  1300,     0,     0,     0,     0,  1308,     0,     0,
    1309,     0,     0,     0,     0,     0,     0,     0,   293,     0,
       0,  1294,     0,     0,     0,     0,     0,     0,     0,     0,
     199,     0,  3653,  1298,     0,  1301,     0,     0,     0,     0,
       0,  1302,     0,     0,     0,  1299,   200,   201,     0,     0,
    1303,  1304,  1295,  1305,     0,  1296,   202,     0,     0,     0,
       0,     0,     0,     0,     0,  1306,  1307,     0,  1297,     0,
       0,     0,     0,  1308,     0,     0,  1309,     0,     0,     0,
       0,     0,     0,     0,   293,     0,  1300,     0,  2560,  2561,
    2562,  2563,  2564,  2565,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  2327,     0,     0,  1298,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1301,
    1299,     0,     0,     0,     0,  1302,     0,     0,     0,     0,
       0,  1294,     0,     0,  1303,  1304,  1295,  1305,     0,  1296,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1306,
    1307,     0,  1297,     0,     0,     0,     0,  1308,     0,     0,
    1309,  1300,  3210,     0,     0,  3211,     0,     0,   293,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  3212,     0,
       0,     0,     0,     0,     0,  2566,     0,     0,     0,     0,
       0,     0,  1298,     0,  1301,     0,     0,     0,     0,     0,
    1302,     0,     0,     0,  1299,     0,     0,     0,     0,  1303,
    1304,     0,  1305,     0,     0,     0,     0,     0,  3214,     0,
       0,     0,     0,     0,  1306,  1307,     0,   203,     0,     0,
    3215,     0,  1308,     0,     0,  1309,     0,     0,     0,     0,
       0,     0,     0,   293,     0,  1300,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   204,     0,     0,     0,
       0,  3216,     0,     0,     0,     0,     0,     0,  1301,     0,
       0,     0,     0,     0,  1302,   205,   206,   207,   208,     0,
    3624,     0,     0,  1303,  1304,     0,  1305,     0,     0,     0,
       0,     0,     0,   209,     0,     0,     0,     0,  1306,  1307,
    3217,     0,     0,     0,     0,     0,  1308,     0,     0,  1309,
       0,     0,  3218,     0,     0,   210,     0,   293,     0,     0,
       0,     0,     0,     0,  3219,  3220,     0,   211,     0,     0,
       0,     0,  3221,     0,     0,  3222,     0,  3625,   212,     0,
       0,     0,     0,   293,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   213,     0,     0,     0,     0,     0,
       0,     0,  3626,     0,   214,     0,     0,     0,     0,     0,
       0,  3627,     0,     0,     0,     0,     0,     0,     0,   215,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  3628,
       0,     0,  2567,     0,     0,     0,     0,  3629,     0,   216,
       0,     0,     0,     0,     0,  2568,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   217,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   218,     0,     0,
       0,     0,     0,     0,   219,     0,     0,   220,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  2569,   221,     0,
       0,     0,   222,  2570,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  3630,     0,
       0,   223,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   224,
       0,     0,  2571,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  2572,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  2573,  2574,     0,     0,
       0,   225,  2575,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  2576,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  2577,     0,     0,  2578,  2579,     0,
       0,     0,  2580,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  2581,
       0,     0,     0,     0,     0,     0,     0,     0,  3631,     0,
    2582
};

static const short yycheck[] =
{
       3,     4,     5,   392,   651,     8,   583,   105,   998,   586,
     169,  1051,   188,    45,   714,  1129,  1459,   125,  1169,  1164,
      69,  1144,   259,   260,  1374,  1286,  1287,   635,   791,  2122,
     541,    54,  1126,  2379,   775,   171,  1929,    40,   971,  1140,
    1141,  1367,  1143,   567,  1145,  1146,   593,  2377,  2362,    52,
    2364,    54,  1125,  2325,   257,   258,     5,  2516,    90,  1894,
    1895,   264,    65,  2067,  2672,    20,    27,   116,     5,    72,
    1399,   169,    27,    76,    27,  2448,    79,    80,  2070,   793,
     750,    84,    85,  2061,   715,    27,  2757,  2914,  2915,  2916,
     188,  1321,     5,  1323,     5,  2245,     5,     5,   147,    27,
    2559,   104,     5,   711,    25,    19,    27,  2000,   739,     5,
      27,   811,    26,     8,   722,    19,  1417,  2634,   121,     5,
    2917,   124,    26,   151,  1218,   261,   129,   235,   236,   265,
    2687,   267,  2689,   269,   270,   271,     5,  1251,  1232,     5,
       5,     5,   278,     5,   114,    27,   282,   283,     5,     5,
       5,    24,    25,    26,   785,    25,    45,    27,   781,   318,
    2009,  2010,  2011,  2012,   795,    26,    27,   798,    27,   777,
     114,   802,   780,     5,   223,    27,   225,   808,    19,   810,
       5,   789,  1222,    24,    25,    26,    24,   190,    26,     5,
      24,    25,    26,    27,     5,  2373,  2374,  2375,     5,   279,
    2378,    90,     6,    27,     9,    10,    27,    12,    13,    14,
      15,    16,    17,    27,    20,    24,    25,    26,    27,    25,
     318,    27,   442,    20,   322,     5,   326,     5,    25,   232,
      27,  2257,    25,    26,    27,   238,  3002,   133,   134,   287,
      26,   189,  2913,  2914,  2915,  2916,    27,   250,    24,    25,
      26,    27,   202,   256,   257,   258,   259,   260,   120,    23,
     122,   264,   124,  2441,   481,    24,    25,    26,    27,    24,
      25,    26,    27,    25,    25,    27,    27,    60,   288,    25,
     687,    27,   195,    25,     6,    27,     5,     5,  1151,  1152,
     339,   211,    45,   537,   430,   481,   345,   433,     5,     5,
     393,   545,  2913,  2914,  2915,  2916,   508,   509,   311,   312,
       6,   398,   719,   720,   450,   451,   452,   453,   321,   455,
     456,   457,   458,   459,   460,   461,   462,   463,   464,   465,
     466,   467,   468,   469,   470,   471,   512,   215,  2555,   334,
     672,  1414,   685,   686,    27,   226,   482,   483,  2694,  2621,
     399,   487,   347,   489,   137,   138,    25,  2450,    27,    25,
       5,    27,  2299,  1296,   771,  2302,   502,   503,   504,   505,
     573,  1516,   242,   509,     5,     5,   444,   954,   334,     5,
     723,   242,     5,   726,  1125,     0,   139,   140,   694,   393,
     593,   347,   596,   736,   726,   588,    25,   740,    27,   674,
     626,   744,     5,    97,    98,    99,   100,   101,   751,   413,
       5,   393,     5,   756,   512,   758,   575,   326,  1458,   509,
       5,   764,   697,   326,   767,   142,     5,  2605,   481,   673,
       5,   774,  1063,   242,     5,     5,   457,  2615,   781,    30,
     666,   300,   323,    34,   637,   788,    19,   481,     5,   106,
     107,     5,   444,    26,   760,   508,   799,     5,   675,     5,
     803,   242,     5,   667,   807,    31,   242,   428,   516,   202,
     813,  2652,  1186,   816,   650,   509,     5,   575,   488,   136,
     137,   138,   531,   242,    29,   480,     5,   242,   708,   675,
       5,   242,     5,    25,     5,    27,   242,   444,   501,   304,
     242,     5,     5,     5,     5,  2354,     5,   555,     5,   661,
     542,   543,     5,   296,   105,    27,     5,   588,   618,   300,
     398,   112,   286,   603,   480,  2913,  2914,  2915,  2916,     5,
     444,   534,  2710,     5,   537,   628,  3207,  3208,  1169,  2720,
    3211,     5,   545,     5,   403,     5,  1177,   491,  1179,   786,
     787,   403,   650,    18,    19,    20,    21,    22,   645,   562,
       5,   564,    25,    10,    27,   768,   637,   158,   159,   572,
     573,   639,     5,   576,   447,   166,   242,  2603,   815,   669,
       5,   818,    18,    19,    20,    21,    22,   444,     5,   403,
     593,     5,     5,     5,     5,     5,  3207,  3208,  3364,    25,
    3211,  3272,     9,    10,  3275,    12,    13,    14,    15,    16,
      17,   477,   444,     5,     5,  2887,   564,   645,  2453,   424,
     425,   477,   592,    25,   628,    27,   576,  1250,    30,  2846,
      27,   513,    28,   444,     5,   442,  2814,  2951,   447,   444,
     444,  1048,   559,  1506,     5,  2991,   628,   639,   592,   427,
     611,   521,   477,   542,     5,   116,  3453,   481,   444,     5,
     481,   477,   521,  1070,     5,  1176,    25,    27,   387,   521,
     673,   447,   592,  1414,   479,   678,   679,   680,   681,   682,
     683,   684,   437,  3142,   687,   688,   689,     5,  3205,   692,
     551,   694,   639,   589,   697,   606,   699,   477,   606,  2592,
    1277,  3160,  2639,  1280,  1281,   708,  1420,  3264,   603,   618,
     242,   639,   521,  1360,   600,   618,   719,   720,  1432,   438,
    2070,  2899,   444,  2049,   666,   639,   729,   203,  3058,  3246,
     667,   596,   735,  2883,   603,   639,   600,   444,   741,   742,
     743,   596,  3115,   604,   747,  1269,  3119,   750,   444,   752,
     753,  1421,  3066,   666,  3068,   716,  2760,   760,  3088,   477,
     763,   716,   711,   716,  2742,   768,   769,  3438,   771,  2212,
    2762,   477,   775,  3444,  3445,   778,  3447,  3448,  3449,  3450,
     676,   784,   537,   786,   787,  3456,  1129,   335,   791,   792,
     793,  1422,  1423,  1424,   797,   716,   669,   800,  2099,   716,
    2101,   606,   805,   229,  3475,   667,    27,    27,  1439,   812,
    3418,   814,   815,   675,   817,   818,  2145,   820,   821,  3207,
    3208,   444,   639,  3211,  3432,    27,   419,  3438,   669,   420,
      27,   669,   477,  3444,  3445,   669,  3447,  3448,  3449,  3450,
     242,   444,  3669,   576,   661,  3456,   477,   477,   505,   444,
     986,   477,   481,   989,   301,   661,   444,   718,   600,   444,
     669,   997,   998,   335,   661,   444,  2601,   672,   661,   444,
     229,   444,     5,   444,   444,  3053,  1507,  3055,   117,  1268,
     626,    30,   242,   395,   635,    34,   288,   444,    23,   672,
     444,   403,   404,   669,  1525,   215,   565,   304,   444,  3570,
     297,   444,  3573,  3574,  3575,  3576,  1249,  1250,  1251,   661,
     669,   504,  1543,   310,   669,   444,   428,   722,   723,   431,
     509,   924,   675,  1554,   515,   444,   407,   520,  3599,   444,
     356,   444,   666,   444,   591,   447,   362,   363,   364,   633,
     444,   444,   444,   444,  1552,   444,  3260,   444,  3262,  3263,
      23,   444,   190,   191,  3413,   444,  3564,  1006,   384,  3570,
      10,  2796,  3573,  3574,  3575,  3576,   639,    25,   971,    27,
     563,   688,   689,   690,   691,   692,  3290,   634,   127,   440,
     444,    25,   444,    27,   444,    26,    27,  1394,   661,  3660,
    1537,   347,   439,   509,   441,   294,  1403,   356,  3669,   444,
       5,  3347,   463,   362,   363,   364,    56,   409,  1011,   602,
    1013,   444,   477,  1524,  3192,   412,   607,   424,   425,   444,
     871,   242,   242,  1430,  3202,   384,     5,   444,  2151,     8,
     444,   444,   444,   444,   444,   210,    26,    27,   631,   551,
     378,   477,    25,   412,    27,  1048,     5,   640,  1051,  3660,
    3438,   639,   444,   444,   412,   481,  3444,  3445,  3669,  3447,
    3448,  3449,  3450,   489,  1067,  2138,   492,  1070,  3456,  2002,
     203,  2004,   479,   444,   500,  2425,   444,   437,   398,  2429,
     669,  2014,  2015,   444,   481,   546,   488,   326,  2021,  2022,
    2023,  2024,   604,   444,   444,   297,   687,  2327,   444,   611,
     297,   669,   447,   444,   695,  2199,  1109,  3285,   310,   535,
    3231,  1114,  3458,   310,   407,   517,    18,    19,    20,    21,
      22,  3211,  1125,  2980,   480,  2982,   444,   509,  2985,   526,
     489,    26,    27,   492,   444,   310,  1139,  1140,  1141,   288,
    1143,   500,  1145,  1146,   570,   542,    26,    27,  1151,  1152,
    3422,   286,    14,   669,  2889,  2890,   378,   526,   444,   398,
     588,  2391,  2392,   589,   590,    19,   476,   216,   526,   218,
      24,  2285,    26,   348,   600,   509,   535,   638,    25,   605,
      27,  1184,  3570,  1186,   242,  3573,  3574,  3575,  3576,   650,
     651,   572,  1195,   531,  2184,  1198,  1433,   658,   242,   606,
    1203,   242,    25,   442,    27,   481,   385,   219,   297,   637,
     412,   570,   216,   286,   218,   412,   437,   165,   644,  1222,
    1223,   310,    25,    25,    27,    27,     0,    25,  1231,    27,
     589,   590,  1435,    25,   481,    27,   340,   412,   481,   243,
    2375,   600,    16,  2378,  1247,  1248,   605,  3425,   352,   487,
     676,   426,   242,    26,    27,  1363,   371,  3445,  1366,   242,
     409,  1301,   509,  1303,  1304,   672,   635,   216,  3456,   218,
    1273,   639,  3660,   322,   594,  2208,   325,   635,   799,   481,
     415,  3669,   803,  1286,  1287,   644,   807,   632,  1447,   639,
     635,  3552,  3553,  1296,   243,  1532,  1533,  1148,   347,    26,
      27,  3194,   476,  3617,  1155,   639,  1309,   627,   457,   531,
     708,   481,  3433,  3434,  1317,   722,   723,   676,   322,  3271,
     297,   325,  3274,   412,   526,  3277,   481,   661,  3563,   526,
     521,   729,  3567,   310,  1537,   669,   674,   509,   529,   488,
     542,  3519,   415,   347,   742,   542,    26,   242,  3438,  1447,
      24,   526,    26,   639,  3444,   693,   694,  3447,  3448,  3449,
    3450,    24,   242,    26,   481,  1368,  1389,   542,   517,  1372,
    1373,  1374,    27,   322,   481,   713,   325,    20,  3639,   618,
    3641,  1384,  1385,  1386,    27,   564,  1389,  1390,  1391,  1392,
    1393,  1394,  2325,   481,  2539,   242,   575,  2138,   347,  1976,
    1403,  2334,  1979,   668,  2337,  2338,  2339,  2340,  2734,    20,
     675,  1414,  2762,  1416,   481,  1418,    27,  1420,  1421,   242,
     432,  3278,   258,   259,   260,  1428,  1429,  1430,   481,  1432,
    1433,   480,  1435,  1436,   446,   412,   481,   526,  2478,   242,
     242,  1444,   290,  2673,   242,  2675,   481,  2677,  1451,  1452,
     242,   814,   674,   542,   817,  1458,  1459,   820,   419,   698,
     699,   700,  2093,   508,   509,   481,   419,   674,  2182,   242,
     709,   693,   694,  2173,   674,   481,   480,   489,  2109,    25,
    3570,    27,  2090,  3573,  3574,  3575,  3576,    20,   500,   696,
     697,   713,  2255,  2607,    27,   481,   696,   697,   509,   347,
    1503,  1504,   157,  1506,   481,  2136,  1509,  1510,    25,   521,
      27,  1918,  2143,  1920,  1921,   242,   528,  1924,  1925,  2633,
     719,   720,   721,  1930,   536,    20,   571,  1530,  3621,  1532,
    1533,   480,    27,  3485,  1537,  2249,  1539,    20,  1541,  1542,
     531,  2172,   444,   504,    27,  3638,   558,   389,    20,   526,
     481,   504,   207,   401,   481,    27,   481,   405,   400,   520,
    2191,  1564,   419,   758,   481,   542,    20,   520,   419,   481,
    3660,    19,   767,    27,   290,   481,    24,    25,    26,   685,
     686,   508,   509,   290,   690,   691,    26,   242,  3437,   244,
    3439,  3440,  3441,  3442,    20,   481,  3689,   703,    42,    43,
      44,    27,   563,    47,   481,    49,    50,   481,   450,  2016,
     563,    28,    29,  3706,   419,   451,   481,   723,   813,    26,
     726,   816,   464,   635,   675,    25,   732,    27,   481,   641,
     736,   347,   480,   688,   740,   481,   691,   692,   744,   675,
     347,   602,   748,   749,   571,   751,   481,   504,   754,   602,
     756,   757,   758,   504,  1891,  1892,  2167,    25,   764,    27,
     481,   767,   726,   520,   419,   419,   689,   690,   774,   520,
     631,    24,    25,    26,   481,   781,   740,   481,   631,   640,
     744,    26,   788,   674,  2778,   401,   341,   640,  2621,   405,
     153,   154,   756,   799,   401,  3138,   481,   803,   405,   504,
    2823,   807,   693,   694,  2855,   481,   563,   813,   508,   509,
     816,   553,   563,   691,   692,   520,  2430,   481,  2979,  2980,
    2434,  2982,   713,    24,  2985,    26,  2820,  1149,  1150,  2443,
    2137,  1153,  1154,    26,  2879,    20,    21,  2314,    18,    19,
      20,    21,    22,  2320,  2321,   602,  2679,    26,  3098,   504,
     504,   602,   698,   699,  2468,   410,    26,    24,   563,    26,
      25,  2694,    27,   418,   480,   520,   520,   422,   669,    25,
     212,    27,  2705,   480,   631,   662,   663,   664,   665,    25,
     631,    27,   576,   640,  2127,   227,   228,   481,  2419,   640,
     481,    42,    43,    44,   236,   481,    47,   602,    49,    50,
     698,   699,  3245,   458,  2435,  2436,  2437,  2438,   563,   563,
     161,   162,   163,    24,   973,    26,   481,   976,  2426,   978,
     979,   980,   981,   982,   481,  2456,   631,   481,   270,    61,
      62,    63,    64,   489,    24,   640,    26,   279,   190,   339,
     340,  2831,   194,    25,   500,    27,   481,   602,   602,  2839,
    2840,  2752,  2753,  1961,    20,    21,  2263,   481,   143,   144,
     145,   146,   147,   148,   481,   521,   308,    26,    25,   524,
      27,  2479,   528,    24,   471,    26,   631,   631,   322,   509,
     536,   325,    24,   327,    26,   640,   640,  1890,  1891,  1892,
      25,  2522,    27,    26,  1897,  1898,  1416,   481,  1418,  2035,
    3207,  3208,   558,   347,    26,    26,    26,  2144,   563,  2252,
      26,   353,    26,   357,  1917,  1918,    26,  1920,  1921,   669,
    2528,  1924,  1925,  2856,  1927,   110,   691,  1930,   444,   481,
     414,   669,   587,    26,   378,   444,  2044,  2344,   703,   481,
      18,    19,  2285,   481,     5,   477,    24,    25,    26,    27,
     481,  1954,   184,   444,  2887,   397,   444,   401,    36,    37,
     192,   405,  1965,   444,   444,   444,   521,   732,   481,   201,
     675,    20,   204,    20,  3417,   481,   631,   143,   144,   145,
     146,   147,   148,   748,   749,   640,   444,   481,     5,   754,
     509,  2040,   757,  2624,   481,  2626,   673,    26,   669,  2002,
      26,  2004,   310,    18,    19,    20,    21,  2244,   444,   444,
     477,  2014,  2015,  2016,    30,   247,  2019,  3278,  2021,  2022,
    2023,  2024,   254,  1129,   414,    20,  2229,  2230,    26,    26,
    2166,  2034,    26,  2440,    26,    26,   480,    26,   116,    26,
     639,   444,   444,  1259,    26,   444,   444,   444,  2184,    26,
       5,   444,    20,  2056,  2987,    26,   481,    26,  2061,    26,
      26,   669,   444,     5,  2067,   444,   675,  2070,  2782,   724,
     725,   322,    26,   444,   325,   444,   327,   354,  2655,   311,
     444,  2658,   444,  2660,  2661,  2088,   444,   673,     5,   444,
     444,  2094,   481,   675,    26,   444,   347,    26,   639,   675,
     444,    25,    25,  2817,   336,    25,   357,  3147,   444,    25,
     444,   343,   444,   345,   113,   444,   444,   444,   444,   444,
    2123,   354,   444,   355,   444,   444,   673,   378,   143,   144,
     145,   146,   147,   148,  2137,  2138,   477,   444,  2141,  2142,
     444,  2144,   188,  1249,  1250,  1251,    18,    19,    20,    21,
     401,   383,     8,   674,   405,   669,  2159,  2788,   481,   391,
    2791,  3151,   669,   529,   242,   318,     5,   645,   510,   667,
     667,   645,   471,     5,   708,   510,   669,  2180,   708,  2182,
     380,   646,     5,  2590,   661,   509,     5,   669,   471,   188,
     481,   481,   481,   481,   481,   398,   428,   628,   639,     8,
    2203,    14,  2205,  2206,   250,  2208,   252,   625,  2211,  2212,
       5,     5,  2619,   471,    26,   481,   708,   481,   708,   117,
     452,    26,   268,  3368,  2855,   509,  2229,  2230,  2635,   480,
     276,   142,  3377,    26,   280,    42,    43,    44,   639,   669,
      47,  2244,    49,    50,   481,   291,  2249,  2250,  2251,  3394,
     481,   250,  2255,   252,   481,   481,   481,   489,  2601,   305,
    2263,   481,   481,   481,  2607,   471,   509,    26,   500,   268,
       5,   143,   144,   145,   146,   147,   148,   276,   645,   481,
    2687,   280,  2689,   481,     5,   481,   481,  2290,   675,    45,
    2633,   675,   711,   188,   674,  2298,  2299,   404,     5,  2302,
     606,   666,  2461,    18,   205,    19,   305,  3007,  3008,  3009,
     436,  3011,  3012,  3013,  3014,  3015,  3016,    25,   639,   628,
    3020,     5,  2325,   532,   672,   532,   669,   596,   203,    26,
     375,  2334,   451,   596,  2337,  2338,  2339,  2340,  2341,   596,
      26,  2344,   444,  3457,  2002,  2348,  2349,   481,  3281,  2352,
    3283,    26,   444,   444,   444,   250,   521,   252,   675,   669,
     576,   713,   714,  2461,   675,   444,   598,   599,   600,   447,
    2373,  2374,  2375,   268,     5,  2378,  2379,  2380,   481,   611,
    2383,   276,   481,   481,   481,   280,   481,   109,   669,   639,
     444,  3105,   639,   669,   481,   713,  3541,   596,   666,     5,
     478,   675,     5,   481,     5,   629,     5,   669,  2815,  2412,
     305,  2414,  2415,   674,  2417,  2418,   494,   481,  2421,  3133,
     533,   675,  2425,     5,     8,   371,  2429,  2430,    26,    26,
     117,  2434,   270,     5,   379,     5,   444,  2440,  2441,   481,
    2443,  2444,   481,   413,  2447,  2448,   675,    14,   600,   646,
     709,   596,     5,    26,   481,   533,   534,   151,   675,   811,
     481,   669,   674,     5,   596,  2468,   688,   477,   546,   821,
     675,    26,  2475,   674,     5,  2478,     5,     5,   421,   444,
     312,   444,   714,   444,  2487,   668,   385,    26,  2491,  3422,
       5,   477,   511,   511,   669,  3126,   481,   481,   481,     5,
     481,   481,   481,  3436,  3649,   481,   481,   669,     8,   587,
    3550,   669,     5,  2516,   626,   322,   509,   603,   325,   351,
     327,   379,    25,  3624,  3625,  3626,  3627,  3628,  3629,   398,
     398,  3162,   669,   398,   481,   509,   413,  2540,   370,   371,
     347,   476,     5,     5,   700,   509,  2889,  2890,   626,    26,
     357,     5,     5,  2211,    25,    14,    14,    26,   666,   481,
     638,   645,   645,   603,     5,     5,   444,   481,   444,    26,
     675,   378,   650,   651,   444,     6,   320,   444,   410,     7,
     658,   444,   444,   661,   444,   498,     5,  2590,   669,   444,
     422,   669,    26,    26,   401,   675,    26,    26,   405,    26,
     669,   433,  2605,   669,   444,    20,   326,     5,     5,   616,
    2613,  2614,  2615,     5,     5,  2618,  2619,   449,  2621,   971,
    2652,    20,    21,    22,   596,     8,     5,   459,   717,   444,
     444,  2634,  2635,  3566,   669,  2638,  2639,   481,   521,   675,
       5,     5,   474,   621,  3291,   596,   263,    46,   673,    26,
    3640,   675,   444,  2693,  2813,  2695,   444,  3371,   444,   481,
     481,   675,   675,   675,     5,     5,  2869,    25,  2871,   675,
    3603,   673,  3079,   480,    25,  3389,  2679,  3254,  2854,  3256,
    3257,    25,   514,    25,  2687,   348,  2689,   497,  2720,  2692,
    2826,  2694,    25,   444,    26,  2831,    26,    26,    26,  1051,
      26,    26,  2705,  2839,  2840,   537,   668,  2710,  2711,  2712,
     444,    26,     5,   444,   444,  2813,   481,   518,     5,   481,
     552,  2724,     8,   292,    26,   444,   600,   559,    25,   477,
     562,   444,  3772,   491,   398,    20,  1952,  1953,   194,  2742,
     481,   481,  3373,  1959,   143,   144,   145,   146,   147,   148,
     603,   583,   481,   481,   481,   587,  2854,  2760,   481,  2762,
       5,    40,   161,   162,   163,   481,     5,    14,   263,     5,
     444,   444,  2775,   509,   606,   492,    26,  3408,   444,  2782,
      26,   481,  3715,   444,    26,   444,    26,   427,    26,    26,
     618,    26,   624,   444,   292,   444,   444,   444,   481,   293,
     509,   491,   398,   481,  2807,   596,  2809,   444,  2811,    14,
     444,  2814,  2815,     7,  2817,   444,   291,   291,  3532,    26,
     444,   675,   444,   481,   445,   104,   105,   669,   444,  2832,
     444,  2834,  2835,  2836,    26,   625,   481,    25,   477,   444,
     444,   293,   444,     5,   444,    26,  2849,   115,    26,   444,
     444,   669,   509,  2856,     5,   444,    26,  3264,   669,   477,
    2834,   669,   477,  2775,  3253,  3699,  2869,   997,  2871,  2512,
    1222,  1544,    29,  2913,  2914,  2915,  2916,  2192,  2881,  2882,
    2444,    31,  2807,  2450,  2887,   350,  3123,   112,   116,   205,
     169,   341,  2039,   654,  2040,   531,  2899,   210,   596,  3136,
     351,   223,   301,   379,   550,   304,   562,  1285,   380,   188,
    2913,  2914,  2915,  2916,  2917,  2918,  3689,  2093,   989,  1256,
     171,   564,   412,  2296,  2927,  2303,   797,  2437,  2143,  2932,
    1890,  2858,  3172,  3743,  1286,  1287,  1893,  2219,  2536,  2239,
    2440,  2981,  3385,  2983,  1296,    16,  1435,    90,    40,  3312,
      40,  2197,    22,   753,  2203,  1555,   322,  1013,  3117,  2175,
    1898,  1504,  2206,  1223,  3309,  2968,  2969,   926,  3494,  1429,
    3706,  2856,   778,  1502,  3047,  1418,  2979,  2980,  2172,  2982,
    1525,  3504,  2985,   449,  2987,  3045,  3029,  2723,  2991,  3103,
    3365,  3363,  3356,  3095,  2429,  2073,  2056,  2383,  3715,  2215,
    2601,  3285,  1932,  1932,  3635,  2274,  2620,  3204,  3052,  3519,
    3086,  2344,  2262,  2692,  2968,  3151,  3275,  3594,  3595,  3117,
    3599,  2127,   273,  2969,  3074,   424,  1917,  3328,  3031,  2745,
     281,  2724,   311,   312,     8,  3761,   287,  1252,   289,   318,
     439,  3044,  2712,   322,   443,  3206,  2711,  2900,  2015,   300,
    3053,  3054,  3055,  3283,  1912,  3560,  2014,  1248,  2614,  3201,
    3436,  1885,  3455,  3444,  2034,  2815,  1114,  1444,  2813,  1452,
     540,  2461,    -1,  1434,    -1,    -1,  3079,   328,    -1,    -1,
     479,    -1,    -1,   351,    -1,    -1,    -1,    -1,  3091,  3092,
      -1,    -1,  3095,   344,    -1,  3098,    -1,    -1,   349,    -1,
      -1,    -1,  3105,   371,   372,   373,  1458,  3738,   507,    -1,
     361,    -1,  3115,    -1,  3457,  3118,  3119,   368,    -1,    -1,
    3123,    -1,    -1,    -1,    -1,    -1,   525,    -1,    -1,    -1,
    3133,    -1,    -1,  3136,    -1,  3138,    -1,    -1,    -1,    -1,
      -1,    -1,   410,    -1,  3147,    -1,  2252,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   422,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  3367,   433,    -1,  3207,  3208,    -1,
      -1,  3211,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2285,
      -1,   449,    -1,  3186,    -1,    -1,    -1,    -1,    -1,  3192,
      -1,   459,    -1,    -1,    -1,    -1,    -1,    -1,  3201,  3202,
      -1,  3204,  3205,    -1,  3207,  3208,   474,   606,  3211,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  3222,
      -1,    -1,   501,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   512,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  3245,  3246,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   522,  2913,  2914,  2915,  2916,    -1,
      -1,  3264,    -1,    -1,    -1,   516,    -1,    -1,    -1,  3272,
     521,    -1,  3275,   672,    -1,  3278,    -1,   528,  3281,    -1,
    3283,    -1,  3285,    -1,   552,    -1,    -1,    -1,    -1,    -1,
    2506,  2507,    -1,    -1,   562,    -1,   575,    -1,    -1,   550,
      -1,  2517,    -1,    -1,   555,    -1,  3309,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   583,    -1,    -1,    -1,   587,
      -1,    -1,    -1,    -1,    -1,  2541,  2542,  2543,  2544,  2545,
    2546,    -1,    -1,    -1,    -1,  2551,  2552,  2553,  2554,    -1,
      -1,    -1,  2558,    -1,  3347,    -1,    -1,   615,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   624,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  3367,    -1,    -1,    -1,  3371,    -1,
      -1,   650,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    3556,    -1,    -1,    -1,    -1,    -1,  3389,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  3438,   678,
     679,   680,    -1,   682,  3444,  3445,    -1,  3447,  3448,  3449,
    3450,    -1,    -1,    -1,  3417,    -1,  3456,    -1,    -1,  3422,
     699,    -1,  3425,    -1,  2640,  2641,    -1,    -1,    -1,    -1,
      -1,  2647,  2648,  3436,    -1,  3438,    -1,    -1,    -1,    -1,
      -1,  3444,  3445,    -1,  3447,  3448,  3449,  3450,    -1,    -1,
    3453,    -1,  3455,  3456,    -1,  3458,   735,    -1,  3556,    -1,
      -1,    -1,   741,    -1,   743,    -1,    -1,    -1,   747,    -1,
      -1,   750,    -1,    -1,   753,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   763,    -1,    -1,    -1,    -1,    -1,
      -1,  3494,    -1,    -1,    -1,  2601,  3499,    -1,  3501,   778,
      -1,  2607,    -1,    -1,  3640,   784,    -1,    -1,    -1,    -1,
      -1,    -1,   791,   792,   793,    -1,  3519,    -1,   797,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   805,  2633,    -1,  3532,
    3570,    -1,    -1,  3573,  3574,  3575,  3576,    -1,    -1,    -1,
      -1,    -1,   821,    -1,    -1,    -1,  1898,  3550,    -1,  3207,
    3208,    -1,    -1,  3211,    -1,    -1,    -1,  3560,    -1,    -1,
      -1,    -1,    -1,  3566,    -1,    -1,    -1,  3570,    -1,    -1,
    3573,  3574,  3575,  3576,    -1,  3578,    -1,    -1,    -1,    -1,
      -1,  2797,  2798,    -1,    -1,    -1,    -1,    -1,    -1,  3592,
    2806,    -1,     9,    -1,    -1,    -1,  3599,    -1,    -1,    -1,
    3603,    18,    19,    -1,    -1,    -1,    -1,    24,    25,    26,
      27,    -1,    -1,    -1,  3272,    -1,    -1,  3275,    -1,    -1,
    3660,  3624,  3625,  3626,  3627,  3628,  3629,  2843,  2844,  3669,
      -1,    -1,    -1,  3636,    -1,    -1,    -1,    -1,   312,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    2002,    -1,  2004,    -1,  2870,    -1,  2872,  3660,    -1,    -1,
      -1,    -1,  2014,  2015,    -1,    -1,  3669,    -1,    -1,  2021,
    2022,  2023,  2024,    -1,    -1,    -1,    -1,   351,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   111,    -1,   370,   371,    -1,   116,
      -1,    -1,    -1,    -1,    -1,    -1,   123,    -1,    -1,    -1,
      22,    -1,  3715,    -1,  3717,    -1,    -1,  2933,  2934,    -1,
      -1,  2937,  2938,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   150,    46,    -1,   410,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   422,    -1,
      -1,    -1,    18,    19,    -1,    -1,  3759,  3760,  3761,   433,
      26,    27,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  3772,
      -1,  3774,  1051,    -1,    -1,   449,    -1,    -1,  3436,    -1,
    3438,    -1,    -1,  2889,  2890,   459,  3444,  3445,  1067,  3447,
    3448,  3449,  3450,    -1,    -1,    -1,    -1,    -1,  3456,    -1,
     474,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  3035,
      -1,  2173,    -1,    -1,    -1,   242,    -1,   244,    -1,    -1,
    1109,   143,   144,   145,   146,   147,   148,    -1,    -1,    -1,
     514,    -1,    -1,    -1,    -1,   111,    -1,    -1,    -1,   161,
     162,   163,    -1,    -1,    -1,    -1,  2208,   123,    -1,    -1,
    1139,  1140,  1141,   537,  1143,    -1,  1145,  1146,    -1,    -1,
      -1,    -1,  1151,  1152,    -1,    -1,    -1,    -1,   552,    -1,
      -1,    -1,    -1,    -1,   150,   559,    -1,    -1,   562,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    3116,    -1,    -1,    -1,  3120,    -1,    -1,  1186,    -1,   583,
      -1,    -1,  3570,   587,    -1,  3573,  3574,  3575,  3576,  1198,
      -1,    -1,    -1,  3139,   341,    -1,    -1,    -1,    -1,   346,
      -1,    -1,   606,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  3599,  3158,  1222,  1223,    -1,    -1,    -1,    -1,    -1,
     624,    -1,  1231,    46,    -1,    -1,    -1,    -1,    -1,   376,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1247,  1248,
      -1,    -1,    -1,  2325,    -1,    -1,   242,    -1,   244,    -1,
      -1,    -1,  2334,    -1,    -1,  2337,  2338,  2339,  2340,   301,
      -1,    -1,   304,   410,    -1,    -1,    -1,  2349,    -1,    -1,
      -1,    -1,  3660,    -1,    -1,   422,    -1,    -1,    -1,    -1,
      -1,  3669,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   440,    -1,    -1,    -1,  2379,   445,    -1,
     447,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   458,    -1,    -1,    -1,    -1,   463,    -1,    -1,    -1,
     143,   144,   145,   146,   147,   148,   473,    -1,    -1,    -1,
      -1,   478,    -1,    -1,   481,    -1,    -1,   484,   161,   162,
     163,     9,    -1,    -1,    -1,   341,   493,   494,    -1,    -1,
      18,    19,    20,    -1,    -1,    -1,    24,    25,    26,    27,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    36,    37,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     376,    -1,   424,    -1,    -1,    -1,   533,   534,    -1,    -1,
      -1,   538,    -1,    -1,    -1,    -1,  2478,   439,    -1,   546,
      -1,   443,    -1,    -1,    -1,    -1,    -1,  1416,    -1,  1418,
     557,  1420,  1421,    -1,   410,    -1,   563,    -1,    -1,  1428,
    1429,    -1,    -1,  1432,    -1,    -1,   422,  1436,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   479,  1447,    -1,
     587,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   116,  1458,
    1459,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    3406,    -1,   458,  3409,    -1,   507,    -1,    -1,    -1,    -1,
     125,   126,    -1,   128,   129,   130,    -1,   473,   301,    -1,
      -1,   304,    -1,   525,   631,   481,    -1,    -1,    -1,    -1,
      -1,   638,    -1,   640,  1503,  1504,    -1,  1506,   494,    -1,
    1509,  1510,    -1,   650,   651,    -1,    -1,    -1,    -1,    -1,
      -1,   658,    -1,    -1,    -1,    -1,    -1,  3353,    -1,    -1,
      -1,    -1,   669,    -1,    -1,    -1,    -1,  3363,    -1,    -1,
    1539,    -1,    -1,    -1,    -1,     9,    -1,    -1,    -1,  2621,
      -1,    -1,   538,    -1,    18,    19,    -1,    -1,    -1,    -1,
      24,    25,    26,    27,    -1,  1564,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   606,    -1,    -1,   563,    -1,    -1,
      -1,    -1,    -1,   228,   242,    -1,    -1,   724,   725,    -1,
      -1,   236,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   587,    -1,    -1,    -1,    -1,    -1,  2679,    -1,    -1,
      -1,   424,    -1,    -1,    -1,    -1,    -1,    -1,  3554,    -1,
    2692,    -1,  2694,    -1,    -1,   270,   439,    -1,    -1,    -1,
     443,  3457,    -1,  2705,   279,    -1,    -1,    -1,    -1,    -1,
     672,    -1,    -1,    -1,    -1,   631,    -1,   111,    -1,    -1,
      -1,    -1,   116,    -1,   640,    -1,    -1,    -1,    -1,   123,
      -1,    -1,    -1,   308,   309,    -1,   479,    -1,    -1,  3605,
    3606,    -1,  3608,    -1,  3610,  3611,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  2757,   150,    -1,   346,    -1,
      -1,    -1,    -1,    -1,   507,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   353,    -1,
      -1,    -1,   525,    -1,     5,     6,     7,     8,    -1,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    -1,    -1,    -1,    -1,    -1,    -1,   724,   725,
      -1,  3677,    -1,  3679,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   397,    -1,    -1,    46,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  3713,   242,    -1,
     244,    -1,    -1,    -1,  2856,    -1,    -1,    -1,    -1,   447,
      -1,    -1,    -1,   606,    -1,    -1,  3732,  3733,    -1,    -1,
    3736,    -1,    -1,  3739,    -1,    -1,   451,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  2887,    -1,    -1,    -1,    -1,
     478,    -1,    -1,   481,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   493,   494,    -1,    -1,    -1,
      -1,  2913,  2914,  2915,  2916,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   143,   144,   145,   146,   147,   148,    -1,   672,
      -1,    -1,    -1,   521,    -1,    -1,    -1,    -1,    -1,    -1,
     161,   162,   163,    -1,    -1,    -1,   534,   341,    -1,    -1,
      -1,    -1,   346,    -1,    -1,    -1,    -1,    -1,   546,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  2968,  2969,  1897,  1898,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  2979,  2980,    -1,
    2982,    -1,   376,  2985,    -1,  2987,    -1,    -1,    -1,  2991,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   587,
      -1,    -1,    -1,    -1,    -1,  3007,  3008,  3009,    -1,  3011,
    3012,  3013,  3014,  3015,  3016,    -1,   410,    -1,  3020,    -1,
      -1,    -1,    -1,    -1,    -1,  1954,    -1,    -1,   422,    -1,
      -1,    -1,   620,    -1,    -1,    -1,    -1,    -1,   626,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   440,   635,   636,    -1,
     638,   445,    -1,   447,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   650,   651,   458,    -1,    -1,    -1,    -1,   463,
     658,    -1,    -1,   661,    -1,    -1,    -1,    -1,    -1,   473,
     301,   669,    -1,   304,   478,    -1,    -1,   481,    -1,    -1,
     484,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   493,
     494,    -1,   677,   678,   679,   680,   681,   682,   683,   684,
     685,   686,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   533,
     534,    -1,    -1,    -1,   538,  3147,    -1,    -1,    -1,    -1,
      -1,    -1,   546,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   557,    -1,    -1,    -1,    -1,    -1,   563,
      -1,     5,     6,     7,     8,    -1,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    -1,
      -1,    -1,    -1,   587,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   424,    -1,  3207,  3208,    -1,    -1,  3211,
      -1,    -1,    46,    -1,    -1,    -1,    -1,    -1,   439,    -1,
      -1,    -1,   443,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    2159,    -1,    -1,    -1,    -1,    -1,    -1,   631,    -1,    -1,
      -1,    -1,    -1,    -1,   638,    -1,   640,    -1,    -1,    -1,
      -1,     9,    -1,  2182,    -1,    -1,   650,   651,   479,    -1,
      18,    19,    -1,    -1,   658,    -1,    24,    25,    26,    27,
    3272,    -1,    -1,  3275,  2203,   669,  3278,    -1,    -1,  3281,
      -1,  3283,    -1,  2212,    -1,    -1,   507,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   525,    -1,    -1,    -1,    -1,   143,
     144,   145,   146,   147,   148,    -1,    -1,    -1,    -1,    -1,
    2249,  2250,  2251,    -1,    -1,    -1,  2255,   161,   162,   163,
     724,   725,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  3347,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   111,    -1,    -1,    -1,    -1,   116,    -1,
      -1,  2290,    -1,    -1,    -1,   123,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   606,    -1,    -1,    -1,    -1,
       9,    -1,   150,    -1,    -1,    -1,    -1,    -1,    -1,    18,
      19,    -1,    -1,    -1,    -1,    24,    25,    26,    27,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    3422,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  3436,    -1,  3438,    -1,    -1,    -1,
      -1,    -1,  3444,  3445,    -1,  3447,  3448,  3449,  3450,    -1,
      -1,   672,    -1,    -1,  3456,    -1,  3458,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   301,    -1,    -1,
     304,    -1,    -1,  3475,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   242,    -1,   244,    -1,    -1,    -1,
      -1,    -1,   111,    -1,    -1,    -1,    -1,   116,    -1,    -1,
      -1,  2430,    -1,    -1,   123,  2434,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  2443,    -1,    -1,    -1,    -1,    -1,
       9,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    18,
      19,   150,  2461,    -1,    -1,    24,    25,    26,    27,  2468,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  3550,  2478,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2487,    -1,
      -1,    -1,  2491,    -1,  3566,    -1,    -1,    -1,  3570,    -1,
      -1,  3573,  3574,  3575,  3576,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   341,    -1,    -1,    -1,  2516,   346,    -1,
     424,    -1,    -1,    -1,    -1,    -1,    -1,  3599,    -1,    -1,
      -1,  3603,    -1,    -1,    -1,   439,    -1,    -1,    -1,   443,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   376,    -1,
      -1,    -1,   111,   242,    -1,   244,    -1,   116,    -1,    -1,
      -1,    -1,    -1,    -1,   123,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   479,    -1,    -1,    -1,    -1,
      -1,    -1,   410,    -1,    -1,    -1,    -1,    -1,  3660,    -1,
      -1,   150,    -1,    -1,   422,    -1,    -1,  3669,    -1,    -1,
      -1,    -1,    -1,   507,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   440,    -1,    -1,    -1,    -1,   445,    -1,   447,
      -1,   525,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     458,     9,    -1,    -1,    -1,   463,    -1,    -1,    -1,  2638,
      18,    19,    20,  3715,    -1,   473,    24,    25,    26,    27,
     478,    -1,   341,   481,    18,    19,   484,   346,    36,    37,
      24,    25,    26,    27,    -1,   493,   494,    -1,    -1,    -1,
      -1,    -1,    36,    37,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   242,    -1,   244,    -1,   376,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    3772,    -1,   606,    -1,    -1,    -1,   534,    -1,    -1,    -1,
     538,    -1,  2711,    -1,    -1,    -1,    -1,    -1,   546,    -1,
      -1,   410,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   557,
      -1,   559,    -1,   422,    -1,   563,    -1,    -1,   116,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   440,   116,    -1,    -1,    -1,   445,    -1,   447,   587,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   672,   458,
      -1,    -1,    -1,    -1,   463,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   341,  2782,   473,    -1,    -1,   346,    -1,   478,
      -1,    -1,   481,    -1,    -1,   484,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   631,   493,   494,    -1,    -1,    -1,    -1,
     638,    -1,   640,    -1,  2813,    -1,    -1,   376,  2817,    -1,
      -1,    -1,   650,   651,    -1,    -1,    -1,    -1,    -1,    -1,
     658,    -1,    -1,  2832,    -1,  2834,    -1,  2836,    -1,    -1,
      -1,   669,    -1,    -1,   533,   534,    -1,    -1,    -1,   538,
    2849,   410,    -1,    -1,    -1,  2854,    -1,   546,    -1,    -1,
      -1,    -1,    -1,   422,   242,    -1,    -1,    -1,   557,    -1,
      -1,    -1,    -1,    -1,   563,    -1,    -1,    -1,   242,    -1,
      -1,   440,  2881,  2882,    -1,    -1,   445,    -1,   447,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   724,   725,   587,   458,
      -1,    -1,    -1,    -1,   463,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   473,    -1,    -1,    -1,    -1,   478,
      -1,    -1,   481,    -1,    -1,   484,    -1,    -1,  2927,    -1,
      -1,    -1,    -1,    -1,   493,   494,    -1,    -1,    -1,    -1,
      -1,    -1,   631,    -1,    -1,    -1,    -1,    -1,    -1,   638,
      -1,   640,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   650,   651,    -1,    -1,    -1,    -1,    -1,   346,   658,
      -1,    -1,    -1,    -1,    -1,   534,    -1,    -1,    -1,   538,
     669,    -1,    -1,    -1,    -1,    -1,    -1,   546,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   557,    -1,
      18,    19,    20,    -1,   563,    -1,    24,    25,    26,    27,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    36,    37,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   587,    -1,
      -1,    -1,  3031,    -1,    -1,   724,   725,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  3044,     6,     7,     8,    -1,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    -1,    -1,    -1,    -1,    -1,    -1,   447,
      -1,    -1,   631,    -1,    -1,    -1,    -1,    -1,    -1,   638,
      -1,   640,    -1,   447,    -1,    -1,    46,    -1,    -1,    -1,
      -1,   650,   651,    -1,    -1,    -1,    -1,    -1,   116,   658,
     478,    -1,    -1,   481,    -1,    -1,  3105,    -1,    -1,    -1,
     669,    -1,    -1,    -1,   478,   493,   494,   481,  3117,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     494,    -1,    -1,    -1,  3133,    -1,    -1,    -1,    -1,  3138,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  3147,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   534,   521,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   724,   725,    -1,   546,    -1,
     534,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   546,   143,   144,   145,   146,   147,   148,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   161,   162,   163,    -1,    -1,    -1,    -1,    -1,   587,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   587,   242,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   620,    -1,    -1,    -1,  3245,    -1,   626,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   635,   636,    -1,
     638,    -1,   626,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   650,   651,   638,    -1,    -1,    -1,    -1,    -1,
     658,    -1,    -1,   661,    -1,    -1,   650,   651,    -1,    -1,
      -1,   669,    -1,    -1,   658,    -1,    -1,   661,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   669,    -1,    -1,    -1,    -1,
    3309,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   346,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   301,    -1,    -1,   304,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,     5,     6,     7,     8,     9,    10,    -1,    12,
      13,    14,    -1,    -1,    -1,    18,    19,    20,    21,    22,
      23,    -1,  3371,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      33,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    3389,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    57,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  3417,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   447,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     478,   114,    -1,   481,   424,    -1,    -1,    -1,    -1,    -1,
     123,    -1,    -1,    -1,    -1,   493,   494,    -1,    -1,   439,
      -1,    -1,    -1,   443,   444,    -1,    -1,    -1,   141,   142,
      -1,    -1,    -1,    -1,    -1,  3494,    -1,   150,    -1,    -1,
    3499,    -1,  3501,    -1,   157,   158,    -1,    -1,   161,   162,
     163,   164,    -1,    -1,   167,   168,   534,    -1,    -1,   479,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   546,    -1,
      -1,    -1,    -1,  3532,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   507,    -1,    -1,
      -1,  3550,    -1,    -1,   207,    -1,    -1,  3556,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   525,    -1,    -1,    -1,   587,
      -1,    -1,    -1,    -1,    -1,    -1,   229,    -1,    -1,    -1,
      -1,    -1,   235,    -1,    -1,    -1,    -1,    -1,   241,   242,
      -1,   244,    -1,    -1,    -1,    -1,   249,    -1,    -1,    -1,
      -1,    -1,   620,    -1,    -1,    -1,    -1,    -1,   626,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   635,   636,    -1,
     638,    -1,   275,    -1,    -1,  3624,  3625,  3626,  3627,  3628,
    3629,    -1,   650,   651,    -1,    -1,    24,    25,    26,    27,
     658,    -1,    -1,   661,    -1,    -1,   606,    -1,    36,    37,
      -1,   669,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     313,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   326,    -1,    -1,    -1,    -1,    -1,   332,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   341,   342,
      -1,    -1,    -1,    -1,    -1,   348,    -1,    -1,   351,   352,
      -1,    -1,    -1,   356,    -1,    -1,    -1,    -1,    -1,   362,
     363,    -1,   672,    -1,    -1,    -1,   369,   370,   371,    -1,
      -1,   374,   375,   376,    -1,    -1,    -1,   380,   116,    -1,
      -1,   384,    -1,   386,    -1,    -1,    -1,    -1,    -1,    -1,
     393,   394,   395,   396,    -1,   398,   399,    -1,    -1,    -1,
     403,   404,    -1,   406,   407,   408,   409,   410,   411,   412,
      -1,    -1,    -1,    -1,    -1,   418,   419,   420,    -1,   422,
     423,    -1,    -1,  3772,   427,   428,   429,   430,   431,   432,
     433,   434,    -1,   436,    -1,    -1,    -1,   440,   441,   442,
     443,   444,   445,   446,   447,   448,   449,   450,   451,   452,
     453,   454,   455,   456,   457,   458,   459,   460,   461,   462,
     463,   464,   465,   466,   467,   468,   469,   470,   471,   472,
     473,   474,   475,    -1,   477,   478,    -1,    -1,   481,   482,
     483,   484,   485,   486,   487,   488,   489,   490,    -1,   492,
     493,   494,   495,   496,   497,   498,   499,   500,   501,   502,
     503,   504,   505,   506,   242,    -1,   509,   510,   511,   512,
     513,   514,   515,   516,   517,    -1,   519,   520,   521,   522,
      -1,   524,   525,   526,   527,   528,   529,   530,   531,   532,
     533,   534,   535,   536,   537,   538,   539,   540,   541,   542,
     543,   544,   545,   546,   547,   548,   549,   550,   551,   552,
     553,   554,   555,   556,   557,   558,   559,    -1,   561,   562,
     563,   564,   565,   566,    -1,    -1,   569,   570,    -1,   572,
     573,   574,   575,   576,   577,   578,   579,   580,   581,   582,
     583,   584,   585,   586,   587,   588,   589,   590,   591,   592,
     593,   594,   595,   596,   597,    -1,    -1,   600,   601,   602,
     603,   604,   605,   606,   607,   608,   609,   610,   611,   612,
     613,   614,   615,   616,   617,   618,   619,   620,   621,   622,
     623,   624,   625,   626,   627,   628,   629,   630,   631,   632,
     633,   634,   635,   636,   637,   638,   639,   640,   641,   642,
     643,   644,   645,   646,   647,   648,   649,   650,   651,   652,
     653,   654,   655,   656,   657,   658,   659,   660,   661,    -1,
      -1,    -1,    -1,   666,   667,   668,   669,   670,   671,   672,
     673,   674,   675,   676,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   687,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   695,    -1,    -1,    -1,    -1,   700,    -1,    -1,
      -1,   704,    -1,    -1,   707,   708,   709,   710,    -1,   447,
     713,   714,    -1,   716,   717,   718,     5,     6,     7,     8,
       9,    10,    -1,    12,    13,    14,    -1,    -1,    -1,    18,
      19,    20,    21,    22,    23,    -1,    -1,    -1,    -1,    -1,
     478,    -1,    -1,   481,    33,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   494,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    57,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   534,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   546,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   114,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   123,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   587,
      -1,    -1,   141,   142,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   150,    -1,    -1,    -1,    -1,    -1,    -1,   157,   158,
      -1,    -1,   161,   162,   163,   164,    -1,    -1,   167,   168,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   626,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     638,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   650,   651,    -1,    -1,    -1,    -1,   207,    -1,
     658,    -1,    -1,   661,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   669,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     229,    -1,    -1,    -1,    -1,    -1,   235,    -1,    -1,    -1,
      -1,    -1,    -1,   242,    -1,   244,    -1,    -1,    -1,    -1,
     249,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   275,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   313,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   326,    -1,    -1,
      -1,    -1,    -1,   332,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   341,   342,    -1,    -1,    -1,    -1,    -1,   348,
      -1,    -1,   351,   352,    -1,    -1,    -1,   356,    -1,    -1,
      -1,    -1,    -1,   362,   363,    -1,    -1,    -1,    -1,    -1,
     369,   370,   371,    -1,    -1,   374,   375,   376,    -1,    -1,
      -1,   380,    -1,    -1,    -1,   384,    -1,   386,    -1,    -1,
      -1,    -1,    -1,    -1,   393,   394,   395,   396,    -1,   398,
     399,    -1,    -1,    -1,   403,   404,    -1,   406,   407,   408,
     409,   410,   411,   412,    -1,    -1,    -1,    -1,    -1,   418,
     419,   420,    -1,   422,   423,    -1,    -1,    -1,   427,   428,
     429,   430,   431,   432,   433,   434,    -1,   436,    -1,    -1,
      -1,   440,   441,   442,   443,   444,   445,   446,   447,   448,
     449,   450,   451,   452,   453,   454,   455,   456,   457,   458,
     459,   460,   461,   462,   463,   464,   465,   466,   467,   468,
     469,   470,   471,   472,   473,   474,   475,    -1,   477,   478,
      -1,    -1,   481,   482,   483,   484,   485,   486,   487,   488,
     489,   490,    -1,   492,   493,   494,   495,   496,   497,   498,
     499,   500,   501,   502,   503,   504,   505,   506,    -1,    -1,
     509,   510,   511,   512,   513,   514,   515,   516,   517,    -1,
     519,   520,   521,   522,    -1,   524,   525,   526,   527,   528,
     529,   530,   531,   532,   533,   534,   535,   536,   537,   538,
     539,   540,   541,   542,   543,   544,   545,   546,   547,   548,
     549,   550,   551,   552,   553,   554,   555,   556,   557,   558,
     559,    -1,   561,   562,   563,   564,   565,   566,    -1,    -1,
     569,   570,    -1,   572,   573,   574,   575,   576,   577,   578,
     579,   580,   581,   582,   583,   584,   585,   586,   587,   588,
     589,   590,   591,   592,   593,   594,   595,   596,   597,    -1,
      -1,   600,   601,   602,   603,   604,   605,   606,   607,   608,
     609,   610,   611,   612,   613,   614,   615,   616,   617,   618,
     619,   620,   621,   622,   623,   624,   625,   626,   627,   628,
     629,   630,   631,   632,   633,   634,   635,   636,   637,   638,
     639,   640,   641,   642,   643,   644,   645,   646,   647,   648,
     649,   650,   651,   652,   653,   654,   655,   656,   657,   658,
     659,   660,   661,    23,    -1,    -1,    -1,   666,   667,   668,
     669,   670,   671,   672,   673,   674,   675,   676,    -1,    -1,
      -1,    -1,    42,    43,    44,    -1,    -1,    47,   687,    49,
      50,    -1,    -1,    -1,    -1,    -1,   695,    -1,    -1,    -1,
      -1,   700,    -1,    -1,    -1,   704,    -1,    -1,   707,   708,
     709,   710,    -1,    -1,   713,   714,    -1,   716,   717,   718,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   114,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   142,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   188,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   216,    -1,   218,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   243,    -1,    -1,    -1,    -1,    -1,    -1,
     250,    -1,   252,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   263,    -1,    -1,    -1,    -1,   268,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   276,    -1,    -1,    -1,
     280,    -1,    -1,    -1,    -1,    -1,   286,    -1,    -1,    -1,
     290,   291,   292,   293,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   305,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   322,    -1,    -1,   325,    -1,   327,    -1,    -1,
      -1,    -1,    -1,    30,   334,    -1,    -1,    34,    -1,    -1,
      -1,    -1,    39,    40,    41,    -1,    -1,   347,    -1,    -1,
      -1,    48,    -1,    -1,    51,    -1,    -1,   357,    -1,    -1,
      -1,    58,    59,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   378,   379,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   393,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   401,    -1,    -1,    -1,   405,   103,   104,    -1,    -1,
      -1,   108,    -1,   413,   414,   415,    -1,    -1,    -1,    -1,
      -1,   118,   119,    -1,   121,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   135,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   152,    -1,    -1,   155,   156,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   170,    -1,   172,   173,   174,    -1,    -1,
     480,    -1,    -1,    -1,    -1,   182,   183,    -1,   185,   186,
     187,   491,    -1,    -1,    -1,    -1,   193,    -1,    -1,   196,
      -1,   198,   199,   200,    -1,    -1,    -1,    -1,    -1,   206,
      -1,   208,   209,    -1,   211,    -1,   213,   214,    -1,    -1,
     217,    -1,    -1,   220,   221,   222,   223,   224,   225,    -1,
      -1,   531,   229,   230,   231,    -1,   233,    -1,    -1,    -1,
     237,    -1,   239,   240,    -1,    -1,    -1,    -1,   245,    -1,
      -1,   248,    -1,    -1,   251,    -1,   253,    -1,   255,    -1,
     257,    -1,    -1,    -1,   261,   262,    -1,   264,   265,   266,
      -1,    -1,   269,    -1,   271,   272,    -1,   274,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   282,   283,    -1,    -1,    -1,
      -1,    -1,   592,    -1,    -1,    -1,    -1,    -1,   295,    -1,
      -1,   298,   299,    -1,    -1,   302,   303,    -1,    -1,   306,
     307,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   315,   316,
     317,    -1,   319,    -1,    -1,    -1,    -1,    -1,   628,    -1,
      -1,    -1,   329,   330,   331,    -1,   333,    -1,    -1,    -1,
     337,   338,    -1,    -1,    -1,   342,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   350,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   358,   359,   360,    -1,    -1,    -1,    -1,    -1,   366,
     367,    -1,    -1,    -1,   674,    -1,    -1,   374,    -1,    -1,
     377,    -1,    -1,    -1,   381,   382,    -1,    -1,   688,   689,
     690,   691,   692,   693,   694,   392,   696,   697,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   409,   713,    -1,    -1,    -1,    -1,    -1,    -1,
     417,    -1,    -1,    -1,    -1,    -1,   423,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   434,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   446,
      -1,    -1,    -1,    -1,    -1,   452,    -1,   454,   455,    -1,
      -1,    -1,    -1,    -1,    -1,   462,    -1,    -1,     6,     7,
       8,    -1,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    -1,    -1,    -1,    -1,    52,
      53,    54,    55,    56,    57,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   501,    -1,    -1,    -1,    46,    -1,
      -1,    -1,    -1,    -1,    -1,   512,    -1,    -1,    -1,    -1,
      -1,    -1,   519,    -1,    -1,    -1,    -1,     6,     7,     8,
      -1,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    -1,    -1,   543,   544,    -1,    -1,
      -1,   548,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   560,    -1,    -1,    -1,    46,    -1,   566,
     567,   568,   569,    -1,    -1,    -1,   573,    -1,    -1,    -1,
     577,    -1,    -1,    -1,    -1,    -1,   149,   584,   585,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   595,    -1,
     597,    -1,    -1,    -1,    -1,   143,   144,   145,   146,   147,
     148,   608,    -1,   610,    -1,    -1,   613,    -1,    -1,    -1,
      -1,    -1,   619,   161,   162,   163,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   645,    -1,
      -1,   648,    -1,    -1,    -1,    -1,   653,    -1,    -1,   656,
     657,    -1,    -1,    -1,   143,   144,   145,   146,   147,   148,
      -1,    -1,    -1,    -1,   671,    -1,    -1,    -1,    -1,    -1,
      -1,   678,   161,   162,   163,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   701,   702,   703,   704,   705,   706,
     707,    -1,    -1,   710,    -1,   712,    -1,   714,     6,     7,
       8,    -1,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    -1,    -1,    -1,    -1,     6,
       7,     8,    -1,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    -1,    -1,    46,    -1,
      -1,    -1,    -1,   301,    -1,    -1,   304,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,     6,     7,     8,    46,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    -1,    -1,    -1,    -1,     6,     7,     8,
      -1,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    -1,    -1,    46,    -1,    -1,    -1,
      -1,    -1,   301,   386,    -1,   304,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   399,    46,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   143,   144,   145,   146,   147,
     148,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   161,   162,   163,   143,   144,   145,   146,
     147,   148,    -1,    -1,    -1,    -1,   424,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   161,   162,   163,    -1,   461,    -1,
      -1,   439,    -1,    -1,   467,   443,   444,    -1,    -1,    -1,
      -1,    -1,    -1,   143,   144,   145,   146,   147,   148,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   161,   162,   163,   143,   144,   145,   146,   147,   148,
      -1,   479,    -1,   506,    -1,   424,    -1,    -1,    -1,    -1,
      -1,    -1,   161,   162,   163,    -1,    -1,    -1,    -1,    -1,
     439,    -1,    -1,    -1,   443,   444,    -1,   530,    -1,   507,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   540,   541,    -1,
      -1,    -1,    -1,   546,    -1,    -1,    -1,   525,    -1,    -1,
      -1,    -1,    -1,   556,    -1,    -1,    -1,    -1,    -1,    -1,
     479,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   301,    -1,   578,   304,    -1,   581,   582,
      -1,    -1,    -1,   586,    -1,    -1,    -1,    -1,   507,    -1,
      -1,    -1,    -1,    -1,   301,    -1,    -1,   304,    -1,    -1,
      -1,    -1,    -1,     6,     7,     8,   525,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   606,    -1,
      -1,   301,    -1,    -1,   304,    -1,    -1,    -1,    -1,    -1,
     643,    -1,    -1,    46,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   654,   301,    -1,    -1,   304,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,     6,     7,     8,    -1,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    -1,    -1,    -1,    -1,    -1,    -1,   606,    -1,    -1,
      -1,    -1,    -1,    -1,   672,    -1,   424,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    46,    -1,    -1,    -1,    -1,    -1,
      -1,   439,    -1,    -1,    -1,   443,   444,   424,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   439,    -1,    -1,    -1,   443,   444,    -1,    -1,
     143,   144,   145,   146,   147,   148,    -1,    -1,    -1,    -1,
      -1,   479,    -1,   672,   424,    -1,    -1,    -1,   161,   162,
     163,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   439,
      -1,    -1,   479,   443,   444,   424,    -1,    -1,    -1,   507,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     439,    -1,    -1,    -1,   443,   444,    -1,   525,    -1,    -1,
     507,   143,   144,   145,   146,   147,   148,    -1,    -1,   479,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   525,   161,
     162,   163,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     479,    -1,    -1,    -1,     6,     7,     8,   507,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    -1,    -1,    -1,    -1,   525,    -1,    -1,   507,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    46,    -1,   525,    -1,   606,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   301,   606,
      -1,   304,    -1,    -1,    -1,    -1,     6,     7,     8,    -1,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   606,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   672,    -1,    46,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   606,    -1,   301,
      -1,    -1,   304,    -1,    -1,   672,    -1,    -1,    -1,    -1,
      -1,   143,   144,   145,   146,   147,   148,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   161,
     162,   163,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   672,     7,     8,    -1,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    -1,
      -1,   424,    -1,   672,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   439,    -1,    -1,    -1,
     443,   444,    46,   143,   144,   145,   146,   147,   148,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   161,   162,   163,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   479,    -1,    -1,     6,
       7,     8,   424,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    -1,   439,    -1,    -1,
      -1,   443,    -1,    -1,   507,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    46,
      -1,    -1,   525,    -1,    -1,    -1,    -1,    -1,    -1,   301,
      -1,    -1,   304,    -1,    -1,    -1,    -1,   479,    -1,   143,
     144,   145,   146,   147,   148,    -1,    -1,    -1,    -1,    -1,
     492,    -1,    -1,    -1,    -1,    -1,    -1,   161,   162,   163,
      -1,    -1,    -1,    -1,    -1,   507,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   525,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   301,    -1,   606,   304,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   143,   144,   145,   146,
     147,   148,    18,    19,    20,    21,    22,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   161,   162,   163,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      46,    -1,   424,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   606,    -1,    -1,   439,    -1,   672,
      -1,   443,    -1,     8,    -1,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   301,    -1,    -1,
     304,    -1,    -1,    -1,    -1,    -1,    -1,   479,    -1,    -1,
      -1,    46,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     492,    -1,    -1,    -1,   424,    -1,    -1,    -1,    -1,    -1,
     672,    -1,    -1,    -1,    -1,   507,    -1,    -1,    -1,   439,
      -1,    -1,    -1,   443,    -1,    -1,    -1,   143,   144,   145,
     146,   147,   148,   525,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   161,   162,   163,    -1,    -1,
      -1,    -1,    -1,    -1,   301,    -1,    -1,   304,    -1,   479,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   492,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    -1,   507,   143,   144,
     145,   146,   147,   148,    -1,    -1,    -1,    -1,    -1,    -1,
     424,    -1,    -1,    -1,    -1,   525,   161,   162,   163,    46,
      -1,    -1,    -1,    -1,   606,   439,    -1,    -1,    -1,   443,
      -1,    -1,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   479,    -1,    46,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    46,    15,
      16,    17,    18,    19,    20,    21,    22,   424,    -1,    -1,
     672,    -1,    -1,   507,    -1,   301,   606,    -1,   304,    -1,
      -1,    -1,   439,    -1,    -1,    -1,   443,    -1,    -1,    -1,
      46,   525,    -1,    -1,    -1,    -1,   143,   144,   145,   146,
     147,   148,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    -1,    -1,   161,   162,   163,    -1,    -1,    -1,
      -1,    -1,   479,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    46,   301,    -1,    -1,   304,
      -1,    -1,   672,    -1,   143,   144,   145,   146,   147,   148,
     507,    -1,    -1,    -1,    -1,   143,   144,   145,   146,   147,
     148,    -1,   161,   162,   163,    -1,    -1,    -1,   525,    -1,
      -1,    -1,   606,   161,   162,   163,    -1,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    -1,   143,   144,   145,
     146,   147,   148,    -1,    -1,    -1,    -1,    -1,   424,    -1,
      -1,    -1,    -1,    -1,    -1,   161,   162,   163,    -1,    46,
      -1,    -1,    -1,   439,    -1,    -1,    -1,   443,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   143,   144,   145,   146,   147,   148,   672,    16,
      17,    18,    19,    20,    21,    22,    -1,    -1,    -1,   606,
     161,   162,   163,   479,   301,    -1,    -1,   304,    -1,   424,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    46,
      -1,    -1,    -1,    -1,   439,    -1,    -1,    -1,   443,    -1,
      -1,   507,    -1,    17,    18,    19,    20,    21,    22,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   525,
      -1,    -1,   301,    -1,    -1,   304,   143,   144,   145,   146,
     147,   148,    46,   301,   479,   672,   304,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   161,   162,   163,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   507,    -1,    -1,   301,    -1,    -1,   304,    -1,
      -1,    -1,    -1,    -1,    -1,    18,    19,    20,    -1,    -1,
     525,    24,    25,    26,    27,    -1,   143,   144,   145,   146,
     147,   148,    -1,    36,    37,    -1,    -1,   424,    -1,    -1,
     606,    -1,    -1,    -1,   161,   162,   163,    -1,    -1,    -1,
     301,    -1,   439,   304,    -1,    -1,   443,    18,    19,    20,
      -1,    -1,    -1,    24,    25,    26,    27,    -1,    -1,   143,
     144,   145,   146,   147,   148,    36,    37,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   424,    -1,   161,   162,   163,
      -1,    -1,   479,    -1,    -1,    -1,   424,    -1,    -1,    -1,
     439,   606,    -1,    -1,   443,    -1,   672,    -1,    -1,    -1,
      -1,   439,    -1,   116,    -1,   443,    -1,    -1,    -1,    -1,
     507,    -1,    -1,    -1,   301,    20,    -1,   304,   424,    24,
      25,    26,    27,    -1,    -1,    -1,    -1,    -1,   525,    -1,
     479,    36,    37,   439,    -1,    -1,    -1,   443,    -1,    -1,
      -1,   479,    -1,   492,    -1,   116,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   672,   507,    -1,
      -1,    -1,    -1,   424,    -1,    -1,    -1,    -1,    -1,   507,
      -1,    -1,    -1,   479,   301,    -1,   525,   304,   439,    -1,
      -1,    -1,   443,    -1,    -1,    -1,    -1,   525,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    18,    19,    20,
      -1,   507,    -1,    24,    25,    26,    27,    -1,    -1,   606,
      -1,   116,    -1,    -1,    -1,    36,    37,   301,   479,   525,
     304,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   242,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   424,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   507,    -1,    -1,    -1,
      -1,    -1,   439,    -1,    -1,    -1,   443,   606,    -1,    -1,
      -1,    -1,    -1,    -1,   525,    -1,    -1,    -1,   606,    -1,
      -1,   242,    18,    19,    20,   672,    -1,    -1,    24,    25,
      26,    27,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      36,    37,   479,    -1,    -1,   116,    -1,   424,    -1,    -1,
     606,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   439,    -1,    -1,    -1,   443,    -1,    -1,    -1,
     507,    -1,    -1,   672,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   672,    -1,    -1,   242,   525,    -1,
     424,    -1,    -1,    -1,    -1,   606,    -1,    -1,    -1,    -1,
      -1,    -1,   479,    -1,    -1,   439,    18,    19,    20,   443,
      -1,    -1,    24,    25,    26,    27,   672,    -1,    -1,    -1,
     116,    -1,    -1,    -1,    36,    37,    -1,    -1,    -1,    -1,
     507,    -1,    18,    19,    -1,    -1,    -1,    -1,    24,    25,
      26,    27,    -1,    -1,    -1,   479,    -1,    -1,   525,    -1,
      36,    37,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   672,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   606,
      -1,   242,    -1,   507,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   447,    -1,    -1,    -1,    -1,    -1,
      -1,   525,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   116,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   478,    -1,    -1,   481,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   447,    -1,    -1,   606,
     116,   494,    -1,    -1,    -1,   672,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   242,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   478,   521,    -1,
     481,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   534,   606,   494,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   546,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   447,    -1,    -1,   672,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   533,   534,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   478,   587,   546,   481,    -1,    -1,    -1,
     242,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   672,   494,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   242,   620,    -1,    -1,
      -1,    -1,    -1,   626,    -1,    -1,   587,    -1,    -1,    -1,
      -1,    -1,   635,   636,    -1,   638,   447,    32,    -1,   534,
      -1,    -1,    -1,    38,    -1,    -1,    -1,   650,   651,    -1,
      -1,   546,    -1,    -1,    -1,   658,    -1,    -1,   661,   620,
      -1,    -1,    -1,    -1,    -1,   626,   669,   478,    -1,    -1,
     481,    -1,    -1,    -1,   635,   636,    -1,   638,    -1,    -1,
      -1,    -1,    -1,   494,    -1,    -1,    -1,    -1,    -1,   650,
     651,    -1,   587,    -1,    -1,    -1,    -1,   658,    -1,    -1,
     661,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   669,    -1,
      -1,   447,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     115,    -1,   533,   534,    -1,   620,    -1,    -1,    -1,    -1,
      -1,   626,    -1,    -1,    -1,   546,   131,   132,    -1,    -1,
     635,   636,   478,   638,    -1,   481,   141,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   650,   651,    -1,   494,    -1,
      -1,    -1,    -1,   658,    -1,    -1,   661,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   669,    -1,   587,    -1,    52,    53,
      54,    55,    56,    57,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   447,    -1,    -1,   534,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   620,
     546,    -1,    -1,    -1,    -1,   626,    -1,    -1,    -1,    -1,
      -1,   447,    -1,    -1,   635,   636,   478,   638,    -1,   481,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   650,
     651,    -1,   494,    -1,    -1,    -1,    -1,   658,    -1,    -1,
     661,   587,   478,    -1,    -1,   481,    -1,    -1,   669,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   494,    -1,
      -1,    -1,    -1,    -1,    -1,   149,    -1,    -1,    -1,    -1,
      -1,    -1,   534,    -1,   620,    -1,    -1,    -1,    -1,    -1,
     626,    -1,    -1,    -1,   546,    -1,    -1,    -1,    -1,   635,
     636,    -1,   638,    -1,    -1,    -1,    -1,    -1,   534,    -1,
      -1,    -1,    -1,    -1,   650,   651,    -1,   312,    -1,    -1,
     546,    -1,   658,    -1,    -1,   661,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   669,    -1,   587,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   351,    -1,    -1,    -1,
      -1,   587,    -1,    -1,    -1,    -1,    -1,    -1,   620,    -1,
      -1,    -1,    -1,    -1,   626,   370,   371,   372,   373,    -1,
     254,    -1,    -1,   635,   636,    -1,   638,    -1,    -1,    -1,
      -1,    -1,    -1,   388,    -1,    -1,    -1,    -1,   650,   651,
     626,    -1,    -1,    -1,    -1,    -1,   658,    -1,    -1,   661,
      -1,    -1,   638,    -1,    -1,   410,    -1,   669,    -1,    -1,
      -1,    -1,    -1,    -1,   650,   651,    -1,   422,    -1,    -1,
      -1,    -1,   658,    -1,    -1,   661,    -1,   311,   433,    -1,
      -1,    -1,    -1,   669,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   449,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   336,    -1,   459,    -1,    -1,    -1,    -1,    -1,
      -1,   345,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   474,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   383,
      -1,    -1,   386,    -1,    -1,    -1,    -1,   391,    -1,   514,
      -1,    -1,    -1,    -1,    -1,   399,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   537,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   552,    -1,    -1,
      -1,    -1,    -1,    -1,   559,    -1,    -1,   562,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   461,   583,    -1,
      -1,    -1,   587,   467,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   482,    -1,
      -1,   606,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   624,
      -1,    -1,   506,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   530,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   540,   541,    -1,    -1,
      -1,   666,   546,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   556,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   578,    -1,    -1,   581,   582,    -1,
      -1,    -1,   586,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   643,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   652,    -1,
     654
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const unsigned short yystos[] =
{
       0,    30,    34,   127,   288,   409,   457,   488,   517,   785,
     812,   813,   869,  1041,  1097,  1099,  1100,  1101,  1106,  1108,
    1121,  1122,  1123,  1124,  1125,  1568,    28,    29,   786,   787,
     788,   789,   790,    27,  1005,  1583,  1005,    25,  1005,  1473,
    1126,   814,  1473,   813,     0,  1098,  1101,  1124,    31,   788,
     790,   870,   661,    25,   242,   811,   812,   992,  1005,  1010,
    1106,  1121,  1127,  1162,  1163,  1164,  1165,  1166,  1170,   407,
     816,   817,   818,   819,   822,   823,   105,   112,   158,   159,
     166,   420,   515,   607,   687,   695,   785,   964,  1040,  1102,
    1103,  1105,  1109,  1110,  1116,  1128,  1149,  1282,  1292,  1568,
     666,  1005,  1165,   294,   508,   509,  1171,    20,  1005,  1169,
     669,   817,     5,   815,   407,  1005,     5,   841,   843,   844,
    1005,  1293,  1005,  1005,  1283,  1117,  1005,  1005,  1105,  1111,
     312,   351,   370,   371,   410,   422,   433,   449,   459,   474,
     514,   537,   552,   559,   562,   583,   587,   606,   624,   871,
     872,   873,   876,    25,  1162,  1168,    18,    19,    26,   111,
     123,   150,   244,   341,   376,   410,   422,   458,   473,   481,
     494,   538,   563,   587,   631,   640,   724,   725,   735,   737,
     929,   934,   945,   947,  1005,  1162,  1172,  1173,   509,    14,
     868,   819,   572,  1269,   820,   817,   822,    32,    38,   115,
     131,   132,   141,   312,   351,   370,   371,   372,   373,   388,
     410,   422,   433,   449,   459,   474,   514,   537,   552,   559,
     562,   583,   587,   606,   624,   666,   826,   835,   846,   851,
    1005,   481,   165,  1005,   811,   965,  1150,  1005,   878,   371,
     824,   481,   854,   856,   857,   855,   864,   865,   481,   481,
     877,   509,   481,   817,   852,   476,   481,   481,   481,   481,
     481,   481,   481,   481,   481,   481,   735,   481,   808,     9,
      18,    19,    24,    25,    26,   116,   346,   440,   445,   447,
     463,   478,   481,   484,   493,   534,   546,   557,   587,   638,
     650,   651,   658,   669,   905,   913,   914,   915,   916,   917,
     945,   946,   948,  1011,  1162,  1272,  1465,   481,   481,   481,
     481,   481,   481,    18,    19,    20,    21,    22,   736,    26,
     481,   571,     5,   477,  1172,    25,    26,  1005,  1011,    19,
      25,    26,   821,  1011,   719,   720,   721,   825,   848,   837,
     849,   824,   481,   481,   481,   838,   854,   855,   481,   481,
     836,   509,   847,   481,   852,   817,   845,   481,    26,  1005,
     481,  1118,   811,   811,   481,  1005,   481,   508,   830,    26,
     675,   419,   504,   520,   563,   602,   631,   640,   858,   675,
     419,   504,   520,   563,   602,   631,   640,   866,    26,    26,
     879,   880,   881,   882,  1005,    26,   833,   834,    26,   669,
     716,   953,   996,  1005,   996,   996,   953,   953,   905,    24,
      25,    26,    19,    24,    25,    26,   949,   950,   951,   952,
      25,   954,   996,   997,   905,   444,   905,   905,   905,   905,
     576,  1289,   481,   481,   905,   419,   504,   520,   563,   602,
     631,   640,  1468,  1469,   481,   905,   905,   481,   481,   918,
     481,   481,   481,   481,    26,     6,     7,     8,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    46,   143,   144,   145,   146,   147,   148,   161,   162,
     163,   301,   304,   424,   439,   443,   479,   507,   525,   606,
     672,   807,   906,   919,   921,   922,   923,   924,   925,   926,
     927,   471,   937,   935,   941,   939,  1162,  1162,   735,   930,
    1005,  1173,   509,   477,    26,   828,   481,   850,   817,   850,
     830,    26,    26,    26,   817,    26,    26,   816,   833,   850,
      26,   669,   110,   842,  1294,   444,   481,  1284,  1584,  1585,
    1586,  1587,  1588,   966,  1151,  1112,   669,    26,   444,   859,
     860,   481,   861,   866,   867,   861,   481,   862,     5,   444,
       5,   444,     5,   335,     5,   871,   477,     5,     5,   444,
     817,   853,   481,     5,   444,   509,   669,   444,   444,   444,
     444,   444,   444,   444,    19,    26,   444,   639,   950,    19,
      26,   639,   444,     5,   444,   444,     5,   809,   905,   521,
    1489,   905,   481,   675,    20,   444,  1489,    20,  1272,   905,
     905,   905,   905,   905,   905,   905,   905,   905,   905,   905,
     905,   905,   905,   905,   905,   905,   905,   905,   905,   905,
     905,   905,   481,   905,   905,   481,  1162,   905,   905,   905,
     905,   444,     5,   533,   765,   766,   767,   905,   481,  1172,
     509,   673,    26,   669,    26,   444,   444,     5,   444,   310,
       5,   444,     5,   444,   335,   477,     5,   444,   853,  1005,
    1178,  1179,  1181,  1129,  1178,   414,  1585,  1269,    39,    40,
      41,    48,    51,    58,    59,   103,   104,   108,   118,   119,
     121,   135,   152,   155,   156,   170,   172,   173,   174,   182,
     183,   185,   186,   187,   193,   196,   198,   199,   200,   206,
     208,   209,   211,   213,   214,   217,   220,   221,   222,   223,
     224,   225,   229,   230,   231,   233,   237,   239,   240,   245,
     248,   251,   253,   255,   257,   261,   262,   264,   265,   266,
     269,   271,   272,   274,   282,   283,   295,   298,   299,   302,
     303,   306,   307,   315,   316,   317,   319,   329,   330,   331,
     333,   337,   338,   342,   350,   358,   359,   360,   366,   367,
     374,   377,   381,   382,   392,   409,   417,   423,   434,   446,
     452,   454,   455,   462,   501,   512,   519,   543,   544,   548,
     560,   566,   567,   568,   569,   573,   577,   584,   585,   595,
     597,   608,   610,   613,   619,   645,   648,   653,   656,   657,
     671,   678,   701,   702,   703,   704,   705,   706,   707,   710,
     712,   714,   728,   729,   730,   731,   748,   770,   784,   785,
     791,   810,   884,   885,   886,   887,   898,   899,   900,   901,
     902,   903,   904,   955,   959,   990,  1012,  1014,  1017,  1018,
    1019,  1020,  1033,  1042,  1066,  1067,  1069,  1073,  1088,  1089,
    1093,  1094,  1095,  1096,  1104,  1119,  1132,  1143,  1144,  1145,
    1156,  1159,  1193,  1196,  1198,  1204,  1205,  1208,  1211,  1214,
    1216,  1218,  1221,  1228,  1233,  1238,  1239,  1240,  1252,  1253,
    1256,  1262,  1264,  1265,  1290,  1305,  1306,  1307,  1308,  1309,
    1321,  1327,  1328,  1348,  1351,  1380,  1382,  1474,  1475,  1506,
    1507,  1514,  1529,  1553,  1568,  1569,  1574,  1575,  1577,  1581,
    1582,  1589,   785,  1107,   674,   697,  1152,  1153,  1178,    20,
     444,   476,   831,   858,    26,   863,    26,    26,    26,   880,
     882,   874,   834,    26,  1005,   996,   735,    20,   716,  1005,
     943,  1469,   943,    26,   444,   639,   943,    24,    26,    26,
     639,    24,    26,   855,   944,   997,   856,   444,   412,   526,
     635,  1497,   444,   444,    26,  1469,   444,   444,   444,   444,
     444,   444,   444,   492,   492,   492,   928,  1489,   492,   928,
    1489,   938,   936,   942,   940,    26,   931,     5,   932,   477,
    1172,   841,   444,    20,   831,    26,   481,    26,    26,   827,
      26,   669,   444,     5,  1178,   444,  1162,  1162,  1162,  1005,
      25,  1162,  1215,  1005,    25,  1005,  1458,   403,  1006,  1007,
    1583,  1006,    25,  1005,  1457,  1005,  1005,  1236,  1000,  1006,
    1000,  1005,  1579,  1458,  1005,    26,   732,  1162,  1312,  1000,
    1236,   928,    26,  1011,  1277,  1278,  1277,   905,   912,  1350,
    1457,  1457,   907,   928,  1006,  1515,  1515,   888,  1236,  1000,
    1310,  1162,  1002,  1006,   912,  1515,  1162,  1236,  1162,  1349,
    1515,    25,   635,  1146,  1147,  1162,  1000,  1000,  1146,  1001,
    1006,  1005,  1147,  1000,  1515,  1000,  1002,  1458,  1162,  1191,
    1192,   998,  1006,  1002,   428,   611,   996,  1068,  1005,   792,
    1457,  1003,  1006,    25,   242,  1005,  1381,  1557,  1559,  1560,
    1561,  1562,  1564,   928,  1191,   675,   928,  1006,  1217,   960,
      61,    62,    63,    64,   184,   192,   201,   204,   247,   254,
     311,   336,   343,   345,   355,   383,   391,   428,   452,   489,
     500,   598,   599,   600,   611,   714,  1082,  1212,  1213,  1162,
    1183,  1184,   911,   912,  1227,   953,   953,   999,  1006,   928,
    1215,  1291,  1162,  1268,    25,  1162,  1509,  1263,   912,  1570,
     157,   207,   244,   341,   418,   458,   524,   749,   934,  1005,
    1162,  1300,   772,   912,   998,   639,  1005,  1013,  1133,   912,
     998,    26,  1162,  1090,   998,   912,  1530,   912,  1277,  1005,
    1015,  1016,  1002,  1015,   953,  1002,  1015,   953,  1021,  1015,
      25,    26,   437,   537,  1011,  1071,  1162,  1180,  1182,   117,
     326,   398,   442,   618,   698,   699,   700,   709,   739,  1023,
    1025,  1027,  1029,  1031,  1157,  1158,  1161,   389,   400,   450,
     464,   553,  1383,   689,   690,   968,   969,   970,  1005,  1154,
     696,  1153,   444,   354,   444,   444,   444,   444,   673,     5,
     444,   444,   477,   481,   675,    19,    26,   444,   943,    26,
     444,   444,   639,    26,   639,   675,    18,    19,    20,    25,
      26,    36,    37,   116,   447,   478,   481,   494,   534,   546,
     587,   620,   626,   635,   636,   638,   650,   651,   658,   661,
    1005,  1011,  1464,  1466,  1496,  1498,  1499,  1501,  1502,  1503,
    1525,  1526,  1527,  1528,  1558,  1559,  1563,  1289,   444,  1289,
    1289,  1289,  1289,  1289,  1289,    25,    25,    25,   905,   920,
     444,    25,   920,   444,   444,   444,   444,   444,   444,   444,
     767,   765,   477,   354,   444,   817,   839,   840,   444,   444,
     673,   444,  1005,  1295,  1181,   444,  1285,   106,   107,   136,
     137,   138,   505,   591,   634,  1329,  1330,  1331,  1334,  1337,
    1340,  1341,  1342,  1345,   669,   639,   661,   153,   154,   481,
     669,   639,   661,     8,   674,   477,  1457,   529,  1237,  1180,
     161,   162,   163,   645,   533,   908,   909,   912,  1162,  1187,
    1457,   738,   739,   891,   318,    45,   139,   140,   675,  1234,
     510,     5,   668,   675,   667,   667,  1194,   645,   471,     5,
     606,  1043,   510,   708,  1572,   708,   437,   794,  1162,   596,
     667,  1199,  1200,  1201,   669,    25,  1560,   509,  1565,   380,
    1379,   661,   669,   910,   912,   606,  1557,   910,     8,   603,
     999,    26,   551,   604,   718,   991,  1162,   991,   991,   991,
      25,   229,   356,   362,   363,   364,   384,   489,   492,   500,
     535,   570,   589,   590,   600,   605,   644,   676,  1086,  1087,
     991,   991,   646,  1083,   739,  1083,  1083,   992,   992,  1083,
    1083,   739,     5,   471,     5,   387,   438,     5,   738,   133,
     134,   589,   676,  1074,   711,  1573,   911,   662,   663,   664,
     665,  1267,  1269,   912,  1258,  1259,  1260,  1270,  1271,   912,
     481,   481,   481,   481,    25,   768,  1005,   481,  1509,   398,
     481,   571,   639,   628,   773,   780,   771,  1005,    25,  1148,
    1162,  1254,     8,  1257,    14,  1005,  1167,  1174,  1175,  1177,
    1185,  1186,  1229,   215,   398,   594,   627,     5,     6,     7,
       8,     9,    10,    12,    13,    14,    18,    19,    20,    21,
      22,    23,    33,    57,   114,   123,   141,   142,   150,   157,
     158,   161,   162,   163,   164,   167,   168,   207,   229,   235,
     242,   244,   249,   275,   313,   326,   332,   341,   342,   348,
     351,   352,   356,   362,   363,   369,   370,   371,   374,   375,
     376,   380,   384,   386,   393,   394,   395,   396,   398,   399,
     403,   404,   406,   407,   408,   409,   410,   411,   412,   418,
     419,   420,   422,   423,   427,   428,   429,   430,   431,   432,
     433,   434,   436,   440,   441,   442,   443,   444,   445,   446,
     447,   448,   449,   450,   451,   452,   453,   454,   455,   456,
     457,   458,   459,   460,   461,   462,   463,   464,   465,   466,
     467,   468,   469,   470,   471,   472,   473,   474,   475,   477,
     478,   481,   482,   483,   484,   485,   486,   487,   488,   489,
     490,   492,   493,   494,   495,   496,   497,   498,   499,   500,
     501,   502,   503,   504,   505,   506,   509,   510,   511,   512,
     513,   514,   515,   516,   517,   519,   520,   521,   522,   524,
     525,   526,   527,   528,   529,   530,   531,   532,   533,   534,
     535,   536,   537,   538,   539,   540,   541,   542,   543,   544,
     545,   546,   547,   548,   549,   550,   551,   552,   553,   554,
     555,   556,   557,   558,   559,   561,   562,   563,   564,   565,
     566,   569,   570,   572,   573,   574,   575,   576,   577,   578,
     579,   580,   581,   582,   583,   584,   585,   586,   587,   588,
     589,   590,   591,   592,   593,   594,   595,   596,   597,   600,
     601,   602,   603,   604,   605,   606,   607,   608,   609,   610,
     611,   612,   613,   614,   615,   616,   617,   618,   619,   620,
     621,   622,   623,   624,   625,   626,   627,   628,   629,   630,
     631,   632,   633,   634,   635,   636,   637,   638,   639,   640,
     641,   642,   643,   644,   645,   646,   647,   648,   649,   650,
     651,   652,   653,   654,   655,   656,   657,   658,   659,   660,
     661,   666,   667,   668,   669,   670,   671,   672,   673,   674,
     675,   676,   687,   695,   700,   704,   707,   708,   709,   710,
     713,   714,   716,   717,   718,  1531,  1532,  1533,  1535,   625,
       5,   708,   708,   910,  1180,  1187,  1070,   471,     5,   203,
    1048,   481,  1162,   910,   481,    26,    26,   117,  1160,    25,
    1162,  1513,  1513,  1006,  1363,  1217,   999,   171,   273,   281,
     287,   289,   300,   328,   344,   349,   361,   368,   516,   521,
     528,   550,   555,  1352,  1353,  1361,  1370,  1371,  1377,  1378,
    1384,  1385,  1395,  1415,  1419,  1485,  1486,  1516,  1517,  1520,
    1521,  1537,   971,   972,   142,   967,   978,   979,   970,  1155,
    1584,  1113,   509,   871,   834,   669,  1005,   419,   504,   520,
     563,   602,   631,   640,  1470,    26,   444,   639,   943,   444,
     639,   943,   943,    24,    26,   639,    24,    26,   859,  1502,
    1502,   419,   504,   520,   563,   602,   631,   640,  1467,  1471,
     521,  1501,   481,   481,   481,   481,  1496,  1496,  1496,   481,
     481,   481,   481,  1005,   481,     5,   596,  1424,  1429,   666,
    1005,    18,    19,    20,    21,   143,   144,   145,   146,   147,
     148,  1523,  1471,  1471,   471,     5,   444,   444,   933,   509,
       5,   444,   841,   811,  1130,   811,   297,   310,   412,   481,
     526,   542,  1399,  1400,  1405,  1407,   481,  1005,  1346,  1347,
      26,   481,  1005,  1326,  1339,  1407,  1409,   481,  1005,  1336,
     481,  1326,  1332,     5,  1005,    25,  1005,  1005,    25,  1008,
    1165,  1005,    25,  1005,  1005,  1005,  1580,  1457,   645,   481,
     481,   891,  1457,     5,   675,   481,  1557,    25,  1010,  1235,
    1234,  1235,  1509,  1146,   912,   912,   912,   993,   994,   481,
    1162,  1192,  1044,  1045,  1046,  1457,   675,  1509,   953,  1573,
    1068,  1162,   793,   674,   912,   404,  1203,   606,  1202,  1561,
     735,  1566,  1567,  1005,    20,  1562,     5,  1554,   666,  1209,
     120,   122,   124,   667,   675,   883,  1180,  1183,   961,    18,
      19,   481,  1084,  1086,  1213,  1162,  1184,   992,   912,   398,
     645,    26,  1162,    26,  1162,   738,   205,  1266,   436,  1304,
    1269,  1260,     5,   667,  1261,  1571,  1005,    25,   953,   953,
     639,   997,   672,  1162,   753,  1005,  1005,   912,   393,   776,
     780,   628,   774,   782,    23,   286,  1135,  1139,   532,   928,
     532,  1255,   912,   508,  1171,   669,     5,  1091,   596,  1230,
    1162,  1534,  1536,   241,  1532,  1034,  1016,   953,   953,  1026,
    1027,  1048,  1048,    42,    43,    44,    47,    49,    50,   322,
     325,   327,   347,   357,   378,   401,   405,   480,  1047,  1049,
    1050,  1078,  1162,  1182,   596,   740,    26,   451,  1032,   375,
    1508,  1508,   190,   191,   487,   596,  1005,  1416,  1417,  1459,
    1457,  1457,  1457,  1354,  1457,  1457,  1005,  1518,   219,   432,
     446,   489,   500,   521,   528,   536,   558,   635,   641,  1386,
    1388,  1389,  1390,  1497,  1457,  1362,  1386,  1388,  1584,  1584,
     437,   980,  1162,   691,   692,   973,   974,   975,   531,   674,
     693,   694,   713,   983,   984,  1584,   811,    26,   832,    20,
    1005,   444,   481,    26,   444,   943,    26,   943,    24,    26,
     444,   444,    24,    26,   675,  1497,   444,   447,  1501,  1524,
    1563,   412,   526,   635,  1448,  1501,  1504,  1448,  1448,  1448,
    1448,   669,  1504,  1499,   565,  1425,  1426,  1427,  1457,   576,
    1423,  1430,   385,   564,   575,  1372,  1492,  1005,  1501,  1501,
    1501,  1501,   675,   481,   675,  1558,   905,   444,   832,   840,
    1296,   811,  1286,   481,   481,   481,  1343,  1407,   481,   481,
     109,  1344,  1346,     5,  1338,  1339,   115,   351,   371,   372,
     373,   410,   422,   433,   449,   459,   474,   522,   552,   562,
     583,   587,   615,   624,  1449,  1450,  1451,  1453,  1335,  1336,
    1332,  1333,   713,  1330,   669,   639,   444,   669,   639,   596,
    1578,   481,   733,   734,  1005,  1313,   928,   908,  1005,  1311,
     666,  1206,  1234,  1234,   675,     5,     5,     5,   629,   912,
       5,   669,   533,   675,   674,   216,   218,   322,   325,   795,
     798,   799,  1078,   796,   797,  1005,   481,  1006,   698,   699,
    1207,     5,   477,   912,  1457,  1555,  1556,  1557,   626,   666,
    1210,  1005,  1005,   994,   995,   559,   953,   891,     8,     8,
     963,    26,    26,  1085,  1086,  1162,   371,  1222,   117,   905,
    1269,   270,  1271,  1277,  1584,     5,     5,   444,   444,   769,
    1005,   444,  1509,   765,   481,   481,   781,   777,   413,   775,
     912,   393,   778,   782,   646,  1080,  1140,  1136,   415,  1134,
    1135,   910,   675,  1168,    20,  1005,  1176,  1186,    14,   533,
    1231,  1232,  1501,  1563,  1183,  1584,  1028,  1029,   600,  1004,
     596,  1061,  1060,  1059,  1058,  1063,  1062,   996,  1064,   996,
    1065,  1057,  1056,  1054,  1053,  1079,   378,  1050,  1055,   953,
      52,    53,    54,    55,    56,    57,   149,   386,   399,   461,
     467,   506,   530,   540,   541,   546,   556,   578,   581,   582,
     586,   643,   654,   741,   742,  1076,  1077,     5,    26,  1509,
     300,  1162,   521,  1490,  1491,  1509,  1217,  1484,  1486,   151,
     151,   645,  1215,  1418,  1419,   481,  1396,   202,  1430,  1457,
     226,   323,  1522,   669,   675,   481,  1391,  1391,   596,   674,
       5,  1487,  1538,   395,   404,   428,   431,   447,   551,   604,
     611,   999,  1364,  1369,   675,   674,   982,  1162,     5,   596,
     976,   977,   688,   975,   981,  1005,   981,   985,   986,   981,
     378,   984,  1114,   477,    26,   444,   639,   943,   444,   639,
     444,   444,   943,   943,   419,   504,   520,   563,   602,   631,
     640,  1472,  1498,     5,  1471,     5,   444,     5,  1501,     5,
     444,  1501,  1501,  1501,  1501,  1005,   444,   481,  1427,     5,
    1005,  1463,     9,   346,   481,   493,  1433,  1434,  1435,  1436,
    1437,  1441,  1445,  1447,  1501,   421,  1421,  1431,  1005,  1493,
     668,  1448,   385,  1472,    26,  1472,   477,   511,  1279,  1299,
    1131,   511,  1241,  1273,   661,  1005,  1402,  1404,  1457,  1461,
    1462,  1406,  1461,  1406,     5,   444,  1344,  1406,  1433,  1005,
     444,  1347,     5,   444,   481,   481,   481,  1471,  1471,   481,
     481,   481,   481,   481,   258,   259,   260,   451,  1408,  1410,
       5,   444,     5,   444,  1005,  1005,    25,  1005,  1005,    25,
    1005,   912,  1005,  1323,  1324,     5,  1325,  1326,   928,  1120,
     669,  1325,   626,  1509,  1509,   912,   912,   993,   559,   912,
    1576,     5,  1045,    20,  1461,  1509,   796,   804,   803,   805,
    1005,  1009,   806,  1009,   243,   799,   802,     5,  1048,   669,
     912,     8,  1567,   509,   669,     5,  1509,   626,  1005,  1180,
     928,   603,  1367,     5,   444,  1162,     5,    26,  1162,   379,
      25,  1301,   398,   398,   509,   669,   398,   481,   754,   758,
     751,  1584,  1584,   783,   779,   775,  1081,    25,  1004,  1141,
    1162,  1584,   912,   476,   509,   928,     5,  1035,  1030,  1031,
      26,   738,  1005,  1584,  1584,  1584,  1584,  1584,  1584,     5,
    1051,     5,  1052,  1584,  1584,  1584,  1584,  1084,  1584,  1004,
      25,    14,    14,     5,   444,    26,  1457,  1497,  1478,   645,
     645,  1353,  1483,  1484,  1419,  1397,  1461,   666,   999,   481,
    1357,  1005,  1519,  1518,  1392,  1461,   513,  1393,  1394,  1459,
    1457,  1390,  1498,    97,    98,    99,   100,   101,   633,  1541,
     912,   912,   603,  1365,   999,  1393,  1457,     5,  1162,   981,
    1584,  1584,     5,   988,   989,  1584,  1584,   987,  1107,   875,
     444,   943,    26,   943,    24,    26,   943,   943,   481,  1429,
    1471,   675,  1471,  1471,   444,  1501,   444,   444,   444,   444,
    1426,  1428,  1426,  1436,  1496,  1433,  1501,  1496,     6,     7,
       9,    10,    12,    13,    14,    15,    16,    17,   304,   424,
     425,   479,   606,   672,   722,   723,  1444,  1446,  1422,  1500,
    1501,   498,  1420,  1432,   320,  1322,    26,  1373,  1374,  1375,
    1461,  1490,  1493,   444,   829,   125,   126,   128,   129,   130,
     228,   236,   270,   279,   308,   309,   353,   397,   451,   677,
     678,   679,   680,   681,   682,   683,   684,   685,   686,  1276,
    1280,   189,   564,  1281,  1297,  1107,   212,   227,   228,   236,
     270,   279,   308,   353,   397,  1274,  1275,  1287,  1281,  1462,
     509,  1460,   444,     5,   669,     5,   444,   444,  1407,   444,
     444,  1339,    26,  1454,  1454,    26,   675,   481,   675,    26,
    1455,    26,    26,  1455,  1455,    25,  1464,   210,   310,   348,
     412,   426,   526,   542,  1401,  1411,  1412,  1413,  1414,  1336,
    1332,   669,   669,   588,   637,     5,   444,   734,     5,   444,
     910,   444,    20,   444,  1509,     5,   912,   616,   326,   743,
     744,   912,  1048,  1584,  1584,     5,   800,   509,   669,     5,
     801,  1584,   797,   596,    20,  1005,     5,  1005,  1197,  1566,
      20,  1461,  1556,     8,  1509,   442,   708,   910,  1368,   962,
    1086,   717,  1220,   905,     5,   765,  1162,   750,   732,  1005,
    1162,   756,   444,   765,   765,  1584,  1584,  1084,  1138,    25,
    1142,  1162,   621,   958,  1172,   533,   911,  1092,  1232,   114,
     592,  1036,  1022,  1023,   669,   996,  1584,   996,  1584,   738,
      26,  1162,    26,  1162,   742,   444,   481,  1510,  1498,  1484,
    1484,  1476,     5,   444,   521,  1495,  1358,  1461,   529,  1355,
    1495,   675,     5,   444,     5,   596,  1488,    18,    19,   116,
     478,   481,   494,   533,   534,   546,   587,   626,   638,   650,
     651,   658,   661,  1005,  1464,  1496,  1525,  1527,  1546,  1547,
    1548,  1549,  1550,  1551,  1563,  1546,  1546,  1546,  1461,  1543,
    1545,  1542,  1543,  1544,  1539,  1366,   675,  1162,  1005,  1584,
    1584,  1584,  1584,   673,   444,   639,   444,   444,    26,   444,
     675,  1472,   675,   675,     5,   444,   444,  1434,  1435,  1439,
    1502,  1439,   481,  1496,  1439,   481,  1496,  1439,    10,   301,
     439,   441,  1501,     5,  1433,     5,   588,   637,  1376,  1322,
     675,   673,  1277,  1277,  1277,    25,  1277,  1277,  1277,  1277,
    1277,  1277,    25,    25,  1277,  1280,  1162,  1188,  1189,   668,
     497,  1242,  1584,    25,    25,    26,    26,    26,    26,    26,
      25,  1162,  1275,  1242,    26,  1401,  1461,    20,  1005,  1461,
    1344,   444,   444,     5,   444,  1472,    26,  1472,     5,  1452,
       5,   444,   444,   444,  1452,  1403,  1457,   481,  1413,  1344,
    1005,  1005,  1324,   672,   726,  1318,  1319,  1320,  1326,    60,
     137,   138,   296,   672,  1314,  1315,  1316,   518,   890,  1314,
       5,   427,  1509,     5,   481,   444,   600,  1075,  1009,  1584,
     735,    20,  1005,  1009,  1584,   953,   912,   477,  1509,     8,
     953,  1183,  1584,    26,  1004,    25,  1302,  1180,   477,   765,
     755,   759,   444,  1584,  1004,   912,   956,   477,  1038,  1037,
     491,  1024,  1025,    20,  1005,  1511,  1512,   603,  1494,  1479,
    1477,  1461,  1497,   194,  1398,     5,   444,  1356,  1519,  1461,
    1394,  1393,  1494,  1549,  1549,  1548,   481,   481,   481,   481,
     481,   481,   481,  1005,   481,     5,   444,    18,    19,    20,
      21,  1523,   444,     5,   444,     5,    14,   202,   576,  1540,
    1183,  1393,   263,  1115,   871,   943,    24,    26,   943,   943,
     444,  1472,  1472,  1472,  1426,   492,  1438,  1438,  1442,  1443,
    1464,  1563,  1438,  1442,  1438,  1439,  1501,  1500,  1374,  1472,
     841,   588,   637,  1190,     5,  1188,   113,   188,   250,   252,
     268,   276,   280,   305,  1243,  1244,  1298,  1115,  1288,     5,
     477,  1460,    26,   444,    26,  1456,   444,    26,   444,   481,
    1433,  1317,  1583,    26,  1320,    26,    26,  1317,  1322,  1316,
     996,   738,   427,  1509,   912,   745,   618,  1195,    26,   738,
     477,  1075,   444,  1509,   292,   738,   444,   444,   481,   757,
     398,   763,   444,   752,  1137,  1584,   509,   912,  1584,  1004,
       5,   444,  1183,  1429,  1498,  1461,   481,  1429,   444,  1524,
    1448,  1548,  1552,  1448,  1448,  1448,  1448,   509,   669,  1552,
    1547,  1548,  1548,  1548,  1548,  1543,    14,  1544,  1547,   999,
    1433,   195,   666,  1387,   444,   444,  1440,  1464,  1505,     5,
     444,   444,  1438,     7,  1189,  1245,  1246,  1162,  1248,  1162,
    1247,  1249,  1244,   291,   291,    26,   444,   675,   444,  1404,
     444,   889,  1509,   445,   254,   311,   336,   345,   383,   391,
     482,   652,   742,   746,   747,   481,   669,   738,  1219,  1303,
     760,   444,  1180,   763,   763,  1584,   957,  1172,   625,  1072,
    1512,  1492,  1429,   533,  1359,  1360,  1501,  1492,   444,  1548,
       5,   444,  1548,  1548,  1548,  1548,    26,  1005,   444,   481,
    1005,   943,   943,  1443,  1501,  1584,  1584,  1250,  1584,  1251,
    1584,  1584,   477,  1472,   444,   290,   401,   405,   892,   893,
     894,  1078,   991,   991,   991,   991,   991,   991,    25,     5,
     444,   912,    20,  1005,  1078,  1223,  1224,  1225,   763,   765,
     763,   293,   477,  1039,   738,     5,   444,   339,   340,  1480,
     444,  1548,   444,   444,   444,   444,     5,   477,   509,  1546,
    1584,  1584,   896,   895,   290,   894,   897,   747,     5,  1226,
     334,  1225,   761,  1584,  1360,    25,  1005,  1481,  1482,    26,
      26,   444,  1584,  1584,  1584,   912,  1584,   444,  1036,   669,
     669,     5,   477,     5,   477,   444,   762,  1005,  1005,  1482,
      26,   215,   398,   764,   669,   477,  1180,  1005
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
#line 999 "fgl.yacc"
    { print_screen_mode(0);}
    break;

  case 3:
#line 1002 "fgl.yacc"
    { print_screen_mode(1);}
    break;

  case 4:
#line 1006 "fgl.yacc"
    {
		print_start_server(yyvsp[-3].str,yyvsp[0].str);
	}
    break;

  case 5:
#line 1012 "fgl.yacc"
    {
	print_stop_external();
	}
    break;

  case 6:
#line 1017 "fgl.yacc"
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
#line 1029 "fgl.yacc"
    {
	sprintf(yyval.str,"%s%s",yyvsp[-2].str,yyvsp[0].str);
	}
    break;

  case 10:
#line 1034 "fgl.yacc"
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
#line 1057 "fgl.yacc"
    {sprintf(yyval.str,"(%s)",yyvsp[-1].str);}
    break;

  case 12:
#line 1058 "fgl.yacc"
    { sprintf(yyval.str,"%s%s%s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 13:
#line 1059 "fgl.yacc"
    {sprintf(yyval.str,"%d",atoi(yyvsp[0].str));}
    break;

  case 14:
#line 1060 "fgl.yacc"
    {sprintf(yyval.str,"(%s%s)",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 15:
#line 1061 "fgl.yacc"
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
#line 1072 "fgl.yacc"
    {
	sprintf(yyval.str,print_arr_expr_fcall(yyvsp[0].ptr));
}
    break;

  case 17:
#line 1078 "fgl.yacc"
    {strcpy(yyval.str,"+");}
    break;

  case 18:
#line 1079 "fgl.yacc"
    {strcpy(yyval.str,"-");}
    break;

  case 19:
#line 1080 "fgl.yacc"
    {strcpy(yyval.str,"*");}
    break;

  case 20:
#line 1081 "fgl.yacc"
    {strcpy(yyval.str,"/");}
    break;

  case 21:
#line 1082 "fgl.yacc"
    {strcpy(yyval.str,"%");}
    break;

  case 22:
#line 1087 "fgl.yacc"
    {strcpy(yyval.str,"+");}
    break;

  case 23:
#line 1088 "fgl.yacc"
    {strcpy(yyval.str,"-");}
    break;

  case 24:
#line 1099 "fgl.yacc"
    {
	 A4GL_debug("Using default attribute of WHITE");
		sprintf(yyval.str,"%d",0);}
    break;

  case 25:
#line 1102 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 26:
#line 1105 "fgl.yacc"
    {start_state("attribute",1);}
    break;

  case 27:
#line 1105 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[-1].str);
A4GL_debug("Got Attributes : %s",yyvsp[-1].str);
start_state("attribute",0);
}
    break;

  case 29:
#line 1112 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 30:
#line 1113 "fgl.yacc"
    {
sprintf(yyval.str,"%d",atoi(yyvsp[-2].str)|atoi(yyvsp[0].str));
}
    break;

  case 31:
#line 1119 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("BLACK"));}
    break;

  case 32:
#line 1120 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("BLUE"));}
    break;

  case 33:
#line 1121 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("CYAN"));}
    break;

  case 34:
#line 1122 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("GREEN"));}
    break;

  case 35:
#line 1123 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("MAGENTA"));}
    break;

  case 36:
#line 1124 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("RED"));}
    break;

  case 37:
#line 1125 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("WHITE"));}
    break;

  case 38:
#line 1126 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("YELLOW"));}
    break;

  case 39:
#line 1127 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("REVERSE"));}
    break;

  case 40:
#line 1128 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("BLINK"));}
    break;

  case 41:
#line 1129 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("UNDERLINE"));}
    break;

  case 42:
#line 1130 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("BOLD"));}
    break;

  case 43:
#line 1131 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("NORMAL"));}
    break;

  case 44:
#line 1132 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("INVISIBLE"));}
    break;

  case 45:
#line 1133 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("DIM"));}
    break;

  case 46:
#line 1134 "fgl.yacc"
    {inp_flags=inp_flags | 0x1; strcpy(yyval.str,"0");}
    break;

  case 47:
#line 1135 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 50:
#line 1142 "fgl.yacc"
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
#line 1153 "fgl.yacc"
    {start_state("attribute",0);strcpy(yyval.str,"");
}
    break;

  case 52:
#line 1157 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 53:
#line 1158 "fgl.yacc"
    {sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 54:
#line 1162 "fgl.yacc"
    { 
/*printf("Window attribute = %s\n",$<str>1);*/
form_attrib.attrib      =form_attrib.attrib|atoi(yyvsp[0].str);
/*printf("Window attribute = %d\n",form_attrib.attrib);*/
}
    break;

  case 55:
#line 1168 "fgl.yacc"
    { form_attrib.border      =1;}
    break;

  case 56:
#line 1170 "fgl.yacc"
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
#line 1181 "fgl.yacc"
    { form_attrib.comment_line=atoi(yyvsp[0].str); }
    break;

  case 58:
#line 1183 "fgl.yacc"
    { form_attrib.form_line   =atoi(yyvsp[0].str); }
    break;

  case 59:
#line 1185 "fgl.yacc"
    { form_attrib.error_line  =atoi(yyvsp[0].str); }
    break;

  case 60:
#line 1187 "fgl.yacc"
    { form_attrib.menu_line   =atoi(yyvsp[0].str); 
A4GL_debug("Set menu line to %s",yyvsp[0].str);
}
    break;

  case 61:
#line 1191 "fgl.yacc"
    { form_attrib.message_line=atoi(yyvsp[0].str); }
    break;

  case 62:
#line 1193 "fgl.yacc"
    { form_attrib.prompt_line =atoi(yyvsp[0].str); }
    break;

  case 63:
#line 1254 "fgl.yacc"
    {strcpy(yyval.str,"CALL");}
    break;

  case 64:
#line 1258 "fgl.yacc"
    { A4GL_debug("print_expr (3)"); 
		print_expr(yyvsp[-2].ptr);
		print_pop_variable(yyvsp[0].str);
	}
    break;

  case 65:
#line 1262 "fgl.yacc"
    {
        if (!isin_command("INPUT")&&!isin_command("CONSTRUCT")) {
                a4gl_yyerror("get_fldbuf can only be used in an input or construct");
                YYERROR;
        }
	print_getfldbuf(field_name_list_as_char(yyvsp[-2].field_list));
	}
    break;

  case 66:
#line 1269 "fgl.yacc"
    {
		print_returning();
	}
    break;

  case 67:
#line 1272 "fgl.yacc"
    {
	print_form_is_compiled(yyvsp[-5].str,yyvsp[-3].str,yyvsp[-1].str);
	}
    break;

  case 68:
#line 1276 "fgl.yacc"
    {
		print_field_func('I',field_name_as_char(yyvsp[-3].field_entry),yyvsp[0].str);
   }
    break;

  case 70:
#line 1280 "fgl.yacc"
    { 
        if (!isin_command("INPUT")&&!isin_command("CONSTRUCT")) {
                a4gl_yyerror("get_fldbuf can only be used in an input or construct");
                YYERROR;
        }
	print_field_func('T',field_name_list_as_char(yyvsp[-3].field_list),yyvsp[0].str);
   }
    break;

  case 71:
#line 1287 "fgl.yacc"
    {
	new_counter();
   	addmap("Call",yyvsp[-3].str,curr_func,yylineno,infilename);
   }
    break;

  case 72:
#line 1293 "fgl.yacc"
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
#line 1302 "fgl.yacc"
    {
	print_returning();
	/* strcpy($<str>$,$<str>5); */
   }
    break;

  case 74:
#line 1306 "fgl.yacc"
    {
	new_counter();
   	addmap("Call",yyvsp[-1].str,curr_func,yylineno,infilename);
   }
    break;

  case 75:
#line 1311 "fgl.yacc"
    {
 A4GL_debug("Got args");
   }
    break;

  case 76:
#line 1315 "fgl.yacc"
    {
	int a;
	dump_expr(yyvsp[-2].ptr);
	a=get_counter_val();
	drop_counter();
  	print_func_call(yyvsp[-5].str,yyvsp[-2].ptr,a);
   }
    break;

  case 77:
#line 1323 "fgl.yacc"
    {
	print_returning();
	/* strcpy($<str>$,$<str>5);  */
   }
    break;

  case 78:
#line 1327 "fgl.yacc"
    {
	A4GLSQL_set_status(0,0);
	new_counter();
	}
    break;

  case 79:
#line 1331 "fgl.yacc"
    {
   sprintf(yyval.str,"%d",get_counter_val());drop_counter();
}
    break;

  case 80:
#line 1333 "fgl.yacc"
    {
        print_expr ((struct expr_str *)yyvsp[-3].ptr);  
	print_call_shared(yyvsp[-6].str,yyvsp[-8].str,atoi(yyvsp[-2].str));
	print_returning();
	print_end_call_shared();
}
    break;

  case 81:
#line 1339 "fgl.yacc"
    {
	sprintf(yyval.str,"\"%s\",\"%s\"",yyvsp[-3].str,yyvsp[-1].str);
	A4GLSQL_set_status(0,0);
	new_counter();
	}
    break;

  case 82:
#line 1344 "fgl.yacc"
    {
   	sprintf(yyval.str,"%d",get_counter_val());drop_counter();
}
    break;

  case 83:
#line 1347 "fgl.yacc"
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
#line 1363 "fgl.yacc"
    {
   char buff[256];
   new_counter();
   sprintf(buff,"%s:%s(%p)",yyvsp[-6].str,yyvsp[-4].str,yyvsp[-2].str);
   addmap("External",buff,curr_func,yylineno,infilename);
   }
    break;

  case 85:
#line 1370 "fgl.yacc"
    {
   sprintf(yyval.str,"%d",get_counter_val());drop_counter();
   }
    break;

  case 86:
#line 1374 "fgl.yacc"
    {
	 A4GL_debug("print_expr (6)");print_expr(yyvsp[-2].ptr);
   }
    break;

  case 87:
#line 1378 "fgl.yacc"
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
#line 1400 "fgl.yacc"
    {start_bind('i',0);strcpy(yyval.str,"0");}
    break;

  case 89:
#line 1400 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);
}
    break;

  case 90:
#line 1404 "fgl.yacc"
    {start_bind('i',0);strcpy(yyval.str,"0");}
    break;

  case 91:
#line 1405 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 92:
#line 1406 "fgl.yacc"
    {strcpy(yyval.str,"WITHOUT WAITING"); }
    break;

  case 93:
#line 1411 "fgl.yacc"
    {
			yyval.ptr=A4GL_new_expr("");
		}
    break;

  case 94:
#line 1414 "fgl.yacc"
    {
			yyval.ptr=yyvsp[0].ptr;
		}
    break;

  case 95:
#line 1420 "fgl.yacc"
    {
	yyval.ptr=yyvsp[0].ptr;
}
    break;

  case 96:
#line 1423 "fgl.yacc"
    {
		yyval.ptr=A4GL_append_expr_expr(yyvsp[-2].ptr,yyvsp[0].ptr);
}
    break;

  case 98:
#line 1432 "fgl.yacc"
    {yyval.ptr=A4GL_new_expr("A4GL_push_null(2,0);");}
    break;

  case 100:
#line 1436 "fgl.yacc"
    {
sprintf(yyval.str,"\"%s\"",yyvsp[0].str);
}
    break;

  case 101:
#line 1442 "fgl.yacc"
    {
sprintf(yyval.str,"\"%s\"",yyvsp[0].str);
}
    break;

  case 102:
#line 1445 "fgl.yacc"
    { sprintf(yyval.str,"\"%s.%s\"",yyvsp[-2].str,yyvsp[0].str); }
    break;

  case 103:
#line 1460 "fgl.yacc"
    {
push_blockcommand("CASE");
setinc(1);
A4GL_incprint();
print_case(1);
setinc(1);
}
    break;

  case 104:
#line 1470 "fgl.yacc"
    {
print_after_when(0);
pop_blockcommand("CASE");
}
    break;

  case 105:
#line 1476 "fgl.yacc"
    {  push_blockcommand("CASE"); 
setinc(1);
A4GL_incprint(); 
print_case(0);
setinc(1);
}
    break;

  case 106:
#line 1485 "fgl.yacc"
    {
print_after_when(0);
pop_blockcommand("CASE");
}
    break;

  case 111:
#line 1498 "fgl.yacc"
    {setinc(-1);A4GL_incprint();}
    break;

  case 113:
#line 1501 "fgl.yacc"
    {
A4GL_incprint();
}
    break;

  case 114:
#line 1503 "fgl.yacc"
    {A4GL_incprint();
print_after_when(0);
}
    break;

  case 116:
#line 1509 "fgl.yacc"
    {A4GL_incprint();}
    break;

  case 117:
#line 1511 "fgl.yacc"
    {A4GL_incprint();
print_after_when(0);
}
    break;

  case 118:
#line 1516 "fgl.yacc"
    {
print_when(0);

A4GL_incprint();
}
    break;

  case 119:
#line 1521 "fgl.yacc"
    {A4GL_incprint();
print_after_when(1);
setinc(-1);}
    break;

  case 120:
#line 1527 "fgl.yacc"
    {
A4GL_incprint();
print_when(1);
}
    break;

  case 121:
#line 1531 "fgl.yacc"
    {A4GL_incprint();
print_after_when(1);
setinc(-1);}
    break;

  case 122:
#line 1546 "fgl.yacc"
    {
  print_close('F',yyvsp[0].str);
 }
    break;

  case 123:
#line 1549 "fgl.yacc"
    {
  print_close('W',yyvsp[0].str);
}
    break;

  case 124:
#line 1552 "fgl.yacc"
    {
  print_close('W',yyvsp[0].str);
}
    break;

  case 125:
#line 1555 "fgl.yacc"
    {
  print_close('D',0);
}
    break;

  case 126:
#line 1558 "fgl.yacc"
    {
  print_close('S',yyvsp[0].str);
}
    break;

  case 127:
#line 1561 "fgl.yacc"
    {
  print_close('C',yyvsp[0].str);
}
    break;

  case 133:
#line 1583 "fgl.yacc"
    {
			A4GL_lex_printc("%s",yyvsp[0].str);
}
    break;

  case 136:
#line 1592 "fgl.yacc"
    {
			A4GL_lex_printc("%s\n",yyvsp[0].str);
}
    break;

  case 137:
#line 1611 "fgl.yacc"
    {
push_blockcommand("CONSTRUCT");
A4GL_new_events();
}
    break;

  case 138:
#line 1616 "fgl.yacc"
    {
	print_construct_1();
}
    break;

  case 139:
#line 1619 "fgl.yacc"
    {
	print_construct_2(yyvsp[-2].str);
A4GL_drop_events();
}
    break;

  case 140:
#line 1628 "fgl.yacc"
    {
	print_construct_3(1,yyvsp[-5].str,0,yyvsp[0].str,atoi(yyvsp[0].str));
	strcpy(yyval.str,A4GL_get_formloop_str(0));
	reset_constr();
}
    break;

  case 141:
#line 1634 "fgl.yacc"
    {
	print_construct_3(0,yyvsp[-7].str,field_name_list_as_char(yyvsp[-2].field_list),yyvsp[0].str,atoi(yyvsp[0].str));
	strcpy(yyval.str,A4GL_get_formloop_str(0));
	reset_constr();
}
    break;

  case 146:
#line 1649 "fgl.yacc"
    {
                push_construct("",yyval.str);
             }
    break;

  case 147:
#line 1653 "fgl.yacc"
    {
                sprintf(yyval.str,"%s.%s",yyvsp[-2].str,yyvsp[0].str);
                push_construct(yyvsp[-2].str,yyvsp[0].str); 
             }
    break;

  case 148:
#line 1658 "fgl.yacc"
    {
                push_construct(yyvsp[-2].str,"*");
             }
    break;

  case 151:
#line 1668 "fgl.yacc"
    { A4GL_add_event(-97,field_name_list_as_or_char(yyvsp[0].field_list)); print_befaft_field_1(field_name_list_as_or_char(yyvsp[0].field_list)); }
    break;

  case 152:
#line 1668 "fgl.yacc"
    { print_befaft_field_2(); }
    break;

  case 153:
#line 1669 "fgl.yacc"
    { A4GL_add_event(-98,field_name_list_as_or_char(yyvsp[0].field_list)); print_befaft_field_1(field_name_list_as_or_char(yyvsp[0].field_list)); }
    break;

  case 154:
#line 1669 "fgl.yacc"
    { print_befaft_field_2(); }
    break;

  case 155:
#line 1670 "fgl.yacc"
    { A4GL_add_onkey_key(yyvsp[0].str); print_onkey_1(yyvsp[0].str); }
    break;

  case 156:
#line 1670 "fgl.yacc"
    { print_onkey_2(); }
    break;

  case 157:
#line 1671 "fgl.yacc"
    { A4GL_add_event(-95,""); print_befaft_field_1("AFTER_INP"); }
    break;

  case 158:
#line 1671 "fgl.yacc"
    { print_befaft_field_2(); }
    break;

  case 159:
#line 1672 "fgl.yacc"
    { A4GL_add_event(-99,""); print_befaft_field_1("BEFORE_INP"); }
    break;

  case 160:
#line 1672 "fgl.yacc"
    { print_befaft_field_2(); }
    break;

  case 161:
#line 1680 "fgl.yacc"
    {
			yyval.field_list=new_field_list();
			yyval.field_list=append_field_to_list(yyval.field_list,yyvsp[0].field_entry);
	}
    break;

  case 162:
#line 1684 "fgl.yacc"
    {
			yyval.field_list=append_field_to_list(yyvsp[-2].field_list,yyvsp[0].field_entry);
	}
    break;

  case 163:
#line 1690 "fgl.yacc"
    {
			yyval.field_list=new_field_list();
			yyval.field_list=append_field_to_list(yyval.field_list,yyvsp[0].field_entry);
	}
    break;

  case 164:
#line 1694 "fgl.yacc"
    {
			yyval.field_list=append_field_to_list(yyvsp[-2].field_list,yyvsp[0].field_entry);
	}
    break;

  case 165:
#line 1709 "fgl.yacc"
    {
        	yyval.ptr=A4GL_new_expr("A4GL_pushop(OP_YEAR);");
	}
    break;

  case 166:
#line 1712 "fgl.yacc"
    {
        	yyval.ptr=A4GL_new_expr("A4GL_pushop(OP_MONTH);");
	}
    break;

  case 167:
#line 1715 "fgl.yacc"
    {
        	yyval.ptr=A4GL_new_expr("A4GL_pushop(OP_DAY);");
	}
    break;

  case 168:
#line 1718 "fgl.yacc"
    {
        	yyval.ptr=A4GL_new_expr("A4GL_pushop(OP_HOUR);");
	}
    break;

  case 169:
#line 1721 "fgl.yacc"
    {
        	yyval.ptr=A4GL_new_expr("A4GL_pushop(OP_MINUTE);");
	}
    break;

  case 170:
#line 1724 "fgl.yacc"
    {
        	yyval.ptr=A4GL_new_expr("A4GL_pushop(OP_SECOND);");
	}
    break;

  case 171:
#line 1733 "fgl.yacc"
    {
			yyval.ptr=A4GL_append_expr_expr(yyvsp[-2].ptr,yyvsp[-1].ptr);
		}
    break;

  case 172:
#line 1741 "fgl.yacc"
    { 
	char buff[50];
	sprintf(buff,"A4GL_push_int(%d);",(19*16)+10); 
	yyval.ptr=A4GL_new_expr(buff);
}
    break;

  case 173:
#line 1746 "fgl.yacc"
    { 
	char buff[50];
	sprintf(buff,"A4GL_push_int(%d);",(atoi(yyvsp[-2].str)*16) +atoi(yyvsp[0].str)  ); 
	yyval.ptr=A4GL_new_expr(buff);
}
    break;

  case 174:
#line 1759 "fgl.yacc"
    {
				print_defer(0);
			}
    break;

  case 175:
#line 1763 "fgl.yacc"
    {
				print_defer(1);
			}
    break;

  case 176:
#line 1778 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 177:
#line 1779 "fgl.yacc"
    {strcpy(yyval.str,"");lastlineno=yylineno;}
    break;

  case 180:
#line 1787 "fgl.yacc"
    {dtypelist[0]=0;A4GL_lex_printcomment("/* define */\n");}
    break;

  case 181:
#line 1787 "fgl.yacc"
    {A4GL_lex_printcomment("/*end def */\n");}
    break;

  case 186:
#line 1796 "fgl.yacc"
    {in_define=1;}
    break;

  case 187:
#line 1796 "fgl.yacc"
    {in_define=0;strcpy(yyval.str,yyvsp[0].str);
                        set_yytext(yyval.str);
                        if (A4GL_bad_identifiers(yyval.str)) {
                                a4gl_yyerror("You can't use this identifier as it is a reserved word in the target language");
                        }
}
    break;

  case 188:
#line 1805 "fgl.yacc"
    { add_constant('c',yyvsp[0].str,yyvsp[-2].str); addmap("Constant",yyvsp[-2].str,curr_func,yylineno,infilename); }
    break;

  case 189:
#line 1806 "fgl.yacc"
    { add_constant('C',yyvsp[0].str,yyvsp[-2].str); addmap("Constant",yyvsp[-2].str,curr_func,yylineno,infilename); }
    break;

  case 190:
#line 1807 "fgl.yacc"
    { add_constant('f',yyvsp[0].str,yyvsp[-2].str);
addmap("Constant",yyvsp[-2].str,curr_func,yylineno,infilename);
 }
    break;

  case 191:
#line 1810 "fgl.yacc"
    { 
add_constant('i',yyvsp[0].str,yyvsp[-2].str);
addmap("Constant",yyvsp[-2].str,curr_func,yylineno,infilename);
 }
    break;

  case 193:
#line 1815 "fgl.yacc"
    { }
    break;

  case 194:
#line 1815 "fgl.yacc"
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

  case 198:
#line 1832 "fgl.yacc"
    {
		sprintf(yyval.str,"-%p",yyvsp[0].str);}
    break;

  case 199:
#line 1836 "fgl.yacc"
    {
/*AF CygWin FIX */
push_name(yyval.str,0);
addmap("Define",yyvsp[0].str,curr_func,yylineno,infilename);
}
    break;

  case 204:
#line 1851 "fgl.yacc"
    {strcpy(yyval.str,"-1");}
    break;

  case 205:
#line 1852 "fgl.yacc"
    {strcpy(yyval.str,"-1");}
    break;

  case 206:
#line 1853 "fgl.yacc"
    {strcpy(yyval.str,"-2");}
    break;

  case 207:
#line 1854 "fgl.yacc"
    {strcpy(yyval.str,"-3");}
    break;

  case 208:
#line 1859 "fgl.yacc"
    {
 A4GL_debug("defines array %s",yyvsp[-1].str);
	push_type(0,0,yyvsp[-1].str);
}
    break;

  case 210:
#line 1865 "fgl.yacc"
    {
 A4GL_debug("defines array %s",yyvsp[0].str);
	push_type(0,0,yyvsp[0].str);
}
    break;

  case 212:
#line 1874 "fgl.yacc"
    {
	push_associate(yyvsp[-5].str,yyvsp[-1].str);
	push_type(0,0,yyvsp[-1].str);
}
    break;

  case 213:
#line 1878 "fgl.yacc"
    {
    /* void pop_associate (char *a); */
	pop_associate(0);

}
    break;

  case 219:
#line 1894 "fgl.yacc"
    {sprintf(yyval.str,"%s][%s][%s",yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str); A4GL_debug("Triplet");}
    break;

  case 220:
#line 1896 "fgl.yacc"
    {sprintf(yyval.str,"%s][%s",yyvsp[-2].str,yyvsp[0].str); A4GL_debug("double");}
    break;

  case 221:
#line 1897 "fgl.yacc"
    {A4GL_debug("Single");}
    break;

  case 223:
#line 1904 "fgl.yacc"
    {push_record();in_record++;}
    break;

  case 224:
#line 1904 "fgl.yacc"
    {pop_record();in_record--;}
    break;

  case 225:
#line 1905 "fgl.yacc"
    {in_record++;push_record();A4GL_debug("Like\n");}
    break;

  case 226:
#line 1906 "fgl.yacc"
    {A4GL_debug("Link Table : %s\n",yyvsp[-2].str);
                  push_rectab(yyvsp[-2].str);
                  pop_record();in_record--;}
    break;

  case 227:
#line 1909 "fgl.yacc"
    {
		push_record();A4GL_debug("Like\n");}
    break;

  case 228:
#line 1911 "fgl.yacc"
    {
		  A4GL_debug("Table:%s\n",yyvsp[-4].str);
		  add_link_to(yyvsp[-4].str,yyvsp[-1].str);
	          A4GL_debug("Push record...\n");
                  push_rectab(yyvsp[-4].str);
                  pop_record();
}
    break;

  case 230:
#line 1921 "fgl.yacc"
    {
	sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 235:
#line 1936 "fgl.yacc"
    {start_state("dtype",1);}
    break;

  case 236:
#line 1936 "fgl.yacc"
    {start_state("dtype",0);}
    break;

  case 240:
#line 1942 "fgl.yacc"
    {push_type("char","1",0);}
    break;

  case 241:
#line 1943 "fgl.yacc"
    {push_type("char","1",0);}
    break;

  case 242:
#line 1944 "fgl.yacc"
    { if (atoi(yyvsp[-1].str)==4) { addmap("size=4","----",curr_func,yylineno,infilename); } push_type("char",yyvsp[-1].str,0); }
    break;

  case 243:
#line 1945 "fgl.yacc"
    { if (atoi(yyvsp[-1].str)==4) { addmap("size=4","----",curr_func,yylineno,infilename); } push_type("char",yyvsp[-1].str,0); }
    break;

  case 244:
#line 1946 "fgl.yacc"
    {push_type("varchar",yyvsp[-1].str,0);}
    break;

  case 245:
#line 1947 "fgl.yacc"
    {push_type("varchar",yyvsp[-3].str,0);}
    break;

  case 246:
#line 1948 "fgl.yacc"
    {push_type("char",yyvsp[-1].str,0);}
    break;

  case 247:
#line 1949 "fgl.yacc"
    {push_type("char",yyvsp[-3].str,0);}
    break;

  case 248:
#line 1950 "fgl.yacc"
    {push_type("long",0,0);}
    break;

  case 249:
#line 1951 "fgl.yacc"
    {
A4GL_debug("Using specified type...");
push_dim(yyvsp[0].str);}
    break;

  case 250:
#line 1954 "fgl.yacc"
    {push_type("int",0,0);}
    break;

  case 251:
#line 1955 "fgl.yacc"
    {push_type("form",0,0);}
    break;

  case 252:
#line 1956 "fgl.yacc"
    {push_type("form",0,0);}
    break;

  case 253:
#line 1957 "fgl.yacc"
    { char buff[256];
				sprintf(buff,"%d",16*256+2);
				push_type("fgldecimal",buff,0);
				}
    break;

  case 254:
#line 1961 "fgl.yacc"
    {
				char buff[256];
				sprintf(buff,"%d",atoi(yyvsp[-1].str)*256+2);
				push_type("fgldecimal",buff,0);
}
    break;

  case 255:
#line 1966 "fgl.yacc"
    {
char buff[256];
sprintf(buff,"%d",atoi(yyvsp[-3].str)*256+atoi(yyvsp[-1].str));
push_type("fgldecimal",buff,0);
}
    break;

  case 256:
#line 1971 "fgl.yacc"
    {
			char buff[256];
			sprintf(buff,"%d",16*256+2);
			push_type("fglmoney",buff,0);}
    break;

  case 257:
#line 1975 "fgl.yacc"
    {
		char buff[256];sprintf(buff,"%d",atoi(yyvsp[-1].str)*256+2);
			push_type("fglmoney",buff,0);}
    break;

  case 258:
#line 1978 "fgl.yacc"
    {
char buff[256];
sprintf(buff,"%d",atoi(yyvsp[-3].str)*256+atoi(yyvsp[-1].str));
push_type("fglmoney",buff,0);}
    break;

  case 259:
#line 1982 "fgl.yacc"
    {push_type("double",0,0);}
    break;

  case 261:
#line 1983 "fgl.yacc"
    {push_type("double",0,0);}
    break;

  case 263:
#line 1984 "fgl.yacc"
    {push_type("float",0,0);}
    break;

  case 265:
#line 1985 "fgl.yacc"
    {push_type("fgldate",0,0);}
    break;

  case 266:
#line 1986 "fgl.yacc"
    {push_type("fglbyte",0,0);}
    break;

  case 267:
#line 1987 "fgl.yacc"
    {push_type("fglbyte",0,0);}
    break;

  case 268:
#line 1988 "fgl.yacc"
    {push_type("fgltext",0,0);}
    break;

  case 269:
#line 1989 "fgl.yacc"
    {push_type("fgltext",0,0);}
    break;

  case 270:
#line 1990 "fgl.yacc"
    {
push_type("struct_dtime",yyvsp[0].str,0);
}
    break;

  case 271:
#line 1993 "fgl.yacc"
    {push_type("struct_ival",yyvsp[0].str,0);}
    break;

  case 272:
#line 1994 "fgl.yacc"
    {push_like(yyvsp[0].str);A4GL_lex_printcomment("/*added(XXXXX)\n */");}
    break;

  case 273:
#line 1995 "fgl.yacc"
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

  case 276:
#line 2030 "fgl.yacc"
    {
A4GL_lex_printcomment("/*column like(ZZZ)\n*/"); sprintf(yyval.str,"%s.%s",yyvsp[-2].str,yyvsp[0].str); A4GL_lex_printcomment ("/*set col...(ZZZ)\n*/");}
    break;

  case 277:
#line 2034 "fgl.yacc"
    {A4GL_debug("--->%s\n",yyvsp[0].str);strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 278:
#line 2036 "fgl.yacc"
    {A4GL_debug("--->%s\n",yyvsp[0].str);strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 279:
#line 2038 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 280:
#line 2040 "fgl.yacc"
    {
A4GL_debug("Real datetime %s to %s\n",yyvsp[-2].str,yyvsp[0].str);
sprintf(yyval.str,"%d",(atoi(yyvsp[-2].str)*16)+atoi(yyvsp[0].str)); }
    break;

  case 281:
#line 2045 "fgl.yacc"
    {
	sprintf(yyval.str,"%d",(atoi(yyvsp[-2].str)*16)+atoi(yyvsp[0].str)); 
}
    break;

  case 282:
#line 2049 "fgl.yacc"
    {start_state("dtime_val",1);}
    break;

  case 283:
#line 2049 "fgl.yacc"
    {start_state("dtime_val",0); strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 284:
#line 2053 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 285:
#line 2054 "fgl.yacc"
    {strcpy(yyval.str,"2");}
    break;

  case 286:
#line 2055 "fgl.yacc"
    {strcpy(yyval.str,"3");}
    break;

  case 287:
#line 2056 "fgl.yacc"
    {strcpy(yyval.str,"4");}
    break;

  case 288:
#line 2057 "fgl.yacc"
    {strcpy(yyval.str,"5");}
    break;

  case 289:
#line 2058 "fgl.yacc"
    {strcpy(yyval.str,"6");}
    break;

  case 290:
#line 2060 "fgl.yacc"
    {
A4GL_debug("opt_frac returns %s",yyvsp[0].str);
sprintf(yyval.str,"%d",atoi(yyvsp[0].str)+6); }
    break;

  case 291:
#line 2065 "fgl.yacc"
    {start_state("dtime_val",1);}
    break;

  case 292:
#line 2065 "fgl.yacc"
    { A4GL_debug ("Got end");start_state("dtime_val",0);  strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 293:
#line 2068 "fgl.yacc"
    {
A4GL_debug("Nothing in fraction - assume 2");
strcpy(yyval.str,"2");}
    break;

  case 294:
#line 2070 "fgl.yacc"
    {
A4GL_debug("Read fraction .. ");
A4GL_debug("    %s",yyvsp[-1].str);
strcpy(yyval.str,yyvsp[-1].str);
}
    break;

  case 295:
#line 2076 "fgl.yacc"
    {
A4GL_debug("Nothing in fraction - assume 2");
strcpy(yyval.str,"2");}
    break;

  case 296:
#line 2078 "fgl.yacc"
    {
A4GL_debug("    %s",yyvsp[-1].str);
strcpy(yyval.str,yyvsp[-1].str);
}
    break;

  case 297:
#line 2084 "fgl.yacc"
    {
if (atoi(yyvsp[0].str)>5) {
a4gl_yyerror("Fraction values are between 0 and 5");
YYERROR;
}
}
    break;

  case 298:
#line 2092 "fgl.yacc"
    {start_state("interval_val",1);}
    break;

  case 299:
#line 2092 "fgl.yacc"
    {start_state("interval_val",0); sprintf(yyval.str,"%d",atoi(yyvsp[0].str)*16+atoi(yyvsp[-1].str));}
    break;

  case 300:
#line 2095 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 301:
#line 2096 "fgl.yacc"
    {strcpy(yyval.str,"2");}
    break;

  case 302:
#line 2097 "fgl.yacc"
    {strcpy(yyval.str,"3");}
    break;

  case 303:
#line 2098 "fgl.yacc"
    {strcpy(yyval.str,"4");}
    break;

  case 304:
#line 2099 "fgl.yacc"
    {strcpy(yyval.str,"5");}
    break;

  case 305:
#line 2100 "fgl.yacc"
    {strcpy(yyval.str,"6");}
    break;

  case 306:
#line 2102 "fgl.yacc"
    {
A4GL_debug("opt_frac returns %s",yyvsp[0].str);
sprintf(yyval.str,"%d",atoi(yyvsp[0].str)+6); }
    break;

  case 310:
#line 2123 "fgl.yacc"
    {
              	dim_set_name(yyvsp[0].str);
              }
    break;

  case 314:
#line 2132 "fgl.yacc"
    {dim_push_type("char","1",0);}
    break;

  case 315:
#line 2134 "fgl.yacc"
    {dim_push_type("char",yyvsp[-1].str,0);}
    break;

  case 316:
#line 2135 "fgl.yacc"
    {
						dim_push_type("varchar",yyvsp[-1].str,0);
				}
    break;

  case 317:
#line 2138 "fgl.yacc"
    {
						char buff[256];
						sprintf(buff,"%d",atoi(yyvsp[-3].str)*256+atoi(yyvsp[-1].str));
						dim_push_type("varchar",buff,0);}
    break;

  case 318:
#line 2142 "fgl.yacc"
    {dim_push_type("long",0,0);}
    break;

  case 319:
#line 2143 "fgl.yacc"
    {dim_push_type("integer",0,0);}
    break;

  case 320:
#line 2144 "fgl.yacc"
    {dim_push_type("FORM",0,0);}
    break;

  case 321:
#line 2145 "fgl.yacc"
    {
char buff[256];
sprintf(buff,"%d",16*256+2);
dim_push_type("fgldecimal",buff,0);
}
    break;

  case 322:
#line 2150 "fgl.yacc"
    {

char buff[256];
sprintf(buff,"%d",atoi(yyvsp[-1].str)*256+2);
dim_push_type("fgldecimal",buff,0);
}
    break;

  case 323:
#line 2157 "fgl.yacc"
    {
char buff[256];
sprintf(buff,"%d",atoi(yyvsp[-3].str)*256+atoi(yyvsp[-1].str));
dim_push_type("fgldecimal",buff,0);
}
    break;

  case 324:
#line 2162 "fgl.yacc"
    {dim_push_type("fglmoney",0,0);}
    break;

  case 325:
#line 2164 "fgl.yacc"
    {dim_push_type("fglmoney",0,0);}
    break;

  case 326:
#line 2166 "fgl.yacc"
    {dim_push_type("fglmoney",0,0);}
    break;

  case 327:
#line 2167 "fgl.yacc"
    {dim_push_type("double",0,0);}
    break;

  case 328:
#line 2168 "fgl.yacc"
    {dim_push_type("float",0,0);}
    break;

  case 329:
#line 2169 "fgl.yacc"
    {dim_push_type("fgldate",0,0);}
    break;

  case 330:
#line 2170 "fgl.yacc"
    {dim_push_type("fglbyte",0,0);}
    break;

  case 331:
#line 2171 "fgl.yacc"
    {dim_push_type("fgltext",0,0);}
    break;

  case 332:
#line 2172 "fgl.yacc"
    {
dim_push_type("struct_dtime",yyvsp[0].str,0);
}
    break;

  case 333:
#line 2175 "fgl.yacc"
    {dim_push_type("struct_ival",0,0);}
    break;

  case 334:
#line 2177 "fgl.yacc"
    {dim_push_like(yyvsp[0].str);A4GL_lex_printcomment("/*added(XXXXX)\n */");}
    break;

  case 335:
#line 2183 "fgl.yacc"
    {
A4GL_lex_printcomment("/*column like(ZZZ)\n*/");
sprintf(yyval.str,"%s.%s",yyvsp[-2].str,yyvsp[0].str)
; A4GL_lex_printcomment ("/*set col...(ZZZ)\n*/");}
    break;

  case 336:
#line 2191 "fgl.yacc"
    {
dim_push_type(0,0,yyvsp[-1].str);
}
    break;

  case 338:
#line 2199 "fgl.yacc"
    {
dim_push_associate(yyvsp[-5].str,yyvsp[-1].str);
dim_push_type(0,0,yyvsp[-1].str);
}
    break;

  case 339:
#line 2203 "fgl.yacc"
    {
	/* void dim_pop_associate (char *a); */
	dim_pop_associate(0);
}
    break;

  case 340:
#line 2211 "fgl.yacc"
    {dim_push_record();}
    break;

  case 341:
#line 2212 "fgl.yacc"
    {dim_pop_record();}
    break;

  case 342:
#line 2213 "fgl.yacc"
    {dim_push_record();A4GL_debug("Like\n");}
    break;

  case 343:
#line 2214 "fgl.yacc"
    {A4GL_debug("Table:%s\n",yyvsp[-2].str);
                                  dim_push_rectab(yyvsp[-2].str);
                                  dim_pop_record();}
    break;

  case 349:
#line 2233 "fgl.yacc"
    { dim_push_name(yyval.str,0); }
    break;

  case 350:
#line 2245 "fgl.yacc"
    {
	print_display_line();
		strcpy(yyval.str,A4GL_get_display_str(0,0,0));
	}
    break;

  case 351:
#line 2249 "fgl.yacc"
    {
		strcpy(yyval.str,A4GL_get_display_str(1,0,0)); /* FIXME */
	}
    break;

  case 352:
#line 2252 "fgl.yacc"
    { 
	strcpy(yyval.str,"#error not implemented yet");
	}
    break;

  case 353:
#line 2255 "fgl.yacc"
    { strcpy(yyval.str, A4GL_get_display_str(4,0,0)); }
    break;

  case 354:
#line 2256 "fgl.yacc"
    { strcpy(yyval.str, A4GL_get_display_str(2,field_name_list_as_char(yyvsp[0].field_list),0)); }
    break;

  case 355:
#line 2257 "fgl.yacc"
    { strcpy(yyval.str, A4GL_get_display_str(3,field_name_list_as_char(yyvsp[0].field_list),yyvsp[-2].str)); }
    break;

  case 356:
#line 2258 "fgl.yacc"
    { strcpy(yyval.str, A4GL_get_display_str(5,yyvsp[-1].str,0)); }
    break;

  case 357:
#line 2259 "fgl.yacc"
    { 
	strcpy(yyval.str,"#error not implemented yet");
 }
    break;

  case 358:
#line 2265 "fgl.yacc"
    {
		print_display_by_name(yyvsp[0].str);
                }
    break;

  case 359:
#line 2272 "fgl.yacc"
    { 
				print_display(yyvsp[-1].str,yyvsp[-2].str,yyvsp[0].str);
		}
    break;

  case 360:
#line 2277 "fgl.yacc"
    {
		print_display_form(yyvsp[-1].str,yyvsp[0].str);
	}
    break;

  case 361:
#line 2282 "fgl.yacc"
    {
		push_blockcommand("DISPLAY");
		curr_input_array_attribs.curr_row_display=0;
		}
    break;

  case 362:
#line 2287 "fgl.yacc"
    {
		print_display_array_p1(fgl_add_scope(yyvsp[-6].str,0),yyvsp[-4].str,yyvsp[-1].str,yyvsp[0].str,&curr_input_array_attribs);
	  	A4GL_new_events();
		}
    break;

  case 363:
#line 2291 "fgl.yacc"
    {
		add_continue_blockcommand ("DISPLAY");  
		print_display_array_p2();
		pop_blockcommand("DISPLAY");
	  	A4GL_drop_events();
}
    break;

  case 364:
#line 2300 "fgl.yacc"
    {
strcpy(yyval.str,"0,0");
}
    break;

  case 365:
#line 2302 "fgl.yacc"
    {
	strcpy(yyval.str,field_name_as_char(yyvsp[0].field_entry));
}
    break;

  case 366:
#line 2307 "fgl.yacc"
    {
				sprintf(yyval.str,"0x%lx",atol(yyvsp[0].str));
			}
    break;

  case 372:
#line 2319 "fgl.yacc"
    {
		A4GL_add_event(-11,"");
		print_befaft_field_1("AFT_ROW");
		}
    break;

  case 373:
#line 2323 "fgl.yacc"
    {
		print_befaft_field_2();
	}
    break;

  case 374:
#line 2326 "fgl.yacc"
    {
		A4GL_add_event(-10,"");
		print_befaft_field_1("BEF_ROW");
		}
    break;

  case 375:
#line 2330 "fgl.yacc"
    {
		print_befaft_field_2();
	}
    break;

  case 376:
#line 2333 "fgl.yacc"
    {
		A4GL_add_onkey_key(yyvsp[0].str);
		print_onkey_1(yyvsp[0].str);
		}
    break;

  case 377:
#line 2337 "fgl.yacc"
    {
		print_onkey_2();
	}
    break;

  case 378:
#line 2344 "fgl.yacc"
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

  case 379:
#line 2362 "fgl.yacc"
    {
		print_dealloc_arr(yyvsp[0].str);
	}
    break;

  case 380:
#line 2368 "fgl.yacc"
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

  case 381:
#line 2392 "fgl.yacc"
    {
			print_error(yyvsp[0].str,0);
		}
    break;

  case 382:
#line 2395 "fgl.yacc"
    { 
			print_error(yyvsp[-1].str,1);
	}
    break;

  case 383:
#line 2410 "fgl.yacc"
    { if (in_command("WHILE")) { exit_loop("WHILE"); } else { YYERROR;} }
    break;

  case 384:
#line 2412 "fgl.yacc"
    { if (in_command("INPUT")) { exit_loop("INPUT"); } else { YYERROR;} }
    break;

  case 385:
#line 2414 "fgl.yacc"
    { if (in_command("FOREACH")) { exit_loop("FOREACH"); } else { YYERROR;} }
    break;

  case 386:
#line 2416 "fgl.yacc"
    { if (in_command("FOR")) { exit_loop("FOR"); } else { YYERROR;} }
    break;

  case 387:
#line 2418 "fgl.yacc"
    { if (in_command("CONSTRUCT")) { exit_loop("CONSTRUCT"); } else { YYERROR;} }
    break;

  case 388:
#line 2420 "fgl.yacc"
    { if (in_command("DISPLAY")) { exit_loop("DISPLAY"); } else { YYERROR;} }
    break;

  case 389:
#line 2421 "fgl.yacc"
    {
	if (in_command("MENU")) {
		exit_loop("MENU");
		/* A4GL_lex_printc("cmd_no=-3;continue;\n"); */
	} 
              else YYERROR;}
    break;

  case 390:
#line 2428 "fgl.yacc"
    { if (in_command("CASE")) { exit_loop("CASE"); } else { YYERROR;} }
    break;

  case 391:
#line 2430 "fgl.yacc"
    { if (in_command("PROMPT")) { exit_loop("PROMPT"); } else { YYERROR;} }
    break;

  case 392:
#line 2434 "fgl.yacc"
    { if (in_command("WHILE")) { continue_loop("WHILE");  } else { YYERROR;} }
    break;

  case 393:
#line 2436 "fgl.yacc"
    { if (in_command("INPUT")) { continue_loop("INPUT"); } else { YYERROR;} }
    break;

  case 394:
#line 2438 "fgl.yacc"
    { if (in_command("FOREACH")) { continue_loop("FOREACH");} else { YYERROR;} }
    break;

  case 395:
#line 2440 "fgl.yacc"
    { if (in_command("FOR")) { continue_loop("FOR"); } else { YYERROR;} }
    break;

  case 396:
#line 2442 "fgl.yacc"
    { if (in_command("CONSTRUCT")) { continue_loop("CONSTRUCT"); } else { YYERROR;} }
    break;

  case 397:
#line 2444 "fgl.yacc"
    { if (in_command("DISPLAY")) { continue_loop("DISPLAY"); } else { YYERROR;} }
    break;

  case 398:
#line 2446 "fgl.yacc"
    { if (in_command("MENU")) {  continue_loop("MENU");  } else { YYERROR;} }
    break;

  case 399:
#line 2452 "fgl.yacc"
    { if (in_command("PROMPT")) { continue_loop("PROMPT"); } else { YYERROR;} }
    break;

  case 400:
#line 2466 "fgl.yacc"
    {
	print_exit_program(0);
}
    break;

  case 401:
#line 2469 "fgl.yacc"
    {
	print_exit_program(1);
}
    break;

  case 405:
#line 2488 "fgl.yacc"
    {
	dec_counter();
	yyval.ptr=A4GL_append_expr_expr(yyvsp[-1].ptr,yyvsp[0].ptr);
}
    break;

  case 408:
#line 2494 "fgl.yacc"
    {
	A4GL_debug("Got literal ptr=%p",yyvsp[0].ptr);
}
    break;

  case 409:
#line 2498 "fgl.yacc"
    {
	yyval.ptr=A4GL_new_expr("A4GL_push_int(0);");
	yyval.ptr=A4GL_append_expr_expr(yyval.ptr,yyvsp[0].ptr);
	yyval.ptr=A4GL_append_expr(yyval.ptr,"A4GL_pushop(OP_SUB);");
}
    break;

  case 410:
#line 2503 "fgl.yacc"
    {
	yyval.ptr=yyvsp[0].ptr;
}
    break;

  case 414:
#line 2513 "fgl.yacc"
    { yyval.ptr=A4GL_new_expr("A4GL_add_spaces();"); }
    break;

  case 415:
#line 2514 "fgl.yacc"
    {inc_counter();}
    break;

  case 421:
#line 2520 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_CONCAT);");
}
    break;

  case 422:
#line 2527 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 423:
#line 2527 "fgl.yacc"
    {
strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 425:
#line 2532 "fgl.yacc"
    {yyval.ptr=A4GL_new_expr("A4GL_push_null(2,0);");}
    break;

  case 426:
#line 2536 "fgl.yacc"
    {
	/*set_counter(0);*/
	sprintf(yyval.str,"%d",get_counter_val());
	A4GL_lex_printcomment("/*L1 %s*/\n",yyval.str);
}
    break;

  case 427:
#line 2542 "fgl.yacc"
    {
	sprintf(yyval.str,"%d",get_counter_val());
	A4GL_lex_printcomment("/*L2 %s*/\n",yyval.str);
}
    break;

  case 428:
#line 2550 "fgl.yacc"
    {
	/*set_counter(0);*/
	sprintf(yyval.str,"%d",get_counter_val());
	A4GL_lex_printcomment("/*L1 %s*/\n",yyval.str);
}
    break;

  case 429:
#line 2556 "fgl.yacc"
    {
	sprintf(yyval.str,"%d",get_counter_val());
	A4GL_lex_printcomment("/*L2 %s*/\n",yyval.str);
}
    break;

  case 430:
#line 2565 "fgl.yacc"
    {sprintf(yyval.str,"%d",get_counter_val());}
    break;

  case 431:
#line 2567 "fgl.yacc"
    {
	print_op("OP_CONCAT");
	dec_counter();sprintf(yyval.str,"%d",get_counter_val());
}
    break;

  case 432:
#line 2574 "fgl.yacc"
    {
	A4GL_debug("Print expr (2)");
	print_expr(yyvsp[0].ptr);
}
    break;

  case 433:
#line 2595 "fgl.yacc"
    {
	
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_NOT);");
}
    break;

  case 434:
#line 2600 "fgl.yacc"
    {
	yyval.ptr=A4GL_new_expr("A4GL_push_int(1);");
        inc_counter();
}
    break;

  case 435:
#line 2605 "fgl.yacc"
    {
	inc_counter();
	yyval.ptr=A4GL_new_expr("A4GL_push_int(0);");
}
    break;

  case 436:
#line 2609 "fgl.yacc"
    { yyval.ptr=yyvsp[-1].ptr; }
    break;

  case 437:
#line 2611 "fgl.yacc"
    {
	yyval.ptr=get_in_exists_sql(yyvsp[-1].sql_string,'E');
}
    break;

  case 438:
#line 2614 "fgl.yacc"
    {
	yyval.ptr=get_in_exists_sql(yyvsp[-1].sql_string,'e');
}
    break;

  case 439:
#line 2632 "fgl.yacc"
    {
	sprintf(yyval.str,"%s",A4GL_get_push_literal('S',yyvsp[0].str));
	yyval.ptr=A4GL_new_expr(yyval.str);
	inc_counter();
}
    break;

  case 440:
#line 2638 "fgl.yacc"
    {
	sprintf(yyval.str,"%s",A4GL_get_push_literal('D',yyvsp[0].str));
	yyval.ptr=A4GL_new_expr(yyval.str);
	inc_counter();
}
    break;

  case 441:
#line 2644 "fgl.yacc"
    {
	sprintf(yyval.str,"%s",A4GL_get_push_literal('L',yyvsp[0].str));
	yyval.ptr=A4GL_new_expr(yyval.str);
	inc_counter();
}
    break;

  case 444:
#line 2654 "fgl.yacc"
    {
		sprintf(yyval.str,"%s\n%s",yyvsp[-2].str,yyvsp[0].str);
	}
    break;

  case 445:
#line 2660 "fgl.yacc"
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
               		strcpy(yyval.str,"A4GL_push_variable(&_rep.page_no,2);");
                  		}
          		if (A4GL_aubit_strcasecmp(yyvsp[0].str,"lineno")==0) {
               		flg=1;
               		strcpy(yyval.str,"A4GL_push_variable(&_rep.line_no,2);");
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

  case 446:
#line 2732 "fgl.yacc"
    {
	if (doing_a_print) {
		sprintf(yyval.str,"A4GL_%sset_column(&_rep);",ispdf());
	} else {
		sprintf(yyval.str,"A4GL_ensure_column();");
	}
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,yyval.str);
	
}
    break;

  case 447:
#line 2743 "fgl.yacc"
    {
	if (doing_a_print) {
		sprintf(yyval.str,"A4GL_%sset_column(&_rep);",ispdf());
	} else {
		sprintf(yyval.str,"A4GL_ensure_column();");
	}
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,yyval.str);
}
    break;

  case 448:
#line 2751 "fgl.yacc"
    {
   if (!isin_command("REPORT")) {
   a4gl_yyerror("This can only be done in a report!");
   YYERROR;
} 
insql=0;
	yyval.ptr=A4GL_new_expr(yyvsp[0].str);
}
    break;

  case 449:
#line 2759 "fgl.yacc"
    {insql=1;set_ingroup();}
    break;

  case 450:
#line 2759 "fgl.yacc"
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

  case 451:
#line 2775 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_AND);");
}
    break;

  case 452:
#line 2779 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_OR);");
}
    break;

  case 453:
#line 2785 "fgl.yacc"
    {
	yyval.ptr=yyvsp[0].ptr;
	}
    break;

  case 454:
#line 2788 "fgl.yacc"
    {
		A4GL_debug("Adding to list...");
		yyval.ptr=A4GL_append_expr_expr(yyvsp[-2].ptr,yyvsp[0].ptr);
	}
    break;

  case 455:
#line 2796 "fgl.yacc"
    {
	yyval.ptr=get_in_exists_sql(yyvsp[-1].sql_string,'I');
}
    break;

  case 456:
#line 2800 "fgl.yacc"
    {
	yyval.ptr=get_in_exists_sql(yyvsp[-1].sql_string,'i');
}
    break;

  case 457:
#line 2803 "fgl.yacc"
    {
	char buff[256];
	sprintf(buff,"A4GL_push_int(%d);",length_expr(yyvsp[-1].ptr));
	yyval.ptr=A4GL_append_expr(yyvsp[-1].ptr,buff);
	A4GL_append_expr(yyval.ptr,"A4GL_pushop(OP_IN);");
}
    break;

  case 458:
#line 2809 "fgl.yacc"
    {
	char buff[256];
	sprintf(buff,"A4GL_push_int(%d);",length_expr(yyvsp[-1].ptr));
	yyval.ptr=A4GL_append_expr(yyvsp[-1].ptr,buff);
	A4GL_append_expr(yyval.ptr,"A4GL_pushop(OP_NOTIN);");
}
    break;

  case 459:
#line 2819 "fgl.yacc"
    { 
	strcpy(yyval.str,"A4GL_pushop(OP_ISNULL);");
	yyval.ptr=A4GL_new_expr(yyval.str);
}
    break;

  case 460:
#line 2824 "fgl.yacc"
    {
	strcpy(yyval.str,"A4GL_pushop(OP_ISNOTNULL);");
	yyval.ptr=A4GL_new_expr(yyval.str);
}
    break;

  case 461:
#line 2831 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_push_char(\"\\\\\");A4GL_pushop(OP_MATCHES);");
 }
    break;

  case 462:
#line 2834 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_push_char(\"\\\\\");A4GL_pushop(OP_MATCHES);A4GL_pushop(OP_NOT);");
}
    break;

  case 463:
#line 2837 "fgl.yacc"
    {
	char buff[40];
	sprintf(buff,"A4GL_push_char(%s);A4GL_pushop(OP_MATCHES);",yyvsp[0].str);
	yyval.ptr=A4GL_append_expr(yyvsp[-2].ptr,buff);
 }
    break;

  case 464:
#line 2842 "fgl.yacc"
    {
	char buff[40];
	sprintf(buff,"A4GL_push_char(%s);A4GL_pushop(OP_MATCHES);A4GL_pushop(OP_NOT);",yyvsp[0].str);
	yyval.ptr=A4GL_append_expr(yyvsp[-2].ptr,buff);
}
    break;

  case 465:
#line 2849 "fgl.yacc"
    {
	char buff[40];
	sprintf(buff,"A4GL_push_char(\"\\\\\");A4GL_pushop(OP_LIKE);");
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,buff);
}
    break;

  case 466:
#line 2854 "fgl.yacc"
    {
	char buff[40];
	sprintf(buff,"A4GL_push_char(\"\\\\\");A4GL_pushop(OP_LIKE);A4GL_pushop(OP_NOT);");
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,buff);
}
    break;

  case 467:
#line 2859 "fgl.yacc"
    {
	char buff[40];
	sprintf(buff,"A4GL_push_char(%s);A4GL_pushop(OP_LIKE);",yyvsp[0].str);
	yyval.ptr=A4GL_append_expr(yyvsp[-2].ptr,buff);
}
    break;

  case 468:
#line 2864 "fgl.yacc"
    {
	char buff[40];
	sprintf(buff,"A4GL_push_char(%s);A4GL_pushop(OP_LIKE);A4GL_pushop(OP_NOT);",yyvsp[0].str);
	yyval.ptr=A4GL_append_expr(yyvsp[-2].ptr,buff);
}
    break;

  case 469:
#line 2875 "fgl.yacc"
    {
	strcpy(yyval.str,"A4GL_pushop(OP_CLIP);");
	yyval.ptr=A4GL_new_expr(yyval.str);
	inc_counter();
}
    break;

  case 470:
#line 2883 "fgl.yacc"
    {
	sprintf(yyval.str,"%s A4GL_pushop(OP_USING);",yyvsp[0].str);
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_USING);");
}
    break;

  case 471:
#line 2891 "fgl.yacc"
    {
	A4GL_debug("PLUS in math_expr $<ptr>2 = %p",yyvsp[0].ptr);
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_ADD);");
}
    break;

  case 472:
#line 2896 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_SUB);");
}
    break;

  case 473:
#line 2900 "fgl.yacc"
    {
      sprintf(yyval.str,"%s A4GL_A4GL_pushop(OP_MULT);",yyvsp[0].str);
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_MULT);");
}
    break;

  case 474:
#line 2905 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_DIV);");
}
    break;

  case 475:
#line 2909 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_MOD);");
}
    break;

  case 476:
#line 2913 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_POWER);");
}
    break;

  case 477:
#line 2919 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_EQUAL);");
}
    break;

  case 478:
#line 2922 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_EQUAL);");
}
    break;

  case 479:
#line 2926 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_LESS_THAN);");
}
    break;

  case 480:
#line 2930 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_GREATER_THAN);");
}
    break;

  case 481:
#line 2934 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_NOT_EQUAL);");
}
    break;

  case 482:
#line 2938 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_LESS_THAN_EQ);");
}
    break;

  case 483:
#line 2942 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_GREATER_THAN_EQ);");
}
    break;

  case 484:
#line 2949 "fgl.yacc"
    {
	reset_counter();
}
    break;

  case 485:
#line 2959 "fgl.yacc"
    { 
		addmap("Call",yyvsp[-1].str,curr_func,yylineno,infilename);
		new_counter(); 
		}
    break;

  case 486:
#line 2964 "fgl.yacc"
    { 
		sprintf(yyval.str,"%d",get_counter_val()); 
		A4GL_lex_printcomment("/*function_call_expr2 %s*/\n",yyval.str);
		drop_counter(); 
		}
    break;

  case 487:
#line 2970 "fgl.yacc"
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

  case 488:
#line 2980 "fgl.yacc"
    {
        sprintf(yyval.str,"\"%s\",\"%s\"",yyvsp[-3].str,yyvsp[-1].str);
	A4GL_debug("NEWFORMAT : %s\n",yyval.str);
        A4GLSQL_set_status(0,0);
        new_counter();
}
    break;

  case 489:
#line 2985 "fgl.yacc"
    {
	sprintf(yyval.str,"%d",get_counter_val());  
	drop_counter();
}
    break;

  case 490:
#line 2988 "fgl.yacc"
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

  case 491:
#line 3002 "fgl.yacc"
    {chk4var=1;}
    break;

  case 492:
#line 3002 "fgl.yacc"
    {chk4var=0;}
    break;

  case 493:
#line 3002 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[-2].ptr,"aclfgl_date(1);");
}
    break;

  case 494:
#line 3005 "fgl.yacc"
    {chk4var=1;}
    break;

  case 495:
#line 3005 "fgl.yacc"
    {chk4var=0;}
    break;

  case 496:
#line 3005 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[-2].ptr,"aclfgl_month(1);");
	/* consumes and replaces a fgl_expr_c - so we don't need to dec or inc_counter */
}
    break;

  case 497:
#line 3009 "fgl.yacc"
    {chk4var=1;}
    break;

  case 498:
#line 3009 "fgl.yacc"
    {chk4var=0;}
    break;

  case 499:
#line 3009 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[-2].ptr,"aclfgl_day(1);");
	/* consumes and replaces a fgl_expr_c - so we don't need to dec or inc_counter */
}
    break;

  case 500:
#line 3013 "fgl.yacc"
    {chk4var=1;}
    break;

  case 501:
#line 3013 "fgl.yacc"
    {chk4var=0;}
    break;

  case 502:
#line 3013 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[-2].ptr,"aclfgl_year(1);");
	/* consumes and replaces a fgl_expr_c - so we don't need to dec or inc_counter */
}
    break;

  case 503:
#line 3017 "fgl.yacc"
    {
	char buff[256];
	sprintf(buff,"acli_interval(%s,%s);",yyvsp[-2].str,yyvsp[0].str);
	yyval.ptr=A4GL_new_expr(buff);
	inc_counter();
}
    break;

  case 504:
#line 3023 "fgl.yacc"
    {
	char buff[256];
	sprintf(buff,"acli_datetime(%s,%s);",yyvsp[-2].str,yyvsp[0].str);
	yyval.ptr=A4GL_new_expr(buff);
	inc_counter();
}
    break;

  case 505:
#line 3029 "fgl.yacc"
    {
	char buff[256];
	sprintf(buff,"acli_datetime(\"%s\",%s);",yyvsp[-2].str,yyvsp[0].str);
	yyval.ptr=A4GL_new_expr(buff);
	inc_counter();
}
    break;

  case 506:
#line 3035 "fgl.yacc"
    {
	char buff[256];
	sprintf(buff,"acli_datetime(\"%s\",%s);",yyvsp[-2].str,yyvsp[0].str);
	yyval.ptr=A4GL_new_expr(buff);
	inc_counter();
}
    break;

  case 507:
#line 3043 "fgl.yacc"
    {
	char buff[256];
	sprintf(buff,"acli_datetime(\"%s:%s\",%s);",yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str);
	yyval.ptr=A4GL_new_expr(buff);
	inc_counter();
}
    break;

  case 508:
#line 3049 "fgl.yacc"
    {
	char buff[256];
	sprintf(buff,"acli_datetime(\"%s:%s\",%s);",yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str);
	yyval.ptr=A4GL_new_expr(buff);
	inc_counter();
}
    break;

  case 509:
#line 3057 "fgl.yacc"
    {
	char buff[256];
	sprintf(buff,"acli_datetime(\"%s:%s:%s\",%s);",yyvsp[-6].str,yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str);
	yyval.ptr=A4GL_new_expr(buff);
	inc_counter();
}
    break;

  case 510:
#line 3063 "fgl.yacc"
    {
	char buff[256];
	sprintf(buff,"acli_datetime(\"%s:%s:%s\",%s);",yyvsp[-6].str,yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str);
	yyval.ptr=A4GL_new_expr(buff);
	inc_counter();
}
    break;

  case 511:
#line 3072 "fgl.yacc"
    {
	char buff[256];
	sprintf(buff,"acli_datetime(\"%s %s\",%s);",yyvsp[-3].str,yyvsp[-2].str,yyvsp[0].str);
	yyval.ptr=A4GL_new_expr(buff);
	inc_counter();
}
    break;

  case 512:
#line 3078 "fgl.yacc"
    {
	char buff[256];
	sprintf(buff,"acli_datetime(\"%s %s:%s\",%s);",yyvsp[-5].str,yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str);
	yyval.ptr=A4GL_new_expr(buff);
	inc_counter();
}
    break;

  case 513:
#line 3085 "fgl.yacc"
    {
	char buff[256];
	sprintf(buff,"acli_datetime(\"%s %s:%s%s\",%s);",yyvsp[-7].str,yyvsp[-6].str,yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str);
	yyval.ptr=A4GL_new_expr(buff);
	inc_counter();
}
    break;

  case 514:
#line 3092 "fgl.yacc"
    {
	char buff[256];
	sprintf(buff,"acli_datetime(\"%s %s:%s%s\",%s);",yyvsp[-7].str,yyvsp[-6].str,yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str);
	yyval.ptr=A4GL_new_expr(buff);
	inc_counter();
}
    break;

  case 515:
#line 3101 "fgl.yacc"
    {
	char buff[256];
	sprintf(buff,"acli_datetime(\"%s-%s\",%s);",yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str);
	yyval.ptr=A4GL_new_expr(buff);
	inc_counter();
}
    break;

  case 516:
#line 3107 "fgl.yacc"
    {
	char buff[256];
	sprintf(buff,"acli_datetime(\"%s-%s-%s\",%s);",yyvsp[-6].str,yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str);
	yyval.ptr=A4GL_new_expr(buff);
	inc_counter();
}
    break;

  case 517:
#line 3113 "fgl.yacc"
    {
	char buff[256];
	sprintf(buff,"acli_datetime(\"%s-%s %s\",%s);",yyvsp[-5].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[0].str);
	yyval.ptr=A4GL_new_expr(buff);
	inc_counter();
}
    break;

  case 518:
#line 3120 "fgl.yacc"
    {
	char buff[256];
	sprintf(buff,"acli_datetime(\"%s-%s-%s %s\",%s);",yyvsp[-7].str,yyvsp[-5].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[0].str);
	yyval.ptr=A4GL_new_expr(buff);
	inc_counter();
}
    break;

  case 519:
#line 3126 "fgl.yacc"
    {
	char buff[256];
	sprintf(buff,"acli_datetime(\"%s-%s-%s %s:%s\",%s);",yyvsp[-9].str,yyvsp[-7].str,yyvsp[-5].str,yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str);
	yyval.ptr=A4GL_new_expr(buff);
	inc_counter();
}
    break;

  case 520:
#line 3132 "fgl.yacc"
    {
	char buff[256];
	sprintf(buff,"acli_datetime(\"%s-%s-%s %s:%s:%s\",%s);",yyvsp[-11].str,yyvsp[-9].str,yyvsp[-7].str,yyvsp[-6].str,yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str);
	yyval.ptr=A4GL_new_expr(buff);
	inc_counter();
}
    break;

  case 521:
#line 3138 "fgl.yacc"
    {
	char buff[256];
	sprintf(buff,"acli_datetime(\"%s-%s-%s %s:%s:%s\",%s);",yyvsp[-11].str,yyvsp[-9].str,yyvsp[-7].str,yyvsp[-6].str,yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str);
	yyval.ptr=A4GL_new_expr(buff);
	inc_counter();
}
    break;

  case 522:
#line 3146 "fgl.yacc"
    {
	char buff[256];
	sprintf(buff,"acli_datetime(\"%s-%s %s:%s\",%s);",yyvsp[-7].str,yyvsp[-5].str,yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str);
	yyval.ptr=A4GL_new_expr(buff);
	inc_counter();
}
    break;

  case 523:
#line 3152 "fgl.yacc"
    {
	char buff[256];
	sprintf(buff,"acli_datetime(\"%s-%s %s:%s:%s\",%s);",yyvsp[-9].str,yyvsp[-7].str,yyvsp[-6].str,yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str);
	yyval.ptr=A4GL_new_expr(buff);
	inc_counter();
}
    break;

  case 524:
#line 3158 "fgl.yacc"
    {
	char buff[256];
	sprintf(buff,"acli_datetime(\"%s-%s %s:%s:%s\",%s);",yyvsp[-9].str,yyvsp[-7].str,yyvsp[-6].str,yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str);
	yyval.ptr=A4GL_new_expr(buff);
	inc_counter();
}
    break;

  case 525:
#line 3170 "fgl.yacc"
    {
	char buff[256];
	sprintf(buff,"A4GL_isdynarr_allocated(&%s);",yyvsp[-1].str);
        yyval.ptr=A4GL_new_expr(buff);
        inc_counter();
}
    break;

  case 526:
#line 3176 "fgl.yacc"
    { 
        char buff[256];
        sprintf(buff,"A4GL_dynarr_extent(&%s,%d);",yyvsp[-3].str,atoi(yyvsp[-1].str));
        yyval.ptr=A4GL_new_expr(buff);
        inc_counter();
}
    break;

  case 527:
#line 3186 "fgl.yacc"
    {strcpy(yyval.str,"-1");}
    break;

  case 528:
#line 3187 "fgl.yacc"
    {sprintf(yyval.str,"%d",atoi(yyvsp[-2].str)*16+atoi(yyvsp[0].str));}
    break;

  case 531:
#line 3195 "fgl.yacc"
    {
	if (!isin_command("INPUT")&&!isin_command("CONSTRUCT")) { 
   		a4gl_yyerror("get_fldbuf can only be used in an input or construct");
   		YYERROR;
	}
sprintf(yyval.str,"{int _retvars;\n_retvars=A4GL_fgl_getfldbuf(_sio_%d,_inp_io_type,%s,0,0);\nif (_retvars != 1 ) {A4GLSQL_set_status(-3001,0);A4GL_chk_err(%d,\"%s\");}\n}\n",get_sio_id("ALL"),
	field_name_list_as_char(yyvsp[-1].field_list), lastlineno,infilename); 
	yyval.ptr=A4GL_new_expr(yyval.str);	
	inc_counter();

}
    break;

  case 532:
#line 3206 "fgl.yacc"
    {sprintf(yyval.str,"A4GL_push_int(A4GL_fgl_fieldnametoid(\"\",%s));",field_name_as_char(yyvsp[-1].field_entry)); yyval.ptr=A4GL_new_expr(yyval.str); }
    break;

  case 533:
#line 3207 "fgl.yacc"
    {
sprintf(yyval.str,"A4GL_push_int(A4GL_fgl_fieldnametoid(\"\",%s));",field_name_as_char(yyvsp[-1].field_entry)); yyval.ptr=A4GL_new_expr(yyval.str); 
addmap("Get Field",field_name_as_char(yyvsp[-1].field_entry),curr_func,yylineno,infilename);
	inc_counter();
}
    break;

  case 534:
#line 3213 "fgl.yacc"
    {
/* Informix allows this outside of a input/construct... */
	if (isin_command("INPUT")&&!isin_command("CONSTRUCT")) { 
		sprintf(yyval.str,"A4GL_push_int(A4GL_fgl_infield(_sio_%d,_inp_io_type,%s,0,0));",get_sio_id("ALL"),field_name_list_as_char(yyvsp[-1].field_list)); 
	} else {
		sprintf(yyval.str,"A4GL_push_int(A4GL_fgl_infield(0,0,%s,0,0));",field_name_list_as_char(yyvsp[-1].field_list)); 
	}
	yyval.ptr=A4GL_new_expr(yyval.str);
	inc_counter();
}
    break;

  case 535:
#line 3224 "fgl.yacc"
    { 
	if (!isin_command("INPUT")&&!isin_command("CONSTRUCT")) { 
   		a4gl_yyerror("field_touched can only be used in an input or construct");
   		YYERROR;
	}
	sprintf(yyval.str,"A4GL_push_int(A4GL_fgl_fieldtouched(_sio_%d,_inp_io_type,%s,0,0));",get_sio_id("ALL"),field_name_list_as_char(yyvsp[-1].field_list)); 
	yyval.ptr=A4GL_new_expr(yyval.str);
	inc_counter();
}
    break;

  case 536:
#line 3234 "fgl.yacc"
    { 
	if (!isin_command("INPUT")&&!isin_command("CONSTRUCT")) { 
   		a4gl_yyerror("field_touched can only be used in an input or construct");
   		YYERROR;
	}
	sprintf(yyval.str,"A4GL_push_int(!A4GL_fgl_fieldtouched(_sio_%d,_inp_io_type,%s,0,0));",get_sio_id("ALL"),field_name_list_as_char(yyvsp[-1].field_list)); 
	yyval.ptr=A4GL_new_expr(yyval.str);
	inc_counter();
}
    break;

  case 539:
#line 3247 "fgl.yacc"
    {
		inc_counter();
               sprintf(yyval.str,"A4GL_push_current(%s);",yyvsp[0].str);
		yyval.ptr=A4GL_new_expr(yyval.str);
          	}
    break;

  case 540:
#line 3252 "fgl.yacc"
    { inc_counter(); strcpy(yyval.str,"A4GL_push_today();");
		yyval.ptr=A4GL_new_expr(yyval.str);
		}
    break;

  case 541:
#line 3259 "fgl.yacc"
    { 
	yyval.ptr=A4GL_append_expr(yyvsp[-1].ptr,"A4GL_upshift_stk();");
}
    break;

  case 542:
#line 3263 "fgl.yacc"
    { 
	yyval.ptr=A4GL_append_expr(yyvsp[-1].ptr,"A4GL_downshift_stk();");
}
    break;

  case 543:
#line 3266 "fgl.yacc"
    { 
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_push_ascii();");
}
    break;

  case 544:
#line 3269 "fgl.yacc"
    { 
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"aclfgli_extend();"); }
    break;

  case 545:
#line 3275 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[-1].ptr,"A4GL_push_double(-1);A4GL_pushop(OP_MULT);");
}
    break;

  case 546:
#line 3278 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[-1].ptr,"A4GL_push_double(-28.3465);A4GL_pushop(OP_MULT);");
}
    break;

  case 547:
#line 3281 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[-1].ptr,"A4GL_push_double(-72.0);A4GL_pushop(OP_MULT);");
}
    break;

  case 548:
#line 3298 "fgl.yacc"
    {
	strcpy(yyval.str,yyvsp[0].str);
}
    break;

  case 549:
#line 3301 "fgl.yacc"
    {
	strcpy(yyval.str,yyvsp[0].str);
}
    break;

  case 550:
#line 3307 "fgl.yacc"
    {sprintf(yyval.str,"-%s",yyvsp[0].str);}
    break;

  case 551:
#line 3308 "fgl.yacc"
    {sprintf(yyval.str,"\"%s\"",yyvsp[0].str);}
    break;

  case 552:
#line 3309 "fgl.yacc"
    {sprintf(yyval.str,"\"%s\"",yyvsp[0].str);}
    break;

  case 554:
#line 3314 "fgl.yacc"
    {sprintf(yyval.str,"%s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 555:
#line 3315 "fgl.yacc"
    {sprintf(yyval.str,"%s %s:%s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 556:
#line 3316 "fgl.yacc"
    {sprintf(yyval.str,"%s %s:%s:%s",yyvsp[-5].str,yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 557:
#line 3317 "fgl.yacc"
    {sprintf(yyval.str,"%s %s:%s:%s",yyvsp[-5].str,yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 558:
#line 3319 "fgl.yacc"
    {sprintf(yyval.str,"%s:%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 559:
#line 3320 "fgl.yacc"
    {sprintf(yyval.str,"%s:%s:%s",yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 560:
#line 3321 "fgl.yacc"
    {sprintf(yyval.str,"%s:%s:%s",yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 561:
#line 3323 "fgl.yacc"
    {sprintf(yyval.str,"%s:%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 562:
#line 3324 "fgl.yacc"
    {sprintf(yyval.str,"%s",yyvsp[0].str);}
    break;

  case 564:
#line 3330 "fgl.yacc"
    {sprintf(yyval.str,"%s-%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 565:
#line 3334 "fgl.yacc"
    {
                        yyval.field_list=new_field_list();
                        yyval.field_list=append_field_to_list(yyval.field_list,yyvsp[0].field_entry);
		}
    break;

  case 566:
#line 3338 "fgl.yacc"
    {
                        yyval.field_list=append_field_to_list(yyvsp[-2].field_list,yyvsp[0].field_entry);
	}
    break;

  case 567:
#line 3343 "fgl.yacc"
    {
                        yyval.field_list=new_field_list();
                        yyval.field_list=append_field_to_list(yyval.field_list,yyvsp[0].field_entry);
		}
    break;

  case 568:
#line 3347 "fgl.yacc"
    {
                        yyval.field_list=append_field_to_list(yyvsp[-2].field_list,yyvsp[0].field_entry);
	}
    break;

  case 569:
#line 3362 "fgl.yacc"
    {
print_for_start(yyvsp[-5].str);
push_blockcommand("FOR");
}
    break;

  case 570:
#line 3366 "fgl.yacc"
    {A4GL_debug("For_cmds\n");}
    break;

  case 571:
#line 3367 "fgl.yacc"
    {

pop_blockcommand("FOR");
print_for_end();
A4GL_lex_printcomment(" /*END FOR*/\n");}
    break;

  case 572:
#line 3374 "fgl.yacc"
    {
		print_for_default_step();
	}
    break;

  case 574:
#line 3391 "fgl.yacc"
    {
push_blockcommand("FOREACH");
}
    break;

  case 575:
#line 3395 "fgl.yacc"
    {
print_foreach_start();
A4GL_lex_printcomment(" /* foreach */\n");
}
    break;

  case 576:
#line 3401 "fgl.yacc"
    {
print_foreach_next(yyvsp[-3].str,yyvsp[-1].str,yyvsp[0].str);
}
    break;

  case 577:
#line 3405 "fgl.yacc"
    {
add_continue_blockcommand ("FOREACH");
print_foreach_end(yyvsp[-6].str);
pop_blockcommand("FOREACH"); 
print_foreach_close(yyvsp[-6].str);
}
    break;

  case 578:
#line 3414 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 579:
#line 3415 "fgl.yacc"
    {
		strcpy(yyval.str,yyvsp[0].str);
	}
    break;

  case 580:
#line 3427 "fgl.yacc"
    {
		sprintf(curr_func,"%s",yyvsp[0].str); 
		print_formhandler(yyvsp[0].str);
		start_state("formhandler",1);
	push_blockcommand("FORMHANDLER");
        }
    break;

  case 581:
#line 3433 "fgl.yacc"
    {
		print_variables();
		print_getwin();
	}
    break;

  case 582:
#line 3441 "fgl.yacc"
    {
pop_blockcommand("FORMHANDLER");
print_end_formhandler(); 
start_state("formhandler",0);}
    break;

  case 589:
#line 3458 "fgl.yacc"
    {
		print_event('B');
        }
    break;

  case 590:
#line 3460 "fgl.yacc"
    {
		print_event_2();
        }
    break;

  case 591:
#line 3463 "fgl.yacc"
    {
		print_event('b');
        }
    break;

  case 592:
#line 3465 "fgl.yacc"
    {
		print_event_2();
        }
    break;

  case 597:
#line 3479 "fgl.yacc"
    {
		print_event('A');
        }
    break;

  case 598:
#line 3481 "fgl.yacc"
    {
		print_event_2();
        }
    break;

  case 599:
#line 3484 "fgl.yacc"
    {
		print_event('a');
        }
    break;

  case 600:
#line 3486 "fgl.yacc"
    {
		print_event_2();
        }
    break;

  case 613:
#line 3517 "fgl.yacc"
    { 
			print_gtk_field('B',0);
		}
    break;

  case 614:
#line 3519 "fgl.yacc"
    {
			print_gtk_field_2();
		}
    break;

  case 615:
#line 3522 "fgl.yacc"
    { 
			print_gtk_field('A',0);
		}
    break;

  case 616:
#line 3524 "fgl.yacc"
    {
			print_gtk_field_2();
		}
    break;

  case 617:
#line 3527 "fgl.yacc"
    {
			print_gtk_field('b',yyvsp[0].str);
		}
    break;

  case 618:
#line 3529 "fgl.yacc"
    { 
			print_gtk_field_2();
		}
    break;

  case 619:
#line 3532 "fgl.yacc"
    {
			print_gtk_field('a',yyvsp[0].str);
		}
    break;

  case 620:
#line 3534 "fgl.yacc"
    { 
			print_gtk_field_2();
		}
    break;

  case 621:
#line 3537 "fgl.yacc"
    { 
			print_gtk_field('o',yyvsp[0].str);
		}
    break;

  case 622:
#line 3539 "fgl.yacc"
    { 
			print_gtk_field_2();
		}
    break;

  case 623:
#line 3554 "fgl.yacc"
    {
		//print_niy("Free Cursor");
		A4GL_lex_printcomment(" /* FIXME: Not implemented: Free Cursor */\n");;

		strcpy(yyval.str,"");
		}
    break;

  case 624:
#line 3570 "fgl.yacc"
    {sprintf(yyval.str,"%d",-1-(atoi(yyvsp[0].str)));}
    break;

  case 625:
#line 3571 "fgl.yacc"
    {strcpy(yyval.str,"-1");}
    break;

  case 626:
#line 3572 "fgl.yacc"
    {sprintf (yyval.str,"%d",atoi(yyvsp[0].str)+1);}
    break;

  case 627:
#line 3573 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 628:
#line 3574 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 629:
#line 3575 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 630:
#line 3576 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 634:
#line 3584 "fgl.yacc"
    {sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str); }
    break;

  case 636:
#line 3590 "fgl.yacc"
    { 
			yyval.field_entry=new_field_entry(yyvsp[0].str,"1",1);
		}
    break;

  case 637:
#line 3593 "fgl.yacc"
    { 
				char buff[256];
				sprintf(buff,"int_to_id(%s)",yyvsp[-1].str);
				yyval.field_entry=new_field_entry(buff,"1",0); 
		}
    break;

  case 638:
#line 3598 "fgl.yacc"
    { 
				char buff[256];
				sprintf(buff,"int_to_id(%s.%s)",yyvsp[-5].str,yyvsp[-1].str); 
				yyval.field_entry=new_field_entry(buff,"1",0); 
		}
    break;

  case 639:
#line 3603 "fgl.yacc"
    {
				yyval.field_entry=new_field_entry(yyvsp[-3].str,yyvsp[-1].str,1);
		}
    break;

  case 640:
#line 3606 "fgl.yacc"
    {
				char buff[256];
				sprintf(buff,"%s.*",yyvsp[-2].str);
				yyval.field_entry=new_field_entry(buff,"1",1);
		}
    break;

  case 641:
#line 3611 "fgl.yacc"
    {
				char buff[256];
				sprintf(buff,"%s.*",yyvsp[-5].str);
				yyval.field_entry=new_field_entry(buff,yyvsp[-3].str,1);
		}
    break;

  case 642:
#line 3616 "fgl.yacc"
    {
				char buff[256];
				sprintf(buff,"%s.%s",yyvsp[-2].str,yyvsp[0].str);
				yyval.field_entry=new_field_entry(buff,"1",1);
		}
    break;

  case 643:
#line 3621 "fgl.yacc"
    {
				char buff[256];
				sprintf(buff,"%s.%s",yyvsp[-5].str,yyvsp[0].str);
				yyval.field_entry=new_field_entry(buff,yyvsp[-3].str,1);
		}
    break;

  case 644:
#line 3628 "fgl.yacc"
    {yyval.field_entry=yyvsp[0].field_entry;}
    break;

  case 645:
#line 3629 "fgl.yacc"
    { 
                 char buff[256];
                 sprintf(buff,"%s",yyvsp[0].str);
                 yyval.field_entry=new_field_entry(buff,"1",0);
	}
    break;

  case 646:
#line 3636 "fgl.yacc"
    {
				print_pushchar(yyvsp[0].str);
				addmap("Cursor",last_var,curr_func,yylineno,infilename);
			}
    break;

  case 647:
#line 3643 "fgl.yacc"
    {sprintf(yyval.str,"%s",yyvsp[0].str);}
    break;

  case 648:
#line 3645 "fgl.yacc"
    {sprintf(yyval.str,"%s",yyvsp[0].str);
addmap("Window",last_var,curr_func,yylineno,infilename);
}
    break;

  case 649:
#line 3651 "fgl.yacc"
    {sprintf(yyval.str,"%s",yyvsp[0].str);
addmap("Open Window",last_var,curr_func,yylineno,infilename);
}
    break;

  case 650:
#line 3656 "fgl.yacc"
    {sprintf(yyval.str,"%s",yyvsp[0].str);
addmap("Form",last_var,curr_func,yylineno,infilename);
}
    break;

  case 651:
#line 3661 "fgl.yacc"
    {sprintf(yyval.str,"%s",yyvsp[0].str);
addmap("Open Form",last_var,curr_func,yylineno,infilename);
}
    break;

  case 652:
#line 3666 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 653:
#line 3666 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 654:
#line 3669 "fgl.yacc"
    { 
			strcpy(yyval.str,downshift(yyvsp[0].str)) ;
}
    break;

  case 655:
#line 3675 "fgl.yacc"
    {
			sprintf(yyval.str,"%s",downshift(yyvsp[0].str)) ;
			}
    break;

  case 656:
#line 3680 "fgl.yacc"
    {
	strcpy(yyval.str,do_clobbering(clobber,downshift(yyvsp[0].str))) ;
	strcpy(last_var,downshift(yyvsp[0].str));
}
    break;

  case 657:
#line 3684 "fgl.yacc"
    {
		sprintf(yyval.str,"aclfgli_str_to_id(%s)",yyvsp[-1].str);
		sprintf(last_var,"->%s",yyvsp[-1].str);
	}
    break;

  case 660:
#line 3692 "fgl.yacc"
    {
					yyval.field_entry=new_field_entry(yyvsp[0].str,"1",1); 
				}
    break;

  case 661:
#line 3695 "fgl.yacc"
    {
					yyval.field_entry=new_field_entry(yyvsp[-3].str,yyvsp[-1].str,1); 
				}
    break;

  case 662:
#line 3698 "fgl.yacc"
    {
					char buff[256];
					sprintf(buff,"%s.*",yyvsp[-2].str);
					yyval.field_entry=new_field_entry(buff,"1",1); 
				}
    break;

  case 663:
#line 3703 "fgl.yacc"
    {
					char buff[256];
					sprintf(buff,"%s.*",yyvsp[-5].str);
					yyval.field_entry=new_field_entry(buff,yyvsp[-3].str,1); 
				}
    break;

  case 664:
#line 3708 "fgl.yacc"
    {
					char buff[256];
					sprintf(buff,"%s.%s",yyvsp[-2].str,yyvsp[0].str);
					yyval.field_entry=new_field_entry(buff,"1",1); 
				}
    break;

  case 665:
#line 3713 "fgl.yacc"
    {
					char buff[256];
					sprintf(buff,"%s.%s",yyvsp[-5].str,yyvsp[0].str);
					yyval.field_entry=new_field_entry(buff,yyvsp[-3].str,1); 
				}
    break;

  case 666:
#line 3720 "fgl.yacc"
    {
A4GL_debug("Scanvar=%d",scan_variable(yyvsp[0].str)&15);
if ((scan_variable(yyvsp[0].str)&15)!=0) {
a4gl_yyerror("Only a character variable can be used for this");
YYERROR;
}
}
    break;

  case 668:
#line 3729 "fgl.yacc"
    {
		sprintf(yyval.str,".%s",yyvsp[0].str);
}
    break;

  case 669:
#line 3791 "fgl.yacc"
    {
	char buff[256];
	strcpy(buff,yyvsp[0].str);
	A4GL_convlower(buff);
	print_goto(buff);
}
    break;

  case 671:
#line 3800 "fgl.yacc"
    {sprintf(yyval.str,"%s",yyvsp[0].str);}
    break;

  case 672:
#line 3809 "fgl.yacc"
    {
print_gui_do_menuitems(yyvsp[0].str,'C');
}
    break;

  case 674:
#line 3816 "fgl.yacc"
    {sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 675:
#line 3819 "fgl.yacc"
    {
        sprintf(yyval.str,"\"%s\"",yyvsp[0].str);
}
    break;

  case 676:
#line 3825 "fgl.yacc"
    {
print_gui_do_menuitems(yyvsp[0].str,'U');
}
    break;

  case 677:
#line 3831 "fgl.yacc"
    {
print_gui_do_menuitems(yyvsp[0].str,'D');
}
    break;

  case 678:
#line 3835 "fgl.yacc"
    {
print_gui_do_fields(field_name_list_as_char(yyvsp[0].field_list),'D');
}
    break;

  case 679:
#line 3839 "fgl.yacc"
    {
print_gui_do_form(yyvsp[-2].str,field_name_list_as_char(yyvsp[0].field_list),'D');
}
    break;

  case 680:
#line 3845 "fgl.yacc"
    {
print_gui_do_menuitems(yyvsp[0].str,'E');
}
    break;

  case 681:
#line 3849 "fgl.yacc"
    {
print_gui_do_fields(field_name_list_as_char(yyvsp[0].field_list),'E');
}
    break;

  case 682:
#line 3853 "fgl.yacc"
    {
print_gui_do_form(field_name_list_as_char(yyvsp[-2].field_list),yyvsp[0].str,'E');
}
    break;

  case 683:
#line 3858 "fgl.yacc"
    {start_state("messagebox",1);}
    break;

  case 684:
#line 3863 "fgl.yacc"
    {start_state("messagebox",0);}
    break;

  case 703:
#line 3904 "fgl.yacc"
    {
		if_print_stack_cnt++;
		if_print_stack[if_print_stack_cnt][0]=0;
		if_print_stack[if_print_stack_cnt][1]=0;
		if_print_section[if_print_stack_cnt]=0;
		print_if_start();
	}
    break;

  case 704:
#line 3911 "fgl.yacc"
    {
		if_print_section[if_print_stack_cnt]=1;
	}
    break;

  case 705:
#line 3913 "fgl.yacc"
    {
		char wt;
		print_if_end();
	        wt=get_curr_report_stack_whytype_1();
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

  case 707:
#line 3932 "fgl.yacc"
    {
		print_if_else();
	}
    break;

  case 709:
#line 3935 "fgl.yacc"
    {
		print_if_else();
		}
    break;

  case 710:
#line 3937 "fgl.yacc"
    {

		print_if_start();
	}
    break;

  case 711:
#line 3940 "fgl.yacc"
    {
		print_if_end();
	}
    break;

  case 712:
#line 3944 "fgl.yacc"
    {
		print_import(yyvsp[-3].str,atoi(yyvsp[-1].str));
	}
    break;

  case 713:
#line 3947 "fgl.yacc"
    {
		print_import_legacy(yyvsp[0].str);
	}
    break;

  case 714:
#line 3953 "fgl.yacc"
    { add_ex_dtype(yyvsp[0].str); }
    break;

  case 715:
#line 3964 "fgl.yacc"
    {A4GL_debug("init to\n");}
    break;

  case 716:
#line 3965 "fgl.yacc"
    {
	print_init();
 }
    break;

  case 717:
#line 3968 "fgl.yacc"
    {
	print_init_table(yyvsp[0].str);
}
    break;

  case 719:
#line 3974 "fgl.yacc"
    {sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 720:
#line 3978 "fgl.yacc"
    {setrecord(yyval.str,yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 721:
#line 3979 "fgl.yacc"
    {setrecord(yyval.str,yyvsp[-2].str,0);}
    break;

  case 722:
#line 3983 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 726:
#line 3998 "fgl.yacc"
    {
sprintf(yyval.str,"0");
}
    break;

  case 727:
#line 4000 "fgl.yacc"
    {
sprintf(yyval.str,"1");
}
    break;

  case 730:
#line 4009 "fgl.yacc"
    {
		A4GL_add_event(-97,field_name_list_as_or_char(yyvsp[0].field_list));
		print_befaft_field_1(field_name_list_as_or_char(yyvsp[0].field_list));
}
    break;

  case 731:
#line 4012 "fgl.yacc"
    {
	print_befaft_field_2();
}
    break;

  case 732:
#line 4016 "fgl.yacc"
    {
		A4GL_add_event(-98,field_name_list_as_or_char(yyvsp[0].field_list));
		print_befaft_field_1(field_name_list_as_or_char(yyvsp[0].field_list));
}
    break;

  case 733:
#line 4019 "fgl.yacc"
    {
	print_befaft_field_2();
}
    break;

  case 734:
#line 4022 "fgl.yacc"
    {
		A4GL_add_event(-11,"");
		print_befaft_field_1("AFT_ROW");
}
    break;

  case 735:
#line 4025 "fgl.yacc"
    {
	print_befaft_field_2();
}
    break;

  case 736:
#line 4028 "fgl.yacc"
    {
		A4GL_add_event(-10,"");
		A4GL_lex_printcomment("/* before row */ \n");
		print_befaft_field_1("BEF_ROW");
}
    break;

  case 737:
#line 4032 "fgl.yacc"
    {
	print_befaft_field_2();
		}
    break;

  case 738:
#line 4035 "fgl.yacc"
    {
	A4GL_add_onkey_key(yyvsp[0].str);
	print_onkey_1(yyvsp[0].str);
}
    break;

  case 739:
#line 4038 "fgl.yacc"
    {
	print_onkey_2();
}
    break;

  case 740:
#line 4041 "fgl.yacc"
    {
		A4GL_add_event(-95,"");
		print_befaft_field_1("AFTER_INP");
}
    break;

  case 741:
#line 4044 "fgl.yacc"
    {
	print_befaft_field_2();
}
    break;

  case 742:
#line 4047 "fgl.yacc"
    {
		A4GL_add_event(-99,"");
		print_befaft_field_1("BEFORE_INP");
}
    break;

  case 743:
#line 4050 "fgl.yacc"
    {
	print_befaft_field_2();
}
    break;

  case 744:
#line 4053 "fgl.yacc"
    {
		A4GL_add_event(-12,"");
		print_befaft_field_1("DO_BEFORE_DELETE");
	}
    break;

  case 745:
#line 4056 "fgl.yacc"
    { print_befaft_field_2(); }
    break;

  case 746:
#line 4057 "fgl.yacc"
    { A4GL_add_event(-14,""); print_befaft_field_1("DO_BEFORE_INSERT"); }
    break;

  case 747:
#line 4057 "fgl.yacc"
    { print_befaft_field_2(); }
    break;

  case 748:
#line 4058 "fgl.yacc"
    { A4GL_add_event(-17,""); print_befaft_field_1("DO_BEFORE_INSERT_DELETE"); }
    break;

  case 749:
#line 4058 "fgl.yacc"
    { print_befaft_field_2(); }
    break;

  case 750:
#line 4059 "fgl.yacc"
    { A4GL_add_event(-18,""); print_befaft_field_1("DO_AFTER_INSERT_DELETE"); }
    break;

  case 751:
#line 4059 "fgl.yacc"
    { print_befaft_field_2(); }
    break;

  case 752:
#line 4060 "fgl.yacc"
    {
		A4GL_add_event(-13,"");
		print_befaft_field_1("DO_AFTER_DELETE");
	}
    break;

  case 753:
#line 4063 "fgl.yacc"
    { print_befaft_field_2(); }
    break;

  case 754:
#line 4064 "fgl.yacc"
    {
		A4GL_add_event(-15,"");
		print_befaft_field_1("DO_AFTER_INSERT");
	}
    break;

  case 755:
#line 4067 "fgl.yacc"
    { print_befaft_field_2(); }
    break;

  case 756:
#line 4075 "fgl.yacc"
    {
                        yyval.field_list=new_field_list();
                        yyval.field_list=append_field_to_list(yyval.field_list,yyvsp[0].field_entry);
        }
    break;

  case 757:
#line 4079 "fgl.yacc"
    {
                        yyval.field_list=append_field_to_list(yyvsp[-2].field_list,yyvsp[0].field_entry);
        }
    break;

  case 758:
#line 4085 "fgl.yacc"
    {
                        yyval.field_list=new_field_list();
                        yyval.field_list=append_field_to_list(yyval.field_list,yyvsp[0].field_entry);
        }
    break;

  case 759:
#line 4089 "fgl.yacc"
    {
                        yyval.field_list=append_field_to_list(yyvsp[-2].field_list,yyvsp[0].field_entry);
        }
    break;

  case 760:
#line 4094 "fgl.yacc"
    {
print_next_field(yyvsp[0].str);
}
    break;

  case 761:
#line 4099 "fgl.yacc"
    {
print_next_form_field(yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 762:
#line 4104 "fgl.yacc"
    {sprintf(yyval.str,"\"+\"");}
    break;

  case 763:
#line 4105 "fgl.yacc"
    {sprintf(yyval.str,"\"-\"");}
    break;

  case 764:
#line 4106 "fgl.yacc"
    {sprintf(yyval.str,field_name_as_char(yyvsp[0].field_entry));}
    break;

  case 765:
#line 4110 "fgl.yacc"
    {
print_input_1();
  A4GL_new_events();
}
    break;

  case 766:
#line 4114 "fgl.yacc"
    {
print_input_2(yyvsp[-2].str);
A4GL_drop_events();
}
    break;

  case 767:
#line 4123 "fgl.yacc"
    {
print_input(1,yyvsp[-2].str,yyvsp[-1].str,0,atoi(yyvsp[0].str));
strcpy(yyval.str,A4GL_get_formloop_str(0));
}
    break;

  case 768:
#line 4128 "fgl.yacc"
    {
print_input(0,yyvsp[-4].str,yyvsp[-1].str,field_name_list_as_char(yyvsp[-2].field_list),atoi(yyvsp[0].str));
strcpy(yyval.str,A4GL_get_formloop_str(0));
}
    break;

  case 769:
#line 4132 "fgl.yacc"
    {
curr_input_array_attribs.maxcount=0;
curr_input_array_attribs.count=0;
curr_input_array_attribs.allow_insert=1;
curr_input_array_attribs.allow_delete=1;
curr_input_array_attribs.curr_row_display=0;
inp_flags=0;}
    break;

  case 770:
#line 4139 "fgl.yacc"
    {
strcpy(yyval.str,print_input_array(fgl_add_scope(yyvsp[-8].str,0),yyvsp[-2].str,yyvsp[-7].str,yyvsp[-5].str,yyvsp[0].str,&curr_input_array_attribs));
}
    break;

  case 771:
#line 4148 "fgl.yacc"
    {
		print_scroll(field_name_list_as_char(yyvsp[-1].field_list),yyvsp[0].str);
	}
    break;

  case 772:
#line 4154 "fgl.yacc"
    {sprintf(yyval.str,"%s",yyvsp[0].str);}
    break;

  case 773:
#line 4155 "fgl.yacc"
    {sprintf(yyval.str,"-%s",yyvsp[0].str);}
    break;

  case 774:
#line 4156 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 775:
#line 4157 "fgl.yacc"
    {strcpy(yyval.str,"-1");}
    break;

  case 776:
#line 4158 "fgl.yacc"
    {
  		int a;
  		a=scan_variable(yyvsp[0].str)&15;
  		if (a!=1&&a!=2) {
    		a4gl_yyerror("Only INTEGER/SMALLINT variables may be here");
    		YYERROR;
    		/* error processing */;
  		}
  		sprintf(yyval.str,"%s",fgl_add_scope(yyvsp[0].str,0));
	}
    break;

  case 777:
#line 4168 "fgl.yacc"
    {
  		int a;
  		a=scan_variable(yyvsp[0].str)&15;
  		if (a!=1&&a!=2) {
    		a4gl_yyerror("Only INTEGER/SMALLINT variables may be here");
    		YYERROR;
    		/* error processing */;
  		}
  		sprintf(yyval.str,"%s",fgl_add_scope(yyvsp[0].str,0));
	}
    break;

  case 778:
#line 4182 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 780:
#line 4185 "fgl.yacc"
    {
	strcpy(yyval.str,"");
}
    break;

  case 781:
#line 4192 "fgl.yacc"
    { curr_input_array_attribs.curr_row_display=strdup(yyvsp[0].str); }
    break;

  case 782:
#line 4193 "fgl.yacc"
    { curr_input_array_attribs.count=strdup(yyvsp[0].str); }
    break;

  case 783:
#line 4194 "fgl.yacc"
    { curr_input_array_attribs.count=strdup(yyvsp[0].str); }
    break;

  case 784:
#line 4195 "fgl.yacc"
    { curr_input_array_attribs.maxcount=strdup(yyvsp[0].str); }
    break;

  case 785:
#line 4196 "fgl.yacc"
    { curr_input_array_attribs.maxcount=strdup(yyvsp[0].str); }
    break;

  case 786:
#line 4197 "fgl.yacc"
    { curr_input_array_attribs.allow_insert=1; }
    break;

  case 787:
#line 4198 "fgl.yacc"
    { curr_input_array_attribs.allow_insert=0; }
    break;

  case 788:
#line 4199 "fgl.yacc"
    { curr_input_array_attribs.allow_delete=1; }
    break;

  case 789:
#line 4200 "fgl.yacc"
    { curr_input_array_attribs.allow_delete=0; }
    break;

  case 790:
#line 4205 "fgl.yacc"
    {iskey=1;}
    break;

  case 791:
#line 4205 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);iskey=0;}
    break;

  case 792:
#line 4207 "fgl.yacc"
    {strcpy(yyval.str,"->ANY");}
    break;

  case 793:
#line 4210 "fgl.yacc"
    {iskey=1;}
    break;

  case 794:
#line 4210 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);iskey=0;}
    break;

  case 795:
#line 4212 "fgl.yacc"
    {sprintf(yyval.str,"A4GL_key_val(\"%s\")",yyvsp[0].str);iskey=0;}
    break;

  case 796:
#line 4216 "fgl.yacc"
    {sprintf(yyval.str,"A4GL_key_val(\"%s\")",yyvsp[0].str);iskey=0;}
    break;

  case 797:
#line 4219 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 798:
#line 4220 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[-1].str);}
    break;

  case 800:
#line 4223 "fgl.yacc"
    {
	sprintf(yyval.str,"%s||%s",yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 806:
#line 4235 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 807:
#line 4236 "fgl.yacc"
    {strcpy(yyval.str,"escape");}
    break;

  case 808:
#line 4237 "fgl.yacc"
    {strcpy(yyval.str,"up");}
    break;

  case 809:
#line 4238 "fgl.yacc"
    {strcpy(yyval.str,"help");}
    break;

  case 810:
#line 4239 "fgl.yacc"
    {strcpy(yyval.str,"down");}
    break;

  case 811:
#line 4240 "fgl.yacc"
    {strcpy(yyval.str,"return");}
    break;

  case 812:
#line 4241 "fgl.yacc"
    {strcpy(yyval.str,"delete");}
    break;

  case 813:
#line 4242 "fgl.yacc"
    {strcpy(yyval.str,"insert");}
    break;

  case 814:
#line 4243 "fgl.yacc"
    {strcpy(yyval.str,"tab");}
    break;

  case 815:
#line 4244 "fgl.yacc"
    {strcpy(yyval.str,"left");}
    break;

  case 816:
#line 4245 "fgl.yacc"
    {strcpy(yyval.str,"right");}
    break;

  case 817:
#line 4246 "fgl.yacc"
    {strcpy(yyval.str,"nextpage");}
    break;

  case 818:
#line 4247 "fgl.yacc"
    {strcpy(yyval.str,"prevpage");}
    break;

  case 819:
#line 4248 "fgl.yacc"
    { rm_quotes(yyvsp[0].str); strcpy(yyval.str,yyvsp[0].str); }
    break;

  case 820:
#line 4252 "fgl.yacc"
    {
char buff[256];
A4GL_debug("Label : %s\n",get_idents(0));
strcpy(buff,get_idents(0));
A4GL_convlower(buff);
print_label(buff);
}
    break;

  case 821:
#line 4270 "fgl.yacc"
    {chk4var=1;}
    break;

  case 822:
#line 4270 "fgl.yacc"
    {chk4var=0;
expand_obind();
A4GL_lex_printcomment("/*let3*/\n");}
    break;

  case 823:
#line 4273 "fgl.yacc"
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

  case 824:
#line 4297 "fgl.yacc"
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

  case 826:
#line 4315 "fgl.yacc"
    {
		if (!print_linked_cmd('S',yyvsp[0].str)) a4gl_yyerror("Not a linked variable");
	}
    break;

  case 827:
#line 4321 "fgl.yacc"
    {
		 if (!print_linked_cmd('D',yyvsp[0].str)) a4gl_yyerror("Not a linked variable");
	}
    break;

  case 828:
#line 4327 "fgl.yacc"
    {
		 if (!print_linked_cmd('U',yyvsp[0].str)) a4gl_yyerror("Not a linked variable");
}
    break;

  case 829:
#line 4333 "fgl.yacc"
    {
int vtype;
int a;
for (a=0;a<get_bind_cnt('o');a++) {
	vtype=scan_variable(get_bind_varname('o',a));
	if (vtype!=11&&vtype!=12) {
		a4gl_yyerror("Only Byte & Text may be located...");
		YYERROR;
	}
	print_locate('M',get_bind_varname('o',a),"0");
}
}
    break;

  case 830:
#line 4345 "fgl.yacc"
    {
int vtype;
int a;
for (a=0;a<get_bind_cnt('o');a++) {
	vtype=scan_variable(get_bind_varname('o',a));
	if (vtype!=11&&vtype!=12) {
		a4gl_yyerror("Only Byte & Text may be located...");
		YYERROR;
	}
	print_locate('F',get_bind_varname('o',a),yyvsp[0].str);
}
}
    break;

  case 831:
#line 4370 "fgl.yacc"
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

  case 834:
#line 4386 "fgl.yacc"
    {
	}
    break;

  case 843:
#line 4411 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 847:
#line 4419 "fgl.yacc"
    {
		print_at_termination(yyvsp[0].str);
	}
    break;

  case 862:
#line 4445 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 863:
#line 4446 "fgl.yacc"
    {
strcpy(yyval.str,"static ");
}
    break;

  case 864:
#line 4454 "fgl.yacc"
    {
  clr_variable(); lastlineno=yylineno;
  clr_function_constants (); 
}
    break;

  case 865:
#line 4459 "fgl.yacc"
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

  case 866:
#line 4475 "fgl.yacc"
    {
  A4GL_lex_printcomment("/* new function %s parameters*/\n",yyvsp[-1].str);
  push_blockcommand("FUNC");
  A4GL_lex_printcomment("/* define section */\n");
}
    break;

  case 867:
#line 4481 "fgl.yacc"
    {
  int c;
  A4GL_lex_printcomment("/*end of define section */\n");
	print_variables();
  c=print_param('f');
  printPushFunction();
  print_func_args(c);
}
    break;

  case 869:
#line 4496 "fgl.yacc"
    {
    printPopFunction();
    print_func_defret0();
    pop_blockcommand("FUNC");
    print_func_end();
    clr_function_constants ();
    A4GL_lex_printcomment("/*end function*/\n");
  }
    break;

  case 870:
#line 4509 "fgl.yacc"
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

  case 871:
#line 4519 "fgl.yacc"
    {
	print_variables();
    printDeclareFunctionStack("MAIN");
    print_fgllib_start(hdr_dbname);
    printInitFunctionStack();
    printPushFunction();
  }
    break;

  case 872:
#line 4526 "fgl.yacc"
    {
pop_blockcommand("MAIN");
print_main_end();
A4GL_lex_printcomment("/*end main */\n");}
    break;

  case 873:
#line 4533 "fgl.yacc"
    {
    printPopFunction();
    print_return(atoi(yyvsp[0].str));
  }
    break;

  case 874:
#line 4539 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 875:
#line 4539 "fgl.yacc"
    {
A4GL_lex_printcomment("/* Got expr list */");
sprintf(yyval.str,"%s",yyvsp[0].str);}
    break;

  case 876:
#line 4544 "fgl.yacc"
    {
					open_db(yyvsp[0].str);
					strcpy(hdr_dbname,yyvsp[0].str);
					lastlineno=yylineno;
					is_schema=0;
			}
    break;

  case 877:
#line 4550 "fgl.yacc"
    {
					open_db(yyvsp[0].str);
					strcpy(hdr_dbname,yyvsp[0].str);
					lastlineno=yylineno;
					is_schema=1;
			}
    break;

  case 878:
#line 4558 "fgl.yacc"
    {
}
    break;

  case 882:
#line 4570 "fgl.yacc"
    {
strcpy(curr_func,"[Globals]");
set_current_variable_scope('g');
A4GL_lex_printcomment("/* start of globals */\n");
}
    break;

  case 884:
#line 4578 "fgl.yacc"
    {
 A4GL_lex_printcomment("/* end of globals */");
	A4GL_debug("end of globals\n");
	lastlineno=yylineno;
	set_current_variable_scope('m');
}
    break;

  case 885:
#line 4584 "fgl.yacc"
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

  case 888:
#line 4600 "fgl.yacc"
    {
  addmap("Define Member Function",curr_func,"MODULE",yylineno,infilename);
}
    break;

  case 889:
#line 4604 "fgl.yacc"
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

  case 890:
#line 4617 "fgl.yacc"
    {
	print_variables();
  A4GL_lex_printcomment("/*end of define section */\n");
  print_param('f');
  printPushFunction();
  print_func_args(atoi(yyvsp[-3].str));
}
    break;

  case 892:
#line 4635 "fgl.yacc"
    {
	start_state("menu",1);
   	menu_cnt=npush_menu();
   	menu_cmd_cnt[menu_cnt]=1;
   	push_blockcommand("MENU");
        menu_blk[menu_cnt]=get_blk_no();
	do_print_menu_1();
	}
    break;

  case 893:
#line 4643 "fgl.yacc"
    {
	start_state("menu",0);
	}
    break;

  case 894:
#line 4649 "fgl.yacc"
    {
   print_end_menu_1(menu_blk[menu_cnt]);
   add_continue_blockcommand ("MENU");
print_end_menu_2(menu_blk[menu_cnt]);
   pop_blockcommand("MENU");
   pop_menu();
}
    break;

  case 895:
#line 4660 "fgl.yacc"
    {
	 A4GL_lex_printcomment("/* Block%d_m2 (Before menu) */",menu_cnt);
		print_menu_block(menu_blk[menu_cnt],-2) ;
                  }
    break;

  case 896:
#line 4664 "fgl.yacc"
    {
		do_print_menu_block_end();
	}
    break;

  case 897:
#line 4671 "fgl.yacc"
    {
A4GL_debug("Menu=%d menu cnt=%d",menu_cnt,menu_cmd_cnt[menu_cnt]);
		push_command(menu_cnt,menu_cmd_cnt[menu_cnt],yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);
	 A4GL_lex_printcomment("/* Block%d_%d */",menu_cnt,menu_cmd_cnt[menu_cnt]-1);
		print_menu_block(menu_blk[menu_cnt],menu_cmd_cnt[menu_cnt]-1);
		menu_cmd_cnt[menu_cnt]++;
		}
    break;

  case 898:
#line 4678 "fgl.yacc"
    {
		do_print_menu_block_end();
}
    break;

  case 899:
#line 4684 "fgl.yacc"
    {
		push_command(menu_cnt,menu_cmd_cnt[menu_cnt],yyvsp[-1].str,"\"\"","\"\"",0);
		print_menu_block(menu_blk[menu_cnt],menu_cmd_cnt[menu_cnt]-1);
		menu_cmd_cnt[menu_cnt]++;
		}
    break;

  case 900:
#line 4689 "fgl.yacc"
    {
		do_print_menu_block_end();
}
    break;

  case 903:
#line 4696 "fgl.yacc"
    {strcpy(yyval.str,"\"EMPTY\"");}
    break;

  case 904:
#line 4697 "fgl.yacc"
    {sprintf(yyval.str,"\"%s\"",yyvsp[0].str);}
    break;

  case 905:
#line 4699 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str); }
    break;

  case 906:
#line 4700 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 907:
#line 4703 "fgl.yacc"
    {strcpy(yyval.str,"\"\"");}
    break;

  case 908:
#line 4704 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 909:
#line 4705 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 910:
#line 4707 "fgl.yacc"
    {
	print_option_op('N',yyvsp[0].str,menu_blk[menu_cnt]);
}
    break;

  case 911:
#line 4712 "fgl.yacc"
    {
	print_option_op('S',yyvsp[0].str,menu_blk[menu_cnt]);
}
    break;

  case 912:
#line 4717 "fgl.yacc"
    {
	print_option_op('H',yyvsp[0].str,menu_blk[menu_cnt]);
}
    break;

  case 913:
#line 4724 "fgl.yacc"
    {sprintf(yyval.str,"MENU_ALL");}
    break;

  case 917:
#line 4731 "fgl.yacc"
    {sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 918:
#line 4733 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);  
push_menu_title(yyval.str);}
    break;

  case 919:
#line 4735 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str); 
push_menu_title(yyval.str);}
    break;

  case 920:
#line 4743 "fgl.yacc"
    {
                strcpy(menuhandler,yyvsp[0].str);
	sprintf(curr_func,"%s",yyvsp[0].str); 
	print_gtk_menuhandler_1(yyvsp[0].str);
                push_blockcommand("MENUH");
}
    break;

  case 921:
#line 4749 "fgl.yacc"
    {
		print_variables();
        }
    break;

  case 922:
#line 4753 "fgl.yacc"
    {
                        pop_blockcommand("MENUH");
			print_gtk_menuhandler_end();
                }
    break;

  case 925:
#line 4765 "fgl.yacc"
    {
		print_gtk_menuhandler_bsm();
                push_blockcommand("BSM");
        }
    break;

  case 926:
#line 4768 "fgl.yacc"
    {
                pop_blockcommand("BSM");
		print_gtk_menuhandler_bsm_end();
        }
    break;

  case 927:
#line 4772 "fgl.yacc"
    {
		print_gtk_menuhandler_on(yyvsp[0].str);
                push_blockcommand("ON");
        }
    break;

  case 928:
#line 4775 "fgl.yacc"
    {
                pop_blockcommand("ON");
		print_gtk_menuhandler_on_end();
}
    break;

  case 930:
#line 4784 "fgl.yacc"
    {
		print_message(0,"0",0,message_cnt);
	   }
    break;

  case 931:
#line 4787 "fgl.yacc"
    { 
		print_message(0,yyvsp[-1].str,atoi(yyvsp[0].str),message_cnt);
	  }
    break;

  case 932:
#line 4790 "fgl.yacc"
    { 
		print_message(0,"0",atoi(yyvsp[0].str),message_cnt);
	  }
    break;

  case 939:
#line 4806 "fgl.yacc"
    {
		strcpy(yyval.str,yyvsp[0].str);
		message_cnt=atoi(yyvsp[0].str);
		}
    break;

  case 940:
#line 4811 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 941:
#line 4811 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 942:
#line 4814 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 943:
#line 4842 "fgl.yacc"
    {
char buff[256];
char buff2[256];
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

  case 945:
#line 4899 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 947:
#line 4906 "fgl.yacc"
    { 
         sprintf (yyval.str, "%s.%s", yyvsp[-1].str, yyvsp[0].str); 
         A4GL_lex_printcomment("/* record building -> %s */\n",yyval.str);
         }
    break;

  case 948:
#line 4910 "fgl.yacc"
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

  case 949:
#line 4953 "fgl.yacc"
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

  case 953:
#line 5001 "fgl.yacc"
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

  case 954:
#line 5015 "fgl.yacc"
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

  case 959:
#line 5039 "fgl.yacc"
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

  case 960:
#line 5103 "fgl.yacc"
    {
	 A4GL_debug("---> Subscript or substring");
		strcpy(yyval.str,yyvsp[-1].str);
	}
    break;

  case 961:
#line 5108 "fgl.yacc"
    {
	 A4GL_debug("---> Subscript & substring");
		sprintf(yyval.str,"%s:%s",yyvsp[-4].str,yyvsp[-1].str);
	}
    break;

  case 962:
#line 5116 "fgl.yacc"
    {
A4GL_debug("List element");
  sprintf (yyval.str, "%s", yyvsp[0].str);
}
    break;

  case 963:
#line 5121 "fgl.yacc"
    {
A4GL_debug("List element continues");
  sprintf (yyval.str, "%s,%s", yyvsp[-2].str, yyvsp[0].str); 
}
    break;

  case 964:
#line 5129 "fgl.yacc"
    {
  sprintf (yyval.str, "%s", yyvsp[0].str);
}
    break;

  case 965:
#line 5135 "fgl.yacc"
    {
char buff[256];
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

  case 966:
#line 5167 "fgl.yacc"
    {
	 A4GL_debug("Array..");
}
    break;

  case 967:
#line 5170 "fgl.yacc"
    { sprintf (yyval.str, "%s.%s", yyvsp[-2].str, yyvsp[0].str); }
    break;

  case 968:
#line 5172 "fgl.yacc"
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

  case 969:
#line 5213 "fgl.yacc"
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

  case 974:
#line 5266 "fgl.yacc"
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

  case 975:
#line 5318 "fgl.yacc"
    {
		start_bind('f',0);
		/*start_bind('O',0);*/
		strcpy(yyval.str,"0");
		}
    break;

  case 977:
#line 5327 "fgl.yacc"
    {
				start_bind('f',yyvsp[0].str);
				start_bind('O',0);
				sprintf(yyval.str,"1");
			}
    break;

  case 978:
#line 5332 "fgl.yacc"
    {
				int c;
				c=add_bind('f',yyvsp[0].str);
				/*c=add_bind('O',$<str>3); */
				sprintf(yyval.str,"%d",c); 
			}
    break;

  case 979:
#line 5343 "fgl.yacc"
    {
A4GL_lex_printcomment("/*STarted bind %s*/\n",yyvsp[0].str);
start_bind('i',yyvsp[0].str);
A4GL_lex_printcomment("/*STarted bind 2*/\n");
strcpy(yyval.str,"");
}
    break;

  case 980:
#line 5350 "fgl.yacc"
    {
A4GL_lex_printcomment("/* Added */\n");
add_bind('i',yyvsp[0].str);
strcpy(yyval.str,"");
}
    break;

  case 982:
#line 5358 "fgl.yacc"
    {sprintf(yyval.str,"%s.%s",yyvsp[-2].str,yyvsp[-1].str);}
    break;

  case 983:
#line 5361 "fgl.yacc"
    {A4GL_lex_printcomment("/* Variable */\n");}
    break;

  case 984:
#line 5362 "fgl.yacc"
    { A4GL_debug("Got an ibind thru..."); sprintf(yyval.str,"%s\n%s",yyvsp[-2].str,yyvsp[0].str); }
    break;

  case 986:
#line 5364 "fgl.yacc"
    {sprintf(yyval.str,"\"%s\"",yyvsp[0].str);}
    break;

  case 987:
#line 5365 "fgl.yacc"
    {sprintf(yyval.str,"\"%s\"",yyvsp[0].str);}
    break;

  case 988:
#line 5368 "fgl.yacc"
    {
start_bind('o',yyvsp[0].str);
}
    break;

  case 989:
#line 5371 "fgl.yacc"
    {
add_bind('o',yyvsp[0].str);
strcpy(yyval.str,"");
}
    break;

  case 990:
#line 5377 "fgl.yacc"
    {
	addmap("OBIND",yyvsp[0].str,curr_func,yylineno,infilename);
	}
    break;

  case 991:
#line 5380 "fgl.yacc"
    { A4GL_debug("Got an obind thru..."); sprintf(yyval.str,"%s\n%s",yyvsp[-2].str,yyvsp[0].str); }
    break;

  case 992:
#line 5384 "fgl.yacc"
    {
A4GL_lex_printcomment("/* start obind with  %s*/\n",yyvsp[0].str);
A4GL_debug("obind_var_let_list ---> %s\n",yyvsp[0].str);
start_bind('o',yyvsp[0].str);
}
    break;

  case 993:
#line 5389 "fgl.yacc"
    {
A4GL_lex_printcomment("/* add to obind %s */\n",yyvsp[0].str);
add_bind('o',yyvsp[0].str);
A4GL_debug("obind_var_let_list ---> %s\n",yyvsp[0].str);
strcpy(yyval.str,"");
}
    break;

  case 994:
#line 5397 "fgl.yacc"
    {
A4GL_lex_printcomment("/* Read variable %s*/\n",yyvsp[0].str);
}
    break;

  case 995:
#line 5402 "fgl.yacc"
    {
    A4GL_lex_printcomment("/* use_arr_var */\n");
    start_arr_bind('o',yyvsp[0].str);
    A4GL_lex_printcomment("/* use_arr_var complete */\n");
}
    break;

  case 996:
#line 5409 "fgl.yacc"
    {
		start_bind('O',yyvsp[0].str);
	}
    break;

  case 997:
#line 5411 "fgl.yacc"
    {
               add_bind('O',yyvsp[0].str);
               strcpy(yyval.str,"");
	}
    break;

  case 1002:
#line 5439 "fgl.yacc"
    {
A4GL_lex_printcomment("/*STarted bind %s*/\n",yyvsp[0].str);
start_bind('N',yyvsp[0].str);
A4GL_lex_printcomment("/*STarted bind 2*/\n");
strcpy(yyval.str,"");
}
    break;

  case 1003:
#line 5446 "fgl.yacc"
    {
A4GL_lex_printcomment("/* Added */\n");
add_bind('N',yyvsp[0].str);
strcpy(yyval.str,"");
}
    break;

  case 1004:
#line 5453 "fgl.yacc"
    {
		strcpy(yyval.str,yyvsp[0].str);
	}
    break;

  case 1005:
#line 5456 "fgl.yacc"
    {
			sprintf(yyval.str,"%s\n%s",yyvsp[-2].str,yyvsp[0].str);
		}
    break;

  case 1006:
#line 5470 "fgl.yacc"
    {
form_attrib.iswindow=1;
print_open_window(yyvsp[-5].str,yyvsp[-1].str);
sprintf(yyval.str,"open window");
}
    break;

  case 1011:
#line 5487 "fgl.yacc"
    {
	print_niy("OPEN_STATUSBOX");
}
    break;

  case 1012:
#line 5492 "fgl.yacc"
    {
addmap("Call Formhandler",yyvsp[0].str,curr_func,yylineno,infilename); 
}
    break;

  case 1013:
#line 5498 "fgl.yacc"
    {
		print_open_form(yyvsp[0].str,yyvsp[-1].str,yyvsp[-1].str);
		}
    break;

  case 1015:
#line 5505 "fgl.yacc"
    { form_attrib.iswindow=0;strcpy(yyval.str,"A4GL_open_form(%s);"); }
    break;

  case 1016:
#line 5510 "fgl.yacc"
    {sprintf(yyval.str,"A4GL_open_gui_form(&%%s,%%s,%s,%s,%s,hnd_e_%s,hnd_c_%s);",yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[0].str,yyvsp[0].str);}
    break;

  case 1017:
#line 5513 "fgl.yacc"
    {strcpy(yyval.str,"0,0");}
    break;

  case 1018:
#line 5514 "fgl.yacc"
    {sprintf(yyval.str,"%s,2",yyvsp[-5].str);}
    break;

  case 1019:
#line 5517 "fgl.yacc"
    {strcpy(yyval.str,"\"\"");}
    break;

  case 1020:
#line 5518 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1021:
#line 5521 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 1022:
#line 5522 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 1023:
#line 5527 "fgl.yacc"
    {
print_open_session(yyvsp[-3].str,yyvsp[-1].str,yyvsp[0].str);

}
    break;

  case 1024:
#line 5534 "fgl.yacc"
    {
	print_open_cursor(yyvsp[0].str,"0");
}
    break;

  case 1025:
#line 5537 "fgl.yacc"
    {
	print_open_cursor(yyvsp[-3].str,yyvsp[0].str); /* CHANGED from $<str>4 */
}
    break;

  case 1026:
#line 5543 "fgl.yacc"
    {sprintf(yyval.str,"0,0");}
    break;

  case 1027:
#line 5545 "fgl.yacc"
    {sprintf(yyval.str,"%s, %s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1028:
#line 5547 "fgl.yacc"
    {sprintf(yyval.str,"%s, %s",yyvsp[-3].str,yyvsp[0].str);}
    break;

  case 1029:
#line 5549 "fgl.yacc"
    {sprintf(yyval.str,"%s, %s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1030:
#line 5552 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 1031:
#line 5552 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 1032:
#line 5553 "fgl.yacc"
    {strcpy(yyval.str,"2");}
    break;

  case 1033:
#line 5558 "fgl.yacc"
    {
	print_open_session(yyvsp[-1].str,yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 1034:
#line 5566 "fgl.yacc"
    {strcpy(yyval.str,"\"default_conn\"");}
    break;

  case 1035:
#line 5567 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1036:
#line 5572 "fgl.yacc"
    {sprintf(yyval.str,"0,0");}
    break;

  case 1037:
#line 5574 "fgl.yacc"
    {sprintf(yyval.str,"%s, %s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1038:
#line 5576 "fgl.yacc"
    {sprintf(yyval.str,"%s, %s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1042:
#line 5594 "fgl.yacc"
    { print_options('C',yyvsp[0].str); }
    break;

  case 1043:
#line 5595 "fgl.yacc"
    { print_options('E',yyvsp[0].str); }
    break;

  case 1044:
#line 5596 "fgl.yacc"
    { print_options('F',yyvsp[0].str); }
    break;

  case 1045:
#line 5597 "fgl.yacc"
    { print_options('M',yyvsp[0].str); }
    break;

  case 1046:
#line 5598 "fgl.yacc"
    { print_options('m',yyvsp[0].str); }
    break;

  case 1047:
#line 5599 "fgl.yacc"
    { print_options('P',yyvsp[0].str); }
    break;

  case 1048:
#line 5600 "fgl.yacc"
    { print_options('A',yyvsp[0].str); iskey=0; }
    break;

  case 1049:
#line 5601 "fgl.yacc"
    { print_options('D',yyvsp[0].str); iskey=0; }
    break;

  case 1050:
#line 5602 "fgl.yacc"
    { print_options('I',yyvsp[0].str); iskey=0; }
    break;

  case 1051:
#line 5603 "fgl.yacc"
    { print_options('N',yyvsp[0].str); }
    break;

  case 1052:
#line 5604 "fgl.yacc"
    { print_options('p',yyvsp[0].str); iskey=0; }
    break;

  case 1053:
#line 5605 "fgl.yacc"
    { print_options('H',yyvsp[0].str); }
    break;

  case 1054:
#line 5606 "fgl.yacc"
    { print_set_helpfile(yyvsp[0].str); }
    break;

  case 1055:
#line 5607 "fgl.yacc"
    { print_set_langfile(yyvsp[0].str); }
    break;

  case 1056:
#line 5608 "fgl.yacc"
    { print_options('Z',"1"); }
    break;

  case 1057:
#line 5609 "fgl.yacc"
    { print_options('Z',"2"); }
    break;

  case 1058:
#line 5610 "fgl.yacc"
    { print_options('Y',"1"); }
    break;

  case 1059:
#line 5611 "fgl.yacc"
    { print_options('Y',"2"); }
    break;

  case 1060:
#line 5612 "fgl.yacc"
    { print_options('d',yyvsp[0].str);print_options('Z',"0"); }
    break;

  case 1061:
#line 5613 "fgl.yacc"
    { print_options('i',yyvsp[0].str); print_options('Y',"0");}
    break;

  case 1062:
#line 5614 "fgl.yacc"
    { print_options('W',"1"); }
    break;

  case 1063:
#line 5615 "fgl.yacc"
    { print_options('W',"0"); }
    break;

  case 1064:
#line 5616 "fgl.yacc"
    { print_options('f',"1"); }
    break;

  case 1065:
#line 5617 "fgl.yacc"
    { print_options('f',"0"); }
    break;

  case 1066:
#line 5618 "fgl.yacc"
    { print_options('S',"1"); }
    break;

  case 1067:
#line 5619 "fgl.yacc"
    { print_options('S',"0"); }
    break;

  case 1068:
#line 5634 "fgl.yacc"
    {
	print_prepare(yyvsp[-2].str,yyvsp[0].str);
	addmap("Prepare",yyvsp[-2].str,curr_func,yylineno,infilename);
	print_undo_use(yyvsp[-4].str);
}
    break;

  case 1071:
#line 5643 "fgl.yacc"
    {
		print_execute(yyvsp[0].str,0);
		addmap("Execute",yyvsp[0].str,curr_func,yylineno,infilename);
		}
    break;

  case 1072:
#line 5647 "fgl.yacc"
    {
		addmap("Execute",yyvsp[-2].str,curr_func,yylineno,infilename);
		print_execute(yyvsp[-2].str,1);
	}
    break;

  case 1073:
#line 5651 "fgl.yacc"
    {
		addmap("Execute",yyvsp[-2].str,curr_func,yylineno,infilename);
		print_execute(yyvsp[-2].str,2);
	}
    break;

  case 1074:
#line 5655 "fgl.yacc"
    {
		addmap("Execute",yyvsp[-4].str,curr_func,yylineno,infilename);
		print_execute(yyvsp[-4].str,3);
	}
    break;

  case 1075:
#line 5659 "fgl.yacc"
    {
		print_execute_immediate(yyvsp[0].str);
	}
    break;

  case 1077:
#line 5679 "fgl.yacc"
    {
                push_blockcommand("PROMPT");
	A4GL_new_events();
	print_prompt_1(yyvsp[-6].str,yyvsp[-4].str,yyvsp[-1].str,yyvsp[0].str,atoi(yyvsp[-2].str)) ;
}
    break;

  case 1078:
#line 5684 "fgl.yacc"
    {
		if (strcmp(yyvsp[-6].str,"1")==0) {
			print_prompt_forchar();
                }
		add_continue_blockcommand ("PROMPT");
		print_prompt_end(yyvsp[-5].str);
                pop_blockcommand("PROMPT");
		A4GL_drop_events();
                A4GL_lex_printcomment("/* END OF PROMPT */");
                }
    break;

  case 1079:
#line 5697 "fgl.yacc"
    {sprintf(yyval.str,"0");}
    break;

  case 1080:
#line 5698 "fgl.yacc"
    {sprintf(yyval.str,yyvsp[0].str);}
    break;

  case 1081:
#line 5702 "fgl.yacc"
    {
		print_niy("GUI PROMPT");
	}
    break;

  case 1082:
#line 5707 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 1083:
#line 5708 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 1084:
#line 5712 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1088:
#line 5718 "fgl.yacc"
    {
	A4GL_add_onkey_key(yyvsp[0].str);
	print_onkey_1(yyvsp[0].str);
}
    break;

  case 1089:
#line 5721 "fgl.yacc"
    {
	print_onkey_2_prompt();
}
    break;

  case 1091:
#line 5736 "fgl.yacc"
    {
		start_bind('i',0);
		}
    break;

  case 1092:
#line 5740 "fgl.yacc"
    {
		print_put(yyvsp[-2].str,yyvsp[0].str);
	}
    break;

  case 1093:
#line 5746 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1094:
#line 5747 "fgl.yacc"
    { strcpy(yyval.str,yyvsp[0].str);
A4GL_debug("putlist = %s\n",yyval.str);
}
    break;

  case 1095:
#line 5752 "fgl.yacc"
    {push_gen(PUTVAL,yyvsp[0].str);}
    break;

  case 1096:
#line 5753 "fgl.yacc"
    {push_gen(PUTVAL,yyvsp[0].str); sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1097:
#line 5756 "fgl.yacc"
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

  case 1099:
#line 5783 "fgl.yacc"
    {
			addmap("Start Report",yyvsp[-2].str,curr_func,yylineno,infilename);
			print_start_report("P","acl_getenv(\"DBPRINT\")",yyvsp[-2].str);
			}
    break;

  case 1100:
#line 5787 "fgl.yacc"
    {
			addmap("Start Report",yyvsp[-3].str,curr_func,yylineno,infilename);
			print_start_report("F",yyvsp[-1].str,yyvsp[-3].str);
			}
    break;

  case 1101:
#line 5791 "fgl.yacc"
    {
			addmap("Start Report",yyvsp[-3].str,curr_func,yylineno,infilename);
			print_start_report("P",yyvsp[-1].str,yyvsp[-3].str);
			}
    break;

  case 1102:
#line 5795 "fgl.yacc"
    {
			addmap("Start Report",yyvsp[-1].str,curr_func,yylineno,infilename);
			print_start_report("","\"\"",yyvsp[-1].str);
			}
    break;

  case 1103:
#line 5802 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 1104:
#line 5803 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 1110:
#line 5815 "fgl.yacc"
    {
		addmap("Output to report",yyvsp[-5].str,curr_func,yylineno,infilename);
		print_output_to_report(yyvsp[-5].str,yyvsp[-1].str); 
		}
    break;

  case 1111:
#line 5821 "fgl.yacc"
    {
		addmap("Finish Report",yyvsp[0].str,curr_func,yylineno,infilename);
		print_finish_report(yyvsp[0].str);
		}
    break;

  case 1112:
#line 5829 "fgl.yacc"
    {
		addmap("Finish Report",yyvsp[0].str,curr_func,yylineno,infilename);
		print_terminate_report(yyvsp[0].str);
}
    break;

  case 1113:
#line 5835 "fgl.yacc"
    { strcpy(yyval.str,yyvsp[0].str); }
    break;

  case 1114:
#line 5837 "fgl.yacc"
    {
	print_format_every_row();
}
    break;

  case 1118:
#line 5847 "fgl.yacc"
    { push_report_block("FIRST",'P');}
    break;

  case 1119:
#line 5847 "fgl.yacc"
    {
		rep_struct.lines_in_first_header=if_print_stack[0][0];
		pdf_rep_struct.lines_in_first_header=if_print_stack[0][0];
		print_rep_ret(0,1);
		}
    break;

  case 1120:
#line 5852 "fgl.yacc"
    { 
		push_report_block("TRAILER",'T');
		if_print_stack[0][0]=0;
		if_print_stack[0][1]=0;
	}
    break;

  case 1121:
#line 5856 "fgl.yacc"
    {
		rep_struct.lines_in_trailer=if_print_stack[0][0];
		pdf_rep_struct.lines_in_trailer=if_print_stack[0][0];
		print_rep_ret(0,1);
	}
    break;

  case 1122:
#line 5861 "fgl.yacc"
    { push_report_block("HEADER",'p');}
    break;

  case 1123:
#line 5861 "fgl.yacc"
    {
		rep_struct.lines_in_header=if_print_stack[0][0];
		pdf_rep_struct.lines_in_header=if_print_stack[0][0];
		print_rep_ret(0,1);}
    break;

  case 1124:
#line 5865 "fgl.yacc"
    { push_report_block("EVERY",'E');}
    break;

  case 1125:
#line 5865 "fgl.yacc"
    {print_rep_ret(0,1);}
    break;

  case 1126:
#line 5866 "fgl.yacc"
    { push_report_block("LAST",'L');}
    break;

  case 1127:
#line 5866 "fgl.yacc"
    {print_rep_ret(0,1);}
    break;

  case 1128:
#line 5867 "fgl.yacc"
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

  case 1129:
#line 5880 "fgl.yacc"
    {print_rep_ret(0,1);}
    break;

  case 1130:
#line 5881 "fgl.yacc"
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

  case 1131:
#line 5897 "fgl.yacc"
    {print_rep_ret(0,1);}
    break;

  case 1138:
#line 5909 "fgl.yacc"
    {start_state("skip",1);}
    break;

  case 1139:
#line 5909 "fgl.yacc"
    {
	print_need_lines();
	start_state("skip",0);
}
    break;

  case 1140:
#line 5915 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 1141:
#line 5915 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 1142:
#line 5918 "fgl.yacc"
    {start_state("KWLINE",1);}
    break;

  case 1143:
#line 5918 "fgl.yacc"
    {
double n;
char buff[256];
strcpy(buff,yyvsp[0].str);
n=atof(yyvsp[-2].str);
if (buff[0]=='1') {
	print_skip_lines(n);
	if (if_print_stack_cnt==0) if_print_section[0]=0;
	if (get_curr_report_stack_whytype_1()=='T') {
		if_print_stack[if_print_stack_cnt][if_print_section[if_print_stack_cnt]]+=(int)n;
	}
} else {
	if (rep_type!=REP_TYPE_PDF) { a4gl_yyerror("SKIP BY is only in PDF reports"); YYERROR; } print_skip_by(n);
}
start_state("KWLINE",0); 
}
    break;

  case 1144:
#line 5934 "fgl.yacc"
    { print_skip_top(); }
    break;

  case 1145:
#line 5935 "fgl.yacc"
    { print_niy("FONT SIZE"); }
    break;

  case 1146:
#line 5936 "fgl.yacc"
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

  case 1147:
#line 5945 "fgl.yacc"
    {
			if (rep_type!=REP_TYPE_PDF) {
				a4gl_yyerror("SKIP TO is only in PDF reports");
				YYERROR;
			}
			print_skip_to(yyvsp[0].str);
		}
    break;

  case 1148:
#line 5957 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1154:
#line 5968 "fgl.yacc"
    {
	print_niy("PRINT AT...");
}
    break;

  case 1155:
#line 5973 "fgl.yacc"
    {doing_a_print=1;}
    break;

  case 1156:
#line 5973 "fgl.yacc"
    {
	char wt;
	doing_a_print=0;
	print_report_print(0,yyvsp[0].str,0);
	wt=get_curr_report_stack_whytype_1();
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
		if (get_curr_report_stack_whytype_1()=='T') {
			if_print_stack[if_print_stack_cnt][if_print_section[if_print_stack_cnt]]+=1;
		}
	}
}
    break;

  case 1157:
#line 5994 "fgl.yacc"
    { 
	print_report_print_file(yyvsp[-1].str,yyvsp[0].str);
}
    break;

  case 1158:
#line 5999 "fgl.yacc"
    { 
	print_report_print_img(yyvsp[-1].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 1159:
#line 6005 "fgl.yacc"
    { strcpy(yyval.str,A4GL_get_default_scaling());}
    break;

  case 1160:
#line 6006 "fgl.yacc"
    { strcpy(yyval.str,yyvsp[0].str); strcat(yyval.str,yyvsp[0].str); }
    break;

  case 1161:
#line 6007 "fgl.yacc"
    {sprintf(yyval.str,"%s %s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1162:
#line 6011 "fgl.yacc"
    {strcpy(yyval.str,"tiff");}
    break;

  case 1163:
#line 6012 "fgl.yacc"
    {strcpy(yyval.str,"gif");}
    break;

  case 1164:
#line 6013 "fgl.yacc"
    {strcpy(yyval.str,"png");}
    break;

  case 1165:
#line 6014 "fgl.yacc"
    {strcpy(yyval.str,"jpeg");}
    break;

  case 1166:
#line 6018 "fgl.yacc"
    {
	int vtype;
	vtype=scan_variable(yyvsp[0].str);
	if (vtype!=11&&vtype!=12) {
	a4gl_yyerror("Only Blobs may be printed...");
	YYERROR;
	}
}
    break;

  case 1167:
#line 6028 "fgl.yacc"
    {
strcpy(yyval.str,"0");
}
    break;

  case 1168:
#line 6030 "fgl.yacc"
    {
strcpy(yyval.str,"1");
}
    break;

  case 1169:
#line 6035 "fgl.yacc"
    {
	print_report_print(1,0,yyvsp[0].str);
	}
    break;

  case 1170:
#line 6038 "fgl.yacc"
    {
	print_report_print(1,0,yyvsp[0].str); /* changed from $<str>1 */
}
    break;

  case 1171:
#line 6043 "fgl.yacc"
    {
	strcpy(yyval.str,yyvsp[0].str); 
	}
    break;

  case 1172:
#line 6050 "fgl.yacc"
    {
int a;
a=add_report_agg('S',yyvsp[-2].ptr,yyvsp[0].ptr,racnt);
sprintf(yyval.str,"A4GL_push_double(_g%d);\n",racnt);
racnt+=a;
}
    break;

  case 1173:
#line 6057 "fgl.yacc"
    {
int a;
a=add_report_agg('C',0,yyvsp[0].ptr,racnt);
sprintf(yyval.str,"A4GL_push_int(_g%d);\n",racnt);
racnt+=a;
}
    break;

  case 1174:
#line 6064 "fgl.yacc"
    {
int a;
a=add_report_agg('C',0,yyvsp[0].ptr,racnt);
sprintf(yyval.str,"A4GL_push_int(_g%d);\n",racnt);
racnt+=a;
}
    break;

  case 1175:
#line 6073 "fgl.yacc"
    {
int a;
a=add_report_agg('P',yyvsp[-2].ptr,yyvsp[0].ptr,racnt);
sprintf(yyval.str,"A4GL_push_double((double)_g%d/(double)_g%d);\n",racnt,racnt+1);
racnt+=a;
}
    break;

  case 1176:
#line 6080 "fgl.yacc"
    {
int a;
a=add_report_agg('A',yyvsp[-2].ptr,yyvsp[0].ptr,racnt);
sprintf(yyval.str,"A4GL_push_double(_g%d/(double)_g%d);\n",racnt,racnt+1);
racnt+=a;
}
    break;

  case 1177:
#line 6087 "fgl.yacc"
    {
int a;
a=add_report_agg('A',yyvsp[-2].ptr,yyvsp[0].ptr,racnt);
sprintf(yyval.str,"A4GL_push_double(_g%d/_g%d);\n",racnt,racnt+1);
racnt+=a;
}
    break;

  case 1178:
#line 6094 "fgl.yacc"
    {
int a;
a=add_report_agg('N',yyvsp[-2].ptr,yyvsp[0].ptr,racnt);
sprintf(yyval.str,"A4GL_push_double(_g%d);\n",racnt);
racnt+=a;
}
    break;

  case 1179:
#line 6101 "fgl.yacc"
    {
int a;
a=add_report_agg('X',yyvsp[-2].ptr,yyvsp[0].ptr,racnt);
sprintf(yyval.str,"A4GL_push_double(_g%d);\n",racnt);
racnt+=a;
}
    break;

  case 1184:
#line 6114 "fgl.yacc"
    {rep_struct.left_margin=atoi(yyvsp[0].str);}
    break;

  case 1185:
#line 6115 "fgl.yacc"
    {rep_struct.right_margin=atoi(yyvsp[0].str);}
    break;

  case 1186:
#line 6116 "fgl.yacc"
    {rep_struct.top_margin=atoi(yyvsp[0].str);}
    break;

  case 1187:
#line 6117 "fgl.yacc"
    {rep_struct.bottom_margin=atoi(yyvsp[0].str);}
    break;

  case 1188:
#line 6118 "fgl.yacc"
    {rep_struct.page_length=atoi(yyvsp[0].str);}
    break;

  case 1189:
#line 6119 "fgl.yacc"
    { rep_struct.output_mode='P';strcpy(rep_struct.output_loc,"acl_getenv(\"DBPRINT\")");}
    break;

  case 1190:
#line 6120 "fgl.yacc"
    {rep_struct.output_mode='F';strcpy(rep_struct.output_loc,yyvsp[0].str);}
    break;

  case 1191:
#line 6121 "fgl.yacc"
    {rep_struct.output_mode='F';strcpy(rep_struct.output_loc,yyvsp[0].str);}
    break;

  case 1192:
#line 6122 "fgl.yacc"
    {rep_struct.output_mode='P';strcpy(rep_struct.output_loc,yyvsp[0].str);}
    break;

  case 1193:
#line 6123 "fgl.yacc"
    {strcpy(rep_struct.top_of_page,yyvsp[0].str);}
    break;

  case 1196:
#line 6129 "fgl.yacc"
    {sprintf(yyval.str,"-%f",atof(yyvsp[-1].str));}
    break;

  case 1197:
#line 6130 "fgl.yacc"
    {sprintf(yyval.str,"-%f",atof(yyvsp[-1].str)*72.0); }
    break;

  case 1198:
#line 6131 "fgl.yacc"
    {sprintf(yyval.str,"-%f",atof(yyvsp[-1].str)*2.83465);}
    break;

  case 1199:
#line 6132 "fgl.yacc"
    {sprintf(yyval.str,"%f",atof(yyvsp[0].str));}
    break;

  case 1204:
#line 6141 "fgl.yacc"
    {pdf_rep_struct.left_margin=atof(yyvsp[0].str);A4GL_debug("Left margin=%s\n",yyvsp[0].str);}
    break;

  case 1205:
#line 6142 "fgl.yacc"
    {pdf_rep_struct.right_margin=atof(yyvsp[0].str);}
    break;

  case 1206:
#line 6143 "fgl.yacc"
    {pdf_rep_struct.top_margin=atof(yyvsp[0].str);}
    break;

  case 1207:
#line 6144 "fgl.yacc"
    {pdf_rep_struct.bottom_margin=atof(yyvsp[0].str);}
    break;

  case 1208:
#line 6145 "fgl.yacc"
    {pdf_rep_struct.page_length=atof(yyvsp[0].str);}
    break;

  case 1209:
#line 6146 "fgl.yacc"
    {pdf_rep_struct.page_width=atof(yyvsp[0].str);}
    break;

  case 1210:
#line 6147 "fgl.yacc"
    {strcpy(pdf_rep_struct.font_name,yyvsp[0].str);}
    break;

  case 1211:
#line 6148 "fgl.yacc"
    {pdf_rep_struct.font_size=atof(yyvsp[0].str);}
    break;

  case 1212:
#line 6150 "fgl.yacc"
    {pdf_rep_struct.paper_size=1;}
    break;

  case 1213:
#line 6151 "fgl.yacc"
    {pdf_rep_struct.paper_size=2;}
    break;

  case 1214:
#line 6152 "fgl.yacc"
    {pdf_rep_struct.paper_size=3;}
    break;

  case 1215:
#line 6153 "fgl.yacc"
    {pdf_rep_struct.paper_size=5;}
    break;

  case 1216:
#line 6155 "fgl.yacc"
    {pdf_rep_struct.paper_size=-1;}
    break;

  case 1217:
#line 6156 "fgl.yacc"
    {pdf_rep_struct.paper_size=-2;}
    break;

  case 1218:
#line 6157 "fgl.yacc"
    {pdf_rep_struct.paper_size=-3;}
    break;

  case 1219:
#line 6158 "fgl.yacc"
    {pdf_rep_struct.paper_size=-5;}
    break;

  case 1223:
#line 6163 "fgl.yacc"
    {pdf_rep_struct.output_mode='F';strcpy(pdf_rep_struct.output_loc,yyvsp[0].str);}
    break;

  case 1224:
#line 6164 "fgl.yacc"
    {pdf_rep_struct.output_mode='P';strcpy(pdf_rep_struct.output_loc,yyvsp[0].str);}
    break;

  case 1228:
#line 6171 "fgl.yacc"
    {
int a;
set_rep_no_orderby(1);
if (get_bind_cnt('f')&&!get_bind_cnt('O')) { A4GL_copy_fbind_to_Obind(); }
a=print_bind_definition('O');
print_order_by_type(2,-1);
sprintf(yyval.str,"%d",a);
}
    break;

  case 1229:
#line 6180 "fgl.yacc"
    {
int a;
set_rep_no_orderby(0);
if (get_bind_cnt('f')&&!get_bind_cnt('O')) { A4GL_copy_fbind_to_Obind(); }
a=print_bind_definition('O');
print_order_by_type(1,a);
sprintf(yyval.str,"%d",a);
A4GL_debug("Order by Gives :%d\n",a);
}
    break;

  case 1230:
#line 6189 "fgl.yacc"
    {
int a;
set_rep_no_orderby(0);
if (get_bind_cnt('f')&&!get_bind_cnt('O')) { A4GL_copy_fbind_to_Obind(); }
a=print_bind_definition('O');
print_order_by_type(2,a);
sprintf(yyval.str,"%d",a);
A4GL_debug("Order by Gives :%d\n",a);
}
    break;

  case 1231:
#line 6202 "fgl.yacc"
    { 
		rep_type=REP_TYPE_NORMAL; 
		clr_function_constants (); 
		clr_variable(); 
		lastlineno=yylineno; 
		init_report_structure(&rep_struct); 
		}
    break;

  case 1232:
#line 6211 "fgl.yacc"
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

  case 1233:
#line 6222 "fgl.yacc"
    {
		lastlineno=yylineno;
		}
    break;

  case 1234:
#line 6226 "fgl.yacc"
    {
		print_variables();
		}
    break;

  case 1235:
#line 6230 "fgl.yacc"
    {
		print_report_2(0,yyvsp[0].str);
		rordcnt=atoi(yyvsp[0].str);
	 A4GL_debug("SET rordcnt=%d %s",rordcnt,yyvsp[0].str);
		}
    break;

  case 1236:
#line 6236 "fgl.yacc"
    {
		print_report_ctrl();
		}
    break;

  case 1237:
#line 6241 "fgl.yacc"
    {
		pop_blockcommand("REPORT");
		print_report_end() ;
		}
    break;

  case 1238:
#line 6249 "fgl.yacc"
    { strcpy(yyval.str,"");
	yyval.ptr=0;
}
    break;

  case 1239:
#line 6252 "fgl.yacc"
    {
	yyval.ptr=yyvsp[0].ptr;
//sprintf($<str>$,"%s", $<str>2);
}
    break;

  case 1240:
#line 6261 "fgl.yacc"
    {
if (!in_command("REPORT")) {
	a4gl_yyerror("PAUSE can only be used in reportes");
	YYERROR;
        }

print_pause(yyvsp[0].str) ;
}
    break;

  case 1241:
#line 6272 "fgl.yacc"
    {strcpy(yyval.str,"\"\"");}
    break;

  case 1243:
#line 6279 "fgl.yacc"
    {
rep_type=REP_TYPE_PDF;
clr_function_constants();
clr_variable(); 
lastlineno=yylineno; 
pdf_init_report_structure(&pdf_rep_struct);
}
    break;

  case 1244:
#line 6287 "fgl.yacc"
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

  case 1245:
#line 6297 "fgl.yacc"
    {
lastlineno=yylineno;
}
    break;

  case 1246:
#line 6300 "fgl.yacc"
    {
	print_variables();
}
    break;

  case 1247:
#line 6304 "fgl.yacc"
    {
//print_variables();
resize_paper(&pdf_rep_struct);
	print_report_2(1,yyvsp[0].str);
A4GL_debug("SET rordcnt=%d (%s)",rordcnt,yyvsp[0].str);
	rordcnt=atoi(yyvsp[0].str);
}
    break;

  case 1248:
#line 6312 "fgl.yacc"
    {
print_report_ctrl();
}
    break;

  case 1249:
#line 6315 "fgl.yacc"
    {
	pop_blockcommand("REPORT");
	print_report_end();
}
    break;

  case 1250:
#line 6321 "fgl.yacc"
    { strcpy(yyval.str,yyvsp[0].str); }
    break;

  case 1251:
#line 6325 "fgl.yacc"
    {new_counter();
   		addmap("CALL",yyvsp[-1].str,curr_func,yylineno,infilename);
   		}
    break;

  case 1252:
#line 6329 "fgl.yacc"
    {
		sprintf(yyval.str,"%d",get_counter_val());drop_counter();
		}
    break;

  case 1253:
#line 6333 "fgl.yacc"
    {
		print_pdf_call(yyvsp[-5].str,yyvsp[-2].ptr,yyvsp[-1].str);
   		}
    break;

  case 1254:
#line 6337 "fgl.yacc"
    {
	print_returning();
   }
    break;

  case 1255:
#line 6343 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 1256:
#line 6344 "fgl.yacc"
    { strcpy(yyval.str,"_rep.right_margin"); }
    break;

  case 1257:
#line 6345 "fgl.yacc"
    { sprintf(yyval.str,"%s",yyvsp[0].str); }
    break;

  case 1258:
#line 6346 "fgl.yacc"
    { sprintf(yyval.str,"%s",yyvsp[0].str); }
    break;

  case 1259:
#line 6351 "fgl.yacc"
    {
print_system_run(0,0);
}
    break;

  case 1260:
#line 6353 "fgl.yacc"
    {
print_system_run(1,yyvsp[0].str);
}
    break;

  case 1261:
#line 6356 "fgl.yacc"
    {
print_system_run(2,0);
}
    break;

  case 1262:
#line 6360 "fgl.yacc"
    {
print_system_run(0,0);
}
    break;

  case 1263:
#line 6363 "fgl.yacc"
    {
print_system_run(0,0);
/* FIXME */
}
    break;

  case 1264:
#line 6370 "fgl.yacc"
    {
	print_exec_sql(yyvsp[0].str);
}
    break;

  case 1265:
#line 6375 "fgl.yacc"
    {sprintf(yyval.str, "%s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1266:
#line 6376 "fgl.yacc"
    {sprintf(yyval.str,  "%s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1267:
#line 6377 "fgl.yacc"
    {sprintf(yyval.str,"%s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1268:
#line 6378 "fgl.yacc"
    {sprintf(yyval.str,"%s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1269:
#line 6383 "fgl.yacc"
    { print_exec_sql(yyvsp[0].str); }
    break;

  case 1270:
#line 6384 "fgl.yacc"
    { print_exec_sql(yyvsp[0].sql_string); 
	free(yyvsp[0].sql_string);
}
    break;

  case 1271:
#line 6390 "fgl.yacc"
    {insql=1;}
    break;

  case 1272:
#line 6390 "fgl.yacc"
    {insql=0;}
    break;

  case 1273:
#line 6390 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-7].str," ",yyvsp[-5].str," ",yyvsp[-4].str,yyvsp[-2].sql_string,yyvsp[-1].str,yyvsp[0].str,0);
		free(yyvsp[-2].sql_string);
	}
    break;

  case 1274:
#line 6395 "fgl.yacc"
    {insql=1;}
    break;

  case 1275:
#line 6395 "fgl.yacc"
    {insql=0;}
    break;

  case 1276:
#line 6395 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-8].str," ",yyvsp[-6].str," ",yyvsp[-5].str,yyvsp[-3].sql_string,yyvsp[-2].str, " ",yyvsp[-1].str,yyvsp[0].str,0);
		free(yyvsp[-3].sql_string);
	}
    break;

  case 1277:
#line 6403 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1278:
#line 6404 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1280:
#line 6409 "fgl.yacc"
    {sprintf(yyval.str,"%s%s",yyvsp[-1].str,yyvsp[0].str); }
    break;

  case 1281:
#line 6414 "fgl.yacc"
    {sprintf(yyval.str," IN %s",yyvsp[0].str);}
    break;

  case 1282:
#line 6415 "fgl.yacc"
    {sprintf(yyval.str," EXTENT SIZE %s",yyvsp[0].str); }
    break;

  case 1283:
#line 6416 "fgl.yacc"
    {sprintf(yyval.str," NEXT SIZE %s",yyvsp[0].str); }
    break;

  case 1284:
#line 6417 "fgl.yacc"
    {sprintf(yyval.str," LOCK MODE PAGE");}
    break;

  case 1285:
#line 6418 "fgl.yacc"
    {sprintf(yyval.str," LOCK MODE ROW");}
    break;

  case 1287:
#line 6423 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1288:
#line 6423 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1290:
#line 6427 "fgl.yacc"
    {sprintf(yyval.str,"%s%s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1291:
#line 6431 "fgl.yacc"
    {sprintf(yyval.str," IN %s",yyvsp[0].str);}
    break;

  case 1292:
#line 6432 "fgl.yacc"
    {sprintf(yyval.str,"FILLFACTOR %s",yyvsp[0].str);}
    break;

  case 1293:
#line 6435 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s %s %s %s %s",yyvsp[-7].str,yyvsp[-6].str,yyvsp[-5].str,yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1294:
#line 6436 "fgl.yacc"
    {
		a4gl_yyerror("You cannot create a database from within Aubit4gl - if the target database allows - prepare and execute it manually");
	}
    break;

  case 1295:
#line 6439 "fgl.yacc"
    {
		a4gl_yyerror("You cannot drop a database from within Aubit4gl - if the target database allows - prepare and execute it manually");
	}
    break;

  case 1296:
#line 6442 "fgl.yacc"
    {
		sprintf(yyval.str,"%s %s FOR %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[0].str);
	}
    break;

  case 1297:
#line 6445 "fgl.yacc"
    {
		sprintf(yyval.str,"%s %s",yyvsp[-1].str,yyvsp[0].str);
	}
    break;

  case 1298:
#line 6451 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1299:
#line 6453 "fgl.yacc"
    {
if (A4GL_isyes(acl_getenv("A4GL_OMIT_NO_LOG"))) {
	strcpy(yyval.str,"");
} else {
	sprintf(yyval.str," %s ",yyvsp[0].str);
}
}
    break;

  case 1301:
#line 6466 "fgl.yacc"
    {sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1302:
#line 6470 "fgl.yacc"
    {sprintf(yyval.str,"%s ASC",yyvsp[-1].str);}
    break;

  case 1303:
#line 6471 "fgl.yacc"
    {sprintf(yyval.str,"%s DESC",yyvsp[-1].str);}
    break;

  case 1305:
#line 6476 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1306:
#line 6479 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",",yyvsp[0].sql_string,0);
	}
    break;

  case 1307:
#line 6485 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1308:
#line 6488 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1309:
#line 6496 "fgl.yacc"
    {sprintf(yyval.str,"%s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1311:
#line 6503 "fgl.yacc"
    {
	yyval.sql_string=make_sql_string(yyvsp[-2].str," ",yyvsp[-1].str," ",yyvsp[0].sql_string,0);
	print_exec_sql(yyval.sql_string); 
}
    break;

  case 1312:
#line 6507 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("ALTER INDEX ",yyvsp[-1].str," TO CLUSTER",0);
		print_exec_sql(yyval.sql_string); 
		}
    break;

  case 1313:
#line 6511 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("ALTER INDEX ",yyvsp[-1].str," TO NOT CLUSTER",0);
		}
    break;

  case 1314:
#line 6517 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1315:
#line 6520 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",",yyvsp[0].sql_string,0);
	}
    break;

  case 1316:
#line 6529 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1317:
#line 6532 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1318:
#line 6535 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1319:
#line 6538 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1320:
#line 6541 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1321:
#line 6544 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1322:
#line 6547 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1323:
#line 6554 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("ADD ",yyvsp[0].sql_string,0);
	}
    break;

  case 1324:
#line 6557 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("ADD (",yyvsp[-1].sql_string,")",0);
	}
    break;

  case 1325:
#line 6564 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1326:
#line 6567 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string," BEFORE ",yyvsp[0].str,0);
	}
    break;

  case 1327:
#line 6573 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1328:
#line 6576 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",",yyvsp[0].sql_string,0);
	}
    break;

  case 1329:
#line 6583 "fgl.yacc"
    {
		sprintf(yyval.str,"DROP %s",yyvsp[0].str);
	}
    break;

  case 1330:
#line 6586 "fgl.yacc"
    {
		sprintf(yyval.str,"DROP (%s)",yyvsp[-1].str);
	}
    break;

  case 1332:
#line 6594 "fgl.yacc"
    {
		sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);
	}
    break;

  case 1334:
#line 6603 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("MODIFY ",yyvsp[0].sql_string,0);
	}
    break;

  case 1335:
#line 6606 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("MODIFY (",yyvsp[-1].sql_string,")",0);
	}
    break;

  case 1336:
#line 6612 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1337:
#line 6615 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",",yyvsp[0].sql_string,0);
	}
    break;

  case 1338:
#line 6621 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1339:
#line 6628 "fgl.yacc"
    {strcpy(yyval.str,"LOCK MODE (PAGE)");}
    break;

  case 1340:
#line 6629 "fgl.yacc"
    {strcpy(yyval.str,"LOCK MODE (ROW)");}
    break;

  case 1341:
#line 6633 "fgl.yacc"
    {
		sprintf(yyval.str,"MODIFY NEXT SIZE %d",atoi(yyvsp[0].str));
	}
    break;

  case 1342:
#line 6643 "fgl.yacc"
    {
		sprintf(yyval.str,"ADD CONSTRAINT %s%s",yyvsp[-1].sql_string,yyvsp[0].str);
	}
    break;

  case 1343:
#line 6646 "fgl.yacc"
    {
		sprintf(yyval.str,"ADD CONSTRAINT (%s)",yyvsp[-1].sql_string);
	}
    break;

  case 1344:
#line 6652 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-1].sql_string,yyvsp[0].str,0);
}
    break;

  case 1345:
#line 6654 "fgl.yacc"
    {
	yyval.sql_string=make_sql_string(yyvsp[-3].sql_string,",",yyvsp[-1].sql_string,yyvsp[0].str, 0);
}
    break;

  case 1346:
#line 6659 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1347:
#line 6660 "fgl.yacc"
    {sprintf(yyval.str," %s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1348:
#line 6665 "fgl.yacc"
    { sprintf(yyval.str,"DROP CONSTRAINT %s",yyvsp[0].str); }
    break;

  case 1349:
#line 6666 "fgl.yacc"
    {
		sprintf(yyval.str,"DROP CONSTRAINT (%s)",yyvsp[-1].str);
	}
    break;

  case 1350:
#line 6672 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1351:
#line 6673 "fgl.yacc"
    {sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1355:
#line 6700 "fgl.yacc"
    {sprintf(yyval.str,"%s %s /*FIXME */",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1361:
#line 6706 "fgl.yacc"
    { 
	print_set_conn(yyvsp[0].str);
}
    break;

  case 1362:
#line 6709 "fgl.yacc"
    {
	print_set_options("conn",yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 1363:
#line 6712 "fgl.yacc"
    {
	print_set_options("stmt",yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 1364:
#line 6718 "fgl.yacc"
    {strcpy(yyval.str,"\"default\"");}
    break;

  case 1366:
#line 6724 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1368:
#line 6735 "fgl.yacc"
    {
		print_sleep();
	}
    break;

  case 1369:
#line 6749 "fgl.yacc"
    {
		print_sql_commit(0);
		}
    break;

  case 1370:
#line 6758 "fgl.yacc"
    { insql=1;start_bind('i',0);}
    break;

  case 1371:
#line 6758 "fgl.yacc"
    {
	yyval.sql_string=make_sql_string(yyvsp[-4].str," ",yyvsp[-2].str," ",yyvsp[-1].str," ",yyvsp[0].sql_string,0);
}
    break;

  case 1372:
#line 6763 "fgl.yacc"
    {insql=1;}
    break;

  case 1373:
#line 6763 "fgl.yacc"
    {
insql=0;
	//printf("Value = %s\n",$<sql_string>4);
yyval.sql_string=make_sql_string(yyvsp[-4].str," (",yyvsp[-1].sql_string,")",0);}
    break;

  case 1374:
#line 6768 "fgl.yacc"
    {yyval.sql_string=yyvsp[0].sql_string;}
    break;

  case 1375:
#line 6771 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1376:
#line 6773 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1378:
#line 6780 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1379:
#line 6784 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	//printf(" 1. Value = %s\n",$<sql_string>$);
	}
    break;

  case 1380:
#line 6788 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",", yyvsp[0].sql_string,0);
	//printf(" 2. Value = %s\n",$<sql_string>$);
	}
    break;

  case 1381:
#line 6795 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1382:
#line 6798 "fgl.yacc"
    {
		yyval.sql_string=strdup("NULL");
	}
    break;

  case 1383:
#line 6805 "fgl.yacc"
    {
      print_fetch_1();
    }
    break;

  case 1384:
#line 6809 "fgl.yacc"
    {
      print_fetch_2();
      print_fetch_3(yyvsp[-1].str,yyvsp[0].str);
    }
    break;

  case 1385:
#line 6815 "fgl.yacc"
    {sprintf(yyval.str,"%s",yyvsp[0].str);doing_declare=1;}
    break;

  case 1386:
#line 6820 "fgl.yacc"
    {sprintf(yyval.str,"%s, %s",yyvsp[0].str,yyvsp[-1].str);
addmap("Fetch Cursor",yyvsp[0].str,curr_func,yylineno,infilename);
}
    break;

  case 1387:
#line 6824 "fgl.yacc"
    {sprintf(yyval.str,"%s, %d, 1",yyvsp[0].str,FETCH_RELATIVE);

addmap("Fetch Cursor",yyvsp[0].str,curr_func,yylineno,infilename);
}
    break;

  case 1388:
#line 6830 "fgl.yacc"
    {
A4GL_debug("no into\n");
strcpy(yyval.str,"0,0");
}
    break;

  case 1389:
#line 6833 "fgl.yacc"
    {
 A4GL_debug("FETCH INTO  ...");
	/* start_bind('i',0,-1); */
    start_bind('o',0);
}
    break;

  case 1390:
#line 6839 "fgl.yacc"
    {
	int no;
	no=get_bind_cnt('o');
	sprintf(yyval.str,"%d,obind",no);
}
    break;

  case 1391:
#line 6846 "fgl.yacc"
    {
A4GL_debug("no into\n");
strcpy(yyval.str,"0,0");
}
    break;

  case 1392:
#line 6850 "fgl.yacc"
    {
 A4GL_debug("FETCH INTO  ...");
	/* start_bind('i',0,-1); */
    start_bind('o',0);
}
    break;

  case 1393:
#line 6855 "fgl.yacc"
    {
/*
int ni;
ni=print_bind('i');
sprintf($<str>$,"%d,ibind",ni);
*/
}
    break;

  case 1394:
#line 6865 "fgl.yacc"
    {
		sprintf(yyval.str,"%d,1",FETCH_ABSOLUTE);}
    break;

  case 1395:
#line 6868 "fgl.yacc"
    {sprintf(yyval.str,"%d,-1",FETCH_ABSOLUTE);}
    break;

  case 1396:
#line 6870 "fgl.yacc"
    {sprintf(yyval.str,"%d,1",FETCH_RELATIVE);}
    break;

  case 1397:
#line 6872 "fgl.yacc"
    {sprintf(yyval.str,"%d,-1",FETCH_RELATIVE);}
    break;

  case 1398:
#line 6874 "fgl.yacc"
    {sprintf(yyval.str,"%d,-1",FETCH_RELATIVE);}
    break;

  case 1399:
#line 6876 "fgl.yacc"
    {sprintf(yyval.str,"%d,0",FETCH_RELATIVE);}
    break;

  case 1400:
#line 6878 "fgl.yacc"
    {sprintf(yyval.str,"%d,A4GL_pop_int()",FETCH_RELATIVE);}
    break;

  case 1401:
#line 6880 "fgl.yacc"
    {sprintf(yyval.str,"%d,A4GL_pop_int()",FETCH_ABSOLUTE);}
    break;

  case 1402:
#line 6886 "fgl.yacc"
    {
 
rm_quotes(yyvsp[0].str);
sprintf(yyval.str," %s %s %s %s ",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str
);}
    break;

  case 1403:
#line 6896 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].str," ",yyvsp[-1].str," ",yyvsp[0].sql_string,0);
		}
    break;

  case 1404:
#line 6903 "fgl.yacc"
    {sprintf(yyval.str,"%s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1406:
#line 6909 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1407:
#line 6912 "fgl.yacc"
    {sprintf(yyval.str,"%s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1410:
#line 6919 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1413:
#line 6924 "fgl.yacc"
    {
print_sql_commit(-1);
}
    break;

  case 1414:
#line 6929 "fgl.yacc"
    {
		print_sql_commit(1);
	}
    break;

  case 1415:
#line 6936 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1416:
#line 6937 "fgl.yacc"
    {
		strcpy(yyval.str,"EXCLUSIVE");
	}
    break;

  case 1417:
#line 6944 "fgl.yacc"
    {
if (strcmp(yyvsp[-1].str,"?")==0) {
	print_init_conn(0);
} else {
	print_init_conn(yyvsp[-1].str);
}
}
    break;

  case 1418:
#line 6955 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1419:
#line 6956 "fgl.yacc"
    {sprintf(yyval.str,"%s@%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1420:
#line 6957 "fgl.yacc"
    {strcpy(yyval.str, A4GL_strip_quotes (yyvsp[0].str));}
    break;

  case 1421:
#line 6960 "fgl.yacc"
    {insql=1;}
    break;

  case 1422:
#line 6960 "fgl.yacc"
    {
print_undo_use(yyvsp[-2].str);
insql=0;strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1423:
#line 6965 "fgl.yacc"
    {
		 A4GL_lex_printcomment("/*  schema */\n");
			print_exec_sql(yyvsp[0].sql_string);
			strcpy(yyval.str,"Schema");
	}
    break;

  case 1424:
#line 6970 "fgl.yacc"
    {
	 A4GL_lex_printcomment("/*  schema  2*/\n");
		print_exec_sql(yyvsp[0].sql_string);
		strcpy(yyval.str,"Schema Element");
	}
    break;

  case 1426:
#line 6976 "fgl.yacc"
    {
		print_exec_sql(yyvsp[0].str);
 	}
    break;

  case 1428:
#line 6980 "fgl.yacc"
    {
	 A4GL_lex_printcomment("/*  delete 1 */\n");
		print_exec_sql_bound(yyvsp[0].str);
		strcpy(yyval.str,"Delete where current...");
	}
    break;

  case 1429:
#line 6985 "fgl.yacc"
    {
	 A4GL_lex_printcomment("/*  delete 2 */\n");
		print_exec_sql_bound(yyvsp[0].sql_string);
		strcpy(yyval.str,"Delete where ...");
	}
    break;

  case 1430:
#line 6990 "fgl.yacc"
    {
		strcpy(yyval.str,"Fetch");
	 A4GL_lex_printcomment("/*  fetch */\n");
	}
    break;

  case 1431:
#line 6994 "fgl.yacc"
    {
	 A4GL_lex_printcomment("/*  insert */\n");
		print_exec_sql_bound(yyvsp[0].sql_string);
		strcpy(yyval.str,"insert");
	}
    break;

  case 1433:
#line 7000 "fgl.yacc"
    {
		print_do_select(yyvsp[0].sql_string);
		strcpy(yyval.str,"select");
	}
    break;

  case 1434:
#line 7004 "fgl.yacc"
    {
		print_exec_sql_bound(yyvsp[0].sql_string);
		strcpy(yyval.str,"update");
	}
    break;

  case 1435:
#line 7011 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s %s %s %s",yyvsp[-6].str,yyvsp[-5].str,yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1436:
#line 7012 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s %s %s",yyvsp[-5].str,yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1437:
#line 7013 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s ",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1438:
#line 7014 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s ",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1442:
#line 7024 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1443:
#line 7025 "fgl.yacc"
    {sprintf(yyval.str," %s ",yyvsp[0].str);}
    break;

  case 1444:
#line 7026 "fgl.yacc"
    {sprintf(yyval.str," %s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1445:
#line 7030 "fgl.yacc"
    {sprintf(yyval.str," %s ",yyvsp[0].str);}
    break;

  case 1446:
#line 7031 "fgl.yacc"
    {sprintf(yyval.str," %s ",yyvsp[0].str);}
    break;

  case 1449:
#line 7038 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1450:
#line 7041 "fgl.yacc"
    {sprintf(yyval.str," %s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1453:
#line 7044 "fgl.yacc"
    {sprintf(yyval.str," %s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1456:
#line 7049 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1457:
#line 7051 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1459:
#line 7057 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1461:
#line 7063 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1464:
#line 7073 "fgl.yacc"
    {
yyval.sql_string=make_sql_string(yyvsp[-5].str," ",yyvsp[-4].str," ",yyvsp[-3].str," ",yyvsp[-2].str," ",yyvsp[-1].sql_string," ",yyvsp[0].str,0);
}
    break;

  case 1465:
#line 7078 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1466:
#line 7080 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1468:
#line 7086 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1469:
#line 7089 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1471:
#line 7095 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("CHECK(",yyvsp[-1].sql_string,")",0);
	}
    break;

  case 1472:
#line 7103 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s %s",yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1473:
#line 7108 "fgl.yacc"
    {sprintf(yyval.str," %s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1476:
#line 7118 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1478:
#line 7124 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1479:
#line 7129 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1480:
#line 7130 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1481:
#line 7132 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1483:
#line 7138 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1484:
#line 7143 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1485:
#line 7146 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1486:
#line 7149 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1487:
#line 7156 "fgl.yacc"
    {sprintf(yyval.str," %s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1488:
#line 7157 "fgl.yacc"
    {sprintf(yyval.str," DEFAULT USER");}
    break;

  case 1489:
#line 7158 "fgl.yacc"
    {sprintf(yyval.str," DEFAULT TODAY");}
    break;

  case 1490:
#line 7160 "fgl.yacc"
    {sprintf(yyval.str," %s",yyvsp[0].str);}
    break;

  case 1491:
#line 7173 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-3].str," ",yyvsp[-2].str," ",yyvsp[-1].str," ",yyvsp[0].sql_string,0);
	}
    break;

  case 1492:
#line 7178 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1494:
#line 7182 "fgl.yacc"
    {
		yyval.sql_string=strdup("");
	}
    break;

  case 1495:
#line 7184 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1496:
#line 7191 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1497:
#line 7194 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-1].sql_string,yyvsp[0].sql_string,0);
	}
    break;

  case 1498:
#line 7200 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-1].sql_string,yyvsp[0].str,0);
	}
    break;

  case 1499:
#line 7208 "fgl.yacc"
    {
		sprintf(yyval.str," %s ",yyvsp[0].str);
		yyval.sql_string=strdup(yyval.str);
	}
    break;

  case 1500:
#line 7212 "fgl.yacc"
    {
		sprintf(yyval.str," %s ",yyvsp[0].str);
		yyval.sql_string=strdup(yyval.str);
	}
    break;

  case 1501:
#line 7216 "fgl.yacc"
    {
		sprintf(yyval.str," %s ",yyvsp[0].str);
		yyval.sql_string=strdup(yyval.str);
	}
    break;

  case 1502:
#line 7220 "fgl.yacc"
    {
		sprintf(yyval.str," %s ",yyvsp[0].str);
		yyval.sql_string=strdup(yyval.str);
	}
    break;

  case 1503:
#line 7224 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1504:
#line 7227 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-3].str," ",yyvsp[-2].str," ",yyvsp[-1].sql_string," ",yyvsp[0].str,0);
	}
    break;

  case 1505:
#line 7230 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(" PRIMARY KEY ",0);
	}
    break;

  case 1506:
#line 7238 "fgl.yacc"
    {
yyval.sql_string=make_sql_string(yyvsp[-2].str," ",yyvsp[-1].str," ",yyvsp[0].str,0);
}
    break;

  case 1507:
#line 7245 "fgl.yacc"
    {sprintf(yyval.str," %s",yyvsp[0].str);}
    break;

  case 1510:
#line 7254 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-1].sql_string," ",yyvsp[0].sql_string,0);
	}
    break;

  case 1511:
#line 7260 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1512:
#line 7263 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1513:
#line 7274 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-1].str," ",yyvsp[0].sql_string,0);
	}
    break;

  case 1514:
#line 7281 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("GROUP BY ",yyvsp[0].sql_string,0);
	}
    break;

  case 1515:
#line 7287 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1516:
#line 7290 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",",yyvsp[0].sql_string,0);
	}
    break;

  case 1517:
#line 7297 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("WHERE ",yyvsp[0].sql_string,0);
	}
    break;

  case 1518:
#line 7304 "fgl.yacc"
    {
		sprintf(yyval.str,"%s %s",yyvsp[-1].str,yyvsp[0].str);
	}
    break;

  case 1520:
#line 7311 "fgl.yacc"
    {
		sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);
	}
    break;

  case 1521:
#line 7317 "fgl.yacc"
    {sprintf(yyval.str," %s ", yyvsp[0].str);}
    break;

  case 1522:
#line 7318 "fgl.yacc"
    {sprintf(yyval.str," %s %s ",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1523:
#line 7319 "fgl.yacc"
    {sprintf(yyval.str," %s (%s) ",yyvsp[-3].str,yyvsp[-1].str);}
    break;

  case 1525:
#line 7323 "fgl.yacc"
    {sprintf(yyval.str,"%s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1527:
#line 7328 "fgl.yacc"
    { sprintf(yyval.str," %s,%s ",yyvsp[-2].str,yyvsp[0].str);  }
    break;

  case 1528:
#line 7335 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-3].str," ",yyvsp[-2].sql_string," ",yyvsp[-1].sql_string," ",yyvsp[0].sql_string,0);
	}
    break;

  case 1529:
#line 7340 "fgl.yacc"
    { yyval.sql_string=strdup("");}
    break;

  case 1530:
#line 7341 "fgl.yacc"
    {yyval.sql_string=yyvsp[0].sql_string;}
    break;

  case 1531:
#line 7344 "fgl.yacc"
    {
	yyval.sql_string=strdup("");
}
    break;

  case 1532:
#line 7347 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
}
    break;

  case 1533:
#line 7352 "fgl.yacc"
    {yyval.sql_string=strdup("");}
    break;

  case 1534:
#line 7353 "fgl.yacc"
    {yyval.sql_string=yyvsp[0].sql_string;}
    break;

  case 1535:
#line 7358 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1536:
#line 7361 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string," OR ",yyvsp[0].sql_string,0);
	}
    break;

  case 1537:
#line 7367 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1538:
#line 7370 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string," AND ",yyvsp[0].sql_string,0);
	}
    break;

  case 1539:
#line 7376 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1540:
#line 7379 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-1].str," ",yyvsp[0].sql_string,0);
	}
    break;

  case 1541:
#line 7385 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1542:
#line 7388 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].str,yyvsp[-1].sql_string,yyvsp[0].str,0);
	}
    break;

  case 1543:
#line 7395 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-1].str," ",yyvsp[0].sql_string,0);}
    break;

  case 1544:
#line 7396 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-1].str," ",yyvsp[0].sql_string,0);}
    break;

  case 1545:
#line 7425 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1546:
#line 7427 "fgl.yacc"
    {sprintf(yyval.str," %s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1547:
#line 7431 "fgl.yacc"
    {yyval.sql_string=yyvsp[0].sql_string;}
    break;

  case 1549:
#line 7444 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-4].sql_string," IN (",yyvsp[-1].str,")",0);
	}
    break;

  case 1550:
#line 7447 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string," ",yyvsp[-1].str," ",yyvsp[0].sql_string,0);
	}
    break;

  case 1551:
#line 7450 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-4].sql_string," NOT IN (",yyvsp[-1].str,")",0);
	}
    break;

  case 1552:
#line 7453 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string," ",yyvsp[-1].str," ",yyvsp[0].sql_string,0);
	}
    break;

  case 1554:
#line 7461 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1555:
#line 7464 "fgl.yacc"
    {
		strcpy(yyval.str,yyvsp[0].sql_string);
	}
    break;

  case 1557:
#line 7470 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1559:
#line 7476 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string," ",yyvsp[-1].str," IS NULL",0);
	}
    break;

  case 1560:
#line 7479 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string," ",yyvsp[-1].str," IS NOT NULL",0);
	}
    break;

  case 1561:
#line 7482 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string," ",yyvsp[-1].str," ",yyvsp[0].sql_string,0);
	}
    break;

  case 1562:
#line 7485 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-5].sql_string," ",yyvsp[-4].str," BETWEEN ",yyvsp[-2].sql_string," AND ",yyvsp[0].sql_string,0);
	}
    break;

  case 1563:
#line 7488 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-3].sql_string," ",yyvsp[-2].str," ",yyvsp[-1].sql_string,yyvsp[0].str,0);
	}
    break;

  case 1564:
#line 7491 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-3].sql_string," ",yyvsp[-2].str," ",yyvsp[-1].sql_string,yyvsp[0].str,0);
	}
    break;

  case 1565:
#line 7494 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-3].sql_string," ",yyvsp[-2].str," ",yyvsp[-1].sql_string,yyvsp[0].str,0);
	}
    break;

  case 1566:
#line 7497 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-3].sql_string," ",yyvsp[-2].str," ",yyvsp[-1].sql_string,yyvsp[0].str,0);
	}
    break;

  case 1567:
#line 7502 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-4].sql_string," ",yyvsp[-3].str," MATCHES ",yyvsp[-1].sql_string,yyvsp[0].str,0);
	}
    break;

  case 1569:
#line 7509 "fgl.yacc"
    {strcpy(yyval.str,"!=");}
    break;

  case 1575:
#line 7517 "fgl.yacc"
    {strcpy(yyval.str,"<=");}
    break;

  case 1576:
#line 7518 "fgl.yacc"
    {strcpy(yyval.str,">=");}
    break;

  case 1577:
#line 7523 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1578:
#line 7526 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1579:
#line 7530 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1580:
#line 7536 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1581:
#line 7537 "fgl.yacc"
    {strcpy(yyval.str," ALL ");}
    break;

  case 1582:
#line 7538 "fgl.yacc"
    {strcpy(yyval.str," DISTINCT ");}
    break;

  case 1583:
#line 7539 "fgl.yacc"
    {
		ansi_violation("Use DISTINCT not UNIQUE",0);
		strcpy(yyval.str," DISTINCT ");
	}
    break;

  case 1588:
#line 7559 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1590:
#line 7563 "fgl.yacc"
    {strcpy(yyval.str,"SERIAL");}
    break;

  case 1591:
#line 7564 "fgl.yacc"
    {sprintf(yyval.str,"SERIAL(%s)",yyvsp[-1].str);}
    break;

  case 1593:
#line 7567 "fgl.yacc"
    {sprintf(yyval.str," DECIMAL(%s%s)",yyvsp[-2].str,yyvsp[-1].str);}
    break;

  case 1594:
#line 7569 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s %s",yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1602:
#line 7578 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1603:
#line 7580 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s %s %s",yyvsp[-5].str,yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1604:
#line 7582 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1606:
#line 7585 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1608:
#line 7588 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s %s %s %s",yyvsp[-6].str,yyvsp[-5].str,yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1612:
#line 7593 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1613:
#line 7595 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s %s %s",yyvsp[-5].str,yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1614:
#line 7598 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1615:
#line 7599 "fgl.yacc"
    {
		sprintf(yyval.str,",%s",yyvsp[0].str);
}
    break;

  case 1616:
#line 7606 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1620:
#line 7611 "fgl.yacc"
    {sprintf(yyval.str," %s",yyvsp[0].str);}
    break;

  case 1624:
#line 7627 "fgl.yacc"
    { 
			if (A4GL_escape_quote_owner()) {
				sprintf(yyval.str,"\\\"%s\\\"%s%s", A4GL_strip_quotes (yyvsp[-2].str),yyvsp[-1].str,yyvsp[0].str); addmap("Use Table",yyval.str,curr_func,yylineno,infilename); 
			} else {
				sprintf(yyval.str,"\"%s\"%s%s", A4GL_strip_quotes (yyvsp[-2].str),yyvsp[-1].str,yyvsp[0].str); addmap("Use Table",yyval.str,curr_func,yylineno,infilename); 
			}
	}
    break;

  case 1625:
#line 7634 "fgl.yacc"
    {
		sprintf(yyval.str," %s", A4GL_strip_quotes (yyvsp[0].str));
		addmap("Use Table",yyval.str,curr_func,yylineno,infilename);
	}
    break;

  case 1626:
#line 7638 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str); addmap("Use Table",yyvsp[0].str,curr_func,yylineno,infilename); }
    break;

  case 1627:
#line 7639 "fgl.yacc"
    { sprintf(yyval.str," %s%s%s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str); addmap("Use Table",yyval.str,curr_func,yylineno,infilename); }
    break;

  case 1628:
#line 7640 "fgl.yacc"
    { 
                        if (A4GL_escape_quote_owner()) {
				sprintf(yyval.str," %s:\\\"%s\\\".%s",yyvsp[-4].str,A4GL_strip_quotes(yyvsp[-2].str),yyvsp[0].str); addmap("Use Table",yyval.str,curr_func,yylineno,infilename); 
                        } else {
				sprintf(yyval.str," %s:%s.%s",yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str); addmap("Use Table",yyval.str,curr_func,yylineno,infilename); 
                        }
	}
    break;

  case 1629:
#line 7648 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[-2].str); addmap("Use Table",yyvsp[-2].str,curr_func,yylineno,infilename); }
    break;

  case 1630:
#line 7649 "fgl.yacc"
    { sprintf(yyval.str," %s@%s%s%s",yyvsp[-4].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str); addmap("Use Table",yyval.str,curr_func,yylineno,infilename); }
    break;

  case 1631:
#line 7650 "fgl.yacc"
    { 
                        if (A4GL_escape_quote_owner()) {
				sprintf(yyval.str," %s@%s:\\\"%s\\\".%s",yyvsp[-6].str,yyvsp[-4].str,A4GL_strip_quotes(yyvsp[-2].str),yyvsp[0].str); addmap("Use Table",yyval.str,curr_func,yylineno,infilename); 
                        } else {
				sprintf(yyval.str," %s@%s:%s.%s",yyvsp[-6].str,yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str); addmap("Use Table",yyval.str,curr_func,yylineno,infilename); 
                        }
	}
    break;

  case 1632:
#line 7661 "fgl.yacc"
    { 
			if (A4GL_escape_quote_owner()) {
				sprintf(yyval.str,"\\\"%s\\\"%s%s", A4GL_strip_quotes (yyvsp[-2].str),yyvsp[-1].str,yyvsp[0].str); addmap("Use Index",yyval.str,curr_func,yylineno,infilename); 
			} else {
				sprintf(yyval.str,"\"%s\"%s%s", A4GL_strip_quotes (yyvsp[-2].str),yyvsp[-1].str,yyvsp[0].str); addmap("Use Index",yyval.str,curr_func,yylineno,infilename); 
			}
	}
    break;

  case 1633:
#line 7668 "fgl.yacc"
    {
		sprintf(yyval.str," %s", A4GL_strip_quotes (yyvsp[0].str));
		addmap("Use Index",yyval.str,curr_func,yylineno,infilename);
	}
    break;

  case 1634:
#line 7673 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str); addmap("Use Index",yyvsp[0].str,curr_func,yylineno,infilename); }
    break;

  case 1635:
#line 7674 "fgl.yacc"
    { sprintf(yyval.str," %s%s%s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str); addmap("Use Index",yyval.str,curr_func,yylineno,infilename); }
    break;

  case 1636:
#line 7675 "fgl.yacc"
    { 
                        if (A4GL_escape_quote_owner()) {
				sprintf(yyval.str," %s:\\\"%s\\\".%s",yyvsp[-4].str,A4GL_strip_quotes(yyvsp[-2].str),yyvsp[0].str); addmap("Use Index",yyval.str,curr_func,yylineno,infilename); 
                        } else {
				sprintf(yyval.str," %s:%s.%s",yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str); addmap("Use Index",yyval.str,curr_func,yylineno,infilename); 
                        }
	}
    break;

  case 1637:
#line 7683 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[-2].str); addmap("Use Index",yyvsp[-2].str,curr_func,yylineno,infilename); }
    break;

  case 1638:
#line 7684 "fgl.yacc"
    { sprintf(yyval.str," %s@%s%s%s",yyvsp[-4].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str); addmap("Use Index",yyval.str,curr_func,yylineno,infilename); }
    break;

  case 1639:
#line 7685 "fgl.yacc"
    { 
                        if (A4GL_escape_quote_owner()) {
				sprintf(yyval.str," %s@%s:\\\"%s\\\".%s",yyvsp[-6].str,yyvsp[-4].str,A4GL_strip_quotes(yyvsp[-2].str),yyvsp[0].str); addmap("Use Index",yyval.str,curr_func,yylineno,infilename); 
                        } else {
				sprintf(yyval.str," %s@%s:%s.%s",yyvsp[-6].str,yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str); addmap("Use Index",yyval.str,curr_func,yylineno,infilename); 
                        }
	}
    break;

  case 1641:
#line 7711 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1642:
#line 7712 "fgl.yacc"
    {sprintf(yyval.str,"[%s]",yyvsp[-1].str);}
    break;

  case 1643:
#line 7713 "fgl.yacc"
    {sprintf(yyval.str,"[%s,%s]",yyvsp[-3].str,yyvsp[-1].str);}
    break;

  case 1644:
#line 7717 "fgl.yacc"
    {
		strcpy(yyval.str,yyvsp[0].str);
	}
    break;

  case 1645:
#line 7720 "fgl.yacc"
    {
		strcpy(yyval.str,yyvsp[0].str);
	}
    break;

  case 1646:
#line 7726 "fgl.yacc"
    { 
addmap("Use Column",yyvsp[-1].str,curr_func,yylineno,infilename);
sprintf(yyval.str,"%s%s",yyvsp[-1].str,yyvsp[0].str);
}
    break;

  case 1647:
#line 7731 "fgl.yacc"
    {
sprintf(yyval.str,"%s.%s%s",yyvsp[-3].str,yyvsp[-1].str,yyvsp[0].str);
addmap("Use Column",yyval.str,curr_func,yylineno,infilename);
}
    break;

  case 1648:
#line 7736 "fgl.yacc"
    {
sprintf(yyval.str,"%s.%s",yyvsp[-2].str,yyvsp[0].str);
addmap("Use Column",yyval.str,curr_func,yylineno,infilename);
}
    break;

  case 1650:
#line 7747 "fgl.yacc"
    {
	strcpy(yyval.str,convstrsql(yyvsp[0].str));
 A4GL_debug("Set $<str>$ to %s\n",yyval.str);
}
    break;

  case 1654:
#line 7765 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1655:
#line 7768 "fgl.yacc"
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

  case 1656:
#line 7781 "fgl.yacc"
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

  case 1657:
#line 7796 "fgl.yacc"
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

  case 1658:
#line 7808 "fgl.yacc"
    {strcpy(yyval.str,"1,10");}
    break;

  case 1659:
#line 7810 "fgl.yacc"
    {sprintf(yyval.str," %s ,%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1660:
#line 7813 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 1661:
#line 7813 "fgl.yacc"
    {strcpy(yyval.str,"2");}
    break;

  case 1662:
#line 7813 "fgl.yacc"
    {strcpy(yyval.str,"3");}
    break;

  case 1663:
#line 7813 "fgl.yacc"
    {strcpy(yyval.str,"4");}
    break;

  case 1664:
#line 7813 "fgl.yacc"
    {strcpy(yyval.str,"5");}
    break;

  case 1665:
#line 7813 "fgl.yacc"
    {strcpy(yyval.str,"6");}
    break;

  case 1666:
#line 7814 "fgl.yacc"
    {
sprintf(yyval.str,"%d",6+2);
}
    break;

  case 1667:
#line 7817 "fgl.yacc"
    {
sprintf(yyval.str,"%d",atoi(yyvsp[-1].str)+6);
}
    break;

  case 1668:
#line 7822 "fgl.yacc"
    {strcpy(yyval.str,"4");}
    break;

  case 1669:
#line 7822 "fgl.yacc"
    {strcpy(yyval.str,"7");}
    break;

  case 1670:
#line 7822 "fgl.yacc"
    {strcpy(yyval.str,"10");}
    break;

  case 1671:
#line 7822 "fgl.yacc"
    {strcpy(yyval.str,"13");}
    break;

  case 1672:
#line 7822 "fgl.yacc"
    {strcpy(yyval.str,"16");}
    break;

  case 1673:
#line 7822 "fgl.yacc"
    {strcpy(yyval.str,"19");}
    break;

  case 1674:
#line 7824 "fgl.yacc"
    {
strcpy(yyval.str,"25");
}
    break;

  case 1675:
#line 7827 "fgl.yacc"
    {
strcpy(yyval.str,"25");
}
    break;

  case 1690:
#line 7834 "fgl.yacc"
    {sprintf(yyval.str,"FRACTION(%s)",yyvsp[-1].str);}
    break;

  case 1691:
#line 7837 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1692:
#line 7838 "fgl.yacc"
    {sprintf(yyval.str,"%s@%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1693:
#line 7839 "fgl.yacc"
    {strcpy(yyval.str, A4GL_strip_quotes (yyvsp[0].str));}
    break;

  case 1694:
#line 7843 "fgl.yacc"
    {
	print_flush_cursor(yyvsp[0].str);
		addmap("Flush Cursor",yyvsp[0].str,curr_func,yylineno,infilename);
print_undo_use(yyvsp[-2].str);
		}
    break;

  case 1695:
#line 7851 "fgl.yacc"
    {insql=0;chk4var=0;}
    break;

  case 1696:
#line 7851 "fgl.yacc"
    {
		print_declare("",yyvsp[-1].sql_string,yyvsp[-4].str,0,0);
		addmap("Declare Cursor",yyvsp[-4].str,curr_func,yylineno,infilename);
		print_undo_use(yyvsp[-6].str);
		doing_declare=0;
	}
    break;

  case 1697:
#line 7857 "fgl.yacc"
    {insql=0;chk4var=0;}
    break;

  case 1698:
#line 7857 "fgl.yacc"
    {
		print_declare("",yyvsp[-1].sql_string,yyvsp[-5].str,2,0); 
		addmap("Declare Cursor",yyvsp[-5].str,curr_func,yylineno,infilename);
		print_undo_use(yyvsp[-7].str);
		doing_declare=0;
	}
    break;

  case 1699:
#line 7864 "fgl.yacc"
    {insql=0;chk4var=0;}
    break;

  case 1700:
#line 7864 "fgl.yacc"
    {
		print_declare("",yyvsp[-1].sql_string,yyvsp[-3].str,0,1); 
		addmap("Declare Cursor",yyvsp[-3].str,curr_func,yylineno,infilename);
		print_undo_use(yyvsp[-5].str);
		doing_declare=0;
	}
    break;

  case 1701:
#line 7870 "fgl.yacc"
    {insql=0;chk4var=0;}
    break;

  case 1702:
#line 7870 "fgl.yacc"
    {
		print_declare("",yyvsp[-1].sql_string,yyvsp[-5].str,2,1); 
		addmap("Declare Cursor",yyvsp[-5].str,curr_func,yylineno,infilename);
		print_undo_use(yyvsp[-7].str);
		doing_declare=0;
	}
    break;

  case 1703:
#line 7878 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1704:
#line 7879 "fgl.yacc"
    {strcpy(yyval.str," FOR UPDATE");}
    break;

  case 1705:
#line 7880 "fgl.yacc"
    {sprintf(yyval.str," FOR UPDATE OF %s",yyvsp[0].str);}
    break;

  case 1706:
#line 7883 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1707:
#line 7883 "fgl.yacc"
    {sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1709:
#line 7887 "fgl.yacc"
    {sprintf(yyval.str,"%s.%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1710:
#line 7888 "fgl.yacc"
    {
			if (A4GL_escape_quote_owner()) {
				sprintf(yyval.str,"\\\"%s\\\".%s.%s", A4GL_strip_quotes (yyvsp[-4].str),yyvsp[-2].str,yyvsp[0].str);
			} else {
				sprintf(yyval.str,"\"%s\".%s.%s", A4GL_strip_quotes (yyvsp[-4].str),yyvsp[-2].str,yyvsp[0].str);
			}
	}
    break;

  case 1711:
#line 7899 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1712:
#line 7902 "fgl.yacc"
    { 
		yyval.sql_string=make_sql_string(print_curr_spec(1,yyvsp[0].sql_string),0);
	}
    break;

  case 1713:
#line 7908 "fgl.yacc"
    {
		start_bind('i',0);
		start_bind('o',0);
		yyval.sql_string=make_sql_string(print_curr_spec(2,yyvsp[0].str) ,0);
	}
    break;

  case 1714:
#line 7913 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1715:
#line 7921 "fgl.yacc"
    {
	yyval.sql_string=yyvsp[0].sql_string;
	if (strstr(yyvsp[0].str,"FOR UPDATE")) {
		printf("Warning SELECT ... FOR UPDATE when not declaring a cursor currently has no locking effect\n");
	}
}
    break;

  case 1716:
#line 7933 "fgl.yacc"
    { start_bind('i',0); }
    break;

  case 1717:
#line 7934 "fgl.yacc"
    {A4GL_debug("Got select list...\n");}
    break;

  case 1718:
#line 7937 "fgl.yacc"
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

  case 1719:
#line 7952 "fgl.yacc"
    {
		/*$<sql_string>$=make_sql_string("A4GL_push_char(\"", $<str>1, " ",$<str>2," ", $<sql_string>3, " ",$<sql_string>4, " ",$<sql_string>5, "\");",0); */
		yyval.sql_string=make_sql_string(yyvsp[-4].str, " ",yyvsp[-3].str," ", yyvsp[-2].sql_string, " ",yyvsp[-1].sql_string, " ",yyvsp[0].sql_string,0);
	free(yyvsp[-2].sql_string);
	free(yyvsp[-1].sql_string);
	free(yyvsp[0].sql_string);
}
    break;

  case 1720:
#line 7963 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	 }
    break;

  case 1721:
#line 7966 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1722:
#line 7974 "fgl.yacc"
    {
	yyval.sql_string=make_sql_string(yyvsp[-5].str, " ",yyvsp[-4].str," ",yyvsp[-3].sql_string," ", yyvsp[-2].sql_string," ", yyvsp[-1].sql_string, " ",yyvsp[0].sql_string,0);
	free(yyvsp[-3].sql_string);
	free(yyvsp[-1].sql_string);
	free(yyvsp[0].sql_string);
}
    break;

  case 1723:
#line 7983 "fgl.yacc"
    {
		yyval.sql_string=strdup("");
		}
    break;

  case 1724:
#line 7986 "fgl.yacc"
    {
       A4GL_lex_printcomment("/* UNION */");
	yyval.sql_string=make_sql_string(yyvsp[-2].str," ",yyvsp[-1].str," ",yyvsp[0].sql_string,0);
       }
    break;

  case 1725:
#line 7990 "fgl.yacc"
    {
	yyval.sql_string=strdup(yyvsp[0].str);
}
    break;

  case 1726:
#line 7993 "fgl.yacc"
    { yyval.sql_string=make_sql_string(yyvsp[-2].str," ",yyvsp[-1].str," ",yyvsp[0].str,0); }
    break;

  case 1727:
#line 7994 "fgl.yacc"
    { 
	if (A4GL_isyes(acl_getenv("A4GL_NO_ORDBY_INTO_TEMP"))) {
		yyval.sql_string=make_sql_string(yyvsp[-2].str," ",yyvsp[-1].str," ",yyvsp[0].str,0);
	} else {
		yyval.sql_string=make_sql_string(yyvsp[-3].str," ",yyvsp[-2].str," ",yyvsp[-1].str," ",yyvsp[0].str,0);
	}
}
    break;

  case 1729:
#line 8007 "fgl.yacc"
    { start_bind('o',0);yyval.sql_string=make_sql_string("",0); }
    break;

  case 1730:
#line 8008 "fgl.yacc"
    { 
		yyval.sql_string=make_sql_string(A4GL_get_into_part(doing_declare,get_bind_cnt('o')),0 ); 

	}
    break;

  case 1731:
#line 8017 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-3].str," ",yyvsp[-2].str," ", yyvsp[-1].sql_string," ",yyvsp[0].sql_string,0);
		free(yyvsp[-1].sql_string);
		//free($<sql_string>4);

	}
    break;

  case 1732:
#line 8026 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("(",yyvsp[-4].str," ",yyvsp[-3].str," ",yyvsp[-2].sql_string," ",yyvsp[-1].sql_string,")",0);
	}
    break;

  case 1733:
#line 8031 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1734:
#line 8032 "fgl.yacc"
    {strcpy(yyval.str,"ALL ");}
    break;

  case 1735:
#line 8033 "fgl.yacc"
    {strcpy(yyval.str," DISTINCT ");}
    break;

  case 1736:
#line 8034 "fgl.yacc"
    {strcpy(yyval.str," DISTINCT ");
		ansi_violation("Use DISTINCT not UNIQUE",0);
		strcpy(yyval.str," DISTINCT ");
}
    break;

  case 1737:
#line 8041 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1738:
#line 8044 "fgl.yacc"
    { 
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",",yyvsp[0].sql_string,0);
	}
    break;

  case 1739:
#line 8050 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1740:
#line 8053 "fgl.yacc"
    {
		if (A4GL_isyes(acl_getenv("A4GL_USE_ALIAS_AS"))) {
			yyval.sql_string=make_sql_string(yyvsp[-1].sql_string," AS ",yyvsp[0].str,0);
		} else {
			yyval.sql_string=make_sql_string(yyvsp[-1].sql_string," ",yyvsp[0].str,0);
		}
	}
    break;

  case 1741:
#line 8060 "fgl.yacc"
    {
		if (A4GL_isyes(acl_getenv("A4GL_USE_ALIAS_AS"))) {
			yyval.sql_string=make_sql_string(yyvsp[-2].sql_string," AS ",yyvsp[0].str,0);
		} else {
			yyval.sql_string=make_sql_string(yyvsp[-2].sql_string," ",yyvsp[0].str,0);
		}
	}
    break;

  case 1742:
#line 8072 "fgl.yacc"
    {
	yyval.sql_string=yyvsp[0].sql_string;
}
    break;

  case 1743:
#line 8081 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1744:
#line 8084 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("-",yyvsp[0].sql_string,0);
	}
    break;

  case 1745:
#line 8087 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("+",yyvsp[0].sql_string,0);
	}
    break;

  case 1746:
#line 8093 "fgl.yacc"
    {
			if (strlen(current_upd_table)) {
				push_gen(UPDVAL,yyvsp[0].sql_string);
			}
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1747:
#line 8099 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1748:
#line 8102 "fgl.yacc"
    { yyval.sql_string=yyvsp[0].sql_string; }
    break;

  case 1749:
#line 8103 "fgl.yacc"
    { yyval.sql_string=make_sql_string("ALL ",yyvsp[0].sql_string,0); }
    break;

  case 1750:
#line 8104 "fgl.yacc"
    { yyval.sql_string=make_sql_string("ANY ",yyvsp[0].sql_string,0); }
    break;

  case 1751:
#line 8105 "fgl.yacc"
    { yyval.sql_string=make_sql_string("SOME ",yyvsp[0].sql_string,0); }
    break;

  case 1752:
#line 8106 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1753:
#line 8109 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].str,".",yyvsp[0].str,0);
	}
    break;

  case 1754:
#line 8116 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,"/",yyvsp[0].sql_string,0);}
    break;

  case 1755:
#line 8118 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-1].sql_string," ",yyvsp[0].str,0);}
    break;

  case 1756:
#line 8120 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,"*",yyvsp[0].sql_string,0);}
    break;

  case 1757:
#line 8122 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,"+",yyvsp[0].sql_string,0);}
    break;

  case 1758:
#line 8124 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,"-",yyvsp[0].sql_string,0);}
    break;

  case 1759:
#line 8125 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[0].str,0);}
    break;

  case 1760:
#line 8126 "fgl.yacc"
    {yyval.sql_string=make_sql_string("1",0);}
    break;

  case 1761:
#line 8127 "fgl.yacc"
    {yyval.sql_string=make_sql_string("0",0);}
    break;

  case 1762:
#line 8128 "fgl.yacc"
    {yyval.sql_string=make_sql_string("USER",0);}
    break;

  case 1763:
#line 8129 "fgl.yacc"
    {yyval.sql_string=make_sql_string("*",0);}
    break;

  case 1764:
#line 8130 "fgl.yacc"
    {yyval.sql_string=make_sql_string("COUNT(*)",0);}
    break;

  case 1765:
#line 8132 "fgl.yacc"
    {yyval.sql_string=make_sql_string("AVG(",yyvsp[-2].str,yyvsp[-1].sql_string,")",0);}
    break;

  case 1766:
#line 8134 "fgl.yacc"
    {yyval.sql_string=make_sql_string("MAX(",yyvsp[-2].str,yyvsp[-1].sql_string,")",0);}
    break;

  case 1767:
#line 8136 "fgl.yacc"
    {yyval.sql_string=make_sql_string("MIN(",yyvsp[-2].str,yyvsp[-1].sql_string,")",0);}
    break;

  case 1768:
#line 8138 "fgl.yacc"
    {yyval.sql_string=make_sql_string("SUM(",yyvsp[-2].str,yyvsp[-1].sql_string,")",0);}
    break;

  case 1769:
#line 8140 "fgl.yacc"
    {yyval.sql_string=make_sql_string("COUNT(",yyvsp[-2].str,yyvsp[-1].sql_string,")",0);}
    break;

  case 1770:
#line 8142 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-3].str,"(",yyvsp[-1].sql_string,")",0);}
    break;

  case 1771:
#line 8144 "fgl.yacc"
    {yyval.sql_string=make_sql_string("DATE(",yyvsp[-1].sql_string,")",0);}
    break;

  case 1772:
#line 8145 "fgl.yacc"
    {yyval.sql_string=make_sql_string("(",yyvsp[-1].sql_string,")",0);}
    break;

  case 1773:
#line 8147 "fgl.yacc"
    {yyval.sql_string=make_sql_string("EXTEND(",yyvsp[-1].sql_string,")",0);}
    break;

  case 1774:
#line 8148 "fgl.yacc"
    { yyval.sql_string=make_sql_string(yyvsp[0].str,0);}
    break;

  case 1775:
#line 8149 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[0].str,0);}
    break;

  case 1776:
#line 8155 "fgl.yacc"
    {yyval.sql_string=yyvsp[0].sql_string;}
    break;

  case 1777:
#line 8156 "fgl.yacc"
    {
	yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",",yyvsp[0].sql_string,0);
}
    break;

  case 1779:
#line 8166 "fgl.yacc"
    {
print_unload(yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].sql_string);
print_undo_use(yyvsp[-4].str);
}
    break;

  case 1780:
#line 8174 "fgl.yacc"
    {
print_load(yyvsp[-4].str,yyvsp[-3].str,yyvsp[-1].str,yyvsp[0].str);
print_undo_use(yyvsp[-6].str);
}
    break;

  case 1781:
#line 8178 "fgl.yacc"
    {
print_load_str(yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);
print_undo_use(yyvsp[-4].str);
}
    break;

  case 1782:
#line 8185 "fgl.yacc"
    {strcpy(yyval.str,"\"|\"");}
    break;

  case 1783:
#line 8185 "fgl.yacc"
    {
strcpy(yyval.str,yyvsp[0].str);
}
    break;

  case 1785:
#line 8189 "fgl.yacc"
    {
		if ((scan_variable(yyvsp[0].str)&15)!=0) {a4gl_yyerror("Variable must be of type charr..");YYERROR;}
}
    break;

  case 1786:
#line 8194 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 1787:
#line 8194 "fgl.yacc"
    {
sprintf(yyval.str,"%s,0",yyvsp[-1].str);
}
    break;

  case 1789:
#line 8198 "fgl.yacc"
    {
    sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 1790:
#line 8202 "fgl.yacc"
    {
     sprintf(yyval.str,"\"%s\"",yyvsp[0].str);
}
    break;

  case 1793:
#line 8211 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1794:
#line 8211 "fgl.yacc"
    {
print_use_session(yyvsp[0].str);
strcpy(yyval.str,A4GL_get_undo_use());
}
    break;

  case 1799:
#line 8230 "fgl.yacc"
    { sprintf(yyval.str,"%s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str); }
    break;

  case 1800:
#line 8231 "fgl.yacc"
    { sprintf(yyval.str,"RENAME COLUMN  %s.%s TO %s",yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str); }
    break;

  case 1803:
#line 8239 "fgl.yacc"
    {
		sprintf(yyval.str,"%s %s",yyvsp[-1].str,yyvsp[0].str);
	}
    break;

  case 1804:
#line 8245 "fgl.yacc"
    {
		sprintf(yyval.str,"%s %s %s",
					yyvsp[-2].str,
					yyvsp[-1].str,
					yyvsp[0].str
					);
		}
    break;

  case 1807:
#line 8264 "fgl.yacc"
    {strcpy(yyval.str,"UNITS YEAR");}
    break;

  case 1808:
#line 8265 "fgl.yacc"
    {strcpy(yyval.str,"UNITS MONTH"); }
    break;

  case 1809:
#line 8266 "fgl.yacc"
    {strcpy(yyval.str,"UNITS DAY"); }
    break;

  case 1810:
#line 8267 "fgl.yacc"
    {strcpy(yyval.str,"UNITS HOUR"); }
    break;

  case 1811:
#line 8268 "fgl.yacc"
    {strcpy(yyval.str,"UNITS MINUTE"); }
    break;

  case 1812:
#line 8269 "fgl.yacc"
    {strcpy(yyval.str,"UNITS SECOND"); }
    break;

  case 1813:
#line 8273 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str," ",yyvsp[-1].str," ",yyvsp[0].str,0);}
    break;

  case 1814:
#line 8274 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-4].sql_string,yyvsp[-3].str,yyvsp[-2].str," ",yyvsp[-1].str," ",yyvsp[0].str,0);}
    break;

  case 1815:
#line 8275 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-3].str,yyvsp[-2].str," ",yyvsp[-1].str," ",yyvsp[0].str,0);}
    break;

  case 1817:
#line 8280 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1818:
#line 8281 "fgl.yacc"
    {sprintf(yyval.str,"%s %s TO %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1819:
#line 8285 "fgl.yacc"
    {sprintf(yyval.str,"%s",yyvsp[0].str);}
    break;

  case 1820:
#line 8301 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1821:
#line 8302 "fgl.yacc"
    {sprintf(yyval.str,"%s %s(%s) TO %s",yyvsp[-6].str,yyvsp[-5].str,yyvsp[-3].str,yyvsp[0].str);}
    break;

  case 1822:
#line 8303 "fgl.yacc"
    {sprintf(yyval.str,"%s %s TO %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1823:
#line 8307 "fgl.yacc"
    {sprintf(yyval.str,"%s",yyvsp[0].str);}
    break;

  case 1824:
#line 8321 "fgl.yacc"
    {
		sql_mode=1;
		start_bind('i',0);
		start_bind('o',0);
	}
    break;

  case 1825:
#line 8325 "fgl.yacc"
    {
			sql_mode=0;
			print_sql_block_cmd(yyvsp[-1].str);
	}
    break;

  case 1827:
#line 8334 "fgl.yacc"
    {sprintf(yyval.str,"%s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1829:
#line 8339 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1830:
#line 8340 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 2146:
#line 8664 "fgl.yacc"
    {sql_mode=0;}
    break;

  case 2147:
#line 8664 "fgl.yacc"
    {
		strcpy(yyval.str,yyvsp[0].sql_string);
		sql_mode=1;
	}
    break;

  case 2148:
#line 8671 "fgl.yacc"
    {sql_mode=0;}
    break;

  case 2149:
#line 8671 "fgl.yacc"
    {
 		strcpy(yyval.str,A4GL_get_into_part(doing_declare,get_bind_cnt('o')));
		sql_mode=1;
	}
    break;

  case 2150:
#line 8759 "fgl.yacc"
    {
		strcpy(current_upd_table,yyvsp[0].str);
		pop_all_gen(UPDCOL,"!"); pop_all_gen(UPDVAL,"!"); pop_all_gen(UPDVAL2,"!");
		yyval.sql_string=strdup("");
	}
    break;

  case 2151:
#line 8763 "fgl.yacc"
    {
		strcpy(current_upd_table,"");
	}
    break;

  case 2152:
#line 8765 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-5].str," ",yyvsp[-4].str," ",yyvsp[-2].sql_string," ",yyvsp[0].sql_string,0);
	}
    break;

  case 2153:
#line 8772 "fgl.yacc"
    {
		pop_all_gen(UPDCOL,"!"); pop_all_gen(UPDVAL,"!"); pop_all_gen(UPDVAL2,"!");
		yyval.sql_string=strdup("");
	}
    break;

  case 2154:
#line 8776 "fgl.yacc"
    { 
		pop_all_gen(UPDCOL,"!"); pop_all_gen(UPDVAL,"!"); pop_all_gen(UPDVAL2,"!");
		rm_quotes(yyvsp[0].str);
		sprintf(yyval.str,"%s %s",yyvsp[-1].str,yyvsp[0].str);
		yyval.sql_string=make_sql_string(yyval.str,0);
	}
    break;

  case 2155:
#line 8782 "fgl.yacc"
    {
		pop_all_gen(UPDCOL,"!"); pop_all_gen(UPDVAL,"!"); pop_all_gen(UPDVAL2,"!");
		yyval.sql_string=make_sql_string("WHERE ",yyvsp[0].sql_string,0);
	}
    break;

  case 2156:
#line 8790 "fgl.yacc"
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

  case 2157:
#line 8800 "fgl.yacc"
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

  case 2158:
#line 8810 "fgl.yacc"
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

  case 2159:
#line 8822 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("SET ",yyvsp[0].sql_string,0);
    }
    break;

  case 2160:
#line 8825 "fgl.yacc"
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

  case 2161:
#line 8844 "fgl.yacc"
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

  case 2162:
#line 8870 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 2163:
#line 8873 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",",yyvsp[0].sql_string,0);
	}
    break;

  case 2165:
#line 8882 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].str,"=",yyvsp[0].sql_string,0);
	}
    break;

  case 2166:
#line 8887 "fgl.yacc"
    {
			push_gen(UPDCOL,yyvsp[0].str); strcpy(yyval.str,yyvsp[0].str);
		}
    break;

  case 2167:
#line 8890 "fgl.yacc"
    {
			push_gen(UPDCOL,yyvsp[0].str); sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);
		}
    break;

  case 2168:
#line 8898 "fgl.yacc"
    { 
		yyval.sql_string=yyvsp[0].sql_string; 
		if (gen_cnt(UPDVAL2)) {
			copy_gen(UPDVAL,UPDVAL2);
		} else {
                	push_gen(UPDVAL,yyvsp[0].sql_string);
		}
	}
    break;

  case 2169:
#line 8906 "fgl.yacc"
    { 
		if (gen_cnt(UPDVAL2)) {
			copy_gen(UPDVAL,UPDVAL2);
		} else {
                	push_gen(UPDVAL,yyvsp[0].sql_string);
		}
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",",yyvsp[0].sql_string,0); 
	}
    break;

  case 2170:
#line 8919 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 2171:
#line 8922 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 2172:
#line 8930 "fgl.yacc"
    {
                yyval.sql_string=yyvsp[0].sql_string;
        }
    break;

  case 2173:
#line 8933 "fgl.yacc"
    {
                yyval.sql_string=make_sql_string("-",yyvsp[0].sql_string,0);
        }
    break;

  case 2174:
#line 8936 "fgl.yacc"
    {
                yyval.sql_string=make_sql_string("+",yyvsp[0].sql_string,0);
        }
    break;

  case 2175:
#line 8944 "fgl.yacc"
    { 
		
		yyval.sql_string=yyvsp[0].sql_string; 
	}
    break;

  case 2176:
#line 8948 "fgl.yacc"
    { yyval.sql_string=yyvsp[0].sql_string; }
    break;

  case 2177:
#line 8949 "fgl.yacc"
    { yyval.sql_string=strdup(yyvsp[0].str); }
    break;

  case 2178:
#line 8950 "fgl.yacc"
    { yyval.sql_string=make_sql_string(yyvsp[-2].str,".",yyvsp[0].str,0); }
    break;

  case 2179:
#line 8951 "fgl.yacc"
    { yyval.sql_string=make_sql_string(yyvsp[-3].str,"[",yyvsp[-1].str,"]",0); }
    break;

  case 2180:
#line 8952 "fgl.yacc"
    { yyval.sql_string=make_sql_string(yyvsp[-5].str,".",yyvsp[-3].str,"[",yyvsp[-1].str,"]",0); }
    break;

  case 2181:
#line 8953 "fgl.yacc"
    { yyval.sql_string=make_sql_string(yyvsp[-5].str,"[",yyvsp[-3].str,",",yyvsp[-1].str,"]",0); }
    break;

  case 2182:
#line 8954 "fgl.yacc"
    { yyval.sql_string=make_sql_string(yyvsp[-7].str,".",yyvsp[-5].str,"[",yyvsp[-3].str,",",yyvsp[-1].str,"]",0); }
    break;

  case 2183:
#line 8955 "fgl.yacc"
    { 
		yyval.sql_string=yyvsp[0].sql_string; 
		pop_all_gen(UPDVAL2,"!");
	}
    break;

  case 2184:
#line 8959 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[0].str,0);}
    break;

  case 2185:
#line 8960 "fgl.yacc"
    {yyval.sql_string=make_sql_string("TRUE",0);}
    break;

  case 2186:
#line 8961 "fgl.yacc"
    {yyval.sql_string=make_sql_string("FALSE",0);}
    break;

  case 2187:
#line 8962 "fgl.yacc"
    {yyval.sql_string=make_sql_string("USER",0);}
    break;

  case 2188:
#line 8963 "fgl.yacc"
    {yyval.sql_string=make_sql_string("COUNT(*)",0);}
    break;

  case 2189:
#line 8969 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,"/",yyvsp[0].sql_string,0);}
    break;

  case 2190:
#line 8970 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-1].sql_string,yyvsp[0].str,0);}
    break;

  case 2191:
#line 8971 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,"*",yyvsp[0].sql_string,0);}
    break;

  case 2192:
#line 8972 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,"+",yyvsp[0].sql_string,0);}
    break;

  case 2193:
#line 8973 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,"-",yyvsp[0].sql_string,0);}
    break;

  case 2194:
#line 8974 "fgl.yacc"
    {yyval.sql_string=make_sql_string("AVERAGE(",yyvsp[-2].str,yyvsp[-1].sql_string,")",0);}
    break;

  case 2195:
#line 8975 "fgl.yacc"
    {yyval.sql_string=make_sql_string("MAX(",yyvsp[-2].str,yyvsp[-1].sql_string,")",0);}
    break;

  case 2196:
#line 8976 "fgl.yacc"
    {yyval.sql_string=make_sql_string("MIN(",yyvsp[-2].str,yyvsp[-1].sql_string,")",0);}
    break;

  case 2197:
#line 8977 "fgl.yacc"
    {yyval.sql_string=make_sql_string("SUM(",yyvsp[-2].str,yyvsp[-1].sql_string,")",0);}
    break;

  case 2198:
#line 8978 "fgl.yacc"
    {yyval.sql_string=make_sql_string("COUNT(",yyvsp[-2].str,yyvsp[-1].sql_string,")",0);}
    break;

  case 2199:
#line 8979 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-3].str,"(",yyvsp[-1].sql_string,")",0);}
    break;

  case 2200:
#line 8980 "fgl.yacc"
    {yyval.sql_string=make_sql_string("DATE(",yyvsp[-1].sql_string,")",0);}
    break;

  case 2201:
#line 8981 "fgl.yacc"
    {yyval.sql_string=make_sql_string("(",yyvsp[-1].sql_string,")",0);}
    break;

  case 2202:
#line 8982 "fgl.yacc"
    {yyval.sql_string=make_sql_string("EXTEND(",yyvsp[-1].sql_string,")",0);}
    break;

  case 2203:
#line 8983 "fgl.yacc"
    { yyval.sql_string=make_sql_string(yyvsp[0].str,0);}
    break;

  case 2204:
#line 8984 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[0].str,0);}
    break;

  case 2205:
#line 8989 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
}
    break;

  case 2206:
#line 8995 "fgl.yacc"
    {yyval.sql_string=yyvsp[0].sql_string;}
    break;

  case 2207:
#line 8996 "fgl.yacc"
    {
        yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",",yyvsp[0].sql_string,0);
}
    break;

  case 2208:
#line 9004 "fgl.yacc"
    {
	clr_validate_list();
}
    break;

  case 2209:
#line 9006 "fgl.yacc"
    {
	print_validate();
}
    break;

  case 2211:
#line 9012 "fgl.yacc"
    {sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 2212:
#line 9016 "fgl.yacc"
    {
		sprintf(yyval.str,"%s.%s",yyvsp[-2].str,yyvsp[0].str);
		push_validate(yyval.str);
	}
    break;

  case 2213:
#line 9020 "fgl.yacc"
    {
		sprintf(yyval.str,"%s.*",yyvsp[-2].str);
		push_validate(yyval.str);
	}
    break;

  case 2214:
#line 9036 "fgl.yacc"
    {
	if (scan_variable(variable_usage_as_string(yyvsp[0].var_usg,VAR_USG_ANY))!=-1) {
		char buff[1024];
		sprintf(buff,"%s",fgl_add_scope(variable_usage_as_string(yyvsp[0].var_usg,VAR_USG_VARIABLE),0));
		print_push_variable(buff);
		strcpy(yyval.str,"?");
	} else {
		strcpy(yyval.str,variable_usage_as_string(yyvsp[0].var_usg,VAR_USG_IDENT));
	}

}
    break;

  case 2215:
#line 9050 "fgl.yacc"
    {
		strcpy(yyval.str,variable_usage_as_string(yyvsp[0].var_usg,VAR_USG_ANY));
	}
    break;

  case 2216:
#line 9056 "fgl.yacc"
    {
		yyval.var_usg=yyvsp[0].var_usg;
	}
    break;

  case 2217:
#line 9058 "fgl.yacc"
    {
		yyval.var_usg=yyvsp[0].var_usg;
	}
    break;

  case 2221:
#line 9072 "fgl.yacc"
    {
		yyval.var_usg=append_variable_usage(yyvsp[-2].var_usg,yyvsp[0].var_usg);
	}
    break;

  case 2222:
#line 9075 "fgl.yacc"
    {
		yyval.var_usg=new_variable_usage(yyvsp[-2].var_usg,"*",0);
	}
    break;

  case 2223:
#line 9082 "fgl.yacc"
    {
			yyval.var_usg=yyvsp[0].var_usg;
	}
    break;

  case 2224:
#line 9085 "fgl.yacc"
    { yyval.var_usg=new_variable_usage(0,yyvsp[0].str,0); }
    break;

  case 2225:
#line 9115 "fgl.yacc"
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

  case 2226:
#line 9140 "fgl.yacc"
    {
char buff[256];
char was_str[40000];
char lstr[1024];
int z = 0,a = 0;
strcpy(was_str,"");
printf("THRU : %s %s\n",yyvsp[-2].str,yyvsp[0].str);

A4GL_debug("Starting THRU");

sprintf(buff,"%s\n%s",yyvsp[-2].str,yyvsp[0].str);
a=get_bind_cnt('i');
printf("get_bind_cnt=%d\n",a);
z=add_bind('i',buff);
z-=a;

strcpy(was_str,A4GL_set_var_sql(doing_declare,z));
//for (a=0;a<z;a++)  {
         //if (strlen(was_str)) {strcat(was_str,",");}
	 //strcat(was_str,A4GL_set_var_sql(doing_declare,1));
//}



	/* split_record(buff,&v_r,&v_1,&v_2);

	v_loop=v_1;

	while (1) {
                //strcpy(kp,was_str);
                sprintf(buff,"%s.%s",r1,v_loop->names.name);

		if (scan_variable(buff)!=-1&&(!system_var(buff))) {
			a=get_bind_cnt('i');
			z=add_bind('i',buff);
			z-=a;
			if (strlen(was_str)) {strcat(was_str,",");}
			strcat(was_str,A4GL_set_var_sql(doing_declare,z));
        	}

		//for (a=0;a<z;a++)  {
			//if (strlen(was_str)) {strcat(was_str,",");}
         		//strcat(was_str,"?");
		//}
		v_loop=get_next_variable(v_r,v_loop,v_2);
	}
*/


yyval.sql_string=strdup(was_str);
}
    break;

  case 2227:
#line 9195 "fgl.yacc"
    {
  int type,arrsize,size,level;
  char arrbuff[256];
  struct num_list *array;
  struct num_list *substr;
  struct array_list *al;

  yyval.var_usg=new_variable_usage(0,yyvsp[-1].str,0);
  al=yyvsp[0].array_list;
  array=al->array;
  substr=al->substr;

  if (array) {
	int cnt;
	cnt=0;
	while (array) {
		set_variable_usage_subscript(yyval.var_usg,cnt,array->num);
		cnt++;
		array=array->next;
	}
  }

  if (substr) {
	int cnt;
	cnt=0;
	while (substr) {
		set_variable_usage_substr(yyval.var_usg,cnt,substr->num);
		cnt++;
		substr=substr->next;
	}
  }
}
    break;

  case 2228:
#line 9230 "fgl.yacc"
    {
		struct array_list *al;
         	A4GL_debug("---> Subscript or substring");
		al=malloc(sizeof(struct array_list));
		al->array=yyvsp[-1].num_list;
		al->substr=0;
		yyval.array_list=al;

        }
    break;

  case 2229:
#line 9239 "fgl.yacc"
    {
		struct array_list *al;
         	A4GL_debug("---> Subscript & substring");
		al=malloc(sizeof(struct array_list));
		al->array=yyvsp[-4].num_list;
		al->substr=yyvsp[-1].num_list;
		yyval.array_list=al;
        }
    break;

  case 2230:
#line 9250 "fgl.yacc"
    { 
			yyval.num_list=yyvsp[0].num_list; 
		}
    break;

  case 2231:
#line 9253 "fgl.yacc"
    { 
			yyval.num_list=append_num_list_items(yyvsp[-2].num_list,yyvsp[0].num_list); 
		}
    break;

  case 2232:
#line 9259 "fgl.yacc"
    {
  yyval.num_list=new_num_list_item(yyvsp[0].str);
}
    break;

  case 2233:
#line 9272 "fgl.yacc"
    {
		set_whenever_from_store();
}
    break;

  case 2234:
#line 9286 "fgl.yacc"
    {
print_while_1();
push_blockcommand("WHILE");
}
    break;

  case 2235:
#line 9289 "fgl.yacc"
    {
print_while_2();
}
    break;

  case 2236:
#line 9293 "fgl.yacc"
    {
print_while_3();
pop_blockcommand("WHILE");
}
    break;

  case 2237:
#line 9308 "fgl.yacc"
    {yyval.field_list=0;}
    break;

  case 2238:
#line 9308 "fgl.yacc"
    {
	yyval.field_list=yyvsp[0].field_list;
}
    break;

  case 2239:
#line 9314 "fgl.yacc"
    { strcpy(yyval.str,"0"); }
    break;

  case 2240:
#line 9315 "fgl.yacc"
    { strcpy(yyval.str,"1"); }
    break;

  case 2241:
#line 9318 "fgl.yacc"
    { print_current_window("\"screen\""); print_clr_window("\"screen\""); }
    break;

  case 2242:
#line 9319 "fgl.yacc"
    { print_clr_window(yyvsp[0].str); }
    break;

  case 2243:
#line 9320 "fgl.yacc"
    { print_clr_window(yyvsp[0].str); }
    break;

  case 2244:
#line 9321 "fgl.yacc"
    { print_clr_form(0,0,"0"); }
    break;

  case 2245:
#line 9322 "fgl.yacc"
    { print_clr_form(0,0,"1"); }
    break;

  case 2246:
#line 9323 "fgl.yacc"
    { print_clr_form(yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str); }
    break;

  case 2247:
#line 9324 "fgl.yacc"
    {
	print_clr_fields(field_name_list_as_char(yyvsp[-1].field_list),yyvsp[0].str);
}
    break;

  case 2248:
#line 9335 "fgl.yacc"
    {
	print_current_window("\"screen\"");
}
    break;

  case 2249:
#line 9339 "fgl.yacc"
    {
	print_current_window(yyvsp[0].str);
}
    break;

  case 2250:
#line 9343 "fgl.yacc"
    {
sprintf(yyval.str,"A4GL_cr_window");
reset_attrib(&form_attrib);
}
    break;

  case 2251:
#line 9347 "fgl.yacc"
    {
sprintf(yyval.str,"A4GL_cr_window_form");
reset_attrib(&form_attrib);
}
    break;

  case 2252:
#line 9352 "fgl.yacc"
    {
	print_show_window(yyvsp[0].str);
	addmap("Show Window",yyvsp[0].str,curr_func,yylineno,infilename); 
}
    break;

  case 2253:
#line 9356 "fgl.yacc"
    {
	print_show_menu(yyvsp[-3].str,yyvsp[-1].str);
	addmap("Call Menuhandler",yyvsp[-1].str,curr_func,yylineno,infilename); 
}
    break;

  case 2254:
#line 9361 "fgl.yacc"
    {

print_def_mn_file();

}
    break;

  case 2256:
#line 9369 "fgl.yacc"
    {addmap("Use Menu",yyvsp[0].str,curr_func,yylineno,infilename); }
    break;

  case 2258:
#line 9375 "fgl.yacc"
    {
	print_hide_window(yyvsp[0].str);
}
    break;

  case 2259:
#line 9381 "fgl.yacc"
    {
print_move_window(yyvsp[-4].str,0);
}
    break;

  case 2260:
#line 9385 "fgl.yacc"
    {
print_move_window(yyvsp[-4].str,1);
}
    break;

  case 2265:
#line 9403 "fgl.yacc"
    {
chk4var=0;A4GL_lex_printcomment("/* [Comm:%s] */\n",yyval.str);
if (A4GL_isyes(acl_getenv("INCLINES")))
A4GL_lex_printc("{A4GL_debug(\"Line %d %s:%s\");}",lastlineno,infilename,convstrsql(larr));
	A4GL_prchkerr(lastlineno,infilename);
	lastlineno=yylineno;
}
    break;

  case 2266:
#line 9410 "fgl.yacc"
    {
A4GL_lex_printcomment("/* [COMM:%s] */\n",yyvsp[0].str);chk4var=0;
if (A4GL_isyes(acl_getenv("INCLINES")))
A4GL_lex_printc("{A4GL_debug(\"Line %d %s:%s\");}",lastlineno,infilename,convstrsql(larr));
/* if (A4GL_aubit_strcasecmp($<str>$,"whenever")!=0)  */
A4GL_prchkerr(lastlineno,infilename);
lastlineno=yylineno;
}
    break;

  case 2267:
#line 9420 "fgl.yacc"
    {print_cmd_start();}
    break;

  case 2268:
#line 9420 "fgl.yacc"
    {print_cmd_end();}
    break;


    }

/* Line 991 of yacc.c.  */
#line 19358 "y.tab.c"

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


#line 999 "fgl.yacc"

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



