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
     NAME = 1704,
     UMINUS = 1705,
     COMMA = 1609,
     KW_OR = 1649,
     KW_AND = 1604,
     KW_USING = 1541,
     NOT = 1624,
     MATCHES = 1421,
     POWER = 1527,
     LESS_THAN = 1523,
     GREATER_THAN = 1438,
     EQUAL = 1599,
     GREATER_THAN_EQ = 1339,
     LESS_THAN_EQ = 1396,
     NOT_EQUAL = 1469,
     PLUS = 1635,
     MINUS = 1622,
     MULTIPLY = 1528,
     DIVIDE = 1555,
     MOD = 1623,
     COMMAND = 1403,
     NUMBER_VALUE = 1706,
     CHAR_VALUE = 1707,
     INT_VALUE = 1708,
     NAMED_GEN = 1709,
     CLINE = 1710,
     SQLLINE = 1711,
     KW_CSTART = 1712,
     KW_CEND = 1713,
     USER_DTYPE = 1714,
     SQL_TEXT = 1715,
     KW_WHENEVER_SET = 1716,
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
     ALTER_INDEX = 1017,
     NEXT_SIZE = 1018,
     WHENEVER_ERROR_CONTINUE = 1019,
     WHENEVER_ANY_ERROR_CONTINUE = 1020,
     WHENEVER_WARNING_CONTINUE = 1021,
     WHENEVER_SQLSUCCESS_CONTINUE = 1022,
     WHENEVER_SQLWARNING_CONTINUE = 1023,
     WHENEVER_NOT_FOUND_CONTINUE = 1024,
     WHENEVER_SQLERROR_CONTINUE = 1025,
     WHENEVER_SUCCESS_CONTINUE = 1026,
     WHENEVER_ERROR_GOTO = 1027,
     WHENEVER_ANY_ERROR_GOTO = 1028,
     WHENEVER_WARNING_GOTO = 1029,
     WHENEVER_SQLSUCCESS_GOTO = 1030,
     WHENEVER_SQLWARNING_GOTO = 1031,
     WHENEVER_NOT_FOUND_GOTO = 1032,
     WHENEVER_SQLERROR_GOTO = 1033,
     WHENEVER_SUCCESS_GOTO = 1034,
     WHENEVER_ERROR_CALL = 1035,
     WHENEVER_ANY_ERROR_CALL = 1036,
     WHENEVER_WARNING_CALL = 1037,
     WHENEVER_SQLSUCCESS_CALL = 1038,
     WHENEVER_SQLWARNING_CALL = 1039,
     WHENEVER_NOT_FOUND_CALL = 1040,
     WHENEVER_SQLERROR_CALL = 1041,
     WHENEVER_SUCCESS_CALL = 1042,
     WHENEVER_ERROR_STOP = 1043,
     WHENEVER_ANY_ERROR_STOP = 1044,
     WHENEVER_WARNING_STOP = 1045,
     WHENEVER_SQLSUCCESS_STOP = 1046,
     WHENEVER_SQLWARNING_STOP = 1047,
     WHENEVER_NOT_FOUND_STOP = 1048,
     WHENEVER_SQLERROR_STOP = 1049,
     WHENEVER_SUCCESS_STOP = 1050,
     XSET_MULTIPLY_EQUAL_OPEN_BRACKET = 1051,
     XSET_ident_DOT_MULTIPLY_EQUAL_OPEN_BRACKET = 1052,
     XSET_ident_DOT_MULTIPLY_EQUAL = 1053,
     XSET_MULTIPLY_EQUAL = 1054,
     XSET_OPEN_BRACKET = 1055,
     NEWFORMATSHARED = 1056,
     CREATE_DATABASE = 1057,
     DROP_DATABASE = 1058,
     IMPORT_LEGACY_FUNCTION = 1059,
     ADD_CONSTRAINT = 1060,
     DROP_CONSTRAINT = 1061,
     DROP_SYNONYM = 1062,
     CONSTRAINT = 1063,
     AS_STATIC = 1064,
     NOT_FIELD_TOUCHED = 1065,
     LOCAL_FUNCTION = 1066,
     EVERY_ROW = 1067,
     ELIF = 1068,
     DOUBLE_PRECISION = 1069,
     COUNT_MULTIPLY = 1070,
     WAIT_FOR_KEY = 1071,
     AT_TERMINATION_CALL = 1072,
     TERMINATE_REPORT = 1073,
     TO_MAIN_CAPTION = 1074,
     CLEARSTAT = 1075,
     TO_MENUITEM = 1076,
     ID_TO_INT = 1077,
     TO_STATUSBOX = 1078,
     ASCII_HEIGHT_ALL = 1079,
     ASCII_WIDTH_ALL = 1080,
     IMPORT_DATATYPE = 1081,
     PAGE_TRAILER_SIZE = 1082,
     PAGE_HEADER_SIZE = 1083,
     FIRST_PAGE_HEADER_SIZE = 1084,
     BYTES_USE_AS_IMAGE = 1085,
     BYTES_USE_AS_ASCII = 1086,
     KWUP_BY = 1087,
     KWDOWN_BY = 1088,
     CLOSE_STATUSBOX = 1089,
     MODIFY_NEXT_SIZE = 1090,
     LOCK_MODE_PAGE = 1091,
     LOCK_MODE_ROW = 1092,
     TO_PIPE = 1093,
     TO_PRINTER = 1094,
     STATUSBOX = 1095,
     CONNECT_TO = 1096,
     FORMHANDLER_INPUT = 1097,
     UNITS_YEAR = 1098,
     UNITS_MONTH = 1099,
     UNITS_DAY = 1100,
     UNITS_HOUR = 1101,
     UNITS_MINUTE = 1102,
     UNITS_SECOND = 1103,
     NO_NEW_LINES = 1104,
     FIELDTOWIDGET = 1105,
     WITH_HOLD = 1106,
     SHOW_MENU = 1107,
     TO_CLUSTER = 1108,
     TO_NOT_CLUSTER = 1109,
     CWIS = 1110,
     CREATE_IDX = 1111,
     FORM_IS_COMPILED = 1112,
     PDF_REPORT = 1113,
     IMPORT_FUNCTION = 1114,
     PROMPT_MANY = 1115,
     POINTS = 1116,
     MM = 1117,
     INCHES = 1118,
     PREPEND = 1119,
     MEMBER_OF = 1120,
     MEMBER_FUNCTION = 1121,
     APPEND = 1122,
     TEMPLATE = 1123,
     END_TEMPLATE = 1124,
     SQLSICS = 1125,
     CREATE_SCHEMA = 1126,
     SQLSIRR = 1127,
     UPDATESTATS_T = 1128,
     SQLSICR = 1129,
     WHENEVER_SQLSUCCESS = 1130,
     WHENEVER_SQLWARNING = 1131,
     WHENEVER_ANY_ERROR = 1132,
     WHENEVER_NOT_FOUND = 1133,
     WHENEVER_SQLERROR = 1134,
     WHENEVER_SUCCESS = 1135,
     WHENEVER_ERROR = 1136,
     START_EXTERN = 1137,
     CONTINUE_CONSTRUCT = 1138,
     FOUNCONSTR = 1139,
     SQLSIDR = 1140,
     CREATE_TEMP_TABLE = 1141,
     CURRENT_WINDOW_IS = 1142,
     FIRST_PAGE_HEADER = 1143,
     ORDER_EXTERNAL_BY = 1144,
     SCROLL_CURSOR_FOR = 1145,
     SCROLL_CURSOR = 1146,
     SQL_INTERRUPT_OFF = 1147,
     STOP_ALL_EXTERNAL = 1148,
     WITH_CHECK_OPTION = 1149,
     WITH_GRANT_OPTION = 1150,
     SQLSLMNW = 1151,
     ADDCONSTUNIQ = 1152,
     CONTINUE_DISPLAY = 1153,
     CONTINUE_FOREACH = 1154,
     OUTPUT_TO_REPORT = 1155,
     SQL_INTERRUPT_ON = 1156,
     WHERE_CURRENT_OF = 1157,
     WITHOUT_DEFAULTS = 1158,
     FOCONSTR = 1159,
     SCALED_BY = 1160,
     CONTINUE_PROMPT = 1161,
     PDF_FUNCTION = 1162,
     DEFER_INTERRUPT = 1163,
     DISPLAY_BY_NAME = 1164,
     NOT_NULL_UNIQUE = 1165,
     SKIP_TO_TOP = 1166,
     TOP_OF_PAGE = 1167,
     SKIP_TO = 1168,
     SKIP_BY = 1169,
     WITHOUT_WAITING = 1170,
     BEFCONSTRUCT = 1171,
     SQLSLMW = 1172,
     AFTCONSTRUCT = 1173,
     ALL_PRIVILEGES = 1174,
     CLOSE_DATABASE = 1175,
     CONTINUE_INPUT = 1176,
     CONTINUE_WHILE = 1177,
     CREATE_SYNONYM = 1178,
     DROP_TABLE = 1179,
     EXIT_CONSTRUCT = 1180,
     INEXCLUSIVE = 1181,
     REPORT_TO_PRINTER = 1182,
     REPORT_TO_PIPE = 1183,
     RETURN = 1184,
     SET_SESSION_TO = 1185,
     UPDATESTATS = 1186,
     WITHOUT_HEAD = 1187,
     CLEARSCR = 1188,
     WITH_B_LOG = 1189,
     AUTHORIZATION = 1190,
     BOTTOM_MARGIN = 1191,
     CLOSE_SESSION = 1192,
     CONTINUE_CASE = 1193,
     CONTINUE_MENU = 1194,
     DISPLAY_ARRAY = 1195,
     END_SQL = 1196,
     DOLLAR = 1197,
     END_CONSTRUCT = 1198,
     FIELD_TOUCHED = 1199,
     FINISH_REPORT = 1200,
     INFACC = 1201,
     INPUT_NO_WRAP = 1202,
     SETPMOFF = 1203,
     UNCONSTRAINED = 1204,
     PAGE_TRAILER = 1205,
     SETPMON = 1206,
     BEFGROUP = 1207,
     CLOSE_WINDOW = 1208,
     COMMENT_LINE = 1209,
     CONTINUE_FOR = 1210,
     CREATE_DB = 1211,
     CREATE_TABLE = 1212,
     DEFAULT_NULL = 1213,
     DEFAULT_TODAY = 1214,
     DEFAULT_USER = 1215,
     DELETE_USING = 1216,
     DISPLAY_FORM = 1217,
     END_FUNCTION = 1218,
     EXIT_DISPLAY = 1219,
     EXIT_FOREACH = 1220,
     EXIT_PROGRAM = 1221,
     INFCOLS = 1222,
     ON_EVERY_ROW = 1223,
     OPEN_SESSION = 1224,
     RIGHT_MARGIN = 1225,
     SELECT_USING = 1226,
     START_REPORT = 1227,
     UNLOCK_TABLE = 1228,
     UPDATE_USING = 1229,
     ACL_BUILTIN = 1230,
     AFTGROUP = 1231,
     INFIDX = 1232,
     INFSTAT = 1233,
     LEFT_MARGIN = 1234,
     PAGE_HEADER = 1235,
     ROLLBACK_W = 1236,
     SET_SESSION = 1237,
     SQLSEOFF = 1238,
     WITH_A_LOG = 1239,
     BEFDISP = 1240,
     BEFORE_MENU = 1241,
     CREATE_VIEW = 1242,
     DEFINE_TYPE = 1243,
     DELETE_FROM = 1244,
     END_DISPLAY = 1245,
     END_REPORT = 1246,
     END_FOREACH = 1247,
     END_FOR = 1248,
     END_GLOBALS = 1249,
     EXIT_PROMPT = 1250,
     EXTENT_SIZE = 1251,
     FOREIGN_KEY = 1252,
     HIDE_OPTION = 1253,
     HIDE_WINDOW = 1254,
     INSERT_INTO = 1255,
     IS_NOT_NULL = 1256,
     MOVE_WINDOW = 1257,
     NEXT_OPTION = 1258,
     NOT_MATCHES = 1259,
     ON_LAST_ROW = 1260,
     OPEN_WINDOW = 1261,
     OPEN_STATUSBOX = 1262,
     PAGE_LENGTH = 1263,
     PAGE_WIDTH = 1264,
     PRIMARY_KEY = 1265,
     PROMPT_LINE = 1266,
     RECORD_LIKE = 1267,
     ROLLFORWARD = 1268,
     SETBL = 1269,
     SHOW_OPTION = 1270,
     SHOW_WINDOW = 1271,
     SQLSEON = 1272,
     TO_DATABASE = 1273,
     USE_SESSION = 1274,
     WITH_NO_LOG = 1275,
     AFTDISP = 1276,
     BEFFIELD = 1277,
     INSHARE = 1278,
     UNLOCKTAB = 1279,
     AFTFIELD = 1280,
     ATTRIBUTES = 1281,
     BEFINP = 1282,
     BEGIN_WORK = 1283,
     CLEARWIN = 1284,
     CLOSE_FORM = 1285,
     DEFER_QUIT = 1286,
     DESCENDING = 1287,
     DROP_INDEX = 1288,
     END_PROMPT = 1289,
     END_RECORD = 1290,
     ERROR_LINE = 1291,
     EXIT_INPUT = 1292,
     EXIT_WHILE = 1293,
     FOR_UPDATE_OF = 1294,
     FOR_UPDATE = 1295,
     GET_FLDBUF = 1296,
     INITIALIZE = 1297,
     INPUT_WRAP = 1298,
     LOCK_TABLE = 1299,
     MSG_LINE = 1300,
     NOT_EXISTS = 1301,
     ON_ANY_KEY = 1302,
     REFERENCES = 1303,
     RENCOL = 1304,
     SET_CURSOR = 1305,
     SMALLFLOAT = 1306,
     SQLSUCCESS = 1307,
     TOP_MARGIN = 1308,
     WITH_ARRAY = 1309,
     ACCEPTKEY = 1310,
     ACCEPT = 1311,
     AFTINP = 1312,
     CLEARFORMTODEFAULTS = 1313,
     CLEARFORM = 1314,
     CLEAR_X_FORM = 1315,
     COMMIT_W = 1316,
     NEXTPAGE = 1317,
     PREVPAGE = 1318,
     CTRL_KEY = 1319,
     INFTABS = 1320,
     NEXTFIELD = 1321,
     NEXTFORM = 1322,
     RENTAB = 1323,
     ASCENDING = 1324,
     ASSOCIATE = 1325,
     CHAR = 1326,
     NCHAR = 1327,
     NVARCHAR = 1328,
     CONSTRUCT = 1329,
     DELIMITER = 1330,
     DOWNSHIFT = 1331,
     DROP_VIEW = 1332,
     END_INPUT = 1333,
     END_WHILE = 1334,
     EXCLUSIVE = 1335,
     EXIT_CASE = 1336,
     EXIT_MENU = 1337,
     FORM_LINE = 1338,
     INTERRUPT = 1340,
     INTO_TEMP = 1341,
     INVISIBLE = 1342,
     IN_MEMORY = 1343,
     LINKED_TO = 1344,
     LOAD_FROM = 1345,
     LOCKTAB = 1346,
     MENU_LINE = 1347,
     OPEN_FORM = 1348,
     OTHERWISE = 1349,
     PRECISION = 1350,
     PRIOR = 1351,
     PROCEDURE = 1352,
     REPORT_TO = 1353,
     RETURNING = 1354,
     UNDERLINE = 1355,
     UNLOAD_TO = 1356,
     BEFROW = 1357,
     UNLOAD_T = 1358,
     VARIABLE = 1359,
     ABSOLUTE = 1360,
     AFTROW = 1361,
     BUFFERED = 1362,
     CONSTANT = 1363,
     CONST = 1364,
     DATABASE = 1365,
     DATETIME = 1366,
     DEFAULTS = 1367,
     DISTINCT = 1368,
     END_CASE = 1369,
     END_MAIN = 1370,
     END_MENU = 1371,
     END_TYPE = 1372,
     EXIT_FOR = 1373,
     EXTERNAL = 1374,
     FRACTION = 1375,
     FUNCTION = 1376,
     GROUP_BY = 1377,
     INTERVAL = 1378,
     KWMESSAGE = 1379,
     NOT_LIKE = 1380,
     NOT_ILIKE = 1381,
     NOT_NULL = 1382,
     PASSWORD = 1383,
     PREVIOUS = 1384,
     READONLY = 1385,
     REGISTER = 1386,
     RELATIVE = 1387,
     RESOURCE = 1388,
     SMALLINT = 1389,
     VALIDATE = 1390,
     WITH_LOG = 1391,
     WORDWRAP = 1392,
     BY_NAME = 1393,
     IN_FILE = 1394,
     IS_NULL = 1395,
     AVERAGE = 1397,
     BETWEEN = 1398,
     CAPTION = 1399,
     CLIPPED = 1400,
     CLOSE_BRACKET = 1401,
     COLUMNS = 1402,
     COMMENT = 1404,
     CONNECT = 1405,
     CURRENT = 1406,
     DBYNAME = 1407,
     DECIMAL = 1408,
     DECLARE = 1409,
     DEFAULT = 1410,
     DISPLAY = 1411,
     ENDCODE = 1412,
     EXECUTE = 1413,
     FOREACH = 1414,
     FOREIGN = 1415,
     GLOBALS = 1416,
     INFIELD = 1417,
     INTEGER = 1418,
     KWWINDOW = 1419,
     MAGENTA = 1420,
     OPTIONS = 1422,
     PERCENT = 1423,
     PREPARE = 1424,
     PROGRAM = 1425,
     RECOVER = 1426,
     REVERSE = 1427,
     SECTION = 1428,
     SESSION = 1429,
     SYNONYM = 1430,
     THRU = 1431,
     TRAILER = 1432,
     UPSHIFT = 1433,
     VARCHAR = 1434,
     WAITING = 1435,
     CLOSE_SHEV = 1436,
     CLOSE_SQUARE = 1437,
     KW_FALSE = 1439,
     NOT_IN = 1440,
     ONKEY = 1441,
     OPEN_BRACKET = 1442,
     BORDER = 1443,
     BOTTOM = 1444,
     COLUMN = 1445,
     COMMIT = 1446,
     CREATE = 1447,
     CURSOR = 1448,
     DEFINE = 1449,
     DELETE = 1450,
     DOUBLE = 1451,
     END_IF = 1452,
     ESCAPE = 1453,
     EXISTS = 1454,
     EXTEND = 1455,
     EXTENT = 1456,
     FINISH = 1457,
     FORMAT = 1458,
     HAVING = 1459,
     HEADER = 1460,
     INSERT = 1461,
     LOCATE = 1462,
     MARGIN = 1463,
     MEMORY = 1464,
     MINUTE = 1465,
     MODIFY = 1466,
     NORMAL = 1467,
     EQUAL_EQUAL = 1468,
     OPEN_SHEV = 1470,
     OPEN_SQUARE = 1471,
     OPTION = 1472,
     OUTPUT = 1473,
     PROMPT = 1474,
     PUBLIC = 1475,
     RECORD = 1476,
     REPORT = 1477,
     REVOKE = 1478,
     SCHEMA = 1479,
     SCROLL_USING = 1480,
     SCROLL = 1481,
     SECOND = 1482,
     SELECT = 1483,
     SERIAL = 1484,
     SETL = 1485,
     SHARED = 1486,
     SPACES = 1487,
     UNIQUE = 1488,
     UNLOCK = 1489,
     UPDATE = 1490,
     VALUES = 1491,
     YELLOW = 1492,
     AFTER = 1493,
     KWLINE = 1494,
     KW_NULL = 1495,
     KW_TRUE = 1496,
     SINGLE_KEY = 1497,
     ALTER = 1498,
     ARRAY = 1499,
     ASCII = 1500,
     AUDIT = 1501,
     BLACK = 1502,
     BLINK = 1503,
     CHECK = 1504,
     CLEAR = 1505,
     CLOSE = 1506,
     CODE_C = 1507,
     COUNT = 1508,
     DEFER = 1509,
     ERROR = 1510,
     EVERY = 1511,
     FETCH = 1512,
     FIRST = 1513,
     FLOAT = 1514,
     FLUSH = 1515,
     FOUND = 1516,
     GRANT = 1517,
     GREEN = 1518,
     GROUP = 1519,
     INDEX = 1520,
     KWFORM = 1521,
     LABEL = 1522,
     LOCAL = 1524,
     MONEY = 1525,
     MONTH = 1526,
     ORDER = 1529,
     OUTER = 1530,
     PAUSE = 1531,
     PRINT_IMAGE = 1532,
     PRINT_FILE = 1533,
     PRINT = 1534,
     RIGHT = 1535,
     DOUBLE_COLON = 1536,
     SEMICOLON = 1537,
     SLEEP = 1538,
     TUPLE = 1539,
     UNION = 1540,
     WHERE = 1542,
     WHILE = 1543,
     WHITE = 1544,
     CCODE = 1545,
     ANSI = 1546,
     BLUE = 1547,
     BOLD = 1548,
     BYTE = 1549,
     FCALL = 1550,
     CASE = 1551,
     CYAN = 1552,
     DATE = 1553,
     DESC = 1554,
     KWDOWN = 1556,
     TAB = 1557,
     DROP = 1558,
     ELSE = 1559,
     EXEC = 1560,
     EXIT = 1561,
     FREE = 1562,
     FROM = 1563,
     GOTO = 1564,
     HELP_FILE = 1565,
     LANG_FILE = 1566,
     HELP = 1567,
     HIDE = 1568,
     HOUR = 1569,
     INTO = 1570,
     LAST = 1571,
     LEFT = 1572,
     LIKE = 1573,
     MAIN = 1574,
     MENU = 1575,
     MODE = 1576,
     NEED = 1577,
     NEXT = 1578,
     NOCR = 1579,
     OPEN = 1580,
     QUIT = 1581,
     REAL = 1582,
     ROWS = 1583,
     SHOW = 1584,
     SIZE = 1585,
     SKIP = 1586,
     SOME = 1587,
     STEP = 1588,
     STOP = 1589,
     TEMP = 1590,
     TEXT = 1591,
     THEN = 1592,
     USER = 1593,
     WAIT = 1594,
     WHEN = 1595,
     WITH = 1596,
     WORK = 1597,
     YEAR = 1598,
     KW_IS = 1600,
     XSET = 1601,
     ADD = 1602,
     ALL = 1603,
     ANY = 1605,
     ASC = 1606,
     AVG = 1607,
     COLON = 1608,
     DAY = 1610,
     DBA = 1611,
     DEC = 1612,
     DIM = 1613,
     FKEY = 1614,
     FOR = 1615,
     KEY = 1616,
     KWNO = 1617,
     LET = 1618,
     LOG = 1619,
     XMAX = 1620,
     XMIN = 1621,
     PAD = 1625,
     PUT = 1626,
     RED = 1627,
     ROW = 1628,
     RUN = 1629,
     SQL = 1630,
     SUM = 1631,
     TOP = 1632,
     USE = 1633,
     ATSIGN = 1634,
     AS_TIFF = 1636,
     AS_GIF = 1637,
     AS_PNG = 1638,
     AS_JPEG = 1639,
     AS = 1640,
     AT = 1641,
     BY = 1642,
     DOT = 1643,
     GO = 1644,
     IF = 1645,
     IN = 1646,
     OF = 1647,
     ON = 1648,
     TO = 1650,
     KWUP = 1651,
     FONT_NAME = 1652,
     FONT_SIZE = 1653,
     PAPER_SIZE_IS_LETTER = 1654,
     PAPER_SIZE_IS_LEGAL = 1655,
     PAPER_SIZE_IS_A5 = 1656,
     PAPER_SIZE_IS_A4 = 1657,
     PAPER_SIZE_IS_LETTER_L = 1658,
     PAPER_SIZE_IS_LEGAL_L = 1659,
     PAPER_SIZE_IS_A5_L = 1660,
     PAPER_SIZE_IS_A4_L = 1661,
     FORMHANDLER = 1662,
     END_FORMHANDLER = 1663,
     BEFORE_EVENT = 1664,
     BEFORE_OPEN_FORM = 1665,
     AFTER_EVENT = 1666,
     BEFORE_CLOSE_FORM = 1667,
     BEFORE_ANY = 1668,
     AFTER_ANY = 1669,
     MENUHANDLER = 1670,
     END_MENUHANDLER = 1671,
     BEFORE_SHOW_MENU = 1672,
     DISABLE_PROGRAM = 1673,
     DISABLE_ALL = 1674,
     BUTTONS = 1675,
     CHECK_MENUITEM = 1676,
     DISABLE_FORM = 1677,
     DISABLE_MENUITEMS = 1678,
     DISABLE = 1679,
     ENABLE_FORM = 1680,
     ENABLE_MENUITEMS = 1681,
     ENABLE = 1682,
     KWFIELD = 1683,
     ICON = 1684,
     MESSAGEBOX = 1685,
     TO_DEFAULTS = 1686,
     UNCHECK_MENUITEM = 1687,
     BEFORE = 1688,
     INPUT = 1689,
     END = 1690,
     INT_TO_ID = 1691,
     TIMEOUT = 1692,
     OFF = 1693,
     WITH_1_DIMENSION = 1694,
     WITH_2_DIMENSION = 1695,
     WITH_3_DIMENSION = 1696,
     TILDE = 1697,
     ILIKE = 1698,
     DROP_TRIGGER = 1699,
     FGL_ISDYNARR_ALLOCATED = 1700,
     FGL_DYNARR_EXTENTSIZE = 1701,
     FILLFACTOR = 1702
   };
#endif
#define NAME 1704
#define UMINUS 1705
#define COMMA 1609
#define KW_OR 1649
#define KW_AND 1604
#define KW_USING 1541
#define NOT 1624
#define MATCHES 1421
#define POWER 1527
#define LESS_THAN 1523
#define GREATER_THAN 1438
#define EQUAL 1599
#define GREATER_THAN_EQ 1339
#define LESS_THAN_EQ 1396
#define NOT_EQUAL 1469
#define PLUS 1635
#define MINUS 1622
#define MULTIPLY 1528
#define DIVIDE 1555
#define MOD 1623
#define COMMAND 1403
#define NUMBER_VALUE 1706
#define CHAR_VALUE 1707
#define INT_VALUE 1708
#define NAMED_GEN 1709
#define CLINE 1710
#define SQLLINE 1711
#define KW_CSTART 1712
#define KW_CEND 1713
#define USER_DTYPE 1714
#define SQL_TEXT 1715
#define KW_WHENEVER_SET 1716
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
#define ALTER_INDEX 1017
#define NEXT_SIZE 1018
#define WHENEVER_ERROR_CONTINUE 1019
#define WHENEVER_ANY_ERROR_CONTINUE 1020
#define WHENEVER_WARNING_CONTINUE 1021
#define WHENEVER_SQLSUCCESS_CONTINUE 1022
#define WHENEVER_SQLWARNING_CONTINUE 1023
#define WHENEVER_NOT_FOUND_CONTINUE 1024
#define WHENEVER_SQLERROR_CONTINUE 1025
#define WHENEVER_SUCCESS_CONTINUE 1026
#define WHENEVER_ERROR_GOTO 1027
#define WHENEVER_ANY_ERROR_GOTO 1028
#define WHENEVER_WARNING_GOTO 1029
#define WHENEVER_SQLSUCCESS_GOTO 1030
#define WHENEVER_SQLWARNING_GOTO 1031
#define WHENEVER_NOT_FOUND_GOTO 1032
#define WHENEVER_SQLERROR_GOTO 1033
#define WHENEVER_SUCCESS_GOTO 1034
#define WHENEVER_ERROR_CALL 1035
#define WHENEVER_ANY_ERROR_CALL 1036
#define WHENEVER_WARNING_CALL 1037
#define WHENEVER_SQLSUCCESS_CALL 1038
#define WHENEVER_SQLWARNING_CALL 1039
#define WHENEVER_NOT_FOUND_CALL 1040
#define WHENEVER_SQLERROR_CALL 1041
#define WHENEVER_SUCCESS_CALL 1042
#define WHENEVER_ERROR_STOP 1043
#define WHENEVER_ANY_ERROR_STOP 1044
#define WHENEVER_WARNING_STOP 1045
#define WHENEVER_SQLSUCCESS_STOP 1046
#define WHENEVER_SQLWARNING_STOP 1047
#define WHENEVER_NOT_FOUND_STOP 1048
#define WHENEVER_SQLERROR_STOP 1049
#define WHENEVER_SUCCESS_STOP 1050
#define XSET_MULTIPLY_EQUAL_OPEN_BRACKET 1051
#define XSET_ident_DOT_MULTIPLY_EQUAL_OPEN_BRACKET 1052
#define XSET_ident_DOT_MULTIPLY_EQUAL 1053
#define XSET_MULTIPLY_EQUAL 1054
#define XSET_OPEN_BRACKET 1055
#define NEWFORMATSHARED 1056
#define CREATE_DATABASE 1057
#define DROP_DATABASE 1058
#define IMPORT_LEGACY_FUNCTION 1059
#define ADD_CONSTRAINT 1060
#define DROP_CONSTRAINT 1061
#define DROP_SYNONYM 1062
#define CONSTRAINT 1063
#define AS_STATIC 1064
#define NOT_FIELD_TOUCHED 1065
#define LOCAL_FUNCTION 1066
#define EVERY_ROW 1067
#define ELIF 1068
#define DOUBLE_PRECISION 1069
#define COUNT_MULTIPLY 1070
#define WAIT_FOR_KEY 1071
#define AT_TERMINATION_CALL 1072
#define TERMINATE_REPORT 1073
#define TO_MAIN_CAPTION 1074
#define CLEARSTAT 1075
#define TO_MENUITEM 1076
#define ID_TO_INT 1077
#define TO_STATUSBOX 1078
#define ASCII_HEIGHT_ALL 1079
#define ASCII_WIDTH_ALL 1080
#define IMPORT_DATATYPE 1081
#define PAGE_TRAILER_SIZE 1082
#define PAGE_HEADER_SIZE 1083
#define FIRST_PAGE_HEADER_SIZE 1084
#define BYTES_USE_AS_IMAGE 1085
#define BYTES_USE_AS_ASCII 1086
#define KWUP_BY 1087
#define KWDOWN_BY 1088
#define CLOSE_STATUSBOX 1089
#define MODIFY_NEXT_SIZE 1090
#define LOCK_MODE_PAGE 1091
#define LOCK_MODE_ROW 1092
#define TO_PIPE 1093
#define TO_PRINTER 1094
#define STATUSBOX 1095
#define CONNECT_TO 1096
#define FORMHANDLER_INPUT 1097
#define UNITS_YEAR 1098
#define UNITS_MONTH 1099
#define UNITS_DAY 1100
#define UNITS_HOUR 1101
#define UNITS_MINUTE 1102
#define UNITS_SECOND 1103
#define NO_NEW_LINES 1104
#define FIELDTOWIDGET 1105
#define WITH_HOLD 1106
#define SHOW_MENU 1107
#define TO_CLUSTER 1108
#define TO_NOT_CLUSTER 1109
#define CWIS 1110
#define CREATE_IDX 1111
#define FORM_IS_COMPILED 1112
#define PDF_REPORT 1113
#define IMPORT_FUNCTION 1114
#define PROMPT_MANY 1115
#define POINTS 1116
#define MM 1117
#define INCHES 1118
#define PREPEND 1119
#define MEMBER_OF 1120
#define MEMBER_FUNCTION 1121
#define APPEND 1122
#define TEMPLATE 1123
#define END_TEMPLATE 1124
#define SQLSICS 1125
#define CREATE_SCHEMA 1126
#define SQLSIRR 1127
#define UPDATESTATS_T 1128
#define SQLSICR 1129
#define WHENEVER_SQLSUCCESS 1130
#define WHENEVER_SQLWARNING 1131
#define WHENEVER_ANY_ERROR 1132
#define WHENEVER_NOT_FOUND 1133
#define WHENEVER_SQLERROR 1134
#define WHENEVER_SUCCESS 1135
#define WHENEVER_ERROR 1136
#define START_EXTERN 1137
#define CONTINUE_CONSTRUCT 1138
#define FOUNCONSTR 1139
#define SQLSIDR 1140
#define CREATE_TEMP_TABLE 1141
#define CURRENT_WINDOW_IS 1142
#define FIRST_PAGE_HEADER 1143
#define ORDER_EXTERNAL_BY 1144
#define SCROLL_CURSOR_FOR 1145
#define SCROLL_CURSOR 1146
#define SQL_INTERRUPT_OFF 1147
#define STOP_ALL_EXTERNAL 1148
#define WITH_CHECK_OPTION 1149
#define WITH_GRANT_OPTION 1150
#define SQLSLMNW 1151
#define ADDCONSTUNIQ 1152
#define CONTINUE_DISPLAY 1153
#define CONTINUE_FOREACH 1154
#define OUTPUT_TO_REPORT 1155
#define SQL_INTERRUPT_ON 1156
#define WHERE_CURRENT_OF 1157
#define WITHOUT_DEFAULTS 1158
#define FOCONSTR 1159
#define SCALED_BY 1160
#define CONTINUE_PROMPT 1161
#define PDF_FUNCTION 1162
#define DEFER_INTERRUPT 1163
#define DISPLAY_BY_NAME 1164
#define NOT_NULL_UNIQUE 1165
#define SKIP_TO_TOP 1166
#define TOP_OF_PAGE 1167
#define SKIP_TO 1168
#define SKIP_BY 1169
#define WITHOUT_WAITING 1170
#define BEFCONSTRUCT 1171
#define SQLSLMW 1172
#define AFTCONSTRUCT 1173
#define ALL_PRIVILEGES 1174
#define CLOSE_DATABASE 1175
#define CONTINUE_INPUT 1176
#define CONTINUE_WHILE 1177
#define CREATE_SYNONYM 1178
#define DROP_TABLE 1179
#define EXIT_CONSTRUCT 1180
#define INEXCLUSIVE 1181
#define REPORT_TO_PRINTER 1182
#define REPORT_TO_PIPE 1183
#define RETURN 1184
#define SET_SESSION_TO 1185
#define UPDATESTATS 1186
#define WITHOUT_HEAD 1187
#define CLEARSCR 1188
#define WITH_B_LOG 1189
#define AUTHORIZATION 1190
#define BOTTOM_MARGIN 1191
#define CLOSE_SESSION 1192
#define CONTINUE_CASE 1193
#define CONTINUE_MENU 1194
#define DISPLAY_ARRAY 1195
#define END_SQL 1196
#define DOLLAR 1197
#define END_CONSTRUCT 1198
#define FIELD_TOUCHED 1199
#define FINISH_REPORT 1200
#define INFACC 1201
#define INPUT_NO_WRAP 1202
#define SETPMOFF 1203
#define UNCONSTRAINED 1204
#define PAGE_TRAILER 1205
#define SETPMON 1206
#define BEFGROUP 1207
#define CLOSE_WINDOW 1208
#define COMMENT_LINE 1209
#define CONTINUE_FOR 1210
#define CREATE_DB 1211
#define CREATE_TABLE 1212
#define DEFAULT_NULL 1213
#define DEFAULT_TODAY 1214
#define DEFAULT_USER 1215
#define DELETE_USING 1216
#define DISPLAY_FORM 1217
#define END_FUNCTION 1218
#define EXIT_DISPLAY 1219
#define EXIT_FOREACH 1220
#define EXIT_PROGRAM 1221
#define INFCOLS 1222
#define ON_EVERY_ROW 1223
#define OPEN_SESSION 1224
#define RIGHT_MARGIN 1225
#define SELECT_USING 1226
#define START_REPORT 1227
#define UNLOCK_TABLE 1228
#define UPDATE_USING 1229
#define ACL_BUILTIN 1230
#define AFTGROUP 1231
#define INFIDX 1232
#define INFSTAT 1233
#define LEFT_MARGIN 1234
#define PAGE_HEADER 1235
#define ROLLBACK_W 1236
#define SET_SESSION 1237
#define SQLSEOFF 1238
#define WITH_A_LOG 1239
#define BEFDISP 1240
#define BEFORE_MENU 1241
#define CREATE_VIEW 1242
#define DEFINE_TYPE 1243
#define DELETE_FROM 1244
#define END_DISPLAY 1245
#define END_REPORT 1246
#define END_FOREACH 1247
#define END_FOR 1248
#define END_GLOBALS 1249
#define EXIT_PROMPT 1250
#define EXTENT_SIZE 1251
#define FOREIGN_KEY 1252
#define HIDE_OPTION 1253
#define HIDE_WINDOW 1254
#define INSERT_INTO 1255
#define IS_NOT_NULL 1256
#define MOVE_WINDOW 1257
#define NEXT_OPTION 1258
#define NOT_MATCHES 1259
#define ON_LAST_ROW 1260
#define OPEN_WINDOW 1261
#define OPEN_STATUSBOX 1262
#define PAGE_LENGTH 1263
#define PAGE_WIDTH 1264
#define PRIMARY_KEY 1265
#define PROMPT_LINE 1266
#define RECORD_LIKE 1267
#define ROLLFORWARD 1268
#define SETBL 1269
#define SHOW_OPTION 1270
#define SHOW_WINDOW 1271
#define SQLSEON 1272
#define TO_DATABASE 1273
#define USE_SESSION 1274
#define WITH_NO_LOG 1275
#define AFTDISP 1276
#define BEFFIELD 1277
#define INSHARE 1278
#define UNLOCKTAB 1279
#define AFTFIELD 1280
#define ATTRIBUTES 1281
#define BEFINP 1282
#define BEGIN_WORK 1283
#define CLEARWIN 1284
#define CLOSE_FORM 1285
#define DEFER_QUIT 1286
#define DESCENDING 1287
#define DROP_INDEX 1288
#define END_PROMPT 1289
#define END_RECORD 1290
#define ERROR_LINE 1291
#define EXIT_INPUT 1292
#define EXIT_WHILE 1293
#define FOR_UPDATE_OF 1294
#define FOR_UPDATE 1295
#define GET_FLDBUF 1296
#define INITIALIZE 1297
#define INPUT_WRAP 1298
#define LOCK_TABLE 1299
#define MSG_LINE 1300
#define NOT_EXISTS 1301
#define ON_ANY_KEY 1302
#define REFERENCES 1303
#define RENCOL 1304
#define SET_CURSOR 1305
#define SMALLFLOAT 1306
#define SQLSUCCESS 1307
#define TOP_MARGIN 1308
#define WITH_ARRAY 1309
#define ACCEPTKEY 1310
#define ACCEPT 1311
#define AFTINP 1312
#define CLEARFORMTODEFAULTS 1313
#define CLEARFORM 1314
#define CLEAR_X_FORM 1315
#define COMMIT_W 1316
#define NEXTPAGE 1317
#define PREVPAGE 1318
#define CTRL_KEY 1319
#define INFTABS 1320
#define NEXTFIELD 1321
#define NEXTFORM 1322
#define RENTAB 1323
#define ASCENDING 1324
#define ASSOCIATE 1325
#define CHAR 1326
#define NCHAR 1327
#define NVARCHAR 1328
#define CONSTRUCT 1329
#define DELIMITER 1330
#define DOWNSHIFT 1331
#define DROP_VIEW 1332
#define END_INPUT 1333
#define END_WHILE 1334
#define EXCLUSIVE 1335
#define EXIT_CASE 1336
#define EXIT_MENU 1337
#define FORM_LINE 1338
#define INTERRUPT 1340
#define INTO_TEMP 1341
#define INVISIBLE 1342
#define IN_MEMORY 1343
#define LINKED_TO 1344
#define LOAD_FROM 1345
#define LOCKTAB 1346
#define MENU_LINE 1347
#define OPEN_FORM 1348
#define OTHERWISE 1349
#define PRECISION 1350
#define PRIOR 1351
#define PROCEDURE 1352
#define REPORT_TO 1353
#define RETURNING 1354
#define UNDERLINE 1355
#define UNLOAD_TO 1356
#define BEFROW 1357
#define UNLOAD_T 1358
#define VARIABLE 1359
#define ABSOLUTE 1360
#define AFTROW 1361
#define BUFFERED 1362
#define CONSTANT 1363
#define CONST 1364
#define DATABASE 1365
#define DATETIME 1366
#define DEFAULTS 1367
#define DISTINCT 1368
#define END_CASE 1369
#define END_MAIN 1370
#define END_MENU 1371
#define END_TYPE 1372
#define EXIT_FOR 1373
#define EXTERNAL 1374
#define FRACTION 1375
#define FUNCTION 1376
#define GROUP_BY 1377
#define INTERVAL 1378
#define KWMESSAGE 1379
#define NOT_LIKE 1380
#define NOT_ILIKE 1381
#define NOT_NULL 1382
#define PASSWORD 1383
#define PREVIOUS 1384
#define READONLY 1385
#define REGISTER 1386
#define RELATIVE 1387
#define RESOURCE 1388
#define SMALLINT 1389
#define VALIDATE 1390
#define WITH_LOG 1391
#define WORDWRAP 1392
#define BY_NAME 1393
#define IN_FILE 1394
#define IS_NULL 1395
#define AVERAGE 1397
#define BETWEEN 1398
#define CAPTION 1399
#define CLIPPED 1400
#define CLOSE_BRACKET 1401
#define COLUMNS 1402
#define COMMENT 1404
#define CONNECT 1405
#define CURRENT 1406
#define DBYNAME 1407
#define DECIMAL 1408
#define DECLARE 1409
#define DEFAULT 1410
#define DISPLAY 1411
#define ENDCODE 1412
#define EXECUTE 1413
#define FOREACH 1414
#define FOREIGN 1415
#define GLOBALS 1416
#define INFIELD 1417
#define INTEGER 1418
#define KWWINDOW 1419
#define MAGENTA 1420
#define OPTIONS 1422
#define PERCENT 1423
#define PREPARE 1424
#define PROGRAM 1425
#define RECOVER 1426
#define REVERSE 1427
#define SECTION 1428
#define SESSION 1429
#define SYNONYM 1430
#define THRU 1431
#define TRAILER 1432
#define UPSHIFT 1433
#define VARCHAR 1434
#define WAITING 1435
#define CLOSE_SHEV 1436
#define CLOSE_SQUARE 1437
#define KW_FALSE 1439
#define NOT_IN 1440
#define ONKEY 1441
#define OPEN_BRACKET 1442
#define BORDER 1443
#define BOTTOM 1444
#define COLUMN 1445
#define COMMIT 1446
#define CREATE 1447
#define CURSOR 1448
#define DEFINE 1449
#define DELETE 1450
#define DOUBLE 1451
#define END_IF 1452
#define ESCAPE 1453
#define EXISTS 1454
#define EXTEND 1455
#define EXTENT 1456
#define FINISH 1457
#define FORMAT 1458
#define HAVING 1459
#define HEADER 1460
#define INSERT 1461
#define LOCATE 1462
#define MARGIN 1463
#define MEMORY 1464
#define MINUTE 1465
#define MODIFY 1466
#define NORMAL 1467
#define EQUAL_EQUAL 1468
#define OPEN_SHEV 1470
#define OPEN_SQUARE 1471
#define OPTION 1472
#define OUTPUT 1473
#define PROMPT 1474
#define PUBLIC 1475
#define RECORD 1476
#define REPORT 1477
#define REVOKE 1478
#define SCHEMA 1479
#define SCROLL_USING 1480
#define SCROLL 1481
#define SECOND 1482
#define SELECT 1483
#define SERIAL 1484
#define SETL 1485
#define SHARED 1486
#define SPACES 1487
#define UNIQUE 1488
#define UNLOCK 1489
#define UPDATE 1490
#define VALUES 1491
#define YELLOW 1492
#define AFTER 1493
#define KWLINE 1494
#define KW_NULL 1495
#define KW_TRUE 1496
#define SINGLE_KEY 1497
#define ALTER 1498
#define ARRAY 1499
#define ASCII 1500
#define AUDIT 1501
#define BLACK 1502
#define BLINK 1503
#define CHECK 1504
#define CLEAR 1505
#define CLOSE 1506
#define CODE_C 1507
#define COUNT 1508
#define DEFER 1509
#define ERROR 1510
#define EVERY 1511
#define FETCH 1512
#define FIRST 1513
#define FLOAT 1514
#define FLUSH 1515
#define FOUND 1516
#define GRANT 1517
#define GREEN 1518
#define GROUP 1519
#define INDEX 1520
#define KWFORM 1521
#define LABEL 1522
#define LOCAL 1524
#define MONEY 1525
#define MONTH 1526
#define ORDER 1529
#define OUTER 1530
#define PAUSE 1531
#define PRINT_IMAGE 1532
#define PRINT_FILE 1533
#define PRINT 1534
#define RIGHT 1535
#define DOUBLE_COLON 1536
#define SEMICOLON 1537
#define SLEEP 1538
#define TUPLE 1539
#define UNION 1540
#define WHERE 1542
#define WHILE 1543
#define WHITE 1544
#define CCODE 1545
#define ANSI 1546
#define BLUE 1547
#define BOLD 1548
#define BYTE 1549
#define FCALL 1550
#define CASE 1551
#define CYAN 1552
#define DATE 1553
#define DESC 1554
#define KWDOWN 1556
#define TAB 1557
#define DROP 1558
#define ELSE 1559
#define EXEC 1560
#define EXIT 1561
#define FREE 1562
#define FROM 1563
#define GOTO 1564
#define HELP_FILE 1565
#define LANG_FILE 1566
#define HELP 1567
#define HIDE 1568
#define HOUR 1569
#define INTO 1570
#define LAST 1571
#define LEFT 1572
#define LIKE 1573
#define MAIN 1574
#define MENU 1575
#define MODE 1576
#define NEED 1577
#define NEXT 1578
#define NOCR 1579
#define OPEN 1580
#define QUIT 1581
#define REAL 1582
#define ROWS 1583
#define SHOW 1584
#define SIZE 1585
#define SKIP 1586
#define SOME 1587
#define STEP 1588
#define STOP 1589
#define TEMP 1590
#define TEXT 1591
#define THEN 1592
#define USER 1593
#define WAIT 1594
#define WHEN 1595
#define WITH 1596
#define WORK 1597
#define YEAR 1598
#define KW_IS 1600
#define XSET 1601
#define ADD 1602
#define ALL 1603
#define ANY 1605
#define ASC 1606
#define AVG 1607
#define COLON 1608
#define DAY 1610
#define DBA 1611
#define DEC 1612
#define DIM 1613
#define FKEY 1614
#define FOR 1615
#define KEY 1616
#define KWNO 1617
#define LET 1618
#define LOG 1619
#define XMAX 1620
#define XMIN 1621
#define PAD 1625
#define PUT 1626
#define RED 1627
#define ROW 1628
#define RUN 1629
#define SQL 1630
#define SUM 1631
#define TOP 1632
#define USE 1633
#define ATSIGN 1634
#define AS_TIFF 1636
#define AS_GIF 1637
#define AS_PNG 1638
#define AS_JPEG 1639
#define AS 1640
#define AT 1641
#define BY 1642
#define DOT 1643
#define GO 1644
#define IF 1645
#define IN 1646
#define OF 1647
#define ON 1648
#define TO 1650
#define KWUP 1651
#define FONT_NAME 1652
#define FONT_SIZE 1653
#define PAPER_SIZE_IS_LETTER 1654
#define PAPER_SIZE_IS_LEGAL 1655
#define PAPER_SIZE_IS_A5 1656
#define PAPER_SIZE_IS_A4 1657
#define PAPER_SIZE_IS_LETTER_L 1658
#define PAPER_SIZE_IS_LEGAL_L 1659
#define PAPER_SIZE_IS_A5_L 1660
#define PAPER_SIZE_IS_A4_L 1661
#define FORMHANDLER 1662
#define END_FORMHANDLER 1663
#define BEFORE_EVENT 1664
#define BEFORE_OPEN_FORM 1665
#define AFTER_EVENT 1666
#define BEFORE_CLOSE_FORM 1667
#define BEFORE_ANY 1668
#define AFTER_ANY 1669
#define MENUHANDLER 1670
#define END_MENUHANDLER 1671
#define BEFORE_SHOW_MENU 1672
#define DISABLE_PROGRAM 1673
#define DISABLE_ALL 1674
#define BUTTONS 1675
#define CHECK_MENUITEM 1676
#define DISABLE_FORM 1677
#define DISABLE_MENUITEMS 1678
#define DISABLE 1679
#define ENABLE_FORM 1680
#define ENABLE_MENUITEMS 1681
#define ENABLE 1682
#define KWFIELD 1683
#define ICON 1684
#define MESSAGEBOX 1685
#define TO_DEFAULTS 1686
#define UNCHECK_MENUITEM 1687
#define BEFORE 1688
#define INPUT 1689
#define END 1690
#define INT_TO_ID 1691
#define TIMEOUT 1692
#define OFF 1693
#define WITH_1_DIMENSION 1694
#define WITH_2_DIMENSION 1695
#define WITH_3_DIMENSION 1696
#define TILDE 1697
#define ILIKE 1698
#define DROP_TRIGGER 1699
#define FGL_ISDYNARR_ALLOCATED 1700
#define FGL_DYNARR_EXTENTSIZE 1701
#define FILLFACTOR 1702




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
#line 213 "fgl.yacc"
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
	int 	integer_val;
	float 	float_val;
	} YYSTYPE;
/* Line 191 of yacc.c.  */
#line 1686 "y.tab.c"
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 214 of yacc.c.  */
#line 1698 "y.tab.c"

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
#define YYLAST   10082

/* YYNTOKENS -- Number of terminals. */
#define YYNTOKENS  719
/* YYNNTS -- Number of nonterminals. */
#define YYNNTS  854
/* YYNRULES -- Number of rules. */
#define YYNRULES  2293
/* YYNRULES -- Number of states. */
#define YYNSTATES  3618

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   1716

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
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,   193,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
     255,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,   331,   332,   333,   334,
     335,   336,   337,   338,   339,   340,   341,   342,   343,   344,
     345,   346,   347,   348,   349,   350,   351,   352,   353,   354,
     355,   356,   357,   358,   359,   360,   361,   362,   363,   364,
     365,   366,   367,   368,   369,   370,   371,   372,   373,    15,
     374,   375,   376,   377,   378,   379,   380,   381,   382,   383,
     384,   385,   386,   387,   388,   389,   390,   391,   392,   393,
     394,   395,   396,   397,   398,   399,   400,   401,   402,   403,
     404,   405,   406,   407,   408,   409,   410,   411,   412,   413,
     414,   415,   416,   417,   418,   419,   420,   421,   422,   423,
     424,   425,   426,   427,   428,   429,    16,   430,   431,   432,
     433,   434,   435,    23,   436,   437,   438,   439,   440,   441,
     442,   443,   444,   445,   446,   447,   448,   449,   450,   451,
     452,    10,   453,   454,   455,   456,   457,   458,   459,   460,
     461,   462,   463,   464,   465,   466,   467,   468,    13,   469,
     470,   471,   472,   473,   474,   475,   476,   477,   478,   479,
     480,   481,   482,   483,   484,   485,   486,   487,   488,   489,
     490,   491,   492,   493,   494,   495,   496,   497,   498,    17,
     499,   500,   501,   502,   503,   504,   505,   506,   507,   508,
     509,   510,   511,   512,   513,   514,   515,   516,   517,   518,
     519,   520,   521,   522,   523,   524,   525,   526,   527,   528,
     529,   530,   531,   532,   533,   534,   535,   536,   537,   538,
     539,   540,   541,   542,   543,   544,   545,   546,   547,   548,
     549,   550,   551,    12,   552,   553,   554,    11,    20,   555,
     556,   557,   558,   559,   560,   561,   562,   563,   564,   565,
     566,     8,   567,   568,   569,   570,   571,   572,   573,   574,
     575,   576,   577,   578,   579,    21,   580,   581,   582,   583,
     584,   585,   586,   587,   588,   589,   590,   591,   592,   593,
     594,   595,   596,   597,   598,   599,   600,   601,   602,   603,
     604,   605,   606,   607,   608,   609,   610,   611,   612,   613,
     614,   615,   616,   617,   618,   619,   620,   621,   622,    14,
     623,   624,   625,   626,     7,   627,   628,   629,   630,     5,
     631,   632,   633,   634,   635,   636,   637,   638,   639,   640,
     641,   642,    19,    22,     9,   643,   644,   645,   646,   647,
     648,   649,   650,   651,   652,    18,   653,   654,   655,   656,
     657,   658,   659,   660,   661,   662,   663,   664,   665,     6,
     666,   667,   668,   669,   670,   671,   672,   673,   674,   675,
     676,   677,   678,   679,   680,   681,   682,   683,   684,   685,
     686,   687,   688,   689,   690,   691,   692,   693,   694,   695,
     696,   697,   698,   699,   700,   701,   702,   703,   704,   705,
     706,   707,   708,   709,   710,   711,   712,   713,   714,   715,
     716,   717,   718,     2,     3,     4,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34
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
     511,   512,   513,   519,   521,   523,   527,   528,   531,   536,
     541,   546,   551,   554,   555,   560,   562,   564,   566,   569,
     571,   573,   577,   578,   580,   581,   583,   585,   587,   588,
     596,   597,   603,   604,   617,   619,   621,   623,   625,   627,
     633,   637,   639,   641,   642,   647,   648,   654,   655,   663,
     665,   669,   671,   673,   674,   676,   677,   678,   683,   685,
     687,   689,   694,   699,   706,   708,   711,   713,   715,   717,
     719,   724,   731,   733,   738,   745,   746,   750,   751,   755,
     756,   760,   762,   764,   766,   768,   770,   773,   776,   778,
     780,   781,   785,   790,   792,   794,   795,   799,   803,   804,
     807,   809,   811,   813,   815,   817,   819,   822,   823,   826,
     827,   831,   832,   836,   838,   839,   843,   845,   847,   849,
     851,   853,   855,   858,   860,   861,   863,   864,   870,   872,
     874,   876,   881,   886,   893,   895,   897,   899,   901,   906,
     913,   915,   920,   927,   929,   931,   933,   935,   937,   940,
     943,   945,   950,   951,   959,   960,   973,   974,   979,   980,
     986,   988,   992,   995,   997,  1001,  1003,  1004,  1007,  1010,
    1012,  1015,  1021,  1026,  1029,  1034,  1040,  1044,  1045,  1046,
    1058,  1059,  1062,  1064,  1065,  1068,  1070,  1072,  1075,  1076,
    1080,  1081,  1085,  1086,  1090,  1093,  1096,  1099,  1104,  1110,
    1112,  1115,  1117,  1119,  1121,  1123,  1125,  1127,  1129,  1131,
    1133,  1135,  1137,  1139,  1141,  1143,  1145,  1147,  1149,  1151,
    1153,  1155,  1157,  1160,  1162,  1164,  1166,  1169,  1172,  1174,
    1176,  1178,  1180,  1182,  1184,  1186,  1188,  1190,  1192,  1195,
    1197,  1200,  1202,  1204,  1206,  1210,  1212,  1216,  1218,  1222,
    1224,  1226,  1228,  1231,  1233,  1235,  1239,  1244,  1249,  1252,
    1255,  1257,  1259,  1261,  1263,  1265,  1269,  1271,  1274,  1277,
    1279,  1280,  1284,  1287,  1290,  1292,  1296,  1301,  1306,  1312,
    1318,  1320,  1322,  1325,  1328,  1333,  1338,  1341,  1344,  1349,
    1354,  1356,  1359,  1362,  1365,  1368,  1371,  1374,  1377,  1380,
    1383,  1386,  1389,  1392,  1395,  1398,  1399,  1400,  1401,  1408,
    1409,  1410,  1419,  1420,  1421,  1428,  1429,  1430,  1437,  1438,
    1439,  1446,  1447,  1448,  1455,  1461,  1467,  1473,  1481,  1486,
    1493,  1494,  1498,  1500,  1502,  1507,  1512,  1517,  1522,  1527,
    1532,  1534,  1536,  1538,  1540,  1545,  1550,  1553,  1556,  1559,
    1562,  1565,  1567,  1569,  1572,  1574,  1576,  1578,  1581,  1586,
    1593,  1600,  1604,  1610,  1616,  1620,  1622,  1624,  1628,  1630,
    1634,  1636,  1640,  1641,  1642,  1643,  1653,  1654,  1658,  1659,
    1660,  1671,  1672,  1674,  1675,  1677,  1679,  1682,  1683,  1687,
    1688,  1692,  1693,  1695,  1697,  1700,  1701,  1705,  1706,  1710,
    1714,  1716,  1721,  1725,  1727,  1731,  1733,  1737,  1739,  1743,
    1745,  1748,  1749,  1753,  1754,  1758,  1759,  1764,  1765,  1770,
    1771,  1776,  1777,  1778,  1790,  1791,  1794,  1797,  1801,  1803,
    1807,  1809,  1811,  1813,  1815,  1817,  1819,  1821,  1825,  1827,
    1829,  1834,  1841,  1846,  1850,  1857,  1861,  1868,  1870,  1872,
    1874,  1876,  1878,  1880,  1882,  1884,  1885,  1888,  1890,  1892,
    1894,  1899,  1901,  1903,  1905,  1910,  1914,  1921,  1925,  1932,
    1934,  1936,  1939,  1942,  1944,  1947,  1950,  1952,  1956,  1958,
    1961,  1964,  1967,  1972,  1975,  1978,  1983,  1984,  1993,  1994,
    1996,  1998,  2000,  2001,  2003,  2006,  2007,  2009,  2012,  2013,
    2015,  2018,  2019,  2021,  2025,  2026,  2029,  2030,  2031,  2040,
    2041,  2042,  2046,  2047,  2048,  2056,  2062,  2065,  2068,  2069,
    2075,  2080,  2082,  2086,  2090,  2094,  2096,  2097,  2100,  2102,
    2103,  2105,  2107,  2110,  2111,  2116,  2117,  2122,  2123,  2127,
    2128,  2132,  2133,  2137,  2138,  2142,  2143,  2147,  2148,  2152,
    2153,  2157,  2158,  2162,  2163,  2167,  2169,  2173,  2175,  2179,
    2182,  2187,  2189,  2191,  2193,  2194,  2199,  2205,  2212,  2213,
    2224,  2228,  2231,  2234,  2236,  2238,  2239,  2242,  2244,  2247,
    2251,  2255,  2259,  2263,  2265,  2267,  2269,  2271,  2272,  2276,
    2278,  2279,  2283,  2286,  2289,  2291,  2295,  2297,  2301,  2303,
    2305,  2307,  2309,  2311,  2313,  2315,  2317,  2319,  2321,  2323,
    2325,  2327,  2329,  2331,  2333,  2335,  2337,  2339,  2341,  2342,
    2343,  2351,  2353,  2355,  2358,  2361,  2364,  2368,  2373,  2374,
    2378,  2379,  2381,  2383,  2386,  2388,  2390,  2392,  2394,  2396,
    2398,  2399,  2401,  2403,  2406,  2409,  2411,  2413,  2415,  2417,
    2419,  2421,  2423,  2425,  2427,  2429,  2431,  2433,  2434,  2436,
    2438,  2440,  2442,  2443,  2444,  2445,  2446,  2460,  2462,  2463,
    2464,  2471,  2474,  2476,  2479,  2482,  2485,  2487,  2489,  2492,
    2494,  2495,  2499,  2502,  2504,  2506,  2508,  2509,  2510,  2511,
    2526,  2527,  2528,  2536,  2538,  2541,  2542,  2546,  2547,  2552,
    2553,  2559,  2561,  2562,  2566,  2567,  2575,  2576,  2582,  2584,
    2587,  2588,  2590,  2592,  2594,  2595,  2597,  2599,  2602,  2605,
    2608,  2610,  2612,  2614,  2616,  2620,  2622,  2624,  2627,  2628,
    2631,  2633,  2635,  2637,  2639,  2641,  2643,  2645,  2649,  2650,
    2652,  2654,  2656,  2658,  2661,  2664,  2667,  2673,  2682,  2684,
    2686,  2688,  2693,  2698,  2700,  2702,  2704,  2706,  2709,  2712,
    2716,  2723,  2725,  2729,  2731,  2733,  2735,  2739,  2746,  2756,
    2758,  2760,  2762,  2764,  2767,  2768,  2770,  2772,  2776,  2778,
    2782,  2784,  2788,  2790,  2794,  2796,  2798,  2800,  2802,  2806,
    2808,  2812,  2814,  2818,  2820,  2822,  2824,  2828,  2831,  2832,
    2834,  2836,  2841,  2843,  2847,  2849,  2853,  2861,  2862,  2870,
    2871,  2878,  2882,  2884,  2888,  2890,  2893,  2899,  2900,  2908,
    2909,  2912,  2913,  2915,  2921,  2924,  2930,  2931,  2937,  2944,
    2949,  2950,  2952,  2954,  2959,  2960,  2963,  2964,  2970,  2975,
    2978,  2980,  2984,  2987,  2990,  2993,  2996,  2999,  3002,  3004,
    3007,  3010,  3013,  3016,  3019,  3022,  3025,  3028,  3031,  3033,
    3035,  3037,  3039,  3041,  3043,  3049,  3051,  3053,  3056,  3061,
    3064,  3066,  3067,  3079,  3080,  3083,  3089,  3090,  3092,  3093,
    3096,  3098,  3101,  3102,  3106,  3108,  3109,  3114,  3115,  3118,
    3120,  3124,  3126,  3128,  3132,  3137,  3142,  3145,  3147,  3149,
    3151,  3152,  3154,  3162,  3165,  3168,  3171,  3174,  3177,  3179,
    3182,  3183,  3187,  3188,  3192,  3193,  3197,  3198,  3202,  3203,
    3207,  3208,  3213,  3214,  3219,  3221,  3223,  3225,  3227,  3229,
    3231,  3232,  3237,  3238,  3240,  3241,  3246,  3248,  3251,  3254,
    3257,  3258,  3260,  3262,  3265,  3268,  3269,  3272,  3273,  3278,
    3282,  3288,  3289,  3292,  3297,  3299,  3301,  3303,  3305,  3307,
    3308,  3310,  3312,  3316,  3319,  3325,  3328,  3334,  3340,  3346,
    3352,  3358,  3364,  3365,  3368,  3370,  3373,  3376,  3379,  3382,
    3385,  3388,  3390,  3393,  3396,  3399,  3402,  3404,  3407,  3410,
    3413,  3416,  3418,  3420,  3422,  3423,  3426,  3429,  3432,  3435,
    3438,  3441,  3444,  3447,  3450,  3452,  3454,  3456,  3458,  3460,
    3462,  3464,  3466,  3469,  3472,  3475,  3478,  3481,  3483,  3485,
    3487,  3488,  3492,  3495,  3496,  3497,  3498,  3499,  3500,  3501,
    3517,  3518,  3521,  3524,  3525,  3527,  3528,  3529,  3530,  3531,
    3532,  3533,  3549,  3552,  3553,  3554,  3555,  3566,  3567,  3569,
    3573,  3577,  3580,  3585,  3589,  3593,  3597,  3599,  3602,  3605,
    3608,  3611,  3613,  3615,  3616,  3617,  3626,  3627,  3628,  3638,
    3639,  3641,  3643,  3646,  3649,  3652,  3655,  3657,  3659,  3661,
    3662,  3664,  3666,  3669,  3672,  3675,  3684,  3687,  3690,  3695,
    3698,  3699,  3701,  3703,  3707,  3710,  3713,  3715,  3717,  3721,
    3723,  3725,  3728,  3730,  3734,  3738,  3742,  3744,  3748,  3750,
    3752,  3754,  3756,  3758,  3760,  3762,  3765,  3770,  3772,  3776,
    3778,  3782,  3785,  3790,  3792,  3796,  3798,  3801,  3806,  3808,
    3812,  3814,  3816,  3818,  3821,  3825,  3830,  3833,  3838,  3839,
    3842,  3845,  3850,  3852,  3856,  3858,  3860,  3862,  3865,  3867,
    3869,  3871,  3873,  3875,  3878,  3885,  3892,  3893,  3895,  3896,
    3898,  3901,  3903,  3904,  3910,  3911,  3917,  3919,  3920,  3924,
    3926,  3930,  3932,  3936,  3938,  3940,  3941,  3946,  3948,  3951,
    3953,  3954,  3955,  3959,  3960,  3961,  3965,  3967,  3969,  3971,
    3973,  3975,  3977,  3980,  3983,  3988,  3992,  3996,  3998,  4002,
    4005,  4007,  4009,  4010,  4012,  4014,  4016,  4018,  4019,  4021,
    4025,  4027,  4031,  4033,  4034,  4038,  4040,  4042,  4044,  4046,
    4048,  4050,  4052,  4054,  4056,  4058,  4060,  4062,  4070,  4071,
    4073,  4075,  4077,  4079,  4083,  4085,  4087,  4089,  4092,  4093,
    4097,  4099,  4103,  4105,  4109,  4111,  4113,  4120,  4121,  4125,
    4127,  4131,  4132,  4134,  4139,  4145,  4148,  4150,  4152,  4157,
    4159,  4163,  4168,  4173,  4178,  4180,  4184,  4186,  4188,  4190,
    4193,  4195,  4197,  4199,  4204,  4205,  4207,  4208,  4210,  4212,
    4215,  4218,  4220,  4222,  4224,  4226,  4228,  4233,  4235,  4239,
    4241,  4243,  4245,  4248,  4250,  4252,  4255,  4258,  4260,  4264,
    4267,  4270,  4272,  4276,  4278,  4281,  4286,  4288,  4291,  4293,
    4297,  4302,  4303,  4305,  4306,  4308,  4309,  4311,  4313,  4317,
    4319,  4323,  4325,  4328,  4330,  4334,  4337,  4340,  4341,  4344,
    4346,  4348,  4354,  4358,  4364,  4368,  4370,  4374,  4376,  4378,
    4379,  4381,  4385,  4389,  4393,  4400,  4405,  4410,  4415,  4420,
    4426,  4428,  4430,  4432,  4434,  4436,  4438,  4440,  4442,  4444,
    4446,  4448,  4450,  4451,  4453,  4455,  4457,  4459,  4461,  4463,
    4465,  4470,  4471,  4473,  4478,  4480,  4486,  4492,  4494,  4496,
    4498,  4500,  4502,  4507,  4509,  4514,  4521,  4526,  4528,  4533,
    4535,  4543,  4545,  4547,  4549,  4554,  4561,  4562,  4565,  4570,
    4572,  4574,  4576,  4578,  4580,  4582,  4584,  4588,  4590,  4592,
    4596,  4602,  4606,  4612,  4620,  4624,  4626,  4628,  4632,  4638,
    4642,  4648,  4656,  4658,  4659,  4663,  4669,  4671,  4674,  4677,
    4682,  4686,  4688,  4690,  4692,  4694,  4696,  4699,  4702,  4703,
    4707,  4708,  4712,  4714,  4716,  4718,  4720,  4722,  4724,  4726,
    4731,  4733,  4735,  4737,  4739,  4741,  4743,  4745,  4750,  4752,
    4754,  4756,  4758,  4760,  4762,  4764,  4766,  4768,  4770,  4772,
    4774,  4776,  4778,  4783,  4785,  4789,  4791,  4795,  4796,  4804,
    4805,  4814,  4815,  4822,  4823,  4832,  4833,  4835,  4838,  4840,
    4844,  4846,  4850,  4856,  4858,  4860,  4862,  4864,  4866,  4867,
    4868,  4878,  4884,  4886,  4888,  4895,  4896,  4900,  4902,  4906,
    4911,  4913,  4914,  4917,  4922,  4929,  4930,  4932,  4934,  4936,
    4938,  4942,  4944,  4947,  4949,  4951,  4954,  4957,  4959,  4961,
    4963,  4966,  4971,  4975,  4978,  4982,  4986,  4990,  4992,  4994,
    4996,  4998,  5000,  5002,  5008,  5014,  5020,  5026,  5032,  5037,
    5042,  5046,  5051,  5053,  5057,  5059,  5065,  5073,  5079,  5080,
    5083,  5085,  5087,  5088,  5092,  5094,  5098,  5100,  5102,  5104,
    5105,  5109,  5111,  5113,  5115,  5117,  5122,  5129,  5131,  5133,
    5136,  5140,  5142,  5144,  5146,  5148,  5150,  5152,  5154,  5156,
    5162,  5168,  5173,  5174,  5179,  5181,  5184,  5186,  5188,  5190,
    5192,  5194,  5196,  5198,  5200,  5202,  5204,  5206,  5208,  5210,
    5212,  5214,  5216,  5218,  5220,  5222,  5224,  5226,  5228,  5230,
    5232,  5234,  5236,  5238,  5240,  5242,  5244,  5246,  5248,  5250,
    5252,  5254,  5256,  5258,  5260,  5262,  5264,  5266,  5268,  5270,
    5272,  5274,  5276,  5278,  5280,  5282,  5284,  5286,  5288,  5290,
    5292,  5294,  5296,  5298,  5300,  5302,  5304,  5306,  5308,  5310,
    5312,  5314,  5316,  5318,  5320,  5322,  5324,  5326,  5328,  5330,
    5332,  5334,  5336,  5338,  5340,  5342,  5344,  5346,  5348,  5350,
    5352,  5354,  5356,  5358,  5360,  5362,  5364,  5366,  5368,  5370,
    5372,  5374,  5376,  5378,  5380,  5382,  5384,  5386,  5388,  5390,
    5392,  5394,  5396,  5398,  5400,  5402,  5404,  5406,  5408,  5410,
    5412,  5414,  5416,  5418,  5420,  5422,  5424,  5426,  5428,  5430,
    5432,  5434,  5436,  5438,  5440,  5442,  5444,  5446,  5448,  5450,
    5452,  5454,  5456,  5458,  5460,  5462,  5464,  5466,  5468,  5470,
    5472,  5474,  5476,  5478,  5480,  5482,  5484,  5486,  5488,  5490,
    5492,  5494,  5496,  5498,  5500,  5502,  5504,  5506,  5508,  5510,
    5512,  5514,  5516,  5518,  5520,  5522,  5524,  5526,  5528,  5530,
    5532,  5534,  5536,  5538,  5540,  5542,  5544,  5546,  5548,  5550,
    5552,  5554,  5556,  5558,  5560,  5562,  5564,  5566,  5568,  5570,
    5572,  5574,  5576,  5578,  5580,  5582,  5584,  5586,  5588,  5590,
    5592,  5594,  5596,  5598,  5600,  5602,  5604,  5606,  5608,  5610,
    5612,  5614,  5616,  5618,  5620,  5622,  5624,  5626,  5628,  5630,
    5632,  5634,  5636,  5638,  5640,  5642,  5644,  5646,  5648,  5650,
    5652,  5654,  5656,  5658,  5660,  5662,  5664,  5666,  5668,  5670,
    5672,  5674,  5676,  5678,  5680,  5682,  5684,  5686,  5688,  5690,
    5692,  5694,  5696,  5698,  5700,  5702,  5704,  5706,  5708,  5710,
    5712,  5714,  5716,  5718,  5720,  5722,  5724,  5726,  5728,  5730,
    5732,  5734,  5736,  5738,  5740,  5742,  5744,  5746,  5748,  5750,
    5752,  5754,  5756,  5758,  5760,  5762,  5764,  5766,  5768,  5770,
    5772,  5774,  5776,  5778,  5780,  5782,  5784,  5786,  5788,  5790,
    5792,  5794,  5796,  5798,  5800,  5802,  5804,  5806,  5808,  5810,
    5812,  5814,  5816,  5818,  5820,  5822,  5823,  5827,  5828,  5832,
    5833,  5834,  5841,  5842,  5845,  5848,  5856,  5860,  5864,  5867,
    5870,  5873,  5875,  5879,  5881,  5885,  5887,  5891,  5893,  5897,
    5899,  5901,  5903,  5906,  5909,  5911,  5913,  5916,  5921,  5923,
    5925,  5927,  5929,  5931,  5933,  5937,  5940,  5944,  5948,  5952,
    5958,  5964,  5970,  5976,  5982,  5987,  5992,  5996,  6001,  6003,
    6005,  6009,  6010,  6016,  6018,  6022,  6026,  6030,  6032,  6035,
    6037,  6039,  6041,  6045,  6051,  6053,  6055,  6057,  6059,  6063,
    6065,  6066,  6067,  6074,  6075,  6078,  6079,  6081,  6083,  6086,
    6089,  6091,  6093,  6098,  6102,  6104,  6107,  6113,  6116,  6119,
    6125,  6126,  6129,  6131,  6133,  6136,  6143,  6150,  6152,  6153,
    6155,  6158,  6160,  6163,  6164,  6167,  6169,  6171,  6173,  6175,
    6177,  6179,  6181,  6183,  6185,  6187,  6189,  6191,  6193,  6195,
    6197,  6199,  6201,  6203,  6205,  6207,  6209,  6211,  6213,  6215,
    6217,  6219,  6221,  6223,  6225,  6227,  6229,  6231,  6233,  6235,
    6237,  6239,  6241,  6243,  6245,  6247,  6249,  6251,  6253,  6255,
    6257,  6259,  6261,  6263,  6265,  6267,  6269,  6271,  6273,  6275,
    6277,  6279,  6281,  6283,  6285,  6287,  6289,  6291,  6293,  6295,
    6297,  6299,  6301,  6303,  6305,  6307,  6309,  6311,  6313,  6315,
    6317,  6319,  6321,  6323,  6325,  6327,  6329,  6331,  6333,  6335,
    6337,  6339,  6341,  6343
};

/* YYRHS -- A `-1'-separated list of the rules' RHS. */
static const short yyrhs[] =
{
    1090,     0,    -1,   241,    -1,   238,    -1,   172,   724,   468,
     636,   725,    -1,   183,    -1,  1155,    -1,    26,    -1,   726,
      -1,   725,     5,   726,    -1,  1000,    -1,   472,   727,   434,
      -1,   727,   728,   727,    -1,    26,    -1,   729,    26,    -1,
    1155,    -1,   940,    -1,    18,    -1,    19,    -1,    20,    -1,
      21,    -1,    22,    -1,    18,    -1,    19,    -1,    -1,   731,
      -1,    -1,   316,   472,   732,   733,   434,    -1,   609,   472,
      26,     5,    26,   434,    -1,   734,    -1,   733,     5,   734,
      -1,   531,    -1,   572,    -1,   577,    -1,   547,    -1,   452,
      -1,   645,    -1,   569,    -1,   521,    -1,   458,    -1,   532,
      -1,   389,    -1,   573,    -1,   497,    -1,   376,    -1,   634,
      -1,   139,    -1,  1069,    -1,    -1,   736,    -1,    -1,   316,
     472,   737,   738,   434,    -1,   739,    -1,   738,     5,   739,
      -1,   734,    -1,   473,    -1,   643,    25,    -1,   244,   986,
      -1,   373,   986,    -1,   326,   986,    -1,   381,   986,    -1,
     335,   986,    -1,   301,   986,    -1,   575,   741,    -1,   929,
     388,  1155,    -1,    -1,   331,   472,   948,   434,   388,   742,
    1174,    -1,   147,   472,  1000,     5,    25,     5,    25,   434,
      -1,   449,   472,   992,   434,   388,  1155,    -1,  1294,    -1,
     234,   472,   948,   434,   388,  1155,    -1,    -1,    -1,  1155,
     630,  1000,   472,   743,   757,   434,   744,   755,    -1,    -1,
      -1,    -1,  1000,   472,   745,   757,   746,   434,   747,   755,
      -1,    -1,    -1,   515,  1502,   663,  1502,   472,   748,   757,
     749,   434,   755,    -1,    -1,    -1,  1000,   562,  1000,   472,
     750,   757,   751,   434,   755,    -1,    -1,    -1,    -1,   408,
     760,   630,   761,   500,   724,   468,   472,   752,   757,   753,
     434,   754,   756,    -1,    -1,   388,  1174,    -1,    -1,   388,
    1174,    -1,   205,    -1,    -1,   758,    -1,   759,    -1,   758,
       5,   759,    -1,   898,    -1,    25,    -1,  1000,    -1,  1000,
      -1,  1000,   660,  1000,    -1,    -1,   576,   905,   763,   766,
     770,   767,    -1,    -1,   576,   764,   765,   768,   767,    -1,
     772,    -1,   765,   772,    -1,   774,    -1,   766,   774,    -1,
     403,    -1,    -1,    -1,   383,   769,  1567,    -1,    -1,    -1,
     383,   771,  1567,    -1,    -1,   619,   905,   773,  1567,    -1,
      -1,   619,   905,   775,  1567,    -1,   320,   997,    -1,   243,
     995,    -1,   124,   995,    -1,   210,    -1,   227,  1508,    -1,
     535,   994,    -1,    30,   778,    31,    -1,   779,    -1,   781,
      -1,   780,    -1,   779,   780,    -1,    29,    -1,   782,    -1,
     781,   782,    -1,    28,    -1,   436,    -1,    -1,    -1,   364,
     785,   787,   786,   788,    -1,   427,  1155,   665,   789,  1043,
    1068,   730,    -1,  1155,   665,   789,  1043,   587,   948,  1068,
     730,    -1,    -1,   791,   233,    -1,   790,    -1,   789,     5,
     790,    -1,  1000,    -1,  1000,   660,  1000,    -1,  1000,   660,
      20,    -1,   792,    -1,   791,   792,    -1,    -1,   312,   798,
     793,  1567,    -1,    -1,   315,   799,   794,  1567,    -1,    -1,
    1071,   795,  1567,    -1,    -1,   208,   796,  1567,    -1,    -1,
     206,   797,  1567,    -1,  1004,    -1,   798,     5,  1004,    -1,
    1004,    -1,   799,     5,  1004,    -1,   133,    -1,   134,    -1,
     135,    -1,   136,    -1,   137,    -1,   138,    -1,   472,   898,
     802,   434,    -1,    -1,     5,   849,   666,   852,    -1,   198,
      -1,   321,    -1,    -1,   805,    -1,   806,    -1,   805,   806,
      -1,    -1,    -1,   479,   807,   809,   808,  1263,    -1,   862,
      -1,   812,    -1,   809,     5,   812,    -1,    -1,   811,  1000,
      -1,   397,   810,   861,    25,    -1,   397,   810,   861,  1000,
      -1,   397,   810,   861,  1006,    -1,   397,   810,   861,    26,
      -1,   816,   834,    -1,    -1,   810,   397,   813,   814,    -1,
      26,    -1,    25,    -1,  1006,    -1,    19,    26,    -1,   810,
      -1,   815,    -1,   816,     5,   815,    -1,    -1,   361,    -1,
      -1,   710,    -1,   711,    -1,   712,    -1,    -1,   528,   500,
     826,   468,   820,   664,   834,    -1,    -1,    35,   818,   821,
     664,   834,    -1,    -1,   360,   817,   823,    26,   824,   344,
     500,   825,   468,   822,   664,   834,    -1,   472,    -1,   499,
      -1,   434,    -1,   467,    -1,    26,    -1,   827,     5,   827,
       5,   827,    -1,   827,     5,   827,    -1,   827,    -1,    26,
      -1,    -1,   505,   829,   809,   325,    -1,    -1,   302,   830,
     810,   660,    20,    -1,    -1,   378,   831,   810,   300,   472,
     832,   434,    -1,   833,    -1,   832,     5,   833,    -1,   810,
      -1,   836,    -1,    -1,    99,    -1,    -1,    -1,   837,   839,
     838,   835,    -1,   819,    -1,   828,    -1,   361,    -1,   361,
     472,    26,   434,    -1,   465,   472,    26,   434,    -1,   465,
     472,    26,     5,    26,   434,    -1,   450,    -1,   657,   810,
      -1,   423,    -1,   550,    -1,   130,    -1,   440,    -1,   440,
     472,    26,   434,    -1,   440,   472,    26,     5,    26,   434,
      -1,   553,    -1,   553,   472,    26,   434,    -1,   553,   472,
      26,     5,    26,   434,    -1,    -1,   543,   840,   843,    -1,
      -1,   104,   841,   843,    -1,    -1,   341,   842,   843,    -1,
     578,    -1,   574,    -1,   120,    -1,   121,    -1,   615,    -1,
     400,   847,    -1,   412,   848,    -1,   844,    -1,    32,    -1,
      -1,   472,    26,   434,    -1,   597,   845,   660,   846,    -1,
     810,    -1,   810,    -1,    -1,   849,   666,   852,    -1,   857,
     666,   860,    -1,    -1,   850,   851,    -1,   622,    -1,   554,
      -1,   631,    -1,   593,    -1,   495,    -1,   511,    -1,   409,
     854,    -1,    -1,   853,   851,    -1,    -1,   472,   856,   434,
      -1,    -1,   472,    26,   434,    -1,    26,    -1,    -1,   858,
     859,   855,    -1,   622,    -1,   554,    -1,   631,    -1,   593,
      -1,   495,    -1,   511,    -1,   409,   854,    -1,   859,    -1,
      -1,    14,    -1,    -1,   278,  1000,   863,   657,   864,    -1,
     866,    -1,   869,    -1,   361,    -1,   361,   472,    26,   434,
      -1,   465,   472,    26,   434,    -1,   465,   472,    26,     5,
      26,   434,    -1,   450,    -1,   423,    -1,   550,    -1,   440,
      -1,   440,   472,    26,   434,    -1,   440,   472,    26,     5,
      26,   434,    -1,   553,    -1,   553,   472,    26,   434,    -1,
     553,   472,    26,     5,    26,   434,    -1,   543,    -1,   341,
      -1,   578,    -1,   574,    -1,   615,    -1,   400,   847,    -1,
     412,   848,    -1,   865,    -1,   597,   845,   660,   846,    -1,
      -1,   528,   500,   826,   468,   867,   664,   864,    -1,    -1,
     360,   817,   823,    26,   824,   344,   500,   825,   468,   868,
     664,   864,    -1,    -1,   505,   870,   872,   325,    -1,    -1,
     302,   871,  1000,   660,    20,    -1,   873,    -1,   872,     5,
     873,    -1,   874,   864,    -1,   875,    -1,   874,     5,   875,
      -1,  1000,    -1,    -1,   658,   990,    -1,   111,  1000,    -1,
     109,    -1,   666,   948,    -1,   666,   550,  1000,   699,   948,
      -1,   666,   550,  1000,   432,    -1,   113,  1000,    -1,   199,
     923,  1174,   884,    -1,   443,   923,   903,   876,   884,    -1,
     252,   997,   884,    -1,    -1,    -1,   230,   881,  1181,   666,
    1000,   660,    20,   883,   730,   882,   885,    -1,    -1,   509,
     991,    -1,   730,    -1,    -1,   886,   280,    -1,   280,    -1,
     887,    -1,   886,   887,    -1,    -1,   395,   888,  1567,    -1,
      -1,   391,   889,  1567,    -1,    -1,  1071,   890,  1567,    -1,
      37,  1155,    -1,    38,  1155,    -1,    36,  1155,    -1,   539,
     923,   904,   730,    -1,   539,   923,   904,   730,   106,    -1,
     256,    -1,   256,   905,    -1,   328,    -1,   327,    -1,   255,
      -1,   407,    -1,   215,    -1,   254,    -1,   372,    -1,   371,
      -1,   285,    -1,   212,    -1,   211,    -1,   189,    -1,   245,
      -1,   173,    -1,   188,    -1,   229,    -1,   196,    -1,   908,
      -1,   907,    -1,   912,    -1,   940,    -1,   898,   899,    -1,
     941,    -1,   943,    -1,   909,    -1,    19,   898,    -1,    18,
     898,    -1,   914,    -1,   922,    -1,   916,    -1,   516,    -1,
     800,    -1,   917,    -1,   918,    -1,   919,    -1,   920,    -1,
     921,    -1,    40,   898,    -1,   923,    -1,   923,   902,    -1,
     905,    -1,   524,    -1,   901,    -1,   902,     5,   901,    -1,
     905,    -1,   903,     5,   905,    -1,   905,    -1,   904,     5,
     905,    -1,   898,    -1,    18,    -1,    19,    -1,     9,   898,
      -1,   525,    -1,   469,    -1,   472,   898,   434,    -1,   484,
     472,  1482,   434,    -1,   336,   472,  1482,   434,    -1,   906,
    1006,    -1,   906,    26,    -1,    25,    -1,  1006,    -1,    26,
      -1,   911,    -1,  1155,    -1,  1155,   462,  1155,    -1,   910,
      -1,   475,   898,    -1,   435,   898,    -1,  1266,    -1,    -1,
     548,   913,  1266,    -1,     7,   898,    -1,     6,   898,    -1,
     898,    -1,   915,     5,   898,    -1,   663,   472,  1482,   434,
      -1,   470,   472,  1482,   434,    -1,   663,   472,   923,   915,
     434,    -1,   470,   472,   923,   915,   434,    -1,   429,    -1,
     291,    -1,    10,   898,    -1,   294,   898,    -1,    10,   898,
     483,    25,    -1,   294,   898,   483,    25,    -1,   597,   898,
      -1,   414,   898,    -1,   597,   898,   483,    25,    -1,   414,
     898,   483,    25,    -1,   433,    -1,     8,   898,    -1,    18,
     898,    -1,    19,   898,    -1,    20,   898,    -1,    21,   898,
      -1,    22,   898,    -1,    11,   898,    -1,    14,   898,    -1,
     498,   898,    -1,    12,   898,    -1,    13,   898,    -1,    17,
     898,    -1,    16,   898,    -1,    15,   898,    -1,    -1,    -1,
      -1,  1000,   472,   925,   757,   926,   434,    -1,    -1,    -1,
    1000,   562,  1000,   472,   927,   757,   928,   434,    -1,    -1,
      -1,   578,   472,   930,   898,   931,   434,    -1,    -1,    -1,
     554,   472,   932,   898,   933,   434,    -1,    -1,    -1,   631,
     472,   934,   898,   935,   434,    -1,    -1,    -1,   622,   472,
     936,   898,   937,   434,    -1,   412,   472,   944,   434,   939,
      -1,   400,   472,    25,   434,   938,    -1,   400,   472,    26,
     434,   938,    -1,   400,   472,    26,   630,    26,   434,   938,
      -1,   716,   472,  1155,   434,    -1,   717,   472,  1155,     5,
      26,   434,    -1,    -1,  1462,   666,  1463,    -1,   848,    -1,
     929,    -1,   331,   472,   948,   434,    -1,   140,   472,   991,
     434,    -1,   112,   472,   991,   434,    -1,   449,   472,   949,
     434,    -1,   234,   472,   948,   434,    -1,   100,   472,   948,
     434,    -1,   942,    -1,   924,    -1,  1458,    -1,   578,    -1,
     464,   472,   898,   434,    -1,   366,   472,   898,   434,    -1,
     529,   898,    -1,   485,   801,    -1,   898,   151,    -1,   898,
     152,    -1,   898,   153,    -1,    25,    -1,   945,    -1,    19,
     945,    -1,   947,    -1,   946,    -1,    26,    -1,    26,    26,
      -1,    26,    26,   630,    26,    -1,    26,    26,   630,    26,
     630,    26,    -1,    26,    26,   630,    26,   630,    24,    -1,
      26,   630,    26,    -1,    26,   630,    26,   630,    26,    -1,
      26,   630,    26,   630,    24,    -1,    26,   630,    24,    -1,
      24,    -1,    26,    -1,    26,    19,    26,    -1,   991,    -1,
     948,     5,   991,    -1,   992,    -1,   949,     5,   992,    -1,
      -1,    -1,    -1,   446,   951,   994,   952,   954,  1361,   953,
    1567,   282,    -1,    -1,     8,   923,   903,    -1,    -1,    -1,
     678,  1000,   956,   804,   957,  1100,   959,   958,   964,   679,
      -1,    -1,   969,    -1,    -1,   960,    -1,   961,    -1,   960,
     961,    -1,    -1,   680,   962,  1567,    -1,    -1,   681,   963,
    1567,    -1,    -1,   965,    -1,   966,    -1,   965,   966,    -1,
      -1,   682,   967,  1567,    -1,    -1,   683,   968,  1567,    -1,
     970,   974,   368,    -1,   132,    -1,   132,   971,   587,   972,
      -1,   132,   427,   973,    -1,  1155,    -1,   971,     5,  1155,
      -1,  1000,    -1,   972,     5,  1000,    -1,  1155,    -1,   973,
       5,  1155,    -1,   975,    -1,   974,   975,    -1,    -1,   684,
     976,  1567,    -1,    -1,   685,   977,  1567,    -1,    -1,   704,
     972,   978,  1567,    -1,    -1,   522,   972,   979,  1567,    -1,
      -1,   665,   972,   980,  1567,    -1,    -1,    -1,   636,  1155,
      14,   905,   666,   905,   984,   982,  1567,   983,   283,    -1,
      -1,   612,   905,    -1,   586,   993,    -1,   595,    19,    26,
      -1,   595,    -1,   542,    18,    26,    -1,   542,    -1,    26,
      -1,  1155,    -1,   709,    -1,    25,    -1,  1005,    -1,   905,
      -1,   988,     5,   988,    -1,   989,    -1,  1000,    -1,   707,
     472,  1000,   434,    -1,  1000,   660,   707,   472,  1000,   434,
      -1,  1000,   500,   727,   468,    -1,  1000,   660,    20,    -1,
    1000,   500,   727,   468,   660,    20,    -1,  1000,   660,  1000,
      -1,  1000,   500,   727,   468,   660,  1000,    -1,   991,    -1,
      25,    -1,  1001,    -1,  1001,    -1,  1001,    -1,  1001,    -1,
    1001,    -1,  1001,    -1,    -1,   591,    26,    -1,  1566,    -1,
    1002,    -1,  1566,    -1,   393,   472,  1003,   434,    -1,  1158,
      -1,    25,    -1,  1000,    -1,  1000,   500,   727,   468,    -1,
    1000,   660,    20,    -1,  1000,   500,   727,   468,   660,    20,
      -1,  1000,   660,  1000,    -1,  1000,   500,   727,   468,   660,
    1000,    -1,  1155,    -1,    24,    -1,   660,    26,    -1,   588,
    1008,    -1,  1000,    -1,   630,  1000,    -1,   692,  1010,    -1,
    1011,    -1,  1010,     5,  1011,    -1,  1000,    -1,   703,  1010,
      -1,   694,  1010,    -1,   695,   948,    -1,   693,   997,   699,
     948,    -1,   697,  1010,    -1,   698,   948,    -1,   696,   997,
     699,   948,    -1,    -1,   701,  1016,   903,  1021,  1023,  1025,
    1017,  1019,    -1,    -1,  1018,    -1,   689,    -1,   690,    -1,
      -1,  1020,    -1,   388,  1155,    -1,    -1,  1022,    -1,   432,
     903,    -1,    -1,  1024,    -1,   700,    26,    -1,    -1,  1026,
      -1,   691,    26,  1027,    -1,    -1,   442,    26,    -1,    -1,
      -1,   662,   905,   616,  1029,  1567,  1030,  1031,   482,    -1,
      -1,    -1,   583,  1032,  1567,    -1,    -1,    -1,   103,  1033,
     905,   616,  1034,  1567,  1031,    -1,   149,  1000,   472,    26,
     434,    -1,    94,  1000,    -1,   116,  1000,    -1,    -1,   332,
    1186,  1038,   666,   524,    -1,   332,  1186,   597,  1039,    -1,
    1040,    -1,  1039,     5,  1040,    -1,  1041,   660,  1454,    -1,
    1041,   660,    20,    -1,  1450,    -1,    -1,  1044,   368,    -1,
     368,    -1,    -1,   193,    -1,  1045,    -1,  1044,  1045,    -1,
      -1,   312,  1057,  1046,  1567,    -1,    -1,   315,  1058,  1047,
    1567,    -1,    -1,   395,  1048,  1567,    -1,    -1,   391,  1049,
    1567,    -1,    -1,  1071,  1050,  1567,    -1,    -1,   347,  1051,
    1567,    -1,    -1,   317,  1052,  1567,    -1,    -1,    41,  1053,
    1567,    -1,    -1,    39,  1054,  1567,    -1,    -1,    43,  1055,
    1567,    -1,    -1,    42,  1056,  1567,    -1,   991,    -1,  1057,
       5,   991,    -1,   991,    -1,  1058,     5,   991,    -1,   356,
    1061,    -1,   357,  1000,   699,  1061,    -1,   602,    -1,   418,
      -1,   991,    -1,    -1,   705,  1064,  1063,  1042,    -1,   427,
    1174,  1043,   999,   730,    -1,  1174,  1043,   587,   948,   999,
     730,    -1,    -1,   528,  1181,  1043,   587,  1000,   660,    20,
     999,  1065,   730,    -1,   510,   948,  1067,    -1,   122,    26,
      -1,   123,    26,    -1,   667,    -1,   580,    -1,    -1,   591,
      26,    -1,  1070,    -1,    49,    25,    -1,   537,    14,    26,
      -1,   537,    14,  1155,    -1,    50,    14,    26,    -1,    50,
      14,  1155,    -1,    46,    -1,    48,    -1,    45,    -1,    47,
      -1,    -1,   471,  1072,  1077,    -1,   337,    -1,    -1,   637,
    1074,  1077,    -1,   345,  1079,    -1,   637,  1077,    -1,  1079,
      -1,   472,  1078,   434,    -1,  1079,    -1,  1078,     5,  1079,
      -1,  1080,    -1,   635,    -1,   354,    -1,   374,    -1,   346,
      -1,   526,    -1,   483,    -1,   667,    -1,   591,    -1,   580,
      -1,   219,    -1,   480,    -1,   491,    -1,   581,    -1,   596,
      -1,   561,    -1,   352,    -1,   353,    -1,    25,    -1,   551,
      -1,    -1,    -1,   639,  1083,  1179,  1084,    14,   923,  1085,
      -1,   524,    -1,   904,    -1,   261,  1155,    -1,   251,  1155,
      -1,   264,  1155,    -1,   492,  1177,   377,    -1,   492,  1177,
     428,   987,    -1,    -1,  1092,  1091,  1095,    -1,    -1,  1093,
      -1,  1094,    -1,  1093,  1094,    -1,  1036,    -1,  1099,    -1,
    1551,    -1,  1115,    -1,  1101,    -1,  1114,    -1,    -1,  1096,
      -1,  1098,    -1,  1096,  1098,    -1,   107,  1000,    -1,  1103,
      -1,  1109,    -1,  1121,    -1,  1276,    -1,  1286,    -1,  1125,
      -1,   955,    -1,   777,    -1,  1035,    -1,   783,    -1,  1551,
      -1,   777,    -1,    -1,   777,    -1,   805,    -1,   410,    -1,
     101,    -1,    -1,    -1,    -1,    -1,  1102,  1104,  1000,   472,
    1105,  1172,   434,  1106,   804,  1107,  1100,  1567,  1108,    -1,
     253,    -1,    -1,    -1,   598,  1110,   804,  1111,  1567,   404,
      -1,   219,   900,    -1,   923,    -1,   923,   903,    -1,   399,
    1466,    -1,   508,  1466,    -1,  1116,    -1,  1117,    -1,  1116,
    1117,    -1,  1118,    -1,    -1,   448,  1119,  1120,    -1,   804,
     284,    -1,   987,    -1,  1099,    -1,  1114,    -1,    -1,    -1,
      -1,   156,  1000,   155,  1000,   472,  1122,  1172,   434,  1123,
     804,  1124,  1100,  1567,  1108,    -1,    -1,    -1,   686,  1000,
    1126,   804,  1127,  1128,   687,    -1,  1129,    -1,  1128,  1129,
      -1,    -1,   688,  1130,  1567,    -1,    -1,   665,  1000,  1131,
    1567,    -1,    -1,   599,  1133,  1148,  1139,  1134,    -1,   405,
      -1,    -1,   276,  1136,  1567,    -1,    -1,    23,  1140,  1141,
    1142,   999,  1137,  1567,    -1,    -1,    23,  1140,   999,  1138,
    1567,    -1,  1135,    -1,  1139,  1135,    -1,    -1,  1073,    -1,
      25,    -1,  1155,    -1,    -1,  1155,    -1,    25,    -1,   293,
    1146,    -1,   305,  1147,    -1,   288,  1147,    -1,   626,    -1,
      25,    -1,  1155,    -1,  1146,    -1,  1147,     5,  1146,    -1,
    1155,    -1,    25,    -1,  1152,  1150,    -1,    -1,   731,  1153,
      -1,  1154,    -1,  1151,    -1,  1022,    -1,  1024,    -1,  1026,
      -1,  1018,    -1,  1020,    -1,   413,   923,   903,    -1,    -1,
     106,    -1,   106,    -1,  1156,    -1,  1158,    -1,   232,  1158,
      -1,  1158,   660,    -1,  1157,  1162,    -1,  1157,  1000,   500,
    1166,   468,    -1,  1157,  1000,   500,  1166,   468,   500,  1166,
     468,    -1,  1163,    -1,  1000,    -1,  1159,    -1,  1000,   499,
    1161,   467,    -1,  1000,   499,  1161,   467,    -1,  1155,    -1,
      25,    -1,    20,    -1,  1000,    -1,  1000,  1165,    -1,  1000,
    1165,    -1,   500,  1166,   468,    -1,   500,  1166,   468,   500,
    1166,   468,    -1,  1167,    -1,  1166,     5,  1167,    -1,   727,
      -1,  1169,    -1,  1171,    -1,  1169,   660,  1170,    -1,  1169,
     660,  1000,   500,  1166,   468,    -1,  1169,   660,  1000,   500,
    1166,   468,   500,  1166,   468,    -1,  1000,    -1,  1160,    -1,
      20,    -1,  1000,    -1,  1000,  1165,    -1,    -1,  1173,    -1,
    1175,    -1,  1173,     5,  1175,    -1,  1176,    -1,  1174,     5,
    1176,    -1,  1000,    -1,  1000,   660,  1000,    -1,  1155,    -1,
    1155,   462,  1155,    -1,    25,    -1,  1006,    -1,    26,    -1,
    1178,    -1,  1177,     5,  1178,    -1,  1155,    -1,  1155,   462,
    1155,    -1,  1180,    -1,  1179,     5,  1180,    -1,  1168,    -1,
    1155,    -1,  1183,    -1,  1182,     5,  1183,    -1,  1155,  1184,
      -1,    -1,   628,    -1,   579,    -1,  1000,   500,  1166,   468,
      -1,  1187,    -1,  1186,     5,  1187,    -1,  1155,    -1,  1155,
     462,  1155,    -1,   296,   996,   658,   989,   620,  1559,   735,
      -1,    -1,   658,   472,   905,     5,   905,   434,  1190,    -1,
      -1,   609,   472,   905,     5,   905,   434,    -1,   297,  1000,
    1189,    -1,  1000,    -1,   382,   998,  1194,    -1,  1195,    -1,
     587,   905,    -1,  1196,  1197,  1202,     8,  1192,    -1,    -1,
     658,  1198,   472,   905,     5,   905,   434,    -1,    -1,   597,
    1001,    -1,    -1,   394,    -1,   259,  1508,   308,  1546,  1201,
      -1,   604,   993,    -1,   604,   993,     8,   923,   903,    -1,
      -1,   657,   617,  1502,   417,  1502,    -1,   657,   617,  1502,
       5,   417,  1502,    -1,   657,  1502,     5,  1502,    -1,    -1,
     689,    -1,   690,    -1,   131,  1546,  1204,  1205,    -1,    -1,
     657,  1546,    -1,    -1,   657,   617,  1502,     8,  1502,    -1,
     617,  1502,     8,  1502,    -1,   453,  1207,    -1,  1208,    -1,
    1207,     5,  1208,    -1,   244,   986,    -1,   326,   986,    -1,
     373,   986,    -1,   381,   986,    -1,   335,   986,    -1,   301,
     986,    -1,  1075,    -1,   480,  1076,    -1,   491,  1076,    -1,
     602,  1076,    -1,   418,  1076,    -1,   591,  1076,    -1,   589,
     987,    -1,   590,   987,    -1,   443,   731,    -1,   705,   731,
      -1,   333,    -1,   237,    -1,   194,    -1,   174,    -1,   191,
      -1,   182,    -1,  1507,   455,  1212,   587,  1210,    -1,  1155,
      -1,    25,    -1,   445,  1212,    -1,   445,  1212,     8,  1174,
      -1,    44,  1210,    -1,  1001,    -1,    -1,   503,  1222,   730,
     636,  1217,  1155,  1215,   999,   730,  1214,  1218,    -1,    -1,
     708,    26,    -1,   503,  1222,   730,   388,  1155,    -1,    -1,
     361,    -1,    -1,  1219,   324,    -1,  1220,    -1,  1219,  1220,
      -1,    -1,  1071,  1221,  1567,    -1,   904,    -1,    -1,   644,
     993,  1224,  1225,    -1,    -1,   587,  1226,    -1,  1227,    -1,
    1226,     5,  1227,    -1,  1494,    -1,   524,    -1,   262,  1230,
     129,    -1,   262,  1230,   666,  1229,    -1,   262,  1230,   128,
    1229,    -1,   262,  1230,    -1,    25,    -1,  1005,    -1,  1000,
      -1,    -1,   520,    -1,   190,  1230,  1231,   472,   923,  1113,
     434,    -1,   235,  1230,    -1,   108,  1230,    -1,  1267,  1275,
      -1,   488,   102,    -1,   488,  1237,    -1,  1238,    -1,  1237,
    1238,    -1,    -1,   178,  1239,  1567,    -1,    -1,   240,  1240,
    1567,    -1,    -1,   270,  1241,  1567,    -1,    -1,   258,  1242,
    1567,    -1,    -1,   295,  1243,  1567,    -1,    -1,   242,  1155,
    1244,  1567,    -1,    -1,   266,  1155,  1245,  1567,    -1,  1256,
      -1,  1259,    -1,  1258,    -1,  1247,    -1,  1284,    -1,  1250,
      -1,    -1,   601,   905,  1248,   523,    -1,    -1,   523,    -1,
      -1,   610,    26,  1251,  1249,    -1,   201,    -1,   669,  1271,
      -1,   204,  1271,    -1,   203,  1271,    -1,    -1,  1253,    -1,
    1254,    -1,  1253,  1254,    -1,  1264,  1255,    -1,    -1,   658,
    1271,    -1,    -1,   560,  1257,  1252,  1263,    -1,   559,  1502,
    1263,    -1,   558,  1262,  1261,  1260,  1263,    -1,    -1,   195,
     898,    -1,   195,   898,     5,   898,    -1,   653,    -1,   654,
      -1,   655,    -1,   656,    -1,  1155,    -1,    -1,   563,    -1,
    1265,    -1,  1264,     5,  1265,    -1,   905,  1298,    -1,   649,
     472,   898,   434,  1283,    -1,   105,  1283,    -1,   537,   472,
      20,   434,  1283,    -1,   454,   472,    20,   434,  1283,    -1,
     430,   472,   898,   434,  1283,    -1,   629,   472,   898,   434,
    1283,    -1,   642,   472,   898,   434,  1283,    -1,   641,   472,
     898,   434,  1283,    -1,    -1,   502,  1268,    -1,  1269,    -1,
    1268,  1269,    -1,   269,    26,    -1,   260,    26,    -1,   343,
      26,    -1,   226,    26,    -1,   298,    26,    -1,   217,    -1,
     387,    25,    -1,   387,  1155,    -1,   218,    25,    -1,   202,
      25,    -1,  1274,    -1,  1270,  1274,    -1,  1272,   151,    -1,
    1272,   153,    -1,  1272,   152,    -1,  1272,    -1,  1006,    -1,
      26,    -1,    -1,   502,  1270,    -1,   269,  1271,    -1,   260,
    1271,    -1,   343,  1271,    -1,   226,  1271,    -1,   298,  1271,
      -1,   299,  1271,    -1,   668,    25,    -1,   669,  1271,    -1,
     673,    -1,   670,    -1,   671,    -1,   672,    -1,   677,    -1,
     674,    -1,   675,    -1,   676,    -1,   117,  1271,    -1,   118,
    1271,    -1,   119,  1271,    -1,   387,    25,    -1,   218,    25,
      -1,   442,    -1,   114,    -1,   115,    -1,    -1,   555,   659,
    1182,    -1,   179,  1182,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   506,  1277,  1000,   472,  1278,  1172,   434,  1279,   804,
    1280,  1235,  1281,  1236,  1282,   281,    -1,    -1,   567,   898,
      -1,   557,  1285,    -1,    -1,  1210,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   148,  1287,  1000,   472,  1288,  1172,   434,
    1289,   804,  1290,  1293,  1291,  1236,  1292,   281,    -1,  1273,
    1275,    -1,    -1,    -1,    -1,   197,   472,    25,     5,  1295,
     757,  1296,   434,  1297,   755,    -1,    -1,   426,    -1,   426,
     260,    26,    -1,   426,   260,  1155,    -1,   647,   905,    -1,
     647,   905,   388,  1155,    -1,   647,   905,   205,    -1,   647,
     905,   618,    -1,   647,   905,   585,    -1,  1301,    -1,   214,
    1450,    -1,   367,  1450,    -1,   323,  1451,    -1,   715,  1000,
      -1,  1315,    -1,  1303,    -1,    -1,    -1,   247,  1304,  1450,
     472,  1305,  1319,   434,  1308,    -1,    -1,    -1,   176,  1306,
    1450,   472,  1307,  1319,   434,  1308,  1316,    -1,    -1,  1309,
      -1,  1310,    -1,  1309,  1310,    -1,   663,  1311,    -1,   286,
      26,    -1,    53,    26,    -1,   126,    -1,   127,    -1,  1566,
      -1,    -1,  1313,    -1,  1314,    -1,  1313,  1314,    -1,   663,
    1311,    -1,   718,    26,    -1,   146,  1451,   665,  1450,   472,
    1317,   434,  1312,    -1,    92,  1001,    -1,    93,  1001,    -1,
     213,  1450,   636,  1450,    -1,    97,  1450,    -1,    -1,   310,
      -1,  1318,    -1,  1317,     5,  1318,    -1,  1000,   628,    -1,
    1000,   579,    -1,  1000,    -1,  1320,    -1,  1319,     5,  1320,
      -1,  1402,    -1,  1400,    -1,   163,  1000,    -1,   221,    -1,
      51,  1000,  1323,    -1,    52,  1451,   143,    -1,    52,  1451,
     144,    -1,  1324,    -1,  1323,     5,  1324,    -1,  1325,    -1,
    1328,    -1,  1331,    -1,  1336,    -1,  1339,    -1,  1335,    -1,
    1334,    -1,   625,  1326,    -1,   625,   472,  1327,   434,    -1,
    1320,    -1,  1320,   704,  1000,    -1,  1326,    -1,  1327,     5,
    1326,    -1,   582,  1330,    -1,   582,   472,  1329,   434,    -1,
    1330,    -1,  1329,     5,  1330,    -1,  1000,    -1,   496,  1333,
      -1,   496,   472,  1332,   434,    -1,  1333,    -1,  1332,     5,
    1333,    -1,  1320,    -1,   126,    -1,   127,    -1,   125,    26,
      -1,    95,  1400,  1338,    -1,    95,   472,  1337,   434,    -1,
    1400,  1338,    -1,  1337,     5,  1400,  1338,    -1,    -1,    98,
    1000,    -1,    96,  1340,    -1,    96,   472,  1340,   434,    -1,
    1341,    -1,  1340,     5,  1341,    -1,  1000,    -1,   307,    -1,
     273,    -1,   207,  1344,    -1,   186,    -1,   175,    -1,   162,
      -1,   160,    -1,   164,    -1,   220,  1508,    -1,   272,  1343,
     501,  1502,   666,  1502,    -1,   340,   993,   501,  1502,   666,
    1502,    -1,    -1,  1508,    -1,    -1,   905,    -1,   564,   905,
      -1,   271,    -1,    -1,   290,  1348,  1450,  1351,  1349,    -1,
      -1,   520,  1350,   472,  1353,   434,    -1,  1488,    -1,    -1,
     472,  1352,   434,    -1,  1454,    -1,  1352,     5,  1454,    -1,
    1354,    -1,  1353,     5,  1354,    -1,  1494,    -1,   524,    -1,
      -1,   541,  1356,  1358,  1359,    -1,  1001,    -1,  1363,   994,
      -1,   994,    -1,    -1,    -1,   594,  1360,  1177,    -1,    -1,
      -1,   594,  1362,  1177,    -1,   542,    -1,   595,    -1,   602,
      -1,   418,    -1,   385,    -1,   438,    -1,   421,   905,    -1,
     394,   905,    -1,   279,  1450,   192,   994,    -1,   279,  1450,
    1423,    -1,   555,   659,  1367,    -1,  1368,    -1,  1367,     5,
    1368,    -1,  1369,  1370,    -1,    26,    -1,  1454,    -1,    -1,
     628,    -1,   579,    -1,   318,    -1,   351,    -1,    -1,   370,
      -1,   399,  1375,  1373,    -1,  1546,    -1,  1546,   652,  1000,
      -1,    25,    -1,    -1,  1507,  1377,  1378,    -1,  1408,    -1,
    1412,    -1,  1372,    -1,  1509,    -1,  1371,    -1,  1364,    -1,
    1365,    -1,  1355,    -1,  1347,    -1,  1346,    -1,  1478,    -1,
    1526,    -1,   546,  1381,   665,  1450,   666,  1386,  1380,    -1,
      -1,   185,    -1,   209,    -1,  1382,    -1,  1383,    -1,  1382,
       5,  1383,    -1,   512,    -1,   491,    -1,   480,    -1,   519,
    1384,    -1,    -1,   472,  1385,   434,    -1,  1454,    -1,  1385,
       5,  1454,    -1,  1387,    -1,  1386,     5,  1387,    -1,   504,
      -1,  1452,    -1,   277,  1450,  1389,   657,  1488,  1391,    -1,
      -1,   472,  1390,   434,    -1,  1454,    -1,  1390,     5,  1454,
      -1,    -1,   184,    -1,   533,   472,  1426,   434,    -1,   287,
     472,  1395,   434,  1394,    -1,   338,  1396,    -1,  1397,    -1,
    1450,    -1,  1450,   472,  1397,   434,    -1,  1454,    -1,  1397,
       5,  1454,    -1,   517,   472,  1399,   434,    -1,   402,   472,
    1399,   434,    -1,   300,   472,  1399,   434,    -1,  1454,    -1,
    1399,     5,  1454,    -1,  1398,    -1,  1393,    -1,  1392,    -1,
     442,  1457,    -1,   250,    -1,   249,    -1,   248,    -1,  1000,
    1442,  1403,  1404,    -1,    -1,  1401,    -1,    -1,  1405,    -1,
    1406,    -1,  1405,  1406,    -1,  1407,  1338,    -1,   416,    -1,
     200,    -1,   517,    -1,   402,    -1,  1394,    -1,   533,   472,
    1426,   434,    -1,   300,    -1,   161,  1409,  1411,    -1,  1410,
      -1,  1452,    -1,  1412,    -1,  1411,  1412,    -1,  1388,    -1,
    1379,    -1,   489,  1426,    -1,   411,  1415,    -1,  1493,    -1,
    1415,     5,  1493,    -1,   567,  1426,    -1,   587,  1418,    -1,
    1419,    -1,  1418,     5,  1419,    -1,  1420,    -1,   556,  1420,
      -1,   556,   472,  1421,   434,    -1,  1450,    -1,  1450,  1456,
      -1,  1419,    -1,  1421,     5,  1419,    -1,  1417,  1423,  1424,
    1425,    -1,    -1,  1416,    -1,    -1,  1414,    -1,    -1,  1413,
      -1,  1427,    -1,  1426,     6,  1427,    -1,  1428,    -1,  1427,
       7,  1428,    -1,  1429,    -1,     9,  1429,    -1,  1440,    -1,
     472,  1426,   434,    -1,   484,  1489,    -1,   336,  1489,    -1,
      -1,   483,  1433,    -1,  1495,    -1,  1498,    -1,  1494,   663,
     472,  1435,   434,    -1,  1494,   663,  1489,    -1,  1494,   470,
     472,  1435,   434,    -1,  1494,   470,  1489,    -1,  1436,    -1,
    1435,     5,  1436,    -1,  1550,    -1,  1457,    -1,    -1,     9,
      -1,  1494,  1437,   429,    -1,  1494,  1437,   291,    -1,  1494,
    1439,  1494,    -1,  1494,  1437,   431,  1494,     7,  1494,    -1,
    1494,   597,  1432,  1431,    -1,  1494,   414,  1432,  1431,    -1,
    1494,   714,  1432,  1431,    -1,  1494,   415,  1432,  1431,    -1,
    1494,  1437,    10,  1432,  1431,    -1,    14,    -1,    17,    -1,
      12,    -1,    13,    -1,   294,    -1,    10,    -1,   713,    -1,
      16,    -1,    15,    -1,  1438,    -1,  1434,    -1,  1430,    -1,
      -1,   626,    -1,   402,    -1,   517,    -1,  1443,    -1,  1444,
      -1,  1446,    -1,   361,    -1,   361,   472,  1447,   434,    -1,
      -1,   513,    -1,   513,   472,    26,   434,    -1,   440,    -1,
     440,   472,  1448,  1445,   434,    -1,   553,   472,  1448,  1445,
     434,    -1,   553,    -1,   578,    -1,   450,    -1,   423,    -1,
     362,    -1,   362,   472,  1447,   434,    -1,   363,    -1,   363,
     472,    26,   434,    -1,   363,   472,    26,     5,    26,   434,
      -1,   400,  1464,   666,  1465,    -1,   400,    -1,   412,  1464,
     666,  1465,    -1,   412,    -1,   412,  1464,   472,    26,   434,
     666,  1465,    -1,   615,    -1,   574,    -1,   465,    -1,   465,
     472,    26,   434,    -1,   465,   472,    26,     5,    26,   434,
      -1,    -1,     5,  1449,    -1,   543,   472,  1448,   434,    -1,
     606,    -1,   341,    -1,   543,    -1,   104,    -1,    26,    -1,
      26,    -1,    26,    -1,    25,   660,  1000,    -1,    25,    -1,
    1000,    -1,  1000,   630,  1000,    -1,  1000,   630,    25,   660,
    1000,    -1,  1000,   652,  1000,    -1,  1000,   652,  1000,   630,
    1000,    -1,  1000,   652,  1000,   630,    25,   660,  1000,    -1,
      25,   660,  1000,    -1,    25,    -1,  1000,    -1,  1000,   630,
    1000,    -1,  1000,   630,    25,   660,  1000,    -1,  1000,   652,
    1000,    -1,  1000,   652,  1000,   630,  1000,    -1,  1000,   652,
    1000,   630,    25,   660,  1000,    -1,  1000,    -1,    -1,   500,
      26,   468,    -1,   500,    26,     5,    26,   468,    -1,  1455,
      -1,   652,  1455,    -1,  1000,  1453,    -1,  1450,   660,  1000,
    1453,    -1,  1450,   660,    20,    -1,  1000,    -1,    25,    -1,
    1006,    -1,    26,    -1,  1459,    -1,   438,  1461,    -1,   438,
    1460,    -1,    -1,  1464,   666,  1465,    -1,    -1,  1462,   666,
    1462,    -1,   622,    -1,   554,    -1,   631,    -1,   593,    -1,
     495,    -1,   511,    -1,   409,    -1,   409,   472,    26,   434,
      -1,   622,    -1,   554,    -1,   631,    -1,   593,    -1,   495,
      -1,   511,    -1,   409,    -1,   409,   472,    26,   434,    -1,
     622,    -1,   554,    -1,   631,    -1,   593,    -1,   495,    -1,
     511,    -1,   409,    -1,   622,    -1,   554,    -1,   631,    -1,
     593,    -1,   495,    -1,   511,    -1,   409,    -1,   409,   472,
      26,   434,    -1,  1000,    -1,  1000,   652,  1000,    -1,    25,
      -1,  1507,   544,   994,    -1,    -1,  1507,   441,  1357,   478,
     636,  1476,  1469,    -1,    -1,  1507,   441,  1357,   478,   141,
     636,  1477,  1470,    -1,    -1,  1507,   441,  1357,   180,  1477,
    1471,    -1,    -1,  1507,   441,  1357,   181,   141,   636,  1477,
    1472,    -1,    -1,   330,    -1,   329,  1474,    -1,  1475,    -1,
    1474,     5,  1475,    -1,  1000,    -1,  1000,   660,  1000,    -1,
      25,   660,  1000,   660,  1000,    -1,  1477,    -1,  1347,    -1,
    1212,    -1,  1479,    -1,  1479,    -1,    -1,    -1,   512,  1490,
    1480,  1491,  1481,  1487,  1422,  1485,  1473,    -1,   512,  1490,
    1491,  1422,  1485,    -1,  1484,    -1,  1502,    -1,   512,  1490,
    1491,  1487,  1422,  1485,    -1,    -1,   566,  1441,  1483,    -1,
    1366,    -1,   375,  1486,  1316,    -1,  1366,   375,  1486,  1316,
      -1,  1000,    -1,    -1,   594,  1177,    -1,   512,  1490,  1491,
    1422,    -1,   472,   512,  1490,  1491,  1422,   434,    -1,    -1,
     626,    -1,   402,    -1,   517,    -1,  1492,    -1,  1491,     5,
    1492,    -1,  1494,    -1,  1494,  1000,    -1,  1494,    -1,  1495,
      -1,    19,  1495,    -1,    18,  1495,    -1,  1496,    -1,  1550,
      -1,  1489,    -1,   652,  1000,    -1,   652,  1000,   660,  1000,
      -1,  1495,    21,  1494,    -1,  1495,  1516,    -1,  1495,    20,
    1494,    -1,  1495,    18,  1494,    -1,  1495,    19,  1494,    -1,
    1457,    -1,   525,    -1,   469,    -1,   617,    -1,    20,    -1,
     105,    -1,   629,   472,  1441,  1494,   434,    -1,   641,   472,
    1441,  1494,   434,    -1,   642,   472,  1441,  1494,   434,    -1,
     649,   472,  1441,  1494,   434,    -1,   537,   472,  1441,  1494,
     434,    -1,  1000,   472,  1497,   434,    -1,   578,   472,  1497,
     434,    -1,   472,  1494,   434,    -1,   485,   472,  1517,   434,
      -1,  1494,    -1,  1497,     5,  1494,    -1,  1457,    -1,  1507,
     390,  1506,  1501,  1483,    -1,  1507,   379,  1506,  1501,   290,
    1450,  1503,    -1,  1507,   379,  1506,  1501,  1155,    -1,    -1,
     365,  1502,    -1,    25,    -1,  1155,    -1,    -1,   472,  1504,
     434,    -1,  1505,    -1,  1504,     5,  1505,    -1,  1000,    -1,
      25,    -1,  1155,    -1,    -1,   309,  1508,   636,    -1,  1001,
      -1,  1514,    -1,  1513,    -1,  1510,    -1,   358,  1511,   666,
    1511,    -1,   339,  1511,   660,  1512,   666,  1512,    -1,  1000,
      -1,  1000,    -1,   263,  1450,    -1,   334,  1450,  1515,    -1,
     313,    -1,   216,    -1,   133,    -1,   134,    -1,   135,    -1,
     136,    -1,   137,    -1,   138,    -1,   438,     5,  1464,   666,
    1465,    -1,  1550,     5,  1464,   666,  1465,    -1,   438,  1464,
     666,  1465,    -1,    -1,   648,  1519,  1520,   231,    -1,  1521,
      -1,  1520,  1521,    -1,    33,    -1,  1522,    -1,  1524,    -1,
     394,    -1,   346,    -1,   265,    -1,   625,    -1,   522,    -1,
     626,    -1,   527,    -1,   571,    -1,   627,    -1,   157,    -1,
     528,    -1,   657,    -1,   628,    -1,   359,    -1,   529,    -1,
     360,    -1,   658,    -1,   652,    -1,   316,    -1,   530,    -1,
     225,    -1,   430,    -1,   629,    -1,   704,    -1,   431,    -1,
     531,    -1,   532,    -1,   572,    -1,   573,    -1,   473,    -1,
     474,    -1,   396,    -1,   691,    -1,   659,    -1,   574,    -1,
     432,    -1,   576,    -1,   570,    -1,   361,    -1,   533,    -1,
     534,    -1,   433,    -1,   535,    -1,   434,    -1,   468,    -1,
     536,    -1,   630,    -1,   475,    -1,   435,    -1,     5,    -1,
      23,    -1,   436,    -1,   476,    -1,   437,    -1,   398,    -1,
     397,    -1,   364,    -1,   537,    -1,   477,    -1,   438,    -1,
     478,    -1,   577,    -1,   399,    -1,   578,    -1,   400,    -1,
     631,    -1,   632,    -1,   439,    -1,   633,    -1,   440,    -1,
     441,    -1,   442,    -1,   401,    -1,   538,    -1,   479,    -1,
     480,    -1,   365,    -1,   579,    -1,   322,    -1,   634,    -1,
     695,    -1,   443,    -1,   402,    -1,    21,    -1,   660,    -1,
     481,    -1,   366,    -1,   582,    -1,   103,    -1,   583,    -1,
     698,    -1,   444,    -1,    14,    -1,   539,    -1,   483,    -1,
     540,    -1,   370,    -1,   584,    -1,   445,    -1,   484,    -1,
     585,    -1,   485,    -1,   486,    -1,   408,    -1,   575,    -1,
     541,    -1,   140,    -1,   234,    -1,   487,    -1,   542,    -1,
     635,    -1,   543,    -1,   544,    -1,   636,    -1,   446,    -1,
     447,    -1,   488,    -1,   678,    -1,   132,    -1,   147,    -1,
     545,    -1,   409,    -1,   586,    -1,   587,    -1,   410,    -1,
     331,    -1,   448,    -1,   661,    -1,   588,    -1,   546,    -1,
      13,    -1,   547,    -1,   548,    -1,   489,    -1,   490,    -1,
     591,    -1,   592,    -1,   593,    -1,   700,    -1,   112,    -1,
     662,    -1,   663,    -1,   153,    -1,   549,    -1,   449,    -1,
     332,    -1,   705,    -1,   491,    -1,   450,    -1,   374,    -1,
     412,    -1,   707,    -1,   376,    -1,   637,    -1,   580,    -1,
     699,    -1,   550,    -1,   523,    -1,   413,    -1,   638,    -1,
     667,    -1,   451,    -1,     7,    -1,   469,    -1,   623,    -1,
     524,    -1,     6,    -1,   525,    -1,     8,    -1,   595,    -1,
     596,    -1,    12,    -1,   639,    -1,   597,    -1,   552,    -1,
     492,    -1,   640,    -1,   452,    -1,   598,    -1,   493,    -1,
      10,    -1,    50,    -1,   494,    -1,   599,    -1,   686,    -1,
     701,    -1,    19,    -1,   495,    -1,   152,    -1,    22,    -1,
     600,    -1,   496,    -1,   553,    -1,   554,    -1,    20,    -1,
     601,    -1,   602,    -1,   352,    -1,   603,    -1,   497,    -1,
       9,    -1,   664,    -1,   709,    -1,   665,    -1,   604,    -1,
     472,    -1,   500,    -1,   501,    -1,   453,    -1,   555,    -1,
     383,    -1,   556,    -1,   502,    -1,   643,    -1,   417,    -1,
     557,    -1,   197,    -1,   148,    -1,   454,    -1,    18,    -1,
     151,    -1,   384,    -1,   455,    -1,   154,    -1,   418,    -1,
     353,    -1,   560,    -1,   385,    -1,   386,    -1,   456,    -1,
     503,    -1,   504,    -1,   644,    -1,   605,    -1,   419,    -1,
     606,    -1,   505,    -1,   457,    -1,   645,    -1,   338,    -1,
     420,    -1,   421,    -1,   506,    -1,   422,    -1,   219,    -1,
     388,    -1,   458,    -1,   507,    -1,   561,    -1,   303,    -1,
     646,    -1,   607,    -1,   647,    -1,   508,    -1,   510,    -1,
     511,    -1,   459,    -1,   512,    -1,   563,    -1,   513,    -1,
     460,    -1,   515,    -1,   608,    -1,   526,    -1,   609,    -1,
     610,    -1,   564,    -1,   341,    -1,   423,    -1,   611,    -1,
     516,    -1,   648,    -1,   342,    -1,   130,    -1,   612,    -1,
     613,    -1,   649,    -1,   461,    -1,   581,    -1,   614,    -1,
     158,    -1,   615,    -1,   616,    -1,   462,    -1,   708,    -1,
     666,    -1,   650,    -1,   463,    -1,   565,    -1,   239,    -1,
     389,    -1,   566,    -1,   517,    -1,   518,    -1,   519,    -1,
     464,    -1,   651,    -1,   617,    -1,   424,    -1,   520,    -1,
     465,    -1,   393,    -1,   618,    -1,   466,    -1,   619,    -1,
     567,    -1,   568,    -1,   569,    -1,   620,    -1,   426,    -1,
     621,    -1,   641,    -1,   642,    -1,   624,    -1,   622,    -1,
     521,    -1,    -1,   232,  1523,  1550,    -1,    -1,   594,  1525,
    1177,    -1,    -1,    -1,   519,  1450,  1527,  1530,  1528,  1529,
      -1,    -1,   192,   994,    -1,   567,  1426,    -1,    90,  1534,
     434,    14,   472,  1535,   434,    -1,    86,  1535,   434,    -1,
      87,  1535,   434,    -1,   624,  1531,    -1,    89,  1535,    -1,
      88,  1535,    -1,  1533,    -1,  1531,     5,  1533,    -1,  1454,
      -1,  1532,    14,  1536,    -1,  1532,    -1,  1534,     5,  1532,
      -1,  1536,    -1,  1535,     5,  1536,    -1,   524,    -1,  1537,
      -1,  1538,    -1,    19,  1538,    -1,    18,  1538,    -1,  1540,
      -1,  1489,    -1,   652,  1000,    -1,   652,  1000,   660,  1000,
      -1,  1539,    -1,  1457,    -1,   525,    -1,   469,    -1,   617,
      -1,   105,    -1,  1538,    21,  1537,    -1,  1538,  1516,    -1,
    1538,    20,  1537,    -1,  1538,    18,  1537,    -1,  1538,    19,
    1537,    -1,   629,   472,  1441,  1537,   434,    -1,   641,   472,
    1441,  1537,   434,    -1,   642,   472,  1441,  1537,   434,    -1,
     649,   472,  1441,  1537,   434,    -1,   537,   472,  1441,  1537,
     434,    -1,  1000,   472,  1541,   434,    -1,   578,   472,  1541,
     434,    -1,   472,  1537,   434,    -1,   485,   472,  1517,   434,
      -1,  1550,    -1,  1537,    -1,  1541,     5,  1537,    -1,    -1,
     424,  1186,   597,  1543,  1544,    -1,  1545,    -1,  1544,     5,
    1545,    -1,  1450,   660,  1454,    -1,  1450,   660,    20,    -1,
    1547,    -1,   232,  1548,    -1,  1548,    -1,  1164,    -1,  1000,
      -1,  1548,   660,  1549,    -1,    25,   660,  1548,   660,  1549,
      -1,    20,    -1,  1185,    -1,  1000,    -1,  1547,    -1,  1547,
     462,  1547,    -1,    34,    -1,    -1,    -1,   568,  1553,   905,
    1554,  1567,   369,    -1,    -1,   699,   948,    -1,    -1,   702,
      -1,   223,    -1,   319,   995,    -1,   110,   995,    -1,   349,
      -1,   348,    -1,   350,   997,  1555,  1556,    -1,   534,   948,
    1556,    -1,   145,    -1,   177,   995,    -1,   905,   607,     5,
     905,   435,    -1,   550,   905,    -1,   306,   995,    -1,   142,
    1562,     8,  1563,  1561,    -1,    -1,   587,   905,    -1,  1000,
      -1,  1000,    -1,   289,   995,    -1,   292,   995,   666,   905,
       5,   905,    -1,   292,   995,   659,   905,     5,   905,    -1,
      27,    -1,    -1,  1569,    -1,  1570,  1263,    -1,  1568,    -1,
    1569,  1568,    -1,    -1,  1571,  1572,    -1,   720,    -1,   721,
      -1,   722,    -1,   723,    -1,   740,    -1,   762,    -1,   776,
      -1,   777,    -1,   783,    -1,   784,    -1,   803,    -1,   877,
      -1,   878,    -1,   879,    -1,   880,    -1,   891,    -1,   892,
      -1,   893,    -1,   894,    -1,   895,    -1,   896,    -1,   897,
      -1,   950,    -1,   981,    -1,   985,    -1,  1007,    -1,  1009,
      -1,  1012,    -1,  1013,    -1,  1014,    -1,  1015,    -1,  1028,
      -1,  1037,    -1,  1059,    -1,  1060,    -1,  1062,    -1,  1066,
      -1,  1081,    -1,  1082,    -1,  1086,    -1,  1087,    -1,  1088,
      -1,  1089,    -1,  1097,    -1,  1112,    -1,  1132,    -1,  1143,
      -1,  1144,    -1,  1145,    -1,  1149,    -1,  1188,    -1,  1191,
      -1,  1193,    -1,  1199,    -1,  1200,    -1,  1203,    -1,  1206,
      -1,  1209,    -1,  1211,    -1,  1213,    -1,  1216,    -1,  1223,
      -1,  1228,    -1,  1232,    -1,  1233,    -1,  1234,    -1,  1246,
      -1,  1299,    -1,  1300,    -1,  1302,    -1,  1321,    -1,  1322,
      -1,  1342,    -1,  1345,    -1,  1374,    -1,  1376,    -1,  1467,
      -1,  1468,    -1,  1499,    -1,  1500,    -1,  1518,    -1,  1542,
      -1,  1551,    -1,  1552,    -1,  1557,    -1,  1558,    -1,  1560,
      -1,  1564,    -1,  1565,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const unsigned short yyrline[] =
{
       0,   987,   987,   990,   993,   999,  1005,  1012,  1016,  1016,
    1022,  1045,  1046,  1047,  1048,  1049,  1060,  1066,  1067,  1068,
    1069,  1070,  1075,  1076,  1087,  1090,  1093,  1093,  1097,  1100,
    1101,  1107,  1108,  1109,  1110,  1111,  1112,  1113,  1114,  1115,
    1116,  1117,  1118,  1119,  1120,  1121,  1122,  1123,  1126,  1127,
    1130,  1130,  1145,  1146,  1149,  1155,  1157,  1168,  1170,  1172,
    1174,  1178,  1180,  1242,  1246,  1250,  1250,  1260,  1264,  1267,
    1268,  1275,  1281,  1275,  1294,  1299,  1303,  1294,  1315,  1319,
    1315,  1327,  1332,  1327,  1351,  1358,  1362,  1350,  1388,  1388,
    1392,  1393,  1394,  1399,  1402,  1407,  1411,  1419,  1422,  1422,
    1428,  1432,  1447,  1445,  1463,  1463,  1478,  1478,  1481,  1481,
    1485,  1488,  1488,  1488,  1495,  1496,  1495,  1503,  1503,  1514,
    1514,  1533,  1536,  1539,  1542,  1545,  1548,  1561,  1566,  1566,
    1567,  1567,  1570,  1575,  1575,  1579,  1589,  1603,  1608,  1602,
    1619,  1625,  1633,  1634,  1637,  1637,  1640,  1644,  1649,  1656,
    1656,  1660,  1660,  1661,  1661,  1662,  1662,  1663,  1663,  1664,
    1664,  1672,  1676,  1682,  1686,  1701,  1704,  1707,  1710,  1713,
    1716,  1722,  1733,  1738,  1751,  1755,  1770,  1771,  1775,  1775,
    1779,  1779,  1779,  1780,  1785,  1785,  1788,  1788,  1797,  1798,
    1799,  1802,  1806,  1807,  1807,  1824,  1824,  1824,  1824,  1828,
    1835,  1836,  1839,  1839,  1843,  1844,  1845,  1846,  1851,  1851,
    1857,  1857,  1866,  1863,  1879,  1879,  1881,  1881,  1883,  1885,
    1887,  1889,  1892,  1896,  1896,  1897,  1897,  1901,  1901,  1913,
    1913,  1918,  1922,  1924,  1925,  1928,  1928,  1928,  1932,  1933,
    1934,  1935,  1942,  1943,  1944,  1945,  1948,  1949,  1950,  1951,
    1955,  1960,  1965,  1969,  1972,  1976,  1976,  1977,  1977,  1978,
    1978,  1979,  1980,  1981,  1982,  1983,  1984,  1987,  1988,  1989,
    2019,  2019,  2024,  2028,  2030,  2032,  2032,  2039,  2043,  2043,
    2047,  2048,  2049,  2050,  2051,  2052,  2053,  2059,  2059,  2062,
    2064,  2070,  2072,  2078,  2086,  2086,  2089,  2090,  2091,  2092,
    2093,  2094,  2095,  2101,  2104,  2104,  2117,  2117,  2124,  2125,
    2126,  2128,  2129,  2131,  2133,  2134,  2135,  2136,  2141,  2147,
    2153,  2154,  2156,  2158,  2159,  2160,  2161,  2162,  2163,  2166,
    2167,  2174,  2182,  2182,  2190,  2187,  2202,  2202,  2204,  2204,
    2212,  2212,  2215,  2218,  2219,  2224,  2236,  2240,  2243,  2246,
    2247,  2248,  2249,  2250,  2255,  2262,  2268,  2273,  2278,  2273,
    2291,  2293,  2298,  2303,  2303,  2303,  2307,  2307,  2310,  2310,
    2317,  2317,  2324,  2324,  2335,  2353,  2359,  2383,  2386,  2401,
    2404,  2417,  2419,  2421,  2423,  2425,  2427,  2429,  2435,  2437,
    2441,  2443,  2445,  2447,  2449,  2451,  2453,  2459,  2473,  2474,
    2475,  2476,  2477,  2481,  2482,  2483,  2487,  2492,  2499,  2500,
    2501,  2502,  2503,  2504,  2505,  2506,  2507,  2508,  2509,  2516,
    2516,  2521,  2521,  2524,  2530,  2538,  2544,  2554,  2555,  2563,
    2570,  2574,  2584,  2588,  2593,  2598,  2600,  2603,  2609,  2617,
    2630,  2635,  2641,  2646,  2651,  2652,  2658,  2729,  2740,  2749,
    2757,  2757,  2772,  2776,  2783,  2786,  2794,  2798,  2801,  2807,
    2816,  2821,  2829,  2832,  2835,  2840,  2847,  2852,  2857,  2862,
    2872,  2880,  2888,  2893,  2897,  2902,  2906,  2910,  2917,  2920,
    2923,  2927,  2931,  2935,  2939,  2947,  2957,  2962,  2955,  2978,
    2983,  2978,  3000,  3000,  3000,  3003,  3003,  3003,  3007,  3007,
    3007,  3011,  3011,  3011,  3015,  3021,  3027,  3033,  3039,  3045,
    3055,  3055,  3059,  3063,  3064,  3075,  3076,  3082,  3092,  3102,
    3112,  3113,  3116,  3121,  3127,  3131,  3135,  3138,  3144,  3147,
    3150,  3167,  3170,  3176,  3177,  3178,  3182,  3183,  3184,  3185,
    3186,  3188,  3189,  3190,  3192,  3193,  3197,  3198,  3203,  3207,
    3212,  3216,  3231,  3235,  3241,  3230,  3254,  3255,  3267,  3273,
    3267,  3287,  3287,  3289,  3290,  3294,  3294,  3298,  3298,  3303,
    3303,  3310,  3311,  3315,  3315,  3319,  3319,  3324,  3324,  3331,
    3335,  3336,  3337,  3342,  3342,  3345,  3345,  3349,  3349,  3353,
    3353,  3357,  3357,  3362,  3362,  3367,  3367,  3372,  3372,  3377,
    3377,  3393,  3397,  3392,  3405,  3408,  3422,  3439,  3440,  3441,
    3442,  3443,  3444,  3445,  3448,  3448,  3451,  3453,  3456,  3459,
    3462,  3467,  3472,  3475,  3480,  3485,  3490,  3497,  3498,  3505,
    3512,  3514,  3520,  3525,  3530,  3535,  3535,  3538,  3544,  3549,
    3552,  3559,  3559,  3561,  3564,  3567,  3572,  3577,  3582,  3589,
    3598,  3598,  3660,  3668,  3669,  3677,  3684,  3684,  3688,  3693,
    3699,  3703,  3707,  3713,  3717,  3721,  3727,  3727,  3735,  3736,
    3740,  3740,  3744,  3745,  3748,  3751,  3751,  3754,  3756,  3756,
    3759,  3761,  3761,  3762,  3764,  3764,  3773,  3780,  3771,  3801,
    3801,  3801,  3804,  3806,  3804,  3813,  3816,  3822,  3833,  3833,
    3837,  3843,  3843,  3847,  3848,  3852,  3862,  3863,  3864,  3867,
    3869,  3874,  3874,  3878,  3877,  3885,  3884,  3891,  3891,  3897,
    3897,  3904,  3904,  3910,  3910,  3916,  3916,  3922,  3922,  3926,
    3926,  3930,  3930,  3934,  3934,  3945,  3949,  3955,  3959,  3964,
    3969,  3974,  3975,  3976,  3980,  3979,  3992,  3997,  4002,  4002,
    4018,  4024,  4025,  4026,  4027,  4030,  4030,  4033,  4040,  4041,
    4042,  4043,  4044,  4045,  4046,  4047,  4048,  4053,  4053,  4055,
    4058,  4058,  4060,  4064,  4067,  4068,  4071,  4071,  4076,  4079,
    4080,  4081,  4082,  4083,  4084,  4085,  4086,  4087,  4088,  4089,
    4090,  4091,  4092,  4093,  4094,  4095,  4096,  4100,  4118,  4118,
    4118,  4145,  4156,  4163,  4169,  4175,  4181,  4193,  4218,  4217,
    4234,  4234,  4238,  4239,  4247,  4248,  4249,  4250,  4251,  4252,
    4259,  4260,  4262,  4263,  4267,  4272,  4273,  4274,  4275,  4276,
    4277,  4278,  4279,  4280,  4281,  4282,  4285,  4287,  4287,  4289,
    4293,  4293,  4302,  4307,  4323,  4329,  4301,  4343,  4357,  4367,
    4356,  4380,  4387,  4387,  4392,  4398,  4406,  4411,  4412,  4415,
    4418,  4418,  4426,  4432,  4443,  4444,  4448,  4452,  4465,  4447,
    4478,  4484,  4478,  4495,  4496,  4500,  4500,  4507,  4507,  4522,
    4522,  4536,  4547,  4546,  4558,  4554,  4571,  4568,  4581,  4581,
    4583,  4584,  4586,  4587,  4590,  4591,  4592,  4594,  4599,  4604,
    4610,  4612,  4613,  4616,  4617,  4620,  4622,  4629,  4632,  4635,
    4638,  4642,  4646,  4647,  4648,  4649,  4650,  4654,  4659,  4659,
    4662,  4689,  4747,  4747,  4750,  4754,  4758,  4801,  4843,  4844,
    4845,  4848,  4862,  4874,  4874,  4879,  4880,  4886,  4946,  5003,
    5008,  5015,  5020,  5028,  5034,  5067,  5070,  5071,  5112,  5155,
    5156,  5160,  5161,  5165,  5218,  5222,  5225,  5231,  5242,  5249,
    5257,  5257,  5260,  5261,  5262,  5263,  5264,  5267,  5270,  5276,
    5279,  5283,  5288,  5296,  5301,  5308,  5311,  5317,  5319,  5319,
    5319,  5323,  5343,  5350,  5357,  5360,  5374,  5381,  5382,  5385,
    5386,  5390,  5396,  5401,  5407,  5408,  5413,  5417,  5417,  5421,
    5422,  5425,  5426,  5430,  5438,  5441,  5447,  5448,  5450,  5452,
    5456,  5456,  5457,  5462,  5470,  5471,  5476,  5477,  5479,  5492,
    5494,  5495,  5497,  5500,  5503,  5506,  5510,  5513,  5516,  5520,
    5524,  5528,  5531,  5535,  5538,  5539,  5540,  5543,  5546,  5549,
    5552,  5555,  5558,  5561,  5577,  5585,  5585,  5587,  5594,  5598,
    5603,  5618,  5616,  5636,  5637,  5641,  5646,  5647,  5651,  5652,
    5654,  5655,  5657,  5657,  5666,  5675,  5675,  5685,  5686,  5691,
    5692,  5695,  5708,  5722,  5727,  5732,  5737,  5747,  5747,  5751,
    5754,  5754,  5756,  5766,  5775,  5782,  5784,  5788,  5791,  5791,
    5795,  5794,  5802,  5801,  5812,  5811,  5818,  5817,  5821,  5820,
    5823,  5823,  5839,  5838,  5860,  5861,  5862,  5863,  5864,  5865,
    5868,  5868,  5874,  5874,  5877,  5877,  5893,  5894,  5895,  5904,
    5916,  5917,  5920,  5921,  5924,  5927,  5927,  5932,  5932,  5953,
    5958,  5964,  5965,  5966,  5970,  5971,  5972,  5973,  5977,  5987,
    5989,  5994,  5997,  6002,  6008,  6015,  6022,  6031,  6038,  6045,
    6052,  6059,  6068,  6068,  6070,  6070,  6073,  6074,  6075,  6076,
    6077,  6078,  6079,  6080,  6081,  6082,  6085,  6085,  6088,  6089,
    6090,  6091,  6094,  6094,  6097,  6097,  6100,  6101,  6102,  6103,
    6104,  6105,  6106,  6107,  6109,  6110,  6111,  6112,  6114,  6115,
    6116,  6117,  6119,  6120,  6121,  6122,  6123,  6124,  6125,  6126,
    6130,  6137,  6146,  6158,  6167,  6178,  6182,  6186,  6192,  6157,
    6205,  6208,  6216,  6228,  6230,  6235,  6243,  6253,  6256,  6260,
    6268,  6234,  6277,  6281,  6285,  6289,  6281,  6299,  6300,  6301,
    6302,  6307,  6309,  6312,  6316,  6319,  6326,  6331,  6332,  6333,
    6334,  6339,  6340,  6346,  6346,  6346,  6351,  6351,  6351,  6359,
    6360,  6364,  6365,  6370,  6371,  6372,  6373,  6374,  6377,  6379,
    6379,  6382,  6383,  6387,  6388,  6391,  6392,  6395,  6398,  6401,
    6407,  6408,  6420,  6421,  6426,  6427,  6428,  6432,  6435,  6441,
    6444,  6452,  6453,  6459,  6463,  6467,  6473,  6476,  6485,  6488,
    6491,  6494,  6497,  6500,  6503,  6510,  6513,  6520,  6523,  6529,
    6532,  6539,  6542,  6549,  6550,  6555,  6559,  6562,  6568,  6571,
    6577,  6584,  6585,  6589,  6599,  6602,  6608,  6610,  6615,  6616,
    6620,  6622,  6628,  6629,  6642,  6653,  6654,  6655,  6656,  6657,
    6658,  6659,  6660,  6661,  6664,  6667,  6673,  6673,  6679,  6679,
    6690,  6703,  6713,  6713,  6718,  6718,  6722,  6726,  6727,  6733,
    6734,  6739,  6743,  6750,  6753,  6760,  6759,  6770,  6774,  6778,
    6785,  6788,  6788,  6801,  6805,  6805,  6820,  6822,  6824,  6826,
    6828,  6830,  6832,  6834,  6840,  6850,  6857,  6862,  6863,  6867,
    6870,  6871,  6874,  6875,  6876,  6879,  6884,  6891,  6892,  6898,
    6910,  6911,  6912,  6915,  6915,  6920,  6925,  6930,  6931,  6934,
    6935,  6940,  6945,  6949,  6954,  6955,  6959,  6966,  6970,  6971,
    6976,  6978,  6982,  6983,  6987,  6988,  6989,  6990,  6994,  6995,
    7000,  7001,  7006,  7007,  7012,  7013,  7018,  7023,  7024,  7029,
    7030,  7034,  7035,  7040,  7047,  7052,  7057,  7061,  7062,  7067,
    7068,  7074,  7075,  7076,  7081,  7082,  7088,  7091,  7094,  7101,
    7102,  7103,  7104,  7118,  7123,  7124,  7127,  7129,  7136,  7139,
    7145,  7153,  7157,  7161,  7165,  7169,  7172,  7175,  7182,  7189,
    7194,  7198,  7199,  7205,  7208,  7219,  7226,  7232,  7235,  7242,
    7249,  7255,  7256,  7262,  7263,  7264,  7267,  7268,  7273,  7273,
    7277,  7285,  7286,  7289,  7292,  7297,  7298,  7303,  7306,  7312,
    7315,  7321,  7324,  7330,  7333,  7340,  7341,  7370,  7371,  7376,
    7384,  7389,  7392,  7395,  7398,  7404,  7405,  7409,  7412,  7415,
    7416,  7421,  7424,  7427,  7430,  7433,  7436,  7439,  7442,  7447,
    7453,  7454,  7455,  7456,  7457,  7459,  7460,  7462,  7463,  7468,
    7471,  7475,  7481,  7482,  7483,  7484,  7496,  7497,  7498,  7502,
    7503,  7507,  7508,  7509,  7510,  7511,  7513,  7515,  7516,  7517,
    7518,  7519,  7520,  7521,  7522,  7524,  7526,  7528,  7529,  7531,
    7532,  7534,  7535,  7536,  7537,  7539,  7543,  7544,  7550,  7552,
    7553,  7554,  7555,  7560,  7564,  7568,  7572,  7579,  7583,  7584,
    7585,  7593,  7594,  7595,  7606,  7613,  7618,  7619,  7620,  7628,
    7629,  7630,  7647,  7656,  7657,  7658,  7662,  7665,  7670,  7675,
    7680,  7688,  7692,  7697,  7698,  7706,  7709,  7712,  7726,  7740,
    7753,  7754,  7758,  7758,  7758,  7758,  7758,  7758,  7759,  7762,
    7767,  7767,  7767,  7767,  7767,  7767,  7769,  7772,  7778,  7778,
    7778,  7778,  7778,  7778,  7778,  7779,  7779,  7779,  7779,  7779,
    7779,  7779,  7779,  7782,  7783,  7784,  7787,  7796,  7796,  7802,
    7802,  7809,  7809,  7815,  7815,  7823,  7824,  7825,  7828,  7828,
    7831,  7832,  7833,  7844,  7847,  7853,  7858,  7865,  7878,  7879,
    7876,  7897,  7908,  7911,  7916,  7928,  7931,  7935,  7938,  7939,
    7945,  7948,  7949,  7958,  7967,  7972,  7973,  7974,  7975,  7982,
    7985,  7991,  7994,  8004,  8013,  8016,  8019,  8025,  8031,  8034,
    8037,  8040,  8046,  8048,  8050,  8052,  8054,  8056,  8057,  8058,
    8059,  8060,  8061,  8062,  8064,  8066,  8068,  8070,  8072,  8074,
    8076,  8077,  8082,  8083,  8090,  8093,  8102,  8106,  8113,  8113,
    8117,  8117,  8122,  8122,  8126,  8126,  8130,  8136,  8136,  8139,
    8139,  8145,  8152,  8153,  8154,  8158,  8159,  8162,  8163,  8167,
    8173,  8183,  8184,  8192,  8193,  8194,  8195,  8196,  8197,  8201,
    8202,  8203,  8207,  8207,  8219,  8220,  8224,  8225,  8226,  8227,
    8228,  8229,  8230,  8231,  8232,  8233,  8234,  8235,  8236,  8237,
    8238,  8239,  8240,  8241,  8242,  8243,  8244,  8245,  8246,  8247,
    8248,  8249,  8250,  8251,  8252,  8253,  8254,  8255,  8256,  8257,
    8258,  8259,  8260,  8261,  8262,  8263,  8264,  8265,  8266,  8267,
    8268,  8269,  8270,  8271,  8272,  8273,  8274,  8275,  8276,  8277,
    8278,  8279,  8280,  8281,  8282,  8283,  8284,  8285,  8286,  8287,
    8288,  8289,  8290,  8291,  8292,  8293,  8294,  8295,  8296,  8297,
    8298,  8299,  8300,  8301,  8302,  8303,  8304,  8305,  8306,  8307,
    8308,  8309,  8310,  8311,  8312,  8313,  8314,  8315,  8316,  8317,
    8318,  8319,  8320,  8321,  8322,  8323,  8324,  8325,  8326,  8327,
    8328,  8329,  8330,  8331,  8332,  8333,  8334,  8335,  8336,  8337,
    8338,  8339,  8340,  8341,  8342,  8343,  8344,  8345,  8346,  8347,
    8348,  8349,  8350,  8351,  8352,  8353,  8354,  8355,  8356,  8357,
    8358,  8359,  8360,  8361,  8362,  8363,  8364,  8365,  8366,  8367,
    8368,  8369,  8370,  8371,  8372,  8373,  8374,  8375,  8376,  8377,
    8378,  8379,  8380,  8381,  8382,  8383,  8384,  8385,  8386,  8387,
    8388,  8389,  8390,  8391,  8392,  8393,  8394,  8395,  8396,  8397,
    8398,  8399,  8400,  8401,  8402,  8403,  8404,  8405,  8406,  8407,
    8408,  8409,  8410,  8411,  8412,  8413,  8414,  8415,  8416,  8417,
    8418,  8419,  8420,  8421,  8422,  8423,  8424,  8425,  8426,  8427,
    8429,  8430,  8431,  8432,  8433,  8434,  8435,  8436,  8437,  8438,
    8439,  8440,  8441,  8442,  8443,  8444,  8445,  8446,  8447,  8448,
    8449,  8450,  8451,  8452,  8453,  8454,  8455,  8456,  8457,  8458,
    8459,  8460,  8461,  8462,  8463,  8464,  8465,  8466,  8467,  8468,
    8469,  8470,  8471,  8472,  8473,  8474,  8475,  8476,  8477,  8478,
    8479,  8480,  8481,  8482,  8483,  8484,  8485,  8486,  8487,  8488,
    8489,  8490,  8491,  8492,  8493,  8494,  8495,  8496,  8497,  8498,
    8499,  8500,  8501,  8502,  8503,  8504,  8505,  8506,  8507,  8508,
    8509,  8510,  8511,  8512,  8513,  8514,  8515,  8516,  8517,  8518,
    8519,  8520,  8521,  8522,  8523,  8524,  8525,  8526,  8527,  8528,
    8529,  8530,  8531,  8532,  8533,  8534,  8535,  8536,  8537,  8538,
    8539,  8540,  8541,  8542,  8543,  8551,  8551,  8558,  8558,  8646,
    8650,  8646,  8659,  8663,  8669,  8677,  8687,  8697,  8709,  8712,
    8731,  8757,  8760,  8766,  8769,  8774,  8777,  8785,  8793,  8806,
    8809,  8817,  8820,  8823,  8831,  8835,  8838,  8841,  8844,  8848,
    8849,  8850,  8851,  8852,  8858,  8859,  8860,  8861,  8862,  8863,
    8864,  8865,  8866,  8867,  8868,  8869,  8870,  8871,  8875,  8881,
    8882,  8890,  8890,  8898,  8898,  8902,  8906,  8921,  8941,  8943,
    8949,  8950,  8951,  8952,  8962,  8963,  8964,  8969,  8995,  9051,
    9065,  9068,  9064,  9087,  9087,  9093,  9094,  9097,  9098,  9099,
    9100,  9101,  9102,  9103,  9114,  9117,  9122,  9126,  9131,  9135,
    9140,  9144,  9147,  9151,  9154,  9159,  9163,  9174,  9180,  9180,
    9181,  9182,  9189,  9199,  9199,  9201,  9202,  9203,  9204,  9205,
    9206,  9207,  9208,  9209,  9210,  9211,  9212,  9213,  9214,  9215,
    9216,  9217,  9218,  9219,  9220,  9221,  9222,  9223,  9224,  9225,
    9226,  9227,  9228,  9229,  9230,  9231,  9232,  9233,  9234,  9235,
    9236,  9237,  9238,  9239,  9240,  9241,  9242,  9243,  9244,  9245,
    9246,  9247,  9248,  9249,  9250,  9251,  9252,  9253,  9254,  9255,
    9256,  9257,  9258,  9259,  9260,  9261,  9262,  9263,  9264,  9265,
    9266,  9267,  9268,  9269,  9270,  9271,  9272,  9273,  9274,  9275,
    9276,  9277,  9278,  9279,  9280,  9281,  9282,  9283,  9284,  9285,
    9286,  9287,  9288,  9289
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
  "KW_CEND", "USER_DTYPE", "SQL_TEXT", "KW_WHENEVER_SET", "DYNAMIC_ARRAY", 
  "RESIZE_ARRAY", "ALLOCATE_ARRAY", "DEALLOCATE_ARRAY", "BEFORE_INSERT", 
  "CONCAT_PIPES", "BEFORE_DELETE", "AFTER_INSERT", "AFTER_DELETE", 
  "EXECUTE_IMMEDIATE", "DELETE_ROW_EQUAL_TRUE", "INSERT_ROW_EQUAL_TRUE", 
  "DELETE_ROW_EQUAL_FALSE", "INSERT_ROW_EQUAL_FALSE", 
  "CURRENT_ROW_DISPLAY_EQUAL", "MAXCOUNT", "ALTER_TABLE", "ALTER_INDEX", 
  "NEXT_SIZE", "WHENEVER_ERROR_CONTINUE", "WHENEVER_ANY_ERROR_CONTINUE", 
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
  "LOCK_MODE_ROW", "TO_PIPE", "TO_PRINTER", "STATUSBOX", "CONNECT_TO", 
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
  "CLIPPED", "CLOSE_BRACKET", "COLUMNS", "COMMENT", "CONNECT", "CURRENT", 
  "DBYNAME", "DECIMAL", "DECLARE", "DEFAULT", "DISPLAY", "ENDCODE", 
  "EXECUTE", "FOREACH", "FOREIGN", "GLOBALS", "INFIELD", "INTEGER", 
  "KWWINDOW", "MAGENTA", "OPTIONS", "PERCENT", "PREPARE", "PROGRAM", 
  "RECOVER", "REVERSE", "SECTION", "SESSION", "SYNONYM", "THRU", 
  "TRAILER", "UPSHIFT", "VARCHAR", "WAITING", "CLOSE_SHEV", 
  "CLOSE_SQUARE", "KW_FALSE", "NOT_IN", "ONKEY", "OPEN_BRACKET", "BORDER", 
  "BOTTOM", "COLUMN", "COMMIT", "CREATE", "CURSOR", "DEFINE", "DELETE", 
  "DOUBLE", "END_IF", "ESCAPE", "EXISTS", "EXTEND", "EXTENT", "FINISH", 
  "FORMAT", "HAVING", "HEADER", "INSERT", "LOCATE", "MARGIN", "MEMORY", 
  "MINUTE", "MODIFY", "NORMAL", "EQUAL_EQUAL", "OPEN_SHEV", "OPEN_SQUARE", 
  "OPTION", "OUTPUT", "PROMPT", "PUBLIC", "RECORD", "REPORT", "REVOKE", 
  "SCHEMA", "SCROLL_USING", "SCROLL", "SECOND", "SELECT", "SERIAL", 
  "SETL", "SHARED", "SPACES", "UNIQUE", "UNLOCK", "UPDATE", "VALUES", 
  "YELLOW", "AFTER", "KWLINE", "KW_NULL", "KW_TRUE", "SINGLE_KEY", 
  "ALTER", "ARRAY", "ASCII", "AUDIT", "BLACK", "BLINK", "CHECK", "CLEAR", 
  "CLOSE", "CODE_C", "COUNT", "DEFER", "ERROR", "EVERY", "FETCH", "FIRST", 
  "FLOAT", "FLUSH", "FOUND", "GRANT", "GREEN", "GROUP", "INDEX", "KWFORM", 
  "LABEL", "LOCAL", "MONEY", "MONTH", "ORDER", "OUTER", "PAUSE", 
  "PRINT_IMAGE", "PRINT_FILE", "PRINT", "RIGHT", "DOUBLE_COLON", 
  "SEMICOLON", "SLEEP", "TUPLE", "UNION", "WHERE", "WHILE", "WHITE", 
  "CCODE", "ANSI", "BLUE", "BOLD", "BYTE", "FCALL", "CASE", "CYAN", 
  "DATE", "DESC", "KWDOWN", "TAB", "DROP", "ELSE", "EXEC", "EXIT", "FREE", 
  "FROM", "GOTO", "HELP_FILE", "LANG_FILE", "HELP", "HIDE", "HOUR", 
  "INTO", "LAST", "LEFT", "LIKE", "MAIN", "MENU", "MODE", "NEED", "NEXT", 
  "NOCR", "OPEN", "QUIT", "REAL", "ROWS", "SHOW", "SIZE", "SKIP", "SOME", 
  "STEP", "STOP", "TEMP", "TEXT", "THEN", "USER", "WAIT", "WHEN", "WITH", 
  "WORK", "YEAR", "KW_IS", "XSET", "ADD", "ALL", "ANY", "ASC", "AVG", 
  "COLON", "DAY", "DBA", "DEC", "DIM", "FKEY", "FOR", "KEY", "KWNO", 
  "LET", "LOG", "XMAX", "XMIN", "PAD", "PUT", "RED", "ROW", "RUN", "SQL", 
  "SUM", "TOP", "USE", "ATSIGN", "AS_TIFF", "AS_GIF", "AS_PNG", "AS_JPEG", 
  "AS", "AT", "BY", "DOT", "GO", "IF", "IN", "OF", "ON", "TO", "KWUP", 
  "FONT_NAME", "FONT_SIZE", "PAPER_SIZE_IS_LETTER", "PAPER_SIZE_IS_LEGAL", 
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
  "TILDE", "ILIKE", "DROP_TRIGGER", "FGL_ISDYNARR_ALLOCATED", 
  "FGL_DYNARR_EXTENTSIZE", "FILLFACTOR", "$accept", "pause_screen_on_cmd", 
  "pause_screen_off_cmd", "start_rpc_cmd", "stop_rpc_cmd", "valid_port", 
  "remote_func_list", "remote_func", "arr_expr", "arr_next_math", 
  "arr_int_sign", "opt_attributes", "attributes_def", "@1", "attribs_sec", 
  "attribute", "win_attributes", "win_attributes_def", "@2", 
  "wattribs_sec", "wattribute", "call_cmd", "call_ext", "@3", "@4", "@5", 
  "@6", "@7", "@8", "@9", "@10", "@11", "@12", "@13", "@14", "@15", 
  "opt_return", "opt_return_remote", "opt_func_call_args", 
  "func_call_args", "func_arg", "remote_host_name", "remote_func_name", 
  "case_cmd", "@16", "@17", "when_unit", "when_unit_expr", 
  "end_case_command", "op_otherwise_command", "@18", 
  "op_otherwise_command_expr", "@19", "when_command", "@20", 
  "when_command_expr", "@21", "close_cmd", "code_cmd", "emb_code", 
  "sql_code", "sql_code_part", "c_code", "c_code_part", "comment_cmd", 
  "construct_cmd", "@22", "@23", "constr_rest", "end_constr", 
  "constr_col_list", "constr_col", "constr_extra_commands", 
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
  "dealloc_arr_cmd", "resize_arr_cmd", "error_cmd", "exit_prog_cmd", 
  "ext_cmd", "continue_cmd", "fgl_expr_c", "fgl_next", 
  "op_fgl_expr_ret_list", "fgl_expr_ret", "fgl_expr_ret_list", 
  "fgl_expr_list", "fgl_expr_concat", "fgl_expr", "int_sign", 
  "boolean_expr", "initial_expr", "literal_expr", "variable_entry_2", 
  "variable_entry", "report_only_expr", "@57", "and_or_expr", 
  "inexpr_list", "in_expr", "null_expr", "string_match_expr", "clip_expr", 
  "using_expr", "math_expr", "comparison_expr", "reset_cnt", 
  "function_call_expr2", "@58", "@59", "@60", "@61", "function_callb", 
  "@62", "@63", "@64", "@65", "@66", "@67", "@68", "@69", "op_extend_d", 
  "op_extend_i", "function_call_expr", "builtin_expr", "builtin_funcs", 
  "pdf_expr", "interval_func_params", "numeric_time_interval", 
  "numeric_time_unit_small", "numeric_time_unit_big", 
  "field_name_list_as_struct", "field_name_list_or_char_as_struct", 
  "foreach_cmd", "@70", "@71", "@72", "opt_foreach_using_part", 
  "formhandler_def", "@73", "@74", "op_input_section", "op_bef_ev_list", 
  "bef_ev_list", "bef_ev", "@75", "@76", "op_aft_ev_list", "aft_ev_list", 
  "aft_ev", "@77", "@78", "input_section", "input_sub_section", 
  "in_variable_list", "in_id_list", "in_bn_variable_list", "field_ops", 
  "field_op", "@79", "@80", "@81", "@82", "@83", "for_cmd", "@84", "@85", 
  "for_step", "free_cmd", "line_no", "file_name", "a_number", "coords", 
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
  "@100", "@101", "@102", "@103", "bef_field_list_as_struct", 
  "aft_field_list_as_struct", "next_field_cmd", "next_form_cmd", 
  "next_field", "input_cmd", "@104", "inp_rest", "@105", "scroll_cmd", 
  "up_or_down", "op_help", "input_array_attributes", 
  "input_array_attributes_int", "on_key_command", "@106", "key_val", 
  "@107", "accept_key", "single_key_val", "key_do", "key_value_list", 
  "key_value", "key_value_1", "label_cmd", "let_cmd", "@108", "@109", 
  "op_expr_null", "linked_cmd", "linked_del_cmd", "linked_upd_cmd", 
  "locate_cmd", "module", "@110", "op_module_header", "module_header", 
  "module_entry", "func_main_def", "func_or_main2", "at_term_cmd", 
  "func_or_main", "module_code", "op_code", "module_define_section", 
  "ldeffunction", "func_def", "@111", "@112", "@113", "@114", 
  "end_func_command", "main_def", "@115", "@116", "return_cmd", 
  "op_fgl_expr_list", "db_section", "module_globals_section", 
  "actual_globals_section", "xglobals_entry", "globals_entry", "@117", 
  "glob_section", "mem_func_def", "@118", "@119", "@120", "menu_def", 
  "@121", "@122", "menu_handler_elements", "menu_handler_element", "@123", 
  "@124", "menu_cmd", "@125", "end_menu_command", "menu_block_command", 
  "@126", "@127", "@128", "menu_commands", "opt_key", "menu_opt_name", 
  "menu_optional_desc", "next_option_cmd", "show_option_cmd", 
  "hide_option_cmd", "opt_name", "opt_name_list", "menu_title", 
  "message_cmd", "msg_next", "gui_message", "msg_start", "op_msg_wait", 
  "msg_wait", "variable", "var_int", "varsetidentdot", "var", 
  "assoc_var_read", "assoc_var_write", "assoc_sub", "dot_part_var", 
  "array_r_variable", "array_r_variable_or_ident", "arr_subscripts", 
  "num_list", "num_list_element", "let_variable", "let_var", 
  "let_var_dot", "let_array_r_variable", "op_param_var_list", 
  "fparam_var_list", "ibind_var_list", "func_def_var", "ibind_var", 
  "obind_var_list", "obind_var", "obind_var_let_list", "obind_let_var", 
  "use_arr_var", "obind_var_list_ord", "obind_var_ord", 
  "optional_asc_desc", "array_r_varid", "init_bind_var_list", 
  "init_bind_var", "open_window_cmd", "op_at_statusbox", 
  "op_size_statusbox", "open_statusbox_cmd", "formhandler_name", 
  "open_form_cmd", "open_form_rest", "open_form_gui", "op_at_gui", 
  "op_like_gui", "op_absolute", "open_session_cmd", "open_cursor_cmd", 
  "user_details", "op_disable", "connect_cmd", "op_connect_as", 
  "con_user_details", "options_cmd", "opt_options", "opt_allopts", 
  "prepare_cmd", "var_or_char", "execute_cmd", "stmt_id", "prompt_cmd", 
  "@129", "opt_timeout", "gui_prompt_cmd", "opt_char", "prompt_key_sec", 
  "prompt_key_clause", "on_key_command_prompt", "@130", "prompt_title", 
  "put_cmd", "@131", "put_from", "put_val_list", "put_val", "start_cmd", 
  "rout", "rep_name", "op_values", "output_cmd", "finish_cmd", 
  "term_rep_cmd", "report_section", "format_section", "format_actions", 
  "format_action", "@132", "@133", "@134", "@135", "@136", "@137", "@138", 
  "report_cmd", "need_command", "@139", "op_lines", "skip_command", 
  "@140", "opt_rep_expr_list", "xrep_expr_list", "xxrep_expr_list", 
  "opt_print_at", "print_command", "@141", "print_file_command", 
  "print_img_command", "opt_scaling", "img_types", "blob_var", "opt_semi", 
  "rep_expr_list", "rep_expr", "rep_agg", "op_output_section", 
  "output_commands", "output_command", "pdf_output_commands", "nval", 
  "nval_number", "pdf_op_output_section", "pdf_output_command", 
  "op_rep_order_by", "report_def", "@142", "@143", "@144", "@145", "@146", 
  "@147", "rep_where", "pause_command", "pause_msg", "pdf_report_def", 
  "@148", "@149", "@150", "@151", "@152", "@153", "pdf_report_section", 
  "pdf_functions", "@154", "@155", "@156", "op_wordwrap", "run_cmd", 
  "drops_cmd", "drops_c", "create_cmd", "create_c_2_ss", "@157", "@158", 
  "@159", "@160", "opt_cr_table_extra", "cr_table_extra", 
  "cr_table_extra_entry", "space_name", "op_cr_index_extra", 
  "cr_index_extra", "cr_index_extra_entry", "create_c_1", "op_no_log", 
  "idx_column_list", "idx_column", "table_element_list_ss", 
  "table_element_ss", "upd_stats_cmd", "alter_cmd", "alter_clauses_ss", 
  "alter_clause_ss", "alter_add_clause_ss", "add_column_clause_ss", 
  "add_column_clauses_ss", "alter_drop_clause", "drop_column_list", 
  "drop_column", "alter_modify_clause_ss", "modify_column_clauses_ss", 
  "modify_column_clause_ss", "alter_lock_mode", "alter_modify_next", 
  "alter_add_constraint_clause", "table_constraint_definition_list_ss", 
  "opt_constraint_name", "alter_drop_constraint_clause", 
  "constraint_names", "constraint_name", "set_cmd", "op_conn_id", 
  "op_fgl_expr", "sleep_cmd", "rollback_statement", "insert_statement_ss", 
  "@161", "ins_2_ss", "@162", "op_insert_column_list", 
  "insert_column_list", "insert_value_list_ss", "insert_value_ss", 
  "fetch_statement", "@163", "declare_cursor_name", "fetch_part", 
  "opt_into_fetch_part", "@164", "opt_foreach_into_fetch_part", "@165", 
  "fetch_place", "delete_statement_position", 
  "delete_statement_search_ss", "order_by_clause", 
  "sort_specification_list", "sort_specification", "sort_spec", 
  "op_asc_desc", "begin_statement", "commit_statement", "op_exclusive", 
  "set_database_cmd", "var_ident_qchar", "sql_cmd", "@166", 
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
  "s_curr", "e_curr", "dbase_name", "flush_cmd", "declare_cmd", "@167", 
  "@168", "@169", "@170", "curs_forupdate", "cur_update_list", "colident", 
  "cursor_specification_all_ss", "cursor_specification_sel_ss", 
  "select_statement_full_ss", "select_statement_ss", "@171", "@172", 
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
  "units_qual", "extend_qual_ss", "sql_block_cmd", "@173", "sql_block", 
  "sql_block_entry", "in_var", "@174", "sql_block_into", "@175", 
  "update_statement_ss", "@176", "@177", "where_upd_ss", 
  "set_clause_list_ss", "upd_columns_ss", "upd_column_name", "col_1_ss", 
  "upd_col_list", "upd_val_list_ss", "upd_val_ss", 
  "upd_value_expression_ss", "upd_value_expression_initial_ss", 
  "upd_value_expression_complex_ss", "upd_var_ident_ibind_ss", 
  "upd_value_expr_list_ss", "validate_cmd", "@178", "validate_tab_list", 
  "validate_tab", "var_ident", "var2", "var3", "aft_dot", 
  "var_ident_ibind_ss", "whenever_cmd", "while_cmd", "@179", "@180", 
  "op_clr_fields", "op_to_defs", "clear_cmd", "current_win_cmd", 
  "window_type", "show_cmd", "op_mnfile", "menu_name", "menu_handler", 
  "hide_cmd", "move_cmd", "NAMED", "commands", "all_commands", "command1", 
  "commands_all", "@181", "commands_all1", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const unsigned short yytoknum[] =
{
       0,   256,  1703,  1704,  1705,  1609,  1649,  1604,  1541,  1624,
    1421,  1527,  1523,  1438,  1599,  1339,  1396,  1469,  1635,  1622,
    1528,  1555,  1623,  1403,  1706,  1707,  1708,  1709,  1710,  1711,
    1712,  1713,  1714,  1715,  1716,  1000,  1001,  1002,  1003,  1004,
    1005,  1006,  1007,  1008,  1009,  1010,  1011,  1012,  1013,  1014,
    1015,  1016,  1017,  1018,  1019,  1020,  1021,  1022,  1023,  1024,
    1025,  1026,  1027,  1028,  1029,  1030,  1031,  1032,  1033,  1034,
    1035,  1036,  1037,  1038,  1039,  1040,  1041,  1042,  1043,  1044,
    1045,  1046,  1047,  1048,  1049,  1050,  1051,  1052,  1053,  1054,
    1055,  1056,  1057,  1058,  1059,  1060,  1061,  1062,  1063,  1064,
    1065,  1066,  1067,  1068,  1069,  1070,  1071,  1072,  1073,  1074,
    1075,  1076,  1077,  1078,  1079,  1080,  1081,  1082,  1083,  1084,
    1085,  1086,  1087,  1088,  1089,  1090,  1091,  1092,  1093,  1094,
    1095,  1096,  1097,  1098,  1099,  1100,  1101,  1102,  1103,  1104,
    1105,  1106,  1107,  1108,  1109,  1110,  1111,  1112,  1113,  1114,
    1115,  1116,  1117,  1118,  1119,  1120,  1121,  1122,  1123,  1124,
    1125,  1126,  1127,  1128,  1129,  1130,  1131,  1132,  1133,  1134,
    1135,  1136,  1137,  1138,  1139,  1140,  1141,  1142,  1143,  1144,
    1145,  1146,  1147,  1148,  1149,  1150,  1151,  1152,  1153,  1154,
    1155,  1156,  1157,  1158,  1159,  1160,  1161,  1162,  1163,  1164,
    1165,  1166,  1167,  1168,  1169,  1170,  1171,  1172,  1173,  1174,
    1175,  1176,  1177,  1178,  1179,  1180,  1181,  1182,  1183,  1184,
    1185,  1186,  1187,  1188,  1189,  1190,  1191,  1192,  1193,  1194,
    1195,  1196,  1197,  1198,  1199,  1200,  1201,  1202,  1203,  1204,
    1205,  1206,  1207,  1208,  1209,  1210,  1211,  1212,  1213,  1214,
    1215,  1216,  1217,  1218,  1219,  1220,  1221,  1222,  1223,  1224,
    1225,  1226,  1227,  1228,  1229,  1230,  1231,  1232,  1233,  1234,
    1235,  1236,  1237,  1238,  1239,  1240,  1241,  1242,  1243,  1244,
    1245,  1246,  1247,  1248,  1249,  1250,  1251,  1252,  1253,  1254,
    1255,  1256,  1257,  1258,  1259,  1260,  1261,  1262,  1263,  1264,
    1265,  1266,  1267,  1268,  1269,  1270,  1271,  1272,  1273,  1274,
    1275,  1276,  1277,  1278,  1279,  1280,  1281,  1282,  1283,  1284,
    1285,  1286,  1287,  1288,  1289,  1290,  1291,  1292,  1293,  1294,
    1295,  1296,  1297,  1298,  1299,  1300,  1301,  1302,  1303,  1304,
    1305,  1306,  1307,  1308,  1309,  1310,  1311,  1312,  1313,  1314,
    1315,  1316,  1317,  1318,  1319,  1320,  1321,  1322,  1323,  1324,
    1325,  1326,  1327,  1328,  1329,  1330,  1331,  1332,  1333,  1334,
    1335,  1336,  1337,  1338,  1340,  1341,  1342,  1343,  1344,  1345,
    1346,  1347,  1348,  1349,  1350,  1351,  1352,  1353,  1354,  1355,
    1356,  1357,  1358,  1359,  1360,  1361,  1362,  1363,  1364,  1365,
    1366,  1367,  1368,  1369,  1370,  1371,  1372,  1373,  1374,  1375,
    1376,  1377,  1378,  1379,  1380,  1381,  1382,  1383,  1384,  1385,
    1386,  1387,  1388,  1389,  1390,  1391,  1392,  1393,  1394,  1395,
    1397,  1398,  1399,  1400,  1401,  1402,  1404,  1405,  1406,  1407,
    1408,  1409,  1410,  1411,  1412,  1413,  1414,  1415,  1416,  1417,
    1418,  1419,  1420,  1422,  1423,  1424,  1425,  1426,  1427,  1428,
    1429,  1430,  1431,  1432,  1433,  1434,  1435,  1436,  1437,  1439,
    1440,  1441,  1442,  1443,  1444,  1445,  1446,  1447,  1448,  1449,
    1450,  1451,  1452,  1453,  1454,  1455,  1456,  1457,  1458,  1459,
    1460,  1461,  1462,  1463,  1464,  1465,  1466,  1467,  1468,  1470,
    1471,  1472,  1473,  1474,  1475,  1476,  1477,  1478,  1479,  1480,
    1481,  1482,  1483,  1484,  1485,  1486,  1487,  1488,  1489,  1490,
    1491,  1492,  1493,  1494,  1495,  1496,  1497,  1498,  1499,  1500,
    1501,  1502,  1503,  1504,  1505,  1506,  1507,  1508,  1509,  1510,
    1511,  1512,  1513,  1514,  1515,  1516,  1517,  1518,  1519,  1520,
    1521,  1522,  1524,  1525,  1526,  1529,  1530,  1531,  1532,  1533,
    1534,  1535,  1536,  1537,  1538,  1539,  1540,  1542,  1543,  1544,
    1545,  1546,  1547,  1548,  1549,  1550,  1551,  1552,  1553,  1554,
    1556,  1557,  1558,  1559,  1560,  1561,  1562,  1563,  1564,  1565,
    1566,  1567,  1568,  1569,  1570,  1571,  1572,  1573,  1574,  1575,
    1576,  1577,  1578,  1579,  1580,  1581,  1582,  1583,  1584,  1585,
    1586,  1587,  1588,  1589,  1590,  1591,  1592,  1593,  1594,  1595,
    1596,  1597,  1598,  1600,  1601,  1602,  1603,  1605,  1606,  1607,
    1608,  1610,  1611,  1612,  1613,  1614,  1615,  1616,  1617,  1618,
    1619,  1620,  1621,  1625,  1626,  1627,  1628,  1629,  1630,  1631,
    1632,  1633,  1634,  1636,  1637,  1638,  1639,  1640,  1641,  1642,
    1643,  1644,  1645,  1646,  1647,  1648,  1650,  1651,  1652,  1653,
    1654,  1655,  1656,  1657,  1658,  1659,  1660,  1661,  1662,  1663,
    1664,  1665,  1666,  1667,  1668,  1669,  1670,  1671,  1672,  1673,
    1674,  1675,  1676,  1677,  1678,  1679,  1680,  1681,  1682,  1683,
    1684,  1685,  1686,  1687,  1688,  1689,  1690,  1691,  1692,  1693,
    1694,  1695,  1696,  1697,  1698,  1699,  1700,  1701,  1702
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const unsigned short yyr1[] =
{
       0,   719,   720,   721,   722,   723,   724,   724,   725,   725,
     726,   727,   727,   727,   727,   727,   727,   728,   728,   728,
     728,   728,   729,   729,   730,   730,   732,   731,   731,   733,
     733,   734,   734,   734,   734,   734,   734,   734,   734,   734,
     734,   734,   734,   734,   734,   734,   734,   734,   735,   735,
     737,   736,   738,   738,   739,   739,   739,   739,   739,   739,
     739,   739,   739,   740,   741,   742,   741,   741,   741,   741,
     741,   743,   744,   741,   745,   746,   747,   741,   748,   749,
     741,   750,   751,   741,   752,   753,   754,   741,   755,   755,
     756,   756,   756,   757,   757,   758,   758,   759,   760,   760,
     761,   761,   763,   762,   764,   762,   765,   765,   766,   766,
     767,   768,   769,   768,   770,   771,   770,   773,   772,   775,
     774,   776,   776,   776,   776,   776,   776,   777,   778,   778,
     779,   779,   780,   781,   781,   782,   783,   785,   786,   784,
     787,   787,   788,   788,   789,   789,   790,   790,   790,   791,
     791,   793,   792,   794,   792,   795,   792,   796,   792,   797,
     792,   798,   798,   799,   799,   800,   800,   800,   800,   800,
     800,   801,   802,   802,   803,   803,   804,   804,   805,   805,
     807,   808,   806,   806,   809,   809,   811,   810,   812,   812,
     812,   812,   812,   813,   812,   814,   814,   814,   814,   815,
     816,   816,   817,   817,   818,   818,   818,   818,   820,   819,
     821,   819,   822,   819,   823,   823,   824,   824,   825,   826,
     826,   826,   827,   829,   828,   830,   828,   831,   828,   832,
     832,   833,   834,   835,   835,   837,   838,   836,   839,   839,
     839,   839,   839,   839,   839,   839,   839,   839,   839,   839,
     839,   839,   839,   839,   839,   840,   839,   841,   839,   842,
     839,   839,   839,   839,   839,   839,   839,   839,   839,   839,
     843,   843,   844,   845,   846,   847,   847,   848,   850,   849,
     851,   851,   851,   851,   851,   851,   851,   853,   852,   854,
     854,   855,   855,   856,   858,   857,   859,   859,   859,   859,
     859,   859,   859,   860,   861,   861,   863,   862,   864,   864,
     864,   864,   864,   864,   864,   864,   864,   864,   864,   864,
     864,   864,   864,   864,   864,   864,   864,   864,   864,   864,
     864,   865,   867,   866,   868,   866,   870,   869,   871,   869,
     872,   872,   873,   874,   874,   875,   876,   876,   876,   876,
     876,   876,   876,   876,   877,   878,   879,   881,   882,   880,
     883,   883,   884,   885,   885,   885,   886,   886,   888,   887,
     889,   887,   890,   887,   891,   892,   893,   894,   894,   895,
     895,   896,   896,   896,   896,   896,   896,   896,   896,   896,
     897,   897,   897,   897,   897,   897,   897,   897,   898,   898,
     898,   898,   898,   898,   898,   898,   898,   898,   899,   899,
     899,   899,   899,   899,   899,   899,   899,   899,   899,   900,
     900,   901,   901,   902,   902,   903,   903,   904,   904,   905,
     906,   906,   907,   907,   907,   907,   907,   907,   908,   908,
     909,   909,   909,   909,   910,   910,   911,   912,   912,   912,
     913,   912,   914,   914,   915,   915,   916,   916,   916,   916,
     917,   917,   918,   918,   918,   918,   918,   918,   918,   918,
     919,   920,   921,   921,   921,   921,   921,   921,   922,   922,
     922,   922,   922,   922,   922,   923,   925,   926,   924,   927,
     928,   924,   930,   931,   929,   932,   933,   929,   934,   935,
     929,   936,   937,   929,   929,   929,   929,   929,   929,   929,
     938,   938,   939,   940,   940,   940,   940,   940,   940,   940,
     940,   940,   941,   941,   942,   942,   942,   942,   943,   943,
     943,   944,   944,   945,   945,   945,   946,   946,   946,   946,
     946,   946,   946,   946,   946,   946,   947,   947,   948,   948,
     949,   949,   951,   952,   953,   950,   954,   954,   956,   957,
     955,   958,   958,   959,   959,   960,   960,   962,   961,   963,
     961,   964,   964,   965,   965,   967,   966,   968,   966,   969,
     970,   970,   970,   971,   971,   972,   972,   973,   973,   974,
     974,   976,   975,   977,   975,   978,   975,   979,   975,   980,
     975,   982,   983,   981,   984,   984,   985,   986,   986,   986,
     986,   986,   986,   986,   987,   987,   988,   989,   990,   991,
     991,   991,   991,   991,   991,   991,   991,   992,   992,   993,
     994,   995,   996,   997,   998,   999,   999,  1000,  1001,  1002,
    1002,  1003,  1003,  1004,  1004,  1004,  1004,  1004,  1004,  1005,
    1006,  1006,  1007,  1008,  1008,  1009,  1010,  1010,  1011,  1012,
    1013,  1013,  1013,  1014,  1014,  1014,  1016,  1015,  1017,  1017,
    1018,  1018,  1019,  1019,  1020,  1021,  1021,  1022,  1023,  1023,
    1024,  1025,  1025,  1026,  1027,  1027,  1029,  1030,  1028,  1031,
    1032,  1031,  1033,  1034,  1031,  1035,  1035,  1036,  1038,  1037,
    1037,  1039,  1039,  1040,  1040,  1041,  1042,  1042,  1042,  1043,
    1043,  1044,  1044,  1046,  1045,  1047,  1045,  1048,  1045,  1049,
    1045,  1050,  1045,  1051,  1045,  1052,  1045,  1053,  1045,  1054,
    1045,  1055,  1045,  1056,  1045,  1057,  1057,  1058,  1058,  1059,
    1060,  1061,  1061,  1061,  1063,  1062,  1064,  1064,  1065,  1064,
    1066,  1067,  1067,  1067,  1067,  1068,  1068,  1069,  1070,  1070,
    1070,  1070,  1070,  1070,  1070,  1070,  1070,  1072,  1071,  1071,
    1074,  1073,  1075,  1076,  1077,  1077,  1078,  1078,  1079,  1080,
    1080,  1080,  1080,  1080,  1080,  1080,  1080,  1080,  1080,  1080,
    1080,  1080,  1080,  1080,  1080,  1080,  1080,  1081,  1083,  1084,
    1082,  1085,  1085,  1086,  1087,  1088,  1089,  1089,  1091,  1090,
    1092,  1092,  1093,  1093,  1094,  1094,  1094,  1094,  1094,  1094,
    1095,  1095,  1096,  1096,  1097,  1098,  1098,  1098,  1098,  1098,
    1098,  1098,  1098,  1098,  1098,  1098,  1099,  1100,  1100,  1101,
    1102,  1102,  1104,  1105,  1106,  1107,  1103,  1108,  1110,  1111,
    1109,  1112,  1113,  1113,  1114,  1114,  1115,  1116,  1116,  1117,
    1119,  1118,  1120,  1120,  1120,  1120,  1122,  1123,  1124,  1121,
    1126,  1127,  1125,  1128,  1128,  1130,  1129,  1131,  1129,  1133,
    1132,  1134,  1136,  1135,  1137,  1135,  1138,  1135,  1139,  1139,
    1140,  1140,  1141,  1141,  1142,  1142,  1142,  1143,  1144,  1145,
    1146,  1146,  1146,  1147,  1147,  1148,  1148,  1149,  1150,  1150,
    1150,  1150,  1151,  1151,  1151,  1151,  1151,  1152,  1153,  1153,
    1154,  1155,  1156,  1156,  1157,  1158,  1158,  1158,  1158,  1158,
    1158,  1159,  1160,  1161,  1161,  1162,  1162,  1163,  1164,  1165,
    1165,  1166,  1166,  1167,  1168,  1169,  1169,  1169,  1169,  1169,
    1169,  1170,  1170,  1171,  1172,  1172,  1173,  1173,  1174,  1174,
    1175,  1175,  1176,  1176,  1176,  1176,  1176,  1177,  1177,  1178,
    1178,  1179,  1179,  1180,  1181,  1182,  1182,  1183,  1184,  1184,
    1184,  1185,  1186,  1186,  1187,  1187,  1188,  1189,  1189,  1190,
    1190,  1191,  1192,  1193,  1194,  1194,  1195,  1196,  1196,  1197,
    1197,  1198,  1198,  1199,  1200,  1200,  1201,  1201,  1201,  1201,
    1202,  1202,  1202,  1203,  1204,  1204,  1205,  1205,  1205,  1206,
    1207,  1207,  1208,  1208,  1208,  1208,  1208,  1208,  1208,  1208,
    1208,  1208,  1208,  1208,  1208,  1208,  1208,  1208,  1208,  1208,
    1208,  1208,  1208,  1208,  1209,  1210,  1210,  1211,  1211,  1211,
    1212,  1214,  1213,  1215,  1215,  1216,  1217,  1217,  1218,  1218,
    1219,  1219,  1221,  1220,  1222,  1224,  1223,  1225,  1225,  1226,
    1226,  1227,  1227,  1228,  1228,  1228,  1228,  1229,  1229,  1230,
    1231,  1231,  1232,  1233,  1234,  1235,  1236,  1236,  1237,  1237,
    1239,  1238,  1240,  1238,  1241,  1238,  1242,  1238,  1243,  1238,
    1244,  1238,  1245,  1238,  1246,  1246,  1246,  1246,  1246,  1246,
    1248,  1247,  1249,  1249,  1251,  1250,  1250,  1250,  1250,  1250,
    1252,  1252,  1253,  1253,  1254,  1255,  1255,  1257,  1256,  1258,
    1259,  1260,  1260,  1260,  1261,  1261,  1261,  1261,  1262,  1263,
    1263,  1264,  1264,  1265,  1266,  1266,  1266,  1266,  1266,  1266,
    1266,  1266,  1267,  1267,  1268,  1268,  1269,  1269,  1269,  1269,
    1269,  1269,  1269,  1269,  1269,  1269,  1270,  1270,  1271,  1271,
    1271,  1271,  1272,  1272,  1273,  1273,  1274,  1274,  1274,  1274,
    1274,  1274,  1274,  1274,  1274,  1274,  1274,  1274,  1274,  1274,
    1274,  1274,  1274,  1274,  1274,  1274,  1274,  1274,  1274,  1274,
    1275,  1275,  1275,  1277,  1278,  1279,  1280,  1281,  1282,  1276,
    1283,  1283,  1284,  1285,  1285,  1287,  1288,  1289,  1290,  1291,
    1292,  1286,  1293,  1295,  1296,  1297,  1294,  1298,  1298,  1298,
    1298,  1299,  1299,  1299,  1299,  1299,  1300,  1301,  1301,  1301,
    1301,  1302,  1302,  1304,  1305,  1303,  1306,  1307,  1303,  1308,
    1308,  1309,  1309,  1310,  1310,  1310,  1310,  1310,  1311,  1312,
    1312,  1313,  1313,  1314,  1314,  1315,  1315,  1315,  1315,  1315,
    1316,  1316,  1317,  1317,  1318,  1318,  1318,  1319,  1319,  1320,
    1320,  1321,  1321,  1322,  1322,  1322,  1323,  1323,  1324,  1324,
    1324,  1324,  1324,  1324,  1324,  1325,  1325,  1326,  1326,  1327,
    1327,  1328,  1328,  1329,  1329,  1330,  1331,  1331,  1332,  1332,
    1333,  1334,  1334,  1335,  1336,  1336,  1337,  1337,  1338,  1338,
    1339,  1339,  1340,  1340,  1341,  1342,  1342,  1342,  1342,  1342,
    1342,  1342,  1342,  1342,  1342,  1342,  1343,  1343,  1344,  1344,
    1345,  1346,  1348,  1347,  1350,  1349,  1349,  1351,  1351,  1352,
    1352,  1353,  1353,  1354,  1354,  1356,  1355,  1357,  1358,  1358,
    1359,  1360,  1359,  1361,  1362,  1361,  1363,  1363,  1363,  1363,
    1363,  1363,  1363,  1363,  1364,  1365,  1366,  1367,  1367,  1368,
    1369,  1369,  1370,  1370,  1370,  1371,  1372,  1373,  1373,  1374,
    1375,  1375,  1375,  1377,  1376,  1378,  1378,  1378,  1378,  1378,
    1378,  1378,  1378,  1378,  1378,  1378,  1378,  1379,  1380,  1380,
    1381,  1381,  1382,  1382,  1383,  1383,  1383,  1383,  1384,  1384,
    1385,  1385,  1386,  1386,  1387,  1387,  1388,  1389,  1389,  1390,
    1390,  1391,  1391,  1392,  1393,  1394,  1395,  1396,  1396,  1397,
    1397,  1398,  1398,  1398,  1399,  1399,  1400,  1400,  1400,  1401,
    1401,  1401,  1401,  1402,  1403,  1403,  1404,  1404,  1405,  1405,
    1406,  1407,  1407,  1407,  1407,  1407,  1407,  1407,  1408,  1409,
    1410,  1411,  1411,  1412,  1412,  1413,  1414,  1415,  1415,  1416,
    1417,  1418,  1418,  1419,  1419,  1419,  1420,  1420,  1421,  1421,
    1422,  1423,  1423,  1424,  1424,  1425,  1425,  1426,  1426,  1427,
    1427,  1428,  1428,  1429,  1429,  1430,  1430,  1431,  1431,  1432,
    1433,  1434,  1434,  1434,  1434,  1435,  1435,  1436,  1436,  1437,
    1437,  1438,  1438,  1438,  1438,  1438,  1438,  1438,  1438,  1438,
    1439,  1439,  1439,  1439,  1439,  1439,  1439,  1439,  1439,  1440,
    1440,  1440,  1441,  1441,  1441,  1441,  1442,  1442,  1442,  1443,
    1443,  1444,  1444,  1444,  1444,  1444,  1444,  1444,  1444,  1444,
    1444,  1444,  1444,  1444,  1444,  1444,  1444,  1444,  1444,  1444,
    1444,  1444,  1444,  1444,  1444,  1444,  1445,  1445,  1446,  1446,
    1446,  1446,  1446,  1447,  1448,  1449,  1450,  1450,  1450,  1450,
    1450,  1450,  1450,  1450,  1451,  1451,  1451,  1451,  1451,  1451,
    1451,  1451,  1452,  1453,  1453,  1453,  1454,  1454,  1455,  1455,
    1455,  1456,  1457,  1457,  1457,  1457,  1458,  1459,  1460,  1460,
    1461,  1461,  1462,  1462,  1462,  1462,  1462,  1462,  1462,  1462,
    1463,  1463,  1463,  1463,  1463,  1463,  1463,  1463,  1464,  1464,
    1464,  1464,  1464,  1464,  1464,  1465,  1465,  1465,  1465,  1465,
    1465,  1465,  1465,  1466,  1466,  1466,  1467,  1469,  1468,  1470,
    1468,  1471,  1468,  1472,  1468,  1473,  1473,  1473,  1474,  1474,
    1475,  1475,  1475,  1476,  1476,  1477,  1477,  1478,  1480,  1481,
    1479,  1482,  1483,  1483,  1484,  1485,  1485,  1485,  1485,  1485,
    1486,  1487,  1487,  1488,  1489,  1490,  1490,  1490,  1490,  1491,
    1491,  1492,  1492,  1493,  1494,  1494,  1494,  1495,  1495,  1495,
    1495,  1495,  1496,  1496,  1496,  1496,  1496,  1496,  1496,  1496,
    1496,  1496,  1496,  1496,  1496,  1496,  1496,  1496,  1496,  1496,
    1496,  1496,  1497,  1497,  1498,  1499,  1500,  1500,  1501,  1501,
    1502,  1502,  1503,  1503,  1504,  1504,  1505,  1506,  1506,  1507,
    1507,  1508,  1509,  1509,  1509,  1510,  1510,  1511,  1512,  1513,
    1514,  1515,  1515,  1516,  1516,  1516,  1516,  1516,  1516,  1517,
    1517,  1517,  1519,  1518,  1520,  1520,  1521,  1521,  1521,  1521,
    1521,  1521,  1521,  1521,  1521,  1521,  1521,  1521,  1521,  1521,
    1521,  1521,  1521,  1521,  1521,  1521,  1521,  1521,  1521,  1521,
    1521,  1521,  1521,  1521,  1521,  1521,  1521,  1521,  1521,  1521,
    1521,  1521,  1521,  1521,  1521,  1521,  1521,  1521,  1521,  1521,
    1521,  1521,  1521,  1521,  1521,  1521,  1521,  1521,  1521,  1521,
    1521,  1521,  1521,  1521,  1521,  1521,  1521,  1521,  1521,  1521,
    1521,  1521,  1521,  1521,  1521,  1521,  1521,  1521,  1521,  1521,
    1521,  1521,  1521,  1521,  1521,  1521,  1521,  1521,  1521,  1521,
    1521,  1521,  1521,  1521,  1521,  1521,  1521,  1521,  1521,  1521,
    1521,  1521,  1521,  1521,  1521,  1521,  1521,  1521,  1521,  1521,
    1521,  1521,  1521,  1521,  1521,  1521,  1521,  1521,  1521,  1521,
    1521,  1521,  1521,  1521,  1521,  1521,  1521,  1521,  1521,  1521,
    1521,  1521,  1521,  1521,  1521,  1521,  1521,  1521,  1521,  1521,
    1521,  1521,  1521,  1521,  1521,  1521,  1521,  1521,  1521,  1521,
    1521,  1521,  1521,  1521,  1521,  1521,  1521,  1521,  1521,  1521,
    1521,  1521,  1521,  1521,  1521,  1521,  1521,  1521,  1521,  1521,
    1521,  1521,  1521,  1521,  1521,  1521,  1521,  1521,  1521,  1521,
    1521,  1521,  1521,  1521,  1521,  1521,  1521,  1521,  1521,  1521,
    1521,  1521,  1521,  1521,  1521,  1521,  1521,  1521,  1521,  1521,
    1521,  1521,  1521,  1521,  1521,  1521,  1521,  1521,  1521,  1521,
    1521,  1521,  1521,  1521,  1521,  1521,  1521,  1521,  1521,  1521,
    1521,  1521,  1521,  1521,  1521,  1521,  1521,  1521,  1521,  1521,
    1521,  1521,  1521,  1521,  1521,  1521,  1521,  1521,  1521,  1521,
    1521,  1521,  1521,  1521,  1521,  1521,  1521,  1521,  1521,  1521,
    1521,  1521,  1521,  1521,  1521,  1521,  1521,  1521,  1521,  1521,
    1521,  1521,  1521,  1521,  1521,  1521,  1521,  1521,  1521,  1521,
    1521,  1521,  1521,  1521,  1521,  1521,  1521,  1521,  1521,  1521,
    1521,  1521,  1521,  1521,  1521,  1521,  1521,  1521,  1521,  1521,
    1521,  1521,  1521,  1521,  1521,  1521,  1521,  1521,  1521,  1521,
    1521,  1521,  1521,  1521,  1521,  1521,  1521,  1521,  1521,  1521,
    1521,  1521,  1521,  1521,  1521,  1521,  1521,  1521,  1521,  1521,
    1521,  1521,  1521,  1521,  1521,  1523,  1522,  1525,  1524,  1527,
    1528,  1526,  1529,  1529,  1529,  1530,  1530,  1530,  1530,  1530,
    1530,  1531,  1531,  1532,  1533,  1534,  1534,  1535,  1535,  1536,
    1536,  1537,  1537,  1537,  1538,  1538,  1538,  1538,  1538,  1538,
    1538,  1538,  1538,  1538,  1539,  1539,  1539,  1539,  1539,  1539,
    1539,  1539,  1539,  1539,  1539,  1539,  1539,  1539,  1540,  1541,
    1541,  1543,  1542,  1544,  1544,  1545,  1545,  1546,  1547,  1547,
    1548,  1548,  1548,  1548,  1549,  1549,  1549,  1550,  1550,  1551,
    1553,  1554,  1552,  1555,  1555,  1556,  1556,  1557,  1557,  1557,
    1557,  1557,  1557,  1557,  1558,  1558,  1559,  1559,  1560,  1560,
    1561,  1561,  1562,  1563,  1564,  1565,  1565,  1566,  1567,  1567,
    1568,  1569,  1569,  1571,  1570,  1572,  1572,  1572,  1572,  1572,
    1572,  1572,  1572,  1572,  1572,  1572,  1572,  1572,  1572,  1572,
    1572,  1572,  1572,  1572,  1572,  1572,  1572,  1572,  1572,  1572,
    1572,  1572,  1572,  1572,  1572,  1572,  1572,  1572,  1572,  1572,
    1572,  1572,  1572,  1572,  1572,  1572,  1572,  1572,  1572,  1572,
    1572,  1572,  1572,  1572,  1572,  1572,  1572,  1572,  1572,  1572,
    1572,  1572,  1572,  1572,  1572,  1572,  1572,  1572,  1572,  1572,
    1572,  1572,  1572,  1572,  1572,  1572,  1572,  1572,  1572,  1572,
    1572,  1572,  1572,  1572,  1572,  1572,  1572,  1572,  1572,  1572,
    1572,  1572,  1572,  1572
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
       0,     0,     5,     1,     1,     3,     0,     2,     4,     4,
       4,     4,     2,     0,     4,     1,     1,     1,     2,     1,
       1,     3,     0,     1,     0,     1,     1,     1,     0,     7,
       0,     5,     0,    12,     1,     1,     1,     1,     1,     5,
       3,     1,     1,     0,     4,     0,     5,     0,     7,     1,
       3,     1,     1,     0,     1,     0,     0,     4,     1,     1,
       1,     4,     4,     6,     1,     2,     1,     1,     1,     1,
       4,     6,     1,     4,     6,     0,     3,     0,     3,     0,
       3,     1,     1,     1,     1,     1,     2,     2,     1,     1,
       0,     3,     4,     1,     1,     0,     3,     3,     0,     2,
       1,     1,     1,     1,     1,     1,     2,     0,     2,     0,
       3,     0,     3,     1,     0,     3,     1,     1,     1,     1,
       1,     1,     2,     1,     0,     1,     0,     5,     1,     1,
       1,     4,     4,     6,     1,     1,     1,     1,     4,     6,
       1,     4,     6,     1,     1,     1,     1,     1,     2,     2,
       1,     4,     0,     7,     0,    12,     0,     4,     0,     5,
       1,     3,     2,     1,     3,     1,     0,     2,     2,     1,
       2,     5,     4,     2,     4,     5,     3,     0,     0,    11,
       0,     2,     1,     0,     2,     1,     1,     2,     0,     3,
       0,     3,     0,     3,     2,     2,     2,     4,     5,     1,
       2,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     2,     1,     1,     1,     2,     2,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     2,     1,
       2,     1,     1,     1,     3,     1,     3,     1,     3,     1,
       1,     1,     2,     1,     1,     3,     4,     4,     2,     2,
       1,     1,     1,     1,     1,     3,     1,     2,     2,     1,
       0,     3,     2,     2,     1,     3,     4,     4,     5,     5,
       1,     1,     2,     2,     4,     4,     2,     2,     4,     4,
       1,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     0,     0,     0,     6,     0,
       0,     8,     0,     0,     6,     0,     0,     6,     0,     0,
       6,     0,     0,     6,     5,     5,     5,     7,     4,     6,
       0,     3,     1,     1,     4,     4,     4,     4,     4,     4,
       1,     1,     1,     1,     4,     4,     2,     2,     2,     2,
       2,     1,     1,     2,     1,     1,     1,     2,     4,     6,
       6,     3,     5,     5,     3,     1,     1,     3,     1,     3,
       1,     3,     0,     0,     0,     9,     0,     3,     0,     0,
      10,     0,     1,     0,     1,     1,     2,     0,     3,     0,
       3,     0,     1,     1,     2,     0,     3,     0,     3,     3,
       1,     4,     3,     1,     3,     1,     3,     1,     3,     1,
       2,     0,     3,     0,     3,     0,     4,     0,     4,     0,
       4,     0,     0,    11,     0,     2,     2,     3,     1,     3,
       1,     1,     1,     1,     1,     1,     1,     3,     1,     1,
       4,     6,     4,     3,     6,     3,     6,     1,     1,     1,
       1,     1,     1,     1,     1,     0,     2,     1,     1,     1,
       4,     1,     1,     1,     4,     3,     6,     3,     6,     1,
       1,     2,     2,     1,     2,     2,     1,     3,     1,     2,
       2,     2,     4,     2,     2,     4,     0,     8,     0,     1,
       1,     1,     0,     1,     2,     0,     1,     2,     0,     1,
       2,     0,     1,     3,     0,     2,     0,     0,     8,     0,
       0,     3,     0,     0,     7,     5,     2,     2,     0,     5,
       4,     1,     3,     3,     3,     1,     0,     2,     1,     0,
       1,     1,     2,     0,     4,     0,     4,     0,     3,     0,
       3,     0,     3,     0,     3,     0,     3,     0,     3,     0,
       3,     0,     3,     0,     3,     1,     3,     1,     3,     2,
       4,     1,     1,     1,     0,     4,     5,     6,     0,    10,
       3,     2,     2,     1,     1,     0,     2,     1,     2,     3,
       3,     3,     3,     1,     1,     1,     1,     0,     3,     1,
       0,     3,     2,     2,     1,     3,     1,     3,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     0,     0,
       7,     1,     1,     2,     2,     2,     3,     4,     0,     3,
       0,     1,     1,     2,     1,     1,     1,     1,     1,     1,
       0,     1,     1,     2,     2,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     0,     1,     1,
       1,     1,     0,     0,     0,     0,    13,     1,     0,     0,
       6,     2,     1,     2,     2,     2,     1,     1,     2,     1,
       0,     3,     2,     1,     1,     1,     0,     0,     0,    14,
       0,     0,     7,     1,     2,     0,     3,     0,     4,     0,
       5,     1,     0,     3,     0,     7,     0,     5,     1,     2,
       0,     1,     1,     1,     0,     1,     1,     2,     2,     2,
       1,     1,     1,     1,     3,     1,     1,     2,     0,     2,
       1,     1,     1,     1,     1,     1,     1,     3,     0,     1,
       1,     1,     1,     2,     2,     2,     5,     8,     1,     1,
       1,     4,     4,     1,     1,     1,     1,     2,     2,     3,
       6,     1,     3,     1,     1,     1,     3,     6,     9,     1,
       1,     1,     1,     2,     0,     1,     1,     3,     1,     3,
       1,     3,     1,     3,     1,     1,     1,     1,     3,     1,
       3,     1,     3,     1,     1,     1,     3,     2,     0,     1,
       1,     4,     1,     3,     1,     3,     7,     0,     7,     0,
       6,     3,     1,     3,     1,     2,     5,     0,     7,     0,
       2,     0,     1,     5,     2,     5,     0,     5,     6,     4,
       0,     1,     1,     4,     0,     2,     0,     5,     4,     2,
       1,     3,     2,     2,     2,     2,     2,     2,     1,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     1,     1,
       1,     1,     1,     1,     5,     1,     1,     2,     4,     2,
       1,     0,    11,     0,     2,     5,     0,     1,     0,     2,
       1,     2,     0,     3,     1,     0,     4,     0,     2,     1,
       3,     1,     1,     3,     4,     4,     2,     1,     1,     1,
       0,     1,     7,     2,     2,     2,     2,     2,     1,     2,
       0,     3,     0,     3,     0,     3,     0,     3,     0,     3,
       0,     4,     0,     4,     1,     1,     1,     1,     1,     1,
       0,     4,     0,     1,     0,     4,     1,     2,     2,     2,
       0,     1,     1,     2,     2,     0,     2,     0,     4,     3,
       5,     0,     2,     4,     1,     1,     1,     1,     1,     0,
       1,     1,     3,     2,     5,     2,     5,     5,     5,     5,
       5,     5,     0,     2,     1,     2,     2,     2,     2,     2,
       2,     1,     2,     2,     2,     2,     1,     2,     2,     2,
       2,     1,     1,     1,     0,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     1,     1,     1,     1,     1,     1,
       1,     1,     2,     2,     2,     2,     2,     1,     1,     1,
       0,     3,     2,     0,     0,     0,     0,     0,     0,    15,
       0,     2,     2,     0,     1,     0,     0,     0,     0,     0,
       0,    15,     2,     0,     0,     0,    10,     0,     1,     3,
       3,     2,     4,     3,     3,     3,     1,     2,     2,     2,
       2,     1,     1,     0,     0,     8,     0,     0,     9,     0,
       1,     1,     2,     2,     2,     2,     1,     1,     1,     0,
       1,     1,     2,     2,     2,     8,     2,     2,     4,     2,
       0,     1,     1,     3,     2,     2,     1,     1,     3,     1,
       1,     2,     1,     3,     3,     3,     1,     3,     1,     1,
       1,     1,     1,     1,     1,     2,     4,     1,     3,     1,
       3,     2,     4,     1,     3,     1,     2,     4,     1,     3,
       1,     1,     1,     2,     3,     4,     2,     4,     0,     2,
       2,     4,     1,     3,     1,     1,     1,     2,     1,     1,
       1,     1,     1,     2,     6,     6,     0,     1,     0,     1,
       2,     1,     0,     5,     0,     5,     1,     0,     3,     1,
       3,     1,     3,     1,     1,     0,     4,     1,     2,     1,
       0,     0,     3,     0,     0,     3,     1,     1,     1,     1,
       1,     1,     2,     2,     4,     3,     3,     1,     3,     2,
       1,     1,     0,     1,     1,     1,     1,     0,     1,     3,
       1,     3,     1,     0,     3,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     7,     0,     1,
       1,     1,     1,     3,     1,     1,     1,     2,     0,     3,
       1,     3,     1,     3,     1,     1,     6,     0,     3,     1,
       3,     0,     1,     4,     5,     2,     1,     1,     4,     1,
       3,     4,     4,     4,     1,     3,     1,     1,     1,     2,
       1,     1,     1,     4,     0,     1,     0,     1,     1,     2,
       2,     1,     1,     1,     1,     1,     4,     1,     3,     1,
       1,     1,     2,     1,     1,     2,     2,     1,     3,     2,
       2,     1,     3,     1,     2,     4,     1,     2,     1,     3,
       4,     0,     1,     0,     1,     0,     1,     1,     3,     1,
       3,     1,     2,     1,     3,     2,     2,     0,     2,     1,
       1,     5,     3,     5,     3,     1,     3,     1,     1,     0,
       1,     3,     3,     3,     6,     4,     4,     4,     4,     5,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     0,     1,     1,     1,     1,     1,     1,     1,
       4,     0,     1,     4,     1,     5,     5,     1,     1,     1,
       1,     1,     4,     1,     4,     6,     4,     1,     4,     1,
       7,     1,     1,     1,     4,     6,     0,     2,     4,     1,
       1,     1,     1,     1,     1,     1,     3,     1,     1,     3,
       5,     3,     5,     7,     3,     1,     1,     3,     5,     3,
       5,     7,     1,     0,     3,     5,     1,     2,     2,     4,
       3,     1,     1,     1,     1,     1,     2,     2,     0,     3,
       0,     3,     1,     1,     1,     1,     1,     1,     1,     4,
       1,     1,     1,     1,     1,     1,     1,     4,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     4,     1,     3,     1,     3,     0,     7,     0,
       8,     0,     6,     0,     8,     0,     1,     2,     1,     3,
       1,     3,     5,     1,     1,     1,     1,     1,     0,     0,
       9,     5,     1,     1,     6,     0,     3,     1,     3,     4,
       1,     0,     2,     4,     6,     0,     1,     1,     1,     1,
       3,     1,     2,     1,     1,     2,     2,     1,     1,     1,
       2,     4,     3,     2,     3,     3,     3,     1,     1,     1,
       1,     1,     1,     5,     5,     5,     5,     5,     4,     4,
       3,     4,     1,     3,     1,     5,     7,     5,     0,     2,
       1,     1,     0,     3,     1,     3,     1,     1,     1,     0,
       3,     1,     1,     1,     1,     4,     6,     1,     1,     2,
       3,     1,     1,     1,     1,     1,     1,     1,     1,     5,
       5,     4,     0,     4,     1,     2,     1,     1,     1,     1,
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
       1,     1,     3,     5,     1,     1,     1,     1,     3,     1,
       0,     0,     6,     0,     2,     0,     1,     1,     2,     2,
       1,     1,     4,     3,     1,     2,     5,     2,     2,     5,
       0,     2,     1,     1,     2,     6,     6,     1,     0,     1,
       2,     1,     2,     0,     2,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const unsigned short yydefact[] =
{
     810,     0,  2169,     0,     0,     0,   860,   180,     0,   836,
     839,   178,   183,   814,     0,   808,   811,   812,   815,   818,
     819,   817,   856,   857,   859,   816,   135,   132,     0,   128,
     130,   129,   133,  2197,   697,   637,   306,  1655,  1653,   854,
     176,   186,   855,   179,     1,   820,   813,   858,   127,   131,
     134,     0,     0,   614,     0,     0,   177,   863,   929,   615,
     864,   865,   861,   649,   921,     0,   922,   930,   928,   186,
     181,   199,     0,   184,   200,   235,     0,   841,  1215,     0,
       0,   840,   136,  1203,   848,     0,     0,   832,   834,   831,
     833,   809,   821,   822,   842,   825,   826,   827,   830,   828,
     829,   835,     0,  1654,   923,   862,     0,     0,   937,   935,
     936,   925,   924,   304,   186,  1139,   193,   187,   186,   192,
     232,     0,   696,     0,     0,     0,     0,   176,   558,   870,
     823,     0,   338,   324,   202,   310,   275,   294,   315,   317,
     314,     0,   336,     0,   323,   316,   320,   326,   325,   186,
     327,   307,   330,   308,   309,   934,   933,     0,    22,    23,
      13,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     943,     0,   521,   513,    16,   520,   929,    15,     0,   941,
       0,   305,     0,   185,  1140,   182,     0,   199,   201,   269,
     204,   257,   263,   264,   248,   225,   259,   202,   240,   227,
     275,   294,   246,   249,   244,     0,   223,     0,   255,   247,
     252,   262,   261,   186,   265,   186,   238,   239,   236,   268,
       0,     0,     0,     0,   849,   176,   176,     0,     0,   203,
       0,     0,   328,     0,     0,   329,     0,     0,     0,     0,
       0,     0,     0,   273,     0,   931,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   527,     0,
       0,     0,   650,   440,   442,  1210,     0,     0,     0,  1620,
       0,   434,     0,     0,     0,   433,     0,   450,   523,     0,
       0,     0,     0,     0,   526,     0,   399,   398,   405,   446,
     443,   400,   401,   403,   404,   441,   444,   449,   522,   495,
     492,   501,   498,     0,     0,    17,    18,    19,    20,    21,
       0,    14,   486,     0,     0,   939,     0,   188,   191,   189,
     190,     0,   196,   195,   194,   197,   205,   206,   207,   210,
     270,   186,   270,     0,     0,   186,   266,   267,     0,     0,
     186,     0,   270,     0,     0,   245,   233,  1216,     0,     0,
    1204,  2203,   559,   871,   843,     0,   214,   215,     0,     0,
     287,   289,   284,   285,   281,   283,   280,   282,   279,     0,
     289,   300,   301,   297,   299,   296,   298,   291,     0,     0,
       0,   340,     0,   343,   345,   222,     0,   221,     0,   186,
       0,     0,   548,   619,     0,     0,     0,     0,     0,     0,
       0,     0,   545,   531,   536,     0,   532,   535,   534,   628,
       0,   627,   550,     0,    11,   172,   432,   407,   406,     0,
    1145,     0,     0,   448,  1628,  1626,  1627,  1623,  1625,  1622,
    1624,  1616,     0,     0,     0,   447,     0,     0,     0,     0,
       0,     0,     0,   651,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   165,   166,   167,   168,   169,   170,   528,   529,   530,
     461,     0,     0,   460,   470,     0,     0,   411,     0,     0,
     412,   402,   408,   410,   413,   414,   415,   416,   417,   409,
     439,   438,     0,     0,     0,     0,     0,     0,     0,    12,
      93,     0,   942,     0,   926,   198,     0,     0,   258,     0,
     260,     0,     0,     0,     0,     0,     0,     0,   256,     0,
     186,   234,   237,   954,   695,   866,   954,     0,  2201,  2203,
    1139,  1749,   837,     0,   954,     0,     0,   311,   276,     0,
       0,   286,   303,   277,   302,     0,   295,     0,   318,     0,
     312,     0,   337,     0,   342,   332,     0,     0,   321,   274,
     331,     0,     0,   519,     0,     0,   516,   515,   518,   514,
     525,   510,   510,     0,   533,     0,   537,     0,   294,     0,
     517,   524,   278,     0,  1211,  1695,     0,     0,     0,     0,
       0,   435,     0,     0,   451,     0,     0,     0,     0,   453,
     452,   471,   462,   477,   480,   481,   478,   484,   483,   482,
     472,   473,   474,   475,   476,   418,   463,   467,   485,   479,
     466,   485,   445,   496,   493,   502,   499,   508,     0,   487,
      94,    95,    97,   489,     0,     0,   235,     0,     0,     0,
     241,     0,     0,   250,     0,   242,   224,   208,     0,   253,
     272,   960,     0,   955,   956,   954,     0,   850,  2202,  2200,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  2184,     0,  1331,  1330,     0,
    1332,     0,   394,  1329,  1246,     0,     5,  1328,   395,   392,
       0,   397,   174,   485,  1116,     0,     0,  1338,   124,   391,
     390,     0,     0,   385,   485,     0,  1282,  2177,     0,   396,
     357,     0,     3,     2,     0,   393,  1243,     0,     0,   386,
     383,   379,     0,     0,     0,     0,  1336,  1326,   389,     0,
       0,     0,     0,     0,     0,     0,     0,  1325,     0,     0,
       0,   175,     0,   382,   381,     0,     0,  2181,  2180,     0,
       0,     0,   137,     0,   388,   387,     0,     0,   384,   485,
       0,   485,     0,   552,     0,     0,     0,     0,     0,     0,
     485,   797,  1213,     0,     0,  1127,     0,  2170,     0,   104,
       0,     0,   879,     0,     0,     0,     0,   798,     0,     0,
    1772,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     666,     0,     0,     0,  2205,  2206,  2207,  2208,  2209,  2210,
    2211,  2212,  2213,  2214,  2215,  2216,  2217,  2218,  2219,  2220,
    2221,  2222,  2223,  2224,  2225,  2226,  2227,  2228,  2229,  2230,
    2231,  2232,  2233,  2234,  2235,  2236,  2237,  2238,  2239,  2240,
    2241,  2242,  2243,  2244,  2245,  2246,  2247,  2248,  2249,  2250,
    2251,  2252,  2253,  2254,   908,  2255,  2256,  2257,  2258,  2259,
    2260,  2261,  2262,  2263,  2264,  2265,  2266,  2267,  2268,  2269,
    2270,  2271,  1107,  1109,  1104,  1106,  1105,  1108,  2272,  2273,
    1236,  2274,  1242,  1241,  2275,  2276,  2277,  2278,  2279,  2280,
    2281,  2282,  2283,  2284,  1393,  2285,  2286,  2287,  2288,  2289,
    2290,  2291,  2292,  2293,  2204,   838,   563,     0,   875,     0,
     873,     0,   339,   216,   217,     0,   288,   293,     0,     0,
       0,     0,   341,   344,     0,   220,     0,     0,   549,     0,
     623,     0,   625,   505,     0,   506,     0,   547,     0,   544,
     541,   512,   504,   551,     0,   171,  1697,  1698,  1696,     0,
     437,  1210,     0,  1621,  1210,   436,  1210,  1210,  1210,  1210,
    1210,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    93,   940,     0,   211,
     271,   226,     0,   186,     0,     0,     0,     0,     0,  1217,
       0,     0,  1205,   376,   374,   375,  1046,  1045,  1049,     0,
    1595,  1596,     0,     0,  1266,   638,   639,  1267,  1587,  1588,
    1269,   824,  1079,  1084,  2179,   631,   123,     0,     0,  2161,
    2160,  1014,  2157,  2159,  2192,     0,     0,  1281,     7,     0,
       6,     0,  2185,  1080,     0,  1173,  1172,  1119,  1171,  1118,
     429,  1339,  1327,     0,  1237,   851,   419,  1751,  1333,   125,
       0,  1083,   122,     0,   804,    24,   633,   380,     0,   803,
    1076,   805,     0,  1337,   901,   900,   903,   899,   902,  2194,
       0,   897,     0,   632,   987,   898,  2188,     0,  2178,   121,
    1239,   984,   698,   982,     0,   629,  2173,   742,   741,   743,
     739,     0,     0,  1238,   997,   634,  1392,  1387,  1390,     0,
       0,     0,  1050,  1047,     0,  1041,  1043,  1042,  1040,  1039,
       0,     0,     0,  1038,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1028,  1019,  1020,
     969,     0,   967,  1064,   427,    24,     0,  2175,   126,   630,
       0,  1214,  1212,  1138,     0,  1740,  1741,  1139,  1120,  1340,
       0,     0,     0,     0,     0,     0,     0,     0,    63,     0,
     929,     0,    69,     0,   102,   606,     0,   653,   652,     0,
    1110,  1004,  1114,     0,     0,  1065,  1231,     0,     0,  1117,
     658,   655,   656,     0,   660,   661,     0,   663,   664,     0,
     659,   964,   966,     0,     0,   965,   744,   962,   709,   958,
    1240,   920,     0,     0,     0,     0,   670,   671,     0,     0,
     918,   915,   916,   912,   913,   914,   907,   911,   910,     0,
       0,     0,     0,     0,     0,   567,   569,   561,   564,   565,
     877,  2203,   872,   874,   844,     0,   290,   292,   319,   313,
       0,     0,   322,   620,   622,     0,     0,   510,   538,     0,
     287,     0,     0,  1721,  1612,  1614,  1722,  1618,  1719,     0,
       0,  1718,     0,     0,  1720,     0,     0,     0,     0,     0,
    2161,  1613,  1717,  1615,  1709,     0,  1699,  1701,  1704,  1707,
    2167,  1708,  1148,  1629,  1147,  1146,  1149,  1151,  1150,  1144,
     464,   465,   469,   454,     0,   457,   468,     0,   456,   497,
     494,   503,   500,   509,   488,    96,   490,   927,     0,   231,
       0,   229,   251,   243,   235,   254,   961,   176,   957,   867,
     176,     0,     0,     0,  1311,  1312,     0,     0,     0,  1283,
    1286,  1288,  1289,  1290,  1294,  1293,  1291,  1292,     0,     0,
       0,  1284,  1285,     0,     0,     0,     0,     0,  2158,   938,
       0,  1016,     0,     0,     0,     0,     0,  1081,     0,    24,
    1168,  1170,  1169,     0,   422,   423,   420,   421,   974,     0,
       0,   362,    25,   356,     0,     0,  1073,     0,     0,     0,
       0,     0,     0,     0,   991,  1750,     0,     0,     0,     0,
       0,     0,  2175,     0,     0,   138,     0,     0,  1001,   993,
     994,   999,  1388,  1389,     0,   917,   425,  2151,   346,     0,
     553,   611,   610,   608,   613,  1022,   612,  1027,  1023,  1026,
     796,   788,   782,   794,   795,   780,   781,   789,   784,   790,
     783,   793,   787,   791,   786,   792,   779,   785,   772,   778,
    1024,  1025,     0,  1032,  1036,  1029,  1030,  1034,  1035,  1033,
    1031,  1037,     0,     0,     0,   806,     0,     0,     0,     0,
       0,   754,   753,   750,  2176,  2183,    24,  1134,  1135,  1136,
    1137,  1131,  1129,  1227,  1139,  1121,  1122,  1125,  1141,  2171,
       0,     0,     0,     0,    98,     0,    99,     0,     0,     0,
      74,     0,     0,     0,   111,   106,     0,   654,   906,     0,
     905,     0,   485,  1112,     0,   949,   950,   973,   944,   945,
     799,   971,  1067,  1233,     0,  1235,  1234,  1828,  1945,  1941,
    1947,  1979,  1959,  1950,  1909,  1871,  1998,  1965,  1973,  1862,
    1968,  1829,  1776,  1960,  1867,  1918,  2052,  1897,  1885,  1898,
    1996,  1999,  1967,  1921,  2002,  1788,  2059,  1995,  2023,  1799,
    2095,  1886,  2068,  1781,  2028,  1797,  1857,  1904,  1924,  2018,
    2046,  2051,  1780,  1976,  2004,  1792,  1794,  1817,  1835,  1855,
    1865,  1875,  1928,  1931,  1989,  2000,  2006,  2007,  2024,  2069,
    2080,  1779,  1810,  1834,  1833,  1841,  1843,  1851,  1861,  1882,
    1900,  1903,  1929,  1937,  1993,  2003,  2013,  2019,  2020,  2022,
    2047,  2077,  2088,  1800,  1803,  1814,  1820,  1822,  1827,  1830,
    1832,  1838,  1846,  1848,  1849,  1850,  1860,  1870,  1877,  1893,
    1894,  1905,  1923,  1927,  1940,  1956,  1987,  1997,  2001,  2008,
    2016,  2025,  2035,  2039,  2056,  2062,  2066,  2074,  2079,  2082,
    1823,  1942,  1984,  1808,  1809,  1826,  1831,  1837,  1839,  1853,
    1854,  1864,  1873,  1878,  1880,  1881,  1887,  1895,  1912,  1913,
    1926,  1954,  1958,  1961,  1966,  1970,  1978,  1985,  1986,  1991,
    2009,  2010,  2015,  2021,  2026,  2032,  2033,  2034,  2036,  2038,
    2040,  2049,  2071,  2072,  2073,  2078,  2094,  1783,  1936,  1944,
    1946,  2042,  1785,  1789,  1793,  1798,  1804,  1805,  1818,  1819,
    1821,  1824,  1836,  1852,  1872,  1874,  1884,  1888,  1890,  1891,
    1899,  1908,  1910,  1911,  1922,  1935,  1953,  1971,  1972,  1988,
    1990,  1994,  2005,  2027,  2037,  2045,  2067,  2070,  2084,  2085,
    2086,  1816,  1786,  1806,  1807,  1813,  1883,  1815,  1840,  1842,
    1856,  1933,  2057,  1866,  1868,  1876,  1879,  1901,  1902,  1907,
    1914,  1915,  1916,  2097,  1948,  1949,  1952,  1957,  1962,  1969,
    1974,  1975,  1977,  1983,  2012,  2014,  2030,  2041,  2043,  2044,
    2048,  2053,  2054,  2058,  2060,  2061,  2076,  2081,  2083,  2087,
    2089,  2093,  1943,  2092,  1782,  1784,  1787,  1791,  1801,  1825,
    1844,  1845,  1847,  1858,  1889,  1892,  1932,  1938,  1951,  1955,
    2090,  2091,  1992,  2011,  2017,  2029,  2031,  2050,  2055,  2065,
    2075,  1796,  1790,  1795,  1812,  1863,  1906,  1919,  1920,  1980,
    1982,  2064,  1939,  1896,  1963,  1811,  1859,  1869,  1934,  1917,
    1964,  1802,  1925,  1930,  2063,  1981,     0,  1774,  1777,  1778,
     686,     0,     0,     0,   675,   709,   709,   706,     0,     0,
     710,     0,    26,   674,   677,     0,   684,   680,   919,   909,
    1747,  1748,  1738,  1738,  1357,     0,     0,  1656,     0,     0,
    1341,     0,     0,  1342,  1385,     0,     0,  1386,     0,  1695,
       0,  1355,     0,  1404,  1403,  1402,  1400,  1401,  1399,  1397,
    1394,  1474,  1473,  1395,  1396,  1405,  1677,  1398,  1754,  1753,
    1752,  1406,  2203,  2203,   580,   571,   562,     0,   566,  2203,
     876,   176,     0,   333,   219,     0,     0,  1636,  1634,  1635,
    1631,  1633,  1630,  1632,   511,   507,     0,   543,   542,   173,
    1706,  1705,  1644,  1642,  1643,  1639,  1641,  1638,  1640,  1617,
       0,  1695,     0,     0,  1542,     0,  1542,  1542,  1542,  1542,
    1710,     0,     0,     0,  1491,  1685,  1702,     0,     0,     0,
       0,  1763,  1764,  1765,  1766,  1767,  1768,  1713,     0,     0,
     459,   458,     0,     0,   186,   228,   209,  1218,   176,  1206,
       0,     0,     0,     0,     0,     0,  1448,  1447,  1446,  1318,
       0,  1324,  1320,  1322,  1313,     0,  1551,  1310,  1306,  1280,
    1279,     0,  1305,  1301,     0,  1297,  1295,     0,  1594,     0,
    1597,  1599,   642,     0,   641,  1586,     0,  1589,  1591,     0,
    1015,     0,     0,  1013,  2164,  2166,  2165,  2162,  2193,  2190,
       0,     0,  1247,   485,   354,  1268,     0,     0,  1244,  1006,
    1077,  1078,  1075,  1074,     0,   904,     0,     0,   616,     0,
       0,     0,   985,   983,   700,   701,     0,   705,     0,     0,
    2174,  2182,   740,     0,   142,     0,   995,  1002,     0,     0,
    1010,  1391,     0,     0,   349,     0,     0,     0,     0,    24,
    1048,   556,     0,     0,     0,   773,   774,  1021,   970,   968,
     807,   428,     0,  1056,   751,   752,   377,     0,  1139,  1228,
    1143,  1128,  1123,     0,     0,  1124,  2203,     0,     0,     0,
       0,     0,     0,     0,    64,    93,     0,     0,   117,   112,
       0,   107,     0,   114,   108,   890,   882,   888,     0,  1111,
       0,  1113,  1115,     0,     0,   953,     0,     0,     0,     0,
    1066,  1232,     0,     0,  1773,  1775,  2203,   657,   662,   665,
     678,   676,   635,     0,   729,   727,   733,   731,     0,     0,
     725,   769,   723,   708,   719,   717,   767,   745,     0,   711,
     721,   963,   959,     0,     0,     0,     0,   683,     0,     0,
       0,     0,     0,     0,     0,  1602,     0,  1469,  1470,  1759,
    1427,  1491,     0,     0,  1757,     0,     0,  1678,  2099,     0,
    1410,  1416,  1415,  1414,  1418,     0,  1411,  1412,   568,   570,
       0,     0,   583,   575,   577,     0,   572,   573,     0,     0,
     591,   593,     0,     0,   589,   878,   845,   218,     0,   624,
     626,   621,     0,   540,   539,     0,     0,  1730,     0,     0,
       0,  1544,  1545,  1543,     0,  1732,     0,     0,     0,     0,
       0,     0,     0,  1700,     0,  1480,  1481,  1483,  1486,     0,
    1492,  1493,     0,     0,  1542,  1687,  1681,  1715,  1716,  1714,
    1712,  2168,   455,   491,     0,   230,  1174,   868,  1152,     0,
       0,     0,     0,  1318,     0,     0,     0,  1314,     0,     0,
       0,  1308,  1582,  1580,  1549,  1561,  1563,  1567,  1569,  1560,
    1554,  1559,  1573,  1552,  1581,  1557,  1572,  1558,  1579,  1571,
    1454,  1546,  1547,  1548,     0,  1303,  1299,     0,     0,  1287,
       0,     0,   640,     0,     0,     0,     0,     0,     0,     0,
    2189,     0,     4,     8,    10,     0,   485,   424,     0,     0,
       0,  1003,     0,     0,     0,     0,     0,     0,     0,     0,
     699,     0,     0,   159,   157,     0,     0,   139,     0,   149,
     155,   709,   144,   146,     0,  1000,  1011,  1012,     0,   426,
       0,  2152,  2153,   348,   353,   618,   347,     0,   350,   355,
     485,  1363,   609,   607,     0,   776,  1055,  1057,     0,   378,
    1132,  1130,     0,  1142,  1126,     0,     0,  1223,     0,     0,
       0,   100,     0,     0,    75,    81,    71,  2203,  2203,   110,
     105,   119,   115,     0,   109,   770,   891,   635,  2203,   881,
     880,   889,  1005,     0,     0,   951,   952,   946,   972,   485,
    1072,  1068,  1069,  1071,  2096,  2098,   687,   681,   679,     0,
      24,     0,  2203,  2203,  2203,  2203,   735,   713,   737,   715,
    2203,  2203,  2203,  2203,     0,   707,   712,  2203,   635,   765,
     763,   766,   764,     0,     0,    46,    44,    41,    35,    39,
      43,    38,    31,    40,     0,    34,    37,    32,    42,    33,
      45,    36,     0,    29,    47,   757,     0,   685,  1739,     0,
    1737,  1695,  1735,  1682,  1683,  1675,  1661,  1676,     0,     0,
       0,  1044,  1468,  1471,     0,     0,     0,  1375,  1347,  1762,
    1761,  1760,     0,     0,     0,     0,  1370,     0,  1369,     0,
    1371,  1366,  1367,  1368,  1359,  1360,     0,     0,  1417,     0,
       0,   582,   587,     0,     0,  2203,  2203,   560,   574,   597,
     585,   599,  2203,  2203,   595,   579,   590,   837,   334,     0,
    1651,  1649,  1650,  1646,  1648,  1645,  1647,  1619,     0,     0,
       0,  1731,     0,     0,     0,  1729,     0,     0,     0,     0,
    1711,  1728,     0,  1484,     0,  1611,  1487,     0,     0,     0,
       0,  1479,  1497,  1499,  1501,  1541,  1540,  1539,  1503,  1519,
       0,  1494,  1495,  1690,  1270,     0,     0,     0,   212,     0,
    1200,  1219,   837,     0,  1207,  1200,     0,  1603,     0,  1436,
       0,  1439,  1606,     0,  1444,     0,     0,  1315,  1316,     0,
       0,  1319,  1321,  1323,     0,  1307,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1452,  1451,  1450,     0,
    1455,  1456,     0,  1302,     0,  1296,  1298,  1598,     0,  1600,
    1590,     0,  1592,  2163,     0,     0,     0,  2191,  1276,     0,
    1272,     0,     0,  1277,   852,     0,     0,     0,     0,     0,
    1334,  2196,  2195,   617,     0,     0,    48,     0,   702,   704,
     703,  1335,   709,  2203,  2203,   151,   643,   161,   153,   163,
     143,   150,  2203,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1364,   554,     0,   775,  1053,     0,  1229,  1230,
    2172,     0,    93,     0,    65,     0,     0,     0,    78,     0,
      93,    93,   118,   113,  2203,  2203,   103,     0,   892,   886,
     894,   893,   883,   604,   932,     0,     0,     0,   689,   668,
     682,   636,   746,     0,   730,   728,   734,   732,     0,  2203,
       0,  2203,   726,   724,   720,   718,   768,   722,    24,   758,
       0,     0,     0,    27,     0,  1742,     0,  1662,     0,     0,
    1674,  1657,  1673,  1472,     0,  1429,     0,  1374,     0,     0,
    1758,     0,  1755,  1679,     0,     0,     0,     0,     0,     0,
    2100,  1373,  1372,  1361,  1356,  1358,     0,  1420,     0,  1413,
       0,   584,   581,   576,   578,     0,  2203,  2203,   592,   594,
    2203,  2203,     0,  1637,     0,     0,     0,     0,     0,  1727,
    1733,  1723,  1724,  1725,  1726,  1488,     0,  1482,  1502,     0,
    1506,     0,  1519,  1505,     0,     0,  1520,  1535,  1532,  1533,
    1530,  1538,  1537,  1531,  1534,     0,     0,     0,     0,     0,
    1536,     0,     0,     0,  1476,  1477,  1703,     0,  1496,  1490,
    1271,  1688,  1380,  1376,  1377,  1382,  1381,  1686,  1270,     0,
    1198,  1199,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1197,     0,     0,  1185,  1186,  1187,  1184,
    1189,  1190,  1191,  1188,  1175,  1166,     0,     0,  1222,     0,
    2203,     0,  1161,     0,     0,     0,     0,     0,     0,     0,
    1153,  1154,     0,  1085,  1607,     0,  1608,     0,     0,     0,
       0,  1443,  1442,  1318,  1441,  1433,  1309,  1583,     0,     0,
       0,     0,     0,     0,  1584,  1576,     0,     0,     0,  1576,
    1612,  1449,  1462,  1467,     0,  1464,  1461,  1463,     0,  1465,
    1453,  1457,  1458,  1318,  1304,  1300,     0,     0,  1018,     0,
     981,  1275,  1274,     0,  1259,     9,     0,  1249,   853,  1082,
     360,  1249,     0,     0,  2187,     0,     0,   986,    49,     0,
     755,   160,   158,     0,  2203,     0,     0,     0,  2203,   156,
     145,     0,   148,   147,     0,   992,   996,  2156,  2155,  2154,
     352,     0,   557,     0,  2203,   777,     0,   635,  1133,     0,
    1224,    70,     0,     0,   101,    68,    93,    76,    82,     0,
     120,   116,   771,  2203,   896,   635,   895,     0,   601,     0,
     801,   802,   800,  1070,   692,   690,     0,   672,   669,     0,
     736,   714,   738,   716,   747,   761,   762,   759,   760,    30,
      28,     0,  1736,  1691,  1663,  1659,  1658,     0,  1428,  1695,
    1431,     0,  1349,  1344,  1343,  1346,     0,  1691,     0,     0,
    2133,  2131,     0,     0,  2119,  2130,     0,     0,  2132,     0,
       0,     0,     0,     0,  2161,  2129,  2125,     0,  2117,  2120,
    2121,  2128,  2124,  2148,     0,  2110,  2109,  2113,  2115,     0,
    2108,     0,  2111,  2102,     0,     0,  1419,     0,   588,   586,
     598,   600,   596,     0,     0,     0,  1694,     0,  1771,     0,
       0,  1485,  1504,  1498,  1500,  1507,  1509,  1507,     0,  1514,
    1507,     0,  1512,  1507,     0,  1522,  1521,     0,  1523,     0,
    1475,     0,  1384,  1383,  1379,  1689,   235,  1192,  1193,  1194,
    1196,  1179,  1177,  1176,  1180,  1181,  1178,  1195,  1182,  1183,
    1167,   978,  1202,   975,     0,     0,  1220,     0,  1165,  1164,
    1159,  1157,  1156,  1160,  1158,  1162,  1163,  1155,  1208,     0,
    1434,  1440,  1610,  1603,  1445,  1317,  1550,  1562,     0,  1564,
    1566,     0,  1568,     0,     0,     0,  1574,  1553,  1578,     0,
    1435,  1437,     0,  1459,  1460,  1601,  1593,  1017,  1273,     0,
       0,  1265,  1260,  1261,  1278,     0,  1256,  1257,     0,     0,
    1270,  1250,  1251,     0,    24,  1245,     0,     0,  1009,     0,
      50,   989,     0,    24,   162,   152,     0,   645,   647,   164,
     154,   755,     0,   351,  1365,     0,  1054,    24,     0,     0,
      66,     0,    79,    88,     0,    72,   887,   884,   605,  2203,
     947,     0,  2203,   688,   667,   673,   635,  1746,     0,  1744,
       0,     0,  1664,  1660,  1430,     0,  1432,  1426,     0,  1348,
       0,  1756,     0,  2123,  2122,     0,     0,  1542,     0,  1542,
    1542,  1542,  1542,  2126,     0,     0,  2106,     0,     0,     0,
       0,  2135,  2107,     0,     0,     0,     0,     0,     0,  2101,
    1362,  1421,  1424,  1408,  1422,  1425,   847,   846,   335,  1652,
    1769,  1770,  1489,     0,  1526,  1528,     0,  1515,  1518,  1517,
    1525,     0,  1527,  1507,     0,  1478,  1378,   213,   980,   979,
     977,     0,  1201,  1086,  1090,  1092,     0,  1096,     0,  1094,
    1098,  1087,  1088,     0,   869,     0,     0,  1604,  1609,     0,
       0,  1585,  1577,  1555,     0,  1556,     0,     0,  1263,  1258,
    1264,  1262,  1255,  1254,  1253,  1248,  1252,   361,   358,     0,
    1007,     0,     0,     0,   988,   756,   140,   644,    24,   998,
     555,  1051,    67,  1225,    84,     0,     0,    77,    88,    88,
    2203,   602,     0,     0,   691,   748,     0,  1743,  1692,  1685,
       0,  1350,     0,  1685,  2146,     0,     0,  2149,     0,     0,
       0,     0,     0,     0,     0,  2118,  2137,  2138,  2136,  2134,
    2116,     0,  2112,  2114,  2103,  2104,     0,  1409,  1407,  1508,
    1734,  1510,     0,  1513,  1511,  1529,     0,   976,  2203,  2203,
    1100,  2203,  1102,  2203,  2203,  1089,  1221,  1209,     0,  1565,
       0,  1575,     0,  1466,   363,  1008,  2186,     0,     0,     0,
       0,     0,     0,    55,     0,    54,     0,    52,     0,     0,
     141,  1058,    88,    93,    88,    89,    83,    73,   885,     0,
       0,   693,    24,  1745,  1684,  1693,  1354,     0,  1351,  1353,
    1665,  2147,     0,     0,  2145,     0,     0,     0,     0,  2127,
    2144,     0,  1423,  1516,  1524,  1091,  1093,  2203,  1097,  2203,
    1095,  1099,  1605,  1570,  1438,   365,   370,   368,   359,     0,
     366,   372,    57,    62,    59,    61,    58,    60,    56,     0,
      51,     0,   646,   648,  1062,  1052,     0,  1060,  1226,    85,
      80,   603,   948,  2203,   749,     0,  1345,     0,  1666,  1680,
    2143,  2150,  2139,  2140,  2141,  2142,     0,  1101,  1103,  2203,
    2203,   364,   367,  2203,    53,     0,  2203,  1059,  1061,     0,
     689,  1352,     0,  1670,  1667,  1668,  2105,   371,   369,   373,
       0,  1063,    86,   694,     0,     0,     0,   990,    90,     0,
    1671,  1669,    92,     0,    87,     0,    91,  1672
};

/* YYDEFGOTO[NTERM-NUM]. */
static const short yydefgoto[] =
{
      -1,   814,   815,   816,   817,  1039,  2342,  2343,   180,   320,
     181,  1381,  1382,  2184,  2492,  3485,  2987,  2988,  3392,  3486,
    3487,   818,  1168,  3022,  2731,  3409,  2125,  2729,  3263,  3026,
    3405,  2730,  3264,  3493,  3589,  3608,  3407,  3614,   639,   640,
     641,  1495,  2410,   819,  1506,  1173,  1504,  2133,  2420,  2130,
    2418,  2423,  2735,  1505,  2417,  2134,  2734,   820,     9,    28,
      29,    30,    31,    32,    88,   823,  1102,  2074,  1405,  2367,
    2371,  2372,  2368,  2369,  2994,  2998,  2702,  2694,  2693,  2695,
    2698,   490,   268,   593,   824,    55,    56,    11,    41,   115,
      70,    71,    72,    73,   196,   334,    74,    75,   240,   339,
     226,   996,   516,  2879,   368,   925,  2238,   396,   397,   227,
     350,   341,   345,  1320,  1321,   119,   532,   120,   121,   356,
     228,   352,   340,   342,   518,   229,   254,   570,   242,   245,
     243,   244,   378,   548,   549,   551,   556,   928,   246,   247,
     387,   553,   192,    12,    51,   151,   152,   153,   934,  2822,
     154,   250,   238,   390,   391,   392,   393,  2089,   825,   826,
     827,   828,  1060,  3474,  3234,  1383,  3538,  3539,  3540,  3580,
    3579,  3583,   829,   830,   831,   832,   833,   834,   835,  1050,
     491,  1055,  1375,  1376,  1415,  1143,  1416,   295,   296,   297,
     298,   299,   300,   301,   448,   492,  1304,   493,   494,   495,
     496,   497,   498,   499,   974,   182,   510,   984,   986,  1982,
     183,   504,   980,   503,   979,   506,   982,   505,   981,   943,
     952,   302,   303,   185,   304,   415,   416,   417,   418,   401,
     420,   836,  1114,  2091,  3014,  2391,    89,   235,   542,  1915,
    1237,  1238,  1239,  1912,  1913,  2225,  2226,  2227,  2545,  2546,
    1916,  1917,  2221,  2549,  2541,  2233,  2234,  2552,  2553,  2820,
    2816,  2817,   837,  3269,  3499,  3038,   838,  1425,    57,  2059,
    2060,  2386,   402,   422,  1094,  1148,  1024,  1082,  1065,  1104,
    2450,   186,  1025,  1015,  2023,  2697,    59,   305,   839,  1178,
     840,  1191,  1192,   841,   842,   843,   844,  1199,  3047,  1221,
    3274,  1222,  2160,  1223,  2447,  1224,  2749,  1225,  2187,   845,
    2156,  2748,  3046,  3272,  3271,  3563,    90,    13,   846,  1399,
    2064,  2065,  2066,  2177,  1861,  2178,  2179,  2759,  2761,  2463,
    2462,  2467,  2461,  2460,  2453,  2452,  2455,  2454,  2457,  2459,
     847,   848,  1100,   849,  1857,  1206,  3502,   850,  1473,  3243,
    2494,  2495,  2180,  2464,  2426,  2737,  1137,  1453,  2095,  2394,
    2096,  1449,   851,   852,  1184,  2148,  3042,   853,   854,   855,
     856,    14,    45,    15,    16,    17,    91,    92,   857,    93,
      18,   916,    19,    94,    95,   131,   544,  1921,  2557,  3327,
      96,   127,   361,   858,  2675,    20,    21,    22,    23,    24,
      40,    62,    97,   665,  1988,  2612,    98,   236,   543,   919,
     920,  1241,  1919,   859,  1179,  2430,  2137,  2428,  3410,  3033,
    2138,  2427,  2740,  3035,   860,   861,   862,  1076,  1077,  1509,
     863,  1226,  1227,   864,  1869,  1228,   306,    64,    65,    66,
      67,  1516,   157,   111,    68,  1030,   108,   188,   189,  1517,
    1518,  2437,  1519,   662,   663,  1208,   664,  1209,  1141,  1142,
    1520,  1521,  1379,  3172,  3173,  3350,  2036,  1092,  1093,   865,
    1394,  3394,   866,  3006,   867,  1409,  1410,  1411,  2080,  2078,
     868,   869,  2351,  2378,   870,  1361,  2033,   871,  1138,  1139,
     872,  1008,   873,  2505,   874,  3491,  3017,   875,  2398,  3555,
    3556,  3557,  3586,  1145,   876,  1522,  2150,  2441,  2442,   877,
    2052,  1023,  1368,   878,   879,   880,  2614,  3176,  3361,  3362,
    3458,  3459,  3463,  3461,  3464,  3527,  3529,   881,   882,  1511,
    2142,   883,  1513,  1484,  1485,  1486,  2115,   884,  1158,   885,
     886,  2108,  1481,  1154,   195,  1487,  1488,   307,  2615,  2920,
    2921,  2904,  1047,  1048,  2610,  2905,  2908,    99,   126,   536,
    1330,  2288,  2922,  3365,   430,   887,  1152,   100,   123,   533,
    1327,  2286,  2909,  3363,  2611,  1172,  2722,  3259,  3492,  2110,
     888,   889,   890,   891,   892,  1063,  2349,  1041,  2345,  3230,
    3231,  3232,  3378,  3221,  3222,  3223,   893,  2871,  2669,  2670,
    2672,  2007,   894,   895,  1339,  1340,  1341,  2016,  2327,  1342,
    2324,  2013,  1343,  2300,  2008,  1344,  1345,  1346,  2292,  2297,
    1347,  2002,  2003,   896,  1072,  1052,   897,  1893,  1894,  2202,
    3074,  3290,  2789,  3071,  3507,  3508,  1895,  2209,  1875,  2535,
    2804,  3114,  2713,  3013,  2536,  1896,  1897,  2275,  2873,  2874,
    2875,  3154,  1898,  1899,  1413,   898,  1107,   899,  1234,  1900,
    1901,  3448,  2215,  2216,  2217,  2538,  2806,  3323,  3324,  1902,
    2515,  2784,  3287,  1996,  1997,  2959,  2618,  3210,  2619,  1998,
    2623,  2009,  2650,  2010,  2651,  2960,  2961,  2962,  2963,  1903,
    2196,  2197,  2512,  1904,  2868,  2601,  2864,  2270,  1964,  2265,
    2266,  2267,  2836,  1965,  2271,  2602,  2869,  2591,  2592,  2593,
    2594,  2595,  3334,  3135,  3449,  2596,  3336,  3337,  2862,  2597,
    2863,  2598,  2254,  2320,  2321,  2322,  3204,  2323,  2938,  2945,
    3372,  2620,  1012,  3325,  2926,  3107,  2622,  2586,  1282,   308,
    1283,  1949,   441,   944,  1934,  1950,  2567,    39,   900,   901,
    3066,  3283,  2777,  3282,  3569,  3594,  3595,  2781,  2506,  1905,
    2507,  2524,  3077,   596,  2502,  2503,  2276,  2604,  3281,  3070,
    1284,   959,  1285,  1286,  2865,  2599,  1288,  1289,  2256,  3451,
     902,   903,  2189,  2504,  3062,  3278,  3279,  1872,   904,  1058,
    1907,  1908,  2205,  2791,  1909,  1910,  2521,  1977,  2249,   905,
    1187,  1846,  1847,  1848,  2152,  1849,  2153,  1911,  2525,  3113,
    3319,  2800,  3110,  3111,  3112,  3109,  3097,  3098,  3099,  3100,
    3101,  3102,  3428,   906,  2083,  2381,  2382,  1031,  1290,  1033,
    2037,  1291,    25,   908,  1160,  2116,  1402,  1475,   909,   910,
    2686,   911,  2340,  1035,  2039,   912,   913,    35,   537,   538,
     539,   540,   541,   914
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -2757
static const short yypact[] =
{
     865,  1293, -2757,   272,   272,  1190, -2757, -2757,  1190, -2757,
      30, -2757, -2757, -2757,   415, -2757,   865, -2757, -2757, -2757,
   -2757, -2757,    28, -2757, -2757, -2757, -2757, -2757,   479,   496,
   -2757,   473, -2757, -2757, -2757, -2757, -2757, -2757,  -112, -2757,
     584,   157, -2757, -2757, -2757,  1034, -2757, -2757, -2757, -2757,
   -2757,   -15,   272, -2757,   272,   373,    30, -2757,   827, -2757,
   -2757, -2757, -2757, -2757, -2757,  1152,     6, -2757, -2757, -2757,
     721,   529,   272, -2757, -2757,   847,   272, -2757, -2757,   272,
     272, -2757, -2757, -2757, -2757,   272,   272, -2757, -2757, -2757,
   -2757, -2757,  1034, -2757, -2757, -2757, -2757, -2757, -2757, -2757,
   -2757, -2757,  5303, -2757,     6, -2757,   808,  3868, -2757, -2757,
     376, -2757, -2757,   870,   157,   327, -2757, -2757, -2757, -2757,
   -2757,  9300, -2757,   272,   515,   789,   272,    30, -2757, -2757,
   -2757,   272, -2757, -2757,   602,   551,   914, -2757, -2757,   557,
   -2757,   574, -2757,   580, -2757, -2757,   640, -2757, -2757, -2757,
   -2757, -2757, -2757, -2757, -2757, -2757, -2757,   544, -2757, -2757,
   -2757,   684,   706,   720,   732,   801,   811,   820,   825,   840,
     844,  3868,   859,  4347,   877,   896,   907,   920,   924,   938,
    1668,  1398, -2757, -2757, -2757, -2757,   633, -2757,   168, -2757,
    3868, -2757,   189, -2757, -2757, -2757,   152, -2757, -2757, -2757,
    -327, -2757, -2757, -2757, -2757, -2757, -2757,   602,   958, -2757,
     914, -2757, -2757,   977, -2757,  1023, -2757,  1009, -2757, -2757,
    1047, -2757, -2757, -2757, -2757, -2757, -2757, -2757, -2757, -2757,
    1065,  1451,   272,  1078, -2757,    30,    30,  1083,   272, -2757,
     435,  1544, -2757,   929,  1005, -2757,   933,  1017,  1583,  1587,
     272,  1597,  1602, -2757,   973, -2757,    48,    48,    48,    48,
      48,  4347,  1428,  1489,    64,  4347,   555,  4347, -2757,  4347,
    4347,  4347, -2757, -2757, -2757,  1082,  1184,  1187,  4347,  1077,
    1225, -2757,  4347,  4347,  1234, -2757,  1241, -2757,   896,  1264,
    1276,  1277,  1286,  1643,  8203,    75, -2757, -2757, -2757, -2757,
   -2757, -2757, -2757, -2757, -2757, -2757,  1220, -2757, -2757, -2757,
   -2757, -2757, -2757,   569,   569, -2757, -2757, -2757, -2757, -2757,
    3868, -2757, -2757,   272,  3868,  1176,   236, -2757, -2757, -2757,
   -2757,  1690, -2757, -2757, -2757, -2757, -2757, -2757, -2757, -2757,
    1289, -2757,  1289,   435,  1736, -2757, -2757, -2757,  1742,  1743,
     157,  1597,  1289,  1744,  1111, -2757,  1676, -2757,  1343,  1308,
   -2757,  1380, -2757, -2757, -2757,  1130, -2757, -2757,  1761,  1358,
   -2757,  1321, -2757, -2757, -2757, -2757, -2757, -2757, -2757,  1017,
    1321, -2757, -2757, -2757, -2757, -2757, -2757,  1323,   169,   215,
     288, -2757,  5274, -2757, -2757, -2757,  1329,  1794,   240, -2757,
    1332,   266, -2757,   -67,  1367,  1371,   277,   282,  7034,  1372,
    -139,  1281, -2757, -2757,   146,  1375, -2757, -2757, -2757, -2757,
     286, -2757, -2757,  7096, -2757,  6948,  8488,  4706,  4706,  4347,
   -2757,  1298,  4347,  8203,  1339, -2757, -2757, -2757, -2757, -2757,
   -2757, -2757,  1146,  1793,  7135,  8203,  1298,  1797,   528,  4347,
    4347,  4347,  4347, -2757,  4347,  4347,  4347,  4347,  4347,  4347,
    4347,  4347,  4347,  4347,  4347,  4347,  4347,  4347,  4347,  4347,
    4347, -2757, -2757, -2757, -2757, -2757, -2757, -2757, -2757, -2757,
   -2757,  4347,  4347, -2757, -2757,  1346,  4347, -2757,  4347,  1347,
   -2757, -2757, -2757, -2757, -2757, -2757, -2757, -2757, -2757, -2757,
   -2757, -2757,   569,  4347,  4347,  4347,  4347,  1387,  1818,  1668,
    4347,  1360, -2757,  3868,  1333, -2757,  1170,  1809, -2757,  1177,
   -2757,  1819,  1412,  1547,   391,   395,   307,  1384, -2757,   396,
   -2757, -2757, -2757,   272, -2757, -2757,   272,  1449, -2757,  6514,
     327,  6242,  1824,   264,   272,  1837,   348, -2757, -2757,  1005,
    1833, -2757, -2757, -2757, -2757,  1839, -2757,  1844, -2757,  1846,
   -2757,   272, -2757,   272, -2757, -2757,  1597,  1847, -2757, -2757,
   -2757,   272,    48, -2757,  3868,    38, -2757, -2757, -2757, -2757,
   -2757,  1077,  1077,  1851, -2757,  1854,  1254,  1340, -2757,    64,
   -2757, -2757, -2757,  1452,  8203,   586,  1456,  7301,  1865,  1077,
    1460, -2757,  1461,  1464, -2757,  7336,  7649,  7688,  7850,  8445,
    3793,  8488,  8545,  8593,  8636,  8693,  8798,  1269,  8625,  8830,
    4706,  4706,  3356,  3356,  3117,  8203,  7889,  7938,  1298,  8203,
    7998,  1298, -2757,  8203,  8203,  8203,  8203, -2757,  1866, -2757,
    1892, -2757,  8203, -2757,   247,  3868, -2757,  1465,  1885,   348,
   -2757,  1435,  1882, -2757,  1883, -2757, -2757, -2757,  1884, -2757,
   -2757,  1252,  1479,  1909, -2757,   272,  1482, -2757, -2757, -2757,
     569,   569,   569,  1031,   272,  1353,   248,   248,  1408,   272,
     272,   248,   248,  1045,   272, -2757,  1353, -2757, -2757,   272,
   -2757,   810, -2757, -2757, -2757,   248, -2757, -2757, -2757, -2757,
     272, -2757, -2757, -2757, -2757,    83,    83,  4347, -2757, -2757,
   -2757,  1408,  1408, -2757, -2757,   248, -2757, -2757,   248, -2757,
   -2757,   272, -2757, -2757,   248, -2757, -2757,   569,   248, -2757,
   -2757,  4347,   248,   569,   272,   569,   248, -2757, -2757,   136,
     248,   248,   136,   248,   272,   136,   248, -2757,   248,   248,
     248, -2757,  1353, -2757, -2757,   569,   248, -2757, -2757,   248,
      63,   272, -2757,  1408, -2757, -2757,   248,  1064, -2757, -2757,
     569, -2757,   248, -2757,  1463,   569,  4347,    48,    48,   248,
   -2757, -2757,  1031,   569,  1079, -2757,  4347, -2757,   671,  4347,
     248,    77, -2757,  4347,   248,  1891,   569, -2757,   248,  4347,
   -2757,  4347,    83,   272,   248,   272,    48,   248,   272,    48,
   -2757,   272,   171,   272, -2757, -2757, -2757, -2757, -2757, -2757,
   -2757, -2757, -2757, -2757, -2757, -2757, -2757, -2757, -2757, -2757,
   -2757, -2757, -2757, -2757, -2757, -2757, -2757, -2757, -2757, -2757,
   -2757, -2757, -2757, -2757, -2757, -2757, -2757, -2757, -2757, -2757,
   -2757, -2757, -2757, -2757, -2757, -2757, -2757, -2757, -2757, -2757,
   -2757, -2757, -2757, -2757,   498, -2757, -2757, -2757, -2757, -2757,
   -2757, -2757, -2757, -2757, -2757, -2757, -2757, -2757, -2757, -2757,
   -2757, -2757, -2757, -2757, -2757, -2757, -2757, -2757, -2757, -2757,
   -2757, -2757, -2757, -2757, -2757, -2757, -2757, -2757, -2757, -2757,
   -2757, -2757, -2757, -2757,  1127, -2757, -2757, -2757, -2757, -2757,
   -2757, -2757, -2757, -2757, -2757, -2757,   851,   272, -2757,   283,
   -2757,  1487, -2757, -2757, -2757,  1579, -2757, -2757,  1490,  1491,
    1492,  1494, -2757, -2757,  1265,  1925,  1500,  1501, -2757,   360,
   -2757,  1467, -2757, -2757,  1270, -2757,  1503, -2757,  1916, -2757,
    1319, -2757, -2757, -2757,  1291, -2757, -2757, -2757, -2757,  8972,
   -2757,  1082,  1521, -2757,  1082, -2757,  1082,  1082,  1082,  1082,
    1082,  1936,  1937,  1938,  4347,  1534,  1944,  4347,  1538,  1542,
    1546,  1548,  1550,  1552,  1553,  4347,  4347, -2757,   321, -2757,
   -2757, -2757,  1630, -2757,  1554,  1559,  1314,  1560,   272, -2757,
     272,  1562, -2757, -2757, -2757, -2757, -2757, -2757, -2757,   342,
    1330,  -189,  1561,  1509, -2757, -2757, -2757, -2757,  1338,   497,
   -2757, -2757, -2757, -2757, -2757, -2757, -2757,  1341,  1458,  1499,
   -2757,  1335, -2757,  1345, -2757,  1992,  1348, -2757, -2757,  1549,
   -2757,  1408, -2757,  1486,   199, -2757, -2757, -2757,  1081, -2757,
    8203, -2757, -2757,  1374, -2757, -2757,  3611, -2757, -2757, -2757,
     569, -2757, -2757,  1408, -2757,   -27, -2757, -2757,  1704, -2757,
      19, -2757,  1514, -2757, -2757, -2757, -2757,  2014, -2757, -2757,
     710, -2757,  1362, -2757,  1364,  2014, -2757,  1389, -2757, -2757,
   -2757,  1567,   124, -2757,  1525, -2757,  1325, -2757, -2757, -2757,
   -2757,  1334,   232, -2757,   364, -2757,  1341,  1665,  1385,  4347,
     195,  4347, -2757,  2035,   248, -2757, -2757, -2757, -2757, -2757,
      87,    87,    87, -2757,    87,  2703,    87,    87,  1409,   -27,
    1409,  1409,  1140,  1140,  1409,  1409,   -27, -2757,  2040, -2757,
    1585,   392, -2757,  2044, -2757,   -27,   111,    49, -2757, -2757,
    4347, -2757, -2757, -2757,  1011, -2757, -2757,   327,  4347, -2757,
    4347,  1594,  1595,  1596,  1601,  1493,  1603,  1079, -2757,  1681,
    1025,  1440, -2757,  1455, -2757, -2757,   272, -2757, -2757,  1210,
   -2757,  2068, -2757,  2063,   272, -2757,   508,  5604,  1462, -2757,
   -2757,  2076, -2757,  1390,  2076,  2079,  1391,  2076,  2079,  4347,
    2076, -2757, -2757,   199,   569, -2757, -2757,  1625,   388, -2757,
   -2757, -2757,  1616,   569,  4347,  1619, -2757, -2757,  2067,  2069,
    1988, -2757, -2757, -2757, -2757, -2757, -2757, -2757, -2757,  1213,
    1213,   248,   248,   248,  2922, -2757, -2757,  1964,   851, -2757,
   -2757,   520, -2757, -2757, -2757,  1604, -2757, -2757, -2757, -2757,
    5303,  1597, -2757, -2757,  1438,   272,  1157,  1077,  1471,  1523,
   -2757,  2031,  2031, -2757,  1341, -2757, -2757,  1229, -2757,  7657,
    1634, -2757,  1637,  1641, -2757,  1649,  1652,  1654,  1655,   272,
     587, -2757, -2757, -2757, -2757,    74, -2757,   272,  1926, -2757,
    1640, -2757, -2757, -2757, -2757, -2757, -2757, -2757, -2757, -2757,
   -2757, -2757, -2757,  8203,   400, -2757, -2757,   413, -2757, -2757,
   -2757, -2757, -2757, -2757, -2757, -2757, -2757, -2757,  1608, -2757,
     417, -2757, -2757, -2757, -2757, -2757, -2757,    30, -2757, -2757,
      30,   641,   201,  2089, -2757, -2757,   461,   222,   567,  2114,
   -2757, -2757, -2757, -2757, -2757, -2757, -2757, -2757,   272,  1540,
     272, -2757, -2757,  1556,   272,  1569,   272,  1458,  1345, -2757,
    1045,  -128,  1388,   272,  1408,  1496,  1656, -2757,  1657,    93,
   -2757, -2757, -2757,  1408, -2757, -2757,  2128, -2757, -2757,  1468,
    1666, -2757, -2757, -2757,  1045,  1214, -2757,  1214,  1079,   136,
    4347,  4347,  4347,  1667, -2757, -2757,   569,   569,  1408,  1474,
    1079,    48,  1443,    63,   569, -2757,  1472,  4347,  1748, -2757,
   -2757,  1551, -2757, -2757,   272,  2142, -2757, -2757,   153,   199,
   -2757, -2757,  2133,  2134, -2757, -2757, -2757, -2757, -2757, -2757,
   -2757, -2757, -2757, -2757, -2757, -2757, -2757, -2757, -2757, -2757,
   -2757, -2757, -2757, -2757, -2757, -2757, -2757, -2757, -2757, -2757,
   -2757, -2757,   564, -2757, -2757, -2757, -2757, -2757, -2757, -2757,
   -2757, -2757,  1463,   569,   569, -2757,  1140,  4347,   -30,  2126,
    2129, -2757, -2757, -2757, -2757, -2757,   164, -2757, -2757, -2757,
   -2757,  1965, -2757,  1733,   327,  4347, -2757,    80, -2757, -2757,
     272,  2145,    48,    48, -2757,  1537, -2757,    64,  1510,   569,
   -2757,   272,   272,  4347,  -137, -2757,  1557, -2757, -2757,   302,
   -2757,  1658, -2757,  1669,  4347,  1215, -2757, -2757,  1517, -2757,
    2173, -2757,  1610, -2757,   569, -2757, -2757, -2757, -2757, -2757,
   -2757, -2757, -2757, -2757, -2757, -2757, -2757, -2757, -2757, -2757,
   -2757, -2757, -2757, -2757, -2757, -2757, -2757, -2757, -2757, -2757,
   -2757, -2757, -2757, -2757, -2757, -2757, -2757, -2757, -2757, -2757,
   -2757, -2757, -2757, -2757, -2757, -2757, -2757, -2757, -2757, -2757,
   -2757, -2757, -2757, -2757, -2757, -2757, -2757, -2757, -2757, -2757,
   -2757, -2757, -2757, -2757, -2757, -2757, -2757, -2757, -2757, -2757,
   -2757, -2757, -2757, -2757, -2757, -2757, -2757, -2757, -2757, -2757,
   -2757, -2757, -2757, -2757, -2757, -2757, -2757, -2757, -2757, -2757,
   -2757, -2757, -2757, -2757, -2757, -2757, -2757, -2757, -2757, -2757,
   -2757, -2757, -2757, -2757, -2757, -2757, -2757, -2757, -2757, -2757,
   -2757, -2757, -2757, -2757, -2757, -2757, -2757, -2757, -2757, -2757,
   -2757, -2757, -2757, -2757, -2757, -2757, -2757, -2757, -2757, -2757,
   -2757, -2757, -2757, -2757, -2757, -2757, -2757, -2757, -2757, -2757,
   -2757, -2757, -2757, -2757, -2757, -2757, -2757, -2757, -2757, -2757,
   -2757, -2757, -2757, -2757, -2757, -2757, -2757, -2757, -2757, -2757,
   -2757, -2757, -2757, -2757, -2757, -2757, -2757, -2757, -2757, -2757,
   -2757, -2757, -2757, -2757, -2757, -2757, -2757, -2757, -2757, -2757,
   -2757, -2757, -2757, -2757, -2757, -2757, -2757, -2757, -2757, -2757,
   -2757, -2757, -2757, -2757, -2757, -2757, -2757, -2757, -2757, -2757,
   -2757, -2757, -2757, -2757, -2757, -2757, -2757, -2757, -2757, -2757,
   -2757, -2757, -2757, -2757, -2757, -2757, -2757, -2757, -2757, -2757,
   -2757, -2757, -2757, -2757, -2757, -2757, -2757, -2757, -2757, -2757,
   -2757, -2757, -2757, -2757, -2757, -2757, -2757, -2757, -2757, -2757,
   -2757, -2757, -2757, -2757, -2757, -2757, -2757, -2757, -2757, -2757,
   -2757, -2757, -2757, -2757, -2757, -2757, -2757, -2757, -2757, -2757,
   -2757, -2757, -2757, -2757, -2757, -2757, -2757, -2757, -2757, -2757,
   -2757, -2757, -2757, -2757, -2757, -2757, -2757, -2757, -2757, -2757,
   -2757, -2757, -2757, -2757, -2757, -2757, -2757, -2757, -2757, -2757,
   -2757, -2757, -2757, -2757, -2757, -2757, -2757, -2757, -2757, -2757,
   -2757, -2757, -2757, -2757, -2757, -2757, -2757, -2757, -2757, -2757,
   -2757, -2757, -2757, -2757, -2757, -2757, -2757, -2757, -2757, -2757,
   -2757, -2757, -2757, -2757, -2757, -2757,  4899, -2757, -2757, -2757,
   -2757,   272,    48,    48,   231,   388,  2002,  1239,   569,   199,
   -2757,  1613, -2757, -2757,  2142,  2175,  1760, -2757, -2757, -2757,
   -2757, -2757,  1841,  1841, -2757,   372,  1617, -2757,   272,  1408,
   -2757,  1408,  1408, -2757, -2757,  1408,   272, -2757,   272,   586,
    1408, -2757,   672, -2757, -2757, -2757, -2757, -2757, -2757, -2757,
   -2757, -2757, -2757, -2757, -2757, -2757, -2757, -2757, -2757, -2757,
   -2757, -2757,   162,   162,   251,  1036, -2757,   940, -2757,   520,
   -2757,    30,  2181, -2757, -2757,  1392,  1781,  1749, -2757, -2757,
   -2757, -2757, -2757, -2757, -2757, -2757,  1582, -2757, -2757, -2757,
    1558,  1558, -2757, -2757, -2757, -2757, -2757, -2757, -2757, -2757,
    1565,   586,  1790,   572,   680,  8972,   680,   680,   680,   680,
    1568,  8972,  8972,   242,  1663,    24, -2757,  8972,  8972,  8972,
    8972, -2757, -2757, -2757, -2757, -2757, -2757, -2757,  1045,  4347,
   -2757, -2757,  1798,  2181, -2757, -2757, -2757, -2757,    30, -2757,
    1750,  1765,  1766,   866,  1767,  1770, -2757, -2757, -2757,  2148,
     272, -2757,  2242, -2757, -2757,   598,  2123, -2757, -2757, -2757,
   -2757,   272, -2757, -2757,   598,  1545, -2757,   342, -2757,  1590,
   -2757,  1623, -2757,  1828,     6, -2757,  1607, -2757,  1638,  1620,
   -2757,  1079,  1664, -2757, -2757,  1782, -2757, -2757, -2757,  1697,
    1813,   272, -2757, -2757, -2757, -2757,  3611,   272, -2757,  1633,
   -2757, -2757, -2757, -2757,  1629, -2757,  2289,  2302, -2757,  2303,
    1693,  4347, -2757, -2757,  2305, -2757,  1659, -2757,  1792,  1648,
    2079, -2757, -2757,  1653,   942,   272, -2757, -2757,  1845,   248,
    1032, -2757,  4347,  1408, -2757,   272,   272,  4347,    37,   -27,
    2316,  2314,  2297,  2298,  2703, -2757, -2757, -2757, -2757, -2757,
   -2757, -2757,   569,  1968, -2757, -2757,  2220,  4347,   327,  2073,
   -2757, -2757, -2757,  4347,    83, -2757,  1966,  2331,  2332,   419,
     422,   272,  1906,  1079, -2757,  4347,  1869,  1871, -2757, -2757,
    1941, -2757,  4347,   -83, -2757,  1708, -2757, -2757,   219, -2757,
    4347, -2757, -2757,  1682,   808, -2757,  1414,   272,  2336,  8730,
   -2757, -2757,  1045,   569, -2757, -2757,    81, -2757,  2079,  2079,
    1651, -2757,  1762,  1774, -2757, -2757, -2757, -2757,    48,    48,
   -2757, -2757, -2757, -2757, -2757, -2757, -2757, -2757,  1636, -2757,
   -2757, -2757, -2757,    48,  3640,  2347,  2328, -2757,  1079,   805,
     265,   141,  2216,    16,  1031, -2757,    54, -2757, -2757, -2757,
    1893,   117,  1408,   224, -2757,  1706,  1698, -2757, -2757,   660,
   -2757, -2757, -2757, -2757,  1895,  1707,  2369, -2757, -2757, -2757,
     569,   197, -2757, -2757, -2757,  1701,  1036, -2757,   272,   272,
   -2757, -2757,   272,   563, -2757, -2757, -2757, -2757,  1908, -2757,
   -2757, -2757,  2355, -2757, -2757,  1271,  8972, -2757,   455,  1948,
    2378, -2757, -2757, -2757,  8972, -2757,   437,  8972,  8972,  8972,
    8972,   272,   438, -2757,   245,  2383, -2757, -2757,   272,  4549,
   -2757,  1978,   272,  1732,   680,  2017, -2757, -2757, -2757, -2757,
   -2757, -2757,  8203, -2757,  1928, -2757,  1898, -2757,  1899,   161,
     161,   161,   449,  2148,   161,  4549,   272, -2757,   453,   272,
     457, -2757, -2757, -2757,  1930,  1939,  1946,  1229,  1229, -2757,
    1947, -2757,  1949,  1950,  1951,  1953, -2757, -2757, -2757, -2757,
    1093, -2757, -2757, -2757,   467, -2757, -2757,   468,   272, -2757,
     272,  1615, -2757,   272,  1628,  1388,  2389,  1079,  3868,  4347,
   -2757,   272,  2405, -2757, -2757,   598, -2757, -2757,  1768,   598,
     105, -2757,  1079,  4347,  4347,  4347,  3969,  2415,  1408,   155,
   -2757,  1079,   272, -2757, -2757,   272,   272, -2757,   799, -2757,
   -2757,   408, -2757,  1769,  4347, -2757, -2757, -2757,  2418, -2757,
    1771,  2422, -2757, -2757, -2757, -2757, -2757,   272,  2079, -2757,
   -2757,  1836, -2757, -2757,   470, -2757, -2757, -2757,   569, -2757,
    6987, -2757,  1040, -2757, -2757,  2064,  2407, -2757,  2046,  2047,
    1940,  1776,  2049,  1967, -2757, -2757, -2757,    31,  2038, -2757,
   -2757, -2757, -2757,  1941, -2757, -2757, -2757,   233,   541, -2757,
   -2757, -2757,  2142,  4347,  1971, -2757,  1942, -2757, -2757, -2757,
   -2757,  2439, -2757, -2757, -2757,  2441, -2757,  1756, -2757,  2423,
     -27,   272,  1788,  1788,  1788,  1788, -2757,  2445, -2757,  2446,
    1788,  1788,  1788,  1788,   564, -2757, -2757,  1788,   110, -2757,
   -2757, -2757, -2757,  2427,  2443, -2757, -2757, -2757, -2757, -2757,
   -2757, -2757, -2757, -2757,  2447, -2757, -2757, -2757, -2757, -2757,
   -2757, -2757,   472, -2757, -2757, -2757,  2429, -2757, -2757,  1408,
   -2757,   586, -2757, -2757, -2757, -2757, -2757, -2757,  1826,  1827,
     241, -2757,    54, -2757,   161,  1803,   248, -2757,  1993, -2757,
   -2757, -2757,   272,   272,  8972,   216, -2757,  4347, -2757,  4347,
   -2757, -2757, -2757, -2757, -2757,  1872,   248,   161, -2757,  1408,
    1061,  2462, -2757,   569,   272,   968,   968, -2757, -2757,  2463,
   -2757,  2463,   826,   826,  2463, -2757, -2757,  1824, -2757,  2036,
    1999, -2757, -2757, -2757, -2757, -2757, -2757, -2757,    74,  1229,
    1806, -2757,  1229,  2039,  8972, -2757,  2041,  2042,  2045,  2048,
   -2757, -2757,   242, -2757,   242, -2757, -2757,  4597,  2006,  2887,
    2006,  2468,  2473, -2757, -2757, -2757, -2757, -2757, -2757,   606,
    8972, -2757,  1998, -2757,  2171,   205,   265,   272, -2757,  6589,
      72, -2757,  1824,  1598, -2757,    72,  1408,   874,  2054,  2478,
    1830, -2757, -2757,   474, -2757,   487,   866, -2757, -2757,   488,
     154, -2757, -2757, -2757,   598, -2757,  2466,  2466,  2467,  1829,
     -95,  2471,  2472,  2475,  2471,  2471, -2757, -2757, -2757,   167,
   -2757,   922,   272, -2757,   598, -2757, -2757, -2757,  1834, -2757,
   -2757,  1842, -2757,  1848,  1079,  2491,   323, -2757,   281,   489,
   -2757,   272,   491, -2757,  4347,  2070,  2485,   493,  1079,  2501,
   -2757, -2757, -2757, -2757,  4347,  1900,  2193,  4347, -2757, -2757,
   -2757, -2757,   408,  1003,  1003,  2505,   374, -2757,  2507, -2757,
   -2757, -2757,  1003,   272,  1931,  1430,  2512,   272,   223,  1408,
     -56,  4347, -2757, -2757,  2703, -2757,  1817,  4347, -2757, -2757,
   -2757,  2521,  4347,   569, -2757,   810,   272,   569, -2757,  2093,
    4347,  4347, -2757, -2757,    31,  2038, -2757,   564, -2757, -2757,
    1219, -2757, -2757,  1917, -2757,  3868,  4325,  8730,    61,  1038,
   -2757, -2757, -2757,  1877, -2757, -2757, -2757, -2757,    48,  1788,
      48,  1788, -2757, -2757, -2757, -2757, -2757, -2757,   -27, -2757,
    1197,  1224,  3640, -2757,  2104,  2071,  8972, -2757,   141,   141,
   -2757, -2757, -2757, -2757,   501, -2757,  2027, -2757,   161,   589,
   -2757,  1876, -2757,  2539,  8993,  8993,  8993,  8993,   161,   161,
   -2757, -2757, -2757, -2757, -2757, -2757,   502, -2757,  1879, -2757,
     569, -2757,  2463, -2757, -2757,   272,   826,   826, -2757, -2757,
     826,  2294,  1886, -2757,  2522,  2115,  1887,  1271,  1888, -2757,
   -2757, -2757, -2757, -2757, -2757, -2757,   503, -2757, -2757,  2043,
   -2757,   361,   505, -2757,  4549,  4549, -2757, -2757, -2757, -2757,
   -2757, -2757, -2757, -2757, -2757,  2031,  2031,  2080,  2031,  2085,
   -2757,  2031,   597,  8972,  2546, -2757, -2757,  4549, -2757, -2757,
   -2757, -2757, -2757,  2553, -2757,   287, -2757, -2757,  2171,  1901,
   -2757, -2757,    83,    83,    83,  2534,    83,    83,    83,    83,
      83,    83,  2541, -2757,  2542,    83, -2757, -2757, -2757, -2757,
   -2757, -2757, -2757, -2757,  6589, -2757,   569,  1905, -2757,  2081,
    2294,  2545, -2757,  2547,  2548,  2549,  2550,  2551,  2552,  1312,
    1598, -2757,  2081, -2757, -2757,  2556, -2757,  2247,   161,  1502,
     161, -2757, -2757,  2148, -2757, -2757, -2757, -2757,  2153,  2155,
     506,  1271,  2564,  1271, -2757,  2586,   511,  2158,  2159,  2586,
   -2757, -2757, -2757, -2757,  1408, -2757, -2757, -2757,  2122, -2757,
   -2757,   922, -2757,  2148, -2757, -2757,   272,   272, -2757,  1079,
   -2757, -2757, -2757,   272,  -261, -2757,   598,   158,  2142, -2757,
    2086,   158,   239,  1079, -2757,  2591,  2127, -2757, -2757,  2164,
    2009, -2757, -2757,   272,  1003,  3868,  1526,   272,  1003, -2757,
   -2757,    48, -2757, -2757,  4347, -2757, -2757, -2757, -2757, -2757,
   -2757,    48,  2142,   569,  2323, -2757,  2581,  1762,  8203,  2583,
   -2757, -2757,   199,  2143, -2757, -2757,  4347, -2757, -2757,  2176,
   -2757, -2757, -2757,   541, -2757,  1762, -2757,  4347, -2757,   354,
   -2757,  2044, -2757, -2757, -2757, -2757,  2130,  2228, -2757,  2597,
   -2757, -2757, -2757, -2757, -2757, -2757, -2757, -2757, -2757, -2757,
   -2757,   272, -2757,   101, -2757, -2757, -2757,   161, -2757,   586,
    2434,   519, -2757, -2757, -2757, -2757,   272,  2025,  7768,  7768,
   -2757, -2757,  9093,  2149, -2757, -2757,  2150,  2151, -2757,  2152,
    2154,  2156,  2161,   272,   616, -2757, -2757,   527, -2757, -2757,
    2279, -2757, -2757, -2757,   530,  2615,  2615, -2757, -2757,   534,
    2620,  2613, -2757,   126,   569,   161, -2757,   156, -2757, -2757,
   -2757, -2757, -2757,  2377,  5303,  2200, -2757,  1271, -2757,  1271,
     242, -2757, -2757,  2473, -2757,  2157,  1926,  2157,   213, -2757,
    2157,   213, -2757,  2157,  2031, -2757, -2757,  8972, -2757,  8972,
    2468,   205, -2757, -2757, -2757, -2757, -2757, -2757, -2757, -2757,
   -2757, -2757, -2757, -2757, -2757, -2757, -2757, -2757, -2757, -2757,
   -2757,   424,  2630, -2757,   569,  1661, -2757,  2377, -2757, -2757,
   -2757, -2757, -2757, -2757, -2757, -2757, -2757, -2757, -2757,   355,
   -2757, -2757, -2757,  2137, -2757, -2757, -2757, -2757,  2612, -2757,
   -2757,  2205, -2757,  2617,  2207,  2619, -2757, -2757, -2757,  2213,
   -2757,  2178,  4549, -2757, -2757, -2757, -2757, -2757, -2757,   272,
    2628, -2757,  -261, -2757, -2757,  2629, -2757, -2757,  2631,   272,
    2171,   158, -2757,    48,   -27, -2757,  2241,  1079, -2757,  4347,
   -2757,  2050,  2636,   -27, -2757, -2757,   429, -2757, -2757, -2757,
   -2757,   121,  2229,  2079,  2441,  2382, -2757,   -27,  2231,  2233,
    2316,  2198, -2757,  2283,  2240, -2757, -2757, -2757, -2757,  2394,
    2179,  4347,  2196, -2757, -2757, -2757,  1762, -2757,   539, -2757,
     569,  2094, -2757, -2757, -2757,  8972, -2757, -2757,   161, -2757,
    2210, -2757,  2094,  2168,  2168,  2250,   572,   680,  9119,   680,
     680,   680,   680,  2026,  9119,  8993, -2757,  9119,  9119,  9119,
    9119, -2757, -2757,   161,  2671,   161,  8993,   248,  4549, -2757,
    2441, -2757, -2757,   850, -2757, -2757, -2757, -2757, -2757, -2757,
   -2757, -2757, -2757,   167, -2757, -2757,   540, -2757, -2757, -2757,
   -2757,   542, -2757,  2157,  2680, -2757, -2757, -2757, -2757, -2757,
   -2757,   569,  2630, -2757, -2757, -2757,   569, -2757,   569, -2757,
   -2757,  1994, -2757,  2408, -2757,  2409,  2662, -2757, -2757,  2258,
    2029, -2757, -2757, -2757,  2259, -2757,   161,   363, -2757, -2757,
   -2757, -2757, -2757, -2757, -2757, -2757, -2757, -2757, -2757,  1079,
   -2757,  2261,  9437,  2226, -2757, -2757, -2757,  2051,   -27, -2757,
   -2757, -2757, -2757, -2757, -2757,  2265,   199, -2757,  2283,  2283,
     541, -2757,  3868,  2087, -2757, -2757,   272, -2757,  2441,    24,
      74, -2757,  8872,    24, -2757,  2273,  9119, -2757,   543,  9119,
    9119,  9119,  9119,   272,   545, -2757, -2757, -2757, -2757, -2757,
   -2757,  2236, -2757, -2757, -2757,  2468,   156, -2757, -2757, -2757,
   -2757, -2757,   179, -2757, -2757, -2757,  8972, -2757,  1737,  1737,
   -2757,  1737, -2757,  1737,  1737, -2757, -2757, -2757,  2245, -2757,
    1271, -2757,   546, -2757,  1052, -2757, -2757,    87,    87,    87,
      87,    87,    87, -2757,  2684, -2757,   550, -2757,  4347,  1564,
   -2757,    55,  2283,  4347,  2283,  2316, -2757, -2757, -2757,  2431,
     358, -2757,   -27, -2757, -2757, -2757, -2757,   552, -2757, -2757,
    1401, -2757,  2276,  9119, -2757,  2282,  2284,  2285,  2287, -2757,
   -2757,  8993, -2757, -2757, -2757, -2757, -2757,  1737, -2757,  1737,
   -2757, -2757, -2757, -2757, -2757, -2757, -2757, -2757, -2757,  1147,
   -2757, -2757, -2757, -2757, -2757, -2757, -2757, -2757, -2757,  9437,
   -2757,  2712, -2757, -2757, -2757, -2757,   623, -2757, -2757, -2757,
   -2757, -2757, -2757,    81, -2757,  8872, -2757,  1647, -2757, -2757,
   -2757, -2757, -2757, -2757, -2757, -2757,   565, -2757, -2757,  1202,
    1202, -2757, -2757,  1202, -2757,  4347,   725, -2757, -2757,  2291,
      61, -2757,  2072,  2074,  2722, -2757, -2757, -2757, -2757, -2757,
    2296, -2757, -2757, -2757,   272,   272,  1647, -2757,   220,  2075,
   -2757, -2757, -2757,   199, -2757,   272,  2316, -2757
};

/* YYPGOTO[NTERM-NUM].  */
static const short yypgoto[] =
{
   -2757, -2757, -2757, -2757, -2757,     8, -2757,    60,  -168, -2757,
   -2757, -1059,  -534, -2757, -2757, -2044, -2757, -2757, -2757, -2757,
    -813, -2757, -2757, -2757, -2757, -2757, -2757, -2757, -2757, -2757,
   -2757, -2757, -2757, -2757, -2757, -2757, -1851, -2757,  -978, -2757,
    1755, -2757, -2757, -2757, -2757, -2757, -2757, -2757,   318, -2757,
   -2757, -2757, -2757,  1238, -2757,   612, -2757, -2757,   -29, -2757,
   -2757,  2714, -2757,  2715,  2206, -2757, -2757, -2757, -2757, -2757,
     386,    46, -2757,   382, -2757, -2757, -2757, -2757, -2757, -2757,
   -2757, -2757, -2757, -2757, -2757,  -114,   998,   994, -2757, -2757,
    2402,   -44, -2757,  2639, -2757, -2757,  2638, -2757,  2555, -2757,
   -2757, -2757, -2757, -2757,  2411,  2110,   777,  2412,  -511, -2757,
   -2757, -2757, -2757, -2757,   780,  -634, -2757, -2757, -2757, -2757,
   -2757, -2757, -2757, -2757,   878, -2757,  2543,  2235,  2559,    70,
    2180, -2757,  2221,  1511, -2757,  2395, -2757, -2757, -2757, -2757,
    2397, -2757, -2757, -2757, -2757,  -385, -2757, -2757, -2757, -2757,
   -2757, -2757, -2757, -2757,  2217, -2757,  2211, -2757, -2757, -2757,
   -2757, -2757, -2757, -2757, -2757, -1330, -2757, -2757,  -762, -2757,
   -2757, -2757, -2757, -2757, -2757, -2757, -2757, -2757, -2757,  -116,
   -2757, -2757,   733, -2757, -1089, -1131,  -513, -2757, -2757, -2757,
   -2757, -2757, -2757, -2757, -2757, -2757,  1804, -2757, -2757, -2757,
   -2757, -2757, -2757, -2757,  -570, -2757, -2757, -2757, -2757, -2757,
    1995, -2757, -2757, -2757, -2757, -2757, -2757, -2757, -2757,  -510,
   -2757,  -103, -2757, -2757, -2757, -2757,  2373, -2757, -2757,  -250,
   -2757, -2757, -2757, -2757, -2757, -2757, -2757, -2757, -2757, -2757,
   -2757, -2757,  1563, -2757, -2757, -2757, -2757,   554, -2757, -2757,
   -2757, -2757, -2757, -1905, -2757, -2757,   553, -2757, -2757, -2757,
   -2757, -2757, -2757, -2757, -2757, -2757, -2757, -1074,  -811,   432,
     702, -2757,  -198,  -554,   577, -1099,   880, -2757,   558, -2757,
   -2387,    -3,  -648, -2757, -2757, -2247,   316,   979, -2757, -2757,
   -2757,   664,   939, -2757, -2757, -2757, -2757, -2757, -2757,    50,
   -2757,  -249, -2757,   943, -2757,   642, -2757,   353, -2757, -2757,
   -2757, -2757,  -787, -2757, -2757, -2757, -2757, -2757, -2757, -2757,
   -2757,   446, -2757, -2757, -1810, -2757,   627, -2757, -2757, -2757,
   -2757, -2757, -2757, -2757, -2757, -2757, -2757, -2757, -2757, -2757,
   -2757, -2757,  1403, -2757, -2757, -2757, -2757, -2757, -2757,  -443,
   -2757, -2757, -2051, -2757, -2757, -2757, -2757,   603, -2157, -2757,
   -1098, -2757, -2757, -2757, -2757, -2757, -2757, -2757, -2757, -2757,
   -2757, -2757, -2757, -2757, -2757,  2793, -2757, -2757, -2757,  2718,
    2771, -2122, -2757, -2757, -2757, -2757, -2757, -2757, -2757,  -364,
   -2757, -2757, -2757, -2757, -2757,  2776, -2757, -2757,  2795, -2757,
   -2757, -2757, -2757, -2757, -2757, -2757, -2757, -2757, -2757, -2757,
    1902, -2757, -2757, -2757, -2757, -2757,   681, -2757, -2757, -2757,
   -2757, -2757, -2757, -2757, -2757, -2757, -2757,  -686,  2077, -2757,
   -2757, -2757, -2757, -2757, -2757, -2757,   990, -2757, -2757,   -23,
   -2757, -2757,   676, -2757, -2757, -2757, -1015,  -184,  2499, -2757,
   -2757, -2757, -2757,   610, -2757, -1033,  1825,   965, -2121,  1365,
   -2757,   679,  1624,  -344,  -520, -2757, -2757,  2062,  1436, -2757,
   -2757, -2757, -2757, -2757, -2757, -2757, -2757, -2757, -2757, -2757,
   -2757, -2757, -2757, -2757, -2757, -2757, -2757, -2757, -2757,  1373,
   -2757,  -756, -2757,  -553, -2757, -2757, -2757, -2757, -2757, -2757,
   -2757,  -722, -2757, -2757, -2757, -2757, -2757, -2757,    89, -2757,
    1450,   656, -2757, -2757, -2757, -2757, -2757,   -79, -2757,  -522,
   -2757, -2757, -2757, -2757, -2757, -2757, -2757, -2757, -2757, -2757,
   -2757, -2757, -2757, -2757, -2757,  1355, -2757, -2757, -2757, -2757,
   -2757, -2757, -2757, -2757,  -519, -2757,   731,  2398, -2757, -2757,
     -75, -2757,  -612, -2757, -2757,   -57,   235, -2757, -2757, -2757,
   -2757, -2757, -2757, -2757,  1244, -2757, -2757, -2757, -2757, -2757,
   -2757, -2757, -2757, -2757, -2757, -2757, -2757, -2757, -2757, -2757,
   -2757, -2757, -2757, -2757, -2757, -2757, -2757, -2757, -2757,  -130,
   -2757,  -377,  -373, -2757, -2757,  -365, -2757, -2599, -2757,  -111,
     510, -1318, -2757, -2757, -2757,   846, -2757, -1917, -2757, -2757,
   -2757, -1933, -2757, -2757, -1878, -2757, -2757, -2757, -2757, -2200,
   -2757,   861,   566, -2757, -2757, -2757, -2757, -2757,   356, -2757,
   -2757, -2757, -2757, -2757, -2757,  -698, -2757, -2757, -2757, -2757,
   -2757, -2757, -2757, -2757, -2757, -2757, -2757, -2757, -2757,  -283,
   -2757, -2757, -2757, -2757, -2757, -2757, -2757, -2757, -2757, -2757,
   -2757, -2757, -2757, -2757,   329, -2757, -2757, -2757,  -575, -2757,
   -2757, -2757, -2757, -2757, -2757,   -54, -2757, -2757,  -501, -2757,
    -936, -1301, -2757, -2757, -2757, -2757, -2757,   -85, -2757, -2757,
   -2757, -2757, -2757, -1974, -2757, -2757, -2757, -2757, -2757, -2757,
   -2441,   621, -2757, -2527,   685, -2757, -2757, -2257,    43,    35,
     301, -2757, -1842, -1899, -2757, -2757,  -252,  -561, -2757, -2757,
   -2757, -2757, -1821, -2757, -2757, -2757,   -55, -2757,   256,  -903,
   -2757,   430,  -267,  1019,  -298, -2082,   284, -2757,  -264, -2757,
   -2757, -2757, -2757,    36, -2757, -1316, -2756,  2890, -2757, -2757,
   -2757, -2757, -2757, -2757, -2757, -2757,  -705, -2757, -2187, -2757,
    1674, -2757, -2757,   -82,   296, -2757, -2158,   308,  -160,   129,
   -2292, -1855, -2210,   959,  -229,  -503, -1244, -2757,   962, -2757,
   -2757, -2757,  1051,  -760, -2757, -2757,  -488,  1700, -2757,   700,
   -2757, -2757, -1796,  -145, -2757, -2757, -2757, -2220,  -363, -2757,
   -2757, -2757,  1086, -2757, -2757, -2757, -2757, -2757, -2757, -2757,
   -2757, -2757, -2757, -2659,  -380, -2757, -2753, -2297, -1268, -1332,
   -2757, -2757,  -368, -2757, -2757, -2757,   228,  -655,  -650,  -745,
     604,  -426,   182, -2757, -2757, -2757, -2757,  1536, -2757, -2757,
   -2757, -2757, -2757, -2757, -2757, -2757, -2757,  -320,  1204,  2403,
   -2757, -2757, -2757, -2757
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -2200
static const short yytable[] =
{
      34,    36,    38,   266,   184,    38,   326,   564,  1316,   406,
     407,  1369,   989,   234,  1359,  1420,    87,  1940,  1941,  1476,
    2015,   669,  1418,  2370,  1157,   113,  1151,  1448,  1014,  1017,
    1999,   104,  2445,  1032,  2207,   953,  2568,    58,  2630,  2044,
    2739,  2825,  3104,  3105,  3106,  2162,  2163,  1427,  1428,   103,
    1429,    58,  1450,  1451,   572,   935,  1081,   294,   940,   404,
     405,   977,   110,    87,    33,    33,   421,  1057,   184,   117,
    1057,  3128,   945,   122,   197,    33,   124,   125,  2325,  1962,
    1066,  2768,   128,   129,  1057,  2113,  1468,   184,  1057,   419,
      33,    33,  2206,  2628,  1049,  1083,  2246,  2326,  1859,   272,
    1057,   500,  1066,    58,    33,   253,  1962,   272,  1095,  1045,
    1854,  1066,  1108,  1421,    33,   572,   572,  1032,  1105,  2699,
     230,   362,   363,   233,  1112,  1864,   572,  2301,   237,  1397,
    1155,  1149,    33,  1044,  1877,  2257,  2258,  2259,  2260,  3108,
    2493,  2835,  1095,  2837,  1056,   408,  1095,  1385,  1386,   423,
    1095,   425,   509,   426,   427,   428,  1066,  2509,  2082,  1066,
    2844,  1074,   433,    33,  3044,   585,   444,   445,    33,  1467,
    1855,   331,   586,   324,   557,  2689,   272,   332,   333,   253,
    1018,   355,    33,    33, -2198,  3200,  1018,  3202,    33,   329,
    1189,   272,  2950,  1265,  1051,   272,  1201,  1202,    33,  1109,
    1397,  1111,  2543,   272,  1264,  1265,    33,  2621,  2624,  2624,
    1150,  3225,  2624,   272,   327,   328,    33,   184,  1067,  1113,
     559,   184,  2513,   272,  1201,  1202,    33,   101,    33,   359,
    1018,  2872,    33,  1469,  1470,   365,  2082,   272,  1264,  1265,
      33,   324,  2135,  3007,  3236,   567,  2129,   394,  1018,    33,
      33,  2906,   324,   403,   403,   403,   403,   403,  2738,    33,
      33,   403,  2084,  1144,  2085,  1359,  2086,  1018,    33,    33,
    1018,   572,    33,  1159,   101,    33,  1174,  2690,    33,  3155,
    1180,   347,   572,  1358,  3226,  3227,  1186,   572,  1188,  1212,
    1155,   589,    33,   561, -2198,   582,  2840,   519,  2843,    33,
    2422,   523,  2794,  2795,  2796,  2797,  2798,  2766,     4,  2516,
      58,    58,   114,   594,  2793,   442,   597,  2370,  3317,    54,
     511,  1457,  1458,  2782,  2551,  2135,   324,  2554,   324,   644,
    1220,  1881,  2841,   605,   606,   607,   608,    54,   609,   610,
     611,   612,   613,   614,   615,   616,   617,   618,   619,   620,
     621,   622,   623,   624,   625,   569,  1016,  1016,  2102,   324,
    3366,  1016,  1016,   324,   602,   626,   627,  2844,    54,  2844,
     629,  3330,   630,  3331,   938,  1016,  3010,  2942,   315,   316,
     317,   318,   319,   336,   337,   338,  2090,   633,   634,   635,
     636,   421,  2171,  1859,   642,  1016,   652,  1464,  1016,  2272,
     654,   658,  3219,    54,  1016,  1979,   939,  1498,  1016,  1212,
     184,  1028,  1016,  2703, -2198,    44,  1016,  2106,  1979,  1036,
    1016,  1016,  1984,  1016,   572,  3612,  1016,   572,  1016,  1016,
    1016,    54,  2785,   574, -2198,  2821,  1016,  1331,  1332,  1016,
    2519,  1349,  2574,  2574,  3228,  1028,  1016,   315,   316,   317,
     318,   319,  1016,  2606,  2626,  2807,  1287,  3220,  2299,  1016,
    2569,   988,  2634,  1350,    54,    54,  1149,  1333,  1334,  1335,
    1016,   184,  2652,  2654,  1016,  2714,     6,  2772,  1016,  2930,
    1212,  1097,  1503,    54,  1016,  1090,   569,  1016,    33,  2031,
    2910,   583,  2930,  2930,  2973,  2136,  2976,    54,  2976,    58,
    2145,    26,  3096,  3096,  3096,  3096,  3067,  3115,  3130,     7,
      48,  3198,   821,   915,  2846,  2847,  3205,  2848,  2849,  2850,
    2851,  2852,  2853,  2876,  3288,    27,  2176,  1146,  1147,  2032,
     661,  1883,  3305,   661,  1013,  3305,  2132,  2520,  2783,  3313,
      52,   661,   184,  1377,  3416,  3452,   975,  3452,  3513,   978,
    3513,  2928,  2191,  2192,    69,  3549,  1195,  3565,   394,  1198,
     394,  2704,  1099, -2198, -2198,  3139,  3063,  3142,   937,   403,
    3305,  2943,   942,   315,   316,   317,   318,   319,  2136,  2273,
    3032,  1860,  1215,  1874,  1112,  1149,   403,  2387,  2935,  1430,
    2274,  3064,  3065,   575,    33,  1454,    33,  1027,  1203,    33,
    1892,  1860,  1461,   558,  1211,  1267,  2103,  3144,  3613,    53,
    3150,    33,  2029,   562,     1,  2846,  2847,  1267,  2848,  2849,
    2850,  2851,  2852,  2853,  2429,    33,  3008,  2907,  2054,  1422,
    3257,  3385,   656,   275,  1013,   963,   325,  1144,  1482,  2812,
    2069,  1013,   102,  3011,  3045,  1483,  2776,  1489,  3267,   560,
   -2198,  1267,  2510,  1889,  3440,  2100,  3237,   105,   951,  1404,
    3322,  1963,   661,  1214, -2198,  1098,   112,    58,    58,    58,
      58,  1009,  1011,  2000,   568,  1019,  1021,  1022,  2220,  1876,
    1029,  1034,  1423,  1011,  2269,  1387,  1037,    33,    58,  3332,
    1986,  1471,  2293,  3318,  2011,  3280,  2015,  1022,    33,  1204,
     573,  2449,  1215,  2055,   514,  2030,  3072,  1176,  1019,  1019,
    1032,   578,  3242,  1523,  3533,   987,   579,  2582,  1022,  2964,
     590,  1398,  2678,   907,    58,  1951,   114,  2792,  3059,  2049,
      58,  1022,    58,  3195,  1032,   293,    58,  2965,  2114,    58,
    1924,  1084,    58,   293,   400,   941,  3244,  1935,  1990,  1011,
    3249,  1474,    58,  1889,  3419,   400,  2936,   403,  1101,  2389,
    1019,  1991,  1075,  3214,  1029,  3423,  1952,    58,  3576,  1465,
     400,   400,    58,  1215,   403,   403,   587,  2501,  1472,    58,
      58,    58,   923,  1431,  2544,  1170,  3096,  3096,  1177,  1317,
    3096,  2970,  1417,    58,  1016,  3132,  1424,  3473,  2264,  2854,
    1190,    54,  1190,   403,  1028,  1190,   403,  2616,  1190,    58,
    1210,  2087,   293,  2616,  1212,   924,    54, -2198,  1161,  2088,
    1466,  3229,  3270,  3367,  2449,   653,  3562,   293,  1254,   655,
     659,   293,    33,   155,  1980,    33,  1038,    33,  1336,   293,
    2799, -2198, -2198, -2198, -2198, -2198,  3191,  1981,  3194,   293,
    2193,  1985,   118,  2408,  1990,  3446,  2409,  2616,  1303,   293,
    2971,  1303,     4,  1992,  1942,  1923,  3152,  1991,  1162,   642,
     642,  2575,  2581,   293,  2995,  2616,   190,  2056,  2057,  2058,
    3311,  2210,  2990,  2627,   191,  1990,  1213,  2632,  3145,  3415,
     194,  2635,  3254,  3505,  2076,     1,  1524,  3397,  1991,     2,
    2854,  2653,  2655,    54,  2715,  1163,  2773,   366,  2931,  2972,
    1432,  1016,  1016,  1016,  1240,  3153,  1433,  1434,  1435,  2855,
    2856,  2932,  2934,  2974,  1337,  2977,   116,  2981,  1990,   917,
    1214,  2555,  2570,  2005,   367,  3068,  3116,  3131,  1436,  2247,
    3199,  1991,  2140,  2122,   232,  3206, -2198,  3587,   917,  1319,
    1943,  1407,   918,  3289,  2101,  3377,  1280,  3137,   277,  3140,
    2171,  3306,  3143,   239,  3312,  2111,  1944,  1338,  3314,  1992,
    1242,   918,  1483,  3417,  3453,  2857,  3454,  3514,  1994,  3520,
    3534,     3,   280,     5,  3550,  3284,  3566,   231,   956,   424,
    2128,  2639,  2640,  3320,  1995,  1326,  2395,   661,    10,  3596,
    1992,  2143,  1164,  3348,    43,  2363,  3096,  2364,  3435,  1945,
    2248,   255,  3096,  3096,    10,  3096,  3096,  3096,  3096,  3443,
    2855,  2856,  1408,   241,  3096,  1029,  3146,  2673,  3147,   248,
      63,  2673,  2700,  3321,  2996,  3447,  2094,    54,  1019,  2014,
      54,    58,    54,  1992,  1437,  2526,   249,  1438,  1946, -2198,
      43,  2432,  3349,  1013,  2527,  1439,  1006,    58,    33,  1961,
    1019,  3445, -2198,     7,     1,   286,  2718,    33,     2,  2876,
    1027,   167,    33,  3311,  3311,  3420,  2857,  1947,  2528,  1165,
     251,  2529,  2251,   168,  1994,  2228,  1948,   107,  3304,  1106,
    1440,    33,     8,  1525,  2176,  2499,   156,   187,  2530,    58,
    1995,  3069,  2858,   957,  1155,   322,    33,  1215,  1020,  3073,
    2534,  2365,   252,  1993,  2366,  1994,   107,    58,    58,    58,
    1166,    58,  2952,    58,    58,  1441,  1526,  1355,    76,    58,
      58,  1995,   106,   107,  3096,    77,  2171,  3096,  3096,  3096,
    3096,  1053,  1054,     4,  1442,  1443,   666,  2414,  2363,  1356,
    2364,  2070,  2211,  1990,   921,  1444,   256,   289,  1994,  3418,
    1445,   187,  1496,  2212,    58,    53,  1991,    33,  2859,   290,
     291,   330,   109,  1507,  1995,   335,    58,   292,   257,    33,
     187,  1515,    78,    79,  2213, -2198,  1167,  1216,  1217,  1218,
      80,  2214,   258,  1103, -2198,   323, -2198,  2252,  1219,  1446,
      58,    58,  2531,  2858,   259,  1099,  3421, -2198, -2198, -2198,
      58, -2198,   958,  1987,  3285,    37,  1989,    33,  2860,  2861,
     520,  3096,  2953,  3055,    33,   174,    58,    58,  2229,  3096,
     528,  1447,  1370,  1371,  1372,  1508, -2198,    33,  1870,  2050,
      33,    33,  2119,  2120,  3034,  3343,    33,  2230,  2231,   175,
    3057,    33,  1926,  2826,  2365,  2532,  2828,  2366,  1280,  1280,
    2954,  3504,  2533,    54,     5,  3510,  1280,  2232,  1992,  2859,
    2176,  2336,    54,   260,   501,  1001,  1960,  1028,  2164,  2171,
    2165,  2166,  2167,   261,  1966,   463,   464,   465,   466,   467,
     468,   469,   262,   176,  2621,  3335,  1028,   263,  3340,   421,
     411,  3342,   177,   507,   508,   412,  2253,   414,  1089,   470,
     187,    54,   264,     6,   187, -2198,   265,  1096, -2198,  2860,
    2861,    26,    27,  -278,  2955,  2933,   106,   107,  2281,  2001,
    2024,   267,  3535,  2006,  2012,  2006,  2015,  3185,  2956,    33,
   -2198,  2646,  2647,  2648,     7,  2018,  2020,  2021, -2198,   309,
      58,  2025,  2027,  2028,  1029,  2625,  1043,  1029,  2629,  2035,
    2038,  1019,  1193,  2413,   949,  1196,   950,  1175,   310,  1390,
    1019,  1181,    54,     8,  2925,  1185,  1391,  1061,  1010,   311,
      33,  1029,    58,  1994,    58,    58,    58,   178,   179,  2171,
    1070,  2752,   312,    58,    58,  1019,   313,    58,   403,  1995,
     403,    58,   471,   472,   473,   474,   475,   476,  2034,  -278,
     314,  2081,  2239,  2176,   371,    33,    58,  2787,  1059,    33,
     477,   478,   479,  3541,   321,  -278,   380,  3581,  2498,    54,
     344,  2375,  1068,  1018,  2435,    33,  1073,  2805,  2511,  2957,
    3554,    33,    54,  3536,    81,    54,    54,  3537,  1087,   348,
    3002,    54,  2255,   409,   410,  2958,    54,    33,  2255,  1287,
      58,    58,  2228,    58,  2277,  2278,  2279,  2280,  -278,  1194,
      82,  1366,  1197,  2346, -2198,  1200,  3426,   358,  3429,  3430,
    3431,  3432, -2198,  1027,  2171,    33,   434,  2117,  3541,   403,
     403, -2198,   632,  1380,   403,   349,    58,  1500,  2126,  2127,
     372,  3455,  2404,   187,  1355,  3554,  1229,  -278,   411,   351,
   -2198, -2198,   381,   412,   413,   414,   373,  1230,  1494,   353,
      33,    58,  3192,  2176,   106,   107,  1356,  2250,   382,    33,
   -2198,  1235,  1236,  1377, -1588,  2649,  -278,   357,  3536, -2198,
      83,  2211,  3537,  1112,    54,  -278,  3247,  1937,  2357,  1938,
     360,  2168,  2212,    33,  2169,   364,  2170,  3496,  3497,   374,
     480,  1149,  1026,   481,   187,  2019,  1927,    33,  1231,  2379,
     369,   383,   435,  2213,  2058,  1042,  2171,  2665,  1969,  1970,
    2214,  2022,  1232,    33,  3552,  2978,  2172,  1501,   436,  2401,
    2679,    33,  2680, -2198,  2026,   370,    33, -2198,   375,   379,
    1483,  2691,  2158,  2159,  1062,  2229,  2243,  2173,  2244,   388,
     384,  3136,  3136,   389,  3136,  3041,  3015,  3136,  2176,  2421,
    1079,  1080,  3012,   395,  2230,  2231,  1086,   376,   398,  1088,
    2174,   437,    84,   399,  2175,   187,   377,  1115,  1942,   385,
    2658,  3558,    33,  3560,  2232,  1116,  2443, -2198,   386,   429,
   -2198, -2198,  1928,  2661,  1117,    33,   431,  1118,  3224,   432,
    1003,  1004,  1005,  1007,  1477,  1478,  1479,  1480,  1929,   453,
     438,  1233,  3592, -2198,    33,  2164,   513,  2165,  2166,  2167,
    2560,  1040,   502,   482,  1046,  1046,   315,   316,   317,   318,
     319,  1971,  1972,  1973,  1974,  1975,  1976,   443,   483,   439,
    1119,  2051,   484,  2051,  1351,  1352,   446,  1120,   440,  3054,
    2176,  1930,    85,   447,  2144,   107,   515,  1064,  2223,  2224,
      86,  2376,  2377,  1069,  1943,  1071,  2444,  1216,  1217,  1078,
    3567,  3568,  1078,  1455,  1456,  1078,   449,  1459,  1460,   485,
    1944,  2948,  2949,  1287,  3020,  1091,  3293,  3294,   450,   451,
    1931,  2573,  3028,  3029,  2576,  2577,  2578,  2579,   452,  1016,
    1091,   517,   522,  3353,  1121,  1140,  2561,   486,   524,   525,
     529,   530,  1007,  1153,  1156,   531,  2674,   534,  1171,  1932,
     535,  1046,  2562,  1945, -2198,   487,  1183,   546,  1933,  1122,
     545,  1205,   547,   550,  2040,   555,  1123,   565,  1124,   566,
    2911,   576,  1207,  2045,   571,   577,   581,  2236,  1125,   588,
     595,   598,   599,   600,  3295,  2912,  2913,   603,   628,   631,
    2711,   637,  1946,   638,  2914,  2563,  2667, -2198,  2067, -2198,
   -2198, -2198,   643,   645,   646,   647,  1126,   648,  2388,  3354,
    2681,  2682,  2058,  2685,  1127,   649,   650,   651,  1190,   403,
     403,  1947,   657,   667,     1,    58,    58,   922,  2915,   927,
    1948,  2706,  1112,  2282,  2564,   929,   488,  2916,  1149,  2746,
     930,  1016,   931,   936,  2287,  2195,  1019,   946,  1019,  1019,
     947,  1128,  1019,  2204,   948,  2204,   955,  1019,  1149,  1016,
     960,   962,   983,  2565,   964,   965,  2917,   985,   966,   990,
    3136,  3355,  2566,  3356,  2968,   991,  1129,   993,   994,   995,
     997,    58,   998,   999,  1000, -2198,  1002,  1182,  2982,  3357,
    2743,  1244,  2240,  1245,  1246,  1247,  1248,  3358,  1249,  1250,
    1251,  3359,   489,  2468,  1252,  1253,  1256,  1257,  1281,  1255,
    1319,  2918,  1258,  1130,  1967,  1968,  1969,  1970,  2168,  1259,
    1029,  2169,  1280,  2170,  1131,  1293,  3360,  1260,  1280,  1280,
    1019,  1300,  1301,  1302,  1280,  1280,  1280,  1280,  1305,  1306,
    2456,  2458,  1308,  2171,  1318,  1029,  1309, -2198,  1324, -2198,
    1310,  1353,  1311,  2172,  1312,  2919,  1313,  1314,  1322,  3260,
    1348,  2400,  1360,  1323,  1325, -2198,  1329,  2001,  1354,   107,
    1363,  1357,  2006, -2198,  2465,  1362,  1367, -2198,  2012,   642,
    1373,  2006,  1384,  1364,  2801,  1388,  2802,  1365, -2198,  1389,
    1392,  1287,  1393,  1205,  1401,  1395,  1400,  2174,    58,  1396,
    3427,  2175, -2198,  1403,  1207,  1412,  3427,  1414,  2344,  3436,
    3437,  3438,  3439,  1419,  2348,  1462,  1452,  1463,  3262,  1467,
    1378,  1263,  1132,  1133,  1134,   272,  1264,  1265,    33,  1971,
    1972,  1973,  1974,  1975,  1976,  1135,  1490,  1491,  1492,  1499,
    1502,  2830,  2373,  1493,  1503,  1497,  1512,  1514,  1850,  1359,
    1019,  1851,  2383,  2384,   572,   403,  2842,  1858,  1862,  1852,
    1853,  1865,  1406,  1866,  1868,  1867,  1914,  2866,  1925,    58,
   -2198,  1936,  1978, -2198,  1922, -2198,  1953,  2176,  1983,  1954,
    1426,  1426,  1426,  1955,  1426,  2004,  1426,  1426,  2411,  2017,
      58,  1956,    63,    63,  1957, -2198,  1958,  1959,  2042,  2043,
    1112,  1112,  2041,  2046,  2047, -2198,  1266,  2075,  2048,  2061,
    2068,    58,  2077,  2436,  1515,  1474,  1280,  2082,  2079,  1029,
      58,  2092,  2104,  2093,  2666,  2105, -2198,  1156,  3512,  2109,
    2107,  3515,  3516,  3517,  3518,   403,   403,  2121,  1136,  1510,
    2118,  2984,  3354,  2123,  2989,  3388,  2132,  2146,  2147, -2198,
     403,  2139,  1205, -2198,  3396,    58,    58,    58,  3309,  3310,
    1016,    58,  2141,  1207,  1378,  1860,  1016,  2149,  3401,  1019,
    2183,  2185,  2186,  1863,  2194,  1292,  2188,  2237,  1294,  3217,
    1295,  1296,  1297,  1298,  1299,  2241,  1016,    58,  3444,  1871,
    1871,  2242,  2289,  3238,  2247,  2550,  2550,  2302,  2261,  2550,
    2269,  2245,  2283,  1144,  3355,   184,  3356,  2290,  2291,  2294,
    1281,  1281,  2295,  1280,  2443,  3571,  2296,  2299,  1281,  2328,
    2330,  1280,  3357,  2331,  1280,  1280,  1280,  1280,  2580, -2198,
    3358,  1019,  2332,  1028,  3359,  2585,  1280,  2333,  2334,  2603,
    3157,  3158,  3159,  1287,  3161,  3162,  3163,  3164,  3165,  3166,
    2335,  2337,  2338,  3169,  2339,  2341,  2617,  2617,  2617,  3360,
    2350,  2617,  1280,  2631,  2353,  2352,  2001,  3307,  3308,  3309,
    3310,  1971,  1972,  1973,  1974,  1975,  1976,  2354,  2355,  2199,
    2358,  2200,  2201,  2356,  2361,  2203,  2360,  2374,  2362,  2359,
    2208,  1859,  2390,  2392,  2393,  2656,  2399,  2657,  2659,  2397,
    2660,  2662,  2035,  2402,    58, -2198,  2406,  2407,  2668,  3490,
    2412,  2415,  2006,  2416,  2419,  2425,  2006,    58,  2433,    58,
    2439,  1219,  2496,  2449,  2497,  1019,  2617,  2508,    58,  2373,
    3148,  2451,  2696,  2696,  2523,  2514,  2522,  2537,  3103,  3103,
    3103,  3103,  2539,  3495,  2540,    63,  2558,    63,  1156,  1078,
    2547,  2559,  2571,  2572,  2710,  2951,  2062,  1091,  2584,  2600,
    1156,  2605,  2607,  2268,  2073,    58,  2608,  2664,  1205,    58,
    2609,  2613,  2636,  3542,  3543,  3544,  3545,  3546,  3547,  1207,
    2671,  2637,  1971,  1972,  1973,  1974,  1975,  1976,  2638,  2641,
    2687,  2642,  2643,  2644,    58,  2645,  2707,  2709,  2676,  2705,
    2712,  2708,  2721,  2720,  2723,  2724,  2726,  2727,  2744,  2728,
    2725, -2198,  2745,  3564,  2747,  1920,  1464,  1218,  2753,  2751,
    2758,  2760,  2769,  2098,  1140,  2774,    63,  2770,  1016,  1016,
    2786,  2771,  2778,  2779,  2303,  2788,  2803,  2810,  2815,  1267,
    2823,  2824,  2827,  2829,  2844,  2831,  2832,  3390,  2839,  2833,
    2845,  2870,  2834,  2928,  2304,  2305,  2306,  2867,  2927,  2124,
    2929,  3252,  2937,  2940,  2966,  2941,  1019,  2944,  2946,  2969,
    1268,  2947,  2967,  1269,  2979,  2980,  2983,  2985, -2162,  2986,
    2993,  2617,  2997,  2380,  2151,  3559,  1270,  3004,  3001,  2790,
    2204,  1280,  3347,  2307,  3268,  3016,  3019,  3027,   915,  3037,
    3095,  3095,  3095,  3095,  2617,  2308,  1019,  3049,  3060,  3069,
      58,  2550,  3076,  3061,  1962,  3117,  2309, -2198,  3125,  3126,
    3124,  3149,  3138,  3127,  3129,  1951,  1271,  3141,  3151,  3160,
    3050,  3039,  3052,  2310,  3174,  3156,  3167,  3168,  1272,  3175,
    3178,  1280,  3179,  2311,  3180,  3181,  3182,  3183,  3184,  1019,
    3616,  1019,  3189,   915,  1280,  2954,  1280,  3196,  2312,  3197,
    3201,  3203,  3207,  3208,  3212,  3233,  3239,  1280,  3241,  3240,
    3242,  3018,  2617,    58,  2603, -2198,   642,  3256,  3258,  1273,
    3265,  3261,  3273,  2617,   642,   642,  1213,  3276,  3286,  3280,
    3305,  3296,  3297,  3298,  3299,  3315,  3300,  3316,  3301,  3475,
    3326,  2006,  2518,  3302,  3329,  3351,  2313,  2925,  3369,  3370,
    3333,  3373,   184,  3371,  3344,  3374,  2866,  3375,  1274,  2012,
    3376,  2006,  3103,  3103,  3380,  3382,  3103,  3383,  3389,  3393,
    1275,    58,  3395,  3399,  3400,  3402,  2314,  3403,  2344,  1149,
    3404,  3406,  1276,  1277,  3408,    58,  2315, -2198, -2198,  3412,
    1278,  1963,  3422,  1279,  3424,  3441,  3433,  3456,  3468,  3466,
    3467,   293,  3469,  3471,  2268,  3470,  3476,  2316,  3488,  3494,
    2373,  2317,  3003,  3501,  3005,  2617,  1019,  3511,  3521,  3548,
    3570,  3489,  3339,  3532,  3561,  3339,  3572,  3585,  3573,  3574,
      58,  3575,    58,  3024,    58,  3602,  3391,  3606,  1430,  2318,
    3607,  2975,  3604,  3023,  3605,  3615,  3584,    58,  2319,  3328,
    1315,  2736,  2131,    49,  1280,  2424,    50,   822,  2692,  3000,
    2701,  3251,   526,   193,   521,   403,   198,   403,  3413,   992,
    2284,  3253,   343,   527,  2285,   660,   354,    58,    58,   346,
     926,  1939,   954,  1280,   933,   554,   552,  3582,   932,  2347,
    2548,  1307,  1287,  1169,   584,  2617,  2556,  2683,  2067,  2385,
    2157,  3094,  3094,  3094,  3094,  2617,  2617,  2161,  3275,  3048,
    2750,  1918,  2448,  3603,  2688,  2466,  2072,    58,  3398,    46,
     130,    60,  3119,  3364,  3095,  3095,    61,    47,  3095,  2431,
    2434,  1243,  1085,   512,  2182,  1328,  2438,  3246,  1856,  2099,
    3352,  3457,  1110,  2063,  3588,  2097,  3043,  2053,  1205,  3465,
    2112,  1280,  1280,  3188,  2403,  3187,   604,  3170,  2181,  1207,
    2923,  3235,  1280,  1280,  3386,  1280,  3384,  3381,  1280,  2677,
    1280,  2298,  3218,  2329,  1280,  2633,  2780,  3591,  3346,  2809,
    2250,  3522,  3103,  3190,  3338,  3472,  3213,  3338,  3103,  3103,
    3134,  3103,  3103,  3103,  3103,  2583,  2517,  3133,  2838,  3341,
    3103,  3523,   184,  2939,  3209,  3368,  2587,  2198,    42,  3379,
    2924,  3611,  2877,    58,  2222,  1261,  1262,  1263,  1906,  3379,
     642,   272,  1264,  1265,    33,  2878,    58,  3292,  3075,  3509,
    3345,  2263,  1431,  2262,  2190,  2617,  3193,  2617,  3503,  2775,
    1873,  3291,  2155,  3425,  1281,  3442,  3434,  3009,  2071,  2663,
    1281,  1281,   668,     0,     0,     0,  1281,  1281,  1281,  1281,
       0,  1019,     0,  3524,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  3215,  3216,     0,    58,     0,     0,  2808,
    2668,     0,     0,  2006,     0,  3551,     0,     0,     0,     0,
      58,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    2696,     0,  1266,  3248,  2696,     0,     0,  1016,   403,     0,
    3103,     0,     0,  3103,  3103,  3103,  3103,     0,   403,     0,
      58,     0,  2268,     0,  2268,     0,     0,     0,     0,    58,
       0,  1156,     0,     0,     0,     0,  3339,     0,     0,     0,
       0,     0,     0,     0,  3095,  3387,     0,     0,     0,     0,
    3095,  3095,     0,  3095,  3095,  3095,  3095,     0,     0,  1432,
       0,     0,  3095,     0,     0,  1433,  1434,  1435,  3277,     0,
       0,     0,  3509,     0,  2617,     0,     0,     0,     0,  3450,
       0,     0,  3600,  2790,     0,  3094,  3094,  1436,     0,  3094,
       0,     0,     0,  1878,     0,     0,     0,  3103,     0,     0,
    3303,     0,  2396,  1046,     0,  3103,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    58,  2617,  1156,  2195,     0,  2218,  2219,     0,  1028,
       0,     0,     0,  2235,     0,     0,     0,  1019,  1281,     0,
       0,     0,     0,     0,   156,  1029,     0,     0,  1029,  2380,
       0,  1280,     0,  1140,  1280,     0,  1280,     0,  2617,     0,
       0,     0,     0,     0,     0,     0,     0,   470,     0,     0,
       0,     0,  3095,     0,     0,  3095,  3095,  3095,  3095,     0,
       0,    58,     0,     0,     0,     0,     0,     0,  1156,  2500,
    1156,     0,     0,  1437,  1007,  1879,  1438,     0,  3338,     0,
       0,     0,     0,  1880,  1439,     0,     0,     0,     0,  1881,
       0,  1882,     0,     0,     0,     0,     0,     0,     0,  1280,
    2542,     0,  1883,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  2588,     0,  1281,     0,     0,  3500,  1440,
     403,     0,     0,  1281,    58,     0,  1281,  1281,  1281,  1281,
    1884,     0,     0,     0,     0,     0,     0,     0,  1281,  3095,
     471,   472,   473,   474,   475,   476,  1885,  3095,     0,     0,
       0,  1886,     0,     0,  1441,     0,     0,     0,   477,   478,
     479,     0,     0,  1887,  1281,     0,     0,    58,     0,     0,
    1888,     0,  1280,  1442,  1443,  2617,     0,     0,     0,     0,
       0,     0,     0,  1029,  1444,  3094,     0,     0,     0,  1445,
       0,  3094,  3094,     0,  3094,  3094,  3094,  3094,     0,   184,
    2617,     0,  2617,  3094,     0,  1280,     0,     0,     0,     0,
    2405,     0,     0,     0,     0,  1267,     0,  1156,   187,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1446,     0,
    1156,     0,  1156,     0,     0,     0,     0,     0,    58,     0,
       0,  1156,     0,    58,     0,    58,  1268,     0,     0,  2589,
    2446,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1447,  2590,  1270,  2617,     0,     0,     0,   642,   469,     0,
       0,     0,     0,     0,  3211,     0,    58,     0,  2716,     0,
       0,     0,  2719,     0,     0,     0,   470,     0,     0,  1951,
       0,     0,     0,    58,     0,     0,     0,     0,   480,     0,
       0,   481,  1271,  3277,     0,     0,     0,  2741,     0,  1280,
       0,     0,     0,  3094,  1272,     0,  3094,  3094,  3094,  3094,
    3519,     0,     0,     0,  1889,     0,     0,     0,     0,     0,
       0,  1890,     0,  2195,     0,     0,     0,     0,     0,  1029,
       0,     0,     0,  1280,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1891,     0,  1273,     0,     0,  1892,     0,
       0,     0,     0,     0,    58,    58,    58,    58,    58,    58,
       0,     0,     0,     0,     0,     0,  3553,     0,     0,   471,
     472,   473,   474,   475,   476,     0,     0,     0,     0,     0,
       0,     0,     0,  1281,  1274,     0,     0,   477,   478,   479,
    3094,     0,     0,     0,     0,     0,  1275,     0,  3094,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1276,  1277,
       0,   482,     0,  2811,     0,     0,  1278,     0,     0,  1279,
       0,     0,     0,     0,     0,     0,   483,   293,     0,     0,
     484,     0,     0,  1281,     0,     0,     0,     0,     0,     0,
    2268,     0,  1280,     0,  3593,     0,  1281,     0,  1281,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1281,
       0,     0,     0,     0,     0,     0,     0,   485,     0,     0,
       0,     0,     0,     0,     0,     0,  1156,     0,     0,     0,
       0,  3609,  3610,  3593,     0,     0,     0,     0,     0,     0,
      58,     0,  3617,     0,     0,   486,     0,     0,     0,     0,
     269,  2732,  2733,     0,     0,     0,     0,     0,  1281,   270,
     271,     0,  2742,   487,     0,   272,   273,   274,    33,     0,
       0,     0,     0,     0,     0,     0,     0,   480,     0,     0,
     481,     0,     0,     0,  1156,     0,  2754,  2755,  2756,  2757,
       0,     0,     0,     0,  2762,  2763,  2764,  2765,  1156,     0,
       0,  2767,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  2469,  2470,  2471,  2472,  2473,
    2474,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   161,     0,  3021,   488,  1040,   275,  3025,     0,     0,
       0,     0,     0,   162,     0,     0,  1281,     0,     0,     0,
    3036,     0,     0,     0,     0,   187,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  2813,
    2814,   163,     0,     0,     0,  1281,  2818,  2819,     0,     0,
    3056,  3058,     0,     0,     0,     0,     0,     0,     0,     0,
     482,     0,     0,  1281,  1281,  1281,  1281,     0,     0,  2475,
     489,     0,     0,     0,     0,   483,     0,     0,     0,   484,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    3118,   456,     0,   457,   458,   459,   460,   461,   462,   463,
     464,   465,   466,   467,   468,   469,     0,     0,     0,     0,
       0,     0,     0,  1281,  1281,     0,   485,     0,     0,     0,
       0,     0,     0,   470,  1281,  1281,     0,  1281,     0,     0,
    1281,     0,  1281,    54,     0,   164,  1281,     0,     0,     0,
       0,     0,     0,     0,   486,     0,     0,     0,     0,     0,
       0,  1046,  1046,  1046,     0,  1046,  1046,  1046,  1046,  1046,
    1046,     0,   487,     0,  1046,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   158,   159,     0,     0,
       0,     0,     0,     0,   160,    33,  3171,  2991,  2992,     0,
       0,     0,     0,     0,     0,     0,  2999,     0,     0,  3186,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   471,   472,   473,   474,
     475,   476,     0,     0,     0,     0,     0,     0,  3030,  3031,
       0,     0,   165,     0,   477,   478,   479,   276,     0,     0,
       0,     0,     0,   488,     0,     0,     0,     0,     0,  1156,
       0,     0,     0,  3051,     0,  3053,     0,     0,   161,     0,
       0,     0,     0,  1156,     0,     0,     0,   166,   269,     0,
     162,     0,     0,     0,     0,   187,     0,   270,   271,     0,
       0,     0,     0,   272,   273,   274,    33,     0,     0,     0,
       0,  1205,     0,  1140,     0,     0,     0,     0,   163,     0,
       0,   167,  1207,     0,     0,     0,  2476,     0,     0,   489,
    3120,  3121,     0,   168,  3122,  3123,     0,     0,     0,  2477,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   277,     0,     0,     0,     0,   278,     0,     0,   279,
       0,     0,     0,     0,     0,     0,     0,  1281,  1281,     0,
     169,  1281,     0,     0,     0,   280,     0,     0,     0,   161,
       0,     0,     0,     0,   275,   170,     0,     0,     0,     0,
     281,   162,     0,   282,   480,     0,   283,   481,     0,     0,
       0,     0,  2478,     0,     0,   284,   172,     0,  2479,     0,
      54,     0,   164,     0,  1140,     0,     0,     0,     0,   163,
       0,     0,     0,     0,  3177,     0,     0,  1281,     0,     0,
    1281,     0,     0,  1281,     0,     0,  1281,     0,  1281,     0,
       0,     0,     0,     0,     0,  1374,   285,  2480,     0,     0,
     173,     0,     0,     0,     0,     0,     0,     0,   286,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   287,
       0,  2481,     0,     0,  3171,   174,     0,     0,     0,     0,
       0,  2482,  2483,     0,     0,     0,     0,  2484,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  2485,     0,   288,
       0,  1281,     0,     0,     0,     0,     0,     0,  3245,   165,
       0,    54,  3250,   164,     0,     0,     0,   482,     0,  2486,
       0,     0,  2487,  2488,     0,     0,     0,  2489,  3255,     0,
       0,     0,   483,     0,     0,     0,   484,  1156,     0,     0,
       0,     0,     0,   176,   166,     0,     0,  3266,     0,     0,
     289,     0,   177,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   290,   291,     0,     0,     0,     0,     0,     0,
     292,     0,     0,   485,  1281,     0,     0,     0,   167,     0,
    1140,   293,     0,     0,  2490,     0,     0,  1281,     0,     0,
     168,     0,     0,  1281,  1281,  2491,  1281,  1281,  1281,  1281,
       0,   486,     0,     0,     0,  1281,     0,  1281,     0,     0,
     165,     0,     0,     0,     0,   276,     0,     0,     0,   487,
       0,     0,  1281,     0,     0,     0,     0,   169,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   178,   179,     0,
       0,     0,   170,     0,   269,   166,     0,     0,     0,     0,
     171,  3171,     0,   270,   271,     0,  3460,     0,  3462,   272,
     273,   274,    33,   172,     0,     0,   269,     0,     0,     0,
       0,     0,     0,     0,     0,   270,   271,     0,     0,   167,
       0,   272,   273,   274,    33,     0,     0,     0,     0,  1156,
       0,   168,     0,     0,     0,  1205,     0,     0,     0,     0,
     488,     0,     0,     0,     0,     0,  1207,   173,     0,   277,
       0,  1281,   187,     0,   278,  1281,     0,   279,  1281,  1281,
    1281,  1281,     0,     0,     0,     0,     0,     0,   169,     0,
       0,     0,   174,   280,     0,   161,     0,     0,     0,     0,
     275,  1281,     0,   170,     0,  1281,     0,   162,   281,     0,
       0,   282,     0,     0,   283,     0,   175,   161,     0,     0,
       0,     0,   275,   284,   172,     0,   489,     0,     0,   162,
       0,     0,     0,     0,     0,   163,     0,  1426,  1426,  1426,
    1426,  1426,  1426,  3411,     0,     0,  3414,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   163,     0,     0,
     176,     0,  1281,     0,   285,     0,     0,     0,   173,   177,
    1281,     0,     0,     0,     0,     0,   286,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   287,     0,  2684,
       0,     0,     0,   174,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1281,     0,     0,   288,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    54,  2587,   164,
       0,     0,     0,     0,     0,     0,     0,  1261,  1262,  1263,
       0,     0,     0,   272,  1264,  1265,    33,     0,     0,    54,
       0,   164,     0,     0,   178,   179,     0,     0,     0,     0,
       0,   176,  1205,     0,     0,     0,     0,     0,   289,     0,
     177,     0,     0,  1207,     0,     0,     0,     0,     0,     0,
     290,   291,     0,     0,  3498,  1261,  1262,  1263,   292,     0,
       0,   272,  1264,  1265,    33,     0,     0,     0,     0,   293,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1266,     0,   165,     0,     0,     0,
       0,   276,  3525,  3526,     0,  3528,     0,  3530,  3531,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   165,     0,
       0,     0,     0,   276,     0,   178,   179,     0,     0,     0,
       0,   166,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1266,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   166,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   167,   467,   468,   469,     0,
       0,  3577,     0,  3578,     0,     0,     0,   168,     0,     0,
       0,     0,     0,     0,     0,     0,   470,   167,     0,     0,
       0,     0,     0,     0,     0,   277,     0,     0,     0,   168,
     278,     0,     0,   279,     0,     0,     0,  3590,     0,     0,
       0,     0,     0,     0,   169,     0,     0,   277,     0,   280,
       0,  1028,   278,  3597,  3598,   279,     0,  3599,     0,   170,
    3601,     0,     0,     0,   281,     0,   169,   282,     0,     0,
     283,   280,     0,     0,     0,     0,     0,     0,     0,   284,
     172,   170,     0,     0,     0,     0,   281,     0,     0,   282,
       0,     0,   283,     0,     0,     0,     0,     0,     0,  1028,
       0,   284,   172,     0,     0,     0,     0,     0,     0,   471,
     472,   473,   474,   475,   476,     0,     0,     0,     0,  3040,
     285,     0,     0,     0,   173,     0,     0,   477,   478,   479,
       0,     0,   286,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   285,   287,     0,     0,   173,     0,     0,   174,
       0,     0,     0,     0,   286,  2588,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   287,     0,     0,     0,     0,
       0,   174,     0,   288,  1527,  1528,  1529,  1530,  1531,  1532,
       0,  1533,  1534,  1535,     0,     0,     0,  1536,  1537,  1538,
    1539,  1540,  1541,     0,     0,   288,     0,     0,     0,     0,
       0,     0,  1542,  2588,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   176,     0,  1543,
       0,     0,     0,     0,   289,     0,   177,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   290,   291,     0,   176,
       0,     0,     0,     0,   292,     0,   289,     0,   177,     0,
       0,     0,     0,     0,     0,   293,     0,  1267,   290,   291,
       0,     0,     0,     0,     0,     0,   292,   480,     0,     0,
     481,     0,  1544,     0,     0,     0,     0,   293,     0,     0,
       0,  1545,     0,     0,     0,     0,     0,     0,  1268,     0,
       0,  2589,     0,     0,     0,     0,     0,     0,     0,  1546,
       0,  1547,     0,  2590,  1270,  1267,     0,     0,     0,  1548,
       0,   178,   179,     0,     0,     0,  1549,  1550,     0,     0,
    1551,  1552,  1553,  1554,     0,     0,  1555,  1556,     0,     0,
       0,     0,     0,   178,   179,     0,  1268,     0,     0,  2589,
       0,     0,     0,     0,  1271,     0,     0,     0,     0,     0,
       0,  2590,  1270,     0,     0,     0,  1272,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1557,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1558,     0,
     482,     0,  1271,     0,  1559,     0,     0,  1273,     0,     0,
    2154,  1560,     0,  1561,  1272,   483,     0,     0,  1562,   484,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1563,     0,  1274,     0,     0,     0,
       0,     0,     0,     0,     0,  1273,   485,     0,  1275,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1276,  1277,     0,     0,     0,     0,     0,     0,  1278,     0,
       0,  1279,  1564,     0,   486,     0,     0,     0,     0,   293,
       0,     0,     0,     0,  1274,  1565,     0,     0,     0,     0,
       0,  1566,   487,     0,     0,     0,  1275,     0,     0,     0,
    1567,  1568,     0,     0,     0,     0,     0,  1569,  1276,  1277,
    1570,  1571,     0,     0,     0,  1572,  1278,     0,     0,  1279,
       0,  1573,  1574,     0,     0,     0,     0,   293,  1575,  1576,
    1577,     0,     0,  1578,  1579,  1580,     0,     0,     0,  1581,
       0,     0,     0,  1582,     0,  1583,     0,     0,     0,   563,
       0,     0,  1584,  1585,  1586,  1587,     0,  1588,  1589,     0,
       0,     0,  1590,  1591,     0,  1592,  1593,  1594,  1595,  1596,
    1597,  1598,     0,   488,     0,     0,     0,  1599,  1600,  1601,
       0,  1602,  1603,     0,     0,     0,  1604,  1605,  1606,  1607,
    1608,  1609,  1610,  1611,     0,  1612,     0,     0,     0,  1613,
    1614,  1615,  1616,  1617,  1618,  1619,  1620,  1621,  1622,  1623,
    1624,  1625,  1626,  1627,  1628,  1629,  1630,  1631,  1632,  1633,
    1634,  1635,  1636,  1637,  1638,  1639,  1640,  1641,  1642,  1643,
    1644,  1645,  1646,  1647,  1648,  1649,     0,  1650,  1651,   489,
       0,  1652,  1653,  1654,  1655,  1656,  1657,  1658,  1659,  1660,
    1661,     0,  1662,  1663,  1664,  1665,  1666,  1667,  1668,  1669,
    1670,  1671,  1672,  1673,  1674,  1675,  1676,     0,     0,  1677,
    1678,  1679,  1680,  1681,  1682,  1683,  1684,  1685,     0,  1686,
    1687,  1688,  1689,     0,  1690,  1691,  1692,  1693,  1694,  1695,
    1696,  1697,  1698,  1699,  1700,  1701,  1702,  1703,  1704,  1705,
    1706,  1707,  1708,  1709,  1710,  1711,  1712,  1713,  1714,  1715,
    1716,  1717,  1718,  1719,  1720,  1721,  1722,  1723,  1724,  1725,
       0,  1726,  1727,  1728,  1729,  1730,  1731,     0,     0,  1732,
    1733,     0,  1734,  1735,  1736,  1737,  1738,  1739,  1740,  1741,
    1742,  1743,  1744,  1745,  1746,  1747,  1748,  1749,  1750,  1751,
    1752,  1753,  1754,  1755,  1756,  1757,  1758,  1759,     0,     0,
    1760,  1761,  1762,  1763,  1764,  1765,  1766,  1767,  1768,  1769,
    1770,  1771,  1772,  1773,  1774,  1775,  1776,  1777,  1778,  1779,
    1780,  1781,  1782,  1783,  1784,  1785,  1786,  1787,  1788,  1789,
    1790,  1791,  1792,  1793,  1794,  1795,  1796,  1797,  1798,  1799,
    1800,  1801,  1802,  1803,  1804,  1805,  1806,  1807,  1808,  1809,
    1810,  1811,  1812,  1813,  1814,  1815,  1816,  1817,  1818,  1819,
    1820,  1821,     0,     0,     0,     0,  1822,  1823,  1824,  1825,
    1826,  1827,  1828,  1829,  1830,  1831,  1832,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   132,  1833,     0,     0,
       0,     0,     0,     0,     0,  1834,     0,     0,     0,     0,
    1835,     0,     0,     0,  1836,     0,     0,  1837,  1838,  1839,
    1840,     0,     0,  1841,  1842,   132,  1843,  1844,  1845,  1527,
    1528,  1529,  1530,  1531,  1532,   133,  1533,  1534,  1535,     0,
       0,     0,  1536,  1537,  1538,  1539,  1540,  1541,     0,     0,
       0,     0,     0,     0,   134,   135,     0,  1542,     0,     0,
       0,     0,     0,     0,   133,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1543,     0,     0,     0,     0,     0,
       0,     0,     0,   134,   135,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   136,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   137,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   138,     0,     0,
       0,     0,     0,   136,     0,     0,     0,  1544,     0,     0,
       0,     0,     0,     0,   139,   137,  1545,     0,     0,     0,
       0,     0,     0,     0,   140,     0,   138,     0,     0,     0,
       0,     0,     0,     0,  1546,     0,  1547,     0,     0,   141,
       0,     0,     0,   139,  1548,     0,     0,     0,     0,     0,
       0,  1549,  1550,   140,     0,  1551,  1552,  1553,  1554,     0,
       0,  1555,  1556,     0,     0,     0,     0,     0,   141,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   142,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1557,   143,     0,     0,     0,     0,     0,   142,     0,
       0,     0,     0,     0,     0,     0,     0,   144,     0,     0,
       0,     0,     0,  1558,   145,     0,     0,   146,     0,  1559,
       0,   143,     0,     0,     0,     0,  1560,     0,  1561,     0,
       0,     0,     0,  1562,     0,     0,   144,     0,   147,     0,
       0,     0,   148,   145,     0,     0,   146,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1563,
       0,   149,     0,     0,     0,     0,     0,   147,     0,     0,
       0,   148,     0,     0,     0,     0,     0,     0,     0,   150,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     149,     0,     0,     0,     0,     0,     0,  1564,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   150,     0,
    1565,     0,     0,     0,     0,     0,  1566,     0,     0,     0,
       0,     0,     0,     0,     0,  1567,  1568,     0,     0,     0,
       0,     0,  1569,     0,     0,  1570,  1571,     0,     0,     0,
    1572,     0,     0,     0,     0,     0,  1573,  1574,     0,     0,
       0,     0,     0,  1575,  1576,  1577,     0,     0,  1578,  1579,
    1580,     0,     0,     0,  1581,     0,     0,     0,  1582,     0,
    1583,     0,     0,     0,     0,     0,     0,  1584,  1585,  1586,
    1587,     0,  1588,  1589,     0,     0,     0,  1590,  1591,     0,
    1592,  1593,  1594,  1595,  1596,  1597,  1598,     0,     0,     0,
       0,     0,  1599,  1600,  1601,     0,  1602,  1603,     0,     0,
       0,  1604,  1605,  1606,  1607,  1608,  1609,  1610,  1611,     0,
    1612,     0,     0,     0,  1613,  1614,  1615,  1616,  1617,  1618,
    1619,  1620,  1621,  1622,  1623,  1624,  1625,  1626,  1627,  1628,
    1629,  1630,  1631,  1632,  1633,  1634,  1635,  1636,  1637,  1638,
    1639,  1640,  1641,  1642,  1643,  1644,  1645,  1646,  1647,  1648,
    1649,     0,  1650,  1651,     0,     0,  1652,  1653,  1654,  1655,
    1656,  1657,  1658,  1659,  1660,  1661,     0,  1662,  1663,  1664,
    1665,  1666,  1667,  1668,  1669,  1670,  1671,  1672,  1673,  1674,
    1675,  1676,     0,     0,  1677,  1678,  1679,  1680,  1681,  1682,
    1683,  1684,  1685,     0,  1686,  1687,  1688,  1689,     0,  1690,
    1691,  1692,  1693,  1694,  1695,  1696,  1697,  1698,  1699,  1700,
    1701,  1702,  1703,  1704,  1705,  1706,  1707,  1708,  1709,  1710,
    1711,  1712,  1713,  1714,  1715,  1716,  1717,  1718,  1719,  1720,
    1721,  1722,  1723,  1724,  1725,     0,  1726,  1727,  1728,  1729,
    1730,  1731,     0,     0,  1732,  1733,     0,  1734,  1735,  1736,
    1737,  1738,  1739,  1740,  1741,  1742,  1743,  1744,  1745,  1746,
    1747,  1748,  1749,  1750,  1751,  1752,  1753,  1754,  1755,  1756,
    1757,  1758,  1759,     0,     0,  1760,  1761,  1762,  1763,  1764,
    1765,  1766,  1767,  1768,  1769,  1770,  1771,  1772,  1773,  1774,
    1775,  1776,  1777,  1778,  1779,  1780,  1781,  1782,  1783,  1784,
    1785,  1786,  1787,  1788,  1789,  1790,  1791,  1792,  1793,  1794,
    1795,  1796,  1797,  1798,  1799,  1800,  1801,  1802,  1803,  1804,
    1805,  1806,  1807,  1808,  1809,  1810,  1811,  1812,  1813,  1814,
    1815,  1816,  1817,  1818,  1819,  1820,  1821,     0,     0,     0,
       0,  1822,  1823,  1824,  1825,  1826,  1827,  1828,  1829,  1830,
    1831,  1832,     1,     0,     0,     0,     2,     0,   670,   671,
     672,     0,  1833,     0,     0,     0,   673,     0,     0,     0,
    1834,     0,     0,   674,   675,  1835,     0,     0,     0,  1836,
       0,     0,  1837,  1838,  1839,  1840,     0,     0,  1841,  1842,
       0,  1843,  1844,  1845,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   676,   677,     0,     0,     0,   678,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   679,
     680,     0,   681,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   682,     0,     0,     0,
       0,     0,     0,   683,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   684,     0,     0,   685,   686,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   687,     0,   688,   689,   690,     0,     0,     0,
       0,     0,     0,     0,   691,   692,     0,   693,   694,   695,
       0,     0,     0,     0,     0,   696,     0,     0,   697,     0,
     698,   699,   700,     0,     0,     0,     0,     0,   701,     0,
     702,   703,     0,   704,     0,   705,   706,     0,     0,   707,
       0,     0,   708,   709,   710,   711,   712,   713,     0,     0,
       0,   714,   715,   716,     0,   717,     0,     0,     0,   718,
       0,   719,   720,     0,     0,     0,     0,   721,     0,     0,
     722,     0,     0,   723,     0,   724,     0,   725,     0,   726,
       0,     0,     0,   727,   728,     0,   729,   730,   731,     0,
       0,   732,     0,   733,   734,     0,   735,     0,     0,     0,
       0,     0,     0,     0,   736,   737,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   738,     0,     0,
     739,   740,     0,     0,   741,   742,     0, -2199,   743,   744,
       0,     0,     0,     0,     0,     0,     0,   745,   746,   747,
       0,   748,     0, -2199,     0, -2199, -2199, -2199,     0,     0,
       0,   749,   750,   751,     0,   752,     0,     0,     0,   753,
     754,     0,     0,     0,   755,     0,     0,     0,     0,     0,
       0,     0,   756,     0,     0,     0,     0,     0,     0,     0,
     757,   758,   759,     0,     0,     0,     0,     0,   760,   761,
       0,     0,     0,     0,     0,     0,   762,     0,     0,   763,
       0,     0,     0,   764,   765,     0,     0, -2199,     0,     0,
       0,     0,     0,     0,   766,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   767,     0,     0,     0,     0, -2199,     0,     0,   768,
       0,     0,     0,     0,     0,   769,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   770,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    82,     0,
       0,     0,     0,     0,     0,   771,     0,   772,   773,     0,
       0,     0, -2199,     0,     0,   774,     0,     0,     0,     0,
       0,     0,     0,  2880,  2881,     0,  2882,  2883,  2884,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
   -2199,     0, -2199,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   775,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   776,     0, -2199,     0,     0,
       0,     0,   777,     0, -2199,     0, -2199,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0, -2199,     0,     0,
       0,     0, -2199,     0,     0,     0,   778,   779,     0,     0,
   -2199,   780,     0,     0, -2199,     0,     0,     0,     0,     0,
   -2199,     0,     0,   781, -2199, -2199, -2199, -2199,     0,   782,
     783,   784,   785,     0,     0,     0,   786,  2885,     0, -2199,
     787,     0,     0,     0,     0,  2886,     0,   788,   789,     0,
       0,     0,     0,     0,     0,     0, -2199,     0,   790, -2199,
     791, -2199,     0,     0,     0,     0,     0,     0, -2199,     0,
       0,   792,     0,   793,     0,     0,   794,     0,     0,  2887,
       0, -2199,   795,     0,     0,     0,     0,     0,  2888,     0,
       0, -2199,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   796,     0,
       0,   797, -2199, -2199,     0,     0,   798,  2889,  2890,   799,
     800,     0,     0,     0,     0,     0,     0, -2199,     0,     0,
       0,     0,     0,     0,   801, -2199,     0,     0,     0, -2199,
       0,   802,     0,     0,     0,     0,     0, -2199, -2199, -2199,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  2891,     0,   803,   804,   805,   806,   807,   808,
     809,     0,     0,   810,     0,   811,     0,   812,     0,     0,
       0,     0,     0,   592,   454,   455,   456,   813,   457,   458,
     459,   460,   461,   462,   463,   464,   465,   466,   467,   468,
     469,     0,     0,     0,     0,     0,  2892,     0,     0,     0,
       0,     0,     0,     0,     0, -2199,     0,     0,   470,     0,
       0,     0,  2717,   454,   455,   456, -2199,   457,   458,   459,
     460,   461,   462,   463,   464,   465,   466,   467,   468,   469,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   470,     0,     0,
       0,  2893,     0,     0,     0,     0, -2199,     0,     0,     0,
     454,   455,   456,     0,   457,   458,   459,   460,   461,   462,
     463,   464,   465,   466,   467,   468,   469,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   470,     0,     0,     0,     0,     0,
       0,   471,   472,   473,   474,   475,   476,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0, -2199,     0,   477,
     478,   479,   454,   455,   456,     0,   457,   458,   459,   460,
     461,   462,   463,   464,   465,   466,   467,   468,   469,     0,
     471,   472,   473,   474,   475,   476,     0,     0,     0,     0,
       0,     0,     0, -2199,     0,     0,   470,     0,   477,   478,
     479,   454,   455,   456,     0,   457,   458,   459,   460,   461,
     462,   463,   464,   465,   466,   467,   468,   469,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   471,   472,   473,
     474,   475,   476,     0,     0,   470,     0,     0,     0, -2199,
       0,     0,     0,     0,     0,   477,   478,   479,     0,     0,
       0,     0,     0, -2199, -2199, -2199, -2199, -2199, -2199, -2199,
       0, -2199, -2199,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0, -2199,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   471,
     472,   473,   474,   475,   476,     0,     0,     0,     0,   480,
       0,     0,   481,     0,     0,     0,     0,   477,   478,   479,
       0,     0,     0,     0,     0,     0,     0,  2894,  2895,  2896,
    2897,  2898,  2899,  2900,  2901,  2902,  2903,     0,   471,   472,
     473,   474,   475,   476,     0,     0,     0,     0,   480,     0,
       0,   481,     0,     0,     0,     0,   477,   478,   479,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   454,   455,   456,
       0,   457,   458,   459,   460,   461,   462,   463,   464,   465,
     466,   467,   468,   469,     0,   480,     0,     0,   481,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   470,   454,   455,   456,     0,   457,   458,   459,   460,
     461,   462,   463,   464,   465,   466,   467,   468,   469,     0,
       0,     0,   482,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   470,   483,     0,     0,
       0,   484,     0,     0,     0,     0,     0,   480,     0,     0,
     481,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   482,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   483,     0,   485,     0,
     484,     0,     0,     0,     0,     0,   480,     0,     0,   481,
       0,     0,     0,     0,   471,   472,   473,   474,   475,   476,
       0,     0,     0,     0,     0,     0,   486,     0,   482,     0,
       0,     0,   477,   478,   479,     0,     0,   485,     0,     0,
       0,     0,     0,   483,   487,     0,     0,   484,   580,   471,
     472,   473,   474,   475,   476,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   486,     0,   477,   478,   479,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   487,   485,     0,     0,     0,     0,     0,
     482,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   483,     0,     0,     0,   484,
     591,     0,   486,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   488,     0,     0,     0,   482,
     487,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   483,     0,   485,     0,   484,   601,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   488,     0,     0,     0,     0,     0,
       0,     0,   480,     0,   486,   481,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   485,     0,     0,     0,     0,
       0,   489,   487,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   480,     0,     0,
     481,   488,     0,   486,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     489,   487,     0,     0,     0,   454,   455,   456,     0,   457,
     458,   459,   460,   461,   462,   463,   464,   465,   466,   467,
     468,   469,     0,     0,     0,  1261,  1262,  1263,     0,     0,
       0,   272,  1264,  1265,    33,     0,     0,     0,     0,   470,
       0,     0,     0,   488,   454,   455,   456,   489,   457,   458,
     459,   460,   461,   462,   463,   464,   465,   466,   467,   468,
     469,     0,     0,     0,     0,   482,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   470,     0,
     483,     0,   488,     0,   484,   961,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     482,     0,     0,     0,     0,     0,     0,     0,     0,   489,
       0,     0,  1266,     0,     0,   483,     0,     0,     0,   484,
     967,   485,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   471,   472,   473,   474,   475,   476,     0,     0,
       0,     0,   272,  1264,  1265,    33,     0,     0,   489,   486,
     477,   478,   479,     0,     0,     0,   485,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   487,     0,     0,
       0,   471,   472,   473,   474,   475,   476,     0,     0,     0,
       0,     0,     0,     0,   486,     0,     0,     0,     0,   477,
     478,   479,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   487,     0,     0,     0,   454,   455,   456,     0,
     457,   458,   459,   460,   461,   462,   463,   464,   465,   466,
     467,   468,   469,  3080,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1028,
     470,     0,     0,     0,     0,   454,   455,   456,   488,   457,
     458,   459,   460,   461,   462,   463,   464,   465,   466,   467,
     468,   469,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   470,
       0,     0,     0,   488,     0,     0,     0,     0,     0,     0,
     480,     0,     0,   481,   454,   455,   456,     0,   457,   458,
     459,   460,   461,   462,   463,   464,   465,   466,   467,   468,
     469,     0,     0,     0,   489,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   470,   480,
       0,     0,   481,   471,   472,   473,   474,   475,   476,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   489,
    1028,   477,   478,   479,   454,   455,   456,     0,   457,   458,
     459,   460,   461,   462,   463,   464,   465,   466,   467,   468,
     469,     0,   471,   472,   473,   474,   475,   476,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   470,     0,
     477,   478,   479,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   482,     0,     0,     0,     0,     0,     0,
       0,   471,   472,   473,   474,   475,   476,     0,   483,     0,
       0,     0,   484,   968,     0,     0,     0,     0,     0,   477,
     478,   479,     0,     0,     0,  1267,     0,     0,     0,     0,
       0,     0,   482,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   483,     0,   485,
       0,   484,   969,     0,     0,     0,  1268,     0,     0,  1269,
       0,   471,   472,   473,   474,   475,   476,     0,     0,     0,
       0,   480,  1270,     0,   481,     0,     0,   486,     0,   477,
     478,   479,     0,     0,     0,     0,     0,     0,   485,     0,
       0,     0,     0,     0,     0,   487,     0,     0,     0,  1951,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     480,     0,  1271,   481,     0,     0,   486,     0,     0,     0,
       0,     0,     0,     0,  1272,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   487,     0,  1267,     0,     0,   454,
     455,   456,     0,   457,   458,   459,   460,   461,   462,   463,
     464,   465,   466,   467,   468,   469,     0,     0,     0,   480,
       0,     0,   481,     0,     0,  1273,     0,  3081,     0,     0,
    3082,     0,     0,   470,     0,     0,   488,     0,     0,     0,
       0,     0,     0,  3083,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   482,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1274,     0,     0,     0,     0,   483,
       0,     0,     0,   484,   970,   488,  1275,     0,     0,   480,
       0,     0,   481,  3085,     0,     0,     0,     0,  1276,  1277,
       0,     0,     0,   482,     0,  3086,  1278,     0,     0,  1279,
       0,     0,   489,     0,     0,     0,     0,   293,   483,     0,
     485,     0,   484,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   471,   472,   473,   474,
     475,   476,     0,     0,     0,     0,  3087,     0,   486,     0,
       0,   489,   482,     0,   477,   478,   479,     0,     0,   485,
       0,     0,     0,     0,     0,     0,   487,   483,     0,     0,
       0,   484,   972,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  3088,     0,   486,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  3089,     0,     0,
       0,     0,     0,     0,     0,   487,     0,     0,   485,  3090,
    3091,     0,   482,     0,     0,     0,     0,  3092,     0,     0,
    3093,   973,     0,     0,     0,     0,     0,   483,   293,     0,
       0,   484,     0,     0,     0,     0,   486,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   488,     0,     0,
       0,     0,   455,   456,   487,   457,   458,   459,   460,   461,
     462,   463,   464,   465,   466,   467,   468,   469,   485,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   976,     0,     0,     0,   470,   488,     0,     0,     0,
       0,     0,     0,     0,   480,     0,   486,   481,   457,   458,
     459,   460,   461,   462,   463,   464,   465,   466,   467,   468,
     469,     0,     0,   489,   487,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   470,     0,
       0,     0,     0,     0,     0,   488,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   489,     0,     0,     0,   458,   459,   460,   461,
     462,   463,   464,   465,   466,   467,   468,   469,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   471,   472,
     473,   474,   475,   476,     0,   470,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   488,   477,   478,   479,     0,
       0,   489,     0,     0,     0,   459,   460,   461,   462,   463,
     464,   465,   466,   467,   468,   469,     0,   482,     0,     0,
       0,   471,   472,   473,   474,   475,   476,     0,     0,     0,
       0,     0,   483,   470,     0,     0,   484,     0,     0,   477,
     478,   479,   464,   465,   466,   467,   468,   469,     0,   460,
     461,   462,   463,   464,   465,   466,   467,   468,   469,     0,
       0,   489,     0,     0,     0,   470,     0,     0,     0,     0,
       0,     0,     0,   485,     0,     0,   470,     0,   471,   472,
     473,   474,   475,   476,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   477,   478,   479,     0,
       0,   486,     0,     0,     0,     0,     0,   461,   462,   463,
     464,   465,   466,   467,   468,   469,     0,     0,     0,   487,
       0,     0,     0,     0,     0,     0,   471,   472,   473,   474,
     475,   476,     0,   470,     0,     0,   480,     0,     0,   481,
       0,     0,     0,     0,   477,   478,   479,     0,  1261,  1262,
    1263,     0,     0,     0,   272,  1264,  1265,    33,   471,   472,
     473,   474,   475,   476,     0,     0,     0,     0,     0,   471,
     472,   473,   474,   475,   476,     0,   477,   478,   479,   480,
       0,     0,   481,     0,     0,     0,     0,   477,   478,   479,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     488,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   462,   463,   464,   465,   466,   467,   468,
     469,     0,     0,     0,     0,     0,   471,   472,   473,   474,
     475,   476,     0,     0,     0,  1266,   480,     0,   470,   481,
       0,     0,     0,     0,   477,   478,   479,     0,   465,   466,
     467,   468,   469,     0,     0,     0,     0,     0,     0,   482,
       0,     0,     0,     0,     0,     0,   489,     0,     0,     0,
     470,     0,     0,     0,   483,     0,     0,     0,   484,     0,
       0,     0,     0,     0,   480,     0,     0,   481,     0,     0,
    1261,  1262,  1263,     0,     0,     0,   272,  1264,  1265,    33,
       0,     0,   482,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   485,   480,   483,     0,   481,
       0,   484,     0,     0,     0,     0,     0,   480,     0,     0,
     481,   471,   472,   473,   474,   475,   476,     0,     0,     0,
       0,     0,     0,   486,     0,     0,     0,     0,     0,   477,
     478,   479,     0,     0,     0,     0,     0,     0,   485,   482,
       0,   487,  1028,   471,   472,   473,   474,   475,   476,     0,
       0,     0,     0,     0,   483,     0,     0,  1266,   484,     0,
       0,   477,   478,   479,   480,     0,   486,   481,     0,     0,
    1261,  1262,  1263,     0,     0,     0,   272,  1264,  1265,    33,
       0,     0,     0,     0,   487,     0,     0,   482,     0,     0,
       0,  3078,  3079,     0,     0,   485,     0,   272,  1264,  1265,
      33,     0,   483,     0,     0,     0,   484,     0,   971,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   482,
       0,     0,   488,   486,     0,     0,     0,     0,     0,     0,
     482,     0,     0,     0,   483,     0,     0,     0,   484,     0,
       0,   487,     0,   485,     0,   483,     0,     0,     0,   484,
       0,     0,     0,     0,     0,     0,     0,  1266,     0,     0,
       0,     0,     0,     0,     0,   488,     0,     0,     0,   480,
       0,   486,   481,     0,     0,   485,     0,     0,  3080,     0,
       0,     0,     0,     0,  1028,     0,   485,   482,   489,   487,
       0,  3078,  3079,     0,     0,     0,     0,   272,  1264,  1265,
      33,   480,   483,   486,   481,     0,   484,     0,     0,     0,
       0,     0,     0,     0,   486,     0,     0,  3078,  3079,     0,
       0,   487,   488,   272,  1264,  1265,    33,     0,     0,     0,
       0,   489,   487,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   485,     0,     0,     0,     0,  1267,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     488,   486,     0,     0,     0,     0,     0,     0,  3080,  1268,
       0,     0,  1269,     0,  1028,     0,     0,     0,   489,   487,
       0,     0,   482,     0,     0,  1270,     0,     0,     0,     0,
       0,     0,   488,     0,  3080,  1028,     0,   483,     0,     0,
       0,   484,     0,   488,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   482,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  2440,  1271,   489,     0,     0,   483,
       0,     0,     0,   484,     0,     0,     0,  1272,   485,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   489,     0,
     488,     0,     0,     0,     0,     0,   486,     0,     0,   489,
     485,     0,     0,     0,     0,     0,     0,     0,  1273,     0,
    1267,     0,     0,     0,   487,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1028,     0,     0,   486,     0,
       0,     0,   199,     0,     0,   200,     0,     0,     0,     0,
       0,  1268,     0,     0,  1269,     0,   487,  1274,     0,     0,
       0,  1028,     0,     0,     0,     0,   489,  1270,     0,  1275,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1276,  1277,     0,     0,     0,     0,     0,     0,  1278,
       0,     0,  1279,     0,     0,     0,     0,     0,     0,     0,
     293,     0,     0,     0,     0,   488,  3506,  1271,     0,     0,
       0,     0,     0,     0,   201,     0,     0,     0,     0,  1272,
    1267,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     202,   203,     0,     0,     0,     0,     0,   488,     0,     0,
     204,  1267,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1268,     0,     0,  1269,     0,     0,     0,     0,     0,
    1273,     0,     0,     0,     0,     0,     0,  1270,     0,     0,
       0,   489,  3081,     0,     0,  3082,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  3083,     0,
       0,     0,  2469,  2470,  2471,  2472,  2473,  2474,     0,  1274,
       0,     0,     0,   489,     0,     0,     0,  1271,     0,     0,
       0,  1275,     0,     0,     0,     0,     0,     0,     0,  1272,
       0,     0,     0,  1276,  1277,     0,     0,  3084,  3085,     0,
       0,  1278,     0,     0,  1279,     0,     0,     0,     0,     0,
    3086,  1267,   293,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1273,     0,     0,     0,     0,     0,     0,  1267,     0,     0,
       0,     0,  3081,     0,     0,  3082,     0,     0,     0,     0,
       0,  3087,     0,     0,     0,     0,  2475,     0,  3083,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  3081,  1274,
       0,  3082,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1275,   205,     0,  3083,  1951,     0,     0,     0,     0,
    3088,     0,     0,  1276,  1277,     0,     0,     0,  3085,     0,
       0,  1278,  3089,     0,  1279,     0,     0,     0,     0,     0,
    3086,     0,   293,     0,  3090,  3091,     0,     0,     0,     0,
       0,   206,  3092,     0,  3085,  3093,     0,     0,     0,     0,
       0,     0,     0,   293,     0,     0,  3086,     0,     0,     0,
     207,   208,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  3087,     0,     0,     0,     0,     0,     0,   209,     0,
       0,  3477,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  3087,     0,     0,
     210,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    3088,     0,   211,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  3089,   212,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  3090,  3091,  3088,     0,  3478,     0,
     213,     0,  3092,     0,     0,  3093,     0,     0,  3089,     0,
     214,     0,     0,   293,     0,     0,     0,     0,     0,     0,
    3090,  3091,     0,  3479,     0,   215,     0,     0,  3092,     0,
       0,  3093,  3480,     0,     0,     0,     0,     0,     0,   293,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   216,     0,     0,     0,     0,
    3481,     0,     0,  2476,     0,     0,     0,     0,  3482,     0,
       0,     0,     0,     0,     0,     0,  2477,     0,   217,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   218,     0,     0,     0,     0,     0,     0,
     219,     0,     0,   220,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   221,     0,     0,     0,   222,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  2478,
       0,     0,     0,     0,     0,  2479,     0,   223,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    3483,     0,     0,     0,     0,   224,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  2480,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   225,  2481,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  2482,  2483,
       0,     0,     0,     0,  2484,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  2485,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  2486,     0,     0,  2487,
    2488,     0,     0,     0,  2489,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  2490,     0,     0,     0,     0,     0,     0,     0,     0,
    3484,     0,  2491
};

static const short yycheck[] =
{
       3,     4,     5,   171,   107,     8,   190,   392,   986,   259,
     260,  1044,   646,   127,  1029,  1114,    45,  1261,  1262,  1150,
    1338,   540,  1111,  2074,   784,    69,   782,  1125,   676,   677,
    1331,    54,  2153,   683,  1889,   589,  2246,    40,  2295,  1369,
    2427,  2568,  2795,  2796,  2797,  1855,  1856,  1121,  1122,    52,
    1124,    54,  1126,  1127,     5,   566,   742,   173,    20,   257,
     258,   631,    65,    92,    27,    27,   264,   715,   171,    72,
     718,  2827,   582,    76,   118,    27,    79,    80,  2011,     5,
     728,  2468,    85,    86,   732,     5,  1145,   190,   736,    25,
      27,    27,  1888,  2293,   706,   743,  1951,  2014,     5,    24,
     748,    26,   750,   106,    27,   149,     5,    24,   756,    26,
    1199,   759,   767,    26,    27,     5,     5,   767,   766,  2366,
     123,   235,   236,   126,   772,  1214,     5,  2005,   131,     5,
      25,   779,    27,   703,  1233,  1956,  1957,  1958,  1959,  2798,
    2184,  2582,   790,  2584,   714,   261,   794,   128,   129,   265,
     798,   267,   320,   269,   270,   271,   804,   141,     5,   807,
       6,    25,   278,    27,   103,    19,   282,   283,    27,     5,
    1203,    19,    26,     5,     5,    20,    24,    25,    26,   223,
      25,   225,    27,    27,   103,  2941,    25,  2943,    27,   192,
     802,    24,    25,    26,   707,    24,    25,    26,    27,   769,
       5,   771,     5,    24,    25,    26,    27,  2289,  2290,  2291,
     780,    53,  2294,    24,    25,    26,    27,   320,   731,   772,
       5,   324,  2196,    24,    25,    26,    27,    45,    27,   232,
      25,    26,    27,   122,   123,   238,     5,    24,    25,    26,
      27,     5,    23,    20,     5,     5,   383,   250,    25,    27,
      27,   179,     5,   256,   257,   258,   259,   260,    25,    27,
      27,   264,   109,   776,   111,  1280,   113,    25,    27,    27,
      25,     5,    27,   786,    92,    27,   789,  2359,    27,  2878,
     793,   211,     5,  1028,   126,   127,   799,     5,   801,   316,
      25,     5,    27,     5,   132,   434,  2588,   341,  2590,    27,
     383,   345,    86,    87,    88,    89,    90,  2464,   278,   192,
     313,   314,     5,   429,  2524,   279,   432,  2368,   192,   232,
     323,  1132,  1133,  2510,  2229,    23,     5,  2232,     5,   513,
     864,   277,  2589,   449,   450,   451,   452,   232,   454,   455,
     456,   457,   458,   459,   460,   461,   462,   463,   464,   465,
     466,   467,   468,   469,   470,   399,   676,   677,   388,     5,
       5,   681,   682,     5,   446,   481,   482,     6,   232,     6,
     486,  3127,   488,  3129,   572,   695,   432,   472,    18,    19,
      20,    21,    22,   710,   711,   712,  1419,   503,   504,   505,
     506,   589,   337,     5,   510,   715,     5,     5,   718,   375,
       5,     5,   663,   232,   724,     5,   574,  1167,   728,   316,
     513,   232,   732,     5,   383,     0,   736,  1476,     5,   686,
     740,   741,     5,   743,     5,   205,   746,     5,   748,   749,
     750,   232,  2514,   500,   403,  2557,   756,    95,    96,   759,
     216,   630,     5,     5,   286,   232,   766,    18,    19,    20,
      21,    22,   772,  2274,     5,  2537,   959,   718,     5,   779,
       5,   645,     5,   652,   232,   232,  1114,   125,   126,   127,
     790,   574,     5,     5,   794,     5,   448,     5,   798,     5,
     316,   418,   619,   232,   804,   752,   530,   807,    27,   617,
    2612,   630,     5,     5,     5,   276,     5,   232,     5,   502,
    1515,    28,  2794,  2795,  2796,  2797,     5,     5,     5,   479,
      31,     5,   541,   542,     9,    10,     5,    12,    13,    14,
      15,    16,    17,  2605,     5,    29,   471,   777,   778,   657,
     533,   290,     5,   536,   393,     5,   619,   313,  2512,     5,
     652,   544,   645,  1056,     5,     5,   628,     5,     5,   631,
       5,     5,   180,   181,   397,     5,   806,     5,   561,   809,
     563,  2371,   760,   482,    23,  2857,  2776,  2859,   571,   572,
       5,   666,   575,    18,    19,    20,    21,    22,   276,   555,
    2737,   193,   609,  1231,  1232,  1233,   589,   550,   434,    25,
     566,  2778,  2779,   660,    27,  1129,    27,    25,   427,    27,
     546,   193,  1136,   434,   106,   438,   636,    10,   388,    25,
    2867,    27,  1357,   325,    30,     9,    10,   438,    12,    13,
      14,    15,    16,    17,   405,    27,  2708,   555,  1388,   542,
    3017,  3230,   325,   105,   393,   599,   468,  1150,  1157,  2544,
    1400,   393,   657,   699,   583,  1158,  2501,  1160,  3035,   434,
     619,   438,   636,   512,  3313,  1466,   417,   284,   588,   427,
     504,   587,   665,   432,   583,   602,   660,   670,   671,   672,
     673,   674,   675,   472,   434,   678,   679,   680,   427,  1232,
     683,   684,   595,   686,   567,   666,   689,    27,   691,  3130,
    1324,   580,  1993,   567,   472,   594,  2014,   700,    27,   528,
     434,   591,   609,  1389,   468,  1360,  2788,   630,   711,   712,
    1360,   434,   591,   205,  3470,   468,   434,   472,   721,  2652,
     434,   597,   617,   541,   727,   512,     5,  2523,  2772,  1384,
     733,   734,   735,  2933,  1384,   660,   739,  2654,   658,   742,
    1251,   744,   745,   660,   707,   707,  2993,  1257,   287,   752,
    2997,   702,   755,   512,  3281,   707,  2634,   760,   761,  2089,
     763,   300,   626,  2963,   767,  3292,  1269,   770,  3521,   377,
     707,   707,   775,   609,   777,   778,   630,   512,   667,   782,
     783,   784,   434,   219,   587,   788,  3078,  3079,   791,   468,
    3082,   468,   597,   796,  1114,   434,   709,   434,   556,   294,
     803,   232,   805,   806,   232,   808,   809,   652,   811,   812,
     813,   658,   660,   652,   316,   467,   232,   276,   147,   666,
     428,   663,   468,   468,   591,   434,   468,   660,   468,   434,
     434,   660,    27,    25,   434,    27,    26,    27,   496,   660,
     624,   679,   680,   681,   682,   683,  2928,   434,  2930,   660,
     478,   434,     5,   434,   287,     5,   434,   652,   974,   660,
     579,   977,   278,   402,   409,  1250,   579,   300,   197,   985,
     986,   434,   434,   660,   500,   652,   500,  1390,  1391,  1392,
    3100,   209,  2692,   434,    14,   287,   388,   434,   291,  3276,
     563,   434,  3013,  3420,  1407,    30,   388,   468,   300,    34,
     294,   434,   434,   232,   434,   234,   434,   472,   434,   628,
     346,  1231,  1232,  1233,   917,   628,   352,   353,   354,   414,
     415,   434,   434,   434,   582,   434,   397,   434,   287,   665,
     432,   368,  2248,   472,   499,   434,   434,   434,   374,   434,
     434,   300,  1512,  1497,   155,   434,   405,   324,   665,   993,
     495,   587,   688,   434,  1467,  3212,   959,  2856,   430,  2858,
     337,   434,  2861,   361,   434,  1484,   511,   625,   434,   402,
     687,   688,  1485,   434,   434,   470,   434,   434,   517,   434,
     434,   116,   454,   399,   434,  3067,   434,   472,   402,   434,
    1503,  2307,  2308,  3114,   533,   998,  2094,  1000,     0,   434,
     402,  1514,   331,   579,    10,   206,  3298,   208,  3305,   554,
     438,   467,  3304,  3305,    16,  3307,  3308,  3309,  3310,  3316,
     414,   415,   658,   472,  3316,  1028,   429,  2345,   431,   472,
      40,  2349,   233,  3115,   660,   185,   472,   232,  1041,   472,
     232,  1044,   232,   402,   480,   385,   472,   483,   593,   324,
      56,  2140,   628,   393,   394,   491,    25,  1060,    27,   472,
    1063,  3318,   337,   479,    30,   537,    26,    27,    34,  3151,
      25,   400,    27,  3293,  3294,  3285,   470,   622,   418,   408,
     500,   421,   402,   412,   517,   522,   631,   500,   472,    25,
     526,    27,   508,   585,   471,   290,   106,   107,   438,  1102,
     533,   512,   597,   517,    25,   472,    27,   609,   678,   520,
    2209,   312,   472,   472,   315,   517,   500,  1120,  1121,  1122,
     449,  1124,   200,  1126,  1127,   561,   618,   630,    94,  1132,
    1133,   533,   499,   500,  3426,   101,   337,  3429,  3430,  3431,
    3432,   711,   712,   278,   580,   581,   536,  2125,   206,   652,
     208,  1401,   480,   287,   544,   591,   472,   629,   517,  3280,
     596,   171,  1165,   491,  1167,    25,   300,    27,   663,   641,
     642,   192,    20,  1176,   533,   196,  1179,   649,   472,    27,
     190,  1184,   148,   149,   512,   665,   515,   689,   690,   691,
     156,   519,   472,   763,   368,   562,   471,   517,   700,   635,
    1203,  1204,   542,   597,   472,  1403,  3288,   687,   688,   206,
    1213,   208,   626,  1327,  3069,    25,  1330,    27,   713,   714,
     342,  3513,   300,    26,    27,   554,  1229,  1230,   665,  3521,
     352,   667,   151,   152,   153,    25,   233,    27,    25,    25,
      27,    27,  1492,  1493,    25,  3144,    27,   684,   685,   578,
      26,    27,  1255,  2569,   312,   595,  2572,   315,  1261,  1262,
     338,  3419,   602,   232,   399,  3423,  1269,   704,   402,   663,
     471,  2031,   232,   472,   295,   665,  1279,   232,    39,   337,
      41,    42,    43,   472,  1287,    16,    17,    18,    19,    20,
      21,    22,   472,   622,  3376,  3137,   232,   472,  3140,  1497,
      19,  3143,   631,   313,   314,    24,   626,    26,   750,    40,
     320,   232,   472,   448,   324,   312,   472,   759,   315,   713,
     714,    28,    29,   409,   402,  2626,   499,   500,  1978,  1332,
    1353,   472,   280,  1336,  1337,  1338,  2654,    25,   416,    27,
     337,   248,   249,   250,   479,  1348,  1349,  1350,   522,   472,
    1353,  1354,  1355,  1356,  1357,  2291,   700,  1360,  2294,  1362,
    1363,  1364,   804,  2123,    24,   807,    26,   790,   472,   659,
    1373,   794,   232,   508,   500,   798,   666,   721,    25,   472,
      27,  1384,  1385,   517,  1387,  1388,  1389,   716,   717,   337,
     734,  2450,   472,  1396,  1397,  1398,   472,  1400,  1401,   533,
    1403,  1404,   133,   134,   135,   136,   137,   138,    20,   495,
     472,  1414,    20,   471,   409,    27,  1419,  2516,   718,    27,
     151,   152,   153,  3474,    26,   511,   409,   280,  2188,   232,
     472,  2079,   732,    25,    20,    27,   736,  2536,  2194,   517,
    3491,    27,   232,   391,   410,   232,   232,   395,   748,   472,
      20,   232,  1955,    25,    26,   533,   232,    27,  1961,  1962,
    1463,  1464,   522,  1466,  1967,  1968,  1969,  1970,   554,   805,
     436,  1041,   808,  2043,   471,   811,  3297,    26,  3299,  3300,
    3301,  3302,   280,    25,   337,    27,   409,  1490,  3539,  1492,
    1493,   665,   502,  1063,  1497,   472,  1499,   472,  1501,  1502,
     495,  3343,  2114,   513,   630,  3556,   379,   593,    19,   500,
     684,   685,   495,    24,    25,    26,   511,   390,    25,   472,
      27,  1524,    20,   471,   499,   500,   652,  1953,   511,    27,
     704,   680,   681,  2046,   660,   442,   622,   472,   391,   337,
     506,   480,   395,  2191,   232,   631,    20,    24,  2061,    26,
     472,   312,   491,    27,   315,   472,   317,  3408,  3409,   554,
     291,  2209,   682,   294,   574,    25,   409,    27,   441,  2082,
      26,   554,   495,   512,  2087,   695,   337,  2337,    20,    21,
     519,    25,   455,    27,    20,  2674,   347,   562,   511,  2108,
    2350,    27,  2352,   391,    25,   666,    27,   395,   593,   666,
    2113,  2361,  1852,  1853,   724,   665,    24,   368,    26,    26,
     593,  2855,  2856,    26,  2858,  2746,  2714,  2861,   471,  2132,
     740,   741,  2711,    26,   684,   685,   746,   622,    26,   749,
     391,   554,   598,   660,   395,   645,   631,   174,   409,   622,
      25,  3492,    27,  3494,   704,   182,  2149,   679,   631,   567,
     682,   683,   495,    25,   191,    27,   472,   194,  2976,   472,
     670,   671,   672,   673,   653,   654,   655,   656,   511,    26,
     593,   544,    25,   471,    27,    39,   500,    41,    42,    43,
     409,   691,   462,   414,   705,   706,    18,    19,    20,    21,
      22,   133,   134,   135,   136,   137,   138,   472,   429,   622,
     237,  1385,   433,  1387,   143,   144,   472,   244,   631,  2768,
     471,   554,   678,   472,   499,   500,    26,   727,   682,   683,
     686,   689,   690,   733,   495,   735,  2152,   689,   690,   739,
     329,   330,   742,  1130,  1131,   745,   472,  1134,  1135,   470,
     511,  2644,  2645,  2246,  2722,   755,  3078,  3079,   472,   472,
     593,  2254,  2730,  2731,  2257,  2258,  2259,  2260,   472,  2079,
     770,   472,    26,   102,   301,   775,   495,   498,    26,    26,
      26,   660,   782,   783,   784,    99,  2346,   434,   788,   622,
     472,   802,   511,   554,   404,   516,   796,    26,   631,   326,
     660,   812,   434,   472,  1364,   472,   333,   468,   335,     5,
     202,   434,   812,  1373,   472,   434,   434,  1921,   345,   434,
     512,   472,   666,    20,  3082,   217,   218,    20,   472,   472,
    2390,   434,   593,     5,   226,   554,  2339,    39,  1398,    41,
      42,    43,   472,   500,   664,    26,   373,   660,  2088,   178,
    2353,  2354,  2355,  2356,   381,    26,   434,   300,  1851,  1852,
    1853,   622,   468,   404,    30,  1858,  1859,    20,   260,    26,
     631,  2374,  2510,  1979,   593,    26,   597,   269,  2516,  2439,
      26,  2191,    26,    26,  1988,  1878,  1879,    26,  1881,  1882,
      26,   418,  1885,  1886,   630,  1888,   434,  1890,  2536,  2209,
     434,    26,    26,   622,   434,   434,   298,     5,   434,   434,
    3144,   240,   631,   242,  2664,    20,   443,   472,    26,    26,
      26,  1914,   660,   434,     5,   178,   434,    26,  2678,   258,
    2433,   434,  1925,   344,   434,   434,   434,   266,   434,   664,
       5,   270,   663,  2183,   434,   434,   666,   434,   959,   472,
    1984,   343,    26,   480,    18,    19,    20,    21,   312,   630,
    1953,   315,  1955,   317,   491,   434,   295,   666,  1961,  1962,
    1963,    25,    25,    25,  1967,  1968,  1969,  1970,   434,    25,
    2168,  2169,   434,   337,   344,  1978,   434,   240,   664,   242,
     434,   472,   434,   347,   434,   387,   434,   434,   434,  3022,
     660,  2107,   657,   434,   434,   258,   434,  2000,   660,   500,
       8,   660,  2005,   266,   368,   660,   520,   270,  2011,  2125,
     636,  2014,   308,   665,  2527,   501,  2529,   468,   281,     5,
     658,  2524,   658,  1044,   699,   636,   501,   391,  2031,   462,
    3298,   395,   295,   699,  1044,   370,  3304,   652,  2041,  3307,
    3308,  3309,  3310,     8,  2047,     5,   637,   462,  3026,     5,
    1060,    20,   589,   590,   591,    24,    25,    26,    27,   133,
     134,   135,   136,   137,   138,   602,   472,   472,   472,   388,
     630,  2574,  2075,   472,   619,   472,     8,    14,   616,  3094,
    2083,     5,  2085,  2086,     5,  2088,  2589,   462,   472,   699,
     699,   472,  1102,    26,   106,    26,   132,  2600,   660,  2102,
     312,   630,   462,   315,   500,   317,   472,   471,   500,   472,
    1120,  1121,  1122,   472,  1124,    26,  1126,  1127,  2121,     5,
    2123,   472,  1132,  1133,   472,   337,   472,   472,   472,   472,
    2778,  2779,   636,     5,   666,   347,   105,   665,   472,   472,
     666,  2144,   394,  2146,  2147,   702,  2149,     5,   597,  2152,
    2153,    18,    26,    19,  2338,    26,   368,  1167,  3426,   426,
     195,  3429,  3430,  3431,  3432,  2168,  2169,   630,   705,  1179,
      25,  2684,   178,   663,  2687,  3234,   619,   660,     5,   391,
    2183,   523,  1203,   395,  3243,  2188,  2189,  2190,    20,    21,
    2510,  2194,   523,  1203,  1204,   193,  2516,   587,  3257,  2202,
     587,    26,   442,  1213,   587,   961,   365,    26,   964,  2969,
     966,   967,   968,   969,   970,   434,  2536,  2220,  3317,  1229,
    1230,   472,   472,  2983,   434,  2228,  2229,   104,   660,  2232,
     567,   666,   434,  2746,   240,  2338,   242,   472,   472,   472,
    1261,  1262,   472,  2246,  2747,  3513,    98,     5,  1269,   704,
     660,  2254,   258,   630,  2257,  2258,  2259,  2260,  2261,   471,
     266,  2264,   434,   232,   270,  2268,  2269,   660,   630,  2272,
    2882,  2883,  2884,  2776,  2886,  2887,  2888,  2889,  2890,  2891,
     660,   617,   500,  2895,   587,   472,  2289,  2290,  2291,   295,
     657,  2294,  2295,  2296,     5,   666,  2299,    18,    19,    20,
      21,   133,   134,   135,   136,   137,   138,     5,     5,  1879,
       5,  1881,  1882,   620,   666,  1885,   524,   472,   665,   660,
    1890,     5,     8,    26,    26,  2328,   106,  2330,  2331,   361,
    2333,  2334,  2335,   260,  2337,   369,     5,     5,  2341,  3398,
     434,   472,  2345,   472,   403,   637,  2349,  2350,   666,  2352,
      14,   700,     5,   591,    26,  2358,  2359,   141,  2361,  2362,
    2863,   587,  2365,  2366,   666,   472,   660,   472,  2794,  2795,
    2796,  2797,   665,  3406,     5,  1385,   468,  1387,  1388,  1389,
     679,    26,   434,     5,  2387,  2649,  1396,  1397,     5,   411,
    1400,   659,   375,  1963,  1404,  2398,   468,     8,  1419,  2402,
     502,   502,   472,  3477,  3478,  3479,  3480,  3481,  3482,  1419,
       5,   472,   133,   134,   135,   136,   137,   138,   472,   472,
       5,   472,   472,   472,  2427,   472,     8,     5,   660,   660,
     594,   660,    25,   369,   388,   388,   660,   388,   467,   472,
     500,   403,   500,  3502,     5,  1241,     5,   691,  2451,    26,
       5,     5,    25,  1463,  1464,    26,  1466,    14,  2778,  2779,
     657,    14,   636,   636,   341,   472,   594,     5,     5,   438,
     434,   472,   666,   434,     6,   434,   434,  3237,   472,   434,
       7,   310,   434,     5,   361,   362,   363,   489,   434,  1499,
     660,  3004,    26,    26,   660,   666,  2499,    26,    26,     8,
     469,    26,   660,   472,   434,    20,     5,   607,   660,   316,
       5,  2514,     5,  2083,  1524,  3493,   485,     5,   587,  2522,
    2523,  2524,  3156,   400,  3037,   708,     5,   434,  2557,   612,
    2794,  2795,  2796,  2797,  2537,   412,  2539,   660,   434,   512,
    2543,  2544,   666,   472,     5,   666,   423,   253,    26,   434,
     664,     5,   472,   666,   666,   512,   525,   472,     5,    25,
    2758,  2745,  2760,   440,   659,   664,    25,    25,   537,   488,
      25,  2574,    25,   450,    26,    26,    26,    26,    26,  2582,
    3613,  2584,    26,  2612,  2587,   338,  2589,   434,   465,   434,
      26,     5,   434,   434,   472,   509,     5,  2600,   434,   472,
     591,  2717,  2605,  2606,  2607,   282,  2722,    26,    25,   578,
     434,   468,   482,  2616,  2730,  2731,   388,    20,   184,   594,
       5,   472,   472,   472,   472,     5,   472,    14,   472,  3389,
     253,  2634,  2202,   472,   434,     5,   513,   500,    26,   434,
     483,   434,  2745,    26,  3147,    26,  3149,   434,   617,  2652,
     472,  2654,  3078,  3079,    26,    26,  3082,    26,   417,   609,
     629,  2664,    26,   434,   282,   434,   543,   434,  2671,  3317,
     472,   388,   641,   642,   434,  2678,   553,   283,   482,   500,
     649,   587,   472,   652,   434,    14,   660,     7,    26,   281,
     281,   660,   434,   434,  2264,   666,   435,   574,   472,   434,
    2703,   578,  2705,   616,  2707,  2708,  2709,   434,   472,    25,
     434,   660,  3138,   468,   283,  3141,   434,     5,   434,   434,
    2723,   434,  2725,  2726,  2727,   434,  3239,     5,    25,   606,
     434,  2671,   660,  2725,   660,   660,  3549,  2740,   615,  3124,
     985,  2423,  1504,    29,  2747,  2133,    31,   541,  2362,  2703,
    2368,  3001,   350,   114,   343,  2758,   118,  2760,  3271,   649,
    1983,  3011,   207,   351,  1984,   530,   223,  2770,  2771,   210,
     549,  1260,   592,  2776,   563,   380,   379,  3539,   561,  2046,
    2226,   977,  3285,   788,   411,  2788,  2233,  2355,  2358,  2087,
    1851,  2794,  2795,  2796,  2797,  2798,  2799,  1854,  3047,  2749,
    2447,  1238,  2160,  3590,  2358,  2178,  1403,  2810,  3251,    16,
      92,    40,  2815,  3177,  3078,  3079,    40,    22,  3082,  2138,
    2144,   919,   745,   324,  1859,  1000,  2147,  2995,  1204,  1464,
    3174,  3351,   770,  1397,  3556,  1462,  2747,  1387,  1859,  3361,
    1485,  2844,  2845,  2922,  2113,  2920,   448,  2904,  1858,  1859,
    2615,  2981,  2855,  2856,  3231,  2858,  3229,  3222,  2861,  2349,
    2863,  2000,  2973,  2017,  2867,  2299,  2510,  3565,  3151,  2540,
    3296,  3446,  3298,  2927,  3138,  3376,  2961,  3141,  3304,  3305,
    2845,  3307,  3308,  3309,  3310,  2264,  2201,  2844,  2587,  3141,
    3316,  3452,  2995,  2637,  2949,  3193,     9,  1878,     8,  3219,
    2616,  3606,  2606,  2906,  1914,    18,    19,    20,  1234,  3229,
    3026,    24,    25,    26,    27,  2607,  2919,  3077,  2789,  3422,
    3149,  1962,   219,  1961,  1873,  2928,  2929,  2930,  3416,  2499,
    1230,  3076,  1846,  3296,  1955,  3315,  3304,  2709,  1402,  2335,
    1961,  1962,   539,    -1,    -1,    -1,  1967,  1968,  1969,  1970,
      -1,  2954,    -1,  3456,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  2966,  2967,    -1,  2969,    -1,    -1,  2539,
    2973,    -1,    -1,  2976,    -1,  3488,    -1,    -1,    -1,    -1,
    2983,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    2993,    -1,   105,  2996,  2997,    -1,    -1,  3317,  3001,    -1,
    3426,    -1,    -1,  3429,  3430,  3431,  3432,    -1,  3011,    -1,
    3013,    -1,  2582,    -1,  2584,    -1,    -1,    -1,    -1,  3022,
      -1,  2031,    -1,    -1,    -1,    -1,  3452,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  3298,  3233,    -1,    -1,    -1,    -1,
    3304,  3305,    -1,  3307,  3308,  3309,  3310,    -1,    -1,   346,
      -1,    -1,  3316,    -1,    -1,   352,   353,   354,  3061,    -1,
      -1,    -1,  3565,    -1,  3067,    -1,    -1,    -1,    -1,  3333,
      -1,    -1,  3585,  3076,    -1,  3078,  3079,   374,    -1,  3082,
      -1,    -1,    -1,   161,    -1,    -1,    -1,  3513,    -1,    -1,
    3093,    -1,  2102,  2114,    -1,  3521,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  3114,  3115,  2123,  3117,    -1,  1912,  1913,    -1,   232,
      -1,    -1,    -1,  1919,    -1,    -1,    -1,  3130,  2149,    -1,
      -1,    -1,    -1,    -1,  2144,  3138,    -1,    -1,  3141,  2709,
      -1,  3144,    -1,  2153,  3147,    -1,  3149,    -1,  3151,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    40,    -1,    -1,
      -1,    -1,  3426,    -1,    -1,  3429,  3430,  3431,  3432,    -1,
      -1,  3174,    -1,    -1,    -1,    -1,    -1,    -1,  2188,  2189,
    2190,    -1,    -1,   480,  2194,   263,   483,    -1,  3452,    -1,
      -1,    -1,    -1,   271,   491,    -1,    -1,    -1,    -1,   277,
      -1,   279,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  3212,
    2220,    -1,   290,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   336,    -1,  2246,    -1,    -1,  3412,   526,
    3233,    -1,    -1,  2254,  3237,    -1,  2257,  2258,  2259,  2260,
     318,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2269,  3513,
     133,   134,   135,   136,   137,   138,   334,  3521,    -1,    -1,
      -1,   339,    -1,    -1,   561,    -1,    -1,    -1,   151,   152,
     153,    -1,    -1,   351,  2295,    -1,    -1,  3280,    -1,    -1,
     358,    -1,  3285,   580,   581,  3288,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  3296,   591,  3298,    -1,    -1,    -1,   596,
      -1,  3304,  3305,    -1,  3307,  3308,  3309,  3310,    -1,  3412,
    3313,    -1,  3315,  3316,    -1,  3318,    -1,    -1,    -1,    -1,
    2116,    -1,    -1,    -1,    -1,   438,    -1,  2337,  2338,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   635,    -1,
    2350,    -1,  2352,    -1,    -1,    -1,    -1,    -1,  3351,    -1,
      -1,  2361,    -1,  3356,    -1,  3358,   469,    -1,    -1,   472,
    2156,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     667,   484,   485,  3376,    -1,    -1,    -1,  3493,    22,    -1,
      -1,    -1,    -1,    -1,  2954,    -1,  3389,    -1,  2398,    -1,
      -1,    -1,  2402,    -1,    -1,    -1,    40,    -1,    -1,   512,
      -1,    -1,    -1,  3406,    -1,    -1,    -1,    -1,   291,    -1,
      -1,   294,   525,  3416,    -1,    -1,    -1,  2427,    -1,  3422,
      -1,    -1,    -1,  3426,   537,    -1,  3429,  3430,  3431,  3432,
    3433,    -1,    -1,    -1,   512,    -1,    -1,    -1,    -1,    -1,
      -1,   519,    -1,  3446,    -1,    -1,    -1,    -1,    -1,  3452,
      -1,    -1,    -1,  3456,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   541,    -1,   578,    -1,    -1,   546,    -1,
      -1,    -1,    -1,    -1,  3477,  3478,  3479,  3480,  3481,  3482,
      -1,    -1,    -1,    -1,    -1,    -1,  3489,    -1,    -1,   133,
     134,   135,   136,   137,   138,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  2524,   617,    -1,    -1,   151,   152,   153,
    3513,    -1,    -1,    -1,    -1,    -1,   629,    -1,  3521,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   641,   642,
      -1,   414,    -1,  2543,    -1,    -1,   649,    -1,    -1,   652,
      -1,    -1,    -1,    -1,    -1,    -1,   429,   660,    -1,    -1,
     433,    -1,    -1,  2574,    -1,    -1,    -1,    -1,    -1,    -1,
    3130,    -1,  3565,    -1,  3567,    -1,  2587,    -1,  2589,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2600,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   470,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  2606,    -1,    -1,    -1,
      -1,  3604,  3605,  3606,    -1,    -1,    -1,    -1,    -1,    -1,
    3613,    -1,  3615,    -1,    -1,   498,    -1,    -1,    -1,    -1,
       9,  2417,  2418,    -1,    -1,    -1,    -1,    -1,  2649,    18,
      19,    -1,  2428,   516,    -1,    24,    25,    26,    27,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   291,    -1,    -1,
     294,    -1,    -1,    -1,  2664,    -1,  2452,  2453,  2454,  2455,
      -1,    -1,    -1,    -1,  2460,  2461,  2462,  2463,  2678,    -1,
      -1,  2467,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    45,    46,    47,    48,    49,
      50,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   100,    -1,  2723,   597,  2725,   105,  2727,    -1,    -1,
      -1,    -1,    -1,   112,    -1,    -1,  2747,    -1,    -1,    -1,
    2740,    -1,    -1,    -1,    -1,  2745,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2545,
    2546,   140,    -1,    -1,    -1,  2776,  2552,  2553,    -1,    -1,
    2770,  2771,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     414,    -1,    -1,  2794,  2795,  2796,  2797,    -1,    -1,   139,
     663,    -1,    -1,    -1,    -1,   429,    -1,    -1,    -1,   433,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    2810,     8,    -1,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  2844,  2845,    -1,   470,    -1,    -1,    -1,
      -1,    -1,    -1,    40,  2855,  2856,    -1,  2858,    -1,    -1,
    2861,    -1,  2863,   232,    -1,   234,  2867,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   498,    -1,    -1,    -1,    -1,    -1,
      -1,  2882,  2883,  2884,    -1,  2886,  2887,  2888,  2889,  2890,
    2891,    -1,   516,    -1,  2895,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    18,    19,    -1,    -1,
      -1,    -1,    -1,    -1,    26,    27,  2906,  2693,  2694,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  2702,    -1,    -1,  2919,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   133,   134,   135,   136,
     137,   138,    -1,    -1,    -1,    -1,    -1,    -1,  2734,  2735,
      -1,    -1,   331,    -1,   151,   152,   153,   336,    -1,    -1,
      -1,    -1,    -1,   597,    -1,    -1,    -1,    -1,    -1,  2969,
      -1,    -1,    -1,  2759,    -1,  2761,    -1,    -1,   100,    -1,
      -1,    -1,    -1,  2983,    -1,    -1,    -1,   366,     9,    -1,
     112,    -1,    -1,    -1,    -1,  2995,    -1,    18,    19,    -1,
      -1,    -1,    -1,    24,    25,    26,    27,    -1,    -1,    -1,
      -1,  3022,    -1,  3013,    -1,    -1,    -1,    -1,   140,    -1,
      -1,   400,  3022,    -1,    -1,    -1,   376,    -1,    -1,   663,
    2816,  2817,    -1,   412,  2820,  2821,    -1,    -1,    -1,   389,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   430,    -1,    -1,    -1,    -1,   435,    -1,    -1,   438,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  3078,  3079,    -1,
     449,  3082,    -1,    -1,    -1,   454,    -1,    -1,    -1,   100,
      -1,    -1,    -1,    -1,   105,   464,    -1,    -1,    -1,    -1,
     469,   112,    -1,   472,   291,    -1,   475,   294,    -1,    -1,
      -1,    -1,   452,    -1,    -1,   484,   485,    -1,   458,    -1,
     232,    -1,   234,    -1,  3114,    -1,    -1,    -1,    -1,   140,
      -1,    -1,    -1,    -1,  2910,    -1,    -1,  3138,    -1,    -1,
    3141,    -1,    -1,  3144,    -1,    -1,  3147,    -1,  3149,    -1,
      -1,    -1,    -1,    -1,    -1,   524,   525,   497,    -1,    -1,
     529,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   537,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   548,
      -1,   521,    -1,    -1,  3174,   554,    -1,    -1,    -1,    -1,
      -1,   531,   532,    -1,    -1,    -1,    -1,   537,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   547,    -1,   578,
      -1,  3212,    -1,    -1,    -1,    -1,    -1,    -1,  2994,   331,
      -1,   232,  2998,   234,    -1,    -1,    -1,   414,    -1,   569,
      -1,    -1,   572,   573,    -1,    -1,    -1,   577,  3014,    -1,
      -1,    -1,   429,    -1,    -1,    -1,   433,  3237,    -1,    -1,
      -1,    -1,    -1,   622,   366,    -1,    -1,  3033,    -1,    -1,
     629,    -1,   631,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   641,   642,    -1,    -1,    -1,    -1,    -1,    -1,
     649,    -1,    -1,   470,  3285,    -1,    -1,    -1,   400,    -1,
    3280,   660,    -1,    -1,   634,    -1,    -1,  3298,    -1,    -1,
     412,    -1,    -1,  3304,  3305,   645,  3307,  3308,  3309,  3310,
      -1,   498,    -1,    -1,    -1,  3316,    -1,  3318,    -1,    -1,
     331,    -1,    -1,    -1,    -1,   336,    -1,    -1,    -1,   516,
      -1,    -1,  3333,    -1,    -1,    -1,    -1,   449,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   716,   717,    -1,
      -1,    -1,   464,    -1,     9,   366,    -1,    -1,    -1,    -1,
     472,  3351,    -1,    18,    19,    -1,  3356,    -1,  3358,    24,
      25,    26,    27,   485,    -1,    -1,     9,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    18,    19,    -1,    -1,   400,
      -1,    24,    25,    26,    27,    -1,    -1,    -1,    -1,  3389,
      -1,   412,    -1,    -1,    -1,  3406,    -1,    -1,    -1,    -1,
     597,    -1,    -1,    -1,    -1,    -1,  3406,   529,    -1,   430,
      -1,  3422,  3412,    -1,   435,  3426,    -1,   438,  3429,  3430,
    3431,  3432,    -1,    -1,    -1,    -1,    -1,    -1,   449,    -1,
      -1,    -1,   554,   454,    -1,   100,    -1,    -1,    -1,    -1,
     105,  3452,    -1,   464,    -1,  3456,    -1,   112,   469,    -1,
      -1,   472,    -1,    -1,   475,    -1,   578,   100,    -1,    -1,
      -1,    -1,   105,   484,   485,    -1,   663,    -1,    -1,   112,
      -1,    -1,    -1,    -1,    -1,   140,    -1,  3477,  3478,  3479,
    3480,  3481,  3482,  3269,    -1,    -1,  3272,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   140,    -1,    -1,
     622,    -1,  3513,    -1,   525,    -1,    -1,    -1,   529,   631,
    3521,    -1,    -1,    -1,    -1,    -1,   537,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   548,    -1,   550,
      -1,    -1,    -1,   554,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  3565,    -1,    -1,   578,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   232,     9,   234,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    18,    19,    20,
      -1,    -1,    -1,    24,    25,    26,    27,    -1,    -1,   232,
      -1,   234,    -1,    -1,   716,   717,    -1,    -1,    -1,    -1,
      -1,   622,  3613,    -1,    -1,    -1,    -1,    -1,   629,    -1,
     631,    -1,    -1,  3613,    -1,    -1,    -1,    -1,    -1,    -1,
     641,   642,    -1,    -1,  3410,    18,    19,    20,   649,    -1,
      -1,    24,    25,    26,    27,    -1,    -1,    -1,    -1,   660,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   105,    -1,   331,    -1,    -1,    -1,
      -1,   336,  3458,  3459,    -1,  3461,    -1,  3463,  3464,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   331,    -1,
      -1,    -1,    -1,   336,    -1,   716,   717,    -1,    -1,    -1,
      -1,   366,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   105,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   366,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   400,    20,    21,    22,    -1,
      -1,  3527,    -1,  3529,    -1,    -1,    -1,   412,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    40,   400,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   430,    -1,    -1,    -1,   412,
     435,    -1,    -1,   438,    -1,    -1,    -1,  3563,    -1,    -1,
      -1,    -1,    -1,    -1,   449,    -1,    -1,   430,    -1,   454,
      -1,   232,   435,  3579,  3580,   438,    -1,  3583,    -1,   464,
    3586,    -1,    -1,    -1,   469,    -1,   449,   472,    -1,    -1,
     475,   454,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   484,
     485,   464,    -1,    -1,    -1,    -1,   469,    -1,    -1,   472,
      -1,    -1,   475,    -1,    -1,    -1,    -1,    -1,    -1,   232,
      -1,   484,   485,    -1,    -1,    -1,    -1,    -1,    -1,   133,
     134,   135,   136,   137,   138,    -1,    -1,    -1,    -1,   524,
     525,    -1,    -1,    -1,   529,    -1,    -1,   151,   152,   153,
      -1,    -1,   537,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   525,   548,    -1,    -1,   529,    -1,    -1,   554,
      -1,    -1,    -1,    -1,   537,   336,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   548,    -1,    -1,    -1,    -1,
      -1,   554,    -1,   578,     5,     6,     7,     8,     9,    10,
      -1,    12,    13,    14,    -1,    -1,    -1,    18,    19,    20,
      21,    22,    23,    -1,    -1,   578,    -1,    -1,    -1,    -1,
      -1,    -1,    33,   336,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   622,    -1,    50,
      -1,    -1,    -1,    -1,   629,    -1,   631,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   641,   642,    -1,   622,
      -1,    -1,    -1,    -1,   649,    -1,   629,    -1,   631,    -1,
      -1,    -1,    -1,    -1,    -1,   660,    -1,   438,   641,   642,
      -1,    -1,    -1,    -1,    -1,    -1,   649,   291,    -1,    -1,
     294,    -1,   103,    -1,    -1,    -1,    -1,   660,    -1,    -1,
      -1,   112,    -1,    -1,    -1,    -1,    -1,    -1,   469,    -1,
      -1,   472,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   130,
      -1,   132,    -1,   484,   485,   438,    -1,    -1,    -1,   140,
      -1,   716,   717,    -1,    -1,    -1,   147,   148,    -1,    -1,
     151,   152,   153,   154,    -1,    -1,   157,   158,    -1,    -1,
      -1,    -1,    -1,   716,   717,    -1,   469,    -1,    -1,   472,
      -1,    -1,    -1,    -1,   525,    -1,    -1,    -1,    -1,    -1,
      -1,   484,   485,    -1,    -1,    -1,   537,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   197,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   219,    -1,
     414,    -1,   525,    -1,   225,    -1,    -1,   578,    -1,    -1,
     231,   232,    -1,   234,   537,   429,    -1,    -1,   239,   433,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   265,    -1,   617,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   578,   470,    -1,   629,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     641,   642,    -1,    -1,    -1,    -1,    -1,    -1,   649,    -1,
      -1,   652,   303,    -1,   498,    -1,    -1,    -1,    -1,   660,
      -1,    -1,    -1,    -1,   617,   316,    -1,    -1,    -1,    -1,
      -1,   322,   516,    -1,    -1,    -1,   629,    -1,    -1,    -1,
     331,   332,    -1,    -1,    -1,    -1,    -1,   338,   641,   642,
     341,   342,    -1,    -1,    -1,   346,   649,    -1,    -1,   652,
      -1,   352,   353,    -1,    -1,    -1,    -1,   660,   359,   360,
     361,    -1,    -1,   364,   365,   366,    -1,    -1,    -1,   370,
      -1,    -1,    -1,   374,    -1,   376,    -1,    -1,    -1,     5,
      -1,    -1,   383,   384,   385,   386,    -1,   388,   389,    -1,
      -1,    -1,   393,   394,    -1,   396,   397,   398,   399,   400,
     401,   402,    -1,   597,    -1,    -1,    -1,   408,   409,   410,
      -1,   412,   413,    -1,    -1,    -1,   417,   418,   419,   420,
     421,   422,   423,   424,    -1,   426,    -1,    -1,    -1,   430,
     431,   432,   433,   434,   435,   436,   437,   438,   439,   440,
     441,   442,   443,   444,   445,   446,   447,   448,   449,   450,
     451,   452,   453,   454,   455,   456,   457,   458,   459,   460,
     461,   462,   463,   464,   465,   466,    -1,   468,   469,   663,
      -1,   472,   473,   474,   475,   476,   477,   478,   479,   480,
     481,    -1,   483,   484,   485,   486,   487,   488,   489,   490,
     491,   492,   493,   494,   495,   496,   497,    -1,    -1,   500,
     501,   502,   503,   504,   505,   506,   507,   508,    -1,   510,
     511,   512,   513,    -1,   515,   516,   517,   518,   519,   520,
     521,   522,   523,   524,   525,   526,   527,   528,   529,   530,
     531,   532,   533,   534,   535,   536,   537,   538,   539,   540,
     541,   542,   543,   544,   545,   546,   547,   548,   549,   550,
      -1,   552,   553,   554,   555,   556,   557,    -1,    -1,   560,
     561,    -1,   563,   564,   565,   566,   567,   568,   569,   570,
     571,   572,   573,   574,   575,   576,   577,   578,   579,   580,
     581,   582,   583,   584,   585,   586,   587,   588,    -1,    -1,
     591,   592,   593,   594,   595,   596,   597,   598,   599,   600,
     601,   602,   603,   604,   605,   606,   607,   608,   609,   610,
     611,   612,   613,   614,   615,   616,   617,   618,   619,   620,
     621,   622,   623,   624,   625,   626,   627,   628,   629,   630,
     631,   632,   633,   634,   635,   636,   637,   638,   639,   640,
     641,   642,   643,   644,   645,   646,   647,   648,   649,   650,
     651,   652,    -1,    -1,    -1,    -1,   657,   658,   659,   660,
     661,   662,   663,   664,   665,   666,   667,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   302,   678,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   686,    -1,    -1,    -1,    -1,
     691,    -1,    -1,    -1,   695,    -1,    -1,   698,   699,   700,
     701,    -1,    -1,   704,   705,   302,   707,   708,   709,     5,
       6,     7,     8,     9,    10,   341,    12,    13,    14,    -1,
      -1,    -1,    18,    19,    20,    21,    22,    23,    -1,    -1,
      -1,    -1,    -1,    -1,   360,   361,    -1,    33,    -1,    -1,
      -1,    -1,    -1,    -1,   341,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    50,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   360,   361,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   400,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   412,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   423,    -1,    -1,
      -1,    -1,    -1,   400,    -1,    -1,    -1,   103,    -1,    -1,
      -1,    -1,    -1,    -1,   440,   412,   112,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   450,    -1,   423,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   130,    -1,   132,    -1,    -1,   465,
      -1,    -1,    -1,   440,   140,    -1,    -1,    -1,    -1,    -1,
      -1,   147,   148,   450,    -1,   151,   152,   153,   154,    -1,
      -1,   157,   158,    -1,    -1,    -1,    -1,    -1,   465,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   505,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   197,   528,    -1,    -1,    -1,    -1,    -1,   505,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   543,    -1,    -1,
      -1,    -1,    -1,   219,   550,    -1,    -1,   553,    -1,   225,
      -1,   528,    -1,    -1,    -1,    -1,   232,    -1,   234,    -1,
      -1,    -1,    -1,   239,    -1,    -1,   543,    -1,   574,    -1,
      -1,    -1,   578,   550,    -1,    -1,   553,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   265,
      -1,   597,    -1,    -1,    -1,    -1,    -1,   574,    -1,    -1,
      -1,   578,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   615,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     597,    -1,    -1,    -1,    -1,    -1,    -1,   303,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   615,    -1,
     316,    -1,    -1,    -1,    -1,    -1,   322,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   331,   332,    -1,    -1,    -1,
      -1,    -1,   338,    -1,    -1,   341,   342,    -1,    -1,    -1,
     346,    -1,    -1,    -1,    -1,    -1,   352,   353,    -1,    -1,
      -1,    -1,    -1,   359,   360,   361,    -1,    -1,   364,   365,
     366,    -1,    -1,    -1,   370,    -1,    -1,    -1,   374,    -1,
     376,    -1,    -1,    -1,    -1,    -1,    -1,   383,   384,   385,
     386,    -1,   388,   389,    -1,    -1,    -1,   393,   394,    -1,
     396,   397,   398,   399,   400,   401,   402,    -1,    -1,    -1,
      -1,    -1,   408,   409,   410,    -1,   412,   413,    -1,    -1,
      -1,   417,   418,   419,   420,   421,   422,   423,   424,    -1,
     426,    -1,    -1,    -1,   430,   431,   432,   433,   434,   435,
     436,   437,   438,   439,   440,   441,   442,   443,   444,   445,
     446,   447,   448,   449,   450,   451,   452,   453,   454,   455,
     456,   457,   458,   459,   460,   461,   462,   463,   464,   465,
     466,    -1,   468,   469,    -1,    -1,   472,   473,   474,   475,
     476,   477,   478,   479,   480,   481,    -1,   483,   484,   485,
     486,   487,   488,   489,   490,   491,   492,   493,   494,   495,
     496,   497,    -1,    -1,   500,   501,   502,   503,   504,   505,
     506,   507,   508,    -1,   510,   511,   512,   513,    -1,   515,
     516,   517,   518,   519,   520,   521,   522,   523,   524,   525,
     526,   527,   528,   529,   530,   531,   532,   533,   534,   535,
     536,   537,   538,   539,   540,   541,   542,   543,   544,   545,
     546,   547,   548,   549,   550,    -1,   552,   553,   554,   555,
     556,   557,    -1,    -1,   560,   561,    -1,   563,   564,   565,
     566,   567,   568,   569,   570,   571,   572,   573,   574,   575,
     576,   577,   578,   579,   580,   581,   582,   583,   584,   585,
     586,   587,   588,    -1,    -1,   591,   592,   593,   594,   595,
     596,   597,   598,   599,   600,   601,   602,   603,   604,   605,
     606,   607,   608,   609,   610,   611,   612,   613,   614,   615,
     616,   617,   618,   619,   620,   621,   622,   623,   624,   625,
     626,   627,   628,   629,   630,   631,   632,   633,   634,   635,
     636,   637,   638,   639,   640,   641,   642,   643,   644,   645,
     646,   647,   648,   649,   650,   651,   652,    -1,    -1,    -1,
      -1,   657,   658,   659,   660,   661,   662,   663,   664,   665,
     666,   667,    30,    -1,    -1,    -1,    34,    -1,    36,    37,
      38,    -1,   678,    -1,    -1,    -1,    44,    -1,    -1,    -1,
     686,    -1,    -1,    51,    52,   691,    -1,    -1,    -1,   695,
      -1,    -1,   698,   699,   700,   701,    -1,    -1,   704,   705,
      -1,   707,   708,   709,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    92,    93,    -1,    -1,    -1,    97,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   107,
     108,    -1,   110,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   124,    -1,    -1,    -1,
      -1,    -1,    -1,   131,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   142,    -1,    -1,   145,   146,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   160,    -1,   162,   163,   164,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   172,   173,    -1,   175,   176,   177,
      -1,    -1,    -1,    -1,    -1,   183,    -1,    -1,   186,    -1,
     188,   189,   190,    -1,    -1,    -1,    -1,    -1,   196,    -1,
     198,   199,    -1,   201,    -1,   203,   204,    -1,    -1,   207,
      -1,    -1,   210,   211,   212,   213,   214,   215,    -1,    -1,
      -1,   219,   220,   221,    -1,   223,    -1,    -1,    -1,   227,
      -1,   229,   230,    -1,    -1,    -1,    -1,   235,    -1,    -1,
     238,    -1,    -1,   241,    -1,   243,    -1,   245,    -1,   247,
      -1,    -1,    -1,   251,   252,    -1,   254,   255,   256,    -1,
      -1,   259,    -1,   261,   262,    -1,   264,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   272,   273,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   285,    -1,    -1,
     288,   289,    -1,    -1,   292,   293,    -1,    23,   296,   297,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   305,   306,   307,
      -1,   309,    -1,    39,    -1,    41,    42,    43,    -1,    -1,
      -1,   319,   320,   321,    -1,   323,    -1,    -1,    -1,   327,
     328,    -1,    -1,    -1,   332,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   340,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     348,   349,   350,    -1,    -1,    -1,    -1,    -1,   356,   357,
      -1,    -1,    -1,    -1,    -1,    -1,   364,    -1,    -1,   367,
      -1,    -1,    -1,   371,   372,    -1,    -1,   103,    -1,    -1,
      -1,    -1,    -1,    -1,   382,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   399,    -1,    -1,    -1,    -1,   132,    -1,    -1,   407,
      -1,    -1,    -1,    -1,    -1,   413,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   424,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   436,    -1,
      -1,    -1,    -1,    -1,    -1,   443,    -1,   445,   446,    -1,
      -1,    -1,   178,    -1,    -1,   453,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   114,   115,    -1,   117,   118,   119,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     206,    -1,   208,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   492,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   503,    -1,   233,    -1,    -1,
      -1,    -1,   510,    -1,   240,    -1,   242,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   253,    -1,    -1,
      -1,    -1,   258,    -1,    -1,    -1,   534,   535,    -1,    -1,
     266,   539,    -1,    -1,   270,    -1,    -1,    -1,    -1,    -1,
     276,    -1,    -1,   551,   280,   281,   282,   283,    -1,   557,
     558,   559,   560,    -1,    -1,    -1,   564,   218,    -1,   295,
     568,    -1,    -1,    -1,    -1,   226,    -1,   575,   576,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   312,    -1,   586,   315,
     588,   317,    -1,    -1,    -1,    -1,    -1,    -1,   324,    -1,
      -1,   599,    -1,   601,    -1,    -1,   604,    -1,    -1,   260,
      -1,   337,   610,    -1,    -1,    -1,    -1,    -1,   269,    -1,
      -1,   347,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   636,    -1,
      -1,   639,   368,   369,    -1,    -1,   644,   298,   299,   647,
     648,    -1,    -1,    -1,    -1,    -1,    -1,   383,    -1,    -1,
      -1,    -1,    -1,    -1,   662,   391,    -1,    -1,    -1,   395,
      -1,   669,    -1,    -1,    -1,    -1,    -1,   403,   404,   405,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   343,    -1,   692,   693,   694,   695,   696,   697,
     698,    -1,    -1,   701,    -1,   703,    -1,   705,    -1,    -1,
      -1,    -1,    -1,     5,     6,     7,     8,   715,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    -1,    -1,    -1,    -1,    -1,   387,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   471,    -1,    -1,    40,    -1,
      -1,    -1,     5,     6,     7,     8,   482,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    40,    -1,    -1,
      -1,   442,    -1,    -1,    -1,    -1,   522,    -1,    -1,    -1,
       6,     7,     8,    -1,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    40,    -1,    -1,    -1,    -1,    -1,
      -1,   133,   134,   135,   136,   137,   138,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   583,    -1,   151,
     152,   153,     6,     7,     8,    -1,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    -1,
     133,   134,   135,   136,   137,   138,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   619,    -1,    -1,    40,    -1,   151,   152,
     153,     6,     7,     8,    -1,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   133,   134,   135,
     136,   137,   138,    -1,    -1,    40,    -1,    -1,    -1,   665,
      -1,    -1,    -1,    -1,    -1,   151,   152,   153,    -1,    -1,
      -1,    -1,    -1,   679,   680,   681,   682,   683,   684,   685,
      -1,   687,   688,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   704,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   133,
     134,   135,   136,   137,   138,    -1,    -1,    -1,    -1,   291,
      -1,    -1,   294,    -1,    -1,    -1,    -1,   151,   152,   153,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   668,   669,   670,
     671,   672,   673,   674,   675,   676,   677,    -1,   133,   134,
     135,   136,   137,   138,    -1,    -1,    -1,    -1,   291,    -1,
      -1,   294,    -1,    -1,    -1,    -1,   151,   152,   153,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,     6,     7,     8,
      -1,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    -1,   291,    -1,    -1,   294,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    40,     6,     7,     8,    -1,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    -1,
      -1,    -1,   414,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    40,   429,    -1,    -1,
      -1,   433,    -1,    -1,    -1,    -1,    -1,   291,    -1,    -1,
     294,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   414,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   429,    -1,   470,    -1,
     433,    -1,    -1,    -1,    -1,    -1,   291,    -1,    -1,   294,
      -1,    -1,    -1,    -1,   133,   134,   135,   136,   137,   138,
      -1,    -1,    -1,    -1,    -1,    -1,   498,    -1,   414,    -1,
      -1,    -1,   151,   152,   153,    -1,    -1,   470,    -1,    -1,
      -1,    -1,    -1,   429,   516,    -1,    -1,   433,   434,   133,
     134,   135,   136,   137,   138,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   498,    -1,   151,   152,   153,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   516,   470,    -1,    -1,    -1,    -1,    -1,
     414,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   429,    -1,    -1,    -1,   433,
     434,    -1,   498,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   597,    -1,    -1,    -1,   414,
     516,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   429,    -1,   470,    -1,   433,   434,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   597,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   291,    -1,   498,   294,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   470,    -1,    -1,    -1,    -1,
      -1,   663,   516,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   291,    -1,    -1,
     294,   597,    -1,   498,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     663,   516,    -1,    -1,    -1,     6,     7,     8,    -1,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    -1,    -1,    -1,    18,    19,    20,    -1,    -1,
      -1,    24,    25,    26,    27,    -1,    -1,    -1,    -1,    40,
      -1,    -1,    -1,   597,     6,     7,     8,   663,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    -1,    -1,    -1,    -1,   414,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    40,    -1,
     429,    -1,   597,    -1,   433,   434,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     414,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   663,
      -1,    -1,   105,    -1,    -1,   429,    -1,    -1,    -1,   433,
     434,   470,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   133,   134,   135,   136,   137,   138,    -1,    -1,
      -1,    -1,    24,    25,    26,    27,    -1,    -1,   663,   498,
     151,   152,   153,    -1,    -1,    -1,   470,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   516,    -1,    -1,
      -1,   133,   134,   135,   136,   137,   138,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   498,    -1,    -1,    -1,    -1,   151,
     152,   153,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   516,    -1,    -1,    -1,     6,     7,     8,    -1,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,   105,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   232,
      40,    -1,    -1,    -1,    -1,     6,     7,     8,   597,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    40,
      -1,    -1,    -1,   597,    -1,    -1,    -1,    -1,    -1,    -1,
     291,    -1,    -1,   294,     6,     7,     8,    -1,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    -1,    -1,    -1,   663,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    40,   291,
      -1,    -1,   294,   133,   134,   135,   136,   137,   138,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   663,
     232,   151,   152,   153,     6,     7,     8,    -1,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    -1,   133,   134,   135,   136,   137,   138,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    40,    -1,
     151,   152,   153,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   414,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   133,   134,   135,   136,   137,   138,    -1,   429,    -1,
      -1,    -1,   433,   434,    -1,    -1,    -1,    -1,    -1,   151,
     152,   153,    -1,    -1,    -1,   438,    -1,    -1,    -1,    -1,
      -1,    -1,   414,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   429,    -1,   470,
      -1,   433,   434,    -1,    -1,    -1,   469,    -1,    -1,   472,
      -1,   133,   134,   135,   136,   137,   138,    -1,    -1,    -1,
      -1,   291,   485,    -1,   294,    -1,    -1,   498,    -1,   151,
     152,   153,    -1,    -1,    -1,    -1,    -1,    -1,   470,    -1,
      -1,    -1,    -1,    -1,    -1,   516,    -1,    -1,    -1,   512,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     291,    -1,   525,   294,    -1,    -1,   498,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   537,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   516,    -1,   438,    -1,    -1,     6,
       7,     8,    -1,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    -1,    -1,    -1,   291,
      -1,    -1,   294,    -1,    -1,   578,    -1,   469,    -1,    -1,
     472,    -1,    -1,    40,    -1,    -1,   597,    -1,    -1,    -1,
      -1,    -1,    -1,   485,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   414,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   617,    -1,    -1,    -1,    -1,   429,
      -1,    -1,    -1,   433,   434,   597,   629,    -1,    -1,   291,
      -1,    -1,   294,   525,    -1,    -1,    -1,    -1,   641,   642,
      -1,    -1,    -1,   414,    -1,   537,   649,    -1,    -1,   652,
      -1,    -1,   663,    -1,    -1,    -1,    -1,   660,   429,    -1,
     470,    -1,   433,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   133,   134,   135,   136,
     137,   138,    -1,    -1,    -1,    -1,   578,    -1,   498,    -1,
      -1,   663,   414,    -1,   151,   152,   153,    -1,    -1,   470,
      -1,    -1,    -1,    -1,    -1,    -1,   516,   429,    -1,    -1,
      -1,   433,   483,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   617,    -1,   498,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   629,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   516,    -1,    -1,   470,   641,
     642,    -1,   414,    -1,    -1,    -1,    -1,   649,    -1,    -1,
     652,   483,    -1,    -1,    -1,    -1,    -1,   429,   660,    -1,
      -1,   433,    -1,    -1,    -1,    -1,   498,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   597,    -1,    -1,
      -1,    -1,     7,     8,   516,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,   470,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   483,    -1,    -1,    -1,    40,   597,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   291,    -1,   498,   294,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    -1,    -1,   663,   516,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    40,    -1,
      -1,    -1,    -1,    -1,    -1,   597,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   663,    -1,    -1,    -1,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   133,   134,
     135,   136,   137,   138,    -1,    40,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   597,   151,   152,   153,    -1,
      -1,   663,    -1,    -1,    -1,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    -1,   414,    -1,    -1,
      -1,   133,   134,   135,   136,   137,   138,    -1,    -1,    -1,
      -1,    -1,   429,    40,    -1,    -1,   433,    -1,    -1,   151,
     152,   153,    17,    18,    19,    20,    21,    22,    -1,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    -1,
      -1,   663,    -1,    -1,    -1,    40,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   470,    -1,    -1,    40,    -1,   133,   134,
     135,   136,   137,   138,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   151,   152,   153,    -1,
      -1,   498,    -1,    -1,    -1,    -1,    -1,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    -1,    -1,    -1,   516,
      -1,    -1,    -1,    -1,    -1,    -1,   133,   134,   135,   136,
     137,   138,    -1,    40,    -1,    -1,   291,    -1,    -1,   294,
      -1,    -1,    -1,    -1,   151,   152,   153,    -1,    18,    19,
      20,    -1,    -1,    -1,    24,    25,    26,    27,   133,   134,
     135,   136,   137,   138,    -1,    -1,    -1,    -1,    -1,   133,
     134,   135,   136,   137,   138,    -1,   151,   152,   153,   291,
      -1,    -1,   294,    -1,    -1,    -1,    -1,   151,   152,   153,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     597,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    15,    16,    17,    18,    19,    20,    21,
      22,    -1,    -1,    -1,    -1,    -1,   133,   134,   135,   136,
     137,   138,    -1,    -1,    -1,   105,   291,    -1,    40,   294,
      -1,    -1,    -1,    -1,   151,   152,   153,    -1,    18,    19,
      20,    21,    22,    -1,    -1,    -1,    -1,    -1,    -1,   414,
      -1,    -1,    -1,    -1,    -1,    -1,   663,    -1,    -1,    -1,
      40,    -1,    -1,    -1,   429,    -1,    -1,    -1,   433,    -1,
      -1,    -1,    -1,    -1,   291,    -1,    -1,   294,    -1,    -1,
      18,    19,    20,    -1,    -1,    -1,    24,    25,    26,    27,
      -1,    -1,   414,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   470,   291,   429,    -1,   294,
      -1,   433,    -1,    -1,    -1,    -1,    -1,   291,    -1,    -1,
     294,   133,   134,   135,   136,   137,   138,    -1,    -1,    -1,
      -1,    -1,    -1,   498,    -1,    -1,    -1,    -1,    -1,   151,
     152,   153,    -1,    -1,    -1,    -1,    -1,    -1,   470,   414,
      -1,   516,   232,   133,   134,   135,   136,   137,   138,    -1,
      -1,    -1,    -1,    -1,   429,    -1,    -1,   105,   433,    -1,
      -1,   151,   152,   153,   291,    -1,   498,   294,    -1,    -1,
      18,    19,    20,    -1,    -1,    -1,    24,    25,    26,    27,
      -1,    -1,    -1,    -1,   516,    -1,    -1,   414,    -1,    -1,
      -1,    18,    19,    -1,    -1,   470,    -1,    24,    25,    26,
      27,    -1,   429,    -1,    -1,    -1,   433,    -1,   483,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   414,
      -1,    -1,   597,   498,    -1,    -1,    -1,    -1,    -1,    -1,
     414,    -1,    -1,    -1,   429,    -1,    -1,    -1,   433,    -1,
      -1,   516,    -1,   470,    -1,   429,    -1,    -1,    -1,   433,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   105,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   597,    -1,    -1,    -1,   291,
      -1,   498,   294,    -1,    -1,   470,    -1,    -1,   105,    -1,
      -1,    -1,    -1,    -1,   232,    -1,   470,   414,   663,   516,
      -1,    18,    19,    -1,    -1,    -1,    -1,    24,    25,    26,
      27,   291,   429,   498,   294,    -1,   433,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   498,    -1,    -1,    18,    19,    -1,
      -1,   516,   597,    24,    25,    26,    27,    -1,    -1,    -1,
      -1,   663,   516,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   470,    -1,    -1,    -1,    -1,   438,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     597,   498,    -1,    -1,    -1,    -1,    -1,    -1,   105,   469,
      -1,    -1,   472,    -1,   232,    -1,    -1,    -1,   663,   516,
      -1,    -1,   414,    -1,    -1,   485,    -1,    -1,    -1,    -1,
      -1,    -1,   597,    -1,   105,   232,    -1,   429,    -1,    -1,
      -1,   433,    -1,   597,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   414,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   524,   525,   663,    -1,    -1,   429,
      -1,    -1,    -1,   433,    -1,    -1,    -1,   537,   470,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   663,    -1,
     597,    -1,    -1,    -1,    -1,    -1,   498,    -1,    -1,   663,
     470,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   578,    -1,
     438,    -1,    -1,    -1,   516,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   232,    -1,    -1,   498,    -1,
      -1,    -1,    32,    -1,    -1,    35,    -1,    -1,    -1,    -1,
      -1,   469,    -1,    -1,   472,    -1,   516,   617,    -1,    -1,
      -1,   232,    -1,    -1,    -1,    -1,   663,   485,    -1,   629,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   641,   642,    -1,    -1,    -1,    -1,    -1,    -1,   649,
      -1,    -1,   652,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     660,    -1,    -1,    -1,    -1,   597,   524,   525,    -1,    -1,
      -1,    -1,    -1,    -1,   104,    -1,    -1,    -1,    -1,   537,
     438,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     120,   121,    -1,    -1,    -1,    -1,    -1,   597,    -1,    -1,
     130,   438,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   469,    -1,    -1,   472,    -1,    -1,    -1,    -1,    -1,
     578,    -1,    -1,    -1,    -1,    -1,    -1,   485,    -1,    -1,
      -1,   663,   469,    -1,    -1,   472,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   485,    -1,
      -1,    -1,    45,    46,    47,    48,    49,    50,    -1,   617,
      -1,    -1,    -1,   663,    -1,    -1,    -1,   525,    -1,    -1,
      -1,   629,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   537,
      -1,    -1,    -1,   641,   642,    -1,    -1,   524,   525,    -1,
      -1,   649,    -1,    -1,   652,    -1,    -1,    -1,    -1,    -1,
     537,   438,   660,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     578,    -1,    -1,    -1,    -1,    -1,    -1,   438,    -1,    -1,
      -1,    -1,   469,    -1,    -1,   472,    -1,    -1,    -1,    -1,
      -1,   578,    -1,    -1,    -1,    -1,   139,    -1,   485,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   469,   617,
      -1,   472,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   629,   302,    -1,   485,   512,    -1,    -1,    -1,    -1,
     617,    -1,    -1,   641,   642,    -1,    -1,    -1,   525,    -1,
      -1,   649,   629,    -1,   652,    -1,    -1,    -1,    -1,    -1,
     537,    -1,   660,    -1,   641,   642,    -1,    -1,    -1,    -1,
      -1,   341,   649,    -1,   525,   652,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   660,    -1,    -1,   537,    -1,    -1,    -1,
     360,   361,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   578,    -1,    -1,    -1,    -1,    -1,    -1,   378,    -1,
      -1,   244,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   578,    -1,    -1,
     400,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     617,    -1,   412,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   629,   423,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   641,   642,   617,    -1,   301,    -1,
     440,    -1,   649,    -1,    -1,   652,    -1,    -1,   629,    -1,
     450,    -1,    -1,   660,    -1,    -1,    -1,    -1,    -1,    -1,
     641,   642,    -1,   326,    -1,   465,    -1,    -1,   649,    -1,
      -1,   652,   335,    -1,    -1,    -1,    -1,    -1,    -1,   660,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   505,    -1,    -1,    -1,    -1,
     373,    -1,    -1,   376,    -1,    -1,    -1,    -1,   381,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   389,    -1,   528,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   543,    -1,    -1,    -1,    -1,    -1,    -1,
     550,    -1,    -1,   553,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   574,    -1,    -1,    -1,   578,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   452,
      -1,    -1,    -1,    -1,    -1,   458,    -1,   597,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     473,    -1,    -1,    -1,    -1,   615,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   497,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   657,   521,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   531,   532,
      -1,    -1,    -1,    -1,   537,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   547,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   569,    -1,    -1,   572,
     573,    -1,    -1,    -1,   577,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   634,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     643,    -1,   645
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const unsigned short yystos[] =
{
       0,    30,    34,   116,   278,   399,   448,   479,   508,   777,
     805,   806,   862,  1036,  1090,  1092,  1093,  1094,  1099,  1101,
    1114,  1115,  1116,  1117,  1118,  1551,    28,    29,   778,   779,
     780,   781,   782,    27,  1000,  1566,  1000,    25,  1000,  1466,
    1119,   807,  1466,   806,     0,  1091,  1094,  1117,    31,   780,
     782,   863,   652,    25,   232,   804,   805,   987,  1000,  1005,
    1099,  1114,  1120,  1155,  1156,  1157,  1158,  1159,  1163,   397,
     809,   810,   811,   812,   815,   816,    94,   101,   148,   149,
     156,   410,   436,   506,   598,   678,   686,   777,   783,   955,
    1035,  1095,  1096,  1098,  1102,  1103,  1109,  1121,  1125,  1276,
    1286,  1551,   657,  1000,  1158,   284,   499,   500,  1165,    20,
    1000,  1162,   660,   810,     5,   808,   397,  1000,     5,   834,
     836,   837,  1000,  1287,  1000,  1000,  1277,  1110,  1000,  1000,
    1098,  1104,   302,   341,   360,   361,   400,   412,   423,   440,
     450,   465,   505,   528,   543,   550,   553,   574,   578,   597,
     615,   864,   865,   866,   869,    25,  1155,  1161,    18,    19,
      26,   100,   112,   140,   234,   331,   366,   400,   412,   449,
     464,   472,   485,   529,   554,   578,   622,   631,   716,   717,
     727,   729,   924,   929,   940,   942,  1000,  1155,  1166,  1167,
     500,    14,   861,   812,   563,  1263,   813,   810,   815,    32,
      35,   104,   120,   121,   130,   302,   341,   360,   361,   378,
     400,   412,   423,   440,   450,   465,   505,   528,   543,   550,
     553,   574,   578,   597,   615,   657,   819,   828,   839,   844,
    1000,   472,   155,  1000,   804,   956,  1126,  1000,   871,   361,
     817,   472,   847,   849,   850,   848,   857,   858,   472,   472,
     870,   500,   472,   810,   845,   467,   472,   472,   472,   472,
     472,   472,   472,   472,   472,   472,   727,   472,   801,     9,
      18,    19,    24,    25,    26,   105,   336,   430,   435,   438,
     454,   469,   472,   475,   484,   525,   537,   548,   578,   629,
     641,   642,   649,   660,   898,   906,   907,   908,   909,   910,
     911,   912,   940,   941,   943,  1006,  1155,  1266,  1458,   472,
     472,   472,   472,   472,   472,    18,    19,    20,    21,    22,
     728,    26,   472,   562,     5,   468,  1166,    25,    26,  1000,
    1006,    19,    25,    26,   814,  1006,   710,   711,   712,   818,
     841,   830,   842,   817,   472,   831,   847,   848,   472,   472,
     829,   500,   840,   472,   845,   810,   838,   472,    26,  1000,
     472,  1111,   804,   804,   472,  1000,   472,   499,   823,    26,
     666,   409,   495,   511,   554,   593,   622,   631,   851,   666,
     409,   495,   511,   554,   593,   622,   631,   859,    26,    26,
     872,   873,   874,   875,  1000,    26,   826,   827,    26,   660,
     707,   948,   991,  1000,   991,   991,   948,   948,   898,    25,
      26,    19,    24,    25,    26,   944,   945,   946,   947,    25,
     949,   991,   992,   898,   434,   898,   898,   898,   898,   567,
    1283,   472,   472,   898,   409,   495,   511,   554,   593,   622,
     631,  1461,  1462,   472,   898,   898,   472,   472,   913,   472,
     472,   472,   472,    26,     6,     7,     8,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      40,   133,   134,   135,   136,   137,   138,   151,   152,   153,
     291,   294,   414,   429,   433,   470,   498,   516,   597,   663,
     800,   899,   914,   916,   917,   918,   919,   920,   921,   922,
      26,  1006,   462,   932,   930,   936,   934,  1155,  1155,   727,
     925,  1000,  1167,   500,   468,    26,   821,   472,   843,   810,
     843,   823,    26,   810,    26,    26,   809,   826,   843,    26,
     660,    99,   835,  1288,   434,   472,  1278,  1567,  1568,  1569,
    1570,  1571,   957,  1127,  1105,   660,    26,   434,   852,   853,
     472,   854,   859,   860,   854,   472,   855,     5,   434,     5,
     434,     5,   325,     5,   864,   468,     5,     5,   434,   810,
     846,   472,     5,   434,   500,   660,   434,   434,   434,   434,
     434,   434,   434,   630,   945,    19,    26,   630,   434,     5,
     434,   434,     5,   802,   898,   512,  1482,   898,   472,   666,
      20,   434,  1482,    20,  1266,   898,   898,   898,   898,   898,
     898,   898,   898,   898,   898,   898,   898,   898,   898,   898,
     898,   898,   898,   898,   898,   898,   898,   898,   472,   898,
     898,   472,  1155,   898,   898,   898,   898,   434,     5,   757,
     758,   759,   898,   472,  1166,   500,   664,    26,   660,    26,
     434,   300,     5,   434,     5,   434,   325,   468,     5,   434,
     846,  1000,  1172,  1173,  1175,  1122,  1172,   404,  1568,  1263,
      36,    37,    38,    44,    51,    52,    92,    93,    97,   107,
     108,   110,   124,   131,   142,   145,   146,   160,   162,   163,
     164,   172,   173,   175,   176,   177,   183,   186,   188,   189,
     190,   196,   198,   199,   201,   203,   204,   207,   210,   211,
     212,   213,   214,   215,   219,   220,   221,   223,   227,   229,
     230,   235,   238,   241,   243,   245,   247,   251,   252,   254,
     255,   256,   259,   261,   262,   264,   272,   273,   285,   288,
     289,   292,   293,   296,   297,   305,   306,   307,   309,   319,
     320,   321,   323,   327,   328,   332,   340,   348,   349,   350,
     356,   357,   364,   367,   371,   372,   382,   399,   407,   413,
     424,   443,   445,   446,   453,   492,   503,   510,   534,   535,
     539,   551,   557,   558,   559,   560,   564,   568,   575,   576,
     586,   588,   599,   601,   604,   610,   636,   639,   644,   647,
     648,   662,   669,   692,   693,   694,   695,   696,   697,   698,
     701,   703,   705,   715,   720,   721,   722,   723,   740,   762,
     776,   777,   783,   784,   803,   877,   878,   879,   880,   891,
     892,   893,   894,   895,   896,   897,   950,   981,   985,  1007,
    1009,  1012,  1013,  1014,  1015,  1028,  1037,  1059,  1060,  1062,
    1066,  1081,  1082,  1086,  1087,  1088,  1089,  1097,  1112,  1132,
    1143,  1144,  1145,  1149,  1152,  1188,  1191,  1193,  1199,  1200,
    1203,  1206,  1209,  1211,  1213,  1216,  1223,  1228,  1232,  1233,
    1234,  1246,  1247,  1250,  1256,  1258,  1259,  1284,  1299,  1300,
    1301,  1302,  1303,  1315,  1321,  1322,  1342,  1345,  1374,  1376,
    1467,  1468,  1499,  1500,  1507,  1518,  1542,  1551,  1552,  1557,
    1558,  1560,  1564,  1565,  1572,   777,  1100,   665,   688,  1128,
    1129,  1172,    20,   434,   467,   824,   851,    26,   856,    26,
      26,    26,   873,   875,   867,   827,    26,  1000,   991,   727,
      20,   707,  1000,   938,  1462,   938,    26,    26,   630,    24,
      26,   848,   939,   992,   849,   434,   402,   517,   626,  1490,
     434,   434,    26,  1462,   434,   434,   434,   434,   434,   434,
     434,   483,   483,   483,   923,  1482,   483,   923,  1482,   933,
     931,   937,   935,    26,   926,     5,   927,   468,  1166,   834,
     434,    20,   824,   472,    26,    26,   820,    26,   660,   434,
       5,  1172,   434,  1155,  1155,  1155,    25,  1155,  1210,  1000,
      25,  1000,  1451,   393,  1001,  1002,  1566,  1001,    25,  1000,
    1450,  1000,  1000,  1230,   995,  1001,   995,    25,   232,  1000,
    1164,  1546,  1547,  1548,  1000,  1562,  1451,  1000,    26,   724,
    1155,  1306,   995,  1230,   923,    26,  1006,  1271,  1272,  1271,
     898,   905,  1344,  1450,  1450,   900,   923,  1001,  1508,  1508,
     881,  1230,   995,  1304,  1155,   997,  1001,   905,  1508,  1155,
    1230,  1155,  1343,  1508,    25,   626,  1146,  1147,  1155,   995,
     995,  1146,   996,  1001,  1000,  1147,   995,  1508,   995,   997,
    1451,  1155,  1186,  1187,   993,  1001,   997,   418,   602,   991,
    1061,  1000,   785,  1450,   998,  1001,    25,  1375,  1546,   923,
    1186,   923,  1001,  1212,   951,   174,   182,   191,   194,   237,
     244,   301,   326,   333,   335,   345,   373,   381,   418,   443,
     480,   491,   589,   590,   591,   602,   705,  1075,  1207,  1208,
    1155,  1177,  1178,   904,   905,  1222,   948,   948,   994,  1001,
     923,  1210,  1285,  1155,  1262,    25,  1155,  1502,  1257,   905,
    1553,   147,   197,   234,   331,   408,   449,   515,   741,   929,
    1000,  1155,  1294,   764,   905,   993,   630,  1000,  1008,  1133,
     905,   993,    26,  1155,  1083,   993,   905,  1519,   905,  1271,
    1000,  1010,  1011,   997,  1010,   948,   997,  1010,   948,  1016,
    1010,    25,    26,   427,   528,  1006,  1064,  1155,  1174,  1176,
    1000,   106,   316,   388,   432,   609,   689,   690,   691,   700,
     731,  1018,  1020,  1022,  1024,  1026,  1150,  1151,  1154,   379,
     390,   441,   455,   544,  1377,   680,   681,   959,   960,   961,
    1000,  1130,   687,  1129,   434,   344,   434,   434,   434,   434,
     664,     5,   434,   434,   468,   472,   666,   434,    26,   630,
     666,    18,    19,    20,    25,    26,   105,   438,   469,   472,
     485,   525,   537,   578,   617,   629,   641,   642,   649,   652,
    1000,  1006,  1457,  1459,  1489,  1491,  1492,  1494,  1495,  1496,
    1547,  1550,  1283,   434,  1283,  1283,  1283,  1283,  1283,  1283,
      25,    25,    25,   898,   915,   434,    25,   915,   434,   434,
     434,   434,   434,   434,   434,   759,   757,   468,   344,   810,
     832,   833,   434,   434,   664,   434,  1000,  1289,  1175,   434,
    1279,    95,    96,   125,   126,   127,   496,   582,   625,  1323,
    1324,  1325,  1328,  1331,  1334,  1335,  1336,  1339,   660,   630,
     652,   143,   144,   472,   660,   630,   652,   660,  1548,  1165,
     657,  1204,   660,     8,   665,   468,  1450,   520,  1231,  1174,
     151,   152,   153,   636,   524,   901,   902,   905,  1155,  1181,
    1450,   730,   731,   884,   308,   128,   129,   666,   501,     5,
     659,   666,   658,   658,  1189,   636,   462,     5,   597,  1038,
     501,   699,  1555,   699,   427,   787,  1155,   587,   658,  1194,
    1195,  1196,   370,  1373,   652,   903,   905,   597,   903,     8,
     994,    26,   542,   595,   709,   986,  1155,   986,   986,   986,
      25,   219,   346,   352,   353,   354,   374,   480,   483,   491,
     526,   561,   580,   581,   591,   596,   635,   667,  1079,  1080,
     986,   986,   637,  1076,   731,  1076,  1076,   987,   987,  1076,
    1076,   731,     5,   462,     5,   377,   428,     5,   730,   122,
     123,   580,   667,  1067,   702,  1556,   904,   653,   654,   655,
     656,  1261,  1263,   905,  1252,  1253,  1254,  1264,  1265,   905,
     472,   472,   472,   472,    25,   760,  1000,   472,  1502,   388,
     472,   562,   630,   619,   765,   772,   763,  1000,    25,  1148,
    1155,  1248,     8,  1251,    14,  1000,  1160,  1168,  1169,  1171,
    1179,  1180,  1224,   205,   388,   585,   618,     5,     6,     7,
       8,     9,    10,    12,    13,    14,    18,    19,    20,    21,
      22,    23,    33,    50,   103,   112,   130,   132,   140,   147,
     148,   151,   152,   153,   154,   157,   158,   197,   219,   225,
     232,   234,   239,   265,   303,   316,   322,   331,   332,   338,
     341,   342,   346,   352,   353,   359,   360,   361,   364,   365,
     366,   370,   374,   376,   383,   384,   385,   386,   388,   389,
     393,   394,   396,   397,   398,   399,   400,   401,   402,   408,
     409,   410,   412,   413,   417,   418,   419,   420,   421,   422,
     423,   424,   426,   430,   431,   432,   433,   434,   435,   436,
     437,   438,   439,   440,   441,   442,   443,   444,   445,   446,
     447,   448,   449,   450,   451,   452,   453,   454,   455,   456,
     457,   458,   459,   460,   461,   462,   463,   464,   465,   466,
     468,   469,   472,   473,   474,   475,   476,   477,   478,   479,
     480,   481,   483,   484,   485,   486,   487,   488,   489,   490,
     491,   492,   493,   494,   495,   496,   497,   500,   501,   502,
     503,   504,   505,   506,   507,   508,   510,   511,   512,   513,
     515,   516,   517,   518,   519,   520,   521,   522,   523,   524,
     525,   526,   527,   528,   529,   530,   531,   532,   533,   534,
     535,   536,   537,   538,   539,   540,   541,   542,   543,   544,
     545,   546,   547,   548,   549,   550,   552,   553,   554,   555,
     556,   557,   560,   561,   563,   564,   565,   566,   567,   568,
     569,   570,   571,   572,   573,   574,   575,   576,   577,   578,
     579,   580,   581,   582,   583,   584,   585,   586,   587,   588,
     591,   592,   593,   594,   595,   596,   597,   598,   599,   600,
     601,   602,   603,   604,   605,   606,   607,   608,   609,   610,
     611,   612,   613,   614,   615,   616,   617,   618,   619,   620,
     621,   622,   623,   624,   625,   626,   627,   628,   629,   630,
     631,   632,   633,   634,   635,   636,   637,   638,   639,   640,
     641,   642,   643,   644,   645,   646,   647,   648,   649,   650,
     651,   652,   657,   658,   659,   660,   661,   662,   663,   664,
     665,   666,   667,   678,   686,   691,   695,   698,   699,   700,
     701,   704,   705,   707,   708,   709,  1520,  1521,  1522,  1524,
     616,     5,   699,   699,   903,  1174,  1181,  1063,   462,     5,
     193,  1043,   472,  1155,   903,   472,    26,    26,   106,  1153,
      25,  1155,  1506,  1506,  1001,  1357,  1212,   994,   161,   263,
     271,   277,   279,   290,   318,   334,   339,   351,   358,   512,
     519,   541,   546,  1346,  1347,  1355,  1364,  1365,  1371,  1372,
    1378,  1379,  1388,  1408,  1412,  1478,  1479,  1509,  1510,  1513,
    1514,  1526,   962,   963,   132,   958,   969,   970,   961,  1131,
    1567,  1106,   500,   864,   827,   660,  1000,   409,   495,   511,
     554,   593,   622,   631,  1463,   938,   630,    24,    26,   852,
    1495,  1495,   409,   495,   511,   554,   593,   622,   631,  1460,
    1464,   512,  1494,   472,   472,   472,   472,   472,   472,   472,
    1000,   472,     5,   587,  1417,  1422,  1000,    18,    19,    20,
      21,   133,   134,   135,   136,   137,   138,  1516,   462,     5,
     434,   434,   928,   500,     5,   434,   834,   804,  1123,   804,
     287,   300,   402,   472,   517,   533,  1392,  1393,  1398,  1400,
     472,  1000,  1340,  1341,    26,   472,  1000,  1320,  1333,  1400,
    1402,   472,  1000,  1330,   472,  1320,  1326,     5,  1000,    25,
    1000,  1000,    25,  1003,  1158,  1000,    25,  1000,  1000,  1548,
    1546,   617,   657,  1205,    20,  1000,  1185,  1549,  1000,  1563,
    1450,   636,   472,   472,   884,  1450,     5,   666,   472,  1546,
      25,  1005,  1229,  1229,  1502,  1146,   905,   905,   905,   988,
     989,   472,  1155,  1187,  1039,  1040,  1041,  1450,   666,  1502,
     948,  1556,  1061,  1155,   786,   665,   905,   394,  1198,   597,
    1197,  1000,     5,  1543,   109,   111,   113,   658,   666,   876,
    1174,   952,    18,    19,   472,  1077,  1079,  1208,  1155,  1178,
     987,   905,   388,   636,    26,    26,   730,   195,  1260,   426,
    1298,  1263,  1254,     5,   658,  1255,  1554,  1000,    25,   948,
     948,   630,   992,   663,  1155,   745,  1000,  1000,   905,   383,
     768,   772,   619,   766,   774,    23,   276,  1135,  1139,   523,
     923,   523,  1249,   905,   499,  1165,   660,     5,  1084,   587,
    1225,  1155,  1523,  1525,   231,  1521,  1029,  1011,   948,   948,
    1021,  1022,  1043,  1043,    39,    41,    42,    43,   312,   315,
     317,   337,   347,   368,   391,   395,   471,  1042,  1044,  1045,
    1071,  1155,  1176,   587,   732,    26,   442,  1027,   365,  1501,
    1501,   180,   181,   478,   587,  1000,  1409,  1410,  1452,  1450,
    1450,  1450,  1348,  1450,  1000,  1511,  1511,  1490,  1450,  1356,
     209,   480,   491,   512,   519,  1381,  1382,  1383,  1567,  1567,
     427,   971,  1155,   682,   683,   964,   965,   966,   522,   665,
     684,   685,   704,   974,   975,  1567,   804,    26,   825,    20,
    1000,   434,   472,    24,    26,   666,  1490,   434,   438,  1517,
    1550,   402,   517,   626,  1441,  1494,  1497,  1441,  1441,  1441,
    1441,   660,  1497,  1492,   556,  1418,  1419,  1420,  1450,   567,
    1416,  1423,   375,   555,   566,  1366,  1485,  1494,  1494,  1494,
    1494,  1547,   898,   434,   825,   833,  1290,   804,  1280,   472,
     472,   472,  1337,  1400,   472,   472,    98,  1338,  1340,     5,
    1332,  1333,   104,   341,   361,   362,   363,   400,   412,   423,
     440,   450,   465,   513,   543,   553,   574,   578,   606,   615,
    1442,  1443,  1444,  1446,  1329,  1330,  1326,  1327,   704,  1324,
     660,   630,   434,   660,   630,   660,  1502,   617,   500,   587,
    1561,   472,   725,   726,  1000,  1307,   923,   901,  1000,  1305,
     657,  1201,   666,     5,     5,     5,   620,   905,     5,   660,
     524,   666,   665,   206,   208,   312,   315,   788,   791,   792,
    1071,   789,   790,  1000,   472,  1001,   689,   690,  1202,   905,
    1450,  1544,  1545,  1000,  1000,   989,   990,   550,   948,   884,
       8,   954,    26,    26,  1078,  1079,  1155,   361,  1217,   106,
     898,  1263,   260,  1265,  1271,  1567,     5,     5,   434,   434,
     761,  1000,   434,  1502,   757,   472,   472,   773,   769,   403,
     767,   905,   383,   770,   774,   637,  1073,  1140,  1136,   405,
    1134,  1135,   903,   666,  1161,    20,  1000,  1170,  1180,    14,
     524,  1226,  1227,  1494,  1550,  1177,  1567,  1023,  1024,   591,
     999,   587,  1054,  1053,  1056,  1055,   991,  1057,   991,  1058,
    1052,  1051,  1049,  1048,  1072,   368,  1045,  1050,   948,    45,
      46,    47,    48,    49,    50,   139,   376,   389,   452,   458,
     497,   521,   531,   532,   537,   547,   569,   572,   573,   577,
     634,   645,   733,   734,  1069,  1070,     5,    26,  1502,   290,
    1155,   512,  1483,  1484,  1502,  1212,  1477,  1479,   141,   141,
     636,  1210,  1411,  1412,   472,  1389,   192,  1423,  1450,   216,
     313,  1515,   660,   666,  1480,  1527,   385,   394,   418,   421,
     438,   542,   595,   602,   994,  1358,  1363,   472,  1384,   665,
       5,   973,  1155,     5,   587,   967,   968,   679,   966,   972,
    1000,   972,   976,   977,   972,   368,   975,  1107,   468,    26,
     409,   495,   511,   554,   593,   622,   631,  1465,  1491,     5,
    1464,   434,     5,  1494,     5,   434,  1494,  1494,  1494,  1494,
    1000,   434,   472,  1420,     5,  1000,  1456,     9,   336,   472,
     484,  1426,  1427,  1428,  1429,  1430,  1434,  1438,  1440,  1494,
     411,  1414,  1424,  1000,  1486,   659,  1441,   375,   468,   502,
    1273,  1293,  1124,   502,  1235,  1267,   652,  1000,  1395,  1397,
    1450,  1454,  1455,  1399,  1454,  1399,     5,   434,  1338,  1399,
    1426,  1000,   434,  1341,     5,   434,   472,   472,   472,  1464,
    1464,   472,   472,   472,   472,   472,   248,   249,   250,   442,
    1401,  1403,     5,   434,     5,   434,  1000,  1000,    25,  1000,
    1000,    25,  1000,  1549,     8,  1502,  1166,   905,  1000,  1317,
    1318,     5,  1319,  1320,   923,  1113,   660,  1319,   617,  1502,
    1502,   905,   905,   988,   550,   905,  1559,     5,  1040,    20,
    1454,  1502,   789,   797,   796,   798,  1000,  1004,   799,  1004,
     233,   792,   795,     5,  1043,   660,   905,     8,   660,     5,
    1000,   923,   594,  1361,     5,   434,  1155,     5,    26,  1155,
     369,    25,  1295,   388,   388,   500,   660,   388,   472,   746,
     750,   743,  1567,  1567,   775,   771,   767,  1074,    25,   999,
    1141,  1155,  1567,   905,   467,   500,   923,     5,  1030,  1025,
    1026,    26,   730,  1000,  1567,  1567,  1567,  1567,     5,  1046,
       5,  1047,  1567,  1567,  1567,  1567,  1077,  1567,   999,    25,
      14,    14,     5,   434,    26,  1450,  1490,  1471,   636,   636,
    1347,  1476,  1477,  1412,  1390,  1454,   657,   994,   472,  1351,
    1000,  1512,  1511,  1491,    86,    87,    88,    89,    90,   624,
    1530,   905,   905,   594,  1359,   994,  1385,  1454,  1450,  1383,
       5,  1155,   972,  1567,  1567,     5,   979,   980,  1567,  1567,
     978,  1100,   868,   434,   472,  1422,  1464,   666,  1464,   434,
    1494,   434,   434,   434,   434,  1419,  1421,  1419,  1429,   472,
    1489,  1426,  1494,  1489,     6,     7,     9,    10,    12,    13,
      14,    15,    16,    17,   294,   414,   415,   470,   597,   663,
     713,   714,  1437,  1439,  1415,  1493,  1494,   489,  1413,  1425,
     310,  1316,    26,  1367,  1368,  1369,  1454,  1483,  1486,   822,
     114,   115,   117,   118,   119,   218,   226,   260,   269,   298,
     299,   343,   387,   442,   668,   669,   670,   671,   672,   673,
     674,   675,   676,   677,  1270,  1274,   179,   555,  1275,  1291,
    1100,   202,   217,   218,   226,   260,   269,   298,   343,   387,
    1268,  1269,  1281,  1275,  1455,   500,  1453,   434,     5,   660,
       5,   434,   434,  1400,   434,   434,  1333,    26,  1447,  1447,
      26,   666,   472,   666,    26,  1448,    26,    26,  1448,  1448,
      25,  1457,   200,   300,   338,   402,   416,   517,   533,  1394,
    1404,  1405,  1406,  1407,  1330,  1326,   660,   660,  1502,     8,
     468,   579,   628,     5,   434,   726,     5,   434,   903,   434,
      20,   434,  1502,     5,   905,   607,   316,   735,   736,   905,
    1043,  1567,  1567,     5,   793,   500,   660,     5,   794,  1567,
     790,   587,    20,  1000,     5,  1000,  1192,    20,  1454,  1545,
     432,   699,   903,  1362,   953,  1079,   708,  1215,   898,     5,
     757,  1155,   742,   724,  1000,  1155,   748,   434,   757,   757,
    1567,  1567,  1077,  1138,    25,  1142,  1155,   612,   984,  1166,
     524,   904,  1085,  1227,   103,   583,  1031,  1017,  1018,   660,
     991,  1567,   991,  1567,   730,    26,  1155,    26,  1155,   734,
     434,   472,  1503,  1491,  1477,  1477,  1469,     5,   434,   512,
    1488,  1352,  1454,   520,  1349,  1488,   666,  1481,    18,    19,
     105,   469,   472,   485,   524,   525,   537,   578,   617,   629,
     641,   642,   649,   652,  1000,  1457,  1489,  1535,  1536,  1537,
    1538,  1539,  1540,  1550,  1535,  1535,  1535,  1454,  1532,  1534,
    1531,  1532,  1533,  1528,  1360,     5,   434,   666,  1155,  1000,
    1567,  1567,  1567,  1567,   664,    26,   434,   666,  1465,   666,
       5,   434,   434,  1427,  1428,  1432,  1495,  1432,   472,  1489,
    1432,   472,  1489,  1432,    10,   291,   429,   431,  1494,     5,
    1426,     5,   579,   628,  1370,  1316,   664,  1271,  1271,  1271,
      25,  1271,  1271,  1271,  1271,  1271,  1271,    25,    25,  1271,
    1274,  1155,  1182,  1183,   659,   488,  1236,  1567,    25,    25,
      26,    26,    26,    26,    26,    25,  1155,  1269,  1236,    26,
    1394,  1454,    20,  1000,  1454,  1338,   434,   434,     5,   434,
    1465,    26,  1465,     5,  1445,     5,   434,   434,   434,  1445,
    1396,  1450,   472,  1406,  1338,  1000,  1000,  1502,  1318,   663,
     718,  1312,  1313,  1314,  1320,    53,   126,   127,   286,   663,
    1308,  1309,  1310,   509,   883,  1308,     5,   417,  1502,     5,
     472,   434,   591,  1068,  1004,  1567,   727,    20,  1000,  1004,
    1567,   948,   905,   948,  1177,  1567,    26,   999,    25,  1296,
    1174,   468,   757,   747,   751,   434,  1567,   999,   905,   982,
     468,  1033,  1032,   482,  1019,  1020,    20,  1000,  1504,  1505,
     594,  1487,  1472,  1470,  1454,  1490,   184,  1391,     5,   434,
    1350,  1512,  1487,  1538,  1538,  1537,   472,   472,   472,   472,
     472,   472,   472,  1000,   472,     5,   434,    18,    19,    20,
      21,  1516,   434,     5,   434,     5,    14,   192,   567,  1529,
    1177,  1454,   504,  1386,  1387,  1452,   253,  1108,   864,   434,
    1465,  1465,  1419,   483,  1431,  1431,  1435,  1436,  1457,  1550,
    1431,  1435,  1431,  1432,  1494,  1493,  1368,   834,   579,   628,
    1184,     5,  1182,   102,   178,   240,   242,   258,   266,   270,
     295,  1237,  1238,  1292,  1108,  1282,     5,   468,  1453,    26,
     434,    26,  1449,   434,    26,   434,   472,  1426,  1311,  1566,
      26,  1314,    26,    26,  1311,  1316,  1310,   991,   730,   417,
    1502,   905,   737,   609,  1190,    26,   730,   468,  1068,   434,
     282,   730,   434,   434,   472,   749,   388,   755,   434,   744,
    1137,  1567,   500,   905,  1567,   999,     5,   434,  1177,  1422,
    1491,  1454,   472,  1422,   434,  1517,  1441,  1537,  1541,  1441,
    1441,  1441,  1441,   660,  1541,  1536,  1537,  1537,  1537,  1537,
    1532,    14,  1533,  1536,   994,  1426,     5,   185,  1380,  1433,
    1457,  1498,     5,   434,   434,  1431,     7,  1183,  1239,  1240,
    1155,  1242,  1155,  1241,  1243,  1238,   281,   281,    26,   434,
     666,   434,  1397,   434,   882,  1502,   435,   244,   301,   326,
     335,   373,   381,   473,   643,   734,   738,   739,   472,   660,
     730,  1214,  1297,   752,   434,  1174,   755,   755,  1567,   983,
    1166,   616,  1065,  1505,  1485,  1422,   524,  1353,  1354,  1494,
    1485,   434,  1537,     5,   434,  1537,  1537,  1537,  1537,  1000,
     434,   472,  1387,  1436,  1494,  1567,  1567,  1244,  1567,  1245,
    1567,  1567,   468,  1465,   434,   280,   391,   395,   885,   886,
     887,  1071,   986,   986,   986,   986,   986,   986,    25,     5,
     434,   905,    20,  1000,  1071,  1218,  1219,  1220,   755,   757,
     755,   283,   468,  1034,   730,     5,   434,   329,   330,  1473,
     434,  1537,   434,   434,   434,   434,  1535,  1567,  1567,   889,
     888,   280,   887,   890,   739,     5,  1221,   324,  1220,   753,
    1567,  1354,    25,  1000,  1474,  1475,   434,  1567,  1567,  1567,
     905,  1567,   434,  1031,   660,   660,     5,   434,   754,  1000,
    1000,  1475,   205,   388,   756,   660,  1174,  1000
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
#line 987 "fgl.yacc"
    { print_screen_mode(0);}
    break;

  case 3:
#line 990 "fgl.yacc"
    { print_screen_mode(1);}
    break;

  case 4:
#line 994 "fgl.yacc"
    {
		print_start_server(yyvsp[-3].str,yyvsp[0].str);
	}
    break;

  case 5:
#line 1000 "fgl.yacc"
    {
	print_stop_external();
	}
    break;

  case 6:
#line 1005 "fgl.yacc"
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
#line 1017 "fgl.yacc"
    {
	sprintf(yyval.str,"%s%s",yyvsp[-2].str,yyvsp[0].str);
	}
    break;

  case 10:
#line 1022 "fgl.yacc"
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
#line 1045 "fgl.yacc"
    {sprintf(yyval.str,"(%s)",yyvsp[-1].str);}
    break;

  case 12:
#line 1046 "fgl.yacc"
    { sprintf(yyval.str,"%s%s%s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 13:
#line 1047 "fgl.yacc"
    {sprintf(yyval.str,"%d",atoi(yyvsp[0].str));}
    break;

  case 14:
#line 1048 "fgl.yacc"
    {sprintf(yyval.str,"(%s%s)",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 15:
#line 1049 "fgl.yacc"
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
#line 1060 "fgl.yacc"
    {
	sprintf(yyval.str,print_arr_expr_fcall(yyvsp[0].ptr));
}
    break;

  case 17:
#line 1066 "fgl.yacc"
    {strcpy(yyval.str,"+");}
    break;

  case 18:
#line 1067 "fgl.yacc"
    {strcpy(yyval.str,"-");}
    break;

  case 19:
#line 1068 "fgl.yacc"
    {strcpy(yyval.str,"*");}
    break;

  case 20:
#line 1069 "fgl.yacc"
    {strcpy(yyval.str,"/");}
    break;

  case 21:
#line 1070 "fgl.yacc"
    {strcpy(yyval.str,"%");}
    break;

  case 22:
#line 1075 "fgl.yacc"
    {strcpy(yyval.str,"+");}
    break;

  case 23:
#line 1076 "fgl.yacc"
    {strcpy(yyval.str,"-");}
    break;

  case 24:
#line 1087 "fgl.yacc"
    {
	 A4GL_debug("Using default attribute of WHITE");
		sprintf(yyval.str,"%d",0);}
    break;

  case 25:
#line 1090 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 26:
#line 1093 "fgl.yacc"
    {start_state("attribute",1);}
    break;

  case 27:
#line 1093 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[-1].str);
A4GL_debug("Got Attributes : %s",yyvsp[-1].str);
start_state("attribute",0);
}
    break;

  case 29:
#line 1100 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 30:
#line 1101 "fgl.yacc"
    {
sprintf(yyval.str,"%d",atoi(yyvsp[-2].str)|atoi(yyvsp[0].str));
}
    break;

  case 31:
#line 1107 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("BLACK"));}
    break;

  case 32:
#line 1108 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("BLUE"));}
    break;

  case 33:
#line 1109 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("CYAN"));}
    break;

  case 34:
#line 1110 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("GREEN"));}
    break;

  case 35:
#line 1111 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("MAGENTA"));}
    break;

  case 36:
#line 1112 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("RED"));}
    break;

  case 37:
#line 1113 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("WHITE"));}
    break;

  case 38:
#line 1114 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("YELLOW"));}
    break;

  case 39:
#line 1115 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("REVERSE"));}
    break;

  case 40:
#line 1116 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("BLINK"));}
    break;

  case 41:
#line 1117 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("UNDERLINE"));}
    break;

  case 42:
#line 1118 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("BOLD"));}
    break;

  case 43:
#line 1119 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("NORMAL"));}
    break;

  case 44:
#line 1120 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("INVISIBLE"));}
    break;

  case 45:
#line 1121 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("DIM"));}
    break;

  case 46:
#line 1122 "fgl.yacc"
    {inp_flags=inp_flags | 0x1; strcpy(yyval.str,"0");}
    break;

  case 47:
#line 1123 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 50:
#line 1130 "fgl.yacc"
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
#line 1141 "fgl.yacc"
    {start_state("attribute",0);strcpy(yyval.str,"");
}
    break;

  case 52:
#line 1145 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 53:
#line 1146 "fgl.yacc"
    {sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 54:
#line 1150 "fgl.yacc"
    { 
/*printf("Window attribute = %s\n",$<str>1);*/
form_attrib.attrib      =form_attrib.attrib|atoi(yyvsp[0].str);
/*printf("Window attribute = %d\n",form_attrib.attrib);*/
}
    break;

  case 55:
#line 1156 "fgl.yacc"
    { form_attrib.border      =1;}
    break;

  case 56:
#line 1158 "fgl.yacc"
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
#line 1169 "fgl.yacc"
    { form_attrib.comment_line=atoi(yyvsp[0].str); }
    break;

  case 58:
#line 1171 "fgl.yacc"
    { form_attrib.form_line   =atoi(yyvsp[0].str); }
    break;

  case 59:
#line 1173 "fgl.yacc"
    { form_attrib.error_line  =atoi(yyvsp[0].str); }
    break;

  case 60:
#line 1175 "fgl.yacc"
    { form_attrib.menu_line   =atoi(yyvsp[0].str); 
A4GL_debug("Set menu line to %s",yyvsp[0].str);
}
    break;

  case 61:
#line 1179 "fgl.yacc"
    { form_attrib.message_line=atoi(yyvsp[0].str); }
    break;

  case 62:
#line 1181 "fgl.yacc"
    { form_attrib.prompt_line =atoi(yyvsp[0].str); }
    break;

  case 63:
#line 1242 "fgl.yacc"
    {strcpy(yyval.str,"CALL");}
    break;

  case 64:
#line 1246 "fgl.yacc"
    { A4GL_debug("print_expr (3)"); 
		print_expr(yyvsp[-2].ptr);
		print_pop_variable(yyvsp[0].str);
	}
    break;

  case 65:
#line 1250 "fgl.yacc"
    {
        if (!isin_command("INPUT")&&!isin_command("CONSTRUCT")) {
                a4gl_yyerror("get_fldbuf can only be used in an input or construct");
                YYERROR;
        }
	print_getfldbuf(field_name_list_as_char(yyvsp[-2].field_list));
	}
    break;

  case 66:
#line 1257 "fgl.yacc"
    {
		print_returning();
	}
    break;

  case 67:
#line 1260 "fgl.yacc"
    {
	print_form_is_compiled(yyvsp[-5].str,yyvsp[-3].str,yyvsp[-1].str);
	}
    break;

  case 68:
#line 1264 "fgl.yacc"
    {
		print_field_func('I',field_name_as_char(yyvsp[-3].field_entry),yyvsp[0].str);
   }
    break;

  case 70:
#line 1268 "fgl.yacc"
    { 
        if (!isin_command("INPUT")&&!isin_command("CONSTRUCT")) {
                a4gl_yyerror("get_fldbuf can only be used in an input or construct");
                YYERROR;
        }
	print_field_func('T',field_name_list_as_char(yyvsp[-3].field_list),yyvsp[0].str);
   }
    break;

  case 71:
#line 1275 "fgl.yacc"
    {
	new_counter();
   	addmap("Call",yyvsp[-3].str,curr_func,yylineno,infilename);
   }
    break;

  case 72:
#line 1281 "fgl.yacc"
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
#line 1290 "fgl.yacc"
    {
	print_returning();
	/* strcpy($<str>$,$<str>5); */
   }
    break;

  case 74:
#line 1294 "fgl.yacc"
    {
	new_counter();
   	addmap("Call",yyvsp[-1].str,curr_func,yylineno,infilename);
   }
    break;

  case 75:
#line 1299 "fgl.yacc"
    {
 A4GL_debug("Got args");
   }
    break;

  case 76:
#line 1303 "fgl.yacc"
    {
	int a;
	dump_expr(yyvsp[-2].ptr);
	a=get_counter_val();
	drop_counter();
  	print_func_call(yyvsp[-5].str,yyvsp[-2].ptr,a);
   }
    break;

  case 77:
#line 1311 "fgl.yacc"
    {
	print_returning();
	/* strcpy($<str>$,$<str>5);  */
   }
    break;

  case 78:
#line 1315 "fgl.yacc"
    {
	A4GLSQL_set_status(0,0);
	new_counter();
	}
    break;

  case 79:
#line 1319 "fgl.yacc"
    {
   sprintf(yyval.str,"%d",get_counter_val());drop_counter();
}
    break;

  case 80:
#line 1321 "fgl.yacc"
    {
        print_expr ((struct expr_str *)yyvsp[-3].ptr);  
	print_call_shared(yyvsp[-6].str,yyvsp[-8].str,atoi(yyvsp[-2].str));
	print_returning();
	print_end_call_shared();
}
    break;

  case 81:
#line 1327 "fgl.yacc"
    {
	sprintf(yyval.str,"\"%s\",\"%s\"",yyvsp[-3].str,yyvsp[-1].str);
	A4GLSQL_set_status(0,0);
	new_counter();
	}
    break;

  case 82:
#line 1332 "fgl.yacc"
    {
   	sprintf(yyval.str,"%d",get_counter_val());drop_counter();
}
    break;

  case 83:
#line 1335 "fgl.yacc"
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
#line 1351 "fgl.yacc"
    {
   char buff[256];
   new_counter();
   sprintf(buff,"%s:%s(%p)",yyvsp[-6].str,yyvsp[-4].str,yyvsp[-2].str);
   addmap("External",buff,curr_func,yylineno,infilename);
   }
    break;

  case 85:
#line 1358 "fgl.yacc"
    {
   sprintf(yyval.str,"%d",get_counter_val());drop_counter();
   }
    break;

  case 86:
#line 1362 "fgl.yacc"
    {
	 A4GL_debug("print_expr (6)");print_expr(yyvsp[-2].ptr);
   }
    break;

  case 87:
#line 1366 "fgl.yacc"
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
#line 1388 "fgl.yacc"
    {start_bind('i',0);strcpy(yyval.str,"0");}
    break;

  case 89:
#line 1388 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);
}
    break;

  case 90:
#line 1392 "fgl.yacc"
    {start_bind('i',0);strcpy(yyval.str,"0");}
    break;

  case 91:
#line 1393 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 92:
#line 1394 "fgl.yacc"
    {strcpy(yyval.str,"WITHOUT WAITING"); }
    break;

  case 93:
#line 1399 "fgl.yacc"
    {
			yyval.ptr=A4GL_new_expr("");
		}
    break;

  case 94:
#line 1402 "fgl.yacc"
    {
			yyval.ptr=yyvsp[0].ptr;
		}
    break;

  case 95:
#line 1408 "fgl.yacc"
    {
	yyval.ptr=yyvsp[0].ptr;
}
    break;

  case 96:
#line 1411 "fgl.yacc"
    {
		yyval.ptr=A4GL_append_expr_expr(yyvsp[-2].ptr,yyvsp[0].ptr);
}
    break;

  case 99:
#line 1423 "fgl.yacc"
    {
sprintf(yyval.str,"\"%s\"",yyvsp[0].str);
}
    break;

  case 100:
#line 1429 "fgl.yacc"
    {
sprintf(yyval.str,"\"%s\"",yyvsp[0].str);
}
    break;

  case 101:
#line 1432 "fgl.yacc"
    { sprintf(yyval.str,"\"%s.%s\"",yyvsp[-2].str,yyvsp[0].str); }
    break;

  case 102:
#line 1447 "fgl.yacc"
    {
push_blockcommand("CASE");
setinc(1);
A4GL_incprint();
print_case(1);
setinc(1);
}
    break;

  case 103:
#line 1457 "fgl.yacc"
    {
print_after_when(0);
pop_blockcommand("CASE");
}
    break;

  case 104:
#line 1463 "fgl.yacc"
    {  push_blockcommand("CASE"); 
setinc(1);
A4GL_incprint(); 
print_case(0);
setinc(1);
}
    break;

  case 105:
#line 1472 "fgl.yacc"
    {
print_after_when(0);
pop_blockcommand("CASE");
}
    break;

  case 110:
#line 1485 "fgl.yacc"
    {setinc(-1);A4GL_incprint();}
    break;

  case 112:
#line 1488 "fgl.yacc"
    {
A4GL_incprint();
}
    break;

  case 113:
#line 1490 "fgl.yacc"
    {A4GL_incprint();
print_after_when(0);
}
    break;

  case 115:
#line 1496 "fgl.yacc"
    {A4GL_incprint();}
    break;

  case 116:
#line 1498 "fgl.yacc"
    {A4GL_incprint();
print_after_when(0);
}
    break;

  case 117:
#line 1503 "fgl.yacc"
    {
print_when(0);

A4GL_incprint();
}
    break;

  case 118:
#line 1508 "fgl.yacc"
    {A4GL_incprint();
print_after_when(1);
setinc(-1);}
    break;

  case 119:
#line 1514 "fgl.yacc"
    {
A4GL_incprint();
print_when(1);
}
    break;

  case 120:
#line 1518 "fgl.yacc"
    {A4GL_incprint();
print_after_when(1);
setinc(-1);}
    break;

  case 121:
#line 1533 "fgl.yacc"
    {
  print_close('F',yyvsp[0].str);
 }
    break;

  case 122:
#line 1536 "fgl.yacc"
    {
  print_close('W',yyvsp[0].str);
}
    break;

  case 123:
#line 1539 "fgl.yacc"
    {
  print_close('W',yyvsp[0].str);
}
    break;

  case 124:
#line 1542 "fgl.yacc"
    {
  print_close('D',0);
}
    break;

  case 125:
#line 1545 "fgl.yacc"
    {
  print_close('S',yyvsp[0].str);
}
    break;

  case 126:
#line 1548 "fgl.yacc"
    {
  print_close('C',yyvsp[0].str);
}
    break;

  case 132:
#line 1570 "fgl.yacc"
    {
			A4GL_lex_printc("%s",yyvsp[0].str);
}
    break;

  case 135:
#line 1579 "fgl.yacc"
    {
			A4GL_lex_printc("%s\n",yyvsp[0].str);
}
    break;

  case 136:
#line 1589 "fgl.yacc"
    {
/* This aint used - its filtered by the lexer first... */
	A4GL_lex_printc("FIXME : Comment : %s\n");
}
    break;

  case 137:
#line 1603 "fgl.yacc"
    {
push_blockcommand("CONSTRUCT");
A4GL_new_events();
}
    break;

  case 138:
#line 1608 "fgl.yacc"
    {
	print_construct_1();
}
    break;

  case 139:
#line 1611 "fgl.yacc"
    {
	print_construct_2(yyvsp[-2].str);
A4GL_drop_events();
}
    break;

  case 140:
#line 1620 "fgl.yacc"
    {
	print_construct_3(1,yyvsp[-5].str,0,yyvsp[0].str,atoi(yyvsp[0].str));
	strcpy(yyval.str,A4GL_get_formloop_str(0));
	reset_constr();
}
    break;

  case 141:
#line 1626 "fgl.yacc"
    {
	print_construct_3(0,yyvsp[-7].str,field_name_list_as_char(yyvsp[-2].field_list),yyvsp[0].str,atoi(yyvsp[0].str));
	strcpy(yyval.str,A4GL_get_formloop_str(0));
	reset_constr();
}
    break;

  case 146:
#line 1641 "fgl.yacc"
    {
                push_construct("",yyval.str);
             }
    break;

  case 147:
#line 1645 "fgl.yacc"
    {
                sprintf(yyval.str,"%s.%s",yyvsp[-2].str,yyvsp[0].str);
                push_construct(yyvsp[-2].str,yyvsp[0].str); 
             }
    break;

  case 148:
#line 1650 "fgl.yacc"
    {
                push_construct(yyvsp[-2].str,"*");
             }
    break;

  case 151:
#line 1660 "fgl.yacc"
    { A4GL_add_event(-97,field_name_list_as_or_char(yyvsp[0].field_list)); print_befaft_field_1(field_name_list_as_or_char(yyvsp[0].field_list)); }
    break;

  case 152:
#line 1660 "fgl.yacc"
    { print_befaft_field_2(); }
    break;

  case 153:
#line 1661 "fgl.yacc"
    { A4GL_add_event(-98,field_name_list_as_or_char(yyvsp[0].field_list)); print_befaft_field_1(field_name_list_as_or_char(yyvsp[0].field_list)); }
    break;

  case 154:
#line 1661 "fgl.yacc"
    { print_befaft_field_2(); }
    break;

  case 155:
#line 1662 "fgl.yacc"
    { A4GL_add_onkey_key(yyvsp[0].str); print_onkey_1(yyvsp[0].str); }
    break;

  case 156:
#line 1662 "fgl.yacc"
    { print_onkey_2(); }
    break;

  case 157:
#line 1663 "fgl.yacc"
    { A4GL_add_event(-95,""); print_befaft_field_1("AFTER_INP"); }
    break;

  case 158:
#line 1663 "fgl.yacc"
    { print_befaft_field_2(); }
    break;

  case 159:
#line 1664 "fgl.yacc"
    { A4GL_add_event(-99,""); print_befaft_field_1("BEFORE_INP"); }
    break;

  case 160:
#line 1664 "fgl.yacc"
    { print_befaft_field_2(); }
    break;

  case 161:
#line 1672 "fgl.yacc"
    {
			yyval.field_list=new_field_list();
			yyval.field_list=append_field_to_list(yyval.field_list,yyvsp[0].field_entry);
	}
    break;

  case 162:
#line 1676 "fgl.yacc"
    {
			yyval.field_list=append_field_to_list(yyvsp[-2].field_list,yyvsp[0].field_entry);
	}
    break;

  case 163:
#line 1682 "fgl.yacc"
    {
			yyval.field_list=new_field_list();
			yyval.field_list=append_field_to_list(yyval.field_list,yyvsp[0].field_entry);
	}
    break;

  case 164:
#line 1686 "fgl.yacc"
    {
			yyval.field_list=append_field_to_list(yyvsp[-2].field_list,yyvsp[0].field_entry);
	}
    break;

  case 165:
#line 1701 "fgl.yacc"
    {
        	yyval.ptr=A4GL_new_expr("A4GL_pushop(OP_YEAR);");
	}
    break;

  case 166:
#line 1704 "fgl.yacc"
    {
        	yyval.ptr=A4GL_new_expr("A4GL_pushop(OP_MONTH);");
	}
    break;

  case 167:
#line 1707 "fgl.yacc"
    {
        	yyval.ptr=A4GL_new_expr("A4GL_pushop(OP_DAY);");
	}
    break;

  case 168:
#line 1710 "fgl.yacc"
    {
        	yyval.ptr=A4GL_new_expr("A4GL_pushop(OP_HOUR);");
	}
    break;

  case 169:
#line 1713 "fgl.yacc"
    {
        	yyval.ptr=A4GL_new_expr("A4GL_pushop(OP_MINUTE);");
	}
    break;

  case 170:
#line 1716 "fgl.yacc"
    {
        	yyval.ptr=A4GL_new_expr("A4GL_pushop(OP_SECOND);");
	}
    break;

  case 171:
#line 1725 "fgl.yacc"
    {
			yyval.ptr=A4GL_append_expr_expr(yyvsp[-2].ptr,yyvsp[-1].ptr);
		}
    break;

  case 172:
#line 1733 "fgl.yacc"
    { 
	char buff[50];
	sprintf(buff,"A4GL_push_int(%d);",(19*16)+10); 
	yyval.ptr=A4GL_new_expr(buff);
}
    break;

  case 173:
#line 1738 "fgl.yacc"
    { 
	char buff[50];
	sprintf(buff,"A4GL_push_int(%d);",(atoi(yyvsp[-2].str)*16) +atoi(yyvsp[0].str)  ); 
	yyval.ptr=A4GL_new_expr(buff);
}
    break;

  case 174:
#line 1751 "fgl.yacc"
    {
				print_defer(0);
			}
    break;

  case 175:
#line 1755 "fgl.yacc"
    {
				print_defer(1);
			}
    break;

  case 176:
#line 1770 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 177:
#line 1771 "fgl.yacc"
    {strcpy(yyval.str,"");lastlineno=yylineno;}
    break;

  case 180:
#line 1779 "fgl.yacc"
    {dtypelist[0]=0;A4GL_lex_printcomment("/* define */\n");}
    break;

  case 181:
#line 1779 "fgl.yacc"
    {A4GL_lex_printcomment("/*end def */\n");}
    break;

  case 186:
#line 1788 "fgl.yacc"
    {in_define=1;}
    break;

  case 187:
#line 1788 "fgl.yacc"
    {in_define=0;strcpy(yyval.str,yyvsp[0].str);
                        set_yytext(yyval.str);
                        if (A4GL_bad_identifiers(yyval.str)) {
                                a4gl_yyerror("You can't use this identifier as it is a reserved word in the target language");
                        }
}
    break;

  case 188:
#line 1797 "fgl.yacc"
    { add_constant('c',yyvsp[0].str,yyvsp[-2].str); addmap("Constant",yyvsp[-2].str,curr_func,yylineno,infilename); }
    break;

  case 189:
#line 1798 "fgl.yacc"
    { add_constant('C',yyvsp[0].str,yyvsp[-2].str); addmap("Constant",yyvsp[-2].str,curr_func,yylineno,infilename); }
    break;

  case 190:
#line 1799 "fgl.yacc"
    { add_constant('f',yyvsp[0].str,yyvsp[-2].str);
addmap("Constant",yyvsp[-2].str,curr_func,yylineno,infilename);
 }
    break;

  case 191:
#line 1802 "fgl.yacc"
    { 
add_constant('i',yyvsp[0].str,yyvsp[-2].str);
addmap("Constant",yyvsp[-2].str,curr_func,yylineno,infilename);
 }
    break;

  case 193:
#line 1807 "fgl.yacc"
    { }
    break;

  case 194:
#line 1807 "fgl.yacc"
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
#line 1824 "fgl.yacc"
    {
		sprintf(yyval.str,"-%p",yyvsp[0].str);}
    break;

  case 199:
#line 1828 "fgl.yacc"
    {
/*AF CygWin FIX */
push_name(yyval.str,0);
addmap("Define",yyvsp[0].str,curr_func,yylineno,infilename);
}
    break;

  case 204:
#line 1843 "fgl.yacc"
    {strcpy(yyval.str,"-1");}
    break;

  case 205:
#line 1844 "fgl.yacc"
    {strcpy(yyval.str,"-1");}
    break;

  case 206:
#line 1845 "fgl.yacc"
    {strcpy(yyval.str,"-2");}
    break;

  case 207:
#line 1846 "fgl.yacc"
    {strcpy(yyval.str,"-3");}
    break;

  case 208:
#line 1851 "fgl.yacc"
    {
 A4GL_debug("defines array %s",yyvsp[-1].str);
	push_type(0,0,yyvsp[-1].str);
}
    break;

  case 210:
#line 1857 "fgl.yacc"
    {
 A4GL_debug("defines array %s",yyvsp[0].str);
	push_type(0,0,yyvsp[0].str);
}
    break;

  case 212:
#line 1866 "fgl.yacc"
    {
	push_associate(yyvsp[-5].str,yyvsp[-1].str);
	push_type(0,0,yyvsp[-1].str);
}
    break;

  case 213:
#line 1870 "fgl.yacc"
    {
    /* void pop_associate (char *a); */
	pop_associate(0);

}
    break;

  case 219:
#line 1886 "fgl.yacc"
    {sprintf(yyval.str,"%s][%s][%s",yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str); A4GL_debug("Triplet");}
    break;

  case 220:
#line 1888 "fgl.yacc"
    {sprintf(yyval.str,"%s][%s",yyvsp[-2].str,yyvsp[0].str); A4GL_debug("double");}
    break;

  case 221:
#line 1889 "fgl.yacc"
    {A4GL_debug("Single");}
    break;

  case 223:
#line 1896 "fgl.yacc"
    {push_record();in_record++;}
    break;

  case 224:
#line 1896 "fgl.yacc"
    {pop_record();in_record--;}
    break;

  case 225:
#line 1897 "fgl.yacc"
    {in_record++;push_record();A4GL_debug("Like\n");}
    break;

  case 226:
#line 1898 "fgl.yacc"
    {A4GL_debug("Link Table : %s\n",yyvsp[-2].str);
                  push_rectab(yyvsp[-2].str);
                  pop_record();in_record--;}
    break;

  case 227:
#line 1901 "fgl.yacc"
    {
		push_record();A4GL_debug("Like\n");}
    break;

  case 228:
#line 1903 "fgl.yacc"
    {
		  A4GL_debug("Table:%s\n",yyvsp[-4].str);
		  add_link_to(yyvsp[-4].str,yyvsp[-1].str);
	          A4GL_debug("Push record...\n");
                  push_rectab(yyvsp[-4].str);
                  pop_record();
}
    break;

  case 230:
#line 1913 "fgl.yacc"
    {
	sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 235:
#line 1928 "fgl.yacc"
    {start_state("dtype",1);}
    break;

  case 236:
#line 1928 "fgl.yacc"
    {start_state("dtype",0);}
    break;

  case 240:
#line 1934 "fgl.yacc"
    {push_type("char","1",0);}
    break;

  case 241:
#line 1935 "fgl.yacc"
    {
/* char buff[80]; */
if (atoi(yyvsp[-1].str)==4) {
	addmap("size=4","----",curr_func,yylineno,infilename);
}
push_type("char",yyvsp[-1].str,0);
}
    break;

  case 242:
#line 1942 "fgl.yacc"
    {push_type("char",yyvsp[-1].str,0);}
    break;

  case 243:
#line 1943 "fgl.yacc"
    {push_type("char",yyvsp[-3].str,0);}
    break;

  case 244:
#line 1944 "fgl.yacc"
    {push_type("long",0,0);}
    break;

  case 245:
#line 1945 "fgl.yacc"
    {
A4GL_debug("Using specified type...");
push_dim(yyvsp[0].str);}
    break;

  case 246:
#line 1948 "fgl.yacc"
    {push_type("int",0,0);}
    break;

  case 247:
#line 1949 "fgl.yacc"
    {push_type("form",0,0);}
    break;

  case 248:
#line 1950 "fgl.yacc"
    {push_type("form",0,0);}
    break;

  case 249:
#line 1951 "fgl.yacc"
    { char buff[256];
				sprintf(buff,"%d",16*256+2);
				push_type("fgldecimal",buff,0);
				}
    break;

  case 250:
#line 1955 "fgl.yacc"
    {
				char buff[256];
				sprintf(buff,"%d",atoi(yyvsp[-1].str)*256+2);
				push_type("fgldecimal",buff,0);
}
    break;

  case 251:
#line 1960 "fgl.yacc"
    {
char buff[256];
sprintf(buff,"%d",atoi(yyvsp[-3].str)*256+atoi(yyvsp[-1].str));
push_type("fgldecimal",buff,0);
}
    break;

  case 252:
#line 1965 "fgl.yacc"
    {
			char buff[256];
			sprintf(buff,"%d",16*256+2);
			push_type("fglmoney",buff,0);}
    break;

  case 253:
#line 1969 "fgl.yacc"
    {
		char buff[256];sprintf(buff,"%d",atoi(yyvsp[-1].str)*256+2);
			push_type("fglmoney",buff,0);}
    break;

  case 254:
#line 1972 "fgl.yacc"
    {
char buff[256];
sprintf(buff,"%d",atoi(yyvsp[-3].str)*256+atoi(yyvsp[-1].str));
push_type("fglmoney",buff,0);}
    break;

  case 255:
#line 1976 "fgl.yacc"
    {push_type("double",0,0);}
    break;

  case 257:
#line 1977 "fgl.yacc"
    {push_type("double",0,0);}
    break;

  case 259:
#line 1978 "fgl.yacc"
    {push_type("float",0,0);}
    break;

  case 261:
#line 1979 "fgl.yacc"
    {push_type("fgldate",0,0);}
    break;

  case 262:
#line 1980 "fgl.yacc"
    {push_type("fglbyte",0,0);}
    break;

  case 263:
#line 1981 "fgl.yacc"
    {push_type("fglbyte",0,0);}
    break;

  case 264:
#line 1982 "fgl.yacc"
    {push_type("fgltext",0,0);}
    break;

  case 265:
#line 1983 "fgl.yacc"
    {push_type("fgltext",0,0);}
    break;

  case 266:
#line 1984 "fgl.yacc"
    {
push_type("struct_dtime",yyvsp[0].str,0);
}
    break;

  case 267:
#line 1987 "fgl.yacc"
    {push_type("struct_ival",yyvsp[0].str,0);}
    break;

  case 268:
#line 1988 "fgl.yacc"
    {push_like(yyvsp[0].str);A4GL_lex_printcomment("/*added(XXXXX)\n */");}
    break;

  case 269:
#line 1989 "fgl.yacc"
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

  case 272:
#line 2024 "fgl.yacc"
    {
A4GL_lex_printcomment("/*column like(ZZZ)\n*/"); sprintf(yyval.str,"%s.%s",yyvsp[-2].str,yyvsp[0].str); A4GL_lex_printcomment ("/*set col...(ZZZ)\n*/");}
    break;

  case 273:
#line 2028 "fgl.yacc"
    {A4GL_debug("--->%s\n",yyvsp[0].str);strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 274:
#line 2030 "fgl.yacc"
    {A4GL_debug("--->%s\n",yyvsp[0].str);strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 275:
#line 2032 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 276:
#line 2034 "fgl.yacc"
    {
A4GL_debug("Real datetime %s to %s\n",yyvsp[-2].str,yyvsp[0].str);
sprintf(yyval.str,"%d",(atoi(yyvsp[-2].str)*16)+atoi(yyvsp[0].str)); }
    break;

  case 277:
#line 2039 "fgl.yacc"
    {
	sprintf(yyval.str,"%d",(atoi(yyvsp[-2].str)*16)+atoi(yyvsp[0].str)); 
}
    break;

  case 278:
#line 2043 "fgl.yacc"
    {start_state("dtime_val",1);}
    break;

  case 279:
#line 2043 "fgl.yacc"
    {start_state("dtime_val",0); strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 280:
#line 2047 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 281:
#line 2048 "fgl.yacc"
    {strcpy(yyval.str,"2");}
    break;

  case 282:
#line 2049 "fgl.yacc"
    {strcpy(yyval.str,"3");}
    break;

  case 283:
#line 2050 "fgl.yacc"
    {strcpy(yyval.str,"4");}
    break;

  case 284:
#line 2051 "fgl.yacc"
    {strcpy(yyval.str,"5");}
    break;

  case 285:
#line 2052 "fgl.yacc"
    {strcpy(yyval.str,"6");}
    break;

  case 286:
#line 2054 "fgl.yacc"
    {
A4GL_debug("opt_frac returns %s",yyvsp[0].str);
sprintf(yyval.str,"%d",atoi(yyvsp[0].str)+6); }
    break;

  case 287:
#line 2059 "fgl.yacc"
    {start_state("dtime_val",1);}
    break;

  case 288:
#line 2059 "fgl.yacc"
    { A4GL_debug ("Got end");start_state("dtime_val",0);  strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 289:
#line 2062 "fgl.yacc"
    {
A4GL_debug("Nothing in fraction - assume 2");
strcpy(yyval.str,"2");}
    break;

  case 290:
#line 2064 "fgl.yacc"
    {
A4GL_debug("Read fraction .. ");
A4GL_debug("    %s",yyvsp[-1].str);
strcpy(yyval.str,yyvsp[-1].str);
}
    break;

  case 291:
#line 2070 "fgl.yacc"
    {
A4GL_debug("Nothing in fraction - assume 2");
strcpy(yyval.str,"2");}
    break;

  case 292:
#line 2072 "fgl.yacc"
    {
A4GL_debug("    %s",yyvsp[-1].str);
strcpy(yyval.str,yyvsp[-1].str);
}
    break;

  case 293:
#line 2078 "fgl.yacc"
    {
if (atoi(yyvsp[0].str)>5) {
a4gl_yyerror("Fraction values are between 0 and 5");
YYERROR;
}
}
    break;

  case 294:
#line 2086 "fgl.yacc"
    {start_state("interval_val",1);}
    break;

  case 295:
#line 2086 "fgl.yacc"
    {start_state("interval_val",0); sprintf(yyval.str,"%d",atoi(yyvsp[0].str)*16+atoi(yyvsp[-1].str));}
    break;

  case 296:
#line 2089 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 297:
#line 2090 "fgl.yacc"
    {strcpy(yyval.str,"2");}
    break;

  case 298:
#line 2091 "fgl.yacc"
    {strcpy(yyval.str,"3");}
    break;

  case 299:
#line 2092 "fgl.yacc"
    {strcpy(yyval.str,"4");}
    break;

  case 300:
#line 2093 "fgl.yacc"
    {strcpy(yyval.str,"5");}
    break;

  case 301:
#line 2094 "fgl.yacc"
    {strcpy(yyval.str,"6");}
    break;

  case 302:
#line 2096 "fgl.yacc"
    {
A4GL_debug("opt_frac returns %s",yyvsp[0].str);
sprintf(yyval.str,"%d",atoi(yyvsp[0].str)+6); }
    break;

  case 306:
#line 2117 "fgl.yacc"
    {
              	dim_set_name(yyvsp[0].str);
              }
    break;

  case 310:
#line 2126 "fgl.yacc"
    {dim_push_type("char","1",0);}
    break;

  case 311:
#line 2128 "fgl.yacc"
    {dim_push_type("char",yyvsp[-1].str,0);}
    break;

  case 312:
#line 2130 "fgl.yacc"
    {dim_push_type("char",yyvsp[-1].str,0);}
    break;

  case 313:
#line 2132 "fgl.yacc"
    {dim_push_type("char",yyvsp[-3].str,0);}
    break;

  case 314:
#line 2133 "fgl.yacc"
    {dim_push_type("long",0,0);}
    break;

  case 315:
#line 2134 "fgl.yacc"
    {dim_push_type("integer",0,0);}
    break;

  case 316:
#line 2135 "fgl.yacc"
    {dim_push_type("FORM",0,0);}
    break;

  case 317:
#line 2136 "fgl.yacc"
    {
char buff[256];
sprintf(buff,"%d",16*256+2);
dim_push_type("fgldecimal",buff,0);
}
    break;

  case 318:
#line 2141 "fgl.yacc"
    {

char buff[256];
sprintf(buff,"%d",atoi(yyvsp[-1].str)*256+2);
dim_push_type("fgldecimal",buff,0);
}
    break;

  case 319:
#line 2148 "fgl.yacc"
    {
char buff[256];
sprintf(buff,"%d",atoi(yyvsp[-3].str)*256+atoi(yyvsp[-1].str));
dim_push_type("fgldecimal",buff,0);
}
    break;

  case 320:
#line 2153 "fgl.yacc"
    {dim_push_type("fglmoney",0,0);}
    break;

  case 321:
#line 2155 "fgl.yacc"
    {dim_push_type("fglmoney",0,0);}
    break;

  case 322:
#line 2157 "fgl.yacc"
    {dim_push_type("fglmoney",0,0);}
    break;

  case 323:
#line 2158 "fgl.yacc"
    {dim_push_type("double",0,0);}
    break;

  case 324:
#line 2159 "fgl.yacc"
    {dim_push_type("float",0,0);}
    break;

  case 325:
#line 2160 "fgl.yacc"
    {dim_push_type("fgldate",0,0);}
    break;

  case 326:
#line 2161 "fgl.yacc"
    {dim_push_type("fglbyte",0,0);}
    break;

  case 327:
#line 2162 "fgl.yacc"
    {dim_push_type("fgltext",0,0);}
    break;

  case 328:
#line 2163 "fgl.yacc"
    {
dim_push_type("struct_dtime",yyvsp[0].str,0);
}
    break;

  case 329:
#line 2166 "fgl.yacc"
    {dim_push_type("struct_ival",0,0);}
    break;

  case 330:
#line 2168 "fgl.yacc"
    {dim_push_like(yyvsp[0].str);A4GL_lex_printcomment("/*added(XXXXX)\n */");}
    break;

  case 331:
#line 2174 "fgl.yacc"
    {
A4GL_lex_printcomment("/*column like(ZZZ)\n*/");
sprintf(yyval.str,"%s.%s",yyvsp[-2].str,yyvsp[0].str)
; A4GL_lex_printcomment ("/*set col...(ZZZ)\n*/");}
    break;

  case 332:
#line 2182 "fgl.yacc"
    {
dim_push_type(0,0,yyvsp[-1].str);
}
    break;

  case 334:
#line 2190 "fgl.yacc"
    {
dim_push_associate(yyvsp[-5].str,yyvsp[-1].str);
dim_push_type(0,0,yyvsp[-1].str);
}
    break;

  case 335:
#line 2194 "fgl.yacc"
    {
	/* void dim_pop_associate (char *a); */
	dim_pop_associate(0);
}
    break;

  case 336:
#line 2202 "fgl.yacc"
    {dim_push_record();}
    break;

  case 337:
#line 2203 "fgl.yacc"
    {dim_pop_record();}
    break;

  case 338:
#line 2204 "fgl.yacc"
    {dim_push_record();A4GL_debug("Like\n");}
    break;

  case 339:
#line 2205 "fgl.yacc"
    {A4GL_debug("Table:%s\n",yyvsp[-2].str);
                                  dim_push_rectab(yyvsp[-2].str);
                                  dim_pop_record();}
    break;

  case 345:
#line 2224 "fgl.yacc"
    { dim_push_name(yyval.str,0); }
    break;

  case 346:
#line 2236 "fgl.yacc"
    {
	print_display_line();
		strcpy(yyval.str,A4GL_get_display_str(0,0,0));
	}
    break;

  case 347:
#line 2240 "fgl.yacc"
    {
		strcpy(yyval.str,A4GL_get_display_str(1,0,0)); /* FIXME */
	}
    break;

  case 348:
#line 2243 "fgl.yacc"
    { 
	strcpy(yyval.str,"#error not implemented yet");
	}
    break;

  case 349:
#line 2246 "fgl.yacc"
    { strcpy(yyval.str, A4GL_get_display_str(4,0,0)); }
    break;

  case 350:
#line 2247 "fgl.yacc"
    { strcpy(yyval.str, A4GL_get_display_str(2,field_name_list_as_char(yyvsp[0].field_list),0)); }
    break;

  case 351:
#line 2248 "fgl.yacc"
    { strcpy(yyval.str, A4GL_get_display_str(3,field_name_list_as_char(yyvsp[0].field_list),yyvsp[-2].str)); }
    break;

  case 352:
#line 2249 "fgl.yacc"
    { strcpy(yyval.str, A4GL_get_display_str(5,yyvsp[-1].str,0)); }
    break;

  case 353:
#line 2250 "fgl.yacc"
    { 
	strcpy(yyval.str,"#error not implemented yet");
 }
    break;

  case 354:
#line 2256 "fgl.yacc"
    {
		print_display_by_name(yyvsp[0].str);
                }
    break;

  case 355:
#line 2263 "fgl.yacc"
    { 
				print_display(yyvsp[-1].str,yyvsp[-2].str,yyvsp[0].str);
		}
    break;

  case 356:
#line 2268 "fgl.yacc"
    {
		print_display_form(yyvsp[-1].str,yyvsp[0].str);
	}
    break;

  case 357:
#line 2273 "fgl.yacc"
    {
		push_blockcommand("DISPLAY");
		curr_input_array_attribs.curr_row_display=0;
		}
    break;

  case 358:
#line 2278 "fgl.yacc"
    {
		print_display_array_p1(fgl_add_scope(yyvsp[-6].str,0),yyvsp[-4].str,yyvsp[-1].str,yyvsp[0].str,&curr_input_array_attribs);
	  	A4GL_new_events();
		}
    break;

  case 359:
#line 2282 "fgl.yacc"
    {
		add_continue_blockcommand ("DISPLAY");  
		print_display_array_p2();
		pop_blockcommand("DISPLAY");
	  	A4GL_drop_events();
}
    break;

  case 360:
#line 2291 "fgl.yacc"
    {
strcpy(yyval.str,"0,0");
}
    break;

  case 361:
#line 2293 "fgl.yacc"
    {
	strcpy(yyval.str,field_name_as_char(yyvsp[0].field_entry));
}
    break;

  case 362:
#line 2298 "fgl.yacc"
    {
				sprintf(yyval.str,"0x%lx",atol(yyvsp[0].str));
			}
    break;

  case 368:
#line 2310 "fgl.yacc"
    {
		A4GL_add_event(-11,"");
		print_befaft_field_1("AFT_ROW");
		}
    break;

  case 369:
#line 2314 "fgl.yacc"
    {
		print_befaft_field_2();
	}
    break;

  case 370:
#line 2317 "fgl.yacc"
    {
		A4GL_add_event(-10,"");
		print_befaft_field_1("BEF_ROW");
		}
    break;

  case 371:
#line 2321 "fgl.yacc"
    {
		print_befaft_field_2();
	}
    break;

  case 372:
#line 2324 "fgl.yacc"
    {
		A4GL_add_onkey_key(yyvsp[0].str);
		print_onkey_1(yyvsp[0].str);
		}
    break;

  case 373:
#line 2328 "fgl.yacc"
    {
		print_onkey_2();
	}
    break;

  case 374:
#line 2335 "fgl.yacc"
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

  case 375:
#line 2353 "fgl.yacc"
    {
		print_dealloc_arr(yyvsp[0].str);
	}
    break;

  case 376:
#line 2359 "fgl.yacc"
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

  case 377:
#line 2383 "fgl.yacc"
    {
			print_error(yyvsp[0].str,0);
		}
    break;

  case 378:
#line 2386 "fgl.yacc"
    { 
			print_error(yyvsp[-1].str,1);
	}
    break;

  case 379:
#line 2401 "fgl.yacc"
    {
	print_exit_program(0);
}
    break;

  case 380:
#line 2404 "fgl.yacc"
    {
	print_exit_program(1);
}
    break;

  case 381:
#line 2418 "fgl.yacc"
    { if (in_command("WHILE")) { exit_loop("WHILE"); } else { YYERROR;} }
    break;

  case 382:
#line 2420 "fgl.yacc"
    { if (in_command("INPUT")) { exit_loop("INPUT"); } else { YYERROR;} }
    break;

  case 383:
#line 2422 "fgl.yacc"
    { if (in_command("FOREACH")) { exit_loop("FOREACH"); } else { YYERROR;} }
    break;

  case 384:
#line 2424 "fgl.yacc"
    { if (in_command("FOR")) { exit_loop("FOR"); } else { YYERROR;} }
    break;

  case 385:
#line 2426 "fgl.yacc"
    { if (in_command("CONSTRUCT")) { exit_loop("CONSTRUCT"); } else { YYERROR;} }
    break;

  case 386:
#line 2428 "fgl.yacc"
    { if (in_command("DISPLAY")) { exit_loop("DISPLAY"); } else { YYERROR;} }
    break;

  case 387:
#line 2429 "fgl.yacc"
    {
	if (in_command("MENU")) {
		exit_loop("MENU");
		/* A4GL_lex_printc("cmd_no=-3;continue;\n"); */
	} 
              else YYERROR;}
    break;

  case 388:
#line 2436 "fgl.yacc"
    { if (in_command("CASE")) { exit_loop("CASE"); } else { YYERROR;} }
    break;

  case 389:
#line 2438 "fgl.yacc"
    { if (in_command("PROMPT")) { exit_loop("PROMPT"); } else { YYERROR;} }
    break;

  case 390:
#line 2442 "fgl.yacc"
    { if (in_command("WHILE")) { continue_loop("WHILE");  } else { YYERROR;} }
    break;

  case 391:
#line 2444 "fgl.yacc"
    { if (in_command("INPUT")) { continue_loop("INPUT"); } else { YYERROR;} }
    break;

  case 392:
#line 2446 "fgl.yacc"
    { if (in_command("FOREACH")) { continue_loop("FOREACH");} else { YYERROR;} }
    break;

  case 393:
#line 2448 "fgl.yacc"
    { if (in_command("FOR")) { continue_loop("FOR"); } else { YYERROR;} }
    break;

  case 394:
#line 2450 "fgl.yacc"
    { if (in_command("CONSTRUCT")) { continue_loop("CONSTRUCT"); } else { YYERROR;} }
    break;

  case 395:
#line 2452 "fgl.yacc"
    { if (in_command("DISPLAY")) { continue_loop("DISPLAY"); } else { YYERROR;} }
    break;

  case 396:
#line 2454 "fgl.yacc"
    { if (in_command("MENU")) {  continue_loop("MENU");  } else { YYERROR;} }
    break;

  case 397:
#line 2460 "fgl.yacc"
    { if (in_command("PROMPT")) { continue_loop("PROMPT"); } else { YYERROR;} }
    break;

  case 402:
#line 2477 "fgl.yacc"
    {
	dec_counter();
	yyval.ptr=A4GL_append_expr_expr(yyvsp[-1].ptr,yyvsp[0].ptr);
}
    break;

  case 405:
#line 2483 "fgl.yacc"
    {
	A4GL_debug("Got literal ptr=%p",yyvsp[0].ptr);
}
    break;

  case 406:
#line 2487 "fgl.yacc"
    {
	yyval.ptr=A4GL_new_expr("A4GL_push_int(0);");
	yyval.ptr=A4GL_append_expr_expr(yyval.ptr,yyvsp[0].ptr);
	yyval.ptr=A4GL_append_expr(yyval.ptr,"A4GL_pushop(OP_SUB);");
}
    break;

  case 407:
#line 2492 "fgl.yacc"
    {
	yyval.ptr=yyvsp[0].ptr;
}
    break;

  case 411:
#line 2502 "fgl.yacc"
    { yyval.ptr=A4GL_new_expr("A4GL_add_spaces();"); }
    break;

  case 412:
#line 2503 "fgl.yacc"
    {inc_counter();}
    break;

  case 418:
#line 2509 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_CONCAT);");
}
    break;

  case 419:
#line 2516 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 420:
#line 2516 "fgl.yacc"
    {
strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 422:
#line 2521 "fgl.yacc"
    {yyval.ptr=A4GL_new_expr("A4GL_push_null(2,0)");}
    break;

  case 423:
#line 2525 "fgl.yacc"
    {
	/*set_counter(0);*/
	sprintf(yyval.str,"%d",get_counter_val());
	A4GL_lex_printcomment("/*L1 %s*/\n",yyval.str);
}
    break;

  case 424:
#line 2531 "fgl.yacc"
    {
	sprintf(yyval.str,"%d",get_counter_val());
	A4GL_lex_printcomment("/*L2 %s*/\n",yyval.str);
}
    break;

  case 425:
#line 2539 "fgl.yacc"
    {
	/*set_counter(0);*/
	sprintf(yyval.str,"%d",get_counter_val());
	A4GL_lex_printcomment("/*L1 %s*/\n",yyval.str);
}
    break;

  case 426:
#line 2545 "fgl.yacc"
    {
	sprintf(yyval.str,"%d",get_counter_val());
	A4GL_lex_printcomment("/*L2 %s*/\n",yyval.str);
}
    break;

  case 427:
#line 2554 "fgl.yacc"
    {sprintf(yyval.str,"%d",get_counter_val());}
    break;

  case 428:
#line 2556 "fgl.yacc"
    {
	print_op("OP_CONCAT");
	dec_counter();sprintf(yyval.str,"%d",get_counter_val());
}
    break;

  case 429:
#line 2563 "fgl.yacc"
    {
	A4GL_debug("Print expr (2)");
	print_expr(yyvsp[0].ptr);
}
    break;

  case 430:
#line 2571 "fgl.yacc"
    {
	strcpy(yyval.str,"+");
}
    break;

  case 431:
#line 2575 "fgl.yacc"
    {
	strcpy(yyval.str,"-");
}
    break;

  case 432:
#line 2584 "fgl.yacc"
    {
	
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_NOT);");
}
    break;

  case 433:
#line 2589 "fgl.yacc"
    {
	yyval.ptr=A4GL_new_expr("A4GL_push_int(1);");
        inc_counter();
}
    break;

  case 434:
#line 2594 "fgl.yacc"
    {
	inc_counter();
	yyval.ptr=A4GL_new_expr("A4GL_push_int(0);");
}
    break;

  case 435:
#line 2598 "fgl.yacc"
    { yyval.ptr=yyvsp[-1].ptr; }
    break;

  case 436:
#line 2600 "fgl.yacc"
    {
	yyval.ptr=get_in_exists_sql(yyvsp[-1].sql_string,'E');
}
    break;

  case 437:
#line 2603 "fgl.yacc"
    {
	yyval.ptr=get_in_exists_sql(yyvsp[-1].sql_string,'e');
}
    break;

  case 438:
#line 2610 "fgl.yacc"
    {
	A4GL_debug("init expr %s %s",yyvsp[-1].str,yyvsp[0].str);
	sprintf(yyval.str,"%s%p",yyvsp[-1].str,yyvsp[0].str);
	sprintf(yyval.str,"%s",A4GL_get_push_literal('D',yyval.str));
	yyval.ptr=A4GL_new_expr(yyval.str);
        inc_counter();
}
    break;

  case 439:
#line 2618 "fgl.yacc"
    {
	A4GL_debug("init expr int %s %d",yyvsp[-1].str,atoi(yyvsp[0].str));
	sprintf(yyval.str,"%s%p",yyvsp[-1].str,yyvsp[0].str);
	sprintf(yyval.str,"%s",A4GL_get_push_literal('L',yyval.str));
	yyval.ptr=A4GL_new_expr(yyval.str);
	inc_counter();
}
    break;

  case 440:
#line 2630 "fgl.yacc"
    {
	sprintf(yyval.str,"%s",A4GL_get_push_literal('S',yyvsp[0].str));
	yyval.ptr=A4GL_new_expr(yyval.str);
	inc_counter();
}
    break;

  case 441:
#line 2636 "fgl.yacc"
    {
	sprintf(yyval.str,"%s",A4GL_get_push_literal('D',yyvsp[0].str));
	yyval.ptr=A4GL_new_expr(yyval.str);
	inc_counter();
}
    break;

  case 442:
#line 2642 "fgl.yacc"
    {
	sprintf(yyval.str,"%s",A4GL_get_push_literal('L',yyvsp[0].str));
	yyval.ptr=A4GL_new_expr(yyval.str);
	inc_counter();
}
    break;

  case 445:
#line 2652 "fgl.yacc"
    {
		sprintf(yyval.str,"%s\n%s",yyvsp[-2].str,yyvsp[0].str);
	}
    break;

  case 446:
#line 2658 "fgl.yacc"
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

  case 447:
#line 2730 "fgl.yacc"
    {
	if (doing_a_print) {
		sprintf(yyval.str,"A4GL_%sset_column(&rep);",ispdf());
	} else {
		sprintf(yyval.str,"A4GL_ensure_column();");
	}
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,yyval.str);
	
}
    break;

  case 448:
#line 2741 "fgl.yacc"
    {
	if (doing_a_print) {
		sprintf(yyval.str,"A4GL_%sset_column(&rep);",ispdf());
	} else {
		sprintf(yyval.str,"A4GL_ensure_column();");
	}
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,yyval.str);
}
    break;

  case 449:
#line 2749 "fgl.yacc"
    {
   if (!isin_command("REPORT")) {
   a4gl_yyerror("This can only be done in a report!");
   YYERROR;
} 
insql=0;
	yyval.ptr=A4GL_new_expr(yyvsp[0].str);
}
    break;

  case 450:
#line 2757 "fgl.yacc"
    {insql=1;set_ingroup();}
    break;

  case 451:
#line 2757 "fgl.yacc"
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

  case 452:
#line 2773 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_AND);");
}
    break;

  case 453:
#line 2777 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_OR);");
}
    break;

  case 454:
#line 2783 "fgl.yacc"
    {
	yyval.ptr=yyvsp[0].ptr;
	}
    break;

  case 455:
#line 2786 "fgl.yacc"
    {
		A4GL_debug("Adding to list...");
		yyval.ptr=A4GL_append_expr_expr(yyvsp[-2].ptr,yyvsp[0].ptr);
	}
    break;

  case 456:
#line 2794 "fgl.yacc"
    {
	yyval.ptr=get_in_exists_sql(yyvsp[-1].sql_string,'I');
}
    break;

  case 457:
#line 2798 "fgl.yacc"
    {
	yyval.ptr=get_in_exists_sql(yyvsp[-1].sql_string,'i');
}
    break;

  case 458:
#line 2801 "fgl.yacc"
    {
	char buff[256];
	sprintf(buff,"A4GL_push_int(%d);",length_expr(yyvsp[-1].ptr));
	yyval.ptr=A4GL_append_expr(yyvsp[-1].ptr,buff);
	A4GL_append_expr(yyval.ptr,"A4GL_pushop(OP_IN);");
}
    break;

  case 459:
#line 2807 "fgl.yacc"
    {
	char buff[256];
	sprintf(buff,"A4GL_push_int(%d);",length_expr(yyvsp[-1].ptr));
	yyval.ptr=A4GL_append_expr(yyvsp[-1].ptr,buff);
	A4GL_append_expr(yyval.ptr,"A4GL_pushop(OP_NOTIN);");
}
    break;

  case 460:
#line 2817 "fgl.yacc"
    { 
	strcpy(yyval.str,"A4GL_pushop(OP_ISNULL);");
	yyval.ptr=A4GL_new_expr(yyval.str);
}
    break;

  case 461:
#line 2822 "fgl.yacc"
    {
	strcpy(yyval.str,"A4GL_pushop(OP_ISNOTNULL);");
	yyval.ptr=A4GL_new_expr(yyval.str);
}
    break;

  case 462:
#line 2829 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_push_char(\"\\\\\");A4GL_pushop(OP_MATCHES);");
 }
    break;

  case 463:
#line 2832 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_push_char(\"\\\\\");A4GL_pushop(OP_MATCHES);A4GL_pushop(OP_NOT);");
}
    break;

  case 464:
#line 2835 "fgl.yacc"
    {
	char buff[40];
	sprintf(buff,"A4GL_push_char(%s);A4GL_pushop(OP_MATCHES);",yyvsp[0].str);
	yyval.ptr=A4GL_append_expr(yyvsp[-2].ptr,buff);
 }
    break;

  case 465:
#line 2840 "fgl.yacc"
    {
	char buff[40];
	sprintf(buff,"A4GL_push_char(%s);A4GL_pushop(OP_MATCHES);A4GL_pushop(OP_NOT);",yyvsp[0].str);
	yyval.ptr=A4GL_append_expr(yyvsp[-2].ptr,buff);
}
    break;

  case 466:
#line 2847 "fgl.yacc"
    {
	char buff[40];
	sprintf(buff,"A4GL_push_char(\"\\\\\");A4GL_pushop(OP_LIKE);");
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,buff);
}
    break;

  case 467:
#line 2852 "fgl.yacc"
    {
	char buff[40];
	sprintf(buff,"A4GL_push_char(\"\\\\\");A4GL_pushop(OP_LIKE);A4GL_pushop(OP_NOT);");
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,buff);
}
    break;

  case 468:
#line 2857 "fgl.yacc"
    {
	char buff[40];
	sprintf(buff,"A4GL_push_char(%s);A4GL_pushop(OP_LIKE);",yyvsp[0].str);
	yyval.ptr=A4GL_append_expr(yyvsp[-2].ptr,buff);
}
    break;

  case 469:
#line 2862 "fgl.yacc"
    {
	char buff[40];
	sprintf(buff,"A4GL_push_char(%s);A4GL_pushop(OP_LIKE);A4GL_pushop(OP_NOT);",yyvsp[0].str);
	yyval.ptr=A4GL_append_expr(yyvsp[-2].ptr,buff);
}
    break;

  case 470:
#line 2873 "fgl.yacc"
    {
	strcpy(yyval.str,"A4GL_pushop(OP_CLIP);");
	yyval.ptr=A4GL_new_expr(yyval.str);
	inc_counter();
}
    break;

  case 471:
#line 2881 "fgl.yacc"
    {
	sprintf(yyval.str,"%s A4GL_pushop(OP_USING);",yyvsp[0].str);
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_USING);");
}
    break;

  case 472:
#line 2889 "fgl.yacc"
    {
	A4GL_debug("PLUS in math_expr $<ptr>2 = %p",yyvsp[0].ptr);
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_ADD);");
}
    break;

  case 473:
#line 2894 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_SUB);");
}
    break;

  case 474:
#line 2898 "fgl.yacc"
    {
      sprintf(yyval.str,"%s A4GL_A4GL_pushop(OP_MULT);",yyvsp[0].str);
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_MULT);");
}
    break;

  case 475:
#line 2903 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_DIV);");
}
    break;

  case 476:
#line 2907 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_MOD);");
}
    break;

  case 477:
#line 2911 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_POWER);");
}
    break;

  case 478:
#line 2917 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_EQUAL);");
}
    break;

  case 479:
#line 2920 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_EQUAL);");
}
    break;

  case 480:
#line 2924 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_LESS_THAN);");
}
    break;

  case 481:
#line 2928 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_GREATER_THAN);");
}
    break;

  case 482:
#line 2932 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_NOT_EQUAL);");
}
    break;

  case 483:
#line 2936 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_LESS_THAN_EQ);");
}
    break;

  case 484:
#line 2940 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_GREATER_THAN_EQ);");
}
    break;

  case 485:
#line 2947 "fgl.yacc"
    {
	reset_counter();
}
    break;

  case 486:
#line 2957 "fgl.yacc"
    { 
		addmap("Call",yyvsp[-1].str,curr_func,yylineno,infilename);
		new_counter(); 
		}
    break;

  case 487:
#line 2962 "fgl.yacc"
    { 
		sprintf(yyval.str,"%d",get_counter_val()); 
		A4GL_lex_printcomment("/*function_call_expr2 %s*/\n",yyval.str);
		drop_counter(); 
		}
    break;

  case 488:
#line 2968 "fgl.yacc"
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

  case 489:
#line 2978 "fgl.yacc"
    {
        sprintf(yyval.str,"\"%s\",\"%s\"",yyvsp[-3].str,yyvsp[-1].str);
	A4GL_debug("NEWFORMAT : %s\n",yyval.str);
        A4GLSQL_set_status(0,0);
        new_counter();
}
    break;

  case 490:
#line 2983 "fgl.yacc"
    {
	sprintf(yyval.str,"%d",get_counter_val());  
	drop_counter();
}
    break;

  case 491:
#line 2986 "fgl.yacc"
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

  case 492:
#line 3000 "fgl.yacc"
    {chk4var=1;}
    break;

  case 493:
#line 3000 "fgl.yacc"
    {chk4var=0;}
    break;

  case 494:
#line 3000 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[-2].ptr,"aclfgl_date(1);");
}
    break;

  case 495:
#line 3003 "fgl.yacc"
    {chk4var=1;}
    break;

  case 496:
#line 3003 "fgl.yacc"
    {chk4var=0;}
    break;

  case 497:
#line 3003 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[-2].ptr,"aclfgl_month(1);");
	/* consumes and replaces a fgl_expr_c - so we don't need to dec or inc_counter */
}
    break;

  case 498:
#line 3007 "fgl.yacc"
    {chk4var=1;}
    break;

  case 499:
#line 3007 "fgl.yacc"
    {chk4var=0;}
    break;

  case 500:
#line 3007 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[-2].ptr,"aclfgl_day(1);");
	/* consumes and replaces a fgl_expr_c - so we don't need to dec or inc_counter */
}
    break;

  case 501:
#line 3011 "fgl.yacc"
    {chk4var=1;}
    break;

  case 502:
#line 3011 "fgl.yacc"
    {chk4var=0;}
    break;

  case 503:
#line 3011 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[-2].ptr,"aclfgl_year(1);");
	/* consumes and replaces a fgl_expr_c - so we don't need to dec or inc_counter */
}
    break;

  case 504:
#line 3015 "fgl.yacc"
    {
	char buff[256];
	sprintf(buff,"acli_interval(%s,%s);",yyvsp[-2].str,yyvsp[0].str);
	yyval.ptr=A4GL_new_expr(buff);
	inc_counter();
}
    break;

  case 505:
#line 3021 "fgl.yacc"
    {
	char buff[256];
	sprintf(buff,"acli_datetime(%s,%s);",yyvsp[-2].str,yyvsp[0].str);
	yyval.ptr=A4GL_new_expr(buff);
	inc_counter();
}
    break;

  case 506:
#line 3027 "fgl.yacc"
    {
	char buff[256];
	sprintf(buff,"acli_datetime(\"%s\",%s);",yyvsp[-2].str,yyvsp[0].str);
	yyval.ptr=A4GL_new_expr(buff);
	inc_counter();
}
    break;

  case 507:
#line 3033 "fgl.yacc"
    {
	char buff[256];
	sprintf(buff,"acli_datetime(\"%s:%s\",%s);",yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str);
	yyval.ptr=A4GL_new_expr(buff);
	inc_counter();
}
    break;

  case 508:
#line 3039 "fgl.yacc"
    {
	char buff[256];
	sprintf(buff,"A4GL_isdynarr_allocated(&%s);",yyvsp[-1].str);
        yyval.ptr=A4GL_new_expr(buff);
        inc_counter();
}
    break;

  case 509:
#line 3045 "fgl.yacc"
    { 
        char buff[256];
        sprintf(buff,"A4GL_dynarr_extent(&%s,%d);",yyvsp[-3].str,atoi(yyvsp[-1].str));
        yyval.ptr=A4GL_new_expr(buff);
        inc_counter();
}
    break;

  case 510:
#line 3055 "fgl.yacc"
    {strcpy(yyval.str,"-1");}
    break;

  case 511:
#line 3056 "fgl.yacc"
    {sprintf(yyval.str,"%d",atoi(yyvsp[-2].str)*16+atoi(yyvsp[0].str));}
    break;

  case 514:
#line 3064 "fgl.yacc"
    {
	if (!isin_command("INPUT")&&!isin_command("CONSTRUCT")) { 
   		a4gl_yyerror("get_fldbuf can only be used in an input or construct");
   		YYERROR;
	}
sprintf(yyval.str,"{int _retvars;\n_retvars=A4GL_fgl_getfldbuf(_sio,_inp_io_type,%s,0,0);\nif (_retvars != 1 ) {A4GLSQL_set_status(-3001,0);A4GL_chk_err(%d,\"%s\");}\n}\n",
	field_name_list_as_char(yyvsp[-1].field_list), lastlineno,infilename); 
	yyval.ptr=A4GL_new_expr(yyval.str);	
	inc_counter();

}
    break;

  case 515:
#line 3075 "fgl.yacc"
    {sprintf(yyval.str,"A4GL_push_int(A4GL_fgl_fieldnametoid(\"\",%s));",field_name_as_char(yyvsp[-1].field_entry)); yyval.ptr=A4GL_new_expr(yyval.str); }
    break;

  case 516:
#line 3076 "fgl.yacc"
    {
sprintf(yyval.str,"A4GL_push_int(A4GL_fgl_fieldnametoid(\"\",%s));",field_name_as_char(yyvsp[-1].field_entry)); yyval.ptr=A4GL_new_expr(yyval.str); 
addmap("Get Field",field_name_as_char(yyvsp[-1].field_entry),curr_func,yylineno,infilename);
	inc_counter();
}
    break;

  case 517:
#line 3082 "fgl.yacc"
    {
/* Informix allows this outside of a input/construct... */
	if (isin_command("INPUT")&&!isin_command("CONSTRUCT")) { 
		sprintf(yyval.str,"A4GL_push_int(A4GL_fgl_infield(_sio,_inp_io_type,%s,0,0));",field_name_list_as_char(yyvsp[-1].field_list)); 
	} else {
		sprintf(yyval.str,"A4GL_push_int(A4GL_fgl_infield(0,0,%s,0,0));",field_name_list_as_char(yyvsp[-1].field_list)); 
	}
	yyval.ptr=A4GL_new_expr(yyval.str);
	inc_counter();
}
    break;

  case 518:
#line 3093 "fgl.yacc"
    { 
	if (!isin_command("INPUT")&&!isin_command("CONSTRUCT")) { 
   		a4gl_yyerror("field_touched can only be used in an input or construct");
   		YYERROR;
	}
	sprintf(yyval.str,"A4GL_push_int(A4GL_fgl_fieldtouched(_sio,_inp_io_type,%s,0,0));",field_name_list_as_char(yyvsp[-1].field_list)); 
	yyval.ptr=A4GL_new_expr(yyval.str);
	inc_counter();
}
    break;

  case 519:
#line 3103 "fgl.yacc"
    { 
	if (!isin_command("INPUT")&&!isin_command("CONSTRUCT")) { 
   		a4gl_yyerror("field_touched can only be used in an input or construct");
   		YYERROR;
	}
	sprintf(yyval.str,"A4GL_push_int(!A4GL_fgl_fieldtouched(_sio,_inp_io_type,%s,0,0));",field_name_list_as_char(yyvsp[-1].field_list)); 
	yyval.ptr=A4GL_new_expr(yyval.str);
	inc_counter();
}
    break;

  case 522:
#line 3116 "fgl.yacc"
    {
		inc_counter();
               sprintf(yyval.str,"A4GL_push_current(%s);",yyvsp[0].str);
		yyval.ptr=A4GL_new_expr(yyval.str);
          	}
    break;

  case 523:
#line 3121 "fgl.yacc"
    { inc_counter(); strcpy(yyval.str,"A4GL_push_today();");
		yyval.ptr=A4GL_new_expr(yyval.str);
		}
    break;

  case 524:
#line 3128 "fgl.yacc"
    { 
	yyval.ptr=A4GL_append_expr(yyvsp[-1].ptr,"A4GL_upshift_stk();");
}
    break;

  case 525:
#line 3132 "fgl.yacc"
    { 
	yyval.ptr=A4GL_append_expr(yyvsp[-1].ptr,"A4GL_downshift_stk();");
}
    break;

  case 526:
#line 3135 "fgl.yacc"
    { 
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_push_ascii();");
}
    break;

  case 527:
#line 3138 "fgl.yacc"
    { 
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"aclfgli_extend();"); }
    break;

  case 528:
#line 3144 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[-1].ptr,"A4GL_push_double(-1);A4GL_pushop(OP_MULT);");
}
    break;

  case 529:
#line 3147 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[-1].ptr,"A4GL_push_double(-28.3465);A4GL_pushop(OP_MULT);");
}
    break;

  case 530:
#line 3150 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[-1].ptr,"A4GL_push_double(-72.0);A4GL_pushop(OP_MULT);");
}
    break;

  case 531:
#line 3167 "fgl.yacc"
    {
	strcpy(yyval.str,yyvsp[0].str);
}
    break;

  case 532:
#line 3170 "fgl.yacc"
    {
	strcpy(yyval.str,yyvsp[0].str);
}
    break;

  case 533:
#line 3176 "fgl.yacc"
    {sprintf(yyval.str,"-%s",yyvsp[0].str);}
    break;

  case 534:
#line 3177 "fgl.yacc"
    {sprintf(yyval.str,"\"%s\"",yyvsp[0].str);}
    break;

  case 535:
#line 3178 "fgl.yacc"
    {sprintf(yyval.str,"\"%s\"",yyvsp[0].str);}
    break;

  case 537:
#line 3183 "fgl.yacc"
    {sprintf(yyval.str,"%s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 538:
#line 3184 "fgl.yacc"
    {sprintf(yyval.str,"%s %s:%s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 539:
#line 3185 "fgl.yacc"
    {sprintf(yyval.str,"%s %s:%s:%s",yyvsp[-5].str,yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 540:
#line 3186 "fgl.yacc"
    {sprintf(yyval.str,"%s %s:%s:%s",yyvsp[-5].str,yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 541:
#line 3188 "fgl.yacc"
    {sprintf(yyval.str,"%s:%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 542:
#line 3189 "fgl.yacc"
    {sprintf(yyval.str,"%s:%s:%s",yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 543:
#line 3190 "fgl.yacc"
    {sprintf(yyval.str,"%s:%s:%s",yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 544:
#line 3192 "fgl.yacc"
    {sprintf(yyval.str,"%s:%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 545:
#line 3193 "fgl.yacc"
    {sprintf(yyval.str,"%s",yyvsp[0].str);}
    break;

  case 547:
#line 3199 "fgl.yacc"
    {sprintf(yyval.str,"%s-%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 548:
#line 3203 "fgl.yacc"
    {
                        yyval.field_list=new_field_list();
                        yyval.field_list=append_field_to_list(yyval.field_list,yyvsp[0].field_entry);
		}
    break;

  case 549:
#line 3207 "fgl.yacc"
    {
                        yyval.field_list=append_field_to_list(yyvsp[-2].field_list,yyvsp[0].field_entry);
	}
    break;

  case 550:
#line 3212 "fgl.yacc"
    {
                        yyval.field_list=new_field_list();
                        yyval.field_list=append_field_to_list(yyval.field_list,yyvsp[0].field_entry);
		}
    break;

  case 551:
#line 3216 "fgl.yacc"
    {
                        yyval.field_list=append_field_to_list(yyvsp[-2].field_list,yyvsp[0].field_entry);
	}
    break;

  case 552:
#line 3231 "fgl.yacc"
    {
push_blockcommand("FOREACH");
}
    break;

  case 553:
#line 3235 "fgl.yacc"
    {
print_foreach_start();
A4GL_lex_printcomment(" /* foreach */\n");
}
    break;

  case 554:
#line 3241 "fgl.yacc"
    {
print_foreach_next(yyvsp[-3].str,yyvsp[-1].str,yyvsp[0].str);
}
    break;

  case 555:
#line 3245 "fgl.yacc"
    {
add_continue_blockcommand ("FOREACH");
print_foreach_end(yyvsp[-6].str);
pop_blockcommand("FOREACH"); 
print_foreach_close(yyvsp[-6].str);
}
    break;

  case 556:
#line 3254 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 557:
#line 3255 "fgl.yacc"
    {
		strcpy(yyval.str,yyvsp[0].str);
	}
    break;

  case 558:
#line 3267 "fgl.yacc"
    {
		sprintf(curr_func,"%s",yyvsp[0].str); 
		print_formhandler(yyvsp[0].str);
		start_state("formhandler",1);
	push_blockcommand("FORMHANDLER");
        }
    break;

  case 559:
#line 3273 "fgl.yacc"
    {
		print_variables();
		print_getwin();
	}
    break;

  case 560:
#line 3281 "fgl.yacc"
    {
pop_blockcommand("FORMHANDLER");
print_end_formhandler(); 
start_state("formhandler",0);}
    break;

  case 567:
#line 3298 "fgl.yacc"
    {
		print_event('B');
        }
    break;

  case 568:
#line 3300 "fgl.yacc"
    {
		print_event_2();
        }
    break;

  case 569:
#line 3303 "fgl.yacc"
    {
		print_event('b');
        }
    break;

  case 570:
#line 3305 "fgl.yacc"
    {
		print_event_2();
        }
    break;

  case 575:
#line 3319 "fgl.yacc"
    {
		print_event('A');
        }
    break;

  case 576:
#line 3321 "fgl.yacc"
    {
		print_event_2();
        }
    break;

  case 577:
#line 3324 "fgl.yacc"
    {
		print_event('a');
        }
    break;

  case 578:
#line 3326 "fgl.yacc"
    {
		print_event_2();
        }
    break;

  case 591:
#line 3357 "fgl.yacc"
    { 
			print_gtk_field('B',0);
		}
    break;

  case 592:
#line 3359 "fgl.yacc"
    {
			print_gtk_field_2();
		}
    break;

  case 593:
#line 3362 "fgl.yacc"
    { 
			print_gtk_field('A',0);
		}
    break;

  case 594:
#line 3364 "fgl.yacc"
    {
			print_gtk_field_2();
		}
    break;

  case 595:
#line 3367 "fgl.yacc"
    {
			print_gtk_field('b',yyvsp[0].str);
		}
    break;

  case 596:
#line 3369 "fgl.yacc"
    { 
			print_gtk_field_2();
		}
    break;

  case 597:
#line 3372 "fgl.yacc"
    {
			print_gtk_field('a',yyvsp[0].str);
		}
    break;

  case 598:
#line 3374 "fgl.yacc"
    { 
			print_gtk_field_2();
		}
    break;

  case 599:
#line 3377 "fgl.yacc"
    { 
			print_gtk_field('o',yyvsp[0].str);
		}
    break;

  case 600:
#line 3379 "fgl.yacc"
    { 
			print_gtk_field_2();
		}
    break;

  case 601:
#line 3393 "fgl.yacc"
    {
print_for_start(yyvsp[-5].str);
push_blockcommand("FOR");
}
    break;

  case 602:
#line 3397 "fgl.yacc"
    {A4GL_debug("For_cmds\n");}
    break;

  case 603:
#line 3398 "fgl.yacc"
    {

pop_blockcommand("FOR");
print_for_end();
A4GL_lex_printcomment(" /*END FOR*/\n");}
    break;

  case 604:
#line 3405 "fgl.yacc"
    {
		print_for_default_step();
	}
    break;

  case 606:
#line 3423 "fgl.yacc"
    {
		//print_niy("Free Cursor");
		A4GL_lex_printcomment(" /* FIXME: Not implemented: Free Cursor */\n");;

		strcpy(yyval.str,"");
		}
    break;

  case 607:
#line 3439 "fgl.yacc"
    {sprintf(yyval.str,"%d",-1-(atoi(yyvsp[0].str)));}
    break;

  case 608:
#line 3440 "fgl.yacc"
    {strcpy(yyval.str,"-1");}
    break;

  case 609:
#line 3441 "fgl.yacc"
    {sprintf (yyval.str,"%d",atoi(yyvsp[0].str)+1);}
    break;

  case 610:
#line 3442 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 611:
#line 3443 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 612:
#line 3444 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 613:
#line 3445 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 617:
#line 3453 "fgl.yacc"
    {sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str); }
    break;

  case 619:
#line 3459 "fgl.yacc"
    { 
			yyval.field_entry=new_field_entry(yyvsp[0].str,"1",1);
		}
    break;

  case 620:
#line 3462 "fgl.yacc"
    { 
				char buff[256];
				sprintf(buff,"int_to_id(%s)",yyvsp[-1].str);
				yyval.field_entry=new_field_entry(buff,"1",0); 
		}
    break;

  case 621:
#line 3467 "fgl.yacc"
    { 
				char buff[256];
				sprintf(buff,"int_to_id(%s.%s)",yyvsp[-5].str,yyvsp[-1].str); 
				yyval.field_entry=new_field_entry(buff,"1",0); 
		}
    break;

  case 622:
#line 3472 "fgl.yacc"
    {
				yyval.field_entry=new_field_entry(yyvsp[-3].str,yyvsp[-1].str,1);
		}
    break;

  case 623:
#line 3475 "fgl.yacc"
    {
				char buff[256];
				sprintf(buff,"%s.*",yyvsp[-2].str);
				yyval.field_entry=new_field_entry(buff,"1",1);
		}
    break;

  case 624:
#line 3480 "fgl.yacc"
    {
				char buff[256];
				sprintf(buff,"%s.*",yyvsp[-5].str);
				yyval.field_entry=new_field_entry(buff,yyvsp[-3].str,1);
		}
    break;

  case 625:
#line 3485 "fgl.yacc"
    {
				char buff[256];
				sprintf(buff,"%s.%s",yyvsp[-2].str,yyvsp[0].str);
				yyval.field_entry=new_field_entry(buff,"1",1);
		}
    break;

  case 626:
#line 3490 "fgl.yacc"
    {
				char buff[256];
				sprintf(buff,"%s.%s",yyvsp[-5].str,yyvsp[0].str);
				yyval.field_entry=new_field_entry(buff,yyvsp[-3].str,1);
		}
    break;

  case 627:
#line 3497 "fgl.yacc"
    {yyval.field_entry=yyvsp[0].field_entry;}
    break;

  case 628:
#line 3498 "fgl.yacc"
    { 
                 char buff[256];
                 sprintf(buff,"%s",yyvsp[0].str);
                 yyval.field_entry=new_field_entry(buff,"1",0);
	}
    break;

  case 629:
#line 3505 "fgl.yacc"
    {
				print_pushchar(yyvsp[0].str);
				addmap("Cursor",last_var,curr_func,yylineno,infilename);
			}
    break;

  case 630:
#line 3512 "fgl.yacc"
    {sprintf(yyval.str,"%s",yyvsp[0].str);}
    break;

  case 631:
#line 3514 "fgl.yacc"
    {sprintf(yyval.str,"%s",yyvsp[0].str);
addmap("Window",last_var,curr_func,yylineno,infilename);
}
    break;

  case 632:
#line 3520 "fgl.yacc"
    {sprintf(yyval.str,"%s",yyvsp[0].str);
addmap("Open Window",last_var,curr_func,yylineno,infilename);
}
    break;

  case 633:
#line 3525 "fgl.yacc"
    {sprintf(yyval.str,"%s",yyvsp[0].str);
addmap("Form",last_var,curr_func,yylineno,infilename);
}
    break;

  case 634:
#line 3530 "fgl.yacc"
    {sprintf(yyval.str,"%s",yyvsp[0].str);
addmap("Open Form",last_var,curr_func,yylineno,infilename);
}
    break;

  case 635:
#line 3535 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 636:
#line 3535 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 637:
#line 3538 "fgl.yacc"
    { 
			strcpy(yyval.str,downshift(yyvsp[0].str)) ;
}
    break;

  case 638:
#line 3544 "fgl.yacc"
    {
			sprintf(yyval.str,"%s",downshift(yyvsp[0].str)) ;
			}
    break;

  case 639:
#line 3549 "fgl.yacc"
    {
	strcpy(yyval.str,do_clobbering(clobber,downshift(yyvsp[0].str))) ;
	strcpy(last_var,downshift(yyvsp[0].str));
}
    break;

  case 640:
#line 3553 "fgl.yacc"
    {
		sprintf(yyval.str,"aclfgli_str_to_id(%s)",yyvsp[-1].str);
		sprintf(last_var,"->%s",yyvsp[-1].str);
	}
    break;

  case 643:
#line 3561 "fgl.yacc"
    {
					yyval.field_entry=new_field_entry(yyvsp[0].str,"1",1); 
				}
    break;

  case 644:
#line 3564 "fgl.yacc"
    {
					yyval.field_entry=new_field_entry(yyvsp[-3].str,yyvsp[-1].str,1); 
				}
    break;

  case 645:
#line 3567 "fgl.yacc"
    {
					char buff[256];
					sprintf(buff,"%s.*",yyvsp[-2].str);
					yyval.field_entry=new_field_entry(buff,"1",1); 
				}
    break;

  case 646:
#line 3572 "fgl.yacc"
    {
					char buff[256];
					sprintf(buff,"%s.*",yyvsp[-5].str);
					yyval.field_entry=new_field_entry(buff,yyvsp[-3].str,1); 
				}
    break;

  case 647:
#line 3577 "fgl.yacc"
    {
					char buff[256];
					sprintf(buff,"%s.%s",yyvsp[-2].str,yyvsp[0].str);
					yyval.field_entry=new_field_entry(buff,"1",1); 
				}
    break;

  case 648:
#line 3582 "fgl.yacc"
    {
					char buff[256];
					sprintf(buff,"%s.%s",yyvsp[-5].str,yyvsp[0].str);
					yyval.field_entry=new_field_entry(buff,yyvsp[-3].str,1); 
				}
    break;

  case 649:
#line 3589 "fgl.yacc"
    {
A4GL_debug("Scanvar=%d",scan_variable(yyvsp[0].str)&15);
if ((scan_variable(yyvsp[0].str)&15)!=0) {
a4gl_yyerror("Only a character variable can be used for this");
YYERROR;
}
}
    break;

  case 651:
#line 3598 "fgl.yacc"
    {
		sprintf(yyval.str,".%s",yyvsp[0].str);
}
    break;

  case 652:
#line 3660 "fgl.yacc"
    {
	char buff[256];
	strcpy(buff,yyvsp[0].str);
	A4GL_convlower(buff);
	print_goto(buff);
}
    break;

  case 654:
#line 3669 "fgl.yacc"
    {sprintf(yyval.str,"%s",yyvsp[0].str);}
    break;

  case 655:
#line 3678 "fgl.yacc"
    {
print_gui_do_menuitems(yyvsp[0].str,'C');
}
    break;

  case 657:
#line 3685 "fgl.yacc"
    {sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 658:
#line 3688 "fgl.yacc"
    {
        sprintf(yyval.str,"\"%s\"",yyvsp[0].str);
}
    break;

  case 659:
#line 3694 "fgl.yacc"
    {
print_gui_do_menuitems(yyvsp[0].str,'U');
}
    break;

  case 660:
#line 3700 "fgl.yacc"
    {
print_gui_do_menuitems(yyvsp[0].str,'D');
}
    break;

  case 661:
#line 3704 "fgl.yacc"
    {
print_gui_do_fields(field_name_list_as_char(yyvsp[0].field_list),'D');
}
    break;

  case 662:
#line 3708 "fgl.yacc"
    {
print_gui_do_form(yyvsp[-2].str,field_name_list_as_char(yyvsp[0].field_list),'D');
}
    break;

  case 663:
#line 3714 "fgl.yacc"
    {
print_gui_do_menuitems(yyvsp[0].str,'E');
}
    break;

  case 664:
#line 3718 "fgl.yacc"
    {
print_gui_do_fields(field_name_list_as_char(yyvsp[0].field_list),'E');
}
    break;

  case 665:
#line 3722 "fgl.yacc"
    {
print_gui_do_form(field_name_list_as_char(yyvsp[-2].field_list),yyvsp[0].str,'E');
}
    break;

  case 666:
#line 3727 "fgl.yacc"
    {start_state("messagebox",1);}
    break;

  case 667:
#line 3732 "fgl.yacc"
    {start_state("messagebox",0);}
    break;

  case 686:
#line 3773 "fgl.yacc"
    {
		if_print_stack_cnt++;
		if_print_stack[if_print_stack_cnt][0]=0;
		if_print_stack[if_print_stack_cnt][1]=0;
		if_print_section[if_print_stack_cnt]=0;
		print_if_start();
	}
    break;

  case 687:
#line 3780 "fgl.yacc"
    {
		if_print_section[if_print_stack_cnt]=1;
	}
    break;

  case 688:
#line 3782 "fgl.yacc"
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

  case 690:
#line 3801 "fgl.yacc"
    {
		print_if_else();
	}
    break;

  case 692:
#line 3804 "fgl.yacc"
    {
		print_if_else();
		}
    break;

  case 693:
#line 3806 "fgl.yacc"
    {

		print_if_start();
	}
    break;

  case 694:
#line 3809 "fgl.yacc"
    {
		print_if_end();
	}
    break;

  case 695:
#line 3813 "fgl.yacc"
    {
		print_import(yyvsp[-3].str,atoi(yyvsp[-1].str));
	}
    break;

  case 696:
#line 3816 "fgl.yacc"
    {
		print_import_legacy(yyvsp[0].str);
	}
    break;

  case 697:
#line 3822 "fgl.yacc"
    { add_ex_dtype(yyvsp[0].str); }
    break;

  case 698:
#line 3833 "fgl.yacc"
    {A4GL_debug("init to\n");}
    break;

  case 699:
#line 3834 "fgl.yacc"
    {
	print_init();
 }
    break;

  case 700:
#line 3837 "fgl.yacc"
    {
	print_init_table(yyvsp[0].str);
}
    break;

  case 702:
#line 3843 "fgl.yacc"
    {sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 703:
#line 3847 "fgl.yacc"
    {setrecord(yyval.str,yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 704:
#line 3848 "fgl.yacc"
    {setrecord(yyval.str,yyvsp[-2].str,0);}
    break;

  case 705:
#line 3852 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 709:
#line 3867 "fgl.yacc"
    {
sprintf(yyval.str,"0");
}
    break;

  case 710:
#line 3869 "fgl.yacc"
    {
sprintf(yyval.str,"1");
}
    break;

  case 713:
#line 3878 "fgl.yacc"
    {
		A4GL_add_event(-97,field_name_list_as_or_char(yyvsp[0].field_list));
		print_befaft_field_1(field_name_list_as_or_char(yyvsp[0].field_list));
}
    break;

  case 714:
#line 3881 "fgl.yacc"
    {
	print_befaft_field_2();
}
    break;

  case 715:
#line 3885 "fgl.yacc"
    {
		A4GL_add_event(-98,field_name_list_as_or_char(yyvsp[0].field_list));
		print_befaft_field_1(field_name_list_as_or_char(yyvsp[0].field_list));
}
    break;

  case 716:
#line 3888 "fgl.yacc"
    {
	print_befaft_field_2();
}
    break;

  case 717:
#line 3891 "fgl.yacc"
    {
		A4GL_add_event(-11,"");
		print_befaft_field_1("AFT_ROW");
}
    break;

  case 718:
#line 3894 "fgl.yacc"
    {
	print_befaft_field_2();
}
    break;

  case 719:
#line 3897 "fgl.yacc"
    {
		A4GL_add_event(-10,"");
		A4GL_lex_printcomment("/* before row */ \n");
		print_befaft_field_1("BEF_ROW");
}
    break;

  case 720:
#line 3901 "fgl.yacc"
    {
	print_befaft_field_2();
		}
    break;

  case 721:
#line 3904 "fgl.yacc"
    {
	A4GL_add_onkey_key(yyvsp[0].str);
	print_onkey_1(yyvsp[0].str);
}
    break;

  case 722:
#line 3907 "fgl.yacc"
    {
	print_onkey_2();
}
    break;

  case 723:
#line 3910 "fgl.yacc"
    {
		A4GL_add_event(-95,"");
		print_befaft_field_1("AFTER_INP");
}
    break;

  case 724:
#line 3913 "fgl.yacc"
    {
	print_befaft_field_2();
}
    break;

  case 725:
#line 3916 "fgl.yacc"
    {
		A4GL_add_event(-99,"");
		print_befaft_field_1("BEFORE_INP");
}
    break;

  case 726:
#line 3919 "fgl.yacc"
    {
	print_befaft_field_2();
}
    break;

  case 727:
#line 3922 "fgl.yacc"
    {
		A4GL_add_event(-12,"");
		print_befaft_field_1("DO_BEFORE_DELETE");
	}
    break;

  case 728:
#line 3925 "fgl.yacc"
    { print_befaft_field_2(); }
    break;

  case 729:
#line 3926 "fgl.yacc"
    {
		A4GL_add_event(-14,"");
		print_befaft_field_1("DO_BEFORE_INSERT");
	}
    break;

  case 730:
#line 3929 "fgl.yacc"
    { print_befaft_field_2(); }
    break;

  case 731:
#line 3930 "fgl.yacc"
    {
		A4GL_add_event(-13,"");
		print_befaft_field_1("DO_AFTER_DELETE");
	}
    break;

  case 732:
#line 3933 "fgl.yacc"
    { print_befaft_field_2(); }
    break;

  case 733:
#line 3934 "fgl.yacc"
    {
		A4GL_add_event(-15,"");
		print_befaft_field_1("DO_AFTER_INSERT");
	}
    break;

  case 734:
#line 3937 "fgl.yacc"
    { print_befaft_field_2(); }
    break;

  case 735:
#line 3945 "fgl.yacc"
    {
                        yyval.field_list=new_field_list();
                        yyval.field_list=append_field_to_list(yyval.field_list,yyvsp[0].field_entry);
        }
    break;

  case 736:
#line 3949 "fgl.yacc"
    {
                        yyval.field_list=append_field_to_list(yyvsp[-2].field_list,yyvsp[0].field_entry);
        }
    break;

  case 737:
#line 3955 "fgl.yacc"
    {
                        yyval.field_list=new_field_list();
                        yyval.field_list=append_field_to_list(yyval.field_list,yyvsp[0].field_entry);
        }
    break;

  case 738:
#line 3959 "fgl.yacc"
    {
                        yyval.field_list=append_field_to_list(yyvsp[-2].field_list,yyvsp[0].field_entry);
        }
    break;

  case 739:
#line 3964 "fgl.yacc"
    {
print_next_field(yyvsp[0].str);
}
    break;

  case 740:
#line 3969 "fgl.yacc"
    {
print_next_form_field(yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 741:
#line 3974 "fgl.yacc"
    {sprintf(yyval.str,"\"+\"");}
    break;

  case 742:
#line 3975 "fgl.yacc"
    {sprintf(yyval.str,"\"-\"");}
    break;

  case 743:
#line 3976 "fgl.yacc"
    {sprintf(yyval.str,field_name_as_char(yyvsp[0].field_entry));}
    break;

  case 744:
#line 3980 "fgl.yacc"
    {
print_input_1();
  A4GL_new_events();
}
    break;

  case 745:
#line 3984 "fgl.yacc"
    {
print_input_2(yyvsp[-2].str);
A4GL_drop_events();
}
    break;

  case 746:
#line 3993 "fgl.yacc"
    {
print_input(1,yyvsp[-2].str,yyvsp[-1].str,0,atoi(yyvsp[0].str));
strcpy(yyval.str,A4GL_get_formloop_str(0));
}
    break;

  case 747:
#line 3998 "fgl.yacc"
    {
print_input(0,yyvsp[-4].str,yyvsp[-1].str,field_name_list_as_char(yyvsp[-2].field_list),atoi(yyvsp[0].str));
strcpy(yyval.str,A4GL_get_formloop_str(0));
}
    break;

  case 748:
#line 4002 "fgl.yacc"
    {
curr_input_array_attribs.maxcount=0;
curr_input_array_attribs.count=0;
curr_input_array_attribs.allow_insert=1;
curr_input_array_attribs.allow_delete=1;
curr_input_array_attribs.curr_row_display=0;
inp_flags=0;}
    break;

  case 749:
#line 4009 "fgl.yacc"
    {
strcpy(yyval.str,print_input_array(fgl_add_scope(yyvsp[-8].str,0),yyvsp[-2].str,yyvsp[-7].str,yyvsp[-5].str,yyvsp[0].str,&curr_input_array_attribs));
}
    break;

  case 750:
#line 4018 "fgl.yacc"
    {
		print_scroll(field_name_list_as_char(yyvsp[-1].field_list),yyvsp[0].str);
	}
    break;

  case 751:
#line 4024 "fgl.yacc"
    {sprintf(yyval.str,"%s",yyvsp[0].str);}
    break;

  case 752:
#line 4025 "fgl.yacc"
    {sprintf(yyval.str,"-%s",yyvsp[0].str);}
    break;

  case 753:
#line 4026 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 754:
#line 4027 "fgl.yacc"
    {strcpy(yyval.str,"-1");}
    break;

  case 755:
#line 4030 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 757:
#line 4033 "fgl.yacc"
    {
	strcpy(yyval.str,"");
}
    break;

  case 758:
#line 4040 "fgl.yacc"
    { curr_input_array_attribs.curr_row_display=strdup(yyvsp[0].str); }
    break;

  case 759:
#line 4041 "fgl.yacc"
    { curr_input_array_attribs.count=strdup(yyvsp[0].str); }
    break;

  case 760:
#line 4042 "fgl.yacc"
    { curr_input_array_attribs.count=strdup(yyvsp[0].str); }
    break;

  case 761:
#line 4043 "fgl.yacc"
    { curr_input_array_attribs.maxcount=strdup(yyvsp[0].str); }
    break;

  case 762:
#line 4044 "fgl.yacc"
    { curr_input_array_attribs.maxcount=strdup(yyvsp[0].str); }
    break;

  case 763:
#line 4045 "fgl.yacc"
    { curr_input_array_attribs.allow_insert=1; }
    break;

  case 764:
#line 4046 "fgl.yacc"
    { curr_input_array_attribs.allow_insert=0; }
    break;

  case 765:
#line 4047 "fgl.yacc"
    { curr_input_array_attribs.allow_delete=1; }
    break;

  case 766:
#line 4048 "fgl.yacc"
    { curr_input_array_attribs.allow_delete=0; }
    break;

  case 767:
#line 4053 "fgl.yacc"
    {iskey=1;}
    break;

  case 768:
#line 4053 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);iskey=0;}
    break;

  case 769:
#line 4055 "fgl.yacc"
    {strcpy(yyval.str,"->ANY");}
    break;

  case 770:
#line 4058 "fgl.yacc"
    {iskey=1;}
    break;

  case 771:
#line 4058 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);iskey=0;}
    break;

  case 772:
#line 4060 "fgl.yacc"
    {sprintf(yyval.str,"A4GL_key_val(\"%s\")",yyvsp[0].str);iskey=0;}
    break;

  case 773:
#line 4064 "fgl.yacc"
    {sprintf(yyval.str,"A4GL_key_val(\"%s\")",yyvsp[0].str);iskey=0;}
    break;

  case 774:
#line 4067 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 775:
#line 4068 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[-1].str);}
    break;

  case 777:
#line 4071 "fgl.yacc"
    {
	sprintf(yyval.str,"%s||%s",yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 783:
#line 4083 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 784:
#line 4084 "fgl.yacc"
    {strcpy(yyval.str,"escape");}
    break;

  case 785:
#line 4085 "fgl.yacc"
    {strcpy(yyval.str,"up");}
    break;

  case 786:
#line 4086 "fgl.yacc"
    {strcpy(yyval.str,"help");}
    break;

  case 787:
#line 4087 "fgl.yacc"
    {strcpy(yyval.str,"down");}
    break;

  case 788:
#line 4088 "fgl.yacc"
    {strcpy(yyval.str,"return");}
    break;

  case 789:
#line 4089 "fgl.yacc"
    {strcpy(yyval.str,"delete");}
    break;

  case 790:
#line 4090 "fgl.yacc"
    {strcpy(yyval.str,"insert");}
    break;

  case 791:
#line 4091 "fgl.yacc"
    {strcpy(yyval.str,"tab");}
    break;

  case 792:
#line 4092 "fgl.yacc"
    {strcpy(yyval.str,"left");}
    break;

  case 793:
#line 4093 "fgl.yacc"
    {strcpy(yyval.str,"right");}
    break;

  case 794:
#line 4094 "fgl.yacc"
    {strcpy(yyval.str,"nextpage");}
    break;

  case 795:
#line 4095 "fgl.yacc"
    {strcpy(yyval.str,"prevpage");}
    break;

  case 796:
#line 4096 "fgl.yacc"
    { rm_quotes(yyvsp[0].str); strcpy(yyval.str,yyvsp[0].str); }
    break;

  case 797:
#line 4100 "fgl.yacc"
    {
char buff[256];
A4GL_debug("Label : %s\n",get_idents(0));
strcpy(buff,get_idents(0));
A4GL_convlower(buff);
print_label(buff);
}
    break;

  case 798:
#line 4118 "fgl.yacc"
    {chk4var=1;}
    break;

  case 799:
#line 4118 "fgl.yacc"
    {chk4var=0;
expand_obind();
A4GL_lex_printcomment("/*let3*/\n");}
    break;

  case 800:
#line 4121 "fgl.yacc"
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

  case 801:
#line 4145 "fgl.yacc"
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

  case 803:
#line 4163 "fgl.yacc"
    {
		if (!print_linked_cmd('S',yyvsp[0].str)) a4gl_yyerror("Not a linked variable");
	}
    break;

  case 804:
#line 4169 "fgl.yacc"
    {
		 if (!print_linked_cmd('D',yyvsp[0].str)) a4gl_yyerror("Not a linked variable");
	}
    break;

  case 805:
#line 4175 "fgl.yacc"
    {
		 if (!print_linked_cmd('U',yyvsp[0].str)) a4gl_yyerror("Not a linked variable");
}
    break;

  case 806:
#line 4181 "fgl.yacc"
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

  case 807:
#line 4193 "fgl.yacc"
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

  case 808:
#line 4218 "fgl.yacc"
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

  case 811:
#line 4234 "fgl.yacc"
    {
	}
    break;

  case 820:
#line 4259 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 824:
#line 4267 "fgl.yacc"
    {
		print_at_termination(yyvsp[0].str);
	}
    break;

  case 840:
#line 4293 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 841:
#line 4294 "fgl.yacc"
    {
strcpy(yyval.str,"static ");
}
    break;

  case 842:
#line 4302 "fgl.yacc"
    {
  clr_variable(); lastlineno=yylineno;
  clr_function_constants (); 
}
    break;

  case 843:
#line 4307 "fgl.yacc"
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

  case 844:
#line 4323 "fgl.yacc"
    {
  A4GL_lex_printcomment("/* new function %s parameters*/\n",yyvsp[-1].str);
  push_blockcommand("FUNC");
  A4GL_lex_printcomment("/* define section */\n");
}
    break;

  case 845:
#line 4329 "fgl.yacc"
    {
  int c;
  A4GL_lex_printcomment("/*end of define section */\n");
	print_variables();
  c=print_param('f');
  printPushFunction();
  print_func_args(c);
}
    break;

  case 847:
#line 4344 "fgl.yacc"
    {
    printPopFunction();
    print_func_defret0();
    pop_blockcommand("FUNC");
    print_func_end();
    clr_function_constants ();
    A4GL_lex_printcomment("/*end function*/\n");
  }
    break;

  case 848:
#line 4357 "fgl.yacc"
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

  case 849:
#line 4367 "fgl.yacc"
    {
	print_variables();
    printDeclareFunctionStack("MAIN");
    print_fgllib_start(hdr_dbname);
    printInitFunctionStack();
    printPushFunction();
  }
    break;

  case 850:
#line 4374 "fgl.yacc"
    {
pop_blockcommand("MAIN");
print_main_end();
A4GL_lex_printcomment("/*end main */\n");}
    break;

  case 851:
#line 4381 "fgl.yacc"
    {
    printPopFunction();
    print_return(atoi(yyvsp[0].str));
  }
    break;

  case 852:
#line 4387 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 853:
#line 4387 "fgl.yacc"
    {
A4GL_lex_printcomment("/* Got expr list */");
sprintf(yyval.str,"%s",yyvsp[0].str);}
    break;

  case 854:
#line 4392 "fgl.yacc"
    {
					open_db(yyvsp[0].str);
					strcpy(hdr_dbname,yyvsp[0].str);
					lastlineno=yylineno;
					is_schema=0;
			}
    break;

  case 855:
#line 4398 "fgl.yacc"
    {
					open_db(yyvsp[0].str);
					strcpy(hdr_dbname,yyvsp[0].str);
					lastlineno=yylineno;
					is_schema=1;
			}
    break;

  case 856:
#line 4406 "fgl.yacc"
    {
}
    break;

  case 860:
#line 4418 "fgl.yacc"
    {
strcpy(curr_func,"[Globals]");
set_current_variable_scope('g');
A4GL_lex_printcomment("/* start of globals */\n");
}
    break;

  case 862:
#line 4426 "fgl.yacc"
    {
 A4GL_lex_printcomment("/* end of globals */");
	A4GL_debug("end of globals\n");
	lastlineno=yylineno;
	set_current_variable_scope('m');
}
    break;

  case 863:
#line 4432 "fgl.yacc"
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

  case 866:
#line 4448 "fgl.yacc"
    {
  addmap("Define Member Function",curr_func,"MODULE",yylineno,infilename);
}
    break;

  case 867:
#line 4452 "fgl.yacc"
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

  case 868:
#line 4465 "fgl.yacc"
    {
	print_variables();
  A4GL_lex_printcomment("/*end of define section */\n");
  print_param('f');
  printPushFunction();
  print_func_args(atoi(yyvsp[-3].str));
}
    break;

  case 870:
#line 4478 "fgl.yacc"
    {
                strcpy(menuhandler,yyvsp[0].str);
	sprintf(curr_func,"%s",yyvsp[0].str); 
	print_gtk_menuhandler_1(yyvsp[0].str);
                push_blockcommand("MENUH");
}
    break;

  case 871:
#line 4484 "fgl.yacc"
    {
		print_variables();
        }
    break;

  case 872:
#line 4488 "fgl.yacc"
    {
                        pop_blockcommand("MENUH");
			print_gtk_menuhandler_end();
                }
    break;

  case 875:
#line 4500 "fgl.yacc"
    {
		print_gtk_menuhandler_bsm();
                push_blockcommand("BSM");
        }
    break;

  case 876:
#line 4503 "fgl.yacc"
    {
                pop_blockcommand("BSM");
		print_gtk_menuhandler_bsm_end();
        }
    break;

  case 877:
#line 4507 "fgl.yacc"
    {
		print_gtk_menuhandler_on(yyvsp[0].str);
                push_blockcommand("ON");
        }
    break;

  case 878:
#line 4510 "fgl.yacc"
    {
                pop_blockcommand("ON");
		print_gtk_menuhandler_on_end();
}
    break;

  case 879:
#line 4522 "fgl.yacc"
    {
	start_state("menu",1);
   	menu_cnt=npush_menu();
   	menu_cmd_cnt[menu_cnt]=1;
   	push_blockcommand("MENU");
        menu_blk[menu_cnt]=get_blk_no();
	do_print_menu_1();
	}
    break;

  case 880:
#line 4530 "fgl.yacc"
    {
	start_state("menu",0);
	}
    break;

  case 881:
#line 4536 "fgl.yacc"
    {
   print_end_menu_1(menu_blk[menu_cnt]);
   add_continue_blockcommand ("MENU");
print_end_menu_2(menu_blk[menu_cnt]);
   pop_blockcommand("MENU");
   pop_menu();
}
    break;

  case 882:
#line 4547 "fgl.yacc"
    {
	 A4GL_lex_printcomment("/* Block%d_m2 (Before menu) */",menu_cnt);
		print_menu_block(menu_blk[menu_cnt],-2) ;
                  }
    break;

  case 883:
#line 4551 "fgl.yacc"
    {
		do_print_menu_block_end();
	}
    break;

  case 884:
#line 4558 "fgl.yacc"
    {
A4GL_debug("Menu=%d menu cnt=%d",menu_cnt,menu_cmd_cnt[menu_cnt]);
		push_command(menu_cnt,menu_cmd_cnt[menu_cnt],yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);
	 A4GL_lex_printcomment("/* Block%d_%d */",menu_cnt,menu_cmd_cnt[menu_cnt]-1);
		print_menu_block(menu_blk[menu_cnt],menu_cmd_cnt[menu_cnt]-1);
		menu_cmd_cnt[menu_cnt]++;
		}
    break;

  case 885:
#line 4565 "fgl.yacc"
    {
		do_print_menu_block_end();
}
    break;

  case 886:
#line 4571 "fgl.yacc"
    {
		push_command(menu_cnt,menu_cmd_cnt[menu_cnt],yyvsp[-1].str,"\"\"","\"\"",0);
		print_menu_block(menu_blk[menu_cnt],menu_cmd_cnt[menu_cnt]-1);
		menu_cmd_cnt[menu_cnt]++;
		}
    break;

  case 887:
#line 4576 "fgl.yacc"
    {
		do_print_menu_block_end();
}
    break;

  case 890:
#line 4583 "fgl.yacc"
    {strcpy(yyval.str,"\"EMPTY\"");}
    break;

  case 891:
#line 4584 "fgl.yacc"
    {sprintf(yyval.str,"\"%s\"",yyvsp[0].str);}
    break;

  case 892:
#line 4586 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str); }
    break;

  case 893:
#line 4587 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 894:
#line 4590 "fgl.yacc"
    {strcpy(yyval.str,"\"\"");}
    break;

  case 895:
#line 4591 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 896:
#line 4592 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 897:
#line 4594 "fgl.yacc"
    {
	print_option_op('N',yyvsp[0].str,menu_blk[menu_cnt]);
}
    break;

  case 898:
#line 4599 "fgl.yacc"
    {
	print_option_op('S',yyvsp[0].str,menu_blk[menu_cnt]);
}
    break;

  case 899:
#line 4604 "fgl.yacc"
    {
	print_option_op('H',yyvsp[0].str,menu_blk[menu_cnt]);
}
    break;

  case 900:
#line 4611 "fgl.yacc"
    {sprintf(yyval.str,"MENU_ALL");}
    break;

  case 904:
#line 4618 "fgl.yacc"
    {sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 905:
#line 4620 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);  
push_menu_title(yyval.str);}
    break;

  case 906:
#line 4622 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str); 
push_menu_title(yyval.str);}
    break;

  case 908:
#line 4632 "fgl.yacc"
    {
		print_message(0,"0",0,message_cnt);
	   }
    break;

  case 909:
#line 4635 "fgl.yacc"
    { 
		print_message(0,yyvsp[-1].str,atoi(yyvsp[0].str),message_cnt);
	  }
    break;

  case 910:
#line 4638 "fgl.yacc"
    { 
		print_message(0,"0",atoi(yyvsp[0].str),message_cnt);
	  }
    break;

  case 917:
#line 4654 "fgl.yacc"
    {
		strcpy(yyval.str,yyvsp[0].str);
		message_cnt=atoi(yyvsp[0].str);
		}
    break;

  case 918:
#line 4659 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 919:
#line 4659 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 920:
#line 4662 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 921:
#line 4690 "fgl.yacc"
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

  case 923:
#line 4747 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 925:
#line 4754 "fgl.yacc"
    { 
         sprintf (yyval.str, "%s.%s", yyvsp[-1].str, yyvsp[0].str); 
         A4GL_lex_printcomment("/* record building -> %s */\n",yyval.str);
         }
    break;

  case 926:
#line 4758 "fgl.yacc"
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

  case 927:
#line 4801 "fgl.yacc"
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

  case 931:
#line 4849 "fgl.yacc"
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

  case 932:
#line 4863 "fgl.yacc"
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

  case 937:
#line 4887 "fgl.yacc"
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

  case 938:
#line 4947 "fgl.yacc"
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

  case 939:
#line 5003 "fgl.yacc"
    {
	 A4GL_debug("---> Subscript or substring");
		strcpy(yyval.str,yyvsp[-1].str);
	}
    break;

  case 940:
#line 5008 "fgl.yacc"
    {
	 A4GL_debug("---> Subscript & substring");
		sprintf(yyval.str,"%s:%s",yyvsp[-4].str,yyvsp[-1].str);
	}
    break;

  case 941:
#line 5016 "fgl.yacc"
    {
A4GL_debug("List element");
  sprintf (yyval.str, "%s", yyvsp[0].str);
}
    break;

  case 942:
#line 5021 "fgl.yacc"
    {
A4GL_debug("List element continues");
  sprintf (yyval.str, "%s,%s", yyvsp[-2].str, yyvsp[0].str); 
}
    break;

  case 943:
#line 5029 "fgl.yacc"
    {
  sprintf (yyval.str, "%s", yyvsp[0].str);
}
    break;

  case 944:
#line 5035 "fgl.yacc"
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

  case 945:
#line 5067 "fgl.yacc"
    {
	 A4GL_debug("Array..");
}
    break;

  case 946:
#line 5070 "fgl.yacc"
    { sprintf (yyval.str, "%s.%s", yyvsp[-2].str, yyvsp[0].str); }
    break;

  case 947:
#line 5072 "fgl.yacc"
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

  case 948:
#line 5113 "fgl.yacc"
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

  case 953:
#line 5166 "fgl.yacc"
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

  case 954:
#line 5218 "fgl.yacc"
    {
start_bind('f',0);
start_bind('O',0);
strcpy(yyval.str,"0");}
    break;

  case 956:
#line 5225 "fgl.yacc"
    {
start_bind('f',yyvsp[0].str);
start_bind('O',yyvsp[0].str);
sprintf(yyval.str,"1");
}
    break;

  case 957:
#line 5231 "fgl.yacc"
    {
int c;
c=add_bind('f',yyvsp[0].str);
c=add_bind('O',yyvsp[0].str);
sprintf(yyval.str,"%d",c); 
}
    break;

  case 958:
#line 5242 "fgl.yacc"
    {
A4GL_lex_printcomment("/*STarted bind %s*/\n",yyvsp[0].str);
start_bind('i',yyvsp[0].str);
A4GL_lex_printcomment("/*STarted bind 2*/\n");
strcpy(yyval.str,"");
}
    break;

  case 959:
#line 5249 "fgl.yacc"
    {
A4GL_lex_printcomment("/* Added */\n");
add_bind('i',yyvsp[0].str);
strcpy(yyval.str,"");
}
    break;

  case 961:
#line 5257 "fgl.yacc"
    {sprintf(yyval.str,"%s.%s",yyvsp[-2].str,yyvsp[-1].str);}
    break;

  case 962:
#line 5260 "fgl.yacc"
    {A4GL_lex_printcomment("/* Variable */\n");}
    break;

  case 963:
#line 5261 "fgl.yacc"
    { A4GL_debug("Got an ibind thru..."); sprintf(yyval.str,"%s\n%s",yyvsp[-2].str,yyvsp[0].str); }
    break;

  case 965:
#line 5263 "fgl.yacc"
    {sprintf(yyval.str,"\"%s\"",yyvsp[0].str);}
    break;

  case 966:
#line 5264 "fgl.yacc"
    {sprintf(yyval.str,"\"%s\"",yyvsp[0].str);}
    break;

  case 967:
#line 5267 "fgl.yacc"
    {
start_bind('o',yyvsp[0].str);
}
    break;

  case 968:
#line 5270 "fgl.yacc"
    {
add_bind('o',yyvsp[0].str);
strcpy(yyval.str,"");
}
    break;

  case 969:
#line 5276 "fgl.yacc"
    {
	addmap("OBIND",yyvsp[0].str,curr_func,yylineno,infilename);
	}
    break;

  case 970:
#line 5279 "fgl.yacc"
    { A4GL_debug("Got an obind thru..."); sprintf(yyval.str,"%s\n%s",yyvsp[-2].str,yyvsp[0].str); }
    break;

  case 971:
#line 5283 "fgl.yacc"
    {
A4GL_lex_printcomment("/* start obind with  %s*/\n",yyvsp[0].str);
A4GL_debug("obind_var_let_list ---> %s\n",yyvsp[0].str);
start_bind('o',yyvsp[0].str);
}
    break;

  case 972:
#line 5288 "fgl.yacc"
    {
A4GL_lex_printcomment("/* add to obind %s */\n",yyvsp[0].str);
add_bind('o',yyvsp[0].str);
A4GL_debug("obind_var_let_list ---> %s\n",yyvsp[0].str);
strcpy(yyval.str,"");
}
    break;

  case 973:
#line 5296 "fgl.yacc"
    {
A4GL_lex_printcomment("/* Read variable %s*/\n",yyvsp[0].str);
}
    break;

  case 974:
#line 5301 "fgl.yacc"
    {
    A4GL_lex_printcomment("/* use_arr_var */\n");
    start_arr_bind('o',yyvsp[0].str);
    A4GL_lex_printcomment("/* use_arr_var complete */\n");
}
    break;

  case 975:
#line 5308 "fgl.yacc"
    {
start_bind('O',yyvsp[0].str);
}
    break;

  case 976:
#line 5311 "fgl.yacc"
    {
               add_bind('O',yyvsp[0].str);
               strcpy(yyval.str,"");
}
    break;

  case 981:
#line 5324 "fgl.yacc"
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

  case 982:
#line 5343 "fgl.yacc"
    {
A4GL_lex_printcomment("/*STarted bind %s*/\n",yyvsp[0].str);
start_bind('N',yyvsp[0].str);
A4GL_lex_printcomment("/*STarted bind 2*/\n");
strcpy(yyval.str,"");
}
    break;

  case 983:
#line 5350 "fgl.yacc"
    {
A4GL_lex_printcomment("/* Added */\n");
add_bind('N',yyvsp[0].str);
strcpy(yyval.str,"");
}
    break;

  case 984:
#line 5357 "fgl.yacc"
    {
		strcpy(yyval.str,yyvsp[0].str);
	}
    break;

  case 985:
#line 5360 "fgl.yacc"
    {
			sprintf(yyval.str,"%s\n%s",yyvsp[-2].str,yyvsp[0].str);
		}
    break;

  case 986:
#line 5374 "fgl.yacc"
    {
form_attrib.iswindow=1;
print_open_window(yyvsp[-5].str,yyvsp[-1].str);
sprintf(yyval.str,"open window");
}
    break;

  case 991:
#line 5391 "fgl.yacc"
    {
	print_niy("OPEN_STATUSBOX");
}
    break;

  case 992:
#line 5396 "fgl.yacc"
    {
addmap("Call Formhandler",yyvsp[0].str,curr_func,yylineno,infilename); 
}
    break;

  case 993:
#line 5402 "fgl.yacc"
    {
		print_open_form(yyvsp[0].str,yyvsp[-1].str,yyvsp[-1].str);
		}
    break;

  case 995:
#line 5409 "fgl.yacc"
    { form_attrib.iswindow=0;strcpy(yyval.str,"A4GL_open_form(%s);"); }
    break;

  case 996:
#line 5414 "fgl.yacc"
    {sprintf(yyval.str,"A4GL_open_gui_form(&%%s,%%s,%s,%s,%s,hnd_e_%s,hnd_c_%s);",yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[0].str,yyvsp[0].str);}
    break;

  case 997:
#line 5417 "fgl.yacc"
    {strcpy(yyval.str,"0,0");}
    break;

  case 998:
#line 5418 "fgl.yacc"
    {sprintf(yyval.str,"%s,2",yyvsp[-5].str);}
    break;

  case 999:
#line 5421 "fgl.yacc"
    {strcpy(yyval.str,"\"\"");}
    break;

  case 1000:
#line 5422 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1001:
#line 5425 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 1002:
#line 5426 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 1003:
#line 5431 "fgl.yacc"
    {
print_open_session(yyvsp[-3].str,yyvsp[-1].str,yyvsp[0].str);

}
    break;

  case 1004:
#line 5438 "fgl.yacc"
    {
	print_open_cursor(yyvsp[0].str,"0");
}
    break;

  case 1005:
#line 5441 "fgl.yacc"
    {
	print_open_cursor(yyvsp[-3].str,yyvsp[0].str); /* CHANGED from $<str>4 */
}
    break;

  case 1006:
#line 5447 "fgl.yacc"
    {sprintf(yyval.str,"0,0");}
    break;

  case 1007:
#line 5449 "fgl.yacc"
    {sprintf(yyval.str,"%s, %s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1008:
#line 5451 "fgl.yacc"
    {sprintf(yyval.str,"%s, %s",yyvsp[-3].str,yyvsp[0].str);}
    break;

  case 1009:
#line 5453 "fgl.yacc"
    {sprintf(yyval.str,"%s, %s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1010:
#line 5456 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 1011:
#line 5456 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 1012:
#line 5457 "fgl.yacc"
    {strcpy(yyval.str,"2");}
    break;

  case 1013:
#line 5462 "fgl.yacc"
    {
	print_open_session(yyvsp[-1].str,yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 1014:
#line 5470 "fgl.yacc"
    {strcpy(yyval.str,"\"default_conn\"");}
    break;

  case 1015:
#line 5471 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1016:
#line 5476 "fgl.yacc"
    {sprintf(yyval.str,"0,0");}
    break;

  case 1017:
#line 5478 "fgl.yacc"
    {sprintf(yyval.str,"%s, %s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1018:
#line 5480 "fgl.yacc"
    {sprintf(yyval.str,"%s, %s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1022:
#line 5497 "fgl.yacc"
    {
print_options('C',yyvsp[0].str);
}
    break;

  case 1023:
#line 5500 "fgl.yacc"
    {
print_options('E',yyvsp[0].str);
}
    break;

  case 1024:
#line 5503 "fgl.yacc"
    {
print_options('F',yyvsp[0].str);
}
    break;

  case 1025:
#line 5506 "fgl.yacc"
    {
//A4GL_lex_printc("A4GL_set_option_value('M',%s);\n",$<str>2);
print_options('M',yyvsp[0].str);
}
    break;

  case 1026:
#line 5510 "fgl.yacc"
    {
print_options('m',yyvsp[0].str);
}
    break;

  case 1027:
#line 5513 "fgl.yacc"
    {
print_options('P',yyvsp[0].str);
}
    break;

  case 1028:
#line 5516 "fgl.yacc"
    {
print_options('A',yyvsp[0].str);
iskey=0;
}
    break;

  case 1029:
#line 5520 "fgl.yacc"
    {
print_options('D',yyvsp[0].str);
iskey=0;
}
    break;

  case 1030:
#line 5524 "fgl.yacc"
    {
print_options('I',yyvsp[0].str);
iskey=0;
}
    break;

  case 1031:
#line 5528 "fgl.yacc"
    {
print_options('N',yyvsp[0].str);
}
    break;

  case 1032:
#line 5531 "fgl.yacc"
    {
print_options('p',yyvsp[0].str);
iskey=0;
}
    break;

  case 1033:
#line 5535 "fgl.yacc"
    {
print_options('H',yyvsp[0].str);
}
    break;

  case 1034:
#line 5538 "fgl.yacc"
    { print_set_helpfile(yyvsp[0].str); }
    break;

  case 1035:
#line 5539 "fgl.yacc"
    { print_set_langfile(yyvsp[0].str); }
    break;

  case 1036:
#line 5540 "fgl.yacc"
    {
print_options('d',yyvsp[0].str);
}
    break;

  case 1037:
#line 5543 "fgl.yacc"
    {
print_options('i',yyvsp[0].str);
}
    break;

  case 1038:
#line 5546 "fgl.yacc"
    {
print_options('W',"1");
}
    break;

  case 1039:
#line 5549 "fgl.yacc"
    {
print_options('W',"0");
}
    break;

  case 1040:
#line 5552 "fgl.yacc"
    {
print_options('f',"1");
}
    break;

  case 1041:
#line 5555 "fgl.yacc"
    {
print_options('f',"0");
}
    break;

  case 1042:
#line 5558 "fgl.yacc"
    {
print_options('S',"1");
}
    break;

  case 1043:
#line 5561 "fgl.yacc"
    {
print_options('S',"0");
}
    break;

  case 1044:
#line 5578 "fgl.yacc"
    {
	print_prepare(yyvsp[-2].str,yyvsp[0].str);
	addmap("Prepare",yyvsp[-2].str,curr_func,yylineno,infilename);
	print_undo_use(yyvsp[-4].str);
}
    break;

  case 1047:
#line 5588 "fgl.yacc"
    {

print_execute(yyvsp[0].str,0);

addmap("Execute",yyvsp[0].str,curr_func,yylineno,infilename);
}
    break;

  case 1048:
#line 5594 "fgl.yacc"
    {
	addmap("Execute",yyvsp[-2].str,curr_func,yylineno,infilename);
	print_execute(yyvsp[-2].str,1);
	}
    break;

  case 1049:
#line 5598 "fgl.yacc"
    {
		print_execute_immediate(yyvsp[0].str);
	}
    break;

  case 1051:
#line 5618 "fgl.yacc"
    {
                push_blockcommand("PROMPT");
	A4GL_new_events();
	print_prompt_1(yyvsp[-6].str,yyvsp[-4].str,yyvsp[-1].str,yyvsp[0].str,atoi(yyvsp[-2].str)) ;
}
    break;

  case 1052:
#line 5623 "fgl.yacc"
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

  case 1053:
#line 5636 "fgl.yacc"
    {sprintf(yyval.str,"0");}
    break;

  case 1054:
#line 5637 "fgl.yacc"
    {sprintf(yyval.str,yyvsp[0].str);}
    break;

  case 1055:
#line 5641 "fgl.yacc"
    {
		print_niy("GUI PROMPT");
	}
    break;

  case 1056:
#line 5646 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 1057:
#line 5647 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 1058:
#line 5651 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1062:
#line 5657 "fgl.yacc"
    {
	A4GL_add_onkey_key(yyvsp[0].str);
	print_onkey_1(yyvsp[0].str);
}
    break;

  case 1063:
#line 5660 "fgl.yacc"
    {
	print_onkey_2_prompt();
}
    break;

  case 1065:
#line 5675 "fgl.yacc"
    {
		start_bind('i',0);
		}
    break;

  case 1066:
#line 5679 "fgl.yacc"
    {
		print_put(yyvsp[-2].str,yyvsp[0].str);
	}
    break;

  case 1067:
#line 5685 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1068:
#line 5686 "fgl.yacc"
    { strcpy(yyval.str,yyvsp[0].str);
A4GL_debug("putlist = %s\n",yyval.str);
}
    break;

  case 1069:
#line 5691 "fgl.yacc"
    {push_gen(PUTVAL,yyvsp[0].str);}
    break;

  case 1070:
#line 5692 "fgl.yacc"
    {push_gen(PUTVAL,yyvsp[0].str); sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1071:
#line 5695 "fgl.yacc"
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

  case 1073:
#line 5723 "fgl.yacc"
    {
addmap("Start Report",yyvsp[-1].str,curr_func,yylineno,infilename);
print_start_report("P","acl_getenv(\"DBPRINT\")",yyvsp[-1].str);
}
    break;

  case 1074:
#line 5728 "fgl.yacc"
    {
addmap("Start Report",yyvsp[-2].str,curr_func,yylineno,infilename);
print_start_report("F",yyvsp[0].str,yyvsp[-2].str);
}
    break;

  case 1075:
#line 5733 "fgl.yacc"
    {
addmap("Start Report",yyvsp[-2].str,curr_func,yylineno,infilename);
print_start_report("P",yyvsp[0].str,yyvsp[-2].str);
}
    break;

  case 1076:
#line 5738 "fgl.yacc"
    {
addmap("Start Report",yyvsp[0].str,curr_func,yylineno,infilename);
print_start_report("","\"\"",yyvsp[0].str);
}
    break;

  case 1082:
#line 5760 "fgl.yacc"
    {
addmap("Output to report",yyvsp[-5].str,curr_func,yylineno,infilename);
print_output_to_report(yyvsp[-5].str,yyvsp[-1].str); 
}
    break;

  case 1083:
#line 5767 "fgl.yacc"
    {
addmap("Finish Report",yyvsp[0].str,curr_func,yylineno,infilename);
print_finish_report(yyvsp[0].str);
}
    break;

  case 1084:
#line 5776 "fgl.yacc"
    {
addmap("Finish Report",yyvsp[0].str,curr_func,yylineno,infilename);
print_terminate_report(yyvsp[0].str);
}
    break;

  case 1085:
#line 5782 "fgl.yacc"
    { strcpy(yyval.str,yyvsp[0].str); }
    break;

  case 1086:
#line 5784 "fgl.yacc"
    {
	print_format_every_row();
}
    break;

  case 1090:
#line 5795 "fgl.yacc"
    { push_report_block("FIRST",'P');}
    break;

  case 1091:
#line 5796 "fgl.yacc"
    {
rep_struct.lines_in_first_header=if_print_stack[0][0];
pdf_rep_struct.lines_in_first_header=if_print_stack[0][0];
print_rep_ret(0,1);
}
    break;

  case 1092:
#line 5802 "fgl.yacc"
    { push_report_block("TRAILER",'T');
if_print_stack[0][0]=0;
if_print_stack[0][1]=0;
}
    break;

  case 1093:
#line 5806 "fgl.yacc"
    {
rep_struct.lines_in_trailer=if_print_stack[0][0];
pdf_rep_struct.lines_in_trailer=if_print_stack[0][0];
print_rep_ret(0,1);
}
    break;

  case 1094:
#line 5812 "fgl.yacc"
    { push_report_block("HEADER",'p');}
    break;

  case 1095:
#line 5813 "fgl.yacc"
    {
rep_struct.lines_in_header=if_print_stack[0][0];
pdf_rep_struct.lines_in_header=if_print_stack[0][0];
print_rep_ret(0,1);}
    break;

  case 1096:
#line 5818 "fgl.yacc"
    { push_report_block("EVERY",'E');}
    break;

  case 1097:
#line 5819 "fgl.yacc"
    {print_rep_ret(0,1);}
    break;

  case 1098:
#line 5821 "fgl.yacc"
    { push_report_block("LAST",'L');}
    break;

  case 1099:
#line 5822 "fgl.yacc"
    {print_rep_ret(0,1);}
    break;

  case 1100:
#line 5823 "fgl.yacc"
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

  case 1101:
#line 5837 "fgl.yacc"
    {print_rep_ret(0,1);}
    break;

  case 1102:
#line 5839 "fgl.yacc"
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

  case 1103:
#line 5856 "fgl.yacc"
    {print_rep_ret(0,1);}
    break;

  case 1110:
#line 5868 "fgl.yacc"
    {start_state("skip",1);}
    break;

  case 1111:
#line 5868 "fgl.yacc"
    {
	print_need_lines();
	start_state("skip",0);
}
    break;

  case 1112:
#line 5874 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 1113:
#line 5874 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 1114:
#line 5877 "fgl.yacc"
    {start_state("KWLINE",1);}
    break;

  case 1115:
#line 5877 "fgl.yacc"
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

  case 1116:
#line 5893 "fgl.yacc"
    { print_skip_top(); }
    break;

  case 1117:
#line 5894 "fgl.yacc"
    { print_niy("FONT SIZE"); }
    break;

  case 1118:
#line 5895 "fgl.yacc"
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

  case 1119:
#line 5904 "fgl.yacc"
    {
			if (rep_type!=REP_TYPE_PDF) {
				a4gl_yyerror("SKIP TO is only in PDF reports");
				YYERROR;
			}
			print_skip_to(yyvsp[0].str);
		}
    break;

  case 1120:
#line 5916 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1126:
#line 5927 "fgl.yacc"
    {
	print_niy("PRINT AT...");
}
    break;

  case 1127:
#line 5932 "fgl.yacc"
    {doing_a_print=1;}
    break;

  case 1128:
#line 5932 "fgl.yacc"
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

  case 1129:
#line 5953 "fgl.yacc"
    { 
	print_report_print_file(yyvsp[-1].str,yyvsp[0].str);
}
    break;

  case 1130:
#line 5958 "fgl.yacc"
    { 
	print_report_print_img(yyvsp[-1].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 1131:
#line 5964 "fgl.yacc"
    { strcpy(yyval.str,A4GL_get_default_scaling());}
    break;

  case 1132:
#line 5965 "fgl.yacc"
    { strcpy(yyval.str,yyvsp[0].str); strcat(yyval.str,yyvsp[0].str); }
    break;

  case 1133:
#line 5966 "fgl.yacc"
    {sprintf(yyval.str,"%s %s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1134:
#line 5970 "fgl.yacc"
    {strcpy(yyval.str,"tiff");}
    break;

  case 1135:
#line 5971 "fgl.yacc"
    {strcpy(yyval.str,"gif");}
    break;

  case 1136:
#line 5972 "fgl.yacc"
    {strcpy(yyval.str,"png");}
    break;

  case 1137:
#line 5973 "fgl.yacc"
    {strcpy(yyval.str,"jpeg");}
    break;

  case 1138:
#line 5977 "fgl.yacc"
    {
	int vtype;
	vtype=scan_variable(yyvsp[0].str);
	if (vtype!=11&&vtype!=12) {
	a4gl_yyerror("Only Blobs may be printed...");
	YYERROR;
	}
}
    break;

  case 1139:
#line 5987 "fgl.yacc"
    {
strcpy(yyval.str,"0");
}
    break;

  case 1140:
#line 5989 "fgl.yacc"
    {
strcpy(yyval.str,"1");
}
    break;

  case 1141:
#line 5994 "fgl.yacc"
    {
	print_report_print(1,0,yyvsp[0].str);
	}
    break;

  case 1142:
#line 5997 "fgl.yacc"
    {
	print_report_print(1,0,yyvsp[0].str); /* changed from $<str>1 */
}
    break;

  case 1143:
#line 6002 "fgl.yacc"
    {
	strcpy(yyval.str,yyvsp[0].str); 
	}
    break;

  case 1144:
#line 6009 "fgl.yacc"
    {
int a;
a=add_report_agg('S',yyvsp[-2].ptr,yyvsp[0].ptr,racnt);
sprintf(yyval.str,"A4GL_push_double(_g%d);\n",racnt);
racnt+=a;
}
    break;

  case 1145:
#line 6016 "fgl.yacc"
    {
int a;
a=add_report_agg('C',0,yyvsp[0].ptr,racnt);
sprintf(yyval.str,"A4GL_push_int(_g%d);\n",racnt);
racnt+=a;
}
    break;

  case 1146:
#line 6023 "fgl.yacc"
    {
int a;
a=add_report_agg('C',0,yyvsp[0].ptr,racnt);
sprintf(yyval.str,"A4GL_push_int(_g%d);\n",racnt);
racnt+=a;
}
    break;

  case 1147:
#line 6032 "fgl.yacc"
    {
int a;
a=add_report_agg('P',yyvsp[-2].ptr,yyvsp[0].ptr,racnt);
sprintf(yyval.str,"A4GL_push_double((double)_g%d/(double)_g%d);\n",racnt,racnt+1);
racnt+=a;
}
    break;

  case 1148:
#line 6039 "fgl.yacc"
    {
int a;
a=add_report_agg('A',yyvsp[-2].ptr,yyvsp[0].ptr,racnt);
sprintf(yyval.str,"A4GL_push_double(_g%d/(double)_g%d);\n",racnt,racnt+1);
racnt+=a;
}
    break;

  case 1149:
#line 6046 "fgl.yacc"
    {
int a;
a=add_report_agg('A',yyvsp[-2].ptr,yyvsp[0].ptr,racnt);
sprintf(yyval.str,"A4GL_push_double(_g%d/_g%d);\n",racnt,racnt+1);
racnt+=a;
}
    break;

  case 1150:
#line 6053 "fgl.yacc"
    {
int a;
a=add_report_agg('N',yyvsp[-2].ptr,yyvsp[0].ptr,racnt);
sprintf(yyval.str,"A4GL_push_double(_g%d);\n",racnt);
racnt+=a;
}
    break;

  case 1151:
#line 6060 "fgl.yacc"
    {
int a;
a=add_report_agg('X',yyvsp[-2].ptr,yyvsp[0].ptr,racnt);
sprintf(yyval.str,"A4GL_push_double(_g%d);\n",racnt);
racnt+=a;
}
    break;

  case 1156:
#line 6073 "fgl.yacc"
    {rep_struct.left_margin=atoi(yyvsp[0].str);}
    break;

  case 1157:
#line 6074 "fgl.yacc"
    {rep_struct.right_margin=atoi(yyvsp[0].str);}
    break;

  case 1158:
#line 6075 "fgl.yacc"
    {rep_struct.top_margin=atoi(yyvsp[0].str);}
    break;

  case 1159:
#line 6076 "fgl.yacc"
    {rep_struct.bottom_margin=atoi(yyvsp[0].str);}
    break;

  case 1160:
#line 6077 "fgl.yacc"
    {rep_struct.page_length=atoi(yyvsp[0].str);}
    break;

  case 1161:
#line 6078 "fgl.yacc"
    { rep_struct.output_mode='P';strcpy(rep_struct.output_loc,"acl_getenv(\"DBPRINT\")");}
    break;

  case 1162:
#line 6079 "fgl.yacc"
    {rep_struct.output_mode='F';strcpy(rep_struct.output_loc,yyvsp[0].str);}
    break;

  case 1163:
#line 6080 "fgl.yacc"
    {rep_struct.output_mode='F';strcpy(rep_struct.output_loc,yyvsp[0].str);}
    break;

  case 1164:
#line 6081 "fgl.yacc"
    {rep_struct.output_mode='P';strcpy(rep_struct.output_loc,yyvsp[0].str);}
    break;

  case 1165:
#line 6082 "fgl.yacc"
    {strcpy(rep_struct.top_of_page,yyvsp[0].str);}
    break;

  case 1168:
#line 6088 "fgl.yacc"
    {sprintf(yyval.str,"-%f",atof(yyvsp[-1].str));}
    break;

  case 1169:
#line 6089 "fgl.yacc"
    {sprintf(yyval.str,"-%f",atof(yyvsp[-1].str)*72.0); }
    break;

  case 1170:
#line 6090 "fgl.yacc"
    {sprintf(yyval.str,"-%f",atof(yyvsp[-1].str)*2.83465);}
    break;

  case 1171:
#line 6091 "fgl.yacc"
    {sprintf(yyval.str,"%f",atof(yyvsp[0].str));}
    break;

  case 1176:
#line 6100 "fgl.yacc"
    {pdf_rep_struct.left_margin=atof(yyvsp[0].str);A4GL_debug("Left margin=%s\n",yyvsp[0].str);}
    break;

  case 1177:
#line 6101 "fgl.yacc"
    {pdf_rep_struct.right_margin=atof(yyvsp[0].str);}
    break;

  case 1178:
#line 6102 "fgl.yacc"
    {pdf_rep_struct.top_margin=atof(yyvsp[0].str);}
    break;

  case 1179:
#line 6103 "fgl.yacc"
    {pdf_rep_struct.bottom_margin=atof(yyvsp[0].str);}
    break;

  case 1180:
#line 6104 "fgl.yacc"
    {pdf_rep_struct.page_length=atof(yyvsp[0].str);}
    break;

  case 1181:
#line 6105 "fgl.yacc"
    {pdf_rep_struct.page_width=atof(yyvsp[0].str);}
    break;

  case 1182:
#line 6106 "fgl.yacc"
    {strcpy(pdf_rep_struct.font_name,yyvsp[0].str);}
    break;

  case 1183:
#line 6107 "fgl.yacc"
    {pdf_rep_struct.font_size=atof(yyvsp[0].str);}
    break;

  case 1184:
#line 6109 "fgl.yacc"
    {pdf_rep_struct.paper_size=1;}
    break;

  case 1185:
#line 6110 "fgl.yacc"
    {pdf_rep_struct.paper_size=2;}
    break;

  case 1186:
#line 6111 "fgl.yacc"
    {pdf_rep_struct.paper_size=3;}
    break;

  case 1187:
#line 6112 "fgl.yacc"
    {pdf_rep_struct.paper_size=5;}
    break;

  case 1188:
#line 6114 "fgl.yacc"
    {pdf_rep_struct.paper_size=-1;}
    break;

  case 1189:
#line 6115 "fgl.yacc"
    {pdf_rep_struct.paper_size=-2;}
    break;

  case 1190:
#line 6116 "fgl.yacc"
    {pdf_rep_struct.paper_size=-3;}
    break;

  case 1191:
#line 6117 "fgl.yacc"
    {pdf_rep_struct.paper_size=-5;}
    break;

  case 1195:
#line 6122 "fgl.yacc"
    {pdf_rep_struct.output_mode='F';strcpy(pdf_rep_struct.output_loc,yyvsp[0].str);}
    break;

  case 1196:
#line 6123 "fgl.yacc"
    {pdf_rep_struct.output_mode='P';strcpy(pdf_rep_struct.output_loc,yyvsp[0].str);}
    break;

  case 1200:
#line 6130 "fgl.yacc"
    {
int a;
set_rep_no_orderby(1);
a=print_bind_definition('O');
print_order_by_type(2,-1);
sprintf(yyval.str,"%d",a);
}
    break;

  case 1201:
#line 6138 "fgl.yacc"
    {
int a;
set_rep_no_orderby(0);
a=print_bind_definition('O');
print_order_by_type(1,a);
sprintf(yyval.str,"%d",a);
A4GL_debug("Order by Gives :%d\n",a);
}
    break;

  case 1202:
#line 6146 "fgl.yacc"
    {
int a;
set_rep_no_orderby(0);
a=print_bind_definition('O');
print_order_by_type(2,a);
sprintf(yyval.str,"%d",a);
A4GL_debug("Order by Gives :%d\n",a);
}
    break;

  case 1203:
#line 6158 "fgl.yacc"
    { 
		rep_type=REP_TYPE_NORMAL; 
		clr_function_constants (); 
		clr_variable(); 
		lastlineno=yylineno; 
		init_report_structure(&rep_struct); 
		}
    break;

  case 1204:
#line 6167 "fgl.yacc"
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

  case 1205:
#line 6178 "fgl.yacc"
    {
		lastlineno=yylineno;
		}
    break;

  case 1206:
#line 6182 "fgl.yacc"
    {
		print_variables();
		}
    break;

  case 1207:
#line 6186 "fgl.yacc"
    {
		print_report_2(0,yyvsp[0].str);
		rordcnt=atoi(yyvsp[0].str);
	 A4GL_debug("SET rordcnt=%d %s",rordcnt,yyvsp[0].str);
		}
    break;

  case 1208:
#line 6192 "fgl.yacc"
    {
		print_report_ctrl();
		}
    break;

  case 1209:
#line 6197 "fgl.yacc"
    {
		pop_blockcommand("REPORT");
		print_report_end() ;
		}
    break;

  case 1210:
#line 6205 "fgl.yacc"
    { strcpy(yyval.str,"");
	yyval.ptr=0;
}
    break;

  case 1211:
#line 6208 "fgl.yacc"
    {
	yyval.ptr=yyvsp[0].ptr;
//sprintf($<str>$,"%s", $<str>2);
}
    break;

  case 1212:
#line 6217 "fgl.yacc"
    {
if (!in_command("REPORT")) {
	a4gl_yyerror("PAUSE can only be used in reportes");
	YYERROR;
        }

print_pause(yyvsp[0].str) ;
}
    break;

  case 1213:
#line 6228 "fgl.yacc"
    {strcpy(yyval.str,"\"\"");}
    break;

  case 1215:
#line 6235 "fgl.yacc"
    {
rep_type=REP_TYPE_PDF;
clr_function_constants();
clr_variable(); 
lastlineno=yylineno; 
pdf_init_report_structure(&pdf_rep_struct);
}
    break;

  case 1216:
#line 6243 "fgl.yacc"
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

  case 1217:
#line 6253 "fgl.yacc"
    {
lastlineno=yylineno;
}
    break;

  case 1218:
#line 6256 "fgl.yacc"
    {
	print_variables();
}
    break;

  case 1219:
#line 6260 "fgl.yacc"
    {
//print_variables();
resize_paper(&pdf_rep_struct);
	print_report_2(1,yyvsp[0].str);
A4GL_debug("SET rordcnt=%d (%s)",rordcnt,yyvsp[0].str);
	rordcnt=atoi(yyvsp[0].str);
}
    break;

  case 1220:
#line 6268 "fgl.yacc"
    {
print_report_ctrl();
}
    break;

  case 1221:
#line 6271 "fgl.yacc"
    {
	pop_blockcommand("REPORT");
	print_report_end();
}
    break;

  case 1222:
#line 6277 "fgl.yacc"
    { strcpy(yyval.str,yyvsp[0].str); }
    break;

  case 1223:
#line 6281 "fgl.yacc"
    {new_counter();
   		addmap("CALL",yyvsp[-1].str,curr_func,yylineno,infilename);
   		}
    break;

  case 1224:
#line 6285 "fgl.yacc"
    {
		sprintf(yyval.str,"%d",get_counter_val());drop_counter();
		}
    break;

  case 1225:
#line 6289 "fgl.yacc"
    {
		print_pdf_call(yyvsp[-5].str,yyvsp[-2].ptr,yyvsp[-1].str);
   		}
    break;

  case 1226:
#line 6293 "fgl.yacc"
    {
	print_returning();
   }
    break;

  case 1227:
#line 6299 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 1228:
#line 6300 "fgl.yacc"
    { strcpy(yyval.str,"_rep.right_margin"); }
    break;

  case 1229:
#line 6301 "fgl.yacc"
    { sprintf(yyval.str,"%s",yyvsp[0].str); }
    break;

  case 1230:
#line 6302 "fgl.yacc"
    { sprintf(yyval.str,"%s",yyvsp[0].str); }
    break;

  case 1231:
#line 6307 "fgl.yacc"
    {
print_system_run(0,0);
}
    break;

  case 1232:
#line 6309 "fgl.yacc"
    {
print_system_run(1,yyvsp[0].str);
}
    break;

  case 1233:
#line 6312 "fgl.yacc"
    {
print_system_run(2,0);
}
    break;

  case 1234:
#line 6316 "fgl.yacc"
    {
print_system_run(0,0);
}
    break;

  case 1235:
#line 6319 "fgl.yacc"
    {
print_system_run(0,0);
/* FIXME */
}
    break;

  case 1236:
#line 6326 "fgl.yacc"
    {
	print_exec_sql(yyvsp[0].str);
}
    break;

  case 1237:
#line 6331 "fgl.yacc"
    {sprintf(yyval.str, "%s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1238:
#line 6332 "fgl.yacc"
    {sprintf(yyval.str,  "%s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1239:
#line 6333 "fgl.yacc"
    {sprintf(yyval.str,"%s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1240:
#line 6334 "fgl.yacc"
    {sprintf(yyval.str,"%s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1241:
#line 6339 "fgl.yacc"
    { print_exec_sql(yyvsp[0].str); }
    break;

  case 1242:
#line 6340 "fgl.yacc"
    { print_exec_sql(yyvsp[0].sql_string); 
	free(yyvsp[0].sql_string);
}
    break;

  case 1243:
#line 6346 "fgl.yacc"
    {insql=1;}
    break;

  case 1244:
#line 6346 "fgl.yacc"
    {insql=0;}
    break;

  case 1245:
#line 6346 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-7].str," ",yyvsp[-5].str," ",yyvsp[-4].str,yyvsp[-2].sql_string,yyvsp[-1].str,yyvsp[0].str,0);
		free(yyvsp[-2].sql_string);
	}
    break;

  case 1246:
#line 6351 "fgl.yacc"
    {insql=1;}
    break;

  case 1247:
#line 6351 "fgl.yacc"
    {insql=0;}
    break;

  case 1248:
#line 6351 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-8].str," ",yyvsp[-6].str," ",yyvsp[-5].str,yyvsp[-3].sql_string,yyvsp[-2].str, " ",yyvsp[-1].str,yyvsp[0].str,0);
		free(yyvsp[-3].sql_string);
	}
    break;

  case 1249:
#line 6359 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1250:
#line 6360 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1252:
#line 6365 "fgl.yacc"
    {sprintf(yyval.str,"%s%s",yyvsp[-1].str,yyvsp[0].str); }
    break;

  case 1253:
#line 6370 "fgl.yacc"
    {sprintf(yyval.str," IN %s",yyvsp[0].str);}
    break;

  case 1254:
#line 6371 "fgl.yacc"
    {sprintf(yyval.str," EXTENT SIZE %s",yyvsp[0].str); }
    break;

  case 1255:
#line 6372 "fgl.yacc"
    {sprintf(yyval.str," NEXT SIZE %s",yyvsp[0].str); }
    break;

  case 1256:
#line 6373 "fgl.yacc"
    {sprintf(yyval.str," LOCK MODE PAGE");}
    break;

  case 1257:
#line 6374 "fgl.yacc"
    {sprintf(yyval.str," LOCK MODE ROW");}
    break;

  case 1259:
#line 6379 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1260:
#line 6379 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1262:
#line 6383 "fgl.yacc"
    {sprintf(yyval.str,"%s%s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1263:
#line 6387 "fgl.yacc"
    {sprintf(yyval.str," IN %s",yyvsp[0].str);}
    break;

  case 1264:
#line 6388 "fgl.yacc"
    {sprintf(yyval.str,"FILLFACTOR %s",yyvsp[0].str);}
    break;

  case 1265:
#line 6391 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s %s %s %s %s",yyvsp[-7].str,yyvsp[-6].str,yyvsp[-5].str,yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1266:
#line 6392 "fgl.yacc"
    {
		a4gl_yyerror("You cannot create a database from within Aubit4gl - if the target database allows - prepare and execute it manually");
	}
    break;

  case 1267:
#line 6395 "fgl.yacc"
    {
		a4gl_yyerror("You cannot drop a database from within Aubit4gl - if the target database allows - prepare and execute it manually");
	}
    break;

  case 1268:
#line 6398 "fgl.yacc"
    {
		sprintf(yyval.str,"%s %s FOR %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[0].str);
	}
    break;

  case 1269:
#line 6401 "fgl.yacc"
    {
		sprintf(yyval.str,"%s %s",yyvsp[-1].str,yyvsp[0].str);
	}
    break;

  case 1270:
#line 6407 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1271:
#line 6409 "fgl.yacc"
    {
if (A4GL_isyes(acl_getenv("A4GL_OMIT_NO_LOG"))) {
	strcpy(yyval.str,"");
} else {
	sprintf(yyval.str," %s ",yyvsp[0].str);
}
}
    break;

  case 1273:
#line 6422 "fgl.yacc"
    {sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1274:
#line 6426 "fgl.yacc"
    {sprintf(yyval.str,"%s ASC",yyvsp[-1].str);}
    break;

  case 1275:
#line 6427 "fgl.yacc"
    {sprintf(yyval.str,"%s DESC",yyvsp[-1].str);}
    break;

  case 1277:
#line 6432 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1278:
#line 6435 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",",yyvsp[0].sql_string,0);
	}
    break;

  case 1279:
#line 6441 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1280:
#line 6444 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1281:
#line 6452 "fgl.yacc"
    {sprintf(yyval.str,"%s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1283:
#line 6459 "fgl.yacc"
    {
	yyval.sql_string=make_sql_string(yyvsp[-2].str," ",yyvsp[-1].str," ",yyvsp[0].sql_string,0);
	print_exec_sql(yyval.sql_string); 
}
    break;

  case 1284:
#line 6463 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("ALTER INDEX ",yyvsp[-1].str," TO CLUSTER",0);
		print_exec_sql(yyval.sql_string); 
		}
    break;

  case 1285:
#line 6467 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("ALTER INDEX ",yyvsp[-1].str," TO NOT CLUSTER",0);
		}
    break;

  case 1286:
#line 6473 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1287:
#line 6476 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",",yyvsp[0].sql_string,0);
	}
    break;

  case 1288:
#line 6485 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1289:
#line 6488 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1290:
#line 6491 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1291:
#line 6494 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1292:
#line 6497 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1293:
#line 6500 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1294:
#line 6503 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1295:
#line 6510 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("ADD ",yyvsp[0].sql_string,0);
	}
    break;

  case 1296:
#line 6513 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("ADD (",yyvsp[-1].sql_string,")",0);
	}
    break;

  case 1297:
#line 6520 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1298:
#line 6523 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string," BEFORE ",yyvsp[0].str,0);
	}
    break;

  case 1299:
#line 6529 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1300:
#line 6532 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",",yyvsp[0].sql_string,0);
	}
    break;

  case 1301:
#line 6539 "fgl.yacc"
    {
		sprintf(yyval.str,"DROP %s",yyvsp[0].str);
	}
    break;

  case 1302:
#line 6542 "fgl.yacc"
    {
		sprintf(yyval.str,"DROP (%s)",yyvsp[-1].str);
	}
    break;

  case 1304:
#line 6550 "fgl.yacc"
    {
		sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);
	}
    break;

  case 1306:
#line 6559 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("MODIFY ",yyvsp[0].sql_string,0);
	}
    break;

  case 1307:
#line 6562 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("MODIFY (",yyvsp[-1].sql_string,")",0);
	}
    break;

  case 1308:
#line 6568 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1309:
#line 6571 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",",yyvsp[0].sql_string,0);
	}
    break;

  case 1310:
#line 6577 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1311:
#line 6584 "fgl.yacc"
    {strcpy(yyval.str,"LOCK MODE (PAGE)");}
    break;

  case 1312:
#line 6585 "fgl.yacc"
    {strcpy(yyval.str,"LOCK MODE (ROW)");}
    break;

  case 1313:
#line 6589 "fgl.yacc"
    {
		sprintf(yyval.str,"MODIFY NEXT SIZE %d",atoi(yyvsp[0].str));
	}
    break;

  case 1314:
#line 6599 "fgl.yacc"
    {
		sprintf(yyval.str,"ADD CONSTRAINT %s%s",yyvsp[-1].sql_string,yyvsp[0].str);
	}
    break;

  case 1315:
#line 6602 "fgl.yacc"
    {
		sprintf(yyval.str,"ADD CONSTRAINT (%s)",yyvsp[-1].sql_string);
	}
    break;

  case 1316:
#line 6608 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-1].sql_string,yyvsp[0].str,0);
}
    break;

  case 1317:
#line 6610 "fgl.yacc"
    {
	yyval.sql_string=make_sql_string(yyvsp[-3].sql_string,",",yyvsp[-1].sql_string,yyvsp[0].str, 0);
}
    break;

  case 1318:
#line 6615 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1319:
#line 6616 "fgl.yacc"
    {sprintf(yyval.str," %s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1320:
#line 6621 "fgl.yacc"
    { sprintf(yyval.str,"DROP CONSTRAINT %s",yyvsp[0].str); }
    break;

  case 1321:
#line 6622 "fgl.yacc"
    {
		sprintf(yyval.str,"DROP CONSTRAINT (%s)",yyvsp[-1].str);
	}
    break;

  case 1322:
#line 6628 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1323:
#line 6629 "fgl.yacc"
    {sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1327:
#line 6655 "fgl.yacc"
    {sprintf(yyval.str,"%s %s /*FIXME */",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1333:
#line 6661 "fgl.yacc"
    { 
	print_set_conn(yyvsp[0].str);
}
    break;

  case 1334:
#line 6664 "fgl.yacc"
    {
	print_set_options("conn",yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 1335:
#line 6667 "fgl.yacc"
    {
	print_set_options("stmt",yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 1336:
#line 6673 "fgl.yacc"
    {strcpy(yyval.str,"\"default\"");}
    break;

  case 1338:
#line 6679 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1340:
#line 6690 "fgl.yacc"
    {
		print_sleep();
	}
    break;

  case 1341:
#line 6704 "fgl.yacc"
    {
		print_sql_commit(0);
		}
    break;

  case 1342:
#line 6713 "fgl.yacc"
    { insql=1;start_bind('i',0);}
    break;

  case 1343:
#line 6713 "fgl.yacc"
    {
	yyval.sql_string=make_sql_string(yyvsp[-4].str," ",yyvsp[-2].str," ",yyvsp[-1].str," ",yyvsp[0].sql_string,0);
}
    break;

  case 1344:
#line 6718 "fgl.yacc"
    {insql=1;}
    break;

  case 1345:
#line 6718 "fgl.yacc"
    {
insql=0;
	//printf("Value = %s\n",$<sql_string>4);
yyval.sql_string=make_sql_string(yyvsp[-4].str," (",yyvsp[-1].sql_string,")",0);}
    break;

  case 1346:
#line 6723 "fgl.yacc"
    {yyval.sql_string=yyvsp[0].sql_string;}
    break;

  case 1347:
#line 6726 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1348:
#line 6728 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1350:
#line 6735 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1351:
#line 6739 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	//printf(" 1. Value = %s\n",$<sql_string>$);
	}
    break;

  case 1352:
#line 6743 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",", yyvsp[0].sql_string,0);
	//printf(" 2. Value = %s\n",$<sql_string>$);
	}
    break;

  case 1353:
#line 6750 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1354:
#line 6753 "fgl.yacc"
    {
		yyval.sql_string=strdup("NULL");
	}
    break;

  case 1355:
#line 6760 "fgl.yacc"
    {
      print_fetch_1();
    }
    break;

  case 1356:
#line 6764 "fgl.yacc"
    {
      print_fetch_2();
      print_fetch_3(yyvsp[-1].str,yyvsp[0].str);
    }
    break;

  case 1357:
#line 6770 "fgl.yacc"
    {sprintf(yyval.str,"%s",yyvsp[0].str);doing_declare=1;}
    break;

  case 1358:
#line 6775 "fgl.yacc"
    {sprintf(yyval.str,"%s, %s",yyvsp[0].str,yyvsp[-1].str);
addmap("Fetch Cursor",yyvsp[0].str,curr_func,yylineno,infilename);
}
    break;

  case 1359:
#line 6779 "fgl.yacc"
    {sprintf(yyval.str,"%s, %d, 1",yyvsp[0].str,FETCH_RELATIVE);

addmap("Fetch Cursor",yyvsp[0].str,curr_func,yylineno,infilename);
}
    break;

  case 1360:
#line 6785 "fgl.yacc"
    {
A4GL_debug("no into\n");
strcpy(yyval.str,"0,0");
}
    break;

  case 1361:
#line 6788 "fgl.yacc"
    {
 A4GL_debug("FETCH INTO  ...");
	/* start_bind('i',0,-1); */
    start_bind('o',0);
}
    break;

  case 1362:
#line 6794 "fgl.yacc"
    {
	int no;
	no=get_bind_cnt('o');
	sprintf(yyval.str,"%d,obind",no);
}
    break;

  case 1363:
#line 6801 "fgl.yacc"
    {
A4GL_debug("no into\n");
strcpy(yyval.str,"0,0");
}
    break;

  case 1364:
#line 6805 "fgl.yacc"
    {
 A4GL_debug("FETCH INTO  ...");
	/* start_bind('i',0,-1); */
    start_bind('o',0);
}
    break;

  case 1365:
#line 6810 "fgl.yacc"
    {
/*
int ni;
ni=print_bind('i');
sprintf($<str>$,"%d,ibind",ni);
*/
}
    break;

  case 1366:
#line 6820 "fgl.yacc"
    {
		sprintf(yyval.str,"%d,1",FETCH_ABSOLUTE);}
    break;

  case 1367:
#line 6823 "fgl.yacc"
    {sprintf(yyval.str,"%d,-1",FETCH_ABSOLUTE);}
    break;

  case 1368:
#line 6825 "fgl.yacc"
    {sprintf(yyval.str,"%d,1",FETCH_RELATIVE);}
    break;

  case 1369:
#line 6827 "fgl.yacc"
    {sprintf(yyval.str,"%d,-1",FETCH_RELATIVE);}
    break;

  case 1370:
#line 6829 "fgl.yacc"
    {sprintf(yyval.str,"%d,-1",FETCH_RELATIVE);}
    break;

  case 1371:
#line 6831 "fgl.yacc"
    {sprintf(yyval.str,"%d,0",FETCH_RELATIVE);}
    break;

  case 1372:
#line 6833 "fgl.yacc"
    {sprintf(yyval.str,"%d,A4GL_pop_int()",FETCH_RELATIVE);}
    break;

  case 1373:
#line 6835 "fgl.yacc"
    {sprintf(yyval.str,"%d,A4GL_pop_int()",FETCH_ABSOLUTE);}
    break;

  case 1374:
#line 6841 "fgl.yacc"
    {
 
rm_quotes(yyvsp[0].str);
sprintf(yyval.str," %s %s %s %s ",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str
);}
    break;

  case 1375:
#line 6851 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].str," ",yyvsp[-1].str," ",yyvsp[0].sql_string,0);
		}
    break;

  case 1376:
#line 6858 "fgl.yacc"
    {sprintf(yyval.str,"%s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1378:
#line 6864 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1379:
#line 6867 "fgl.yacc"
    {sprintf(yyval.str,"%s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1382:
#line 6874 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1385:
#line 6879 "fgl.yacc"
    {
print_sql_commit(-1);
}
    break;

  case 1386:
#line 6884 "fgl.yacc"
    {
		print_sql_commit(1);
	}
    break;

  case 1387:
#line 6891 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1388:
#line 6892 "fgl.yacc"
    {
		strcpy(yyval.str,"EXCLUSIVE");
	}
    break;

  case 1389:
#line 6899 "fgl.yacc"
    {
if (strcmp(yyvsp[-1].str,"?")==0) {
	print_init_conn(0);
} else {
	print_init_conn(yyvsp[-1].str);
}
}
    break;

  case 1390:
#line 6910 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1391:
#line 6911 "fgl.yacc"
    {sprintf(yyval.str,"%s@%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1392:
#line 6912 "fgl.yacc"
    {strcpy(yyval.str, A4GL_strip_quotes (yyvsp[0].str));}
    break;

  case 1393:
#line 6915 "fgl.yacc"
    {insql=1;}
    break;

  case 1394:
#line 6915 "fgl.yacc"
    {
print_undo_use(yyvsp[-2].str);
insql=0;strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1395:
#line 6920 "fgl.yacc"
    {
		 A4GL_lex_printcomment("/*  schema */\n");
			print_exec_sql(yyvsp[0].sql_string);
			strcpy(yyval.str,"Schema");
	}
    break;

  case 1396:
#line 6925 "fgl.yacc"
    {
	 A4GL_lex_printcomment("/*  schema  2*/\n");
		print_exec_sql(yyvsp[0].sql_string);
		strcpy(yyval.str,"Schema Element");
	}
    break;

  case 1398:
#line 6931 "fgl.yacc"
    {
		print_exec_sql(yyvsp[0].str);
 	}
    break;

  case 1400:
#line 6935 "fgl.yacc"
    {
	 A4GL_lex_printcomment("/*  delete 1 */\n");
		print_exec_sql_bound(yyvsp[0].str);
		strcpy(yyval.str,"Delete where current...");
	}
    break;

  case 1401:
#line 6940 "fgl.yacc"
    {
	 A4GL_lex_printcomment("/*  delete 2 */\n");
		print_exec_sql_bound(yyvsp[0].sql_string);
		strcpy(yyval.str,"Delete where ...");
	}
    break;

  case 1402:
#line 6945 "fgl.yacc"
    {
		strcpy(yyval.str,"Fetch");
	 A4GL_lex_printcomment("/*  fetch */\n");
	}
    break;

  case 1403:
#line 6949 "fgl.yacc"
    {
	 A4GL_lex_printcomment("/*  insert */\n");
		print_exec_sql_bound(yyvsp[0].sql_string);
		strcpy(yyval.str,"insert");
	}
    break;

  case 1405:
#line 6955 "fgl.yacc"
    {
		print_do_select(yyvsp[0].sql_string);
		strcpy(yyval.str,"select");
	}
    break;

  case 1406:
#line 6959 "fgl.yacc"
    {
		print_exec_sql_bound(yyvsp[0].sql_string);
		strcpy(yyval.str,"update");
	}
    break;

  case 1407:
#line 6967 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s %s %s %s",yyvsp[-6].str,yyvsp[-5].str,yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1408:
#line 6970 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1409:
#line 6972 "fgl.yacc"
    {sprintf(yyval.str," %s ",yyvsp[0].str);}
    break;

  case 1410:
#line 6977 "fgl.yacc"
    {sprintf(yyval.str," %s ",yyvsp[0].str);}
    break;

  case 1413:
#line 6984 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1417:
#line 6991 "fgl.yacc"
    {sprintf(yyval.str," %s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1418:
#line 6994 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1419:
#line 6996 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1421:
#line 7002 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1423:
#line 7008 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1426:
#line 7018 "fgl.yacc"
    {
yyval.sql_string=make_sql_string(yyvsp[-5].str," ",yyvsp[-4].str," ",yyvsp[-3].str," ",yyvsp[-2].str," ",yyvsp[-1].sql_string," ",yyvsp[0].str,0);
}
    break;

  case 1427:
#line 7023 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1428:
#line 7025 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1430:
#line 7031 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1431:
#line 7034 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1433:
#line 7040 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("CHECK(",yyvsp[-1].sql_string,")",0);
	}
    break;

  case 1434:
#line 7048 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s %s",yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1435:
#line 7053 "fgl.yacc"
    {sprintf(yyval.str," %s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1438:
#line 7063 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1440:
#line 7069 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1441:
#line 7074 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1442:
#line 7075 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1443:
#line 7077 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1445:
#line 7083 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1446:
#line 7088 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1447:
#line 7091 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1448:
#line 7094 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1449:
#line 7101 "fgl.yacc"
    {sprintf(yyval.str," %s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1450:
#line 7102 "fgl.yacc"
    {sprintf(yyval.str," DEFAULT USER");}
    break;

  case 1451:
#line 7103 "fgl.yacc"
    {sprintf(yyval.str," DEFAULT TODAY");}
    break;

  case 1452:
#line 7105 "fgl.yacc"
    {sprintf(yyval.str," %s",yyvsp[0].str);}
    break;

  case 1453:
#line 7118 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-3].str," ",yyvsp[-2].str," ",yyvsp[-1].str," ",yyvsp[0].sql_string,0);
	}
    break;

  case 1454:
#line 7123 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1456:
#line 7127 "fgl.yacc"
    {
		yyval.sql_string=strdup("");
	}
    break;

  case 1457:
#line 7129 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1458:
#line 7136 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1459:
#line 7139 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-1].sql_string,yyvsp[0].sql_string,0);
	}
    break;

  case 1460:
#line 7145 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-1].sql_string,yyvsp[0].str,0);
	}
    break;

  case 1461:
#line 7153 "fgl.yacc"
    {
		sprintf(yyval.str," %s ",yyvsp[0].str);
		yyval.sql_string=strdup(yyval.str);
	}
    break;

  case 1462:
#line 7157 "fgl.yacc"
    {
		sprintf(yyval.str," %s ",yyvsp[0].str);
		yyval.sql_string=strdup(yyval.str);
	}
    break;

  case 1463:
#line 7161 "fgl.yacc"
    {
		sprintf(yyval.str," %s ",yyvsp[0].str);
		yyval.sql_string=strdup(yyval.str);
	}
    break;

  case 1464:
#line 7165 "fgl.yacc"
    {
		sprintf(yyval.str," %s ",yyvsp[0].str);
		yyval.sql_string=strdup(yyval.str);
	}
    break;

  case 1465:
#line 7169 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1466:
#line 7172 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-3].str," ",yyvsp[-2].str," ",yyvsp[-1].sql_string," ",yyvsp[0].str,0);
	}
    break;

  case 1467:
#line 7175 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(" PRIMARY KEY ",0);
	}
    break;

  case 1468:
#line 7183 "fgl.yacc"
    {
yyval.sql_string=make_sql_string(yyvsp[-2].str," ",yyvsp[-1].str," ",yyvsp[0].str,0);
}
    break;

  case 1469:
#line 7190 "fgl.yacc"
    {sprintf(yyval.str," %s",yyvsp[0].str);}
    break;

  case 1472:
#line 7199 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-1].sql_string," ",yyvsp[0].sql_string,0);
	}
    break;

  case 1473:
#line 7205 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1474:
#line 7208 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1475:
#line 7219 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-1].str," ",yyvsp[0].sql_string,0);
	}
    break;

  case 1476:
#line 7226 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("GROUP BY ",yyvsp[0].sql_string,0);
	}
    break;

  case 1477:
#line 7232 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1478:
#line 7235 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",",yyvsp[0].sql_string,0);
	}
    break;

  case 1479:
#line 7242 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("WHERE ",yyvsp[0].sql_string,0);
	}
    break;

  case 1480:
#line 7249 "fgl.yacc"
    {
		sprintf(yyval.str,"%s %s",yyvsp[-1].str,yyvsp[0].str);
	}
    break;

  case 1482:
#line 7256 "fgl.yacc"
    {
		sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);
	}
    break;

  case 1483:
#line 7262 "fgl.yacc"
    {sprintf(yyval.str," %s ", yyvsp[0].str);}
    break;

  case 1484:
#line 7263 "fgl.yacc"
    {sprintf(yyval.str," %s %s ",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1485:
#line 7264 "fgl.yacc"
    {sprintf(yyval.str," %s (%s) ",yyvsp[-3].str,yyvsp[-1].str);}
    break;

  case 1487:
#line 7268 "fgl.yacc"
    {sprintf(yyval.str,"%s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1489:
#line 7273 "fgl.yacc"
    { sprintf(yyval.str," %s,%s ",yyvsp[-2].str,yyvsp[0].str);  }
    break;

  case 1490:
#line 7280 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-3].str," ",yyvsp[-2].sql_string," ",yyvsp[-1].sql_string," ",yyvsp[0].sql_string,0);
	}
    break;

  case 1491:
#line 7285 "fgl.yacc"
    { yyval.sql_string=strdup("");}
    break;

  case 1492:
#line 7286 "fgl.yacc"
    {yyval.sql_string=yyvsp[0].sql_string;}
    break;

  case 1493:
#line 7289 "fgl.yacc"
    {
	yyval.sql_string=strdup("");
}
    break;

  case 1494:
#line 7292 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
}
    break;

  case 1495:
#line 7297 "fgl.yacc"
    {yyval.sql_string=strdup("");}
    break;

  case 1496:
#line 7298 "fgl.yacc"
    {yyval.sql_string=yyvsp[0].sql_string;}
    break;

  case 1497:
#line 7303 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1498:
#line 7306 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string," OR ",yyvsp[0].sql_string,0);
	}
    break;

  case 1499:
#line 7312 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1500:
#line 7315 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string," AND ",yyvsp[0].sql_string,0);
	}
    break;

  case 1501:
#line 7321 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1502:
#line 7324 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-1].str," ",yyvsp[0].sql_string,0);
	}
    break;

  case 1503:
#line 7330 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1504:
#line 7333 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].str,yyvsp[-1].sql_string,yyvsp[0].str,0);
	}
    break;

  case 1505:
#line 7340 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-1].str," ",yyvsp[0].sql_string,0);}
    break;

  case 1506:
#line 7341 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-1].str," ",yyvsp[0].sql_string,0);}
    break;

  case 1507:
#line 7370 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1508:
#line 7372 "fgl.yacc"
    {sprintf(yyval.str," %s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1509:
#line 7376 "fgl.yacc"
    {yyval.sql_string=yyvsp[0].sql_string;}
    break;

  case 1511:
#line 7389 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-4].sql_string," IN (",yyvsp[-1].str,")",0);
	}
    break;

  case 1512:
#line 7392 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string," ",yyvsp[-1].str," ",yyvsp[0].sql_string,0);
	}
    break;

  case 1513:
#line 7395 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-4].sql_string," NOT IN (",yyvsp[-1].str,")",0);
	}
    break;

  case 1514:
#line 7398 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string," ",yyvsp[-1].str," ",yyvsp[0].sql_string,0);
	}
    break;

  case 1516:
#line 7406 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1517:
#line 7409 "fgl.yacc"
    {
		strcpy(yyval.str,yyvsp[0].sql_string);
	}
    break;

  case 1519:
#line 7415 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1521:
#line 7421 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string," ",yyvsp[-1].str," IS NULL",0);
	}
    break;

  case 1522:
#line 7424 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string," ",yyvsp[-1].str," IS NOT NULL",0);
	}
    break;

  case 1523:
#line 7427 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string," ",yyvsp[-1].str," ",yyvsp[0].sql_string,0);
	}
    break;

  case 1524:
#line 7430 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-5].sql_string," ",yyvsp[-4].str," BETWEEN ",yyvsp[-2].sql_string," AND ",yyvsp[0].sql_string,0);
	}
    break;

  case 1525:
#line 7433 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-3].sql_string," ",yyvsp[-2].str," ",yyvsp[-1].sql_string,yyvsp[0].str,0);
	}
    break;

  case 1526:
#line 7436 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-3].sql_string," ",yyvsp[-2].str," ",yyvsp[-1].sql_string,yyvsp[0].str,0);
	}
    break;

  case 1527:
#line 7439 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-3].sql_string," ",yyvsp[-2].str," ",yyvsp[-1].sql_string,yyvsp[0].str,0);
	}
    break;

  case 1528:
#line 7442 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-3].sql_string," ",yyvsp[-2].str," ",yyvsp[-1].sql_string,yyvsp[0].str,0);
	}
    break;

  case 1529:
#line 7447 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-4].sql_string," ",yyvsp[-3].str," MATCHES ",yyvsp[-1].sql_string,yyvsp[0].str,0);
	}
    break;

  case 1531:
#line 7454 "fgl.yacc"
    {strcpy(yyval.str,"!=");}
    break;

  case 1537:
#line 7462 "fgl.yacc"
    {strcpy(yyval.str,"<=");}
    break;

  case 1538:
#line 7463 "fgl.yacc"
    {strcpy(yyval.str,">=");}
    break;

  case 1539:
#line 7468 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1540:
#line 7471 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1541:
#line 7475 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1542:
#line 7481 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1543:
#line 7482 "fgl.yacc"
    {strcpy(yyval.str," ALL ");}
    break;

  case 1544:
#line 7483 "fgl.yacc"
    {strcpy(yyval.str," DISTINCT ");}
    break;

  case 1545:
#line 7484 "fgl.yacc"
    {
		ansi_violation("Use DISTINCT not UNIQUE",0);
		strcpy(yyval.str," DISTINCT ");
	}
    break;

  case 1550:
#line 7504 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1552:
#line 7508 "fgl.yacc"
    {strcpy(yyval.str,"SERIAL");}
    break;

  case 1553:
#line 7509 "fgl.yacc"
    {sprintf(yyval.str,"SERIAL(%s)",yyvsp[-1].str);}
    break;

  case 1555:
#line 7512 "fgl.yacc"
    {sprintf(yyval.str," DECIMAL(%s%s)",yyvsp[-2].str,yyvsp[-1].str);}
    break;

  case 1556:
#line 7514 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s %s",yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1564:
#line 7523 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1565:
#line 7525 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s %s %s",yyvsp[-5].str,yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1566:
#line 7527 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1568:
#line 7530 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1570:
#line 7533 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s %s %s %s",yyvsp[-6].str,yyvsp[-5].str,yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1574:
#line 7538 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1575:
#line 7540 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s %s %s",yyvsp[-5].str,yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1576:
#line 7543 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1577:
#line 7544 "fgl.yacc"
    {
		sprintf(yyval.str,",%s",yyvsp[0].str);
}
    break;

  case 1578:
#line 7551 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1582:
#line 7556 "fgl.yacc"
    {sprintf(yyval.str," %s",yyvsp[0].str);}
    break;

  case 1586:
#line 7572 "fgl.yacc"
    { 
			if (A4GL_escape_quote_owner()) {
				sprintf(yyval.str,"\\\"%s\\\"%s%s", A4GL_strip_quotes (yyvsp[-2].str),yyvsp[-1].str,yyvsp[0].str); addmap("Use Table",yyval.str,curr_func,yylineno,infilename); 
			} else {
				sprintf(yyval.str,"\"%s\"%s%s", A4GL_strip_quotes (yyvsp[-2].str),yyvsp[-1].str,yyvsp[0].str); addmap("Use Table",yyval.str,curr_func,yylineno,infilename); 
			}
	}
    break;

  case 1587:
#line 7579 "fgl.yacc"
    {
		sprintf(yyval.str," %s", A4GL_strip_quotes (yyvsp[0].str));
		addmap("Use Table",yyval.str,curr_func,yylineno,infilename);
	}
    break;

  case 1588:
#line 7583 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str); addmap("Use Table",yyvsp[0].str,curr_func,yylineno,infilename); }
    break;

  case 1589:
#line 7584 "fgl.yacc"
    { sprintf(yyval.str," %s%s%s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str); addmap("Use Table",yyval.str,curr_func,yylineno,infilename); }
    break;

  case 1590:
#line 7585 "fgl.yacc"
    { 
                        if (A4GL_escape_quote_owner()) {
				sprintf(yyval.str," %s:\\\"%s\\\".%s",yyvsp[-4].str,A4GL_strip_quotes(yyvsp[-2].str),yyvsp[0].str); addmap("Use Table",yyval.str,curr_func,yylineno,infilename); 
                        } else {
				sprintf(yyval.str," %s:%s.%s",yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str); addmap("Use Table",yyval.str,curr_func,yylineno,infilename); 
                        }
	}
    break;

  case 1591:
#line 7593 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[-2].str); addmap("Use Table",yyvsp[-2].str,curr_func,yylineno,infilename); }
    break;

  case 1592:
#line 7594 "fgl.yacc"
    { sprintf(yyval.str," %s@%s%s%s",yyvsp[-4].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str); addmap("Use Table",yyval.str,curr_func,yylineno,infilename); }
    break;

  case 1593:
#line 7595 "fgl.yacc"
    { 
                        if (A4GL_escape_quote_owner()) {
				sprintf(yyval.str," %s@%s:\\\"%s\\\".%s",yyvsp[-6].str,yyvsp[-4].str,A4GL_strip_quotes(yyvsp[-2].str),yyvsp[0].str); addmap("Use Table",yyval.str,curr_func,yylineno,infilename); 
                        } else {
				sprintf(yyval.str," %s@%s:%s.%s",yyvsp[-6].str,yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str); addmap("Use Table",yyval.str,curr_func,yylineno,infilename); 
                        }
	}
    break;

  case 1594:
#line 7606 "fgl.yacc"
    { 
			if (A4GL_escape_quote_owner()) {
				sprintf(yyval.str,"\\\"%s\\\"%s%s", A4GL_strip_quotes (yyvsp[-2].str),yyvsp[-1].str,yyvsp[0].str); addmap("Use Index",yyval.str,curr_func,yylineno,infilename); 
			} else {
				sprintf(yyval.str,"\"%s\"%s%s", A4GL_strip_quotes (yyvsp[-2].str),yyvsp[-1].str,yyvsp[0].str); addmap("Use Index",yyval.str,curr_func,yylineno,infilename); 
			}
	}
    break;

  case 1595:
#line 7613 "fgl.yacc"
    {
		sprintf(yyval.str," %s", A4GL_strip_quotes (yyvsp[0].str));
		addmap("Use Index",yyval.str,curr_func,yylineno,infilename);
	}
    break;

  case 1596:
#line 7618 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str); addmap("Use Index",yyvsp[0].str,curr_func,yylineno,infilename); }
    break;

  case 1597:
#line 7619 "fgl.yacc"
    { sprintf(yyval.str," %s%s%s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str); addmap("Use Index",yyval.str,curr_func,yylineno,infilename); }
    break;

  case 1598:
#line 7620 "fgl.yacc"
    { 
                        if (A4GL_escape_quote_owner()) {
				sprintf(yyval.str," %s:\\\"%s\\\".%s",yyvsp[-4].str,A4GL_strip_quotes(yyvsp[-2].str),yyvsp[0].str); addmap("Use Index",yyval.str,curr_func,yylineno,infilename); 
                        } else {
				sprintf(yyval.str," %s:%s.%s",yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str); addmap("Use Index",yyval.str,curr_func,yylineno,infilename); 
                        }
	}
    break;

  case 1599:
#line 7628 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[-2].str); addmap("Use Index",yyvsp[-2].str,curr_func,yylineno,infilename); }
    break;

  case 1600:
#line 7629 "fgl.yacc"
    { sprintf(yyval.str," %s@%s%s%s",yyvsp[-4].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str); addmap("Use Index",yyval.str,curr_func,yylineno,infilename); }
    break;

  case 1601:
#line 7630 "fgl.yacc"
    { 
                        if (A4GL_escape_quote_owner()) {
				sprintf(yyval.str," %s@%s:\\\"%s\\\".%s",yyvsp[-6].str,yyvsp[-4].str,A4GL_strip_quotes(yyvsp[-2].str),yyvsp[0].str); addmap("Use Index",yyval.str,curr_func,yylineno,infilename); 
                        } else {
				sprintf(yyval.str," %s@%s:%s.%s",yyvsp[-6].str,yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str); addmap("Use Index",yyval.str,curr_func,yylineno,infilename); 
                        }
	}
    break;

  case 1603:
#line 7656 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1604:
#line 7657 "fgl.yacc"
    {sprintf(yyval.str,"[%s]",yyvsp[-1].str);}
    break;

  case 1605:
#line 7658 "fgl.yacc"
    {sprintf(yyval.str,"[%s,%s]",yyvsp[-3].str,yyvsp[-1].str);}
    break;

  case 1606:
#line 7662 "fgl.yacc"
    {
		strcpy(yyval.str,yyvsp[0].str);
	}
    break;

  case 1607:
#line 7665 "fgl.yacc"
    {
		strcpy(yyval.str,yyvsp[0].str);
	}
    break;

  case 1608:
#line 7671 "fgl.yacc"
    { 
addmap("Use Column",yyvsp[-1].str,curr_func,yylineno,infilename);
sprintf(yyval.str,"%s%s",yyvsp[-1].str,yyvsp[0].str);
}
    break;

  case 1609:
#line 7676 "fgl.yacc"
    {
sprintf(yyval.str,"%s.%s%s",yyvsp[-3].str,yyvsp[-1].str,yyvsp[0].str);
addmap("Use Column",yyval.str,curr_func,yylineno,infilename);
}
    break;

  case 1610:
#line 7681 "fgl.yacc"
    {
sprintf(yyval.str,"%s.%s",yyvsp[-2].str,yyvsp[0].str);
addmap("Use Column",yyval.str,curr_func,yylineno,infilename);
}
    break;

  case 1612:
#line 7692 "fgl.yacc"
    {
	strcpy(yyval.str,convstrsql(yyvsp[0].str));
 A4GL_debug("Set $<str>$ to %s\n",yyval.str);
}
    break;

  case 1616:
#line 7710 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1617:
#line 7713 "fgl.yacc"
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

  case 1618:
#line 7726 "fgl.yacc"
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

  case 1619:
#line 7741 "fgl.yacc"
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

  case 1620:
#line 7753 "fgl.yacc"
    {strcpy(yyval.str,"1,10");}
    break;

  case 1621:
#line 7755 "fgl.yacc"
    {sprintf(yyval.str," %s ,%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1622:
#line 7758 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 1623:
#line 7758 "fgl.yacc"
    {strcpy(yyval.str,"2");}
    break;

  case 1624:
#line 7758 "fgl.yacc"
    {strcpy(yyval.str,"3");}
    break;

  case 1625:
#line 7758 "fgl.yacc"
    {strcpy(yyval.str,"4");}
    break;

  case 1626:
#line 7758 "fgl.yacc"
    {strcpy(yyval.str,"5");}
    break;

  case 1627:
#line 7758 "fgl.yacc"
    {strcpy(yyval.str,"6");}
    break;

  case 1628:
#line 7759 "fgl.yacc"
    {
sprintf(yyval.str,"%d",6+2);
}
    break;

  case 1629:
#line 7762 "fgl.yacc"
    {
sprintf(yyval.str,"%d",atoi(yyvsp[-1].str)+6);
}
    break;

  case 1630:
#line 7767 "fgl.yacc"
    {strcpy(yyval.str,"4");}
    break;

  case 1631:
#line 7767 "fgl.yacc"
    {strcpy(yyval.str,"7");}
    break;

  case 1632:
#line 7767 "fgl.yacc"
    {strcpy(yyval.str,"10");}
    break;

  case 1633:
#line 7767 "fgl.yacc"
    {strcpy(yyval.str,"13");}
    break;

  case 1634:
#line 7767 "fgl.yacc"
    {strcpy(yyval.str,"16");}
    break;

  case 1635:
#line 7767 "fgl.yacc"
    {strcpy(yyval.str,"19");}
    break;

  case 1636:
#line 7769 "fgl.yacc"
    {
strcpy(yyval.str,"25");
}
    break;

  case 1637:
#line 7772 "fgl.yacc"
    {
strcpy(yyval.str,"25");
}
    break;

  case 1652:
#line 7779 "fgl.yacc"
    {sprintf(yyval.str,"FRACTION(%s)",yyvsp[-1].str);}
    break;

  case 1653:
#line 7782 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1654:
#line 7783 "fgl.yacc"
    {sprintf(yyval.str,"%s@%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1655:
#line 7784 "fgl.yacc"
    {strcpy(yyval.str, A4GL_strip_quotes (yyvsp[0].str));}
    break;

  case 1656:
#line 7788 "fgl.yacc"
    {
	print_flush_cursor(yyvsp[0].str);
		addmap("Flush Cursor",yyvsp[0].str,curr_func,yylineno,infilename);
print_undo_use(yyvsp[-2].str);
		}
    break;

  case 1657:
#line 7796 "fgl.yacc"
    {insql=0;chk4var=0;}
    break;

  case 1658:
#line 7796 "fgl.yacc"
    {
		print_declare("",yyvsp[-1].sql_string,yyvsp[-4].str,0,0);
		addmap("Declare Cursor",yyvsp[-4].str,curr_func,yylineno,infilename);
		print_undo_use(yyvsp[-6].str);
		doing_declare=0;
	}
    break;

  case 1659:
#line 7802 "fgl.yacc"
    {insql=0;chk4var=0;}
    break;

  case 1660:
#line 7802 "fgl.yacc"
    {
		print_declare("",yyvsp[-1].sql_string,yyvsp[-5].str,2,0); 
		addmap("Declare Cursor",yyvsp[-5].str,curr_func,yylineno,infilename);
		print_undo_use(yyvsp[-7].str);
		doing_declare=0;
	}
    break;

  case 1661:
#line 7809 "fgl.yacc"
    {insql=0;chk4var=0;}
    break;

  case 1662:
#line 7809 "fgl.yacc"
    {
		print_declare("",yyvsp[-1].sql_string,yyvsp[-3].str,0,1); 
		addmap("Declare Cursor",yyvsp[-3].str,curr_func,yylineno,infilename);
		print_undo_use(yyvsp[-5].str);
		doing_declare=0;
	}
    break;

  case 1663:
#line 7815 "fgl.yacc"
    {insql=0;chk4var=0;}
    break;

  case 1664:
#line 7815 "fgl.yacc"
    {
		print_declare("",yyvsp[-1].sql_string,yyvsp[-5].str,2,1); 
		addmap("Declare Cursor",yyvsp[-5].str,curr_func,yylineno,infilename);
		print_undo_use(yyvsp[-7].str);
		doing_declare=0;
	}
    break;

  case 1665:
#line 7823 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1666:
#line 7824 "fgl.yacc"
    {strcpy(yyval.str," FOR UPDATE");}
    break;

  case 1667:
#line 7825 "fgl.yacc"
    {sprintf(yyval.str," FOR UPDATE OF %s",yyvsp[0].str);}
    break;

  case 1668:
#line 7828 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1669:
#line 7828 "fgl.yacc"
    {sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1671:
#line 7832 "fgl.yacc"
    {sprintf(yyval.str,"%s.%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1672:
#line 7833 "fgl.yacc"
    {
			if (A4GL_escape_quote_owner()) {
				sprintf(yyval.str,"\\\"%s\\\".%s.%s", A4GL_strip_quotes (yyvsp[-4].str),yyvsp[-2].str,yyvsp[0].str);
			} else {
				sprintf(yyval.str,"\"%s\".%s.%s", A4GL_strip_quotes (yyvsp[-4].str),yyvsp[-2].str,yyvsp[0].str);
			}
	}
    break;

  case 1673:
#line 7844 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1674:
#line 7847 "fgl.yacc"
    { 
		yyval.sql_string=make_sql_string(print_curr_spec(1,yyvsp[0].sql_string),0);
	}
    break;

  case 1675:
#line 7853 "fgl.yacc"
    {
		start_bind('i',0);
		start_bind('o',0);
		yyval.sql_string=make_sql_string(print_curr_spec(2,yyvsp[0].str) ,0);
	}
    break;

  case 1676:
#line 7858 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1677:
#line 7866 "fgl.yacc"
    {
	yyval.sql_string=yyvsp[0].sql_string;
	if (strstr(yyvsp[0].str,"FOR UPDATE")) {
		printf("Warning SELECT ... FOR UPDATE when not declaring a cursor currently has no locking effect\n");
	}
}
    break;

  case 1678:
#line 7878 "fgl.yacc"
    { start_bind('i',0); }
    break;

  case 1679:
#line 7879 "fgl.yacc"
    {A4GL_debug("Got select list...\n");}
    break;

  case 1680:
#line 7882 "fgl.yacc"
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

  case 1681:
#line 7897 "fgl.yacc"
    {
		/*$<sql_string>$=make_sql_string("A4GL_push_char(\"", $<str>1, " ",$<str>2," ", $<sql_string>3, " ",$<sql_string>4, " ",$<sql_string>5, "\");",0); */
		yyval.sql_string=make_sql_string(yyvsp[-4].str, " ",yyvsp[-3].str," ", yyvsp[-2].sql_string, " ",yyvsp[-1].sql_string, " ",yyvsp[0].sql_string,0);
	free(yyvsp[-2].sql_string);
	free(yyvsp[-1].sql_string);
	free(yyvsp[0].sql_string);
}
    break;

  case 1682:
#line 7908 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	 }
    break;

  case 1683:
#line 7911 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1684:
#line 7919 "fgl.yacc"
    {
	yyval.sql_string=make_sql_string(yyvsp[-5].str, " ",yyvsp[-4].str," ",yyvsp[-3].sql_string," ", yyvsp[-2].sql_string," ", yyvsp[-1].sql_string, " ",yyvsp[0].sql_string,0);
	free(yyvsp[-3].sql_string);
	free(yyvsp[-1].sql_string);
	free(yyvsp[0].sql_string);
}
    break;

  case 1685:
#line 7928 "fgl.yacc"
    {
		yyval.sql_string=strdup("");
		}
    break;

  case 1686:
#line 7931 "fgl.yacc"
    {
       A4GL_lex_printcomment("/* UNION */");
	yyval.sql_string=make_sql_string(yyvsp[-2].str," ",yyvsp[-1].str," ",yyvsp[0].sql_string,0);
       }
    break;

  case 1687:
#line 7935 "fgl.yacc"
    {
	yyval.sql_string=strdup(yyvsp[0].str);
}
    break;

  case 1688:
#line 7938 "fgl.yacc"
    { yyval.sql_string=make_sql_string(yyvsp[-2].str," ",yyvsp[-1].str," ",yyvsp[0].str,0); }
    break;

  case 1689:
#line 7939 "fgl.yacc"
    { 
	yyval.sql_string=make_sql_string(yyvsp[-3].str," ",yyvsp[-2].str," ",yyvsp[-1].str," ",yyvsp[0].str,0);
}
    break;

  case 1691:
#line 7948 "fgl.yacc"
    { start_bind('o',0);yyval.sql_string=make_sql_string("",0); }
    break;

  case 1692:
#line 7949 "fgl.yacc"
    { 
		yyval.sql_string=make_sql_string(A4GL_get_into_part(doing_declare,get_bind_cnt('o')),0 ); 

	}
    break;

  case 1693:
#line 7958 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-3].str," ",yyvsp[-2].str," ", yyvsp[-1].sql_string," ",yyvsp[0].sql_string,0);
		free(yyvsp[-1].sql_string);
		//free($<sql_string>4);

	}
    break;

  case 1694:
#line 7967 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("(",yyvsp[-4].str," ",yyvsp[-3].str," ",yyvsp[-2].sql_string," ",yyvsp[-1].sql_string,")",0);
	}
    break;

  case 1695:
#line 7972 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1696:
#line 7973 "fgl.yacc"
    {strcpy(yyval.str,"ALL ");}
    break;

  case 1697:
#line 7974 "fgl.yacc"
    {strcpy(yyval.str," DISTINCT ");}
    break;

  case 1698:
#line 7975 "fgl.yacc"
    {strcpy(yyval.str," DISTINCT ");
		ansi_violation("Use DISTINCT not UNIQUE",0);
		strcpy(yyval.str," DISTINCT ");
}
    break;

  case 1699:
#line 7982 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1700:
#line 7985 "fgl.yacc"
    { 
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",",yyvsp[0].sql_string,0);
	}
    break;

  case 1701:
#line 7991 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1702:
#line 7994 "fgl.yacc"
    {
		if (A4GL_isyes(acl_getenv("A4GL_USE_ALIAS_AS"))) {
			yyval.sql_string=make_sql_string(yyvsp[-1].sql_string," AS ",yyvsp[0].str,0);
		} else {
			yyval.sql_string=make_sql_string(yyvsp[-1].sql_string," ",yyvsp[0].str,0);
		}
	}
    break;

  case 1703:
#line 8004 "fgl.yacc"
    {
	yyval.sql_string=yyvsp[0].sql_string;
}
    break;

  case 1704:
#line 8013 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1705:
#line 8016 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("-",yyvsp[0].sql_string,0);
	}
    break;

  case 1706:
#line 8019 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("+",yyvsp[0].sql_string,0);
	}
    break;

  case 1707:
#line 8025 "fgl.yacc"
    {
			if (strlen(current_upd_table)) {
				push_gen(UPDVAL,yyvsp[0].sql_string);
			}
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1708:
#line 8031 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1709:
#line 8034 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1710:
#line 8037 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1711:
#line 8040 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].str,".",yyvsp[0].str);
	}
    break;

  case 1712:
#line 8047 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,"/",yyvsp[0].sql_string,0);}
    break;

  case 1713:
#line 8049 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-1].sql_string," ",yyvsp[0].str,0);}
    break;

  case 1714:
#line 8051 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,"*",yyvsp[0].sql_string,0);}
    break;

  case 1715:
#line 8053 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,"+",yyvsp[0].sql_string,0);}
    break;

  case 1716:
#line 8055 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,"-",yyvsp[0].sql_string,0);}
    break;

  case 1717:
#line 8056 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[0].str,0);}
    break;

  case 1718:
#line 8057 "fgl.yacc"
    {yyval.sql_string=make_sql_string("1",0);}
    break;

  case 1719:
#line 8058 "fgl.yacc"
    {yyval.sql_string=make_sql_string("0",0);}
    break;

  case 1720:
#line 8059 "fgl.yacc"
    {yyval.sql_string=make_sql_string("USER",0);}
    break;

  case 1721:
#line 8060 "fgl.yacc"
    {yyval.sql_string=make_sql_string("*",0);}
    break;

  case 1722:
#line 8061 "fgl.yacc"
    {yyval.sql_string=make_sql_string("COUNT(*)",0);}
    break;

  case 1723:
#line 8063 "fgl.yacc"
    {yyval.sql_string=make_sql_string("AVG(",yyvsp[-2].str,yyvsp[-1].sql_string,")",0);}
    break;

  case 1724:
#line 8065 "fgl.yacc"
    {yyval.sql_string=make_sql_string("MAX(",yyvsp[-2].str,yyvsp[-1].sql_string,")",0);}
    break;

  case 1725:
#line 8067 "fgl.yacc"
    {yyval.sql_string=make_sql_string("MIN(",yyvsp[-2].str,yyvsp[-1].sql_string,")",0);}
    break;

  case 1726:
#line 8069 "fgl.yacc"
    {yyval.sql_string=make_sql_string("SUM(",yyvsp[-2].str,yyvsp[-1].sql_string,")",0);}
    break;

  case 1727:
#line 8071 "fgl.yacc"
    {yyval.sql_string=make_sql_string("COUNT(",yyvsp[-2].str,yyvsp[-1].sql_string,")",0);}
    break;

  case 1728:
#line 8073 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-3].str,"(",yyvsp[-1].sql_string,")",0);}
    break;

  case 1729:
#line 8075 "fgl.yacc"
    {yyval.sql_string=make_sql_string("DATE(",yyvsp[-1].sql_string,")",0);}
    break;

  case 1730:
#line 8076 "fgl.yacc"
    {yyval.sql_string=make_sql_string("(",yyvsp[-1].sql_string,")",0);}
    break;

  case 1731:
#line 8078 "fgl.yacc"
    {yyval.sql_string=make_sql_string("EXTEND(",yyvsp[-1].sql_string,")",0);}
    break;

  case 1732:
#line 8082 "fgl.yacc"
    {yyval.sql_string=yyvsp[0].sql_string;}
    break;

  case 1733:
#line 8083 "fgl.yacc"
    {
	yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",",yyvsp[0].sql_string,0);
}
    break;

  case 1735:
#line 8093 "fgl.yacc"
    {

print_unload(yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].sql_string);
print_undo_use(yyvsp[-4].str);
}
    break;

  case 1736:
#line 8102 "fgl.yacc"
    {
print_load(yyvsp[-4].str,yyvsp[-3].str,yyvsp[-1].str,yyvsp[0].str);
print_undo_use(yyvsp[-6].str);
}
    break;

  case 1737:
#line 8106 "fgl.yacc"
    {
print_load_str(yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);
print_undo_use(yyvsp[-4].str);
}
    break;

  case 1738:
#line 8113 "fgl.yacc"
    {strcpy(yyval.str,"\"|\"");}
    break;

  case 1739:
#line 8113 "fgl.yacc"
    {
strcpy(yyval.str,yyvsp[0].str);
}
    break;

  case 1741:
#line 8117 "fgl.yacc"
    {
if ((scan_variable(yyvsp[0].str)&15)!=0) {a4gl_yyerror("Variable must be of type char for a delimiter..");YYERROR;}
}
    break;

  case 1742:
#line 8122 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 1743:
#line 8122 "fgl.yacc"
    {
sprintf(yyval.str,"%s,0",yyvsp[-1].str);
}
    break;

  case 1745:
#line 8126 "fgl.yacc"
    {
    sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 1746:
#line 8130 "fgl.yacc"
    {
     sprintf(yyval.str,"\"%s\"",yyvsp[0].str);
}
    break;

  case 1749:
#line 8139 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1750:
#line 8139 "fgl.yacc"
    {
print_use_session(yyvsp[0].str);
strcpy(yyval.str,A4GL_get_undo_use());
}
    break;

  case 1755:
#line 8158 "fgl.yacc"
    { sprintf(yyval.str,"%s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str); }
    break;

  case 1756:
#line 8159 "fgl.yacc"
    { sprintf(yyval.str,"%s %s %s %s",yyvsp[-5].str,yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str); }
    break;

  case 1759:
#line 8167 "fgl.yacc"
    {
		sprintf(yyval.str,"%s %s",yyvsp[-1].str,yyvsp[0].str);
	}
    break;

  case 1760:
#line 8173 "fgl.yacc"
    {
		sprintf(yyval.str,"%s %s %s",
					yyvsp[-2].str,
					yyvsp[-1].str,
					yyvsp[0].str
					);
		}
    break;

  case 1763:
#line 8192 "fgl.yacc"
    {strcpy(yyval.str,"UNITS YEAR");}
    break;

  case 1764:
#line 8193 "fgl.yacc"
    {strcpy(yyval.str,"UNITS MONTH"); }
    break;

  case 1765:
#line 8194 "fgl.yacc"
    {strcpy(yyval.str,"UNITS DAY"); }
    break;

  case 1766:
#line 8195 "fgl.yacc"
    {strcpy(yyval.str,"UNITS HOUR"); }
    break;

  case 1767:
#line 8196 "fgl.yacc"
    {strcpy(yyval.str,"UNITS MINUTE"); }
    break;

  case 1768:
#line 8197 "fgl.yacc"
    {strcpy(yyval.str,"UNITS SECOND"); }
    break;

  case 1769:
#line 8201 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str," ",yyvsp[-1].str," ",yyvsp[0].str,0);}
    break;

  case 1770:
#line 8202 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-4].sql_string,yyvsp[-3].str,yyvsp[-2].str," ",yyvsp[-1].str," ",yyvsp[0].str,0);}
    break;

  case 1771:
#line 8203 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-3].str,yyvsp[-2].str," ",yyvsp[-1].str," ",yyvsp[0].str,0);}
    break;

  case 1772:
#line 8207 "fgl.yacc"
    {
		sql_mode=1;
		start_bind('i',0);
		start_bind('o',0);
	}
    break;

  case 1773:
#line 8211 "fgl.yacc"
    {
			sql_mode=0;
			print_sql_block_cmd(yyvsp[-1].str);
	}
    break;

  case 1775:
#line 8220 "fgl.yacc"
    {sprintf(yyval.str,"%s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1777:
#line 8225 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1778:
#line 8226 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 2095:
#line 8551 "fgl.yacc"
    {sql_mode=0;}
    break;

  case 2096:
#line 8551 "fgl.yacc"
    {
		strcpy(yyval.str,yyvsp[0].sql_string);
		sql_mode=1;
	}
    break;

  case 2097:
#line 8558 "fgl.yacc"
    {sql_mode=0;}
    break;

  case 2098:
#line 8558 "fgl.yacc"
    {
 		strcpy(yyval.str,A4GL_get_into_part(doing_declare,get_bind_cnt('o')));
		sql_mode=1;
	}
    break;

  case 2099:
#line 8646 "fgl.yacc"
    {
		strcpy(current_upd_table,yyvsp[0].str);
		pop_all_gen(UPDCOL,"!"); pop_all_gen(UPDVAL,"!"); pop_all_gen(UPDVAL2,"!");
		yyval.sql_string=strdup("");
	}
    break;

  case 2100:
#line 8650 "fgl.yacc"
    {
		strcpy(current_upd_table,"");
	}
    break;

  case 2101:
#line 8652 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-5].str," ",yyvsp[-4].str," ",yyvsp[-2].sql_string," ",yyvsp[0].sql_string,0);
	}
    break;

  case 2102:
#line 8659 "fgl.yacc"
    {
		pop_all_gen(UPDCOL,"!"); pop_all_gen(UPDVAL,"!"); pop_all_gen(UPDVAL2,"!");
		yyval.sql_string=strdup("");
	}
    break;

  case 2103:
#line 8663 "fgl.yacc"
    { 
		pop_all_gen(UPDCOL,"!"); pop_all_gen(UPDVAL,"!"); pop_all_gen(UPDVAL2,"!");
		rm_quotes(yyvsp[0].str);
		sprintf(yyval.str,"%s %s",yyvsp[-1].str,yyvsp[0].str);
		yyval.sql_string=make_sql_string(yyval.str,0);
	}
    break;

  case 2104:
#line 8669 "fgl.yacc"
    {
		pop_all_gen(UPDCOL,"!"); pop_all_gen(UPDVAL,"!"); pop_all_gen(UPDVAL2,"!");
		yyval.sql_string=make_sql_string("WHERE ",yyvsp[0].sql_string,0);
	}
    break;

  case 2105:
#line 8677 "fgl.yacc"
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

  case 2106:
#line 8687 "fgl.yacc"
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

  case 2107:
#line 8697 "fgl.yacc"
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

  case 2108:
#line 8709 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("SET ",yyvsp[0].sql_string,0);
    }
    break;

  case 2109:
#line 8712 "fgl.yacc"
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

  case 2110:
#line 8731 "fgl.yacc"
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

  case 2111:
#line 8757 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 2112:
#line 8760 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",",yyvsp[0].sql_string,0);
	}
    break;

  case 2114:
#line 8769 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].str,"=",yyvsp[0].sql_string,0);
	}
    break;

  case 2115:
#line 8774 "fgl.yacc"
    {
			push_gen(UPDCOL,yyvsp[0].str); strcpy(yyval.str,yyvsp[0].str);
		}
    break;

  case 2116:
#line 8777 "fgl.yacc"
    {
			push_gen(UPDCOL,yyvsp[0].str); sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);
		}
    break;

  case 2117:
#line 8785 "fgl.yacc"
    { 
		yyval.sql_string=yyvsp[0].sql_string; 
		if (gen_cnt(UPDVAL2)) {
			copy_gen(UPDVAL,UPDVAL2);
		} else {
                	push_gen(UPDVAL,yyvsp[0].sql_string);
		}
	}
    break;

  case 2118:
#line 8793 "fgl.yacc"
    { 
		if (gen_cnt(UPDVAL2)) {
			copy_gen(UPDVAL,UPDVAL2);
		} else {
                	push_gen(UPDVAL,yyvsp[0].sql_string);
		}
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",",yyvsp[0].sql_string,0); 
	}
    break;

  case 2119:
#line 8806 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 2120:
#line 8809 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 2121:
#line 8817 "fgl.yacc"
    {
                yyval.sql_string=yyvsp[0].sql_string;
        }
    break;

  case 2122:
#line 8820 "fgl.yacc"
    {
                yyval.sql_string=make_sql_string("-",yyvsp[0].sql_string,0);
        }
    break;

  case 2123:
#line 8823 "fgl.yacc"
    {
                yyval.sql_string=make_sql_string("+",yyvsp[0].sql_string,0);
        }
    break;

  case 2124:
#line 8831 "fgl.yacc"
    {
                yyval.sql_string=yyvsp[0].sql_string;

        }
    break;

  case 2125:
#line 8835 "fgl.yacc"
    {
                yyval.sql_string=yyvsp[0].sql_string;
        }
    break;

  case 2126:
#line 8838 "fgl.yacc"
    {
                yyval.sql_string=strdup(yyvsp[0].str);
        }
    break;

  case 2127:
#line 8841 "fgl.yacc"
    {
                yyval.sql_string=make_sql_string(yyvsp[-2].str,".",yyvsp[0].str);
        }
    break;

  case 2128:
#line 8844 "fgl.yacc"
    { 
		yyval.sql_string=yyvsp[0].sql_string; 
		pop_all_gen(UPDVAL2,"!");
	}
    break;

  case 2129:
#line 8848 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[0].str,0);}
    break;

  case 2130:
#line 8849 "fgl.yacc"
    {yyval.sql_string=make_sql_string("TRUE",0);}
    break;

  case 2131:
#line 8850 "fgl.yacc"
    {yyval.sql_string=make_sql_string("FALSE",0);}
    break;

  case 2132:
#line 8851 "fgl.yacc"
    {yyval.sql_string=make_sql_string("USER",0);}
    break;

  case 2133:
#line 8852 "fgl.yacc"
    {yyval.sql_string=make_sql_string("COUNT(*)",0);}
    break;

  case 2134:
#line 8858 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,"/",yyvsp[0].sql_string,0);}
    break;

  case 2135:
#line 8859 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-1].sql_string,yyvsp[0].str,0);}
    break;

  case 2136:
#line 8860 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,"*",yyvsp[0].sql_string,0);}
    break;

  case 2137:
#line 8861 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,"+",yyvsp[0].sql_string,0);}
    break;

  case 2138:
#line 8862 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,"-",yyvsp[0].sql_string,0);}
    break;

  case 2139:
#line 8863 "fgl.yacc"
    {yyval.sql_string=make_sql_string("AVERAGE(",yyvsp[-2].str,yyvsp[-1].sql_string,")",0);}
    break;

  case 2140:
#line 8864 "fgl.yacc"
    {yyval.sql_string=make_sql_string("MAX(",yyvsp[-2].str,yyvsp[-1].sql_string,")",0);}
    break;

  case 2141:
#line 8865 "fgl.yacc"
    {yyval.sql_string=make_sql_string("MIN(",yyvsp[-2].str,yyvsp[-1].sql_string,")",0);}
    break;

  case 2142:
#line 8866 "fgl.yacc"
    {yyval.sql_string=make_sql_string("SUM(",yyvsp[-2].str,yyvsp[-1].sql_string,")",0);}
    break;

  case 2143:
#line 8867 "fgl.yacc"
    {yyval.sql_string=make_sql_string("COUNT(",yyvsp[-2].str,yyvsp[-1].sql_string,")",0);}
    break;

  case 2144:
#line 8868 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-3].str,"(",yyvsp[-1].sql_string,")",0);}
    break;

  case 2145:
#line 8869 "fgl.yacc"
    {yyval.sql_string=make_sql_string("DATE(",yyvsp[-1].sql_string,")",0);}
    break;

  case 2146:
#line 8870 "fgl.yacc"
    {yyval.sql_string=make_sql_string("(",yyvsp[-1].sql_string,")",0);}
    break;

  case 2147:
#line 8871 "fgl.yacc"
    {yyval.sql_string=make_sql_string("EXTEND(",yyvsp[-1].sql_string,")",0);}
    break;

  case 2148:
#line 8875 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
}
    break;

  case 2149:
#line 8881 "fgl.yacc"
    {yyval.sql_string=yyvsp[0].sql_string;}
    break;

  case 2150:
#line 8882 "fgl.yacc"
    {
        yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",",yyvsp[0].sql_string,0);
}
    break;

  case 2151:
#line 8890 "fgl.yacc"
    {
	clr_validate_list();
}
    break;

  case 2152:
#line 8892 "fgl.yacc"
    {
	print_validate();
}
    break;

  case 2154:
#line 8898 "fgl.yacc"
    {sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 2155:
#line 8902 "fgl.yacc"
    {
		sprintf(yyval.str,"%s.%s",yyvsp[-2].str,yyvsp[0].str);
		push_validate(yyval.str);
	}
    break;

  case 2156:
#line 8906 "fgl.yacc"
    {
		sprintf(yyval.str,"%s.*",yyvsp[-2].str);
		push_validate(yyval.str);
	}
    break;

  case 2157:
#line 8922 "fgl.yacc"
    {
	if (scan_variable(yyvsp[0].str)!=-1)
	{
		char buff[1024];
			sprintf(buff,"%s",fgl_add_scope(yyvsp[0].str,0));

		print_push_variable(buff);

		strcpy(yyval.str,"?");

	} else {
		strcpy(yyval.str,yyvsp[0].str);
	}

}
    break;

  case 2158:
#line 8941 "fgl.yacc"
    {
		strcpy(yyval.str,yyvsp[0].str);
	}
    break;

  case 2159:
#line 8943 "fgl.yacc"
    {
		strcpy(yyval.str,yyvsp[0].str);
	}
    break;

  case 2160:
#line 8949 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 2161:
#line 8950 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 2162:
#line 8951 "fgl.yacc"
    {sprintf(yyval.str,"%s.%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 2163:
#line 8952 "fgl.yacc"
    {
		if (A4GL_escape_quote_owner()) {
			sprintf(yyval.str,"\\\"%s\\\".%s.%s", A4GL_strip_quotes (yyvsp[-4].str),yyvsp[-2].str,yyvsp[0].str);
		} else {
			sprintf(yyval.str,"\"%s\".%s.%s", A4GL_strip_quotes (yyvsp[-4].str),yyvsp[-2].str,yyvsp[0].str);
		}
	}
    break;

  case 2167:
#line 8970 "fgl.yacc"
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

  case 2168:
#line 8996 "fgl.yacc"
    {
char buff[256];
char was_str[40000];
int z = 0,a = 0;
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

  case 2169:
#line 9051 "fgl.yacc"
    {
		set_whenever_from_store();
}
    break;

  case 2170:
#line 9065 "fgl.yacc"
    {
print_while_1();
push_blockcommand("WHILE");
}
    break;

  case 2171:
#line 9068 "fgl.yacc"
    {
print_while_2();
}
    break;

  case 2172:
#line 9072 "fgl.yacc"
    {
print_while_3();
pop_blockcommand("WHILE");
}
    break;

  case 2173:
#line 9087 "fgl.yacc"
    {yyval.field_list=0;}
    break;

  case 2174:
#line 9087 "fgl.yacc"
    {
	yyval.field_list=yyvsp[0].field_list;
}
    break;

  case 2175:
#line 9093 "fgl.yacc"
    { strcpy(yyval.str,"0"); }
    break;

  case 2176:
#line 9094 "fgl.yacc"
    { strcpy(yyval.str,"1"); }
    break;

  case 2177:
#line 9097 "fgl.yacc"
    { print_current_window("\"screen\""); print_clr_window("\"screen\""); }
    break;

  case 2178:
#line 9098 "fgl.yacc"
    { print_clr_window(yyvsp[0].str); }
    break;

  case 2179:
#line 9099 "fgl.yacc"
    { print_clr_window(yyvsp[0].str); }
    break;

  case 2180:
#line 9100 "fgl.yacc"
    { print_clr_form(0,0,"0"); }
    break;

  case 2181:
#line 9101 "fgl.yacc"
    { print_clr_form(0,0,"1"); }
    break;

  case 2182:
#line 9102 "fgl.yacc"
    { print_clr_form(yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str); }
    break;

  case 2183:
#line 9103 "fgl.yacc"
    {
	print_clr_fields(field_name_list_as_char(yyvsp[-1].field_list),yyvsp[0].str);
}
    break;

  case 2184:
#line 9114 "fgl.yacc"
    {
	print_current_window("\"screen\"");
}
    break;

  case 2185:
#line 9118 "fgl.yacc"
    {
	print_current_window(yyvsp[0].str);
}
    break;

  case 2186:
#line 9122 "fgl.yacc"
    {
sprintf(yyval.str,"A4GL_cr_window");
reset_attrib(&form_attrib);
}
    break;

  case 2187:
#line 9126 "fgl.yacc"
    {
sprintf(yyval.str,"A4GL_cr_window_form");
reset_attrib(&form_attrib);
}
    break;

  case 2188:
#line 9131 "fgl.yacc"
    {
	print_show_window(yyvsp[0].str);
	addmap("Show Window",yyvsp[0].str,curr_func,yylineno,infilename); 
}
    break;

  case 2189:
#line 9135 "fgl.yacc"
    {
	print_show_menu(yyvsp[-3].str,yyvsp[-1].str);
	addmap("Call Menuhandler",yyvsp[-1].str,curr_func,yylineno,infilename); 
}
    break;

  case 2190:
#line 9140 "fgl.yacc"
    {

print_def_mn_file();

}
    break;

  case 2192:
#line 9148 "fgl.yacc"
    {addmap("Use Menu",yyvsp[0].str,curr_func,yylineno,infilename); }
    break;

  case 2194:
#line 9154 "fgl.yacc"
    {
	print_hide_window(yyvsp[0].str);
}
    break;

  case 2195:
#line 9160 "fgl.yacc"
    {
print_move_window(yyvsp[-4].str,0);
}
    break;

  case 2196:
#line 9164 "fgl.yacc"
    {
print_move_window(yyvsp[-4].str,1);
}
    break;

  case 2201:
#line 9182 "fgl.yacc"
    {
chk4var=0;A4GL_lex_printcomment("/* [Comm:%s] */\n",yyval.str);
if (A4GL_isyes(acl_getenv("INCLINES")))
A4GL_lex_printc("{A4GL_debug(\"Line %d %s:%s\");}",lastlineno,infilename,convstrsql(larr));
	A4GL_prchkerr(lastlineno,infilename);
	lastlineno=yylineno;
}
    break;

  case 2202:
#line 9189 "fgl.yacc"
    {
A4GL_lex_printcomment("/* [COMM:%s] */\n",yyvsp[0].str);chk4var=0;
if (A4GL_isyes(acl_getenv("INCLINES")))
A4GL_lex_printc("{A4GL_debug(\"Line %d %s:%s\");}",lastlineno,infilename,convstrsql(larr));
/* if (A4GL_aubit_strcasecmp($<str>$,"whenever")!=0)  */
A4GL_prchkerr(lastlineno,infilename);
lastlineno=yylineno;
}
    break;

  case 2203:
#line 9199 "fgl.yacc"
    {print_cmd_start();}
    break;

  case 2204:
#line 9199 "fgl.yacc"
    {print_cmd_end();}
    break;


    }

/* Line 991 of yacc.c.  */
#line 18616 "y.tab.c"

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


#line 9298 "fgl.yacc"

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



