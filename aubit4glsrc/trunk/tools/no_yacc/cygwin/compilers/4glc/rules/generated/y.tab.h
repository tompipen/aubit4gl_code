/* A Bison parser, made by GNU Bison 1.875b.  */

/* Skeleton parser for Yacc-like parsing with Bison,
   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003 Free Software Foundation, Inc.

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
     NAME = 1727,
     UMINUS = 1728,
     COMMA = 1628,
     KW_OR = 1668,
     KW_AND = 1623,
     KW_USING = 1560,
     NOT = 1643,
     MATCHES = 1441,
     POWER = 1546,
     LESS_THAN = 1542,
     GREATER_THAN = 1458,
     EQUAL = 1618,
     GREATER_THAN_EQ = 1360,
     LESS_THAN_EQ = 1417,
     NOT_EQUAL = 1489,
     PLUS = 1654,
     MINUS = 1641,
     MULTIPLY = 1547,
     DIVIDE = 1574,
     MOD = 1642,
     COMMAND = 1424,
     NUMBER_VALUE = 1729,
     CHAR_VALUE = 1730,
     INT_VALUE = 1731,
     NAMED_GEN = 1732,
     CLINE = 1733,
     SQLLINE = 1734,
     KW_CSTART = 1735,
     KW_CEND = 1736,
     USER_DTYPE = 1737,
     SQL_TEXT = 1738,
     KW_WHENEVER_SET = 1739,
     COMMENT = 1740,
     MEMBER_FUNCTION = 1000,
     MISC_INFX_SQL = 1001,
     AS_CONVERTABLE = 1002,
     FREE_REPORT = 1003,
     CONVERTING_TO_MANY = 1004,
     CONVERTING_TO = 1005,
     CONVERT_REPORT = 1006,
     DATETIME_VALUE = 1007,
     INTERVAL_VALUE = 1008,
     RECOVER_TABLE = 1009,
     ROLLFORWARD_DATABASE = 1010,
     IN_LINE_MODE = 1011,
     IN_FORM_MODE = 1012,
     FGL_SIZEOF = 1013,
     IMPORT_PACKAGE = 1014,
     DYNAMIC_ARRAY = 1015,
     RESIZE_ARRAY = 1016,
     ALLOCATE_ARRAY = 1017,
     DEALLOCATE_ARRAY = 1018,
     AFTER_INSERT_DELETE = 1019,
     BEFORE_INSERT_DELETE = 1020,
     BEFORE_INSERT = 1021,
     CONCAT_PIPES = 1022,
     BEFORE_DELETE = 1023,
     DROP_TRIGGER = 1024,
     DROP_AUDIT_FOR = 1025,
     CREATE_AUDIT_FOR = 1026,
     AFTER_INSERT = 1027,
     AFTER_DELETE = 1028,
     EXECUTE_IMMEDIATE = 1029,
     DELETE_ROW_EQUAL_TRUE = 1030,
     INSERT_ROW_EQUAL_TRUE = 1031,
     DELETE_ROW_EQUAL_FALSE = 1032,
     INSERT_ROW_EQUAL_FALSE = 1033,
     CURRENT_ROW_DISPLAY_EQUAL = 1034,
     MAXCOUNT = 1035,
     ALTER_TABLE = 1036,
     ALTER_INDEX = 1037,
     NEXT_SIZE = 1038,
     DISPLAY_ATTR_FORM = 1039,
     DISPLAY_ATTR_WINDOW = 1040,
     INPUT_ATTR_FORM = 1041,
     INPUT_ATTR_WINDOW = 1042,
     WHENEVER_ERROR_CONTINUE = 1043,
     WHENEVER_ANY_ERROR_CONTINUE = 1044,
     WHENEVER_WARNING_CONTINUE = 1045,
     WHENEVER_SQLSUCCESS_CONTINUE = 1046,
     WHENEVER_SQLWARNING_CONTINUE = 1047,
     WHENEVER_NOT_FOUND_CONTINUE = 1048,
     WHENEVER_SQLERROR_CONTINUE = 1049,
     WHENEVER_SUCCESS_CONTINUE = 1050,
     WHENEVER_ERROR_GOTO = 1051,
     WHENEVER_ANY_ERROR_GOTO = 1052,
     WHENEVER_WARNING_GOTO = 1053,
     WHENEVER_SQLSUCCESS_GOTO = 1054,
     WHENEVER_SQLWARNING_GOTO = 1055,
     WHENEVER_NOT_FOUND_GOTO = 1056,
     WHENEVER_SQLERROR_GOTO = 1057,
     WHENEVER_SUCCESS_GOTO = 1058,
     WHENEVER_ERROR_CALL = 1059,
     WHENEVER_ANY_ERROR_CALL = 1060,
     WHENEVER_WARNING_CALL = 1061,
     WHENEVER_SQLSUCCESS_CALL = 1062,
     WHENEVER_SQLWARNING_CALL = 1063,
     WHENEVER_NOT_FOUND_CALL = 1064,
     WHENEVER_SQLERROR_CALL = 1065,
     WHENEVER_SUCCESS_CALL = 1066,
     WHENEVER_ERROR_STOP = 1067,
     WHENEVER_ANY_ERROR_STOP = 1068,
     WHENEVER_WARNING_STOP = 1069,
     WHENEVER_SQLSUCCESS_STOP = 1070,
     WHENEVER_SQLWARNING_STOP = 1071,
     WHENEVER_NOT_FOUND_STOP = 1072,
     WHENEVER_SQLERROR_STOP = 1073,
     WHENEVER_SUCCESS_STOP = 1074,
     XSET_MULTIPLY_EQUAL_OPEN_BRACKET = 1075,
     XSET_ident_DOT_MULTIPLY_EQUAL_OPEN_BRACKET = 1076,
     XSET_ident_DOT_MULTIPLY_EQUAL = 1077,
     XSET_MULTIPLY_EQUAL = 1078,
     XSET_OPEN_BRACKET = 1079,
     NEWFORMATSHARED = 1080,
     DEFINE_NEW_TYPE = 1081,
     CREATE_DATABASE = 1082,
     DROP_DATABASE = 1083,
     IMPORT_LEGACY_FUNCTION = 1084,
     ADD_CONSTRAINT = 1085,
     DROP_CONSTRAINT = 1086,
     DROP_SYNONYM = 1087,
     CONSTRAINT = 1088,
     AS_STATIC = 1089,
     NOT_FIELD_TOUCHED = 1090,
     LOCAL_FUNCTION = 1091,
     EVERY_ROW = 1092,
     ELIF = 1093,
     DOUBLE_PRECISION = 1094,
     COUNT_MULTIPLY = 1095,
     WAIT_FOR_KEY = 1096,
     AT_TERMINATION_CALL = 1097,
     TERMINATE_REPORT = 1098,
     TO_MAIN_CAPTION = 1099,
     CLEARSTAT = 1100,
     TO_MENUITEM = 1101,
     ID_TO_INT = 1102,
     TO_STATUSBOX = 1103,
     ASCII_HEIGHT_ALL = 1104,
     ASCII_WIDTH_ALL = 1105,
     IMPORT_DATATYPE = 1106,
     PAGE_TRAILER_SIZE = 1107,
     PAGE_HEADER_SIZE = 1108,
     FIRST_PAGE_HEADER_SIZE = 1109,
     BYTES_USE_AS_IMAGE = 1110,
     BYTES_USE_AS_ASCII = 1111,
     KWUP_BY = 1112,
     KWDOWN_BY = 1113,
     CLOSE_STATUSBOX = 1114,
     MODIFY_NEXT_SIZE = 1115,
     LOCK_MODE_PAGE = 1116,
     LOCK_MODE_ROW = 1117,
     TO_PIPE = 1118,
     TO_SCREEN = 1119,
     TO_PRINTER = 1120,
     STATUSBOX = 1121,
     UNITS_YEAR = 1122,
     UNITS_MONTH = 1123,
     UNITS_DAY = 1124,
     UNITS_HOUR = 1125,
     UNITS_MINUTE = 1126,
     UNITS_SECOND = 1127,
     NO_NEW_LINES = 1128,
     FIELDTOWIDGET = 1129,
     WITH_HOLD = 1130,
     SHOW_MENU = 1131,
     TO_CLUSTER = 1132,
     TO_NOT_CLUSTER = 1133,
     CWIS = 1134,
     CREATE_IDX = 1135,
     FORM_IS_COMPILED = 1136,
     PDF_REPORT = 1137,
     IMPORT_FUNCTION = 1138,
     PROMPT_MANY = 1139,
     POINTS = 1140,
     MM = 1141,
     INCHES = 1142,
     PREPEND = 1143,
     MEMBER_OF = 1144,
     APPEND = 1145,
     TEMPLATE = 1146,
     END_TEMPLATE = 1147,
     SQLSICS = 1148,
     CREATE_SCHEMA = 1149,
     SQLSIRR = 1150,
     UPDATESTATS_T = 1151,
     SQLSICR = 1152,
     WHENEVER_SQLSUCCESS = 1153,
     WHENEVER_SQLWARNING = 1154,
     WHENEVER_ANY_ERROR = 1155,
     WHENEVER_NOT_FOUND = 1156,
     WHENEVER_SQLERROR = 1157,
     WHENEVER_SUCCESS = 1158,
     WHENEVER_ERROR = 1159,
     START_EXTERN = 1160,
     CONTINUE_CONSTRUCT = 1161,
     FOUNCONSTR = 1162,
     SQLSIDR = 1163,
     CREATE_TEMP_TABLE = 1164,
     CURRENT_WINDOW_IS = 1165,
     FIRST_PAGE_HEADER = 1166,
     ORDER_EXTERNAL_BY = 1167,
     SCROLL_CURSOR_FOR = 1168,
     SCROLL_CURSOR = 1169,
     SQL_INTERRUPT_OFF = 1170,
     STOP_ALL_EXTERNAL = 1171,
     WITH_CHECK_OPTION = 1172,
     WITH_GRANT_OPTION = 1173,
     SQLSLMNW = 1174,
     ADDCONSTUNIQ = 1175,
     CONTINUE_DISPLAY = 1176,
     CONTINUE_FOREACH = 1177,
     OUTPUT_TO_REPORT = 1178,
     SQL_INTERRUPT_ON = 1179,
     WHERE_CURRENT_OF = 1180,
     WITHOUT_DEFAULTS = 1181,
     FOCONSTR = 1182,
     SCALED_BY = 1183,
     CONTINUE_PROMPT = 1184,
     PDF_FUNCTION = 1185,
     DEFER_INTERRUPT = 1186,
     DISPLAY_BY_NAME = 1187,
     NOT_NULL_UNIQUE = 1188,
     SKIP_TO_TOP = 1189,
     TOP_OF_PAGE = 1190,
     SKIP_TO = 1191,
     SKIP_BY = 1192,
     WITHOUT_WAITING = 1193,
     BEFCONSTRUCT = 1194,
     SQLSLMW = 1195,
     AFTCONSTRUCT = 1196,
     ALL_PRIVILEGES = 1197,
     CLOSE_DATABASE = 1198,
     CONTINUE_INPUT = 1199,
     CONTINUE_WHILE = 1200,
     CREATE_SYNONYM = 1201,
     DROP_TABLE = 1202,
     EXIT_CONSTRUCT = 1203,
     INEXCLUSIVE = 1204,
     REPORT_TO_PRINTER = 1205,
     REPORT_TO_PIPE = 1206,
     RETURN = 1207,
     SET_SESSION_TO = 1208,
     UPDATESTATS = 1209,
     WITHOUT_HEAD = 1210,
     CLEARSCR = 1211,
     WITH_B_LOG = 1212,
     AUTHORIZATION = 1213,
     BOTTOM_MARGIN = 1214,
     CLOSE_SESSION = 1215,
     CONTINUE_CASE = 1216,
     CONTINUE_MENU = 1217,
     DISPLAY_ARRAY = 1218,
     END_SQL = 1219,
     DOLLAR = 1220,
     END_CONSTRUCT = 1221,
     FIELD_TOUCHED = 1222,
     FINISH_REPORT = 1223,
     INFACC = 1224,
     INPUT_NO_WRAP = 1225,
     SETPMOFF = 1226,
     UNCONSTRAINED = 1227,
     PAGE_TRAILER = 1228,
     SETPMON = 1229,
     BEFGROUP = 1230,
     CLOSE_WINDOW = 1231,
     COMMENT_LINE = 1232,
     CONTINUE_FOR = 1233,
     CREATE_DB = 1234,
     CREATE_TABLE = 1235,
     DEFAULT_NULL = 1236,
     DEFAULT_TODAY = 1237,
     DEFAULT_USER = 1238,
     DELETE_USING = 1239,
     DISPLAY_FORM = 1240,
     END_FUNCTION = 1241,
     EXIT_DISPLAY = 1242,
     EXIT_FOREACH = 1243,
     EXIT_PROGRAM = 1244,
     INFCOLS = 1245,
     ON_EVERY_ROW = 1246,
     OPEN_SESSION = 1247,
     RIGHT_MARGIN = 1248,
     SELECT_USING = 1249,
     START_REPORT = 1250,
     UNLOCK_TABLE = 1251,
     UPDATE_USING = 1252,
     ACL_BUILTIN = 1253,
     AFTGROUP = 1254,
     INFIDX = 1255,
     INFSTAT = 1256,
     LEFT_MARGIN = 1257,
     PAGE_HEADER = 1258,
     ROLLBACK_W = 1259,
     SET_SESSION = 1260,
     SQLSEOFF = 1261,
     WITH_A_LOG = 1262,
     BEFDISP = 1263,
     BEFORE_MENU = 1264,
     CREATE_VIEW = 1265,
     DELETE_FROM = 1266,
     END_DISPLAY = 1267,
     END_REPORT = 1268,
     END_FOREACH = 1269,
     END_FOR = 1270,
     END_GLOBALS = 1271,
     EXIT_PROMPT = 1272,
     EXTENT_SIZE = 1273,
     FOREIGN_KEY = 1274,
     HIDE_OPTION = 1275,
     HIDE_WINDOW = 1276,
     INSERT_INTO = 1277,
     IS_NOT_NULL = 1278,
     MOVE_WINDOW = 1279,
     NEXT_OPTION = 1280,
     NOT_MATCHES = 1281,
     ON_LAST_ROW = 1282,
     OPEN_WINDOW = 1283,
     OPEN_STATUSBOX = 1284,
     PAGE_LENGTH = 1285,
     PAGE_WIDTH = 1286,
     PRIMARY_KEY = 1287,
     PROMPT_LINE = 1288,
     RECORD_LIKE = 1289,
     ROLLFORWARD = 1290,
     SHOW_OPTION = 1291,
     SHOW_WINDOW = 1292,
     SQLSEON = 1293,
     TO_DATABASE = 1294,
     USE_SESSION = 1295,
     WITH_NO_LOG = 1296,
     AFTDISP = 1297,
     BEFFIELD = 1298,
     INSHARE = 1299,
     UNLOCKTAB = 1300,
     AFTFIELD = 1301,
     ATTRIBUTES = 1302,
     BEFINP = 1303,
     BEGIN_WORK = 1304,
     CLEARWIN = 1305,
     CLOSE_FORM = 1306,
     DEFER_QUIT = 1307,
     DESCENDING = 1308,
     DROP_INDEX = 1309,
     END_PROMPT = 1310,
     END_RECORD = 1311,
     ERROR_LINE = 1312,
     EXIT_INPUT = 1313,
     EXIT_WHILE = 1314,
     FOR_UPDATE_OF = 1315,
     FOR_UPDATE = 1316,
     GET_FLDBUF = 1317,
     INITIALIZE = 1318,
     INPUT_WRAP = 1319,
     LOCK_TABLE = 1320,
     MSG_LINE = 1321,
     NOT_EXISTS = 1322,
     ON_ANY_KEY = 1323,
     REFERENCES = 1324,
     RENCOL = 1325,
     SET_CURSOR = 1326,
     SMALLFLOAT = 1327,
     SQLSUCCESS = 1328,
     TOP_MARGIN = 1329,
     WITH_ARRAY = 1330,
     ACCEPTKEY = 1331,
     ACCEPT = 1332,
     AFTINP = 1333,
     CLEARFORMTODEFAULTS = 1334,
     CLEARFORM = 1335,
     CLEAR_X_FORM = 1336,
     COMMIT_W = 1337,
     NEXTPAGE = 1338,
     PREVPAGE = 1339,
     CTRL_KEY = 1340,
     INFTABS = 1341,
     NEXTFIELD = 1342,
     NEXTFORM = 1343,
     RENTAB = 1344,
     ASCENDING = 1345,
     ASSOCIATE = 1346,
     CHAR = 1347,
     NCHAR = 1348,
     NVARCHAR = 1349,
     CONSTRUCT = 1350,
     DELIMITER = 1351,
     DOWNSHIFT = 1352,
     DROP_VIEW = 1353,
     END_INPUT = 1354,
     END_WHILE = 1355,
     EXCLUSIVE = 1356,
     EXIT_CASE = 1357,
     EXIT_MENU = 1358,
     FORM_LINE = 1359,
     INTERRUPT = 1361,
     INTO_TEMP = 1362,
     INVISIBLE = 1363,
     IN_MEMORY = 1364,
     LINKED_TO = 1365,
     LOAD_FROM = 1366,
     LOCKTAB = 1367,
     MENU_LINE = 1368,
     OPEN_FORM = 1369,
     OTHERWISE = 1370,
     PRECISION = 1371,
     PRIOR = 1372,
     PROCEDURE = 1373,
     REPORT_TO = 1374,
     RETURNING = 1375,
     UNDERLINE = 1376,
     UNLOAD_TO = 1377,
     BEFROW = 1378,
     UNLOAD_T = 1379,
     VARIABLE = 1380,
     ABSOLUTE = 1381,
     AFTROW = 1382,
     BUFFERED = 1383,
     CONSTANT = 1384,
     CONST = 1385,
     DATABASE = 1386,
     DATETIME = 1387,
     DEFAULTS = 1388,
     DISTINCT = 1389,
     END_CASE = 1390,
     END_MAIN = 1391,
     END_MENU = 1392,
     END_TYPE = 1393,
     EXIT_FOR = 1394,
     EXTERNAL = 1395,
     FRACTION = 1396,
     FUNCTION = 1397,
     GROUP_BY = 1398,
     INTERVAL = 1399,
     KWMESSAGE = 1400,
     NOT_LIKE = 1401,
     NOT_ILIKE = 1402,
     NOT_NULL = 1403,
     PASSWORD = 1404,
     PREVIOUS = 1405,
     READONLY = 1406,
     REGISTER = 1407,
     RELATIVE = 1408,
     RESOURCE = 1409,
     SMALLINT = 1410,
     VALIDATE = 1411,
     WITH_LOG = 1412,
     WORDWRAP = 1413,
     BY_NAME = 1414,
     IN_FILE = 1415,
     IS_NULL = 1416,
     AVERAGE = 1418,
     BETWEEN = 1419,
     CAPTION = 1420,
     CLIPPED = 1421,
     CLOSE_BRACKET = 1422,
     COLUMNS = 1423,
     CONNECT = 1425,
     CURRENT = 1426,
     DBYNAME = 1427,
     DECIMAL = 1428,
     DECLARE = 1429,
     DEFAULT = 1430,
     DISPLAY = 1431,
     ENDCODE = 1432,
     EXECUTE = 1433,
     FOREACH = 1434,
     FOREIGN = 1435,
     GLOBALS = 1436,
     INFIELD = 1437,
     INTEGER = 1438,
     KWWINDOW = 1439,
     MAGENTA = 1440,
     OPTIONS = 1442,
     PERCENT = 1443,
     PREPARE = 1444,
     PROGRAM = 1445,
     RECOVER = 1446,
     REVERSE = 1447,
     SECTION = 1448,
     SESSION = 1449,
     SYNONYM = 1450,
     THRU = 1451,
     TRAILER = 1452,
     UPSHIFT = 1453,
     VARCHAR = 1454,
     WAITING = 1455,
     CLOSE_SHEV = 1456,
     CLOSE_SQUARE = 1457,
     KW_FALSE = 1459,
     NOT_IN = 1460,
     ONKEY = 1461,
     OPEN_BRACKET = 1462,
     BORDER = 1463,
     BOTTOM = 1464,
     COLUMN = 1465,
     COMMIT = 1466,
     CREATE = 1467,
     CURSOR = 1468,
     DEFINE = 1469,
     DELETE = 1470,
     DOUBLE = 1471,
     END_IF = 1472,
     ESCAPE = 1473,
     EXISTS = 1474,
     EXTEND = 1475,
     EXTENT = 1476,
     FINISH = 1477,
     FORMAT = 1478,
     HAVING = 1479,
     HEADER = 1480,
     INSERT = 1481,
     LOCATE = 1482,
     MARGIN = 1483,
     MEMORY = 1484,
     MINUTE = 1485,
     MODIFY = 1486,
     NORMAL = 1487,
     EQUAL_EQUAL = 1488,
     OPEN_SHEV = 1490,
     OPEN_SQUARE = 1491,
     OPTION = 1492,
     OUTPUT = 1493,
     PROMPT = 1494,
     PUBLIC = 1495,
     RECORD = 1496,
     REPORT = 1497,
     REVOKE = 1498,
     SCHEMA = 1499,
     SCROLL_USING = 1500,
     SCROLL = 1501,
     SECOND = 1502,
     SELECT = 1503,
     SERIAL = 1504,
     SHARED = 1505,
     SPACES = 1506,
     UNIQUE = 1507,
     UNLOCK = 1508,
     UPDATE = 1509,
     VALUES = 1510,
     YELLOW = 1511,
     AFTER = 1512,
     KWLINE = 1513,
     KW_NULL = 1514,
     KW_TRUE = 1515,
     SINGLE_KEY = 1516,
     ALTER = 1517,
     ARRAY = 1518,
     ASCII = 1519,
     AUDIT = 1520,
     BLACK = 1521,
     BLINK = 1522,
     CHECK = 1523,
     CLEAR = 1524,
     CLOSE = 1525,
     CODE_C = 1526,
     COUNT = 1527,
     DEFER = 1528,
     ERROR = 1529,
     EVERY = 1530,
     FETCH = 1531,
     FIRST = 1532,
     FLOAT = 1533,
     FLUSH = 1534,
     FOUND = 1535,
     GRANT = 1536,
     GREEN = 1537,
     GROUP = 1538,
     INDEX = 1539,
     KWFORM = 1540,
     LABEL = 1541,
     LOCAL = 1543,
     MONEY = 1544,
     MONTH = 1545,
     ORDER = 1548,
     OUTER = 1549,
     PAUSE = 1550,
     PRINT_IMAGE = 1551,
     PRINT_FILE = 1552,
     PRINT = 1553,
     RIGHT = 1554,
     DOUBLE_COLON = 1555,
     SEMICOLON = 1556,
     SLEEP = 1557,
     TUPLE = 1558,
     UNION = 1559,
     WHERE = 1561,
     WHILE = 1562,
     WHITE = 1563,
     CCODE = 1564,
     ANSI = 1565,
     BLUE = 1566,
     BOLD = 1567,
     BYTE = 1568,
     FCALL = 1569,
     CASE = 1570,
     CYAN = 1571,
     DATE = 1572,
     DESC = 1573,
     KWDOWN = 1575,
     TAB = 1576,
     DROP = 1577,
     ELSE = 1578,
     EXEC = 1579,
     EXIT = 1580,
     FREE = 1581,
     FROM = 1582,
     GOTO = 1583,
     HELP_FILE = 1584,
     LANG_FILE = 1585,
     HELP = 1586,
     HIDE = 1587,
     HOUR = 1588,
     INTO = 1589,
     LAST = 1590,
     LEFT = 1591,
     LIKE = 1592,
     MAIN = 1593,
     MENU = 1594,
     MODE = 1595,
     NEED = 1596,
     NEXT = 1597,
     NOCR = 1598,
     OPEN = 1599,
     QUIT = 1600,
     REAL = 1601,
     ROWS = 1602,
     SHOW = 1603,
     SIZE = 1604,
     SKIP = 1605,
     SOME = 1606,
     STEP = 1607,
     STOP = 1608,
     TEMP = 1609,
     TEXT = 1610,
     THEN = 1611,
     USER = 1612,
     WAIT = 1613,
     WHEN = 1614,
     WITH = 1615,
     WORK = 1616,
     YEAR = 1617,
     KW_IS = 1619,
     XSET = 1620,
     ADD = 1621,
     ALL = 1622,
     ANY = 1624,
     ASC = 1625,
     AVG = 1626,
     COLON = 1627,
     DAY = 1629,
     DBA = 1630,
     DEC = 1631,
     DIM = 1632,
     FKEY = 1633,
     FOR = 1634,
     KEY = 1635,
     KWNO = 1636,
     LET = 1637,
     LOG = 1638,
     XMAX = 1639,
     XMIN = 1640,
     PAD = 1644,
     PUT = 1645,
     RED = 1646,
     ROW = 1647,
     RUN = 1648,
     SQL = 1649,
     SUM = 1650,
     TOP = 1651,
     USE = 1652,
     ATSIGN = 1653,
     AS_TIFF = 1655,
     AS_GIF = 1656,
     AS_PNG = 1657,
     AS_JPEG = 1658,
     AS = 1659,
     AT = 1660,
     BY = 1661,
     DOT = 1662,
     GO = 1663,
     IF = 1664,
     IN = 1665,
     OF = 1666,
     ON = 1667,
     TO = 1669,
     KWUP = 1670,
     FONT_NAME = 1671,
     FONT_SIZE = 1672,
     PAPER_SIZE_IS_LETTER = 1673,
     PAPER_SIZE_IS_LEGAL = 1674,
     PAPER_SIZE_IS_A5 = 1675,
     PAPER_SIZE_IS_A4 = 1676,
     PAPER_SIZE_IS_LETTER_L = 1677,
     PAPER_SIZE_IS_LEGAL_L = 1678,
     PAPER_SIZE_IS_A5_L = 1679,
     PAPER_SIZE_IS_A4_L = 1680,
     FORMHANDLER = 1681,
     END_FORMHANDLER = 1682,
     BEFORE_EVENT = 1683,
     BEFORE_OPEN_FORM = 1684,
     AFTER_EVENT = 1685,
     BEFORE_CLOSE_FORM = 1686,
     BEFORE_ANY = 1687,
     AFTER_ANY = 1688,
     MENUHANDLER = 1689,
     END_MENUHANDLER = 1690,
     BEFORE_SHOW_MENU = 1691,
     DISABLE_PROGRAM = 1692,
     DISABLE_ALL = 1693,
     BUTTONS = 1694,
     CHECK_MENUITEM = 1695,
     DISABLE_FORM = 1696,
     DISABLE_MENUITEMS = 1697,
     DISABLE = 1698,
     ENABLE_FORM = 1699,
     ENABLE_MENUITEMS = 1700,
     ENABLE = 1701,
     KWFIELD = 1702,
     ICON = 1703,
     MESSAGEBOX = 1704,
     TO_DEFAULTS = 1705,
     UNCHECK_MENUITEM = 1706,
     BEFORE = 1707,
     INPUT = 1708,
     END = 1709,
     INT_TO_ID = 1710,
     TIMEOUT = 1711,
     OFF = 1712,
     WITH_1_DIMENSION = 1713,
     WITH_2_DIMENSION = 1714,
     WITH_3_DIMENSION = 1715,
     TILDE = 1716,
     ILIKE = 1717,
     FGL_ISDYNARR_ALLOCATED = 1718,
     FGL_DYNARR_EXTENTSIZE = 1719,
     FILLFACTOR = 1720,
     END_CLASS = 1721,
     KW_CLASS = 1722,
     EXTENDS = 1723,
     PIPE = 1724,
     FORMHANDLER_INPUT = 1725
   };
#endif
#define NAME 1727
#define UMINUS 1728
#define COMMA 1628
#define KW_OR 1668
#define KW_AND 1623
#define KW_USING 1560
#define NOT 1643
#define MATCHES 1441
#define POWER 1546
#define LESS_THAN 1542
#define GREATER_THAN 1458
#define EQUAL 1618
#define GREATER_THAN_EQ 1360
#define LESS_THAN_EQ 1417
#define NOT_EQUAL 1489
#define PLUS 1654
#define MINUS 1641
#define MULTIPLY 1547
#define DIVIDE 1574
#define MOD 1642
#define COMMAND 1424
#define NUMBER_VALUE 1729
#define CHAR_VALUE 1730
#define INT_VALUE 1731
#define NAMED_GEN 1732
#define CLINE 1733
#define SQLLINE 1734
#define KW_CSTART 1735
#define KW_CEND 1736
#define USER_DTYPE 1737
#define SQL_TEXT 1738
#define KW_WHENEVER_SET 1739
#define COMMENT 1740
#define MEMBER_FUNCTION 1000
#define MISC_INFX_SQL 1001
#define AS_CONVERTABLE 1002
#define FREE_REPORT 1003
#define CONVERTING_TO_MANY 1004
#define CONVERTING_TO 1005
#define CONVERT_REPORT 1006
#define DATETIME_VALUE 1007
#define INTERVAL_VALUE 1008
#define RECOVER_TABLE 1009
#define ROLLFORWARD_DATABASE 1010
#define IN_LINE_MODE 1011
#define IN_FORM_MODE 1012
#define FGL_SIZEOF 1013
#define IMPORT_PACKAGE 1014
#define DYNAMIC_ARRAY 1015
#define RESIZE_ARRAY 1016
#define ALLOCATE_ARRAY 1017
#define DEALLOCATE_ARRAY 1018
#define AFTER_INSERT_DELETE 1019
#define BEFORE_INSERT_DELETE 1020
#define BEFORE_INSERT 1021
#define CONCAT_PIPES 1022
#define BEFORE_DELETE 1023
#define DROP_TRIGGER 1024
#define DROP_AUDIT_FOR 1025
#define CREATE_AUDIT_FOR 1026
#define AFTER_INSERT 1027
#define AFTER_DELETE 1028
#define EXECUTE_IMMEDIATE 1029
#define DELETE_ROW_EQUAL_TRUE 1030
#define INSERT_ROW_EQUAL_TRUE 1031
#define DELETE_ROW_EQUAL_FALSE 1032
#define INSERT_ROW_EQUAL_FALSE 1033
#define CURRENT_ROW_DISPLAY_EQUAL 1034
#define MAXCOUNT 1035
#define ALTER_TABLE 1036
#define ALTER_INDEX 1037
#define NEXT_SIZE 1038
#define DISPLAY_ATTR_FORM 1039
#define DISPLAY_ATTR_WINDOW 1040
#define INPUT_ATTR_FORM 1041
#define INPUT_ATTR_WINDOW 1042
#define WHENEVER_ERROR_CONTINUE 1043
#define WHENEVER_ANY_ERROR_CONTINUE 1044
#define WHENEVER_WARNING_CONTINUE 1045
#define WHENEVER_SQLSUCCESS_CONTINUE 1046
#define WHENEVER_SQLWARNING_CONTINUE 1047
#define WHENEVER_NOT_FOUND_CONTINUE 1048
#define WHENEVER_SQLERROR_CONTINUE 1049
#define WHENEVER_SUCCESS_CONTINUE 1050
#define WHENEVER_ERROR_GOTO 1051
#define WHENEVER_ANY_ERROR_GOTO 1052
#define WHENEVER_WARNING_GOTO 1053
#define WHENEVER_SQLSUCCESS_GOTO 1054
#define WHENEVER_SQLWARNING_GOTO 1055
#define WHENEVER_NOT_FOUND_GOTO 1056
#define WHENEVER_SQLERROR_GOTO 1057
#define WHENEVER_SUCCESS_GOTO 1058
#define WHENEVER_ERROR_CALL 1059
#define WHENEVER_ANY_ERROR_CALL 1060
#define WHENEVER_WARNING_CALL 1061
#define WHENEVER_SQLSUCCESS_CALL 1062
#define WHENEVER_SQLWARNING_CALL 1063
#define WHENEVER_NOT_FOUND_CALL 1064
#define WHENEVER_SQLERROR_CALL 1065
#define WHENEVER_SUCCESS_CALL 1066
#define WHENEVER_ERROR_STOP 1067
#define WHENEVER_ANY_ERROR_STOP 1068
#define WHENEVER_WARNING_STOP 1069
#define WHENEVER_SQLSUCCESS_STOP 1070
#define WHENEVER_SQLWARNING_STOP 1071
#define WHENEVER_NOT_FOUND_STOP 1072
#define WHENEVER_SQLERROR_STOP 1073
#define WHENEVER_SUCCESS_STOP 1074
#define XSET_MULTIPLY_EQUAL_OPEN_BRACKET 1075
#define XSET_ident_DOT_MULTIPLY_EQUAL_OPEN_BRACKET 1076
#define XSET_ident_DOT_MULTIPLY_EQUAL 1077
#define XSET_MULTIPLY_EQUAL 1078
#define XSET_OPEN_BRACKET 1079
#define NEWFORMATSHARED 1080
#define DEFINE_NEW_TYPE 1081
#define CREATE_DATABASE 1082
#define DROP_DATABASE 1083
#define IMPORT_LEGACY_FUNCTION 1084
#define ADD_CONSTRAINT 1085
#define DROP_CONSTRAINT 1086
#define DROP_SYNONYM 1087
#define CONSTRAINT 1088
#define AS_STATIC 1089
#define NOT_FIELD_TOUCHED 1090
#define LOCAL_FUNCTION 1091
#define EVERY_ROW 1092
#define ELIF 1093
#define DOUBLE_PRECISION 1094
#define COUNT_MULTIPLY 1095
#define WAIT_FOR_KEY 1096
#define AT_TERMINATION_CALL 1097
#define TERMINATE_REPORT 1098
#define TO_MAIN_CAPTION 1099
#define CLEARSTAT 1100
#define TO_MENUITEM 1101
#define ID_TO_INT 1102
#define TO_STATUSBOX 1103
#define ASCII_HEIGHT_ALL 1104
#define ASCII_WIDTH_ALL 1105
#define IMPORT_DATATYPE 1106
#define PAGE_TRAILER_SIZE 1107
#define PAGE_HEADER_SIZE 1108
#define FIRST_PAGE_HEADER_SIZE 1109
#define BYTES_USE_AS_IMAGE 1110
#define BYTES_USE_AS_ASCII 1111
#define KWUP_BY 1112
#define KWDOWN_BY 1113
#define CLOSE_STATUSBOX 1114
#define MODIFY_NEXT_SIZE 1115
#define LOCK_MODE_PAGE 1116
#define LOCK_MODE_ROW 1117
#define TO_PIPE 1118
#define TO_SCREEN 1119
#define TO_PRINTER 1120
#define STATUSBOX 1121
#define UNITS_YEAR 1122
#define UNITS_MONTH 1123
#define UNITS_DAY 1124
#define UNITS_HOUR 1125
#define UNITS_MINUTE 1126
#define UNITS_SECOND 1127
#define NO_NEW_LINES 1128
#define FIELDTOWIDGET 1129
#define WITH_HOLD 1130
#define SHOW_MENU 1131
#define TO_CLUSTER 1132
#define TO_NOT_CLUSTER 1133
#define CWIS 1134
#define CREATE_IDX 1135
#define FORM_IS_COMPILED 1136
#define PDF_REPORT 1137
#define IMPORT_FUNCTION 1138
#define PROMPT_MANY 1139
#define POINTS 1140
#define MM 1141
#define INCHES 1142
#define PREPEND 1143
#define MEMBER_OF 1144
#define APPEND 1145
#define TEMPLATE 1146
#define END_TEMPLATE 1147
#define SQLSICS 1148
#define CREATE_SCHEMA 1149
#define SQLSIRR 1150
#define UPDATESTATS_T 1151
#define SQLSICR 1152
#define WHENEVER_SQLSUCCESS 1153
#define WHENEVER_SQLWARNING 1154
#define WHENEVER_ANY_ERROR 1155
#define WHENEVER_NOT_FOUND 1156
#define WHENEVER_SQLERROR 1157
#define WHENEVER_SUCCESS 1158
#define WHENEVER_ERROR 1159
#define START_EXTERN 1160
#define CONTINUE_CONSTRUCT 1161
#define FOUNCONSTR 1162
#define SQLSIDR 1163
#define CREATE_TEMP_TABLE 1164
#define CURRENT_WINDOW_IS 1165
#define FIRST_PAGE_HEADER 1166
#define ORDER_EXTERNAL_BY 1167
#define SCROLL_CURSOR_FOR 1168
#define SCROLL_CURSOR 1169
#define SQL_INTERRUPT_OFF 1170
#define STOP_ALL_EXTERNAL 1171
#define WITH_CHECK_OPTION 1172
#define WITH_GRANT_OPTION 1173
#define SQLSLMNW 1174
#define ADDCONSTUNIQ 1175
#define CONTINUE_DISPLAY 1176
#define CONTINUE_FOREACH 1177
#define OUTPUT_TO_REPORT 1178
#define SQL_INTERRUPT_ON 1179
#define WHERE_CURRENT_OF 1180
#define WITHOUT_DEFAULTS 1181
#define FOCONSTR 1182
#define SCALED_BY 1183
#define CONTINUE_PROMPT 1184
#define PDF_FUNCTION 1185
#define DEFER_INTERRUPT 1186
#define DISPLAY_BY_NAME 1187
#define NOT_NULL_UNIQUE 1188
#define SKIP_TO_TOP 1189
#define TOP_OF_PAGE 1190
#define SKIP_TO 1191
#define SKIP_BY 1192
#define WITHOUT_WAITING 1193
#define BEFCONSTRUCT 1194
#define SQLSLMW 1195
#define AFTCONSTRUCT 1196
#define ALL_PRIVILEGES 1197
#define CLOSE_DATABASE 1198
#define CONTINUE_INPUT 1199
#define CONTINUE_WHILE 1200
#define CREATE_SYNONYM 1201
#define DROP_TABLE 1202
#define EXIT_CONSTRUCT 1203
#define INEXCLUSIVE 1204
#define REPORT_TO_PRINTER 1205
#define REPORT_TO_PIPE 1206
#define RETURN 1207
#define SET_SESSION_TO 1208
#define UPDATESTATS 1209
#define WITHOUT_HEAD 1210
#define CLEARSCR 1211
#define WITH_B_LOG 1212
#define AUTHORIZATION 1213
#define BOTTOM_MARGIN 1214
#define CLOSE_SESSION 1215
#define CONTINUE_CASE 1216
#define CONTINUE_MENU 1217
#define DISPLAY_ARRAY 1218
#define END_SQL 1219
#define DOLLAR 1220
#define END_CONSTRUCT 1221
#define FIELD_TOUCHED 1222
#define FINISH_REPORT 1223
#define INFACC 1224
#define INPUT_NO_WRAP 1225
#define SETPMOFF 1226
#define UNCONSTRAINED 1227
#define PAGE_TRAILER 1228
#define SETPMON 1229
#define BEFGROUP 1230
#define CLOSE_WINDOW 1231
#define COMMENT_LINE 1232
#define CONTINUE_FOR 1233
#define CREATE_DB 1234
#define CREATE_TABLE 1235
#define DEFAULT_NULL 1236
#define DEFAULT_TODAY 1237
#define DEFAULT_USER 1238
#define DELETE_USING 1239
#define DISPLAY_FORM 1240
#define END_FUNCTION 1241
#define EXIT_DISPLAY 1242
#define EXIT_FOREACH 1243
#define EXIT_PROGRAM 1244
#define INFCOLS 1245
#define ON_EVERY_ROW 1246
#define OPEN_SESSION 1247
#define RIGHT_MARGIN 1248
#define SELECT_USING 1249
#define START_REPORT 1250
#define UNLOCK_TABLE 1251
#define UPDATE_USING 1252
#define ACL_BUILTIN 1253
#define AFTGROUP 1254
#define INFIDX 1255
#define INFSTAT 1256
#define LEFT_MARGIN 1257
#define PAGE_HEADER 1258
#define ROLLBACK_W 1259
#define SET_SESSION 1260
#define SQLSEOFF 1261
#define WITH_A_LOG 1262
#define BEFDISP 1263
#define BEFORE_MENU 1264
#define CREATE_VIEW 1265
#define DELETE_FROM 1266
#define END_DISPLAY 1267
#define END_REPORT 1268
#define END_FOREACH 1269
#define END_FOR 1270
#define END_GLOBALS 1271
#define EXIT_PROMPT 1272
#define EXTENT_SIZE 1273
#define FOREIGN_KEY 1274
#define HIDE_OPTION 1275
#define HIDE_WINDOW 1276
#define INSERT_INTO 1277
#define IS_NOT_NULL 1278
#define MOVE_WINDOW 1279
#define NEXT_OPTION 1280
#define NOT_MATCHES 1281
#define ON_LAST_ROW 1282
#define OPEN_WINDOW 1283
#define OPEN_STATUSBOX 1284
#define PAGE_LENGTH 1285
#define PAGE_WIDTH 1286
#define PRIMARY_KEY 1287
#define PROMPT_LINE 1288
#define RECORD_LIKE 1289
#define ROLLFORWARD 1290
#define SHOW_OPTION 1291
#define SHOW_WINDOW 1292
#define SQLSEON 1293
#define TO_DATABASE 1294
#define USE_SESSION 1295
#define WITH_NO_LOG 1296
#define AFTDISP 1297
#define BEFFIELD 1298
#define INSHARE 1299
#define UNLOCKTAB 1300
#define AFTFIELD 1301
#define ATTRIBUTES 1302
#define BEFINP 1303
#define BEGIN_WORK 1304
#define CLEARWIN 1305
#define CLOSE_FORM 1306
#define DEFER_QUIT 1307
#define DESCENDING 1308
#define DROP_INDEX 1309
#define END_PROMPT 1310
#define END_RECORD 1311
#define ERROR_LINE 1312
#define EXIT_INPUT 1313
#define EXIT_WHILE 1314
#define FOR_UPDATE_OF 1315
#define FOR_UPDATE 1316
#define GET_FLDBUF 1317
#define INITIALIZE 1318
#define INPUT_WRAP 1319
#define LOCK_TABLE 1320
#define MSG_LINE 1321
#define NOT_EXISTS 1322
#define ON_ANY_KEY 1323
#define REFERENCES 1324
#define RENCOL 1325
#define SET_CURSOR 1326
#define SMALLFLOAT 1327
#define SQLSUCCESS 1328
#define TOP_MARGIN 1329
#define WITH_ARRAY 1330
#define ACCEPTKEY 1331
#define ACCEPT 1332
#define AFTINP 1333
#define CLEARFORMTODEFAULTS 1334
#define CLEARFORM 1335
#define CLEAR_X_FORM 1336
#define COMMIT_W 1337
#define NEXTPAGE 1338
#define PREVPAGE 1339
#define CTRL_KEY 1340
#define INFTABS 1341
#define NEXTFIELD 1342
#define NEXTFORM 1343
#define RENTAB 1344
#define ASCENDING 1345
#define ASSOCIATE 1346
#define CHAR 1347
#define NCHAR 1348
#define NVARCHAR 1349
#define CONSTRUCT 1350
#define DELIMITER 1351
#define DOWNSHIFT 1352
#define DROP_VIEW 1353
#define END_INPUT 1354
#define END_WHILE 1355
#define EXCLUSIVE 1356
#define EXIT_CASE 1357
#define EXIT_MENU 1358
#define FORM_LINE 1359
#define INTERRUPT 1361
#define INTO_TEMP 1362
#define INVISIBLE 1363
#define IN_MEMORY 1364
#define LINKED_TO 1365
#define LOAD_FROM 1366
#define LOCKTAB 1367
#define MENU_LINE 1368
#define OPEN_FORM 1369
#define OTHERWISE 1370
#define PRECISION 1371
#define PRIOR 1372
#define PROCEDURE 1373
#define REPORT_TO 1374
#define RETURNING 1375
#define UNDERLINE 1376
#define UNLOAD_TO 1377
#define BEFROW 1378
#define UNLOAD_T 1379
#define VARIABLE 1380
#define ABSOLUTE 1381
#define AFTROW 1382
#define BUFFERED 1383
#define CONSTANT 1384
#define CONST 1385
#define DATABASE 1386
#define DATETIME 1387
#define DEFAULTS 1388
#define DISTINCT 1389
#define END_CASE 1390
#define END_MAIN 1391
#define END_MENU 1392
#define END_TYPE 1393
#define EXIT_FOR 1394
#define EXTERNAL 1395
#define FRACTION 1396
#define FUNCTION 1397
#define GROUP_BY 1398
#define INTERVAL 1399
#define KWMESSAGE 1400
#define NOT_LIKE 1401
#define NOT_ILIKE 1402
#define NOT_NULL 1403
#define PASSWORD 1404
#define PREVIOUS 1405
#define READONLY 1406
#define REGISTER 1407
#define RELATIVE 1408
#define RESOURCE 1409
#define SMALLINT 1410
#define VALIDATE 1411
#define WITH_LOG 1412
#define WORDWRAP 1413
#define BY_NAME 1414
#define IN_FILE 1415
#define IS_NULL 1416
#define AVERAGE 1418
#define BETWEEN 1419
#define CAPTION 1420
#define CLIPPED 1421
#define CLOSE_BRACKET 1422
#define COLUMNS 1423
#define CONNECT 1425
#define CURRENT 1426
#define DBYNAME 1427
#define DECIMAL 1428
#define DECLARE 1429
#define DEFAULT 1430
#define DISPLAY 1431
#define ENDCODE 1432
#define EXECUTE 1433
#define FOREACH 1434
#define FOREIGN 1435
#define GLOBALS 1436
#define INFIELD 1437
#define INTEGER 1438
#define KWWINDOW 1439
#define MAGENTA 1440
#define OPTIONS 1442
#define PERCENT 1443
#define PREPARE 1444
#define PROGRAM 1445
#define RECOVER 1446
#define REVERSE 1447
#define SECTION 1448
#define SESSION 1449
#define SYNONYM 1450
#define THRU 1451
#define TRAILER 1452
#define UPSHIFT 1453
#define VARCHAR 1454
#define WAITING 1455
#define CLOSE_SHEV 1456
#define CLOSE_SQUARE 1457
#define KW_FALSE 1459
#define NOT_IN 1460
#define ONKEY 1461
#define OPEN_BRACKET 1462
#define BORDER 1463
#define BOTTOM 1464
#define COLUMN 1465
#define COMMIT 1466
#define CREATE 1467
#define CURSOR 1468
#define DEFINE 1469
#define DELETE 1470
#define DOUBLE 1471
#define END_IF 1472
#define ESCAPE 1473
#define EXISTS 1474
#define EXTEND 1475
#define EXTENT 1476
#define FINISH 1477
#define FORMAT 1478
#define HAVING 1479
#define HEADER 1480
#define INSERT 1481
#define LOCATE 1482
#define MARGIN 1483
#define MEMORY 1484
#define MINUTE 1485
#define MODIFY 1486
#define NORMAL 1487
#define EQUAL_EQUAL 1488
#define OPEN_SHEV 1490
#define OPEN_SQUARE 1491
#define OPTION 1492
#define OUTPUT 1493
#define PROMPT 1494
#define PUBLIC 1495
#define RECORD 1496
#define REPORT 1497
#define REVOKE 1498
#define SCHEMA 1499
#define SCROLL_USING 1500
#define SCROLL 1501
#define SECOND 1502
#define SELECT 1503
#define SERIAL 1504
#define SHARED 1505
#define SPACES 1506
#define UNIQUE 1507
#define UNLOCK 1508
#define UPDATE 1509
#define VALUES 1510
#define YELLOW 1511
#define AFTER 1512
#define KWLINE 1513
#define KW_NULL 1514
#define KW_TRUE 1515
#define SINGLE_KEY 1516
#define ALTER 1517
#define ARRAY 1518
#define ASCII 1519
#define AUDIT 1520
#define BLACK 1521
#define BLINK 1522
#define CHECK 1523
#define CLEAR 1524
#define CLOSE 1525
#define CODE_C 1526
#define COUNT 1527
#define DEFER 1528
#define ERROR 1529
#define EVERY 1530
#define FETCH 1531
#define FIRST 1532
#define FLOAT 1533
#define FLUSH 1534
#define FOUND 1535
#define GRANT 1536
#define GREEN 1537
#define GROUP 1538
#define INDEX 1539
#define KWFORM 1540
#define LABEL 1541
#define LOCAL 1543
#define MONEY 1544
#define MONTH 1545
#define ORDER 1548
#define OUTER 1549
#define PAUSE 1550
#define PRINT_IMAGE 1551
#define PRINT_FILE 1552
#define PRINT 1553
#define RIGHT 1554
#define DOUBLE_COLON 1555
#define SEMICOLON 1556
#define SLEEP 1557
#define TUPLE 1558
#define UNION 1559
#define WHERE 1561
#define WHILE 1562
#define WHITE 1563
#define CCODE 1564
#define ANSI 1565
#define BLUE 1566
#define BOLD 1567
#define BYTE 1568
#define FCALL 1569
#define CASE 1570
#define CYAN 1571
#define DATE 1572
#define DESC 1573
#define KWDOWN 1575
#define TAB 1576
#define DROP 1577
#define ELSE 1578
#define EXEC 1579
#define EXIT 1580
#define FREE 1581
#define FROM 1582
#define GOTO 1583
#define HELP_FILE 1584
#define LANG_FILE 1585
#define HELP 1586
#define HIDE 1587
#define HOUR 1588
#define INTO 1589
#define LAST 1590
#define LEFT 1591
#define LIKE 1592
#define MAIN 1593
#define MENU 1594
#define MODE 1595
#define NEED 1596
#define NEXT 1597
#define NOCR 1598
#define OPEN 1599
#define QUIT 1600
#define REAL 1601
#define ROWS 1602
#define SHOW 1603
#define SIZE 1604
#define SKIP 1605
#define SOME 1606
#define STEP 1607
#define STOP 1608
#define TEMP 1609
#define TEXT 1610
#define THEN 1611
#define USER 1612
#define WAIT 1613
#define WHEN 1614
#define WITH 1615
#define WORK 1616
#define YEAR 1617
#define KW_IS 1619
#define XSET 1620
#define ADD 1621
#define ALL 1622
#define ANY 1624
#define ASC 1625
#define AVG 1626
#define COLON 1627
#define DAY 1629
#define DBA 1630
#define DEC 1631
#define DIM 1632
#define FKEY 1633
#define FOR 1634
#define KEY 1635
#define KWNO 1636
#define LET 1637
#define LOG 1638
#define XMAX 1639
#define XMIN 1640
#define PAD 1644
#define PUT 1645
#define RED 1646
#define ROW 1647
#define RUN 1648
#define SQL 1649
#define SUM 1650
#define TOP 1651
#define USE 1652
#define ATSIGN 1653
#define AS_TIFF 1655
#define AS_GIF 1656
#define AS_PNG 1657
#define AS_JPEG 1658
#define AS 1659
#define AT 1660
#define BY 1661
#define DOT 1662
#define GO 1663
#define IF 1664
#define IN 1665
#define OF 1666
#define ON 1667
#define TO 1669
#define KWUP 1670
#define FONT_NAME 1671
#define FONT_SIZE 1672
#define PAPER_SIZE_IS_LETTER 1673
#define PAPER_SIZE_IS_LEGAL 1674
#define PAPER_SIZE_IS_A5 1675
#define PAPER_SIZE_IS_A4 1676
#define PAPER_SIZE_IS_LETTER_L 1677
#define PAPER_SIZE_IS_LEGAL_L 1678
#define PAPER_SIZE_IS_A5_L 1679
#define PAPER_SIZE_IS_A4_L 1680
#define FORMHANDLER 1681
#define END_FORMHANDLER 1682
#define BEFORE_EVENT 1683
#define BEFORE_OPEN_FORM 1684
#define AFTER_EVENT 1685
#define BEFORE_CLOSE_FORM 1686
#define BEFORE_ANY 1687
#define AFTER_ANY 1688
#define MENUHANDLER 1689
#define END_MENUHANDLER 1690
#define BEFORE_SHOW_MENU 1691
#define DISABLE_PROGRAM 1692
#define DISABLE_ALL 1693
#define BUTTONS 1694
#define CHECK_MENUITEM 1695
#define DISABLE_FORM 1696
#define DISABLE_MENUITEMS 1697
#define DISABLE 1698
#define ENABLE_FORM 1699
#define ENABLE_MENUITEMS 1700
#define ENABLE 1701
#define KWFIELD 1702
#define ICON 1703
#define MESSAGEBOX 1704
#define TO_DEFAULTS 1705
#define UNCHECK_MENUITEM 1706
#define BEFORE 1707
#define INPUT 1708
#define END 1709
#define INT_TO_ID 1710
#define TIMEOUT 1711
#define OFF 1712
#define WITH_1_DIMENSION 1713
#define WITH_2_DIMENSION 1714
#define WITH_3_DIMENSION 1715
#define TILDE 1716
#define ILIKE 1717
#define FGL_ISDYNARR_ALLOCATED 1718
#define FGL_DYNARR_EXTENTSIZE 1719
#define FILLFACTOR 1720
#define END_CLASS 1721
#define KW_CLASS 1722
#define EXTENDS 1723
#define PIPE 1724
#define FORMHANDLER_INPUT 1725




#if ! defined (YYSTYPE) && ! defined (YYSTYPE_IS_DECLARED)
#line 218 "fgl.yacc"
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
/* Line 1252 of yacc.c.  */
#line 1546 "y.tab.h"
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif





