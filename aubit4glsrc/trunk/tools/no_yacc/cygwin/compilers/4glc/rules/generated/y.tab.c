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



/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     NAME = 1633,
     UMINUS = 1634,
     COMMA = 1549,
     KW_OR = 1589,
     KW_AND = 1544,
     KW_USING = 1480,
     MATCHES = 1359,
     POWER = 1467,
     LESS_THAN = 1463,
     GREATER_THAN = 1377,
     EQUAL = 1539,
     GREATER_THAN_EQ = 1276,
     LESS_THAN_EQ = 1334,
     NOT_EQUAL = 1408,
     PLUS = 1575,
     MINUS = 1562,
     DIVIDE = 1495,
     MULTIPLY = 1468,
     MOD = 1563,
     COMMAND = 1341,
     NUMBER_VALUE = 1635,
     CHAR_VALUE = 1636,
     INT_VALUE = 1637,
     NAMED_GEN = 1638,
     CLINE = 1639,
     SQLLINE = 1640,
     KW_CSTART = 1641,
     KW_CEND = 1642,
     USER_DTYPE = 1643,
     SQL_TEXT = 1644,
     ALTER_TABLE = 1000,
     CREATE_DATABASE = 1001,
     ADD_CONSTRAINT = 1002,
     DROP_CONSTRAINT = 1003,
     AS_STATIC = 1004,
     NOT_FIELD_TOUCHED = 1005,
     LOCAL_FUNCTION = 1006,
     EVERY_ROW = 1007,
     ELIF = 1008,
     DOUBLE_PRECISION = 1009,
     COUNT_MULTIPLY = 1010,
     NEWFORMATSHARED = 1011,
     WAIT_FOR_KEY = 1012,
     AT_TERMINATION_CALL = 1013,
     TO_MAIN_CAPTION = 1014,
     CLEARSTAT = 1015,
     TO_MENUITEM = 1016,
     ID_TO_INT = 1017,
     TO_STATUSBOX = 1018,
     ASCII_HEIGHT_ALL = 1019,
     ASCII_WIDTH_ALL = 1020,
     IMPORT_DATATYPE = 1021,
     UP_BY = 1022,
     PAGE_TRAILER_SIZE = 1023,
     PAGE_HEADER_SIZE = 1024,
     FIRST_PAGE_HEADER_SIZE = 1025,
     BYTES_USE_AS_IMAGE = 1026,
     BYTES_USE_AS_ASCII = 1027,
     DOWN_BY = 1028,
     CLOSE_STATUSBOX = 1029,
     MODIFY_NEXT_SIZE = 1030,
     LOCK_MODE_PAGE = 1031,
     LOCK_MODE_ROW = 1032,
     TO_PIPE = 1033,
     TO_PRINTER = 1034,
     STATUSBOX = 1035,
     CONNECT_TO = 1036,
     FORMHANDLER_INPUT = 1037,
     UNITS_YEAR = 1038,
     UNITS_MONTH = 1039,
     UNITS_DAY = 1040,
     UNITS_HOUR = 1041,
     UNITS_MINUTE = 1042,
     UNITS_SECOND = 1043,
     NO_NEW_LINES = 1044,
     FIELDTOWIDGET = 1045,
     WITH_HOLD = 1046,
     SHOW_MENU = 1047,
     CWIS = 1048,
     CREATE_IDX = 1049,
     FORM_IS_COMPILED = 1050,
     PDF_REPORT = 1051,
     IMPORT_FUNCTION = 1052,
     PROMPT_MANY = 1053,
     POINTS = 1054,
     MM = 1055,
     INCHES = 1056,
     PREPEND = 1057,
     MEMBER_OF = 1058,
     MEMBER_FUNCTION = 1059,
     APPEND = 1060,
     TEMPLATE = 1061,
     END_TEMPLATE = 1062,
     SQLSICS = 1063,
     CREATE_SCHEMA = 1064,
     SQLSIRR = 1065,
     UPDATESTATS_T = 1066,
     SQLSICR = 1067,
     WHENEVER_SQLSUCCESS = 1068,
     WHENEVER_SQLWARNING = 1069,
     START_EXTERN = 1070,
     WHENEVER_ANY_ERROR = 1071,
     WHENEVER_NOT_FOUND = 1072,
     CONTINUE_CONSTRUCT = 1073,
     FOUNCONSTR = 1074,
     SQLSIDR = 1075,
     WHENEVER_SQLERROR = 1076,
     CREATE_TEMP_TABLE = 1077,
     CURRENT_WINDOW_IS = 1078,
     FIRST_PAGE_HEADER = 1079,
     ORDER_EXTERNAL_BY = 1080,
     SCROLL_CURSOR_FOR = 1081,
     SCROLL_CURSOR = 1082,
     SQL_INTERRUPT_OFF = 1083,
     STOP_ALL_EXTERNAL = 1084,
     WITH_CHECK_OPTION = 1085,
     WITH_GRANT_OPTION = 1086,
     SQLSLMNW = 1087,
     ADDCONSTUNIQ = 1088,
     CONTINUE_DISPLAY = 1089,
     CONTINUE_FOREACH = 1090,
     OUTPUT_TO_REPORT = 1091,
     SQL_INTERRUPT_ON = 1092,
     WHENEVER_SUCCESS = 1093,
     WHENEVER_WARNING = 1094,
     WHERE_CURRENT_OF = 1095,
     WITHOUT_DEFAULTS = 1096,
     FOCONSTR = 1097,
     SCALED_BY = 1098,
     CONTINUE_PROMPT = 1099,
     PDF_FUNCTION = 1100,
     DEFER_INTERRUPT = 1101,
     DISPLAY_BY_NAME = 1102,
     NOT_NULL_UNIQUE = 1103,
     SKIP_TO_TOP = 1104,
     TOP_OF_PAGE = 1105,
     SKIP_TO = 1106,
     SKIP_BY = 1107,
     WITHOUT_WAITING = 1108,
     BEFCONSTRUCT = 1109,
     SQLSLMW = 1110,
     WHENEVER_ERROR_CONTINUE = 1111,
     WHENEVER_ERROR = 1112,
     AFTCONSTRUCT = 1113,
     ALL_PRIVILEGES = 1114,
     CLOSE_DATABASE = 1115,
     CONTINUE_INPUT = 1116,
     CONTINUE_WHILE = 1117,
     CREATE_SYNONYM = 1118,
     DROP_TABLE = 1119,
     EXIT_CONSTRUCT = 1120,
     INEXCLUSIVE = 1121,
     REPORT_TO_PRINTER = 1122,
     REPORT_TO_PIPE = 1123,
     SET_SESSION_TO = 1124,
     UPDATESTATS = 1125,
     WITHOUT_HEAD = 1126,
     CLEARSCR = 1127,
     WITH_B_LOG = 1128,
     AUTHORIZATION = 1129,
     BOTTOM_MARGIN = 1130,
     CLOSE_SESSION = 1131,
     CONTINUE_CASE = 1132,
     CONTINUE_MENU = 1133,
     DISPLAY_ARRAY = 1134,
     END_SQL = 1135,
     DOLLAR = 1136,
     END_CONSTRUCT = 1137,
     FIELD_TOUCHED = 1138,
     FINISH_REPORT = 1139,
     INFACC = 1140,
     INPUT_NO_WRAP = 1141,
     LOCKMODEPAGE = 1142,
     SETPMOFF = 1143,
     UNCONSTRAINED = 1144,
     PAGE_TRAILER = 1145,
     SETPMON = 1146,
     BEFGROUP = 1147,
     CLOSE_WINDOW = 1148,
     COMMENT_LINE = 1149,
     CONTINUE_FOR = 1150,
     CREATE_DB = 1151,
     CREATE_TABLE = 1152,
     DEFAULT_NULL = 1153,
     DELETE_USING = 1154,
     DISPLAY_FORM = 1155,
     END_FUNCTION = 1156,
     EXIT_DISPLAY = 1157,
     EXIT_FOREACH = 1158,
     EXIT_PROGRAM = 1159,
     INFCOLS = 1160,
     LOCKMODEROW = 1161,
     ON_EVERY_ROW = 1162,
     OPEN_SESSION = 1163,
     RIGHT_MARGIN = 1164,
     SELECT_USING = 1165,
     START_REPORT = 1166,
     UNLOCK_TABLE = 1167,
     UPDATE_USING = 1168,
     ACL_BUILTIN = 1169,
     AFTGROUP = 1170,
     INFIDX = 1171,
     INFSTAT = 1172,
     LEFT_MARGIN = 1173,
     PAGE_HEADER = 1174,
     ROLLBACK_W = 1175,
     SET_SESSION = 1176,
     SQLSEOFF = 1177,
     WITH_A_LOG = 1178,
     BEFDISP = 1179,
     BEFORE_MENU = 1180,
     CREATE_VIEW = 1181,
     DEFINE_TYPE = 1182,
     DELETE_FROM = 1183,
     END_DISPLAY = 1184,
     END_REPORT = 1185,
     END_FOREACH = 1186,
     END_FOR = 1187,
     END_GLOBALS = 1188,
     EXIT_PROMPT = 1189,
     EXTENT_SIZE = 1190,
     FOREIGN_KEY = 1191,
     HIDE_OPTION = 1192,
     HIDE_WINDOW = 1193,
     INSERT_INTO = 1194,
     IS_NOT_NULL = 1195,
     MOVE_WINDOW = 1196,
     NEXT_OPTION = 1197,
     NOT_MATCHES = 1198,
     ON_LAST_ROW = 1199,
     OPEN_WINDOW = 1200,
     OPEN_STATUSBOX = 1201,
     PAGE_LENGTH = 1202,
     PAGE_WIDTH = 1203,
     PRIMARY_KEY = 1204,
     PROMPT_LINE = 1205,
     RECORD_LIKE = 1206,
     ROLLFORWARD = 1207,
     SETBL = 1208,
     SHOW_OPTION = 1209,
     SHOW_WINDOW = 1210,
     SQLSEON = 1211,
     TO_DATABASE = 1212,
     USE_SESSION = 1213,
     WITH_NO_LOG = 1214,
     AFTDISP = 1215,
     BEFFIELD = 1216,
     INSHARE = 1217,
     UNLOCKTAB = 1218,
     AFTFIELD = 1219,
     ATTRIBUTES = 1220,
     BEFINP = 1221,
     BEGIN_WORK = 1222,
     CLEARWIN = 1223,
     CLOSE_FORM = 1224,
     DEFER_QUIT = 1225,
     DESCENDING = 1226,
     DROP_INDEX = 1227,
     END_PROMPT = 1228,
     END_RECORD = 1229,
     ERROR_LINE = 1230,
     EXIT_INPUT = 1231,
     EXIT_WHILE = 1232,
     FOR_UPDATE_OF = 1233,
     FOR_UPDATE = 1234,
     GET_FLDBUF = 1235,
     INITIALIZE = 1236,
     INPUT_WRAP = 1237,
     LOCK_TABLE = 1238,
     MSG_LINE = 1239,
     NOT_EXISTS = 1240,
     ON_ANY_KEY = 1241,
     REFERENCES = 1242,
     RENCOL = 1243,
     SET_CURSOR = 1244,
     SMALLFLOAT = 1245,
     SQLSUCCESS = 1246,
     TOP_MARGIN = 1247,
     WITH_ARRAY = 1248,
     ACCEPTKEY = 1249,
     ACCEPT = 1250,
     AFTINP = 1251,
     CLEARFORMTODEFAULTS = 1252,
     CLEARFORM = 1253,
     CLEAR_X_FORM = 1254,
     COMMIT_W = 1255,
     NEXTPAGE = 1256,
     PREVPAGE = 1257,
     CTRL_KEY = 1258,
     INFTABS = 1259,
     NEXTFIELD = 1260,
     NEXTFORM = 1261,
     RENTAB = 1262,
     ASCENDING = 1263,
     ASSOCIATE = 1264,
     CHARACTER = 1265,
     CONSTRUCT = 1266,
     DELIMITER = 1267,
     DOWNSHIFT = 1268,
     DROP_VIEW = 1269,
     END_INPUT = 1270,
     END_WHILE = 1271,
     EXCLUSIVE = 1272,
     EXIT_CASE = 1273,
     EXIT_MENU = 1274,
     FORM_LINE = 1275,
     INTERRUPT = 1277,
     INTO_TEMP = 1278,
     INVISIBLE = 1279,
     IN_MEMORY = 1280,
     LINKED_TO = 1281,
     LOAD_FROM = 1282,
     LOCKTAB = 1283,
     MENU_LINE = 1284,
     OPEN_FORM = 1285,
     OTHERWISE = 1286,
     PRECISION = 1287,
     PRIOR = 1288,
     PROCEDURE = 1289,
     REPORT_TO = 1290,
     RETURNING = 1291,
     UNDERLINE = 1292,
     UNLOAD_TO = 1293,
     BEFROW = 1294,
     UNLOAD_T = 1295,
     VARIABLE = 1296,
     ABSOLUTE = 1297,
     AFTROW = 1298,
     BUFFERED = 1299,
     CONSTANT = 1300,
     CONST = 1301,
     CONTINUE = 1302,
     DATABASE = 1303,
     DATETIME = 1304,
     DEFAULTS = 1305,
     DISTINCT = 1306,
     END_CASE = 1307,
     END_MAIN = 1308,
     END_MENU = 1309,
     END_TYPE = 1310,
     EXIT_FOR = 1311,
     EXTERNAL = 1312,
     FRACTION = 1313,
     FUNCTION = 1314,
     GROUP_BY = 1315,
     INTERVAL = 1316,
     KWMESSAGE = 1317,
     NOT_LIKE = 1318,
     NOT_NULL = 1319,
     PASSWORD = 1320,
     PREVIOUS = 1321,
     READONLY = 1322,
     REGISTER = 1323,
     RELATIVE = 1324,
     RESOURCE = 1325,
     SMALLINT = 1326,
     VALIDATE = 1327,
     WHENEVER = 1328,
     WITH_LOG = 1329,
     WORDWRAP = 1330,
     BY_NAME = 1331,
     IN_FILE = 1332,
     IS_NULL = 1333,
     AVERAGE = 1335,
     BETWEEN = 1336,
     CAPTION = 1337,
     CLIPPED = 1338,
     CLOSE_BRACKET = 1339,
     COLUMNS = 1340,
     COMMENT = 1342,
     CONNECT = 1343,
     CURRENT = 1344,
     DBYNAME = 1345,
     DECIMAL = 1346,
     DECLARE = 1347,
     DEFAULT = 1348,
     DISPLAY = 1349,
     ENDCODE = 1350,
     EXECUTE = 1351,
     FOREACH = 1352,
     FOREIGN = 1353,
     GLOBALS = 1354,
     INFIELD = 1355,
     INTEGER = 1356,
     KWWINDOW = 1357,
     MAGENTA = 1358,
     NUMERIC = 1360,
     OPTIONS = 1361,
     PERCENT = 1362,
     PREPARE = 1363,
     PROGRAM = 1364,
     RECOVER = 1365,
     REVERSE = 1366,
     SECTION = 1367,
     SESSION = 1368,
     SYNONYM = 1369,
     THRU = 1370,
     TRAILER = 1371,
     UPSHIFT = 1372,
     VARCHAR = 1373,
     WAITING = 1374,
     CLOSE_SHEV = 1375,
     CLOSE_SQUARE = 1376,
     KW_FALSE = 1378,
     NOT_IN = 1379,
     ONKEY = 1380,
     OPEN_BRACKET = 1381,
     BORDER = 1382,
     BOTTOM = 1383,
     COLUMN = 1384,
     COMMIT = 1385,
     CREATE = 1386,
     CURSOR = 1387,
     DEFINE = 1388,
     DELETE = 1389,
     DOUBLE = 1390,
     END_IF = 1391,
     ESCAPE = 1392,
     EXISTS = 1393,
     EXTEND = 1394,
     EXTENT = 1395,
     FINISH = 1396,
     FORMAT = 1397,
     HAVING = 1398,
     HEADER = 1399,
     INSERT = 1400,
     LOCATE = 1401,
     MARGIN = 1402,
     MEMORY = 1403,
     MINUTE = 1404,
     MODIFY = 1405,
     NORMAL = 1406,
     EQUAL_EQUAL = 1407,
     OPEN_SHEV = 1409,
     OPEN_SQUARE = 1410,
     OPTION = 1411,
     OUTPUT = 1412,
     PROMPT = 1413,
     PUBLIC = 1414,
     RECORD = 1415,
     REPORT = 1416,
     RETURN = 1417,
     REVOKE = 1418,
     SCHEMA = 1419,
     SCROLL_USING = 1420,
     SCROLL = 1421,
     SECOND = 1422,
     SELECT = 1423,
     SERIAL = 1424,
     SETL = 1425,
     SHARED = 1426,
     SPACES = 1427,
     UNIQUE = 1428,
     UNLOCK = 1429,
     UPDATE = 1430,
     VALUES = 1431,
     YELLOW = 1432,
     AFTER = 1433,
     KWLINE = 1434,
     KW_NULL = 1435,
     KW_TRUE = 1436,
     SINGLE_KEY = 1437,
     ALTER = 1438,
     ARRAY = 1439,
     ASCII = 1440,
     AUDIT = 1441,
     BLACK = 1442,
     BLINK = 1443,
     CHECK = 1444,
     CLEAR = 1445,
     CLOSE = 1446,
     CODE_C = 1447,
     COUNT = 1448,
     DEFER = 1449,
     ERROR = 1450,
     EVERY = 1451,
     FETCH = 1452,
     FIRST = 1453,
     FLOAT = 1454,
     FLUSH = 1455,
     FOUND = 1456,
     GRANT = 1457,
     GREEN = 1458,
     GROUP = 1459,
     INDEX = 1460,
     KWFORM = 1461,
     LABEL = 1462,
     LOCAL = 1464,
     MONEY = 1465,
     MONTH = 1466,
     ORDER = 1469,
     OUTER = 1470,
     PAUSE = 1471,
     PRINT_IMAGE = 1472,
     PRINT_FILE = 1473,
     PRINT = 1474,
     RIGHT = 1475,
     SEMICOLON = 1476,
     SLEEP = 1477,
     TUPLE = 1478,
     UNION = 1479,
     WHERE = 1481,
     WHILE = 1482,
     WHITE = 1483,
     CCODE = 1484,
     ANSI = 1485,
     BLUE = 1486,
     BOLD = 1487,
     BYTE = 1488,
     FCALL = 1489,
     CASE = 1490,
     CHAR = 1491,
     CYAN = 1492,
     DATE = 1493,
     DESC = 1494,
     DOWN = 1496,
     TAB = 1497,
     DROP = 1498,
     ELSE = 1499,
     EXEC = 1500,
     EXIT = 1501,
     FREE = 1502,
     FROM = 1503,
     GOTO = 1504,
     HELP_FILE = 1505,
     LANG_FILE = 1506,
     HELP = 1507,
     HIDE = 1508,
     HOUR = 1509,
     INTO = 1510,
     LAST = 1511,
     LEFT = 1512,
     LIKE = 1513,
     MAIN = 1514,
     MENU = 1515,
     MODE = 1516,
     NEED = 1517,
     NEXT = 1518,
     NOCR = 1519,
     OPEN = 1520,
     QUIT = 1521,
     REAL = 1522,
     ROWS = 1523,
     SHOW = 1524,
     SIZE = 1525,
     SKIP = 1526,
     SOME = 1527,
     STEP = 1528,
     STOP = 1529,
     TEMP = 1530,
     TEXT = 1531,
     THEN = 1532,
     USER = 1533,
     WAIT = 1534,
     WHEN = 1535,
     WITH = 1536,
     WORK = 1537,
     YEAR = 1538,
     KW_IS = 1540,
     XSET = 1541,
     ADD = 1542,
     ALL = 1543,
     ANY = 1545,
     ASC = 1546,
     AVG = 1547,
     COLON = 1548,
     DAY = 1550,
     DBA = 1551,
     DEC = 1552,
     DIM = 1553,
     FKEY = 1554,
     FOR = 1555,
     KEY = 1556,
     KWNO = 1557,
     LET = 1558,
     LOG = 1559,
     XMAX = 1560,
     XMIN = 1561,
     NOT = 1564,
     PAD = 1565,
     PUT = 1566,
     RED = 1567,
     ROW = 1568,
     RUN = 1569,
     SQL = 1570,
     SUM = 1571,
     TOP = 1572,
     USE = 1573,
     ATSIGN = 1574,
     AS_TIFF = 1576,
     AS_GIF = 1577,
     AS_PNG = 1578,
     AS_JPEG = 1579,
     AS = 1580,
     AT = 1581,
     BY = 1582,
     DOT = 1583,
     GO = 1584,
     IF = 1585,
     IN = 1586,
     OF = 1587,
     ON = 1588,
     TO = 1590,
     UP = 1591,
     FONT_NAME = 1592,
     FONT_SIZE = 1593,
     PAPER_SIZE_IS_LETTER = 1594,
     PAPER_SIZE_IS_LEGAL = 1595,
     PAPER_SIZE_IS_A5 = 1596,
     PAPER_SIZE_IS_A4 = 1597,
     PAPER_SIZE_IS_LETTER_L = 1598,
     PAPER_SIZE_IS_LEGAL_L = 1599,
     PAPER_SIZE_IS_A5_L = 1600,
     PAPER_SIZE_IS_A4_L = 1601,
     FORMHANDLER = 1602,
     END_FORMHANDLER = 1603,
     BEFORE_EVENT = 1604,
     BEFORE_OPEN_FORM = 1605,
     AFTER_EVENT = 1606,
     BEFORE_CLOSE_FORM = 1607,
     BEFORE_ANY = 1608,
     AFTER_ANY = 1609,
     MENUHANDLER = 1610,
     END_MENUHANDLER = 1611,
     BEFORE_SHOW_MENU = 1612,
     DISABLE_PROGRAM = 1613,
     DISABLE_ALL = 1614,
     BUTTONS = 1615,
     CHECK_MENUITEM = 1616,
     DISABLE_FORM = 1617,
     DISABLE_MENUITEMS = 1618,
     DISABLE = 1619,
     ENABLE_FORM = 1620,
     ENABLE_MENUITEMS = 1621,
     ENABLE = 1622,
     KWFIELD = 1623,
     ICON = 1624,
     MESSAGEBOX = 1625,
     TO_DEFAULTS = 1626,
     UNCHECK_MENUITEM = 1627,
     BEFORE = 1628,
     INPUT = 1629,
     END = 1630,
     INT_TO_ID = 1631
   };
#endif
#define NAME 1633
#define UMINUS 1634
#define COMMA 1549
#define KW_OR 1589
#define KW_AND 1544
#define KW_USING 1480
#define MATCHES 1359
#define POWER 1467
#define LESS_THAN 1463
#define GREATER_THAN 1377
#define EQUAL 1539
#define GREATER_THAN_EQ 1276
#define LESS_THAN_EQ 1334
#define NOT_EQUAL 1408
#define PLUS 1575
#define MINUS 1562
#define DIVIDE 1495
#define MULTIPLY 1468
#define MOD 1563
#define COMMAND 1341
#define NUMBER_VALUE 1635
#define CHAR_VALUE 1636
#define INT_VALUE 1637
#define NAMED_GEN 1638
#define CLINE 1639
#define SQLLINE 1640
#define KW_CSTART 1641
#define KW_CEND 1642
#define USER_DTYPE 1643
#define SQL_TEXT 1644
#define ALTER_TABLE 1000
#define CREATE_DATABASE 1001
#define ADD_CONSTRAINT 1002
#define DROP_CONSTRAINT 1003
#define AS_STATIC 1004
#define NOT_FIELD_TOUCHED 1005
#define LOCAL_FUNCTION 1006
#define EVERY_ROW 1007
#define ELIF 1008
#define DOUBLE_PRECISION 1009
#define COUNT_MULTIPLY 1010
#define NEWFORMATSHARED 1011
#define WAIT_FOR_KEY 1012
#define AT_TERMINATION_CALL 1013
#define TO_MAIN_CAPTION 1014
#define CLEARSTAT 1015
#define TO_MENUITEM 1016
#define ID_TO_INT 1017
#define TO_STATUSBOX 1018
#define ASCII_HEIGHT_ALL 1019
#define ASCII_WIDTH_ALL 1020
#define IMPORT_DATATYPE 1021
#define UP_BY 1022
#define PAGE_TRAILER_SIZE 1023
#define PAGE_HEADER_SIZE 1024
#define FIRST_PAGE_HEADER_SIZE 1025
#define BYTES_USE_AS_IMAGE 1026
#define BYTES_USE_AS_ASCII 1027
#define DOWN_BY 1028
#define CLOSE_STATUSBOX 1029
#define MODIFY_NEXT_SIZE 1030
#define LOCK_MODE_PAGE 1031
#define LOCK_MODE_ROW 1032
#define TO_PIPE 1033
#define TO_PRINTER 1034
#define STATUSBOX 1035
#define CONNECT_TO 1036
#define FORMHANDLER_INPUT 1037
#define UNITS_YEAR 1038
#define UNITS_MONTH 1039
#define UNITS_DAY 1040
#define UNITS_HOUR 1041
#define UNITS_MINUTE 1042
#define UNITS_SECOND 1043
#define NO_NEW_LINES 1044
#define FIELDTOWIDGET 1045
#define WITH_HOLD 1046
#define SHOW_MENU 1047
#define CWIS 1048
#define CREATE_IDX 1049
#define FORM_IS_COMPILED 1050
#define PDF_REPORT 1051
#define IMPORT_FUNCTION 1052
#define PROMPT_MANY 1053
#define POINTS 1054
#define MM 1055
#define INCHES 1056
#define PREPEND 1057
#define MEMBER_OF 1058
#define MEMBER_FUNCTION 1059
#define APPEND 1060
#define TEMPLATE 1061
#define END_TEMPLATE 1062
#define SQLSICS 1063
#define CREATE_SCHEMA 1064
#define SQLSIRR 1065
#define UPDATESTATS_T 1066
#define SQLSICR 1067
#define WHENEVER_SQLSUCCESS 1068
#define WHENEVER_SQLWARNING 1069
#define START_EXTERN 1070
#define WHENEVER_ANY_ERROR 1071
#define WHENEVER_NOT_FOUND 1072
#define CONTINUE_CONSTRUCT 1073
#define FOUNCONSTR 1074
#define SQLSIDR 1075
#define WHENEVER_SQLERROR 1076
#define CREATE_TEMP_TABLE 1077
#define CURRENT_WINDOW_IS 1078
#define FIRST_PAGE_HEADER 1079
#define ORDER_EXTERNAL_BY 1080
#define SCROLL_CURSOR_FOR 1081
#define SCROLL_CURSOR 1082
#define SQL_INTERRUPT_OFF 1083
#define STOP_ALL_EXTERNAL 1084
#define WITH_CHECK_OPTION 1085
#define WITH_GRANT_OPTION 1086
#define SQLSLMNW 1087
#define ADDCONSTUNIQ 1088
#define CONTINUE_DISPLAY 1089
#define CONTINUE_FOREACH 1090
#define OUTPUT_TO_REPORT 1091
#define SQL_INTERRUPT_ON 1092
#define WHENEVER_SUCCESS 1093
#define WHENEVER_WARNING 1094
#define WHERE_CURRENT_OF 1095
#define WITHOUT_DEFAULTS 1096
#define FOCONSTR 1097
#define SCALED_BY 1098
#define CONTINUE_PROMPT 1099
#define PDF_FUNCTION 1100
#define DEFER_INTERRUPT 1101
#define DISPLAY_BY_NAME 1102
#define NOT_NULL_UNIQUE 1103
#define SKIP_TO_TOP 1104
#define TOP_OF_PAGE 1105
#define SKIP_TO 1106
#define SKIP_BY 1107
#define WITHOUT_WAITING 1108
#define BEFCONSTRUCT 1109
#define SQLSLMW 1110
#define WHENEVER_ERROR_CONTINUE 1111
#define WHENEVER_ERROR 1112
#define AFTCONSTRUCT 1113
#define ALL_PRIVILEGES 1114
#define CLOSE_DATABASE 1115
#define CONTINUE_INPUT 1116
#define CONTINUE_WHILE 1117
#define CREATE_SYNONYM 1118
#define DROP_TABLE 1119
#define EXIT_CONSTRUCT 1120
#define INEXCLUSIVE 1121
#define REPORT_TO_PRINTER 1122
#define REPORT_TO_PIPE 1123
#define SET_SESSION_TO 1124
#define UPDATESTATS 1125
#define WITHOUT_HEAD 1126
#define CLEARSCR 1127
#define WITH_B_LOG 1128
#define AUTHORIZATION 1129
#define BOTTOM_MARGIN 1130
#define CLOSE_SESSION 1131
#define CONTINUE_CASE 1132
#define CONTINUE_MENU 1133
#define DISPLAY_ARRAY 1134
#define END_SQL 1135
#define DOLLAR 1136
#define END_CONSTRUCT 1137
#define FIELD_TOUCHED 1138
#define FINISH_REPORT 1139
#define INFACC 1140
#define INPUT_NO_WRAP 1141
#define LOCKMODEPAGE 1142
#define SETPMOFF 1143
#define UNCONSTRAINED 1144
#define PAGE_TRAILER 1145
#define SETPMON 1146
#define BEFGROUP 1147
#define CLOSE_WINDOW 1148
#define COMMENT_LINE 1149
#define CONTINUE_FOR 1150
#define CREATE_DB 1151
#define CREATE_TABLE 1152
#define DEFAULT_NULL 1153
#define DELETE_USING 1154
#define DISPLAY_FORM 1155
#define END_FUNCTION 1156
#define EXIT_DISPLAY 1157
#define EXIT_FOREACH 1158
#define EXIT_PROGRAM 1159
#define INFCOLS 1160
#define LOCKMODEROW 1161
#define ON_EVERY_ROW 1162
#define OPEN_SESSION 1163
#define RIGHT_MARGIN 1164
#define SELECT_USING 1165
#define START_REPORT 1166
#define UNLOCK_TABLE 1167
#define UPDATE_USING 1168
#define ACL_BUILTIN 1169
#define AFTGROUP 1170
#define INFIDX 1171
#define INFSTAT 1172
#define LEFT_MARGIN 1173
#define PAGE_HEADER 1174
#define ROLLBACK_W 1175
#define SET_SESSION 1176
#define SQLSEOFF 1177
#define WITH_A_LOG 1178
#define BEFDISP 1179
#define BEFORE_MENU 1180
#define CREATE_VIEW 1181
#define DEFINE_TYPE 1182
#define DELETE_FROM 1183
#define END_DISPLAY 1184
#define END_REPORT 1185
#define END_FOREACH 1186
#define END_FOR 1187
#define END_GLOBALS 1188
#define EXIT_PROMPT 1189
#define EXTENT_SIZE 1190
#define FOREIGN_KEY 1191
#define HIDE_OPTION 1192
#define HIDE_WINDOW 1193
#define INSERT_INTO 1194
#define IS_NOT_NULL 1195
#define MOVE_WINDOW 1196
#define NEXT_OPTION 1197
#define NOT_MATCHES 1198
#define ON_LAST_ROW 1199
#define OPEN_WINDOW 1200
#define OPEN_STATUSBOX 1201
#define PAGE_LENGTH 1202
#define PAGE_WIDTH 1203
#define PRIMARY_KEY 1204
#define PROMPT_LINE 1205
#define RECORD_LIKE 1206
#define ROLLFORWARD 1207
#define SETBL 1208
#define SHOW_OPTION 1209
#define SHOW_WINDOW 1210
#define SQLSEON 1211
#define TO_DATABASE 1212
#define USE_SESSION 1213
#define WITH_NO_LOG 1214
#define AFTDISP 1215
#define BEFFIELD 1216
#define INSHARE 1217
#define UNLOCKTAB 1218
#define AFTFIELD 1219
#define ATTRIBUTES 1220
#define BEFINP 1221
#define BEGIN_WORK 1222
#define CLEARWIN 1223
#define CLOSE_FORM 1224
#define DEFER_QUIT 1225
#define DESCENDING 1226
#define DROP_INDEX 1227
#define END_PROMPT 1228
#define END_RECORD 1229
#define ERROR_LINE 1230
#define EXIT_INPUT 1231
#define EXIT_WHILE 1232
#define FOR_UPDATE_OF 1233
#define FOR_UPDATE 1234
#define GET_FLDBUF 1235
#define INITIALIZE 1236
#define INPUT_WRAP 1237
#define LOCK_TABLE 1238
#define MSG_LINE 1239
#define NOT_EXISTS 1240
#define ON_ANY_KEY 1241
#define REFERENCES 1242
#define RENCOL 1243
#define SET_CURSOR 1244
#define SMALLFLOAT 1245
#define SQLSUCCESS 1246
#define TOP_MARGIN 1247
#define WITH_ARRAY 1248
#define ACCEPTKEY 1249
#define ACCEPT 1250
#define AFTINP 1251
#define CLEARFORMTODEFAULTS 1252
#define CLEARFORM 1253
#define CLEAR_X_FORM 1254
#define COMMIT_W 1255
#define NEXTPAGE 1256
#define PREVPAGE 1257
#define CTRL_KEY 1258
#define INFTABS 1259
#define NEXTFIELD 1260
#define NEXTFORM 1261
#define RENTAB 1262
#define ASCENDING 1263
#define ASSOCIATE 1264
#define CHARACTER 1265
#define CONSTRUCT 1266
#define DELIMITER 1267
#define DOWNSHIFT 1268
#define DROP_VIEW 1269
#define END_INPUT 1270
#define END_WHILE 1271
#define EXCLUSIVE 1272
#define EXIT_CASE 1273
#define EXIT_MENU 1274
#define FORM_LINE 1275
#define INTERRUPT 1277
#define INTO_TEMP 1278
#define INVISIBLE 1279
#define IN_MEMORY 1280
#define LINKED_TO 1281
#define LOAD_FROM 1282
#define LOCKTAB 1283
#define MENU_LINE 1284
#define OPEN_FORM 1285
#define OTHERWISE 1286
#define PRECISION 1287
#define PRIOR 1288
#define PROCEDURE 1289
#define REPORT_TO 1290
#define RETURNING 1291
#define UNDERLINE 1292
#define UNLOAD_TO 1293
#define BEFROW 1294
#define UNLOAD_T 1295
#define VARIABLE 1296
#define ABSOLUTE 1297
#define AFTROW 1298
#define BUFFERED 1299
#define CONSTANT 1300
#define CONST 1301
#define CONTINUE 1302
#define DATABASE 1303
#define DATETIME 1304
#define DEFAULTS 1305
#define DISTINCT 1306
#define END_CASE 1307
#define END_MAIN 1308
#define END_MENU 1309
#define END_TYPE 1310
#define EXIT_FOR 1311
#define EXTERNAL 1312
#define FRACTION 1313
#define FUNCTION 1314
#define GROUP_BY 1315
#define INTERVAL 1316
#define KWMESSAGE 1317
#define NOT_LIKE 1318
#define NOT_NULL 1319
#define PASSWORD 1320
#define PREVIOUS 1321
#define READONLY 1322
#define REGISTER 1323
#define RELATIVE 1324
#define RESOURCE 1325
#define SMALLINT 1326
#define VALIDATE 1327
#define WHENEVER 1328
#define WITH_LOG 1329
#define WORDWRAP 1330
#define BY_NAME 1331
#define IN_FILE 1332
#define IS_NULL 1333
#define AVERAGE 1335
#define BETWEEN 1336
#define CAPTION 1337
#define CLIPPED 1338
#define CLOSE_BRACKET 1339
#define COLUMNS 1340
#define COMMENT 1342
#define CONNECT 1343
#define CURRENT 1344
#define DBYNAME 1345
#define DECIMAL 1346
#define DECLARE 1347
#define DEFAULT 1348
#define DISPLAY 1349
#define ENDCODE 1350
#define EXECUTE 1351
#define FOREACH 1352
#define FOREIGN 1353
#define GLOBALS 1354
#define INFIELD 1355
#define INTEGER 1356
#define KWWINDOW 1357
#define MAGENTA 1358
#define NUMERIC 1360
#define OPTIONS 1361
#define PERCENT 1362
#define PREPARE 1363
#define PROGRAM 1364
#define RECOVER 1365
#define REVERSE 1366
#define SECTION 1367
#define SESSION 1368
#define SYNONYM 1369
#define THRU 1370
#define TRAILER 1371
#define UPSHIFT 1372
#define VARCHAR 1373
#define WAITING 1374
#define CLOSE_SHEV 1375
#define CLOSE_SQUARE 1376
#define KW_FALSE 1378
#define NOT_IN 1379
#define ONKEY 1380
#define OPEN_BRACKET 1381
#define BORDER 1382
#define BOTTOM 1383
#define COLUMN 1384
#define COMMIT 1385
#define CREATE 1386
#define CURSOR 1387
#define DEFINE 1388
#define DELETE 1389
#define DOUBLE 1390
#define END_IF 1391
#define ESCAPE 1392
#define EXISTS 1393
#define EXTEND 1394
#define EXTENT 1395
#define FINISH 1396
#define FORMAT 1397
#define HAVING 1398
#define HEADER 1399
#define INSERT 1400
#define LOCATE 1401
#define MARGIN 1402
#define MEMORY 1403
#define MINUTE 1404
#define MODIFY 1405
#define NORMAL 1406
#define EQUAL_EQUAL 1407
#define OPEN_SHEV 1409
#define OPEN_SQUARE 1410
#define OPTION 1411
#define OUTPUT 1412
#define PROMPT 1413
#define PUBLIC 1414
#define RECORD 1415
#define REPORT 1416
#define RETURN 1417
#define REVOKE 1418
#define SCHEMA 1419
#define SCROLL_USING 1420
#define SCROLL 1421
#define SECOND 1422
#define SELECT 1423
#define SERIAL 1424
#define SETL 1425
#define SHARED 1426
#define SPACES 1427
#define UNIQUE 1428
#define UNLOCK 1429
#define UPDATE 1430
#define VALUES 1431
#define YELLOW 1432
#define AFTER 1433
#define KWLINE 1434
#define KW_NULL 1435
#define KW_TRUE 1436
#define SINGLE_KEY 1437
#define ALTER 1438
#define ARRAY 1439
#define ASCII 1440
#define AUDIT 1441
#define BLACK 1442
#define BLINK 1443
#define CHECK 1444
#define CLEAR 1445
#define CLOSE 1446
#define CODE_C 1447
#define COUNT 1448
#define DEFER 1449
#define ERROR 1450
#define EVERY 1451
#define FETCH 1452
#define FIRST 1453
#define FLOAT 1454
#define FLUSH 1455
#define FOUND 1456
#define GRANT 1457
#define GREEN 1458
#define GROUP 1459
#define INDEX 1460
#define KWFORM 1461
#define LABEL 1462
#define LOCAL 1464
#define MONEY 1465
#define MONTH 1466
#define ORDER 1469
#define OUTER 1470
#define PAUSE 1471
#define PRINT_IMAGE 1472
#define PRINT_FILE 1473
#define PRINT 1474
#define RIGHT 1475
#define SEMICOLON 1476
#define SLEEP 1477
#define TUPLE 1478
#define UNION 1479
#define WHERE 1481
#define WHILE 1482
#define WHITE 1483
#define CCODE 1484
#define ANSI 1485
#define BLUE 1486
#define BOLD 1487
#define BYTE 1488
#define FCALL 1489
#define CASE 1490
#define CHAR 1491
#define CYAN 1492
#define DATE 1493
#define DESC 1494
#define DOWN 1496
#define TAB 1497
#define DROP 1498
#define ELSE 1499
#define EXEC 1500
#define EXIT 1501
#define FREE 1502
#define FROM 1503
#define GOTO 1504
#define HELP_FILE 1505
#define LANG_FILE 1506
#define HELP 1507
#define HIDE 1508
#define HOUR 1509
#define INTO 1510
#define LAST 1511
#define LEFT 1512
#define LIKE 1513
#define MAIN 1514
#define MENU 1515
#define MODE 1516
#define NEED 1517
#define NEXT 1518
#define NOCR 1519
#define OPEN 1520
#define QUIT 1521
#define REAL 1522
#define ROWS 1523
#define SHOW 1524
#define SIZE 1525
#define SKIP 1526
#define SOME 1527
#define STEP 1528
#define STOP 1529
#define TEMP 1530
#define TEXT 1531
#define THEN 1532
#define USER 1533
#define WAIT 1534
#define WHEN 1535
#define WITH 1536
#define WORK 1537
#define YEAR 1538
#define KW_IS 1540
#define XSET 1541
#define ADD 1542
#define ALL 1543
#define ANY 1545
#define ASC 1546
#define AVG 1547
#define COLON 1548
#define DAY 1550
#define DBA 1551
#define DEC 1552
#define DIM 1553
#define FKEY 1554
#define FOR 1555
#define KEY 1556
#define KWNO 1557
#define LET 1558
#define LOG 1559
#define XMAX 1560
#define XMIN 1561
#define NOT 1564
#define PAD 1565
#define PUT 1566
#define RED 1567
#define ROW 1568
#define RUN 1569
#define SQL 1570
#define SUM 1571
#define TOP 1572
#define USE 1573
#define ATSIGN 1574
#define AS_TIFF 1576
#define AS_GIF 1577
#define AS_PNG 1578
#define AS_JPEG 1579
#define AS 1580
#define AT 1581
#define BY 1582
#define DOT 1583
#define GO 1584
#define IF 1585
#define IN 1586
#define OF 1587
#define ON 1588
#define TO 1590
#define UP 1591
#define FONT_NAME 1592
#define FONT_SIZE 1593
#define PAPER_SIZE_IS_LETTER 1594
#define PAPER_SIZE_IS_LEGAL 1595
#define PAPER_SIZE_IS_A5 1596
#define PAPER_SIZE_IS_A4 1597
#define PAPER_SIZE_IS_LETTER_L 1598
#define PAPER_SIZE_IS_LEGAL_L 1599
#define PAPER_SIZE_IS_A5_L 1600
#define PAPER_SIZE_IS_A4_L 1601
#define FORMHANDLER 1602
#define END_FORMHANDLER 1603
#define BEFORE_EVENT 1604
#define BEFORE_OPEN_FORM 1605
#define AFTER_EVENT 1606
#define BEFORE_CLOSE_FORM 1607
#define BEFORE_ANY 1608
#define AFTER_ANY 1609
#define MENUHANDLER 1610
#define END_MENUHANDLER 1611
#define BEFORE_SHOW_MENU 1612
#define DISABLE_PROGRAM 1613
#define DISABLE_ALL 1614
#define BUTTONS 1615
#define CHECK_MENUITEM 1616
#define DISABLE_FORM 1617
#define DISABLE_MENUITEMS 1618
#define DISABLE 1619
#define ENABLE_FORM 1620
#define ENABLE_MENUITEMS 1621
#define ENABLE 1622
#define KWFIELD 1623
#define ICON 1624
#define MESSAGEBOX 1625
#define TO_DEFAULTS 1626
#define UNCHECK_MENUITEM 1627
#define BEFORE 1628
#define INPUT 1629
#define END 1630
#define INT_TO_ID 1631




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
int 		in_sql=0;
int 		continue_cmd[]={0,1,1,1,1,1,1,1,1,0};
int 		in_cmd[]={0,0,0,0,0,0,0,0,0,0};
int 		fcall_cnt=0;

struct 		rep_structure rep_struct;
struct 		pdf_rep_structure pdf_rep_struct;
struct 		form_attr form_attrib;

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
#line 187 "fgl.yacc"
typedef union YYSTYPE {



	char	str[3100];  /* This would core dump in CygWin on call to */
						/* yyparse in y.tab.c - 3100 in maximum. */
						/* Was: char	str[20000]; */

	struct expr_str *ptr;

	} YYSTYPE;
/* Line 191 of yacc.c.  */
#line 1498 "y.tab.c"
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 214 of yacc.c.  */
#line 1510 "y.tab.c"

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
#define YYFINAL  63
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   8507

/* YYNTOKENS -- Number of terminals. */
#define YYNTOKENS  647
/* YYNNTS -- Number of nonterminals. */
#define YYNNTS  816
/* YYNRULES -- Number of rules. */
#define YYNRULES  1877
/* YYNRULES -- Number of states. */
#define YYNSTATES  3079

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   1644

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
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      93,    94,    95,    96,    97,    98,    99,   100,   101,   102,
     103,   104,   105,   106,   107,   108,   109,   110,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   131,   132,
     133,   134,   135,   136,   137,   138,   139,   140,   141,   142,
     143,   144,   145,   146,   147,   148,   149,   150,   151,   152,
     153,   154,   155,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     173,   174,   175,   176,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,   192,
     193,   194,   195,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
     253,   254,   255,   256,   257,   258,   259,   260,   261,   262,
     263,   264,   265,   266,   267,   268,   269,   270,   271,   272,
     273,   274,   275,   276,   277,   278,   279,   280,   281,   282,
     283,   284,   285,   286,   287,   288,   289,   290,   291,   292,
     293,   294,   295,   296,   297,   298,   299,   300,   301,   302,
     303,   304,   305,   306,   307,   308,    14,   309,   310,   311,
     312,   313,   314,   315,   316,   317,   318,   319,   320,   321,
     322,   323,   324,   325,   326,   327,   328,   329,   330,   331,
     332,   333,   334,   335,   336,   337,   338,   339,   340,   341,
     342,   343,   344,   345,   346,   347,   348,   349,   350,   351,
     352,   353,   354,   355,   356,   357,   358,   359,   360,   361,
     362,   363,   364,   365,    15,   366,   367,   368,   369,   370,
     371,    22,   372,   373,   374,   375,   376,   377,   378,   379,
     380,   381,   382,   383,   384,   385,   386,   387,   388,     9,
     389,   390,   391,   392,   393,   394,   395,   396,   397,   398,
     399,   400,   401,   402,   403,   404,   405,    12,   406,   407,
     408,   409,   410,   411,   412,   413,   414,   415,   416,   417,
     418,   419,   420,   421,   422,   423,   424,   425,   426,   427,
     428,   429,   430,   431,   432,   433,   434,   435,    16,   436,
     437,   438,   439,   440,   441,   442,   443,   444,   445,   446,
     447,   448,   449,   450,   451,   452,   453,   454,   455,   456,
     457,   458,   459,   460,   461,   462,   463,   464,   465,   466,
     467,   468,   469,   470,   471,   472,   473,   474,   475,   476,
     477,   478,   479,   480,   481,   482,   483,   484,   485,   486,
     487,   488,   489,    11,   490,   491,   492,    10,    20,   493,
     494,   495,   496,   497,   498,   499,   500,   501,   502,   503,
       8,   504,   505,   506,   507,   508,   509,   510,   511,   512,
     513,   514,   515,   516,   517,    19,   518,   519,   520,   521,
     522,   523,   524,   525,   526,   527,   528,   529,   530,   531,
     532,   533,   534,   535,   536,   537,   538,   539,   540,   541,
     542,   543,   544,   545,   546,   547,   548,   549,   550,   551,
     552,   553,   554,   555,   556,   557,   558,   559,   560,    13,
     561,   562,   563,   564,     7,   565,   566,   567,   568,     5,
     569,   570,   571,   572,   573,   574,   575,   576,   577,   578,
     579,   580,    18,    21,   581,   582,   583,   584,   585,   586,
     587,   588,   589,   590,   591,    17,   592,   593,   594,   595,
     596,   597,   598,   599,   600,   601,   602,   603,   604,     6,
     605,   606,   607,   608,   609,   610,   611,   612,   613,   614,
     615,   616,   617,   618,   619,   620,   621,   622,   623,   624,
     625,   626,   627,   628,   629,   630,   631,   632,   633,   634,
     635,   636,   637,   638,   639,   640,   641,   642,   643,   644,
     645,   646,     2,     3,     4,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const unsigned short yyprhs[] =
{
       0,     0,     3,     5,     7,    13,    15,    17,    19,    21,
      25,    27,    31,    35,    37,    40,    42,    44,    46,    48,
      50,    52,    54,    56,    57,    59,    60,    66,    73,    75,
      79,    81,    83,    85,    87,    89,    91,    93,    95,    97,
      99,   101,   103,   105,   107,   109,   111,   112,   114,   115,
     121,   123,   127,   129,   131,   134,   137,   140,   143,   146,
     149,   152,   155,   159,   160,   168,   173,   180,   182,   189,
     190,   191,   201,   202,   203,   204,   213,   214,   215,   226,
     227,   228,   236,   237,   238,   239,   254,   255,   258,   259,
     262,   264,   265,   267,   269,   273,   275,   277,   279,   281,
     285,   286,   293,   294,   300,   302,   305,   307,   310,   312,
     313,   314,   318,   319,   320,   324,   325,   330,   331,   336,
     339,   342,   345,   347,   350,   353,   357,   359,   361,   363,
     366,   368,   370,   373,   375,   377,   378,   379,   385,   393,
     402,   403,   406,   408,   412,   414,   418,   422,   424,   427,
     428,   433,   434,   439,   440,   444,   445,   449,   450,   454,
     456,   460,   462,   466,   468,   470,   472,   474,   476,   478,
     483,   484,   489,   491,   493,   494,   496,   498,   501,   502,
     503,   509,   511,   513,   515,   519,   520,   523,   528,   533,
     538,   543,   546,   547,   552,   554,   556,   558,   561,   563,
     565,   569,   570,   572,   573,   581,   582,   595,   597,   599,
     601,   603,   605,   611,   615,   617,   619,   620,   625,   626,
     632,   633,   641,   643,   647,   649,   651,   652,   654,   655,
     656,   661,   663,   665,   667,   672,   677,   684,   686,   689,
     691,   693,   695,   697,   702,   709,   711,   716,   723,   725,
     727,   729,   731,   733,   735,   737,   740,   743,   745,   747,
     752,   754,   756,   757,   761,   765,   766,   769,   771,   773,
     775,   777,   779,   781,   784,   785,   788,   789,   793,   794,
     798,   800,   801,   805,   807,   809,   811,   813,   815,   817,
     820,   822,   823,   825,   826,   832,   834,   836,   838,   843,
     848,   855,   857,   859,   861,   863,   868,   875,   877,   882,
     889,   891,   893,   895,   897,   899,   902,   905,   907,   912,
     913,   921,   922,   935,   936,   941,   942,   948,   950,   954,
     957,   959,   963,   965,   966,   969,   972,   974,   977,   983,
     988,   991,   996,  1002,  1006,  1007,  1008,  1020,  1021,  1024,
    1026,  1027,  1030,  1032,  1035,  1036,  1040,  1041,  1045,  1046,
    1050,  1055,  1061,  1063,  1065,  1067,  1069,  1071,  1073,  1075,
    1077,  1079,  1081,  1083,  1085,  1087,  1089,  1091,  1093,  1095,
    1097,  1100,  1102,  1104,  1106,  1108,  1111,  1113,  1115,  1117,
    1120,  1123,  1125,  1127,  1129,  1131,  1133,  1135,  1137,  1139,
    1141,  1143,  1145,  1148,  1150,  1152,  1154,  1158,  1160,  1164,
    1166,  1170,  1172,  1174,  1176,  1179,  1181,  1183,  1187,  1192,
    1197,  1200,  1203,  1205,  1207,  1209,  1211,  1213,  1217,  1219,
    1222,  1225,  1227,  1228,  1232,  1235,  1238,  1240,  1244,  1249,
    1254,  1260,  1266,  1268,  1270,  1273,  1276,  1279,  1282,  1284,
    1287,  1290,  1293,  1296,  1299,  1302,  1305,  1308,  1311,  1314,
    1317,  1320,  1323,  1326,  1327,  1328,  1329,  1336,  1337,  1338,
    1345,  1346,  1347,  1354,  1355,  1356,  1363,  1364,  1365,  1372,
    1373,  1374,  1381,  1387,  1393,  1399,  1407,  1408,  1412,  1414,
    1416,  1421,  1426,  1431,  1436,  1441,  1446,  1448,  1450,  1452,
    1454,  1459,  1464,  1467,  1470,  1473,  1476,  1479,  1481,  1483,
    1486,  1488,  1490,  1492,  1495,  1500,  1507,  1514,  1518,  1524,
    1530,  1534,  1536,  1538,  1542,  1543,  1544,  1556,  1557,  1560,
    1561,  1562,  1563,  1572,  1573,  1574,  1585,  1586,  1588,  1589,
    1591,  1593,  1596,  1597,  1601,  1602,  1606,  1607,  1609,  1611,
    1614,  1615,  1619,  1620,  1624,  1628,  1630,  1635,  1639,  1641,
    1645,  1647,  1651,  1653,  1657,  1659,  1662,  1663,  1667,  1668,
    1672,  1673,  1678,  1679,  1684,  1685,  1690,  1693,  1697,  1699,
    1703,  1705,  1707,  1709,  1711,  1713,  1715,  1719,  1721,  1723,
    1728,  1735,  1740,  1744,  1751,  1755,  1762,  1764,  1766,  1768,
    1770,  1772,  1774,  1775,  1778,  1782,  1786,  1788,  1793,  1795,
    1797,  1798,  1799,  1801,  1806,  1810,  1817,  1821,  1828,  1830,
    1832,  1835,  1837,  1839,  1841,  1843,  1845,  1847,  1849,  1851,
    1853,  1855,  1857,  1859,  1861,  1863,  1865,  1867,  1869,  1871,
    1873,  1875,  1877,  1879,  1881,  1883,  1885,  1887,  1889,  1891,
    1893,  1895,  1897,  1899,  1901,  1903,  1905,  1907,  1909,  1911,
    1913,  1915,  1917,  1919,  1921,  1924,  1927,  1929,  1933,  1935,
    1938,  1941,  1944,  1949,  1952,  1955,  1960,  1961,  1970,  1971,
    1973,  1975,  1977,  1978,  1980,  1983,  1984,  1986,  1989,  1990,
    1992,  1995,  1996,  1998,  2002,  2003,  2006,  2007,  2015,  2016,
    2017,  2021,  2022,  2023,  2031,  2037,  2040,  2041,  2047,  2052,
    2054,  2058,  2062,  2066,  2067,  2070,  2071,  2073,  2075,  2078,
    2079,  2084,  2085,  2090,  2091,  2095,  2096,  2100,  2101,  2105,
    2106,  2110,  2111,  2115,  2116,  2121,  2122,  2127,  2129,  2133,
    2135,  2137,  2139,  2143,  2145,  2147,  2149,  2153,  2155,  2159,
    2162,  2167,  2169,  2171,  2173,  2174,  2179,  2185,  2192,  2193,
    2204,  2208,  2210,  2212,  2215,  2218,  2219,  2222,  2223,  2227,
    2229,  2230,  2234,  2237,  2238,  2242,  2244,  2248,  2250,  2254,
    2255,  2258,  2260,  2262,  2264,  2266,  2268,  2270,  2272,  2274,
    2276,  2278,  2280,  2282,  2284,  2286,  2288,  2290,  2292,  2293,
    2294,  2302,  2304,  2306,  2309,  2312,  2315,  2319,  2324,  2325,
    2329,  2330,  2332,  2334,  2337,  2339,  2341,  2343,  2345,  2346,
    2348,  2350,  2353,  2356,  2358,  2360,  2362,  2364,  2366,  2368,
    2370,  2372,  2374,  2376,  2378,  2380,  2382,  2383,  2385,  2387,
    2389,  2391,  2393,  2394,  2395,  2396,  2397,  2411,  2413,  2414,
    2415,  2422,  2425,  2427,  2430,  2433,  2435,  2437,  2440,  2442,
    2444,  2446,  2447,  2451,  2454,  2456,  2457,  2458,  2459,  2474,
    2475,  2481,  2483,  2484,  2488,  2489,  2497,  2498,  2504,  2506,
    2509,  2510,  2512,  2514,  2516,  2517,  2519,  2521,  2524,  2527,
    2530,  2532,  2534,  2536,  2538,  2542,  2544,  2546,  2547,  2548,
    2556,  2558,  2561,  2562,  2566,  2567,  2572,  2575,  2576,  2579,
    2581,  2583,  2585,  2587,  2589,  2591,  2593,  2594,  2598,  2599,
    2601,  2603,  2605,  2607,  2610,  2614,  2617,  2623,  2625,  2627,
    2629,  2634,  2639,  2641,  2643,  2645,  2647,  2650,  2654,  2661,
    2663,  2667,  2669,  2671,  2673,  2678,  2686,  2688,  2690,  2692,
    2694,  2697,  2698,  2700,  2702,  2706,  2708,  2712,  2714,  2718,
    2720,  2724,  2726,  2728,  2730,  2732,  2736,  2738,  2742,  2744,
    2748,  2750,  2752,  2754,  2758,  2761,  2762,  2764,  2766,  2771,
    2773,  2777,  2779,  2783,  2791,  2792,  2800,  2801,  2808,  2812,
    2814,  2818,  2820,  2823,  2829,  2830,  2838,  2839,  2842,  2843,
    2845,  2851,  2854,  2860,  2861,  2867,  2874,  2879,  2880,  2882,
    2884,  2889,  2890,  2893,  2894,  2900,  2905,  2908,  2910,  2914,
    2917,  2920,  2923,  2926,  2929,  2932,  2934,  2937,  2940,  2943,
    2946,  2949,  2952,  2955,  2958,  2961,  2963,  2965,  2967,  2969,
    2971,  2973,  2979,  2981,  2983,  2986,  2991,  2993,  2994,  3005,
    3011,  3012,  3014,  3015,  3018,  3020,  3023,  3024,  3028,  3030,
    3031,  3036,  3037,  3040,  3042,  3046,  3048,  3050,  3054,  3059,
    3064,  3067,  3069,  3071,  3073,  3074,  3076,  3084,  3087,  3090,
    3093,  3096,  3098,  3101,  3102,  3106,  3107,  3111,  3112,  3116,
    3117,  3121,  3122,  3126,  3127,  3132,  3133,  3138,  3140,  3142,
    3144,  3146,  3148,  3150,  3151,  3156,  3157,  3159,  3160,  3165,
    3167,  3170,  3173,  3176,  3177,  3179,  3181,  3184,  3187,  3188,
    3191,  3195,  3199,  3205,  3206,  3209,  3214,  3216,  3218,  3220,
    3222,  3224,  3225,  3227,  3229,  3233,  3236,  3242,  3245,  3251,
    3257,  3263,  3269,  3275,  3281,  3282,  3285,  3287,  3290,  3293,
    3296,  3299,  3302,  3305,  3307,  3310,  3313,  3316,  3319,  3321,
    3324,  3327,  3330,  3333,  3335,  3337,  3339,  3340,  3343,  3346,
    3349,  3352,  3355,  3358,  3361,  3364,  3367,  3369,  3371,  3373,
    3375,  3377,  3379,  3381,  3383,  3386,  3389,  3392,  3395,  3398,
    3400,  3402,  3404,  3405,  3409,  3412,  3413,  3414,  3415,  3416,
    3417,  3418,  3434,  3435,  3438,  3441,  3442,  3444,  3445,  3446,
    3447,  3448,  3449,  3450,  3466,  3469,  3470,  3471,  3472,  3483,
    3484,  3486,  3490,  3494,  3497,  3502,  3506,  3510,  3514,  3516,
    3518,  3520,  3522,  3524,  3528,  3529,  3530,  3538,  3539,  3540,
    3549,  3552,  3553,  3555,  3557,  3561,  3564,  3567,  3569,  3571,
    3575,  3577,  3579,  3582,  3584,  3586,  3590,  3592,  3596,  3598,
    3600,  3602,  3604,  3606,  3608,  3610,  3613,  3618,  3620,  3624,
    3626,  3630,  3633,  3638,  3640,  3644,  3646,  3649,  3654,  3656,
    3660,  3662,  3664,  3666,  3669,  3672,  3677,  3680,  3685,  3687,
    3691,  3693,  3695,  3697,  3700,  3702,  3704,  3706,  3708,  3710,
    3713,  3720,  3727,  3728,  3730,  3731,  3733,  3736,  3737,  3738,
    3746,  3747,  3750,  3753,  3761,  3763,  3769,  3773,  3775,  3779,
    3781,  3785,  3787,  3791,  3793,  3797,  3799,  3801,  3803,  3805,
    3806,  3812,  3813,  3819,  3821,  3822,  3826,  3828,  3832,  3834,
    3838,  3840,  3842,  3843,  3844,  3850,  3853,  3855,  3856,  3857,
    3861,  3862,  3863,  3867,  3869,  3871,  3873,  3875,  3877,  3879,
    3882,  3885,  3890,  3894,  3898,  3900,  3904,  3907,  3909,  3911,
    3912,  3914,  3916,  3918,  3920,  3921,  3923,  3927,  3928,  3932,
    3934,  3936,  3938,  3940,  3942,  3944,  3946,  3948,  3950,  3952,
    3954,  3956,  3964,  3965,  3967,  3969,  3971,  3973,  3977,  3979,
    3981,  3983,  3986,  3987,  3991,  3993,  3997,  3999,  4003,  4005,
    4007,  4014,  4015,  4019,  4021,  4025,  4026,  4028,  4033,  4039,
    4042,  4044,  4046,  4051,  4053,  4057,  4062,  4067,  4069,  4073,
    4075,  4077,  4079,  4082,  4084,  4089,  4090,  4092,  4093,  4096,
    4098,  4100,  4102,  4107,  4111,  4113,  4115,  4117,  4120,  4122,
    4124,  4127,  4130,  4132,  4136,  4139,  4142,  4144,  4148,  4150,
    4153,  4158,  4160,  4163,  4165,  4169,  4174,  4175,  4177,  4178,
    4180,  4181,  4183,  4185,  4189,  4191,  4195,  4197,  4200,  4202,
    4206,  4209,  4212,  4217,  4221,  4222,  4224,  4226,  4228,  4230,
    4232,  4235,  4237,  4239,  4245,  4249,  4255,  4259,  4261,  4265,
    4267,  4269,  4270,  4272,  4276,  4280,  4284,  4288,  4295,  4301,
    4303,  4305,  4307,  4309,  4311,  4313,  4315,  4317,  4319,  4321,
    4323,  4325,  4327,  4329,  4330,  4332,  4334,  4336,  4338,  4340,
    4342,  4344,  4349,  4355,  4357,  4363,  4369,  4371,  4373,  4375,
    4380,  4382,  4387,  4389,  4397,  4399,  4401,  4403,  4408,  4415,
    4416,  4419,  4424,  4426,  4428,  4430,  4432,  4434,  4436,  4438,
    4442,  4444,  4446,  4450,  4452,  4453,  4457,  4463,  4466,  4472,
    4477,  4479,  4481,  4483,  4485,  4487,  4490,  4493,  4496,  4499,
    4501,  4504,  4507,  4508,  4512,  4513,  4517,  4519,  4521,  4523,
    4525,  4527,  4529,  4531,  4536,  4538,  4540,  4542,  4544,  4546,
    4548,  4550,  4555,  4557,  4559,  4561,  4563,  4565,  4567,  4569,
    4571,  4573,  4575,  4577,  4579,  4581,  4583,  4585,  4587,  4591,
    4592,  4601,  4602,  4612,  4613,  4621,  4622,  4632,  4633,  4635,
    4638,  4640,  4644,  4646,  4650,  4656,  4658,  4660,  4662,  4664,
    4667,  4668,  4669,  4678,  4684,  4686,  4688,  4696,  4697,  4701,
    4703,  4707,  4712,  4714,  4715,  4718,  4724,  4732,  4733,  4735,
    4737,  4739,  4741,  4745,  4747,  4750,  4753,  4755,  4757,  4759,
    4763,  4766,  4770,  4774,  4778,  4780,  4782,  4784,  4786,  4788,
    4790,  4796,  4802,  4808,  4814,  4820,  4825,  4832,  4836,  4841,
    4843,  4847,  4848,  4850,  4856,  4864,  4865,  4868,  4870,  4872,
    4873,  4877,  4879,  4883,  4885,  4887,  4889,  4890,  4894,  4896,
    4898,  4900,  4902,  4907,  4914,  4916,  4918,  4921,  4925,  4927,
    4929,  4931,  4933,  4935,  4937,  4939,  4941,  4947,  4953,  4958,
    4960,  4963,  4965,  4967,  4969,  4973,  4979,  4981,  4983,  4985,
    4987,  4991,  4994,  4997,  5000,  5002,  5005,  5008,  5011,  5014,
    5017,  5019,  5023,  5026,  5028,  5031,  5033,  5036,  5038,  5039,
    5040,  5047,  5048,  5051,  5052,  5054,  5056,  5059,  5062,  5064,
    5066,  5071,  5075,  5077,  5081,  5083,  5086,  5092,  5095,  5098,
    5104,  5105,  5108,  5110,  5112,  5115,  5122,  5129,  5131,  5132,
    5134,  5137,  5139,  5142,  5143,  5146,  5148,  5150,  5152,  5154,
    5156,  5158,  5160,  5162,  5164,  5166,  5168,  5170,  5172,  5174,
    5176,  5178,  5180,  5182,  5184,  5186,  5188,  5190,  5192,  5194,
    5196,  5198,  5200,  5202,  5204,  5206,  5208,  5210,  5212,  5214,
    5216,  5218,  5220,  5222,  5224,  5226,  5228,  5230,  5232,  5234,
    5236,  5238,  5240,  5242,  5244,  5246,  5248,  5250,  5252,  5254,
    5256,  5258,  5260,  5262,  5264,  5266,  5268,  5270,  5272,  5274,
    5276,  5278,  5280,  5282,  5284,  5286,  5288,  5290,  5292,  5294,
    5296,  5298,  5300,  5302,  5304,  5306,  5308,  5310
};

/* YYRHS -- A `-1'-separated list of the rules' RHS. */
static const short yyrhs[] =
{
    1007,     0,    -1,   179,    -1,   176,    -1,   103,   652,   405,
     574,   653,    -1,   117,    -1,  1073,    -1,    25,    -1,   654,
      -1,   653,     5,   654,    -1,   915,    -1,   409,   655,   370,
      -1,   655,   656,   655,    -1,    25,    -1,   657,    25,    -1,
    1073,    -1,    17,    -1,    18,    -1,    20,    -1,    19,    -1,
      21,    -1,    17,    -1,    18,    -1,    -1,   659,    -1,    -1,
     253,   409,   660,   661,   370,    -1,   547,   409,    25,     5,
      25,   370,    -1,   662,    -1,   661,     5,   662,    -1,   469,
      -1,   509,    -1,   515,    -1,   485,    -1,   388,    -1,   584,
      -1,   506,    -1,   459,    -1,   395,    -1,   470,    -1,   324,
      -1,   510,    -1,   434,    -1,   311,    -1,   572,    -1,    77,
      -1,    -1,   664,    -1,    -1,   253,   409,   665,   666,   370,
      -1,   667,    -1,   666,     5,   667,    -1,   662,    -1,   410,
      -1,   582,    24,    -1,   182,   902,    -1,   308,   902,    -1,
     263,   902,    -1,   316,   902,    -1,   272,   902,    -1,   238,
     902,    -1,   512,   669,    -1,   848,   323,  1073,    -1,    -1,
     268,   409,  1447,   370,   323,   670,  1091,    -1,    83,   409,
     915,   370,    -1,   385,   409,   907,   370,   323,  1073,    -1,
    1208,    -1,   171,   409,   907,   370,   323,  1073,    -1,    -1,
      -1,  1073,   568,   915,   409,   671,   685,   370,   672,   683,
      -1,    -1,    -1,    -1,   915,   409,   673,   685,   674,   370,
     675,   683,    -1,    -1,    -1,   453,  1416,   602,  1416,   409,
     676,   685,   677,   370,   683,    -1,    -1,    -1,    44,   409,
     678,   685,   679,   370,   683,    -1,    -1,    -1,    -1,   344,
     688,   568,   689,   437,   652,   405,   409,   680,   685,   681,
     370,   682,   684,    -1,    -1,   323,  1091,    -1,    -1,   323,
    1091,    -1,   141,    -1,    -1,   686,    -1,   687,    -1,   686,
       5,   687,    -1,   817,    -1,    24,    -1,   915,    -1,   915,
      -1,   915,   599,   915,    -1,    -1,   513,   824,   691,   694,
     698,   695,    -1,    -1,   513,   692,   693,   696,   695,    -1,
     700,    -1,   693,   700,    -1,   702,    -1,   694,   702,    -1,
     339,    -1,    -1,    -1,   318,   697,  1457,    -1,    -1,    -1,
     318,   699,  1457,    -1,    -1,   557,   824,   701,  1457,    -1,
      -1,   557,   824,   703,  1457,    -1,   257,   912,    -1,   181,
     910,    -1,    62,   910,    -1,   148,    -1,   164,  1422,    -1,
     473,   909,    -1,    29,   706,    30,    -1,   707,    -1,   709,
      -1,   708,    -1,   707,   708,    -1,    28,    -1,   710,    -1,
     709,   710,    -1,    27,    -1,   372,    -1,    -1,    -1,   299,
     713,   715,   714,   716,    -1,   363,  1073,   604,   717,   958,
     985,   658,    -1,  1073,   604,   717,   958,   525,  1447,   985,
     658,    -1,    -1,   719,   170,    -1,   718,    -1,   717,     5,
     718,    -1,   915,    -1,   915,   599,   915,    -1,   915,   599,
      20,    -1,   720,    -1,   719,   720,    -1,    -1,   249,   726,
     721,  1457,    -1,    -1,   252,   727,   722,  1457,    -1,    -1,
     986,   723,  1457,    -1,    -1,   146,   724,  1457,    -1,    -1,
     142,   725,  1457,    -1,   921,    -1,   726,     5,   921,    -1,
     921,    -1,   727,     5,   921,    -1,    71,    -1,    72,    -1,
      73,    -1,    74,    -1,    75,    -1,    76,    -1,   409,   817,
     730,   370,    -1,    -1,     5,   771,   605,   774,    -1,   134,
      -1,   258,    -1,    -1,   733,    -1,   734,    -1,   733,   734,
      -1,    -1,    -1,   416,   735,   737,   736,  1177,    -1,   784,
      -1,  1437,    -1,   740,    -1,   737,     5,   740,    -1,    -1,
     739,   915,    -1,   332,   738,   783,    24,    -1,   332,   738,
     783,   915,    -1,   332,   738,   783,   923,    -1,   332,   738,
     783,    25,    -1,   744,   760,    -1,    -1,   738,   332,   741,
     742,    -1,    25,    -1,    24,    -1,   923,    -1,    18,    25,
      -1,   738,    -1,   743,    -1,   744,     5,   743,    -1,    -1,
     514,    -1,    -1,   466,   437,   752,   405,   747,   603,   760,
      -1,    -1,   297,   745,   749,    25,   750,   281,   437,   751,
     405,   748,   603,   760,    -1,   409,    -1,   436,    -1,   370,
      -1,   404,    -1,    25,    -1,   753,     5,   753,     5,   753,
      -1,   753,     5,   753,    -1,   753,    -1,    25,    -1,    -1,
     442,   755,   737,   262,    -1,    -1,   239,   756,   738,   599,
      20,    -1,    -1,   313,   757,   738,   237,   409,   758,   370,
      -1,   759,    -1,   758,     5,   759,    -1,   738,    -1,   762,
      -1,    -1,    37,    -1,    -1,    -1,   763,   765,   764,   761,
      -1,   746,    -1,   754,    -1,   514,    -1,   514,   409,    25,
     370,    -1,   402,   409,    25,   370,    -1,   402,   409,    25,
       5,    25,   370,    -1,   386,    -1,   596,   738,    -1,   358,
      -1,   488,    -1,    68,    -1,   376,    -1,   376,   409,    25,
     370,    -1,   376,   409,    25,     5,    25,   370,    -1,   491,
      -1,   491,   409,    25,   370,    -1,   491,   409,    25,     5,
      25,   370,    -1,   481,    -1,   278,    -1,   516,    -1,   511,
      -1,    59,    -1,    60,    -1,   553,    -1,   336,   769,    -1,
     348,   770,    -1,   766,    -1,    31,    -1,   535,   767,   599,
     768,    -1,   738,    -1,   738,    -1,    -1,   771,   605,   774,
      -1,   779,   605,   782,    -1,    -1,   772,   773,    -1,   560,
      -1,   492,    -1,   569,    -1,   531,    -1,   432,    -1,   449,
      -1,   345,   776,    -1,    -1,   775,   773,    -1,    -1,   409,
     778,   370,    -1,    -1,   409,    25,   370,    -1,    25,    -1,
      -1,   780,   781,   777,    -1,   560,    -1,   492,    -1,   569,
      -1,   531,    -1,   432,    -1,   449,    -1,   345,   776,    -1,
     781,    -1,    -1,    13,    -1,    -1,   215,   915,   785,   596,
     786,    -1,   788,    -1,   791,    -1,   514,    -1,   514,   409,
      25,   370,    -1,   402,   409,    25,   370,    -1,   402,   409,
      25,     5,    25,   370,    -1,   386,    -1,   358,    -1,   488,
      -1,   376,    -1,   376,   409,    25,   370,    -1,   376,   409,
      25,     5,    25,   370,    -1,   491,    -1,   491,   409,    25,
     370,    -1,   491,   409,    25,     5,    25,   370,    -1,   481,
      -1,   278,    -1,   516,    -1,   511,    -1,   553,    -1,   336,
     769,    -1,   348,   770,    -1,   787,    -1,   535,   767,   599,
     768,    -1,    -1,   466,   437,   752,   405,   789,   603,   786,
      -1,    -1,   297,   745,   749,    25,   750,   281,   437,   751,
     405,   790,   603,   786,    -1,    -1,   442,   792,   794,   262,
      -1,    -1,   239,   793,   915,   599,    20,    -1,   795,    -1,
     794,     5,   795,    -1,   796,   786,    -1,   797,    -1,   796,
       5,   797,    -1,   915,    -1,    -1,   597,   906,    -1,    49,
     915,    -1,    47,    -1,   605,  1447,    -1,   605,   488,   915,
     638,  1447,    -1,   605,   488,   915,   368,    -1,    51,   915,
      -1,   135,   842,  1091,   806,    -1,   379,   842,   822,   798,
     806,    -1,   188,   912,   806,    -1,    -1,    -1,   167,   803,
    1098,   605,   915,   599,    20,   805,   658,   804,   807,    -1,
      -1,   447,   907,    -1,   658,    -1,    -1,   808,   217,    -1,
     809,    -1,   808,   809,    -1,    -1,   330,   810,  1457,    -1,
      -1,   326,   811,  1457,    -1,    -1,   986,   812,  1457,    -1,
     477,   842,   823,   658,    -1,   477,   842,   823,   658,    45,
      -1,   265,    -1,   264,    -1,   191,    -1,   343,    -1,   153,
      -1,   190,    -1,   307,    -1,   306,    -1,   222,    -1,   150,
      -1,   149,    -1,   123,    -1,   183,    -1,   106,    -1,   122,
      -1,   166,    -1,   132,    -1,   192,    -1,   192,   824,    -1,
     827,    -1,   826,    -1,   831,    -1,   859,    -1,   817,   818,
      -1,   860,    -1,   862,    -1,   828,    -1,    18,   817,    -1,
      17,   817,    -1,   833,    -1,   841,    -1,   835,    -1,   454,
      -1,   728,    -1,   836,    -1,   837,    -1,   838,    -1,   839,
      -1,   840,    -1,   842,    -1,   842,   821,    -1,   824,    -1,
     462,    -1,   820,    -1,   821,     5,   820,    -1,   824,    -1,
     822,     5,   824,    -1,   824,    -1,   823,     5,   824,    -1,
     817,    -1,    17,    -1,    18,    -1,   581,   817,    -1,   463,
      -1,   406,    -1,   409,   817,   370,    -1,   421,   409,  1397,
     370,    -1,   273,   409,  1397,   370,    -1,   825,   923,    -1,
     825,    25,    -1,    24,    -1,   923,    -1,    25,    -1,   830,
      -1,  1073,    -1,  1073,   399,  1073,    -1,   829,    -1,   412,
     817,    -1,   371,   817,    -1,  1180,    -1,    -1,   486,   832,
    1180,    -1,     7,   817,    -1,     6,   817,    -1,   817,    -1,
     834,     5,   817,    -1,   602,   409,  1397,   370,    -1,   407,
     409,  1397,   370,    -1,   602,   409,   842,   834,   370,    -1,
     407,   409,   842,   834,   370,    -1,   365,    -1,   228,    -1,
       9,   817,    -1,   231,   817,    -1,   535,   817,    -1,   350,
     817,    -1,   369,    -1,     8,   817,    -1,    17,   817,    -1,
      18,   817,    -1,    20,   817,    -1,    19,   817,    -1,    21,
     817,    -1,    10,   817,    -1,    13,   817,    -1,   435,   817,
      -1,    11,   817,    -1,    12,   817,    -1,    16,   817,    -1,
      15,   817,    -1,    14,   817,    -1,    -1,    -1,    -1,   915,
     409,   844,   685,   845,   370,    -1,    -1,    -1,    44,   409,
     846,   685,   847,   370,    -1,    -1,    -1,   516,   409,   849,
     817,   850,   370,    -1,    -1,    -1,   492,   409,   851,   817,
     852,   370,    -1,    -1,    -1,   569,   409,   853,   817,   854,
     370,    -1,    -1,    -1,   560,   409,   855,   817,   856,   370,
      -1,   348,   409,   863,   370,   858,    -1,   336,   409,    24,
     370,   857,    -1,   336,   409,    25,   370,   857,    -1,   336,
     409,    25,   568,    25,   370,   857,    -1,    -1,  1377,   605,
    1378,    -1,   770,    -1,   848,    -1,   268,   409,  1447,   370,
      -1,    78,   409,   907,   370,    -1,    50,   409,   907,   370,
      -1,   385,   409,   907,   370,    -1,   171,   409,   907,   370,
      -1,    38,   409,   907,   370,    -1,   861,    -1,   843,    -1,
    1373,    -1,   516,    -1,   401,   409,   817,   370,    -1,   301,
     409,   817,   370,    -1,   467,   817,    -1,   422,   729,    -1,
     817,    87,    -1,   817,    88,    -1,   817,    89,    -1,    24,
      -1,   864,    -1,    18,   864,    -1,   866,    -1,   865,    -1,
      25,    -1,    25,    25,    -1,    25,    25,   568,    25,    -1,
      25,    25,   568,    25,   568,    25,    -1,    25,    25,   568,
      25,   568,    23,    -1,    25,   568,    25,    -1,    25,   568,
      25,   568,    25,    -1,    25,   568,    25,   568,    23,    -1,
      25,   568,    23,    -1,    23,    -1,    25,    -1,    25,    18,
      25,    -1,    -1,    -1,   574,  1073,    13,   824,   605,   824,
     870,   868,  1457,   869,   220,    -1,    -1,   550,   824,    -1,
      -1,    -1,    -1,   382,   872,   909,   873,  1277,   874,  1457,
     219,    -1,    -1,    -1,   617,   915,   876,   732,   877,  1017,
     879,   878,   884,   618,    -1,    -1,   889,    -1,    -1,   880,
      -1,   881,    -1,   880,   881,    -1,    -1,   619,   882,  1457,
      -1,    -1,   620,   883,  1457,    -1,    -1,   885,    -1,   886,
      -1,   885,   886,    -1,    -1,   621,   887,  1457,    -1,    -1,
     622,   888,  1457,    -1,   890,   894,   303,    -1,    70,    -1,
      70,   891,   525,   892,    -1,    70,   363,   893,    -1,  1073,
      -1,   891,     5,  1073,    -1,   915,    -1,   892,     5,   915,
      -1,  1073,    -1,   893,     5,  1073,    -1,   895,    -1,   894,
     895,    -1,    -1,   623,   896,  1457,    -1,    -1,   624,   897,
    1457,    -1,    -1,   643,   892,   898,  1457,    -1,    -1,   460,
     892,   899,  1457,    -1,    -1,   604,   892,   900,  1457,    -1,
     524,   908,    -1,   533,    18,    25,    -1,   533,    -1,   480,
      17,    25,    -1,   480,    -1,    25,    -1,  1073,    -1,    24,
      -1,   922,    -1,   824,    -1,   904,     5,   904,    -1,   905,
      -1,   915,    -1,   646,   409,   915,   370,    -1,   915,   599,
     646,   409,   915,   370,    -1,   915,   437,   655,   405,    -1,
     915,   599,    20,    -1,   915,   437,   655,   405,   599,    20,
      -1,   915,   599,   915,    -1,   915,   437,   655,   405,   599,
     915,    -1,   916,    -1,   916,    -1,   916,    -1,   916,    -1,
     916,    -1,   916,    -1,    -1,   529,    25,    -1,   919,  1456,
     920,    -1,   919,   917,   920,    -1,  1456,    -1,   328,   409,
     918,   370,    -1,  1076,    -1,    24,    -1,    -1,    -1,   915,
      -1,   915,   437,   655,   405,    -1,   915,   599,    20,    -1,
     915,   437,   655,   405,   599,    20,    -1,   915,   599,   915,
      -1,   915,   437,   655,   405,   599,   915,    -1,  1073,    -1,
      23,    -1,   599,    25,    -1,   352,    -1,   471,    -1,   472,
      -1,   369,    -1,   473,    -1,   332,    -1,   299,    -1,   475,
      -1,   438,    -1,   515,    -1,   427,    -1,   570,    -1,   375,
      -1,   468,    -1,   461,    -1,   538,    -1,   378,    -1,   337,
      -1,   476,    -1,   300,    -1,   517,    -1,   259,    -1,   572,
      -1,   634,    -1,   518,    -1,   301,    -1,   520,    -1,   383,
      -1,   421,    -1,   560,    -1,   492,    -1,   569,    -1,   454,
      -1,   357,    -1,   372,    -1,   417,    -1,   359,    -1,   420,
      -1,   401,    -1,   366,    -1,   324,    -1,   537,    -1,   516,
      -1,   526,  1439,    -1,   631,   927,    -1,   928,    -1,   927,
       5,   928,    -1,   915,    -1,   642,   927,    -1,   633,   927,
      -1,   634,  1447,    -1,   632,   912,   638,  1447,    -1,   636,
     927,    -1,   637,  1447,    -1,   635,   912,   638,  1447,    -1,
      -1,   640,   933,   822,   938,   940,   942,   934,   936,    -1,
      -1,   935,    -1,   628,    -1,   629,    -1,    -1,   937,    -1,
     323,  1073,    -1,    -1,   939,    -1,   368,   822,    -1,    -1,
     941,    -1,   639,    25,    -1,    -1,   943,    -1,   630,    25,
     944,    -1,    -1,   378,    25,    -1,    -1,   601,   824,   554,
     946,  1457,   947,   419,    -1,    -1,    -1,   521,   948,  1457,
      -1,    -1,    -1,    41,   949,   824,   554,   950,  1457,   947,
      -1,    85,   915,   409,    25,   370,    -1,    54,   915,    -1,
      -1,   269,  1103,   954,   605,   462,    -1,   269,  1103,   535,
     955,    -1,   956,    -1,   955,     5,   956,    -1,   767,   599,
    1370,    -1,   767,   599,    20,    -1,    -1,   959,   303,    -1,
      -1,   129,    -1,   960,    -1,   959,   960,    -1,    -1,   249,
     974,   961,  1457,    -1,    -1,   252,   975,   962,  1457,    -1,
      -1,   330,   963,  1457,    -1,    -1,   326,   964,  1457,    -1,
      -1,   986,   965,  1457,    -1,    -1,   284,   966,  1457,    -1,
      -1,   254,   967,  1457,    -1,    -1,   643,   972,   968,  1457,
      -1,    -1,   460,   970,   969,  1457,    -1,   971,    -1,   970,
       5,   971,    -1,   428,    -1,   417,    -1,   973,    -1,   972,
       5,   973,    -1,   428,    -1,   417,    -1,   907,    -1,   974,
       5,   907,    -1,   907,    -1,   975,     5,   907,    -1,   293,
     978,    -1,   294,   915,   638,   978,    -1,   540,    -1,   353,
      -1,   907,    -1,    -1,   644,   981,   980,   957,    -1,   363,
    1091,   958,   914,   658,    -1,  1091,   958,   525,  1447,   914,
     658,    -1,    -1,   466,  1098,   958,   525,   915,   599,    20,
     914,   982,   658,    -1,   448,  1447,   984,    -1,   606,    -1,
     518,    -1,    55,    25,    -1,    61,    25,    -1,    -1,   529,
      25,    -1,    -1,   408,   987,   993,    -1,   274,    -1,    -1,
     575,   989,   993,    -1,   282,   995,    -1,    -1,   575,   992,
     993,    -1,   995,    -1,   409,   994,   370,    -1,   995,    -1,
     994,     5,   995,    -1,    -1,   996,   997,    -1,   573,    -1,
     291,    -1,   309,    -1,   283,    -1,   464,    -1,   420,    -1,
     606,    -1,   518,    -1,   444,    -1,   417,    -1,   519,    -1,
     534,    -1,   499,    -1,   289,    -1,   290,    -1,    24,    -1,
     489,    -1,    -1,    -1,   577,  1000,  1096,  1001,    13,   842,
    1002,    -1,   462,    -1,   823,    -1,   198,  1073,    -1,   187,
    1073,    -1,   201,  1073,    -1,   429,  1073,   312,    -1,   429,
    1073,   364,   903,    -1,    -1,  1009,  1008,  1012,    -1,    -1,
    1010,    -1,  1011,    -1,  1010,  1011,    -1,   952,    -1,  1016,
      -1,  1032,    -1,  1018,    -1,    -1,  1013,    -1,  1015,    -1,
    1013,  1015,    -1,    46,   915,    -1,  1020,    -1,  1026,    -1,
    1038,    -1,  1190,    -1,  1200,    -1,  1059,    -1,  1437,    -1,
     875,    -1,   705,    -1,   951,    -1,   711,    -1,   705,    -1,
    1437,    -1,    -1,   705,    -1,  1437,    -1,   733,    -1,   346,
      -1,    39,    -1,    -1,    -1,    -1,    -1,  1019,  1021,   915,
     409,  1022,  1089,   370,  1023,   732,  1024,  1017,  1457,  1025,
      -1,   189,    -1,    -1,    -1,   536,  1027,   732,  1028,  1457,
     340,    -1,   444,   819,    -1,   842,    -1,   842,   822,    -1,
     335,  1381,    -1,  1033,    -1,  1034,    -1,  1033,  1034,    -1,
    1035,    -1,  1016,    -1,  1031,    -1,    -1,   384,  1036,  1037,
      -1,   732,   221,    -1,   903,    -1,    -1,    -1,    -1,    92,
     915,    91,   915,   409,  1039,  1089,   370,  1040,   732,  1041,
    1017,  1457,  1025,    -1,    -1,   537,  1043,  1058,  1049,  1044,
      -1,   341,    -1,    -1,   213,  1046,  1457,    -1,    -1,    22,
    1050,  1051,  1052,   914,  1047,  1457,    -1,    -1,    22,  1050,
     914,  1048,  1457,    -1,  1045,    -1,  1049,  1045,    -1,    -1,
     988,    -1,    24,    -1,  1073,    -1,    -1,  1073,    -1,    24,
      -1,   230,  1056,    -1,   242,  1057,    -1,   225,  1057,    -1,
     564,    -1,    24,    -1,  1073,    -1,  1056,    -1,  1057,     5,
    1056,    -1,  1073,    -1,    24,    -1,    -1,    -1,   625,   915,
    1060,   732,  1061,  1062,   626,    -1,  1063,    -1,  1062,  1063,
      -1,    -1,   627,  1064,  1457,    -1,    -1,   604,   915,  1065,
    1457,    -1,  1069,  1067,    -1,    -1,   659,  1071,    -1,  1072,
      -1,  1068,    -1,   939,    -1,   941,    -1,   943,    -1,   935,
      -1,   937,    -1,    -1,   349,  1070,   823,    -1,    -1,    45,
      -1,    45,    -1,  1074,    -1,  1076,    -1,   591,  1076,    -1,
    1076,   919,   599,    -1,  1075,  1080,    -1,  1075,   915,   437,
    1083,   405,    -1,  1081,    -1,   915,    -1,  1077,    -1,   915,
     436,  1079,   404,    -1,   915,   436,  1079,   404,    -1,  1073,
      -1,    24,    -1,    20,    -1,   915,    -1,   915,  1082,    -1,
     437,  1083,   405,    -1,   437,  1083,   405,   437,  1083,   405,
      -1,  1084,    -1,  1083,     5,  1084,    -1,   655,    -1,  1086,
      -1,  1088,    -1,  1086,   919,   599,  1087,    -1,  1086,   919,
     599,   915,   437,  1083,   405,    -1,   915,    -1,  1078,    -1,
      20,    -1,   915,    -1,   915,  1082,    -1,    -1,  1090,    -1,
    1092,    -1,  1090,     5,  1092,    -1,  1093,    -1,  1091,     5,
    1093,    -1,   915,    -1,   915,   599,   915,    -1,  1073,    -1,
    1073,   399,  1073,    -1,    24,    -1,   923,    -1,    25,    -1,
    1095,    -1,  1094,     5,  1095,    -1,  1073,    -1,  1073,   399,
    1073,    -1,  1097,    -1,  1096,     5,  1097,    -1,  1085,    -1,
    1073,    -1,  1100,    -1,  1099,     5,  1100,    -1,  1073,  1101,
      -1,    -1,   566,    -1,   517,    -1,   915,   437,  1083,   405,
      -1,  1104,    -1,  1103,     5,  1104,    -1,  1073,    -1,  1073,
     399,  1073,    -1,   233,   911,   597,   905,   558,  1449,   663,
      -1,    -1,   597,   409,   824,     5,   824,   370,  1107,    -1,
      -1,   547,   409,   824,     5,   824,   370,    -1,   234,   915,
    1106,    -1,   915,    -1,   317,   913,  1111,    -1,  1112,    -1,
     525,   824,    -1,  1113,  1114,  1119,     8,  1109,    -1,    -1,
     597,  1115,   409,   824,     5,   824,   370,    -1,    -1,   535,
     916,    -1,    -1,   329,    -1,   196,  1422,   245,  1432,  1118,
      -1,   542,   908,    -1,   542,   908,     8,   842,   822,    -1,
      -1,   596,   555,  1416,   352,  1416,    -1,   596,   555,  1416,
       5,   352,  1416,    -1,   596,  1416,     5,  1416,    -1,    -1,
     628,    -1,   629,    -1,    69,  1432,  1121,  1122,    -1,    -1,
     596,  1432,    -1,    -1,   596,   555,  1416,     8,  1416,    -1,
     555,  1416,     8,  1416,    -1,   390,  1124,    -1,  1125,    -1,
    1124,     5,  1125,    -1,   182,   902,    -1,   263,   902,    -1,
     308,   902,    -1,   316,   902,    -1,   272,   902,    -1,   238,
     902,    -1,   990,    -1,   417,   991,    -1,   428,   991,    -1,
     540,   991,    -1,   353,   991,    -1,   529,   991,    -1,   527,
     903,    -1,   528,   903,    -1,   379,   659,    -1,   644,   659,
      -1,   270,    -1,   174,    -1,   130,    -1,   107,    -1,   125,
      -1,   116,    -1,  1421,   392,  1129,   525,  1127,    -1,  1073,
      -1,    24,    -1,   381,  1129,    -1,   381,  1129,     8,  1091,
      -1,   916,    -1,    -1,   440,  1138,   658,   574,  1133,  1073,
     914,   658,  1131,  1134,    -1,   440,  1138,   658,   323,  1073,
      -1,    -1,   514,    -1,    -1,  1135,   261,    -1,  1136,    -1,
    1135,  1136,    -1,    -1,   986,  1137,  1457,    -1,   823,    -1,
      -1,   583,   908,  1140,  1141,    -1,    -1,   525,  1142,    -1,
    1143,    -1,  1142,     5,  1143,    -1,  1409,    -1,   462,    -1,
     199,  1146,    67,    -1,   199,  1146,   605,  1145,    -1,   199,
    1146,    66,  1145,    -1,   199,  1146,    -1,    24,    -1,   922,
      -1,   915,    -1,    -1,   458,    -1,   124,  1146,  1147,   409,
     842,  1030,   370,    -1,   172,  1146,    -1,  1181,  1189,    -1,
     425,    40,    -1,   425,  1152,    -1,  1153,    -1,  1152,  1153,
      -1,    -1,   112,  1154,  1457,    -1,    -1,   178,  1155,  1457,
      -1,    -1,   207,  1156,  1457,    -1,    -1,   195,  1157,  1457,
      -1,    -1,   232,  1158,  1457,    -1,    -1,   180,  1073,  1159,
    1457,    -1,    -1,   203,  1073,  1160,  1457,    -1,  1171,    -1,
    1173,    -1,  1172,    -1,  1162,    -1,  1198,    -1,  1165,    -1,
      -1,   539,   824,  1163,   461,    -1,    -1,   461,    -1,    -1,
     548,   824,  1166,  1164,    -1,   137,    -1,   608,  1185,    -1,
     140,  1185,    -1,   139,  1185,    -1,    -1,  1168,    -1,  1169,
      -1,  1168,  1169,    -1,  1178,  1170,    -1,    -1,   597,  1185,
      -1,   498,  1167,  1177,    -1,   497,  1416,  1177,    -1,   496,
    1176,  1175,  1174,  1177,    -1,    -1,   131,   817,    -1,   131,
     817,     5,   817,    -1,   592,    -1,   593,    -1,   594,    -1,
     595,    -1,  1073,    -1,    -1,   500,    -1,  1179,    -1,  1178,
       5,  1179,    -1,   824,  1212,    -1,   588,   409,   817,   370,
    1197,    -1,    43,  1197,    -1,   475,   409,    20,   370,  1197,
      -1,   391,   409,    20,   370,  1197,    -1,   366,   409,   817,
     370,  1197,    -1,   567,   409,   817,   370,  1197,    -1,   580,
     409,   817,   370,  1197,    -1,   579,   409,   817,   370,  1197,
      -1,    -1,   439,  1182,    -1,  1183,    -1,  1182,  1183,    -1,
     206,    25,    -1,   197,    25,    -1,   280,    25,    -1,   163,
      25,    -1,   235,    25,    -1,   155,    -1,   322,    24,    -1,
     322,  1073,    -1,   156,    24,    -1,   138,    24,    -1,  1188,
      -1,  1184,  1188,    -1,  1186,    87,    -1,  1186,    89,    -1,
    1186,    88,    -1,  1186,    -1,   923,    -1,    25,    -1,    -1,
     439,  1184,    -1,   206,  1185,    -1,   197,  1185,    -1,   280,
    1185,    -1,   163,  1185,    -1,   235,  1185,    -1,   236,  1185,
      -1,   607,    24,    -1,   608,  1185,    -1,   612,    -1,   609,
      -1,   610,    -1,   611,    -1,   616,    -1,   613,    -1,   614,
      -1,   615,    -1,    56,  1185,    -1,    57,  1185,    -1,    58,
    1185,    -1,   322,    24,    -1,   156,    24,    -1,   378,    -1,
      52,    -1,    53,    -1,    -1,   493,   598,  1099,    -1,   113,
    1099,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   443,  1191,
     915,   409,  1192,  1089,   370,  1193,   732,  1194,  1150,  1195,
    1151,  1196,   218,    -1,    -1,   504,   817,    -1,   495,  1199,
      -1,    -1,  1127,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      84,  1201,   915,   409,  1202,  1089,   370,  1203,   732,  1204,
    1207,  1205,  1151,  1206,   218,    -1,  1187,  1189,    -1,    -1,
      -1,    -1,   133,   409,    24,     5,  1209,   685,  1210,   370,
    1211,   683,    -1,    -1,   362,    -1,   362,   197,    25,    -1,
     362,   197,  1073,    -1,   586,   824,    -1,   586,   824,   323,
    1073,    -1,   586,   824,   141,    -1,   586,   824,   556,    -1,
     586,   824,   523,    -1,  1215,    -1,   152,    -1,   302,    -1,
     260,    -1,  1217,    -1,    82,  1223,   370,    -1,    -1,    -1,
     185,  1218,  1367,   409,  1219,  1225,   370,    -1,    -1,    -1,
     110,  1220,  1367,   409,  1221,  1225,   370,  1222,    -1,    34,
     916,    -1,    -1,   247,    -1,  1224,    -1,  1223,     5,  1224,
      -1,   915,   566,    -1,   915,   517,    -1,   915,    -1,  1226,
      -1,  1225,     5,  1226,    -1,  1317,    -1,  1315,    -1,    99,
     915,    -1,   158,    -1,  1229,    -1,    33,   915,  1230,    -1,
    1231,    -1,  1230,     5,  1231,    -1,  1232,    -1,  1235,    -1,
    1238,    -1,  1243,    -1,  1244,    -1,  1242,    -1,  1241,    -1,
     563,  1233,    -1,   563,   409,  1234,   370,    -1,  1226,    -1,
    1226,   643,   915,    -1,  1233,    -1,  1234,     5,  1233,    -1,
     520,  1237,    -1,   520,   409,  1236,   370,    -1,  1237,    -1,
    1236,     5,  1237,    -1,   915,    -1,   433,  1240,    -1,   433,
     409,  1239,   370,    -1,  1240,    -1,  1239,     5,  1240,    -1,
    1226,    -1,    64,    -1,    65,    -1,    63,    25,    -1,    35,
    1320,    -1,    35,   409,  1245,   370,    -1,    36,  1246,    -1,
      36,   409,  1245,   370,    -1,  1320,    -1,  1245,     5,  1320,
      -1,   915,    -1,   244,    -1,   210,    -1,   143,  1249,    -1,
     120,    -1,   108,    -1,    98,    -1,    96,    -1,   100,    -1,
     157,  1422,    -1,   209,  1248,   438,  1416,   605,  1416,    -1,
     277,   908,   438,  1416,   605,  1416,    -1,    -1,  1422,    -1,
      -1,   824,    -1,   501,   824,    -1,    -1,    -1,   457,  1367,
    1252,   562,  1255,  1253,  1254,    -1,    -1,   128,   909,    -1,
     504,  1339,    -1,   409,  1259,   370,    13,   409,  1260,   370,
      -1,  1256,    -1,    20,    13,   409,  1260,   370,    -1,    20,
      13,  1260,    -1,  1258,    -1,  1256,     5,  1258,    -1,  1370,
      -1,  1257,    13,  1261,    -1,  1257,    -1,  1259,     5,  1257,
      -1,  1261,    -1,  1260,     5,  1261,    -1,  1404,    -1,   462,
      -1,  1409,    -1,   208,    -1,    -1,   227,  1264,  1367,  1267,
    1265,    -1,    -1,   458,  1266,   409,  1269,   370,    -1,  1403,
      -1,    -1,   409,  1268,   370,    -1,  1370,    -1,  1268,     5,
    1370,    -1,  1270,    -1,  1269,     5,  1270,    -1,  1409,    -1,
     462,    -1,    -1,    -1,   479,  1272,  1274,  1273,  1275,    -1,
    1279,   909,    -1,   909,    -1,    -1,    -1,   532,  1276,  1094,
      -1,    -1,    -1,   532,  1278,  1094,    -1,   480,    -1,   533,
      -1,   540,    -1,   353,    -1,   320,    -1,   374,    -1,   356,
     824,    -1,   329,   824,    -1,   216,  1367,   128,   909,    -1,
     216,  1367,  1336,    -1,   493,   598,  1283,    -1,  1284,    -1,
    1283,     5,  1284,    -1,  1285,  1286,    -1,    25,    -1,  1370,
      -1,    -1,   566,    -1,   517,    -1,   255,    -1,   288,    -1,
      -1,   305,    -1,   335,  1432,  1289,    -1,    -1,  1421,  1292,
    1293,    -1,  1321,    -1,  1325,    -1,  1288,    -1,  1423,    -1,
    1287,    -1,  1280,    -1,  1281,    -1,  1271,    -1,  1263,    -1,
    1262,    -1,  1393,    -1,  1251,    -1,   484,  1296,   604,  1367,
     605,  1301,  1295,    -1,    -1,   119,    -1,   147,    -1,  1297,
      -1,  1298,    -1,  1297,     5,  1298,    -1,   450,    -1,   428,
      -1,   417,    -1,   457,  1299,    -1,    -1,   409,  1300,   370,
      -1,  1370,    -1,  1300,     5,  1370,    -1,  1302,    -1,  1301,
       5,  1302,    -1,   441,    -1,  1368,    -1,   214,  1367,  1304,
     596,  1403,  1306,    -1,    -1,   409,  1305,   370,    -1,  1370,
      -1,  1305,     5,  1370,    -1,    -1,   118,    -1,   471,   409,
    1339,   370,    -1,   224,   409,  1310,   370,  1309,    -1,   275,
    1311,    -1,  1312,    -1,  1367,    -1,  1367,   409,  1312,   370,
      -1,  1370,    -1,  1312,     5,  1370,    -1,   455,   409,  1314,
     370,    -1,   237,   409,  1314,   370,    -1,  1370,    -1,  1314,
       5,  1370,    -1,  1313,    -1,  1308,    -1,  1307,    -1,   378,
    1372,    -1,   186,    -1,   915,  1359,  1318,  1319,    -1,    -1,
    1316,    -1,    -1,  1320,  1319,    -1,   351,    -1,   136,    -1,
    1309,    -1,   471,   409,  1339,   370,    -1,    97,  1322,  1324,
      -1,  1323,    -1,  1368,    -1,  1325,    -1,  1324,  1325,    -1,
    1303,    -1,  1294,    -1,   426,  1339,    -1,   347,  1328,    -1,
    1408,    -1,  1328,     5,  1408,    -1,   504,  1339,    -1,   525,
    1331,    -1,  1332,    -1,  1331,     5,  1332,    -1,  1333,    -1,
     494,  1333,    -1,   494,   409,  1334,   370,    -1,  1367,    -1,
    1367,  1371,    -1,  1332,    -1,  1334,     5,  1332,    -1,  1330,
    1336,  1337,  1338,    -1,    -1,  1329,    -1,    -1,  1327,    -1,
      -1,  1326,    -1,  1340,    -1,  1339,     6,  1340,    -1,  1341,
      -1,  1340,     7,  1341,    -1,  1342,    -1,   581,  1342,    -1,
    1357,    -1,   409,  1339,   370,    -1,   421,  1404,    -1,   273,
    1404,    -1,  1409,  1356,  1345,  1404,    -1,  1404,  1356,  1409,
      -1,    -1,  1346,    -1,  1347,    -1,   564,    -1,   549,    -1,
     565,    -1,   420,  1350,    -1,  1412,    -1,  1412,    -1,  1409,
     602,   409,  1352,   370,    -1,  1409,   602,  1404,    -1,  1409,
     407,   409,  1352,   370,    -1,  1409,   407,  1404,    -1,  1353,
      -1,  1352,     5,  1353,    -1,  1436,    -1,  1372,    -1,    -1,
     581,    -1,  1409,  1354,   365,    -1,  1409,  1354,   228,    -1,
    1409,  1356,  1409,    -1,  1409,  1356,  1404,    -1,  1409,  1354,
     367,  1409,     7,  1409,    -1,  1409,  1354,   535,  1349,  1348,
      -1,    13,    -1,    16,    -1,    11,    -1,    12,    -1,   231,
      -1,   350,    -1,     9,    -1,   535,    -1,    15,    -1,    14,
      -1,  1355,    -1,  1351,    -1,  1344,    -1,  1343,    -1,    -1,
     564,    -1,   338,    -1,   455,    -1,  1360,    -1,  1361,    -1,
    1363,    -1,   514,    -1,   514,   409,  1364,   370,    -1,   389,
     409,  1365,  1362,   370,    -1,   451,    -1,   376,   409,  1365,
    1362,   370,    -1,   491,   409,  1365,  1362,   370,    -1,   516,
      -1,   386,    -1,   358,    -1,   336,  1379,   605,  1380,    -1,
     336,    -1,   348,  1379,   605,  1380,    -1,   348,    -1,   348,
    1379,   409,    25,   370,   605,  1380,    -1,   553,    -1,   511,
      -1,   402,    -1,   402,   409,    25,   370,    -1,   402,   409,
      25,     5,    25,   370,    -1,    -1,     5,  1366,    -1,   481,
     409,  1365,   370,    -1,   544,    -1,   278,    -1,   481,    -1,
      42,    -1,    25,    -1,    25,    -1,    25,    -1,    24,   599,
     915,    -1,    24,    -1,   915,    -1,   915,   568,   915,    -1,
     915,    -1,    -1,   437,    25,   405,    -1,   437,    25,     5,
      25,   405,    -1,   915,  1369,    -1,  1367,   919,   599,   915,
    1369,    -1,  1367,   919,   599,    20,    -1,   915,    -1,    24,
      -1,   389,    -1,   923,    -1,    25,    -1,    17,   923,    -1,
      17,    25,    -1,    18,   923,    -1,    18,    25,    -1,  1374,
      -1,   374,  1376,    -1,   374,  1375,    -1,    -1,  1379,   605,
    1380,    -1,    -1,  1377,   605,  1378,    -1,   560,    -1,   492,
      -1,   569,    -1,   531,    -1,   432,    -1,   449,    -1,   345,
      -1,   345,   409,    25,   370,    -1,   560,    -1,   492,    -1,
     569,    -1,   531,    -1,   432,    -1,   449,    -1,   345,    -1,
     345,   409,    25,   370,    -1,   560,    -1,   492,    -1,   569,
      -1,   531,    -1,   432,    -1,   449,    -1,   345,    -1,   560,
      -1,   492,    -1,   569,    -1,   531,    -1,   432,    -1,   449,
      -1,   345,    -1,   915,    -1,    24,    -1,  1421,   482,   909,
      -1,    -1,  1421,   377,   909,   415,   574,  1391,  1384,  1388,
      -1,    -1,  1421,   377,   909,   415,    79,   574,  1392,  1385,
    1388,    -1,    -1,  1421,   377,   909,   114,  1392,  1386,  1388,
      -1,    -1,  1421,   377,   909,   115,    79,   574,  1392,  1387,
    1388,    -1,    -1,   267,    -1,   266,  1389,    -1,  1390,    -1,
    1389,     5,  1390,    -1,   915,    -1,   915,   599,   915,    -1,
      24,   599,   915,   599,   915,    -1,  1392,    -1,  1263,    -1,
    1129,    -1,  1394,    -1,  1394,  1388,    -1,    -1,    -1,   450,
    1405,  1406,  1395,  1402,  1396,  1335,  1400,    -1,   450,  1405,
    1406,  1335,  1400,    -1,  1399,    -1,  1416,    -1,   450,   919,
    1405,  1406,  1402,  1335,  1400,    -1,    -1,   503,  1358,  1398,
      -1,  1282,    -1,   310,  1401,  1222,    -1,  1282,   310,  1401,
    1222,    -1,   915,    -1,    -1,   532,  1094,    -1,   450,   919,
    1405,  1406,  1335,    -1,   409,   450,   919,  1405,  1406,  1335,
     370,    -1,    -1,   564,    -1,   338,    -1,   455,    -1,  1407,
      -1,  1406,     5,  1407,    -1,  1409,    -1,  1409,  1456,    -1,
    1409,   924,    -1,  1409,    -1,  1410,    -1,  1436,    -1,  1409,
      19,  1409,    -1,  1409,  1430,    -1,  1409,    20,  1409,    -1,
    1409,    17,  1409,    -1,  1409,    18,  1409,    -1,  1372,    -1,
     463,    -1,   406,    -1,   555,    -1,    20,    -1,    43,    -1,
     567,   409,  1358,  1409,   370,    -1,   579,   409,  1358,  1409,
     370,    -1,   580,   409,  1358,  1409,   370,    -1,   588,   409,
    1358,  1409,   370,    -1,   475,   409,  1358,  1409,   370,    -1,
     915,   409,  1411,   370,    -1,   516,   919,   409,   919,  1411,
     370,    -1,   409,  1409,   370,    -1,   422,   409,  1431,   370,
      -1,  1409,    -1,  1411,     5,  1409,    -1,    -1,  1372,    -1,
    1421,   325,  1420,  1415,  1398,    -1,  1421,   314,  1420,  1415,
     227,  1367,  1417,    -1,    -1,   300,  1416,    -1,    24,    -1,
    1073,    -1,    -1,   409,  1418,   370,    -1,  1419,    -1,  1418,
       5,  1419,    -1,   915,    -1,    24,    -1,  1073,    -1,    -1,
     246,  1422,   574,    -1,   916,    -1,  1428,    -1,  1427,    -1,
    1424,    -1,   295,  1425,   605,  1425,    -1,   276,  1425,   599,
    1426,   605,  1426,    -1,   915,    -1,   915,    -1,   200,   767,
      -1,   271,   767,  1429,    -1,   250,    -1,   154,    -1,    71,
      -1,    72,    -1,    73,    -1,    74,    -1,    75,    -1,    76,
      -1,   374,     5,  1379,   605,  1380,    -1,  1370,     5,  1379,
     605,  1380,    -1,   374,  1379,   605,  1380,    -1,  1433,    -1,
     591,  1434,    -1,  1434,    -1,  1102,    -1,   915,    -1,  1434,
     599,  1435,    -1,    24,   599,  1434,   599,  1435,    -1,    20,
      -1,  1102,    -1,   915,    -1,  1433,    -1,  1433,   399,  1433,
      -1,   105,  1438,    -1,   109,  1438,    -1,   104,  1438,    -1,
     144,    -1,   145,  1438,    -1,   102,  1438,    -1,   127,  1438,
      -1,   126,  1438,    -1,   101,  1438,    -1,   334,    -1,   600,
     605,  1439,    -1,   526,  1439,    -1,   551,    -1,   512,  1440,
      -1,   915,    -1,   568,   915,    -1,   915,    -1,    -1,    -1,
     505,  1442,   824,  1443,  1457,   304,    -1,    -1,   638,  1447,
      -1,    -1,   641,    -1,   160,    -1,   256,   910,    -1,    48,
     910,    -1,   286,    -1,   285,    -1,   287,   912,  1444,  1445,
      -1,   472,  1447,  1445,    -1,   907,    -1,  1447,     5,   907,
      -1,    81,    -1,   111,   910,    -1,   824,   545,     5,   824,
     371,    -1,   488,   824,    -1,   243,   910,    -1,    80,  1452,
       8,  1453,  1451,    -1,    -1,   525,   824,    -1,   915,    -1,
     915,    -1,   226,   910,    -1,   229,   910,   605,   824,     5,
     824,    -1,   229,   910,   598,   824,     5,   824,    -1,    26,
      -1,    -1,  1459,    -1,  1460,  1177,    -1,  1458,    -1,  1459,
    1458,    -1,    -1,  1461,  1462,    -1,   648,    -1,   649,    -1,
     650,    -1,   651,    -1,   668,    -1,   690,    -1,   704,    -1,
     705,    -1,   711,    -1,   712,    -1,   731,    -1,   799,    -1,
     800,    -1,   801,    -1,   802,    -1,   813,    -1,   814,    -1,
     815,    -1,   816,    -1,   867,    -1,   871,    -1,   901,    -1,
     925,    -1,   926,    -1,   929,    -1,   930,    -1,   931,    -1,
     932,    -1,   945,    -1,   953,    -1,   976,    -1,   977,    -1,
     979,    -1,   983,    -1,   998,    -1,   999,    -1,  1003,    -1,
    1004,    -1,  1005,    -1,  1006,    -1,  1014,    -1,  1029,    -1,
    1042,    -1,  1053,    -1,  1054,    -1,  1055,    -1,  1066,    -1,
    1105,    -1,  1108,    -1,  1110,    -1,  1116,    -1,  1117,    -1,
    1120,    -1,  1123,    -1,  1126,    -1,  1128,    -1,  1130,    -1,
    1132,    -1,  1139,    -1,  1144,    -1,  1148,    -1,  1149,    -1,
    1161,    -1,  1213,    -1,  1214,    -1,  1216,    -1,  1227,    -1,
    1228,    -1,  1247,    -1,  1250,    -1,  1290,    -1,  1291,    -1,
    1382,    -1,  1383,    -1,  1413,    -1,  1414,    -1,  1437,    -1,
    1441,    -1,  1446,    -1,  1448,    -1,  1450,    -1,  1454,    -1,
    1455,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const unsigned short yyrline[] =
{
       0,   879,   879,   882,   885,   891,   897,   904,   908,   908,
     914,   932,   933,   934,   935,   936,   950,   951,   952,   953,
     954,   959,   960,   971,   974,   977,   977,   981,   984,   985,
     991,   992,   993,   994,   995,   996,   997,   998,   999,  1000,
    1001,  1002,  1003,  1004,  1005,  1006,  1009,  1010,  1013,  1013,
    1021,  1022,  1025,  1031,  1033,  1044,  1046,  1048,  1050,  1054,
    1056,  1118,  1122,  1126,  1126,  1133,  1136,  1140,  1141,  1144,
    1150,  1144,  1163,  1168,  1172,  1163,  1184,  1188,  1184,  1197,
    1202,  1197,  1221,  1228,  1232,  1220,  1258,  1258,  1262,  1263,
    1264,  1269,  1272,  1277,  1281,  1289,  1292,  1292,  1298,  1302,
    1317,  1315,  1333,  1333,  1348,  1348,  1351,  1351,  1355,  1358,
    1358,  1358,  1365,  1366,  1365,  1373,  1373,  1384,  1384,  1403,
    1406,  1409,  1412,  1415,  1418,  1431,  1436,  1436,  1437,  1437,
    1440,  1445,  1445,  1449,  1459,  1473,  1477,  1472,  1487,  1493,
    1501,  1502,  1505,  1505,  1508,  1512,  1517,  1524,  1524,  1528,
    1528,  1535,  1535,  1540,  1540,  1545,  1545,  1550,  1550,  1563,
    1564,  1572,  1573,  1590,  1593,  1596,  1599,  1602,  1605,  1611,
    1622,  1627,  1640,  1644,  1659,  1660,  1664,  1664,  1668,  1668,
    1668,  1669,  1670,  1675,  1675,  1678,  1678,  1687,  1688,  1689,
    1692,  1696,  1697,  1697,  1714,  1714,  1714,  1714,  1718,  1725,
    1726,  1729,  1729,  1732,  1732,  1741,  1738,  1754,  1754,  1756,
    1756,  1758,  1760,  1762,  1764,  1767,  1771,  1771,  1772,  1772,
    1776,  1776,  1788,  1788,  1793,  1797,  1799,  1800,  1803,  1803,
    1803,  1807,  1808,  1809,  1810,  1817,  1818,  1819,  1820,  1823,
    1824,  1825,  1826,  1830,  1835,  1840,  1844,  1847,  1851,  1852,
    1853,  1854,  1855,  1856,  1857,  1858,  1861,  1862,  1863,  1895,
    1899,  1901,  1903,  1903,  1910,  1916,  1916,  1920,  1921,  1922,
    1923,  1924,  1925,  1926,  1932,  1932,  1935,  1937,  1943,  1945,
    1951,  1959,  1959,  1962,  1963,  1964,  1965,  1966,  1967,  1968,
    1974,  1977,  1977,  1990,  1990,  1997,  1998,  1999,  2001,  2002,
    2004,  2006,  2007,  2008,  2009,  2014,  2020,  2026,  2027,  2029,
    2031,  2032,  2033,  2034,  2035,  2036,  2039,  2040,  2047,  2055,
    2055,  2063,  2060,  2075,  2075,  2077,  2077,  2085,  2085,  2088,
    2091,  2092,  2097,  2109,  2113,  2116,  2119,  2120,  2121,  2122,
    2123,  2128,  2135,  2141,  2146,  2150,  2146,  2161,  2163,  2168,
    2173,  2173,  2177,  2177,  2180,  2180,  2186,  2186,  2192,  2192,
    2208,  2211,  2225,  2227,  2229,  2231,  2233,  2235,  2237,  2243,
    2245,  2249,  2251,  2253,  2255,  2257,  2259,  2261,  2267,  2282,
    2285,  2298,  2299,  2300,  2301,  2302,  2306,  2307,  2308,  2312,
    2317,  2324,  2325,  2326,  2327,  2328,  2329,  2330,  2331,  2332,
    2333,  2338,  2338,  2343,  2343,  2346,  2352,  2360,  2366,  2376,
    2377,  2385,  2392,  2396,  2406,  2410,  2415,  2420,  2422,  2432,
    2445,  2453,  2466,  2471,  2477,  2482,  2487,  2488,  2494,  2565,
    2571,  2576,  2584,  2584,  2600,  2604,  2611,  2614,  2622,  2633,
    2643,  2649,  2658,  2663,  2671,  2675,  2679,  2683,  2690,  2698,
    2706,  2711,  2715,  2720,  2724,  2728,  2735,  2738,  2741,  2745,
    2749,  2753,  2757,  2765,  2775,  2780,  2773,  2795,  2800,  2795,
    2817,  2817,  2817,  2820,  2820,  2820,  2823,  2823,  2823,  2826,
    2826,  2826,  2829,  2835,  2841,  2847,  2857,  2857,  2861,  2865,
    2866,  2872,  2873,  2878,  2881,  2885,  2889,  2890,  2893,  2898,
    2904,  2908,  2912,  2915,  2921,  2924,  2927,  2942,  2945,  2951,
    2952,  2953,  2957,  2958,  2959,  2960,  2961,  2963,  2964,  2965,
    2967,  2968,  2972,  2973,  2987,  2991,  2986,  2999,  3002,  3016,
    3020,  3025,  3015,  3045,  3051,  3045,  3065,  3065,  3067,  3068,
    3072,  3072,  3076,  3076,  3081,  3081,  3088,  3089,  3093,  3093,
    3097,  3097,  3102,  3102,  3109,  3113,  3114,  3115,  3120,  3120,
    3123,  3123,  3127,  3127,  3131,  3131,  3135,  3135,  3140,  3140,
    3145,  3145,  3150,  3150,  3155,  3155,  3171,  3188,  3189,  3190,
    3191,  3192,  3193,  3196,  3196,  3199,  3201,  3204,  3207,  3209,
    3210,  3211,  3213,  3215,  3217,  3219,  3223,  3230,  3232,  3238,
    3243,  3248,  3253,  3253,  3256,  3262,  3267,  3270,  3277,  3277,
    3279,  3285,  3289,  3290,  3292,  3294,  3296,  3298,  3302,  3311,
    3311,  3318,  3319,  3320,  3321,  3322,  3323,  3324,  3325,  3326,
    3327,  3328,  3329,  3330,  3331,  3332,  3333,  3334,  3335,  3336,
    3337,  3338,  3339,  3340,  3341,  3342,  3343,  3344,  3345,  3346,
    3347,  3348,  3349,  3350,  3351,  3352,  3353,  3354,  3355,  3356,
    3357,  3358,  3359,  3360,  3372,  3385,  3392,  3392,  3396,  3401,
    3407,  3411,  3415,  3421,  3425,  3429,  3435,  3435,  3443,  3444,
    3448,  3448,  3452,  3453,  3456,  3459,  3459,  3462,  3464,  3464,
    3467,  3469,  3469,  3470,  3472,  3472,  3481,  3479,  3491,  3491,
    3491,  3494,  3496,  3494,  3503,  3509,  3519,  3519,  3523,  3529,
    3529,  3533,  3534,  3545,  3546,  3548,  3550,  3555,  3555,  3559,
    3558,  3565,  3564,  3570,  3570,  3575,  3575,  3581,  3581,  3586,
    3586,  3591,  3591,  3596,  3596,  3601,  3601,  3609,  3610,  3618,
    3619,  3624,  3625,  3634,  3635,  3642,  3643,  3651,  3652,  3661,
    3666,  3671,  3672,  3673,  3677,  3676,  3687,  3692,  3697,  3697,
    3708,  3713,  3714,  3715,  3716,  3719,  3719,  3725,  3725,  3727,
    3730,  3730,  3732,  3736,  3736,  3739,  3740,  3743,  3743,  3748,
    3748,  3751,  3752,  3753,  3754,  3755,  3756,  3757,  3758,  3759,
    3760,  3761,  3762,  3763,  3764,  3765,  3766,  3770,  3788,  3788,
    3788,  3814,  3825,  3832,  3838,  3844,  3850,  3861,  3884,  3883,
    3900,  3900,  3904,  3905,  3913,  3914,  3915,  3916,  3923,  3924,
    3926,  3927,  3931,  3936,  3937,  3938,  3939,  3940,  3941,  3942,
    3943,  3944,  3945,  3946,  3949,  3949,  3951,  3951,  3951,  3953,
    3957,  3957,  3966,  3971,  3984,  3990,  3965,  4004,  4018,  4028,
    4017,  4041,  4048,  4048,  4053,  4058,  4063,  4064,  4067,  4067,
    4067,  4070,  4070,  4078,  4084,  4098,  4102,  4115,  4097,  4133,
    4133,  4146,  4157,  4156,  4168,  4164,  4181,  4178,  4191,  4191,
    4193,  4194,  4196,  4197,  4200,  4201,  4202,  4204,  4209,  4214,
    4220,  4222,  4223,  4226,  4227,  4230,  4232,  4241,  4247,  4241,
    4258,  4259,  4263,  4263,  4273,  4273,  4285,  4288,  4292,  4296,
    4301,  4305,  4306,  4307,  4308,  4309,  4313,  4313,  4315,  4315,
    4318,  4327,  4365,  4365,  4368,  4372,  4377,  4415,  4416,  4417,
    4420,  4434,  4446,  4446,  4451,  4452,  4458,  4513,  4518,  4525,
    4530,  4538,  4544,  4565,  4568,  4569,  4607,  4608,  4612,  4613,
    4617,  4670,  4674,  4677,  4683,  4694,  4701,  4709,  4709,  4712,
    4713,  4714,  4715,  4716,  4719,  4722,  4728,  4731,  4735,  4739,
    4746,  4751,  4758,  4761,  4767,  4769,  4769,  4769,  4773,  4787,
    4794,  4801,  4804,  4818,  4825,  4826,  4829,  4830,  4834,  4840,
    4845,  4851,  4852,  4857,  4861,  4861,  4865,  4866,  4869,  4870,
    4874,  4882,  4885,  4891,  4892,  4894,  4896,  4900,  4900,  4901,
    4906,  4914,  4915,  4920,  4921,  4923,  4936,  4938,  4939,  4941,
    4944,  4947,  4950,  4953,  4956,  4959,  4963,  4967,  4971,  4974,
    4978,  4981,  4982,  4983,  4986,  4989,  4992,  4995,  4998,  5001,
    5004,  5020,  5028,  5028,  5030,  5037,  5044,  5059,  5057,  5077,
    5082,  5083,  5087,  5088,  5090,  5091,  5093,  5093,  5101,  5110,
    5110,  5120,  5121,  5124,  5125,  5128,  5128,  5140,  5145,  5150,
    5155,  5165,  5165,  5169,  5172,  5172,  5174,  5184,  5191,  5193,
    5197,  5200,  5200,  5204,  5203,  5207,  5206,  5210,  5209,  5213,
    5212,  5216,  5215,  5218,  5218,  5234,  5233,  5255,  5256,  5257,
    5258,  5259,  5260,  5263,  5263,  5269,  5269,  5272,  5272,  5282,
    5283,  5284,  5291,  5303,  5304,  5307,  5308,  5311,  5314,  5314,
    5319,  5323,  5328,  5334,  5335,  5336,  5340,  5341,  5342,  5343,
    5347,  5357,  5359,  5364,  5367,  5372,  5378,  5385,  5392,  5401,
    5408,  5415,  5422,  5429,  5438,  5438,  5440,  5440,  5443,  5444,
    5445,  5446,  5447,  5448,  5449,  5450,  5451,  5452,  5455,  5455,
    5458,  5459,  5460,  5461,  5464,  5464,  5467,  5467,  5470,  5471,
    5472,  5473,  5474,  5475,  5476,  5477,  5479,  5480,  5481,  5482,
    5484,  5485,  5486,  5487,  5489,  5490,  5491,  5492,  5493,  5494,
    5495,  5496,  5500,  5506,  5514,  5525,  5534,  5545,  5549,  5553,
    5559,  5524,  5572,  5575,  5583,  5595,  5597,  5602,  5607,  5617,
    5620,  5624,  5632,  5601,  5641,  5645,  5649,  5653,  5645,  5663,
    5664,  5665,  5666,  5671,  5673,  5676,  5680,  5683,  5690,  5695,
    5696,  5697,  5701,  5708,  5710,  5710,  5710,  5712,  5712,  5712,
    5714,  5720,  5721,  5727,  5728,  5733,  5734,  5735,  5739,  5740,
    5745,  5746,  5752,  5753,  5758,  5762,  5768,  5769,  5774,  5775,
    5776,  5777,  5778,  5779,  5780,  5785,  5788,  5795,  5796,  5802,
    5803,  5810,  5813,  5820,  5821,  5826,  5830,  5833,  5839,  5840,
    5846,  5851,  5852,  5856,  5862,  5863,  5870,  5871,  5876,  5877,
    5882,  5893,  5894,  5895,  5896,  5897,  5898,  5899,  5900,  5901,
    5904,  5907,  5913,  5913,  5919,  5919,  5930,  5944,  5946,  5944,
    5953,  5956,  5961,  5969,  5978,  5979,  5988,  6007,  6007,  6014,
    6016,  6022,  6023,  6026,  6027,  6031,  6032,  6033,  6037,  6047,
    6047,  6053,  6053,  6056,  6059,  6060,  6066,  6067,  6072,  6073,
    6078,  6079,  6084,  6088,  6083,  6100,  6104,  6111,  6115,  6115,
    6128,  6132,  6132,  6147,  6149,  6151,  6153,  6155,  6157,  6159,
    6161,  6167,  6177,  6182,  6187,  6188,  6192,  6194,  6195,  6198,
    6199,  6200,  6203,  6208,  6215,  6216,  6222,  6235,  6235,  6240,
    6245,  6251,  6252,  6255,  6256,  6263,  6270,  6274,  6284,  6285,
    6289,  6297,  6301,  6302,  6307,  6309,  6313,  6314,  6318,  6319,
    6320,  6321,  6325,  6326,  6331,  6332,  6337,  6338,  6343,  6344,
    6349,  6353,  6354,  6359,  6360,  6364,  6365,  6370,  6376,  6381,
    6386,  6390,  6391,  6396,  6397,  6403,  6405,  6410,  6411,  6417,
    6418,  6419,  6424,  6426,  6437,  6441,  6442,  6445,  6446,  6451,
    6453,  6455,  6456,  6462,  6467,  6472,  6476,  6477,  6482,  6483,
    6492,  6498,  6503,  6504,  6509,  6514,  6518,  6519,  6524,  6525,
    6526,  6529,  6530,  6535,  6535,  6539,  6550,  6551,  6554,  6555,
    6558,  6559,  6564,  6565,  6570,  6571,  6576,  6577,  6582,  6583,
    6589,  6590,  6595,  6597,  6602,  6603,  6604,  6607,  6611,  6612,
    6620,  6625,  6629,  6634,  6636,  6638,  6640,  6646,  6647,  6651,
    6651,  6654,  6655,  6660,  6662,  6664,  6666,  6668,  6670,  6676,
    6677,  6678,  6679,  6680,  6681,  6682,  6683,  6684,  6685,  6690,
    6691,  6692,  6693,  6695,  6696,  6697,  6698,  6710,  6711,  6712,
    6716,  6717,  6722,  6724,  6725,  6726,  6728,  6729,  6730,  6731,
    6733,  6734,  6736,  6737,  6739,  6740,  6741,  6742,  6744,  6748,
    6749,  6755,  6757,  6758,  6759,  6760,  6765,  6769,  6773,  6777,
    6778,  6782,  6783,  6790,  6798,  6799,  6800,  6803,  6808,  6813,
    6823,  6827,  6831,  6832,  6833,  6834,  6836,  6838,  6840,  6842,
    6845,  6848,  6852,  6853,  6857,  6858,  6862,  6862,  6862,  6862,
    6862,  6862,  6863,  6866,  6871,  6871,  6871,  6871,  6871,  6871,
    6873,  6876,  6882,  6882,  6882,  6882,  6882,  6882,  6882,  6883,
    6883,  6883,  6883,  6883,  6883,  6883,  6885,  6886,  6889,  6899,
    6898,  6904,  6904,  6910,  6910,  6916,  6916,  6926,  6927,  6928,
    6931,  6931,  6934,  6935,  6936,  6941,  6942,  6948,  6951,  6956,
    6970,  6972,  6967,  6985,  6994,  6994,  6997,  7005,  7006,  7010,
    7011,  7012,  7016,  7019,  7020,  7029,  7034,  7038,  7039,  7040,
    7041,  7049,  7050,  7054,  7055,  7056,  7061,  7066,  7069,  7073,
    7075,  7077,  7079,  7081,  7083,  7084,  7085,  7086,  7087,  7088,
    7090,  7092,  7094,  7096,  7098,  7100,  7102,  7104,  7105,  7109,
    7109,  7111,  7112,  7115,  7123,  7128,  7128,  7132,  7132,  7137,
    7137,  7141,  7141,  7145,  7151,  7151,  7154,  7154,  7160,  7167,
    7168,  7169,  7173,  7174,  7177,  7178,  7182,  7188,  7198,  7199,
    7207,  7208,  7209,  7210,  7211,  7212,  7216,  7217,  7218,  7301,
    7313,  7313,  7317,  7318,  7319,  7320,  7324,  7325,  7326,  7329,
    7341,  7439,  7441,  7443,  7445,  7449,  7454,  7456,  7458,  7460,
    7464,  7467,  7472,  7477,  7481,  7490,  7491,  7495,  7507,  7510,
    7506,  7529,  7529,  7533,  7534,  7537,  7538,  7539,  7540,  7541,
    7542,  7543,  7548,  7549,  7553,  7556,  7561,  7565,  7570,  7574,
    7579,  7583,  7586,  7590,  7593,  7598,  7602,  7613,  7619,  7619,
    7620,  7621,  7628,  7637,  7637,  7639,  7640,  7641,  7642,  7643,
    7644,  7645,  7646,  7647,  7648,  7649,  7650,  7651,  7652,  7653,
    7654,  7655,  7656,  7657,  7658,  7659,  7660,  7661,  7662,  7663,
    7664,  7665,  7666,  7667,  7668,  7669,  7670,  7671,  7672,  7673,
    7674,  7675,  7676,  7677,  7678,  7679,  7680,  7681,  7682,  7683,
    7684,  7685,  7686,  7687,  7688,  7689,  7690,  7691,  7692,  7693,
    7694,  7695,  7696,  7697,  7698,  7699,  7700,  7701,  7702,  7703,
    7704,  7705,  7706,  7707,  7708,  7709,  7710,  7711,  7712,  7713,
    7714,  7715,  7716,  7717,  7718,  7719,  7720,  7721
};
#endif

#if YYDEBUG || YYERROR_VERBOSE
/* YYTNME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals. */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "NAME", "UMINUS", "COMMA", "KW_OR", 
  "KW_AND", "KW_USING", "MATCHES", "POWER", "LESS_THAN", "GREATER_THAN", 
  "EQUAL", "GREATER_THAN_EQ", "LESS_THAN_EQ", "NOT_EQUAL", "PLUS", 
  "MINUS", "DIVIDE", "MULTIPLY", "MOD", "COMMAND", "NUMBER_VALUE", 
  "CHAR_VALUE", "INT_VALUE", "NAMED_GEN", "CLINE", "SQLLINE", "KW_CSTART", 
  "KW_CEND", "USER_DTYPE", "SQL_TEXT", "ALTER_TABLE", "CREATE_DATABASE", 
  "ADD_CONSTRAINT", "DROP_CONSTRAINT", "AS_STATIC", "NOT_FIELD_TOUCHED", 
  "LOCAL_FUNCTION", "EVERY_ROW", "ELIF", "DOUBLE_PRECISION", 
  "COUNT_MULTIPLY", "NEWFORMATSHARED", "WAIT_FOR_KEY", 
  "AT_TERMINATION_CALL", "TO_MAIN_CAPTION", "CLEARSTAT", "TO_MENUITEM", 
  "ID_TO_INT", "TO_STATUSBOX", "ASCII_HEIGHT_ALL", "ASCII_WIDTH_ALL", 
  "IMPORT_DATATYPE", "UP_BY", "PAGE_TRAILER_SIZE", "PAGE_HEADER_SIZE", 
  "FIRST_PAGE_HEADER_SIZE", "BYTES_USE_AS_IMAGE", "BYTES_USE_AS_ASCII", 
  "DOWN_BY", "CLOSE_STATUSBOX", "MODIFY_NEXT_SIZE", "LOCK_MODE_PAGE", 
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
  "WITHOUT_WAITING", "BEFCONSTRUCT", "SQLSLMW", "WHENEVER_ERROR_CONTINUE", 
  "WHENEVER_ERROR", "AFTCONSTRUCT", "ALL_PRIVILEGES", "CLOSE_DATABASE", 
  "CONTINUE_INPUT", "CONTINUE_WHILE", "CREATE_SYNONYM", "DROP_TABLE", 
  "EXIT_CONSTRUCT", "INEXCLUSIVE", "REPORT_TO_PRINTER", "REPORT_TO_PIPE", 
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
  "NEXTFORM", "RENTAB", "ASCENDING", "ASSOCIATE", "CHARACTER", 
  "CONSTRUCT", "DELIMITER", "DOWNSHIFT", "DROP_VIEW", "END_INPUT", 
  "END_WHILE", "EXCLUSIVE", "EXIT_CASE", "EXIT_MENU", "FORM_LINE", 
  "INTERRUPT", "INTO_TEMP", "INVISIBLE", "IN_MEMORY", "LINKED_TO", 
  "LOAD_FROM", "LOCKTAB", "MENU_LINE", "OPEN_FORM", "OTHERWISE", 
  "PRECISION", "PRIOR", "PROCEDURE", "REPORT_TO", "RETURNING", 
  "UNDERLINE", "UNLOAD_TO", "BEFROW", "UNLOAD_T", "VARIABLE", "ABSOLUTE", 
  "AFTROW", "BUFFERED", "CONSTANT", "CONST", "CONTINUE", "DATABASE", 
  "DATETIME", "DEFAULTS", "DISTINCT", "END_CASE", "END_MAIN", "END_MENU", 
  "END_TYPE", "EXIT_FOR", "EXTERNAL", "FRACTION", "FUNCTION", "GROUP_BY", 
  "INTERVAL", "KWMESSAGE", "NOT_LIKE", "NOT_NULL", "PASSWORD", "PREVIOUS", 
  "READONLY", "REGISTER", "RELATIVE", "RESOURCE", "SMALLINT", "VALIDATE", 
  "WHENEVER", "WITH_LOG", "WORDWRAP", "BY_NAME", "IN_FILE", "IS_NULL", 
  "AVERAGE", "BETWEEN", "CAPTION", "CLIPPED", "CLOSE_BRACKET", "COLUMNS", 
  "COMMENT", "CONNECT", "CURRENT", "DBYNAME", "DECIMAL", "DECLARE", 
  "DEFAULT", "DISPLAY", "ENDCODE", "EXECUTE", "FOREACH", "FOREIGN", 
  "GLOBALS", "INFIELD", "INTEGER", "KWWINDOW", "MAGENTA", "NUMERIC", 
  "OPTIONS", "PERCENT", "PREPARE", "PROGRAM", "RECOVER", "REVERSE", 
  "SECTION", "SESSION", "SYNONYM", "THRU", "TRAILER", "UPSHIFT", 
  "VARCHAR", "WAITING", "CLOSE_SHEV", "CLOSE_SQUARE", "KW_FALSE", 
  "NOT_IN", "ONKEY", "OPEN_BRACKET", "BORDER", "BOTTOM", "COLUMN", 
  "COMMIT", "CREATE", "CURSOR", "DEFINE", "DELETE", "DOUBLE", "END_IF", 
  "ESCAPE", "EXISTS", "EXTEND", "EXTENT", "FINISH", "FORMAT", "HAVING", 
  "HEADER", "INSERT", "LOCATE", "MARGIN", "MEMORY", "MINUTE", "MODIFY", 
  "NORMAL", "EQUAL_EQUAL", "OPEN_SHEV", "OPEN_SQUARE", "OPTION", "OUTPUT", 
  "PROMPT", "PUBLIC", "RECORD", "REPORT", "RETURN", "REVOKE", "SCHEMA", 
  "SCROLL_USING", "SCROLL", "SECOND", "SELECT", "SERIAL", "SETL", 
  "SHARED", "SPACES", "UNIQUE", "UNLOCK", "UPDATE", "VALUES", "YELLOW", 
  "AFTER", "KWLINE", "KW_NULL", "KW_TRUE", "SINGLE_KEY", "ALTER", "ARRAY", 
  "ASCII", "AUDIT", "BLACK", "BLINK", "CHECK", "CLEAR", "CLOSE", "CODE_C", 
  "COUNT", "DEFER", "ERROR", "EVERY", "FETCH", "FIRST", "FLOAT", "FLUSH", 
  "FOUND", "GRANT", "GREEN", "GROUP", "INDEX", "KWFORM", "LABEL", "LOCAL", 
  "MONEY", "MONTH", "ORDER", "OUTER", "PAUSE", "PRINT_IMAGE", 
  "PRINT_FILE", "PRINT", "RIGHT", "SEMICOLON", "SLEEP", "TUPLE", "UNION", 
  "WHERE", "WHILE", "WHITE", "CCODE", "ANSI", "BLUE", "BOLD", "BYTE", 
  "FCALL", "CASE", "CHAR", "CYAN", "DATE", "DESC", "DOWN", "TAB", "DROP", 
  "ELSE", "EXEC", "EXIT", "FREE", "FROM", "GOTO", "HELP_FILE", 
  "LANG_FILE", "HELP", "HIDE", "HOUR", "INTO", "LAST", "LEFT", "LIKE", 
  "MAIN", "MENU", "MODE", "NEED", "NEXT", "NOCR", "OPEN", "QUIT", "REAL", 
  "ROWS", "SHOW", "SIZE", "SKIP", "SOME", "STEP", "STOP", "TEMP", "TEXT", 
  "THEN", "USER", "WAIT", "WHEN", "WITH", "WORK", "YEAR", "KW_IS", "XSET", 
  "ADD", "ALL", "ANY", "ASC", "AVG", "COLON", "DAY", "DBA", "DEC", "DIM", 
  "FKEY", "FOR", "KEY", "KWNO", "LET", "LOG", "XMAX", "XMIN", "NOT", 
  "PAD", "PUT", "RED", "ROW", "RUN", "SQL", "SUM", "TOP", "USE", "ATSIGN", 
  "AS_TIFF", "AS_GIF", "AS_PNG", "AS_JPEG", "AS", "AT", "BY", "DOT", "GO", 
  "IF", "IN", "OF", "ON", "TO", "UP", "FONT_NAME", "FONT_SIZE", 
  "PAPER_SIZE_IS_LETTER", "PAPER_SIZE_IS_LEGAL", "PAPER_SIZE_IS_A5", 
  "PAPER_SIZE_IS_A4", "PAPER_SIZE_IS_LETTER_L", "PAPER_SIZE_IS_LEGAL_L", 
  "PAPER_SIZE_IS_A5_L", "PAPER_SIZE_IS_A4_L", "FORMHANDLER", 
  "END_FORMHANDLER", "BEFORE_EVENT", "BEFORE_OPEN_FORM", "AFTER_EVENT", 
  "BEFORE_CLOSE_FORM", "BEFORE_ANY", "AFTER_ANY", "MENUHANDLER", 
  "END_MENUHANDLER", "BEFORE_SHOW_MENU", "DISABLE_PROGRAM", "DISABLE_ALL", 
  "BUTTONS", "CHECK_MENUITEM", "DISABLE_FORM", "DISABLE_MENUITEMS", 
  "DISABLE", "ENABLE_FORM", "ENABLE_MENUITEMS", "ENABLE", "KWFIELD", 
  "ICON", "MESSAGEBOX", "TO_DEFAULTS", "UNCHECK_MENUITEM", "BEFORE", 
  "INPUT", "END", "INT_TO_ID", "$accept", "pause_screen_on_cmd", 
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
  "bef_c_field_list", "aft_c_field_list", "interval_expr", 
  "extend_parameters", "op_datetime_qual", "defer_cmd", "define_section", 
  "define_multiple", "define_set", "@29", "@30", "def_part", 
  "define_ident", "@31", "def_part2", "@32", "constant_value", 
  "var_def_name", "var_def_list", "op_char", "array_variable", "@33", 
  "@34", "assoc_open_bracket", "assoc_close_bracket", "number_arr_assoc", 
  "number_arr_list", "number_value_arr", "record_variable", "@35", "@36", 
  "@37", "link_to_pk_list", "link_to_pk", "dtype_ident", "op_as_static", 
  "dtype2", "@38", "@39", "dtype", "like_var", "tab_name", "col_name", 
  "datetime_qual", "interval_qual", "dtime_start", "@40", "dtime_val", 
  "dtime_end", "@41", "opt_frac", "opt_unit_size", "dtfrac", "int_start", 
  "@42", "int_start_unit", "int_end", "op_equal", "dim_section", "@43", 
  "dim_dtype", "dim_like_var", "dim_array_variable", "@44", "@45", 
  "dim_record_variable", "@46", "@47", "dim_def_part", "dim_def_part2", 
  "dim_var_def_list", "dim_var_def_name", "opt_at", "display_b_n_cmd", 
  "display_cmd", "display_form_cmd", "display_array_cmd", "@48", "@49", 
  "opt_scroll", "display_attr", "disp_rest", "disp_field_commands", 
  "disp_field_command", "@50", "@51", "@52", "error_cmd", "ext_cmd", 
  "continue_cmd", "exit_prog_cmd", "fgl_expr_c", "fgl_next", 
  "op_fgl_expr_ret_list", "fgl_expr_ret", "fgl_expr_ret_list", 
  "fgl_expr_list", "fgl_expr_concat", "fgl_expr", "int_sign", 
  "boolean_expr", "initial_expr", "literal_expr", "variable_entry_2", 
  "variable_entry", "report_only_expr", "@53", "and_or_expr", 
  "inexpr_list", "in_expr", "null_expr", "string_match_expr", "clip_expr", 
  "using_expr", "math_expr", "comparison_expr", "reset_cnt", 
  "function_call_expr2", "@54", "@55", "@56", "@57", "function_callb", 
  "@58", "@59", "@60", "@61", "@62", "@63", "@64", "@65", "op_extend_d", 
  "op_extend_i", "function_call_expr", "builtin_expr", "builtin_funcs", 
  "pdf_expr", "interval_func_params", "numeric_time_interval", 
  "numeric_time_unit_small", "numeric_time_unit_big", "for_cmd", "@66", 
  "@67", "for_step", "foreach_cmd", "@68", "@69", "@70", 
  "formhandler_def", "@71", "@72", "op_input_section", "op_bef_ev_list", 
  "bef_ev_list", "bef_ev", "@73", "@74", "op_aft_ev_list", "aft_ev_list", 
  "aft_ev", "@75", "@76", "input_section", "input_sub_section", 
  "in_variable_list", "in_id_list", "in_bn_variable_list", "field_ops", 
  "field_op", "@77", "@78", "@79", "@80", "@81", "free_cmd", "line_no", 
  "file_name", "a_number", "coords", "display_coords", "field_name", 
  "cursor_name", "fetch_cursor_name", "win_name", "open_win_name", 
  "form_name", "open_form_name", "opt_help_no", "identifier", 
  "ident_or_var", "ident_p2", "var_or_string", "setident", "unsetident", 
  "field_name2", "cvariable", "real_number", "reserved_word", "goto_cmd", 
  "check_menu_cmd", "menu_item_list", "menu_item", "uncheck_menu_cmd", 
  "disable_cmd", "enable_cmd", "msg_box_cmd", "@82", "op_disable_msg", 
  "gm_disable_msg", "op_returning_msg", "gm_returning_msg", "op_caption", 
  "gm_caption", "op_icon", "gm_icon", "op_buttons", "gm_buttons", 
  "op_def_but", "if_cmd", "@83", "op_else", "@84", "@85", "@86", 
  "import_m", "module_import", "init_cmd", "@87", "init_tab_list", 
  "init_tab", "end_input", "opt_defs", "field_commands", "field_command", 
  "@88", "@89", "@90", "@91", "@92", "@93", "@94", "@95", "@96", 
  "a_ins_or_delete_row", "a_ins_or_delete", "b_ins_or_delete_row", 
  "b_ins_or_delete", "bef_field_list", "aft_field_list", "next_field_cmd", 
  "next_form_cmd", "next_field", "input_cmd", "@97", "inp_rest", "@98", 
  "scroll_cmd", "up_or_down", "op_help", "on_key_command", "@99", 
  "key_val", "@100", "accept_key", "single_key_val", "@101", "key_do", 
  "key_value_list", "key_value", "@102", "key_value_1", "label_cmd", 
  "let_cmd", "@103", "@104", "op_expr_null", "linked_cmd", 
  "linked_del_cmd", "linked_upd_cmd", "locate_cmd", "module", "@105", 
  "op_module_header", "module_header", "module_entry", "func_main_def", 
  "func_or_main2", "at_term_cmd", "func_or_main", "module_code", 
  "op_code", "module_define_section", "ldeffunction", "func_def", "@106", 
  "@107", "@108", "@109", "end_func_command", "main_def", "@110", "@111", 
  "return_cmd", "op_fgl_expr_list", "db_section", 
  "module_globals_section", "actual_globals_section", "xglobals_entry", 
  "globals_entry", "@112", "glob_section", "mem_func_def", "@113", "@114", 
  "@115", "menu_cmd", "@116", "end_menu_command", "menu_block_command", 
  "@117", "@118", "@119", "menu_commands", "opt_key", "menu_opt_name", 
  "menu_optional_desc", "next_option_cmd", "show_option_cmd", 
  "hide_option_cmd", "opt_name", "opt_name_list", "menu_title", 
  "menu_def", "@120", "@121", "menu_handler_elements", 
  "menu_handler_element", "@122", "@123", "message_cmd", "msg_next", 
  "gui_message", "msg_start", "@124", "op_msg_wait", "msg_wait", 
  "variable", "var_int", "varsetidentdot", "var", "assoc_var_read", 
  "assoc_var_write", "assoc_sub", "dot_part_var", "array_r_variable", 
  "arr_subscripts", "num_list", "num_list_element", "let_variable", 
  "let_var", "let_var_dot", "let_array_r_variable", "op_param_var_list", 
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
  "@125", "gui_prompt_cmd", "opt_char", "prompt_key_sec", 
  "prompt_key_clause", "on_key_command_prompt", "@126", "prompt_title", 
  "put_cmd", "@127", "put_from", "put_val_list", "put_val", "start_cmd", 
  "rout", "rep_name", "op_values", "output_cmd", "finish_cmd", 
  "report_section", "format_section", "format_actions", "format_action", 
  "@128", "@129", "@130", "@131", "@132", "@133", "@134", "report_cmd", 
  "need_command", "@135", "op_lines", "skip_command", "@136", 
  "opt_rep_expr_list", "xrep_expr_list", "xxrep_expr_list", 
  "opt_print_at", "print_command", "print_file_command", 
  "print_img_command", "opt_scaling", "img_types", "blob_var", "opt_semi", 
  "rep_expr_list", "rep_expr", "rep_agg", "op_output_section", 
  "output_commands", "output_command", "pdf_output_commands", "nval", 
  "nval_number", "pdf_op_output_section", "pdf_output_command", 
  "op_rep_order_by", "report_def", "@137", "@138", "@139", "@140", "@141", 
  "@142", "rep_where", "pause_command", "pause_msg", "pdf_report_def", 
  "@143", "@144", "@145", "@146", "@147", "@148", "pdf_report_section", 
  "pdf_functions", "@149", "@150", "@151", "op_wordwrap", "run_cmd", 
  "drops_cmd", "drops_c", "create_cmd", "create_c_1", "@152", "@153", 
  "@154", "@155", "op_no_log", "idx_column_list", "idx_column", 
  "table_element_list", "table_element", "upd_stats_cmd", "alter_cmd", 
  "alter_1_c", "alter_clauses", "alter_clause", "alter_add_clause", 
  "add_column_clause", "add_column_clauses", "alter_drop_clause", 
  "drop_column_list", "drop_column", "alter_modify_clause", 
  "modify_column_clauses", "modify_column_clause", "alter_lock_mode", 
  "alter_modify_next", "alter_add_constraint_clause", 
  "alter_drop_contraint_clause", "column_constraints", "constraint_name", 
  "set_cmd", "op_conn_id", "op_fgl_expr", "sleep_cmd", "update_statement", 
  "@156", "@157", "where_upd", "set_clause_list", "upd_columns", 
  "upd_column_name", "col_1", "upd_col_list", "upd_val_list", "upd_val", 
  "rollback_statement", "insert_statement", "@158", "ins_2", "@159", 
  "op_insert_column_list", "insert_column_list", "insert_value_list", 
  "insert_value", "fetch_statement", "@160", "@161", "fetch_part", 
  "opt_into_fetch_part", "@162", "opt_foreach_into_fetch_part", "@163", 
  "fetch_place", "delete_statement_position", "delete_statement_search", 
  "order_by_clause", "sort_specification_list", "sort_specification", 
  "sort_spec", "op_asc_desc", "begin_statement", "commit_statement", 
  "op_exclusive", "set_database_cmd", "sql_cmd", "@164", "sql_commands", 
  "privilege_definition", "op_with_grant_option", "privileges", 
  "action_list", "action", "op_grant_column_list", "grant_column_list", 
  "grantee_list", "grantee", "view_definition", "op_view_column_list", 
  "view_column_list", "op_with_check_option", 
  "check_constraint_definition", "referential_constraint_definition", 
  "references_specification", "references_columns", 
  "referenced_table_and_columns", "references_column_list", 
  "unique_constraint_definition", "unique_column_list", 
  "table_constraint_definition", "default_clause", "ct_column_definiton", 
  "op_default_clause", "op_column_constraint_list", "column_constraint", 
  "schema", "schema_authorization_clause", 
  "schema_authorization_identifier", "schema_element_list", 
  "schema_element", "having_clause", "group_by_clause", 
  "column_specification_list", "where_clause", "from_clause", 
  "table_reference_list", "table_reference", "tname", "tname_list", 
  "table_expression", "op_where_clause", "op_group_by_clause", 
  "op_having_clause", "search_condition", "boolean_term", 
  "boolean_factor", "boolean_primary", "exists_predicate", 
  "quantified_predicate", "quantifier", "all", "some", "op_escape", 
  "pattern", "escape_character", "in_predicate", "in_value_list", 
  "in_value_specification", "op_not", "comparison_predicate", "comp_op", 
  "predicate", "op_all", "data_type", "char_string_type", 
  "exact_numeric_type", "op_scale", "approx_numeric_type", "length", 
  "precision", "scale", "table_name", "authorization_identifier", 
  "col_arr", "column_name", "correlation_name", "literal", 
  "curr_v_clause", "curr_clause", "cur_part", "cur_v_part", "s_curr_v", 
  "e_curr_v", "s_curr", "e_curr", "dbase_name", "flush_cmd", 
  "declare_cmd", "@165", "@166", "@167", "@168", "curs_forupdate", 
  "cur_update_list", "colident", "cursor_specification_all", 
  "cursor_specification_sel", "select_statement_full", "select_statement", 
  "@169", "@170", "in_select_statement", "select_statement2", 
  "select_statement21", "sel_p2", "tmp_tabname", "opt_into_sel", 
  "query_specification", "subquery", "op_ad", "select_list", 
  "value_expression_pls", "column_specification", "value_expression", 
  "value_expression_complex", "value_expr_list", "value_specification", 
  "unload_cmd", "load_cmd", "opt_delim", "char_or_var", "opt_col_list", 
  "col_list", "simple_column_name", "ufile", "opt_use", "conn_id", 
  "misc_sql", "rename_stmt", "rentabname", "rencolname", "unlock_stmt", 
  "lock_stmt", "share_or_exclusive", "units_qual", "extend_qual", 
  "var_ident", "var2", "var3", "aft_dot", "var_ident_ibind", 
  "whenever_cmd", "when_do", "label_goto", "function_name_when", 
  "while_cmd", "@171", "@172", "op_clr_fields", "op_to_defs", "clear_cmd", 
  "fld_list", "current_win_cmd", "window_type", "show_cmd", "op_mnfile", 
  "menu_name", "menu_handler", "hide_cmd", "move_cmd", "NAMED", 
  "commands", "all_commands", "command1", "commands_all", "@173", 
  "commands_all1", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const unsigned short yytoknum[] =
{
       0,   256,  1632,  1633,  1634,  1549,  1589,  1544,  1480,  1359,
    1467,  1463,  1377,  1539,  1276,  1334,  1408,  1575,  1562,  1495,
    1468,  1563,  1341,  1635,  1636,  1637,  1638,  1639,  1640,  1641,
    1642,  1643,  1644,  1000,  1001,  1002,  1003,  1004,  1005,  1006,
    1007,  1008,  1009,  1010,  1011,  1012,  1013,  1014,  1015,  1016,
    1017,  1018,  1019,  1020,  1021,  1022,  1023,  1024,  1025,  1026,
    1027,  1028,  1029,  1030,  1031,  1032,  1033,  1034,  1035,  1036,
    1037,  1038,  1039,  1040,  1041,  1042,  1043,  1044,  1045,  1046,
    1047,  1048,  1049,  1050,  1051,  1052,  1053,  1054,  1055,  1056,
    1057,  1058,  1059,  1060,  1061,  1062,  1063,  1064,  1065,  1066,
    1067,  1068,  1069,  1070,  1071,  1072,  1073,  1074,  1075,  1076,
    1077,  1078,  1079,  1080,  1081,  1082,  1083,  1084,  1085,  1086,
    1087,  1088,  1089,  1090,  1091,  1092,  1093,  1094,  1095,  1096,
    1097,  1098,  1099,  1100,  1101,  1102,  1103,  1104,  1105,  1106,
    1107,  1108,  1109,  1110,  1111,  1112,  1113,  1114,  1115,  1116,
    1117,  1118,  1119,  1120,  1121,  1122,  1123,  1124,  1125,  1126,
    1127,  1128,  1129,  1130,  1131,  1132,  1133,  1134,  1135,  1136,
    1137,  1138,  1139,  1140,  1141,  1142,  1143,  1144,  1145,  1146,
    1147,  1148,  1149,  1150,  1151,  1152,  1153,  1154,  1155,  1156,
    1157,  1158,  1159,  1160,  1161,  1162,  1163,  1164,  1165,  1166,
    1167,  1168,  1169,  1170,  1171,  1172,  1173,  1174,  1175,  1176,
    1177,  1178,  1179,  1180,  1181,  1182,  1183,  1184,  1185,  1186,
    1187,  1188,  1189,  1190,  1191,  1192,  1193,  1194,  1195,  1196,
    1197,  1198,  1199,  1200,  1201,  1202,  1203,  1204,  1205,  1206,
    1207,  1208,  1209,  1210,  1211,  1212,  1213,  1214,  1215,  1216,
    1217,  1218,  1219,  1220,  1221,  1222,  1223,  1224,  1225,  1226,
    1227,  1228,  1229,  1230,  1231,  1232,  1233,  1234,  1235,  1236,
    1237,  1238,  1239,  1240,  1241,  1242,  1243,  1244,  1245,  1246,
    1247,  1248,  1249,  1250,  1251,  1252,  1253,  1254,  1255,  1256,
    1257,  1258,  1259,  1260,  1261,  1262,  1263,  1264,  1265,  1266,
    1267,  1268,  1269,  1270,  1271,  1272,  1273,  1274,  1275,  1277,
    1278,  1279,  1280,  1281,  1282,  1283,  1284,  1285,  1286,  1287,
    1288,  1289,  1290,  1291,  1292,  1293,  1294,  1295,  1296,  1297,
    1298,  1299,  1300,  1301,  1302,  1303,  1304,  1305,  1306,  1307,
    1308,  1309,  1310,  1311,  1312,  1313,  1314,  1315,  1316,  1317,
    1318,  1319,  1320,  1321,  1322,  1323,  1324,  1325,  1326,  1327,
    1328,  1329,  1330,  1331,  1332,  1333,  1335,  1336,  1337,  1338,
    1339,  1340,  1342,  1343,  1344,  1345,  1346,  1347,  1348,  1349,
    1350,  1351,  1352,  1353,  1354,  1355,  1356,  1357,  1358,  1360,
    1361,  1362,  1363,  1364,  1365,  1366,  1367,  1368,  1369,  1370,
    1371,  1372,  1373,  1374,  1375,  1376,  1378,  1379,  1380,  1381,
    1382,  1383,  1384,  1385,  1386,  1387,  1388,  1389,  1390,  1391,
    1392,  1393,  1394,  1395,  1396,  1397,  1398,  1399,  1400,  1401,
    1402,  1403,  1404,  1405,  1406,  1407,  1409,  1410,  1411,  1412,
    1413,  1414,  1415,  1416,  1417,  1418,  1419,  1420,  1421,  1422,
    1423,  1424,  1425,  1426,  1427,  1428,  1429,  1430,  1431,  1432,
    1433,  1434,  1435,  1436,  1437,  1438,  1439,  1440,  1441,  1442,
    1443,  1444,  1445,  1446,  1447,  1448,  1449,  1450,  1451,  1452,
    1453,  1454,  1455,  1456,  1457,  1458,  1459,  1460,  1461,  1462,
    1464,  1465,  1466,  1469,  1470,  1471,  1472,  1473,  1474,  1475,
    1476,  1477,  1478,  1479,  1481,  1482,  1483,  1484,  1485,  1486,
    1487,  1488,  1489,  1490,  1491,  1492,  1493,  1494,  1496,  1497,
    1498,  1499,  1500,  1501,  1502,  1503,  1504,  1505,  1506,  1507,
    1508,  1509,  1510,  1511,  1512,  1513,  1514,  1515,  1516,  1517,
    1518,  1519,  1520,  1521,  1522,  1523,  1524,  1525,  1526,  1527,
    1528,  1529,  1530,  1531,  1532,  1533,  1534,  1535,  1536,  1537,
    1538,  1540,  1541,  1542,  1543,  1545,  1546,  1547,  1548,  1550,
    1551,  1552,  1553,  1554,  1555,  1556,  1557,  1558,  1559,  1560,
    1561,  1564,  1565,  1566,  1567,  1568,  1569,  1570,  1571,  1572,
    1573,  1574,  1576,  1577,  1578,  1579,  1580,  1581,  1582,  1583,
    1584,  1585,  1586,  1587,  1588,  1590,  1591,  1592,  1593,  1594,
    1595,  1596,  1597,  1598,  1599,  1600,  1601,  1602,  1603,  1604,
    1605,  1606,  1607,  1608,  1609,  1610,  1611,  1612,  1613,  1614,
    1615,  1616,  1617,  1618,  1619,  1620,  1621,  1622,  1623,  1624,
    1625,  1626,  1627,  1628,  1629,  1630,  1631
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const unsigned short yyr1[] =
{
       0,   647,   648,   649,   650,   651,   652,   652,   653,   653,
     654,   655,   655,   655,   655,   655,   656,   656,   656,   656,
     656,   657,   657,   658,   658,   660,   659,   659,   661,   661,
     662,   662,   662,   662,   662,   662,   662,   662,   662,   662,
     662,   662,   662,   662,   662,   662,   663,   663,   665,   664,
     666,   666,   667,   667,   667,   667,   667,   667,   667,   667,
     667,   668,   669,   670,   669,   669,   669,   669,   669,   671,
     672,   669,   673,   674,   675,   669,   676,   677,   669,   678,
     679,   669,   680,   681,   682,   669,   683,   683,   684,   684,
     684,   685,   685,   686,   686,   687,   688,   688,   689,   689,
     691,   690,   692,   690,   693,   693,   694,   694,   695,   696,
     697,   696,   698,   699,   698,   701,   700,   703,   702,   704,
     704,   704,   704,   704,   704,   705,   706,   706,   707,   707,
     708,   709,   709,   710,   711,   713,   714,   712,   715,   715,
     716,   716,   717,   717,   718,   718,   718,   719,   719,   721,
     720,   722,   720,   723,   720,   724,   720,   725,   720,   726,
     726,   727,   727,   728,   728,   728,   728,   728,   728,   729,
     730,   730,   731,   731,   732,   732,   733,   733,   735,   736,
     734,   734,   734,   737,   737,   739,   738,   740,   740,   740,
     740,   740,   741,   740,   742,   742,   742,   742,   743,   744,
     744,   745,   745,   747,   746,   748,   746,   749,   749,   750,
     750,   751,   752,   752,   752,   753,   755,   754,   756,   754,
     757,   754,   758,   758,   759,   760,   761,   761,   763,   764,
     762,   765,   765,   765,   765,   765,   765,   765,   765,   765,
     765,   765,   765,   765,   765,   765,   765,   765,   765,   765,
     765,   765,   765,   765,   765,   765,   765,   765,   765,   766,
     767,   768,   769,   769,   770,   772,   771,   773,   773,   773,
     773,   773,   773,   773,   775,   774,   776,   776,   777,   777,
     778,   780,   779,   781,   781,   781,   781,   781,   781,   781,
     782,   783,   783,   785,   784,   786,   786,   786,   786,   786,
     786,   786,   786,   786,   786,   786,   786,   786,   786,   786,
     786,   786,   786,   786,   786,   786,   786,   786,   787,   789,
     788,   790,   788,   792,   791,   793,   791,   794,   794,   795,
     796,   796,   797,   798,   798,   798,   798,   798,   798,   798,
     798,   799,   800,   801,   803,   804,   802,   805,   805,   806,
     807,   807,   808,   808,   810,   809,   811,   809,   812,   809,
     813,   813,   814,   814,   814,   814,   814,   814,   814,   814,
     814,   815,   815,   815,   815,   815,   815,   815,   815,   816,
     816,   817,   817,   817,   817,   817,   817,   817,   817,   817,
     817,   818,   818,   818,   818,   818,   818,   818,   818,   818,
     818,   819,   819,   820,   820,   821,   821,   822,   822,   823,
     823,   824,   825,   825,   826,   826,   826,   826,   826,   826,
     827,   827,   828,   828,   828,   828,   829,   829,   830,   831,
     831,   831,   832,   831,   833,   833,   834,   834,   835,   835,
     835,   835,   836,   836,   837,   837,   837,   837,   838,   839,
     840,   840,   840,   840,   840,   840,   841,   841,   841,   841,
     841,   841,   841,   842,   844,   845,   843,   846,   847,   843,
     849,   850,   848,   851,   852,   848,   853,   854,   848,   855,
     856,   848,   848,   848,   848,   848,   857,   857,   858,   859,
     859,   859,   859,   859,   859,   859,   859,   859,   860,   860,
     861,   861,   861,   861,   862,   862,   862,   863,   863,   864,
     864,   864,   865,   865,   865,   865,   865,   865,   865,   865,
     865,   865,   866,   866,   868,   869,   867,   870,   870,   872,
     873,   874,   871,   876,   877,   875,   878,   878,   879,   879,
     880,   880,   882,   881,   883,   881,   884,   884,   885,   885,
     887,   886,   888,   886,   889,   890,   890,   890,   891,   891,
     892,   892,   893,   893,   894,   894,   896,   895,   897,   895,
     898,   895,   899,   895,   900,   895,   901,   902,   902,   902,
     902,   902,   902,   903,   903,   904,   905,   906,   907,   907,
     907,   907,   907,   907,   907,   907,   908,   909,   910,   911,
     912,   913,   914,   914,   915,   916,   917,   917,   918,   918,
     919,   920,   921,   921,   921,   921,   921,   921,   922,   923,
     923,   924,   924,   924,   924,   924,   924,   924,   924,   924,
     924,   924,   924,   924,   924,   924,   924,   924,   924,   924,
     924,   924,   924,   924,   924,   924,   924,   924,   924,   924,
     924,   924,   924,   924,   924,   924,   924,   924,   924,   924,
     924,   924,   924,   924,   925,   926,   927,   927,   928,   929,
     930,   930,   930,   931,   931,   931,   933,   932,   934,   934,
     935,   935,   936,   936,   937,   938,   938,   939,   940,   940,
     941,   942,   942,   943,   944,   944,   946,   945,   947,   948,
     947,   949,   950,   947,   951,   952,   954,   953,   953,   955,
     955,   956,   956,   957,   957,   958,   958,   959,   959,   961,
     960,   962,   960,   963,   960,   964,   960,   965,   960,   966,
     960,   967,   960,   968,   960,   969,   960,   970,   970,   971,
     971,   972,   972,   973,   973,   974,   974,   975,   975,   976,
     977,   978,   978,   978,   980,   979,   981,   981,   982,   981,
     983,   984,   984,   984,   984,   985,   985,   987,   986,   986,
     989,   988,   990,   992,   991,   993,   993,   994,   994,   996,
     995,   997,   997,   997,   997,   997,   997,   997,   997,   997,
     997,   997,   997,   997,   997,   997,   997,   998,  1000,  1001,
     999,  1002,  1002,  1003,  1004,  1005,  1006,  1006,  1008,  1007,
    1009,  1009,  1010,  1010,  1011,  1011,  1011,  1011,  1012,  1012,
    1013,  1013,  1014,  1015,  1015,  1015,  1015,  1015,  1015,  1015,
    1015,  1015,  1015,  1015,  1016,  1016,  1017,  1017,  1017,  1018,
    1019,  1019,  1021,  1022,  1023,  1024,  1020,  1025,  1027,  1028,
    1026,  1029,  1030,  1030,  1031,  1032,  1033,  1033,  1034,  1034,
    1034,  1036,  1035,  1037,  1037,  1039,  1040,  1041,  1038,  1043,
    1042,  1044,  1046,  1045,  1047,  1045,  1048,  1045,  1049,  1049,
    1050,  1050,  1051,  1051,  1052,  1052,  1052,  1053,  1054,  1055,
    1056,  1056,  1056,  1057,  1057,  1058,  1058,  1060,  1061,  1059,
    1062,  1062,  1064,  1063,  1065,  1063,  1066,  1067,  1067,  1067,
    1067,  1068,  1068,  1068,  1068,  1068,  1070,  1069,  1071,  1071,
    1072,  1073,  1074,  1074,  1075,  1076,  1076,  1076,  1076,  1076,
    1077,  1078,  1079,  1079,  1080,  1080,  1081,  1082,  1082,  1083,
    1083,  1084,  1085,  1086,  1086,  1086,  1086,  1086,  1087,  1087,
    1088,  1089,  1089,  1090,  1090,  1091,  1091,  1092,  1092,  1093,
    1093,  1093,  1093,  1093,  1094,  1094,  1095,  1095,  1096,  1096,
    1097,  1098,  1099,  1099,  1100,  1101,  1101,  1101,  1102,  1103,
    1103,  1104,  1104,  1105,  1106,  1106,  1107,  1107,  1108,  1109,
    1110,  1111,  1111,  1112,  1113,  1113,  1114,  1114,  1115,  1115,
    1116,  1117,  1117,  1118,  1118,  1118,  1118,  1119,  1119,  1119,
    1120,  1121,  1121,  1122,  1122,  1122,  1123,  1124,  1124,  1125,
    1125,  1125,  1125,  1125,  1125,  1125,  1125,  1125,  1125,  1125,
    1125,  1125,  1125,  1125,  1125,  1125,  1125,  1125,  1125,  1125,
    1125,  1126,  1127,  1127,  1128,  1128,  1129,  1131,  1130,  1132,
    1133,  1133,  1134,  1134,  1135,  1135,  1137,  1136,  1138,  1140,
    1139,  1141,  1141,  1142,  1142,  1143,  1143,  1144,  1144,  1144,
    1144,  1145,  1145,  1146,  1147,  1147,  1148,  1149,  1150,  1151,
    1151,  1152,  1152,  1154,  1153,  1155,  1153,  1156,  1153,  1157,
    1153,  1158,  1153,  1159,  1153,  1160,  1153,  1161,  1161,  1161,
    1161,  1161,  1161,  1163,  1162,  1164,  1164,  1166,  1165,  1165,
    1165,  1165,  1165,  1167,  1167,  1168,  1168,  1169,  1170,  1170,
    1171,  1172,  1173,  1174,  1174,  1174,  1175,  1175,  1175,  1175,
    1176,  1177,  1177,  1178,  1178,  1179,  1180,  1180,  1180,  1180,
    1180,  1180,  1180,  1180,  1181,  1181,  1182,  1182,  1183,  1183,
    1183,  1183,  1183,  1183,  1183,  1183,  1183,  1183,  1184,  1184,
    1185,  1185,  1185,  1185,  1186,  1186,  1187,  1187,  1188,  1188,
    1188,  1188,  1188,  1188,  1188,  1188,  1188,  1188,  1188,  1188,
    1188,  1188,  1188,  1188,  1188,  1188,  1188,  1188,  1188,  1188,
    1188,  1188,  1189,  1189,  1189,  1191,  1192,  1193,  1194,  1195,
    1196,  1190,  1197,  1197,  1198,  1199,  1199,  1201,  1202,  1203,
    1204,  1205,  1206,  1200,  1207,  1209,  1210,  1211,  1208,  1212,
    1212,  1212,  1212,  1213,  1213,  1213,  1213,  1213,  1214,  1215,
    1215,  1215,  1216,  1217,  1218,  1219,  1217,  1220,  1221,  1217,
    1217,  1222,  1222,  1223,  1223,  1224,  1224,  1224,  1225,  1225,
    1226,  1226,  1227,  1227,  1228,  1229,  1230,  1230,  1231,  1231,
    1231,  1231,  1231,  1231,  1231,  1232,  1232,  1233,  1233,  1234,
    1234,  1235,  1235,  1236,  1236,  1237,  1238,  1238,  1239,  1239,
    1240,  1241,  1241,  1242,  1243,  1243,  1244,  1244,  1245,  1245,
    1246,  1247,  1247,  1247,  1247,  1247,  1247,  1247,  1247,  1247,
    1247,  1247,  1248,  1248,  1249,  1249,  1250,  1252,  1253,  1251,
    1254,  1254,  1254,  1255,  1255,  1255,  1255,  1256,  1256,  1257,
    1258,  1259,  1259,  1260,  1260,  1261,  1261,  1261,  1262,  1264,
    1263,  1266,  1265,  1265,  1267,  1267,  1268,  1268,  1269,  1269,
    1270,  1270,  1272,  1273,  1271,  1274,  1274,  1275,  1276,  1275,
    1277,  1278,  1277,  1279,  1279,  1279,  1279,  1279,  1279,  1279,
    1279,  1280,  1281,  1282,  1283,  1283,  1284,  1285,  1285,  1286,
    1286,  1286,  1287,  1288,  1289,  1289,  1290,  1292,  1291,  1293,
    1293,  1293,  1293,  1293,  1293,  1293,  1293,  1293,  1293,  1293,
    1293,  1294,  1295,  1295,  1296,  1296,  1297,  1297,  1298,  1298,
    1298,  1298,  1299,  1299,  1300,  1300,  1301,  1301,  1302,  1302,
    1303,  1304,  1304,  1305,  1305,  1306,  1306,  1307,  1308,  1309,
    1310,  1311,  1311,  1312,  1312,  1313,  1313,  1314,  1314,  1315,
    1315,  1315,  1316,  1316,  1317,  1318,  1318,  1319,  1319,  1320,
    1320,  1320,  1320,  1321,  1322,  1323,  1324,  1324,  1325,  1325,
    1326,  1327,  1328,  1328,  1329,  1330,  1331,  1331,  1332,  1332,
    1332,  1333,  1333,  1334,  1334,  1335,  1336,  1336,  1337,  1337,
    1338,  1338,  1339,  1339,  1340,  1340,  1341,  1341,  1342,  1342,
    1343,  1343,  1344,  1344,  1345,  1345,  1345,  1346,  1347,  1347,
    1348,  1349,  1350,  1351,  1351,  1351,  1351,  1352,  1352,  1353,
    1353,  1354,  1354,  1355,  1355,  1355,  1355,  1355,  1355,  1356,
    1356,  1356,  1356,  1356,  1356,  1356,  1356,  1356,  1356,  1357,
    1357,  1357,  1357,  1358,  1358,  1358,  1358,  1359,  1359,  1359,
    1360,  1360,  1361,  1361,  1361,  1361,  1361,  1361,  1361,  1361,
    1361,  1361,  1361,  1361,  1361,  1361,  1361,  1361,  1361,  1362,
    1362,  1363,  1363,  1363,  1363,  1363,  1364,  1365,  1366,  1367,
    1367,  1367,  1367,  1368,  1369,  1369,  1369,  1370,  1370,  1370,
    1371,  1372,  1372,  1372,  1372,  1372,  1372,  1372,  1372,  1372,
    1373,  1374,  1375,  1375,  1376,  1376,  1377,  1377,  1377,  1377,
    1377,  1377,  1377,  1377,  1378,  1378,  1378,  1378,  1378,  1378,
    1378,  1378,  1379,  1379,  1379,  1379,  1379,  1379,  1379,  1380,
    1380,  1380,  1380,  1380,  1380,  1380,  1381,  1381,  1382,  1384,
    1383,  1385,  1383,  1386,  1383,  1387,  1383,  1388,  1388,  1388,
    1389,  1389,  1390,  1390,  1390,  1391,  1391,  1392,  1392,  1393,
    1395,  1396,  1394,  1397,  1398,  1398,  1399,  1400,  1400,  1400,
    1400,  1400,  1401,  1402,  1402,  1403,  1404,  1405,  1405,  1405,
    1405,  1406,  1406,  1407,  1407,  1407,  1408,  1409,  1409,  1410,
    1410,  1410,  1410,  1410,  1410,  1410,  1410,  1410,  1410,  1410,
    1410,  1410,  1410,  1410,  1410,  1410,  1410,  1410,  1410,  1411,
    1411,  1412,  1412,  1413,  1414,  1415,  1415,  1416,  1416,  1417,
    1417,  1418,  1418,  1419,  1420,  1420,  1421,  1421,  1422,  1423,
    1423,  1423,  1424,  1424,  1425,  1426,  1427,  1428,  1429,  1429,
    1430,  1430,  1430,  1430,  1430,  1430,  1431,  1431,  1431,  1432,
    1433,  1433,  1434,  1434,  1434,  1434,  1435,  1435,  1435,  1436,
    1436,  1437,  1437,  1437,  1437,  1437,  1437,  1437,  1437,  1437,
    1438,  1438,  1438,  1438,  1438,  1439,  1439,  1440,  1442,  1443,
    1441,  1444,  1444,  1445,  1445,  1446,  1446,  1446,  1446,  1446,
    1446,  1446,  1447,  1447,  1448,  1448,  1449,  1449,  1450,  1450,
    1451,  1451,  1452,  1453,  1454,  1455,  1455,  1456,  1457,  1457,
    1458,  1459,  1459,  1461,  1460,  1462,  1462,  1462,  1462,  1462,
    1462,  1462,  1462,  1462,  1462,  1462,  1462,  1462,  1462,  1462,
    1462,  1462,  1462,  1462,  1462,  1462,  1462,  1462,  1462,  1462,
    1462,  1462,  1462,  1462,  1462,  1462,  1462,  1462,  1462,  1462,
    1462,  1462,  1462,  1462,  1462,  1462,  1462,  1462,  1462,  1462,
    1462,  1462,  1462,  1462,  1462,  1462,  1462,  1462,  1462,  1462,
    1462,  1462,  1462,  1462,  1462,  1462,  1462,  1462,  1462,  1462,
    1462,  1462,  1462,  1462,  1462,  1462,  1462,  1462,  1462,  1462,
    1462,  1462,  1462,  1462,  1462,  1462,  1462,  1462
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const unsigned char yyr2[] =
{
       0,     2,     1,     1,     5,     1,     1,     1,     1,     3,
       1,     3,     3,     1,     2,     1,     1,     1,     1,     1,
       1,     1,     1,     0,     1,     0,     5,     6,     1,     3,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     0,     1,     0,     5,
       1,     3,     1,     1,     2,     2,     2,     2,     2,     2,
       2,     2,     3,     0,     7,     4,     6,     1,     6,     0,
       0,     9,     0,     0,     0,     8,     0,     0,    10,     0,
       0,     7,     0,     0,     0,    14,     0,     2,     0,     2,
       1,     0,     1,     1,     3,     1,     1,     1,     1,     3,
       0,     6,     0,     5,     1,     2,     1,     2,     1,     0,
       0,     3,     0,     0,     3,     0,     4,     0,     4,     2,
       2,     2,     1,     2,     2,     3,     1,     1,     1,     2,
       1,     1,     2,     1,     1,     0,     0,     5,     7,     8,
       0,     2,     1,     3,     1,     3,     3,     1,     2,     0,
       4,     0,     4,     0,     3,     0,     3,     0,     3,     1,
       3,     1,     3,     1,     1,     1,     1,     1,     1,     4,
       0,     4,     1,     1,     0,     1,     1,     2,     0,     0,
       5,     1,     1,     1,     3,     0,     2,     4,     4,     4,
       4,     2,     0,     4,     1,     1,     1,     2,     1,     1,
       3,     0,     1,     0,     7,     0,    12,     1,     1,     1,
       1,     1,     5,     3,     1,     1,     0,     4,     0,     5,
       0,     7,     1,     3,     1,     1,     0,     1,     0,     0,
       4,     1,     1,     1,     4,     4,     6,     1,     2,     1,
       1,     1,     1,     4,     6,     1,     4,     6,     1,     1,
       1,     1,     1,     1,     1,     2,     2,     1,     1,     4,
       1,     1,     0,     3,     3,     0,     2,     1,     1,     1,
       1,     1,     1,     2,     0,     2,     0,     3,     0,     3,
       1,     0,     3,     1,     1,     1,     1,     1,     1,     2,
       1,     0,     1,     0,     5,     1,     1,     1,     4,     4,
       6,     1,     1,     1,     1,     4,     6,     1,     4,     6,
       1,     1,     1,     1,     1,     2,     2,     1,     4,     0,
       7,     0,    12,     0,     4,     0,     5,     1,     3,     2,
       1,     3,     1,     0,     2,     2,     1,     2,     5,     4,
       2,     4,     5,     3,     0,     0,    11,     0,     2,     1,
       0,     2,     1,     2,     0,     3,     0,     3,     0,     3,
       4,     5,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       2,     1,     1,     1,     1,     2,     1,     1,     1,     2,
       2,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     2,     1,     1,     1,     3,     1,     3,     1,
       3,     1,     1,     1,     2,     1,     1,     3,     4,     4,
       2,     2,     1,     1,     1,     1,     1,     3,     1,     2,
       2,     1,     0,     3,     2,     2,     1,     3,     4,     4,
       5,     5,     1,     1,     2,     2,     2,     2,     1,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     0,     0,     0,     6,     0,     0,     6,
       0,     0,     6,     0,     0,     6,     0,     0,     6,     0,
       0,     6,     5,     5,     5,     7,     0,     3,     1,     1,
       4,     4,     4,     4,     4,     4,     1,     1,     1,     1,
       4,     4,     2,     2,     2,     2,     2,     1,     1,     2,
       1,     1,     1,     2,     4,     6,     6,     3,     5,     5,
       3,     1,     1,     3,     0,     0,    11,     0,     2,     0,
       0,     0,     8,     0,     0,    10,     0,     1,     0,     1,
       1,     2,     0,     3,     0,     3,     0,     1,     1,     2,
       0,     3,     0,     3,     3,     1,     4,     3,     1,     3,
       1,     3,     1,     3,     1,     2,     0,     3,     0,     3,
       0,     4,     0,     4,     0,     4,     2,     3,     1,     3,
       1,     1,     1,     1,     1,     1,     3,     1,     1,     4,
       6,     4,     3,     6,     3,     6,     1,     1,     1,     1,
       1,     1,     0,     2,     3,     3,     1,     4,     1,     1,
       0,     0,     1,     4,     3,     6,     3,     6,     1,     1,
       2,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     2,     2,     1,     3,     1,     2,
       2,     2,     4,     2,     2,     4,     0,     8,     0,     1,
       1,     1,     0,     1,     2,     0,     1,     2,     0,     1,
       2,     0,     1,     3,     0,     2,     0,     7,     0,     0,
       3,     0,     0,     7,     5,     2,     0,     5,     4,     1,
       3,     3,     3,     0,     2,     0,     1,     1,     2,     0,
       4,     0,     4,     0,     3,     0,     3,     0,     3,     0,
       3,     0,     3,     0,     4,     0,     4,     1,     3,     1,
       1,     1,     3,     1,     1,     1,     3,     1,     3,     2,
       4,     1,     1,     1,     0,     4,     5,     6,     0,    10,
       3,     1,     1,     2,     2,     0,     2,     0,     3,     1,
       0,     3,     2,     0,     3,     1,     3,     1,     3,     0,
       2,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     0,     0,
       7,     1,     1,     2,     2,     2,     3,     4,     0,     3,
       0,     1,     1,     2,     1,     1,     1,     1,     0,     1,
       1,     2,     2,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     0,     1,     1,     1,
       1,     1,     0,     0,     0,     0,    13,     1,     0,     0,
       6,     2,     1,     2,     2,     1,     1,     2,     1,     1,
       1,     0,     3,     2,     1,     0,     0,     0,    14,     0,
       5,     1,     0,     3,     0,     7,     0,     5,     1,     2,
       0,     1,     1,     1,     0,     1,     1,     2,     2,     2,
       1,     1,     1,     1,     3,     1,     1,     0,     0,     7,
       1,     2,     0,     3,     0,     4,     2,     0,     2,     1,
       1,     1,     1,     1,     1,     1,     0,     3,     0,     1,
       1,     1,     1,     2,     3,     2,     5,     1,     1,     1,
       4,     4,     1,     1,     1,     1,     2,     3,     6,     1,
       3,     1,     1,     1,     4,     7,     1,     1,     1,     1,
       2,     0,     1,     1,     3,     1,     3,     1,     3,     1,
       3,     1,     1,     1,     1,     3,     1,     3,     1,     3,
       1,     1,     1,     3,     2,     0,     1,     1,     4,     1,
       3,     1,     3,     7,     0,     7,     0,     6,     3,     1,
       3,     1,     2,     5,     0,     7,     0,     2,     0,     1,
       5,     2,     5,     0,     5,     6,     4,     0,     1,     1,
       4,     0,     2,     0,     5,     4,     2,     1,     3,     2,
       2,     2,     2,     2,     2,     1,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     1,     1,     1,     1,     1,
       1,     5,     1,     1,     2,     4,     1,     0,    10,     5,
       0,     1,     0,     2,     1,     2,     0,     3,     1,     0,
       4,     0,     2,     1,     3,     1,     1,     3,     4,     4,
       2,     1,     1,     1,     0,     1,     7,     2,     2,     2,
       2,     1,     2,     0,     3,     0,     3,     0,     3,     0,
       3,     0,     3,     0,     4,     0,     4,     1,     1,     1,
       1,     1,     1,     0,     4,     0,     1,     0,     4,     1,
       2,     2,     2,     0,     1,     1,     2,     2,     0,     2,
       3,     3,     5,     0,     2,     4,     1,     1,     1,     1,
       1,     0,     1,     1,     3,     2,     5,     2,     5,     5,
       5,     5,     5,     5,     0,     2,     1,     2,     2,     2,
       2,     2,     2,     1,     2,     2,     2,     2,     1,     2,
       2,     2,     2,     1,     1,     1,     0,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     1,     1,     1,
       1,     1,     1,     1,     2,     2,     2,     2,     2,     1,
       1,     1,     0,     3,     2,     0,     0,     0,     0,     0,
       0,    15,     0,     2,     2,     0,     1,     0,     0,     0,
       0,     0,     0,    15,     2,     0,     0,     0,    10,     0,
       1,     3,     3,     2,     4,     3,     3,     3,     1,     1,
       1,     1,     1,     3,     0,     0,     7,     0,     0,     8,
       2,     0,     1,     1,     3,     2,     2,     1,     1,     3,
       1,     1,     2,     1,     1,     3,     1,     3,     1,     1,
       1,     1,     1,     1,     1,     2,     4,     1,     3,     1,
       3,     2,     4,     1,     3,     1,     2,     4,     1,     3,
       1,     1,     1,     2,     2,     4,     2,     4,     1,     3,
       1,     1,     1,     2,     1,     1,     1,     1,     1,     2,
       6,     6,     0,     1,     0,     1,     2,     0,     0,     7,
       0,     2,     2,     7,     1,     5,     3,     1,     3,     1,
       3,     1,     3,     1,     3,     1,     1,     1,     1,     0,
       5,     0,     5,     1,     0,     3,     1,     3,     1,     3,
       1,     1,     0,     0,     5,     2,     1,     0,     0,     3,
       0,     0,     3,     1,     1,     1,     1,     1,     1,     2,
       2,     4,     3,     3,     1,     3,     2,     1,     1,     0,
       1,     1,     1,     1,     0,     1,     3,     0,     3,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     7,     0,     1,     1,     1,     1,     3,     1,     1,
       1,     2,     0,     3,     1,     3,     1,     3,     1,     1,
       6,     0,     3,     1,     3,     0,     1,     4,     5,     2,
       1,     1,     4,     1,     3,     4,     4,     1,     3,     1,
       1,     1,     2,     1,     4,     0,     1,     0,     2,     1,
       1,     1,     4,     3,     1,     1,     1,     2,     1,     1,
       2,     2,     1,     3,     2,     2,     1,     3,     1,     2,
       4,     1,     2,     1,     3,     4,     0,     1,     0,     1,
       0,     1,     1,     3,     1,     3,     1,     2,     1,     3,
       2,     2,     4,     3,     0,     1,     1,     1,     1,     1,
       2,     1,     1,     5,     3,     5,     3,     1,     3,     1,
       1,     0,     1,     3,     3,     3,     3,     6,     5,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     0,     1,     1,     1,     1,     1,     1,
       1,     4,     5,     1,     5,     5,     1,     1,     1,     4,
       1,     4,     1,     7,     1,     1,     1,     4,     6,     0,
       2,     4,     1,     1,     1,     1,     1,     1,     1,     3,
       1,     1,     3,     1,     0,     3,     5,     2,     5,     4,
       1,     1,     1,     1,     1,     2,     2,     2,     2,     1,
       2,     2,     0,     3,     0,     3,     1,     1,     1,     1,
       1,     1,     1,     4,     1,     1,     1,     1,     1,     1,
       1,     4,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     3,     0,
       8,     0,     9,     0,     7,     0,     9,     0,     1,     2,
       1,     3,     1,     3,     5,     1,     1,     1,     1,     2,
       0,     0,     8,     5,     1,     1,     7,     0,     3,     1,
       3,     4,     1,     0,     2,     5,     7,     0,     1,     1,
       1,     1,     3,     1,     2,     2,     1,     1,     1,     3,
       2,     3,     3,     3,     1,     1,     1,     1,     1,     1,
       5,     5,     5,     5,     5,     4,     6,     3,     4,     1,
       3,     0,     1,     5,     7,     0,     2,     1,     1,     0,
       3,     1,     3,     1,     1,     1,     0,     3,     1,     1,
       1,     1,     4,     6,     1,     1,     2,     3,     1,     1,
       1,     1,     1,     1,     1,     1,     5,     5,     4,     1,
       2,     1,     1,     1,     3,     5,     1,     1,     1,     1,
       3,     2,     2,     2,     1,     2,     2,     2,     2,     2,
       1,     3,     2,     1,     2,     1,     2,     1,     0,     0,
       6,     0,     2,     0,     1,     1,     2,     2,     1,     1,
       4,     3,     1,     3,     1,     2,     5,     2,     2,     5,
       0,     2,     1,     1,     2,     6,     6,     1,     0,     1,
       2,     1,     2,     0,     2,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const unsigned short yydefact[] =
{
     810,     0,   610,     0,     0,     0,     0,     0,     0,     0,
    1744,     0,   610,   610,   861,   178,   834,   839,   176,   181,
     814,     0,   808,   811,   812,   815,   817,   860,   816,   855,
     856,   858,   182,   133,   130,     0,   126,   128,   127,   131,
     705,     0,  1750,   610,   610,  1753,     0,  1749,  1746,  1743,
    1741,  1742,  1748,  1747,  1745,   293,  1617,  1616,   854,   174,
     185,   177,   182,     1,   818,   813,   859,   857,   835,   125,
     129,   132,  1787,   611,  1757,  1754,   610,  1755,  1752,   610,
       0,   583,   610,     0,   175,   864,   928,   584,   862,   618,
     921,   610,   922,   929,   927,   185,   179,   198,   610,   183,
     199,   228,   841,  1207,   610,   610,   840,   134,  1195,   848,
     610,   610,   831,   833,   830,   832,   809,   819,   820,   842,
     823,   824,   825,   828,   826,   827,   829,   604,  1756,  1751,
       0,   923,   863,   610,   610,   936,   934,   935,   925,     0,
     291,   185,  1131,   192,   186,   185,   191,   225,     0,   610,
       0,     0,   610,   174,   533,   897,   821,   610,   325,   311,
     201,   262,   281,   302,   304,   301,     0,   323,     0,   310,
     303,   307,   313,   297,   312,   185,   314,   294,   317,   295,
     296,   933,   932,     0,    21,    22,    13,   610,   941,     0,
      15,     0,   939,   610,   924,   292,   610,   184,  1132,   180,
       0,   198,   200,   258,   252,   253,   241,   218,   249,   201,
     220,   262,   281,   239,   242,   237,     0,   216,     0,   248,
     240,   245,   251,   233,   250,   185,   254,   185,   231,   232,
     229,   257,     0,     0,   610,     0,   849,   174,   174,     0,
     610,   202,     0,   315,     0,     0,   316,     0,     0,     0,
       0,   610,     0,     0,     0,   260,     0,   930,     0,    16,
      17,    19,    18,    20,   610,    14,   610,   937,     0,   619,
     187,   190,     0,   188,   189,     0,   195,   194,   193,   196,
     185,     0,   185,   255,   256,     0,     0,   185,     0,     0,
       0,     0,   238,   226,  1208,     0,     0,  1196,  1793,   534,
     898,   843,     0,   207,   208,     0,   274,   276,   271,   272,
     268,   270,   267,   269,   266,     0,   276,   287,   288,   284,
     286,   283,   285,   278,     0,     0,     0,   327,     0,   330,
     332,   215,     0,   214,     0,     0,   185,    11,    12,   940,
     610,   926,   620,   197,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   185,   227,   230,   610,   704,   865,   610,
       0,  1791,  1793,  1131,  1706,   836,     0,   610,     0,     0,
     263,     0,     0,   273,   290,   264,   289,     0,   282,     0,
     305,     0,   299,   610,   324,   610,   329,   319,     0,     0,
     308,   298,   261,   318,     0,     0,     0,     0,     0,   243,
       0,   235,   217,   203,     0,   246,   234,   259,   957,     0,
     952,   953,   610,     0,   850,  1792,  1790,   610,   610,   610,
     610,   610,   610,   610,  1774,   610,  1297,  1296,   610,  1298,
     610,   375,  1295,  1237,   610,     5,  1294,   376,   373,   610,
     378,   172,   463,  1109,     0,     0,  1304,   122,   372,   371,
    1229,   366,   610,  1253,  1765,   610,   377,   344,   610,     3,
       2,   610,   374,  1234,   610,   610,   367,   364,   379,   610,
     610,   610,   610,   610,  1292,   370,   610,   610,   610,   610,
     610,   610,   610,   610,  1291,   610,   610,   610,   173,  1231,
     363,   362,   610,   610,  1769,  1768,   610,   610,   610,   135,
    1230,   369,   368,   610,   610,   365,   916,   463,   610,   529,
       0,   610,   610,   463,   610,   610,   610,   463,   797,  1205,
     610,   610,  1113,   610,  1758,   610,   102,   610,   610,   869,
     610,   610,   610,   610,   798,   610,   610,   610,     0,   610,
     610,   610,   610,   610,   610,   610,   676,   610,   610,  1795,
    1796,  1797,  1798,  1799,  1800,  1801,  1802,  1803,  1804,  1805,
    1806,  1807,  1808,  1809,  1810,  1811,  1812,  1813,  1814,  1815,
    1816,  1817,  1818,  1819,  1820,  1821,  1822,  1823,  1824,  1825,
    1826,  1827,  1828,  1829,  1830,  1831,  1832,  1833,  1834,  1835,
    1836,  1837,  1838,  1839,  1840,  1841,   907,  1842,  1843,  1844,
    1845,  1846,  1847,  1848,  1849,  1850,  1851,  1852,  1853,  1854,
    1855,  1856,  1857,  1100,  1102,  1097,  1099,  1098,  1101,  1858,
    1859,  1228,  1860,  1232,  1861,  1862,  1254,  1863,  1864,  1865,
    1866,  1867,  1868,  1869,  1870,  1377,  1871,  1872,  1873,  1874,
    1875,  1876,  1877,  1794,   837,   538,   838,   610,   902,     0,
     900,     0,   326,   209,   210,     0,   275,   280,     0,     0,
       0,     0,   328,   331,     0,   213,     0,   938,   219,     0,
     185,     0,     0,     0,     0,   610,  1209,   610,     0,  1197,
       0,  1240,     0,   822,  1767,   598,   121,     0,   610,  1733,
    1732,  1011,  1729,  1731,  1782,     0,  1247,     0,  1243,  1252,
       7,     0,     6,   610,  1775,  1073,  1074,   610,  1165,  1164,
    1112,  1163,  1111,   610,   610,   422,   424,     0,  1202,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   610,
    1584,     0,     0,     0,   416,   610,   610,     0,     0,   415,
     610,     0,   432,     0,   499,     0,     0,     0,     0,     0,
     610,     0,   411,  1305,     0,   382,   381,   388,   428,   425,
     383,   497,   489,   384,   386,   496,   387,   928,   423,   426,
     431,  1293,   498,  1708,  1299,   123,   610,  1077,   120,   610,
     804,    23,   600,   380,     0,   803,  1070,   805,     0,  1303,
     891,   890,   893,   889,   892,  1784,     0,   887,     0,   599,
     984,   888,  1778,     0,  1766,   119,   981,   706,   979,     0,
     596,  1761,   752,   751,     0,   753,   588,   749,     0,   610,
     994,   601,  1374,   610,   610,  1046,  1044,   610,  1038,  1040,
    1039,  1037,  1036,   610,   610,   610,  1035,   610,   779,   610,
     610,     0,     0,     0,     0,   610,   610,     0,     0,     0,
    1025,  1016,  1017,     0,  1058,   409,    23,   851,   401,  1772,
       0,  1763,   124,   597,   610,  1043,  1042,  1206,  1204,  1130,
       0,  1697,  1698,  1131,  1219,  1131,  1114,  1115,  1118,  1133,
    1306,   610,     0,     0,     0,     0,     0,   610,     0,   610,
       0,    61,     0,   928,     0,    67,     0,   100,   576,   664,
     610,  1103,  1001,  1107,     0,   610,  1059,  1223,     0,  1110,
     668,   665,   666,     0,   670,   671,     0,   673,   674,   610,
     669,   961,   963,   610,   610,   962,   754,   959,   715,   955,
     920,     0,   610,   610,     0,   680,   681,     0,     0,   918,
     914,   915,   911,   912,   913,   906,   910,   909,   610,   610,
     610,   610,   610,     0,   542,   544,   536,   539,   540,   904,
    1793,   899,   901,   844,     0,   277,   279,   306,   300,     0,
       0,   309,     0,   224,     0,   222,   244,   236,   228,   247,
     958,   174,   954,   866,   174,     0,   610,     0,  1281,  1282,
     610,   610,   610,  1255,  1256,  1258,  1259,  1260,  1264,  1263,
    1261,  1262,     0,   611,   606,   610,  1730,   610,   610,  1013,
     610,   610,  1246,  1245,   610,  1233,     0,  1560,  1561,     0,
    1075,     0,    23,  1160,  1162,  1161,   390,   389,   610,   610,
    1137,   467,   610,   610,   610,   610,     0,   610,     0,     0,
     610,   430,  1592,  1590,  1591,  1587,  1589,  1586,  1588,  1580,
       0,   610,     0,   610,     0,   429,     0,   610,   503,   502,
       0,     0,   473,   470,   479,   610,   476,   610,   610,   414,
     610,   610,   610,   610,   610,   610,   610,   610,   610,   610,
     610,   610,   610,   610,   610,   610,   610,   163,   164,   165,
     166,   167,   168,   504,   505,   506,   443,   610,   610,   442,
     448,     0,   610,   394,   610,     0,   395,   385,   391,   393,
     396,   397,   398,   399,   400,   392,   421,   420,   464,   610,
     971,     0,     0,   349,    24,   343,   610,   610,  1067,   610,
     610,   610,   610,   610,   610,     0,   988,  1707,   610,   610,
     185,     0,   610,   610,  1763,   610,   610,   610,   610,   610,
     136,     0,   610,   998,   990,   991,   996,  1375,  1376,   917,
     333,   407,   610,   530,   581,   580,   578,  1019,   582,  1024,
    1020,  1023,   772,     0,  1021,  1022,   773,  1029,  1033,  1026,
    1027,  1031,  1032,  1030,  1028,  1034,     0,   806,   610,   610,
       0,   404,   405,   402,   403,   610,     0,     0,   762,   761,
     760,  1764,  1771,    23,  1126,  1127,  1128,  1129,  1123,  1121,
    1220,  1135,  1120,  1116,   610,     0,  1117,  1759,    79,   610,
       0,   610,   610,    96,     0,    97,   610,     0,   610,    72,
     610,   610,   109,   104,     0,   896,     0,   895,     0,   463,
    1105,   610,   946,   947,   970,   942,   943,   799,   968,  1061,
    1225,   610,  1227,  1226,   696,   610,   610,   610,   685,   715,
     715,   713,   610,   610,   716,     0,    25,   684,   687,     0,
     694,   690,   919,   908,  1704,  1705,  1695,  1695,     0,     0,
    1618,   610,   185,  1328,   610,   610,  1329,  1372,   185,   610,
    1373,   610,  1657,   610,  1342,     0,  1390,  1388,  1387,  1386,
    1384,  1385,  1383,  1381,  1378,  1449,  1448,  1379,  1380,  1389,
    1627,  1382,  1711,  1710,  1709,  1793,  1793,   555,   546,   537,
       0,   541,  1793,   903,   174,     0,   320,   212,     0,   185,
     221,   204,  1210,   174,  1198,  1440,   610,  1439,     0,     0,
    1441,  1284,     0,  1290,  1286,  1283,     0,     0,   610,     0,
       0,     0,  1280,  1276,  1431,  1430,  1429,  1251,  1250,   610,
    1275,  1271,   610,  1267,  1265,     0,   610,   605,     0,     0,
    1012,   610,     0,  1010,  1736,  1738,  1737,  1734,  1783,  1780,
    1244,   610,   610,   610,  1238,   463,   341,     0,  1203,    91,
       0,     0,     0,     0,  1657,     0,     0,     0,     0,     0,
     521,   507,   512,     0,   508,   511,   510,     0,     0,     0,
       0,     0,     0,   417,     0,   170,     0,   433,   610,   610,
     610,     0,   610,     0,     0,     0,   435,   434,   449,   444,
     455,   458,   459,   456,   462,   461,   460,   450,   451,   453,
     452,   454,   445,   447,   463,   457,   446,   463,    91,   427,
     610,  1235,  1003,  1071,  1072,  1069,  1068,     0,   894,     0,
       0,   585,     0,     0,   610,   982,   980,     0,   708,   709,
       0,     0,  1762,  1770,     0,     0,   592,     0,   594,   750,
       0,   140,   610,   992,   999,     0,   610,  1007,   610,   336,
     610,   610,   610,   610,    23,  1045,  1350,     0,     0,   796,
     784,   794,   795,   782,   783,   790,   786,   789,   785,   793,
     788,   791,   792,   781,   787,   780,   779,  1018,   807,   410,
     610,  1050,   610,  1773,   763,   764,   360,   610,  1131,   610,
    1134,  1119,  1793,    91,     0,     0,     0,     0,   610,     0,
     610,    62,    91,     0,   115,   110,     0,   105,   610,   112,
     106,   880,   872,   878,     0,  1104,   610,  1106,  1108,     0,
     610,   950,     0,   610,     0,   610,  1060,  1224,  1793,   667,
     672,   675,   688,   686,   602,     0,   610,   610,   731,   769,
     729,   725,   723,   767,     0,     0,   755,     0,   717,   727,
     960,   956,   610,     0,     0,     0,   693,   610,     0,   610,
     610,     0,     0,   610,  1563,     0,  1444,  1445,  1716,  1411,
    1466,   610,     0,  1714,     0,     0,  1659,  1660,  1658,   610,
    1307,   610,  1394,  1400,  1399,  1398,  1402,     0,  1395,  1396,
     610,  1628,  1639,   543,   545,   610,     0,   558,   550,   552,
       0,   547,   548,   610,   610,   566,   568,   610,     0,   564,
     905,   845,   211,     0,     0,   223,  1166,   867,  1144,  1419,
    1421,     0,  1288,   610,     0,   610,   610,     0,  1278,   610,
     610,  1555,  1553,  1540,  1542,  1538,     0,  1537,     0,  1546,
    1533,  1554,     0,  1545,  1530,  1536,  1552,  1544,  1435,  1527,
    1528,  1529,     0,  1273,  1269,     0,   610,  1257,   609,     0,
     608,   610,   978,     0,   610,   610,  1779,     4,     8,    10,
    1559,  1562,   610,   463,   495,   468,    92,    93,    95,   492,
     491,   494,   490,   610,   419,   501,   486,   486,     0,   509,
       0,   513,     0,   281,  1202,     0,  1600,  1598,  1599,  1595,
    1597,  1594,  1596,  1585,   493,  1202,   500,   418,   265,     0,
    1202,   474,   471,   480,  1202,   477,  1202,  1202,  1202,   610,
       0,   610,     0,   465,     0,   610,   610,  1000,   610,   610,
     610,   610,   610,     0,   610,   185,   707,   610,   589,   591,
     610,   610,   157,   155,   610,   610,   137,     0,   147,   153,
     715,   142,   144,   610,   997,  1008,  1009,     0,   408,   335,
     340,   587,   334,   610,   337,   342,  1351,   531,   579,   577,
     779,   774,   775,  1049,  1051,   610,   406,   361,  1124,  1122,
    1221,  1222,     0,    80,    65,  1215,     0,     0,     0,    98,
       0,     0,    73,    69,  1793,  1793,   108,   103,   117,   113,
       0,   107,   770,   881,   602,  1793,   871,   870,   879,  1002,
     610,     0,   610,   969,   463,     0,     0,  1678,  1571,  1574,
    1679,  1582,  1572,  1676,   610,     0,  1066,  1675,     0,   610,
    1677,     0,     0,     0,     0,  1733,  1573,  1062,  1063,  1674,
    1579,  1065,  1667,  1739,  1668,   698,   691,   689,     0,    23,
     610,   745,   719,   747,   721,  1793,  1793,  1793,  1793,   779,
     740,   739,   735,   737,   744,   743,   733,   741,   714,   718,
    1793,   602,    45,    43,    40,    34,    38,    42,    37,    30,
      39,    33,    36,    31,    41,    32,    44,    35,     0,    28,
       0,   695,  1696,   610,   610,  1693,  1644,  1645,  1637,  1623,
    1638,     0,     0,   610,  1041,  1443,  1446,   610,     0,   610,
     610,  1467,  1362,  1334,  1719,  1718,  1717,   610,   610,  1640,
    1661,  1663,     0,  1357,   610,  1356,   610,  1358,  1353,  1354,
    1355,  1346,  1343,   610,   610,  1401,   610,     0,     0,  1632,
    1629,  1630,   557,   562,   610,   610,  1793,  1793,   535,   549,
     572,   560,   574,  1793,  1793,   570,   554,   565,   836,   321,
     205,     0,  1192,  1211,   836,     0,  1199,  1192,   610,     0,
    1285,     0,   610,     0,   610,     0,  1472,  1474,  1476,  1522,
    1521,  1520,  1519,  1478,     0,  1501,  1287,  1564,     0,  1420,
     610,  1423,     0,  1427,   610,  1277,     0,     0,  1608,  1606,
    1607,  1603,  1605,  1602,  1604,     0,     0,     0,     0,     0,
       0,     0,     0,  1433,     0,  1436,  1437,   610,  1272,   610,
    1266,  1268,   607,  1735,   610,     0,  1781,   610,     0,  1248,
     610,     0,     0,   610,     0,   483,     0,   484,     0,   523,
       0,   520,   517,   488,   482,  1140,  1593,     0,  1139,     0,
     169,  1138,     0,     0,     0,  1141,     0,  1143,  1142,  1136,
     436,     0,   439,     0,   438,     0,     0,     0,   610,     0,
    1300,  1786,  1785,   586,   610,     0,    46,   610,   712,   711,
     710,  1301,   610,     0,   715,  1793,  1793,   149,   612,   159,
     151,   161,   141,   148,  1793,   610,     0,   610,     0,   610,
       0,   610,  1793,     0,   777,   602,   610,  1760,     0,    91,
     610,    63,   610,   610,   610,    76,     0,    91,   116,   111,
    1793,  1793,   101,   779,   882,   876,   884,   883,   873,   527,
     931,   948,   949,   944,   610,  1576,  1575,  1578,  1577,  1581,
       0,     0,   610,  1523,     0,  1523,  1523,  1523,  1523,   610,
     610,   610,   610,   610,   610,  1720,  1721,  1722,  1723,  1724,
    1725,  1670,   610,   701,   699,     0,   678,   692,   603,   756,
       0,   610,  1793,   610,  1793,   732,   730,   726,   724,   768,
       0,  1793,     0,  1793,   728,    23,     0,    26,     0,  1699,
    1657,  1627,   610,   610,  1636,  1619,  1635,  1447,     0,  1413,
       0,  1361,  1454,   610,     0,  1715,     0,  1712,   610,  1653,
     642,   627,   640,   646,   661,   626,   638,   621,   654,   657,
     660,   624,   655,   633,   637,   648,   659,   656,   658,   649,
     631,   629,   653,   635,   634,   622,   623,   625,   628,   639,
     651,   630,   663,   641,   645,   647,   662,   636,   650,   652,
     632,   643,   644,  1665,  1664,   610,  1360,  1359,  1347,  1345,
       0,  1404,     0,  1397,   610,   610,   610,   610,   559,   556,
     551,   553,   610,  1793,  1793,   567,   569,  1793,  1793,     0,
       0,  1190,  1191,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1189,     0,     0,  1177,  1178,  1179,
    1176,  1181,  1182,  1183,  1180,  1167,  1158,   610,     0,  1214,
       0,  1793,     0,  1153,     0,     0,     0,     0,     0,     0,
     610,  1145,  1146,     0,  1078,     0,  1289,     0,  1481,   610,
       0,  1501,  1480,  1477,   610,  1442,   610,  1515,  1511,  1512,
    1509,  1518,  1517,  1510,  1513,  1514,  1516,   610,     0,  1502,
       0,     0,   610,     0,  1567,     0,   610,     0,   610,  1426,
    1279,  1425,  1417,     0,     0,     0,  1557,  1549,  1549,     0,
       0,  1549,  1556,     0,  1571,  1432,  1434,  1437,  1274,  1270,
    1015,   610,     9,   610,  1241,   853,  1076,   469,    94,   610,
    1466,  1647,     0,   486,   514,     0,     0,   274,   475,   472,
     481,   478,   610,   441,   440,   466,   347,  1236,     0,   610,
    1777,     0,     0,   983,    47,     0,   593,   595,   590,   765,
     158,   156,   610,  1793,   610,   610,   610,  1793,   154,   143,
     610,   146,   145,   610,   989,   993,   339,   610,   966,  1352,
     964,     0,   779,   776,    23,  1125,    86,  1216,    68,   610,
       0,    99,    66,    91,    74,     0,   118,   114,   771,  1793,
     886,   602,   885,   610,   524,   610,   801,   802,   800,     0,
    1687,     0,     0,     0,  1525,  1526,  1524,   610,   610,   610,
     610,   610,   610,  1689,     0,  1064,  1672,  1673,  1669,  1671,
    1740,   610,  1793,   697,   682,   679,     0,   746,   720,   748,
     722,   738,   736,   742,   734,   757,    29,    27,   610,  1694,
     610,  1624,  1625,  1621,  1627,   610,  1412,   610,  1415,     0,
    1336,  1331,  1330,  1333,   610,  1662,   610,  1641,     0,   610,
    1308,  1314,     0,  1317,  1319,  1348,  1344,   610,  1403,   610,
       0,  1633,  1631,   563,   561,   573,   575,   571,     0,     0,
     228,  1184,  1185,  1186,  1188,  1171,  1169,  1168,  1172,  1173,
    1170,  1187,  1174,  1175,  1159,   975,  1194,   972,   610,     0,
    1212,     0,  1157,  1156,  1151,  1149,  1148,  1152,  1150,  1154,
    1155,  1147,  1200,  1422,  1657,  1479,  1473,  1475,  1483,   610,
    1496,   610,  1494,  1504,  1503,   610,  1691,   610,  1488,  1487,
    1489,     0,  1485,  1486,  1506,  1505,     0,  1418,  1424,   610,
    1428,  1615,  1613,  1614,  1610,  1612,  1609,  1611,  1539,     0,
    1541,     0,     0,     0,     0,  1547,  1551,     0,  1531,  1438,
    1014,  1249,  1242,  1239,   610,  1455,  1456,  1458,  1461,  1468,
     610,     0,  1523,  1649,  1643,   487,   485,     0,   519,   518,
    1601,   171,   437,   610,    23,     0,   610,  1006,   610,    48,
     986,     0,    23,   160,   150,     0,   614,   616,   162,   152,
     765,     0,   338,   610,   610,   532,   778,  1047,   610,    81,
       0,    64,     0,    77,    86,    70,   877,   874,   528,  1793,
       0,  1583,     0,     0,     0,  1688,     0,   610,     0,     0,
       0,     0,   610,  1685,     0,   700,   677,   683,   602,  1703,
       0,  1701,  1653,  1627,  1627,  1620,  1414,  1657,  1416,  1410,
     610,  1335,     0,  1713,  1654,     0,   610,  1321,     0,  1310,
     610,   610,   610,  1405,  1408,  1392,  1406,  1409,   610,   847,
     846,   322,   206,   977,   976,   974,   610,  1193,  1079,  1083,
    1085,   610,  1089,   610,  1087,  1091,  1080,  1081,     0,   868,
       0,   610,     0,  1497,  1500,  1499,     0,     0,     0,  1692,
    1491,  1482,     0,  1565,  1569,  1564,     0,  1558,  1550,  1534,
    1532,     0,  1535,   610,  1459,   610,  1570,  1462,   610,  1469,
    1470,  1652,  1241,   610,   610,   610,   516,   515,   348,   345,
     610,  1004,     0,     0,     0,   985,   766,   138,   613,    23,
     995,   967,   965,  1052,    87,  1217,    82,     0,    75,    86,
    1793,   525,   945,     0,     0,     0,  1684,     0,  1680,  1681,
    1682,  1683,  1690,   702,   758,   610,  1700,     0,  1626,  1622,
     610,  1337,   610,  1647,   610,  1326,  1316,  1323,  1325,  1327,
     610,     0,   610,   610,  1309,  1318,  1320,  1349,   610,  1393,
    1391,  1634,   973,  1793,  1793,  1093,  1793,  1095,  1793,  1793,
    1082,  1213,  1201,     0,   610,  1495,  1493,   610,  1691,  1508,
       0,  1568,     0,  1548,  1463,     0,  1457,  1451,  1452,  1666,
     610,  1471,  1465,  1650,  1367,  1363,  1364,  1369,  1368,  1648,
    1241,   350,  1005,  1776,   610,   610,   610,   610,   610,   610,
      53,     0,    52,     0,    50,   610,   610,   139,  1056,  1048,
       0,  1054,    86,    91,    86,    71,   875,     0,     0,  1728,
       0,  1686,  1793,    23,  1702,  1647,     0,  1341,     0,  1338,
    1340,  1642,     0,  1327,   610,  1322,     0,  1311,  1312,  1407,
    1084,  1086,  1793,  1090,  1793,  1088,  1092,     0,  1498,  1507,
    1490,  1492,  1566,  1543,   610,  1460,   610,  1450,   610,  1371,
    1370,  1366,  1651,   356,   354,   346,     0,   352,   358,    55,
      60,    57,    59,    56,    58,    54,     0,    49,     0,   615,
     617,  1793,  1053,  1055,  1218,    83,    78,   526,  1726,  1727,
     698,   759,  1646,  1655,   610,  1332,  1315,  1324,   610,  1094,
    1096,  1656,  1464,  1453,  1365,  1793,  1793,   351,   353,  1793,
      51,   610,  1057,     0,   703,  1339,     0,   357,   355,   359,
       0,    84,  1313,   987,    88,    90,   610,    85,    89
};

/* YYDEFGOTO[NTERM-NUM]. */
static const short yydefgoto[] =
{
      -1,   549,   550,   551,   552,   701,  1707,  1708,   188,   264,
     189,  1123,  1124,  1593,  1928,  2952,  2453,  2454,  2843,  2953,
    2954,   553,   891,  2489,  2157,  2859,  1542,  2156,  2724,  2493,
    2857,  1533,  2148,  2963,  3063,  3074,  2719,  3077,  1715,  1716,
    1717,  1224,  1828,   554,  1234,   896,  1232,  1549,  1837,  1546,
    1835,  1840,  2161,  1233,  1834,  1550,  2160,   555,    16,    35,
      36,    37,    38,    39,   113,   558,   819,  1481,  1150,  1786,
    1790,  1791,  1787,  1788,  2463,  2467,  2134,  2126,  2125,  2127,
    2130,  1106,  1058,  1749,   559,    83,    84,    18,    60,   142,
      96,   255,    98,    99,   200,   278,   100,   101,   242,   228,
     673,  2320,   305,   655,  1653,   332,   333,   229,   287,   280,
     282,   974,   975,   146,   355,   147,   148,   293,   230,   231,
    1467,   393,   243,   246,   244,   245,   314,   370,   371,   373,
     378,   658,   247,   248,   323,   375,   196,    19,    80,   177,
     178,   179,   664,  2319,   180,   251,   240,   326,   327,   328,
     329,  1494,   560,   561,   562,   563,   776,  2941,  2694,  1125,
    3015,  3016,  3017,  3056,  3055,  3059,   564,   565,   566,   567,
     752,  1107,   857,  1192,  1193,  1160,   854,  1161,   754,   755,
     756,   757,   758,   759,   760,  1061,  1108,  2101,  1109,  1110,
    1111,  1112,  1113,  1114,  1115,   707,   761,  1448,  2105,  1389,
    2072,   762,  1419,  2093,  1418,  2092,  1422,  2096,  1420,  2094,
    2075,  2084,   763,   764,   765,   766,  1403,  1404,  1405,  1406,
     568,  2729,  2967,  2504,   569,   827,  1496,  2142,   114,   237,
     365,  1318,   956,   957,   958,  1315,  1316,  1640,  1641,  1642,
    1986,  1987,  1319,  1320,  1636,  1990,  1982,  1648,  1649,  1993,
    1994,  2317,  2313,  2314,   570,  1167,    85,  1462,  1463,  1802,
     859,   809,   862,   684,   798,   781,   820,  1889,    86,   685,
    1003,  1699,    41,   127,  2129,    87,   768,  2293,   571,   572,
     911,   912,   573,   574,   575,   576,   919,  2534,   940,  2746,
     941,  1572,   942,  1886,   943,  2206,   944,  1596,   577,  1568,
    2205,  2532,  2531,  2972,   115,    20,   578,  1141,  1468,  1469,
    1586,  1265,  1587,  1588,  2212,  2214,  1898,  1897,  1910,  1896,
    1895,  2223,  2221,  1902,  1903,  1906,  1907,  1892,  1894,   579,
     580,   817,   581,  1261,   926,  2973,   582,  1200,  2702,  1589,
    1899,  1843,  2163,   850,  1177,  1516,  1811,  2143,  1812,  1173,
    1515,   583,   584,   905,  1564,  2508,   585,   586,   587,   588,
      21,    64,    22,    23,    24,   116,   117,   589,   118,    25,
     645,    26,   119,   120,   157,   367,  1324,  1998,  2780,   121,
     153,   298,   590,  2071,    27,    28,    29,    30,    31,    59,
      88,   122,   412,  1333,  2004,   591,   900,  1847,  1553,  1845,
    2860,  2499,  1554,  1844,  2166,  2501,   592,   593,   594,   792,
     793,  1236,   123,   238,   366,   649,   650,   960,  1322,   595,
     945,   946,   596,   823,  1273,   947,   769,    90,    91,    92,
      93,  1243,   183,   138,    94,   135,   191,   192,  1244,  1245,
    2173,  1246,   409,   410,   928,   411,   929,  2479,  2480,  1247,
    1248,  1121,  2606,  2607,  2785,   690,   807,   808,   597,  1136,
    2845,   598,  2475,   599,  1154,  1155,  1156,  1487,  1485,   600,
     601,  1767,  1797,   602,  1009,  1373,   603,   851,   852,   604,
     867,   605,  1938,   606,  2853,   607,  1815,  2959,  2960,  2961,
    3031,   856,   608,  1249,  1566,  1877,  1878,   609,  1455,   706,
    1021,   610,   611,  2006,  2610,  2796,  2797,  2903,  2904,  2908,
    2906,  2909,  2992,  2994,   612,   613,  1238,  1558,   614,  1240,
     875,   876,   877,  1216,   615,   616,   617,  1528,  1208,   870,
     199,   878,   879,   770,  2007,  2361,  2362,  2345,   710,   711,
    2002,  2346,  2349,   124,   152,   359,   984,  1658,  2363,  2800,
    1030,   618,   868,   125,   149,   356,   981,  1656,  2350,  2798,
    2003,   895,  2149,  2720,  2962,  1211,   619,   620,   621,   622,
     623,   779,  1765,   703,  1712,  2673,   697,   698,  2068,  1352,
     624,   625,   626,   993,   994,   995,  1364,  1695,   996,  1692,
    1361,   997,  1667,  1353,   998,   999,  1000,  1001,  1661,  1344,
     627,   788,   771,   628,  1296,  1962,  2769,  2894,  2570,  2571,
    2572,  2573,  2768,  2886,  2887,  1297,  1298,  1611,  2562,  2762,
    2244,  2559,  2978,  2979,  1299,  1621,  2298,  1972,  2576,  2772,
    1807,  2141,  1973,  1300,  1301,  2683,  2935,  2936,  2937,  3011,
    1302,  1303,  1158,   629,   630,   953,  1304,  1305,  2900,  1627,
    1628,  1629,  1975,  2300,  2775,  2776,  1306,  1948,  2238,  2759,
    1354,  1355,  1340,  2028,  1659,  2029,  1356,  2032,  1357,  2055,
    1358,  2056,  2416,  1662,  1307,  1605,  1606,  1945,  1308,  2931,
    2829,  2927,  1951,  2430,  2675,  2676,  2677,  2925,  2431,  1952,
    2830,  2932,  2015,  2016,  2017,  2018,  2019,  2020,  2641,  2642,
    2643,  2919,  2808,  3000,  2021,  2802,  2803,  2391,  2022,  2392,
    2023,  2517,  1688,  1689,  1690,  2662,  1691,  2413,  2407,  2818,
    2030,  2777,  2394,  2574,  2827,  1879,   772,  1880,  2179,  1049,
    2076,  1743,  2045,  2658,    58,   631,   632,  2554,  2754,  2231,
    2753,  1632,  1980,  1981,  2235,  1939,  1309,  1940,  2249,  2765,
    1395,  1935,  1936,  2684,  2832,  2567,  2558,  2024,  1619,  1959,
    1960,  2928,  2025,  1882,  2524,  2810,   633,   634,  1598,  1937,
    2549,  2750,  2751,  1276,   635,   774,  1311,  1312,  1614,  2246,
    1313,  1314,  1956,  2201,  2513,   691,  1883,   693,  1377,  1884,
      62,    47,    78,    75,   637,   881,  1532,  1144,  1202,   638,
     860,   639,  2116,   640,  1706,   695,  1379,   641,   642,    73,
     360,   361,   362,   363,   364,   643
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -2538
static const short yypact[] =
{
    1374,  1141, -2538,   625,   625,   625,   625,   625,   625,   625,
   -2538,   625, -2538,   313, -2538, -2538, -2538,  1451, -2538, -2538,
   -2538,   351, -2538,  1374, -2538, -2538, -2538, -2538, -2538,  1551,
   -2538, -2538, -2538, -2538, -2538,   384,   396, -2538,   446, -2538,
   -2538,   543, -2538, -2538,   120, -2538,   -78, -2538, -2538, -2538,
   -2538, -2538, -2538, -2538, -2538, -2538, -2538, -2538, -2538,   267,
     472, -2538, -2538, -2538,   169, -2538, -2538, -2538, -2538, -2538,
   -2538, -2538, -2538, -2538, -2538, -2538, -2538, -2538, -2538,   120,
     249, -2538, -2538,   531,  1451, -2538,   772, -2538, -2538, -2538,
   -2538,   868,   307, -2538, -2538, -2538,   909,   602, -2538, -2538,
   -2538,   942, -2538, -2538, -2538, -2538, -2538, -2538, -2538, -2538,
   -2538, -2538, -2538, -2538, -2538, -2538, -2538,   169, -2538, -2538,
   -2538, -2538, -2538, -2538, -2538, -2538, -2538, -2538, -2538, -2538,
    4373,   307, -2538,    96,    80, -2538, -2538,   523, -2538,   370,
     960,   472,   493, -2538, -2538, -2538, -2538, -2538,  7806, -2538,
     593,   920, -2538,  1451, -2538, -2538, -2538, -2538, -2538, -2538,
     520,  1182, -2538, -2538,   635, -2538,   637, -2538,   617, -2538,
   -2538,   648, -2538,   652, -2538, -2538, -2538, -2538, -2538, -2538,
   -2538, -2538, -2538,   655, -2538, -2538, -2538,    80,  1606,  1060,
   -2538,   188, -2538,    80, -2538, -2538,   162, -2538, -2538, -2538,
     138, -2538, -2538, -2538, -2538, -2538, -2538, -2538, -2538,   520,
   -2538,  1182, -2538, -2538,   679, -2538,   685, -2538,   681, -2538,
   -2538,   707, -2538,   724, -2538, -2538, -2538, -2538, -2538, -2538,
   -2538, -2538,   729,  1119, -2538,   757, -2538,  1451,  1451,   775,
   -2538, -2538,   428, -2538,   587,  1187, -2538,   591,  1258,  1180,
    1185, -2538,  1188,  1196,  1198, -2538,   632, -2538,   538, -2538,
   -2538, -2538, -2538, -2538,    80, -2538,    80,   796,   197, -2538,
   -2538, -2538,  1211, -2538, -2538,  1215, -2538, -2538, -2538, -2538,
   -2538,   428, -2538, -2538, -2538,  1227,  1235,   472,  1188,  1242,
    1244,   689, -2538,  1243, -2538,   926,   892, -2538,   964, -2538,
   -2538, -2538,   719, -2538, -2538,  1281, -2538,   912, -2538, -2538,
   -2538, -2538, -2538, -2538, -2538,  1258,   912, -2538, -2538, -2538,
   -2538, -2538, -2538,   918,   161,   226,   336, -2538,  2484, -2538,
   -2538, -2538,   928,  1324,   238,   977, -2538, -2538,  1606, -2538,
      80, -2538, -2538, -2538,   756,  1331,  1122,   263,   271,   394,
     958,   292,   995, -2538, -2538, -2538,   997, -2538, -2538,   997,
    1028, -2538,  4070,   493,  4930,  2395,   257,   997,  1351,    -9,
   -2538,  1187,  1347, -2538, -2538, -2538, -2538,  1348, -2538,  1350,
   -2538,  1352, -2538, -2538, -2538, -2538, -2538, -2538,  1188,  1357,
   -2538, -2538, -2538, -2538,   200,  1356,    -9,   979,  1364, -2538,
    1373, -2538, -2538, -2538,  1377, -2538, -2538, -2538,   806,  1036,
    1419, -2538,   997,  1055, -2538, -2538, -2538, -2538, -2538, -2538,
   -2538, -2538,    99, -2538, -2538, -2538, -2538, -2538, -2538, -2538,
      68, -2538, -2538, -2538, -2538, -2538, -2538, -2538, -2538, -2538,
   -2538, -2538, -2538, -2538,   115,   115,  6776, -2538, -2538, -2538,
   -2538, -2538, -2538, -2538, -2538, -2538, -2538, -2538, -2538, -2538,
   -2538, -2538, -2538, -2538,   838, -2538, -2538, -2538,  6776, -2538,
     838, -2538,   838,   988, -2538, -2538,    63, -2538, -2538,    63,
   -2538, -2538,    63, -2538, -2538, -2538, -2538, -2538, -2538, -2538,
   -2538, -2538,   838, -2538, -2538, -2538, -2538,  -102, -2538, -2538,
   -2538, -2538, -2538, -2538,    99, -2538, -2538, -2538, -2538, -2538,
    3818,   838,  7449, -2538,   785,   785, -2538, -2538, -2538,   171,
     838,   103,  6776,  7449, -2538,   792,  6776, -2538,   120, -2538,
    7449, -2538,  7449,   838, -2538, -2538,  7449,  7449,   115, -2538,
   -2538, -2538,   785, -2538, -2538,   785, -2538, -2538,    67, -2538,
   -2538, -2538, -2538, -2538, -2538, -2538, -2538, -2538, -2538, -2538,
   -2538, -2538, -2538, -2538, -2538, -2538, -2538, -2538, -2538, -2538,
   -2538, -2538, -2538, -2538, -2538, -2538, -2538, -2538, -2538, -2538,
   -2538, -2538, -2538, -2538, -2538, -2538, -2538, -2538, -2538, -2538,
   -2538, -2538, -2538, -2538, -2538, -2538,    50, -2538, -2538, -2538,
   -2538, -2538, -2538, -2538, -2538, -2538, -2538, -2538, -2538, -2538,
   -2538, -2538, -2538, -2538, -2538, -2538, -2538, -2538, -2538, -2538,
   -2538, -2538, -2538, -2538, -2538, -2538, -2538, -2538, -2538, -2538,
   -2538, -2538, -2538, -2538, -2538,   580, -2538, -2538, -2538, -2538,
   -2538, -2538, -2538, -2538, -2538,   628, -2538, -2538, -2538,   319,
   -2538,  1063, -2538, -2538, -2538,  1163, -2538, -2538,  1075,  1077,
    1083,  1084, -2538, -2538,   852,  1452,  1088, -2538, -2538,  1179,
   -2538,  1091,  1093,   861,  1101, -2538, -2538, -2538,  1102, -2538,
     339, -2538,   243, -2538, -2538, -2538, -2538,   874,  1453,  1044,
   -2538,   888, -2538,   886, -2538,  1479,  -169,   294, -2538, -2538,
   -2538,  1087, -2538,  1478, -2538, -2538,  1045,   148, -2538, -2538,
   -2538,  1111, -2538,  7449,  7449, -2538, -2538,  1097,  1003,  1103,
    1104,  1106,  1120,  1124,  1126,  1133,  1135,  1136,  1138,  7449,
    1436,  1148,  1149,  1150, -2538,  7449,  7449,  1153,  1157, -2538,
    7449,  1167, -2538,  1170,  1173,  1174,  1175,  1184,  1190,  1191,
    7449,  1192,  5910, -2538,   118, -2538, -2538, -2538, -2538, -2538,
   -2538, -2538, -2538, -2538, -2538, -2538, -2538,   490, -2538,  1129,
   -2538, -2538, -2538, -2538, -2538, -2538,   838, -2538, -2538,  1478,
   -2538,   -29, -2538, -2538,  1342, -2538,   159, -2538,  1112, -2538,
   -2538, -2538, -2538,  1583, -2538, -2538,   202, -2538,   994, -2538,
    1000,  1583, -2538,  1020, -2538, -2538,  1203,   108, -2538,  1169,
   -2538,   967, -2538, -2538,  1206, -2538,  -121, -2538,   974,   -83,
    -166, -2538,  1311,  7449,  7449, -2538,  1610, -2538, -2538, -2538,
   -2538, -2538, -2538,   124,   124,   124, -2538,   124, -2538,   124,
     124,  1059,   -29,  1059,  1059,   109,   109,  1059,  1059,   -29,
   -2538,  1625, -2538,   107,  1630, -2538,   -29, -2538,  6540, -2538,
      70,    56, -2538, -2538,  7449, -2538, -2538, -2538, -2538, -2538,
     929, -2538, -2538,   493,  1278,   493,  6776, -2538,    71, -2538,
   -2538,  7449,  1239,  1241,  1250,  1253,  1256,  1648,  1264,   103,
    1173, -2538,  1353,   779,  1107, -2538,  1127, -2538, -2538, -2538,
     134, -2538,  1678, -2538,  1674, -2538, -2538,   286,  1134, -2538,
   -2538,  1687, -2538,  1062,  1687,  1688,  1064,  1687,  1688,  7449,
    1687, -2538, -2538,   148,   838, -2538, -2538,  1298,   305, -2538,
   -2538,  1289,   838,  7449,  1292, -2538, -2538,  1680,  1681,  1666,
   -2538, -2538, -2538, -2538, -2538, -2538, -2538, -2538,   135,   135,
   -2538, -2538, -2538,  1516, -2538, -2538,  1638,   628, -2538, -2538,
     387, -2538, -2538, -2538,  1275, -2538, -2538, -2538, -2538,  4373,
    1188, -2538,  1282, -2538,   295, -2538, -2538, -2538, -2538, -2538,
   -2538,  1451, -2538, -2538,  1451,   740,  1306,  1695, -2538, -2538,
     644,  1313,   658,  1721, -2538, -2538, -2538, -2538, -2538, -2538,
   -2538, -2538,  1319, -2538, -2538,  1453,   886,    80,    99,   114,
    1709, -2538, -2538, -2538, -2538, -2538,  1159,  1142,  1177,  1340,
   -2538,  1344,   102, -2538, -2538, -2538,  6466,  6466,   785,  7449,
   -2538, -2538,   785,   785,   785,   785,  1304,  7449,  1240,  1486,
    7449,  5910,  1366, -2538, -2538, -2538, -2538, -2538, -2538, -2538,
    1155,   785,  1742,  7449,  3998,  5910,  1304,  7449, -2538,  5910,
    1745,   437, -2538, -2538, -2538,  7449, -2538,  7449,  7449,  5910,
    7449,  7449,  7449,  7449,  7449,  7449,  7449,  7449,  7449,  7449,
    7449,  7449,  7449,  7449,  7449,  7449,  7449, -2538, -2538, -2538,
   -2538, -2538, -2538, -2538, -2538, -2538, -2538,  7449,  7449, -2538,
   -2538,  1367,  7449, -2538,  7449,  1371, -2538, -2538, -2538, -2538,
   -2538, -2538, -2538, -2538, -2538, -2538, -2538, -2538, -2538,   838,
   -2538,  1161,  1376, -2538, -2538, -2538,    99,   145, -2538,   145,
     103,    63,  7449,  7449,  7449,  1379, -2538, -2538,   838,   838,
   -2538,  1181,   103,   785,  1152, -2538,    80,    52,  -102,   838,
   -2538,  1194,  7449,  1465, -2538, -2538,  1260, -2538, -2538,  1630,
      77, -2538,   148, -2538, -2538,  1779,  1781, -2538, -2538, -2538,
   -2538, -2538, -2538,    55, -2538, -2538, -2538, -2538, -2538, -2538,
   -2538, -2538, -2538, -2538, -2538, -2538,  3818, -2538,   109,  7449,
     -68, -2538, -2538,  1795, -2538,   785,  1777,  1782, -2538, -2538,
   -2538, -2538, -2538,   125, -2538, -2538, -2538, -2538,  1675, -2538,
    1611, -2538, -2538, -2538,  7449,   115, -2538, -2538, -2538, -2538,
    1785,   785,   785, -2538,  1251, -2538,   785,  1208,   838, -2538,
   -2538,  7449,   -54, -2538,  1263, -2538,   240, -2538,  1365, -2538,
    1368,  7449,   835, -2538, -2538,   307, -2538,  1820, -2538,  1303,
   -2538,   838, -2538, -2538, -2538, -2538,   785,   785,   222,   305,
    1702,  1074,   838,   148, -2538,  1314, -2538, -2538,  1835,  1816,
    1464, -2538, -2538, -2538, -2538, -2538,  1543,  1543,   377,  1321,
   -2538, -2538, -2538, -2538,  1478,  1478, -2538, -2538, -2538, -2538,
   -2538, -2538,   464,  1478, -2538,   697, -2538, -2538, -2538, -2538,
   -2538, -2538, -2538, -2538, -2538, -2538, -2538, -2538, -2538, -2538,
    1009, -2538, -2538, -2538, -2538,   177,   177,   127,   664, -2538,
     638, -2538,   387, -2538,  1451,  1819, -2538, -2538,  1819, -2538,
   -2538, -2538, -2538,  1451, -2538, -2538,  1478, -2538,   761,  1438,
   -2538, -2538,   761, -2538, -2538, -2538,  1440,  1442,   646,  1443,
    1445,  2755, -2538, -2538, -2538, -2538, -2538, -2538, -2538, -2538,
   -2538, -2538,   646,  1202, -2538,   339,  1832, -2538,  1273,   206,
   -2538,   103,  1328, -2538, -2538,  1044, -2538, -2538, -2538,  1349,
   -2538, -2538, -2538, -2538, -2538, -2538, -2538,  1514,  5910,  6776,
    1517,  1520,  1524,   297,   464,  1531,  5242,  1532,   -51,  1027,
   -2538, -2538,   156,  1533, -2538, -2538, -2538,  5274,  1880,  1487,
    1536,  1537,  5373, -2538,  1538,  2088,  1539, -2538,  7449,  7449,
    7449,  5644,  7449,  5741,  5775,  5871,  6046,  6144,  6280,  4104,
    6315,  2729,  6403,  3793,  1320,  6363,  6179,  6466,  6466,  6601,
    7756,  2497,  5910,  5910,  1304,  5910,  5910,  1304,  6776, -2538,
   -2538, -2538,  1322, -2538, -2538, -2538, -2538,  1312, -2538,  1905,
    1918, -2538,  1919,  1369,  7449, -2538, -2538,  1326,  1921, -2538,
    1467,  1325,  1688, -2538,  1563,   304, -2538,  1525, -2538, -2538,
    1333,  1178, -2538, -2538, -2538,  1534, -2538,   670,  7449, -2538,
   -2538, -2538,  7449,   -96,   -29,  1936,  1410,  1922,  1925, -2538,
   -2538, -2538, -2538, -2538, -2538, -2538, -2538, -2538, -2538, -2538,
   -2538, -2538, -2538, -2538, -2538, -2538,  1542, -2538, -2538, -2538,
     838,  1432,  6843, -2538, -2538, -2538,  1907,  7449,   493,    94,
   -2538, -2538,  1649,  6776,  1584,  1952,  1589,   321, -2538,  1590,
     103, -2538,  6776,  1552, -2538, -2538,  1624, -2538,  7449,   -11,
   -2538,  1390, -2538, -2538,   235, -2538,  7449, -2538, -2538,  1370,
      96, -2538,  1378, -2538,  1956,  6550, -2538, -2538,   129, -2538,
    1688,  1688,  1341, -2538,  1441,  1456,   785,   785, -2538, -2538,
   -2538, -2538, -2538, -2538,   504,   533, -2538,   989, -2538, -2538,
   -2538, -2538,   785,  1973,  1983,  1964, -2538,   103,  1764,    64,
    1544,  1913,    36,   158, -2538,    23, -2538, -2538, -2538,  1588,
      76,  1478,   275, -2538,  1399,  1396, -2538, -2538, -2538,  7687,
   -2538,  1825, -2538, -2538, -2538, -2538,  1593,  1403,  1998, -2538,
    1985, -2538, -2538, -2538, -2538,   838,   204, -2538, -2538, -2538,
    1393,   664, -2538, -2538, -2538, -2538, -2538, -2538,   721, -2538,
   -2538, -2538, -2538,  1609,  1612, -2538,  1576, -2538,  1580, -2538,
    1607,   326, -2538,  7511,   334,  1478,  1478,   338, -2538,  1478,
    7511, -2538, -2538,  1637,  1637, -2538,  1613, -2538,  1614,  1615,
   -2538,  1618,  1619, -2538,  1620, -2538, -2538, -2538,   247, -2538,
   -2538, -2538,   386, -2538, -2538,   401, -2538, -2538, -2538,  1651,
     307,  1709, -2538,  2022,   103,  7449, -2538,  2026, -2538, -2538,
   -2538, -2538,   646, -2538, -2538, -2538,  2030, -2538,  5910, -2538,
   -2538, -2538, -2538,  7687, -2538, -2538,  1436,  1436,  2011, -2538,
    2012,  1481,   855, -2538,  1003,  1676,  1642, -2538, -2538, -2538,
   -2538, -2538, -2538, -2538, -2538,  1003, -2538, -2538, -2538,  1683,
    1003,  5910,  5910,  5910,  1003,  5910,  1003,  1003,  1003,  7449,
    1690,  7449,  1691, -2538,  1463,   646,    60, -2538,   103,  7449,
    7449,  7449,  6910,  2058,   346, -2538, -2538,   103, -2538,  1468,
   -2538, -2538, -2538, -2538, -2538, -2538, -2538,  1395, -2538, -2538,
     771, -2538,  1474,  7449, -2538, -2538, -2538,  2056, -2538, -2538,
   -2538, -2538, -2538, -2538,  1688, -2538, -2538, -2538, -2538, -2538,
   -2538, -2538, -2538, -2538, -2538,   838, -2538, -2538,  3371, -2538,
   -2538, -2538,  1770, -2538, -2538, -2538,  1743,  1752,  1639,  1480,
    1755,  1671, -2538, -2538,   -41,  1744, -2538, -2538, -2538, -2538,
    1624, -2538, -2538, -2538,   164,   296, -2538, -2538, -2538,  1835,
    7449,  1677,  2062, -2538, -2538,   121,   152, -2538,   874, -2538,
   -2538,  1637, -2538, -2538,  7687,  1679, -2538, -2538,  1682, -2538,
   -2538,  1701,  1704,  1707,  1708,   -49, -2538,  2079, -2538, -2538,
   -2538,  2516, -2538,  1686, -2538,   142,  1457, -2538,  2065,   -29,
   -2538, -2538,  2087, -2538,  2106,  1048,  1048,  1048,  1048,  1542,
   -2538, -2538,  2113, -2538, -2538, -2538,  2116, -2538, -2538, -2538,
    1048,   163, -2538, -2538, -2538, -2538, -2538, -2538, -2538, -2538,
   -2538, -2538, -2538, -2538, -2538, -2538, -2538, -2538,   404, -2538,
    2094, -2538, -2538,  1478, -2538, -2538, -2538, -2538, -2538, -2538,
   -2538,  1548,  1549,    82, -2538,    23, -2538,  1478,  1528, -2538,
    7511, -2538, -2538,  1717, -2538, -2538, -2538, -2538, -2538,  2123,
   -2538,  4424,  1568, -2538,  7449, -2538,  7449, -2538, -2538, -2538,
   -2538, -2538, -2538, -2538,  1478, -2538,  1478,   501,  1535,  1550,
    2126, -2538,  2131, -2538,   838, -2538,   557,   557, -2538, -2538,
    2143, -2538,  2143,   726,   726,  2143, -2538, -2538,  2395, -2538,
   -2538,  4407,   126, -2538,  2395,  2066, -2538,   126,  1478,   761,
   -2538,  1747,   310,  1747,  4358,   244,  2145, -2538, -2538, -2538,
   -2538, -2538, -2538, -2538,   270,  1423, -2538,  -136,  1780,  2148,
   -2538, -2538,   408, -2538,   646, -2538,   411,   300, -2538, -2538,
   -2538, -2538, -2538, -2538, -2538,  1553,   -67,  2132,  2132,  2140,
    2132,  2132,  2141, -2538,   242, -2538,   761, -2538, -2538,   646,
   -2538, -2538, -2538,  1570,   103,  2159, -2538, -2538,   417, -2538,
    7047,  1800,  1809,  7449,   205, -2538,  1578, -2538,  1812, -2538,
    2160, -2538,  1616, -2538, -2538, -2538, -2538,  2161, -2538,  1597,
   -2538, -2538,  1823,  1824,  1828, -2538,  1833, -2538, -2538, -2538,
    5910,   420, -2538,   431, -2538,  1837,  2175,   440,   103,  2200,
   -2538, -2538, -2538, -2538,  7449,  1667,  1955,  7449, -2538, -2538,
   -2538, -2538,  2193,  1844,   771,  1397,  1397,  2210,  -101, -2538,
    2211, -2538, -2538, -2538,  1397, -2538,  1692,  2199,  2218, -2538,
    -116,   838,  2005,   442, -2538,  1441,  7449, -2538,  1855,  6776,
     838, -2538,    68, -2538,   838, -2538,  1857,  6776, -2538, -2538,
     -41,  1744, -2538,  1542, -2538, -2538,   175, -2538, -2538,  1684,
   -2538, -2538,  1791, -2538,  7182, -2538, -2538, -2538, -2538, -2538,
    1626,   947,   196,   522,  1821,   522,   522,   522,   522,  7687,
    6550,  7687,  7687,  7687,  7687, -2538, -2538, -2538, -2538, -2538,
   -2538, -2538,    99, -2538, -2538,  1813,   714, -2538, -2538, -2538,
    1634,   785,  1048,   785,  1048, -2538, -2538, -2538, -2538, -2538,
     504,  1048,   533,  1048, -2538,   -29,  1973, -2538,  1868,  1831,
     464,  1009,  1544,  1544, -2538, -2538, -2538, -2538,   444, -2538,
    1792, -2538,  2237,  1478,   -50, -2538,  1640, -2538,  7687,  1712,
   -2538, -2538, -2538, -2538, -2538, -2538, -2538, -2538, -2538, -2538,
   -2538, -2538, -2538, -2538, -2538, -2538, -2538, -2538, -2538, -2538,
   -2538, -2538, -2538, -2538, -2538, -2538, -2538, -2538, -2538, -2538,
   -2538, -2538, -2538, -2538, -2538, -2538, -2538, -2538, -2538, -2538,
   -2538, -2538, -2538, -2538, -2538,   209, -2538, -2538,  1715, -2538,
     447, -2538,  1643, -2538, -2538, -2538,  1985,   838, -2538,  2143,
   -2538, -2538, -2538,   726,   726, -2538, -2538,   726,  2060,  1647,
    1650, -2538, -2538,   115,   115,   115,  2227,   115,   115,   115,
     115,   115,   115,  2232, -2538,  2233,   115, -2538, -2538, -2538,
   -2538, -2538, -2538, -2538, -2538,  4407, -2538,   838,  1660, -2538,
    1834,  2060,  2236, -2538,  2240,  2244,  2246,  2248,  2249,  2250,
     172,  2066, -2538,  1834, -2538,   449, -2538,  1815, -2538, -2538,
     373,   924, -2538, -2538,  7511, -2538,  7511, -2538, -2538, -2538,
   -2538, -2538, -2538, -2538, -2538, -2538, -2538,  7687,  1870, -2538,
    1872,    17,  1846,  2258, -2538,  2014,  1478,  1693,  1478, -2538,
   -2538, -2538, -2538,  1769,  2261,  1769, -2538,  2285,  2285,   450,
    1924,  2285, -2538,  1926, -2538, -2538, -2538,   761, -2538, -2538,
   -2538,   103, -2538,   646,  2048,  1835, -2538, -2538, -2538,   154,
    1803,     1,  1487,  1436,  1731,   897,  1941, -2538, -2538, -2538,
   -2538, -2538,  7449, -2538, -2538, -2538,  1865, -2538,   210,   103,
   -2538,  2309,  1906, -2538, -2538,  1948, -2538, -2538, -2538,  1793,
   -2538, -2538, -2538,  1397,    80,  2300, -2538,  1397, -2538, -2538,
     785, -2538, -2538,  7449, -2538, -2538, -2538,   785,  1931,  2318,
   -2538,  2105, -2538, -2538,   -29,  5910,  2009, -2538, -2538,   148,
    1928, -2538, -2538,  6776, -2538,  1965, -2538, -2538, -2538,   296,
   -2538,  1441, -2538,  7449, -2538,    80, -2538,  1630, -2538,  1769,
   -2538,   423,  2329,  1966, -2538, -2538, -2538,  7687, -2538,  7687,
    7687,  7687,  7687,  2516,   453, -2538,  1497,  1497,  1741,  1762,
   -2538,  7449,  1923, -2538,  2018, -2538,  2323, -2538, -2538, -2538,
   -2538, -2538, -2538, -2538, -2538, -2538, -2538, -2538, -2538, -2538,
    7687, -2538, -2538, -2538,  1009,  1478, -2538, -2538,  2226,   454,
   -2538, -2538, -2538, -2538, -2538, -2538,   838, -2538,  2334,  1478,
   -2538,  2343,  2336, -2538, -2538, -2538, -2538,  1478, -2538,  1909,
    1753, -2538, -2538, -2538, -2538, -2538, -2538, -2538,  2162,  4373,
   -2538, -2538, -2538, -2538, -2538, -2538, -2538, -2538, -2538, -2538,
   -2538, -2538, -2538, -2538, -2538,  -161,  2348, -2538,   838,  1545,
   -2538,  2162, -2538, -2538, -2538, -2538, -2538, -2538, -2538, -2538,
   -2538, -2538, -2538, -2538,   464, -2538,  2145, -2538,  2516,   189,
   -2538,   189, -2538, -2538, -2538,  7687,   242,  3738, -2538, -2538,
   -2538,  1747, -2538, -2538, -2538,  2516,   212, -2538, -2538,  2335,
   -2538, -2538, -2538, -2538, -2538, -2538, -2538, -2538, -2538,  1986,
   -2538,  2332,  1989,  1990,  2338, -2538, -2538,  1994, -2538, -2538,
   -2538, -2538, -2538, -2538,   176,  2361, -2538, -2538,  2341,  2023,
   -2538,  1771,   522,  2063, -2538, -2538, -2538,   982, -2538, -2538,
   -2538, -2538,  5910,   785,   -29,  2024,   103, -2538,  7449, -2538,
    1830,  2350,   -29, -2538, -2538,   422, -2538, -2538, -2538, -2538,
     174,  2008,  1688,   838,   838, -2538, -2538, -2538,   148, -2538,
    2013,  1936,  1970, -2538,  2009, -2538, -2538, -2538, -2538,  2164,
     218, -2538,  1637,  1784,  1637, -2538,  1394,  7687,  1663,  1804,
    1840,  1967,  7687, -2538,  1838, -2538, -2538, -2538,  1441, -2538,
     460, -2538,    89,  1009,  1009, -2538, -2538,   464, -2538, -2538,
    1478, -2538,  1982, -2538,  2318,  1874,  7557, -2538,   462,    88,
    1478,  7588,   838, -2538, -2538,   327, -2538, -2538, -2538, -2538,
   -2538, -2538, -2538, -2538, -2538, -2538,   838,  2348, -2538, -2538,
   -2538,   838, -2538,   838, -2538, -2538,  1426, -2538,  2179, -2538,
    2182,  7687,   463, -2538, -2538, -2538,   465,  2590,  1962, -2538,
   -2538, -2538,  2368, -2538, -2538,  1968,  1797, -2538, -2538, -2538,
   -2538,  2034, -2538,   154, -2538,   154, -2538, -2538,  7687, -2538,
    1980, -2538,  2048,  1329,    64, -2538, -2538, -2538, -2538, -2538,
     103, -2538,  2037,  7923,  2000, -2538, -2538, -2538,  1817,   -29,
   -2538, -2538, -2538,    43,  1936, -2538, -2538,  2042, -2538,  2009,
     296, -2538, -2538,  1810,  1769,  1814, -2538,   469, -2538, -2538,
   -2538, -2538,  2516, -2538, -2538, -2538, -2538,  1874, -2538, -2538,
    7687, -2538,  7665,     1,  3260, -2538,  2409, -2538, -2538,  2516,
    1478,  2404, -2538,  7511, -2538, -2538, -2538,  2318,  1909, -2538,
   -2538, -2538, -2538,  2059,  2059, -2538,  2059, -2538,  2059,  2059,
   -2538, -2538, -2538,   205,   217, -2538, -2538,  7687,   242, -2538,
    2015, -2538,  1769, -2538, -2538,   476, -2538,  2413, -2538,  2516,
    7511, -2538, -2538, -2538, -2538,  2417, -2538,  -159, -2538, -2538,
    2048,   711, -2538, -2538,   124,   124,   124,   124,   124,   124,
   -2538,  2399, -2538,   478, -2538,  7449,  2408, -2538, -2538, -2538,
     573, -2538,  2009,  6776,  2009, -2538, -2538,  2213,  1769, -2538,
    1769, -2538,   129,   -29, -2538,     1,   205, -2538,   479, -2538,
    2516, -2538,   480,   947,  7588, -2538,  2021, -2538,  2237, -2538,
   -2538, -2538,  2059, -2538,  2059, -2538, -2538,  2061, -2538,  2516,
   -2538, -2538, -2538, -2538,   154, -2538,  7687,  2237,  1329, -2538,
   -2538, -2538, -2538, -2538, -2538, -2538,   650, -2538, -2538, -2538,
   -2538, -2538, -2538, -2538, -2538, -2538,  7923, -2538,  2430, -2538,
   -2538,   579, -2538, -2538, -2538, -2538, -2538, -2538, -2538, -2538,
     142, -2538, -2538, -2538,  7665, -2538, -2538, -2538,  7588, -2538,
   -2538, -2538, -2538, -2538, -2538,   656,   656, -2538, -2538,   656,
   -2538,  7449, -2538,  2069, -2538, -2538,   481, -2538, -2538, -2538,
    2071, -2538, -2538, -2538,   309, -2538,   148, -2538,  1936
};

/* YYPGOTO[NTERM-NUM].  */
static const short yypgoto[] =
{
   -2538, -2538, -2538, -2538, -2538,   284, -2538,   379,  -184, -2538,
   -2538,  -841,    44, -2538, -2538, -1524, -2538, -2538, -2538, -2538,
    -582, -2538, -2538, -2538, -2538, -2538, -2538, -2538, -2538, -2538,
   -2538, -2538, -2538, -2538, -2538, -2538, -1858, -2538, -1382, -2538,
     374, -2538, -2538, -2538, -2538, -2538, -2538, -2538,   608, -2538,
   -2538, -2538, -2538,  1217, -2538,   901, -2538, -2538,   -60, -2538,
   -2538,  2415, -2538,  2414,  2090, -2538, -2538, -2538, -2538, -2538,
     674,   324, -2538,   669, -2538, -2538, -2538, -2538, -2538, -2538,
   -2538, -2538, -2538, -2538, -2538,  -127,   887,   808, -2538, -2538,
    2174,   -24, -2538,  2321, -2538, -2538,  2320, -2538,  2257, -2538,
   -2538, -2538,  2186,  2073,  1144,  2185,  -310, -2538, -2538, -2538,
   -2538, -2538,  1145,  -970, -2538, -2538, -2538, -2538, -2538, -2538,
    -125,  2117,  2265,  -203,   730, -2538,  2109,    40, -2538,  2165,
   -2538, -2538, -2538, -2538,  2169, -2538, -2538, -2538, -2538,  -322,
   -2538, -2538, -2538, -2538, -2538, -2538, -2538, -2538,  2102, -2538,
    2101, -2538, -2538, -2538, -2538, -2538, -2538, -2538, -2538,  -868,
   -2538, -2538,  -529, -2538, -2538, -2538, -2538, -2538, -2538, -2538,
    2114, -2538, -2538,   968, -2538,  -879,  -804,  1522, -2538, -2538,
   -2538, -2538, -2538, -2538, -2538, -2538, -2538,   731, -2538, -2538,
   -2538, -2538, -2538, -2538, -2538,  -469, -2538, -2538, -2538, -2538,
   -2538,  1969, -2538, -2538, -2538, -2538, -2538, -2538, -2538, -2538,
   -1688, -2538, -2538, -2538, -2538, -2538, -2538,  1094, -2538, -2538,
   -2538, -2538, -2538, -2538, -2538, -2538, -2538, -2538, -2538, -2538,
   -2538, -2538, -2538, -2538,  1541, -2538, -2538, -2538, -2538,   862,
   -2538, -2538, -2538, -2538, -2538, -1372, -2538, -2538,   854, -2538,
   -2538, -2538, -2538, -2538, -2538,  -806,  -624,   734,  1014, -2538,
    -467,   512,  -815,   773, -2538,   750, -2538, -1795,    -2,  -351,
   -2538, -2538,   687,  1504, -1720,  -731,  1166, -2538, -2538, -2538,
     427,  1254, -2538, -2538, -2538, -2538, -2538, -2538,   302, -2538,
     -23, -2538,  1252, -2538,   940, -2538,   630, -2538, -2538, -2538,
    -526, -2538, -2538, -2538, -2538, -2538, -2538, -2538, -2538,   749,
   -2538, -1196, -2538,   938, -2538, -2538, -2538, -2538, -2538, -2538,
   -2538, -2538, -2538, -2538,   306, -2538,   308, -2538, -2538, -2538,
   -2538,  1380, -2538, -2538, -2538, -2538, -2538, -2538,  -183, -1467,
   -2538, -2538, -2538, -2538,   279, -2538, -1591, -2538,  -831, -2538,
   -2538, -2538, -2538, -2538, -2538, -2538, -2538, -2538, -2538, -2538,
   -2538, -2538, -2538, -2538,  2508, -2538, -2538, -2538,  2421,  2503,
   -1511, -2538, -2538, -2538, -2538, -2538, -2538, -2538,   -64, -2538,
   -2538, -2538, -2538, -2538, -2538, -2538, -2538,  2514, -2538, -2538,
   -2538, -2538, -2538, -2538, -2538, -2538, -2538, -2538,   990, -2538,
   -2538, -2538, -2538, -2538, -2538, -2538, -2538, -2538, -2538,  -409,
    2067, -2538, -2538, -2538, -2538, -2538,  1901, -2538, -2538, -2538,
   -2538, -2538, -2538, -2538, -2538, -2538,  1806, -2538, -2538,   -59,
   -2538, -2538,   991, -2538, -2538,  1310,  -192,  2288, -2538, -2538,
   -2538, -2538,   537, -2538,  -705,  1878,  1295, -2272,  -155, -2538,
     998,  1636,   -45,  -222, -2538,  -957, -2538,  1427, -2538, -2538,
   -2538, -2538, -2538, -2538, -2538, -2538, -2538, -2538, -2538, -2538,
   -2538, -2538, -2538, -2538, -2538, -2538, -2538, -2538,  1388, -2538,
     962, -2538,  -344, -2538, -2538, -2538, -2538, -2538, -2538,  -384,
   -2538, -2538, -2538, -2538, -2538, -2538,   388, -2538,  1450,   311,
   -2538, -2538, -2538, -2538,   220, -2538,  -216, -2538, -2538, -2538,
   -2538, -2538, -2538, -2538, -2538, -2538, -2538, -2538, -2538, -2538,
   -2538, -2538,  1705, -2538, -2538, -2538, -2538, -2538, -2538, -2538,
    -326, -2538,  1381,  1540, -2538, -2538,   232, -2538,  -432, -2538,
   -2538,   251,   592, -2538, -2538, -2538, -2538, -2538, -2538, -2538,
    -335, -2538, -2538, -2538, -2538, -2538, -2538, -2538, -2538, -2538,
   -2538, -2538, -2538, -2538, -2538, -2538, -2538, -2538, -2538, -2538,
   -2538, -2538, -2538, -2538, -2538, -2452, -2538,  1586,   829,  -972,
   -2538, -2538, -2538, -2538,  1233, -2538, -1306, -2538, -2538, -2538,
   -1307, -2538, -2538, -1293, -2538, -2538, -2538, -2538,  1261, -2538,
   -2538, -2538, -2538, -2538, -2538, -2538, -2538, -2538, -2538, -2538,
   -2339,  -168, -2538, -2537, -2479, -2538,   661, -2538, -2538, -2538,
   -2538, -2538, -2538,  -439, -2538, -2538, -2538, -2538, -2538, -2538,
   -2538, -2538, -2538, -2538, -2538, -2538, -2538,  -402, -2538, -2538,
   -2538, -2538, -2538, -2538, -2538, -2538, -2538, -2538, -2538, -2538,
   -2538,   634, -2538, -2538, -2538,  -286, -2538, -2538, -2538, -2538,
   -2538, -2538,   219, -2538, -2538,   605, -2538,   946, -2538, -2538,
   -2538, -2538,   199,  -967, -2538, -2538, -2538, -2538, -1377, -2538,
   -2538, -2538, -2538, -2538, -2538, -1994,   -57, -2538, -2416,   190,
   -2538, -2538, -1635,   245,   246,   604, -2538, -2538, -2538, -2538,
   -2538, -2538, -2538, -2538, -2538,    -7,  -288, -2538, -2538,   607,
   -2538, -1898, -2538, -2538, -2538, -1456, -2538, -2538,  -889, -2538,
    -698,  1361,  -187, -1607, -2538, -2007, -2538, -2538, -2538, -2538,
    1902,   216, -1642, -2157, -2538, -2538, -2538, -2538, -2538, -2538,
   -2538, -2119, -2538,   328, -2538, -1580, -2538,  1685, -2538, -2538,
    -865,  -197, -2538, -2498,  -191,  -103,   406, -1928, -1367, -1698,
     405,  -349,  1151, -2538,   -79,  -259, -2538, -2538,  1391,  -500,
   -2538, -2538,  -208,  1720, -2538,   716, -2538, -2538, -1223,   106,
   -2538, -2538, -2538, -2538, -2538,  -431,  -405,  -452,   970, -2385,
      22,  1305,    53, -2538, -2538, -2538, -2538, -2538,  1529, -2538,
    -499, -2538, -2538, -2538, -2538, -2538, -2538, -2538, -2538,  -658,
    1577,  2313, -2538, -2538, -2538, -2538
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1790
static const short yytable[] =
{
      40,   268,  1022,   258,   112,  1019,   386,  1172,  1331,   284,
      55,    57,  1163,   712,  1789,  1190,   861,   692,  1341,  1159,
    1363,   873,    32,   131,  1004,  2074,   236,  1723,  1169,  1170,
     815,  1171,  2046,  1174,  1175,  2037,    97,   416,   824,  2077,
    1258,    74,    77,   915,   858,    32,   918,  2415,   864,  2165,
     256,    68,  1693,  1376,  1268,  1668,  1694,   112,  2031,  2033,
    1203,  1195,  2033,  1574,  1575,  2131,  1763,   681,  1615,  1929,
     797,   140,  1476,   822,   128,  1195,  1214,    77,   665,  1499,
     338,  1122,  1488,  2368,   871,  2372,   126,   790,   871,   137,
     269,   921,   922,   700,  2248,   930,   144,   184,   185,   692,
     291,   773,   150,   151,   773,   186,   909,  1263,   154,   155,
     299,   300,  2551,  1139,   782,  1942,  2225,    97,   773,  1820,
     181,   201,   773,   687,  1489,  1196,  1490,   871,  1491,   799,
    1189,  1197,   129,    81,   773,  1278,   782,  1280,   269,   126,
     708,   269,   810,  1116,   269,   782,  2175,   232,   394,  1164,
     235,  1823,   821,  -610,  1386,   239,   275,   825,  1235,  1274,
    1832,   269,   276,   277,   826,   863,   379,  2119,  1195,  1453,
   -1788,   269,   921,   922,  1730,   269,   810,  2177,  1017,  1195,
     810,  1731,   865,  2203,   810,   269,   270,   271,  2164,   782,
    -610,  1414,   782,   266,   273,   865,  2619,  -610,     1,  2500,
    1017,  -610,   266,   292,  1949,   266,  1855,  1856,   102,  1984,
    2248,   266,   269,  1858,  1859,  2695,  2892,  2812,  1259,  2180,
    1017,  1181,  1182,   266,   931,  1127,  1128,  1488,  1946,  2568,
    2767,   381,   296,  1017,  1855,  1856,  1006,  1284,   302,  2347,
     269,  1858,  1859,   389,  2805,  2633,  2805, -1788,  2660,   330,
    2374,   812,  2476,   103,   104,  1520,   344,  1551,   346,  1855,
    1856,   105,  1551,    97,  1545,   269,  2414,  1859,   398,    72,
       3,     4,  1992,     5,     6,  1995,   400, -1788,     7,  2377,
    1149,  2378,  2379,  2380,  2381,  2382,  2383,  2519,  2520,  2521,
    2522,    81,  2896,  -610,  2764,     8,     9,   404, -1788,  1014,
    1329,  2393,  1195,   931,   556,   644,  2374,  1839,  2219,  1286,
    1263,  2680,   392,    10,    11,  2242,  1146,  1579, -1788,  1727,
    1789,   259,   260,   261,   262,   263,  1195,  1855,  1856,   392,
    1857,  2009,  2898,   269,  1858,  1859,  2464,    56,  1500,  2009,
    2239,   383,  2404,  2034,  1501,  1502,  1503,  2982,  1012,  2883,
    2484,    63,  2731,  1860,   408,   931,  2783,   408,  3009,  1152,
    2189,   653,  1526,  2236,  1504,   408,  2118,  2301,     3,     4,
    1017,     5,     6,   932,   985,   986,     7,  2370,   931,  2374,
    2933,   330,  2634,   330,  2635,  2981,   636,   646,  1007,  1227,
    1363,  2057,  1803,     8,     9,   654,  1454,  1013,  1454,   141,
    2557,  2031,   987,   988,   989,  2784,  2059,  3010,  2561,  2226,
     408,    10,    11,  2398,    69,   680,  2398,   683,   933,  1187,
     689,   694,  2423,   696,    34,  2442,   699,  1250,  2732,  1954,
     923,  1153,  1383,  2053,  1264,  2755,  2442,   705,   813,   259,
     260,   261,   262,   263,   767,  2423,  2899,  2482,  1552,  2555,
    3075,  1583,  2577,  1552,  2396,  2664,   705,  1495,  2742,  2760,
    2630,  2975,  2632, -1561,  2644,  2875,   767,  2890,  2914,   705,
    2914,  1188,  1505,    33,  2742,  1506,   863,  3042,  1147,   800,
     718,  3004,    12,  3026,  3044,  2984,  2984,  2318,  3012,   187,
    1635,  1600,  1601,  2351,  2681,   816,   818,  2997,  2465,  1507,
    2897,  2384,   689,  1231,  2682,  3047,  1521,  1295,    82, -1788,
     767,  3066,   816,   816,  1934,   106, -1788,  1728,   934,  1508,
     767,   767,  2477,   893,   767,  1955,    77,    79,   767,  2805,
     767,   380,  1292,   924,   767,   767,  1393,   910,  2405,   910,
     816,   107,   910,   816,   814,   910,  1548,  1209, -1788,  1212,
     814,  2985,  2636,  1368,  1509,   259,   260,   261,   262,   263,
    3043,  1387,  2696,  1861,  1518,  1390,  1391,  1392,  2237,    72,
    2511,  1002,  2498,  1510,  1511,  2512,  1846,  1370,  1862,  1760,
    1950,   899,  1762,  2011,  1410,  2823,  1609,  1610,  1198,  1512,
     933,  1861,  2893,   267,  2136,  1620,   382,   934,   384,   863,
     825,   863,   341,   692,  1165,   667,  1862,  1279,   390,  1251,
    1943,  1702,   108,  2309,  2375,  2108,  1861,  2813,  2569,  2348,
    2385,  2566,  2804,  2862,  2804,  2054,  1805,   791,  1513,  2809,
    1457,  1862,  3076,   399,  2878,  2879,  2560, -1788,  1660,  2369,
     939,   401,  1471,  1140,  1472,   959,   973,  1326,  2674,   934,
   -1788,    82,  2552,  2553,    82,    82,   402,  1166,    82,    82,
    1327,  1514,   405,  2204,  1015,  1330,   272,  1722,  1215,  1371,
    2402,    82,   934,   980,  1492,   408,  1199,  1849,   935,   936,
     937,   815,  1493,    15,  1861,    82,   689,    82,    76,   938,
     688,  1827,  1888,  1888,    82,  1452,  2010,  1201,  1477,  1862,
      82,  1018,  2546,  2701,  2026,   109,  2727,  2969,  2035,  1779,
    1372,   767,   767,  2811,   272,    82,  1863,   272,    82,  2012,
     272,   692,  1458,  1537,  1732,    82,    82,   767,  1523,  1985,
    2429,  2013,  1865,   767,   767,  2247,    82,   272,   767,    82,
    2069,  2400,  2703,  2625,  1376,  2686,  2708,   272,   767,    82,
    2418,   272,   132,  2419,  1536,    82,  2058,  1570,  1571,  1539,
    2369,   272,    82,    82,  1129,  3003,    82,  2487,  2038,   777,
    1556,  2060,   990,  1867,  2227,  2495,  2135,  1018,  2399,   139,
     688,  2401,   786,  1531,  2834,  1868,   110,  2424,   272,  2648,
    2443,  2650,  1602,  2069,   111, -1788, -1788, -1788, -1788, -1788,
    1132,  2444,  1616,   728,    95,  2386,  1971,  1133,   688,  1252,
    2447,  3038,  2483,  3039,  2556,  1369,   272,  2578,   139,  2623,
    2665,   767,   767,  2743,  2761,    61,  1869,  2848,   732,  2924,
    2876,  2926,  2891,  2915,  3032,  2916,   882,   303,  2888,  2971,
   -1788,   272,  1253,  2888,  1622,   130,  3005,  1579,  3027,  3045,
    3046,  3072,  2752, -1788,  1332,  2039,   767,  1334,    82,   991,
    2514,   647,   767,  2550,   304,  1870,  2858,  3057,  1346,  2733,
    1346,  1703,  2040, -1788,   767,   883,  1335,  1871,  2081,   767,
    2082,  1347,  1346,  1347,   648,  1225,  1178,    17,   136,  1872,
    1873,  2014,    61,  1185,   948,  1347,   413,  1335,  1874,  1118,
    1264,   688,   992,  1242,   651,   949,  -610,  2804,   337,   272,
      17,  2809,   741,  1953,   141,  2041,  1713,   767,  1623,  1617,
    2688,  1900,  2689,   647,  1579,   884,   133,   134,  2459,  1624,
   -1788,   767,  1901,  2377,   143,  2378,  2379,  2380,  2381,  2382,
    2383,  2191,  2192,  2193,  2194,   961,   648,   145,  2756,   678,
    1904,  1625,  2663,  2874,  2042,  2667,  2888,   950,  1626,    42,
     193,  1905,  1475,   885,  2191,  2192,  2193,  2194,   914,   194,
    2773,   917,   951,   195,   920,  1759,  3013,  2515,  1761,  2144,
    3014,  1583, -1788,  2043,  1343,  1579, -1788, -1788,  1351,  1360,
    1351, -1788,  2044,   198,  1804,  2195,  2196,  2197,  2198,  2199,
    2200,  2965,   233,   689,   746,  2836,   689,  2837,  1375,  1378,
    3052,   234,   696, -1788, -1788,  1336,   748,   749,  2195,  2196,
    2197,  2198,  2199,  2200,  1996,   751,   816,   767,  1618, -1788,
     816,   816,   816,   816,   241,   767,  1336,  3013,   767,   898,
    1831,  3014,  2366,   902,   249,  1399,   250,   906,  2209,   816,
    1400,   767,  1402,  1348,   252,   767,  2888,   253,  1583,   257,
     886,   254,   952,   767, -1788,   767,   767,  1362,   767,   767,
     767,   767,   767,   767,   767,   767,   767,   767,   767,   767,
     767,   767,   767,   767,   767,   265,  2516,  1363,   285,  2417,
    2863,  1337,  2865,  1911,   286,   767,   767,  1932,  1643,  1349,
     767,  1349,   767,  2913,  3034,   682,  3036,   682,   682,  1891,
    1893,  2723,  1337,  1349,  1623,  1350,   289,  1350,   288,  1583,
    2888,   682,  1179,  1180,   689,  1624,  1183,  1184,   726,  1350,
     767,   767,   767,   290,  2241,  1794,   887,    43,   294,   682,
     727,   816,   682,  1474,   295,  1478,   816,  1625,   682,  1338,
     767,    44,   682,  2881,  1626,  2384,   682,  1608,  2299,  2408,
     682,  2410,  2411,  1612,   682,   682,   297,   682,    33,    34,
     682,   775,   682,   682,   682, -1788,    45,   888, -1788, -1788,
     682,  1643,  2976,   682,   301,   784, -1788,   767,  1229,   789,
     682,  2425,   306,   816,   686,   682,   315,  1651,  1023,  1024,
    1025,   803,  1819,   682,  2065,   324,  1657,   704,   133,   134,
     325,  1339,   767,   331,   682,   133,   134,  1534,   682,   816,
     816,   334,   682,   335,   816,    46,  2938,   682,  1543,   767,
     682,   336,  1339,   340,   778,  2229,   342,   805,  1576,   767,
     343,  1577,  1644,  1578,  2070,   889,   811,   954,   955,   825,
     795,   796,   347,   910,   816,   816,   802,  2801,  2988,   804,
     348,  1645,  1646,  1579,  1397,  1398,  2109,   351,  2110,   352,
     863,  1560,   134,  1580,  2385,  1630,  1631,  2121,  2302,  1604,
     354,  1647,  1018,  1018,   743,  1638,  1639,  1613,   353,  1613,
     913,  1018,  1908,   916,  2510,  3007,   357, -1788,  1795,  1796,
   -1788,   358, -1788,  2294, -1788,   973,   369,  1700,   890,    48,
      49,    50,    51,    52,    53,  1581,    54,  2510,   368,  1582,
    1782,   372, -1788,  1576,  1783,  1644,  1577,   377,  1578,   388,
   -1788,  2388, -1788,   387,  1018,  1080,  1081,  1082,  1083,  1084,
    1085,  1086,   935,   936,  1645,  1646,  1351,   391,  1579, -1788,
   -1788, -1788,   745,  1017,  2934,   395,   396,  1360,  1580,   397,
    1351,   747,   274,   403,  1647,   406,   279,  -951,   414, -1788,
    2507,   652,   657,   659, -1788,   660,   668,   661, -1788,  1709,
    1710,  1711,   666,    82,  2545,  2174,  2958,   767,   670,   671,
    2880,  1087,  1088,  1089,  1090,  1091,  1092,  1583,   672,  2085,
    1581,  2938,   674,     1,  1582,   675,   676,  1093,  1094,  1095,
    2088,  2191,  2192,  2193,  2194,  2091,   767,   767,   767,  2095,
     767,  2097,  2098,  2099,   677,   679, -1302,  1784,     2,    82,
    1785,   814,  2377,   963,  2378,  2379,  2380,  2381,  2382,  2383,
    2191,  2192,  2193,  2194,   964,   965,   767,   966,  1764,  1584,
    2417,  2671,  1579,   967,   968,   969, -1788,   970,   971,  2386,
     972,   976,   767,   977,   978,  2195,  2196,  2197,  2198,  2199,
    2200,   979,   983,  1005,  3018,     3,     4,   687,     5,     6,
    1792,  1007,  1583,     7,  1008,  1010,   767,  1011,  1799,  1800,
     767,   816,  1016,  2958,  2195,  2196,  2197,  2198,  2199,  2200,
       8,     9,  1017,  1020,  1399,  2389,  1028,  1029, -1788,  1400,
    1401,  1402,  1031,  1032,   682,  1033,  2193,  2194,    10,    11,
     767,  1204,  1205,  1206,  1207,   767,  2390,  -265,  1119,  1034,
    2083,   767,   307,  1035,  1584,  1036,  1829,  1782,  2789, -1788,
     767,  1783,  1037, -1788,  1038,  1039,   767,  1040,  1096,  3018,
    1130,  1097,     3,     4,   767,     5,     6,  1051,  1052,  1053,
       7,  1242,  1056,  1875,  2420,  2132,  1057, -1788,  2195,  2196,
    2197,  2198,  2199,  2200,   816,   816,  1060,     8,     9,  1062,
       1,  3035,  1063,  1064,  1065,  2788,  1583,  1126,  1131,    12,
     816,  1134,   825,  1066,  1137,    10,    11,  1135,   863,  1067,
    1068,  1070,  1138,   316,  2790,  1143,  2791,  1142,  2448,  1018,
     709,   709,  1148,  1281,  -265,  1145,  1157,  1875,  1162,   308,
    2782,  2792,   863,   259,   260,   261,   262,   263,  1979,  2793,
    1186,  -265,  1585,  2794,  1176,  1189,   309,   682,   682,   682,
    1210,  1991,  1991,  2717,  1784,  1991, -1788,  1785,  1218, -1788,
    1219,  2716,     3,     4,  2384,     5,     6,  2789,  2795,  1220,
       7,  1875,  1221,  2027,  2027,  1222,    12,  2027,  1875,  1579,
    1098, -1788,  1223,  1226,  -265,  1230,  1228,     8,     9,   310,
    2191,  2192,  2193,  2194,  1231,  1099,  1239,  1241,  1254,  1100,
     317, -1788,  1255,  1195,  2061,    10,    11,  1262,  1266,  1375,
    1256,  1269,  1257,   767,   709,  1270,  1271,   318,  1317,    13,
    1351,  1272,  1325,  -265,   925,  1342,  1282,  1585,   311,  1328,
    1345,  1875,  1359,  2790,  1283,  2791,  1365,  1101,  1366,  1374,
    1284,  2678,  1285,  1381,  2195,  2196,  2197,  2198,  2199,  2200,
    2792,  1382,  -265,  1286,  2537,  1383,  2539,   312,  2793,  1384,
     319,  -265,  2794,  1385,  1394,  1102,   313,   767,    14,   767,
    1409,  2194,  1411,  1351,  2866,  1416,  1450,   767,   767,   767,
     767,  1287,  2027,  2385,  1103,  1408,  1444,  2795,  2123,  1792,
    1447,  1042,  2128,  2128,  2721,  1451,  1470,  1288,  1464,   320,
      15,   767,  1289,  1201,  1484,  1486,  1497,  2530,  1482,  1498,
    1522,  2140,  1524,  1583,  1290, -1788,  1527,  1525,  1529,  1535,
    1540,  1291,  2195,  2196,  2197,  2198,  2199,  2200,   321,  1538,
    1548,  2191,  2192,  2193,  2194,  1563,  1555,   322,  1565,  1557,
    2388,  1264,  1736,  2195,  2196,  2197,  2198,  2199,  2200,  1592,
    1488,  1594,  1595,  1597,  1652,  1696,  1603,  1663,   767,  1665,
    2172,  1666,  1669,  2839,  1670,  1104,  1698,  2191,  2192,  2193,
    2194,  2847,  1875,  1855,  1856,    89,  1857,    15,  1043,   269,
    1858,  1859,  1701,   925,  1705,  2195,  2196,  2197,  2198,  2199,
    2200,   825,   825,  1704,  1714,  1044,    13,  1719,  2210,  1860,
    1720,  2591,  2592,  2593,  1721,  2595,  2596,  2597,  2598,  2599,
    2600,  1724,  1726,  1733,  2603,  1735,  1744,  1745,  1747,  1750,
    1769,  2195,  2196,  2197,  2198,  2199,  2200,  1768,  1766,  1737,
    1117,  2670,  1105,  1770,  1771,  1774,  1775,  1772,  1045,  1776,
    1777,  1018,  1562,  1778,  1780,    14,  1738,  1781,   644,   182,
     190,  1263,  1806,  1793,   644,  2027,  1814,  1808,  1875,  2697,
    1809,  1810,  1817, -1788,  1824,  2245,  1613,  1825,  2386,  1826,
    1830,  1833,   767,  1836,   767,  1842,  1292,  1046,   753,  1854,
    1888,  2710,  2027,  1293,  1018,  1850,  2678,  1852,  2712,  1739,
     938,  1890,  2038,  1991,  2191,  2192,  2193,  2194,  1930,  1931,
     783,  1933,  1941,   190,  1292,  1294,  1047,  1947,  1957,   190,
    1295,  1958,  1974,  1977,  2389,  1048,  2027,  1976,  2957,  1978,
    1875,  1988,  1875,  2854,  1999,  2001,  2008,  2000,  1740,  2005,
     646,  2062,  2047,  2048,  2049,  2390,   646,  2050,  2051,  2052,
    2064,  2067,  1351,  2868,   855,  2073,  2078,  2079,  2195,  2196,
    2197,  2198,  2199,  2200,   874,   880,  2086,  1741,   897,  2080,
    1912,  2087,   901,  2090,   903,  1360,  1742,  1351,   907,   908,
    2102,  2104,  2106,  2117,  2139,  1709,  2150,  2122,   767,  2039,
     190,   767,   190,  2137,  2147,  2151,  2152,  2987,  2154,  2153,
    2155,  2170,  2171, -1788,  2190,  2202,  2040,   937,  2182,   925,
    2208,  2183,  2211,  1748,  1071,  1072,  1073,  1074,  1075,  1076,
    1077,  1078,  1079,  1080,  1081,  1082,  1083,  1084,  1085,  1086,
    2185,  2213,   767,  2186,  2651,   767,  2187,  2188,  2220,  2228,
    2457,  2222,  2232,  2233,  2240,  2678,  2243,  2678,  2248,  2041,
    2295,  2306,  3041,  1792,  2304,  2472,  2307,  2474,  3019,  3020,
    3021,  3022,  3023,  3024,   767,  1963,   190,   767,  2312,  2305,
    2395,  2491,  2376,  2396,  1964,   767,  2367,  2406,  2403,  1087,
    1088,  1089,  1090,  1091,  1092,  2409,  2412,  2421,  2042, -1734,
    2426, -1788,   767,   682,  2869,  1093,  1094,  1095,  1965,  2427,
    2027,  1966,  2433,  2432,  2435,  2434,  2436,  1875,  1875,  1875,
    1875,  1875,  1875,  2438,  2439,  2446,  2841,  2043,  2440,  1967,
     689,  2652,  2437,  2441,  2352,  2449,  2044,  2445,  2452,   816,
    2870,   816,  2451,  2456,  2458,  2462,  2466,  2470,  2653,  2471,
    1861,  2353,  2354,  2473, -1788,  2486,  2838,  2494,  2505,  2355,
    2518,  2509,  2533,  2536,  2503,  1862,   702, -1788,  2547, -1788,
    2548,  2027,  2557,  2374,  2566,  2564,  1875,  2575,  2579, -1788,
    2589,  2594,  1863,  2590, -1788,  2637,  2601,  2602,  2608,  2609,
    2612,  2654, -1788,  2356,  2613,  2369, -1788,  2781,  1865,  2614,
     780,  2615,  2357,  2616,  2617,  2618,   785, -1788,   787,  2629,
    2705,  2631,   794,  2646,  1913,   794,  2659,   682,   794,  1336,
    2661, -1788,  2649,  2027,  2666,  2672,  2668,  1914,   806,  2687,
    2655,  2358,  2580,  2581,  1979,  1968,  2678,  1950,   682,  1867,
    2584,  2690,  2693,  2730,  2698,  2699,  1096,   853,  2700,  1097,
    2706,  1868,  2701,  2714,  2715,   866,   869,   872,   925,  2656,
    2713,   894,  2718,  2722,  2734,  2725,  2735,  2871,  2657,   904,
    2942,   932, -1788,  2748,  2758,   855,  2359,  2766,  2770,  2771,
    2774,  2779,  2778,  2786,   927,  2814,  2816,  2817,  1969,  2819,
    2820,  1915,  1869,  2821,  2822,  1970,  2825,  -610,  1916,  2833,
    2828,  3078,  1875,  2835,  1875,  2846,  2840,  2844,  2850,  2856,
    1194,   709,  2918,  2855, -1788,  1875,   855,   139,  2360,  2864,
    1875,  2882,  2873,  2920,  2027,  2638,  2027,  2911,   874,  2429,
    2912,  1870,  2922,  1217,  2923,  2393,  2930,  1917,  2943,  2955,
    2639,  2640,  2964,  1871,  2984,  2968,  2956,  2986,  3006,  2970,
    3002,  1351,  3008,  3025,     1,  1872,  1873,  1018,  3029,   925,
    3048,  3051,  1918,  3037,  1874,  3061,  2490,   688,  1098,  3071,
     767,  3073,  1919,  1920,  3060,   272,  2422,  2428,  2162,  1547,
    1841,    70,    71,  1099,   557,  2124,  2133,  1100,  1921,  2469,
    2128,   349,   197,  2707,  2128,   202,   281,   345,   816,   669,
     407,   767,  1654,   350,  1655,   816,   283,  2691,  2089,  1922,
     656,   376,  1923,  1924,   374,   662,   663,  3058,  1925,   385,
    1816,   767,  2103,  1729,   892,  1101,     3,     4,  1321,     5,
       6,   767,  1997,  1989,     7,  2113,  1801,  1367,  2535,  1569,
    1573,  2747,  1887,   927,  3064,  1875,  2207,  1875,  1875,  1875,
    1875,     8,     9,  1102,  2120,  1909,  2541,  2849,  1479,   767,
    2543,    65,    66,  2191,  2192,  2193,  2194,  1323,   156,    10,
      11,   863,  1103,    67,  1848,  1926,  2749,  2799,  1875,   801,
     962,  1851,  1561,  2027,   339,   982,  2184,  1927,  1591,  2852,
    1260,  1853,  2245,  2787,  2902,  1944,  1466,  2027,  1087,  1088,
    1089,  1090,  1091,  1092,  1517,  2027,  3033,  1604,  2525,  1456,
    2910,  1213,  1120,  2622,  1093,  1094,  1095,  2195,  2196,  2197,
    2198,  2199,  2200,  2621,  2107,  1530,  2604,  2917,  1697,  2364,
    1380,  1417,  2895,  1664,  2234,  3065,  3054,  2191,  2192,  2193,
    2194,  2303,  2989,  2365,  2647,  2036,  2669,  2824,  2373,  2626,
    2679,  2230,  2627,  1104,  2806,  1151,  2998,   689,  2921,   689,
     682,  2387,  1050,  1875,  2582,  1875,   682,  2939,  1310,  1168,
    1168,  1168,  1607,  1168,  2940,  1168,  1168,  2815,  2685,  2877,
    2563,    89,    89,  2565,  1459,  1460,  1461,  3053,  2867,  3001,
     682,  2195,  2196,  2197,  2198,  2199,  2200,  2974,  1599,  1277,
    2763,  2063,  1018,  1473,  1483,   415,  2826,     0,  2831,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1105,   816,     0,     0,     0,   872,   767,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1237,     0,     0,     0,
       0,  1519,     0,     0,     0,     0,  1881,  2397,     0,     0,
       0,     0,     0,   158,     0,  1096,     0,     0,  1097,   927,
    1120,  1876,     0,     0,     0,  1875,   874,     0,  1267,     0,
    1875,  1077,  1078,  1079,  1080,  1081,  1082,  1083,  1084,  1085,
    1086,     0,     0,  1544,  1275,  1275,     0,     0,  2027,     0,
       0,     0,   159,  1559,  1875,     0,     0,     0,  2027,  1875,
    1961,     0,     0,     0,     0,     0,  2901,     0,     0,     0,
       0,   160,     0,     0,     0,  1876,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1671,     0,  1875,
    1087,  1088,  1089,  1090,  1091,  1092,     0,     0,     0,     0,
       0,     0,     0,   190,     0,     0,  1093,  1094,  1095,     0,
     161,  1018,     0,  1018,     0,     0,  1875,  1026,  1027,  1876,
       0,  2027,   162,  2831,     0,     0,  1876,     0,     0,     0,
       0,     0,   163,  1041,     0,     0,     0,  1098,     0,  1054,
    1055,     0,     0,     0,  1059,     0,     0,     0,     0,     0,
     164,     0,  1099,     0,  1069,     0,  1100,     0,     0,     0,
     165,     0,     0,  2749,  1961,     0,     0,     0,  1875,     0,
    1875,     0,  1875,     0,     0,     0,   166,     0,  2027,  1876,
       0,  1875,  1633,  1634,     0,     0,  1604,     0,     0,  1650,
       0,     0,     0,     0,  1101,     0,     0,     0,     0,     0,
       0,     0,   689,     0,     0,  1875,     0,     0,     0,   682,
     682,     0,     0,     0,     0,  1449,   167,     0,  1875,     0,
       0,     0,  1102,    89,     0,    89,   872,   794,     0,     0,
       0,     0,     0,     0,  1465,   806,     0,     0,   872,     0,
     168,  1103,   190,   767,  3030,  1480,     0,  1096,     0,     0,
    1097,   767,     0,     0,     0,   169,     0,     0,   927,     0,
       0,     0,   170,     0,     0,   171,     0,     0,     0,     0,
       0,     0,  1875,     0,     0,     0,  1773,     0,     0,     0,
       0,     0,     0,     0,    89,   172,     0,     0,   173,     0,
     174,     0,  1018,     0,  1875,     0,  2027,     0,     0,     0,
    1798,     0,     0,     0,  1461,  2181,     0,     0,     0,   175,
       0,  2176,  2178,     0,     0,     0,     0,     0,     0,     0,
    1876,     0,  1104,  1672,  1541,     0,     0,   176,     0,     0,
       0,     0,  1875,     0,  1194,     0,  1875,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  2624,  1567,     0,   767,
       0,     0,     0,     0,     0,     0,     0,     0,  1590,   927,
    1838,     0,     0,     0,     0,     0,     0,     0,     0,  1098,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1673,     0,     0,  1099,     0,     0,     0,  1100,  1105,
       0,     0,     0,  1674,     0,     0,     0,     0,     0,  1822,
       0,     0,     0,  1675,     0,     0,  1876,     0,     0,     0,
       0,     0,     0,  1637,     0,     0,     0,     0,     0,     0,
       0,  1676,     0,     0,     0,     0,  1101,     0,     0,     0,
       0,  1677,     0,  1388,  1678,  1885,     0,     0,     0,     0,
       0,  1396,     0,     0,  1407,     0,     0,  1679,     0,     0,
       0,     0,     0,  2371,  1102,     0,     0,  1412,     0,     0,
       0,  1415,     0,     0,     0,     0,     0,   872,  1876,  1421,
    1876,  1423,  1424,  1103,  1425,  1426,  1427,  1428,  1429,  1430,
    1431,  1432,  1433,  1434,  1435,  1436,  1437,  1438,  1439,  1440,
    1441,     0,     0,     0,     0,  2737,  1680,     0,     0,     0,
       0,  1442,  1443,     0,     0,     0,  1445,     0,  1446,     0,
    1876,     0,     0,     0,     0,     0,     0,  2066,     0,     0,
       0,     0,     0,     0,     0,     0,  1681,     0,     0,     0,
       0,     0,     0,     0,  2757,     0,  1682,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1104,     0,  1683,     0,     0,  1684,
       0,  1685,     0,     0,     0,     0,     0,  1855,  1856,     0,
    1857,     0,     0,   269,  1858,  1859,     0,     0,     0,     0,
       0,  2111,  2112,  1461,  2115,     0,     0,     0,     0,  1686,
       0,     0,     0,  1860,     0,     0,     0,     0,  1687,     0,
       0,     0,     0,     0,     0,  2138,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1813,     0,     0,     0,
       0,  1105,     0,     0,     0,  1821,     0,     0,     0,     0,
    2523,  1881,  2526,  2527,  2528,  2529,   872,     0,     0,     0,
       0,     0,     0,     0,     0,  1876,  1876,  1876,  1876,  1876,
    1876,     0,     0,     0,     0,     0,   182,     0,     0,     0,
       0,     0,  2169,     0,     0,     0,  2146,  1071,  1072,  1073,
    1074,  1075,  1076,  1077,  1078,  1079,  1080,  1081,  1082,  1083,
    1084,  1085,  1086,     0,     0,     0,     0,     0,     0,  1961,
       0,     0,     0,   872,     0,   872,     0,     0,     0,   866,
       0,  2158,  2159,     0,  1876,     0,     0,     0,     0,     0,
       0,     0,  2168,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1983,  1087,  1088,  1089,  1090,  1091,  1092,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1093,  1094,
    1095,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  2215,  2216,  2217,  2218,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  2296,  2224,  2297,   709,
     709,   709,     0,   709,   709,   709,   709,   709,   709,     0,
       0,     0,   709,  1718,     0,     0,     0,     0,     0,     0,
     872,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1751,  1752,  1753,     0,  1755,     0,  2628,     0,
    1876,     0,  1876,  2645,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1876,     0,     0,     0,     0,  1876,     0,
       0,     0,  1718,  2310,  2311,     0,     0,     0,     0,     0,
    2315,  2316,   872,     0,   872,     0,     0,     0,     0,   682,
       0,     0,     0,   872,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1096,
       0,     0,  1097,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  2145,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1861,     0,  2450,     0,     0,  2455,
       0,  1818,     0,     0,     0,     0,     0,  1718,     0,  1862,
    2167,     0,     0,     0,     0,   925,  1718,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1863,     0,  2736,  2637,
    2738,  2739,  2740,  2741,     0,     0,     0,     0,     0,     0,
       0,     0,  1865,  1876,     0,  1876,  1876,  1876,  1876,     0,
       0,     0,     0,     0,     0,     0,   855,     0,     0,     0,
       0,  1961,  2460,  2461,     0,     0,     0,     0,     0,     0,
    2369,  2468,     0,     0,     0,     0,  1876,     0,     0,  2481,
       0,  1098,  2885,  1867,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1868,  1099,  2496,  2497,     0,
    1100,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1855,  1856,     0,  1857,     0,
       0,   269,  1858,  1859,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1869,     0,  1101,     0,
       0,  1860,     0,     0,     0,     0,  2807,     0,  2181,  2538,
    2308,  2540,     0,     0,     0,  1876,     0,  1876,  2542,     0,
    2544,  1876,  1876,  1876,     0,     0,  1102,  1079,  1080,  1081,
    1082,  1083,  1084,  1085,  1086,  1870,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1103,     0,  1871,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1872,
    1873,     0,     0,     0,     0,     0,     0,     0,  1874,     0,
       0,   688,     0,     0,     0,     0,     0,     0,     0,   272,
       0,     0,     0,     0,  1087,  1088,  1089,  1090,  1091,  1092,
     872,     0,     0,  2100,     0,  2100,     0,     0,     0,     0,
    1093,  1094,  1095,     0,   925,     0,     0,     0,  2523,     0,
    2585,  2586,     0,  2872,  2587,  2588,     0,     0,     0,     0,
       0,     0,     0,  1876,     0,     0,  1104,     0,  1876,     0,
       0,     0,     0,     0,   872,     0,     0,  2889,     0,     0,
       0,     0,  2889,     0,     0,   828,     0,     0,  2611,     0,
       0,     0,  1876,     0,   829,     0,     0,  1876,     0,     0,
       0,     0,     0,   830,     0,     0,     0,  2478,   831,     0,
       0,     0,  1961,     0,     0,     0,  2488,     0,   702,     0,
    2492,     0,     0,     0,     0,     0,     0,  1876,     0,     0,
       0,     0,  2502,  1105,     0,     0,     0,     0,     0,  2929,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   832,     0,  1876,  2711,     0,     0,     0,     0,
     833,     0,     0,     0,  1071,  1072,  1073,  1074,  1075,  1076,
    1077,  1078,  1079,  1080,  1081,  1082,  1083,  1084,  1085,  1086,
       0,  1096,     0,     0,  1097,  2728,     0,     0,     0,     0,
       0,  1961,     0,  2980,     0,  2983,     0,     0,     0,     0,
    2704,     0,     0,     0,  2709,     0,  1876,     0,  1876,     0,
    1876,     0,     0,  2744,     0,     0,   834,     0,     0,  1876,
       0,     0,     0,     0,     0,     0,     0,     0,  2999,  1087,
    1088,  1089,  1090,  1091,  1092,     0,  2726,     0,     0,     0,
    1876,   835,     0,  1876,  1876,  1093,  1094,  1095,   836,     0,
     837,     0, -1789,     0,     0,     0,  1876,     0,     0,     0,
     838,     0,     0,     0,     0,     0,     0,     0,     0,  2745,
       0, -1789,  1861,  2583,  1075,  1076,  1077,  1078,  1079,  1080,
    1081,  1082,  1083,  1084,  1085,  1086,   839,  1862,     0,     0,
       0,     0,     0,     0,   840,  2889,     0,     0,     0,     0,
   -1789,     0,     0,  1098,  1863,     0,     0,  1864,     0,     0,
    1876,     0,     0,  2605,     0,     0,     0,  2929,  1099,     0,
    1865,     0,  1100,     0,     0,     0,  2620,     0,     0,     0,
       0,   841,  1876,     0,     0,  1087,  1088,  1089,  1090,  1091,
    1092,     0, -1789,     0,     0,     0,     0,  1718,  2369,     0,
       0,  1093,  1094,  1095,     0,  2980,     0,   842,     0,  2889,
    1101,  1867,     0,     0,     0,     0,     0,     0,     0,     0,
    1876,     0, -1789,  1868,  1876,     0, -1789,     0,     0,     0,
    2842,     0,     0,     0,     0,     0,  1096,   872,  1102,  1097,
       0,     0,     0,     0,     0,   843,     0,     0,     0,     0,
   -1789,     0,   925,     0,     0,     0,   844,  1103, -1789,     0,
   -1789,     0,     0,     0,  1869,   872,     0,     0,     0, -1789,
    2485,     0,     0,  1718,     0, -1789,     0,     0,     0,     0,
     190,  1718,     0, -1789,     0,     0,     0, -1789,     0,     0,
       0,     0,     0, -1789,     0,     0,     0, -1789, -1789, -1789,
   -1789,     0,     0,  1870,     0,   927,     0,     0,     0,     0,
       0,     0, -1789,     0,     0,  1871,  2861,     0,     0,     0,
       0,   190,     0,     0,     0,     0,     0,  1872,  1873, -1789,
       0,     0, -1789,     0, -1789,     0,  1874,     0,  1104,   688,
       0, -1789,  1096,     0,     0,  1097,     0,   272,     0,     0,
       0,     0,     0,     0, -1789,   845,   846,   847,  1098,     0,
       0,     0,     0,     0, -1789,     0,     0,     0,   848,     0,
       0,     0,     0,  1099,     0,     0,     0,  1100,  1413,     0,
       0,     0,  2478, -1789, -1789,  1855,  1856,     0,  1857,     0,
       0,   269,  1858,  1859,     0,     0,     0,     0, -1789,     0,
       0,     0,     0,     0,     0,  1105, -1789,     0,     0,     0,
   -1789,  1860,     0,     0,     0,  1101,     0,     0,     0, -1789,
   -1789, -1789,     0,     0,  2605,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1102,     0,     0,     0,  2966,     0,     0,
       0,  2191,  2192,  2193,  2194,     0,     0,     0,     0,     0,
      72,     0,  1103,     0,  1098,     0,     0,     0,     0,  2321,
    2322,     0,   849,  2323,  2324,  2325,     0,     0,     0,  1099,
       0,     0,     0,  1100,     0,     0,     0,  3028, -1789,     0,
    2990,  2991,     0,  2993,     0,  2995,  2996,     0,     0, -1789,
       0,     0,     0,     0,     0,  2195,  2196,  2197,  2198,  2199,
    2200,     0,   872,     0,     0,     0,     0,     0,     0,     0,
       0,  1101,     0,     0,     0,     0,     0,     0,     0,  2851,
    2478,     0,     0,     0,   927,     0,     0,     0,     0,     0,
   -1789,     0,     0,  1104,     0,     0,     0,     0,     0,  1102,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  3040,
       0,     0,     0,     0,     0,     0,  2692,     0,  1103,     0,
       0,     0,     0,  2326,     0,     0,     0,     0,     0,  3049,
    2327,  3050,     0,     0,     0,     0,     0,     0,  2478,     0,
       0,     0,     0,  3070,     0,     0,     0,     0,     0,     0,
       0, -1789,  2605,     0,     0,     0,     0,  2905,     0,  2907,
    1105,     0,     0,     0,  2328,     0,     0,  1718,  3062,     0,
       0,     0,   158,  2329,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0, -1789,     0,     0,
       0,  2011,  3067,  3068,     0,     0,  3069,     0,     0,  1104,
     872,     0,  2330,  2331,     0,     0,   872,     0,     0,     0,
       0,   159,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     160,     0,     0,     0, -1789,     0,     0,     0,     0,     0,
       0,     0,     0,  2250,     0,     0,     0,  2332, -1789, -1789,
   -1789, -1789, -1789, -1789, -1789,     0, -1789, -1789,     0,     0,
       0,     0,     0,     0,     0,     0,  1105,     0,     0,   161,
       0,     0,     0, -1789,     0,     0,     0,     0,     0,     0,
       0,   162,     0,  2251,  2252,  2253,     0,     0,     0,  2333,
       0,   163,  1861,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1862,  2254,   164,
    1168,  1168,  1168,  1168,  1168,  1168,  2255,     0,     0,   165,
       0,  2256,     0,     0,  1863,     0,     0,  2012,     0,     0,
       0,     0,     0,     0,     0,   166,  2257,     0,     0,  2013,
    1865,  2258,     0,  2259,     0,  2334,     0,     0,     0,     0,
    2260,     0,     0,  2261,     0,     0,  2262,     0,     0,  2263,
       0,     0,  2264,     0,     0,     0,     0,  2265,     0,     0,
       0,     0,     0,     0,     0,   167,     0,     0,     0,     0,
       0,  1867,     0,     0,     0,  2266,     0,     0,     0,     0,
       0,     0,     0,  1868,     0,     0,     0,     0,     0,   168,
       0,  2267,     0,     0,  2268,  2269,     0,     0,     0,     0,
       0,  2270,     0,     0,   169,     0,     0,     0,     0,     0,
       0,   170,  2271,     0,   171,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1869,     0,     0,     0,  2272,     0,
       0,     0,   927,     0,   172,  2273,     0,   173,     0,   174,
       0,     0,  2274,     0,     0,  2275,  2276,  2277,     0,  2278,
    2279,     0,     0,     0,     0,     0,     0,     0,   175,     0,
       0,     0,     0,  1870,     0,     0,  2280,     0,     0,     0,
       0,     0,     0,     0,     0,  1871,   176,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1872,  1873,  2281,
    2282,  2283,  2284,     0,  2285,     0,  1874,     0,     0,   688,
       0,     0,     0,     0,     0,     0,     0,   272,     0,     1,
       0,  2286,  2287,   417,   418,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   419,     0,   420,     0,
       0,     0,     0,     0,  2288,     0,     0,     0,     0,     0,
       0,     0,   421,  2289,  2290,     0,  2291,     0,     0,   422,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     423,   424,   425,     0,  2335,  2336,  2337,  2338,  2339,  2340,
    2341,  2342,  2343,  2344,     0,     0,   426,     0,   427,   428,
     429,     3,     4,   430,     5,     6,   431,     0,   432,     7,
     433,   434,     0,     0,     0,     0,     0,   435,     0,     0,
     436,     0,   437,   438,   439,     0,     8,     9,  2292,     0,
       0,     0,   440,     0,   441,   442,     0,   443,     0,   444,
     445,     0,     0,   446,    10,    11,     0,  1718,   447,   448,
     449,     0,   450,   451,     0,     0,     0,   452,   453,     0,
     454,     0,     0,     0,   455,     0,   456,   457,     0,     0,
       0,     0,   458,     0,     0,     0,   459,     0,     0,   460,
       0,   461,     0,   462,     0,   463,     0,   464,   465,     0,
     466,   467,   468,     0,     0,     0,   469,     0,   470,   471,
       0,   472,     0,     0,     0,     0,     0,     0,     0,   473,
     474,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   475,     0,     0,   476,   477,     0,     0,   478,
     479,     0,     0,   480,   481,     0,     0,     0,     0,     0,
       0,     0,   482,   483,   484,     0,   485,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   486,   487,   488,     0,
     489,     0,     0,     0,   490,   491,     0,     0,     0,   492,
       0,     0,     0,     0,     0,     0,     0,   493,     0,     0,
       0,     0,     0,     0,     0,   494,   495,   496,     0,     0,
       0,     0,     0,   497,   498,     0,     0,     0,     0,   499,
       0,     0,   500,     0,     0,     0,   501,   502,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   503,  1071,  1072,
    1073,  1074,  1075,  1076,  1077,  1078,  1079,  1080,  1081,  1082,
    1083,  1084,  1085,  1086,     0,   504,     0,     0,     0,     0,
       0,     0,     0,   505,     0,     0,     0,     0,     0,   506,
    1071,  1072,  1073,  1074,  1075,  1076,  1077,  1078,  1079,  1080,
    1081,  1082,  1083,  1084,  1085,  1086,     0,     0,     0,     0,
       0,     0,   107,     0,     0,     0,     0,     0,     0,   507,
       0,   508,   509,  1087,  1088,  1089,  1090,  1091,  1092,     0,
     510,     0,     0,     0,     0,     0,     0,     0,     0,  1093,
    1094,  1095,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1087,  1088,  1089,  1090,  1091,
    1092,     0,     0,     0,     0,     0,     0,     0,     0,   511,
       0,  1093,  1094,  1095,     0,     0,     0,     0,     0,     0,
     512,     0,     0,     0,   513,     0,     0,     0,   514,  1071,
    1072,  1073,  1074,  1075,  1076,  1077,  1078,  1079,  1080,  1081,
    1082,  1083,  1084,  1085,  1086,     0,     0,     0,     0,     0,
       0,     0,   515,   516,     0,     0,     0,   517,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   518,
       0,     0,     0,     0,     0,   519,   520,   521,   522,     0,
       0,   523,     0,     0,     0,   524,     0,     0,     0,     0,
       0,     0,   525,   526,  1087,  1088,  1089,  1090,  1091,  1092,
       0,     0,     0,     0,   527,     0,   528,     0,     0,     0,
    1093,  1094,  1095,     0,     0,     0,     0,   529,     0,   530,
    1096,     0,   531,  1097,     0,     0,     0,     0,   532,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1096,     0,   533,  1097,     0,   534,     0,     0,
       0,     0,     0,   535,     0,     0,   536,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   537,     0,     0,     0,     0,     0,     0,   538,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   539,   540,   541,   542,   543,   544,   545,     0,     0,
     546,     0,   547,     0,   548,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1098,     0,     0,     0,     0,     0,     0,     0,
       0,  1096,     0,     0,  1097,     0,     0,  1099,     0,     0,
       0,  1100,  1725,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1098,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1099,
       0,     0,     0,  1100,  1734,     0,     0,     0,     0,  1101,
    1071,  1072,  1073,  1074,  1075,  1076,  1077,  1078,  1079,  1080,
    1081,  1082,  1083,  1084,  1085,  1086,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1102,     0,     0,
       0,  1101,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1103,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1102,
       0,     0,     0,     0,     0,  1087,  1088,  1089,  1090,  1091,
    1092,     0,     0,  1098,     0,     0,     0,     0,  1103,     0,
       0,  1093,  1094,  1095,     0,     0,     0,     0,  1099,     0,
       0,     0,  1100,  1746,     0,     0,     0,  1071,  1072,  1073,
    1074,  1075,  1076,  1077,  1078,  1079,  1080,  1081,  1082,  1083,
    1084,  1085,  1086,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1104,     0,     0,
    1101,  1071,  1072,  1073,  1074,  1075,  1076,  1077,  1078,  1079,
    1080,  1081,  1082,  1083,  1084,  1085,  1086,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1102,  1104,
       0,     0,  1087,  1088,  1089,  1090,  1091,  1092,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1103,  1093,  1094,
    1095,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1105,     0,  1087,  1088,  1089,  1090,
    1091,  1092,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1093,  1094,  1095,     0,     0,     0,     0,     0,
       0,     0,  1096,     0,     0,  1097,  1105,  1071,  1072,  1073,
    1074,  1075,  1076,  1077,  1078,  1079,  1080,  1081,  1082,  1083,
    1084,  1085,  1086,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1104,     0,
       0,     0,     0,     0,     0,     0,  1071,  1072,  1073,  1074,
    1075,  1076,  1077,  1078,  1079,  1080,  1081,  1082,  1083,  1084,
    1085,  1086,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1087,  1088,  1089,  1090,  1091,  1092,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1093,  1094,
    1095,     0,     0,     0,     0,     0,     0,     0,     0,  1096,
       0,     0,  1097,     0,     0,  1105,     0,     0,     0,     0,
       0,  1087,  1088,  1089,  1090,  1091,  1092,     0,     0,     0,
       0,     0,     0,     0,  1098,     0,     0,  1093,  1094,  1095,
       0,     0,     0,  1096,     0,     0,  1097,     0,     0,  1099,
       0,     0,     0,  1100,  1754,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1101,     0,  1072,  1073,  1074,  1075,  1076,  1077,  1078,
    1079,  1080,  1081,  1082,  1083,  1084,  1085,  1086,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1102,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1098,     0,     0,     0,     0,     0,     0,  1103,  1096,
       0,     0,  1097,     0,     0,     0,  1099,     0,     0,     0,
    1100,  1756,     0,     0,     0,     0,     0,  1087,  1088,  1089,
    1090,  1091,  1092,     0,     0,  1098,     0,     0,     0,     0,
       0,     0,     0,  1093,  1094,  1095,     0,     0,  1096,     0,
    1099,  1097,     0,     0,  1100,  1757,     0,     0,  1101,     0,
       0,     0,  1073,  1074,  1075,  1076,  1077,  1078,  1079,  1080,
    1081,  1082,  1083,  1084,  1085,  1086,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1102,     0,     0,  1104,
       0,     0,  1101,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1103,  1082,  1083,  1084,  1085,
    1086,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1102,     0,     0,     0,     0,  1087,  1088,  1089,  1090,  1091,
    1092,  1098,     0,     0,     0,     0,     0,     0,     0,  1103,
       0,  1093,  1094,  1095,     0,     0,  1099,     0,     0,     0,
    1100,  1758,     0,     0,     0,     0,  1105,     0,     0,     0,
    1087,  1088,  1089,  1090,  1091,  1092,     0,     0,     0,     0,
    1098,     0,     0,     0,     0,     0,  1093,  1094,  1095,     0,
       0,     0,     0,     0,  1096,  1099,  1104,  1097,  1101,  1100,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1074,
    1075,  1076,  1077,  1078,  1079,  1080,  1081,  1082,  1083,  1084,
    1085,  1086,     0,     0,     0,     0,  1102,     0,     0,     0,
    1104,     0,     0,     0,     0,     0,     0,  1101,     0,     0,
       0,     0,     0,     0,     0,  1103,  1076,  1077,  1078,  1079,
    1080,  1081,  1082,  1083,  1084,  1085,  1086,     0,     0,     0,
       0,     0,     0,  1105,     0,  1102,     0,     0,     0,     0,
       0,  1087,  1088,  1089,  1090,  1091,  1092,     0,     0,     0,
       0,     0,     0,     0,  1103,     0,     0,  1093,  1094,  1095,
       0,     0,  1096,     0,     0,  1097,     0,  1105,     0,  1081,
    1082,  1083,  1084,  1085,  1086,     0,  1087,  1088,  1089,  1090,
    1091,  1092,     0,     0,     0,     0,  1098,     0,     0,     0,
       0,     0,  1093,  1094,  1095,     0,  1104,  1096,     0,     0,
    1097,  1099,     0,     0,     0,  1100,  1078,  1079,  1080,  1081,
    1082,  1083,  1084,  1085,  1086,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1087,  1088,  1089,  1090,  1091,  1092,
       0,     0,     0,     0,     0,  1104,     0,     0,     0,     0,
    1093,  1094,  1095,  1101,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1105,  1087,  1088,  1089,  1090,  1091,  1092,
       0,  1102,     0,     0,     0,  1084,  1085,  1086,     0,     0,
    1093,  1094,  1095,     0,  1098,     0,     0,     0,     0,     0,
    1103,     0,     0,     0,     0,     0,     0,     0,  1096,  1099,
       0,  1097,  1105,  1100,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1098,
       0,     0,     0,     0,     0,     0,     0,  1087,  1088,  1089,
    1090,  1091,  1092,  1096,  1099,     0,  1097,     0,  1100,     0,
       0,  1101,     0,  1093,  1094,  1095,     0,   713,   714,     0,
       0,     0,     0,   269,   715,   716,  -610,  1855,  1856,     0,
    1857,     0,     0,   269,  1858,  1859,     0,     0,   717,  1102,
       0,  1104,     0,   718,   719,     0,  1101,     0,     0,     0,
     720,  1096,     0,  1860,  1097,     0,     0,     0,  1103,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1102,     0,     0,     0,   721,     0,
       0,  1085,  1086,     0,     0,     0,     0,     0,     0,     0,
    1098,  1096,     0,  1103,  1097,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1099,     0,     0,  1105,  1100,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1098,     0,     0,     0,     0,
       0,     0,  1087,  1088,  1089,  1090,  1091,  1092,     0,  1104,
    1099,     0,     0,     0,  1100,     0,     0,  1101,  1093,  1094,
    1095,     0,     0,     0,  1096,     0,     0,  1097,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   722,     0,  1098,  1104,  1102,     0,     0,     0,     0,
       0,     0,  1101,     0,     0,     0,     0,     0,  1099,     0,
       0,     0,  1100,     0,  1103,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1105,     0,     0,     0,
    1102,     0,     0,  1098,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1099,  1103,
    1101,     0,  1100,     0,     0,     0,     0,     0,     0,     0,
       0,  1105,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   713,   714,     0,     0,     0,  1102,   269,
     715,   716,  -610,     0,     0,     0,     0,     0,   723,     0,
    1101,     0,     0,   724,   717,  1104,  1098,  1103,     0,   718,
     719,     0,     0,     0,     0,     0,   720,     0,     0,  1096,
       0,  1099,  1097,     0,     0,  1100,     0,     0,  1102,     0,
       0,   725,     0,     0,     0,     0,     0,     0,     0,     0,
    1104,     0,     0,     0,   721,     0,     0,  1103,     0,     0,
     713,   714,     0,     0,     0,     0,   269,   715,   716,     0,
       0,     0,     0,  1101,     0,     0,   726,     0,     0,     0,
       0,   717,  1105,     0,     0,     0,   718,   719,   727,     0,
       0,     0,     0,   720,     0,     0,     0,     0,  1104,     0,
       0,  1102,     0,     0,     0,     0,   728,     0,     0,     0,
       0,   729,     0,     0,   730,     0,     0,  1105,     0,     0,
    1103,   721,     0,     0,  1861,   731,     0,   713,   714,     0,
       0,   732,     0,   269,   715,   716,     0,     0,  1104,  1862,
       0,   733,     0,     0,     0,     0,   734,   722,   717,   735,
       0,  1098,   736,   718,   719,     0,  1863,     0,     0,  1864,
     720,   737,   738,     0,     0,  1105,  1099,     0,     0,     0,
    1100,     0,  1865,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   721,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1104,  1191,   739,     0,  1105,     0,   740,  1101,     0,
       0,     0,  1866,  1867,   722,   741,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1868,   742,     0,     0,     0,
       0,     0,   743,     0,     0,     0,  1102,     0,     0,     0,
       0,     0,     0,     0,   723,     0,     0,     0,     0,   724,
       0,     0,     0,     0,     0,  1103,   744,     0,     0,     0,
       0,     0,     0,     0,   713,   714,  1869,     0,  1105,     0,
     269,   715,   716,     0,     0,     0,     0,   725,     0,     0,
       0,   722,     0,     0,     0,   717,     0,     0,     0,     0,
     718,   719,     0,     0,     0,     0,     0,   720,     0,     0,
     745,     0,     0,     0,     0,  1870,     0,   746,     0,   747,
       0,   723,   726,     0,     0,     0,   724,  1871,     0,   748,
     749,   750,     0,     0,   727,   721,     0,     0,   751,  1872,
    1873,    82,     0,     0,     0,     0,  1104,     0,  1874,   272,
       0,   688,   728,     0,   725,     0,     0,   729,     0,   272,
     730,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   731,     0,     0,     0,     0,     0,   732,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   733,   723,   726,
       0,     0,   734,   724,     0,   735,     0,     0,   736,     0,
       0,   727,     0,     0,     0,     0,     0,   737,   738,   713,
     714,     0,     0,  1105,     0,   269,   715,   716,     0,   728,
       0,   725,     0,     0,   729,     0,     0,   730,   722,     0,
     717,     0,     0,     0,     0,   718,   719,     0,   731,     0,
       0,     0,   720,     0,   732,     0,     0,     0,     0,   739,
       0,     0,     0,   740,   733,     0,   726,     0,     0,   734,
       0,   741,   735,     0,     0,   736,     0,     0,   727,     0,
     721,     0,   742,     0,   737,   738,     0,     0,   743,     0,
       0,     0,     0,     0,     0,     0,   728,     0,     0,     0,
       0,   729,     0,     0,   730,     0,     0,     0,     0,     0,
       0,     0,   744,     0,     0,   731,     0,     0,     0,     0,
       0,   732,     0,     0,     0,  1191,   739,     0,     0,     0,
     740,   733,     0,     0,     0,   723,   734,     0,   741,   735,
     724,     0,   736,     0,     0,     0,     0,     0,     0,   742,
       0,   737,   738,     0,     0,   743,   745,     0,     0,     0,
       0,     0,     0,   746,     0,   747,     0,     0,   725,     0,
       0,     0,     0,   722,     0,   748,   749,   750,     0,   744,
       0,     0,     0,     0,   751,     0,     0,    82,     0,     0,
       0,     0,     0,   739,     0,   272,     0,   740,     0,     0,
       0,     0,     0,   726,     0,   741,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   727,   742,     0,  2114,     0,
       0,     0,   743,   745,     0,     0,     0,     0,     0,     0,
     746,     0,   747,   728,     0,     0,     0,  -852,   729,     0,
       0,   730,   748,   749,   750,     0,   744,     0,     0,     0,
       0,   751,   731,     0,    82,     0,     0,     0,   732,     0,
       0,     0,   272,     0,     0,     0,     0,     0,   733,     0,
     723,     0,     0,   734,     0,   724,   735,     0,     0,   736,
       0,     0,     0,     0,     0,     0,   713,   714,   737,   738,
     745,     0,   269,   715,   716,     0,     0,   746,     0,   747,
       0,     0,     0,   725,     0,     0,     0,   717,     0,   748,
     749,   750,   718,   719,     0,     0,     0,     0,   751,   720,
       0,    82,     0,     0,     0,     0,     0,     0,     0,   272,
     739,     0,     0,     0,   740,     0,     0,     0,   726,     0,
       0,     0,   741,     0,     0,     0,     0,   721,  1855,  1856,
     727,  1857,     0,   742,   269,  1858,  1859,     0,     0,   743,
       0,     0,     0,     0,     0,     0,     0,     0,   728,     0,
       0,     0,     0,   729,  1860,     0,   730,     0,     0,     0,
       0,     0,     0,   744,     0,     0,     0,   731,     0,     0,
       0,     0,     0,   732,  1855,  1856,     0,  1857,     0,     0,
     269,  1858,  1859,   733,     0,     0,     0,     0,   734,     0,
       0,   735,     0,     0,   736,     0,     0,     0,     0,     0,
    1860,     0,     0,   737,   738,  1855,  1856,   745,  1857,     0,
       0,   269,  1858,  1859,   746,     0,   747,     0,     0,     0,
     722,     0,     0,     0,     0,     0,   748,   749,   750,     0,
       0,  1860,     0,     0,     0,   751,     0,     0,    82,     0,
       0,     0,     0,     0,  2506,   739,   272,     0,     0,   740,
       0,     0,     0,     0,     0,     0,     0,   741,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   742,     0,
       0,     0,     0,     0,   743,     0,     0,     0,     0,     0,
       0,     0,  1855,  1856,     0,  1857,     0,     0,   269,  1858,
    1859,     0,     0,     0,     0,     0,     0,     0,   744,     0,
       0,     0,     0,     0,  1855,  1856,     0,  1857,  1860,     0,
     269,  1858,  1859,     0,     0,     0,     0,   723,     0,     0,
       0,     0,   724,     0,     0,     0,     0,     0,     0,     0,
    1860,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   745,     0,     0,     0,     0,     0,     0,   746,
     725,   747,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   748,   749,   750,     0,     0,     0,     0,     0,     0,
     751,     0,     0,    82,     0,     0,     0,  1086,     0,     0,
       0,   272,     0,     0,  2011,   726,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   727,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   728,     0,     0,     0,     0,
     729,     0,     0,   730,     0,     0,     0,  1087,  1088,  1089,
    1090,  1091,  1092,     0,   731,     0,     0,   203,     0,     0,
     732,     0,     0,  1093,  1094,  1095,     0,     0,     0,     0,
     733,     0,     0,     0,     0,   734,     0,     0,   735,     0,
       0,   736,     0,     0,     0,   204,   205,     0,     0,     0,
     737,   738,     0,     0,   206,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1861,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1862,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   739,     0,     0,     0,   740,  1863,     0,     0,
    2012,     0,     0,     0,   741,     0,     0,     0,     0,     0,
       0,  1861,  2013,  1865,     0,   742,     0,     0,     0,     0,
       0,   743,     0,     0,     0,     0,  1862,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1861,  1863,     0,   744,  2884,     0,     0,     0,
       0,     0,     0,     0,  1867,     0,     0,  1862,     0,  1865,
       0,     0,     0,     0,  1096,     0,  1868,  1097,     0,     0,
       0,     0,     0,     0,  1863,     0,     0,  2637,     0,     0,
    1912,     0,     0,     0,     0,     0,     0,     0,     0,   745,
    1865,     0,     0,     0,     0,     0,   746,     0,   747,  2885,
    1867,     0,     0,     0,     0,     0,     0,  1869,   748,   749,
     750,     0,  1868,     0,     0,     0,     0,   751,     0,  1861,
      82,     0,     0,     0,     0,   207,     0,     0,   272,     0,
    2885,  1867,     0,     0,  1862,     0,     0,     0,     0,     0,
       0,  1861,     0,  1868,     0,     0,  1870,     0,     0,     0,
       0,  1863,     0,  1869,  1864,     0,  1862,     0,  1871,     0,
       0,     0,     0,     0,   208,     0,     0,  1865,     0,     0,
    1872,  1873,  2014,  1863,     0,     0,  1864,     0,     0,  1874,
       0,     0,   688,   209,  1869,  2944,  1098,     0,     0,  1865,
     272,     0,  1870,     0,     0,     0,     0,     0,     0,   210,
       0,  1099,     0,     0,  1871,  1100,     0,  2977,  1867,     0,
       0,     0,     0,     0,     0,     0,  1872,  1873,     0,     0,
    1868,     0,   211,  1870,     0,  1874,     0,     0,   688,     0,
    1867,     0,     0,     0,   212,  1871,   272,     0,     0,     0,
       0,  2945,  1868,  1101,   213,     0,     0,  1872,  1873,     0,
       0,     0,     0,     0,     0,     0,  1874,     0,     0,   688,
       0,  1869,   214,     0,     0,     0,  2946,   272,     0,     0,
       0,  1102,   215,     0,     0,  2947,     0,     0,     0,     0,
       0,     0,     0,  1869,     0,     0,     0,     0,   216,     0,
    1103,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1870,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  2948,  1871,     0,  1913,     0,     0,     0,     0,  2949,
       0,     0,  1870,     0,  1872,  1873,     0,  1914,   217,     0,
       0,     0,     0,  1874,  1871,     0,   688,     0,     0,     0,
       0,     0,     0,     0,   272,     0,  1872,  1873,     0,     0,
       0,     0,   218,     0,     0,  1874,     0,     0,   688,     0,
       0,     0,     0,     0,     0,     0,   272,   219,     0,     0,
       0,  1104,     0,     0,   220,     0,     0,   221,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1915,     0,     0,     0,     0,     0,   222,  1916,     0,
     223,     0,   224,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  2950,     0,     0,     0,     0,     0,     0,
       0,   225,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1917,  1105,   226,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1918,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1919,  1920,     0,     0,     0,     0,     0,     0,
       0,     0,   227,     0,     0,     0,     0,     0,  1921,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1922,
       0,     0,  1923,  1924,     0,     0,     0,     0,  1925,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1926,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  2951,     0,  1927
};

static const short yycheck[] =
{
       2,   193,   707,   187,    64,   703,   328,   838,   978,   212,
      12,    13,   827,   445,  1481,   856,   515,   422,   985,   823,
     992,   521,     0,    82,   682,  1723,   153,  1394,   834,   835,
     497,   837,  1674,   839,   840,  1670,    60,   363,   507,  1727,
     919,    43,    44,   542,   513,    23,   545,  2054,   517,  1844,
     175,    29,  1359,  1010,   933,  1348,  1362,   117,  1665,  1666,
     864,     5,  1669,  1259,  1260,  1785,  1448,   418,  1291,  1593,
     479,    95,    20,   504,    76,     5,     5,    79,   388,    24,
     264,   779,     5,  2011,    24,  2013,    64,    24,    24,    91,
      23,    24,    25,    25,     5,    45,    98,    17,    18,   504,
     225,   452,   104,   105,   455,    25,   538,     5,   110,   111,
     237,   238,  2231,     5,   465,    79,  1911,   141,   469,    25,
      24,   145,   473,    24,    47,    55,    49,    24,    51,   480,
       5,    61,    79,    24,   485,   950,   487,   952,    23,   117,
      25,    23,   493,    25,    23,   496,    25,   149,   340,    25,
     152,  1533,   503,    26,  1022,   157,    18,   508,    24,    24,
    1542,    23,    24,    25,   508,   516,     5,  1774,     5,    24,
      41,    23,    24,    25,    18,    23,   527,    25,    24,     5,
     531,    25,    24,    41,   535,    23,    24,    25,    24,   540,
      26,  1056,   543,     5,   196,    24,    24,    26,    29,    24,
      24,    26,     5,   227,   128,     5,    17,    18,    39,     5,
       5,     5,    23,    24,    25,     5,   128,     5,   923,  1861,
      24,   845,   846,     5,   253,    66,    67,     5,  1605,    20,
    2569,     5,   234,    24,    17,    18,   688,   214,   240,   113,
      23,    24,    25,     5,  2629,   228,  2631,    70,  2405,   251,
       6,   353,   368,    84,    85,   323,   280,    22,   282,    17,
      18,    92,    22,   287,   318,    23,    24,    25,     5,    26,
     101,   102,  1644,   104,   105,  1647,     5,   318,   109,     9,
     363,    11,    12,    13,    14,    15,    16,  2185,  2186,  2187,
    2188,    24,  2771,    26,  2566,   126,   127,     5,   339,     5,
       5,   437,     5,   253,   364,   365,     6,   318,  1899,   227,
       5,   310,   336,   144,   145,  1950,   437,   274,    22,   370,
    1787,    17,    18,    19,    20,    21,     5,    17,    18,   353,
      20,     5,     5,    23,    24,    25,   437,    24,   283,     5,
    1947,     5,   409,     5,   289,   290,   291,  2884,   517,  2765,
    2145,     0,  2509,    43,   356,   253,   517,   359,   517,   525,
     409,   370,  1203,  1943,   309,   367,    20,  1974,   101,   102,
      24,   104,   105,   323,    35,    36,   109,  2012,   253,     6,
    2832,   383,   365,   385,   367,  2883,   364,   365,   437,   889,
    1362,     5,   488,   126,   127,   404,  1127,   566,  1129,     5,
     450,  2008,    63,    64,    65,   566,     5,   566,   458,     5,
     412,   144,   145,     5,    30,   417,     5,   419,   368,   312,
     422,   423,     5,   425,    28,     5,   428,   141,     5,   154,
     363,   597,   568,   186,   129,  2554,     5,   439,   540,    17,
      18,    19,    20,    21,   446,     5,   119,     5,   213,     5,
     141,   408,     5,   213,     5,     5,   458,  1162,     5,     5,
    2388,  2877,  2390,   599,  2392,     5,   468,     5,     5,   471,
       5,   364,   417,    27,     5,   420,   827,  2975,   599,   481,
      43,     5,   215,     5,     5,     5,     5,  1998,  2940,   409,
     363,   114,   115,  2004,   493,   497,   498,  2913,   599,   444,
    2772,   231,   504,   557,   503,  2984,   574,   484,   591,   213,
     512,  3048,   514,   515,   450,   346,   557,   568,   547,   464,
     522,   523,   638,   525,   526,   250,   528,   605,   530,  2914,
     532,   370,   450,   466,   536,   537,  1035,   539,   605,   541,
     542,   372,   544,   545,   646,   547,   557,   873,   419,   875,
     646,  2890,   535,  1005,   499,    17,    18,    19,    20,    21,
    2976,  1028,   352,   374,  1188,  1032,  1033,  1034,  1945,    26,
     374,   328,  2163,   518,   519,  2182,   341,  1008,   389,  1444,
     504,   528,  1447,   273,  1051,   409,  1284,  1285,   518,   534,
     368,   374,   504,   405,  1790,  1293,   370,   547,   262,   950,
     951,   952,   405,  1008,   480,   405,   389,   951,   370,   323,
     574,   405,   443,  1985,   370,   555,   374,   405,   409,   493,
     350,   532,  2629,   405,  2631,   378,  1494,   564,   573,  2636,
    1130,   389,   323,   370,  2753,  2754,  2243,   341,  1336,   450,
     596,   370,  1142,   535,  1143,   647,   670,   969,   494,   547,
     521,   591,  2232,  2233,   591,   591,   262,   533,   591,   591,
     970,   606,   370,   521,   370,   370,   599,   370,   597,   555,
     370,   591,   547,   675,   597,   677,   606,  1556,   628,   629,
     630,  1148,   605,   416,   374,   591,   688,   591,   568,   639,
     591,   370,   529,   529,   591,  1126,   370,   641,   646,   389,
     591,   703,  2226,   529,   370,   536,  2501,  2864,   370,   405,
     596,   713,   714,  2641,   599,   591,   406,   599,   591,   409,
     599,  1126,  1131,  1222,   568,   591,   591,   729,  1195,   525,
     525,   421,   422,   735,   736,  1958,   591,   599,   740,   591,
    1712,  2034,  2462,   370,  1701,  2433,  2466,   599,   750,   591,
    2057,   599,   221,  2059,  1221,   591,   370,  1256,  1257,  1226,
     450,   599,   591,   591,   605,  2922,   591,  2149,   345,   458,
    1239,   370,   433,   463,   370,  2157,     5,   779,   370,    92,
     591,   370,   471,  1215,  2682,   475,   617,   370,   599,  2396,
     370,  2398,   415,  1765,   625,   618,   619,   620,   621,   622,
     598,   370,   338,   366,   332,   535,  1621,   605,   591,   523,
     370,  2968,   370,  2970,   370,  1007,   599,   370,   131,   370,
     370,   823,   824,   370,   370,    17,   516,   405,   391,  2823,
     370,  2825,   370,   370,   261,   370,    44,   409,  2766,   370,
     261,   599,   556,  2771,   147,   596,   370,   274,   370,   370,
     370,   370,  2550,   274,   981,   432,   858,   984,   591,   520,
     338,   604,   864,  2230,   436,   555,  2724,   217,   224,  2511,
     224,  1371,   449,   217,   876,    83,   136,   567,    23,   881,
      25,   237,   224,   237,   627,   887,   842,     0,    20,   579,
     580,   581,    84,   849,   314,   237,   359,   136,   588,   409,
     129,   591,   563,   905,   367,   325,   599,  2914,   370,   599,
      23,  2918,   475,  1611,     5,   492,  1385,   919,   417,   455,
      23,   417,    25,   604,   274,   133,   436,   437,  2124,   428,
     274,   933,   428,     9,   332,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,   626,   627,     5,  2555,   412,
     417,   450,  2408,  2748,   531,  2411,  2884,   377,   457,   334,
     437,   428,  1146,   171,    17,    18,    19,    20,   541,   599,
    2577,   544,   392,    13,   547,  1444,   326,   455,  1447,  1810,
     330,   408,   326,   560,   986,   274,   330,   408,   990,   991,
     992,   604,   569,   500,  1493,    71,    72,    73,    74,    75,
      76,  2859,   409,  1005,   567,    23,  1008,    25,  1010,  1011,
    3004,    91,  1014,   626,   627,   275,   579,   580,    71,    72,
      73,    74,    75,    76,   303,   588,  1028,  1029,   564,   303,
    1032,  1033,  1034,  1035,   514,  1037,   275,   326,  1040,   527,
    1540,   330,  2009,   531,   409,    18,   409,   535,  1889,  1051,
      23,  1053,    25,   409,   437,  1057,  2984,   409,   408,   404,
     268,   409,   482,  1065,   408,  1067,  1068,   409,  1070,  1071,
    1072,  1073,  1074,  1075,  1076,  1077,  1078,  1079,  1080,  1081,
    1082,  1083,  1084,  1085,  1086,    25,   564,  2059,   409,  2056,
    2732,   351,  2734,  1592,   409,  1097,  1098,  1597,   460,   455,
    1102,   455,  1104,  2801,  2962,   418,  2964,   420,   421,  1576,
    1577,  2493,   351,   455,   417,   471,   409,   471,   437,   408,
    3048,   434,   843,   844,  1126,   428,   847,   848,   336,   471,
    1132,  1133,  1134,   409,  1949,  1486,   344,   512,   409,   452,
     348,  1143,   455,  1145,    25,  1147,  1148,   450,   461,   409,
    1152,   526,   465,  2760,   457,   231,   469,  1282,  1973,  2048,
     473,  2050,  2051,  1288,   477,   478,   409,   480,    27,    28,
     483,   455,   485,   486,   487,   618,   551,   385,   621,   622,
     493,   460,  2880,   496,   409,   469,   460,  1189,   409,   473,
     503,  2070,   605,  1195,   421,   508,   605,  1324,    87,    88,
      89,   485,  1528,   516,  1704,    25,  1333,   434,   436,   437,
      25,   471,  1214,    25,   527,   436,   437,  1219,   531,  1221,
    1222,    25,   535,    25,  1226,   600,  2833,   540,  1230,  1231,
     543,   599,   471,   437,   461,  1933,    25,   487,   249,  1241,
      25,   252,   604,   254,  1713,   453,   496,   619,   620,  1600,
     477,   478,    25,  1255,  1256,  1257,   483,  2624,  2893,   486,
      25,   623,   624,   274,    24,    25,  1766,    25,  1768,    25,
    1621,   436,   437,   284,   350,   266,   267,  1777,  1976,  1281,
      37,   643,  1284,  1285,   492,   621,   622,  1289,   599,  1291,
     540,  1293,   303,   543,   370,  2930,   370,   249,   628,   629,
     252,   409,   254,  1961,   340,  1329,    25,  1366,   516,     4,
       5,     6,     7,     8,     9,   326,    11,   370,   599,   330,
     142,   409,   274,   249,   146,   604,   252,   409,   254,     5,
     604,   407,   284,   405,  1336,    15,    16,    17,    18,    19,
      20,    21,   628,   629,   623,   624,  1348,   370,   274,   623,
     624,   303,   560,    24,    25,   599,    25,  1359,   284,   237,
    1362,   569,   196,   405,   643,   370,   200,   370,   340,   643,
    2174,    20,    25,    25,   326,    25,    20,    25,   330,  1381,
    1382,  1383,    25,   591,  2225,  1854,  2853,  1389,   409,    25,
    2757,    71,    72,    73,    74,    75,    76,   408,    25,  1734,
     326,  3008,    25,    29,   330,   599,   370,    87,    88,    89,
    1745,    17,    18,    19,    20,  1750,  1418,  1419,  1420,  1754,
    1422,  1756,  1757,  1758,     5,   370,   438,   249,    54,   591,
     252,   646,     9,   370,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,   281,   370,  1448,   370,  1450,   460,
    2417,  2423,   274,   370,   370,   603,   408,     5,   370,   535,
     281,   370,  1464,   370,   603,    71,    72,    73,    74,    75,
      76,   370,   370,   599,  2941,   101,   102,    24,   104,   105,
    1482,   437,   408,   109,   596,   599,  1488,     8,  1490,  1491,
    1492,  1493,   405,  2960,    71,    72,    73,    74,    75,    76,
     126,   127,    24,   458,    18,   581,   409,   504,   460,    23,
      24,    25,   409,   409,   827,   409,    19,    20,   144,   145,
    1522,   592,   593,   594,   595,  1527,   602,   345,   399,   409,
    1733,  1533,   345,   409,   460,   409,  1538,   142,   112,   142,
    1542,   146,   409,   146,   409,   409,  1548,   409,   228,  3016,
     438,   231,   101,   102,  1556,   104,   105,   409,   409,   409,
     109,  1563,   409,  1565,  2064,   170,   409,   170,    71,    72,
      73,    74,    75,    76,  1576,  1577,   409,   126,   127,   409,
      29,  2963,   409,   409,   409,    40,   408,   245,     5,   215,
    1592,   597,  1943,   409,   574,   144,   145,   597,  1949,   409,
     409,   409,   399,   345,   178,   638,   180,   438,  2108,  1611,
     444,   445,   638,    97,   432,   409,   305,  1619,     8,   432,
    2590,   195,  1973,    17,    18,    19,    20,    21,  1630,   203,
       5,   449,   643,   207,   575,     5,   449,   950,   951,   952,
     362,  1643,  1644,  2484,   249,  1647,   249,   252,   409,   252,
     409,  2482,   101,   102,   231,   104,   105,   112,   232,   409,
     109,  1663,   409,  1665,  1666,   409,   215,  1669,  1670,   274,
     350,   274,    24,   409,   492,   568,   323,   126,   127,   492,
      17,    18,    19,    20,   557,   365,     8,    13,   554,   369,
     432,   643,     5,     5,  1696,   144,   145,   399,   409,  1701,
     638,   409,   638,  1705,   538,    25,    25,   449,    70,   335,
    1712,    45,   437,   531,   548,   409,   200,   643,   531,   437,
      25,  1723,   409,   178,   208,   180,     5,   407,   409,    20,
     214,  2429,   216,   574,    71,    72,    73,    74,    75,    76,
     195,   599,   560,   227,  2211,   568,  2213,   560,   203,   409,
     492,   569,   207,   409,   450,   435,   569,  1759,   384,  1761,
     605,    20,    20,  1765,   370,    20,   605,  1769,  1770,  1771,
    1772,   255,  1774,   350,   454,   409,   409,   232,  1780,  1781,
     409,   345,  1784,  1785,  2489,   409,   605,   271,   409,   531,
     416,  1793,   276,   641,   329,   535,    17,  2202,   604,    18,
       5,  1803,    25,   408,   288,   408,   131,    25,   197,    24,
     602,   295,    71,    72,    73,    74,    75,    76,   560,   568,
     557,    17,    18,    19,    20,     5,   461,   569,   525,   461,
     407,   129,   345,    71,    72,    73,    74,    75,    76,   525,
       5,    25,   378,   300,    25,   643,   525,   409,  1850,   409,
    1852,   409,   409,  2694,   409,   535,    24,    17,    18,    19,
      20,  2702,  1864,    17,    18,    59,    20,   416,   432,    23,
      24,    25,   599,   707,   525,    71,    72,    73,    74,    75,
      76,  2232,  2233,   555,   370,   449,   335,   370,  1890,    43,
     370,  2323,  2324,  2325,   370,  2327,  2328,  2329,  2330,  2331,
    2332,   370,   370,   370,  2336,    25,   370,   370,   370,   370,
       5,    71,    72,    73,    74,    75,    76,   605,   596,   432,
     754,  2421,   602,     5,     5,   599,     5,   558,   492,   462,
     605,  1933,  1245,   370,   409,   384,   449,   604,  1998,   133,
     134,     5,   532,   409,  2004,  1947,   514,    25,  1950,  2449,
      25,   409,    45,   304,   370,  1957,  1958,     5,   535,   370,
     370,   409,  1964,   339,  1966,   575,   450,   531,   446,    13,
     529,  2470,  1974,   457,  1976,   605,  2674,   599,  2477,   492,
     639,   525,   345,  1985,    17,    18,    19,    20,     5,    25,
     468,   227,    79,   187,   450,   479,   560,   409,   599,   193,
     484,   605,   409,     5,   581,   569,  2008,   604,  2849,    24,
    2012,   618,  2014,  2718,   405,   439,   409,   405,   531,   439,
    1998,   370,   409,   409,   409,   602,  2004,   409,   409,   409,
       8,     5,  2034,   370,   512,     5,    25,    25,    71,    72,
      73,    74,    75,    76,   522,   523,   370,   560,   526,   568,
      77,   409,   530,   370,   532,  2057,   569,  2059,   536,   537,
     370,   370,   599,     5,     8,  2067,   323,   599,  2070,   432,
     264,  2073,   266,   599,   304,   323,   437,  2892,   323,   599,
     409,   404,    20,   339,     5,   399,   449,   630,   409,   923,
      25,   409,     5,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
     409,     5,  2114,   409,   345,  2117,   409,   409,     5,    25,
    2122,     5,   574,   574,   596,  2823,   409,  2825,     5,   492,
     562,     5,  2973,  2135,   599,  2137,     5,  2139,  2944,  2945,
    2946,  2947,  2948,  2949,  2146,   320,   340,  2149,     5,   599,
     370,  2153,     7,     5,   329,  2157,   409,    25,   605,    71,
      72,    73,    74,    75,    76,    25,    25,     8,   531,   599,
     370,   112,  2174,  1486,   370,    87,    88,    89,   353,   370,
    2182,   356,   370,   605,   568,    25,    25,  2189,  2190,  2191,
    2192,  2193,  2194,   370,   370,    20,  2696,   560,   370,   374,
    2202,   432,   605,   370,   138,     5,   569,   370,   253,  2211,
     370,  2213,   545,    20,   370,     5,     5,   525,   449,    20,
     374,   155,   156,     5,   219,   370,  2693,   370,   437,   163,
     409,   605,   419,   599,   550,   389,   430,   178,   370,   180,
     409,  2243,   450,     6,   532,   605,  2248,   532,   605,   189,
     603,    24,   406,   603,   195,   409,    24,    24,   598,   425,
      24,   492,   203,   197,    24,   450,   207,  2589,   422,    25,
     464,    25,   206,    25,    25,    25,   470,   218,   472,   409,
    2464,   409,   476,    25,   311,   479,    25,  1600,   482,   275,
       5,   232,   599,  2295,   370,   247,   370,   324,   492,   568,
     531,   235,  2304,  2305,  2306,   480,  3004,   504,  1621,   463,
    2312,   370,   447,  2505,     5,   409,   228,   511,   370,   231,
      20,   475,   529,     5,   219,   519,   520,   521,  1162,   560,
     399,   525,   323,   405,     5,   370,   370,   370,   569,   533,
    2840,   323,   419,    20,   118,   823,   280,    13,     5,    13,
     441,   189,   599,     5,   548,    20,   370,    25,   533,   370,
     370,   388,   516,    25,   370,   540,     5,    26,   395,   598,
     347,  3076,  2374,   310,  2376,    25,   352,   547,   370,   409,
     858,  1215,   420,   370,   220,  2387,   864,  1700,   322,   605,
    2392,   409,   554,    25,  2396,   549,  2398,   218,   876,   525,
     218,   555,   605,   881,   370,   437,   426,   434,   371,   409,
     564,   565,   370,   567,     5,   605,   599,    13,     5,   605,
     405,  2423,     5,    24,    29,   579,   580,  2429,    20,  1263,
     409,   370,   459,   220,   588,     5,  2152,   591,   350,   370,
    2442,   370,   469,   470,  3026,   599,  2067,  2073,  1840,  1232,
    1549,    36,    38,   365,   364,  1781,  1787,   369,   485,  2135,
    2462,   287,   141,  2465,  2466,   145,   209,   281,  2470,   396,
     353,  2473,  1328,   288,  1329,  2477,   211,  2437,  1748,   506,
     371,   316,   509,   510,   315,   383,   385,  3016,   515,     5,
    1522,  2493,  1761,  1399,   525,   407,   101,   102,   957,   104,
     105,  2503,  1648,  1641,   109,  1771,  1492,  1003,  2206,  1255,
    1258,  2534,  1572,   707,  3040,  2517,  1886,  2519,  2520,  2521,
    2522,   126,   127,   435,  1775,  1587,  2220,  2710,  1148,  2531,
    2222,    23,    29,    17,    18,    19,    20,   960,   117,   144,
     145,  2892,   454,    29,  1554,   572,  2548,  2611,  2550,   482,
     649,  1560,  1242,  2555,   266,   677,  1869,   584,  1263,  2714,
     924,  1563,  2564,  2608,  2786,  1603,  1139,  2569,    71,    72,
      73,    74,    75,    76,  1186,  2577,  2960,  2579,  2190,  1129,
    2796,   876,   776,  2363,    87,    88,    89,    71,    72,    73,
      74,    75,    76,  2361,  1765,  1214,  2345,     7,  1365,  2007,
    1014,  1061,  2770,  1342,  1943,  3044,  3008,    17,    18,    19,
      20,  1977,  2898,  2008,  2395,  1669,  2417,  2674,  2014,  2374,
    2430,  1934,  2376,   535,  2631,   819,  2914,  2629,  2815,  2631,
    1943,  2024,   730,  2635,  2306,  2637,  1949,  2834,   953,   833,
     834,   835,  1281,   837,  2835,   839,   840,  2649,  2432,  2752,
    2244,   845,   846,  2248,  1132,  1133,  1134,  3006,  2737,  2918,
    1973,    71,    72,    73,    74,    75,    76,  2875,  1277,   949,
    2564,  1701,  2674,  1144,  1152,   362,  2678,    -1,  2680,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     602,  2693,    -1,    -1,    -1,   889,  2698,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   900,    -1,    -1,    -1,
      -1,  1189,    -1,    -1,    -1,    -1,  1565,  2030,    -1,    -1,
      -1,    -1,    -1,   239,    -1,   228,    -1,    -1,   231,   923,
     924,  1565,    -1,    -1,    -1,  2737,  1214,    -1,   932,    -1,
    2742,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    -1,    -1,  1231,   948,   949,    -1,    -1,  2760,    -1,
      -1,    -1,   278,  1241,  2766,    -1,    -1,    -1,  2770,  2771,
    1619,    -1,    -1,    -1,    -1,    -1,  2778,    -1,    -1,    -1,
      -1,   297,    -1,    -1,    -1,  1619,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    42,    -1,  2801,
      71,    72,    73,    74,    75,    76,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1007,    -1,    -1,    87,    88,    89,    -1,
     336,  2823,    -1,  2825,    -1,    -1,  2828,   713,   714,  1663,
      -1,  2833,   348,  2835,    -1,    -1,  1670,    -1,    -1,    -1,
      -1,    -1,   358,   729,    -1,    -1,    -1,   350,    -1,   735,
     736,    -1,    -1,    -1,   740,    -1,    -1,    -1,    -1,    -1,
     376,    -1,   365,    -1,   750,    -1,   369,    -1,    -1,    -1,
     386,    -1,    -1,  2875,  1723,    -1,    -1,    -1,  2880,    -1,
    2882,    -1,  2884,    -1,    -1,    -1,   402,    -1,  2890,  1723,
      -1,  2893,  1315,  1316,    -1,    -1,  2898,    -1,    -1,  1322,
      -1,    -1,    -1,    -1,   407,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  2914,    -1,    -1,  2917,    -1,    -1,    -1,  2232,
    2233,    -1,    -1,    -1,    -1,  1119,   442,    -1,  2930,    -1,
      -1,    -1,   435,  1127,    -1,  1129,  1130,  1131,    -1,    -1,
      -1,    -1,    -1,    -1,  1138,  1139,    -1,    -1,  1142,    -1,
     466,   454,  1146,  2955,  2956,  1149,    -1,   228,    -1,    -1,
     231,  2963,    -1,    -1,    -1,   481,    -1,    -1,  1162,    -1,
      -1,    -1,   488,    -1,    -1,   491,    -1,    -1,    -1,    -1,
      -1,    -1,  2984,    -1,    -1,    -1,  1464,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1188,   511,    -1,    -1,   514,    -1,
     516,    -1,  3004,    -1,  3006,    -1,  3008,    -1,    -1,    -1,
    1488,    -1,    -1,    -1,  1492,  1864,    -1,    -1,    -1,   535,
      -1,  1855,  1856,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1864,    -1,   535,   278,  1228,    -1,    -1,   553,    -1,    -1,
      -1,    -1,  3044,    -1,  1522,    -1,  3048,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  2369,  1251,    -1,  3061,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1262,  1263,
    1548,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   350,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   336,    -1,    -1,   365,    -1,    -1,    -1,   369,   602,
      -1,    -1,    -1,   348,    -1,    -1,    -1,    -1,    -1,  1532,
      -1,    -1,    -1,   358,    -1,    -1,  1950,    -1,    -1,    -1,
      -1,    -1,    -1,  1317,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   376,    -1,    -1,    -1,    -1,   407,    -1,    -1,    -1,
      -1,   386,    -1,  1029,   389,  1568,    -1,    -1,    -1,    -1,
      -1,  1037,    -1,    -1,  1040,    -1,    -1,   402,    -1,    -1,
      -1,    -1,    -1,  2012,   435,    -1,    -1,  1053,    -1,    -1,
      -1,  1057,    -1,    -1,    -1,    -1,    -1,  1371,  2012,  1065,
    2014,  1067,  1068,   454,  1070,  1071,  1072,  1073,  1074,  1075,
    1076,  1077,  1078,  1079,  1080,  1081,  1082,  1083,  1084,  1085,
    1086,    -1,    -1,    -1,    -1,  2518,   451,    -1,    -1,    -1,
      -1,  1097,  1098,    -1,    -1,    -1,  1102,    -1,  1104,    -1,
    2054,    -1,    -1,    -1,    -1,    -1,    -1,  1705,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   481,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  2557,    -1,   491,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   535,    -1,   511,    -1,    -1,   514,
      -1,   516,    -1,    -1,    -1,    -1,    -1,    17,    18,    -1,
      20,    -1,    -1,    23,    24,    25,    -1,    -1,    -1,    -1,
      -1,  1769,  1770,  1771,  1772,    -1,    -1,    -1,    -1,   544,
      -1,    -1,    -1,    43,    -1,    -1,    -1,    -1,   553,    -1,
      -1,    -1,    -1,    -1,    -1,  1793,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1520,    -1,    -1,    -1,
      -1,   602,    -1,    -1,    -1,  1529,    -1,    -1,    -1,    -1,
    2189,  2190,  2191,  2192,  2193,  2194,  1540,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  2189,  2190,  2191,  2192,  2193,
    2194,    -1,    -1,    -1,    -1,    -1,  1560,    -1,    -1,    -1,
      -1,    -1,  1850,    -1,    -1,    -1,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    -1,    -1,    -1,    -1,    -1,    -1,  2248,
      -1,    -1,    -1,  1597,    -1,  1599,    -1,    -1,    -1,  1603,
      -1,  1834,  1835,    -1,  2248,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1845,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1635,    71,    72,    73,    74,    75,    76,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    87,    88,
      89,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1895,  1896,  1897,  1898,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1964,  1910,  1966,  2323,
    2324,  2325,    -1,  2327,  2328,  2329,  2330,  2331,  2332,    -1,
      -1,    -1,  2336,  1389,    -1,    -1,    -1,    -1,    -1,    -1,
    1704,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1418,  1419,  1420,    -1,  1422,    -1,  2387,    -1,
    2374,    -1,  2376,  2392,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  2387,    -1,    -1,    -1,    -1,  2392,    -1,
      -1,    -1,  1448,  1986,  1987,    -1,    -1,    -1,    -1,    -1,
    1993,  1994,  1766,    -1,  1768,    -1,    -1,    -1,    -1,  2892,
      -1,    -1,    -1,  1777,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   228,
      -1,    -1,   231,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1815,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   374,    -1,  2114,    -1,    -1,  2117,
      -1,  1527,    -1,    -1,    -1,    -1,    -1,  1533,    -1,   389,
    1844,    -1,    -1,    -1,    -1,  2489,  1542,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   406,    -1,  2517,   409,
    2519,  2520,  2521,  2522,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   422,  2517,    -1,  2519,  2520,  2521,  2522,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  2174,    -1,    -1,    -1,
      -1,  2550,  2125,  2126,    -1,    -1,    -1,    -1,    -1,    -1,
     450,  2134,    -1,    -1,    -1,    -1,  2550,    -1,    -1,  2142,
      -1,   350,   462,   463,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   475,   365,  2160,  2161,    -1,
     369,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    17,    18,    -1,    20,    -1,
      -1,    23,    24,    25,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   516,    -1,   407,    -1,
      -1,    43,    -1,    -1,    -1,    -1,  2635,    -1,  2637,  2212,
    1984,  2214,    -1,    -1,    -1,  2629,    -1,  2631,  2221,    -1,
    2223,  2635,  2636,  2637,    -1,    -1,   435,    14,    15,    16,
      17,    18,    19,    20,    21,   555,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   454,    -1,   567,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   579,
     580,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   588,    -1,
      -1,   591,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   599,
      -1,    -1,    -1,    -1,    71,    72,    73,    74,    75,    76,
    2064,    -1,    -1,  1759,    -1,  1761,    -1,    -1,    -1,    -1,
      87,    88,    89,    -1,  2718,    -1,    -1,    -1,  2737,    -1,
    2313,  2314,    -1,  2742,  2317,  2318,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  2737,    -1,    -1,   535,    -1,  2742,    -1,
      -1,    -1,    -1,    -1,  2108,    -1,    -1,  2766,    -1,    -1,
      -1,    -1,  2771,    -1,    -1,   107,    -1,    -1,  2351,    -1,
      -1,    -1,  2766,    -1,   116,    -1,    -1,  2771,    -1,    -1,
      -1,    -1,    -1,   125,    -1,    -1,    -1,  2141,   130,    -1,
      -1,    -1,  2801,    -1,    -1,    -1,  2150,    -1,  2152,    -1,
    2154,    -1,    -1,    -1,    -1,    -1,    -1,  2801,    -1,    -1,
      -1,    -1,  2166,   602,    -1,    -1,    -1,    -1,    -1,  2828,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   174,    -1,  2828,  2473,    -1,    -1,    -1,    -1,
     182,    -1,    -1,    -1,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      -1,   228,    -1,    -1,   231,  2503,    -1,    -1,    -1,    -1,
      -1,  2880,    -1,  2882,    -1,  2884,    -1,    -1,    -1,    -1,
    2463,    -1,    -1,    -1,  2467,    -1,  2880,    -1,  2882,    -1,
    2884,    -1,    -1,  2531,    -1,    -1,   238,    -1,    -1,  2893,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2917,    71,
      72,    73,    74,    75,    76,    -1,  2499,    -1,    -1,    -1,
    2914,   263,    -1,  2917,  2918,    87,    88,    89,   270,    -1,
     272,    -1,    22,    -1,    -1,    -1,  2930,    -1,    -1,    -1,
     282,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2532,
      -1,    41,   374,  2307,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,   308,   389,    -1,    -1,
      -1,    -1,    -1,    -1,   316,  2984,    -1,    -1,    -1,    -1,
      70,    -1,    -1,   350,   406,    -1,    -1,   409,    -1,    -1,
    2984,    -1,    -1,  2347,    -1,    -1,    -1,  3006,   365,    -1,
     422,    -1,   369,    -1,    -1,    -1,  2360,    -1,    -1,    -1,
      -1,   353,  3006,    -1,    -1,    71,    72,    73,    74,    75,
      76,    -1,   112,    -1,    -1,    -1,    -1,  2073,   450,    -1,
      -1,    87,    88,    89,    -1,  3044,    -1,   379,    -1,  3048,
     407,   463,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    3044,    -1,   142,   475,  3048,    -1,   146,    -1,    -1,    -1,
    2698,    -1,    -1,    -1,    -1,    -1,   228,  2421,   435,   231,
      -1,    -1,    -1,    -1,    -1,   417,    -1,    -1,    -1,    -1,
     170,    -1,  3076,    -1,    -1,    -1,   428,   454,   178,    -1,
     180,    -1,    -1,    -1,   516,  2449,    -1,    -1,    -1,   189,
    2146,    -1,    -1,  2149,    -1,   195,    -1,    -1,    -1,    -1,
    2464,  2157,    -1,   203,    -1,    -1,    -1,   207,    -1,    -1,
      -1,    -1,    -1,   213,    -1,    -1,    -1,   217,   218,   219,
     220,    -1,    -1,   555,    -1,  2489,    -1,    -1,    -1,    -1,
      -1,    -1,   232,    -1,    -1,   567,  2729,    -1,    -1,    -1,
      -1,  2505,    -1,    -1,    -1,    -1,    -1,   579,   580,   249,
      -1,    -1,   252,    -1,   254,    -1,   588,    -1,   535,   591,
      -1,   261,   228,    -1,    -1,   231,    -1,   599,    -1,    -1,
      -1,    -1,    -1,    -1,   274,   527,   528,   529,   350,    -1,
      -1,    -1,    -1,    -1,   284,    -1,    -1,    -1,   540,    -1,
      -1,    -1,    -1,   365,    -1,    -1,    -1,   369,   370,    -1,
      -1,    -1,  2566,   303,   304,    17,    18,    -1,    20,    -1,
      -1,    23,    24,    25,    -1,    -1,    -1,    -1,   318,    -1,
      -1,    -1,    -1,    -1,    -1,   602,   326,    -1,    -1,    -1,
     330,    43,    -1,    -1,    -1,   407,    -1,    -1,    -1,   339,
     340,   341,    -1,    -1,  2608,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   435,    -1,    -1,    -1,  2860,    -1,    -1,
      -1,    17,    18,    19,    20,    -1,    -1,    -1,    -1,    -1,
      26,    -1,   454,    -1,   350,    -1,    -1,    -1,    -1,    52,
      53,    -1,   644,    56,    57,    58,    -1,    -1,    -1,   365,
      -1,    -1,    -1,   369,    -1,    -1,    -1,  2955,   408,    -1,
    2903,  2904,    -1,  2906,    -1,  2908,  2909,    -1,    -1,   419,
      -1,    -1,    -1,    -1,    -1,    71,    72,    73,    74,    75,
      76,    -1,  2696,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   407,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2713,
    2714,    -1,    -1,    -1,  2718,    -1,    -1,    -1,    -1,    -1,
     460,    -1,    -1,   535,    -1,    -1,    -1,    -1,    -1,   435,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2972,
      -1,    -1,    -1,    -1,    -1,    -1,  2442,    -1,   454,    -1,
      -1,    -1,    -1,   156,    -1,    -1,    -1,    -1,    -1,  2992,
     163,  2994,    -1,    -1,    -1,    -1,    -1,    -1,  2772,    -1,
      -1,    -1,    -1,  3061,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   521,  2786,    -1,    -1,    -1,    -1,  2791,    -1,  2793,
     602,    -1,    -1,    -1,   197,    -1,    -1,  2493,  3031,    -1,
      -1,    -1,   239,   206,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   557,    -1,    -1,
      -1,   273,  3055,  3056,    -1,    -1,  3059,    -1,    -1,   535,
    2834,    -1,   235,   236,    -1,    -1,  2840,    -1,    -1,    -1,
      -1,   278,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     297,    -1,    -1,    -1,   604,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   259,    -1,    -1,    -1,   280,   618,   619,
     620,   621,   622,   623,   624,    -1,   626,   627,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   602,    -1,    -1,   336,
      -1,    -1,    -1,   643,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   348,    -1,   299,   300,   301,    -1,    -1,    -1,   322,
      -1,   358,   374,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   389,   324,   376,
    2944,  2945,  2946,  2947,  2948,  2949,   332,    -1,    -1,   386,
      -1,   337,    -1,    -1,   406,    -1,    -1,   409,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   402,   352,    -1,    -1,   421,
     422,   357,    -1,   359,    -1,   378,    -1,    -1,    -1,    -1,
     366,    -1,    -1,   369,    -1,    -1,   372,    -1,    -1,   375,
      -1,    -1,   378,    -1,    -1,    -1,    -1,   383,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   442,    -1,    -1,    -1,    -1,
      -1,   463,    -1,    -1,    -1,   401,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   475,    -1,    -1,    -1,    -1,    -1,   466,
      -1,   417,    -1,    -1,   420,   421,    -1,    -1,    -1,    -1,
      -1,   427,    -1,    -1,   481,    -1,    -1,    -1,    -1,    -1,
      -1,   488,   438,    -1,   491,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   516,    -1,    -1,    -1,   454,    -1,
      -1,    -1,  3076,    -1,   511,   461,    -1,   514,    -1,   516,
      -1,    -1,   468,    -1,    -1,   471,   472,   473,    -1,   475,
     476,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   535,    -1,
      -1,    -1,    -1,   555,    -1,    -1,   492,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   567,   553,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   579,   580,   515,
     516,   517,   518,    -1,   520,    -1,   588,    -1,    -1,   591,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   599,    -1,    29,
      -1,   537,   538,    33,    34,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    46,    -1,    48,    -1,
      -1,    -1,    -1,    -1,   560,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    62,   569,   570,    -1,   572,    -1,    -1,    69,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      80,    81,    82,    -1,   607,   608,   609,   610,   611,   612,
     613,   614,   615,   616,    -1,    -1,    96,    -1,    98,    99,
     100,   101,   102,   103,   104,   105,   106,    -1,   108,   109,
     110,   111,    -1,    -1,    -1,    -1,    -1,   117,    -1,    -1,
     120,    -1,   122,   123,   124,    -1,   126,   127,   634,    -1,
      -1,    -1,   132,    -1,   134,   135,    -1,   137,    -1,   139,
     140,    -1,    -1,   143,   144,   145,    -1,  2963,   148,   149,
     150,    -1,   152,   153,    -1,    -1,    -1,   157,   158,    -1,
     160,    -1,    -1,    -1,   164,    -1,   166,   167,    -1,    -1,
      -1,    -1,   172,    -1,    -1,    -1,   176,    -1,    -1,   179,
      -1,   181,    -1,   183,    -1,   185,    -1,   187,   188,    -1,
     190,   191,   192,    -1,    -1,    -1,   196,    -1,   198,   199,
      -1,   201,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   209,
     210,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   222,    -1,    -1,   225,   226,    -1,    -1,   229,
     230,    -1,    -1,   233,   234,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   242,   243,   244,    -1,   246,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   256,   257,   258,    -1,
     260,    -1,    -1,    -1,   264,   265,    -1,    -1,    -1,   269,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   277,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   285,   286,   287,    -1,    -1,
      -1,    -1,    -1,   293,   294,    -1,    -1,    -1,    -1,   299,
      -1,    -1,   302,    -1,    -1,    -1,   306,   307,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   317,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    -1,   335,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   343,    -1,    -1,    -1,    -1,    -1,   349,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    -1,    -1,    -1,    -1,
      -1,    -1,   372,    -1,    -1,    -1,    -1,    -1,    -1,   379,
      -1,   381,   382,    71,    72,    73,    74,    75,    76,    -1,
     390,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    87,
      88,    89,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    71,    72,    73,    74,    75,
      76,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   429,
      -1,    87,    88,    89,    -1,    -1,    -1,    -1,    -1,    -1,
     440,    -1,    -1,    -1,   444,    -1,    -1,    -1,   448,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   472,   473,    -1,    -1,    -1,   477,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   489,
      -1,    -1,    -1,    -1,    -1,   495,   496,   497,   498,    -1,
      -1,   501,    -1,    -1,    -1,   505,    -1,    -1,    -1,    -1,
      -1,    -1,   512,   513,    71,    72,    73,    74,    75,    76,
      -1,    -1,    -1,    -1,   524,    -1,   526,    -1,    -1,    -1,
      87,    88,    89,    -1,    -1,    -1,    -1,   537,    -1,   539,
     228,    -1,   542,   231,    -1,    -1,    -1,    -1,   548,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   228,    -1,   574,   231,    -1,   577,    -1,    -1,
      -1,    -1,    -1,   583,    -1,    -1,   586,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   601,    -1,    -1,    -1,    -1,    -1,    -1,   608,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   631,   632,   633,   634,   635,   636,   637,    -1,    -1,
     640,    -1,   642,    -1,   644,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   350,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   228,    -1,    -1,   231,    -1,    -1,   365,    -1,    -1,
      -1,   369,   370,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   350,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   365,
      -1,    -1,    -1,   369,   370,    -1,    -1,    -1,    -1,   407,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   435,    -1,    -1,
      -1,   407,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   454,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   435,
      -1,    -1,    -1,    -1,    -1,    71,    72,    73,    74,    75,
      76,    -1,    -1,   350,    -1,    -1,    -1,    -1,   454,    -1,
      -1,    87,    88,    89,    -1,    -1,    -1,    -1,   365,    -1,
      -1,    -1,   369,   370,    -1,    -1,    -1,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   535,    -1,    -1,
     407,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   435,   535,
      -1,    -1,    71,    72,    73,    74,    75,    76,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   454,    87,    88,
      89,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   602,    -1,    71,    72,    73,    74,
      75,    76,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    87,    88,    89,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   228,    -1,    -1,   231,   602,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   535,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    71,    72,    73,    74,    75,    76,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    87,    88,
      89,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   228,
      -1,    -1,   231,    -1,    -1,   602,    -1,    -1,    -1,    -1,
      -1,    71,    72,    73,    74,    75,    76,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   350,    -1,    -1,    87,    88,    89,
      -1,    -1,    -1,   228,    -1,    -1,   231,    -1,    -1,   365,
      -1,    -1,    -1,   369,   370,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   407,    -1,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   435,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   350,    -1,    -1,    -1,    -1,    -1,    -1,   454,   228,
      -1,    -1,   231,    -1,    -1,    -1,   365,    -1,    -1,    -1,
     369,   370,    -1,    -1,    -1,    -1,    -1,    71,    72,    73,
      74,    75,    76,    -1,    -1,   350,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    87,    88,    89,    -1,    -1,   228,    -1,
     365,   231,    -1,    -1,   369,   370,    -1,    -1,   407,    -1,
      -1,    -1,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   435,    -1,    -1,   535,
      -1,    -1,   407,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   454,    17,    18,    19,    20,
      21,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     435,    -1,    -1,    -1,    -1,    71,    72,    73,    74,    75,
      76,   350,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   454,
      -1,    87,    88,    89,    -1,    -1,   365,    -1,    -1,    -1,
     369,   370,    -1,    -1,    -1,    -1,   602,    -1,    -1,    -1,
      71,    72,    73,    74,    75,    76,    -1,    -1,    -1,    -1,
     350,    -1,    -1,    -1,    -1,    -1,    87,    88,    89,    -1,
      -1,    -1,    -1,    -1,   228,   365,   535,   231,   407,   369,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    -1,    -1,    -1,    -1,   435,    -1,    -1,    -1,
     535,    -1,    -1,    -1,    -1,    -1,    -1,   407,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   454,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    -1,    -1,    -1,
      -1,    -1,    -1,   602,    -1,   435,    -1,    -1,    -1,    -1,
      -1,    71,    72,    73,    74,    75,    76,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   454,    -1,    -1,    87,    88,    89,
      -1,    -1,   228,    -1,    -1,   231,    -1,   602,    -1,    16,
      17,    18,    19,    20,    21,    -1,    71,    72,    73,    74,
      75,    76,    -1,    -1,    -1,    -1,   350,    -1,    -1,    -1,
      -1,    -1,    87,    88,    89,    -1,   535,   228,    -1,    -1,
     231,   365,    -1,    -1,    -1,   369,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    71,    72,    73,    74,    75,    76,
      -1,    -1,    -1,    -1,    -1,   535,    -1,    -1,    -1,    -1,
      87,    88,    89,   407,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   602,    71,    72,    73,    74,    75,    76,
      -1,   435,    -1,    -1,    -1,    19,    20,    21,    -1,    -1,
      87,    88,    89,    -1,   350,    -1,    -1,    -1,    -1,    -1,
     454,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   228,   365,
      -1,   231,   602,   369,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   350,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    71,    72,    73,
      74,    75,    76,   228,   365,    -1,   231,    -1,   369,    -1,
      -1,   407,    -1,    87,    88,    89,    -1,    17,    18,    -1,
      -1,    -1,    -1,    23,    24,    25,    26,    17,    18,    -1,
      20,    -1,    -1,    23,    24,    25,    -1,    -1,    38,   435,
      -1,   535,    -1,    43,    44,    -1,   407,    -1,    -1,    -1,
      50,   228,    -1,    43,   231,    -1,    -1,    -1,   454,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   435,    -1,    -1,    -1,    78,    -1,
      -1,    20,    21,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     350,   228,    -1,   454,   231,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   365,    -1,    -1,   602,   369,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   350,    -1,    -1,    -1,    -1,
      -1,    -1,    71,    72,    73,    74,    75,    76,    -1,   535,
     365,    -1,    -1,    -1,   369,    -1,    -1,   407,    87,    88,
      89,    -1,    -1,    -1,   228,    -1,    -1,   231,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   171,    -1,   350,   535,   435,    -1,    -1,    -1,    -1,
      -1,    -1,   407,    -1,    -1,    -1,    -1,    -1,   365,    -1,
      -1,    -1,   369,    -1,   454,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   602,    -1,    -1,    -1,
     435,    -1,    -1,   350,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   365,   454,
     407,    -1,   369,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   602,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    17,    18,    -1,    -1,    -1,   435,    23,
      24,    25,    26,    -1,    -1,    -1,    -1,    -1,   268,    -1,
     407,    -1,    -1,   273,    38,   535,   350,   454,    -1,    43,
      44,    -1,    -1,    -1,    -1,    -1,    50,    -1,    -1,   228,
      -1,   365,   231,    -1,    -1,   369,    -1,    -1,   435,    -1,
      -1,   301,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     535,    -1,    -1,    -1,    78,    -1,    -1,   454,    -1,    -1,
      17,    18,    -1,    -1,    -1,    -1,    23,    24,    25,    -1,
      -1,    -1,    -1,   407,    -1,    -1,   336,    -1,    -1,    -1,
      -1,    38,   602,    -1,    -1,    -1,    43,    44,   348,    -1,
      -1,    -1,    -1,    50,    -1,    -1,    -1,    -1,   535,    -1,
      -1,   435,    -1,    -1,    -1,    -1,   366,    -1,    -1,    -1,
      -1,   371,    -1,    -1,   374,    -1,    -1,   602,    -1,    -1,
     454,    78,    -1,    -1,   374,   385,    -1,    17,    18,    -1,
      -1,   391,    -1,    23,    24,    25,    -1,    -1,   535,   389,
      -1,   401,    -1,    -1,    -1,    -1,   406,   171,    38,   409,
      -1,   350,   412,    43,    44,    -1,   406,    -1,    -1,   409,
      50,   421,   422,    -1,    -1,   602,   365,    -1,    -1,    -1,
     369,    -1,   422,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    78,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   535,   462,   463,    -1,   602,    -1,   467,   407,    -1,
      -1,    -1,   462,   463,   171,   475,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   475,   486,    -1,    -1,    -1,
      -1,    -1,   492,    -1,    -1,    -1,   435,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   268,    -1,    -1,    -1,    -1,   273,
      -1,    -1,    -1,    -1,    -1,   454,   516,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    17,    18,   516,    -1,   602,    -1,
      23,    24,    25,    -1,    -1,    -1,    -1,   301,    -1,    -1,
      -1,   171,    -1,    -1,    -1,    38,    -1,    -1,    -1,    -1,
      43,    44,    -1,    -1,    -1,    -1,    -1,    50,    -1,    -1,
     560,    -1,    -1,    -1,    -1,   555,    -1,   567,    -1,   569,
      -1,   268,   336,    -1,    -1,    -1,   273,   567,    -1,   579,
     580,   581,    -1,    -1,   348,    78,    -1,    -1,   588,   579,
     580,   591,    -1,    -1,    -1,    -1,   535,    -1,   588,   599,
      -1,   591,   366,    -1,   301,    -1,    -1,   371,    -1,   599,
     374,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   385,    -1,    -1,    -1,    -1,    -1,   391,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   401,   268,   336,
      -1,    -1,   406,   273,    -1,   409,    -1,    -1,   412,    -1,
      -1,   348,    -1,    -1,    -1,    -1,    -1,   421,   422,    17,
      18,    -1,    -1,   602,    -1,    23,    24,    25,    -1,   366,
      -1,   301,    -1,    -1,   371,    -1,    -1,   374,   171,    -1,
      38,    -1,    -1,    -1,    -1,    43,    44,    -1,   385,    -1,
      -1,    -1,    50,    -1,   391,    -1,    -1,    -1,    -1,   463,
      -1,    -1,    -1,   467,   401,    -1,   336,    -1,    -1,   406,
      -1,   475,   409,    -1,    -1,   412,    -1,    -1,   348,    -1,
      78,    -1,   486,    -1,   421,   422,    -1,    -1,   492,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   366,    -1,    -1,    -1,
      -1,   371,    -1,    -1,   374,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   516,    -1,    -1,   385,    -1,    -1,    -1,    -1,
      -1,   391,    -1,    -1,    -1,   462,   463,    -1,    -1,    -1,
     467,   401,    -1,    -1,    -1,   268,   406,    -1,   475,   409,
     273,    -1,   412,    -1,    -1,    -1,    -1,    -1,    -1,   486,
      -1,   421,   422,    -1,    -1,   492,   560,    -1,    -1,    -1,
      -1,    -1,    -1,   567,    -1,   569,    -1,    -1,   301,    -1,
      -1,    -1,    -1,   171,    -1,   579,   580,   581,    -1,   516,
      -1,    -1,    -1,    -1,   588,    -1,    -1,   591,    -1,    -1,
      -1,    -1,    -1,   463,    -1,   599,    -1,   467,    -1,    -1,
      -1,    -1,    -1,   336,    -1,   475,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   348,   486,    -1,   488,    -1,
      -1,    -1,   492,   560,    -1,    -1,    -1,    -1,    -1,    -1,
     567,    -1,   569,   366,    -1,    -1,    -1,   370,   371,    -1,
      -1,   374,   579,   580,   581,    -1,   516,    -1,    -1,    -1,
      -1,   588,   385,    -1,   591,    -1,    -1,    -1,   391,    -1,
      -1,    -1,   599,    -1,    -1,    -1,    -1,    -1,   401,    -1,
     268,    -1,    -1,   406,    -1,   273,   409,    -1,    -1,   412,
      -1,    -1,    -1,    -1,    -1,    -1,    17,    18,   421,   422,
     560,    -1,    23,    24,    25,    -1,    -1,   567,    -1,   569,
      -1,    -1,    -1,   301,    -1,    -1,    -1,    38,    -1,   579,
     580,   581,    43,    44,    -1,    -1,    -1,    -1,   588,    50,
      -1,   591,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   599,
     463,    -1,    -1,    -1,   467,    -1,    -1,    -1,   336,    -1,
      -1,    -1,   475,    -1,    -1,    -1,    -1,    78,    17,    18,
     348,    20,    -1,   486,    23,    24,    25,    -1,    -1,   492,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   366,    -1,
      -1,    -1,    -1,   371,    43,    -1,   374,    -1,    -1,    -1,
      -1,    -1,    -1,   516,    -1,    -1,    -1,   385,    -1,    -1,
      -1,    -1,    -1,   391,    17,    18,    -1,    20,    -1,    -1,
      23,    24,    25,   401,    -1,    -1,    -1,    -1,   406,    -1,
      -1,   409,    -1,    -1,   412,    -1,    -1,    -1,    -1,    -1,
      43,    -1,    -1,   421,   422,    17,    18,   560,    20,    -1,
      -1,    23,    24,    25,   567,    -1,   569,    -1,    -1,    -1,
     171,    -1,    -1,    -1,    -1,    -1,   579,   580,   581,    -1,
      -1,    43,    -1,    -1,    -1,   588,    -1,    -1,   591,    -1,
      -1,    -1,    -1,    -1,   462,   463,   599,    -1,    -1,   467,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   475,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   486,    -1,
      -1,    -1,    -1,    -1,   492,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    17,    18,    -1,    20,    -1,    -1,    23,    24,
      25,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   516,    -1,
      -1,    -1,    -1,    -1,    17,    18,    -1,    20,    43,    -1,
      23,    24,    25,    -1,    -1,    -1,    -1,   268,    -1,    -1,
      -1,    -1,   273,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      43,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   560,    -1,    -1,    -1,    -1,    -1,    -1,   567,
     301,   569,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   579,   580,   581,    -1,    -1,    -1,    -1,    -1,    -1,
     588,    -1,    -1,   591,    -1,    -1,    -1,    21,    -1,    -1,
      -1,   599,    -1,    -1,   273,   336,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   348,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   366,    -1,    -1,    -1,    -1,
     371,    -1,    -1,   374,    -1,    -1,    -1,    71,    72,    73,
      74,    75,    76,    -1,   385,    -1,    -1,    31,    -1,    -1,
     391,    -1,    -1,    87,    88,    89,    -1,    -1,    -1,    -1,
     401,    -1,    -1,    -1,    -1,   406,    -1,    -1,   409,    -1,
      -1,   412,    -1,    -1,    -1,    59,    60,    -1,    -1,    -1,
     421,   422,    -1,    -1,    68,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   374,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     389,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   463,    -1,    -1,    -1,   467,   406,    -1,    -1,
     409,    -1,    -1,    -1,   475,    -1,    -1,    -1,    -1,    -1,
      -1,   374,   421,   422,    -1,   486,    -1,    -1,    -1,    -1,
      -1,   492,    -1,    -1,    -1,    -1,   389,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   374,   406,    -1,   516,   409,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   463,    -1,    -1,   389,    -1,   422,
      -1,    -1,    -1,    -1,   228,    -1,   475,   231,    -1,    -1,
      -1,    -1,    -1,    -1,   406,    -1,    -1,   409,    -1,    -1,
      77,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   560,
     422,    -1,    -1,    -1,    -1,    -1,   567,    -1,   569,   462,
     463,    -1,    -1,    -1,    -1,    -1,    -1,   516,   579,   580,
     581,    -1,   475,    -1,    -1,    -1,    -1,   588,    -1,   374,
     591,    -1,    -1,    -1,    -1,   239,    -1,    -1,   599,    -1,
     462,   463,    -1,    -1,   389,    -1,    -1,    -1,    -1,    -1,
      -1,   374,    -1,   475,    -1,    -1,   555,    -1,    -1,    -1,
      -1,   406,    -1,   516,   409,    -1,   389,    -1,   567,    -1,
      -1,    -1,    -1,    -1,   278,    -1,    -1,   422,    -1,    -1,
     579,   580,   581,   406,    -1,    -1,   409,    -1,    -1,   588,
      -1,    -1,   591,   297,   516,   182,   350,    -1,    -1,   422,
     599,    -1,   555,    -1,    -1,    -1,    -1,    -1,    -1,   313,
      -1,   365,    -1,    -1,   567,   369,    -1,   462,   463,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   579,   580,    -1,    -1,
     475,    -1,   336,   555,    -1,   588,    -1,    -1,   591,    -1,
     463,    -1,    -1,    -1,   348,   567,   599,    -1,    -1,    -1,
      -1,   238,   475,   407,   358,    -1,    -1,   579,   580,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   588,    -1,    -1,   591,
      -1,   516,   376,    -1,    -1,    -1,   263,   599,    -1,    -1,
      -1,   435,   386,    -1,    -1,   272,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   516,    -1,    -1,    -1,    -1,   402,    -1,
     454,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     555,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   308,   567,    -1,   311,    -1,    -1,    -1,    -1,   316,
      -1,    -1,   555,    -1,   579,   580,    -1,   324,   442,    -1,
      -1,    -1,    -1,   588,   567,    -1,   591,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   599,    -1,   579,   580,    -1,    -1,
      -1,    -1,   466,    -1,    -1,   588,    -1,    -1,   591,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   599,   481,    -1,    -1,
      -1,   535,    -1,    -1,   488,    -1,    -1,   491,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   388,    -1,    -1,    -1,    -1,    -1,   511,   395,    -1,
     514,    -1,   516,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   410,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   535,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   434,   602,   553,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   459,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   469,   470,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   596,    -1,    -1,    -1,    -1,    -1,   485,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   506,
      -1,    -1,   509,   510,    -1,    -1,    -1,    -1,   515,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   572,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   582,    -1,   584
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const unsigned short yystos[] =
{
       0,    29,    54,   101,   102,   104,   105,   109,   126,   127,
     144,   145,   215,   335,   384,   416,   705,   733,   734,   784,
     952,  1007,  1009,  1010,  1011,  1016,  1018,  1031,  1032,  1033,
    1034,  1035,  1437,    27,    28,   706,   707,   708,   709,   710,
     915,   919,   334,   512,   526,   551,   600,  1438,  1438,  1438,
    1438,  1438,  1438,  1438,  1438,   915,    24,   915,  1381,  1036,
     735,   734,  1437,     0,  1008,  1011,  1016,  1034,  1437,    30,
     708,   710,    26,  1456,   915,  1440,   568,   915,  1439,   605,
     785,    24,   591,   732,   733,   903,   915,   922,  1037,  1073,
    1074,  1075,  1076,  1077,  1081,   332,   737,   738,   739,   740,
     743,   744,    39,    84,    85,    92,   346,   372,   443,   536,
     617,   625,   705,   711,   875,   951,  1012,  1013,  1015,  1019,
    1020,  1026,  1038,  1059,  1190,  1200,  1437,   920,   915,  1439,
     596,  1076,   221,   436,   437,  1082,    20,   915,  1080,   919,
     738,     5,   736,   332,   915,     5,   760,   762,   763,  1201,
     915,   915,  1191,  1027,   915,   915,  1015,  1021,   239,   278,
     297,   336,   348,   358,   376,   386,   402,   442,   466,   481,
     488,   491,   511,   514,   516,   535,   553,   786,   787,   788,
     791,    24,  1073,  1079,    17,    18,    25,   409,   655,   657,
    1073,  1083,  1084,   437,   599,    13,   783,   740,   500,  1177,
     741,   738,   743,    31,    59,    60,    68,   239,   278,   297,
     313,   336,   348,   358,   376,   386,   402,   442,   466,   481,
     488,   491,   511,   514,   516,   535,   553,   596,   746,   754,
     765,   766,   915,   409,    91,   915,   732,   876,  1060,   915,
     793,   514,   745,   769,   771,   772,   770,   779,   780,   409,
     409,   792,   437,   409,   409,   738,   767,   404,   655,    17,
      18,    19,    20,    21,   656,    25,     5,   405,  1083,    23,
      24,    25,   599,   915,   923,    18,    24,    25,   742,   923,
     756,   745,   757,   769,   770,   409,   409,   755,   437,   409,
     409,   767,   738,   764,   409,    25,   915,   409,  1028,   732,
     732,   409,   915,   409,   436,   749,   605,   345,   432,   449,
     492,   531,   560,   569,   773,   605,   345,   432,   449,   492,
     531,   560,   569,   781,    25,    25,   794,   795,   796,   797,
     915,    25,   752,   753,    25,    25,   599,   370,   655,  1084,
     437,   405,    25,    25,   738,   749,   738,    25,    25,   737,
     752,    25,    25,   599,    37,   761,  1202,   370,   409,  1192,
    1457,  1458,  1459,  1460,  1461,   877,  1061,  1022,   599,    25,
     774,   775,   409,   776,   781,   782,   776,   409,   777,     5,
     370,     5,   370,     5,   262,     5,   786,   405,     5,     5,
     370,   370,   738,   768,  1083,   599,    25,   237,     5,   370,
       5,   370,   262,   405,     5,   370,   370,   768,   915,  1089,
    1090,  1092,  1039,  1089,   340,  1458,  1177,    33,    34,    46,
      48,    62,    69,    80,    81,    82,    96,    98,    99,   100,
     103,   106,   108,   110,   111,   117,   120,   122,   123,   124,
     132,   134,   135,   137,   139,   140,   143,   148,   149,   150,
     152,   153,   157,   158,   160,   164,   166,   167,   172,   176,
     179,   181,   183,   185,   187,   188,   190,   191,   192,   196,
     198,   199,   201,   209,   210,   222,   225,   226,   229,   230,
     233,   234,   242,   243,   244,   246,   256,   257,   258,   260,
     264,   265,   269,   277,   285,   286,   287,   293,   294,   299,
     302,   306,   307,   317,   335,   343,   349,   379,   381,   382,
     390,   429,   440,   444,   448,   472,   473,   477,   489,   495,
     496,   497,   498,   501,   505,   512,   513,   524,   526,   537,
     539,   542,   548,   574,   577,   583,   586,   601,   608,   631,
     632,   633,   634,   635,   636,   637,   640,   642,   644,   648,
     649,   650,   651,   668,   690,   704,   705,   711,   712,   731,
     799,   800,   801,   802,   813,   814,   815,   816,   867,   871,
     901,   925,   926,   929,   930,   931,   932,   945,   953,   976,
     977,   979,   983,   998,   999,  1003,  1004,  1005,  1006,  1014,
    1029,  1042,  1053,  1054,  1055,  1066,  1069,  1105,  1108,  1110,
    1116,  1117,  1120,  1123,  1126,  1128,  1130,  1132,  1139,  1144,
    1148,  1149,  1161,  1162,  1165,  1171,  1172,  1173,  1198,  1213,
    1214,  1215,  1216,  1217,  1227,  1228,  1229,  1247,  1250,  1290,
    1291,  1382,  1383,  1413,  1414,  1421,  1437,  1441,  1446,  1448,
    1450,  1454,  1455,  1462,   705,  1017,  1437,   604,   627,  1062,
    1063,  1089,    20,   370,   404,   750,   773,    25,   778,    25,
      25,    25,   795,   797,   789,   753,    25,   405,    20,   750,
     409,    25,    25,   747,    25,   599,   370,     5,  1089,   370,
     915,   916,   919,   915,   910,   916,   910,    24,   591,   915,
    1102,  1432,  1433,  1434,   915,  1452,   915,  1223,  1224,   915,
      25,   652,  1073,  1220,   910,   915,  1146,   842,    25,   923,
    1185,  1186,  1185,    17,    18,    24,    25,    38,    43,    44,
      50,    78,   171,   268,   273,   301,   336,   348,   366,   371,
     374,   385,   391,   401,   406,   409,   412,   421,   422,   463,
     467,   475,   486,   492,   516,   560,   567,   569,   579,   580,
     581,   588,   817,   824,   825,   826,   827,   828,   829,   830,
     831,   843,   848,   859,   860,   861,   862,   915,   923,  1073,
    1180,  1249,  1373,   916,  1422,  1422,   803,  1146,   910,  1218,
    1073,   912,   916,   824,  1422,  1073,  1146,  1073,  1248,  1422,
      24,   564,  1056,  1057,  1073,   910,   910,  1056,   911,   916,
     915,  1057,   910,  1422,   910,   912,  1073,  1103,  1104,   908,
     916,   912,   353,   540,   646,   907,   915,   978,   915,   713,
     913,   916,  1432,  1070,   842,   916,  1129,   872,   107,   116,
     125,   130,   174,   182,   238,   263,   270,   272,   282,   308,
     316,   353,   379,   417,   428,   527,   528,   529,   540,   644,
     990,  1124,  1125,  1073,   823,   824,  1138,   819,   842,   907,
    1447,  1447,   909,   916,   842,    24,  1073,  1127,  1199,  1073,
    1176,    24,  1073,  1416,   824,  1167,  1168,  1169,  1178,  1179,
     824,  1442,    44,    83,   133,   171,   268,   344,   385,   453,
     516,   669,   848,   915,  1073,  1208,   692,   824,   908,  1439,
    1043,   824,   908,   824,  1073,  1000,   908,   824,   824,  1185,
     915,   927,   928,   912,   927,  1447,   912,   927,  1447,   933,
     927,    24,    25,   363,   466,   923,   981,  1073,  1091,  1093,
      45,   253,   323,   368,   547,   628,   629,   630,   639,   659,
     935,   937,   939,   941,   943,  1067,  1068,  1072,   314,   325,
     377,   392,   482,  1292,   619,   620,   879,   880,   881,   915,
    1064,   626,  1063,   370,   281,   370,   370,   370,   370,   603,
       5,   370,   281,   738,   758,   759,   370,   370,   603,   370,
     915,  1203,  1092,   370,  1193,    35,    36,    63,    64,    65,
     433,   520,   563,  1230,  1231,  1232,  1235,  1238,  1241,  1242,
    1243,  1244,   328,   917,  1456,   599,  1434,   437,   596,  1121,
     599,     8,   517,   566,     5,   370,   405,    24,   915,  1367,
     458,  1147,  1091,    87,    88,    89,   817,   817,   409,   504,
    1197,   409,   409,   409,   409,   409,   409,   409,   409,   409,
     409,   817,   345,   432,   449,   492,   531,   560,   569,  1376,
    1377,   409,   409,   409,   817,   817,   409,   409,   729,   817,
     409,   832,   409,   409,   409,   409,   409,   409,   409,   817,
     409,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    71,    72,    73,
      74,    75,    76,    87,    88,    89,   228,   231,   350,   365,
     369,   407,   435,   454,   535,   602,   728,   818,   833,   835,
     836,   837,   838,   839,   840,   841,    25,   923,   409,   399,
    1073,  1098,  1367,   658,   659,   806,   245,    66,    67,   605,
     438,     5,   598,   605,   597,   597,  1106,   574,   399,     5,
     535,   954,   438,   638,  1444,   409,   437,   599,   638,   363,
     715,  1073,   525,   597,  1111,  1112,  1113,   305,  1289,   823,
     822,   824,     8,   909,    25,   480,   533,   902,  1073,   902,
     902,   902,   995,   996,   902,   902,   575,   991,   659,   991,
     991,   903,   903,   991,   991,   659,     5,   312,   364,     5,
     658,   462,   820,   821,   824,     5,    55,    61,   518,   606,
     984,   641,  1445,   823,   592,   593,   594,   595,  1175,  1177,
     362,  1212,  1177,  1169,     5,   597,  1170,   824,   409,   409,
     409,   409,   409,    24,   688,   915,   409,  1416,   323,   409,
     568,   557,   693,   700,   691,    24,  1058,  1073,  1163,     8,
    1166,    13,   915,  1078,  1085,  1086,  1088,  1096,  1097,  1140,
     141,   323,   523,   556,   554,     5,   638,   638,   822,  1091,
    1098,   980,   399,     5,   129,   958,   409,  1073,   822,   409,
      25,    25,    45,  1071,    24,  1073,  1420,  1420,   909,  1129,
     909,    97,   200,   208,   214,   216,   227,   255,   271,   276,
     288,   295,   450,   457,   479,   484,  1251,  1262,  1263,  1271,
    1280,  1281,  1287,  1288,  1293,  1294,  1303,  1321,  1325,  1393,
    1394,  1423,  1424,  1427,  1428,   882,   883,    70,   878,   889,
     890,   881,  1065,  1457,  1023,   437,   786,   753,   437,     5,
     370,   760,   732,  1040,   732,   136,   275,   351,   409,   471,
    1309,  1320,   409,   915,  1246,    25,   224,   237,   409,   455,
     471,   915,  1226,  1240,  1307,  1308,  1313,  1315,  1317,   409,
     915,  1237,   409,  1226,  1233,     5,   409,   920,  1434,  1083,
    1432,   555,   596,  1122,    20,   915,  1102,  1435,   915,  1453,
    1224,   574,   599,   568,   409,   409,   806,   907,   817,   846,
     907,   907,   907,  1447,   450,  1397,   817,    24,    25,    18,
      23,    24,    25,   863,   864,   865,   866,   817,   409,   605,
     907,    20,   817,   370,  1397,   817,    20,  1180,   851,   849,
     855,   817,   853,   817,   817,   817,   817,   817,   817,   817,
     817,   817,   817,   817,   817,   817,   817,   817,   817,   817,
     817,   817,   817,   817,   409,   817,   817,   409,   844,  1073,
     605,   409,  1432,    24,   922,  1145,  1145,  1416,  1056,   824,
     824,   824,   904,   905,   409,  1073,  1104,   767,   955,   956,
     605,  1416,  1447,  1445,   915,   655,    20,   646,   915,   978,
    1073,   714,   604,   824,   329,  1115,   535,  1114,     5,    47,
      49,    51,   597,   605,   798,  1091,   873,    17,    18,    24,
     283,   289,   290,   291,   309,   417,   420,   444,   464,   499,
     518,   519,   534,   573,   606,   997,   992,  1125,   903,   824,
     323,   574,     5,   907,    25,    25,   658,   131,  1174,   197,
    1179,  1185,  1443,   678,   915,    24,   907,  1447,   568,   907,
     602,  1073,   673,   915,   824,   318,   696,   700,   557,   694,
     702,    22,   213,  1045,  1049,   461,   842,   461,  1164,   824,
     436,  1082,   919,     5,  1001,   525,  1141,  1073,   946,   928,
    1447,  1447,   938,   939,   958,   958,   249,   252,   254,   274,
     284,   326,   330,   408,   460,   643,   957,   959,   960,   986,
    1073,  1093,   525,   660,    25,   378,   944,   300,  1415,  1415,
     114,   115,   415,   525,   915,  1322,  1323,  1368,   767,  1367,
    1367,  1264,   767,   915,  1425,  1425,   338,   455,   564,  1405,
    1367,  1272,   147,   417,   428,   450,   457,  1296,  1297,  1298,
     266,   267,  1388,  1457,  1457,   363,   891,  1073,   621,   622,
     884,   885,   886,   460,   604,   623,   624,   643,   894,   895,
    1457,   732,    25,   751,   751,   759,  1204,   732,  1194,  1311,
    1367,  1245,  1320,   409,  1245,   409,   409,  1239,  1240,   409,
     409,    42,   278,   336,   348,   358,   376,   386,   389,   402,
     451,   481,   491,   511,   514,   516,   544,   553,  1359,  1360,
    1361,  1363,  1236,  1237,  1233,  1234,   643,  1231,    24,   918,
    1076,   599,   405,  1416,   555,   525,  1451,   653,   654,   915,
     915,   915,  1221,   842,   370,   685,   686,   687,   817,   370,
     370,   370,   370,  1405,   370,   370,   370,   370,   568,   864,
      18,    25,   568,   370,   370,    25,   345,   432,   449,   492,
     531,   560,   569,  1378,   370,   370,   370,   370,     5,   730,
     370,   817,   817,   817,   370,   817,   370,   370,   370,   842,
    1397,   842,  1397,   685,   915,  1219,   596,  1118,   605,     5,
       5,     5,   558,   824,   599,     5,   462,   605,   370,   405,
     409,   604,   142,   146,   249,   252,   716,   719,   720,   986,
     717,   718,   915,   409,   916,   628,   629,  1119,   824,   915,
     915,   905,   906,   488,  1447,   806,   532,  1277,    25,    25,
     409,   993,   995,  1073,   514,  1133,   820,    45,   817,  1177,
      25,  1073,  1457,   685,   370,     5,   370,   370,   689,   915,
     370,  1416,   685,   409,   701,   697,   339,   695,   824,   318,
     698,   702,   575,   988,  1050,  1046,   341,  1044,  1045,   822,
     605,  1079,   599,  1097,    13,    17,    18,    20,    24,    25,
      43,   374,   389,   406,   409,   422,   462,   463,   475,   516,
     555,   567,   579,   580,   588,   915,   923,  1142,  1143,  1372,
    1374,  1409,  1410,  1433,  1436,  1457,   940,   941,   529,   914,
     525,   907,   974,   907,   975,   967,   966,   964,   963,   987,
     417,   428,   970,   971,   417,   428,   972,   973,   303,   960,
     965,  1447,    77,   311,   324,   388,   395,   434,   459,   469,
     470,   485,   506,   509,   510,   515,   572,   584,   661,   662,
       5,    25,  1416,   227,   450,  1398,  1399,  1416,  1129,  1392,
    1394,    79,    79,   574,  1127,  1324,  1325,   409,  1304,   128,
     504,  1329,  1336,  1367,   154,   250,  1429,   599,   605,  1406,
    1407,  1409,  1252,   320,   329,   353,   356,   374,   480,   533,
     540,   909,  1274,  1279,   409,  1299,   604,     5,    24,   915,
    1389,  1390,   893,  1073,     5,   525,   887,   888,   618,   886,
     892,   915,   892,   896,   897,   892,   303,   895,  1024,   405,
     405,   439,  1187,  1207,  1041,   439,  1150,  1181,   409,     5,
     370,   273,   409,   421,   581,  1339,  1340,  1341,  1342,  1343,
    1344,  1351,  1355,  1357,  1404,  1409,   370,   915,  1310,  1312,
    1367,  1370,  1314,  1370,     5,   370,  1314,  1339,   345,   432,
     449,   492,   531,   560,   569,  1379,  1379,   409,   409,   409,
     409,   409,   409,   186,   378,  1316,  1318,     5,   370,     5,
     370,   915,   370,  1435,     8,  1416,   824,     5,  1225,  1226,
     842,  1030,   847,     5,  1406,   857,  1377,   857,    25,    25,
     568,    23,    25,   770,   858,  1197,   370,   409,  1197,   771,
     370,  1197,   852,   850,   856,  1197,   854,  1197,  1197,  1197,
     817,   834,   370,   834,   370,   845,   599,  1225,   555,  1416,
    1416,   824,   824,   904,   488,   824,  1449,     5,    20,  1370,
     956,  1416,   599,   915,   717,   725,   724,   726,   915,   921,
     727,   921,   170,   720,   723,     5,   958,   599,   824,     8,
     915,  1278,   874,   994,   995,  1073,     5,   304,   679,  1209,
     323,   323,   437,   599,   323,   409,   674,   671,  1457,  1457,
     703,   699,   695,   989,    24,   914,  1051,  1073,  1457,   824,
     404,    20,   915,  1087,   842,    25,   923,    25,   923,  1375,
    1379,  1409,   409,   409,   919,   409,   409,   409,   409,   409,
       5,    17,    18,    19,    20,    71,    72,    73,    74,    75,
      76,  1430,   399,    41,   521,   947,   942,   943,    25,   658,
     915,     5,   961,     5,   962,  1457,  1457,  1457,  1457,   993,
       5,   969,     5,   968,  1457,   914,     5,   370,    25,  1367,
     919,  1386,   574,   574,  1263,  1391,  1392,  1325,  1305,  1370,
     596,   909,  1339,   409,  1267,   915,  1426,  1425,     5,  1395,
     259,   299,   300,   301,   324,   332,   337,   352,   357,   359,
     366,   369,   372,   375,   378,   383,   401,   417,   420,   421,
     427,   438,   454,   461,   468,   471,   472,   473,   475,   476,
     492,   515,   516,   517,   518,   520,   537,   538,   560,   569,
     570,   572,   634,   924,  1456,   562,   824,   824,  1273,   909,
    1300,  1370,  1367,  1298,   599,   599,     5,     5,  1073,   892,
    1457,  1457,     5,   899,   900,  1457,  1457,   898,  1017,   790,
     748,    52,    53,    56,    57,    58,   156,   163,   197,   206,
     235,   236,   280,   322,   378,   607,   608,   609,   610,   611,
     612,   613,   614,   615,   616,  1184,  1188,   113,   493,  1189,
    1205,  1017,   138,   155,   156,   163,   197,   206,   235,   280,
     322,  1182,  1183,  1195,  1189,  1312,  1320,   409,  1404,   450,
    1339,  1409,  1404,  1342,     6,   370,     7,     9,    11,    12,
      13,    14,    15,    16,   231,   350,   535,  1356,   407,   581,
     602,  1354,  1356,   437,  1369,   370,     5,   919,     5,   370,
    1240,   370,   370,   605,   409,   605,    25,  1365,  1365,    25,
    1365,  1365,    25,  1364,    24,  1372,  1319,  1320,  1237,  1233,
    1416,     8,   654,     5,   370,   822,   370,   370,   687,   525,
    1330,  1335,   605,   370,    25,   568,    25,   605,   370,   370,
     370,   370,     5,   370,   370,   370,    20,   370,  1416,     5,
     824,   545,   253,   663,   664,   824,    20,   915,   370,   958,
    1457,  1457,     5,   721,   437,   599,     5,   722,  1457,   718,
     525,    20,   915,     5,   915,  1109,   368,   638,  1073,  1094,
    1095,  1457,     5,   370,   914,   817,   370,   685,  1073,   670,
     652,   915,  1073,   676,   370,   685,  1457,  1457,   993,  1048,
      24,  1052,  1073,   550,   870,   437,   462,   823,  1002,   605,
     370,   374,  1370,  1431,   338,   455,   564,  1358,   409,  1358,
    1358,  1358,  1358,  1409,  1411,  1143,  1409,  1409,  1409,  1409,
    1433,   949,   948,   419,   934,   935,   599,   907,  1457,   907,
    1457,   971,  1457,   973,  1457,   658,   662,   370,   409,  1417,
    1405,  1388,  1392,  1392,  1384,     5,   370,   450,  1403,  1268,
    1370,   458,  1265,  1403,   605,  1407,   532,  1402,    20,   409,
    1255,  1256,  1257,  1258,  1370,   532,  1275,     5,   370,   605,
     915,   915,  1390,  1073,   915,  1457,  1457,  1457,  1457,   603,
     603,  1185,  1185,  1185,    24,  1185,  1185,  1185,  1185,  1185,
    1185,    24,    24,  1185,  1188,  1073,  1099,  1100,   598,   425,
    1151,  1457,    24,    24,    25,    25,    25,    25,    25,    24,
    1073,  1183,  1151,   370,   919,   370,  1340,  1341,  1409,   409,
    1404,   409,  1404,   228,   365,   367,   535,   409,   549,   564,
     565,  1345,  1346,  1347,  1404,  1409,    25,  1309,  1370,   599,
    1370,   345,   432,   449,   492,   531,   560,   569,  1380,    25,
    1380,     5,  1362,  1362,     5,   370,   370,  1362,   370,  1319,
    1416,  1226,   247,  1222,   494,  1331,  1332,  1333,  1367,  1336,
     310,   493,   503,  1282,  1400,  1378,   857,   568,    23,    25,
     370,   774,   817,   447,   805,     5,   352,  1416,     5,   409,
     370,   529,   985,   921,  1457,   655,    20,   915,   921,  1457,
    1447,   824,  1447,   399,     5,   219,   995,   658,   323,   683,
    1210,  1091,   405,   685,   675,   370,  1457,   914,   824,   868,
    1083,  1380,     5,  1379,     5,   370,  1409,   919,  1409,  1409,
    1409,  1409,     5,   370,   824,  1457,   936,   937,    20,   915,
    1418,  1419,  1406,  1387,  1385,  1388,  1370,   919,   118,  1306,
       5,   370,  1266,  1426,  1094,  1396,    13,  1257,  1259,  1253,
       5,    13,  1276,  1370,   441,  1301,  1302,  1368,   599,   189,
    1025,   786,   760,   517,   566,  1101,     5,  1099,    40,   112,
     178,   180,   195,   203,   207,   232,  1152,  1153,  1206,  1025,
    1196,  1405,  1352,  1353,  1372,  1436,  1352,  1409,  1349,  1372,
    1412,  1404,     5,   405,    20,   915,   370,    25,  1366,   370,
     370,    25,   370,   409,  1333,     5,   915,  1371,   347,  1327,
    1337,   915,  1401,   598,  1358,   310,    23,    25,   907,   658,
     352,  1416,   824,   665,   547,  1107,    25,   658,   405,   985,
     370,  1073,  1095,  1131,  1091,   370,   409,   677,   683,   672,
    1047,  1457,   405,  1379,   605,  1379,   370,  1411,   370,   370,
     370,   370,  1409,   554,   914,     5,   370,  1402,  1388,  1388,
    1405,  1370,   409,  1335,   409,   462,  1260,  1261,  1404,  1409,
       5,   370,   128,   504,  1254,  1258,  1261,  1094,     5,   119,
    1295,   915,  1100,  1154,  1155,  1073,  1157,  1073,  1156,  1158,
    1153,   218,   218,  1406,     5,   370,   370,     7,   420,  1348,
      25,  1369,   605,   370,  1332,  1334,  1332,  1328,  1408,  1409,
     426,  1326,  1338,  1222,    25,  1283,  1284,  1285,  1370,  1398,
    1401,   804,  1416,   371,   182,   238,   263,   272,   308,   316,
     410,   582,   662,   666,   667,   409,   599,   658,   986,  1134,
    1135,  1136,  1211,   680,   370,   683,  1457,   869,   605,  1380,
     605,   370,   950,   982,  1419,  1335,  1406,   462,  1269,  1270,
    1409,  1400,  1260,  1409,     5,  1257,    13,   909,  1339,  1302,
    1457,  1457,  1159,  1457,  1160,  1457,  1457,  1335,  1353,  1409,
    1350,  1412,   405,  1380,     5,   370,     5,  1339,     5,   517,
     566,  1286,  1222,   326,   330,   807,   808,   809,   986,   902,
     902,   902,   902,   902,   902,    24,     5,   370,   824,    20,
     915,  1137,   261,  1136,   683,   685,   683,   220,  1380,  1380,
    1457,   658,  1400,  1335,     5,   370,   370,  1261,   409,  1457,
    1457,   370,  1332,  1408,  1284,   811,   810,   217,   809,   812,
     667,     5,  1457,   681,   947,  1270,  1260,  1457,  1457,  1457,
     824,   370,   370,   370,   682,   141,   323,   684,  1091
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
#line 879 "fgl.yacc"
    { print_screen_mode(0);}
    break;

  case 3:
#line 882 "fgl.yacc"
    { print_screen_mode(1);}
    break;

  case 4:
#line 886 "fgl.yacc"
    {
		print_start_server(yyvsp[-3].str,yyvsp[0].str);
	}
    break;

  case 5:
#line 892 "fgl.yacc"
    {
	print_stop_external();
	}
    break;

  case 6:
#line 897 "fgl.yacc"
    {
		if (scan_variable(yyvsp[0].str)!=2) {
		char buff[256];
			strcpy(buff,"START EXTERNAL ..ON must be an integer");
			yyerror(buff);
			YYERROR;
		}
	}
    break;

  case 9:
#line 909 "fgl.yacc"
    {
	sprintf(yyval.str,"%s%s",yyvsp[-2].str,yyvsp[0].str);
	}
    break;

  case 10:
#line 914 "fgl.yacc"
    {
	print_remote_func(yyvsp[0].str);
	sprintf(yyval.str,"unregister_func(\"%s\",aclfgl_%s);\n",yyvsp[0].str,yyvsp[0].str);
	addmap("Call Remote",yyvsp[0].str,curr_func,yylineno,infilename);
	}
    break;

  case 11:
#line 932 "fgl.yacc"
    {sprintf(yyval.str,"(%s)",yyvsp[-1].str);}
    break;

  case 12:
#line 933 "fgl.yacc"
    { sprintf(yyval.str,"%s%s%s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 13:
#line 934 "fgl.yacc"
    {sprintf(yyval.str,"%d",atoi(yyvsp[0].str));}
    break;

  case 14:
#line 935 "fgl.yacc"
    {sprintf(yyval.str,"(%s%s)",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 15:
#line 936 "fgl.yacc"
    {
  int a;
  a=scan_variable(yyvsp[0].str)&15;
  if (a!=1&&a!=2) {
    
    yyerror("Only INTEGER/SMALLINT variables may be used as subscripts");
    YYERROR;
    /* error processing */;
  }
  sprintf(yyval.str,"%s",yyvsp[0].str);
}
    break;

  case 16:
#line 950 "fgl.yacc"
    {strcpy(yyval.str,"+");}
    break;

  case 17:
#line 951 "fgl.yacc"
    {strcpy(yyval.str,"-");}
    break;

  case 18:
#line 952 "fgl.yacc"
    {strcpy(yyval.str,"*");}
    break;

  case 19:
#line 953 "fgl.yacc"
    {strcpy(yyval.str,"/");}
    break;

  case 20:
#line 954 "fgl.yacc"
    {strcpy(yyval.str,"%");}
    break;

  case 21:
#line 959 "fgl.yacc"
    {strcpy(yyval.str,"+");}
    break;

  case 22:
#line 960 "fgl.yacc"
    {strcpy(yyval.str,"-");}
    break;

  case 23:
#line 971 "fgl.yacc"
    {
		debug("Using default attribute of WHITE");
		sprintf(yyval.str,"%d",0);}
    break;

  case 24:
#line 974 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 25:
#line 977 "fgl.yacc"
    {start_state("attribute",1);}
    break;

  case 26:
#line 977 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[-1].str);
debug("Got Attributes : %s",yyvsp[-1].str);
start_state("attribute",0);
}
    break;

  case 28:
#line 984 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 29:
#line 985 "fgl.yacc"
    {
sprintf(yyval.str,"%d",atoi(yyvsp[-2].str)|atoi(yyvsp[0].str));
}
    break;

  case 30:
#line 991 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("BLACK"));}
    break;

  case 31:
#line 992 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("BLUE"));}
    break;

  case 32:
#line 993 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("CYAN"));}
    break;

  case 33:
#line 994 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("GREEN"));}
    break;

  case 34:
#line 995 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("MAGENTA"));}
    break;

  case 35:
#line 996 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("RED"));}
    break;

  case 36:
#line 997 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("WHITE"));}
    break;

  case 37:
#line 998 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("YELLOW"));}
    break;

  case 38:
#line 999 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("REVERSE"));}
    break;

  case 39:
#line 1000 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("BLINK"));}
    break;

  case 40:
#line 1001 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("UNDERLINE"));}
    break;

  case 41:
#line 1002 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("BOLD"));}
    break;

  case 42:
#line 1003 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("NORMAL"));}
    break;

  case 43:
#line 1004 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("INVISIBLE"));}
    break;

  case 44:
#line 1005 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("DIM"));}
    break;

  case 45:
#line 1006 "fgl.yacc"
    {inp_flags=inp_flags | 0x1; strcpy(yyval.str,"0");}
    break;

  case 48:
#line 1013 "fgl.yacc"
    {
debug("win_attributes_def");
start_state("attribute",1);
debug("Started states");
form_attrib.attrib=0;}
    break;

  case 49:
#line 1017 "fgl.yacc"
    {start_state("attribute",0);strcpy(yyval.str,"");
}
    break;

  case 50:
#line 1021 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 51:
#line 1022 "fgl.yacc"
    {sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 52:
#line 1026 "fgl.yacc"
    { 
/*printf("Window attribute = %s\n",$<str>1);*/
form_attrib.attrib      =form_attrib.attrib|atoi(yyvsp[0].str);
/*printf("Window attribute = %d\n",form_attrib.attrib);*/
}
    break;

  case 53:
#line 1032 "fgl.yacc"
    { form_attrib.border      =1;}
    break;

  case 54:
#line 1034 "fgl.yacc"
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

  case 55:
#line 1045 "fgl.yacc"
    { form_attrib.comment_line=atoi(yyvsp[0].str); }
    break;

  case 56:
#line 1047 "fgl.yacc"
    { form_attrib.form_line   =atoi(yyvsp[0].str); }
    break;

  case 57:
#line 1049 "fgl.yacc"
    { form_attrib.error_line  =atoi(yyvsp[0].str); }
    break;

  case 58:
#line 1051 "fgl.yacc"
    { form_attrib.menu_line   =atoi(yyvsp[0].str); 
debug("Set menu line to %s",yyvsp[0].str);
}
    break;

  case 59:
#line 1055 "fgl.yacc"
    { form_attrib.message_line=atoi(yyvsp[0].str); }
    break;

  case 60:
#line 1057 "fgl.yacc"
    { form_attrib.prompt_line =atoi(yyvsp[0].str); }
    break;

  case 61:
#line 1118 "fgl.yacc"
    {strcpy(yyval.str,"CALL");}
    break;

  case 62:
#line 1122 "fgl.yacc"
    { debug("print_expr (3)"); 
		print_expr(yyvsp[-2].ptr);
		print_pop_variable(yyvsp[0].str);
	}
    break;

  case 63:
#line 1126 "fgl.yacc"
    {
	print_getfldbuf(yyvsp[-2].str);
	}
    break;

  case 64:
#line 1129 "fgl.yacc"
    {
	print_returning();
}
    break;

  case 65:
#line 1133 "fgl.yacc"
    {
	print_form_is_compiled(yyvsp[-1].str);
	}
    break;

  case 66:
#line 1137 "fgl.yacc"
    {
	print_field_func('I',yyvsp[-3].str,yyvsp[0].str);
   }
    break;

  case 68:
#line 1141 "fgl.yacc"
    { 
	print_field_func('T',yyvsp[-3].str,yyvsp[0].str);
     }
    break;

  case 69:
#line 1144 "fgl.yacc"
    {
	new_counter();
   	addmap("Call",yyvsp[-3].str,curr_func,yylineno,infilename);
   }
    break;

  case 70:
#line 1150 "fgl.yacc"
    {
	int a;
	dump_expr(yyvsp[-1].ptr);
	a=get_counter_val();
	drop_counter();
	debug("Printing call_func_call...");
  	print_class_func_call(yyvsp[-6].str,yyvsp[-4].str,yyvsp[-1].ptr,a);
   }
    break;

  case 71:
#line 1159 "fgl.yacc"
    {
	print_returning();
	strcpy(yyval.str,yyvsp[-4].str); /* ? */
   }
    break;

  case 72:
#line 1163 "fgl.yacc"
    {
	new_counter();
   	addmap("Call",yyvsp[-1].str,curr_func,yylineno,infilename);
   }
    break;

  case 73:
#line 1168 "fgl.yacc"
    {
	debug("Got args");
   }
    break;

  case 74:
#line 1172 "fgl.yacc"
    {
	int a;
	dump_expr(yyvsp[-2].ptr);
	a=get_counter_val();
	drop_counter();
  	print_func_call(yyvsp[-5].str,yyvsp[-2].ptr,a);
   }
    break;

  case 75:
#line 1180 "fgl.yacc"
    {
	print_returning();
	strcpy(yyval.str,yyvsp[-3].str); /* ? */
   }
    break;

  case 76:
#line 1184 "fgl.yacc"
    {
	A4GLSQL_set_status(0,0);
	new_counter();
	}
    break;

  case 77:
#line 1188 "fgl.yacc"
    {
   sprintf(yyval.str,"%d",get_counter_val());drop_counter();
}
    break;

  case 78:
#line 1191 "fgl.yacc"
    {
        print_expr ((struct expr_str *)yyvsp[-3].ptr);  
	print_call_shared(yyvsp[-6].str,yyvsp[-8].str,atoi(yyvsp[-2].str));
	print_returning();
	print_end_call_shared();
}
    break;

  case 79:
#line 1197 "fgl.yacc"
    {
	sprintf(yyval.str,"\"%s\",\"%s\"",get_idents(0),get_idents(1));
	A4GLSQL_set_status(0,0);
	new_counter();
	}
    break;

  case 80:
#line 1202 "fgl.yacc"
    {
   	sprintf(yyval.str,"%d",get_counter_val());drop_counter();
}
    break;

  case 81:
#line 1205 "fgl.yacc"
    {
	char buff[256];
	char *ptr;
	debug("STR3 = %s",yyvsp[-4].str);
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

  case 82:
#line 1221 "fgl.yacc"
    {
   char buff[256];
   new_counter();
   sprintf(buff,"%s:%s(%p)",yyvsp[-6].str,yyvsp[-4].str,yyvsp[-2].str);
   addmap("External",buff,curr_func,yylineno,infilename);
   }
    break;

  case 83:
#line 1228 "fgl.yacc"
    {
   sprintf(yyval.str,"%d",get_counter_val());drop_counter();
   }
    break;

  case 84:
#line 1232 "fgl.yacc"
    {
	 debug("print_expr (6)");print_expr(yyvsp[-2].ptr);
   }
    break;

  case 85:
#line 1236 "fgl.yacc"
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

  case 86:
#line 1258 "fgl.yacc"
    {start_bind('i',0);strcpy(yyval.str,"0");}
    break;

  case 87:
#line 1258 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);
}
    break;

  case 88:
#line 1262 "fgl.yacc"
    {start_bind('i',0);strcpy(yyval.str,"0");}
    break;

  case 89:
#line 1263 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 90:
#line 1264 "fgl.yacc"
    {strcpy(yyval.str,"WITHOUT WAITING"); }
    break;

  case 91:
#line 1269 "fgl.yacc"
    {
			yyval.ptr=new_expr("");
		}
    break;

  case 92:
#line 1272 "fgl.yacc"
    {
			yyval.ptr=yyvsp[0].ptr;
		}
    break;

  case 93:
#line 1278 "fgl.yacc"
    {
	yyval.ptr=yyvsp[0].ptr;
}
    break;

  case 94:
#line 1281 "fgl.yacc"
    {
		yyval.ptr=append_expr_expr(yyvsp[-2].ptr,yyvsp[0].ptr);
}
    break;

  case 97:
#line 1293 "fgl.yacc"
    {
sprintf(yyval.str,"\"%s\"",yyvsp[0].str);
}
    break;

  case 98:
#line 1299 "fgl.yacc"
    {
sprintf(yyval.str,"\"%s\"",yyvsp[0].str);
}
    break;

  case 99:
#line 1302 "fgl.yacc"
    { sprintf(yyval.str,"\"%s.%s\"",yyvsp[-2].str,yyvsp[0].str); }
    break;

  case 100:
#line 1317 "fgl.yacc"
    {
push_blockcommand("CASE");
setinc(1);
incprint();
print_case(1);
setinc(1);
}
    break;

  case 101:
#line 1327 "fgl.yacc"
    {
print_after_when(0);
pop_blockcommand("CASE");
}
    break;

  case 102:
#line 1333 "fgl.yacc"
    {  push_blockcommand("CASE"); 
setinc(1);
incprint(); 
print_case(0);
setinc(1);
}
    break;

  case 103:
#line 1342 "fgl.yacc"
    {
print_after_when(0);
pop_blockcommand("CASE");
}
    break;

  case 108:
#line 1355 "fgl.yacc"
    {setinc(-1);incprint();}
    break;

  case 110:
#line 1358 "fgl.yacc"
    {
incprint();
}
    break;

  case 111:
#line 1360 "fgl.yacc"
    {incprint();
print_after_when(0);
}
    break;

  case 113:
#line 1366 "fgl.yacc"
    {incprint();}
    break;

  case 114:
#line 1368 "fgl.yacc"
    {incprint();
print_after_when(0);
}
    break;

  case 115:
#line 1373 "fgl.yacc"
    {
print_when(0);

incprint();
}
    break;

  case 116:
#line 1378 "fgl.yacc"
    {incprint();
print_after_when(1);
setinc(-1);}
    break;

  case 117:
#line 1384 "fgl.yacc"
    {
incprint();
print_when(1);
}
    break;

  case 118:
#line 1388 "fgl.yacc"
    {incprint();
print_after_when(1);
setinc(-1);}
    break;

  case 119:
#line 1403 "fgl.yacc"
    {
  print_close('F',yyvsp[0].str);
 }
    break;

  case 120:
#line 1406 "fgl.yacc"
    {
  print_close('W',yyvsp[0].str);
}
    break;

  case 121:
#line 1409 "fgl.yacc"
    {
  print_close('W',yyvsp[0].str);
}
    break;

  case 122:
#line 1412 "fgl.yacc"
    {
  print_close('D',0);
}
    break;

  case 123:
#line 1415 "fgl.yacc"
    {
  print_close('S',yyvsp[0].str);
}
    break;

  case 124:
#line 1418 "fgl.yacc"
    {
  print_close('C',yyvsp[0].str);
}
    break;

  case 130:
#line 1440 "fgl.yacc"
    {
			lex_printc("%s",yyvsp[0].str);
}
    break;

  case 133:
#line 1449 "fgl.yacc"
    {
			lex_printc("%s\n",yyvsp[0].str);
}
    break;

  case 134:
#line 1459 "fgl.yacc"
    {
/* This aint used - its filtered by the lexer first... */
	lex_printc("FIXME : Comment : %s\n");
}
    break;

  case 135:
#line 1473 "fgl.yacc"
    {
push_blockcommand("CONSTRUCT");
}
    break;

  case 136:
#line 1477 "fgl.yacc"
    {
	print_construct_1();
}
    break;

  case 137:
#line 1480 "fgl.yacc"
    {
	print_construct_2(yyvsp[-2].str);
}
    break;

  case 138:
#line 1488 "fgl.yacc"
    {
	print_construct_3(1,yyvsp[-5].str,yyvsp[0].str);
	strcpy(yyval.str,"form_loop(&_inp_io)"); /* FIXME */
	reset_constr();
}
    break;

  case 139:
#line 1494 "fgl.yacc"
    {
	print_construct_3(0,yyvsp[-7].str,yyvsp[0].str);
	strcpy(yyval.str,"form_loop(&_inp_io)"); /* FIXME */
	reset_constr();
}
    break;

  case 144:
#line 1509 "fgl.yacc"
    {
                push_construct("",yyval.str);
             }
    break;

  case 145:
#line 1513 "fgl.yacc"
    {
                sprintf(yyval.str,"%s.%s",yyvsp[-2].str,yyvsp[0].str);
                push_construct(yyvsp[-2].str,yyvsp[0].str); 
             }
    break;

  case 146:
#line 1518 "fgl.yacc"
    {
                push_construct(yyvsp[-2].str,"*");
             }
    break;

  case 149:
#line 1528 "fgl.yacc"
    {
		print_befaft_field_1(yyvsp[0].str);
	}
    break;

  case 150:
#line 1531 "fgl.yacc"
    {
		print_befaft_field_2();

	}
    break;

  case 151:
#line 1535 "fgl.yacc"
    {
		print_befaft_field_1(yyvsp[0].str);
	}
    break;

  case 152:
#line 1537 "fgl.yacc"
    {
		print_befaft_field_2();
	}
    break;

  case 153:
#line 1540 "fgl.yacc"
    {
		print_onkey_1(yyvsp[0].str);
	}
    break;

  case 154:
#line 1542 "fgl.yacc"
    {
		print_onkey_2();
	}
    break;

  case 155:
#line 1545 "fgl.yacc"
    {
		print_befaft_field_1("AFTER_INP");
	}
    break;

  case 156:
#line 1547 "fgl.yacc"
    {
		print_befaft_field_2();
	}
    break;

  case 157:
#line 1550 "fgl.yacc"
    {
		print_befaft_field_1("BEFORE_INP");
		}
    break;

  case 158:
#line 1553 "fgl.yacc"
    {
		print_befaft_field_2();
	}
    break;

  case 159:
#line 1563 "fgl.yacc"
    {sprintf(yyval.str,"BEF_FIELD_CHK(%s)",yyvsp[0].str);}
    break;

  case 160:
#line 1564 "fgl.yacc"
    {
	  char buff[80];
	  sprintf(buff,"BEF_FIELD_CHK(%s)",yyvsp[0].str);
	  generate_or(yyval.str,yyvsp[-2].str,buff);
	}
    break;

  case 161:
#line 1572 "fgl.yacc"
    {sprintf(yyval.str,"AFT_FIELD_CHK(%s)",yyvsp[0].str);}
    break;

  case 162:
#line 1573 "fgl.yacc"
    {
	  char buff[80];
	  sprintf(buff,"AFT_FIELD_CHK(%s)",yyvsp[0].str);
	  generate_or(yyval.str,yyvsp[-2].str,buff);
	}
    break;

  case 163:
#line 1590 "fgl.yacc"
    {
        	yyval.ptr=new_expr("pushop(OP_YEAR);");
	}
    break;

  case 164:
#line 1593 "fgl.yacc"
    {
        	yyval.ptr=new_expr("pushop(OP_MONTH);");
	}
    break;

  case 165:
#line 1596 "fgl.yacc"
    {
        	yyval.ptr=new_expr("pushop(OP_DAY);");
	}
    break;

  case 166:
#line 1599 "fgl.yacc"
    {
        	yyval.ptr=new_expr("pushop(OP_HOUR);");
	}
    break;

  case 167:
#line 1602 "fgl.yacc"
    {
        	yyval.ptr=new_expr("pushop(OP_MINUTE);");
	}
    break;

  case 168:
#line 1605 "fgl.yacc"
    {
        	yyval.ptr=new_expr("pushop(OP_SECOND);");
	}
    break;

  case 169:
#line 1614 "fgl.yacc"
    {
			yyval.ptr=append_expr_expr(yyvsp[-2].ptr,yyvsp[-1].ptr);
		}
    break;

  case 170:
#line 1622 "fgl.yacc"
    { 
	char buff[50];
	sprintf(buff,"push_int(%d);",(19*16)+10); 
	yyval.ptr=new_expr(buff);
}
    break;

  case 171:
#line 1627 "fgl.yacc"
    { 
	char buff[50];
	sprintf(buff,"push_int(%d);",(atoi(yyvsp[-2].str)*16) +atoi(yyvsp[0].str)  ); 
	yyval.ptr=new_expr(buff);
}
    break;

  case 172:
#line 1640 "fgl.yacc"
    {
				print_defer(0);
			}
    break;

  case 173:
#line 1644 "fgl.yacc"
    {
				print_defer(1);
			}
    break;

  case 174:
#line 1659 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 175:
#line 1660 "fgl.yacc"
    {strcpy(yyval.str,"");lastlineno=yylineno;}
    break;

  case 178:
#line 1668 "fgl.yacc"
    {dtypelist[0]=0;lex_printcomment("/* define */\n");}
    break;

  case 179:
#line 1668 "fgl.yacc"
    {lex_printcomment("/*end def */\n");}
    break;

  case 185:
#line 1678 "fgl.yacc"
    {in_define=1;}
    break;

  case 186:
#line 1678 "fgl.yacc"
    {in_define=0;strcpy(yyval.str,yyvsp[0].str);
                        set_yytext(yyval.str);
                        if (bad_identifiers(yyval.str)) {
                                yyerror("You can't use this identifier as it is a reserved word in the target language");
                        }
}
    break;

  case 187:
#line 1687 "fgl.yacc"
    { add_constant('c',yyvsp[0].str,yyvsp[-2].str); addmap("Constant",yyvsp[-2].str,curr_func,yylineno,infilename); }
    break;

  case 188:
#line 1688 "fgl.yacc"
    { add_constant('C',yyvsp[0].str,yyvsp[-2].str); addmap("Constant",yyvsp[-2].str,curr_func,yylineno,infilename); }
    break;

  case 189:
#line 1689 "fgl.yacc"
    { add_constant('f',yyvsp[0].str,yyvsp[-2].str);
addmap("Constant",yyvsp[-2].str,curr_func,yylineno,infilename);
 }
    break;

  case 190:
#line 1692 "fgl.yacc"
    { 
add_constant('i',yyvsp[0].str,yyvsp[-2].str);
addmap("Constant",yyvsp[-2].str,curr_func,yylineno,infilename);
 }
    break;

  case 192:
#line 1697 "fgl.yacc"
    { }
    break;

  case 193:
#line 1697 "fgl.yacc"
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

  case 197:
#line 1714 "fgl.yacc"
    {
		sprintf(yyval.str,"-%p",yyvsp[0].str);}
    break;

  case 198:
#line 1718 "fgl.yacc"
    {
/*AF CygWin FIX */
push_name(yyval.str,0);
addmap("Define",yyvsp[0].str,curr_func,yylineno,infilename);
}
    break;

  case 203:
#line 1732 "fgl.yacc"
    {
	debug("defines array %s",yyvsp[-1].str);
	push_type(0,0,yyvsp[-1].str);
}
    break;

  case 205:
#line 1741 "fgl.yacc"
    {
	push_associate(yyvsp[-5].str,yyvsp[-1].str);
	push_type(0,0,yyvsp[-1].str);
}
    break;

  case 206:
#line 1745 "fgl.yacc"
    {
    /* void pop_associate (char *a); */
	pop_associate(0);

}
    break;

  case 212:
#line 1761 "fgl.yacc"
    {sprintf(yyval.str,"%s][%s][%s",yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str); debug("Triplet");}
    break;

  case 213:
#line 1763 "fgl.yacc"
    {sprintf(yyval.str,"%s][%s",yyvsp[-2].str,yyvsp[0].str); debug("double");}
    break;

  case 214:
#line 1764 "fgl.yacc"
    {debug("Single");}
    break;

  case 216:
#line 1771 "fgl.yacc"
    {push_record();in_record++;}
    break;

  case 217:
#line 1771 "fgl.yacc"
    {pop_record();in_record--;}
    break;

  case 218:
#line 1772 "fgl.yacc"
    {in_record++;push_record();debug("Like\n");}
    break;

  case 219:
#line 1773 "fgl.yacc"
    {debug("Link Table : %s\n",yyvsp[-2].str);
                  push_rectab(yyvsp[-2].str);
                  pop_record();in_record--;}
    break;

  case 220:
#line 1776 "fgl.yacc"
    {
		push_record();debug("Like\n");}
    break;

  case 221:
#line 1778 "fgl.yacc"
    {
		  debug("Table:%s\n",yyvsp[-4].str);
		  add_link_to(yyvsp[-4].str,yyvsp[-1].str);
	          debug("Push record...\n");
                  push_rectab(yyvsp[-4].str);
                  pop_record();
}
    break;

  case 223:
#line 1788 "fgl.yacc"
    {
	sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 228:
#line 1803 "fgl.yacc"
    {start_state("dtype",1);}
    break;

  case 229:
#line 1803 "fgl.yacc"
    {start_state("dtype",0);}
    break;

  case 233:
#line 1809 "fgl.yacc"
    {push_type("char","1",0);}
    break;

  case 234:
#line 1810 "fgl.yacc"
    {
/* char buff[80]; */
if (atoi(yyvsp[-1].str)==4) {
	addmap("size=4","----",curr_func,yylineno,infilename);
}
push_type("char",yyvsp[-1].str,0);
}
    break;

  case 235:
#line 1817 "fgl.yacc"
    {push_type("char",yyvsp[-1].str,0);}
    break;

  case 236:
#line 1818 "fgl.yacc"
    {push_type("char",yyvsp[-3].str,0);}
    break;

  case 237:
#line 1819 "fgl.yacc"
    {push_type("long",0,0);}
    break;

  case 238:
#line 1820 "fgl.yacc"
    {
debug("Using specified type...");
push_dim(yyvsp[0].str);}
    break;

  case 239:
#line 1823 "fgl.yacc"
    {push_type("int",0,0);}
    break;

  case 240:
#line 1824 "fgl.yacc"
    {push_type("form",0,0);}
    break;

  case 241:
#line 1825 "fgl.yacc"
    {push_type("form",0,0);}
    break;

  case 242:
#line 1826 "fgl.yacc"
    { char buff[256];
				sprintf(buff,"%d",16*256+2);
				push_type("fgldecimal",buff,0);
				}
    break;

  case 243:
#line 1830 "fgl.yacc"
    {
				char buff[256];
				sprintf(buff,"%d",atoi(yyvsp[-1].str)*256+2);
				push_type("fgldecimal",buff,0);
}
    break;

  case 244:
#line 1835 "fgl.yacc"
    {
char buff[256];
sprintf(buff,"%d",atoi(yyvsp[-3].str)*256+atoi(yyvsp[-1].str));
push_type("fgldecimal",buff,0);
}
    break;

  case 245:
#line 1840 "fgl.yacc"
    {
			char buff[256];
			sprintf(buff,"%d",16*256+2);
			push_type("fglmoney",buff,0);}
    break;

  case 246:
#line 1844 "fgl.yacc"
    {
		char buff[256];sprintf(buff,"%d",atoi(yyvsp[-1].str)*256+2);
			push_type("fglmoney",buff,0);}
    break;

  case 247:
#line 1847 "fgl.yacc"
    {
char buff[256];
sprintf(buff,"%d",atoi(yyvsp[-3].str)*256+atoi(yyvsp[-1].str));
push_type("fglmoney",buff,0);}
    break;

  case 248:
#line 1851 "fgl.yacc"
    {push_type("double",0,0);}
    break;

  case 249:
#line 1852 "fgl.yacc"
    {push_type("float",0,0);}
    break;

  case 250:
#line 1853 "fgl.yacc"
    {push_type("fgldate",0,0);}
    break;

  case 251:
#line 1854 "fgl.yacc"
    {push_type("fglbyte",0,0);}
    break;

  case 252:
#line 1855 "fgl.yacc"
    {push_type("fglbyte",0,0);}
    break;

  case 253:
#line 1856 "fgl.yacc"
    {push_type("fgltext",0,0);}
    break;

  case 254:
#line 1857 "fgl.yacc"
    {push_type("fgltext",0,0);}
    break;

  case 255:
#line 1858 "fgl.yacc"
    {
push_type("struct_dtime",yyvsp[0].str,0);
}
    break;

  case 256:
#line 1861 "fgl.yacc"
    {push_type("struct_ival",yyvsp[0].str,0);}
    break;

  case 257:
#line 1862 "fgl.yacc"
    {push_like(yyvsp[0].str);lex_printcomment("/*added(XXXXX)\n */");}
    break;

  case 258:
#line 1863 "fgl.yacc"
    {
			char buff[256];
			strcpy(buff,yyvsp[0].str);
			debug("Got a rogue datatype");

			if (find_datatype(upshift(buff))) 
			{
				char *(*function) (void);
				debug("Checking ...");
				function=get_datatype_function_n(upshift(buff),"OUTPUT");
				debug("Got function as %p",function);

                /*  warning: comparison between pointer and integer */
				if ((int)function != -1 && (int)function != 0)
				{
					debug("call returns %s\n",function());
					strcpy(buff,function());
					debug("Set up buff as %s");
					push_type(function(),0,0);
					debug("Pushed type : %s\n",function());
				}
			} else {
				/* yyerror("Unknown datatype : %s",$<str>1); */
                yyerror("Unknown datatype.");
			}
		}
    break;

  case 259:
#line 1895 "fgl.yacc"
    {
lex_printcomment("/*column like(ZZZ)\n*/"); sprintf(yyval.str,"%s.%s",yyvsp[-2].str,yyvsp[0].str); lex_printcomment ("/*set col...(ZZZ)\n*/");}
    break;

  case 260:
#line 1899 "fgl.yacc"
    {debug("--->%s\n",yyvsp[0].str);strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 261:
#line 1901 "fgl.yacc"
    {debug("--->%s\n",yyvsp[0].str);strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 262:
#line 1903 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 263:
#line 1905 "fgl.yacc"
    {
debug("Real datetime %s to %s\n",yyvsp[-2].str,yyvsp[0].str);
sprintf(yyval.str,"%d",(atoi(yyvsp[-2].str)*16)+atoi(yyvsp[0].str)); }
    break;

  case 264:
#line 1910 "fgl.yacc"
    {

sprintf(yyval.str,"%d",(atoi(yyvsp[-2].str)*16)+atoi(yyvsp[0].str)); 
printf("-->%s\n",yyval.str);
}
    break;

  case 265:
#line 1916 "fgl.yacc"
    {start_state("dtime_val",1);}
    break;

  case 266:
#line 1916 "fgl.yacc"
    {start_state("dtime_val",0); strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 267:
#line 1920 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 268:
#line 1921 "fgl.yacc"
    {strcpy(yyval.str,"2");}
    break;

  case 269:
#line 1922 "fgl.yacc"
    {strcpy(yyval.str,"3");}
    break;

  case 270:
#line 1923 "fgl.yacc"
    {strcpy(yyval.str,"4");}
    break;

  case 271:
#line 1924 "fgl.yacc"
    {strcpy(yyval.str,"5");}
    break;

  case 272:
#line 1925 "fgl.yacc"
    {strcpy(yyval.str,"6");}
    break;

  case 273:
#line 1927 "fgl.yacc"
    {
debug("opt_frac returns %s",yyvsp[0].str);
sprintf(yyval.str,"%d",atoi(yyvsp[0].str)+6); }
    break;

  case 274:
#line 1932 "fgl.yacc"
    {start_state("dtime_val",1);}
    break;

  case 275:
#line 1932 "fgl.yacc"
    { debug ("Got end");start_state("dtime_val",0);  strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 276:
#line 1935 "fgl.yacc"
    {
debug("Nothing in fraction - assume 2");
strcpy(yyval.str,"2");}
    break;

  case 277:
#line 1937 "fgl.yacc"
    {
debug("Read fraction .. ");
debug("    %s",yyvsp[-1].str);
strcpy(yyval.str,yyvsp[-1].str);
}
    break;

  case 278:
#line 1943 "fgl.yacc"
    {
debug("Nothing in fraction - assume 2");
strcpy(yyval.str,"2");}
    break;

  case 279:
#line 1945 "fgl.yacc"
    {
debug("    %s",yyvsp[-1].str);
strcpy(yyval.str,yyvsp[-1].str);
}
    break;

  case 280:
#line 1951 "fgl.yacc"
    {
if (atoi(yyvsp[0].str)>5) {
yyerror("Fraction values are between 0 and 5");
YYERROR;
}
}
    break;

  case 281:
#line 1959 "fgl.yacc"
    {start_state("interval_val",1);}
    break;

  case 282:
#line 1959 "fgl.yacc"
    {start_state("interval_val",0); sprintf(yyval.str,"%d",atoi(yyvsp[0].str)*16+atoi(yyvsp[-1].str));}
    break;

  case 283:
#line 1962 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 284:
#line 1963 "fgl.yacc"
    {strcpy(yyval.str,"2");}
    break;

  case 285:
#line 1964 "fgl.yacc"
    {strcpy(yyval.str,"3");}
    break;

  case 286:
#line 1965 "fgl.yacc"
    {strcpy(yyval.str,"4");}
    break;

  case 287:
#line 1966 "fgl.yacc"
    {strcpy(yyval.str,"5");}
    break;

  case 288:
#line 1967 "fgl.yacc"
    {strcpy(yyval.str,"6");}
    break;

  case 289:
#line 1969 "fgl.yacc"
    {
debug("opt_frac returns %s",yyvsp[0].str);
sprintf(yyval.str,"%d",atoi(yyvsp[0].str)+6); }
    break;

  case 293:
#line 1990 "fgl.yacc"
    {
              	dim_set_name(yyvsp[0].str);
              }
    break;

  case 297:
#line 1999 "fgl.yacc"
    {dim_push_type("char","1",0);}
    break;

  case 298:
#line 2001 "fgl.yacc"
    {dim_push_type("char",yyvsp[-1].str,0);}
    break;

  case 299:
#line 2003 "fgl.yacc"
    {dim_push_type("char",yyvsp[-1].str,0);}
    break;

  case 300:
#line 2005 "fgl.yacc"
    {dim_push_type("char",yyvsp[-3].str,0);}
    break;

  case 301:
#line 2006 "fgl.yacc"
    {dim_push_type("long",0,0);}
    break;

  case 302:
#line 2007 "fgl.yacc"
    {dim_push_type("integer",0,0);}
    break;

  case 303:
#line 2008 "fgl.yacc"
    {dim_push_type("FORM",0,0);}
    break;

  case 304:
#line 2009 "fgl.yacc"
    {
char buff[256];
sprintf(buff,"%d",16*256+2);
dim_push_type("fgldecimal",buff,0);
}
    break;

  case 305:
#line 2014 "fgl.yacc"
    {

char buff[256];
sprintf(buff,"%d",atoi(yyvsp[-1].str)*256+2);
dim_push_type("fgldecimal",buff,0);
}
    break;

  case 306:
#line 2021 "fgl.yacc"
    {
char buff[256];
sprintf(buff,"%d",atoi(yyvsp[-3].str)*256+atoi(yyvsp[-1].str));
dim_push_type("fgldecimal",buff,0);
}
    break;

  case 307:
#line 2026 "fgl.yacc"
    {dim_push_type("fglmoney",0,0);}
    break;

  case 308:
#line 2028 "fgl.yacc"
    {dim_push_type("fglmoney",0,0);}
    break;

  case 309:
#line 2030 "fgl.yacc"
    {dim_push_type("fglmoney",0,0);}
    break;

  case 310:
#line 2031 "fgl.yacc"
    {dim_push_type("double",0,0);}
    break;

  case 311:
#line 2032 "fgl.yacc"
    {dim_push_type("float",0,0);}
    break;

  case 312:
#line 2033 "fgl.yacc"
    {dim_push_type("fgldate",0,0);}
    break;

  case 313:
#line 2034 "fgl.yacc"
    {dim_push_type("fglbyte",0,0);}
    break;

  case 314:
#line 2035 "fgl.yacc"
    {dim_push_type("fgltext",0,0);}
    break;

  case 315:
#line 2036 "fgl.yacc"
    {
dim_push_type("struct_dtime",yyvsp[0].str,0);
}
    break;

  case 316:
#line 2039 "fgl.yacc"
    {dim_push_type("struct_ival",0,0);}
    break;

  case 317:
#line 2041 "fgl.yacc"
    {dim_push_like(yyvsp[0].str);lex_printcomment("/*added(XXXXX)\n */");}
    break;

  case 318:
#line 2047 "fgl.yacc"
    {
lex_printcomment("/*column like(ZZZ)\n*/");
sprintf(yyval.str,"%s.%s",yyvsp[-2].str,yyvsp[0].str)
; lex_printcomment ("/*set col...(ZZZ)\n*/");}
    break;

  case 319:
#line 2055 "fgl.yacc"
    {
dim_push_type(0,0,yyvsp[-1].str);
}
    break;

  case 321:
#line 2063 "fgl.yacc"
    {
dim_push_associate(yyvsp[-5].str,yyvsp[-1].str);
dim_push_type(0,0,yyvsp[-1].str);
}
    break;

  case 322:
#line 2067 "fgl.yacc"
    {
	/* void dim_pop_associate (char *a); */
	dim_pop_associate(0);
}
    break;

  case 323:
#line 2075 "fgl.yacc"
    {dim_push_record();}
    break;

  case 324:
#line 2076 "fgl.yacc"
    {dim_pop_record();}
    break;

  case 325:
#line 2077 "fgl.yacc"
    {dim_push_record();debug("Like\n");}
    break;

  case 326:
#line 2078 "fgl.yacc"
    {debug("Table:%s\n",yyvsp[-2].str);
                                  dim_push_rectab(yyvsp[-2].str);
                                  dim_pop_record();}
    break;

  case 332:
#line 2097 "fgl.yacc"
    { dim_push_name(yyval.str,0); }
    break;

  case 333:
#line 2109 "fgl.yacc"
    {
	print_display_line();
		strcpy(yyval.str,get_display_str(0,0,0));
	}
    break;

  case 334:
#line 2113 "fgl.yacc"
    {
		strcpy(yyval.str,get_display_str(1,0,0)); /* FIXME */
	}
    break;

  case 335:
#line 2116 "fgl.yacc"
    { 
	strcpy(yyval.str,"#error not implemented yet");
	}
    break;

  case 336:
#line 2119 "fgl.yacc"
    { strcpy(yyval.str, get_display_str(4,0,0)); }
    break;

  case 337:
#line 2120 "fgl.yacc"
    { strcpy(yyval.str, get_display_str(2,yyvsp[0].str,0)); }
    break;

  case 338:
#line 2121 "fgl.yacc"
    { strcpy(yyval.str, get_display_str(3,yyvsp[0].str,yyvsp[-2].str)); }
    break;

  case 339:
#line 2122 "fgl.yacc"
    { strcpy(yyval.str, get_display_str(5,yyvsp[-1].str,0)); }
    break;

  case 340:
#line 2123 "fgl.yacc"
    { 
	strcpy(yyval.str,"#error not implemented yet");
 }
    break;

  case 341:
#line 2129 "fgl.yacc"
    {
		print_display_by_name(yyvsp[0].str);
                }
    break;

  case 342:
#line 2136 "fgl.yacc"
    { 
				print_display(yyvsp[-1].str,yyvsp[-2].str,yyvsp[0].str);
		}
    break;

  case 343:
#line 2141 "fgl.yacc"
    {
		print_display_form(yyvsp[-1].str,yyvsp[0].str);
	}
    break;

  case 344:
#line 2146 "fgl.yacc"
    {
		push_blockcommand("DISPLAY");
		}
    break;

  case 345:
#line 2150 "fgl.yacc"
    {
		print_display_array_p1(yyvsp[-6].str,yyvsp[-4].str,yyvsp[-1].str,yyvsp[0].str);
		}
    break;

  case 346:
#line 2153 "fgl.yacc"
    {
		add_continue_blockcommand ("DISPLAY");  
		print_display_array_p2();
		pop_blockcommand("DISPLAY");
}
    break;

  case 347:
#line 2161 "fgl.yacc"
    {
strcpy(yyval.str,"0,0");
}
    break;

  case 348:
#line 2163 "fgl.yacc"
    {
	strcpy(yyval.str,yyvsp[0].str);
}
    break;

  case 349:
#line 2168 "fgl.yacc"
    {
				sprintf(yyval.str,"0x%lx",atol(yyvsp[0].str));
			}
    break;

  case 354:
#line 2180 "fgl.yacc"
    {
		print_befaft_field_1("AFT_ROW");
		}
    break;

  case 355:
#line 2183 "fgl.yacc"
    {
		print_befaft_field_2();
	}
    break;

  case 356:
#line 2186 "fgl.yacc"
    {
		print_befaft_field_1("BEF_ROW");
		}
    break;

  case 357:
#line 2189 "fgl.yacc"
    {
		print_befaft_field_2();
	}
    break;

  case 358:
#line 2192 "fgl.yacc"
    {
		print_onkey_1(yyvsp[0].str);
		}
    break;

  case 359:
#line 2195 "fgl.yacc"
    {
		print_onkey_2();
	}
    break;

  case 360:
#line 2208 "fgl.yacc"
    {
			print_error(yyvsp[0].str,0);
		}
    break;

  case 361:
#line 2211 "fgl.yacc"
    { 
			print_error(yyvsp[-1].str,1);
	}
    break;

  case 362:
#line 2226 "fgl.yacc"
    { if (in_command("WHILE")) { exit_loop("WHILE"); } else { YYERROR;} }
    break;

  case 363:
#line 2228 "fgl.yacc"
    { if (in_command("INPUT")) { exit_loop("INPUT"); } else { YYERROR;} }
    break;

  case 364:
#line 2230 "fgl.yacc"
    { if (in_command("FOREACH")) { exit_loop("FOREACH"); } else { YYERROR;} }
    break;

  case 365:
#line 2232 "fgl.yacc"
    { if (in_command("FOR")) { exit_loop("FOR"); } else { YYERROR;} }
    break;

  case 366:
#line 2234 "fgl.yacc"
    { if (in_command("CONSTRUCT")) { exit_loop("CONSTRUCT"); } else { YYERROR;} }
    break;

  case 367:
#line 2236 "fgl.yacc"
    { if (in_command("DISPLAY")) { exit_loop("DISPLAY"); } else { YYERROR;} }
    break;

  case 368:
#line 2237 "fgl.yacc"
    {
	if (in_command("MENU")) {
		exit_loop("MENU");
		/* lex_printc("cmd_no=-3;continue;\n"); */
	} 
              else YYERROR;}
    break;

  case 369:
#line 2244 "fgl.yacc"
    { if (in_command("CASE")) { exit_loop("CASE"); } else { YYERROR;} }
    break;

  case 370:
#line 2246 "fgl.yacc"
    { if (in_command("PROMPT")) { exit_loop("PROMPT"); } else { YYERROR;} }
    break;

  case 371:
#line 2250 "fgl.yacc"
    { if (in_command("WHILE")) { continue_loop("WHILE");  } else { YYERROR;} }
    break;

  case 372:
#line 2252 "fgl.yacc"
    { if (in_command("INPUT")) { continue_loop("INPUT"); } else { YYERROR;} }
    break;

  case 373:
#line 2254 "fgl.yacc"
    { if (in_command("FOREACH")) { continue_loop("FOREACH");} else { YYERROR;} }
    break;

  case 374:
#line 2256 "fgl.yacc"
    { if (in_command("FOR")) { continue_loop("FOR"); } else { YYERROR;} }
    break;

  case 375:
#line 2258 "fgl.yacc"
    { if (in_command("CONSTRUCT")) { continue_loop("CONSTRUCT"); } else { YYERROR;} }
    break;

  case 376:
#line 2260 "fgl.yacc"
    { if (in_command("DISPLAY")) { continue_loop("DISPLAY"); } else { YYERROR;} }
    break;

  case 377:
#line 2262 "fgl.yacc"
    { if (in_command("MENU")) {  continue_loop("MENU");  } else { YYERROR;} }
    break;

  case 378:
#line 2268 "fgl.yacc"
    { if (in_command("PROMPT")) { continue_loop("PROMPT"); } else { YYERROR;} }
    break;

  case 379:
#line 2282 "fgl.yacc"
    {
	print_exit_program(0);
}
    break;

  case 380:
#line 2285 "fgl.yacc"
    {
	print_exit_program(1);
}
    break;

  case 385:
#line 2302 "fgl.yacc"
    {
	dec_counter();
	yyval.ptr=append_expr_expr(yyvsp[-1].ptr,yyvsp[0].ptr);
}
    break;

  case 388:
#line 2308 "fgl.yacc"
    {
	debug("Got literal ptr=%p",yyvsp[0].ptr);
}
    break;

  case 389:
#line 2312 "fgl.yacc"
    {
	yyval.ptr=new_expr("push_int(0);");
	yyval.ptr=append_expr_expr(yyval.ptr,yyvsp[0].ptr);
	yyval.ptr=append_expr(yyval.ptr,"pushop(OP_SUB);");
}
    break;

  case 390:
#line 2317 "fgl.yacc"
    {
	yyval.ptr=yyvsp[0].ptr;
}
    break;

  case 394:
#line 2327 "fgl.yacc"
    { yyval.ptr=new_expr("add_spaces();"); }
    break;

  case 401:
#line 2338 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 402:
#line 2338 "fgl.yacc"
    {
strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 404:
#line 2343 "fgl.yacc"
    {yyval.ptr=new_expr("push_null()");}
    break;

  case 405:
#line 2347 "fgl.yacc"
    {
	/*set_counter(0);*/
	sprintf(yyval.str,"%d",get_counter_val());
	lex_printcomment("/*L1 %s*/\n",yyval.str);
}
    break;

  case 406:
#line 2353 "fgl.yacc"
    {
	sprintf(yyval.str,"%d",get_counter_val());
	lex_printcomment("/*L2 %s*/\n",yyval.str);
}
    break;

  case 407:
#line 2361 "fgl.yacc"
    {
	/*set_counter(0);*/
	sprintf(yyval.str,"%d",get_counter_val());
	lex_printcomment("/*L1 %s*/\n",yyval.str);
}
    break;

  case 408:
#line 2367 "fgl.yacc"
    {
	sprintf(yyval.str,"%d",get_counter_val());
	lex_printcomment("/*L2 %s*/\n",yyval.str);
}
    break;

  case 409:
#line 2376 "fgl.yacc"
    {sprintf(yyval.str,"%d",get_counter_val());}
    break;

  case 410:
#line 2378 "fgl.yacc"
    {
	print_op("OP_CONCAT");
	dec_counter();sprintf(yyval.str,"%d",get_counter_val());
}
    break;

  case 411:
#line 2385 "fgl.yacc"
    {
	debug("Print expr (2)");
	print_expr(yyvsp[0].ptr);
}
    break;

  case 412:
#line 2393 "fgl.yacc"
    {
	strcpy(yyval.str,"+");
}
    break;

  case 413:
#line 2397 "fgl.yacc"
    {
	strcpy(yyval.str,"-");
}
    break;

  case 414:
#line 2406 "fgl.yacc"
    {
	
	yyval.ptr=append_expr(yyvsp[0].ptr,"pushop(OP_NOT);");
}
    break;

  case 415:
#line 2411 "fgl.yacc"
    {
	yyval.ptr=new_expr("push_int(1);");
        inc_counter();
}
    break;

  case 416:
#line 2416 "fgl.yacc"
    {
	inc_counter();
	yyval.ptr=new_expr("push_int(0);");
}
    break;

  case 417:
#line 2420 "fgl.yacc"
    { yyval.ptr=yyvsp[-1].ptr; }
    break;

  case 418:
#line 2422 "fgl.yacc"
    {
	char buff[256];
	int n;
	yyval.ptr=new_expr(yyvsp[-1].str);
	append_expr(yyval.ptr,"{");
	n=print_bind_expr(yyval.ptr,'i');
	sprintf(buff,"push_binding(ibind,%d);}",n);
	append_expr(yyval.ptr,buff);
	append_expr(yyval.ptr,"pushop(OP_EXISTS);");
}
    break;

  case 419:
#line 2432 "fgl.yacc"
    {
	char buff[256];
	int n;
	yyval.ptr=new_expr(yyvsp[-1].str);
	append_expr(yyval.ptr,"{");
	n=print_bind_expr(yyval.ptr,'i');
	sprintf(buff,"push_binding(ibind,%d);}",n);
	append_expr(yyval.ptr,buff);
	append_expr(yyval.ptr,"pushop(OP_NOTEXISTS);");
}
    break;

  case 420:
#line 2446 "fgl.yacc"
    {
	debug("init expr %s %s",yyvsp[-1].str,yyvsp[0].str);
	sprintf(yyval.str,"%s%p",yyvsp[-1].str,yyvsp[0].str);
	sprintf(yyval.str,"%s",get_push_literal('D',yyval.str));
	yyval.ptr=new_expr(yyval.str);
        inc_counter();
}
    break;

  case 421:
#line 2454 "fgl.yacc"
    {
	debug("init expr int %s %d",yyvsp[-1].str,atoi(yyvsp[0].str));
	sprintf(yyval.str,"%s%p",yyvsp[-1].str,yyvsp[0].str);
	sprintf(yyval.str,"%s",get_push_literal('L',yyval.str));
	yyval.ptr=new_expr(yyval.str);
	inc_counter();
}
    break;

  case 422:
#line 2466 "fgl.yacc"
    {
	sprintf(yyval.str,"%s",get_push_literal('S',yyvsp[0].str));
	yyval.ptr=new_expr(yyval.str);
	inc_counter();
}
    break;

  case 423:
#line 2472 "fgl.yacc"
    {
	sprintf(yyval.str,"%s",get_push_literal('D',yyvsp[0].str));
	yyval.ptr=new_expr(yyval.str);
	inc_counter();
}
    break;

  case 424:
#line 2478 "fgl.yacc"
    {
	sprintf(yyval.str,"%s",get_push_literal('L',yyvsp[0].str));
	yyval.ptr=new_expr(yyval.str);
	inc_counter();
}
    break;

  case 427:
#line 2488 "fgl.yacc"
    {
		sprintf(yyval.str,"%s\n%s",yyvsp[-2].str,yyvsp[0].str);
	}
    break;

  case 428:
#line 2494 "fgl.yacc"
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
          		if (aubit_strcasecmp(yyvsp[0].str,"today")==0) {
               		flg=1;
               		strcpy(yyval.str,"push_today();");
          		}
		
          		if (aubit_strcasecmp(yyvsp[0].str,"time")==0) {
               		flg=1;
               		strcpy(yyval.str,"push_time();");
          		}
		
          		if (aubit_strcasecmp(yyvsp[0].str,"pageno")==0) {
               		flg=1;
               		strcpy(yyval.str,"push_variable(&rep.page_no,2);");
                  		}
          		if (aubit_strcasecmp(yyvsp[0].str,"lineno")==0) {
               		flg=1;
               		strcpy(yyval.str,"push_variable(&rep.line_no,2);");
          		}

         		if (flg==0) {
         				sprintf(yyval.str,"push_variable(&%s,0x%x);",yyvsp[0].str,(int)scan_variable(yyvsp[0].str));
         		}
      			p1=new_expr(yyval.str);
       			yyval.ptr=p1;
			inc_counter();
   		}



        	if (a==-1)
        	{
                	sprintf(yyval.str,"push_char(%s);",yyvsp[0].str);inc_counter();
      			p1=new_expr(yyval.str);
       			yyval.ptr=p1;
			inc_counter();
        	}


        	if (a==-2)
        	{
			p1=new_expr("");
	        	incvcnt=print_push_rec(yyvsp[0].str,&p1);
	        	inc_counter_by(incvcnt);
			yyval.ptr=p1;
        	}




	}
    break;

  case 429:
#line 2566 "fgl.yacc"
    {
	sprintf(yyval.str,"%sset_column(&rep);",ispdf());
	yyval.ptr=append_expr(yyvsp[0].ptr,yyval.str);
}
    break;

  case 430:
#line 2572 "fgl.yacc"
    {
sprintf(yyval.str,"%sset_column(&rep);",ispdf());
yyval.ptr=append_expr(yyvsp[0].ptr,yyval.str);
}
    break;

  case 431:
#line 2576 "fgl.yacc"
    {
   if (!in_command("REPORT")) {
   yyerror("This can only be done in a report!");
   YYERROR;
} 
insql=0;
	yyval.ptr=new_expr(yyvsp[0].str);
}
    break;

  case 432:
#line 2584 "fgl.yacc"
    {insql=1;set_ingroup();}
    break;

  case 433:
#line 2584 "fgl.yacc"
    {
	char buff[256];
      if (!in_command("REPORT")) {
        yyerror("This can only be done in a report!");YYERROR;
      } 
      insql=0; 
	lex_printcomment("/* rep_Agg = %s\n*/",yyvsp[0].str);
        strcpy(buff,yyvsp[0].str);
	debug("report aggregate :  %s",buff);
	yyval.ptr=new_expr(buff);
      }
    break;

  case 434:
#line 2601 "fgl.yacc"
    {
	yyval.ptr=append_expr(yyvsp[0].ptr,"pushop(OP_AND);");
}
    break;

  case 435:
#line 2605 "fgl.yacc"
    {
	yyval.ptr=append_expr(yyvsp[0].ptr,"pushop(OP_OR);");
}
    break;

  case 436:
#line 2611 "fgl.yacc"
    {
	yyval.ptr=yyvsp[0].ptr;
	}
    break;

  case 437:
#line 2614 "fgl.yacc"
    {
		debug("Adding to list...");
		yyval.ptr=append_expr_expr(yyvsp[-2].ptr,yyvsp[0].ptr);
	}
    break;

  case 438:
#line 2622 "fgl.yacc"
    {
	char buff[256];
	int n;
	yyval.ptr=new_expr(yyvsp[-1].str);
	append_expr(yyval.ptr,"{");
	n=print_bind_expr(yyval.ptr,'i');
	sprintf(buff,"push_binding(ibind,%d);}",n);
	append_expr(yyval.ptr,buff);
	append_expr(yyval.ptr,"pushop(OP_IN_SELECT);");
}
    break;

  case 439:
#line 2633 "fgl.yacc"
    {
	char buff[256];
	int n;
	yyval.ptr=new_expr(yyvsp[-1].str);
	append_expr(yyval.ptr,"{");
	n=print_bind_expr(yyval.ptr,'i');
	sprintf(buff,"push_binding(ibind,%d);}",n);
	append_expr(yyval.ptr,buff);
	append_expr(yyval.ptr,"pushop(OP_NOTIN_SELECT);");
}
    break;

  case 440:
#line 2643 "fgl.yacc"
    {
	char buff[256];
	sprintf(buff,"push_int(%d);",length_expr(yyvsp[-1].ptr));
	yyval.ptr=append_expr(yyvsp[-1].ptr,buff);
	append_expr(yyval.ptr,"pushop(OP_IN);");
}
    break;

  case 441:
#line 2649 "fgl.yacc"
    {
	char buff[256];
	sprintf(buff,"push_int(%d);",length_expr(yyvsp[-1].ptr));
	yyval.ptr=append_expr(yyvsp[-1].ptr,buff);
	append_expr(yyval.ptr,"pushop(OP_NOTIN);");
}
    break;

  case 442:
#line 2659 "fgl.yacc"
    { 
	strcpy(yyval.str,"pushop(OP_ISNULL);");
	yyval.ptr=new_expr(yyval.str);
}
    break;

  case 443:
#line 2664 "fgl.yacc"
    {
	strcpy(yyval.str,"pushop(OP_ISNOTNULL);");
	yyval.ptr=new_expr(yyval.str);
}
    break;

  case 444:
#line 2672 "fgl.yacc"
    {
	yyval.ptr=append_expr(yyvsp[0].ptr,"pushop(OP_MATCHES);");
}
    break;

  case 445:
#line 2676 "fgl.yacc"
    {
	yyval.ptr=append_expr(yyvsp[0].ptr,"pushop(OP_MATCHES);pushop(OP_NOT);");
}
    break;

  case 446:
#line 2680 "fgl.yacc"
    {
	yyval.ptr=append_expr(yyvsp[0].ptr,"pushop(OP_LIKE);");
}
    break;

  case 447:
#line 2684 "fgl.yacc"
    {
	yyval.ptr=append_expr(yyvsp[0].ptr,"pushop(OP_LIKE);pushop(OP_NOT);");
}
    break;

  case 448:
#line 2691 "fgl.yacc"
    {
	strcpy(yyval.str,"pushop(OP_CLIP);");
	yyval.ptr=new_expr(yyval.str);
	inc_counter();
}
    break;

  case 449:
#line 2699 "fgl.yacc"
    {
	sprintf(yyval.str,"%s pushop(OP_USING);",yyvsp[0].str);
	yyval.ptr=append_expr(yyvsp[0].ptr,"pushop(OP_USING);");
}
    break;

  case 450:
#line 2707 "fgl.yacc"
    {
	debug("PLUS in math_expr $<ptr>2 = %p",yyvsp[0].ptr);
	yyval.ptr=append_expr(yyvsp[0].ptr,"pushop(OP_ADD);");
}
    break;

  case 451:
#line 2712 "fgl.yacc"
    {
	yyval.ptr=append_expr(yyvsp[0].ptr,"pushop(OP_SUB);");
}
    break;

  case 452:
#line 2716 "fgl.yacc"
    {
      sprintf(yyval.str,"%s pushop(OP_MULT);",yyvsp[0].str);
	yyval.ptr=append_expr(yyvsp[0].ptr,"pushop(OP_MULT);");
}
    break;

  case 453:
#line 2721 "fgl.yacc"
    {
	yyval.ptr=append_expr(yyvsp[0].ptr,"pushop(OP_DIV);");
}
    break;

  case 454:
#line 2725 "fgl.yacc"
    {
	yyval.ptr=append_expr(yyvsp[0].ptr,"pushop(OP_MOD);");
}
    break;

  case 455:
#line 2729 "fgl.yacc"
    {
	yyval.ptr=append_expr(yyvsp[0].ptr,"pushop(OP_POWER);");
}
    break;

  case 456:
#line 2735 "fgl.yacc"
    {
	yyval.ptr=append_expr(yyvsp[0].ptr,"pushop(OP_EQUAL);");
}
    break;

  case 457:
#line 2738 "fgl.yacc"
    {
	yyval.ptr=append_expr(yyvsp[0].ptr,"pushop(OP_EQUAL);");
}
    break;

  case 458:
#line 2742 "fgl.yacc"
    {
	yyval.ptr=append_expr(yyvsp[0].ptr,"pushop(OP_LESS_THAN);");
}
    break;

  case 459:
#line 2746 "fgl.yacc"
    {
	yyval.ptr=append_expr(yyvsp[0].ptr,"pushop(OP_GREATER_THAN);");
}
    break;

  case 460:
#line 2750 "fgl.yacc"
    {
	yyval.ptr=append_expr(yyvsp[0].ptr,"pushop(OP_NOT_EQUAL);");
}
    break;

  case 461:
#line 2754 "fgl.yacc"
    {
	yyval.ptr=append_expr(yyvsp[0].ptr,"pushop(OP_LESS_THAN_EQ);");
}
    break;

  case 462:
#line 2758 "fgl.yacc"
    {
	yyval.ptr=append_expr(yyvsp[0].ptr,"pushop(OP_GREATER_THAN_EQ);");
}
    break;

  case 463:
#line 2765 "fgl.yacc"
    {
	reset_counter();
}
    break;

  case 464:
#line 2775 "fgl.yacc"
    { 
		addmap("Call",yyvsp[-1].str,curr_func,yylineno,infilename);
		new_counter(); 
		}
    break;

  case 465:
#line 2780 "fgl.yacc"
    { 
		sprintf(yyval.str,"%d",get_counter_val()); 
		lex_printcomment("/*function_call_expr2 %s*/\n",yyval.str);
		drop_counter(); 
		}
    break;

  case 466:
#line 2786 "fgl.yacc"
    {
		int cnt;
		cnt=1;
		debug("Print expr (1)");
		/* print_expr($<ptr>4); */
		sprintf(yyval.str,"{int _retvars;\n_retvars=aclfgl_%s(%s); {\nif (_retvars!= 1 ) {A4GLSQL_set_status(-3001,0);chk_err(%d,\"%s\");}\n}\n}\n", yyvsp[-5].str,yyvsp[-1].str, lastlineno,infilename);
		yyval.ptr=append_expr(yyvsp[-2].ptr,yyval.str);
		inc_counter();
		}
    break;

  case 467:
#line 2795 "fgl.yacc"
    {
        sprintf(yyval.str,"\"%s\",\"%s\"",get_idents(0),get_idents(1));
	debug("NEWFORMAT : %s\n",yyval.str);
        A4GLSQL_set_status(0,0);
        new_counter();
}
    break;

  case 468:
#line 2800 "fgl.yacc"
    {
	sprintf(yyval.str,"%d",get_counter_val());  
	drop_counter();
}
    break;

  case 469:
#line 2803 "fgl.yacc"
    {
	char buff[256];
        char *ptr;
        strcpy(buff,yyvsp[-3].str);
        ptr=strchr(buff,',');
        *ptr=0;
        ptr++;
	sprintf(yyval.str,"{int _retvars;\n_retvars=call_4gl_dll(%s,%s,%d); {\nif (_retvars!= 1 ) {A4GLSQL_set_status(-3001,0);chk_err(%d,\"%s\");pop_args(_retvars);push_null();}\n}\n}\n", buff,ptr,atoi(yyvsp[-1].str), lastlineno,infilename);
	yyval.ptr=append_expr(yyvsp[-2].ptr,yyval.str);
}
    break;

  case 470:
#line 2817 "fgl.yacc"
    {inc_counter();chk4var=1;}
    break;

  case 471:
#line 2817 "fgl.yacc"
    {chk4var=0;}
    break;

  case 472:
#line 2817 "fgl.yacc"
    {
	yyval.ptr=append_expr(yyvsp[-2].ptr,"aclfgl_date(1);");
inc_counter();}
    break;

  case 473:
#line 2820 "fgl.yacc"
    {inc_counter();chk4var=1;}
    break;

  case 474:
#line 2820 "fgl.yacc"
    {chk4var=0;}
    break;

  case 475:
#line 2820 "fgl.yacc"
    {
	yyval.ptr=append_expr(yyvsp[-2].ptr,"aclfgl_month(1);");
inc_counter();}
    break;

  case 476:
#line 2823 "fgl.yacc"
    {inc_counter();chk4var=1;}
    break;

  case 477:
#line 2823 "fgl.yacc"
    {chk4var=0;}
    break;

  case 478:
#line 2823 "fgl.yacc"
    {
	yyval.ptr=append_expr(yyvsp[-2].ptr,"aclfgl_day(1);");
inc_counter();}
    break;

  case 479:
#line 2826 "fgl.yacc"
    {inc_counter();chk4var=1;}
    break;

  case 480:
#line 2826 "fgl.yacc"
    {chk4var=0;}
    break;

  case 481:
#line 2826 "fgl.yacc"
    {
	yyval.ptr=append_expr(yyvsp[-2].ptr,"aclfgl_year(1);");
inc_counter();}
    break;

  case 482:
#line 2829 "fgl.yacc"
    {
	char buff[256];
	sprintf(buff,"acli_interval(%s,%s);",yyvsp[-2].str,yyvsp[0].str);
	yyval.ptr=new_expr(buff);
	inc_counter();
}
    break;

  case 483:
#line 2835 "fgl.yacc"
    {
	char buff[256];
	sprintf(buff,"acli_datetime(%s,%s)",yyvsp[-2].str,yyvsp[0].str);
	yyval.ptr=new_expr(buff);
	inc_counter();
}
    break;

  case 484:
#line 2841 "fgl.yacc"
    {
	char buff[256];
	sprintf(buff,"acli_datetime(\"%s\",%s)",yyvsp[-2].str,yyvsp[0].str);
	yyval.ptr=new_expr(buff);
	inc_counter();
}
    break;

  case 485:
#line 2847 "fgl.yacc"
    {
	char buff[256];
	sprintf(buff,"acli_datetime(\"%s:%s\",%s)",yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str);
	yyval.ptr=new_expr(buff);
	inc_counter();
}
    break;

  case 486:
#line 2857 "fgl.yacc"
    {strcpy(yyval.str,"-1,-1");}
    break;

  case 487:
#line 2858 "fgl.yacc"
    {sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 490:
#line 2866 "fgl.yacc"
    {
sprintf(yyval.str,"{int _retvars;\n_retvars=fgl_getfldbuf(%s);\nif (_retvars != 1 ) {A4GLSQL_set_status(-3001,0);chk_err(%d,\"%s\");}\n}\n",
	yyvsp[-1].str, lastlineno,infilename); 
	yyval.ptr=new_expr(yyval.str);

}
    break;

  case 491:
#line 2872 "fgl.yacc"
    {sprintf(yyval.str,"push_int(fgl_fieldnametoid(\"\",%s));",yyvsp[-1].str); yyval.ptr=new_expr(yyval.str); }
    break;

  case 492:
#line 2873 "fgl.yacc"
    {
sprintf(yyval.str,"push_int(fgl_fieldnametoid(\"\",%s));",yyvsp[-1].str); yyval.ptr=new_expr(yyval.str); 
addmap("Get Field",yyvsp[-1].str,curr_func,yylineno,infilename);
}
    break;

  case 493:
#line 2878 "fgl.yacc"
    {sprintf(yyval.str,"push_int(fgl_infield(%s));",yyvsp[-1].str); 
	yyval.ptr=new_expr(yyval.str);
}
    break;

  case 494:
#line 2882 "fgl.yacc"
    { sprintf(yyval.str,"push_int(fgl_fieldtouched(%s));",yyvsp[-1].str); 
	yyval.ptr=new_expr(yyval.str);
}
    break;

  case 495:
#line 2886 "fgl.yacc"
    { sprintf(yyval.str,"push_int(!fgl_fieldtouched(%s));",yyvsp[-1].str); 
	yyval.ptr=new_expr(yyval.str);
}
    break;

  case 498:
#line 2893 "fgl.yacc"
    {
		inc_counter();
               sprintf(yyval.str,"push_current(%s);",yyvsp[0].str);
		yyval.ptr=new_expr(yyval.str);
          	}
    break;

  case 499:
#line 2898 "fgl.yacc"
    { inc_counter(); strcpy(yyval.str,"push_today();");
		yyval.ptr=new_expr(yyval.str);
		}
    break;

  case 500:
#line 2905 "fgl.yacc"
    { 
	yyval.ptr=append_expr(yyvsp[-1].ptr,"upshift_stk();");
}
    break;

  case 501:
#line 2909 "fgl.yacc"
    { 
	yyval.ptr=append_expr(yyvsp[-1].ptr,"downshift_stk();");
}
    break;

  case 502:
#line 2912 "fgl.yacc"
    { 
	yyval.ptr=append_expr(yyvsp[0].ptr,"push_ascii();");
}
    break;

  case 503:
#line 2915 "fgl.yacc"
    { 
	yyval.ptr=append_expr(yyvsp[0].ptr,"aclfgli_extend();"); }
    break;

  case 504:
#line 2921 "fgl.yacc"
    {
	yyval.ptr=append_expr(yyvsp[-1].ptr,"push_double(-1);pushop(OP_MULT);");
}
    break;

  case 505:
#line 2924 "fgl.yacc"
    {
	yyval.ptr=append_expr(yyvsp[-1].ptr,"push_double(-28.3465);pushop(OP_MULT);");
}
    break;

  case 506:
#line 2927 "fgl.yacc"
    {
	yyval.ptr=append_expr(yyvsp[-1].ptr,"push_double(-72.0);pushop(OP_MULT);");
}
    break;

  case 507:
#line 2942 "fgl.yacc"
    {
	strcpy(yyval.str,yyvsp[0].str);
}
    break;

  case 508:
#line 2945 "fgl.yacc"
    {
	strcpy(yyval.str,yyvsp[0].str);
}
    break;

  case 509:
#line 2951 "fgl.yacc"
    {sprintf(yyval.str,"-%s",yyvsp[0].str);}
    break;

  case 510:
#line 2952 "fgl.yacc"
    {sprintf(yyval.str,"\"%s\"",yyvsp[0].str);}
    break;

  case 511:
#line 2953 "fgl.yacc"
    {sprintf(yyval.str,"\"%s\"",yyvsp[0].str);}
    break;

  case 513:
#line 2958 "fgl.yacc"
    {sprintf(yyval.str,"%s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 514:
#line 2959 "fgl.yacc"
    {sprintf(yyval.str,"%s %s:%s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 515:
#line 2960 "fgl.yacc"
    {sprintf(yyval.str,"%s %s:%s:%s",yyvsp[-5].str,yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 516:
#line 2961 "fgl.yacc"
    {sprintf(yyval.str,"%s %s:%s:%s",yyvsp[-5].str,yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 517:
#line 2963 "fgl.yacc"
    {sprintf(yyval.str,"%s:%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 518:
#line 2964 "fgl.yacc"
    {sprintf(yyval.str,"%s:%s:%s",yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 519:
#line 2965 "fgl.yacc"
    {sprintf(yyval.str,"%s:%s:%s",yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 520:
#line 2967 "fgl.yacc"
    {sprintf(yyval.str,"%s:%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 521:
#line 2968 "fgl.yacc"
    {sprintf(yyval.str,"%s",yyvsp[0].str);}
    break;

  case 523:
#line 2974 "fgl.yacc"
    {sprintf(yyval.str,"%s-%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 524:
#line 2987 "fgl.yacc"
    {
print_for_start(yyvsp[-5].str);
push_blockcommand("FOR");
}
    break;

  case 525:
#line 2991 "fgl.yacc"
    {debug("For_cmds\n");}
    break;

  case 526:
#line 2992 "fgl.yacc"
    {

pop_blockcommand("FOR");
print_for_end();
lex_printcomment(" /*END FOR*/\n");}
    break;

  case 527:
#line 2999 "fgl.yacc"
    {
		print_for_default_step();
	}
    break;

  case 529:
#line 3016 "fgl.yacc"
    {
push_blockcommand("FOREACH");
}
    break;

  case 530:
#line 3020 "fgl.yacc"
    {
print_foreach_start();
lex_printcomment(" /* foreach */\n");
}
    break;

  case 531:
#line 3025 "fgl.yacc"
    {
print_foreach_next(yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 532:
#line 3029 "fgl.yacc"
    {
add_continue_blockcommand ("FOREACH");
print_foreach_end();
pop_blockcommand("FOREACH");
}
    break;

  case 533:
#line 3045 "fgl.yacc"
    {
		sprintf(curr_func,"%s",yyvsp[0].str); 
		print_formhandler(yyvsp[0].str);
		start_state("formhandler",1);
	push_blockcommand("FORMHANDLER");
        }
    break;

  case 534:
#line 3051 "fgl.yacc"
    {
		print_variables();
		print_getwin();
	}
    break;

  case 535:
#line 3059 "fgl.yacc"
    {
pop_blockcommand("FORMHANDLER");
print_end_formhandler(); 
start_state("formhandler",0);}
    break;

  case 542:
#line 3076 "fgl.yacc"
    {
		print_event('B');
        }
    break;

  case 543:
#line 3078 "fgl.yacc"
    {
		print_event_2();
        }
    break;

  case 544:
#line 3081 "fgl.yacc"
    {
		print_event('b');
        }
    break;

  case 545:
#line 3083 "fgl.yacc"
    {
		print_event_2();
        }
    break;

  case 550:
#line 3097 "fgl.yacc"
    {
		print_event('A');
        }
    break;

  case 551:
#line 3099 "fgl.yacc"
    {
		print_event_2();
        }
    break;

  case 552:
#line 3102 "fgl.yacc"
    {
		print_event('a');
        }
    break;

  case 553:
#line 3104 "fgl.yacc"
    {
		print_event_2();
        }
    break;

  case 566:
#line 3135 "fgl.yacc"
    { 
			print_gtk_field('B',0);
		}
    break;

  case 567:
#line 3137 "fgl.yacc"
    {
			print_gtk_field_2();
		}
    break;

  case 568:
#line 3140 "fgl.yacc"
    { 
			print_gtk_field('A',0);
		}
    break;

  case 569:
#line 3142 "fgl.yacc"
    {
			print_gtk_field_2();
		}
    break;

  case 570:
#line 3145 "fgl.yacc"
    {
			print_gtk_field('b',yyvsp[0].str);
		}
    break;

  case 571:
#line 3147 "fgl.yacc"
    { 
			print_gtk_field_2();
		}
    break;

  case 572:
#line 3150 "fgl.yacc"
    {
			print_gtk_field('a',yyvsp[0].str);
		}
    break;

  case 573:
#line 3152 "fgl.yacc"
    { 
			print_gtk_field_2();
		}
    break;

  case 574:
#line 3155 "fgl.yacc"
    { 
			print_gtk_field('o',yyvsp[0].str);
		}
    break;

  case 575:
#line 3157 "fgl.yacc"
    { 
			print_gtk_field_2();
		}
    break;

  case 576:
#line 3172 "fgl.yacc"
    {
		//print_niy("Free Cursor");
		lex_printcomment(" /* FIXME: Not implemented: Free Cursor */\n");;

		strcpy(yyval.str,"");
		}
    break;

  case 577:
#line 3188 "fgl.yacc"
    {sprintf(yyval.str,"%d",-1-(atoi(yyvsp[0].str)));}
    break;

  case 578:
#line 3189 "fgl.yacc"
    {strcpy(yyval.str,"-1");}
    break;

  case 579:
#line 3190 "fgl.yacc"
    {sprintf (yyval.str,"%d",atoi(yyvsp[0].str)+1);}
    break;

  case 580:
#line 3191 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 581:
#line 3192 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 582:
#line 3193 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 586:
#line 3201 "fgl.yacc"
    {sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str); }
    break;

  case 588:
#line 3207 "fgl.yacc"
    {
			sprintf(yyval.str,"\"%s\",1",yyvsp[0].str);}
    break;

  case 589:
#line 3209 "fgl.yacc"
    { sprintf(yyval.str,"int_to_id(%s)",yyvsp[-1].str); }
    break;

  case 590:
#line 3210 "fgl.yacc"
    { sprintf(yyval.str,"int_to_id(%s.%s)",yyvsp[-5].str,yyvsp[-1].str); }
    break;

  case 591:
#line 3212 "fgl.yacc"
    {sprintf(yyval.str,"\"%s\",%s",yyvsp[-3].str,yyvsp[-1].str);}
    break;

  case 592:
#line 3214 "fgl.yacc"
    {sprintf(yyval.str,"\"%s.*\",1",yyvsp[-2].str);}
    break;

  case 593:
#line 3216 "fgl.yacc"
    {sprintf(yyval.str,"\"%s.*\",%s",yyvsp[-5].str,yyvsp[-3].str);}
    break;

  case 594:
#line 3218 "fgl.yacc"
    {sprintf(yyval.str,"\"%s.%s\",1",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 595:
#line 3220 "fgl.yacc"
    {sprintf(yyval.str,"\"%s.%s\",%s",yyvsp[-5].str,yyvsp[0].str,yyvsp[-3].str);}
    break;

  case 596:
#line 3223 "fgl.yacc"
    {
				print_pushchar(yyvsp[0].str);
				addmap("Cursor",last_var,curr_func,yylineno,infilename);
			}
    break;

  case 597:
#line 3230 "fgl.yacc"
    {sprintf(yyval.str,"%s",yyvsp[0].str);}
    break;

  case 598:
#line 3232 "fgl.yacc"
    {sprintf(yyval.str,"%s",yyvsp[0].str);
addmap("Window",last_var,curr_func,yylineno,infilename);
}
    break;

  case 599:
#line 3238 "fgl.yacc"
    {sprintf(yyval.str,"%s",yyvsp[0].str);
addmap("Open Window",last_var,curr_func,yylineno,infilename);
}
    break;

  case 600:
#line 3243 "fgl.yacc"
    {sprintf(yyval.str,"%s",yyvsp[0].str);
addmap("Form",last_var,curr_func,yylineno,infilename);
}
    break;

  case 601:
#line 3248 "fgl.yacc"
    {sprintf(yyval.str,"%s",yyvsp[0].str);
addmap("Open Form",last_var,curr_func,yylineno,infilename);
}
    break;

  case 602:
#line 3253 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 603:
#line 3253 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 604:
#line 3256 "fgl.yacc"
    { 
			strcpy(yyval.str,downshift(yyvsp[-1].str)) ;
}
    break;

  case 605:
#line 3262 "fgl.yacc"
    {
			sprintf(yyval.str,"%s",yyvsp[-1].str) ;
			}
    break;

  case 606:
#line 3267 "fgl.yacc"
    {
sprintf(yyval.str,"\"%s_%s\"",clobber,downshift(yyvsp[0].str)) ;
strcpy(last_var,downshift(yyvsp[0].str));
}
    break;

  case 607:
#line 3271 "fgl.yacc"
    {
		sprintf(yyval.str,"aclfgli_str_to_id(%s)",yyvsp[-1].str);
		sprintf(last_var,"->%s",yyvsp[-1].str);
	}
    break;

  case 610:
#line 3279 "fgl.yacc"
    {
		debug("Setident\n");
		/* chk4var=1; */
	strcpy(yyval.str,"");
	   }
    break;

  case 611:
#line 3285 "fgl.yacc"
    {
		debug("Unsetident\n");
		chk4var=0;
		}
    break;

  case 612:
#line 3289 "fgl.yacc"
    {sprintf(yyval.str,"\"%s\",1",yyvsp[0].str);}
    break;

  case 613:
#line 3291 "fgl.yacc"
    {sprintf(yyval.str,"\"%s\",%s",yyvsp[-3].str,yyvsp[-1].str);}
    break;

  case 614:
#line 3293 "fgl.yacc"
    {sprintf(yyval.str,"\"%s.*\",1",yyvsp[-2].str);}
    break;

  case 615:
#line 3295 "fgl.yacc"
    {sprintf(yyval.str,"\"%s.*\",%s",yyvsp[-5].str,yyvsp[-3].str);}
    break;

  case 616:
#line 3297 "fgl.yacc"
    {sprintf(yyval.str,"\"%s.%s\",1",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 617:
#line 3299 "fgl.yacc"
    {sprintf(yyval.str,"\"%s.%s\",%s",yyvsp[-5].str,yyvsp[0].str,yyvsp[-3].str);}
    break;

  case 618:
#line 3302 "fgl.yacc"
    {
debug("Scanvar=%d",scan_variable(yyvsp[0].str)&15);
if ((scan_variable(yyvsp[0].str)&15)!=0) {
yyerror("Only a character variable can be used for this");
YYERROR;
}
}
    break;

  case 620:
#line 3311 "fgl.yacc"
    {
		sprintf(yyval.str,".%s",yyvsp[0].str);
}
    break;

  case 664:
#line 3372 "fgl.yacc"
    {
	char buff[256];
	print_goto(yyvsp[0].str);
}
    break;

  case 665:
#line 3386 "fgl.yacc"
    {
print_gui_do_menuitems(yyvsp[0].str,'C');
}
    break;

  case 667:
#line 3393 "fgl.yacc"
    {sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 668:
#line 3396 "fgl.yacc"
    {
        sprintf(yyval.str,"\"%s\"",yyvsp[0].str);
}
    break;

  case 669:
#line 3402 "fgl.yacc"
    {
print_gui_do_menuitems(yyvsp[0].str,'U');
}
    break;

  case 670:
#line 3408 "fgl.yacc"
    {
print_gui_do_menuitems(yyvsp[0].str,'D');
}
    break;

  case 671:
#line 3412 "fgl.yacc"
    {
print_gui_do_fields(yyvsp[0].str,'D');
}
    break;

  case 672:
#line 3416 "fgl.yacc"
    {
print_gui_do_form(yyvsp[-2].str,yyvsp[0].str,'D');
}
    break;

  case 673:
#line 3422 "fgl.yacc"
    {
print_gui_do_menuitems(yyvsp[0].str,'E');
}
    break;

  case 674:
#line 3426 "fgl.yacc"
    {
print_gui_do_fields(yyvsp[0].str,'E');
}
    break;

  case 675:
#line 3430 "fgl.yacc"
    {
print_gui_do_form(yyvsp[-2].str,yyvsp[0].str,'E');
}
    break;

  case 676:
#line 3435 "fgl.yacc"
    {start_state("messagebox",1);}
    break;

  case 677:
#line 3440 "fgl.yacc"
    {start_state("messagebox",0);}
    break;

  case 696:
#line 3481 "fgl.yacc"
    {
		print_if_start();
	}
    break;

  case 697:
#line 3486 "fgl.yacc"
    {
		print_if_end();
	}
    break;

  case 699:
#line 3491 "fgl.yacc"
    {
		print_if_else();
	}
    break;

  case 701:
#line 3494 "fgl.yacc"
    {
		print_if_else();
		}
    break;

  case 702:
#line 3496 "fgl.yacc"
    {

		print_if_start();
	}
    break;

  case 703:
#line 3499 "fgl.yacc"
    {
		print_if_end();
	}
    break;

  case 704:
#line 3504 "fgl.yacc"
    {
	print_import(yyvsp[-3].str,atoi(yyvsp[-1].str));
}
    break;

  case 705:
#line 3509 "fgl.yacc"
    { add_ex_dtype(yyvsp[0].str); }
    break;

  case 706:
#line 3519 "fgl.yacc"
    {debug("init to\n");}
    break;

  case 707:
#line 3520 "fgl.yacc"
    {
	print_init();
 }
    break;

  case 708:
#line 3523 "fgl.yacc"
    {
	print_init_table(yyvsp[0].str);
}
    break;

  case 710:
#line 3529 "fgl.yacc"
    {sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 711:
#line 3533 "fgl.yacc"
    {setrecord(yyval.str,yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 712:
#line 3534 "fgl.yacc"
    {setrecord(yyval.str,yyvsp[-2].str,0);}
    break;

  case 715:
#line 3548 "fgl.yacc"
    {
sprintf(yyval.str,"0");
}
    break;

  case 716:
#line 3550 "fgl.yacc"
    {
sprintf(yyval.str,"1");
}
    break;

  case 719:
#line 3559 "fgl.yacc"
    {
		print_befaft_field_1(yyvsp[0].str);
}
    break;

  case 720:
#line 3561 "fgl.yacc"
    {
	print_befaft_field_2();
}
    break;

  case 721:
#line 3565 "fgl.yacc"
    {
		print_befaft_field_1(yyvsp[0].str);
}
    break;

  case 722:
#line 3567 "fgl.yacc"
    {
	print_befaft_field_2();
}
    break;

  case 723:
#line 3570 "fgl.yacc"
    {
		print_befaft_field_1("AFT_ROW");
}
    break;

  case 724:
#line 3572 "fgl.yacc"
    {
	print_befaft_field_2();
}
    break;

  case 725:
#line 3575 "fgl.yacc"
    {
		lex_printcomment("/* before row */ \n");
		print_befaft_field_1("BEF_ROW");
}
    break;

  case 726:
#line 3578 "fgl.yacc"
    {
	print_befaft_field_2();
		}
    break;

  case 727:
#line 3581 "fgl.yacc"
    {
	print_onkey_1(yyvsp[0].str);
}
    break;

  case 728:
#line 3583 "fgl.yacc"
    {
	print_onkey_2();
}
    break;

  case 729:
#line 3586 "fgl.yacc"
    {
		print_befaft_field_1("AFTER_INP");
}
    break;

  case 730:
#line 3588 "fgl.yacc"
    {
	print_befaft_field_2();
}
    break;

  case 731:
#line 3591 "fgl.yacc"
    {
		print_befaft_field_1("BEFORE_INP");
}
    break;

  case 732:
#line 3593 "fgl.yacc"
    {
	print_befaft_field_2();
}
    break;

  case 733:
#line 3596 "fgl.yacc"
    {lex_printcomment("/* before insert/delete */ \n");
		print_befaft_field_1(yyvsp[0].str);
}
    break;

  case 734:
#line 3598 "fgl.yacc"
    {
	print_befaft_field_2();
}
    break;

  case 735:
#line 3601 "fgl.yacc"
    {
		print_befaft_field_1(yyvsp[0].str);
}
    break;

  case 736:
#line 3603 "fgl.yacc"
    {
	print_befaft_field_2();
}
    break;

  case 737:
#line 3609 "fgl.yacc"
    {sprintf(yyval.str,"(%s)",yyvsp[0].str);}
    break;

  case 738:
#line 3610 "fgl.yacc"
    {
	char buff[256];
	sprintf(buff,"(%s)",yyvsp[0].str);
	generate_or(yyval.str,yyvsp[-2].str,buff);
	}
    break;

  case 739:
#line 3618 "fgl.yacc"
    {strcpy(yyval.str,"AFT_INSERT");}
    break;

  case 740:
#line 3619 "fgl.yacc"
    {strcpy(yyval.str,"AFT_DELETE");}
    break;

  case 741:
#line 3624 "fgl.yacc"
    {sprintf(yyval.str,"(%s)",yyvsp[0].str);}
    break;

  case 742:
#line 3625 "fgl.yacc"
    {
	char buff[80];
		sprintf(buff,"(%s)",yyvsp[0].str);
		generate_or(yyval.str,yyvsp[-2].str,yyvsp[0].str);
 }
    break;

  case 743:
#line 3634 "fgl.yacc"
    {strcpy(yyval.str,"BEF_INSERT");}
    break;

  case 744:
#line 3635 "fgl.yacc"
    {strcpy(yyval.str,"BEF_DELETE");}
    break;

  case 745:
#line 3642 "fgl.yacc"
    {sprintf(yyval.str,"BEF_FIELD_CHK(%s)",yyvsp[0].str);}
    break;

  case 746:
#line 3643 "fgl.yacc"
    {
	char buff[80];
	sprintf(buff,"BEF_FIELD_CHK(%s)",yyvsp[0].str);
	generate_or(yyval.str,yyvsp[-2].str,buff);
	}
    break;

  case 747:
#line 3651 "fgl.yacc"
    {sprintf(yyval.str,"AFT_FIELD_CHK(%s)",yyvsp[0].str);}
    break;

  case 748:
#line 3652 "fgl.yacc"
    {
	char buff[80];
	sprintf(buff,"AFT_FIELD_CHK(%s)",yyvsp[0].str);
	generate_or(yyval.str,yyvsp[-2].str,buff);
	}
    break;

  case 749:
#line 3661 "fgl.yacc"
    {
print_next_field(yyvsp[0].str);
}
    break;

  case 750:
#line 3666 "fgl.yacc"
    {
print_next_form_field(yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 751:
#line 3671 "fgl.yacc"
    {sprintf(yyval.str,"\"+\",0");}
    break;

  case 752:
#line 3672 "fgl.yacc"
    {sprintf(yyval.str,"\"-\",0");}
    break;

  case 754:
#line 3677 "fgl.yacc"
    {
print_input_1();
}
    break;

  case 755:
#line 3680 "fgl.yacc"
    {
print_input_2(yyvsp[-2].str);
}
    break;

  case 756:
#line 3688 "fgl.yacc"
    {
print_input(1,yyvsp[-2].str,yyvsp[-1].str,0);
strcpy(yyval.str,get_formloop_str(0));
}
    break;

  case 757:
#line 3693 "fgl.yacc"
    {
print_input(0,yyvsp[-4].str,yyvsp[-1].str,yyvsp[-2].str);
strcpy(yyval.str,get_formloop_str(0));
}
    break;

  case 758:
#line 3697 "fgl.yacc"
    {
inp_flags=0;}
    break;

  case 759:
#line 3699 "fgl.yacc"
    {
strcpy(yyval.str,print_input_array(yyvsp[-8].str,yyvsp[-2].str,yyvsp[-7].str,yyvsp[-5].str,yyvsp[0].str));
}
    break;

  case 760:
#line 3708 "fgl.yacc"
    {
		print_scroll(yyvsp[-1].str,yyvsp[0].str);
	}
    break;

  case 761:
#line 3713 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 762:
#line 3714 "fgl.yacc"
    {strcpy(yyval.str,"-1");}
    break;

  case 763:
#line 3715 "fgl.yacc"
    {sprintf(yyval.str,"%s",yyvsp[0].str);}
    break;

  case 764:
#line 3716 "fgl.yacc"
    {sprintf(yyval.str,"-%s",yyvsp[0].str);}
    break;

  case 765:
#line 3719 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 767:
#line 3725 "fgl.yacc"
    {iskey=1;}
    break;

  case 768:
#line 3725 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);iskey=0;}
    break;

  case 769:
#line 3727 "fgl.yacc"
    {strcpy(yyval.str,"->ANY");}
    break;

  case 770:
#line 3730 "fgl.yacc"
    {iskey=1;}
    break;

  case 771:
#line 3730 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);iskey=0;}
    break;

  case 772:
#line 3732 "fgl.yacc"
    {sprintf(yyval.str,"key_val(\"%s\")",yyvsp[0].str);iskey=0;}
    break;

  case 773:
#line 3736 "fgl.yacc"
    {start_state("keymode",1);iskey=1;}
    break;

  case 774:
#line 3736 "fgl.yacc"
    {sprintf(yyval.str,"key_val(\"%s\")",yyvsp[0].str);iskey=0;start_state("keymode",0);}
    break;

  case 775:
#line 3739 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 776:
#line 3740 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[-1].str);}
    break;

  case 778:
#line 3743 "fgl.yacc"
    {
	sprintf(yyval.str,"%s||%s",yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 779:
#line 3748 "fgl.yacc"
    {start_state("keymode",1);}
    break;

  case 780:
#line 3748 "fgl.yacc"
    {start_state("keymode",0);strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 785:
#line 3755 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 786:
#line 3756 "fgl.yacc"
    {strcpy(yyval.str,"escape");}
    break;

  case 787:
#line 3757 "fgl.yacc"
    {strcpy(yyval.str,"up");}
    break;

  case 788:
#line 3758 "fgl.yacc"
    {strcpy(yyval.str,"down");}
    break;

  case 789:
#line 3759 "fgl.yacc"
    {strcpy(yyval.str,"return");}
    break;

  case 790:
#line 3760 "fgl.yacc"
    {strcpy(yyval.str,"delete");}
    break;

  case 791:
#line 3761 "fgl.yacc"
    {strcpy(yyval.str,"tab");}
    break;

  case 792:
#line 3762 "fgl.yacc"
    {strcpy(yyval.str,"left");}
    break;

  case 793:
#line 3763 "fgl.yacc"
    {strcpy(yyval.str,"right");}
    break;

  case 794:
#line 3764 "fgl.yacc"
    {strcpy(yyval.str,"nextpage");}
    break;

  case 795:
#line 3765 "fgl.yacc"
    {strcpy(yyval.str,"prevpage");}
    break;

  case 796:
#line 3766 "fgl.yacc"
    { rm_quotes(yyvsp[0].str); strcpy(yyval.str,yyvsp[0].str); }
    break;

  case 797:
#line 3770 "fgl.yacc"
    {
char buff[256];
debug("Label : %s\n",get_idents(0));
strcpy(buff,get_idents(0));
convlower(buff);
print_label(buff);
}
    break;

  case 798:
#line 3788 "fgl.yacc"
    {chk4var=1;}
    break;

  case 799:
#line 3788 "fgl.yacc"
    {chk4var=0;
expand_obind();
lex_printcomment("/*let3*/\n");}
    break;

  case 800:
#line 3791 "fgl.yacc"
    {
int to_vars;
	
	debug("/*processing let*/\n");
	expand_obind();
	to_vars=how_many_in_bind('o');
	if (to_vars>=1)
	{

		if (!print_let_manyvars(yyvsp[0].str))
		{
	    		yyerror("Number of variables in let not equal to number of values\n");YYERROR;
		}

	}
	else
	{
	    print_bind_pop1('o');
	}

}
    break;

  case 801:
#line 3814 "fgl.yacc"
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
#line 3832 "fgl.yacc"
    {
		if (!print_linked_cmd('S',yyvsp[0].str)) yyerror("Not a linked variable");
	}
    break;

  case 804:
#line 3838 "fgl.yacc"
    {
		 if (!print_linked_cmd('D',yyvsp[0].str)) yyerror("Not a linked variable");
	}
    break;

  case 805:
#line 3844 "fgl.yacc"
    {
		 if (!print_linked_cmd('U',yyvsp[0].str)) yyerror("Not a linked variable");
}
    break;

  case 806:
#line 3850 "fgl.yacc"
    {
int vtype;
vtype=scan_variable(yyvsp[-1].str);
if (vtype!=11&&vtype!=12) {
yyerror("Only Byte & Text may be located...");
YYERROR;
}
print_locate('M',yyvsp[-1].str,"0");


}
    break;

  case 807:
#line 3861 "fgl.yacc"
    {
int vtype;
vtype=scan_variable(yyvsp[-2].str);
if (vtype!=11&&vtype!=12) {
yyerror("Only Byte & Text may be located...");
YYERROR;
}

print_locate('F',yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 808:
#line 3884 "fgl.yacc"
    {
		if (glob_only==1) {
       			debug("Read globals section so Im done\n");
       			YYACCEPT;
		}
	
		set_4gl_vars();

		set_current_variable_scope('g'); print_variables (); set_current_variable_scope('G'); print_variables (); set_current_variable_scope('m'); print_variables ();
print_module_variable_init();
		set_current_variable_scope('m');
	}
    break;

  case 811:
#line 3900 "fgl.yacc"
    {
	}
    break;

  case 818:
#line 3923 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 822:
#line 3931 "fgl.yacc"
    {
		print_at_termination(yyvsp[0].str);
	}
    break;

  case 840:
#line 3957 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 841:
#line 3958 "fgl.yacc"
    {
strcpy(yyval.str,"static ");
}
    break;

  case 842:
#line 3966 "fgl.yacc"
    {
  clr_variable(); lastlineno=yylineno;
  clr_function_constants (); 
}
    break;

  case 843:
#line 3971 "fgl.yacc"
    { 

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
#line 3984 "fgl.yacc"
    {
  lex_printcomment("/* new function %s parameters*/\n",yyvsp[-1].str);
  push_blockcommand("FUNC");
  lex_printcomment("/* define section */\n");
}
    break;

  case 845:
#line 3990 "fgl.yacc"
    {
  int c;
  lex_printcomment("/*end of define section */\n");
	print_variables();
  c=print_param('f');
  printPushFunction();
  print_func_args(c);
}
    break;

  case 847:
#line 4005 "fgl.yacc"
    {
    printPopFunction();
    print_func_defret0();
    pop_blockcommand("FUNC");
    print_func_end();
    clr_function_constants ();
    lex_printcomment("/*end function*/\n");
  }
    break;

  case 848:
#line 4018 "fgl.yacc"
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
#line 4028 "fgl.yacc"
    {
	print_variables();
    printDeclareFunctionStack("MAIN");
    print_fgllib_start(hdr_dbname);
    printInitFunctionStack();
    printPushFunction();
  }
    break;

  case 850:
#line 4035 "fgl.yacc"
    {
pop_blockcommand("MAIN");
print_main_end();
lex_printcomment("/*end main */\n");}
    break;

  case 851:
#line 4042 "fgl.yacc"
    {
    printPopFunction();
    print_return(atoi(yyvsp[0].str));
  }
    break;

  case 852:
#line 4048 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 853:
#line 4048 "fgl.yacc"
    {
lex_printcomment("/* Got expr list */");
sprintf(yyval.str,"%s",yyvsp[0].str);}
    break;

  case 854:
#line 4053 "fgl.yacc"
    {open_db(yyvsp[0].str);
			strcpy(hdr_dbname,yyvsp[0].str);
			lastlineno=yylineno;}
    break;

  case 855:
#line 4058 "fgl.yacc"
    {
}
    break;

  case 861:
#line 4070 "fgl.yacc"
    {
strcpy(curr_func,"[Globals]");
set_current_variable_scope('g');
lex_printcomment("/* start of globals */\n");
}
    break;

  case 863:
#line 4078 "fgl.yacc"
    {
	lex_printcomment("/* end of globals */");
	debug("end of globals\n");
	lastlineno=yylineno;
	set_current_variable_scope('m');
}
    break;

  case 864:
#line 4084 "fgl.yacc"
    {
char b[256];
	lastlineno=yylineno;
	strcpy(b,yyvsp[0].str);
	set_current_variable_scope('G');
	tr_glob_fname(b);
	debug("Reading globals file %s\n",b);
	rm_quote(b);
	read_glob(b);
	set_current_variable_scope('m');
}
    break;

  case 865:
#line 4098 "fgl.yacc"
    {
  addmap("Define Member Function",curr_func,"MODULE",yylineno,infilename);
}
    break;

  case 866:
#line 4102 "fgl.yacc"
    {
  char buff[80];
  sprintf(buff,"%s_%s_%d",yyvsp[-4].str,yyvsp[-6].str,atoi(yyvsp[-1].str));
  sprintf(curr_func,"%s",buff);
  print_func_start("",buff,1);
  printDeclareFunctionStack(buff);

  cnt=0;
  lex_printcomment("/* new function %s parameters*/\n",yyvsp[-1].str);
  push_blockcommand("FUNC");
  lex_printcomment("/* define section */\n");
}
    break;

  case 867:
#line 4115 "fgl.yacc"
    {
	print_variables();
  lex_printcomment("/*end of define section */\n");
  print_param('f');
  printPushFunction();
  print_func_args(atoi(yyvsp[-3].str));
}
    break;

  case 869:
#line 4133 "fgl.yacc"
    {
	start_state("menu",1);
   	menu_cnt=npush_menu();
   	menu_cmd_cnt[menu_cnt]=1;
   	push_blockcommand("MENU");
	print_menu_1();
	}
    break;

  case 870:
#line 4140 "fgl.yacc"
    {
	start_state("menu",0);
	}
    break;

  case 871:
#line 4146 "fgl.yacc"
    {
   print_end_menu_1();
   add_continue_blockcommand ("MENU");
print_end_menu_2();
   pop_blockcommand("MENU");
   pop_menu();
}
    break;

  case 872:
#line 4157 "fgl.yacc"
    {
	 lex_printcomment("/* Block%d_m2 (Before menu) */",menu_cnt);
		print_menu_block(-2) ;
                  }
    break;

  case 873:
#line 4161 "fgl.yacc"
    {
		print_menu_block_end();
	}
    break;

  case 874:
#line 4168 "fgl.yacc"
    {
debug("Menu=%d menu cnt=%d",menu_cnt,menu_cmd_cnt[menu_cnt]);
		push_command(menu_cnt,menu_cmd_cnt[menu_cnt],yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);
		lex_printcomment("/* Block%d_%d */",menu_cnt,menu_cmd_cnt[menu_cnt]-1);
		print_menu_block(menu_cmd_cnt[menu_cnt]-1);
		menu_cmd_cnt[menu_cnt]++;
		}
    break;

  case 875:
#line 4175 "fgl.yacc"
    {
		print_menu_block_end();
}
    break;

  case 876:
#line 4181 "fgl.yacc"
    {
		push_command(menu_cnt,menu_cmd_cnt[menu_cnt],yyvsp[-1].str,"\"\"","\"\"",0);
		print_menu_block(menu_cmd_cnt[menu_cnt]-1);
		menu_cmd_cnt[menu_cnt]++;
		}
    break;

  case 877:
#line 4186 "fgl.yacc"
    {
		print_menu_block_end();
}
    break;

  case 880:
#line 4193 "fgl.yacc"
    {strcpy(yyval.str,"\"EMPTY\"");}
    break;

  case 881:
#line 4194 "fgl.yacc"
    {sprintf(yyval.str,"\"%s\"",yyvsp[0].str);}
    break;

  case 882:
#line 4196 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str); }
    break;

  case 883:
#line 4197 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 884:
#line 4200 "fgl.yacc"
    {strcpy(yyval.str,"\"\"");}
    break;

  case 885:
#line 4201 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 886:
#line 4202 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 887:
#line 4204 "fgl.yacc"
    {
	print_option_op('N',yyvsp[0].str);
}
    break;

  case 888:
#line 4209 "fgl.yacc"
    {
	print_option_op('S',yyvsp[0].str);
}
    break;

  case 889:
#line 4214 "fgl.yacc"
    {
	print_option_op('H',yyvsp[0].str);
}
    break;

  case 890:
#line 4221 "fgl.yacc"
    {sprintf(yyval.str,"MENU_ALL");}
    break;

  case 894:
#line 4228 "fgl.yacc"
    {sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 895:
#line 4230 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);  
push_menu_title(yyval.str);}
    break;

  case 896:
#line 4232 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str); 
push_menu_title(yyval.str);}
    break;

  case 897:
#line 4241 "fgl.yacc"
    {
                strcpy(menuhandler,yyvsp[0].str);
	sprintf(curr_func,"%s",yyvsp[0].str); 
	print_gtk_menuhandler_1(yyvsp[0].str);
                push_blockcommand("MENUH");
}
    break;

  case 898:
#line 4247 "fgl.yacc"
    {
		print_variables();
        }
    break;

  case 899:
#line 4251 "fgl.yacc"
    {
                        pop_blockcommand("MENUH");
			print_gtk_menuhandler_end();
                }
    break;

  case 902:
#line 4263 "fgl.yacc"
    {

		print_gtk_menuhandler_bsm();

                push_blockcommand("BSM");
        }
    break;

  case 903:
#line 4268 "fgl.yacc"
    {
                pop_blockcommand("BSM");
		print_gtk_menuhandler_bsm_end();

        }
    break;

  case 904:
#line 4273 "fgl.yacc"
    {
print_gtk_menuhandler_on(yyvsp[0].str);
                push_blockcommand("ON");
        }
    break;

  case 905:
#line 4276 "fgl.yacc"
    {
                pop_blockcommand("ON");
		print_gtk_menuhandler_on_end();
}
    break;

  case 906:
#line 4285 "fgl.yacc"
    {start_state("message",0);}
    break;

  case 907:
#line 4288 "fgl.yacc"
    {
		print_message(0,"0",0);
		start_state("message",0);
	   }
    break;

  case 908:
#line 4292 "fgl.yacc"
    { 
		print_message(0,yyvsp[-1].str,atoi(yyvsp[0].str));
		start_state("message",0);
	  }
    break;

  case 909:
#line 4296 "fgl.yacc"
    { 
		print_message(0,"0",atoi(yyvsp[0].str));
		start_state("message",0);
	  }
    break;

  case 916:
#line 4313 "fgl.yacc"
    {start_state("message",1);}
    break;

  case 918:
#line 4315 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 919:
#line 4315 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 920:
#line 4318 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 921:
#line 4328 "fgl.yacc"
    {
char buff[256];
char buff2[256];
int n;
strcpy(buff,yyvsp[0].str);
lex_printcomment("/* .. var %s*/",buff);
if (buff[0]!=' ') addmap("Use Variable",buff,curr_func,yylineno,infilename);

if (strncmp(buff," ASSOCIATE_",11)!=0) {
	convlower(buff);
}

strcpy(yyval.str,buff);
debug("Checking variable '%s'",buff);
n=scan_variable(buff);

  debug("scan variable returns -> %d\n",n);

  if (n == -1&&buff[0]!=' ') {
           sprintf(buff2,"'%s' does not represent a defined variable (1)",buff);
           yyerror(buff2);
           exit (0);
  }
  if (strstr(buff,".*") && n!=-2) {
		char *ptr;
		printf("WARNING : Using a .* on a non-record - %s\n",yyvsp[0].str);
		ptr=strstr(buff,".*");
		*ptr=0;
		strcpy(yyval.str,buff);
  }
 
  mcnt = 0;
}
    break;

  case 923:
#line 4365 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 925:
#line 4372 "fgl.yacc"
    { 
         sprintf (yyval.str, "%s.%s", yyvsp[-1].str, yyvsp[0].str); 
         lex_printcomment("/* record building -> %s */\n",yyval.str);
         }
    break;

  case 926:
#line 4377 "fgl.yacc"
    {

         int type,arrsize,size,level;
         char buff[256];
         char buff2[256];
         char arrbuff[256];

         lex_printcomment("/* OPEN_SQUARE.. */\n");

         sprintf(buff,"%s.%s",yyvsp[-4].str,yyvsp[-3].str);
         if (scan_variable(buff)==-1) {
           sprintf(buff2,"'%s' does not represent a defined variable (2)",buff);
           yyerror(buff2);
           YYERROR;
         }

         lex_printcomment("/*variable with [...]*/");
         get_variable_dets (buff,&type,&arrsize,&size,&level,arrbuff);
         lex_printcomment("/* Arrsize = %d size = %d*/",arrsize,size);
	 
         if (arrsize>0)
         {
             debug("Is array...");
             sprintf (yyval.str, "%s[%s]", buff, change_arr_elem(yyvsp[-1].str));
             lex_printcomment ("/* array variable %s num_arr_elem=%d arrbuff=%d*/\n", yyval.str,num_arr_elem(yyvsp[-1].str),num_arr_elem(arrbuff));
         }
         else
         {
             debug ("Is string...");
             sprintf (yyval.str, " substr(%s , %d , %s , 0 ) /*1*/", buff,
                      (int)scan_variable (buff), yyvsp[-1].str);

             addmap("Use Variable",buff,curr_func,yylineno,infilename);
             lex_printcomment ("/*character variable %s*/\n", yyval.str);
         }

         mcnt++;
}
    break;

  case 930:
#line 4421 "fgl.yacc"
    {
char buff2[256];
         if (scan_variable(yyvsp[-3].str)==-1) {
           sprintf(buff2,"'%s' does not represent a defined variable (3)",yyvsp[-3].str);
           yyerror(buff2); 
           YYERROR;
         }

lex_printcomment("/*Associative Variable : %s*/\n",yyvsp[-1].str);
sprintf(yyval.str," ASSOCIATE_%s(%s,1)",upshift(yyvsp[-3].str),yyvsp[-1].str);
}
    break;

  case 931:
#line 4435 "fgl.yacc"
    {
char buff2[256];
         if (scan_variable(yyvsp[-3].str)==-1) {
           sprintf(buff2,"'%s' does not represent a defined variable (4)",yyvsp[-3].str);
           yyerror(buff2); 
           YYERROR;
         }
lex_printcomment("/*Associative Variable : %s*/\n",yyvsp[-1].str);
sprintf(yyval.str," ASSOCIATE_%s(%s,0)",upshift(yyvsp[-3].str),yyvsp[-1].str);
}
    break;

  case 936:
#line 4459 "fgl.yacc"
    {
  int type,arrsize,size,level;
  char buff2[256];
  char arrbuff[256];
  lex_printcomment("/*array variable nnn */");
  get_variable_dets (yyvsp[-1].str,&type,&arrsize,&size,&level,arrbuff);
  lex_printcomment("/*here %s %x */",yyvsp[-1].str,type);
  if (scan_variable(yyvsp[-1].str)==-1) {
           sprintf(buff2,"'%s' does not represent a defined variable (7)",yyvsp[-1].str);
           yyerror(buff2); 
           YYERROR;

	}


  debug("Type=%d (%d) arrsize=%d",type,type&0xffff,arrsize);

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
        sprintf (yyval.str, " substr(%s,%d,%s,0) /*2*/", tmpbuff, (int)scan_variable (tmpbuff), rbuff);
  } else {
 
  if ((type & (0xffff != 0)) || (arrsize>0))
    {
      lex_printcomment("/* changing optbase for array: %s */\n",yyvsp[0].str);
      sprintf (yyval.str, "%s[%s]", yyvsp[-1].str, change_arr_elem(yyvsp[0].str));
      lex_printcomment ("/* array variable %s*/\n", yyval.str);
    }
  else
    {
      sprintf (yyval.str, " substr(%s,%d,%s,0)/*3*/", yyvsp[-1].str, (int)scan_variable (yyvsp[-1].str), yyvsp[0].str);
             addmap("Use Variable",yyvsp[-1].str,curr_func,yylineno,infilename);
      lex_printcomment ("/*character variable %s*/\n", yyval.str);
      	dec_counter();
      	mcnt--;
    }
}

  mcnt++;
}
    break;

  case 937:
#line 4513 "fgl.yacc"
    {
		debug("---> Subscript or substring");
		strcpy(yyval.str,yyvsp[-1].str);
	}
    break;

  case 938:
#line 4518 "fgl.yacc"
    {
		debug("---> Subscript & substring");
		sprintf(yyval.str,"%s:%s",yyvsp[-4].str,yyvsp[-1].str);
	}
    break;

  case 939:
#line 4526 "fgl.yacc"
    {
debug("List element");
  sprintf (yyval.str, "%s", yyvsp[0].str);
}
    break;

  case 940:
#line 4531 "fgl.yacc"
    {
debug("List element continues");
  sprintf (yyval.str, "%s,%s", yyvsp[-2].str, yyvsp[0].str);
}
    break;

  case 941:
#line 4539 "fgl.yacc"
    {
  sprintf (yyval.str, "%s", yyvsp[0].str);
}
    break;

  case 942:
#line 4545 "fgl.yacc"
    {
char buff[256];
strcpy(buff,yyvsp[0].str);
addmap("Let Variable",buff,curr_func,yylineno,infilename);

if (strncmp(buff," ASSOCIATE_",11)!=0) {
convlower(buff);
}
strcpy(yyval.str,buff);
lex_printcomment("/* %s */\n",yyvsp[0].str);
  if (scan_variable (buff) == -1&&buff[0]!=' ')
    {
      lex_printcomment ("/*NOt a variable*/");
      sprintf(buff,"%s is not a variable",yyvsp[0].str);
      yyerror(buff);
    }

  mcnt = 0;
}
    break;

  case 943:
#line 4565 "fgl.yacc"
    {
		debug("Array..");
}
    break;

  case 944:
#line 4568 "fgl.yacc"
    { sprintf (yyval.str, "%s.%s", yyvsp[-3].str, yyvsp[0].str); }
    break;

  case 945:
#line 4570 "fgl.yacc"
    {
  int a;
  int b;
  char buff[256];
  char buff2[256];
  lex_printcomment("/*array variable .let. */");

  sprintf(yyval.str,"%s.%s",yyvsp[-6].str,yyvsp[-3].str);

         if (scan_variable(yyval.str)==-1) {
           sprintf(buff2,"'%s' does not represent a defined variable (5)",yyval.str);
           yyerror(buff2); 
           YYERROR;
         }

  debug("?1arrvar=%s",yyval.str);
  b = isarrvariable (yyval.str);
  a = scan_variable (yyval.str);

  lex_printcomment("/*a=%x b=%x */\n",a,b);

  if (b != 0)
    {
      sprintf (yyval.str, "%s.%s[%s-1] ", yyvsp[-6].str, yyvsp[-3].str,yyvsp[-1].str);
      lex_printcomment ("/* array variable %s*/\n", yyval.str);
    }
  else
    {
      sprintf(buff,"%s.%s",yyvsp[-6].str,yyvsp[-3].str);
      sprintf (yyval.str, " let_substr(%s,%d,%s,0)", buff, a, yyvsp[-1].str);
      addmap("Let Variable",buff,curr_func,yylineno,infilename);
      lex_printcomment ("/*character variable %s*/\n", yyval.str);
    }

  mcnt++;

}
    break;

  case 950:
#line 4618 "fgl.yacc"
    {
/*OPEN_SQUARE num_list CLOSE_SQUARE*/
  int a;
  int b;
  char buff2[256];
  lex_printcomment("/*.let. array variable */");

  debug("?2 arrvar=%s",yyvsp[-1].str);
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
        sprintf (yyval.str, " let_substr(%s,%d,%s,0)", tmpbuff, (int)scan_variable (tmpbuff), rbuff);
  } else {
  	b = isarrvariable (yyvsp[-1].str);
  	a = scan_variable (yyvsp[-1].str);

         if (a==-1) {
           sprintf(buff2,"'%s' does not represent a defined variable (6)",yyvsp[-1].str);
           yyerror(buff2); 
           YYERROR;
         }


  debug("/*a=%d b=%d*/\n",a,b);

  if (b != 0)
    {
      sprintf (yyval.str, "%s[%s]", yyvsp[-1].str, decode_array_string(yyvsp[0].str));
      debug ("/* array variable %s*/\n", yyval.str);
    }
  else
    {
      sprintf (yyval.str, " let_substr(%s,%d,%s,0)", yyvsp[-1].str, (int)scan_variable (yyvsp[-1].str), yyvsp[0].str);

      addmap("Let Variable",yyvsp[-1].str,curr_func,yylineno,infilename);
      debug ("/*character variable %s*/\n", yyval.str);
    }
 }
  mcnt++;

}
    break;

  case 951:
#line 4670 "fgl.yacc"
    {
start_bind('f',0);
start_bind('O',0);
strcpy(yyval.str,"0");}
    break;

  case 953:
#line 4677 "fgl.yacc"
    {
start_bind('f',yyvsp[0].str);
start_bind('O',yyvsp[0].str);
sprintf(yyval.str,"1");
}
    break;

  case 954:
#line 4683 "fgl.yacc"
    {
int c;
c=add_bind('f',yyvsp[0].str);
c=add_bind('O',yyvsp[0].str);
sprintf(yyval.str,"%d",c); 
}
    break;

  case 955:
#line 4694 "fgl.yacc"
    {
lex_printcomment("/*STarted bind %s*/\n",yyvsp[0].str);
start_bind('i',yyvsp[0].str);
lex_printcomment("/*STarted bind 2*/\n");
strcpy(yyval.str,"");
}
    break;

  case 956:
#line 4701 "fgl.yacc"
    {
lex_printcomment("/* Added */\n");
add_bind('i',yyvsp[0].str);
strcpy(yyval.str,"");
}
    break;

  case 958:
#line 4709 "fgl.yacc"
    {sprintf(yyval.str,"%s.%s",yyvsp[-2].str,yyvsp[-1].str);}
    break;

  case 959:
#line 4712 "fgl.yacc"
    {lex_printcomment("/* Variable */\n");}
    break;

  case 960:
#line 4713 "fgl.yacc"
    { debug("Got an ibind thru..."); sprintf(yyval.str,"%s\n%s",yyvsp[-2].str,yyvsp[0].str); }
    break;

  case 962:
#line 4715 "fgl.yacc"
    {sprintf(yyval.str,"\"%s\"",yyvsp[0].str);}
    break;

  case 963:
#line 4716 "fgl.yacc"
    {sprintf(yyval.str,"\"%s\"",yyvsp[0].str);}
    break;

  case 964:
#line 4719 "fgl.yacc"
    {
start_bind('o',yyvsp[0].str);
}
    break;

  case 965:
#line 4722 "fgl.yacc"
    {
add_bind('o',yyvsp[0].str);
strcpy(yyval.str,"");
}
    break;

  case 966:
#line 4728 "fgl.yacc"
    {
	addmap("OBIND",yyvsp[0].str,curr_func,yylineno,infilename);
	}
    break;

  case 967:
#line 4731 "fgl.yacc"
    { debug("Got an obind thru..."); sprintf(yyval.str,"%s\n%s",yyvsp[-2].str,yyvsp[0].str); }
    break;

  case 968:
#line 4735 "fgl.yacc"
    {
lex_printcomment("/* start obind with  %s*/\n",yyvsp[0].str);
start_bind('o',yyvsp[0].str);
}
    break;

  case 969:
#line 4739 "fgl.yacc"
    {
lex_printcomment("/* add to obind %s */\n",yyvsp[0].str);
add_bind('o',yyvsp[0].str);
strcpy(yyval.str,"");
}
    break;

  case 970:
#line 4746 "fgl.yacc"
    {
lex_printcomment("/* Read variable %s*/\n",yyvsp[0].str);
}
    break;

  case 971:
#line 4751 "fgl.yacc"
    {
    lex_printcomment("/* use_arr_var */\n");
    start_arr_bind('o',yyvsp[0].str);
    lex_printcomment("/* use_arr_var complete */\n");
}
    break;

  case 972:
#line 4758 "fgl.yacc"
    {
start_bind('O',yyvsp[0].str);
}
    break;

  case 973:
#line 4761 "fgl.yacc"
    {
               add_bind('O',yyvsp[0].str);
               strcpy(yyval.str,"");
}
    break;

  case 978:
#line 4774 "fgl.yacc"
    {
  int type,arrsize,size,level;
  char arrbuff[256];
  lex_printcomment("/*..array_r_varid..*/");

if (get_variable_dets (yyvsp[-3].str,&type,&arrsize,&size,&level,arrbuff)>=0) {
  sprintf(yyval.str,"%s[%s]",yyvsp[-3].str,subtract_one(yyvsp[-1].str));
} else {
  sprintf(yyval.str,"%s[%s]",yyvsp[-3].str,yyvsp[-1].str);
}
}
    break;

  case 979:
#line 4787 "fgl.yacc"
    {
lex_printcomment("/*STarted bind %s*/\n",yyvsp[0].str);
start_bind('N',yyvsp[0].str);
lex_printcomment("/*STarted bind 2*/\n");
strcpy(yyval.str,"");
}
    break;

  case 980:
#line 4794 "fgl.yacc"
    {
lex_printcomment("/* Added */\n");
add_bind('N',yyvsp[0].str);
strcpy(yyval.str,"");
}
    break;

  case 981:
#line 4801 "fgl.yacc"
    {
		strcpy(yyval.str,yyvsp[0].str);
	}
    break;

  case 982:
#line 4804 "fgl.yacc"
    {
			sprintf(yyval.str,"%s\n%s",yyvsp[-2].str,yyvsp[0].str);
		}
    break;

  case 983:
#line 4818 "fgl.yacc"
    {
form_attrib.iswindow=1;
print_open_window(yyvsp[-5].str,yyvsp[-1].str);
sprintf(yyval.str,"open window");
}
    break;

  case 988:
#line 4835 "fgl.yacc"
    {
	print_niy("OPEN_STATUSBOX");
}
    break;

  case 989:
#line 4840 "fgl.yacc"
    {
addmap("Call Formhandler",yyvsp[0].str,curr_func,yylineno,infilename); 
}
    break;

  case 990:
#line 4846 "fgl.yacc"
    {
		print_open_form(yyvsp[0].str,yyvsp[-1].str,yyvsp[-1].str);
		}
    break;

  case 992:
#line 4853 "fgl.yacc"
    { form_attrib.iswindow=0;strcpy(yyval.str,"open_form(%s);"); }
    break;

  case 993:
#line 4858 "fgl.yacc"
    {sprintf(yyval.str,"open_gui_form(%%s,%s,%s,%s,hnd_e_%s,hnd_c_%s);",yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[0].str,yyvsp[0].str);}
    break;

  case 994:
#line 4861 "fgl.yacc"
    {strcpy(yyval.str,"0,0");}
    break;

  case 995:
#line 4862 "fgl.yacc"
    {sprintf(yyval.str,"%s,2",yyvsp[-5].str);}
    break;

  case 996:
#line 4865 "fgl.yacc"
    {strcpy(yyval.str,"\"\"");}
    break;

  case 997:
#line 4866 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 998:
#line 4869 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 999:
#line 4870 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 1000:
#line 4875 "fgl.yacc"
    {
print_open_session(yyvsp[-3].str,yyvsp[-1].str,yyvsp[0].str);

}
    break;

  case 1001:
#line 4882 "fgl.yacc"
    {
	print_open_cursor(yyvsp[0].str,"0");
}
    break;

  case 1002:
#line 4885 "fgl.yacc"
    {
	print_open_cursor(yyvsp[-3].str,yyvsp[0].str); /* CHANGED from $<str>4 */
}
    break;

  case 1003:
#line 4891 "fgl.yacc"
    {sprintf(yyval.str,"0,0");}
    break;

  case 1004:
#line 4893 "fgl.yacc"
    {sprintf(yyval.str,"%s, %s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1005:
#line 4895 "fgl.yacc"
    {sprintf(yyval.str,"%s, %s",yyvsp[-3].str,yyvsp[0].str);}
    break;

  case 1006:
#line 4897 "fgl.yacc"
    {sprintf(yyval.str,"%s, %s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1007:
#line 4900 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 1008:
#line 4900 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 1009:
#line 4901 "fgl.yacc"
    {strcpy(yyval.str,"2");}
    break;

  case 1010:
#line 4906 "fgl.yacc"
    {
	print_open_session(yyvsp[-1].str,yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 1011:
#line 4914 "fgl.yacc"
    {strcpy(yyval.str,"\"default_conn\"");}
    break;

  case 1012:
#line 4915 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1013:
#line 4920 "fgl.yacc"
    {sprintf(yyval.str,"0,0");}
    break;

  case 1014:
#line 4922 "fgl.yacc"
    {sprintf(yyval.str,"%s, %s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1015:
#line 4924 "fgl.yacc"
    {sprintf(yyval.str,"%s, %s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1019:
#line 4941 "fgl.yacc"
    {
print_options('C',yyvsp[0].str);
}
    break;

  case 1020:
#line 4944 "fgl.yacc"
    {
print_options('E',yyvsp[0].str);
}
    break;

  case 1021:
#line 4947 "fgl.yacc"
    {
print_options('F',yyvsp[0].str);
}
    break;

  case 1022:
#line 4950 "fgl.yacc"
    {
lex_printc("set_option_value('M',%s);\n",yyvsp[0].str);
}
    break;

  case 1023:
#line 4953 "fgl.yacc"
    {
print_options('m',yyvsp[0].str);
}
    break;

  case 1024:
#line 4956 "fgl.yacc"
    {
print_options('P',yyvsp[0].str);
}
    break;

  case 1025:
#line 4959 "fgl.yacc"
    {
print_options('A',yyvsp[0].str);
iskey=0;
}
    break;

  case 1026:
#line 4963 "fgl.yacc"
    {
print_options('D',yyvsp[0].str);
iskey=0;
}
    break;

  case 1027:
#line 4967 "fgl.yacc"
    {
print_options('I',yyvsp[0].str);
iskey=0;
}
    break;

  case 1028:
#line 4971 "fgl.yacc"
    {
print_options('N',yyvsp[0].str);
}
    break;

  case 1029:
#line 4974 "fgl.yacc"
    {
print_options('p',yyvsp[0].str);
iskey=0;
}
    break;

  case 1030:
#line 4978 "fgl.yacc"
    {
print_options('H',yyvsp[0].str);
}
    break;

  case 1031:
#line 4981 "fgl.yacc"
    { print_set_helpfile(yyvsp[0].str); }
    break;

  case 1032:
#line 4982 "fgl.yacc"
    { print_set_langfile(yyvsp[0].str); }
    break;

  case 1033:
#line 4983 "fgl.yacc"
    {
print_options('d',yyvsp[0].str);
}
    break;

  case 1034:
#line 4986 "fgl.yacc"
    {
print_options('i',yyvsp[0].str);
}
    break;

  case 1035:
#line 4989 "fgl.yacc"
    {
print_options('W',"1");
}
    break;

  case 1036:
#line 4992 "fgl.yacc"
    {
print_options('W',"0");
}
    break;

  case 1037:
#line 4995 "fgl.yacc"
    {
print_options('f',"1");
}
    break;

  case 1038:
#line 4998 "fgl.yacc"
    {
print_options('f',"0");
}
    break;

  case 1039:
#line 5001 "fgl.yacc"
    {
print_options('S',"1");
}
    break;

  case 1040:
#line 5004 "fgl.yacc"
    {
print_options('S',"0");
}
    break;

  case 1041:
#line 5021 "fgl.yacc"
    {
	print_prepare(yyvsp[-2].str,yyvsp[0].str);
	addmap("Prepare",yyvsp[-2].str,curr_func,yylineno,infilename);
	print_undo_use(yyvsp[-4].str);
}
    break;

  case 1044:
#line 5031 "fgl.yacc"
    {

print_execute(yyvsp[0].str,0);

addmap("Execute",yyvsp[0].str,curr_func,yylineno,infilename);
}
    break;

  case 1045:
#line 5038 "fgl.yacc"
    {
	addmap("Execute",yyvsp[-2].str,curr_func,yylineno,infilename);
	print_execute(yyvsp[-2].str,1);
}
    break;

  case 1047:
#line 5059 "fgl.yacc"
    {
                push_blockcommand("PROMPT");

	print_prompt_1(yyvsp[-5].str,yyvsp[-3].str,yyvsp[-1].str,yyvsp[0].str) ;
}
    break;

  case 1048:
#line 5064 "fgl.yacc"
    {
		if (strcmp(yyvsp[-5].str,"1")==0) {
			print_prompt_forchar();
                }
		add_continue_blockcommand ("PROMPT");
		print_prompt_end(yyvsp[-4].str);
                pop_blockcommand("PROMPT");
                lex_printcomment("/* END OF PROMPT */");
                }
    break;

  case 1049:
#line 5077 "fgl.yacc"
    {
		print_niy("GUI PROMPT");
	}
    break;

  case 1050:
#line 5082 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 1051:
#line 5083 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 1052:
#line 5087 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1056:
#line 5093 "fgl.yacc"
    {
	print_onkey_1(yyvsp[0].str);
}
    break;

  case 1057:
#line 5095 "fgl.yacc"
    {
	print_onkey_2_prompt();
}
    break;

  case 1059:
#line 5110 "fgl.yacc"
    {
		start_bind('i',0);
		}
    break;

  case 1060:
#line 5114 "fgl.yacc"
    {
		print_put();
	}
    break;

  case 1061:
#line 5120 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1062:
#line 5121 "fgl.yacc"
    { strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1063:
#line 5124 "fgl.yacc"
    {push_gen(PUTVAL,yyvsp[0].str);}
    break;

  case 1064:
#line 5125 "fgl.yacc"
    {push_gen(PUTVAL,yyvsp[0].str); sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1067:
#line 5141 "fgl.yacc"
    {
addmap("Start Report",yyvsp[-1].str,curr_func,yylineno,infilename);
print_start_report("P","\"lp\"",yyvsp[-1].str);
}
    break;

  case 1068:
#line 5146 "fgl.yacc"
    {
addmap("Start Report",yyvsp[-2].str,curr_func,yylineno,infilename);
print_start_report("F",yyvsp[0].str,yyvsp[-2].str);
}
    break;

  case 1069:
#line 5151 "fgl.yacc"
    {
addmap("Start Report",yyvsp[-2].str,curr_func,yylineno,infilename);
print_start_report("P",yyvsp[0].str,yyvsp[-2].str);
}
    break;

  case 1070:
#line 5156 "fgl.yacc"
    {
addmap("Start Report",yyvsp[0].str,curr_func,yylineno,infilename);
print_start_report("","\"\"",yyvsp[0].str);
}
    break;

  case 1076:
#line 5178 "fgl.yacc"
    {
addmap("Output to report",yyvsp[-5].str,curr_func,yylineno,infilename);
print_output_to_report(yyvsp[-5].str,yyvsp[-1].str); 
}
    break;

  case 1077:
#line 5185 "fgl.yacc"
    {
addmap("Finish Report",yyvsp[0].str,curr_func,yylineno,infilename);
print_finish_report(yyvsp[0].str);
}
    break;

  case 1078:
#line 5191 "fgl.yacc"
    { strcpy(yyval.str,yyvsp[0].str); }
    break;

  case 1079:
#line 5193 "fgl.yacc"
    {
	print_format_every_row();
}
    break;

  case 1083:
#line 5204 "fgl.yacc"
    { push_report_block("FIRST",'P');}
    break;

  case 1084:
#line 5205 "fgl.yacc"
    {print_rep_ret(0);}
    break;

  case 1085:
#line 5207 "fgl.yacc"
    { push_report_block("TRAILER",'T');}
    break;

  case 1086:
#line 5208 "fgl.yacc"
    {print_rep_ret(0);}
    break;

  case 1087:
#line 5210 "fgl.yacc"
    { push_report_block("HEADER",'p');}
    break;

  case 1088:
#line 5211 "fgl.yacc"
    {print_rep_ret(0);}
    break;

  case 1089:
#line 5213 "fgl.yacc"
    { push_report_block("EVERY",'E');}
    break;

  case 1090:
#line 5214 "fgl.yacc"
    {print_rep_ret(0);}
    break;

  case 1091:
#line 5216 "fgl.yacc"
    { push_report_block("LAST",'L');}
    break;

  case 1092:
#line 5217 "fgl.yacc"
    {print_rep_ret(0);}
    break;

  case 1093:
#line 5218 "fgl.yacc"
    {
int a;
char buff[80];
debug("rordcnt=%d",rordcnt);
a=scan_orderby(yyvsp[0].str,rordcnt);
if (a<0) {
   sprintf(buff,"%s is not in the order by list",yyvsp[0].str);
   yyerror(buff);
	YYERROR;
}
sprintf(buff,"%d",a+1);
push_report_block(buff,'B');
set_curr_block(a+1);
}
    break;

  case 1094:
#line 5232 "fgl.yacc"
    {print_rep_ret(0);}
    break;

  case 1095:
#line 5234 "fgl.yacc"
    { 
int a;
char buff[80];

debug("rordcnt=%d",rordcnt);
a=scan_orderby(yyvsp[0].str,rordcnt);
if (a<0) {
   sprintf(buff,"%s is not in the order by list",yyvsp[0].str);
   yyerror(buff);
	YYERROR;
}

sprintf(buff,"%d",a+1);
push_report_block(buff,'A');
set_curr_block(a+1);

}
    break;

  case 1096:
#line 5251 "fgl.yacc"
    {print_rep_ret(0);}
    break;

  case 1103:
#line 5263 "fgl.yacc"
    {start_state("skip",1);}
    break;

  case 1104:
#line 5263 "fgl.yacc"
    {
	print_need_lines();
	start_state("skip",0);
}
    break;

  case 1105:
#line 5269 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 1106:
#line 5269 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 1107:
#line 5272 "fgl.yacc"
    {start_state("KWLINE",1);}
    break;

  case 1108:
#line 5272 "fgl.yacc"
    {
char buff[256];
strcpy(buff,yyvsp[0].str);
if (buff[0]=='1') {
	print_skip_lines();
} else {
	if (rep_type!=REP_TYPE_PDF) { yyerror("SKIP BY is only in PDF reports"); YYERROR; } print_skip_by(yyvsp[-2].str);
}
start_state("KWLINE",0); 
}
    break;

  case 1109:
#line 5282 "fgl.yacc"
    { print_skip_top(); }
    break;

  case 1110:
#line 5283 "fgl.yacc"
    { print_niy("FONT SIZE"); }
    break;

  case 1111:
#line 5284 "fgl.yacc"
    {
			if (rep_type!=REP_TYPE_PDF) {
				yyerror("SKIP BY is only in PDF reports");
				YYERROR;
			}
			print_skip_by(yyvsp[0].str);
		}
    break;

  case 1112:
#line 5291 "fgl.yacc"
    {
			if (rep_type!=REP_TYPE_PDF) {
				yyerror("SKIP TO is only in PDF reports");
				YYERROR;
			}
			print_skip_to(yyvsp[0].str);
		}
    break;

  case 1113:
#line 5303 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1119:
#line 5314 "fgl.yacc"
    {
	print_niy("PRINT AT...");
}
    break;

  case 1120:
#line 5319 "fgl.yacc"
    {
	print_report_print(0,yyvsp[0].str,0);
}
    break;

  case 1121:
#line 5323 "fgl.yacc"
    { 
	print_report_print_file(yyvsp[-1].str,yyvsp[0].str);
}
    break;

  case 1122:
#line 5328 "fgl.yacc"
    { 
	print_report_print_img(yyvsp[-1].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 1123:
#line 5334 "fgl.yacc"
    { strcpy(yyval.str,get_default_scaling());}
    break;

  case 1124:
#line 5335 "fgl.yacc"
    { strcpy(yyval.str,yyvsp[0].str); strcat(yyval.str,yyvsp[0].str); }
    break;

  case 1125:
#line 5336 "fgl.yacc"
    {sprintf(yyval.str,"%s %s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1126:
#line 5340 "fgl.yacc"
    {strcpy(yyval.str,"tiff");}
    break;

  case 1127:
#line 5341 "fgl.yacc"
    {strcpy(yyval.str,"gif");}
    break;

  case 1128:
#line 5342 "fgl.yacc"
    {strcpy(yyval.str,"png");}
    break;

  case 1129:
#line 5343 "fgl.yacc"
    {strcpy(yyval.str,"jpeg");}
    break;

  case 1130:
#line 5347 "fgl.yacc"
    {
	int vtype;
	vtype=scan_variable(yyvsp[0].str);
	if (vtype!=11&&vtype!=12) {
	yyerror("Only Blobs may be printed...");
	YYERROR;
	}
}
    break;

  case 1131:
#line 5357 "fgl.yacc"
    {
strcpy(yyval.str,"0");
}
    break;

  case 1132:
#line 5359 "fgl.yacc"
    {
strcpy(yyval.str,"1");
}
    break;

  case 1133:
#line 5364 "fgl.yacc"
    {
	print_report_print(1,0,yyvsp[0].str);
	}
    break;

  case 1134:
#line 5367 "fgl.yacc"
    {
	print_report_print(1,0,yyvsp[0].str); /* changed from $<str>1 */
}
    break;

  case 1135:
#line 5372 "fgl.yacc"
    {
	strcpy(yyval.str,yyvsp[0].str); 
	}
    break;

  case 1136:
#line 5379 "fgl.yacc"
    {
int a;
a=add_report_agg('S',yyvsp[-2].ptr,yyvsp[0].ptr,racnt);
sprintf(yyval.str,"push_double(_g%d);\n",racnt);
racnt+=a;
}
    break;

  case 1137:
#line 5386 "fgl.yacc"
    {
int a;
a=add_report_agg('C',0,yyvsp[0].ptr,racnt);
sprintf(yyval.str,"push_int(_g%d);\n",racnt);
racnt+=a;
}
    break;

  case 1138:
#line 5393 "fgl.yacc"
    {
int a;
a=add_report_agg('C',0,yyvsp[0].ptr,racnt);
sprintf(yyval.str,"push_int(_g%d);\n",racnt);
racnt+=a;
}
    break;

  case 1139:
#line 5402 "fgl.yacc"
    {
int a;
a=add_report_agg('P',yyvsp[-2].ptr,yyvsp[0].ptr,racnt);
sprintf(yyval.str,"push_double((double)_g%d/(double)_g%d);\n",racnt,racnt+1);
racnt+=a;
}
    break;

  case 1140:
#line 5409 "fgl.yacc"
    {
int a;
a=add_report_agg('A',yyvsp[-2].ptr,yyvsp[0].ptr,racnt);
sprintf(yyval.str,"push_double(_g%d/(double)_g%d);\n",racnt,racnt+1);
racnt+=a;
}
    break;

  case 1141:
#line 5416 "fgl.yacc"
    {
int a;
a=add_report_agg('A',yyvsp[-2].ptr,yyvsp[0].ptr,racnt);
sprintf(yyval.str,"push_double(_g%d/_g%d);\n",racnt,racnt+1);
racnt+=a;
}
    break;

  case 1142:
#line 5423 "fgl.yacc"
    {
int a;
a=add_report_agg('N',yyvsp[-2].ptr,yyvsp[0].ptr,racnt);
sprintf(yyval.str,"push_double(_g%d);\n",racnt);
racnt+=a;
}
    break;

  case 1143:
#line 5430 "fgl.yacc"
    {
int a;
a=add_report_agg('X',yyvsp[-2].ptr,yyvsp[0].ptr,racnt);
sprintf(yyval.str,"push_double(_g%d);\n",racnt);
racnt+=a;
}
    break;

  case 1148:
#line 5443 "fgl.yacc"
    {rep_struct.left_margin=atoi(yyvsp[0].str);}
    break;

  case 1149:
#line 5444 "fgl.yacc"
    {rep_struct.right_margin=atoi(yyvsp[0].str);}
    break;

  case 1150:
#line 5445 "fgl.yacc"
    {rep_struct.top_margin=atoi(yyvsp[0].str);}
    break;

  case 1151:
#line 5446 "fgl.yacc"
    {rep_struct.bottom_margin=atoi(yyvsp[0].str);}
    break;

  case 1152:
#line 5447 "fgl.yacc"
    {rep_struct.page_length=atoi(yyvsp[0].str);}
    break;

  case 1153:
#line 5448 "fgl.yacc"
    { rep_struct.output_mode='P';strcpy(rep_struct.output_loc,"\"lp\"");}
    break;

  case 1154:
#line 5449 "fgl.yacc"
    {rep_struct.output_mode='F';strcpy(rep_struct.output_loc,yyvsp[0].str);}
    break;

  case 1155:
#line 5450 "fgl.yacc"
    {rep_struct.output_mode='F';strcpy(rep_struct.output_loc,yyvsp[0].str);}
    break;

  case 1156:
#line 5451 "fgl.yacc"
    {rep_struct.output_mode='P';strcpy(rep_struct.output_loc,yyvsp[0].str);}
    break;

  case 1157:
#line 5452 "fgl.yacc"
    {strcpy(rep_struct.top_of_page,yyvsp[0].str);}
    break;

  case 1160:
#line 5458 "fgl.yacc"
    {sprintf(yyval.str,"-%f",atof(yyvsp[-1].str));}
    break;

  case 1161:
#line 5459 "fgl.yacc"
    {sprintf(yyval.str,"-%f",atof(yyvsp[-1].str)*72.0); }
    break;

  case 1162:
#line 5460 "fgl.yacc"
    {sprintf(yyval.str,"-%f",atof(yyvsp[-1].str)*2.83465);}
    break;

  case 1163:
#line 5461 "fgl.yacc"
    {sprintf(yyval.str,"%f",atof(yyvsp[0].str));}
    break;

  case 1168:
#line 5470 "fgl.yacc"
    {pdf_rep_struct.left_margin=atof(yyvsp[0].str);debug("Left margin=%s\n",yyvsp[0].str);}
    break;

  case 1169:
#line 5471 "fgl.yacc"
    {pdf_rep_struct.right_margin=atof(yyvsp[0].str);}
    break;

  case 1170:
#line 5472 "fgl.yacc"
    {pdf_rep_struct.top_margin=atof(yyvsp[0].str);}
    break;

  case 1171:
#line 5473 "fgl.yacc"
    {pdf_rep_struct.bottom_margin=atof(yyvsp[0].str);}
    break;

  case 1172:
#line 5474 "fgl.yacc"
    {pdf_rep_struct.page_length=atof(yyvsp[0].str);}
    break;

  case 1173:
#line 5475 "fgl.yacc"
    {pdf_rep_struct.page_width=atof(yyvsp[0].str);}
    break;

  case 1174:
#line 5476 "fgl.yacc"
    {strcpy(pdf_rep_struct.font_name,yyvsp[0].str);}
    break;

  case 1175:
#line 5477 "fgl.yacc"
    {pdf_rep_struct.font_size=atof(yyvsp[0].str);}
    break;

  case 1176:
#line 5479 "fgl.yacc"
    {pdf_rep_struct.paper_size=1;}
    break;

  case 1177:
#line 5480 "fgl.yacc"
    {pdf_rep_struct.paper_size=2;}
    break;

  case 1178:
#line 5481 "fgl.yacc"
    {pdf_rep_struct.paper_size=3;}
    break;

  case 1179:
#line 5482 "fgl.yacc"
    {pdf_rep_struct.paper_size=5;}
    break;

  case 1180:
#line 5484 "fgl.yacc"
    {pdf_rep_struct.paper_size=-1;}
    break;

  case 1181:
#line 5485 "fgl.yacc"
    {pdf_rep_struct.paper_size=-2;}
    break;

  case 1182:
#line 5486 "fgl.yacc"
    {pdf_rep_struct.paper_size=-3;}
    break;

  case 1183:
#line 5487 "fgl.yacc"
    {pdf_rep_struct.paper_size=-5;}
    break;

  case 1187:
#line 5492 "fgl.yacc"
    {pdf_rep_struct.output_mode='F';strcpy(pdf_rep_struct.output_loc,yyvsp[0].str);}
    break;

  case 1188:
#line 5493 "fgl.yacc"
    {pdf_rep_struct.output_mode='P';strcpy(pdf_rep_struct.output_loc,yyvsp[0].str);}
    break;

  case 1192:
#line 5500 "fgl.yacc"
    {
int a;
a=print_bind('O');
print_order_by_type(2);
sprintf(yyval.str,"%d",a);
}
    break;

  case 1193:
#line 5507 "fgl.yacc"
    {
int a;
a=print_bind('O');
print_order_by_type(1);
sprintf(yyval.str,"%d",a);
debug("Order by Gives :%d\n",a);
}
    break;

  case 1194:
#line 5514 "fgl.yacc"
    {
int a;
a=print_bind('O');
print_order_by_type(2);
sprintf(yyval.str,"%d",a);
debug("Order by Gives :%d\n",a);
}
    break;

  case 1195:
#line 5525 "fgl.yacc"
    { 
		rep_type=REP_TYPE_NORMAL; 
		clr_function_constants (); 
		clr_variable(); 
		lastlineno=yylineno; 
		init_report_structure(&rep_struct); 
		}
    break;

  case 1196:
#line 5534 "fgl.yacc"
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

  case 1197:
#line 5545 "fgl.yacc"
    {
		lastlineno=yylineno;
		}
    break;

  case 1198:
#line 5549 "fgl.yacc"
    {
		print_variables();
		}
    break;

  case 1199:
#line 5553 "fgl.yacc"
    {
		print_report_2(0,yyvsp[0].str);
		rordcnt=atoi(yyvsp[0].str);
		debug("SET rordcnt=%d %s",rordcnt,yyvsp[0].str);
		}
    break;

  case 1200:
#line 5559 "fgl.yacc"
    {
		print_report_ctrl();
		}
    break;

  case 1201:
#line 5564 "fgl.yacc"
    {
		pop_blockcommand("REPORT");
		print_report_end() ;
		}
    break;

  case 1202:
#line 5572 "fgl.yacc"
    { strcpy(yyval.str,"");
	yyval.ptr=0;
}
    break;

  case 1203:
#line 5575 "fgl.yacc"
    {
	yyval.ptr=yyvsp[0].ptr;
//sprintf($<str>$,"%s", $<str>2);
}
    break;

  case 1204:
#line 5584 "fgl.yacc"
    {
if (!in_command("REPORT")) {
	yyerror("PAUSE can only be used in reportes");
	YYERROR;
        }

print_pause(yyvsp[0].str) ;
}
    break;

  case 1205:
#line 5595 "fgl.yacc"
    {strcpy(yyval.str,"\"\"");}
    break;

  case 1207:
#line 5602 "fgl.yacc"
    {
rep_type=REP_TYPE_PDF;
clr_variable(); lastlineno=yylineno; pdf_init_report_structure(&pdf_rep_struct);
}
    break;

  case 1208:
#line 5607 "fgl.yacc"
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

  case 1209:
#line 5617 "fgl.yacc"
    {
lastlineno=yylineno;
}
    break;

  case 1210:
#line 5620 "fgl.yacc"
    {
	print_variables();
}
    break;

  case 1211:
#line 5624 "fgl.yacc"
    {
print_variables();
resize_paper(&pdf_rep_struct);
	print_report_2(1,yyvsp[0].str);
debug("SET rordcnt=%d (%s)",rordcnt,yyvsp[0].str);
	rordcnt=atoi(yyvsp[0].str);
}
    break;

  case 1212:
#line 5632 "fgl.yacc"
    {
print_report_ctrl();
}
    break;

  case 1213:
#line 5635 "fgl.yacc"
    {
	pop_blockcommand("REPORT");
	print_report_end();
}
    break;

  case 1214:
#line 5641 "fgl.yacc"
    { strcpy(yyval.str,yyvsp[0].str); }
    break;

  case 1215:
#line 5645 "fgl.yacc"
    {new_counter();
   		addmap("CALL",yyvsp[-1].str,curr_func,yylineno,infilename);
   		}
    break;

  case 1216:
#line 5649 "fgl.yacc"
    {
		sprintf(yyval.str,"%d",get_counter_val());drop_counter();
		}
    break;

  case 1217:
#line 5653 "fgl.yacc"
    {
		print_pdf_call(yyvsp[-5].str,yyvsp[-2].ptr,yyvsp[-1].str);
   		}
    break;

  case 1218:
#line 5657 "fgl.yacc"
    {
	print_returning();
   }
    break;

  case 1219:
#line 5663 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 1220:
#line 5664 "fgl.yacc"
    { strcpy(yyval.str,"rep.right_margin"); }
    break;

  case 1221:
#line 5665 "fgl.yacc"
    { sprintf(yyval.str,"%s",yyvsp[0].str); }
    break;

  case 1222:
#line 5666 "fgl.yacc"
    { sprintf(yyval.str,"%s",yyvsp[0].str); }
    break;

  case 1223:
#line 5671 "fgl.yacc"
    {
print_system_run(0,0);
}
    break;

  case 1224:
#line 5673 "fgl.yacc"
    {
print_system_run(1,yyvsp[0].str);
}
    break;

  case 1225:
#line 5676 "fgl.yacc"
    {
print_system_run(2,0);
}
    break;

  case 1226:
#line 5680 "fgl.yacc"
    {
print_system_run(0,0);
}
    break;

  case 1227:
#line 5683 "fgl.yacc"
    {
print_system_run(0,0);
/* FIXME */
}
    break;

  case 1228:
#line 5690 "fgl.yacc"
    {
	print_exec_sql(yyvsp[0].str);
}
    break;

  case 1229:
#line 5695 "fgl.yacc"
    {sprintf(yyval.str, "%s",yyvsp[0].str);}
    break;

  case 1230:
#line 5696 "fgl.yacc"
    {sprintf(yyval.str,  "%s",yyvsp[0].str);}
    break;

  case 1231:
#line 5697 "fgl.yacc"
    {sprintf(yyval.str,"%s",yyvsp[0].str);}
    break;

  case 1232:
#line 5701 "fgl.yacc"
    {
	print_exec_sql(yyvsp[0].str);

}
    break;

  case 1233:
#line 5709 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1234:
#line 5710 "fgl.yacc"
    {insql=1;}
    break;

  case 1235:
#line 5710 "fgl.yacc"
    {insql=0;}
    break;

  case 1236:
#line 5711 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s %s",yyvsp[-6].str,yyvsp[-4].str,yyvsp[-3].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1237:
#line 5712 "fgl.yacc"
    {insql=1;}
    break;

  case 1238:
#line 5712 "fgl.yacc"
    {insql=0;}
    break;

  case 1239:
#line 5713 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s %s %s",yyvsp[-7].str,yyvsp[-5].str,yyvsp[-4].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1240:
#line 5714 "fgl.yacc"
    {
		yyerror("You cannot create a database from within Aubit4gl....");
	}
    break;

  case 1241:
#line 5720 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1242:
#line 5722 "fgl.yacc"
    {sprintf(yyval.str," %s ",yyvsp[0].str);}
    break;

  case 1244:
#line 5729 "fgl.yacc"
    {sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1245:
#line 5733 "fgl.yacc"
    {sprintf(yyval.str,"%s ASC",yyvsp[-1].str);}
    break;

  case 1246:
#line 5734 "fgl.yacc"
    {sprintf(yyval.str,"%s DESC",yyvsp[-1].str);}
    break;

  case 1249:
#line 5741 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1252:
#line 5752 "fgl.yacc"
    {sprintf(yyval.str,"%s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1254:
#line 5758 "fgl.yacc"
    {
	print_exec_sql(yyvsp[0].str);
}
    break;

  case 1255:
#line 5762 "fgl.yacc"
    {
	sprintf(yyval.str,"%s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);
}
    break;

  case 1257:
#line 5769 "fgl.yacc"
    {sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1265:
#line 5785 "fgl.yacc"
    {
		sprintf(yyval.str,"ADD %s",yyvsp[0].str);
	}
    break;

  case 1266:
#line 5788 "fgl.yacc"
    {
		sprintf(yyval.str,"%s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);
	}
    break;

  case 1268:
#line 5796 "fgl.yacc"
    {
		sprintf(yyval.str,"%s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);
	}
    break;

  case 1270:
#line 5803 "fgl.yacc"
    {
		sprintf(yyval.str,"%s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);
	}
    break;

  case 1271:
#line 5810 "fgl.yacc"
    {
		sprintf(yyval.str,"DROP %s",yyvsp[0].str);
	}
    break;

  case 1272:
#line 5813 "fgl.yacc"
    {
		sprintf(yyval.str,"DROP (%s)",yyvsp[-1].str);
	}
    break;

  case 1274:
#line 5821 "fgl.yacc"
    {
		sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);
	}
    break;

  case 1276:
#line 5830 "fgl.yacc"
    {
		sprintf(yyval.str,"MODIFY %s",yyvsp[0].str);
	}
    break;

  case 1277:
#line 5833 "fgl.yacc"
    {
		sprintf(yyval.str,"MODIFY (%s)",yyvsp[-1].str);
	}
    break;

  case 1279:
#line 5840 "fgl.yacc"
    {
		sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);
	}
    break;

  case 1281:
#line 5851 "fgl.yacc"
    {strcpy(yyval.str,"LOCK MODE PAGE");}
    break;

  case 1282:
#line 5852 "fgl.yacc"
    {strcpy(yyval.str,"LOCK MODE ROW");}
    break;

  case 1283:
#line 5856 "fgl.yacc"
    {
		sprintf(yyval.str,"MODIFT NEXT SIZE %d",atoi(yyvsp[0].str));
	}
    break;

  case 1285:
#line 5863 "fgl.yacc"
    {
		sprintf(yyval.str,"ADD CONSTRAINT (%s)",yyvsp[-1].str);
	}
    break;

  case 1287:
#line 5871 "fgl.yacc"
    {
		sprintf(yyval.str,"ADD CONSTRAINT (%s)",yyvsp[-1].str);
	}
    break;

  case 1289:
#line 5877 "fgl.yacc"
    {
		sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);
	}
    break;

  case 1293:
#line 5895 "fgl.yacc"
    {sprintf(yyval.str,"%s %s /*FIXME */",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1299:
#line 5901 "fgl.yacc"
    { 
	print_set_conn(yyvsp[0].str);
}
    break;

  case 1300:
#line 5904 "fgl.yacc"
    {
	print_set_options("conn",yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 1301:
#line 5907 "fgl.yacc"
    {
	print_set_options("stmt",yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 1302:
#line 5913 "fgl.yacc"
    {strcpy(yyval.str,"\"default\"");}
    break;

  case 1304:
#line 5919 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1306:
#line 5930 "fgl.yacc"
    {
		print_sleep();
	}
    break;

  case 1307:
#line 5944 "fgl.yacc"
    {
		strcpy(current_upd_table,yyvsp[0].str);
	}
    break;

  case 1308:
#line 5946 "fgl.yacc"
    {
		strcpy(current_upd_table,"");
	}
    break;

  case 1309:
#line 5950 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s %s",yyvsp[-6].str,yyvsp[-5].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1310:
#line 5953 "fgl.yacc"
    {strcpy(yyval.str,"");
		pop_all_gen(UPDCOL,"!"); pop_all_gen(UPDVAL,"!");
	}
    break;

  case 1311:
#line 5956 "fgl.yacc"
    { 
		pop_all_gen(UPDCOL,"!"); pop_all_gen(UPDVAL,"!");
		rm_quotes(yyvsp[0].str);
		sprintf(yyval.str," %s %s",yyvsp[-1].str,yyvsp[0].str);
	}
    break;

  case 1312:
#line 5961 "fgl.yacc"
    {
		pop_all_gen(UPDCOL,"!"); pop_all_gen(UPDVAL,"!");
		sprintf(yyval.str," %s %s",yyvsp[-1].str,yyvsp[0].str);
	}
    break;

  case 1313:
#line 5969 "fgl.yacc"
    {
		sprintf(yyval.str," %s %s %s %s %s %s %s",yyvsp[-6].str,yyvsp[-5].str,yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);
		if (isyes(acl_getenv("FIXUPDATE"))) { 
			strcpy(yyval.str,fix_update_expr(0)); 
			ansi_violation("Update (..)=(..)",0);
		}  else {
		ansi_violation("Update (..)=(..)",1);
		}
    }
    break;

  case 1315:
#line 5979 "fgl.yacc"
    {sprintf(yyval.str,"%s %s %s %s %s ",yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);
		push_gen(UPDCOL,"*");
		if (isyes(acl_getenv("FIXUPDATE"))) { 
			strcpy(yyval.str,fix_update_expr(1));
			ansi_violation("Update (..)=(..)",0);
		} else {
			ansi_violation("Update (..)=(..)",1);
		}
}
    break;

  case 1316:
#line 5988 "fgl.yacc"
    {
		char *ptr;
		ptr=yyvsp[0].str;
		push_gen(UPDCOL,"*");

		if (ptr[0]==' ' && ptr[1]=='(') {
			sprintf(yyval.str," %s %s %s  ",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);
		} else {
			sprintf(yyval.str," %s %s(%s) ",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);
		}
		if (isyes(acl_getenv("FIXUPDATE"))) { 
			strcpy(yyval.str,fix_update_expr(1));
			ansi_violation("Update (..)=(..)",0);
		} else {
			ansi_violation("Update (..)=(..)",1);
		}
		}
    break;

  case 1318:
#line 6008 "fgl.yacc"
    {
sprintf(yyval.str," %s , %s",yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 1320:
#line 6017 "fgl.yacc"
    {
sprintf(yyval.str," %s = %s",yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 1321:
#line 6022 "fgl.yacc"
    {push_gen(UPDCOL,yyvsp[0].str); strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1322:
#line 6023 "fgl.yacc"
    {push_gen(UPDCOL,yyvsp[0].str); sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1324:
#line 6027 "fgl.yacc"
    { sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1325:
#line 6031 "fgl.yacc"
    {push_gen(UPDVAL,"<SUBQUERY>");}
    break;

  case 1326:
#line 6032 "fgl.yacc"
    {push_gen(UPDVAL,"NULL");}
    break;

  case 1328:
#line 6038 "fgl.yacc"
    {
		print_sql_commit(0);
		}
    break;

  case 1329:
#line 6047 "fgl.yacc"
    { insql=1;start_bind('i',0);}
    break;

  case 1330:
#line 6048 "fgl.yacc"
    {
sprintf(yyval.str," %s %s %s %s",yyvsp[-4].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);
}
    break;

  case 1331:
#line 6053 "fgl.yacc"
    {insql=1;}
    break;

  case 1332:
#line 6053 "fgl.yacc"
    {
insql=0;
sprintf(yyval.str," %s %s %s %s" ,yyvsp[-4].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1334:
#line 6059 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1335:
#line 6061 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1337:
#line 6068 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1339:
#line 6074 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1342:
#line 6084 "fgl.yacc"
    {
      print_fetch_1();
    }
    break;

  case 1343:
#line 6088 "fgl.yacc"
    {
      print_fetch_2();
    }
    break;

  case 1344:
#line 6092 "fgl.yacc"
    {
      print_fetch_3(yyvsp[-2].str,yyvsp[0].str);
    }
    break;

  case 1345:
#line 6101 "fgl.yacc"
    {sprintf(yyval.str,"%s,%s",yyvsp[0].str,yyvsp[-1].str);
addmap("Fetch Cursor",yyvsp[0].str,curr_func,yylineno,infilename);
}
    break;

  case 1346:
#line 6105 "fgl.yacc"
    {sprintf(yyval.str,"%s,%d,1",yyvsp[0].str,FETCH_RELATIVE);

addmap("Fetch Cursor",yyvsp[0].str,curr_func,yylineno,infilename);
}
    break;

  case 1347:
#line 6111 "fgl.yacc"
    {
debug("no into\n");
strcpy(yyval.str,"0,0");
}
    break;

  case 1348:
#line 6115 "fgl.yacc"
    {
	debug("FETCH INTO  ...");
	/* start_bind('i',0,-1); */
    start_bind('o',0);
}
    break;

  case 1349:
#line 6121 "fgl.yacc"
    {
	int no;
	no=print_bind('o');
	sprintf(yyval.str,"%d,obind",no);
}
    break;

  case 1350:
#line 6128 "fgl.yacc"
    {
debug("no into\n");
strcpy(yyval.str,"0,0");
}
    break;

  case 1351:
#line 6132 "fgl.yacc"
    {
	debug("FETCH INTO  ...");
	/* start_bind('i',0,-1); */
    start_bind('o',0);
}
    break;

  case 1352:
#line 6137 "fgl.yacc"
    {
/*
int ni;
ni=print_bind('i');
sprintf($<str>$,"%d,ibind",ni);
*/
}
    break;

  case 1353:
#line 6147 "fgl.yacc"
    {
		sprintf(yyval.str,"%d,1",FETCH_ABSOLUTE);}
    break;

  case 1354:
#line 6150 "fgl.yacc"
    {sprintf(yyval.str,"%d,-1",FETCH_ABSOLUTE);}
    break;

  case 1355:
#line 6152 "fgl.yacc"
    {sprintf(yyval.str,"%d,1",FETCH_RELATIVE);}
    break;

  case 1356:
#line 6154 "fgl.yacc"
    {sprintf(yyval.str,"%d,-1",FETCH_RELATIVE);}
    break;

  case 1357:
#line 6156 "fgl.yacc"
    {sprintf(yyval.str,"%d,-1",FETCH_RELATIVE);}
    break;

  case 1358:
#line 6158 "fgl.yacc"
    {sprintf(yyval.str,"%d,0",FETCH_RELATIVE);}
    break;

  case 1359:
#line 6160 "fgl.yacc"
    {sprintf(yyval.str,"%d,pop_int()",FETCH_RELATIVE);}
    break;

  case 1360:
#line 6162 "fgl.yacc"
    {sprintf(yyval.str,"%d,pop_int()",FETCH_ABSOLUTE);}
    break;

  case 1361:
#line 6168 "fgl.yacc"
    {
 
rm_quotes(yyvsp[0].str);
sprintf(yyval.str," %s %s %s %s ",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str
);}
    break;

  case 1362:
#line 6178 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1363:
#line 6183 "fgl.yacc"
    {sprintf(yyval.str,"%s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1365:
#line 6189 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1369:
#line 6198 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1372:
#line 6203 "fgl.yacc"
    {
print_sql_commit(-1);
}
    break;

  case 1373:
#line 6208 "fgl.yacc"
    {
		print_sql_commit(1);
	}
    break;

  case 1374:
#line 6215 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1375:
#line 6216 "fgl.yacc"
    {
		strcpy(yyval.str,"EXCLUSIVE");
	}
    break;

  case 1376:
#line 6223 "fgl.yacc"
    {
if (strcmp(yyvsp[-1].str,"?")==0) {
	print_init_conn(0);
} else {
	print_init_conn(yyvsp[-1].str);
}
}
    break;

  case 1377:
#line 6235 "fgl.yacc"
    {insql=1;}
    break;

  case 1378:
#line 6235 "fgl.yacc"
    {
print_undo_use(yyvsp[-2].str);
insql=0;strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1379:
#line 6240 "fgl.yacc"
    {lex_printcomment("/*  schema */\n");
	print_exec_sql(yyvsp[0].str);

strcpy(yyval.str,"Schema");
}
    break;

  case 1380:
#line 6245 "fgl.yacc"
    {lex_printcomment("/*  schema  2*/\n");

	print_exec_sql(yyvsp[0].str);

strcpy(yyval.str,"Schema Element");
}
    break;

  case 1382:
#line 6252 "fgl.yacc"
    {
	print_exec_sql(yyvsp[0].str);
 }
    break;

  case 1384:
#line 6256 "fgl.yacc"
    {

lex_printcomment("/*  delete 1 */\n");

print_exec_sql_bound(yyvsp[0].str);
strcpy(yyval.str,"Delete where current...");
}
    break;

  case 1385:
#line 6263 "fgl.yacc"
    {

lex_printcomment("/*  delete 2 */\n");

print_exec_sql_bound(yyvsp[0].str);
strcpy(yyval.str,"Delete where ...");
}
    break;

  case 1386:
#line 6270 "fgl.yacc"
    {
strcpy(yyval.str,"Fetch");
lex_printcomment("/*  fetch */\n");
}
    break;

  case 1387:
#line 6274 "fgl.yacc"
    {

lex_printcomment("/*  insert */\n");

print_exec_sql_bound(yyvsp[0].str);


strcpy(yyval.str,"insert");

}
    break;

  case 1389:
#line 6285 "fgl.yacc"
    {
	print_do_select(yyvsp[0].str);
	strcpy(yyval.str,"select");
}
    break;

  case 1390:
#line 6289 "fgl.yacc"
    {

print_exec_sql_bound(yyvsp[0].str);
strcpy(yyval.str,"update");
}
    break;

  case 1391:
#line 6298 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s %s %s %s",yyvsp[-6].str,yyvsp[-5].str,yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1392:
#line 6301 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1393:
#line 6303 "fgl.yacc"
    {sprintf(yyval.str," %s ",yyvsp[0].str);}
    break;

  case 1394:
#line 6308 "fgl.yacc"
    {sprintf(yyval.str," %s ",yyvsp[0].str);}
    break;

  case 1397:
#line 6315 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1401:
#line 6322 "fgl.yacc"
    {sprintf(yyval.str," %s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1402:
#line 6325 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1403:
#line 6327 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1405:
#line 6333 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1407:
#line 6339 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1410:
#line 6350 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s %s %s",yyvsp[-5].str,yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1411:
#line 6353 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1412:
#line 6355 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1414:
#line 6361 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1415:
#line 6364 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1417:
#line 6371 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1418:
#line 6377 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s %s",yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1419:
#line 6382 "fgl.yacc"
    {sprintf(yyval.str," %s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1422:
#line 6392 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1424:
#line 6398 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1425:
#line 6404 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1426:
#line 6406 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1428:
#line 6412 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1432:
#line 6425 "fgl.yacc"
    {sprintf(yyval.str," %s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1433:
#line 6427 "fgl.yacc"
    {sprintf(yyval.str," %s",yyvsp[0].str);}
    break;

  case 1434:
#line 6438 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1435:
#line 6441 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1437:
#line 6445 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1438:
#line 6447 "fgl.yacc"
    {sprintf(yyval.str," %s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1439:
#line 6452 "fgl.yacc"
    {sprintf(yyval.str," %s ",yyvsp[0].str);}
    break;

  case 1440:
#line 6454 "fgl.yacc"
    {sprintf(yyval.str," %s ",yyvsp[0].str);}
    break;

  case 1442:
#line 6457 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1443:
#line 6463 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1444:
#line 6468 "fgl.yacc"
    {sprintf(yyval.str," %s",yyvsp[0].str);}
    break;

  case 1447:
#line 6478 "fgl.yacc"
    {sprintf(yyval.str," %s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1450:
#line 6493 "fgl.yacc"
    {sprintf(yyval.str," %s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1451:
#line 6499 "fgl.yacc"
    {sprintf(yyval.str," %s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1454:
#line 6509 "fgl.yacc"
    {sprintf(yyval.str,"%s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1455:
#line 6514 "fgl.yacc"
    {sprintf(yyval.str,"%s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1457:
#line 6520 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1458:
#line 6524 "fgl.yacc"
    {sprintf(yyval.str," %s ", yyvsp[0].str);}
    break;

  case 1459:
#line 6525 "fgl.yacc"
    {sprintf(yyval.str," %s %s ",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1460:
#line 6526 "fgl.yacc"
    {sprintf(yyval.str," %s (%s) ",yyvsp[-3].str,yyvsp[-1].str);}
    break;

  case 1462:
#line 6530 "fgl.yacc"
    {sprintf(yyval.str,"%s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1464:
#line 6535 "fgl.yacc"
    { sprintf(yyval.str," %s,%s ",yyvsp[-2].str,yyvsp[0].str);  }
    break;

  case 1465:
#line 6543 "fgl.yacc"
    {
sprintf(yyval.str,"%s %s %s %s",
yyvsp[-3].str,yyvsp[-2].str,
yyvsp[-1].str,yyvsp[0].str);
}
    break;

  case 1466:
#line 6550 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1467:
#line 6551 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1468:
#line 6554 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1469:
#line 6555 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1470:
#line 6558 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1471:
#line 6559 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1473:
#line 6566 "fgl.yacc"
    {sprintf(yyval.str,"%s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1475:
#line 6572 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1477:
#line 6578 "fgl.yacc"
    {sprintf(yyval.str," %s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1479:
#line 6584 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1480:
#line 6589 "fgl.yacc"
    {sprintf(yyval.str," %s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1481:
#line 6590 "fgl.yacc"
    {sprintf(yyval.str," %s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1482:
#line 6596 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1483:
#line 6598 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1484:
#line 6602 "fgl.yacc"
    {strcpy(yyval.str," ALL ");}
    break;

  case 1490:
#line 6621 "fgl.yacc"
    {sprintf(yyval.str," %s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1493:
#line 6635 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s %s",yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1494:
#line 6637 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1495:
#line 6639 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s %s",yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1496:
#line 6641 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1498:
#line 6648 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1501:
#line 6654 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1503:
#line 6661 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1504:
#line 6663 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1505:
#line 6665 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1506:
#line 6667 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1507:
#line 6669 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s %s %s",yyvsp[-5].str,yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1508:
#line 6671 "fgl.yacc"
    {sprintf(yyval.str," %s %s Like %s %s",yyvsp[-4].str,yyvsp[-3].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1510:
#line 6677 "fgl.yacc"
    {strcpy(yyval.str,"!=");}
    break;

  case 1516:
#line 6683 "fgl.yacc"
    {strcpy(yyval.str,"likE");}
    break;

  case 1517:
#line 6684 "fgl.yacc"
    {strcpy(yyval.str,"<=");}
    break;

  case 1518:
#line 6685 "fgl.yacc"
    {strcpy(yyval.str,">=");}
    break;

  case 1523:
#line 6695 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1526:
#line 6698 "fgl.yacc"
    {
		ansi_violation("Use DISTINCT not UNIQUE",0);
		strcpy(yyval.str,"DISTINCT ");
	}
    break;

  case 1531:
#line 6718 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1532:
#line 6723 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s %s",yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1533:
#line 6724 "fgl.yacc"
    {strcpy(yyval.str,"SERIAL");}
    break;

  case 1535:
#line 6727 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s %s",yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1539:
#line 6732 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1541:
#line 6735 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1543:
#line 6738 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s %s %s %s",yyvsp[-6].str,yyvsp[-5].str,yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1547:
#line 6743 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1548:
#line 6745 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s %s %s",yyvsp[-5].str,yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1549:
#line 6748 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1550:
#line 6749 "fgl.yacc"
    {
		sprintf(yyval.str,",%s",yyvsp[0].str);
}
    break;

  case 1551:
#line 6756 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1555:
#line 6761 "fgl.yacc"
    {sprintf(yyval.str," %s",yyvsp[0].str);}
    break;

  case 1559:
#line 6777 "fgl.yacc"
    { sprintf(yyval.str,"\\\"%s\\\"%s%s",strip_quotes(yyvsp[-2].str),yyvsp[-1].str,yyvsp[0].str); addmap("Use Table",yyval.str,curr_func,yylineno,infilename); }
    break;

  case 1560:
#line 6778 "fgl.yacc"
    {
		sprintf(yyval.str," %s",strip_quotes(yyvsp[0].str));
		addmap("Use Table",yyval.str,curr_func,yylineno,infilename);
	}
    break;

  case 1561:
#line 6782 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str); addmap("Use Table",yyvsp[0].str,curr_func,yylineno,infilename); }
    break;

  case 1562:
#line 6783 "fgl.yacc"
    { sprintf(yyval.str," %s%s%s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str); addmap("Use Table",yyval.str,curr_func,yylineno,infilename); }
    break;

  case 1564:
#line 6798 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1565:
#line 6799 "fgl.yacc"
    {sprintf(yyval.str,"[%s]",yyvsp[-1].str);}
    break;

  case 1566:
#line 6800 "fgl.yacc"
    {sprintf(yyval.str,"[%s,%s]",yyvsp[-3].str,yyvsp[-1].str);}
    break;

  case 1567:
#line 6804 "fgl.yacc"
    { 
addmap("Use Column",yyvsp[-1].str,curr_func,yylineno,infilename);
sprintf(yyval.str,"%s%s",yyvsp[-1].str,yyvsp[0].str);
}
    break;

  case 1568:
#line 6809 "fgl.yacc"
    {
sprintf(yyval.str,"%s.%s%s",yyvsp[-4].str,yyvsp[-1].str,yyvsp[0].str);
addmap("Use Column",yyval.str,curr_func,yylineno,infilename);
}
    break;

  case 1569:
#line 6814 "fgl.yacc"
    {
sprintf(yyval.str,"%s.%s",yyvsp[-3].str,yyvsp[0].str);
addmap("Use Column",yyval.str,curr_func,yylineno,infilename);
}
    break;

  case 1571:
#line 6827 "fgl.yacc"
    {
	strcpy(yyval.str,convstrsql(yyvsp[0].str));
	debug("Set $<str>$ to %s\n",yyval.str);
}
    break;

  case 1575:
#line 6835 "fgl.yacc"
    {sprintf(yyval.str," %s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1576:
#line 6837 "fgl.yacc"
    {sprintf(yyval.str," %s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1577:
#line 6839 "fgl.yacc"
    {sprintf(yyval.str," %s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1578:
#line 6841 "fgl.yacc"
    {sprintf(yyval.str," %s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1580:
#line 6846 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1581:
#line 6849 "fgl.yacc"
    {sprintf(yyval.str," %s %s ",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1582:
#line 6852 "fgl.yacc"
    {strcpy(yyval.str," YEAR TO SECOND ");}
    break;

  case 1583:
#line 6854 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1584:
#line 6857 "fgl.yacc"
    {strcpy(yyval.str,"0,19");}
    break;

  case 1585:
#line 6859 "fgl.yacc"
    {sprintf(yyval.str," %s ,%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1586:
#line 6862 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 1587:
#line 6862 "fgl.yacc"
    {strcpy(yyval.str,"5");}
    break;

  case 1588:
#line 6862 "fgl.yacc"
    {strcpy(yyval.str,"8");}
    break;

  case 1589:
#line 6862 "fgl.yacc"
    {strcpy(yyval.str,"11");}
    break;

  case 1590:
#line 6862 "fgl.yacc"
    {strcpy(yyval.str,"14");}
    break;

  case 1591:
#line 6862 "fgl.yacc"
    {strcpy(yyval.str,"17");}
    break;

  case 1592:
#line 6863 "fgl.yacc"
    {
strcpy(yyval.str,"23");
}
    break;

  case 1593:
#line 6866 "fgl.yacc"
    {
strcpy(yyval.str,"23");
}
    break;

  case 1594:
#line 6871 "fgl.yacc"
    {strcpy(yyval.str,"4");}
    break;

  case 1595:
#line 6871 "fgl.yacc"
    {strcpy(yyval.str,"7");}
    break;

  case 1596:
#line 6871 "fgl.yacc"
    {strcpy(yyval.str,"10");}
    break;

  case 1597:
#line 6871 "fgl.yacc"
    {strcpy(yyval.str,"13");}
    break;

  case 1598:
#line 6871 "fgl.yacc"
    {strcpy(yyval.str,"16");}
    break;

  case 1599:
#line 6871 "fgl.yacc"
    {strcpy(yyval.str,"19");}
    break;

  case 1600:
#line 6873 "fgl.yacc"
    {
strcpy(yyval.str,"25");
}
    break;

  case 1601:
#line 6876 "fgl.yacc"
    {
strcpy(yyval.str,"25");
}
    break;

  case 1616:
#line 6885 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1617:
#line 6886 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1618:
#line 6890 "fgl.yacc"
    {
	print_flush_cursor(yyvsp[0].str);
		addmap("Flush Cursor",yyvsp[0].str,curr_func,yylineno,infilename);
print_undo_use(yyvsp[-2].str);
		}
    break;

  case 1619:
#line 6899 "fgl.yacc"
    {insql=0;chk4var=0;}
    break;

  case 1620:
#line 6899 "fgl.yacc"
    {
print_declare(yyvsp[0].str,yyvsp[-2].str,yyvsp[-5].str,0,0);
addmap("Declare Cursor",yyvsp[-5].str,curr_func,yylineno,infilename);
print_undo_use(yyvsp[-7].str);
}
    break;

  case 1621:
#line 6904 "fgl.yacc"
    {insql=0;chk4var=0;}
    break;

  case 1622:
#line 6904 "fgl.yacc"
    {
print_declare(yyvsp[0].str,yyvsp[-2].str,yyvsp[-6].str,2,0); 
addmap("Declare Cursor",yyvsp[-6].str,curr_func,yylineno,infilename);
print_undo_use(yyvsp[-8].str);
}
    break;

  case 1623:
#line 6910 "fgl.yacc"
    {insql=0;chk4var=0;}
    break;

  case 1624:
#line 6911 "fgl.yacc"
    {
print_declare(yyvsp[0].str,yyvsp[-2].str,yyvsp[-4].str,0,1); 
addmap("Declare Cursor",yyvsp[-4].str,curr_func,yylineno,infilename);
print_undo_use(yyvsp[-6].str);
}
    break;

  case 1625:
#line 6916 "fgl.yacc"
    {insql=0;chk4var=0;}
    break;

  case 1626:
#line 6917 "fgl.yacc"
    {
print_declare(yyvsp[0].str,yyvsp[-2].str,yyvsp[-6].str,0,1); 
addmap("Declare Cursor",yyvsp[-6].str,curr_func,yylineno,infilename);
print_undo_use(yyvsp[-8].str);
}
    break;

  case 1627:
#line 6926 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 1628:
#line 6927 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 1629:
#line 6928 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 1633:
#line 6935 "fgl.yacc"
    {sprintf(yyval.str,"%s.%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1634:
#line 6936 "fgl.yacc"
    {sprintf(yyval.str,"\\\"%s\\\".%s.%s",strip_quotes(yyvsp[-4].str),yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1636:
#line 6942 "fgl.yacc"
    { 
		strcpy(yyval.str,print_curr_spec(1,yyvsp[0].str));
	}
    break;

  case 1637:
#line 6948 "fgl.yacc"
    {
		strcpy(yyval.str,print_curr_spec(2,yyvsp[0].str));
}
    break;

  case 1639:
#line 6957 "fgl.yacc"
    {
	sprintf(yyval.str,"%s",yyvsp[-1].str);
	if (atoi(yyvsp[0].str)) {
		printf("Warning SELECT ... FOR UPDATE when not declaring a cursor currently has no locking effect\n");
	}

	}
    break;

  case 1640:
#line 6970 "fgl.yacc"
    {debug("Got select list...\n");}
    break;

  case 1641:
#line 6972 "fgl.yacc"
    { /* start_bind('i',0,-1); */ start_bind('i',0); lex_printcomment("/* startbind */"); }
    break;

  case 1642:
#line 6974 "fgl.yacc"
    {
             char buff[1024];
             sprintf(buff,"%s %s %s %s %s %s", yyvsp[-7].str, yyvsp[-6].str, yyvsp[-5].str, yyvsp[-3].str, yyvsp[-1].str,yyvsp[0].str);
	     debug("call print_select_all with %s\n",buff);
	     strcpy(yyval.str,print_select_all(buff));

}
    break;

  case 1643:
#line 6985 "fgl.yacc"
    {
             char buff[1024];

             sprintf(buff,"%s %s %s %s %s", yyvsp[-4].str, yyvsp[-3].str, yyvsp[-2].str, yyvsp[-1].str, yyvsp[0].str);
             sprintf(yyval.str,"push_char(\"%s\");",buff);
}
    break;

  case 1646:
#line 7001 "fgl.yacc"
    {sprintf(yyval.str,"%s %s %s %s %s %s %s", yyvsp[-6].str, yyvsp[-5].str, yyvsp[-4].str, yyvsp[-3].str, yyvsp[-2].str, yyvsp[-1].str, yyvsp[0].str);}
    break;

  case 1647:
#line 7005 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1648:
#line 7006 "fgl.yacc"
    {
       lex_printcomment("/* UNION */");
       sprintf(yyval.str,"%s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);
       }
    break;

  case 1650:
#line 7011 "fgl.yacc"
    { sprintf(yyval.str,"%s %s %s ",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str); }
    break;

  case 1651:
#line 7012 "fgl.yacc"
    { sprintf(yyval.str,"%s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str); }
    break;

  case 1653:
#line 7019 "fgl.yacc"
    { start_bind('o',0);strcpy(yyval.str,""); }
    break;

  case 1654:
#line 7020 "fgl.yacc"
    { 
		
		strcpy(yyval.str,get_into_part(get_bind_cnt('o'))); 
	}
    break;

  case 1655:
#line 7030 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s",yyvsp[-4].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1656:
#line 7035 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s %s %s %s",yyvsp[-6].str,yyvsp[-5].str,yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1657:
#line 7038 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1658:
#line 7039 "fgl.yacc"
    {strcpy(yyval.str,"ALL");}
    break;

  case 1659:
#line 7040 "fgl.yacc"
    {strcpy(yyval.str,"DISTINCT");}
    break;

  case 1660:
#line 7041 "fgl.yacc"
    {strcpy(yyval.str,"DISTINCT");
		ansi_violation("Use DISTINCT not UNIQUE",0);
		strcpy(yyval.str,"DISTINCT ");

}
    break;

  case 1662:
#line 7050 "fgl.yacc"
    { sprintf(yyval.str," %s,%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1664:
#line 7055 "fgl.yacc"
    {sprintf(yyval.str," %s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1665:
#line 7056 "fgl.yacc"
    {sprintf(yyval.str," %s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1667:
#line 7066 "fgl.yacc"
    {
			if (strlen(current_upd_table)) push_gen(UPDVAL,yyvsp[0].str);
	}
    break;

  case 1669:
#line 7074 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1670:
#line 7076 "fgl.yacc"
    {sprintf(yyval.str," %s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1671:
#line 7078 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1672:
#line 7080 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1673:
#line 7082 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1678:
#line 7087 "fgl.yacc"
    {sprintf(yyval.str," %s ",yyvsp[0].str);}
    break;

  case 1679:
#line 7089 "fgl.yacc"
    {sprintf(yyval.str," %s",yyvsp[0].str);}
    break;

  case 1680:
#line 7091 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s %s",yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1681:
#line 7093 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s %s",yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1682:
#line 7095 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s %s",yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1683:
#line 7097 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s %s",yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1684:
#line 7099 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s %s",yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1685:
#line 7101 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1686:
#line 7103 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s %s %s",yyvsp[-5].str,yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1687:
#line 7104 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1688:
#line 7105 "fgl.yacc"
    {sprintf(yyval.str,"extend(%s)",yyvsp[-1].str);}
    break;

  case 1693:
#line 7115 "fgl.yacc"
    {

print_unload(yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);
print_undo_use(yyvsp[-4].str);
}
    break;

  case 1694:
#line 7123 "fgl.yacc"
    {
print_load(yyvsp[-4].str,yyvsp[-3].str,yyvsp[-1].str,yyvsp[0].str);
print_undo_use(yyvsp[-6].str);
}
    break;

  case 1695:
#line 7128 "fgl.yacc"
    {strcpy(yyval.str,"\"|\"");}
    break;

  case 1696:
#line 7128 "fgl.yacc"
    {
strcpy(yyval.str,yyvsp[0].str);
}
    break;

  case 1698:
#line 7132 "fgl.yacc"
    {
if ((scan_variable(yyvsp[0].str)&15)!=0) {yyerror("Variable must be of type char for a delimiter..");YYERROR;}
}
    break;

  case 1699:
#line 7137 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 1700:
#line 7137 "fgl.yacc"
    {
sprintf(yyval.str,"%s,0",yyvsp[-1].str);
}
    break;

  case 1702:
#line 7141 "fgl.yacc"
    {
    sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 1703:
#line 7145 "fgl.yacc"
    {
     sprintf(yyval.str,"\"%s\"",yyvsp[0].str);
}
    break;

  case 1706:
#line 7154 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1707:
#line 7154 "fgl.yacc"
    {
print_use_session(yyvsp[0].str);
strcpy(yyval.str,get_undo_use());
}
    break;

  case 1712:
#line 7173 "fgl.yacc"
    { sprintf(yyval.str,"%s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str); }
    break;

  case 1713:
#line 7174 "fgl.yacc"
    { sprintf(yyval.str,"%s %s %s %s",yyvsp[-5].str,yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str); }
    break;

  case 1716:
#line 7182 "fgl.yacc"
    {
		sprintf(yyval.str,"%s %s",yyvsp[-1].str,yyvsp[0].str);
	}
    break;

  case 1717:
#line 7188 "fgl.yacc"
    {
		sprintf(yyval.str,"%s %s %s",
					yyvsp[-2].str,
					yyvsp[-1].str,
					yyvsp[0].str
					);
		}
    break;

  case 1720:
#line 7207 "fgl.yacc"
    {strcpy(yyval.str,"UNITS YEAR");}
    break;

  case 1721:
#line 7208 "fgl.yacc"
    {strcpy(yyval.str,"UNITS MONTH"); }
    break;

  case 1722:
#line 7209 "fgl.yacc"
    {strcpy(yyval.str,"UNITS DAY);"); }
    break;

  case 1723:
#line 7210 "fgl.yacc"
    {strcpy(yyval.str,"UNITS HOUR);"); }
    break;

  case 1724:
#line 7211 "fgl.yacc"
    {strcpy(yyval.str,"UNITS MINUTE);"); }
    break;

  case 1725:
#line 7212 "fgl.yacc"
    {strcpy(yyval.str,"UNITS SECOND);"); }
    break;

  case 1726:
#line 7216 "fgl.yacc"
    {sprintf(yyval.str,"%s %s %s %s %s",yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1727:
#line 7217 "fgl.yacc"
    {sprintf(yyval.str,"%s %s %s %s %s",yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1728:
#line 7218 "fgl.yacc"
    {sprintf(yyval.str,"%s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1729:
#line 7302 "fgl.yacc"
    {
	if (scan_variable(yyvsp[0].str)!=-1)
	{
		print_push_variable(yyvsp[0].str);
		strcpy(yyval.str,"?");
	}
}
    break;

  case 1730:
#line 7313 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1734:
#line 7319 "fgl.yacc"
    {sprintf(yyval.str,"%s.%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1735:
#line 7320 "fgl.yacc"
    {sprintf(yyval.str,"\\\"%s\\\".%s.%s",strip_quotes(yyvsp[-4].str),yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1739:
#line 7330 "fgl.yacc"
    {
	if (scan_variable(yyvsp[0].str)!=-1&&(!system_var(yyvsp[0].str)))
	{
		int z = 0,a = 0;
		a=get_bind_cnt('i');
		z=add_bind('i',yyvsp[0].str);

		z-=a;
		strcpy(yyval.str,set_var_sql(z));
	}
}
    break;

  case 1740:
#line 7342 "fgl.yacc"
    {
char r1[256];
char r2[256];
char buff[256];
char kp[40000];
char *ptr1;
char *ptr2;
/*
int v1;
int v2 = 0;
*/
int aa;
int z = 0,a = 0;
struct variable *v_r;
struct variable *v_1;
struct variable *v_2;
struct variable *v_loop;

 /*
        strcpy(r1,$<str>1);
        ptr1=strrchr(r1,'.');
        if (ptr1==0) {
                yyerror("Must have a . in a thru");YYERROR;
        }
        *ptr1=0;
        ptr1++;

        strcpy(r2,$<str>3);
        debug("r2=%s",r2);

        ptr2=strrchr(r2,'.');

        if (ptr2==0) {
                yyerror("Must have a . in a thru");YYERROR;
        }
        *ptr2=0;

        debug("Checking portions %s %s\n",r1,r2);

        if (strcmp(r1,r2)!=0) {
                yyerror("Records for thru look different...");YYERROR;
        }

        debug("Checking variables");
        v1=scan_variable($<str>1);

        if (v2==-1) {
                debug("Variable not found..");
                yyerror("Variable not found (first entry in thru)");YYERROR;
        }
        v1=last_var_found;
        debug("v1=%d",v1);

        v2=scan_variable($<str>3);
        if (v2==-1) {
                debug("Variable not found..");
                yyerror("Variable not found (second entry in thru)");
        }
        v2=last_var_found;
        debug("v2=%d",v2);

*/
        strcpy(yyval.str,"");


	split_record(yyvsp[0].str,&v_r,&v_1,&v_2);

	v_loop=v_1;

	while (1) {
                strcpy(kp,yyval.str);
                sprintf(buff,"%s.%s",r1,v_loop->names.name);

		if (scan_variable(buff)!=-1&&(!system_var(buff))) {
			a=get_bind_cnt('i');
			z=add_bind('i',buff);
			z-=a;
        	}

		for (a=0;a<z;a++)  {
			if (strlen(yyval.str)) {strcat(yyval.str,",");}
         		strcat(yyval.str,"?");
		}
		v_loop=get_next_variable(v_r,v_loop,v_2);
	}
}
    break;

  case 1741:
#line 7440 "fgl.yacc"
    {set_whenever(WHEN_NOTFOUND|atoi(yyvsp[0].str),0);}
    break;

  case 1742:
#line 7442 "fgl.yacc"
    {set_whenever(WHEN_SQLERROR|atoi(yyvsp[0].str),0);}
    break;

  case 1743:
#line 7444 "fgl.yacc"
    {set_whenever(WHEN_ANYERROR|atoi(yyvsp[0].str),0);}
    break;

  case 1744:
#line 7445 "fgl.yacc"
    {
 		set_whento("");
		set_whenever(WHEN_ERROR+WHEN_CONTINUE,0);
}
    break;

  case 1745:
#line 7450 "fgl.yacc"
    {
debug("Whenever error...%d %d",WHEN_ERROR,atoi(yyvsp[0].str));
set_whenever(WHEN_ERROR+atoi(yyvsp[0].str),0);
}
    break;

  case 1746:
#line 7455 "fgl.yacc"
    {set_whenever(WHEN_SQLWARNING|atoi(yyvsp[0].str),0);}
    break;

  case 1747:
#line 7457 "fgl.yacc"
    {set_whenever(WHEN_WARNING|atoi(yyvsp[0].str),0);}
    break;

  case 1748:
#line 7459 "fgl.yacc"
    {set_whenever(WHEN_SUCCESS|atoi(yyvsp[0].str),0);}
    break;

  case 1749:
#line 7461 "fgl.yacc"
    {set_whenever(WHEN_SQLSUCCESS|atoi(yyvsp[0].str),0);}
    break;

  case 1750:
#line 7464 "fgl.yacc"
    {
 set_whento("");
			sprintf(yyval.str,"%d",WHEN_CONTINUE); }
    break;

  case 1751:
#line 7468 "fgl.yacc"
    {
set_whento(yyvsp[0].str);
sprintf(yyval.str,"%d",WHEN_GOTO);
 }
    break;

  case 1752:
#line 7473 "fgl.yacc"
    {
set_whento(yyvsp[0].str); 
sprintf(yyval.str,"%d",WHEN_GOTO);
}
    break;

  case 1753:
#line 7478 "fgl.yacc"
    { set_whento(""); 
sprintf(yyval.str,"%d",WHEN_STOP);
}
    break;

  case 1754:
#line 7482 "fgl.yacc"
    {
set_whento(yyvsp[0].str);
sprintf(yyval.str,"%d",WHEN_CALL);
}
    break;

  case 1756:
#line 7492 "fgl.yacc"
    {sprintf(yyval.str,"%s",yyvsp[0].str);}
    break;

  case 1758:
#line 7507 "fgl.yacc"
    {
print_while_1();
push_blockcommand("WHILE");
}
    break;

  case 1759:
#line 7510 "fgl.yacc"
    {
print_while_2();
}
    break;

  case 1760:
#line 7514 "fgl.yacc"
    {
print_while_3();
pop_blockcommand("WHILE");
}
    break;

  case 1763:
#line 7533 "fgl.yacc"
    { strcpy(yyval.str,"0"); }
    break;

  case 1764:
#line 7534 "fgl.yacc"
    { strcpy(yyval.str,"1"); }
    break;

  case 1765:
#line 7537 "fgl.yacc"
    { print_clr_window("\"screen\""); }
    break;

  case 1766:
#line 7538 "fgl.yacc"
    { print_clr_window(yyvsp[0].str); }
    break;

  case 1767:
#line 7539 "fgl.yacc"
    { print_clr_window(yyvsp[0].str); }
    break;

  case 1768:
#line 7540 "fgl.yacc"
    { print_clr_form(0,0,"0"); }
    break;

  case 1769:
#line 7541 "fgl.yacc"
    { print_clr_form(0,0,"1"); }
    break;

  case 1770:
#line 7542 "fgl.yacc"
    { print_clr_form(yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str); }
    break;

  case 1771:
#line 7543 "fgl.yacc"
    {
	print_clr_fields(yyvsp[-1].str,yyvsp[0].str);
}
    break;

  case 1772:
#line 7548 "fgl.yacc"
    {sprintf(yyval.str,"%s",yyvsp[0].str);}
    break;

  case 1773:
#line 7549 "fgl.yacc"
    {sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1774:
#line 7553 "fgl.yacc"
    {
	print_current_window("\"screen\"");
}
    break;

  case 1775:
#line 7557 "fgl.yacc"
    {
	print_current_window(yyvsp[0].str);
}
    break;

  case 1776:
#line 7561 "fgl.yacc"
    {
sprintf(yyval.str,"cr_window");
reset_attrib(&form_attrib);
}
    break;

  case 1777:
#line 7565 "fgl.yacc"
    {
sprintf(yyval.str,"cr_window_form");
reset_attrib(&form_attrib);
}
    break;

  case 1778:
#line 7570 "fgl.yacc"
    {
	print_show_window(yyvsp[0].str);
	addmap("Show Window",yyvsp[0].str,curr_func,yylineno,infilename); 
}
    break;

  case 1779:
#line 7574 "fgl.yacc"
    {
	print_show_menu(yyvsp[-3].str,yyvsp[-1].str);
	addmap("Call Menuhandler",yyvsp[-1].str,curr_func,yylineno,infilename); 
}
    break;

  case 1780:
#line 7579 "fgl.yacc"
    {

print_def_mn_file();

}
    break;

  case 1782:
#line 7587 "fgl.yacc"
    {addmap("Use Menu",yyvsp[0].str,curr_func,yylineno,infilename); }
    break;

  case 1784:
#line 7593 "fgl.yacc"
    {
	print_hide_window(yyvsp[0].str);
}
    break;

  case 1785:
#line 7599 "fgl.yacc"
    {
print_move_window(yyvsp[-4].str,0);
}
    break;

  case 1786:
#line 7603 "fgl.yacc"
    {
print_move_window(yyvsp[-4].str,1);
}
    break;

  case 1791:
#line 7621 "fgl.yacc"
    {
chk4var=0;lex_printcomment("/* [Comm:%s] */\n",yyval.str);
if (acl_getenv("INCLINES"))
lex_printc("{debug(\"Line %d %s:%s\");}",lastlineno,infilename,convstrsql(larr));
	prchkerr(lastlineno,infilename);
	lastlineno=yylineno;
}
    break;

  case 1792:
#line 7628 "fgl.yacc"
    {
lex_printcomment("/* [COMM:%s] */\n",yyvsp[0].str);chk4var=0;
if (acl_getenv("INCLINES"))
lex_printc("{debug(\"Line %d %s:%s\");}",lastlineno,infilename,convstrsql(larr));
if (aubit_strcasecmp(yyval.str,"whenever")!=0) prchkerr(lastlineno,infilename);
lastlineno=yylineno;
}
    break;

  case 1793:
#line 7637 "fgl.yacc"
    {print_cmd_start();}
    break;

  case 1794:
#line 7637 "fgl.yacc"
    {print_cmd_end();}
    break;


    }

/* Line 991 of yacc.c.  */
#line 15774 "y.tab.c"

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


#line 7730 "fgl.yacc"

/* programmer routines */
/*
# include "lex.yy.c"
# include "lexify.c"
*/

void
set_clobber(char *c)
{
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



