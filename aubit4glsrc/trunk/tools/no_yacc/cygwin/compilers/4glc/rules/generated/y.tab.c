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
#define YYLAST   8532

/* YYNTOKENS -- Number of terminals. */
#define YYNTOKENS  647
/* YYNNTS -- Number of nonterminals. */
#define YYNNTS  811
/* YYNRULES -- Number of rules. */
#define YYNRULES  1862
/* YYNRULES -- Number of states. */
#define YYNSTATES  3072

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
     480,   482,   483,   485,   487,   490,   491,   492,   498,   500,
     502,   504,   508,   509,   512,   517,   522,   527,   530,   531,
     536,   538,   540,   542,   545,   547,   549,   553,   554,   556,
     557,   565,   566,   579,   581,   583,   585,   587,   589,   595,
     599,   601,   603,   604,   609,   610,   616,   617,   625,   627,
     631,   633,   635,   636,   638,   639,   640,   645,   647,   649,
     651,   656,   661,   668,   670,   673,   675,   677,   679,   681,
     686,   693,   695,   700,   707,   709,   711,   713,   715,   717,
     719,   721,   724,   727,   729,   731,   736,   738,   740,   741,
     745,   749,   750,   753,   755,   757,   759,   761,   763,   765,
     768,   769,   772,   773,   777,   778,   782,   784,   785,   789,
     791,   793,   795,   797,   799,   801,   804,   806,   807,   809,
     810,   816,   818,   820,   822,   827,   832,   839,   841,   843,
     845,   847,   852,   859,   861,   866,   873,   875,   877,   879,
     881,   883,   886,   889,   891,   896,   897,   905,   906,   919,
     920,   925,   926,   932,   934,   938,   941,   943,   947,   949,
     950,   953,   956,   958,   961,   967,   972,   975,   980,   986,
     990,   991,   992,  1004,  1005,  1008,  1010,  1011,  1014,  1016,
    1019,  1020,  1024,  1025,  1029,  1030,  1034,  1039,  1045,  1047,
    1049,  1051,  1053,  1055,  1057,  1059,  1061,  1063,  1065,  1067,
    1069,  1071,  1073,  1075,  1077,  1079,  1081,  1084,  1086,  1088,
    1090,  1092,  1095,  1097,  1099,  1101,  1104,  1107,  1109,  1111,
    1113,  1115,  1117,  1119,  1121,  1123,  1125,  1127,  1129,  1132,
    1134,  1136,  1138,  1142,  1144,  1148,  1150,  1154,  1156,  1158,
    1160,  1163,  1165,  1167,  1171,  1176,  1181,  1184,  1187,  1189,
    1191,  1193,  1195,  1197,  1201,  1203,  1206,  1209,  1211,  1212,
    1216,  1219,  1222,  1224,  1228,  1233,  1238,  1244,  1250,  1252,
    1254,  1257,  1260,  1263,  1266,  1268,  1271,  1274,  1277,  1280,
    1283,  1286,  1289,  1292,  1295,  1298,  1301,  1304,  1307,  1310,
    1311,  1312,  1313,  1320,  1321,  1322,  1329,  1330,  1331,  1338,
    1339,  1340,  1347,  1348,  1349,  1356,  1357,  1358,  1365,  1371,
    1377,  1385,  1391,  1397,  1405,  1406,  1410,  1411,  1415,  1417,
    1422,  1427,  1432,  1437,  1442,  1447,  1449,  1451,  1453,  1455,
    1460,  1465,  1468,  1473,  1476,  1479,  1482,  1488,  1494,  1499,
    1500,  1501,  1513,  1514,  1517,  1518,  1519,  1520,  1529,  1530,
    1531,  1542,  1543,  1545,  1546,  1548,  1550,  1553,  1554,  1558,
    1559,  1563,  1564,  1566,  1568,  1571,  1572,  1576,  1577,  1581,
    1585,  1587,  1592,  1596,  1598,  1602,  1604,  1608,  1610,  1614,
    1616,  1619,  1620,  1624,  1625,  1629,  1630,  1635,  1636,  1641,
    1642,  1647,  1650,  1654,  1656,  1660,  1662,  1664,  1666,  1668,
    1670,  1672,  1676,  1678,  1680,  1685,  1692,  1697,  1701,  1708,
    1712,  1719,  1721,  1723,  1725,  1727,  1729,  1731,  1732,  1735,
    1739,  1743,  1745,  1750,  1752,  1754,  1755,  1756,  1758,  1763,
    1767,  1774,  1778,  1785,  1787,  1789,  1792,  1794,  1796,  1798,
    1800,  1802,  1804,  1806,  1808,  1810,  1812,  1814,  1816,  1818,
    1820,  1822,  1824,  1826,  1828,  1830,  1832,  1834,  1836,  1838,
    1840,  1842,  1844,  1846,  1848,  1850,  1852,  1854,  1856,  1858,
    1860,  1862,  1864,  1866,  1868,  1870,  1872,  1874,  1876,  1878,
    1881,  1884,  1886,  1890,  1892,  1895,  1898,  1901,  1906,  1909,
    1912,  1917,  1918,  1927,  1928,  1930,  1932,  1934,  1935,  1937,
    1940,  1941,  1943,  1946,  1947,  1949,  1952,  1953,  1955,  1959,
    1960,  1963,  1964,  1972,  1973,  1974,  1978,  1979,  1980,  1988,
    1994,  1997,  1998,  2004,  2009,  2011,  2015,  2019,  2023,  2024,
    2027,  2028,  2030,  2032,  2035,  2036,  2041,  2042,  2047,  2048,
    2052,  2053,  2057,  2058,  2062,  2063,  2067,  2068,  2072,  2073,
    2078,  2079,  2084,  2086,  2090,  2092,  2094,  2096,  2100,  2102,
    2104,  2106,  2110,  2112,  2116,  2119,  2124,  2126,  2128,  2130,
    2131,  2136,  2142,  2149,  2150,  2161,  2165,  2167,  2169,  2172,
    2175,  2176,  2179,  2180,  2184,  2186,  2187,  2191,  2194,  2195,
    2199,  2201,  2205,  2207,  2211,  2212,  2215,  2217,  2219,  2221,
    2223,  2225,  2227,  2229,  2231,  2233,  2235,  2237,  2239,  2241,
    2243,  2245,  2247,  2249,  2250,  2251,  2259,  2261,  2263,  2266,
    2269,  2272,  2276,  2281,  2282,  2286,  2287,  2289,  2291,  2294,
    2296,  2298,  2300,  2302,  2303,  2305,  2307,  2310,  2313,  2315,
    2317,  2319,  2321,  2323,  2325,  2327,  2329,  2331,  2333,  2335,
    2337,  2339,  2340,  2342,  2344,  2346,  2348,  2350,  2351,  2352,
    2353,  2354,  2368,  2370,  2371,  2372,  2379,  2382,  2384,  2387,
    2390,  2392,  2394,  2397,  2399,  2401,  2403,  2404,  2408,  2411,
    2413,  2414,  2415,  2416,  2431,  2432,  2438,  2440,  2441,  2445,
    2446,  2454,  2455,  2461,  2463,  2466,  2467,  2469,  2471,  2473,
    2474,  2476,  2478,  2481,  2484,  2487,  2489,  2491,  2493,  2495,
    2499,  2501,  2503,  2504,  2505,  2513,  2515,  2518,  2519,  2523,
    2524,  2529,  2532,  2533,  2536,  2538,  2540,  2542,  2544,  2546,
    2548,  2550,  2551,  2555,  2556,  2558,  2560,  2562,  2564,  2567,
    2571,  2574,  2580,  2582,  2584,  2586,  2591,  2596,  2598,  2600,
    2602,  2604,  2607,  2611,  2618,  2620,  2624,  2626,  2628,  2630,
    2635,  2643,  2645,  2647,  2649,  2651,  2654,  2655,  2657,  2659,
    2663,  2665,  2669,  2671,  2675,  2677,  2681,  2683,  2685,  2687,
    2689,  2693,  2695,  2699,  2701,  2705,  2707,  2709,  2711,  2715,
    2718,  2719,  2721,  2723,  2728,  2730,  2734,  2736,  2740,  2748,
    2749,  2757,  2758,  2765,  2769,  2771,  2775,  2777,  2780,  2786,
    2787,  2795,  2796,  2799,  2800,  2802,  2808,  2811,  2817,  2818,
    2824,  2831,  2836,  2837,  2839,  2841,  2846,  2847,  2850,  2851,
    2857,  2862,  2865,  2867,  2871,  2874,  2877,  2880,  2883,  2886,
    2889,  2891,  2894,  2897,  2900,  2903,  2906,  2909,  2912,  2915,
    2918,  2920,  2922,  2924,  2926,  2928,  2930,  2936,  2938,  2940,
    2943,  2948,  2950,  2951,  2962,  2968,  2969,  2971,  2972,  2975,
    2977,  2980,  2981,  2985,  2987,  2988,  2993,  2994,  2997,  2999,
    3003,  3005,  3007,  3011,  3016,  3021,  3024,  3026,  3028,  3030,
    3031,  3033,  3041,  3044,  3047,  3050,  3053,  3055,  3058,  3059,
    3063,  3064,  3068,  3069,  3073,  3074,  3078,  3079,  3083,  3084,
    3089,  3090,  3095,  3097,  3099,  3101,  3103,  3105,  3107,  3108,
    3113,  3114,  3116,  3117,  3122,  3124,  3127,  3130,  3133,  3134,
    3136,  3138,  3141,  3144,  3145,  3148,  3152,  3156,  3162,  3163,
    3166,  3171,  3173,  3175,  3177,  3179,  3181,  3182,  3184,  3186,
    3190,  3193,  3199,  3202,  3208,  3214,  3220,  3226,  3232,  3238,
    3239,  3242,  3244,  3247,  3250,  3253,  3256,  3259,  3262,  3264,
    3267,  3270,  3273,  3276,  3278,  3281,  3284,  3287,  3290,  3292,
    3294,  3296,  3297,  3300,  3303,  3306,  3309,  3312,  3315,  3318,
    3321,  3324,  3326,  3328,  3330,  3332,  3334,  3336,  3338,  3340,
    3343,  3346,  3349,  3352,  3355,  3357,  3359,  3361,  3362,  3366,
    3369,  3370,  3371,  3372,  3373,  3374,  3375,  3391,  3392,  3395,
    3398,  3399,  3401,  3402,  3403,  3404,  3405,  3406,  3407,  3423,
    3426,  3427,  3428,  3429,  3440,  3441,  3443,  3447,  3451,  3454,
    3459,  3463,  3467,  3471,  3473,  3475,  3477,  3479,  3481,  3485,
    3486,  3487,  3495,  3496,  3497,  3506,  3509,  3510,  3512,  3514,
    3518,  3521,  3524,  3526,  3528,  3532,  3534,  3536,  3539,  3541,
    3543,  3547,  3549,  3553,  3555,  3557,  3559,  3561,  3563,  3565,
    3567,  3570,  3575,  3577,  3581,  3583,  3587,  3590,  3595,  3597,
    3601,  3603,  3606,  3611,  3613,  3617,  3619,  3621,  3623,  3626,
    3629,  3634,  3637,  3642,  3644,  3648,  3650,  3652,  3654,  3657,
    3659,  3661,  3663,  3665,  3667,  3670,  3677,  3684,  3685,  3687,
    3688,  3690,  3693,  3694,  3695,  3703,  3704,  3707,  3710,  3718,
    3720,  3726,  3730,  3732,  3736,  3738,  3742,  3744,  3748,  3750,
    3754,  3756,  3758,  3760,  3762,  3763,  3769,  3770,  3776,  3778,
    3779,  3783,  3785,  3789,  3791,  3795,  3797,  3799,  3800,  3801,
    3807,  3810,  3812,  3813,  3814,  3818,  3819,  3820,  3824,  3826,
    3828,  3830,  3832,  3834,  3836,  3839,  3842,  3847,  3851,  3855,
    3857,  3861,  3864,  3866,  3868,  3869,  3871,  3873,  3875,  3877,
    3878,  3880,  3884,  3885,  3889,  3891,  3893,  3895,  3897,  3899,
    3901,  3903,  3905,  3907,  3909,  3911,  3913,  3921,  3922,  3924,
    3926,  3928,  3930,  3934,  3936,  3938,  3940,  3943,  3944,  3948,
    3950,  3954,  3956,  3960,  3962,  3964,  3971,  3972,  3976,  3978,
    3982,  3983,  3985,  3990,  3996,  3999,  4001,  4003,  4008,  4010,
    4014,  4019,  4024,  4026,  4030,  4032,  4034,  4036,  4039,  4041,
    4046,  4047,  4049,  4050,  4053,  4055,  4057,  4059,  4064,  4068,
    4070,  4072,  4074,  4077,  4079,  4081,  4084,  4087,  4089,  4093,
    4096,  4099,  4101,  4105,  4107,  4110,  4115,  4117,  4120,  4122,
    4126,  4131,  4132,  4134,  4135,  4137,  4138,  4140,  4142,  4146,
    4148,  4152,  4154,  4157,  4159,  4163,  4166,  4169,  4174,  4178,
    4179,  4181,  4183,  4185,  4187,  4189,  4192,  4194,  4196,  4202,
    4206,  4212,  4216,  4218,  4222,  4224,  4226,  4227,  4229,  4233,
    4237,  4241,  4245,  4252,  4258,  4260,  4262,  4264,  4266,  4268,
    4270,  4272,  4274,  4276,  4278,  4280,  4282,  4284,  4286,  4287,
    4289,  4291,  4293,  4295,  4297,  4299,  4301,  4306,  4312,  4314,
    4320,  4326,  4328,  4330,  4332,  4337,  4339,  4344,  4346,  4354,
    4356,  4358,  4360,  4365,  4372,  4373,  4376,  4381,  4383,  4385,
    4387,  4389,  4391,  4393,  4395,  4399,  4401,  4403,  4407,  4409,
    4410,  4414,  4420,  4423,  4429,  4434,  4436,  4438,  4440,  4442,
    4444,  4447,  4450,  4453,  4456,  4458,  4461,  4464,  4465,  4469,
    4470,  4474,  4476,  4478,  4480,  4482,  4484,  4486,  4488,  4493,
    4495,  4497,  4499,  4501,  4503,  4505,  4507,  4512,  4514,  4516,
    4518,  4520,  4522,  4524,  4526,  4528,  4530,  4532,  4534,  4536,
    4538,  4540,  4542,  4544,  4548,  4549,  4558,  4559,  4569,  4570,
    4578,  4579,  4589,  4590,  4592,  4595,  4597,  4601,  4603,  4607,
    4613,  4615,  4617,  4619,  4621,  4624,  4625,  4626,  4635,  4641,
    4643,  4645,  4653,  4654,  4658,  4660,  4664,  4669,  4671,  4672,
    4675,  4681,  4689,  4690,  4692,  4694,  4696,  4698,  4702,  4704,
    4707,  4710,  4712,  4714,  4716,  4720,  4723,  4727,  4731,  4735,
    4737,  4739,  4741,  4743,  4745,  4747,  4753,  4759,  4765,  4771,
    4777,  4782,  4789,  4793,  4798,  4800,  4804,  4805,  4807,  4813,
    4821,  4822,  4825,  4827,  4829,  4830,  4834,  4836,  4840,  4842,
    4844,  4846,  4847,  4851,  4853,  4855,  4857,  4859,  4864,  4871,
    4873,  4875,  4878,  4882,  4884,  4886,  4888,  4890,  4892,  4894,
    4896,  4898,  4904,  4910,  4915,  4917,  4920,  4922,  4924,  4926,
    4930,  4936,  4938,  4940,  4942,  4944,  4948,  4951,  4954,  4957,
    4959,  4962,  4965,  4968,  4971,  4974,  4976,  4980,  4983,  4985,
    4988,  4990,  4993,  4995,  4996,  4997,  5004,  5005,  5008,  5009,
    5011,  5013,  5016,  5019,  5021,  5023,  5028,  5032,  5034,  5038,
    5040,  5043,  5049,  5052,  5055,  5061,  5062,  5065,  5067,  5069,
    5072,  5079,  5086,  5088,  5089,  5091,  5094,  5096,  5099,  5100,
    5103,  5105,  5107,  5109,  5111,  5113,  5115,  5117,  5119,  5121,
    5123,  5125,  5127,  5129,  5131,  5133,  5135,  5137,  5139,  5141,
    5143,  5145,  5147,  5149,  5151,  5153,  5155,  5157,  5159,  5161,
    5163,  5165,  5167,  5169,  5171,  5173,  5175,  5177,  5179,  5181,
    5183,  5185,  5187,  5189,  5191,  5193,  5195,  5197,  5199,  5201,
    5203,  5205,  5207,  5209,  5211,  5213,  5215,  5217,  5219,  5221,
    5223,  5225,  5227,  5229,  5231,  5233,  5235,  5237,  5239,  5241,
    5243,  5245,  5247,  5249,  5251,  5253,  5255,  5257,  5259,  5261,
    5263,  5265,  5267
};

/* YYRHS -- A `-1'-separated list of the rules' RHS. */
static const short yyrhs[] =
{
    1002,     0,    -1,   179,    -1,   176,    -1,   103,   652,   405,
     574,   653,    -1,   117,    -1,  1068,    -1,    25,    -1,   654,
      -1,   653,     5,   654,    -1,   910,    -1,   409,   655,   370,
      -1,   655,   656,   655,    -1,    25,    -1,   657,    25,    -1,
    1068,    -1,    17,    -1,    18,    -1,    20,    -1,    19,    -1,
      21,    -1,    17,    -1,    18,    -1,    -1,   659,    -1,    -1,
     253,   409,   660,   661,   370,    -1,   547,   409,    25,     5,
      25,   370,    -1,   662,    -1,   661,     5,   662,    -1,   469,
      -1,   509,    -1,   515,    -1,   485,    -1,   388,    -1,   584,
      -1,   506,    -1,   459,    -1,   395,    -1,   470,    -1,   324,
      -1,   510,    -1,   434,    -1,   311,    -1,   572,    -1,    77,
      -1,    -1,   664,    -1,    -1,   253,   409,   665,   666,   370,
      -1,   667,    -1,   666,     5,   667,    -1,   662,    -1,   410,
      -1,   582,    24,    -1,   182,   897,    -1,   308,   897,    -1,
     263,   897,    -1,   316,   897,    -1,   272,   897,    -1,   238,
     897,    -1,   512,   669,    -1,   846,   323,  1068,    -1,    -1,
     268,   409,  1442,   370,   323,   670,  1086,    -1,    83,   409,
     910,   370,    -1,   385,   409,   902,   370,   323,  1068,    -1,
    1203,    -1,   171,   409,   902,   370,   323,  1068,    -1,    -1,
      -1,  1068,   568,   910,   409,   671,   685,   370,   672,   683,
      -1,    -1,    -1,    -1,   910,   409,   673,   685,   674,   370,
     675,   683,    -1,    -1,    -1,   453,  1411,   602,  1411,   409,
     676,   685,   677,   370,   683,    -1,    -1,    -1,    44,   409,
     678,   685,   679,   370,   683,    -1,    -1,    -1,    -1,   344,
     688,   568,   689,   437,   652,   405,   409,   680,   685,   681,
     370,   682,   684,    -1,    -1,   323,  1086,    -1,    -1,   323,
    1086,    -1,   141,    -1,    -1,   686,    -1,   687,    -1,   686,
       5,   687,    -1,   815,    -1,    24,    -1,   910,    -1,   910,
      -1,   910,   599,   910,    -1,    -1,   513,   822,   691,   694,
     698,   695,    -1,    -1,   513,   692,   693,   696,   695,    -1,
     700,    -1,   693,   700,    -1,   702,    -1,   694,   702,    -1,
     339,    -1,    -1,    -1,   318,   697,  1452,    -1,    -1,    -1,
     318,   699,  1452,    -1,    -1,   557,   822,   701,  1452,    -1,
      -1,   557,   822,   703,  1452,    -1,   257,   907,    -1,   181,
     905,    -1,    62,   905,    -1,   148,    -1,   164,  1417,    -1,
     473,   904,    -1,    29,   706,    30,    -1,   707,    -1,   709,
      -1,   708,    -1,   707,   708,    -1,    28,    -1,   710,    -1,
     709,   710,    -1,    27,    -1,   372,    -1,    -1,    -1,   299,
     713,   715,   714,   716,    -1,   363,  1068,   604,   717,   953,
     980,   658,    -1,  1068,   604,   717,   953,   525,  1442,   980,
     658,    -1,    -1,   719,   170,    -1,   718,    -1,   717,     5,
     718,    -1,   910,    -1,   910,   599,   910,    -1,   910,   599,
      20,    -1,   720,    -1,   719,   720,    -1,    -1,   249,   726,
     721,  1452,    -1,    -1,   252,   727,   722,  1452,    -1,    -1,
     981,   723,  1452,    -1,    -1,   146,   724,  1452,    -1,    -1,
     142,   725,  1452,    -1,   916,    -1,   726,     5,   916,    -1,
     916,    -1,   727,     5,   916,    -1,    71,    -1,    72,    -1,
      73,    -1,    74,    -1,    75,    -1,    76,    -1,   134,    -1,
     258,    -1,    -1,   731,    -1,   732,    -1,   731,   732,    -1,
      -1,    -1,   416,   733,   735,   734,  1172,    -1,   782,    -1,
    1432,    -1,   738,    -1,   735,     5,   738,    -1,    -1,   737,
     910,    -1,   332,   736,   781,    24,    -1,   332,   736,   781,
     918,    -1,   332,   736,   781,    25,    -1,   742,   758,    -1,
      -1,   736,   332,   739,   740,    -1,    25,    -1,    24,    -1,
     918,    -1,    18,    25,    -1,   736,    -1,   741,    -1,   742,
       5,   741,    -1,    -1,   514,    -1,    -1,   466,   437,   750,
     405,   745,   603,   758,    -1,    -1,   297,   743,   747,    25,
     748,   281,   437,   749,   405,   746,   603,   758,    -1,   409,
      -1,   436,    -1,   370,    -1,   404,    -1,    25,    -1,   751,
       5,   751,     5,   751,    -1,   751,     5,   751,    -1,   751,
      -1,    25,    -1,    -1,   442,   753,   735,   262,    -1,    -1,
     239,   754,   736,   599,    20,    -1,    -1,   313,   755,   736,
     237,   409,   756,   370,    -1,   757,    -1,   756,     5,   757,
      -1,   736,    -1,   760,    -1,    -1,    37,    -1,    -1,    -1,
     761,   763,   762,   759,    -1,   744,    -1,   752,    -1,   514,
      -1,   514,   409,    25,   370,    -1,   402,   409,    25,   370,
      -1,   402,   409,    25,     5,    25,   370,    -1,   386,    -1,
     596,   736,    -1,   358,    -1,   488,    -1,    68,    -1,   376,
      -1,   376,   409,    25,   370,    -1,   376,   409,    25,     5,
      25,   370,    -1,   491,    -1,   491,   409,    25,   370,    -1,
     491,   409,    25,     5,    25,   370,    -1,   481,    -1,   278,
      -1,   516,    -1,   511,    -1,    59,    -1,    60,    -1,   553,
      -1,   336,   767,    -1,   348,   768,    -1,   764,    -1,    31,
      -1,   535,   765,   599,   766,    -1,   736,    -1,   736,    -1,
      -1,   769,   605,   772,    -1,   777,   605,   780,    -1,    -1,
     770,   771,    -1,   560,    -1,   492,    -1,   569,    -1,   531,
      -1,   432,    -1,   449,    -1,   345,   774,    -1,    -1,   773,
     771,    -1,    -1,   409,   776,   370,    -1,    -1,   409,    25,
     370,    -1,    25,    -1,    -1,   778,   779,   775,    -1,   560,
      -1,   492,    -1,   569,    -1,   531,    -1,   432,    -1,   449,
      -1,   345,   774,    -1,   779,    -1,    -1,    13,    -1,    -1,
     215,   910,   783,   596,   784,    -1,   786,    -1,   789,    -1,
     514,    -1,   514,   409,    25,   370,    -1,   402,   409,    25,
     370,    -1,   402,   409,    25,     5,    25,   370,    -1,   386,
      -1,   358,    -1,   488,    -1,   376,    -1,   376,   409,    25,
     370,    -1,   376,   409,    25,     5,    25,   370,    -1,   491,
      -1,   491,   409,    25,   370,    -1,   491,   409,    25,     5,
      25,   370,    -1,   481,    -1,   278,    -1,   516,    -1,   511,
      -1,   553,    -1,   336,   767,    -1,   348,   768,    -1,   785,
      -1,   535,   765,   599,   766,    -1,    -1,   466,   437,   750,
     405,   787,   603,   784,    -1,    -1,   297,   743,   747,    25,
     748,   281,   437,   749,   405,   788,   603,   784,    -1,    -1,
     442,   790,   792,   262,    -1,    -1,   239,   791,   910,   599,
      20,    -1,   793,    -1,   792,     5,   793,    -1,   794,   784,
      -1,   795,    -1,   794,     5,   795,    -1,   910,    -1,    -1,
     597,   901,    -1,    49,   910,    -1,    47,    -1,   605,  1442,
      -1,   605,   488,   910,   638,  1442,    -1,   605,   488,   910,
     368,    -1,    51,   910,    -1,   135,   840,  1086,   804,    -1,
     379,   840,   820,   796,   804,    -1,   188,   907,   804,    -1,
      -1,    -1,   167,   801,  1093,   605,   910,   599,    20,   803,
     658,   802,   805,    -1,    -1,   447,   902,    -1,   658,    -1,
      -1,   806,   217,    -1,   807,    -1,   806,   807,    -1,    -1,
     330,   808,  1452,    -1,    -1,   326,   809,  1452,    -1,    -1,
     981,   810,  1452,    -1,   477,   840,   821,   658,    -1,   477,
     840,   821,   658,    45,    -1,   265,    -1,   264,    -1,   191,
      -1,   343,    -1,   153,    -1,   190,    -1,   307,    -1,   306,
      -1,   222,    -1,   150,    -1,   149,    -1,   123,    -1,   183,
      -1,   106,    -1,   122,    -1,   166,    -1,   132,    -1,   192,
      -1,   192,   822,    -1,   825,    -1,   824,    -1,   829,    -1,
     857,    -1,   815,   816,    -1,   858,    -1,   860,    -1,   826,
      -1,    18,   815,    -1,    17,   815,    -1,   831,    -1,   839,
      -1,   833,    -1,   454,    -1,   728,    -1,   834,    -1,   835,
      -1,   836,    -1,   837,    -1,   838,    -1,   840,    -1,   840,
     819,    -1,   822,    -1,   462,    -1,   818,    -1,   819,     5,
     818,    -1,   822,    -1,   820,     5,   822,    -1,   822,    -1,
     821,     5,   822,    -1,   815,    -1,    17,    -1,    18,    -1,
     581,   815,    -1,   463,    -1,   406,    -1,   409,   815,   370,
      -1,   421,   409,  1392,   370,    -1,   273,   409,  1392,   370,
      -1,   823,   918,    -1,   823,    25,    -1,    24,    -1,   918,
      -1,    25,    -1,   828,    -1,  1068,    -1,  1068,   399,  1068,
      -1,   827,    -1,   412,   815,    -1,   371,   815,    -1,  1175,
      -1,    -1,   486,   830,  1175,    -1,     7,   815,    -1,     6,
     815,    -1,   815,    -1,   832,     5,   815,    -1,   602,   409,
    1392,   370,    -1,   407,   409,  1392,   370,    -1,   602,   409,
     840,   832,   370,    -1,   407,   409,   840,   832,   370,    -1,
     365,    -1,   228,    -1,     9,   815,    -1,   231,   815,    -1,
     535,   815,    -1,   350,   815,    -1,   369,    -1,     8,   815,
      -1,    17,   815,    -1,    18,   815,    -1,    20,   815,    -1,
      19,   815,    -1,    21,   815,    -1,    10,   815,    -1,    13,
     815,    -1,   435,   815,    -1,    11,   815,    -1,    12,   815,
      -1,    16,   815,    -1,    15,   815,    -1,    14,   815,    -1,
      -1,    -1,    -1,   910,   409,   842,   685,   843,   370,    -1,
      -1,    -1,    44,   409,   844,   685,   845,   370,    -1,    -1,
      -1,   516,   409,   847,   815,   848,   370,    -1,    -1,    -1,
     492,   409,   849,   815,   850,   370,    -1,    -1,    -1,   569,
     409,   851,   815,   852,   370,    -1,    -1,    -1,   560,   409,
     853,   815,   854,   370,    -1,   348,   409,    24,   370,   856,
      -1,   348,   409,    25,   370,   856,    -1,   348,   409,    25,
     568,    25,   370,   856,    -1,   336,   409,    24,   370,   855,
      -1,   336,   409,    25,   370,   855,    -1,   336,   409,    25,
     568,    25,   370,   855,    -1,    -1,  1372,   605,  1373,    -1,
      -1,  1372,   605,  1373,    -1,   846,    -1,   268,   409,  1442,
     370,    -1,    78,   409,   902,   370,    -1,    50,   409,   902,
     370,    -1,   385,   409,   902,   370,    -1,   171,   409,   902,
     370,    -1,    38,   409,   902,   370,    -1,   859,    -1,   841,
      -1,  1368,    -1,   516,    -1,   401,   409,   815,   370,    -1,
     301,   409,   815,   370,    -1,   467,   815,    -1,   422,   409,
     861,   370,    -1,   815,    87,    -1,   815,    88,    -1,   815,
      89,    -1,   374,     5,  1372,   605,  1373,    -1,  1068,     5,
    1372,   605,  1373,    -1,   374,  1372,   605,  1373,    -1,    -1,
      -1,   574,  1068,    13,   822,   605,   822,   865,   863,  1452,
     864,   220,    -1,    -1,   550,   822,    -1,    -1,    -1,    -1,
     382,   867,   904,   868,  1272,   869,  1452,   219,    -1,    -1,
      -1,   617,   910,   871,   730,   872,  1012,   874,   873,   879,
     618,    -1,    -1,   884,    -1,    -1,   875,    -1,   876,    -1,
     875,   876,    -1,    -1,   619,   877,  1452,    -1,    -1,   620,
     878,  1452,    -1,    -1,   880,    -1,   881,    -1,   880,   881,
      -1,    -1,   621,   882,  1452,    -1,    -1,   622,   883,  1452,
      -1,   885,   889,   303,    -1,    70,    -1,    70,   886,   525,
     887,    -1,    70,   363,   888,    -1,  1068,    -1,   886,     5,
    1068,    -1,   910,    -1,   887,     5,   910,    -1,  1068,    -1,
     888,     5,  1068,    -1,   890,    -1,   889,   890,    -1,    -1,
     623,   891,  1452,    -1,    -1,   624,   892,  1452,    -1,    -1,
     643,   887,   893,  1452,    -1,    -1,   460,   887,   894,  1452,
      -1,    -1,   604,   887,   895,  1452,    -1,   524,   903,    -1,
     533,    18,    25,    -1,   533,    -1,   480,    17,    25,    -1,
     480,    -1,    25,    -1,  1068,    -1,    24,    -1,   917,    -1,
     822,    -1,   899,     5,   899,    -1,   900,    -1,   910,    -1,
     646,   409,   910,   370,    -1,   910,   599,   646,   409,   910,
     370,    -1,   910,   437,   655,   405,    -1,   910,   599,    20,
      -1,   910,   437,   655,   405,   599,    20,    -1,   910,   599,
     910,    -1,   910,   437,   655,   405,   599,   910,    -1,   911,
      -1,   911,    -1,   911,    -1,   911,    -1,   911,    -1,   911,
      -1,    -1,   529,    25,    -1,   914,  1451,   915,    -1,   914,
     912,   915,    -1,  1451,    -1,   328,   409,   913,   370,    -1,
    1071,    -1,    24,    -1,    -1,    -1,   910,    -1,   910,   437,
     655,   405,    -1,   910,   599,    20,    -1,   910,   437,   655,
     405,   599,    20,    -1,   910,   599,   910,    -1,   910,   437,
     655,   405,   599,   910,    -1,  1068,    -1,    23,    -1,   599,
      25,    -1,   352,    -1,   471,    -1,   472,    -1,   369,    -1,
     473,    -1,   332,    -1,   299,    -1,   475,    -1,   438,    -1,
     515,    -1,   427,    -1,   570,    -1,   375,    -1,   468,    -1,
     461,    -1,   538,    -1,   378,    -1,   337,    -1,   476,    -1,
     300,    -1,   517,    -1,   259,    -1,   572,    -1,   634,    -1,
     518,    -1,   301,    -1,   520,    -1,   383,    -1,   421,    -1,
     560,    -1,   492,    -1,   569,    -1,   454,    -1,   357,    -1,
     372,    -1,   417,    -1,   359,    -1,   420,    -1,   401,    -1,
     366,    -1,   324,    -1,   537,    -1,   516,    -1,   526,  1434,
      -1,   631,   922,    -1,   923,    -1,   922,     5,   923,    -1,
     910,    -1,   642,   922,    -1,   633,   922,    -1,   634,  1442,
      -1,   632,   907,   638,  1442,    -1,   636,   922,    -1,   637,
    1442,    -1,   635,   907,   638,  1442,    -1,    -1,   640,   928,
     820,   933,   935,   937,   929,   931,    -1,    -1,   930,    -1,
     628,    -1,   629,    -1,    -1,   932,    -1,   323,  1068,    -1,
      -1,   934,    -1,   368,   820,    -1,    -1,   936,    -1,   639,
      25,    -1,    -1,   938,    -1,   630,    25,   939,    -1,    -1,
     378,    25,    -1,    -1,   601,   822,   554,   941,  1452,   942,
     419,    -1,    -1,    -1,   521,   943,  1452,    -1,    -1,    -1,
      41,   944,   822,   554,   945,  1452,   942,    -1,    85,   910,
     409,    25,   370,    -1,    54,   910,    -1,    -1,   269,  1098,
     949,   605,   462,    -1,   269,  1098,   535,   950,    -1,   951,
      -1,   950,     5,   951,    -1,   765,   599,  1365,    -1,   765,
     599,    20,    -1,    -1,   954,   303,    -1,    -1,   129,    -1,
     955,    -1,   954,   955,    -1,    -1,   249,   969,   956,  1452,
      -1,    -1,   252,   970,   957,  1452,    -1,    -1,   330,   958,
    1452,    -1,    -1,   326,   959,  1452,    -1,    -1,   981,   960,
    1452,    -1,    -1,   284,   961,  1452,    -1,    -1,   254,   962,
    1452,    -1,    -1,   643,   967,   963,  1452,    -1,    -1,   460,
     965,   964,  1452,    -1,   966,    -1,   965,     5,   966,    -1,
     428,    -1,   417,    -1,   968,    -1,   967,     5,   968,    -1,
     428,    -1,   417,    -1,   902,    -1,   969,     5,   902,    -1,
     902,    -1,   970,     5,   902,    -1,   293,   973,    -1,   294,
     910,   638,   973,    -1,   540,    -1,   353,    -1,   902,    -1,
      -1,   644,   976,   975,   952,    -1,   363,  1086,   953,   909,
     658,    -1,  1086,   953,   525,  1442,   909,   658,    -1,    -1,
     466,  1093,   953,   525,   910,   599,    20,   909,   977,   658,
      -1,   448,  1442,   979,    -1,   606,    -1,   518,    -1,    55,
      25,    -1,    61,    25,    -1,    -1,   529,    25,    -1,    -1,
     408,   982,   988,    -1,   274,    -1,    -1,   575,   984,   988,
      -1,   282,   990,    -1,    -1,   575,   987,   988,    -1,   990,
      -1,   409,   989,   370,    -1,   990,    -1,   989,     5,   990,
      -1,    -1,   991,   992,    -1,   573,    -1,   291,    -1,   309,
      -1,   283,    -1,   464,    -1,   420,    -1,   606,    -1,   518,
      -1,   444,    -1,   417,    -1,   519,    -1,   534,    -1,   499,
      -1,   289,    -1,   290,    -1,    24,    -1,   489,    -1,    -1,
      -1,   577,   995,  1091,   996,    13,   840,   997,    -1,   462,
      -1,   821,    -1,   198,  1068,    -1,   187,  1068,    -1,   201,
    1068,    -1,   429,  1068,   312,    -1,   429,  1068,   364,   898,
      -1,    -1,  1004,  1003,  1007,    -1,    -1,  1005,    -1,  1006,
      -1,  1005,  1006,    -1,   947,    -1,  1011,    -1,  1027,    -1,
    1013,    -1,    -1,  1008,    -1,  1010,    -1,  1008,  1010,    -1,
      46,   910,    -1,  1015,    -1,  1021,    -1,  1033,    -1,  1185,
      -1,  1195,    -1,  1054,    -1,  1432,    -1,   870,    -1,   705,
      -1,   946,    -1,   711,    -1,   705,    -1,  1432,    -1,    -1,
     705,    -1,  1432,    -1,   731,    -1,   346,    -1,    39,    -1,
      -1,    -1,    -1,    -1,  1014,  1016,   910,   409,  1017,  1084,
     370,  1018,   730,  1019,  1012,  1452,  1020,    -1,   189,    -1,
      -1,    -1,   536,  1022,   730,  1023,  1452,   340,    -1,   444,
     817,    -1,   840,    -1,   840,   820,    -1,   335,  1376,    -1,
    1028,    -1,  1029,    -1,  1028,  1029,    -1,  1030,    -1,  1011,
      -1,  1026,    -1,    -1,   384,  1031,  1032,    -1,   730,   221,
      -1,   898,    -1,    -1,    -1,    -1,    92,   910,    91,   910,
     409,  1034,  1084,   370,  1035,   730,  1036,  1012,  1452,  1020,
      -1,    -1,   537,  1038,  1053,  1044,  1039,    -1,   341,    -1,
      -1,   213,  1041,  1452,    -1,    -1,    22,  1045,  1046,  1047,
     909,  1042,  1452,    -1,    -1,    22,  1045,   909,  1043,  1452,
      -1,  1040,    -1,  1044,  1040,    -1,    -1,   983,    -1,    24,
      -1,  1068,    -1,    -1,  1068,    -1,    24,    -1,   230,  1051,
      -1,   242,  1052,    -1,   225,  1052,    -1,   564,    -1,    24,
      -1,  1068,    -1,  1051,    -1,  1052,     5,  1051,    -1,  1068,
      -1,    24,    -1,    -1,    -1,   625,   910,  1055,   730,  1056,
    1057,   626,    -1,  1058,    -1,  1057,  1058,    -1,    -1,   627,
    1059,  1452,    -1,    -1,   604,   910,  1060,  1452,    -1,  1064,
    1062,    -1,    -1,   659,  1066,    -1,  1067,    -1,  1063,    -1,
     934,    -1,   936,    -1,   938,    -1,   930,    -1,   932,    -1,
      -1,   349,  1065,   821,    -1,    -1,    45,    -1,    45,    -1,
    1069,    -1,  1071,    -1,   591,  1071,    -1,  1071,   914,   599,
      -1,  1070,  1075,    -1,  1070,   910,   437,  1078,   405,    -1,
    1076,    -1,   910,    -1,  1072,    -1,   910,   436,  1074,   404,
      -1,   910,   436,  1074,   404,    -1,  1068,    -1,    24,    -1,
      20,    -1,   910,    -1,   910,  1077,    -1,   437,  1078,   405,
      -1,   437,  1078,   405,   437,  1078,   405,    -1,  1079,    -1,
    1078,     5,  1079,    -1,   655,    -1,  1081,    -1,  1083,    -1,
    1081,   914,   599,  1082,    -1,  1081,   914,   599,   910,   437,
    1078,   405,    -1,   910,    -1,  1073,    -1,    20,    -1,   910,
      -1,   910,  1077,    -1,    -1,  1085,    -1,  1087,    -1,  1085,
       5,  1087,    -1,  1088,    -1,  1086,     5,  1088,    -1,   910,
      -1,   910,   599,   910,    -1,  1068,    -1,  1068,   399,  1068,
      -1,    24,    -1,   918,    -1,    25,    -1,  1090,    -1,  1089,
       5,  1090,    -1,  1068,    -1,  1068,   399,  1068,    -1,  1092,
      -1,  1091,     5,  1092,    -1,  1080,    -1,  1068,    -1,  1095,
      -1,  1094,     5,  1095,    -1,  1068,  1096,    -1,    -1,   566,
      -1,   517,    -1,   910,   437,  1078,   405,    -1,  1099,    -1,
    1098,     5,  1099,    -1,  1068,    -1,  1068,   399,  1068,    -1,
     233,   906,   597,   900,   558,  1444,   663,    -1,    -1,   597,
     409,   822,     5,   822,   370,  1102,    -1,    -1,   547,   409,
     822,     5,   822,   370,    -1,   234,   910,  1101,    -1,   910,
      -1,   317,   908,  1106,    -1,  1107,    -1,   525,   822,    -1,
    1108,  1109,  1114,     8,  1104,    -1,    -1,   597,  1110,   409,
     822,     5,   822,   370,    -1,    -1,   535,   911,    -1,    -1,
     329,    -1,   196,  1417,   245,  1427,  1113,    -1,   542,   903,
      -1,   542,   903,     8,   840,   820,    -1,    -1,   596,   555,
    1411,   352,  1411,    -1,   596,   555,  1411,     5,   352,  1411,
      -1,   596,  1411,     5,  1411,    -1,    -1,   628,    -1,   629,
      -1,    69,  1427,  1116,  1117,    -1,    -1,   596,  1427,    -1,
      -1,   596,   555,  1411,     8,  1411,    -1,   555,  1411,     8,
    1411,    -1,   390,  1119,    -1,  1120,    -1,  1119,     5,  1120,
      -1,   182,   897,    -1,   263,   897,    -1,   308,   897,    -1,
     316,   897,    -1,   272,   897,    -1,   238,   897,    -1,   985,
      -1,   417,   986,    -1,   428,   986,    -1,   540,   986,    -1,
     353,   986,    -1,   529,   986,    -1,   527,   898,    -1,   528,
     898,    -1,   379,   659,    -1,   644,   659,    -1,   270,    -1,
     174,    -1,   130,    -1,   107,    -1,   125,    -1,   116,    -1,
    1416,   392,  1124,   525,  1122,    -1,  1068,    -1,    24,    -1,
     381,  1124,    -1,   381,  1124,     8,  1086,    -1,   911,    -1,
      -1,   440,  1133,   658,   574,  1128,  1068,   909,   658,  1126,
    1129,    -1,   440,  1133,   658,   323,  1068,    -1,    -1,   514,
      -1,    -1,  1130,   261,    -1,  1131,    -1,  1130,  1131,    -1,
      -1,   981,  1132,  1452,    -1,   821,    -1,    -1,   583,   903,
    1135,  1136,    -1,    -1,   525,  1137,    -1,  1138,    -1,  1137,
       5,  1138,    -1,  1404,    -1,   462,    -1,   199,  1141,    67,
      -1,   199,  1141,   605,  1140,    -1,   199,  1141,    66,  1140,
      -1,   199,  1141,    -1,    24,    -1,   917,    -1,   910,    -1,
      -1,   458,    -1,   124,  1141,  1142,   409,   840,  1025,   370,
      -1,   172,  1141,    -1,  1176,  1184,    -1,   425,    40,    -1,
     425,  1147,    -1,  1148,    -1,  1147,  1148,    -1,    -1,   112,
    1149,  1452,    -1,    -1,   178,  1150,  1452,    -1,    -1,   207,
    1151,  1452,    -1,    -1,   195,  1152,  1452,    -1,    -1,   232,
    1153,  1452,    -1,    -1,   180,  1068,  1154,  1452,    -1,    -1,
     203,  1068,  1155,  1452,    -1,  1166,    -1,  1168,    -1,  1167,
      -1,  1157,    -1,  1193,    -1,  1160,    -1,    -1,   539,   822,
    1158,   461,    -1,    -1,   461,    -1,    -1,   548,   822,  1161,
    1159,    -1,   137,    -1,   608,  1180,    -1,   140,  1180,    -1,
     139,  1180,    -1,    -1,  1163,    -1,  1164,    -1,  1163,  1164,
      -1,  1173,  1165,    -1,    -1,   597,  1180,    -1,   498,  1162,
    1172,    -1,   497,  1411,  1172,    -1,   496,  1171,  1170,  1169,
    1172,    -1,    -1,   131,   815,    -1,   131,   815,     5,   815,
      -1,   592,    -1,   593,    -1,   594,    -1,   595,    -1,  1068,
      -1,    -1,   500,    -1,  1174,    -1,  1173,     5,  1174,    -1,
     822,  1207,    -1,   588,   409,   815,   370,  1192,    -1,    43,
    1192,    -1,   475,   409,    20,   370,  1192,    -1,   391,   409,
      20,   370,  1192,    -1,   366,   409,   815,   370,  1192,    -1,
     567,   409,   815,   370,  1192,    -1,   580,   409,   815,   370,
    1192,    -1,   579,   409,   815,   370,  1192,    -1,    -1,   439,
    1177,    -1,  1178,    -1,  1177,  1178,    -1,   206,    25,    -1,
     197,    25,    -1,   280,    25,    -1,   163,    25,    -1,   235,
      25,    -1,   155,    -1,   322,    24,    -1,   322,  1068,    -1,
     156,    24,    -1,   138,    24,    -1,  1183,    -1,  1179,  1183,
      -1,  1181,    87,    -1,  1181,    89,    -1,  1181,    88,    -1,
    1181,    -1,   918,    -1,    25,    -1,    -1,   439,  1179,    -1,
     206,  1180,    -1,   197,  1180,    -1,   280,  1180,    -1,   163,
    1180,    -1,   235,  1180,    -1,   236,  1180,    -1,   607,    24,
      -1,   608,  1180,    -1,   612,    -1,   609,    -1,   610,    -1,
     611,    -1,   616,    -1,   613,    -1,   614,    -1,   615,    -1,
      56,  1180,    -1,    57,  1180,    -1,    58,  1180,    -1,   322,
      24,    -1,   156,    24,    -1,   378,    -1,    52,    -1,    53,
      -1,    -1,   493,   598,  1094,    -1,   113,  1094,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   443,  1186,   910,   409,  1187,
    1084,   370,  1188,   730,  1189,  1145,  1190,  1146,  1191,   218,
      -1,    -1,   504,   815,    -1,   495,  1194,    -1,    -1,  1122,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    84,  1196,   910,
     409,  1197,  1084,   370,  1198,   730,  1199,  1202,  1200,  1146,
    1201,   218,    -1,  1182,  1184,    -1,    -1,    -1,    -1,   133,
     409,    24,     5,  1204,   685,  1205,   370,  1206,   683,    -1,
      -1,   362,    -1,   362,   197,    25,    -1,   362,   197,  1068,
      -1,   586,   822,    -1,   586,   822,   323,  1068,    -1,   586,
     822,   141,    -1,   586,   822,   556,    -1,   586,   822,   523,
      -1,  1210,    -1,   152,    -1,   302,    -1,   260,    -1,  1212,
      -1,    82,  1218,   370,    -1,    -1,    -1,   185,  1213,  1362,
     409,  1214,  1220,   370,    -1,    -1,    -1,   110,  1215,  1362,
     409,  1216,  1220,   370,  1217,    -1,    34,   911,    -1,    -1,
     247,    -1,  1219,    -1,  1218,     5,  1219,    -1,   910,   566,
      -1,   910,   517,    -1,   910,    -1,  1221,    -1,  1220,     5,
    1221,    -1,  1312,    -1,  1310,    -1,    99,   910,    -1,   158,
      -1,  1224,    -1,    33,   910,  1225,    -1,  1226,    -1,  1225,
       5,  1226,    -1,  1227,    -1,  1230,    -1,  1233,    -1,  1238,
      -1,  1239,    -1,  1237,    -1,  1236,    -1,   563,  1228,    -1,
     563,   409,  1229,   370,    -1,  1221,    -1,  1221,   643,   910,
      -1,  1228,    -1,  1229,     5,  1228,    -1,   520,  1232,    -1,
     520,   409,  1231,   370,    -1,  1232,    -1,  1231,     5,  1232,
      -1,   910,    -1,   433,  1235,    -1,   433,   409,  1234,   370,
      -1,  1235,    -1,  1234,     5,  1235,    -1,  1221,    -1,    64,
      -1,    65,    -1,    63,    25,    -1,    35,  1315,    -1,    35,
     409,  1240,   370,    -1,    36,  1241,    -1,    36,   409,  1240,
     370,    -1,  1315,    -1,  1240,     5,  1315,    -1,   910,    -1,
     244,    -1,   210,    -1,   143,  1244,    -1,   120,    -1,   108,
      -1,    98,    -1,    96,    -1,   100,    -1,   157,  1417,    -1,
     209,  1243,   438,  1411,   605,  1411,    -1,   277,   903,   438,
    1411,   605,  1411,    -1,    -1,  1417,    -1,    -1,   822,    -1,
     501,   822,    -1,    -1,    -1,   457,  1362,  1247,   562,  1250,
    1248,  1249,    -1,    -1,   128,   904,    -1,   504,  1334,    -1,
     409,  1254,   370,    13,   409,  1255,   370,    -1,  1251,    -1,
      20,    13,   409,  1255,   370,    -1,    20,    13,  1255,    -1,
    1253,    -1,  1251,     5,  1253,    -1,  1365,    -1,  1252,    13,
    1256,    -1,  1252,    -1,  1254,     5,  1252,    -1,  1256,    -1,
    1255,     5,  1256,    -1,  1399,    -1,   462,    -1,  1404,    -1,
     208,    -1,    -1,   227,  1259,  1362,  1262,  1260,    -1,    -1,
     458,  1261,   409,  1264,   370,    -1,  1398,    -1,    -1,   409,
    1263,   370,    -1,  1365,    -1,  1263,     5,  1365,    -1,  1265,
      -1,  1264,     5,  1265,    -1,  1404,    -1,   462,    -1,    -1,
      -1,   479,  1267,  1269,  1268,  1270,    -1,  1274,   904,    -1,
     904,    -1,    -1,    -1,   532,  1271,  1089,    -1,    -1,    -1,
     532,  1273,  1089,    -1,   480,    -1,   533,    -1,   540,    -1,
     353,    -1,   320,    -1,   374,    -1,   356,   822,    -1,   329,
     822,    -1,   216,  1362,   128,   904,    -1,   216,  1362,  1331,
      -1,   493,   598,  1278,    -1,  1279,    -1,  1278,     5,  1279,
      -1,  1280,  1281,    -1,    25,    -1,  1365,    -1,    -1,   566,
      -1,   517,    -1,   255,    -1,   288,    -1,    -1,   305,    -1,
     335,  1427,  1284,    -1,    -1,  1416,  1287,  1288,    -1,  1316,
      -1,  1320,    -1,  1283,    -1,  1418,    -1,  1282,    -1,  1275,
      -1,  1276,    -1,  1266,    -1,  1258,    -1,  1257,    -1,  1388,
      -1,  1246,    -1,   484,  1291,   604,  1362,   605,  1296,  1290,
      -1,    -1,   119,    -1,   147,    -1,  1292,    -1,  1293,    -1,
    1292,     5,  1293,    -1,   450,    -1,   428,    -1,   417,    -1,
     457,  1294,    -1,    -1,   409,  1295,   370,    -1,  1365,    -1,
    1295,     5,  1365,    -1,  1297,    -1,  1296,     5,  1297,    -1,
     441,    -1,  1363,    -1,   214,  1362,  1299,   596,  1398,  1301,
      -1,    -1,   409,  1300,   370,    -1,  1365,    -1,  1300,     5,
    1365,    -1,    -1,   118,    -1,   471,   409,  1334,   370,    -1,
     224,   409,  1305,   370,  1304,    -1,   275,  1306,    -1,  1307,
      -1,  1362,    -1,  1362,   409,  1307,   370,    -1,  1365,    -1,
    1307,     5,  1365,    -1,   455,   409,  1309,   370,    -1,   237,
     409,  1309,   370,    -1,  1365,    -1,  1309,     5,  1365,    -1,
    1308,    -1,  1303,    -1,  1302,    -1,   378,  1367,    -1,   186,
      -1,   910,  1354,  1313,  1314,    -1,    -1,  1311,    -1,    -1,
    1315,  1314,    -1,   351,    -1,   136,    -1,  1304,    -1,   471,
     409,  1334,   370,    -1,    97,  1317,  1319,    -1,  1318,    -1,
    1363,    -1,  1320,    -1,  1319,  1320,    -1,  1298,    -1,  1289,
      -1,   426,  1334,    -1,   347,  1323,    -1,  1403,    -1,  1323,
       5,  1403,    -1,   504,  1334,    -1,   525,  1326,    -1,  1327,
      -1,  1326,     5,  1327,    -1,  1328,    -1,   494,  1328,    -1,
     494,   409,  1329,   370,    -1,  1362,    -1,  1362,  1366,    -1,
    1327,    -1,  1329,     5,  1327,    -1,  1325,  1331,  1332,  1333,
      -1,    -1,  1324,    -1,    -1,  1322,    -1,    -1,  1321,    -1,
    1335,    -1,  1334,     6,  1335,    -1,  1336,    -1,  1335,     7,
    1336,    -1,  1337,    -1,   581,  1337,    -1,  1352,    -1,   409,
    1334,   370,    -1,   421,  1399,    -1,   273,  1399,    -1,  1404,
    1351,  1340,  1399,    -1,  1399,  1351,  1404,    -1,    -1,  1341,
      -1,  1342,    -1,   564,    -1,   549,    -1,   565,    -1,   420,
    1345,    -1,  1407,    -1,  1407,    -1,  1404,   602,   409,  1347,
     370,    -1,  1404,   602,  1399,    -1,  1404,   407,   409,  1347,
     370,    -1,  1404,   407,  1399,    -1,  1348,    -1,  1347,     5,
    1348,    -1,  1431,    -1,  1367,    -1,    -1,   581,    -1,  1404,
    1349,   365,    -1,  1404,  1349,   228,    -1,  1404,  1351,  1404,
      -1,  1404,  1351,  1399,    -1,  1404,  1349,   367,  1404,     7,
    1404,    -1,  1404,  1349,   535,  1344,  1343,    -1,    13,    -1,
      16,    -1,    11,    -1,    12,    -1,   231,    -1,   350,    -1,
       9,    -1,   535,    -1,    15,    -1,    14,    -1,  1350,    -1,
    1346,    -1,  1339,    -1,  1338,    -1,    -1,   564,    -1,   338,
      -1,   455,    -1,  1355,    -1,  1356,    -1,  1358,    -1,   514,
      -1,   514,   409,  1359,   370,    -1,   389,   409,  1360,  1357,
     370,    -1,   451,    -1,   376,   409,  1360,  1357,   370,    -1,
     491,   409,  1360,  1357,   370,    -1,   516,    -1,   386,    -1,
     358,    -1,   336,  1374,   605,  1375,    -1,   336,    -1,   348,
    1374,   605,  1375,    -1,   348,    -1,   348,  1374,   409,    25,
     370,   605,  1375,    -1,   553,    -1,   511,    -1,   402,    -1,
     402,   409,    25,   370,    -1,   402,   409,    25,     5,    25,
     370,    -1,    -1,     5,  1361,    -1,   481,   409,  1360,   370,
      -1,   544,    -1,   278,    -1,   481,    -1,    42,    -1,    25,
      -1,    25,    -1,    25,    -1,    24,   599,   910,    -1,    24,
      -1,   910,    -1,   910,   568,   910,    -1,   910,    -1,    -1,
     437,    25,   405,    -1,   437,    25,     5,    25,   405,    -1,
     910,  1364,    -1,  1362,   914,   599,   910,  1364,    -1,  1362,
     914,   599,    20,    -1,   910,    -1,    24,    -1,   389,    -1,
     918,    -1,    25,    -1,    17,   918,    -1,    17,    25,    -1,
      18,   918,    -1,    18,    25,    -1,  1369,    -1,   374,  1371,
      -1,   374,  1370,    -1,    -1,  1374,   605,  1375,    -1,    -1,
    1372,   605,  1373,    -1,   560,    -1,   492,    -1,   569,    -1,
     531,    -1,   432,    -1,   449,    -1,   345,    -1,   345,   409,
      25,   370,    -1,   560,    -1,   492,    -1,   569,    -1,   531,
      -1,   432,    -1,   449,    -1,   345,    -1,   345,   409,    25,
     370,    -1,   560,    -1,   492,    -1,   569,    -1,   531,    -1,
     432,    -1,   449,    -1,   345,    -1,   560,    -1,   492,    -1,
     569,    -1,   531,    -1,   432,    -1,   449,    -1,   345,    -1,
     910,    -1,    24,    -1,  1416,   482,   904,    -1,    -1,  1416,
     377,   904,   415,   574,  1386,  1379,  1383,    -1,    -1,  1416,
     377,   904,   415,    79,   574,  1387,  1380,  1383,    -1,    -1,
    1416,   377,   904,   114,  1387,  1381,  1383,    -1,    -1,  1416,
     377,   904,   115,    79,   574,  1387,  1382,  1383,    -1,    -1,
     267,    -1,   266,  1384,    -1,  1385,    -1,  1384,     5,  1385,
      -1,   910,    -1,   910,   599,   910,    -1,    24,   599,   910,
     599,   910,    -1,  1387,    -1,  1258,    -1,  1124,    -1,  1389,
      -1,  1389,  1383,    -1,    -1,    -1,   450,  1400,  1401,  1390,
    1397,  1391,  1330,  1395,    -1,   450,  1400,  1401,  1330,  1395,
      -1,  1394,    -1,  1411,    -1,   450,   914,  1400,  1401,  1397,
    1330,  1395,    -1,    -1,   503,  1353,  1393,    -1,  1277,    -1,
     310,  1396,  1217,    -1,  1277,   310,  1396,  1217,    -1,   910,
      -1,    -1,   532,  1089,    -1,   450,   914,  1400,  1401,  1330,
      -1,   409,   450,   914,  1400,  1401,  1330,   370,    -1,    -1,
     564,    -1,   338,    -1,   455,    -1,  1402,    -1,  1401,     5,
    1402,    -1,  1404,    -1,  1404,  1451,    -1,  1404,   919,    -1,
    1404,    -1,  1405,    -1,  1431,    -1,  1404,    19,  1404,    -1,
    1404,  1425,    -1,  1404,    20,  1404,    -1,  1404,    17,  1404,
      -1,  1404,    18,  1404,    -1,  1367,    -1,   463,    -1,   406,
      -1,   555,    -1,    20,    -1,    43,    -1,   567,   409,  1353,
    1404,   370,    -1,   579,   409,  1353,  1404,   370,    -1,   580,
     409,  1353,  1404,   370,    -1,   588,   409,  1353,  1404,   370,
      -1,   475,   409,  1353,  1404,   370,    -1,   910,   409,  1406,
     370,    -1,   516,   914,   409,   914,  1406,   370,    -1,   409,
    1404,   370,    -1,   422,   409,  1426,   370,    -1,  1404,    -1,
    1406,     5,  1404,    -1,    -1,  1367,    -1,  1416,   325,  1415,
    1410,  1393,    -1,  1416,   314,  1415,  1410,   227,  1362,  1412,
      -1,    -1,   300,  1411,    -1,    24,    -1,  1068,    -1,    -1,
     409,  1413,   370,    -1,  1414,    -1,  1413,     5,  1414,    -1,
     910,    -1,    24,    -1,  1068,    -1,    -1,   246,  1417,   574,
      -1,   911,    -1,  1423,    -1,  1422,    -1,  1419,    -1,   295,
    1420,   605,  1420,    -1,   276,  1420,   599,  1421,   605,  1421,
      -1,   910,    -1,   910,    -1,   200,   765,    -1,   271,   765,
    1424,    -1,   250,    -1,   154,    -1,    71,    -1,    72,    -1,
      73,    -1,    74,    -1,    75,    -1,    76,    -1,   374,     5,
    1374,   605,  1375,    -1,  1365,     5,  1374,   605,  1375,    -1,
     374,  1374,   605,  1375,    -1,  1428,    -1,   591,  1429,    -1,
    1429,    -1,  1097,    -1,   910,    -1,  1429,   599,  1430,    -1,
      24,   599,  1429,   599,  1430,    -1,    20,    -1,  1097,    -1,
     910,    -1,  1428,    -1,  1428,   399,  1428,    -1,   105,  1433,
      -1,   109,  1433,    -1,   104,  1433,    -1,   144,    -1,   145,
    1433,    -1,   102,  1433,    -1,   127,  1433,    -1,   126,  1433,
      -1,   101,  1433,    -1,   334,    -1,   600,   605,  1434,    -1,
     526,  1434,    -1,   551,    -1,   512,  1435,    -1,   910,    -1,
     568,   910,    -1,   910,    -1,    -1,    -1,   505,  1437,   822,
    1438,  1452,   304,    -1,    -1,   638,  1442,    -1,    -1,   641,
      -1,   160,    -1,   256,   905,    -1,    48,   905,    -1,   286,
      -1,   285,    -1,   287,   907,  1439,  1440,    -1,   472,  1442,
    1440,    -1,   902,    -1,  1442,     5,   902,    -1,    81,    -1,
     111,   905,    -1,   822,   545,     5,   822,   371,    -1,   488,
     822,    -1,   243,   905,    -1,    80,  1447,     8,  1448,  1446,
      -1,    -1,   525,   822,    -1,   910,    -1,   910,    -1,   226,
     905,    -1,   229,   905,   605,   822,     5,   822,    -1,   229,
     905,   598,   822,     5,   822,    -1,    26,    -1,    -1,  1454,
      -1,  1455,  1172,    -1,  1453,    -1,  1454,  1453,    -1,    -1,
    1456,  1457,    -1,   648,    -1,   649,    -1,   650,    -1,   651,
      -1,   668,    -1,   690,    -1,   704,    -1,   705,    -1,   711,
      -1,   712,    -1,   729,    -1,   797,    -1,   798,    -1,   799,
      -1,   800,    -1,   811,    -1,   812,    -1,   813,    -1,   814,
      -1,   862,    -1,   866,    -1,   896,    -1,   920,    -1,   921,
      -1,   924,    -1,   925,    -1,   926,    -1,   927,    -1,   940,
      -1,   948,    -1,   971,    -1,   972,    -1,   974,    -1,   978,
      -1,   993,    -1,   994,    -1,   998,    -1,   999,    -1,  1000,
      -1,  1001,    -1,  1009,    -1,  1024,    -1,  1037,    -1,  1048,
      -1,  1049,    -1,  1050,    -1,  1061,    -1,  1100,    -1,  1103,
      -1,  1105,    -1,  1111,    -1,  1112,    -1,  1115,    -1,  1118,
      -1,  1121,    -1,  1123,    -1,  1125,    -1,  1127,    -1,  1134,
      -1,  1139,    -1,  1143,    -1,  1144,    -1,  1156,    -1,  1208,
      -1,  1209,    -1,  1211,    -1,  1222,    -1,  1223,    -1,  1242,
      -1,  1245,    -1,  1285,    -1,  1286,    -1,  1377,    -1,  1378,
      -1,  1408,    -1,  1409,    -1,  1432,    -1,  1436,    -1,  1441,
      -1,  1443,    -1,  1445,    -1,  1449,    -1,  1450,    -1
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
    1564,  1572,  1573,  1590,  1593,  1596,  1599,  1602,  1605,  1618,
    1622,  1637,  1638,  1642,  1642,  1646,  1646,  1646,  1647,  1648,
    1653,  1653,  1656,  1656,  1665,  1666,  1669,  1673,  1674,  1674,
    1691,  1691,  1691,  1691,  1695,  1702,  1703,  1706,  1706,  1709,
    1709,  1718,  1715,  1731,  1731,  1733,  1733,  1735,  1737,  1739,
    1741,  1744,  1748,  1748,  1749,  1749,  1753,  1753,  1765,  1765,
    1770,  1774,  1776,  1777,  1780,  1780,  1780,  1784,  1785,  1786,
    1787,  1794,  1795,  1796,  1797,  1800,  1801,  1802,  1803,  1807,
    1812,  1817,  1821,  1824,  1828,  1829,  1830,  1831,  1832,  1833,
    1834,  1835,  1838,  1839,  1840,  1872,  1876,  1878,  1880,  1880,
    1887,  1891,  1891,  1895,  1896,  1897,  1898,  1899,  1900,  1901,
    1907,  1907,  1910,  1912,  1918,  1920,  1926,  1934,  1934,  1937,
    1938,  1939,  1940,  1941,  1942,  1943,  1949,  1952,  1952,  1965,
    1965,  1972,  1973,  1974,  1976,  1977,  1979,  1981,  1982,  1983,
    1984,  1989,  1995,  2001,  2002,  2004,  2006,  2007,  2008,  2009,
    2010,  2011,  2014,  2015,  2022,  2030,  2030,  2038,  2035,  2050,
    2050,  2052,  2052,  2060,  2060,  2063,  2066,  2067,  2072,  2084,
    2088,  2091,  2094,  2095,  2096,  2097,  2098,  2103,  2110,  2116,
    2121,  2125,  2121,  2136,  2138,  2143,  2148,  2148,  2152,  2152,
    2155,  2155,  2161,  2161,  2167,  2167,  2183,  2186,  2200,  2202,
    2204,  2206,  2208,  2210,  2212,  2218,  2220,  2224,  2226,  2228,
    2230,  2232,  2234,  2236,  2242,  2257,  2260,  2273,  2274,  2275,
    2276,  2277,  2281,  2282,  2283,  2287,  2292,  2299,  2300,  2301,
    2302,  2303,  2304,  2305,  2306,  2307,  2308,  2313,  2313,  2318,
    2318,  2321,  2327,  2335,  2341,  2351,  2352,  2360,  2367,  2371,
    2381,  2385,  2390,  2395,  2397,  2407,  2420,  2428,  2441,  2446,
    2452,  2457,  2462,  2463,  2469,  2540,  2546,  2551,  2559,  2559,
    2575,  2579,  2586,  2589,  2597,  2608,  2618,  2624,  2633,  2638,
    2646,  2650,  2654,  2658,  2665,  2673,  2681,  2686,  2690,  2695,
    2699,  2703,  2710,  2713,  2716,  2720,  2724,  2728,  2732,  2740,
    2750,  2755,  2748,  2770,  2775,  2770,  2792,  2792,  2792,  2795,
    2795,  2795,  2798,  2798,  2798,  2801,  2801,  2801,  2804,  2809,
    2814,  2819,  2824,  2829,  2838,  2838,  2842,  2842,  2848,  2849,
    2855,  2856,  2861,  2864,  2868,  2872,  2873,  2876,  2881,  2887,
    2891,  2895,  2898,  2900,  2903,  2906,  2912,  2913,  2914,  2925,
    2929,  2924,  2937,  2940,  2954,  2958,  2963,  2953,  2983,  2989,
    2983,  3003,  3003,  3005,  3006,  3010,  3010,  3014,  3014,  3019,
    3019,  3026,  3027,  3031,  3031,  3035,  3035,  3040,  3040,  3047,
    3051,  3052,  3053,  3058,  3058,  3061,  3061,  3065,  3065,  3069,
    3069,  3073,  3073,  3078,  3078,  3083,  3083,  3088,  3088,  3093,
    3093,  3109,  3126,  3127,  3128,  3129,  3130,  3131,  3134,  3134,
    3137,  3139,  3142,  3145,  3147,  3148,  3149,  3151,  3153,  3155,
    3157,  3161,  3168,  3170,  3176,  3181,  3186,  3191,  3191,  3194,
    3200,  3205,  3208,  3215,  3215,  3217,  3223,  3227,  3228,  3230,
    3232,  3234,  3236,  3240,  3249,  3249,  3256,  3257,  3258,  3259,
    3260,  3261,  3262,  3263,  3264,  3265,  3266,  3267,  3268,  3269,
    3270,  3271,  3272,  3273,  3274,  3275,  3276,  3277,  3278,  3279,
    3280,  3281,  3282,  3283,  3284,  3285,  3286,  3287,  3288,  3289,
    3290,  3291,  3292,  3293,  3294,  3295,  3296,  3297,  3298,  3310,
    3323,  3330,  3330,  3334,  3339,  3345,  3349,  3353,  3359,  3363,
    3367,  3373,  3373,  3381,  3382,  3386,  3386,  3390,  3391,  3394,
    3397,  3397,  3400,  3402,  3402,  3405,  3407,  3407,  3408,  3410,
    3410,  3419,  3417,  3429,  3429,  3429,  3432,  3434,  3432,  3441,
    3447,  3457,  3457,  3461,  3467,  3467,  3471,  3472,  3483,  3484,
    3486,  3488,  3493,  3493,  3497,  3496,  3503,  3502,  3508,  3508,
    3513,  3513,  3519,  3519,  3524,  3524,  3529,  3529,  3534,  3534,
    3539,  3539,  3547,  3548,  3556,  3557,  3562,  3563,  3572,  3573,
    3580,  3581,  3589,  3590,  3599,  3604,  3609,  3610,  3611,  3615,
    3614,  3625,  3630,  3635,  3635,  3646,  3651,  3652,  3653,  3654,
    3657,  3657,  3663,  3663,  3665,  3668,  3668,  3670,  3674,  3674,
    3677,  3678,  3681,  3681,  3686,  3686,  3689,  3690,  3691,  3692,
    3693,  3694,  3695,  3696,  3697,  3698,  3699,  3700,  3701,  3702,
    3703,  3704,  3708,  3726,  3726,  3726,  3752,  3763,  3770,  3776,
    3782,  3788,  3799,  3822,  3821,  3838,  3838,  3842,  3843,  3851,
    3852,  3853,  3854,  3861,  3862,  3864,  3865,  3869,  3874,  3875,
    3876,  3877,  3878,  3879,  3880,  3881,  3882,  3883,  3884,  3887,
    3887,  3889,  3889,  3889,  3891,  3895,  3895,  3904,  3909,  3917,
    3923,  3903,  3937,  3951,  3960,  3950,  3973,  3980,  3980,  3985,
    3990,  3995,  3996,  3999,  3999,  3999,  4002,  4002,  4010,  4016,
    4030,  4034,  4047,  4029,  4065,  4065,  4078,  4089,  4088,  4100,
    4096,  4113,  4110,  4123,  4123,  4125,  4126,  4128,  4129,  4132,
    4133,  4134,  4136,  4141,  4146,  4152,  4154,  4155,  4158,  4159,
    4162,  4164,  4173,  4179,  4173,  4190,  4191,  4195,  4195,  4205,
    4205,  4217,  4220,  4224,  4228,  4233,  4237,  4238,  4239,  4240,
    4241,  4245,  4245,  4247,  4247,  4250,  4259,  4297,  4297,  4300,
    4304,  4309,  4347,  4348,  4349,  4352,  4366,  4378,  4378,  4383,
    4384,  4390,  4445,  4450,  4457,  4462,  4470,  4476,  4497,  4500,
    4501,  4539,  4540,  4544,  4545,  4549,  4602,  4606,  4609,  4615,
    4626,  4633,  4641,  4641,  4644,  4645,  4646,  4647,  4648,  4651,
    4654,  4660,  4663,  4667,  4671,  4678,  4683,  4690,  4693,  4699,
    4701,  4701,  4701,  4705,  4719,  4726,  4733,  4736,  4750,  4757,
    4758,  4761,  4762,  4766,  4772,  4777,  4783,  4784,  4789,  4793,
    4793,  4797,  4798,  4801,  4802,  4806,  4814,  4817,  4823,  4824,
    4826,  4828,  4832,  4832,  4833,  4838,  4846,  4847,  4852,  4853,
    4855,  4868,  4870,  4871,  4873,  4876,  4879,  4882,  4885,  4888,
    4891,  4895,  4899,  4903,  4906,  4910,  4913,  4914,  4915,  4918,
    4921,  4924,  4927,  4930,  4933,  4936,  4952,  4960,  4960,  4962,
    4969,  4976,  4991,  4989,  5009,  5014,  5015,  5019,  5020,  5022,
    5023,  5025,  5025,  5033,  5042,  5042,  5052,  5053,  5056,  5057,
    5060,  5060,  5072,  5077,  5082,  5087,  5097,  5097,  5101,  5104,
    5104,  5106,  5116,  5123,  5125,  5129,  5132,  5132,  5136,  5135,
    5139,  5138,  5142,  5141,  5145,  5144,  5148,  5147,  5150,  5150,
    5166,  5165,  5187,  5188,  5189,  5190,  5191,  5192,  5195,  5195,
    5201,  5201,  5204,  5204,  5214,  5215,  5216,  5223,  5235,  5236,
    5239,  5240,  5243,  5246,  5246,  5251,  5255,  5260,  5266,  5267,
    5268,  5272,  5273,  5274,  5275,  5279,  5289,  5291,  5296,  5299,
    5304,  5310,  5317,  5324,  5333,  5340,  5347,  5354,  5361,  5370,
    5370,  5372,  5372,  5375,  5376,  5377,  5378,  5379,  5380,  5381,
    5382,  5383,  5384,  5387,  5387,  5390,  5391,  5392,  5393,  5396,
    5396,  5399,  5399,  5402,  5403,  5404,  5405,  5406,  5407,  5408,
    5409,  5411,  5412,  5413,  5414,  5416,  5417,  5418,  5419,  5421,
    5422,  5423,  5424,  5425,  5426,  5427,  5428,  5432,  5438,  5446,
    5457,  5466,  5476,  5480,  5484,  5490,  5456,  5503,  5506,  5514,
    5526,  5528,  5533,  5538,  5547,  5550,  5554,  5562,  5532,  5571,
    5575,  5579,  5583,  5575,  5593,  5594,  5595,  5596,  5601,  5603,
    5606,  5610,  5613,  5620,  5625,  5626,  5627,  5631,  5638,  5640,
    5640,  5640,  5642,  5642,  5642,  5644,  5650,  5651,  5657,  5658,
    5663,  5664,  5665,  5669,  5670,  5675,  5676,  5682,  5683,  5688,
    5692,  5698,  5699,  5704,  5705,  5706,  5707,  5708,  5709,  5710,
    5715,  5718,  5725,  5726,  5732,  5733,  5740,  5743,  5750,  5751,
    5756,  5760,  5763,  5769,  5770,  5776,  5781,  5782,  5786,  5792,
    5793,  5800,  5801,  5806,  5807,  5812,  5823,  5824,  5825,  5826,
    5827,  5828,  5829,  5830,  5831,  5834,  5837,  5843,  5843,  5849,
    5849,  5860,  5874,  5876,  5874,  5883,  5886,  5891,  5899,  5908,
    5909,  5918,  5937,  5937,  5944,  5946,  5952,  5953,  5956,  5957,
    5961,  5962,  5963,  5967,  5977,  5977,  5983,  5983,  5986,  5989,
    5990,  5996,  5997,  6002,  6003,  6008,  6009,  6014,  6018,  6013,
    6030,  6034,  6041,  6045,  6045,  6058,  6062,  6062,  6077,  6079,
    6081,  6083,  6085,  6087,  6089,  6091,  6097,  6107,  6112,  6117,
    6118,  6122,  6124,  6125,  6128,  6129,  6130,  6133,  6138,  6145,
    6146,  6152,  6165,  6165,  6170,  6175,  6181,  6182,  6185,  6186,
    6193,  6200,  6204,  6214,  6215,  6219,  6227,  6231,  6232,  6237,
    6239,  6243,  6244,  6248,  6249,  6250,  6251,  6255,  6256,  6261,
    6262,  6267,  6268,  6273,  6274,  6279,  6283,  6284,  6289,  6290,
    6294,  6295,  6300,  6306,  6311,  6316,  6320,  6321,  6326,  6327,
    6333,  6335,  6340,  6341,  6347,  6348,  6349,  6354,  6356,  6367,
    6371,  6372,  6375,  6376,  6381,  6383,  6385,  6386,  6392,  6397,
    6402,  6406,  6407,  6412,  6413,  6422,  6428,  6433,  6434,  6439,
    6444,  6448,  6449,  6454,  6455,  6456,  6459,  6460,  6465,  6465,
    6469,  6480,  6481,  6484,  6485,  6488,  6489,  6494,  6495,  6500,
    6501,  6506,  6507,  6512,  6513,  6519,  6520,  6525,  6527,  6532,
    6533,  6534,  6537,  6541,  6542,  6550,  6555,  6559,  6564,  6566,
    6568,  6570,  6576,  6577,  6581,  6581,  6584,  6585,  6590,  6592,
    6594,  6596,  6598,  6600,  6606,  6607,  6608,  6609,  6610,  6611,
    6612,  6613,  6614,  6615,  6620,  6621,  6622,  6623,  6625,  6626,
    6627,  6628,  6640,  6641,  6642,  6646,  6647,  6652,  6654,  6655,
    6656,  6658,  6659,  6660,  6661,  6663,  6664,  6666,  6667,  6669,
    6670,  6671,  6672,  6674,  6678,  6679,  6685,  6687,  6688,  6689,
    6690,  6695,  6699,  6703,  6707,  6708,  6712,  6713,  6720,  6728,
    6729,  6730,  6733,  6738,  6743,  6753,  6757,  6761,  6762,  6763,
    6764,  6766,  6768,  6770,  6772,  6775,  6778,  6782,  6783,  6787,
    6788,  6792,  6792,  6792,  6792,  6792,  6792,  6793,  6796,  6801,
    6801,  6801,  6801,  6801,  6801,  6803,  6806,  6812,  6812,  6812,
    6812,  6812,  6812,  6812,  6813,  6813,  6813,  6813,  6813,  6813,
    6813,  6815,  6816,  6819,  6829,  6828,  6834,  6834,  6840,  6840,
    6846,  6846,  6856,  6857,  6858,  6861,  6861,  6864,  6865,  6866,
    6871,  6872,  6878,  6881,  6886,  6900,  6902,  6897,  6915,  6924,
    6924,  6927,  6935,  6936,  6940,  6941,  6942,  6946,  6949,  6950,
    6959,  6964,  6968,  6969,  6970,  6971,  6979,  6980,  6984,  6985,
    6986,  6991,  6996,  6997,  7001,  7003,  7005,  7007,  7009,  7011,
    7012,  7013,  7014,  7015,  7016,  7018,  7020,  7022,  7024,  7026,
    7028,  7030,  7032,  7033,  7037,  7037,  7039,  7040,  7043,  7051,
    7056,  7056,  7060,  7060,  7065,  7065,  7069,  7069,  7073,  7079,
    7079,  7082,  7082,  7088,  7095,  7096,  7097,  7101,  7102,  7105,
    7106,  7110,  7116,  7126,  7127,  7135,  7136,  7137,  7138,  7139,
    7140,  7144,  7145,  7146,  7229,  7241,  7241,  7245,  7246,  7247,
    7248,  7252,  7253,  7254,  7257,  7269,  7367,  7369,  7371,  7373,
    7377,  7382,  7384,  7386,  7388,  7392,  7395,  7400,  7405,  7409,
    7418,  7419,  7423,  7435,  7438,  7434,  7457,  7457,  7461,  7462,
    7465,  7466,  7467,  7468,  7469,  7470,  7471,  7476,  7477,  7481,
    7484,  7489,  7493,  7498,  7502,  7507,  7511,  7514,  7518,  7521,
    7526,  7530,  7541,  7547,  7547,  7548,  7549,  7556,  7565,  7565,
    7567,  7568,  7569,  7570,  7571,  7572,  7573,  7574,  7575,  7576,
    7577,  7578,  7579,  7580,  7581,  7582,  7583,  7584,  7585,  7586,
    7587,  7588,  7589,  7590,  7591,  7592,  7593,  7594,  7595,  7596,
    7597,  7598,  7599,  7600,  7601,  7602,  7603,  7604,  7605,  7606,
    7607,  7608,  7609,  7610,  7611,  7612,  7613,  7614,  7615,  7616,
    7617,  7618,  7619,  7620,  7621,  7622,  7623,  7624,  7625,  7626,
    7627,  7628,  7629,  7630,  7631,  7632,  7633,  7634,  7635,  7636,
    7637,  7638,  7639,  7640,  7641,  7642,  7643,  7644,  7645,  7646,
    7647,  7648,  7649
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
  "bef_c_field_list", "aft_c_field_list", "interval_expr", "defer_cmd", 
  "define_section", "define_multiple", "define_set", "@29", "@30", 
  "def_part", "define_ident", "@31", "def_part2", "@32", "constant_value", 
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
  "pdf_expr", "variable_or_current", "for_cmd", "@66", "@67", "for_step", 
  "foreach_cmd", "@68", "@69", "@70", "formhandler_def", "@71", "@72", 
  "op_input_section", "op_bef_ev_list", "bef_ev_list", "bef_ev", "@73", 
  "@74", "op_aft_ev_list", "aft_ev_list", "aft_ev", "@75", "@76", 
  "input_section", "input_sub_section", "in_variable_list", "in_id_list", 
  "in_bn_variable_list", "field_ops", "field_op", "@77", "@78", "@79", 
  "@80", "@81", "free_cmd", "line_no", "file_name", "a_number", "coords", 
  "display_coords", "field_name", "cursor_name", "fetch_cursor_name", 
  "win_name", "open_win_name", "form_name", "open_form_name", 
  "opt_help_no", "identifier", "ident_or_var", "ident_p2", 
  "var_or_string", "setident", "unsetident", "field_name2", "cvariable", 
  "real_number", "reserved_word", "goto_cmd", "check_menu_cmd", 
  "menu_item_list", "menu_item", "uncheck_menu_cmd", "disable_cmd", 
  "enable_cmd", "msg_box_cmd", "@82", "op_disable_msg", "gm_disable_msg", 
  "op_returning_msg", "gm_returning_msg", "op_caption", "gm_caption", 
  "op_icon", "gm_icon", "op_buttons", "gm_buttons", "op_def_but", 
  "if_cmd", "@83", "op_else", "@84", "@85", "@86", "import_m", 
  "module_import", "init_cmd", "@87", "init_tab_list", "init_tab", 
  "end_input", "opt_defs", "field_commands", "field_command", "@88", 
  "@89", "@90", "@91", "@92", "@93", "@94", "@95", "@96", 
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
     729,   730,   730,   731,   731,   733,   734,   732,   732,   732,
     735,   735,   737,   736,   738,   738,   738,   738,   739,   738,
     740,   740,   740,   740,   741,   742,   742,   743,   743,   745,
     744,   746,   744,   747,   747,   748,   748,   749,   750,   750,
     750,   751,   753,   752,   754,   752,   755,   752,   756,   756,
     757,   758,   759,   759,   761,   762,   760,   763,   763,   763,
     763,   763,   763,   763,   763,   763,   763,   763,   763,   763,
     763,   763,   763,   763,   763,   763,   763,   763,   763,   763,
     763,   763,   763,   763,   763,   764,   765,   766,   767,   767,
     768,   770,   769,   771,   771,   771,   771,   771,   771,   771,
     773,   772,   774,   774,   775,   775,   776,   778,   777,   779,
     779,   779,   779,   779,   779,   779,   780,   781,   781,   783,
     782,   784,   784,   784,   784,   784,   784,   784,   784,   784,
     784,   784,   784,   784,   784,   784,   784,   784,   784,   784,
     784,   784,   784,   784,   785,   787,   786,   788,   786,   790,
     789,   791,   789,   792,   792,   793,   794,   794,   795,   796,
     796,   796,   796,   796,   796,   796,   796,   797,   798,   799,
     801,   802,   800,   803,   803,   804,   805,   805,   806,   806,
     808,   807,   809,   807,   810,   807,   811,   811,   812,   812,
     812,   812,   812,   812,   812,   812,   812,   813,   813,   813,
     813,   813,   813,   813,   813,   814,   814,   815,   815,   815,
     815,   815,   815,   815,   815,   815,   815,   816,   816,   816,
     816,   816,   816,   816,   816,   816,   816,   817,   817,   818,
     818,   819,   819,   820,   820,   821,   821,   822,   823,   823,
     824,   824,   824,   824,   824,   824,   825,   825,   826,   826,
     826,   826,   827,   827,   828,   829,   829,   829,   830,   829,
     831,   831,   832,   832,   833,   833,   833,   833,   834,   834,
     835,   835,   835,   835,   836,   837,   838,   838,   838,   838,
     838,   838,   839,   839,   839,   839,   839,   839,   839,   840,
     842,   843,   841,   844,   845,   841,   847,   848,   846,   849,
     850,   846,   851,   852,   846,   853,   854,   846,   846,   846,
     846,   846,   846,   846,   855,   855,   856,   856,   857,   857,
     857,   857,   857,   857,   857,   857,   857,   858,   858,   859,
     859,   859,   859,   860,   860,   860,   861,   861,   861,   863,
     864,   862,   865,   865,   867,   868,   869,   866,   871,   872,
     870,   873,   873,   874,   874,   875,   875,   877,   876,   878,
     876,   879,   879,   880,   880,   882,   881,   883,   881,   884,
     885,   885,   885,   886,   886,   887,   887,   888,   888,   889,
     889,   891,   890,   892,   890,   893,   890,   894,   890,   895,
     890,   896,   897,   897,   897,   897,   897,   897,   898,   898,
     899,   900,   901,   902,   902,   902,   902,   902,   902,   902,
     902,   903,   904,   905,   906,   907,   908,   909,   909,   910,
     911,   912,   912,   913,   913,   914,   915,   916,   916,   916,
     916,   916,   916,   917,   918,   918,   919,   919,   919,   919,
     919,   919,   919,   919,   919,   919,   919,   919,   919,   919,
     919,   919,   919,   919,   919,   919,   919,   919,   919,   919,
     919,   919,   919,   919,   919,   919,   919,   919,   919,   919,
     919,   919,   919,   919,   919,   919,   919,   919,   919,   920,
     921,   922,   922,   923,   924,   925,   925,   925,   926,   926,
     926,   928,   927,   929,   929,   930,   930,   931,   931,   932,
     933,   933,   934,   935,   935,   936,   937,   937,   938,   939,
     939,   941,   940,   942,   943,   942,   944,   945,   942,   946,
     947,   949,   948,   948,   950,   950,   951,   951,   952,   952,
     953,   953,   954,   954,   956,   955,   957,   955,   958,   955,
     959,   955,   960,   955,   961,   955,   962,   955,   963,   955,
     964,   955,   965,   965,   966,   966,   967,   967,   968,   968,
     969,   969,   970,   970,   971,   972,   973,   973,   973,   975,
     974,   976,   976,   977,   976,   978,   979,   979,   979,   979,
     980,   980,   982,   981,   981,   984,   983,   985,   987,   986,
     988,   988,   989,   989,   991,   990,   992,   992,   992,   992,
     992,   992,   992,   992,   992,   992,   992,   992,   992,   992,
     992,   992,   993,   995,   996,   994,   997,   997,   998,   999,
    1000,  1001,  1001,  1003,  1002,  1004,  1004,  1005,  1005,  1006,
    1006,  1006,  1006,  1007,  1007,  1008,  1008,  1009,  1010,  1010,
    1010,  1010,  1010,  1010,  1010,  1010,  1010,  1010,  1010,  1011,
    1011,  1012,  1012,  1012,  1013,  1014,  1014,  1016,  1017,  1018,
    1019,  1015,  1020,  1022,  1023,  1021,  1024,  1025,  1025,  1026,
    1027,  1028,  1028,  1029,  1029,  1029,  1031,  1030,  1032,  1032,
    1034,  1035,  1036,  1033,  1038,  1037,  1039,  1041,  1040,  1042,
    1040,  1043,  1040,  1044,  1044,  1045,  1045,  1046,  1046,  1047,
    1047,  1047,  1048,  1049,  1050,  1051,  1051,  1051,  1052,  1052,
    1053,  1053,  1055,  1056,  1054,  1057,  1057,  1059,  1058,  1060,
    1058,  1061,  1062,  1062,  1062,  1062,  1063,  1063,  1063,  1063,
    1063,  1065,  1064,  1066,  1066,  1067,  1068,  1069,  1069,  1070,
    1071,  1071,  1071,  1071,  1071,  1072,  1073,  1074,  1074,  1075,
    1075,  1076,  1077,  1077,  1078,  1078,  1079,  1080,  1081,  1081,
    1081,  1081,  1081,  1082,  1082,  1083,  1084,  1084,  1085,  1085,
    1086,  1086,  1087,  1087,  1088,  1088,  1088,  1088,  1088,  1089,
    1089,  1090,  1090,  1091,  1091,  1092,  1093,  1094,  1094,  1095,
    1096,  1096,  1096,  1097,  1098,  1098,  1099,  1099,  1100,  1101,
    1101,  1102,  1102,  1103,  1104,  1105,  1106,  1106,  1107,  1108,
    1108,  1109,  1109,  1110,  1110,  1111,  1112,  1112,  1113,  1113,
    1113,  1113,  1114,  1114,  1114,  1115,  1116,  1116,  1117,  1117,
    1117,  1118,  1119,  1119,  1120,  1120,  1120,  1120,  1120,  1120,
    1120,  1120,  1120,  1120,  1120,  1120,  1120,  1120,  1120,  1120,
    1120,  1120,  1120,  1120,  1120,  1120,  1121,  1122,  1122,  1123,
    1123,  1124,  1126,  1125,  1127,  1128,  1128,  1129,  1129,  1130,
    1130,  1132,  1131,  1133,  1135,  1134,  1136,  1136,  1137,  1137,
    1138,  1138,  1139,  1139,  1139,  1139,  1140,  1140,  1141,  1142,
    1142,  1143,  1144,  1145,  1146,  1146,  1147,  1147,  1149,  1148,
    1150,  1148,  1151,  1148,  1152,  1148,  1153,  1148,  1154,  1148,
    1155,  1148,  1156,  1156,  1156,  1156,  1156,  1156,  1158,  1157,
    1159,  1159,  1161,  1160,  1160,  1160,  1160,  1160,  1162,  1162,
    1163,  1163,  1164,  1165,  1165,  1166,  1167,  1168,  1169,  1169,
    1169,  1170,  1170,  1170,  1170,  1171,  1172,  1172,  1173,  1173,
    1174,  1175,  1175,  1175,  1175,  1175,  1175,  1175,  1175,  1176,
    1176,  1177,  1177,  1178,  1178,  1178,  1178,  1178,  1178,  1178,
    1178,  1178,  1178,  1179,  1179,  1180,  1180,  1180,  1180,  1181,
    1181,  1182,  1182,  1183,  1183,  1183,  1183,  1183,  1183,  1183,
    1183,  1183,  1183,  1183,  1183,  1183,  1183,  1183,  1183,  1183,
    1183,  1183,  1183,  1183,  1183,  1183,  1183,  1184,  1184,  1184,
    1186,  1187,  1188,  1189,  1190,  1191,  1185,  1192,  1192,  1193,
    1194,  1194,  1196,  1197,  1198,  1199,  1200,  1201,  1195,  1202,
    1204,  1205,  1206,  1203,  1207,  1207,  1207,  1207,  1208,  1208,
    1208,  1208,  1208,  1209,  1210,  1210,  1210,  1211,  1212,  1213,
    1214,  1212,  1215,  1216,  1212,  1212,  1217,  1217,  1218,  1218,
    1219,  1219,  1219,  1220,  1220,  1221,  1221,  1222,  1222,  1223,
    1224,  1225,  1225,  1226,  1226,  1226,  1226,  1226,  1226,  1226,
    1227,  1227,  1228,  1228,  1229,  1229,  1230,  1230,  1231,  1231,
    1232,  1233,  1233,  1234,  1234,  1235,  1236,  1236,  1237,  1238,
    1238,  1239,  1239,  1240,  1240,  1241,  1242,  1242,  1242,  1242,
    1242,  1242,  1242,  1242,  1242,  1242,  1242,  1243,  1243,  1244,
    1244,  1245,  1247,  1248,  1246,  1249,  1249,  1249,  1250,  1250,
    1250,  1250,  1251,  1251,  1252,  1253,  1254,  1254,  1255,  1255,
    1256,  1256,  1256,  1257,  1259,  1258,  1261,  1260,  1260,  1262,
    1262,  1263,  1263,  1264,  1264,  1265,  1265,  1267,  1268,  1266,
    1269,  1269,  1270,  1271,  1270,  1272,  1273,  1272,  1274,  1274,
    1274,  1274,  1274,  1274,  1274,  1274,  1275,  1276,  1277,  1278,
    1278,  1279,  1280,  1280,  1281,  1281,  1281,  1282,  1283,  1284,
    1284,  1285,  1287,  1286,  1288,  1288,  1288,  1288,  1288,  1288,
    1288,  1288,  1288,  1288,  1288,  1288,  1289,  1290,  1290,  1291,
    1291,  1292,  1292,  1293,  1293,  1293,  1293,  1294,  1294,  1295,
    1295,  1296,  1296,  1297,  1297,  1298,  1299,  1299,  1300,  1300,
    1301,  1301,  1302,  1303,  1304,  1305,  1306,  1306,  1307,  1307,
    1308,  1308,  1309,  1309,  1310,  1310,  1310,  1311,  1311,  1312,
    1313,  1313,  1314,  1314,  1315,  1315,  1315,  1315,  1316,  1317,
    1318,  1319,  1319,  1320,  1320,  1321,  1322,  1323,  1323,  1324,
    1325,  1326,  1326,  1327,  1327,  1327,  1328,  1328,  1329,  1329,
    1330,  1331,  1331,  1332,  1332,  1333,  1333,  1334,  1334,  1335,
    1335,  1336,  1336,  1337,  1337,  1338,  1338,  1339,  1339,  1340,
    1340,  1340,  1341,  1342,  1342,  1343,  1344,  1345,  1346,  1346,
    1346,  1346,  1347,  1347,  1348,  1348,  1349,  1349,  1350,  1350,
    1350,  1350,  1350,  1350,  1351,  1351,  1351,  1351,  1351,  1351,
    1351,  1351,  1351,  1351,  1352,  1352,  1352,  1352,  1353,  1353,
    1353,  1353,  1354,  1354,  1354,  1355,  1355,  1356,  1356,  1356,
    1356,  1356,  1356,  1356,  1356,  1356,  1356,  1356,  1356,  1356,
    1356,  1356,  1356,  1356,  1357,  1357,  1358,  1358,  1358,  1358,
    1358,  1359,  1360,  1361,  1362,  1362,  1362,  1362,  1363,  1364,
    1364,  1364,  1365,  1365,  1365,  1366,  1367,  1367,  1367,  1367,
    1367,  1367,  1367,  1367,  1367,  1368,  1369,  1370,  1370,  1371,
    1371,  1372,  1372,  1372,  1372,  1372,  1372,  1372,  1372,  1373,
    1373,  1373,  1373,  1373,  1373,  1373,  1373,  1374,  1374,  1374,
    1374,  1374,  1374,  1374,  1375,  1375,  1375,  1375,  1375,  1375,
    1375,  1376,  1376,  1377,  1379,  1378,  1380,  1378,  1381,  1378,
    1382,  1378,  1383,  1383,  1383,  1384,  1384,  1385,  1385,  1385,
    1386,  1386,  1387,  1387,  1388,  1390,  1391,  1389,  1392,  1393,
    1393,  1394,  1395,  1395,  1395,  1395,  1395,  1396,  1397,  1397,
    1398,  1399,  1400,  1400,  1400,  1400,  1401,  1401,  1402,  1402,
    1402,  1403,  1404,  1404,  1405,  1405,  1405,  1405,  1405,  1405,
    1405,  1405,  1405,  1405,  1405,  1405,  1405,  1405,  1405,  1405,
    1405,  1405,  1405,  1405,  1406,  1406,  1407,  1407,  1408,  1409,
    1410,  1410,  1411,  1411,  1412,  1412,  1413,  1413,  1414,  1415,
    1415,  1416,  1416,  1417,  1418,  1418,  1418,  1419,  1419,  1420,
    1421,  1422,  1423,  1424,  1424,  1425,  1425,  1425,  1425,  1425,
    1425,  1426,  1426,  1426,  1427,  1428,  1428,  1429,  1429,  1429,
    1429,  1430,  1430,  1430,  1431,  1431,  1432,  1432,  1432,  1432,
    1432,  1432,  1432,  1432,  1432,  1433,  1433,  1433,  1433,  1433,
    1434,  1434,  1435,  1437,  1438,  1436,  1439,  1439,  1440,  1440,
    1441,  1441,  1441,  1441,  1441,  1441,  1441,  1442,  1442,  1443,
    1443,  1444,  1444,  1445,  1445,  1446,  1446,  1447,  1448,  1449,
    1450,  1450,  1451,  1452,  1452,  1453,  1454,  1454,  1456,  1455,
    1457,  1457,  1457,  1457,  1457,  1457,  1457,  1457,  1457,  1457,
    1457,  1457,  1457,  1457,  1457,  1457,  1457,  1457,  1457,  1457,
    1457,  1457,  1457,  1457,  1457,  1457,  1457,  1457,  1457,  1457,
    1457,  1457,  1457,  1457,  1457,  1457,  1457,  1457,  1457,  1457,
    1457,  1457,  1457,  1457,  1457,  1457,  1457,  1457,  1457,  1457,
    1457,  1457,  1457,  1457,  1457,  1457,  1457,  1457,  1457,  1457,
    1457,  1457,  1457,  1457,  1457,  1457,  1457,  1457,  1457,  1457,
    1457,  1457,  1457,  1457,  1457,  1457,  1457,  1457,  1457,  1457,
    1457,  1457,  1457
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
       3,     1,     3,     1,     1,     1,     1,     1,     1,     1,
       1,     0,     1,     1,     2,     0,     0,     5,     1,     1,
       1,     3,     0,     2,     4,     4,     4,     2,     0,     4,
       1,     1,     1,     2,     1,     1,     3,     0,     1,     0,
       7,     0,    12,     1,     1,     1,     1,     1,     5,     3,
       1,     1,     0,     4,     0,     5,     0,     7,     1,     3,
       1,     1,     0,     1,     0,     0,     4,     1,     1,     1,
       4,     4,     6,     1,     2,     1,     1,     1,     1,     4,
       6,     1,     4,     6,     1,     1,     1,     1,     1,     1,
       1,     2,     2,     1,     1,     4,     1,     1,     0,     3,
       3,     0,     2,     1,     1,     1,     1,     1,     1,     2,
       0,     2,     0,     3,     0,     3,     1,     0,     3,     1,
       1,     1,     1,     1,     1,     2,     1,     0,     1,     0,
       5,     1,     1,     1,     4,     4,     6,     1,     1,     1,
       1,     4,     6,     1,     4,     6,     1,     1,     1,     1,
       1,     2,     2,     1,     4,     0,     7,     0,    12,     0,
       4,     0,     5,     1,     3,     2,     1,     3,     1,     0,
       2,     2,     1,     2,     5,     4,     2,     4,     5,     3,
       0,     0,    11,     0,     2,     1,     0,     2,     1,     2,
       0,     3,     0,     3,     0,     3,     4,     5,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     2,     1,     1,     1,
       1,     2,     1,     1,     1,     2,     2,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     2,     1,
       1,     1,     3,     1,     3,     1,     3,     1,     1,     1,
       2,     1,     1,     3,     4,     4,     2,     2,     1,     1,
       1,     1,     1,     3,     1,     2,     2,     1,     0,     3,
       2,     2,     1,     3,     4,     4,     5,     5,     1,     1,
       2,     2,     2,     2,     1,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     0,
       0,     0,     6,     0,     0,     6,     0,     0,     6,     0,
       0,     6,     0,     0,     6,     0,     0,     6,     5,     5,
       7,     5,     5,     7,     0,     3,     0,     3,     1,     4,
       4,     4,     4,     4,     4,     1,     1,     1,     1,     4,
       4,     2,     4,     2,     2,     2,     5,     5,     4,     0,
       0,    11,     0,     2,     0,     0,     0,     8,     0,     0,
      10,     0,     1,     0,     1,     1,     2,     0,     3,     0,
       3,     0,     1,     1,     2,     0,     3,     0,     3,     3,
       1,     4,     3,     1,     3,     1,     3,     1,     3,     1,
       2,     0,     3,     0,     3,     0,     4,     0,     4,     0,
       4,     2,     3,     1,     3,     1,     1,     1,     1,     1,
       1,     3,     1,     1,     4,     6,     4,     3,     6,     3,
       6,     1,     1,     1,     1,     1,     1,     0,     2,     3,
       3,     1,     4,     1,     1,     0,     0,     1,     4,     3,
       6,     3,     6,     1,     1,     2,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     2,
       2,     1,     3,     1,     2,     2,     2,     4,     2,     2,
       4,     0,     8,     0,     1,     1,     1,     0,     1,     2,
       0,     1,     2,     0,     1,     2,     0,     1,     3,     0,
       2,     0,     7,     0,     0,     3,     0,     0,     7,     5,
       2,     0,     5,     4,     1,     3,     3,     3,     0,     2,
       0,     1,     1,     2,     0,     4,     0,     4,     0,     3,
       0,     3,     0,     3,     0,     3,     0,     3,     0,     4,
       0,     4,     1,     3,     1,     1,     1,     3,     1,     1,
       1,     3,     1,     3,     2,     4,     1,     1,     1,     0,
       4,     5,     6,     0,    10,     3,     1,     1,     2,     2,
       0,     2,     0,     3,     1,     0,     3,     2,     0,     3,
       1,     3,     1,     3,     0,     2,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     0,     0,     7,     1,     1,     2,     2,
       2,     3,     4,     0,     3,     0,     1,     1,     2,     1,
       1,     1,     1,     0,     1,     1,     2,     2,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     0,     1,     1,     1,     1,     1,     0,     0,     0,
       0,    13,     1,     0,     0,     6,     2,     1,     2,     2,
       1,     1,     2,     1,     1,     1,     0,     3,     2,     1,
       0,     0,     0,    14,     0,     5,     1,     0,     3,     0,
       7,     0,     5,     1,     2,     0,     1,     1,     1,     0,
       1,     1,     2,     2,     2,     1,     1,     1,     1,     3,
       1,     1,     0,     0,     7,     1,     2,     0,     3,     0,
       4,     2,     0,     2,     1,     1,     1,     1,     1,     1,
       1,     0,     3,     0,     1,     1,     1,     1,     2,     3,
       2,     5,     1,     1,     1,     4,     4,     1,     1,     1,
       1,     2,     3,     6,     1,     3,     1,     1,     1,     4,
       7,     1,     1,     1,     1,     2,     0,     1,     1,     3,
       1,     3,     1,     3,     1,     3,     1,     1,     1,     1,
       3,     1,     3,     1,     3,     1,     1,     1,     3,     2,
       0,     1,     1,     4,     1,     3,     1,     3,     7,     0,
       7,     0,     6,     3,     1,     3,     1,     2,     5,     0,
       7,     0,     2,     0,     1,     5,     2,     5,     0,     5,
       6,     4,     0,     1,     1,     4,     0,     2,     0,     5,
       4,     2,     1,     3,     2,     2,     2,     2,     2,     2,
       1,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       1,     1,     1,     1,     1,     1,     5,     1,     1,     2,
       4,     1,     0,    10,     5,     0,     1,     0,     2,     1,
       2,     0,     3,     1,     0,     4,     0,     2,     1,     3,
       1,     1,     3,     4,     4,     2,     1,     1,     1,     0,
       1,     7,     2,     2,     2,     2,     1,     2,     0,     3,
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
       3,     3,     3,     1,     1,     1,     1,     1,     3,     0,
       0,     7,     0,     0,     8,     2,     0,     1,     1,     3,
       2,     2,     1,     1,     3,     1,     1,     2,     1,     1,
       3,     1,     3,     1,     1,     1,     1,     1,     1,     1,
       2,     4,     1,     3,     1,     3,     2,     4,     1,     3,
       1,     2,     4,     1,     3,     1,     1,     1,     2,     2,
       4,     2,     4,     1,     3,     1,     1,     1,     2,     1,
       1,     1,     1,     1,     2,     6,     6,     0,     1,     0,
       1,     2,     0,     0,     7,     0,     2,     2,     7,     1,
       5,     3,     1,     3,     1,     3,     1,     3,     1,     3,
       1,     1,     1,     1,     0,     5,     0,     5,     1,     0,
       3,     1,     3,     1,     3,     1,     1,     0,     0,     5,
       2,     1,     0,     0,     3,     0,     0,     3,     1,     1,
       1,     1,     1,     1,     2,     2,     4,     3,     3,     1,
       3,     2,     1,     1,     0,     1,     1,     1,     1,     0,
       1,     3,     0,     3,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     7,     0,     1,     1,
       1,     1,     3,     1,     1,     1,     2,     0,     3,     1,
       3,     1,     3,     1,     1,     6,     0,     3,     1,     3,
       0,     1,     4,     5,     2,     1,     1,     4,     1,     3,
       4,     4,     1,     3,     1,     1,     1,     2,     1,     4,
       0,     1,     0,     2,     1,     1,     1,     4,     3,     1,
       1,     1,     2,     1,     1,     2,     2,     1,     3,     2,
       2,     1,     3,     1,     2,     4,     1,     2,     1,     3,
       4,     0,     1,     0,     1,     0,     1,     1,     3,     1,
       3,     1,     2,     1,     3,     2,     2,     4,     3,     0,
       1,     1,     1,     1,     1,     2,     1,     1,     5,     3,
       5,     3,     1,     3,     1,     1,     0,     1,     3,     3,
       3,     3,     6,     5,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     0,     1,
       1,     1,     1,     1,     1,     1,     4,     5,     1,     5,
       5,     1,     1,     1,     4,     1,     4,     1,     7,     1,
       1,     1,     4,     6,     0,     2,     4,     1,     1,     1,
       1,     1,     1,     1,     3,     1,     1,     3,     1,     0,
       3,     5,     2,     5,     4,     1,     1,     1,     1,     1,
       2,     2,     2,     2,     1,     2,     2,     0,     3,     0,
       3,     1,     1,     1,     1,     1,     1,     1,     4,     1,
       1,     1,     1,     1,     1,     1,     4,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     3,     0,     8,     0,     9,     0,     7,
       0,     9,     0,     1,     2,     1,     3,     1,     3,     5,
       1,     1,     1,     1,     2,     0,     0,     8,     5,     1,
       1,     7,     0,     3,     1,     3,     4,     1,     0,     2,
       5,     7,     0,     1,     1,     1,     1,     3,     1,     2,
       2,     1,     1,     1,     3,     2,     3,     3,     3,     1,
       1,     1,     1,     1,     1,     5,     5,     5,     5,     5,
       4,     6,     3,     4,     1,     3,     0,     1,     5,     7,
       0,     2,     1,     1,     0,     3,     1,     3,     1,     1,
       1,     0,     3,     1,     1,     1,     1,     4,     6,     1,
       1,     2,     3,     1,     1,     1,     1,     1,     1,     1,
       1,     5,     5,     4,     1,     2,     1,     1,     1,     3,
       5,     1,     1,     1,     1,     3,     2,     2,     2,     1,
       2,     2,     2,     2,     2,     1,     3,     2,     1,     2,
       1,     2,     1,     0,     0,     6,     0,     2,     0,     1,
       1,     2,     2,     1,     1,     4,     3,     1,     3,     1,
       2,     5,     2,     2,     5,     0,     2,     1,     1,     2,
       6,     6,     1,     0,     1,     2,     1,     2,     0,     2,
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
     795,     0,   595,     0,     0,     0,     0,     0,     0,     0,
    1729,     0,   595,   595,   846,   175,   819,   824,   173,   178,
     799,     0,   793,   796,   797,   800,   802,   845,   801,   840,
     841,   843,   179,   133,   130,     0,   126,   128,   127,   131,
     690,     0,  1735,   595,   595,  1738,     0,  1734,  1731,  1728,
    1726,  1727,  1733,  1732,  1730,   289,  1602,  1601,   839,   171,
     182,   174,   179,     1,   803,   798,   844,   842,   820,   125,
     129,   132,  1772,   596,  1742,  1739,   595,  1740,  1737,   595,
       0,   568,   595,     0,   172,   849,   913,   569,   847,   603,
     906,   595,   907,   914,   912,   182,   176,   194,   595,   180,
     195,   224,   826,  1192,   595,   595,   825,   134,  1180,   833,
     595,   595,   816,   818,   815,   817,   794,   804,   805,   827,
     808,   809,   810,   813,   811,   812,   814,   589,  1741,  1736,
       0,   908,   848,   595,   595,   921,   919,   920,   910,     0,
     287,   182,  1116,   188,   183,   182,   187,   221,     0,   595,
       0,     0,   595,   171,   518,   882,   806,   595,   321,   307,
     197,   258,   277,   298,   300,   297,     0,   319,     0,   306,
     299,   303,   309,   293,   308,   182,   310,   290,   313,   291,
     292,   918,   917,     0,    21,    22,    13,   595,   926,     0,
      15,     0,   924,   595,   909,   288,     0,   181,  1117,   177,
       0,   194,   196,   254,   248,   249,   237,   214,   245,   197,
     216,   258,   277,   235,   238,   233,     0,   212,     0,   244,
     236,   241,   247,   229,   246,   182,   250,   182,   227,   228,
     225,   253,     0,     0,   595,     0,   834,   171,   171,     0,
     595,   198,     0,   311,     0,     0,   312,     0,     0,     0,
       0,   595,     0,     0,     0,   256,     0,   915,     0,    16,
      17,    19,    18,    20,   595,    14,   595,   922,     0,   604,
     184,   186,     0,   185,     0,   191,   190,   189,   192,   182,
       0,   182,   251,   252,     0,     0,   182,     0,     0,     0,
       0,   234,   222,  1193,     0,     0,  1181,  1778,   519,   883,
     828,     0,   203,   204,     0,   270,   272,   267,   268,   264,
     266,   263,   265,   262,     0,   272,   283,   284,   280,   282,
     279,   281,   274,     0,     0,     0,   323,     0,   326,   328,
     211,     0,   210,     0,     0,   182,    11,    12,   925,   595,
     911,   605,   193,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   182,   223,   226,   595,   689,   850,   595,     0,
    1776,  1778,  1116,  1691,   821,     0,   595,     0,     0,   259,
       0,     0,   269,   286,   260,   285,     0,   278,     0,   301,
       0,   295,   595,   320,   595,   325,   315,     0,     0,   304,
     294,   257,   314,     0,     0,     0,     0,     0,   239,     0,
     231,   213,   199,     0,   242,   230,   255,   942,     0,   937,
     938,   595,     0,   835,  1777,  1775,   595,   595,   595,   595,
     595,   595,   595,  1759,   595,  1282,  1281,   595,  1283,   595,
     371,  1280,  1222,   595,     5,  1279,   372,   369,   595,   374,
     169,   459,  1094,     0,     0,  1289,   122,   368,   367,  1214,
     362,   595,  1238,  1750,   595,   373,   340,   595,     3,     2,
     595,   370,  1219,   595,   595,   363,   360,   375,   595,   595,
     595,   595,   595,  1277,   366,   595,   595,   595,   595,   595,
     595,   595,   595,  1276,   595,   595,   595,   170,  1216,   359,
     358,   595,   595,  1754,  1753,   595,   595,   595,   135,  1215,
     365,   364,   595,   595,   361,   901,   459,   595,   514,     0,
     595,   595,   459,   595,   595,   595,   459,   782,  1190,   595,
     595,  1098,   595,  1743,   595,   102,   595,   595,   854,   595,
     595,   595,   595,   783,   595,   595,   595,     0,   595,   595,
     595,   595,   595,   595,   595,   661,   595,   595,  1780,  1781,
    1782,  1783,  1784,  1785,  1786,  1787,  1788,  1789,  1790,  1791,
    1792,  1793,  1794,  1795,  1796,  1797,  1798,  1799,  1800,  1801,
    1802,  1803,  1804,  1805,  1806,  1807,  1808,  1809,  1810,  1811,
    1812,  1813,  1814,  1815,  1816,  1817,  1818,  1819,  1820,  1821,
    1822,  1823,  1824,  1825,  1826,   892,  1827,  1828,  1829,  1830,
    1831,  1832,  1833,  1834,  1835,  1836,  1837,  1838,  1839,  1840,
    1841,  1842,  1085,  1087,  1082,  1084,  1083,  1086,  1843,  1844,
    1213,  1845,  1217,  1846,  1847,  1239,  1848,  1849,  1850,  1851,
    1852,  1853,  1854,  1855,  1362,  1856,  1857,  1858,  1859,  1860,
    1861,  1862,  1779,   822,   523,   823,   595,   887,     0,   885,
       0,   322,   205,   206,     0,   271,   276,     0,     0,     0,
       0,   324,   327,     0,   209,     0,   923,   215,     0,   182,
       0,     0,     0,     0,   595,  1194,   595,     0,  1182,     0,
    1225,     0,   807,  1752,   583,   121,     0,   595,  1718,  1717,
     996,  1714,  1716,  1767,     0,  1232,     0,  1228,  1237,     7,
       0,     6,   595,  1760,  1058,  1059,   595,  1150,  1149,  1097,
    1148,  1096,   595,   595,   418,   420,     0,  1187,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   595,  1569,
       0,     0,     0,   412,   595,   595,     0,     0,   411,   595,
       0,   428,     0,   498,     0,     0,     0,     0,     0,   595,
       0,   407,  1290,     0,   378,   377,   384,   424,   421,   379,
     496,   488,   380,   382,   495,   383,   913,   419,   422,   427,
    1278,   497,  1693,  1284,   123,   595,  1062,   120,   595,   789,
      23,   585,   376,     0,   788,  1055,   790,     0,  1288,   876,
     875,   878,   874,   877,  1769,     0,   872,     0,   584,   969,
     873,  1763,     0,  1751,   119,   966,   691,   964,     0,   581,
    1746,   737,   736,     0,   738,   573,   734,     0,   595,   979,
     586,  1359,   595,   595,  1031,  1029,   595,  1023,  1025,  1024,
    1022,  1021,   595,   595,   595,  1020,   595,   764,   595,   595,
       0,     0,     0,     0,   595,   595,     0,     0,     0,  1010,
    1001,  1002,     0,  1043,   405,    23,   836,   397,  1757,     0,
    1748,   124,   582,   595,  1028,  1027,  1191,  1189,  1115,     0,
    1682,  1683,  1116,  1204,  1116,  1099,  1100,  1103,  1118,  1291,
     595,     0,     0,     0,     0,     0,   595,     0,   595,     0,
      61,     0,   913,     0,    67,     0,   100,   561,   649,   595,
    1088,   986,  1092,     0,   595,  1044,  1208,     0,  1095,   653,
     650,   651,     0,   655,   656,     0,   658,   659,   595,   654,
     946,   948,   595,   595,   947,   739,   944,   700,   940,   905,
       0,   595,   595,     0,   665,   666,     0,     0,   903,   899,
     900,   896,   897,   898,   891,   895,   894,   595,   595,   595,
     595,   595,     0,   527,   529,   521,   524,   525,   889,  1778,
     884,   886,   829,     0,   273,   275,   302,   296,     0,     0,
     305,     0,   220,     0,   218,   240,   232,   224,   243,   943,
     171,   939,   851,   171,     0,   595,     0,  1266,  1267,   595,
     595,   595,  1240,  1241,  1243,  1244,  1245,  1249,  1248,  1246,
    1247,     0,   596,   591,   595,  1715,   595,   595,   998,   595,
     595,  1231,  1230,   595,  1218,     0,  1545,  1546,     0,  1060,
       0,    23,  1145,  1147,  1146,   386,   385,   595,   595,  1122,
     463,   595,   595,   595,   595,     0,   595,     0,     0,   595,
     426,  1577,  1575,  1576,  1572,  1574,  1571,  1573,  1565,     0,
     595,     0,   595,     0,   425,     0,   595,   501,     0,     0,
     469,   466,   475,   595,   472,   595,   595,   410,   595,   595,
     595,   595,   595,   595,   595,   595,   595,   595,   595,   595,
     595,   595,   595,   595,   595,   163,   164,   165,   166,   167,
     168,   503,   504,   505,   439,   595,   595,   438,   444,     0,
     595,   390,   595,     0,   391,   381,   387,   389,   392,   393,
     394,   395,   396,   388,   417,   416,   460,   595,   956,     0,
       0,   345,    24,   339,   595,   595,  1052,   595,   595,   595,
     595,   595,   595,     0,   973,  1692,   595,   595,   182,     0,
     595,   595,  1748,   595,   595,   595,   595,   595,   136,     0,
     595,   983,   975,   976,   981,  1360,  1361,   902,   329,   403,
     595,   515,   566,   565,   563,  1004,   567,  1009,  1005,  1008,
     757,     0,  1006,  1007,   758,  1014,  1018,  1011,  1012,  1016,
    1017,  1015,  1013,  1019,     0,   791,   595,   595,     0,   400,
     401,   398,   399,   595,     0,     0,   747,   746,   745,  1749,
    1756,    23,  1111,  1112,  1113,  1114,  1108,  1106,  1205,  1120,
    1105,  1101,   595,     0,  1102,  1744,    79,   595,     0,   595,
     595,    96,     0,    97,   595,     0,   595,    72,   595,   595,
     109,   104,     0,   881,     0,   880,     0,   459,  1090,   595,
     931,   932,   955,   927,   928,   784,   953,  1046,  1210,   595,
    1212,  1211,   681,   595,   595,   595,   670,   700,   700,   698,
     595,   595,   701,     0,    25,   669,   672,     0,   679,   675,
     904,   893,  1689,  1690,  1680,  1680,     0,     0,  1603,   595,
     182,  1313,   595,   595,  1314,  1357,   182,   595,  1358,   595,
    1642,   595,  1327,     0,  1375,  1373,  1372,  1371,  1369,  1370,
    1368,  1366,  1363,  1434,  1433,  1364,  1365,  1374,  1612,  1367,
    1696,  1695,  1694,  1778,  1778,   540,   531,   522,     0,   526,
    1778,   888,   171,     0,   316,   208,     0,   182,   217,   200,
    1195,   171,  1183,  1425,   595,  1424,     0,     0,  1426,  1269,
       0,  1275,  1271,  1268,     0,     0,   595,     0,     0,     0,
    1265,  1261,  1416,  1415,  1414,  1236,  1235,   595,  1260,  1256,
     595,  1252,  1250,     0,   595,   590,     0,     0,   997,   595,
       0,   995,  1721,  1723,  1722,  1719,  1768,  1765,  1229,   595,
     595,   595,  1223,   459,   337,     0,  1188,    91,     0,     0,
       0,     0,  1642,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   413,     0,     0,     0,     0,
       0,   429,   595,   595,   595,     0,   595,     0,     0,     0,
     431,   430,   445,   440,   451,   454,   455,   452,   458,   457,
     456,   446,   447,   449,   448,   450,   441,   443,   459,   453,
     442,   459,    91,   423,   595,  1220,   988,  1056,  1057,  1054,
    1053,     0,   879,     0,     0,   570,     0,     0,   595,   967,
     965,     0,   693,   694,     0,     0,  1747,  1755,     0,     0,
     577,     0,   579,   735,     0,   140,   595,   977,   984,     0,
     595,   992,   595,   332,   595,   595,   595,   595,    23,  1030,
    1335,     0,     0,   781,   769,   779,   780,   767,   768,   775,
     771,   774,   770,   778,   773,   776,   777,   766,   772,   765,
     764,  1003,   792,   406,   595,  1035,   595,  1758,   748,   749,
     356,   595,  1116,   595,  1119,  1104,  1778,    91,     0,     0,
       0,     0,   595,     0,   595,    62,    91,     0,   115,   110,
       0,   105,   595,   112,   106,   865,   857,   863,     0,  1089,
     595,  1091,  1093,     0,   595,   935,     0,   595,     0,   595,
    1045,  1209,  1778,   652,   657,   660,   673,   671,   587,     0,
     595,   595,   716,   754,   714,   710,   708,   752,     0,     0,
     740,     0,   702,   712,   945,   941,   595,     0,     0,     0,
     678,   595,     0,   595,   595,     0,     0,   595,  1548,     0,
    1429,  1430,  1701,  1396,  1451,   595,     0,  1699,     0,     0,
    1644,  1645,  1643,   595,  1292,   595,  1379,  1385,  1384,  1383,
    1387,     0,  1380,  1381,   595,  1613,  1624,   528,   530,   595,
       0,   543,   535,   537,     0,   532,   533,   595,   595,   551,
     553,   595,     0,   549,   890,   830,   207,     0,     0,   219,
    1151,   852,  1129,  1404,  1406,     0,  1273,   595,     0,   595,
     595,     0,  1263,   595,   595,  1540,  1538,  1525,  1527,  1523,
       0,  1522,     0,  1531,  1518,  1539,     0,  1530,  1515,  1521,
    1537,  1529,  1420,  1512,  1513,  1514,     0,  1258,  1254,     0,
     595,  1242,   594,     0,   593,   595,   963,     0,   595,   595,
    1764,     4,     8,    10,  1544,  1547,   595,   459,   494,   464,
      92,    93,    95,   491,   490,   493,   489,   595,   415,   500,
     484,   484,     0,   486,   486,     0,  1187,     0,  1585,  1583,
    1584,  1580,  1582,  1579,  1581,  1570,   492,  1187,   499,   414,
       0,     0,   502,     0,  1187,   470,   467,   476,  1187,   473,
    1187,  1187,  1187,   595,     0,   595,     0,   461,     0,   595,
     595,   985,   595,   595,   595,   595,   595,     0,   595,   182,
     692,   595,   574,   576,   595,   595,   157,   155,   595,   595,
     137,     0,   147,   153,   700,   142,   144,   595,   982,   993,
     994,     0,   404,   331,   336,   572,   330,   595,   333,   338,
    1336,   516,   564,   562,   764,   759,   760,  1034,  1036,   595,
     402,   357,  1109,  1107,  1206,  1207,     0,    80,    65,  1200,
       0,     0,     0,    98,     0,     0,    73,    69,  1778,  1778,
     108,   103,   117,   113,     0,   107,   755,   866,   587,  1778,
     856,   855,   864,   987,   595,     0,   595,   954,   459,     0,
       0,  1663,  1556,  1559,  1664,  1567,  1557,  1661,   595,     0,
    1051,  1660,     0,   595,  1662,     0,     0,     0,     0,  1718,
    1558,  1047,  1048,  1659,  1564,  1050,  1652,  1724,  1653,   683,
     676,   674,     0,    23,   595,   730,   704,   732,   706,  1778,
    1778,  1778,  1778,   764,   725,   724,   720,   722,   729,   728,
     718,   726,   699,   703,  1778,   587,    45,    43,    40,    34,
      38,    42,    37,    30,    39,    33,    36,    31,    41,    32,
      44,    35,     0,    28,     0,   680,  1681,   595,   595,  1678,
    1629,  1630,  1622,  1608,  1623,     0,     0,   595,  1026,  1428,
    1431,   595,     0,   595,   595,  1452,  1347,  1319,  1704,  1703,
    1702,   595,   595,  1625,  1646,  1648,     0,  1342,   595,  1341,
     595,  1343,  1338,  1339,  1340,  1331,  1328,   595,   595,  1386,
     595,     0,     0,  1617,  1614,  1615,   542,   547,   595,   595,
    1778,  1778,   520,   534,   557,   545,   559,  1778,  1778,   555,
     539,   550,   821,   317,   201,     0,  1177,  1196,   821,     0,
    1184,  1177,   595,     0,  1270,     0,   595,     0,   595,     0,
    1457,  1459,  1461,  1507,  1506,  1505,  1504,  1463,     0,  1486,
    1272,  1549,     0,  1405,   595,  1408,     0,  1412,   595,  1262,
       0,     0,  1593,  1591,  1592,  1588,  1590,  1587,  1589,     0,
       0,     0,     0,     0,     0,     0,     0,  1418,     0,  1421,
    1422,   595,  1257,   595,  1251,  1253,   592,  1720,   595,     0,
    1766,   595,     0,  1233,   595,     0,     0,   595,     0,   481,
       0,   482,     0,   478,     0,   479,     0,  1125,  1578,     0,
    1124,     0,     0,     0,  1123,     0,     0,     0,  1126,     0,
    1128,  1127,  1121,   432,     0,   435,     0,   434,     0,     0,
       0,   595,     0,  1285,  1771,  1770,   571,   595,     0,    46,
     595,   697,   696,   695,  1286,   595,     0,   700,  1778,  1778,
     149,   597,   159,   151,   161,   141,   148,  1778,   595,     0,
     595,     0,   595,     0,   595,  1778,     0,   762,   587,   595,
    1745,     0,    91,   595,    63,   595,   595,   595,    76,     0,
      91,   116,   111,  1778,  1778,   101,   764,   867,   861,   869,
     868,   858,   512,   916,   933,   934,   929,   595,  1561,  1560,
    1563,  1562,  1566,     0,     0,   595,  1508,     0,  1508,  1508,
    1508,  1508,   595,   595,   595,   595,   595,   595,  1705,  1706,
    1707,  1708,  1709,  1710,  1655,   595,   686,   684,     0,   663,
     677,   588,   741,     0,   595,  1778,   595,  1778,   717,   715,
     711,   709,   753,     0,  1778,     0,  1778,   713,    23,     0,
      26,     0,  1684,  1642,  1612,   595,   595,  1621,  1604,  1620,
    1432,     0,  1398,     0,  1346,  1439,   595,     0,  1700,     0,
    1697,   595,  1638,   627,   612,   625,   631,   646,   611,   623,
     606,   639,   642,   645,   609,   640,   618,   622,   633,   644,
     641,   643,   634,   616,   614,   638,   620,   619,   607,   608,
     610,   613,   624,   636,   615,   648,   626,   630,   632,   647,
     621,   635,   637,   617,   628,   629,  1650,  1649,   595,  1345,
    1344,  1332,  1330,     0,  1389,     0,  1382,   595,   595,   595,
     595,   544,   541,   536,   538,   595,  1778,  1778,   552,   554,
    1778,  1778,     0,     0,  1175,  1176,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1174,     0,     0,
    1162,  1163,  1164,  1161,  1166,  1167,  1168,  1165,  1152,  1143,
     595,     0,  1199,     0,  1778,     0,  1138,     0,     0,     0,
       0,     0,     0,   595,  1130,  1131,     0,  1063,     0,  1274,
       0,  1466,   595,     0,  1486,  1465,  1462,   595,  1427,   595,
    1500,  1496,  1497,  1494,  1503,  1502,  1495,  1498,  1499,  1501,
     595,     0,  1487,     0,     0,   595,     0,  1552,     0,   595,
       0,   595,  1411,  1264,  1410,  1402,     0,     0,     0,  1542,
    1534,  1534,     0,     0,  1534,  1541,     0,  1556,  1417,  1419,
    1422,  1259,  1255,  1000,   595,     9,   595,  1226,   838,  1061,
     465,    94,   595,  1451,  1632,     0,   484,     0,   486,     0,
       0,   508,     0,   471,   468,   477,   474,   595,   437,   436,
     462,   343,  1221,     0,   595,  1762,     0,     0,   968,    47,
       0,   578,   580,   575,   750,   158,   156,   595,  1778,   595,
     595,   595,  1778,   154,   143,   595,   146,   145,   595,   974,
     978,   335,   595,   951,  1337,   949,     0,   764,   761,    23,
    1110,    86,  1201,    68,   595,     0,    99,    66,    91,    74,
       0,   118,   114,   756,  1778,   871,   587,   870,   595,   509,
     595,   786,   787,   785,     0,  1672,     0,     0,     0,  1510,
    1511,  1509,   595,   595,   595,   595,   595,   595,  1674,     0,
    1049,  1657,  1658,  1654,  1656,  1725,   595,  1778,   682,   667,
     664,     0,   731,   705,   733,   707,   723,   721,   727,   719,
     742,    29,    27,   595,  1679,   595,  1609,  1610,  1606,  1612,
     595,  1397,   595,  1400,     0,  1321,  1316,  1315,  1318,   595,
    1647,   595,  1626,     0,   595,  1293,  1299,     0,  1302,  1304,
    1333,  1329,   595,  1388,   595,     0,  1618,  1616,   548,   546,
     558,   560,   556,     0,     0,   224,  1169,  1170,  1171,  1173,
    1156,  1154,  1153,  1157,  1158,  1155,  1172,  1159,  1160,  1144,
     960,  1179,   957,   595,     0,  1197,     0,  1142,  1141,  1136,
    1134,  1133,  1137,  1135,  1139,  1140,  1132,  1185,  1407,  1642,
    1464,  1458,  1460,  1468,   595,  1481,   595,  1479,  1489,  1488,
     595,  1676,   595,  1473,  1472,  1474,     0,  1470,  1471,  1491,
    1490,     0,  1403,  1409,   595,  1413,  1600,  1598,  1599,  1595,
    1597,  1594,  1596,  1524,     0,  1526,     0,     0,     0,     0,
    1532,  1536,     0,  1516,  1423,   999,  1234,  1227,  1224,   595,
    1440,  1441,  1443,  1446,  1453,   595,     0,  1508,  1634,  1628,
     485,   483,   487,   480,  1586,   506,   507,   433,   595,    23,
       0,   595,   991,   595,    48,   971,     0,    23,   160,   150,
       0,   599,   601,   162,   152,   750,     0,   334,   595,   595,
     517,   763,  1032,   595,    81,     0,    64,     0,    77,    86,
      70,   862,   859,   513,  1778,     0,  1568,     0,     0,     0,
    1673,     0,   595,     0,     0,     0,     0,   595,  1670,     0,
     685,   662,   668,   587,  1688,     0,  1686,  1638,  1612,  1612,
    1605,  1399,  1642,  1401,  1395,   595,  1320,     0,  1698,  1639,
       0,   595,  1306,     0,  1295,   595,   595,   595,  1390,  1393,
    1377,  1391,  1394,   595,   832,   831,   318,   202,   962,   961,
     959,   595,  1178,  1064,  1068,  1070,   595,  1074,   595,  1072,
    1076,  1065,  1066,     0,   853,     0,   595,     0,  1482,  1485,
    1484,     0,     0,     0,  1677,  1476,  1467,     0,  1550,  1554,
    1549,     0,  1543,  1535,  1519,  1517,     0,  1520,   595,  1444,
     595,  1555,  1447,   595,  1454,  1455,  1637,  1226,   595,   595,
     595,   344,   341,   595,   989,     0,     0,     0,   970,   751,
     138,   598,    23,   980,   952,   950,  1037,    87,  1202,    82,
       0,    75,    86,  1778,   510,   930,     0,     0,     0,  1669,
       0,  1665,  1666,  1667,  1668,  1675,   687,   743,   595,  1685,
       0,  1611,  1607,   595,  1322,   595,  1632,   595,  1311,  1301,
    1308,  1310,  1312,   595,     0,   595,   595,  1294,  1303,  1305,
    1334,   595,  1378,  1376,  1619,   958,  1778,  1778,  1078,  1778,
    1080,  1778,  1778,  1067,  1198,  1186,     0,   595,  1480,  1478,
     595,  1676,  1493,     0,  1553,     0,  1533,  1448,     0,  1442,
    1436,  1437,  1651,   595,  1456,  1450,  1635,  1352,  1348,  1349,
    1354,  1353,  1633,  1226,   346,   990,  1761,   595,   595,   595,
     595,   595,   595,    53,     0,    52,     0,    50,   595,   595,
     139,  1041,  1033,     0,  1039,    86,    91,    86,    71,   860,
       0,     0,  1713,     0,  1671,  1778,    23,  1687,  1632,     0,
    1326,     0,  1323,  1325,  1627,     0,  1312,   595,  1307,     0,
    1296,  1297,  1392,  1069,  1071,  1778,  1075,  1778,  1073,  1077,
       0,  1483,  1492,  1475,  1477,  1551,  1528,   595,  1445,   595,
    1435,   595,  1356,  1355,  1351,  1636,   352,   350,   342,     0,
     348,   354,    55,    60,    57,    59,    56,    58,    54,     0,
      49,     0,   600,   602,  1778,  1038,  1040,  1203,    83,    78,
     511,  1711,  1712,   683,   744,  1631,  1640,   595,  1317,  1300,
    1309,   595,  1079,  1081,  1641,  1449,  1438,  1350,  1778,  1778,
     347,   349,  1778,    51,   595,  1042,     0,   688,  1324,     0,
     353,   351,   355,     0,    84,  1298,   972,    88,    90,   595,
      85,    89
};

/* YYDEFGOTO[NTERM-NUM]. */
static const short yydefgoto[] =
{
      -1,   548,   549,   550,   551,   700,  1701,  1702,   188,   264,
     189,  1121,  1122,  1587,  1922,  2945,  2448,  2449,  2836,  2946,
    2947,   552,   890,  2484,  2150,  2852,  1536,  2149,  2719,  2488,
    2850,  1527,  2141,  2956,  3056,  3067,  2714,  3070,  1709,  1710,
    1711,  1222,  1822,   553,  1232,   895,  1230,  1543,  1831,  1540,
    1829,  1834,  2154,  1231,  1828,  1544,  2153,   554,    16,    35,
      36,    37,    38,    39,   113,   557,   818,  1475,  1148,  1780,
    1784,  1785,  1781,  1782,  2458,  2462,  2127,  2119,  2118,  2120,
    2123,  1104,   558,    83,    84,    18,    60,   142,    96,   255,
      98,    99,   200,   277,   100,   101,   242,   228,   672,  2313,
     304,   654,  1647,   331,   332,   229,   286,   279,   281,   973,
     974,   146,   354,   147,   148,   292,   230,   231,  1461,   392,
     243,   246,   244,   245,   313,   369,   370,   372,   377,   657,
     247,   248,   322,   374,   196,    19,    80,   177,   178,   179,
     663,  2312,   180,   251,   240,   325,   326,   327,   328,  1488,
     559,   560,   561,   562,   775,  2934,  2689,  1123,  3008,  3009,
    3010,  3049,  3048,  3052,   563,   564,   565,   566,   751,  1105,
     856,  1190,  1191,  1158,   853,  1159,   753,   754,   755,   756,
     757,   758,   759,  1059,  1106,  2094,  1107,  1108,  1109,  1110,
    1111,  1112,  1113,   706,   760,  1442,  2098,  1387,  2066,   761,
    1413,  2086,  1412,  2085,  1416,  2089,  1414,  2087,  2069,  2073,
     762,   763,   764,   765,  1408,   567,  2724,  2960,  2499,   568,
     826,  1490,  2135,   114,   237,   364,  1316,   955,   956,   957,
    1313,  1314,  1634,  1635,  1636,  1980,  1981,  1317,  1318,  1630,
    1984,  1976,  1642,  1643,  1987,  1988,  2310,  2306,  2307,   569,
    1165,    85,  1456,  1457,  1796,   858,   808,   861,   683,   797,
     780,   819,  1883,    86,   684,  1002,  1693,    41,   127,  2122,
      87,   767,  2286,   570,   571,   910,   911,   572,   573,   574,
     575,   918,  2529,   939,  2741,   940,  1566,   941,  1880,   942,
    2199,   943,  1590,   576,  1562,  2198,  2527,  2526,  2965,   115,
      20,   577,  1139,  1462,  1463,  1580,  1263,  1581,  1582,  2205,
    2207,  1892,  1891,  1904,  1890,  1889,  2216,  2214,  1896,  1897,
    1900,  1901,  1886,  1888,   578,   579,   816,   580,  1259,   925,
    2966,   581,  1198,  2697,  1583,  1893,  1837,  2156,   849,  1175,
    1510,  1805,  2136,  1806,  1171,  1509,   582,   583,   904,  1558,
    2503,   584,   585,   586,   587,    21,    64,    22,    23,    24,
     116,   117,   588,   118,    25,   644,    26,   119,   120,   157,
     366,  1322,  1992,  2775,   121,   153,   297,   589,  2065,    27,
      28,    29,    30,    31,    59,    88,   122,   411,  1331,  1998,
     590,   899,  1841,  1547,  1839,  2853,  2494,  1548,  1838,  2159,
    2496,   591,   592,   593,   791,   792,  1234,   123,   238,   365,
     648,   649,   959,  1320,   594,   944,   945,   595,   822,  1271,
     946,   768,    90,    91,    92,    93,  1241,   183,   138,    94,
     135,   191,   192,  1242,  1243,  2166,  1244,   408,   409,   927,
     410,   928,  2474,  2475,  1245,  1246,  1119,  2601,  2602,  2780,
     689,   806,   807,   596,  1134,  2838,   597,  2470,   598,  1152,
    1153,  1154,  1481,  1479,   599,   600,  1761,  1791,   601,  1008,
    1371,   602,   850,   851,   603,   866,   604,  1932,   605,  2846,
     606,  1809,  2952,  2953,  2954,  3024,   855,   607,  1247,  1560,
    1871,  1872,   608,  1449,   705,  1020,   609,   610,  2000,  2605,
    2791,  2792,  2896,  2897,  2901,  2899,  2902,  2985,  2987,   611,
     612,  1236,  1552,   613,  1238,   874,   875,   876,  1214,   614,
     615,   616,  1522,  1206,   869,   199,   877,   878,   769,  2001,
    2354,  2355,  2338,   709,   710,  1996,  2339,  2342,   124,   152,
     358,   983,  1652,  2356,  2795,  1029,   617,   867,   125,   149,
     355,   980,  1650,  2343,  2793,  1997,   894,  2142,  2715,  2955,
    1209,   618,   619,   620,   621,   622,   778,  1759,   702,  1706,
    2668,   696,   697,  2062,  1350,   623,   624,   625,   992,   993,
     994,  1362,  1689,   995,  1686,  1359,   996,  1661,  1351,   997,
     998,   999,  1000,  1655,  1342,   626,   787,   770,   627,  1294,
    1956,  2764,  2887,  2565,  2566,  2567,  2568,  2763,  2879,  2880,
    1295,  1296,  1605,  2557,  2757,  2237,  2554,  2971,  2972,  1297,
    1615,  2291,  1966,  2571,  2767,  1801,  2134,  1967,  1298,  1299,
    2678,  2928,  2929,  2930,  3004,  1300,  1301,  1156,   628,   629,
     952,  1302,  1303,  2893,  1621,  1622,  1623,  1969,  2293,  2770,
    2771,  1304,  1942,  2231,  2754,  1352,  1353,  1338,  2022,  1653,
    2023,  1354,  2026,  1355,  2049,  1356,  2050,  2409,  1656,  1305,
    1599,  1600,  1939,  1306,  2924,  2824,  2920,  1945,  2423,  2670,
    2671,  2672,  2918,  2424,  1946,  2825,  2925,  2009,  2010,  2011,
    2012,  2013,  2014,  2636,  2637,  2638,  2912,  2803,  2993,  2015,
    2797,  2798,  2384,  2016,  2385,  2017,  2512,  1682,  1683,  1684,
    2657,  1685,  2406,  2400,  2813,  2024,  2772,  2387,  2569,  2822,
    1873,   771,  1874,  2172,  1048,  2070,  1735,  2039,  2653,    58,
     630,   631,  2549,  2749,  2224,  2748,  1626,  1974,  1975,  2228,
    1933,  1307,  1934,  2242,  2760,  1393,  1929,  1930,  2679,  2827,
    2562,  2553,  2018,  1613,  1953,  1954,  2921,  2019,  1876,  2519,
    2805,   632,   633,  1592,  1931,  2544,  2745,  2746,  1274,   634,
     773,  1309,  1310,  1608,  2239,  1311,  1312,  1950,  2194,  2508,
     690,  1877,   692,  1375,  1878,    62,    47,    78,    75,   636,
     880,  1526,  1142,  1200,   637,   859,   638,  2109,   639,  1700,
     694,  1377,   640,   641,    73,   359,   360,   361,   362,   363,
     642
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -2590
static const short yypact[] =
{
    1990,   995, -2590,   509,   509,   509,   509,   509,   509,   509,
   -2590,   509, -2590,   315, -2590, -2590, -2590,  1419, -2590, -2590,
   -2590,   354, -2590,  1990, -2590, -2590, -2590, -2590, -2590,  1689,
   -2590, -2590, -2590, -2590, -2590,   339,   329, -2590,   345, -2590,
   -2590,   380, -2590, -2590,  -144, -2590,   -99, -2590, -2590, -2590,
   -2590, -2590, -2590, -2590, -2590, -2590, -2590, -2590, -2590,   387,
     208, -2590, -2590, -2590,   232, -2590, -2590, -2590, -2590, -2590,
   -2590, -2590, -2590, -2590, -2590, -2590, -2590, -2590, -2590,  -144,
     244, -2590, -2590,   553,  1419, -2590,   616, -2590, -2590, -2590,
   -2590,   784,   248, -2590, -2590, -2590,   801,   519, -2590, -2590,
   -2590,   859, -2590, -2590, -2590, -2590, -2590, -2590, -2590, -2590,
   -2590, -2590, -2590, -2590, -2590, -2590, -2590,   232, -2590, -2590,
   -2590, -2590, -2590, -2590, -2590, -2590, -2590, -2590, -2590, -2590,
    2121,   248, -2590,    69,    73, -2590, -2590,   446, -2590,   280,
     883,   208,   420, -2590, -2590, -2590, -2590, -2590,  7936, -2590,
     490,   812, -2590,  1419, -2590, -2590, -2590, -2590, -2590, -2590,
     413,   890, -2590, -2590,   523, -2590,   534, -2590,   517, -2590,
   -2590,   552, -2590,   555, -2590, -2590, -2590, -2590, -2590, -2590,
   -2590, -2590, -2590,   536, -2590, -2590, -2590,    73,  1372,   942,
   -2590,   183, -2590,    73, -2590, -2590,   157, -2590, -2590, -2590,
     136, -2590, -2590, -2590, -2590, -2590, -2590, -2590, -2590,   413,
   -2590,   890, -2590, -2590,   562, -2590,   575, -2590,   557, -2590,
   -2590,   583, -2590,   587, -2590, -2590, -2590, -2590, -2590, -2590,
   -2590, -2590,   609,  1019, -2590,   646, -2590,  1419,  1419,   648,
   -2590, -2590,   -94, -2590,   441,  1357, -2590,   457,  1680,  1034,
    1067, -2590,  1079,  1087,  1092, -2590,   485, -2590,   545, -2590,
   -2590, -2590, -2590, -2590,    73, -2590,    73,   686,   191, -2590,
   -2590, -2590,  1094, -2590,  1108, -2590, -2590, -2590, -2590, -2590,
     -94, -2590, -2590, -2590,  1111,  1113,   208,  1079,  1134,  1136,
     551, -2590,  1126, -2590,   795,   775, -2590,   833, -2590, -2590,
   -2590,   590, -2590, -2590,  1177, -2590,   799, -2590, -2590, -2590,
   -2590, -2590, -2590, -2590,  1680,   799, -2590, -2590, -2590, -2590,
   -2590, -2590,   802,   198,   235,   255, -2590,  4137, -2590, -2590,
   -2590,   811,  1220,   237,   864, -2590, -2590,  1372, -2590,    73,
   -2590, -2590, -2590,   639,  1217,  1013,   241,   261,   264,   871,
     281,   899, -2590, -2590, -2590,   921, -2590, -2590,   921,   948,
   -2590,  3835,   420,  4764,  1912,  -302,   921,  1273,   -52, -2590,
    1357,  1276, -2590, -2590, -2590, -2590,  1277, -2590,  1279, -2590,
    1282, -2590, -2590, -2590, -2590, -2590, -2590,  1079,  1283, -2590,
   -2590, -2590, -2590,   201,  1278,   -52,   903,  1290, -2590,  1291,
   -2590, -2590, -2590,  1294, -2590, -2590, -2590,   722,   959,  1328,
   -2590,   921,   966, -2590, -2590, -2590, -2590, -2590, -2590, -2590,
   -2590,    82, -2590, -2590, -2590, -2590, -2590, -2590, -2590,    72,
   -2590, -2590, -2590, -2590, -2590, -2590, -2590, -2590, -2590, -2590,
   -2590, -2590, -2590,   108,   108,  6471, -2590, -2590, -2590, -2590,
   -2590, -2590, -2590, -2590, -2590, -2590, -2590, -2590, -2590, -2590,
   -2590, -2590, -2590,   749, -2590, -2590, -2590,  6471, -2590,   749,
   -2590,   749,   904, -2590, -2590,    64, -2590, -2590,    64, -2590,
   -2590,    64, -2590, -2590, -2590, -2590, -2590, -2590, -2590, -2590,
   -2590,   749, -2590, -2590, -2590, -2590,   -56, -2590, -2590, -2590,
   -2590, -2590, -2590,    82, -2590, -2590, -2590, -2590, -2590,  1467,
     749,  7487, -2590,   697,   697, -2590, -2590, -2590,   118,   749,
      93,  6471,  7487, -2590,   912,  6471, -2590,  -144, -2590,  7487,
   -2590,  7487,   749, -2590, -2590,  7487,  7487,   108, -2590, -2590,
   -2590,   697, -2590, -2590,   697, -2590, -2590,   220, -2590, -2590,
   -2590, -2590, -2590, -2590, -2590, -2590, -2590, -2590, -2590, -2590,
   -2590, -2590, -2590, -2590, -2590, -2590, -2590, -2590, -2590, -2590,
   -2590, -2590, -2590, -2590, -2590, -2590, -2590, -2590, -2590, -2590,
   -2590, -2590, -2590, -2590, -2590, -2590, -2590, -2590, -2590, -2590,
   -2590, -2590, -2590, -2590, -2590,    95, -2590, -2590, -2590, -2590,
   -2590, -2590, -2590, -2590, -2590, -2590, -2590, -2590, -2590, -2590,
   -2590, -2590, -2590, -2590, -2590, -2590, -2590, -2590, -2590, -2590,
   -2590, -2590, -2590, -2590, -2590, -2590, -2590, -2590, -2590, -2590,
   -2590, -2590, -2590, -2590,   918, -2590, -2590, -2590, -2590, -2590,
   -2590, -2590, -2590, -2590,   535, -2590, -2590, -2590,   531, -2590,
     978, -2590, -2590, -2590,  1071, -2590, -2590,   992,   993,   994,
     996, -2590, -2590,   765,  1362,  1000, -2590, -2590,  1090, -2590,
    1004,  1005,   778,  1016, -2590, -2590, -2590,  1028, -2590,   365,
   -2590,   196, -2590, -2590, -2590, -2590,   804,  1381,   970, -2590,
     813, -2590,   809, -2590,  1405,  -223,   287, -2590, -2590, -2590,
    1010, -2590,  1392, -2590, -2590,   961,    62, -2590, -2590, -2590,
     861, -2590,  7487,  7487, -2590, -2590,  1008,   916,  1014,  1017,
    1022,  1042,  1044,  1045,  1046,  1049,  1051,  1052,  7487,  1867,
    1054,  1055,  1058, -2590,  7487,  7487,  1060,  1062, -2590,  7487,
    1064, -2590,  1068,  1069,  1070,  1082,  1083,  1084,  1097,  7487,
    1098,  5739, -2590,   152, -2590, -2590, -2590, -2590, -2590, -2590,
   -2590, -2590, -2590, -2590, -2590, -2590,   515, -2590,  1023, -2590,
   -2590, -2590, -2590, -2590, -2590,   749, -2590, -2590,  1392, -2590,
      25, -2590, -2590,  1180, -2590,   149, -2590,  1030, -2590, -2590,
   -2590, -2590,  1491, -2590, -2590,  -203, -2590,   913, -2590,   914,
    1491, -2590,   938, -2590, -2590,  1116,   111, -2590,  1080, -2590,
     884, -2590, -2590,  1118, -2590,  -137, -2590,   888,   -83,  -187,
   -2590,  1224,  7487,  7487, -2590,  1523, -2590, -2590, -2590, -2590,
   -2590, -2590,    80,    80,    80, -2590,    80, -2590,    80,    80,
     960,    25,   960,   960,   106,   106,   960,   960,    25, -2590,
    1536, -2590,   -17,  1537, -2590,    25, -2590,  6336, -2590,    71,
      65, -2590, -2590,  7487, -2590, -2590, -2590, -2590, -2590,   894,
   -2590, -2590,   420,  1182,   420,  6471, -2590,    79, -2590, -2590,
    7487,  1138,  1140,  1144,  1147,  1153,  1530,  1156,    93,  1069,
   -2590,  1236,   715,   999, -2590,  1015, -2590, -2590, -2590,   122,
   -2590,  1562, -2590,  1563, -2590, -2590,    26,  1021, -2590, -2590,
    1573, -2590,   943,  1573,  1575,   947,  1573,  1575,  7487,  1573,
   -2590, -2590,    62,   749, -2590, -2590,  1183,   274, -2590, -2590,
    1181,   749,  7487,  1186, -2590, -2590,  1564,  1566,  1542, -2590,
   -2590, -2590, -2590, -2590, -2590, -2590, -2590,   125,   125, -2590,
   -2590, -2590,  1059, -2590, -2590,  1528,   535, -2590, -2590,   549,
   -2590, -2590, -2590,  1164, -2590, -2590, -2590, -2590,  2121,  1079,
   -2590,  1167, -2590,   300, -2590, -2590, -2590, -2590, -2590, -2590,
    1419, -2590, -2590,  1419,   642,  1196,  1581, -2590, -2590,   723,
    1198,   925,  1603, -2590, -2590, -2590, -2590, -2590, -2590, -2590,
   -2590,  1209, -2590, -2590,  1381,   809,    73,    82,  -251,  1599,
   -2590, -2590, -2590, -2590, -2590,  1063,  1027,  1061,  1211, -2590,
    1219,   107, -2590, -2590, -2590,  2930,  2930,   697,  7487, -2590,
   -2590,   697,   697,   697,   697,  1190,  7487,  1145,  1168,  7487,
    5739,  1222, -2590, -2590, -2590, -2590, -2590, -2590, -2590,  1037,
     697,  1612,  7487,  2337,  5739,  1190,  -124,  5739,  1613,   528,
   -2590, -2590, -2590,  7487, -2590,  7487,  7487,  5739,  7487,  7487,
    7487,  7487,  7487,  7487,  7487,  7487,  7487,  7487,  7487,  7487,
    7487,  7487,  7487,  7487,  7487, -2590, -2590, -2590, -2590, -2590,
   -2590, -2590, -2590, -2590, -2590,  7487,  7487, -2590, -2590,  1234,
    7487, -2590,  7487,  1235, -2590, -2590, -2590, -2590, -2590, -2590,
   -2590, -2590, -2590, -2590, -2590, -2590, -2590,   749, -2590,  1041,
    1241, -2590, -2590, -2590,    82,   138, -2590,   138,    93,    64,
    7487,  7487,  7487,  1243, -2590, -2590,   749,   749, -2590,  1048,
      93,   697,  1006, -2590,    73,    55,   -56,   749, -2590,  1050,
    7487,  1327, -2590, -2590,  1124, -2590, -2590,  1537,    90, -2590,
      62, -2590, -2590,  1646,  1647, -2590, -2590, -2590, -2590, -2590,
   -2590,   481, -2590, -2590, -2590, -2590, -2590, -2590, -2590, -2590,
   -2590, -2590, -2590, -2590,  1467, -2590,   106,  7487,  -128, -2590,
   -2590,  1659, -2590,   697,  1641,  1654, -2590, -2590, -2590, -2590,
   -2590,   206, -2590, -2590, -2590, -2590,  1549, -2590,  1484, -2590,
   -2590, -2590,  7487,   108, -2590, -2590, -2590, -2590,  1658,   697,
     697, -2590,  1128, -2590,   697,  1099,   749, -2590, -2590,  7487,
     -93, -2590,  1129, -2590,   268, -2590,  1242, -2590,  1245,  7487,
     783, -2590, -2590,   248, -2590,  1694, -2590,  1184, -2590,   749,
   -2590, -2590, -2590, -2590,   697,   697,   199,   274,  1579,  1178,
     749,    62, -2590,  1185, -2590, -2590,  1706,  1687,  1338, -2590,
   -2590, -2590, -2590, -2590,  1417,  1417,   161,  1194, -2590, -2590,
   -2590, -2590,  1392,  1392, -2590, -2590, -2590, -2590, -2590, -2590,
     463,  1392, -2590,   668, -2590, -2590, -2590, -2590, -2590, -2590,
   -2590, -2590, -2590, -2590, -2590, -2590, -2590, -2590,   963, -2590,
   -2590, -2590, -2590,   167,   167,   117,   633, -2590,   342, -2590,
     549, -2590,  1419,  1695, -2590, -2590,  1695, -2590, -2590, -2590,
   -2590,  1419, -2590, -2590,  1392, -2590,   630,  1312, -2590, -2590,
     630, -2590, -2590, -2590,  1313,  1319,   676,  1320,  1323,  3351,
   -2590, -2590, -2590, -2590, -2590, -2590, -2590, -2590, -2590, -2590,
     676,  1093, -2590,   365,  1711, -2590,  1139,   224, -2590,    93,
    1187, -2590, -2590,   970, -2590, -2590, -2590,  1215, -2590, -2590,
   -2590, -2590, -2590, -2590, -2590,  1371,  5739,  6471,  1380,  1384,
    1385,   323,   463,  1386,  3169,  1389,   -98,  1390,   -85,  5112,
    1740,  1930,  1397,  1400,  5207, -2590,  1401,   422,  1404,  1773,
    1409, -2590,  7487,  7487,  7487,  5480,  7487,  5577,  5609,  5710,
    5978,  6111,  6141,  6221,  3129,  4061,  6242,  2246,  6262,  1596,
    2938,  2930,  2930,  3864,  1125,  3259,  5739,  5739,  1190,  5739,
    5739,  1190,  6471, -2590, -2590, -2590,  1191, -2590, -2590, -2590,
   -2590,  1175, -2590,  1777,  1783, -2590,  1787,  1239,  7487, -2590,
   -2590,  1200,  1795, -2590,  1339,  1197,  1575, -2590,  1433,   432,
   -2590,  1395, -2590, -2590,  1214,   764, -2590, -2590, -2590,  1410,
   -2590,   629,  7487, -2590, -2590, -2590,  7487,  -225,    25,  1817,
    1293,  1798,  1801, -2590, -2590, -2590, -2590, -2590, -2590, -2590,
   -2590, -2590, -2590, -2590, -2590, -2590, -2590, -2590, -2590, -2590,
    1420, -2590, -2590, -2590,   749,  1314,  6736, -2590, -2590, -2590,
    1785,  7487,   420,   100, -2590, -2590,  1527,  6471,  1466,  1827,
    1469,   324, -2590,  1473,    93, -2590,  6471,  1428, -2590, -2590,
    1506, -2590,  7487,   -36, -2590,  1272, -2590, -2590,   773, -2590,
    7487, -2590, -2590,  1246,    69, -2590,  1249, -2590,  1837,  7435,
   -2590, -2590,   116, -2590,  1575,  1575,  1213, -2590,  1324,  1332,
     697,   697, -2590, -2590, -2590, -2590, -2590, -2590,  -107,   -97,
   -2590,   987, -2590, -2590, -2590, -2590,   697,  1299,  1854,  1835,
   -2590,    93,  1634,    68,  1412,  1791,    66,   169, -2590,   246,
   -2590, -2590, -2590,  1464,    70,  1392,   142, -2590,  1275,  1281,
   -2590, -2590, -2590,  7894, -2590,  1378, -2590, -2590, -2590, -2590,
    1471,  1286,  1882, -2590,  1868, -2590, -2590, -2590, -2590,   749,
     131, -2590, -2590, -2590,  1284,   633, -2590, -2590, -2590, -2590,
   -2590, -2590,   660, -2590, -2590, -2590, -2590,  1486,  1489, -2590,
    1457, -2590,  1460, -2590,  1492,   335, -2590,  6053,   358,  1392,
    1392,   385, -2590,  1392,  6053, -2590, -2590,  2060,  2060, -2590,
    1495, -2590,  1499,  1503, -2590,  1505,  1510, -2590,  1511, -2590,
   -2590, -2590,    88, -2590, -2590, -2590,   392, -2590, -2590,   399,
   -2590, -2590, -2590,  1545,   248,  1599, -2590,  1916,    93,  7487,
   -2590,  1922, -2590, -2590, -2590, -2590,   676, -2590, -2590, -2590,
    1924, -2590,  5739, -2590, -2590, -2590, -2590,  7894, -2590, -2590,
    1867,  1867,  1896,  1867,  1867,  1915,   916,  1568,  1535, -2590,
   -2590, -2590, -2590, -2590, -2590, -2590, -2590,   916, -2590, -2590,
    1867,  1340, -2590,  1867,   916,  5739,  5739,  5739,   916,  5739,
     916,   916,   916,  7487,  1578,  7487,  1583, -2590,  1355,   676,
      59, -2590,    93,  7487,  7487,  7487,  6947,  1952,   821, -2590,
   -2590,    93, -2590,  1360, -2590, -2590, -2590, -2590, -2590, -2590,
   -2590,  1150, -2590, -2590,   276, -2590,  1363,  7487, -2590, -2590,
   -2590,  1956, -2590, -2590, -2590, -2590, -2590, -2590,  1575, -2590,
   -2590, -2590, -2590, -2590, -2590, -2590, -2590, -2590, -2590,   749,
   -2590, -2590,  5077, -2590, -2590, -2590,  1663, -2590, -2590, -2590,
    1648,  1651,  1533,  1376,  1655,  1580, -2590, -2590,   -20,  1643,
   -2590, -2590, -2590, -2590,  1506, -2590, -2590, -2590,   140,   785,
   -2590, -2590, -2590,  1706,  7487,  1587,  1973, -2590, -2590,   160,
     164, -2590,   804, -2590, -2590,  2060, -2590, -2590,  7894,  1589,
   -2590, -2590,  1592, -2590, -2590,  1593,  1600,  1606,  1609,  -102,
   -2590,  2006, -2590, -2590, -2590,  2429, -2590,  1621, -2590,   128,
    1382, -2590,  1997,    25, -2590, -2590,  2027, -2590,  2028,  1057,
    1057,  1057,  1057,  1420, -2590, -2590,  2029, -2590, -2590, -2590,
    2031, -2590, -2590, -2590,  1057,   123, -2590, -2590, -2590, -2590,
   -2590, -2590, -2590, -2590, -2590, -2590, -2590, -2590, -2590, -2590,
   -2590, -2590,   403, -2590,  2015, -2590, -2590,  1392, -2590, -2590,
   -2590, -2590, -2590, -2590, -2590,  1474,  1479,   554, -2590,   246,
   -2590,  1392,  1445, -2590,  6053, -2590, -2590,  1636, -2590, -2590,
   -2590, -2590, -2590,  2038, -2590,  4258,  1493, -2590,  7487, -2590,
    7487, -2590, -2590, -2590, -2590, -2590, -2590, -2590,  1392, -2590,
    1392,   944,  1455,  1459,  2056, -2590,  2061, -2590,   749, -2590,
     561,   561, -2590, -2590,  2062, -2590,  2062,   714,   714,  2062,
   -2590, -2590,  1912, -2590, -2590,  2498,    99, -2590,  1912,  2237,
   -2590,    99,  1392,   630, -2590,  1660,  6003,  1660,  4192,   178,
    2064, -2590, -2590, -2590, -2590, -2590, -2590, -2590,   372,   607,
   -2590,   402,  1698,  2065, -2590, -2590,   407, -2590,   676, -2590,
     421,   207, -2590, -2590, -2590, -2590, -2590, -2590, -2590,  1472,
    -136,  2047,  2047,  2049,  2047,  2047,  2051, -2590,   210, -2590,
     630, -2590, -2590,   676, -2590, -2590, -2590,  1480,    93,  2070,
   -2590, -2590,   427, -2590,  7076,  1710,  1717,  7487,   192, -2590,
    1483, -2590,  1723, -2590,  1502, -2590,  1726, -2590, -2590,  2072,
   -2590,  1504,  1930,  1513, -2590,  1728,  1749,  1750, -2590,  1751,
   -2590, -2590, -2590,  5739,   429, -2590,   435, -2590,  1753,  2090,
     440,    93,  2120, -2590, -2590, -2590, -2590,  7487,  1582,  1880,
    7487, -2590, -2590, -2590, -2590,  2116,  1768,   276,  1287,  1287,
    2134,   -43, -2590,  2136, -2590, -2590, -2590,  1287, -2590,  1617,
    2123,  2140, -2590,    30,   749,  1927,   442, -2590,  1324,  7487,
   -2590,  1794,  6471,   749, -2590,    72, -2590,   749, -2590,  1804,
    6471, -2590, -2590,   -20,  1643, -2590,  1420, -2590, -2590,   166,
   -2590, -2590,  1597, -2590, -2590,  1724, -2590,  7216, -2590, -2590,
   -2590, -2590, -2590,  1570,  1426,   154,   476,  1767,   476,   476,
     476,   476,  7894,  7435,  7894,  7894,  7894,  7894, -2590, -2590,
   -2590, -2590, -2590, -2590, -2590,    82, -2590, -2590,  1759,   637,
   -2590, -2590, -2590,  1588,   697,  1057,   697,  1057, -2590, -2590,
   -2590, -2590, -2590,  -107,  1057,   -97,  1057, -2590,    25,  1299,
   -2590,  1816,  1779,   463,   963,  1412,  1412, -2590, -2590, -2590,
   -2590,   443, -2590,  1739, -2590,  2184,  1392,   366, -2590,  1586,
   -2590,  7894,  1662, -2590, -2590, -2590, -2590, -2590, -2590, -2590,
   -2590, -2590, -2590, -2590, -2590, -2590, -2590, -2590, -2590, -2590,
   -2590, -2590, -2590, -2590, -2590, -2590, -2590, -2590, -2590, -2590,
   -2590, -2590, -2590, -2590, -2590, -2590, -2590, -2590, -2590, -2590,
   -2590, -2590, -2590, -2590, -2590, -2590, -2590, -2590,   200, -2590,
   -2590,  1664, -2590,   453, -2590,  1595, -2590, -2590, -2590,  1868,
     749, -2590,  2062, -2590, -2590, -2590,   714,   714, -2590, -2590,
     714,  2008,  1598,  1605, -2590, -2590,   108,   108,   108,  2179,
     108,   108,   108,   108,   108,   108,  2185, -2590,  2186,   108,
   -2590, -2590, -2590, -2590, -2590, -2590, -2590, -2590,  2498, -2590,
     749,  1616, -2590,  1790,  2008,  2192, -2590,  2194,  2197,  2198,
    2199,  2201,  2202,   170,  2237, -2590,  1790, -2590,   456, -2590,
    1781, -2590, -2590,   230,   816, -2590, -2590,  6053, -2590,  6053,
   -2590, -2590, -2590, -2590, -2590, -2590, -2590, -2590, -2590, -2590,
    7894,  1823, -2590,  1824,   556,  7166,  2216, -2590,  1967,  1392,
    1644,  1392, -2590, -2590, -2590, -2590,  2148,  2219,  2148, -2590,
    2241,  2241,   472,  1878,  2241, -2590,  1881, -2590, -2590, -2590,
     630, -2590, -2590, -2590,    93, -2590,   676,  2003,  1706, -2590,
   -2590, -2590,    76,  1752,   634,  1930,  1867,  1930,  1867,  1884,
    1930, -2590,  1930, -2590, -2590, -2590, -2590,  7487, -2590, -2590,
   -2590,  1808, -2590,   242,    93, -2590,  2253,  1860, -2590, -2590,
    1898, -2590, -2590, -2590,  1741, -2590, -2590, -2590,  1287,    73,
    2251, -2590,  1287, -2590, -2590,   697, -2590, -2590,  7487, -2590,
   -2590, -2590,   697,  1873,  2269, -2590,  2057, -2590, -2590,    25,
    5739,  1954, -2590, -2590,    62,  1874, -2590, -2590,  6471, -2590,
    1908, -2590, -2590, -2590,   785, -2590,  1324, -2590,  7487, -2590,
      73, -2590,  1537, -2590,  2148, -2590,   437,  2275,  1911, -2590,
   -2590, -2590,  7894, -2590,  7894,  7894,  7894,  7894,  2429,   480,
   -2590,  2095,  2095,  1252,  1602, -2590,  7487,  1864, -2590,  1961,
   -2590,  2265, -2590, -2590, -2590, -2590, -2590, -2590, -2590, -2590,
   -2590, -2590, -2590, -2590, -2590,  7894, -2590, -2590, -2590,   963,
    1392, -2590, -2590,  2169,   482, -2590, -2590, -2590, -2590, -2590,
   -2590,   749, -2590,  2285,  1392, -2590,  2283,  2287, -2590, -2590,
   -2590, -2590,  1392, -2590,  1861,  1705, -2590, -2590, -2590, -2590,
   -2590, -2590, -2590,  2117,  2121, -2590, -2590, -2590, -2590, -2590,
   -2590, -2590, -2590, -2590, -2590, -2590, -2590, -2590, -2590, -2590,
    -211,  2300, -2590,   749,  2050, -2590,  2117, -2590, -2590, -2590,
   -2590, -2590, -2590, -2590, -2590, -2590, -2590, -2590, -2590,   463,
   -2590,  2064, -2590,  2429,    97, -2590,    97, -2590, -2590, -2590,
    7894,   210,  7675, -2590, -2590, -2590,  1660, -2590, -2590, -2590,
    2429,   225, -2590, -2590,  2288, -2590, -2590, -2590, -2590, -2590,
   -2590, -2590, -2590, -2590,  1937, -2590,  2284,  1940,  1941,  2289,
   -2590, -2590,  1943, -2590, -2590, -2590, -2590, -2590, -2590,   134,
    2310, -2590, -2590,  2297,  1977, -2590,  1729,   476,  2016, -2590,
   -2590, -2590, -2590, -2590, -2590, -2590, -2590,  5739,   697,    25,
    1976,    93, -2590,  7487, -2590,  1782,  2305,    25, -2590, -2590,
     455, -2590, -2590, -2590, -2590,   129,  1962,  1575,   749,   749,
   -2590, -2590, -2590,    62, -2590,  1966,  1817,  1928, -2590,  1954,
   -2590, -2590, -2590, -2590,  2111,   234, -2590,  2060,  1733,  2060,
   -2590,  1672,  7894,  1793,  1859,  2010,  2084,  7894, -2590,  1786,
   -2590, -2590, -2590,  1324, -2590,   488, -2590,   113,   963,   963,
   -2590, -2590,   463, -2590, -2590,  1392, -2590,  1955, -2590,  2269,
    1814,  7746, -2590,   492,    89,  1392,  7813,   749, -2590, -2590,
     272, -2590, -2590, -2590, -2590, -2590, -2590, -2590, -2590, -2590,
   -2590,   749,  2300, -2590, -2590, -2590,   749, -2590,   749, -2590,
   -2590,  1393, -2590,  2143, -2590,  2145,  7894,   493, -2590, -2590,
   -2590,   495,  2218,  1948, -2590, -2590, -2590,  2344, -2590, -2590,
    1936,  1772, -2590, -2590, -2590, -2590,  2011, -2590,    76, -2590,
      76, -2590, -2590,  7894, -2590,  1959, -2590,  2003,  1238,    68,
   -2590, -2590, -2590,    93, -2590,  2019,  7697,  1986, -2590, -2590,
   -2590,  1797,    25, -2590, -2590, -2590,    15,  1817, -2590, -2590,
    2032, -2590,  1954,   785, -2590, -2590,  1792,  2148,  1796, -2590,
     497, -2590, -2590, -2590, -2590,  2429, -2590, -2590, -2590, -2590,
    1814, -2590, -2590,  7894, -2590,  7842,   634,  7226, -2590,  2381,
   -2590, -2590,  2429,  1392,  2390, -2590,  6053, -2590, -2590, -2590,
    2269,  1861, -2590, -2590, -2590, -2590,  1857,  1857, -2590,  1857,
   -2590,  1857,  1857, -2590, -2590, -2590,   192,   184, -2590, -2590,
    7894,   210, -2590,  2002, -2590,  2148, -2590, -2590,   498, -2590,
    2410, -2590,  2429,  6053, -2590, -2590, -2590, -2590,  2411, -2590,
    -205, -2590, -2590,  2003,   698, -2590, -2590,    80,    80,    80,
      80,    80,    80, -2590,  2393, -2590,   502, -2590,  7487,  2399,
   -2590, -2590, -2590,    27, -2590,  1954,  6471,  1954, -2590, -2590,
    2208,  2148, -2590,  2148, -2590,   116,    25, -2590,   634,   192,
   -2590,   510, -2590,  2429, -2590,   511,  1426,  7813, -2590,  2020,
   -2590,  2184, -2590, -2590, -2590,  1857, -2590,  1857, -2590, -2590,
    2068, -2590,  2429, -2590, -2590, -2590, -2590,    76, -2590,  7894,
    2184,  1238, -2590, -2590, -2590, -2590, -2590, -2590, -2590,    48,
   -2590, -2590, -2590, -2590, -2590, -2590, -2590, -2590, -2590,  7697,
   -2590,  2434, -2590, -2590,   782, -2590, -2590, -2590, -2590, -2590,
   -2590, -2590, -2590,   128, -2590, -2590, -2590,  7842, -2590, -2590,
   -2590,  7813, -2590, -2590, -2590, -2590, -2590, -2590,   841,   841,
   -2590, -2590,   841, -2590,  7487, -2590,  2071, -2590, -2590,   525,
   -2590, -2590, -2590,  2074, -2590, -2590, -2590,   667, -2590,    62,
   -2590,  1817
};

/* YYPGOTO[NTERM-NUM].  */
static const short yypgoto[] =
{
   -2590, -2590, -2590, -2590, -2590,   295, -2590,   381,  -186, -2590,
   -2590,  -834,    94, -2590, -2590, -1515, -2590, -2590, -2590, -2590,
    -569, -2590, -2590, -2590, -2590, -2590, -2590, -2590, -2590, -2590,
   -2590, -2590, -2590, -2590, -2590, -2590, -1750, -2590, -1423, -2590,
     384, -2590, -2590, -2590, -2590, -2590, -2590, -2590,   618, -2590,
   -2590, -2590, -2590,  1223, -2590,   919, -2590, -2590,   -55, -2590,
   -2590,  2420, -2590,  2426,  2102, -2590, -2590, -2590, -2590, -2590,
     692,   343, -2590,   687, -2590, -2590, -2590, -2590, -2590, -2590,
   -2590, -2590, -2590,  -127,   327,   267, -2590, -2590,  2187,   -22,
   -2590,  2334, -2590, -2590,  2331, -2590,  2271, -2590, -2590, -2590,
    2204,  2083,  1155,  2195,  -307, -2590, -2590, -2590, -2590, -2590,
    1158,  -961, -2590, -2590, -2590, -2590, -2590, -2590,  -146,  2135,
    2277,  2279, -2590, -2590,  2119, -2590, -2590,  2180, -2590, -2590,
   -2590, -2590,  2205, -2590, -2590, -2590, -2590,  -325, -2590, -2590,
   -2590, -2590, -2590, -2590, -2590, -2590,  2112, -2590,  2114, -2590,
   -2590, -2590, -2590, -2590, -2590, -2590, -2590,  -856, -2590, -2590,
    -503, -2590, -2590, -2590, -2590, -2590, -2590, -2590,  2333, -2590,
   -2590,  1002, -2590,  -883,  -808,  2063, -2590, -2590, -2590, -2590,
   -2590, -2590, -2590, -2590, -2590,   756, -2590, -2590, -2590, -2590,
   -2590, -2590, -2590,  -479, -2590, -2590, -2590, -2590, -2590,  1992,
   -2590, -2590, -2590, -2590, -2590, -2590, -2590, -2590, -1674, -1684,
   -2590, -2590, -2590, -2590, -2590, -2590, -2590, -2590, -2590, -2590,
   -2590, -2590, -2590, -2590, -2590, -2590, -2590, -2590, -2590,  1565,
   -2590, -2590, -2590, -2590,   885, -2590, -2590, -2590, -2590, -2590,
   -1371, -2590, -2590,   880, -2590, -2590, -2590, -2590, -2590, -2590,
    -788,  -589,   760,  1040, -2590,  -481,   340,  -822,  1117, -2590,
     682, -2590, -1806,    -2,  -316, -2590, -2590,  1421,  1525, -1721,
    -710,  1270, -2590, -2590, -2590,   433,  1280, -2590, -2590, -2590,
   -2590, -2590, -2590,   330, -2590,    -1, -2590,  1288, -2590,   968,
   -2590,   652, -2590, -2590, -2590,  -498, -2590, -2590, -2590, -2590,
   -2590, -2590, -2590, -2590,   767, -2590, -1205, -2590,   956, -2590,
   -2590, -2590, -2590, -2590, -2590, -2590, -2590, -2590, -2590,   325,
   -2590,   331, -2590, -2590, -2590, -2590,  1394, -2590, -2590, -2590,
   -2590, -2590, -2590,  -166, -1458, -2590, -2590, -2590, -2590,   503,
   -2590, -1652, -2590,  -829, -2590, -2590, -2590, -2590, -2590, -2590,
   -2590, -2590, -2590, -2590, -2590, -2590, -2590, -2590, -2590,  2519,
   -2590, -2590, -2590,  2428,  2518, -1554, -2590, -2590, -2590, -2590,
   -2590, -2590, -2590,   -57, -2590, -2590, -2590, -2590, -2590, -2590,
   -2590, -2590,  2524, -2590, -2590, -2590, -2590, -2590, -2590, -2590,
   -2590, -2590, -2590,  1012, -2590, -2590, -2590, -2590, -2590, -2590,
   -2590, -2590, -2590, -2590,  -411,  2077, -2590, -2590, -2590, -2590,
   -2590,  1918, -2590, -2590, -2590, -2590, -2590, -2590, -2590, -2590,
   -2590,  1913, -2590, -2590,   -64, -2590, -2590,  1007, -2590, -2590,
    1331,  -188,  2298, -2590, -2590, -2590, -2590,   -67, -2590,  -703,
    1891,  1315, -2313,  -134, -2590,  1020,  1650,   -25,  -202, -2590,
    -949, -2590,  1444, -2590, -2590, -2590, -2590, -2590, -2590, -2590,
   -2590, -2590, -2590, -2590, -2590, -2590, -2590, -2590, -2590, -2590,
   -2590, -2590, -2590,  1398, -2590,   986, -2590,  -335, -2590, -2590,
   -2590, -2590, -2590, -2590,  -367, -2590, -2590, -2590, -2590, -2590,
   -2590,   406, -2590,  1463,   -95, -2590, -2590, -2590, -2590,   239,
   -2590,  -198, -2590, -2590, -2590, -2590, -2590, -2590, -2590, -2590,
   -2590, -2590, -2590, -2590, -2590, -2590, -2590,  1725, -2590, -2590,
   -2590, -2590, -2590, -2590, -2590,  -319, -2590,  1391,  1546, -2590,
   -2590,   247, -2590,  -337, -2590, -2590,   266,   605, -2590, -2590,
   -2590, -2590, -2590, -2590, -2590,   469, -2590, -2590, -2590, -2590,
   -2590, -2590, -2590, -2590, -2590, -2590, -2590, -2590, -2590, -2590,
   -2590, -2590, -2590, -2590, -2590, -2590, -2590, -2590, -2590, -2590,
   -2534, -2590,  1594,   849,  -967, -2590, -2590, -2590, -2590,  1247,
   -2590, -1304, -2590, -2590, -2590, -1303, -2590, -2590, -1287, -2590,
   -2590, -2590, -2590,  1274, -2590, -2590, -2590, -2590, -2590, -2590,
   -2590, -2590, -2590, -2590, -2590, -2302,  -152, -2590, -2551, -2498,
   -2590,   679, -2590, -2590, -2590, -2590, -2590, -2590,  -420, -2590,
   -2590, -2590, -2590, -2590, -2590, -2590, -2590, -2590, -2590, -2590,
   -2590, -2590,  -383, -2590, -2590, -2590, -2590, -2590, -2590, -2590,
   -2590, -2590, -2590, -2590, -2590, -2590,   650, -2590, -2590, -2590,
    -268, -2590, -2590, -2590, -2590, -2590, -2590,   238, -2590, -2590,
     623, -2590,   964, -2590, -2590, -2590, -2590,   221,  -962, -2590,
   -2590, -2590, -2590, -1378, -2590, -2590, -2590, -2590, -2590, -2590,
   -2452,   -35, -2590, -1995,   213, -2590, -2590, -1641,   271,   270,
     625, -2590, -2590, -2590, -2590, -2590, -2590, -2590, -2590, -2590,
      17,  -266, -2590, -2590,   626, -2590, -1927, -2590, -2590, -2590,
   -2090, -2590, -2590,  -798, -2590,  -696,  1367,  -163, -1595, -2590,
   -2014, -2590, -2590, -2590, -2590,  -704, -1491, -1624, -2115, -2590,
   -2590, -2590, -2590, -2590, -2590, -2590, -2050, -2590,   349, -2590,
   -1216, -2590,  1697, -2590, -2590,  -884,  -179, -2590, -2589,  -178,
     -96,   418, -1944, -1379, -1686,   416,  -341,  1086, -2590,   -73,
    -249, -2590, -2590,  1388,  -492, -2590, -2590,  -208,  1718, -2590,
     454, -2590, -2590, -1232,   109, -2590, -2590, -2590, -2590, -2590,
    -422,  -409,  -429,   974, -2193,     7,  1430,    74, -2590, -2590,
   -2590, -2590, -2590,  1534, -2590,  -475, -2590, -2590, -2590, -2590,
   -2590, -2590, -2590, -2590,  -661,  1462,  2304, -2590, -2590, -2590,
   -2590
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1775
static const short yytable[] =
{
      40,   258,   385,  1021,  1161,   268,  1018,    32,  1170,   112,
      55,    57,   691,  1717,  1157,   814,  1329,  1783,   131,  1757,
    1003,  1188,  1339,  2031,  1361,  1049,   236,   823,   872,   256,
      32,  2068,  2158,   857,  2408,  1256,    68,   863,    97,   860,
    2075,    74,    77,   415,  2040,  1167,  1168,  2071,  1169,  1266,
    1172,  1173,  1568,  1569,  1687,  1201,  1688,  1609,  2124,  1662,
    1374,  2361,   112,  2365,  2025,  2027,   914,   796,  2027,   917,
    1193,   126,  1923,   140,   128,  1470,  1193,    77,   337,   290,
     664,   821,  1120,   870,  1212,   269,   920,   921,   789,   137,
     184,   185,   870,   181,   691,  1482,   144,   699,   186,  2218,
    1016,   680,   150,   151,  1817,  1162,   686,   711,   154,   155,
     298,   299,  1261,  1826,  1849,  1850,  1137,   870,  2241,    97,
     269,  1852,  1853,   201,   126,  1814,  1194,  1276,  1193,  1278,
      81,   269,  1195,   707,  1193,   772,  1978,  1483,   772,  1484,
     929,  1485,   864,  -595,  -595,  1936,  1233,   232,   781,  1272,
     235,   393,   772,   129,   274,   239,   772, -1773,  1016,   269,
     275,   276,  1447,   798,  2157,  1384,  -595,  1248,   772,  2196,
     781,  1406,   825,  2112,  2546,   269,   809,  1114,  1016,   781,
     269,   270,   271,   269,  2367,  2168,   820,   269,   266,  2170,
    2495,   824,  -595,   864,  2614,  1514,   266,  2241,  1943,   862,
     908,  1849,  1850,   378,  1482,   291,   266,   269,  1852,  1853,
     809,  1187,  2340,  2367,   809,  1125,  1126,  2885,   809,  1257,
    2563,  1940,    72,   781,  1016,  1539,   781,  1849,  1850,   266,
    2807,  2173,   295,   269,  2407,  1853,  2367, -1773,   301,   266,
     380,  2212,   388,   269,   920,   921,   397,  2690,  2759,   329,
    1407,  2514,  2515,  2516,  2517,  1179,  1180,   343,  1005,   345,
     382,     1,  2762,  1797,    97,  3050,   399,  1986,  2889,   141,
    1989,   102,  1721,  2397,  2047,  1594,  1595,  2891,   930,  1261,
    1147,  2128,  1833,  2655,    61,  1724,   403,  2974,  3025,  1573,
    1545,   412,  1013,  2926,  1011,  1185,  1948,   811, -1773,   650,
    1144,  1573,   646,  2235,  1369,  1327,  2778,  2182,   555,   643,
    1894,  2658,  3002,   391,  2662,   302,   103,   104,   652, -1773,
    1898,  1895,  1573,  1783,   105,   647,  2975,    17,  1193,  1193,
     391,  1899,  2479,     3,     4,  1006,     5,     6,  1150,    56,
    2003,     7,   303,  1012,   677,  1370,  2232,  1186,   930,  1249,
      17,    61,   653,   407,    63,  2779,   407,    34,     8,     9,
     930,  3003,   776,  2003,   407,  2363,  2917,  1520,  2919,    69,
     635,   645,    33,  2294,  3006,   785,    10,    11,  3007,  3035,
     329,  2370,   329,  2371,  2372,  2373,  2374,  2375,  2376,  2726,
    2028,  2892,  1949,  1361,  2459,  1130,  1225,  2051,  2471,  3005,
     984,   985,  1131,  1262,  2053,  1262,    72,  2025,  2219,   407,
    1151,    81,  2391,  -595,   679,  1448,   682,  1448,   931,   688,
     693,   813,   695,  1577,    76,   698,  2391,  1740,   986,   987,
     988,  2800,  2416,  2800,  2437,  1577,   704,  2625,  2311,  2627,
    2437,  2639,  2727,   766,  2344,  2416,  1515,  2477,  2550,   259,
     260,   261,   262,   263,  2890,   704,  1577,  1489,  2572,   930,
    1282,  2389,  1145,   932,  1229,   766,  2048,    82,   704,  2398,
    1722,  1855,   259,   260,   261,   262,   263,  2659,   799,  3040,
    1629,  1546,   187,  1725,   812,  2737,  1856,  2755,     3,     4,
    3059,     5,     6,  2868,   815,   817,     7,  2883,  2907,  2750,
    2907,   688,  2737,  2997,  2493,  1493,    79,  3019,    82,   766,
     862,   815,   815,     8,     9,  3037,  2977,   383,  1928,   766,
     766,  1542,   892,   766,  1001,    77,   401,   766,  2506,   766,
    2977,    10,    11,   766,   766, -1773,   909, -1773,   909,   815,
      95,   909,   815,  2818,   909,  3045,  1385,  2362,  2368,  1250,
    1388,  1389,  1390,  1207,  1754,  1210,  2460,  1756,  1855,  1391,
    1163,  2230,   259,   260,   261,   262,   263,   932,   379,  1402,
    2669,   717,   933,  1856,  1944,  1366,  1596,  2395,   106,  2129,
    2507,  2978,  1251,   922,  1855,  1368,  1603,  1604,   267,  1196,
     813,  2431,  2341,  2886,  2691,  1614,   340,  1512,   691,  1856,
    2620,   898,    12,  2377,   107,   381,   666,   389,  2302,  2564,
    2799,   398,  2799,  1164,  2101,  1277,  2370,  2804,  2371,  2372,
    2373,  2374,  2375,  2376,  2184,  2185,  2186,  2187,   790,  1696,
    2808,   400,  1799,   862,   824,   862,  1451, -1773,  1654,  2855,
    1937,  2555,   933,  1324,   958,  2561,  1138,   972,  1465,  2197,
      82,   404,  1882,    82,   933,    82,  1979,  1014,  2696,    82,
      82,   272,  1325,    82,    82,   814,  1466,  1843,  2472,  1882,
    1328,    82,   979,   687,   407,   108,  1213,  1197,  2188,  2189,
    2190,  2191,  2192,  2193,    82,   688,   923,  1486,   687,   938,
    2722,    82,  2806,  1716,  1821,  1487,   272,    82,  2871,  2872,
    1017,  1471,  1446,  1741,  2541,  2004,  1199,   272,    82,    82,
     766,   766,  1517,    82,  2800,   691,    82,  2422,  1452,  2482,
    2240,  2229,  2378,   934,   935,   936,   766,  2490,  2020,    82,
    1293,    82,   766,   766,   937,   272,  2698,   766,  1530,  2063,
    2703,  2393,  2962,  1533,  2683,  1531,  1374,   766,  2411,  2412,
    2829,   272,  2681,   933,  1127,  2029,   272,    82,  1550,   272,
      82,    82,  2052,   272,  1494,  2876,  1333,  1041,   109,  2054,
    1495,  1496,  1497,  2220,   132,   687,  1017,  2392,  1333,  1564,
    1565,  1284,  2032,   272,  2628, -1773, -1773, -1773, -1773, -1773,
    1498,  2394,  2063,  1965,  2643,  1545,  2645,  2417,   989,  2438,
    2996,  1610,  1637,    15,   136,  2439,   141, -1773,  3068,   272,
    2442,    82,  2478,  2551,  2509,  1616,  2552,  2881,  1367,   272,
     766,   766,  2881,  2573,  2556,  2370,  2618,  2371,  2372,  2373,
    2374,  2375,  2376,  2184,  2185,  2186,  2187,  1773,  2377,  2386,
     130,  2111,  2660,    42,  2545,  1016,  3031,  -595,  3032,   110,
    2738,   143,  2756,  1330,  1042,   766,  1332,   111,  2869,  2747,
    2841,   766,  2884,  2908,   145,  2909,   897,  2964,  2998,  2033,
     901,  1043,  3020,   766,   905,  2968,  1525,  1697,   766,   194,
    3038,  3039,  2728,   193,  1223,   990,  2034,  2188,  2189,  2190,
    2191,  2192,  2193,  2799,   727,  3065,   195,  2804,  1499,   233,
    1344,  1500,  1240,   234,  1707,  1334,  1776,  2379,   774,  1947,
    1777,  2990,  2454,  1345,  1044,   336,   766,  1334,  1611,   731,
     198,  2629,   783,  2630,  1116,  1501,   788,   241,   991,  2035,
     766,  2510,   249,  2881,  2680,  1176,  2682,  2867,   802,  2685,
     257,  2686,  1183,   250,  2675,  1502,  1638,  1344,  1022,  1023,
    1024,   133,   134,  1045,   252,  2751,   881,  2378,  1469,  1753,
    1345,   253,  1755,  1990,   254,  1639,  1640,   265,  2036,  2851,
    1381,   284,  1573,   913,  3036,  2137,   916,  2768,    82,   919,
    1503,  1335,  1046,  1341,   285,  1641,  1546,  1349,  1358,  1349,
    3069,  1047,   288,  1335,   287,   882,   289,  2037, -1773,  1504,
    1505, -1546,   688,   740,  1290,   688,  2038,  1373,  1376,  2547,
    2548,   695,  1798,  1778,  2381,  1506,  1779, -1773,   293,  2074,
    2074,    43,    33,    34,  3006,   815,   766,  1612,  3007,   815,
     815,   815,   815,  2881,   766,    44,  2081,   766,  1573,  2083,
    2511,  2359,  1825, -1773,   294,   883,   305,  2377,   815,  2202,
     766,  1336,   133,   134,  1507,   296, -1773,   300, -1773,   323,
      45,   766,   314,   766,   766,  2718,   766,   766,   766,   766,
     766,   766,   766,   766,   766,   766,   766,   766,   766,   766,
     766,   766,   766,   884,   335,  1617,  1361,  1508,  2410,  1885,
    1887,  2631,   324,   766,   766,   745,  1618,  2881,   766,  1926,
     766,  1337,  2958,  2856,   330,  2858,  1577,   747,   748,    46,
    2906,  1905,   333,  1337,  1840, -1773,   750,   334,  1619,   341,
    1637,  2234,   688,   339,  1227,  1620, -1773,  2676,   766,   766,
     766,  1347,  1346,   342,  1602,   646,   346,  2677,   347,   815,
    1606,  1468,  2379,  1472,   815,  2292,  1084,  1348,   766,  1344,
     352,   133,   134, -1773,   953,   954,  1279,   960,   647,   350,
    2874,   351,  1345,   353,  1788,   356,  2378, -1773,   804,  1395,
    1396, -1773,  1577, -1773, -1773, -1773, -1773,   810,  1347, -1773,
     885,  2418, -1773, -1773,   357,   766,  2505,  2969,  2382,   367,
   -1773,   815,  1397,  1398,  1348,  1645,  1085,  1086,  1087,  1088,
    1089,  1090,   368,  1813,  1651,  3027,  2059,  3029,   371,  2383,
     766,   376,  1091,  1092,  1093,  1528,   386,   815,   815,  1554,
     134,   912,   815,  2381,   915,   387,  1537,   766,  2064,  1624,
    1625,  2222,   947,  2931,   390,  -261,  1570,   766,   394,  1571,
    2796,  1572,   395,   948,  2401,  2981,  2403,  2404,   725, -1773,
     396,   909,   815,   815,  1632,  1633,   886,  1789,  1790,  1280,
     726,  1573,  1016,  2927,  1638,   934,   935,  1281,  2102,   405,
    2103,  1574,  2187,  1282,  2295,  1283,   402,  1598,   824,  2114,
    1017,  1017,  3000,  1639,  1640,  1607,  1284,  1607,   413,  1017,
    1902,  -936,  1776,   651,  2287,   949,  1777,   887,   667,   862,
    1694,   656,   658,  1641,   659,   972, -1773,   660,   665, -1773,
     950, -1773,   669,  1575,  1285,   670,   671,  1576, -1773,   673,
    2125,   674,  -261,  2188,  2189,  2190,  2191,  2192,  2193,   675,
    1286, -1773,  1017,   676,  1360,  1287,   678, -1773, -1773,  -261,
      82, -1773, -1287,   813,  1349,  1177,  1178,  1288,   962,  1181,
    1182,  2379,   963,  1094,  1289,  1358,  1095, -1773,  1349,  2502,
   -1773,  1617,   964,   965,   966,   888,   967,   969,   968,  2167,
     970,   971,  1618,  2873,   975,   976,  1906,  1703,  1704,  1705,
    1347,   977,  -261, -1773,  2540,   766,   978, -1773,  2951,   259,
     260,   261,   262,   263,  1619,  1577,  1348,  2382,   982,  1778,
     951,  1620,  1779,  1004,   742,   686,  2931,  1006,  1009,  1007,
     766,   766,   766,  1010,   766,  1015,  1016,  1027,  2383,  1019,
    1028,  -261,  1117,  1030,  1573,  1124,  1031,  1570,   889, -1773,
    1571,  1032,  1572, -1773,    48,    49,    50,    51,    52,    53,
     766,    54,  1758,  2184,  2185,  2186,  2187,  1578,  2410,  2666,
    -261,  1033,  1573,  1034,  1035,  1036,   766, -1773,  1037,  -261,
    1038,  1039,  1574,  1050,  1051, -1773,   273,  1052,  1128,  1055,
     278,  1056,   744,  1058,  1786,  1096,  3011,  1060,  1061,  1062,
     766,   746,  1793,  1794,   766,   815,  1202,  1203,  1204,  1205,
    1097,  1063,  1064,  1065,  1098,  2951,  1129,  2188,  2189,  2190,
    2191,  2192,  2193,    82,  1575,  2784,  1066,  1068,  1576,  1290,
    1132,  1133,  1135,   139,   766,  1136,  1291, -1773,  1140,   766,
       3,     4,  1141,     5,     6,   766,  1146,  1143,     7,  1155,
    1823,  1160,  1099,  3028,   766,  1174, -1773,   685,  1292, -1773,
     766,  1184,  1187,  1293,  1208,     8,     9,  1216,   766,  1217,
     703,  3011,   139,  1218,  1221,  1240,  1219,  1869,  1577,  1226,
    1100, -1773,  1220,    10,    11,  1224,  2413,  1228,   815,   815,
    1237,  2785,  1229,  2786,   827,  1252,  1239,   777,  1253,  1101,
    1193,  1254,  1260,   828,   815,  1255,  1577,  1270,  2787,  1268,
    1264,  1269,   829,   794,   795,  1267,  2788,   830,  1315,   801,
    2789,  1323,   803,  1017,  1326,  1340,  1343,  1357,  1363,  2443,
    1907,  1869,  1079,  1080,  1081,  1082,  1083,  1084,  1364,  1372,
    1382,   824,  1973,  1908,  2777,  2790,  1380,   862,  1383,  1381,
    1579,  1400,  1403,  1410,    12,  1985,  1985,  1379,  1578,  1985,
    1392,   831,  1401,  1438,  1441,  2712,  1444,  1199,  2711,   832,
    1445,   862,  1458,  1464,  1476,  1869,  1478,  2021,  2021,  1480,
    1102,  2021,  1869,  1491,  1516,  1492,  1518,  1085,  1086,  1087,
    1088,  1089,  1090,  2188,  2189,  2190,  2191,  2192,  2193,  1519,
    1521,  1523,  1529,  1091,  1092,  1093,  1542,  1909,  2055,  2184,
    2185,  2186,  2187,  1373,  1910, -1773,  1532,   766,  1957,  1557,
   -1773,  1534,   306,  1549,  1349,   833,  1551,  1958,  1262,  1559,
    1586,  1482,  1588,   708,   708,  1869,  1589,  1591,     1,  1597,
    1646,  1657,  1659,  2532,  2074,  2534,  2673,  1103,  1660,  1663,
     834,  1959,  1664,  1911,  1960,  1692,  1690,   835,  1695,   836,
    1699,  1708,  1698,  2188,  2189,  2190,  2191,  2192,  2193,   837,
    1713,   766,  1961,   766,  1714,  1715,  1718,  1349,  1912,  1720,
    1723,   766,   766,   766,   766,  1727,  2021,  1736,  1913,  1914,
    1737,  1739,  2116,  1786,  1742,   838,  2121,  2121,  1743,  1744,
    1762,  2716,  1763,   839,  1915,   766,  2525,  1760,  1764,   307,
       3,     4,  1765,     5,     6,  2133,  2505,  1766,     7,  1768,
    1769,  1770,  1771,  1772,  1774,  1916,   308,   708,  1917,  1918,
    2184,  2185,  2186,  2187,  1919,     8,     9,   924,  1775,  1787,
     840,  1579,  1261,  1802,  1094,  1800,  1803,  1095,  1808,  1804,
    1811, -1773,  1819,    10,    11,    15,  1818,  1827,   681,  1820,
     681,   681,   766,  1824,  2165,  1830,   841,  1836,  1846,   309,
    1848,  1844,   937,  1882,   681,  2832,  1869,  1884,  1962,  1924,
    1925,  1927,  1290,  2840,  2188,  2189,  2190,  2191,  2192,  2193,
    1935,  1920,   681,  1941,  1951,   681,  2184,  2185,  2186,  2187,
    1968,   681,  2203,  1921,   842,   681,  1952,  1971,   310,   681,
    1970,  1993,  1972,   681,  1994,   843,  1995,   681,   681,  1999,
     681,  2002,  1982,   681,  2041,   681,   681,   681,  2042,   824,
     824,  1963,  2043,   681,  2044,  2056,   681,   311,  1964,  2045,
    2046,  2072,  2665,   681,  2058,  1017,   312,  2061,   681,  2067,
    2188,  2189,  2190,  2191,  2192,  2193,   681,   643,  2078,  2021,
    2076,     1,  1869,   643,  2079,  2082,  1096,   681,  2095,  2238,
    1607,   681,  2692,  2097,  2099,   681,   766,  2110,   766,  2115,
     681,  1097,  2130,   681,  2132,  1098,  2021,  2140,  1017, -1773,
    2145,  2143,    89,  2673,  2144,  2146,   924,  1985,  2147,  2586,
    2587,  2588, -1773,  2590,  2591,  2592,  2593,  2594,  2595,  2148,
    2705,  2163,  2598,  2164,   844,   845,   846,  2707,  2175,   645,
    2021,  2176,  2178,  1099,  1869,   645,  1869,   847,  2950,  2179,
    2847,  2183,   936,     3,     4,  2180,     5,     6,  2181,     1,
    2195,     7,  2201,  1115,    13,   315,  1349,  2184,  2185,  2186,
    2187,  1100,  2204,  2206,  2213, -1773,  2215, -1773,     8,     9,
    2221,  2233,  2859,  2241,     2,  2236,   182,   190,  2225,  1358,
    1101,  1349, -1773,  2226,  2297,  2288,    10,    11,  2298,  1703,
   -1773,  2299,   766,  2980, -1773,   766,  2300,  2305,  2388,  2360,
    2389,  2369,  2399,    14,  2402, -1773,  2405,  2396,  2414, -1719,
    2419,  2188,  2189,  2190,  2191,  2192,  2193,  2420,  2425, -1773,
    2783,     3,     4,  2426,     5,     6,  2428,  2429,  2433,     7,
     190,  2184,  2185,  2186,  2187,   766,   190,  2427,   766,  2430,
    2441,   848,   316,  2452,  2186,  2187,     8,     9,  2432,  2434,
    2435,  2436,  2673,  2440,  2673,  2444,  1786,  2446,  2467,   317,
    2469,  1102,  3034,  2447,    10,    11,  2451,   766,  2453,  2457,
     766,  2461,  2465,  2466,  2486,  2468, -1773,  2498,   766,  3012,
    3013,  3014,  3015,  3016,  3017,  2188,  2189,  2190,  2191,  2192,
    2193,  2500,  2784,  2861,  2481,   766,  2188,  2189,  2190,  2191,
    2192,  2193,   318,  2021,  2489,  2504,  2513,   190,  2528,   190,
    1869,  1869,  1869,  1869,  1869,  1869,  2542,  2531,  2543,  2552,
    2367,  2559,   924,   688,  2561,  2077,  2570, -1773,  1103,  2834,
    2574,  2584,   815,  2589,   815,    12,  2080,  2831,  2585,  2596,
    2597,   319,  1041,  2084,  2603,  2604,  2607,  2088,  2608,  2090,
    2091,  2092,  2609,  2610,  2611,  2910,  2612,  2613,  2785,  2862,
    2786,  2362,  2624,  2626,  2021,  2184,  2185,  2186,  2187,  1869,
     320,  2641,  1334,  2644,  2654,  2787,  2656,   681,  2661,   321,
    2667,  2663,   190,  2788,  2684,  2688,  1944,  2789,  2693,  2776,
    1077,  1078,  1079,  1080,  1081,  1082,  1083,  1084,  2695,  2694,
    2696,  2701,  2708,  2700,  2709,  1728,  2710,  2713,  2720,  2717,
    2729,  2730,  2790, -1773,   931,  2743,  2021,  2753,  2765,  2188,
    2189,  2190,  2191,  2192,  2193,  2575,  2576,  1973,  2761,  1042,
    2766,  2673,  2769,  2579,  2773,  2781,  2774,  2811,  2809,  2812,
    2814,  2815,  2725,  2817,  2816,  2820,  1043,  1085,  1086,  1087,
    1088,  1089,  1090,  -595,  2823,    13,  2830,  2828,  2833,  2837,
    2839, -1773,  2843,  1091,  1092,  1093,  2848,  2849,  2857,  2422,
    2866,  2935,   701,  1069,  1070,  1071,  1072,  1073,  1074,  1075,
    1076,  1077,  1078,  1079,  1080,  1081,  1082,  1083,  1084,  1044,
     158,  2904,  1729,  2905,  2875,  1869,  3071,  1869,  2911,  2913,
     681,   681,   681,  2386,    14,  2345,   779,  2915,  1869,  1730,
    2863,  2916,   784,  1869,   786,  2923,  2977,  2021,   793,  2021,
    2936,   793,  2346,  2347,   793,  2948,  2949,  2961,  1045,   159,
    2348,  2963,  2957,  2979,   805,  2032,    15,  2995,  1085,  1086,
    1087,  1088,  1089,  1090,  1349,  2999,  3001,  3018,   160,  3022,
    1017,  1321,  1731,   852,  1091,  1092,  1093,  1046,  3030,  3041,
     924,   865,   868,   871,  2349,   766,  1047,   893,  3044,  3054,
    2485,  3064,  2415,  2350,  3066,   903,  2184,  2185,  2186,  2187,
    3053,  2421,  2155,  1541,  2864,  2121,    70,   161,  2702,  2121,
     926,  1732,  1835,   815,    71,   556,   766,  2117,  2126,   162,
     815,  2464,  2351,   348,  1094,   197,   202,  1095,   668,   163,
     280,  1648,   349,   708,   344,  1649,   766,   406,   282,   655,
    1733,   283,  2033,  2646,   661,   375,   766,   164,   662,  1734,
    2188,  2189,  2190,  2191,  2192,  2193,  3051,   165,   752,  2034,
    1869,  2096,  1869,  1869,  1869,  1869,   891,  2352,  1810,   373,
    1983,  1319,  1991,   166,   766,  2106,  1795,  1365,  2742,  2530,
     782,   924,  2200,  1563,  1881,  3057,  2113,  1903,  2536,  2842,
    1473,  2744,    65,  1869,  1567,   156,  2538,    66,  2021,  2794,
    2314,  2315,  2035,    67,  2316,  2317,  2318,  2238,   800,  2353,
    1842,  1845,  2021,   167,   338,  1094,   961,   981,  1095,   862,
    2021,  1555,  1598,  1258,   854,  2845,  1585,  1847,  2782,  2895,
    2647,  1460,  1511,  1938,   873,   879,  3026,   168,   896,  2520,
    1450,  2036,   900,  2903,   902,  2617,  1096,  2648,   906,   907,
    1211,  2616,   169,  1524,  2599,  1411,  2357,  1378,  2100,   170,
    1691,  1097,   171,  2888,  1658,  1098,  2227,  3058,  3047,   926,
    2037,  2296,   688,  2982,   688,  2358,  2642,  2030,  1869,  2038,
    1869,  2664,   172,  2366,  2819,   173,  2674,   174,  2621,  2622,
    2649,  2991,  2810,  2801,  2380,  1875,  1601,  2914,  2577,  1308,
    2932,  2870,  2933,  1099,  2319,  2558,   175,  2560,  3046,  2860,
    2967,  2320,  2994,  1593,  1556,   414,  1275,  1017,  2758,  2057,
       0,  2821,     0,  2826,   176,     0,  1467,     0,     0,  2650,
       0,  1100,     0,     0,     0,     0,   815,  1096,  1118,     0,
       0,   766,     0,     0,     0,  2321,     0,     0,     0,  1955,
    1101,     0,  1097,     0,  2322,     0,  1098,  1405,  2651,     0,
       0,     0,     0,     0,     0,     0,     0,  2652,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1869,  1149,     0,  2323,  2324,  1869,     0,     0,     0,     0,
       0,     0,     0,     0,  1099,  1166,  1166,  1166,     0,  1166,
       0,  1166,  1166,  2021,     0,     0,     0,    89,    89,  1869,
       0,     0,     0,  2021,  1869,     0,     0,     0,     0,     0,
       0,  2894,  1100,     0,     0,  1627,  1628,     0,  2325,     0,
       0,  1102,  1644,     0,     0,     0,     0,     0,     0,     0,
       0,  1101,     0,     0,  1869,     0,     0,     0,     0,     0,
       0,   871,     0,  1955,     0,     0,     0,     0,     0,     0,
       0,     0,  1235,     0,     0,     0,  1017,     0,  1017,     0,
    2326,  1869,     0,     0,     0,     0,  2021,     0,  2826,  1870,
       0,     0,     0,     0,     0,   926,  1118,     0,     0,     0,
       0,     0,     0,     0,  1265,     0,     0,     0,  1103,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1273,  1273,     0,     0,     0,     0,  2744,     0,     0,     0,
       0,  1869,  1102,  1869,     0,  1869,  2327,     0,     0,     0,
       0,  2021,     0,  1870,  1869,   854,     0,     0,     0,  1598,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   681,     0,     0,     0,   688,     0,     0,  1869,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   190,
    1192,  1869,     0,     0,     0,     0,   854,  1870,     0,     0,
       0,     0,     0,     0,  1870,     0,     0,     0,   873,  1103,
       0,     0,     0,  1215,  2174,     0,   766,  3023,     0,  1082,
    1083,  1084,     0,     0,   766,  1080,  1081,  1082,  1083,  1084,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1409,
       0,     0,     0,     0,     0,  1869,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1870,  1816,     0,
       0,     0,     0,     0,     0,  1017,     0,  1869,     0,  2021,
       0,  1085,  1086,  1087,  1088,  1089,  1090,     0,     0,  1085,
    1086,  1087,  1088,  1089,  1090,   681,     0,  1091,  1092,  1093,
       0,     0,     0,     0,  1879,  1091,  1092,  1093,     0,     0,
    1443,     0,     0,     0,     0,  1869,   681,     0,    89,  1869,
      89,   871,   793,     0,     0,  1025,  1026,     0,     0,  1459,
     805,     0,   766,   871,     0,     0,     0,   190,     0,     0,
    1474,  1040,     0,     0,     0,     0,     0,  1053,  1054,     0,
       0,     0,  1057,   926,     0,     0,     0,     0,     0,     0,
       0,     0,  1067,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  2364,     0,     0,     0,     0,     0,     0,    89,
       0,     0,     0,     0,     0,  2328,  2329,  2330,  2331,  2332,
    2333,  2334,  2335,  2336,  2337,   139,     0,     0,     0,  2169,
    2171,     0,     0,     0,     0,     0,     0,     0,  1870,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1535,
    1074,  1075,  1076,  1077,  1078,  1079,  1080,  1081,  1082,  1083,
    1084,     0,     0,     0,     0,     0,     0,     0,  1094,     0,
       0,  1095,  1561,     0,     0,     0,  1094,     0,     0,  1095,
       0,     0,     0,  1584,   926,  1069,  1070,  1071,  1072,  1073,
    1074,  1075,  1076,  1077,  1078,  1079,  1080,  1081,  1082,  1083,
    1084,     0,     0,  1453,  1454,  1455,     0,     0,     0,     0,
    1085,  1086,  1087,  1088,  1089,  1090,     0,     0,     0,     0,
       0,     0,     0,  1477,  1870,     0,  1091,  1092,  1093,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1631,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1085,  1086,  1087,  1088,  1089,  1090,     0,     0,     0,     0,
    1513,     0,     0,     0,     0,     0,  1091,  1092,  1093,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  2518,  1875,
    2521,  2522,  2523,  2524,     0,   873,  1870,     0,  1870,     0,
    1096,     0,   871,     0,  2177,     0,     0,     0,  1096,     0,
    2151,  2152,  1538,     0,     0,  1097,     0,     0,     0,  1098,
       0,  2161,  1553,  1097,     0,     0,     0,  1098,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1870,     0,
       0,     0,     0,     0,     0,     0,     0,  1955,     0,     0,
    1085,  1086,  1087,  1088,  1089,  1090,     0,  1099,     0,     0,
       0,     0,     0,     0,     0,  1099,  1091,  1092,  1093,  2223,
       0,  2208,  2209,  2210,  2211,     0,     0,  1094,   681,     0,
    1095,  1386,     0,     0,   681,  1100,  2217,     0,     0,  1394,
       0,     0,  1399,  1100,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1101,  1404,     0,     0,   681,     0,
       0,     0,  1101,  1665,     0,     0,  1415,  1094,  1417,  1418,
    1095,  1419,  1420,  1421,  1422,  1423,  1424,  1425,  1426,  1427,
    1428,  1429,  1430,  1431,  1432,  1433,  1434,  1435,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1807,  1436,  1437,
       0,     0,     0,  1439,     0,  1440,  1815,     0,     0,     0,
       0,     0,  2303,  2304,     0,  2390,     0,   871,     0,  2308,
    2309,     0,  1870,  1870,  1870,  1870,  1870,  1870,     0,     0,
       0,     0,     0,     0,     0,  1102,  2623,   182,     0,     0,
       0,  2640,     0,  1102,     0,     0,     0,     0,     0,  1096,
       0,     0,     0,     0,     0,     0,     0,  1094,     0,     0,
    1095,     0,     0,     0,  1097,     0,     0,     0,  1098,     0,
       0,     0,     0,     0,   871,     0,   871,     0,     0,     0,
     865,  1870,     0,     0,     0,     0,     0,     0,     0,  1096,
       0,  1767,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1103,     0,  1097,     0,  1099,     0,  1098,  1719,
    1103,     0,  1977,     0,     0,  1792,     0,     0,     0,  1455,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1100,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1099,     0,     0,  1192,
    2455,  2456,     0,  1101,     0,     0,   708,   708,   708,  2463,
     708,   708,   708,   708,   708,   708,     0,  2476,  2731,   708,
    2733,  2734,  2735,  2736,  1100,  1832,     0,     0,     0,  1096,
       0,   871,     0,     0,     0,  2491,  2492,     0,     0,     0,
       0,     0,     0,  1101,  1097,     0,     0,     0,  1098,  1666,
       0,  1955,     0,     0,     0,     0,     0,  1870,     0,  1870,
       0,     0,     0,     0,     0,     0,   681,   681,     0,     0,
    1870,     0,     0,     0,     0,  1870,     0,     0,     0,     0,
       0,     0,     0,     0,  1102,     0,  1099,  2533,     0,  2535,
       0,     0,     0,   871,     0,   871,  2537,     0,  2539,     0,
       0,     0,     0,     0,   871,     0,     0,  1667,     0,     0,
       0,     0,     0,     0,  1100,     0,     0,     0,     0,  1668,
       0,     0,     0,     0,  1102,     0,     0,     0,     0,  1669,
       0,     0,     0,  1101,     0,     0,  2802,     0,  2174,     0,
    1712,     0,  2138,     0,     0,     0,     0,  1670,     0,     0,
       0,  1103,     0,     0,     0,     0,     0,  1671,     0,     0,
    1672,     0,     0,     0,     0,  1745,  1746,  1747,     0,  1749,
       0,  2160,     0,  1673,   924,     0,     0,     0,     0,     0,
       0,     0,  2060,     0,     0,     0,     0,     0,  2580,  2581,
       0,  1103,  2582,  2583,     0,  1712,     0,     0,     0,     0,
       0,     0,  1870,  2619,  1870,  1870,  1870,  1870,     0,     0,
       0,     0,     0,     0,  1102,     0,     0,     0,     0,     0,
       0,     0,  1674,     0,     0,     0,  2606,     0,     0,     0,
       0,     0,     0,     0,     0,  1870,     0,     0,  2518,     0,
       0,     0,     0,  2865,     0,     0,  2104,  2105,  1455,  2108,
       0,     0,  1675,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1676,     0,     0,     0,     0,  2882,     0,     0,
    2131,     0,  2882,     0,  1812,     0,     0, -1774,     0,     0,
    1712,  1103,  1677,     0,     0,  1678,     0,  1679,     0,  1712,
       0,     0,     0,     0,     0,     0, -1774,     0,     0,     0,
       0,     0,  1955,     0,  1083,  1084,     0,     0,     0,     0,
       0,  2301,     0,     0,  1870,  1680,  1870,     0,     0,     0,
    1870,  1870,  1870,     0,  1681, -1774,     0,  2162,     0,  2922,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    2699,     0,     0,     0,  2704,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  2732,  1085,  1086,  1087,  1088,  1089,
    1090,     0,     0,     0,     0,     0,     0, -1774,     0,     0,
       0,  1091,  1092,  1093,     0,     0,  2721,     0,     0,  1955,
       0,  2973,     0,  2976,     0,     0,     0,     0,     0,     0,
       0,   871,     0,  2752,     0,     0,     0, -1774,     0,     0,
       0, -1774,     0,   924,     0,     0,     0,     0,     0,  2740,
       0,     0,     0,     0,     0,     0,  2992,     0,     0,     0,
       0,     0,  1870,     0,     0, -1774,     0,  1870,     0,     0,
       0,     0,     0, -1774,   871, -1774,     0,     0,     0,     0,
       0,  2289,     0,  2290, -1774,     0,     0,     0,     0,     0,
   -1774,  1870,     0,     0,     0,     0,  1870,     0, -1774,     0,
       0,     0, -1774,     0,     0,     0,     0,  2473, -1774,     0,
       0,     0, -1774, -1774, -1774, -1774,  2483,     0,   701,     0,
    2487,     0,     0,  2882,     0,     0,  1870, -1774,     0,     0,
       0,     0,  2497,  1075,  1076,  1077,  1078,  1079,  1080,  1081,
    1082,  1083,  1084,     0, -1774,  2922,  2093, -1774,  2093, -1774,
       0,     0,  1094,  1870,     0,  1095, -1774,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0, -1774,
       0,     0,     0,     0,     0,     0,     0,     0,     0, -1774,
       0,     0,     0,  2973,     0,     0,     0,  2882,     0,     0,
       0,     0,  1085,  1086,  1087,  1088,  1089,  1090, -1774, -1774,
       0,     0,   384,  1870,     0,  1870,     0,  1870,  1091,  1092,
    1093,     0,     0, -1774,     0,     0,  1870,     0,     0,     0,
       0, -1774,     0,     0,     0, -1774,     0,     0,     0,     0,
    2445,     0,     0,  2450, -1774, -1774, -1774,  1870,     0,     0,
    1870,  1870,     0,     0,     0,     0,  2854,     0,     0,     0,
       0,     0,     0,  1870,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1849,
    1850,     0,  1851,  2578,  1096,   269,  1852,  1853,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1097,
     854,     0,     0,  1098,     0,  1854,     0,     0,     0,     0,
       0,     0,     0, -1774,     0,     0,     0,  1870,     0,     0,
       0,     0,     0,  2600, -1774,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  2615,     0,     0,  1870,
       0,  1099,     0,     0,     0,  2184,  2185,  2186,  2187,     0,
       0,     0,     0,     0,    72,     0,     0,     0,     0,  1094,
       0,     0,  1095,     0,     0, -1774,     0,     0,     0,  1100,
       0,     0,     0,     0,     0,     0,   681,  1870,     0,     0,
       0,  1870,     0,     0,     0,  2959,     0,     0,  1101,     0,
       0,     0,     0,     0,     0,     0,     0,   871,     0,  2188,
    2189,  2190,  2191,  2192,  2193,     0,     0,     0,     0,   924,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0, -1774,   871,  2983,  2984,
       0,  2986,     0,  2988,  2989,     0,     0,     0,     0,     0,
       0,     0,   190,     0,     0,     0,   158,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0, -1774,     0,     0,     0,     0,   926,     0,  1102,
    1712,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1096,     0,   190,     0,   159,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1097,  3033,     0,     0,
    1098,     0,     0,     0,   160,     0,     0,     0,     0, -1774,
       0,     0,     0,     0,     0,     0,     0,  3042,     0,  3043,
       0,     0,     0, -1774, -1774, -1774, -1774, -1774, -1774, -1774,
       0, -1774, -1774,     0,     0,  2005,  1103,     0,  1099,     0,
       0,     0,  2480,   161,  2473,  1712,     0,     0, -1774,     0,
       0,     0,     0,  1712,     0,   162,  3055,     0,     0,     0,
       0,     0,     0,     0,     0,   163,  1100,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    3060,  3061,     0,   164,  3062,  1101,  2600,  2243,     0,     0,
       0,     0,     0,   165,     0,     0,     0,     0,     0,     0,
       0,  2706,     0,     0,     0,     0,     0,     0,     0,   166,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  2244,  2245,  2246,
       0,  2723,     0,     0,     0,     0,  1855,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   167,
       0,  1856,  2247,     0,     0,     0,     0,     0,     0,  2739,
    2248,     0,     0,     0,     0,  2249,  1102,     0,  1857,     0,
       0,  2006,     0,   168,   871,     0,     0,     0,     0,     0,
    2250,     0,     0,  2007,  1859,  2251,     0,  2252,   169,     0,
       0,  2844,  2473,     0,  2253,   170,   926,  2254,   171,     0,
    2255,     0,     0,  2256,     0,     0,  2257,     0,     0,     0,
       0,  2258,     0,     0,     0,     0,     0,     0,   172,     0,
       0,   173,     0,   174,     0,  1861,     0,     0,     0,  2259,
       0,     0,     0,  1103,     0,     0,     0,  1862,     0,     0,
       0,     0,   175,     0,     0,  2260,     0,     0,  2261,  2262,
    2473,     0,     0,     0,     0,  2263,     0,     0,     0,     0,
     176,     0,     0,     0,  2600,     0,  2264,     0,     0,  2898,
       0,  2900,     0,     0,     0,     0,     0,     0,  1863,     0,
       0,     0,  2265,     0,     0,     0,     0,     0,     0,  2266,
       0,     0,     0,     0,     0,     0,  2267,     0,     0,  2268,
    2269,  2270,     0,  2271,  2272,     0,     0,     0,     0,     0,
       0,     0,   871,     0,     0,     0,   871,  1864,     0,     0,
    2273,     0,     0,     0,     0,     0,  2835,     0,     0,  1865,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    2687,  1866,  1867,  2274,  2275,  2276,  2277,     0,  2278,     0,
    1868,     0,     0,   687,     0,     0,     0,     0,     0,     0,
       0,   272,     0,     1,     0,  2279,  2280,   416,   417,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     418,     0,   419,     0,     0,     0,     0,     0,  2281,     0,
       0,  1712,     0,     0,     0,     0,   420,  2282,  2283,     0,
    2284,     0,     0,   421,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   422,   423,   424,     0,     0,     0,
    1166,  1166,  1166,  1166,  1166,  1166,     0,     0,     0,     0,
     425,     0,   426,   427,   428,     3,     4,   429,     5,     6,
     430,     0,   431,     7,   432,   433,     0,     0,     0,     0,
       0,   434,     0,     0,   435,     0,   436,   437,   438,     0,
       8,     9,  2285,     0,     0,     0,   439,     0,   440,   441,
       0,   442,     0,   443,   444,     0,     0,   445,    10,    11,
       0,     0,   446,   447,   448,     0,   449,   450,     0,     0,
       0,   451,   452,     0,   453,     0,     0,     0,   454,     0,
     455,   456,     0,     0,     0,     0,   457,     0,     0,     0,
     458,     0,     0,   459,     0,   460,     0,   461,     0,   462,
       0,   463,   464,     0,   465,   466,   467,     0,     0,     0,
     468,     0,   469,   470,     0,   471,     0,     0,     0,     0,
       0,     0,     0,   472,   473,     0,     0,     0,     0,     0,
       0,     0,   926,     0,     0,     0,   474,     0,     0,   475,
     476,     0,     0,   477,   478,     0,     0,   479,   480,     0,
       0,     0,     0,     0,     0,     0,   481,   482,   483,     0,
     484,  3021,     0,     0,     0,     0,     0,     0,     0,     0,
     485,   486,   487,     0,   488,     0,     0,     0,   489,   490,
       0,     0,     0,   491,     0,     0,     0,     0,     0,     0,
       0,   492,     0,     0,     0,     0,     0,     0,     0,   493,
     494,   495,     0,     0,     0,     0,     0,   496,   497,     0,
       0,     0,     0,   498,     0,     0,   499,     0,     0,     0,
     500,   501,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   502,  2139,  1069,  1070,  1071,  1072,  1073,  1074,  1075,
    1076,  1077,  1078,  1079,  1080,  1081,  1082,  1083,  1084,   503,
       0,     0,     0,     0,     0,     0,     0,   504,     0,     0,
       0,     0,     0,   505,     0,     0,     0,  3063,  1069,  1070,
    1071,  1072,  1073,  1074,  1075,  1076,  1077,  1078,  1079,  1080,
    1081,  1082,  1083,  1084,     0,     0,   107,     0,     0,     0,
       0,     0,     0,   506,     0,   507,   508,     0,  1085,  1086,
    1087,  1088,  1089,  1090,   509,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1091,  1092,  1093,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1085,  1086,  1087,  1088,  1089,  1090,     0,
       0,     0,     0,   510,     0,     0,     0,     0,     0,  1091,
    1092,  1093,     0,     0,   511,     0,     0,     0,   512,     0,
       0,     0,   513,  1069,  1070,  1071,  1072,  1073,  1074,  1075,
    1076,  1077,  1078,  1079,  1080,  1081,  1082,  1083,  1084,     0,
       0,     0,     0,     0,     0,     0,   514,   515,     0,     0,
       0,   516,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   517,     0,     0,     0,     0,     0,   518,
     519,   520,   521,     0,     0,   522,     0,     0,     0,   523,
       0,     0,     0,     0,     0,     0,   524,   525,  1085,  1086,
    1087,  1088,  1089,  1090,     0,     0,     0,     0,   526,  1712,
     527,     0,     0,     0,  1091,  1092,  1093,     0,     0,     0,
       0,   528,     0,   529,     0,  1094,   530,     0,  1095,     0,
       0,     0,   531,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   532,     0,
    1094,   533,     0,  1095,     0,     0,     0,   534,     0,     0,
     535,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   536,     0,     0,     0,     0,
       0,     0,   537,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   538,   539,   540,   541,   542,
     543,   544,     0,     0,   545,     0,   546,     0,   547,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1096,     0,     0,
       0,     0,     0,     0,     0,  1094,     0,     0,  1095,     0,
       0,     0,  1097,     0,     0,     0,  1098,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1096,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1097,     0,     0,
       0,  1098,  1726,     0,  1099,     0,  1069,  1070,  1071,  1072,
    1073,  1074,  1075,  1076,  1077,  1078,  1079,  1080,  1081,  1082,
    1083,  1084,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1100,     0,     0,     0,     0,     0,     0,  1099,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1101,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1100,     0,     0,
       0,  1085,  1086,  1087,  1088,  1089,  1090,  1096,     0,     0,
       0,     0,     0,     0,     0,     0,  1101,  1091,  1092,  1093,
       0,     0,  1097,     0,     0,     0,  1098,  1738,     0,     0,
       0,     0,     0,  1069,  1070,  1071,  1072,  1073,  1074,  1075,
    1076,  1077,  1078,  1079,  1080,  1081,  1082,  1083,  1084,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1102,     0,  1099,  1069,  1070,  1071,  1072,  1073,
    1074,  1075,  1076,  1077,  1078,  1079,  1080,  1081,  1082,  1083,
    1084,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1100,     0,     0,     0,     0,  1102,  1085,  1086,
    1087,  1088,  1089,  1090,     0,     0,     0,     0,     0,     0,
       0,  1101,     0,     0,  1091,  1092,  1093,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1103,
    1085,  1086,  1087,  1088,  1089,  1090,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1091,  1092,  1093,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1094,     0,
       0,  1095,     0,     0,  1103,     0,  1069,  1070,  1071,  1072,
    1073,  1074,  1075,  1076,  1077,  1078,  1079,  1080,  1081,  1082,
    1083,  1084,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1102,     0,     0,  1069,  1070,  1071,  1072,  1073,
    1074,  1075,  1076,  1077,  1078,  1079,  1080,  1081,  1082,  1083,
    1084,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1085,  1086,  1087,  1088,  1089,  1090,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1091,  1092,  1093,
       0,     0,     0,     0,     0,  1094,     0,     0,  1095,  1103,
    1085,  1086,  1087,  1088,  1089,  1090,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1091,  1092,  1093,     0,
    1096,     0,     0,     0,     0,     0,     0,  1094,     0,     0,
    1095,     0,     0,     0,     0,  1097,     0,     0,     0,  1098,
    1748,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1099,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1100,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1096,     0,     0,
       0,     0,     0,     0,  1101,     0,     0,     0,  1094,     0,
       0,  1095,  1097,     0,     0,     0,  1098,  1750,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1096,
       0,     0,     0,     0,     0,     0,     0,  1094,     0,     0,
    1095,     0,     0,     0,  1097,     0,     0,     0,  1098,  1751,
       0,     0,     0,     0,  1099,  1070,  1071,  1072,  1073,  1074,
    1075,  1076,  1077,  1078,  1079,  1080,  1081,  1082,  1083,  1084,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1100,     0,     0,  1102,  1099,     0,     0,     0,
    1849,  1850,     0,  1851,     0,     0,   269,  1852,  1853,     0,
       0,  1101,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1100,     0,  1854,     0,     0,  1085,
    1086,  1087,  1088,  1089,  1090,     0,     0,     0,     0,     0,
    1096,     0,     0,  1101,     0,  1091,  1092,  1093,     0,     0,
    1849,  1850,     0,  1851,     0,  1097,   269,  1852,  1853,  1098,
    1752,     0,  1103,     0,     0,     0,     0,     0,     0,  1096,
       0,     0,     0,     0,     0,     0,  1854,     0,     0,     0,
       0,     0,     0,     0,  1097,     0,     0,     0,  1098,     0,
       0,     0,  1102,     0,     0,     0,     0,  1099,     0,  1071,
    1072,  1073,  1074,  1075,  1076,  1077,  1078,  1079,  1080,  1081,
    1082,  1083,  1084,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1102,  1100,  1099,     0,     0,     0,
    1072,  1073,  1074,  1075,  1076,  1077,  1078,  1079,  1080,  1081,
    1082,  1083,  1084,     0,  1101,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1100,     0,     0,     0,     0,  1103,
       0,     0,  1085,  1086,  1087,  1088,  1089,  1090,     0,     0,
       0,     0,     0,  1101,     0,     0,     0,     0,  1091,  1092,
    1093,     0,     0,     0,     0,     0,  1094,     0,     0,  1095,
       0,  1103,  1085,  1086,  1087,  1088,  1089,  1090,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1091,  1092,
    1093,  1073,  1074,  1075,  1076,  1077,  1078,  1079,  1080,  1081,
    1082,  1083,  1084,     0,     0,  1102,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1076,  1077,  1078,  1079,  1080,
    1081,  1082,  1083,  1084,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1102,     0,  2005,  1078,  1079,  1080,
    1081,  1082,  1083,  1084,     0,     0,     0,     0,     0,     0,
       0,     0,  1085,  1086,  1087,  1088,  1089,  1090,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1091,  1092,
    1093,     0,  1103,  1085,  1086,  1087,  1088,  1089,  1090,     0,
       0,     0,     0,     0,     0,     0,  2005,     0,  1096,  1091,
    1092,  1093,     0,  1085,  1086,  1087,  1088,  1089,  1090,  1094,
       0,  1103,  1095,  1097,     0,     0,     0,  1098,     0,  1091,
    1092,  1093,     0,   712,   713,     0,     0,     0,     0,   269,
     714,   715,  -595,     0,     0,     0,     0,     0,     0,  1094,
       0,     0,  1095,     0,   716,     0,     0,  1855,     0,   717,
     718,     0,     0,     0,     0,  1099,   719,     0,     0,     0,
       0,     0,  1856,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1857,
       0,     0,  2006,  1100,   720,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  2007,  1859,     0,  1855,     0,     0,
       0,     0,  1101,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1856,     0,     0,     0,     0,     0,     0,  1094,
       0,     0,  1095,  2362,     0,     0,     0,     0,     0,  1857,
       0,  1096,  2006,     0,     0,     0,  1861,     0,     0,     0,
    1094,     0,     0,  1095,  2007,  1859,  1097,     0,  1862,     0,
    1098,     0,     0,     0,     0,     0,     0,     0,   712,   713,
    1094,  1096,     0,  1095,   269,   714,   715,  -595,     0,     0,
       0,     0,     0,     0,     0,     0,  1097,   721,     0,   716,
    1098,     0,     0,  1102,   717,   718,  1861,     0,  1099,  1863,
       0,   719,     0,     0,     0,     0,     0,     0,  1862,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1100,     0,  1099,   720,
       0,     0,     0,     0,     0,     0,     0,     0,  1864,     0,
       0,     0,     0,     0,     0,  1101,     0,     0,     0,  1863,
    1865,  1096,     0,     0,     0,     0,  1100,     0,     0,     0,
    1103,     0,  1866,  1867,  2008,     0,  1097,     0,     0,     0,
    1098,  1868,  1096,     0,   687,  1101,     0,     0,     0,     0,
       0,     0,   272,     0,   722,     0,     0,  1097,  1864,   723,
       0,  1098,  1096,     0,     0,     0,     0,     0,     0,     0,
    1865,     0,     0,     0,     0,     0,     0,  1097,  1099,     0,
       0,  1098,  1866,  1867,  2008,     0,     0,   724,     0,     0,
       0,  1868,   721,     0,   687,     0,  1102,     0,     0,  1099,
       0,     0,   272,     0,     0,     0,  1100,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1099,
       0,     0,   725,     0,     0,  1101,  1102,  1100,     0,     0,
       0,     0,     0,     0,   726,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1101,  1100,     0,     0,
       0,     0,   727,     0,     0,     0,     0,   728,     0,     0,
     729,     0,     0,  1103,     0,     0,  1101,     0,     0,     0,
       0,   730,     0,     0,     0,     0,     0,   731,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   732,     0,   722,
       0,     0,   733,  1103,   723,   734,     0,     0,   735,     0,
       0,     0,     0,   712,   713,     0,  1102,   736,   737,   269,
     714,   715,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   724,     0,   716,     0,     0,  1102,     0,   717,
     718,     0,     0,     0,     0,     0,   719,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1102,  1189,   738,
       0,     0,     0,   739,     0,     0,     0,   725,     0,     0,
       0,   740,     0,     0,   720,     0,     0,     0,     0,   726,
       0,     0,   741,  1103,     0,     0,     0,     0,   742,     0,
       0,     0,     0,     0,     0,     0,     0,   727,     0,     0,
       0,     0,   728,     0,  1103,   729,     0,     0,     0,     0,
       0,     0,   743,     0,     0,     0,   730,     0,     0,     0,
       0,     0,   731,     0,  1103,     0,     0,     0,     0,     0,
       0,     0,   732,     0,     0,     0,     0,   733,     0,     0,
     734,     0,     0,   735,     0,     0,     0,     0,     0,     0,
       0,     0,   736,   737,     0,     0,   744,     0,     0,     0,
       0,     0,     0,   745,     0,   746,     0,   721,     0,     0,
       0,     0,     0,     0,     0,   747,   748,   749,     0,     0,
       0,     0,     0,     0,   750,     0,     0,    82,     0,     0,
       0,     0,     0,     0,   738,   272,     0,     0,   739,     0,
       0,     0,     0,     0,     0,     0,   740,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   741,     0,     0,
       0,     0,     0,   742,   712,   713,     0,     0,     0,     0,
     269,   714,   715,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   716,     0,   743,     0,     0,
     717,   718,     0,     0,     0,     0,     0,   719,     0,     0,
       0,     0,     0,     0,   722,     0,     0,     0,     0,   723,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   720,     0,     0,     0,     0,
       0,   744,     0,     0,     0,     0,     0,   724,   745,     0,
     746,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     747,   748,   749,     0,     0,     0,     0,     0,     0,   750,
       0,     0,    82,     0,     0,     0,     0,     0,     0,     0,
     272,     0,   725,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   726,     0,     0,     0,     0,     0,
       0,     0,     0,   712,   713,     0,     0,     0,     0,   269,
     714,   715,   727,     0,     0,     0,     0,   728,     0,     0,
     729,     0,     0,     0,   716,     0,     0,     0,   721,   717,
     718,   730,     0,     0,     0,     0,   719,   731,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   732,     0,     0,
       0,     0,   733,     0,     0,   734,     0,     0,   735,     0,
       0,     0,     0,     0,   720,     0,     0,   736,   737,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1849,  1850,     0,  1851,     0,     0,   269,
    1852,  1853,     0,     0,     0,     0,     0,     0,  1189,   738,
       0,     0,     0,   739,     0,     0,     0,     0,     0,  1854,
       0,   740,     0,     0,     0,   722,     0,     0,     0,     0,
     723,     0,   741,     0,     0,     0,     0,     0,   742,     0,
       0,     0,     0,   712,   713,     0,     0,     0,     0,   269,
     714,   715,     0,  1849,  1850,     0,  1851,   721,   724,   269,
    1852,  1853,   743,     0,   716,     0,     0,     0,     0,   717,
     718,     0,     0,     0,     0,     0,   719,     0,     0,  1854,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   725,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   720,   726,   744,     0,     0,     0,
       0,     0,     0,   745,     0,   746,     0,     0,     0,     0,
       0,     0,     0,   727,     0,   747,   748,   749,   728,     0,
       0,   729,     0,     0,   750,     0,     0,    82,     0,     0,
       0,     0,   730,     0,     0,   272,     0,     0,   731,     0,
       0,     0,     0,     0,   722,     0,     0,     0,   732,   723,
       0,     0,     0,   733,     0,     0,   734,     0,     0,   735,
       0,     0,     0,     0,     0,     0,     0,     0,   736,   737,
       0,     0,     0,     0,     0,     0,     0,   724,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   721,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     738,     0,   725,     0,   739,     0,     0,     0,     0,     0,
       0,     0,   740,     0,   726,     0,     0,     0,     0,     0,
       0,     0,     0,   741,     0,  2107,     0,     0,     0,   742,
       0,     0,   727,     0,     0,     0,  -837,   728,     0,     0,
     729,     0,  1849,  1850,     0,  1851,     0,     0,   269,  1852,
    1853,   730,     0,   743,     0,     0,     0,   731,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   732,  1854,     0,
       0,     0,   733,     0,   722,   734,     0,     0,   735,   723,
       0,     0,     0,     0,     0,     0,     0,   736,   737,     0,
       0,     0,     0,     0,   712,   713,     0,   744,     0,     0,
     269,   714,   715,     0,   745,     0,   746,   724,     0,     0,
       0,     0,     0,     0,     0,   716,   747,   748,   749,     0,
     717,   718,     0,     0,     0,   750,     0,   719,    82,   738,
    1855,     0,     0,   739,     0,     0,   272,     0,     0,     0,
       0,   740,   725,     0,     0,  1856,     0,     0,     0,     0,
       0,     0,   741,     0,   726,   720,     0,     0,   742,     0,
       0,     0,  1857,     0,     0,  2632,     0,     0,     0,     0,
       0,     0,   727,     0,     0,     0,     0,   728,  1859,     0,
     729,     0,   743,     0,     0,     0,     0,     0,     0,     0,
    1855,   730,     0,     0,     0,     0,     0,   731,     0,     0,
       0,     0,     0,     0,     0,  1856,     0,   732,     0,     0,
       0,     0,   733,     0,     0,   734,     0,     0,   735,  1861,
       0,     0,  1857,     0,     0,  2632,   744,   736,   737,     0,
       0,  1862,     0,   745,     0,   746,     0,     0,  1859,     0,
       0,     0,     0,     0,     0,   747,   748,   749,   721,     0,
       0,     0,     0,     0,   750,     0,     0,    82,     0,     0,
       0,     0,     0,     0,     0,   272,  2362,     0,  2501,   738,
       0,     0,  1863,   739,     0,     0,     0,     0,  2878,  1861,
       0,   740,  1849,  1850,     0,  1851,     0,     0,   269,  1852,
    1853,  1862,   741,     0,     0,     0,     0,     0,   742,     0,
       0,     0,     0,     0,     0,  2633,     0,     0,  1854,     0,
       0,  1864,     0,     0,     0,     0,     0,     0,     0,     0,
    2634,  2635,   743,  1865,     0,     0,     0,     0,     0,     0,
       0,     0,  1863,     0,     0,  1866,  1867,     0,     0,     0,
       0,     0,     0,     0,  1868,   722,     0,   687,     0,     0,
     723,     0,     0,  1849,  1850,   272,  1851,     0,     0,   269,
    1852,  1853,     0,     0,  1906,     0,   744,     0,     0,     0,
       0,  1864,     0,   745,     0,   746,     0,     0,   724,  1854,
       0,     0,     0,  1865,     0,   747,   748,   749,     0,     0,
       0,     0,     0,     0,   750,  1866,  1867,    82,     0,  1855,
       0,     0,     0,     0,  1868,   272,     0,   687,     0,     0,
       0,     0,     0,   725,  1856,   272,     0,     0,     0,     0,
    1849,  1850,     0,  1851,     0,   726,   269,  1852,  1853,     0,
       0,  1857,     0,     0,  1858,     0,     0,     0,     0,     0,
       0,     0,     0,   727,     0,     0,  1854,  1859,   728,  1849,
    1850,   729,  1851,     0,     0,   269,  1852,  1853,     0,     0,
       0,     0,   730,     0,     0,     0,     0,     0,   731,  2937,
       0,     0,     0,     0,     0,  1854,     0,     0,   732,     0,
       0,     0,     0,   733,     0,     0,   734,  1860,  1861,   735,
       0,     0,     0,     0,     0,     0,     0,     0,   736,   737,
    1862,  1849,  1850,     0,  1851,     0,     0,   269,  1852,  1853,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  2938,     0,  1854,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     738,  1863,     0,     0,   739,     0,     0,     0,     0,     0,
    2939,     0,   740,     0,     0,     0,     0,   203,     0,  2940,
       0,     0,     0,   741,     0,     0,     0,     0,     0,   742,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1864,     0,     0,     0,     0,   204,   205,     0,     0,     0,
       0,     0,  1865,   743,   206,  2941,     0,     0,  1907,     0,
       0,     0,     0,  2942,  1866,  1867,     0,     0,     0,     0,
       0,  1908,     0,  1868,     0,     0,   687,     0,     0,     0,
       0,     0,     0,     0,   272,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   744,     0,  1855,
       0,     0,     0,     0,   745,     0,   746,     0,     0,     0,
       0,     0,     0,     0,  1856,     0,   747,   748,   749,     0,
       0,     0,     0,     0,     0,   750,     0,     0,    82,     0,
       0,  1857,     0,     0,  1858,  1909,   272,     0,     0,     0,
       0,     0,  1910,     0,     0,     0,     0,  1859,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  2943,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1855,     0,     0,     0,     0,  2362,     0,     0,     0,     0,
       0,  1911,     0,     0,     0,  1856,     0,     0,  1861,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1862,     0,  1857,     0,     0,  2877,  1912,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1913,  1914,  1859,     0,
       0,     0,     0,     0,     0,   207,     0,     0,     0,     0,
       0,     0,  1915,     0,     0,     0,     0,  1855,     0,     0,
       0,  1863,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1856,  1916,     0,     0,  1917,  1918,  2878,  1861,
       0,     0,  1919,     0,   208,     0,  1855,     0,     0,  1857,
       0,  1862,  2632,     0,     0,     0,     0,     0,     0,     0,
    1864,  1856,     0,   209,     0,  1859,     0,     0,     0,     0,
       0,     0,  1865,     0,     0,     0,     0,     0,  1857,   210,
       0,  1858,     0,     0,  1866,  1867,     0,     0,     0,     0,
       0,     0,  1863,  1868,  1859,     0,   687,     0,  1855,  1920,
       0,     0,   211,     0,   272,  2878,  1861,     0,     0,  2944,
       0,  1921,     0,  1856,   212,     0,     0,     0,  1862,     0,
       0,     0,     0,     0,   213,     0,     0,     0,     0,     0,
    1857,  1864,     0,  1858,  2970,  1861,     0,     0,     0,     0,
       0,     0,   214,  1865,     0,     0,  1859,  1862,     0,     0,
       0,     0,   215,     0,     0,  1866,  1867,     0,     0,  1863,
       0,     0,     0,     0,  1868,     0,     0,   687,   216,     0,
       0,     0,     0,     0,     0,   272,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1861,  1863,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1864,  1862,
       0,     0,     0,     0,     0,     0,     0,     0,   217,     0,
    1865,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1866,  1867,     0,     0,     0,  1864,     0,     0,
       0,  1868,   218,     0,   687,     0,     0,     0,     0,  1865,
    1863,     0,   272,     0,     0,     0,     0,   219,     0,     0,
       0,  1866,  1867,     0,   220,     0,     0,   221,     0,     0,
    1868,     0,     0,   687,     0,     0,     0,     0,     0,     0,
       0,   272,     0,     0,     0,     0,     0,   222,     0,  1864,
     223,     0,   224,     0,     0,     0,     0,     0,     0,     0,
       0,  1865,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   225,     0,  1866,  1867,     0,     0,     0,     0,     0,
       0,     0,  1868,     0,     0,   687,     0,     0,     0,   226,
       0,     0,     0,   272,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   227
};

static const short yycheck[] =
{
       2,   187,   327,   706,   826,   193,   702,     0,   837,    64,
      12,    13,   421,  1392,   822,   496,   977,  1475,    82,  1442,
     681,   855,   984,  1664,   991,   729,   153,   506,   520,   175,
      23,  1717,  1838,   512,  2048,   918,    29,   516,    60,   514,
    1724,    43,    44,   362,  1668,   833,   834,  1721,   836,   932,
     838,   839,  1257,  1258,  1357,   863,  1360,  1289,  1779,  1346,
    1009,  2005,   117,  2007,  1659,  1660,   541,   478,  1663,   544,
       5,    64,  1587,    95,    76,    20,     5,    79,   264,   225,
     387,   503,   778,    24,     5,    23,    24,    25,    24,    91,
      17,    18,    24,    24,   503,     5,    98,    25,    25,  1905,
      24,   417,   104,   105,  1527,    25,    24,   444,   110,   111,
     237,   238,     5,  1536,    17,    18,     5,    24,     5,   141,
      23,    24,    25,   145,   117,    25,    55,   949,     5,   951,
      24,    23,    61,    25,     5,   451,     5,    47,   454,    49,
      45,    51,    24,    26,    26,    79,    24,   149,   464,    24,
     152,   339,   468,    79,    18,   157,   472,    41,    24,    23,
      24,    25,    24,   479,    24,  1021,    26,   141,   484,    41,
     486,  1055,   507,  1768,  2224,    23,   492,    25,    24,   495,
      23,    24,    25,    23,     6,    25,   502,    23,     5,    25,
      24,   507,    26,    24,    24,   323,     5,     5,   128,   515,
     537,    17,    18,     5,     5,   227,     5,    23,    24,    25,
     526,     5,   113,     6,   530,    66,    67,   128,   534,   922,
      20,  1599,    26,   539,    24,   318,   542,    17,    18,     5,
       5,  1855,   234,    23,    24,    25,     6,    70,   240,     5,
       5,  1893,     5,    23,    24,    25,     5,     5,  2561,   251,
     374,  2178,  2179,  2180,  2181,   844,   845,   279,   687,   281,
       5,    29,  2564,   488,   286,   217,     5,  1638,  2766,     5,
    1641,    39,   370,   409,   186,   114,   115,     5,   253,     5,
     363,     5,   318,  2398,    17,   370,     5,  2876,   261,   274,
      22,   358,     5,  2827,   517,   312,   154,   353,   318,   366,
     437,   274,   604,  1944,   555,     5,   517,   409,   363,   364,
     417,  2401,   517,   335,  2404,   409,    84,    85,   370,   339,
     417,   428,   274,  1781,    92,   627,  2877,     0,     5,     5,
     352,   428,  2138,   101,   102,   437,   104,   105,   525,    24,
       5,   109,   436,   566,   411,   596,  1941,   364,   253,   323,
      23,    84,   404,   355,     0,   566,   358,    28,   126,   127,
     253,   566,   457,     5,   366,  2006,  2818,  1201,  2820,    30,
     363,   364,    27,  1968,   326,   470,   144,   145,   330,  2968,
     382,     9,   384,    11,    12,    13,    14,    15,    16,  2504,
       5,   119,   250,  1360,   437,   598,   888,     5,   368,  2933,
      35,    36,   605,   129,     5,   129,    26,  2002,     5,   411,
     597,    24,     5,    26,   416,  1125,   418,  1127,   323,   421,
     422,   646,   424,   408,   568,   427,     5,     5,    63,    64,
      65,  2624,     5,  2626,     5,   408,   438,  2381,  1992,  2383,
       5,  2385,     5,   445,  1998,     5,   574,     5,     5,    17,
      18,    19,    20,    21,  2767,   457,   408,  1160,     5,   253,
     214,     5,   599,   368,   557,   467,   378,   591,   470,   605,
     568,   374,    17,    18,    19,    20,    21,     5,   480,  2977,
     363,   213,   409,   568,   540,     5,   389,     5,   101,   102,
    3041,   104,   105,     5,   496,   497,   109,     5,     5,  2549,
       5,   503,     5,     5,  2156,    24,   605,     5,   591,   511,
     826,   513,   514,   126,   127,     5,     5,   262,   450,   521,
     522,   557,   524,   525,   328,   527,   262,   529,   374,   531,
       5,   144,   145,   535,   536,   419,   538,   557,   540,   541,
     332,   543,   544,   409,   546,  2997,  1027,   450,   370,   523,
    1031,  1032,  1033,   872,  1438,   874,   599,  1441,   374,  1034,
     480,  1939,    17,    18,    19,    20,    21,   368,   370,  1050,
     494,    43,   547,   389,   504,  1004,   415,   370,   346,  1784,
    2175,  2883,   556,   363,   374,  1007,  1282,  1283,   405,   518,
     646,  2082,   493,   504,   352,  1291,   405,  1186,  1007,   389,
     370,   527,   215,   231,   372,   370,   405,   370,  1979,   409,
    2624,   370,  2626,   533,   555,   950,     9,  2631,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,   564,   405,
     405,   370,  1488,   949,   950,   951,  1128,   521,  1334,   405,
     574,  2236,   547,   968,   646,   532,   535,   669,  1140,   521,
     591,   370,   529,   591,   547,   591,   525,   370,   529,   591,
     591,   599,   969,   591,   591,  1146,  1141,  1550,   638,   529,
     370,   591,   674,   591,   676,   443,   597,   606,    71,    72,
      73,    74,    75,    76,   591,   687,   466,   597,   591,   595,
    2496,   591,  2636,   370,   370,   605,   599,   591,  2748,  2749,
     702,   646,  1124,  1407,  2219,   370,   641,   599,   591,   591,
     712,   713,  1193,   591,  2907,  1124,   591,   525,  1129,  2142,
    1952,  1937,   350,   628,   629,   630,   728,  2150,   370,   591,
     484,   591,   734,   735,   639,   599,  2457,   739,  1219,  1706,
    2461,  2028,  2857,  1224,  2428,  1220,  1695,   749,  2051,  2053,
    2677,   599,  2426,   547,   605,   370,   599,   591,  1237,   599,
     591,   591,   370,   599,   283,  2760,   136,   345,   536,   370,
     289,   290,   291,   370,   221,   591,   778,   370,   136,  1254,
    1255,   227,   345,   599,   228,   618,   619,   620,   621,   622,
     309,   370,  1759,  1615,  2389,    22,  2391,   370,   433,   370,
    2915,   338,   460,   416,    20,   370,     5,    22,   141,   599,
     370,   591,   370,   370,   338,   147,   450,  2761,  1006,   599,
     822,   823,  2766,   370,   458,     9,   370,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,   405,   231,   437,
     596,    20,   370,   334,  2223,    24,  2961,   599,  2963,   617,
     370,   332,   370,   980,   432,   857,   983,   625,   370,  2545,
     405,   863,   370,   370,     5,   370,   526,   370,   370,   432,
     530,   449,   370,   875,   534,  2870,  1213,  1369,   880,   599,
     370,   370,  2506,   437,   886,   520,   449,    71,    72,    73,
      74,    75,    76,  2907,   366,   370,    13,  2911,   417,   409,
     224,   420,   904,    91,  1383,   275,   142,   535,   454,  1605,
     146,  2906,  2117,   237,   492,   370,   918,   275,   455,   391,
     500,   365,   468,   367,   409,   444,   472,   514,   563,   492,
     932,   455,   409,  2877,  2425,   841,  2427,  2743,   484,  2430,
     404,  2432,   848,   409,   310,   464,   604,   224,    87,    88,
      89,   436,   437,   531,   437,  2550,    44,   350,  1144,  1438,
     237,   409,  1441,   303,   409,   623,   624,    25,   531,  2719,
     568,   409,   274,   540,  2969,  1804,   543,  2572,   591,   546,
     499,   351,   560,   985,   409,   643,   213,   989,   990,   991,
     323,   569,   409,   351,   437,    83,   409,   560,   213,   518,
     519,   599,  1004,   475,   450,  1007,   569,  1009,  1010,  2225,
    2226,  1013,  1487,   249,   407,   534,   252,   303,   409,  1723,
    1724,   512,    27,    28,   326,  1027,  1028,   564,   330,  1031,
    1032,  1033,  1034,  2977,  1036,   526,  1740,  1039,   274,  1743,
     564,  2003,  1534,   261,    25,   133,   605,   231,  1050,  1883,
    1052,   409,   436,   437,   573,   409,   274,   409,   217,    25,
     551,  1063,   605,  1065,  1066,  2488,  1068,  1069,  1070,  1071,
    1072,  1073,  1074,  1075,  1076,  1077,  1078,  1079,  1080,  1081,
    1082,  1083,  1084,   171,   599,   417,  2053,   606,  2050,  1570,
    1571,   535,    25,  1095,  1096,   567,   428,  3041,  1100,  1591,
    1102,   471,  2852,  2727,    25,  2729,   408,   579,   580,   600,
    2796,  1586,    25,   471,   341,   274,   588,    25,   450,    25,
     460,  1943,  1124,   437,   409,   457,   341,   493,  1130,  1131,
    1132,   455,   409,    25,  1280,   604,    25,   503,    25,  1141,
    1286,  1143,   535,  1145,  1146,  1967,    21,   471,  1150,   224,
     599,   436,   437,   604,   619,   620,    97,   626,   627,    25,
    2755,    25,   237,    37,  1480,   370,   350,   326,   486,    24,
      25,   330,   408,   340,   460,   626,   627,   495,   455,   618,
     268,  2064,   621,   622,   409,  1187,   370,  2873,   581,   599,
     408,  1193,    24,    25,   471,  1322,    71,    72,    73,    74,
      75,    76,    25,  1522,  1331,  2955,  1698,  2957,   409,   602,
    1212,   409,    87,    88,    89,  1217,   405,  1219,  1220,   436,
     437,   539,  1224,   407,   542,     5,  1228,  1229,  1707,   266,
     267,  1927,   314,  2828,   370,   345,   249,  1239,   599,   252,
    2619,   254,    25,   325,  2042,  2886,  2044,  2045,   336,   408,
     237,  1253,  1254,  1255,   621,   622,   344,   628,   629,   200,
     348,   274,    24,    25,   604,   628,   629,   208,  1760,   370,
    1762,   284,    20,   214,  1970,   216,   405,  1279,  1594,  1771,
    1282,  1283,  2923,   623,   624,  1287,   227,  1289,   340,  1291,
     303,   370,   142,    20,  1955,   377,   146,   385,    20,  1615,
    1364,    25,    25,   643,    25,  1327,   249,    25,    25,   252,
     392,   254,   409,   326,   255,    25,    25,   330,   604,    25,
     170,   599,   432,    71,    72,    73,    74,    75,    76,   370,
     271,   274,  1334,     5,   409,   276,   370,   623,   624,   449,
     591,   284,   438,   646,  1346,   842,   843,   288,   370,   846,
     847,   535,   281,   228,   295,  1357,   231,   643,  1360,  2167,
     303,   417,   370,   370,   370,   453,   370,     5,   603,  1848,
     370,   281,   428,  2752,   370,   370,    77,  1379,  1380,  1381,
     455,   603,   492,   326,  2218,  1387,   370,   330,  2846,    17,
      18,    19,    20,    21,   450,   408,   471,   581,   370,   249,
     482,   457,   252,   599,   492,    24,  3001,   437,   599,   596,
    1412,  1413,  1414,     8,  1416,   405,    24,   409,   602,   458,
     504,   531,   399,   409,   274,   245,   409,   249,   516,   142,
     252,   409,   254,   146,     4,     5,     6,     7,     8,     9,
    1442,    11,  1444,    17,    18,    19,    20,   460,  2410,  2416,
     560,   409,   274,   409,   409,   409,  1458,   170,   409,   569,
     409,   409,   284,   409,   409,   408,   196,   409,   438,   409,
     200,   409,   560,   409,  1476,   350,  2934,   409,   409,   409,
    1482,   569,  1484,  1485,  1486,  1487,   592,   593,   594,   595,
     365,   409,   409,   409,   369,  2953,     5,    71,    72,    73,
      74,    75,    76,   591,   326,   112,   409,   409,   330,   450,
     597,   597,   574,    92,  1516,   399,   457,   460,   438,  1521,
     101,   102,   638,   104,   105,  1527,   638,   409,   109,   305,
    1532,     8,   407,  2956,  1536,   575,   249,   420,   479,   252,
    1542,     5,     5,   484,   362,   126,   127,   409,  1550,   409,
     433,  3009,   131,   409,    24,  1557,   409,  1559,   408,   323,
     435,   274,   409,   144,   145,   409,  2058,   568,  1570,  1571,
       8,   178,   557,   180,   107,   554,    13,   460,     5,   454,
       5,   638,   399,   116,  1586,   638,   408,    45,   195,    25,
     409,    25,   125,   476,   477,   409,   203,   130,    70,   482,
     207,   437,   485,  1605,   437,   409,    25,   409,     5,  2101,
     311,  1613,    16,    17,    18,    19,    20,    21,   409,    20,
     409,  1937,  1624,   324,  2585,   232,   599,  1943,   409,   568,
     643,   409,    20,    20,   215,  1637,  1638,   574,   460,  1641,
     450,   174,   605,   409,   409,  2479,   605,   641,  2477,   182,
     409,  1967,   409,   605,   604,  1657,   329,  1659,  1660,   535,
     535,  1663,  1664,    17,     5,    18,    25,    71,    72,    73,
      74,    75,    76,    71,    72,    73,    74,    75,    76,    25,
     131,   197,    24,    87,    88,    89,   557,   388,  1690,    17,
      18,    19,    20,  1695,   395,   408,   568,  1699,   320,     5,
     643,   602,   345,   461,  1706,   238,   461,   329,   129,   525,
     525,     5,    25,   443,   444,  1717,   378,   300,    29,   525,
      25,   409,   409,  2204,  2428,  2206,  2422,   602,   409,   409,
     263,   353,   409,   434,   356,    24,   643,   270,   599,   272,
     525,   370,   555,    71,    72,    73,    74,    75,    76,   282,
     370,  1753,   374,  1755,   370,   370,   370,  1759,   459,   370,
     370,  1763,  1764,  1765,  1766,    25,  1768,   370,   469,   470,
     370,   370,  1774,  1775,   370,   308,  1778,  1779,     5,   370,
     605,  2484,     5,   316,   485,  1787,  2195,   596,     5,   432,
     101,   102,     5,   104,   105,  1797,   370,   558,   109,   599,
       5,   462,   605,   370,   409,   506,   449,   537,   509,   510,
      17,    18,    19,    20,   515,   126,   127,   547,   604,   409,
     353,   643,     5,    25,   228,   532,    25,   231,   514,   409,
      45,   304,     5,   144,   145,   416,   370,   409,   417,   370,
     419,   420,  1844,   370,  1846,   339,   379,   575,   599,   492,
      13,   605,   639,   529,   433,  2689,  1858,   525,   480,     5,
      25,   227,   450,  2697,    71,    72,    73,    74,    75,    76,
      79,   572,   451,   409,   599,   454,    17,    18,    19,    20,
     409,   460,  1884,   584,   417,   464,   605,     5,   531,   468,
     604,   405,    24,   472,   405,   428,   439,   476,   477,   439,
     479,   409,   618,   482,   409,   484,   485,   486,   409,  2225,
    2226,   533,   409,   492,   409,   370,   495,   560,   540,   409,
     409,    25,  2414,   502,     8,  1927,   569,     5,   507,     5,
      71,    72,    73,    74,    75,    76,   515,  1992,   370,  1941,
      25,    29,  1944,  1998,   409,   605,   350,   526,   370,  1951,
    1952,   530,  2444,   370,   599,   534,  1958,     5,  1960,   599,
     539,   365,   599,   542,     8,   369,  1968,   304,  1970,   112,
     437,   323,    59,  2669,   323,   599,   706,  1979,   323,  2316,
    2317,  2318,   339,  2320,  2321,  2322,  2323,  2324,  2325,   409,
    2465,   404,  2329,    20,   527,   528,   529,  2472,   409,  1992,
    2002,   409,   409,   407,  2006,  1998,  2008,   540,  2842,   409,
    2713,     5,   630,   101,   102,   409,   104,   105,   409,    29,
     399,   109,    25,   753,   335,   345,  2028,    17,    18,    19,
      20,   435,     5,     5,     5,   178,     5,   180,   126,   127,
      25,   596,   370,     5,    54,   409,   133,   134,   574,  2051,
     454,  2053,   195,   574,   599,   562,   144,   145,   599,  2061,
     203,     5,  2064,  2885,   207,  2067,     5,     5,   370,   409,
       5,     7,    25,   384,    25,   218,    25,   605,     8,   599,
     370,    71,    72,    73,    74,    75,    76,   370,   605,   232,
      40,   101,   102,   370,   104,   105,   370,    25,   370,   109,
     187,    17,    18,    19,    20,  2107,   193,   605,  2110,   605,
      20,   644,   432,  2115,    19,    20,   126,   127,   605,   370,
     370,   370,  2818,   370,  2820,     5,  2128,   545,  2130,   449,
    2132,   535,  2966,   253,   144,   145,    20,  2139,   370,     5,
    2142,     5,   525,    20,  2146,     5,   219,   550,  2150,  2937,
    2938,  2939,  2940,  2941,  2942,    71,    72,    73,    74,    75,
      76,   437,   112,   370,   370,  2167,    71,    72,    73,    74,
      75,    76,   492,  2175,   370,   605,   409,   264,   419,   266,
    2182,  2183,  2184,  2185,  2186,  2187,   370,   599,   409,   450,
       6,   605,   922,  2195,   532,  1726,   532,   189,   602,  2691,
     605,   603,  2204,    24,  2206,   215,  1737,  2688,   603,    24,
      24,   531,   345,  1744,   598,   425,    24,  1748,    24,  1750,
    1751,  1752,    25,    25,    25,     7,    25,    25,   178,   370,
     180,   450,   409,   409,  2236,    17,    18,    19,    20,  2241,
     560,    25,   275,   599,    25,   195,     5,   826,   370,   569,
     247,   370,   339,   203,   370,   447,   504,   207,     5,  2584,
      14,    15,    16,    17,    18,    19,    20,    21,   370,   409,
     529,    20,   399,  2459,     5,   345,   219,   323,   370,   405,
       5,   370,   232,   419,   323,    20,  2288,   118,     5,    71,
      72,    73,    74,    75,    76,  2297,  2298,  2299,    13,   432,
      13,  2997,   441,  2305,   599,     5,   189,   370,    20,    25,
     370,   370,  2500,   370,    25,     5,   449,    71,    72,    73,
      74,    75,    76,    26,   347,   335,   310,   598,   352,   547,
      25,   220,   370,    87,    88,    89,   370,   409,   605,   525,
     554,  2833,   429,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,   492,
     239,   218,   432,   218,   409,  2367,  3069,  2369,   420,    25,
     949,   950,   951,   437,   384,   138,   463,   605,  2380,   449,
     370,   370,   469,  2385,   471,   426,     5,  2389,   475,  2391,
     371,   478,   155,   156,   481,   409,   599,   605,   531,   278,
     163,   605,   370,    13,   491,   345,   416,   405,    71,    72,
      73,    74,    75,    76,  2416,     5,     5,    24,   297,    20,
    2422,   959,   492,   510,    87,    88,    89,   560,   220,   409,
    1160,   518,   519,   520,   197,  2437,   569,   524,   370,     5,
    2145,   370,  2061,   206,   370,   532,    17,    18,    19,    20,
    3019,  2067,  1834,  1230,   370,  2457,    36,   336,  2460,  2461,
     547,   531,  1543,  2465,    38,   363,  2468,  1775,  1781,   348,
    2472,  2128,   235,   286,   228,   141,   145,   231,   395,   358,
     209,  1326,   287,  1213,   280,  1327,  2488,   352,   211,   370,
     560,   212,   432,   345,   382,   315,  2498,   376,   384,   569,
      71,    72,    73,    74,    75,    76,  3009,   386,   445,   449,
    2512,  1755,  2514,  2515,  2516,  2517,   524,   280,  1516,   314,
    1635,   956,  1642,   402,  2526,  1765,  1486,  1002,  2529,  2199,
     467,  1261,  1880,  1253,  1566,  3033,  1769,  1581,  2213,  2705,
    1146,  2543,    23,  2545,  1256,   117,  2215,    29,  2550,  2606,
      52,    53,   492,    29,    56,    57,    58,  2559,   481,   322,
    1548,  1554,  2564,   442,   266,   228,   648,   676,   231,  2885,
    2572,  1240,  2574,   923,   511,  2709,  1261,  1557,  2603,  2781,
     432,  1137,  1184,  1597,   521,   522,  2953,   466,   525,  2183,
    1127,   531,   529,  2791,   531,  2356,   350,   449,   535,   536,
     875,  2354,   481,  1212,  2338,  1059,  2001,  1013,  1759,   488,
    1363,   365,   491,  2765,  1340,   369,  1937,  3037,  3001,   706,
     560,  1971,  2624,  2891,  2626,  2002,  2388,  1663,  2630,   569,
    2632,  2410,   511,  2008,  2669,   514,  2423,   516,  2367,  2369,
     492,  2907,  2644,  2626,  2018,  1559,  1279,  2810,  2299,   952,
    2829,  2747,  2830,   407,   156,  2237,   535,  2241,  2999,  2732,
    2868,   163,  2911,  1275,  1243,   361,   948,  2669,  2559,  1695,
      -1,  2673,    -1,  2675,   553,    -1,  1142,    -1,    -1,   531,
      -1,   435,    -1,    -1,    -1,    -1,  2688,   350,   775,    -1,
      -1,  2693,    -1,    -1,    -1,   197,    -1,    -1,    -1,  1613,
     454,    -1,   365,    -1,   206,    -1,   369,   370,   560,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   569,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    2732,   818,    -1,   235,   236,  2737,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   407,   832,   833,   834,    -1,   836,
      -1,   838,   839,  2755,    -1,    -1,    -1,   844,   845,  2761,
      -1,    -1,    -1,  2765,  2766,    -1,    -1,    -1,    -1,    -1,
      -1,  2773,   435,    -1,    -1,  1313,  1314,    -1,   280,    -1,
      -1,   535,  1320,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   454,    -1,    -1,  2796,    -1,    -1,    -1,    -1,    -1,
      -1,   888,    -1,  1717,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   899,    -1,    -1,    -1,  2818,    -1,  2820,    -1,
     322,  2823,    -1,    -1,    -1,    -1,  2828,    -1,  2830,  1559,
      -1,    -1,    -1,    -1,    -1,   922,   923,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   931,    -1,    -1,    -1,   602,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     947,   948,    -1,    -1,    -1,    -1,  2868,    -1,    -1,    -1,
      -1,  2873,   535,  2875,    -1,  2877,   378,    -1,    -1,    -1,
      -1,  2883,    -1,  1613,  2886,   822,    -1,    -1,    -1,  2891,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1480,    -1,    -1,    -1,  2907,    -1,    -1,  2910,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1006,
     857,  2923,    -1,    -1,    -1,    -1,   863,  1657,    -1,    -1,
      -1,    -1,    -1,    -1,  1664,    -1,    -1,    -1,   875,   602,
      -1,    -1,    -1,   880,  1858,    -1,  2948,  2949,    -1,    19,
      20,    21,    -1,    -1,  2956,    17,    18,    19,    20,    21,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1056,
      -1,    -1,    -1,    -1,    -1,  2977,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1717,  1526,    -1,
      -1,    -1,    -1,    -1,    -1,  2997,    -1,  2999,    -1,  3001,
      -1,    71,    72,    73,    74,    75,    76,    -1,    -1,    71,
      72,    73,    74,    75,    76,  1594,    -1,    87,    88,    89,
      -1,    -1,    -1,    -1,  1562,    87,    88,    89,    -1,    -1,
    1117,    -1,    -1,    -1,    -1,  3037,  1615,    -1,  1125,  3041,
    1127,  1128,  1129,    -1,    -1,   712,   713,    -1,    -1,  1136,
    1137,    -1,  3054,  1140,    -1,    -1,    -1,  1144,    -1,    -1,
    1147,   728,    -1,    -1,    -1,    -1,    -1,   734,   735,    -1,
      -1,    -1,   739,  1160,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   749,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  2006,    -1,    -1,    -1,    -1,    -1,    -1,  1186,
      -1,    -1,    -1,    -1,    -1,   607,   608,   609,   610,   611,
     612,   613,   614,   615,   616,  1694,    -1,    -1,    -1,  1849,
    1850,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1858,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1226,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   228,    -1,
      -1,   231,  1249,    -1,    -1,    -1,   228,    -1,    -1,   231,
      -1,    -1,    -1,  1260,  1261,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    -1,    -1,  1130,  1131,  1132,    -1,    -1,    -1,    -1,
      71,    72,    73,    74,    75,    76,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1150,  1944,    -1,    87,    88,    89,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1315,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      71,    72,    73,    74,    75,    76,    -1,    -1,    -1,    -1,
    1187,    -1,    -1,    -1,    -1,    -1,    87,    88,    89,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2182,  2183,
    2184,  2185,  2186,  2187,    -1,  1212,  2006,    -1,  2008,    -1,
     350,    -1,  1369,    -1,  1863,    -1,    -1,    -1,   350,    -1,
    1828,  1829,  1229,    -1,    -1,   365,    -1,    -1,    -1,   369,
      -1,  1839,  1239,   365,    -1,    -1,    -1,   369,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2048,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  2241,    -1,    -1,
      71,    72,    73,    74,    75,    76,    -1,   407,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   407,    87,    88,    89,  1928,
      -1,  1889,  1890,  1891,  1892,    -1,    -1,   228,  1937,    -1,
     231,  1028,    -1,    -1,  1943,   435,  1904,    -1,    -1,  1036,
      -1,    -1,  1039,   435,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   454,  1052,    -1,    -1,  1967,    -1,
      -1,    -1,   454,    42,    -1,    -1,  1063,   228,  1065,  1066,
     231,  1068,  1069,  1070,  1071,  1072,  1073,  1074,  1075,  1076,
    1077,  1078,  1079,  1080,  1081,  1082,  1083,  1084,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1514,  1095,  1096,
      -1,    -1,    -1,  1100,    -1,  1102,  1523,    -1,    -1,    -1,
      -1,    -1,  1980,  1981,    -1,  2024,    -1,  1534,    -1,  1987,
    1988,    -1,  2182,  2183,  2184,  2185,  2186,  2187,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   535,  2380,  1554,    -1,    -1,
      -1,  2385,    -1,   535,    -1,    -1,    -1,    -1,    -1,   350,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   228,    -1,    -1,
     231,    -1,    -1,    -1,   365,    -1,    -1,    -1,   369,    -1,
      -1,    -1,    -1,    -1,  1591,    -1,  1593,    -1,    -1,    -1,
    1597,  2241,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   350,
      -1,  1458,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   602,    -1,   365,    -1,   407,    -1,   369,   370,
     602,    -1,  1629,    -1,    -1,  1482,    -1,    -1,    -1,  1486,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   435,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   407,    -1,    -1,  1516,
    2118,  2119,    -1,   454,    -1,    -1,  2316,  2317,  2318,  2127,
    2320,  2321,  2322,  2323,  2324,  2325,    -1,  2135,  2512,  2329,
    2514,  2515,  2516,  2517,   435,  1542,    -1,    -1,    -1,   350,
      -1,  1698,    -1,    -1,    -1,  2153,  2154,    -1,    -1,    -1,
      -1,    -1,    -1,   454,   365,    -1,    -1,    -1,   369,   278,
      -1,  2545,    -1,    -1,    -1,    -1,    -1,  2367,    -1,  2369,
      -1,    -1,    -1,    -1,    -1,    -1,  2225,  2226,    -1,    -1,
    2380,    -1,    -1,    -1,    -1,  2385,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   535,    -1,   407,  2205,    -1,  2207,
      -1,    -1,    -1,  1760,    -1,  1762,  2214,    -1,  2216,    -1,
      -1,    -1,    -1,    -1,  1771,    -1,    -1,   336,    -1,    -1,
      -1,    -1,    -1,    -1,   435,    -1,    -1,    -1,    -1,   348,
      -1,    -1,    -1,    -1,   535,    -1,    -1,    -1,    -1,   358,
      -1,    -1,    -1,   454,    -1,    -1,  2630,    -1,  2632,    -1,
    1387,    -1,  1809,    -1,    -1,    -1,    -1,   376,    -1,    -1,
      -1,   602,    -1,    -1,    -1,    -1,    -1,   386,    -1,    -1,
     389,    -1,    -1,    -1,    -1,  1412,  1413,  1414,    -1,  1416,
      -1,  1838,    -1,   402,  2484,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1699,    -1,    -1,    -1,    -1,    -1,  2306,  2307,
      -1,   602,  2310,  2311,    -1,  1442,    -1,    -1,    -1,    -1,
      -1,    -1,  2512,  2362,  2514,  2515,  2516,  2517,    -1,    -1,
      -1,    -1,    -1,    -1,   535,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   451,    -1,    -1,    -1,  2344,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  2545,    -1,    -1,  2732,    -1,
      -1,    -1,    -1,  2737,    -1,    -1,  1763,  1764,  1765,  1766,
      -1,    -1,   481,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   491,    -1,    -1,    -1,    -1,  2761,    -1,    -1,
    1787,    -1,  2766,    -1,  1521,    -1,    -1,    22,    -1,    -1,
    1527,   602,   511,    -1,    -1,   514,    -1,   516,    -1,  1536,
      -1,    -1,    -1,    -1,    -1,    -1,    41,    -1,    -1,    -1,
      -1,    -1,  2796,    -1,    20,    21,    -1,    -1,    -1,    -1,
      -1,  1978,    -1,    -1,  2624,   544,  2626,    -1,    -1,    -1,
    2630,  2631,  2632,    -1,   553,    70,    -1,  1844,    -1,  2823,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    2458,    -1,    -1,    -1,  2462,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  2513,    71,    72,    73,    74,    75,
      76,    -1,    -1,    -1,    -1,    -1,    -1,   112,    -1,    -1,
      -1,    87,    88,    89,    -1,    -1,  2494,    -1,    -1,  2873,
      -1,  2875,    -1,  2877,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  2058,    -1,  2552,    -1,    -1,    -1,   142,    -1,    -1,
      -1,   146,    -1,  2713,    -1,    -1,    -1,    -1,    -1,  2527,
      -1,    -1,    -1,    -1,    -1,    -1,  2910,    -1,    -1,    -1,
      -1,    -1,  2732,    -1,    -1,   170,    -1,  2737,    -1,    -1,
      -1,    -1,    -1,   178,  2101,   180,    -1,    -1,    -1,    -1,
      -1,  1958,    -1,  1960,   189,    -1,    -1,    -1,    -1,    -1,
     195,  2761,    -1,    -1,    -1,    -1,  2766,    -1,   203,    -1,
      -1,    -1,   207,    -1,    -1,    -1,    -1,  2134,   213,    -1,
      -1,    -1,   217,   218,   219,   220,  2143,    -1,  2145,    -1,
    2147,    -1,    -1,  2977,    -1,    -1,  2796,   232,    -1,    -1,
      -1,    -1,  2159,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    -1,   249,  2999,  1753,   252,  1755,   254,
      -1,    -1,   228,  2823,    -1,   231,   261,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   274,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   284,
      -1,    -1,    -1,  3037,    -1,    -1,    -1,  3041,    -1,    -1,
      -1,    -1,    71,    72,    73,    74,    75,    76,   303,   304,
      -1,    -1,     5,  2873,    -1,  2875,    -1,  2877,    87,    88,
      89,    -1,    -1,   318,    -1,    -1,  2886,    -1,    -1,    -1,
      -1,   326,    -1,    -1,    -1,   330,    -1,    -1,    -1,    -1,
    2107,    -1,    -1,  2110,   339,   340,   341,  2907,    -1,    -1,
    2910,  2911,    -1,    -1,    -1,    -1,  2724,    -1,    -1,    -1,
      -1,    -1,    -1,  2923,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    17,
      18,    -1,    20,  2300,   350,    23,    24,    25,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   365,
    2167,    -1,    -1,   369,    -1,    43,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   408,    -1,    -1,    -1,  2977,    -1,    -1,
      -1,    -1,    -1,  2340,   419,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  2353,    -1,    -1,  2999,
      -1,   407,    -1,    -1,    -1,    17,    18,    19,    20,    -1,
      -1,    -1,    -1,    -1,    26,    -1,    -1,    -1,    -1,   228,
      -1,    -1,   231,    -1,    -1,   460,    -1,    -1,    -1,   435,
      -1,    -1,    -1,    -1,    -1,    -1,  2885,  3037,    -1,    -1,
      -1,  3041,    -1,    -1,    -1,  2853,    -1,    -1,   454,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  2414,    -1,    71,
      72,    73,    74,    75,    76,    -1,    -1,    -1,    -1,  3069,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   521,  2444,  2896,  2897,
      -1,  2899,    -1,  2901,  2902,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  2459,    -1,    -1,    -1,   239,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   557,    -1,    -1,    -1,    -1,  2484,    -1,   535,
    2067,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   350,    -1,  2500,    -1,   278,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   365,  2965,    -1,    -1,
     369,    -1,    -1,    -1,   297,    -1,    -1,    -1,    -1,   604,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  2985,    -1,  2987,
      -1,    -1,    -1,   618,   619,   620,   621,   622,   623,   624,
      -1,   626,   627,    -1,    -1,   273,   602,    -1,   407,    -1,
      -1,    -1,  2139,   336,  2561,  2142,    -1,    -1,   643,    -1,
      -1,    -1,    -1,  2150,    -1,   348,  3024,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   358,   435,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    3048,  3049,    -1,   376,  3052,   454,  2603,   259,    -1,    -1,
      -1,    -1,    -1,   386,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  2468,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   402,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   299,   300,   301,
      -1,  2498,    -1,    -1,    -1,    -1,   374,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   442,
      -1,   389,   324,    -1,    -1,    -1,    -1,    -1,    -1,  2526,
     332,    -1,    -1,    -1,    -1,   337,   535,    -1,   406,    -1,
      -1,   409,    -1,   466,  2691,    -1,    -1,    -1,    -1,    -1,
     352,    -1,    -1,   421,   422,   357,    -1,   359,   481,    -1,
      -1,  2708,  2709,    -1,   366,   488,  2713,   369,   491,    -1,
     372,    -1,    -1,   375,    -1,    -1,   378,    -1,    -1,    -1,
      -1,   383,    -1,    -1,    -1,    -1,    -1,    -1,   511,    -1,
      -1,   514,    -1,   516,    -1,   463,    -1,    -1,    -1,   401,
      -1,    -1,    -1,   602,    -1,    -1,    -1,   475,    -1,    -1,
      -1,    -1,   535,    -1,    -1,   417,    -1,    -1,   420,   421,
    2767,    -1,    -1,    -1,    -1,   427,    -1,    -1,    -1,    -1,
     553,    -1,    -1,    -1,  2781,    -1,   438,    -1,    -1,  2786,
      -1,  2788,    -1,    -1,    -1,    -1,    -1,    -1,   516,    -1,
      -1,    -1,   454,    -1,    -1,    -1,    -1,    -1,    -1,   461,
      -1,    -1,    -1,    -1,    -1,    -1,   468,    -1,    -1,   471,
     472,   473,    -1,   475,   476,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  2829,    -1,    -1,    -1,  2833,   555,    -1,    -1,
     492,    -1,    -1,    -1,    -1,    -1,  2693,    -1,    -1,   567,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    2437,   579,   580,   515,   516,   517,   518,    -1,   520,    -1,
     588,    -1,    -1,   591,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   599,    -1,    29,    -1,   537,   538,    33,    34,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      46,    -1,    48,    -1,    -1,    -1,    -1,    -1,   560,    -1,
      -1,  2488,    -1,    -1,    -1,    -1,    62,   569,   570,    -1,
     572,    -1,    -1,    69,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    80,    81,    82,    -1,    -1,    -1,
    2937,  2938,  2939,  2940,  2941,  2942,    -1,    -1,    -1,    -1,
      96,    -1,    98,    99,   100,   101,   102,   103,   104,   105,
     106,    -1,   108,   109,   110,   111,    -1,    -1,    -1,    -1,
      -1,   117,    -1,    -1,   120,    -1,   122,   123,   124,    -1,
     126,   127,   634,    -1,    -1,    -1,   132,    -1,   134,   135,
      -1,   137,    -1,   139,   140,    -1,    -1,   143,   144,   145,
      -1,    -1,   148,   149,   150,    -1,   152,   153,    -1,    -1,
      -1,   157,   158,    -1,   160,    -1,    -1,    -1,   164,    -1,
     166,   167,    -1,    -1,    -1,    -1,   172,    -1,    -1,    -1,
     176,    -1,    -1,   179,    -1,   181,    -1,   183,    -1,   185,
      -1,   187,   188,    -1,   190,   191,   192,    -1,    -1,    -1,
     196,    -1,   198,   199,    -1,   201,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   209,   210,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  3069,    -1,    -1,    -1,   222,    -1,    -1,   225,
     226,    -1,    -1,   229,   230,    -1,    -1,   233,   234,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   242,   243,   244,    -1,
     246,  2948,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     256,   257,   258,    -1,   260,    -1,    -1,    -1,   264,   265,
      -1,    -1,    -1,   269,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   277,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   285,
     286,   287,    -1,    -1,    -1,    -1,    -1,   293,   294,    -1,
      -1,    -1,    -1,   299,    -1,    -1,   302,    -1,    -1,    -1,
     306,   307,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   317,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,   335,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   343,    -1,    -1,
      -1,    -1,    -1,   349,    -1,    -1,    -1,  3054,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    -1,    -1,   372,    -1,    -1,    -1,
      -1,    -1,    -1,   379,    -1,   381,   382,    -1,    71,    72,
      73,    74,    75,    76,   390,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    87,    88,    89,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    71,    72,    73,    74,    75,    76,    -1,
      -1,    -1,    -1,   429,    -1,    -1,    -1,    -1,    -1,    87,
      88,    89,    -1,    -1,   440,    -1,    -1,    -1,   444,    -1,
      -1,    -1,   448,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   472,   473,    -1,    -1,
      -1,   477,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   489,    -1,    -1,    -1,    -1,    -1,   495,
     496,   497,   498,    -1,    -1,   501,    -1,    -1,    -1,   505,
      -1,    -1,    -1,    -1,    -1,    -1,   512,   513,    71,    72,
      73,    74,    75,    76,    -1,    -1,    -1,    -1,   524,  2956,
     526,    -1,    -1,    -1,    87,    88,    89,    -1,    -1,    -1,
      -1,   537,    -1,   539,    -1,   228,   542,    -1,   231,    -1,
      -1,    -1,   548,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   574,    -1,
     228,   577,    -1,   231,    -1,    -1,    -1,   583,    -1,    -1,
     586,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   601,    -1,    -1,    -1,    -1,
      -1,    -1,   608,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   631,   632,   633,   634,   635,
     636,   637,    -1,    -1,   640,    -1,   642,    -1,   644,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   350,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   228,    -1,    -1,   231,    -1,
      -1,    -1,   365,    -1,    -1,    -1,   369,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   350,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   365,    -1,    -1,
      -1,   369,   370,    -1,   407,    -1,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   435,    -1,    -1,    -1,    -1,    -1,    -1,   407,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   454,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   435,    -1,    -1,
      -1,    71,    72,    73,    74,    75,    76,   350,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   454,    87,    88,    89,
      -1,    -1,   365,    -1,    -1,    -1,   369,   370,    -1,    -1,
      -1,    -1,    -1,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   535,    -1,   407,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   435,    -1,    -1,    -1,    -1,   535,    71,    72,
      73,    74,    75,    76,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   454,    -1,    -1,    87,    88,    89,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   602,
      71,    72,    73,    74,    75,    76,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    87,    88,    89,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   228,    -1,
      -1,   231,    -1,    -1,   602,    -1,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   535,    -1,    -1,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    71,    72,    73,    74,    75,    76,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    87,    88,    89,
      -1,    -1,    -1,    -1,    -1,   228,    -1,    -1,   231,   602,
      71,    72,    73,    74,    75,    76,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    87,    88,    89,    -1,
     350,    -1,    -1,    -1,    -1,    -1,    -1,   228,    -1,    -1,
     231,    -1,    -1,    -1,    -1,   365,    -1,    -1,    -1,   369,
     370,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   407,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   435,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   350,    -1,    -1,
      -1,    -1,    -1,    -1,   454,    -1,    -1,    -1,   228,    -1,
      -1,   231,   365,    -1,    -1,    -1,   369,   370,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   350,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   228,    -1,    -1,
     231,    -1,    -1,    -1,   365,    -1,    -1,    -1,   369,   370,
      -1,    -1,    -1,    -1,   407,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   435,    -1,    -1,   535,   407,    -1,    -1,    -1,
      17,    18,    -1,    20,    -1,    -1,    23,    24,    25,    -1,
      -1,   454,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   435,    -1,    43,    -1,    -1,    71,
      72,    73,    74,    75,    76,    -1,    -1,    -1,    -1,    -1,
     350,    -1,    -1,   454,    -1,    87,    88,    89,    -1,    -1,
      17,    18,    -1,    20,    -1,   365,    23,    24,    25,   369,
     370,    -1,   602,    -1,    -1,    -1,    -1,    -1,    -1,   350,
      -1,    -1,    -1,    -1,    -1,    -1,    43,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   365,    -1,    -1,    -1,   369,    -1,
      -1,    -1,   535,    -1,    -1,    -1,    -1,   407,    -1,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   535,   435,   407,    -1,    -1,    -1,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    -1,   454,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   435,    -1,    -1,    -1,    -1,   602,
      -1,    -1,    71,    72,    73,    74,    75,    76,    -1,    -1,
      -1,    -1,    -1,   454,    -1,    -1,    -1,    -1,    87,    88,
      89,    -1,    -1,    -1,    -1,    -1,   228,    -1,    -1,   231,
      -1,   602,    71,    72,    73,    74,    75,    76,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    87,    88,
      89,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    -1,    -1,   535,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   535,    -1,   273,    15,    16,    17,
      18,    19,    20,    21,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    71,    72,    73,    74,    75,    76,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    87,    88,
      89,    -1,   602,    71,    72,    73,    74,    75,    76,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   273,    -1,   350,    87,
      88,    89,    -1,    71,    72,    73,    74,    75,    76,   228,
      -1,   602,   231,   365,    -1,    -1,    -1,   369,    -1,    87,
      88,    89,    -1,    17,    18,    -1,    -1,    -1,    -1,    23,
      24,    25,    26,    -1,    -1,    -1,    -1,    -1,    -1,   228,
      -1,    -1,   231,    -1,    38,    -1,    -1,   374,    -1,    43,
      44,    -1,    -1,    -1,    -1,   407,    50,    -1,    -1,    -1,
      -1,    -1,   389,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   406,
      -1,    -1,   409,   435,    78,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   421,   422,    -1,   374,    -1,    -1,
      -1,    -1,   454,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   389,    -1,    -1,    -1,    -1,    -1,    -1,   228,
      -1,    -1,   231,   450,    -1,    -1,    -1,    -1,    -1,   406,
      -1,   350,   409,    -1,    -1,    -1,   463,    -1,    -1,    -1,
     228,    -1,    -1,   231,   421,   422,   365,    -1,   475,    -1,
     369,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    17,    18,
     228,   350,    -1,   231,    23,    24,    25,    26,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   365,   171,    -1,    38,
     369,    -1,    -1,   535,    43,    44,   463,    -1,   407,   516,
      -1,    50,    -1,    -1,    -1,    -1,    -1,    -1,   475,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   435,    -1,   407,    78,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   555,    -1,
      -1,    -1,    -1,    -1,    -1,   454,    -1,    -1,    -1,   516,
     567,   350,    -1,    -1,    -1,    -1,   435,    -1,    -1,    -1,
     602,    -1,   579,   580,   581,    -1,   365,    -1,    -1,    -1,
     369,   588,   350,    -1,   591,   454,    -1,    -1,    -1,    -1,
      -1,    -1,   599,    -1,   268,    -1,    -1,   365,   555,   273,
      -1,   369,   350,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     567,    -1,    -1,    -1,    -1,    -1,    -1,   365,   407,    -1,
      -1,   369,   579,   580,   581,    -1,    -1,   301,    -1,    -1,
      -1,   588,   171,    -1,   591,    -1,   535,    -1,    -1,   407,
      -1,    -1,   599,    -1,    -1,    -1,   435,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   407,
      -1,    -1,   336,    -1,    -1,   454,   535,   435,    -1,    -1,
      -1,    -1,    -1,    -1,   348,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   454,   435,    -1,    -1,
      -1,    -1,   366,    -1,    -1,    -1,    -1,   371,    -1,    -1,
     374,    -1,    -1,   602,    -1,    -1,   454,    -1,    -1,    -1,
      -1,   385,    -1,    -1,    -1,    -1,    -1,   391,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   401,    -1,   268,
      -1,    -1,   406,   602,   273,   409,    -1,    -1,   412,    -1,
      -1,    -1,    -1,    17,    18,    -1,   535,   421,   422,    23,
      24,    25,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   301,    -1,    38,    -1,    -1,   535,    -1,    43,
      44,    -1,    -1,    -1,    -1,    -1,    50,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   535,   462,   463,
      -1,    -1,    -1,   467,    -1,    -1,    -1,   336,    -1,    -1,
      -1,   475,    -1,    -1,    78,    -1,    -1,    -1,    -1,   348,
      -1,    -1,   486,   602,    -1,    -1,    -1,    -1,   492,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   366,    -1,    -1,
      -1,    -1,   371,    -1,   602,   374,    -1,    -1,    -1,    -1,
      -1,    -1,   516,    -1,    -1,    -1,   385,    -1,    -1,    -1,
      -1,    -1,   391,    -1,   602,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   401,    -1,    -1,    -1,    -1,   406,    -1,    -1,
     409,    -1,    -1,   412,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   421,   422,    -1,    -1,   560,    -1,    -1,    -1,
      -1,    -1,    -1,   567,    -1,   569,    -1,   171,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   579,   580,   581,    -1,    -1,
      -1,    -1,    -1,    -1,   588,    -1,    -1,   591,    -1,    -1,
      -1,    -1,    -1,    -1,   463,   599,    -1,    -1,   467,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   475,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   486,    -1,    -1,
      -1,    -1,    -1,   492,    17,    18,    -1,    -1,    -1,    -1,
      23,    24,    25,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    38,    -1,   516,    -1,    -1,
      43,    44,    -1,    -1,    -1,    -1,    -1,    50,    -1,    -1,
      -1,    -1,    -1,    -1,   268,    -1,    -1,    -1,    -1,   273,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    78,    -1,    -1,    -1,    -1,
      -1,   560,    -1,    -1,    -1,    -1,    -1,   301,   567,    -1,
     569,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     579,   580,   581,    -1,    -1,    -1,    -1,    -1,    -1,   588,
      -1,    -1,   591,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     599,    -1,   336,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   348,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    17,    18,    -1,    -1,    -1,    -1,    23,
      24,    25,   366,    -1,    -1,    -1,    -1,   371,    -1,    -1,
     374,    -1,    -1,    -1,    38,    -1,    -1,    -1,   171,    43,
      44,   385,    -1,    -1,    -1,    -1,    50,   391,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   401,    -1,    -1,
      -1,    -1,   406,    -1,    -1,   409,    -1,    -1,   412,    -1,
      -1,    -1,    -1,    -1,    78,    -1,    -1,   421,   422,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    17,    18,    -1,    20,    -1,    -1,    23,
      24,    25,    -1,    -1,    -1,    -1,    -1,    -1,   462,   463,
      -1,    -1,    -1,   467,    -1,    -1,    -1,    -1,    -1,    43,
      -1,   475,    -1,    -1,    -1,   268,    -1,    -1,    -1,    -1,
     273,    -1,   486,    -1,    -1,    -1,    -1,    -1,   492,    -1,
      -1,    -1,    -1,    17,    18,    -1,    -1,    -1,    -1,    23,
      24,    25,    -1,    17,    18,    -1,    20,   171,   301,    23,
      24,    25,   516,    -1,    38,    -1,    -1,    -1,    -1,    43,
      44,    -1,    -1,    -1,    -1,    -1,    50,    -1,    -1,    43,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   336,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    78,   348,   560,    -1,    -1,    -1,
      -1,    -1,    -1,   567,    -1,   569,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   366,    -1,   579,   580,   581,   371,    -1,
      -1,   374,    -1,    -1,   588,    -1,    -1,   591,    -1,    -1,
      -1,    -1,   385,    -1,    -1,   599,    -1,    -1,   391,    -1,
      -1,    -1,    -1,    -1,   268,    -1,    -1,    -1,   401,   273,
      -1,    -1,    -1,   406,    -1,    -1,   409,    -1,    -1,   412,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   421,   422,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   301,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   171,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     463,    -1,   336,    -1,   467,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   475,    -1,   348,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   486,    -1,   488,    -1,    -1,    -1,   492,
      -1,    -1,   366,    -1,    -1,    -1,   370,   371,    -1,    -1,
     374,    -1,    17,    18,    -1,    20,    -1,    -1,    23,    24,
      25,   385,    -1,   516,    -1,    -1,    -1,   391,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   401,    43,    -1,
      -1,    -1,   406,    -1,   268,   409,    -1,    -1,   412,   273,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   421,   422,    -1,
      -1,    -1,    -1,    -1,    17,    18,    -1,   560,    -1,    -1,
      23,    24,    25,    -1,   567,    -1,   569,   301,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    38,   579,   580,   581,    -1,
      43,    44,    -1,    -1,    -1,   588,    -1,    50,   591,   463,
     374,    -1,    -1,   467,    -1,    -1,   599,    -1,    -1,    -1,
      -1,   475,   336,    -1,    -1,   389,    -1,    -1,    -1,    -1,
      -1,    -1,   486,    -1,   348,    78,    -1,    -1,   492,    -1,
      -1,    -1,   406,    -1,    -1,   409,    -1,    -1,    -1,    -1,
      -1,    -1,   366,    -1,    -1,    -1,    -1,   371,   422,    -1,
     374,    -1,   516,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     374,   385,    -1,    -1,    -1,    -1,    -1,   391,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   389,    -1,   401,    -1,    -1,
      -1,    -1,   406,    -1,    -1,   409,    -1,    -1,   412,   463,
      -1,    -1,   406,    -1,    -1,   409,   560,   421,   422,    -1,
      -1,   475,    -1,   567,    -1,   569,    -1,    -1,   422,    -1,
      -1,    -1,    -1,    -1,    -1,   579,   580,   581,   171,    -1,
      -1,    -1,    -1,    -1,   588,    -1,    -1,   591,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   599,   450,    -1,   462,   463,
      -1,    -1,   516,   467,    -1,    -1,    -1,    -1,   462,   463,
      -1,   475,    17,    18,    -1,    20,    -1,    -1,    23,    24,
      25,   475,   486,    -1,    -1,    -1,    -1,    -1,   492,    -1,
      -1,    -1,    -1,    -1,    -1,   549,    -1,    -1,    43,    -1,
      -1,   555,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     564,   565,   516,   567,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   516,    -1,    -1,   579,   580,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   588,   268,    -1,   591,    -1,    -1,
     273,    -1,    -1,    17,    18,   599,    20,    -1,    -1,    23,
      24,    25,    -1,    -1,    77,    -1,   560,    -1,    -1,    -1,
      -1,   555,    -1,   567,    -1,   569,    -1,    -1,   301,    43,
      -1,    -1,    -1,   567,    -1,   579,   580,   581,    -1,    -1,
      -1,    -1,    -1,    -1,   588,   579,   580,   591,    -1,   374,
      -1,    -1,    -1,    -1,   588,   599,    -1,   591,    -1,    -1,
      -1,    -1,    -1,   336,   389,   599,    -1,    -1,    -1,    -1,
      17,    18,    -1,    20,    -1,   348,    23,    24,    25,    -1,
      -1,   406,    -1,    -1,   409,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   366,    -1,    -1,    43,   422,   371,    17,
      18,   374,    20,    -1,    -1,    23,    24,    25,    -1,    -1,
      -1,    -1,   385,    -1,    -1,    -1,    -1,    -1,   391,   182,
      -1,    -1,    -1,    -1,    -1,    43,    -1,    -1,   401,    -1,
      -1,    -1,    -1,   406,    -1,    -1,   409,   462,   463,   412,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   421,   422,
     475,    17,    18,    -1,    20,    -1,    -1,    23,    24,    25,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   238,    -1,    43,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     463,   516,    -1,    -1,   467,    -1,    -1,    -1,    -1,    -1,
     263,    -1,   475,    -1,    -1,    -1,    -1,    31,    -1,   272,
      -1,    -1,    -1,   486,    -1,    -1,    -1,    -1,    -1,   492,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     555,    -1,    -1,    -1,    -1,    59,    60,    -1,    -1,    -1,
      -1,    -1,   567,   516,    68,   308,    -1,    -1,   311,    -1,
      -1,    -1,    -1,   316,   579,   580,    -1,    -1,    -1,    -1,
      -1,   324,    -1,   588,    -1,    -1,   591,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   599,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   560,    -1,   374,
      -1,    -1,    -1,    -1,   567,    -1,   569,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   389,    -1,   579,   580,   581,    -1,
      -1,    -1,    -1,    -1,    -1,   588,    -1,    -1,   591,    -1,
      -1,   406,    -1,    -1,   409,   388,   599,    -1,    -1,    -1,
      -1,    -1,   395,    -1,    -1,    -1,    -1,   422,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   410,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     374,    -1,    -1,    -1,    -1,   450,    -1,    -1,    -1,    -1,
      -1,   434,    -1,    -1,    -1,   389,    -1,    -1,   463,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     475,    -1,   406,    -1,    -1,   409,   459,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   469,   470,   422,    -1,
      -1,    -1,    -1,    -1,    -1,   239,    -1,    -1,    -1,    -1,
      -1,    -1,   485,    -1,    -1,    -1,    -1,   374,    -1,    -1,
      -1,   516,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   389,   506,    -1,    -1,   509,   510,   462,   463,
      -1,    -1,   515,    -1,   278,    -1,   374,    -1,    -1,   406,
      -1,   475,   409,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     555,   389,    -1,   297,    -1,   422,    -1,    -1,    -1,    -1,
      -1,    -1,   567,    -1,    -1,    -1,    -1,    -1,   406,   313,
      -1,   409,    -1,    -1,   579,   580,    -1,    -1,    -1,    -1,
      -1,    -1,   516,   588,   422,    -1,   591,    -1,   374,   572,
      -1,    -1,   336,    -1,   599,   462,   463,    -1,    -1,   582,
      -1,   584,    -1,   389,   348,    -1,    -1,    -1,   475,    -1,
      -1,    -1,    -1,    -1,   358,    -1,    -1,    -1,    -1,    -1,
     406,   555,    -1,   409,   462,   463,    -1,    -1,    -1,    -1,
      -1,    -1,   376,   567,    -1,    -1,   422,   475,    -1,    -1,
      -1,    -1,   386,    -1,    -1,   579,   580,    -1,    -1,   516,
      -1,    -1,    -1,    -1,   588,    -1,    -1,   591,   402,    -1,
      -1,    -1,    -1,    -1,    -1,   599,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   463,   516,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   555,   475,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   442,    -1,
     567,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   579,   580,    -1,    -1,    -1,   555,    -1,    -1,
      -1,   588,   466,    -1,   591,    -1,    -1,    -1,    -1,   567,
     516,    -1,   599,    -1,    -1,    -1,    -1,   481,    -1,    -1,
      -1,   579,   580,    -1,   488,    -1,    -1,   491,    -1,    -1,
     588,    -1,    -1,   591,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   599,    -1,    -1,    -1,    -1,    -1,   511,    -1,   555,
     514,    -1,   516,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   567,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   535,    -1,   579,   580,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   588,    -1,    -1,   591,    -1,    -1,    -1,   553,
      -1,    -1,    -1,   599,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   596
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const unsigned short yystos[] =
{
       0,    29,    54,   101,   102,   104,   105,   109,   126,   127,
     144,   145,   215,   335,   384,   416,   705,   731,   732,   782,
     947,  1002,  1004,  1005,  1006,  1011,  1013,  1026,  1027,  1028,
    1029,  1030,  1432,    27,    28,   706,   707,   708,   709,   710,
     910,   914,   334,   512,   526,   551,   600,  1433,  1433,  1433,
    1433,  1433,  1433,  1433,  1433,   910,    24,   910,  1376,  1031,
     733,   732,  1432,     0,  1003,  1006,  1011,  1029,  1432,    30,
     708,   710,    26,  1451,   910,  1435,   568,   910,  1434,   605,
     783,    24,   591,   730,   731,   898,   910,   917,  1032,  1068,
    1069,  1070,  1071,  1072,  1076,   332,   735,   736,   737,   738,
     741,   742,    39,    84,    85,    92,   346,   372,   443,   536,
     617,   625,   705,   711,   870,   946,  1007,  1008,  1010,  1014,
    1015,  1021,  1033,  1054,  1185,  1195,  1432,   915,   910,  1434,
     596,  1071,   221,   436,   437,  1077,    20,   910,  1075,   914,
     736,     5,   734,   332,   910,     5,   758,   760,   761,  1196,
     910,   910,  1186,  1022,   910,   910,  1010,  1016,   239,   278,
     297,   336,   348,   358,   376,   386,   402,   442,   466,   481,
     488,   491,   511,   514,   516,   535,   553,   784,   785,   786,
     789,    24,  1068,  1074,    17,    18,    25,   409,   655,   657,
    1068,  1078,  1079,   437,   599,    13,   781,   738,   500,  1172,
     739,   736,   741,    31,    59,    60,    68,   239,   278,   297,
     313,   336,   348,   358,   376,   386,   402,   442,   466,   481,
     488,   491,   511,   514,   516,   535,   553,   596,   744,   752,
     763,   764,   910,   409,    91,   910,   730,   871,  1055,   910,
     791,   514,   743,   767,   769,   770,   768,   777,   778,   409,
     409,   790,   437,   409,   409,   736,   765,   404,   655,    17,
      18,    19,    20,    21,   656,    25,     5,   405,  1078,    23,
      24,    25,   599,   918,    18,    24,    25,   740,   918,   754,
     743,   755,   767,   768,   409,   409,   753,   437,   409,   409,
     765,   736,   762,   409,    25,   910,   409,  1023,   730,   730,
     409,   910,   409,   436,   747,   605,   345,   432,   449,   492,
     531,   560,   569,   771,   605,   345,   432,   449,   492,   531,
     560,   569,   779,    25,    25,   792,   793,   794,   795,   910,
      25,   750,   751,    25,    25,   599,   370,   655,  1079,   437,
     405,    25,    25,   736,   747,   736,    25,    25,   735,   750,
      25,    25,   599,    37,   759,  1197,   370,   409,  1187,  1452,
    1453,  1454,  1455,  1456,   872,  1056,  1017,   599,    25,   772,
     773,   409,   774,   779,   780,   774,   409,   775,     5,   370,
       5,   370,     5,   262,     5,   784,   405,     5,     5,   370,
     370,   736,   766,  1078,   599,    25,   237,     5,   370,     5,
     370,   262,   405,     5,   370,   370,   766,   910,  1084,  1085,
    1087,  1034,  1084,   340,  1453,  1172,    33,    34,    46,    48,
      62,    69,    80,    81,    82,    96,    98,    99,   100,   103,
     106,   108,   110,   111,   117,   120,   122,   123,   124,   132,
     134,   135,   137,   139,   140,   143,   148,   149,   150,   152,
     153,   157,   158,   160,   164,   166,   167,   172,   176,   179,
     181,   183,   185,   187,   188,   190,   191,   192,   196,   198,
     199,   201,   209,   210,   222,   225,   226,   229,   230,   233,
     234,   242,   243,   244,   246,   256,   257,   258,   260,   264,
     265,   269,   277,   285,   286,   287,   293,   294,   299,   302,
     306,   307,   317,   335,   343,   349,   379,   381,   382,   390,
     429,   440,   444,   448,   472,   473,   477,   489,   495,   496,
     497,   498,   501,   505,   512,   513,   524,   526,   537,   539,
     542,   548,   574,   577,   583,   586,   601,   608,   631,   632,
     633,   634,   635,   636,   637,   640,   642,   644,   648,   649,
     650,   651,   668,   690,   704,   705,   711,   712,   729,   797,
     798,   799,   800,   811,   812,   813,   814,   862,   866,   896,
     920,   921,   924,   925,   926,   927,   940,   948,   971,   972,
     974,   978,   993,   994,   998,   999,  1000,  1001,  1009,  1024,
    1037,  1048,  1049,  1050,  1061,  1064,  1100,  1103,  1105,  1111,
    1112,  1115,  1118,  1121,  1123,  1125,  1127,  1134,  1139,  1143,
    1144,  1156,  1157,  1160,  1166,  1167,  1168,  1193,  1208,  1209,
    1210,  1211,  1212,  1222,  1223,  1224,  1242,  1245,  1285,  1286,
    1377,  1378,  1408,  1409,  1416,  1432,  1436,  1441,  1443,  1445,
    1449,  1450,  1457,   705,  1012,  1432,   604,   627,  1057,  1058,
    1084,    20,   370,   404,   748,   771,    25,   776,    25,    25,
      25,   793,   795,   787,   751,    25,   405,    20,   748,   409,
      25,    25,   745,    25,   599,   370,     5,  1084,   370,   910,
     911,   914,   910,   905,   911,   905,    24,   591,   910,  1097,
    1427,  1428,  1429,   910,  1447,   910,  1218,  1219,   910,    25,
     652,  1068,  1215,   905,   910,  1141,   840,    25,   918,  1180,
    1181,  1180,    17,    18,    24,    25,    38,    43,    44,    50,
      78,   171,   268,   273,   301,   336,   348,   366,   371,   374,
     385,   391,   401,   406,   409,   412,   421,   422,   463,   467,
     475,   486,   492,   516,   560,   567,   569,   579,   580,   581,
     588,   815,   822,   823,   824,   825,   826,   827,   828,   829,
     841,   846,   857,   858,   859,   860,   910,   918,  1068,  1175,
    1244,  1368,   911,  1417,  1417,   801,  1141,   905,  1213,  1068,
     907,   911,   822,  1417,  1068,  1141,  1068,  1243,  1417,    24,
     564,  1051,  1052,  1068,   905,   905,  1051,   906,   911,   910,
    1052,   905,  1417,   905,   907,  1068,  1098,  1099,   903,   911,
     907,   353,   540,   646,   902,   910,   973,   910,   713,   908,
     911,  1427,  1065,   840,   911,  1124,   867,   107,   116,   125,
     130,   174,   182,   238,   263,   270,   272,   282,   308,   316,
     353,   379,   417,   428,   527,   528,   529,   540,   644,   985,
    1119,  1120,  1068,   821,   822,  1133,   817,   840,   902,  1442,
    1442,   904,   911,   840,    24,  1068,  1122,  1194,  1068,  1171,
      24,  1068,  1411,   822,  1162,  1163,  1164,  1173,  1174,   822,
    1437,    44,    83,   133,   171,   268,   344,   385,   453,   516,
     669,   846,   910,  1068,  1203,   692,   822,   903,  1434,  1038,
     822,   903,   822,  1068,   995,   903,   822,   822,  1180,   910,
     922,   923,   907,   922,  1442,   907,   922,  1442,   928,   922,
      24,    25,   363,   466,   918,   976,  1068,  1086,  1088,    45,
     253,   323,   368,   547,   628,   629,   630,   639,   659,   930,
     932,   934,   936,   938,  1062,  1063,  1067,   314,   325,   377,
     392,   482,  1287,   619,   620,   874,   875,   876,   910,  1059,
     626,  1058,   370,   281,   370,   370,   370,   370,   603,     5,
     370,   281,   736,   756,   757,   370,   370,   603,   370,   910,
    1198,  1087,   370,  1188,    35,    36,    63,    64,    65,   433,
     520,   563,  1225,  1226,  1227,  1230,  1233,  1236,  1237,  1238,
    1239,   328,   912,  1451,   599,  1429,   437,   596,  1116,   599,
       8,   517,   566,     5,   370,   405,    24,   910,  1362,   458,
    1142,  1086,    87,    88,    89,   815,   815,   409,   504,  1192,
     409,   409,   409,   409,   409,   409,   409,   409,   409,   409,
     815,   345,   432,   449,   492,   531,   560,   569,  1371,  1372,
     409,   409,   409,   815,   815,   409,   409,   815,   409,   830,
     409,   409,   409,   409,   409,   409,   409,   815,   409,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    71,    72,    73,    74,    75,
      76,    87,    88,    89,   228,   231,   350,   365,   369,   407,
     435,   454,   535,   602,   728,   816,   831,   833,   834,   835,
     836,   837,   838,   839,    25,   918,   409,   399,  1068,  1093,
    1362,   658,   659,   804,   245,    66,    67,   605,   438,     5,
     598,   605,   597,   597,  1101,   574,   399,     5,   535,   949,
     438,   638,  1439,   409,   437,   599,   638,   363,   715,  1068,
     525,   597,  1106,  1107,  1108,   305,  1284,   821,   820,   822,
       8,   904,    25,   480,   533,   897,  1068,   897,   897,   897,
     990,   991,   897,   897,   575,   986,   659,   986,   986,   898,
     898,   986,   986,   659,     5,   312,   364,     5,   658,   462,
     818,   819,   822,     5,    55,    61,   518,   606,   979,   641,
    1440,   821,   592,   593,   594,   595,  1170,  1172,   362,  1207,
    1172,  1164,     5,   597,  1165,   822,   409,   409,   409,   409,
     409,    24,   688,   910,   409,  1411,   323,   409,   568,   557,
     693,   700,   691,    24,  1053,  1068,  1158,     8,  1161,    13,
     910,  1073,  1080,  1081,  1083,  1091,  1092,  1135,   141,   323,
     523,   556,   554,     5,   638,   638,   820,  1086,  1093,   975,
     399,     5,   129,   953,   409,  1068,   820,   409,    25,    25,
      45,  1066,    24,  1068,  1415,  1415,   904,  1124,   904,    97,
     200,   208,   214,   216,   227,   255,   271,   276,   288,   295,
     450,   457,   479,   484,  1246,  1257,  1258,  1266,  1275,  1276,
    1282,  1283,  1288,  1289,  1298,  1316,  1320,  1388,  1389,  1418,
    1419,  1422,  1423,   877,   878,    70,   873,   884,   885,   876,
    1060,  1452,  1018,   437,   784,   751,   437,     5,   370,   758,
     730,  1035,   730,   136,   275,   351,   409,   471,  1304,  1315,
     409,   910,  1241,    25,   224,   237,   409,   455,   471,   910,
    1221,  1235,  1302,  1303,  1308,  1310,  1312,   409,   910,  1232,
     409,  1221,  1228,     5,   409,   915,  1429,  1078,  1427,   555,
     596,  1117,    20,   910,  1097,  1430,   910,  1448,  1219,   574,
     599,   568,   409,   409,   804,   902,   815,   844,   902,   902,
     902,  1442,   450,  1392,   815,    24,    25,    24,    25,   815,
     409,   605,   902,    20,   815,   370,  1392,   374,   861,  1068,
      20,  1175,   849,   847,   853,   815,   851,   815,   815,   815,
     815,   815,   815,   815,   815,   815,   815,   815,   815,   815,
     815,   815,   815,   815,   815,   815,   815,   815,   409,   815,
     815,   409,   842,  1068,   605,   409,  1427,    24,   917,  1140,
    1140,  1411,  1051,   822,   822,   822,   899,   900,   409,  1068,
    1099,   765,   950,   951,   605,  1411,  1442,  1440,   910,   655,
      20,   646,   910,   973,  1068,   714,   604,   822,   329,  1110,
     535,  1109,     5,    47,    49,    51,   597,   605,   796,  1086,
     868,    17,    18,    24,   283,   289,   290,   291,   309,   417,
     420,   444,   464,   499,   518,   519,   534,   573,   606,   992,
     987,  1120,   898,   822,   323,   574,     5,   902,    25,    25,
     658,   131,  1169,   197,  1174,  1180,  1438,   678,   910,    24,
     902,  1442,   568,   902,   602,  1068,   673,   910,   822,   318,
     696,   700,   557,   694,   702,    22,   213,  1040,  1044,   461,
     840,   461,  1159,   822,   436,  1077,   914,     5,   996,   525,
    1136,  1068,   941,   923,  1442,  1442,   933,   934,   953,   953,
     249,   252,   254,   274,   284,   326,   330,   408,   460,   643,
     952,   954,   955,   981,  1068,  1088,   525,   660,    25,   378,
     939,   300,  1410,  1410,   114,   115,   415,   525,   910,  1317,
    1318,  1363,   765,  1362,  1362,  1259,   765,   910,  1420,  1420,
     338,   455,   564,  1400,  1362,  1267,   147,   417,   428,   450,
     457,  1291,  1292,  1293,   266,   267,  1383,  1452,  1452,   363,
     886,  1068,   621,   622,   879,   880,   881,   460,   604,   623,
     624,   643,   889,   890,  1452,   730,    25,   749,   749,   757,
    1199,   730,  1189,  1306,  1362,  1240,  1315,   409,  1240,   409,
     409,  1234,  1235,   409,   409,    42,   278,   336,   348,   358,
     376,   386,   389,   402,   451,   481,   491,   511,   514,   516,
     544,   553,  1354,  1355,  1356,  1358,  1231,  1232,  1228,  1229,
     643,  1226,    24,   913,  1071,   599,   405,  1411,   555,   525,
    1446,   653,   654,   910,   910,   910,  1216,   840,   370,   685,
     686,   687,   815,   370,   370,   370,   370,  1400,   370,   370,
     370,   370,   568,   370,   370,   568,   370,    25,   345,   432,
     449,   492,   531,   560,   569,  1373,   370,   370,   370,   370,
       5,  1372,   370,     5,   370,   815,   815,   815,   370,   815,
     370,   370,   370,   840,  1392,   840,  1392,   685,   910,  1214,
     596,  1113,   605,     5,     5,     5,   558,   822,   599,     5,
     462,   605,   370,   405,   409,   604,   142,   146,   249,   252,
     716,   719,   720,   981,   717,   718,   910,   409,   911,   628,
     629,  1114,   822,   910,   910,   900,   901,   488,  1442,   804,
     532,  1272,    25,    25,   409,   988,   990,  1068,   514,  1128,
     818,    45,   815,  1172,    25,  1068,  1452,   685,   370,     5,
     370,   370,   689,   910,   370,  1411,   685,   409,   701,   697,
     339,   695,   822,   318,   698,   702,   575,   983,  1045,  1041,
     341,  1039,  1040,   820,   605,  1074,   599,  1092,    13,    17,
      18,    20,    24,    25,    43,   374,   389,   406,   409,   422,
     462,   463,   475,   516,   555,   567,   579,   580,   588,   910,
     918,  1137,  1138,  1367,  1369,  1404,  1405,  1428,  1431,  1452,
     935,   936,   529,   909,   525,   902,   969,   902,   970,   962,
     961,   959,   958,   982,   417,   428,   965,   966,   417,   428,
     967,   968,   303,   955,   960,  1442,    77,   311,   324,   388,
     395,   434,   459,   469,   470,   485,   506,   509,   510,   515,
     572,   584,   661,   662,     5,    25,  1411,   227,   450,  1393,
    1394,  1411,  1124,  1387,  1389,    79,    79,   574,  1122,  1319,
    1320,   409,  1299,   128,   504,  1324,  1331,  1362,   154,   250,
    1424,   599,   605,  1401,  1402,  1404,  1247,   320,   329,   353,
     356,   374,   480,   533,   540,   904,  1269,  1274,   409,  1294,
     604,     5,    24,   910,  1384,  1385,   888,  1068,     5,   525,
     882,   883,   618,   881,   887,   910,   887,   891,   892,   887,
     303,   890,  1019,   405,   405,   439,  1182,  1202,  1036,   439,
    1145,  1176,   409,     5,   370,   273,   409,   421,   581,  1334,
    1335,  1336,  1337,  1338,  1339,  1346,  1350,  1352,  1399,  1404,
     370,   910,  1305,  1307,  1362,  1365,  1309,  1365,     5,   370,
    1309,  1334,   345,   432,   449,   492,   531,   560,   569,  1374,
    1374,   409,   409,   409,   409,   409,   409,   186,   378,  1311,
    1313,     5,   370,     5,   370,   910,   370,  1430,     8,  1411,
     822,     5,  1220,  1221,   840,  1025,   845,     5,  1401,   855,
    1372,   855,    25,   856,  1372,   856,    25,  1192,   370,   409,
    1192,  1372,   605,  1372,  1192,   850,   848,   854,  1192,   852,
    1192,  1192,  1192,   815,   832,   370,   832,   370,   843,   599,
    1220,   555,  1411,  1411,   822,   822,   899,   488,   822,  1444,
       5,    20,  1365,   951,  1411,   599,   910,   717,   725,   724,
     726,   910,   916,   727,   916,   170,   720,   723,     5,   953,
     599,   822,     8,   910,  1273,   869,   989,   990,  1068,     5,
     304,   679,  1204,   323,   323,   437,   599,   323,   409,   674,
     671,  1452,  1452,   703,   699,   695,   984,    24,   909,  1046,
    1068,  1452,   822,   404,    20,   910,  1082,   840,    25,   918,
      25,   918,  1370,  1374,  1404,   409,   409,   914,   409,   409,
     409,   409,   409,     5,    17,    18,    19,    20,    71,    72,
      73,    74,    75,    76,  1425,   399,    41,   521,   942,   937,
     938,    25,   658,   910,     5,   956,     5,   957,  1452,  1452,
    1452,  1452,   988,     5,   964,     5,   963,  1452,   909,     5,
     370,    25,  1362,   914,  1381,   574,   574,  1258,  1386,  1387,
    1320,  1300,  1365,   596,   904,  1334,   409,  1262,   910,  1421,
    1420,     5,  1390,   259,   299,   300,   301,   324,   332,   337,
     352,   357,   359,   366,   369,   372,   375,   378,   383,   401,
     417,   420,   421,   427,   438,   454,   461,   468,   471,   472,
     473,   475,   476,   492,   515,   516,   517,   518,   520,   537,
     538,   560,   569,   570,   572,   634,   919,  1451,   562,   822,
     822,  1268,   904,  1295,  1365,  1362,  1293,   599,   599,     5,
       5,  1068,   887,  1452,  1452,     5,   894,   895,  1452,  1452,
     893,  1012,   788,   746,    52,    53,    56,    57,    58,   156,
     163,   197,   206,   235,   236,   280,   322,   378,   607,   608,
     609,   610,   611,   612,   613,   614,   615,   616,  1179,  1183,
     113,   493,  1184,  1200,  1012,   138,   155,   156,   163,   197,
     206,   235,   280,   322,  1177,  1178,  1190,  1184,  1307,  1315,
     409,  1399,   450,  1334,  1404,  1399,  1337,     6,   370,     7,
       9,    11,    12,    13,    14,    15,    16,   231,   350,   535,
    1351,   407,   581,   602,  1349,  1351,   437,  1364,   370,     5,
     914,     5,   370,  1235,   370,   370,   605,   409,   605,    25,
    1360,  1360,    25,  1360,  1360,    25,  1359,    24,  1367,  1314,
    1315,  1232,  1228,  1411,     8,   654,     5,   370,   820,   370,
     370,   687,   525,  1325,  1330,   605,   370,   605,   370,    25,
     605,  1373,   605,   370,   370,   370,   370,     5,   370,   370,
     370,    20,   370,  1411,     5,   822,   545,   253,   663,   664,
     822,    20,   910,   370,   953,  1452,  1452,     5,   721,   437,
     599,     5,   722,  1452,   718,   525,    20,   910,     5,   910,
    1104,   368,   638,  1068,  1089,  1090,  1452,     5,   370,   909,
     815,   370,   685,  1068,   670,   652,   910,  1068,   676,   370,
     685,  1452,  1452,   988,  1043,    24,  1047,  1068,   550,   865,
     437,   462,   821,   997,   605,   370,   374,  1365,  1426,   338,
     455,   564,  1353,   409,  1353,  1353,  1353,  1353,  1404,  1406,
    1138,  1404,  1404,  1404,  1404,  1428,   944,   943,   419,   929,
     930,   599,   902,  1452,   902,  1452,   966,  1452,   968,  1452,
     658,   662,   370,   409,  1412,  1400,  1383,  1387,  1387,  1379,
       5,   370,   450,  1398,  1263,  1365,   458,  1260,  1398,   605,
    1402,   532,  1397,    20,   409,  1250,  1251,  1252,  1253,  1365,
     532,  1270,     5,   370,   605,   910,   910,  1385,  1068,   910,
    1452,  1452,  1452,  1452,   603,   603,  1180,  1180,  1180,    24,
    1180,  1180,  1180,  1180,  1180,  1180,    24,    24,  1180,  1183,
    1068,  1094,  1095,   598,   425,  1146,  1452,    24,    24,    25,
      25,    25,    25,    25,    24,  1068,  1178,  1146,   370,   914,
     370,  1335,  1336,  1404,   409,  1399,   409,  1399,   228,   365,
     367,   535,   409,   549,   564,   565,  1340,  1341,  1342,  1399,
    1404,    25,  1304,  1365,   599,  1365,   345,   432,   449,   492,
     531,   560,   569,  1375,    25,  1375,     5,  1357,  1357,     5,
     370,   370,  1357,   370,  1314,  1411,  1221,   247,  1217,   494,
    1326,  1327,  1328,  1362,  1331,   310,   493,   503,  1277,  1395,
    1373,   855,  1373,   856,   370,  1373,  1373,   815,   447,   803,
       5,   352,  1411,     5,   409,   370,   529,   980,   916,  1452,
     655,    20,   910,   916,  1452,  1442,   822,  1442,   399,     5,
     219,   990,   658,   323,   683,  1205,  1086,   405,   685,   675,
     370,  1452,   909,   822,   863,  1078,  1375,     5,  1374,     5,
     370,  1404,   914,  1404,  1404,  1404,  1404,     5,   370,   822,
    1452,   931,   932,    20,   910,  1413,  1414,  1401,  1382,  1380,
    1383,  1365,   914,   118,  1301,     5,   370,  1261,  1421,  1089,
    1391,    13,  1252,  1254,  1248,     5,    13,  1271,  1365,   441,
    1296,  1297,  1363,   599,   189,  1020,   784,   758,   517,   566,
    1096,     5,  1094,    40,   112,   178,   180,   195,   203,   207,
     232,  1147,  1148,  1201,  1020,  1191,  1400,  1347,  1348,  1367,
    1431,  1347,  1404,  1344,  1367,  1407,  1399,     5,   405,    20,
     910,   370,    25,  1361,   370,   370,    25,   370,   409,  1328,
       5,   910,  1366,   347,  1322,  1332,   910,  1396,   598,  1353,
     310,   902,   658,   352,  1411,   822,   665,   547,  1102,    25,
     658,   405,   980,   370,  1068,  1090,  1126,  1086,   370,   409,
     677,   683,   672,  1042,  1452,   405,  1374,   605,  1374,   370,
    1406,   370,   370,   370,   370,  1404,   554,   909,     5,   370,
    1397,  1383,  1383,  1400,  1365,   409,  1330,   409,   462,  1255,
    1256,  1399,  1404,     5,   370,   128,   504,  1249,  1253,  1256,
    1089,     5,   119,  1290,   910,  1095,  1149,  1150,  1068,  1152,
    1068,  1151,  1153,  1148,   218,   218,  1401,     5,   370,   370,
       7,   420,  1343,    25,  1364,   605,   370,  1327,  1329,  1327,
    1323,  1403,  1404,   426,  1321,  1333,  1217,    25,  1278,  1279,
    1280,  1365,  1393,  1396,   802,  1411,   371,   182,   238,   263,
     272,   308,   316,   410,   582,   662,   666,   667,   409,   599,
     658,   981,  1129,  1130,  1131,  1206,   680,   370,   683,  1452,
     864,   605,  1375,   605,   370,   945,   977,  1414,  1330,  1401,
     462,  1264,  1265,  1404,  1395,  1255,  1404,     5,  1252,    13,
     904,  1334,  1297,  1452,  1452,  1154,  1452,  1155,  1452,  1452,
    1330,  1348,  1404,  1345,  1407,   405,  1375,     5,   370,     5,
    1334,     5,   517,   566,  1281,  1217,   326,   330,   805,   806,
     807,   981,   897,   897,   897,   897,   897,   897,    24,     5,
     370,   822,    20,   910,  1132,   261,  1131,   683,   685,   683,
     220,  1375,  1375,  1452,   658,  1395,  1330,     5,   370,   370,
    1256,   409,  1452,  1452,   370,  1327,  1403,  1279,   809,   808,
     217,   807,   810,   667,     5,  1452,   681,   942,  1265,  1255,
    1452,  1452,  1452,   822,   370,   370,   370,   682,   141,   323,
     684,  1086
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
#line 1618 "fgl.yacc"
    {
				print_defer(0);
			}
    break;

  case 170:
#line 1622 "fgl.yacc"
    {
				print_defer(1);
			}
    break;

  case 171:
#line 1637 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 172:
#line 1638 "fgl.yacc"
    {strcpy(yyval.str,"");lastlineno=yylineno;}
    break;

  case 175:
#line 1646 "fgl.yacc"
    {dtypelist[0]=0;lex_printcomment("/* define */\n");}
    break;

  case 176:
#line 1646 "fgl.yacc"
    {lex_printcomment("/*end def */\n");}
    break;

  case 182:
#line 1656 "fgl.yacc"
    {in_define=1;}
    break;

  case 183:
#line 1656 "fgl.yacc"
    {in_define=0;strcpy(yyval.str,yyvsp[0].str);
                        set_yytext(yyval.str);
                        if (bad_identifiers(yyval.str)) {
                                yyerror("You can't use this identifier as it is a reserved word in the target language");
                        }
}
    break;

  case 184:
#line 1665 "fgl.yacc"
    { add_constant('c',yyvsp[0].str,yyvsp[-2].str); addmap("Constant",yyvsp[-2].str,curr_func,yylineno,infilename); }
    break;

  case 185:
#line 1666 "fgl.yacc"
    { add_constant('f',yyvsp[0].str,yyvsp[-2].str);
addmap("Constant",yyvsp[-2].str,curr_func,yylineno,infilename);
 }
    break;

  case 186:
#line 1669 "fgl.yacc"
    { 
add_constant('i',yyvsp[0].str,yyvsp[-2].str);
addmap("Constant",yyvsp[-2].str,curr_func,yylineno,infilename);
 }
    break;

  case 188:
#line 1674 "fgl.yacc"
    { }
    break;

  case 189:
#line 1674 "fgl.yacc"
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

  case 193:
#line 1691 "fgl.yacc"
    {
		sprintf(yyval.str,"-%p",yyvsp[0].str);}
    break;

  case 194:
#line 1695 "fgl.yacc"
    {
/*AF CygWin FIX */
push_name(yyval.str,0);
addmap("Define",yyvsp[0].str,curr_func,yylineno,infilename);
}
    break;

  case 199:
#line 1709 "fgl.yacc"
    {
	debug("defines array %s",yyvsp[-1].str);
	push_type(0,0,yyvsp[-1].str);
}
    break;

  case 201:
#line 1718 "fgl.yacc"
    {
	push_associate(yyvsp[-5].str,yyvsp[-1].str);
	push_type(0,0,yyvsp[-1].str);
}
    break;

  case 202:
#line 1722 "fgl.yacc"
    {
    /* void pop_associate (char *a); */
	pop_associate(0);

}
    break;

  case 208:
#line 1738 "fgl.yacc"
    {sprintf(yyval.str,"%s][%s][%s",yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str); debug("Triplet");}
    break;

  case 209:
#line 1740 "fgl.yacc"
    {sprintf(yyval.str,"%s][%s",yyvsp[-2].str,yyvsp[0].str); debug("double");}
    break;

  case 210:
#line 1741 "fgl.yacc"
    {debug("Single");}
    break;

  case 212:
#line 1748 "fgl.yacc"
    {push_record();in_record++;}
    break;

  case 213:
#line 1748 "fgl.yacc"
    {pop_record();in_record--;}
    break;

  case 214:
#line 1749 "fgl.yacc"
    {in_record++;push_record();debug("Like\n");}
    break;

  case 215:
#line 1750 "fgl.yacc"
    {debug("Link Table : %s\n",yyvsp[-2].str);
                  push_rectab(yyvsp[-2].str);
                  pop_record();in_record--;}
    break;

  case 216:
#line 1753 "fgl.yacc"
    {
		push_record();debug("Like\n");}
    break;

  case 217:
#line 1755 "fgl.yacc"
    {
		  debug("Table:%s\n",yyvsp[-4].str);
		  add_link_to(yyvsp[-4].str,yyvsp[-1].str);
	          debug("Push record...\n");
                  push_rectab(yyvsp[-4].str);
                  pop_record();
}
    break;

  case 219:
#line 1765 "fgl.yacc"
    {
	sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 224:
#line 1780 "fgl.yacc"
    {start_state("dtype",1);}
    break;

  case 225:
#line 1780 "fgl.yacc"
    {start_state("dtype",0);}
    break;

  case 229:
#line 1786 "fgl.yacc"
    {push_type("char","1",0);}
    break;

  case 230:
#line 1787 "fgl.yacc"
    {
/* char buff[80]; */
if (atoi(yyvsp[-1].str)==4) {
	addmap("size=4","----",curr_func,yylineno,infilename);
}
push_type("char",yyvsp[-1].str,0);
}
    break;

  case 231:
#line 1794 "fgl.yacc"
    {push_type("char",yyvsp[-1].str,0);}
    break;

  case 232:
#line 1795 "fgl.yacc"
    {push_type("char",yyvsp[-3].str,0);}
    break;

  case 233:
#line 1796 "fgl.yacc"
    {push_type("long",0,0);}
    break;

  case 234:
#line 1797 "fgl.yacc"
    {
debug("Using specified type...");
push_dim(yyvsp[0].str);}
    break;

  case 235:
#line 1800 "fgl.yacc"
    {push_type("int",0,0);}
    break;

  case 236:
#line 1801 "fgl.yacc"
    {push_type("form",0,0);}
    break;

  case 237:
#line 1802 "fgl.yacc"
    {push_type("form",0,0);}
    break;

  case 238:
#line 1803 "fgl.yacc"
    { char buff[256];
				sprintf(buff,"%d",16*256+2);
				push_type("fgldecimal",buff,0);
				}
    break;

  case 239:
#line 1807 "fgl.yacc"
    {
				char buff[256];
				sprintf(buff,"%d",atoi(yyvsp[-1].str)*256+2);
				push_type("fgldecimal",buff,0);
}
    break;

  case 240:
#line 1812 "fgl.yacc"
    {
char buff[256];
sprintf(buff,"%d",atoi(yyvsp[-3].str)*256+atoi(yyvsp[-1].str));
push_type("fgldecimal",buff,0);
}
    break;

  case 241:
#line 1817 "fgl.yacc"
    {
			char buff[256];
			sprintf(buff,"%d",16*256+2);
			push_type("fglmoney",buff,0);}
    break;

  case 242:
#line 1821 "fgl.yacc"
    {
		char buff[256];sprintf(buff,"%d",atoi(yyvsp[-1].str)*256+2);
			push_type("fglmoney",buff,0);}
    break;

  case 243:
#line 1824 "fgl.yacc"
    {
char buff[256];
sprintf(buff,"%d",atoi(yyvsp[-3].str)*256+atoi(yyvsp[-1].str));
push_type("fglmoney",buff,0);}
    break;

  case 244:
#line 1828 "fgl.yacc"
    {push_type("double",0,0);}
    break;

  case 245:
#line 1829 "fgl.yacc"
    {push_type("float",0,0);}
    break;

  case 246:
#line 1830 "fgl.yacc"
    {push_type("fgldate",0,0);}
    break;

  case 247:
#line 1831 "fgl.yacc"
    {push_type("fglbyte",0,0);}
    break;

  case 248:
#line 1832 "fgl.yacc"
    {push_type("fglbyte",0,0);}
    break;

  case 249:
#line 1833 "fgl.yacc"
    {push_type("fgltext",0,0);}
    break;

  case 250:
#line 1834 "fgl.yacc"
    {push_type("fgltext",0,0);}
    break;

  case 251:
#line 1835 "fgl.yacc"
    {
push_type("struct_dtime",yyvsp[0].str,0);
}
    break;

  case 252:
#line 1838 "fgl.yacc"
    {push_type("struct_ival",yyvsp[0].str,0);}
    break;

  case 253:
#line 1839 "fgl.yacc"
    {push_like(yyvsp[0].str);lex_printcomment("/*added(XXXXX)\n */");}
    break;

  case 254:
#line 1840 "fgl.yacc"
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

  case 255:
#line 1872 "fgl.yacc"
    {
lex_printcomment("/*column like(ZZZ)\n*/"); sprintf(yyval.str,"%s.%s",yyvsp[-2].str,yyvsp[0].str); lex_printcomment ("/*set col...(ZZZ)\n*/");}
    break;

  case 256:
#line 1876 "fgl.yacc"
    {debug("--->%s\n",yyvsp[0].str);strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 257:
#line 1878 "fgl.yacc"
    {debug("--->%s\n",yyvsp[0].str);strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 258:
#line 1880 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 259:
#line 1882 "fgl.yacc"
    {
debug("Real datetime %s to %s\n",yyvsp[-2].str,yyvsp[0].str);
sprintf(yyval.str,"%d",(atoi(yyvsp[-2].str)*16)+atoi(yyvsp[0].str)); }
    break;

  case 260:
#line 1887 "fgl.yacc"
    {
sprintf(yyval.str,"%d",(atoi(yyvsp[-2].str)*16)+atoi(yyvsp[0].str)); 
}
    break;

  case 261:
#line 1891 "fgl.yacc"
    {start_state("dtime_val",1);}
    break;

  case 262:
#line 1891 "fgl.yacc"
    {start_state("dtime_val",0); strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 263:
#line 1895 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 264:
#line 1896 "fgl.yacc"
    {strcpy(yyval.str,"2");}
    break;

  case 265:
#line 1897 "fgl.yacc"
    {strcpy(yyval.str,"3");}
    break;

  case 266:
#line 1898 "fgl.yacc"
    {strcpy(yyval.str,"4");}
    break;

  case 267:
#line 1899 "fgl.yacc"
    {strcpy(yyval.str,"5");}
    break;

  case 268:
#line 1900 "fgl.yacc"
    {strcpy(yyval.str,"6");}
    break;

  case 269:
#line 1902 "fgl.yacc"
    {
debug("opt_frac returns %s",yyvsp[0].str);
sprintf(yyval.str,"%d",atoi(yyvsp[0].str)+6); }
    break;

  case 270:
#line 1907 "fgl.yacc"
    {start_state("dtime_val",1);}
    break;

  case 271:
#line 1907 "fgl.yacc"
    { debug ("Got end");start_state("dtime_val",0);  strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 272:
#line 1910 "fgl.yacc"
    {
debug("Nothing in fraction - assume 2");
strcpy(yyval.str,"2");}
    break;

  case 273:
#line 1912 "fgl.yacc"
    {
debug("Read fraction .. ");
debug("    %s",yyvsp[-1].str);
strcpy(yyval.str,yyvsp[-1].str);
}
    break;

  case 274:
#line 1918 "fgl.yacc"
    {
debug("Nothing in fraction - assume 2");
strcpy(yyval.str,"2");}
    break;

  case 275:
#line 1920 "fgl.yacc"
    {
debug("    %s",yyvsp[-1].str);
strcpy(yyval.str,yyvsp[-1].str);
}
    break;

  case 276:
#line 1926 "fgl.yacc"
    {
if (atoi(yyvsp[0].str)>5) {
yyerror("Fraction values are between 0 and 5");
YYERROR;
}
}
    break;

  case 277:
#line 1934 "fgl.yacc"
    {start_state("interval_val",1);}
    break;

  case 278:
#line 1934 "fgl.yacc"
    {start_state("interval_val",0); sprintf(yyval.str,"%d",atoi(yyvsp[0].str)*16+atoi(yyvsp[-1].str));}
    break;

  case 279:
#line 1937 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 280:
#line 1938 "fgl.yacc"
    {strcpy(yyval.str,"2");}
    break;

  case 281:
#line 1939 "fgl.yacc"
    {strcpy(yyval.str,"3");}
    break;

  case 282:
#line 1940 "fgl.yacc"
    {strcpy(yyval.str,"4");}
    break;

  case 283:
#line 1941 "fgl.yacc"
    {strcpy(yyval.str,"5");}
    break;

  case 284:
#line 1942 "fgl.yacc"
    {strcpy(yyval.str,"6");}
    break;

  case 285:
#line 1944 "fgl.yacc"
    {
debug("opt_frac returns %s",yyvsp[0].str);
sprintf(yyval.str,"%d",atoi(yyvsp[0].str)+6); }
    break;

  case 289:
#line 1965 "fgl.yacc"
    {
              	dim_set_name(yyvsp[0].str);
              }
    break;

  case 293:
#line 1974 "fgl.yacc"
    {dim_push_type("char","1",0);}
    break;

  case 294:
#line 1976 "fgl.yacc"
    {dim_push_type("char",yyvsp[-1].str,0);}
    break;

  case 295:
#line 1978 "fgl.yacc"
    {dim_push_type("char",yyvsp[-1].str,0);}
    break;

  case 296:
#line 1980 "fgl.yacc"
    {dim_push_type("char",yyvsp[-3].str,0);}
    break;

  case 297:
#line 1981 "fgl.yacc"
    {dim_push_type("long",0,0);}
    break;

  case 298:
#line 1982 "fgl.yacc"
    {dim_push_type("integer",0,0);}
    break;

  case 299:
#line 1983 "fgl.yacc"
    {dim_push_type("FORM",0,0);}
    break;

  case 300:
#line 1984 "fgl.yacc"
    {
char buff[256];
sprintf(buff,"%d",16*256+2);
dim_push_type("fgldecimal",buff,0);
}
    break;

  case 301:
#line 1989 "fgl.yacc"
    {

char buff[256];
sprintf(buff,"%d",atoi(yyvsp[-1].str)*256+2);
dim_push_type("fgldecimal",buff,0);
}
    break;

  case 302:
#line 1996 "fgl.yacc"
    {
char buff[256];
sprintf(buff,"%d",atoi(yyvsp[-3].str)*256+atoi(yyvsp[-1].str));
dim_push_type("fgldecimal",buff,0);
}
    break;

  case 303:
#line 2001 "fgl.yacc"
    {dim_push_type("fglmoney",0,0);}
    break;

  case 304:
#line 2003 "fgl.yacc"
    {dim_push_type("fglmoney",0,0);}
    break;

  case 305:
#line 2005 "fgl.yacc"
    {dim_push_type("fglmoney",0,0);}
    break;

  case 306:
#line 2006 "fgl.yacc"
    {dim_push_type("double",0,0);}
    break;

  case 307:
#line 2007 "fgl.yacc"
    {dim_push_type("float",0,0);}
    break;

  case 308:
#line 2008 "fgl.yacc"
    {dim_push_type("fgldate",0,0);}
    break;

  case 309:
#line 2009 "fgl.yacc"
    {dim_push_type("fglbyte",0,0);}
    break;

  case 310:
#line 2010 "fgl.yacc"
    {dim_push_type("fgltext",0,0);}
    break;

  case 311:
#line 2011 "fgl.yacc"
    {
dim_push_type("struct_dtime",yyvsp[0].str,0);
}
    break;

  case 312:
#line 2014 "fgl.yacc"
    {dim_push_type("struct_ival",0,0);}
    break;

  case 313:
#line 2016 "fgl.yacc"
    {dim_push_like(yyvsp[0].str);lex_printcomment("/*added(XXXXX)\n */");}
    break;

  case 314:
#line 2022 "fgl.yacc"
    {
lex_printcomment("/*column like(ZZZ)\n*/");
sprintf(yyval.str,"%s.%s",yyvsp[-2].str,yyvsp[0].str)
; lex_printcomment ("/*set col...(ZZZ)\n*/");}
    break;

  case 315:
#line 2030 "fgl.yacc"
    {
dim_push_type(0,0,yyvsp[-1].str);
}
    break;

  case 317:
#line 2038 "fgl.yacc"
    {
dim_push_associate(yyvsp[-5].str,yyvsp[-1].str);
dim_push_type(0,0,yyvsp[-1].str);
}
    break;

  case 318:
#line 2042 "fgl.yacc"
    {
	/* void dim_pop_associate (char *a); */
	dim_pop_associate(0);
}
    break;

  case 319:
#line 2050 "fgl.yacc"
    {dim_push_record();}
    break;

  case 320:
#line 2051 "fgl.yacc"
    {dim_pop_record();}
    break;

  case 321:
#line 2052 "fgl.yacc"
    {dim_push_record();debug("Like\n");}
    break;

  case 322:
#line 2053 "fgl.yacc"
    {debug("Table:%s\n",yyvsp[-2].str);
                                  dim_push_rectab(yyvsp[-2].str);
                                  dim_pop_record();}
    break;

  case 328:
#line 2072 "fgl.yacc"
    { dim_push_name(yyval.str,0); }
    break;

  case 329:
#line 2084 "fgl.yacc"
    {
	print_display_line();
		strcpy(yyval.str,get_display_str(0,0,0));
	}
    break;

  case 330:
#line 2088 "fgl.yacc"
    {
		strcpy(yyval.str,get_display_str(1,0,0)); /* FIXME */
	}
    break;

  case 331:
#line 2091 "fgl.yacc"
    { 
	strcpy(yyval.str,"#error not implemented yet");
	}
    break;

  case 332:
#line 2094 "fgl.yacc"
    { strcpy(yyval.str, get_display_str(4,0,0)); }
    break;

  case 333:
#line 2095 "fgl.yacc"
    { strcpy(yyval.str, get_display_str(2,yyvsp[0].str,0)); }
    break;

  case 334:
#line 2096 "fgl.yacc"
    { strcpy(yyval.str, get_display_str(3,yyvsp[0].str,yyvsp[-2].str)); }
    break;

  case 335:
#line 2097 "fgl.yacc"
    { strcpy(yyval.str, get_display_str(5,yyvsp[-1].str,0)); }
    break;

  case 336:
#line 2098 "fgl.yacc"
    { 
	strcpy(yyval.str,"#error not implemented yet");
 }
    break;

  case 337:
#line 2104 "fgl.yacc"
    {
		print_display_by_name(yyvsp[0].str);
                }
    break;

  case 338:
#line 2111 "fgl.yacc"
    { 
				print_display(yyvsp[-1].str,yyvsp[-2].str,yyvsp[0].str);
		}
    break;

  case 339:
#line 2116 "fgl.yacc"
    {
		print_display_form(yyvsp[-1].str,yyvsp[0].str);
	}
    break;

  case 340:
#line 2121 "fgl.yacc"
    {
		push_blockcommand("DISPLAY");
		}
    break;

  case 341:
#line 2125 "fgl.yacc"
    {
		print_display_array_p1(yyvsp[-6].str,yyvsp[-4].str,yyvsp[-1].str,yyvsp[0].str);
		}
    break;

  case 342:
#line 2128 "fgl.yacc"
    {
		add_continue_blockcommand ("DISPLAY");  
		print_display_array_p2();
		pop_blockcommand("DISPLAY");
}
    break;

  case 343:
#line 2136 "fgl.yacc"
    {
strcpy(yyval.str,"0,0");
}
    break;

  case 344:
#line 2138 "fgl.yacc"
    {
	strcpy(yyval.str,yyvsp[0].str);
}
    break;

  case 345:
#line 2143 "fgl.yacc"
    {
				sprintf(yyval.str,"0x%lx",atol(yyvsp[0].str));
			}
    break;

  case 350:
#line 2155 "fgl.yacc"
    {
		print_befaft_field_1("AFT_ROW");
		}
    break;

  case 351:
#line 2158 "fgl.yacc"
    {
		print_befaft_field_2();
	}
    break;

  case 352:
#line 2161 "fgl.yacc"
    {
		print_befaft_field_1("BEF_ROW");
		}
    break;

  case 353:
#line 2164 "fgl.yacc"
    {
		print_befaft_field_2();
	}
    break;

  case 354:
#line 2167 "fgl.yacc"
    {
		print_onkey_1(yyvsp[0].str);
		}
    break;

  case 355:
#line 2170 "fgl.yacc"
    {
		print_onkey_2();
	}
    break;

  case 356:
#line 2183 "fgl.yacc"
    {
			print_error(yyvsp[0].str,0);
		}
    break;

  case 357:
#line 2186 "fgl.yacc"
    { 
			print_error(yyvsp[-1].str,1);
	}
    break;

  case 358:
#line 2201 "fgl.yacc"
    { if (in_command("WHILE")) { exit_loop("WHILE"); } else { YYERROR;} }
    break;

  case 359:
#line 2203 "fgl.yacc"
    { if (in_command("INPUT")) { exit_loop("INPUT"); } else { YYERROR;} }
    break;

  case 360:
#line 2205 "fgl.yacc"
    { if (in_command("FOREACH")) { exit_loop("FOREACH"); } else { YYERROR;} }
    break;

  case 361:
#line 2207 "fgl.yacc"
    { if (in_command("FOR")) { exit_loop("FOR"); } else { YYERROR;} }
    break;

  case 362:
#line 2209 "fgl.yacc"
    { if (in_command("CONSTRUCT")) { exit_loop("CONSTRUCT"); } else { YYERROR;} }
    break;

  case 363:
#line 2211 "fgl.yacc"
    { if (in_command("DISPLAY")) { exit_loop("DISPLAY"); } else { YYERROR;} }
    break;

  case 364:
#line 2212 "fgl.yacc"
    {
	if (in_command("MENU")) {
		exit_loop("MENU");
		/* lex_printc("cmd_no=-3;continue;\n"); */
	} 
              else YYERROR;}
    break;

  case 365:
#line 2219 "fgl.yacc"
    { if (in_command("CASE")) { exit_loop("CASE"); } else { YYERROR;} }
    break;

  case 366:
#line 2221 "fgl.yacc"
    { if (in_command("PROMPT")) { exit_loop("PROMPT"); } else { YYERROR;} }
    break;

  case 367:
#line 2225 "fgl.yacc"
    { if (in_command("WHILE")) { continue_loop("WHILE");  } else { YYERROR;} }
    break;

  case 368:
#line 2227 "fgl.yacc"
    { if (in_command("INPUT")) { continue_loop("INPUT"); } else { YYERROR;} }
    break;

  case 369:
#line 2229 "fgl.yacc"
    { if (in_command("FOREACH")) { continue_loop("FOREACH");} else { YYERROR;} }
    break;

  case 370:
#line 2231 "fgl.yacc"
    { if (in_command("FOR")) { continue_loop("FOR"); } else { YYERROR;} }
    break;

  case 371:
#line 2233 "fgl.yacc"
    { if (in_command("CONSTRUCT")) { continue_loop("CONSTRUCT"); } else { YYERROR;} }
    break;

  case 372:
#line 2235 "fgl.yacc"
    { if (in_command("DISPLAY")) { continue_loop("DISPLAY"); } else { YYERROR;} }
    break;

  case 373:
#line 2237 "fgl.yacc"
    { if (in_command("MENU")) {  continue_loop("MENU");  } else { YYERROR;} }
    break;

  case 374:
#line 2243 "fgl.yacc"
    { if (in_command("PROMPT")) { continue_loop("PROMPT"); } else { YYERROR;} }
    break;

  case 375:
#line 2257 "fgl.yacc"
    {
	print_exit_program(0);
}
    break;

  case 376:
#line 2260 "fgl.yacc"
    {
	print_exit_program(1);
}
    break;

  case 381:
#line 2277 "fgl.yacc"
    {
	dec_counter();
	yyval.ptr=append_expr_expr(yyvsp[-1].ptr,yyvsp[0].ptr);
}
    break;

  case 384:
#line 2283 "fgl.yacc"
    {
	debug("Got literal ptr=%p",yyvsp[0].ptr);
}
    break;

  case 385:
#line 2287 "fgl.yacc"
    {
	yyval.ptr=new_expr("push_int(0);");
	yyval.ptr=append_expr_expr(yyval.ptr,yyvsp[0].ptr);
	yyval.ptr=append_expr(yyval.ptr,"pushop(OP_SUB);");
}
    break;

  case 386:
#line 2292 "fgl.yacc"
    {
	yyval.ptr=yyvsp[0].ptr;
}
    break;

  case 390:
#line 2302 "fgl.yacc"
    { yyval.ptr=new_expr("add_spaces();"); }
    break;

  case 397:
#line 2313 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 398:
#line 2313 "fgl.yacc"
    {
strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 400:
#line 2318 "fgl.yacc"
    {yyval.ptr=new_expr("push_null()");}
    break;

  case 401:
#line 2322 "fgl.yacc"
    {
	/*set_counter(0);*/
	sprintf(yyval.str,"%d",get_counter_val());
	lex_printcomment("/*L1 %s*/\n",yyval.str);
}
    break;

  case 402:
#line 2328 "fgl.yacc"
    {
	sprintf(yyval.str,"%d",get_counter_val());
	lex_printcomment("/*L2 %s*/\n",yyval.str);
}
    break;

  case 403:
#line 2336 "fgl.yacc"
    {
	/*set_counter(0);*/
	sprintf(yyval.str,"%d",get_counter_val());
	lex_printcomment("/*L1 %s*/\n",yyval.str);
}
    break;

  case 404:
#line 2342 "fgl.yacc"
    {
	sprintf(yyval.str,"%d",get_counter_val());
	lex_printcomment("/*L2 %s*/\n",yyval.str);
}
    break;

  case 405:
#line 2351 "fgl.yacc"
    {sprintf(yyval.str,"%d",get_counter_val());}
    break;

  case 406:
#line 2353 "fgl.yacc"
    {
	print_op("OP_CONCAT");
	dec_counter();sprintf(yyval.str,"%d",get_counter_val());
}
    break;

  case 407:
#line 2360 "fgl.yacc"
    {
	debug("Print expr (2)");
	print_expr(yyvsp[0].ptr);
}
    break;

  case 408:
#line 2368 "fgl.yacc"
    {
	strcpy(yyval.str,"+");
}
    break;

  case 409:
#line 2372 "fgl.yacc"
    {
	strcpy(yyval.str,"-");
}
    break;

  case 410:
#line 2381 "fgl.yacc"
    {
	
	yyval.ptr=append_expr(yyvsp[0].ptr,"pushop(OP_NOT);");
}
    break;

  case 411:
#line 2386 "fgl.yacc"
    {
	yyval.ptr=new_expr("push_int(1);");
        inc_counter();
}
    break;

  case 412:
#line 2391 "fgl.yacc"
    {
	inc_counter();
	yyval.ptr=new_expr("push_int(0);");
}
    break;

  case 413:
#line 2395 "fgl.yacc"
    { yyval.ptr=yyvsp[-1].ptr; }
    break;

  case 414:
#line 2397 "fgl.yacc"
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

  case 415:
#line 2407 "fgl.yacc"
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

  case 416:
#line 2421 "fgl.yacc"
    {
	debug("init expr %s %s",yyvsp[-1].str,yyvsp[0].str);
	sprintf(yyval.str,"%s%p",yyvsp[-1].str,yyvsp[0].str);
	sprintf(yyval.str,"%s",get_push_literal('D',yyval.str));
	yyval.ptr=new_expr(yyval.str);
        inc_counter();
}
    break;

  case 417:
#line 2429 "fgl.yacc"
    {
	debug("init expr int %s %d",yyvsp[-1].str,atoi(yyvsp[0].str));
	sprintf(yyval.str,"%s%p",yyvsp[-1].str,yyvsp[0].str);
	sprintf(yyval.str,"%s",get_push_literal('L',yyval.str));
	yyval.ptr=new_expr(yyval.str);
	inc_counter();
}
    break;

  case 418:
#line 2441 "fgl.yacc"
    {
	sprintf(yyval.str,"%s",get_push_literal('S',yyvsp[0].str));
	yyval.ptr=new_expr(yyval.str);
	inc_counter();
}
    break;

  case 419:
#line 2447 "fgl.yacc"
    {
	sprintf(yyval.str,"%s",get_push_literal('D',yyvsp[0].str));
	yyval.ptr=new_expr(yyval.str);
	inc_counter();
}
    break;

  case 420:
#line 2453 "fgl.yacc"
    {
	sprintf(yyval.str,"%s",get_push_literal('L',yyvsp[0].str));
	yyval.ptr=new_expr(yyval.str);
	inc_counter();
}
    break;

  case 423:
#line 2463 "fgl.yacc"
    {
		sprintf(yyval.str,"%s\n%s",yyvsp[-2].str,yyvsp[0].str);
	}
    break;

  case 424:
#line 2469 "fgl.yacc"
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

  case 425:
#line 2541 "fgl.yacc"
    {
	sprintf(yyval.str,"%sset_column(&rep);",ispdf());
	yyval.ptr=append_expr(yyvsp[0].ptr,yyval.str);
}
    break;

  case 426:
#line 2547 "fgl.yacc"
    {
sprintf(yyval.str,"%sset_column(&rep);",ispdf());
yyval.ptr=append_expr(yyvsp[0].ptr,yyval.str);
}
    break;

  case 427:
#line 2551 "fgl.yacc"
    {
   if (!in_command("REPORT")) {
   yyerror("This can only be done in a report!");
   YYERROR;
} 
insql=0;
	yyval.ptr=new_expr(yyvsp[0].str);
}
    break;

  case 428:
#line 2559 "fgl.yacc"
    {insql=1;set_ingroup();}
    break;

  case 429:
#line 2559 "fgl.yacc"
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

  case 430:
#line 2576 "fgl.yacc"
    {
	yyval.ptr=append_expr(yyvsp[0].ptr,"pushop(OP_AND);");
}
    break;

  case 431:
#line 2580 "fgl.yacc"
    {
	yyval.ptr=append_expr(yyvsp[0].ptr,"pushop(OP_OR);");
}
    break;

  case 432:
#line 2586 "fgl.yacc"
    {
	yyval.ptr=yyvsp[0].ptr;
	}
    break;

  case 433:
#line 2589 "fgl.yacc"
    {
		debug("Adding to list...");
		yyval.ptr=append_expr_expr(yyvsp[-2].ptr,yyvsp[0].ptr);
	}
    break;

  case 434:
#line 2597 "fgl.yacc"
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

  case 435:
#line 2608 "fgl.yacc"
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

  case 436:
#line 2618 "fgl.yacc"
    {
	char buff[256];
	sprintf(buff,"push_int(%d);",length_expr(yyvsp[-1].ptr));
	yyval.ptr=append_expr(yyvsp[-1].ptr,buff);
	append_expr(yyval.ptr,"pushop(OP_IN);");
}
    break;

  case 437:
#line 2624 "fgl.yacc"
    {
	char buff[256];
	sprintf(buff,"push_int(%d);",length_expr(yyvsp[-1].ptr));
	yyval.ptr=append_expr(yyvsp[-1].ptr,buff);
	append_expr(yyval.ptr,"pushop(OP_NOTIN);");
}
    break;

  case 438:
#line 2634 "fgl.yacc"
    { 
	strcpy(yyval.str,"pushop(OP_ISNULL);");
	yyval.ptr=new_expr(yyval.str);
}
    break;

  case 439:
#line 2639 "fgl.yacc"
    {
	strcpy(yyval.str,"pushop(OP_ISNOTNULL);");
	yyval.ptr=new_expr(yyval.str);
}
    break;

  case 440:
#line 2647 "fgl.yacc"
    {
	yyval.ptr=append_expr(yyvsp[0].ptr,"pushop(OP_MATCHES);");
}
    break;

  case 441:
#line 2651 "fgl.yacc"
    {
	yyval.ptr=append_expr(yyvsp[0].ptr,"pushop(OP_MATCHES);pushop(OP_NOT);");
}
    break;

  case 442:
#line 2655 "fgl.yacc"
    {
	yyval.ptr=append_expr(yyvsp[0].ptr,"pushop(OP_LIKE);");
}
    break;

  case 443:
#line 2659 "fgl.yacc"
    {
	yyval.ptr=append_expr(yyvsp[0].ptr,"pushop(OP_LIKE);pushop(OP_NOT);");
}
    break;

  case 444:
#line 2666 "fgl.yacc"
    {
	strcpy(yyval.str,"pushop(OP_CLIP);");
	yyval.ptr=new_expr(yyval.str);
	inc_counter();
}
    break;

  case 445:
#line 2674 "fgl.yacc"
    {
	sprintf(yyval.str,"%s pushop(OP_USING);",yyvsp[0].str);
	yyval.ptr=append_expr(yyvsp[0].ptr,"pushop(OP_USING);");
}
    break;

  case 446:
#line 2682 "fgl.yacc"
    {
	debug("PLUS in math_expr $<ptr>2 = %p",yyvsp[0].ptr);
	yyval.ptr=append_expr(yyvsp[0].ptr,"pushop(OP_ADD);");
}
    break;

  case 447:
#line 2687 "fgl.yacc"
    {
	yyval.ptr=append_expr(yyvsp[0].ptr,"pushop(OP_SUB);");
}
    break;

  case 448:
#line 2691 "fgl.yacc"
    {
      sprintf(yyval.str,"%s pushop(OP_MULT);",yyvsp[0].str);
	yyval.ptr=append_expr(yyvsp[0].ptr,"pushop(OP_MULT);");
}
    break;

  case 449:
#line 2696 "fgl.yacc"
    {
	yyval.ptr=append_expr(yyvsp[0].ptr,"pushop(OP_DIV);");
}
    break;

  case 450:
#line 2700 "fgl.yacc"
    {
	yyval.ptr=append_expr(yyvsp[0].ptr,"pushop(OP_MOD);");
}
    break;

  case 451:
#line 2704 "fgl.yacc"
    {
	yyval.ptr=append_expr(yyvsp[0].ptr,"pushop(OP_POWER);");
}
    break;

  case 452:
#line 2710 "fgl.yacc"
    {
	yyval.ptr=append_expr(yyvsp[0].ptr,"pushop(OP_EQUAL);");
}
    break;

  case 453:
#line 2713 "fgl.yacc"
    {
	yyval.ptr=append_expr(yyvsp[0].ptr,"pushop(OP_EQUAL);");
}
    break;

  case 454:
#line 2717 "fgl.yacc"
    {
	yyval.ptr=append_expr(yyvsp[0].ptr,"pushop(OP_LESS_THAN);");
}
    break;

  case 455:
#line 2721 "fgl.yacc"
    {
	yyval.ptr=append_expr(yyvsp[0].ptr,"pushop(OP_GREATER_THAN);");
}
    break;

  case 456:
#line 2725 "fgl.yacc"
    {
	yyval.ptr=append_expr(yyvsp[0].ptr,"pushop(OP_NOT_EQUAL);");
}
    break;

  case 457:
#line 2729 "fgl.yacc"
    {
	yyval.ptr=append_expr(yyvsp[0].ptr,"pushop(OP_LESS_THAN_EQ);");
}
    break;

  case 458:
#line 2733 "fgl.yacc"
    {
	yyval.ptr=append_expr(yyvsp[0].ptr,"pushop(OP_GREATER_THAN_EQ);");
}
    break;

  case 459:
#line 2740 "fgl.yacc"
    {
	reset_counter();
}
    break;

  case 460:
#line 2750 "fgl.yacc"
    { 
		addmap("Call",yyvsp[-1].str,curr_func,yylineno,infilename);
		new_counter(); 
		}
    break;

  case 461:
#line 2755 "fgl.yacc"
    { 
		sprintf(yyval.str,"%d",get_counter_val()); 
		lex_printcomment("/*function_call_expr2 %s*/\n",yyval.str);
		drop_counter(); 
		}
    break;

  case 462:
#line 2761 "fgl.yacc"
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

  case 463:
#line 2770 "fgl.yacc"
    {
        sprintf(yyval.str,"\"%s\",\"%s\"",get_idents(0),get_idents(1));
	debug("NEWFORMAT : %s\n",yyval.str);
        A4GLSQL_set_status(0,0);
        new_counter();
}
    break;

  case 464:
#line 2775 "fgl.yacc"
    {
	sprintf(yyval.str,"%d",get_counter_val());  
	drop_counter();
}
    break;

  case 465:
#line 2778 "fgl.yacc"
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

  case 466:
#line 2792 "fgl.yacc"
    {inc_counter();chk4var=1;}
    break;

  case 467:
#line 2792 "fgl.yacc"
    {chk4var=0;}
    break;

  case 468:
#line 2792 "fgl.yacc"
    {
	yyval.ptr=append_expr(yyvsp[-2].ptr,"aclfgl_date(1);");
inc_counter();}
    break;

  case 469:
#line 2795 "fgl.yacc"
    {inc_counter();chk4var=1;}
    break;

  case 470:
#line 2795 "fgl.yacc"
    {chk4var=0;}
    break;

  case 471:
#line 2795 "fgl.yacc"
    {
	yyval.ptr=append_expr(yyvsp[-2].ptr,"aclfgl_month(1);");
inc_counter();}
    break;

  case 472:
#line 2798 "fgl.yacc"
    {inc_counter();chk4var=1;}
    break;

  case 473:
#line 2798 "fgl.yacc"
    {chk4var=0;}
    break;

  case 474:
#line 2798 "fgl.yacc"
    {
	yyval.ptr=append_expr(yyvsp[-2].ptr,"aclfgl_day(1);");
inc_counter();}
    break;

  case 475:
#line 2801 "fgl.yacc"
    {inc_counter();chk4var=1;}
    break;

  case 476:
#line 2801 "fgl.yacc"
    {chk4var=0;}
    break;

  case 477:
#line 2801 "fgl.yacc"
    {
	yyval.ptr=append_expr(yyvsp[-2].ptr,"aclfgl_year(1);");
inc_counter();}
    break;

  case 478:
#line 2804 "fgl.yacc"
    {
	char buff[256];
	sprintf(buff,"acli_interval(%s,%s)",yyvsp[-2].str,yyvsp[0].str);
	yyval.ptr=new_expr(buff);
}
    break;

  case 479:
#line 2809 "fgl.yacc"
    {
	char buff[256];
	sprintf(buff,"acli_interval(\"%s\",%s)",yyvsp[-2].str,yyvsp[0].str);
	yyval.ptr=new_expr(buff);
}
    break;

  case 480:
#line 2814 "fgl.yacc"
    {
	char buff[256];
	sprintf(buff,"acli_interval(\"%s:%s\",%s)",yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str);
	yyval.ptr=new_expr(buff);
}
    break;

  case 481:
#line 2819 "fgl.yacc"
    {
	char buff[256];
	sprintf(buff,"acli_datetime(%s,%s)",yyvsp[-2].str,yyvsp[0].str);
	yyval.ptr=new_expr(buff);
}
    break;

  case 482:
#line 2824 "fgl.yacc"
    {
	char buff[256];
	sprintf(buff,"acli_datetime(\"%s\",%s)",yyvsp[-2].str,yyvsp[0].str);
	yyval.ptr=new_expr(buff);
}
    break;

  case 483:
#line 2829 "fgl.yacc"
    {
	char buff[256];
	sprintf(buff,"acli_datetime(\"%s:%s\",%s)",yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str);
	yyval.ptr=new_expr(buff);
}
    break;

  case 484:
#line 2838 "fgl.yacc"
    {strcpy(yyval.str,"-1,-1");}
    break;

  case 485:
#line 2839 "fgl.yacc"
    {sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 486:
#line 2842 "fgl.yacc"
    {strcpy(yyval.str,"-1,-1");}
    break;

  case 487:
#line 2843 "fgl.yacc"
    {sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 489:
#line 2849 "fgl.yacc"
    {
sprintf(yyval.str,"{int _retvars;\n_retvars=fgl_getfldbuf(%s);\nif (_retvars != 1 ) {A4GLSQL_set_status(-3001,0);chk_err(%d,\"%s\");}\n}\n",
	yyvsp[-1].str, lastlineno,infilename); 
	yyval.ptr=new_expr(yyval.str);

}
    break;

  case 490:
#line 2855 "fgl.yacc"
    {sprintf(yyval.str,"push_int(fgl_fieldnametoid(\"\",%s));",yyvsp[-1].str); yyval.ptr=new_expr(yyval.str); }
    break;

  case 491:
#line 2856 "fgl.yacc"
    {
sprintf(yyval.str,"push_int(fgl_fieldnametoid(\"\",%s));",yyvsp[-1].str); yyval.ptr=new_expr(yyval.str); 
addmap("Get Field",yyvsp[-1].str,curr_func,yylineno,infilename);
}
    break;

  case 492:
#line 2861 "fgl.yacc"
    {sprintf(yyval.str,"push_int(fgl_infield(%s));",yyvsp[-1].str); 
	yyval.ptr=new_expr(yyval.str);
}
    break;

  case 493:
#line 2865 "fgl.yacc"
    { sprintf(yyval.str,"push_int(fgl_fieldtouched(%s));",yyvsp[-1].str); 
	yyval.ptr=new_expr(yyval.str);
}
    break;

  case 494:
#line 2869 "fgl.yacc"
    { sprintf(yyval.str,"push_int(!fgl_fieldtouched(%s));",yyvsp[-1].str); 
	yyval.ptr=new_expr(yyval.str);
}
    break;

  case 497:
#line 2876 "fgl.yacc"
    {
		inc_counter();
               sprintf(yyval.str,"push_current(%s);",yyvsp[0].str);
		yyval.ptr=new_expr(yyval.str);
          	}
    break;

  case 498:
#line 2881 "fgl.yacc"
    { inc_counter(); strcpy(yyval.str,"push_today();");
		yyval.ptr=new_expr(yyval.str);
		}
    break;

  case 499:
#line 2888 "fgl.yacc"
    { 
	yyval.ptr=append_expr(yyvsp[-1].ptr,"upshift_stk();");
}
    break;

  case 500:
#line 2892 "fgl.yacc"
    { 
	yyval.ptr=append_expr(yyvsp[-1].ptr,"downshift_stk();");
}
    break;

  case 501:
#line 2895 "fgl.yacc"
    { 
	yyval.ptr=append_expr(yyvsp[0].ptr,"push_ascii();");
}
    break;

  case 502:
#line 2898 "fgl.yacc"
    { 
	sprintf(yyval.str,"%s",yyvsp[-1].str); yyval.ptr=new_expr(yyval.str); }
    break;

  case 503:
#line 2900 "fgl.yacc"
    {
	yyval.ptr=append_expr(yyvsp[-1].ptr,"push_double(-1);pushop(OP_MULT);");
}
    break;

  case 504:
#line 2903 "fgl.yacc"
    {
	yyval.ptr=append_expr(yyvsp[-1].ptr,"push_double(-28.3465);pushop(OP_MULT);");
}
    break;

  case 505:
#line 2906 "fgl.yacc"
    {
	yyval.ptr=append_expr(yyvsp[-1].ptr,"push_double(-72.0);pushop(OP_MULT);");
}
    break;

  case 506:
#line 2912 "fgl.yacc"
    { sprintf(yyval.str,"aclfgli_current(%s,%s);",yyvsp[-2].str,yyvsp[0].str); }
    break;

  case 507:
#line 2913 "fgl.yacc"
    { sprintf(yyval.str,"aclfgli_extend(%s,%s,%s);",yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str); }
    break;

  case 508:
#line 2914 "fgl.yacc"
    { sprintf(yyval.str,"aclfgli_current(%s,%s);",yyvsp[-2].str,yyvsp[0].str); }
    break;

  case 509:
#line 2925 "fgl.yacc"
    {
print_for_start(yyvsp[-5].str);
push_blockcommand("FOR");
}
    break;

  case 510:
#line 2929 "fgl.yacc"
    {debug("For_cmds\n");}
    break;

  case 511:
#line 2930 "fgl.yacc"
    {

pop_blockcommand("FOR");
print_for_end();
lex_printcomment(" /*END FOR*/\n");}
    break;

  case 512:
#line 2937 "fgl.yacc"
    {
		print_for_default_step();
	}
    break;

  case 514:
#line 2954 "fgl.yacc"
    {
push_blockcommand("FOREACH");
}
    break;

  case 515:
#line 2958 "fgl.yacc"
    {
print_foreach_start();
lex_printcomment(" /* foreach */\n");
}
    break;

  case 516:
#line 2963 "fgl.yacc"
    {
print_foreach_next(yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 517:
#line 2967 "fgl.yacc"
    {
add_continue_blockcommand ("FOREACH");
print_foreach_end();
pop_blockcommand("FOREACH");
}
    break;

  case 518:
#line 2983 "fgl.yacc"
    {
		sprintf(curr_func,"%s",yyvsp[0].str); 
		print_formhandler(yyvsp[0].str);
		start_state("formhandler",1);
	push_blockcommand("FORMHANDLER");
        }
    break;

  case 519:
#line 2989 "fgl.yacc"
    {
		print_variables();
		print_getwin();
	}
    break;

  case 520:
#line 2997 "fgl.yacc"
    {
pop_blockcommand("FORMHANDLER");
print_end_formhandler(); 
start_state("formhandler",0);}
    break;

  case 527:
#line 3014 "fgl.yacc"
    {
		print_event('B');
        }
    break;

  case 528:
#line 3016 "fgl.yacc"
    {
		print_event_2();
        }
    break;

  case 529:
#line 3019 "fgl.yacc"
    {
		print_event('b');
        }
    break;

  case 530:
#line 3021 "fgl.yacc"
    {
		print_event_2();
        }
    break;

  case 535:
#line 3035 "fgl.yacc"
    {
		print_event('A');
        }
    break;

  case 536:
#line 3037 "fgl.yacc"
    {
		print_event_2();
        }
    break;

  case 537:
#line 3040 "fgl.yacc"
    {
		print_event('a');
        }
    break;

  case 538:
#line 3042 "fgl.yacc"
    {
		print_event_2();
        }
    break;

  case 551:
#line 3073 "fgl.yacc"
    { 
			print_gtk_field('B',0);
		}
    break;

  case 552:
#line 3075 "fgl.yacc"
    {
			print_gtk_field_2();
		}
    break;

  case 553:
#line 3078 "fgl.yacc"
    { 
			print_gtk_field('A',0);
		}
    break;

  case 554:
#line 3080 "fgl.yacc"
    {
			print_gtk_field_2();
		}
    break;

  case 555:
#line 3083 "fgl.yacc"
    {
			print_gtk_field('b',yyvsp[0].str);
		}
    break;

  case 556:
#line 3085 "fgl.yacc"
    { 
			print_gtk_field_2();
		}
    break;

  case 557:
#line 3088 "fgl.yacc"
    {
			print_gtk_field('a',yyvsp[0].str);
		}
    break;

  case 558:
#line 3090 "fgl.yacc"
    { 
			print_gtk_field_2();
		}
    break;

  case 559:
#line 3093 "fgl.yacc"
    { 
			print_gtk_field('o',yyvsp[0].str);
		}
    break;

  case 560:
#line 3095 "fgl.yacc"
    { 
			print_gtk_field_2();
		}
    break;

  case 561:
#line 3110 "fgl.yacc"
    {
		//print_niy("Free Cursor");
		lex_printcomment(" /* FIXME: Not implemented: Free Cursor */\n");;

		strcpy(yyval.str,"");
		}
    break;

  case 562:
#line 3126 "fgl.yacc"
    {sprintf(yyval.str,"%d",-1-(atoi(yyvsp[0].str)));}
    break;

  case 563:
#line 3127 "fgl.yacc"
    {strcpy(yyval.str,"-1");}
    break;

  case 564:
#line 3128 "fgl.yacc"
    {sprintf (yyval.str,"%d",atoi(yyvsp[0].str)+1);}
    break;

  case 565:
#line 3129 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 566:
#line 3130 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 567:
#line 3131 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 571:
#line 3139 "fgl.yacc"
    {sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str); }
    break;

  case 573:
#line 3145 "fgl.yacc"
    {
			sprintf(yyval.str,"\"%s\",1",yyvsp[0].str);}
    break;

  case 574:
#line 3147 "fgl.yacc"
    { sprintf(yyval.str,"int_to_id(%s)",yyvsp[-1].str); }
    break;

  case 575:
#line 3148 "fgl.yacc"
    { sprintf(yyval.str,"int_to_id(%s.%s)",yyvsp[-5].str,yyvsp[-1].str); }
    break;

  case 576:
#line 3150 "fgl.yacc"
    {sprintf(yyval.str,"\"%s\",%s",yyvsp[-3].str,yyvsp[-1].str);}
    break;

  case 577:
#line 3152 "fgl.yacc"
    {sprintf(yyval.str,"\"%s.*\",1",yyvsp[-2].str);}
    break;

  case 578:
#line 3154 "fgl.yacc"
    {sprintf(yyval.str,"\"%s.*\",%s",yyvsp[-5].str,yyvsp[-3].str);}
    break;

  case 579:
#line 3156 "fgl.yacc"
    {sprintf(yyval.str,"\"%s.%s\",1",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 580:
#line 3158 "fgl.yacc"
    {sprintf(yyval.str,"\"%s.%s\",%s",yyvsp[-5].str,yyvsp[0].str,yyvsp[-3].str);}
    break;

  case 581:
#line 3161 "fgl.yacc"
    {
				print_pushchar(yyvsp[0].str);
				addmap("Cursor",last_var,curr_func,yylineno,infilename);
			}
    break;

  case 582:
#line 3168 "fgl.yacc"
    {sprintf(yyval.str,"%s",yyvsp[0].str);}
    break;

  case 583:
#line 3170 "fgl.yacc"
    {sprintf(yyval.str,"%s",yyvsp[0].str);
addmap("Window",last_var,curr_func,yylineno,infilename);
}
    break;

  case 584:
#line 3176 "fgl.yacc"
    {sprintf(yyval.str,"%s",yyvsp[0].str);
addmap("Open Window",last_var,curr_func,yylineno,infilename);
}
    break;

  case 585:
#line 3181 "fgl.yacc"
    {sprintf(yyval.str,"%s",yyvsp[0].str);
addmap("Form",last_var,curr_func,yylineno,infilename);
}
    break;

  case 586:
#line 3186 "fgl.yacc"
    {sprintf(yyval.str,"%s",yyvsp[0].str);
addmap("Open Form",last_var,curr_func,yylineno,infilename);
}
    break;

  case 587:
#line 3191 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 588:
#line 3191 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 589:
#line 3194 "fgl.yacc"
    { 
			strcpy(yyval.str,downshift(yyvsp[-1].str)) ;
}
    break;

  case 590:
#line 3200 "fgl.yacc"
    {
			sprintf(yyval.str,"%s",yyvsp[-1].str) ;
			}
    break;

  case 591:
#line 3205 "fgl.yacc"
    {
sprintf(yyval.str,"\"%s_%s\"",clobber,downshift(yyvsp[0].str)) ;
strcpy(last_var,downshift(yyvsp[0].str));
}
    break;

  case 592:
#line 3209 "fgl.yacc"
    {
		sprintf(yyval.str,"aclfgli_str_to_id(%s)",yyvsp[-1].str);
		sprintf(last_var,"->%s",yyvsp[-1].str);
	}
    break;

  case 595:
#line 3217 "fgl.yacc"
    {
		debug("Setident\n");
		/* chk4var=1; */
	strcpy(yyval.str,"");
	   }
    break;

  case 596:
#line 3223 "fgl.yacc"
    {
		debug("Unsetident\n");
		chk4var=0;
		}
    break;

  case 597:
#line 3227 "fgl.yacc"
    {sprintf(yyval.str,"\"%s\",1",yyvsp[0].str);}
    break;

  case 598:
#line 3229 "fgl.yacc"
    {sprintf(yyval.str,"\"%s\",%s",yyvsp[-3].str,yyvsp[-1].str);}
    break;

  case 599:
#line 3231 "fgl.yacc"
    {sprintf(yyval.str,"\"%s.*\",1",yyvsp[-2].str);}
    break;

  case 600:
#line 3233 "fgl.yacc"
    {sprintf(yyval.str,"\"%s.*\",%s",yyvsp[-5].str,yyvsp[-3].str);}
    break;

  case 601:
#line 3235 "fgl.yacc"
    {sprintf(yyval.str,"\"%s.%s\",1",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 602:
#line 3237 "fgl.yacc"
    {sprintf(yyval.str,"\"%s.%s\",%s",yyvsp[-5].str,yyvsp[0].str,yyvsp[-3].str);}
    break;

  case 603:
#line 3240 "fgl.yacc"
    {
debug("Scanvar=%d",scan_variable(yyvsp[0].str)&15);
if ((scan_variable(yyvsp[0].str)&15)!=0) {
yyerror("Only a character variable can be used for this");
YYERROR;
}
}
    break;

  case 605:
#line 3249 "fgl.yacc"
    {
		sprintf(yyval.str,".%s",yyvsp[0].str);
}
    break;

  case 649:
#line 3310 "fgl.yacc"
    {
	char buff[256];
	print_goto(yyvsp[0].str);
}
    break;

  case 650:
#line 3324 "fgl.yacc"
    {
print_gui_do_menuitems(yyvsp[0].str,'C');
}
    break;

  case 652:
#line 3331 "fgl.yacc"
    {sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 653:
#line 3334 "fgl.yacc"
    {
        sprintf(yyval.str,"\"%s\"",yyvsp[0].str);
}
    break;

  case 654:
#line 3340 "fgl.yacc"
    {
print_gui_do_menuitems(yyvsp[0].str,'U');
}
    break;

  case 655:
#line 3346 "fgl.yacc"
    {
print_gui_do_menuitems(yyvsp[0].str,'D');
}
    break;

  case 656:
#line 3350 "fgl.yacc"
    {
print_gui_do_fields(yyvsp[0].str,'D');
}
    break;

  case 657:
#line 3354 "fgl.yacc"
    {
print_gui_do_form(yyvsp[-2].str,yyvsp[0].str,'D');
}
    break;

  case 658:
#line 3360 "fgl.yacc"
    {
print_gui_do_menuitems(yyvsp[0].str,'E');
}
    break;

  case 659:
#line 3364 "fgl.yacc"
    {
print_gui_do_fields(yyvsp[0].str,'E');
}
    break;

  case 660:
#line 3368 "fgl.yacc"
    {
print_gui_do_form(yyvsp[-2].str,yyvsp[0].str,'E');
}
    break;

  case 661:
#line 3373 "fgl.yacc"
    {start_state("messagebox",1);}
    break;

  case 662:
#line 3378 "fgl.yacc"
    {start_state("messagebox",0);}
    break;

  case 681:
#line 3419 "fgl.yacc"
    {
		print_if_start();
	}
    break;

  case 682:
#line 3424 "fgl.yacc"
    {
		print_if_end();
	}
    break;

  case 684:
#line 3429 "fgl.yacc"
    {
		print_if_else();
	}
    break;

  case 686:
#line 3432 "fgl.yacc"
    {
		print_if_else();
		}
    break;

  case 687:
#line 3434 "fgl.yacc"
    {

		print_if_start();
	}
    break;

  case 688:
#line 3437 "fgl.yacc"
    {
		print_if_end();
	}
    break;

  case 689:
#line 3442 "fgl.yacc"
    {
	print_import(yyvsp[-3].str,atoi(yyvsp[-1].str));
}
    break;

  case 690:
#line 3447 "fgl.yacc"
    { add_ex_dtype(yyvsp[0].str); }
    break;

  case 691:
#line 3457 "fgl.yacc"
    {debug("init to\n");}
    break;

  case 692:
#line 3458 "fgl.yacc"
    {
	print_init();
 }
    break;

  case 693:
#line 3461 "fgl.yacc"
    {
	print_init_table(yyvsp[0].str);
}
    break;

  case 695:
#line 3467 "fgl.yacc"
    {sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 696:
#line 3471 "fgl.yacc"
    {setrecord(yyval.str,yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 697:
#line 3472 "fgl.yacc"
    {setrecord(yyval.str,yyvsp[-2].str,0);}
    break;

  case 700:
#line 3486 "fgl.yacc"
    {
sprintf(yyval.str,"0");
}
    break;

  case 701:
#line 3488 "fgl.yacc"
    {
sprintf(yyval.str,"1");
}
    break;

  case 704:
#line 3497 "fgl.yacc"
    {
		print_befaft_field_1(yyvsp[0].str);
}
    break;

  case 705:
#line 3499 "fgl.yacc"
    {
	print_befaft_field_2();
}
    break;

  case 706:
#line 3503 "fgl.yacc"
    {
		print_befaft_field_1(yyvsp[0].str);
}
    break;

  case 707:
#line 3505 "fgl.yacc"
    {
	print_befaft_field_2();
}
    break;

  case 708:
#line 3508 "fgl.yacc"
    {
		print_befaft_field_1("AFT_ROW");
}
    break;

  case 709:
#line 3510 "fgl.yacc"
    {
	print_befaft_field_2();
}
    break;

  case 710:
#line 3513 "fgl.yacc"
    {
		lex_printcomment("/* before row */ \n");
		print_befaft_field_1("BEF_ROW");
}
    break;

  case 711:
#line 3516 "fgl.yacc"
    {
	print_befaft_field_2();
		}
    break;

  case 712:
#line 3519 "fgl.yacc"
    {
	print_onkey_1(yyvsp[0].str);
}
    break;

  case 713:
#line 3521 "fgl.yacc"
    {
	print_onkey_2();
}
    break;

  case 714:
#line 3524 "fgl.yacc"
    {
		print_befaft_field_1("AFTER_INP");
}
    break;

  case 715:
#line 3526 "fgl.yacc"
    {
	print_befaft_field_2();
}
    break;

  case 716:
#line 3529 "fgl.yacc"
    {
		print_befaft_field_1("BEFORE_INP");
}
    break;

  case 717:
#line 3531 "fgl.yacc"
    {
	print_befaft_field_2();
}
    break;

  case 718:
#line 3534 "fgl.yacc"
    {lex_printcomment("/* before insert/delete */ \n");
		print_befaft_field_1(yyvsp[0].str);
}
    break;

  case 719:
#line 3536 "fgl.yacc"
    {
	print_befaft_field_2();
}
    break;

  case 720:
#line 3539 "fgl.yacc"
    {
		print_befaft_field_1(yyvsp[0].str);
}
    break;

  case 721:
#line 3541 "fgl.yacc"
    {
	print_befaft_field_2();
}
    break;

  case 722:
#line 3547 "fgl.yacc"
    {sprintf(yyval.str,"(%s)",yyvsp[0].str);}
    break;

  case 723:
#line 3548 "fgl.yacc"
    {
	char buff[256];
	sprintf(buff,"(%s)",yyvsp[0].str);
	generate_or(yyval.str,yyvsp[-2].str,buff);
	}
    break;

  case 724:
#line 3556 "fgl.yacc"
    {strcpy(yyval.str,"AFT_INSERT");}
    break;

  case 725:
#line 3557 "fgl.yacc"
    {strcpy(yyval.str,"AFT_DELETE");}
    break;

  case 726:
#line 3562 "fgl.yacc"
    {sprintf(yyval.str,"(%s)",yyvsp[0].str);}
    break;

  case 727:
#line 3563 "fgl.yacc"
    {
	char buff[80];
		sprintf(buff,"(%s)",yyvsp[0].str);
		generate_or(yyval.str,yyvsp[-2].str,yyvsp[0].str);
 }
    break;

  case 728:
#line 3572 "fgl.yacc"
    {strcpy(yyval.str,"BEF_INSERT");}
    break;

  case 729:
#line 3573 "fgl.yacc"
    {strcpy(yyval.str,"BEF_DELETE");}
    break;

  case 730:
#line 3580 "fgl.yacc"
    {sprintf(yyval.str,"BEF_FIELD_CHK(%s)",yyvsp[0].str);}
    break;

  case 731:
#line 3581 "fgl.yacc"
    {
	char buff[80];
	sprintf(buff,"BEF_FIELD_CHK(%s)",yyvsp[0].str);
	generate_or(yyval.str,yyvsp[-2].str,buff);
	}
    break;

  case 732:
#line 3589 "fgl.yacc"
    {sprintf(yyval.str,"AFT_FIELD_CHK(%s)",yyvsp[0].str);}
    break;

  case 733:
#line 3590 "fgl.yacc"
    {
	char buff[80];
	sprintf(buff,"AFT_FIELD_CHK(%s)",yyvsp[0].str);
	generate_or(yyval.str,yyvsp[-2].str,buff);
	}
    break;

  case 734:
#line 3599 "fgl.yacc"
    {
print_next_field(yyvsp[0].str);
}
    break;

  case 735:
#line 3604 "fgl.yacc"
    {
print_next_form_field(yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 736:
#line 3609 "fgl.yacc"
    {sprintf(yyval.str,"\"+\",0");}
    break;

  case 737:
#line 3610 "fgl.yacc"
    {sprintf(yyval.str,"\"-\",0");}
    break;

  case 739:
#line 3615 "fgl.yacc"
    {
print_input_1();
}
    break;

  case 740:
#line 3618 "fgl.yacc"
    {
print_input_2(yyvsp[-2].str);
}
    break;

  case 741:
#line 3626 "fgl.yacc"
    {
print_input(1,yyvsp[-2].str,yyvsp[-1].str,0);
strcpy(yyval.str,get_formloop_str(0));
}
    break;

  case 742:
#line 3631 "fgl.yacc"
    {
print_input(0,yyvsp[-4].str,yyvsp[-1].str,yyvsp[-2].str);
strcpy(yyval.str,get_formloop_str(0));
}
    break;

  case 743:
#line 3635 "fgl.yacc"
    {
inp_flags=0;}
    break;

  case 744:
#line 3637 "fgl.yacc"
    {
strcpy(yyval.str,print_input_array(yyvsp[-8].str,yyvsp[-2].str,yyvsp[-7].str,yyvsp[-5].str,yyvsp[0].str));
}
    break;

  case 745:
#line 3646 "fgl.yacc"
    {
		print_scroll(yyvsp[-1].str,yyvsp[0].str);
	}
    break;

  case 746:
#line 3651 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 747:
#line 3652 "fgl.yacc"
    {strcpy(yyval.str,"-1");}
    break;

  case 748:
#line 3653 "fgl.yacc"
    {sprintf(yyval.str,"%s",yyvsp[0].str);}
    break;

  case 749:
#line 3654 "fgl.yacc"
    {sprintf(yyval.str,"-%s",yyvsp[0].str);}
    break;

  case 750:
#line 3657 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 752:
#line 3663 "fgl.yacc"
    {iskey=1;}
    break;

  case 753:
#line 3663 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);iskey=0;}
    break;

  case 754:
#line 3665 "fgl.yacc"
    {strcpy(yyval.str,"->ANY");}
    break;

  case 755:
#line 3668 "fgl.yacc"
    {iskey=1;}
    break;

  case 756:
#line 3668 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);iskey=0;}
    break;

  case 757:
#line 3670 "fgl.yacc"
    {sprintf(yyval.str,"key_val(\"%s\")",yyvsp[0].str);iskey=0;}
    break;

  case 758:
#line 3674 "fgl.yacc"
    {start_state("keymode",1);iskey=1;}
    break;

  case 759:
#line 3674 "fgl.yacc"
    {sprintf(yyval.str,"key_val(\"%s\")",yyvsp[0].str);iskey=0;start_state("keymode",0);}
    break;

  case 760:
#line 3677 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 761:
#line 3678 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[-1].str);}
    break;

  case 763:
#line 3681 "fgl.yacc"
    {
	sprintf(yyval.str,"%s||%s",yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 764:
#line 3686 "fgl.yacc"
    {start_state("keymode",1);}
    break;

  case 765:
#line 3686 "fgl.yacc"
    {start_state("keymode",0);strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 770:
#line 3693 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 771:
#line 3694 "fgl.yacc"
    {strcpy(yyval.str,"escape");}
    break;

  case 772:
#line 3695 "fgl.yacc"
    {strcpy(yyval.str,"up");}
    break;

  case 773:
#line 3696 "fgl.yacc"
    {strcpy(yyval.str,"down");}
    break;

  case 774:
#line 3697 "fgl.yacc"
    {strcpy(yyval.str,"return");}
    break;

  case 775:
#line 3698 "fgl.yacc"
    {strcpy(yyval.str,"delete");}
    break;

  case 776:
#line 3699 "fgl.yacc"
    {strcpy(yyval.str,"tab");}
    break;

  case 777:
#line 3700 "fgl.yacc"
    {strcpy(yyval.str,"left");}
    break;

  case 778:
#line 3701 "fgl.yacc"
    {strcpy(yyval.str,"right");}
    break;

  case 779:
#line 3702 "fgl.yacc"
    {strcpy(yyval.str,"nextpage");}
    break;

  case 780:
#line 3703 "fgl.yacc"
    {strcpy(yyval.str,"prevpage");}
    break;

  case 781:
#line 3704 "fgl.yacc"
    { rm_quotes(yyvsp[0].str); strcpy(yyval.str,yyvsp[0].str); }
    break;

  case 782:
#line 3708 "fgl.yacc"
    { 
char buff[256];
printf("Label : %s\n",get_idents(0));
strcpy(buff,get_idents(0));
convlower(buff);
print_label(buff);
}
    break;

  case 783:
#line 3726 "fgl.yacc"
    {chk4var=1;}
    break;

  case 784:
#line 3726 "fgl.yacc"
    {chk4var=0;
expand_obind();
lex_printcomment("/*let3*/\n");}
    break;

  case 785:
#line 3729 "fgl.yacc"
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

  case 786:
#line 3752 "fgl.yacc"
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

  case 788:
#line 3770 "fgl.yacc"
    {
		if (!print_linked_cmd('S',yyvsp[0].str)) yyerror("Not a linked variable");
	}
    break;

  case 789:
#line 3776 "fgl.yacc"
    {
		 if (!print_linked_cmd('D',yyvsp[0].str)) yyerror("Not a linked variable");
	}
    break;

  case 790:
#line 3782 "fgl.yacc"
    {
		 if (!print_linked_cmd('U',yyvsp[0].str)) yyerror("Not a linked variable");
}
    break;

  case 791:
#line 3788 "fgl.yacc"
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

  case 792:
#line 3799 "fgl.yacc"
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

  case 793:
#line 3822 "fgl.yacc"
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

  case 796:
#line 3838 "fgl.yacc"
    {
	}
    break;

  case 803:
#line 3861 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 807:
#line 3869 "fgl.yacc"
    {
		print_at_termination(yyvsp[0].str);
	}
    break;

  case 825:
#line 3895 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 826:
#line 3896 "fgl.yacc"
    {
strcpy(yyval.str,"static ");
}
    break;

  case 827:
#line 3904 "fgl.yacc"
    {
  clr_variable(); lastlineno=yylineno;
  clr_function_constants (); 
}
    break;

  case 828:
#line 3909 "fgl.yacc"
    { 
  sprintf(curr_func,"%s",yyvsp[-1].str);
  addmap("Declare Function",curr_func,"MODULE",yylineno,infilename);
  print_func_start(yyvsp[-3].str,yyvsp[-1].str,0);
  printDeclareFunctionStack(yyvsp[-1].str);
  cnt=0;
}
    break;

  case 829:
#line 3917 "fgl.yacc"
    {
  lex_printcomment("/* new function %s parameters*/\n",yyvsp[-1].str);
  push_blockcommand("FUNC");
  lex_printcomment("/* define section */\n");
}
    break;

  case 830:
#line 3923 "fgl.yacc"
    {
  int c;
  lex_printcomment("/*end of define section */\n");
	print_variables();
  c=print_param('f');
  printPushFunction();
  print_func_args(c);
}
    break;

  case 832:
#line 3938 "fgl.yacc"
    {
    printPopFunction();
    print_func_defret0();
    pop_blockcommand("FUNC");
    print_func_end();
    clr_function_constants ();
    lex_printcomment("/*end function*/\n");
  }
    break;

  case 833:
#line 3951 "fgl.yacc"
    { 
    lastlineno=yylineno;
    sprintf(curr_func,"MAIN");
    clr_variable(); 
    push_blockcommand("MAIN"); 
    addmap("MAIN",curr_func,"MODULE",yylineno,infilename);
    print_main_1();
  }
    break;

  case 834:
#line 3960 "fgl.yacc"
    {
	print_variables();
    printDeclareFunctionStack("MAIN");
    print_fgllib_start(hdr_dbname);
    printInitFunctionStack();
    printPushFunction();
  }
    break;

  case 835:
#line 3967 "fgl.yacc"
    {
pop_blockcommand("MAIN");
print_main_end();
lex_printcomment("/*end main */\n");}
    break;

  case 836:
#line 3974 "fgl.yacc"
    {
    printPopFunction();
    print_return(atoi(yyvsp[0].str));
  }
    break;

  case 837:
#line 3980 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 838:
#line 3980 "fgl.yacc"
    {
lex_printcomment("/* Got expr list */");
sprintf(yyval.str,"%s",yyvsp[0].str);}
    break;

  case 839:
#line 3985 "fgl.yacc"
    {open_db(yyvsp[0].str);
			strcpy(hdr_dbname,yyvsp[0].str);
			lastlineno=yylineno;}
    break;

  case 840:
#line 3990 "fgl.yacc"
    {
}
    break;

  case 846:
#line 4002 "fgl.yacc"
    {
strcpy(curr_func,"[Globals]");
set_current_variable_scope('g');
lex_printcomment("/* start of globals */\n");
}
    break;

  case 848:
#line 4010 "fgl.yacc"
    {
	lex_printcomment("/* end of globals */");
	debug("end of globals\n");
	lastlineno=yylineno;
	set_current_variable_scope('m');
}
    break;

  case 849:
#line 4016 "fgl.yacc"
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

  case 850:
#line 4030 "fgl.yacc"
    {
  addmap("Define Member Function",curr_func,"MODULE",yylineno,infilename);
}
    break;

  case 851:
#line 4034 "fgl.yacc"
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

  case 852:
#line 4047 "fgl.yacc"
    {
	print_variables();
  lex_printcomment("/*end of define section */\n");
  print_param('f');
  printPushFunction();
  print_func_args(atoi(yyvsp[-3].str));
}
    break;

  case 854:
#line 4065 "fgl.yacc"
    {
	start_state("menu",1);
   	menu_cnt=npush_menu();
   	menu_cmd_cnt[menu_cnt]=1;
   	push_blockcommand("MENU");
	print_menu_1();
	}
    break;

  case 855:
#line 4072 "fgl.yacc"
    {
	start_state("menu",0);
	}
    break;

  case 856:
#line 4078 "fgl.yacc"
    {
   print_end_menu_1();
   add_continue_blockcommand ("MENU");
print_end_menu_2();
   pop_blockcommand("MENU");
   pop_menu();
}
    break;

  case 857:
#line 4089 "fgl.yacc"
    {
	 lex_printcomment("/* Block%d_m2 (Before menu) */",menu_cnt);
		print_menu_block(-2) ;
                  }
    break;

  case 858:
#line 4093 "fgl.yacc"
    {
		print_menu_block_end();
	}
    break;

  case 859:
#line 4100 "fgl.yacc"
    {
debug("Menu=%d menu cnt=%d",menu_cnt,menu_cmd_cnt[menu_cnt]);
		push_command(menu_cnt,menu_cmd_cnt[menu_cnt],yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);
		lex_printcomment("/* Block%d_%d */",menu_cnt,menu_cmd_cnt[menu_cnt]-1);
		print_menu_block(menu_cmd_cnt[menu_cnt]-1);
		menu_cmd_cnt[menu_cnt]++;
		}
    break;

  case 860:
#line 4107 "fgl.yacc"
    {
		print_menu_block_end();
}
    break;

  case 861:
#line 4113 "fgl.yacc"
    {
		push_command(menu_cnt,menu_cmd_cnt[menu_cnt],yyvsp[-1].str,"\"\"","\"\"",0);
		print_menu_block(menu_cmd_cnt[menu_cnt]-1);
		menu_cmd_cnt[menu_cnt]++;
		}
    break;

  case 862:
#line 4118 "fgl.yacc"
    {
		print_menu_block_end();
}
    break;

  case 865:
#line 4125 "fgl.yacc"
    {strcpy(yyval.str,"\"EMPTY\"");}
    break;

  case 866:
#line 4126 "fgl.yacc"
    {sprintf(yyval.str,"\"%s\"",yyvsp[0].str);}
    break;

  case 867:
#line 4128 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str); }
    break;

  case 868:
#line 4129 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 869:
#line 4132 "fgl.yacc"
    {strcpy(yyval.str,"\"\"");}
    break;

  case 870:
#line 4133 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 871:
#line 4134 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 872:
#line 4136 "fgl.yacc"
    {
	print_option_op('N',yyvsp[0].str);
}
    break;

  case 873:
#line 4141 "fgl.yacc"
    {
	print_option_op('S',yyvsp[0].str);
}
    break;

  case 874:
#line 4146 "fgl.yacc"
    {
	print_option_op('H',yyvsp[0].str);
}
    break;

  case 875:
#line 4153 "fgl.yacc"
    {sprintf(yyval.str,"MENU_ALL");}
    break;

  case 879:
#line 4160 "fgl.yacc"
    {sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 880:
#line 4162 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);  
push_menu_title(yyval.str);}
    break;

  case 881:
#line 4164 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str); 
push_menu_title(yyval.str);}
    break;

  case 882:
#line 4173 "fgl.yacc"
    {
                strcpy(menuhandler,yyvsp[0].str);
	sprintf(curr_func,"%s",yyvsp[0].str); 
	print_gtk_menuhandler_1(yyvsp[0].str);
                push_blockcommand("MENUH");
}
    break;

  case 883:
#line 4179 "fgl.yacc"
    {
		print_variables();
        }
    break;

  case 884:
#line 4183 "fgl.yacc"
    {
                        pop_blockcommand("MENUH");
			print_gtk_menuhandler_end();
                }
    break;

  case 887:
#line 4195 "fgl.yacc"
    {

		print_gtk_menuhandler_bsm();

                push_blockcommand("BSM");
        }
    break;

  case 888:
#line 4200 "fgl.yacc"
    {
                pop_blockcommand("BSM");
		print_gtk_menuhandler_bsm_end();

        }
    break;

  case 889:
#line 4205 "fgl.yacc"
    {
print_gtk_menuhandler_on(yyvsp[0].str);
                push_blockcommand("ON");
        }
    break;

  case 890:
#line 4208 "fgl.yacc"
    {
                pop_blockcommand("ON");
		print_gtk_menuhandler_on_end();
}
    break;

  case 891:
#line 4217 "fgl.yacc"
    {start_state("message",0);}
    break;

  case 892:
#line 4220 "fgl.yacc"
    {
		print_message(0,"0",0);
		start_state("message",0);
	   }
    break;

  case 893:
#line 4224 "fgl.yacc"
    { 
		print_message(0,yyvsp[-1].str,atoi(yyvsp[0].str));
		start_state("message",0);
	  }
    break;

  case 894:
#line 4228 "fgl.yacc"
    { 
		print_message(0,"0",atoi(yyvsp[0].str));
		start_state("message",0);
	  }
    break;

  case 901:
#line 4245 "fgl.yacc"
    {start_state("message",1);}
    break;

  case 903:
#line 4247 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 904:
#line 4247 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 905:
#line 4250 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 906:
#line 4260 "fgl.yacc"
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

  case 908:
#line 4297 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 910:
#line 4304 "fgl.yacc"
    { 
         sprintf (yyval.str, "%s.%s", yyvsp[-1].str, yyvsp[0].str); 
         lex_printcomment("/* record building -> %s */\n",yyval.str);
         }
    break;

  case 911:
#line 4309 "fgl.yacc"
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

  case 915:
#line 4353 "fgl.yacc"
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

  case 916:
#line 4367 "fgl.yacc"
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

  case 921:
#line 4391 "fgl.yacc"
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

  case 922:
#line 4445 "fgl.yacc"
    {
		debug("---> Subscript or substring");
		strcpy(yyval.str,yyvsp[-1].str);
	}
    break;

  case 923:
#line 4450 "fgl.yacc"
    {
		debug("---> Subscript & substring");
		sprintf(yyval.str,"%s:%s",yyvsp[-4].str,yyvsp[-1].str);
	}
    break;

  case 924:
#line 4458 "fgl.yacc"
    {
debug("List element");
  sprintf (yyval.str, "%s", yyvsp[0].str);
}
    break;

  case 925:
#line 4463 "fgl.yacc"
    {
debug("List element continues");
  sprintf (yyval.str, "%s,%s", yyvsp[-2].str, yyvsp[0].str);
}
    break;

  case 926:
#line 4471 "fgl.yacc"
    {
  sprintf (yyval.str, "%s", yyvsp[0].str);
}
    break;

  case 927:
#line 4477 "fgl.yacc"
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

  case 928:
#line 4497 "fgl.yacc"
    {
		debug("Array..");
}
    break;

  case 929:
#line 4500 "fgl.yacc"
    { sprintf (yyval.str, "%s.%s", yyvsp[-3].str, yyvsp[0].str); }
    break;

  case 930:
#line 4502 "fgl.yacc"
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

  case 935:
#line 4550 "fgl.yacc"
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

  case 936:
#line 4602 "fgl.yacc"
    {
start_bind('f',0);
start_bind('O',0);
strcpy(yyval.str,"0");}
    break;

  case 938:
#line 4609 "fgl.yacc"
    {
start_bind('f',yyvsp[0].str);
start_bind('O',yyvsp[0].str);
sprintf(yyval.str,"1");
}
    break;

  case 939:
#line 4615 "fgl.yacc"
    {
int c;
c=add_bind('f',yyvsp[0].str);
c=add_bind('O',yyvsp[0].str);
sprintf(yyval.str,"%d",c); 
}
    break;

  case 940:
#line 4626 "fgl.yacc"
    {
lex_printcomment("/*STarted bind %s*/\n",yyvsp[0].str);
start_bind('i',yyvsp[0].str);
lex_printcomment("/*STarted bind 2*/\n");
strcpy(yyval.str,"");
}
    break;

  case 941:
#line 4633 "fgl.yacc"
    {
lex_printcomment("/* Added */\n");
add_bind('i',yyvsp[0].str);
strcpy(yyval.str,"");
}
    break;

  case 943:
#line 4641 "fgl.yacc"
    {sprintf(yyval.str,"%s.%s",yyvsp[-2].str,yyvsp[-1].str);}
    break;

  case 944:
#line 4644 "fgl.yacc"
    {lex_printcomment("/* Variable */\n");}
    break;

  case 945:
#line 4645 "fgl.yacc"
    { debug("Got an ibind thru..."); sprintf(yyval.str,"%s\n%s",yyvsp[-2].str,yyvsp[0].str); }
    break;

  case 947:
#line 4647 "fgl.yacc"
    {sprintf(yyval.str,"\"%s\"",yyvsp[0].str);}
    break;

  case 948:
#line 4648 "fgl.yacc"
    {sprintf(yyval.str,"\"%s\"",yyvsp[0].str);}
    break;

  case 949:
#line 4651 "fgl.yacc"
    {
start_bind('o',yyvsp[0].str);
}
    break;

  case 950:
#line 4654 "fgl.yacc"
    {
add_bind('o',yyvsp[0].str);
strcpy(yyval.str,"");
}
    break;

  case 951:
#line 4660 "fgl.yacc"
    {
	addmap("OBIND",yyvsp[0].str,curr_func,yylineno,infilename);
	}
    break;

  case 952:
#line 4663 "fgl.yacc"
    { debug("Got an obind thru..."); sprintf(yyval.str,"%s\n%s",yyvsp[-2].str,yyvsp[0].str); }
    break;

  case 953:
#line 4667 "fgl.yacc"
    {
lex_printcomment("/* start obind with  %s*/\n",yyvsp[0].str);
start_bind('o',yyvsp[0].str);
}
    break;

  case 954:
#line 4671 "fgl.yacc"
    {
lex_printcomment("/* add to obind %s */\n",yyvsp[0].str);
add_bind('o',yyvsp[0].str);
strcpy(yyval.str,"");
}
    break;

  case 955:
#line 4678 "fgl.yacc"
    {
lex_printcomment("/* Read variable %s*/\n",yyvsp[0].str);
}
    break;

  case 956:
#line 4683 "fgl.yacc"
    {
    lex_printcomment("/* use_arr_var */\n");
    start_arr_bind('o',yyvsp[0].str);
    lex_printcomment("/* use_arr_var complete */\n");
}
    break;

  case 957:
#line 4690 "fgl.yacc"
    {
start_bind('O',yyvsp[0].str);
}
    break;

  case 958:
#line 4693 "fgl.yacc"
    {
               add_bind('O',yyvsp[0].str);
               strcpy(yyval.str,"");
}
    break;

  case 963:
#line 4706 "fgl.yacc"
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

  case 964:
#line 4719 "fgl.yacc"
    {
lex_printcomment("/*STarted bind %s*/\n",yyvsp[0].str);
start_bind('N',yyvsp[0].str);
lex_printcomment("/*STarted bind 2*/\n");
strcpy(yyval.str,"");
}
    break;

  case 965:
#line 4726 "fgl.yacc"
    {
lex_printcomment("/* Added */\n");
add_bind('N',yyvsp[0].str);
strcpy(yyval.str,"");
}
    break;

  case 966:
#line 4733 "fgl.yacc"
    {
		strcpy(yyval.str,yyvsp[0].str);
	}
    break;

  case 967:
#line 4736 "fgl.yacc"
    {
			sprintf(yyval.str,"%s\n%s",yyvsp[-2].str,yyvsp[0].str);
		}
    break;

  case 968:
#line 4750 "fgl.yacc"
    {
form_attrib.iswindow=1;
print_open_window(yyvsp[-5].str,yyvsp[-1].str);
sprintf(yyval.str,"open window");
}
    break;

  case 973:
#line 4767 "fgl.yacc"
    {
	print_niy("OPEN_STATUSBOX");
}
    break;

  case 974:
#line 4772 "fgl.yacc"
    {
addmap("Call Formhandler",yyvsp[0].str,curr_func,yylineno,infilename); 
}
    break;

  case 975:
#line 4778 "fgl.yacc"
    {
		print_open_form(yyvsp[0].str,yyvsp[-1].str,yyvsp[-1].str);
		}
    break;

  case 977:
#line 4785 "fgl.yacc"
    { form_attrib.iswindow=0;strcpy(yyval.str,"open_form(%s);"); }
    break;

  case 978:
#line 4790 "fgl.yacc"
    {sprintf(yyval.str,"open_gui_form(%%s,%s,%s,%s,hnd_e_%s,hnd_c_%s);",yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[0].str,yyvsp[0].str);}
    break;

  case 979:
#line 4793 "fgl.yacc"
    {strcpy(yyval.str,"0,0");}
    break;

  case 980:
#line 4794 "fgl.yacc"
    {sprintf(yyval.str,"%s,2",yyvsp[-5].str);}
    break;

  case 981:
#line 4797 "fgl.yacc"
    {strcpy(yyval.str,"\"\"");}
    break;

  case 982:
#line 4798 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 983:
#line 4801 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 984:
#line 4802 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 985:
#line 4807 "fgl.yacc"
    {
print_open_session(yyvsp[-3].str,yyvsp[-1].str,yyvsp[0].str);

}
    break;

  case 986:
#line 4814 "fgl.yacc"
    {
	print_open_cursor(yyvsp[0].str,"0");
}
    break;

  case 987:
#line 4817 "fgl.yacc"
    {
	print_open_cursor(yyvsp[-3].str,yyvsp[0].str); /* CHANGED from $<str>4 */
}
    break;

  case 988:
#line 4823 "fgl.yacc"
    {sprintf(yyval.str,"0,0");}
    break;

  case 989:
#line 4825 "fgl.yacc"
    {sprintf(yyval.str,"%s, %s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 990:
#line 4827 "fgl.yacc"
    {sprintf(yyval.str,"%s, %s",yyvsp[-3].str,yyvsp[0].str);}
    break;

  case 991:
#line 4829 "fgl.yacc"
    {sprintf(yyval.str,"%s, %s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 992:
#line 4832 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 993:
#line 4832 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 994:
#line 4833 "fgl.yacc"
    {strcpy(yyval.str,"2");}
    break;

  case 995:
#line 4838 "fgl.yacc"
    {
	print_open_session(yyvsp[-1].str,yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 996:
#line 4846 "fgl.yacc"
    {strcpy(yyval.str,"\"default_conn\"");}
    break;

  case 997:
#line 4847 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 998:
#line 4852 "fgl.yacc"
    {sprintf(yyval.str,"0,0");}
    break;

  case 999:
#line 4854 "fgl.yacc"
    {sprintf(yyval.str,"%s, %s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1000:
#line 4856 "fgl.yacc"
    {sprintf(yyval.str,"%s, %s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1004:
#line 4873 "fgl.yacc"
    {
print_options('C',yyvsp[0].str);
}
    break;

  case 1005:
#line 4876 "fgl.yacc"
    {
print_options('E',yyvsp[0].str);
}
    break;

  case 1006:
#line 4879 "fgl.yacc"
    {
print_options('F',yyvsp[0].str);
}
    break;

  case 1007:
#line 4882 "fgl.yacc"
    {
lex_printc("set_option_value('M',%s);\n",yyvsp[0].str);
}
    break;

  case 1008:
#line 4885 "fgl.yacc"
    {
print_options('m',yyvsp[0].str);
}
    break;

  case 1009:
#line 4888 "fgl.yacc"
    {
print_options('P',yyvsp[0].str);
}
    break;

  case 1010:
#line 4891 "fgl.yacc"
    {
print_options('A',yyvsp[0].str);
iskey=0;
}
    break;

  case 1011:
#line 4895 "fgl.yacc"
    {
print_options('D',yyvsp[0].str);
iskey=0;
}
    break;

  case 1012:
#line 4899 "fgl.yacc"
    {
print_options('I',yyvsp[0].str);
iskey=0;
}
    break;

  case 1013:
#line 4903 "fgl.yacc"
    {
print_options('N',yyvsp[0].str);
}
    break;

  case 1014:
#line 4906 "fgl.yacc"
    {
print_options('p',yyvsp[0].str);
iskey=0;
}
    break;

  case 1015:
#line 4910 "fgl.yacc"
    {
print_options('H',yyvsp[0].str);
}
    break;

  case 1016:
#line 4913 "fgl.yacc"
    { print_set_helpfile(yyvsp[0].str); }
    break;

  case 1017:
#line 4914 "fgl.yacc"
    { print_set_langfile(yyvsp[0].str); }
    break;

  case 1018:
#line 4915 "fgl.yacc"
    {
print_options('d',yyvsp[0].str);
}
    break;

  case 1019:
#line 4918 "fgl.yacc"
    {
print_options('i',yyvsp[0].str);
}
    break;

  case 1020:
#line 4921 "fgl.yacc"
    {
print_options('W',"1");
}
    break;

  case 1021:
#line 4924 "fgl.yacc"
    {
print_options('W',"0");
}
    break;

  case 1022:
#line 4927 "fgl.yacc"
    {
print_options('f',"1");
}
    break;

  case 1023:
#line 4930 "fgl.yacc"
    {
print_options('f',"0");
}
    break;

  case 1024:
#line 4933 "fgl.yacc"
    {
print_options('S',"1");
}
    break;

  case 1025:
#line 4936 "fgl.yacc"
    {
print_options('S',"0");
}
    break;

  case 1026:
#line 4953 "fgl.yacc"
    {
	print_prepare(yyvsp[-2].str,yyvsp[0].str);
	addmap("Prepare",yyvsp[-2].str,curr_func,yylineno,infilename);
	print_undo_use(yyvsp[-4].str);
}
    break;

  case 1029:
#line 4963 "fgl.yacc"
    {

print_execute(yyvsp[0].str,0);

addmap("Execute",yyvsp[0].str,curr_func,yylineno,infilename);
}
    break;

  case 1030:
#line 4970 "fgl.yacc"
    {
	addmap("Execute",yyvsp[-2].str,curr_func,yylineno,infilename);
	print_execute(yyvsp[-2].str,1);
}
    break;

  case 1032:
#line 4991 "fgl.yacc"
    {
                push_blockcommand("PROMPT");

	print_prompt_1(yyvsp[-5].str,yyvsp[-3].str,yyvsp[-1].str,yyvsp[0].str) ;
}
    break;

  case 1033:
#line 4996 "fgl.yacc"
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

  case 1034:
#line 5009 "fgl.yacc"
    {
		print_niy("GUI PROMPT");
	}
    break;

  case 1035:
#line 5014 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 1036:
#line 5015 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 1037:
#line 5019 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1041:
#line 5025 "fgl.yacc"
    {
	print_onkey_1(yyvsp[0].str);
}
    break;

  case 1042:
#line 5027 "fgl.yacc"
    {
	print_onkey_2_prompt();
}
    break;

  case 1044:
#line 5042 "fgl.yacc"
    {
		start_bind('i',0);
		}
    break;

  case 1045:
#line 5046 "fgl.yacc"
    {
		print_put();
	}
    break;

  case 1046:
#line 5052 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1047:
#line 5053 "fgl.yacc"
    { strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1048:
#line 5056 "fgl.yacc"
    {push_gen(PUTVAL,yyvsp[0].str);}
    break;

  case 1049:
#line 5057 "fgl.yacc"
    {push_gen(PUTVAL,yyvsp[0].str); sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1052:
#line 5073 "fgl.yacc"
    {
addmap("Start Report",yyvsp[-1].str,curr_func,yylineno,infilename);
print_start_report("P","\"lp\"",yyvsp[-1].str);
}
    break;

  case 1053:
#line 5078 "fgl.yacc"
    {
addmap("Start Report",yyvsp[-2].str,curr_func,yylineno,infilename);
print_start_report("F",yyvsp[0].str,yyvsp[-2].str);
}
    break;

  case 1054:
#line 5083 "fgl.yacc"
    {
addmap("Start Report",yyvsp[-2].str,curr_func,yylineno,infilename);
print_start_report("P",yyvsp[0].str,yyvsp[-2].str);
}
    break;

  case 1055:
#line 5088 "fgl.yacc"
    {
addmap("Start Report",yyvsp[0].str,curr_func,yylineno,infilename);
print_start_report("","\"\"",yyvsp[0].str);
}
    break;

  case 1061:
#line 5110 "fgl.yacc"
    {
addmap("Output to report",yyvsp[-5].str,curr_func,yylineno,infilename);
print_output_to_report(yyvsp[-5].str,yyvsp[-1].str); 
}
    break;

  case 1062:
#line 5117 "fgl.yacc"
    {
addmap("Finish Report",yyvsp[0].str,curr_func,yylineno,infilename);
print_finish_report(yyvsp[0].str);
}
    break;

  case 1063:
#line 5123 "fgl.yacc"
    { strcpy(yyval.str,yyvsp[0].str); }
    break;

  case 1064:
#line 5125 "fgl.yacc"
    {
	print_format_every_row();
}
    break;

  case 1068:
#line 5136 "fgl.yacc"
    { push_report_block("FIRST",'P');}
    break;

  case 1069:
#line 5137 "fgl.yacc"
    {print_rep_ret(0);}
    break;

  case 1070:
#line 5139 "fgl.yacc"
    { push_report_block("TRAILER",'T');}
    break;

  case 1071:
#line 5140 "fgl.yacc"
    {print_rep_ret(0);}
    break;

  case 1072:
#line 5142 "fgl.yacc"
    { push_report_block("HEADER",'p');}
    break;

  case 1073:
#line 5143 "fgl.yacc"
    {print_rep_ret(0);}
    break;

  case 1074:
#line 5145 "fgl.yacc"
    { push_report_block("EVERY",'E');}
    break;

  case 1075:
#line 5146 "fgl.yacc"
    {print_rep_ret(0);}
    break;

  case 1076:
#line 5148 "fgl.yacc"
    { push_report_block("LAST",'L');}
    break;

  case 1077:
#line 5149 "fgl.yacc"
    {print_rep_ret(0);}
    break;

  case 1078:
#line 5150 "fgl.yacc"
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

  case 1079:
#line 5164 "fgl.yacc"
    {print_rep_ret(0);}
    break;

  case 1080:
#line 5166 "fgl.yacc"
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

  case 1081:
#line 5183 "fgl.yacc"
    {print_rep_ret(0);}
    break;

  case 1088:
#line 5195 "fgl.yacc"
    {start_state("skip",1);}
    break;

  case 1089:
#line 5195 "fgl.yacc"
    {
	print_need_lines();
	start_state("skip",0);
}
    break;

  case 1090:
#line 5201 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 1091:
#line 5201 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 1092:
#line 5204 "fgl.yacc"
    {start_state("KWLINE",1);}
    break;

  case 1093:
#line 5204 "fgl.yacc"
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

  case 1094:
#line 5214 "fgl.yacc"
    { print_skip_top(); }
    break;

  case 1095:
#line 5215 "fgl.yacc"
    { print_niy("FONT SIZE"); }
    break;

  case 1096:
#line 5216 "fgl.yacc"
    {
			if (rep_type!=REP_TYPE_PDF) {
				yyerror("SKIP BY is only in PDF reports");
				YYERROR;
			}
			print_skip_by(yyvsp[0].str);
		}
    break;

  case 1097:
#line 5223 "fgl.yacc"
    {
			if (rep_type!=REP_TYPE_PDF) {
				yyerror("SKIP TO is only in PDF reports");
				YYERROR;
			}
			print_skip_to(yyvsp[0].str);
		}
    break;

  case 1098:
#line 5235 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1104:
#line 5246 "fgl.yacc"
    {
	print_niy("PRINT AT...");
}
    break;

  case 1105:
#line 5251 "fgl.yacc"
    {
	print_report_print(0,yyvsp[0].str,0);
}
    break;

  case 1106:
#line 5255 "fgl.yacc"
    { 
	print_report_print_file(yyvsp[-1].str,yyvsp[0].str);
}
    break;

  case 1107:
#line 5260 "fgl.yacc"
    { 
	print_report_print_img(yyvsp[-1].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 1108:
#line 5266 "fgl.yacc"
    { strcpy(yyval.str,get_default_scaling());}
    break;

  case 1109:
#line 5267 "fgl.yacc"
    { strcpy(yyval.str,yyvsp[0].str); strcat(yyval.str,yyvsp[0].str); }
    break;

  case 1110:
#line 5268 "fgl.yacc"
    {sprintf(yyval.str,"%s %s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1111:
#line 5272 "fgl.yacc"
    {strcpy(yyval.str,"tiff");}
    break;

  case 1112:
#line 5273 "fgl.yacc"
    {strcpy(yyval.str,"gif");}
    break;

  case 1113:
#line 5274 "fgl.yacc"
    {strcpy(yyval.str,"png");}
    break;

  case 1114:
#line 5275 "fgl.yacc"
    {strcpy(yyval.str,"jpeg");}
    break;

  case 1115:
#line 5279 "fgl.yacc"
    {
	int vtype;
	vtype=scan_variable(yyvsp[0].str);
	if (vtype!=11&&vtype!=12) {
	yyerror("Only Blobs may be printed...");
	YYERROR;
	}
}
    break;

  case 1116:
#line 5289 "fgl.yacc"
    {
strcpy(yyval.str,"0");
}
    break;

  case 1117:
#line 5291 "fgl.yacc"
    {
strcpy(yyval.str,"1");
}
    break;

  case 1118:
#line 5296 "fgl.yacc"
    {
	print_report_print(1,0,yyvsp[0].str);
	}
    break;

  case 1119:
#line 5299 "fgl.yacc"
    {
	print_report_print(1,0,yyvsp[0].str); /* changed from $<str>1 */
}
    break;

  case 1120:
#line 5304 "fgl.yacc"
    {
	strcpy(yyval.str,yyvsp[0].str); 
	}
    break;

  case 1121:
#line 5311 "fgl.yacc"
    {
int a;
a=add_report_agg('S',yyvsp[-2].ptr,yyvsp[0].ptr,racnt);
sprintf(yyval.str,"push_double(_g%d);\n",racnt);
racnt+=a;
}
    break;

  case 1122:
#line 5318 "fgl.yacc"
    {
int a;
a=add_report_agg('C',0,yyvsp[0].ptr,racnt);
sprintf(yyval.str,"push_int(_g%d);\n",racnt);
racnt+=a;
}
    break;

  case 1123:
#line 5325 "fgl.yacc"
    {
int a;
a=add_report_agg('C',0,yyvsp[0].ptr,racnt);
sprintf(yyval.str,"push_int(_g%d);\n",racnt);
racnt+=a;
}
    break;

  case 1124:
#line 5334 "fgl.yacc"
    {
int a;
a=add_report_agg('P',yyvsp[-2].ptr,yyvsp[0].ptr,racnt);
sprintf(yyval.str,"push_double((double)_g%d/(double)_g%d);\n",racnt,racnt+1);
racnt+=a;
}
    break;

  case 1125:
#line 5341 "fgl.yacc"
    {
int a;
a=add_report_agg('A',yyvsp[-2].ptr,yyvsp[0].ptr,racnt);
sprintf(yyval.str,"push_double(_g%d/(double)_g%d);\n",racnt,racnt+1);
racnt+=a;
}
    break;

  case 1126:
#line 5348 "fgl.yacc"
    {
int a;
a=add_report_agg('A',yyvsp[-2].ptr,yyvsp[0].ptr,racnt);
sprintf(yyval.str,"push_double(_g%d/_g%d);\n",racnt,racnt+1);
racnt+=a;
}
    break;

  case 1127:
#line 5355 "fgl.yacc"
    {
int a;
a=add_report_agg('N',yyvsp[-2].ptr,yyvsp[0].ptr,racnt);
sprintf(yyval.str,"push_double(_g%d);\n",racnt);
racnt+=a;
}
    break;

  case 1128:
#line 5362 "fgl.yacc"
    {
int a;
a=add_report_agg('X',yyvsp[-2].ptr,yyvsp[0].ptr,racnt);
sprintf(yyval.str,"push_double(_g%d);\n",racnt);
racnt+=a;
}
    break;

  case 1133:
#line 5375 "fgl.yacc"
    {rep_struct.left_margin=atoi(yyvsp[0].str);}
    break;

  case 1134:
#line 5376 "fgl.yacc"
    {rep_struct.right_margin=atoi(yyvsp[0].str);}
    break;

  case 1135:
#line 5377 "fgl.yacc"
    {rep_struct.top_margin=atoi(yyvsp[0].str);}
    break;

  case 1136:
#line 5378 "fgl.yacc"
    {rep_struct.bottom_margin=atoi(yyvsp[0].str);}
    break;

  case 1137:
#line 5379 "fgl.yacc"
    {rep_struct.page_length=atoi(yyvsp[0].str);}
    break;

  case 1138:
#line 5380 "fgl.yacc"
    { rep_struct.output_mode='P';strcpy(rep_struct.output_loc,"\"lp\"");}
    break;

  case 1139:
#line 5381 "fgl.yacc"
    {rep_struct.output_mode='F';strcpy(rep_struct.output_loc,yyvsp[0].str);}
    break;

  case 1140:
#line 5382 "fgl.yacc"
    {rep_struct.output_mode='F';strcpy(rep_struct.output_loc,yyvsp[0].str);}
    break;

  case 1141:
#line 5383 "fgl.yacc"
    {rep_struct.output_mode='P';strcpy(rep_struct.output_loc,yyvsp[0].str);}
    break;

  case 1142:
#line 5384 "fgl.yacc"
    {strcpy(rep_struct.top_of_page,yyvsp[0].str);}
    break;

  case 1145:
#line 5390 "fgl.yacc"
    {sprintf(yyval.str,"-%f",atof(yyvsp[-1].str));}
    break;

  case 1146:
#line 5391 "fgl.yacc"
    {sprintf(yyval.str,"-%f",atof(yyvsp[-1].str)*72.0); }
    break;

  case 1147:
#line 5392 "fgl.yacc"
    {sprintf(yyval.str,"-%f",atof(yyvsp[-1].str)*2.83465);}
    break;

  case 1148:
#line 5393 "fgl.yacc"
    {sprintf(yyval.str,"%f",atof(yyvsp[0].str));}
    break;

  case 1153:
#line 5402 "fgl.yacc"
    {pdf_rep_struct.left_margin=atof(yyvsp[0].str);debug("Left margin=%s\n",yyvsp[0].str);}
    break;

  case 1154:
#line 5403 "fgl.yacc"
    {pdf_rep_struct.right_margin=atof(yyvsp[0].str);}
    break;

  case 1155:
#line 5404 "fgl.yacc"
    {pdf_rep_struct.top_margin=atof(yyvsp[0].str);}
    break;

  case 1156:
#line 5405 "fgl.yacc"
    {pdf_rep_struct.bottom_margin=atof(yyvsp[0].str);}
    break;

  case 1157:
#line 5406 "fgl.yacc"
    {pdf_rep_struct.page_length=atof(yyvsp[0].str);}
    break;

  case 1158:
#line 5407 "fgl.yacc"
    {pdf_rep_struct.page_width=atof(yyvsp[0].str);}
    break;

  case 1159:
#line 5408 "fgl.yacc"
    {strcpy(pdf_rep_struct.font_name,yyvsp[0].str);}
    break;

  case 1160:
#line 5409 "fgl.yacc"
    {pdf_rep_struct.font_size=atof(yyvsp[0].str);}
    break;

  case 1161:
#line 5411 "fgl.yacc"
    {pdf_rep_struct.paper_size=1;}
    break;

  case 1162:
#line 5412 "fgl.yacc"
    {pdf_rep_struct.paper_size=2;}
    break;

  case 1163:
#line 5413 "fgl.yacc"
    {pdf_rep_struct.paper_size=3;}
    break;

  case 1164:
#line 5414 "fgl.yacc"
    {pdf_rep_struct.paper_size=5;}
    break;

  case 1165:
#line 5416 "fgl.yacc"
    {pdf_rep_struct.paper_size=-1;}
    break;

  case 1166:
#line 5417 "fgl.yacc"
    {pdf_rep_struct.paper_size=-2;}
    break;

  case 1167:
#line 5418 "fgl.yacc"
    {pdf_rep_struct.paper_size=-3;}
    break;

  case 1168:
#line 5419 "fgl.yacc"
    {pdf_rep_struct.paper_size=-5;}
    break;

  case 1172:
#line 5424 "fgl.yacc"
    {pdf_rep_struct.output_mode='F';strcpy(pdf_rep_struct.output_loc,yyvsp[0].str);}
    break;

  case 1173:
#line 5425 "fgl.yacc"
    {pdf_rep_struct.output_mode='P';strcpy(pdf_rep_struct.output_loc,yyvsp[0].str);}
    break;

  case 1177:
#line 5432 "fgl.yacc"
    {
int a;
a=print_bind('O');
print_order_by_type(2);
sprintf(yyval.str,"%d",a);
}
    break;

  case 1178:
#line 5439 "fgl.yacc"
    {
int a;
a=print_bind('O');
print_order_by_type(1);
sprintf(yyval.str,"%d",a);
debug("Order by Gives :%d\n",a);
}
    break;

  case 1179:
#line 5446 "fgl.yacc"
    {
int a;
a=print_bind('O');
print_order_by_type(2);
sprintf(yyval.str,"%d",a);
debug("Order by Gives :%d\n",a);
}
    break;

  case 1180:
#line 5457 "fgl.yacc"
    { 
		rep_type=REP_TYPE_NORMAL; 
		clr_function_constants (); 
		clr_variable(); 
		lastlineno=yylineno; 
		init_report_structure(&rep_struct); 
		}
    break;

  case 1181:
#line 5466 "fgl.yacc"
    {
		inc_report_cnt();
		sprintf(curr_func,"%s",yyvsp[-1].str);
		addmap("Define Report",curr_func,"MODULE",yylineno,infilename);
		set_curr_rep_name(yyvsp[-1].str);
		print_report_1(yyvsp[-1].str);
		push_blockcommand("REPORT");
		}
    break;

  case 1182:
#line 5476 "fgl.yacc"
    {
		lastlineno=yylineno;
		}
    break;

  case 1183:
#line 5480 "fgl.yacc"
    {
		print_variables();
		}
    break;

  case 1184:
#line 5484 "fgl.yacc"
    {
		print_report_2(0,yyvsp[0].str);
		rordcnt=atoi(yyvsp[0].str);
		debug("SET rordcnt=%d %s",rordcnt,yyvsp[0].str);
		}
    break;

  case 1185:
#line 5490 "fgl.yacc"
    {
		print_report_ctrl();
		}
    break;

  case 1186:
#line 5495 "fgl.yacc"
    {
		pop_blockcommand("REPORT");
		print_report_end() ;
		}
    break;

  case 1187:
#line 5503 "fgl.yacc"
    { strcpy(yyval.str,"");
	yyval.ptr=0;
}
    break;

  case 1188:
#line 5506 "fgl.yacc"
    {
	yyval.ptr=yyvsp[0].ptr;
//sprintf($<str>$,"%s", $<str>2);
}
    break;

  case 1189:
#line 5515 "fgl.yacc"
    {
if (!in_command("REPORT")) {
	yyerror("PAUSE can only be used in reportes");
	YYERROR;
        }

print_pause(yyvsp[0].str) ;
}
    break;

  case 1190:
#line 5526 "fgl.yacc"
    {strcpy(yyval.str,"\"\"");}
    break;

  case 1192:
#line 5533 "fgl.yacc"
    {
rep_type=REP_TYPE_PDF;
clr_variable(); lastlineno=yylineno; pdf_init_report_structure(&pdf_rep_struct);
}
    break;

  case 1193:
#line 5538 "fgl.yacc"
    {
inc_report_cnt();
sprintf(curr_func,"%s",yyvsp[-1].str);
addmap("Define PDF Report",curr_func,"MODULE",yylineno,infilename);
set_curr_rep_name(yyvsp[-1].str);
print_report_1(yyvsp[-1].str);
push_blockcommand("REPORT");
}
    break;

  case 1194:
#line 5547 "fgl.yacc"
    {
lastlineno=yylineno;
}
    break;

  case 1195:
#line 5550 "fgl.yacc"
    {
	print_variables();
}
    break;

  case 1196:
#line 5554 "fgl.yacc"
    {
print_variables();
resize_paper(&pdf_rep_struct);
	print_report_2(1,yyvsp[0].str);
debug("SET rordcnt=%d (%s)",rordcnt,yyvsp[0].str);
	rordcnt=atoi(yyvsp[0].str);
}
    break;

  case 1197:
#line 5562 "fgl.yacc"
    {
print_report_ctrl();
}
    break;

  case 1198:
#line 5565 "fgl.yacc"
    {
	pop_blockcommand("REPORT");
	print_report_end();
}
    break;

  case 1199:
#line 5571 "fgl.yacc"
    { strcpy(yyval.str,yyvsp[0].str); }
    break;

  case 1200:
#line 5575 "fgl.yacc"
    {new_counter();
   		addmap("CALL",yyvsp[-1].str,curr_func,yylineno,infilename);
   		}
    break;

  case 1201:
#line 5579 "fgl.yacc"
    {
		sprintf(yyval.str,"%d",get_counter_val());drop_counter();
		}
    break;

  case 1202:
#line 5583 "fgl.yacc"
    {
		print_pdf_call(yyvsp[-5].str,yyvsp[-2].ptr,yyvsp[-1].str);
   		}
    break;

  case 1203:
#line 5587 "fgl.yacc"
    {
	print_returning();
   }
    break;

  case 1204:
#line 5593 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 1205:
#line 5594 "fgl.yacc"
    { strcpy(yyval.str,"rep.right_margin"); }
    break;

  case 1206:
#line 5595 "fgl.yacc"
    { sprintf(yyval.str,"%s",yyvsp[0].str); }
    break;

  case 1207:
#line 5596 "fgl.yacc"
    { sprintf(yyval.str,"%s",yyvsp[0].str); }
    break;

  case 1208:
#line 5601 "fgl.yacc"
    {
print_system_run(0,0);
}
    break;

  case 1209:
#line 5603 "fgl.yacc"
    {
print_system_run(1,yyvsp[0].str);
}
    break;

  case 1210:
#line 5606 "fgl.yacc"
    {
print_system_run(2,0);
}
    break;

  case 1211:
#line 5610 "fgl.yacc"
    {
print_system_run(0,0);
}
    break;

  case 1212:
#line 5613 "fgl.yacc"
    {
print_system_run(0,0);
/* FIXME */
}
    break;

  case 1213:
#line 5620 "fgl.yacc"
    {
	print_exec_sql(yyvsp[0].str);
}
    break;

  case 1214:
#line 5625 "fgl.yacc"
    {sprintf(yyval.str, "%s",yyvsp[0].str);}
    break;

  case 1215:
#line 5626 "fgl.yacc"
    {sprintf(yyval.str,  "%s",yyvsp[0].str);}
    break;

  case 1216:
#line 5627 "fgl.yacc"
    {sprintf(yyval.str,"%s",yyvsp[0].str);}
    break;

  case 1217:
#line 5631 "fgl.yacc"
    {
	print_exec_sql(yyvsp[0].str);

}
    break;

  case 1218:
#line 5639 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1219:
#line 5640 "fgl.yacc"
    {insql=1;}
    break;

  case 1220:
#line 5640 "fgl.yacc"
    {insql=0;}
    break;

  case 1221:
#line 5641 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s %s",yyvsp[-6].str,yyvsp[-4].str,yyvsp[-3].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1222:
#line 5642 "fgl.yacc"
    {insql=1;}
    break;

  case 1223:
#line 5642 "fgl.yacc"
    {insql=0;}
    break;

  case 1224:
#line 5643 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s %s %s",yyvsp[-7].str,yyvsp[-5].str,yyvsp[-4].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1225:
#line 5644 "fgl.yacc"
    {
		yyerror("You cannot create a database from within Aubit4gl....");
	}
    break;

  case 1226:
#line 5650 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1227:
#line 5652 "fgl.yacc"
    {sprintf(yyval.str," %s ",yyvsp[0].str);}
    break;

  case 1229:
#line 5659 "fgl.yacc"
    {sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1230:
#line 5663 "fgl.yacc"
    {sprintf(yyval.str,"%s ASC",yyvsp[-1].str);}
    break;

  case 1231:
#line 5664 "fgl.yacc"
    {sprintf(yyval.str,"%s DESC",yyvsp[-1].str);}
    break;

  case 1234:
#line 5671 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1237:
#line 5682 "fgl.yacc"
    {sprintf(yyval.str,"%s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1239:
#line 5688 "fgl.yacc"
    {
	print_exec_sql(yyvsp[0].str);
}
    break;

  case 1240:
#line 5692 "fgl.yacc"
    {
	sprintf(yyval.str,"%s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);
}
    break;

  case 1242:
#line 5699 "fgl.yacc"
    {sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1250:
#line 5715 "fgl.yacc"
    {
		sprintf(yyval.str,"ADD %s",yyvsp[0].str);
	}
    break;

  case 1251:
#line 5718 "fgl.yacc"
    {
		sprintf(yyval.str,"%s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);
	}
    break;

  case 1253:
#line 5726 "fgl.yacc"
    {
		sprintf(yyval.str,"%s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);
	}
    break;

  case 1255:
#line 5733 "fgl.yacc"
    {
		sprintf(yyval.str,"%s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);
	}
    break;

  case 1256:
#line 5740 "fgl.yacc"
    {
		sprintf(yyval.str,"DROP %s",yyvsp[0].str);
	}
    break;

  case 1257:
#line 5743 "fgl.yacc"
    {
		sprintf(yyval.str,"DROP (%s)",yyvsp[-1].str);
	}
    break;

  case 1259:
#line 5751 "fgl.yacc"
    {
		sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);
	}
    break;

  case 1261:
#line 5760 "fgl.yacc"
    {
		sprintf(yyval.str,"MODIFY %s",yyvsp[0].str);
	}
    break;

  case 1262:
#line 5763 "fgl.yacc"
    {
		sprintf(yyval.str,"MODIFY (%s)",yyvsp[-1].str);
	}
    break;

  case 1264:
#line 5770 "fgl.yacc"
    {
		sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);
	}
    break;

  case 1266:
#line 5781 "fgl.yacc"
    {strcpy(yyval.str,"LOCK MODE PAGE");}
    break;

  case 1267:
#line 5782 "fgl.yacc"
    {strcpy(yyval.str,"LOCK MODE ROW");}
    break;

  case 1268:
#line 5786 "fgl.yacc"
    {
		sprintf(yyval.str,"MODIFT NEXT SIZE %d",atoi(yyvsp[0].str));
	}
    break;

  case 1270:
#line 5793 "fgl.yacc"
    {
		sprintf(yyval.str,"ADD CONSTRAINT (%s)",yyvsp[-1].str);
	}
    break;

  case 1272:
#line 5801 "fgl.yacc"
    {
		sprintf(yyval.str,"ADD CONSTRAINT (%s)",yyvsp[-1].str);
	}
    break;

  case 1274:
#line 5807 "fgl.yacc"
    {
		sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);
	}
    break;

  case 1278:
#line 5825 "fgl.yacc"
    {sprintf(yyval.str,"%s %s /*FIXME */",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1284:
#line 5831 "fgl.yacc"
    { 
	print_set_conn(yyvsp[0].str);
}
    break;

  case 1285:
#line 5834 "fgl.yacc"
    {
	print_set_options("conn",yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 1286:
#line 5837 "fgl.yacc"
    {
	print_set_options("stmt",yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 1287:
#line 5843 "fgl.yacc"
    {strcpy(yyval.str,"\"default\"");}
    break;

  case 1289:
#line 5849 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1291:
#line 5860 "fgl.yacc"
    {
		print_sleep();
	}
    break;

  case 1292:
#line 5874 "fgl.yacc"
    {
		strcpy(current_upd_table,yyvsp[0].str);
	}
    break;

  case 1293:
#line 5876 "fgl.yacc"
    {
		strcpy(current_upd_table,"");
	}
    break;

  case 1294:
#line 5880 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s %s",yyvsp[-6].str,yyvsp[-5].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1295:
#line 5883 "fgl.yacc"
    {strcpy(yyval.str,"");
		pop_all_gen(UPDCOL,"!"); pop_all_gen(UPDVAL,"!");
	}
    break;

  case 1296:
#line 5886 "fgl.yacc"
    { 
		pop_all_gen(UPDCOL,"!"); pop_all_gen(UPDVAL,"!");
		rm_quotes(yyvsp[0].str);
		sprintf(yyval.str," %s %s",yyvsp[-1].str,yyvsp[0].str);
	}
    break;

  case 1297:
#line 5891 "fgl.yacc"
    {
		pop_all_gen(UPDCOL,"!"); pop_all_gen(UPDVAL,"!");
		sprintf(yyval.str," %s %s",yyvsp[-1].str,yyvsp[0].str);
	}
    break;

  case 1298:
#line 5899 "fgl.yacc"
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

  case 1300:
#line 5909 "fgl.yacc"
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

  case 1301:
#line 5918 "fgl.yacc"
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

  case 1303:
#line 5938 "fgl.yacc"
    {
sprintf(yyval.str," %s , %s",yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 1305:
#line 5947 "fgl.yacc"
    {
sprintf(yyval.str," %s = %s",yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 1306:
#line 5952 "fgl.yacc"
    {push_gen(UPDCOL,yyvsp[0].str); strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1307:
#line 5953 "fgl.yacc"
    {push_gen(UPDCOL,yyvsp[0].str); sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1309:
#line 5957 "fgl.yacc"
    { sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1310:
#line 5961 "fgl.yacc"
    {push_gen(UPDVAL,"<SUBQUERY>");}
    break;

  case 1311:
#line 5962 "fgl.yacc"
    {push_gen(UPDVAL,"NULL");}
    break;

  case 1313:
#line 5968 "fgl.yacc"
    {
		print_sql_commit(0);
		}
    break;

  case 1314:
#line 5977 "fgl.yacc"
    { insql=1;start_bind('i',0);}
    break;

  case 1315:
#line 5978 "fgl.yacc"
    {
sprintf(yyval.str," %s %s %s %s",yyvsp[-4].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);
}
    break;

  case 1316:
#line 5983 "fgl.yacc"
    {insql=1;}
    break;

  case 1317:
#line 5983 "fgl.yacc"
    {
insql=0;
sprintf(yyval.str," %s %s %s %s" ,yyvsp[-4].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1319:
#line 5989 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1320:
#line 5991 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1322:
#line 5998 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1324:
#line 6004 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1327:
#line 6014 "fgl.yacc"
    {
      print_fetch_1();
    }
    break;

  case 1328:
#line 6018 "fgl.yacc"
    {
      print_fetch_2();
    }
    break;

  case 1329:
#line 6022 "fgl.yacc"
    {
      print_fetch_3(yyvsp[-2].str,yyvsp[0].str);
    }
    break;

  case 1330:
#line 6031 "fgl.yacc"
    {sprintf(yyval.str,"%s,%s",yyvsp[0].str,yyvsp[-1].str);
addmap("Fetch Cursor",yyvsp[0].str,curr_func,yylineno,infilename);
}
    break;

  case 1331:
#line 6035 "fgl.yacc"
    {sprintf(yyval.str,"%s,%d,1",yyvsp[0].str,FETCH_RELATIVE);

addmap("Fetch Cursor",yyvsp[0].str,curr_func,yylineno,infilename);
}
    break;

  case 1332:
#line 6041 "fgl.yacc"
    {
debug("no into\n");
strcpy(yyval.str,"0,0");
}
    break;

  case 1333:
#line 6045 "fgl.yacc"
    {
	debug("FETCH INTO  ...");
	/* start_bind('i',0,-1); */
    start_bind('o',0);
}
    break;

  case 1334:
#line 6051 "fgl.yacc"
    {
	int no;
	no=print_bind('o');
	sprintf(yyval.str,"%d,obind",no);
}
    break;

  case 1335:
#line 6058 "fgl.yacc"
    {
debug("no into\n");
strcpy(yyval.str,"0,0");
}
    break;

  case 1336:
#line 6062 "fgl.yacc"
    {
	debug("FETCH INTO  ...");
	/* start_bind('i',0,-1); */
    start_bind('o',0);
}
    break;

  case 1337:
#line 6067 "fgl.yacc"
    {
/*
int ni;
ni=print_bind('i');
sprintf($<str>$,"%d,ibind",ni);
*/
}
    break;

  case 1338:
#line 6077 "fgl.yacc"
    {
		sprintf(yyval.str,"%d,1",FETCH_ABSOLUTE);}
    break;

  case 1339:
#line 6080 "fgl.yacc"
    {sprintf(yyval.str,"%d,-1",FETCH_ABSOLUTE);}
    break;

  case 1340:
#line 6082 "fgl.yacc"
    {sprintf(yyval.str,"%d,1",FETCH_RELATIVE);}
    break;

  case 1341:
#line 6084 "fgl.yacc"
    {sprintf(yyval.str,"%d,-1",FETCH_RELATIVE);}
    break;

  case 1342:
#line 6086 "fgl.yacc"
    {sprintf(yyval.str,"%d,-1",FETCH_RELATIVE);}
    break;

  case 1343:
#line 6088 "fgl.yacc"
    {sprintf(yyval.str,"%d,0",FETCH_RELATIVE);}
    break;

  case 1344:
#line 6090 "fgl.yacc"
    {sprintf(yyval.str,"%d,pop_int()",FETCH_RELATIVE);}
    break;

  case 1345:
#line 6092 "fgl.yacc"
    {sprintf(yyval.str,"%d,pop_int()",FETCH_ABSOLUTE);}
    break;

  case 1346:
#line 6098 "fgl.yacc"
    {
 
rm_quotes(yyvsp[0].str);
sprintf(yyval.str," %s %s %s %s ",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str
);}
    break;

  case 1347:
#line 6108 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1348:
#line 6113 "fgl.yacc"
    {sprintf(yyval.str,"%s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1350:
#line 6119 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1354:
#line 6128 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1357:
#line 6133 "fgl.yacc"
    {
print_sql_commit(-1);
}
    break;

  case 1358:
#line 6138 "fgl.yacc"
    {
		print_sql_commit(1);
	}
    break;

  case 1359:
#line 6145 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1360:
#line 6146 "fgl.yacc"
    {
		strcpy(yyval.str,"EXCLUSIVE");
	}
    break;

  case 1361:
#line 6153 "fgl.yacc"
    {
if (strcmp(yyvsp[-1].str,"?")==0) {
	print_init_conn(0);
} else {
	print_init_conn(yyvsp[-1].str);
}
}
    break;

  case 1362:
#line 6165 "fgl.yacc"
    {insql=1;}
    break;

  case 1363:
#line 6165 "fgl.yacc"
    {
print_undo_use(yyvsp[-2].str);
insql=0;strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1364:
#line 6170 "fgl.yacc"
    {lex_printcomment("/*  schema */\n");
	print_exec_sql(yyvsp[0].str);

strcpy(yyval.str,"Schema");
}
    break;

  case 1365:
#line 6175 "fgl.yacc"
    {lex_printcomment("/*  schema  2*/\n");

	print_exec_sql(yyvsp[0].str);

strcpy(yyval.str,"Schema Element");
}
    break;

  case 1367:
#line 6182 "fgl.yacc"
    {
	print_exec_sql(yyvsp[0].str);
 }
    break;

  case 1369:
#line 6186 "fgl.yacc"
    {

lex_printcomment("/*  delete 1 */\n");

print_exec_sql_bound(yyvsp[0].str);
strcpy(yyval.str,"Delete where current...");
}
    break;

  case 1370:
#line 6193 "fgl.yacc"
    {

lex_printcomment("/*  delete 2 */\n");

print_exec_sql_bound(yyvsp[0].str);
strcpy(yyval.str,"Delete where ...");
}
    break;

  case 1371:
#line 6200 "fgl.yacc"
    {
strcpy(yyval.str,"Fetch");
lex_printcomment("/*  fetch */\n");
}
    break;

  case 1372:
#line 6204 "fgl.yacc"
    {

lex_printcomment("/*  insert */\n");

print_exec_sql_bound(yyvsp[0].str);


strcpy(yyval.str,"insert");

}
    break;

  case 1374:
#line 6215 "fgl.yacc"
    {
	print_do_select(yyvsp[0].str);
	strcpy(yyval.str,"select");
}
    break;

  case 1375:
#line 6219 "fgl.yacc"
    {

print_exec_sql_bound(yyvsp[0].str);
strcpy(yyval.str,"update");
}
    break;

  case 1376:
#line 6228 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s %s %s %s",yyvsp[-6].str,yyvsp[-5].str,yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1377:
#line 6231 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1378:
#line 6233 "fgl.yacc"
    {sprintf(yyval.str," %s ",yyvsp[0].str);}
    break;

  case 1379:
#line 6238 "fgl.yacc"
    {sprintf(yyval.str," %s ",yyvsp[0].str);}
    break;

  case 1382:
#line 6245 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1386:
#line 6252 "fgl.yacc"
    {sprintf(yyval.str," %s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1387:
#line 6255 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1388:
#line 6257 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1390:
#line 6263 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1392:
#line 6269 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1395:
#line 6280 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s %s %s",yyvsp[-5].str,yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1396:
#line 6283 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1397:
#line 6285 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1399:
#line 6291 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1400:
#line 6294 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1402:
#line 6301 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1403:
#line 6307 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s %s",yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1404:
#line 6312 "fgl.yacc"
    {sprintf(yyval.str," %s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1407:
#line 6322 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1409:
#line 6328 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1410:
#line 6334 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1411:
#line 6336 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1413:
#line 6342 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1417:
#line 6355 "fgl.yacc"
    {sprintf(yyval.str," %s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1418:
#line 6357 "fgl.yacc"
    {sprintf(yyval.str," %s",yyvsp[0].str);}
    break;

  case 1419:
#line 6368 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1420:
#line 6371 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1422:
#line 6375 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1423:
#line 6377 "fgl.yacc"
    {sprintf(yyval.str," %s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1424:
#line 6382 "fgl.yacc"
    {sprintf(yyval.str," %s ",yyvsp[0].str);}
    break;

  case 1425:
#line 6384 "fgl.yacc"
    {sprintf(yyval.str," %s ",yyvsp[0].str);}
    break;

  case 1427:
#line 6387 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1428:
#line 6393 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1429:
#line 6398 "fgl.yacc"
    {sprintf(yyval.str," %s",yyvsp[0].str);}
    break;

  case 1432:
#line 6408 "fgl.yacc"
    {sprintf(yyval.str," %s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1435:
#line 6423 "fgl.yacc"
    {sprintf(yyval.str," %s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1436:
#line 6429 "fgl.yacc"
    {sprintf(yyval.str," %s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1439:
#line 6439 "fgl.yacc"
    {sprintf(yyval.str,"%s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1440:
#line 6444 "fgl.yacc"
    {sprintf(yyval.str,"%s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1442:
#line 6450 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1443:
#line 6454 "fgl.yacc"
    {sprintf(yyval.str," %s ", yyvsp[0].str);}
    break;

  case 1444:
#line 6455 "fgl.yacc"
    {sprintf(yyval.str," %s %s ",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1445:
#line 6456 "fgl.yacc"
    {sprintf(yyval.str," %s (%s) ",yyvsp[-3].str,yyvsp[-1].str);}
    break;

  case 1447:
#line 6460 "fgl.yacc"
    {sprintf(yyval.str,"%s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1449:
#line 6465 "fgl.yacc"
    { sprintf(yyval.str," %s,%s ",yyvsp[-2].str,yyvsp[0].str);  }
    break;

  case 1450:
#line 6473 "fgl.yacc"
    {
sprintf(yyval.str,"%s %s %s %s",
yyvsp[-3].str,yyvsp[-2].str,
yyvsp[-1].str,yyvsp[0].str);
}
    break;

  case 1451:
#line 6480 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1452:
#line 6481 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1453:
#line 6484 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1454:
#line 6485 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1455:
#line 6488 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1456:
#line 6489 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1458:
#line 6496 "fgl.yacc"
    {sprintf(yyval.str,"%s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1460:
#line 6502 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1462:
#line 6508 "fgl.yacc"
    {sprintf(yyval.str," %s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1464:
#line 6514 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1465:
#line 6519 "fgl.yacc"
    {sprintf(yyval.str," %s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1466:
#line 6520 "fgl.yacc"
    {sprintf(yyval.str," %s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1467:
#line 6526 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1468:
#line 6528 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1469:
#line 6532 "fgl.yacc"
    {strcpy(yyval.str," ALL ");}
    break;

  case 1475:
#line 6551 "fgl.yacc"
    {sprintf(yyval.str," %s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1478:
#line 6565 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s %s",yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1479:
#line 6567 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1480:
#line 6569 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s %s",yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1481:
#line 6571 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1483:
#line 6578 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1486:
#line 6584 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1488:
#line 6591 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1489:
#line 6593 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1490:
#line 6595 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1491:
#line 6597 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1492:
#line 6599 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s %s %s",yyvsp[-5].str,yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1493:
#line 6601 "fgl.yacc"
    {sprintf(yyval.str," %s %s Like %s %s",yyvsp[-4].str,yyvsp[-3].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1495:
#line 6607 "fgl.yacc"
    {strcpy(yyval.str,"!=");}
    break;

  case 1501:
#line 6613 "fgl.yacc"
    {strcpy(yyval.str,"likE");}
    break;

  case 1502:
#line 6614 "fgl.yacc"
    {strcpy(yyval.str,"<=");}
    break;

  case 1503:
#line 6615 "fgl.yacc"
    {strcpy(yyval.str,">=");}
    break;

  case 1508:
#line 6625 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1511:
#line 6628 "fgl.yacc"
    {
		ansi_violation("Use DISTINCT not UNIQUE",0);
		strcpy(yyval.str,"DISTINCT ");
	}
    break;

  case 1516:
#line 6648 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1517:
#line 6653 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s %s",yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1518:
#line 6654 "fgl.yacc"
    {strcpy(yyval.str,"SERIAL");}
    break;

  case 1520:
#line 6657 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s %s",yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1524:
#line 6662 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1526:
#line 6665 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1528:
#line 6668 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s %s %s %s",yyvsp[-6].str,yyvsp[-5].str,yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1532:
#line 6673 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1533:
#line 6675 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s %s %s",yyvsp[-5].str,yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1534:
#line 6678 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1535:
#line 6679 "fgl.yacc"
    {
		sprintf(yyval.str,",%s",yyvsp[0].str);
}
    break;

  case 1536:
#line 6686 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1540:
#line 6691 "fgl.yacc"
    {sprintf(yyval.str," %s",yyvsp[0].str);}
    break;

  case 1544:
#line 6707 "fgl.yacc"
    { sprintf(yyval.str,"\\\"%s\\\"%s%s",strip_quotes(yyvsp[-2].str),yyvsp[-1].str,yyvsp[0].str); addmap("Use Table",yyval.str,curr_func,yylineno,infilename); }
    break;

  case 1545:
#line 6708 "fgl.yacc"
    {
		sprintf(yyval.str," %s",strip_quotes(yyvsp[0].str));
		addmap("Use Table",yyval.str,curr_func,yylineno,infilename);
	}
    break;

  case 1546:
#line 6712 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str); addmap("Use Table",yyvsp[0].str,curr_func,yylineno,infilename); }
    break;

  case 1547:
#line 6713 "fgl.yacc"
    { sprintf(yyval.str," %s%s%s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str); addmap("Use Table",yyval.str,curr_func,yylineno,infilename); }
    break;

  case 1549:
#line 6728 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1550:
#line 6729 "fgl.yacc"
    {sprintf(yyval.str,"[%s]",yyvsp[-1].str);}
    break;

  case 1551:
#line 6730 "fgl.yacc"
    {sprintf(yyval.str,"[%s,%s]",yyvsp[-3].str,yyvsp[-1].str);}
    break;

  case 1552:
#line 6734 "fgl.yacc"
    { 
addmap("Use Column",yyvsp[-1].str,curr_func,yylineno,infilename);
sprintf(yyval.str,"%s%s",yyvsp[-1].str,yyvsp[0].str);
}
    break;

  case 1553:
#line 6739 "fgl.yacc"
    {
sprintf(yyval.str,"%s.%s%s",yyvsp[-4].str,yyvsp[-1].str,yyvsp[0].str);
addmap("Use Column",yyval.str,curr_func,yylineno,infilename);
}
    break;

  case 1554:
#line 6744 "fgl.yacc"
    {
sprintf(yyval.str,"%s.%s",yyvsp[-3].str,yyvsp[0].str);
addmap("Use Column",yyval.str,curr_func,yylineno,infilename);
}
    break;

  case 1556:
#line 6757 "fgl.yacc"
    {
	strcpy(yyval.str,convstrsql(yyvsp[0].str));
	debug("Set $<str>$ to %s\n",yyval.str);
}
    break;

  case 1560:
#line 6765 "fgl.yacc"
    {sprintf(yyval.str," %s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1561:
#line 6767 "fgl.yacc"
    {sprintf(yyval.str," %s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1562:
#line 6769 "fgl.yacc"
    {sprintf(yyval.str," %s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1563:
#line 6771 "fgl.yacc"
    {sprintf(yyval.str," %s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1565:
#line 6776 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1566:
#line 6779 "fgl.yacc"
    {sprintf(yyval.str," %s %s ",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1567:
#line 6782 "fgl.yacc"
    {strcpy(yyval.str," YEAR TO SECOND ");}
    break;

  case 1568:
#line 6784 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1569:
#line 6787 "fgl.yacc"
    {strcpy(yyval.str,"0,17");}
    break;

  case 1570:
#line 6789 "fgl.yacc"
    {sprintf(yyval.str," %s ,%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1571:
#line 6792 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 1572:
#line 6792 "fgl.yacc"
    {strcpy(yyval.str,"5");}
    break;

  case 1573:
#line 6792 "fgl.yacc"
    {strcpy(yyval.str,"8");}
    break;

  case 1574:
#line 6792 "fgl.yacc"
    {strcpy(yyval.str,"11");}
    break;

  case 1575:
#line 6792 "fgl.yacc"
    {strcpy(yyval.str,"14");}
    break;

  case 1576:
#line 6792 "fgl.yacc"
    {strcpy(yyval.str,"17");}
    break;

  case 1577:
#line 6793 "fgl.yacc"
    {
strcpy(yyval.str,"23");
}
    break;

  case 1578:
#line 6796 "fgl.yacc"
    {
strcpy(yyval.str,"23");
}
    break;

  case 1579:
#line 6801 "fgl.yacc"
    {strcpy(yyval.str,"4");}
    break;

  case 1580:
#line 6801 "fgl.yacc"
    {strcpy(yyval.str,"7");}
    break;

  case 1581:
#line 6801 "fgl.yacc"
    {strcpy(yyval.str,"10");}
    break;

  case 1582:
#line 6801 "fgl.yacc"
    {strcpy(yyval.str,"13");}
    break;

  case 1583:
#line 6801 "fgl.yacc"
    {strcpy(yyval.str,"16");}
    break;

  case 1584:
#line 6801 "fgl.yacc"
    {strcpy(yyval.str,"19");}
    break;

  case 1585:
#line 6803 "fgl.yacc"
    {
strcpy(yyval.str,"25");
}
    break;

  case 1586:
#line 6806 "fgl.yacc"
    {
strcpy(yyval.str,"25");
}
    break;

  case 1601:
#line 6815 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1602:
#line 6816 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1603:
#line 6820 "fgl.yacc"
    {
	print_flush_cursor(yyvsp[0].str);
		addmap("Flush Cursor",yyvsp[0].str,curr_func,yylineno,infilename);
print_undo_use(yyvsp[-2].str);
		}
    break;

  case 1604:
#line 6829 "fgl.yacc"
    {insql=0;chk4var=0;}
    break;

  case 1605:
#line 6829 "fgl.yacc"
    {
print_declare(yyvsp[0].str,yyvsp[-2].str,yyvsp[-5].str,0,0);
addmap("Declare Cursor",yyvsp[-5].str,curr_func,yylineno,infilename);
print_undo_use(yyvsp[-7].str);
}
    break;

  case 1606:
#line 6834 "fgl.yacc"
    {insql=0;chk4var=0;}
    break;

  case 1607:
#line 6834 "fgl.yacc"
    {
print_declare(yyvsp[0].str,yyvsp[-2].str,yyvsp[-6].str,2,0); 
addmap("Declare Cursor",yyvsp[-6].str,curr_func,yylineno,infilename);
print_undo_use(yyvsp[-8].str);
}
    break;

  case 1608:
#line 6840 "fgl.yacc"
    {insql=0;chk4var=0;}
    break;

  case 1609:
#line 6841 "fgl.yacc"
    {
print_declare(yyvsp[0].str,yyvsp[-2].str,yyvsp[-4].str,0,1); 
addmap("Declare Cursor",yyvsp[-4].str,curr_func,yylineno,infilename);
print_undo_use(yyvsp[-6].str);
}
    break;

  case 1610:
#line 6846 "fgl.yacc"
    {insql=0;chk4var=0;}
    break;

  case 1611:
#line 6847 "fgl.yacc"
    {
print_declare(yyvsp[0].str,yyvsp[-2].str,yyvsp[-6].str,0,1); 
addmap("Declare Cursor",yyvsp[-6].str,curr_func,yylineno,infilename);
print_undo_use(yyvsp[-8].str);
}
    break;

  case 1612:
#line 6856 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 1613:
#line 6857 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 1614:
#line 6858 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 1618:
#line 6865 "fgl.yacc"
    {sprintf(yyval.str,"%s.%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1619:
#line 6866 "fgl.yacc"
    {sprintf(yyval.str,"\\\"%s\\\".%s.%s",strip_quotes(yyvsp[-4].str),yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1621:
#line 6872 "fgl.yacc"
    { 
		strcpy(yyval.str,print_curr_spec(1,yyvsp[0].str));
	}
    break;

  case 1622:
#line 6878 "fgl.yacc"
    {
		strcpy(yyval.str,print_curr_spec(2,yyvsp[0].str));
}
    break;

  case 1624:
#line 6887 "fgl.yacc"
    {
	sprintf(yyval.str,"%s",yyvsp[-1].str);
	if (atoi(yyvsp[0].str)) {
		printf("Warning SELECT ... FOR UPDATE when not declaring a cursor currently has no locking effect\n");
	}

	}
    break;

  case 1625:
#line 6900 "fgl.yacc"
    {debug("Got select list...\n");}
    break;

  case 1626:
#line 6902 "fgl.yacc"
    { /* start_bind('i',0,-1); */ start_bind('i',0); lex_printcomment("/* startbind */"); }
    break;

  case 1627:
#line 6904 "fgl.yacc"
    {
             char buff[1024];
             sprintf(buff,"%s %s %s %s %s %s", yyvsp[-7].str, yyvsp[-6].str, yyvsp[-5].str, yyvsp[-3].str, yyvsp[-1].str,yyvsp[0].str);
	     debug("call print_select_all with %s\n",buff);
	     strcpy(yyval.str,print_select_all(buff));

}
    break;

  case 1628:
#line 6915 "fgl.yacc"
    {
             char buff[1024];

             sprintf(buff,"%s %s %s %s %s", yyvsp[-4].str, yyvsp[-3].str, yyvsp[-2].str, yyvsp[-1].str, yyvsp[0].str);
             sprintf(yyval.str,"push_char(\"%s\");",buff);
}
    break;

  case 1631:
#line 6931 "fgl.yacc"
    {sprintf(yyval.str,"%s %s %s %s %s %s %s", yyvsp[-6].str, yyvsp[-5].str, yyvsp[-4].str, yyvsp[-3].str, yyvsp[-2].str, yyvsp[-1].str, yyvsp[0].str);}
    break;

  case 1632:
#line 6935 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1633:
#line 6936 "fgl.yacc"
    {
       lex_printcomment("/* UNION */");
       sprintf(yyval.str,"%s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);
       }
    break;

  case 1635:
#line 6941 "fgl.yacc"
    { sprintf(yyval.str,"%s %s %s ",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str); }
    break;

  case 1636:
#line 6942 "fgl.yacc"
    { sprintf(yyval.str,"%s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str); }
    break;

  case 1638:
#line 6949 "fgl.yacc"
    { start_bind('o',0);strcpy(yyval.str,""); }
    break;

  case 1639:
#line 6950 "fgl.yacc"
    { 
		
		strcpy(yyval.str,get_into_part(get_bind_cnt('o'))); 
	}
    break;

  case 1640:
#line 6960 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s",yyvsp[-4].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1641:
#line 6965 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s %s %s %s",yyvsp[-6].str,yyvsp[-5].str,yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1642:
#line 6968 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1643:
#line 6969 "fgl.yacc"
    {strcpy(yyval.str,"ALL");}
    break;

  case 1644:
#line 6970 "fgl.yacc"
    {strcpy(yyval.str,"DISTINCT");}
    break;

  case 1645:
#line 6971 "fgl.yacc"
    {strcpy(yyval.str,"DISTINCT");
		ansi_violation("Use DISTINCT not UNIQUE",0);
		strcpy(yyval.str,"DISTINCT ");

}
    break;

  case 1647:
#line 6980 "fgl.yacc"
    { sprintf(yyval.str," %s,%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1649:
#line 6985 "fgl.yacc"
    {sprintf(yyval.str," %s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1650:
#line 6986 "fgl.yacc"
    {sprintf(yyval.str," %s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1652:
#line 6996 "fgl.yacc"
    {push_gen(UPDVAL,yyvsp[0].str);}
    break;

  case 1654:
#line 7002 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1655:
#line 7004 "fgl.yacc"
    {sprintf(yyval.str," %s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1656:
#line 7006 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1657:
#line 7008 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1658:
#line 7010 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1663:
#line 7015 "fgl.yacc"
    {sprintf(yyval.str," %s ",yyvsp[0].str);}
    break;

  case 1664:
#line 7017 "fgl.yacc"
    {sprintf(yyval.str," %s",yyvsp[0].str);}
    break;

  case 1665:
#line 7019 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s %s",yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1666:
#line 7021 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s %s",yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1667:
#line 7023 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s %s",yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1668:
#line 7025 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s %s",yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1669:
#line 7027 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s %s",yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1670:
#line 7029 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1671:
#line 7031 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s %s %s",yyvsp[-5].str,yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1672:
#line 7032 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1673:
#line 7033 "fgl.yacc"
    {sprintf(yyval.str,"extend(%s)",yyvsp[-1].str);}
    break;

  case 1678:
#line 7043 "fgl.yacc"
    {

print_unload(yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);
print_undo_use(yyvsp[-4].str);
}
    break;

  case 1679:
#line 7051 "fgl.yacc"
    {
print_load(yyvsp[-4].str,yyvsp[-3].str,yyvsp[-1].str,yyvsp[0].str);
print_undo_use(yyvsp[-6].str);
}
    break;

  case 1680:
#line 7056 "fgl.yacc"
    {strcpy(yyval.str,"\"|\"");}
    break;

  case 1681:
#line 7056 "fgl.yacc"
    {
strcpy(yyval.str,yyvsp[0].str);
}
    break;

  case 1683:
#line 7060 "fgl.yacc"
    {
if ((scan_variable(yyvsp[0].str)&15)!=0) {yyerror("Variable must be of type char for a delimiter..");YYERROR;}
}
    break;

  case 1684:
#line 7065 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 1685:
#line 7065 "fgl.yacc"
    {
sprintf(yyval.str,"%s,0",yyvsp[-1].str);
}
    break;

  case 1687:
#line 7069 "fgl.yacc"
    {
    sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 1688:
#line 7073 "fgl.yacc"
    {
     sprintf(yyval.str,"\"%s\"",yyvsp[0].str);
}
    break;

  case 1691:
#line 7082 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1692:
#line 7082 "fgl.yacc"
    {
print_use_session(yyvsp[0].str);
strcpy(yyval.str,get_undo_use());
}
    break;

  case 1697:
#line 7101 "fgl.yacc"
    { sprintf(yyval.str,"%s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str); }
    break;

  case 1698:
#line 7102 "fgl.yacc"
    { sprintf(yyval.str,"%s %s %s %s",yyvsp[-5].str,yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str); }
    break;

  case 1701:
#line 7110 "fgl.yacc"
    {
		sprintf(yyval.str,"%s %s",yyvsp[-1].str,yyvsp[0].str);
	}
    break;

  case 1702:
#line 7116 "fgl.yacc"
    {
		sprintf(yyval.str,"%s %s %s",
					yyvsp[-2].str,
					yyvsp[-1].str,
					yyvsp[0].str
					);
		}
    break;

  case 1705:
#line 7135 "fgl.yacc"
    {strcpy(yyval.str,"UNITS YEAR");}
    break;

  case 1706:
#line 7136 "fgl.yacc"
    {strcpy(yyval.str,"UNITS MONTH"); }
    break;

  case 1707:
#line 7137 "fgl.yacc"
    {strcpy(yyval.str,"UNITS DAY);"); }
    break;

  case 1708:
#line 7138 "fgl.yacc"
    {strcpy(yyval.str,"UNITS HOUR);"); }
    break;

  case 1709:
#line 7139 "fgl.yacc"
    {strcpy(yyval.str,"UNITS MINUTE);"); }
    break;

  case 1710:
#line 7140 "fgl.yacc"
    {strcpy(yyval.str,"UNITS SECOND);"); }
    break;

  case 1711:
#line 7144 "fgl.yacc"
    {sprintf(yyval.str,"%s %s %s %s %s",yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1712:
#line 7145 "fgl.yacc"
    {sprintf(yyval.str,"%s %s %s %s %s",yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1713:
#line 7146 "fgl.yacc"
    {sprintf(yyval.str,"%s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1714:
#line 7230 "fgl.yacc"
    {
	if (scan_variable(yyvsp[0].str)!=-1)
	{
		print_push_variable(yyvsp[0].str);
		strcpy(yyval.str,"?");
	}
}
    break;

  case 1715:
#line 7241 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1719:
#line 7247 "fgl.yacc"
    {sprintf(yyval.str,"%s.%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1720:
#line 7248 "fgl.yacc"
    {sprintf(yyval.str,"\\\"%s\\\".%s.%s",strip_quotes(yyvsp[-4].str),yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1724:
#line 7258 "fgl.yacc"
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

  case 1725:
#line 7270 "fgl.yacc"
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

  case 1726:
#line 7368 "fgl.yacc"
    {set_whenever(WHEN_NOTFOUND|atoi(yyvsp[0].str),0);}
    break;

  case 1727:
#line 7370 "fgl.yacc"
    {set_whenever(WHEN_SQLERROR|atoi(yyvsp[0].str),0);}
    break;

  case 1728:
#line 7372 "fgl.yacc"
    {set_whenever(WHEN_ANYERROR|atoi(yyvsp[0].str),0);}
    break;

  case 1729:
#line 7373 "fgl.yacc"
    {
 		set_whento("");
		set_whenever(WHEN_ERROR+WHEN_CONTINUE,0);
}
    break;

  case 1730:
#line 7378 "fgl.yacc"
    {
debug("Whenever error...%d %d",WHEN_ERROR,atoi(yyvsp[0].str));
set_whenever(WHEN_ERROR+atoi(yyvsp[0].str),0);
}
    break;

  case 1731:
#line 7383 "fgl.yacc"
    {set_whenever(WHEN_SQLWARNING|atoi(yyvsp[0].str),0);}
    break;

  case 1732:
#line 7385 "fgl.yacc"
    {set_whenever(WHEN_WARNING|atoi(yyvsp[0].str),0);}
    break;

  case 1733:
#line 7387 "fgl.yacc"
    {set_whenever(WHEN_SUCCESS|atoi(yyvsp[0].str),0);}
    break;

  case 1734:
#line 7389 "fgl.yacc"
    {set_whenever(WHEN_SQLSUCCESS|atoi(yyvsp[0].str),0);}
    break;

  case 1735:
#line 7392 "fgl.yacc"
    {
 set_whento("");
			sprintf(yyval.str,"%d",WHEN_CONTINUE); }
    break;

  case 1736:
#line 7396 "fgl.yacc"
    {
set_whento(yyvsp[0].str);
sprintf(yyval.str,"%d",WHEN_GOTO);
 }
    break;

  case 1737:
#line 7401 "fgl.yacc"
    {
set_whento(yyvsp[0].str); 
sprintf(yyval.str,"%d",WHEN_GOTO);
}
    break;

  case 1738:
#line 7406 "fgl.yacc"
    { set_whento(""); 
sprintf(yyval.str,"%d",WHEN_STOP);
}
    break;

  case 1739:
#line 7410 "fgl.yacc"
    {
set_whento(yyvsp[0].str);
sprintf(yyval.str,"%d",WHEN_CALL);
}
    break;

  case 1741:
#line 7420 "fgl.yacc"
    {sprintf(yyval.str,"%s",yyvsp[0].str);}
    break;

  case 1743:
#line 7435 "fgl.yacc"
    {
print_while_1();
push_blockcommand("WHILE");
}
    break;

  case 1744:
#line 7438 "fgl.yacc"
    {
print_while_2();
}
    break;

  case 1745:
#line 7442 "fgl.yacc"
    {
print_while_3();
pop_blockcommand("WHILE");
}
    break;

  case 1748:
#line 7461 "fgl.yacc"
    { strcpy(yyval.str,"0"); }
    break;

  case 1749:
#line 7462 "fgl.yacc"
    { strcpy(yyval.str,"1"); }
    break;

  case 1750:
#line 7465 "fgl.yacc"
    { print_clr_window("\"screen\""); }
    break;

  case 1751:
#line 7466 "fgl.yacc"
    { print_clr_window(yyvsp[0].str); }
    break;

  case 1752:
#line 7467 "fgl.yacc"
    { print_clr_window(yyvsp[0].str); }
    break;

  case 1753:
#line 7468 "fgl.yacc"
    { print_clr_form(0,0,"0"); }
    break;

  case 1754:
#line 7469 "fgl.yacc"
    { print_clr_form(0,0,"1"); }
    break;

  case 1755:
#line 7470 "fgl.yacc"
    { print_clr_form(yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str); }
    break;

  case 1756:
#line 7471 "fgl.yacc"
    {
	print_clr_fields(yyvsp[-1].str,yyvsp[0].str);
}
    break;

  case 1757:
#line 7476 "fgl.yacc"
    {sprintf(yyval.str,"%s",yyvsp[0].str);}
    break;

  case 1758:
#line 7477 "fgl.yacc"
    {sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1759:
#line 7481 "fgl.yacc"
    {
	print_current_window("\"screen\"");
}
    break;

  case 1760:
#line 7485 "fgl.yacc"
    {
	print_current_window(yyvsp[0].str);
}
    break;

  case 1761:
#line 7489 "fgl.yacc"
    {
sprintf(yyval.str,"cr_window");
reset_attrib(&form_attrib);
}
    break;

  case 1762:
#line 7493 "fgl.yacc"
    {
sprintf(yyval.str,"cr_window_form");
reset_attrib(&form_attrib);
}
    break;

  case 1763:
#line 7498 "fgl.yacc"
    {
	print_show_window(yyvsp[0].str);
	addmap("Show Window",yyvsp[0].str,curr_func,yylineno,infilename); 
}
    break;

  case 1764:
#line 7502 "fgl.yacc"
    {
	print_show_menu(yyvsp[-3].str,yyvsp[-1].str);
	addmap("Call Menuhandler",yyvsp[-1].str,curr_func,yylineno,infilename); 
}
    break;

  case 1765:
#line 7507 "fgl.yacc"
    {

print_def_mn_file();

}
    break;

  case 1767:
#line 7515 "fgl.yacc"
    {addmap("Use Menu",yyvsp[0].str,curr_func,yylineno,infilename); }
    break;

  case 1769:
#line 7521 "fgl.yacc"
    {
	print_hide_window(yyvsp[0].str);
}
    break;

  case 1770:
#line 7527 "fgl.yacc"
    {
print_move_window(yyvsp[-4].str,0);
}
    break;

  case 1771:
#line 7531 "fgl.yacc"
    {
print_move_window(yyvsp[-4].str,1);
}
    break;

  case 1776:
#line 7549 "fgl.yacc"
    {
chk4var=0;lex_printcomment("/* [Comm:%s] */\n",yyval.str);
if (acl_getenv("INCLINES"))
lex_printc("{debug(\"Line %d %s:%s\");}",lastlineno,infilename,convstrsql(larr));
	prchkerr(lastlineno,infilename);
	lastlineno=yylineno;
}
    break;

  case 1777:
#line 7556 "fgl.yacc"
    {
lex_printcomment("/* [COMM:%s] */\n",yyvsp[0].str);chk4var=0;
if (acl_getenv("INCLINES"))
lex_printc("{debug(\"Line %d %s:%s\");}",lastlineno,infilename,convstrsql(larr));
if (aubit_strcasecmp(yyval.str,"whenever")!=0) prchkerr(lastlineno,infilename);
lastlineno=yylineno;
}
    break;

  case 1778:
#line 7565 "fgl.yacc"
    {print_cmd_start();}
    break;

  case 1779:
#line 7565 "fgl.yacc"
    {print_cmd_end();}
    break;


    }

/* Line 991 of yacc.c.  */
#line 15687 "y.tab.c"

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


#line 7658 "fgl.yacc"

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



