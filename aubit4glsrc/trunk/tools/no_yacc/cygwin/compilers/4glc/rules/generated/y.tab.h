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
     NAME = 1641,
     UMINUS = 1642,
     COMMA = 1557,
     KW_OR = 1597,
     KW_AND = 1552,
     KW_USING = 1488,
     MATCHES = 1366,
     POWER = 1474,
     LESS_THAN = 1470,
     GREATER_THAN = 1384,
     EQUAL = 1547,
     GREATER_THAN_EQ = 1283,
     LESS_THAN_EQ = 1341,
     NOT_EQUAL = 1415,
     PLUS = 1583,
     MINUS = 1570,
     DIVIDE = 1503,
     MULTIPLY = 1475,
     MOD = 1571,
     COMMAND = 1348,
     NUMBER_VALUE = 1643,
     CHAR_VALUE = 1644,
     INT_VALUE = 1645,
     NAMED_GEN = 1646,
     CLINE = 1647,
     SQLLINE = 1648,
     KW_CSTART = 1649,
     KW_CEND = 1650,
     USER_DTYPE = 1651,
     SQL_TEXT = 1652,
     ALTER_TABLE = 1000,
     XSET_MULTIPLY_EQUAL_OPEN_BRACKET = 1001,
     XSET_ident_DOT_MULTIPLY_EQUAL_OPEN_BRACKET = 1002,
     XSET_ident_DOT_MULTIPLY_EQUAL = 1003,
     XSET_MULTIPLY_EQUAL = 1004,
     XSET_OPEN_BRACKET = 1005,
     NEWFORMATSHARED = 1006,
     CREATE_DATABASE = 1007,
     IMPORT_LEGACY_FUNCTION = 1008,
     ADD_CONSTRAINT = 1009,
     DROP_CONSTRAINT = 1010,
     AS_STATIC = 1011,
     NOT_FIELD_TOUCHED = 1012,
     LOCAL_FUNCTION = 1013,
     EVERY_ROW = 1014,
     ELIF = 1015,
     DOUBLE_PRECISION = 1016,
     COUNT_MULTIPLY = 1017,
     WAIT_FOR_KEY = 1018,
     AT_TERMINATION_CALL = 1019,
     TERMINATE_REPORT = 1020,
     TO_MAIN_CAPTION = 1021,
     CLEARSTAT = 1022,
     TO_MENUITEM = 1023,
     ID_TO_INT = 1024,
     TO_STATUSBOX = 1025,
     ASCII_HEIGHT_ALL = 1026,
     ASCII_WIDTH_ALL = 1027,
     IMPORT_DATATYPE = 1028,
     UP_BY = 1029,
     PAGE_TRAILER_SIZE = 1030,
     PAGE_HEADER_SIZE = 1031,
     FIRST_PAGE_HEADER_SIZE = 1032,
     BYTES_USE_AS_IMAGE = 1033,
     BYTES_USE_AS_ASCII = 1034,
     DOWN_BY = 1035,
     CLOSE_STATUSBOX = 1036,
     MODIFY_NEXT_SIZE = 1037,
     LOCK_MODE_PAGE = 1038,
     LOCK_MODE_ROW = 1039,
     TO_PIPE = 1040,
     TO_PRINTER = 1041,
     STATUSBOX = 1042,
     CONNECT_TO = 1043,
     FORMHANDLER_INPUT = 1044,
     UNITS_YEAR = 1045,
     UNITS_MONTH = 1046,
     UNITS_DAY = 1047,
     UNITS_HOUR = 1048,
     UNITS_MINUTE = 1049,
     UNITS_SECOND = 1050,
     NO_NEW_LINES = 1051,
     FIELDTOWIDGET = 1052,
     WITH_HOLD = 1053,
     SHOW_MENU = 1054,
     CWIS = 1055,
     CREATE_IDX = 1056,
     FORM_IS_COMPILED = 1057,
     PDF_REPORT = 1058,
     IMPORT_FUNCTION = 1059,
     PROMPT_MANY = 1060,
     POINTS = 1061,
     MM = 1062,
     INCHES = 1063,
     PREPEND = 1064,
     MEMBER_OF = 1065,
     MEMBER_FUNCTION = 1066,
     APPEND = 1067,
     TEMPLATE = 1068,
     END_TEMPLATE = 1069,
     SQLSICS = 1070,
     CREATE_SCHEMA = 1071,
     SQLSIRR = 1072,
     UPDATESTATS_T = 1073,
     SQLSICR = 1074,
     WHENEVER_SQLSUCCESS = 1075,
     WHENEVER_SQLWARNING = 1076,
     START_EXTERN = 1077,
     WHENEVER_ANY_ERROR = 1078,
     WHENEVER_NOT_FOUND = 1079,
     CONTINUE_CONSTRUCT = 1080,
     FOUNCONSTR = 1081,
     SQLSIDR = 1082,
     WHENEVER_SQLERROR = 1083,
     CREATE_TEMP_TABLE = 1084,
     CURRENT_WINDOW_IS = 1085,
     FIRST_PAGE_HEADER = 1086,
     ORDER_EXTERNAL_BY = 1087,
     SCROLL_CURSOR_FOR = 1088,
     SCROLL_CURSOR = 1089,
     SQL_INTERRUPT_OFF = 1090,
     STOP_ALL_EXTERNAL = 1091,
     WITH_CHECK_OPTION = 1092,
     WITH_GRANT_OPTION = 1093,
     SQLSLMNW = 1094,
     ADDCONSTUNIQ = 1095,
     CONTINUE_DISPLAY = 1096,
     CONTINUE_FOREACH = 1097,
     OUTPUT_TO_REPORT = 1098,
     SQL_INTERRUPT_ON = 1099,
     WHENEVER_SUCCESS = 1100,
     WHENEVER_WARNING = 1101,
     WHERE_CURRENT_OF = 1102,
     WITHOUT_DEFAULTS = 1103,
     FOCONSTR = 1104,
     SCALED_BY = 1105,
     CONTINUE_PROMPT = 1106,
     PDF_FUNCTION = 1107,
     DEFER_INTERRUPT = 1108,
     DISPLAY_BY_NAME = 1109,
     NOT_NULL_UNIQUE = 1110,
     SKIP_TO_TOP = 1111,
     TOP_OF_PAGE = 1112,
     SKIP_TO = 1113,
     SKIP_BY = 1114,
     WITHOUT_WAITING = 1115,
     BEFCONSTRUCT = 1116,
     SQLSLMW = 1117,
     WHENEVER_ERROR_CONTINUE = 1118,
     WHENEVER_ERROR = 1119,
     AFTCONSTRUCT = 1120,
     ALL_PRIVILEGES = 1121,
     CLOSE_DATABASE = 1122,
     CONTINUE_INPUT = 1123,
     CONTINUE_WHILE = 1124,
     CREATE_SYNONYM = 1125,
     DROP_TABLE = 1126,
     EXIT_CONSTRUCT = 1127,
     INEXCLUSIVE = 1128,
     REPORT_TO_PRINTER = 1129,
     REPORT_TO_PIPE = 1130,
     SET_SESSION_TO = 1131,
     UPDATESTATS = 1132,
     WITHOUT_HEAD = 1133,
     CLEARSCR = 1134,
     WITH_B_LOG = 1135,
     AUTHORIZATION = 1136,
     BOTTOM_MARGIN = 1137,
     CLOSE_SESSION = 1138,
     CONTINUE_CASE = 1139,
     CONTINUE_MENU = 1140,
     DISPLAY_ARRAY = 1141,
     END_SQL = 1142,
     DOLLAR = 1143,
     END_CONSTRUCT = 1144,
     FIELD_TOUCHED = 1145,
     FINISH_REPORT = 1146,
     INFACC = 1147,
     INPUT_NO_WRAP = 1148,
     LOCKMODEPAGE = 1149,
     SETPMOFF = 1150,
     UNCONSTRAINED = 1151,
     PAGE_TRAILER = 1152,
     SETPMON = 1153,
     BEFGROUP = 1154,
     CLOSE_WINDOW = 1155,
     COMMENT_LINE = 1156,
     CONTINUE_FOR = 1157,
     CREATE_DB = 1158,
     CREATE_TABLE = 1159,
     DEFAULT_NULL = 1160,
     DELETE_USING = 1161,
     DISPLAY_FORM = 1162,
     END_FUNCTION = 1163,
     EXIT_DISPLAY = 1164,
     EXIT_FOREACH = 1165,
     EXIT_PROGRAM = 1166,
     INFCOLS = 1167,
     LOCKMODEROW = 1168,
     ON_EVERY_ROW = 1169,
     OPEN_SESSION = 1170,
     RIGHT_MARGIN = 1171,
     SELECT_USING = 1172,
     START_REPORT = 1173,
     UNLOCK_TABLE = 1174,
     UPDATE_USING = 1175,
     ACL_BUILTIN = 1176,
     AFTGROUP = 1177,
     INFIDX = 1178,
     INFSTAT = 1179,
     LEFT_MARGIN = 1180,
     PAGE_HEADER = 1181,
     ROLLBACK_W = 1182,
     SET_SESSION = 1183,
     SQLSEOFF = 1184,
     WITH_A_LOG = 1185,
     BEFDISP = 1186,
     BEFORE_MENU = 1187,
     CREATE_VIEW = 1188,
     DEFINE_TYPE = 1189,
     DELETE_FROM = 1190,
     END_DISPLAY = 1191,
     END_REPORT = 1192,
     END_FOREACH = 1193,
     END_FOR = 1194,
     END_GLOBALS = 1195,
     EXIT_PROMPT = 1196,
     EXTENT_SIZE = 1197,
     FOREIGN_KEY = 1198,
     HIDE_OPTION = 1199,
     HIDE_WINDOW = 1200,
     INSERT_INTO = 1201,
     IS_NOT_NULL = 1202,
     MOVE_WINDOW = 1203,
     NEXT_OPTION = 1204,
     NOT_MATCHES = 1205,
     ON_LAST_ROW = 1206,
     OPEN_WINDOW = 1207,
     OPEN_STATUSBOX = 1208,
     PAGE_LENGTH = 1209,
     PAGE_WIDTH = 1210,
     PRIMARY_KEY = 1211,
     PROMPT_LINE = 1212,
     RECORD_LIKE = 1213,
     ROLLFORWARD = 1214,
     SETBL = 1215,
     SHOW_OPTION = 1216,
     SHOW_WINDOW = 1217,
     SQLSEON = 1218,
     TO_DATABASE = 1219,
     USE_SESSION = 1220,
     WITH_NO_LOG = 1221,
     AFTDISP = 1222,
     BEFFIELD = 1223,
     INSHARE = 1224,
     UNLOCKTAB = 1225,
     AFTFIELD = 1226,
     ATTRIBUTES = 1227,
     BEFINP = 1228,
     BEGIN_WORK = 1229,
     CLEARWIN = 1230,
     CLOSE_FORM = 1231,
     DEFER_QUIT = 1232,
     DESCENDING = 1233,
     DROP_INDEX = 1234,
     END_PROMPT = 1235,
     END_RECORD = 1236,
     ERROR_LINE = 1237,
     EXIT_INPUT = 1238,
     EXIT_WHILE = 1239,
     FOR_UPDATE_OF = 1240,
     FOR_UPDATE = 1241,
     GET_FLDBUF = 1242,
     INITIALIZE = 1243,
     INPUT_WRAP = 1244,
     LOCK_TABLE = 1245,
     MSG_LINE = 1246,
     NOT_EXISTS = 1247,
     ON_ANY_KEY = 1248,
     REFERENCES = 1249,
     RENCOL = 1250,
     SET_CURSOR = 1251,
     SMALLFLOAT = 1252,
     SQLSUCCESS = 1253,
     TOP_MARGIN = 1254,
     WITH_ARRAY = 1255,
     ACCEPTKEY = 1256,
     ACCEPT = 1257,
     AFTINP = 1258,
     CLEARFORMTODEFAULTS = 1259,
     CLEARFORM = 1260,
     CLEAR_X_FORM = 1261,
     COMMIT_W = 1262,
     NEXTPAGE = 1263,
     PREVPAGE = 1264,
     CTRL_KEY = 1265,
     INFTABS = 1266,
     NEXTFIELD = 1267,
     NEXTFORM = 1268,
     RENTAB = 1269,
     ASCENDING = 1270,
     ASSOCIATE = 1271,
     CHARACTER = 1272,
     CONSTRUCT = 1273,
     DELIMITER = 1274,
     DOWNSHIFT = 1275,
     DROP_VIEW = 1276,
     END_INPUT = 1277,
     END_WHILE = 1278,
     EXCLUSIVE = 1279,
     EXIT_CASE = 1280,
     EXIT_MENU = 1281,
     FORM_LINE = 1282,
     INTERRUPT = 1284,
     INTO_TEMP = 1285,
     INVISIBLE = 1286,
     IN_MEMORY = 1287,
     LINKED_TO = 1288,
     LOAD_FROM = 1289,
     LOCKTAB = 1290,
     MENU_LINE = 1291,
     OPEN_FORM = 1292,
     OTHERWISE = 1293,
     PRECISION = 1294,
     PRIOR = 1295,
     PROCEDURE = 1296,
     REPORT_TO = 1297,
     RETURNING = 1298,
     UNDERLINE = 1299,
     UNLOAD_TO = 1300,
     BEFROW = 1301,
     UNLOAD_T = 1302,
     VARIABLE = 1303,
     ABSOLUTE = 1304,
     AFTROW = 1305,
     BUFFERED = 1306,
     CONSTANT = 1307,
     CONST = 1308,
     CONTINUE = 1309,
     DATABASE = 1310,
     DATETIME = 1311,
     DEFAULTS = 1312,
     DISTINCT = 1313,
     END_CASE = 1314,
     END_MAIN = 1315,
     END_MENU = 1316,
     END_TYPE = 1317,
     EXIT_FOR = 1318,
     EXTERNAL = 1319,
     FRACTION = 1320,
     FUNCTION = 1321,
     GROUP_BY = 1322,
     INTERVAL = 1323,
     KWMESSAGE = 1324,
     NOT_LIKE = 1325,
     NOT_NULL = 1326,
     PASSWORD = 1327,
     PREVIOUS = 1328,
     READONLY = 1329,
     REGISTER = 1330,
     RELATIVE = 1331,
     RESOURCE = 1332,
     SMALLINT = 1333,
     VALIDATE = 1334,
     WHENEVER = 1335,
     WITH_LOG = 1336,
     WORDWRAP = 1337,
     BY_NAME = 1338,
     IN_FILE = 1339,
     IS_NULL = 1340,
     AVERAGE = 1342,
     BETWEEN = 1343,
     CAPTION = 1344,
     CLIPPED = 1345,
     CLOSE_BRACKET = 1346,
     COLUMNS = 1347,
     COMMENT = 1349,
     CONNECT = 1350,
     CURRENT = 1351,
     DBYNAME = 1352,
     DECIMAL = 1353,
     DECLARE = 1354,
     DEFAULT = 1355,
     DISPLAY = 1356,
     ENDCODE = 1357,
     EXECUTE = 1358,
     FOREACH = 1359,
     FOREIGN = 1360,
     GLOBALS = 1361,
     INFIELD = 1362,
     INTEGER = 1363,
     KWWINDOW = 1364,
     MAGENTA = 1365,
     NUMERIC = 1367,
     OPTIONS = 1368,
     PERCENT = 1369,
     PREPARE = 1370,
     PROGRAM = 1371,
     RECOVER = 1372,
     REVERSE = 1373,
     SECTION = 1374,
     SESSION = 1375,
     SYNONYM = 1376,
     THRU = 1377,
     TRAILER = 1378,
     UPSHIFT = 1379,
     VARCHAR = 1380,
     WAITING = 1381,
     CLOSE_SHEV = 1382,
     CLOSE_SQUARE = 1383,
     KW_FALSE = 1385,
     NOT_IN = 1386,
     ONKEY = 1387,
     OPEN_BRACKET = 1388,
     BORDER = 1389,
     BOTTOM = 1390,
     COLUMN = 1391,
     COMMIT = 1392,
     CREATE = 1393,
     CURSOR = 1394,
     DEFINE = 1395,
     DELETE = 1396,
     DOUBLE = 1397,
     END_IF = 1398,
     ESCAPE = 1399,
     EXISTS = 1400,
     EXTEND = 1401,
     EXTENT = 1402,
     FINISH = 1403,
     FORMAT = 1404,
     HAVING = 1405,
     HEADER = 1406,
     INSERT = 1407,
     LOCATE = 1408,
     MARGIN = 1409,
     MEMORY = 1410,
     MINUTE = 1411,
     MODIFY = 1412,
     NORMAL = 1413,
     EQUAL_EQUAL = 1414,
     OPEN_SHEV = 1416,
     OPEN_SQUARE = 1417,
     OPTION = 1418,
     OUTPUT = 1419,
     PROMPT = 1420,
     PUBLIC = 1421,
     RECORD = 1422,
     REPORT = 1423,
     RETURN = 1424,
     REVOKE = 1425,
     SCHEMA = 1426,
     SCROLL_USING = 1427,
     SCROLL = 1428,
     SECOND = 1429,
     SELECT = 1430,
     SERIAL = 1431,
     SETL = 1432,
     SHARED = 1433,
     SPACES = 1434,
     UNIQUE = 1435,
     UNLOCK = 1436,
     UPDATE = 1437,
     VALUES = 1438,
     YELLOW = 1439,
     AFTER = 1440,
     KWLINE = 1441,
     KW_NULL = 1442,
     KW_TRUE = 1443,
     SINGLE_KEY = 1444,
     ALTER = 1445,
     ARRAY = 1446,
     ASCII = 1447,
     AUDIT = 1448,
     BLACK = 1449,
     BLINK = 1450,
     CHECK = 1451,
     CLEAR = 1452,
     CLOSE = 1453,
     CODE_C = 1454,
     COUNT = 1455,
     DEFER = 1456,
     ERROR = 1457,
     EVERY = 1458,
     FETCH = 1459,
     FIRST = 1460,
     FLOAT = 1461,
     FLUSH = 1462,
     FOUND = 1463,
     GRANT = 1464,
     GREEN = 1465,
     GROUP = 1466,
     INDEX = 1467,
     KWFORM = 1468,
     LABEL = 1469,
     LOCAL = 1471,
     MONEY = 1472,
     MONTH = 1473,
     ORDER = 1476,
     OUTER = 1477,
     PAUSE = 1478,
     PRINT_IMAGE = 1479,
     PRINT_FILE = 1480,
     PRINT = 1481,
     RIGHT = 1482,
     DOUBLE_COLON = 1483,
     SEMICOLON = 1484,
     SLEEP = 1485,
     TUPLE = 1486,
     UNION = 1487,
     WHERE = 1489,
     WHILE = 1490,
     WHITE = 1491,
     CCODE = 1492,
     ANSI = 1493,
     BLUE = 1494,
     BOLD = 1495,
     BYTE = 1496,
     FCALL = 1497,
     CASE = 1498,
     CHAR = 1499,
     CYAN = 1500,
     DATE = 1501,
     DESC = 1502,
     DOWN = 1504,
     TAB = 1505,
     DROP = 1506,
     ELSE = 1507,
     EXEC = 1508,
     EXIT = 1509,
     FREE = 1510,
     FROM = 1511,
     GOTO = 1512,
     HELP_FILE = 1513,
     LANG_FILE = 1514,
     HELP = 1515,
     HIDE = 1516,
     HOUR = 1517,
     INTO = 1518,
     LAST = 1519,
     LEFT = 1520,
     LIKE = 1521,
     MAIN = 1522,
     MENU = 1523,
     MODE = 1524,
     NEED = 1525,
     NEXT = 1526,
     NOCR = 1527,
     OPEN = 1528,
     QUIT = 1529,
     REAL = 1530,
     ROWS = 1531,
     SHOW = 1532,
     SIZE = 1533,
     SKIP = 1534,
     SOME = 1535,
     STEP = 1536,
     STOP = 1537,
     TEMP = 1538,
     TEXT = 1539,
     THEN = 1540,
     USER = 1541,
     WAIT = 1542,
     WHEN = 1543,
     WITH = 1544,
     WORK = 1545,
     YEAR = 1546,
     KW_IS = 1548,
     XSET = 1549,
     ADD = 1550,
     ALL = 1551,
     ANY = 1553,
     ASC = 1554,
     AVG = 1555,
     COLON = 1556,
     DAY = 1558,
     DBA = 1559,
     DEC = 1560,
     DIM = 1561,
     FKEY = 1562,
     FOR = 1563,
     KEY = 1564,
     KWNO = 1565,
     LET = 1566,
     LOG = 1567,
     XMAX = 1568,
     XMIN = 1569,
     NOT = 1572,
     PAD = 1573,
     PUT = 1574,
     RED = 1575,
     ROW = 1576,
     RUN = 1577,
     SQL = 1578,
     SUM = 1579,
     TOP = 1580,
     USE = 1581,
     ATSIGN = 1582,
     AS_TIFF = 1584,
     AS_GIF = 1585,
     AS_PNG = 1586,
     AS_JPEG = 1587,
     AS = 1588,
     AT = 1589,
     BY = 1590,
     DOT = 1591,
     GO = 1592,
     IF = 1593,
     IN = 1594,
     OF = 1595,
     ON = 1596,
     TO = 1598,
     UP = 1599,
     FONT_NAME = 1600,
     FONT_SIZE = 1601,
     PAPER_SIZE_IS_LETTER = 1602,
     PAPER_SIZE_IS_LEGAL = 1603,
     PAPER_SIZE_IS_A5 = 1604,
     PAPER_SIZE_IS_A4 = 1605,
     PAPER_SIZE_IS_LETTER_L = 1606,
     PAPER_SIZE_IS_LEGAL_L = 1607,
     PAPER_SIZE_IS_A5_L = 1608,
     PAPER_SIZE_IS_A4_L = 1609,
     FORMHANDLER = 1610,
     END_FORMHANDLER = 1611,
     BEFORE_EVENT = 1612,
     BEFORE_OPEN_FORM = 1613,
     AFTER_EVENT = 1614,
     BEFORE_CLOSE_FORM = 1615,
     BEFORE_ANY = 1616,
     AFTER_ANY = 1617,
     MENUHANDLER = 1618,
     END_MENUHANDLER = 1619,
     BEFORE_SHOW_MENU = 1620,
     DISABLE_PROGRAM = 1621,
     DISABLE_ALL = 1622,
     BUTTONS = 1623,
     CHECK_MENUITEM = 1624,
     DISABLE_FORM = 1625,
     DISABLE_MENUITEMS = 1626,
     DISABLE = 1627,
     ENABLE_FORM = 1628,
     ENABLE_MENUITEMS = 1629,
     ENABLE = 1630,
     KWFIELD = 1631,
     ICON = 1632,
     MESSAGEBOX = 1633,
     TO_DEFAULTS = 1634,
     UNCHECK_MENUITEM = 1635,
     BEFORE = 1636,
     INPUT = 1637,
     END = 1638,
     INT_TO_ID = 1639
   };
#endif
#define NAME 1641
#define UMINUS 1642
#define COMMA 1557
#define KW_OR 1597
#define KW_AND 1552
#define KW_USING 1488
#define MATCHES 1366
#define POWER 1474
#define LESS_THAN 1470
#define GREATER_THAN 1384
#define EQUAL 1547
#define GREATER_THAN_EQ 1283
#define LESS_THAN_EQ 1341
#define NOT_EQUAL 1415
#define PLUS 1583
#define MINUS 1570
#define DIVIDE 1503
#define MULTIPLY 1475
#define MOD 1571
#define COMMAND 1348
#define NUMBER_VALUE 1643
#define CHAR_VALUE 1644
#define INT_VALUE 1645
#define NAMED_GEN 1646
#define CLINE 1647
#define SQLLINE 1648
#define KW_CSTART 1649
#define KW_CEND 1650
#define USER_DTYPE 1651
#define SQL_TEXT 1652
#define ALTER_TABLE 1000
#define XSET_MULTIPLY_EQUAL_OPEN_BRACKET 1001
#define XSET_ident_DOT_MULTIPLY_EQUAL_OPEN_BRACKET 1002
#define XSET_ident_DOT_MULTIPLY_EQUAL 1003
#define XSET_MULTIPLY_EQUAL 1004
#define XSET_OPEN_BRACKET 1005
#define NEWFORMATSHARED 1006
#define CREATE_DATABASE 1007
#define IMPORT_LEGACY_FUNCTION 1008
#define ADD_CONSTRAINT 1009
#define DROP_CONSTRAINT 1010
#define AS_STATIC 1011
#define NOT_FIELD_TOUCHED 1012
#define LOCAL_FUNCTION 1013
#define EVERY_ROW 1014
#define ELIF 1015
#define DOUBLE_PRECISION 1016
#define COUNT_MULTIPLY 1017
#define WAIT_FOR_KEY 1018
#define AT_TERMINATION_CALL 1019
#define TERMINATE_REPORT 1020
#define TO_MAIN_CAPTION 1021
#define CLEARSTAT 1022
#define TO_MENUITEM 1023
#define ID_TO_INT 1024
#define TO_STATUSBOX 1025
#define ASCII_HEIGHT_ALL 1026
#define ASCII_WIDTH_ALL 1027
#define IMPORT_DATATYPE 1028
#define UP_BY 1029
#define PAGE_TRAILER_SIZE 1030
#define PAGE_HEADER_SIZE 1031
#define FIRST_PAGE_HEADER_SIZE 1032
#define BYTES_USE_AS_IMAGE 1033
#define BYTES_USE_AS_ASCII 1034
#define DOWN_BY 1035
#define CLOSE_STATUSBOX 1036
#define MODIFY_NEXT_SIZE 1037
#define LOCK_MODE_PAGE 1038
#define LOCK_MODE_ROW 1039
#define TO_PIPE 1040
#define TO_PRINTER 1041
#define STATUSBOX 1042
#define CONNECT_TO 1043
#define FORMHANDLER_INPUT 1044
#define UNITS_YEAR 1045
#define UNITS_MONTH 1046
#define UNITS_DAY 1047
#define UNITS_HOUR 1048
#define UNITS_MINUTE 1049
#define UNITS_SECOND 1050
#define NO_NEW_LINES 1051
#define FIELDTOWIDGET 1052
#define WITH_HOLD 1053
#define SHOW_MENU 1054
#define CWIS 1055
#define CREATE_IDX 1056
#define FORM_IS_COMPILED 1057
#define PDF_REPORT 1058
#define IMPORT_FUNCTION 1059
#define PROMPT_MANY 1060
#define POINTS 1061
#define MM 1062
#define INCHES 1063
#define PREPEND 1064
#define MEMBER_OF 1065
#define MEMBER_FUNCTION 1066
#define APPEND 1067
#define TEMPLATE 1068
#define END_TEMPLATE 1069
#define SQLSICS 1070
#define CREATE_SCHEMA 1071
#define SQLSIRR 1072
#define UPDATESTATS_T 1073
#define SQLSICR 1074
#define WHENEVER_SQLSUCCESS 1075
#define WHENEVER_SQLWARNING 1076
#define START_EXTERN 1077
#define WHENEVER_ANY_ERROR 1078
#define WHENEVER_NOT_FOUND 1079
#define CONTINUE_CONSTRUCT 1080
#define FOUNCONSTR 1081
#define SQLSIDR 1082
#define WHENEVER_SQLERROR 1083
#define CREATE_TEMP_TABLE 1084
#define CURRENT_WINDOW_IS 1085
#define FIRST_PAGE_HEADER 1086
#define ORDER_EXTERNAL_BY 1087
#define SCROLL_CURSOR_FOR 1088
#define SCROLL_CURSOR 1089
#define SQL_INTERRUPT_OFF 1090
#define STOP_ALL_EXTERNAL 1091
#define WITH_CHECK_OPTION 1092
#define WITH_GRANT_OPTION 1093
#define SQLSLMNW 1094
#define ADDCONSTUNIQ 1095
#define CONTINUE_DISPLAY 1096
#define CONTINUE_FOREACH 1097
#define OUTPUT_TO_REPORT 1098
#define SQL_INTERRUPT_ON 1099
#define WHENEVER_SUCCESS 1100
#define WHENEVER_WARNING 1101
#define WHERE_CURRENT_OF 1102
#define WITHOUT_DEFAULTS 1103
#define FOCONSTR 1104
#define SCALED_BY 1105
#define CONTINUE_PROMPT 1106
#define PDF_FUNCTION 1107
#define DEFER_INTERRUPT 1108
#define DISPLAY_BY_NAME 1109
#define NOT_NULL_UNIQUE 1110
#define SKIP_TO_TOP 1111
#define TOP_OF_PAGE 1112
#define SKIP_TO 1113
#define SKIP_BY 1114
#define WITHOUT_WAITING 1115
#define BEFCONSTRUCT 1116
#define SQLSLMW 1117
#define WHENEVER_ERROR_CONTINUE 1118
#define WHENEVER_ERROR 1119
#define AFTCONSTRUCT 1120
#define ALL_PRIVILEGES 1121
#define CLOSE_DATABASE 1122
#define CONTINUE_INPUT 1123
#define CONTINUE_WHILE 1124
#define CREATE_SYNONYM 1125
#define DROP_TABLE 1126
#define EXIT_CONSTRUCT 1127
#define INEXCLUSIVE 1128
#define REPORT_TO_PRINTER 1129
#define REPORT_TO_PIPE 1130
#define SET_SESSION_TO 1131
#define UPDATESTATS 1132
#define WITHOUT_HEAD 1133
#define CLEARSCR 1134
#define WITH_B_LOG 1135
#define AUTHORIZATION 1136
#define BOTTOM_MARGIN 1137
#define CLOSE_SESSION 1138
#define CONTINUE_CASE 1139
#define CONTINUE_MENU 1140
#define DISPLAY_ARRAY 1141
#define END_SQL 1142
#define DOLLAR 1143
#define END_CONSTRUCT 1144
#define FIELD_TOUCHED 1145
#define FINISH_REPORT 1146
#define INFACC 1147
#define INPUT_NO_WRAP 1148
#define LOCKMODEPAGE 1149
#define SETPMOFF 1150
#define UNCONSTRAINED 1151
#define PAGE_TRAILER 1152
#define SETPMON 1153
#define BEFGROUP 1154
#define CLOSE_WINDOW 1155
#define COMMENT_LINE 1156
#define CONTINUE_FOR 1157
#define CREATE_DB 1158
#define CREATE_TABLE 1159
#define DEFAULT_NULL 1160
#define DELETE_USING 1161
#define DISPLAY_FORM 1162
#define END_FUNCTION 1163
#define EXIT_DISPLAY 1164
#define EXIT_FOREACH 1165
#define EXIT_PROGRAM 1166
#define INFCOLS 1167
#define LOCKMODEROW 1168
#define ON_EVERY_ROW 1169
#define OPEN_SESSION 1170
#define RIGHT_MARGIN 1171
#define SELECT_USING 1172
#define START_REPORT 1173
#define UNLOCK_TABLE 1174
#define UPDATE_USING 1175
#define ACL_BUILTIN 1176
#define AFTGROUP 1177
#define INFIDX 1178
#define INFSTAT 1179
#define LEFT_MARGIN 1180
#define PAGE_HEADER 1181
#define ROLLBACK_W 1182
#define SET_SESSION 1183
#define SQLSEOFF 1184
#define WITH_A_LOG 1185
#define BEFDISP 1186
#define BEFORE_MENU 1187
#define CREATE_VIEW 1188
#define DEFINE_TYPE 1189
#define DELETE_FROM 1190
#define END_DISPLAY 1191
#define END_REPORT 1192
#define END_FOREACH 1193
#define END_FOR 1194
#define END_GLOBALS 1195
#define EXIT_PROMPT 1196
#define EXTENT_SIZE 1197
#define FOREIGN_KEY 1198
#define HIDE_OPTION 1199
#define HIDE_WINDOW 1200
#define INSERT_INTO 1201
#define IS_NOT_NULL 1202
#define MOVE_WINDOW 1203
#define NEXT_OPTION 1204
#define NOT_MATCHES 1205
#define ON_LAST_ROW 1206
#define OPEN_WINDOW 1207
#define OPEN_STATUSBOX 1208
#define PAGE_LENGTH 1209
#define PAGE_WIDTH 1210
#define PRIMARY_KEY 1211
#define PROMPT_LINE 1212
#define RECORD_LIKE 1213
#define ROLLFORWARD 1214
#define SETBL 1215
#define SHOW_OPTION 1216
#define SHOW_WINDOW 1217
#define SQLSEON 1218
#define TO_DATABASE 1219
#define USE_SESSION 1220
#define WITH_NO_LOG 1221
#define AFTDISP 1222
#define BEFFIELD 1223
#define INSHARE 1224
#define UNLOCKTAB 1225
#define AFTFIELD 1226
#define ATTRIBUTES 1227
#define BEFINP 1228
#define BEGIN_WORK 1229
#define CLEARWIN 1230
#define CLOSE_FORM 1231
#define DEFER_QUIT 1232
#define DESCENDING 1233
#define DROP_INDEX 1234
#define END_PROMPT 1235
#define END_RECORD 1236
#define ERROR_LINE 1237
#define EXIT_INPUT 1238
#define EXIT_WHILE 1239
#define FOR_UPDATE_OF 1240
#define FOR_UPDATE 1241
#define GET_FLDBUF 1242
#define INITIALIZE 1243
#define INPUT_WRAP 1244
#define LOCK_TABLE 1245
#define MSG_LINE 1246
#define NOT_EXISTS 1247
#define ON_ANY_KEY 1248
#define REFERENCES 1249
#define RENCOL 1250
#define SET_CURSOR 1251
#define SMALLFLOAT 1252
#define SQLSUCCESS 1253
#define TOP_MARGIN 1254
#define WITH_ARRAY 1255
#define ACCEPTKEY 1256
#define ACCEPT 1257
#define AFTINP 1258
#define CLEARFORMTODEFAULTS 1259
#define CLEARFORM 1260
#define CLEAR_X_FORM 1261
#define COMMIT_W 1262
#define NEXTPAGE 1263
#define PREVPAGE 1264
#define CTRL_KEY 1265
#define INFTABS 1266
#define NEXTFIELD 1267
#define NEXTFORM 1268
#define RENTAB 1269
#define ASCENDING 1270
#define ASSOCIATE 1271
#define CHARACTER 1272
#define CONSTRUCT 1273
#define DELIMITER 1274
#define DOWNSHIFT 1275
#define DROP_VIEW 1276
#define END_INPUT 1277
#define END_WHILE 1278
#define EXCLUSIVE 1279
#define EXIT_CASE 1280
#define EXIT_MENU 1281
#define FORM_LINE 1282
#define INTERRUPT 1284
#define INTO_TEMP 1285
#define INVISIBLE 1286
#define IN_MEMORY 1287
#define LINKED_TO 1288
#define LOAD_FROM 1289
#define LOCKTAB 1290
#define MENU_LINE 1291
#define OPEN_FORM 1292
#define OTHERWISE 1293
#define PRECISION 1294
#define PRIOR 1295
#define PROCEDURE 1296
#define REPORT_TO 1297
#define RETURNING 1298
#define UNDERLINE 1299
#define UNLOAD_TO 1300
#define BEFROW 1301
#define UNLOAD_T 1302
#define VARIABLE 1303
#define ABSOLUTE 1304
#define AFTROW 1305
#define BUFFERED 1306
#define CONSTANT 1307
#define CONST 1308
#define CONTINUE 1309
#define DATABASE 1310
#define DATETIME 1311
#define DEFAULTS 1312
#define DISTINCT 1313
#define END_CASE 1314
#define END_MAIN 1315
#define END_MENU 1316
#define END_TYPE 1317
#define EXIT_FOR 1318
#define EXTERNAL 1319
#define FRACTION 1320
#define FUNCTION 1321
#define GROUP_BY 1322
#define INTERVAL 1323
#define KWMESSAGE 1324
#define NOT_LIKE 1325
#define NOT_NULL 1326
#define PASSWORD 1327
#define PREVIOUS 1328
#define READONLY 1329
#define REGISTER 1330
#define RELATIVE 1331
#define RESOURCE 1332
#define SMALLINT 1333
#define VALIDATE 1334
#define WHENEVER 1335
#define WITH_LOG 1336
#define WORDWRAP 1337
#define BY_NAME 1338
#define IN_FILE 1339
#define IS_NULL 1340
#define AVERAGE 1342
#define BETWEEN 1343
#define CAPTION 1344
#define CLIPPED 1345
#define CLOSE_BRACKET 1346
#define COLUMNS 1347
#define COMMENT 1349
#define CONNECT 1350
#define CURRENT 1351
#define DBYNAME 1352
#define DECIMAL 1353
#define DECLARE 1354
#define DEFAULT 1355
#define DISPLAY 1356
#define ENDCODE 1357
#define EXECUTE 1358
#define FOREACH 1359
#define FOREIGN 1360
#define GLOBALS 1361
#define INFIELD 1362
#define INTEGER 1363
#define KWWINDOW 1364
#define MAGENTA 1365
#define NUMERIC 1367
#define OPTIONS 1368
#define PERCENT 1369
#define PREPARE 1370
#define PROGRAM 1371
#define RECOVER 1372
#define REVERSE 1373
#define SECTION 1374
#define SESSION 1375
#define SYNONYM 1376
#define THRU 1377
#define TRAILER 1378
#define UPSHIFT 1379
#define VARCHAR 1380
#define WAITING 1381
#define CLOSE_SHEV 1382
#define CLOSE_SQUARE 1383
#define KW_FALSE 1385
#define NOT_IN 1386
#define ONKEY 1387
#define OPEN_BRACKET 1388
#define BORDER 1389
#define BOTTOM 1390
#define COLUMN 1391
#define COMMIT 1392
#define CREATE 1393
#define CURSOR 1394
#define DEFINE 1395
#define DELETE 1396
#define DOUBLE 1397
#define END_IF 1398
#define ESCAPE 1399
#define EXISTS 1400
#define EXTEND 1401
#define EXTENT 1402
#define FINISH 1403
#define FORMAT 1404
#define HAVING 1405
#define HEADER 1406
#define INSERT 1407
#define LOCATE 1408
#define MARGIN 1409
#define MEMORY 1410
#define MINUTE 1411
#define MODIFY 1412
#define NORMAL 1413
#define EQUAL_EQUAL 1414
#define OPEN_SHEV 1416
#define OPEN_SQUARE 1417
#define OPTION 1418
#define OUTPUT 1419
#define PROMPT 1420
#define PUBLIC 1421
#define RECORD 1422
#define REPORT 1423
#define RETURN 1424
#define REVOKE 1425
#define SCHEMA 1426
#define SCROLL_USING 1427
#define SCROLL 1428
#define SECOND 1429
#define SELECT 1430
#define SERIAL 1431
#define SETL 1432
#define SHARED 1433
#define SPACES 1434
#define UNIQUE 1435
#define UNLOCK 1436
#define UPDATE 1437
#define VALUES 1438
#define YELLOW 1439
#define AFTER 1440
#define KWLINE 1441
#define KW_NULL 1442
#define KW_TRUE 1443
#define SINGLE_KEY 1444
#define ALTER 1445
#define ARRAY 1446
#define ASCII 1447
#define AUDIT 1448
#define BLACK 1449
#define BLINK 1450
#define CHECK 1451
#define CLEAR 1452
#define CLOSE 1453
#define CODE_C 1454
#define COUNT 1455
#define DEFER 1456
#define ERROR 1457
#define EVERY 1458
#define FETCH 1459
#define FIRST 1460
#define FLOAT 1461
#define FLUSH 1462
#define FOUND 1463
#define GRANT 1464
#define GREEN 1465
#define GROUP 1466
#define INDEX 1467
#define KWFORM 1468
#define LABEL 1469
#define LOCAL 1471
#define MONEY 1472
#define MONTH 1473
#define ORDER 1476
#define OUTER 1477
#define PAUSE 1478
#define PRINT_IMAGE 1479
#define PRINT_FILE 1480
#define PRINT 1481
#define RIGHT 1482
#define DOUBLE_COLON 1483
#define SEMICOLON 1484
#define SLEEP 1485
#define TUPLE 1486
#define UNION 1487
#define WHERE 1489
#define WHILE 1490
#define WHITE 1491
#define CCODE 1492
#define ANSI 1493
#define BLUE 1494
#define BOLD 1495
#define BYTE 1496
#define FCALL 1497
#define CASE 1498
#define CHAR 1499
#define CYAN 1500
#define DATE 1501
#define DESC 1502
#define DOWN 1504
#define TAB 1505
#define DROP 1506
#define ELSE 1507
#define EXEC 1508
#define EXIT 1509
#define FREE 1510
#define FROM 1511
#define GOTO 1512
#define HELP_FILE 1513
#define LANG_FILE 1514
#define HELP 1515
#define HIDE 1516
#define HOUR 1517
#define INTO 1518
#define LAST 1519
#define LEFT 1520
#define LIKE 1521
#define MAIN 1522
#define MENU 1523
#define MODE 1524
#define NEED 1525
#define NEXT 1526
#define NOCR 1527
#define OPEN 1528
#define QUIT 1529
#define REAL 1530
#define ROWS 1531
#define SHOW 1532
#define SIZE 1533
#define SKIP 1534
#define SOME 1535
#define STEP 1536
#define STOP 1537
#define TEMP 1538
#define TEXT 1539
#define THEN 1540
#define USER 1541
#define WAIT 1542
#define WHEN 1543
#define WITH 1544
#define WORK 1545
#define YEAR 1546
#define KW_IS 1548
#define XSET 1549
#define ADD 1550
#define ALL 1551
#define ANY 1553
#define ASC 1554
#define AVG 1555
#define COLON 1556
#define DAY 1558
#define DBA 1559
#define DEC 1560
#define DIM 1561
#define FKEY 1562
#define FOR 1563
#define KEY 1564
#define KWNO 1565
#define LET 1566
#define LOG 1567
#define XMAX 1568
#define XMIN 1569
#define NOT 1572
#define PAD 1573
#define PUT 1574
#define RED 1575
#define ROW 1576
#define RUN 1577
#define SQL 1578
#define SUM 1579
#define TOP 1580
#define USE 1581
#define ATSIGN 1582
#define AS_TIFF 1584
#define AS_GIF 1585
#define AS_PNG 1586
#define AS_JPEG 1587
#define AS 1588
#define AT 1589
#define BY 1590
#define DOT 1591
#define GO 1592
#define IF 1593
#define IN 1594
#define OF 1595
#define ON 1596
#define TO 1598
#define UP 1599
#define FONT_NAME 1600
#define FONT_SIZE 1601
#define PAPER_SIZE_IS_LETTER 1602
#define PAPER_SIZE_IS_LEGAL 1603
#define PAPER_SIZE_IS_A5 1604
#define PAPER_SIZE_IS_A4 1605
#define PAPER_SIZE_IS_LETTER_L 1606
#define PAPER_SIZE_IS_LEGAL_L 1607
#define PAPER_SIZE_IS_A5_L 1608
#define PAPER_SIZE_IS_A4_L 1609
#define FORMHANDLER 1610
#define END_FORMHANDLER 1611
#define BEFORE_EVENT 1612
#define BEFORE_OPEN_FORM 1613
#define AFTER_EVENT 1614
#define BEFORE_CLOSE_FORM 1615
#define BEFORE_ANY 1616
#define AFTER_ANY 1617
#define MENUHANDLER 1618
#define END_MENUHANDLER 1619
#define BEFORE_SHOW_MENU 1620
#define DISABLE_PROGRAM 1621
#define DISABLE_ALL 1622
#define BUTTONS 1623
#define CHECK_MENUITEM 1624
#define DISABLE_FORM 1625
#define DISABLE_MENUITEMS 1626
#define DISABLE 1627
#define ENABLE_FORM 1628
#define ENABLE_MENUITEMS 1629
#define ENABLE 1630
#define KWFIELD 1631
#define ICON 1632
#define MESSAGEBOX 1633
#define TO_DEFAULTS 1634
#define UNCHECK_MENUITEM 1635
#define BEFORE 1636
#define INPUT 1637
#define END 1638
#define INT_TO_ID 1639




#if ! defined (YYSTYPE) && ! defined (YYSTYPE_IS_DECLARED)
#line 198 "fgl.yacc"
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
#line 1364 "y.tab.h"
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif





