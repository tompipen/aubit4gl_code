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

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     NAME = 1708,
     UMINUS = 1709,
     COMMA = 1614,
     KW_OR = 1654,
     KW_AND = 1609,
     KW_USING = 1546,
     NOT = 1629,
     MATCHES = 1426,
     POWER = 1532,
     LESS_THAN = 1528,
     GREATER_THAN = 1443,
     EQUAL = 1604,
     GREATER_THAN_EQ = 1345,
     LESS_THAN_EQ = 1402,
     NOT_EQUAL = 1474,
     PLUS = 1640,
     MINUS = 1627,
     MULTIPLY = 1533,
     DIVIDE = 1560,
     MOD = 1628,
     COMMAND = 1409,
     NUMBER_VALUE = 1710,
     CHAR_VALUE = 1711,
     INT_VALUE = 1712,
     NAMED_GEN = 1713,
     CLINE = 1714,
     SQLLINE = 1715,
     KW_CSTART = 1716,
     KW_CEND = 1717,
     USER_DTYPE = 1718,
     SQL_TEXT = 1719,
     KW_WHENEVER_SET = 1720,
     COMMENT = 1721,
     DYNAMIC_ARRAY = 1000,
     RESIZE_ARRAY = 1001,
     ALLOCATE_ARRAY = 1002,
     DEALLOCATE_ARRAY = 1003,
     AFTER_INSERT_DELETE = 1004,
     BEFORE_INSERT_DELETE = 1005,
     BEFORE_INSERT = 1006,
     CONCAT_PIPES = 1007,
     BEFORE_DELETE = 1008,
     DROP_TRIGGER = 1009,
     AFTER_INSERT = 1010,
     AFTER_DELETE = 1011,
     EXECUTE_IMMEDIATE = 1012,
     DELETE_ROW_EQUAL_TRUE = 1013,
     INSERT_ROW_EQUAL_TRUE = 1014,
     DELETE_ROW_EQUAL_FALSE = 1015,
     INSERT_ROW_EQUAL_FALSE = 1016,
     CURRENT_ROW_DISPLAY_EQUAL = 1017,
     MAXCOUNT = 1018,
     ALTER_TABLE = 1019,
     ALTER_INDEX = 1020,
     NEXT_SIZE = 1021,
     DISPLAY_ATTR_FORM = 1022,
     DISPLAY_ATTR_WINDOW = 1023,
     INPUT_ATTR_FORM = 1024,
     INPUT_ATTR_WINDOW = 1025,
     WHENEVER_ERROR_CONTINUE = 1026,
     WHENEVER_ANY_ERROR_CONTINUE = 1027,
     WHENEVER_WARNING_CONTINUE = 1028,
     WHENEVER_SQLSUCCESS_CONTINUE = 1029,
     WHENEVER_SQLWARNING_CONTINUE = 1030,
     WHENEVER_NOT_FOUND_CONTINUE = 1031,
     WHENEVER_SQLERROR_CONTINUE = 1032,
     WHENEVER_SUCCESS_CONTINUE = 1033,
     WHENEVER_ERROR_GOTO = 1034,
     WHENEVER_ANY_ERROR_GOTO = 1035,
     WHENEVER_WARNING_GOTO = 1036,
     WHENEVER_SQLSUCCESS_GOTO = 1037,
     WHENEVER_SQLWARNING_GOTO = 1038,
     WHENEVER_NOT_FOUND_GOTO = 1039,
     WHENEVER_SQLERROR_GOTO = 1040,
     WHENEVER_SUCCESS_GOTO = 1041,
     WHENEVER_ERROR_CALL = 1042,
     WHENEVER_ANY_ERROR_CALL = 1043,
     WHENEVER_WARNING_CALL = 1044,
     WHENEVER_SQLSUCCESS_CALL = 1045,
     WHENEVER_SQLWARNING_CALL = 1046,
     WHENEVER_NOT_FOUND_CALL = 1047,
     WHENEVER_SQLERROR_CALL = 1048,
     WHENEVER_SUCCESS_CALL = 1049,
     WHENEVER_ERROR_STOP = 1050,
     WHENEVER_ANY_ERROR_STOP = 1051,
     WHENEVER_WARNING_STOP = 1052,
     WHENEVER_SQLSUCCESS_STOP = 1053,
     WHENEVER_SQLWARNING_STOP = 1054,
     WHENEVER_NOT_FOUND_STOP = 1055,
     WHENEVER_SQLERROR_STOP = 1056,
     WHENEVER_SUCCESS_STOP = 1057,
     XSET_MULTIPLY_EQUAL_OPEN_BRACKET = 1058,
     XSET_ident_DOT_MULTIPLY_EQUAL_OPEN_BRACKET = 1059,
     XSET_ident_DOT_MULTIPLY_EQUAL = 1060,
     XSET_MULTIPLY_EQUAL = 1061,
     XSET_OPEN_BRACKET = 1062,
     NEWFORMATSHARED = 1063,
     CREATE_DATABASE = 1064,
     DROP_DATABASE = 1065,
     IMPORT_LEGACY_FUNCTION = 1066,
     ADD_CONSTRAINT = 1067,
     DROP_CONSTRAINT = 1068,
     DROP_SYNONYM = 1069,
     CONSTRAINT = 1070,
     AS_STATIC = 1071,
     NOT_FIELD_TOUCHED = 1072,
     LOCAL_FUNCTION = 1073,
     EVERY_ROW = 1074,
     ELIF = 1075,
     DOUBLE_PRECISION = 1076,
     COUNT_MULTIPLY = 1077,
     WAIT_FOR_KEY = 1078,
     AT_TERMINATION_CALL = 1079,
     TERMINATE_REPORT = 1080,
     TO_MAIN_CAPTION = 1081,
     CLEARSTAT = 1082,
     TO_MENUITEM = 1083,
     ID_TO_INT = 1084,
     TO_STATUSBOX = 1085,
     ASCII_HEIGHT_ALL = 1086,
     ASCII_WIDTH_ALL = 1087,
     IMPORT_DATATYPE = 1088,
     PAGE_TRAILER_SIZE = 1089,
     PAGE_HEADER_SIZE = 1090,
     FIRST_PAGE_HEADER_SIZE = 1091,
     BYTES_USE_AS_IMAGE = 1092,
     BYTES_USE_AS_ASCII = 1093,
     KWUP_BY = 1094,
     KWDOWN_BY = 1095,
     CLOSE_STATUSBOX = 1096,
     MODIFY_NEXT_SIZE = 1097,
     LOCK_MODE_PAGE = 1098,
     LOCK_MODE_ROW = 1099,
     TO_PIPE = 1100,
     TO_PRINTER = 1101,
     STATUSBOX = 1102,
     FORMHANDLER_INPUT = 1103,
     UNITS_YEAR = 1104,
     UNITS_MONTH = 1105,
     UNITS_DAY = 1106,
     UNITS_HOUR = 1107,
     UNITS_MINUTE = 1108,
     UNITS_SECOND = 1109,
     NO_NEW_LINES = 1110,
     FIELDTOWIDGET = 1111,
     WITH_HOLD = 1112,
     SHOW_MENU = 1113,
     TO_CLUSTER = 1114,
     TO_NOT_CLUSTER = 1115,
     CWIS = 1116,
     CREATE_IDX = 1117,
     FORM_IS_COMPILED = 1118,
     PDF_REPORT = 1119,
     IMPORT_FUNCTION = 1120,
     PROMPT_MANY = 1121,
     POINTS = 1122,
     MM = 1123,
     INCHES = 1124,
     PREPEND = 1125,
     MEMBER_OF = 1126,
     MEMBER_FUNCTION = 1127,
     APPEND = 1128,
     TEMPLATE = 1129,
     END_TEMPLATE = 1130,
     SQLSICS = 1131,
     CREATE_SCHEMA = 1132,
     SQLSIRR = 1133,
     UPDATESTATS_T = 1134,
     SQLSICR = 1135,
     WHENEVER_SQLSUCCESS = 1136,
     WHENEVER_SQLWARNING = 1137,
     WHENEVER_ANY_ERROR = 1138,
     WHENEVER_NOT_FOUND = 1139,
     WHENEVER_SQLERROR = 1140,
     WHENEVER_SUCCESS = 1141,
     WHENEVER_ERROR = 1142,
     START_EXTERN = 1143,
     CONTINUE_CONSTRUCT = 1144,
     FOUNCONSTR = 1145,
     SQLSIDR = 1146,
     CREATE_TEMP_TABLE = 1147,
     CURRENT_WINDOW_IS = 1148,
     FIRST_PAGE_HEADER = 1149,
     ORDER_EXTERNAL_BY = 1150,
     SCROLL_CURSOR_FOR = 1151,
     SCROLL_CURSOR = 1152,
     SQL_INTERRUPT_OFF = 1153,
     STOP_ALL_EXTERNAL = 1154,
     WITH_CHECK_OPTION = 1155,
     WITH_GRANT_OPTION = 1156,
     SQLSLMNW = 1157,
     ADDCONSTUNIQ = 1158,
     CONTINUE_DISPLAY = 1159,
     CONTINUE_FOREACH = 1160,
     OUTPUT_TO_REPORT = 1161,
     SQL_INTERRUPT_ON = 1162,
     WHERE_CURRENT_OF = 1163,
     WITHOUT_DEFAULTS = 1164,
     FOCONSTR = 1165,
     SCALED_BY = 1166,
     CONTINUE_PROMPT = 1167,
     PDF_FUNCTION = 1168,
     DEFER_INTERRUPT = 1169,
     DISPLAY_BY_NAME = 1170,
     NOT_NULL_UNIQUE = 1171,
     SKIP_TO_TOP = 1172,
     TOP_OF_PAGE = 1173,
     SKIP_TO = 1174,
     SKIP_BY = 1175,
     WITHOUT_WAITING = 1176,
     BEFCONSTRUCT = 1177,
     SQLSLMW = 1178,
     AFTCONSTRUCT = 1179,
     ALL_PRIVILEGES = 1180,
     CLOSE_DATABASE = 1181,
     CONTINUE_INPUT = 1182,
     CONTINUE_WHILE = 1183,
     CREATE_SYNONYM = 1184,
     DROP_TABLE = 1185,
     EXIT_CONSTRUCT = 1186,
     INEXCLUSIVE = 1187,
     REPORT_TO_PRINTER = 1188,
     REPORT_TO_PIPE = 1189,
     RETURN = 1190,
     SET_SESSION_TO = 1191,
     UPDATESTATS = 1192,
     WITHOUT_HEAD = 1193,
     CLEARSCR = 1194,
     WITH_B_LOG = 1195,
     AUTHORIZATION = 1196,
     BOTTOM_MARGIN = 1197,
     CLOSE_SESSION = 1198,
     CONTINUE_CASE = 1199,
     CONTINUE_MENU = 1200,
     DISPLAY_ARRAY = 1201,
     END_SQL = 1202,
     DOLLAR = 1203,
     END_CONSTRUCT = 1204,
     FIELD_TOUCHED = 1205,
     FINISH_REPORT = 1206,
     INFACC = 1207,
     INPUT_NO_WRAP = 1208,
     SETPMOFF = 1209,
     UNCONSTRAINED = 1210,
     PAGE_TRAILER = 1211,
     SETPMON = 1212,
     BEFGROUP = 1213,
     CLOSE_WINDOW = 1214,
     COMMENT_LINE = 1215,
     CONTINUE_FOR = 1216,
     CREATE_DB = 1217,
     CREATE_TABLE = 1218,
     DEFAULT_NULL = 1219,
     DEFAULT_TODAY = 1220,
     DEFAULT_USER = 1221,
     DELETE_USING = 1222,
     DISPLAY_FORM = 1223,
     END_FUNCTION = 1224,
     EXIT_DISPLAY = 1225,
     EXIT_FOREACH = 1226,
     EXIT_PROGRAM = 1227,
     INFCOLS = 1228,
     ON_EVERY_ROW = 1229,
     OPEN_SESSION = 1230,
     RIGHT_MARGIN = 1231,
     SELECT_USING = 1232,
     START_REPORT = 1233,
     UNLOCK_TABLE = 1234,
     UPDATE_USING = 1235,
     ACL_BUILTIN = 1236,
     AFTGROUP = 1237,
     INFIDX = 1238,
     INFSTAT = 1239,
     LEFT_MARGIN = 1240,
     PAGE_HEADER = 1241,
     ROLLBACK_W = 1242,
     SET_SESSION = 1243,
     SQLSEOFF = 1244,
     WITH_A_LOG = 1245,
     BEFDISP = 1246,
     BEFORE_MENU = 1247,
     CREATE_VIEW = 1248,
     DEFINE_TYPE = 1249,
     DELETE_FROM = 1250,
     END_DISPLAY = 1251,
     END_REPORT = 1252,
     END_FOREACH = 1253,
     END_FOR = 1254,
     END_GLOBALS = 1255,
     EXIT_PROMPT = 1256,
     EXTENT_SIZE = 1257,
     FOREIGN_KEY = 1258,
     HIDE_OPTION = 1259,
     HIDE_WINDOW = 1260,
     INSERT_INTO = 1261,
     IS_NOT_NULL = 1262,
     MOVE_WINDOW = 1263,
     NEXT_OPTION = 1264,
     NOT_MATCHES = 1265,
     ON_LAST_ROW = 1266,
     OPEN_WINDOW = 1267,
     OPEN_STATUSBOX = 1268,
     PAGE_LENGTH = 1269,
     PAGE_WIDTH = 1270,
     PRIMARY_KEY = 1271,
     PROMPT_LINE = 1272,
     RECORD_LIKE = 1273,
     ROLLFORWARD = 1274,
     SETBL = 1275,
     SHOW_OPTION = 1276,
     SHOW_WINDOW = 1277,
     SQLSEON = 1278,
     TO_DATABASE = 1279,
     USE_SESSION = 1280,
     WITH_NO_LOG = 1281,
     AFTDISP = 1282,
     BEFFIELD = 1283,
     INSHARE = 1284,
     UNLOCKTAB = 1285,
     AFTFIELD = 1286,
     ATTRIBUTES = 1287,
     BEFINP = 1288,
     BEGIN_WORK = 1289,
     CLEARWIN = 1290,
     CLOSE_FORM = 1291,
     DEFER_QUIT = 1292,
     DESCENDING = 1293,
     DROP_INDEX = 1294,
     END_PROMPT = 1295,
     END_RECORD = 1296,
     ERROR_LINE = 1297,
     EXIT_INPUT = 1298,
     EXIT_WHILE = 1299,
     FOR_UPDATE_OF = 1300,
     FOR_UPDATE = 1301,
     GET_FLDBUF = 1302,
     INITIALIZE = 1303,
     INPUT_WRAP = 1304,
     LOCK_TABLE = 1305,
     MSG_LINE = 1306,
     NOT_EXISTS = 1307,
     ON_ANY_KEY = 1308,
     REFERENCES = 1309,
     RENCOL = 1310,
     SET_CURSOR = 1311,
     SMALLFLOAT = 1312,
     SQLSUCCESS = 1313,
     TOP_MARGIN = 1314,
     WITH_ARRAY = 1315,
     ACCEPTKEY = 1316,
     ACCEPT = 1317,
     AFTINP = 1318,
     CLEARFORMTODEFAULTS = 1319,
     CLEARFORM = 1320,
     CLEAR_X_FORM = 1321,
     COMMIT_W = 1322,
     NEXTPAGE = 1323,
     PREVPAGE = 1324,
     CTRL_KEY = 1325,
     INFTABS = 1326,
     NEXTFIELD = 1327,
     NEXTFORM = 1328,
     RENTAB = 1329,
     ASCENDING = 1330,
     ASSOCIATE = 1331,
     CHAR = 1332,
     NCHAR = 1333,
     NVARCHAR = 1334,
     CONSTRUCT = 1335,
     DELIMITER = 1336,
     DOWNSHIFT = 1337,
     DROP_VIEW = 1338,
     END_INPUT = 1339,
     END_WHILE = 1340,
     EXCLUSIVE = 1341,
     EXIT_CASE = 1342,
     EXIT_MENU = 1343,
     FORM_LINE = 1344,
     INTERRUPT = 1346,
     INTO_TEMP = 1347,
     INVISIBLE = 1348,
     IN_MEMORY = 1349,
     LINKED_TO = 1350,
     LOAD_FROM = 1351,
     LOCKTAB = 1352,
     MENU_LINE = 1353,
     OPEN_FORM = 1354,
     OTHERWISE = 1355,
     PRECISION = 1356,
     PRIOR = 1357,
     PROCEDURE = 1358,
     REPORT_TO = 1359,
     RETURNING = 1360,
     UNDERLINE = 1361,
     UNLOAD_TO = 1362,
     BEFROW = 1363,
     UNLOAD_T = 1364,
     VARIABLE = 1365,
     ABSOLUTE = 1366,
     AFTROW = 1367,
     BUFFERED = 1368,
     CONSTANT = 1369,
     CONST = 1370,
     DATABASE = 1371,
     DATETIME = 1372,
     DEFAULTS = 1373,
     DISTINCT = 1374,
     END_CASE = 1375,
     END_MAIN = 1376,
     END_MENU = 1377,
     END_TYPE = 1378,
     EXIT_FOR = 1379,
     EXTERNAL = 1380,
     FRACTION = 1381,
     FUNCTION = 1382,
     GROUP_BY = 1383,
     INTERVAL = 1384,
     KWMESSAGE = 1385,
     NOT_LIKE = 1386,
     NOT_ILIKE = 1387,
     NOT_NULL = 1388,
     PASSWORD = 1389,
     PREVIOUS = 1390,
     READONLY = 1391,
     REGISTER = 1392,
     RELATIVE = 1393,
     RESOURCE = 1394,
     SMALLINT = 1395,
     VALIDATE = 1396,
     WITH_LOG = 1397,
     WORDWRAP = 1398,
     BY_NAME = 1399,
     IN_FILE = 1400,
     IS_NULL = 1401,
     AVERAGE = 1403,
     BETWEEN = 1404,
     CAPTION = 1405,
     CLIPPED = 1406,
     CLOSE_BRACKET = 1407,
     COLUMNS = 1408,
     CONNECT = 1410,
     CURRENT = 1411,
     DBYNAME = 1412,
     DECIMAL = 1413,
     DECLARE = 1414,
     DEFAULT = 1415,
     DISPLAY = 1416,
     ENDCODE = 1417,
     EXECUTE = 1418,
     FOREACH = 1419,
     FOREIGN = 1420,
     GLOBALS = 1421,
     INFIELD = 1422,
     INTEGER = 1423,
     KWWINDOW = 1424,
     MAGENTA = 1425,
     OPTIONS = 1427,
     PERCENT = 1428,
     PREPARE = 1429,
     PROGRAM = 1430,
     RECOVER = 1431,
     REVERSE = 1432,
     SECTION = 1433,
     SESSION = 1434,
     SYNONYM = 1435,
     THRU = 1436,
     TRAILER = 1437,
     UPSHIFT = 1438,
     VARCHAR = 1439,
     WAITING = 1440,
     CLOSE_SHEV = 1441,
     CLOSE_SQUARE = 1442,
     KW_FALSE = 1444,
     NOT_IN = 1445,
     ONKEY = 1446,
     OPEN_BRACKET = 1447,
     BORDER = 1448,
     BOTTOM = 1449,
     COLUMN = 1450,
     COMMIT = 1451,
     CREATE = 1452,
     CURSOR = 1453,
     DEFINE = 1454,
     DELETE = 1455,
     DOUBLE = 1456,
     END_IF = 1457,
     ESCAPE = 1458,
     EXISTS = 1459,
     EXTEND = 1460,
     EXTENT = 1461,
     FINISH = 1462,
     FORMAT = 1463,
     HAVING = 1464,
     HEADER = 1465,
     INSERT = 1466,
     LOCATE = 1467,
     MARGIN = 1468,
     MEMORY = 1469,
     MINUTE = 1470,
     MODIFY = 1471,
     NORMAL = 1472,
     EQUAL_EQUAL = 1473,
     OPEN_SHEV = 1475,
     OPEN_SQUARE = 1476,
     OPTION = 1477,
     OUTPUT = 1478,
     PROMPT = 1479,
     PUBLIC = 1480,
     RECORD = 1481,
     REPORT = 1482,
     REVOKE = 1483,
     SCHEMA = 1484,
     SCROLL_USING = 1485,
     SCROLL = 1486,
     SECOND = 1487,
     SELECT = 1488,
     SERIAL = 1489,
     SETL = 1490,
     SHARED = 1491,
     SPACES = 1492,
     UNIQUE = 1493,
     UNLOCK = 1494,
     UPDATE = 1495,
     VALUES = 1496,
     YELLOW = 1497,
     AFTER = 1498,
     KWLINE = 1499,
     KW_NULL = 1500,
     KW_TRUE = 1501,
     SINGLE_KEY = 1502,
     ALTER = 1503,
     ARRAY = 1504,
     ASCII = 1505,
     AUDIT = 1506,
     BLACK = 1507,
     BLINK = 1508,
     CHECK = 1509,
     CLEAR = 1510,
     CLOSE = 1511,
     CODE_C = 1512,
     COUNT = 1513,
     DEFER = 1514,
     ERROR = 1515,
     EVERY = 1516,
     FETCH = 1517,
     FIRST = 1518,
     FLOAT = 1519,
     FLUSH = 1520,
     FOUND = 1521,
     GRANT = 1522,
     GREEN = 1523,
     GROUP = 1524,
     INDEX = 1525,
     KWFORM = 1526,
     LABEL = 1527,
     LOCAL = 1529,
     MONEY = 1530,
     MONTH = 1531,
     ORDER = 1534,
     OUTER = 1535,
     PAUSE = 1536,
     PRINT_IMAGE = 1537,
     PRINT_FILE = 1538,
     PRINT = 1539,
     RIGHT = 1540,
     DOUBLE_COLON = 1541,
     SEMICOLON = 1542,
     SLEEP = 1543,
     TUPLE = 1544,
     UNION = 1545,
     WHERE = 1547,
     WHILE = 1548,
     WHITE = 1549,
     CCODE = 1550,
     ANSI = 1551,
     BLUE = 1552,
     BOLD = 1553,
     BYTE = 1554,
     FCALL = 1555,
     CASE = 1556,
     CYAN = 1557,
     DATE = 1558,
     DESC = 1559,
     KWDOWN = 1561,
     TAB = 1562,
     DROP = 1563,
     ELSE = 1564,
     EXEC = 1565,
     EXIT = 1566,
     FREE = 1567,
     FROM = 1568,
     GOTO = 1569,
     HELP_FILE = 1570,
     LANG_FILE = 1571,
     HELP = 1572,
     HIDE = 1573,
     HOUR = 1574,
     INTO = 1575,
     LAST = 1576,
     LEFT = 1577,
     LIKE = 1578,
     MAIN = 1579,
     MENU = 1580,
     MODE = 1581,
     NEED = 1582,
     NEXT = 1583,
     NOCR = 1584,
     OPEN = 1585,
     QUIT = 1586,
     REAL = 1587,
     ROWS = 1588,
     SHOW = 1589,
     SIZE = 1590,
     SKIP = 1591,
     SOME = 1592,
     STEP = 1593,
     STOP = 1594,
     TEMP = 1595,
     TEXT = 1596,
     THEN = 1597,
     USER = 1598,
     WAIT = 1599,
     WHEN = 1600,
     WITH = 1601,
     WORK = 1602,
     YEAR = 1603,
     KW_IS = 1605,
     XSET = 1606,
     ADD = 1607,
     ALL = 1608,
     ANY = 1610,
     ASC = 1611,
     AVG = 1612,
     COLON = 1613,
     DAY = 1615,
     DBA = 1616,
     DEC = 1617,
     DIM = 1618,
     FKEY = 1619,
     FOR = 1620,
     KEY = 1621,
     KWNO = 1622,
     LET = 1623,
     LOG = 1624,
     XMAX = 1625,
     XMIN = 1626,
     PAD = 1630,
     PUT = 1631,
     RED = 1632,
     ROW = 1633,
     RUN = 1634,
     SQL = 1635,
     SUM = 1636,
     TOP = 1637,
     USE = 1638,
     ATSIGN = 1639,
     AS_TIFF = 1641,
     AS_GIF = 1642,
     AS_PNG = 1643,
     AS_JPEG = 1644,
     AS = 1645,
     AT = 1646,
     BY = 1647,
     DOT = 1648,
     GO = 1649,
     IF = 1650,
     IN = 1651,
     OF = 1652,
     ON = 1653,
     TO = 1655,
     KWUP = 1656,
     FONT_NAME = 1657,
     FONT_SIZE = 1658,
     PAPER_SIZE_IS_LETTER = 1659,
     PAPER_SIZE_IS_LEGAL = 1660,
     PAPER_SIZE_IS_A5 = 1661,
     PAPER_SIZE_IS_A4 = 1662,
     PAPER_SIZE_IS_LETTER_L = 1663,
     PAPER_SIZE_IS_LEGAL_L = 1664,
     PAPER_SIZE_IS_A5_L = 1665,
     PAPER_SIZE_IS_A4_L = 1666,
     FORMHANDLER = 1667,
     END_FORMHANDLER = 1668,
     BEFORE_EVENT = 1669,
     BEFORE_OPEN_FORM = 1670,
     AFTER_EVENT = 1671,
     BEFORE_CLOSE_FORM = 1672,
     BEFORE_ANY = 1673,
     AFTER_ANY = 1674,
     MENUHANDLER = 1675,
     END_MENUHANDLER = 1676,
     BEFORE_SHOW_MENU = 1677,
     DISABLE_PROGRAM = 1678,
     DISABLE_ALL = 1679,
     BUTTONS = 1680,
     CHECK_MENUITEM = 1681,
     DISABLE_FORM = 1682,
     DISABLE_MENUITEMS = 1683,
     DISABLE = 1684,
     ENABLE_FORM = 1685,
     ENABLE_MENUITEMS = 1686,
     ENABLE = 1687,
     KWFIELD = 1688,
     ICON = 1689,
     MESSAGEBOX = 1690,
     TO_DEFAULTS = 1691,
     UNCHECK_MENUITEM = 1692,
     BEFORE = 1693,
     INPUT = 1694,
     END = 1695,
     INT_TO_ID = 1696,
     TIMEOUT = 1697,
     OFF = 1698,
     WITH_1_DIMENSION = 1699,
     WITH_2_DIMENSION = 1700,
     WITH_3_DIMENSION = 1701,
     TILDE = 1702,
     ILIKE = 1703,
     FGL_ISDYNARR_ALLOCATED = 1704,
     FGL_DYNARR_EXTENTSIZE = 1705,
     FILLFACTOR = 1706
   };
#endif
#define NAME 1708
#define UMINUS 1709
#define COMMA 1614
#define KW_OR 1654
#define KW_AND 1609
#define KW_USING 1546
#define NOT 1629
#define MATCHES 1426
#define POWER 1532
#define LESS_THAN 1528
#define GREATER_THAN 1443
#define EQUAL 1604
#define GREATER_THAN_EQ 1345
#define LESS_THAN_EQ 1402
#define NOT_EQUAL 1474
#define PLUS 1640
#define MINUS 1627
#define MULTIPLY 1533
#define DIVIDE 1560
#define MOD 1628
#define COMMAND 1409
#define NUMBER_VALUE 1710
#define CHAR_VALUE 1711
#define INT_VALUE 1712
#define NAMED_GEN 1713
#define CLINE 1714
#define SQLLINE 1715
#define KW_CSTART 1716
#define KW_CEND 1717
#define USER_DTYPE 1718
#define SQL_TEXT 1719
#define KW_WHENEVER_SET 1720
#define COMMENT 1721
#define DYNAMIC_ARRAY 1000
#define RESIZE_ARRAY 1001
#define ALLOCATE_ARRAY 1002
#define DEALLOCATE_ARRAY 1003
#define AFTER_INSERT_DELETE 1004
#define BEFORE_INSERT_DELETE 1005
#define BEFORE_INSERT 1006
#define CONCAT_PIPES 1007
#define BEFORE_DELETE 1008
#define DROP_TRIGGER 1009
#define AFTER_INSERT 1010
#define AFTER_DELETE 1011
#define EXECUTE_IMMEDIATE 1012
#define DELETE_ROW_EQUAL_TRUE 1013
#define INSERT_ROW_EQUAL_TRUE 1014
#define DELETE_ROW_EQUAL_FALSE 1015
#define INSERT_ROW_EQUAL_FALSE 1016
#define CURRENT_ROW_DISPLAY_EQUAL 1017
#define MAXCOUNT 1018
#define ALTER_TABLE 1019
#define ALTER_INDEX 1020
#define NEXT_SIZE 1021
#define DISPLAY_ATTR_FORM 1022
#define DISPLAY_ATTR_WINDOW 1023
#define INPUT_ATTR_FORM 1024
#define INPUT_ATTR_WINDOW 1025
#define WHENEVER_ERROR_CONTINUE 1026
#define WHENEVER_ANY_ERROR_CONTINUE 1027
#define WHENEVER_WARNING_CONTINUE 1028
#define WHENEVER_SQLSUCCESS_CONTINUE 1029
#define WHENEVER_SQLWARNING_CONTINUE 1030
#define WHENEVER_NOT_FOUND_CONTINUE 1031
#define WHENEVER_SQLERROR_CONTINUE 1032
#define WHENEVER_SUCCESS_CONTINUE 1033
#define WHENEVER_ERROR_GOTO 1034
#define WHENEVER_ANY_ERROR_GOTO 1035
#define WHENEVER_WARNING_GOTO 1036
#define WHENEVER_SQLSUCCESS_GOTO 1037
#define WHENEVER_SQLWARNING_GOTO 1038
#define WHENEVER_NOT_FOUND_GOTO 1039
#define WHENEVER_SQLERROR_GOTO 1040
#define WHENEVER_SUCCESS_GOTO 1041
#define WHENEVER_ERROR_CALL 1042
#define WHENEVER_ANY_ERROR_CALL 1043
#define WHENEVER_WARNING_CALL 1044
#define WHENEVER_SQLSUCCESS_CALL 1045
#define WHENEVER_SQLWARNING_CALL 1046
#define WHENEVER_NOT_FOUND_CALL 1047
#define WHENEVER_SQLERROR_CALL 1048
#define WHENEVER_SUCCESS_CALL 1049
#define WHENEVER_ERROR_STOP 1050
#define WHENEVER_ANY_ERROR_STOP 1051
#define WHENEVER_WARNING_STOP 1052
#define WHENEVER_SQLSUCCESS_STOP 1053
#define WHENEVER_SQLWARNING_STOP 1054
#define WHENEVER_NOT_FOUND_STOP 1055
#define WHENEVER_SQLERROR_STOP 1056
#define WHENEVER_SUCCESS_STOP 1057
#define XSET_MULTIPLY_EQUAL_OPEN_BRACKET 1058
#define XSET_ident_DOT_MULTIPLY_EQUAL_OPEN_BRACKET 1059
#define XSET_ident_DOT_MULTIPLY_EQUAL 1060
#define XSET_MULTIPLY_EQUAL 1061
#define XSET_OPEN_BRACKET 1062
#define NEWFORMATSHARED 1063
#define CREATE_DATABASE 1064
#define DROP_DATABASE 1065
#define IMPORT_LEGACY_FUNCTION 1066
#define ADD_CONSTRAINT 1067
#define DROP_CONSTRAINT 1068
#define DROP_SYNONYM 1069
#define CONSTRAINT 1070
#define AS_STATIC 1071
#define NOT_FIELD_TOUCHED 1072
#define LOCAL_FUNCTION 1073
#define EVERY_ROW 1074
#define ELIF 1075
#define DOUBLE_PRECISION 1076
#define COUNT_MULTIPLY 1077
#define WAIT_FOR_KEY 1078
#define AT_TERMINATION_CALL 1079
#define TERMINATE_REPORT 1080
#define TO_MAIN_CAPTION 1081
#define CLEARSTAT 1082
#define TO_MENUITEM 1083
#define ID_TO_INT 1084
#define TO_STATUSBOX 1085
#define ASCII_HEIGHT_ALL 1086
#define ASCII_WIDTH_ALL 1087
#define IMPORT_DATATYPE 1088
#define PAGE_TRAILER_SIZE 1089
#define PAGE_HEADER_SIZE 1090
#define FIRST_PAGE_HEADER_SIZE 1091
#define BYTES_USE_AS_IMAGE 1092
#define BYTES_USE_AS_ASCII 1093
#define KWUP_BY 1094
#define KWDOWN_BY 1095
#define CLOSE_STATUSBOX 1096
#define MODIFY_NEXT_SIZE 1097
#define LOCK_MODE_PAGE 1098
#define LOCK_MODE_ROW 1099
#define TO_PIPE 1100
#define TO_PRINTER 1101
#define STATUSBOX 1102
#define FORMHANDLER_INPUT 1103
#define UNITS_YEAR 1104
#define UNITS_MONTH 1105
#define UNITS_DAY 1106
#define UNITS_HOUR 1107
#define UNITS_MINUTE 1108
#define UNITS_SECOND 1109
#define NO_NEW_LINES 1110
#define FIELDTOWIDGET 1111
#define WITH_HOLD 1112
#define SHOW_MENU 1113
#define TO_CLUSTER 1114
#define TO_NOT_CLUSTER 1115
#define CWIS 1116
#define CREATE_IDX 1117
#define FORM_IS_COMPILED 1118
#define PDF_REPORT 1119
#define IMPORT_FUNCTION 1120
#define PROMPT_MANY 1121
#define POINTS 1122
#define MM 1123
#define INCHES 1124
#define PREPEND 1125
#define MEMBER_OF 1126
#define MEMBER_FUNCTION 1127
#define APPEND 1128
#define TEMPLATE 1129
#define END_TEMPLATE 1130
#define SQLSICS 1131
#define CREATE_SCHEMA 1132
#define SQLSIRR 1133
#define UPDATESTATS_T 1134
#define SQLSICR 1135
#define WHENEVER_SQLSUCCESS 1136
#define WHENEVER_SQLWARNING 1137
#define WHENEVER_ANY_ERROR 1138
#define WHENEVER_NOT_FOUND 1139
#define WHENEVER_SQLERROR 1140
#define WHENEVER_SUCCESS 1141
#define WHENEVER_ERROR 1142
#define START_EXTERN 1143
#define CONTINUE_CONSTRUCT 1144
#define FOUNCONSTR 1145
#define SQLSIDR 1146
#define CREATE_TEMP_TABLE 1147
#define CURRENT_WINDOW_IS 1148
#define FIRST_PAGE_HEADER 1149
#define ORDER_EXTERNAL_BY 1150
#define SCROLL_CURSOR_FOR 1151
#define SCROLL_CURSOR 1152
#define SQL_INTERRUPT_OFF 1153
#define STOP_ALL_EXTERNAL 1154
#define WITH_CHECK_OPTION 1155
#define WITH_GRANT_OPTION 1156
#define SQLSLMNW 1157
#define ADDCONSTUNIQ 1158
#define CONTINUE_DISPLAY 1159
#define CONTINUE_FOREACH 1160
#define OUTPUT_TO_REPORT 1161
#define SQL_INTERRUPT_ON 1162
#define WHERE_CURRENT_OF 1163
#define WITHOUT_DEFAULTS 1164
#define FOCONSTR 1165
#define SCALED_BY 1166
#define CONTINUE_PROMPT 1167
#define PDF_FUNCTION 1168
#define DEFER_INTERRUPT 1169
#define DISPLAY_BY_NAME 1170
#define NOT_NULL_UNIQUE 1171
#define SKIP_TO_TOP 1172
#define TOP_OF_PAGE 1173
#define SKIP_TO 1174
#define SKIP_BY 1175
#define WITHOUT_WAITING 1176
#define BEFCONSTRUCT 1177
#define SQLSLMW 1178
#define AFTCONSTRUCT 1179
#define ALL_PRIVILEGES 1180
#define CLOSE_DATABASE 1181
#define CONTINUE_INPUT 1182
#define CONTINUE_WHILE 1183
#define CREATE_SYNONYM 1184
#define DROP_TABLE 1185
#define EXIT_CONSTRUCT 1186
#define INEXCLUSIVE 1187
#define REPORT_TO_PRINTER 1188
#define REPORT_TO_PIPE 1189
#define RETURN 1190
#define SET_SESSION_TO 1191
#define UPDATESTATS 1192
#define WITHOUT_HEAD 1193
#define CLEARSCR 1194
#define WITH_B_LOG 1195
#define AUTHORIZATION 1196
#define BOTTOM_MARGIN 1197
#define CLOSE_SESSION 1198
#define CONTINUE_CASE 1199
#define CONTINUE_MENU 1200
#define DISPLAY_ARRAY 1201
#define END_SQL 1202
#define DOLLAR 1203
#define END_CONSTRUCT 1204
#define FIELD_TOUCHED 1205
#define FINISH_REPORT 1206
#define INFACC 1207
#define INPUT_NO_WRAP 1208
#define SETPMOFF 1209
#define UNCONSTRAINED 1210
#define PAGE_TRAILER 1211
#define SETPMON 1212
#define BEFGROUP 1213
#define CLOSE_WINDOW 1214
#define COMMENT_LINE 1215
#define CONTINUE_FOR 1216
#define CREATE_DB 1217
#define CREATE_TABLE 1218
#define DEFAULT_NULL 1219
#define DEFAULT_TODAY 1220
#define DEFAULT_USER 1221
#define DELETE_USING 1222
#define DISPLAY_FORM 1223
#define END_FUNCTION 1224
#define EXIT_DISPLAY 1225
#define EXIT_FOREACH 1226
#define EXIT_PROGRAM 1227
#define INFCOLS 1228
#define ON_EVERY_ROW 1229
#define OPEN_SESSION 1230
#define RIGHT_MARGIN 1231
#define SELECT_USING 1232
#define START_REPORT 1233
#define UNLOCK_TABLE 1234
#define UPDATE_USING 1235
#define ACL_BUILTIN 1236
#define AFTGROUP 1237
#define INFIDX 1238
#define INFSTAT 1239
#define LEFT_MARGIN 1240
#define PAGE_HEADER 1241
#define ROLLBACK_W 1242
#define SET_SESSION 1243
#define SQLSEOFF 1244
#define WITH_A_LOG 1245
#define BEFDISP 1246
#define BEFORE_MENU 1247
#define CREATE_VIEW 1248
#define DEFINE_TYPE 1249
#define DELETE_FROM 1250
#define END_DISPLAY 1251
#define END_REPORT 1252
#define END_FOREACH 1253
#define END_FOR 1254
#define END_GLOBALS 1255
#define EXIT_PROMPT 1256
#define EXTENT_SIZE 1257
#define FOREIGN_KEY 1258
#define HIDE_OPTION 1259
#define HIDE_WINDOW 1260
#define INSERT_INTO 1261
#define IS_NOT_NULL 1262
#define MOVE_WINDOW 1263
#define NEXT_OPTION 1264
#define NOT_MATCHES 1265
#define ON_LAST_ROW 1266
#define OPEN_WINDOW 1267
#define OPEN_STATUSBOX 1268
#define PAGE_LENGTH 1269
#define PAGE_WIDTH 1270
#define PRIMARY_KEY 1271
#define PROMPT_LINE 1272
#define RECORD_LIKE 1273
#define ROLLFORWARD 1274
#define SETBL 1275
#define SHOW_OPTION 1276
#define SHOW_WINDOW 1277
#define SQLSEON 1278
#define TO_DATABASE 1279
#define USE_SESSION 1280
#define WITH_NO_LOG 1281
#define AFTDISP 1282
#define BEFFIELD 1283
#define INSHARE 1284
#define UNLOCKTAB 1285
#define AFTFIELD 1286
#define ATTRIBUTES 1287
#define BEFINP 1288
#define BEGIN_WORK 1289
#define CLEARWIN 1290
#define CLOSE_FORM 1291
#define DEFER_QUIT 1292
#define DESCENDING 1293
#define DROP_INDEX 1294
#define END_PROMPT 1295
#define END_RECORD 1296
#define ERROR_LINE 1297
#define EXIT_INPUT 1298
#define EXIT_WHILE 1299
#define FOR_UPDATE_OF 1300
#define FOR_UPDATE 1301
#define GET_FLDBUF 1302
#define INITIALIZE 1303
#define INPUT_WRAP 1304
#define LOCK_TABLE 1305
#define MSG_LINE 1306
#define NOT_EXISTS 1307
#define ON_ANY_KEY 1308
#define REFERENCES 1309
#define RENCOL 1310
#define SET_CURSOR 1311
#define SMALLFLOAT 1312
#define SQLSUCCESS 1313
#define TOP_MARGIN 1314
#define WITH_ARRAY 1315
#define ACCEPTKEY 1316
#define ACCEPT 1317
#define AFTINP 1318
#define CLEARFORMTODEFAULTS 1319
#define CLEARFORM 1320
#define CLEAR_X_FORM 1321
#define COMMIT_W 1322
#define NEXTPAGE 1323
#define PREVPAGE 1324
#define CTRL_KEY 1325
#define INFTABS 1326
#define NEXTFIELD 1327
#define NEXTFORM 1328
#define RENTAB 1329
#define ASCENDING 1330
#define ASSOCIATE 1331
#define CHAR 1332
#define NCHAR 1333
#define NVARCHAR 1334
#define CONSTRUCT 1335
#define DELIMITER 1336
#define DOWNSHIFT 1337
#define DROP_VIEW 1338
#define END_INPUT 1339
#define END_WHILE 1340
#define EXCLUSIVE 1341
#define EXIT_CASE 1342
#define EXIT_MENU 1343
#define FORM_LINE 1344
#define INTERRUPT 1346
#define INTO_TEMP 1347
#define INVISIBLE 1348
#define IN_MEMORY 1349
#define LINKED_TO 1350
#define LOAD_FROM 1351
#define LOCKTAB 1352
#define MENU_LINE 1353
#define OPEN_FORM 1354
#define OTHERWISE 1355
#define PRECISION 1356
#define PRIOR 1357
#define PROCEDURE 1358
#define REPORT_TO 1359
#define RETURNING 1360
#define UNDERLINE 1361
#define UNLOAD_TO 1362
#define BEFROW 1363
#define UNLOAD_T 1364
#define VARIABLE 1365
#define ABSOLUTE 1366
#define AFTROW 1367
#define BUFFERED 1368
#define CONSTANT 1369
#define CONST 1370
#define DATABASE 1371
#define DATETIME 1372
#define DEFAULTS 1373
#define DISTINCT 1374
#define END_CASE 1375
#define END_MAIN 1376
#define END_MENU 1377
#define END_TYPE 1378
#define EXIT_FOR 1379
#define EXTERNAL 1380
#define FRACTION 1381
#define FUNCTION 1382
#define GROUP_BY 1383
#define INTERVAL 1384
#define KWMESSAGE 1385
#define NOT_LIKE 1386
#define NOT_ILIKE 1387
#define NOT_NULL 1388
#define PASSWORD 1389
#define PREVIOUS 1390
#define READONLY 1391
#define REGISTER 1392
#define RELATIVE 1393
#define RESOURCE 1394
#define SMALLINT 1395
#define VALIDATE 1396
#define WITH_LOG 1397
#define WORDWRAP 1398
#define BY_NAME 1399
#define IN_FILE 1400
#define IS_NULL 1401
#define AVERAGE 1403
#define BETWEEN 1404
#define CAPTION 1405
#define CLIPPED 1406
#define CLOSE_BRACKET 1407
#define COLUMNS 1408
#define CONNECT 1410
#define CURRENT 1411
#define DBYNAME 1412
#define DECIMAL 1413
#define DECLARE 1414
#define DEFAULT 1415
#define DISPLAY 1416
#define ENDCODE 1417
#define EXECUTE 1418
#define FOREACH 1419
#define FOREIGN 1420
#define GLOBALS 1421
#define INFIELD 1422
#define INTEGER 1423
#define KWWINDOW 1424
#define MAGENTA 1425
#define OPTIONS 1427
#define PERCENT 1428
#define PREPARE 1429
#define PROGRAM 1430
#define RECOVER 1431
#define REVERSE 1432
#define SECTION 1433
#define SESSION 1434
#define SYNONYM 1435
#define THRU 1436
#define TRAILER 1437
#define UPSHIFT 1438
#define VARCHAR 1439
#define WAITING 1440
#define CLOSE_SHEV 1441
#define CLOSE_SQUARE 1442
#define KW_FALSE 1444
#define NOT_IN 1445
#define ONKEY 1446
#define OPEN_BRACKET 1447
#define BORDER 1448
#define BOTTOM 1449
#define COLUMN 1450
#define COMMIT 1451
#define CREATE 1452
#define CURSOR 1453
#define DEFINE 1454
#define DELETE 1455
#define DOUBLE 1456
#define END_IF 1457
#define ESCAPE 1458
#define EXISTS 1459
#define EXTEND 1460
#define EXTENT 1461
#define FINISH 1462
#define FORMAT 1463
#define HAVING 1464
#define HEADER 1465
#define INSERT 1466
#define LOCATE 1467
#define MARGIN 1468
#define MEMORY 1469
#define MINUTE 1470
#define MODIFY 1471
#define NORMAL 1472
#define EQUAL_EQUAL 1473
#define OPEN_SHEV 1475
#define OPEN_SQUARE 1476
#define OPTION 1477
#define OUTPUT 1478
#define PROMPT 1479
#define PUBLIC 1480
#define RECORD 1481
#define REPORT 1482
#define REVOKE 1483
#define SCHEMA 1484
#define SCROLL_USING 1485
#define SCROLL 1486
#define SECOND 1487
#define SELECT 1488
#define SERIAL 1489
#define SETL 1490
#define SHARED 1491
#define SPACES 1492
#define UNIQUE 1493
#define UNLOCK 1494
#define UPDATE 1495
#define VALUES 1496
#define YELLOW 1497
#define AFTER 1498
#define KWLINE 1499
#define KW_NULL 1500
#define KW_TRUE 1501
#define SINGLE_KEY 1502
#define ALTER 1503
#define ARRAY 1504
#define ASCII 1505
#define AUDIT 1506
#define BLACK 1507
#define BLINK 1508
#define CHECK 1509
#define CLEAR 1510
#define CLOSE 1511
#define CODE_C 1512
#define COUNT 1513
#define DEFER 1514
#define ERROR 1515
#define EVERY 1516
#define FETCH 1517
#define FIRST 1518
#define FLOAT 1519
#define FLUSH 1520
#define FOUND 1521
#define GRANT 1522
#define GREEN 1523
#define GROUP 1524
#define INDEX 1525
#define KWFORM 1526
#define LABEL 1527
#define LOCAL 1529
#define MONEY 1530
#define MONTH 1531
#define ORDER 1534
#define OUTER 1535
#define PAUSE 1536
#define PRINT_IMAGE 1537
#define PRINT_FILE 1538
#define PRINT 1539
#define RIGHT 1540
#define DOUBLE_COLON 1541
#define SEMICOLON 1542
#define SLEEP 1543
#define TUPLE 1544
#define UNION 1545
#define WHERE 1547
#define WHILE 1548
#define WHITE 1549
#define CCODE 1550
#define ANSI 1551
#define BLUE 1552
#define BOLD 1553
#define BYTE 1554
#define FCALL 1555
#define CASE 1556
#define CYAN 1557
#define DATE 1558
#define DESC 1559
#define KWDOWN 1561
#define TAB 1562
#define DROP 1563
#define ELSE 1564
#define EXEC 1565
#define EXIT 1566
#define FREE 1567
#define FROM 1568
#define GOTO 1569
#define HELP_FILE 1570
#define LANG_FILE 1571
#define HELP 1572
#define HIDE 1573
#define HOUR 1574
#define INTO 1575
#define LAST 1576
#define LEFT 1577
#define LIKE 1578
#define MAIN 1579
#define MENU 1580
#define MODE 1581
#define NEED 1582
#define NEXT 1583
#define NOCR 1584
#define OPEN 1585
#define QUIT 1586
#define REAL 1587
#define ROWS 1588
#define SHOW 1589
#define SIZE 1590
#define SKIP 1591
#define SOME 1592
#define STEP 1593
#define STOP 1594
#define TEMP 1595
#define TEXT 1596
#define THEN 1597
#define USER 1598
#define WAIT 1599
#define WHEN 1600
#define WITH 1601
#define WORK 1602
#define YEAR 1603
#define KW_IS 1605
#define XSET 1606
#define ADD 1607
#define ALL 1608
#define ANY 1610
#define ASC 1611
#define AVG 1612
#define COLON 1613
#define DAY 1615
#define DBA 1616
#define DEC 1617
#define DIM 1618
#define FKEY 1619
#define FOR 1620
#define KEY 1621
#define KWNO 1622
#define LET 1623
#define LOG 1624
#define XMAX 1625
#define XMIN 1626
#define PAD 1630
#define PUT 1631
#define RED 1632
#define ROW 1633
#define RUN 1634
#define SQL 1635
#define SUM 1636
#define TOP 1637
#define USE 1638
#define ATSIGN 1639
#define AS_TIFF 1641
#define AS_GIF 1642
#define AS_PNG 1643
#define AS_JPEG 1644
#define AS 1645
#define AT 1646
#define BY 1647
#define DOT 1648
#define GO 1649
#define IF 1650
#define IN 1651
#define OF 1652
#define ON 1653
#define TO 1655
#define KWUP 1656
#define FONT_NAME 1657
#define FONT_SIZE 1658
#define PAPER_SIZE_IS_LETTER 1659
#define PAPER_SIZE_IS_LEGAL 1660
#define PAPER_SIZE_IS_A5 1661
#define PAPER_SIZE_IS_A4 1662
#define PAPER_SIZE_IS_LETTER_L 1663
#define PAPER_SIZE_IS_LEGAL_L 1664
#define PAPER_SIZE_IS_A5_L 1665
#define PAPER_SIZE_IS_A4_L 1666
#define FORMHANDLER 1667
#define END_FORMHANDLER 1668
#define BEFORE_EVENT 1669
#define BEFORE_OPEN_FORM 1670
#define AFTER_EVENT 1671
#define BEFORE_CLOSE_FORM 1672
#define BEFORE_ANY 1673
#define AFTER_ANY 1674
#define MENUHANDLER 1675
#define END_MENUHANDLER 1676
#define BEFORE_SHOW_MENU 1677
#define DISABLE_PROGRAM 1678
#define DISABLE_ALL 1679
#define BUTTONS 1680
#define CHECK_MENUITEM 1681
#define DISABLE_FORM 1682
#define DISABLE_MENUITEMS 1683
#define DISABLE 1684
#define ENABLE_FORM 1685
#define ENABLE_MENUITEMS 1686
#define ENABLE 1687
#define KWFIELD 1688
#define ICON 1689
#define MESSAGEBOX 1690
#define TO_DEFAULTS 1691
#define UNCHECK_MENUITEM 1692
#define BEFORE 1693
#define INPUT 1694
#define END 1695
#define INT_TO_ID 1696
#define TIMEOUT 1697
#define OFF 1698
#define WITH_1_DIMENSION 1699
#define WITH_2_DIMENSION 1700
#define WITH_3_DIMENSION 1701
#define TILDE 1702
#define ILIKE 1703
#define FGL_ISDYNARR_ALLOCATED 1704
#define FGL_DYNARR_EXTENTSIZE 1705
#define FILLFACTOR 1706




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
/* Line 1248 of yacc.c.  */
#line 1507 "y.tab.h"
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif





