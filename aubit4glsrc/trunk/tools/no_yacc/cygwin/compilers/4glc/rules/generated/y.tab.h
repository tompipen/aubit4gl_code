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
     NAME = 1653,
     UMINUS = 1654,
     COMMA = 1569,
     KW_OR = 1609,
     KW_AND = 1564,
     KW_USING = 1500,
     MATCHES = 1378,
     POWER = 1486,
     LESS_THAN = 1482,
     GREATER_THAN = 1396,
     EQUAL = 1559,
     GREATER_THAN_EQ = 1295,
     LESS_THAN_EQ = 1353,
     NOT_EQUAL = 1427,
     PLUS = 1595,
     MINUS = 1582,
     DIVIDE = 1515,
     MULTIPLY = 1487,
     MOD = 1583,
     COMMAND = 1360,
     NUMBER_VALUE = 1655,
     CHAR_VALUE = 1656,
     INT_VALUE = 1657,
     NAMED_GEN = 1658,
     CLINE = 1659,
     SQLLINE = 1660,
     KW_CSTART = 1661,
     KW_CEND = 1662,
     USER_DTYPE = 1663,
     SQL_TEXT = 1664,
     BEFORE_INSERT = 1000,
     CONCAT_PIPES = 1001,
     BEFORE_DELETE = 1002,
     AFTER_INSERT = 1003,
     AFTER_DELETE = 1004,
     DELETE_ROW_EQUAL_TRUE = 1005,
     INSERT_ROW_EQUAL_TRUE = 1006,
     DELETE_ROW_EQUAL_FALSE = 1007,
     INSERT_ROW_EQUAL_FALSE = 1008,
     CURRENT_ROW_DISPLAY_EQUAL = 1009,
     MAXCOUNT = 1010,
     ALTER_TABLE = 1011,
     WHENEVER_ERROR_CONTINUE = 1012,
     WHENEVER_WARNING_CONTINUE = 1013,
     XSET_MULTIPLY_EQUAL_OPEN_BRACKET = 1014,
     XSET_ident_DOT_MULTIPLY_EQUAL_OPEN_BRACKET = 1015,
     XSET_ident_DOT_MULTIPLY_EQUAL = 1016,
     XSET_MULTIPLY_EQUAL = 1017,
     XSET_OPEN_BRACKET = 1018,
     NEWFORMATSHARED = 1019,
     CREATE_DATABASE = 1020,
     IMPORT_LEGACY_FUNCTION = 1021,
     ADD_CONSTRAINT = 1022,
     DROP_CONSTRAINT = 1023,
     AS_STATIC = 1024,
     NOT_FIELD_TOUCHED = 1025,
     LOCAL_FUNCTION = 1026,
     EVERY_ROW = 1027,
     ELIF = 1028,
     DOUBLE_PRECISION = 1029,
     COUNT_MULTIPLY = 1030,
     WAIT_FOR_KEY = 1031,
     AT_TERMINATION_CALL = 1032,
     TERMINATE_REPORT = 1033,
     TO_MAIN_CAPTION = 1034,
     CLEARSTAT = 1035,
     TO_MENUITEM = 1036,
     ID_TO_INT = 1037,
     TO_STATUSBOX = 1038,
     ASCII_HEIGHT_ALL = 1039,
     ASCII_WIDTH_ALL = 1040,
     IMPORT_DATATYPE = 1041,
     UP_BY = 1042,
     PAGE_TRAILER_SIZE = 1043,
     PAGE_HEADER_SIZE = 1044,
     FIRST_PAGE_HEADER_SIZE = 1045,
     BYTES_USE_AS_IMAGE = 1046,
     BYTES_USE_AS_ASCII = 1047,
     DOWN_BY = 1048,
     CLOSE_STATUSBOX = 1049,
     MODIFY_NEXT_SIZE = 1050,
     LOCK_MODE_PAGE = 1051,
     LOCK_MODE_ROW = 1052,
     TO_PIPE = 1053,
     TO_PRINTER = 1054,
     STATUSBOX = 1055,
     CONNECT_TO = 1056,
     FORMHANDLER_INPUT = 1057,
     UNITS_YEAR = 1058,
     UNITS_MONTH = 1059,
     UNITS_DAY = 1060,
     UNITS_HOUR = 1061,
     UNITS_MINUTE = 1062,
     UNITS_SECOND = 1063,
     NO_NEW_LINES = 1064,
     FIELDTOWIDGET = 1065,
     WITH_HOLD = 1066,
     SHOW_MENU = 1067,
     CWIS = 1068,
     CREATE_IDX = 1069,
     FORM_IS_COMPILED = 1070,
     PDF_REPORT = 1071,
     IMPORT_FUNCTION = 1072,
     PROMPT_MANY = 1073,
     POINTS = 1074,
     MM = 1075,
     INCHES = 1076,
     PREPEND = 1077,
     MEMBER_OF = 1078,
     MEMBER_FUNCTION = 1079,
     APPEND = 1080,
     TEMPLATE = 1081,
     END_TEMPLATE = 1082,
     SQLSICS = 1083,
     CREATE_SCHEMA = 1084,
     SQLSIRR = 1085,
     UPDATESTATS_T = 1086,
     SQLSICR = 1087,
     WHENEVER_SQLSUCCESS = 1088,
     WHENEVER_SQLWARNING = 1089,
     START_EXTERN = 1090,
     WHENEVER_ANY_ERROR = 1091,
     WHENEVER_NOT_FOUND = 1092,
     CONTINUE_CONSTRUCT = 1093,
     FOUNCONSTR = 1094,
     SQLSIDR = 1095,
     WHENEVER_SQLERROR = 1096,
     CREATE_TEMP_TABLE = 1097,
     CURRENT_WINDOW_IS = 1098,
     FIRST_PAGE_HEADER = 1099,
     ORDER_EXTERNAL_BY = 1100,
     SCROLL_CURSOR_FOR = 1101,
     SCROLL_CURSOR = 1102,
     SQL_INTERRUPT_OFF = 1103,
     STOP_ALL_EXTERNAL = 1104,
     WITH_CHECK_OPTION = 1105,
     WITH_GRANT_OPTION = 1106,
     SQLSLMNW = 1107,
     ADDCONSTUNIQ = 1108,
     CONTINUE_DISPLAY = 1109,
     CONTINUE_FOREACH = 1110,
     OUTPUT_TO_REPORT = 1111,
     SQL_INTERRUPT_ON = 1112,
     WHENEVER_SUCCESS = 1113,
     WHENEVER_WARNING = 1114,
     WHERE_CURRENT_OF = 1115,
     WITHOUT_DEFAULTS = 1116,
     FOCONSTR = 1117,
     SCALED_BY = 1118,
     CONTINUE_PROMPT = 1119,
     PDF_FUNCTION = 1120,
     DEFER_INTERRUPT = 1121,
     DISPLAY_BY_NAME = 1122,
     NOT_NULL_UNIQUE = 1123,
     SKIP_TO_TOP = 1124,
     TOP_OF_PAGE = 1125,
     SKIP_TO = 1126,
     SKIP_BY = 1127,
     WITHOUT_WAITING = 1128,
     BEFCONSTRUCT = 1129,
     SQLSLMW = 1130,
     WHENEVER_ERROR = 1131,
     AFTCONSTRUCT = 1132,
     ALL_PRIVILEGES = 1133,
     CLOSE_DATABASE = 1134,
     CONTINUE_INPUT = 1135,
     CONTINUE_WHILE = 1136,
     CREATE_SYNONYM = 1137,
     DROP_TABLE = 1138,
     EXIT_CONSTRUCT = 1139,
     INEXCLUSIVE = 1140,
     REPORT_TO_PRINTER = 1141,
     REPORT_TO_PIPE = 1142,
     SET_SESSION_TO = 1143,
     UPDATESTATS = 1144,
     WITHOUT_HEAD = 1145,
     CLEARSCR = 1146,
     WITH_B_LOG = 1147,
     AUTHORIZATION = 1148,
     BOTTOM_MARGIN = 1149,
     CLOSE_SESSION = 1150,
     CONTINUE_CASE = 1151,
     CONTINUE_MENU = 1152,
     DISPLAY_ARRAY = 1153,
     END_SQL = 1154,
     DOLLAR = 1155,
     END_CONSTRUCT = 1156,
     FIELD_TOUCHED = 1157,
     FINISH_REPORT = 1158,
     INFACC = 1159,
     INPUT_NO_WRAP = 1160,
     LOCKMODEPAGE = 1161,
     SETPMOFF = 1162,
     UNCONSTRAINED = 1163,
     PAGE_TRAILER = 1164,
     SETPMON = 1165,
     BEFGROUP = 1166,
     CLOSE_WINDOW = 1167,
     COMMENT_LINE = 1168,
     CONTINUE_FOR = 1169,
     CREATE_DB = 1170,
     CREATE_TABLE = 1171,
     DEFAULT_NULL = 1172,
     DELETE_USING = 1173,
     DISPLAY_FORM = 1174,
     END_FUNCTION = 1175,
     EXIT_DISPLAY = 1176,
     EXIT_FOREACH = 1177,
     EXIT_PROGRAM = 1178,
     INFCOLS = 1179,
     LOCKMODEROW = 1180,
     ON_EVERY_ROW = 1181,
     OPEN_SESSION = 1182,
     RIGHT_MARGIN = 1183,
     SELECT_USING = 1184,
     START_REPORT = 1185,
     UNLOCK_TABLE = 1186,
     UPDATE_USING = 1187,
     ACL_BUILTIN = 1188,
     AFTGROUP = 1189,
     INFIDX = 1190,
     INFSTAT = 1191,
     LEFT_MARGIN = 1192,
     PAGE_HEADER = 1193,
     ROLLBACK_W = 1194,
     SET_SESSION = 1195,
     SQLSEOFF = 1196,
     WITH_A_LOG = 1197,
     BEFDISP = 1198,
     BEFORE_MENU = 1199,
     CREATE_VIEW = 1200,
     DEFINE_TYPE = 1201,
     DELETE_FROM = 1202,
     END_DISPLAY = 1203,
     END_REPORT = 1204,
     END_FOREACH = 1205,
     END_FOR = 1206,
     END_GLOBALS = 1207,
     EXIT_PROMPT = 1208,
     EXTENT_SIZE = 1209,
     FOREIGN_KEY = 1210,
     HIDE_OPTION = 1211,
     HIDE_WINDOW = 1212,
     INSERT_INTO = 1213,
     IS_NOT_NULL = 1214,
     MOVE_WINDOW = 1215,
     NEXT_OPTION = 1216,
     NOT_MATCHES = 1217,
     ON_LAST_ROW = 1218,
     OPEN_WINDOW = 1219,
     OPEN_STATUSBOX = 1220,
     PAGE_LENGTH = 1221,
     PAGE_WIDTH = 1222,
     PRIMARY_KEY = 1223,
     PROMPT_LINE = 1224,
     RECORD_LIKE = 1225,
     ROLLFORWARD = 1226,
     SETBL = 1227,
     SHOW_OPTION = 1228,
     SHOW_WINDOW = 1229,
     SQLSEON = 1230,
     TO_DATABASE = 1231,
     USE_SESSION = 1232,
     WITH_NO_LOG = 1233,
     AFTDISP = 1234,
     BEFFIELD = 1235,
     INSHARE = 1236,
     UNLOCKTAB = 1237,
     AFTFIELD = 1238,
     ATTRIBUTES = 1239,
     BEFINP = 1240,
     BEGIN_WORK = 1241,
     CLEARWIN = 1242,
     CLOSE_FORM = 1243,
     DEFER_QUIT = 1244,
     DESCENDING = 1245,
     DROP_INDEX = 1246,
     END_PROMPT = 1247,
     END_RECORD = 1248,
     ERROR_LINE = 1249,
     EXIT_INPUT = 1250,
     EXIT_WHILE = 1251,
     FOR_UPDATE_OF = 1252,
     FOR_UPDATE = 1253,
     GET_FLDBUF = 1254,
     INITIALIZE = 1255,
     INPUT_WRAP = 1256,
     LOCK_TABLE = 1257,
     MSG_LINE = 1258,
     NOT_EXISTS = 1259,
     ON_ANY_KEY = 1260,
     REFERENCES = 1261,
     RENCOL = 1262,
     SET_CURSOR = 1263,
     SMALLFLOAT = 1264,
     SQLSUCCESS = 1265,
     TOP_MARGIN = 1266,
     WITH_ARRAY = 1267,
     ACCEPTKEY = 1268,
     ACCEPT = 1269,
     AFTINP = 1270,
     CLEARFORMTODEFAULTS = 1271,
     CLEARFORM = 1272,
     CLEAR_X_FORM = 1273,
     COMMIT_W = 1274,
     NEXTPAGE = 1275,
     PREVPAGE = 1276,
     CTRL_KEY = 1277,
     INFTABS = 1278,
     NEXTFIELD = 1279,
     NEXTFORM = 1280,
     RENTAB = 1281,
     ASCENDING = 1282,
     ASSOCIATE = 1283,
     CHARACTER = 1284,
     CONSTRUCT = 1285,
     DELIMITER = 1286,
     DOWNSHIFT = 1287,
     DROP_VIEW = 1288,
     END_INPUT = 1289,
     END_WHILE = 1290,
     EXCLUSIVE = 1291,
     EXIT_CASE = 1292,
     EXIT_MENU = 1293,
     FORM_LINE = 1294,
     INTERRUPT = 1296,
     INTO_TEMP = 1297,
     INVISIBLE = 1298,
     IN_MEMORY = 1299,
     LINKED_TO = 1300,
     LOAD_FROM = 1301,
     LOCKTAB = 1302,
     MENU_LINE = 1303,
     OPEN_FORM = 1304,
     OTHERWISE = 1305,
     PRECISION = 1306,
     PRIOR = 1307,
     PROCEDURE = 1308,
     REPORT_TO = 1309,
     RETURNING = 1310,
     UNDERLINE = 1311,
     UNLOAD_TO = 1312,
     BEFROW = 1313,
     UNLOAD_T = 1314,
     VARIABLE = 1315,
     ABSOLUTE = 1316,
     AFTROW = 1317,
     BUFFERED = 1318,
     CONSTANT = 1319,
     CONST = 1320,
     CONTINUE = 1321,
     DATABASE = 1322,
     DATETIME = 1323,
     DEFAULTS = 1324,
     DISTINCT = 1325,
     END_CASE = 1326,
     END_MAIN = 1327,
     END_MENU = 1328,
     END_TYPE = 1329,
     EXIT_FOR = 1330,
     EXTERNAL = 1331,
     FRACTION = 1332,
     FUNCTION = 1333,
     GROUP_BY = 1334,
     INTERVAL = 1335,
     KWMESSAGE = 1336,
     NOT_LIKE = 1337,
     NOT_NULL = 1338,
     PASSWORD = 1339,
     PREVIOUS = 1340,
     READONLY = 1341,
     REGISTER = 1342,
     RELATIVE = 1343,
     RESOURCE = 1344,
     SMALLINT = 1345,
     VALIDATE = 1346,
     WHENEVER = 1347,
     WITH_LOG = 1348,
     WORDWRAP = 1349,
     BY_NAME = 1350,
     IN_FILE = 1351,
     IS_NULL = 1352,
     AVERAGE = 1354,
     BETWEEN = 1355,
     CAPTION = 1356,
     CLIPPED = 1357,
     CLOSE_BRACKET = 1358,
     COLUMNS = 1359,
     COMMENT = 1361,
     CONNECT = 1362,
     CURRENT = 1363,
     DBYNAME = 1364,
     DECIMAL = 1365,
     DECLARE = 1366,
     DEFAULT = 1367,
     DISPLAY = 1368,
     ENDCODE = 1369,
     EXECUTE = 1370,
     FOREACH = 1371,
     FOREIGN = 1372,
     GLOBALS = 1373,
     INFIELD = 1374,
     INTEGER = 1375,
     KWWINDOW = 1376,
     MAGENTA = 1377,
     NUMERIC = 1379,
     OPTIONS = 1380,
     PERCENT = 1381,
     PREPARE = 1382,
     PROGRAM = 1383,
     RECOVER = 1384,
     REVERSE = 1385,
     SECTION = 1386,
     SESSION = 1387,
     SYNONYM = 1388,
     THRU = 1389,
     TRAILER = 1390,
     UPSHIFT = 1391,
     VARCHAR = 1392,
     WAITING = 1393,
     CLOSE_SHEV = 1394,
     CLOSE_SQUARE = 1395,
     KW_FALSE = 1397,
     NOT_IN = 1398,
     ONKEY = 1399,
     OPEN_BRACKET = 1400,
     BORDER = 1401,
     BOTTOM = 1402,
     COLUMN = 1403,
     COMMIT = 1404,
     CREATE = 1405,
     CURSOR = 1406,
     DEFINE = 1407,
     DELETE = 1408,
     DOUBLE = 1409,
     END_IF = 1410,
     ESCAPE = 1411,
     EXISTS = 1412,
     EXTEND = 1413,
     EXTENT = 1414,
     FINISH = 1415,
     FORMAT = 1416,
     HAVING = 1417,
     HEADER = 1418,
     INSERT = 1419,
     LOCATE = 1420,
     MARGIN = 1421,
     MEMORY = 1422,
     MINUTE = 1423,
     MODIFY = 1424,
     NORMAL = 1425,
     EQUAL_EQUAL = 1426,
     OPEN_SHEV = 1428,
     OPEN_SQUARE = 1429,
     OPTION = 1430,
     OUTPUT = 1431,
     PROMPT = 1432,
     PUBLIC = 1433,
     RECORD = 1434,
     REPORT = 1435,
     RETURN = 1436,
     REVOKE = 1437,
     SCHEMA = 1438,
     SCROLL_USING = 1439,
     SCROLL = 1440,
     SECOND = 1441,
     SELECT = 1442,
     SERIAL = 1443,
     SETL = 1444,
     SHARED = 1445,
     SPACES = 1446,
     UNIQUE = 1447,
     UNLOCK = 1448,
     UPDATE = 1449,
     VALUES = 1450,
     YELLOW = 1451,
     AFTER = 1452,
     KWLINE = 1453,
     KW_NULL = 1454,
     KW_TRUE = 1455,
     SINGLE_KEY = 1456,
     ALTER = 1457,
     ARRAY = 1458,
     ASCII = 1459,
     AUDIT = 1460,
     BLACK = 1461,
     BLINK = 1462,
     CHECK = 1463,
     CLEAR = 1464,
     CLOSE = 1465,
     CODE_C = 1466,
     COUNT = 1467,
     DEFER = 1468,
     ERROR = 1469,
     EVERY = 1470,
     FETCH = 1471,
     FIRST = 1472,
     FLOAT = 1473,
     FLUSH = 1474,
     FOUND = 1475,
     GRANT = 1476,
     GREEN = 1477,
     GROUP = 1478,
     INDEX = 1479,
     KWFORM = 1480,
     LABEL = 1481,
     LOCAL = 1483,
     MONEY = 1484,
     MONTH = 1485,
     ORDER = 1488,
     OUTER = 1489,
     PAUSE = 1490,
     PRINT_IMAGE = 1491,
     PRINT_FILE = 1492,
     PRINT = 1493,
     RIGHT = 1494,
     DOUBLE_COLON = 1495,
     SEMICOLON = 1496,
     SLEEP = 1497,
     TUPLE = 1498,
     UNION = 1499,
     WHERE = 1501,
     WHILE = 1502,
     WHITE = 1503,
     CCODE = 1504,
     ANSI = 1505,
     BLUE = 1506,
     BOLD = 1507,
     BYTE = 1508,
     FCALL = 1509,
     CASE = 1510,
     CHAR = 1511,
     CYAN = 1512,
     DATE = 1513,
     DESC = 1514,
     DOWN = 1516,
     TAB = 1517,
     DROP = 1518,
     ELSE = 1519,
     EXEC = 1520,
     EXIT = 1521,
     FREE = 1522,
     FROM = 1523,
     GOTO = 1524,
     HELP_FILE = 1525,
     LANG_FILE = 1526,
     HELP = 1527,
     HIDE = 1528,
     HOUR = 1529,
     INTO = 1530,
     LAST = 1531,
     LEFT = 1532,
     LIKE = 1533,
     MAIN = 1534,
     MENU = 1535,
     MODE = 1536,
     NEED = 1537,
     NEXT = 1538,
     NOCR = 1539,
     OPEN = 1540,
     QUIT = 1541,
     REAL = 1542,
     ROWS = 1543,
     SHOW = 1544,
     SIZE = 1545,
     SKIP = 1546,
     SOME = 1547,
     STEP = 1548,
     STOP = 1549,
     TEMP = 1550,
     TEXT = 1551,
     THEN = 1552,
     USER = 1553,
     WAIT = 1554,
     WHEN = 1555,
     WITH = 1556,
     WORK = 1557,
     YEAR = 1558,
     KW_IS = 1560,
     XSET = 1561,
     ADD = 1562,
     ALL = 1563,
     ANY = 1565,
     ASC = 1566,
     AVG = 1567,
     COLON = 1568,
     DAY = 1570,
     DBA = 1571,
     DEC = 1572,
     DIM = 1573,
     FKEY = 1574,
     FOR = 1575,
     KEY = 1576,
     KWNO = 1577,
     LET = 1578,
     LOG = 1579,
     XMAX = 1580,
     XMIN = 1581,
     NOT = 1584,
     PAD = 1585,
     PUT = 1586,
     RED = 1587,
     ROW = 1588,
     RUN = 1589,
     SQL = 1590,
     SUM = 1591,
     TOP = 1592,
     USE = 1593,
     ATSIGN = 1594,
     AS_TIFF = 1596,
     AS_GIF = 1597,
     AS_PNG = 1598,
     AS_JPEG = 1599,
     AS = 1600,
     AT = 1601,
     BY = 1602,
     DOT = 1603,
     GO = 1604,
     IF = 1605,
     IN = 1606,
     OF = 1607,
     ON = 1608,
     TO = 1610,
     UP = 1611,
     FONT_NAME = 1612,
     FONT_SIZE = 1613,
     PAPER_SIZE_IS_LETTER = 1614,
     PAPER_SIZE_IS_LEGAL = 1615,
     PAPER_SIZE_IS_A5 = 1616,
     PAPER_SIZE_IS_A4 = 1617,
     PAPER_SIZE_IS_LETTER_L = 1618,
     PAPER_SIZE_IS_LEGAL_L = 1619,
     PAPER_SIZE_IS_A5_L = 1620,
     PAPER_SIZE_IS_A4_L = 1621,
     FORMHANDLER = 1622,
     END_FORMHANDLER = 1623,
     BEFORE_EVENT = 1624,
     BEFORE_OPEN_FORM = 1625,
     AFTER_EVENT = 1626,
     BEFORE_CLOSE_FORM = 1627,
     BEFORE_ANY = 1628,
     AFTER_ANY = 1629,
     MENUHANDLER = 1630,
     END_MENUHANDLER = 1631,
     BEFORE_SHOW_MENU = 1632,
     DISABLE_PROGRAM = 1633,
     DISABLE_ALL = 1634,
     BUTTONS = 1635,
     CHECK_MENUITEM = 1636,
     DISABLE_FORM = 1637,
     DISABLE_MENUITEMS = 1638,
     DISABLE = 1639,
     ENABLE_FORM = 1640,
     ENABLE_MENUITEMS = 1641,
     ENABLE = 1642,
     KWFIELD = 1643,
     ICON = 1644,
     MESSAGEBOX = 1645,
     TO_DEFAULTS = 1646,
     UNCHECK_MENUITEM = 1647,
     BEFORE = 1648,
     INPUT = 1649,
     END = 1650,
     INT_TO_ID = 1651
   };
#endif
#define NAME 1653
#define UMINUS 1654
#define COMMA 1569
#define KW_OR 1609
#define KW_AND 1564
#define KW_USING 1500
#define MATCHES 1378
#define POWER 1486
#define LESS_THAN 1482
#define GREATER_THAN 1396
#define EQUAL 1559
#define GREATER_THAN_EQ 1295
#define LESS_THAN_EQ 1353
#define NOT_EQUAL 1427
#define PLUS 1595
#define MINUS 1582
#define DIVIDE 1515
#define MULTIPLY 1487
#define MOD 1583
#define COMMAND 1360
#define NUMBER_VALUE 1655
#define CHAR_VALUE 1656
#define INT_VALUE 1657
#define NAMED_GEN 1658
#define CLINE 1659
#define SQLLINE 1660
#define KW_CSTART 1661
#define KW_CEND 1662
#define USER_DTYPE 1663
#define SQL_TEXT 1664
#define BEFORE_INSERT 1000
#define CONCAT_PIPES 1001
#define BEFORE_DELETE 1002
#define AFTER_INSERT 1003
#define AFTER_DELETE 1004
#define DELETE_ROW_EQUAL_TRUE 1005
#define INSERT_ROW_EQUAL_TRUE 1006
#define DELETE_ROW_EQUAL_FALSE 1007
#define INSERT_ROW_EQUAL_FALSE 1008
#define CURRENT_ROW_DISPLAY_EQUAL 1009
#define MAXCOUNT 1010
#define ALTER_TABLE 1011
#define WHENEVER_ERROR_CONTINUE 1012
#define WHENEVER_WARNING_CONTINUE 1013
#define XSET_MULTIPLY_EQUAL_OPEN_BRACKET 1014
#define XSET_ident_DOT_MULTIPLY_EQUAL_OPEN_BRACKET 1015
#define XSET_ident_DOT_MULTIPLY_EQUAL 1016
#define XSET_MULTIPLY_EQUAL 1017
#define XSET_OPEN_BRACKET 1018
#define NEWFORMATSHARED 1019
#define CREATE_DATABASE 1020
#define IMPORT_LEGACY_FUNCTION 1021
#define ADD_CONSTRAINT 1022
#define DROP_CONSTRAINT 1023
#define AS_STATIC 1024
#define NOT_FIELD_TOUCHED 1025
#define LOCAL_FUNCTION 1026
#define EVERY_ROW 1027
#define ELIF 1028
#define DOUBLE_PRECISION 1029
#define COUNT_MULTIPLY 1030
#define WAIT_FOR_KEY 1031
#define AT_TERMINATION_CALL 1032
#define TERMINATE_REPORT 1033
#define TO_MAIN_CAPTION 1034
#define CLEARSTAT 1035
#define TO_MENUITEM 1036
#define ID_TO_INT 1037
#define TO_STATUSBOX 1038
#define ASCII_HEIGHT_ALL 1039
#define ASCII_WIDTH_ALL 1040
#define IMPORT_DATATYPE 1041
#define UP_BY 1042
#define PAGE_TRAILER_SIZE 1043
#define PAGE_HEADER_SIZE 1044
#define FIRST_PAGE_HEADER_SIZE 1045
#define BYTES_USE_AS_IMAGE 1046
#define BYTES_USE_AS_ASCII 1047
#define DOWN_BY 1048
#define CLOSE_STATUSBOX 1049
#define MODIFY_NEXT_SIZE 1050
#define LOCK_MODE_PAGE 1051
#define LOCK_MODE_ROW 1052
#define TO_PIPE 1053
#define TO_PRINTER 1054
#define STATUSBOX 1055
#define CONNECT_TO 1056
#define FORMHANDLER_INPUT 1057
#define UNITS_YEAR 1058
#define UNITS_MONTH 1059
#define UNITS_DAY 1060
#define UNITS_HOUR 1061
#define UNITS_MINUTE 1062
#define UNITS_SECOND 1063
#define NO_NEW_LINES 1064
#define FIELDTOWIDGET 1065
#define WITH_HOLD 1066
#define SHOW_MENU 1067
#define CWIS 1068
#define CREATE_IDX 1069
#define FORM_IS_COMPILED 1070
#define PDF_REPORT 1071
#define IMPORT_FUNCTION 1072
#define PROMPT_MANY 1073
#define POINTS 1074
#define MM 1075
#define INCHES 1076
#define PREPEND 1077
#define MEMBER_OF 1078
#define MEMBER_FUNCTION 1079
#define APPEND 1080
#define TEMPLATE 1081
#define END_TEMPLATE 1082
#define SQLSICS 1083
#define CREATE_SCHEMA 1084
#define SQLSIRR 1085
#define UPDATESTATS_T 1086
#define SQLSICR 1087
#define WHENEVER_SQLSUCCESS 1088
#define WHENEVER_SQLWARNING 1089
#define START_EXTERN 1090
#define WHENEVER_ANY_ERROR 1091
#define WHENEVER_NOT_FOUND 1092
#define CONTINUE_CONSTRUCT 1093
#define FOUNCONSTR 1094
#define SQLSIDR 1095
#define WHENEVER_SQLERROR 1096
#define CREATE_TEMP_TABLE 1097
#define CURRENT_WINDOW_IS 1098
#define FIRST_PAGE_HEADER 1099
#define ORDER_EXTERNAL_BY 1100
#define SCROLL_CURSOR_FOR 1101
#define SCROLL_CURSOR 1102
#define SQL_INTERRUPT_OFF 1103
#define STOP_ALL_EXTERNAL 1104
#define WITH_CHECK_OPTION 1105
#define WITH_GRANT_OPTION 1106
#define SQLSLMNW 1107
#define ADDCONSTUNIQ 1108
#define CONTINUE_DISPLAY 1109
#define CONTINUE_FOREACH 1110
#define OUTPUT_TO_REPORT 1111
#define SQL_INTERRUPT_ON 1112
#define WHENEVER_SUCCESS 1113
#define WHENEVER_WARNING 1114
#define WHERE_CURRENT_OF 1115
#define WITHOUT_DEFAULTS 1116
#define FOCONSTR 1117
#define SCALED_BY 1118
#define CONTINUE_PROMPT 1119
#define PDF_FUNCTION 1120
#define DEFER_INTERRUPT 1121
#define DISPLAY_BY_NAME 1122
#define NOT_NULL_UNIQUE 1123
#define SKIP_TO_TOP 1124
#define TOP_OF_PAGE 1125
#define SKIP_TO 1126
#define SKIP_BY 1127
#define WITHOUT_WAITING 1128
#define BEFCONSTRUCT 1129
#define SQLSLMW 1130
#define WHENEVER_ERROR 1131
#define AFTCONSTRUCT 1132
#define ALL_PRIVILEGES 1133
#define CLOSE_DATABASE 1134
#define CONTINUE_INPUT 1135
#define CONTINUE_WHILE 1136
#define CREATE_SYNONYM 1137
#define DROP_TABLE 1138
#define EXIT_CONSTRUCT 1139
#define INEXCLUSIVE 1140
#define REPORT_TO_PRINTER 1141
#define REPORT_TO_PIPE 1142
#define SET_SESSION_TO 1143
#define UPDATESTATS 1144
#define WITHOUT_HEAD 1145
#define CLEARSCR 1146
#define WITH_B_LOG 1147
#define AUTHORIZATION 1148
#define BOTTOM_MARGIN 1149
#define CLOSE_SESSION 1150
#define CONTINUE_CASE 1151
#define CONTINUE_MENU 1152
#define DISPLAY_ARRAY 1153
#define END_SQL 1154
#define DOLLAR 1155
#define END_CONSTRUCT 1156
#define FIELD_TOUCHED 1157
#define FINISH_REPORT 1158
#define INFACC 1159
#define INPUT_NO_WRAP 1160
#define LOCKMODEPAGE 1161
#define SETPMOFF 1162
#define UNCONSTRAINED 1163
#define PAGE_TRAILER 1164
#define SETPMON 1165
#define BEFGROUP 1166
#define CLOSE_WINDOW 1167
#define COMMENT_LINE 1168
#define CONTINUE_FOR 1169
#define CREATE_DB 1170
#define CREATE_TABLE 1171
#define DEFAULT_NULL 1172
#define DELETE_USING 1173
#define DISPLAY_FORM 1174
#define END_FUNCTION 1175
#define EXIT_DISPLAY 1176
#define EXIT_FOREACH 1177
#define EXIT_PROGRAM 1178
#define INFCOLS 1179
#define LOCKMODEROW 1180
#define ON_EVERY_ROW 1181
#define OPEN_SESSION 1182
#define RIGHT_MARGIN 1183
#define SELECT_USING 1184
#define START_REPORT 1185
#define UNLOCK_TABLE 1186
#define UPDATE_USING 1187
#define ACL_BUILTIN 1188
#define AFTGROUP 1189
#define INFIDX 1190
#define INFSTAT 1191
#define LEFT_MARGIN 1192
#define PAGE_HEADER 1193
#define ROLLBACK_W 1194
#define SET_SESSION 1195
#define SQLSEOFF 1196
#define WITH_A_LOG 1197
#define BEFDISP 1198
#define BEFORE_MENU 1199
#define CREATE_VIEW 1200
#define DEFINE_TYPE 1201
#define DELETE_FROM 1202
#define END_DISPLAY 1203
#define END_REPORT 1204
#define END_FOREACH 1205
#define END_FOR 1206
#define END_GLOBALS 1207
#define EXIT_PROMPT 1208
#define EXTENT_SIZE 1209
#define FOREIGN_KEY 1210
#define HIDE_OPTION 1211
#define HIDE_WINDOW 1212
#define INSERT_INTO 1213
#define IS_NOT_NULL 1214
#define MOVE_WINDOW 1215
#define NEXT_OPTION 1216
#define NOT_MATCHES 1217
#define ON_LAST_ROW 1218
#define OPEN_WINDOW 1219
#define OPEN_STATUSBOX 1220
#define PAGE_LENGTH 1221
#define PAGE_WIDTH 1222
#define PRIMARY_KEY 1223
#define PROMPT_LINE 1224
#define RECORD_LIKE 1225
#define ROLLFORWARD 1226
#define SETBL 1227
#define SHOW_OPTION 1228
#define SHOW_WINDOW 1229
#define SQLSEON 1230
#define TO_DATABASE 1231
#define USE_SESSION 1232
#define WITH_NO_LOG 1233
#define AFTDISP 1234
#define BEFFIELD 1235
#define INSHARE 1236
#define UNLOCKTAB 1237
#define AFTFIELD 1238
#define ATTRIBUTES 1239
#define BEFINP 1240
#define BEGIN_WORK 1241
#define CLEARWIN 1242
#define CLOSE_FORM 1243
#define DEFER_QUIT 1244
#define DESCENDING 1245
#define DROP_INDEX 1246
#define END_PROMPT 1247
#define END_RECORD 1248
#define ERROR_LINE 1249
#define EXIT_INPUT 1250
#define EXIT_WHILE 1251
#define FOR_UPDATE_OF 1252
#define FOR_UPDATE 1253
#define GET_FLDBUF 1254
#define INITIALIZE 1255
#define INPUT_WRAP 1256
#define LOCK_TABLE 1257
#define MSG_LINE 1258
#define NOT_EXISTS 1259
#define ON_ANY_KEY 1260
#define REFERENCES 1261
#define RENCOL 1262
#define SET_CURSOR 1263
#define SMALLFLOAT 1264
#define SQLSUCCESS 1265
#define TOP_MARGIN 1266
#define WITH_ARRAY 1267
#define ACCEPTKEY 1268
#define ACCEPT 1269
#define AFTINP 1270
#define CLEARFORMTODEFAULTS 1271
#define CLEARFORM 1272
#define CLEAR_X_FORM 1273
#define COMMIT_W 1274
#define NEXTPAGE 1275
#define PREVPAGE 1276
#define CTRL_KEY 1277
#define INFTABS 1278
#define NEXTFIELD 1279
#define NEXTFORM 1280
#define RENTAB 1281
#define ASCENDING 1282
#define ASSOCIATE 1283
#define CHARACTER 1284
#define CONSTRUCT 1285
#define DELIMITER 1286
#define DOWNSHIFT 1287
#define DROP_VIEW 1288
#define END_INPUT 1289
#define END_WHILE 1290
#define EXCLUSIVE 1291
#define EXIT_CASE 1292
#define EXIT_MENU 1293
#define FORM_LINE 1294
#define INTERRUPT 1296
#define INTO_TEMP 1297
#define INVISIBLE 1298
#define IN_MEMORY 1299
#define LINKED_TO 1300
#define LOAD_FROM 1301
#define LOCKTAB 1302
#define MENU_LINE 1303
#define OPEN_FORM 1304
#define OTHERWISE 1305
#define PRECISION 1306
#define PRIOR 1307
#define PROCEDURE 1308
#define REPORT_TO 1309
#define RETURNING 1310
#define UNDERLINE 1311
#define UNLOAD_TO 1312
#define BEFROW 1313
#define UNLOAD_T 1314
#define VARIABLE 1315
#define ABSOLUTE 1316
#define AFTROW 1317
#define BUFFERED 1318
#define CONSTANT 1319
#define CONST 1320
#define CONTINUE 1321
#define DATABASE 1322
#define DATETIME 1323
#define DEFAULTS 1324
#define DISTINCT 1325
#define END_CASE 1326
#define END_MAIN 1327
#define END_MENU 1328
#define END_TYPE 1329
#define EXIT_FOR 1330
#define EXTERNAL 1331
#define FRACTION 1332
#define FUNCTION 1333
#define GROUP_BY 1334
#define INTERVAL 1335
#define KWMESSAGE 1336
#define NOT_LIKE 1337
#define NOT_NULL 1338
#define PASSWORD 1339
#define PREVIOUS 1340
#define READONLY 1341
#define REGISTER 1342
#define RELATIVE 1343
#define RESOURCE 1344
#define SMALLINT 1345
#define VALIDATE 1346
#define WHENEVER 1347
#define WITH_LOG 1348
#define WORDWRAP 1349
#define BY_NAME 1350
#define IN_FILE 1351
#define IS_NULL 1352
#define AVERAGE 1354
#define BETWEEN 1355
#define CAPTION 1356
#define CLIPPED 1357
#define CLOSE_BRACKET 1358
#define COLUMNS 1359
#define COMMENT 1361
#define CONNECT 1362
#define CURRENT 1363
#define DBYNAME 1364
#define DECIMAL 1365
#define DECLARE 1366
#define DEFAULT 1367
#define DISPLAY 1368
#define ENDCODE 1369
#define EXECUTE 1370
#define FOREACH 1371
#define FOREIGN 1372
#define GLOBALS 1373
#define INFIELD 1374
#define INTEGER 1375
#define KWWINDOW 1376
#define MAGENTA 1377
#define NUMERIC 1379
#define OPTIONS 1380
#define PERCENT 1381
#define PREPARE 1382
#define PROGRAM 1383
#define RECOVER 1384
#define REVERSE 1385
#define SECTION 1386
#define SESSION 1387
#define SYNONYM 1388
#define THRU 1389
#define TRAILER 1390
#define UPSHIFT 1391
#define VARCHAR 1392
#define WAITING 1393
#define CLOSE_SHEV 1394
#define CLOSE_SQUARE 1395
#define KW_FALSE 1397
#define NOT_IN 1398
#define ONKEY 1399
#define OPEN_BRACKET 1400
#define BORDER 1401
#define BOTTOM 1402
#define COLUMN 1403
#define COMMIT 1404
#define CREATE 1405
#define CURSOR 1406
#define DEFINE 1407
#define DELETE 1408
#define DOUBLE 1409
#define END_IF 1410
#define ESCAPE 1411
#define EXISTS 1412
#define EXTEND 1413
#define EXTENT 1414
#define FINISH 1415
#define FORMAT 1416
#define HAVING 1417
#define HEADER 1418
#define INSERT 1419
#define LOCATE 1420
#define MARGIN 1421
#define MEMORY 1422
#define MINUTE 1423
#define MODIFY 1424
#define NORMAL 1425
#define EQUAL_EQUAL 1426
#define OPEN_SHEV 1428
#define OPEN_SQUARE 1429
#define OPTION 1430
#define OUTPUT 1431
#define PROMPT 1432
#define PUBLIC 1433
#define RECORD 1434
#define REPORT 1435
#define RETURN 1436
#define REVOKE 1437
#define SCHEMA 1438
#define SCROLL_USING 1439
#define SCROLL 1440
#define SECOND 1441
#define SELECT 1442
#define SERIAL 1443
#define SETL 1444
#define SHARED 1445
#define SPACES 1446
#define UNIQUE 1447
#define UNLOCK 1448
#define UPDATE 1449
#define VALUES 1450
#define YELLOW 1451
#define AFTER 1452
#define KWLINE 1453
#define KW_NULL 1454
#define KW_TRUE 1455
#define SINGLE_KEY 1456
#define ALTER 1457
#define ARRAY 1458
#define ASCII 1459
#define AUDIT 1460
#define BLACK 1461
#define BLINK 1462
#define CHECK 1463
#define CLEAR 1464
#define CLOSE 1465
#define CODE_C 1466
#define COUNT 1467
#define DEFER 1468
#define ERROR 1469
#define EVERY 1470
#define FETCH 1471
#define FIRST 1472
#define FLOAT 1473
#define FLUSH 1474
#define FOUND 1475
#define GRANT 1476
#define GREEN 1477
#define GROUP 1478
#define INDEX 1479
#define KWFORM 1480
#define LABEL 1481
#define LOCAL 1483
#define MONEY 1484
#define MONTH 1485
#define ORDER 1488
#define OUTER 1489
#define PAUSE 1490
#define PRINT_IMAGE 1491
#define PRINT_FILE 1492
#define PRINT 1493
#define RIGHT 1494
#define DOUBLE_COLON 1495
#define SEMICOLON 1496
#define SLEEP 1497
#define TUPLE 1498
#define UNION 1499
#define WHERE 1501
#define WHILE 1502
#define WHITE 1503
#define CCODE 1504
#define ANSI 1505
#define BLUE 1506
#define BOLD 1507
#define BYTE 1508
#define FCALL 1509
#define CASE 1510
#define CHAR 1511
#define CYAN 1512
#define DATE 1513
#define DESC 1514
#define DOWN 1516
#define TAB 1517
#define DROP 1518
#define ELSE 1519
#define EXEC 1520
#define EXIT 1521
#define FREE 1522
#define FROM 1523
#define GOTO 1524
#define HELP_FILE 1525
#define LANG_FILE 1526
#define HELP 1527
#define HIDE 1528
#define HOUR 1529
#define INTO 1530
#define LAST 1531
#define LEFT 1532
#define LIKE 1533
#define MAIN 1534
#define MENU 1535
#define MODE 1536
#define NEED 1537
#define NEXT 1538
#define NOCR 1539
#define OPEN 1540
#define QUIT 1541
#define REAL 1542
#define ROWS 1543
#define SHOW 1544
#define SIZE 1545
#define SKIP 1546
#define SOME 1547
#define STEP 1548
#define STOP 1549
#define TEMP 1550
#define TEXT 1551
#define THEN 1552
#define USER 1553
#define WAIT 1554
#define WHEN 1555
#define WITH 1556
#define WORK 1557
#define YEAR 1558
#define KW_IS 1560
#define XSET 1561
#define ADD 1562
#define ALL 1563
#define ANY 1565
#define ASC 1566
#define AVG 1567
#define COLON 1568
#define DAY 1570
#define DBA 1571
#define DEC 1572
#define DIM 1573
#define FKEY 1574
#define FOR 1575
#define KEY 1576
#define KWNO 1577
#define LET 1578
#define LOG 1579
#define XMAX 1580
#define XMIN 1581
#define NOT 1584
#define PAD 1585
#define PUT 1586
#define RED 1587
#define ROW 1588
#define RUN 1589
#define SQL 1590
#define SUM 1591
#define TOP 1592
#define USE 1593
#define ATSIGN 1594
#define AS_TIFF 1596
#define AS_GIF 1597
#define AS_PNG 1598
#define AS_JPEG 1599
#define AS 1600
#define AT 1601
#define BY 1602
#define DOT 1603
#define GO 1604
#define IF 1605
#define IN 1606
#define OF 1607
#define ON 1608
#define TO 1610
#define UP 1611
#define FONT_NAME 1612
#define FONT_SIZE 1613
#define PAPER_SIZE_IS_LETTER 1614
#define PAPER_SIZE_IS_LEGAL 1615
#define PAPER_SIZE_IS_A5 1616
#define PAPER_SIZE_IS_A4 1617
#define PAPER_SIZE_IS_LETTER_L 1618
#define PAPER_SIZE_IS_LEGAL_L 1619
#define PAPER_SIZE_IS_A5_L 1620
#define PAPER_SIZE_IS_A4_L 1621
#define FORMHANDLER 1622
#define END_FORMHANDLER 1623
#define BEFORE_EVENT 1624
#define BEFORE_OPEN_FORM 1625
#define AFTER_EVENT 1626
#define BEFORE_CLOSE_FORM 1627
#define BEFORE_ANY 1628
#define AFTER_ANY 1629
#define MENUHANDLER 1630
#define END_MENUHANDLER 1631
#define BEFORE_SHOW_MENU 1632
#define DISABLE_PROGRAM 1633
#define DISABLE_ALL 1634
#define BUTTONS 1635
#define CHECK_MENUITEM 1636
#define DISABLE_FORM 1637
#define DISABLE_MENUITEMS 1638
#define DISABLE 1639
#define ENABLE_FORM 1640
#define ENABLE_MENUITEMS 1641
#define ENABLE 1642
#define KWFIELD 1643
#define ICON 1644
#define MESSAGEBOX 1645
#define TO_DEFAULTS 1646
#define UNCHECK_MENUITEM 1647
#define BEFORE 1648
#define INPUT 1649
#define END 1650
#define INT_TO_ID 1651




#if ! defined (YYSTYPE) && ! defined (YYSTYPE_IS_DECLARED)
#line 202 "fgl.yacc"
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
/* Line 1248 of yacc.c.  */
#line 1388 "y.tab.h"
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif





