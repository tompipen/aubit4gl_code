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
char *		make_sql_string(char *first,...);

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
#line 188 "fgl.yacc"
typedef union YYSTYPE {



	char	str[3100];  /* This would core dump in CygWin on call to */
						/* yyparse in y.tab.c - 3100 in maximum. */
						/* Was: char	str[20000]; */

	struct expr_str *ptr;
	char *sql_string;

	} YYSTYPE;
/* Line 191 of yacc.c.  */
#line 1500 "y.tab.c"
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 214 of yacc.c.  */
#line 1512 "y.tab.c"

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
#define YYLAST   8412

/* YYNTOKENS -- Number of terminals. */
#define YYNTOKENS  647
/* YYNNTS -- Number of nonterminals. */
#define YYNNTS  817
/* YYNRULES -- Number of rules. */
#define YYNRULES  1879
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
    3573,  3577,  3579,  3581,  3584,  3586,  3590,  3592,  3596,  3598,
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
    4075,  4077,  4079,  4082,  4084,  4089,  4090,  4092,  4093,  4095,
    4097,  4100,  4102,  4104,  4106,  4111,  4115,  4117,  4119,  4121,
    4124,  4126,  4128,  4131,  4134,  4136,  4140,  4143,  4146,  4148,
    4152,  4154,  4157,  4162,  4164,  4167,  4169,  4173,  4178,  4179,
    4181,  4182,  4184,  4185,  4187,  4189,  4193,  4195,  4199,  4201,
    4204,  4206,  4210,  4213,  4216,  4221,  4225,  4226,  4228,  4230,
    4232,  4234,  4236,  4239,  4241,  4243,  4249,  4253,  4259,  4263,
    4265,  4269,  4271,  4273,  4274,  4276,  4280,  4284,  4288,  4292,
    4299,  4305,  4307,  4309,  4311,  4313,  4315,  4317,  4319,  4321,
    4323,  4325,  4327,  4329,  4331,  4333,  4334,  4336,  4338,  4340,
    4342,  4344,  4346,  4348,  4353,  4359,  4361,  4367,  4373,  4375,
    4377,  4379,  4384,  4386,  4391,  4393,  4401,  4403,  4405,  4407,
    4412,  4419,  4420,  4423,  4428,  4430,  4432,  4434,  4436,  4438,
    4440,  4442,  4446,  4448,  4450,  4454,  4456,  4457,  4461,  4467,
    4470,  4476,  4481,  4483,  4485,  4487,  4489,  4491,  4494,  4497,
    4500,  4503,  4505,  4508,  4511,  4512,  4516,  4517,  4521,  4523,
    4525,  4527,  4529,  4531,  4533,  4535,  4540,  4542,  4544,  4546,
    4548,  4550,  4552,  4554,  4559,  4561,  4563,  4565,  4567,  4569,
    4571,  4573,  4575,  4577,  4579,  4581,  4583,  4585,  4587,  4589,
    4591,  4595,  4596,  4605,  4606,  4616,  4617,  4625,  4626,  4636,
    4637,  4639,  4642,  4644,  4648,  4650,  4654,  4660,  4662,  4664,
    4666,  4668,  4671,  4672,  4673,  4682,  4688,  4690,  4692,  4700,
    4701,  4705,  4707,  4711,  4716,  4718,  4719,  4722,  4728,  4736,
    4737,  4739,  4741,  4743,  4745,  4749,  4751,  4754,  4757,  4759,
    4761,  4763,  4767,  4770,  4774,  4778,  4782,  4784,  4786,  4788,
    4790,  4792,  4794,  4800,  4806,  4812,  4818,  4824,  4829,  4836,
    4840,  4845,  4847,  4851,  4852,  4854,  4860,  4868,  4869,  4872,
    4874,  4876,  4877,  4881,  4883,  4887,  4889,  4891,  4893,  4894,
    4898,  4900,  4902,  4904,  4906,  4911,  4918,  4920,  4922,  4925,
    4929,  4931,  4933,  4935,  4937,  4939,  4941,  4943,  4945,  4951,
    4957,  4962,  4964,  4967,  4969,  4971,  4973,  4977,  4983,  4985,
    4987,  4989,  4991,  4995,  4998,  5001,  5004,  5006,  5009,  5012,
    5015,  5018,  5021,  5023,  5027,  5030,  5032,  5035,  5037,  5040,
    5042,  5043,  5044,  5051,  5052,  5055,  5056,  5058,  5060,  5063,
    5066,  5068,  5070,  5075,  5079,  5081,  5085,  5087,  5090,  5096,
    5099,  5102,  5108,  5109,  5112,  5114,  5116,  5119,  5126,  5133,
    5135,  5136,  5138,  5141,  5143,  5146,  5147,  5150,  5152,  5154,
    5156,  5158,  5160,  5162,  5164,  5166,  5168,  5170,  5172,  5174,
    5176,  5178,  5180,  5182,  5184,  5186,  5188,  5190,  5192,  5194,
    5196,  5198,  5200,  5202,  5204,  5206,  5208,  5210,  5212,  5214,
    5216,  5218,  5220,  5222,  5224,  5226,  5228,  5230,  5232,  5234,
    5236,  5238,  5240,  5242,  5244,  5246,  5248,  5250,  5252,  5254,
    5256,  5258,  5260,  5262,  5264,  5266,  5268,  5270,  5272,  5274,
    5276,  5278,  5280,  5282,  5284,  5286,  5288,  5290,  5292,  5294,
    5296,  5298,  5300,  5302,  5304,  5306,  5308,  5310,  5312,  5314
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
      -1,    -1,    -1,   382,   872,   909,   873,  1277,   874,  1458,
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
      -1,  1227,    -1,  1226,     5,  1227,    -1,  1317,    -1,  1315,
      -1,    99,   915,    -1,   158,    -1,    33,   915,  1230,    -1,
    1231,    -1,  1230,     5,  1231,    -1,  1232,    -1,  1235,    -1,
    1238,    -1,  1243,    -1,  1244,    -1,  1242,    -1,  1241,    -1,
     563,  1233,    -1,   563,   409,  1234,   370,    -1,  1227,    -1,
    1227,   643,   915,    -1,  1233,    -1,  1234,     5,  1233,    -1,
     520,  1237,    -1,   520,   409,  1236,   370,    -1,  1237,    -1,
    1236,     5,  1237,    -1,   915,    -1,   433,  1240,    -1,   433,
     409,  1239,   370,    -1,  1240,    -1,  1239,     5,  1240,    -1,
    1227,    -1,    64,    -1,    65,    -1,    63,    25,    -1,    35,
    1321,    -1,    35,   409,  1245,   370,    -1,    36,  1246,    -1,
      36,   409,  1245,   370,    -1,  1321,    -1,  1245,     5,  1321,
      -1,   915,    -1,   244,    -1,   210,    -1,   143,  1249,    -1,
     120,    -1,   108,    -1,    98,    -1,    96,    -1,   100,    -1,
     157,  1423,    -1,   209,  1248,   438,  1417,   605,  1417,    -1,
     277,   908,   438,  1417,   605,  1417,    -1,    -1,  1423,    -1,
      -1,   824,    -1,   501,   824,    -1,    -1,    -1,   457,  1368,
    1252,   562,  1255,  1253,  1254,    -1,    -1,   128,   909,    -1,
     504,  1340,    -1,   409,  1259,   370,    13,   409,  1260,   370,
      -1,  1256,    -1,    20,    13,   409,  1260,   370,    -1,    20,
      13,  1260,    -1,  1258,    -1,  1256,     5,  1258,    -1,  1371,
      -1,  1257,    13,  1261,    -1,  1257,    -1,  1259,     5,  1257,
      -1,  1261,    -1,  1260,     5,  1261,    -1,  1405,    -1,   462,
      -1,  1410,    -1,   208,    -1,    -1,   227,  1264,  1368,  1267,
    1265,    -1,    -1,   458,  1266,   409,  1269,   370,    -1,  1404,
      -1,    -1,   409,  1268,   370,    -1,  1371,    -1,  1268,     5,
    1371,    -1,  1270,    -1,  1269,     5,  1270,    -1,  1410,    -1,
     462,    -1,    -1,    -1,   479,  1272,  1274,  1273,  1275,    -1,
    1279,   909,    -1,   909,    -1,    -1,    -1,   532,  1276,  1094,
      -1,    -1,    -1,   532,  1278,  1094,    -1,   480,    -1,   533,
      -1,   540,    -1,   353,    -1,   320,    -1,   374,    -1,   356,
     824,    -1,   329,   824,    -1,   216,  1368,   128,   909,    -1,
     216,  1368,  1337,    -1,   493,   598,  1283,    -1,  1284,    -1,
    1283,     5,  1284,    -1,  1285,  1286,    -1,    25,    -1,  1371,
      -1,    -1,   566,    -1,   517,    -1,   255,    -1,   288,    -1,
      -1,   305,    -1,   335,  1433,  1289,    -1,    -1,  1422,  1292,
    1293,    -1,  1322,    -1,  1326,    -1,  1288,    -1,  1424,    -1,
    1287,    -1,  1280,    -1,  1281,    -1,  1271,    -1,  1263,    -1,
    1262,    -1,  1394,    -1,  1251,    -1,   484,  1296,   604,  1368,
     605,  1301,  1295,    -1,    -1,   119,    -1,   147,    -1,  1297,
      -1,  1298,    -1,  1297,     5,  1298,    -1,   450,    -1,   428,
      -1,   417,    -1,   457,  1299,    -1,    -1,   409,  1300,   370,
      -1,  1371,    -1,  1300,     5,  1371,    -1,  1302,    -1,  1301,
       5,  1302,    -1,   441,    -1,  1369,    -1,   214,  1368,  1304,
     596,  1404,  1306,    -1,    -1,   409,  1305,   370,    -1,  1371,
      -1,  1305,     5,  1371,    -1,    -1,   118,    -1,   471,   409,
    1340,   370,    -1,   224,   409,  1310,   370,  1309,    -1,   275,
    1311,    -1,  1312,    -1,  1368,    -1,  1368,   409,  1312,   370,
      -1,  1371,    -1,  1312,     5,  1371,    -1,   455,   409,  1314,
     370,    -1,   237,   409,  1314,   370,    -1,  1371,    -1,  1314,
       5,  1371,    -1,  1313,    -1,  1308,    -1,  1307,    -1,   378,
    1373,    -1,   186,    -1,   915,  1360,  1318,  1319,    -1,    -1,
    1316,    -1,    -1,  1320,    -1,  1321,    -1,  1320,  1321,    -1,
     351,    -1,   136,    -1,  1309,    -1,   471,   409,  1340,   370,
      -1,    97,  1323,  1325,    -1,  1324,    -1,  1369,    -1,  1326,
      -1,  1325,  1326,    -1,  1303,    -1,  1294,    -1,   426,  1340,
      -1,   347,  1329,    -1,  1409,    -1,  1329,     5,  1409,    -1,
     504,  1340,    -1,   525,  1332,    -1,  1333,    -1,  1332,     5,
    1333,    -1,  1334,    -1,   494,  1334,    -1,   494,   409,  1335,
     370,    -1,  1368,    -1,  1368,  1372,    -1,  1333,    -1,  1335,
       5,  1333,    -1,  1331,  1337,  1338,  1339,    -1,    -1,  1330,
      -1,    -1,  1328,    -1,    -1,  1327,    -1,  1341,    -1,  1340,
       6,  1341,    -1,  1342,    -1,  1341,     7,  1342,    -1,  1343,
      -1,   581,  1343,    -1,  1358,    -1,   409,  1340,   370,    -1,
     421,  1405,    -1,   273,  1405,    -1,  1410,  1357,  1346,  1405,
      -1,  1405,  1357,  1410,    -1,    -1,  1347,    -1,  1348,    -1,
     564,    -1,   549,    -1,   565,    -1,   420,  1351,    -1,  1413,
      -1,  1413,    -1,  1410,   602,   409,  1353,   370,    -1,  1410,
     602,  1405,    -1,  1410,   407,   409,  1353,   370,    -1,  1410,
     407,  1405,    -1,  1354,    -1,  1353,     5,  1354,    -1,  1437,
      -1,  1373,    -1,    -1,   581,    -1,  1410,  1355,   365,    -1,
    1410,  1355,   228,    -1,  1410,  1357,  1410,    -1,  1410,  1357,
    1405,    -1,  1410,  1355,   367,  1410,     7,  1410,    -1,  1410,
    1355,   535,  1350,  1349,    -1,    13,    -1,    16,    -1,    11,
      -1,    12,    -1,   231,    -1,   350,    -1,     9,    -1,   535,
      -1,    15,    -1,    14,    -1,  1356,    -1,  1352,    -1,  1345,
      -1,  1344,    -1,    -1,   564,    -1,   338,    -1,   455,    -1,
    1361,    -1,  1362,    -1,  1364,    -1,   514,    -1,   514,   409,
    1365,   370,    -1,   389,   409,  1366,  1363,   370,    -1,   451,
      -1,   376,   409,  1366,  1363,   370,    -1,   491,   409,  1366,
    1363,   370,    -1,   516,    -1,   386,    -1,   358,    -1,   336,
    1380,   605,  1381,    -1,   336,    -1,   348,  1380,   605,  1381,
      -1,   348,    -1,   348,  1380,   409,    25,   370,   605,  1381,
      -1,   553,    -1,   511,    -1,   402,    -1,   402,   409,    25,
     370,    -1,   402,   409,    25,     5,    25,   370,    -1,    -1,
       5,  1367,    -1,   481,   409,  1366,   370,    -1,   544,    -1,
     278,    -1,   481,    -1,    42,    -1,    25,    -1,    25,    -1,
      25,    -1,    24,   599,   915,    -1,    24,    -1,   915,    -1,
     915,   568,   915,    -1,   915,    -1,    -1,   437,    25,   405,
      -1,   437,    25,     5,    25,   405,    -1,   915,  1370,    -1,
    1368,   919,   599,   915,  1370,    -1,  1368,   919,   599,    20,
      -1,   915,    -1,    24,    -1,   389,    -1,   923,    -1,    25,
      -1,    17,   923,    -1,    17,    25,    -1,    18,   923,    -1,
      18,    25,    -1,  1375,    -1,   374,  1377,    -1,   374,  1376,
      -1,    -1,  1380,   605,  1381,    -1,    -1,  1378,   605,  1379,
      -1,   560,    -1,   492,    -1,   569,    -1,   531,    -1,   432,
      -1,   449,    -1,   345,    -1,   345,   409,    25,   370,    -1,
     560,    -1,   492,    -1,   569,    -1,   531,    -1,   432,    -1,
     449,    -1,   345,    -1,   345,   409,    25,   370,    -1,   560,
      -1,   492,    -1,   569,    -1,   531,    -1,   432,    -1,   449,
      -1,   345,    -1,   560,    -1,   492,    -1,   569,    -1,   531,
      -1,   432,    -1,   449,    -1,   345,    -1,   915,    -1,    24,
      -1,  1422,   482,   909,    -1,    -1,  1422,   377,   909,   415,
     574,  1392,  1385,  1389,    -1,    -1,  1422,   377,   909,   415,
      79,   574,  1393,  1386,  1389,    -1,    -1,  1422,   377,   909,
     114,  1393,  1387,  1389,    -1,    -1,  1422,   377,   909,   115,
      79,   574,  1393,  1388,  1389,    -1,    -1,   267,    -1,   266,
    1390,    -1,  1391,    -1,  1390,     5,  1391,    -1,   915,    -1,
     915,   599,   915,    -1,    24,   599,   915,   599,   915,    -1,
    1393,    -1,  1263,    -1,  1129,    -1,  1395,    -1,  1395,  1389,
      -1,    -1,    -1,   450,  1406,  1407,  1396,  1403,  1397,  1336,
    1401,    -1,   450,  1406,  1407,  1336,  1401,    -1,  1400,    -1,
    1417,    -1,   450,   919,  1406,  1407,  1403,  1336,  1401,    -1,
      -1,   503,  1359,  1399,    -1,  1282,    -1,   310,  1402,  1223,
      -1,  1282,   310,  1402,  1223,    -1,   915,    -1,    -1,   532,
    1094,    -1,   450,   919,  1406,  1407,  1336,    -1,   409,   450,
     919,  1406,  1407,  1336,   370,    -1,    -1,   564,    -1,   338,
      -1,   455,    -1,  1408,    -1,  1407,     5,  1408,    -1,  1410,
      -1,  1410,  1457,    -1,  1410,   924,    -1,  1410,    -1,  1411,
      -1,  1437,    -1,  1410,    19,  1410,    -1,  1410,  1431,    -1,
    1410,    20,  1410,    -1,  1410,    17,  1410,    -1,  1410,    18,
    1410,    -1,  1373,    -1,   463,    -1,   406,    -1,   555,    -1,
      20,    -1,    43,    -1,   567,   409,  1359,  1410,   370,    -1,
     579,   409,  1359,  1410,   370,    -1,   580,   409,  1359,  1410,
     370,    -1,   588,   409,  1359,  1410,   370,    -1,   475,   409,
    1359,  1410,   370,    -1,   915,   409,  1412,   370,    -1,   516,
     919,   409,   919,  1412,   370,    -1,   409,  1410,   370,    -1,
     422,   409,  1432,   370,    -1,  1410,    -1,  1412,     5,  1410,
      -1,    -1,  1373,    -1,  1422,   325,  1421,  1416,  1399,    -1,
    1422,   314,  1421,  1416,   227,  1368,  1418,    -1,    -1,   300,
    1417,    -1,    24,    -1,  1073,    -1,    -1,   409,  1419,   370,
      -1,  1420,    -1,  1419,     5,  1420,    -1,   915,    -1,    24,
      -1,  1073,    -1,    -1,   246,  1423,   574,    -1,   916,    -1,
    1429,    -1,  1428,    -1,  1425,    -1,   295,  1426,   605,  1426,
      -1,   276,  1426,   599,  1427,   605,  1427,    -1,   915,    -1,
     915,    -1,   200,   767,    -1,   271,   767,  1430,    -1,   250,
      -1,   154,    -1,    71,    -1,    72,    -1,    73,    -1,    74,
      -1,    75,    -1,    76,    -1,   374,     5,  1380,   605,  1381,
      -1,  1371,     5,  1380,   605,  1381,    -1,   374,  1380,   605,
    1381,    -1,  1434,    -1,   591,  1435,    -1,  1435,    -1,  1102,
      -1,   915,    -1,  1435,   599,  1436,    -1,    24,   599,  1435,
     599,  1436,    -1,    20,    -1,  1102,    -1,   915,    -1,  1434,
      -1,  1434,   399,  1434,    -1,   105,  1439,    -1,   109,  1439,
      -1,   104,  1439,    -1,   144,    -1,   145,  1439,    -1,   102,
    1439,    -1,   127,  1439,    -1,   126,  1439,    -1,   101,  1439,
      -1,   334,    -1,   600,   605,  1440,    -1,   526,  1440,    -1,
     551,    -1,   512,  1441,    -1,   915,    -1,   568,   915,    -1,
     915,    -1,    -1,    -1,   505,  1443,   824,  1444,  1458,   304,
      -1,    -1,   638,  1448,    -1,    -1,   641,    -1,   160,    -1,
     256,   910,    -1,    48,   910,    -1,   286,    -1,   285,    -1,
     287,   912,  1445,  1446,    -1,   472,  1448,  1446,    -1,   907,
      -1,  1448,     5,   907,    -1,    81,    -1,   111,   910,    -1,
     824,   545,     5,   824,   371,    -1,   488,   824,    -1,   243,
     910,    -1,    80,  1453,     8,  1454,  1452,    -1,    -1,   525,
     824,    -1,   915,    -1,   915,    -1,   226,   910,    -1,   229,
     910,   605,   824,     5,   824,    -1,   229,   910,   598,   824,
       5,   824,    -1,    26,    -1,    -1,  1460,    -1,  1461,  1177,
      -1,  1459,    -1,  1460,  1459,    -1,    -1,  1462,  1463,    -1,
     648,    -1,   649,    -1,   650,    -1,   651,    -1,   668,    -1,
     690,    -1,   704,    -1,   705,    -1,   711,    -1,   712,    -1,
     731,    -1,   799,    -1,   800,    -1,   801,    -1,   802,    -1,
     813,    -1,   814,    -1,   815,    -1,   816,    -1,   867,    -1,
     871,    -1,   901,    -1,   925,    -1,   926,    -1,   929,    -1,
     930,    -1,   931,    -1,   932,    -1,   945,    -1,   953,    -1,
     976,    -1,   977,    -1,   979,    -1,   983,    -1,   998,    -1,
     999,    -1,  1003,    -1,  1004,    -1,  1005,    -1,  1006,    -1,
    1014,    -1,  1029,    -1,  1042,    -1,  1053,    -1,  1054,    -1,
    1055,    -1,  1066,    -1,  1105,    -1,  1108,    -1,  1110,    -1,
    1116,    -1,  1117,    -1,  1120,    -1,  1123,    -1,  1126,    -1,
    1128,    -1,  1130,    -1,  1132,    -1,  1139,    -1,  1144,    -1,
    1148,    -1,  1149,    -1,  1161,    -1,  1213,    -1,  1214,    -1,
    1216,    -1,  1228,    -1,  1229,    -1,  1247,    -1,  1250,    -1,
    1290,    -1,  1291,    -1,  1383,    -1,  1384,    -1,  1414,    -1,
    1415,    -1,  1438,    -1,  1442,    -1,  1447,    -1,  1449,    -1,
    1451,    -1,  1455,    -1,  1456,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const unsigned short yyrline[] =
{
       0,   881,   881,   884,   887,   893,   899,   906,   910,   910,
     916,   934,   935,   936,   937,   938,   952,   953,   954,   955,
     956,   961,   962,   973,   976,   979,   979,   983,   986,   987,
     993,   994,   995,   996,   997,   998,   999,  1000,  1001,  1002,
    1003,  1004,  1005,  1006,  1007,  1008,  1011,  1012,  1015,  1015,
    1023,  1024,  1027,  1033,  1035,  1046,  1048,  1050,  1052,  1056,
    1058,  1120,  1124,  1128,  1128,  1135,  1138,  1142,  1143,  1146,
    1152,  1146,  1165,  1170,  1174,  1165,  1186,  1190,  1186,  1199,
    1204,  1199,  1223,  1230,  1234,  1222,  1260,  1260,  1264,  1265,
    1266,  1271,  1274,  1279,  1283,  1291,  1294,  1294,  1300,  1304,
    1319,  1317,  1335,  1335,  1350,  1350,  1353,  1353,  1357,  1360,
    1360,  1360,  1367,  1368,  1367,  1375,  1375,  1386,  1386,  1405,
    1408,  1411,  1414,  1417,  1420,  1433,  1438,  1438,  1439,  1439,
    1442,  1447,  1447,  1451,  1461,  1475,  1479,  1474,  1489,  1495,
    1503,  1504,  1507,  1507,  1510,  1514,  1519,  1526,  1526,  1530,
    1530,  1537,  1537,  1542,  1542,  1547,  1547,  1552,  1552,  1565,
    1566,  1574,  1575,  1592,  1595,  1598,  1601,  1604,  1607,  1613,
    1624,  1629,  1642,  1646,  1661,  1662,  1666,  1666,  1670,  1670,
    1670,  1671,  1672,  1677,  1677,  1680,  1680,  1689,  1690,  1691,
    1694,  1698,  1699,  1699,  1716,  1716,  1716,  1716,  1720,  1727,
    1728,  1731,  1731,  1734,  1734,  1743,  1740,  1756,  1756,  1758,
    1758,  1760,  1762,  1764,  1766,  1769,  1773,  1773,  1774,  1774,
    1778,  1778,  1790,  1790,  1795,  1799,  1801,  1802,  1805,  1805,
    1805,  1809,  1810,  1811,  1812,  1819,  1820,  1821,  1822,  1825,
    1826,  1827,  1828,  1832,  1837,  1842,  1846,  1849,  1853,  1854,
    1855,  1856,  1857,  1858,  1859,  1860,  1863,  1864,  1865,  1897,
    1901,  1903,  1905,  1905,  1912,  1916,  1916,  1920,  1921,  1922,
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
    5696,  5697,  5702,  5703,  5709,  5709,  5709,  5714,  5714,  5714,
    5725,  5726,  5732,  5733,  5739,  5740,  5745,  5746,  5747,  5751,
    5754,  5760,  5763,  5771,  5772,  5778,  5785,  5788,  5797,  5800,
    5803,  5806,  5809,  5812,  5815,  5822,  5825,  5832,  5835,  5841,
    5844,  5851,  5854,  5861,  5862,  5867,  5871,  5874,  5880,  5883,
    5889,  5896,  5897,  5901,  5907,  5910,  5917,  5918,  5925,  5928,
    5933,  5944,  5945,  5946,  5947,  5948,  5949,  5950,  5951,  5952,
    5955,  5958,  5964,  5964,  5970,  5970,  5981,  5995,  5997,  5995,
    6004,  6008,  6014,  6022,  6032,  6035,  6045,  6067,  6070,  6076,
    6079,  6084,  6085,  6091,  6094,  6102,  6106,  6110,  6116,  6126,
    6126,  6131,  6131,  6134,  6138,  6139,  6145,  6146,  6151,  6152,
    6157,  6158,  6163,  6167,  6162,  6179,  6183,  6190,  6194,  6194,
    6207,  6211,  6211,  6226,  6228,  6230,  6232,  6234,  6236,  6238,
    6240,  6246,  6256,  6263,  6268,  6269,  6273,  6275,  6276,  6279,
    6280,  6281,  6284,  6289,  6296,  6297,  6303,  6316,  6316,  6321,
    6326,  6331,  6332,  6335,  6336,  6341,  6346,  6350,  6355,  6356,
    6360,  6367,  6371,  6372,  6377,  6379,  6383,  6384,  6388,  6389,
    6390,  6391,  6395,  6396,  6401,  6402,  6407,  6408,  6413,  6414,
    6419,  6423,  6424,  6429,  6430,  6434,  6435,  6440,  6447,  6452,
    6457,  6461,  6462,  6467,  6468,  6474,  6476,  6481,  6482,  6488,
    6491,  6494,  6501,  6503,  6515,  6520,  6521,  6524,  6526,  6533,
    6536,  6542,  6546,  6550,  6553,  6560,  6567,  6572,  6576,  6577,
    6583,  6586,  6597,  6604,  6610,  6611,  6616,  6623,  6629,  6630,
    6636,  6637,  6638,  6641,  6642,  6647,  6647,  6651,  6659,  6660,
    6663,  6664,  6667,  6668,  6673,  6676,  6682,  6685,  6691,  6694,
    6700,  6703,  6710,  6711,  6716,  6718,  6723,  6724,  6725,  6728,
    6732,  6733,  6741,  6746,  6750,  6755,  6759,  6762,  6766,  6772,
    6773,  6777,  6777,  6780,  6781,  6786,  6790,  6794,  6798,  6801,
    6805,  6812,  6813,  6814,  6815,  6816,  6817,  6818,  6819,  6820,
    6821,  6826,  6829,  6832,  6835,  6841,  6842,  6843,  6844,  6856,
    6857,  6858,  6862,  6863,  6868,  6870,  6871,  6872,  6874,  6875,
    6876,  6877,  6879,  6880,  6882,  6883,  6885,  6886,  6887,  6888,
    6890,  6894,  6895,  6901,  6903,  6904,  6905,  6906,  6911,  6915,
    6919,  6923,  6924,  6928,  6929,  6936,  6944,  6945,  6946,  6949,
    6954,  6959,  6969,  6973,  6977,  6978,  6979,  6980,  6982,  6984,
    6986,  6988,  6991,  6994,  6998,  6999,  7003,  7004,  7008,  7008,
    7008,  7008,  7008,  7008,  7009,  7012,  7017,  7017,  7017,  7017,
    7017,  7017,  7019,  7022,  7028,  7028,  7028,  7028,  7028,  7028,
    7028,  7029,  7029,  7029,  7029,  7029,  7029,  7029,  7031,  7032,
    7035,  7044,  7044,  7049,  7049,  7055,  7055,  7060,  7060,  7067,
    7068,  7069,  7072,  7072,  7075,  7076,  7077,  7082,  7085,  7091,
    7094,  7102,  7115,  7116,  7113,  7132,  7142,  7145,  7150,  7162,
    7165,  7169,  7172,  7173,  7179,  7182,  7183,  7192,  7201,  7206,
    7207,  7208,  7209,  7217,  7220,  7227,  7228,  7229,  7234,  7239,
    7242,  7246,  7248,  7250,  7252,  7254,  7256,  7257,  7258,  7259,
    7260,  7261,  7263,  7265,  7267,  7269,  7271,  7273,  7275,  7277,
    7278,  7282,  7282,  7284,  7285,  7288,  7296,  7301,  7301,  7305,
    7305,  7310,  7310,  7314,  7314,  7318,  7324,  7324,  7327,  7327,
    7333,  7340,  7341,  7342,  7346,  7347,  7350,  7351,  7355,  7361,
    7371,  7372,  7380,  7381,  7382,  7383,  7384,  7385,  7389,  7390,
    7391,  7474,  7486,  7486,  7490,  7491,  7492,  7493,  7497,  7498,
    7499,  7502,  7514,  7612,  7614,  7616,  7618,  7622,  7627,  7629,
    7631,  7633,  7637,  7640,  7645,  7650,  7654,  7663,  7664,  7668,
    7680,  7683,  7679,  7702,  7702,  7706,  7707,  7710,  7711,  7712,
    7713,  7714,  7715,  7716,  7721,  7722,  7726,  7729,  7734,  7738,
    7743,  7747,  7752,  7756,  7759,  7763,  7766,  7771,  7775,  7786,
    7792,  7792,  7793,  7794,  7801,  7810,  7810,  7812,  7813,  7814,
    7815,  7816,  7817,  7818,  7819,  7820,  7821,  7822,  7823,  7824,
    7825,  7826,  7827,  7828,  7829,  7830,  7831,  7832,  7833,  7834,
    7835,  7836,  7837,  7838,  7839,  7840,  7841,  7842,  7843,  7844,
    7845,  7846,  7847,  7848,  7849,  7850,  7851,  7852,  7853,  7854,
    7855,  7856,  7857,  7858,  7859,  7860,  7861,  7862,  7863,  7864,
    7865,  7866,  7867,  7868,  7869,  7870,  7871,  7872,  7873,  7874,
    7875,  7876,  7877,  7878,  7879,  7880,  7881,  7882,  7883,  7884,
    7885,  7886,  7887,  7888,  7889,  7890,  7891,  7892,  7893,  7894
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
  "drops_cmd", "drops_c", "create_cmd", "create_c_2_ss", "@152", "@153", 
  "@154", "@155", "create_c_1", "op_no_log", "idx_column_list", 
  "idx_column", "table_element_list_ss", "table_element_ss", 
  "upd_stats_cmd", "alter_cmd", "alter_clauses_ss", "alter_clause_ss", 
  "alter_add_clause_ss", "add_column_clause_ss", "add_column_clauses_ss", 
  "alter_drop_clause", "drop_column_list", "drop_column", 
  "alter_modify_clause", "modify_column_clauses_ss", 
  "modify_column_clause_ss", "alter_lock_mode", "alter_modify_next", 
  "alter_add_constraint_clause", "alter_drop_contraint_clause", 
  "column_constraints_ss", "constraint_name", "set_cmd", "op_conn_id", 
  "op_fgl_expr", "sleep_cmd", "update_statement_ss", "@156", "@157", 
  "where_upd_ss", "set_clause_list_ss", "upd_columns_ss", 
  "upd_column_name", "col_1_ss", "upd_col_list", "upd_val_list_ss", 
  "upd_val_ss", "rollback_statement", "insert_statement_ss", "@158", 
  "ins_2_ss", "@159", "op_insert_column_list", "insert_column_list", 
  "insert_value_list", "insert_value", "fetch_statement", "@160", "@161", 
  "fetch_part", "opt_into_fetch_part", "@162", 
  "opt_foreach_into_fetch_part", "@163", "fetch_place", 
  "delete_statement_position", "delete_statement_search_ss", 
  "order_by_clause", "sort_specification_list", "sort_specification", 
  "sort_spec", "op_asc_desc", "begin_statement", "commit_statement", 
  "op_exclusive", "set_database_cmd", "sql_cmd", "@164", "sql_commands", 
  "privilege_definition", "op_with_grant_option", "privileges", 
  "action_list", "action", "op_grant_column_list", "grant_column_list", 
  "grantee_list", "grantee", "view_definition_ss", "op_view_column_list", 
  "view_column_list", "op_with_check_option", 
  "check_constraint_definition_ss", "referential_constraint_definition", 
  "references_specification", "references_columns", 
  "referenced_table_and_columns", "references_column_list", 
  "unique_constraint_definition", "unique_column_list", 
  "table_constraint_definition_ss", "default_clause", 
  "ct_column_definiton_ss", "op_default_clause", 
  "op_column_constraint_list_ss", "column_constraint_list_ss", 
  "column_constraint_ss", "schema_ss", "schema_authorization_clause", 
  "schema_authorization_identifier", "schema_element_list_ss", 
  "schema_element_ss", "having_clause_ss", "group_by_clause", 
  "column_specification_list", "where_clause_ss", "from_clause", 
  "table_reference_list", "table_reference", "tname", "tname_list", 
  "table_expression_ss", "op_where_clause_ss", "op_group_by_clause", 
  "op_having_clause_ss", "search_condition_ss", "boolean_term_ss", 
  "boolean_factor_ss", "boolean_primary_ss", "exists_predicate_ss", 
  "quantified_predicate_ss", "quantifier", "all", "some", "op_escape", 
  "pattern", "escape_character", "in_predicate_ss", "in_value_list", 
  "in_value_specification", "op_not", "comparison_predicate_ss", 
  "comp_op", "predicate_ss", "op_all", "data_type", "char_string_type", 
  "exact_numeric_type", "op_scale", "approx_numeric_type", "length", 
  "precision", "scale", "table_name", "authorization_identifier", 
  "col_arr", "column_name", "correlation_name", "literal", 
  "curr_v_clause", "curr_clause", "cur_part", "cur_v_part", "s_curr_v", 
  "e_curr_v", "s_curr", "e_curr", "dbase_name", "flush_cmd", 
  "declare_cmd", "@165", "@166", "@167", "@168", "curs_forupdate", 
  "cur_update_list", "colident", "cursor_specification_all_ss", 
  "cursor_specification_sel_ss", "select_statement_full_ss", 
  "select_statement_ss", "@169", "@170", "in_select_statement_ss", 
  "select_statement2_ss", "select_statement21_ss", "sel_p2_ss", 
  "tmp_tabname", "opt_into_sel", "query_specification_ss", "subquery_ss", 
  "op_ad", "select_list_ss", "value_expression_pls", 
  "column_specification", "value_expression", "value_expression_complex", 
  "value_expr_list", "value_specification", "unload_cmd", "load_cmd", 
  "opt_delim", "char_or_var", "opt_col_list", "col_list", 
  "simple_column_name", "ufile", "opt_use", "conn_id", "misc_sql", 
  "rename_stmt", "rentabname", "rencolname", "unlock_stmt", "lock_stmt", 
  "share_or_exclusive", "units_qual", "extend_qual", "var_ident", "var2", 
  "var3", "aft_dot", "var_ident_ibind", "whenever_cmd", "when_do", 
  "label_goto", "function_name_when", "while_cmd", "@171", "@172", 
  "op_clr_fields", "op_to_defs", "clear_cmd", "fld_list", 
  "current_win_cmd", "window_type", "show_cmd", "op_mnfile", "menu_name", 
  "menu_handler", "hide_cmd", "move_cmd", "NAMED", "commands", 
  "all_commands", "command1", "commands_all", "@173", "commands_all1", 0
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
    1226,  1227,  1227,  1228,  1228,  1229,  1230,  1230,  1231,  1231,
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
    1320,  1321,  1321,  1321,  1321,  1322,  1323,  1324,  1325,  1325,
    1326,  1326,  1327,  1328,  1329,  1329,  1330,  1331,  1332,  1332,
    1333,  1333,  1333,  1334,  1334,  1335,  1335,  1336,  1337,  1337,
    1338,  1338,  1339,  1339,  1340,  1340,  1341,  1341,  1342,  1342,
    1343,  1343,  1344,  1344,  1345,  1345,  1346,  1346,  1346,  1347,
    1348,  1348,  1349,  1350,  1351,  1352,  1352,  1352,  1352,  1353,
    1353,  1354,  1354,  1355,  1355,  1356,  1356,  1356,  1356,  1356,
    1356,  1357,  1357,  1357,  1357,  1357,  1357,  1357,  1357,  1357,
    1357,  1358,  1358,  1358,  1358,  1359,  1359,  1359,  1359,  1360,
    1360,  1360,  1361,  1361,  1362,  1362,  1362,  1362,  1362,  1362,
    1362,  1362,  1362,  1362,  1362,  1362,  1362,  1362,  1362,  1362,
    1362,  1363,  1363,  1364,  1364,  1364,  1364,  1364,  1365,  1366,
    1367,  1368,  1368,  1368,  1368,  1369,  1370,  1370,  1370,  1371,
    1371,  1371,  1372,  1373,  1373,  1373,  1373,  1373,  1373,  1373,
    1373,  1373,  1374,  1375,  1376,  1376,  1377,  1377,  1378,  1378,
    1378,  1378,  1378,  1378,  1378,  1378,  1379,  1379,  1379,  1379,
    1379,  1379,  1379,  1379,  1380,  1380,  1380,  1380,  1380,  1380,
    1380,  1381,  1381,  1381,  1381,  1381,  1381,  1381,  1382,  1382,
    1383,  1385,  1384,  1386,  1384,  1387,  1384,  1388,  1384,  1389,
    1389,  1389,  1390,  1390,  1391,  1391,  1391,  1392,  1392,  1393,
    1393,  1394,  1396,  1397,  1395,  1398,  1399,  1399,  1400,  1401,
    1401,  1401,  1401,  1401,  1402,  1403,  1403,  1404,  1405,  1406,
    1406,  1406,  1406,  1407,  1407,  1408,  1408,  1408,  1409,  1410,
    1410,  1411,  1411,  1411,  1411,  1411,  1411,  1411,  1411,  1411,
    1411,  1411,  1411,  1411,  1411,  1411,  1411,  1411,  1411,  1411,
    1411,  1412,  1412,  1413,  1413,  1414,  1415,  1416,  1416,  1417,
    1417,  1418,  1418,  1419,  1419,  1420,  1421,  1421,  1422,  1422,
    1423,  1424,  1424,  1424,  1425,  1425,  1426,  1427,  1428,  1429,
    1430,  1430,  1431,  1431,  1431,  1431,  1431,  1431,  1432,  1432,
    1432,  1433,  1434,  1434,  1435,  1435,  1435,  1435,  1436,  1436,
    1436,  1437,  1437,  1438,  1438,  1438,  1438,  1438,  1438,  1438,
    1438,  1438,  1439,  1439,  1439,  1439,  1439,  1440,  1440,  1441,
    1443,  1444,  1442,  1445,  1445,  1446,  1446,  1447,  1447,  1447,
    1447,  1447,  1447,  1447,  1448,  1448,  1449,  1449,  1450,  1450,
    1451,  1451,  1452,  1452,  1453,  1454,  1455,  1456,  1456,  1457,
    1458,  1458,  1459,  1460,  1460,  1462,  1461,  1463,  1463,  1463,
    1463,  1463,  1463,  1463,  1463,  1463,  1463,  1463,  1463,  1463,
    1463,  1463,  1463,  1463,  1463,  1463,  1463,  1463,  1463,  1463,
    1463,  1463,  1463,  1463,  1463,  1463,  1463,  1463,  1463,  1463,
    1463,  1463,  1463,  1463,  1463,  1463,  1463,  1463,  1463,  1463,
    1463,  1463,  1463,  1463,  1463,  1463,  1463,  1463,  1463,  1463,
    1463,  1463,  1463,  1463,  1463,  1463,  1463,  1463,  1463,  1463,
    1463,  1463,  1463,  1463,  1463,  1463,  1463,  1463,  1463,  1463,
    1463,  1463,  1463,  1463,  1463,  1463,  1463,  1463,  1463,  1463
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
       3,     1,     1,     2,     1,     3,     1,     3,     1,     1,
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
       1,     1,     2,     1,     4,     0,     1,     0,     1,     1,
       2,     1,     1,     1,     4,     3,     1,     1,     1,     2,
       1,     1,     2,     2,     1,     3,     2,     2,     1,     3,
       1,     2,     4,     1,     2,     1,     3,     4,     0,     1,
       0,     1,     0,     1,     1,     3,     1,     3,     1,     2,
       1,     3,     2,     2,     4,     3,     0,     1,     1,     1,
       1,     1,     2,     1,     1,     5,     3,     5,     3,     1,
       3,     1,     1,     0,     1,     3,     3,     3,     3,     6,
       5,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     0,     1,     1,     1,     1,
       1,     1,     1,     4,     5,     1,     5,     5,     1,     1,
       1,     4,     1,     4,     1,     7,     1,     1,     1,     4,
       6,     0,     2,     4,     1,     1,     1,     1,     1,     1,
       1,     3,     1,     1,     3,     1,     0,     3,     5,     2,
       5,     4,     1,     1,     1,     1,     1,     2,     2,     2,
       2,     1,     2,     2,     0,     3,     0,     3,     1,     1,
       1,     1,     1,     1,     1,     4,     1,     1,     1,     1,
       1,     1,     1,     4,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       3,     0,     8,     0,     9,     0,     7,     0,     9,     0,
       1,     2,     1,     3,     1,     3,     5,     1,     1,     1,
       1,     2,     0,     0,     8,     5,     1,     1,     7,     0,
       3,     1,     3,     4,     1,     0,     2,     5,     7,     0,
       1,     1,     1,     1,     3,     1,     2,     2,     1,     1,
       1,     3,     2,     3,     3,     3,     1,     1,     1,     1,
       1,     1,     5,     5,     5,     5,     5,     4,     6,     3,
       4,     1,     3,     0,     1,     5,     7,     0,     2,     1,
       1,     0,     3,     1,     3,     1,     1,     1,     0,     3,
       1,     1,     1,     1,     4,     6,     1,     1,     2,     3,
       1,     1,     1,     1,     1,     1,     1,     1,     5,     5,
       4,     1,     2,     1,     1,     1,     3,     5,     1,     1,
       1,     1,     3,     2,     2,     2,     1,     2,     2,     2,
       2,     2,     1,     3,     2,     1,     2,     1,     2,     1,
       0,     0,     6,     0,     2,     0,     1,     1,     2,     2,
       1,     1,     4,     3,     1,     3,     1,     2,     5,     2,
       2,     5,     0,     2,     1,     1,     2,     6,     6,     1,
       0,     1,     2,     1,     2,     0,     2,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const unsigned short yydefact[] =
{
     810,     0,   610,     0,     0,     0,     0,     0,     0,     0,
    1746,     0,   610,   610,   861,   178,   834,   839,   176,   181,
     814,     0,   808,   811,   812,   815,   817,   860,   816,   855,
     856,   858,   182,   133,   130,     0,   126,   128,   127,   131,
     705,     0,  1752,   610,   610,  1755,     0,  1751,  1748,  1745,
    1743,  1744,  1750,  1749,  1747,   293,  1619,  1618,   854,   174,
     185,   177,   182,     1,   818,   813,   859,   857,   835,   125,
     129,   132,  1789,   611,  1759,  1756,   610,  1757,  1754,   610,
       0,   583,   610,     0,   175,   864,   928,   584,   862,   618,
     921,   610,   922,   929,   927,   185,   179,   198,   610,   183,
     199,   228,   841,  1207,   610,   610,   840,   134,  1195,   848,
     610,   610,   831,   833,   830,   832,   809,   819,   820,   842,
     823,   824,   825,   828,   826,   827,   829,   604,  1758,  1753,
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
       0,     0,   238,   226,  1208,     0,     0,  1196,  1795,   534,
     898,   843,     0,   207,   208,     0,   274,   276,   271,   272,
     268,   270,   267,   269,   266,     0,   276,   287,   288,   284,
     286,   283,   285,   278,     0,     0,     0,   327,     0,   330,
     332,   215,     0,   214,     0,     0,   185,    11,    12,   940,
     610,   926,   620,   197,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   185,   227,   230,   610,   704,   865,   610,
       0,  1793,  1795,  1131,  1708,   836,     0,   610,     0,     0,
     263,     0,     0,   273,   290,   264,   289,     0,   282,     0,
     305,     0,   299,   610,   324,   610,   329,   319,     0,     0,
     308,   298,   261,   318,     0,     0,     0,     0,     0,   243,
       0,   235,   217,   203,     0,   246,   234,   259,   957,     0,
     952,   953,   610,     0,   850,  1794,  1792,   610,   610,   610,
     610,   610,   610,   610,  1776,   610,  1297,  1296,   610,  1298,
     610,   375,  1295,  1237,   610,     5,  1294,   376,   373,   610,
     378,   172,   463,  1109,     0,     0,  1304,   122,   372,   371,
    1229,   366,   610,  1254,  1767,   610,   377,   344,   610,     3,
       2,   610,   374,  1234,   610,   610,   367,   364,   379,   610,
     610,   610,   610,   610,  1292,   370,   610,   610,   610,   610,
     610,   610,   610,   610,  1291,   610,   610,   610,   173,  1231,
     363,   362,   610,   610,  1771,  1770,   610,   610,   610,   135,
    1230,   369,   368,   610,   610,   365,   916,   463,   610,   529,
       0,   610,   610,   463,   610,   610,   610,   463,   797,  1205,
     610,   610,  1113,   610,  1760,   610,   102,   610,   610,   869,
     610,   610,   610,   610,   798,   610,   610,   610,     0,   610,
     610,   610,   610,   610,   610,   610,   676,   610,   610,  1797,
    1798,  1799,  1800,  1801,  1802,  1803,  1804,  1805,  1806,  1807,
    1808,  1809,  1810,  1811,  1812,  1813,  1814,  1815,  1816,  1817,
    1818,  1819,  1820,  1821,  1822,  1823,  1824,  1825,  1826,  1827,
    1828,  1829,  1830,  1831,  1832,  1833,  1834,  1835,  1836,  1837,
    1838,  1839,  1840,  1841,  1842,  1843,   907,  1844,  1845,  1846,
    1847,  1848,  1849,  1850,  1851,  1852,  1853,  1854,  1855,  1856,
    1857,  1858,  1859,  1100,  1102,  1097,  1099,  1098,  1101,  1860,
    1861,  1228,  1862,  1233,  1232,  1863,  1864,  1865,  1866,  1867,
    1868,  1869,  1870,  1871,  1872,  1377,  1873,  1874,  1875,  1876,
    1877,  1878,  1879,  1796,   837,   538,   838,   610,   902,     0,
     900,     0,   326,   209,   210,     0,   275,   280,     0,     0,
       0,     0,   328,   331,     0,   213,     0,   938,   219,     0,
     185,     0,     0,     0,     0,   610,  1209,   610,     0,  1197,
       0,  1241,     0,   822,  1769,   598,   121,     0,   610,  1735,
    1734,  1011,  1731,  1733,  1784,     0,  1248,     0,  1244,  1253,
       7,     0,     6,   610,  1777,  1073,  1074,   610,  1165,  1164,
    1112,  1163,  1111,   610,   610,   422,   424,     0,  1202,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   610,
    1586,     0,     0,     0,   416,   610,   610,     0,     0,   415,
     610,     0,   432,     0,   499,     0,     0,     0,     0,     0,
     610,     0,   411,  1305,     0,   382,   381,   388,   428,   425,
     383,   497,   489,   384,   386,   496,   387,   928,   423,   426,
     431,  1293,   498,  1710,  1299,   123,   610,  1077,   120,   610,
     804,    23,   600,   380,     0,   803,  1070,   805,     0,  1303,
     891,   890,   893,   889,   892,  1786,     0,   887,     0,   599,
     984,   888,  1780,     0,  1768,   119,   981,   706,   979,     0,
     596,  1763,   752,   751,     0,   753,   588,   749,     0,   610,
     994,   601,  1374,   610,   610,  1046,  1044,   610,  1038,  1040,
    1039,  1037,  1036,   610,   610,   610,  1035,   610,   779,   610,
     610,     0,     0,     0,     0,   610,   610,     0,     0,     0,
    1025,  1016,  1017,     0,  1058,   409,    23,   851,   401,  1774,
       0,  1765,   124,   597,   610,  1043,  1042,  1206,  1204,  1130,
       0,  1699,  1700,  1131,  1219,  1131,  1114,  1115,  1118,  1133,
    1306,   610,     0,     0,     0,     0,     0,   610,     0,   610,
       0,    61,     0,   928,     0,    67,     0,   100,   576,   664,
     610,  1103,  1001,  1107,     0,   610,  1059,  1223,     0,  1110,
     668,   665,   666,     0,   670,   671,     0,   673,   674,   610,
     669,   961,   963,   610,   610,   962,   754,   959,   715,   955,
     920,     0,   610,   610,     0,   680,   681,     0,     0,   918,
     914,   915,   911,   912,   913,   906,   910,   909,   610,   610,
     610,   610,   610,     0,   542,   544,   536,   539,   540,   904,
    1795,   899,   901,   844,     0,   277,   279,   306,   300,     0,
       0,   309,     0,   224,     0,   222,   244,   236,   228,   247,
     958,   174,   954,   866,   174,     0,   610,     0,  1281,  1282,
     610,   610,   610,  1255,  1256,  1258,  1259,  1260,  1264,  1263,
    1261,  1262,     0,   611,   606,   610,  1732,   610,   610,  1013,
     610,   610,  1247,  1246,   610,  1240,     0,  1562,  1563,     0,
    1075,     0,    23,  1160,  1162,  1161,   390,   389,   610,   610,
    1137,   467,   610,   610,   610,   610,     0,   610,     0,     0,
     610,   430,  1594,  1592,  1593,  1589,  1591,  1588,  1590,  1582,
       0,   610,     0,   610,     0,   429,     0,   610,   503,   502,
       0,     0,   473,   470,   479,   610,   476,   610,   610,   414,
     610,   610,   610,   610,   610,   610,   610,   610,   610,   610,
     610,   610,   610,   610,   610,   610,   610,   163,   164,   165,
     166,   167,   168,   504,   505,   506,   443,   610,   610,   442,
     448,     0,   610,   394,   610,     0,   395,   385,   391,   393,
     396,   397,   398,   399,   400,   392,   421,   420,   464,   610,
     971,     0,     0,   349,    24,   343,   610,   610,  1067,   610,
     610,   610,   610,   610,   610,     0,   988,  1709,   610,   610,
     185,     0,   610,   610,  1765,   610,   610,   610,   610,   610,
     136,     0,   610,   998,   990,   991,   996,  1375,  1376,   917,
     333,   407,   610,   530,   581,   580,   578,  1019,   582,  1024,
    1020,  1023,   772,     0,  1021,  1022,   773,  1029,  1033,  1026,
    1027,  1031,  1032,  1030,  1028,  1034,     0,   806,   610,   610,
       0,   404,   405,   402,   403,   610,     0,     0,   762,   761,
     760,  1766,  1773,    23,  1126,  1127,  1128,  1129,  1123,  1121,
    1220,  1135,  1120,  1116,   610,     0,  1117,  1761,    79,   610,
       0,   610,   610,    96,     0,    97,   610,     0,   610,    72,
     610,   610,   109,   104,     0,   896,     0,   895,     0,   463,
    1105,   610,   946,   947,   970,   942,   943,   799,   968,  1061,
    1225,   610,  1227,  1226,   696,   610,   610,   610,   685,   715,
     715,   713,   610,   610,   716,     0,    25,   684,   687,     0,
     694,   690,   919,   908,  1706,  1707,  1697,  1697,     0,     0,
    1620,   610,   185,  1328,   610,   610,  1329,  1372,   185,   610,
    1373,   610,  1659,   610,  1342,     0,  1390,  1388,  1387,  1386,
    1384,  1385,  1383,  1381,  1378,  1451,  1450,  1379,  1380,  1389,
    1629,  1382,  1713,  1712,  1711,  1795,  1795,   555,   546,   537,
       0,   541,  1795,   903,   174,     0,   320,   212,     0,   185,
     221,   204,  1210,   174,  1198,  1442,   610,  1441,     0,     0,
    1443,  1284,     0,  1290,  1286,  1283,     0,     0,   610,     0,
       0,     0,  1280,  1276,  1431,  1430,  1429,  1252,  1251,   610,
    1275,  1271,   610,  1267,  1265,     0,   610,   605,     0,     0,
    1012,   610,     0,  1010,  1738,  1740,  1739,  1736,  1785,  1782,
    1245,   610,   610,   610,  1238,   463,   341,     0,  1203,    91,
       0,     0,     0,     0,  1659,     0,     0,     0,     0,     0,
     521,   507,   512,     0,   508,   511,   510,     0,     0,     0,
       0,     0,     0,   417,     0,   170,     0,   433,   610,   610,
     610,     0,   610,     0,     0,     0,   435,   434,   449,   444,
     455,   458,   459,   456,   462,   461,   460,   450,   451,   453,
     452,   454,   445,   447,   463,   457,   446,   463,    91,   427,
     610,  1235,  1003,  1071,  1072,  1069,  1068,     0,   894,     0,
       0,   585,     0,     0,   610,   982,   980,     0,   708,   709,
       0,     0,  1764,  1772,     0,     0,   592,     0,   594,   750,
       0,   140,   610,   992,   999,     0,   610,  1007,   610,   336,
     610,   610,   610,   610,    23,  1045,  1350,     0,     0,   796,
     784,   794,   795,   782,   783,   790,   786,   789,   785,   793,
     788,   791,   792,   781,   787,   780,   779,  1018,   807,   410,
     610,  1050,   610,  1775,   763,   764,   360,   610,  1131,   610,
    1134,  1119,  1795,    91,     0,     0,     0,     0,   610,     0,
     610,    62,    91,     0,   115,   110,     0,   105,   610,   112,
     106,   880,   872,   878,     0,  1104,   610,  1106,  1108,     0,
     610,   950,     0,   610,     0,   610,  1060,  1224,  1795,   667,
     672,   675,   688,   686,   602,     0,   610,   610,   731,   769,
     729,   725,   723,   767,     0,     0,   755,     0,   717,   727,
     960,   956,   610,     0,     0,     0,   693,   610,     0,   610,
     610,     0,     0,   610,  1565,     0,  1446,  1447,  1718,  1411,
    1468,   610,     0,  1716,     0,     0,  1661,  1662,  1660,   610,
    1307,   610,  1394,  1400,  1399,  1398,  1402,     0,  1395,  1396,
     610,  1630,  1641,   543,   545,   610,     0,   558,   550,   552,
       0,   547,   548,   610,   610,   566,   568,   610,     0,   564,
     905,   845,   211,     0,     0,   223,  1166,   867,  1144,  1419,
    1421,     0,  1288,   610,     0,   610,   610,     0,  1278,   610,
     610,  1557,  1555,  1542,  1544,  1540,     0,  1539,     0,  1548,
    1535,  1556,     0,  1547,  1532,  1538,  1554,  1546,  1435,  1529,
    1530,  1531,     0,  1273,  1269,     0,   610,  1257,   609,     0,
     608,   610,   978,     0,   610,   610,  1781,     4,     8,    10,
    1561,  1564,   610,   463,   495,   468,    92,    93,    95,   492,
     491,   494,   490,   610,   419,   501,   486,   486,     0,   509,
       0,   513,     0,   281,  1202,     0,  1602,  1600,  1601,  1597,
    1599,  1596,  1598,  1587,   493,  1202,   500,   418,   265,     0,
    1202,   474,   471,   480,  1202,   477,  1202,  1202,  1202,   610,
       0,   610,     0,   465,     0,   610,   610,  1000,   610,   610,
     610,   610,   610,     0,   610,   185,   707,   610,   589,   591,
     610,   610,   157,   155,   610,   610,   137,     0,   147,   153,
     715,   142,   144,   610,   997,  1008,  1009,     0,   408,   335,
     340,   587,   334,   610,   337,   342,  1351,   531,   579,   577,
     779,   774,   775,  1049,  1051,   610,   406,   361,  1124,  1122,
    1221,  1222,     0,    80,    65,  1215,     0,     0,     0,    98,
       0,     0,    73,    69,  1795,  1795,   108,   103,   117,   113,
       0,   107,   770,   881,   602,  1795,   871,   870,   879,  1002,
     610,     0,   610,   969,   463,     0,     0,  1680,  1573,  1576,
    1681,  1584,  1574,  1678,   610,     0,  1066,  1677,     0,   610,
    1679,     0,     0,     0,     0,  1735,  1575,  1062,  1063,  1676,
    1581,  1065,  1669,  1741,  1670,   698,   691,   689,     0,    23,
     610,   745,   719,   747,   721,  1795,  1795,  1795,  1795,   779,
     740,   739,   735,   737,   744,   743,   733,   741,   714,   718,
    1795,   602,    45,    43,    40,    34,    38,    42,    37,    30,
      39,    33,    36,    31,    41,    32,    44,    35,     0,    28,
       0,   695,  1698,   610,   610,  1695,  1646,  1647,  1639,  1625,
    1640,     0,     0,   610,  1041,  1445,  1448,   610,     0,   610,
     610,  1469,  1362,  1334,  1721,  1720,  1719,   610,   610,  1642,
    1663,  1665,     0,  1357,   610,  1356,   610,  1358,  1353,  1354,
    1355,  1346,  1343,   610,   610,  1401,   610,     0,     0,  1634,
    1631,  1632,   557,   562,   610,   610,  1795,  1795,   535,   549,
     572,   560,   574,  1795,  1795,   570,   554,   565,   836,   321,
     205,     0,  1192,  1211,   836,     0,  1199,  1192,   610,     0,
    1285,     0,   610,     0,   610,     0,  1474,  1476,  1478,  1524,
    1523,  1522,  1521,  1480,     0,  1503,  1287,  1566,     0,  1420,
     610,  1423,     0,  1427,   610,  1277,     0,     0,  1610,  1608,
    1609,  1605,  1607,  1604,  1606,     0,     0,     0,     0,     0,
       0,     0,     0,  1433,     0,  1436,  1437,   610,  1272,   610,
    1266,  1268,   607,  1737,   610,     0,  1783,   610,     0,  1249,
     610,     0,     0,   610,     0,   483,     0,   484,     0,   523,
       0,   520,   517,   488,   482,  1140,  1595,     0,  1139,     0,
     169,  1138,     0,     0,     0,  1141,     0,  1143,  1142,  1136,
     436,     0,   439,     0,   438,     0,     0,     0,   610,     0,
    1300,  1788,  1787,   586,   610,     0,    46,   610,   712,   711,
     710,  1301,   610,     0,   715,  1795,  1795,   149,   612,   159,
     151,   161,   141,   148,  1795,   610,     0,   610,     0,   610,
       0,   610,  1795,     0,   777,   602,   610,  1762,     0,    91,
     610,    63,   610,   610,   610,    76,     0,    91,   116,   111,
    1795,  1795,   101,   779,   882,   876,   884,   883,   873,   527,
     931,   948,   949,   944,   610,  1578,  1577,  1580,  1579,  1583,
       0,     0,   610,  1525,     0,  1525,  1525,  1525,  1525,   610,
     610,   610,   610,   610,   610,  1722,  1723,  1724,  1725,  1726,
    1727,  1672,   610,   701,   699,     0,   678,   692,   603,   756,
       0,   610,  1795,   610,  1795,   732,   730,   726,   724,   768,
       0,  1795,     0,  1795,   728,    23,     0,    26,     0,  1701,
    1659,  1629,   610,   610,  1638,  1621,  1637,  1449,     0,  1413,
       0,  1361,  1456,   610,     0,  1717,     0,  1714,   610,  1655,
     642,   627,   640,   646,   661,   626,   638,   621,   654,   657,
     660,   624,   655,   633,   637,   648,   659,   656,   658,   649,
     631,   629,   653,   635,   634,   622,   623,   625,   628,   639,
     651,   630,   663,   641,   645,   647,   662,   636,   650,   652,
     632,   643,   644,  1667,  1666,   610,  1360,  1359,  1347,  1345,
       0,  1404,     0,  1397,   610,   610,   610,   610,   559,   556,
     551,   553,   610,  1795,  1795,   567,   569,  1795,  1795,     0,
       0,  1190,  1191,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1189,     0,     0,  1177,  1178,  1179,
    1176,  1181,  1182,  1183,  1180,  1167,  1158,   610,     0,  1214,
       0,  1795,     0,  1153,     0,     0,     0,     0,     0,     0,
     610,  1145,  1146,     0,  1078,     0,  1289,     0,  1483,   610,
       0,  1503,  1482,  1479,   610,  1444,   610,  1517,  1513,  1514,
    1511,  1520,  1519,  1512,  1515,  1516,  1518,   610,     0,  1504,
       0,     0,   610,     0,  1569,     0,   610,     0,   610,  1426,
    1279,  1425,  1417,     0,     0,     0,  1559,  1551,  1551,     0,
       0,  1551,  1558,     0,  1573,  1432,  1434,  1438,  1439,  1274,
    1270,  1015,   610,     9,   610,  1242,   853,  1076,   469,    94,
     610,  1468,  1649,     0,   486,   514,     0,     0,   274,   475,
     472,   481,   478,   610,   441,   440,   466,   347,  1236,     0,
     610,  1779,     0,     0,   983,    47,     0,   593,   595,   590,
     765,   158,   156,   610,  1795,   610,   610,   610,  1795,   154,
     143,   610,   146,   145,   610,   989,   993,   339,   610,   966,
    1352,   964,     0,   779,   776,    23,  1125,    86,  1216,    68,
     610,     0,    99,    66,    91,    74,     0,   118,   114,   771,
    1795,   886,   602,   885,   610,   524,   610,   801,   802,   800,
       0,  1689,     0,     0,     0,  1527,  1528,  1526,   610,   610,
     610,   610,   610,   610,  1691,     0,  1064,  1674,  1675,  1671,
    1673,  1742,   610,  1795,   697,   682,   679,     0,   746,   720,
     748,   722,   738,   736,   742,   734,   757,    29,    27,   610,
    1696,   610,  1626,  1627,  1623,  1629,   610,  1412,   610,  1415,
       0,  1336,  1331,  1330,  1333,   610,  1664,   610,  1643,     0,
     610,  1308,  1314,     0,  1317,  1319,  1348,  1344,   610,  1403,
     610,     0,  1635,  1633,   563,   561,   573,   575,   571,     0,
       0,   228,  1184,  1185,  1186,  1188,  1171,  1169,  1168,  1172,
    1173,  1170,  1187,  1174,  1175,  1159,   975,  1194,   972,   610,
       0,  1212,     0,  1157,  1156,  1151,  1149,  1148,  1152,  1150,
    1154,  1155,  1147,  1200,  1422,  1659,  1481,  1475,  1477,  1485,
     610,  1498,   610,  1496,  1506,  1505,   610,  1693,   610,  1490,
    1489,  1491,     0,  1487,  1488,  1508,  1507,     0,  1418,  1424,
     610,  1428,  1617,  1615,  1616,  1612,  1614,  1611,  1613,  1541,
       0,  1543,     0,     0,     0,     0,  1549,  1553,     0,  1533,
    1440,  1014,  1250,  1243,  1239,   610,  1457,  1458,  1460,  1463,
    1470,   610,     0,  1525,  1651,  1645,   487,   485,     0,   519,
     518,  1603,   171,   437,   610,    23,     0,   610,  1006,   610,
      48,   986,     0,    23,   160,   150,     0,   614,   616,   162,
     152,   765,     0,   338,   610,   610,   532,   778,  1047,   610,
      81,     0,    64,     0,    77,    86,    70,   877,   874,   528,
    1795,     0,  1585,     0,     0,     0,  1690,     0,   610,     0,
       0,     0,     0,   610,  1687,     0,   700,   677,   683,   602,
    1705,     0,  1703,  1655,  1629,  1629,  1622,  1414,  1659,  1416,
    1410,   610,  1335,     0,  1715,  1656,     0,   610,  1321,     0,
    1310,   610,   610,   610,  1405,  1408,  1392,  1406,  1409,   610,
     847,   846,   322,   206,   977,   976,   974,   610,  1193,  1079,
    1083,  1085,   610,  1089,   610,  1087,  1091,  1080,  1081,     0,
     868,     0,   610,     0,  1499,  1502,  1501,     0,     0,     0,
    1694,  1493,  1484,     0,  1567,  1571,  1566,     0,  1560,  1552,
    1536,  1534,     0,  1537,   610,  1461,   610,  1572,  1464,   610,
    1471,  1472,  1654,  1242,   610,   610,   610,   516,   515,   348,
     345,   610,  1004,     0,     0,     0,   985,   766,   138,   613,
      23,   995,   967,   965,  1052,    87,  1217,    82,     0,    75,
      86,  1795,   525,   945,     0,     0,     0,  1686,     0,  1682,
    1683,  1684,  1685,  1692,   702,   758,   610,  1702,     0,  1628,
    1624,   610,  1337,   610,  1649,   610,  1326,  1316,  1323,  1325,
    1327,   610,     0,   610,   610,  1309,  1318,  1320,  1349,   610,
    1393,  1391,  1636,   973,  1795,  1795,  1093,  1795,  1095,  1795,
    1795,  1082,  1213,  1201,     0,   610,  1497,  1495,   610,  1693,
    1510,     0,  1570,     0,  1550,  1465,     0,  1459,  1453,  1454,
    1668,   610,  1473,  1467,  1652,  1367,  1363,  1364,  1369,  1368,
    1650,  1242,   350,  1005,  1778,   610,   610,   610,   610,   610,
     610,    53,     0,    52,     0,    50,   610,   610,   139,  1056,
    1048,     0,  1054,    86,    91,    86,    71,   875,     0,     0,
    1730,     0,  1688,  1795,    23,  1704,  1649,     0,  1341,     0,
    1338,  1340,  1644,     0,  1327,   610,  1322,     0,  1311,  1312,
    1407,  1084,  1086,  1795,  1090,  1795,  1088,  1092,     0,  1500,
    1509,  1492,  1494,  1568,  1545,   610,  1462,   610,  1452,   610,
    1371,  1370,  1366,  1653,   356,   354,   346,     0,   352,   358,
      55,    60,    57,    59,    56,    58,    54,     0,    49,     0,
     615,   617,  1795,  1053,  1055,  1218,    83,    78,   526,  1728,
    1729,   698,   759,  1648,  1657,   610,  1332,  1315,  1324,   610,
    1094,  1096,  1658,  1466,  1455,  1365,  1795,  1795,   351,   353,
    1795,    51,   610,  1057,     0,   703,  1339,     0,   357,   355,
     359,     0,    84,  1313,   987,    88,    90,   610,    85,    89
};

/* YYDEFGOTO[NTERM-NUM]. */
static const short yydefgoto[] =
{
      -1,   549,   550,   551,   552,   701,  1707,  1708,   188,   264,
     189,  1123,  1124,  1593,  1928,  2953,  2454,  2455,  2844,  2954,
    2955,   553,   891,  2490,  2157,  2860,  1542,  2156,  2725,  2494,
    2858,  1533,  2148,  2964,  3064,  3075,  2720,  3078,  1715,  1716,
    1717,  1224,  1828,   554,  1234,   896,  1232,  1549,  1837,  1546,
    1835,  1840,  2161,  1233,  1834,  1550,  2160,   555,    16,    35,
      36,    37,    38,    39,   113,   558,   819,  1481,  1150,  1786,
    1790,  1791,  1787,  1788,  2464,  2468,  2134,  2126,  2125,  2127,
    2130,  1106,  1058,  1749,   559,    83,    84,    18,    60,   142,
      96,   255,    98,    99,   200,   278,   100,   101,   242,   228,
     673,  2320,   305,   655,  1653,   332,   333,   229,   287,   280,
     282,   974,   975,   146,   355,   147,   148,   293,   230,   231,
    1467,   393,   243,   246,   244,   245,   314,   370,   371,   373,
     378,   658,   247,   248,   323,   375,   196,    19,    80,   177,
     178,   179,   664,  2319,   180,   251,   240,   326,   327,   328,
     329,  1494,   560,   561,   562,   563,   776,  2942,  2695,  1125,
    3016,  3017,  3018,  3057,  3056,  3060,   564,   565,   566,   567,
     752,  1107,   857,  1192,  1193,  1160,   854,  1161,   754,   755,
     756,   757,   758,   759,   760,  1061,  1108,  2101,  1109,  1110,
    1111,  1112,  1113,  1114,  1115,   707,   761,  1448,  2105,  1389,
    2072,   762,  1419,  2093,  1418,  2092,  1422,  2096,  1420,  2094,
    2075,  2084,   763,   764,   765,   766,  1403,  1404,  1405,  1406,
     568,  2730,  2968,  2505,   569,   827,  1496,  2142,   114,   237,
     365,  1318,   956,   957,   958,  1315,  1316,  1640,  1641,  1642,
    1986,  1987,  1319,  1320,  1636,  1990,  1982,  1648,  1649,  1993,
    1994,  2317,  2313,  2314,   570,  1167,    85,  1462,  1463,  1802,
     859,   809,   862,   684,   798,   781,   820,  1889,    86,   685,
    1003,  1699,    41,   127,  2129,    87,   768,  2293,   571,   572,
     911,   912,   573,   574,   575,   576,   919,  2535,   940,  2747,
     941,  1572,   942,  1886,   943,  2206,   944,  1596,   577,  1568,
    2205,  2533,  2532,  2973,   115,    20,   578,  1141,  1468,  1469,
    1586,  1265,  1587,  1588,  2212,  2214,  1898,  1897,  1910,  1896,
    1895,  2223,  2221,  1902,  1903,  1906,  1907,  1892,  1894,   579,
     580,   817,   581,  1261,   926,  2974,   582,  1200,  2703,  1589,
    1899,  1843,  2163,   850,  1177,  1516,  1811,  2143,  1812,  1173,
    1515,   583,   584,   905,  1564,  2509,   585,   586,   587,   588,
      21,    64,    22,    23,    24,   116,   117,   589,   118,    25,
     645,    26,   119,   120,   157,   367,  1324,  1998,  2781,   121,
     153,   298,   590,  2071,    27,    28,    29,    30,    31,    59,
      88,   122,   412,  1333,  2004,   591,   900,  1847,  1553,  1845,
    2861,  2500,  1554,  1844,  2166,  2502,   592,   593,   594,   792,
     793,  1236,   123,   238,   366,   649,   650,   960,  1322,   595,
     945,   946,   596,   823,  1273,   947,   769,    90,    91,    92,
      93,  1243,   183,   138,    94,   135,   191,   192,  1244,  1245,
    2173,  1246,   409,   410,   928,   411,   929,  2480,  2481,  1247,
    1248,  1121,  2607,  2608,  2786,   690,   807,   808,   597,  1136,
    2846,   598,  2476,   599,  1154,  1155,  1156,  1487,  1485,   600,
     601,  1767,  1797,   602,  1009,  1373,   603,   851,   852,   604,
     867,   605,  1938,   606,  2854,   607,  1815,  2960,  2961,  2962,
    3032,   856,   608,  1249,  1566,  1877,  1878,   609,  1455,   706,
    1021,   610,   611,  2006,  2611,  2797,  2798,  2904,  2905,  2909,
    2907,  2910,  2993,  2995,   612,   613,  1238,  1558,   614,  1240,
     875,   876,   877,  1216,   615,   616,   617,  1528,  1208,   870,
     199,   878,   879,   770,  2007,  2361,  2362,  2345,   710,   711,
    2002,  2346,  2349,   124,   152,   359,   984,  1658,  2363,  2801,
    1030,   618,   868,   125,   149,   356,   981,  1656,  2350,  2799,
    2003,   895,  2149,  2721,  2963,  1211,   619,   620,   621,   622,
     623,   779,  1765,   703,  1712,   624,  2674,   697,   698,  2068,
    1352,   625,   626,   993,   994,   995,  1364,  1695,   996,  1692,
    1361,   997,  1667,  1353,   998,   999,  1000,  1001,  1661,  1344,
     627,   788,   771,   628,  1296,  1962,  2770,  2895,  2571,  2572,
    2573,  2574,  2769,  2887,  2888,  1297,  1298,  1611,  2563,  2763,
    2244,  2560,  2979,  2980,  1299,  1621,  2298,  1972,  2577,  2773,
    1807,  2141,  1973,  1300,  1301,  2684,  2936,  2937,  2938,  3012,
    1302,  1303,  1158,   629,   630,   953,  1304,  1305,  2901,  1627,
    1628,  1629,  1975,  2300,  2776,  2777,  1306,  1948,  2238,  2760,
    1354,  1355,  1340,  2028,  1659,  2029,  1356,  2032,  1357,  2055,
    1358,  2056,  2416,  2417,  1662,  1307,  1605,  1606,  1945,  1308,
    2932,  2830,  2928,  1951,  2431,  2676,  2677,  2678,  2926,  2432,
    1952,  2831,  2933,  2015,  2016,  2017,  2018,  2019,  2020,  2642,
    2643,  2644,  2920,  2809,  3001,  2021,  2803,  2804,  2391,  2022,
    2392,  2023,  2518,  1688,  1689,  1690,  2663,  1691,  2413,  2407,
    2819,  2030,  2778,  2394,  2575,  2828,  1879,   772,  1880,  2179,
    1049,  2076,  1743,  2045,  2659,    58,   631,   632,  2555,  2755,
    2231,  2754,  1632,  1980,  1981,  2235,  1939,  1309,  1940,  2249,
    2766,  1395,  1935,  1936,  2685,  2833,  2568,  2559,  2024,  1619,
    1959,  1960,  2929,  2025,  1882,  2525,  2811,   633,   634,  1598,
    1937,  2550,  2751,  2752,  1276,   635,   774,  1311,  1312,  1614,
    2246,  1313,  1314,  1956,  2201,  2514,   691,  1883,   693,  1377,
    1884,    62,    47,    78,    75,   637,   881,  1532,  1144,  1202,
     638,   860,   639,  2116,   640,  1706,   695,  1379,   641,   642,
      73,   360,   361,   362,   363,   364,   643
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -2572
static const short yypact[] =
{
    1204,   458, -2572,   625,   625,   625,   625,   625,   625,   625,
   -2572,   625, -2572,   358, -2572, -2572, -2572,   810, -2572, -2572,
   -2572,   393, -2572,  1204, -2572, -2572, -2572, -2572, -2572,  1288,
   -2572, -2572, -2572, -2572, -2572,   328,   555, -2572,   420, -2572,
   -2572,   823, -2572, -2572,   390, -2572,   333, -2572, -2572, -2572,
   -2572, -2572, -2572, -2572, -2572, -2572, -2572, -2572, -2572,   870,
     612, -2572, -2572, -2572,   242, -2572, -2572, -2572, -2572, -2572,
   -2572, -2572, -2572, -2572, -2572, -2572, -2572, -2572, -2572,   390,
     366, -2572, -2572,   748,   810, -2572,    63, -2572, -2572, -2572,
   -2572,   966,   395, -2572, -2572, -2572,  1014,   697, -2572, -2572,
   -2572,  1037, -2572, -2572, -2572, -2572, -2572, -2572, -2572, -2572,
   -2572, -2572, -2572, -2572, -2572, -2572, -2572,   242, -2572, -2572,
   -2572, -2572, -2572, -2572, -2572, -2572, -2572, -2572, -2572, -2572,
    6252,   395, -2572,    88,   106, -2572, -2572,   611, -2572,   462,
    1040,   612,   559, -2572, -2572, -2572, -2572, -2572,  4163, -2572,
     655,   997, -2572,   810, -2572, -2572, -2572, -2572, -2572, -2572,
     594,   783, -2572, -2572,   689, -2572,   694, -2572,   676, -2572,
   -2572,   707, -2572,   709, -2572, -2572, -2572, -2572, -2572, -2572,
   -2572, -2572, -2572,   721, -2572, -2572, -2572,   106,  1595,  1113,
   -2572,   161, -2572,   106, -2572, -2572,   129, -2572, -2572, -2572,
      69, -2572, -2572, -2572, -2572, -2572, -2572, -2572, -2572,   594,
   -2572,   783, -2572, -2572,   731, -2572,   743, -2572,   720, -2572,
   -2572,   751, -2572,   757, -2572, -2572, -2572, -2572, -2572, -2572,
   -2572, -2572,   761,  1158, -2572,   763, -2572,   810,   810,   779,
   -2572, -2572,   -60, -2572,   592,  1147, -2572,   598,  1178,  1167,
    1181, -2572,  1185,  1196,  1198, -2572,   615, -2572,   312, -2572,
   -2572, -2572, -2572, -2572,   106, -2572,   106,   807,   164, -2572,
   -2572, -2572,  1221, -2572, -2572,  1232, -2572, -2572, -2572, -2572,
   -2572,   -60, -2572, -2572, -2572,  1242,  1249,   612,  1185,  1265,
    1268,   653, -2572,  1255, -2572,   926,   889, -2572,   959, -2572,
   -2572, -2572,   705, -2572, -2572,  1285, -2572,   907, -2572, -2572,
   -2572, -2572, -2572, -2572, -2572,  1178,   907, -2572, -2572, -2572,
   -2572, -2572, -2572,   912,   207,   232,   271, -2572,  3290, -2572,
   -2572, -2572,   921,  1307,   251,   963, -2572, -2572,  1595, -2572,
     106, -2572, -2572, -2572,   737,  1312,  1103,   255,   262,   295,
     936,   264,   974, -2572, -2572, -2572,   981, -2572, -2572,   981,
    1013, -2572,  3535,   559,  4882,  2282,   272,   981,  1335,     8,
   -2572,  1147,  1331, -2572, -2572, -2572, -2572,  1334, -2572,  1338,
   -2572,  1342, -2572, -2572, -2572, -2572, -2572, -2572,  1185,  1343,
   -2572, -2572, -2572, -2572,   173,  1352,     8,   967,  1353, -2572,
    1361, -2572, -2572, -2572,  1371, -2572, -2572, -2572,   799,  1030,
    1399, -2572,   981,  1036, -2572, -2572, -2572, -2572, -2572, -2572,
   -2572, -2572,   111, -2572, -2572, -2572, -2572, -2572, -2572, -2572,
      72, -2572, -2572, -2572, -2572, -2572, -2572, -2572, -2572, -2572,
   -2572, -2572, -2572, -2572,    90,    90,  6368, -2572, -2572, -2572,
   -2572, -2572, -2572, -2572, -2572, -2572, -2572, -2572, -2572, -2572,
   -2572, -2572, -2572, -2572,   818, -2572, -2572, -2572,  6368, -2572,
     818, -2572,   818,   972, -2572, -2572,    60, -2572, -2572,    60,
   -2572, -2572,    60, -2572, -2572, -2572, -2572, -2572, -2572, -2572,
   -2572, -2572,   818, -2572, -2572, -2572, -2572,   -73, -2572, -2572,
   -2572, -2572, -2572, -2572,   111, -2572, -2572, -2572, -2572, -2572,
    1997,   818,  7158, -2572,   765,   765, -2572, -2572, -2572,    74,
     818,   114,  6368,  7158, -2572,  1914,  6368, -2572,   390, -2572,
    7158, -2572,  7158,   818, -2572, -2572,  7158,  7158,    90, -2572,
   -2572, -2572,   765, -2572, -2572,   765, -2572, -2572,    97, -2572,
   -2572, -2572, -2572, -2572, -2572, -2572, -2572, -2572, -2572, -2572,
   -2572, -2572, -2572, -2572, -2572, -2572, -2572, -2572, -2572, -2572,
   -2572, -2572, -2572, -2572, -2572, -2572, -2572, -2572, -2572, -2572,
   -2572, -2572, -2572, -2572, -2572, -2572, -2572, -2572, -2572, -2572,
   -2572, -2572, -2572, -2572, -2572, -2572,   151, -2572, -2572, -2572,
   -2572, -2572, -2572, -2572, -2572, -2572, -2572, -2572, -2572, -2572,
   -2572, -2572, -2572, -2572, -2572, -2572, -2572, -2572, -2572, -2572,
   -2572, -2572, -2572, -2572, -2572, -2572, -2572, -2572, -2572, -2572,
   -2572, -2572, -2572, -2572, -2572,   662, -2572, -2572, -2572, -2572,
   -2572, -2572, -2572, -2572, -2572,   332, -2572, -2572, -2572,   320,
   -2572,  1043, -2572, -2572, -2572,  1148, -2572, -2572,  1061,  1071,
    1072,  1073, -2572, -2572,   841,  1444,  1080, -2572, -2572,  1193,
   -2572,  1107,  1108,   876,  1114, -2572, -2572, -2572,  1115, -2572,
     370, -2572,   263, -2572, -2572, -2572, -2572,   883,  1469,  1059,
   -2572,   901, -2572,   899, -2572,  1491,  -164,   265, -2572, -2572,
   -2572,  1116, -2572,  1493, -2572, -2572,  1060,   118, -2572, -2572,
   -2572,  1005, -2572,  7158,  7158, -2572, -2572,  1110,  1020,  1117,
    1118,  1119,  1121,  1124,  1126,  1132,  1133,  1136,  1143,  7158,
    1189,  1144,  1151,  1156, -2572,  7158,  7158,  1163,  1164, -2572,
    7158,  1168, -2572,  1169,  1176,  1177,  1180,  1182,  1183,  1184,
    7158,  1186,  5557, -2572,    94, -2572, -2572, -2572, -2572, -2572,
   -2572, -2572, -2572, -2572, -2572, -2572, -2572,    13, -2572,  1188,
   -2572, -2572, -2572, -2572, -2572, -2572,   818, -2572, -2572,  1493,
   -2572,    34, -2572, -2572,  1355, -2572,   124, -2572,  1160, -2572,
   -2572, -2572, -2572,  1552, -2572, -2572,   302, -2572,  1010, -2572,
    1021,  1552, -2572,  1048, -2572, -2572,  1225,   237, -2572,  1187,
   -2572,   994, -2572, -2572,  1224, -2572,   -81, -2572,   998,   -26,
    -183, -2572,  1330,  7158,  7158, -2572,  1632, -2572, -2572, -2572,
   -2572, -2572, -2572,   100,   100,   100, -2572,   100, -2572,   100,
     100,  1069,    34,  1069,  1069,   122,   122,  1069,  1069,    34,
   -2572,  1642, -2572,    43,  1644, -2572,    34, -2572,  6228, -2572,
      78,    58, -2572, -2572,  7158, -2572, -2572, -2572, -2572, -2572,
     831, -2572, -2572,   559,  1289,   559,  6368, -2572,    77, -2572,
   -2572,  7158,  1241,  1243,  1245,  1247,  1248,  1638,  1257,   114,
    1176, -2572,  1350,   414,  1106, -2572,  1120, -2572, -2572, -2572,
     146, -2572,  1668, -2572,  1666, -2572, -2572,    61,  1130, -2572,
   -2572,  1675, -2572,  1049,  1675,  1681,  1050,  1675,  1681,  7158,
    1675, -2572, -2572,   118,   818, -2572, -2572,  1291,   343, -2572,
   -2572,  1282,   818,  7158,  1283, -2572, -2572,  1670,  1671,  1652,
   -2572, -2572, -2572, -2572, -2572, -2572, -2572, -2572,   150,   150,
   -2572, -2572, -2572,  1267, -2572, -2572,  1628,   332, -2572, -2572,
     374, -2572, -2572, -2572,  1263, -2572, -2572, -2572, -2572,  6252,
    1185, -2572,  1264, -2572,   267, -2572, -2572, -2572, -2572, -2572,
   -2572,   810, -2572, -2572,   810,    37,  1293,  1679, -2572, -2572,
     708,  1296,   740,  1701, -2572, -2572, -2572, -2572, -2572, -2572,
   -2572, -2572,  1299, -2572, -2572,  1469,   899,   106,   111,  -178,
    1691, -2572, -2572, -2572, -2572, -2572,  1138,  1123,  1146,  1306,
   -2572,  1316,   172, -2572, -2572, -2572,  1836,  1836,   765,  7158,
   -2572, -2572,   765,   765,   765,   765,  1277,  7158,   999,  1097,
    7158,  5557,  1319, -2572, -2572, -2572, -2572, -2572, -2572, -2572,
    1125,   765,  1709,  7158,  3186,  5557,  1277,  7158, -2572,  5557,
    1714,   219, -2572, -2572, -2572,  7158, -2572,  7158,  7158,  5557,
    7158,  7158,  7158,  7158,  7158,  7158,  7158,  7158,  7158,  7158,
    7158,  7158,  7158,  7158,  7158,  7158,  7158, -2572, -2572, -2572,
   -2572, -2572, -2572, -2572, -2572, -2572, -2572,  7158,  7158, -2572,
   -2572,  1326,  7158, -2572,  7158,  1327, -2572, -2572, -2572, -2572,
   -2572, -2572, -2572, -2572, -2572, -2572, -2572, -2572, -2572,   818,
   -2572,  1135,  1328, -2572, -2572, -2572,   111,   165, -2572,   165,
     114,    60,  7158,  7158,  7158,  1333, -2572, -2572,   818,   818,
   -2572,  1139,   114,   765,  1104, -2572,   106,    46,   -73,   818,
   -2572,  1150,  7158,  1421, -2572, -2572,  1217, -2572, -2572,  1644,
      67, -2572,   118, -2572, -2572,  1738,  1743, -2572, -2572, -2572,
   -2572, -2572, -2572,  1112, -2572, -2572, -2572, -2572, -2572, -2572,
   -2572, -2572, -2572, -2572, -2572, -2572,  1997, -2572,   122,  7158,
     -20, -2572, -2572,  1759, -2572,   765,  1748,  1749, -2572, -2572,
   -2572, -2572, -2572,   179, -2572, -2572, -2572, -2572,  1645, -2572,
    1580, -2572, -2572, -2572,  7158,    90, -2572, -2572, -2572, -2572,
    1764,   765,   765, -2572,  1222, -2572,   765,  1194,   818, -2572,
   -2572,  7158,   -54, -2572,  1238, -2572,   381, -2572,  1336, -2572,
    1337,  7158,   485, -2572, -2572,   395, -2572,  1784, -2572,  1275,
   -2572,   818, -2572, -2572, -2572, -2572,   765,   765,   239,   343,
    1674,   711,   818,   118, -2572,  1279, -2572, -2572,  1801,  1782,
    1431, -2572, -2572, -2572, -2572, -2572,  1510,  1510,   144,  1287,
   -2572, -2572, -2572, -2572,  1493,  1493, -2572, -2572, -2572, -2572,
   -2572, -2572,   493,  1493, -2572,   427, -2572, -2572, -2572, -2572,
   -2572, -2572, -2572, -2572, -2572, -2572, -2572, -2572, -2572, -2572,
     867, -2572, -2572, -2572, -2572,   145,   145,    65,   587, -2572,
     804, -2572,   374, -2572,   810,  1794, -2572, -2572,  1794, -2572,
   -2572, -2572, -2572,   810, -2572, -2572,  1493, -2572,   187,  1412,
   -2572, -2572,   187, -2572, -2572, -2572,  1413,  1414,   656,  1415,
    1416,  2509, -2572, -2572, -2572, -2572, -2572, -2572, -2572, -2572,
   -2572, -2572,   656,  1195, -2572,   370,  1802, -2572,  1228,   196,
   -2572,   114,  1273, -2572, -2572,  1059, -2572, -2572, -2572,  1314,
   -2572, -2572, -2572, -2572, -2572, -2572, -2572,  1470,  5557,  6368,
    1471,  1472,  1473,   269,   493,  1474,  3887,  1476,   -59,   850,
   -2572, -2572,   142,  1477, -2572, -2572, -2572,  3916,  1824,  1614,
    1481,  1482,  4292, -2572,  1484,  1495,  1488, -2572,  7158,  7158,
    7158,  4767,  7158,  5232,  5273,  5532,  5641,  3599,  4048,  5677,
    5725,  5756,  5840,  5870,  6098,  6128,  6210,  1836,  1836,   418,
    2249,  1742,  5557,  5557,  1277,  5557,  5557,  1277,  6368, -2572,
   -2572, -2572,  1269, -2572, -2572, -2572, -2572,  1254, -2572,  1858,
    1861, -2572,  1862,  1311,  7158, -2572, -2572,  1290,  1882, -2572,
    1439,  1300,  1681, -2572,  1523,   273, -2572,  1497, -2572, -2572,
    1309,   910, -2572, -2572, -2572,  1505, -2572,   644,  7158, -2572,
   -2572, -2572,  7158,  -163,    34,  1910,  1384,  1893,  1894, -2572,
   -2572, -2572, -2572, -2572, -2572, -2572, -2572, -2572, -2572, -2572,
   -2572, -2572, -2572, -2572, -2572, -2572,  1511, -2572, -2572, -2572,
     818,  1418,  6503, -2572, -2572, -2572,  1883,  7158,   559,    76,
   -2572, -2572,  1623,  6368,  1559,  1928,  1564,   270, -2572,  1565,
     114, -2572,  6368,  1533, -2572, -2572,  1604, -2572,  7158,   -35,
   -2572,  1372, -2572, -2572,   589, -2572,  7158, -2572, -2572,  1341,
      88, -2572,  1366, -2572,  1950,  7325, -2572, -2572,   131, -2572,
    1681,  1681,  1329, -2572,  1438,  1450,   765,   765, -2572, -2572,
   -2572, -2572, -2572, -2572,   -53,   -37, -2572,   915, -2572, -2572,
   -2572, -2572,   765,  2576,  1966,  1951, -2572,   114,  1751,    75,
    1531,  1901,    55,   168, -2572,    27, -2572, -2572, -2572,  1573,
     112,  1493,   166, -2572,  1388,  1385, -2572, -2572, -2572,  7801,
   -2572,  1446, -2572, -2572, -2572, -2572,  1582,  1389,  1984, -2572,
    1970, -2572, -2572, -2572, -2572,   818,   101, -2572, -2572, -2572,
    1377,   587, -2572, -2572, -2572, -2572, -2572, -2572,   531, -2572,
   -2572, -2572, -2572,  1591,  1593, -2572,  1561, -2572,  1562, -2572,
    1596,   274, -2572,  7099,   280,  1493,  1493,   290, -2572,  1493,
    7099, -2572, -2572,  1654,  1654, -2572,  1600, -2572,  1602,  1617,
   -2572,  1618,  1619, -2572,  1620, -2572, -2572, -2572,   110, -2572,
   -2572, -2572,   310, -2572, -2572,   311, -2572, -2572, -2572,  1634,
     395,  1691, -2572,  2023,   114,  7158, -2572,  2028, -2572, -2572,
   -2572, -2572,   656, -2572, -2572, -2572,  2029, -2572,  5557, -2572,
   -2572, -2572, -2572,  7801, -2572, -2572,  1189,  1189,  2010, -2572,
    2011,  1475,   903, -2572,  1020,  1667,  1630, -2572, -2572, -2572,
   -2572, -2572, -2572, -2572, -2572,  1020, -2572, -2572, -2572,  1672,
    1020,  5557,  5557,  5557,  1020,  5557,  1020,  1020,  1020,  7158,
    1678,  7158,  1680, -2572,  1441,   656,    86, -2572,   114,  7158,
    7158,  7158,  6643,  2036,   882, -2572, -2572,   114, -2572,  1445,
   -2572, -2572, -2572, -2572, -2572, -2572, -2572,   916, -2572, -2572,
     355, -2572,  1452,  7158, -2572, -2572, -2572,  2037, -2572, -2572,
   -2572, -2572, -2572, -2572,  1681, -2572, -2572, -2572, -2572, -2572,
   -2572, -2572, -2572, -2572, -2572,   818, -2572, -2572,  1865, -2572,
   -2572, -2572,  1745, -2572, -2572, -2572,  1729,  1730,  1621,  1455,
    1733,  1650, -2572, -2572,   -41,  1721, -2572, -2572, -2572, -2572,
    1604, -2572, -2572, -2572,    64,   769, -2572, -2572, -2572,  1801,
    7158,  1657,  2042, -2572, -2572,   104,   136, -2572,   883, -2572,
   -2572,  1654, -2572, -2572,  7801,  1660, -2572, -2572,  1661, -2572,
   -2572,  1663,  1665,  1682,  1685,   -42, -2572,  2061, -2572, -2572,
   -2572,  2571, -2572,  1676, -2572,   127,  1453, -2572,  2063,    34,
   -2572, -2572,  2085, -2572,  2090,  1345,  1345,  1345,  1345,  1511,
   -2572, -2572,  2093, -2572, -2572, -2572,  2094, -2572, -2572, -2572,
    1345,   240, -2572, -2572, -2572, -2572, -2572, -2572, -2572, -2572,
   -2572, -2572, -2572, -2572, -2572, -2572, -2572, -2572,   317, -2572,
    2075, -2572, -2572,  1493, -2572, -2572, -2572, -2572, -2572, -2572,
   -2572,  1527,  1528,    81, -2572,    27, -2572,  1493,  1509, -2572,
    7099, -2572, -2572,  1699, -2572, -2572, -2572, -2572, -2572,  2104,
   -2572,  4025,  1548, -2572,  7158, -2572,  7158, -2572, -2572, -2572,
   -2572, -2572, -2572, -2572,  1493, -2572,  1493,   499,  1515,  1517,
    2112, -2572,  2113, -2572,   818, -2572,   400,   400, -2572, -2572,
    2114, -2572,  2114,   557,   557,  2114, -2572, -2572,  2282, -2572,
   -2572,  7796,   115, -2572,  2282,  2477, -2572,   115,  1493,   187,
   -2572,  1712,  4085,  1712,  7129,   228,  2116, -2572, -2572, -2572,
   -2572, -2572, -2572, -2572,   797,  3307, -2572,   492,  1754,  2120,
   -2572, -2572,   334, -2572,   656, -2572,   403,   230, -2572, -2572,
   -2572, -2572, -2572, -2572, -2572,  1524,   376,  2105,  2105,  2106,
    2105,  2105,  2109, -2572,   158, -2572,   187, -2572, -2572,   656,
   -2572, -2572, -2572,  1537,   114,  2130, -2572, -2572,   404, -2572,
    6896,  1769,  1770,  7158,   193, -2572,  1536, -2572,  1773, -2572,
    2123, -2572,  1584, -2572, -2572, -2572, -2572,  2125, -2572,  1549,
   -2572, -2572,  1783,  1786,  1787, -2572,  1796, -2572, -2572, -2572,
    5557,   422, -2572,   424, -2572,  1797,  2149,   425,   114,  2165,
   -2572, -2572, -2572, -2572,  7158,  1631,  1920,  7158, -2572, -2572,
   -2572, -2572,  2155,  1808,   355,  1513,  1513,  2176,   367, -2572,
    2179, -2572, -2572, -2572,  1513, -2572,  1669,  2173,  2190, -2572,
     285,   818,  1980,   426, -2572,  1438,  7158, -2572,  1832,  6368,
     818, -2572,    72, -2572,   818, -2572,  1833,  6368, -2572, -2572,
     -41,  1721, -2572,  1511, -2572, -2572,   125, -2572, -2572,  1656,
   -2572, -2572,  1767, -2572,  7018, -2572, -2572, -2572, -2572, -2572,
    1603,  1530,   190,   543,  1798,   543,   543,   543,   543,  7801,
    7325,  7801,  7801,  7801,  7801, -2572, -2572, -2572, -2572, -2572,
   -2572, -2572,   111, -2572, -2572,  1791,   652, -2572, -2572, -2572,
    1622,   765,  1345,   765,  1345, -2572, -2572, -2572, -2572, -2572,
     -53,  1345,   -37,  1345, -2572,    34,  2576, -2572,  1843,  1807,
     493,   867,  1531,  1531, -2572, -2572, -2572, -2572,   435, -2572,
    1774, -2572,  2211,  1493,   437, -2572,  1615, -2572,  7801,  1687,
   -2572, -2572, -2572, -2572, -2572, -2572, -2572, -2572, -2572, -2572,
   -2572, -2572, -2572, -2572, -2572, -2572, -2572, -2572, -2572, -2572,
   -2572, -2572, -2572, -2572, -2572, -2572, -2572, -2572, -2572, -2572,
   -2572, -2572, -2572, -2572, -2572, -2572, -2572, -2572, -2572, -2572,
   -2572, -2572, -2572, -2572, -2572,   209, -2572, -2572,  1693, -2572,
     446, -2572,  1624, -2572, -2572, -2572,  1970,   818, -2572,  2114,
   -2572, -2572, -2572,   557,   557, -2572, -2572,   557,  2038,  1625,
    1629, -2572, -2572,    90,    90,    90,  2207,    90,    90,    90,
      90,    90,    90,  2209, -2572,  2213,    90, -2572, -2572, -2572,
   -2572, -2572, -2572, -2572, -2572,  7796, -2572,   818,  1640, -2572,
    1814,  2038,  2216, -2572,  2218,  2219,  2220,  2222,  2223,  2224,
     171,  2477, -2572,  1814, -2572,   447, -2572,  1803, -2572, -2572,
     300,  2005, -2572, -2572,  7099, -2572,  7099, -2572, -2572, -2572,
   -2572, -2572, -2572, -2572, -2572, -2572, -2572,  7801,  1842, -2572,
    1845,    96,  7229,  2227, -2572,  1981,  1493,  1658,  1493, -2572,
   -2572, -2572, -2572,  1919,  2230,  1919, -2572,  2254,  2254,   449,
    1891,  2254, -2572,  1895, -2572, -2572, -2572,   187, -2572, -2572,
   -2572, -2572,   114, -2572,   656,  2016,  1801, -2572, -2572, -2572,
     175,  1762,   490,  1614,  1189,  1705,   988,  1906, -2572, -2572,
   -2572, -2572, -2572,  7158, -2572, -2572, -2572,  1834, -2572,   216,
     114, -2572,  2277,  1875, -2572, -2572,  1915, -2572, -2572, -2572,
    1757, -2572, -2572, -2572,  1513,   106,  2267, -2572,  1513, -2572,
   -2572,   765, -2572, -2572,  7158, -2572, -2572, -2572,   765,  1889,
    2287, -2572,  2076, -2572, -2572,    34,  5557,  1971, -2572, -2572,
     118,  1892, -2572, -2572,  6368, -2572,  1926, -2572, -2572, -2572,
     769, -2572,  1438, -2572,  7158, -2572,   106, -2572,  1644, -2572,
    1919, -2572,   283,  2293,  1931, -2572, -2572, -2572,  7801, -2572,
    7801,  7801,  7801,  7801,  2571,   454, -2572,  1761,  1761,  1364,
    1397, -2572,  7158,  1887, -2572,  1985, -2572,  2289, -2572, -2572,
   -2572, -2572, -2572, -2572, -2572, -2572, -2572, -2572, -2572, -2572,
   -2572,  7801, -2572, -2572, -2572,   867,  1493, -2572, -2572,  2194,
     459, -2572, -2572, -2572, -2572, -2572, -2572,   818, -2572,  2302,
    1493, -2572,  2311,  2304, -2572, -2572, -2572, -2572,  1493, -2572,
    1877,  1727, -2572, -2572, -2572, -2572, -2572, -2572, -2572,  2138,
    6252, -2572, -2572, -2572, -2572, -2572, -2572, -2572, -2572, -2572,
   -2572, -2572, -2572, -2572, -2572, -2572,  -155,  2324, -2572,   818,
    1027, -2572,  2138, -2572, -2572, -2572, -2572, -2572, -2572, -2572,
   -2572, -2572, -2572, -2572, -2572,   493, -2572,  2116, -2572,  2571,
     162, -2572,   162, -2572, -2572, -2572,  7801,   158,  7393, -2572,
   -2572, -2572,  1712, -2572, -2572, -2572,  2571,   198, -2572, -2572,
    2310, -2572, -2572, -2572, -2572, -2572, -2572, -2572, -2572, -2572,
    1961, -2572,  2308,  1964,  1965,  2314, -2572, -2572,  1972, -2572,
   -2572, -2572, -2572, -2572, -2572,   183,  2335, -2572, -2572,  2319,
    1999, -2572,  1750,   543,  2043, -2572, -2572, -2572,  1011, -2572,
   -2572, -2572, -2572,  5557,   765,    34,  1995,   114, -2572,  7158,
   -2572,  1805,  2329,    34, -2572, -2572,   379, -2572, -2572, -2572,
   -2572,   247,  1979,  1681,   818,   818, -2572, -2572, -2572,   118,
   -2572,  1986,  1910,  1948, -2572,  1971, -2572, -2572, -2572, -2572,
    2139,   199, -2572,  1654,  1753,  1654, -2572,  2344,  7801,  2439,
    2586,  2913,  3109,  7801, -2572,  1806, -2572, -2572, -2572,  1438,
   -2572,   460, -2572,   192,   867,   867, -2572, -2572,   493, -2572,
   -2572,  1493, -2572,  1957, -2572,  2287,  1852,  7424, -2572,   463,
     119,  1493,  7639,   818, -2572, -2572,   294, -2572, -2572, -2572,
   -2572, -2572, -2572, -2572, -2572, -2572, -2572,   818,  2324, -2572,
   -2572, -2572,   818, -2572,   818, -2572, -2572,  1553, -2572,  2152,
   -2572,  2160,  7801,   465, -2572, -2572, -2572,   466,  3291,  1959,
   -2572, -2572, -2572,  2355, -2572, -2572,  1944,  1777, -2572, -2572,
   -2572, -2572,  2018, -2572,   175, -2572,   175, -2572, -2572,  7801,
   -2572,  1963, -2572,  2016,  1212,    75, -2572, -2572, -2572, -2572,
   -2572,   114, -2572,  2021,  7762,  1988, -2572, -2572, -2572,  1799,
      34, -2572, -2572, -2572,   584,  1910, -2572, -2572,  2031, -2572,
    1971,   769, -2572, -2572,  1790,  1919,  1800, -2572,   468, -2572,
   -2572, -2572, -2572,  2571, -2572, -2572, -2572, -2572,  1852, -2572,
   -2572,  7801, -2572,  7736,   490,  5957, -2572,  2394, -2572, -2572,
    2571,  1493,  2389, -2572,  7099, -2572, -2572, -2572,  2287,  1877,
   -2572, -2572, -2572, -2572,  1227,  1227, -2572,  1227, -2572,  1227,
    1227, -2572, -2572, -2572,   193,   140, -2572, -2572,  7801,   158,
   -2572,  1998, -2572,  1919, -2572, -2572,   470, -2572,  2399, -2572,
    2571,  7099, -2572, -2572, -2572, -2572,  2402, -2572,  -123, -2572,
   -2572,  2016,    33, -2572, -2572,   100,   100,   100,   100,   100,
     100, -2572,  2386, -2572,   471, -2572,  7158,  2393, -2572, -2572,
   -2572,   596, -2572,  1971,  6368,  1971, -2572, -2572,  2201,  1919,
   -2572,  1919, -2572,   131,    34, -2572,   490,   193, -2572,   472,
   -2572,  2571, -2572,   475,  1530,  7639, -2572,  2014, -2572,  2211,
   -2572, -2572, -2572,  1227, -2572,  1227, -2572, -2572,  2054, -2572,
    2571, -2572, -2572, -2572, -2572,   175, -2572,  7801,  2211,  1212,
   -2572, -2572, -2572, -2572, -2572, -2572, -2572,   939, -2572, -2572,
   -2572, -2572, -2572, -2572, -2572, -2572, -2572,  7762, -2572,  2424,
   -2572, -2572,   608, -2572, -2572, -2572, -2572, -2572, -2572, -2572,
   -2572,   127, -2572, -2572, -2572,  7736, -2572, -2572, -2572,  7639,
   -2572, -2572, -2572, -2572, -2572, -2572,  1363,  1363, -2572, -2572,
    1363, -2572,  7158, -2572,  2062, -2572, -2572,   477, -2572, -2572,
   -2572,  2064, -2572, -2572, -2572,   204, -2572,   118, -2572,  1910
};

/* YYPGOTO[NTERM-NUM].  */
static const short yypgoto[] =
{
   -2572, -2572, -2572, -2572, -2572,   287, -2572,   368,  -185, -2572,
   -2572,  -842,  -345, -2572, -2572, -1526, -2572, -2572, -2572, -2572,
    -590, -2572, -2572, -2572, -2572, -2572, -2572, -2572, -2572, -2572,
   -2572, -2572, -2572, -2572, -2572, -2572, -1995, -2572, -1405, -2572,
     371, -2572, -2572, -2572, -2572, -2572, -2572, -2572,   600, -2572,
   -2572, -2572, -2572,  1211, -2572,   896, -2572, -2572,   -47, -2572,
   -2572,  2410, -2572,  2409,  2084, -2572, -2572, -2572, -2572, -2572,
     668,   316, -2572,   665, -2572, -2572, -2572, -2572, -2572, -2572,
   -2572, -2572, -2572, -2572, -2572,   -93,   897,   335, -2572, -2572,
    2166,   -34, -2572,  2313, -2572, -2572,  2315, -2572,  2253, -2572,
   -2572, -2572,  2185,  2072,  1142,  2183,  -308, -2572, -2572, -2572,
   -2572, -2572,  1149,  -965, -2572, -2572, -2572, -2572, -2572, -2572,
    -140,  2122,  2270,  -196,   734, -2572,  2115,    47, -2572,  2168,
   -2572, -2572, -2572, -2572,  2172, -2572, -2572, -2572, -2572,  -322,
   -2572, -2572, -2572, -2572, -2572, -2572, -2572, -2572,  2107, -2572,
    2108, -2572, -2572, -2572, -2572, -2572, -2572, -2572, -2572,  -851,
   -2572, -2572,  -526, -2572, -2572, -2572, -2572, -2572, -2572, -2572,
    2039, -2572, -2572,   976, -2572,  -885,  -800,  -306, -2572, -2572,
   -2572, -2572, -2572, -2572, -2572, -2572, -2572,   733, -2572, -2572,
   -2572, -2572, -2572, -2572, -2572,  -442, -2572, -2572, -2572, -2572,
   -2572,  1974, -2572, -2572, -2572, -2572, -2572, -2572, -2572, -2572,
   -1688, -2572, -2572, -2572, -2572, -2572, -2572,  1101, -2572, -2572,
   -2572, -2572, -2572, -2572, -2572, -2572, -2572, -2572, -2572, -2572,
   -2572, -2572, -2572, -2572,  1539, -2572, -2572, -2572, -2572,   862,
   -2572, -2572, -2572, -2572, -2572, -1146, -2572, -2572,   858, -2572,
   -2572, -2572, -2572, -2572, -2572,  -785,  -505,   738,  1016, -2572,
    -472,   667,  -820,  1483, -2572,   -95, -2572, -1807,    -2,  -230,
   -2572, -2572,   842,  1519, -1716,  -188,   419, -2572, -2572, -2572,
     345,  1272, -2572, -2572, -2572, -2572, -2572, -2572,   322, -2572,
     -12, -2572,  1271, -2572,   960, -2572,   645, -2572, -2572, -2572,
    -508, -2572, -2572, -2572, -2572, -2572, -2572, -2572, -2572,   759,
   -2572, -1214, -2572,   948, -2572, -2572, -2572, -2572, -2572, -2572,
   -2572, -2572, -2572, -2572,   318, -2572,   319, -2572, -2572, -2572,
   -2572,  1391, -2572, -2572, -2572, -2572, -2572, -2572,  -168, -1466,
   -2572, -2572, -2572, -2572,   518, -2572, -1676, -2572,  -830, -2572,
   -2572, -2572, -2572, -2572, -2572, -2572, -2572, -2572, -2572, -2572,
   -2572, -2572, -2572, -2572,  2525, -2572, -2572, -2572,  2435,  2524,
   -1150, -2572, -2572, -2572, -2572, -2572, -2572, -2572,   -57, -2572,
   -2572, -2572, -2572, -2572, -2572, -2572, -2572,  2527, -2572, -2572,
   -2572, -2572, -2572, -2572, -2572, -2572, -2572, -2572,  1003, -2572,
   -2572, -2572, -2572, -2572, -2572, -2572, -2572, -2572, -2572,  -417,
    2077, -2572, -2572, -2572, -2572, -2572,  1911, -2572, -2572, -2572,
   -2572, -2572, -2572, -2572, -2572, -2572,  2025, -2572, -2572,   -64,
   -2572, -2572,  1001, -2572, -2572,  1320,  -192,  2298, -2572, -2572,
   -2572, -2572,    12, -2572,  -704,  1888,  1303, -2232,  -148, -2572,
    1006,  1646,   -38,  -215, -2572,  -959, -2572,  1435, -2572, -2572,
   -2572, -2572, -2572, -2572, -2572, -2572, -2572, -2572, -2572, -2572,
   -2572, -2572, -2572, -2572, -2572, -2572, -2572, -2572,  1393, -2572,
     977, -2572,  -352, -2572, -2572, -2572, -2572, -2572, -2572,  -386,
   -2572, -2572, -2572, -2572, -2572, -2572,   391, -2572,  1454,   -86,
   -2572, -2572, -2572, -2572,   221, -2572,  -212, -2572, -2572, -2572,
   -2572, -2572, -2572, -2572, -2572, -2572, -2572, -2572, -2572, -2572,
   -2572, -2572,  1706, -2572, -2572, -2572, -2572, -2572, -2572, -2572,
    -327, -2572,  1373,  1532, -2572, -2572,   231, -2572,  -433, -2572,
   -2572,   249,   588, -2572, -2572, -2572, -2572, -2572, -2572, -2572,
    -507, -2572, -2572, -2572, -2572, -2572, -2572, -2572, -2572, -2572,
   -2572, -2572, -2572, -2572, -2572, -2572, -2572, -2572, -2572, -2572,
   -2572, -2572, -2572, -2572, -2572, -2572, -2505, -2572,  1583,   833,
    -972, -2572, -2572, -2572,  1231, -2572, -1309, -2572, -2572, -2572,
   -1312, -2572, -2572, -1291, -2572, -2572, -2572, -2572,  1258, -2572,
   -2572, -2572, -2572, -2572, -2572, -2572, -2572, -2572, -2572, -2572,
   -2309,  -170, -2572, -2571, -2504, -2572,   659, -2572, -2572, -2572,
   -2572, -2572, -2572,  -429, -2572, -2572, -2572, -2572, -2572, -2572,
   -2572, -2572, -2572, -2572, -2572, -2572, -2572,  -392, -2572, -2572,
   -2572, -2572, -2572, -2572, -2572, -2572, -2572, -2572, -2572, -2572,
   -2572,   642, -2572, -2572, -2572,  -279, -2572, -2572, -2572, -2572,
   -2572, -2572,   226, -2572, -2572,   614, -2572,   954, -2572, -2572,
   -2572, -2572, -2572, -2572,  -966, -2572, -2572, -2572, -2572, -1392,
   -2572, -2572, -2572, -2572, -2572, -2572, -2006,   -51, -2572, -1868,
     194, -2572, -2572, -1646,   252,   253,   613, -2572, -2572, -2572,
   -2572, -2572, -2572, -2572, -2572, -2572,    -1,  -280, -2572, -2572,
     627, -2572, -1977, -2572, -2572, -2572, -1507, -2572, -2572,  -873,
   -2572,  -698,  1356,  -177, -1638, -2572, -2010, -2572, -2572, -2572,
   -2572,  1908,   222, -1634, -2310, -2572, -2572, -2572, -2572, -2572,
   -2572, -2572, -1966, -2572,   346, -2572, -1188, -2572,  1696, -2572,
   -2572,  -838,  -181, -2572, -2534,  -172,   -88,   428, -1935, -1364,
   -1690,   421,  -341,   713, -2572,   -70,  -249, -2572, -2572,  1394,
    -500, -2572, -2572,  -201,  1731, -2572,   815, -2572, -2572, -1233,
     113, -2572, -2572, -2572, -2572, -2572,  -436,  -418,  -434,   975,
   -2348,     9,  1449,   126, -2572, -2572, -2572, -2572, -2572,  1538,
   -2572,  -486, -2572, -2572, -2572, -2572, -2572, -2572, -2572, -2572,
    -660,  1383,  2323, -2572, -2572, -2572, -2572
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1792
static const short yytable[] =
{
      40,   268,   258,  1022,   692,  1019,   386,  1163,  1172,    32,
      55,    57,   712,  1331,  1190,  1789,   284,   112,   131,  1341,
    1363,   873,  1004,  1159,  2037,   815,    97,  2031,  2033,   861,
    1723,  2033,    32,  2074,  1258,   256,   416,  2165,    68,  2077,
    2046,    74,    77,  1763,  2415,  1574,  1575,  1693,  1268,  1169,
    1170,  1376,  1171,  1694,  1174,  1175,   915,  1668,  1615,   918,
     236,   140,   797,  1195,  1203,   824,  1476,  1929,   822,  2131,
     112,   858,  1488,   126,   128,   864,  2368,    77,  2372,   338,
     665,  1122,  1214,  1195,   790,   291,   692,   275,  2164,   137,
    -610,  -610,   269,   276,   277,  2661,   144,   700,   865,   871,
    -610,  1820,   150,   151,  2225,   909,  1984,    97,   154,   155,
     871,   201,   181,   269,  1489,   708,  1490,   269,  1491,  1116,
     269,   921,   922,   184,   185,  1164,   126,   269,  1823,  2175,
    1278,   186,  1280,  1196,  1942,   687,  2119,  1832,   871,  1197,
     753,   269,   921,   922,   299,   300,    81,   232,   394,  2501,
     235,  -610,   269,   270,   271,   239,   826,  1855,  1856,   269,
    1730,  2177,   783,   269,  1858,  1859,   266,  1731,  2203,   266,
    1235,  1386, -1790,  1335,  1274,  1855,  1856,  1263,   266,  1855,
    1856,   269,  2414,  1859,  1189,   269,  1858,  1859,   681,  1453,
    1127,  1128,   865,   292,   273,  2620,   930,  2248,  2248,  1017,
    2732,   266,  1250,  2813,   266,   129,   855,  1017,  2520,  2521,
    2522,  2523,   379,  1946,  1017, -1790,   874,   880,  1414,  1259,
     897,  2696,   773,  2219,   901,   773,   903,  2180,  2347,  2569,
     907,   908,   296,  1017,  2374,   782,  2374,   381,   302,   773,
    1949,  1284,  1139,   773,  1488,  1195,   344,  2893,   346,   330,
     799,   939,  1195,    97,  1006,   773,   389,   782,  1600,  1601,
     398,  2768,   718,   810,  1545,  2552,   782,   400,  2897,   404,
    1014,     1,  1329,   821,  1195,  1195,   383, -1790,   825,  2009,
     812,   102,  2806,  1839,  2806,  2009,   863,   931,  2733,    72,
     259,   260,   261,   262,   263,  2034,  2053,   810, -1790,  2899,
     141,   810,   392,  1520,  2242,   810,  2374,  1579,  1286,  2239,
     782,  1727,  1336,   782,  2983,  2057,  2059,   556,   644,   392,
    1954,  1789,  2226,  1335,  2634,  1803,   103,   104,  2934,   259,
     260,   261,   262,   263,   105,  2765,  2301,  1149,  2485,  2398,
    1181,  1182,  1152,     3,     4,  3076,     5,     6,  1263,   303,
    2982,     7,    61,  1012,   408,  1187,  1146,   408,    69,  3014,
    2135,  1526,  2784,  3015,  1900,   408,  2370,  2189,     8,     9,
    2031,   413,   777,   636,   646,  1901,   304,  1371,   653,   651,
    1904,   330,    56,   330,  1251,   786,    10,    11,  1337,  1227,
    1363,  1905,   805,    63,  3010,  1007,   259,   260,   261,   262,
     263,   811,  1013,  1551,   931,   985,   986,  1188,  2398,  2424,
     408,  2785,   654,  2900,  1153,   680,  1955,   683,  1372,    61,
     689,   694,  1118,   696,   678,   931,   699,  2443,  1635,  2443,
    2424,  2483,   931,   987,   988,   989,  3013,   705,  1085,  1086,
    2556,  1583,  3043,  3011,   767,   913,  1338,    33,   916,   133,
     134,  2578,  2396,  2631,  2665,  2633,   705,  2645,  1495,  2743,
     923,  2635,  1336,  2636,  2761,  2876,   767,   813,  2891,   705,
    2915,  2915,  1264,  2743,   932,  3005,  3027,  3045,  3067,   800,
    2985,  3048,  2985,   814,  1264,    33,    34,  2499,  2054,  1087,
    1088,  1089,  1090,  1091,  1092,   816,   818,  1178,  1992,   133,
     134,  1995,   689,  1231,  1185,  1093,  1094,  1095,  1339,  1728,
     767,  1295,   816,   816,  1861,   187, -1790,   855,  1147,   933,
     767,   767,  1548,   893,   767,  1934,    77,  3077,   767,  1862,
     767,  1292,  1861,   384,   767,   767,  1861,   910,  1337,   910,
     816,  2898,   910,   816,  2513,   910,  1209,  1862,  1212,  1393,
   -1790,  1862,  1194,  2237,  1521,  2970,  1387,   402,   855,  1602,
    1390,  1391,  1392,   924,  2512,    82,   267,  2806,  2697,   341,
     874,  1368,  1370,   814,  1622,  1217,  2136,   380,   667,  1410,
    1165,   934,  2986,    34,  1252,   728,  1609,  1610,   106,  2756,
     692,  1002,  2824,  1888,  1552,  1620,  1198,   863,  2375,  1279,
    2402,  1702,   382,  2814,  2863,  2561,  1760,   933,  2348,  1762,
     732,  1551,  2369,  3004,   107,   274,  1950,  1253,  2570,   279,
    2805,   390,  2805,  2894,   791,   399,  1985,  2810,  2038,  1943,
    1457,  2637,   401,  1166,   405,  1015,   973,  1330,  1660,  1722,
    1827,  2108,  1471,  1805,  2010,   959,  1096,  1326,  2204,  1097,
    2026,    82, -1790,  2477,   899,    82,    82,  1472,  1339,  3039,
    2035,  3040,  1327,    82,  1492,    82,    82,    82,   272,  2675,
    2626,  1849,  1493,   980,  1215,   408,   815,    82,  1779,    82,
    2058,  2060,   337,  1518,  1199,   108,   689,  2227,    82,   272,
    1452,    82,  1477,   272,   741,  2728,   272,    82,   934,  1201,
    2547,  1018,   688,   272,  2399,    82,  2835,  2812,   692,    82,
    1732,   767,   767,    82,  1458,  2039,    82,   272,  2430,   934,
     863,   825,   863,  1523,  2567,  2247,   934,   767,   272,  1129,
    2859,   688,  2040,   767,   767,   272,  1537,    82,   767,   272,
    2069,    82,  1376,  2400,  2488,  2419,  2687,  2704,   767,  1536,
    2420,  2709,  2496,   688,  1539,  2236,    82,   272,  2649,    82,
    2651,   272,    82, -1790, -1790, -1790, -1790, -1790,  1098,  1888,
    1570,  1571,  1140,  2401,  2425,  2041,  2702,  1018,   109,   935,
     936,   937,  1531,  1099,  2849,  2404,   746,  1100,  2879,  2880,
     938, -1790,  2444,  2069,  2445,  2448,  2484,  1556,   748,   749,
    2681,  1971,  1552,   990,  2465,  2557,  2377,   751,  2378,  2379,
    2380,  2381,  2382,  2383,  2042,  1369,  2579,  2624,  2925,  2666,
    2927,   767,   767,  1229,  2744,  1101,  1459,  1460,  1461,  2762,
    2877,  1616,  2889,  2892,  1996,  2916,  2917,  2889,  2972,  2309,
    3006,  3028,  3046,  2043,  1623,  3047,  1483,  3073,  2318,    72,
     133,   134,  2044,  1102,  2351,  1624,   767,  3033,  1579,   110,
   -1790,  2753,   767,   709,   709,  2966,  2551,   111,  1399, -1790,
    1579,  1703,  1103,  1400,   767,  1402,   647,  1625,  2734,   767,
    1346,  2515, -1790,  1519,  1626,  1225,   914,  2558,  1332,   917,
     991,  1334,   920,  1347,    81,  2562,  -610,    17,  2884,   648,
    1132,  2664,  2118,  1242,  2668,  2805,  1017,  1133,   874,  2810,
    2460,     3,     4,  1953,     5,     6,  1623,   767,  2757,     7,
      17,  1560,   134,  2478,   647,  1544,  2081,  1624,  2082,  2393,
    1846,   767,  1346,   992,   139,  1559,     8,     9,    79,  1454,
    2774,  1454,  2875,  1713,    95,  1347,   961,   648,  1617,  1625,
    2889,   954,   955,  1104,    10,    11,  1626,   709,    76,    42,
    1576,  1475,   130,  1577,  1346,  1578,  2466,   925,  3035,   132,
    3037,     3,     4,   139,     5,     6,   948,  1347, -1790,     7,
    2144,  2405, -1790,  2682,  1343,  1579,   136,   949,  1351,  1360,
    1351,  1643,  1583,  2683,  -610,  1580,     8,     9,  2516,  3053,
   -1790, -1790,  1759,   689,  1583,  1761,   689,  1804,  1375,  1378,
    2976,  2689,   696,  2690,    10,    11, -1790, -1790, -1790,   141,
    1105, -1790, -1790,  1397,  1398,    12,   816,   767,  2384,   143,
     816,   816,   816,   816,  2837,   767,  2838,  1581,   767,   950,
    1831,  1582,   145,  2366,  2553,  2554,  2998,  2209,   193,   816,
    2889,   767,  1782,   195,   951,   767,  1783,  1618,  1782,   198,
    1383,   194,  1783,   767,   233,   767,   767,  2789,   767,   767,
     767,   767,   767,   767,   767,   767,   767,   767,   767,   767,
     767,   767,   767,   767,   767,    12,  2132,  1363,   234,  2724,
    2418, -1563,  1023,  1024,  1025,   767,   767,  1932,   249,  2864,
     767,  2866,   767,   250,  1891,  1893,  1911,  2517,   241,  3044,
   -1790,  1349,  2914,   252,  2889,  1399,   253,  1348,   254,  1583,
    1400,  1401,  1402,  2882,   689,   257,   925,  1350,  -265,  2241,
     767,   767,   767,  1630,  1631,  1644,  1499,    43,   265,  2790,
     285,   816,  1608,  1474,   952,  1478,   816,  2385,  1612,  1362,
     767,    44,   286,  2299,  1645,  1646,  3058,   288,  1773,  1784,
     289, -1790,  1785,  1349,  1576,  1784,   290,  1577,  1785,  1578,
     294,  1584,   297,  1117,  1647,  2408,    45,  2410,  2411,  1350,
   -1790, -1790,  1798,   295,  1579,  2426,  1461,   767,   301,  1579,
    1579,  2977,   324,   816,   898,  1349,  2939,   306,   902,  1580,
   -1790,  1819,   906,   315,  2065,  2791,   325,  2792,  1638,  1639,
     331,  1350,   767,  1579,   336,  -265,  1194,  1534,  1908,   816,
     816,   334,  2793,   335,   816,    46,    15,  2085,  1543,   767,
    2794,  1651,  -265,     1,  2795,  2229,  1017,  2935,  2088,   767,
    1657,  1581,  1838,  2091,   340,  1582,   342,  2095,  2989,  2097,
    2098,  2099,   353,   910,   816,   816,  1794,   343,     2,  2796,
     682,  2802,   682,   682,  1643,  3014,  2109,   347,  2110,  3015,
     775,  2070,  1795,  1796,   348,  -265,   682,  2121,  2302,  1604,
     935,   936,  1018,  1018,   784,  3008,    15,  1613,   789,  1613,
     351,  1018,   354,   352,   682,   973,   357,   682,   358, -1790,
     803,  2294,  1700,   682,   368,     3,     4,   682,     5,     6,
     369,   682,   388,     7,  -265,   682,   372,     1,  1583,   682,
     682,   377,   682,  1583,  1583,   682,   387,   682,   682,   682,
       8,     9,  2386,   391,  1018,   682,   395,   396,   682, -1790,
     397,   403,   925,  -265,   406,   682,  1351,  1583,    10,    11,
     682,  -951,  -265,   414,  1585,   652,   657,  1360,   682,   659,
    1351,  1179,  1180,   660,  1281,  1183,  1184,   661,   666,   682,
     825,  2939,   668,   682,  2508,  1584,   670,   682,   671,  1709,
    1710,  1711,   682,  2546,  2194,   682,   672,   767,  2959,     3,
       4,   863,     5,     6,  2881,  1500,   674,     7,   675,  2066,
     676,  1501,  1502,  1503,   677, -1790,   679, -1790,  1644,    82,
   -1302,   814,  2174,   963,     8,     9,   767,   767,   767,    12,
     767,  1504, -1790,  1204,  1205,  1206,  1207,  1645,  1646,   964,
   -1790,   965,    10,    11, -1790,  2195,  2196,  2197,  2198,  2199,
    2200,   966,   967,   968,   969, -1790,   767,  1647,  1764,   970,
     971,  2670,  2672,    48,    49,    50,    51,    52,    53, -1790,
      54,    82,   767,  2111,  2112,  1461,  2115,  1282,  2195,  2196,
    2197,  2198,  2199,  2200,   972,  1283,  3019,   976,   977,   978,
    1792,  1284,  1005,  1285,   979,   983,   767,  2138,  1799,  1800,
     767,   816,   307,   687,  1286,  2959,  1007,  1008,  1010,  1011,
    1748,  1071,  1072,  1073,  1074,  1075,  1076,  1077,  1078,  1079,
    1080,  1081,  1082,  1083,  1084,  1085,  1086,  1017,  1020,  1028,
     767,  1016,  1287,   316,  1029,   767,  1031,  1032,  1033,  1505,
    1034,   767,  1506,  1035,  1042,  1036,  1829,  2083,  1288,    13,
     767,  1037,  1038,  1289,  2169,  1039,   767,  2191,  2192,  2193,
    2194,  3019,  1040,  1051,   767,  1290,  1507,  1131,  1585,  3036,
    1052,  1242,  1291,  1875,  2421,  1053,  1087,  1088,  1089,  1090,
    1091,  1092,  1056,  1057,   816,   816,  1508,  1060,  1062,   308,
   -1790,   925,  1093,  1094,  1095,  1063,  1064,  1119,    14,  1065,
     816,  1066,  1067,  1068, -1790,  1070,   309, -1790,  1130, -1790,
    1126,  2195,  2196,  2197,  2198,  2199,  2200,  1134,  2449,  1018,
     317,  1509,   259,   260,   261,   262,   263,  1875,  1135, -1790,
      15,  1043,  1137,    13,  1138,  1142,  2783,   318,  1979, -1790,
    1510,  1511,  1143,  1145,   709,  1157,  1148, -1790,  1044,   310,
    1162,  1991,  1991,  2718,  1176,  1991,  1512,  1186, -1790,  1189,
    1218,  1210,  1219,  2717,  1220, -1790,  1221,  1222,  2296, -1790,
    2297,  1875,  1223,  2027,  2027,  2790,  1226,  2027,  1875,   682,
     319, -1790,    14,  1228,  1230, -1790,  1239,  1231,   311,  1241,
    1255,  1045,   925, -1790,  1254,  1513,  1195,  1256,  1257, -1790,
    1262,  1266,  1269, -1790,  2061,  1270,  1271,  1272,  1317,  1375,
    1325,  1328,  1342,   767,  1345,  1359,  1365,   312,  1366,   320,
    1351,  1374,  1381,   825,  1383,  1384,   313,  1292,  1514,   863,
    1046,  1875,  1382,  1096,  1293,  1385,  1097,  1394,  1408,  1411,
    1409,  2791,  2679,  2792,  1416,  1444,  1447,  1451,   321,  2538,
    1450,  2540,  1464,   863,  1470,  1201,  1294,   322,  2793,  1047,
    1484,  1295,  1486, -1790,  1482,  1497,  2794,   767,  1048,   767,
    2795,  1498, -1790,  1351,  1522, -1790,  1963,   767,   767,   767,
     767, -1790,  2027,  1524,  1525,  1964,  1527,  1529,  2123,  1792,
    2193,  2194,  2128,  2128,  2531,  2796,  2722, -1790,  1535,  1563,
    1538,   767,   682,   682,   682,  1548,  1540,  1555,  1557,  1965,
    1565,  2140,  1966,  1264,  1592, -1790,  1488,  1594,  2451,  1595,
    1597,  2456,  1603,  1087,  1088,  1089,  1090,  1091,  1092,  1652,
    1967,  1663,  1665,  1666,  1669,  1670,  1698,  1701,  1704,  1093,
    1094,  1095,  2195,  2196,  2197,  2198,  2199,  2200,  1696,  1705,
    1714,  1719,  1720,  1721,  1724,  1098,  1726,  1733,   767,  1735,
    2172,  1744,  1745,  2840,  1747,  1084,  1085,  1086,  1750,  1768,
    1099,  2848,  1875,  1769,  1100,  1766,  1770,  1771,   855,  1772,
    2146,  1071,  1072,  1073,  1074,  1075,  1076,  1077,  1078,  1079,
    1080,  1081,  1082,  1083,  1084,  1085,  1086,  1775,  2210,  1774,
    2592,  2593,  2594,  1778,  2596,  2597,  2598,  2599,  2600,  2601,
    2511,  1776,  1101,  2604,   686,  1777,  1780,  1087,  1088,  1089,
    1090,  1091,  1092,  1781,  1793,  1263,  1806,   704,  1808,  1809,
    1810, -1790,  2671,  1093,  1094,  1095,  1968, -1790,  1817,  1824,
    1102,  1018,  1814,  1825,  1826,  1830,  1087,  1088,  1089,  1090,
    1091,  1092,  1833,  1836,   778,  2027,  1850,  1842,  1875,  1103,
    2698,   644,  1093,  1094,  1095,  2245,  1613,   644,   882,  1736,
     795,   796,   767,  1854,   767,  1852,   802,  1888,   938,   804,
    1096,  1930,  2027,  1097,  1018,  1890,  1931,  2679,  1933,  1969,
    1941,  1292,  1947,  1991,  1876,  2711,  1970,  1957, -1790,  1977,
    1958,  1974,  2713,  1976,  1978,  1988,  1999,   883,  2000,  2038,
    2001,  2005,   825,   825,  2062,  2008,  2027,   646,  2958,  2047,
    1875,  2048,  1875,   646,  2377,  2855,  2378,  2379,  2380,  2381,
    2382,  2383,  2191,  2192,  2193,  2194,  2049,  2050,  2051,  2052,
    1104,  2064,  1351,  2067,  2073,  2078,  2079,  2086,  1876,  2087,
    2106,  2117,  2090,  2080,  2122,  2139,  1737,   884,  2102,  2147,
    2104,  2137,  2150,  2151,  2153,  1360,  2154,  1351,  2152,  2155,
   -1790,  2170,  2171,  1738,  1096,  1709,  2190,  1097,   767,  2182,
    2183,   767,  2185,  2988,  2186,  2202,  2195,  2196,  2197,  2198,
    2199,  2200,  1876,   937,    89,   885,  2039,  1562,  2208,  1876,
    2211,  2187,  1098,  1096,  2188,  2213,  1097,  1105,  2220,  2222,
    2228,  2232,  2233,  2040,   828,  2240,  1739,  1099,  2243,  2248,
    2295,  1100,   767,   829,  2304,   767,  2305,  2306,  2307,  2312,
    2458,  2367,   830,  2376,  2395,  2396,  2679,   831,  2679,  2403,
    2406,  2409,  3042,  1792,  2412,  2473, -1736,  2475,  2422,  2427,
    2428,  2433,  1876,  2434,   767,  1740,  2041,   767,  2435,  1101,
    2437,  2492,  2436,  2439,  2438,   767,  2440,  2441,   182,   190,
    3020,  3021,  3022,  3023,  3024,  3025,  2442,  2446,  2712,  2447,
    2450,   832,   767,  2453,  1741,  2457,  2452,  1102,  2459,   833,
    2027,  2463,   886,  1742,  2467,  2042,  1098,  1875,  1875,  1875,
    1875,  1875,  1875,  2472,  2471,  2474,  1103,  2842,  2729, -1790,
     689,  1099,  2487,  2495,  2506,  1100,  2504,  2519,  2510,   816,
    2534,   816,   190,  2548,  2043,  1098,  2549,  2374,   190,  2567,
    2565,  2537,  2839,  2044,  2558,  2576,  2745, -1790,  2590,  2580,
    1099,  2595,  2591,  2602,  1100,   834,  2384,  2603,  2609,  2610,
    2613,  2027,  2614,  1101,  2615,  2616,  1875,  2617,  2618,  2619,
     726,  2630,  2647,  2369,  2632,  2660,  1336,  2650,   887,  2662,
     835,  2667,   727,  2673,  2652,  2669,  1950,   836,  2782,   837,
    1086,  1102,  1101,  2688,  2176,  2178,  2691,  1104,  1881,   838,
    2706,  2694,  2699,  1876,  2700,  2701,  2702,  2707,  2714,   190,
    1103,   190,  2715,  2027,  2719,  2716,  2726,  2723,  2735,   888,
    1102,  2736,  2581,  2582,  1979,   839, -1790,  2679,   932,  2749,
    2585,     1,  2759,   840,  2731,  2767,  2771,  2772,  2775,  1103,
    1087,  1088,  1089,  1090,  1091,  1092,  2779,  2780,   682,  2787,
    2815,  2817,  1961,  2818,  2820,  2821,  1093,  1094,  1095,  2822,
    2826,  2943,  2823,  1323,  1105,  -610,  2829,  2841,  2834,  2851,
     841,  2653,  2845,  2836,  2847,  2385,  2856,  2857,  2865, -1790,
    2874,  2191,  2192,  2193,  2194,   190,  2883,   889,  2654,  1876,
    2912,  1104,  1875,  3079,  1875,  2511,   842,  2430,  2913,  2919,
    2921,  2393,  2923,     3,     4,  1875,     5,     6,  2924,  2931,
    1875,     7,  2944,  2843,  2027,  2969,  2027,  2956,  2957,  2985,
    1104,  2965,  2987,  3003,  3007,  2971,   743,  3009,     8,     9,
    3026,  2655,  2388,  3030,   843,  2195,  2196,  2197,  2198,  2199,
    2200,  3038,  1351,  3049,  3052,   844,    10,    11,  1018,  3062,
     890,  1876,  3072,  1876,  3074,  2423,  1961,  3061,  1105,  2491,
    2162,   767,   682,  1547,  2429,  1841,    70,    71,   557,  2124,
    2656,  2470,  2133,   349,   197,   702,  2191,  2192,  2193,  2194,
     202,  2128,   281,   682,  2708,  2128,   345,  1105,   669,   816,
    1654,   350,   767,  1876,   745,   407,   816,  1096,  1655,  2657,
    1097,   283,  2089,   747,   376,  2692,   656,   374,  2658,   780,
     662,  3059,   767,   663,  2103,   785,  1321,   787,  1816,   892,
    1729,   794,   767,  1989,   794,    82,  1997,   794,  1801,  2113,
    2195,  2196,  2197,  2198,  2199,  2200,  1875,   806,  1875,  1875,
    1875,  1875,  1367,  2748,   845,   846,   847,  1569,  2536,  1573,
     767,  2207,  1887,  3065,  2120,  1909,   853,   848,  2542,  1479,
    2386,  2544,   139,  2850,   866,   869,   872,  2750,    65,  1875,
     894,  1671,   156,    66,  2027,  2800,    67,  1848,   904,   801,
     962,  1851,  1561,  2245,   339,   982,  1591,  2853,  2027,  1853,
    1260,  2788,  2903,   927,  1466,  3034,  2027,  2181,  1604,  1517,
    1944,  2526,  1213,  1456,  2623,  2911,  2389,  1530,  2191,  2192,
    2193,  2194,  2622,  1417,  2605,  2364,  1697,  1380,  2107,  1098,
    1664,  2896,  2234,  2191,  2192,  2193,  2194,  2390,  1876,  1876,
    1876,  1876,  1876,  1876,  1099,  2352,  3066,  3055,  1100,  2303,
    2990,  2648,  2365,  2036,  2825,  2680,  2627,  2373,   689,  2628,
     689,  2807,  2353,  2354,  1875,  2999,  1875,  1607,  1050,  2922,
    2355,   849,  2195,  2196,  2197,  2198,  2199,  2200,  2816,  1310,
    3029,  2387,  2583,  1912,  2940,  2686,  1101,  2195,  2196,  2197,
    2198,  2199,  2200,   863,  2941,  2878,  3054,  1876,  2868,  2566,
    3002,  1599,  2564,  1018,  2356,  2975,  2063,  2827,  2764,  2832,
    1277,     0,  1473,  2357,  1102,   415,     0,     0,     0,     0,
       0,     0,   816,     0,     0,     0,     0,   767,  1633,  1634,
       0,     0,     0,  1103,     0,  1650,     0,     0,     0,     0,
       0,  2184,  2358,     0,  2867,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  2371,     0,     0,     0,     0,
       0,     0,   927,     0,     0,     0,  1875,     0,     0,     0,
       0,  1875,   709,   709,   709,     0,   709,   709,   709,   709,
     709,   709,  1026,  1027,     0,   709,  3071,  2359,     0,  2027,
       0,     0,     0,     0,     0,  1875,     0,     0,  1041,  2027,
    1875,     0,     0,     0,  1054,  1055,  2230,  2902,     0,  1059,
       0,     0,     0,     0,  1104,   682,     0,  1672,     0,  1069,
       0,   682,     0,  1876,     0,  1876,     0,     0,     0,  2360,
    1875,  1120,     0,     0,     0,     0,  1876,     0,     0,  2869,
       0,  1876,     0,     0,     0,   682,     0,     0,     0,     0,
       0,     0,  1018,     0,  1018,     0,     0,  1875,     0,     0,
       0,     0,  2027,     0,  2832,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1151,  1673,     0,     0,     0,     0,
       0,  1105,     0,     0,     0,     0,     0,  1674,  1168,  1168,
    1168,     0,  1168,     0,  1168,  1168,     0,  1675,     0,     0,
      89,    89,  2397,     0,  2750,     0,     0,     0,     0,  1875,
       0,  1875,     0,  1875,     0,  1676,     0,  1913,     0,  2027,
       0,     0,  1875,     0,     0,  1677,     0,  1604,  1678,     0,
    1914,     0,  2524,  1881,  2527,  2528,  2529,  2530,     0,   925,
       0,  1679,     0,   689,   872,  1822,  1875,     0,     0,     0,
       0,     0,     0,     0,     0,  1237,     0,     0,     0,  1875,
    2191,  2192,  2193,  2194,     0,     0,     0,  1876,     0,  1876,
    1876,  1876,  1876,     0,     0,     0,     0,     0,   927,  1120,
       0,  1885,     0,     0,   767,  3031,  2870,  1267,     0,     0,
    1680,  1961,   767,     0,  1915,     0,     0,     0,     0,     0,
    1876,  1916,     0,  1275,  1275,     0,     0,     0,     0,     0,
       0,     0,     0,  1875,  2195,  2196,  2197,  2198,  2199,  2200,
    1681,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1682,     0,     0,  1018,     0,  1875,     0,  2027,     0,     0,
    1917,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1683,     0,     0,  1684,     0,  1685,     0,     0,     0,     0,
       0,     0,   190,     0,     0,  1918,     0,     0,     0,     0,
       0,     0,     0,  1875,     0,  1919,  1920,  1875,     0,  1876,
       0,  1876,     0,  1686,     0,  1876,  1876,  1876,     0,     0,
     767,  1921,  1687,     0,     0,     0,     0,     0,  1388,     0,
       0,     0,     0,     0,   682,   682,  1396,     0,     0,  1407,
       0,     0,  1922,     0,     0,  1923,  1924,     0,     0,     0,
       0,  1925,  1412,     0,     0,     0,  1415,     0,     0,     0,
    2629,     0,     0,     0,  1421,  2646,  1423,  1424,     0,  1425,
    1426,  1427,  1428,  1429,  1430,  1431,  1432,  1433,  1434,  1435,
    1436,  1437,  1438,  1439,  1440,  1441,  2191,  2192,  2193,  2194,
       0,     0,     0,     0,     0,     0,  1442,  1443,   925,     0,
       0,  1445,     0,  1446,  1449,     0,     0,     0,  1926,     0,
       0,     0,    89,     0,    89,   872,   794,  1876,     0,     0,
    1927,     0,  1876,  1465,   806,     0,     0,   872,     0,     0,
       0,   190,     0,     0,  1480,     0,     0,     0,     0,     0,
    2195,  2196,  2197,  2198,  2199,  2200,  1876,   927,     0,     0,
       0,  1876,  1071,  1072,  1073,  1074,  1075,  1076,  1077,  1078,
    1079,  1080,  1081,  1082,  1083,  1084,  1085,  1086,     0,     0,
       0,  2625,     0,    89,     0,     0,     0,  2158,  2159,     0,
       0,  1876,     0,     0,     0,     0,     0,     0,  2168,     0,
       0,  2737,     0,  2739,  2740,  2741,  2742,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1876,     0,
       0,     0,     0,  1541,     0,     0,     0,  1087,  1088,  1089,
    1090,  1091,  1092,     0,  1961,     0,     0,     0,     0,     0,
       0,     0,     0,  1093,  1094,  1095,  1567,     0,  2215,  2216,
    2217,  2218,     0,  2871,     0,     0,     0,  1590,   927,     0,
       0,     0,     0,  2224,     0,   385,     0,     0,  2918,     0,
    1876,     0,  1876,     0,  1876,     0,     0,     0,  2191,  2192,
    2193,  2194,     0,  1876,     0,     0,  2377,     0,  2378,  2379,
    2380,  2381,  2382,  2383,  2191,  2192,  2193,  2194,     0,     0,
       0,     0,     0,     0,  1876,     0,     0,  1876,  1876,     0,
       0,     0,  1637,     0,     0,     0,     0,     0,     0,  2808,
    1876,  2181,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  2738,  2195,  2196,  2197,  2198,  2199,  2200,     0,  2310,
    2311,     0,     0,     0,     0,     0,  2315,  2316,  2195,  2196,
    2197,  2198,  2199,  2200,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   872,     0,     0,     0,
    2758,     0,     0,     0,  1876,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1096,     0,     0,  1097,     0,     0,
       0,     0,     0,     0,     0,     0,  1876,     0,  1718,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  2524,     0,     0,     0,     0,  2873,  1751,  1752,  1753,
       0,  1755,     0,     0,  1876,     0,     0,     0,  1876,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  2872,
    2890,     0,     0,     0,     0,  2890,     0,  1718,     0,     0,
       0,     0,     0,     0,     0,     0,   925,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  2461,  2462,
       0,     0,     0,     0,     0,  1961,     0,  2469,     0,     0,
       0,     0,     0,     0,     0,  2482,     0,     0,     0,   158,
       0,     0,     0,     0,     0,     0,  1098,     0,  2384,     0,
       0,     0,  2930,  2497,  2498,  1813,     0,     0,     0,     0,
       0,  1099,     0,     0,  1821,  1100,  1413, -1791,     0,     0,
       0,     0,     0,     0,     0,   872,  1818,     0,   159,     0,
       0,     0,  1718,     0,     0,     0, -1791,     0,     0,     0,
       0,  1718,     0,     0,     0,   182,     0,   160,     0,     0,
       0,     0,     0,  1101,  1961,  2539,  2981,  2541,  2984,     0,
       0,     0,     0,     0,  2543, -1791,  2545,  1073,  1074,  1075,
    1076,  1077,  1078,  1079,  1080,  1081,  1082,  1083,  1084,  1085,
    1086,  1102,   872,     0,   872,     0,   161,     0,   866,     0,
       0,  3000,     0,     0,     0,     0,     0,     0,   162,     0,
    1103,     0,     0,     0,     0,     0,     0, -1791,   163,     0,
       0,     0,     0,     0,     0,     0,     0,  2385,     0,     0,
    1983,     0,     0,     0,     0,     0,   164,     0,     0,     0,
    1087,  1088,  1089,  1090,  1091,  1092,   165, -1791,     0,     0,
       0, -1791,     0,     0,     0,     0,  1093,  1094,  1095,     0,
       0,     0,   166,     0,     0,     0,  2586,  2587,  2890,     0,
    2588,  2589,     0,     0,     0, -1791,     0,     0,     0,     0,
       0,     0,     0, -1791,  2388, -1791,     0,     0,     0,     0,
    2930,  1104,     0,     0, -1791,     0,     0,     0,     0,   872,
   -1791,     0,   167,     0,  2612,   682,     0,     0, -1791,     0,
       0,     0, -1791,     0,     0,     0,     0,     0, -1791,     0,
       0,     0, -1791, -1791, -1791, -1791,   168,     0,  2981,     0,
       0,     0,  2890,     0,     0,     0,     0, -1791,     0,     0,
       0,   169,     0,     0,     0,     0,     0,     0,   170,     0,
       0,   171,     0,     0, -1791,     0,     0, -1791,  1105, -1791,
       0,   872,     0,   872,     0,     0, -1791,     0,  2100,     0,
    2100,   172,   872,     0,   173,     0,   174,     0,     0, -1791,
       0,     0,     0,     0,     0,     0,     0,     0,     0, -1791,
       0,     0,     0,     0,     0,   175,     0,  1096,     0,     0,
    1097,     0,     0,     0,     0,     0,     0,     0, -1791, -1791,
    2145,     0,  2386,   176,     0,     0,     0,  2705,     0,     0,
       0,  2710,     0, -1791,     0,     0,     0,     0,     0,     0,
       0, -1791,     0,     0,     0, -1791,     0,     0,     0,  2167,
       0,     0,     0,     0, -1791, -1791, -1791,     0,     0,     0,
       0,     0,     0,  2727,     0,     0,     0,     0,  2389,     0,
       0,     0,     0,  1071,  1072,  1073,  1074,  1075,  1076,  1077,
    1078,  1079,  1080,  1081,  1082,  1083,  1084,  1085,  1086,  2390,
       0,     0,     0,     0,     0,     0,  2746,     0,     0,     0,
       0,     0,  1071,  1072,  1073,  1074,  1075,  1076,  1077,  1078,
    1079,  1080,  1081,  1082,  1083,  1084,  1085,  1086,     0,     0,
       0,     0,     0, -1791,     0,     0,     0,     0,     0,  1098,
       0,     0,     0,     0, -1791,     0,     0,     0,  1087,  1088,
    1089,  1090,  1091,  1092,  1099,     0,     0,     0,  1100,     0,
       0,     0,     0,     0,  1093,  1094,  1095,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1087,  1088,  1089,
    1090,  1091,  1092,     0,     0, -1791,     0,     0,     0,     0,
       0,     0,     0,  1093,  1094,  1095,  1101,     0,     0,  2308,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1102,     0,     0,     0,     0,     0,
       0,     0,  2191,  2192,  2193,  2194,     0,     0,     0,     0,
       0,    72,     0,  1103,     0,     0, -1791,  1074,  1075,  1076,
    1077,  1078,  1079,  1080,  1081,  1082,  1083,  1084,  1085,  1086,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   872,
       0,     0, -1791,     0,     0,     0,  2195,  2196,  2197,  2198,
    2199,  2200,  1855,  1856,     0,  1857,     0,     0,   269,  1858,
    1859,     0,  1718,  2862,     0,  1096,     0,     0,  1097,  1087,
    1088,  1089,  1090,  1091,  1092,     0,     0,     0,  1860,     0,
       0,     0,     0,   872,  1104,  1093,  1094,  1095,     0, -1791,
       0,     0,     0,     0,  1096,     0,     0,  1097,     0,     0,
       0,     0,     0, -1791, -1791, -1791, -1791, -1791, -1791, -1791,
       0, -1791, -1791,     0,     0,     0,  2479,     0,     0,     0,
       0,     0,     0,     0,     0,  2489,     0,   702, -1791,  2493,
       0,     0,     0,     0,     0,  2486,     0,     0,  1718,     0,
       0,  2503,     0,     0,   203,     0,  1718,     0,     0,     0,
       0,  1105,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   204,   205,     0,     0,     0,     0,     0,     0,
       0,   206,     0,     0,     0,     0,     0,  1098,     0,     0,
       0,     0,     0,     0,  2967,     0,     0,     0,     0,     0,
       0,     0,  1099,     0,     0,     0,  1100,  1725,     0,     0,
       0,     0,     0,     0,     0,     0,  1098,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1096,     0,     0,  1097,
       0,  1099,     0,     0,  2250,  1100,  1734,  2991,  2992,     0,
    2994,     0,  2996,  2997,  1101,     0,     0,     0,  1071,  1072,
    1073,  1074,  1075,  1076,  1077,  1078,  1079,  1080,  1081,  1082,
    1083,  1084,  1085,  1086,     0,     0,     0,     0,     0,     0,
       0,     0,  1102,  1101,  2251,  2252,  2253,     0,     0,     0,
       0,     0,  2584,     0,     0,     0,     0,     0,     0,     0,
       0,  1103,     0,     0,     0,     0,     0,     0,     0,  2254,
       0,  1102,     0,     0,     0,     0,  3041,  2255,  2011,     0,
       0,     0,  2256,  1087,  1088,  1089,  1090,  1091,  1092,     0,
    1103,     0,  2606,     0,     0,     0,  3050,  2257,  3051,  1093,
    1094,  1095,  2258,     0,  2259,  2621,     0,     0,     0,     0,
       0,  2260,     0,     0,  2261,     0,     0,  2262,  1098,     0,
    2263,     0,   207,  2264,     0,     0,     0,     0,  2265,     0,
       0,     0,     0,  1099,     0,  3063,     0,  1100,     0,     0,
       0,     0,  1104,     0,     0,     0,  2266,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  3068,
    3069,   208,  2267,  3070,     0,  2268,  2269,   872,     0,     0,
       0,  1104,  2270,     0,     0,  1101,     0,     0,     0,  1861,
     209,     0,     0,  2271,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1862,   872,   210,     0,     0,  2272,
       0,     0,  2693,  1102,     0,     0,  2273,     0,     0,  1105,
     190,  1863,     0,  2274,  2012,     0,  2275,  2276,  2277,   211,
    2278,  2279,  1103,     0,     0,     0,  2013,  1865,     0,     0,
       0,   212,     0,     0,     0,   927,     0,  2280,  1105,     0,
    1096,   213,     0,  1097,     0,     0,     0,     0,     0,     0,
       0,   190,     0,  1718,     0,  2369,     0,     0,     0,   214,
    2281,  2282,  2283,  2284,     0,  2285,     0,     0,  1867,   215,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1868,     0,  2286,  2287,     0,   216,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1104,     0,  2288,     0,     0,     0,     0,
       0,     0,  2479,     0,  2289,  2290,     0,  2291,     0,     0,
       0,  1869,     0,     0,     0,   217,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   218,
       0,     0,     0,     0,  2606,     0,     0,     0,     0,     0,
    1870,     0,  1098,     0,   219,     0,     0,     0,     0,     0,
    1105,   220,  1871,     0,   221,     0,     0,  1099,     0,  2292,
       0,  1100,  1746,     0,  1872,  1873,  2014,     0,     0,     0,
       0,     0,     0,  1874,   222,     0,   688,   223,     0,   224,
       0,     0,     0,     0,   272,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   225,  1101,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   226,     0,     0,     0,
       0,     0,   872,     0,     0,     0,     0,  1102,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  2852,
    2479,     0,     0,     0,   927,     0,  1103,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   227,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1071,  1072,  1073,  1074,  1075,  1076,  1077,
    1078,  1079,  1080,  1081,  1082,  1083,  1084,  1085,  1086,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  2479,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  2606,     0,     0,     0,     0,  2906,     0,  2908,
       0,     0,     0,     0,     0,     0,     0,  1104,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1087,  1088,
    1089,  1090,  1091,  1092,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1093,  1094,  1095,     0,     0,     0,
     872,     0,     0,     0,     0,     0,   872,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1105,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     1,     0,     0,     0,   417,   418,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   419,     0,
     420,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   421,     0,     0,     0,     0,     0,
       0,   422,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   423,   424,   425,     0,     0,     0,     0,     0,
    1168,  1168,  1168,  1168,  1168,  1168,     0,     0,   426,     0,
     427,   428,   429,     3,     4,   430,     5,     6,   431,     0,
     432,     7,   433,   434,     0,  1096,     0,     0,  1097,   435,
       0,     0,   436,  1718,   437,   438,   439,     0,     8,     9,
       0,     0,     0,     0,   440,     0,   441,   442,     0,   443,
       0,   444,   445,     0,     0,   446,    10,    11,     0,     0,
     447,   448,   449,     0,   450,   451,     0,     0,     0,   452,
     453,     0,   454,     0,     0,     0,   455,     0,   456,   457,
       0,     0,     0,     0,   458,     0,     0,     0,   459,     0,
       0,   460,     0,   461,     0,   462,     0,   463,     0,   464,
     465,     0,   466,   467,   468,     0,     0,     0,   469,     0,
     470,   471,     0,   472,     0,     0,     0,     0,     0,     0,
       0,   473,   474,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   927,     0,   475,     0,     0,   476,   477,     0,
       0,   478,   479,     0,     0,   480,   481,  1098,     0,     0,
       0,     0,     0,     0,   482,   483,   484,     0,   485,     0,
       0,     0,  1099,     0,     0,     0,  1100,  1754,   486,   487,
     488,     0,   489,     0,     0,     0,   490,   491,     0,     0,
       0,   492,     0,     0,     0,     0,     0,     0,     0,   493,
       0,     0,     0,     0,     0,     0,     0,   494,   495,   496,
       0,     0,     0,     0,  1101,   497,   498,     0,     0,     0,
       0,   499,     0,     0,   500,     0,     0,     0,   501,   502,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   503,
       0,     0,  1102,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   504,     0,     0,
       0,  1103,     0,     0,     0,   505,     0,     0,     0,     0,
       0,   506,     0,     0,     0,     0,     0,     0,  1071,  1072,
    1073,  1074,  1075,  1076,  1077,  1078,  1079,  1080,  1081,  1082,
    1083,  1084,  1085,  1086,   107,     0,     0,     0,     0,     0,
       0,   507,     0,   508,   509,     0,     0,     0,     0,     0,
       0,     0,   510,     0,     0,     0,     0,     0,     0,  1071,
    1072,  1073,  1074,  1075,  1076,  1077,  1078,  1079,  1080,  1081,
    1082,  1083,  1084,  1085,  1086,     0,     0,     0,     0,     0,
       0,     0,  1104,  1087,  1088,  1089,  1090,  1091,  1092,     0,
       0,   511,     0,     0,     0,     0,     0,     0,     0,  1093,
    1094,  1095,   512,     0,     0,     0,   513,     0,     0,     0,
     514,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1087,  1088,  1089,  1090,  1091,  1092,
       0,     0,     0,     0,   515,   516,     0,     0,     0,   517,
    1093,  1094,  1095,     0,     0,     0,     0,     0,     0,  1105,
       0,   518,     0,     0,     0,     0,     0,   519,   520,   521,
     522,     0,     0,   523,     0,     0,     0,   524,     0,     0,
       0,     0,     0,     0,   525,   526,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   527,     0,   528,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   529,
       0,   530,     0,     0,   531,     0,     0,     0,     0,     0,
     532,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   533,     0,     0,   534,
    1096,     0,     0,  1097,     0,   535,     0,     0,   536,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   537,     0,     0,     0,     0,     0,     0,
     538,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1096,     0,     0,  1097,     0,     0,     0,     0,     0,
       0,     0,     0,   539,   540,   541,   542,   543,   544,   545,
       0,     0,   546,     0,   547,     0,   548,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1071,  1072,
    1073,  1074,  1075,  1076,  1077,  1078,  1079,  1080,  1081,  1082,
    1083,  1084,  1085,  1086,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1071,  1072,  1073,  1074,  1075,  1076,  1077,
    1078,  1079,  1080,  1081,  1082,  1083,  1084,  1085,  1086,     0,
       0,     0,  1098,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1099,     0,     0,
       0,  1100,  1756,  1087,  1088,  1089,  1090,  1091,  1092,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1093,
    1094,  1095,     0,  1098,     0,     0,     0,     0,  1087,  1088,
    1089,  1090,  1091,  1092,     0,     0,     0,     0,  1099,  1101,
       0,     0,  1100,  1757,  1093,  1094,  1095,     0,  1072,  1073,
    1074,  1075,  1076,  1077,  1078,  1079,  1080,  1081,  1082,  1083,
    1084,  1085,  1086,     0,     0,     0,     0,  1102,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1101,     0,     0,     0,     0,     0,  1103,  1075,  1076,  1077,
    1078,  1079,  1080,  1081,  1082,  1083,  1084,  1085,  1086,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1102,     0,
       0,     0,  1087,  1088,  1089,  1090,  1091,  1092,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1103,  1093,  1094,
    1095,     0,     0,     0,     0,     0,  1076,  1077,  1078,  1079,
    1080,  1081,  1082,  1083,  1084,  1085,  1086,     0,  1087,  1088,
    1089,  1090,  1091,  1092,     0,     0,     0,     0,     0,     0,
    1096,     0,     0,  1097,  1093,  1094,  1095,  1104,  1077,  1078,
    1079,  1080,  1081,  1082,  1083,  1084,  1085,  1086,     0,     0,
       0,     0,     0,     0,     0,  1096,     0,     0,  1097,     0,
       0,     0,     0,     0,     0,     0,  1087,  1088,  1089,  1090,
    1091,  1092,     0,     0,     0,     0,     0,     0,  1104,     0,
       0,     0,  1093,  1094,  1095,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1087,  1088,  1089,
    1090,  1091,  1092,     0,  1105,     0,     0,     0,     0,     0,
       0,     0,     0,  1093,  1094,  1095,     0,     0,     0,     0,
       0,     0,     0,  1078,  1079,  1080,  1081,  1082,  1083,  1084,
    1085,  1086,     0,     0,     0,     0,     0,     0,     0,  1096,
       0,     0,  1097,     0,     0,  1105,     0,     0,     0,     0,
       0,     0,  1098,     0,  1079,  1080,  1081,  1082,  1083,  1084,
    1085,  1086,     0,     0,     0,     0,     0,  1099,     0,     0,
       0,  1100,  1758,     0,     0,  1096,     0,  1098,  1097,     0,
       0,  1087,  1088,  1089,  1090,  1091,  1092,     0,     0,     0,
       0,     0,  1099,     0,     0,     0,  1100,  1093,  1094,  1095,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1101,
       0,  1087,  1088,  1089,  1090,  1091,  1092,     0,     0,     0,
       0,     0,     0,  1096,     0,     0,  1097,  1093,  1094,  1095,
       0,     0,     0,     0,  1101,     0,     0,  1102,     0,     0,
       0,     0,     0,     0,  1855,  1856,     0,  1857,     0,     0,
     269,  1858,  1859,     0,  1096,     0,  1103,  1097,     0,     0,
       0,  1098,  1102,     0,     0,     0,     0,     0,     0,     0,
    1860,     0,     0,     0,     0,     0,  1099,     0,     0,     0,
    1100,  1103,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1098,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1099,     0,     0,     0,  1100,     0,  1101,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1104,  1096,     0,
       0,  1097,     0,     0,     0,  1098,  1102,     0,     0,     0,
       0,     0,     0,     0,  1101,     0,     0,     0,     0,     0,
    1099,     0,  1104,     0,  1100,  1103,     0,     0,  1096,     0,
       0,  1097,     0,     0,     0,     0,  1098,     0,     0,     0,
       0,     0,  1102,  1080,  1081,  1082,  1083,  1084,  1085,  1086,
       0,  1099,     0,     0,     0,  1100,     0,     0,     0,     0,
       0,  1103,  1101,     0,  1105,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1081,  1082,  1083,  1084,  1085,  1086,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1105,
    1102,     0,     0,  1101,     0,     0,     0,     0,     0,  1087,
    1088,  1089,  1090,  1091,  1092,     0,  1104,     0,     0,  1103,
       0,     0,     0,     0,     0,  1093,  1094,  1095,     0,     0,
    1098,  1102,     0,     0,     0,     0,     0,     0,     0,  1087,
    1088,  1089,  1090,  1091,  1092,  1099,     0,     0,     0,  1100,
    1103,     0,  1104,     0,     0,  1093,  1094,  1095,     0,     0,
    1098,     0,     0,     0,     0,     0,     0,  1082,  1083,  1084,
    1085,  1086,     0,     0,     0,  1099,     0,     0,     0,  1100,
       0,     0,     0,  1105,     0,   713,   714,  1101,     0,     0,
       0,   269,   715,   716,  -610,     0,     0,     0,     0,     0,
    1104,     0,     0,     0,     0,     0,   717,     0,     0,     0,
       0,   718,   719,     0,     0,  1102,     0,  1101,   720,  1105,
       0,  1087,  1088,  1089,  1090,  1091,  1092,     0,     0,     0,
       0,  1104,     0,     0,  1103,     0,     0,  1093,  1094,  1095,
       0,     0,     0,     0,     0,  1102,   721,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1103,     0,  1096,  1105,     0,  1097,
       0,  1861,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1862,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1096,     0,  1105,  1097,
       0,     0,     0,  1863,     0,     0,  2638,     0,     0,     0,
       0,     0,     0,     0,     0,  1104,     0,     0,     0,  1865,
       0,     0,     0,     0,     0,   713,   714,     0,     0,     0,
       0,   269,   715,   716,  -610,     0,     0,     0,     0,   722,
       0,     0,     0,     0,     0,  1104,   717,  2369,     0,     0,
       0,   718,   719,     0,     0,     0,     0,     0,   720,  2886,
    1867,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1868,     0,     0,     0,     0,     0,  1096,     0,
       0,  1097,  1105,     0,     0,     0,   721,     0,  1098,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1099,     0,     0,     0,  1100,     0,     0,
       0,     0,  1105,  1869,     0,     0,     0,     0,  1098,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   158,     0,  1099,     0,     0,   723,  1100,     0,     0,
       0,   724,     0,     0,     0,  1101,     0,     0,     0,     0,
       0,     0,  1870,     0,     0,     0,     0,     0,     0,     0,
     713,   714,     0,     0,  1871,     0,   269,   715,   716,   725,
     159,     0,     0,  1102,     0,  1101,  1872,  1873,     0,   722,
       0,   717,     0,     0,     0,  1874,   718,   719,   688,   160,
       0,     0,  1103,   720,     0,     0,   272,     0,     0,     0,
    1098,     0,     0,  1102,   726,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1099,   727,     0,     0,  1100,
       0,   721,  1103,     0,     0,     0,     0,     0,   161,     0,
       0,     0,     0,     0,   728,     0,     0,     0,     0,   729,
     162,     0,   730,     0,     0,     0,     0,     0,     0,     0,
     163,     0,     0,   731,     0,     0,     0,  1101,     0,   732,
       0,     0,     0,     0,     0,     0,     0,     0,   164,   733,
       0,     0,     0,  1104,   734,     0,   723,   735,   165,     0,
     736,   724,     0,     0,     0,  1102,     0,     0,     0,   737,
     738,     0,     0,     0,   166,     0,     0,     0,     0,     0,
     713,   714,     0,  1104,  1103,     0,   269,   715,   716,   725,
       0,     0,     0,     0,   722,     0,     0,     0,     0,     0,
       0,   717,     0,     0,     0,     0,   718,   719,     0,     0,
    1191,   739,     0,   720,   167,   740,     0,     0,     0,     0,
    1105,     0,     0,   741,   726,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   742,     0,   727,     0,   168,     0,
     743,   721,     0,     0,     0,     0,     0,     0,     0,     0,
    1105,     0,     0,   169,   728,     0,     0,     0,     0,   729,
     170,     0,   730,   171,   744,  1104,     0,     0,     0,     0,
       0,     0,     0,   731,     0,     0,     0,     0,     0,   732,
       0,     0,     0,   172,     0,     0,   173,     0,   174,   733,
       0,   723,     0,     0,   734,     0,   724,   735,     0,     0,
     736,     0,     0,     0,     0,     0,     0,   175,   745,   737,
     738,     0,     0,     0,     0,   746,     0,   747,     0,     0,
       0,     0,     0,     0,   725,   176,     0,   748,   749,   750,
       0,     0,  1105,     0,   722,     0,   751,     0,     0,    82,
       0,     0,     0,     0,     0,     0,     0,   272,     0,     0,
       0,   739,     0,     0,     0,   740,     0,     0,     0,   726,
       0,     0,     0,   741,     0,     0,     0,     0,     0,     0,
       0,   727,     0,     0,   742,     0,     0,     0,     0,     0,
     743,     0,     0,     0,     0,     0,     0,     0,     0,   728,
       0,     0,     0,     0,   729,     0,     0,   730,     0,     0,
       0,     0,     0,     0,   744,     0,     0,     0,   731,     0,
       0,     0,     0,     0,   732,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   733,     0,     0,     0,     0,   734,
       0,   723,   735,   713,   714,   736,   724,     0,     0,   269,
     715,   716,     0,     0,   737,   738,     0,     0,   745,     0,
       0,     0,     0,     0,   717,   746,     0,   747,     0,   718,
     719,     0,     0,     0,   725,     0,   720,   748,   749,   750,
       0,     0,     0,     0,     0,     0,   751,     0,     0,    82,
       0,     0,     0,     0,     0,  1191,   739,   272,     0,     0,
     740,     0,     0,     0,   721,     0,     0,     0,   741,   726,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   742,
       0,   727,     0,     0,     0,   743,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   728,
       0,     0,     0,     0,   729,     0,     0,   730,     0,   744,
       0,     0,     0,     0,     0,     0,     0,     0,   731,     0,
       0,     0,     0,     0,   732,   713,   714,     0,     0,     0,
       0,   269,   715,   716,   733,     0,     0,     0,     0,   734,
       0,     0,   735,     0,     0,   736,   717,     0,     0,     0,
       0,   718,   719,   745,   737,   738,     0,   722,   720,     0,
     746,     0,   747,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   748,   749,   750,     0,     0,     0,     0,     0,
       0,   751,     0,     0,    82,     0,   721,     0,     0,     0,
       0,     0,   272,     0,     0,     0,   739,     0,     0,     0,
     740,     0,     0,     0,     0,     0,  1855,  1856,   741,  1857,
       0,     0,   269,  1858,  1859,     0,     0,     0,     0,   742,
       0,  2114,     0,     0,     0,   743,     0,     0,     0,     0,
       0,     0,  1860,     0,     0,     0,  1855,  1856,     0,  1857,
       0,     0,   269,  1858,  1859,     0,     0,     0,     0,   744,
       0,     0,     0,     0,   723,     0,     0,     0,     0,   724,
       0,     0,  1860,     0,     0,   713,   714,     0,     0,     0,
       0,   269,   715,   716,     0,     0,     0,     0,     0,   722,
       0,     0,     0,     0,     0,     0,   717,   725,     0,     0,
       0,   718,   719,   745,     0,     0,     0,     0,   720,     0,
     746,     0,   747,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   748,   749,   750,     0,     0,     0,     0,     0,
       0,   751,   726,     0,    82,     0,   721,     0,     0,     0,
       0,     0,   272,     0,   727,     0,  1855,  1856,     0,  1857,
       0,     0,   269,  1858,  1859,     0,     0,     0,     0,     0,
       0,     0,   728,     0,     0,     0,  -852,   729,     0,     0,
     730,     0,  1860,     0,     0,     0,     0,     0,     0,     0,
       0,   731,     0,     0,     0,     0,   723,   732,     0,     0,
       0,   724,     0,     0,     0,     0,     0,   733,     0,     0,
       0,     0,   734,     0,     0,   735,     0,     0,   736,     0,
       0,     0,     0,     0,     0,     0,     0,   737,   738,   725,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   722,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1855,  1856,     0,  1857,     0,     0,   269,  1858,
    1859,     0,     0,     0,   726,     0,     0,     0,     0,   739,
       0,     0,     0,   740,     0,     0,   727,     0,  1860,     0,
       0,   741,  2011,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   742,     0,   728,     0,     0,     0,   743,   729,
       0,     0,   730,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  2011,   731,     0,     0,     0,     0,     0,   732,
    1855,  1856,   744,  1857,     0,     0,   269,  1858,  1859,   733,
       0,     0,     0,     0,   734,     0,   723,   735,     0,     0,
     736,   724,     0,     0,     0,     0,  1860,     0,     0,   737,
     738,  1855,  1856,     0,  1857,     0,     0,   269,  1858,  1859,
       0,     0,     0,     0,     0,     0,   745,     0,     0,   725,
       0,     0,     0,   746,     0,   747,     0,  1860,     0,     0,
       0,     0,     0,  1861,     0,   748,   749,   750,     0,     0,
    2507,   739,     0,     0,   751,   740,     0,    82,  1862,     0,
       0,     0,     0,   741,   726,   272,     0,     0,     0,     0,
       0,     0,     0,  1861,   742,  1863,   727,     0,  2012,     0,
     743,     0,     0,     0,     0,     0,     0,     0,  1862,     0,
    2013,  1865,     0,     0,   728,     0,     0,     0,     0,   729,
       0,     0,   730,     0,   744,  1863,     0,     0,  2012,     0,
       0,     0,     0,   731,     0,     0,     0,     0,     0,   732,
    2013,  1865,     0,     0,     0,     0,     0,     0,     0,   733,
       0,     0,  1867,     0,   734,     0,     0,   735,     0,     0,
     736,     0,     0,     0,  1868,     0,     0,     0,   745,   737,
     738,     0,     0,     0,     0,   746,     0,   747,     0,     0,
       0,     0,  1867,     0,     0,     0,     0,   748,   749,   750,
       0,     0,     0,  1861,  1868,     0,   751,     0,     0,    82,
       0,     0,     0,     0,     0,  1869,     0,   272,  1862,     0,
       0,   739,     0,     0,     0,   740,     0,     0,     0,     0,
       0,     0,     0,   741,     0,  1863,     0,     0,  2638,     0,
       0,     0,     0,     0,   742,  1869,     0,     0,     0,     0,
     743,  1865,     0,     0,  1870,     0,  1855,  1856,     0,  1857,
       0,     0,   269,  1858,  1859,     0,  1871,     0,     0,     0,
       0,     0,     0,     0,   744,     0,     0,     0,  1872,  1873,
    2014,     0,  1860,     0,  1870,     0,     0,  1874,     0,     0,
     688,     0,  1867,     0,     0,     0,  1871,     0,   272,  1861,
       0,     0,     0,     0,  1868,     0,     0,     0,  1872,  1873,
       0,     0,     0,     0,  1862,     0,     0,  1874,   745,     0,
     688,     0,     0,     0,     0,   746,     0,   747,   272,     0,
       0,  1863,     0,     0,  1864,     0,     0,   748,   749,   750,
       0,     0,     0,     0,     0,  1869,   751,  1865,     0,    82,
       0,     0,     0,  1855,  1856,     0,  1857,   272,     0,   269,
    1858,  1859,     0,     0,     0,     0,     0,  1861,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  2639,  1860,
       0,     0,  1862,     0,  1870,     0,     0,  1866,  1867,     0,
       0,     0,     0,  2640,  2641,     0,  1871,     0,  1861,  1863,
    1868,     0,  1864,     0,     0,     0,     0,     0,  1872,  1873,
       0,     0,     0,  1862,     0,  1865,     0,  1874,  1855,  1856,
     688,  1857,     0,     0,   269,  1858,  1859,     0,   272,     0,
    1863,     0,     0,  2885,     0,     0,     0,     0,     0,  1912,
       0,  1869,     0,  2369,  1860,     0,  1865,     0,  2321,  2322,
       0,     0,  2323,  2324,  2325,     0,  1867,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1868,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1870,     0,     0,     0,     0,     0,  2886,  1867,     0,     0,
       0,     0,  1871,     0,     0,     0,     0,     0,     0,  1868,
       0,     0,     0,     0,  1872,  1873,     0,     0,     0,  1869,
       0,     0,     0,  1874,     0,     0,   688,     0,     0,     0,
       0,     0,     0,     0,   272,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1869,     0,     0,     0,  2945,     0,     0,     0,  1870,     0,
       0,     0,  2326,     0,     0,     0,     0,     0,     0,  2327,
    1871,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1872,  1873,     0,     0,     0,     0,     0,  1870,
       0,  1874,     0,     0,   688,     0,     0,     0,     0,     0,
       0,  1871,   272,  2328,     0,     0,     0,     0,     0,     0,
    2946,     0,  2329,  1872,  1873,     0,     0,     0,     0,     0,
       0,     0,  1874,  1861,     0,   688,     0,     0,     0,     0,
       0,     0,     0,   272,     0,  2947,     0,     0,  1862,     0,
       0,  2330,  2331,     0,  2948,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1863,     0,     0,  2638,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1865,     0,     0,     0,     0,     0,     0,     0,     0,
    2949,     0,     0,  1913,     0,     0,  2332,     0,  2950,     0,
       0,     0,     0,     0,     0,     0,  1914,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  2886,  1867,     0,     0,     0,     0,     0,     0,     0,
    1861,     0,     0,     0,  1868,     0,     0,     0,  2333,     0,
       0,     0,     0,     0,     0,  1862,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1863,     0,     0,  1864,     0,     0,     0,     0,
    1915,     0,     0,     0,     0,  1869,     0,  1916,  1865,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  2951,     0,  2334,  1861,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1862,     0,     0,     0,  1870,     0,  1917,     0,  2978,  1867,
       0,     0,     0,     0,     0,     0,  1871,  1863,     0,     0,
    1864,  1868,     0,     0,     0,     0,     0,     0,  1872,  1873,
       0,  1918,     0,  1865,     0,     0,     0,  1874,     0,     0,
     688,  1919,  1920,     0,     0,     0,     0,     0,   272,     0,
       0,     0,     0,     0,     0,     0,     0,  1921,     0,     0,
       0,     0,  1869,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1867,     0,     0,     0,  1922,     0,
       0,  1923,  1924,     0,     0,     0,  1868,  1925,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1870,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1871,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1872,  1873,  1869,     0,     0,
       0,     0,     0,     0,  1874,     0,     0,   688,     0,     0,
       0,     0,     0,     0,  1926,   272,     0,     0,     0,     0,
       0,     0,     0,     0,  2952,     0,  1927,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1870,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1871,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1872,  1873,     0,     0,     0,     0,     0,     0,     0,  1874,
       0,     0,   688,     0,     0,     0,     0,     0,     0,     0,
     272,     0,     0,  2335,  2336,  2337,  2338,  2339,  2340,  2341,
    2342,  2343,  2344
};

static const short yycheck[] =
{
       2,   193,   187,   707,   422,   703,   328,   827,   838,     0,
      12,    13,   445,   978,   856,  1481,   212,    64,    82,   985,
     992,   521,   682,   823,  1670,   497,    60,  1665,  1666,   515,
    1394,  1669,    23,  1723,   919,   175,   363,  1844,    29,  1727,
    1674,    43,    44,  1448,  2054,  1259,  1260,  1359,   933,   834,
     835,  1010,   837,  1362,   839,   840,   542,  1348,  1291,   545,
     153,    95,   479,     5,   864,   507,    20,  1593,   504,  1785,
     117,   513,     5,    64,    76,   517,  2011,    79,  2013,   264,
     388,   779,     5,     5,    24,   225,   504,    18,    24,    91,
      26,    26,    23,    24,    25,  2405,    98,    25,    24,    24,
      26,    25,   104,   105,  1911,   538,     5,   141,   110,   111,
      24,   145,    24,    23,    47,    25,    49,    23,    51,    25,
      23,    24,    25,    17,    18,    25,   117,    23,  1533,    25,
     950,    25,   952,    55,    79,    24,  1774,  1542,    24,    61,
     446,    23,    24,    25,   237,   238,    24,   149,   340,    24,
     152,    26,    23,    24,    25,   157,   508,    17,    18,    23,
      18,    25,   468,    23,    24,    25,     5,    25,    41,     5,
      24,  1022,    41,   136,    24,    17,    18,     5,     5,    17,
      18,    23,    24,    25,     5,    23,    24,    25,   418,    24,
      66,    67,    24,   227,   196,    24,    45,     5,     5,    24,
    2510,     5,   141,     5,     5,    79,   512,    24,  2185,  2186,
    2187,  2188,     5,  1605,    24,    70,   522,   523,  1056,   923,
     526,     5,   452,  1899,   530,   455,   532,  1861,   113,    20,
     536,   537,   234,    24,     6,   465,     6,     5,   240,   469,
     128,   214,     5,   473,     5,     5,   280,   128,   282,   251,
     480,   596,     5,   287,   688,   485,     5,   487,   114,   115,
       5,  2570,    43,   493,   318,  2231,   496,     5,  2772,     5,
       5,    29,     5,   503,     5,     5,     5,   318,   508,     5,
     353,    39,  2630,   318,  2632,     5,   516,   253,     5,    26,
      17,    18,    19,    20,    21,     5,   186,   527,   339,     5,
       5,   531,   336,   323,  1950,   535,     6,   274,   227,  1947,
     540,   370,   275,   543,  2885,     5,     5,   364,   365,   353,
     154,  1787,     5,   136,   228,   488,    84,    85,  2833,    17,
      18,    19,    20,    21,    92,  2567,  1974,   363,  2145,     5,
     845,   846,   525,   101,   102,   141,   104,   105,     5,   409,
    2884,   109,    17,   517,   356,   312,   437,   359,    30,   326,
       5,  1203,   517,   330,   417,   367,  2012,   409,   126,   127,
    2008,   359,   458,   364,   365,   428,   436,   555,   370,   367,
     417,   383,    24,   385,   323,   471,   144,   145,   351,   889,
    1362,   428,   487,     0,   517,   437,    17,    18,    19,    20,
      21,   496,   566,    22,   253,    35,    36,   364,     5,     5,
     412,   566,   404,   119,   597,   417,   250,   419,   596,    84,
     422,   423,   409,   425,   412,   253,   428,     5,   363,     5,
       5,     5,   253,    63,    64,    65,  2941,   439,    20,    21,
       5,   408,  2976,   566,   446,   540,   409,    27,   543,   436,
     437,     5,     5,  2388,     5,  2390,   458,  2392,  1162,     5,
     363,   365,   275,   367,     5,     5,   468,   540,     5,   471,
       5,     5,   129,     5,   323,     5,     5,     5,  3049,   481,
       5,  2985,     5,   646,   129,    27,    28,  2163,   378,    71,
      72,    73,    74,    75,    76,   497,   498,   842,  1644,   436,
     437,  1647,   504,   557,   849,    87,    88,    89,   471,   568,
     512,   484,   514,   515,   374,   409,   557,   823,   599,   368,
     522,   523,   557,   525,   526,   450,   528,   323,   530,   389,
     532,   450,   374,   262,   536,   537,   374,   539,   351,   541,
     542,  2773,   544,   545,  2182,   547,   873,   389,   875,  1035,
     419,   389,   858,  1945,   574,  2865,  1028,   262,   864,   415,
    1032,  1033,  1034,   466,   374,   591,   405,  2915,   352,   405,
     876,  1005,  1008,   646,   147,   881,  1790,   370,   405,  1051,
     480,   547,  2891,    28,   523,   366,  1284,  1285,   346,  2555,
    1008,   328,   409,   529,   213,  1293,   518,   827,   370,   951,
     370,   405,   370,   405,   405,  2243,  1444,   368,   493,  1447,
     391,    22,   450,  2923,   372,   196,   504,   556,   409,   200,
    2630,   370,  2632,   504,   564,   370,   525,  2637,   345,   574,
    1130,   535,   370,   533,   370,   370,   670,   370,  1336,   370,
     370,   555,  1142,  1494,   370,   647,   228,   969,   521,   231,
     370,   591,   521,   368,   528,   591,   591,  1143,   471,  2969,
     370,  2971,   970,   591,   597,   591,   591,   591,   599,   494,
     370,  1556,   605,   675,   597,   677,  1148,   591,   405,   591,
     370,   370,   370,  1188,   606,   443,   688,   370,   591,   599,
    1126,   591,   646,   599,   475,  2502,   599,   591,   547,   641,
    2226,   703,   591,   599,   370,   591,  2683,  2642,  1126,   591,
     568,   713,   714,   591,  1131,   432,   591,   599,   525,   547,
     950,   951,   952,  1195,   532,  1958,   547,   729,   599,   605,
    2725,   591,   449,   735,   736,   599,  1222,   591,   740,   599,
    1712,   591,  1701,  2034,  2149,  2057,  2434,  2463,   750,  1221,
    2059,  2467,  2157,   591,  1226,  1943,   591,   599,  2396,   591,
    2398,   599,   591,   618,   619,   620,   621,   622,   350,   529,
    1256,  1257,   535,   370,   370,   492,   529,   779,   536,   628,
     629,   630,  1215,   365,   405,   409,   567,   369,  2754,  2755,
     639,    22,   370,  1765,   370,   370,   370,  1239,   579,   580,
     310,  1621,   213,   433,   437,   370,     9,   588,    11,    12,
      13,    14,    15,    16,   531,  1007,   370,   370,  2824,   370,
    2826,   823,   824,   409,   370,   407,  1132,  1133,  1134,   370,
     370,   338,  2767,   370,   303,   370,   370,  2772,   370,  1985,
     370,   370,   370,   560,   417,   370,  1152,   370,  1998,    26,
     436,   437,   569,   435,  2004,   428,   858,   261,   274,   617,
     303,  2551,   864,   444,   445,  2860,  2230,   625,    18,   261,
     274,  1371,   454,    23,   876,    25,   604,   450,  2512,   881,
     224,   338,   274,  1189,   457,   887,   541,   450,   981,   544,
     520,   984,   547,   237,    24,   458,    26,     0,  2766,   627,
     598,  2408,    20,   905,  2411,  2915,    24,   605,  1214,  2919,
    2124,   101,   102,  1611,   104,   105,   417,   919,  2556,   109,
      23,   436,   437,   638,   604,  1231,    23,   428,    25,   437,
     341,   933,   224,   563,    92,  1241,   126,   127,   605,  1127,
    2578,  1129,  2749,  1385,   332,   237,   626,   627,   455,   450,
    2885,   619,   620,   535,   144,   145,   457,   538,   568,   334,
     249,  1146,   596,   252,   224,   254,   599,   548,  2963,   221,
    2965,   101,   102,   131,   104,   105,   314,   237,   604,   109,
    1810,   605,   213,   493,   986,   274,    20,   325,   990,   991,
     992,   460,   408,   503,   599,   284,   126,   127,   455,  3005,
     626,   627,  1444,  1005,   408,  1447,  1008,  1493,  1010,  1011,
    2878,    23,  1014,    25,   144,   145,   408,   460,   618,     5,
     602,   621,   622,    24,    25,   215,  1028,  1029,   231,   332,
    1032,  1033,  1034,  1035,    23,  1037,    25,   326,  1040,   377,
    1540,   330,     5,  2009,  2232,  2233,  2914,  1889,   437,  1051,
    2985,  1053,   142,    13,   392,  1057,   146,   564,   142,   500,
     568,   599,   146,  1065,   409,  1067,  1068,    40,  1070,  1071,
    1072,  1073,  1074,  1075,  1076,  1077,  1078,  1079,  1080,  1081,
    1082,  1083,  1084,  1085,  1086,   215,   170,  2059,    91,  2494,
    2056,   599,    87,    88,    89,  1097,  1098,  1597,   409,  2733,
    1102,  2735,  1104,   409,  1576,  1577,  1592,   564,   514,  2977,
     341,   455,  2802,   437,  3049,    18,   409,   409,   409,   408,
      23,    24,    25,  2761,  1126,   404,   707,   471,   345,  1949,
    1132,  1133,  1134,   266,   267,   604,    24,   512,    25,   112,
     409,  1143,  1282,  1145,   482,  1147,  1148,   350,  1288,   409,
    1152,   526,   409,  1973,   623,   624,   217,   437,  1464,   249,
     409,   604,   252,   455,   249,   249,   409,   252,   252,   254,
     409,   460,   409,   754,   643,  2048,   551,  2050,  2051,   471,
     623,   624,  1488,    25,   274,  2070,  1492,  1189,   409,   274,
     274,  2881,    25,  1195,   527,   455,  2834,   605,   531,   284,
     643,  1528,   535,   605,  1704,   178,    25,   180,   621,   622,
      25,   471,  1214,   274,   599,   432,  1522,  1219,   303,  1221,
    1222,    25,   195,    25,  1226,   600,   416,  1734,  1230,  1231,
     203,  1324,   449,    29,   207,  1933,    24,    25,  1745,  1241,
    1333,   326,  1548,  1750,   437,   330,    25,  1754,  2894,  1756,
    1757,  1758,   599,  1255,  1256,  1257,  1486,    25,    54,   232,
     418,  2625,   420,   421,   460,   326,  1766,    25,  1768,   330,
     455,  1713,   628,   629,    25,   492,   434,  1777,  1976,  1281,
     628,   629,  1284,  1285,   469,  2931,   416,  1289,   473,  1291,
      25,  1293,    37,    25,   452,  1329,   370,   455,   409,   340,
     485,  1961,  1366,   461,   599,   101,   102,   465,   104,   105,
      25,   469,     5,   109,   531,   473,   409,    29,   408,   477,
     478,   409,   480,   408,   408,   483,   405,   485,   486,   487,
     126,   127,   535,   370,  1336,   493,   599,    25,   496,   112,
     237,   405,   923,   560,   370,   503,  1348,   408,   144,   145,
     508,   370,   569,   340,   643,    20,    25,  1359,   516,    25,
    1362,   843,   844,    25,    97,   847,   848,    25,    25,   527,
    1600,  3009,    20,   531,  2174,   460,   409,   535,    25,  1381,
    1382,  1383,   540,  2225,    20,   543,    25,  1389,  2854,   101,
     102,  1621,   104,   105,  2758,   283,    25,   109,   599,  1705,
     370,   289,   290,   291,     5,   178,   370,   180,   604,   591,
     438,   646,  1854,   370,   126,   127,  1418,  1419,  1420,   215,
    1422,   309,   195,   592,   593,   594,   595,   623,   624,   281,
     203,   370,   144,   145,   207,    71,    72,    73,    74,    75,
      76,   370,   370,   370,   603,   218,  1448,   643,  1450,     5,
     370,  2417,  2424,     4,     5,     6,     7,     8,     9,   232,
      11,   591,  1464,  1769,  1770,  1771,  1772,   200,    71,    72,
      73,    74,    75,    76,   281,   208,  2942,   370,   370,   603,
    1482,   214,   599,   216,   370,   370,  1488,  1793,  1490,  1491,
    1492,  1493,   345,    24,   227,  2961,   437,   596,   599,     8,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    24,   458,   409,
    1522,   405,   255,   345,   504,  1527,   409,   409,   409,   417,
     409,  1533,   420,   409,   345,   409,  1538,  1733,   271,   335,
    1542,   409,   409,   276,  1850,   409,  1548,    17,    18,    19,
      20,  3017,   409,   409,  1556,   288,   444,     5,   643,  2964,
     409,  1563,   295,  1565,  2064,   409,    71,    72,    73,    74,
      75,    76,   409,   409,  1576,  1577,   464,   409,   409,   432,
     217,  1162,    87,    88,    89,   409,   409,   399,   384,   409,
    1592,   409,   409,   409,   249,   409,   449,   252,   438,   254,
     245,    71,    72,    73,    74,    75,    76,   597,  2108,  1611,
     432,   499,    17,    18,    19,    20,    21,  1619,   597,   274,
     416,   432,   574,   335,   399,   438,  2591,   449,  1630,   284,
     518,   519,   638,   409,  1215,   305,   638,   274,   449,   492,
       8,  1643,  1644,  2485,   575,  1647,   534,     5,   303,     5,
     409,   362,   409,  2483,   409,   142,   409,   409,  1964,   146,
    1966,  1663,    24,  1665,  1666,   112,   409,  1669,  1670,   827,
     492,   326,   384,   323,   568,   330,     8,   557,   531,    13,
       5,   492,  1263,   170,   554,   573,     5,   638,   638,   326,
     399,   409,   409,   330,  1696,    25,    25,    45,    70,  1701,
     437,   437,   409,  1705,    25,   409,     5,   560,   409,   531,
    1712,    20,   574,  1943,   568,   409,   569,   450,   606,  1949,
     531,  1723,   599,   228,   457,   409,   231,   450,   409,    20,
     605,   178,  2430,   180,    20,   409,   409,   409,   560,  2211,
     605,  2213,   409,  1973,   605,   641,   479,   569,   195,   560,
     329,   484,   535,   408,   604,    17,   203,  1759,   569,  1761,
     207,    18,   249,  1765,     5,   252,   320,  1769,  1770,  1771,
    1772,   408,  1774,    25,    25,   329,   131,   197,  1780,  1781,
      19,    20,  1784,  1785,  2202,   232,  2490,   274,    24,     5,
     568,  1793,   950,   951,   952,   557,   602,   461,   461,   353,
     525,  1803,   356,   129,   525,   460,     5,    25,  2114,   378,
     300,  2117,   525,    71,    72,    73,    74,    75,    76,    25,
     374,   409,   409,   409,   409,   409,    24,   599,   555,    87,
      88,    89,    71,    72,    73,    74,    75,    76,   643,   525,
     370,   370,   370,   370,   370,   350,   370,   370,  1850,    25,
    1852,   370,   370,  2695,   370,    19,    20,    21,   370,   605,
     365,  2703,  1864,     5,   369,   596,     5,     5,  2174,   558,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,     5,  1890,   599,
    2323,  2324,  2325,   370,  2327,  2328,  2329,  2330,  2331,  2332,
     370,   462,   407,  2336,   421,   605,   409,    71,    72,    73,
      74,    75,    76,   604,   409,     5,   532,   434,    25,    25,
     409,   408,  2422,    87,    88,    89,   480,   304,    45,   370,
     435,  1933,   514,     5,   370,   370,    71,    72,    73,    74,
      75,    76,   409,   339,   461,  1947,   605,   575,  1950,   454,
    2450,  1998,    87,    88,    89,  1957,  1958,  2004,    44,   345,
     477,   478,  1964,    13,  1966,   599,   483,   529,   639,   486,
     228,     5,  1974,   231,  1976,   525,    25,  2675,   227,   533,
      79,   450,   409,  1985,  1565,  2471,   540,   599,   643,     5,
     605,   409,  2478,   604,    24,   618,   405,    83,   405,   345,
     439,   439,  2232,  2233,   370,   409,  2008,  1998,  2850,   409,
    2012,   409,  2014,  2004,     9,  2719,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,   409,   409,   409,   409,
     535,     8,  2034,     5,     5,    25,    25,   370,  1619,   409,
     599,     5,   370,   568,   599,     8,   432,   133,   370,   304,
     370,   599,   323,   323,   599,  2057,   323,  2059,   437,   409,
     339,   404,    20,   449,   228,  2067,     5,   231,  2070,   409,
     409,  2073,   409,  2893,   409,   399,    71,    72,    73,    74,
      75,    76,  1663,   630,    59,   171,   432,  1245,    25,  1670,
       5,   409,   350,   228,   409,     5,   231,   602,     5,     5,
      25,   574,   574,   449,   107,   596,   492,   365,   409,     5,
     562,   369,  2114,   116,   599,  2117,   599,     5,     5,     5,
    2122,   409,   125,     7,   370,     5,  2824,   130,  2826,   605,
      25,    25,  2974,  2135,    25,  2137,   599,  2139,     8,   370,
     370,   605,  1723,   370,  2146,   531,   492,  2149,    25,   407,
      25,  2153,   568,   370,   605,  2157,   370,   370,   133,   134,
    2945,  2946,  2947,  2948,  2949,  2950,   370,   370,  2474,    20,
       5,   174,  2174,   253,   560,    20,   545,   435,   370,   182,
    2182,     5,   268,   569,     5,   531,   350,  2189,  2190,  2191,
    2192,  2193,  2194,    20,   525,     5,   454,  2697,  2504,   219,
    2202,   365,   370,   370,   437,   369,   550,   409,   605,  2211,
     419,  2213,   187,   370,   560,   350,   409,     6,   193,   532,
     605,   599,  2694,   569,   450,   532,  2532,   189,   603,   605,
     365,    24,   603,    24,   369,   238,   231,    24,   598,   425,
      24,  2243,    24,   407,    25,    25,  2248,    25,    25,    25,
     336,   409,    25,   450,   409,    25,   275,   599,   344,     5,
     263,   370,   348,   247,   345,   370,   504,   270,  2590,   272,
      21,   435,   407,   568,  1855,  1856,   370,   535,  1565,   282,
    2465,   447,     5,  1864,   409,   370,   529,    20,   399,   264,
     454,   266,     5,  2295,   323,   219,   370,   405,     5,   385,
     435,   370,  2304,  2305,  2306,   308,   419,  3005,   323,    20,
    2312,    29,   118,   316,  2506,    13,     5,    13,   441,   454,
      71,    72,    73,    74,    75,    76,   599,   189,  1486,     5,
      20,   370,  1619,    25,   370,   370,    87,    88,    89,    25,
       5,  2841,   370,   960,   602,    26,   347,   352,   598,   370,
     353,   432,   547,   310,    25,   350,   370,   409,   605,   220,
     554,    17,    18,    19,    20,   340,   409,   453,   449,  1950,
     218,   535,  2374,  3077,  2376,   370,   379,   525,   218,   420,
      25,   437,   605,   101,   102,  2387,   104,   105,   370,   426,
    2392,   109,   371,  2699,  2396,   605,  2398,   409,   599,     5,
     535,   370,    13,   405,     5,   605,   492,     5,   126,   127,
      24,   492,   407,    20,   417,    71,    72,    73,    74,    75,
      76,   220,  2424,   409,   370,   428,   144,   145,  2430,     5,
     516,  2012,   370,  2014,   370,  2067,  1723,  3027,   602,  2152,
    1840,  2443,  1600,  1232,  2073,  1549,    36,    38,   364,  1781,
     531,  2135,  1787,   287,   141,   430,    17,    18,    19,    20,
     145,  2463,   209,  1621,  2466,  2467,   281,   602,   396,  2471,
    1328,   288,  2474,  2054,   560,   353,  2478,   228,  1329,   560,
     231,   211,  1748,   569,   316,  2438,   371,   315,   569,   464,
     383,  3017,  2494,   385,  1761,   470,   957,   472,  1522,   525,
    1399,   476,  2504,  1641,   479,   591,  1648,   482,  1492,  1771,
      71,    72,    73,    74,    75,    76,  2518,   492,  2520,  2521,
    2522,  2523,  1003,  2535,   527,   528,   529,  1255,  2206,  1258,
    2532,  1886,  1572,  3041,  1775,  1587,   511,   540,  2220,  1148,
     535,  2222,  1700,  2711,   519,   520,   521,  2549,    23,  2551,
     525,    42,   117,    29,  2556,  2612,    29,  1554,   533,   482,
     649,  1560,  1242,  2565,   266,   677,  1263,  2715,  2570,  1563,
     924,  2609,  2787,   548,  1139,  2961,  2578,  1864,  2580,  1186,
    1603,  2190,   876,  1129,  2363,  2797,   581,  1214,    17,    18,
      19,    20,  2361,  1061,  2345,  2007,  1365,  1014,  1765,   350,
    1342,  2771,  1943,    17,    18,    19,    20,   602,  2189,  2190,
    2191,  2192,  2193,  2194,   365,   138,  3045,  3009,   369,  1977,
    2899,  2395,  2008,  1669,  2675,  2431,  2374,  2014,  2630,  2376,
    2632,  2632,   155,   156,  2636,  2915,  2638,  1281,   730,  2816,
     163,   644,    71,    72,    73,    74,    75,    76,  2650,   953,
    2956,  2024,  2306,    77,  2835,  2433,   407,    71,    72,    73,
      74,    75,    76,  2893,  2836,  2753,  3007,  2248,  2738,  2248,
    2919,  1277,  2244,  2675,   197,  2876,  1701,  2679,  2565,  2681,
     949,    -1,  1144,   206,   435,   362,    -1,    -1,    -1,    -1,
      -1,    -1,  2694,    -1,    -1,    -1,    -1,  2699,  1315,  1316,
      -1,    -1,    -1,   454,    -1,  1322,    -1,    -1,    -1,    -1,
      -1,  1869,   235,    -1,   370,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  2012,    -1,    -1,    -1,    -1,
      -1,    -1,   707,    -1,    -1,    -1,  2738,    -1,    -1,    -1,
      -1,  2743,  2323,  2324,  2325,    -1,  2327,  2328,  2329,  2330,
    2331,  2332,   713,   714,    -1,  2336,  3062,   280,    -1,  2761,
      -1,    -1,    -1,    -1,    -1,  2767,    -1,    -1,   729,  2771,
    2772,    -1,    -1,    -1,   735,   736,  1934,  2779,    -1,   740,
      -1,    -1,    -1,    -1,   535,  1943,    -1,   278,    -1,   750,
      -1,  1949,    -1,  2374,    -1,  2376,    -1,    -1,    -1,   322,
    2802,   776,    -1,    -1,    -1,    -1,  2387,    -1,    -1,   370,
      -1,  2392,    -1,    -1,    -1,  1973,    -1,    -1,    -1,    -1,
      -1,    -1,  2824,    -1,  2826,    -1,    -1,  2829,    -1,    -1,
      -1,    -1,  2834,    -1,  2836,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   819,   336,    -1,    -1,    -1,    -1,
      -1,   602,    -1,    -1,    -1,    -1,    -1,   348,   833,   834,
     835,    -1,   837,    -1,   839,   840,    -1,   358,    -1,    -1,
     845,   846,  2030,    -1,  2876,    -1,    -1,    -1,    -1,  2881,
      -1,  2883,    -1,  2885,    -1,   376,    -1,   311,    -1,  2891,
      -1,    -1,  2894,    -1,    -1,   386,    -1,  2899,   389,    -1,
     324,    -1,  2189,  2190,  2191,  2192,  2193,  2194,    -1,  2490,
      -1,   402,    -1,  2915,   889,  1532,  2918,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   900,    -1,    -1,    -1,  2931,
      17,    18,    19,    20,    -1,    -1,    -1,  2518,    -1,  2520,
    2521,  2522,  2523,    -1,    -1,    -1,    -1,    -1,   923,   924,
      -1,  1568,    -1,    -1,  2956,  2957,   370,   932,    -1,    -1,
     451,  2248,  2964,    -1,   388,    -1,    -1,    -1,    -1,    -1,
    2551,   395,    -1,   948,   949,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  2985,    71,    72,    73,    74,    75,    76,
     481,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     491,    -1,    -1,  3005,    -1,  3007,    -1,  3009,    -1,    -1,
     434,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     511,    -1,    -1,   514,    -1,   516,    -1,    -1,    -1,    -1,
      -1,    -1,  1007,    -1,    -1,   459,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  3045,    -1,   469,   470,  3049,    -1,  2630,
      -1,  2632,    -1,   544,    -1,  2636,  2637,  2638,    -1,    -1,
    3062,   485,   553,    -1,    -1,    -1,    -1,    -1,  1029,    -1,
      -1,    -1,    -1,    -1,  2232,  2233,  1037,    -1,    -1,  1040,
      -1,    -1,   506,    -1,    -1,   509,   510,    -1,    -1,    -1,
      -1,   515,  1053,    -1,    -1,    -1,  1057,    -1,    -1,    -1,
    2387,    -1,    -1,    -1,  1065,  2392,  1067,  1068,    -1,  1070,
    1071,  1072,  1073,  1074,  1075,  1076,  1077,  1078,  1079,  1080,
    1081,  1082,  1083,  1084,  1085,  1086,    17,    18,    19,    20,
      -1,    -1,    -1,    -1,    -1,    -1,  1097,  1098,  2719,    -1,
      -1,  1102,    -1,  1104,  1119,    -1,    -1,    -1,   572,    -1,
      -1,    -1,  1127,    -1,  1129,  1130,  1131,  2738,    -1,    -1,
     584,    -1,  2743,  1138,  1139,    -1,    -1,  1142,    -1,    -1,
      -1,  1146,    -1,    -1,  1149,    -1,    -1,    -1,    -1,    -1,
      71,    72,    73,    74,    75,    76,  2767,  1162,    -1,    -1,
      -1,  2772,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    -1,    -1,
      -1,  2369,    -1,  1188,    -1,    -1,    -1,  1834,  1835,    -1,
      -1,  2802,    -1,    -1,    -1,    -1,    -1,    -1,  1845,    -1,
      -1,  2518,    -1,  2520,  2521,  2522,  2523,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2829,    -1,
      -1,    -1,    -1,  1228,    -1,    -1,    -1,    71,    72,    73,
      74,    75,    76,    -1,  2551,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    87,    88,    89,  1251,    -1,  1895,  1896,
    1897,  1898,    -1,   370,    -1,    -1,    -1,  1262,  1263,    -1,
      -1,    -1,    -1,  1910,    -1,     5,    -1,    -1,     7,    -1,
    2881,    -1,  2883,    -1,  2885,    -1,    -1,    -1,    17,    18,
      19,    20,    -1,  2894,    -1,    -1,     9,    -1,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    -1,    -1,
      -1,    -1,    -1,    -1,  2915,    -1,    -1,  2918,  2919,    -1,
      -1,    -1,  1317,    -1,    -1,    -1,    -1,    -1,    -1,  2636,
    2931,  2638,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  2519,    71,    72,    73,    74,    75,    76,    -1,  1986,
    1987,    -1,    -1,    -1,    -1,    -1,  1993,  1994,    71,    72,
      73,    74,    75,    76,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1371,    -1,    -1,    -1,
    2558,    -1,    -1,    -1,  2985,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   228,    -1,    -1,   231,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  3007,    -1,  1389,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  2738,    -1,    -1,    -1,    -1,  2743,  1418,  1419,  1420,
      -1,  1422,    -1,    -1,  3045,    -1,    -1,    -1,  3049,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   370,
    2767,    -1,    -1,    -1,    -1,  2772,    -1,  1448,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  3077,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2125,  2126,
      -1,    -1,    -1,    -1,    -1,  2802,    -1,  2134,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  2142,    -1,    -1,    -1,   239,
      -1,    -1,    -1,    -1,    -1,    -1,   350,    -1,   231,    -1,
      -1,    -1,  2829,  2160,  2161,  1520,    -1,    -1,    -1,    -1,
      -1,   365,    -1,    -1,  1529,   369,   370,    22,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1540,  1527,    -1,   278,    -1,
      -1,    -1,  1533,    -1,    -1,    -1,    41,    -1,    -1,    -1,
      -1,  1542,    -1,    -1,    -1,  1560,    -1,   297,    -1,    -1,
      -1,    -1,    -1,   407,  2881,  2212,  2883,  2214,  2885,    -1,
      -1,    -1,    -1,    -1,  2221,    70,  2223,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,   435,  1597,    -1,  1599,    -1,   336,    -1,  1603,    -1,
      -1,  2918,    -1,    -1,    -1,    -1,    -1,    -1,   348,    -1,
     454,    -1,    -1,    -1,    -1,    -1,    -1,   112,   358,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   350,    -1,    -1,
    1635,    -1,    -1,    -1,    -1,    -1,   376,    -1,    -1,    -1,
      71,    72,    73,    74,    75,    76,   386,   142,    -1,    -1,
      -1,   146,    -1,    -1,    -1,    -1,    87,    88,    89,    -1,
      -1,    -1,   402,    -1,    -1,    -1,  2313,  2314,  2985,    -1,
    2317,  2318,    -1,    -1,    -1,   170,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   178,   407,   180,    -1,    -1,    -1,    -1,
    3007,   535,    -1,    -1,   189,    -1,    -1,    -1,    -1,  1704,
     195,    -1,   442,    -1,  2351,  2893,    -1,    -1,   203,    -1,
      -1,    -1,   207,    -1,    -1,    -1,    -1,    -1,   213,    -1,
      -1,    -1,   217,   218,   219,   220,   466,    -1,  3045,    -1,
      -1,    -1,  3049,    -1,    -1,    -1,    -1,   232,    -1,    -1,
      -1,   481,    -1,    -1,    -1,    -1,    -1,    -1,   488,    -1,
      -1,   491,    -1,    -1,   249,    -1,    -1,   252,   602,   254,
      -1,  1766,    -1,  1768,    -1,    -1,   261,    -1,  1759,    -1,
    1761,   511,  1777,    -1,   514,    -1,   516,    -1,    -1,   274,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   284,
      -1,    -1,    -1,    -1,    -1,   535,    -1,   228,    -1,    -1,
     231,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   303,   304,
    1815,    -1,   535,   553,    -1,    -1,    -1,  2464,    -1,    -1,
      -1,  2468,    -1,   318,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   326,    -1,    -1,    -1,   330,    -1,    -1,    -1,  1844,
      -1,    -1,    -1,    -1,   339,   340,   341,    -1,    -1,    -1,
      -1,    -1,    -1,  2500,    -1,    -1,    -1,    -1,   581,    -1,
      -1,    -1,    -1,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,   602,
      -1,    -1,    -1,    -1,    -1,    -1,  2533,    -1,    -1,    -1,
      -1,    -1,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    -1,    -1,
      -1,    -1,    -1,   408,    -1,    -1,    -1,    -1,    -1,   350,
      -1,    -1,    -1,    -1,   419,    -1,    -1,    -1,    71,    72,
      73,    74,    75,    76,   365,    -1,    -1,    -1,   369,    -1,
      -1,    -1,    -1,    -1,    87,    88,    89,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    71,    72,    73,
      74,    75,    76,    -1,    -1,   460,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    87,    88,    89,   407,    -1,    -1,  1984,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   435,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    17,    18,    19,    20,    -1,    -1,    -1,    -1,
      -1,    26,    -1,   454,    -1,    -1,   521,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2064,
      -1,    -1,   557,    -1,    -1,    -1,    71,    72,    73,    74,
      75,    76,    17,    18,    -1,    20,    -1,    -1,    23,    24,
      25,    -1,  2073,  2730,    -1,   228,    -1,    -1,   231,    71,
      72,    73,    74,    75,    76,    -1,    -1,    -1,    43,    -1,
      -1,    -1,    -1,  2108,   535,    87,    88,    89,    -1,   604,
      -1,    -1,    -1,    -1,   228,    -1,    -1,   231,    -1,    -1,
      -1,    -1,    -1,   618,   619,   620,   621,   622,   623,   624,
      -1,   626,   627,    -1,    -1,    -1,  2141,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  2150,    -1,  2152,   643,  2154,
      -1,    -1,    -1,    -1,    -1,  2146,    -1,    -1,  2149,    -1,
      -1,  2166,    -1,    -1,    31,    -1,  2157,    -1,    -1,    -1,
      -1,   602,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    59,    60,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    68,    -1,    -1,    -1,    -1,    -1,   350,    -1,    -1,
      -1,    -1,    -1,    -1,  2861,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   365,    -1,    -1,    -1,   369,   370,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   350,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   228,    -1,    -1,   231,
      -1,   365,    -1,    -1,   259,   369,   370,  2904,  2905,    -1,
    2907,    -1,  2909,  2910,   407,    -1,    -1,    -1,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   435,   407,   299,   300,   301,    -1,    -1,    -1,
      -1,    -1,  2307,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   454,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   324,
      -1,   435,    -1,    -1,    -1,    -1,  2973,   332,   273,    -1,
      -1,    -1,   337,    71,    72,    73,    74,    75,    76,    -1,
     454,    -1,  2347,    -1,    -1,    -1,  2993,   352,  2995,    87,
      88,    89,   357,    -1,   359,  2360,    -1,    -1,    -1,    -1,
      -1,   366,    -1,    -1,   369,    -1,    -1,   372,   350,    -1,
     375,    -1,   239,   378,    -1,    -1,    -1,    -1,   383,    -1,
      -1,    -1,    -1,   365,    -1,  3032,    -1,   369,    -1,    -1,
      -1,    -1,   535,    -1,    -1,    -1,   401,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  3056,
    3057,   278,   417,  3060,    -1,   420,   421,  2422,    -1,    -1,
      -1,   535,   427,    -1,    -1,   407,    -1,    -1,    -1,   374,
     297,    -1,    -1,   438,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   389,  2450,   313,    -1,    -1,   454,
      -1,    -1,  2443,   435,    -1,    -1,   461,    -1,    -1,   602,
    2465,   406,    -1,   468,   409,    -1,   471,   472,   473,   336,
     475,   476,   454,    -1,    -1,    -1,   421,   422,    -1,    -1,
      -1,   348,    -1,    -1,    -1,  2490,    -1,   492,   602,    -1,
     228,   358,    -1,   231,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  2506,    -1,  2494,    -1,   450,    -1,    -1,    -1,   376,
     515,   516,   517,   518,    -1,   520,    -1,    -1,   463,   386,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     475,    -1,   537,   538,    -1,   402,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   535,    -1,   560,    -1,    -1,    -1,    -1,
      -1,    -1,  2567,    -1,   569,   570,    -1,   572,    -1,    -1,
      -1,   516,    -1,    -1,    -1,   442,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   466,
      -1,    -1,    -1,    -1,  2609,    -1,    -1,    -1,    -1,    -1,
     555,    -1,   350,    -1,   481,    -1,    -1,    -1,    -1,    -1,
     602,   488,   567,    -1,   491,    -1,    -1,   365,    -1,   634,
      -1,   369,   370,    -1,   579,   580,   581,    -1,    -1,    -1,
      -1,    -1,    -1,   588,   511,    -1,   591,   514,    -1,   516,
      -1,    -1,    -1,    -1,   599,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   535,   407,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   553,    -1,    -1,    -1,
      -1,    -1,  2697,    -1,    -1,    -1,    -1,   435,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2714,
    2715,    -1,    -1,    -1,  2719,    -1,   454,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   596,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2773,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  2787,    -1,    -1,    -1,    -1,  2792,    -1,  2794,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   535,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    71,    72,
      73,    74,    75,    76,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    87,    88,    89,    -1,    -1,    -1,
    2835,    -1,    -1,    -1,    -1,    -1,  2841,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   602,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    29,    -1,    -1,    -1,    33,    34,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    46,    -1,
      48,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    62,    -1,    -1,    -1,    -1,    -1,
      -1,    69,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    80,    81,    82,    -1,    -1,    -1,    -1,    -1,
    2945,  2946,  2947,  2948,  2949,  2950,    -1,    -1,    96,    -1,
      98,    99,   100,   101,   102,   103,   104,   105,   106,    -1,
     108,   109,   110,   111,    -1,   228,    -1,    -1,   231,   117,
      -1,    -1,   120,  2964,   122,   123,   124,    -1,   126,   127,
      -1,    -1,    -1,    -1,   132,    -1,   134,   135,    -1,   137,
      -1,   139,   140,    -1,    -1,   143,   144,   145,    -1,    -1,
     148,   149,   150,    -1,   152,   153,    -1,    -1,    -1,   157,
     158,    -1,   160,    -1,    -1,    -1,   164,    -1,   166,   167,
      -1,    -1,    -1,    -1,   172,    -1,    -1,    -1,   176,    -1,
      -1,   179,    -1,   181,    -1,   183,    -1,   185,    -1,   187,
     188,    -1,   190,   191,   192,    -1,    -1,    -1,   196,    -1,
     198,   199,    -1,   201,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   209,   210,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  3077,    -1,   222,    -1,    -1,   225,   226,    -1,
      -1,   229,   230,    -1,    -1,   233,   234,   350,    -1,    -1,
      -1,    -1,    -1,    -1,   242,   243,   244,    -1,   246,    -1,
      -1,    -1,   365,    -1,    -1,    -1,   369,   370,   256,   257,
     258,    -1,   260,    -1,    -1,    -1,   264,   265,    -1,    -1,
      -1,   269,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   277,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   285,   286,   287,
      -1,    -1,    -1,    -1,   407,   293,   294,    -1,    -1,    -1,
      -1,   299,    -1,    -1,   302,    -1,    -1,    -1,   306,   307,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   317,
      -1,    -1,   435,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   335,    -1,    -1,
      -1,   454,    -1,    -1,    -1,   343,    -1,    -1,    -1,    -1,
      -1,   349,    -1,    -1,    -1,    -1,    -1,    -1,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,   372,    -1,    -1,    -1,    -1,    -1,
      -1,   379,    -1,   381,   382,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   390,    -1,    -1,    -1,    -1,    -1,    -1,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   535,    71,    72,    73,    74,    75,    76,    -1,
      -1,   429,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    87,
      88,    89,   440,    -1,    -1,    -1,   444,    -1,    -1,    -1,
     448,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    71,    72,    73,    74,    75,    76,
      -1,    -1,    -1,    -1,   472,   473,    -1,    -1,    -1,   477,
      87,    88,    89,    -1,    -1,    -1,    -1,    -1,    -1,   602,
      -1,   489,    -1,    -1,    -1,    -1,    -1,   495,   496,   497,
     498,    -1,    -1,   501,    -1,    -1,    -1,   505,    -1,    -1,
      -1,    -1,    -1,    -1,   512,   513,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   524,    -1,   526,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   537,
      -1,   539,    -1,    -1,   542,    -1,    -1,    -1,    -1,    -1,
     548,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   574,    -1,    -1,   577,
     228,    -1,    -1,   231,    -1,   583,    -1,    -1,   586,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   601,    -1,    -1,    -1,    -1,    -1,    -1,
     608,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   228,    -1,    -1,   231,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   631,   632,   633,   634,   635,   636,   637,
      -1,    -1,   640,    -1,   642,    -1,   644,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    -1,
      -1,    -1,   350,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   365,    -1,    -1,
      -1,   369,   370,    71,    72,    73,    74,    75,    76,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    87,
      88,    89,    -1,   350,    -1,    -1,    -1,    -1,    71,    72,
      73,    74,    75,    76,    -1,    -1,    -1,    -1,   365,   407,
      -1,    -1,   369,   370,    87,    88,    89,    -1,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    -1,    -1,    -1,    -1,   435,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     407,    -1,    -1,    -1,    -1,    -1,   454,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   435,    -1,
      -1,    -1,    71,    72,    73,    74,    75,    76,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   454,    87,    88,
      89,    -1,    -1,    -1,    -1,    -1,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    -1,    71,    72,
      73,    74,    75,    76,    -1,    -1,    -1,    -1,    -1,    -1,
     228,    -1,    -1,   231,    87,    88,    89,   535,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   228,    -1,    -1,   231,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    71,    72,    73,    74,
      75,    76,    -1,    -1,    -1,    -1,    -1,    -1,   535,    -1,
      -1,    -1,    87,    88,    89,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    71,    72,    73,
      74,    75,    76,    -1,   602,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    87,    88,    89,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   228,
      -1,    -1,   231,    -1,    -1,   602,    -1,    -1,    -1,    -1,
      -1,    -1,   350,    -1,    14,    15,    16,    17,    18,    19,
      20,    21,    -1,    -1,    -1,    -1,    -1,   365,    -1,    -1,
      -1,   369,   370,    -1,    -1,   228,    -1,   350,   231,    -1,
      -1,    71,    72,    73,    74,    75,    76,    -1,    -1,    -1,
      -1,    -1,   365,    -1,    -1,    -1,   369,    87,    88,    89,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   407,
      -1,    71,    72,    73,    74,    75,    76,    -1,    -1,    -1,
      -1,    -1,    -1,   228,    -1,    -1,   231,    87,    88,    89,
      -1,    -1,    -1,    -1,   407,    -1,    -1,   435,    -1,    -1,
      -1,    -1,    -1,    -1,    17,    18,    -1,    20,    -1,    -1,
      23,    24,    25,    -1,   228,    -1,   454,   231,    -1,    -1,
      -1,   350,   435,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      43,    -1,    -1,    -1,    -1,    -1,   365,    -1,    -1,    -1,
     369,   454,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   350,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   365,    -1,    -1,    -1,   369,    -1,   407,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   535,   228,    -1,
      -1,   231,    -1,    -1,    -1,   350,   435,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   407,    -1,    -1,    -1,    -1,    -1,
     365,    -1,   535,    -1,   369,   454,    -1,    -1,   228,    -1,
      -1,   231,    -1,    -1,    -1,    -1,   350,    -1,    -1,    -1,
      -1,    -1,   435,    15,    16,    17,    18,    19,    20,    21,
      -1,   365,    -1,    -1,    -1,   369,    -1,    -1,    -1,    -1,
      -1,   454,   407,    -1,   602,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    16,    17,    18,    19,    20,    21,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   602,
     435,    -1,    -1,   407,    -1,    -1,    -1,    -1,    -1,    71,
      72,    73,    74,    75,    76,    -1,   535,    -1,    -1,   454,
      -1,    -1,    -1,    -1,    -1,    87,    88,    89,    -1,    -1,
     350,   435,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    71,
      72,    73,    74,    75,    76,   365,    -1,    -1,    -1,   369,
     454,    -1,   535,    -1,    -1,    87,    88,    89,    -1,    -1,
     350,    -1,    -1,    -1,    -1,    -1,    -1,    17,    18,    19,
      20,    21,    -1,    -1,    -1,   365,    -1,    -1,    -1,   369,
      -1,    -1,    -1,   602,    -1,    17,    18,   407,    -1,    -1,
      -1,    23,    24,    25,    26,    -1,    -1,    -1,    -1,    -1,
     535,    -1,    -1,    -1,    -1,    -1,    38,    -1,    -1,    -1,
      -1,    43,    44,    -1,    -1,   435,    -1,   407,    50,   602,
      -1,    71,    72,    73,    74,    75,    76,    -1,    -1,    -1,
      -1,   535,    -1,    -1,   454,    -1,    -1,    87,    88,    89,
      -1,    -1,    -1,    -1,    -1,   435,    78,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   454,    -1,   228,   602,    -1,   231,
      -1,   374,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   389,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   228,    -1,   602,   231,
      -1,    -1,    -1,   406,    -1,    -1,   409,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   535,    -1,    -1,    -1,   422,
      -1,    -1,    -1,    -1,    -1,    17,    18,    -1,    -1,    -1,
      -1,    23,    24,    25,    26,    -1,    -1,    -1,    -1,   171,
      -1,    -1,    -1,    -1,    -1,   535,    38,   450,    -1,    -1,
      -1,    43,    44,    -1,    -1,    -1,    -1,    -1,    50,   462,
     463,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   475,    -1,    -1,    -1,    -1,    -1,   228,    -1,
      -1,   231,   602,    -1,    -1,    -1,    78,    -1,   350,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   365,    -1,    -1,    -1,   369,    -1,    -1,
      -1,    -1,   602,   516,    -1,    -1,    -1,    -1,   350,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   239,    -1,   365,    -1,    -1,   268,   369,    -1,    -1,
      -1,   273,    -1,    -1,    -1,   407,    -1,    -1,    -1,    -1,
      -1,    -1,   555,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      17,    18,    -1,    -1,   567,    -1,    23,    24,    25,   301,
     278,    -1,    -1,   435,    -1,   407,   579,   580,    -1,   171,
      -1,    38,    -1,    -1,    -1,   588,    43,    44,   591,   297,
      -1,    -1,   454,    50,    -1,    -1,   599,    -1,    -1,    -1,
     350,    -1,    -1,   435,   336,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   365,   348,    -1,    -1,   369,
      -1,    78,   454,    -1,    -1,    -1,    -1,    -1,   336,    -1,
      -1,    -1,    -1,    -1,   366,    -1,    -1,    -1,    -1,   371,
     348,    -1,   374,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     358,    -1,    -1,   385,    -1,    -1,    -1,   407,    -1,   391,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   376,   401,
      -1,    -1,    -1,   535,   406,    -1,   268,   409,   386,    -1,
     412,   273,    -1,    -1,    -1,   435,    -1,    -1,    -1,   421,
     422,    -1,    -1,    -1,   402,    -1,    -1,    -1,    -1,    -1,
      17,    18,    -1,   535,   454,    -1,    23,    24,    25,   301,
      -1,    -1,    -1,    -1,   171,    -1,    -1,    -1,    -1,    -1,
      -1,    38,    -1,    -1,    -1,    -1,    43,    44,    -1,    -1,
     462,   463,    -1,    50,   442,   467,    -1,    -1,    -1,    -1,
     602,    -1,    -1,   475,   336,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   486,    -1,   348,    -1,   466,    -1,
     492,    78,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     602,    -1,    -1,   481,   366,    -1,    -1,    -1,    -1,   371,
     488,    -1,   374,   491,   516,   535,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   385,    -1,    -1,    -1,    -1,    -1,   391,
      -1,    -1,    -1,   511,    -1,    -1,   514,    -1,   516,   401,
      -1,   268,    -1,    -1,   406,    -1,   273,   409,    -1,    -1,
     412,    -1,    -1,    -1,    -1,    -1,    -1,   535,   560,   421,
     422,    -1,    -1,    -1,    -1,   567,    -1,   569,    -1,    -1,
      -1,    -1,    -1,    -1,   301,   553,    -1,   579,   580,   581,
      -1,    -1,   602,    -1,   171,    -1,   588,    -1,    -1,   591,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   599,    -1,    -1,
      -1,   463,    -1,    -1,    -1,   467,    -1,    -1,    -1,   336,
      -1,    -1,    -1,   475,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   348,    -1,    -1,   486,    -1,    -1,    -1,    -1,    -1,
     492,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   366,
      -1,    -1,    -1,    -1,   371,    -1,    -1,   374,    -1,    -1,
      -1,    -1,    -1,    -1,   516,    -1,    -1,    -1,   385,    -1,
      -1,    -1,    -1,    -1,   391,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   401,    -1,    -1,    -1,    -1,   406,
      -1,   268,   409,    17,    18,   412,   273,    -1,    -1,    23,
      24,    25,    -1,    -1,   421,   422,    -1,    -1,   560,    -1,
      -1,    -1,    -1,    -1,    38,   567,    -1,   569,    -1,    43,
      44,    -1,    -1,    -1,   301,    -1,    50,   579,   580,   581,
      -1,    -1,    -1,    -1,    -1,    -1,   588,    -1,    -1,   591,
      -1,    -1,    -1,    -1,    -1,   462,   463,   599,    -1,    -1,
     467,    -1,    -1,    -1,    78,    -1,    -1,    -1,   475,   336,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   486,
      -1,   348,    -1,    -1,    -1,   492,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   366,
      -1,    -1,    -1,    -1,   371,    -1,    -1,   374,    -1,   516,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   385,    -1,
      -1,    -1,    -1,    -1,   391,    17,    18,    -1,    -1,    -1,
      -1,    23,    24,    25,   401,    -1,    -1,    -1,    -1,   406,
      -1,    -1,   409,    -1,    -1,   412,    38,    -1,    -1,    -1,
      -1,    43,    44,   560,   421,   422,    -1,   171,    50,    -1,
     567,    -1,   569,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   579,   580,   581,    -1,    -1,    -1,    -1,    -1,
      -1,   588,    -1,    -1,   591,    -1,    78,    -1,    -1,    -1,
      -1,    -1,   599,    -1,    -1,    -1,   463,    -1,    -1,    -1,
     467,    -1,    -1,    -1,    -1,    -1,    17,    18,   475,    20,
      -1,    -1,    23,    24,    25,    -1,    -1,    -1,    -1,   486,
      -1,   488,    -1,    -1,    -1,   492,    -1,    -1,    -1,    -1,
      -1,    -1,    43,    -1,    -1,    -1,    17,    18,    -1,    20,
      -1,    -1,    23,    24,    25,    -1,    -1,    -1,    -1,   516,
      -1,    -1,    -1,    -1,   268,    -1,    -1,    -1,    -1,   273,
      -1,    -1,    43,    -1,    -1,    17,    18,    -1,    -1,    -1,
      -1,    23,    24,    25,    -1,    -1,    -1,    -1,    -1,   171,
      -1,    -1,    -1,    -1,    -1,    -1,    38,   301,    -1,    -1,
      -1,    43,    44,   560,    -1,    -1,    -1,    -1,    50,    -1,
     567,    -1,   569,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   579,   580,   581,    -1,    -1,    -1,    -1,    -1,
      -1,   588,   336,    -1,   591,    -1,    78,    -1,    -1,    -1,
      -1,    -1,   599,    -1,   348,    -1,    17,    18,    -1,    20,
      -1,    -1,    23,    24,    25,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   366,    -1,    -1,    -1,   370,   371,    -1,    -1,
     374,    -1,    43,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   385,    -1,    -1,    -1,    -1,   268,   391,    -1,    -1,
      -1,   273,    -1,    -1,    -1,    -1,    -1,   401,    -1,    -1,
      -1,    -1,   406,    -1,    -1,   409,    -1,    -1,   412,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   421,   422,   301,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   171,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    17,    18,    -1,    20,    -1,    -1,    23,    24,
      25,    -1,    -1,    -1,   336,    -1,    -1,    -1,    -1,   463,
      -1,    -1,    -1,   467,    -1,    -1,   348,    -1,    43,    -1,
      -1,   475,   273,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   486,    -1,   366,    -1,    -1,    -1,   492,   371,
      -1,    -1,   374,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   273,   385,    -1,    -1,    -1,    -1,    -1,   391,
      17,    18,   516,    20,    -1,    -1,    23,    24,    25,   401,
      -1,    -1,    -1,    -1,   406,    -1,   268,   409,    -1,    -1,
     412,   273,    -1,    -1,    -1,    -1,    43,    -1,    -1,   421,
     422,    17,    18,    -1,    20,    -1,    -1,    23,    24,    25,
      -1,    -1,    -1,    -1,    -1,    -1,   560,    -1,    -1,   301,
      -1,    -1,    -1,   567,    -1,   569,    -1,    43,    -1,    -1,
      -1,    -1,    -1,   374,    -1,   579,   580,   581,    -1,    -1,
     462,   463,    -1,    -1,   588,   467,    -1,   591,   389,    -1,
      -1,    -1,    -1,   475,   336,   599,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   374,   486,   406,   348,    -1,   409,    -1,
     492,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   389,    -1,
     421,   422,    -1,    -1,   366,    -1,    -1,    -1,    -1,   371,
      -1,    -1,   374,    -1,   516,   406,    -1,    -1,   409,    -1,
      -1,    -1,    -1,   385,    -1,    -1,    -1,    -1,    -1,   391,
     421,   422,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   401,
      -1,    -1,   463,    -1,   406,    -1,    -1,   409,    -1,    -1,
     412,    -1,    -1,    -1,   475,    -1,    -1,    -1,   560,   421,
     422,    -1,    -1,    -1,    -1,   567,    -1,   569,    -1,    -1,
      -1,    -1,   463,    -1,    -1,    -1,    -1,   579,   580,   581,
      -1,    -1,    -1,   374,   475,    -1,   588,    -1,    -1,   591,
      -1,    -1,    -1,    -1,    -1,   516,    -1,   599,   389,    -1,
      -1,   463,    -1,    -1,    -1,   467,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   475,    -1,   406,    -1,    -1,   409,    -1,
      -1,    -1,    -1,    -1,   486,   516,    -1,    -1,    -1,    -1,
     492,   422,    -1,    -1,   555,    -1,    17,    18,    -1,    20,
      -1,    -1,    23,    24,    25,    -1,   567,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   516,    -1,    -1,    -1,   579,   580,
     581,    -1,    43,    -1,   555,    -1,    -1,   588,    -1,    -1,
     591,    -1,   463,    -1,    -1,    -1,   567,    -1,   599,   374,
      -1,    -1,    -1,    -1,   475,    -1,    -1,    -1,   579,   580,
      -1,    -1,    -1,    -1,   389,    -1,    -1,   588,   560,    -1,
     591,    -1,    -1,    -1,    -1,   567,    -1,   569,   599,    -1,
      -1,   406,    -1,    -1,   409,    -1,    -1,   579,   580,   581,
      -1,    -1,    -1,    -1,    -1,   516,   588,   422,    -1,   591,
      -1,    -1,    -1,    17,    18,    -1,    20,   599,    -1,    23,
      24,    25,    -1,    -1,    -1,    -1,    -1,   374,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   549,    43,
      -1,    -1,   389,    -1,   555,    -1,    -1,   462,   463,    -1,
      -1,    -1,    -1,   564,   565,    -1,   567,    -1,   374,   406,
     475,    -1,   409,    -1,    -1,    -1,    -1,    -1,   579,   580,
      -1,    -1,    -1,   389,    -1,   422,    -1,   588,    17,    18,
     591,    20,    -1,    -1,    23,    24,    25,    -1,   599,    -1,
     406,    -1,    -1,   409,    -1,    -1,    -1,    -1,    -1,    77,
      -1,   516,    -1,   450,    43,    -1,   422,    -1,    52,    53,
      -1,    -1,    56,    57,    58,    -1,   463,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   475,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     555,    -1,    -1,    -1,    -1,    -1,   462,   463,    -1,    -1,
      -1,    -1,   567,    -1,    -1,    -1,    -1,    -1,    -1,   475,
      -1,    -1,    -1,    -1,   579,   580,    -1,    -1,    -1,   516,
      -1,    -1,    -1,   588,    -1,    -1,   591,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   599,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     516,    -1,    -1,    -1,   182,    -1,    -1,    -1,   555,    -1,
      -1,    -1,   156,    -1,    -1,    -1,    -1,    -1,    -1,   163,
     567,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   579,   580,    -1,    -1,    -1,    -1,    -1,   555,
      -1,   588,    -1,    -1,   591,    -1,    -1,    -1,    -1,    -1,
      -1,   567,   599,   197,    -1,    -1,    -1,    -1,    -1,    -1,
     238,    -1,   206,   579,   580,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   588,   374,    -1,   591,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   599,    -1,   263,    -1,    -1,   389,    -1,
      -1,   235,   236,    -1,   272,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   406,    -1,    -1,   409,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   422,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     308,    -1,    -1,   311,    -1,    -1,   280,    -1,   316,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   324,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   462,   463,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     374,    -1,    -1,    -1,   475,    -1,    -1,    -1,   322,    -1,
      -1,    -1,    -1,    -1,    -1,   389,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   406,    -1,    -1,   409,    -1,    -1,    -1,    -1,
     388,    -1,    -1,    -1,    -1,   516,    -1,   395,   422,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   410,    -1,   378,   374,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     389,    -1,    -1,    -1,   555,    -1,   434,    -1,   462,   463,
      -1,    -1,    -1,    -1,    -1,    -1,   567,   406,    -1,    -1,
     409,   475,    -1,    -1,    -1,    -1,    -1,    -1,   579,   580,
      -1,   459,    -1,   422,    -1,    -1,    -1,   588,    -1,    -1,
     591,   469,   470,    -1,    -1,    -1,    -1,    -1,   599,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   485,    -1,    -1,
      -1,    -1,   516,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   463,    -1,    -1,    -1,   506,    -1,
      -1,   509,   510,    -1,    -1,    -1,   475,   515,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   555,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   567,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   579,   580,   516,    -1,    -1,
      -1,    -1,    -1,    -1,   588,    -1,    -1,   591,    -1,    -1,
      -1,    -1,    -1,    -1,   572,   599,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   582,    -1,   584,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   555,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   567,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     579,   580,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   588,
      -1,    -1,   591,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     599,    -1,    -1,   607,   608,   609,   610,   611,   612,   613,
     614,   615,   616
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
    1214,  1215,  1216,  1217,  1222,  1228,  1229,  1247,  1250,  1290,
    1291,  1383,  1384,  1414,  1415,  1422,  1438,  1442,  1447,  1449,
    1451,  1455,  1456,  1463,   705,  1017,  1438,   604,   627,  1062,
    1063,  1089,    20,   370,   404,   750,   773,    25,   778,    25,
      25,    25,   795,   797,   789,   753,    25,   405,    20,   750,
     409,    25,    25,   747,    25,   599,   370,     5,  1089,   370,
     915,   916,   919,   915,   910,   916,   910,    24,   591,   915,
    1102,  1433,  1434,  1435,   915,  1453,   915,  1224,  1225,   915,
      25,   652,  1073,  1220,   910,   915,  1146,   842,    25,   923,
    1185,  1186,  1185,    17,    18,    24,    25,    38,    43,    44,
      50,    78,   171,   268,   273,   301,   336,   348,   366,   371,
     374,   385,   391,   401,   406,   409,   412,   421,   422,   463,
     467,   475,   486,   492,   516,   560,   567,   569,   579,   580,
     581,   588,   817,   824,   825,   826,   827,   828,   829,   830,
     831,   843,   848,   859,   860,   861,   862,   915,   923,  1073,
    1180,  1249,  1374,   916,  1423,  1423,   803,  1146,   910,  1218,
    1073,   912,   916,   824,  1423,  1073,  1146,  1073,  1248,  1423,
      24,   564,  1056,  1057,  1073,   910,   910,  1056,   911,   916,
     915,  1057,   910,  1423,   910,   912,  1073,  1103,  1104,   908,
     916,   912,   353,   540,   646,   907,   915,   978,   915,   713,
     913,   916,  1433,  1070,   842,   916,  1129,   872,   107,   116,
     125,   130,   174,   182,   238,   263,   270,   272,   282,   308,
     316,   353,   379,   417,   428,   527,   528,   529,   540,   644,
     990,  1124,  1125,  1073,   823,   824,  1138,   819,   842,   907,
    1448,  1448,   909,   916,   842,    24,  1073,  1127,  1199,  1073,
    1176,    24,  1073,  1417,   824,  1167,  1168,  1169,  1178,  1179,
     824,  1443,    44,    83,   133,   171,   268,   344,   385,   453,
     516,   669,   848,   915,  1073,  1208,   692,   824,   908,  1440,
    1043,   824,   908,   824,  1073,  1000,   908,   824,   824,  1185,
     915,   927,   928,   912,   927,  1448,   912,   927,  1448,   933,
     927,    24,    25,   363,   466,   923,   981,  1073,  1091,  1093,
      45,   253,   323,   368,   547,   628,   629,   630,   639,   659,
     935,   937,   939,   941,   943,  1067,  1068,  1072,   314,   325,
     377,   392,   482,  1292,   619,   620,   879,   880,   881,   915,
    1064,   626,  1063,   370,   281,   370,   370,   370,   370,   603,
       5,   370,   281,   738,   758,   759,   370,   370,   603,   370,
     915,  1203,  1092,   370,  1193,    35,    36,    63,    64,    65,
     433,   520,   563,  1230,  1231,  1232,  1235,  1238,  1241,  1242,
    1243,  1244,   328,   917,  1457,   599,  1435,   437,   596,  1121,
     599,     8,   517,   566,     5,   370,   405,    24,   915,  1368,
     458,  1147,  1091,    87,    88,    89,   817,   817,   409,   504,
    1197,   409,   409,   409,   409,   409,   409,   409,   409,   409,
     409,   817,   345,   432,   449,   492,   531,   560,   569,  1377,
    1378,   409,   409,   409,   817,   817,   409,   409,   729,   817,
     409,   832,   409,   409,   409,   409,   409,   409,   409,   817,
     409,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    71,    72,    73,
      74,    75,    76,    87,    88,    89,   228,   231,   350,   365,
     369,   407,   435,   454,   535,   602,   728,   818,   833,   835,
     836,   837,   838,   839,   840,   841,    25,   923,   409,   399,
    1073,  1098,  1368,   658,   659,   806,   245,    66,    67,   605,
     438,     5,   598,   605,   597,   597,  1106,   574,   399,     5,
     535,   954,   438,   638,  1445,   409,   437,   599,   638,   363,
     715,  1073,   525,   597,  1111,  1112,  1113,   305,  1289,   823,
     822,   824,     8,   909,    25,   480,   533,   902,  1073,   902,
     902,   902,   995,   996,   902,   902,   575,   991,   659,   991,
     991,   903,   903,   991,   991,   659,     5,   312,   364,     5,
     658,   462,   820,   821,   824,     5,    55,    61,   518,   606,
     984,   641,  1446,   823,   592,   593,   594,   595,  1175,  1177,
     362,  1212,  1177,  1169,     5,   597,  1170,   824,   409,   409,
     409,   409,   409,    24,   688,   915,   409,  1417,   323,   409,
     568,   557,   693,   700,   691,    24,  1058,  1073,  1163,     8,
    1166,    13,   915,  1078,  1085,  1086,  1088,  1096,  1097,  1140,
     141,   323,   523,   556,   554,     5,   638,   638,   822,  1091,
    1098,   980,   399,     5,   129,   958,   409,  1073,   822,   409,
      25,    25,    45,  1071,    24,  1073,  1421,  1421,   909,  1129,
     909,    97,   200,   208,   214,   216,   227,   255,   271,   276,
     288,   295,   450,   457,   479,   484,  1251,  1262,  1263,  1271,
    1280,  1281,  1287,  1288,  1293,  1294,  1303,  1322,  1326,  1394,
    1395,  1424,  1425,  1428,  1429,   882,   883,    70,   878,   889,
     890,   881,  1065,  1458,  1023,   437,   786,   753,   437,     5,
     370,   760,   732,  1040,   732,   136,   275,   351,   409,   471,
    1309,  1321,   409,   915,  1246,    25,   224,   237,   409,   455,
     471,   915,  1227,  1240,  1307,  1308,  1313,  1315,  1317,   409,
     915,  1237,   409,  1227,  1233,     5,   409,   920,  1435,  1083,
    1433,   555,   596,  1122,    20,   915,  1102,  1436,   915,  1454,
    1225,   574,   599,   568,   409,   409,   806,   907,   817,   846,
     907,   907,   907,  1448,   450,  1398,   817,    24,    25,    18,
      23,    24,    25,   863,   864,   865,   866,   817,   409,   605,
     907,    20,   817,   370,  1398,   817,    20,  1180,   851,   849,
     855,   817,   853,   817,   817,   817,   817,   817,   817,   817,
     817,   817,   817,   817,   817,   817,   817,   817,   817,   817,
     817,   817,   817,   817,   409,   817,   817,   409,   844,  1073,
     605,   409,  1433,    24,   922,  1145,  1145,  1417,  1056,   824,
     824,   824,   904,   905,   409,  1073,  1104,   767,   955,   956,
     605,  1417,  1448,  1446,   915,   655,    20,   646,   915,   978,
    1073,   714,   604,   824,   329,  1115,   535,  1114,     5,    47,
      49,    51,   597,   605,   798,  1091,   873,    17,    18,    24,
     283,   289,   290,   291,   309,   417,   420,   444,   464,   499,
     518,   519,   534,   573,   606,   997,   992,  1125,   903,   824,
     323,   574,     5,   907,    25,    25,   658,   131,  1174,   197,
    1179,  1185,  1444,   678,   915,    24,   907,  1448,   568,   907,
     602,  1073,   673,   915,   824,   318,   696,   700,   557,   694,
     702,    22,   213,  1045,  1049,   461,   842,   461,  1164,   824,
     436,  1082,   919,     5,  1001,   525,  1141,  1073,   946,   928,
    1448,  1448,   938,   939,   958,   958,   249,   252,   254,   274,
     284,   326,   330,   408,   460,   643,   957,   959,   960,   986,
    1073,  1093,   525,   660,    25,   378,   944,   300,  1416,  1416,
     114,   115,   415,   525,   915,  1323,  1324,  1369,   767,  1368,
    1368,  1264,   767,   915,  1426,  1426,   338,   455,   564,  1406,
    1368,  1272,   147,   417,   428,   450,   457,  1296,  1297,  1298,
     266,   267,  1389,  1458,  1458,   363,   891,  1073,   621,   622,
     884,   885,   886,   460,   604,   623,   624,   643,   894,   895,
    1458,   732,    25,   751,   751,   759,  1204,   732,  1194,  1311,
    1368,  1245,  1321,   409,  1245,   409,   409,  1239,  1240,   409,
     409,    42,   278,   336,   348,   358,   376,   386,   389,   402,
     451,   481,   491,   511,   514,   516,   544,   553,  1360,  1361,
    1362,  1364,  1236,  1237,  1233,  1234,   643,  1231,    24,   918,
    1076,   599,   405,  1417,   555,   525,  1452,   653,   654,   915,
     915,   915,  1221,   842,   370,   685,   686,   687,   817,   370,
     370,   370,   370,  1406,   370,   370,   370,   370,   568,   864,
      18,    25,   568,   370,   370,    25,   345,   432,   449,   492,
     531,   560,   569,  1379,   370,   370,   370,   370,     5,   730,
     370,   817,   817,   817,   370,   817,   370,   370,   370,   842,
    1398,   842,  1398,   685,   915,  1219,   596,  1118,   605,     5,
       5,     5,   558,   824,   599,     5,   462,   605,   370,   405,
     409,   604,   142,   146,   249,   252,   716,   719,   720,   986,
     717,   718,   915,   409,   916,   628,   629,  1119,   824,   915,
     915,   905,   906,   488,  1448,   806,   532,  1277,    25,    25,
     409,   993,   995,  1073,   514,  1133,   820,    45,   817,  1177,
      25,  1073,  1458,   685,   370,     5,   370,   370,   689,   915,
     370,  1417,   685,   409,   701,   697,   339,   695,   824,   318,
     698,   702,   575,   988,  1050,  1046,   341,  1044,  1045,   822,
     605,  1079,   599,  1097,    13,    17,    18,    20,    24,    25,
      43,   374,   389,   406,   409,   422,   462,   463,   475,   516,
     555,   567,   579,   580,   588,   915,   923,  1142,  1143,  1373,
    1375,  1410,  1411,  1434,  1437,  1458,   940,   941,   529,   914,
     525,   907,   974,   907,   975,   967,   966,   964,   963,   987,
     417,   428,   970,   971,   417,   428,   972,   973,   303,   960,
     965,  1448,    77,   311,   324,   388,   395,   434,   459,   469,
     470,   485,   506,   509,   510,   515,   572,   584,   661,   662,
       5,    25,  1417,   227,   450,  1399,  1400,  1417,  1129,  1393,
    1395,    79,    79,   574,  1127,  1325,  1326,   409,  1304,   128,
     504,  1330,  1337,  1368,   154,   250,  1430,   599,   605,  1407,
    1408,  1410,  1252,   320,   329,   353,   356,   374,   480,   533,
     540,   909,  1274,  1279,   409,  1299,   604,     5,    24,   915,
    1390,  1391,   893,  1073,     5,   525,   887,   888,   618,   886,
     892,   915,   892,   896,   897,   892,   303,   895,  1024,   405,
     405,   439,  1187,  1207,  1041,   439,  1150,  1181,   409,     5,
     370,   273,   409,   421,   581,  1340,  1341,  1342,  1343,  1344,
    1345,  1352,  1356,  1358,  1405,  1410,   370,   915,  1310,  1312,
    1368,  1371,  1314,  1371,     5,   370,  1314,  1340,   345,   432,
     449,   492,   531,   560,   569,  1380,  1380,   409,   409,   409,
     409,   409,   409,   186,   378,  1316,  1318,     5,   370,     5,
     370,   915,   370,  1436,     8,  1417,   824,     5,  1226,  1227,
     842,  1030,   847,     5,  1407,   857,  1378,   857,    25,    25,
     568,    23,    25,   770,   858,  1197,   370,   409,  1197,   771,
     370,  1197,   852,   850,   856,  1197,   854,  1197,  1197,  1197,
     817,   834,   370,   834,   370,   845,   599,  1226,   555,  1417,
    1417,   824,   824,   904,   488,   824,  1450,     5,    20,  1371,
     956,  1417,   599,   915,   717,   725,   724,   726,   915,   921,
     727,   921,   170,   720,   723,     5,   958,   599,   824,     8,
     915,  1278,   874,   994,   995,  1073,     5,   304,   679,  1209,
     323,   323,   437,   599,   323,   409,   674,   671,  1458,  1458,
     703,   699,   695,   989,    24,   914,  1051,  1073,  1458,   824,
     404,    20,   915,  1087,   842,    25,   923,    25,   923,  1376,
    1380,  1410,   409,   409,   919,   409,   409,   409,   409,   409,
       5,    17,    18,    19,    20,    71,    72,    73,    74,    75,
      76,  1431,   399,    41,   521,   947,   942,   943,    25,   658,
     915,     5,   961,     5,   962,  1458,  1458,  1458,  1458,   993,
       5,   969,     5,   968,  1458,   914,     5,   370,    25,  1368,
     919,  1387,   574,   574,  1263,  1392,  1393,  1326,  1305,  1371,
     596,   909,  1340,   409,  1267,   915,  1427,  1426,     5,  1396,
     259,   299,   300,   301,   324,   332,   337,   352,   357,   359,
     366,   369,   372,   375,   378,   383,   401,   417,   420,   421,
     427,   438,   454,   461,   468,   471,   472,   473,   475,   476,
     492,   515,   516,   517,   518,   520,   537,   538,   560,   569,
     570,   572,   634,   924,  1457,   562,   824,   824,  1273,   909,
    1300,  1371,  1368,  1298,   599,   599,     5,     5,  1073,   892,
    1458,  1458,     5,   899,   900,  1458,  1458,   898,  1017,   790,
     748,    52,    53,    56,    57,    58,   156,   163,   197,   206,
     235,   236,   280,   322,   378,   607,   608,   609,   610,   611,
     612,   613,   614,   615,   616,  1184,  1188,   113,   493,  1189,
    1205,  1017,   138,   155,   156,   163,   197,   206,   235,   280,
     322,  1182,  1183,  1195,  1189,  1312,  1321,   409,  1405,   450,
    1340,  1410,  1405,  1343,     6,   370,     7,     9,    11,    12,
      13,    14,    15,    16,   231,   350,   535,  1357,   407,   581,
     602,  1355,  1357,   437,  1370,   370,     5,   919,     5,   370,
    1240,   370,   370,   605,   409,   605,    25,  1366,  1366,    25,
    1366,  1366,    25,  1365,    24,  1373,  1319,  1320,  1321,  1237,
    1233,  1417,     8,   654,     5,   370,   822,   370,   370,   687,
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
    1268,  1371,   458,  1265,  1404,   605,  1408,   532,  1403,    20,
     409,  1255,  1256,  1257,  1258,  1371,   532,  1275,     5,   370,
     605,   915,   915,  1391,  1073,   915,  1458,  1458,  1458,  1458,
     603,   603,  1185,  1185,  1185,    24,  1185,  1185,  1185,  1185,
    1185,  1185,    24,    24,  1185,  1188,  1073,  1099,  1100,   598,
     425,  1151,  1458,    24,    24,    25,    25,    25,    25,    25,
      24,  1073,  1183,  1151,   370,   919,   370,  1341,  1342,  1410,
     409,  1405,   409,  1405,   228,   365,   367,   535,   409,   549,
     564,   565,  1346,  1347,  1348,  1405,  1410,    25,  1309,  1371,
     599,  1371,   345,   432,   449,   492,   531,   560,   569,  1381,
      25,  1381,     5,  1363,  1363,     5,   370,   370,  1363,   370,
    1321,  1417,  1227,   247,  1223,   494,  1332,  1333,  1334,  1368,
    1337,   310,   493,   503,  1282,  1401,  1379,   857,   568,    23,
      25,   370,   774,   817,   447,   805,     5,   352,  1417,     5,
     409,   370,   529,   985,   921,  1458,   655,    20,   915,   921,
    1458,  1448,   824,  1448,   399,     5,   219,   995,   658,   323,
     683,  1210,  1091,   405,   685,   675,   370,  1458,   914,   824,
     868,  1083,  1381,     5,  1380,     5,   370,  1410,   919,  1410,
    1410,  1410,  1410,     5,   370,   824,  1458,   936,   937,    20,
     915,  1419,  1420,  1407,  1388,  1386,  1389,  1371,   919,   118,
    1306,     5,   370,  1266,  1427,  1094,  1397,    13,  1257,  1259,
    1253,     5,    13,  1276,  1371,   441,  1301,  1302,  1369,   599,
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
    1389,  1406,  1371,   409,  1336,   409,   462,  1260,  1261,  1405,
    1410,     5,   370,   128,   504,  1254,  1258,  1261,  1094,     5,
     119,  1295,   915,  1100,  1154,  1155,  1073,  1157,  1073,  1156,
    1158,  1153,   218,   218,  1407,     5,   370,   370,     7,   420,
    1349,    25,  1370,   605,   370,  1333,  1335,  1333,  1329,  1409,
    1410,   426,  1327,  1339,  1223,    25,  1283,  1284,  1285,  1371,
    1399,  1402,   804,  1417,   371,   182,   238,   263,   272,   308,
     316,   410,   582,   662,   666,   667,   409,   599,   658,   986,
    1134,  1135,  1136,  1211,   680,   370,   683,  1458,   869,   605,
    1381,   605,   370,   950,   982,  1420,  1336,  1407,   462,  1269,
    1270,  1410,  1401,  1260,  1410,     5,  1257,    13,   909,  1340,
    1302,  1458,  1458,  1159,  1458,  1160,  1458,  1458,  1336,  1354,
    1410,  1351,  1413,   405,  1381,     5,   370,     5,  1340,     5,
     517,   566,  1286,  1223,   326,   330,   807,   808,   809,   986,
     902,   902,   902,   902,   902,   902,    24,     5,   370,   824,
      20,   915,  1137,   261,  1136,   683,   685,   683,   220,  1381,
    1381,  1458,   658,  1401,  1336,     5,   370,   370,  1261,   409,
    1458,  1458,   370,  1333,  1409,  1284,   811,   810,   217,   809,
     812,   667,     5,  1458,   681,   947,  1270,  1260,  1458,  1458,
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
#line 881 "fgl.yacc"
    { print_screen_mode(0);}
    break;

  case 3:
#line 884 "fgl.yacc"
    { print_screen_mode(1);}
    break;

  case 4:
#line 888 "fgl.yacc"
    {
		print_start_server(yyvsp[-3].str,yyvsp[0].str);
	}
    break;

  case 5:
#line 894 "fgl.yacc"
    {
	print_stop_external();
	}
    break;

  case 6:
#line 899 "fgl.yacc"
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
#line 911 "fgl.yacc"
    {
	sprintf(yyval.str,"%s%s",yyvsp[-2].str,yyvsp[0].str);
	}
    break;

  case 10:
#line 916 "fgl.yacc"
    {
	print_remote_func(yyvsp[0].str);
	sprintf(yyval.str,"unregister_func(\"%s\",aclfgl_%s);\n",yyvsp[0].str,yyvsp[0].str);
	addmap("Call Remote",yyvsp[0].str,curr_func,yylineno,infilename);
	}
    break;

  case 11:
#line 934 "fgl.yacc"
    {sprintf(yyval.str,"(%s)",yyvsp[-1].str);}
    break;

  case 12:
#line 935 "fgl.yacc"
    { sprintf(yyval.str,"%s%s%s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 13:
#line 936 "fgl.yacc"
    {sprintf(yyval.str,"%d",atoi(yyvsp[0].str));}
    break;

  case 14:
#line 937 "fgl.yacc"
    {sprintf(yyval.str,"(%s%s)",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 15:
#line 938 "fgl.yacc"
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
#line 952 "fgl.yacc"
    {strcpy(yyval.str,"+");}
    break;

  case 17:
#line 953 "fgl.yacc"
    {strcpy(yyval.str,"-");}
    break;

  case 18:
#line 954 "fgl.yacc"
    {strcpy(yyval.str,"*");}
    break;

  case 19:
#line 955 "fgl.yacc"
    {strcpy(yyval.str,"/");}
    break;

  case 20:
#line 956 "fgl.yacc"
    {strcpy(yyval.str,"%");}
    break;

  case 21:
#line 961 "fgl.yacc"
    {strcpy(yyval.str,"+");}
    break;

  case 22:
#line 962 "fgl.yacc"
    {strcpy(yyval.str,"-");}
    break;

  case 23:
#line 973 "fgl.yacc"
    {
		debug("Using default attribute of WHITE");
		sprintf(yyval.str,"%d",0);}
    break;

  case 24:
#line 976 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 25:
#line 979 "fgl.yacc"
    {start_state("attribute",1);}
    break;

  case 26:
#line 979 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[-1].str);
debug("Got Attributes : %s",yyvsp[-1].str);
start_state("attribute",0);
}
    break;

  case 28:
#line 986 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 29:
#line 987 "fgl.yacc"
    {
sprintf(yyval.str,"%d",atoi(yyvsp[-2].str)|atoi(yyvsp[0].str));
}
    break;

  case 30:
#line 993 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("BLACK"));}
    break;

  case 31:
#line 994 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("BLUE"));}
    break;

  case 32:
#line 995 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("CYAN"));}
    break;

  case 33:
#line 996 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("GREEN"));}
    break;

  case 34:
#line 997 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("MAGENTA"));}
    break;

  case 35:
#line 998 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("RED"));}
    break;

  case 36:
#line 999 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("WHITE"));}
    break;

  case 37:
#line 1000 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("YELLOW"));}
    break;

  case 38:
#line 1001 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("REVERSE"));}
    break;

  case 39:
#line 1002 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("BLINK"));}
    break;

  case 40:
#line 1003 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("UNDERLINE"));}
    break;

  case 41:
#line 1004 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("BOLD"));}
    break;

  case 42:
#line 1005 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("NORMAL"));}
    break;

  case 43:
#line 1006 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("INVISIBLE"));}
    break;

  case 44:
#line 1007 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("DIM"));}
    break;

  case 45:
#line 1008 "fgl.yacc"
    {inp_flags=inp_flags | 0x1; strcpy(yyval.str,"0");}
    break;

  case 48:
#line 1015 "fgl.yacc"
    {
debug("win_attributes_def");
start_state("attribute",1);
debug("Started states");
form_attrib.attrib=0;}
    break;

  case 49:
#line 1019 "fgl.yacc"
    {start_state("attribute",0);strcpy(yyval.str,"");
}
    break;

  case 50:
#line 1023 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 51:
#line 1024 "fgl.yacc"
    {sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 52:
#line 1028 "fgl.yacc"
    { 
/*printf("Window attribute = %s\n",$<str>1);*/
form_attrib.attrib      =form_attrib.attrib|atoi(yyvsp[0].str);
/*printf("Window attribute = %d\n",form_attrib.attrib);*/
}
    break;

  case 53:
#line 1034 "fgl.yacc"
    { form_attrib.border      =1;}
    break;

  case 54:
#line 1036 "fgl.yacc"
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
#line 1047 "fgl.yacc"
    { form_attrib.comment_line=atoi(yyvsp[0].str); }
    break;

  case 56:
#line 1049 "fgl.yacc"
    { form_attrib.form_line   =atoi(yyvsp[0].str); }
    break;

  case 57:
#line 1051 "fgl.yacc"
    { form_attrib.error_line  =atoi(yyvsp[0].str); }
    break;

  case 58:
#line 1053 "fgl.yacc"
    { form_attrib.menu_line   =atoi(yyvsp[0].str); 
debug("Set menu line to %s",yyvsp[0].str);
}
    break;

  case 59:
#line 1057 "fgl.yacc"
    { form_attrib.message_line=atoi(yyvsp[0].str); }
    break;

  case 60:
#line 1059 "fgl.yacc"
    { form_attrib.prompt_line =atoi(yyvsp[0].str); }
    break;

  case 61:
#line 1120 "fgl.yacc"
    {strcpy(yyval.str,"CALL");}
    break;

  case 62:
#line 1124 "fgl.yacc"
    { debug("print_expr (3)"); 
		print_expr(yyvsp[-2].ptr);
		print_pop_variable(yyvsp[0].str);
	}
    break;

  case 63:
#line 1128 "fgl.yacc"
    {
	print_getfldbuf(yyvsp[-2].str);
	}
    break;

  case 64:
#line 1131 "fgl.yacc"
    {
	print_returning();
}
    break;

  case 65:
#line 1135 "fgl.yacc"
    {
	print_form_is_compiled(yyvsp[-1].str);
	}
    break;

  case 66:
#line 1139 "fgl.yacc"
    {
	print_field_func('I',yyvsp[-3].str,yyvsp[0].str);
   }
    break;

  case 68:
#line 1143 "fgl.yacc"
    { 
	print_field_func('T',yyvsp[-3].str,yyvsp[0].str);
     }
    break;

  case 69:
#line 1146 "fgl.yacc"
    {
	new_counter();
   	addmap("Call",yyvsp[-3].str,curr_func,yylineno,infilename);
   }
    break;

  case 70:
#line 1152 "fgl.yacc"
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
#line 1161 "fgl.yacc"
    {
	print_returning();
	strcpy(yyval.str,yyvsp[-4].str); /* ? */
   }
    break;

  case 72:
#line 1165 "fgl.yacc"
    {
	new_counter();
   	addmap("Call",yyvsp[-1].str,curr_func,yylineno,infilename);
   }
    break;

  case 73:
#line 1170 "fgl.yacc"
    {
	debug("Got args");
   }
    break;

  case 74:
#line 1174 "fgl.yacc"
    {
	int a;
	dump_expr(yyvsp[-2].ptr);
	a=get_counter_val();
	drop_counter();
  	print_func_call(yyvsp[-5].str,yyvsp[-2].ptr,a);
   }
    break;

  case 75:
#line 1182 "fgl.yacc"
    {
	print_returning();
	strcpy(yyval.str,yyvsp[-3].str); /* ? */
   }
    break;

  case 76:
#line 1186 "fgl.yacc"
    {
	A4GLSQL_set_status(0,0);
	new_counter();
	}
    break;

  case 77:
#line 1190 "fgl.yacc"
    {
   sprintf(yyval.str,"%d",get_counter_val());drop_counter();
}
    break;

  case 78:
#line 1193 "fgl.yacc"
    {
        print_expr ((struct expr_str *)yyvsp[-3].ptr);  
	print_call_shared(yyvsp[-6].str,yyvsp[-8].str,atoi(yyvsp[-2].str));
	print_returning();
	print_end_call_shared();
}
    break;

  case 79:
#line 1199 "fgl.yacc"
    {
	sprintf(yyval.str,"\"%s\",\"%s\"",get_idents(0),get_idents(1));
	A4GLSQL_set_status(0,0);
	new_counter();
	}
    break;

  case 80:
#line 1204 "fgl.yacc"
    {
   	sprintf(yyval.str,"%d",get_counter_val());drop_counter();
}
    break;

  case 81:
#line 1207 "fgl.yacc"
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
#line 1223 "fgl.yacc"
    {
   char buff[256];
   new_counter();
   sprintf(buff,"%s:%s(%p)",yyvsp[-6].str,yyvsp[-4].str,yyvsp[-2].str);
   addmap("External",buff,curr_func,yylineno,infilename);
   }
    break;

  case 83:
#line 1230 "fgl.yacc"
    {
   sprintf(yyval.str,"%d",get_counter_val());drop_counter();
   }
    break;

  case 84:
#line 1234 "fgl.yacc"
    {
	 debug("print_expr (6)");print_expr(yyvsp[-2].ptr);
   }
    break;

  case 85:
#line 1238 "fgl.yacc"
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
#line 1260 "fgl.yacc"
    {start_bind('i',0);strcpy(yyval.str,"0");}
    break;

  case 87:
#line 1260 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);
}
    break;

  case 88:
#line 1264 "fgl.yacc"
    {start_bind('i',0);strcpy(yyval.str,"0");}
    break;

  case 89:
#line 1265 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 90:
#line 1266 "fgl.yacc"
    {strcpy(yyval.str,"WITHOUT WAITING"); }
    break;

  case 91:
#line 1271 "fgl.yacc"
    {
			yyval.ptr=new_expr("");
		}
    break;

  case 92:
#line 1274 "fgl.yacc"
    {
			yyval.ptr=yyvsp[0].ptr;
		}
    break;

  case 93:
#line 1280 "fgl.yacc"
    {
	yyval.ptr=yyvsp[0].ptr;
}
    break;

  case 94:
#line 1283 "fgl.yacc"
    {
		yyval.ptr=append_expr_expr(yyvsp[-2].ptr,yyvsp[0].ptr);
}
    break;

  case 97:
#line 1295 "fgl.yacc"
    {
sprintf(yyval.str,"\"%s\"",yyvsp[0].str);
}
    break;

  case 98:
#line 1301 "fgl.yacc"
    {
sprintf(yyval.str,"\"%s\"",yyvsp[0].str);
}
    break;

  case 99:
#line 1304 "fgl.yacc"
    { sprintf(yyval.str,"\"%s.%s\"",yyvsp[-2].str,yyvsp[0].str); }
    break;

  case 100:
#line 1319 "fgl.yacc"
    {
push_blockcommand("CASE");
setinc(1);
incprint();
print_case(1);
setinc(1);
}
    break;

  case 101:
#line 1329 "fgl.yacc"
    {
print_after_when(0);
pop_blockcommand("CASE");
}
    break;

  case 102:
#line 1335 "fgl.yacc"
    {  push_blockcommand("CASE"); 
setinc(1);
incprint(); 
print_case(0);
setinc(1);
}
    break;

  case 103:
#line 1344 "fgl.yacc"
    {
print_after_when(0);
pop_blockcommand("CASE");
}
    break;

  case 108:
#line 1357 "fgl.yacc"
    {setinc(-1);incprint();}
    break;

  case 110:
#line 1360 "fgl.yacc"
    {
incprint();
}
    break;

  case 111:
#line 1362 "fgl.yacc"
    {incprint();
print_after_when(0);
}
    break;

  case 113:
#line 1368 "fgl.yacc"
    {incprint();}
    break;

  case 114:
#line 1370 "fgl.yacc"
    {incprint();
print_after_when(0);
}
    break;

  case 115:
#line 1375 "fgl.yacc"
    {
print_when(0);

incprint();
}
    break;

  case 116:
#line 1380 "fgl.yacc"
    {incprint();
print_after_when(1);
setinc(-1);}
    break;

  case 117:
#line 1386 "fgl.yacc"
    {
incprint();
print_when(1);
}
    break;

  case 118:
#line 1390 "fgl.yacc"
    {incprint();
print_after_when(1);
setinc(-1);}
    break;

  case 119:
#line 1405 "fgl.yacc"
    {
  print_close('F',yyvsp[0].str);
 }
    break;

  case 120:
#line 1408 "fgl.yacc"
    {
  print_close('W',yyvsp[0].str);
}
    break;

  case 121:
#line 1411 "fgl.yacc"
    {
  print_close('W',yyvsp[0].str);
}
    break;

  case 122:
#line 1414 "fgl.yacc"
    {
  print_close('D',0);
}
    break;

  case 123:
#line 1417 "fgl.yacc"
    {
  print_close('S',yyvsp[0].str);
}
    break;

  case 124:
#line 1420 "fgl.yacc"
    {
  print_close('C',yyvsp[0].str);
}
    break;

  case 130:
#line 1442 "fgl.yacc"
    {
			lex_printc("%s",yyvsp[0].str);
}
    break;

  case 133:
#line 1451 "fgl.yacc"
    {
			lex_printc("%s\n",yyvsp[0].str);
}
    break;

  case 134:
#line 1461 "fgl.yacc"
    {
/* This aint used - its filtered by the lexer first... */
	lex_printc("FIXME : Comment : %s\n");
}
    break;

  case 135:
#line 1475 "fgl.yacc"
    {
push_blockcommand("CONSTRUCT");
}
    break;

  case 136:
#line 1479 "fgl.yacc"
    {
	print_construct_1();
}
    break;

  case 137:
#line 1482 "fgl.yacc"
    {
	print_construct_2(yyvsp[-2].str);
}
    break;

  case 138:
#line 1490 "fgl.yacc"
    {
	print_construct_3(1,yyvsp[-5].str,yyvsp[0].str);
	strcpy(yyval.str,"form_loop(&_inp_io)"); /* FIXME */
	reset_constr();
}
    break;

  case 139:
#line 1496 "fgl.yacc"
    {
	print_construct_3(0,yyvsp[-7].str,yyvsp[0].str);
	strcpy(yyval.str,"form_loop(&_inp_io)"); /* FIXME */
	reset_constr();
}
    break;

  case 144:
#line 1511 "fgl.yacc"
    {
                push_construct("",yyval.str);
             }
    break;

  case 145:
#line 1515 "fgl.yacc"
    {
                sprintf(yyval.str,"%s.%s",yyvsp[-2].str,yyvsp[0].str);
                push_construct(yyvsp[-2].str,yyvsp[0].str); 
             }
    break;

  case 146:
#line 1520 "fgl.yacc"
    {
                push_construct(yyvsp[-2].str,"*");
             }
    break;

  case 149:
#line 1530 "fgl.yacc"
    {
		print_befaft_field_1(yyvsp[0].str);
	}
    break;

  case 150:
#line 1533 "fgl.yacc"
    {
		print_befaft_field_2();

	}
    break;

  case 151:
#line 1537 "fgl.yacc"
    {
		print_befaft_field_1(yyvsp[0].str);
	}
    break;

  case 152:
#line 1539 "fgl.yacc"
    {
		print_befaft_field_2();
	}
    break;

  case 153:
#line 1542 "fgl.yacc"
    {
		print_onkey_1(yyvsp[0].str);
	}
    break;

  case 154:
#line 1544 "fgl.yacc"
    {
		print_onkey_2();
	}
    break;

  case 155:
#line 1547 "fgl.yacc"
    {
		print_befaft_field_1("AFTER_INP");
	}
    break;

  case 156:
#line 1549 "fgl.yacc"
    {
		print_befaft_field_2();
	}
    break;

  case 157:
#line 1552 "fgl.yacc"
    {
		print_befaft_field_1("BEFORE_INP");
		}
    break;

  case 158:
#line 1555 "fgl.yacc"
    {
		print_befaft_field_2();
	}
    break;

  case 159:
#line 1565 "fgl.yacc"
    {sprintf(yyval.str,"BEF_FIELD_CHK(%s)",yyvsp[0].str);}
    break;

  case 160:
#line 1566 "fgl.yacc"
    {
	  char buff[80];
	  sprintf(buff,"BEF_FIELD_CHK(%s)",yyvsp[0].str);
	  generate_or(yyval.str,yyvsp[-2].str,buff);
	}
    break;

  case 161:
#line 1574 "fgl.yacc"
    {sprintf(yyval.str,"AFT_FIELD_CHK(%s)",yyvsp[0].str);}
    break;

  case 162:
#line 1575 "fgl.yacc"
    {
	  char buff[80];
	  sprintf(buff,"AFT_FIELD_CHK(%s)",yyvsp[0].str);
	  generate_or(yyval.str,yyvsp[-2].str,buff);
	}
    break;

  case 163:
#line 1592 "fgl.yacc"
    {
        	yyval.ptr=new_expr("pushop(OP_YEAR);");
	}
    break;

  case 164:
#line 1595 "fgl.yacc"
    {
        	yyval.ptr=new_expr("pushop(OP_MONTH);");
	}
    break;

  case 165:
#line 1598 "fgl.yacc"
    {
        	yyval.ptr=new_expr("pushop(OP_DAY);");
	}
    break;

  case 166:
#line 1601 "fgl.yacc"
    {
        	yyval.ptr=new_expr("pushop(OP_HOUR);");
	}
    break;

  case 167:
#line 1604 "fgl.yacc"
    {
        	yyval.ptr=new_expr("pushop(OP_MINUTE);");
	}
    break;

  case 168:
#line 1607 "fgl.yacc"
    {
        	yyval.ptr=new_expr("pushop(OP_SECOND);");
	}
    break;

  case 169:
#line 1616 "fgl.yacc"
    {
			yyval.ptr=append_expr_expr(yyvsp[-2].ptr,yyvsp[-1].ptr);
		}
    break;

  case 170:
#line 1624 "fgl.yacc"
    { 
	char buff[50];
	sprintf(buff,"push_int(%d);",(19*16)+10); 
	yyval.ptr=new_expr(buff);
}
    break;

  case 171:
#line 1629 "fgl.yacc"
    { 
	char buff[50];
	sprintf(buff,"push_int(%d);",(atoi(yyvsp[-2].str)*16) +atoi(yyvsp[0].str)  ); 
	yyval.ptr=new_expr(buff);
}
    break;

  case 172:
#line 1642 "fgl.yacc"
    {
				print_defer(0);
			}
    break;

  case 173:
#line 1646 "fgl.yacc"
    {
				print_defer(1);
			}
    break;

  case 174:
#line 1661 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 175:
#line 1662 "fgl.yacc"
    {strcpy(yyval.str,"");lastlineno=yylineno;}
    break;

  case 178:
#line 1670 "fgl.yacc"
    {dtypelist[0]=0;lex_printcomment("/* define */\n");}
    break;

  case 179:
#line 1670 "fgl.yacc"
    {lex_printcomment("/*end def */\n");}
    break;

  case 185:
#line 1680 "fgl.yacc"
    {in_define=1;}
    break;

  case 186:
#line 1680 "fgl.yacc"
    {in_define=0;strcpy(yyval.str,yyvsp[0].str);
                        set_yytext(yyval.str);
                        if (bad_identifiers(yyval.str)) {
                                yyerror("You can't use this identifier as it is a reserved word in the target language");
                        }
}
    break;

  case 187:
#line 1689 "fgl.yacc"
    { add_constant('c',yyvsp[0].str,yyvsp[-2].str); addmap("Constant",yyvsp[-2].str,curr_func,yylineno,infilename); }
    break;

  case 188:
#line 1690 "fgl.yacc"
    { add_constant('C',yyvsp[0].str,yyvsp[-2].str); addmap("Constant",yyvsp[-2].str,curr_func,yylineno,infilename); }
    break;

  case 189:
#line 1691 "fgl.yacc"
    { add_constant('f',yyvsp[0].str,yyvsp[-2].str);
addmap("Constant",yyvsp[-2].str,curr_func,yylineno,infilename);
 }
    break;

  case 190:
#line 1694 "fgl.yacc"
    { 
add_constant('i',yyvsp[0].str,yyvsp[-2].str);
addmap("Constant",yyvsp[-2].str,curr_func,yylineno,infilename);
 }
    break;

  case 192:
#line 1699 "fgl.yacc"
    { }
    break;

  case 193:
#line 1699 "fgl.yacc"
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
#line 1716 "fgl.yacc"
    {
		sprintf(yyval.str,"-%p",yyvsp[0].str);}
    break;

  case 198:
#line 1720 "fgl.yacc"
    {
/*AF CygWin FIX */
push_name(yyval.str,0);
addmap("Define",yyvsp[0].str,curr_func,yylineno,infilename);
}
    break;

  case 203:
#line 1734 "fgl.yacc"
    {
	debug("defines array %s",yyvsp[-1].str);
	push_type(0,0,yyvsp[-1].str);
}
    break;

  case 205:
#line 1743 "fgl.yacc"
    {
	push_associate(yyvsp[-5].str,yyvsp[-1].str);
	push_type(0,0,yyvsp[-1].str);
}
    break;

  case 206:
#line 1747 "fgl.yacc"
    {
    /* void pop_associate (char *a); */
	pop_associate(0);

}
    break;

  case 212:
#line 1763 "fgl.yacc"
    {sprintf(yyval.str,"%s][%s][%s",yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str); debug("Triplet");}
    break;

  case 213:
#line 1765 "fgl.yacc"
    {sprintf(yyval.str,"%s][%s",yyvsp[-2].str,yyvsp[0].str); debug("double");}
    break;

  case 214:
#line 1766 "fgl.yacc"
    {debug("Single");}
    break;

  case 216:
#line 1773 "fgl.yacc"
    {push_record();in_record++;}
    break;

  case 217:
#line 1773 "fgl.yacc"
    {pop_record();in_record--;}
    break;

  case 218:
#line 1774 "fgl.yacc"
    {in_record++;push_record();debug("Like\n");}
    break;

  case 219:
#line 1775 "fgl.yacc"
    {debug("Link Table : %s\n",yyvsp[-2].str);
                  push_rectab(yyvsp[-2].str);
                  pop_record();in_record--;}
    break;

  case 220:
#line 1778 "fgl.yacc"
    {
		push_record();debug("Like\n");}
    break;

  case 221:
#line 1780 "fgl.yacc"
    {
		  debug("Table:%s\n",yyvsp[-4].str);
		  add_link_to(yyvsp[-4].str,yyvsp[-1].str);
	          debug("Push record...\n");
                  push_rectab(yyvsp[-4].str);
                  pop_record();
}
    break;

  case 223:
#line 1790 "fgl.yacc"
    {
	sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 228:
#line 1805 "fgl.yacc"
    {start_state("dtype",1);}
    break;

  case 229:
#line 1805 "fgl.yacc"
    {start_state("dtype",0);}
    break;

  case 233:
#line 1811 "fgl.yacc"
    {push_type("char","1",0);}
    break;

  case 234:
#line 1812 "fgl.yacc"
    {
/* char buff[80]; */
if (atoi(yyvsp[-1].str)==4) {
	addmap("size=4","----",curr_func,yylineno,infilename);
}
push_type("char",yyvsp[-1].str,0);
}
    break;

  case 235:
#line 1819 "fgl.yacc"
    {push_type("char",yyvsp[-1].str,0);}
    break;

  case 236:
#line 1820 "fgl.yacc"
    {push_type("char",yyvsp[-3].str,0);}
    break;

  case 237:
#line 1821 "fgl.yacc"
    {push_type("long",0,0);}
    break;

  case 238:
#line 1822 "fgl.yacc"
    {
debug("Using specified type...");
push_dim(yyvsp[0].str);}
    break;

  case 239:
#line 1825 "fgl.yacc"
    {push_type("int",0,0);}
    break;

  case 240:
#line 1826 "fgl.yacc"
    {push_type("form",0,0);}
    break;

  case 241:
#line 1827 "fgl.yacc"
    {push_type("form",0,0);}
    break;

  case 242:
#line 1828 "fgl.yacc"
    { char buff[256];
				sprintf(buff,"%d",16*256+2);
				push_type("fgldecimal",buff,0);
				}
    break;

  case 243:
#line 1832 "fgl.yacc"
    {
				char buff[256];
				sprintf(buff,"%d",atoi(yyvsp[-1].str)*256+2);
				push_type("fgldecimal",buff,0);
}
    break;

  case 244:
#line 1837 "fgl.yacc"
    {
char buff[256];
sprintf(buff,"%d",atoi(yyvsp[-3].str)*256+atoi(yyvsp[-1].str));
push_type("fgldecimal",buff,0);
}
    break;

  case 245:
#line 1842 "fgl.yacc"
    {
			char buff[256];
			sprintf(buff,"%d",16*256+2);
			push_type("fglmoney",buff,0);}
    break;

  case 246:
#line 1846 "fgl.yacc"
    {
		char buff[256];sprintf(buff,"%d",atoi(yyvsp[-1].str)*256+2);
			push_type("fglmoney",buff,0);}
    break;

  case 247:
#line 1849 "fgl.yacc"
    {
char buff[256];
sprintf(buff,"%d",atoi(yyvsp[-3].str)*256+atoi(yyvsp[-1].str));
push_type("fglmoney",buff,0);}
    break;

  case 248:
#line 1853 "fgl.yacc"
    {push_type("double",0,0);}
    break;

  case 249:
#line 1854 "fgl.yacc"
    {push_type("float",0,0);}
    break;

  case 250:
#line 1855 "fgl.yacc"
    {push_type("fgldate",0,0);}
    break;

  case 251:
#line 1856 "fgl.yacc"
    {push_type("fglbyte",0,0);}
    break;

  case 252:
#line 1857 "fgl.yacc"
    {push_type("fglbyte",0,0);}
    break;

  case 253:
#line 1858 "fgl.yacc"
    {push_type("fgltext",0,0);}
    break;

  case 254:
#line 1859 "fgl.yacc"
    {push_type("fgltext",0,0);}
    break;

  case 255:
#line 1860 "fgl.yacc"
    {
push_type("struct_dtime",yyvsp[0].str,0);
}
    break;

  case 256:
#line 1863 "fgl.yacc"
    {push_type("struct_ival",yyvsp[0].str,0);}
    break;

  case 257:
#line 1864 "fgl.yacc"
    {push_like(yyvsp[0].str);lex_printcomment("/*added(XXXXX)\n */");}
    break;

  case 258:
#line 1865 "fgl.yacc"
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
#line 1897 "fgl.yacc"
    {
lex_printcomment("/*column like(ZZZ)\n*/"); sprintf(yyval.str,"%s.%s",yyvsp[-2].str,yyvsp[0].str); lex_printcomment ("/*set col...(ZZZ)\n*/");}
    break;

  case 260:
#line 1901 "fgl.yacc"
    {debug("--->%s\n",yyvsp[0].str);strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 261:
#line 1903 "fgl.yacc"
    {debug("--->%s\n",yyvsp[0].str);strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 262:
#line 1905 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 263:
#line 1907 "fgl.yacc"
    {
debug("Real datetime %s to %s\n",yyvsp[-2].str,yyvsp[0].str);
sprintf(yyval.str,"%d",(atoi(yyvsp[-2].str)*16)+atoi(yyvsp[0].str)); }
    break;

  case 264:
#line 1912 "fgl.yacc"
    {
	sprintf(yyval.str,"%d",(atoi(yyvsp[-2].str)*16)+atoi(yyvsp[0].str)); 
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
	yyval.ptr=new_expr(yyvsp[-1].sql_string);
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
	yyval.ptr=new_expr(yyvsp[-1].sql_string);
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
	yyval.ptr=new_expr(yyvsp[-1].sql_string);
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
	yyval.ptr=new_expr(yyvsp[-1].sql_string);
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
	sprintf(buff,"acli_datetime(%s,%s);",yyvsp[-2].str,yyvsp[0].str);
	yyval.ptr=new_expr(buff);
	inc_counter();
}
    break;

  case 484:
#line 2841 "fgl.yacc"
    {
	char buff[256];
	sprintf(buff,"acli_datetime(\"%s\",%s);",yyvsp[-2].str,yyvsp[0].str);
	yyval.ptr=new_expr(buff);
	inc_counter();
}
    break;

  case 485:
#line 2847 "fgl.yacc"
    {
	char buff[256];
	sprintf(buff,"acli_datetime(\"%s:%s\",%s);",yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str);
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
		print_put(yyvsp[-2].str);
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
#line 5702 "fgl.yacc"
    { print_exec_sql(yyvsp[0].str); }
    break;

  case 1233:
#line 5703 "fgl.yacc"
    { print_exec_sql(yyvsp[0].sql_string); 
	free(yyvsp[0].sql_string);
}
    break;

  case 1234:
#line 5709 "fgl.yacc"
    {insql=1;}
    break;

  case 1235:
#line 5709 "fgl.yacc"
    {insql=0;}
    break;

  case 1236:
#line 5709 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-6].str," ",yyvsp[-4].str," ",yyvsp[-3].str,yyvsp[-1].sql_string,yyvsp[0].str,0);
		free(yyvsp[-1].sql_string);
	}
    break;

  case 1237:
#line 5714 "fgl.yacc"
    {insql=1;}
    break;

  case 1238:
#line 5714 "fgl.yacc"
    {insql=0;}
    break;

  case 1239:
#line 5714 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-7].str," ",yyvsp[-5].str," ",yyvsp[-4].str,yyvsp[-2].sql_string,yyvsp[-1].str, " ",yyvsp[0].str,0);
		free(yyvsp[-2].sql_string);

}
    break;

  case 1240:
#line 5725 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1241:
#line 5726 "fgl.yacc"
    {
		yyerror("You cannot create a database from within Aubit4gl....");
	}
    break;

  case 1242:
#line 5732 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1243:
#line 5734 "fgl.yacc"
    {sprintf(yyval.str," %s ",yyvsp[0].str);}
    break;

  case 1245:
#line 5741 "fgl.yacc"
    {sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1246:
#line 5745 "fgl.yacc"
    {sprintf(yyval.str,"%s ASC",yyvsp[-1].str);}
    break;

  case 1247:
#line 5746 "fgl.yacc"
    {sprintf(yyval.str,"%s DESC",yyvsp[-1].str);}
    break;

  case 1249:
#line 5751 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1250:
#line 5754 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",",yyvsp[0].sql_string,0);
	}
    break;

  case 1251:
#line 5760 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1252:
#line 5763 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1253:
#line 5771 "fgl.yacc"
    {sprintf(yyval.str,"%s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1255:
#line 5778 "fgl.yacc"
    {
	yyval.sql_string=make_sql_string(yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].sql_string,0);
	print_exec_sql(yyvsp[-2].sql_string); 
}
    break;

  case 1256:
#line 5785 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1257:
#line 5788 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",",yyvsp[0].sql_string,0);
	}
    break;

  case 1258:
#line 5797 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1259:
#line 5800 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1260:
#line 5803 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1261:
#line 5806 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1262:
#line 5809 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1263:
#line 5812 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1264:
#line 5815 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1265:
#line 5822 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("ADD ",yyvsp[0].sql_string,0);
	}
    break;

  case 1266:
#line 5825 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("ADD (",yyvsp[-2].sql_string,")",0);
	}
    break;

  case 1267:
#line 5832 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1268:
#line 5835 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].str," BEFORE ",yyvsp[0].str,0);
	}
    break;

  case 1269:
#line 5841 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1270:
#line 5844 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].str,",",yyvsp[0].str,0);
	}
    break;

  case 1271:
#line 5851 "fgl.yacc"
    {
		sprintf(yyval.str,"DROP %s",yyvsp[0].str);
	}
    break;

  case 1272:
#line 5854 "fgl.yacc"
    {
		sprintf(yyval.str,"DROP (%s)",yyvsp[-1].str);
	}
    break;

  case 1274:
#line 5862 "fgl.yacc"
    {
		sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);
	}
    break;

  case 1276:
#line 5871 "fgl.yacc"
    {
		sprintf(yyval.str,"MODIFY %s",yyvsp[0].sql_string);
	}
    break;

  case 1277:
#line 5874 "fgl.yacc"
    {
		sprintf(yyval.str,"MODIFY (%s)",yyvsp[-1].sql_string);
	}
    break;

  case 1278:
#line 5880 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1279:
#line 5883 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",",yyvsp[0].sql_string,0);
	}
    break;

  case 1280:
#line 5889 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1281:
#line 5896 "fgl.yacc"
    {strcpy(yyval.str,"LOCK MODE PAGE");}
    break;

  case 1282:
#line 5897 "fgl.yacc"
    {strcpy(yyval.str,"LOCK MODE ROW");}
    break;

  case 1283:
#line 5901 "fgl.yacc"
    {
		sprintf(yyval.str,"MODIFT NEXT SIZE %d",atoi(yyvsp[0].str));
	}
    break;

  case 1284:
#line 5907 "fgl.yacc"
    {
		sprintf(yyval.str,"ADD CONSTRAINT %s",yyvsp[0].sql_string);
	}
    break;

  case 1285:
#line 5910 "fgl.yacc"
    {
		sprintf(yyval.str,"ADD CONSTRAINT (%s)",yyvsp[-1].sql_string);
	}
    break;

  case 1287:
#line 5918 "fgl.yacc"
    {
		sprintf(yyval.str,"ADD CONSTRAINT (%s)",yyvsp[-1].sql_string);
	}
    break;

  case 1288:
#line 5925 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1289:
#line 5928 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",",yyvsp[0].sql_string,0);
	}
    break;

  case 1293:
#line 5946 "fgl.yacc"
    {sprintf(yyval.str,"%s %s /*FIXME */",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1299:
#line 5952 "fgl.yacc"
    { 
	print_set_conn(yyvsp[0].str);
}
    break;

  case 1300:
#line 5955 "fgl.yacc"
    {
	print_set_options("conn",yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 1301:
#line 5958 "fgl.yacc"
    {
	print_set_options("stmt",yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 1302:
#line 5964 "fgl.yacc"
    {strcpy(yyval.str,"\"default\"");}
    break;

  case 1304:
#line 5970 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1306:
#line 5981 "fgl.yacc"
    {
		print_sleep();
	}
    break;

  case 1307:
#line 5995 "fgl.yacc"
    {
		strcpy(current_upd_table,yyvsp[0].str);
	}
    break;

  case 1308:
#line 5997 "fgl.yacc"
    {
		strcpy(current_upd_table,"");
	}
    break;

  case 1309:
#line 5999 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-6].str," ",yyvsp[-5].str," ",yyvsp[-3].str," ",yyvsp[-2].sql_string," ",yyvsp[0].sql_string,0);
	}
    break;

  case 1310:
#line 6004 "fgl.yacc"
    {
		pop_all_gen(UPDCOL,"!"); pop_all_gen(UPDVAL,"!");
		yyval.sql_string=strdup("");
	}
    break;

  case 1311:
#line 6008 "fgl.yacc"
    { 
		pop_all_gen(UPDCOL,"!"); pop_all_gen(UPDVAL,"!");
		rm_quotes(yyvsp[0].str);
		sprintf(yyval.str,"%s %s",yyvsp[-1].str,yyvsp[0].str);
		yyval.sql_string=make_sql_string(yyval.str,0);
	}
    break;

  case 1312:
#line 6014 "fgl.yacc"
    {
		pop_all_gen(UPDCOL,"!"); pop_all_gen(UPDVAL,"!");
		yyval.sql_string=make_sql_string("WHERE ",yyvsp[0].sql_string,0);
	}
    break;

  case 1313:
#line 6022 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("(",yyvsp[-5].str,")=(",yyvsp[-1].sql_string,")",0);

		if (isyes(acl_getenv("FIXUPDATE"))) { 
			yyval.sql_string=strdup(fix_update_expr(0)); 
			ansi_violation("Update (..)=(..)",0);
		}  else {
			ansi_violation("Update (..)=(..)",1);
		}
    }
    break;

  case 1314:
#line 6032 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
    }
    break;

  case 1315:
#line 6035 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("*=(",yyvsp[-1].sql_string,")",0);
		push_gen(UPDCOL,"*");
		if (isyes(acl_getenv("FIXUPDATE"))) { 
			yyval.sql_string=strdup(fix_update_expr(1));
			ansi_violation("Update (..)=(..)",0);
		} else {
			ansi_violation("Update (..)=(..)",1);
		}
}
    break;

  case 1316:
#line 6045 "fgl.yacc"
    {
		char *ptr;

		ptr=yyvsp[0].sql_string;
		push_gen(UPDCOL,"*");

		if (ptr[0]=='(') {
			yyval.sql_string=make_sql_string(yyvsp[-2].str," ",yyvsp[-1].str," ",yyvsp[0].sql_string,0);
		} else {
			yyval.sql_string=make_sql_string(yyvsp[-2].str,yyvsp[-1].str,"(",yyvsp[0].sql_string,")",0);
		}

		if (isyes(acl_getenv("FIXUPDATE"))) { 
			yyval.sql_string=strdup(fix_update_expr(1));
			ansi_violation("Update (..)=(..)",0);
		} else {
			ansi_violation("Update (..)=(..)",1);
		}
	}
    break;

  case 1317:
#line 6067 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1318:
#line 6070 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",",yyvsp[0].sql_string,0);
	}
    break;

  case 1320:
#line 6079 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].str,"=",yyvsp[0].sql_string,0);
	}
    break;

  case 1321:
#line 6084 "fgl.yacc"
    {push_gen(UPDCOL,yyvsp[0].str); strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1322:
#line 6085 "fgl.yacc"
    {push_gen(UPDCOL,yyvsp[0].str); sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1323:
#line 6091 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1324:
#line 6094 "fgl.yacc"
    { 
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",",yyvsp[0].sql_string,0);
	}
    break;

  case 1325:
#line 6102 "fgl.yacc"
    {
		push_gen(UPDVAL,"<SUBQUERY>");
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1326:
#line 6106 "fgl.yacc"
    {
		push_gen(UPDVAL,"NULL");
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1327:
#line 6110 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1328:
#line 6117 "fgl.yacc"
    {
		print_sql_commit(0);
		}
    break;

  case 1329:
#line 6126 "fgl.yacc"
    { insql=1;start_bind('i',0);}
    break;

  case 1330:
#line 6126 "fgl.yacc"
    {
	yyval.sql_string=make_sql_string(yyvsp[-4].str," ",yyvsp[-2].str," ",yyvsp[-1].str," ",yyvsp[0].sql_string,0);
}
    break;

  case 1331:
#line 6131 "fgl.yacc"
    {insql=1;}
    break;

  case 1332:
#line 6131 "fgl.yacc"
    {
insql=0;
yyval.sql_string=make_sql_string(yyvsp[-4].str," ",yyvsp[-2].str," ",yyvsp[-1].str," ",yyvsp[0].str,0);}
    break;

  case 1333:
#line 6135 "fgl.yacc"
    {yyval.sql_string=yyvsp[0].sql_string;}
    break;

  case 1334:
#line 6138 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1335:
#line 6140 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1337:
#line 6147 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1339:
#line 6153 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1342:
#line 6163 "fgl.yacc"
    {
      print_fetch_1();
    }
    break;

  case 1343:
#line 6167 "fgl.yacc"
    {
      print_fetch_2();
    }
    break;

  case 1344:
#line 6171 "fgl.yacc"
    {
      print_fetch_3(yyvsp[-2].str,yyvsp[0].str);
    }
    break;

  case 1345:
#line 6180 "fgl.yacc"
    {sprintf(yyval.str,"%s, %s",yyvsp[0].str,yyvsp[-1].str);
addmap("Fetch Cursor",yyvsp[0].str,curr_func,yylineno,infilename);
}
    break;

  case 1346:
#line 6184 "fgl.yacc"
    {sprintf(yyval.str,"%s, %d, 1",yyvsp[0].str,FETCH_RELATIVE);

addmap("Fetch Cursor",yyvsp[0].str,curr_func,yylineno,infilename);
}
    break;

  case 1347:
#line 6190 "fgl.yacc"
    {
debug("no into\n");
strcpy(yyval.str,"0,0");
}
    break;

  case 1348:
#line 6194 "fgl.yacc"
    {
	debug("FETCH INTO  ...");
	/* start_bind('i',0,-1); */
    start_bind('o',0);
}
    break;

  case 1349:
#line 6200 "fgl.yacc"
    {
	int no;
	no=print_bind('o');
	sprintf(yyval.str,"%d,obind",no);
}
    break;

  case 1350:
#line 6207 "fgl.yacc"
    {
debug("no into\n");
strcpy(yyval.str,"0,0");
}
    break;

  case 1351:
#line 6211 "fgl.yacc"
    {
	debug("FETCH INTO  ...");
	/* start_bind('i',0,-1); */
    start_bind('o',0);
}
    break;

  case 1352:
#line 6216 "fgl.yacc"
    {
/*
int ni;
ni=print_bind('i');
sprintf($<str>$,"%d,ibind",ni);
*/
}
    break;

  case 1353:
#line 6226 "fgl.yacc"
    {
		sprintf(yyval.str,"%d,1",FETCH_ABSOLUTE);}
    break;

  case 1354:
#line 6229 "fgl.yacc"
    {sprintf(yyval.str,"%d,-1",FETCH_ABSOLUTE);}
    break;

  case 1355:
#line 6231 "fgl.yacc"
    {sprintf(yyval.str,"%d,1",FETCH_RELATIVE);}
    break;

  case 1356:
#line 6233 "fgl.yacc"
    {sprintf(yyval.str,"%d,-1",FETCH_RELATIVE);}
    break;

  case 1357:
#line 6235 "fgl.yacc"
    {sprintf(yyval.str,"%d,-1",FETCH_RELATIVE);}
    break;

  case 1358:
#line 6237 "fgl.yacc"
    {sprintf(yyval.str,"%d,0",FETCH_RELATIVE);}
    break;

  case 1359:
#line 6239 "fgl.yacc"
    {sprintf(yyval.str,"%d,pop_int()",FETCH_RELATIVE);}
    break;

  case 1360:
#line 6241 "fgl.yacc"
    {sprintf(yyval.str,"%d,pop_int()",FETCH_ABSOLUTE);}
    break;

  case 1361:
#line 6247 "fgl.yacc"
    {
 
rm_quotes(yyvsp[0].str);
sprintf(yyval.str," %s %s %s %s ",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str
);}
    break;

  case 1362:
#line 6257 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].str," ",yyvsp[-1].str," ",yyvsp[0].sql_string,0);
		}
    break;

  case 1363:
#line 6264 "fgl.yacc"
    {sprintf(yyval.str,"%s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1365:
#line 6270 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1369:
#line 6279 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1372:
#line 6284 "fgl.yacc"
    {
print_sql_commit(-1);
}
    break;

  case 1373:
#line 6289 "fgl.yacc"
    {
		print_sql_commit(1);
	}
    break;

  case 1374:
#line 6296 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1375:
#line 6297 "fgl.yacc"
    {
		strcpy(yyval.str,"EXCLUSIVE");
	}
    break;

  case 1376:
#line 6304 "fgl.yacc"
    {
if (strcmp(yyvsp[-1].str,"?")==0) {
	print_init_conn(0);
} else {
	print_init_conn(yyvsp[-1].str);
}
}
    break;

  case 1377:
#line 6316 "fgl.yacc"
    {insql=1;}
    break;

  case 1378:
#line 6316 "fgl.yacc"
    {
print_undo_use(yyvsp[-2].str);
insql=0;strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1379:
#line 6321 "fgl.yacc"
    {
			lex_printcomment("/*  schema */\n");
			print_exec_sql(yyvsp[0].sql_string);
			strcpy(yyval.str,"Schema");
	}
    break;

  case 1380:
#line 6326 "fgl.yacc"
    {
		lex_printcomment("/*  schema  2*/\n");
		print_exec_sql(yyvsp[0].sql_string);
		strcpy(yyval.str,"Schema Element");
	}
    break;

  case 1382:
#line 6332 "fgl.yacc"
    {
		print_exec_sql(yyvsp[0].str);
 	}
    break;

  case 1384:
#line 6336 "fgl.yacc"
    {
		lex_printcomment("/*  delete 1 */\n");
		print_exec_sql_bound(yyvsp[0].str);
		strcpy(yyval.str,"Delete where current...");
	}
    break;

  case 1385:
#line 6341 "fgl.yacc"
    {
		lex_printcomment("/*  delete 2 */\n");
		print_exec_sql_bound(yyvsp[0].sql_string);
		strcpy(yyval.str,"Delete where ...");
	}
    break;

  case 1386:
#line 6346 "fgl.yacc"
    {
		strcpy(yyval.str,"Fetch");
		lex_printcomment("/*  fetch */\n");
	}
    break;

  case 1387:
#line 6350 "fgl.yacc"
    {
		lex_printcomment("/*  insert */\n");
		print_exec_sql_bound(yyvsp[0].sql_string);
		strcpy(yyval.str,"insert");
	}
    break;

  case 1389:
#line 6356 "fgl.yacc"
    {
		print_do_select(yyvsp[0].sql_string);
		strcpy(yyval.str,"select");
	}
    break;

  case 1390:
#line 6360 "fgl.yacc"
    {
		print_exec_sql_bound(yyvsp[0].sql_string);
		strcpy(yyval.str,"update");
	}
    break;

  case 1391:
#line 6368 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s %s %s %s",yyvsp[-6].str,yyvsp[-5].str,yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1392:
#line 6371 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1393:
#line 6373 "fgl.yacc"
    {sprintf(yyval.str," %s ",yyvsp[0].str);}
    break;

  case 1394:
#line 6378 "fgl.yacc"
    {sprintf(yyval.str," %s ",yyvsp[0].str);}
    break;

  case 1397:
#line 6385 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1401:
#line 6392 "fgl.yacc"
    {sprintf(yyval.str," %s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1402:
#line 6395 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1403:
#line 6397 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1405:
#line 6403 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1407:
#line 6409 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1410:
#line 6419 "fgl.yacc"
    {
yyval.sql_string=make_sql_string(yyvsp[-5].str," ",yyvsp[-4].str," ",yyvsp[-3].str," ",yyvsp[-2].str," ",yyvsp[-1].str," ",yyvsp[0].str,0);}
    break;

  case 1411:
#line 6423 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1412:
#line 6425 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1414:
#line 6431 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1415:
#line 6434 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1417:
#line 6440 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("CHECK(",yyvsp[-1].sql_string,")",0);
	}
    break;

  case 1418:
#line 6448 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s %s",yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1419:
#line 6453 "fgl.yacc"
    {sprintf(yyval.str," %s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1422:
#line 6463 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1424:
#line 6469 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1425:
#line 6475 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1426:
#line 6477 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1428:
#line 6483 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1429:
#line 6488 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1430:
#line 6491 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1431:
#line 6494 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1432:
#line 6502 "fgl.yacc"
    {sprintf(yyval.str," %s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1433:
#line 6504 "fgl.yacc"
    {sprintf(yyval.str," %s",yyvsp[0].str);}
    break;

  case 1434:
#line 6515 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-3].str," ",yyvsp[-2].str," ",yyvsp[-1].str," ",yyvsp[0].sql_string,0);
	}
    break;

  case 1435:
#line 6520 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1437:
#line 6524 "fgl.yacc"
    {
		yyval.sql_string=strdup("");
	}
    break;

  case 1438:
#line 6526 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1439:
#line 6533 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1440:
#line 6536 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-1].sql_string,yyvsp[0].sql_string,0);
	}
    break;

  case 1441:
#line 6542 "fgl.yacc"
    {
		sprintf(yyval.str," %s ",yyvsp[0].str);
		yyval.sql_string=strdup(yyval.str);
	}
    break;

  case 1442:
#line 6546 "fgl.yacc"
    {
		sprintf(yyval.str," %s ",yyvsp[0].str);
		yyval.sql_string=strdup(yyval.str);
	}
    break;

  case 1443:
#line 6550 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1444:
#line 6553 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-3].str," ",yyvsp[-2].str," ",yyvsp[-1].sql_string," ",yyvsp[0].str,0);
	}
    break;

  case 1445:
#line 6561 "fgl.yacc"
    {
yyval.sql_string=make_sql_string(yyvsp[-2].str," ",yyvsp[-1].str," ",yyvsp[0].str,0);
}
    break;

  case 1446:
#line 6568 "fgl.yacc"
    {sprintf(yyval.str," %s",yyvsp[0].str);}
    break;

  case 1449:
#line 6577 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-1].sql_string," ",yyvsp[0].sql_string,0);
	}
    break;

  case 1450:
#line 6583 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1451:
#line 6586 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1452:
#line 6597 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-1].str," ",yyvsp[0].sql_string,0);
	}
    break;

  case 1453:
#line 6604 "fgl.yacc"
    {
		sprintf(yyval.str," %s %s",yyvsp[-1].str,yyvsp[0].str);
	}
    break;

  case 1456:
#line 6616 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("WHERE ",yyvsp[0].sql_string,0);
	}
    break;

  case 1457:
#line 6623 "fgl.yacc"
    {
		sprintf(yyval.str,"%s %s",yyvsp[-1].str,yyvsp[0].str);
	}
    break;

  case 1459:
#line 6630 "fgl.yacc"
    {
		sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);
	}
    break;

  case 1460:
#line 6636 "fgl.yacc"
    {sprintf(yyval.str," %s ", yyvsp[0].str);}
    break;

  case 1461:
#line 6637 "fgl.yacc"
    {sprintf(yyval.str," %s %s ",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1462:
#line 6638 "fgl.yacc"
    {sprintf(yyval.str," %s (%s) ",yyvsp[-3].str,yyvsp[-1].str);}
    break;

  case 1464:
#line 6642 "fgl.yacc"
    {sprintf(yyval.str,"%s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1466:
#line 6647 "fgl.yacc"
    { sprintf(yyval.str," %s,%s ",yyvsp[-2].str,yyvsp[0].str);  }
    break;

  case 1467:
#line 6654 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-3].str," ",yyvsp[-2].sql_string," ",yyvsp[-1].str," ",yyvsp[0].sql_string,0);
	}
    break;

  case 1468:
#line 6659 "fgl.yacc"
    { yyval.sql_string=strdup("");}
    break;

  case 1469:
#line 6660 "fgl.yacc"
    {yyval.sql_string=yyvsp[0].sql_string;}
    break;

  case 1470:
#line 6663 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1471:
#line 6664 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1472:
#line 6667 "fgl.yacc"
    {yyval.sql_string=strdup("");}
    break;

  case 1473:
#line 6668 "fgl.yacc"
    {yyval.sql_string=yyvsp[0].sql_string;}
    break;

  case 1474:
#line 6673 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1475:
#line 6676 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string," OR ",yyvsp[0].sql_string,0);
	}
    break;

  case 1476:
#line 6682 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1477:
#line 6685 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string," AND ",yyvsp[0].sql_string,0);
	}
    break;

  case 1478:
#line 6691 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1479:
#line 6694 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-1].str," ",yyvsp[0].sql_string,0);
	}
    break;

  case 1480:
#line 6700 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1481:
#line 6703 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].str,yyvsp[-1].sql_string,yyvsp[0].str,0);
	}
    break;

  case 1482:
#line 6710 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-1].str," ",yyvsp[0].sql_string,0);}
    break;

  case 1483:
#line 6711 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-1].str," ",yyvsp[0].sql_string,0);}
    break;

  case 1484:
#line 6717 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-3].str," ",yyvsp[-2].str," ",yyvsp[-1].str," ",yyvsp[0].sql_string,0);}
    break;

  case 1485:
#line 6719 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-2].sql_string," ",yyvsp[-1].str," ",yyvsp[0].str,0);}
    break;

  case 1486:
#line 6723 "fgl.yacc"
    {strcpy(yyval.str," ALL ");}
    break;

  case 1492:
#line 6742 "fgl.yacc"
    {sprintf(yyval.str," %s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1495:
#line 6755 "fgl.yacc"
    {
		sprintf(yyval.str,"%s %s %s %s %s",yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);
		yyval.sql_string=strdup(yyvsp[-4].str);
	}
    break;

  case 1496:
#line 6759 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].str," ",yyvsp[-1].str," ",yyvsp[0].sql_string,0);
	}
    break;

  case 1497:
#line 6762 "fgl.yacc"
    {
		sprintf(yyval.str,"%s %s %s %s %s",yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);
		yyval.sql_string=strdup(yyvsp[-4].str);
	}
    break;

  case 1498:
#line 6766 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].str," ",yyvsp[-1].str," ",yyvsp[0].sql_string,0);
	}
    break;

  case 1500:
#line 6774 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1503:
#line 6780 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1505:
#line 6786 "fgl.yacc"
    {
		sprintf(yyval.str,"%s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);
		yyval.sql_string=strdup(yyval.str);
	}
    break;

  case 1506:
#line 6790 "fgl.yacc"
    {
		sprintf(yyval.str,"%s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);
		yyval.sql_string=strdup(yyval.str);
	}
    break;

  case 1507:
#line 6794 "fgl.yacc"
    {
		sprintf(yyval.str,"%s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);
		yyval.sql_string=strdup(yyval.str);
	}
    break;

  case 1508:
#line 6798 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].str," ",yyvsp[-1].str," ",yyvsp[0].sql_string,0);
	}
    break;

  case 1509:
#line 6801 "fgl.yacc"
    {
		sprintf(yyval.str,"%s %s %s %s %s %s",yyvsp[-5].str,yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);
		yyval.sql_string=strdup(yyval.str);
	}
    break;

  case 1510:
#line 6805 "fgl.yacc"
    {
		sprintf(yyval.str,"%s %s Like %s %s",yyvsp[-4].str,yyvsp[-3].str,yyvsp[-1].str,yyvsp[0].str);
		yyval.sql_string=strdup(yyval.str);
	}
    break;

  case 1512:
#line 6813 "fgl.yacc"
    {strcpy(yyval.str,"!=");}
    break;

  case 1518:
#line 6819 "fgl.yacc"
    {strcpy(yyval.str,"likE");}
    break;

  case 1519:
#line 6820 "fgl.yacc"
    {strcpy(yyval.str,"<=");}
    break;

  case 1520:
#line 6821 "fgl.yacc"
    {strcpy(yyval.str,">=");}
    break;

  case 1521:
#line 6826 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1522:
#line 6829 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1523:
#line 6832 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1524:
#line 6835 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1525:
#line 6841 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1526:
#line 6842 "fgl.yacc"
    {strcpy(yyval.str," ALL ");}
    break;

  case 1527:
#line 6843 "fgl.yacc"
    {strcpy(yyval.str," DISTINCT ");}
    break;

  case 1528:
#line 6844 "fgl.yacc"
    {
		ansi_violation("Use DISTINCT not UNIQUE",0);
		strcpy(yyval.str," DISTINCT ");
	}
    break;

  case 1533:
#line 6864 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1534:
#line 6869 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s %s",yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1535:
#line 6870 "fgl.yacc"
    {strcpy(yyval.str,"SERIAL");}
    break;

  case 1537:
#line 6873 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s %s",yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1541:
#line 6878 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1543:
#line 6881 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1545:
#line 6884 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s %s %s %s",yyvsp[-6].str,yyvsp[-5].str,yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1549:
#line 6889 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1550:
#line 6891 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s %s %s",yyvsp[-5].str,yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1551:
#line 6894 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1552:
#line 6895 "fgl.yacc"
    {
		sprintf(yyval.str,",%s",yyvsp[0].str);
}
    break;

  case 1553:
#line 6902 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1557:
#line 6907 "fgl.yacc"
    {sprintf(yyval.str," %s",yyvsp[0].str);}
    break;

  case 1561:
#line 6923 "fgl.yacc"
    { sprintf(yyval.str,"\\\"%s\\\"%s%s",strip_quotes(yyvsp[-2].str),yyvsp[-1].str,yyvsp[0].str); addmap("Use Table",yyval.str,curr_func,yylineno,infilename); }
    break;

  case 1562:
#line 6924 "fgl.yacc"
    {
		sprintf(yyval.str," %s",strip_quotes(yyvsp[0].str));
		addmap("Use Table",yyval.str,curr_func,yylineno,infilename);
	}
    break;

  case 1563:
#line 6928 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str); addmap("Use Table",yyvsp[0].str,curr_func,yylineno,infilename); }
    break;

  case 1564:
#line 6929 "fgl.yacc"
    { sprintf(yyval.str," %s%s%s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str); addmap("Use Table",yyval.str,curr_func,yylineno,infilename); }
    break;

  case 1566:
#line 6944 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1567:
#line 6945 "fgl.yacc"
    {sprintf(yyval.str,"[%s]",yyvsp[-1].str);}
    break;

  case 1568:
#line 6946 "fgl.yacc"
    {sprintf(yyval.str,"[%s,%s]",yyvsp[-3].str,yyvsp[-1].str);}
    break;

  case 1569:
#line 6950 "fgl.yacc"
    { 
addmap("Use Column",yyvsp[-1].str,curr_func,yylineno,infilename);
sprintf(yyval.str,"%s%s",yyvsp[-1].str,yyvsp[0].str);
}
    break;

  case 1570:
#line 6955 "fgl.yacc"
    {
sprintf(yyval.str,"%s.%s%s",yyvsp[-4].str,yyvsp[-1].str,yyvsp[0].str);
addmap("Use Column",yyval.str,curr_func,yylineno,infilename);
}
    break;

  case 1571:
#line 6960 "fgl.yacc"
    {
sprintf(yyval.str,"%s.%s",yyvsp[-3].str,yyvsp[0].str);
addmap("Use Column",yyval.str,curr_func,yylineno,infilename);
}
    break;

  case 1573:
#line 6973 "fgl.yacc"
    {
	strcpy(yyval.str,convstrsql(yyvsp[0].str));
	debug("Set $<str>$ to %s\n",yyval.str);
}
    break;

  case 1577:
#line 6981 "fgl.yacc"
    {sprintf(yyval.str," %s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1578:
#line 6983 "fgl.yacc"
    {sprintf(yyval.str," %s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1579:
#line 6985 "fgl.yacc"
    {sprintf(yyval.str," %s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1580:
#line 6987 "fgl.yacc"
    {sprintf(yyval.str," %s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1582:
#line 6992 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1583:
#line 6995 "fgl.yacc"
    {sprintf(yyval.str," %s %s ",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1584:
#line 6998 "fgl.yacc"
    {strcpy(yyval.str," YEAR TO SECOND ");}
    break;

  case 1585:
#line 7000 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1586:
#line 7003 "fgl.yacc"
    {strcpy(yyval.str,"0,19");}
    break;

  case 1587:
#line 7005 "fgl.yacc"
    {sprintf(yyval.str," %s ,%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1588:
#line 7008 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 1589:
#line 7008 "fgl.yacc"
    {strcpy(yyval.str,"5");}
    break;

  case 1590:
#line 7008 "fgl.yacc"
    {strcpy(yyval.str,"8");}
    break;

  case 1591:
#line 7008 "fgl.yacc"
    {strcpy(yyval.str,"11");}
    break;

  case 1592:
#line 7008 "fgl.yacc"
    {strcpy(yyval.str,"14");}
    break;

  case 1593:
#line 7008 "fgl.yacc"
    {strcpy(yyval.str,"17");}
    break;

  case 1594:
#line 7009 "fgl.yacc"
    {
strcpy(yyval.str,"23");
}
    break;

  case 1595:
#line 7012 "fgl.yacc"
    {
strcpy(yyval.str,"23");
}
    break;

  case 1596:
#line 7017 "fgl.yacc"
    {strcpy(yyval.str,"4");}
    break;

  case 1597:
#line 7017 "fgl.yacc"
    {strcpy(yyval.str,"7");}
    break;

  case 1598:
#line 7017 "fgl.yacc"
    {strcpy(yyval.str,"10");}
    break;

  case 1599:
#line 7017 "fgl.yacc"
    {strcpy(yyval.str,"13");}
    break;

  case 1600:
#line 7017 "fgl.yacc"
    {strcpy(yyval.str,"16");}
    break;

  case 1601:
#line 7017 "fgl.yacc"
    {strcpy(yyval.str,"19");}
    break;

  case 1602:
#line 7019 "fgl.yacc"
    {
strcpy(yyval.str,"25");
}
    break;

  case 1603:
#line 7022 "fgl.yacc"
    {
strcpy(yyval.str,"25");
}
    break;

  case 1618:
#line 7031 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1619:
#line 7032 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1620:
#line 7036 "fgl.yacc"
    {
	print_flush_cursor(yyvsp[0].str);
		addmap("Flush Cursor",yyvsp[0].str,curr_func,yylineno,infilename);
print_undo_use(yyvsp[-2].str);
		}
    break;

  case 1621:
#line 7044 "fgl.yacc"
    {insql=0;chk4var=0;}
    break;

  case 1622:
#line 7044 "fgl.yacc"
    {
		print_declare(yyvsp[0].str,yyvsp[-2].sql_string,yyvsp[-5].str,0,0);
		addmap("Declare Cursor",yyvsp[-5].str,curr_func,yylineno,infilename);
		print_undo_use(yyvsp[-7].str);
	}
    break;

  case 1623:
#line 7049 "fgl.yacc"
    {insql=0;chk4var=0;}
    break;

  case 1624:
#line 7049 "fgl.yacc"
    {
		print_declare(yyvsp[0].str,yyvsp[-2].sql_string,yyvsp[-6].str,2,0); 
		addmap("Declare Cursor",yyvsp[-6].str,curr_func,yylineno,infilename);
		print_undo_use(yyvsp[-8].str);
	}
    break;

  case 1625:
#line 7055 "fgl.yacc"
    {insql=0;chk4var=0;}
    break;

  case 1626:
#line 7055 "fgl.yacc"
    {
		print_declare(yyvsp[0].str,yyvsp[-2].sql_string,yyvsp[-4].str,0,1); 
		addmap("Declare Cursor",yyvsp[-4].str,curr_func,yylineno,infilename);
		print_undo_use(yyvsp[-6].str);
	}
    break;

  case 1627:
#line 7060 "fgl.yacc"
    {insql=0;chk4var=0;}
    break;

  case 1628:
#line 7060 "fgl.yacc"
    {
		print_declare(yyvsp[0].str,yyvsp[-2].sql_string,yyvsp[-6].str,0,1); 
		addmap("Declare Cursor",yyvsp[-6].str,curr_func,yylineno,infilename);
		print_undo_use(yyvsp[-8].str);
	}
    break;

  case 1629:
#line 7067 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 1630:
#line 7068 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 1631:
#line 7069 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 1635:
#line 7076 "fgl.yacc"
    {sprintf(yyval.str,"%s.%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1636:
#line 7077 "fgl.yacc"
    {sprintf(yyval.str,"\\\"%s\\\".%s.%s",strip_quotes(yyvsp[-4].str),yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1637:
#line 7082 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1638:
#line 7085 "fgl.yacc"
    { 
		yyval.sql_string=make_sql_string(print_curr_spec(1,yyvsp[0].sql_string),0);
	}
    break;

  case 1639:
#line 7091 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(print_curr_spec(2,yyvsp[0].str) ,0);
	}
    break;

  case 1640:
#line 7094 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1641:
#line 7103 "fgl.yacc"
    {
	yyval.sql_string=yyvsp[-1].sql_string;
	if (atoi(yyvsp[0].str)) {
		printf("Warning SELECT ... FOR UPDATE when not declaring a cursor currently has no locking effect\n");
	}
}
    break;

  case 1642:
#line 7115 "fgl.yacc"
    {debug("Got select list...\n");}
    break;

  case 1643:
#line 7116 "fgl.yacc"
    { start_bind('i',0); }
    break;

  case 1644:
#line 7118 "fgl.yacc"
    {
		char *ptr;
                ptr=make_sql_string("SELECT ",yyvsp[-6].str, yyvsp[-5].sql_string," ", yyvsp[-3].str, " ",yyvsp[-1].sql_string," ",yyvsp[0].sql_string,0);

		yyval.sql_string=strdup(print_select_all(ptr));
		free(ptr);
		free(yyvsp[-5].sql_string);
		free(yyvsp[-1].sql_string);
		free(yyvsp[0].sql_string);
}
    break;

  case 1645:
#line 7132 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("push_char(\"", yyvsp[-4].str, " ",yyvsp[-3].str," ", yyvsp[-2].sql_string, " ",yyvsp[-1].sql_string, " ",yyvsp[0].sql_string, "\");",0 );
	free(yyvsp[-2].sql_string);
	free(yyvsp[-1].sql_string);
	free(yyvsp[0].sql_string);
}
    break;

  case 1646:
#line 7142 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	 }
    break;

  case 1647:
#line 7145 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1648:
#line 7153 "fgl.yacc"
    {
	yyval.sql_string=make_sql_string(yyvsp[-6].str, " ",yyvsp[-4].str," ",yyvsp[-3].sql_string," ", yyvsp[-2].str," ", yyvsp[-1].sql_string, " ",yyvsp[0].sql_string,0);
	free(yyvsp[-3].sql_string);
	free(yyvsp[-1].sql_string);
	free(yyvsp[0].sql_string);
}
    break;

  case 1649:
#line 7162 "fgl.yacc"
    {
		yyval.sql_string=strdup("");
		}
    break;

  case 1650:
#line 7165 "fgl.yacc"
    {
       lex_printcomment("/* UNION */");
	yyval.sql_string=make_sql_string(yyvsp[-2].str," ",yyvsp[-1].str," ",yyvsp[0].sql_string,0);
       }
    break;

  case 1651:
#line 7169 "fgl.yacc"
    {
	yyval.sql_string=strdup(yyvsp[0].str);
}
    break;

  case 1652:
#line 7172 "fgl.yacc"
    { yyval.sql_string=make_sql_string(yyvsp[-2].str," ",yyvsp[-1].str," ",yyvsp[0].str,0); }
    break;

  case 1653:
#line 7173 "fgl.yacc"
    { 
	yyval.sql_string=make_sql_string(yyvsp[-3].str," ",yyvsp[-2].str," ",yyvsp[-1].str," ",yyvsp[0].str,0);
}
    break;

  case 1655:
#line 7182 "fgl.yacc"
    { start_bind('o',0);strcpy(yyval.str,""); }
    break;

  case 1656:
#line 7183 "fgl.yacc"
    { 
		
		strcpy(yyval.str,get_into_part(get_bind_cnt('o'))); 
	}
    break;

  case 1657:
#line 7192 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-4].str," ",yyvsp[-2].str," ", yyvsp[-1].sql_string," ",yyvsp[0].sql_string,0);
		free(yyvsp[-1].sql_string);
		free(yyvsp[0].sql_string);

	}
    break;

  case 1658:
#line 7201 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("(",yyvsp[-5].str," ",yyvsp[-3].str," ",yyvsp[-2].sql_string," ",yyvsp[-1].sql_string,")",0);
	}
    break;

  case 1659:
#line 7206 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1660:
#line 7207 "fgl.yacc"
    {strcpy(yyval.str,"ALL");}
    break;

  case 1661:
#line 7208 "fgl.yacc"
    {strcpy(yyval.str,"DISTINCT");}
    break;

  case 1662:
#line 7209 "fgl.yacc"
    {strcpy(yyval.str,"DISTINCT");
		ansi_violation("Use DISTINCT not UNIQUE",0);
		strcpy(yyval.str,"DISTINCT ");

}
    break;

  case 1663:
#line 7217 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1664:
#line 7220 "fgl.yacc"
    { 
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",",yyvsp[0].str,0);
		free(yyvsp[-2].sql_string);
	}
    break;

  case 1666:
#line 7228 "fgl.yacc"
    {sprintf(yyval.str," %s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1667:
#line 7229 "fgl.yacc"
    {sprintf(yyval.str," %s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1669:
#line 7239 "fgl.yacc"
    {
			if (strlen(current_upd_table)) push_gen(UPDVAL,yyvsp[0].str);
	}
    break;

  case 1671:
#line 7247 "fgl.yacc"
    {sprintf(yyval.str,"%s%s%s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1672:
#line 7249 "fgl.yacc"
    {sprintf(yyval.str,"%s%s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1673:
#line 7251 "fgl.yacc"
    {sprintf(yyval.str,"%s%s%s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1674:
#line 7253 "fgl.yacc"
    {sprintf(yyval.str,"%s%s%s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1675:
#line 7255 "fgl.yacc"
    {sprintf(yyval.str,"%s%s%s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1680:
#line 7260 "fgl.yacc"
    {sprintf(yyval.str," %s ",yyvsp[0].str);}
    break;

  case 1681:
#line 7262 "fgl.yacc"
    {sprintf(yyval.str,"%s",yyvsp[0].str);}
    break;

  case 1682:
#line 7264 "fgl.yacc"
    {sprintf(yyval.str,"%s%s%s%s%s",yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1683:
#line 7266 "fgl.yacc"
    {sprintf(yyval.str,"%s%s%s%s%s",yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1684:
#line 7268 "fgl.yacc"
    {sprintf(yyval.str,"%s%s%s%s%s",yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1685:
#line 7270 "fgl.yacc"
    {sprintf(yyval.str,"%s(%s%s)",yyvsp[-4].str,yyvsp[-2].str,yyvsp[-1].str);}
    break;

  case 1686:
#line 7272 "fgl.yacc"
    {sprintf(yyval.str,"%s%s%s%s%s",yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1687:
#line 7274 "fgl.yacc"
    {sprintf(yyval.str,"%s%s%s%s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1688:
#line 7276 "fgl.yacc"
    {sprintf(yyval.str,"%s%s%s%s",yyvsp[-5].str,yyvsp[-3].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1689:
#line 7277 "fgl.yacc"
    {sprintf(yyval.str,"%s%s%s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1690:
#line 7278 "fgl.yacc"
    {sprintf(yyval.str,"extend(%s)",yyvsp[-1].str);}
    break;

  case 1695:
#line 7288 "fgl.yacc"
    {

print_unload(yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].sql_string);
print_undo_use(yyvsp[-4].str);
}
    break;

  case 1696:
#line 7296 "fgl.yacc"
    {
print_load(yyvsp[-4].str,yyvsp[-3].str,yyvsp[-1].str,yyvsp[0].str);
print_undo_use(yyvsp[-6].str);
}
    break;

  case 1697:
#line 7301 "fgl.yacc"
    {strcpy(yyval.str,"\"|\"");}
    break;

  case 1698:
#line 7301 "fgl.yacc"
    {
strcpy(yyval.str,yyvsp[0].str);
}
    break;

  case 1700:
#line 7305 "fgl.yacc"
    {
if ((scan_variable(yyvsp[0].str)&15)!=0) {yyerror("Variable must be of type char for a delimiter..");YYERROR;}
}
    break;

  case 1701:
#line 7310 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 1702:
#line 7310 "fgl.yacc"
    {
sprintf(yyval.str,"%s,0",yyvsp[-1].str);
}
    break;

  case 1704:
#line 7314 "fgl.yacc"
    {
    sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 1705:
#line 7318 "fgl.yacc"
    {
     sprintf(yyval.str,"\"%s\"",yyvsp[0].str);
}
    break;

  case 1708:
#line 7327 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1709:
#line 7327 "fgl.yacc"
    {
print_use_session(yyvsp[0].str);
strcpy(yyval.str,get_undo_use());
}
    break;

  case 1714:
#line 7346 "fgl.yacc"
    { sprintf(yyval.str,"%s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str); }
    break;

  case 1715:
#line 7347 "fgl.yacc"
    { sprintf(yyval.str,"%s %s %s %s",yyvsp[-5].str,yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str); }
    break;

  case 1718:
#line 7355 "fgl.yacc"
    {
		sprintf(yyval.str,"%s %s",yyvsp[-1].str,yyvsp[0].str);
	}
    break;

  case 1719:
#line 7361 "fgl.yacc"
    {
		sprintf(yyval.str,"%s %s %s",
					yyvsp[-2].str,
					yyvsp[-1].str,
					yyvsp[0].str
					);
		}
    break;

  case 1722:
#line 7380 "fgl.yacc"
    {strcpy(yyval.str,"UNITS YEAR");}
    break;

  case 1723:
#line 7381 "fgl.yacc"
    {strcpy(yyval.str,"UNITS MONTH"); }
    break;

  case 1724:
#line 7382 "fgl.yacc"
    {strcpy(yyval.str,"UNITS DAY"); }
    break;

  case 1725:
#line 7383 "fgl.yacc"
    {strcpy(yyval.str,"UNITS HOUR"); }
    break;

  case 1726:
#line 7384 "fgl.yacc"
    {strcpy(yyval.str,"UNITS MINUTE"); }
    break;

  case 1727:
#line 7385 "fgl.yacc"
    {strcpy(yyval.str,"UNITS SECOND"); }
    break;

  case 1728:
#line 7389 "fgl.yacc"
    {sprintf(yyval.str,"%s %s %s %s %s",yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1729:
#line 7390 "fgl.yacc"
    {sprintf(yyval.str,"%s %s %s %s %s",yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1730:
#line 7391 "fgl.yacc"
    {sprintf(yyval.str,"%s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1731:
#line 7475 "fgl.yacc"
    {
	if (scan_variable(yyvsp[0].str)!=-1)
	{
		print_push_variable(yyvsp[0].str);
		strcpy(yyval.str,"?");
	}
}
    break;

  case 1732:
#line 7486 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1736:
#line 7492 "fgl.yacc"
    {sprintf(yyval.str,"%s.%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1737:
#line 7493 "fgl.yacc"
    {sprintf(yyval.str,"\\\"%s\\\".%s.%s",strip_quotes(yyvsp[-4].str),yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1741:
#line 7503 "fgl.yacc"
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

  case 1742:
#line 7515 "fgl.yacc"
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

  case 1743:
#line 7613 "fgl.yacc"
    {set_whenever(WHEN_NOTFOUND|atoi(yyvsp[0].str),0);}
    break;

  case 1744:
#line 7615 "fgl.yacc"
    {set_whenever(WHEN_SQLERROR|atoi(yyvsp[0].str),0);}
    break;

  case 1745:
#line 7617 "fgl.yacc"
    {set_whenever(WHEN_ANYERROR|atoi(yyvsp[0].str),0);}
    break;

  case 1746:
#line 7618 "fgl.yacc"
    {
 		set_whento("");
		set_whenever(WHEN_ERROR+WHEN_CONTINUE,0);
}
    break;

  case 1747:
#line 7623 "fgl.yacc"
    {
debug("Whenever error...%d %d",WHEN_ERROR,atoi(yyvsp[0].str));
set_whenever(WHEN_ERROR+atoi(yyvsp[0].str),0);
}
    break;

  case 1748:
#line 7628 "fgl.yacc"
    {set_whenever(WHEN_SQLWARNING|atoi(yyvsp[0].str),0);}
    break;

  case 1749:
#line 7630 "fgl.yacc"
    {set_whenever(WHEN_WARNING|atoi(yyvsp[0].str),0);}
    break;

  case 1750:
#line 7632 "fgl.yacc"
    {set_whenever(WHEN_SUCCESS|atoi(yyvsp[0].str),0);}
    break;

  case 1751:
#line 7634 "fgl.yacc"
    {set_whenever(WHEN_SQLSUCCESS|atoi(yyvsp[0].str),0);}
    break;

  case 1752:
#line 7637 "fgl.yacc"
    {
 set_whento("");
			sprintf(yyval.str,"%d",WHEN_CONTINUE); }
    break;

  case 1753:
#line 7641 "fgl.yacc"
    {
set_whento(yyvsp[0].str);
sprintf(yyval.str,"%d",WHEN_GOTO);
 }
    break;

  case 1754:
#line 7646 "fgl.yacc"
    {
set_whento(yyvsp[0].str); 
sprintf(yyval.str,"%d",WHEN_GOTO);
}
    break;

  case 1755:
#line 7651 "fgl.yacc"
    { set_whento(""); 
sprintf(yyval.str,"%d",WHEN_STOP);
}
    break;

  case 1756:
#line 7655 "fgl.yacc"
    {
set_whento(yyvsp[0].str);
sprintf(yyval.str,"%d",WHEN_CALL);
}
    break;

  case 1758:
#line 7665 "fgl.yacc"
    {sprintf(yyval.str,"%s",yyvsp[0].str);}
    break;

  case 1760:
#line 7680 "fgl.yacc"
    {
print_while_1();
push_blockcommand("WHILE");
}
    break;

  case 1761:
#line 7683 "fgl.yacc"
    {
print_while_2();
}
    break;

  case 1762:
#line 7687 "fgl.yacc"
    {
print_while_3();
pop_blockcommand("WHILE");
}
    break;

  case 1765:
#line 7706 "fgl.yacc"
    { strcpy(yyval.str,"0"); }
    break;

  case 1766:
#line 7707 "fgl.yacc"
    { strcpy(yyval.str,"1"); }
    break;

  case 1767:
#line 7710 "fgl.yacc"
    { print_clr_window("\"screen\""); }
    break;

  case 1768:
#line 7711 "fgl.yacc"
    { print_clr_window(yyvsp[0].str); }
    break;

  case 1769:
#line 7712 "fgl.yacc"
    { print_clr_window(yyvsp[0].str); }
    break;

  case 1770:
#line 7713 "fgl.yacc"
    { print_clr_form(0,0,"0"); }
    break;

  case 1771:
#line 7714 "fgl.yacc"
    { print_clr_form(0,0,"1"); }
    break;

  case 1772:
#line 7715 "fgl.yacc"
    { print_clr_form(yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str); }
    break;

  case 1773:
#line 7716 "fgl.yacc"
    {
	print_clr_fields(yyvsp[-1].str,yyvsp[0].str);
}
    break;

  case 1774:
#line 7721 "fgl.yacc"
    {sprintf(yyval.str,"%s",yyvsp[0].str);}
    break;

  case 1775:
#line 7722 "fgl.yacc"
    {sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1776:
#line 7726 "fgl.yacc"
    {
	print_current_window("\"screen\"");
}
    break;

  case 1777:
#line 7730 "fgl.yacc"
    {
	print_current_window(yyvsp[0].str);
}
    break;

  case 1778:
#line 7734 "fgl.yacc"
    {
sprintf(yyval.str,"cr_window");
reset_attrib(&form_attrib);
}
    break;

  case 1779:
#line 7738 "fgl.yacc"
    {
sprintf(yyval.str,"cr_window_form");
reset_attrib(&form_attrib);
}
    break;

  case 1780:
#line 7743 "fgl.yacc"
    {
	print_show_window(yyvsp[0].str);
	addmap("Show Window",yyvsp[0].str,curr_func,yylineno,infilename); 
}
    break;

  case 1781:
#line 7747 "fgl.yacc"
    {
	print_show_menu(yyvsp[-3].str,yyvsp[-1].str);
	addmap("Call Menuhandler",yyvsp[-1].str,curr_func,yylineno,infilename); 
}
    break;

  case 1782:
#line 7752 "fgl.yacc"
    {

print_def_mn_file();

}
    break;

  case 1784:
#line 7760 "fgl.yacc"
    {addmap("Use Menu",yyvsp[0].str,curr_func,yylineno,infilename); }
    break;

  case 1786:
#line 7766 "fgl.yacc"
    {
	print_hide_window(yyvsp[0].str);
}
    break;

  case 1787:
#line 7772 "fgl.yacc"
    {
print_move_window(yyvsp[-4].str,0);
}
    break;

  case 1788:
#line 7776 "fgl.yacc"
    {
print_move_window(yyvsp[-4].str,1);
}
    break;

  case 1793:
#line 7794 "fgl.yacc"
    {
chk4var=0;lex_printcomment("/* [Comm:%s] */\n",yyval.str);
if (acl_getenv("INCLINES"))
lex_printc("{debug(\"Line %d %s:%s\");}",lastlineno,infilename,convstrsql(larr));
	prchkerr(lastlineno,infilename);
	lastlineno=yylineno;
}
    break;

  case 1794:
#line 7801 "fgl.yacc"
    {
lex_printcomment("/* [COMM:%s] */\n",yyvsp[0].str);chk4var=0;
if (acl_getenv("INCLINES"))
lex_printc("{debug(\"Line %d %s:%s\");}",lastlineno,infilename,convstrsql(larr));
if (aubit_strcasecmp(yyval.str,"whenever")!=0) prchkerr(lastlineno,infilename);
lastlineno=yylineno;
}
    break;

  case 1795:
#line 7810 "fgl.yacc"
    {print_cmd_start();}
    break;

  case 1796:
#line 7810 "fgl.yacc"
    {print_cmd_end();}
    break;


    }

/* Line 991 of yacc.c.  */
#line 16176 "y.tab.c"

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


#line 7903 "fgl.yacc"

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



