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
     NAME = 1636,
     UMINUS = 1637,
     COMMA = 1552,
     KW_OR = 1592,
     KW_AND = 1547,
     KW_USING = 1483,
     MATCHES = 1361,
     POWER = 1469,
     LESS_THAN = 1465,
     GREATER_THAN = 1379,
     EQUAL = 1542,
     GREATER_THAN_EQ = 1278,
     LESS_THAN_EQ = 1336,
     NOT_EQUAL = 1410,
     PLUS = 1578,
     MINUS = 1565,
     DIVIDE = 1498,
     MULTIPLY = 1470,
     MOD = 1566,
     COMMAND = 1343,
     NUMBER_VALUE = 1638,
     CHAR_VALUE = 1639,
     INT_VALUE = 1640,
     NAMED_GEN = 1641,
     CLINE = 1642,
     SQLLINE = 1643,
     KW_CSTART = 1644,
     KW_CEND = 1645,
     USER_DTYPE = 1646,
     SQL_TEXT = 1647,
     ALTER_TABLE = 1000,
     NEWFORMATSHARED = 1001,
     CREATE_DATABASE = 1002,
     IMPORT_LEGACY_FUNCTION = 1003,
     ADD_CONSTRAINT = 1004,
     DROP_CONSTRAINT = 1005,
     AS_STATIC = 1006,
     NOT_FIELD_TOUCHED = 1007,
     LOCAL_FUNCTION = 1008,
     EVERY_ROW = 1009,
     ELIF = 1010,
     DOUBLE_PRECISION = 1011,
     COUNT_MULTIPLY = 1012,
     WAIT_FOR_KEY = 1013,
     AT_TERMINATION_CALL = 1014,
     TERMINATE_REPORT = 1015,
     TO_MAIN_CAPTION = 1016,
     CLEARSTAT = 1017,
     TO_MENUITEM = 1018,
     ID_TO_INT = 1019,
     TO_STATUSBOX = 1020,
     ASCII_HEIGHT_ALL = 1021,
     ASCII_WIDTH_ALL = 1022,
     IMPORT_DATATYPE = 1023,
     UP_BY = 1024,
     PAGE_TRAILER_SIZE = 1025,
     PAGE_HEADER_SIZE = 1026,
     FIRST_PAGE_HEADER_SIZE = 1027,
     BYTES_USE_AS_IMAGE = 1028,
     BYTES_USE_AS_ASCII = 1029,
     DOWN_BY = 1030,
     CLOSE_STATUSBOX = 1031,
     MODIFY_NEXT_SIZE = 1032,
     LOCK_MODE_PAGE = 1033,
     LOCK_MODE_ROW = 1034,
     TO_PIPE = 1035,
     TO_PRINTER = 1036,
     STATUSBOX = 1037,
     CONNECT_TO = 1038,
     FORMHANDLER_INPUT = 1039,
     UNITS_YEAR = 1040,
     UNITS_MONTH = 1041,
     UNITS_DAY = 1042,
     UNITS_HOUR = 1043,
     UNITS_MINUTE = 1044,
     UNITS_SECOND = 1045,
     NO_NEW_LINES = 1046,
     FIELDTOWIDGET = 1047,
     WITH_HOLD = 1048,
     SHOW_MENU = 1049,
     CWIS = 1050,
     CREATE_IDX = 1051,
     FORM_IS_COMPILED = 1052,
     PDF_REPORT = 1053,
     IMPORT_FUNCTION = 1054,
     PROMPT_MANY = 1055,
     POINTS = 1056,
     MM = 1057,
     INCHES = 1058,
     PREPEND = 1059,
     MEMBER_OF = 1060,
     MEMBER_FUNCTION = 1061,
     APPEND = 1062,
     TEMPLATE = 1063,
     END_TEMPLATE = 1064,
     SQLSICS = 1065,
     CREATE_SCHEMA = 1066,
     SQLSIRR = 1067,
     UPDATESTATS_T = 1068,
     SQLSICR = 1069,
     WHENEVER_SQLSUCCESS = 1070,
     WHENEVER_SQLWARNING = 1071,
     START_EXTERN = 1072,
     WHENEVER_ANY_ERROR = 1073,
     WHENEVER_NOT_FOUND = 1074,
     CONTINUE_CONSTRUCT = 1075,
     FOUNCONSTR = 1076,
     SQLSIDR = 1077,
     WHENEVER_SQLERROR = 1078,
     CREATE_TEMP_TABLE = 1079,
     CURRENT_WINDOW_IS = 1080,
     FIRST_PAGE_HEADER = 1081,
     ORDER_EXTERNAL_BY = 1082,
     SCROLL_CURSOR_FOR = 1083,
     SCROLL_CURSOR = 1084,
     SQL_INTERRUPT_OFF = 1085,
     STOP_ALL_EXTERNAL = 1086,
     WITH_CHECK_OPTION = 1087,
     WITH_GRANT_OPTION = 1088,
     SQLSLMNW = 1089,
     ADDCONSTUNIQ = 1090,
     CONTINUE_DISPLAY = 1091,
     CONTINUE_FOREACH = 1092,
     OUTPUT_TO_REPORT = 1093,
     SQL_INTERRUPT_ON = 1094,
     WHENEVER_SUCCESS = 1095,
     WHENEVER_WARNING = 1096,
     WHERE_CURRENT_OF = 1097,
     WITHOUT_DEFAULTS = 1098,
     FOCONSTR = 1099,
     SCALED_BY = 1100,
     CONTINUE_PROMPT = 1101,
     PDF_FUNCTION = 1102,
     DEFER_INTERRUPT = 1103,
     DISPLAY_BY_NAME = 1104,
     NOT_NULL_UNIQUE = 1105,
     SKIP_TO_TOP = 1106,
     TOP_OF_PAGE = 1107,
     SKIP_TO = 1108,
     SKIP_BY = 1109,
     WITHOUT_WAITING = 1110,
     BEFCONSTRUCT = 1111,
     SQLSLMW = 1112,
     WHENEVER_ERROR_CONTINUE = 1113,
     WHENEVER_ERROR = 1114,
     AFTCONSTRUCT = 1115,
     ALL_PRIVILEGES = 1116,
     CLOSE_DATABASE = 1117,
     CONTINUE_INPUT = 1118,
     CONTINUE_WHILE = 1119,
     CREATE_SYNONYM = 1120,
     DROP_TABLE = 1121,
     EXIT_CONSTRUCT = 1122,
     INEXCLUSIVE = 1123,
     REPORT_TO_PRINTER = 1124,
     REPORT_TO_PIPE = 1125,
     SET_SESSION_TO = 1126,
     UPDATESTATS = 1127,
     WITHOUT_HEAD = 1128,
     CLEARSCR = 1129,
     WITH_B_LOG = 1130,
     AUTHORIZATION = 1131,
     BOTTOM_MARGIN = 1132,
     CLOSE_SESSION = 1133,
     CONTINUE_CASE = 1134,
     CONTINUE_MENU = 1135,
     DISPLAY_ARRAY = 1136,
     END_SQL = 1137,
     DOLLAR = 1138,
     END_CONSTRUCT = 1139,
     FIELD_TOUCHED = 1140,
     FINISH_REPORT = 1141,
     INFACC = 1142,
     INPUT_NO_WRAP = 1143,
     LOCKMODEPAGE = 1144,
     SETPMOFF = 1145,
     UNCONSTRAINED = 1146,
     PAGE_TRAILER = 1147,
     SETPMON = 1148,
     BEFGROUP = 1149,
     CLOSE_WINDOW = 1150,
     COMMENT_LINE = 1151,
     CONTINUE_FOR = 1152,
     CREATE_DB = 1153,
     CREATE_TABLE = 1154,
     DEFAULT_NULL = 1155,
     DELETE_USING = 1156,
     DISPLAY_FORM = 1157,
     END_FUNCTION = 1158,
     EXIT_DISPLAY = 1159,
     EXIT_FOREACH = 1160,
     EXIT_PROGRAM = 1161,
     INFCOLS = 1162,
     LOCKMODEROW = 1163,
     ON_EVERY_ROW = 1164,
     OPEN_SESSION = 1165,
     RIGHT_MARGIN = 1166,
     SELECT_USING = 1167,
     START_REPORT = 1168,
     UNLOCK_TABLE = 1169,
     UPDATE_USING = 1170,
     ACL_BUILTIN = 1171,
     AFTGROUP = 1172,
     INFIDX = 1173,
     INFSTAT = 1174,
     LEFT_MARGIN = 1175,
     PAGE_HEADER = 1176,
     ROLLBACK_W = 1177,
     SET_SESSION = 1178,
     SQLSEOFF = 1179,
     WITH_A_LOG = 1180,
     BEFDISP = 1181,
     BEFORE_MENU = 1182,
     CREATE_VIEW = 1183,
     DEFINE_TYPE = 1184,
     DELETE_FROM = 1185,
     END_DISPLAY = 1186,
     END_REPORT = 1187,
     END_FOREACH = 1188,
     END_FOR = 1189,
     END_GLOBALS = 1190,
     EXIT_PROMPT = 1191,
     EXTENT_SIZE = 1192,
     FOREIGN_KEY = 1193,
     HIDE_OPTION = 1194,
     HIDE_WINDOW = 1195,
     INSERT_INTO = 1196,
     IS_NOT_NULL = 1197,
     MOVE_WINDOW = 1198,
     NEXT_OPTION = 1199,
     NOT_MATCHES = 1200,
     ON_LAST_ROW = 1201,
     OPEN_WINDOW = 1202,
     OPEN_STATUSBOX = 1203,
     PAGE_LENGTH = 1204,
     PAGE_WIDTH = 1205,
     PRIMARY_KEY = 1206,
     PROMPT_LINE = 1207,
     RECORD_LIKE = 1208,
     ROLLFORWARD = 1209,
     SETBL = 1210,
     SHOW_OPTION = 1211,
     SHOW_WINDOW = 1212,
     SQLSEON = 1213,
     TO_DATABASE = 1214,
     USE_SESSION = 1215,
     WITH_NO_LOG = 1216,
     AFTDISP = 1217,
     BEFFIELD = 1218,
     INSHARE = 1219,
     UNLOCKTAB = 1220,
     AFTFIELD = 1221,
     ATTRIBUTES = 1222,
     BEFINP = 1223,
     BEGIN_WORK = 1224,
     CLEARWIN = 1225,
     CLOSE_FORM = 1226,
     DEFER_QUIT = 1227,
     DESCENDING = 1228,
     DROP_INDEX = 1229,
     END_PROMPT = 1230,
     END_RECORD = 1231,
     ERROR_LINE = 1232,
     EXIT_INPUT = 1233,
     EXIT_WHILE = 1234,
     FOR_UPDATE_OF = 1235,
     FOR_UPDATE = 1236,
     GET_FLDBUF = 1237,
     INITIALIZE = 1238,
     INPUT_WRAP = 1239,
     LOCK_TABLE = 1240,
     MSG_LINE = 1241,
     NOT_EXISTS = 1242,
     ON_ANY_KEY = 1243,
     REFERENCES = 1244,
     RENCOL = 1245,
     SET_CURSOR = 1246,
     SMALLFLOAT = 1247,
     SQLSUCCESS = 1248,
     TOP_MARGIN = 1249,
     WITH_ARRAY = 1250,
     ACCEPTKEY = 1251,
     ACCEPT = 1252,
     AFTINP = 1253,
     CLEARFORMTODEFAULTS = 1254,
     CLEARFORM = 1255,
     CLEAR_X_FORM = 1256,
     COMMIT_W = 1257,
     NEXTPAGE = 1258,
     PREVPAGE = 1259,
     CTRL_KEY = 1260,
     INFTABS = 1261,
     NEXTFIELD = 1262,
     NEXTFORM = 1263,
     RENTAB = 1264,
     ASCENDING = 1265,
     ASSOCIATE = 1266,
     CHARACTER = 1267,
     CONSTRUCT = 1268,
     DELIMITER = 1269,
     DOWNSHIFT = 1270,
     DROP_VIEW = 1271,
     END_INPUT = 1272,
     END_WHILE = 1273,
     EXCLUSIVE = 1274,
     EXIT_CASE = 1275,
     EXIT_MENU = 1276,
     FORM_LINE = 1277,
     INTERRUPT = 1279,
     INTO_TEMP = 1280,
     INVISIBLE = 1281,
     IN_MEMORY = 1282,
     LINKED_TO = 1283,
     LOAD_FROM = 1284,
     LOCKTAB = 1285,
     MENU_LINE = 1286,
     OPEN_FORM = 1287,
     OTHERWISE = 1288,
     PRECISION = 1289,
     PRIOR = 1290,
     PROCEDURE = 1291,
     REPORT_TO = 1292,
     RETURNING = 1293,
     UNDERLINE = 1294,
     UNLOAD_TO = 1295,
     BEFROW = 1296,
     UNLOAD_T = 1297,
     VARIABLE = 1298,
     ABSOLUTE = 1299,
     AFTROW = 1300,
     BUFFERED = 1301,
     CONSTANT = 1302,
     CONST = 1303,
     CONTINUE = 1304,
     DATABASE = 1305,
     DATETIME = 1306,
     DEFAULTS = 1307,
     DISTINCT = 1308,
     END_CASE = 1309,
     END_MAIN = 1310,
     END_MENU = 1311,
     END_TYPE = 1312,
     EXIT_FOR = 1313,
     EXTERNAL = 1314,
     FRACTION = 1315,
     FUNCTION = 1316,
     GROUP_BY = 1317,
     INTERVAL = 1318,
     KWMESSAGE = 1319,
     NOT_LIKE = 1320,
     NOT_NULL = 1321,
     PASSWORD = 1322,
     PREVIOUS = 1323,
     READONLY = 1324,
     REGISTER = 1325,
     RELATIVE = 1326,
     RESOURCE = 1327,
     SMALLINT = 1328,
     VALIDATE = 1329,
     WHENEVER = 1330,
     WITH_LOG = 1331,
     WORDWRAP = 1332,
     BY_NAME = 1333,
     IN_FILE = 1334,
     IS_NULL = 1335,
     AVERAGE = 1337,
     BETWEEN = 1338,
     CAPTION = 1339,
     CLIPPED = 1340,
     CLOSE_BRACKET = 1341,
     COLUMNS = 1342,
     COMMENT = 1344,
     CONNECT = 1345,
     CURRENT = 1346,
     DBYNAME = 1347,
     DECIMAL = 1348,
     DECLARE = 1349,
     DEFAULT = 1350,
     DISPLAY = 1351,
     ENDCODE = 1352,
     EXECUTE = 1353,
     FOREACH = 1354,
     FOREIGN = 1355,
     GLOBALS = 1356,
     INFIELD = 1357,
     INTEGER = 1358,
     KWWINDOW = 1359,
     MAGENTA = 1360,
     NUMERIC = 1362,
     OPTIONS = 1363,
     PERCENT = 1364,
     PREPARE = 1365,
     PROGRAM = 1366,
     RECOVER = 1367,
     REVERSE = 1368,
     SECTION = 1369,
     SESSION = 1370,
     SYNONYM = 1371,
     THRU = 1372,
     TRAILER = 1373,
     UPSHIFT = 1374,
     VARCHAR = 1375,
     WAITING = 1376,
     CLOSE_SHEV = 1377,
     CLOSE_SQUARE = 1378,
     KW_FALSE = 1380,
     NOT_IN = 1381,
     ONKEY = 1382,
     OPEN_BRACKET = 1383,
     BORDER = 1384,
     BOTTOM = 1385,
     COLUMN = 1386,
     COMMIT = 1387,
     CREATE = 1388,
     CURSOR = 1389,
     DEFINE = 1390,
     DELETE = 1391,
     DOUBLE = 1392,
     END_IF = 1393,
     ESCAPE = 1394,
     EXISTS = 1395,
     EXTEND = 1396,
     EXTENT = 1397,
     FINISH = 1398,
     FORMAT = 1399,
     HAVING = 1400,
     HEADER = 1401,
     INSERT = 1402,
     LOCATE = 1403,
     MARGIN = 1404,
     MEMORY = 1405,
     MINUTE = 1406,
     MODIFY = 1407,
     NORMAL = 1408,
     EQUAL_EQUAL = 1409,
     OPEN_SHEV = 1411,
     OPEN_SQUARE = 1412,
     OPTION = 1413,
     OUTPUT = 1414,
     PROMPT = 1415,
     PUBLIC = 1416,
     RECORD = 1417,
     REPORT = 1418,
     RETURN = 1419,
     REVOKE = 1420,
     SCHEMA = 1421,
     SCROLL_USING = 1422,
     SCROLL = 1423,
     SECOND = 1424,
     SELECT = 1425,
     SERIAL = 1426,
     SETL = 1427,
     SHARED = 1428,
     SPACES = 1429,
     UNIQUE = 1430,
     UNLOCK = 1431,
     UPDATE = 1432,
     VALUES = 1433,
     YELLOW = 1434,
     AFTER = 1435,
     KWLINE = 1436,
     KW_NULL = 1437,
     KW_TRUE = 1438,
     SINGLE_KEY = 1439,
     ALTER = 1440,
     ARRAY = 1441,
     ASCII = 1442,
     AUDIT = 1443,
     BLACK = 1444,
     BLINK = 1445,
     CHECK = 1446,
     CLEAR = 1447,
     CLOSE = 1448,
     CODE_C = 1449,
     COUNT = 1450,
     DEFER = 1451,
     ERROR = 1452,
     EVERY = 1453,
     FETCH = 1454,
     FIRST = 1455,
     FLOAT = 1456,
     FLUSH = 1457,
     FOUND = 1458,
     GRANT = 1459,
     GREEN = 1460,
     GROUP = 1461,
     INDEX = 1462,
     KWFORM = 1463,
     LABEL = 1464,
     LOCAL = 1466,
     MONEY = 1467,
     MONTH = 1468,
     ORDER = 1471,
     OUTER = 1472,
     PAUSE = 1473,
     PRINT_IMAGE = 1474,
     PRINT_FILE = 1475,
     PRINT = 1476,
     RIGHT = 1477,
     DOUBLE_COLON = 1478,
     SEMICOLON = 1479,
     SLEEP = 1480,
     TUPLE = 1481,
     UNION = 1482,
     WHERE = 1484,
     WHILE = 1485,
     WHITE = 1486,
     CCODE = 1487,
     ANSI = 1488,
     BLUE = 1489,
     BOLD = 1490,
     BYTE = 1491,
     FCALL = 1492,
     CASE = 1493,
     CHAR = 1494,
     CYAN = 1495,
     DATE = 1496,
     DESC = 1497,
     DOWN = 1499,
     TAB = 1500,
     DROP = 1501,
     ELSE = 1502,
     EXEC = 1503,
     EXIT = 1504,
     FREE = 1505,
     FROM = 1506,
     GOTO = 1507,
     HELP_FILE = 1508,
     LANG_FILE = 1509,
     HELP = 1510,
     HIDE = 1511,
     HOUR = 1512,
     INTO = 1513,
     LAST = 1514,
     LEFT = 1515,
     LIKE = 1516,
     MAIN = 1517,
     MENU = 1518,
     MODE = 1519,
     NEED = 1520,
     NEXT = 1521,
     NOCR = 1522,
     OPEN = 1523,
     QUIT = 1524,
     REAL = 1525,
     ROWS = 1526,
     SHOW = 1527,
     SIZE = 1528,
     SKIP = 1529,
     SOME = 1530,
     STEP = 1531,
     STOP = 1532,
     TEMP = 1533,
     TEXT = 1534,
     THEN = 1535,
     USER = 1536,
     WAIT = 1537,
     WHEN = 1538,
     WITH = 1539,
     WORK = 1540,
     YEAR = 1541,
     KW_IS = 1543,
     XSET = 1544,
     ADD = 1545,
     ALL = 1546,
     ANY = 1548,
     ASC = 1549,
     AVG = 1550,
     COLON = 1551,
     DAY = 1553,
     DBA = 1554,
     DEC = 1555,
     DIM = 1556,
     FKEY = 1557,
     FOR = 1558,
     KEY = 1559,
     KWNO = 1560,
     LET = 1561,
     LOG = 1562,
     XMAX = 1563,
     XMIN = 1564,
     NOT = 1567,
     PAD = 1568,
     PUT = 1569,
     RED = 1570,
     ROW = 1571,
     RUN = 1572,
     SQL = 1573,
     SUM = 1574,
     TOP = 1575,
     USE = 1576,
     ATSIGN = 1577,
     AS_TIFF = 1579,
     AS_GIF = 1580,
     AS_PNG = 1581,
     AS_JPEG = 1582,
     AS = 1583,
     AT = 1584,
     BY = 1585,
     DOT = 1586,
     GO = 1587,
     IF = 1588,
     IN = 1589,
     OF = 1590,
     ON = 1591,
     TO = 1593,
     UP = 1594,
     FONT_NAME = 1595,
     FONT_SIZE = 1596,
     PAPER_SIZE_IS_LETTER = 1597,
     PAPER_SIZE_IS_LEGAL = 1598,
     PAPER_SIZE_IS_A5 = 1599,
     PAPER_SIZE_IS_A4 = 1600,
     PAPER_SIZE_IS_LETTER_L = 1601,
     PAPER_SIZE_IS_LEGAL_L = 1602,
     PAPER_SIZE_IS_A5_L = 1603,
     PAPER_SIZE_IS_A4_L = 1604,
     FORMHANDLER = 1605,
     END_FORMHANDLER = 1606,
     BEFORE_EVENT = 1607,
     BEFORE_OPEN_FORM = 1608,
     AFTER_EVENT = 1609,
     BEFORE_CLOSE_FORM = 1610,
     BEFORE_ANY = 1611,
     AFTER_ANY = 1612,
     MENUHANDLER = 1613,
     END_MENUHANDLER = 1614,
     BEFORE_SHOW_MENU = 1615,
     DISABLE_PROGRAM = 1616,
     DISABLE_ALL = 1617,
     BUTTONS = 1618,
     CHECK_MENUITEM = 1619,
     DISABLE_FORM = 1620,
     DISABLE_MENUITEMS = 1621,
     DISABLE = 1622,
     ENABLE_FORM = 1623,
     ENABLE_MENUITEMS = 1624,
     ENABLE = 1625,
     KWFIELD = 1626,
     ICON = 1627,
     MESSAGEBOX = 1628,
     TO_DEFAULTS = 1629,
     UNCHECK_MENUITEM = 1630,
     BEFORE = 1631,
     INPUT = 1632,
     END = 1633,
     INT_TO_ID = 1634
   };
#endif
#define NAME 1636
#define UMINUS 1637
#define COMMA 1552
#define KW_OR 1592
#define KW_AND 1547
#define KW_USING 1483
#define MATCHES 1361
#define POWER 1469
#define LESS_THAN 1465
#define GREATER_THAN 1379
#define EQUAL 1542
#define GREATER_THAN_EQ 1278
#define LESS_THAN_EQ 1336
#define NOT_EQUAL 1410
#define PLUS 1578
#define MINUS 1565
#define DIVIDE 1498
#define MULTIPLY 1470
#define MOD 1566
#define COMMAND 1343
#define NUMBER_VALUE 1638
#define CHAR_VALUE 1639
#define INT_VALUE 1640
#define NAMED_GEN 1641
#define CLINE 1642
#define SQLLINE 1643
#define KW_CSTART 1644
#define KW_CEND 1645
#define USER_DTYPE 1646
#define SQL_TEXT 1647
#define ALTER_TABLE 1000
#define NEWFORMATSHARED 1001
#define CREATE_DATABASE 1002
#define IMPORT_LEGACY_FUNCTION 1003
#define ADD_CONSTRAINT 1004
#define DROP_CONSTRAINT 1005
#define AS_STATIC 1006
#define NOT_FIELD_TOUCHED 1007
#define LOCAL_FUNCTION 1008
#define EVERY_ROW 1009
#define ELIF 1010
#define DOUBLE_PRECISION 1011
#define COUNT_MULTIPLY 1012
#define WAIT_FOR_KEY 1013
#define AT_TERMINATION_CALL 1014
#define TERMINATE_REPORT 1015
#define TO_MAIN_CAPTION 1016
#define CLEARSTAT 1017
#define TO_MENUITEM 1018
#define ID_TO_INT 1019
#define TO_STATUSBOX 1020
#define ASCII_HEIGHT_ALL 1021
#define ASCII_WIDTH_ALL 1022
#define IMPORT_DATATYPE 1023
#define UP_BY 1024
#define PAGE_TRAILER_SIZE 1025
#define PAGE_HEADER_SIZE 1026
#define FIRST_PAGE_HEADER_SIZE 1027
#define BYTES_USE_AS_IMAGE 1028
#define BYTES_USE_AS_ASCII 1029
#define DOWN_BY 1030
#define CLOSE_STATUSBOX 1031
#define MODIFY_NEXT_SIZE 1032
#define LOCK_MODE_PAGE 1033
#define LOCK_MODE_ROW 1034
#define TO_PIPE 1035
#define TO_PRINTER 1036
#define STATUSBOX 1037
#define CONNECT_TO 1038
#define FORMHANDLER_INPUT 1039
#define UNITS_YEAR 1040
#define UNITS_MONTH 1041
#define UNITS_DAY 1042
#define UNITS_HOUR 1043
#define UNITS_MINUTE 1044
#define UNITS_SECOND 1045
#define NO_NEW_LINES 1046
#define FIELDTOWIDGET 1047
#define WITH_HOLD 1048
#define SHOW_MENU 1049
#define CWIS 1050
#define CREATE_IDX 1051
#define FORM_IS_COMPILED 1052
#define PDF_REPORT 1053
#define IMPORT_FUNCTION 1054
#define PROMPT_MANY 1055
#define POINTS 1056
#define MM 1057
#define INCHES 1058
#define PREPEND 1059
#define MEMBER_OF 1060
#define MEMBER_FUNCTION 1061
#define APPEND 1062
#define TEMPLATE 1063
#define END_TEMPLATE 1064
#define SQLSICS 1065
#define CREATE_SCHEMA 1066
#define SQLSIRR 1067
#define UPDATESTATS_T 1068
#define SQLSICR 1069
#define WHENEVER_SQLSUCCESS 1070
#define WHENEVER_SQLWARNING 1071
#define START_EXTERN 1072
#define WHENEVER_ANY_ERROR 1073
#define WHENEVER_NOT_FOUND 1074
#define CONTINUE_CONSTRUCT 1075
#define FOUNCONSTR 1076
#define SQLSIDR 1077
#define WHENEVER_SQLERROR 1078
#define CREATE_TEMP_TABLE 1079
#define CURRENT_WINDOW_IS 1080
#define FIRST_PAGE_HEADER 1081
#define ORDER_EXTERNAL_BY 1082
#define SCROLL_CURSOR_FOR 1083
#define SCROLL_CURSOR 1084
#define SQL_INTERRUPT_OFF 1085
#define STOP_ALL_EXTERNAL 1086
#define WITH_CHECK_OPTION 1087
#define WITH_GRANT_OPTION 1088
#define SQLSLMNW 1089
#define ADDCONSTUNIQ 1090
#define CONTINUE_DISPLAY 1091
#define CONTINUE_FOREACH 1092
#define OUTPUT_TO_REPORT 1093
#define SQL_INTERRUPT_ON 1094
#define WHENEVER_SUCCESS 1095
#define WHENEVER_WARNING 1096
#define WHERE_CURRENT_OF 1097
#define WITHOUT_DEFAULTS 1098
#define FOCONSTR 1099
#define SCALED_BY 1100
#define CONTINUE_PROMPT 1101
#define PDF_FUNCTION 1102
#define DEFER_INTERRUPT 1103
#define DISPLAY_BY_NAME 1104
#define NOT_NULL_UNIQUE 1105
#define SKIP_TO_TOP 1106
#define TOP_OF_PAGE 1107
#define SKIP_TO 1108
#define SKIP_BY 1109
#define WITHOUT_WAITING 1110
#define BEFCONSTRUCT 1111
#define SQLSLMW 1112
#define WHENEVER_ERROR_CONTINUE 1113
#define WHENEVER_ERROR 1114
#define AFTCONSTRUCT 1115
#define ALL_PRIVILEGES 1116
#define CLOSE_DATABASE 1117
#define CONTINUE_INPUT 1118
#define CONTINUE_WHILE 1119
#define CREATE_SYNONYM 1120
#define DROP_TABLE 1121
#define EXIT_CONSTRUCT 1122
#define INEXCLUSIVE 1123
#define REPORT_TO_PRINTER 1124
#define REPORT_TO_PIPE 1125
#define SET_SESSION_TO 1126
#define UPDATESTATS 1127
#define WITHOUT_HEAD 1128
#define CLEARSCR 1129
#define WITH_B_LOG 1130
#define AUTHORIZATION 1131
#define BOTTOM_MARGIN 1132
#define CLOSE_SESSION 1133
#define CONTINUE_CASE 1134
#define CONTINUE_MENU 1135
#define DISPLAY_ARRAY 1136
#define END_SQL 1137
#define DOLLAR 1138
#define END_CONSTRUCT 1139
#define FIELD_TOUCHED 1140
#define FINISH_REPORT 1141
#define INFACC 1142
#define INPUT_NO_WRAP 1143
#define LOCKMODEPAGE 1144
#define SETPMOFF 1145
#define UNCONSTRAINED 1146
#define PAGE_TRAILER 1147
#define SETPMON 1148
#define BEFGROUP 1149
#define CLOSE_WINDOW 1150
#define COMMENT_LINE 1151
#define CONTINUE_FOR 1152
#define CREATE_DB 1153
#define CREATE_TABLE 1154
#define DEFAULT_NULL 1155
#define DELETE_USING 1156
#define DISPLAY_FORM 1157
#define END_FUNCTION 1158
#define EXIT_DISPLAY 1159
#define EXIT_FOREACH 1160
#define EXIT_PROGRAM 1161
#define INFCOLS 1162
#define LOCKMODEROW 1163
#define ON_EVERY_ROW 1164
#define OPEN_SESSION 1165
#define RIGHT_MARGIN 1166
#define SELECT_USING 1167
#define START_REPORT 1168
#define UNLOCK_TABLE 1169
#define UPDATE_USING 1170
#define ACL_BUILTIN 1171
#define AFTGROUP 1172
#define INFIDX 1173
#define INFSTAT 1174
#define LEFT_MARGIN 1175
#define PAGE_HEADER 1176
#define ROLLBACK_W 1177
#define SET_SESSION 1178
#define SQLSEOFF 1179
#define WITH_A_LOG 1180
#define BEFDISP 1181
#define BEFORE_MENU 1182
#define CREATE_VIEW 1183
#define DEFINE_TYPE 1184
#define DELETE_FROM 1185
#define END_DISPLAY 1186
#define END_REPORT 1187
#define END_FOREACH 1188
#define END_FOR 1189
#define END_GLOBALS 1190
#define EXIT_PROMPT 1191
#define EXTENT_SIZE 1192
#define FOREIGN_KEY 1193
#define HIDE_OPTION 1194
#define HIDE_WINDOW 1195
#define INSERT_INTO 1196
#define IS_NOT_NULL 1197
#define MOVE_WINDOW 1198
#define NEXT_OPTION 1199
#define NOT_MATCHES 1200
#define ON_LAST_ROW 1201
#define OPEN_WINDOW 1202
#define OPEN_STATUSBOX 1203
#define PAGE_LENGTH 1204
#define PAGE_WIDTH 1205
#define PRIMARY_KEY 1206
#define PROMPT_LINE 1207
#define RECORD_LIKE 1208
#define ROLLFORWARD 1209
#define SETBL 1210
#define SHOW_OPTION 1211
#define SHOW_WINDOW 1212
#define SQLSEON 1213
#define TO_DATABASE 1214
#define USE_SESSION 1215
#define WITH_NO_LOG 1216
#define AFTDISP 1217
#define BEFFIELD 1218
#define INSHARE 1219
#define UNLOCKTAB 1220
#define AFTFIELD 1221
#define ATTRIBUTES 1222
#define BEFINP 1223
#define BEGIN_WORK 1224
#define CLEARWIN 1225
#define CLOSE_FORM 1226
#define DEFER_QUIT 1227
#define DESCENDING 1228
#define DROP_INDEX 1229
#define END_PROMPT 1230
#define END_RECORD 1231
#define ERROR_LINE 1232
#define EXIT_INPUT 1233
#define EXIT_WHILE 1234
#define FOR_UPDATE_OF 1235
#define FOR_UPDATE 1236
#define GET_FLDBUF 1237
#define INITIALIZE 1238
#define INPUT_WRAP 1239
#define LOCK_TABLE 1240
#define MSG_LINE 1241
#define NOT_EXISTS 1242
#define ON_ANY_KEY 1243
#define REFERENCES 1244
#define RENCOL 1245
#define SET_CURSOR 1246
#define SMALLFLOAT 1247
#define SQLSUCCESS 1248
#define TOP_MARGIN 1249
#define WITH_ARRAY 1250
#define ACCEPTKEY 1251
#define ACCEPT 1252
#define AFTINP 1253
#define CLEARFORMTODEFAULTS 1254
#define CLEARFORM 1255
#define CLEAR_X_FORM 1256
#define COMMIT_W 1257
#define NEXTPAGE 1258
#define PREVPAGE 1259
#define CTRL_KEY 1260
#define INFTABS 1261
#define NEXTFIELD 1262
#define NEXTFORM 1263
#define RENTAB 1264
#define ASCENDING 1265
#define ASSOCIATE 1266
#define CHARACTER 1267
#define CONSTRUCT 1268
#define DELIMITER 1269
#define DOWNSHIFT 1270
#define DROP_VIEW 1271
#define END_INPUT 1272
#define END_WHILE 1273
#define EXCLUSIVE 1274
#define EXIT_CASE 1275
#define EXIT_MENU 1276
#define FORM_LINE 1277
#define INTERRUPT 1279
#define INTO_TEMP 1280
#define INVISIBLE 1281
#define IN_MEMORY 1282
#define LINKED_TO 1283
#define LOAD_FROM 1284
#define LOCKTAB 1285
#define MENU_LINE 1286
#define OPEN_FORM 1287
#define OTHERWISE 1288
#define PRECISION 1289
#define PRIOR 1290
#define PROCEDURE 1291
#define REPORT_TO 1292
#define RETURNING 1293
#define UNDERLINE 1294
#define UNLOAD_TO 1295
#define BEFROW 1296
#define UNLOAD_T 1297
#define VARIABLE 1298
#define ABSOLUTE 1299
#define AFTROW 1300
#define BUFFERED 1301
#define CONSTANT 1302
#define CONST 1303
#define CONTINUE 1304
#define DATABASE 1305
#define DATETIME 1306
#define DEFAULTS 1307
#define DISTINCT 1308
#define END_CASE 1309
#define END_MAIN 1310
#define END_MENU 1311
#define END_TYPE 1312
#define EXIT_FOR 1313
#define EXTERNAL 1314
#define FRACTION 1315
#define FUNCTION 1316
#define GROUP_BY 1317
#define INTERVAL 1318
#define KWMESSAGE 1319
#define NOT_LIKE 1320
#define NOT_NULL 1321
#define PASSWORD 1322
#define PREVIOUS 1323
#define READONLY 1324
#define REGISTER 1325
#define RELATIVE 1326
#define RESOURCE 1327
#define SMALLINT 1328
#define VALIDATE 1329
#define WHENEVER 1330
#define WITH_LOG 1331
#define WORDWRAP 1332
#define BY_NAME 1333
#define IN_FILE 1334
#define IS_NULL 1335
#define AVERAGE 1337
#define BETWEEN 1338
#define CAPTION 1339
#define CLIPPED 1340
#define CLOSE_BRACKET 1341
#define COLUMNS 1342
#define COMMENT 1344
#define CONNECT 1345
#define CURRENT 1346
#define DBYNAME 1347
#define DECIMAL 1348
#define DECLARE 1349
#define DEFAULT 1350
#define DISPLAY 1351
#define ENDCODE 1352
#define EXECUTE 1353
#define FOREACH 1354
#define FOREIGN 1355
#define GLOBALS 1356
#define INFIELD 1357
#define INTEGER 1358
#define KWWINDOW 1359
#define MAGENTA 1360
#define NUMERIC 1362
#define OPTIONS 1363
#define PERCENT 1364
#define PREPARE 1365
#define PROGRAM 1366
#define RECOVER 1367
#define REVERSE 1368
#define SECTION 1369
#define SESSION 1370
#define SYNONYM 1371
#define THRU 1372
#define TRAILER 1373
#define UPSHIFT 1374
#define VARCHAR 1375
#define WAITING 1376
#define CLOSE_SHEV 1377
#define CLOSE_SQUARE 1378
#define KW_FALSE 1380
#define NOT_IN 1381
#define ONKEY 1382
#define OPEN_BRACKET 1383
#define BORDER 1384
#define BOTTOM 1385
#define COLUMN 1386
#define COMMIT 1387
#define CREATE 1388
#define CURSOR 1389
#define DEFINE 1390
#define DELETE 1391
#define DOUBLE 1392
#define END_IF 1393
#define ESCAPE 1394
#define EXISTS 1395
#define EXTEND 1396
#define EXTENT 1397
#define FINISH 1398
#define FORMAT 1399
#define HAVING 1400
#define HEADER 1401
#define INSERT 1402
#define LOCATE 1403
#define MARGIN 1404
#define MEMORY 1405
#define MINUTE 1406
#define MODIFY 1407
#define NORMAL 1408
#define EQUAL_EQUAL 1409
#define OPEN_SHEV 1411
#define OPEN_SQUARE 1412
#define OPTION 1413
#define OUTPUT 1414
#define PROMPT 1415
#define PUBLIC 1416
#define RECORD 1417
#define REPORT 1418
#define RETURN 1419
#define REVOKE 1420
#define SCHEMA 1421
#define SCROLL_USING 1422
#define SCROLL 1423
#define SECOND 1424
#define SELECT 1425
#define SERIAL 1426
#define SETL 1427
#define SHARED 1428
#define SPACES 1429
#define UNIQUE 1430
#define UNLOCK 1431
#define UPDATE 1432
#define VALUES 1433
#define YELLOW 1434
#define AFTER 1435
#define KWLINE 1436
#define KW_NULL 1437
#define KW_TRUE 1438
#define SINGLE_KEY 1439
#define ALTER 1440
#define ARRAY 1441
#define ASCII 1442
#define AUDIT 1443
#define BLACK 1444
#define BLINK 1445
#define CHECK 1446
#define CLEAR 1447
#define CLOSE 1448
#define CODE_C 1449
#define COUNT 1450
#define DEFER 1451
#define ERROR 1452
#define EVERY 1453
#define FETCH 1454
#define FIRST 1455
#define FLOAT 1456
#define FLUSH 1457
#define FOUND 1458
#define GRANT 1459
#define GREEN 1460
#define GROUP 1461
#define INDEX 1462
#define KWFORM 1463
#define LABEL 1464
#define LOCAL 1466
#define MONEY 1467
#define MONTH 1468
#define ORDER 1471
#define OUTER 1472
#define PAUSE 1473
#define PRINT_IMAGE 1474
#define PRINT_FILE 1475
#define PRINT 1476
#define RIGHT 1477
#define DOUBLE_COLON 1478
#define SEMICOLON 1479
#define SLEEP 1480
#define TUPLE 1481
#define UNION 1482
#define WHERE 1484
#define WHILE 1485
#define WHITE 1486
#define CCODE 1487
#define ANSI 1488
#define BLUE 1489
#define BOLD 1490
#define BYTE 1491
#define FCALL 1492
#define CASE 1493
#define CHAR 1494
#define CYAN 1495
#define DATE 1496
#define DESC 1497
#define DOWN 1499
#define TAB 1500
#define DROP 1501
#define ELSE 1502
#define EXEC 1503
#define EXIT 1504
#define FREE 1505
#define FROM 1506
#define GOTO 1507
#define HELP_FILE 1508
#define LANG_FILE 1509
#define HELP 1510
#define HIDE 1511
#define HOUR 1512
#define INTO 1513
#define LAST 1514
#define LEFT 1515
#define LIKE 1516
#define MAIN 1517
#define MENU 1518
#define MODE 1519
#define NEED 1520
#define NEXT 1521
#define NOCR 1522
#define OPEN 1523
#define QUIT 1524
#define REAL 1525
#define ROWS 1526
#define SHOW 1527
#define SIZE 1528
#define SKIP 1529
#define SOME 1530
#define STEP 1531
#define STOP 1532
#define TEMP 1533
#define TEXT 1534
#define THEN 1535
#define USER 1536
#define WAIT 1537
#define WHEN 1538
#define WITH 1539
#define WORK 1540
#define YEAR 1541
#define KW_IS 1543
#define XSET 1544
#define ADD 1545
#define ALL 1546
#define ANY 1548
#define ASC 1549
#define AVG 1550
#define COLON 1551
#define DAY 1553
#define DBA 1554
#define DEC 1555
#define DIM 1556
#define FKEY 1557
#define FOR 1558
#define KEY 1559
#define KWNO 1560
#define LET 1561
#define LOG 1562
#define XMAX 1563
#define XMIN 1564
#define NOT 1567
#define PAD 1568
#define PUT 1569
#define RED 1570
#define ROW 1571
#define RUN 1572
#define SQL 1573
#define SUM 1574
#define TOP 1575
#define USE 1576
#define ATSIGN 1577
#define AS_TIFF 1579
#define AS_GIF 1580
#define AS_PNG 1581
#define AS_JPEG 1582
#define AS 1583
#define AT 1584
#define BY 1585
#define DOT 1586
#define GO 1587
#define IF 1588
#define IN 1589
#define OF 1590
#define ON 1591
#define TO 1593
#define UP 1594
#define FONT_NAME 1595
#define FONT_SIZE 1596
#define PAPER_SIZE_IS_LETTER 1597
#define PAPER_SIZE_IS_LEGAL 1598
#define PAPER_SIZE_IS_A5 1599
#define PAPER_SIZE_IS_A4 1600
#define PAPER_SIZE_IS_LETTER_L 1601
#define PAPER_SIZE_IS_LEGAL_L 1602
#define PAPER_SIZE_IS_A5_L 1603
#define PAPER_SIZE_IS_A4_L 1604
#define FORMHANDLER 1605
#define END_FORMHANDLER 1606
#define BEFORE_EVENT 1607
#define BEFORE_OPEN_FORM 1608
#define AFTER_EVENT 1609
#define BEFORE_CLOSE_FORM 1610
#define BEFORE_ANY 1611
#define AFTER_ANY 1612
#define MENUHANDLER 1613
#define END_MENUHANDLER 1614
#define BEFORE_SHOW_MENU 1615
#define DISABLE_PROGRAM 1616
#define DISABLE_ALL 1617
#define BUTTONS 1618
#define CHECK_MENUITEM 1619
#define DISABLE_FORM 1620
#define DISABLE_MENUITEMS 1621
#define DISABLE 1622
#define ENABLE_FORM 1623
#define ENABLE_MENUITEMS 1624
#define ENABLE 1625
#define KWFIELD 1626
#define ICON 1627
#define MESSAGEBOX 1628
#define TO_DEFAULTS 1629
#define UNCHECK_MENUITEM 1630
#define BEFORE 1631
#define INPUT 1632
#define END 1633
#define INT_TO_ID 1634




#if ! defined (YYSTYPE) && ! defined (YYSTYPE_IS_DECLARED)
#line 195 "fgl.yacc"
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
#line 1354 "y.tab.h"
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif





