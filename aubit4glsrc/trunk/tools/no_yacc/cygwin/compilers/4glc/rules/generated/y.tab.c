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
	char *sql_string;

	} YYSTYPE;
/* Line 191 of yacc.c.  */
#line 1499 "y.tab.c"
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 214 of yacc.c.  */
#line 1511 "y.tab.c"

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
#define YYLAST   8215

/* YYNTOKENS -- Number of terminals. */
#define YYNTOKENS  647
/* YYNNTS -- Number of nonterminals. */
#define YYNNTS  817
/* YYNRULES -- Number of rules. */
#define YYNRULES  1878
/* YYNRULES -- Number of states. */
#define YYNSTATES  3080

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
    3518,  3520,  3522,  3524,  3526,  3527,  3528,  3536,  3537,  3538,
    3547,  3551,  3554,  3555,  3557,  3559,  3563,  3566,  3569,  3571,
    3573,  3577,  3579,  3581,  3584,  3586,  3588,  3592,  3594,  3598,
    3600,  3602,  3604,  3606,  3608,  3610,  3612,  3615,  3620,  3622,
    3626,  3628,  3632,  3635,  3640,  3642,  3646,  3648,  3651,  3656,
    3658,  3662,  3664,  3666,  3668,  3671,  3674,  3679,  3682,  3687,
    3689,  3693,  3695,  3697,  3699,  3702,  3704,  3706,  3708,  3710,
    3712,  3715,  3722,  3729,  3730,  3732,  3733,  3735,  3738,  3739,
    3740,  3748,  3749,  3752,  3755,  3763,  3765,  3771,  3775,  3777,
    3781,  3783,  3787,  3789,  3793,  3795,  3799,  3801,  3803,  3805,
    3807,  3808,  3814,  3815,  3821,  3823,  3824,  3828,  3830,  3834,
    3836,  3840,  3842,  3844,  3845,  3846,  3852,  3855,  3857,  3858,
    3859,  3863,  3864,  3865,  3869,  3871,  3873,  3875,  3877,  3879,
    3881,  3884,  3887,  3892,  3896,  3900,  3902,  3906,  3909,  3911,
    3913,  3914,  3916,  3918,  3920,  3922,  3923,  3925,  3929,  3930,
    3934,  3936,  3938,  3940,  3942,  3944,  3946,  3948,  3950,  3952,
    3954,  3956,  3958,  3966,  3967,  3969,  3971,  3973,  3975,  3979,
    3981,  3983,  3985,  3988,  3989,  3993,  3995,  3999,  4001,  4005,
    4007,  4009,  4016,  4017,  4021,  4023,  4027,  4028,  4030,  4035,
    4041,  4044,  4046,  4048,  4053,  4055,  4059,  4064,  4069,  4071,
    4075,  4077,  4079,  4081,  4084,  4086,  4091,  4092,  4094,  4095,
    4098,  4100,  4102,  4104,  4109,  4113,  4115,  4117,  4119,  4122,
    4124,  4126,  4129,  4132,  4134,  4138,  4141,  4144,  4146,  4150,
    4152,  4155,  4160,  4162,  4165,  4167,  4171,  4176,  4177,  4179,
    4180,  4182,  4183,  4185,  4187,  4191,  4193,  4197,  4199,  4202,
    4204,  4208,  4211,  4214,  4219,  4223,  4224,  4226,  4228,  4230,
    4232,  4234,  4237,  4239,  4241,  4247,  4251,  4257,  4261,  4263,
    4267,  4269,  4271,  4272,  4274,  4278,  4282,  4286,  4290,  4297,
    4303,  4305,  4307,  4309,  4311,  4313,  4315,  4317,  4319,  4321,
    4323,  4325,  4327,  4329,  4331,  4332,  4334,  4336,  4338,  4340,
    4342,  4344,  4346,  4351,  4357,  4359,  4365,  4371,  4373,  4375,
    4377,  4382,  4384,  4389,  4391,  4399,  4401,  4403,  4405,  4410,
    4417,  4418,  4421,  4426,  4428,  4430,  4432,  4434,  4436,  4438,
    4440,  4444,  4446,  4448,  4452,  4454,  4455,  4459,  4465,  4468,
    4474,  4479,  4481,  4483,  4485,  4487,  4489,  4492,  4495,  4498,
    4501,  4503,  4506,  4509,  4510,  4514,  4515,  4519,  4521,  4523,
    4525,  4527,  4529,  4531,  4533,  4538,  4540,  4542,  4544,  4546,
    4548,  4550,  4552,  4557,  4559,  4561,  4563,  4565,  4567,  4569,
    4571,  4573,  4575,  4577,  4579,  4581,  4583,  4585,  4587,  4589,
    4593,  4594,  4603,  4604,  4614,  4615,  4623,  4624,  4634,  4635,
    4637,  4640,  4642,  4646,  4648,  4652,  4658,  4660,  4662,  4664,
    4666,  4669,  4670,  4671,  4680,  4686,  4688,  4690,  4698,  4699,
    4703,  4705,  4709,  4714,  4716,  4717,  4720,  4726,  4734,  4735,
    4737,  4739,  4741,  4743,  4747,  4749,  4752,  4755,  4757,  4759,
    4761,  4765,  4768,  4772,  4776,  4780,  4782,  4784,  4786,  4788,
    4790,  4792,  4798,  4804,  4810,  4816,  4822,  4827,  4834,  4838,
    4843,  4845,  4849,  4850,  4852,  4858,  4866,  4867,  4870,  4872,
    4874,  4875,  4879,  4881,  4885,  4887,  4889,  4891,  4892,  4896,
    4898,  4900,  4902,  4904,  4909,  4916,  4918,  4920,  4923,  4927,
    4929,  4931,  4933,  4935,  4937,  4939,  4941,  4943,  4949,  4955,
    4960,  4962,  4965,  4967,  4969,  4971,  4975,  4981,  4983,  4985,
    4987,  4989,  4993,  4996,  4999,  5002,  5004,  5007,  5010,  5013,
    5016,  5019,  5021,  5025,  5028,  5030,  5033,  5035,  5038,  5040,
    5041,  5042,  5049,  5050,  5053,  5054,  5056,  5058,  5061,  5064,
    5066,  5068,  5073,  5077,  5079,  5083,  5085,  5088,  5094,  5097,
    5100,  5106,  5107,  5110,  5112,  5114,  5117,  5124,  5131,  5133,
    5134,  5136,  5139,  5141,  5144,  5145,  5148,  5150,  5152,  5154,
    5156,  5158,  5160,  5162,  5164,  5166,  5168,  5170,  5172,  5174,
    5176,  5178,  5180,  5182,  5184,  5186,  5188,  5190,  5192,  5194,
    5196,  5198,  5200,  5202,  5204,  5206,  5208,  5210,  5212,  5214,
    5216,  5218,  5220,  5222,  5224,  5226,  5228,  5230,  5232,  5234,
    5236,  5238,  5240,  5242,  5244,  5246,  5248,  5250,  5252,  5254,
    5256,  5258,  5260,  5262,  5264,  5266,  5268,  5270,  5272,  5274,
    5276,  5278,  5280,  5282,  5284,  5286,  5288,  5290,  5292,  5294,
    5296,  5298,  5300,  5302,  5304,  5306,  5308,  5310,  5312
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
     268,   409,  1448,   370,   323,   670,  1091,    -1,    83,   409,
     915,   370,    -1,   385,   409,   907,   370,   323,  1073,    -1,
    1208,    -1,   171,   409,   907,   370,   323,  1073,    -1,    -1,
      -1,  1073,   568,   915,   409,   671,   685,   370,   672,   683,
      -1,    -1,    -1,    -1,   915,   409,   673,   685,   674,   370,
     675,   683,    -1,    -1,    -1,   453,  1417,   602,  1417,   409,
     676,   685,   677,   370,   683,    -1,    -1,    -1,    44,   409,
     678,   685,   679,   370,   683,    -1,    -1,    -1,    -1,   344,
     688,   568,   689,   437,   652,   405,   409,   680,   685,   681,
     370,   682,   684,    -1,    -1,   323,  1091,    -1,    -1,   323,
    1091,    -1,   141,    -1,    -1,   686,    -1,   687,    -1,   686,
       5,   687,    -1,   817,    -1,    24,    -1,   915,    -1,   915,
      -1,   915,   599,   915,    -1,    -1,   513,   824,   691,   694,
     698,   695,    -1,    -1,   513,   692,   693,   696,   695,    -1,
     700,    -1,   693,   700,    -1,   702,    -1,   694,   702,    -1,
     339,    -1,    -1,    -1,   318,   697,  1458,    -1,    -1,    -1,
     318,   699,  1458,    -1,    -1,   557,   824,   701,  1458,    -1,
      -1,   557,   824,   703,  1458,    -1,   257,   912,    -1,   181,
     910,    -1,    62,   910,    -1,   148,    -1,   164,  1423,    -1,
     473,   909,    -1,    29,   706,    30,    -1,   707,    -1,   709,
      -1,   708,    -1,   707,   708,    -1,    28,    -1,   710,    -1,
     709,   710,    -1,    27,    -1,   372,    -1,    -1,    -1,   299,
     713,   715,   714,   716,    -1,   363,  1073,   604,   717,   958,
     985,   658,    -1,  1073,   604,   717,   958,   525,  1448,   985,
     658,    -1,    -1,   719,   170,    -1,   718,    -1,   717,     5,
     718,    -1,   915,    -1,   915,   599,   915,    -1,   915,   599,
      20,    -1,   720,    -1,   719,   720,    -1,    -1,   249,   726,
     721,  1458,    -1,    -1,   252,   727,   722,  1458,    -1,    -1,
     986,   723,  1458,    -1,    -1,   146,   724,  1458,    -1,    -1,
     142,   725,  1458,    -1,   921,    -1,   726,     5,   921,    -1,
     921,    -1,   727,     5,   921,    -1,    71,    -1,    72,    -1,
      73,    -1,    74,    -1,    75,    -1,    76,    -1,   409,   817,
     730,   370,    -1,    -1,     5,   771,   605,   774,    -1,   134,
      -1,   258,    -1,    -1,   733,    -1,   734,    -1,   733,   734,
      -1,    -1,    -1,   416,   735,   737,   736,  1177,    -1,   784,
      -1,  1438,    -1,   740,    -1,   737,     5,   740,    -1,    -1,
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
     915,    -1,    47,    -1,   605,  1448,    -1,   605,   488,   915,
     638,  1448,    -1,   605,   488,   915,   368,    -1,    51,   915,
      -1,   135,   842,  1091,   806,    -1,   379,   842,   822,   798,
     806,    -1,   188,   912,   806,    -1,    -1,    -1,   167,   803,
    1098,   605,   915,   599,    20,   805,   658,   804,   807,    -1,
      -1,   447,   907,    -1,   658,    -1,    -1,   808,   217,    -1,
     809,    -1,   808,   809,    -1,    -1,   330,   810,  1458,    -1,
      -1,   326,   811,  1458,    -1,    -1,   986,   812,  1458,    -1,
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
      -1,   406,    -1,   409,   817,   370,    -1,   421,   409,  1398,
     370,    -1,   273,   409,  1398,   370,    -1,   825,   923,    -1,
     825,    25,    -1,    24,    -1,   923,    -1,    25,    -1,   830,
      -1,  1073,    -1,  1073,   399,  1073,    -1,   829,    -1,   412,
     817,    -1,   371,   817,    -1,  1180,    -1,    -1,   486,   832,
    1180,    -1,     7,   817,    -1,     6,   817,    -1,   817,    -1,
     834,     5,   817,    -1,   602,   409,  1398,   370,    -1,   407,
     409,  1398,   370,    -1,   602,   409,   842,   834,   370,    -1,
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
     409,    25,   568,    25,   370,   857,    -1,    -1,  1378,   605,
    1379,    -1,   770,    -1,   848,    -1,   268,   409,  1448,   370,
      -1,    78,   409,   907,   370,    -1,    50,   409,   907,   370,
      -1,   385,   409,   907,   370,    -1,   171,   409,   907,   370,
      -1,    38,   409,   907,   370,    -1,   861,    -1,   843,    -1,
    1374,    -1,   516,    -1,   401,   409,   817,   370,    -1,   301,
     409,   817,   370,    -1,   467,   817,    -1,   422,   729,    -1,
     817,    87,    -1,   817,    88,    -1,   817,    89,    -1,    24,
      -1,   864,    -1,    18,   864,    -1,   866,    -1,   865,    -1,
      25,    -1,    25,    25,    -1,    25,    25,   568,    25,    -1,
      25,    25,   568,    25,   568,    25,    -1,    25,    25,   568,
      25,   568,    23,    -1,    25,   568,    25,    -1,    25,   568,
      25,   568,    25,    -1,    25,   568,    25,   568,    23,    -1,
      25,   568,    23,    -1,    23,    -1,    25,    -1,    25,    18,
      25,    -1,    -1,    -1,   574,  1073,    13,   824,   605,   824,
     870,   868,  1458,   869,   220,    -1,    -1,   550,   824,    -1,
      -1,    -1,    -1,   382,   872,   909,   873,  1278,   874,  1458,
     219,    -1,    -1,    -1,   617,   915,   876,   732,   877,  1017,
     879,   878,   884,   618,    -1,    -1,   889,    -1,    -1,   880,
      -1,   881,    -1,   880,   881,    -1,    -1,   619,   882,  1458,
      -1,    -1,   620,   883,  1458,    -1,    -1,   885,    -1,   886,
      -1,   885,   886,    -1,    -1,   621,   887,  1458,    -1,    -1,
     622,   888,  1458,    -1,   890,   894,   303,    -1,    70,    -1,
      70,   891,   525,   892,    -1,    70,   363,   893,    -1,  1073,
      -1,   891,     5,  1073,    -1,   915,    -1,   892,     5,   915,
      -1,  1073,    -1,   893,     5,  1073,    -1,   895,    -1,   894,
     895,    -1,    -1,   623,   896,  1458,    -1,    -1,   624,   897,
    1458,    -1,    -1,   643,   892,   898,  1458,    -1,    -1,   460,
     892,   899,  1458,    -1,    -1,   604,   892,   900,  1458,    -1,
     524,   908,    -1,   533,    18,    25,    -1,   533,    -1,   480,
      17,    25,    -1,   480,    -1,    25,    -1,  1073,    -1,    24,
      -1,   922,    -1,   824,    -1,   904,     5,   904,    -1,   905,
      -1,   915,    -1,   646,   409,   915,   370,    -1,   915,   599,
     646,   409,   915,   370,    -1,   915,   437,   655,   405,    -1,
     915,   599,    20,    -1,   915,   437,   655,   405,   599,    20,
      -1,   915,   599,   915,    -1,   915,   437,   655,   405,   599,
     915,    -1,   916,    -1,   916,    -1,   916,    -1,   916,    -1,
     916,    -1,   916,    -1,    -1,   529,    25,    -1,   919,  1457,
     920,    -1,   919,   917,   920,    -1,  1457,    -1,   328,   409,
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
      -1,   526,  1440,    -1,   631,   927,    -1,   928,    -1,   927,
       5,   928,    -1,   915,    -1,   642,   927,    -1,   633,   927,
      -1,   634,  1448,    -1,   632,   912,   638,  1448,    -1,   636,
     927,    -1,   637,  1448,    -1,   635,   912,   638,  1448,    -1,
      -1,   640,   933,   822,   938,   940,   942,   934,   936,    -1,
      -1,   935,    -1,   628,    -1,   629,    -1,    -1,   937,    -1,
     323,  1073,    -1,    -1,   939,    -1,   368,   822,    -1,    -1,
     941,    -1,   639,    25,    -1,    -1,   943,    -1,   630,    25,
     944,    -1,    -1,   378,    25,    -1,    -1,   601,   824,   554,
     946,  1458,   947,   419,    -1,    -1,    -1,   521,   948,  1458,
      -1,    -1,    -1,    41,   949,   824,   554,   950,  1458,   947,
      -1,    85,   915,   409,    25,   370,    -1,    54,   915,    -1,
      -1,   269,  1103,   954,   605,   462,    -1,   269,  1103,   535,
     955,    -1,   956,    -1,   955,     5,   956,    -1,   767,   599,
    1371,    -1,   767,   599,    20,    -1,    -1,   959,   303,    -1,
      -1,   129,    -1,   960,    -1,   959,   960,    -1,    -1,   249,
     974,   961,  1458,    -1,    -1,   252,   975,   962,  1458,    -1,
      -1,   330,   963,  1458,    -1,    -1,   326,   964,  1458,    -1,
      -1,   986,   965,  1458,    -1,    -1,   284,   966,  1458,    -1,
      -1,   254,   967,  1458,    -1,    -1,   643,   972,   968,  1458,
      -1,    -1,   460,   970,   969,  1458,    -1,   971,    -1,   970,
       5,   971,    -1,   428,    -1,   417,    -1,   973,    -1,   972,
       5,   973,    -1,   428,    -1,   417,    -1,   907,    -1,   974,
       5,   907,    -1,   907,    -1,   975,     5,   907,    -1,   293,
     978,    -1,   294,   915,   638,   978,    -1,   540,    -1,   353,
      -1,   907,    -1,    -1,   644,   981,   980,   957,    -1,   363,
    1091,   958,   914,   658,    -1,  1091,   958,   525,  1448,   914,
     658,    -1,    -1,   466,  1098,   958,   525,   915,   599,    20,
     914,   982,   658,    -1,   448,  1448,   984,    -1,   606,    -1,
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
    1038,    -1,  1190,    -1,  1200,    -1,  1059,    -1,  1438,    -1,
     875,    -1,   705,    -1,   951,    -1,   711,    -1,   705,    -1,
    1438,    -1,    -1,   705,    -1,  1438,    -1,   733,    -1,   346,
      -1,    39,    -1,    -1,    -1,    -1,    -1,  1019,  1021,   915,
     409,  1022,  1089,   370,  1023,   732,  1024,  1017,  1458,  1025,
      -1,   189,    -1,    -1,    -1,   536,  1027,   732,  1028,  1458,
     340,    -1,   444,   819,    -1,   842,    -1,   842,   822,    -1,
     335,  1382,    -1,  1033,    -1,  1034,    -1,  1033,  1034,    -1,
    1035,    -1,  1016,    -1,  1031,    -1,    -1,   384,  1036,  1037,
      -1,   732,   221,    -1,   903,    -1,    -1,    -1,    -1,    92,
     915,    91,   915,   409,  1039,  1089,   370,  1040,   732,  1041,
    1017,  1458,  1025,    -1,    -1,   537,  1043,  1058,  1049,  1044,
      -1,   341,    -1,    -1,   213,  1046,  1458,    -1,    -1,    22,
    1050,  1051,  1052,   914,  1047,  1458,    -1,    -1,    22,  1050,
     914,  1048,  1458,    -1,  1045,    -1,  1049,  1045,    -1,    -1,
     988,    -1,    24,    -1,  1073,    -1,    -1,  1073,    -1,    24,
      -1,   230,  1056,    -1,   242,  1057,    -1,   225,  1057,    -1,
     564,    -1,    24,    -1,  1073,    -1,  1056,    -1,  1057,     5,
    1056,    -1,  1073,    -1,    24,    -1,    -1,    -1,   625,   915,
    1060,   732,  1061,  1062,   626,    -1,  1063,    -1,  1062,  1063,
      -1,    -1,   627,  1064,  1458,    -1,    -1,   604,   915,  1065,
    1458,    -1,  1069,  1067,    -1,    -1,   659,  1071,    -1,  1072,
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
     399,  1073,    -1,   233,   911,   597,   905,   558,  1450,   663,
      -1,    -1,   597,   409,   824,     5,   824,   370,  1107,    -1,
      -1,   547,   409,   824,     5,   824,   370,    -1,   234,   915,
    1106,    -1,   915,    -1,   317,   913,  1111,    -1,  1112,    -1,
     525,   824,    -1,  1113,  1114,  1119,     8,  1109,    -1,    -1,
     597,  1115,   409,   824,     5,   824,   370,    -1,    -1,   535,
     916,    -1,    -1,   329,    -1,   196,  1423,   245,  1433,  1118,
      -1,   542,   908,    -1,   542,   908,     8,   842,   822,    -1,
      -1,   596,   555,  1417,   352,  1417,    -1,   596,   555,  1417,
       5,   352,  1417,    -1,   596,  1417,     5,  1417,    -1,    -1,
     628,    -1,   629,    -1,    69,  1433,  1121,  1122,    -1,    -1,
     596,  1433,    -1,    -1,   596,   555,  1417,     8,  1417,    -1,
     555,  1417,     8,  1417,    -1,   390,  1124,    -1,  1125,    -1,
    1124,     5,  1125,    -1,   182,   902,    -1,   263,   902,    -1,
     308,   902,    -1,   316,   902,    -1,   272,   902,    -1,   238,
     902,    -1,   990,    -1,   417,   991,    -1,   428,   991,    -1,
     540,   991,    -1,   353,   991,    -1,   529,   991,    -1,   527,
     903,    -1,   528,   903,    -1,   379,   659,    -1,   644,   659,
      -1,   270,    -1,   174,    -1,   130,    -1,   107,    -1,   125,
      -1,   116,    -1,  1422,   392,  1129,   525,  1127,    -1,  1073,
      -1,    24,    -1,   381,  1129,    -1,   381,  1129,     8,  1091,
      -1,   916,    -1,    -1,   440,  1138,   658,   574,  1133,  1073,
     914,   658,  1131,  1134,    -1,   440,  1138,   658,   323,  1073,
      -1,    -1,   514,    -1,    -1,  1135,   261,    -1,  1136,    -1,
    1135,  1136,    -1,    -1,   986,  1137,  1458,    -1,   823,    -1,
      -1,   583,   908,  1140,  1141,    -1,    -1,   525,  1142,    -1,
    1143,    -1,  1142,     5,  1143,    -1,  1410,    -1,   462,    -1,
     199,  1146,    67,    -1,   199,  1146,   605,  1145,    -1,   199,
    1146,    66,  1145,    -1,   199,  1146,    -1,    24,    -1,   922,
      -1,   915,    -1,    -1,   458,    -1,   124,  1146,  1147,   409,
     842,  1030,   370,    -1,   172,  1146,    -1,  1181,  1189,    -1,
     425,    40,    -1,   425,  1152,    -1,  1153,    -1,  1152,  1153,
      -1,    -1,   112,  1154,  1458,    -1,    -1,   178,  1155,  1458,
      -1,    -1,   207,  1156,  1458,    -1,    -1,   195,  1157,  1458,
      -1,    -1,   232,  1158,  1458,    -1,    -1,   180,  1073,  1159,
    1458,    -1,    -1,   203,  1073,  1160,  1458,    -1,  1171,    -1,
    1173,    -1,  1172,    -1,  1162,    -1,  1198,    -1,  1165,    -1,
      -1,   539,   824,  1163,   461,    -1,    -1,   461,    -1,    -1,
     548,   824,  1166,  1164,    -1,   137,    -1,   608,  1185,    -1,
     140,  1185,    -1,   139,  1185,    -1,    -1,  1168,    -1,  1169,
      -1,  1168,  1169,    -1,  1178,  1170,    -1,    -1,   597,  1185,
      -1,   498,  1167,  1177,    -1,   497,  1417,  1177,    -1,   496,
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
     260,    -1,  1222,    -1,  1217,    -1,    -1,    -1,   185,  1218,
    1368,   409,  1219,  1226,   370,    -1,    -1,    -1,   110,  1220,
    1368,   409,  1221,  1226,   370,  1223,    -1,    82,  1224,   370,
      -1,    34,   916,    -1,    -1,   247,    -1,  1225,    -1,  1224,
       5,  1225,    -1,   915,   566,    -1,   915,   517,    -1,   915,
      -1,  1227,    -1,  1226,     5,  1227,    -1,  1318,    -1,  1316,
      -1,    99,   915,    -1,   158,    -1,  1230,    -1,    33,   915,
    1231,    -1,  1232,    -1,  1231,     5,  1232,    -1,  1233,    -1,
    1236,    -1,  1239,    -1,  1244,    -1,  1245,    -1,  1243,    -1,
    1242,    -1,   563,  1234,    -1,   563,   409,  1235,   370,    -1,
    1227,    -1,  1227,   643,   915,    -1,  1234,    -1,  1235,     5,
    1234,    -1,   520,  1238,    -1,   520,   409,  1237,   370,    -1,
    1238,    -1,  1237,     5,  1238,    -1,   915,    -1,   433,  1241,
      -1,   433,   409,  1240,   370,    -1,  1241,    -1,  1240,     5,
    1241,    -1,  1227,    -1,    64,    -1,    65,    -1,    63,    25,
      -1,    35,  1321,    -1,    35,   409,  1246,   370,    -1,    36,
    1247,    -1,    36,   409,  1246,   370,    -1,  1321,    -1,  1246,
       5,  1321,    -1,   915,    -1,   244,    -1,   210,    -1,   143,
    1250,    -1,   120,    -1,   108,    -1,    98,    -1,    96,    -1,
     100,    -1,   157,  1423,    -1,   209,  1249,   438,  1417,   605,
    1417,    -1,   277,   908,   438,  1417,   605,  1417,    -1,    -1,
    1423,    -1,    -1,   824,    -1,   501,   824,    -1,    -1,    -1,
     457,  1368,  1253,   562,  1256,  1254,  1255,    -1,    -1,   128,
     909,    -1,   504,  1340,    -1,   409,  1260,   370,    13,   409,
    1261,   370,    -1,  1257,    -1,    20,    13,   409,  1261,   370,
      -1,    20,    13,  1261,    -1,  1259,    -1,  1257,     5,  1259,
      -1,  1371,    -1,  1258,    13,  1262,    -1,  1258,    -1,  1260,
       5,  1258,    -1,  1262,    -1,  1261,     5,  1262,    -1,  1405,
      -1,   462,    -1,  1410,    -1,   208,    -1,    -1,   227,  1265,
    1368,  1268,  1266,    -1,    -1,   458,  1267,   409,  1270,   370,
      -1,  1404,    -1,    -1,   409,  1269,   370,    -1,  1371,    -1,
    1269,     5,  1371,    -1,  1271,    -1,  1270,     5,  1271,    -1,
    1410,    -1,   462,    -1,    -1,    -1,   479,  1273,  1275,  1274,
    1276,    -1,  1280,   909,    -1,   909,    -1,    -1,    -1,   532,
    1277,  1094,    -1,    -1,    -1,   532,  1279,  1094,    -1,   480,
      -1,   533,    -1,   540,    -1,   353,    -1,   320,    -1,   374,
      -1,   356,   824,    -1,   329,   824,    -1,   216,  1368,   128,
     909,    -1,   216,  1368,  1337,    -1,   493,   598,  1284,    -1,
    1285,    -1,  1284,     5,  1285,    -1,  1286,  1287,    -1,    25,
      -1,  1371,    -1,    -1,   566,    -1,   517,    -1,   255,    -1,
     288,    -1,    -1,   305,    -1,   335,  1433,  1290,    -1,    -1,
    1422,  1293,  1294,    -1,  1322,    -1,  1326,    -1,  1289,    -1,
    1424,    -1,  1288,    -1,  1281,    -1,  1282,    -1,  1272,    -1,
    1264,    -1,  1263,    -1,  1394,    -1,  1252,    -1,   484,  1297,
     604,  1368,   605,  1302,  1296,    -1,    -1,   119,    -1,   147,
      -1,  1298,    -1,  1299,    -1,  1298,     5,  1299,    -1,   450,
      -1,   428,    -1,   417,    -1,   457,  1300,    -1,    -1,   409,
    1301,   370,    -1,  1371,    -1,  1301,     5,  1371,    -1,  1303,
      -1,  1302,     5,  1303,    -1,   441,    -1,  1369,    -1,   214,
    1368,  1305,   596,  1404,  1307,    -1,    -1,   409,  1306,   370,
      -1,  1371,    -1,  1306,     5,  1371,    -1,    -1,   118,    -1,
     471,   409,  1340,   370,    -1,   224,   409,  1311,   370,  1310,
      -1,   275,  1312,    -1,  1313,    -1,  1368,    -1,  1368,   409,
    1313,   370,    -1,  1371,    -1,  1313,     5,  1371,    -1,   455,
     409,  1315,   370,    -1,   237,   409,  1315,   370,    -1,  1371,
      -1,  1315,     5,  1371,    -1,  1314,    -1,  1309,    -1,  1308,
      -1,   378,  1373,    -1,   186,    -1,   915,  1360,  1319,  1320,
      -1,    -1,  1317,    -1,    -1,  1321,  1320,    -1,   351,    -1,
     136,    -1,  1310,    -1,   471,   409,  1340,   370,    -1,    97,
    1323,  1325,    -1,  1324,    -1,  1369,    -1,  1326,    -1,  1325,
    1326,    -1,  1304,    -1,  1295,    -1,   426,  1340,    -1,   347,
    1329,    -1,  1409,    -1,  1329,     5,  1409,    -1,   504,  1340,
      -1,   525,  1332,    -1,  1333,    -1,  1332,     5,  1333,    -1,
    1334,    -1,   494,  1334,    -1,   494,   409,  1335,   370,    -1,
    1368,    -1,  1368,  1372,    -1,  1333,    -1,  1335,     5,  1333,
      -1,  1331,  1337,  1338,  1339,    -1,    -1,  1330,    -1,    -1,
    1328,    -1,    -1,  1327,    -1,  1341,    -1,  1340,     6,  1341,
      -1,  1342,    -1,  1341,     7,  1342,    -1,  1343,    -1,   581,
    1343,    -1,  1358,    -1,   409,  1340,   370,    -1,   421,  1405,
      -1,   273,  1405,    -1,  1410,  1357,  1346,  1405,    -1,  1405,
    1357,  1410,    -1,    -1,  1347,    -1,  1348,    -1,   564,    -1,
     549,    -1,   565,    -1,   420,  1351,    -1,  1413,    -1,  1413,
      -1,  1410,   602,   409,  1353,   370,    -1,  1410,   602,  1405,
      -1,  1410,   407,   409,  1353,   370,    -1,  1410,   407,  1405,
      -1,  1354,    -1,  1353,     5,  1354,    -1,  1437,    -1,  1373,
      -1,    -1,   581,    -1,  1410,  1355,   365,    -1,  1410,  1355,
     228,    -1,  1410,  1357,  1410,    -1,  1410,  1357,  1405,    -1,
    1410,  1355,   367,  1410,     7,  1410,    -1,  1410,  1355,   535,
    1350,  1349,    -1,    13,    -1,    16,    -1,    11,    -1,    12,
      -1,   231,    -1,   350,    -1,     9,    -1,   535,    -1,    15,
      -1,    14,    -1,  1356,    -1,  1352,    -1,  1345,    -1,  1344,
      -1,    -1,   564,    -1,   338,    -1,   455,    -1,  1361,    -1,
    1362,    -1,  1364,    -1,   514,    -1,   514,   409,  1365,   370,
      -1,   389,   409,  1366,  1363,   370,    -1,   451,    -1,   376,
     409,  1366,  1363,   370,    -1,   491,   409,  1366,  1363,   370,
      -1,   516,    -1,   386,    -1,   358,    -1,   336,  1380,   605,
    1381,    -1,   336,    -1,   348,  1380,   605,  1381,    -1,   348,
      -1,   348,  1380,   409,    25,   370,   605,  1381,    -1,   553,
      -1,   511,    -1,   402,    -1,   402,   409,    25,   370,    -1,
     402,   409,    25,     5,    25,   370,    -1,    -1,     5,  1367,
      -1,   481,   409,  1366,   370,    -1,   544,    -1,   278,    -1,
     481,    -1,    42,    -1,    25,    -1,    25,    -1,    25,    -1,
      24,   599,   915,    -1,    24,    -1,   915,    -1,   915,   568,
     915,    -1,   915,    -1,    -1,   437,    25,   405,    -1,   437,
      25,     5,    25,   405,    -1,   915,  1370,    -1,  1368,   919,
     599,   915,  1370,    -1,  1368,   919,   599,    20,    -1,   915,
      -1,    24,    -1,   389,    -1,   923,    -1,    25,    -1,    17,
     923,    -1,    17,    25,    -1,    18,   923,    -1,    18,    25,
      -1,  1375,    -1,   374,  1377,    -1,   374,  1376,    -1,    -1,
    1380,   605,  1381,    -1,    -1,  1378,   605,  1379,    -1,   560,
      -1,   492,    -1,   569,    -1,   531,    -1,   432,    -1,   449,
      -1,   345,    -1,   345,   409,    25,   370,    -1,   560,    -1,
     492,    -1,   569,    -1,   531,    -1,   432,    -1,   449,    -1,
     345,    -1,   345,   409,    25,   370,    -1,   560,    -1,   492,
      -1,   569,    -1,   531,    -1,   432,    -1,   449,    -1,   345,
      -1,   560,    -1,   492,    -1,   569,    -1,   531,    -1,   432,
      -1,   449,    -1,   345,    -1,   915,    -1,    24,    -1,  1422,
     482,   909,    -1,    -1,  1422,   377,   909,   415,   574,  1392,
    1385,  1389,    -1,    -1,  1422,   377,   909,   415,    79,   574,
    1393,  1386,  1389,    -1,    -1,  1422,   377,   909,   114,  1393,
    1387,  1389,    -1,    -1,  1422,   377,   909,   115,    79,   574,
    1393,  1388,  1389,    -1,    -1,   267,    -1,   266,  1390,    -1,
    1391,    -1,  1390,     5,  1391,    -1,   915,    -1,   915,   599,
     915,    -1,    24,   599,   915,   599,   915,    -1,  1393,    -1,
    1264,    -1,  1129,    -1,  1395,    -1,  1395,  1389,    -1,    -1,
      -1,   450,  1406,  1407,  1396,  1403,  1397,  1336,  1401,    -1,
     450,  1406,  1407,  1336,  1401,    -1,  1400,    -1,  1417,    -1,
     450,   919,  1406,  1407,  1403,  1336,  1401,    -1,    -1,   503,
    1359,  1399,    -1,  1283,    -1,   310,  1402,  1223,    -1,  1283,
     310,  1402,  1223,    -1,   915,    -1,    -1,   532,  1094,    -1,
     450,   919,  1406,  1407,  1336,    -1,   409,   450,   919,  1406,
    1407,  1336,   370,    -1,    -1,   564,    -1,   338,    -1,   455,
      -1,  1408,    -1,  1407,     5,  1408,    -1,  1410,    -1,  1410,
    1457,    -1,  1410,   924,    -1,  1410,    -1,  1411,    -1,  1437,
      -1,  1410,    19,  1410,    -1,  1410,  1431,    -1,  1410,    20,
    1410,    -1,  1410,    17,  1410,    -1,  1410,    18,  1410,    -1,
    1373,    -1,   463,    -1,   406,    -1,   555,    -1,    20,    -1,
      43,    -1,   567,   409,  1359,  1410,   370,    -1,   579,   409,
    1359,  1410,   370,    -1,   580,   409,  1359,  1410,   370,    -1,
     588,   409,  1359,  1410,   370,    -1,   475,   409,  1359,  1410,
     370,    -1,   915,   409,  1412,   370,    -1,   516,   919,   409,
     919,  1412,   370,    -1,   409,  1410,   370,    -1,   422,   409,
    1432,   370,    -1,  1410,    -1,  1412,     5,  1410,    -1,    -1,
    1373,    -1,  1422,   325,  1421,  1416,  1399,    -1,  1422,   314,
    1421,  1416,   227,  1368,  1418,    -1,    -1,   300,  1417,    -1,
      24,    -1,  1073,    -1,    -1,   409,  1419,   370,    -1,  1420,
      -1,  1419,     5,  1420,    -1,   915,    -1,    24,    -1,  1073,
      -1,    -1,   246,  1423,   574,    -1,   916,    -1,  1429,    -1,
    1428,    -1,  1425,    -1,   295,  1426,   605,  1426,    -1,   276,
    1426,   599,  1427,   605,  1427,    -1,   915,    -1,   915,    -1,
     200,   767,    -1,   271,   767,  1430,    -1,   250,    -1,   154,
      -1,    71,    -1,    72,    -1,    73,    -1,    74,    -1,    75,
      -1,    76,    -1,   374,     5,  1380,   605,  1381,    -1,  1371,
       5,  1380,   605,  1381,    -1,   374,  1380,   605,  1381,    -1,
    1434,    -1,   591,  1435,    -1,  1435,    -1,  1102,    -1,   915,
      -1,  1435,   599,  1436,    -1,    24,   599,  1435,   599,  1436,
      -1,    20,    -1,  1102,    -1,   915,    -1,  1434,    -1,  1434,
     399,  1434,    -1,   105,  1439,    -1,   109,  1439,    -1,   104,
    1439,    -1,   144,    -1,   145,  1439,    -1,   102,  1439,    -1,
     127,  1439,    -1,   126,  1439,    -1,   101,  1439,    -1,   334,
      -1,   600,   605,  1440,    -1,   526,  1440,    -1,   551,    -1,
     512,  1441,    -1,   915,    -1,   568,   915,    -1,   915,    -1,
      -1,    -1,   505,  1443,   824,  1444,  1458,   304,    -1,    -1,
     638,  1448,    -1,    -1,   641,    -1,   160,    -1,   256,   910,
      -1,    48,   910,    -1,   286,    -1,   285,    -1,   287,   912,
    1445,  1446,    -1,   472,  1448,  1446,    -1,   907,    -1,  1448,
       5,   907,    -1,    81,    -1,   111,   910,    -1,   824,   545,
       5,   824,   371,    -1,   488,   824,    -1,   243,   910,    -1,
      80,  1453,     8,  1454,  1452,    -1,    -1,   525,   824,    -1,
     915,    -1,   915,    -1,   226,   910,    -1,   229,   910,   605,
     824,     5,   824,    -1,   229,   910,   598,   824,     5,   824,
      -1,    26,    -1,    -1,  1460,    -1,  1461,  1177,    -1,  1459,
      -1,  1460,  1459,    -1,    -1,  1462,  1463,    -1,   648,    -1,
     649,    -1,   650,    -1,   651,    -1,   668,    -1,   690,    -1,
     704,    -1,   705,    -1,   711,    -1,   712,    -1,   731,    -1,
     799,    -1,   800,    -1,   801,    -1,   802,    -1,   813,    -1,
     814,    -1,   815,    -1,   816,    -1,   867,    -1,   871,    -1,
     901,    -1,   925,    -1,   926,    -1,   929,    -1,   930,    -1,
     931,    -1,   932,    -1,   945,    -1,   953,    -1,   976,    -1,
     977,    -1,   979,    -1,   983,    -1,   998,    -1,   999,    -1,
    1003,    -1,  1004,    -1,  1005,    -1,  1006,    -1,  1014,    -1,
    1029,    -1,  1042,    -1,  1053,    -1,  1054,    -1,  1055,    -1,
    1066,    -1,  1105,    -1,  1108,    -1,  1110,    -1,  1116,    -1,
    1117,    -1,  1120,    -1,  1123,    -1,  1126,    -1,  1128,    -1,
    1130,    -1,  1132,    -1,  1139,    -1,  1144,    -1,  1148,    -1,
    1149,    -1,  1161,    -1,  1213,    -1,  1214,    -1,  1216,    -1,
    1228,    -1,  1229,    -1,  1248,    -1,  1251,    -1,  1291,    -1,
    1292,    -1,  1383,    -1,  1384,    -1,  1414,    -1,  1415,    -1,
    1438,    -1,  1442,    -1,  1447,    -1,  1449,    -1,  1451,    -1,
    1455,    -1,  1456,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const unsigned short yyrline[] =
{
       0,   880,   880,   883,   886,   892,   898,   905,   909,   909,
     915,   933,   934,   935,   936,   937,   951,   952,   953,   954,
     955,   960,   961,   972,   975,   978,   978,   982,   985,   986,
     992,   993,   994,   995,   996,   997,   998,   999,  1000,  1001,
    1002,  1003,  1004,  1005,  1006,  1007,  1010,  1011,  1014,  1014,
    1022,  1023,  1026,  1032,  1034,  1045,  1047,  1049,  1051,  1055,
    1057,  1119,  1123,  1127,  1127,  1134,  1137,  1141,  1142,  1145,
    1151,  1145,  1164,  1169,  1173,  1164,  1185,  1189,  1185,  1198,
    1203,  1198,  1222,  1229,  1233,  1221,  1259,  1259,  1263,  1264,
    1265,  1270,  1273,  1278,  1282,  1290,  1293,  1293,  1299,  1303,
    1318,  1316,  1334,  1334,  1349,  1349,  1352,  1352,  1356,  1359,
    1359,  1359,  1366,  1367,  1366,  1374,  1374,  1385,  1385,  1404,
    1407,  1410,  1413,  1416,  1419,  1432,  1437,  1437,  1438,  1438,
    1441,  1446,  1446,  1450,  1460,  1474,  1478,  1473,  1488,  1494,
    1502,  1503,  1506,  1506,  1509,  1513,  1518,  1525,  1525,  1529,
    1529,  1536,  1536,  1541,  1541,  1546,  1546,  1551,  1551,  1564,
    1565,  1573,  1574,  1591,  1594,  1597,  1600,  1603,  1606,  1612,
    1623,  1628,  1641,  1645,  1660,  1661,  1665,  1665,  1669,  1669,
    1669,  1670,  1671,  1676,  1676,  1679,  1679,  1688,  1689,  1690,
    1693,  1697,  1698,  1698,  1715,  1715,  1715,  1715,  1719,  1726,
    1727,  1730,  1730,  1733,  1733,  1742,  1739,  1755,  1755,  1757,
    1757,  1759,  1761,  1763,  1765,  1768,  1772,  1772,  1773,  1773,
    1777,  1777,  1789,  1789,  1794,  1798,  1800,  1801,  1804,  1804,
    1804,  1808,  1809,  1810,  1811,  1818,  1819,  1820,  1821,  1824,
    1825,  1826,  1827,  1831,  1836,  1841,  1845,  1848,  1852,  1853,
    1854,  1855,  1856,  1857,  1858,  1859,  1862,  1863,  1864,  1896,
    1900,  1902,  1904,  1904,  1911,  1917,  1917,  1921,  1922,  1923,
    1924,  1925,  1926,  1927,  1933,  1933,  1936,  1938,  1944,  1946,
    1952,  1960,  1960,  1963,  1964,  1965,  1966,  1967,  1968,  1969,
    1975,  1978,  1978,  1991,  1991,  1998,  1999,  2000,  2002,  2003,
    2005,  2007,  2008,  2009,  2010,  2015,  2021,  2027,  2028,  2030,
    2032,  2033,  2034,  2035,  2036,  2037,  2040,  2041,  2048,  2056,
    2056,  2064,  2061,  2076,  2076,  2078,  2078,  2086,  2086,  2089,
    2092,  2093,  2098,  2110,  2114,  2117,  2120,  2121,  2122,  2123,
    2124,  2129,  2136,  2142,  2147,  2151,  2147,  2162,  2164,  2169,
    2174,  2174,  2178,  2178,  2181,  2181,  2187,  2187,  2193,  2193,
    2209,  2212,  2226,  2228,  2230,  2232,  2234,  2236,  2238,  2244,
    2246,  2250,  2252,  2254,  2256,  2258,  2260,  2262,  2268,  2283,
    2286,  2299,  2300,  2301,  2302,  2303,  2307,  2308,  2309,  2313,
    2318,  2325,  2326,  2327,  2328,  2329,  2330,  2331,  2332,  2333,
    2334,  2339,  2339,  2344,  2344,  2347,  2353,  2361,  2367,  2377,
    2378,  2386,  2393,  2397,  2407,  2411,  2416,  2421,  2423,  2433,
    2446,  2454,  2467,  2472,  2478,  2483,  2488,  2489,  2495,  2566,
    2572,  2577,  2585,  2585,  2601,  2605,  2612,  2615,  2623,  2634,
    2644,  2650,  2659,  2664,  2672,  2676,  2680,  2684,  2691,  2699,
    2707,  2712,  2716,  2721,  2725,  2729,  2736,  2739,  2742,  2746,
    2750,  2754,  2758,  2766,  2776,  2781,  2774,  2796,  2801,  2796,
    2818,  2818,  2818,  2821,  2821,  2821,  2824,  2824,  2824,  2827,
    2827,  2827,  2830,  2836,  2842,  2848,  2858,  2858,  2862,  2866,
    2867,  2873,  2874,  2879,  2882,  2886,  2890,  2891,  2894,  2899,
    2905,  2909,  2913,  2916,  2922,  2925,  2928,  2943,  2946,  2952,
    2953,  2954,  2958,  2959,  2960,  2961,  2962,  2964,  2965,  2966,
    2968,  2969,  2973,  2974,  2988,  2992,  2987,  3000,  3003,  3017,
    3021,  3026,  3016,  3046,  3052,  3046,  3066,  3066,  3068,  3069,
    3073,  3073,  3077,  3077,  3082,  3082,  3089,  3090,  3094,  3094,
    3098,  3098,  3103,  3103,  3110,  3114,  3115,  3116,  3121,  3121,
    3124,  3124,  3128,  3128,  3132,  3132,  3136,  3136,  3141,  3141,
    3146,  3146,  3151,  3151,  3156,  3156,  3172,  3189,  3190,  3191,
    3192,  3193,  3194,  3197,  3197,  3200,  3202,  3205,  3208,  3210,
    3211,  3212,  3214,  3216,  3218,  3220,  3224,  3231,  3233,  3239,
    3244,  3249,  3254,  3254,  3257,  3263,  3268,  3271,  3278,  3278,
    3280,  3286,  3290,  3291,  3293,  3295,  3297,  3299,  3303,  3312,
    3312,  3319,  3320,  3321,  3322,  3323,  3324,  3325,  3326,  3327,
    3328,  3329,  3330,  3331,  3332,  3333,  3334,  3335,  3336,  3337,
    3338,  3339,  3340,  3341,  3342,  3343,  3344,  3345,  3346,  3347,
    3348,  3349,  3350,  3351,  3352,  3353,  3354,  3355,  3356,  3357,
    3358,  3359,  3360,  3361,  3373,  3386,  3393,  3393,  3397,  3402,
    3408,  3412,  3416,  3422,  3426,  3430,  3436,  3436,  3444,  3445,
    3449,  3449,  3453,  3454,  3457,  3460,  3460,  3463,  3465,  3465,
    3468,  3470,  3470,  3471,  3473,  3473,  3482,  3480,  3492,  3492,
    3492,  3495,  3497,  3495,  3504,  3510,  3520,  3520,  3524,  3530,
    3530,  3534,  3535,  3546,  3547,  3549,  3551,  3556,  3556,  3560,
    3559,  3566,  3565,  3571,  3571,  3576,  3576,  3582,  3582,  3587,
    3587,  3592,  3592,  3597,  3597,  3602,  3602,  3610,  3611,  3619,
    3620,  3625,  3626,  3635,  3636,  3643,  3644,  3652,  3653,  3662,
    3667,  3672,  3673,  3674,  3678,  3677,  3688,  3693,  3698,  3698,
    3709,  3714,  3715,  3716,  3717,  3720,  3720,  3726,  3726,  3728,
    3731,  3731,  3733,  3737,  3737,  3740,  3741,  3744,  3744,  3749,
    3749,  3752,  3753,  3754,  3755,  3756,  3757,  3758,  3759,  3760,
    3761,  3762,  3763,  3764,  3765,  3766,  3767,  3771,  3789,  3789,
    3789,  3815,  3826,  3833,  3839,  3845,  3851,  3862,  3885,  3884,
    3901,  3901,  3905,  3906,  3914,  3915,  3916,  3917,  3924,  3925,
    3927,  3928,  3932,  3937,  3938,  3939,  3940,  3941,  3942,  3943,
    3944,  3945,  3946,  3947,  3950,  3950,  3952,  3952,  3952,  3954,
    3958,  3958,  3967,  3972,  3985,  3991,  3966,  4005,  4019,  4029,
    4018,  4042,  4049,  4049,  4054,  4059,  4064,  4065,  4068,  4068,
    4068,  4071,  4071,  4079,  4085,  4099,  4103,  4116,  4098,  4134,
    4134,  4147,  4158,  4157,  4169,  4165,  4182,  4179,  4192,  4192,
    4194,  4195,  4197,  4198,  4201,  4202,  4203,  4205,  4210,  4215,
    4221,  4223,  4224,  4227,  4228,  4231,  4233,  4242,  4248,  4242,
    4259,  4260,  4264,  4264,  4274,  4274,  4286,  4289,  4293,  4297,
    4302,  4306,  4307,  4308,  4309,  4310,  4314,  4314,  4316,  4316,
    4319,  4328,  4366,  4366,  4369,  4373,  4378,  4416,  4417,  4418,
    4421,  4435,  4447,  4447,  4452,  4453,  4459,  4514,  4519,  4526,
    4531,  4539,  4545,  4566,  4569,  4570,  4608,  4609,  4613,  4614,
    4618,  4671,  4675,  4678,  4684,  4695,  4702,  4710,  4710,  4713,
    4714,  4715,  4716,  4717,  4720,  4723,  4729,  4732,  4736,  4740,
    4747,  4752,  4759,  4762,  4768,  4770,  4770,  4770,  4774,  4788,
    4795,  4802,  4805,  4819,  4826,  4827,  4830,  4831,  4835,  4841,
    4846,  4852,  4853,  4858,  4862,  4862,  4866,  4867,  4870,  4871,
    4875,  4883,  4886,  4892,  4893,  4895,  4897,  4901,  4901,  4902,
    4907,  4915,  4916,  4921,  4922,  4924,  4937,  4939,  4940,  4942,
    4945,  4948,  4951,  4954,  4957,  4960,  4964,  4968,  4972,  4975,
    4979,  4982,  4983,  4984,  4987,  4990,  4993,  4996,  4999,  5002,
    5005,  5021,  5029,  5029,  5031,  5038,  5045,  5060,  5058,  5078,
    5083,  5084,  5088,  5089,  5091,  5092,  5094,  5094,  5102,  5111,
    5111,  5121,  5122,  5125,  5126,  5129,  5129,  5141,  5146,  5151,
    5156,  5166,  5166,  5170,  5173,  5173,  5175,  5185,  5192,  5194,
    5198,  5201,  5201,  5205,  5204,  5208,  5207,  5211,  5210,  5214,
    5213,  5217,  5216,  5219,  5219,  5235,  5234,  5256,  5257,  5258,
    5259,  5260,  5261,  5264,  5264,  5270,  5270,  5273,  5273,  5283,
    5284,  5285,  5292,  5304,  5305,  5308,  5309,  5312,  5315,  5315,
    5320,  5324,  5329,  5335,  5336,  5337,  5341,  5342,  5343,  5344,
    5348,  5358,  5360,  5365,  5368,  5373,  5379,  5386,  5393,  5402,
    5409,  5416,  5423,  5430,  5439,  5439,  5441,  5441,  5444,  5445,
    5446,  5447,  5448,  5449,  5450,  5451,  5452,  5453,  5456,  5456,
    5459,  5460,  5461,  5462,  5465,  5465,  5468,  5468,  5471,  5472,
    5473,  5474,  5475,  5476,  5477,  5478,  5480,  5481,  5482,  5483,
    5485,  5486,  5487,  5488,  5490,  5491,  5492,  5493,  5494,  5495,
    5496,  5497,  5501,  5507,  5515,  5526,  5535,  5546,  5550,  5554,
    5560,  5525,  5573,  5576,  5584,  5596,  5598,  5603,  5608,  5618,
    5621,  5625,  5633,  5602,  5642,  5646,  5650,  5654,  5646,  5664,
    5665,  5666,  5667,  5672,  5674,  5677,  5681,  5684,  5691,  5696,
    5697,  5698,  5703,  5704,  5710,  5710,  5710,  5728,  5728,  5728,
    5753,  5754,  5760,  5761,  5767,  5768,  5773,  5774,  5775,  5779,
    5782,  5791,  5792,  5798,  5799,  5804,  5808,  5814,  5815,  5820,
    5821,  5822,  5823,  5824,  5825,  5826,  5831,  5834,  5841,  5842,
    5848,  5849,  5856,  5859,  5866,  5867,  5872,  5876,  5879,  5885,
    5886,  5892,  5897,  5898,  5902,  5908,  5909,  5916,  5917,  5922,
    5923,  5928,  5939,  5940,  5941,  5942,  5943,  5944,  5945,  5946,
    5947,  5950,  5953,  5959,  5959,  5965,  5965,  5976,  5990,  5992,
    5990,  5999,  6002,  6007,  6015,  6024,  6025,  6034,  6053,  6053,
    6060,  6062,  6068,  6069,  6072,  6073,  6077,  6078,  6079,  6083,
    6093,  6093,  6099,  6099,  6102,  6105,  6106,  6112,  6113,  6118,
    6119,  6124,  6125,  6130,  6134,  6129,  6146,  6150,  6157,  6161,
    6161,  6174,  6178,  6178,  6193,  6195,  6197,  6199,  6201,  6203,
    6205,  6207,  6213,  6223,  6228,  6233,  6234,  6238,  6240,  6241,
    6244,  6245,  6246,  6249,  6254,  6261,  6262,  6268,  6281,  6281,
    6286,  6291,  6297,  6298,  6301,  6302,  6309,  6316,  6320,  6330,
    6331,  6335,  6343,  6347,  6348,  6353,  6355,  6359,  6360,  6364,
    6365,  6366,  6367,  6371,  6372,  6377,  6378,  6383,  6384,  6389,
    6390,  6395,  6399,  6400,  6405,  6406,  6410,  6411,  6416,  6422,
    6427,  6432,  6436,  6437,  6442,  6443,  6449,  6451,  6456,  6457,
    6463,  6464,  6465,  6470,  6472,  6483,  6487,  6488,  6491,  6492,
    6497,  6499,  6501,  6502,  6508,  6513,  6518,  6522,  6523,  6528,
    6529,  6538,  6544,  6549,  6550,  6555,  6560,  6564,  6565,  6570,
    6571,  6572,  6575,  6576,  6581,  6581,  6585,  6596,  6597,  6600,
    6601,  6604,  6605,  6610,  6611,  6616,  6617,  6622,  6623,  6628,
    6629,  6635,  6636,  6641,  6643,  6648,  6649,  6650,  6653,  6657,
    6658,  6666,  6671,  6675,  6680,  6682,  6684,  6686,  6692,  6693,
    6697,  6697,  6700,  6701,  6706,  6708,  6710,  6712,  6714,  6716,
    6722,  6723,  6724,  6725,  6726,  6727,  6728,  6729,  6730,  6731,
    6736,  6737,  6738,  6739,  6741,  6742,  6743,  6744,  6756,  6757,
    6758,  6762,  6763,  6768,  6770,  6771,  6772,  6774,  6775,  6776,
    6777,  6779,  6780,  6782,  6783,  6785,  6786,  6787,  6788,  6790,
    6794,  6795,  6801,  6803,  6804,  6805,  6806,  6811,  6815,  6819,
    6823,  6824,  6828,  6829,  6836,  6844,  6845,  6846,  6849,  6854,
    6859,  6869,  6873,  6877,  6878,  6879,  6880,  6882,  6884,  6886,
    6888,  6891,  6894,  6898,  6899,  6903,  6904,  6908,  6908,  6908,
    6908,  6908,  6908,  6909,  6912,  6917,  6917,  6917,  6917,  6917,
    6917,  6919,  6922,  6928,  6928,  6928,  6928,  6928,  6928,  6928,
    6929,  6929,  6929,  6929,  6929,  6929,  6929,  6931,  6932,  6935,
    6945,  6944,  6950,  6950,  6956,  6956,  6962,  6962,  6972,  6973,
    6974,  6977,  6977,  6980,  6981,  6982,  6987,  6988,  6994,  6997,
    7002,  7016,  7018,  7013,  7031,  7040,  7040,  7043,  7051,  7052,
    7056,  7057,  7058,  7062,  7065,  7066,  7075,  7080,  7084,  7085,
    7086,  7087,  7095,  7096,  7100,  7101,  7102,  7107,  7112,  7115,
    7119,  7121,  7123,  7125,  7127,  7129,  7130,  7131,  7132,  7133,
    7134,  7136,  7138,  7140,  7142,  7144,  7146,  7148,  7150,  7151,
    7155,  7155,  7157,  7158,  7161,  7169,  7174,  7174,  7178,  7178,
    7183,  7183,  7187,  7187,  7191,  7197,  7197,  7200,  7200,  7206,
    7213,  7214,  7215,  7219,  7220,  7223,  7224,  7228,  7234,  7244,
    7245,  7253,  7254,  7255,  7256,  7257,  7258,  7262,  7263,  7264,
    7347,  7359,  7359,  7363,  7364,  7365,  7366,  7370,  7371,  7372,
    7375,  7387,  7485,  7487,  7489,  7491,  7495,  7500,  7502,  7504,
    7506,  7510,  7513,  7518,  7523,  7527,  7536,  7537,  7541,  7553,
    7556,  7552,  7575,  7575,  7579,  7580,  7583,  7584,  7585,  7586,
    7587,  7588,  7589,  7594,  7595,  7599,  7602,  7607,  7611,  7616,
    7620,  7625,  7629,  7632,  7636,  7639,  7644,  7648,  7659,  7665,
    7665,  7666,  7667,  7674,  7683,  7683,  7685,  7686,  7687,  7688,
    7689,  7690,  7691,  7692,  7693,  7694,  7695,  7696,  7697,  7698,
    7699,  7700,  7701,  7702,  7703,  7704,  7705,  7706,  7707,  7708,
    7709,  7710,  7711,  7712,  7713,  7714,  7715,  7716,  7717,  7718,
    7719,  7720,  7721,  7722,  7723,  7724,  7725,  7726,  7727,  7728,
    7729,  7730,  7731,  7732,  7733,  7734,  7735,  7736,  7737,  7738,
    7739,  7740,  7741,  7742,  7743,  7744,  7745,  7746,  7747,  7748,
    7749,  7750,  7751,  7752,  7753,  7754,  7755,  7756,  7757,  7758,
    7759,  7760,  7761,  7762,  7763,  7764,  7765,  7766,  7767
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
  "drops_cmd", "drops_c", "create_cmd", "create_c_2", "@152", "@153", 
  "@154", "@155", "create_c_1", "op_no_log", "idx_column_list", 
  "idx_column", "table_element_list", "table_element", "upd_stats_cmd", 
  "alter_cmd", "alter_1_c", "alter_clauses", "alter_clause", 
  "alter_add_clause", "add_column_clause", "add_column_clauses", 
  "alter_drop_clause", "drop_column_list", "drop_column", 
  "alter_modify_clause", "modify_column_clauses", "modify_column_clause", 
  "alter_lock_mode", "alter_modify_next", "alter_add_constraint_clause", 
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
    1215,  1215,  1216,  1216,  1218,  1219,  1217,  1220,  1221,  1217,
    1222,  1222,  1223,  1223,  1224,  1224,  1225,  1225,  1225,  1226,
    1226,  1227,  1227,  1228,  1228,  1229,  1230,  1231,  1231,  1232,
    1232,  1232,  1232,  1232,  1232,  1232,  1233,  1233,  1234,  1234,
    1235,  1235,  1236,  1236,  1237,  1237,  1238,  1239,  1239,  1240,
    1240,  1241,  1242,  1242,  1243,  1244,  1244,  1245,  1245,  1246,
    1246,  1247,  1248,  1248,  1248,  1248,  1248,  1248,  1248,  1248,
    1248,  1248,  1248,  1249,  1249,  1250,  1250,  1251,  1253,  1254,
    1252,  1255,  1255,  1255,  1256,  1256,  1256,  1256,  1257,  1257,
    1258,  1259,  1260,  1260,  1261,  1261,  1262,  1262,  1262,  1263,
    1265,  1264,  1267,  1266,  1266,  1268,  1268,  1269,  1269,  1270,
    1270,  1271,  1271,  1273,  1274,  1272,  1275,  1275,  1276,  1277,
    1276,  1278,  1279,  1278,  1280,  1280,  1280,  1280,  1280,  1280,
    1280,  1280,  1281,  1282,  1283,  1284,  1284,  1285,  1286,  1286,
    1287,  1287,  1287,  1288,  1289,  1290,  1290,  1291,  1293,  1292,
    1294,  1294,  1294,  1294,  1294,  1294,  1294,  1294,  1294,  1294,
    1294,  1294,  1295,  1296,  1296,  1297,  1297,  1298,  1298,  1299,
    1299,  1299,  1299,  1300,  1300,  1301,  1301,  1302,  1302,  1303,
    1303,  1304,  1305,  1305,  1306,  1306,  1307,  1307,  1308,  1309,
    1310,  1311,  1312,  1312,  1313,  1313,  1314,  1314,  1315,  1315,
    1316,  1316,  1316,  1317,  1317,  1318,  1319,  1319,  1320,  1320,
    1321,  1321,  1321,  1321,  1322,  1323,  1324,  1325,  1325,  1326,
    1326,  1327,  1328,  1329,  1329,  1330,  1331,  1332,  1332,  1333,
    1333,  1333,  1334,  1334,  1335,  1335,  1336,  1337,  1337,  1338,
    1338,  1339,  1339,  1340,  1340,  1341,  1341,  1342,  1342,  1343,
    1343,  1344,  1344,  1345,  1345,  1346,  1346,  1346,  1347,  1348,
    1348,  1349,  1350,  1351,  1352,  1352,  1352,  1352,  1353,  1353,
    1354,  1354,  1355,  1355,  1356,  1356,  1356,  1356,  1356,  1356,
    1357,  1357,  1357,  1357,  1357,  1357,  1357,  1357,  1357,  1357,
    1358,  1358,  1358,  1358,  1359,  1359,  1359,  1359,  1360,  1360,
    1360,  1361,  1361,  1362,  1362,  1362,  1362,  1362,  1362,  1362,
    1362,  1362,  1362,  1362,  1362,  1362,  1362,  1362,  1362,  1362,
    1363,  1363,  1364,  1364,  1364,  1364,  1364,  1365,  1366,  1367,
    1368,  1368,  1368,  1368,  1369,  1370,  1370,  1370,  1371,  1371,
    1371,  1372,  1373,  1373,  1373,  1373,  1373,  1373,  1373,  1373,
    1373,  1374,  1375,  1376,  1376,  1377,  1377,  1378,  1378,  1378,
    1378,  1378,  1378,  1378,  1378,  1379,  1379,  1379,  1379,  1379,
    1379,  1379,  1379,  1380,  1380,  1380,  1380,  1380,  1380,  1380,
    1381,  1381,  1381,  1381,  1381,  1381,  1381,  1382,  1382,  1383,
    1385,  1384,  1386,  1384,  1387,  1384,  1388,  1384,  1389,  1389,
    1389,  1390,  1390,  1391,  1391,  1391,  1392,  1392,  1393,  1393,
    1394,  1396,  1397,  1395,  1398,  1399,  1399,  1400,  1401,  1401,
    1401,  1401,  1401,  1402,  1403,  1403,  1404,  1405,  1406,  1406,
    1406,  1406,  1407,  1407,  1408,  1408,  1408,  1409,  1410,  1410,
    1411,  1411,  1411,  1411,  1411,  1411,  1411,  1411,  1411,  1411,
    1411,  1411,  1411,  1411,  1411,  1411,  1411,  1411,  1411,  1411,
    1412,  1412,  1413,  1413,  1414,  1415,  1416,  1416,  1417,  1417,
    1418,  1418,  1419,  1419,  1420,  1421,  1421,  1422,  1422,  1423,
    1424,  1424,  1424,  1425,  1425,  1426,  1427,  1428,  1429,  1430,
    1430,  1431,  1431,  1431,  1431,  1431,  1431,  1432,  1432,  1432,
    1433,  1434,  1434,  1435,  1435,  1435,  1435,  1436,  1436,  1436,
    1437,  1437,  1438,  1438,  1438,  1438,  1438,  1438,  1438,  1438,
    1438,  1439,  1439,  1439,  1439,  1439,  1440,  1440,  1441,  1443,
    1444,  1442,  1445,  1445,  1446,  1446,  1447,  1447,  1447,  1447,
    1447,  1447,  1447,  1448,  1448,  1449,  1449,  1450,  1450,  1451,
    1451,  1452,  1452,  1453,  1454,  1455,  1456,  1456,  1457,  1458,
    1458,  1459,  1460,  1460,  1462,  1461,  1463,  1463,  1463,  1463,
    1463,  1463,  1463,  1463,  1463,  1463,  1463,  1463,  1463,  1463,
    1463,  1463,  1463,  1463,  1463,  1463,  1463,  1463,  1463,  1463,
    1463,  1463,  1463,  1463,  1463,  1463,  1463,  1463,  1463,  1463,
    1463,  1463,  1463,  1463,  1463,  1463,  1463,  1463,  1463,  1463,
    1463,  1463,  1463,  1463,  1463,  1463,  1463,  1463,  1463,  1463,
    1463,  1463,  1463,  1463,  1463,  1463,  1463,  1463,  1463,  1463,
    1463,  1463,  1463,  1463,  1463,  1463,  1463,  1463,  1463,  1463,
    1463,  1463,  1463,  1463,  1463,  1463,  1463,  1463,  1463
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
       1,     1,     1,     1,     0,     0,     7,     0,     0,     8,
       3,     2,     0,     1,     1,     3,     2,     2,     1,     1,
       3,     1,     1,     2,     1,     1,     3,     1,     3,     1,
       1,     1,     1,     1,     1,     1,     2,     4,     1,     3,
       1,     3,     2,     4,     1,     3,     1,     2,     4,     1,
       3,     1,     1,     1,     2,     2,     4,     2,     4,     1,
       3,     1,     1,     1,     2,     1,     1,     1,     1,     1,
       2,     6,     6,     0,     1,     0,     1,     2,     0,     0,
       7,     0,     2,     2,     7,     1,     5,     3,     1,     3,
       1,     3,     1,     3,     1,     3,     1,     1,     1,     1,
       0,     5,     0,     5,     1,     0,     3,     1,     3,     1,
       3,     1,     1,     0,     0,     5,     2,     1,     0,     0,
       3,     0,     0,     3,     1,     1,     1,     1,     1,     1,
       2,     2,     4,     3,     3,     1,     3,     2,     1,     1,
       0,     1,     1,     1,     1,     0,     1,     3,     0,     3,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     7,     0,     1,     1,     1,     1,     3,     1,
       1,     1,     2,     0,     3,     1,     3,     1,     3,     1,
       1,     6,     0,     3,     1,     3,     0,     1,     4,     5,
       2,     1,     1,     4,     1,     3,     4,     4,     1,     3,
       1,     1,     1,     2,     1,     4,     0,     1,     0,     2,
       1,     1,     1,     4,     3,     1,     1,     1,     2,     1,
       1,     2,     2,     1,     3,     2,     2,     1,     3,     1,
       2,     4,     1,     2,     1,     3,     4,     0,     1,     0,
       1,     0,     1,     1,     3,     1,     3,     1,     2,     1,
       3,     2,     2,     4,     3,     0,     1,     1,     1,     1,
       1,     2,     1,     1,     5,     3,     5,     3,     1,     3,
       1,     1,     0,     1,     3,     3,     3,     3,     6,     5,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     0,     1,     1,     1,     1,     1,
       1,     1,     4,     5,     1,     5,     5,     1,     1,     1,
       4,     1,     4,     1,     7,     1,     1,     1,     4,     6,
       0,     2,     4,     1,     1,     1,     1,     1,     1,     1,
       3,     1,     1,     3,     1,     0,     3,     5,     2,     5,
       4,     1,     1,     1,     1,     1,     2,     2,     2,     2,
       1,     2,     2,     0,     3,     0,     3,     1,     1,     1,
       1,     1,     1,     1,     4,     1,     1,     1,     1,     1,
       1,     1,     4,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     3,
       0,     8,     0,     9,     0,     7,     0,     9,     0,     1,
       2,     1,     3,     1,     3,     5,     1,     1,     1,     1,
       2,     0,     0,     8,     5,     1,     1,     7,     0,     3,
       1,     3,     4,     1,     0,     2,     5,     7,     0,     1,
       1,     1,     1,     3,     1,     2,     2,     1,     1,     1,
       3,     2,     3,     3,     3,     1,     1,     1,     1,     1,
       1,     5,     5,     5,     5,     5,     4,     6,     3,     4,
       1,     3,     0,     1,     5,     7,     0,     2,     1,     1,
       0,     3,     1,     3,     1,     1,     1,     0,     3,     1,
       1,     1,     1,     4,     6,     1,     1,     2,     3,     1,
       1,     1,     1,     1,     1,     1,     1,     5,     5,     4,
       1,     2,     1,     1,     1,     3,     5,     1,     1,     1,
       1,     3,     2,     2,     2,     1,     2,     2,     2,     2,
       2,     1,     3,     2,     1,     2,     1,     2,     1,     0,
       0,     6,     0,     2,     0,     1,     1,     2,     2,     1,
       1,     4,     3,     1,     3,     1,     2,     5,     2,     2,
       5,     0,     2,     1,     1,     2,     6,     6,     1,     0,
       1,     2,     1,     2,     0,     2,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const unsigned short yydefact[] =
{
     810,     0,   610,     0,     0,     0,     0,     0,     0,     0,
    1745,     0,   610,   610,   861,   178,   834,   839,   176,   181,
     814,     0,   808,   811,   812,   815,   817,   860,   816,   855,
     856,   858,   182,   133,   130,     0,   126,   128,   127,   131,
     705,     0,  1751,   610,   610,  1754,     0,  1750,  1747,  1744,
    1742,  1743,  1749,  1748,  1746,   293,  1618,  1617,   854,   174,
     185,   177,   182,     1,   818,   813,   859,   857,   835,   125,
     129,   132,  1788,   611,  1758,  1755,   610,  1756,  1753,   610,
       0,   583,   610,     0,   175,   864,   928,   584,   862,   618,
     921,   610,   922,   929,   927,   185,   179,   198,   610,   183,
     199,   228,   841,  1207,   610,   610,   840,   134,  1195,   848,
     610,   610,   831,   833,   830,   832,   809,   819,   820,   842,
     823,   824,   825,   828,   826,   827,   829,   604,  1757,  1752,
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
       0,     0,   238,   226,  1208,     0,     0,  1196,  1794,   534,
     898,   843,     0,   207,   208,     0,   274,   276,   271,   272,
     268,   270,   267,   269,   266,     0,   276,   287,   288,   284,
     286,   283,   285,   278,     0,     0,     0,   327,     0,   330,
     332,   215,     0,   214,     0,     0,   185,    11,    12,   940,
     610,   926,   620,   197,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   185,   227,   230,   610,   704,   865,   610,
       0,  1792,  1794,  1131,  1707,   836,     0,   610,     0,     0,
     263,     0,     0,   273,   290,   264,   289,     0,   282,     0,
     305,     0,   299,   610,   324,   610,   329,   319,     0,     0,
     308,   298,   261,   318,     0,     0,     0,     0,     0,   243,
       0,   235,   217,   203,     0,   246,   234,   259,   957,     0,
     952,   953,   610,     0,   850,  1793,  1791,   610,   610,   610,
     610,   610,   610,   610,  1775,   610,  1298,  1297,   610,  1299,
     610,   375,  1296,  1237,   610,     5,  1295,   376,   373,   610,
     378,   172,   463,  1109,     0,     0,  1305,   122,   372,   371,
    1229,   366,   610,  1254,  1766,   610,   377,   344,   610,     3,
       2,   610,   374,  1234,   610,   610,   367,   364,   379,   610,
     610,   610,   610,   610,  1293,   370,   610,   610,   610,   610,
     610,   610,   610,   610,  1292,   610,   610,   610,   173,  1231,
     363,   362,   610,   610,  1770,  1769,   610,   610,   610,   135,
    1230,   369,   368,   610,   610,   365,   916,   463,   610,   529,
       0,   610,   610,   463,   610,   610,   610,   463,   797,  1205,
     610,   610,  1113,   610,  1759,   610,   102,   610,   610,   869,
     610,   610,   610,   610,   798,   610,   610,   610,     0,   610,
     610,   610,   610,   610,   610,   610,   676,   610,   610,  1796,
    1797,  1798,  1799,  1800,  1801,  1802,  1803,  1804,  1805,  1806,
    1807,  1808,  1809,  1810,  1811,  1812,  1813,  1814,  1815,  1816,
    1817,  1818,  1819,  1820,  1821,  1822,  1823,  1824,  1825,  1826,
    1827,  1828,  1829,  1830,  1831,  1832,  1833,  1834,  1835,  1836,
    1837,  1838,  1839,  1840,  1841,  1842,   907,  1843,  1844,  1845,
    1846,  1847,  1848,  1849,  1850,  1851,  1852,  1853,  1854,  1855,
    1856,  1857,  1858,  1100,  1102,  1097,  1099,  1098,  1101,  1859,
    1860,  1228,  1861,  1233,  1232,  1862,  1863,  1255,  1864,  1865,
    1866,  1867,  1868,  1869,  1870,  1871,  1378,  1872,  1873,  1874,
    1875,  1876,  1877,  1878,  1795,   837,   538,   838,   610,   902,
       0,   900,     0,   326,   209,   210,     0,   275,   280,     0,
       0,     0,     0,   328,   331,     0,   213,     0,   938,   219,
       0,   185,     0,     0,     0,     0,   610,  1209,   610,     0,
    1197,     0,  1241,     0,   822,  1768,   598,   121,     0,   610,
    1734,  1733,  1011,  1730,  1732,  1783,     0,  1248,     0,  1244,
    1253,     7,     0,     6,   610,  1776,  1073,  1074,   610,  1165,
    1164,  1112,  1163,  1111,   610,   610,   422,   424,     0,  1202,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     610,  1585,     0,     0,     0,   416,   610,   610,     0,     0,
     415,   610,     0,   432,     0,   499,     0,     0,     0,     0,
       0,   610,     0,   411,  1306,     0,   382,   381,   388,   428,
     425,   383,   497,   489,   384,   386,   496,   387,   928,   423,
     426,   431,  1294,   498,  1709,  1300,   123,   610,  1077,   120,
     610,   804,    23,   600,   380,     0,   803,  1070,   805,     0,
    1304,   891,   890,   893,   889,   892,  1785,     0,   887,     0,
     599,   984,   888,  1779,     0,  1767,   119,   981,   706,   979,
       0,   596,  1762,   752,   751,     0,   753,   588,   749,     0,
     610,   994,   601,  1375,   610,   610,  1046,  1044,   610,  1038,
    1040,  1039,  1037,  1036,   610,   610,   610,  1035,   610,   779,
     610,   610,     0,     0,     0,     0,   610,   610,     0,     0,
       0,  1025,  1016,  1017,     0,  1058,   409,    23,   851,   401,
    1773,     0,  1764,   124,   597,   610,  1043,  1042,  1206,  1204,
    1130,     0,  1698,  1699,  1131,  1219,  1131,  1114,  1115,  1118,
    1133,  1307,   610,     0,     0,     0,     0,     0,   610,     0,
     610,     0,    61,     0,   928,     0,    67,     0,   100,   576,
     664,   610,  1103,  1001,  1107,     0,   610,  1059,  1223,     0,
    1110,   668,   665,   666,     0,   670,   671,     0,   673,   674,
     610,   669,   961,   963,   610,   610,   962,   754,   959,   715,
     955,   920,     0,   610,   610,     0,   680,   681,     0,     0,
     918,   914,   915,   911,   912,   913,   906,   910,   909,   610,
     610,   610,   610,   610,     0,   542,   544,   536,   539,   540,
     904,  1794,   899,   901,   844,     0,   277,   279,   306,   300,
       0,     0,   309,     0,   224,     0,   222,   244,   236,   228,
     247,   958,   174,   954,   866,   174,     0,   610,     0,  1282,
    1283,   610,   610,   610,  1256,  1257,  1259,  1260,  1261,  1265,
    1264,  1262,  1263,     0,   611,   606,   610,  1731,   610,   610,
    1013,   610,   610,  1247,  1246,   610,  1240,     0,  1561,  1562,
       0,  1075,     0,    23,  1160,  1162,  1161,   390,   389,   610,
     610,  1137,   467,   610,   610,   610,   610,     0,   610,     0,
       0,   610,   430,  1593,  1591,  1592,  1588,  1590,  1587,  1589,
    1581,     0,   610,     0,   610,     0,   429,     0,   610,   503,
     502,     0,     0,   473,   470,   479,   610,   476,   610,   610,
     414,   610,   610,   610,   610,   610,   610,   610,   610,   610,
     610,   610,   610,   610,   610,   610,   610,   610,   163,   164,
     165,   166,   167,   168,   504,   505,   506,   443,   610,   610,
     442,   448,     0,   610,   394,   610,     0,   395,   385,   391,
     393,   396,   397,   398,   399,   400,   392,   421,   420,   464,
     610,   971,     0,     0,   349,    24,   343,   610,   610,  1067,
     610,   610,   610,   610,   610,   610,     0,   988,  1708,   610,
     610,   185,     0,   610,   610,  1764,   610,   610,   610,   610,
     610,   136,     0,   610,   998,   990,   991,   996,  1376,  1377,
     917,   333,   407,   610,   530,   581,   580,   578,  1019,   582,
    1024,  1020,  1023,   772,     0,  1021,  1022,   773,  1029,  1033,
    1026,  1027,  1031,  1032,  1030,  1028,  1034,     0,   806,   610,
     610,     0,   404,   405,   402,   403,   610,     0,     0,   762,
     761,   760,  1765,  1772,    23,  1126,  1127,  1128,  1129,  1123,
    1121,  1220,  1135,  1120,  1116,   610,     0,  1117,  1760,    79,
     610,     0,   610,   610,    96,     0,    97,   610,     0,   610,
      72,   610,   610,   109,   104,     0,   896,     0,   895,     0,
     463,  1105,   610,   946,   947,   970,   942,   943,   799,   968,
    1061,  1225,   610,  1227,  1226,   696,   610,   610,   610,   685,
     715,   715,   713,   610,   610,   716,     0,    25,   684,   687,
       0,   694,   690,   919,   908,  1705,  1706,  1696,  1696,     0,
       0,  1619,   610,   185,  1329,   610,   610,  1330,  1373,   185,
     610,  1374,   610,  1658,   610,  1343,     0,  1391,  1389,  1388,
    1387,  1385,  1386,  1384,  1382,  1379,  1450,  1449,  1380,  1381,
    1390,  1628,  1383,  1712,  1711,  1710,  1794,  1794,   555,   546,
     537,     0,   541,  1794,   903,   174,     0,   320,   212,     0,
     185,   221,   204,  1210,   174,  1198,  1441,   610,  1440,     0,
       0,  1442,  1285,     0,  1291,  1287,  1284,     0,     0,   610,
       0,     0,     0,  1281,  1277,  1432,  1431,  1430,  1252,  1251,
     610,  1276,  1272,   610,  1268,  1266,     0,   610,   605,     0,
       0,  1012,   610,     0,  1010,  1737,  1739,  1738,  1735,  1784,
    1781,  1245,   610,   610,   610,  1238,   463,   341,     0,  1203,
      91,     0,     0,     0,     0,  1658,     0,     0,     0,     0,
       0,   521,   507,   512,     0,   508,   511,   510,     0,     0,
       0,     0,     0,     0,   417,     0,   170,     0,   433,   610,
     610,   610,     0,   610,     0,     0,     0,   435,   434,   449,
     444,   455,   458,   459,   456,   462,   461,   460,   450,   451,
     453,   452,   454,   445,   447,   463,   457,   446,   463,    91,
     427,   610,  1235,  1003,  1071,  1072,  1069,  1068,     0,   894,
       0,     0,   585,     0,     0,   610,   982,   980,     0,   708,
     709,     0,     0,  1763,  1771,     0,     0,   592,     0,   594,
     750,     0,   140,   610,   992,   999,     0,   610,  1007,   610,
     336,   610,   610,   610,   610,    23,  1045,  1351,     0,     0,
     796,   784,   794,   795,   782,   783,   790,   786,   789,   785,
     793,   788,   791,   792,   781,   787,   780,   779,  1018,   807,
     410,   610,  1050,   610,  1774,   763,   764,   360,   610,  1131,
     610,  1134,  1119,  1794,    91,     0,     0,     0,     0,   610,
       0,   610,    62,    91,     0,   115,   110,     0,   105,   610,
     112,   106,   880,   872,   878,     0,  1104,   610,  1106,  1108,
       0,   610,   950,     0,   610,     0,   610,  1060,  1224,  1794,
     667,   672,   675,   688,   686,   602,     0,   610,   610,   731,
     769,   729,   725,   723,   767,     0,     0,   755,     0,   717,
     727,   960,   956,   610,     0,     0,     0,   693,   610,     0,
     610,   610,     0,     0,   610,  1564,     0,  1445,  1446,  1717,
    1412,  1467,   610,     0,  1715,     0,     0,  1660,  1661,  1659,
     610,  1308,   610,  1395,  1401,  1400,  1399,  1403,     0,  1396,
    1397,   610,  1629,  1640,   543,   545,   610,     0,   558,   550,
     552,     0,   547,   548,   610,   610,   566,   568,   610,     0,
     564,   905,   845,   211,     0,     0,   223,  1166,   867,  1144,
    1420,  1422,     0,  1289,   610,     0,   610,   610,     0,  1279,
     610,   610,  1556,  1554,  1541,  1543,  1539,     0,  1538,     0,
    1547,  1534,  1555,     0,  1546,  1531,  1537,  1553,  1545,  1436,
    1528,  1529,  1530,     0,  1274,  1270,     0,   610,  1258,   609,
       0,   608,   610,   978,     0,   610,   610,  1780,     4,     8,
      10,  1560,  1563,   610,   463,   495,   468,    92,    93,    95,
     492,   491,   494,   490,   610,   419,   501,   486,   486,     0,
     509,     0,   513,     0,   281,  1202,     0,  1601,  1599,  1600,
    1596,  1598,  1595,  1597,  1586,   493,  1202,   500,   418,   265,
       0,  1202,   474,   471,   480,  1202,   477,  1202,  1202,  1202,
     610,     0,   610,     0,   465,     0,   610,   610,  1000,   610,
     610,   610,   610,   610,     0,   610,   185,   707,   610,   589,
     591,   610,   610,   157,   155,   610,   610,   137,     0,   147,
     153,   715,   142,   144,   610,   997,  1008,  1009,     0,   408,
     335,   340,   587,   334,   610,   337,   342,  1352,   531,   579,
     577,   779,   774,   775,  1049,  1051,   610,   406,   361,  1124,
    1122,  1221,  1222,     0,    80,    65,  1215,     0,     0,     0,
      98,     0,     0,    73,    69,  1794,  1794,   108,   103,   117,
     113,     0,   107,   770,   881,   602,  1794,   871,   870,   879,
    1002,   610,     0,   610,   969,   463,     0,     0,  1679,  1572,
    1575,  1680,  1583,  1573,  1677,   610,     0,  1066,  1676,     0,
     610,  1678,     0,     0,     0,     0,  1734,  1574,  1062,  1063,
    1675,  1580,  1065,  1668,  1740,  1669,   698,   691,   689,     0,
      23,   610,   745,   719,   747,   721,  1794,  1794,  1794,  1794,
     779,   740,   739,   735,   737,   744,   743,   733,   741,   714,
     718,  1794,   602,    45,    43,    40,    34,    38,    42,    37,
      30,    39,    33,    36,    31,    41,    32,    44,    35,     0,
      28,     0,   695,  1697,   610,   610,  1694,  1645,  1646,  1638,
    1624,  1639,     0,     0,   610,  1041,  1444,  1447,   610,     0,
     610,   610,  1468,  1363,  1335,  1720,  1719,  1718,   610,   610,
    1641,  1662,  1664,     0,  1358,   610,  1357,   610,  1359,  1354,
    1355,  1356,  1347,  1344,   610,   610,  1402,   610,     0,     0,
    1633,  1630,  1631,   557,   562,   610,   610,  1794,  1794,   535,
     549,   572,   560,   574,  1794,  1794,   570,   554,   565,   836,
     321,   205,     0,  1192,  1211,   836,     0,  1199,  1192,   610,
       0,  1286,     0,   610,     0,   610,     0,  1473,  1475,  1477,
    1523,  1522,  1521,  1520,  1479,     0,  1502,  1288,  1565,     0,
    1421,   610,  1424,     0,  1428,   610,  1278,     0,     0,  1609,
    1607,  1608,  1604,  1606,  1603,  1605,     0,     0,     0,     0,
       0,     0,     0,     0,  1434,     0,  1437,  1438,   610,  1273,
     610,  1267,  1269,   607,  1736,   610,     0,  1782,   610,     0,
    1249,   610,     0,     0,   610,     0,   483,     0,   484,     0,
     523,     0,   520,   517,   488,   482,  1140,  1594,     0,  1139,
       0,   169,  1138,     0,     0,     0,  1141,     0,  1143,  1142,
    1136,   436,     0,   439,     0,   438,     0,     0,     0,   610,
       0,  1301,  1787,  1786,   586,   610,     0,    46,   610,   712,
     711,   710,  1302,   610,     0,   715,  1794,  1794,   149,   612,
     159,   151,   161,   141,   148,  1794,   610,     0,   610,     0,
     610,     0,   610,  1794,     0,   777,   602,   610,  1761,     0,
      91,   610,    63,   610,   610,   610,    76,     0,    91,   116,
     111,  1794,  1794,   101,   779,   882,   876,   884,   883,   873,
     527,   931,   948,   949,   944,   610,  1577,  1576,  1579,  1578,
    1582,     0,     0,   610,  1524,     0,  1524,  1524,  1524,  1524,
     610,   610,   610,   610,   610,   610,  1721,  1722,  1723,  1724,
    1725,  1726,  1671,   610,   701,   699,     0,   678,   692,   603,
     756,     0,   610,  1794,   610,  1794,   732,   730,   726,   724,
     768,     0,  1794,     0,  1794,   728,    23,     0,    26,     0,
    1700,  1658,  1628,   610,   610,  1637,  1620,  1636,  1448,     0,
    1414,     0,  1362,  1455,   610,     0,  1716,     0,  1713,   610,
    1654,   642,   627,   640,   646,   661,   626,   638,   621,   654,
     657,   660,   624,   655,   633,   637,   648,   659,   656,   658,
     649,   631,   629,   653,   635,   634,   622,   623,   625,   628,
     639,   651,   630,   663,   641,   645,   647,   662,   636,   650,
     652,   632,   643,   644,  1666,  1665,   610,  1361,  1360,  1348,
    1346,     0,  1405,     0,  1398,   610,   610,   610,   610,   559,
     556,   551,   553,   610,  1794,  1794,   567,   569,  1794,  1794,
       0,     0,  1190,  1191,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1189,     0,     0,  1177,  1178,
    1179,  1176,  1181,  1182,  1183,  1180,  1167,  1158,   610,     0,
    1214,     0,  1794,     0,  1153,     0,     0,     0,     0,     0,
       0,   610,  1145,  1146,     0,  1078,     0,  1290,     0,  1482,
     610,     0,  1502,  1481,  1478,   610,  1443,   610,  1516,  1512,
    1513,  1510,  1519,  1518,  1511,  1514,  1515,  1517,   610,     0,
    1503,     0,     0,   610,     0,  1568,     0,   610,     0,   610,
    1427,  1280,  1426,  1418,     0,     0,     0,  1558,  1550,  1550,
       0,     0,  1550,  1557,     0,  1572,  1433,  1435,  1438,  1275,
    1271,  1015,   610,     9,   610,  1242,   853,  1076,   469,    94,
     610,  1467,  1648,     0,   486,   514,     0,     0,   274,   475,
     472,   481,   478,   610,   441,   440,   466,   347,  1236,     0,
     610,  1778,     0,     0,   983,    47,     0,   593,   595,   590,
     765,   158,   156,   610,  1794,   610,   610,   610,  1794,   154,
     143,   610,   146,   145,   610,   989,   993,   339,   610,   966,
    1353,   964,     0,   779,   776,    23,  1125,    86,  1216,    68,
     610,     0,    99,    66,    91,    74,     0,   118,   114,   771,
    1794,   886,   602,   885,   610,   524,   610,   801,   802,   800,
       0,  1688,     0,     0,     0,  1526,  1527,  1525,   610,   610,
     610,   610,   610,   610,  1690,     0,  1064,  1673,  1674,  1670,
    1672,  1741,   610,  1794,   697,   682,   679,     0,   746,   720,
     748,   722,   738,   736,   742,   734,   757,    29,    27,   610,
    1695,   610,  1625,  1626,  1622,  1628,   610,  1413,   610,  1416,
       0,  1337,  1332,  1331,  1334,   610,  1663,   610,  1642,     0,
     610,  1309,  1315,     0,  1318,  1320,  1349,  1345,   610,  1404,
     610,     0,  1634,  1632,   563,   561,   573,   575,   571,     0,
       0,   228,  1184,  1185,  1186,  1188,  1171,  1169,  1168,  1172,
    1173,  1170,  1187,  1174,  1175,  1159,   975,  1194,   972,   610,
       0,  1212,     0,  1157,  1156,  1151,  1149,  1148,  1152,  1150,
    1154,  1155,  1147,  1200,  1423,  1658,  1480,  1474,  1476,  1484,
     610,  1497,   610,  1495,  1505,  1504,   610,  1692,   610,  1489,
    1488,  1490,     0,  1486,  1487,  1507,  1506,     0,  1419,  1425,
     610,  1429,  1616,  1614,  1615,  1611,  1613,  1610,  1612,  1540,
       0,  1542,     0,     0,     0,     0,  1548,  1552,     0,  1532,
    1439,  1014,  1250,  1243,  1239,   610,  1456,  1457,  1459,  1462,
    1469,   610,     0,  1524,  1650,  1644,   487,   485,     0,   519,
     518,  1602,   171,   437,   610,    23,     0,   610,  1006,   610,
      48,   986,     0,    23,   160,   150,     0,   614,   616,   162,
     152,   765,     0,   338,   610,   610,   532,   778,  1047,   610,
      81,     0,    64,     0,    77,    86,    70,   877,   874,   528,
    1794,     0,  1584,     0,     0,     0,  1689,     0,   610,     0,
       0,     0,     0,   610,  1686,     0,   700,   677,   683,   602,
    1704,     0,  1702,  1654,  1628,  1628,  1621,  1415,  1658,  1417,
    1411,   610,  1336,     0,  1714,  1655,     0,   610,  1322,     0,
    1311,   610,   610,   610,  1406,  1409,  1393,  1407,  1410,   610,
     847,   846,   322,   206,   977,   976,   974,   610,  1193,  1079,
    1083,  1085,   610,  1089,   610,  1087,  1091,  1080,  1081,     0,
     868,     0,   610,     0,  1498,  1501,  1500,     0,     0,     0,
    1693,  1492,  1483,     0,  1566,  1570,  1565,     0,  1559,  1551,
    1535,  1533,     0,  1536,   610,  1460,   610,  1571,  1463,   610,
    1470,  1471,  1653,  1242,   610,   610,   610,   516,   515,   348,
     345,   610,  1004,     0,     0,     0,   985,   766,   138,   613,
      23,   995,   967,   965,  1052,    87,  1217,    82,     0,    75,
      86,  1794,   525,   945,     0,     0,     0,  1685,     0,  1681,
    1682,  1683,  1684,  1691,   702,   758,   610,  1701,     0,  1627,
    1623,   610,  1338,   610,  1648,   610,  1327,  1317,  1324,  1326,
    1328,   610,     0,   610,   610,  1310,  1319,  1321,  1350,   610,
    1394,  1392,  1635,   973,  1794,  1794,  1093,  1794,  1095,  1794,
    1794,  1082,  1213,  1201,     0,   610,  1496,  1494,   610,  1692,
    1509,     0,  1569,     0,  1549,  1464,     0,  1458,  1452,  1453,
    1667,   610,  1472,  1466,  1651,  1368,  1364,  1365,  1370,  1369,
    1649,  1242,   350,  1005,  1777,   610,   610,   610,   610,   610,
     610,    53,     0,    52,     0,    50,   610,   610,   139,  1056,
    1048,     0,  1054,    86,    91,    86,    71,   875,     0,     0,
    1729,     0,  1687,  1794,    23,  1703,  1648,     0,  1342,     0,
    1339,  1341,  1643,     0,  1328,   610,  1323,     0,  1312,  1313,
    1408,  1084,  1086,  1794,  1090,  1794,  1088,  1092,     0,  1499,
    1508,  1491,  1493,  1567,  1544,   610,  1461,   610,  1451,   610,
    1372,  1371,  1367,  1652,   356,   354,   346,     0,   352,   358,
      55,    60,    57,    59,    56,    58,    54,     0,    49,     0,
     615,   617,  1794,  1053,  1055,  1218,    83,    78,   526,  1727,
    1728,   698,   759,  1647,  1656,   610,  1333,  1316,  1325,   610,
    1094,  1096,  1657,  1465,  1454,  1366,  1794,  1794,   351,   353,
    1794,    51,   610,  1057,     0,   703,  1340,     0,   357,   355,
     359,     0,    84,  1314,   987,    88,    90,   610,    85,    89
};

/* YYDEFGOTO[NTERM-NUM]. */
static const short yydefgoto[] =
{
      -1,   549,   550,   551,   552,   702,  1708,  1709,   188,   264,
     189,  1124,  1125,  1594,  1929,  2953,  2454,  2455,  2844,  2954,
    2955,   553,   892,  2490,  2158,  2860,  1543,  2157,  2725,  2494,
    2858,  1534,  2149,  2964,  3064,  3075,  2720,  3078,  1716,  1717,
    1718,  1225,  1829,   554,  1235,   897,  1233,  1550,  1838,  1547,
    1836,  1841,  2162,  1234,  1835,  1551,  2161,   555,    16,    35,
      36,    37,    38,    39,   113,   558,   820,  1482,  1151,  1787,
    1791,  1792,  1788,  1789,  2464,  2468,  2135,  2127,  2126,  2128,
    2131,  1107,  1059,  1750,   559,    83,    84,    18,    60,   142,
      96,   255,    98,    99,   200,   278,   100,   101,   242,   228,
     674,  2321,   305,   656,  1654,   332,   333,   229,   287,   280,
     282,   975,   976,   146,   355,   147,   148,   293,   230,   231,
    1468,   393,   243,   246,   244,   245,   314,   370,   371,   373,
     378,   659,   247,   248,   323,   375,   196,    19,    80,   177,
     178,   179,   665,  2320,   180,   251,   240,   326,   327,   328,
     329,  1495,   560,   561,   562,   563,   777,  2942,  2695,  1126,
    3016,  3017,  3018,  3057,  3056,  3060,   564,   565,   566,   567,
     753,  1108,   858,  1193,  1194,  1161,   855,  1162,   755,   756,
     757,   758,   759,   760,   761,  1062,  1109,  2102,  1110,  1111,
    1112,  1113,  1114,  1115,  1116,   708,   762,  1449,  2106,  1390,
    2073,   763,  1420,  2094,  1419,  2093,  1423,  2097,  1421,  2095,
    2076,  2085,   764,   765,   766,   767,  1404,  1405,  1406,  1407,
     568,  2730,  2968,  2505,   569,   828,  1497,  2143,   114,   237,
     365,  1319,   957,   958,   959,  1316,  1317,  1641,  1642,  1643,
    1987,  1988,  1320,  1321,  1637,  1991,  1983,  1649,  1650,  1994,
    1995,  2318,  2314,  2315,   570,  1168,    85,  1463,  1464,  1803,
     860,   810,   863,   685,   799,   782,   821,  1890,    86,   686,
    1004,  1700,    41,   127,  2130,    87,   769,  2294,   571,   572,
     912,   913,   573,   574,   575,   576,   920,  2535,   941,  2747,
     942,  1573,   943,  1887,   944,  2207,   945,  1597,   577,  1569,
    2206,  2533,  2532,  2973,   115,    20,   578,  1142,  1469,  1470,
    1587,  1266,  1588,  1589,  2213,  2215,  1899,  1898,  1911,  1897,
    1896,  2224,  2222,  1903,  1904,  1907,  1908,  1893,  1895,   579,
     580,   818,   581,  1262,   927,  2974,   582,  1201,  2703,  1590,
    1900,  1844,  2164,   851,  1178,  1517,  1812,  2144,  1813,  1174,
    1516,   583,   584,   906,  1565,  2509,   585,   586,   587,   588,
      21,    64,    22,    23,    24,   116,   117,   589,   118,    25,
     646,    26,   119,   120,   157,   367,  1325,  1999,  2781,   121,
     153,   298,   590,  2072,    27,    28,    29,    30,    31,    59,
      88,   122,   412,  1334,  2005,   591,   901,  1848,  1554,  1846,
    2861,  2500,  1555,  1845,  2167,  2502,   592,   593,   594,   793,
     794,  1237,   123,   238,   366,   650,   651,   961,  1323,   595,
     946,   947,   596,   824,  1274,   948,   770,    90,    91,    92,
      93,  1244,   183,   138,    94,   135,   191,   192,  1245,  1246,
    2174,  1247,   409,   410,   929,   411,   930,  2480,  2481,  1248,
    1249,  1122,  2607,  2608,  2786,   691,   808,   809,   597,  1137,
    2846,   598,  2476,   599,  1155,  1156,  1157,  1488,  1486,   600,
     601,  1768,  1798,   602,  1010,  1374,   603,   852,   853,   604,
     868,   605,  1939,   606,  2854,   607,  1816,  2960,  2961,  2962,
    3032,   857,   608,  1250,  1567,  1878,  1879,   609,  1456,   707,
    1022,   610,   611,  2007,  2611,  2797,  2798,  2904,  2905,  2909,
    2907,  2910,  2993,  2995,   612,   613,  1239,  1559,   614,  1241,
     876,   877,   878,  1217,   615,   616,   617,  1529,  1209,   871,
     199,   879,   880,   771,  2008,  2362,  2363,  2346,   711,   712,
    2003,  2347,  2350,   124,   152,   359,   985,  1659,  2364,  2801,
    1031,   618,   869,   125,   149,   356,   982,  1657,  2351,  2799,
    2004,   896,  2150,  2721,  2963,  1212,   619,   620,   621,   622,
     623,   780,  1766,   704,  1713,   624,  2674,   698,   699,  2069,
    1353,   625,   626,   627,   994,   995,   996,  1365,  1696,   997,
    1693,  1362,   998,  1668,  1354,   999,  1000,  1001,  1002,  1662,
    1345,   628,   789,   772,   629,  1297,  1963,  2770,  2895,  2571,
    2572,  2573,  2574,  2769,  2887,  2888,  1298,  1299,  1612,  2563,
    2763,  2245,  2560,  2979,  2980,  1300,  1622,  2299,  1973,  2577,
    2773,  1808,  2142,  1974,  1301,  1302,  2684,  2936,  2937,  2938,
    3012,  1303,  1304,  1159,   630,   631,   954,  1305,  1306,  2901,
    1628,  1629,  1630,  1976,  2301,  2776,  2777,  1307,  1949,  2239,
    2760,  1355,  1356,  1341,  2029,  1660,  2030,  1357,  2033,  1358,
    2056,  1359,  2057,  2417,  1663,  1308,  1606,  1607,  1946,  1309,
    2932,  2830,  2928,  1952,  2431,  2676,  2677,  2678,  2926,  2432,
    1953,  2831,  2933,  2016,  2017,  2018,  2019,  2020,  2021,  2642,
    2643,  2644,  2920,  2809,  3001,  2022,  2803,  2804,  2392,  2023,
    2393,  2024,  2518,  1689,  1690,  1691,  2663,  1692,  2414,  2408,
    2819,  2031,  2778,  2395,  2575,  2828,  1880,   773,  1881,  2180,
    1050,  2077,  1744,  2046,  2659,    58,   632,   633,  2555,  2755,
    2232,  2754,  1633,  1981,  1982,  2236,  1940,  1310,  1941,  2250,
    2766,  1396,  1936,  1937,  2685,  2833,  2568,  2559,  2025,  1620,
    1960,  1961,  2929,  2026,  1883,  2525,  2811,   634,   635,  1599,
    1938,  2550,  2751,  2752,  1277,   636,   775,  1312,  1313,  1615,
    2247,  1314,  1315,  1957,  2202,  2514,   692,  1884,   694,  1378,
    1885,    62,    47,    78,    75,   638,   882,  1533,  1145,  1203,
     639,   861,   640,  2117,   641,  1707,   696,  1380,   642,   643,
      73,   360,   361,   362,   363,   364,   644
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -2577
static const short yypact[] =
{
    3330,   978, -2577,   617,   617,   617,   617,   617,   617,   617,
   -2577,   617, -2577,   317, -2577, -2577, -2577,  1054, -2577, -2577,
   -2577,   361, -2577,  3330, -2577, -2577, -2577, -2577, -2577,  1958,
   -2577, -2577, -2577, -2577, -2577,   336,   399, -2577,   355, -2577,
   -2577,   510, -2577, -2577,   -98, -2577,  -122, -2577, -2577, -2577,
   -2577, -2577, -2577, -2577, -2577, -2577, -2577, -2577, -2577,   733,
     453, -2577, -2577, -2577,   186, -2577, -2577, -2577, -2577, -2577,
   -2577, -2577, -2577, -2577, -2577, -2577, -2577, -2577, -2577,   -98,
     229, -2577, -2577,   667,  1054, -2577,   650, -2577, -2577, -2577,
   -2577,   841,   314, -2577, -2577, -2577,   895,   590, -2577, -2577,
   -2577,   936, -2577, -2577, -2577, -2577, -2577, -2577, -2577, -2577,
   -2577, -2577, -2577, -2577, -2577, -2577, -2577,   186, -2577, -2577,
   -2577, -2577, -2577, -2577, -2577, -2577, -2577, -2577, -2577, -2577,
    3252,   314, -2577,    76,    99, -2577, -2577,   516, -2577,   359,
     974,   453,   492, -2577, -2577, -2577, -2577, -2577,  7054, -2577,
     615,   957, -2577,  1054, -2577, -2577, -2577, -2577, -2577, -2577,
     524,  1168, -2577, -2577,   642, -2577,   648, -2577,   682, -2577,
   -2577,   653, -2577,   700, -2577, -2577, -2577, -2577, -2577, -2577,
   -2577, -2577, -2577,   722, -2577, -2577, -2577,    99,  1804,  1110,
   -2577,   168, -2577,    99, -2577, -2577,   172, -2577, -2577, -2577,
     163, -2577, -2577, -2577, -2577, -2577, -2577, -2577, -2577,   524,
   -2577,  1168, -2577, -2577,   719, -2577,   729, -2577,   727, -2577,
   -2577,   780, -2577,   788, -2577, -2577, -2577, -2577, -2577, -2577,
   -2577, -2577,   796,  1184, -2577,   856, -2577,  1054,  1054,   861,
   -2577, -2577,   -64, -2577,   638,  1226, -2577,   646,  1410,  1256,
    1260, -2577,  1262,  1270,  1279, -2577,   707, -2577,   545, -2577,
   -2577, -2577, -2577, -2577,    99, -2577,    99,   873,   213, -2577,
   -2577, -2577,  1288, -2577, -2577,  1290, -2577, -2577, -2577, -2577,
   -2577,   -64, -2577, -2577, -2577,  1308,  1316,   453,  1262,  1317,
    1328,   755, -2577,  1318, -2577,   989,   954, -2577,  1025, -2577,
   -2577, -2577,   767, -2577, -2577,  1343, -2577,   962, -2577, -2577,
   -2577, -2577, -2577, -2577, -2577,  1410,   962, -2577, -2577, -2577,
   -2577, -2577, -2577,   965,   177,   209,   276, -2577,  2622, -2577,
   -2577, -2577,   981,  1378,   222,  1014, -2577, -2577,  1804, -2577,
      99, -2577, -2577, -2577,   800,  1376,  1171,   237,   239,   775,
    1004,   251,  1040, -2577, -2577, -2577,  1043, -2577, -2577,  1043,
    1083, -2577,  3854,   492,  4997,  2646,  -248,  1043,  1405,   -33,
   -2577,  1226,  1399, -2577, -2577, -2577, -2577,  1407, -2577,  1409,
   -2577,  1412, -2577, -2577, -2577, -2577, -2577, -2577,  1262,  1415,
   -2577, -2577, -2577, -2577,   223,  1421,   -33,  1034,  1419, -2577,
    1423, -2577, -2577, -2577,  1426, -2577, -2577, -2577,   855,  1086,
    1456, -2577,  1043,  1089, -2577, -2577, -2577, -2577, -2577, -2577,
   -2577, -2577,   129, -2577, -2577, -2577, -2577, -2577, -2577, -2577,
      53, -2577, -2577, -2577, -2577, -2577, -2577, -2577, -2577, -2577,
   -2577, -2577, -2577, -2577,    72,    72,  6391, -2577, -2577, -2577,
   -2577, -2577, -2577, -2577, -2577, -2577, -2577, -2577, -2577, -2577,
   -2577, -2577, -2577, -2577,   880, -2577, -2577, -2577,  6391, -2577,
     880, -2577,   880,  1026, -2577, -2577,    69, -2577, -2577,    69,
   -2577, -2577,    69, -2577, -2577, -2577, -2577, -2577, -2577, -2577,
   -2577, -2577,   880, -2577, -2577, -2577, -2577,   549, -2577, -2577,
   -2577, -2577, -2577, -2577,   129, -2577, -2577, -2577, -2577, -2577,
    7571,   880,  7189, -2577,   823,   823, -2577, -2577, -2577,   125,
     880,   136,  6391,  7189, -2577,  1229,  6391, -2577,   -98, -2577,
    7189, -2577,  7189,   880, -2577, -2577,  7189,  7189,    72, -2577,
   -2577, -2577,   823, -2577, -2577,   823, -2577, -2577,   197, -2577,
   -2577, -2577, -2577, -2577, -2577, -2577, -2577, -2577, -2577, -2577,
   -2577, -2577, -2577, -2577, -2577, -2577, -2577, -2577, -2577, -2577,
   -2577, -2577, -2577, -2577, -2577, -2577, -2577, -2577, -2577, -2577,
   -2577, -2577, -2577, -2577, -2577, -2577, -2577, -2577, -2577, -2577,
   -2577, -2577, -2577, -2577, -2577, -2577,    27, -2577, -2577, -2577,
   -2577, -2577, -2577, -2577, -2577, -2577, -2577, -2577, -2577, -2577,
   -2577, -2577, -2577, -2577, -2577, -2577, -2577, -2577, -2577, -2577,
   -2577, -2577, -2577, -2577, -2577, -2577, -2577, -2577, -2577, -2577,
   -2577, -2577, -2577, -2577, -2577, -2577,   625, -2577, -2577, -2577,
   -2577, -2577, -2577, -2577, -2577, -2577,   480, -2577, -2577, -2577,
     611, -2577,  1104, -2577, -2577, -2577,  1194, -2577, -2577,  1106,
    1108,  1109,  1112, -2577, -2577,   877,  1479,  1118, -2577, -2577,
    1212, -2577,  1125,  1131,   899,  1134, -2577, -2577, -2577,  1135,
   -2577,   299, -2577,   187, -2577, -2577, -2577, -2577,   908,  1484,
    1072, -2577,   916, -2577,   915, -2577,  1509,  -169,   279, -2577,
   -2577, -2577,  1114, -2577,  1496, -2577, -2577,  1064,   154, -2577,
   -2577, -2577,  1257, -2577,  7189,  7189, -2577, -2577,  1116,  1019,
    1124,  1126,  1127,  1136,  1137,  1140,  1142,  1144,  1145,  1149,
    7189,  1746,  1150,  1152,  1163, -2577,  7189,  7189,  1165,  1176,
   -2577,  7189,  1177, -2577,  1180,  1181,  1183,  1189,  1192,  1195,
    1196,  7189,  1198,  4349, -2577,    87, -2577, -2577, -2577, -2577,
   -2577, -2577, -2577, -2577, -2577, -2577, -2577, -2577,   536, -2577,
    1128, -2577, -2577, -2577, -2577, -2577, -2577,   880, -2577, -2577,
    1496, -2577,     7, -2577, -2577,  1298, -2577,    18, -2577,  1174,
   -2577, -2577, -2577, -2577,  1539, -2577, -2577,   354, -2577,  1006,
   -2577,  1012,  1539, -2577,  1041, -2577, -2577,  1217,   149, -2577,
    1182, -2577,   983, -2577, -2577,  1210, -2577,  -127, -2577,   997,
     -74,  -205, -2577,  1320,  7189,  7189, -2577,  1616, -2577, -2577,
   -2577, -2577, -2577, -2577,   227,   227,   227, -2577,   227, -2577,
     227,   227,  1052,     7,  1052,  1052,   139,   139,  1052,  1052,
       7, -2577,  1623, -2577,    16,  1632, -2577,     7, -2577,  6324,
   -2577,    64,    65, -2577, -2577,  7189, -2577, -2577, -2577, -2577,
   -2577,   975, -2577, -2577,   492,  1277,   492,  6391, -2577,    75,
   -2577, -2577,  7189,  1231,  1235,  1236,  1238,  1239,  1627,  1245,
     136,  1181, -2577,  1332,   546,  1088, -2577,  1117, -2577, -2577,
   -2577,   140, -2577,  1655, -2577,  1653, -2577, -2577,    71,  1119,
   -2577, -2577,  1671, -2577,  1042,  1671,  1676,  1045,  1671,  1676,
    7189,  1671, -2577, -2577,   154,   880, -2577, -2577,  1285,   347,
   -2577, -2577,  1276,   880,  7189,  1278, -2577, -2577,  1663,  1665,
    1646, -2577, -2577, -2577, -2577, -2577, -2577, -2577, -2577,   142,
     142, -2577, -2577, -2577,  2021, -2577, -2577,  1626,   480, -2577,
   -2577,   619, -2577, -2577, -2577,  1261, -2577, -2577, -2577, -2577,
    3252,  1262, -2577,  1266, -2577,   310, -2577, -2577, -2577, -2577,
   -2577, -2577,  1054, -2577, -2577,  1054,   679,  1284,  1691, -2577,
   -2577,   805,  1310,   987,  1712, -2577, -2577, -2577, -2577, -2577,
   -2577, -2577, -2577,  1311, -2577, -2577,  1484,   915,    99,   129,
    -219,  1705, -2577, -2577, -2577, -2577, -2577,  1156,  1139,  1158,
    1326, -2577,  1333,    89, -2577, -2577, -2577,  1103,  1103,   823,
    7189, -2577, -2577,   823,   823,   823,   823,  1293,  7189,  1148,
    1404,  7189,  4349,  1337, -2577, -2577, -2577, -2577, -2577, -2577,
   -2577,  1146,   823,  1720,  7189,  4327,  4349,  1293,  7189, -2577,
    4349,  1727,   202, -2577, -2577, -2577,  7189, -2577,  7189,  7189,
    4349,  7189,  7189,  7189,  7189,  7189,  7189,  7189,  7189,  7189,
    7189,  7189,  7189,  7189,  7189,  7189,  7189,  7189, -2577, -2577,
   -2577, -2577, -2577, -2577, -2577, -2577, -2577, -2577,  7189,  7189,
   -2577, -2577,  1340,  7189, -2577,  7189,  1344, -2577, -2577, -2577,
   -2577, -2577, -2577, -2577, -2577, -2577, -2577, -2577, -2577, -2577,
     880, -2577,  1147,  1345, -2577, -2577, -2577,   129,   159, -2577,
     159,   136,    69,  7189,  7189,  7189,  1347, -2577, -2577,   880,
     880, -2577,  1154,   136,   823,  1120, -2577,    99,    51,   549,
     880, -2577,  1172,  7189,  1433, -2577, -2577,  1232, -2577, -2577,
    1632,    86, -2577,   154, -2577, -2577,  1755,  1757, -2577, -2577,
   -2577, -2577, -2577, -2577,  1388, -2577, -2577, -2577, -2577, -2577,
   -2577, -2577, -2577, -2577, -2577, -2577, -2577,  7571, -2577,   139,
    7189,   471, -2577, -2577,  1772, -2577,   823,  1753,  1756, -2577,
   -2577, -2577, -2577, -2577,    94, -2577, -2577, -2577, -2577,  1651,
   -2577,  1591, -2577, -2577, -2577,  7189,    72, -2577, -2577, -2577,
   -2577,  1767,   823,   823, -2577,  1225, -2577,   823,  1197,   880,
   -2577, -2577,  7189,   -41, -2577,  1237, -2577,   284, -2577,  1335,
   -2577,  1339,  7189,   765, -2577, -2577,   314, -2577,  1796, -2577,
    1286, -2577,   880, -2577, -2577, -2577, -2577,   823,   823,   238,
     347,  1675,  1418,   880,   154, -2577,  1289, -2577, -2577,  1805,
    1784,  1435, -2577, -2577, -2577, -2577, -2577,  1516,  1516,   207,
    1292, -2577, -2577, -2577, -2577,  1496,  1496, -2577, -2577, -2577,
   -2577, -2577, -2577,   -39,  1496, -2577,   743, -2577, -2577, -2577,
   -2577, -2577, -2577, -2577, -2577, -2577, -2577, -2577, -2577, -2577,
   -2577,   968, -2577, -2577, -2577, -2577,   263,   263,    97,   640,
   -2577,   842, -2577,   619, -2577,  1054,  1793, -2577, -2577,  1793,
   -2577, -2577, -2577, -2577,  1054, -2577, -2577,  1496, -2577,    23,
    1420, -2577, -2577,    23, -2577, -2577, -2577,  1422,  1424,   777,
    1425,  1434,  1097, -2577, -2577, -2577, -2577, -2577, -2577, -2577,
   -2577, -2577, -2577,   777,  1185, -2577,   299,  1795, -2577,  1228,
     230, -2577,   136,  1275, -2577, -2577,  1072, -2577, -2577, -2577,
    1322, -2577, -2577, -2577, -2577, -2577, -2577, -2577,  1465,  4349,
    6391,  1474,  1475,  1480,   386,   -39,  1483,  4882,  1485,   -70,
    1035, -2577, -2577,   208,  1486, -2577, -2577, -2577,  5347,  1832,
    1863,  1490,  1491,  5388, -2577,  1492,  3406,  1494, -2577,  7189,
    7189,  7189,  5647,  7189,  5672,  5758,  5797,  5841,  4079,  5958,
    5988,  6209,  2437,  2567,  2765,  6182,  6246,  4433,  1103,  1103,
    1508,  6216,  6440,  4349,  4349,  1293,  4349,  4349,  1293,  6391,
   -2577, -2577, -2577,  1271, -2577, -2577, -2577, -2577,  1269, -2577,
    1870,  1871, -2577,  1874,  1323,  7189, -2577, -2577,  1281,  1881,
   -2577,  1429,  1280,  1676, -2577,  1514,   369, -2577,  1495, -2577,
   -2577,  1299,   913, -2577, -2577, -2577,  1499, -2577,   669,  7189,
   -2577, -2577, -2577,  7189,  -162,     7,  1883,  1377,  1886,  1887,
   -2577, -2577, -2577, -2577, -2577, -2577, -2577, -2577, -2577, -2577,
   -2577, -2577, -2577, -2577, -2577, -2577, -2577,  1504, -2577, -2577,
   -2577,   880,  1400,  6458, -2577, -2577, -2577,  1884,  7189,   492,
      63, -2577, -2577,  1629,  6391,  1560,  1926,  1569,   391, -2577,
    1570,   136, -2577,  6391,  1529, -2577, -2577,  1606, -2577,  7189,
     -26, -2577,  1372, -2577, -2577,   764, -2577,  7189, -2577, -2577,
    1353,    76, -2577,  1360, -2577,  1947,  4445, -2577, -2577,   256,
   -2577,  1676,  1676,  1325, -2577,  1442,  1449,   823,   823, -2577,
   -2577, -2577, -2577, -2577, -2577,   -68,    40, -2577,   979, -2577,
   -2577, -2577, -2577,   823,  1974,  1971,  1953, -2577,   136,  1754,
     103,  1530,  1903,     2,   167, -2577,    45, -2577, -2577, -2577,
    1574,    42,  1496,   189, -2577,  1387,  1401, -2577, -2577, -2577,
    7329, -2577,  1023, -2577, -2577, -2577, -2577,  1595,  1411,  2000,
   -2577,  1984, -2577, -2577, -2577, -2577,   880,   115, -2577, -2577,
   -2577,  1398,   640, -2577, -2577, -2577, -2577, -2577, -2577,   -53,
   -2577, -2577, -2577, -2577,  1612,  1613, -2577,  1587, -2577,  1588,
   -2577,  1619,   393, -2577,  7220,   397,  1496,  1496,   403, -2577,
    1496,  7220, -2577, -2577,  1869,  1869, -2577,  1620, -2577,  1621,
    1622, -2577,  1628,  1633, -2577,  1638, -2577, -2577, -2577,   141,
   -2577, -2577, -2577,   409, -2577, -2577,   419, -2577, -2577, -2577,
    1662,   314,  1705, -2577,  2028,   136,  7189, -2577,  2033, -2577,
   -2577, -2577, -2577,   777, -2577, -2577, -2577,  2043, -2577,  4349,
   -2577, -2577, -2577, -2577,  7329, -2577, -2577,  1746,  1746,  2024,
   -2577,  2025,  1487,   463, -2577,  1019,  1682,  1644, -2577, -2577,
   -2577, -2577, -2577, -2577, -2577, -2577,  1019, -2577, -2577, -2577,
    1684,  1019,  4349,  4349,  4349,  1019,  4349,  1019,  1019,  1019,
    7189,  1687,  7189,  1695, -2577,  1469,   777,   107, -2577,   136,
    7189,  7189,  7189,  6595,  2065,   960, -2577, -2577,   136, -2577,
    1472, -2577, -2577, -2577, -2577, -2577, -2577, -2577,  1186, -2577,
   -2577,   353, -2577,  1476,  7189, -2577, -2577, -2577,  2066, -2577,
   -2577, -2577, -2577, -2577, -2577,  1676, -2577, -2577, -2577, -2577,
   -2577, -2577, -2577, -2577, -2577, -2577,   880, -2577, -2577,  4228,
   -2577, -2577, -2577,  1769, -2577, -2577, -2577,  1758,  1759,  1640,
    1488,  1760,  1677, -2577, -2577,   -35,  1749, -2577, -2577, -2577,
   -2577,  1606, -2577, -2577, -2577,   102,   799, -2577, -2577, -2577,
    1805,  7189,  1685,  2070, -2577, -2577,    90,   118, -2577,   908,
   -2577, -2577,  1869, -2577, -2577,  7329,  1683, -2577, -2577,  1686,
   -2577, -2577,  1688,  1689,  1697,  1698,    44, -2577,  2089, -2577,
   -2577, -2577,  2305, -2577,  1709, -2577,   217,  1481, -2577,  2079,
       7, -2577, -2577,  2109, -2577,  2112,   990,   990,   990,   990,
    1504, -2577, -2577,  2114, -2577, -2577, -2577,  2115, -2577, -2577,
   -2577,   990,   180, -2577, -2577, -2577, -2577, -2577, -2577, -2577,
   -2577, -2577, -2577, -2577, -2577, -2577, -2577, -2577, -2577,   431,
   -2577,  2097, -2577, -2577,  1496, -2577, -2577, -2577, -2577, -2577,
   -2577, -2577,  1549,  1550,   575, -2577,    45, -2577,  1496,  1531,
   -2577,  7220, -2577, -2577,  1722, -2577, -2577, -2577, -2577, -2577,
    2124, -2577,  4251,  1571, -2577,  7189, -2577,  7189, -2577, -2577,
   -2577, -2577, -2577, -2577, -2577,  1496, -2577,  1496,   -44,  1533,
    1536,  2132, -2577,  2136, -2577,   880, -2577,   548,   548, -2577,
   -2577,  2137, -2577,  2137,   269,   269,  2137, -2577, -2577,  2646,
   -2577, -2577,  1988,    88, -2577,  2646,  1568, -2577,    88,  1496,
      23, -2577,  1734,  2695,  1734,  3427,   241,  2139, -2577, -2577,
   -2577, -2577, -2577, -2577, -2577,   922,   834, -2577,  -121,  1777,
    2145, -2577, -2577,   440, -2577,   777, -2577,   443,   262, -2577,
   -2577, -2577, -2577, -2577, -2577, -2577,  1558,  -116,  2129,  2129,
    2130,  2129,  2129,  2146, -2577,   144, -2577,    23, -2577, -2577,
     777, -2577, -2577, -2577,  1573,   136,  2162, -2577, -2577,   444,
   -2577,  6730,  1806,  1807,  7189,   194, -2577,  1575, -2577,  1809,
   -2577,  2149, -2577,  1607, -2577, -2577, -2577, -2577,  2157, -2577,
    1578, -2577, -2577,  1814,  1816,  1817, -2577,  1828, -2577, -2577,
   -2577,  4349,   450, -2577,   454, -2577,  1829,  2183,   456,   136,
    2199, -2577, -2577, -2577, -2577,  7189,  1660,  1954,  7189, -2577,
   -2577, -2577, -2577,  2191,  1843,   353,  1460,  1460,  2210,  -119,
   -2577,  2211, -2577, -2577, -2577,  1460, -2577,  1692,  2198,  2215,
   -2577,   -82,   880,  2006,   457, -2577,  1442,  7189, -2577,  1856,
    6391,   880, -2577,    53, -2577,   880, -2577,  1857,  6391, -2577,
   -2577,   -35,  1749, -2577,  1504, -2577, -2577,   132, -2577, -2577,
    1678, -2577, -2577,  1794, -2577,  6997, -2577, -2577, -2577, -2577,
   -2577,  1625,   947,   231,   -37,  1823,   -37,   -37,   -37,   -37,
    7329,  4445,  7329,  7329,  7329,  7329, -2577, -2577, -2577, -2577,
   -2577, -2577, -2577,   129, -2577, -2577,  1815,   698, -2577, -2577,
   -2577,  1634,   823,   990,   823,   990, -2577, -2577, -2577, -2577,
   -2577,   -68,   990,    40,   990, -2577,     7,  1974, -2577,  1866,
    1830,   -39,   968,  1530,  1530, -2577, -2577, -2577, -2577,   460,
   -2577,  1791, -2577,  2237,  1496,   -83, -2577,  1639, -2577,  7329,
    1714, -2577, -2577, -2577, -2577, -2577, -2577, -2577, -2577, -2577,
   -2577, -2577, -2577, -2577, -2577, -2577, -2577, -2577, -2577, -2577,
   -2577, -2577, -2577, -2577, -2577, -2577, -2577, -2577, -2577, -2577,
   -2577, -2577, -2577, -2577, -2577, -2577, -2577, -2577, -2577, -2577,
   -2577, -2577, -2577, -2577, -2577, -2577,   216, -2577, -2577,  1717,
   -2577,   462, -2577,  1647, -2577, -2577, -2577,  1984,   880, -2577,
    2137, -2577, -2577, -2577,   269,   269, -2577, -2577,   269,  2064,
    1652,  1656, -2577, -2577,    72,    72,    72,  2230,    72,    72,
      72,    72,    72,    72,  2234, -2577,  2241,    72, -2577, -2577,
   -2577, -2577, -2577, -2577, -2577, -2577,  1988, -2577,   880,  1668,
   -2577,  1836,  2064,  2247, -2577,  2248,  2254,  2258,  2261,  2263,
    2265,   174,  1568, -2577,  1836, -2577,   466, -2577,  1841, -2577,
   -2577,   334,   191, -2577, -2577,  7220, -2577,  7220, -2577, -2577,
   -2577, -2577, -2577, -2577, -2577, -2577, -2577, -2577,  7329,  1864,
   -2577,  1890,   559,   951,  2271, -2577,  2027,  1496,  1701,  1496,
   -2577, -2577, -2577, -2577,  2118,  2283,  2118, -2577,  2308,  2308,
     469,  1950,  2308, -2577,  1951, -2577, -2577, -2577,    23, -2577,
   -2577, -2577,   136, -2577,   777,  2080,  1805, -2577, -2577, -2577,
     122,  1813,   618,  1863,  1746,  1761,   938,  1960, -2577, -2577,
   -2577, -2577, -2577,  7189, -2577, -2577, -2577,  1885, -2577,   232,
     136, -2577,  2326,  1924, -2577, -2577,  1965, -2577, -2577, -2577,
    1808, -2577, -2577, -2577,  1460,    99,  2316, -2577,  1460, -2577,
   -2577,   823, -2577, -2577,  7189, -2577, -2577, -2577,   823,  1939,
    2334, -2577,  2125, -2577, -2577,     7,  4349,  2020, -2577, -2577,
     154,  1940, -2577, -2577,  6391, -2577,  1976, -2577, -2577, -2577,
     799, -2577,  1442, -2577,  7189, -2577,    99, -2577,  1632, -2577,
    2118, -2577,   380,  2344,  1980, -2577, -2577, -2577,  7329, -2577,
    7329,  7329,  7329,  7329,  2305,   470, -2577,   924,   924,  1845,
    1879, -2577,  7189,  1932, -2577,  2029, -2577,  2333, -2577, -2577,
   -2577, -2577, -2577, -2577, -2577, -2577, -2577, -2577, -2577, -2577,
   -2577,  7329, -2577, -2577, -2577,   968,  1496, -2577, -2577,  2236,
     486, -2577, -2577, -2577, -2577, -2577, -2577,   880, -2577,  2343,
    1496, -2577,  2352,  2345, -2577, -2577, -2577, -2577,  1496, -2577,
    1918,  1765, -2577, -2577, -2577, -2577, -2577, -2577, -2577,  2171,
    3252, -2577, -2577, -2577, -2577, -2577, -2577, -2577, -2577, -2577,
   -2577, -2577, -2577, -2577, -2577, -2577,   404,  2360, -2577,   880,
    1454, -2577,  2171, -2577, -2577, -2577, -2577, -2577, -2577, -2577,
   -2577, -2577, -2577, -2577, -2577,   -39, -2577,  2139, -2577,  2305,
     417, -2577,   417, -2577, -2577, -2577,  7329,   144,  1690, -2577,
   -2577, -2577,  1734, -2577, -2577, -2577,  2305,   274, -2577, -2577,
    2347, -2577, -2577, -2577, -2577, -2577, -2577, -2577, -2577, -2577,
    1998, -2577,  2346,  2004,  2012,  2358, -2577, -2577,  2015, -2577,
   -2577, -2577, -2577, -2577, -2577,   301,  2365, -2577, -2577,  2361,
    2041, -2577,  1792,   -37,  2083, -2577, -2577, -2577,  1224, -2577,
   -2577, -2577, -2577,  4349,   823,     7,  2044,   136, -2577,  7189,
   -2577,  1854,  2379,     7, -2577, -2577,   412, -2577, -2577, -2577,
   -2577,   185,  2039,  1676,   880,   880, -2577, -2577, -2577,   154,
   -2577,  2045,  1883,  2002, -2577,  2020, -2577, -2577, -2577, -2577,
    2194,   277, -2577,  1869,  1819,  1869, -2577,  1319,  7329,  1331,
    1852,  1917,  1949,  7329, -2577,  1865, -2577, -2577, -2577,  1442,
   -2577,   494, -2577,   169,   968,   968, -2577, -2577,   -39, -2577,
   -2577,  1496, -2577,  2011, -2577,  2334,  1896,  7036, -2577,   495,
     111,  1496,  7251,   880, -2577, -2577,   306, -2577, -2577, -2577,
   -2577, -2577, -2577, -2577, -2577, -2577, -2577,   880,  2360, -2577,
   -2577, -2577,   880, -2577,   880, -2577, -2577,  1898, -2577,  2207,
   -2577,  2208,  7329,   496, -2577, -2577, -2577,   498,  2792,  2007,
   -2577, -2577, -2577,  2405, -2577, -2577,  1994,  1831, -2577, -2577,
   -2577, -2577,  2067, -2577,   122, -2577,   122, -2577, -2577,  7329,
   -2577,  2008, -2577,  2080,  1305,   103, -2577, -2577, -2577, -2577,
   -2577,   136, -2577,  2068,  7551,  2026, -2577, -2577, -2577,  1846,
       7, -2577, -2577, -2577,    55,  1883, -2577, -2577,  2072, -2577,
    2020,   799, -2577, -2577,  1835,  2118,  1842, -2577,   499, -2577,
   -2577, -2577, -2577,  2305, -2577, -2577, -2577, -2577,  1896, -2577,
   -2577,  7329, -2577,  7319,   618,  6662, -2577,  2441, -2577, -2577,
    2305,  1496,  2447, -2577,  7220, -2577, -2577, -2577,  2334,  1918,
   -2577, -2577, -2577, -2577,   808,   808, -2577,   808, -2577,   808,
     808, -2577, -2577, -2577,   194,   206, -2577, -2577,  7329,   144,
   -2577,  2057, -2577,  2118, -2577, -2577,   500, -2577,  2461, -2577,
    2305,  7220, -2577, -2577, -2577, -2577,  2462, -2577,   413, -2577,
   -2577,  2080,    79, -2577, -2577,   227,   227,   227,   227,   227,
     227, -2577,  2444, -2577,   501, -2577,  7189,  2450, -2577, -2577,
   -2577,    85, -2577,  2020,  6391,  2020, -2577, -2577,  2253,  2118,
   -2577,  2118, -2577,   256,     7, -2577,   618,   194, -2577,   504,
   -2577,  2305, -2577,   506,   947,  7251, -2577,  2073, -2577,  2237,
   -2577, -2577, -2577,   808, -2577,   808, -2577, -2577,  2104, -2577,
    2305, -2577, -2577, -2577, -2577,   122, -2577,  7329,  2237,  1305,
   -2577, -2577, -2577, -2577, -2577, -2577, -2577,   878, -2577, -2577,
   -2577, -2577, -2577, -2577, -2577, -2577, -2577,  7551, -2577,  2472,
   -2577, -2577,   570, -2577, -2577, -2577, -2577, -2577, -2577, -2577,
   -2577,   217, -2577, -2577, -2577,  7319, -2577, -2577, -2577,  7251,
   -2577, -2577, -2577, -2577, -2577, -2577,  1090,  1090, -2577, -2577,
    1090, -2577,  7189, -2577,  2116, -2577, -2577,   509, -2577, -2577,
   -2577,  2117, -2577, -2577, -2577,   162, -2577,   154, -2577,  1883
};

/* YYPGOTO[NTERM-NUM].  */
static const short yypgoto[] =
{
   -2577, -2577, -2577, -2577, -2577,   326, -2577,   420,  -185, -2577,
   -2577,  -849,   204, -2577, -2577, -1528, -2577, -2577, -2577, -2577,
    -542, -2577, -2577, -2577, -2577, -2577, -2577, -2577, -2577, -2577,
   -2577, -2577, -2577, -2577, -2577, -2577, -1664, -2577, -1404, -2577,
     416, -2577, -2577, -2577, -2577, -2577, -2577, -2577,   652, -2577,
   -2577, -2577, -2577,  1258, -2577,   944, -2577, -2577,   -57, -2577,
   -2577,  2459, -2577,  2458,  2133, -2577, -2577, -2577, -2577, -2577,
     716,   363, -2577,   713, -2577, -2577, -2577, -2577, -2577, -2577,
   -2577, -2577, -2577, -2577, -2577,   -66,   370,   315, -2577, -2577,
    2216,   -34, -2577,  2363, -2577, -2577,  2362, -2577,  2297, -2577,
   -2577, -2577,  2233,  2119,  1188,  2235,  -312, -2577, -2577, -2577,
   -2577, -2577,  1202,  -965, -2577, -2577, -2577, -2577, -2577, -2577,
    -135,  2169,  2317,  -194,   784, -2577,  2163,    98, -2577,  2221,
   -2577, -2577, -2577, -2577,  2223, -2577, -2577, -2577, -2577,  -323,
   -2577, -2577, -2577, -2577, -2577, -2577, -2577, -2577,  2156, -2577,
    2155, -2577, -2577, -2577, -2577, -2577, -2577, -2577, -2577,  -891,
   -2577, -2577,  -476, -2577, -2577, -2577, -2577, -2577, -2577, -2577,
    2493, -2577, -2577,  1020, -2577,  -888,  -803,  1880, -2577, -2577,
   -2577, -2577, -2577, -2577, -2577, -2577, -2577,   782, -2577, -2577,
   -2577, -2577, -2577, -2577, -2577,  -488, -2577, -2577, -2577, -2577,
   -2577,  2023, -2577, -2577, -2577, -2577, -2577, -2577, -2577, -2577,
   -1698, -2577, -2577, -2577, -2577, -2577, -2577,  1151, -2577, -2577,
   -2577, -2577, -2577, -2577, -2577, -2577, -2577, -2577, -2577, -2577,
   -2577, -2577, -2577, -2577,  1597, -2577, -2577, -2577, -2577,   903,
   -2577, -2577, -2577, -2577, -2577, -1376, -2577, -2577,   904, -2577,
   -2577, -2577, -2577, -2577, -2577,  -788,  -630,   787,  1063, -2577,
    -485,   368,  -813,  1329, -2577,   771, -2577, -1807,    -2,  -351,
   -2577, -2577,   165,  1556, -1723,   -15,   986, -2577, -2577, -2577,
     675,  1306, -2577, -2577, -2577, -2577, -2577, -2577,   358, -2577,
      26, -2577,  1307, -2577,   996, -2577,   683, -2577, -2577, -2577,
    -469, -2577, -2577, -2577, -2577, -2577, -2577, -2577, -2577,   797,
   -2577, -1202, -2577,   991, -2577, -2577, -2577, -2577, -2577, -2577,
   -2577, -2577, -2577, -2577,   356, -2577,   351, -2577, -2577, -2577,
   -2577,  1440, -2577, -2577, -2577, -2577, -2577, -2577,  -136, -1465,
   -2577, -2577, -2577, -2577,   474, -2577, -1595, -2577,  -830, -2577,
   -2577, -2577, -2577, -2577, -2577, -2577, -2577, -2577, -2577, -2577,
   -2577, -2577, -2577, -2577,  2568, -2577, -2577, -2577,  2473,  2563,
    -956, -2577, -2577, -2577, -2577, -2577, -2577, -2577,   -18, -2577,
   -2577, -2577, -2577, -2577, -2577, -2577, -2577,  2578, -2577, -2577,
   -2577, -2577, -2577, -2577, -2577, -2577, -2577, -2577,  1053, -2577,
   -2577, -2577, -2577, -2577, -2577, -2577, -2577, -2577, -2577,  -414,
    2127, -2577, -2577, -2577, -2577, -2577,  1962, -2577, -2577, -2577,
   -2577, -2577, -2577, -2577, -2577, -2577,  2141, -2577, -2577,   -59,
   -2577, -2577,  1055, -2577, -2577,  1371,  -192,  2349, -2577, -2577,
   -2577, -2577,    52, -2577,  -705,  1941,  1354, -1671,   -94, -2577,
    1058,  1699,    17,  -158, -2577,  -947, -2577,  1497, -2577, -2577,
   -2577, -2577, -2577, -2577, -2577, -2577, -2577, -2577, -2577, -2577,
   -2577, -2577, -2577, -2577, -2577, -2577, -2577, -2577,  1438, -2577,
    1028, -2577,  -274, -2577, -2577, -2577, -2577, -2577, -2577,  -326,
   -2577, -2577, -2577, -2577, -2577, -2577,   455, -2577,  1515,   -20,
   -2577, -2577, -2577, -2577,   280, -2577,  -150, -2577, -2577, -2577,
   -2577, -2577, -2577, -2577, -2577, -2577, -2577, -2577, -2577, -2577,
   -2577, -2577,  1774, -2577, -2577, -2577, -2577, -2577, -2577, -2577,
    -319, -2577,  1443,  1601, -2577, -2577,   297, -2577,  -432, -2577,
   -2577,   318,   659, -2577, -2577, -2577, -2577, -2577, -2577, -2577,
     505, -2577, -2577, -2577, -2577, -2577, -2577, -2577, -2577, -2577,
   -2577, -2577, -2577, -2577, -2577, -2577, -2577, -2577, -2577, -2577,
   -2577, -2577, -2577, -2577, -2577, -2577, -2495, -2577,  1654,   905,
    -962, -2577, -2577, -2577, -2577,  1304, -2577, -1312, -2577, -2577,
   -2577, -1311, -2577, -2577, -1294, -2577, -2577, -2577, -2577,  1338,
   -2577, -2577, -2577, -2577, -2577, -2577, -2577, -2577, -2577, -2577,
   -2577, -2316,   -99, -2577, -2576, -2478, -2577,   732, -2577, -2577,
   -2577, -2577, -2577, -2577,  -365, -2577, -2577, -2577, -2577, -2577,
   -2577, -2577, -2577, -2577, -2577, -2577, -2577, -2577,  -327, -2577,
   -2577, -2577, -2577, -2577, -2577, -2577, -2577, -2577, -2577, -2577,
   -2577, -2577,   705, -2577, -2577, -2577,  -214, -2577, -2577, -2577,
   -2577, -2577, -2577,   290, -2577, -2577,   681, -2577,  1018, -2577,
   -2577, -2577, -2577,   275,  -966, -2577, -2577, -2577, -2577, -1355,
   -2577, -2577, -2577, -2577, -2577, -2577, -1897,    19, -2577, -1810,
     265, -2577, -2577, -1637,   323,   322,   685, -2577, -2577, -2577,
   -2577, -2577, -2577, -2577, -2577, -2577,    70,  -212, -2577, -2577,
     676, -2577, -1913, -2577, -2577, -2577, -2009, -2577, -2577,  -774,
   -2577,  -698,  1427,  -111, -1631, -2577, -2018, -2577, -2577, -2577,
   -2577,  1975,   278, -1621, -2082, -2577, -2577, -2577, -2577, -2577,
   -2577, -2577, -1947, -2577,   400, -2577, -1027, -2577,  1762, -2577,
   -2577,  -653,  -118, -2577, -2533,  -128,   -32,   477, -1939, -1373,
   -1696,   465,  -283,  -354, -2577,   -13,  -193, -2577, -2577,  1450,
    -478, -2577, -2577,  -149,  1779, -2577,   672, -2577, -2577, -1235,
     166, -2577, -2577, -2577, -2577, -2577,  -412,  -406,  -428,  1030,
   -2140,     4,  1991,    96, -2577, -2577, -2577, -2577, -2577,  1585,
   -2577,  -459, -2577, -2577, -2577, -2577, -2577, -2577, -2577, -2577,
    -659,  1024,  2371, -2577, -2577, -2577, -2577
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1791
static const short yytable[] =
{
      40,   268,   258,  1023,    32,   386,  1020,   112,  1191,  1173,
      55,    57,   816,   713,  1332,  1164,   693,  1790,   284,   825,
    1342,  1160,  1724,   131,  1005,   859,    97,    32,  2075,   865,
    2078,  1364,  1259,    68,  2038,  2032,  2034,  2416,  2166,  2034,
     256,    74,    77,   874,   416,  1764,  1269,  1170,  1171,  1694,
    1172,  1695,  1175,  1176,  2047,  1669,   862,  1616,  1575,  1576,
     112,   140,  1204,  2132,  1377,   798,  1930,   682,   126,  1196,
    1196,  1477,   931,  2369,   128,  2373,   666,    77,   701,   338,
    1215,  1943,  1123,   916,  1128,  1129,   919,   236,  1821,   137,
     291,  1489,   823,   791,  1264,   269,   144,   709,   693,  1190,
     181,   774,   150,   151,   774,  2226,   910,    97,   154,   155,
     269,   201,  1117,   269,   783,  2176,   184,   185,   774,  1197,
    1985,   126,   774,  -610,   186,  1198,  2165,   872,  -610,   800,
    1824,   872,  1387,  1490,   774,  1491,   783,  1492,  1279,  1833,
    1281,   269,   811,  2178,  2120,   783,  1018,   232,   394,   866,
     235,  -610,   822,   688,  1140,   239,  2501,   826,  -610,  1336,
     872,  1856,  1857,    81,  1236,   864,  1275,   269,  2415,  1860,
    1950,   299,   300,   266,  2249,   129,   811,   269,   922,   923,
     811,   275,   379,  1454,   811,  1196,   269,   276,   277,   783,
    1196,   866,   783,   292,   273,   269,   270,   271,  2620,  2249,
    2378,  2348,  2379,  2380,  2381,  2382,  2383,  2384,  2192,  2193,
    2194,  2195,  1251,    72,   381,     1,  1182,  1183,   266,  1260,
     269,   922,   923,  1856,  1857,   102,  1731,   389,   266,   269,
    1859,  1860,   296,  1732,   827,   266,  2569,  2696,   302,  2893,
    1018,  2181,   398,  1489,   400,   719,   344,  2375,   346,   330,
    1997,  1947,  1165,    97,  2768,  1018,   404,   139,  2204,  1285,
     932,  1007,  2196,  2197,  2198,  2199,  2200,  2201,  2375,  1993,
     103,   104,  1996,  2520,  2521,  2522,  2523,  1546,   105,  2813,
     932,   383,   266, -1789,  1015,  2552,  2477,     3,     4,  1150,
       5,     6,  1840,  2405,  2897,     7,   139, -1789,  1337,  1617,
    1728,  2515,   392,  3076, -1789,  2220,  1552,   556,   645,  2983,
    1147,  2899,     8,     9,  2243,  1330,  2394,  2240,  2465,   392,
    1153,  1601,  1602,  1790,  2661,  1018,  1804,  2054,  1188,  1580,
      10,    11,    61, -1789,   986,   987,  1372,   654,  2934,  2485,
    2375,    56,   932,  1955,  2302,   303,  3033,   932,  1013,  1901,
     933,  2982,  1264,  1580,   408,  1527,   648,   408,  2136,  1580,
    1902,    63,   988,   989,   990,   408,    69,  2558,   637,   647,
      17,   655,   304,  1624,  1338,  2562,  2371,  1373,  2032,   649,
    1189,   330,    33,   330,  1625,  2733,   259,   260,   261,   262,
     263,  1196,  1154,    17,  1252,   934,  1196,  1014,  2010,    61,
    2664,  1364,  2010,  2668,  1415,  3014,  1626,  1644,  2035,  3015,
     408,   413,  1228,  1627,  2058,   681,  1618,   684,  2516,   652,
     690,   695,  2385,   697,  2060,  2900,   700,    34,  2732,   259,
     260,   261,   262,   263,  1856,  1857,  2227,   706,   778,  1956,
     269,  1859,  1860,  3043,   768,  2399,  3013,  1384,  2399,  2424,
    2631,   787,  2633,  2190,  2645,  2443,   706,  1905,  1496,  2443,
    1636,  2424,  2483,  1584,   679,  2556,   768,  2578,  1906,   706,
      76,  2397,  1148,  3067,  2665,  2743,  1265,   864, -1562,   801,
    2466,  1008,  1265,    79,   815,  3077,  2082,  1584,  2083,  2406,
    2806,  2761,  2806,  1584,  1340,   817,   819,  1553,  1729,  2876,
    2891,  2915,   690,  2915,  2743,  3005,  3027,  3048,   187,  3045,
     768,  2985,   817,   817,  2985,  1003,  1232,    82,  1862,  2055,
     768,   768, -1789,   894,   768,  1619,    77,  2517,   768,  1296,
     768,  1549,   106,  1863,   768,   768,    72,   911,   384,   911,
     817,  2386,   911,   817,  1388,   911,  1951,   380,  1391,  1392,
    1393,  1645,  2513,  1935,   935,  1210,  2478,  1213,   107,  1519,
     924,  2511,   259,   260,   261,   262,   263,  1411,   729,  2499,
    1646,  1647, -1789,   267,   935,  2986,  1944,  1394,  1369,   382,
    1862,  2349,  1199,   683,  2697,   683,   683,  1610,  1611,  2137,
    1648,  2238,   390,   733,  1253,  1863,  1621,  1371,  2389,   683,
     864,   826,   864,   693,  1806,  2512,   934,   399,  2756,   401,
    2310,  2376,  2805,  2561,  2805,  2894,  2675,   683,   341,  2810,
     683,   405,  1603,  1130,   900,  2570,   683,  1254,   668,   108,
     683,  1889,  2403,   792,   683,  1703,   935,   974,   683,  1661,
    1986,   935,   683,   683,    82,   683,   960,  1327,   683,  1016,
     683,   683,   683,  1458,    82,   936,   937,   938,   683,  1328,
      82,   683,  2109,   925,   816,  1472,   939,    82,   683,  1850,
    1200,   272,  1216,   683,   981, -1789,   408,   742,  1280,  2814,
    1331,   683,  2863,  1493,  1141,  1473,   272,   690,    82,   272,
      82,  1494,   683,    82,    82,  2728,   683,  1478,    82,  2547,
     683,  2567,  1019,  2812,  2626,   683,  1202,  1166,   683,  1889,
    2824,  1524,   768,   768,  2702,  1453,    82,   272,  1459,  2430,
     689,   693,   109,    82,  2248,  2039,  2387,    82,   768, -1789,
      82,    82,   991,    82,   768,   768,  2687,  1537,  2205,   768,
    2704,  2401,  1540,   272,  2709,    82,  2488,  2419,  2420,   768,
      82,  2070,  1557,   272,  2496,  1377,  1723,    81,    82,  -610,
    1167,  1828,   272,  2011,  1538,    82,  2649,  2027,  2651,   747,
    2835,   272,  2390,  2036,  1780,  2806,  1733, -1789,  1019,  2059,
     141,   749,   750,  2970,  1532,    95,  1552,  2634,    82,  2061,
     752,  1862,  1761,  2391,  1521,  1763,   272,   689,  1571,  1572,
     940,  2228,  1287,   110,  2070,   272,  1863,  2879,  2880,  1972,
    2400,   111,  2040,  2402,  2425,  1336,  1370,  2849,    82,   992,
    2444, -1789,   768,   768,  2445,   130,  2448,  2484,  2889,  2041,
    2557, -1789,  2579,  2889,     3,     4,  2624,     5,     6,  2666,
    2744,  3004,     7,  2378, -1789,  2379,  2380,  2381,  2382,  2383,
    2384,  2192,  2193,  2194,  2195,  2753,  2762,   768,  2551,     8,
       9,   136,   993,   768,  2877,  2892,  2916,  2370,  2917,  2972,
    3006,  3028,  2042, -1789,  3046,   768,  3047,    10,    11,  3073,
     768, -1789, -1789, -1789, -1789, -1789,  1226,  3039,   132,  3040,
    1623,  2734, -1789, -1789,  1704,   899,  2765,  2805,  1714,   903,
     141,  2810,   813,   907,  1243,  2196,  2197,  2198,  2199,  2200,
    2201,  2043, -1789,  -610,  1954,   337,  1333,  2237,   768,  1335,
   -1789,  2784,   143,  2460,  2635,  2757,  2636,  2925,  2681,  2927,
    3010,  2378,   768,  2379,  2380,  2381,  2382,  2383,  2384,   949,
    2044,   145,  2875,  2194,  2195,  1119,  2889,  2774,    12,  2045,
     950,    42,  1133,   193,  1337,  1230,  2884,  1760,   194,  1134,
    1762,  2689,  1476,  2690,  2192,  2193,  2194,  2195,  1856,  1857,
    2785,  1858,   133,   134,   269,  1859,  1860,  1553, -1789,  3011,
    2119,  2145,   133,   134,  1018,  1344, -1789,   195, -1789,  1352,
    1361,  1352,   198,   683,  1861,  2196,  2197,  2198,  2199,  2200,
    2201,  1347,   951, -1789,   690,    33,    34,   690,   689,  1376,
    1379, -1789, -1789,   697,  1348, -1789,   272,   952,  2196,  2197,
    2198,  2199,  2200,  2201,   233,  1293, -1789,   817,   768,  1347,
    1338,   817,   817,   817,   817,  1805,   768,   402,   241,   768,
   -1789,  2210,  1348,  2319,  2367,  1522,  2889,  1179,   234,  2352,
     817,   249,   768,  1400,  1186,  1783,   768,   250,  1401,  1784,
    1403,  2859,   253,  1832,   768,  2385,   768,   768,  2976,   768,
     768,   768,   768,   768,   768,   768,   768,   768,   768,   768,
     768,   768,   768,   768,   768,   768,   133,   134,  1339,   814,
    2724,  2418,  1892,  1894,  2637,  3058,   768,   768,  1364,   955,
     956,   768,  2898,   768,  2998,  1847,  2914,   953,  3053,   254,
    2889,  2682,  2864,  1455,  2866,  1455,   683,   683,   683,   252,
    1933,  2683,  1085,  1086,  1087,   690,   257,   776,   285,    43,
    2882,   768,   768,   768,  1912,   265,  1795,  2242,   286,  1672,
   -1789,   785,   817,    44,  1475,   790,  1479,   817,  1609,    15,
    1340,   768,  1580,  2385,  1613,     3,     4,   804,     5,     6,
    1624,  2300,  1785,     7,   288,  1786, -1789,  3044,    45, -1789,
   -1789,  1625,  1398,  1399,  1088,  1089,  1090,  1091,  1092,  1093,
       8,     9,   274,  2426,  2386,  2977,   279,  1580,   768,   289,
    1094,  1095,  1096,  1626,   817,   815,  2966,   290,    10,    11,
    1627,  1561,   134,  2939,  3014,   294,  2553,  2554,  3015,   295,
    1820,  1347,  1882,   768,  1349,   648,   915,    46,  1535,   918,
     817,   817,   921, -1789,  1348,   817,  2071,  2066,  1577,  1544,
     768,  1578,  1350,  1579,  1631,  1632,  2230,   962,   649, -1789,
     768,  2389, -1789,   306, -1789, -1789, -1789,  2837,  1351,  2838,
     826,   315,  2802,  1580,   911,   817,   817,  2989,   806,  1652,
    1350,  1639,  1640,  1581, -1789,   297,  1962,   812,  1658,    12,
     301,   864,  2386,   883, -1789,  2409,  1351,  2411,  2412,  2303,
    1605,   324,  1909,  1019,  1019,   325,  1584,   331,  1614,  2110,
    1614,  2111,  1019, -1789,  3008,   334,   974,  1796,  1797,  3035,
    2122,  3037,  1644,  2295,   335,  1582,   336, -1789,  1701,  1583,
     340,   914,   884,   342,   917,   343, -1789,  2511,  1180,  1181,
   -1789,  1584,  1184,  1185,    82,  1862,   936,   937,  1783,  1018,
    2935,  1097,  1784,   347,  1098,  1019,  2192,  2193,  2194,  2195,
    1863,   348,   351,  1964,  1024,  1025,  1026,  1352,  2192,  2193,
    2194,  2195,  1965,   352,   353,   354,  2133,  1864,  1361,   357,
    2638,  1352,   885,   358, -1789, -1789,   368,  2175,   369,  2387,
    1962,   372,  2508,  1866,   377,  1673,  1966,  2546,  2939,  1967,
    1710,  1711,  1712,   388,   391,  2881,   387,  1584,   768,  2959,
    2196,  2197,  2198,  2199,  2200,  2201,  1363,  1968, -1789,   395,
     886,   396,  2196,  2197,  2198,  2199,  2200,  2201,   397,   403,
     406,  1563,  1500,  -951,  1868,  2390, -1789,   768,   768,   768,
   -1789,   768,  1400,   414,   658,   653,  1869,  1401,  1402,  1403,
     710,   710,   660,  1674,   661,  1785,  2391,   662,  1786,  1585,
     667,   669,  1350,   671,   672,  1675,  1645,   768,   673,  1765,
   -1789,   675,  2418,  1099,   676,  1676,   677,  2387,  1351,   680,
    1580,   678,  2672,   768, -1303,  1646,  1647,  1870,  1100,   815,
      15,    82,  1101,  1677,   964,   965,   966,  3019,   967,   968,
     970,  1793,   969,  1678,   971,  1648,  1679,   768,   972,  1800,
    1801,   768,   817,   973,  2789,   977,  2959,   887, -1789,  1680,
    2639,   978,   979,  1969,   980,   984,  1871,  1006,   688,  1008,
    1102,  2182,  1009,  -265,  1011,  2640,  2641,  1012,  1872,  1017,
    1018,   768,  1021,  1030,   710,  1029,   768,  1120,  1086,  1087,
    1873,  1874,   768,  1032,   926,  1033,  1034,  1830,  1103,  1875,
    2084,   768,   689,  1127,  1132,  1035,  1036,   768,  1681,  1037,
     272,  1038,  3019,  1039,  1040,   768,  1970,  1104,  1041,  1052,
    3036,  1053,  1243,  1971,  1876,   727,  2790,  1205,  1206,  1207,
    1208,   307,  1054,   888,  1057,   817,   817,   728,  1682,  1088,
    1089,  1090,  1091,  1092,  1093,  1058,  1061,  2421,  1683,  1063,
    1064,   817,  1065,   826,  1584,  1094,  1095,  1096,  1066,   864,
    -265,  1067, -1789,  1135,  1068,  1069, -1789,  1071,  1684,  1136,
    1019,  1685,  1131,  1686,   889,  1138,  1139,  -265,  1876,  1146,
    1143,  1144,  1586,   864,  1163,  1158,  2783,  1177,  1187,  1980,
   -1789,  2449,  2791, -1789,  2792,  1149,  2718,  1190,  1105,  1211,
    1219,  1687,  1992,  1992,  1220,  1221,  1992,  1222,  1223,  2793,
    1688,  1224,   683,  2717,  1227,  1229,  1231,  2794,   308,  2372,
    -265,  2795,  1876,  1240,  2028,  2028,  1242,  1577,  2028,  1876,
    1578,  1501,  1579,  1255,  1232,   309,  1256,  1502,  1503,  1504,
    1257,  1196,   890,  1258,  1263,  1267,  2796,  1270,  1271,  2867,
    1272,  1273,  1580,  1343,   926,  2062,  1318,  1505,  1326,  -265,
    1376,  2869,  1581,  1329,   768,  1106,  2353,  1856,  1857, -1789,
    1858,  1352, -1789,   269,  1859,  1860,  1346,  1366,   310,  1360,
    1367,   744,  1876,  2354,  2355,  1375,  1384,  2538,  -265,  2540,
    1382,  2356,  2679,  1861, -1789,  1385,  1097,  -265,  1383,  1098,
    1412,  1118,  1386,  1395,  1582,   891,  1409,  1417,  1583,  1445,
     687,  1410,  1451,  1448,  1452,   316,  1465,   311,   768,  1471,
     768,  1202,  1485,   705,  1352,  2357,   683,  1487,   768,   768,
     768,   768,  1498,  2028,  2358,  1499,  1483,  1523,  1525,  2124,
    1793,  1526,  1528,  2129,  2129,  2722,   312,   683,  1530,   746,
     779,  1536,   768,  1539,  1549,   313,  1556,  2531,   748,  1541,
    1558,  1564,  2141,  2359,  1265,  1506,   796,   797,  1507,  1595,
    1489,  1566,   803,  1596,  1593,   805,  1598,  1604,  1653,  1699,
      82,   259,   260,   261,   262,   263,  1584,  1702,  1697,  1664,
    1705,  1666,  1508,  1667,  1670,  1715,  2524,  1882,  2527,  2528,
    2529,  2530,   317,  1671,  1720,  1721,  2840,  1706,  2360,   768,
    1722,  2173,  1509,  1725,  2848,  1727,  1734,  1736,  1099,   318,
    1745,  1746,  1748,  1876,  1751,  2195,   139,  1767, -1789,  2192,
    2193,  2194,  2195,  1100,  1769,  1770,  1771,  1101,  1585,  1772,
    1775,  1773,   826,   826,  1779,  1778,  1776,  1510,  1264,  2211,
    2361,  1777,  2592,  2593,  2594,  1962,  2596,  2597,  2598,  2599,
    2600,  2601,   319,  1782,  1781,  2604,  1511,  1512,  1794,  1807,
     926,  1809,  1810,  1811,  1815,  1102,  2196,  2197,  2198,  2199,
    2200,  2201,  1513,  2196,  2197,  2198,  2199,  2200,  2201,  1818,
    1825,  1826,  1019, -1789,  2192,  2193,  2194,  2195,  1834,  1827,
    1831,   320,   645,  1103,  2671,  1837,  2028,  1843,   645,  1876,
    2196,  2197,  2198,  2199,  2200,  2201,  2246,  1614,  1851,  1853,
    1855,  1514,  1104,   768,   939,   768,  2192,  2193,  2194,  2195,
     321,  1889,  2698,  2028,  1891,  1019,  1931,  2679,  1932,   322,
    1293,  1934,  1942,  1948,  1992,  1324,  1958,     1,  2196,  2197,
    2198,  2199,  2200,  2201,  1515,    48,    49,    50,    51,    52,
      53,  2958,    54,   647,  1975,  1978,  1959,  2028,  1979,   647,
    2790,  1876,  2711,  1876,  2855,  1977,  1989,  2000,  2001,  2713,
    2196,  2197,  2198,  2199,  2200,  2201,  2002,  2006,  2009,  2048,
    2049,  2050,  2063,  1352,  2629,  2185,  2065,  2051,  2068,  2646,
    2322,  2323,  2052,  1105,  2324,  2325,  2326,  2053,  2074,  2079,
    2080,  1913,  2087,  2088,  2091,  2081,  1361,  2103,  1352,     3,
       4,  1586,     5,     6,  1862,  2105,  1710,     7,  2107,   768,
    2118,  2123,   768,  2148,  2140,  2138,  2791,  2153,  2792,  1863,
    2988,  2151,  2152,  2155,     8,     9,  2156,  2154, -1789,  2171,
    2172,  1043,  2183,  2793,  2191,  2184,  1864,  2186,  2187,  1865,
    2231,  2794,    10,    11,  2209,  2795,  2188,  2189,  2203,   683,
    1106,   938,  1866,   768,  2212,   683,   768,  2214,  1282,  2221,
    2223,  2458,  2229,  2233,  2234,  3042,  2679,  2241,  2679,  2249,
    2796,  2244,  2305,  2296,  1793,  2306,  2473,  2307,  2475,   683,
    2370,  2308,  2313,  2368,  2327,   768,  2377,  2396,   768,   926,
    2397,  2328,  2492,  1868,  2407,  2410,   768,  3020,  3021,  3022,
    3023,  3024,  3025,  2404,  2737,  1869,  2739,  2740,  2741,  2742,
    2422,  2413, -1735,   768,  2435,  2436,  2427,  2428,  1044,  2434,
    2433,  2028,  2437,  2438,  2439,  2329,  2440,  2441,  1876,  1876,
    1876,  1876,  1876,  1876,  2330,  1045,  2398,  1962,  2442,  2446,
      89,   690,   710,  2447,  2450,  2452,  1870,  2453,  1737,  2839,
     817,  2457,   817,  2459,  2039,  2463,  2467,  2471,  2472,  2842,
    2474,  1283,  2870,  2331,  2332, -1789,  2487,  2495,  2504,  1284,
    2510,  2506,  2519,  2537,  2534,  1285,  2548,  1286,  1046,  2549,
    2086,  2558,  2028,  2375,  2565,  1871,  2567,  1876,  1287,  2576,
     926,  2089,  2580, -1789,  2595,  2590,  2092,  1872,  2602,  2591,
    2096,  2610,  2098,  2099,  2100,  2603,  2609,  2782,  2333,  1873,
    1874,  2613,  2614,  2630,   182,   190,  1288,  1047,  1875,  2615,
    2706,   689,  2808,  2616,  2182,  1914,  2617,  2871,  2618,   272,
    2619,  2370,  1289,    13,  2028,  1738,  2647,  1290,  1915,  2632,
    2650,  2040,  1337,  2581,  2582,  1980,  1048,  2679,  2660,  1291,
    2334,  2585,  1739,  2662,  2731,  1049,  1292,  1951,  2041,  2872,
    2667,  2669,  2192,  2193,  2194,  2195,   754,  2673,   190,  2688,
    2691,  2699,  2694,  2700,   190,  2701,  2707,  2702,  2714,  2715,
    1634,  1635,    14,  2719,  2716,  2723,  2726,  1651,   784,  2735,
    2736, -1789,   933,  2749,  2759,  1740,  2767,  2771,  2772,  2775,
    2780,  2042,  1916,  2943,  2779,  2787,  2335,  2815,  2817,  1917,
    2826,  2818,  3079,  1876,  2820,  1876,  2196,  2197,  2198,  2199,
    2200,  2201,  2821,  2822,  2524,  2823,  1876,  -610,  2829,  2873,
    2834,  1876,   856,  2836,  1741,  2028,  2841,  2028,   683,   683,
    2043,  2845,   875,   881,  2847,   190,   898,   190,  1918,  2851,
     902,  2857,   904,  2890, -1789,  2856,   908,   909,  2890,  2874,
    2883,  2430,  1352,  1742,  2865,  2912,  2913,  2919,  1019,  2044,
    2921,  2394,  1743,  1919,  2931,  2956,  2923,  2924,  2045,  2944,
    2969,   768,  2965,  1920,  1921,  2957,  2985,  2971,  1962,  1078,
    1079,  1080,  1081,  1082,  1083,  1084,  1085,  1086,  1087,  1922,
    2987,  2129,  3003,  2652,  2708,  2129,  3007,  3009,  3026,   817,
    3030,  1293,   768,  3038,  3052,  2930,   817,  3062,  1294,  2491,
    1923,   190,  3049,  1924,  1925,  3061,  3072,  3074,  2423,  1926,
    2429,  1548,   768,  2163,  1842,    70,    71,   557,  2125,  2470,
    1295,  2134,   768,   349,   197,  1296,   281,   202,  1088,  1089,
    1090,  1091,  1092,  1093,   345,   670,  1876,  1655,  1876,  1876,
    1876,  1876,   407,   350,  1094,  1095,  1096,  1962,   283,  2981,
     768,  2984,  1656,  2090,   657,  2625,  2692,   376,   374,   663,
     664,  3059,   864,  1817,  2104,  1990,  1927,  2750,   893,  1876,
    2653,  1730,  1877,  1998,  2028,  1322,  1802,  1823,  1928,  2114,
    1368,  2748,  1570,  2246,  3000,  2536,  1574,  2654,  2028,  1888,
    2208,   703,  3065,  2121,  2544,  2850,  2028,  2542,  1605,  1910,
    1079,  1080,  1081,  1082,  1083,  1084,  1085,  1086,  1087,  1480,
     156,    65,    66,  1886,  2800,  2336,  2337,  2338,  2339,  2340,
    2341,  2342,  2343,  2344,  2345,   781,  1877,    67,  1849,   802,
    2655,   786,   963,   788,  1562,   339,  1852,   795,  1592,   983,
     795,  2853,  1854,   795,  1261,  1518,  2788,   385,   690,  2903,
     690,  2890,  1945,   807,  1876,  3034,  1876,  1467,  1088,  1089,
    1090,  1091,  1092,  1093,  2623,  1457,  2526,  2911,  2816,  2656,
    1877,  1214,   854,  2930,  1094,  1095,  1096,  1877,  1531,  2622,
     867,   870,   873,  1418,  2605,  1097,   895,  2365,  1098,  1381,
    1698,  2108,  2896,  1019,   905,     1,  2235,  2827,  2657,  2832,
    3066,  1665,  3055,  2304,  2738,  2990,  2648,  2658,  2037,   928,
    2366,  2981,   817,  2670,  2825,  2890,  2680,   768,  2627,  2628,
    2374,  2388,  2807,  2999,   856,  2922,  1051,  2583,  2941,  1608,
    1877,  2686,  1856,  1857,  2566,  1858,  1311,  2940,   269,  1859,
    1860,  2878,  2564,  2758,  3054,  2868,  3002,  2975,  1600,  1278,
    1474,  2764,  2064,   415,     0,     0,  1876,     0,  1861,  1195,
       0,  1876,     0,     0,     0,   856,     0,     3,     4,     0,
       5,     6,     0,     0,     0,     7,     0,   875,     0,  2028,
       0,     0,  1218,     0,     0,  1876,     0,     0,     0,  2028,
    1876,     0,     8,     9,     0,     0,     0,  2902,     0,  1080,
    1081,  1082,  1083,  1084,  1085,  1086,  1087,  1099,     0,     0,
      10,    11,     0,     0,     0,  1097,     0,     0,  1098,  2918,
    1876,     0,  1100,     0,     0,     0,  1101,     0,     0,  2192,
    2193,  2194,  2195,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1019,     0,  1019,     0,     0,  1876,     0,     0,
       0,     0,  2028,     0,  2832,     0,  1088,  1089,  1090,  1091,
    1092,  1093,  2177,  2179,  1102,     0,     0,     0,     0,   928,
       0,  1877,  1094,  1095,  1096,     0,     0,     0,     0,  2159,
    2160,   158,     0,  2196,  2197,  2198,  2199,  2200,  2201,     0,
    2169,     0,  1103,     0,  2750,     0,     0,     0,     0,  1876,
       0,  1876,     0,  1876,     0,     0,     0,     0,     0,  2028,
       0,  1104,  1876,     0,     0,     0,     0,  1605,     0,     0,
     159,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   690,     0,     0,  1876,  1099,  1121,   160,
    2216,  2217,  2218,  2219,     0,     0,     0,     0,     0,  1876,
       0,     0,  1100,     0,     0,  2225,  1101,  1877,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   768,  3031,     0,     0,   161,     0,
       0,  1152,   768,     0,     0,     0,     0,     0,  2012,     0,
     162,     0,  1105,     0,  1102,  1169,  1169,  1169,     0,  1169,
     163,  1169,  1169,  1876,     0,     0,     0,    89,    89,     0,
       0,     0,     0,  1097,     0,     0,  1098,     0,   164,  1877,
       0,  1877,  1103,  1019,     0,  1876,     0,  2028,   165,     0,
       0,  2311,  2312,  1460,  1461,  1462,     0,     0,  2316,  2317,
       0,  1104,     0,     0,   166,     0,     0,     0,     0,     0,
       0,   873,     0,  1484,     0,     0,     0,     0,     0,  1106,
       0,  1877,  1238,  1876,     0,     0,     0,  1876,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   683,     0,
     768,     0,     0,     0,   167,   928,  1121,     0,     0,  1862,
    1520,     0,     0,     0,  1268,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1863,     0,     0,     0,   168,     0,
    1276,  1276,     0,     0,     0,   875,     0,     0,     0,     0,
       0,  1864,  1105,   169,  2013,     0,     0,     0,     0,     0,
     170,     0,  1545,   171,     0,  1099,  2014,  1866,     0,     0,
       0,     0,  1560,     0,     0,     0,     0,     0,     0,     0,
    1100,     0,     0,   172,  1101,     0,   173,     0,   174,     0,
       0,     0,     0,     0,     0,  2370,     0,     0,     0,   190,
    2461,  2462,     0,     0,     0,     0,     0,   175,  1868,  2469,
       0,     0,     0,     0,     0,     0,     0,  2482,     0,  1106,
    1869,     0,  1102,     0,     0,   176,  1877,  1877,  1877,  1877,
    1877,  1877,     0,     0,     0,  2497,  2498,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1103,     0,     0,     0,     0,     0,     0,  1027,  1028,     0,
       0,  1870,     0,     0,     0,     0,     0,     0,     0,  1104,
       0,     0,     0,  1042,     0,     0,     0,     0,     0,  1055,
    1056,     0,     0,     0,  1060,  1877,     0,  2539,     0,  2541,
       0,     0,     0,     0,  1070,     0,  2543,     0,  2545,     0,
    1871,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1450,  1872,     0,     0,     0,     0,     0,     0,    89,
       0,    89,   873,   795,  1873,  1874,  2015,     0,     0,     0,
    1466,   807,     0,  1875,   873,     0,   689,     0,   190,     0,
       0,  1481,     0,     0,   272,     0,     0,     0,     0,     0,
    1105,     0,     0,     0,   928,     0,     0,     0,     0,     0,
     710,   710,   710,     0,   710,   710,   710,   710,   710,   710,
       0,     0,     0,   710,     0,     0,     0,     0,     0,     0,
      89,     0,     0,     0,     0,     0,     0,     0,  2586,  2587,
       0,     0,  2588,  2589,     0,  1774,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     1,
       0,  1877,     0,  1877,     0,     0,     0,  1106,     0,  1799,
    1542,     0,     0,  1462,  1877,     0,  2612,     0,     0,  1877,
       0,     0,     0,     0,     2,     0,     0,     0,     0,     0,
       0,     0,     0,  1568,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1195,  1591,   928,     0,     0,     0,     0,
       0,  1749,  1072,  1073,  1074,  1075,  1076,  1077,  1078,  1079,
    1080,  1081,  1082,  1083,  1084,  1085,  1086,  1087,     0,  1839,
       0,     3,     4,     0,     5,     6,     0,     0,     0,     7,
       0,     0,     0,     0,  1856,  1857,     0,  1858,     0,     0,
     269,  1859,  1860,     0,     0,     0,     8,     9,     0,  1638,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1861,     0,     0,     0,    10,    11,   926,  1088,  1089,  1090,
    1091,  1092,  1093,     0,     0,     0,     0,     0,  2705,     0,
       0,   158,  2710,  1094,  1095,  1096,     0,     0,     0,     0,
       0,     0,     0,     0,  1877,     0,  1877,  1877,  1877,  1877,
       0,     0,     0,   873,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1389,  2727,     0,     0,     0,     0,     0,
     159,  1397,     0,     0,  1408,     0,     0,  1877,     0,     0,
       0,     0,     0,     0,     0,    12,     0,  1413,     0,   160,
       0,  1416,     0,     0,     0,     0,     0,  2746,     0,  1422,
       0,  1424,  1425,     0,  1426,  1427,  1428,  1429,  1430,  1431,
    1432,  1433,  1434,  1435,  1436,  1437,  1438,  1439,  1440,  1441,
    1442,     0,     0,     0,     0,     0,  2067,     0,   161,     0,
       0,  1443,  1444,     0,     0,     0,  1446,     0,  1447,     0,
     162,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     163,     0,     0,     0,     0,     0,  1877,     0,  1877,     0,
       0,     0,  1877,  1877,  1877,     0,     0,     0,   164,     0,
       0,     0,     0,     0,  1097,     0,     0,  1098,   165,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    2112,  2113,  1462,  2116,   166,     0,     0,     0,     0,     0,
       0,     0,  1814,     0,     0,    13,     0,     0,     0,     0,
       0,  1822,     0,     0,  2139,     0,     0,     0,     0,     0,
       0,     0,   873,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   167,     0,     0,     0,     0,     0,
    2012,     0,   182,     0,     0,   926,     0,     0,     0,     0,
       0,     0,     0,     0,    14,     0,     0,     0,   168,     0,
       0,     0,     0,     0,  1877,     0,     0,     0,     0,  1877,
       0,  2170,     0,   169,     0,     0,     0,     0,     0,   873,
     170,   873,     0,   171,     0,   867,    15,     0,     0,     0,
       0,     0,     0,  1877,  2862,     0,  1099,     0,  1877,     0,
       0,     0,     0,   172,     0,     0,   173,     0,   174,     0,
       0,  1100,     0,     0,     0,  1101,     0,  1984,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   175,  1877,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1862,     0,     0,     0,   176,     0,     0,     0,     0,
       0,     0,     0,  1102,     0,  1877,  1863,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1864,     0,     0,  2013,     0,     0,     0,
       0,  1103,     0,     0,     0,  2297,   873,  2298,  2014,  1866,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1104,     0,     0,     0,     0,     0,     0,  1877,     0,  1877,
       0,  1877,     0,     0,     0,     0, -1790,     0,     0,     0,
    1877,     0,     0,  1719,     0,  2967,     0,     0,     0,     0,
    1868,     0,     0,     0,     0, -1790,     0,     0,     0,     0,
       0,  1877,  1869,     0,  1877,  1877,     0,     0,   873,     0,
     873,     0,  1752,  1753,  1754,     0,  1756,  1877,     0,   873,
       0,     0,     0,     0, -1790,     0,     0,     0,  2991,  2992,
       0,  2994,     0,  2996,  2997,     0,     0,     0,     0,     0,
       0,  1105,  1719,  1870,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  2146,     0,     0,
       0,     0,     0,     0,     0,     0, -1790,     0,     0,     0,
       0,  1877,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1871,     0,     0,     0,  2168,     0,     0,     0,
       0,     0,     0,  1877,  1872,  2451, -1790,  3041,  2456,     0,
   -1790,     0,     0,     0,     0,     0,  1873,  1874,  1106,     0,
       0,     0,     0,     0,     0,  1875,     0,  3050,   689,  3051,
       0,  1819,     0,     0, -1790,     0,   272,  1719,     0,     0,
       0,  1877, -1790,     0, -1790,  1877,  1719,     0,     0,     0,
       0,     0,     0, -1790,     0,     0,     0,     0,     0, -1790,
       0,     0,     0,     0,     0,   856,  3063, -1790,     0,     0,
       0, -1790,     0,   926,     0,     0,     0, -1790,     0,     0,
       0, -1790, -1790, -1790, -1790,     0,     0,     0,     0,     0,
    3068,  3069,     0,     0,  3070,     0, -1790,  1074,  1075,  1076,
    1077,  1078,  1079,  1080,  1081,  1082,  1083,  1084,  1085,  1086,
    1087,     0,     0, -1790,     0,     0, -1790,     0, -1790,     0,
       0,     0,     0,     0,     0, -1790,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  2309,     0, -1790,     0,
       0,     0,     0,     0,     0,     0,     0,     0, -1790,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1088,  1089,  1090,  1091,  1092,  1093,     0, -1790, -1790,     0,
       0,     0,     0,     0,     0,     0,  1094,  1095,  1096,     0,
       0,     0, -1790,     0,     0,     0,     0,     0,     0,     0,
   -1790,     0,     0,     0, -1790,     0,     0,     0,     0,     0,
       0,     0,     0, -1790, -1790, -1790,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   873,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  2147,  1072,  1073,  1074,  1075,  1076,  1077,
    1078,  1079,  1080,  1081,  1082,  1083,  1084,  1085,  1086,  1087,
     873,     0,     0,  2101,     0,  2101,     0,     0,     0,     0,
       0,     0, -1790,     0,     0,     0,     0,     0,  2192,  2193,
    2194,  2195,     0, -1790,     0,     0,     0,    72,     0,     0,
       0,     0,     0,  2479,     0,     0,     0,     0,     0,     0,
       0,     0,  2489,     0,   703,     0,  2493,     0,     0,  1088,
    1089,  1090,  1091,  1092,  1093,     0,     0,  1097,  2503,     0,
    1098,     0,     0,     0, -1790,  1094,  1095,  1096,     0,     0,
       0,     0,  2196,  2197,  2198,  2199,  2200,  2201,     0,     0,
       0,     0,     0,  1072,  1073,  1074,  1075,  1076,  1077,  1078,
    1079,  1080,  1081,  1082,  1083,  1084,  1085,  1086,  1087,     0,
       0,     0,     0,     0,  2712,  1072,  1073,  1074,  1075,  1076,
    1077,  1078,  1079,  1080,  1081,  1082,  1083,  1084,  1085,  1086,
    1087,     0,     0,     0,     0, -1790,     0,     0,     0,     0,
       0,     0,     0,     0,  2729,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1088,  1089,
    1090,  1091,  1092,  1093,     0,     0,     0,     0,     0,     0,
       0, -1790,  2745,     0,  1094,  1095,  1096,     0,     0,     0,
    1088,  1089,  1090,  1091,  1092,  1093,     0,     0,     0,  1099,
       0,     0,     0,     0,     0,     0,  1094,  1095,  1096,     0,
       0,     0,     0,     0,  1100,     0,     0,     0,  1101,  2584,
    1083,  1084,  1085,  1086,  1087,     0,  1097,     0, -1790,  1098,
       0,     0,  1856,  1857,     0,  1858,     0,     0,   269,  1859,
    1860,     0, -1790, -1790, -1790, -1790, -1790, -1790, -1790,     0,
   -1790, -1790,     0,     0,     0,     0,  1102,     0,  1861,  2606,
       0,     0,     0,     0,     0,     0,     0, -1790,     0,     0,
       0,     0,  2621,     0,  1088,  1089,  1090,  1091,  1092,  1093,
    2251,     0,     0,     0,  1103,     0,     0,     0,     0,     0,
    1094,  1095,  1096,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1104,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    2252,  2253,  2254,     0,     0,  1097,     0,     0,  1098,     0,
       0,     0,     0,   873,     0,     0,     0,  1719,     0,     0,
       0,     0,     0,     0,     0,  2255,     0,  1097,  1099,  2843,
    1098,     0,     0,  2256,     0,     0,     0,     0,  2257,     0,
       0,   873,     0,  1100,     0,     0,     0,  1101,     0,     0,
       0,     0,     0,  2258,     0,     0,   190,     0,  2259,     0,
    2260,     0,     0,     0,  1105,     0,     0,  2261,     0,     0,
    2262,     0,     0,  2263,     0,     0,  2264,     0,     0,  2265,
       0,   928,     0,     0,  2266,  1102,     0,     0,     0,     0,
    2486,     0,     0,  1719,     0,     0,     0,   190,     0,     0,
       0,  1719,  2267,     0,     0,     0,     0,     0,     0,     0,
       0,  1097,     0,  1103,  1098,     0,     0,     0,  2268,     0,
       0,  2269,  2270,     0,     0,     0,     0,  1099,  2271,     0,
       0,  1106,  1104,     0,     0,     0,     0,     0,     0,  2272,
       0,     0,  1100,     0,     0,     0,  1101,  1414,     0,  1099,
       0,     0,     0,     0,     0,  2273,     0,     0,  2479,     0,
       0,     0,  2274,     0,  1100,     0,     0,     0,  1101,  2275,
       0,     0,  2276,  2277,  2278,     0,  2279,  2280,     0,     0,
       0,     0,     0,     0,  1102,     0,     0,     0,     0,     0,
       0,     0,     0,  2281,     0,     0,     0,     0,     0,     0,
    2606,     0,     0,     0,     0,     0,  1102,     0,     0,     0,
       0,     0,  1103,  1105,     0,     0,  2282,  2283,  2284,  2285,
       0,  2286,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1104,     0,  1099,  1103,     0,     0,     0,  2287,  2288,
       0,     0,     0,     0,     0,     0,     0,     0,  1100,     0,
       0,     0,  1101,  1104,     0,     0,     0,     0,     0,     0,
       0,  2289,     0,     0,     0,     0,     0,     0,     0,  1862,
    2290,  2291,     0,  2292,     0,     0,     0,     0,     0,     0,
    1106,     0,     0,     0,  1863,     0,  3029,     0,   873,     0,
    1102,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1864,     0,     0,  1865,  2852,  2479,     0,     0,     0,
     928,     0,  1105,     0,     0,     0,     0,  1866,  1103,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1105,  2293,     0,  1104,  1072,  1073,
    1074,  1075,  1076,  1077,  1078,  1079,  1080,  1081,  1082,  1083,
    1084,  1085,  1086,  1087,     0,     0,     0,  1867,  1868,     0,
       0,     0,     0,     0,  2479,     0,     0,     0,     0,     0,
    1869,     0,     0,     0,     0,     0,     0,     0,  2606,  1106,
       0,     0,     0,  2906,     0,  2908,  2693,     0,     0,     0,
       0,     0,  3071,     0,     0,     0,     0,     0,     0,     0,
       0,  1106,     0,  1088,  1089,  1090,  1091,  1092,  1093,     0,
       0,  1870,     0,     0,     0,     0,     0,     0,  1105,  1094,
    1095,  1096,     0,     0,     0,     0,   873,     0,     0,     0,
       0,     0,   873,     0,     0,     0,     0,  1719,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1871,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1872,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1873,  1874,     1,     0,     0,     0,
     417,   418,     0,  1875,     0,  1106,   689,     0,     0,     0,
       0,     0,     0,   419,   272,   420,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   421,
       0,     0,     0,     0,     0,     0,   422,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   423,   424,   425,
       0,     0,     0,     0,     0,     0,  1169,  1169,  1169,  1169,
    1169,  1169,     0,   426,     0,   427,   428,   429,     3,     4,
     430,     5,     6,   431,     0,   432,     7,   433,   434,     0,
    1097,     0,     0,  1098,   435,     0,     0,   436,     0,   437,
     438,   439,     0,     8,     9,     0,     0,     0,     0,   440,
       0,   441,   442,     0,   443,     0,   444,   445,     0,     0,
     446,    10,    11,     0,     0,   447,   448,   449,     0,   450,
     451,     0,     0,     0,   452,   453,     0,   454,     0,     0,
       0,   455,     0,   456,   457,     0,     0,     0,     0,   458,
       0,     0,     0,   459,     0,     0,   460,     0,   461,     0,
     462,     0,   463,     0,   464,   465,     0,   466,   467,   468,
       0,     0,     0,   469,     0,   470,   471,     0,   472,     0,
       0,     0,     0,     0,     0,     0,   473,   474,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   928,   475,
       0,     0,   476,   477,     0,     0,   478,   479,     0,     0,
     480,   481,  1099,     0,     0,     0,     0,     0,     0,   482,
     483,   484,     0,   485,     0,     0,     0,  1100,     0,     0,
       0,  1101,  1726,   486,   487,   488,     0,   489,     0,     0,
       0,   490,   491,     0,     0,     0,   492,     0,     0,     0,
       0,     0,     0,     0,   493,     0,     0,     0,     0,     0,
       0,     0,   494,   495,   496,     0,     0,     0,     0,  1102,
     497,   498,     0,     0,     0,     0,   499,     0,     0,   500,
       0,     0,     0,   501,   502,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   503,     0,     0,  1103,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   504,     0,     0,     0,  1104,     0,     0,     0,
     505,     0,     0,     0,     0,     0,   506,     0,     0,     0,
       0,     0,     0,  1072,  1073,  1074,  1075,  1076,  1077,  1078,
    1079,  1080,  1081,  1082,  1083,  1084,  1085,  1086,  1087,   107,
       0,     0,     0,     0,     0,     0,   507,     0,   508,   509,
       0,     0,     0,     0,     0,     0,     0,   510,     0,     0,
       0,     0,     0,     0,  1072,  1073,  1074,  1075,  1076,  1077,
    1078,  1079,  1080,  1081,  1082,  1083,  1084,  1085,  1086,  1087,
       0,     0,     0,     0,     0,     0,     0,  1105,  1088,  1089,
    1090,  1091,  1092,  1093,     0,     0,   511,     0,     0,     0,
       0,     0,     0,     0,  1094,  1095,  1096,   512,     0,     0,
       0,   513,     0,     0,     0,   514,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1719,     0,  1088,
    1089,  1090,  1091,  1092,  1093,     0,     0,     0,     0,   515,
     516,     0,     0,     0,   517,  1094,  1095,  1096,     0,     0,
       0,     0,     0,     0,  1106,     0,   518,     0,     0,     0,
       0,     0,   519,   520,   521,   522,     0,     0,   523,     0,
       0,     0,   524,     0,     0,     0,     0,     0,     0,   525,
     526,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   527,     0,   528,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   529,     0,   530,     0,     0,   531,
       0,     0,     0,     0,     0,   532,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   533,     0,     0,   534,  1097,     0,     0,  1098,     0,
     535,     0,     0,   536,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   537,     0,
       0,     0,     0,     0,     0,   538,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1097,     0,     0,  1098,
       0,     0,     0,     0,     0,     0,     0,     0,   539,   540,
     541,   542,   543,   544,   545,     0,     0,   546,     0,   547,
       0,   548,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1072,  1073,  1074,  1075,  1076,  1077,  1078,
    1079,  1080,  1081,  1082,  1083,  1084,  1085,  1086,  1087,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1072,  1073,
    1074,  1075,  1076,  1077,  1078,  1079,  1080,  1081,  1082,  1083,
    1084,  1085,  1086,  1087,     0,     0,     0,  1099,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1100,     0,     0,     0,  1101,  1735,  1088,  1089,
    1090,  1091,  1092,  1093,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1094,  1095,  1096,     0,  1099,     0,
       0,     0,     0,  1088,  1089,  1090,  1091,  1092,  1093,     0,
       0,     0,     0,  1100,  1102,     0,     0,  1101,  1747,  1094,
    1095,  1096,     0,     0,  1072,  1073,  1074,  1075,  1076,  1077,
    1078,  1079,  1080,  1081,  1082,  1083,  1084,  1085,  1086,  1087,
       0,     0,  1103,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1102,     0,     0,     0,     0,
       0,  1104,     0,  1072,  1073,  1074,  1075,  1076,  1077,  1078,
    1079,  1080,  1081,  1082,  1083,  1084,  1085,  1086,  1087,     0,
       0,     0,     0,  1103,     0,     0,     0,     0,     0,  1088,
    1089,  1090,  1091,  1092,  1093,     0,     0,     0,     0,     0,
       0,     0,  1104,     0,     0,  1094,  1095,  1096,  1073,  1074,
    1075,  1076,  1077,  1078,  1079,  1080,  1081,  1082,  1083,  1084,
    1085,  1086,  1087,     0,     0,     0,     0,     0,  1088,  1089,
    1090,  1091,  1092,  1093,     0,  1097,     0,     0,  1098,     0,
       0,     0,  1105,     0,  1094,  1095,  1096,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1097,     0,     0,  1098,     0,     0,     0,     0,     0,     0,
       0,     0,  1088,  1089,  1090,  1091,  1092,  1093,     0,     0,
       0,     0,     0,  1105,     0,     0,     0,     0,  1094,  1095,
    1096,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1106,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1075,  1076,  1077,
    1078,  1079,  1080,  1081,  1082,  1083,  1084,  1085,  1086,  1087,
       0,     0,     0,     0,     0,     0,  1097,     0,     0,  1098,
    1106,     0,     0,     0,     0,     0,     0,  1099,  1076,  1077,
    1078,  1079,  1080,  1081,  1082,  1083,  1084,  1085,  1086,  1087,
       0,     0,  1100,     0,     0,     0,  1101,  1755,     0,     0,
       0,     0,  1099,     0,     0,  1097,     0,     0,  1098,  1088,
    1089,  1090,  1091,  1092,  1093,     0,     0,  1100,     0,     0,
       0,  1101,  1757,     0,     0,  1094,  1095,  1096,     0,     0,
       0,     0,     0,     0,  1102,     0,     0,     0,     0,  1088,
    1089,  1090,  1091,  1092,  1093,     0,     0,     0,     0,  1097,
       0,     0,  1098,     0,     0,  1094,  1095,  1096,     0,  1102,
       0,     0,  1103,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1104,     0,     0,     0,     0,     0,  1103,  1099,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1100,     0,     0,  1104,  1101,  1758,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1099,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1100,     0,     0,  1102,  1101,  1759,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1105,     0,     0,     0,  1097,     0,     0,  1098,
       0,  1099,     0,  1103,     0,     0,     0,  1081,  1082,  1083,
    1084,  1085,  1086,  1087,  1102,     0,  1100,  1105,     0,     0,
    1101,     0,  1104,     0,     0,     0,  1097,     0,     0,  1098,
    1077,  1078,  1079,  1080,  1081,  1082,  1083,  1084,  1085,  1086,
    1087,     0,  1103,     0,     0,     0,     0,  1087,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1102,  1106,
       0,  1104,     0,  1088,  1089,  1090,  1091,  1092,  1093,     0,
       0,     0,  1082,  1083,  1084,  1085,  1086,  1087,     0,  1094,
    1095,  1096,     0,     0,  1106,     0,  1103,     0,     0,     0,
    1088,  1089,  1090,  1091,  1092,  1093,     0,  1088,  1089,  1090,
    1091,  1092,  1093,  1105,     0,  1104,  1094,  1095,  1096,     0,
       0,     0,     0,  1094,  1095,  1096,     0,     0,  1099,     0,
       0,     0,     0,     0,     0,     0,     0,  1088,  1089,  1090,
    1091,  1092,  1093,  1100,     0,     0,     0,  1101,     0,     0,
       0,     0,  1105,  1094,  1095,  1096,     0,     0,  1099,     0,
       0,   714,   715,     0,     0,     0,     0,   269,   716,   717,
    -610,     0,     0,  1100,     0,     0,     0,  1101,     0,     0,
    1106,     0,   718,     0,     0,  1102,     0,   719,   720,     0,
       0,     0,     0,     0,   721,     0,  1105,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1103,     0,  1102,     0,     0,     0,  1106,
       0,     0,   722,     0,     0,     0,     0,     0,   714,   715,
    1097,     0,  1104,  1098,   269,   716,   717,  -610,     0,     0,
       0,     0,     0,  1103,     0,     0,     0,     0,     0,   718,
       0,     0,     0,     0,   719,   720,     0,  1097,     0,     0,
    1098,   721,  1104,  1106,  1097,     0,     0,  1098,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   722,
       0,     0,     0,     0,  1097,   714,   715,  1098,     0,     0,
       0,   269,   716,   717,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1105,     0,   723,   718,     0,     0,     0,
       0,   719,   720,     0,     0,     0,     0,     0,   721,     0,
       0,  1088,  1089,  1090,  1091,  1092,  1093,     0,     0,     0,
       0,     0,     0,  1105,     0,     0,     0,  1094,  1095,  1096,
       0,     0,  1099,     0,     0,     0,   722,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1100,     0,     0,
       0,  1101,     0,     0,     0,     0,     0,     0,     0,  1099,
    1106,     0,   723,     0,     0,     0,  1099,     0,     0,     0,
       0,     0,     0,     0,  1100,     0,     0,     0,  1101,     0,
       0,  1100,     0,     0,     0,  1101,     0,     0,     0,  1102,
    1106,     0,   724,     0,     0,     0,  1099,   725,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1100,   714,   715,     0,  1101,  1102,  1103,   269,   716,
     717,     0,     0,  1102,     0,   726,     0,     0,     0,   723,
       0,     0,     0,   718,     0,     0,  1104,     0,   719,   720,
       0,     0,     0,     0,  1103,   721,     0,     0,     0,     0,
       0,  1103,     0,  1102,     0,     0,     0,     0,     0,   724,
     727,     0,     0,  1104,   725,     0,     0,     0,  1097,     0,
    1104,  1098,   728,   722,     0,     0,     0,     0,     0,  1856,
    1857,  1103,  1858,     0,     0,   269,  1859,  1860,     0,     0,
     729,     0,   726,     0,     0,   730,     0,     0,   731,     0,
    1104,     0,     0,     0,     0,  1861,     0,     0,     0,   732,
       0,     0,     0,     0,     0,   733,     0,  1105,     0,     0,
       0,     0,     0,     0,     0,   734,   724,   727,     0,     0,
     735,   725,     0,   736,     0,     0,   737,     0,     0,   728,
       0,     0,     0,     0,  1105,   738,   739,   714,   715,     0,
       0,  1105,     0,   269,   716,   717,     0,   729,     0,   726,
       0,     0,   730,     0,     0,   731,   723,     0,   718,     0,
       0,     0,     0,   719,   720,     0,   732,     0,     0,     0,
     721,  1105,   733,     0,  1106,     0,  1192,   740,     0,     0,
    1099,   741,   734,     0,   727,     0,     0,   735,     0,   742,
     736,     0,     0,   737,     0,  1100,   728,     0,   722,  1101,
     743,  1106,   738,   739,     0,     0,   744,     0,  1106,     0,
       0,     0,     0,     0,   729,     0,     0,     0,     0,   730,
       0,     0,   731,     0,     0,     0,     0,     0,     0,     0,
     745,     0,     0,   732,     0,     0,     0,  1102,  1106,   733,
       0,     0,     0,     0,   740,     0,     0,     0,   741,   734,
       0,     0,     0,   724,   735,     0,   742,   736,   725,     0,
     737,     0,     0,     0,     0,  1103,     0,   743,     0,   738,
     739,     0,     0,   744,   746,     0,     0,     0,     0,     0,
       0,   747,     0,   748,  1104,     0,   726,     0,     0,     0,
       0,   723,     0,   749,   750,   751,     0,   745,     0,     0,
       0,     0,   752,     0,     0,    82,     0,     0,     0,     0,
    1192,   740,     0,   272,     0,   741,     0,     0,     0,     0,
       0,   727,     0,   742,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   728,   743,     0,     0,     0,     0,     0,
     744,   746,     0,     0,     0,     0,     0,     0,   747,     0,
     748,   729,     0,     0,     0,     0,   730,     0,     0,   731,
     749,   750,   751,     0,   745,  1105,     0,     0,     0,   752,
     732,     0,    82,     0,     0,     0,   733,     0,     0,     0,
     272,     0,     0,     0,     0,     0,   734,     0,   724,     0,
       0,   735,     0,   725,   736,     0,     0,   737,     0,     0,
       0,     0,     0,     0,   714,   715,   738,   739,   746,     0,
     269,   716,   717,     0,     0,   747,     0,   748,     0,     0,
       0,   726,     0,     0,     0,   718,  1862,   749,   750,   751,
     719,   720,  1106,     0,     0,     0,   752,   721,     0,    82,
       0,  1863,     0,  1856,  1857,     0,  1858,   272,   740,   269,
    1859,  1860,   741,     0,     0,     0,   727,     0,  1864,     0,
     742,  2638,     0,     0,     0,   722,     0,     0,   728,  1861,
       0,   743,     0,  2115,  1866,   203,     0,   744,     0,     0,
       0,     0,     0,     0,     0,     0,   729,     0,     0,     0,
    -852,   730,     0,     0,   731,     0,     0,     0,     0,     0,
       0,   745,  2370,   204,   205,   732,     0,     0,     0,     0,
       0,   733,   206,     0,  2886,  1868,     0,     0,     0,     0,
       0,   734,     0,     0,     0,     0,   735,  1869,     0,   736,
       0,     0,   737,     0,     0,     0,     0,     0,     0,     0,
       0,   738,   739,     0,     0,   746,     0,     0,     0,     0,
       0,     0,   747,     0,   748,     0,     0,     0,   723,     0,
       0,     0,     0,     0,   749,   750,   751,     0,  1870,     0,
       0,     0,     0,   752,     0,     0,    82,     0,     0,     0,
       0,     0,     0,   740,   272,     0,     0,   741,     0,     0,
       0,     0,     0,     0,     0,   742,   714,   715,     0,     0,
       0,     0,   269,   716,   717,     0,   743,  1871,     0,     0,
       0,     0,   744,     0,     0,     0,     0,   718,     0,  1872,
       0,     0,   719,   720,     0,     0,     0,  1856,  1857,   721,
    1858,  1873,  1874,   269,  1859,  1860,   745,     0,     0,     0,
    1875,     0,     0,   689,     0,     0,     0,     0,     0,     0,
       0,   272,     0,  1861,     0,   724,     0,   722,  1856,  1857,
     725,  1858,     0,     0,   269,  1859,  1860,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     746,     0,     0,   207,  1861,     0,     0,   747,   726,   748,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   749,
     750,   751,     0,     0,     0,     0,     0,     0,   752,     0,
       0,    82,     0,     0,     0,     0,     0,     0,     0,   272,
       0,     0,   208,   727,     0,     0,  1856,  1857,     0,  1858,
       0,     0,   269,  1859,  1860,   728,  1856,  1857,     0,  1858,
       0,   209,   269,  1859,  1860,     0,     0,     0,     0,     0,
     723,     0,  1861,   729,     0,     0,     0,   210,   730,     0,
       0,   731,  1861,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   732,     0,     0,     0,     0,     0,   733,     0,
     211,     0,     0,     0,     0,     0,     0,     0,   734,     0,
       0,     0,   212,   735,     0,     0,   736,     0,     0,   737,
    1862,     0,   213,     0,     0,     0,     0,     0,   738,   739,
       0,     0,     0,     0,     0,  1863,     0,     0,     0,     0,
     214,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     215,     0,  1864,     0,     0,  2885,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   216,   724,  1866,  2507,
     740,     0,   725,     0,   741,     0,     0,     0,     0,     0,
       0,     0,   742,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   743,     0,     0,     0,     0,     0,   744,
     726,     0,     0,  2012,     0,     0,   217,     0,  2886,  1868,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1869,     0,   745,     0,     0,     0,     0,     0,     0,
     218,     0,     0,     0,     0,   727,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   219,     0,   728,     0,     0,
       0,     0,   220,     0,     0,   221,     0,     0,     0,     0,
       0,     0,  1870,     0,     0,   729,     0,   746,     0,     0,
     730,     0,     0,   731,   747,   222,   748,     0,   223,     0,
     224,     0,     0,     0,   732,     0,   749,   750,   751,     0,
     733,     0,     0,     0,     0,   752,     0,     0,    82,   225,
     734,  1871,     0,     0,  1862,   735,   272,     0,   736,     0,
       0,   737,     0,  1872,     0,     0,     0,   226,     0,  1863,
     738,   739,     0,     0,     0,  1873,  1874,     0,     0,     0,
       0,     0,     0,     0,  1875,  1862,  1864,   689,  1913,  2013,
       0,     0,     0,     0,     0,   272,     0,     0,     0,     0,
    1863,  2014,  1866,     0,     0,     0,     0,     0,     0,     0,
     227,     0,   740,     0,     0,     0,   741,  1864,     0,     0,
    2638,     0,     0,     0,   742,     0,     0,     0,     0,     0,
       0,     0,     0,  1866,     0,   743,     0,     0,   829,     0,
       0,   744,     0,  1868,     0,     0,     0,   830,     0,     0,
       0,     0,     0,  1862,     0,  1869,   831,     0,     0,     0,
       0,   832,     0,  1862,     0,   745,     0,     0,  1863,     0,
       0,     0,     0,  2886,  1868,     0,     0,     0,  1863,     0,
       0,     0,     0,     0,     0,  1864,  1869,     0,  1865,     0,
       0,     0,     0,  2945,     0,  1864,  1870,     0,  1865,     0,
       0,  1866,     0,     0,     0,   833,     0,     0,     0,   746,
       0,  1866,     0,   834,     0,     0,   747,     0,   748,     0,
       0,     0,     0,     0,     0,     0,     0,  1870,   749,   750,
     751,     0,     0,     0,     0,  1871,     0,   752,     0,     0,
      82,  2978,  1868,     0,     0,     0,     0,  1872,   272,  2946,
       0,     0,  1868,     0,  1869,     0,     0,     0,     0,  1873,
    1874,  2015,     0,     0,  1869,     0,  1871,     0,  1875,   835,
       0,   689,     0,     0,  2947,     0,     0,     0,  1872,   272,
       0,     0,     0,  2948,     0,     0,     0,     0,     0,     0,
    1873,  1874,     0,     0,   836,  1870,     0,     0,     0,  1875,
       0,   837,   689,   838,     0,  1870,     0,     0,     0,     0,
     272,     0,     0,   839,     0,     0,     0,     0,     0,  2949,
       0,     0,  1914,     0,     0,     0,     0,  2950,     0,     0,
       0,     0,     0,     0,  1871,  1915,     0,     0,     0,   840,
       0,     0,     0,     0,  1871,     0,  1872,   841,     0,     0,
       0,     0,     0,     0,     0,     0,  1872,     0,  1873,  1874,
       0,     0,     0,     0,     0,     0,     0,  1875,  1873,  1874,
     689,     0,     0,     0,     0,     0,     0,  1875,   272,     0,
     689,     0,     0,     0,   842,     0,     0,     0,   272,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1916,
       0,     0,     0,     0,     0,     0,  1917,     0,     0,     0,
     843,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  2951,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1918,     0,     0,   844,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   845,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1919,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1920,  1921,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1922,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1923,     0,     0,
    1924,  1925,     0,     0,     0,     0,  1926,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   846,   847,
     848,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   849,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1927,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  2952,     0,  1928,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   850
};

static const short yycheck[] =
{
       2,   193,   187,   708,     0,   328,   704,    64,   857,   839,
      12,    13,   497,   445,   979,   828,   422,  1482,   212,   507,
     986,   824,  1395,    82,   683,   513,    60,    23,  1724,   517,
    1728,   993,   920,    29,  1671,  1666,  1667,  2055,  1845,  1670,
     175,    43,    44,   521,   363,  1449,   934,   835,   836,  1360,
     838,  1363,   840,   841,  1675,  1349,   515,  1292,  1260,  1261,
     117,    95,   865,  1786,  1011,   479,  1594,   418,    64,     5,
       5,    20,    45,  2012,    76,  2014,   388,    79,    25,   264,
       5,    79,   780,   542,    66,    67,   545,   153,    25,    91,
     225,     5,   504,    24,     5,    23,    98,    25,   504,     5,
      24,   452,   104,   105,   455,  1912,   538,   141,   110,   111,
      23,   145,    25,    23,   465,    25,    17,    18,   469,    55,
       5,   117,   473,    26,    25,    61,    24,    24,    26,   480,
    1534,    24,  1023,    47,   485,    49,   487,    51,   951,  1543,
     953,    23,   493,    25,  1775,   496,    24,   149,   340,    24,
     152,    26,   503,    24,     5,   157,    24,   508,    26,   136,
      24,    17,    18,    24,    24,   516,    24,    23,    24,    25,
     128,   237,   238,     5,     5,    79,   527,    23,    24,    25,
     531,    18,     5,    24,   535,     5,    23,    24,    25,   540,
       5,    24,   543,   227,   196,    23,    24,    25,    24,     5,
       9,   113,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,   141,    26,     5,    29,   846,   847,     5,   924,
      23,    24,    25,    17,    18,    39,    18,     5,     5,    23,
      24,    25,   234,    25,   508,     5,    20,     5,   240,   128,
      24,  1862,     5,     5,     5,    43,   280,     6,   282,   251,
     303,  1606,    25,   287,  2570,    24,     5,    92,    41,   214,
     253,   689,    71,    72,    73,    74,    75,    76,     6,  1645,
      84,    85,  1648,  2186,  2187,  2188,  2189,   318,    92,     5,
     253,     5,     5,   318,     5,  2232,   368,   101,   102,   363,
     104,   105,   318,   409,  2772,   109,   131,    41,   275,   338,
     370,   338,   336,   141,   339,  1900,    22,   364,   365,  2885,
     437,     5,   126,   127,  1951,     5,   437,  1948,   437,   353,
     525,   114,   115,  1788,  2406,    24,   488,   186,   312,   274,
     144,   145,    17,    70,    35,    36,   555,   370,  2833,  2146,
       6,    24,   253,   154,  1975,   409,   261,   253,   517,   417,
     323,  2884,     5,   274,   356,  1204,   604,   359,     5,   274,
     428,     0,    63,    64,    65,   367,    30,   450,   364,   365,
       0,   404,   436,   417,   351,   458,  2013,   596,  2009,   627,
     364,   383,    27,   385,   428,     5,    17,    18,    19,    20,
      21,     5,   597,    23,   323,   368,     5,   566,     5,    84,
    2409,  1363,     5,  2412,  1057,   326,   450,   460,     5,   330,
     412,   359,   890,   457,     5,   417,   455,   419,   455,   367,
     422,   423,   231,   425,     5,   119,   428,    28,  2510,    17,
      18,    19,    20,    21,    17,    18,     5,   439,   458,   250,
      23,    24,    25,  2976,   446,     5,  2941,   568,     5,     5,
    2389,   471,  2391,   409,  2393,     5,   458,   417,  1163,     5,
     363,     5,     5,   408,   412,     5,   468,     5,   428,   471,
     568,     5,   599,  3049,     5,     5,   129,   828,   599,   481,
     599,   437,   129,   605,   646,   323,    23,   408,    25,   605,
    2630,     5,  2632,   408,   471,   497,   498,   213,   568,     5,
       5,     5,   504,     5,     5,     5,     5,  2985,   409,     5,
     512,     5,   514,   515,     5,   328,   557,   591,   374,   378,
     522,   523,   557,   525,   526,   564,   528,   564,   530,   484,
     532,   557,   346,   389,   536,   537,    26,   539,   262,   541,
     542,   350,   544,   545,  1029,   547,   504,   370,  1033,  1034,
    1035,   604,  2183,   450,   547,   874,   638,   876,   372,  1189,
     363,   370,    17,    18,    19,    20,    21,  1052,   366,  2164,
     623,   624,   303,   405,   547,  2891,   574,  1036,  1006,   370,
     374,   493,   518,   418,   352,   420,   421,  1285,  1286,  1791,
     643,  1946,   370,   391,   523,   389,  1294,  1009,   407,   434,
     951,   952,   953,  1009,  1495,   374,   368,   370,  2555,   370,
    1986,   370,  2630,  2244,  2632,   504,   494,   452,   405,  2637,
     455,   370,   415,   605,   528,   409,   461,   556,   405,   443,
     465,   529,   370,   564,   469,   405,   547,   671,   473,  1337,
     525,   547,   477,   478,   591,   480,   648,   970,   483,   370,
     485,   486,   487,  1131,   591,   628,   629,   630,   493,   971,
     591,   496,   555,   466,  1149,  1143,   639,   591,   503,  1557,
     606,   599,   597,   508,   676,   419,   678,   475,   952,   405,
     370,   516,   405,   597,   535,  1144,   599,   689,   591,   599,
     591,   605,   527,   591,   591,  2502,   531,   646,   591,  2227,
     535,   532,   704,  2642,   370,   540,   641,   480,   543,   529,
     409,  1196,   714,   715,   529,  1127,   591,   599,  1132,   525,
     591,  1127,   536,   591,  1959,   345,   535,   591,   730,   460,
     591,   591,   433,   591,   736,   737,  2434,  1222,   521,   741,
    2463,  2035,  1227,   599,  2467,   591,  2150,  2058,  2060,   751,
     591,  1713,  1240,   599,  2158,  1702,   370,    24,   591,    26,
     533,   370,   599,   370,  1223,   591,  2397,   370,  2399,   567,
    2683,   599,   581,   370,   405,  2915,   568,   521,   780,   370,
       5,   579,   580,  2865,  1216,   332,    22,   228,   591,   370,
     588,   374,  1445,   602,   323,  1448,   599,   591,  1257,  1258,
     596,   370,   227,   617,  1766,   599,   389,  2754,  2755,  1622,
     370,   625,   432,   370,   370,   136,  1008,   405,   591,   520,
     370,    22,   824,   825,   370,   596,   370,   370,  2767,   449,
     370,   261,   370,  2772,   101,   102,   370,   104,   105,   370,
     370,  2923,   109,     9,   274,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,  2551,   370,   859,  2231,   126,
     127,    20,   563,   865,   370,   370,   370,   450,   370,   370,
     370,   370,   492,   604,   370,   877,   370,   144,   145,   370,
     882,   618,   619,   620,   621,   622,   888,  2969,   221,  2971,
     147,  2512,   623,   624,  1372,   527,  2567,  2915,  1386,   531,
       5,  2919,   353,   535,   906,    71,    72,    73,    74,    75,
      76,   531,   643,   599,  1612,   370,   982,  1944,   920,   985,
     112,   517,   332,  2125,   365,  2556,   367,  2824,   310,  2826,
     517,     9,   934,    11,    12,    13,    14,    15,    16,   314,
     560,     5,  2749,    19,    20,   409,  2885,  2578,   215,   569,
     325,   334,   598,   437,   275,   409,  2766,  1445,   599,   605,
    1448,    23,  1147,    25,    17,    18,    19,    20,    17,    18,
     566,    20,   436,   437,    23,    24,    25,   213,   408,   566,
      20,  1811,   436,   437,    24,   987,   178,    13,   180,   991,
     992,   993,   500,   828,    43,    71,    72,    73,    74,    75,
      76,   224,   377,   195,  1006,    27,    28,  1009,   591,  1011,
    1012,   203,   213,  1015,   237,   207,   599,   392,    71,    72,
      73,    74,    75,    76,   409,   450,   218,  1029,  1030,   224,
     351,  1033,  1034,  1035,  1036,  1494,  1038,   262,   514,  1041,
     232,  1890,   237,  1999,  2010,   574,  2985,   843,    91,  2005,
    1052,   409,  1054,    18,   850,   142,  1058,   409,    23,   146,
      25,  2725,   409,  1541,  1066,   231,  1068,  1069,  2878,  1071,
    1072,  1073,  1074,  1075,  1076,  1077,  1078,  1079,  1080,  1081,
    1082,  1083,  1084,  1085,  1086,  1087,   436,   437,   409,   540,
    2494,  2057,  1577,  1578,   535,   217,  1098,  1099,  2060,   619,
     620,  1103,  2773,  1105,  2914,   341,  2802,   482,  3005,   409,
    3049,   493,  2733,  1128,  2735,  1130,   951,   952,   953,   437,
    1598,   503,    19,    20,    21,  1127,   404,   455,   409,   512,
    2761,  1133,  1134,  1135,  1593,    25,  1487,  1950,   409,    42,
     341,   469,  1144,   526,  1146,   473,  1148,  1149,  1283,   416,
     471,  1153,   274,   231,  1289,   101,   102,   485,   104,   105,
     417,  1974,   249,   109,   437,   252,   618,  2977,   551,   621,
     622,   428,    24,    25,    71,    72,    73,    74,    75,    76,
     126,   127,   196,  2071,   350,  2881,   200,   274,  1190,   409,
      87,    88,    89,   450,  1196,   646,  2860,   409,   144,   145,
     457,   436,   437,  2834,   326,   409,  2233,  2234,   330,    25,
    1529,   224,  1566,  1215,   409,   604,   541,   600,  1220,   544,
    1222,  1223,   547,   604,   237,  1227,  1714,  1705,   249,  1231,
    1232,   252,   455,   254,   266,   267,  1934,   626,   627,   249,
    1242,   407,   252,   605,   254,   626,   627,    23,   471,    25,
    1601,   605,  2625,   274,  1256,  1257,  1258,  2894,   487,  1325,
     455,   621,   622,   284,   274,   409,  1620,   496,  1334,   215,
     409,  1622,   350,    44,   284,  2049,   471,  2051,  2052,  1977,
    1282,    25,   303,  1285,  1286,    25,   408,    25,  1290,  1767,
    1292,  1769,  1294,   303,  2931,    25,  1330,   628,   629,  2963,
    1778,  2965,   460,  1962,    25,   326,   599,   217,  1367,   330,
     437,   540,    83,    25,   543,    25,   326,   370,   844,   845,
     330,   408,   848,   849,   591,   374,   628,   629,   142,    24,
      25,   228,   146,    25,   231,  1337,    17,    18,    19,    20,
     389,    25,    25,   320,    87,    88,    89,  1349,    17,    18,
      19,    20,   329,    25,   599,    37,   170,   406,  1360,   370,
     409,  1363,   133,   409,   274,   340,   599,  1855,    25,   535,
    1724,   409,  2175,   422,   409,   278,   353,  2226,  3009,   356,
    1382,  1383,  1384,     5,   370,  2758,   405,   408,  1390,  2854,
      71,    72,    73,    74,    75,    76,   409,   374,   408,   599,
     171,    25,    71,    72,    73,    74,    75,    76,   237,   405,
     370,  1246,    24,   370,   463,   581,   326,  1419,  1420,  1421,
     330,  1423,    18,   340,    25,    20,   475,    23,    24,    25,
     444,   445,    25,   336,    25,   249,   602,    25,   252,   460,
      25,    20,   455,   409,    25,   348,   604,  1449,    25,  1451,
     460,    25,  2418,   350,   599,   358,   370,   535,   471,   370,
     274,     5,  2424,  1465,   438,   623,   624,   516,   365,   646,
     416,   591,   369,   376,   370,   281,   370,  2942,   370,   370,
     603,  1483,   370,   386,     5,   643,   389,  1489,   370,  1491,
    1492,  1493,  1494,   281,    40,   370,  2961,   268,   408,   402,
     549,   370,   603,   480,   370,   370,   555,   599,    24,   437,
     407,  1865,   596,   345,   599,   564,   565,     8,   567,   405,
      24,  1523,   458,   504,   538,   409,  1528,   399,    20,    21,
     579,   580,  1534,   409,   548,   409,   409,  1539,   435,   588,
    1734,  1543,   591,   245,     5,   409,   409,  1549,   451,   409,
     599,   409,  3017,   409,   409,  1557,   533,   454,   409,   409,
    2964,   409,  1564,   540,  1566,   336,   112,   592,   593,   594,
     595,   345,   409,   344,   409,  1577,  1578,   348,   481,    71,
      72,    73,    74,    75,    76,   409,   409,  2065,   491,   409,
     409,  1593,   409,  1944,   408,    87,    88,    89,   409,  1950,
     432,   409,   142,   597,   409,   409,   146,   409,   511,   597,
    1612,   514,   438,   516,   385,   574,   399,   449,  1620,   409,
     438,   638,   643,  1974,     8,   305,  2591,   575,     5,  1631,
     170,  2109,   178,   643,   180,   638,  2485,     5,   535,   362,
     409,   544,  1644,  1645,   409,   409,  1648,   409,   409,   195,
     553,    24,  1487,  2483,   409,   323,   568,   203,   432,  2013,
     492,   207,  1664,     8,  1666,  1667,    13,   249,  1670,  1671,
     252,   283,   254,   554,   557,   449,     5,   289,   290,   291,
     638,     5,   453,   638,   399,   409,   232,   409,    25,   370,
      25,    45,   274,   409,   708,  1697,    70,   309,   437,   531,
    1702,   370,   284,   437,  1706,   602,   138,    17,    18,   249,
      20,  1713,   252,    23,    24,    25,    25,     5,   492,   409,
     409,   492,  1724,   155,   156,    20,   568,  2212,   560,  2214,
     574,   163,  2430,    43,   274,   409,   228,   569,   599,   231,
      20,   755,   409,   450,   326,   516,   409,    20,   330,   409,
     421,   605,   605,   409,   409,   345,   409,   531,  1760,   605,
    1762,   641,   329,   434,  1766,   197,  1601,   535,  1770,  1771,
    1772,  1773,    17,  1775,   206,    18,   604,     5,    25,  1781,
    1782,    25,   131,  1785,  1786,  2490,   560,  1622,   197,   560,
     461,    24,  1794,   568,   557,   569,   461,  2203,   569,   602,
     461,     5,  1804,   235,   129,   417,   477,   478,   420,    25,
       5,   525,   483,   378,   525,   486,   300,   525,    25,    24,
     591,    17,    18,    19,    20,    21,   408,   599,   643,   409,
     555,   409,   444,   409,   409,   370,  2190,  2191,  2192,  2193,
    2194,  2195,   432,   409,   370,   370,  2695,   525,   280,  1851,
     370,  1853,   464,   370,  2703,   370,   370,    25,   350,   449,
     370,   370,   370,  1865,   370,    20,  1701,   596,   408,    17,
      18,    19,    20,   365,   605,     5,     5,   369,   460,     5,
     599,   558,  2233,  2234,   370,   605,     5,   499,     5,  1891,
     322,   462,  2324,  2325,  2326,  2249,  2328,  2329,  2330,  2331,
    2332,  2333,   492,   604,   409,  2337,   518,   519,   409,   532,
     924,    25,    25,   409,   514,   407,    71,    72,    73,    74,
      75,    76,   534,    71,    72,    73,    74,    75,    76,    45,
     370,     5,  1934,   304,    17,    18,    19,    20,   409,   370,
     370,   531,  1999,   435,  2422,   339,  1948,   575,  2005,  1951,
      71,    72,    73,    74,    75,    76,  1958,  1959,   605,   599,
      13,   573,   454,  1965,   639,  1967,    17,    18,    19,    20,
     560,   529,  2450,  1975,   525,  1977,     5,  2675,    25,   569,
     450,   227,    79,   409,  1986,   961,   599,    29,    71,    72,
      73,    74,    75,    76,   606,     4,     5,     6,     7,     8,
       9,  2850,    11,  1999,   409,     5,   605,  2009,    24,  2005,
     112,  2013,  2471,  2015,  2719,   604,   618,   405,   405,  2478,
      71,    72,    73,    74,    75,    76,   439,   439,   409,   409,
     409,   409,   370,  2035,  2388,  1870,     8,   409,     5,  2393,
      52,    53,   409,   535,    56,    57,    58,   409,     5,    25,
      25,    77,   370,   409,   370,   568,  2058,   370,  2060,   101,
     102,   643,   104,   105,   374,   370,  2068,   109,   599,  2071,
       5,   599,  2074,   304,     8,   599,   178,   437,   180,   389,
    2893,   323,   323,   323,   126,   127,   409,   599,   339,   404,
      20,   345,   409,   195,     5,   409,   406,   409,   409,   409,
    1935,   203,   144,   145,    25,   207,   409,   409,   399,  1944,
     602,   630,   422,  2115,     5,  1950,  2118,     5,    97,     5,
       5,  2123,    25,   574,   574,  2974,  2824,   596,  2826,     5,
     232,   409,   599,   562,  2136,   599,  2138,     5,  2140,  1974,
     450,     5,     5,   409,   156,  2147,     7,   370,  2150,  1163,
       5,   163,  2154,   463,    25,    25,  2158,  2945,  2946,  2947,
    2948,  2949,  2950,   605,  2518,   475,  2520,  2521,  2522,  2523,
       8,    25,   599,  2175,    25,   568,   370,   370,   432,   370,
     605,  2183,    25,   605,   370,   197,   370,   370,  2190,  2191,
    2192,  2193,  2194,  2195,   206,   449,  2031,  2551,   370,   370,
      59,  2203,  1216,    20,     5,   545,   516,   253,   345,  2694,
    2212,    20,  2214,   370,   345,     5,     5,   525,    20,  2697,
       5,   200,   370,   235,   236,   219,   370,   370,   550,   208,
     605,   437,   409,   599,   419,   214,   370,   216,   492,   409,
    1735,   450,  2244,     6,   605,   555,   532,  2249,   227,   532,
    1264,  1746,   605,   189,    24,   603,  1751,   567,    24,   603,
    1755,   425,  1757,  1758,  1759,    24,   598,  2590,   280,   579,
     580,    24,    24,   409,   133,   134,   255,   531,   588,    25,
    2465,   591,  2636,    25,  2638,   311,    25,   370,    25,   599,
      25,   450,   271,   335,  2296,   432,    25,   276,   324,   409,
     599,   432,   275,  2305,  2306,  2307,   560,  3005,    25,   288,
     322,  2313,   449,     5,  2506,   569,   295,   504,   449,   370,
     370,   370,    17,    18,    19,    20,   446,   247,   187,   568,
     370,     5,   447,   409,   193,   370,    20,   529,   399,     5,
    1316,  1317,   384,   323,   219,   405,   370,  1323,   468,     5,
     370,   419,   323,    20,   118,   492,    13,     5,    13,   441,
     189,   492,   388,  2841,   599,     5,   378,    20,   370,   395,
       5,    25,  3077,  2375,   370,  2377,    71,    72,    73,    74,
      75,    76,   370,    25,  2738,   370,  2388,    26,   347,  2743,
     598,  2393,   512,   310,   531,  2397,   352,  2399,  2233,  2234,
     531,   547,   522,   523,    25,   264,   526,   266,   434,   370,
     530,   409,   532,  2767,   220,   370,   536,   537,  2772,   554,
     409,   525,  2424,   560,   605,   218,   218,   420,  2430,   560,
      25,   437,   569,   459,   426,   409,   605,   370,   569,   371,
     605,  2443,   370,   469,   470,   599,     5,   605,  2802,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,   485,
      13,  2463,   405,   345,  2466,  2467,     5,     5,    24,  2471,
      20,   450,  2474,   220,   370,  2829,  2478,     5,   457,  2153,
     506,   340,   409,   509,   510,  3027,   370,   370,  2068,   515,
    2074,  1233,  2494,  1841,  1550,    36,    38,   364,  1782,  2136,
     479,  1788,  2504,   287,   141,   484,   209,   145,    71,    72,
      73,    74,    75,    76,   281,   396,  2518,  1329,  2520,  2521,
    2522,  2523,   353,   288,    87,    88,    89,  2881,   211,  2883,
    2532,  2885,  1330,  1749,   371,  2370,  2438,   316,   315,   383,
     385,  3017,  2893,  1523,  1762,  1642,   572,  2549,   525,  2551,
     432,  1400,  1566,  1649,  2556,   958,  1493,  1533,   584,  1772,
    1004,  2535,  1256,  2565,  2918,  2207,  1259,   449,  2570,  1573,
    1887,   430,  3041,  1776,  2223,  2711,  2578,  2221,  2580,  1588,
      13,    14,    15,    16,    17,    18,    19,    20,    21,  1149,
     117,    23,    29,  1569,  2612,   607,   608,   609,   610,   611,
     612,   613,   614,   615,   616,   464,  1620,    29,  1555,   482,
     492,   470,   650,   472,  1243,   266,  1561,   476,  1264,   678,
     479,  2715,  1564,   482,   925,  1187,  2609,     5,  2630,  2787,
    2632,  2985,  1604,   492,  2636,  2961,  2638,  1140,    71,    72,
      73,    74,    75,    76,  2364,  1130,  2191,  2797,  2650,   531,
    1664,   877,   511,  3007,    87,    88,    89,  1671,  1215,  2362,
     519,   520,   521,  1062,  2346,   228,   525,  2008,   231,  1015,
    1366,  1766,  2771,  2675,   533,    29,  1944,  2679,   560,  2681,
    3045,  1343,  3009,  1978,  2519,  2899,  2396,   569,  1670,   548,
    2009,  3045,  2694,  2418,  2675,  3049,  2431,  2699,  2375,  2377,
    2015,  2025,  2632,  2915,   824,  2816,   731,  2307,  2836,  1282,
    1724,  2433,    17,    18,  2249,    20,   954,  2835,    23,    24,
      25,  2753,  2245,  2558,  3007,  2738,  2919,  2876,  1278,   950,
    1145,  2565,  1702,   362,    -1,    -1,  2738,    -1,    43,   859,
      -1,  2743,    -1,    -1,    -1,   865,    -1,   101,   102,    -1,
     104,   105,    -1,    -1,    -1,   109,    -1,   877,    -1,  2761,
      -1,    -1,   882,    -1,    -1,  2767,    -1,    -1,    -1,  2771,
    2772,    -1,   126,   127,    -1,    -1,    -1,  2779,    -1,    14,
      15,    16,    17,    18,    19,    20,    21,   350,    -1,    -1,
     144,   145,    -1,    -1,    -1,   228,    -1,    -1,   231,     7,
    2802,    -1,   365,    -1,    -1,    -1,   369,    -1,    -1,    17,
      18,    19,    20,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  2824,    -1,  2826,    -1,    -1,  2829,    -1,    -1,
      -1,    -1,  2834,    -1,  2836,    -1,    71,    72,    73,    74,
      75,    76,  1856,  1857,   407,    -1,    -1,    -1,    -1,   708,
      -1,  1865,    87,    88,    89,    -1,    -1,    -1,    -1,  1835,
    1836,   239,    -1,    71,    72,    73,    74,    75,    76,    -1,
    1846,    -1,   435,    -1,  2876,    -1,    -1,    -1,    -1,  2881,
      -1,  2883,    -1,  2885,    -1,    -1,    -1,    -1,    -1,  2891,
      -1,   454,  2894,    -1,    -1,    -1,    -1,  2899,    -1,    -1,
     278,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  2915,    -1,    -1,  2918,   350,   777,   297,
    1896,  1897,  1898,  1899,    -1,    -1,    -1,    -1,    -1,  2931,
      -1,    -1,   365,    -1,    -1,  1911,   369,  1951,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  2956,  2957,    -1,    -1,   336,    -1,
      -1,   820,  2964,    -1,    -1,    -1,    -1,    -1,   273,    -1,
     348,    -1,   535,    -1,   407,   834,   835,   836,    -1,   838,
     358,   840,   841,  2985,    -1,    -1,    -1,   846,   847,    -1,
      -1,    -1,    -1,   228,    -1,    -1,   231,    -1,   376,  2013,
      -1,  2015,   435,  3005,    -1,  3007,    -1,  3009,   386,    -1,
      -1,  1987,  1988,  1133,  1134,  1135,    -1,    -1,  1994,  1995,
      -1,   454,    -1,    -1,   402,    -1,    -1,    -1,    -1,    -1,
      -1,   890,    -1,  1153,    -1,    -1,    -1,    -1,    -1,   602,
      -1,  2055,   901,  3045,    -1,    -1,    -1,  3049,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2893,    -1,
    3062,    -1,    -1,    -1,   442,   924,   925,    -1,    -1,   374,
    1190,    -1,    -1,    -1,   933,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   389,    -1,    -1,    -1,   466,    -1,
     949,   950,    -1,    -1,    -1,  1215,    -1,    -1,    -1,    -1,
      -1,   406,   535,   481,   409,    -1,    -1,    -1,    -1,    -1,
     488,    -1,  1232,   491,    -1,   350,   421,   422,    -1,    -1,
      -1,    -1,  1242,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     365,    -1,    -1,   511,   369,    -1,   514,    -1,   516,    -1,
      -1,    -1,    -1,    -1,    -1,   450,    -1,    -1,    -1,  1008,
    2126,  2127,    -1,    -1,    -1,    -1,    -1,   535,   463,  2135,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  2143,    -1,   602,
     475,    -1,   407,    -1,    -1,   553,  2190,  2191,  2192,  2193,
    2194,  2195,    -1,    -1,    -1,  2161,  2162,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     435,    -1,    -1,    -1,    -1,    -1,    -1,   714,   715,    -1,
      -1,   516,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   454,
      -1,    -1,    -1,   730,    -1,    -1,    -1,    -1,    -1,   736,
     737,    -1,    -1,    -1,   741,  2249,    -1,  2213,    -1,  2215,
      -1,    -1,    -1,    -1,   751,    -1,  2222,    -1,  2224,    -1,
     555,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1120,   567,    -1,    -1,    -1,    -1,    -1,    -1,  1128,
      -1,  1130,  1131,  1132,   579,   580,   581,    -1,    -1,    -1,
    1139,  1140,    -1,   588,  1143,    -1,   591,    -1,  1147,    -1,
      -1,  1150,    -1,    -1,   599,    -1,    -1,    -1,    -1,    -1,
     535,    -1,    -1,    -1,  1163,    -1,    -1,    -1,    -1,    -1,
    2324,  2325,  2326,    -1,  2328,  2329,  2330,  2331,  2332,  2333,
      -1,    -1,    -1,  2337,    -1,    -1,    -1,    -1,    -1,    -1,
    1189,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2314,  2315,
      -1,    -1,  2318,  2319,    -1,  1465,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    29,
      -1,  2375,    -1,  2377,    -1,    -1,    -1,   602,    -1,  1489,
    1229,    -1,    -1,  1493,  2388,    -1,  2352,    -1,    -1,  2393,
      -1,    -1,    -1,    -1,    54,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1252,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1523,  1263,  1264,    -1,    -1,    -1,    -1,
      -1,     5,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    -1,  1549,
      -1,   101,   102,    -1,   104,   105,    -1,    -1,    -1,   109,
      -1,    -1,    -1,    -1,    17,    18,    -1,    20,    -1,    -1,
      23,    24,    25,    -1,    -1,    -1,   126,   127,    -1,  1318,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      43,    -1,    -1,    -1,   144,   145,  2490,    71,    72,    73,
      74,    75,    76,    -1,    -1,    -1,    -1,    -1,  2464,    -1,
      -1,   239,  2468,    87,    88,    89,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  2518,    -1,  2520,  2521,  2522,  2523,
      -1,    -1,    -1,  1372,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1030,  2500,    -1,    -1,    -1,    -1,    -1,
     278,  1038,    -1,    -1,  1041,    -1,    -1,  2551,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   215,    -1,  1054,    -1,   297,
      -1,  1058,    -1,    -1,    -1,    -1,    -1,  2533,    -1,  1066,
      -1,  1068,  1069,    -1,  1071,  1072,  1073,  1074,  1075,  1076,
    1077,  1078,  1079,  1080,  1081,  1082,  1083,  1084,  1085,  1086,
    1087,    -1,    -1,    -1,    -1,    -1,  1706,    -1,   336,    -1,
      -1,  1098,  1099,    -1,    -1,    -1,  1103,    -1,  1105,    -1,
     348,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     358,    -1,    -1,    -1,    -1,    -1,  2630,    -1,  2632,    -1,
      -1,    -1,  2636,  2637,  2638,    -1,    -1,    -1,   376,    -1,
      -1,    -1,    -1,    -1,   228,    -1,    -1,   231,   386,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1770,  1771,  1772,  1773,   402,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1521,    -1,    -1,   335,    -1,    -1,    -1,    -1,
      -1,  1530,    -1,    -1,  1794,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1541,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   442,    -1,    -1,    -1,    -1,    -1,
     273,    -1,  1561,    -1,    -1,  2719,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   384,    -1,    -1,    -1,   466,    -1,
      -1,    -1,    -1,    -1,  2738,    -1,    -1,    -1,    -1,  2743,
      -1,  1851,    -1,   481,    -1,    -1,    -1,    -1,    -1,  1598,
     488,  1600,    -1,   491,    -1,  1604,   416,    -1,    -1,    -1,
      -1,    -1,    -1,  2767,  2730,    -1,   350,    -1,  2772,    -1,
      -1,    -1,    -1,   511,    -1,    -1,   514,    -1,   516,    -1,
      -1,   365,    -1,    -1,    -1,   369,    -1,  1636,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   535,  2802,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   374,    -1,    -1,    -1,   553,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   407,    -1,  2829,   389,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   406,    -1,    -1,   409,    -1,    -1,    -1,
      -1,   435,    -1,    -1,    -1,  1965,  1705,  1967,   421,   422,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     454,    -1,    -1,    -1,    -1,    -1,    -1,  2881,    -1,  2883,
      -1,  2885,    -1,    -1,    -1,    -1,    22,    -1,    -1,    -1,
    2894,    -1,    -1,  1390,    -1,  2861,    -1,    -1,    -1,    -1,
     463,    -1,    -1,    -1,    -1,    41,    -1,    -1,    -1,    -1,
      -1,  2915,   475,    -1,  2918,  2919,    -1,    -1,  1767,    -1,
    1769,    -1,  1419,  1420,  1421,    -1,  1423,  2931,    -1,  1778,
      -1,    -1,    -1,    -1,    70,    -1,    -1,    -1,  2904,  2905,
      -1,  2907,    -1,  2909,  2910,    -1,    -1,    -1,    -1,    -1,
      -1,   535,  1449,   516,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1816,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   112,    -1,    -1,    -1,
      -1,  2985,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   555,    -1,    -1,    -1,  1845,    -1,    -1,    -1,
      -1,    -1,    -1,  3007,   567,  2115,   142,  2973,  2118,    -1,
     146,    -1,    -1,    -1,    -1,    -1,   579,   580,   602,    -1,
      -1,    -1,    -1,    -1,    -1,   588,    -1,  2993,   591,  2995,
      -1,  1528,    -1,    -1,   170,    -1,   599,  1534,    -1,    -1,
      -1,  3045,   178,    -1,   180,  3049,  1543,    -1,    -1,    -1,
      -1,    -1,    -1,   189,    -1,    -1,    -1,    -1,    -1,   195,
      -1,    -1,    -1,    -1,    -1,  2175,  3032,   203,    -1,    -1,
      -1,   207,    -1,  3077,    -1,    -1,    -1,   213,    -1,    -1,
      -1,   217,   218,   219,   220,    -1,    -1,    -1,    -1,    -1,
    3056,  3057,    -1,    -1,  3060,    -1,   232,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    -1,    -1,   249,    -1,    -1,   252,    -1,   254,    -1,
      -1,    -1,    -1,    -1,    -1,   261,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1985,    -1,   274,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   284,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      71,    72,    73,    74,    75,    76,    -1,   303,   304,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    87,    88,    89,    -1,
      -1,    -1,   318,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     326,    -1,    -1,    -1,   330,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   339,   340,   341,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  2065,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
    2109,    -1,    -1,  1760,    -1,  1762,    -1,    -1,    -1,    -1,
      -1,    -1,   408,    -1,    -1,    -1,    -1,    -1,    17,    18,
      19,    20,    -1,   419,    -1,    -1,    -1,    26,    -1,    -1,
      -1,    -1,    -1,  2142,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  2151,    -1,  2153,    -1,  2155,    -1,    -1,    71,
      72,    73,    74,    75,    76,    -1,    -1,   228,  2167,    -1,
     231,    -1,    -1,    -1,   460,    87,    88,    89,    -1,    -1,
      -1,    -1,    71,    72,    73,    74,    75,    76,    -1,    -1,
      -1,    -1,    -1,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    -1,
      -1,    -1,    -1,    -1,  2474,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    -1,    -1,    -1,    -1,   521,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  2504,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    71,    72,
      73,    74,    75,    76,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   557,  2532,    -1,    87,    88,    89,    -1,    -1,    -1,
      71,    72,    73,    74,    75,    76,    -1,    -1,    -1,   350,
      -1,    -1,    -1,    -1,    -1,    -1,    87,    88,    89,    -1,
      -1,    -1,    -1,    -1,   365,    -1,    -1,    -1,   369,  2308,
      17,    18,    19,    20,    21,    -1,   228,    -1,   604,   231,
      -1,    -1,    17,    18,    -1,    20,    -1,    -1,    23,    24,
      25,    -1,   618,   619,   620,   621,   622,   623,   624,    -1,
     626,   627,    -1,    -1,    -1,    -1,   407,    -1,    43,  2348,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   643,    -1,    -1,
      -1,    -1,  2361,    -1,    71,    72,    73,    74,    75,    76,
     259,    -1,    -1,    -1,   435,    -1,    -1,    -1,    -1,    -1,
      87,    88,    89,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   454,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     299,   300,   301,    -1,    -1,   228,    -1,    -1,   231,    -1,
      -1,    -1,    -1,  2422,    -1,    -1,    -1,  2074,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   324,    -1,   228,   350,  2699,
     231,    -1,    -1,   332,    -1,    -1,    -1,    -1,   337,    -1,
      -1,  2450,    -1,   365,    -1,    -1,    -1,   369,    -1,    -1,
      -1,    -1,    -1,   352,    -1,    -1,  2465,    -1,   357,    -1,
     359,    -1,    -1,    -1,   535,    -1,    -1,   366,    -1,    -1,
     369,    -1,    -1,   372,    -1,    -1,   375,    -1,    -1,   378,
      -1,  2490,    -1,    -1,   383,   407,    -1,    -1,    -1,    -1,
    2147,    -1,    -1,  2150,    -1,    -1,    -1,  2506,    -1,    -1,
      -1,  2158,   401,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   228,    -1,   435,   231,    -1,    -1,    -1,   417,    -1,
      -1,   420,   421,    -1,    -1,    -1,    -1,   350,   427,    -1,
      -1,   602,   454,    -1,    -1,    -1,    -1,    -1,    -1,   438,
      -1,    -1,   365,    -1,    -1,    -1,   369,   370,    -1,   350,
      -1,    -1,    -1,    -1,    -1,   454,    -1,    -1,  2567,    -1,
      -1,    -1,   461,    -1,   365,    -1,    -1,    -1,   369,   468,
      -1,    -1,   471,   472,   473,    -1,   475,   476,    -1,    -1,
      -1,    -1,    -1,    -1,   407,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   492,    -1,    -1,    -1,    -1,    -1,    -1,
    2609,    -1,    -1,    -1,    -1,    -1,   407,    -1,    -1,    -1,
      -1,    -1,   435,   535,    -1,    -1,   515,   516,   517,   518,
      -1,   520,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   454,    -1,   350,   435,    -1,    -1,    -1,   537,   538,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   365,    -1,
      -1,    -1,   369,   454,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   560,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   374,
     569,   570,    -1,   572,    -1,    -1,    -1,    -1,    -1,    -1,
     602,    -1,    -1,    -1,   389,    -1,  2956,    -1,  2697,    -1,
     407,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   406,    -1,    -1,   409,  2714,  2715,    -1,    -1,    -1,
    2719,    -1,   535,    -1,    -1,    -1,    -1,   422,   435,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   535,   634,    -1,   454,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    -1,    -1,    -1,   462,   463,    -1,
      -1,    -1,    -1,    -1,  2773,    -1,    -1,    -1,    -1,    -1,
     475,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2787,   602,
      -1,    -1,    -1,  2792,    -1,  2794,  2443,    -1,    -1,    -1,
      -1,    -1,  3062,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   602,    -1,    71,    72,    73,    74,    75,    76,    -1,
      -1,   516,    -1,    -1,    -1,    -1,    -1,    -1,   535,    87,
      88,    89,    -1,    -1,    -1,    -1,  2835,    -1,    -1,    -1,
      -1,    -1,  2841,    -1,    -1,    -1,    -1,  2494,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     555,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   567,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   579,   580,    29,    -1,    -1,    -1,
      33,    34,    -1,   588,    -1,   602,   591,    -1,    -1,    -1,
      -1,    -1,    -1,    46,   599,    48,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    62,
      -1,    -1,    -1,    -1,    -1,    -1,    69,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    80,    81,    82,
      -1,    -1,    -1,    -1,    -1,    -1,  2945,  2946,  2947,  2948,
    2949,  2950,    -1,    96,    -1,    98,    99,   100,   101,   102,
     103,   104,   105,   106,    -1,   108,   109,   110,   111,    -1,
     228,    -1,    -1,   231,   117,    -1,    -1,   120,    -1,   122,
     123,   124,    -1,   126,   127,    -1,    -1,    -1,    -1,   132,
      -1,   134,   135,    -1,   137,    -1,   139,   140,    -1,    -1,
     143,   144,   145,    -1,    -1,   148,   149,   150,    -1,   152,
     153,    -1,    -1,    -1,   157,   158,    -1,   160,    -1,    -1,
      -1,   164,    -1,   166,   167,    -1,    -1,    -1,    -1,   172,
      -1,    -1,    -1,   176,    -1,    -1,   179,    -1,   181,    -1,
     183,    -1,   185,    -1,   187,   188,    -1,   190,   191,   192,
      -1,    -1,    -1,   196,    -1,   198,   199,    -1,   201,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   209,   210,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  3077,   222,
      -1,    -1,   225,   226,    -1,    -1,   229,   230,    -1,    -1,
     233,   234,   350,    -1,    -1,    -1,    -1,    -1,    -1,   242,
     243,   244,    -1,   246,    -1,    -1,    -1,   365,    -1,    -1,
      -1,   369,   370,   256,   257,   258,    -1,   260,    -1,    -1,
      -1,   264,   265,    -1,    -1,    -1,   269,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   277,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   285,   286,   287,    -1,    -1,    -1,    -1,   407,
     293,   294,    -1,    -1,    -1,    -1,   299,    -1,    -1,   302,
      -1,    -1,    -1,   306,   307,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   317,    -1,    -1,   435,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   335,    -1,    -1,    -1,   454,    -1,    -1,    -1,
     343,    -1,    -1,    -1,    -1,    -1,   349,    -1,    -1,    -1,
      -1,    -1,    -1,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,   372,
      -1,    -1,    -1,    -1,    -1,    -1,   379,    -1,   381,   382,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   390,    -1,    -1,
      -1,    -1,    -1,    -1,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   535,    71,    72,
      73,    74,    75,    76,    -1,    -1,   429,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    87,    88,    89,   440,    -1,    -1,
      -1,   444,    -1,    -1,    -1,   448,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  2964,    -1,    71,
      72,    73,    74,    75,    76,    -1,    -1,    -1,    -1,   472,
     473,    -1,    -1,    -1,   477,    87,    88,    89,    -1,    -1,
      -1,    -1,    -1,    -1,   602,    -1,   489,    -1,    -1,    -1,
      -1,    -1,   495,   496,   497,   498,    -1,    -1,   501,    -1,
      -1,    -1,   505,    -1,    -1,    -1,    -1,    -1,    -1,   512,
     513,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   524,    -1,   526,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   537,    -1,   539,    -1,    -1,   542,
      -1,    -1,    -1,    -1,    -1,   548,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   574,    -1,    -1,   577,   228,    -1,    -1,   231,    -1,
     583,    -1,    -1,   586,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   601,    -1,
      -1,    -1,    -1,    -1,    -1,   608,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   228,    -1,    -1,   231,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   631,   632,
     633,   634,   635,   636,   637,    -1,    -1,   640,    -1,   642,
      -1,   644,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    -1,    -1,    -1,   350,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   365,    -1,    -1,    -1,   369,   370,    71,    72,
      73,    74,    75,    76,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    87,    88,    89,    -1,   350,    -1,
      -1,    -1,    -1,    71,    72,    73,    74,    75,    76,    -1,
      -1,    -1,    -1,   365,   407,    -1,    -1,   369,   370,    87,
      88,    89,    -1,    -1,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      -1,    -1,   435,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   407,    -1,    -1,    -1,    -1,
      -1,   454,    -1,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    -1,
      -1,    -1,    -1,   435,    -1,    -1,    -1,    -1,    -1,    71,
      72,    73,    74,    75,    76,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   454,    -1,    -1,    87,    88,    89,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    -1,    -1,    -1,    -1,    -1,    71,    72,
      73,    74,    75,    76,    -1,   228,    -1,    -1,   231,    -1,
      -1,    -1,   535,    -1,    87,    88,    89,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     228,    -1,    -1,   231,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    71,    72,    73,    74,    75,    76,    -1,    -1,
      -1,    -1,    -1,   535,    -1,    -1,    -1,    -1,    87,    88,
      89,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   602,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      -1,    -1,    -1,    -1,    -1,    -1,   228,    -1,    -1,   231,
     602,    -1,    -1,    -1,    -1,    -1,    -1,   350,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      -1,    -1,   365,    -1,    -1,    -1,   369,   370,    -1,    -1,
      -1,    -1,   350,    -1,    -1,   228,    -1,    -1,   231,    71,
      72,    73,    74,    75,    76,    -1,    -1,   365,    -1,    -1,
      -1,   369,   370,    -1,    -1,    87,    88,    89,    -1,    -1,
      -1,    -1,    -1,    -1,   407,    -1,    -1,    -1,    -1,    71,
      72,    73,    74,    75,    76,    -1,    -1,    -1,    -1,   228,
      -1,    -1,   231,    -1,    -1,    87,    88,    89,    -1,   407,
      -1,    -1,   435,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   454,    -1,    -1,    -1,    -1,    -1,   435,   350,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   365,    -1,    -1,   454,   369,   370,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   350,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   365,    -1,    -1,   407,   369,   370,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   535,    -1,    -1,    -1,   228,    -1,    -1,   231,
      -1,   350,    -1,   435,    -1,    -1,    -1,    15,    16,    17,
      18,    19,    20,    21,   407,    -1,   365,   535,    -1,    -1,
     369,    -1,   454,    -1,    -1,    -1,   228,    -1,    -1,   231,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    -1,   435,    -1,    -1,    -1,    -1,    21,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   407,   602,
      -1,   454,    -1,    71,    72,    73,    74,    75,    76,    -1,
      -1,    -1,    16,    17,    18,    19,    20,    21,    -1,    87,
      88,    89,    -1,    -1,   602,    -1,   435,    -1,    -1,    -1,
      71,    72,    73,    74,    75,    76,    -1,    71,    72,    73,
      74,    75,    76,   535,    -1,   454,    87,    88,    89,    -1,
      -1,    -1,    -1,    87,    88,    89,    -1,    -1,   350,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    71,    72,    73,
      74,    75,    76,   365,    -1,    -1,    -1,   369,    -1,    -1,
      -1,    -1,   535,    87,    88,    89,    -1,    -1,   350,    -1,
      -1,    17,    18,    -1,    -1,    -1,    -1,    23,    24,    25,
      26,    -1,    -1,   365,    -1,    -1,    -1,   369,    -1,    -1,
     602,    -1,    38,    -1,    -1,   407,    -1,    43,    44,    -1,
      -1,    -1,    -1,    -1,    50,    -1,   535,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   435,    -1,   407,    -1,    -1,    -1,   602,
      -1,    -1,    78,    -1,    -1,    -1,    -1,    -1,    17,    18,
     228,    -1,   454,   231,    23,    24,    25,    26,    -1,    -1,
      -1,    -1,    -1,   435,    -1,    -1,    -1,    -1,    -1,    38,
      -1,    -1,    -1,    -1,    43,    44,    -1,   228,    -1,    -1,
     231,    50,   454,   602,   228,    -1,    -1,   231,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    78,
      -1,    -1,    -1,    -1,   228,    17,    18,   231,    -1,    -1,
      -1,    23,    24,    25,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   535,    -1,   171,    38,    -1,    -1,    -1,
      -1,    43,    44,    -1,    -1,    -1,    -1,    -1,    50,    -1,
      -1,    71,    72,    73,    74,    75,    76,    -1,    -1,    -1,
      -1,    -1,    -1,   535,    -1,    -1,    -1,    87,    88,    89,
      -1,    -1,   350,    -1,    -1,    -1,    78,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   365,    -1,    -1,
      -1,   369,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   350,
     602,    -1,   171,    -1,    -1,    -1,   350,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   365,    -1,    -1,    -1,   369,    -1,
      -1,   365,    -1,    -1,    -1,   369,    -1,    -1,    -1,   407,
     602,    -1,   268,    -1,    -1,    -1,   350,   273,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   365,    17,    18,    -1,   369,   407,   435,    23,    24,
      25,    -1,    -1,   407,    -1,   301,    -1,    -1,    -1,   171,
      -1,    -1,    -1,    38,    -1,    -1,   454,    -1,    43,    44,
      -1,    -1,    -1,    -1,   435,    50,    -1,    -1,    -1,    -1,
      -1,   435,    -1,   407,    -1,    -1,    -1,    -1,    -1,   268,
     336,    -1,    -1,   454,   273,    -1,    -1,    -1,   228,    -1,
     454,   231,   348,    78,    -1,    -1,    -1,    -1,    -1,    17,
      18,   435,    20,    -1,    -1,    23,    24,    25,    -1,    -1,
     366,    -1,   301,    -1,    -1,   371,    -1,    -1,   374,    -1,
     454,    -1,    -1,    -1,    -1,    43,    -1,    -1,    -1,   385,
      -1,    -1,    -1,    -1,    -1,   391,    -1,   535,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   401,   268,   336,    -1,    -1,
     406,   273,    -1,   409,    -1,    -1,   412,    -1,    -1,   348,
      -1,    -1,    -1,    -1,   535,   421,   422,    17,    18,    -1,
      -1,   535,    -1,    23,    24,    25,    -1,   366,    -1,   301,
      -1,    -1,   371,    -1,    -1,   374,   171,    -1,    38,    -1,
      -1,    -1,    -1,    43,    44,    -1,   385,    -1,    -1,    -1,
      50,   535,   391,    -1,   602,    -1,   462,   463,    -1,    -1,
     350,   467,   401,    -1,   336,    -1,    -1,   406,    -1,   475,
     409,    -1,    -1,   412,    -1,   365,   348,    -1,    78,   369,
     486,   602,   421,   422,    -1,    -1,   492,    -1,   602,    -1,
      -1,    -1,    -1,    -1,   366,    -1,    -1,    -1,    -1,   371,
      -1,    -1,   374,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     516,    -1,    -1,   385,    -1,    -1,    -1,   407,   602,   391,
      -1,    -1,    -1,    -1,   463,    -1,    -1,    -1,   467,   401,
      -1,    -1,    -1,   268,   406,    -1,   475,   409,   273,    -1,
     412,    -1,    -1,    -1,    -1,   435,    -1,   486,    -1,   421,
     422,    -1,    -1,   492,   560,    -1,    -1,    -1,    -1,    -1,
      -1,   567,    -1,   569,   454,    -1,   301,    -1,    -1,    -1,
      -1,   171,    -1,   579,   580,   581,    -1,   516,    -1,    -1,
      -1,    -1,   588,    -1,    -1,   591,    -1,    -1,    -1,    -1,
     462,   463,    -1,   599,    -1,   467,    -1,    -1,    -1,    -1,
      -1,   336,    -1,   475,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   348,   486,    -1,    -1,    -1,    -1,    -1,
     492,   560,    -1,    -1,    -1,    -1,    -1,    -1,   567,    -1,
     569,   366,    -1,    -1,    -1,    -1,   371,    -1,    -1,   374,
     579,   580,   581,    -1,   516,   535,    -1,    -1,    -1,   588,
     385,    -1,   591,    -1,    -1,    -1,   391,    -1,    -1,    -1,
     599,    -1,    -1,    -1,    -1,    -1,   401,    -1,   268,    -1,
      -1,   406,    -1,   273,   409,    -1,    -1,   412,    -1,    -1,
      -1,    -1,    -1,    -1,    17,    18,   421,   422,   560,    -1,
      23,    24,    25,    -1,    -1,   567,    -1,   569,    -1,    -1,
      -1,   301,    -1,    -1,    -1,    38,   374,   579,   580,   581,
      43,    44,   602,    -1,    -1,    -1,   588,    50,    -1,   591,
      -1,   389,    -1,    17,    18,    -1,    20,   599,   463,    23,
      24,    25,   467,    -1,    -1,    -1,   336,    -1,   406,    -1,
     475,   409,    -1,    -1,    -1,    78,    -1,    -1,   348,    43,
      -1,   486,    -1,   488,   422,    31,    -1,   492,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   366,    -1,    -1,    -1,
     370,   371,    -1,    -1,   374,    -1,    -1,    -1,    -1,    -1,
      -1,   516,   450,    59,    60,   385,    -1,    -1,    -1,    -1,
      -1,   391,    68,    -1,   462,   463,    -1,    -1,    -1,    -1,
      -1,   401,    -1,    -1,    -1,    -1,   406,   475,    -1,   409,
      -1,    -1,   412,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   421,   422,    -1,    -1,   560,    -1,    -1,    -1,    -1,
      -1,    -1,   567,    -1,   569,    -1,    -1,    -1,   171,    -1,
      -1,    -1,    -1,    -1,   579,   580,   581,    -1,   516,    -1,
      -1,    -1,    -1,   588,    -1,    -1,   591,    -1,    -1,    -1,
      -1,    -1,    -1,   463,   599,    -1,    -1,   467,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   475,    17,    18,    -1,    -1,
      -1,    -1,    23,    24,    25,    -1,   486,   555,    -1,    -1,
      -1,    -1,   492,    -1,    -1,    -1,    -1,    38,    -1,   567,
      -1,    -1,    43,    44,    -1,    -1,    -1,    17,    18,    50,
      20,   579,   580,    23,    24,    25,   516,    -1,    -1,    -1,
     588,    -1,    -1,   591,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   599,    -1,    43,    -1,   268,    -1,    78,    17,    18,
     273,    20,    -1,    -1,    23,    24,    25,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     560,    -1,    -1,   239,    43,    -1,    -1,   567,   301,   569,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   579,
     580,   581,    -1,    -1,    -1,    -1,    -1,    -1,   588,    -1,
      -1,   591,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   599,
      -1,    -1,   278,   336,    -1,    -1,    17,    18,    -1,    20,
      -1,    -1,    23,    24,    25,   348,    17,    18,    -1,    20,
      -1,   297,    23,    24,    25,    -1,    -1,    -1,    -1,    -1,
     171,    -1,    43,   366,    -1,    -1,    -1,   313,   371,    -1,
      -1,   374,    43,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   385,    -1,    -1,    -1,    -1,    -1,   391,    -1,
     336,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   401,    -1,
      -1,    -1,   348,   406,    -1,    -1,   409,    -1,    -1,   412,
     374,    -1,   358,    -1,    -1,    -1,    -1,    -1,   421,   422,
      -1,    -1,    -1,    -1,    -1,   389,    -1,    -1,    -1,    -1,
     376,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     386,    -1,   406,    -1,    -1,   409,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   402,   268,   422,   462,
     463,    -1,   273,    -1,   467,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   475,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   486,    -1,    -1,    -1,    -1,    -1,   492,
     301,    -1,    -1,   273,    -1,    -1,   442,    -1,   462,   463,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   475,    -1,   516,    -1,    -1,    -1,    -1,    -1,    -1,
     466,    -1,    -1,    -1,    -1,   336,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   481,    -1,   348,    -1,    -1,
      -1,    -1,   488,    -1,    -1,   491,    -1,    -1,    -1,    -1,
      -1,    -1,   516,    -1,    -1,   366,    -1,   560,    -1,    -1,
     371,    -1,    -1,   374,   567,   511,   569,    -1,   514,    -1,
     516,    -1,    -1,    -1,   385,    -1,   579,   580,   581,    -1,
     391,    -1,    -1,    -1,    -1,   588,    -1,    -1,   591,   535,
     401,   555,    -1,    -1,   374,   406,   599,    -1,   409,    -1,
      -1,   412,    -1,   567,    -1,    -1,    -1,   553,    -1,   389,
     421,   422,    -1,    -1,    -1,   579,   580,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   588,   374,   406,   591,    77,   409,
      -1,    -1,    -1,    -1,    -1,   599,    -1,    -1,    -1,    -1,
     389,   421,   422,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     596,    -1,   463,    -1,    -1,    -1,   467,   406,    -1,    -1,
     409,    -1,    -1,    -1,   475,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   422,    -1,   486,    -1,    -1,   107,    -1,
      -1,   492,    -1,   463,    -1,    -1,    -1,   116,    -1,    -1,
      -1,    -1,    -1,   374,    -1,   475,   125,    -1,    -1,    -1,
      -1,   130,    -1,   374,    -1,   516,    -1,    -1,   389,    -1,
      -1,    -1,    -1,   462,   463,    -1,    -1,    -1,   389,    -1,
      -1,    -1,    -1,    -1,    -1,   406,   475,    -1,   409,    -1,
      -1,    -1,    -1,   182,    -1,   406,   516,    -1,   409,    -1,
      -1,   422,    -1,    -1,    -1,   174,    -1,    -1,    -1,   560,
      -1,   422,    -1,   182,    -1,    -1,   567,    -1,   569,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   516,   579,   580,
     581,    -1,    -1,    -1,    -1,   555,    -1,   588,    -1,    -1,
     591,   462,   463,    -1,    -1,    -1,    -1,   567,   599,   238,
      -1,    -1,   463,    -1,   475,    -1,    -1,    -1,    -1,   579,
     580,   581,    -1,    -1,   475,    -1,   555,    -1,   588,   238,
      -1,   591,    -1,    -1,   263,    -1,    -1,    -1,   567,   599,
      -1,    -1,    -1,   272,    -1,    -1,    -1,    -1,    -1,    -1,
     579,   580,    -1,    -1,   263,   516,    -1,    -1,    -1,   588,
      -1,   270,   591,   272,    -1,   516,    -1,    -1,    -1,    -1,
     599,    -1,    -1,   282,    -1,    -1,    -1,    -1,    -1,   308,
      -1,    -1,   311,    -1,    -1,    -1,    -1,   316,    -1,    -1,
      -1,    -1,    -1,    -1,   555,   324,    -1,    -1,    -1,   308,
      -1,    -1,    -1,    -1,   555,    -1,   567,   316,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   567,    -1,   579,   580,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   588,   579,   580,
     591,    -1,    -1,    -1,    -1,    -1,    -1,   588,   599,    -1,
     591,    -1,    -1,    -1,   353,    -1,    -1,    -1,   599,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   388,
      -1,    -1,    -1,    -1,    -1,    -1,   395,    -1,    -1,    -1,
     379,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   410,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   434,    -1,    -1,   417,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   428,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     459,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     469,   470,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   485,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   506,    -1,    -1,
     509,   510,    -1,    -1,    -1,    -1,   515,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   527,   528,
     529,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   540,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   572,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   582,    -1,   584,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   644
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const unsigned short yystos[] =
{
       0,    29,    54,   101,   102,   104,   105,   109,   126,   127,
     144,   145,   215,   335,   384,   416,   705,   733,   734,   784,
     952,  1007,  1009,  1010,  1011,  1016,  1018,  1031,  1032,  1033,
    1034,  1035,  1438,    27,    28,   706,   707,   708,   709,   710,
     915,   919,   334,   512,   526,   551,   600,  1439,  1439,  1439,
    1439,  1439,  1439,  1439,  1439,   915,    24,   915,  1382,  1036,
     735,   734,  1438,     0,  1008,  1011,  1016,  1034,  1438,    30,
     708,   710,    26,  1457,   915,  1441,   568,   915,  1440,   605,
     785,    24,   591,   732,   733,   903,   915,   922,  1037,  1073,
    1074,  1075,  1076,  1077,  1081,   332,   737,   738,   739,   740,
     743,   744,    39,    84,    85,    92,   346,   372,   443,   536,
     617,   625,   705,   711,   875,   951,  1012,  1013,  1015,  1019,
    1020,  1026,  1038,  1059,  1190,  1200,  1438,   920,   915,  1440,
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
    1458,  1459,  1460,  1461,  1462,   877,  1061,  1022,   599,    25,
     774,   775,   409,   776,   781,   782,   776,   409,   777,     5,
     370,     5,   370,     5,   262,     5,   786,   405,     5,     5,
     370,   370,   738,   768,  1083,   599,    25,   237,     5,   370,
       5,   370,   262,   405,     5,   370,   370,   768,   915,  1089,
    1090,  1092,  1039,  1089,   340,  1459,  1177,    33,    34,    46,
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
    1214,  1215,  1216,  1217,  1222,  1228,  1229,  1230,  1248,  1251,
    1291,  1292,  1383,  1384,  1414,  1415,  1422,  1438,  1442,  1447,
    1449,  1451,  1455,  1456,  1463,   705,  1017,  1438,   604,   627,
    1062,  1063,  1089,    20,   370,   404,   750,   773,    25,   778,
      25,    25,    25,   795,   797,   789,   753,    25,   405,    20,
     750,   409,    25,    25,   747,    25,   599,   370,     5,  1089,
     370,   915,   916,   919,   915,   910,   916,   910,    24,   591,
     915,  1102,  1433,  1434,  1435,   915,  1453,   915,  1224,  1225,
     915,    25,   652,  1073,  1220,   910,   915,  1146,   842,    25,
     923,  1185,  1186,  1185,    17,    18,    24,    25,    38,    43,
      44,    50,    78,   171,   268,   273,   301,   336,   348,   366,
     371,   374,   385,   391,   401,   406,   409,   412,   421,   422,
     463,   467,   475,   486,   492,   516,   560,   567,   569,   579,
     580,   581,   588,   817,   824,   825,   826,   827,   828,   829,
     830,   831,   843,   848,   859,   860,   861,   862,   915,   923,
    1073,  1180,  1250,  1374,   916,  1423,  1423,   803,  1146,   910,
    1218,  1073,   912,   916,   824,  1423,  1073,  1146,  1073,  1249,
    1423,    24,   564,  1056,  1057,  1073,   910,   910,  1056,   911,
     916,   915,  1057,   910,  1423,   910,   912,  1073,  1103,  1104,
     908,   916,   912,   353,   540,   646,   907,   915,   978,   915,
     713,   913,   916,  1433,  1070,   842,   916,  1129,   872,   107,
     116,   125,   130,   174,   182,   238,   263,   270,   272,   282,
     308,   316,   353,   379,   417,   428,   527,   528,   529,   540,
     644,   990,  1124,  1125,  1073,   823,   824,  1138,   819,   842,
     907,  1448,  1448,   909,   916,   842,    24,  1073,  1127,  1199,
    1073,  1176,    24,  1073,  1417,   824,  1167,  1168,  1169,  1178,
    1179,   824,  1443,    44,    83,   133,   171,   268,   344,   385,
     453,   516,   669,   848,   915,  1073,  1208,   692,   824,   908,
    1440,  1043,   824,   908,   824,  1073,  1000,   908,   824,   824,
    1185,   915,   927,   928,   912,   927,  1448,   912,   927,  1448,
     933,   927,    24,    25,   363,   466,   923,   981,  1073,  1091,
    1093,    45,   253,   323,   368,   547,   628,   629,   630,   639,
     659,   935,   937,   939,   941,   943,  1067,  1068,  1072,   314,
     325,   377,   392,   482,  1293,   619,   620,   879,   880,   881,
     915,  1064,   626,  1063,   370,   281,   370,   370,   370,   370,
     603,     5,   370,   281,   738,   758,   759,   370,   370,   603,
     370,   915,  1203,  1092,   370,  1193,    35,    36,    63,    64,
      65,   433,   520,   563,  1231,  1232,  1233,  1236,  1239,  1242,
    1243,  1244,  1245,   328,   917,  1457,   599,  1435,   437,   596,
    1121,   599,     8,   517,   566,     5,   370,   405,    24,   915,
    1368,   458,  1147,  1091,    87,    88,    89,   817,   817,   409,
     504,  1197,   409,   409,   409,   409,   409,   409,   409,   409,
     409,   409,   817,   345,   432,   449,   492,   531,   560,   569,
    1377,  1378,   409,   409,   409,   817,   817,   409,   409,   729,
     817,   409,   832,   409,   409,   409,   409,   409,   409,   409,
     817,   409,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    71,    72,
      73,    74,    75,    76,    87,    88,    89,   228,   231,   350,
     365,   369,   407,   435,   454,   535,   602,   728,   818,   833,
     835,   836,   837,   838,   839,   840,   841,    25,   923,   409,
     399,  1073,  1098,  1368,   658,   659,   806,   245,    66,    67,
     605,   438,     5,   598,   605,   597,   597,  1106,   574,   399,
       5,   535,   954,   438,   638,  1445,   409,   437,   599,   638,
     363,   715,  1073,   525,   597,  1111,  1112,  1113,   305,  1290,
     823,   822,   824,     8,   909,    25,   480,   533,   902,  1073,
     902,   902,   902,   995,   996,   902,   902,   575,   991,   659,
     991,   991,   903,   903,   991,   991,   659,     5,   312,   364,
       5,   658,   462,   820,   821,   824,     5,    55,    61,   518,
     606,   984,   641,  1446,   823,   592,   593,   594,   595,  1175,
    1177,   362,  1212,  1177,  1169,     5,   597,  1170,   824,   409,
     409,   409,   409,   409,    24,   688,   915,   409,  1417,   323,
     409,   568,   557,   693,   700,   691,    24,  1058,  1073,  1163,
       8,  1166,    13,   915,  1078,  1085,  1086,  1088,  1096,  1097,
    1140,   141,   323,   523,   556,   554,     5,   638,   638,   822,
    1091,  1098,   980,   399,     5,   129,   958,   409,  1073,   822,
     409,    25,    25,    45,  1071,    24,  1073,  1421,  1421,   909,
    1129,   909,    97,   200,   208,   214,   216,   227,   255,   271,
     276,   288,   295,   450,   457,   479,   484,  1252,  1263,  1264,
    1272,  1281,  1282,  1288,  1289,  1294,  1295,  1304,  1322,  1326,
    1394,  1395,  1424,  1425,  1428,  1429,   882,   883,    70,   878,
     889,   890,   881,  1065,  1458,  1023,   437,   786,   753,   437,
       5,   370,   760,   732,  1040,   732,   136,   275,   351,   409,
     471,  1310,  1321,   409,   915,  1247,    25,   224,   237,   409,
     455,   471,   915,  1227,  1241,  1308,  1309,  1314,  1316,  1318,
     409,   915,  1238,   409,  1227,  1234,     5,   409,   920,  1435,
    1083,  1433,   555,   596,  1122,    20,   915,  1102,  1436,   915,
    1454,  1225,   574,   599,   568,   409,   409,   806,   907,   817,
     846,   907,   907,   907,  1448,   450,  1398,   817,    24,    25,
      18,    23,    24,    25,   863,   864,   865,   866,   817,   409,
     605,   907,    20,   817,   370,  1398,   817,    20,  1180,   851,
     849,   855,   817,   853,   817,   817,   817,   817,   817,   817,
     817,   817,   817,   817,   817,   817,   817,   817,   817,   817,
     817,   817,   817,   817,   817,   409,   817,   817,   409,   844,
    1073,   605,   409,  1433,    24,   922,  1145,  1145,  1417,  1056,
     824,   824,   824,   904,   905,   409,  1073,  1104,   767,   955,
     956,   605,  1417,  1448,  1446,   915,   655,    20,   646,   915,
     978,  1073,   714,   604,   824,   329,  1115,   535,  1114,     5,
      47,    49,    51,   597,   605,   798,  1091,   873,    17,    18,
      24,   283,   289,   290,   291,   309,   417,   420,   444,   464,
     499,   518,   519,   534,   573,   606,   997,   992,  1125,   903,
     824,   323,   574,     5,   907,    25,    25,   658,   131,  1174,
     197,  1179,  1185,  1444,   678,   915,    24,   907,  1448,   568,
     907,   602,  1073,   673,   915,   824,   318,   696,   700,   557,
     694,   702,    22,   213,  1045,  1049,   461,   842,   461,  1164,
     824,   436,  1082,   919,     5,  1001,   525,  1141,  1073,   946,
     928,  1448,  1448,   938,   939,   958,   958,   249,   252,   254,
     274,   284,   326,   330,   408,   460,   643,   957,   959,   960,
     986,  1073,  1093,   525,   660,    25,   378,   944,   300,  1416,
    1416,   114,   115,   415,   525,   915,  1323,  1324,  1369,   767,
    1368,  1368,  1265,   767,   915,  1426,  1426,   338,   455,   564,
    1406,  1368,  1273,   147,   417,   428,   450,   457,  1297,  1298,
    1299,   266,   267,  1389,  1458,  1458,   363,   891,  1073,   621,
     622,   884,   885,   886,   460,   604,   623,   624,   643,   894,
     895,  1458,   732,    25,   751,   751,   759,  1204,   732,  1194,
    1312,  1368,  1246,  1321,   409,  1246,   409,   409,  1240,  1241,
     409,   409,    42,   278,   336,   348,   358,   376,   386,   389,
     402,   451,   481,   491,   511,   514,   516,   544,   553,  1360,
    1361,  1362,  1364,  1237,  1238,  1234,  1235,   643,  1232,    24,
     918,  1076,   599,   405,  1417,   555,   525,  1452,   653,   654,
     915,   915,   915,  1221,   842,   370,   685,   686,   687,   817,
     370,   370,   370,   370,  1406,   370,   370,   370,   370,   568,
     864,    18,    25,   568,   370,   370,    25,   345,   432,   449,
     492,   531,   560,   569,  1379,   370,   370,   370,   370,     5,
     730,   370,   817,   817,   817,   370,   817,   370,   370,   370,
     842,  1398,   842,  1398,   685,   915,  1219,   596,  1118,   605,
       5,     5,     5,   558,   824,   599,     5,   462,   605,   370,
     405,   409,   604,   142,   146,   249,   252,   716,   719,   720,
     986,   717,   718,   915,   409,   916,   628,   629,  1119,   824,
     915,   915,   905,   906,   488,  1448,   806,   532,  1278,    25,
      25,   409,   993,   995,  1073,   514,  1133,   820,    45,   817,
    1177,    25,  1073,  1458,   685,   370,     5,   370,   370,   689,
     915,   370,  1417,   685,   409,   701,   697,   339,   695,   824,
     318,   698,   702,   575,   988,  1050,  1046,   341,  1044,  1045,
     822,   605,  1079,   599,  1097,    13,    17,    18,    20,    24,
      25,    43,   374,   389,   406,   409,   422,   462,   463,   475,
     516,   555,   567,   579,   580,   588,   915,   923,  1142,  1143,
    1373,  1375,  1410,  1411,  1434,  1437,  1458,   940,   941,   529,
     914,   525,   907,   974,   907,   975,   967,   966,   964,   963,
     987,   417,   428,   970,   971,   417,   428,   972,   973,   303,
     960,   965,  1448,    77,   311,   324,   388,   395,   434,   459,
     469,   470,   485,   506,   509,   510,   515,   572,   584,   661,
     662,     5,    25,  1417,   227,   450,  1399,  1400,  1417,  1129,
    1393,  1395,    79,    79,   574,  1127,  1325,  1326,   409,  1305,
     128,   504,  1330,  1337,  1368,   154,   250,  1430,   599,   605,
    1407,  1408,  1410,  1253,   320,   329,   353,   356,   374,   480,
     533,   540,   909,  1275,  1280,   409,  1300,   604,     5,    24,
     915,  1390,  1391,   893,  1073,     5,   525,   887,   888,   618,
     886,   892,   915,   892,   896,   897,   892,   303,   895,  1024,
     405,   405,   439,  1187,  1207,  1041,   439,  1150,  1181,   409,
       5,   370,   273,   409,   421,   581,  1340,  1341,  1342,  1343,
    1344,  1345,  1352,  1356,  1358,  1405,  1410,   370,   915,  1311,
    1313,  1368,  1371,  1315,  1371,     5,   370,  1315,  1340,   345,
     432,   449,   492,   531,   560,   569,  1380,  1380,   409,   409,
     409,   409,   409,   409,   186,   378,  1317,  1319,     5,   370,
       5,   370,   915,   370,  1436,     8,  1417,   824,     5,  1226,
    1227,   842,  1030,   847,     5,  1407,   857,  1378,   857,    25,
      25,   568,    23,    25,   770,   858,  1197,   370,   409,  1197,
     771,   370,  1197,   852,   850,   856,  1197,   854,  1197,  1197,
    1197,   817,   834,   370,   834,   370,   845,   599,  1226,   555,
    1417,  1417,   824,   824,   904,   488,   824,  1450,     5,    20,
    1371,   956,  1417,   599,   915,   717,   725,   724,   726,   915,
     921,   727,   921,   170,   720,   723,     5,   958,   599,   824,
       8,   915,  1279,   874,   994,   995,  1073,     5,   304,   679,
    1209,   323,   323,   437,   599,   323,   409,   674,   671,  1458,
    1458,   703,   699,   695,   989,    24,   914,  1051,  1073,  1458,
     824,   404,    20,   915,  1087,   842,    25,   923,    25,   923,
    1376,  1380,  1410,   409,   409,   919,   409,   409,   409,   409,
     409,     5,    17,    18,    19,    20,    71,    72,    73,    74,
      75,    76,  1431,   399,    41,   521,   947,   942,   943,    25,
     658,   915,     5,   961,     5,   962,  1458,  1458,  1458,  1458,
     993,     5,   969,     5,   968,  1458,   914,     5,   370,    25,
    1368,   919,  1387,   574,   574,  1264,  1392,  1393,  1326,  1306,
    1371,   596,   909,  1340,   409,  1268,   915,  1427,  1426,     5,
    1396,   259,   299,   300,   301,   324,   332,   337,   352,   357,
     359,   366,   369,   372,   375,   378,   383,   401,   417,   420,
     421,   427,   438,   454,   461,   468,   471,   472,   473,   475,
     476,   492,   515,   516,   517,   518,   520,   537,   538,   560,
     569,   570,   572,   634,   924,  1457,   562,   824,   824,  1274,
     909,  1301,  1371,  1368,  1299,   599,   599,     5,     5,  1073,
     892,  1458,  1458,     5,   899,   900,  1458,  1458,   898,  1017,
     790,   748,    52,    53,    56,    57,    58,   156,   163,   197,
     206,   235,   236,   280,   322,   378,   607,   608,   609,   610,
     611,   612,   613,   614,   615,   616,  1184,  1188,   113,   493,
    1189,  1205,  1017,   138,   155,   156,   163,   197,   206,   235,
     280,   322,  1182,  1183,  1195,  1189,  1313,  1321,   409,  1405,
     450,  1340,  1410,  1405,  1343,     6,   370,     7,     9,    11,
      12,    13,    14,    15,    16,   231,   350,   535,  1357,   407,
     581,   602,  1355,  1357,   437,  1370,   370,     5,   919,     5,
     370,  1241,   370,   370,   605,   409,   605,    25,  1366,  1366,
      25,  1366,  1366,    25,  1365,    24,  1373,  1320,  1321,  1238,
    1234,  1417,     8,   654,     5,   370,   822,   370,   370,   687,
     525,  1331,  1336,   605,   370,    25,   568,    25,   605,   370,
     370,   370,   370,     5,   370,   370,   370,    20,   370,  1417,
       5,   824,   545,   253,   663,   664,   824,    20,   915,   370,
     958,  1458,  1458,     5,   721,   437,   599,     5,   722,  1458,
     718,   525,    20,   915,     5,   915,  1109,   368,   638,  1073,
    1094,  1095,  1458,     5,   370,   914,   817,   370,   685,  1073,
     670,   652,   915,  1073,   676,   370,   685,  1458,  1458,   993,
    1048,    24,  1052,  1073,   550,   870,   437,   462,   823,  1002,
     605,   370,   374,  1371,  1432,   338,   455,   564,  1359,   409,
    1359,  1359,  1359,  1359,  1410,  1412,  1143,  1410,  1410,  1410,
    1410,  1434,   949,   948,   419,   934,   935,   599,   907,  1458,
     907,  1458,   971,  1458,   973,  1458,   658,   662,   370,   409,
    1418,  1406,  1389,  1393,  1393,  1385,     5,   370,   450,  1404,
    1269,  1371,   458,  1266,  1404,   605,  1408,   532,  1403,    20,
     409,  1256,  1257,  1258,  1259,  1371,   532,  1276,     5,   370,
     605,   915,   915,  1391,  1073,   915,  1458,  1458,  1458,  1458,
     603,   603,  1185,  1185,  1185,    24,  1185,  1185,  1185,  1185,
    1185,  1185,    24,    24,  1185,  1188,  1073,  1099,  1100,   598,
     425,  1151,  1458,    24,    24,    25,    25,    25,    25,    25,
      24,  1073,  1183,  1151,   370,   919,   370,  1341,  1342,  1410,
     409,  1405,   409,  1405,   228,   365,   367,   535,   409,   549,
     564,   565,  1346,  1347,  1348,  1405,  1410,    25,  1310,  1371,
     599,  1371,   345,   432,   449,   492,   531,   560,   569,  1381,
      25,  1381,     5,  1363,  1363,     5,   370,   370,  1363,   370,
    1320,  1417,  1227,   247,  1223,   494,  1332,  1333,  1334,  1368,
    1337,   310,   493,   503,  1283,  1401,  1379,   857,   568,    23,
      25,   370,   774,   817,   447,   805,     5,   352,  1417,     5,
     409,   370,   529,   985,   921,  1458,   655,    20,   915,   921,
    1458,  1448,   824,  1448,   399,     5,   219,   995,   658,   323,
     683,  1210,  1091,   405,   685,   675,   370,  1458,   914,   824,
     868,  1083,  1381,     5,  1380,     5,   370,  1410,   919,  1410,
    1410,  1410,  1410,     5,   370,   824,  1458,   936,   937,    20,
     915,  1419,  1420,  1407,  1388,  1386,  1389,  1371,   919,   118,
    1307,     5,   370,  1267,  1427,  1094,  1397,    13,  1258,  1260,
    1254,     5,    13,  1277,  1371,   441,  1302,  1303,  1369,   599,
     189,  1025,   786,   760,   517,   566,  1101,     5,  1099,    40,
     112,   178,   180,   195,   203,   207,   232,  1152,  1153,  1206,
    1025,  1196,  1406,  1353,  1354,  1373,  1437,  1353,  1410,  1350,
    1373,  1413,  1405,     5,   405,    20,   915,   370,    25,  1367,
     370,   370,    25,   370,   409,  1334,     5,   915,  1372,   347,
    1328,  1338,   915,  1402,   598,  1359,   310,    23,    25,   907,
     658,   352,  1417,   824,   665,   547,  1107,    25,   658,   405,
     985,   370,  1073,  1095,  1131,  1091,   370,   409,   677,   683,
     672,  1047,  1458,   405,  1380,   605,  1380,   370,  1412,   370,
     370,   370,   370,  1410,   554,   914,     5,   370,  1403,  1389,
    1389,  1406,  1371,   409,  1336,   409,   462,  1261,  1262,  1405,
    1410,     5,   370,   128,   504,  1255,  1259,  1262,  1094,     5,
     119,  1296,   915,  1100,  1154,  1155,  1073,  1157,  1073,  1156,
    1158,  1153,   218,   218,  1407,     5,   370,   370,     7,   420,
    1349,    25,  1370,   605,   370,  1333,  1335,  1333,  1329,  1409,
    1410,   426,  1327,  1339,  1223,    25,  1284,  1285,  1286,  1371,
    1399,  1402,   804,  1417,   371,   182,   238,   263,   272,   308,
     316,   410,   582,   662,   666,   667,   409,   599,   658,   986,
    1134,  1135,  1136,  1211,   680,   370,   683,  1458,   869,   605,
    1381,   605,   370,   950,   982,  1420,  1336,  1407,   462,  1270,
    1271,  1410,  1401,  1261,  1410,     5,  1258,    13,   909,  1340,
    1303,  1458,  1458,  1159,  1458,  1160,  1458,  1458,  1336,  1354,
    1410,  1351,  1413,   405,  1381,     5,   370,     5,  1340,     5,
     517,   566,  1287,  1223,   326,   330,   807,   808,   809,   986,
     902,   902,   902,   902,   902,   902,    24,     5,   370,   824,
      20,   915,  1137,   261,  1136,   683,   685,   683,   220,  1381,
    1381,  1458,   658,  1401,  1336,     5,   370,   370,  1262,   409,
    1458,  1458,   370,  1333,  1409,  1285,   811,   810,   217,   809,
     812,   667,     5,  1458,   681,   947,  1271,  1261,  1458,  1458,
    1458,   824,   370,   370,   370,   682,   141,   323,   684,  1091
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
#line 880 "fgl.yacc"
    { print_screen_mode(0);}
    break;

  case 3:
#line 883 "fgl.yacc"
    { print_screen_mode(1);}
    break;

  case 4:
#line 887 "fgl.yacc"
    {
		print_start_server(yyvsp[-3].str,yyvsp[0].str);
	}
    break;

  case 5:
#line 893 "fgl.yacc"
    {
	print_stop_external();
	}
    break;

  case 6:
#line 898 "fgl.yacc"
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
#line 910 "fgl.yacc"
    {
	sprintf(yyval.str,"%s%s",yyvsp[-2].str,yyvsp[0].str);
	}
    break;

  case 10:
#line 915 "fgl.yacc"
    {
	print_remote_func(yyvsp[0].str);
	sprintf(yyval.str,"unregister_func(\"%s\",aclfgl_%s);\n",yyvsp[0].str,yyvsp[0].str);
	addmap("Call Remote",yyvsp[0].str,curr_func,yylineno,infilename);
	}
    break;

  case 11:
#line 933 "fgl.yacc"
    {sprintf(yyval.str,"(%s)",yyvsp[-1].str);}
    break;

  case 12:
#line 934 "fgl.yacc"
    { sprintf(yyval.str,"%s%s%s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 13:
#line 935 "fgl.yacc"
    {sprintf(yyval.str,"%d",atoi(yyvsp[0].str));}
    break;

  case 14:
#line 936 "fgl.yacc"
    {sprintf(yyval.str,"(%s%s)",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 15:
#line 937 "fgl.yacc"
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
#line 951 "fgl.yacc"
    {strcpy(yyval.str,"+");}
    break;

  case 17:
#line 952 "fgl.yacc"
    {strcpy(yyval.str,"-");}
    break;

  case 18:
#line 953 "fgl.yacc"
    {strcpy(yyval.str,"*");}
    break;

  case 19:
#line 954 "fgl.yacc"
    {strcpy(yyval.str,"/");}
    break;

  case 20:
#line 955 "fgl.yacc"
    {strcpy(yyval.str,"%");}
    break;

  case 21:
#line 960 "fgl.yacc"
    {strcpy(yyval.str,"+");}
    break;

  case 22:
#line 961 "fgl.yacc"
    {strcpy(yyval.str,"-");}
    break;

  case 23:
#line 972 "fgl.yacc"
    {
		debug("Using default attribute of WHITE");
		sprintf(yyval.str,"%d",0);}
    break;

  case 24:
#line 975 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 25:
#line 978 "fgl.yacc"
    {start_state("attribute",1);}
    break;

  case 26:
#line 978 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[-1].str);
debug("Got Attributes : %s",yyvsp[-1].str);
start_state("attribute",0);
}
    break;

  case 28:
#line 985 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 29:
#line 986 "fgl.yacc"
    {
sprintf(yyval.str,"%d",atoi(yyvsp[-2].str)|atoi(yyvsp[0].str));
}
    break;

  case 30:
#line 992 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("BLACK"));}
    break;

  case 31:
#line 993 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("BLUE"));}
    break;

  case 32:
#line 994 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("CYAN"));}
    break;

  case 33:
#line 995 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("GREEN"));}
    break;

  case 34:
#line 996 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("MAGENTA"));}
    break;

  case 35:
#line 997 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("RED"));}
    break;

  case 36:
#line 998 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("WHITE"));}
    break;

  case 37:
#line 999 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("YELLOW"));}
    break;

  case 38:
#line 1000 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("REVERSE"));}
    break;

  case 39:
#line 1001 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("BLINK"));}
    break;

  case 40:
#line 1002 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("UNDERLINE"));}
    break;

  case 41:
#line 1003 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("BOLD"));}
    break;

  case 42:
#line 1004 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("NORMAL"));}
    break;

  case 43:
#line 1005 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("INVISIBLE"));}
    break;

  case 44:
#line 1006 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("DIM"));}
    break;

  case 45:
#line 1007 "fgl.yacc"
    {inp_flags=inp_flags | 0x1; strcpy(yyval.str,"0");}
    break;

  case 48:
#line 1014 "fgl.yacc"
    {
debug("win_attributes_def");
start_state("attribute",1);
debug("Started states");
form_attrib.attrib=0;}
    break;

  case 49:
#line 1018 "fgl.yacc"
    {start_state("attribute",0);strcpy(yyval.str,"");
}
    break;

  case 50:
#line 1022 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 51:
#line 1023 "fgl.yacc"
    {sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 52:
#line 1027 "fgl.yacc"
    { 
/*printf("Window attribute = %s\n",$<str>1);*/
form_attrib.attrib      =form_attrib.attrib|atoi(yyvsp[0].str);
/*printf("Window attribute = %d\n",form_attrib.attrib);*/
}
    break;

  case 53:
#line 1033 "fgl.yacc"
    { form_attrib.border      =1;}
    break;

  case 54:
#line 1035 "fgl.yacc"
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
#line 1046 "fgl.yacc"
    { form_attrib.comment_line=atoi(yyvsp[0].str); }
    break;

  case 56:
#line 1048 "fgl.yacc"
    { form_attrib.form_line   =atoi(yyvsp[0].str); }
    break;

  case 57:
#line 1050 "fgl.yacc"
    { form_attrib.error_line  =atoi(yyvsp[0].str); }
    break;

  case 58:
#line 1052 "fgl.yacc"
    { form_attrib.menu_line   =atoi(yyvsp[0].str); 
debug("Set menu line to %s",yyvsp[0].str);
}
    break;

  case 59:
#line 1056 "fgl.yacc"
    { form_attrib.message_line=atoi(yyvsp[0].str); }
    break;

  case 60:
#line 1058 "fgl.yacc"
    { form_attrib.prompt_line =atoi(yyvsp[0].str); }
    break;

  case 61:
#line 1119 "fgl.yacc"
    {strcpy(yyval.str,"CALL");}
    break;

  case 62:
#line 1123 "fgl.yacc"
    { debug("print_expr (3)"); 
		print_expr(yyvsp[-2].ptr);
		print_pop_variable(yyvsp[0].str);
	}
    break;

  case 63:
#line 1127 "fgl.yacc"
    {
	print_getfldbuf(yyvsp[-2].str);
	}
    break;

  case 64:
#line 1130 "fgl.yacc"
    {
	print_returning();
}
    break;

  case 65:
#line 1134 "fgl.yacc"
    {
	print_form_is_compiled(yyvsp[-1].str);
	}
    break;

  case 66:
#line 1138 "fgl.yacc"
    {
	print_field_func('I',yyvsp[-3].str,yyvsp[0].str);
   }
    break;

  case 68:
#line 1142 "fgl.yacc"
    { 
	print_field_func('T',yyvsp[-3].str,yyvsp[0].str);
     }
    break;

  case 69:
#line 1145 "fgl.yacc"
    {
	new_counter();
   	addmap("Call",yyvsp[-3].str,curr_func,yylineno,infilename);
   }
    break;

  case 70:
#line 1151 "fgl.yacc"
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
#line 1160 "fgl.yacc"
    {
	print_returning();
	strcpy(yyval.str,yyvsp[-4].str); /* ? */
   }
    break;

  case 72:
#line 1164 "fgl.yacc"
    {
	new_counter();
   	addmap("Call",yyvsp[-1].str,curr_func,yylineno,infilename);
   }
    break;

  case 73:
#line 1169 "fgl.yacc"
    {
	debug("Got args");
   }
    break;

  case 74:
#line 1173 "fgl.yacc"
    {
	int a;
	dump_expr(yyvsp[-2].ptr);
	a=get_counter_val();
	drop_counter();
  	print_func_call(yyvsp[-5].str,yyvsp[-2].ptr,a);
   }
    break;

  case 75:
#line 1181 "fgl.yacc"
    {
	print_returning();
	strcpy(yyval.str,yyvsp[-3].str); /* ? */
   }
    break;

  case 76:
#line 1185 "fgl.yacc"
    {
	A4GLSQL_set_status(0,0);
	new_counter();
	}
    break;

  case 77:
#line 1189 "fgl.yacc"
    {
   sprintf(yyval.str,"%d",get_counter_val());drop_counter();
}
    break;

  case 78:
#line 1192 "fgl.yacc"
    {
        print_expr ((struct expr_str *)yyvsp[-3].ptr);  
	print_call_shared(yyvsp[-6].str,yyvsp[-8].str,atoi(yyvsp[-2].str));
	print_returning();
	print_end_call_shared();
}
    break;

  case 79:
#line 1198 "fgl.yacc"
    {
	sprintf(yyval.str,"\"%s\",\"%s\"",get_idents(0),get_idents(1));
	A4GLSQL_set_status(0,0);
	new_counter();
	}
    break;

  case 80:
#line 1203 "fgl.yacc"
    {
   	sprintf(yyval.str,"%d",get_counter_val());drop_counter();
}
    break;

  case 81:
#line 1206 "fgl.yacc"
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
#line 1222 "fgl.yacc"
    {
   char buff[256];
   new_counter();
   sprintf(buff,"%s:%s(%p)",yyvsp[-6].str,yyvsp[-4].str,yyvsp[-2].str);
   addmap("External",buff,curr_func,yylineno,infilename);
   }
    break;

  case 83:
#line 1229 "fgl.yacc"
    {
   sprintf(yyval.str,"%d",get_counter_val());drop_counter();
   }
    break;

  case 84:
#line 1233 "fgl.yacc"
    {
	 debug("print_expr (6)");print_expr(yyvsp[-2].ptr);
   }
    break;

  case 85:
#line 1237 "fgl.yacc"
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
#line 1259 "fgl.yacc"
    {start_bind('i',0);strcpy(yyval.str,"0");}
    break;

  case 87:
#line 1259 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);
}
    break;

  case 88:
#line 1263 "fgl.yacc"
    {start_bind('i',0);strcpy(yyval.str,"0");}
    break;

  case 89:
#line 1264 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 90:
#line 1265 "fgl.yacc"
    {strcpy(yyval.str,"WITHOUT WAITING"); }
    break;

  case 91:
#line 1270 "fgl.yacc"
    {
			yyval.ptr=new_expr("");
		}
    break;

  case 92:
#line 1273 "fgl.yacc"
    {
			yyval.ptr=yyvsp[0].ptr;
		}
    break;

  case 93:
#line 1279 "fgl.yacc"
    {
	yyval.ptr=yyvsp[0].ptr;
}
    break;

  case 94:
#line 1282 "fgl.yacc"
    {
		yyval.ptr=append_expr_expr(yyvsp[-2].ptr,yyvsp[0].ptr);
}
    break;

  case 97:
#line 1294 "fgl.yacc"
    {
sprintf(yyval.str,"\"%s\"",yyvsp[0].str);
}
    break;

  case 98:
#line 1300 "fgl.yacc"
    {
sprintf(yyval.str,"\"%s\"",yyvsp[0].str);
}
    break;

  case 99:
#line 1303 "fgl.yacc"
    { sprintf(yyval.str,"\"%s.%s\"",yyvsp[-2].str,yyvsp[0].str); }
    break;

  case 100:
#line 1318 "fgl.yacc"
    {
push_blockcommand("CASE");
setinc(1);
incprint();
print_case(1);
setinc(1);
}
    break;

  case 101:
#line 1328 "fgl.yacc"
    {
print_after_when(0);
pop_blockcommand("CASE");
}
    break;

  case 102:
#line 1334 "fgl.yacc"
    {  push_blockcommand("CASE"); 
setinc(1);
incprint(); 
print_case(0);
setinc(1);
}
    break;

  case 103:
#line 1343 "fgl.yacc"
    {
print_after_when(0);
pop_blockcommand("CASE");
}
    break;

  case 108:
#line 1356 "fgl.yacc"
    {setinc(-1);incprint();}
    break;

  case 110:
#line 1359 "fgl.yacc"
    {
incprint();
}
    break;

  case 111:
#line 1361 "fgl.yacc"
    {incprint();
print_after_when(0);
}
    break;

  case 113:
#line 1367 "fgl.yacc"
    {incprint();}
    break;

  case 114:
#line 1369 "fgl.yacc"
    {incprint();
print_after_when(0);
}
    break;

  case 115:
#line 1374 "fgl.yacc"
    {
print_when(0);

incprint();
}
    break;

  case 116:
#line 1379 "fgl.yacc"
    {incprint();
print_after_when(1);
setinc(-1);}
    break;

  case 117:
#line 1385 "fgl.yacc"
    {
incprint();
print_when(1);
}
    break;

  case 118:
#line 1389 "fgl.yacc"
    {incprint();
print_after_when(1);
setinc(-1);}
    break;

  case 119:
#line 1404 "fgl.yacc"
    {
  print_close('F',yyvsp[0].str);
 }
    break;

  case 120:
#line 1407 "fgl.yacc"
    {
  print_close('W',yyvsp[0].str);
}
    break;

  case 121:
#line 1410 "fgl.yacc"
    {
  print_close('W',yyvsp[0].str);
}
    break;

  case 122:
#line 1413 "fgl.yacc"
    {
  print_close('D',0);
}
    break;

  case 123:
#line 1416 "fgl.yacc"
    {
  print_close('S',yyvsp[0].str);
}
    break;

  case 124:
#line 1419 "fgl.yacc"
    {
  print_close('C',yyvsp[0].str);
}
    break;

  case 130:
#line 1441 "fgl.yacc"
    {
			lex_printc("%s",yyvsp[0].str);
}
    break;

  case 133:
#line 1450 "fgl.yacc"
    {
			lex_printc("%s\n",yyvsp[0].str);
}
    break;

  case 134:
#line 1460 "fgl.yacc"
    {
/* This aint used - its filtered by the lexer first... */
	lex_printc("FIXME : Comment : %s\n");
}
    break;

  case 135:
#line 1474 "fgl.yacc"
    {
push_blockcommand("CONSTRUCT");
}
    break;

  case 136:
#line 1478 "fgl.yacc"
    {
	print_construct_1();
}
    break;

  case 137:
#line 1481 "fgl.yacc"
    {
	print_construct_2(yyvsp[-2].str);
}
    break;

  case 138:
#line 1489 "fgl.yacc"
    {
	print_construct_3(1,yyvsp[-5].str,yyvsp[0].str);
	strcpy(yyval.str,"form_loop(&_inp_io)"); /* FIXME */
	reset_constr();
}
    break;

  case 139:
#line 1495 "fgl.yacc"
    {
	print_construct_3(0,yyvsp[-7].str,yyvsp[0].str);
	strcpy(yyval.str,"form_loop(&_inp_io)"); /* FIXME */
	reset_constr();
}
    break;

  case 144:
#line 1510 "fgl.yacc"
    {
                push_construct("",yyval.str);
             }
    break;

  case 145:
#line 1514 "fgl.yacc"
    {
                sprintf(yyval.str,"%s.%s",yyvsp[-2].str,yyvsp[0].str);
                push_construct(yyvsp[-2].str,yyvsp[0].str); 
             }
    break;

  case 146:
#line 1519 "fgl.yacc"
    {
                push_construct(yyvsp[-2].str,"*");
             }
    break;

  case 149:
#line 1529 "fgl.yacc"
    {
		print_befaft_field_1(yyvsp[0].str);
	}
    break;

  case 150:
#line 1532 "fgl.yacc"
    {
		print_befaft_field_2();

	}
    break;

  case 151:
#line 1536 "fgl.yacc"
    {
		print_befaft_field_1(yyvsp[0].str);
	}
    break;

  case 152:
#line 1538 "fgl.yacc"
    {
		print_befaft_field_2();
	}
    break;

  case 153:
#line 1541 "fgl.yacc"
    {
		print_onkey_1(yyvsp[0].str);
	}
    break;

  case 154:
#line 1543 "fgl.yacc"
    {
		print_onkey_2();
	}
    break;

  case 155:
#line 1546 "fgl.yacc"
    {
		print_befaft_field_1("AFTER_INP");
	}
    break;

  case 156:
#line 1548 "fgl.yacc"
    {
		print_befaft_field_2();
	}
    break;

  case 157:
#line 1551 "fgl.yacc"
    {
		print_befaft_field_1("BEFORE_INP");
		}
    break;

  case 158:
#line 1554 "fgl.yacc"
    {
		print_befaft_field_2();
	}
    break;

  case 159:
#line 1564 "fgl.yacc"
    {sprintf(yyval.str,"BEF_FIELD_CHK(%s)",yyvsp[0].str);}
    break;

  case 160:
#line 1565 "fgl.yacc"
    {
	  char buff[80];
	  sprintf(buff,"BEF_FIELD_CHK(%s)",yyvsp[0].str);
	  generate_or(yyval.str,yyvsp[-2].str,buff);
	}
    break;

  case 161:
#line 1573 "fgl.yacc"
    {sprintf(yyval.str,"AFT_FIELD_CHK(%s)",yyvsp[0].str);}
    break;

  case 162:
#line 1574 "fgl.yacc"
    {
	  char buff[80];
	  sprintf(buff,"AFT_FIELD_CHK(%s)",yyvsp[0].str);
	  generate_or(yyval.str,yyvsp[-2].str,buff);
	}
    break;

  case 163:
#line 1591 "fgl.yacc"
    {
        	yyval.ptr=new_expr("pushop(OP_YEAR);");
	}
    break;

  case 164:
#line 1594 "fgl.yacc"
    {
        	yyval.ptr=new_expr("pushop(OP_MONTH);");
	}
    break;

  case 165:
#line 1597 "fgl.yacc"
    {
        	yyval.ptr=new_expr("pushop(OP_DAY);");
	}
    break;

  case 166:
#line 1600 "fgl.yacc"
    {
        	yyval.ptr=new_expr("pushop(OP_HOUR);");
	}
    break;

  case 167:
#line 1603 "fgl.yacc"
    {
        	yyval.ptr=new_expr("pushop(OP_MINUTE);");
	}
    break;

  case 168:
#line 1606 "fgl.yacc"
    {
        	yyval.ptr=new_expr("pushop(OP_SECOND);");
	}
    break;

  case 169:
#line 1615 "fgl.yacc"
    {
			yyval.ptr=append_expr_expr(yyvsp[-2].ptr,yyvsp[-1].ptr);
		}
    break;

  case 170:
#line 1623 "fgl.yacc"
    { 
	char buff[50];
	sprintf(buff,"push_int(%d);",(19*16)+10); 
	yyval.ptr=new_expr(buff);
}
    break;

  case 171:
#line 1628 "fgl.yacc"
    { 
	char buff[50];
	sprintf(buff,"push_int(%d);",(atoi(yyvsp[-2].str)*16) +atoi(yyvsp[0].str)  ); 
	yyval.ptr=new_expr(buff);
}
    break;

  case 172:
#line 1641 "fgl.yacc"
    {
				print_defer(0);
			}
    break;

  case 173:
#line 1645 "fgl.yacc"
    {
				print_defer(1);
			}
    break;

  case 174:
#line 1660 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 175:
#line 1661 "fgl.yacc"
    {strcpy(yyval.str,"");lastlineno=yylineno;}
    break;

  case 178:
#line 1669 "fgl.yacc"
    {dtypelist[0]=0;lex_printcomment("/* define */\n");}
    break;

  case 179:
#line 1669 "fgl.yacc"
    {lex_printcomment("/*end def */\n");}
    break;

  case 185:
#line 1679 "fgl.yacc"
    {in_define=1;}
    break;

  case 186:
#line 1679 "fgl.yacc"
    {in_define=0;strcpy(yyval.str,yyvsp[0].str);
                        set_yytext(yyval.str);
                        if (bad_identifiers(yyval.str)) {
                                yyerror("You can't use this identifier as it is a reserved word in the target language");
                        }
}
    break;

  case 187:
#line 1688 "fgl.yacc"
    { add_constant('c',yyvsp[0].str,yyvsp[-2].str); addmap("Constant",yyvsp[-2].str,curr_func,yylineno,infilename); }
    break;

  case 188:
#line 1689 "fgl.yacc"
    { add_constant('C',yyvsp[0].str,yyvsp[-2].str); addmap("Constant",yyvsp[-2].str,curr_func,yylineno,infilename); }
    break;

  case 189:
#line 1690 "fgl.yacc"
    { add_constant('f',yyvsp[0].str,yyvsp[-2].str);
addmap("Constant",yyvsp[-2].str,curr_func,yylineno,infilename);
 }
    break;

  case 190:
#line 1693 "fgl.yacc"
    { 
add_constant('i',yyvsp[0].str,yyvsp[-2].str);
addmap("Constant",yyvsp[-2].str,curr_func,yylineno,infilename);
 }
    break;

  case 192:
#line 1698 "fgl.yacc"
    { }
    break;

  case 193:
#line 1698 "fgl.yacc"
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
#line 1715 "fgl.yacc"
    {
		sprintf(yyval.str,"-%p",yyvsp[0].str);}
    break;

  case 198:
#line 1719 "fgl.yacc"
    {
/*AF CygWin FIX */
push_name(yyval.str,0);
addmap("Define",yyvsp[0].str,curr_func,yylineno,infilename);
}
    break;

  case 203:
#line 1733 "fgl.yacc"
    {
	debug("defines array %s",yyvsp[-1].str);
	push_type(0,0,yyvsp[-1].str);
}
    break;

  case 205:
#line 1742 "fgl.yacc"
    {
	push_associate(yyvsp[-5].str,yyvsp[-1].str);
	push_type(0,0,yyvsp[-1].str);
}
    break;

  case 206:
#line 1746 "fgl.yacc"
    {
    /* void pop_associate (char *a); */
	pop_associate(0);

}
    break;

  case 212:
#line 1762 "fgl.yacc"
    {sprintf(yyval.str,"%s][%s][%s",yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str); debug("Triplet");}
    break;

  case 213:
#line 1764 "fgl.yacc"
    {sprintf(yyval.str,"%s][%s",yyvsp[-2].str,yyvsp[0].str); debug("double");}
    break;

  case 214:
#line 1765 "fgl.yacc"
    {debug("Single");}
    break;

  case 216:
#line 1772 "fgl.yacc"
    {push_record();in_record++;}
    break;

  case 217:
#line 1772 "fgl.yacc"
    {pop_record();in_record--;}
    break;

  case 218:
#line 1773 "fgl.yacc"
    {in_record++;push_record();debug("Like\n");}
    break;

  case 219:
#line 1774 "fgl.yacc"
    {debug("Link Table : %s\n",yyvsp[-2].str);
                  push_rectab(yyvsp[-2].str);
                  pop_record();in_record--;}
    break;

  case 220:
#line 1777 "fgl.yacc"
    {
		push_record();debug("Like\n");}
    break;

  case 221:
#line 1779 "fgl.yacc"
    {
		  debug("Table:%s\n",yyvsp[-4].str);
		  add_link_to(yyvsp[-4].str,yyvsp[-1].str);
	          debug("Push record...\n");
                  push_rectab(yyvsp[-4].str);
                  pop_record();
}
    break;

  case 223:
#line 1789 "fgl.yacc"
    {
	sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 228:
#line 1804 "fgl.yacc"
    {start_state("dtype",1);}
    break;

  case 229:
#line 1804 "fgl.yacc"
    {start_state("dtype",0);}
    break;

  case 233:
#line 1810 "fgl.yacc"
    {push_type("char","1",0);}
    break;

  case 234:
#line 1811 "fgl.yacc"
    {
/* char buff[80]; */
if (atoi(yyvsp[-1].str)==4) {
	addmap("size=4","----",curr_func,yylineno,infilename);
}
push_type("char",yyvsp[-1].str,0);
}
    break;

  case 235:
#line 1818 "fgl.yacc"
    {push_type("char",yyvsp[-1].str,0);}
    break;

  case 236:
#line 1819 "fgl.yacc"
    {push_type("char",yyvsp[-3].str,0);}
    break;

  case 237:
#line 1820 "fgl.yacc"
    {push_type("long",0,0);}
    break;

  case 238:
#line 1821 "fgl.yacc"
    {
debug("Using specified type...");
push_dim(yyvsp[0].str);}
    break;

  case 239:
#line 1824 "fgl.yacc"
    {push_type("int",0,0);}
    break;

  case 240:
#line 1825 "fgl.yacc"
    {push_type("form",0,0);}
    break;

  case 241:
#line 1826 "fgl.yacc"
    {push_type("form",0,0);}
    break;

  case 242:
#line 1827 "fgl.yacc"
    { char buff[256];
				sprintf(buff,"%d",16*256+2);
				push_type("fgldecimal",buff,0);
				}
    break;

  case 243:
#line 1831 "fgl.yacc"
    {
				char buff[256];
				sprintf(buff,"%d",atoi(yyvsp[-1].str)*256+2);
				push_type("fgldecimal",buff,0);
}
    break;

  case 244:
#line 1836 "fgl.yacc"
    {
char buff[256];
sprintf(buff,"%d",atoi(yyvsp[-3].str)*256+atoi(yyvsp[-1].str));
push_type("fgldecimal",buff,0);
}
    break;

  case 245:
#line 1841 "fgl.yacc"
    {
			char buff[256];
			sprintf(buff,"%d",16*256+2);
			push_type("fglmoney",buff,0);}
    break;

  case 246:
#line 1845 "fgl.yacc"
    {
		char buff[256];sprintf(buff,"%d",atoi(yyvsp[-1].str)*256+2);
			push_type("fglmoney",buff,0);}
    break;

  case 247:
#line 1848 "fgl.yacc"
    {
char buff[256];
sprintf(buff,"%d",atoi(yyvsp[-3].str)*256+atoi(yyvsp[-1].str));
push_type("fglmoney",buff,0);}
    break;

  case 248:
#line 1852 "fgl.yacc"
    {push_type("double",0,0);}
    break;

  case 249:
#line 1853 "fgl.yacc"
    {push_type("float",0,0);}
    break;

  case 250:
#line 1854 "fgl.yacc"
    {push_type("fgldate",0,0);}
    break;

  case 251:
#line 1855 "fgl.yacc"
    {push_type("fglbyte",0,0);}
    break;

  case 252:
#line 1856 "fgl.yacc"
    {push_type("fglbyte",0,0);}
    break;

  case 253:
#line 1857 "fgl.yacc"
    {push_type("fgltext",0,0);}
    break;

  case 254:
#line 1858 "fgl.yacc"
    {push_type("fgltext",0,0);}
    break;

  case 255:
#line 1859 "fgl.yacc"
    {
push_type("struct_dtime",yyvsp[0].str,0);
}
    break;

  case 256:
#line 1862 "fgl.yacc"
    {push_type("struct_ival",yyvsp[0].str,0);}
    break;

  case 257:
#line 1863 "fgl.yacc"
    {push_like(yyvsp[0].str);lex_printcomment("/*added(XXXXX)\n */");}
    break;

  case 258:
#line 1864 "fgl.yacc"
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
#line 1896 "fgl.yacc"
    {
lex_printcomment("/*column like(ZZZ)\n*/"); sprintf(yyval.str,"%s.%s",yyvsp[-2].str,yyvsp[0].str); lex_printcomment ("/*set col...(ZZZ)\n*/");}
    break;

  case 260:
#line 1900 "fgl.yacc"
    {debug("--->%s\n",yyvsp[0].str);strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 261:
#line 1902 "fgl.yacc"
    {debug("--->%s\n",yyvsp[0].str);strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 262:
#line 1904 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 263:
#line 1906 "fgl.yacc"
    {
debug("Real datetime %s to %s\n",yyvsp[-2].str,yyvsp[0].str);
sprintf(yyval.str,"%d",(atoi(yyvsp[-2].str)*16)+atoi(yyvsp[0].str)); }
    break;

  case 264:
#line 1911 "fgl.yacc"
    {

sprintf(yyval.str,"%d",(atoi(yyvsp[-2].str)*16)+atoi(yyvsp[0].str)); 
printf("-->%s\n",yyval.str);
}
    break;

  case 265:
#line 1917 "fgl.yacc"
    {start_state("dtime_val",1);}
    break;

  case 266:
#line 1917 "fgl.yacc"
    {start_state("dtime_val",0); strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 267:
#line 1921 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 268:
#line 1922 "fgl.yacc"
    {strcpy(yyval.str,"2");}
    break;

  case 269:
#line 1923 "fgl.yacc"
    {strcpy(yyval.str,"3");}
    break;

  case 270:
#line 1924 "fgl.yacc"
    {strcpy(yyval.str,"4");}
    break;

  case 271:
#line 1925 "fgl.yacc"
    {strcpy(yyval.str,"5");}
    break;

  case 272:
#line 1926 "fgl.yacc"
    {strcpy(yyval.str,"6");}
    break;

  case 273:
#line 1928 "fgl.yacc"
    {
debug("opt_frac returns %s",yyvsp[0].str);
sprintf(yyval.str,"%d",atoi(yyvsp[0].str)+6); }
    break;

  case 274:
#line 1933 "fgl.yacc"
    {start_state("dtime_val",1);}
    break;

  case 275:
#line 1933 "fgl.yacc"
    { debug ("Got end");start_state("dtime_val",0);  strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 276:
#line 1936 "fgl.yacc"
    {
debug("Nothing in fraction - assume 2");
strcpy(yyval.str,"2");}
    break;

  case 277:
#line 1938 "fgl.yacc"
    {
debug("Read fraction .. ");
debug("    %s",yyvsp[-1].str);
strcpy(yyval.str,yyvsp[-1].str);
}
    break;

  case 278:
#line 1944 "fgl.yacc"
    {
debug("Nothing in fraction - assume 2");
strcpy(yyval.str,"2");}
    break;

  case 279:
#line 1946 "fgl.yacc"
    {
debug("    %s",yyvsp[-1].str);
strcpy(yyval.str,yyvsp[-1].str);
}
    break;

  case 280:
#line 1952 "fgl.yacc"
    {
if (atoi(yyvsp[0].str)>5) {
yyerror("Fraction values are between 0 and 5");
YYERROR;
}
}
    break;

  case 281:
#line 1960 "fgl.yacc"
    {start_state("interval_val",1);}
    break;

  case 282:
#line 1960 "fgl.yacc"
    {start_state("interval_val",0); sprintf(yyval.str,"%d",atoi(yyvsp[0].str)*16+atoi(yyvsp[-1].str));}
    break;

  case 283:
#line 1963 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 284:
#line 1964 "fgl.yacc"
    {strcpy(yyval.str,"2");}
    break;

  case 285:
#line 1965 "fgl.yacc"
    {strcpy(yyval.str,"3");}
    break;

  case 286:
#line 1966 "fgl.yacc"
    {strcpy(yyval.str,"4");}
    break;

  case 287:
#line 1967 "fgl.yacc"
    {strcpy(yyval.str,"5");}
    break;

  case 288:
#line 1968 "fgl.yacc"
    {strcpy(yyval.str,"6");}
    break;

  case 289:
#line 1970 "fgl.yacc"
    {
debug("opt_frac returns %s",yyvsp[0].str);
sprintf(yyval.str,"%d",atoi(yyvsp[0].str)+6); }
    break;

  case 293:
#line 1991 "fgl.yacc"
    {
              	dim_set_name(yyvsp[0].str);
              }
    break;

  case 297:
#line 2000 "fgl.yacc"
    {dim_push_type("char","1",0);}
    break;

  case 298:
#line 2002 "fgl.yacc"
    {dim_push_type("char",yyvsp[-1].str,0);}
    break;

  case 299:
#line 2004 "fgl.yacc"
    {dim_push_type("char",yyvsp[-1].str,0);}
    break;

  case 300:
#line 2006 "fgl.yacc"
    {dim_push_type("char",yyvsp[-3].str,0);}
    break;

  case 301:
#line 2007 "fgl.yacc"
    {dim_push_type("long",0,0);}
    break;

  case 302:
#line 2008 "fgl.yacc"
    {dim_push_type("integer",0,0);}
    break;

  case 303:
#line 2009 "fgl.yacc"
    {dim_push_type("FORM",0,0);}
    break;

  case 304:
#line 2010 "fgl.yacc"
    {
char buff[256];
sprintf(buff,"%d",16*256+2);
dim_push_type("fgldecimal",buff,0);
}
    break;

  case 305:
#line 2015 "fgl.yacc"
    {

char buff[256];
sprintf(buff,"%d",atoi(yyvsp[-1].str)*256+2);
dim_push_type("fgldecimal",buff,0);
}
    break;

  case 306:
#line 2022 "fgl.yacc"
    {
char buff[256];
sprintf(buff,"%d",atoi(yyvsp[-3].str)*256+atoi(yyvsp[-1].str));
dim_push_type("fgldecimal",buff,0);
}
    break;

  case 307:
#line 2027 "fgl.yacc"
    {dim_push_type("fglmoney",0,0);}
    break;

  case 308:
#line 2029 "fgl.yacc"
    {dim_push_type("fglmoney",0,0);}
    break;

  case 309:
#line 2031 "fgl.yacc"
    {dim_push_type("fglmoney",0,0);}
    break;

  case 310:
#line 2032 "fgl.yacc"
    {dim_push_type("double",0,0);}
    break;

  case 311:
#line 2033 "fgl.yacc"
    {dim_push_type("float",0,0);}
    break;

  case 312:
#line 2034 "fgl.yacc"
    {dim_push_type("fgldate",0,0);}
    break;

  case 313:
#line 2035 "fgl.yacc"
    {dim_push_type("fglbyte",0,0);}
    break;

  case 314:
#line 2036 "fgl.yacc"
    {dim_push_type("fgltext",0,0);}
    break;

  case 315:
#line 2037 "fgl.yacc"
    {
dim_push_type("struct_dtime",yyvsp[0].str,0);
}
    break;

  case 316:
#line 2040 "fgl.yacc"
    {dim_push_type("struct_ival",0,0);}
    break;

  case 317:
#line 2042 "fgl.yacc"
    {dim_push_like(yyvsp[0].str);lex_printcomment("/*added(XXXXX)\n */");}
    break;

  case 318:
#line 2048 "fgl.yacc"
    {
lex_printcomment("/*column like(ZZZ)\n*/");
sprintf(yyval.str,"%s.%s",yyvsp[-2].str,yyvsp[0].str)
; lex_printcomment ("/*set col...(ZZZ)\n*/");}
    break;

  case 319:
#line 2056 "fgl.yacc"
    {
dim_push_type(0,0,yyvsp[-1].str);
}
    break;

  case 321:
#line 2064 "fgl.yacc"
    {
dim_push_associate(yyvsp[-5].str,yyvsp[-1].str);
dim_push_type(0,0,yyvsp[-1].str);
}
    break;

  case 322:
#line 2068 "fgl.yacc"
    {
	/* void dim_pop_associate (char *a); */
	dim_pop_associate(0);
}
    break;

  case 323:
#line 2076 "fgl.yacc"
    {dim_push_record();}
    break;

  case 324:
#line 2077 "fgl.yacc"
    {dim_pop_record();}
    break;

  case 325:
#line 2078 "fgl.yacc"
    {dim_push_record();debug("Like\n");}
    break;

  case 326:
#line 2079 "fgl.yacc"
    {debug("Table:%s\n",yyvsp[-2].str);
                                  dim_push_rectab(yyvsp[-2].str);
                                  dim_pop_record();}
    break;

  case 332:
#line 2098 "fgl.yacc"
    { dim_push_name(yyval.str,0); }
    break;

  case 333:
#line 2110 "fgl.yacc"
    {
	print_display_line();
		strcpy(yyval.str,get_display_str(0,0,0));
	}
    break;

  case 334:
#line 2114 "fgl.yacc"
    {
		strcpy(yyval.str,get_display_str(1,0,0)); /* FIXME */
	}
    break;

  case 335:
#line 2117 "fgl.yacc"
    { 
	strcpy(yyval.str,"#error not implemented yet");
	}
    break;

  case 336:
#line 2120 "fgl.yacc"
    { strcpy(yyval.str, get_display_str(4,0,0)); }
    break;

  case 337:
#line 2121 "fgl.yacc"
    { strcpy(yyval.str, get_display_str(2,yyvsp[0].str,0)); }
    break;

  case 338:
#line 2122 "fgl.yacc"
    { strcpy(yyval.str, get_display_str(3,yyvsp[0].str,yyvsp[-2].str)); }
    break;

  case 339:
#line 2123 "fgl.yacc"
    { strcpy(yyval.str, get_display_str(5,yyvsp[-1].str,0)); }
    break;

  case 340:
#line 2124 "fgl.yacc"
    { 
	strcpy(yyval.str,"#error not implemented yet");
 }
    break;

  case 341:
#line 2130 "fgl.yacc"
    {
		print_display_by_name(yyvsp[0].str);
                }
    break;

  case 342:
#line 2137 "fgl.yacc"
    { 
				print_display(yyvsp[-1].str,yyvsp[-2].str,yyvsp[0].str);
		}
    break;

  case 343:
#line 2142 "fgl.yacc"
    {
		print_display_form(yyvsp[-1].str,yyvsp[0].str);
	}
    break;

  case 344:
#line 2147 "fgl.yacc"
    {
		push_blockcommand("DISPLAY");
		}
    break;

  case 345:
#line 2151 "fgl.yacc"
    {
		print_display_array_p1(yyvsp[-6].str,yyvsp[-4].str,yyvsp[-1].str,yyvsp[0].str);
		}
    break;

  case 346:
#line 2154 "fgl.yacc"
    {
		add_continue_blockcommand ("DISPLAY");  
		print_display_array_p2();
		pop_blockcommand("DISPLAY");
}
    break;

  case 347:
#line 2162 "fgl.yacc"
    {
strcpy(yyval.str,"0,0");
}
    break;

  case 348:
#line 2164 "fgl.yacc"
    {
	strcpy(yyval.str,yyvsp[0].str);
}
    break;

  case 349:
#line 2169 "fgl.yacc"
    {
				sprintf(yyval.str,"0x%lx",atol(yyvsp[0].str));
			}
    break;

  case 354:
#line 2181 "fgl.yacc"
    {
		print_befaft_field_1("AFT_ROW");
		}
    break;

  case 355:
#line 2184 "fgl.yacc"
    {
		print_befaft_field_2();
	}
    break;

  case 356:
#line 2187 "fgl.yacc"
    {
		print_befaft_field_1("BEF_ROW");
		}
    break;

  case 357:
#line 2190 "fgl.yacc"
    {
		print_befaft_field_2();
	}
    break;

  case 358:
#line 2193 "fgl.yacc"
    {
		print_onkey_1(yyvsp[0].str);
		}
    break;

  case 359:
#line 2196 "fgl.yacc"
    {
		print_onkey_2();
	}
    break;

  case 360:
#line 2209 "fgl.yacc"
    {
			print_error(yyvsp[0].str,0);
		}
    break;

  case 361:
#line 2212 "fgl.yacc"
    { 
			print_error(yyvsp[-1].str,1);
	}
    break;

  case 362:
#line 2227 "fgl.yacc"
    { if (in_command("WHILE")) { exit_loop("WHILE"); } else { YYERROR;} }
    break;

  case 363:
#line 2229 "fgl.yacc"
    { if (in_command("INPUT")) { exit_loop("INPUT"); } else { YYERROR;} }
    break;

  case 364:
#line 2231 "fgl.yacc"
    { if (in_command("FOREACH")) { exit_loop("FOREACH"); } else { YYERROR;} }
    break;

  case 365:
#line 2233 "fgl.yacc"
    { if (in_command("FOR")) { exit_loop("FOR"); } else { YYERROR;} }
    break;

  case 366:
#line 2235 "fgl.yacc"
    { if (in_command("CONSTRUCT")) { exit_loop("CONSTRUCT"); } else { YYERROR;} }
    break;

  case 367:
#line 2237 "fgl.yacc"
    { if (in_command("DISPLAY")) { exit_loop("DISPLAY"); } else { YYERROR;} }
    break;

  case 368:
#line 2238 "fgl.yacc"
    {
	if (in_command("MENU")) {
		exit_loop("MENU");
		/* lex_printc("cmd_no=-3;continue;\n"); */
	} 
              else YYERROR;}
    break;

  case 369:
#line 2245 "fgl.yacc"
    { if (in_command("CASE")) { exit_loop("CASE"); } else { YYERROR;} }
    break;

  case 370:
#line 2247 "fgl.yacc"
    { if (in_command("PROMPT")) { exit_loop("PROMPT"); } else { YYERROR;} }
    break;

  case 371:
#line 2251 "fgl.yacc"
    { if (in_command("WHILE")) { continue_loop("WHILE");  } else { YYERROR;} }
    break;

  case 372:
#line 2253 "fgl.yacc"
    { if (in_command("INPUT")) { continue_loop("INPUT"); } else { YYERROR;} }
    break;

  case 373:
#line 2255 "fgl.yacc"
    { if (in_command("FOREACH")) { continue_loop("FOREACH");} else { YYERROR;} }
    break;

  case 374:
#line 2257 "fgl.yacc"
    { if (in_command("FOR")) { continue_loop("FOR"); } else { YYERROR;} }
    break;

  case 375:
#line 2259 "fgl.yacc"
    { if (in_command("CONSTRUCT")) { continue_loop("CONSTRUCT"); } else { YYERROR;} }
    break;

  case 376:
#line 2261 "fgl.yacc"
    { if (in_command("DISPLAY")) { continue_loop("DISPLAY"); } else { YYERROR;} }
    break;

  case 377:
#line 2263 "fgl.yacc"
    { if (in_command("MENU")) {  continue_loop("MENU");  } else { YYERROR;} }
    break;

  case 378:
#line 2269 "fgl.yacc"
    { if (in_command("PROMPT")) { continue_loop("PROMPT"); } else { YYERROR;} }
    break;

  case 379:
#line 2283 "fgl.yacc"
    {
	print_exit_program(0);
}
    break;

  case 380:
#line 2286 "fgl.yacc"
    {
	print_exit_program(1);
}
    break;

  case 385:
#line 2303 "fgl.yacc"
    {
	dec_counter();
	yyval.ptr=append_expr_expr(yyvsp[-1].ptr,yyvsp[0].ptr);
}
    break;

  case 388:
#line 2309 "fgl.yacc"
    {
	debug("Got literal ptr=%p",yyvsp[0].ptr);
}
    break;

  case 389:
#line 2313 "fgl.yacc"
    {
	yyval.ptr=new_expr("push_int(0);");
	yyval.ptr=append_expr_expr(yyval.ptr,yyvsp[0].ptr);
	yyval.ptr=append_expr(yyval.ptr,"pushop(OP_SUB);");
}
    break;

  case 390:
#line 2318 "fgl.yacc"
    {
	yyval.ptr=yyvsp[0].ptr;
}
    break;

  case 394:
#line 2328 "fgl.yacc"
    { yyval.ptr=new_expr("add_spaces();"); }
    break;

  case 401:
#line 2339 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 402:
#line 2339 "fgl.yacc"
    {
strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 404:
#line 2344 "fgl.yacc"
    {yyval.ptr=new_expr("push_null()");}
    break;

  case 405:
#line 2348 "fgl.yacc"
    {
	/*set_counter(0);*/
	sprintf(yyval.str,"%d",get_counter_val());
	lex_printcomment("/*L1 %s*/\n",yyval.str);
}
    break;

  case 406:
#line 2354 "fgl.yacc"
    {
	sprintf(yyval.str,"%d",get_counter_val());
	lex_printcomment("/*L2 %s*/\n",yyval.str);
}
    break;

  case 407:
#line 2362 "fgl.yacc"
    {
	/*set_counter(0);*/
	sprintf(yyval.str,"%d",get_counter_val());
	lex_printcomment("/*L1 %s*/\n",yyval.str);
}
    break;

  case 408:
#line 2368 "fgl.yacc"
    {
	sprintf(yyval.str,"%d",get_counter_val());
	lex_printcomment("/*L2 %s*/\n",yyval.str);
}
    break;

  case 409:
#line 2377 "fgl.yacc"
    {sprintf(yyval.str,"%d",get_counter_val());}
    break;

  case 410:
#line 2379 "fgl.yacc"
    {
	print_op("OP_CONCAT");
	dec_counter();sprintf(yyval.str,"%d",get_counter_val());
}
    break;

  case 411:
#line 2386 "fgl.yacc"
    {
	debug("Print expr (2)");
	print_expr(yyvsp[0].ptr);
}
    break;

  case 412:
#line 2394 "fgl.yacc"
    {
	strcpy(yyval.str,"+");
}
    break;

  case 413:
#line 2398 "fgl.yacc"
    {
	strcpy(yyval.str,"-");
}
    break;

  case 414:
#line 2407 "fgl.yacc"
    {
	
	yyval.ptr=append_expr(yyvsp[0].ptr,"pushop(OP_NOT);");
}
    break;

  case 415:
#line 2412 "fgl.yacc"
    {
	yyval.ptr=new_expr("push_int(1);");
        inc_counter();
}
    break;

  case 416:
#line 2417 "fgl.yacc"
    {
	inc_counter();
	yyval.ptr=new_expr("push_int(0);");
}
    break;

  case 417:
#line 2421 "fgl.yacc"
    { yyval.ptr=yyvsp[-1].ptr; }
    break;

  case 418:
#line 2423 "fgl.yacc"
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
#line 2433 "fgl.yacc"
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
#line 2447 "fgl.yacc"
    {
	debug("init expr %s %s",yyvsp[-1].str,yyvsp[0].str);
	sprintf(yyval.str,"%s%p",yyvsp[-1].str,yyvsp[0].str);
	sprintf(yyval.str,"%s",get_push_literal('D',yyval.str));
	yyval.ptr=new_expr(yyval.str);
        inc_counter();
}
    break;

  case 421:
#line 2455 "fgl.yacc"
    {
	debug("init expr int %s %d",yyvsp[-1].str,atoi(yyvsp[0].str));
	sprintf(yyval.str,"%s%p",yyvsp[-1].str,yyvsp[0].str);
	sprintf(yyval.str,"%s",get_push_literal('L',yyval.str));
	yyval.ptr=new_expr(yyval.str);
	inc_counter();
}
    break;

  case 422:
#line 2467 "fgl.yacc"
    {
	sprintf(yyval.str,"%s",get_push_literal('S',yyvsp[0].str));
	yyval.ptr=new_expr(yyval.str);
	inc_counter();
}
    break;

  case 423:
#line 2473 "fgl.yacc"
    {
	sprintf(yyval.str,"%s",get_push_literal('D',yyvsp[0].str));
	yyval.ptr=new_expr(yyval.str);
	inc_counter();
}
    break;

  case 424:
#line 2479 "fgl.yacc"
    {
	sprintf(yyval.str,"%s",get_push_literal('L',yyvsp[0].str));
	yyval.ptr=new_expr(yyval.str);
	inc_counter();
}
    break;

  case 427:
#line 2489 "fgl.yacc"
    {
		sprintf(yyval.str,"%s\n%s",yyvsp[-2].str,yyvsp[0].str);
	}
    break;

  case 428:
#line 2495 "fgl.yacc"
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
#line 2567 "fgl.yacc"
    {
	sprintf(yyval.str,"%sset_column(&rep);",ispdf());
	yyval.ptr=append_expr(yyvsp[0].ptr,yyval.str);
}
    break;

  case 430:
#line 2573 "fgl.yacc"
    {
sprintf(yyval.str,"%sset_column(&rep);",ispdf());
yyval.ptr=append_expr(yyvsp[0].ptr,yyval.str);
}
    break;

  case 431:
#line 2577 "fgl.yacc"
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
#line 2585 "fgl.yacc"
    {insql=1;set_ingroup();}
    break;

  case 433:
#line 2585 "fgl.yacc"
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
#line 2602 "fgl.yacc"
    {
	yyval.ptr=append_expr(yyvsp[0].ptr,"pushop(OP_AND);");
}
    break;

  case 435:
#line 2606 "fgl.yacc"
    {
	yyval.ptr=append_expr(yyvsp[0].ptr,"pushop(OP_OR);");
}
    break;

  case 436:
#line 2612 "fgl.yacc"
    {
	yyval.ptr=yyvsp[0].ptr;
	}
    break;

  case 437:
#line 2615 "fgl.yacc"
    {
		debug("Adding to list...");
		yyval.ptr=append_expr_expr(yyvsp[-2].ptr,yyvsp[0].ptr);
	}
    break;

  case 438:
#line 2623 "fgl.yacc"
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
#line 2634 "fgl.yacc"
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
#line 2644 "fgl.yacc"
    {
	char buff[256];
	sprintf(buff,"push_int(%d);",length_expr(yyvsp[-1].ptr));
	yyval.ptr=append_expr(yyvsp[-1].ptr,buff);
	append_expr(yyval.ptr,"pushop(OP_IN);");
}
    break;

  case 441:
#line 2650 "fgl.yacc"
    {
	char buff[256];
	sprintf(buff,"push_int(%d);",length_expr(yyvsp[-1].ptr));
	yyval.ptr=append_expr(yyvsp[-1].ptr,buff);
	append_expr(yyval.ptr,"pushop(OP_NOTIN);");
}
    break;

  case 442:
#line 2660 "fgl.yacc"
    { 
	strcpy(yyval.str,"pushop(OP_ISNULL);");
	yyval.ptr=new_expr(yyval.str);
}
    break;

  case 443:
#line 2665 "fgl.yacc"
    {
	strcpy(yyval.str,"pushop(OP_ISNOTNULL);");
	yyval.ptr=new_expr(yyval.str);
}
    break;

  case 444:
#line 2673 "fgl.yacc"
    {
	yyval.ptr=append_expr(yyvsp[0].ptr,"pushop(OP_MATCHES);");
}
    break;

  case 445:
#line 2677 "fgl.yacc"
    {
	yyval.ptr=append_expr(yyvsp[0].ptr,"pushop(OP_MATCHES);pushop(OP_NOT);");
}
    break;

  case 446:
#line 2681 "fgl.yacc"
    {
	yyval.ptr=append_expr(yyvsp[0].ptr,"pushop(OP_LIKE);");
}
    break;

  case 447:
#line 2685 "fgl.yacc"
    {
	yyval.ptr=append_expr(yyvsp[0].ptr,"pushop(OP_LIKE);pushop(OP_NOT);");
}
    break;

  case 448:
#line 2692 "fgl.yacc"
    {
	strcpy(yyval.str,"pushop(OP_CLIP);");
	yyval.ptr=new_expr(yyval.str);
	inc_counter();
}
    break;

  case 449:
#line 2700 "fgl.yacc"
    {
	sprintf(yyval.str,"%s pushop(OP_USING);",yyvsp[0].str);
	yyval.ptr=append_expr(yyvsp[0].ptr,"pushop(OP_USING);");
}
    break;

  case 450:
#line 2708 "fgl.yacc"
    {
	debug("PLUS in math_expr $<ptr>2 = %p",yyvsp[0].ptr);
	yyval.ptr=append_expr(yyvsp[0].ptr,"pushop(OP_ADD);");
}
    break;

  case 451:
#line 2713 "fgl.yacc"
    {
	yyval.ptr=append_expr(yyvsp[0].ptr,"pushop(OP_SUB);");
}
    break;

  case 452:
#line 2717 "fgl.yacc"
    {
      sprintf(yyval.str,"%s pushop(OP_MULT);",yyvsp[0].str);
	yyval.ptr=append_expr(yyvsp[0].ptr,"pushop(OP_MULT);");
}
    break;

  case 453:
#line 2722 "fgl.yacc"
    {
	yyval.ptr=append_expr(yyvsp[0].ptr,"pushop(OP_DIV);");
}
    break;

  case 454:
#line 2726 "fgl.yacc"
    {
	yyval.ptr=append_expr(yyvsp[0].ptr,"pushop(OP_MOD);");
}
    break;

  case 455:
#line 2730 "fgl.yacc"
    {
	yyval.ptr=append_expr(yyvsp[0].ptr,"pushop(OP_POWER);");
}
    break;

  case 456:
#line 2736 "fgl.yacc"
    {
	yyval.ptr=append_expr(yyvsp[0].ptr,"pushop(OP_EQUAL);");
}
    break;

  case 457:
#line 2739 "fgl.yacc"
    {
	yyval.ptr=append_expr(yyvsp[0].ptr,"pushop(OP_EQUAL);");
}
    break;

  case 458:
#line 2743 "fgl.yacc"
    {
	yyval.ptr=append_expr(yyvsp[0].ptr,"pushop(OP_LESS_THAN);");
}
    break;

  case 459:
#line 2747 "fgl.yacc"
    {
	yyval.ptr=append_expr(yyvsp[0].ptr,"pushop(OP_GREATER_THAN);");
}
    break;

  case 460:
#line 2751 "fgl.yacc"
    {
	yyval.ptr=append_expr(yyvsp[0].ptr,"pushop(OP_NOT_EQUAL);");
}
    break;

  case 461:
#line 2755 "fgl.yacc"
    {
	yyval.ptr=append_expr(yyvsp[0].ptr,"pushop(OP_LESS_THAN_EQ);");
}
    break;

  case 462:
#line 2759 "fgl.yacc"
    {
	yyval.ptr=append_expr(yyvsp[0].ptr,"pushop(OP_GREATER_THAN_EQ);");
}
    break;

  case 463:
#line 2766 "fgl.yacc"
    {
	reset_counter();
}
    break;

  case 464:
#line 2776 "fgl.yacc"
    { 
		addmap("Call",yyvsp[-1].str,curr_func,yylineno,infilename);
		new_counter(); 
		}
    break;

  case 465:
#line 2781 "fgl.yacc"
    { 
		sprintf(yyval.str,"%d",get_counter_val()); 
		lex_printcomment("/*function_call_expr2 %s*/\n",yyval.str);
		drop_counter(); 
		}
    break;

  case 466:
#line 2787 "fgl.yacc"
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
#line 2796 "fgl.yacc"
    {
        sprintf(yyval.str,"\"%s\",\"%s\"",get_idents(0),get_idents(1));
	debug("NEWFORMAT : %s\n",yyval.str);
        A4GLSQL_set_status(0,0);
        new_counter();
}
    break;

  case 468:
#line 2801 "fgl.yacc"
    {
	sprintf(yyval.str,"%d",get_counter_val());  
	drop_counter();
}
    break;

  case 469:
#line 2804 "fgl.yacc"
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
#line 2818 "fgl.yacc"
    {inc_counter();chk4var=1;}
    break;

  case 471:
#line 2818 "fgl.yacc"
    {chk4var=0;}
    break;

  case 472:
#line 2818 "fgl.yacc"
    {
	yyval.ptr=append_expr(yyvsp[-2].ptr,"aclfgl_date(1);");
inc_counter();}
    break;

  case 473:
#line 2821 "fgl.yacc"
    {inc_counter();chk4var=1;}
    break;

  case 474:
#line 2821 "fgl.yacc"
    {chk4var=0;}
    break;

  case 475:
#line 2821 "fgl.yacc"
    {
	yyval.ptr=append_expr(yyvsp[-2].ptr,"aclfgl_month(1);");
inc_counter();}
    break;

  case 476:
#line 2824 "fgl.yacc"
    {inc_counter();chk4var=1;}
    break;

  case 477:
#line 2824 "fgl.yacc"
    {chk4var=0;}
    break;

  case 478:
#line 2824 "fgl.yacc"
    {
	yyval.ptr=append_expr(yyvsp[-2].ptr,"aclfgl_day(1);");
inc_counter();}
    break;

  case 479:
#line 2827 "fgl.yacc"
    {inc_counter();chk4var=1;}
    break;

  case 480:
#line 2827 "fgl.yacc"
    {chk4var=0;}
    break;

  case 481:
#line 2827 "fgl.yacc"
    {
	yyval.ptr=append_expr(yyvsp[-2].ptr,"aclfgl_year(1);");
inc_counter();}
    break;

  case 482:
#line 2830 "fgl.yacc"
    {
	char buff[256];
	sprintf(buff,"acli_interval(%s,%s);",yyvsp[-2].str,yyvsp[0].str);
	yyval.ptr=new_expr(buff);
	inc_counter();
}
    break;

  case 483:
#line 2836 "fgl.yacc"
    {
	char buff[256];
	sprintf(buff,"acli_datetime(%s,%s)",yyvsp[-2].str,yyvsp[0].str);
	yyval.ptr=new_expr(buff);
	inc_counter();
}
    break;

  case 484:
#line 2842 "fgl.yacc"
    {
	char buff[256];
	sprintf(buff,"acli_datetime(\"%s\",%s)",yyvsp[-2].str,yyvsp[0].str);
	yyval.ptr=new_expr(buff);
	inc_counter();
}
    break;

  case 485:
#line 2848 "fgl.yacc"
    {
	char buff[256];
	sprintf(buff,"acli_datetime(\"%s:%s\",%s)",yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str);
	yyval.ptr=new_expr(buff);
	inc_counter();
}
    break;

  case 486:
#line 2858 "fgl.yacc"
    {strcpy(yyval.str,"-1,-1");}
    break;

  case 487:
#line 2859 "fgl.yacc"
    {sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 490:
#line 2867 "fgl.yacc"
    {
sprintf(yyval.str,"{int _retvars;\n_retvars=fgl_getfldbuf(%s);\nif (_retvars != 1 ) {A4GLSQL_set_status(-3001,0);chk_err(%d,\"%s\");}\n}\n",
	yyvsp[-1].str, lastlineno,infilename); 
	yyval.ptr=new_expr(yyval.str);

}
    break;

  case 491:
#line 2873 "fgl.yacc"
    {sprintf(yyval.str,"push_int(fgl_fieldnametoid(\"\",%s));",yyvsp[-1].str); yyval.ptr=new_expr(yyval.str); }
    break;

  case 492:
#line 2874 "fgl.yacc"
    {
sprintf(yyval.str,"push_int(fgl_fieldnametoid(\"\",%s));",yyvsp[-1].str); yyval.ptr=new_expr(yyval.str); 
addmap("Get Field",yyvsp[-1].str,curr_func,yylineno,infilename);
}
    break;

  case 493:
#line 2879 "fgl.yacc"
    {sprintf(yyval.str,"push_int(fgl_infield(%s));",yyvsp[-1].str); 
	yyval.ptr=new_expr(yyval.str);
}
    break;

  case 494:
#line 2883 "fgl.yacc"
    { sprintf(yyval.str,"push_int(fgl_fieldtouched(%s));",yyvsp[-1].str); 
	yyval.ptr=new_expr(yyval.str);
}
    break;

  case 495:
#line 2887 "fgl.yacc"
    { sprintf(yyval.str,"push_int(!fgl_fieldtouched(%s));",yyvsp[-1].str); 
	yyval.ptr=new_expr(yyval.str);
}
    break;

  case 498:
#line 2894 "fgl.yacc"
    {
		inc_counter();
               sprintf(yyval.str,"push_current(%s);",yyvsp[0].str);
		yyval.ptr=new_expr(yyval.str);
          	}
    break;

  case 499:
#line 2899 "fgl.yacc"
    { inc_counter(); strcpy(yyval.str,"push_today();");
		yyval.ptr=new_expr(yyval.str);
		}
    break;

  case 500:
#line 2906 "fgl.yacc"
    { 
	yyval.ptr=append_expr(yyvsp[-1].ptr,"upshift_stk();");
}
    break;

  case 501:
#line 2910 "fgl.yacc"
    { 
	yyval.ptr=append_expr(yyvsp[-1].ptr,"downshift_stk();");
}
    break;

  case 502:
#line 2913 "fgl.yacc"
    { 
	yyval.ptr=append_expr(yyvsp[0].ptr,"push_ascii();");
}
    break;

  case 503:
#line 2916 "fgl.yacc"
    { 
	yyval.ptr=append_expr(yyvsp[0].ptr,"aclfgli_extend();"); }
    break;

  case 504:
#line 2922 "fgl.yacc"
    {
	yyval.ptr=append_expr(yyvsp[-1].ptr,"push_double(-1);pushop(OP_MULT);");
}
    break;

  case 505:
#line 2925 "fgl.yacc"
    {
	yyval.ptr=append_expr(yyvsp[-1].ptr,"push_double(-28.3465);pushop(OP_MULT);");
}
    break;

  case 506:
#line 2928 "fgl.yacc"
    {
	yyval.ptr=append_expr(yyvsp[-1].ptr,"push_double(-72.0);pushop(OP_MULT);");
}
    break;

  case 507:
#line 2943 "fgl.yacc"
    {
	strcpy(yyval.str,yyvsp[0].str);
}
    break;

  case 508:
#line 2946 "fgl.yacc"
    {
	strcpy(yyval.str,yyvsp[0].str);
}
    break;

  case 509:
#line 2952 "fgl.yacc"
    {sprintf(yyval.str,"-%s",yyvsp[0].str);}
    break;

  case 510:
#line 2953 "fgl.yacc"
    {sprintf(yyval.str,"\"%s\"",yyvsp[0].str);}
    break;

  case 511:
#line 2954 "fgl.yacc"
    {sprintf(yyval.str,"\"%s\"",yyvsp[0].str);}
    break;

  case 513:
#line 2959 "fgl.yacc"
    {sprintf(yyval.str,"%s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 514:
#line 2960 "fgl.yacc"
    {sprintf(yyval.str,"%s %s:%s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 515:
#line 2961 "fgl.yacc"
    {sprintf(yyval.str,"%s %s:%s:%s",yyvsp[-5].str,yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 516:
#line 2962 "fgl.yacc"
    {sprintf(yyval.str,"%s %s:%s:%s",yyvsp[-5].str,yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 517:
#line 2964 "fgl.yacc"
    {sprintf(yyval.str,"%s:%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 518:
#line 2965 "fgl.yacc"
    {sprintf(yyval.str,"%s:%s:%s",yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 519:
#line 2966 "fgl.yacc"
    {sprintf(yyval.str,"%s:%s:%s",yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 520:
#line 2968 "fgl.yacc"
    {sprintf(yyval.str,"%s:%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 521:
#line 2969 "fgl.yacc"
    {sprintf(yyval.str,"%s",yyvsp[0].str);}
    break;

  case 523:
#line 2975 "fgl.yacc"
    {sprintf(yyval.str,"%s-%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 524:
#line 2988 "fgl.yacc"
    {
print_for_start(yyvsp[-5].str);
push_blockcommand("FOR");
}
    break;

  case 525:
#line 2992 "fgl.yacc"
    {debug("For_cmds\n");}
    break;

  case 526:
#line 2993 "fgl.yacc"
    {

pop_blockcommand("FOR");
print_for_end();
lex_printcomment(" /*END FOR*/\n");}
    break;

  case 527:
#line 3000 "fgl.yacc"
    {
		print_for_default_step();
	}
    break;

  case 529:
#line 3017 "fgl.yacc"
    {
push_blockcommand("FOREACH");
}
    break;

  case 530:
#line 3021 "fgl.yacc"
    {
print_foreach_start();
lex_printcomment(" /* foreach */\n");
}
    break;

  case 531:
#line 3026 "fgl.yacc"
    {
print_foreach_next(yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 532:
#line 3030 "fgl.yacc"
    {
add_continue_blockcommand ("FOREACH");
print_foreach_end();
pop_blockcommand("FOREACH");
}
    break;

  case 533:
#line 3046 "fgl.yacc"
    {
		sprintf(curr_func,"%s",yyvsp[0].str); 
		print_formhandler(yyvsp[0].str);
		start_state("formhandler",1);
	push_blockcommand("FORMHANDLER");
        }
    break;

  case 534:
#line 3052 "fgl.yacc"
    {
		print_variables();
		print_getwin();
	}
    break;

  case 535:
#line 3060 "fgl.yacc"
    {
pop_blockcommand("FORMHANDLER");
print_end_formhandler(); 
start_state("formhandler",0);}
    break;

  case 542:
#line 3077 "fgl.yacc"
    {
		print_event('B');
        }
    break;

  case 543:
#line 3079 "fgl.yacc"
    {
		print_event_2();
        }
    break;

  case 544:
#line 3082 "fgl.yacc"
    {
		print_event('b');
        }
    break;

  case 545:
#line 3084 "fgl.yacc"
    {
		print_event_2();
        }
    break;

  case 550:
#line 3098 "fgl.yacc"
    {
		print_event('A');
        }
    break;

  case 551:
#line 3100 "fgl.yacc"
    {
		print_event_2();
        }
    break;

  case 552:
#line 3103 "fgl.yacc"
    {
		print_event('a');
        }
    break;

  case 553:
#line 3105 "fgl.yacc"
    {
		print_event_2();
        }
    break;

  case 566:
#line 3136 "fgl.yacc"
    { 
			print_gtk_field('B',0);
		}
    break;

  case 567:
#line 3138 "fgl.yacc"
    {
			print_gtk_field_2();
		}
    break;

  case 568:
#line 3141 "fgl.yacc"
    { 
			print_gtk_field('A',0);
		}
    break;

  case 569:
#line 3143 "fgl.yacc"
    {
			print_gtk_field_2();
		}
    break;

  case 570:
#line 3146 "fgl.yacc"
    {
			print_gtk_field('b',yyvsp[0].str);
		}
    break;

  case 571:
#line 3148 "fgl.yacc"
    { 
			print_gtk_field_2();
		}
    break;

  case 572:
#line 3151 "fgl.yacc"
    {
			print_gtk_field('a',yyvsp[0].str);
		}
    break;

  case 573:
#line 3153 "fgl.yacc"
    { 
			print_gtk_field_2();
		}
    break;

  case 574:
#line 3156 "fgl.yacc"
    { 
			print_gtk_field('o',yyvsp[0].str);
		}
    break;

  case 575:
#line 3158 "fgl.yacc"
    { 
			print_gtk_field_2();
		}
    break;

  case 576:
#line 3173 "fgl.yacc"
    {
		//print_niy("Free Cursor");
		lex_printcomment(" /* FIXME: Not implemented: Free Cursor */\n");;

		strcpy(yyval.str,"");
		}
    break;

  case 577:
#line 3189 "fgl.yacc"
    {sprintf(yyval.str,"%d",-1-(atoi(yyvsp[0].str)));}
    break;

  case 578:
#line 3190 "fgl.yacc"
    {strcpy(yyval.str,"-1");}
    break;

  case 579:
#line 3191 "fgl.yacc"
    {sprintf (yyval.str,"%d",atoi(yyvsp[0].str)+1);}
    break;

  case 580:
#line 3192 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 581:
#line 3193 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 582:
#line 3194 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 586:
#line 3202 "fgl.yacc"
    {sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str); }
    break;

  case 588:
#line 3208 "fgl.yacc"
    {
			sprintf(yyval.str,"\"%s\",1",yyvsp[0].str);}
    break;

  case 589:
#line 3210 "fgl.yacc"
    { sprintf(yyval.str,"int_to_id(%s)",yyvsp[-1].str); }
    break;

  case 590:
#line 3211 "fgl.yacc"
    { sprintf(yyval.str,"int_to_id(%s.%s)",yyvsp[-5].str,yyvsp[-1].str); }
    break;

  case 591:
#line 3213 "fgl.yacc"
    {sprintf(yyval.str,"\"%s\",%s",yyvsp[-3].str,yyvsp[-1].str);}
    break;

  case 592:
#line 3215 "fgl.yacc"
    {sprintf(yyval.str,"\"%s.*\",1",yyvsp[-2].str);}
    break;

  case 593:
#line 3217 "fgl.yacc"
    {sprintf(yyval.str,"\"%s.*\",%s",yyvsp[-5].str,yyvsp[-3].str);}
    break;

  case 594:
#line 3219 "fgl.yacc"
    {sprintf(yyval.str,"\"%s.%s\",1",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 595:
#line 3221 "fgl.yacc"
    {sprintf(yyval.str,"\"%s.%s\",%s",yyvsp[-5].str,yyvsp[0].str,yyvsp[-3].str);}
    break;

  case 596:
#line 3224 "fgl.yacc"
    {
				print_pushchar(yyvsp[0].str);
				addmap("Cursor",last_var,curr_func,yylineno,infilename);
			}
    break;

  case 597:
#line 3231 "fgl.yacc"
    {sprintf(yyval.str,"%s",yyvsp[0].str);}
    break;

  case 598:
#line 3233 "fgl.yacc"
    {sprintf(yyval.str,"%s",yyvsp[0].str);
addmap("Window",last_var,curr_func,yylineno,infilename);
}
    break;

  case 599:
#line 3239 "fgl.yacc"
    {sprintf(yyval.str,"%s",yyvsp[0].str);
addmap("Open Window",last_var,curr_func,yylineno,infilename);
}
    break;

  case 600:
#line 3244 "fgl.yacc"
    {sprintf(yyval.str,"%s",yyvsp[0].str);
addmap("Form",last_var,curr_func,yylineno,infilename);
}
    break;

  case 601:
#line 3249 "fgl.yacc"
    {sprintf(yyval.str,"%s",yyvsp[0].str);
addmap("Open Form",last_var,curr_func,yylineno,infilename);
}
    break;

  case 602:
#line 3254 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 603:
#line 3254 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 604:
#line 3257 "fgl.yacc"
    { 
			strcpy(yyval.str,downshift(yyvsp[-1].str)) ;
}
    break;

  case 605:
#line 3263 "fgl.yacc"
    {
			sprintf(yyval.str,"%s",yyvsp[-1].str) ;
			}
    break;

  case 606:
#line 3268 "fgl.yacc"
    {
sprintf(yyval.str,"\"%s_%s\"",clobber,downshift(yyvsp[0].str)) ;
strcpy(last_var,downshift(yyvsp[0].str));
}
    break;

  case 607:
#line 3272 "fgl.yacc"
    {
		sprintf(yyval.str,"aclfgli_str_to_id(%s)",yyvsp[-1].str);
		sprintf(last_var,"->%s",yyvsp[-1].str);
	}
    break;

  case 610:
#line 3280 "fgl.yacc"
    {
		debug("Setident\n");
		/* chk4var=1; */
	strcpy(yyval.str,"");
	   }
    break;

  case 611:
#line 3286 "fgl.yacc"
    {
		debug("Unsetident\n");
		chk4var=0;
		}
    break;

  case 612:
#line 3290 "fgl.yacc"
    {sprintf(yyval.str,"\"%s\",1",yyvsp[0].str);}
    break;

  case 613:
#line 3292 "fgl.yacc"
    {sprintf(yyval.str,"\"%s\",%s",yyvsp[-3].str,yyvsp[-1].str);}
    break;

  case 614:
#line 3294 "fgl.yacc"
    {sprintf(yyval.str,"\"%s.*\",1",yyvsp[-2].str);}
    break;

  case 615:
#line 3296 "fgl.yacc"
    {sprintf(yyval.str,"\"%s.*\",%s",yyvsp[-5].str,yyvsp[-3].str);}
    break;

  case 616:
#line 3298 "fgl.yacc"
    {sprintf(yyval.str,"\"%s.%s\",1",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 617:
#line 3300 "fgl.yacc"
    {sprintf(yyval.str,"\"%s.%s\",%s",yyvsp[-5].str,yyvsp[0].str,yyvsp[-3].str);}
    break;

  case 618:
#line 3303 "fgl.yacc"
    {
debug("Scanvar=%d",scan_variable(yyvsp[0].str)&15);
if ((scan_variable(yyvsp[0].str)&15)!=0) {
yyerror("Only a character variable can be used for this");
YYERROR;
}
}
    break;

  case 620:
#line 3312 "fgl.yacc"
    {
		sprintf(yyval.str,".%s",yyvsp[0].str);
}
    break;

  case 664:
#line 3373 "fgl.yacc"
    {
	char buff[256];
	print_goto(yyvsp[0].str);
}
    break;

  case 665:
#line 3387 "fgl.yacc"
    {
print_gui_do_menuitems(yyvsp[0].str,'C');
}
    break;

  case 667:
#line 3394 "fgl.yacc"
    {sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 668:
#line 3397 "fgl.yacc"
    {
        sprintf(yyval.str,"\"%s\"",yyvsp[0].str);
}
    break;

  case 669:
#line 3403 "fgl.yacc"
    {
print_gui_do_menuitems(yyvsp[0].str,'U');
}
    break;

  case 670:
#line 3409 "fgl.yacc"
    {
print_gui_do_menuitems(yyvsp[0].str,'D');
}
    break;

  case 671:
#line 3413 "fgl.yacc"
    {
print_gui_do_fields(yyvsp[0].str,'D');
}
    break;

  case 672:
#line 3417 "fgl.yacc"
    {
print_gui_do_form(yyvsp[-2].str,yyvsp[0].str,'D');
}
    break;

  case 673:
#line 3423 "fgl.yacc"
    {
print_gui_do_menuitems(yyvsp[0].str,'E');
}
    break;

  case 674:
#line 3427 "fgl.yacc"
    {
print_gui_do_fields(yyvsp[0].str,'E');
}
    break;

  case 675:
#line 3431 "fgl.yacc"
    {
print_gui_do_form(yyvsp[-2].str,yyvsp[0].str,'E');
}
    break;

  case 676:
#line 3436 "fgl.yacc"
    {start_state("messagebox",1);}
    break;

  case 677:
#line 3441 "fgl.yacc"
    {start_state("messagebox",0);}
    break;

  case 696:
#line 3482 "fgl.yacc"
    {
		print_if_start();
	}
    break;

  case 697:
#line 3487 "fgl.yacc"
    {
		print_if_end();
	}
    break;

  case 699:
#line 3492 "fgl.yacc"
    {
		print_if_else();
	}
    break;

  case 701:
#line 3495 "fgl.yacc"
    {
		print_if_else();
		}
    break;

  case 702:
#line 3497 "fgl.yacc"
    {

		print_if_start();
	}
    break;

  case 703:
#line 3500 "fgl.yacc"
    {
		print_if_end();
	}
    break;

  case 704:
#line 3505 "fgl.yacc"
    {
	print_import(yyvsp[-3].str,atoi(yyvsp[-1].str));
}
    break;

  case 705:
#line 3510 "fgl.yacc"
    { add_ex_dtype(yyvsp[0].str); }
    break;

  case 706:
#line 3520 "fgl.yacc"
    {debug("init to\n");}
    break;

  case 707:
#line 3521 "fgl.yacc"
    {
	print_init();
 }
    break;

  case 708:
#line 3524 "fgl.yacc"
    {
	print_init_table(yyvsp[0].str);
}
    break;

  case 710:
#line 3530 "fgl.yacc"
    {sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 711:
#line 3534 "fgl.yacc"
    {setrecord(yyval.str,yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 712:
#line 3535 "fgl.yacc"
    {setrecord(yyval.str,yyvsp[-2].str,0);}
    break;

  case 715:
#line 3549 "fgl.yacc"
    {
sprintf(yyval.str,"0");
}
    break;

  case 716:
#line 3551 "fgl.yacc"
    {
sprintf(yyval.str,"1");
}
    break;

  case 719:
#line 3560 "fgl.yacc"
    {
		print_befaft_field_1(yyvsp[0].str);
}
    break;

  case 720:
#line 3562 "fgl.yacc"
    {
	print_befaft_field_2();
}
    break;

  case 721:
#line 3566 "fgl.yacc"
    {
		print_befaft_field_1(yyvsp[0].str);
}
    break;

  case 722:
#line 3568 "fgl.yacc"
    {
	print_befaft_field_2();
}
    break;

  case 723:
#line 3571 "fgl.yacc"
    {
		print_befaft_field_1("AFT_ROW");
}
    break;

  case 724:
#line 3573 "fgl.yacc"
    {
	print_befaft_field_2();
}
    break;

  case 725:
#line 3576 "fgl.yacc"
    {
		lex_printcomment("/* before row */ \n");
		print_befaft_field_1("BEF_ROW");
}
    break;

  case 726:
#line 3579 "fgl.yacc"
    {
	print_befaft_field_2();
		}
    break;

  case 727:
#line 3582 "fgl.yacc"
    {
	print_onkey_1(yyvsp[0].str);
}
    break;

  case 728:
#line 3584 "fgl.yacc"
    {
	print_onkey_2();
}
    break;

  case 729:
#line 3587 "fgl.yacc"
    {
		print_befaft_field_1("AFTER_INP");
}
    break;

  case 730:
#line 3589 "fgl.yacc"
    {
	print_befaft_field_2();
}
    break;

  case 731:
#line 3592 "fgl.yacc"
    {
		print_befaft_field_1("BEFORE_INP");
}
    break;

  case 732:
#line 3594 "fgl.yacc"
    {
	print_befaft_field_2();
}
    break;

  case 733:
#line 3597 "fgl.yacc"
    {lex_printcomment("/* before insert/delete */ \n");
		print_befaft_field_1(yyvsp[0].str);
}
    break;

  case 734:
#line 3599 "fgl.yacc"
    {
	print_befaft_field_2();
}
    break;

  case 735:
#line 3602 "fgl.yacc"
    {
		print_befaft_field_1(yyvsp[0].str);
}
    break;

  case 736:
#line 3604 "fgl.yacc"
    {
	print_befaft_field_2();
}
    break;

  case 737:
#line 3610 "fgl.yacc"
    {sprintf(yyval.str,"(%s)",yyvsp[0].str);}
    break;

  case 738:
#line 3611 "fgl.yacc"
    {
	char buff[256];
	sprintf(buff,"(%s)",yyvsp[0].str);
	generate_or(yyval.str,yyvsp[-2].str,buff);
	}
    break;

  case 739:
#line 3619 "fgl.yacc"
    {strcpy(yyval.str,"AFT_INSERT");}
    break;

  case 740:
#line 3620 "fgl.yacc"
    {strcpy(yyval.str,"AFT_DELETE");}
    break;

  case 741:
#line 3625 "fgl.yacc"
    {sprintf(yyval.str,"(%s)",yyvsp[0].str);}
    break;

  case 742:
#line 3626 "fgl.yacc"
    {
	char buff[80];
		sprintf(buff,"(%s)",yyvsp[0].str);
		generate_or(yyval.str,yyvsp[-2].str,yyvsp[0].str);
 }
    break;

  case 743:
#line 3635 "fgl.yacc"
    {strcpy(yyval.str,"BEF_INSERT");}
    break;

  case 744:
#line 3636 "fgl.yacc"
    {strcpy(yyval.str,"BEF_DELETE");}
    break;

  case 745:
#line 3643 "fgl.yacc"
    {sprintf(yyval.str,"BEF_FIELD_CHK(%s)",yyvsp[0].str);}
    break;

  case 746:
#line 3644 "fgl.yacc"
    {
	char buff[80];
	sprintf(buff,"BEF_FIELD_CHK(%s)",yyvsp[0].str);
	generate_or(yyval.str,yyvsp[-2].str,buff);
	}
    break;

  case 747:
#line 3652 "fgl.yacc"
    {sprintf(yyval.str,"AFT_FIELD_CHK(%s)",yyvsp[0].str);}
    break;

  case 748:
#line 3653 "fgl.yacc"
    {
	char buff[80];
	sprintf(buff,"AFT_FIELD_CHK(%s)",yyvsp[0].str);
	generate_or(yyval.str,yyvsp[-2].str,buff);
	}
    break;

  case 749:
#line 3662 "fgl.yacc"
    {
print_next_field(yyvsp[0].str);
}
    break;

  case 750:
#line 3667 "fgl.yacc"
    {
print_next_form_field(yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 751:
#line 3672 "fgl.yacc"
    {sprintf(yyval.str,"\"+\",0");}
    break;

  case 752:
#line 3673 "fgl.yacc"
    {sprintf(yyval.str,"\"-\",0");}
    break;

  case 754:
#line 3678 "fgl.yacc"
    {
print_input_1();
}
    break;

  case 755:
#line 3681 "fgl.yacc"
    {
print_input_2(yyvsp[-2].str);
}
    break;

  case 756:
#line 3689 "fgl.yacc"
    {
print_input(1,yyvsp[-2].str,yyvsp[-1].str,0);
strcpy(yyval.str,get_formloop_str(0));
}
    break;

  case 757:
#line 3694 "fgl.yacc"
    {
print_input(0,yyvsp[-4].str,yyvsp[-1].str,yyvsp[-2].str);
strcpy(yyval.str,get_formloop_str(0));
}
    break;

  case 758:
#line 3698 "fgl.yacc"
    {
inp_flags=0;}
    break;

  case 759:
#line 3700 "fgl.yacc"
    {
strcpy(yyval.str,print_input_array(yyvsp[-8].str,yyvsp[-2].str,yyvsp[-7].str,yyvsp[-5].str,yyvsp[0].str));
}
    break;

  case 760:
#line 3709 "fgl.yacc"
    {
		print_scroll(yyvsp[-1].str,yyvsp[0].str);
	}
    break;

  case 761:
#line 3714 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 762:
#line 3715 "fgl.yacc"
    {strcpy(yyval.str,"-1");}
    break;

  case 763:
#line 3716 "fgl.yacc"
    {sprintf(yyval.str,"%s",yyvsp[0].str);}
    break;

  case 764:
#line 3717 "fgl.yacc"
    {sprintf(yyval.str,"-%s",yyvsp[0].str);}
    break;

  case 765:
#line 3720 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 767:
#line 3726 "fgl.yacc"
    {iskey=1;}
    break;

  case 768:
#line 3726 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);iskey=0;}
    break;

  case 769:
#line 3728 "fgl.yacc"
    {strcpy(yyval.str,"->ANY");}
    break;

  case 770:
#line 3731 "fgl.yacc"
    {iskey=1;}
    break;

  case 771:
#line 3731 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);iskey=0;}
    break;

  case 772:
#line 3733 "fgl.yacc"
    {sprintf(yyval.str,"key_val(\"%s\")",yyvsp[0].str);iskey=0;}
    break;

  case 773:
#line 3737 "fgl.yacc"
    {start_state("keymode",1);iskey=1;}
    break;

  case 774:
#line 3737 "fgl.yacc"
    {sprintf(yyval.str,"key_val(\"%s\")",yyvsp[0].str);iskey=0;start_state("keymode",0);}
    break;

  case 775:
#line 3740 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 776:
#line 3741 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[-1].str);}
    break;

  case 778:
#line 3744 "fgl.yacc"
    {
	sprintf(yyval.str,"%s||%s",yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 779:
#line 3749 "fgl.yacc"
    {start_state("keymode",1);}
    break;

  case 780:
#line 3749 "fgl.yacc"
    {start_state("keymode",0);strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 785:
#line 3756 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 786:
#line 3757 "fgl.yacc"
    {strcpy(yyval.str,"escape");}
    break;

  case 787:
#line 3758 "fgl.yacc"
    {strcpy(yyval.str,"up");}
    break;

  case 788:
#line 3759 "fgl.yacc"
    {strcpy(yyval.str,"down");}
    break;

  case 789:
#line 3760 "fgl.yacc"
    {strcpy(yyval.str,"return");}
    break;

  case 790:
#line 3761 "fgl.yacc"
    {strcpy(yyval.str,"delete");}
    break;

  case 791:
#line 3762 "fgl.yacc"
    {strcpy(yyval.str,"tab");}
    break;

  case 792:
#line 3763 "fgl.yacc"
    {strcpy(yyval.str,"left");}
    break;

  case 793:
#line 3764 "fgl.yacc"
    {strcpy(yyval.str,"right");}
    break;

  case 794:
#line 3765 "fgl.yacc"
    {strcpy(yyval.str,"nextpage");}
    break;

  case 795:
#line 3766 "fgl.yacc"
    {strcpy(yyval.str,"prevpage");}
    break;

  case 796:
#line 3767 "fgl.yacc"
    { rm_quotes(yyvsp[0].str); strcpy(yyval.str,yyvsp[0].str); }
    break;

  case 797:
#line 3771 "fgl.yacc"
    {
char buff[256];
debug("Label : %s\n",get_idents(0));
strcpy(buff,get_idents(0));
convlower(buff);
print_label(buff);
}
    break;

  case 798:
#line 3789 "fgl.yacc"
    {chk4var=1;}
    break;

  case 799:
#line 3789 "fgl.yacc"
    {chk4var=0;
expand_obind();
lex_printcomment("/*let3*/\n");}
    break;

  case 800:
#line 3792 "fgl.yacc"
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
#line 3815 "fgl.yacc"
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
#line 3833 "fgl.yacc"
    {
		if (!print_linked_cmd('S',yyvsp[0].str)) yyerror("Not a linked variable");
	}
    break;

  case 804:
#line 3839 "fgl.yacc"
    {
		 if (!print_linked_cmd('D',yyvsp[0].str)) yyerror("Not a linked variable");
	}
    break;

  case 805:
#line 3845 "fgl.yacc"
    {
		 if (!print_linked_cmd('U',yyvsp[0].str)) yyerror("Not a linked variable");
}
    break;

  case 806:
#line 3851 "fgl.yacc"
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
#line 3862 "fgl.yacc"
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
#line 3885 "fgl.yacc"
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
#line 3901 "fgl.yacc"
    {
	}
    break;

  case 818:
#line 3924 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 822:
#line 3932 "fgl.yacc"
    {
		print_at_termination(yyvsp[0].str);
	}
    break;

  case 840:
#line 3958 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 841:
#line 3959 "fgl.yacc"
    {
strcpy(yyval.str,"static ");
}
    break;

  case 842:
#line 3967 "fgl.yacc"
    {
  clr_variable(); lastlineno=yylineno;
  clr_function_constants (); 
}
    break;

  case 843:
#line 3972 "fgl.yacc"
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
#line 3985 "fgl.yacc"
    {
  lex_printcomment("/* new function %s parameters*/\n",yyvsp[-1].str);
  push_blockcommand("FUNC");
  lex_printcomment("/* define section */\n");
}
    break;

  case 845:
#line 3991 "fgl.yacc"
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
#line 4006 "fgl.yacc"
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
#line 4019 "fgl.yacc"
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
#line 4029 "fgl.yacc"
    {
	print_variables();
    printDeclareFunctionStack("MAIN");
    print_fgllib_start(hdr_dbname);
    printInitFunctionStack();
    printPushFunction();
  }
    break;

  case 850:
#line 4036 "fgl.yacc"
    {
pop_blockcommand("MAIN");
print_main_end();
lex_printcomment("/*end main */\n");}
    break;

  case 851:
#line 4043 "fgl.yacc"
    {
    printPopFunction();
    print_return(atoi(yyvsp[0].str));
  }
    break;

  case 852:
#line 4049 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 853:
#line 4049 "fgl.yacc"
    {
lex_printcomment("/* Got expr list */");
sprintf(yyval.str,"%s",yyvsp[0].str);}
    break;

  case 854:
#line 4054 "fgl.yacc"
    {open_db(yyvsp[0].str);
			strcpy(hdr_dbname,yyvsp[0].str);
			lastlineno=yylineno;}
    break;

  case 855:
#line 4059 "fgl.yacc"
    {
}
    break;

  case 861:
#line 4071 "fgl.yacc"
    {
strcpy(curr_func,"[Globals]");
set_current_variable_scope('g');
lex_printcomment("/* start of globals */\n");
}
    break;

  case 863:
#line 4079 "fgl.yacc"
    {
	lex_printcomment("/* end of globals */");
	debug("end of globals\n");
	lastlineno=yylineno;
	set_current_variable_scope('m');
}
    break;

  case 864:
#line 4085 "fgl.yacc"
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
#line 4099 "fgl.yacc"
    {
  addmap("Define Member Function",curr_func,"MODULE",yylineno,infilename);
}
    break;

  case 866:
#line 4103 "fgl.yacc"
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
#line 4116 "fgl.yacc"
    {
	print_variables();
  lex_printcomment("/*end of define section */\n");
  print_param('f');
  printPushFunction();
  print_func_args(atoi(yyvsp[-3].str));
}
    break;

  case 869:
#line 4134 "fgl.yacc"
    {
	start_state("menu",1);
   	menu_cnt=npush_menu();
   	menu_cmd_cnt[menu_cnt]=1;
   	push_blockcommand("MENU");
	print_menu_1();
	}
    break;

  case 870:
#line 4141 "fgl.yacc"
    {
	start_state("menu",0);
	}
    break;

  case 871:
#line 4147 "fgl.yacc"
    {
   print_end_menu_1();
   add_continue_blockcommand ("MENU");
print_end_menu_2();
   pop_blockcommand("MENU");
   pop_menu();
}
    break;

  case 872:
#line 4158 "fgl.yacc"
    {
	 lex_printcomment("/* Block%d_m2 (Before menu) */",menu_cnt);
		print_menu_block(-2) ;
                  }
    break;

  case 873:
#line 4162 "fgl.yacc"
    {
		print_menu_block_end();
	}
    break;

  case 874:
#line 4169 "fgl.yacc"
    {
debug("Menu=%d menu cnt=%d",menu_cnt,menu_cmd_cnt[menu_cnt]);
		push_command(menu_cnt,menu_cmd_cnt[menu_cnt],yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);
		lex_printcomment("/* Block%d_%d */",menu_cnt,menu_cmd_cnt[menu_cnt]-1);
		print_menu_block(menu_cmd_cnt[menu_cnt]-1);
		menu_cmd_cnt[menu_cnt]++;
		}
    break;

  case 875:
#line 4176 "fgl.yacc"
    {
		print_menu_block_end();
}
    break;

  case 876:
#line 4182 "fgl.yacc"
    {
		push_command(menu_cnt,menu_cmd_cnt[menu_cnt],yyvsp[-1].str,"\"\"","\"\"",0);
		print_menu_block(menu_cmd_cnt[menu_cnt]-1);
		menu_cmd_cnt[menu_cnt]++;
		}
    break;

  case 877:
#line 4187 "fgl.yacc"
    {
		print_menu_block_end();
}
    break;

  case 880:
#line 4194 "fgl.yacc"
    {strcpy(yyval.str,"\"EMPTY\"");}
    break;

  case 881:
#line 4195 "fgl.yacc"
    {sprintf(yyval.str,"\"%s\"",yyvsp[0].str);}
    break;

  case 882:
#line 4197 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str); }
    break;

  case 883:
#line 4198 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 884:
#line 4201 "fgl.yacc"
    {strcpy(yyval.str,"\"\"");}
    break;

  case 885:
#line 4202 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 886:
#line 4203 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 887:
#line 4205 "fgl.yacc"
    {
	print_option_op('N',yyvsp[0].str);
}
    break;

  case 888:
#line 4210 "fgl.yacc"
    {
	print_option_op('S',yyvsp[0].str);
}
    break;

  case 889:
#line 4215 "fgl.yacc"
    {
	print_option_op('H',yyvsp[0].str);
}
    break;

  case 890:
#line 4222 "fgl.yacc"
    {sprintf(yyval.str,"MENU_ALL");}
    break;

  case 894:
#line 4229 "fgl.yacc"
    {sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 895:
#line 4231 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);  
push_menu_title(yyval.str);}
    break;

  case 896:
#line 4233 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str); 
push_menu_title(yyval.str);}
    break;

  case 897:
#line 4242 "fgl.yacc"
    {
                strcpy(menuhandler,yyvsp[0].str);
	sprintf(curr_func,"%s",yyvsp[0].str); 
	print_gtk_menuhandler_1(yyvsp[0].str);
                push_blockcommand("MENUH");
}
    break;

  case 898:
#line 4248 "fgl.yacc"
    {
		print_variables();
        }
    break;

  case 899:
#line 4252 "fgl.yacc"
    {
                        pop_blockcommand("MENUH");
			print_gtk_menuhandler_end();
                }
    break;

  case 902:
#line 4264 "fgl.yacc"
    {

		print_gtk_menuhandler_bsm();

                push_blockcommand("BSM");
        }
    break;

  case 903:
#line 4269 "fgl.yacc"
    {
                pop_blockcommand("BSM");
		print_gtk_menuhandler_bsm_end();

        }
    break;

  case 904:
#line 4274 "fgl.yacc"
    {
print_gtk_menuhandler_on(yyvsp[0].str);
                push_blockcommand("ON");
        }
    break;

  case 905:
#line 4277 "fgl.yacc"
    {
                pop_blockcommand("ON");
		print_gtk_menuhandler_on_end();
}
    break;

  case 906:
#line 4286 "fgl.yacc"
    {start_state("message",0);}
    break;

  case 907:
#line 4289 "fgl.yacc"
    {
		print_message(0,"0",0);
		start_state("message",0);
	   }
    break;

  case 908:
#line 4293 "fgl.yacc"
    { 
		print_message(0,yyvsp[-1].str,atoi(yyvsp[0].str));
		start_state("message",0);
	  }
    break;

  case 909:
#line 4297 "fgl.yacc"
    { 
		print_message(0,"0",atoi(yyvsp[0].str));
		start_state("message",0);
	  }
    break;

  case 916:
#line 4314 "fgl.yacc"
    {start_state("message",1);}
    break;

  case 918:
#line 4316 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 919:
#line 4316 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 920:
#line 4319 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 921:
#line 4329 "fgl.yacc"
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
#line 4366 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 925:
#line 4373 "fgl.yacc"
    { 
         sprintf (yyval.str, "%s.%s", yyvsp[-1].str, yyvsp[0].str); 
         lex_printcomment("/* record building -> %s */\n",yyval.str);
         }
    break;

  case 926:
#line 4378 "fgl.yacc"
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
#line 4422 "fgl.yacc"
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
#line 4436 "fgl.yacc"
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
#line 4460 "fgl.yacc"
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
#line 4514 "fgl.yacc"
    {
		debug("---> Subscript or substring");
		strcpy(yyval.str,yyvsp[-1].str);
	}
    break;

  case 938:
#line 4519 "fgl.yacc"
    {
		debug("---> Subscript & substring");
		sprintf(yyval.str,"%s:%s",yyvsp[-4].str,yyvsp[-1].str);
	}
    break;

  case 939:
#line 4527 "fgl.yacc"
    {
debug("List element");
  sprintf (yyval.str, "%s", yyvsp[0].str);
}
    break;

  case 940:
#line 4532 "fgl.yacc"
    {
debug("List element continues");
  sprintf (yyval.str, "%s,%s", yyvsp[-2].str, yyvsp[0].str);
}
    break;

  case 941:
#line 4540 "fgl.yacc"
    {
  sprintf (yyval.str, "%s", yyvsp[0].str);
}
    break;

  case 942:
#line 4546 "fgl.yacc"
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
#line 4566 "fgl.yacc"
    {
		debug("Array..");
}
    break;

  case 944:
#line 4569 "fgl.yacc"
    { sprintf (yyval.str, "%s.%s", yyvsp[-3].str, yyvsp[0].str); }
    break;

  case 945:
#line 4571 "fgl.yacc"
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
#line 4619 "fgl.yacc"
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
#line 4671 "fgl.yacc"
    {
start_bind('f',0);
start_bind('O',0);
strcpy(yyval.str,"0");}
    break;

  case 953:
#line 4678 "fgl.yacc"
    {
start_bind('f',yyvsp[0].str);
start_bind('O',yyvsp[0].str);
sprintf(yyval.str,"1");
}
    break;

  case 954:
#line 4684 "fgl.yacc"
    {
int c;
c=add_bind('f',yyvsp[0].str);
c=add_bind('O',yyvsp[0].str);
sprintf(yyval.str,"%d",c); 
}
    break;

  case 955:
#line 4695 "fgl.yacc"
    {
lex_printcomment("/*STarted bind %s*/\n",yyvsp[0].str);
start_bind('i',yyvsp[0].str);
lex_printcomment("/*STarted bind 2*/\n");
strcpy(yyval.str,"");
}
    break;

  case 956:
#line 4702 "fgl.yacc"
    {
lex_printcomment("/* Added */\n");
add_bind('i',yyvsp[0].str);
strcpy(yyval.str,"");
}
    break;

  case 958:
#line 4710 "fgl.yacc"
    {sprintf(yyval.str,"%s.%s",yyvsp[-2].str,yyvsp[-1].str);}
    break;

  case 959:
#line 4713 "fgl.yacc"
    {lex_printcomment("/* Variable */\n");}
    break;

  case 960:
#line 4714 "fgl.yacc"
    { debug("Got an ibind thru..."); sprintf(yyval.str,"%s\n%s",yyvsp[-2].str,yyvsp[0].str); }
    break;

  case 962:
#line 4716 "fgl.yacc"
    {sprintf(yyval.str,"\"%s\"",yyvsp[0].str);}
    break;

  case 963:
#line 4717 "fgl.yacc"
    {sprintf(yyval.str,"\"%s\"",yyvsp[0].str);}
    break;

  case 964:
#line 4720 "fgl.yacc"
    {
start_bind('o',yyvsp[0].str);
}
    break;

  case 965:
#line 4723 "fgl.yacc"
    {
add_bind('o',yyvsp[0].str);
strcpy(yyval.str,"");
}
    break;

  case 966:
#line 4729 "fgl.yacc"
    {
	addmap("OBIND",yyvsp[0].str,curr_func,yylineno,infilename);
	}
    break;

  case 967:
#line 4732 "fgl.yacc"
    { debug("Got an obind thru..."); sprintf(yyval.str,"%s\n%s",yyvsp[-2].str,yyvsp[0].str); }
    break;

  case 968:
#line 4736 "fgl.yacc"
    {
lex_printcomment("/* start obind with  %s*/\n",yyvsp[0].str);
start_bind('o',yyvsp[0].str);
}
    break;

  case 969:
#line 4740 "fgl.yacc"
    {
lex_printcomment("/* add to obind %s */\n",yyvsp[0].str);
add_bind('o',yyvsp[0].str);
strcpy(yyval.str,"");
}
    break;

  case 970:
#line 4747 "fgl.yacc"
    {
lex_printcomment("/* Read variable %s*/\n",yyvsp[0].str);
}
    break;

  case 971:
#line 4752 "fgl.yacc"
    {
    lex_printcomment("/* use_arr_var */\n");
    start_arr_bind('o',yyvsp[0].str);
    lex_printcomment("/* use_arr_var complete */\n");
}
    break;

  case 972:
#line 4759 "fgl.yacc"
    {
start_bind('O',yyvsp[0].str);
}
    break;

  case 973:
#line 4762 "fgl.yacc"
    {
               add_bind('O',yyvsp[0].str);
               strcpy(yyval.str,"");
}
    break;

  case 978:
#line 4775 "fgl.yacc"
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
#line 4788 "fgl.yacc"
    {
lex_printcomment("/*STarted bind %s*/\n",yyvsp[0].str);
start_bind('N',yyvsp[0].str);
lex_printcomment("/*STarted bind 2*/\n");
strcpy(yyval.str,"");
}
    break;

  case 980:
#line 4795 "fgl.yacc"
    {
lex_printcomment("/* Added */\n");
add_bind('N',yyvsp[0].str);
strcpy(yyval.str,"");
}
    break;

  case 981:
#line 4802 "fgl.yacc"
    {
		strcpy(yyval.str,yyvsp[0].str);
	}
    break;

  case 982:
#line 4805 "fgl.yacc"
    {
			sprintf(yyval.str,"%s\n%s",yyvsp[-2].str,yyvsp[0].str);
		}
    break;

  case 983:
#line 4819 "fgl.yacc"
    {
form_attrib.iswindow=1;
print_open_window(yyvsp[-5].str,yyvsp[-1].str);
sprintf(yyval.str,"open window");
}
    break;

  case 988:
#line 4836 "fgl.yacc"
    {
	print_niy("OPEN_STATUSBOX");
}
    break;

  case 989:
#line 4841 "fgl.yacc"
    {
addmap("Call Formhandler",yyvsp[0].str,curr_func,yylineno,infilename); 
}
    break;

  case 990:
#line 4847 "fgl.yacc"
    {
		print_open_form(yyvsp[0].str,yyvsp[-1].str,yyvsp[-1].str);
		}
    break;

  case 992:
#line 4854 "fgl.yacc"
    { form_attrib.iswindow=0;strcpy(yyval.str,"open_form(%s);"); }
    break;

  case 993:
#line 4859 "fgl.yacc"
    {sprintf(yyval.str,"open_gui_form(%%s,%s,%s,%s,hnd_e_%s,hnd_c_%s);",yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[0].str,yyvsp[0].str);}
    break;

  case 994:
#line 4862 "fgl.yacc"
    {strcpy(yyval.str,"0,0");}
    break;

  case 995:
#line 4863 "fgl.yacc"
    {sprintf(yyval.str,"%s,2",yyvsp[-5].str);}
    break;

  case 996:
#line 4866 "fgl.yacc"
    {strcpy(yyval.str,"\"\"");}
    break;

  case 997:
#line 4867 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 998:
#line 4870 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 999:
#line 4871 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 1000:
#line 4876 "fgl.yacc"
    {
print_open_session(yyvsp[-3].str,yyvsp[-1].str,yyvsp[0].str);

}
    break;

  case 1001:
#line 4883 "fgl.yacc"
    {
	print_open_cursor(yyvsp[0].str,"0");
}
    break;

  case 1002:
#line 4886 "fgl.yacc"
    {
	print_open_cursor(yyvsp[-3].str,yyvsp[0].str); /* CHANGED from $<str>4 */
}
    break;

  case 1003:
#line 4892 "fgl.yacc"
    {sprintf(yyval.str,"0,0");}
    break;

  case 1004:
#line 4894 "fgl.yacc"
    {sprintf(yyval.str,"%s, %s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1005:
#line 4896 "fgl.yacc"
    {sprintf(yyval.str,"%s, %s",yyvsp[-3].str,yyvsp[0].str);}
    break;

  case 1006:
#line 4898 "fgl.yacc"
    {sprintf(yyval.str,"%s, %s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1007:
#line 4901 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 1008:
#line 4901 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 1009:
#line 4902 "fgl.yacc"
    {strcpy(yyval.str,"2");}
    break;

  case 1010:
#line 4907 "fgl.yacc"
    {
	print_open_session(yyvsp[-1].str,yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 1011:
#line 4915 "fgl.yacc"
    {strcpy(yyval.str,"\"default_conn\"");}
    break;

  case 1012:
#line 4916 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1013:
#line 4921 "fgl.yacc"
    {sprintf(yyval.str,"0,0");}
    break;

  case 1014:
#line 4923 "fgl.yacc"
    {sprintf(yyval.str,"%s, %s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1015:
#line 4925 "fgl.yacc"
    {sprintf(yyval.str,"%s, %s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1019:
#line 4942 "fgl.yacc"
    {
print_options('C',yyvsp[0].str);
}
    break;

  case 1020:
#line 4945 "fgl.yacc"
    {
print_options('E',yyvsp[0].str);
}
    break;

  case 1021:
#line 4948 "fgl.yacc"
    {
print_options('F',yyvsp[0].str);
}
    break;

  case 1022:
#line 4951 "fgl.yacc"
    {
lex_printc("set_option_value('M',%s);\n",yyvsp[0].str);
}
    break;

  case 1023:
#line 4954 "fgl.yacc"
    {
print_options('m',yyvsp[0].str);
}
    break;

  case 1024:
#line 4957 "fgl.yacc"
    {
print_options('P',yyvsp[0].str);
}
    break;

  case 1025:
#line 4960 "fgl.yacc"
    {
print_options('A',yyvsp[0].str);
iskey=0;
}
    break;

  case 1026:
#line 4964 "fgl.yacc"
    {
print_options('D',yyvsp[0].str);
iskey=0;
}
    break;

  case 1027:
#line 4968 "fgl.yacc"
    {
print_options('I',yyvsp[0].str);
iskey=0;
}
    break;

  case 1028:
#line 4972 "fgl.yacc"
    {
print_options('N',yyvsp[0].str);
}
    break;

  case 1029:
#line 4975 "fgl.yacc"
    {
print_options('p',yyvsp[0].str);
iskey=0;
}
    break;

  case 1030:
#line 4979 "fgl.yacc"
    {
print_options('H',yyvsp[0].str);
}
    break;

  case 1031:
#line 4982 "fgl.yacc"
    { print_set_helpfile(yyvsp[0].str); }
    break;

  case 1032:
#line 4983 "fgl.yacc"
    { print_set_langfile(yyvsp[0].str); }
    break;

  case 1033:
#line 4984 "fgl.yacc"
    {
print_options('d',yyvsp[0].str);
}
    break;

  case 1034:
#line 4987 "fgl.yacc"
    {
print_options('i',yyvsp[0].str);
}
    break;

  case 1035:
#line 4990 "fgl.yacc"
    {
print_options('W',"1");
}
    break;

  case 1036:
#line 4993 "fgl.yacc"
    {
print_options('W',"0");
}
    break;

  case 1037:
#line 4996 "fgl.yacc"
    {
print_options('f',"1");
}
    break;

  case 1038:
#line 4999 "fgl.yacc"
    {
print_options('f',"0");
}
    break;

  case 1039:
#line 5002 "fgl.yacc"
    {
print_options('S',"1");
}
    break;

  case 1040:
#line 5005 "fgl.yacc"
    {
print_options('S',"0");
}
    break;

  case 1041:
#line 5022 "fgl.yacc"
    {
	print_prepare(yyvsp[-2].str,yyvsp[0].str);
	addmap("Prepare",yyvsp[-2].str,curr_func,yylineno,infilename);
	print_undo_use(yyvsp[-4].str);
}
    break;

  case 1044:
#line 5032 "fgl.yacc"
    {

print_execute(yyvsp[0].str,0);

addmap("Execute",yyvsp[0].str,curr_func,yylineno,infilename);
}
    break;

  case 1045:
#line 5039 "fgl.yacc"
    {
	addmap("Execute",yyvsp[-2].str,curr_func,yylineno,infilename);
	print_execute(yyvsp[-2].str,1);
}
    break;

  case 1047:
#line 5060 "fgl.yacc"
    {
                push_blockcommand("PROMPT");

	print_prompt_1(yyvsp[-5].str,yyvsp[-3].str,yyvsp[-1].str,yyvsp[0].str) ;
}
    break;

  case 1048:
#line 5065 "fgl.yacc"
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
#line 5078 "fgl.yacc"
    {
		print_niy("GUI PROMPT");
	}
    break;

  case 1050:
#line 5083 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 1051:
#line 5084 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 1052:
#line 5088 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1056:
#line 5094 "fgl.yacc"
    {
	print_onkey_1(yyvsp[0].str);
}
    break;

  case 1057:
#line 5096 "fgl.yacc"
    {
	print_onkey_2_prompt();
}
    break;

  case 1059:
#line 5111 "fgl.yacc"
    {
		start_bind('i',0);
		}
    break;

  case 1060:
#line 5115 "fgl.yacc"
    {
		print_put();
	}
    break;

  case 1061:
#line 5121 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1062:
#line 5122 "fgl.yacc"
    { strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1063:
#line 5125 "fgl.yacc"
    {push_gen(PUTVAL,yyvsp[0].str);}
    break;

  case 1064:
#line 5126 "fgl.yacc"
    {push_gen(PUTVAL,yyvsp[0].str); sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1067:
#line 5142 "fgl.yacc"
    {
addmap("Start Report",yyvsp[-1].str,curr_func,yylineno,infilename);
print_start_report("P","\"lp\"",yyvsp[-1].str);
}
    break;

  case 1068:
#line 5147 "fgl.yacc"
    {
addmap("Start Report",yyvsp[-2].str,curr_func,yylineno,infilename);
print_start_report("F",yyvsp[0].str,yyvsp[-2].str);
}
    break;

  case 1069:
#line 5152 "fgl.yacc"
    {
addmap("Start Report",yyvsp[-2].str,curr_func,yylineno,infilename);
print_start_report("P",yyvsp[0].str,yyvsp[-2].str);
}
    break;

  case 1070:
#line 5157 "fgl.yacc"
    {
addmap("Start Report",yyvsp[0].str,curr_func,yylineno,infilename);
print_start_report("","\"\"",yyvsp[0].str);
}
    break;

  case 1076:
#line 5179 "fgl.yacc"
    {
addmap("Output to report",yyvsp[-5].str,curr_func,yylineno,infilename);
print_output_to_report(yyvsp[-5].str,yyvsp[-1].str); 
}
    break;

  case 1077:
#line 5186 "fgl.yacc"
    {
addmap("Finish Report",yyvsp[0].str,curr_func,yylineno,infilename);
print_finish_report(yyvsp[0].str);
}
    break;

  case 1078:
#line 5192 "fgl.yacc"
    { strcpy(yyval.str,yyvsp[0].str); }
    break;

  case 1079:
#line 5194 "fgl.yacc"
    {
	print_format_every_row();
}
    break;

  case 1083:
#line 5205 "fgl.yacc"
    { push_report_block("FIRST",'P');}
    break;

  case 1084:
#line 5206 "fgl.yacc"
    {print_rep_ret(0);}
    break;

  case 1085:
#line 5208 "fgl.yacc"
    { push_report_block("TRAILER",'T');}
    break;

  case 1086:
#line 5209 "fgl.yacc"
    {print_rep_ret(0);}
    break;

  case 1087:
#line 5211 "fgl.yacc"
    { push_report_block("HEADER",'p');}
    break;

  case 1088:
#line 5212 "fgl.yacc"
    {print_rep_ret(0);}
    break;

  case 1089:
#line 5214 "fgl.yacc"
    { push_report_block("EVERY",'E');}
    break;

  case 1090:
#line 5215 "fgl.yacc"
    {print_rep_ret(0);}
    break;

  case 1091:
#line 5217 "fgl.yacc"
    { push_report_block("LAST",'L');}
    break;

  case 1092:
#line 5218 "fgl.yacc"
    {print_rep_ret(0);}
    break;

  case 1093:
#line 5219 "fgl.yacc"
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
#line 5233 "fgl.yacc"
    {print_rep_ret(0);}
    break;

  case 1095:
#line 5235 "fgl.yacc"
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
#line 5252 "fgl.yacc"
    {print_rep_ret(0);}
    break;

  case 1103:
#line 5264 "fgl.yacc"
    {start_state("skip",1);}
    break;

  case 1104:
#line 5264 "fgl.yacc"
    {
	print_need_lines();
	start_state("skip",0);
}
    break;

  case 1105:
#line 5270 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 1106:
#line 5270 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 1107:
#line 5273 "fgl.yacc"
    {start_state("KWLINE",1);}
    break;

  case 1108:
#line 5273 "fgl.yacc"
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
#line 5283 "fgl.yacc"
    { print_skip_top(); }
    break;

  case 1110:
#line 5284 "fgl.yacc"
    { print_niy("FONT SIZE"); }
    break;

  case 1111:
#line 5285 "fgl.yacc"
    {
			if (rep_type!=REP_TYPE_PDF) {
				yyerror("SKIP BY is only in PDF reports");
				YYERROR;
			}
			print_skip_by(yyvsp[0].str);
		}
    break;

  case 1112:
#line 5292 "fgl.yacc"
    {
			if (rep_type!=REP_TYPE_PDF) {
				yyerror("SKIP TO is only in PDF reports");
				YYERROR;
			}
			print_skip_to(yyvsp[0].str);
		}
    break;

  case 1113:
#line 5304 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1119:
#line 5315 "fgl.yacc"
    {
	print_niy("PRINT AT...");
}
    break;

  case 1120:
#line 5320 "fgl.yacc"
    {
	print_report_print(0,yyvsp[0].str,0);
}
    break;

  case 1121:
#line 5324 "fgl.yacc"
    { 
	print_report_print_file(yyvsp[-1].str,yyvsp[0].str);
}
    break;

  case 1122:
#line 5329 "fgl.yacc"
    { 
	print_report_print_img(yyvsp[-1].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 1123:
#line 5335 "fgl.yacc"
    { strcpy(yyval.str,get_default_scaling());}
    break;

  case 1124:
#line 5336 "fgl.yacc"
    { strcpy(yyval.str,yyvsp[0].str); strcat(yyval.str,yyvsp[0].str); }
    break;

  case 1125:
#line 5337 "fgl.yacc"
    {sprintf(yyval.str,"%s %s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1126:
#line 5341 "fgl.yacc"
    {strcpy(yyval.str,"tiff");}
    break;

  case 1127:
#line 5342 "fgl.yacc"
    {strcpy(yyval.str,"gif");}
    break;

  case 1128:
#line 5343 "fgl.yacc"
    {strcpy(yyval.str,"png");}
    break;

  case 1129:
#line 5344 "fgl.yacc"
    {strcpy(yyval.str,"jpeg");}
    break;

  case 1130:
#line 5348 "fgl.yacc"
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
#line 5358 "fgl.yacc"
    {
strcpy(yyval.str,"0");
}
    break;

  case 1132:
#line 5360 "fgl.yacc"
    {
strcpy(yyval.str,"1");
}
    break;

  case 1133:
#line 5365 "fgl.yacc"
    {
	print_report_print(1,0,yyvsp[0].str);
	}
    break;

  case 1134:
#line 5368 "fgl.yacc"
    {
	print_report_print(1,0,yyvsp[0].str); /* changed from $<str>1 */
}
    break;

  case 1135:
#line 5373 "fgl.yacc"
    {
	strcpy(yyval.str,yyvsp[0].str); 
	}
    break;

  case 1136:
#line 5380 "fgl.yacc"
    {
int a;
a=add_report_agg('S',yyvsp[-2].ptr,yyvsp[0].ptr,racnt);
sprintf(yyval.str,"push_double(_g%d);\n",racnt);
racnt+=a;
}
    break;

  case 1137:
#line 5387 "fgl.yacc"
    {
int a;
a=add_report_agg('C',0,yyvsp[0].ptr,racnt);
sprintf(yyval.str,"push_int(_g%d);\n",racnt);
racnt+=a;
}
    break;

  case 1138:
#line 5394 "fgl.yacc"
    {
int a;
a=add_report_agg('C',0,yyvsp[0].ptr,racnt);
sprintf(yyval.str,"push_int(_g%d);\n",racnt);
racnt+=a;
}
    break;

  case 1139:
#line 5403 "fgl.yacc"
    {
int a;
a=add_report_agg('P',yyvsp[-2].ptr,yyvsp[0].ptr,racnt);
sprintf(yyval.str,"push_double((double)_g%d/(double)_g%d);\n",racnt,racnt+1);
racnt+=a;
}
    break;

  case 1140:
#line 5410 "fgl.yacc"
    {
int a;
a=add_report_agg('A',yyvsp[-2].ptr,yyvsp[0].ptr,racnt);
sprintf(yyval.str,"push_double(_g%d/(double)_g%d);\n",racnt,racnt+1);
racnt+=a;
}
    break;

  case 1141:
#line 5417 "fgl.yacc"
    {
int a;
a=add_report_agg('A',yyvsp[-2].ptr,yyvsp[0].ptr,racnt);
sprintf(yyval.str,"push_double(_g%d/_g%d);\n",racnt,racnt+1);
racnt+=a;
}
    break;

  case 1142:
#line 5424 "fgl.yacc"
    {
int a;
a=add_report_agg('N',yyvsp[-2].ptr,yyvsp[0].ptr,racnt);
sprintf(yyval.str,"push_double(_g%d);\n",racnt);
racnt+=a;
}
    break;

  case 1143:
#line 5431 "fgl.yacc"
    {
int a;
a=add_report_agg('X',yyvsp[-2].ptr,yyvsp[0].ptr,racnt);
sprintf(yyval.str,"push_double(_g%d);\n",racnt);
racnt+=a;
}
    break;

  case 1148:
#line 5444 "fgl.yacc"
    {rep_struct.left_margin=atoi(yyvsp[0].str);}
    break;

  case 1149:
#line 5445 "fgl.yacc"
    {rep_struct.right_margin=atoi(yyvsp[0].str);}
    break;

  case 1150:
#line 5446 "fgl.yacc"
    {rep_struct.top_margin=atoi(yyvsp[0].str);}
    break;

  case 1151:
#line 5447 "fgl.yacc"
    {rep_struct.bottom_margin=atoi(yyvsp[0].str);}
    break;

  case 1152:
#line 5448 "fgl.yacc"
    {rep_struct.page_length=atoi(yyvsp[0].str);}
    break;

  case 1153:
#line 5449 "fgl.yacc"
    { rep_struct.output_mode='P';strcpy(rep_struct.output_loc,"\"lp\"");}
    break;

  case 1154:
#line 5450 "fgl.yacc"
    {rep_struct.output_mode='F';strcpy(rep_struct.output_loc,yyvsp[0].str);}
    break;

  case 1155:
#line 5451 "fgl.yacc"
    {rep_struct.output_mode='F';strcpy(rep_struct.output_loc,yyvsp[0].str);}
    break;

  case 1156:
#line 5452 "fgl.yacc"
    {rep_struct.output_mode='P';strcpy(rep_struct.output_loc,yyvsp[0].str);}
    break;

  case 1157:
#line 5453 "fgl.yacc"
    {strcpy(rep_struct.top_of_page,yyvsp[0].str);}
    break;

  case 1160:
#line 5459 "fgl.yacc"
    {sprintf(yyval.str,"-%f",atof(yyvsp[-1].str));}
    break;

  case 1161:
#line 5460 "fgl.yacc"
    {sprintf(yyval.str,"-%f",atof(yyvsp[-1].str)*72.0); }
    break;

  case 1162:
#line 5461 "fgl.yacc"
    {sprintf(yyval.str,"-%f",atof(yyvsp[-1].str)*2.83465);}
    break;

  case 1163:
#line 5462 "fgl.yacc"
    {sprintf(yyval.str,"%f",atof(yyvsp[0].str));}
    break;

  case 1168:
#line 5471 "fgl.yacc"
    {pdf_rep_struct.left_margin=atof(yyvsp[0].str);debug("Left margin=%s\n",yyvsp[0].str);}
    break;

  case 1169:
#line 5472 "fgl.yacc"
    {pdf_rep_struct.right_margin=atof(yyvsp[0].str);}
    break;

  case 1170:
#line 5473 "fgl.yacc"
    {pdf_rep_struct.top_margin=atof(yyvsp[0].str);}
    break;

  case 1171:
#line 5474 "fgl.yacc"
    {pdf_rep_struct.bottom_margin=atof(yyvsp[0].str);}
    break;

  case 1172:
#line 5475 "fgl.yacc"
    {pdf_rep_struct.page_length=atof(yyvsp[0].str);}
    break;

  case 1173:
#line 5476 "fgl.yacc"
    {pdf_rep_struct.page_width=atof(yyvsp[0].str);}
    break;

  case 1174:
#line 5477 "fgl.yacc"
    {strcpy(pdf_rep_struct.font_name,yyvsp[0].str);}
    break;

  case 1175:
#line 5478 "fgl.yacc"
    {pdf_rep_struct.font_size=atof(yyvsp[0].str);}
    break;

  case 1176:
#line 5480 "fgl.yacc"
    {pdf_rep_struct.paper_size=1;}
    break;

  case 1177:
#line 5481 "fgl.yacc"
    {pdf_rep_struct.paper_size=2;}
    break;

  case 1178:
#line 5482 "fgl.yacc"
    {pdf_rep_struct.paper_size=3;}
    break;

  case 1179:
#line 5483 "fgl.yacc"
    {pdf_rep_struct.paper_size=5;}
    break;

  case 1180:
#line 5485 "fgl.yacc"
    {pdf_rep_struct.paper_size=-1;}
    break;

  case 1181:
#line 5486 "fgl.yacc"
    {pdf_rep_struct.paper_size=-2;}
    break;

  case 1182:
#line 5487 "fgl.yacc"
    {pdf_rep_struct.paper_size=-3;}
    break;

  case 1183:
#line 5488 "fgl.yacc"
    {pdf_rep_struct.paper_size=-5;}
    break;

  case 1187:
#line 5493 "fgl.yacc"
    {pdf_rep_struct.output_mode='F';strcpy(pdf_rep_struct.output_loc,yyvsp[0].str);}
    break;

  case 1188:
#line 5494 "fgl.yacc"
    {pdf_rep_struct.output_mode='P';strcpy(pdf_rep_struct.output_loc,yyvsp[0].str);}
    break;

  case 1192:
#line 5501 "fgl.yacc"
    {
int a;
a=print_bind('O');
print_order_by_type(2);
sprintf(yyval.str,"%d",a);
}
    break;

  case 1193:
#line 5508 "fgl.yacc"
    {
int a;
a=print_bind('O');
print_order_by_type(1);
sprintf(yyval.str,"%d",a);
debug("Order by Gives :%d\n",a);
}
    break;

  case 1194:
#line 5515 "fgl.yacc"
    {
int a;
a=print_bind('O');
print_order_by_type(2);
sprintf(yyval.str,"%d",a);
debug("Order by Gives :%d\n",a);
}
    break;

  case 1195:
#line 5526 "fgl.yacc"
    { 
		rep_type=REP_TYPE_NORMAL; 
		clr_function_constants (); 
		clr_variable(); 
		lastlineno=yylineno; 
		init_report_structure(&rep_struct); 
		}
    break;

  case 1196:
#line 5535 "fgl.yacc"
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
#line 5546 "fgl.yacc"
    {
		lastlineno=yylineno;
		}
    break;

  case 1198:
#line 5550 "fgl.yacc"
    {
		print_variables();
		}
    break;

  case 1199:
#line 5554 "fgl.yacc"
    {
		print_report_2(0,yyvsp[0].str);
		rordcnt=atoi(yyvsp[0].str);
		debug("SET rordcnt=%d %s",rordcnt,yyvsp[0].str);
		}
    break;

  case 1200:
#line 5560 "fgl.yacc"
    {
		print_report_ctrl();
		}
    break;

  case 1201:
#line 5565 "fgl.yacc"
    {
		pop_blockcommand("REPORT");
		print_report_end() ;
		}
    break;

  case 1202:
#line 5573 "fgl.yacc"
    { strcpy(yyval.str,"");
	yyval.ptr=0;
}
    break;

  case 1203:
#line 5576 "fgl.yacc"
    {
	yyval.ptr=yyvsp[0].ptr;
//sprintf($<str>$,"%s", $<str>2);
}
    break;

  case 1204:
#line 5585 "fgl.yacc"
    {
if (!in_command("REPORT")) {
	yyerror("PAUSE can only be used in reportes");
	YYERROR;
        }

print_pause(yyvsp[0].str) ;
}
    break;

  case 1205:
#line 5596 "fgl.yacc"
    {strcpy(yyval.str,"\"\"");}
    break;

  case 1207:
#line 5603 "fgl.yacc"
    {
rep_type=REP_TYPE_PDF;
clr_variable(); lastlineno=yylineno; pdf_init_report_structure(&pdf_rep_struct);
}
    break;

  case 1208:
#line 5608 "fgl.yacc"
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
#line 5618 "fgl.yacc"
    {
lastlineno=yylineno;
}
    break;

  case 1210:
#line 5621 "fgl.yacc"
    {
	print_variables();
}
    break;

  case 1211:
#line 5625 "fgl.yacc"
    {
print_variables();
resize_paper(&pdf_rep_struct);
	print_report_2(1,yyvsp[0].str);
debug("SET rordcnt=%d (%s)",rordcnt,yyvsp[0].str);
	rordcnt=atoi(yyvsp[0].str);
}
    break;

  case 1212:
#line 5633 "fgl.yacc"
    {
print_report_ctrl();
}
    break;

  case 1213:
#line 5636 "fgl.yacc"
    {
	pop_blockcommand("REPORT");
	print_report_end();
}
    break;

  case 1214:
#line 5642 "fgl.yacc"
    { strcpy(yyval.str,yyvsp[0].str); }
    break;

  case 1215:
#line 5646 "fgl.yacc"
    {new_counter();
   		addmap("CALL",yyvsp[-1].str,curr_func,yylineno,infilename);
   		}
    break;

  case 1216:
#line 5650 "fgl.yacc"
    {
		sprintf(yyval.str,"%d",get_counter_val());drop_counter();
		}
    break;

  case 1217:
#line 5654 "fgl.yacc"
    {
		print_pdf_call(yyvsp[-5].str,yyvsp[-2].ptr,yyvsp[-1].str);
   		}
    break;

  case 1218:
#line 5658 "fgl.yacc"
    {
	print_returning();
   }
    break;

  case 1219:
#line 5664 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 1220:
#line 5665 "fgl.yacc"
    { strcpy(yyval.str,"rep.right_margin"); }
    break;

  case 1221:
#line 5666 "fgl.yacc"
    { sprintf(yyval.str,"%s",yyvsp[0].str); }
    break;

  case 1222:
#line 5667 "fgl.yacc"
    { sprintf(yyval.str,"%s",yyvsp[0].str); }
    break;

  case 1223:
#line 5672 "fgl.yacc"
    {
print_system_run(0,0);
}
    break;

  case 1224:
#line 5674 "fgl.yacc"
    {
print_system_run(1,yyvsp[0].str);
}
    break;

  case 1225:
#line 5677 "fgl.yacc"
    {
print_system_run(2,0);
}
    break;

  case 1226:
#line 5681 "fgl.yacc"
    {
print_system_run(0,0);
}
    break;

  case 1227:
#line 5684 "fgl.yacc"
    {
print_system_run(0,0);
/* FIXME */
}
    break;

  case 1228:
#line 5691 "fgl.yacc"
    {
	print_exec_sql(yyvsp[0].str);
}
    break;

  case 1229:
#line 5696 "fgl.yacc"
    {sprintf(yyval.str, "%s",yyvsp[0].str);}
    break;

  case 1230:
#line 5697 "fgl.yacc"
    {sprintf(yyval.str,  "%s",yyvsp[0].str);}
    break;

  case 1231:
#line 5698 "fgl.yacc"
    {sprintf(yyval.str,"%s",yyvsp[0].str);}
    break;

  case 1232:
#line 5703 "fgl.yacc"
    { print_exec_sql(yyvsp[0].str); }
    break;

  case 1233:
#line 5704 "fgl.yacc"
    { print_exec_sql(yyvsp[0].sql_string); 
	free(yyvsp[0].sql_string);
}
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
    {
int sz;
sz=0;
	sz+=strlen(yyvsp[-6].str);
	sz+=strlen(yyvsp[-4].str);
	sz+=strlen(yyvsp[-3].str);
	sz+=strlen(yyvsp[-1].sql_string);
	sz+=strlen(yyvsp[0].str);
	sz+=10;

	yyval.sql_string=malloc(sz);

	sprintf(yyval.sql_string,"%s %s %s %s %s",yyvsp[-6].str,yyvsp[-4].str,yyvsp[-3].str,yyvsp[-1].sql_string,yyvsp[0].str);

	free(yyvsp[-1].sql_string);
}
    break;

  case 1237:
#line 5728 "fgl.yacc"
    {insql=1;}
    break;

  case 1238:
#line 5728 "fgl.yacc"
    {insql=0;}
    break;

  case 1239:
#line 5728 "fgl.yacc"
    {

int sz;
sz=0;
	sz+=strlen(yyvsp[-7].str);
	sz+=strlen(yyvsp[-5].str);
	sz+=strlen(yyvsp[-4].str);
	sz+=strlen(yyvsp[-2].sql_string);
	sz+=strlen(yyvsp[-1].str);
	sz+=strlen(yyvsp[0].str);
	sz+=10;

	yyval.sql_string=malloc(sz);


sprintf(yyval.sql_string,"%s %s %s %s %s %s",yyvsp[-7].str,yyvsp[-5].str,yyvsp[-4].str,yyvsp[-2].sql_string,yyvsp[-1].str,yyvsp[0].str);
	free(yyvsp[-2].sql_string);

}
    break;

  case 1240:
#line 5753 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1241:
#line 5754 "fgl.yacc"
    {
		yyerror("You cannot create a database from within Aubit4gl....");
	}
    break;

  case 1242:
#line 5760 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1243:
#line 5762 "fgl.yacc"
    {sprintf(yyval.str," %s ",yyvsp[0].str);}
    break;

  case 1245:
#line 5769 "fgl.yacc"
    {sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1246:
#line 5773 "fgl.yacc"
    {sprintf(yyval.str,"%s ASC",yyvsp[-1].str);}
    break;

  case 1247:
#line 5774 "fgl.yacc"
    {sprintf(yyval.str,"%s DESC",yyvsp[-1].str);}
    break;

  case 1249:
#line 5779 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	  }
    break;

  case 1250:
#line 5782 "fgl.yacc"
    {
	int sz;
	sz=strlen(yyvsp[-2].sql_string)+strlen(yyvsp[0].str)+2;
	yyval.sql_string=realloc(yyvsp[-2].sql_string,sz);
	sprintf(yyval.sql_string,"%s,%s",yyvsp[-2].sql_string,yyvsp[0].str);
	}
    break;

  case 1253:
#line 5798 "fgl.yacc"
    {sprintf(yyval.str,"%s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1255:
#line 5804 "fgl.yacc"
    {
	print_exec_sql(yyvsp[0].str);
}
    break;

  case 1256:
#line 5808 "fgl.yacc"
    {
	sprintf(yyval.str,"%s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);
}
    break;

  case 1258:
#line 5815 "fgl.yacc"
    {sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1266:
#line 5831 "fgl.yacc"
    {
		sprintf(yyval.str,"ADD %s",yyvsp[0].str);
	}
    break;

  case 1267:
#line 5834 "fgl.yacc"
    {
		sprintf(yyval.str,"%s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);
	}
    break;

  case 1269:
#line 5842 "fgl.yacc"
    {
		sprintf(yyval.str,"%s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);
	}
    break;

  case 1271:
#line 5849 "fgl.yacc"
    {
		sprintf(yyval.str,"%s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);
	}
    break;

  case 1272:
#line 5856 "fgl.yacc"
    {
		sprintf(yyval.str,"DROP %s",yyvsp[0].str);
	}
    break;

  case 1273:
#line 5859 "fgl.yacc"
    {
		sprintf(yyval.str,"DROP (%s)",yyvsp[-1].str);
	}
    break;

  case 1275:
#line 5867 "fgl.yacc"
    {
		sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);
	}
    break;

  case 1277:
#line 5876 "fgl.yacc"
    {
		sprintf(yyval.str,"MODIFY %s",yyvsp[0].str);
	}
    break;

  case 1278:
#line 5879 "fgl.yacc"
    {
		sprintf(yyval.str,"MODIFY (%s)",yyvsp[-1].str);
	}
    break;

  case 1280:
#line 5886 "fgl.yacc"
    {
		sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);
	}
    break;

  case 1282:
#line 5897 "fgl.yacc"
    {strcpy(yyval.str,"LOCK MODE PAGE");}
    break;

  case 1283:
#line 5898 "fgl.yacc"
    {strcpy(yyval.str,"LOCK MODE ROW");}
    break;

  case 1284:
#line 5902 "fgl.yacc"
    {
		sprintf(yyval.str,"MODIFT NEXT SIZE %d",atoi(yyvsp[0].str));
	}
    break;

  case 1286:
#line 5909 "fgl.yacc"
    {
		sprintf(yyval.str,"ADD CONSTRAINT (%s)",yyvsp[-1].str);
	}
    break;

  case 1288:
#line 5917 "fgl.yacc"
    {
		sprintf(yyval.str,"ADD CONSTRAINT (%s)",yyvsp[-1].str);
	}
    break;

  case 1290:
#line 5923 "fgl.yacc"
    {
		sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);
	}
    break;

  case 1294:
#line 5941 "fgl.yacc"
    {sprintf(yyval.str,"%s %s /*FIXME */",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1300:
#line 5947 "fgl.yacc"
    { 
	print_set_conn(yyvsp[0].str);
}
    break;

  case 1301:
#line 5950 "fgl.yacc"
    {
	print_set_options("conn",yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 1302:
#line 5953 "fgl.yacc"
    {
	print_set_options("stmt",yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 1303:
#line 5959 "fgl.yacc"
    {strcpy(yyval.str,"\"default\"");}
    break;

  case 1305:
#line 5965 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1307:
#line 5976 "fgl.yacc"
    {
		print_sleep();
	}
    break;

  case 1308:
#line 5990 "fgl.yacc"
    {
		strcpy(current_upd_table,yyvsp[0].str);
	}
    break;

  case 1309:
#line 5992 "fgl.yacc"
    {
		strcpy(current_upd_table,"");
	}
    break;

  case 1310:
#line 5996 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s %s",yyvsp[-6].str,yyvsp[-5].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1311:
#line 5999 "fgl.yacc"
    {strcpy(yyval.str,"");
		pop_all_gen(UPDCOL,"!"); pop_all_gen(UPDVAL,"!");
	}
    break;

  case 1312:
#line 6002 "fgl.yacc"
    { 
		pop_all_gen(UPDCOL,"!"); pop_all_gen(UPDVAL,"!");
		rm_quotes(yyvsp[0].str);
		sprintf(yyval.str," %s %s",yyvsp[-1].str,yyvsp[0].str);
	}
    break;

  case 1313:
#line 6007 "fgl.yacc"
    {
		pop_all_gen(UPDCOL,"!"); pop_all_gen(UPDVAL,"!");
		sprintf(yyval.str," %s %s",yyvsp[-1].str,yyvsp[0].str);
	}
    break;

  case 1314:
#line 6015 "fgl.yacc"
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

  case 1316:
#line 6025 "fgl.yacc"
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

  case 1317:
#line 6034 "fgl.yacc"
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

  case 1319:
#line 6054 "fgl.yacc"
    {
sprintf(yyval.str," %s , %s",yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 1321:
#line 6063 "fgl.yacc"
    {
sprintf(yyval.str," %s = %s",yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 1322:
#line 6068 "fgl.yacc"
    {push_gen(UPDCOL,yyvsp[0].str); strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1323:
#line 6069 "fgl.yacc"
    {push_gen(UPDCOL,yyvsp[0].str); sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1325:
#line 6073 "fgl.yacc"
    { sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1326:
#line 6077 "fgl.yacc"
    {push_gen(UPDVAL,"<SUBQUERY>");}
    break;

  case 1327:
#line 6078 "fgl.yacc"
    {push_gen(UPDVAL,"NULL");}
    break;

  case 1329:
#line 6084 "fgl.yacc"
    {
		print_sql_commit(0);
		}
    break;

  case 1330:
#line 6093 "fgl.yacc"
    { insql=1;start_bind('i',0);}
    break;

  case 1331:
#line 6094 "fgl.yacc"
    {
sprintf(yyval.str," %s %s %s %s",yyvsp[-4].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);
}
    break;

  case 1332:
#line 6099 "fgl.yacc"
    {insql=1;}
    break;

  case 1333:
#line 6099 "fgl.yacc"
    {
insql=0;
sprintf(yyval.str," %s %s %s %s" ,yyvsp[-4].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1335:
#line 6105 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1336:
#line 6107 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1338:
#line 6114 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1340:
#line 6120 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1343:
#line 6130 "fgl.yacc"
    {
      print_fetch_1();
    }
    break;

  case 1344:
#line 6134 "fgl.yacc"
    {
      print_fetch_2();
    }
    break;

  case 1345:
#line 6138 "fgl.yacc"
    {
      print_fetch_3(yyvsp[-2].str,yyvsp[0].str);
    }
    break;

  case 1346:
#line 6147 "fgl.yacc"
    {sprintf(yyval.str,"%s,%s",yyvsp[0].str,yyvsp[-1].str);
addmap("Fetch Cursor",yyvsp[0].str,curr_func,yylineno,infilename);
}
    break;

  case 1347:
#line 6151 "fgl.yacc"
    {sprintf(yyval.str,"%s,%d,1",yyvsp[0].str,FETCH_RELATIVE);

addmap("Fetch Cursor",yyvsp[0].str,curr_func,yylineno,infilename);
}
    break;

  case 1348:
#line 6157 "fgl.yacc"
    {
debug("no into\n");
strcpy(yyval.str,"0,0");
}
    break;

  case 1349:
#line 6161 "fgl.yacc"
    {
	debug("FETCH INTO  ...");
	/* start_bind('i',0,-1); */
    start_bind('o',0);
}
    break;

  case 1350:
#line 6167 "fgl.yacc"
    {
	int no;
	no=print_bind('o');
	sprintf(yyval.str,"%d,obind",no);
}
    break;

  case 1351:
#line 6174 "fgl.yacc"
    {
debug("no into\n");
strcpy(yyval.str,"0,0");
}
    break;

  case 1352:
#line 6178 "fgl.yacc"
    {
	debug("FETCH INTO  ...");
	/* start_bind('i',0,-1); */
    start_bind('o',0);
}
    break;

  case 1353:
#line 6183 "fgl.yacc"
    {
/*
int ni;
ni=print_bind('i');
sprintf($<str>$,"%d,ibind",ni);
*/
}
    break;

  case 1354:
#line 6193 "fgl.yacc"
    {
		sprintf(yyval.str,"%d,1",FETCH_ABSOLUTE);}
    break;

  case 1355:
#line 6196 "fgl.yacc"
    {sprintf(yyval.str,"%d,-1",FETCH_ABSOLUTE);}
    break;

  case 1356:
#line 6198 "fgl.yacc"
    {sprintf(yyval.str,"%d,1",FETCH_RELATIVE);}
    break;

  case 1357:
#line 6200 "fgl.yacc"
    {sprintf(yyval.str,"%d,-1",FETCH_RELATIVE);}
    break;

  case 1358:
#line 6202 "fgl.yacc"
    {sprintf(yyval.str,"%d,-1",FETCH_RELATIVE);}
    break;

  case 1359:
#line 6204 "fgl.yacc"
    {sprintf(yyval.str,"%d,0",FETCH_RELATIVE);}
    break;

  case 1360:
#line 6206 "fgl.yacc"
    {sprintf(yyval.str,"%d,pop_int()",FETCH_RELATIVE);}
    break;

  case 1361:
#line 6208 "fgl.yacc"
    {sprintf(yyval.str,"%d,pop_int()",FETCH_ABSOLUTE);}
    break;

  case 1362:
#line 6214 "fgl.yacc"
    {
 
rm_quotes(yyvsp[0].str);
sprintf(yyval.str," %s %s %s %s ",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str
);}
    break;

  case 1363:
#line 6224 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1364:
#line 6229 "fgl.yacc"
    {sprintf(yyval.str,"%s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1366:
#line 6235 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1370:
#line 6244 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1373:
#line 6249 "fgl.yacc"
    {
print_sql_commit(-1);
}
    break;

  case 1374:
#line 6254 "fgl.yacc"
    {
		print_sql_commit(1);
	}
    break;

  case 1375:
#line 6261 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1376:
#line 6262 "fgl.yacc"
    {
		strcpy(yyval.str,"EXCLUSIVE");
	}
    break;

  case 1377:
#line 6269 "fgl.yacc"
    {
if (strcmp(yyvsp[-1].str,"?")==0) {
	print_init_conn(0);
} else {
	print_init_conn(yyvsp[-1].str);
}
}
    break;

  case 1378:
#line 6281 "fgl.yacc"
    {insql=1;}
    break;

  case 1379:
#line 6281 "fgl.yacc"
    {
print_undo_use(yyvsp[-2].str);
insql=0;strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1380:
#line 6286 "fgl.yacc"
    {lex_printcomment("/*  schema */\n");
	print_exec_sql(yyvsp[0].str);

strcpy(yyval.str,"Schema");
}
    break;

  case 1381:
#line 6291 "fgl.yacc"
    {lex_printcomment("/*  schema  2*/\n");

	print_exec_sql(yyvsp[0].str);

strcpy(yyval.str,"Schema Element");
}
    break;

  case 1383:
#line 6298 "fgl.yacc"
    {
	print_exec_sql(yyvsp[0].str);
 }
    break;

  case 1385:
#line 6302 "fgl.yacc"
    {

lex_printcomment("/*  delete 1 */\n");

print_exec_sql_bound(yyvsp[0].str);
strcpy(yyval.str,"Delete where current...");
}
    break;

  case 1386:
#line 6309 "fgl.yacc"
    {

lex_printcomment("/*  delete 2 */\n");

print_exec_sql_bound(yyvsp[0].str);
strcpy(yyval.str,"Delete where ...");
}
    break;

  case 1387:
#line 6316 "fgl.yacc"
    {
strcpy(yyval.str,"Fetch");
lex_printcomment("/*  fetch */\n");
}
    break;

  case 1388:
#line 6320 "fgl.yacc"
    {

lex_printcomment("/*  insert */\n");

print_exec_sql_bound(yyvsp[0].str);


strcpy(yyval.str,"insert");

}
    break;

  case 1390:
#line 6331 "fgl.yacc"
    {
	print_do_select(yyvsp[0].str);
	strcpy(yyval.str,"select");
}
    break;

  case 1391:
#line 6335 "fgl.yacc"
    {

print_exec_sql_bound(yyvsp[0].str);
strcpy(yyval.str,"update");
}
    break;

  case 1392:
#line 6344 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s %s %s %s",yyvsp[-6].str,yyvsp[-5].str,yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1393:
#line 6347 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1394:
#line 6349 "fgl.yacc"
    {sprintf(yyval.str," %s ",yyvsp[0].str);}
    break;

  case 1395:
#line 6354 "fgl.yacc"
    {sprintf(yyval.str," %s ",yyvsp[0].str);}
    break;

  case 1398:
#line 6361 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1402:
#line 6368 "fgl.yacc"
    {sprintf(yyval.str," %s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1403:
#line 6371 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1404:
#line 6373 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1406:
#line 6379 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1408:
#line 6385 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1411:
#line 6396 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s %s %s",yyvsp[-5].str,yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1412:
#line 6399 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1413:
#line 6401 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1415:
#line 6407 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1416:
#line 6410 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1418:
#line 6417 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1419:
#line 6423 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s %s",yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1420:
#line 6428 "fgl.yacc"
    {sprintf(yyval.str," %s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1423:
#line 6438 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1425:
#line 6444 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1426:
#line 6450 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1427:
#line 6452 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1429:
#line 6458 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1433:
#line 6471 "fgl.yacc"
    {sprintf(yyval.str," %s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1434:
#line 6473 "fgl.yacc"
    {sprintf(yyval.str," %s",yyvsp[0].str);}
    break;

  case 1435:
#line 6484 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1436:
#line 6487 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1438:
#line 6491 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1439:
#line 6493 "fgl.yacc"
    {sprintf(yyval.str," %s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1440:
#line 6498 "fgl.yacc"
    {sprintf(yyval.str," %s ",yyvsp[0].str);}
    break;

  case 1441:
#line 6500 "fgl.yacc"
    {sprintf(yyval.str," %s ",yyvsp[0].str);}
    break;

  case 1443:
#line 6503 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1444:
#line 6509 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1445:
#line 6514 "fgl.yacc"
    {sprintf(yyval.str," %s",yyvsp[0].str);}
    break;

  case 1448:
#line 6524 "fgl.yacc"
    {sprintf(yyval.str," %s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1451:
#line 6539 "fgl.yacc"
    {sprintf(yyval.str," %s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1452:
#line 6545 "fgl.yacc"
    {sprintf(yyval.str," %s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1455:
#line 6555 "fgl.yacc"
    {sprintf(yyval.str,"%s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1456:
#line 6560 "fgl.yacc"
    {sprintf(yyval.str,"%s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1458:
#line 6566 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1459:
#line 6570 "fgl.yacc"
    {sprintf(yyval.str," %s ", yyvsp[0].str);}
    break;

  case 1460:
#line 6571 "fgl.yacc"
    {sprintf(yyval.str," %s %s ",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1461:
#line 6572 "fgl.yacc"
    {sprintf(yyval.str," %s (%s) ",yyvsp[-3].str,yyvsp[-1].str);}
    break;

  case 1463:
#line 6576 "fgl.yacc"
    {sprintf(yyval.str,"%s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1465:
#line 6581 "fgl.yacc"
    { sprintf(yyval.str," %s,%s ",yyvsp[-2].str,yyvsp[0].str);  }
    break;

  case 1466:
#line 6589 "fgl.yacc"
    {
sprintf(yyval.str,"%s %s %s %s",
yyvsp[-3].str,yyvsp[-2].str,
yyvsp[-1].str,yyvsp[0].str);
}
    break;

  case 1467:
#line 6596 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1468:
#line 6597 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1469:
#line 6600 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1470:
#line 6601 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1471:
#line 6604 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1472:
#line 6605 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1474:
#line 6612 "fgl.yacc"
    {sprintf(yyval.str,"%s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1476:
#line 6618 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1478:
#line 6624 "fgl.yacc"
    {sprintf(yyval.str," %s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1480:
#line 6630 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1481:
#line 6635 "fgl.yacc"
    {sprintf(yyval.str," %s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1482:
#line 6636 "fgl.yacc"
    {sprintf(yyval.str," %s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1483:
#line 6642 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1484:
#line 6644 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1485:
#line 6648 "fgl.yacc"
    {strcpy(yyval.str," ALL ");}
    break;

  case 1491:
#line 6667 "fgl.yacc"
    {sprintf(yyval.str," %s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1494:
#line 6681 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s %s",yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1495:
#line 6683 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1496:
#line 6685 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s %s",yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1497:
#line 6687 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1499:
#line 6694 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1502:
#line 6700 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1504:
#line 6707 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1505:
#line 6709 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1506:
#line 6711 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1507:
#line 6713 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1508:
#line 6715 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s %s %s",yyvsp[-5].str,yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1509:
#line 6717 "fgl.yacc"
    {sprintf(yyval.str," %s %s Like %s %s",yyvsp[-4].str,yyvsp[-3].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1511:
#line 6723 "fgl.yacc"
    {strcpy(yyval.str,"!=");}
    break;

  case 1517:
#line 6729 "fgl.yacc"
    {strcpy(yyval.str,"likE");}
    break;

  case 1518:
#line 6730 "fgl.yacc"
    {strcpy(yyval.str,"<=");}
    break;

  case 1519:
#line 6731 "fgl.yacc"
    {strcpy(yyval.str,">=");}
    break;

  case 1524:
#line 6741 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1527:
#line 6744 "fgl.yacc"
    {
		ansi_violation("Use DISTINCT not UNIQUE",0);
		strcpy(yyval.str,"DISTINCT ");
	}
    break;

  case 1532:
#line 6764 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1533:
#line 6769 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s %s",yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1534:
#line 6770 "fgl.yacc"
    {strcpy(yyval.str,"SERIAL");}
    break;

  case 1536:
#line 6773 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s %s",yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1540:
#line 6778 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1542:
#line 6781 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1544:
#line 6784 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s %s %s %s",yyvsp[-6].str,yyvsp[-5].str,yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1548:
#line 6789 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1549:
#line 6791 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s %s %s",yyvsp[-5].str,yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1550:
#line 6794 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1551:
#line 6795 "fgl.yacc"
    {
		sprintf(yyval.str,",%s",yyvsp[0].str);
}
    break;

  case 1552:
#line 6802 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1556:
#line 6807 "fgl.yacc"
    {sprintf(yyval.str," %s",yyvsp[0].str);}
    break;

  case 1560:
#line 6823 "fgl.yacc"
    { sprintf(yyval.str,"\\\"%s\\\"%s%s",strip_quotes(yyvsp[-2].str),yyvsp[-1].str,yyvsp[0].str); addmap("Use Table",yyval.str,curr_func,yylineno,infilename); }
    break;

  case 1561:
#line 6824 "fgl.yacc"
    {
		sprintf(yyval.str," %s",strip_quotes(yyvsp[0].str));
		addmap("Use Table",yyval.str,curr_func,yylineno,infilename);
	}
    break;

  case 1562:
#line 6828 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str); addmap("Use Table",yyvsp[0].str,curr_func,yylineno,infilename); }
    break;

  case 1563:
#line 6829 "fgl.yacc"
    { sprintf(yyval.str," %s%s%s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str); addmap("Use Table",yyval.str,curr_func,yylineno,infilename); }
    break;

  case 1565:
#line 6844 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1566:
#line 6845 "fgl.yacc"
    {sprintf(yyval.str,"[%s]",yyvsp[-1].str);}
    break;

  case 1567:
#line 6846 "fgl.yacc"
    {sprintf(yyval.str,"[%s,%s]",yyvsp[-3].str,yyvsp[-1].str);}
    break;

  case 1568:
#line 6850 "fgl.yacc"
    { 
addmap("Use Column",yyvsp[-1].str,curr_func,yylineno,infilename);
sprintf(yyval.str,"%s%s",yyvsp[-1].str,yyvsp[0].str);
}
    break;

  case 1569:
#line 6855 "fgl.yacc"
    {
sprintf(yyval.str,"%s.%s%s",yyvsp[-4].str,yyvsp[-1].str,yyvsp[0].str);
addmap("Use Column",yyval.str,curr_func,yylineno,infilename);
}
    break;

  case 1570:
#line 6860 "fgl.yacc"
    {
sprintf(yyval.str,"%s.%s",yyvsp[-3].str,yyvsp[0].str);
addmap("Use Column",yyval.str,curr_func,yylineno,infilename);
}
    break;

  case 1572:
#line 6873 "fgl.yacc"
    {
	strcpy(yyval.str,convstrsql(yyvsp[0].str));
	debug("Set $<str>$ to %s\n",yyval.str);
}
    break;

  case 1576:
#line 6881 "fgl.yacc"
    {sprintf(yyval.str," %s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1577:
#line 6883 "fgl.yacc"
    {sprintf(yyval.str," %s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1578:
#line 6885 "fgl.yacc"
    {sprintf(yyval.str," %s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1579:
#line 6887 "fgl.yacc"
    {sprintf(yyval.str," %s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1581:
#line 6892 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1582:
#line 6895 "fgl.yacc"
    {sprintf(yyval.str," %s %s ",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1583:
#line 6898 "fgl.yacc"
    {strcpy(yyval.str," YEAR TO SECOND ");}
    break;

  case 1584:
#line 6900 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1585:
#line 6903 "fgl.yacc"
    {strcpy(yyval.str,"0,19");}
    break;

  case 1586:
#line 6905 "fgl.yacc"
    {sprintf(yyval.str," %s ,%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1587:
#line 6908 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 1588:
#line 6908 "fgl.yacc"
    {strcpy(yyval.str,"5");}
    break;

  case 1589:
#line 6908 "fgl.yacc"
    {strcpy(yyval.str,"8");}
    break;

  case 1590:
#line 6908 "fgl.yacc"
    {strcpy(yyval.str,"11");}
    break;

  case 1591:
#line 6908 "fgl.yacc"
    {strcpy(yyval.str,"14");}
    break;

  case 1592:
#line 6908 "fgl.yacc"
    {strcpy(yyval.str,"17");}
    break;

  case 1593:
#line 6909 "fgl.yacc"
    {
strcpy(yyval.str,"23");
}
    break;

  case 1594:
#line 6912 "fgl.yacc"
    {
strcpy(yyval.str,"23");
}
    break;

  case 1595:
#line 6917 "fgl.yacc"
    {strcpy(yyval.str,"4");}
    break;

  case 1596:
#line 6917 "fgl.yacc"
    {strcpy(yyval.str,"7");}
    break;

  case 1597:
#line 6917 "fgl.yacc"
    {strcpy(yyval.str,"10");}
    break;

  case 1598:
#line 6917 "fgl.yacc"
    {strcpy(yyval.str,"13");}
    break;

  case 1599:
#line 6917 "fgl.yacc"
    {strcpy(yyval.str,"16");}
    break;

  case 1600:
#line 6917 "fgl.yacc"
    {strcpy(yyval.str,"19");}
    break;

  case 1601:
#line 6919 "fgl.yacc"
    {
strcpy(yyval.str,"25");
}
    break;

  case 1602:
#line 6922 "fgl.yacc"
    {
strcpy(yyval.str,"25");
}
    break;

  case 1617:
#line 6931 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1618:
#line 6932 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1619:
#line 6936 "fgl.yacc"
    {
	print_flush_cursor(yyvsp[0].str);
		addmap("Flush Cursor",yyvsp[0].str,curr_func,yylineno,infilename);
print_undo_use(yyvsp[-2].str);
		}
    break;

  case 1620:
#line 6945 "fgl.yacc"
    {insql=0;chk4var=0;}
    break;

  case 1621:
#line 6945 "fgl.yacc"
    {
print_declare(yyvsp[0].str,yyvsp[-2].str,yyvsp[-5].str,0,0);
addmap("Declare Cursor",yyvsp[-5].str,curr_func,yylineno,infilename);
print_undo_use(yyvsp[-7].str);
}
    break;

  case 1622:
#line 6950 "fgl.yacc"
    {insql=0;chk4var=0;}
    break;

  case 1623:
#line 6950 "fgl.yacc"
    {
print_declare(yyvsp[0].str,yyvsp[-2].str,yyvsp[-6].str,2,0); 
addmap("Declare Cursor",yyvsp[-6].str,curr_func,yylineno,infilename);
print_undo_use(yyvsp[-8].str);
}
    break;

  case 1624:
#line 6956 "fgl.yacc"
    {insql=0;chk4var=0;}
    break;

  case 1625:
#line 6957 "fgl.yacc"
    {
print_declare(yyvsp[0].str,yyvsp[-2].str,yyvsp[-4].str,0,1); 
addmap("Declare Cursor",yyvsp[-4].str,curr_func,yylineno,infilename);
print_undo_use(yyvsp[-6].str);
}
    break;

  case 1626:
#line 6962 "fgl.yacc"
    {insql=0;chk4var=0;}
    break;

  case 1627:
#line 6963 "fgl.yacc"
    {
print_declare(yyvsp[0].str,yyvsp[-2].str,yyvsp[-6].str,0,1); 
addmap("Declare Cursor",yyvsp[-6].str,curr_func,yylineno,infilename);
print_undo_use(yyvsp[-8].str);
}
    break;

  case 1628:
#line 6972 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 1629:
#line 6973 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 1630:
#line 6974 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 1634:
#line 6981 "fgl.yacc"
    {sprintf(yyval.str,"%s.%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1635:
#line 6982 "fgl.yacc"
    {sprintf(yyval.str,"\\\"%s\\\".%s.%s",strip_quotes(yyvsp[-4].str),yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1637:
#line 6988 "fgl.yacc"
    { 
		strcpy(yyval.str,print_curr_spec(1,yyvsp[0].str));
	}
    break;

  case 1638:
#line 6994 "fgl.yacc"
    {
		strcpy(yyval.str,print_curr_spec(2,yyvsp[0].str));
}
    break;

  case 1640:
#line 7003 "fgl.yacc"
    {
	sprintf(yyval.str,"%s",yyvsp[-1].str);
	if (atoi(yyvsp[0].str)) {
		printf("Warning SELECT ... FOR UPDATE when not declaring a cursor currently has no locking effect\n");
	}

	}
    break;

  case 1641:
#line 7016 "fgl.yacc"
    {debug("Got select list...\n");}
    break;

  case 1642:
#line 7018 "fgl.yacc"
    { /* start_bind('i',0,-1); */ start_bind('i',0); lex_printcomment("/* startbind */"); }
    break;

  case 1643:
#line 7020 "fgl.yacc"
    {
             char buff[1024];
             sprintf(buff,"%s %s %s %s %s %s", yyvsp[-7].str, yyvsp[-6].str, yyvsp[-5].str, yyvsp[-3].str, yyvsp[-1].str,yyvsp[0].str);
	     debug("call print_select_all with %s\n",buff);
	     strcpy(yyval.str,print_select_all(buff));

}
    break;

  case 1644:
#line 7031 "fgl.yacc"
    {
             char buff[1024];

             sprintf(buff,"%s %s %s %s %s", yyvsp[-4].str, yyvsp[-3].str, yyvsp[-2].str, yyvsp[-1].str, yyvsp[0].str);
             sprintf(yyval.str,"push_char(\"%s\");",buff);
}
    break;

  case 1647:
#line 7047 "fgl.yacc"
    {sprintf(yyval.str,"%s %s %s %s %s %s %s", yyvsp[-6].str, yyvsp[-5].str, yyvsp[-4].str, yyvsp[-3].str, yyvsp[-2].str, yyvsp[-1].str, yyvsp[0].str);}
    break;

  case 1648:
#line 7051 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1649:
#line 7052 "fgl.yacc"
    {
       lex_printcomment("/* UNION */");
       sprintf(yyval.str,"%s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);
       }
    break;

  case 1651:
#line 7057 "fgl.yacc"
    { sprintf(yyval.str,"%s %s %s ",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str); }
    break;

  case 1652:
#line 7058 "fgl.yacc"
    { sprintf(yyval.str,"%s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str); }
    break;

  case 1654:
#line 7065 "fgl.yacc"
    { start_bind('o',0);strcpy(yyval.str,""); }
    break;

  case 1655:
#line 7066 "fgl.yacc"
    { 
		
		strcpy(yyval.str,get_into_part(get_bind_cnt('o'))); 
	}
    break;

  case 1656:
#line 7076 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s",yyvsp[-4].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1657:
#line 7081 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s %s %s %s",yyvsp[-6].str,yyvsp[-5].str,yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1658:
#line 7084 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1659:
#line 7085 "fgl.yacc"
    {strcpy(yyval.str,"ALL");}
    break;

  case 1660:
#line 7086 "fgl.yacc"
    {strcpy(yyval.str,"DISTINCT");}
    break;

  case 1661:
#line 7087 "fgl.yacc"
    {strcpy(yyval.str,"DISTINCT");
		ansi_violation("Use DISTINCT not UNIQUE",0);
		strcpy(yyval.str,"DISTINCT ");

}
    break;

  case 1663:
#line 7096 "fgl.yacc"
    { sprintf(yyval.str," %s,%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1665:
#line 7101 "fgl.yacc"
    {sprintf(yyval.str," %s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1666:
#line 7102 "fgl.yacc"
    {sprintf(yyval.str," %s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1668:
#line 7112 "fgl.yacc"
    {
			if (strlen(current_upd_table)) push_gen(UPDVAL,yyvsp[0].str);
	}
    break;

  case 1670:
#line 7120 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1671:
#line 7122 "fgl.yacc"
    {sprintf(yyval.str," %s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1672:
#line 7124 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1673:
#line 7126 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1674:
#line 7128 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1679:
#line 7133 "fgl.yacc"
    {sprintf(yyval.str," %s ",yyvsp[0].str);}
    break;

  case 1680:
#line 7135 "fgl.yacc"
    {sprintf(yyval.str," %s",yyvsp[0].str);}
    break;

  case 1681:
#line 7137 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s %s",yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1682:
#line 7139 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s %s",yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1683:
#line 7141 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s %s",yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1684:
#line 7143 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s %s",yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1685:
#line 7145 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s %s",yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1686:
#line 7147 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1687:
#line 7149 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s %s %s",yyvsp[-5].str,yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1688:
#line 7150 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1689:
#line 7151 "fgl.yacc"
    {sprintf(yyval.str,"extend(%s)",yyvsp[-1].str);}
    break;

  case 1694:
#line 7161 "fgl.yacc"
    {

print_unload(yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);
print_undo_use(yyvsp[-4].str);
}
    break;

  case 1695:
#line 7169 "fgl.yacc"
    {
print_load(yyvsp[-4].str,yyvsp[-3].str,yyvsp[-1].str,yyvsp[0].str);
print_undo_use(yyvsp[-6].str);
}
    break;

  case 1696:
#line 7174 "fgl.yacc"
    {strcpy(yyval.str,"\"|\"");}
    break;

  case 1697:
#line 7174 "fgl.yacc"
    {
strcpy(yyval.str,yyvsp[0].str);
}
    break;

  case 1699:
#line 7178 "fgl.yacc"
    {
if ((scan_variable(yyvsp[0].str)&15)!=0) {yyerror("Variable must be of type char for a delimiter..");YYERROR;}
}
    break;

  case 1700:
#line 7183 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 1701:
#line 7183 "fgl.yacc"
    {
sprintf(yyval.str,"%s,0",yyvsp[-1].str);
}
    break;

  case 1703:
#line 7187 "fgl.yacc"
    {
    sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 1704:
#line 7191 "fgl.yacc"
    {
     sprintf(yyval.str,"\"%s\"",yyvsp[0].str);
}
    break;

  case 1707:
#line 7200 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1708:
#line 7200 "fgl.yacc"
    {
print_use_session(yyvsp[0].str);
strcpy(yyval.str,get_undo_use());
}
    break;

  case 1713:
#line 7219 "fgl.yacc"
    { sprintf(yyval.str,"%s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str); }
    break;

  case 1714:
#line 7220 "fgl.yacc"
    { sprintf(yyval.str,"%s %s %s %s",yyvsp[-5].str,yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str); }
    break;

  case 1717:
#line 7228 "fgl.yacc"
    {
		sprintf(yyval.str,"%s %s",yyvsp[-1].str,yyvsp[0].str);
	}
    break;

  case 1718:
#line 7234 "fgl.yacc"
    {
		sprintf(yyval.str,"%s %s %s",
					yyvsp[-2].str,
					yyvsp[-1].str,
					yyvsp[0].str
					);
		}
    break;

  case 1721:
#line 7253 "fgl.yacc"
    {strcpy(yyval.str,"UNITS YEAR");}
    break;

  case 1722:
#line 7254 "fgl.yacc"
    {strcpy(yyval.str,"UNITS MONTH"); }
    break;

  case 1723:
#line 7255 "fgl.yacc"
    {strcpy(yyval.str,"UNITS DAY);"); }
    break;

  case 1724:
#line 7256 "fgl.yacc"
    {strcpy(yyval.str,"UNITS HOUR);"); }
    break;

  case 1725:
#line 7257 "fgl.yacc"
    {strcpy(yyval.str,"UNITS MINUTE);"); }
    break;

  case 1726:
#line 7258 "fgl.yacc"
    {strcpy(yyval.str,"UNITS SECOND);"); }
    break;

  case 1727:
#line 7262 "fgl.yacc"
    {sprintf(yyval.str,"%s %s %s %s %s",yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1728:
#line 7263 "fgl.yacc"
    {sprintf(yyval.str,"%s %s %s %s %s",yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1729:
#line 7264 "fgl.yacc"
    {sprintf(yyval.str,"%s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1730:
#line 7348 "fgl.yacc"
    {
	if (scan_variable(yyvsp[0].str)!=-1)
	{
		print_push_variable(yyvsp[0].str);
		strcpy(yyval.str,"?");
	}
}
    break;

  case 1731:
#line 7359 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1735:
#line 7365 "fgl.yacc"
    {sprintf(yyval.str,"%s.%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1736:
#line 7366 "fgl.yacc"
    {sprintf(yyval.str,"\\\"%s\\\".%s.%s",strip_quotes(yyvsp[-4].str),yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1740:
#line 7376 "fgl.yacc"
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

  case 1741:
#line 7388 "fgl.yacc"
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

  case 1742:
#line 7486 "fgl.yacc"
    {set_whenever(WHEN_NOTFOUND|atoi(yyvsp[0].str),0);}
    break;

  case 1743:
#line 7488 "fgl.yacc"
    {set_whenever(WHEN_SQLERROR|atoi(yyvsp[0].str),0);}
    break;

  case 1744:
#line 7490 "fgl.yacc"
    {set_whenever(WHEN_ANYERROR|atoi(yyvsp[0].str),0);}
    break;

  case 1745:
#line 7491 "fgl.yacc"
    {
 		set_whento("");
		set_whenever(WHEN_ERROR+WHEN_CONTINUE,0);
}
    break;

  case 1746:
#line 7496 "fgl.yacc"
    {
debug("Whenever error...%d %d",WHEN_ERROR,atoi(yyvsp[0].str));
set_whenever(WHEN_ERROR+atoi(yyvsp[0].str),0);
}
    break;

  case 1747:
#line 7501 "fgl.yacc"
    {set_whenever(WHEN_SQLWARNING|atoi(yyvsp[0].str),0);}
    break;

  case 1748:
#line 7503 "fgl.yacc"
    {set_whenever(WHEN_WARNING|atoi(yyvsp[0].str),0);}
    break;

  case 1749:
#line 7505 "fgl.yacc"
    {set_whenever(WHEN_SUCCESS|atoi(yyvsp[0].str),0);}
    break;

  case 1750:
#line 7507 "fgl.yacc"
    {set_whenever(WHEN_SQLSUCCESS|atoi(yyvsp[0].str),0);}
    break;

  case 1751:
#line 7510 "fgl.yacc"
    {
 set_whento("");
			sprintf(yyval.str,"%d",WHEN_CONTINUE); }
    break;

  case 1752:
#line 7514 "fgl.yacc"
    {
set_whento(yyvsp[0].str);
sprintf(yyval.str,"%d",WHEN_GOTO);
 }
    break;

  case 1753:
#line 7519 "fgl.yacc"
    {
set_whento(yyvsp[0].str); 
sprintf(yyval.str,"%d",WHEN_GOTO);
}
    break;

  case 1754:
#line 7524 "fgl.yacc"
    { set_whento(""); 
sprintf(yyval.str,"%d",WHEN_STOP);
}
    break;

  case 1755:
#line 7528 "fgl.yacc"
    {
set_whento(yyvsp[0].str);
sprintf(yyval.str,"%d",WHEN_CALL);
}
    break;

  case 1757:
#line 7538 "fgl.yacc"
    {sprintf(yyval.str,"%s",yyvsp[0].str);}
    break;

  case 1759:
#line 7553 "fgl.yacc"
    {
print_while_1();
push_blockcommand("WHILE");
}
    break;

  case 1760:
#line 7556 "fgl.yacc"
    {
print_while_2();
}
    break;

  case 1761:
#line 7560 "fgl.yacc"
    {
print_while_3();
pop_blockcommand("WHILE");
}
    break;

  case 1764:
#line 7579 "fgl.yacc"
    { strcpy(yyval.str,"0"); }
    break;

  case 1765:
#line 7580 "fgl.yacc"
    { strcpy(yyval.str,"1"); }
    break;

  case 1766:
#line 7583 "fgl.yacc"
    { print_clr_window("\"screen\""); }
    break;

  case 1767:
#line 7584 "fgl.yacc"
    { print_clr_window(yyvsp[0].str); }
    break;

  case 1768:
#line 7585 "fgl.yacc"
    { print_clr_window(yyvsp[0].str); }
    break;

  case 1769:
#line 7586 "fgl.yacc"
    { print_clr_form(0,0,"0"); }
    break;

  case 1770:
#line 7587 "fgl.yacc"
    { print_clr_form(0,0,"1"); }
    break;

  case 1771:
#line 7588 "fgl.yacc"
    { print_clr_form(yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str); }
    break;

  case 1772:
#line 7589 "fgl.yacc"
    {
	print_clr_fields(yyvsp[-1].str,yyvsp[0].str);
}
    break;

  case 1773:
#line 7594 "fgl.yacc"
    {sprintf(yyval.str,"%s",yyvsp[0].str);}
    break;

  case 1774:
#line 7595 "fgl.yacc"
    {sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1775:
#line 7599 "fgl.yacc"
    {
	print_current_window("\"screen\"");
}
    break;

  case 1776:
#line 7603 "fgl.yacc"
    {
	print_current_window(yyvsp[0].str);
}
    break;

  case 1777:
#line 7607 "fgl.yacc"
    {
sprintf(yyval.str,"cr_window");
reset_attrib(&form_attrib);
}
    break;

  case 1778:
#line 7611 "fgl.yacc"
    {
sprintf(yyval.str,"cr_window_form");
reset_attrib(&form_attrib);
}
    break;

  case 1779:
#line 7616 "fgl.yacc"
    {
	print_show_window(yyvsp[0].str);
	addmap("Show Window",yyvsp[0].str,curr_func,yylineno,infilename); 
}
    break;

  case 1780:
#line 7620 "fgl.yacc"
    {
	print_show_menu(yyvsp[-3].str,yyvsp[-1].str);
	addmap("Call Menuhandler",yyvsp[-1].str,curr_func,yylineno,infilename); 
}
    break;

  case 1781:
#line 7625 "fgl.yacc"
    {

print_def_mn_file();

}
    break;

  case 1783:
#line 7633 "fgl.yacc"
    {addmap("Use Menu",yyvsp[0].str,curr_func,yylineno,infilename); }
    break;

  case 1785:
#line 7639 "fgl.yacc"
    {
	print_hide_window(yyvsp[0].str);
}
    break;

  case 1786:
#line 7645 "fgl.yacc"
    {
print_move_window(yyvsp[-4].str,0);
}
    break;

  case 1787:
#line 7649 "fgl.yacc"
    {
print_move_window(yyvsp[-4].str,1);
}
    break;

  case 1792:
#line 7667 "fgl.yacc"
    {
chk4var=0;lex_printcomment("/* [Comm:%s] */\n",yyval.str);
if (acl_getenv("INCLINES"))
lex_printc("{debug(\"Line %d %s:%s\");}",lastlineno,infilename,convstrsql(larr));
	prchkerr(lastlineno,infilename);
	lastlineno=yylineno;
}
    break;

  case 1793:
#line 7674 "fgl.yacc"
    {
lex_printcomment("/* [COMM:%s] */\n",yyvsp[0].str);chk4var=0;
if (acl_getenv("INCLINES"))
lex_printc("{debug(\"Line %d %s:%s\");}",lastlineno,infilename,convstrsql(larr));
if (aubit_strcasecmp(yyval.str,"whenever")!=0) prchkerr(lastlineno,infilename);
lastlineno=yylineno;
}
    break;

  case 1794:
#line 7683 "fgl.yacc"
    {print_cmd_start();}
    break;

  case 1795:
#line 7683 "fgl.yacc"
    {print_cmd_end();}
    break;


    }

/* Line 991 of yacc.c.  */
#line 15766 "y.tab.c"

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


#line 7776 "fgl.yacc"

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



