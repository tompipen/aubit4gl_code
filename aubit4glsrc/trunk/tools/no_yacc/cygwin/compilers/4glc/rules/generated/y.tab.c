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
     NAME = 1631,
     UMINUS = 1632,
     COMMA = 1547,
     KW_OR = 1587,
     KW_AND = 1542,
     KW_USING = 1478,
     MATCHES = 1357,
     POWER = 1465,
     LESS_THAN = 1461,
     GREATER_THAN = 1375,
     EQUAL = 1537,
     GREATER_THAN_EQ = 1274,
     LESS_THAN_EQ = 1332,
     NOT_EQUAL = 1406,
     PLUS = 1573,
     MINUS = 1560,
     DIVIDE = 1493,
     MULTIPLY = 1466,
     MOD = 1561,
     COMMAND = 1339,
     NUMBER_VALUE = 1633,
     CHAR_VALUE = 1634,
     INT_VALUE = 1635,
     NAMED_GEN = 1636,
     CLINE = 1637,
     SQLLINE = 1638,
     KW_CSTART = 1639,
     KW_CEND = 1640,
     USER_DTYPE = 1641,
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
     END_CONSTRUCT = 1135,
     FIELD_TOUCHED = 1136,
     FINISH_REPORT = 1137,
     INFACC = 1138,
     INPUT_NO_WRAP = 1139,
     LOCKMODEPAGE = 1140,
     SETPMOFF = 1141,
     UNCONSTRAINED = 1142,
     PAGE_TRAILER = 1143,
     SETPMON = 1144,
     BEFGROUP = 1145,
     CLOSE_WINDOW = 1146,
     COMMENT_LINE = 1147,
     CONTINUE_FOR = 1148,
     CREATE_DB = 1149,
     CREATE_TABLE = 1150,
     DEFAULT_NULL = 1151,
     DELETE_USING = 1152,
     DISPLAY_FORM = 1153,
     END_FUNCTION = 1154,
     EXIT_DISPLAY = 1155,
     EXIT_FOREACH = 1156,
     EXIT_PROGRAM = 1157,
     INFCOLS = 1158,
     LOCKMODEROW = 1159,
     ON_EVERY_ROW = 1160,
     OPEN_SESSION = 1161,
     RIGHT_MARGIN = 1162,
     SELECT_USING = 1163,
     START_REPORT = 1164,
     UNLOCK_TABLE = 1165,
     UPDATE_USING = 1166,
     ACL_BUILTIN = 1167,
     AFTGROUP = 1168,
     INFIDX = 1169,
     INFSTAT = 1170,
     LEFT_MARGIN = 1171,
     PAGE_HEADER = 1172,
     ROLLBACK_W = 1173,
     SET_SESSION = 1174,
     SQLSEOFF = 1175,
     WITH_A_LOG = 1176,
     BEFDISP = 1177,
     BEFORE_MENU = 1178,
     CREATE_VIEW = 1179,
     DEFINE_TYPE = 1180,
     DELETE_FROM = 1181,
     END_DISPLAY = 1182,
     END_REPORT = 1183,
     END_FOREACH = 1184,
     END_FOR = 1185,
     END_GLOBALS = 1186,
     EXIT_PROMPT = 1187,
     EXTENT_SIZE = 1188,
     FOREIGN_KEY = 1189,
     HIDE_OPTION = 1190,
     HIDE_WINDOW = 1191,
     INSERT_INTO = 1192,
     IS_NOT_NULL = 1193,
     MOVE_WINDOW = 1194,
     NEXT_OPTION = 1195,
     NOT_MATCHES = 1196,
     ON_LAST_ROW = 1197,
     OPEN_WINDOW = 1198,
     OPEN_STATUSBOX = 1199,
     PAGE_LENGTH = 1200,
     PAGE_WIDTH = 1201,
     PRIMARY_KEY = 1202,
     PROMPT_LINE = 1203,
     RECORD_LIKE = 1204,
     ROLLFORWARD = 1205,
     SETBL = 1206,
     SHOW_OPTION = 1207,
     SHOW_WINDOW = 1208,
     SQLSEON = 1209,
     TO_DATABASE = 1210,
     USE_SESSION = 1211,
     WITH_NO_LOG = 1212,
     AFTDISP = 1213,
     BEFFIELD = 1214,
     INSHARE = 1215,
     UNLOCKTAB = 1216,
     AFTFIELD = 1217,
     ATTRIBUTES = 1218,
     BEFINP = 1219,
     BEGIN_WORK = 1220,
     CLEARWIN = 1221,
     CLOSE_FORM = 1222,
     DEFER_QUIT = 1223,
     DESCENDING = 1224,
     DROP_INDEX = 1225,
     END_PROMPT = 1226,
     END_RECORD = 1227,
     ERROR_LINE = 1228,
     EXIT_INPUT = 1229,
     EXIT_WHILE = 1230,
     FOR_UPDATE_OF = 1231,
     FOR_UPDATE = 1232,
     GET_FLDBUF = 1233,
     INITIALIZE = 1234,
     INPUT_WRAP = 1235,
     LOCK_TABLE = 1236,
     MSG_LINE = 1237,
     NOT_EXISTS = 1238,
     ON_ANY_KEY = 1239,
     REFERENCES = 1240,
     RENCOL = 1241,
     SET_CURSOR = 1242,
     SMALLFLOAT = 1243,
     SQLSUCCESS = 1244,
     TOP_MARGIN = 1245,
     WITH_ARRAY = 1246,
     ACCEPTKEY = 1247,
     ACCEPT = 1248,
     AFTINP = 1249,
     CLEARFORMTODEFAULTS = 1250,
     CLEARFORM = 1251,
     CLEAR_X_FORM = 1252,
     COMMIT_W = 1253,
     NEXTPAGE = 1254,
     PREVPAGE = 1255,
     CTRL_KEY = 1256,
     INFTABS = 1257,
     NEXTFIELD = 1258,
     NEXTFORM = 1259,
     RENTAB = 1260,
     ASCENDING = 1261,
     ASSOCIATE = 1262,
     CHARACTER = 1263,
     CONSTRUCT = 1264,
     DELIMITER = 1265,
     DOWNSHIFT = 1266,
     DROP_VIEW = 1267,
     END_INPUT = 1268,
     END_WHILE = 1269,
     EXCLUSIVE = 1270,
     EXIT_CASE = 1271,
     EXIT_MENU = 1272,
     FORM_LINE = 1273,
     INTERRUPT = 1275,
     INTO_TEMP = 1276,
     INVISIBLE = 1277,
     IN_MEMORY = 1278,
     LINKED_TO = 1279,
     LOAD_FROM = 1280,
     LOCKTAB = 1281,
     MENU_LINE = 1282,
     OPEN_FORM = 1283,
     OTHERWISE = 1284,
     PRECISION = 1285,
     PRIOR = 1286,
     PROCEDURE = 1287,
     REPORT_TO = 1288,
     RETURNING = 1289,
     UNDERLINE = 1290,
     UNLOAD_TO = 1291,
     BEFROW = 1292,
     UNLOAD_T = 1293,
     VARIABLE = 1294,
     ABSOLUTE = 1295,
     AFTROW = 1296,
     BUFFERED = 1297,
     CONSTANT = 1298,
     CONST = 1299,
     CONTINUE = 1300,
     DATABASE = 1301,
     DATETIME = 1302,
     DEFAULTS = 1303,
     DISTINCT = 1304,
     END_CASE = 1305,
     END_MAIN = 1306,
     END_MENU = 1307,
     END_TYPE = 1308,
     EXIT_FOR = 1309,
     EXTERNAL = 1310,
     FRACTION = 1311,
     FUNCTION = 1312,
     GROUP_BY = 1313,
     INTERVAL = 1314,
     KWMESSAGE = 1315,
     NOT_LIKE = 1316,
     NOT_NULL = 1317,
     PASSWORD = 1318,
     PREVIOUS = 1319,
     READONLY = 1320,
     REGISTER = 1321,
     RELATIVE = 1322,
     RESOURCE = 1323,
     SMALLINT = 1324,
     VALIDATE = 1325,
     WHENEVER = 1326,
     WITH_LOG = 1327,
     WORDWRAP = 1328,
     BY_NAME = 1329,
     IN_FILE = 1330,
     IS_NULL = 1331,
     AVERAGE = 1333,
     BETWEEN = 1334,
     CAPTION = 1335,
     CLIPPED = 1336,
     CLOSE_BRACKET = 1337,
     COLUMNS = 1338,
     COMMENT = 1340,
     CONNECT = 1341,
     CURRENT = 1342,
     DBYNAME = 1343,
     DECIMAL = 1344,
     DECLARE = 1345,
     DEFAULT = 1346,
     DISPLAY = 1347,
     ENDCODE = 1348,
     EXECUTE = 1349,
     FOREACH = 1350,
     FOREIGN = 1351,
     GLOBALS = 1352,
     INFIELD = 1353,
     INTEGER = 1354,
     KWWINDOW = 1355,
     MAGENTA = 1356,
     NUMERIC = 1358,
     OPTIONS = 1359,
     PERCENT = 1360,
     PREPARE = 1361,
     PROGRAM = 1362,
     RECOVER = 1363,
     REVERSE = 1364,
     SECTION = 1365,
     SESSION = 1366,
     SYNONYM = 1367,
     THRU = 1368,
     TRAILER = 1369,
     UPSHIFT = 1370,
     VARCHAR = 1371,
     WAITING = 1372,
     CLOSE_SHEV = 1373,
     CLOSE_SQUARE = 1374,
     KW_FALSE = 1376,
     NOT_IN = 1377,
     ONKEY = 1378,
     OPEN_BRACKET = 1379,
     BORDER = 1380,
     BOTTOM = 1381,
     COLUMN = 1382,
     COMMIT = 1383,
     CREATE = 1384,
     CURSOR = 1385,
     DEFINE = 1386,
     DELETE = 1387,
     DOUBLE = 1388,
     END_IF = 1389,
     ESCAPE = 1390,
     EXISTS = 1391,
     EXTEND = 1392,
     EXTENT = 1393,
     FINISH = 1394,
     FORMAT = 1395,
     HAVING = 1396,
     HEADER = 1397,
     INSERT = 1398,
     LOCATE = 1399,
     MARGIN = 1400,
     MEMORY = 1401,
     MINUTE = 1402,
     MODIFY = 1403,
     NORMAL = 1404,
     EQUAL_EQUAL = 1405,
     OPEN_SHEV = 1407,
     OPEN_SQUARE = 1408,
     OPTION = 1409,
     OUTPUT = 1410,
     PROMPT = 1411,
     PUBLIC = 1412,
     RECORD = 1413,
     REPORT = 1414,
     RETURN = 1415,
     REVOKE = 1416,
     SCHEMA = 1417,
     SCROLL_USING = 1418,
     SCROLL = 1419,
     SECOND = 1420,
     SELECT = 1421,
     SERIAL = 1422,
     SETL = 1423,
     SHARED = 1424,
     SPACES = 1425,
     UNIQUE = 1426,
     UNLOCK = 1427,
     UPDATE = 1428,
     VALUES = 1429,
     YELLOW = 1430,
     AFTER = 1431,
     KWLINE = 1432,
     KW_NULL = 1433,
     KW_TRUE = 1434,
     SINGLE_KEY = 1435,
     ALTER = 1436,
     ARRAY = 1437,
     ASCII = 1438,
     AUDIT = 1439,
     BLACK = 1440,
     BLINK = 1441,
     CHECK = 1442,
     CLEAR = 1443,
     CLOSE = 1444,
     CODE_C = 1445,
     COUNT = 1446,
     DEFER = 1447,
     ERROR = 1448,
     EVERY = 1449,
     FETCH = 1450,
     FIRST = 1451,
     FLOAT = 1452,
     FLUSH = 1453,
     FOUND = 1454,
     GRANT = 1455,
     GREEN = 1456,
     GROUP = 1457,
     INDEX = 1458,
     KWFORM = 1459,
     LABEL = 1460,
     LOCAL = 1462,
     MONEY = 1463,
     MONTH = 1464,
     ORDER = 1467,
     OUTER = 1468,
     PAUSE = 1469,
     PRINT_IMAGE = 1470,
     PRINT_FILE = 1471,
     PRINT = 1472,
     RIGHT = 1473,
     SEMICOLON = 1474,
     SLEEP = 1475,
     TUPLE = 1476,
     UNION = 1477,
     WHERE = 1479,
     WHILE = 1480,
     WHITE = 1481,
     CCODE = 1482,
     ANSI = 1483,
     BLUE = 1484,
     BOLD = 1485,
     BYTE = 1486,
     FCALL = 1487,
     CASE = 1488,
     CHAR = 1489,
     CYAN = 1490,
     DATE = 1491,
     DESC = 1492,
     DOWN = 1494,
     TAB = 1495,
     DROP = 1496,
     ELSE = 1497,
     EXEC = 1498,
     EXIT = 1499,
     FREE = 1500,
     FROM = 1501,
     GOTO = 1502,
     HELP_FILE = 1503,
     LANG_FILE = 1504,
     HELP = 1505,
     HIDE = 1506,
     HOUR = 1507,
     INTO = 1508,
     LAST = 1509,
     LEFT = 1510,
     LIKE = 1511,
     MAIN = 1512,
     MENU = 1513,
     MODE = 1514,
     NEED = 1515,
     NEXT = 1516,
     NOCR = 1517,
     OPEN = 1518,
     QUIT = 1519,
     REAL = 1520,
     ROWS = 1521,
     SHOW = 1522,
     SIZE = 1523,
     SKIP = 1524,
     SOME = 1525,
     STEP = 1526,
     STOP = 1527,
     TEMP = 1528,
     TEXT = 1529,
     THEN = 1530,
     USER = 1531,
     WAIT = 1532,
     WHEN = 1533,
     WITH = 1534,
     WORK = 1535,
     YEAR = 1536,
     KW_IS = 1538,
     XSET = 1539,
     ADD = 1540,
     ALL = 1541,
     ANY = 1543,
     ASC = 1544,
     AVG = 1545,
     COLON = 1546,
     DAY = 1548,
     DBA = 1549,
     DEC = 1550,
     DIM = 1551,
     FKEY = 1552,
     FOR = 1553,
     KEY = 1554,
     KWNO = 1555,
     LET = 1556,
     LOG = 1557,
     XMAX = 1558,
     XMIN = 1559,
     NOT = 1562,
     PAD = 1563,
     PUT = 1564,
     RED = 1565,
     ROW = 1566,
     RUN = 1567,
     SQL = 1568,
     SUM = 1569,
     TOP = 1570,
     USE = 1571,
     ATSIGN = 1572,
     AS_TIFF = 1574,
     AS_GIF = 1575,
     AS_PNG = 1576,
     AS_JPEG = 1577,
     AS = 1578,
     AT = 1579,
     BY = 1580,
     DOT = 1581,
     GO = 1582,
     IF = 1583,
     IN = 1584,
     OF = 1585,
     ON = 1586,
     TO = 1588,
     UP = 1589,
     FONT_NAME = 1590,
     FONT_SIZE = 1591,
     PAPER_SIZE_IS_LETTER = 1592,
     PAPER_SIZE_IS_LEGAL = 1593,
     PAPER_SIZE_IS_A5 = 1594,
     PAPER_SIZE_IS_A4 = 1595,
     PAPER_SIZE_IS_LETTER_L = 1596,
     PAPER_SIZE_IS_LEGAL_L = 1597,
     PAPER_SIZE_IS_A5_L = 1598,
     PAPER_SIZE_IS_A4_L = 1599,
     FORMHANDLER = 1600,
     END_FORMHANDLER = 1601,
     BEFORE_EVENT = 1602,
     BEFORE_OPEN_FORM = 1603,
     AFTER_EVENT = 1604,
     BEFORE_CLOSE_FORM = 1605,
     BEFORE_ANY = 1606,
     AFTER_ANY = 1607,
     MENUHANDLER = 1608,
     END_MENUHANDLER = 1609,
     BEFORE_SHOW_MENU = 1610,
     DISABLE_PROGRAM = 1611,
     DISABLE_ALL = 1612,
     BUTTONS = 1613,
     CHECK_MENUITEM = 1614,
     DISABLE_FORM = 1615,
     DISABLE_MENUITEMS = 1616,
     DISABLE = 1617,
     ENABLE_FORM = 1618,
     ENABLE_MENUITEMS = 1619,
     ENABLE = 1620,
     KWFIELD = 1621,
     ICON = 1622,
     MESSAGEBOX = 1623,
     TO_DEFAULTS = 1624,
     UNCHECK_MENUITEM = 1625,
     BEFORE = 1626,
     INPUT = 1627,
     END = 1628,
     INT_TO_ID = 1629
   };
#endif
#define NAME 1631
#define UMINUS 1632
#define COMMA 1547
#define KW_OR 1587
#define KW_AND 1542
#define KW_USING 1478
#define MATCHES 1357
#define POWER 1465
#define LESS_THAN 1461
#define GREATER_THAN 1375
#define EQUAL 1537
#define GREATER_THAN_EQ 1274
#define LESS_THAN_EQ 1332
#define NOT_EQUAL 1406
#define PLUS 1573
#define MINUS 1560
#define DIVIDE 1493
#define MULTIPLY 1466
#define MOD 1561
#define COMMAND 1339
#define NUMBER_VALUE 1633
#define CHAR_VALUE 1634
#define INT_VALUE 1635
#define NAMED_GEN 1636
#define CLINE 1637
#define SQLLINE 1638
#define KW_CSTART 1639
#define KW_CEND 1640
#define USER_DTYPE 1641
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
#define END_CONSTRUCT 1135
#define FIELD_TOUCHED 1136
#define FINISH_REPORT 1137
#define INFACC 1138
#define INPUT_NO_WRAP 1139
#define LOCKMODEPAGE 1140
#define SETPMOFF 1141
#define UNCONSTRAINED 1142
#define PAGE_TRAILER 1143
#define SETPMON 1144
#define BEFGROUP 1145
#define CLOSE_WINDOW 1146
#define COMMENT_LINE 1147
#define CONTINUE_FOR 1148
#define CREATE_DB 1149
#define CREATE_TABLE 1150
#define DEFAULT_NULL 1151
#define DELETE_USING 1152
#define DISPLAY_FORM 1153
#define END_FUNCTION 1154
#define EXIT_DISPLAY 1155
#define EXIT_FOREACH 1156
#define EXIT_PROGRAM 1157
#define INFCOLS 1158
#define LOCKMODEROW 1159
#define ON_EVERY_ROW 1160
#define OPEN_SESSION 1161
#define RIGHT_MARGIN 1162
#define SELECT_USING 1163
#define START_REPORT 1164
#define UNLOCK_TABLE 1165
#define UPDATE_USING 1166
#define ACL_BUILTIN 1167
#define AFTGROUP 1168
#define INFIDX 1169
#define INFSTAT 1170
#define LEFT_MARGIN 1171
#define PAGE_HEADER 1172
#define ROLLBACK_W 1173
#define SET_SESSION 1174
#define SQLSEOFF 1175
#define WITH_A_LOG 1176
#define BEFDISP 1177
#define BEFORE_MENU 1178
#define CREATE_VIEW 1179
#define DEFINE_TYPE 1180
#define DELETE_FROM 1181
#define END_DISPLAY 1182
#define END_REPORT 1183
#define END_FOREACH 1184
#define END_FOR 1185
#define END_GLOBALS 1186
#define EXIT_PROMPT 1187
#define EXTENT_SIZE 1188
#define FOREIGN_KEY 1189
#define HIDE_OPTION 1190
#define HIDE_WINDOW 1191
#define INSERT_INTO 1192
#define IS_NOT_NULL 1193
#define MOVE_WINDOW 1194
#define NEXT_OPTION 1195
#define NOT_MATCHES 1196
#define ON_LAST_ROW 1197
#define OPEN_WINDOW 1198
#define OPEN_STATUSBOX 1199
#define PAGE_LENGTH 1200
#define PAGE_WIDTH 1201
#define PRIMARY_KEY 1202
#define PROMPT_LINE 1203
#define RECORD_LIKE 1204
#define ROLLFORWARD 1205
#define SETBL 1206
#define SHOW_OPTION 1207
#define SHOW_WINDOW 1208
#define SQLSEON 1209
#define TO_DATABASE 1210
#define USE_SESSION 1211
#define WITH_NO_LOG 1212
#define AFTDISP 1213
#define BEFFIELD 1214
#define INSHARE 1215
#define UNLOCKTAB 1216
#define AFTFIELD 1217
#define ATTRIBUTES 1218
#define BEFINP 1219
#define BEGIN_WORK 1220
#define CLEARWIN 1221
#define CLOSE_FORM 1222
#define DEFER_QUIT 1223
#define DESCENDING 1224
#define DROP_INDEX 1225
#define END_PROMPT 1226
#define END_RECORD 1227
#define ERROR_LINE 1228
#define EXIT_INPUT 1229
#define EXIT_WHILE 1230
#define FOR_UPDATE_OF 1231
#define FOR_UPDATE 1232
#define GET_FLDBUF 1233
#define INITIALIZE 1234
#define INPUT_WRAP 1235
#define LOCK_TABLE 1236
#define MSG_LINE 1237
#define NOT_EXISTS 1238
#define ON_ANY_KEY 1239
#define REFERENCES 1240
#define RENCOL 1241
#define SET_CURSOR 1242
#define SMALLFLOAT 1243
#define SQLSUCCESS 1244
#define TOP_MARGIN 1245
#define WITH_ARRAY 1246
#define ACCEPTKEY 1247
#define ACCEPT 1248
#define AFTINP 1249
#define CLEARFORMTODEFAULTS 1250
#define CLEARFORM 1251
#define CLEAR_X_FORM 1252
#define COMMIT_W 1253
#define NEXTPAGE 1254
#define PREVPAGE 1255
#define CTRL_KEY 1256
#define INFTABS 1257
#define NEXTFIELD 1258
#define NEXTFORM 1259
#define RENTAB 1260
#define ASCENDING 1261
#define ASSOCIATE 1262
#define CHARACTER 1263
#define CONSTRUCT 1264
#define DELIMITER 1265
#define DOWNSHIFT 1266
#define DROP_VIEW 1267
#define END_INPUT 1268
#define END_WHILE 1269
#define EXCLUSIVE 1270
#define EXIT_CASE 1271
#define EXIT_MENU 1272
#define FORM_LINE 1273
#define INTERRUPT 1275
#define INTO_TEMP 1276
#define INVISIBLE 1277
#define IN_MEMORY 1278
#define LINKED_TO 1279
#define LOAD_FROM 1280
#define LOCKTAB 1281
#define MENU_LINE 1282
#define OPEN_FORM 1283
#define OTHERWISE 1284
#define PRECISION 1285
#define PRIOR 1286
#define PROCEDURE 1287
#define REPORT_TO 1288
#define RETURNING 1289
#define UNDERLINE 1290
#define UNLOAD_TO 1291
#define BEFROW 1292
#define UNLOAD_T 1293
#define VARIABLE 1294
#define ABSOLUTE 1295
#define AFTROW 1296
#define BUFFERED 1297
#define CONSTANT 1298
#define CONST 1299
#define CONTINUE 1300
#define DATABASE 1301
#define DATETIME 1302
#define DEFAULTS 1303
#define DISTINCT 1304
#define END_CASE 1305
#define END_MAIN 1306
#define END_MENU 1307
#define END_TYPE 1308
#define EXIT_FOR 1309
#define EXTERNAL 1310
#define FRACTION 1311
#define FUNCTION 1312
#define GROUP_BY 1313
#define INTERVAL 1314
#define KWMESSAGE 1315
#define NOT_LIKE 1316
#define NOT_NULL 1317
#define PASSWORD 1318
#define PREVIOUS 1319
#define READONLY 1320
#define REGISTER 1321
#define RELATIVE 1322
#define RESOURCE 1323
#define SMALLINT 1324
#define VALIDATE 1325
#define WHENEVER 1326
#define WITH_LOG 1327
#define WORDWRAP 1328
#define BY_NAME 1329
#define IN_FILE 1330
#define IS_NULL 1331
#define AVERAGE 1333
#define BETWEEN 1334
#define CAPTION 1335
#define CLIPPED 1336
#define CLOSE_BRACKET 1337
#define COLUMNS 1338
#define COMMENT 1340
#define CONNECT 1341
#define CURRENT 1342
#define DBYNAME 1343
#define DECIMAL 1344
#define DECLARE 1345
#define DEFAULT 1346
#define DISPLAY 1347
#define ENDCODE 1348
#define EXECUTE 1349
#define FOREACH 1350
#define FOREIGN 1351
#define GLOBALS 1352
#define INFIELD 1353
#define INTEGER 1354
#define KWWINDOW 1355
#define MAGENTA 1356
#define NUMERIC 1358
#define OPTIONS 1359
#define PERCENT 1360
#define PREPARE 1361
#define PROGRAM 1362
#define RECOVER 1363
#define REVERSE 1364
#define SECTION 1365
#define SESSION 1366
#define SYNONYM 1367
#define THRU 1368
#define TRAILER 1369
#define UPSHIFT 1370
#define VARCHAR 1371
#define WAITING 1372
#define CLOSE_SHEV 1373
#define CLOSE_SQUARE 1374
#define KW_FALSE 1376
#define NOT_IN 1377
#define ONKEY 1378
#define OPEN_BRACKET 1379
#define BORDER 1380
#define BOTTOM 1381
#define COLUMN 1382
#define COMMIT 1383
#define CREATE 1384
#define CURSOR 1385
#define DEFINE 1386
#define DELETE 1387
#define DOUBLE 1388
#define END_IF 1389
#define ESCAPE 1390
#define EXISTS 1391
#define EXTEND 1392
#define EXTENT 1393
#define FINISH 1394
#define FORMAT 1395
#define HAVING 1396
#define HEADER 1397
#define INSERT 1398
#define LOCATE 1399
#define MARGIN 1400
#define MEMORY 1401
#define MINUTE 1402
#define MODIFY 1403
#define NORMAL 1404
#define EQUAL_EQUAL 1405
#define OPEN_SHEV 1407
#define OPEN_SQUARE 1408
#define OPTION 1409
#define OUTPUT 1410
#define PROMPT 1411
#define PUBLIC 1412
#define RECORD 1413
#define REPORT 1414
#define RETURN 1415
#define REVOKE 1416
#define SCHEMA 1417
#define SCROLL_USING 1418
#define SCROLL 1419
#define SECOND 1420
#define SELECT 1421
#define SERIAL 1422
#define SETL 1423
#define SHARED 1424
#define SPACES 1425
#define UNIQUE 1426
#define UNLOCK 1427
#define UPDATE 1428
#define VALUES 1429
#define YELLOW 1430
#define AFTER 1431
#define KWLINE 1432
#define KW_NULL 1433
#define KW_TRUE 1434
#define SINGLE_KEY 1435
#define ALTER 1436
#define ARRAY 1437
#define ASCII 1438
#define AUDIT 1439
#define BLACK 1440
#define BLINK 1441
#define CHECK 1442
#define CLEAR 1443
#define CLOSE 1444
#define CODE_C 1445
#define COUNT 1446
#define DEFER 1447
#define ERROR 1448
#define EVERY 1449
#define FETCH 1450
#define FIRST 1451
#define FLOAT 1452
#define FLUSH 1453
#define FOUND 1454
#define GRANT 1455
#define GREEN 1456
#define GROUP 1457
#define INDEX 1458
#define KWFORM 1459
#define LABEL 1460
#define LOCAL 1462
#define MONEY 1463
#define MONTH 1464
#define ORDER 1467
#define OUTER 1468
#define PAUSE 1469
#define PRINT_IMAGE 1470
#define PRINT_FILE 1471
#define PRINT 1472
#define RIGHT 1473
#define SEMICOLON 1474
#define SLEEP 1475
#define TUPLE 1476
#define UNION 1477
#define WHERE 1479
#define WHILE 1480
#define WHITE 1481
#define CCODE 1482
#define ANSI 1483
#define BLUE 1484
#define BOLD 1485
#define BYTE 1486
#define FCALL 1487
#define CASE 1488
#define CHAR 1489
#define CYAN 1490
#define DATE 1491
#define DESC 1492
#define DOWN 1494
#define TAB 1495
#define DROP 1496
#define ELSE 1497
#define EXEC 1498
#define EXIT 1499
#define FREE 1500
#define FROM 1501
#define GOTO 1502
#define HELP_FILE 1503
#define LANG_FILE 1504
#define HELP 1505
#define HIDE 1506
#define HOUR 1507
#define INTO 1508
#define LAST 1509
#define LEFT 1510
#define LIKE 1511
#define MAIN 1512
#define MENU 1513
#define MODE 1514
#define NEED 1515
#define NEXT 1516
#define NOCR 1517
#define OPEN 1518
#define QUIT 1519
#define REAL 1520
#define ROWS 1521
#define SHOW 1522
#define SIZE 1523
#define SKIP 1524
#define SOME 1525
#define STEP 1526
#define STOP 1527
#define TEMP 1528
#define TEXT 1529
#define THEN 1530
#define USER 1531
#define WAIT 1532
#define WHEN 1533
#define WITH 1534
#define WORK 1535
#define YEAR 1536
#define KW_IS 1538
#define XSET 1539
#define ADD 1540
#define ALL 1541
#define ANY 1543
#define ASC 1544
#define AVG 1545
#define COLON 1546
#define DAY 1548
#define DBA 1549
#define DEC 1550
#define DIM 1551
#define FKEY 1552
#define FOR 1553
#define KEY 1554
#define KWNO 1555
#define LET 1556
#define LOG 1557
#define XMAX 1558
#define XMIN 1559
#define NOT 1562
#define PAD 1563
#define PUT 1564
#define RED 1565
#define ROW 1566
#define RUN 1567
#define SQL 1568
#define SUM 1569
#define TOP 1570
#define USE 1571
#define ATSIGN 1572
#define AS_TIFF 1574
#define AS_GIF 1575
#define AS_PNG 1576
#define AS_JPEG 1577
#define AS 1578
#define AT 1579
#define BY 1580
#define DOT 1581
#define GO 1582
#define IF 1583
#define IN 1584
#define OF 1585
#define ON 1586
#define TO 1588
#define UP 1589
#define FONT_NAME 1590
#define FONT_SIZE 1591
#define PAPER_SIZE_IS_LETTER 1592
#define PAPER_SIZE_IS_LEGAL 1593
#define PAPER_SIZE_IS_A5 1594
#define PAPER_SIZE_IS_A4 1595
#define PAPER_SIZE_IS_LETTER_L 1596
#define PAPER_SIZE_IS_LEGAL_L 1597
#define PAPER_SIZE_IS_A5_L 1598
#define PAPER_SIZE_IS_A4_L 1599
#define FORMHANDLER 1600
#define END_FORMHANDLER 1601
#define BEFORE_EVENT 1602
#define BEFORE_OPEN_FORM 1603
#define AFTER_EVENT 1604
#define BEFORE_CLOSE_FORM 1605
#define BEFORE_ANY 1606
#define AFTER_ANY 1607
#define MENUHANDLER 1608
#define END_MENUHANDLER 1609
#define BEFORE_SHOW_MENU 1610
#define DISABLE_PROGRAM 1611
#define DISABLE_ALL 1612
#define BUTTONS 1613
#define CHECK_MENUITEM 1614
#define DISABLE_FORM 1615
#define DISABLE_MENUITEMS 1616
#define DISABLE 1617
#define ENABLE_FORM 1618
#define ENABLE_MENUITEMS 1619
#define ENABLE 1620
#define KWFIELD 1621
#define ICON 1622
#define MESSAGEBOX 1623
#define TO_DEFAULTS 1624
#define UNCHECK_MENUITEM 1625
#define BEFORE 1626
#define INPUT 1627
#define END 1628
#define INT_TO_ID 1629




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
#line 184 "fgl.yacc"
typedef union YYSTYPE {



	char	str[3100];  /* This would core dump in CygWin on call to */
						/* yyparse in y.tab.c - 3100 in maximum. */
						/* Was: char	str[20000]; */

	struct expr_str *ptr;

	} YYSTYPE;
/* Line 191 of yacc.c.  */
#line 1489 "y.tab.c"
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 214 of yacc.c.  */
#line 1501 "y.tab.c"

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
#define YYLAST   8092

/* YYNTOKENS -- Number of terminals. */
#define YYNTOKENS  644
/* YYNNTS -- Number of nonterminals. */
#define YYNNTS  808
/* YYNRULES -- Number of rules. */
#define YYNRULES  1858
/* YYNRULES -- Number of states. */
#define YYNSTATES  3068

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   1641

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
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    93,    94,    95,    96,    97,    98,    99,   100,   101,
     102,   103,   104,   105,   106,   107,   108,   109,   110,   111,
     112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
     132,   133,   134,   135,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,   146,   147,   148,   149,   150,   151,
     152,   153,   154,   155,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   173,   174,   175,   176,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,   193,   194,   195,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,   256,   257,   258,   259,   260,   261,
     262,   263,   264,   265,   266,   267,   268,   269,   270,   271,
     272,   273,   274,   275,   276,   277,   278,   279,   280,   281,
     282,   283,   284,   285,   286,   287,   288,   289,   290,   291,
     292,   293,   294,   295,   296,   297,   298,   299,   300,   301,
     302,   303,   304,   305,    14,   306,   307,   308,   309,   310,
     311,   312,   313,   314,   315,   316,   317,   318,   319,   320,
     321,   322,   323,   324,   325,   326,   327,   328,   329,   330,
     331,   332,   333,   334,   335,   336,   337,   338,   339,   340,
     341,   342,   343,   344,   345,   346,   347,   348,   349,   350,
     351,   352,   353,   354,   355,   356,   357,   358,   359,   360,
     361,   362,    15,   363,   364,   365,   366,   367,   368,    22,
     369,   370,   371,   372,   373,   374,   375,   376,   377,   378,
     379,   380,   381,   382,   383,   384,   385,     9,   386,   387,
     388,   389,   390,   391,   392,   393,   394,   395,   396,   397,
     398,   399,   400,   401,   402,    12,   403,   404,   405,   406,
     407,   408,   409,   410,   411,   412,   413,   414,   415,   416,
     417,   418,   419,   420,   421,   422,   423,   424,   425,   426,
     427,   428,   429,   430,   431,   432,    16,   433,   434,   435,
     436,   437,   438,   439,   440,   441,   442,   443,   444,   445,
     446,   447,   448,   449,   450,   451,   452,   453,   454,   455,
     456,   457,   458,   459,   460,   461,   462,   463,   464,   465,
     466,   467,   468,   469,   470,   471,   472,   473,   474,   475,
     476,   477,   478,   479,   480,   481,   482,   483,   484,   485,
     486,    11,   487,   488,   489,    10,    20,   490,   491,   492,
     493,   494,   495,   496,   497,   498,   499,   500,     8,   501,
     502,   503,   504,   505,   506,   507,   508,   509,   510,   511,
     512,   513,   514,    19,   515,   516,   517,   518,   519,   520,
     521,   522,   523,   524,   525,   526,   527,   528,   529,   530,
     531,   532,   533,   534,   535,   536,   537,   538,   539,   540,
     541,   542,   543,   544,   545,   546,   547,   548,   549,   550,
     551,   552,   553,   554,   555,   556,   557,    13,   558,   559,
     560,   561,     7,   562,   563,   564,   565,     5,   566,   567,
     568,   569,   570,   571,   572,   573,   574,   575,   576,   577,
      18,    21,   578,   579,   580,   581,   582,   583,   584,   585,
     586,   587,   588,    17,   589,   590,   591,   592,   593,   594,
     595,   596,   597,   598,   599,   600,   601,     6,   602,   603,
     604,   605,   606,   607,   608,   609,   610,   611,   612,   613,
     614,   615,   616,   617,   618,   619,   620,   621,   622,   623,
     624,   625,   626,   627,   628,   629,   630,   631,   632,   633,
     634,   635,   636,   637,   638,   639,   640,   641,   642,   643,
       2,     3,     4,    23,    24,    25,    26,    27,    28,    29,
      30,    31
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
    3688,  3690,  3693,  3699,  3700,  3703,  3706,  3708,  3716,  3718,
    3724,  3728,  3730,  3734,  3736,  3740,  3742,  3746,  3748,  3752,
    3754,  3756,  3758,  3760,  3761,  3767,  3768,  3774,  3776,  3777,
    3781,  3783,  3787,  3789,  3793,  3795,  3797,  3798,  3799,  3805,
    3808,  3810,  3811,  3812,  3816,  3817,  3818,  3822,  3824,  3826,
    3828,  3830,  3832,  3834,  3837,  3840,  3845,  3849,  3853,  3855,
    3859,  3862,  3864,  3866,  3867,  3869,  3871,  3873,  3875,  3876,
    3878,  3882,  3883,  3887,  3889,  3891,  3893,  3895,  3897,  3899,
    3901,  3903,  3905,  3907,  3909,  3911,  3919,  3920,  3922,  3924,
    3926,  3928,  3932,  3934,  3936,  3938,  3941,  3942,  3946,  3948,
    3952,  3954,  3958,  3960,  3962,  3969,  3970,  3974,  3976,  3980,
    3981,  3983,  3988,  3994,  3997,  3999,  4001,  4006,  4008,  4012,
    4017,  4022,  4024,  4028,  4030,  4032,  4034,  4037,  4039,  4044,
    4045,  4047,  4048,  4051,  4053,  4055,  4057,  4062,  4066,  4068,
    4070,  4072,  4075,  4077,  4079,  4082,  4085,  4087,  4091,  4094,
    4097,  4099,  4103,  4105,  4108,  4113,  4115,  4118,  4120,  4124,
    4129,  4130,  4132,  4133,  4135,  4136,  4138,  4140,  4144,  4146,
    4150,  4152,  4155,  4157,  4161,  4164,  4167,  4172,  4176,  4177,
    4179,  4181,  4183,  4185,  4187,  4190,  4192,  4194,  4200,  4204,
    4210,  4214,  4216,  4220,  4221,  4223,  4227,  4231,  4235,  4239,
    4246,  4252,  4254,  4256,  4258,  4260,  4262,  4264,  4266,  4268,
    4270,  4272,  4274,  4276,  4278,  4280,  4281,  4283,  4285,  4287,
    4289,  4291,  4293,  4295,  4300,  4306,  4308,  4314,  4320,  4322,
    4324,  4326,  4331,  4333,  4338,  4340,  4348,  4350,  4352,  4354,
    4359,  4366,  4367,  4370,  4375,  4377,  4379,  4381,  4383,  4385,
    4387,  4389,  4393,  4395,  4397,  4401,  4403,  4404,  4408,  4414,
    4417,  4423,  4428,  4430,  4432,  4434,  4436,  4438,  4441,  4444,
    4447,  4450,  4452,  4455,  4458,  4459,  4463,  4464,  4468,  4470,
    4472,  4474,  4476,  4478,  4480,  4482,  4487,  4489,  4491,  4493,
    4495,  4497,  4499,  4501,  4506,  4508,  4510,  4512,  4514,  4516,
    4518,  4520,  4522,  4524,  4526,  4528,  4530,  4532,  4534,  4536,
    4538,  4542,  4543,  4552,  4553,  4563,  4564,  4572,  4573,  4583,
    4584,  4586,  4589,  4591,  4595,  4597,  4601,  4607,  4609,  4611,
    4613,  4615,  4618,  4619,  4620,  4629,  4635,  4637,  4639,  4647,
    4648,  4652,  4654,  4658,  4663,  4665,  4666,  4669,  4675,  4683,
    4684,  4686,  4688,  4690,  4692,  4696,  4698,  4701,  4704,  4706,
    4710,  4713,  4717,  4721,  4725,  4727,  4729,  4731,  4733,  4735,
    4737,  4739,  4745,  4751,  4757,  4763,  4769,  4774,  4781,  4785,
    4790,  4792,  4796,  4797,  4799,  4805,  4813,  4814,  4817,  4819,
    4821,  4822,  4826,  4828,  4832,  4834,  4836,  4838,  4839,  4843,
    4845,  4847,  4849,  4851,  4856,  4863,  4865,  4867,  4870,  4874,
    4876,  4878,  4880,  4882,  4884,  4886,  4888,  4890,  4896,  4902,
    4907,  4909,  4912,  4914,  4916,  4918,  4922,  4928,  4930,  4932,
    4934,  4936,  4940,  4943,  4946,  4949,  4951,  4954,  4957,  4960,
    4963,  4966,  4968,  4972,  4975,  4977,  4980,  4982,  4985,  4987,
    4988,  4989,  4996,  4997,  5000,  5001,  5003,  5005,  5008,  5011,
    5013,  5015,  5020,  5024,  5026,  5030,  5032,  5035,  5041,  5044,
    5047,  5053,  5054,  5057,  5059,  5061,  5064,  5071,  5078,  5080,
    5081,  5083,  5086,  5088,  5091,  5092,  5095,  5097,  5099,  5101,
    5103,  5105,  5107,  5109,  5111,  5113,  5115,  5117,  5119,  5121,
    5123,  5125,  5127,  5129,  5131,  5133,  5135,  5137,  5139,  5141,
    5143,  5145,  5147,  5149,  5151,  5153,  5155,  5157,  5159,  5161,
    5163,  5165,  5167,  5169,  5171,  5173,  5175,  5177,  5179,  5181,
    5183,  5185,  5187,  5189,  5191,  5193,  5195,  5197,  5199,  5201,
    5203,  5205,  5207,  5209,  5211,  5213,  5215,  5217,  5219,  5221,
    5223,  5225,  5227,  5229,  5231,  5233,  5235,  5237,  5239,  5241,
    5243,  5245,  5247,  5249,  5251,  5253,  5255,  5257,  5259
};

/* YYRHS -- A `-1'-separated list of the rules' RHS. */
static const short yyrhs[] =
{
     999,     0,    -1,   176,    -1,   173,    -1,   102,   649,   402,
     571,   650,    -1,   116,    -1,  1065,    -1,    25,    -1,   651,
      -1,   650,     5,   651,    -1,   907,    -1,   406,   652,   367,
      -1,   652,   653,   652,    -1,    25,    -1,   654,    25,    -1,
    1065,    -1,    17,    -1,    18,    -1,    20,    -1,    19,    -1,
      21,    -1,    17,    -1,    18,    -1,    -1,   656,    -1,    -1,
     250,   406,   657,   658,   367,    -1,   544,   406,    25,     5,
      25,   367,    -1,   659,    -1,   658,     5,   659,    -1,   466,
      -1,   506,    -1,   512,    -1,   482,    -1,   385,    -1,   581,
      -1,   503,    -1,   456,    -1,   392,    -1,   467,    -1,   321,
      -1,   507,    -1,   431,    -1,   308,    -1,   569,    -1,    76,
      -1,    -1,   661,    -1,    -1,   250,   406,   662,   663,   367,
      -1,   664,    -1,   663,     5,   664,    -1,   659,    -1,   407,
      -1,   579,    24,    -1,   179,   894,    -1,   305,   894,    -1,
     260,   894,    -1,   313,   894,    -1,   269,   894,    -1,   235,
     894,    -1,   509,   666,    -1,   843,   320,  1065,    -1,    -1,
     265,   406,  1436,   367,   320,   667,  1083,    -1,    82,   406,
     907,   367,    -1,   382,   406,   899,   367,   320,  1065,    -1,
    1200,    -1,   168,   406,   899,   367,   320,  1065,    -1,    -1,
      -1,  1065,   565,   907,   406,   668,   682,   367,   669,   680,
      -1,    -1,    -1,    -1,   907,   406,   670,   682,   671,   367,
     672,   680,    -1,    -1,    -1,   450,  1405,   599,  1405,   406,
     673,   682,   674,   367,   680,    -1,    -1,    -1,    43,   406,
     675,   682,   676,   367,   680,    -1,    -1,    -1,    -1,   341,
     685,   565,   686,   434,   649,   402,   406,   677,   682,   678,
     367,   679,   681,    -1,    -1,   320,  1083,    -1,    -1,   320,
    1083,    -1,   140,    -1,    -1,   683,    -1,   684,    -1,   683,
       5,   684,    -1,   812,    -1,    24,    -1,   907,    -1,   907,
      -1,   907,   596,   907,    -1,    -1,   510,   819,   688,   691,
     695,   692,    -1,    -1,   510,   689,   690,   693,   692,    -1,
     697,    -1,   690,   697,    -1,   699,    -1,   691,   699,    -1,
     336,    -1,    -1,    -1,   315,   694,  1446,    -1,    -1,    -1,
     315,   696,  1446,    -1,    -1,   554,   819,   698,  1446,    -1,
      -1,   554,   819,   700,  1446,    -1,   254,   904,    -1,   178,
     902,    -1,    61,   902,    -1,   147,    -1,   163,  1411,    -1,
     470,   901,    -1,    29,   703,    30,    -1,   704,    -1,   706,
      -1,   705,    -1,   704,   705,    -1,    28,    -1,   707,    -1,
     706,   707,    -1,    27,    -1,   369,    -1,    -1,    -1,   296,
     710,   712,   711,   713,    -1,   360,  1065,   601,   714,   950,
     977,   655,    -1,  1065,   601,   714,   950,   522,  1436,   977,
     655,    -1,    -1,   716,   167,    -1,   715,    -1,   714,     5,
     715,    -1,   907,    -1,   907,   596,   907,    -1,   907,   596,
      20,    -1,   717,    -1,   716,   717,    -1,    -1,   246,   723,
     718,  1446,    -1,    -1,   249,   724,   719,  1446,    -1,    -1,
     978,   720,  1446,    -1,    -1,   145,   721,  1446,    -1,    -1,
     141,   722,  1446,    -1,   913,    -1,   723,     5,   913,    -1,
     913,    -1,   724,     5,   913,    -1,    70,    -1,    71,    -1,
      72,    -1,    73,    -1,    74,    -1,    75,    -1,   133,    -1,
     255,    -1,    -1,   728,    -1,   729,    -1,   728,   729,    -1,
      -1,    -1,   413,   730,   732,   731,  1169,    -1,   779,    -1,
    1426,    -1,   735,    -1,   732,     5,   735,    -1,    -1,   734,
     907,    -1,   329,   733,   778,    24,    -1,   329,   733,   778,
     915,    -1,   329,   733,   778,    25,    -1,   739,   755,    -1,
      -1,   733,   329,   736,   737,    -1,    25,    -1,    24,    -1,
     915,    -1,    18,    25,    -1,   733,    -1,   738,    -1,   739,
       5,   738,    -1,    -1,   511,    -1,    -1,   463,   434,   747,
     402,   742,   600,   755,    -1,    -1,   294,   740,   744,    25,
     745,   278,   434,   746,   402,   743,   600,   755,    -1,   406,
      -1,   433,    -1,   367,    -1,   401,    -1,    25,    -1,   748,
       5,   748,     5,   748,    -1,   748,     5,   748,    -1,   748,
      -1,    25,    -1,    -1,   439,   750,   732,   259,    -1,    -1,
     236,   751,   733,   596,    20,    -1,    -1,   310,   752,   733,
     234,   406,   753,   367,    -1,   754,    -1,   753,     5,   754,
      -1,   733,    -1,   757,    -1,    -1,    36,    -1,    -1,    -1,
     758,   760,   759,   756,    -1,   741,    -1,   749,    -1,   511,
      -1,   511,   406,    25,   367,    -1,   399,   406,    25,   367,
      -1,   399,   406,    25,     5,    25,   367,    -1,   383,    -1,
     593,   733,    -1,   355,    -1,   485,    -1,    67,    -1,   373,
      -1,   373,   406,    25,   367,    -1,   373,   406,    25,     5,
      25,   367,    -1,   488,    -1,   488,   406,    25,   367,    -1,
     488,   406,    25,     5,    25,   367,    -1,   478,    -1,   275,
      -1,   513,    -1,   508,    -1,    58,    -1,    59,    -1,   550,
      -1,   333,   764,    -1,   345,   765,    -1,   761,    -1,    31,
      -1,   532,   762,   596,   763,    -1,   733,    -1,   733,    -1,
      -1,   766,   602,   769,    -1,   774,   602,   777,    -1,    -1,
     767,   768,    -1,   557,    -1,   489,    -1,   566,    -1,   528,
      -1,   429,    -1,   446,    -1,   342,   771,    -1,    -1,   770,
     768,    -1,    -1,   406,   773,   367,    -1,    -1,   406,    25,
     367,    -1,    25,    -1,    -1,   775,   776,   772,    -1,   557,
      -1,   489,    -1,   566,    -1,   528,    -1,   429,    -1,   446,
      -1,   342,   771,    -1,   776,    -1,    -1,    13,    -1,    -1,
     212,   907,   780,   593,   781,    -1,   783,    -1,   786,    -1,
     511,    -1,   511,   406,    25,   367,    -1,   399,   406,    25,
     367,    -1,   399,   406,    25,     5,    25,   367,    -1,   383,
      -1,   355,    -1,   485,    -1,   373,    -1,   373,   406,    25,
     367,    -1,   373,   406,    25,     5,    25,   367,    -1,   488,
      -1,   488,   406,    25,   367,    -1,   488,   406,    25,     5,
      25,   367,    -1,   478,    -1,   275,    -1,   513,    -1,   508,
      -1,   550,    -1,   333,   764,    -1,   345,   765,    -1,   782,
      -1,   532,   762,   596,   763,    -1,    -1,   463,   434,   747,
     402,   784,   600,   781,    -1,    -1,   294,   740,   744,    25,
     745,   278,   434,   746,   402,   785,   600,   781,    -1,    -1,
     439,   787,   789,   259,    -1,    -1,   236,   788,   907,   596,
      20,    -1,   790,    -1,   789,     5,   790,    -1,   791,   781,
      -1,   792,    -1,   791,     5,   792,    -1,   907,    -1,    -1,
     594,   898,    -1,    48,   907,    -1,    46,    -1,   602,  1436,
      -1,   602,   485,   907,   635,  1436,    -1,   602,   485,   907,
     365,    -1,    50,   907,    -1,   134,   837,  1083,   801,    -1,
     376,   837,   817,   793,   801,    -1,   185,   904,   801,    -1,
      -1,    -1,   166,   798,  1090,   602,   907,   596,    20,   800,
     655,   799,   802,    -1,    -1,   444,   899,    -1,   655,    -1,
      -1,   803,   214,    -1,   804,    -1,   803,   804,    -1,    -1,
     327,   805,  1446,    -1,    -1,   323,   806,  1446,    -1,    -1,
     978,   807,  1446,    -1,   474,   837,   818,   655,    -1,   474,
     837,   818,   655,    44,    -1,   262,    -1,   261,    -1,   188,
      -1,   340,    -1,   152,    -1,   187,    -1,   304,    -1,   303,
      -1,   219,    -1,   149,    -1,   148,    -1,   122,    -1,   180,
      -1,   105,    -1,   121,    -1,   165,    -1,   131,    -1,   189,
      -1,   189,   819,    -1,   822,    -1,   821,    -1,   826,    -1,
     854,    -1,   812,   813,    -1,   855,    -1,   857,    -1,   823,
      -1,    18,   812,    -1,    17,   812,    -1,   828,    -1,   836,
      -1,   830,    -1,   451,    -1,   725,    -1,   831,    -1,   832,
      -1,   833,    -1,   834,    -1,   835,    -1,   837,    -1,   837,
     816,    -1,   819,    -1,   459,    -1,   815,    -1,   816,     5,
     815,    -1,   819,    -1,   817,     5,   819,    -1,   819,    -1,
     818,     5,   819,    -1,   812,    -1,    17,    -1,    18,    -1,
     578,   812,    -1,   460,    -1,   403,    -1,   406,   812,   367,
      -1,   418,   406,  1387,   367,    -1,   270,   406,  1387,   367,
      -1,   820,   915,    -1,   820,    25,    -1,    24,    -1,   915,
      -1,    25,    -1,   825,    -1,  1065,    -1,  1065,   396,  1065,
      -1,   824,    -1,   409,   812,    -1,   368,   812,    -1,  1172,
      -1,    -1,   483,   827,  1172,    -1,     7,   812,    -1,     6,
     812,    -1,   812,    -1,   829,     5,   812,    -1,   599,   406,
    1387,   367,    -1,   404,   406,  1387,   367,    -1,   599,   406,
     837,   829,   367,    -1,   404,   406,   837,   829,   367,    -1,
     362,    -1,   225,    -1,     9,   812,    -1,   228,   812,    -1,
     532,   812,    -1,   347,   812,    -1,   366,    -1,     8,   812,
      -1,    17,   812,    -1,    18,   812,    -1,    20,   812,    -1,
      19,   812,    -1,    21,   812,    -1,    10,   812,    -1,    13,
     812,    -1,   432,   812,    -1,    11,   812,    -1,    12,   812,
      -1,    16,   812,    -1,    15,   812,    -1,    14,   812,    -1,
      -1,    -1,    -1,   907,   406,   839,   682,   840,   367,    -1,
      -1,    -1,    43,   406,   841,   682,   842,   367,    -1,    -1,
      -1,   513,   406,   844,   812,   845,   367,    -1,    -1,    -1,
     489,   406,   846,   812,   847,   367,    -1,    -1,    -1,   566,
     406,   848,   812,   849,   367,    -1,    -1,    -1,   557,   406,
     850,   812,   851,   367,    -1,   345,   406,    24,   367,   853,
      -1,   345,   406,    25,   367,   853,    -1,   345,   406,    25,
     565,    25,   367,   853,    -1,   333,   406,    24,   367,   852,
      -1,   333,   406,    25,   367,   852,    -1,   333,   406,    25,
     565,    25,   367,   852,    -1,    -1,  1367,   602,  1368,    -1,
      -1,  1367,   602,  1368,    -1,   843,    -1,   265,   406,  1436,
     367,    -1,    77,   406,   899,   367,    -1,    49,   406,   899,
     367,    -1,   382,   406,   899,   367,    -1,   168,   406,   899,
     367,    -1,    37,   406,   899,   367,    -1,   856,    -1,   838,
      -1,  1363,    -1,   513,    -1,   398,   406,   812,   367,    -1,
     298,   406,   812,   367,    -1,   464,   812,    -1,   419,   406,
     858,   367,    -1,   812,    86,    -1,   812,    87,    -1,   812,
      88,    -1,   371,     5,  1367,   602,  1368,    -1,  1065,     5,
    1367,   602,  1368,    -1,   371,  1367,   602,  1368,    -1,    -1,
      -1,   571,  1065,    13,   819,   602,   819,   862,   860,  1446,
     861,   217,    -1,    -1,   547,   819,    -1,    -1,    -1,    -1,
     379,   864,   901,   865,  1268,   866,  1446,   216,    -1,    -1,
      -1,   614,   907,   868,   727,   869,  1009,   871,   870,   876,
     615,    -1,    -1,   881,    -1,    -1,   872,    -1,   873,    -1,
     872,   873,    -1,    -1,   616,   874,  1446,    -1,    -1,   617,
     875,  1446,    -1,    -1,   877,    -1,   878,    -1,   877,   878,
      -1,    -1,   618,   879,  1446,    -1,    -1,   619,   880,  1446,
      -1,   882,   886,   300,    -1,    69,    -1,    69,   883,   522,
     884,    -1,    69,   360,   885,    -1,  1065,    -1,   883,     5,
    1065,    -1,   907,    -1,   884,     5,   907,    -1,  1065,    -1,
     885,     5,  1065,    -1,   887,    -1,   886,   887,    -1,    -1,
     620,   888,  1446,    -1,    -1,   621,   889,  1446,    -1,    -1,
     640,   884,   890,  1446,    -1,    -1,   457,   884,   891,  1446,
      -1,    -1,   601,   884,   892,  1446,    -1,   521,   900,    -1,
     530,    18,    25,    -1,   530,    -1,   477,    17,    25,    -1,
     477,    -1,    25,    -1,  1065,    -1,    24,    -1,   914,    -1,
     819,    -1,   896,     5,   896,    -1,   897,    -1,   907,    -1,
     643,   406,   907,   367,    -1,   907,   596,   643,   406,   907,
     367,    -1,   907,   434,   652,   402,    -1,   907,   596,    20,
      -1,   907,   434,   652,   402,   596,    20,    -1,   907,   596,
     907,    -1,   907,   434,   652,   402,   596,   907,    -1,   908,
      -1,   908,    -1,   908,    -1,   908,    -1,   908,    -1,   908,
      -1,    -1,   526,    25,    -1,   911,  1445,   912,    -1,   911,
     909,   912,    -1,  1445,    -1,   325,   406,   910,   367,    -1,
    1068,    -1,    24,    -1,    -1,    -1,   907,    -1,   907,   434,
     652,   402,    -1,   907,   596,    20,    -1,   907,   434,   652,
     402,   596,    20,    -1,   907,   596,   907,    -1,   907,   434,
     652,   402,   596,   907,    -1,  1065,    -1,    23,    -1,   596,
      25,    -1,   349,    -1,   468,    -1,   469,    -1,   366,    -1,
     470,    -1,   329,    -1,   296,    -1,   472,    -1,   435,    -1,
     512,    -1,   424,    -1,   567,    -1,   372,    -1,   465,    -1,
     458,    -1,   535,    -1,   375,    -1,   334,    -1,   473,    -1,
     297,    -1,   514,    -1,   256,    -1,   569,    -1,   631,    -1,
     515,    -1,   298,    -1,   517,    -1,   380,    -1,   418,    -1,
     557,    -1,   489,    -1,   566,    -1,   451,    -1,   354,    -1,
     369,    -1,   414,    -1,   356,    -1,   417,    -1,   398,    -1,
     363,    -1,   321,    -1,   534,    -1,   513,    -1,   523,  1428,
      -1,   628,   919,    -1,   920,    -1,   919,     5,   920,    -1,
     907,    -1,   639,   919,    -1,   630,   919,    -1,   631,  1436,
      -1,   629,   904,   635,  1436,    -1,   633,   919,    -1,   634,
    1436,    -1,   632,   904,   635,  1436,    -1,    -1,   637,   925,
     817,   930,   932,   934,   926,   928,    -1,    -1,   927,    -1,
     625,    -1,   626,    -1,    -1,   929,    -1,   320,  1065,    -1,
      -1,   931,    -1,   365,   817,    -1,    -1,   933,    -1,   636,
      25,    -1,    -1,   935,    -1,   627,    25,   936,    -1,    -1,
     375,    25,    -1,    -1,   598,   819,   551,   938,  1446,   939,
     416,    -1,    -1,    -1,   518,   940,  1446,    -1,    -1,    -1,
      40,   941,   819,   551,   942,  1446,   939,    -1,    84,   907,
     406,    25,   367,    -1,    53,   907,    -1,    -1,   266,  1095,
     946,   602,   459,    -1,   266,  1095,   532,   947,    -1,   948,
      -1,   947,     5,   948,    -1,   762,   596,  1360,    -1,   762,
     596,    20,    -1,    -1,   951,   300,    -1,    -1,   128,    -1,
     952,    -1,   951,   952,    -1,    -1,   246,   966,   953,  1446,
      -1,    -1,   249,   967,   954,  1446,    -1,    -1,   327,   955,
    1446,    -1,    -1,   323,   956,  1446,    -1,    -1,   978,   957,
    1446,    -1,    -1,   281,   958,  1446,    -1,    -1,   251,   959,
    1446,    -1,    -1,   640,   964,   960,  1446,    -1,    -1,   457,
     962,   961,  1446,    -1,   963,    -1,   962,     5,   963,    -1,
     425,    -1,   414,    -1,   965,    -1,   964,     5,   965,    -1,
     425,    -1,   414,    -1,   899,    -1,   966,     5,   899,    -1,
     899,    -1,   967,     5,   899,    -1,   290,   970,    -1,   291,
     907,   635,   970,    -1,   537,    -1,   350,    -1,   899,    -1,
      -1,   641,   973,   972,   949,    -1,   360,  1083,   950,   906,
     655,    -1,  1083,   950,   522,  1436,   906,   655,    -1,    -1,
     463,  1090,   950,   522,   907,   596,    20,   906,   974,   655,
      -1,   445,  1436,   976,    -1,   603,    -1,   515,    -1,    54,
      25,    -1,    60,    25,    -1,    -1,   526,    25,    -1,    -1,
     405,   979,   985,    -1,   271,    -1,    -1,   572,   981,   985,
      -1,   279,   987,    -1,    -1,   572,   984,   985,    -1,   987,
      -1,   406,   986,   367,    -1,   987,    -1,   986,     5,   987,
      -1,    -1,   988,   989,    -1,   570,    -1,   288,    -1,   306,
      -1,   280,    -1,   461,    -1,   417,    -1,   603,    -1,   515,
      -1,   441,    -1,   414,    -1,   516,    -1,   531,    -1,   496,
      -1,   286,    -1,   287,    -1,    24,    -1,   486,    -1,    -1,
      -1,   574,   992,  1088,   993,    13,   837,   994,    -1,   459,
      -1,   818,    -1,   195,  1065,    -1,   184,  1065,    -1,   198,
    1065,    -1,   426,  1065,   309,    -1,   426,  1065,   361,   895,
      -1,    -1,  1001,  1000,  1004,    -1,    -1,  1002,    -1,  1003,
      -1,  1002,  1003,    -1,   944,    -1,  1008,    -1,  1024,    -1,
    1010,    -1,    -1,  1005,    -1,  1007,    -1,  1005,  1007,    -1,
      45,   907,    -1,  1012,    -1,  1018,    -1,  1030,    -1,  1182,
      -1,  1192,    -1,  1051,    -1,  1426,    -1,   867,    -1,   702,
      -1,   943,    -1,   708,    -1,   702,    -1,  1426,    -1,    -1,
     702,    -1,  1426,    -1,   728,    -1,   343,    -1,    38,    -1,
      -1,    -1,    -1,    -1,  1011,  1013,   907,   406,  1014,  1081,
     367,  1015,   727,  1016,  1009,  1446,  1017,    -1,   186,    -1,
      -1,    -1,   533,  1019,   727,  1020,  1446,   337,    -1,   441,
     814,    -1,   837,    -1,   837,   817,    -1,   332,  1371,    -1,
    1025,    -1,  1026,    -1,  1025,  1026,    -1,  1027,    -1,  1008,
      -1,  1023,    -1,    -1,   381,  1028,  1029,    -1,   727,   218,
      -1,   895,    -1,    -1,    -1,    -1,    91,   907,    90,   907,
     406,  1031,  1081,   367,  1032,   727,  1033,  1009,  1446,  1017,
      -1,    -1,   534,  1035,  1050,  1041,  1036,    -1,   338,    -1,
      -1,   210,  1038,  1446,    -1,    -1,    22,  1042,  1043,  1044,
     906,  1039,  1446,    -1,    -1,    22,  1042,   906,  1040,  1446,
      -1,  1037,    -1,  1041,  1037,    -1,    -1,   980,    -1,    24,
      -1,  1065,    -1,    -1,  1065,    -1,    24,    -1,   227,  1048,
      -1,   239,  1049,    -1,   222,  1049,    -1,   561,    -1,    24,
      -1,  1065,    -1,  1048,    -1,  1049,     5,  1048,    -1,  1065,
      -1,    24,    -1,    -1,    -1,   622,   907,  1052,   727,  1053,
    1054,   623,    -1,  1055,    -1,  1054,  1055,    -1,    -1,   624,
    1056,  1446,    -1,    -1,   601,   907,  1057,  1446,    -1,  1061,
    1059,    -1,    -1,   656,  1063,    -1,  1064,    -1,  1060,    -1,
     931,    -1,   933,    -1,   935,    -1,   927,    -1,   929,    -1,
      -1,   346,  1062,   818,    -1,    -1,    44,    -1,    44,    -1,
    1066,    -1,  1068,    -1,   588,  1068,    -1,  1068,   911,   596,
      -1,  1067,  1072,    -1,  1067,   907,   434,  1075,   402,    -1,
    1073,    -1,   907,    -1,  1069,    -1,   907,   433,  1071,   401,
      -1,   907,   433,  1071,   401,    -1,  1065,    -1,    24,    -1,
      20,    -1,   907,    -1,   907,  1074,    -1,   434,  1075,   402,
      -1,   434,  1075,   402,   434,  1075,   402,    -1,  1076,    -1,
    1075,     5,  1076,    -1,   652,    -1,  1078,    -1,  1080,    -1,
    1078,   911,   596,  1079,    -1,  1078,   911,   596,   907,   434,
    1075,   402,    -1,   907,    -1,  1070,    -1,    20,    -1,   907,
      -1,   907,  1074,    -1,    -1,  1082,    -1,  1084,    -1,  1082,
       5,  1084,    -1,  1085,    -1,  1083,     5,  1085,    -1,   907,
      -1,   907,   596,   907,    -1,  1065,    -1,  1065,   396,  1065,
      -1,    24,    -1,   915,    -1,    25,    -1,  1087,    -1,  1086,
       5,  1087,    -1,  1065,    -1,  1065,   396,  1065,    -1,  1089,
      -1,  1088,     5,  1089,    -1,  1077,    -1,  1065,    -1,  1092,
      -1,  1091,     5,  1092,    -1,  1065,  1093,    -1,    -1,   563,
      -1,   514,    -1,   907,   434,  1075,   402,    -1,  1096,    -1,
    1095,     5,  1096,    -1,  1065,    -1,  1065,   396,  1065,    -1,
     230,   903,   594,   897,   555,  1438,   660,    -1,    -1,   594,
     406,   819,     5,   819,   367,  1099,    -1,    -1,   544,   406,
     819,     5,   819,   367,    -1,   231,   907,  1098,    -1,   907,
      -1,   314,   905,  1103,    -1,  1104,    -1,   522,   819,    -1,
    1105,  1106,  1111,     8,  1101,    -1,    -1,   594,  1107,   406,
     819,     5,   819,   367,    -1,    -1,   532,   908,    -1,    -1,
     326,    -1,   193,  1411,   242,  1421,  1110,    -1,   539,   900,
      -1,   539,   900,     8,   837,   817,    -1,    -1,   593,   552,
    1405,   349,  1405,    -1,   593,   552,  1405,     5,   349,  1405,
      -1,   593,  1405,     5,  1405,    -1,    -1,   625,    -1,   626,
      -1,    68,  1421,  1113,  1114,    -1,    -1,   593,  1421,    -1,
      -1,   593,   552,  1405,     8,  1405,    -1,   552,  1405,     8,
    1405,    -1,   387,  1116,    -1,  1117,    -1,  1116,     5,  1117,
      -1,   179,   894,    -1,   260,   894,    -1,   305,   894,    -1,
     313,   894,    -1,   269,   894,    -1,   235,   894,    -1,   982,
      -1,   414,   983,    -1,   425,   983,    -1,   537,   983,    -1,
     350,   983,    -1,   526,   983,    -1,   524,   895,    -1,   525,
     895,    -1,   376,   656,    -1,   641,   656,    -1,   267,    -1,
     171,    -1,   129,    -1,   106,    -1,   124,    -1,   115,    -1,
    1410,   389,  1121,   522,  1119,    -1,  1065,    -1,    24,    -1,
     378,  1121,    -1,   378,  1121,     8,  1083,    -1,   908,    -1,
      -1,   437,  1130,   655,   571,  1125,  1065,   906,   655,  1123,
    1126,    -1,   437,  1130,   655,   320,  1065,    -1,    -1,   511,
      -1,    -1,  1127,   258,    -1,  1128,    -1,  1127,  1128,    -1,
      -1,   978,  1129,  1446,    -1,   818,    -1,    -1,   580,   900,
    1132,  1133,    -1,    -1,   522,  1134,    -1,  1135,    -1,  1134,
       5,  1135,    -1,  1399,    -1,   459,    -1,   196,  1138,    66,
      -1,   196,  1138,   602,  1137,    -1,   196,  1138,    65,  1137,
      -1,   196,  1138,    -1,    24,    -1,   914,    -1,   907,    -1,
      -1,   455,    -1,   123,  1138,  1139,   406,   837,  1022,   367,
      -1,   169,  1138,    -1,  1173,  1181,    -1,   422,    39,    -1,
     422,  1144,    -1,  1145,    -1,  1144,  1145,    -1,    -1,   111,
    1146,  1446,    -1,    -1,   175,  1147,  1446,    -1,    -1,   204,
    1148,  1446,    -1,    -1,   192,  1149,  1446,    -1,    -1,   229,
    1150,  1446,    -1,    -1,   177,  1065,  1151,  1446,    -1,    -1,
     200,  1065,  1152,  1446,    -1,  1163,    -1,  1165,    -1,  1164,
      -1,  1154,    -1,  1190,    -1,  1157,    -1,    -1,   536,   819,
    1155,   458,    -1,    -1,   458,    -1,    -1,   545,   819,  1158,
    1156,    -1,   136,    -1,   605,  1177,    -1,   139,  1177,    -1,
     138,  1177,    -1,    -1,  1160,    -1,  1161,    -1,  1160,  1161,
      -1,  1170,  1162,    -1,    -1,   594,  1177,    -1,   495,  1159,
    1169,    -1,   494,  1405,  1169,    -1,   493,  1168,  1167,  1166,
    1169,    -1,    -1,   130,   812,    -1,   130,   812,     5,   812,
      -1,   589,    -1,   590,    -1,   591,    -1,   592,    -1,  1065,
      -1,    -1,   497,    -1,  1171,    -1,  1170,     5,  1171,    -1,
     819,  1204,    -1,   585,   406,   812,   367,  1189,    -1,    42,
    1189,    -1,   472,   406,    20,   367,  1189,    -1,   388,   406,
      20,   367,  1189,    -1,   363,   406,   812,   367,  1189,    -1,
     564,   406,   812,   367,  1189,    -1,   577,   406,   812,   367,
    1189,    -1,   576,   406,   812,   367,  1189,    -1,    -1,   436,
    1174,    -1,  1175,    -1,  1174,  1175,    -1,   203,    25,    -1,
     194,    25,    -1,   277,    25,    -1,   162,    25,    -1,   232,
      25,    -1,   154,    -1,   319,    24,    -1,   319,  1065,    -1,
     155,    24,    -1,   137,    24,    -1,  1180,    -1,  1176,  1180,
      -1,  1178,    86,    -1,  1178,    88,    -1,  1178,    87,    -1,
    1178,    -1,   915,    -1,    25,    -1,    -1,   436,  1176,    -1,
     203,  1177,    -1,   194,  1177,    -1,   277,  1177,    -1,   162,
    1177,    -1,   232,  1177,    -1,   233,  1177,    -1,   604,    24,
      -1,   605,  1177,    -1,   609,    -1,   606,    -1,   607,    -1,
     608,    -1,   613,    -1,   610,    -1,   611,    -1,   612,    -1,
      55,  1177,    -1,    56,  1177,    -1,    57,  1177,    -1,   319,
      24,    -1,   155,    24,    -1,   375,    -1,    51,    -1,    52,
      -1,    -1,   490,   595,  1091,    -1,   112,  1091,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   440,  1183,   907,   406,  1184,
    1081,   367,  1185,   727,  1186,  1142,  1187,  1143,  1188,   215,
      -1,    -1,   501,   812,    -1,   492,  1191,    -1,    -1,  1119,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    83,  1193,   907,
     406,  1194,  1081,   367,  1195,   727,  1196,  1199,  1197,  1143,
    1198,   215,    -1,  1179,  1181,    -1,    -1,    -1,    -1,   132,
     406,    24,     5,  1201,   682,  1202,   367,  1203,   680,    -1,
      -1,   359,    -1,   359,   194,    25,    -1,   359,   194,  1065,
      -1,   583,   819,    -1,   583,   819,   320,  1065,    -1,   583,
     819,   140,    -1,   583,   819,   553,    -1,   583,   819,   520,
      -1,  1207,    -1,   151,    -1,   299,    -1,   257,    -1,  1209,
      -1,    81,  1215,   367,    -1,    -1,    -1,   182,  1210,  1357,
     406,  1211,  1217,   367,    -1,    -1,    -1,   109,  1212,  1357,
     406,  1213,  1217,   367,  1214,    -1,    33,   908,    -1,    -1,
     244,    -1,  1216,    -1,  1215,     5,  1216,    -1,   907,   563,
      -1,   907,   514,    -1,   907,    -1,  1218,    -1,  1217,     5,
    1218,    -1,  1308,    -1,  1306,    -1,    98,   907,    -1,   157,
      -1,  1221,    -1,    32,   907,  1222,    -1,  1223,    -1,  1222,
       5,  1223,    -1,  1224,    -1,  1227,    -1,  1230,    -1,  1235,
      -1,  1236,    -1,  1234,    -1,  1233,    -1,   560,  1225,    -1,
     560,   406,  1226,   367,    -1,  1218,    -1,  1218,   640,   907,
      -1,  1225,    -1,  1226,     5,  1225,    -1,   517,  1229,    -1,
     517,   406,  1228,   367,    -1,  1229,    -1,  1228,     5,  1229,
      -1,   907,    -1,   430,  1232,    -1,   430,   406,  1231,   367,
      -1,  1232,    -1,  1231,     5,  1232,    -1,  1218,    -1,    63,
      -1,    64,    -1,    62,    25,    -1,    34,  1311,    -1,    34,
     406,  1237,   367,    -1,    35,  1238,    -1,    35,   406,  1237,
     367,    -1,  1311,    -1,  1237,     5,  1311,    -1,   907,    -1,
     241,    -1,   207,    -1,   142,  1241,    -1,   119,    -1,   107,
      -1,    97,    -1,    95,    -1,    99,    -1,   156,  1411,    -1,
     206,  1240,   435,  1405,   602,  1405,    -1,   274,   900,   435,
    1405,   602,  1405,    -1,    -1,  1411,    -1,    -1,   819,    -1,
     498,   819,    -1,   454,  1357,   559,  1245,  1244,    -1,    -1,
     127,   901,    -1,   501,  1330,    -1,  1246,    -1,   406,  1250,
     367,    13,   406,  1251,   367,    -1,  1247,    -1,    20,    13,
     406,  1251,   367,    -1,    20,    13,  1251,    -1,  1249,    -1,
    1247,     5,  1249,    -1,  1360,    -1,  1248,    13,  1252,    -1,
    1248,    -1,  1250,     5,  1248,    -1,  1252,    -1,  1251,     5,
    1252,    -1,  1399,    -1,   459,    -1,  1394,    -1,   205,    -1,
      -1,   224,  1255,  1357,  1258,  1256,    -1,    -1,   455,  1257,
     406,  1260,   367,    -1,  1393,    -1,    -1,   406,  1259,   367,
      -1,  1360,    -1,  1259,     5,  1360,    -1,  1261,    -1,  1260,
       5,  1261,    -1,  1399,    -1,   459,    -1,    -1,    -1,   476,
    1263,  1265,  1264,  1266,    -1,  1270,   901,    -1,   901,    -1,
      -1,    -1,   529,  1267,  1086,    -1,    -1,    -1,   529,  1269,
    1086,    -1,   477,    -1,   530,    -1,   537,    -1,   350,    -1,
     317,    -1,   371,    -1,   353,   819,    -1,   326,   819,    -1,
     213,  1357,   127,   901,    -1,   213,  1357,  1327,    -1,   490,
     595,  1274,    -1,  1275,    -1,  1274,     5,  1275,    -1,  1276,
    1277,    -1,    25,    -1,  1360,    -1,    -1,   563,    -1,   514,
      -1,   252,    -1,   285,    -1,    -1,   302,    -1,   332,  1421,
    1280,    -1,    -1,  1410,  1283,  1284,    -1,  1312,    -1,  1316,
      -1,  1279,    -1,  1412,    -1,  1278,    -1,  1271,    -1,  1272,
      -1,  1262,    -1,  1254,    -1,  1253,    -1,  1383,    -1,  1243,
      -1,   481,  1287,   601,  1357,   602,  1292,  1286,    -1,    -1,
     118,    -1,   146,    -1,  1288,    -1,  1289,    -1,  1288,     5,
    1289,    -1,   447,    -1,   425,    -1,   414,    -1,   454,  1290,
      -1,    -1,   406,  1291,   367,    -1,  1360,    -1,  1291,     5,
    1360,    -1,  1293,    -1,  1292,     5,  1293,    -1,   438,    -1,
    1358,    -1,   211,  1357,  1295,   593,  1393,  1297,    -1,    -1,
     406,  1296,   367,    -1,  1360,    -1,  1296,     5,  1360,    -1,
      -1,   117,    -1,   468,   406,  1330,   367,    -1,   221,   406,
    1301,   367,  1300,    -1,   272,  1302,    -1,  1303,    -1,  1357,
      -1,  1357,   406,  1303,   367,    -1,  1360,    -1,  1303,     5,
    1360,    -1,   452,   406,  1305,   367,    -1,   234,   406,  1305,
     367,    -1,  1360,    -1,  1305,     5,  1360,    -1,  1304,    -1,
    1299,    -1,  1298,    -1,   375,  1362,    -1,   183,    -1,   907,
    1349,  1309,  1310,    -1,    -1,  1307,    -1,    -1,  1311,  1310,
      -1,   348,    -1,   135,    -1,  1300,    -1,   468,   406,  1330,
     367,    -1,    96,  1313,  1315,    -1,  1314,    -1,  1358,    -1,
    1316,    -1,  1315,  1316,    -1,  1294,    -1,  1285,    -1,   423,
    1330,    -1,   344,  1319,    -1,  1398,    -1,  1319,     5,  1398,
      -1,   501,  1330,    -1,   522,  1322,    -1,  1323,    -1,  1322,
       5,  1323,    -1,  1324,    -1,   491,  1324,    -1,   491,   406,
    1325,   367,    -1,  1357,    -1,  1357,  1361,    -1,  1323,    -1,
    1325,     5,  1323,    -1,  1321,  1327,  1328,  1329,    -1,    -1,
    1320,    -1,    -1,  1318,    -1,    -1,  1317,    -1,  1331,    -1,
    1330,     6,  1331,    -1,  1332,    -1,  1331,     7,  1332,    -1,
    1333,    -1,   578,  1333,    -1,  1347,    -1,   406,  1330,   367,
      -1,   418,  1394,    -1,   270,  1394,    -1,  1399,  1346,  1336,
    1394,    -1,  1394,  1346,  1399,    -1,    -1,  1337,    -1,  1338,
      -1,   561,    -1,   546,    -1,   562,    -1,   417,  1341,    -1,
    1401,    -1,  1401,    -1,  1399,   599,   406,  1343,   367,    -1,
    1399,   599,  1394,    -1,  1399,   404,   406,  1343,   367,    -1,
    1399,   404,  1394,    -1,  1401,    -1,  1343,     5,  1401,    -1,
      -1,   578,    -1,  1399,  1344,   362,    -1,  1399,  1344,   225,
      -1,  1399,  1346,  1399,    -1,  1399,  1346,  1394,    -1,  1399,
    1344,   364,  1399,     7,  1399,    -1,  1399,  1344,   532,  1340,
    1339,    -1,    13,    -1,    16,    -1,    11,    -1,    12,    -1,
     228,    -1,   347,    -1,     9,    -1,   532,    -1,    15,    -1,
      14,    -1,  1345,    -1,  1342,    -1,  1335,    -1,  1334,    -1,
      -1,   561,    -1,   335,    -1,   452,    -1,  1350,    -1,  1351,
      -1,  1353,    -1,   511,    -1,   511,   406,  1354,   367,    -1,
     386,   406,  1355,  1352,   367,    -1,   448,    -1,   373,   406,
    1355,  1352,   367,    -1,   488,   406,  1355,  1352,   367,    -1,
     513,    -1,   383,    -1,   355,    -1,   333,  1369,   602,  1370,
      -1,   333,    -1,   345,  1369,   602,  1370,    -1,   345,    -1,
     345,  1369,   406,    25,   367,   602,  1370,    -1,   550,    -1,
     508,    -1,   399,    -1,   399,   406,    25,   367,    -1,   399,
     406,    25,     5,    25,   367,    -1,    -1,     5,  1356,    -1,
     478,   406,  1355,   367,    -1,   541,    -1,   275,    -1,   478,
      -1,    41,    -1,    25,    -1,    25,    -1,    25,    -1,    24,
     596,   907,    -1,    24,    -1,   907,    -1,   907,   565,   907,
      -1,   907,    -1,    -1,   434,    25,   402,    -1,   434,    25,
       5,    25,   402,    -1,   907,  1359,    -1,  1357,   911,   596,
     907,  1359,    -1,  1357,   911,   596,    20,    -1,   907,    -1,
      24,    -1,   386,    -1,   915,    -1,    25,    -1,    17,   915,
      -1,    17,    25,    -1,    18,   915,    -1,    18,    25,    -1,
    1364,    -1,   371,  1366,    -1,   371,  1365,    -1,    -1,  1369,
     602,  1370,    -1,    -1,  1367,   602,  1368,    -1,   557,    -1,
     489,    -1,   566,    -1,   528,    -1,   429,    -1,   446,    -1,
     342,    -1,   342,   406,    25,   367,    -1,   557,    -1,   489,
      -1,   566,    -1,   528,    -1,   429,    -1,   446,    -1,   342,
      -1,   342,   406,    25,   367,    -1,   557,    -1,   489,    -1,
     566,    -1,   528,    -1,   429,    -1,   446,    -1,   342,    -1,
     557,    -1,   489,    -1,   566,    -1,   528,    -1,   429,    -1,
     446,    -1,   342,    -1,   907,    -1,    24,    -1,  1410,   479,
     901,    -1,    -1,  1410,   374,   901,   412,   571,  1381,  1374,
    1378,    -1,    -1,  1410,   374,   901,   412,    78,   571,  1382,
    1375,  1378,    -1,    -1,  1410,   374,   901,   113,  1382,  1376,
    1378,    -1,    -1,  1410,   374,   901,   114,    78,   571,  1382,
    1377,  1378,    -1,    -1,   264,    -1,   263,  1379,    -1,  1380,
      -1,  1379,     5,  1380,    -1,   907,    -1,   907,   596,   907,
      -1,    24,   596,   907,   596,   907,    -1,  1382,    -1,  1254,
      -1,  1121,    -1,  1384,    -1,  1384,  1378,    -1,    -1,    -1,
     447,  1395,  1396,  1385,  1392,  1386,  1326,  1390,    -1,   447,
    1395,  1396,  1326,  1390,    -1,  1389,    -1,  1405,    -1,   447,
     911,  1395,  1396,  1392,  1326,  1390,    -1,    -1,   500,  1348,
    1388,    -1,  1273,    -1,   307,  1391,  1214,    -1,  1273,   307,
    1391,  1214,    -1,   907,    -1,    -1,   529,  1086,    -1,   447,
     911,  1395,  1396,  1326,    -1,   406,   447,   911,  1395,  1396,
    1326,   367,    -1,    -1,   561,    -1,   335,    -1,   452,    -1,
    1397,    -1,  1396,     5,  1397,    -1,  1399,    -1,  1399,  1445,
      -1,  1399,   916,    -1,  1399,    -1,  1399,    19,  1399,    -1,
    1399,  1419,    -1,  1399,    20,  1399,    -1,  1399,    17,  1399,
      -1,  1399,    18,  1399,    -1,  1425,    -1,  1362,    -1,   460,
      -1,   403,    -1,   552,    -1,    20,    -1,    42,    -1,   564,
     406,  1348,  1399,   367,    -1,   576,   406,  1348,  1399,   367,
      -1,   577,   406,  1348,  1399,   367,    -1,   585,   406,  1348,
    1399,   367,    -1,   472,   406,  1348,  1399,   367,    -1,   907,
     406,  1400,   367,    -1,   513,   911,   406,   911,  1400,   367,
      -1,   406,  1399,   367,    -1,   419,   406,  1420,   367,    -1,
    1399,    -1,  1400,     5,  1399,    -1,    -1,  1362,    -1,  1410,
     322,  1409,  1404,  1388,    -1,  1410,   311,  1409,  1404,   224,
    1357,  1406,    -1,    -1,   297,  1405,    -1,    24,    -1,  1065,
      -1,    -1,   406,  1407,   367,    -1,  1408,    -1,  1407,     5,
    1408,    -1,   907,    -1,    24,    -1,  1065,    -1,    -1,   243,
    1411,   571,    -1,   908,    -1,  1417,    -1,  1416,    -1,  1413,
      -1,   292,  1414,   602,  1414,    -1,   273,  1414,   596,  1415,
     602,  1415,    -1,   907,    -1,   907,    -1,   197,   762,    -1,
     268,   762,  1418,    -1,   247,    -1,   153,    -1,    70,    -1,
      71,    -1,    72,    -1,    73,    -1,    74,    -1,    75,    -1,
     371,     5,  1369,   602,  1370,    -1,  1360,     5,  1369,   602,
    1370,    -1,   371,  1369,   602,  1370,    -1,  1422,    -1,   588,
    1423,    -1,  1423,    -1,  1094,    -1,   907,    -1,  1423,   596,
    1424,    -1,    24,   596,  1423,   596,  1424,    -1,    20,    -1,
    1094,    -1,   907,    -1,  1422,    -1,  1422,   396,  1422,    -1,
     104,  1427,    -1,   108,  1427,    -1,   103,  1427,    -1,   143,
      -1,   144,  1427,    -1,   101,  1427,    -1,   126,  1427,    -1,
     125,  1427,    -1,   100,  1427,    -1,   331,    -1,   597,   602,
    1428,    -1,   523,  1428,    -1,   548,    -1,   509,  1429,    -1,
     907,    -1,   565,   907,    -1,   907,    -1,    -1,    -1,   502,
    1431,   819,  1432,  1446,   301,    -1,    -1,   635,  1436,    -1,
      -1,   638,    -1,   159,    -1,   253,   902,    -1,    47,   902,
      -1,   283,    -1,   282,    -1,   284,   904,  1433,  1434,    -1,
     469,  1436,  1434,    -1,   899,    -1,  1436,     5,   899,    -1,
      80,    -1,   110,   902,    -1,   819,   542,     5,   819,   368,
      -1,   485,   819,    -1,   240,   902,    -1,    79,  1441,     8,
    1442,  1440,    -1,    -1,   522,   819,    -1,   907,    -1,   907,
      -1,   223,   902,    -1,   226,   902,   602,   819,     5,   819,
      -1,   226,   902,   595,   819,     5,   819,    -1,    26,    -1,
      -1,  1448,    -1,  1449,  1169,    -1,  1447,    -1,  1448,  1447,
      -1,    -1,  1450,  1451,    -1,   645,    -1,   646,    -1,   647,
      -1,   648,    -1,   665,    -1,   687,    -1,   701,    -1,   702,
      -1,   708,    -1,   709,    -1,   726,    -1,   794,    -1,   795,
      -1,   796,    -1,   797,    -1,   808,    -1,   809,    -1,   810,
      -1,   811,    -1,   859,    -1,   863,    -1,   893,    -1,   917,
      -1,   918,    -1,   921,    -1,   922,    -1,   923,    -1,   924,
      -1,   937,    -1,   945,    -1,   968,    -1,   969,    -1,   971,
      -1,   975,    -1,   990,    -1,   991,    -1,   995,    -1,   996,
      -1,   997,    -1,   998,    -1,  1006,    -1,  1021,    -1,  1034,
      -1,  1045,    -1,  1046,    -1,  1047,    -1,  1058,    -1,  1097,
      -1,  1100,    -1,  1102,    -1,  1108,    -1,  1109,    -1,  1112,
      -1,  1115,    -1,  1118,    -1,  1120,    -1,  1122,    -1,  1124,
      -1,  1131,    -1,  1136,    -1,  1140,    -1,  1141,    -1,  1153,
      -1,  1205,    -1,  1206,    -1,  1208,    -1,  1219,    -1,  1220,
      -1,  1239,    -1,  1242,    -1,  1281,    -1,  1282,    -1,  1372,
      -1,  1373,    -1,  1402,    -1,  1403,    -1,  1426,    -1,  1430,
      -1,  1435,    -1,  1437,    -1,  1439,    -1,  1443,    -1,  1444,
      -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const unsigned short yyrline[] =
{
       0,   873,   873,   876,   879,   885,   891,   898,   902,   902,
     908,   926,   927,   928,   929,   930,   944,   945,   946,   947,
     948,   953,   954,   965,   968,   971,   971,   975,   978,   979,
     985,   986,   987,   988,   989,   990,   991,   992,   993,   994,
     995,   996,   997,   998,   999,  1000,  1003,  1004,  1007,  1007,
    1015,  1016,  1019,  1025,  1027,  1038,  1040,  1042,  1044,  1048,
    1050,  1112,  1116,  1120,  1120,  1127,  1130,  1134,  1135,  1138,
    1144,  1138,  1157,  1162,  1166,  1157,  1178,  1182,  1178,  1191,
    1196,  1191,  1215,  1222,  1226,  1214,  1252,  1252,  1256,  1257,
    1258,  1263,  1266,  1271,  1275,  1283,  1286,  1286,  1292,  1296,
    1311,  1309,  1327,  1327,  1342,  1342,  1345,  1345,  1349,  1352,
    1352,  1352,  1359,  1360,  1359,  1367,  1367,  1378,  1378,  1397,
    1400,  1403,  1406,  1409,  1412,  1425,  1430,  1430,  1431,  1431,
    1434,  1439,  1439,  1443,  1453,  1467,  1471,  1466,  1481,  1487,
    1495,  1496,  1499,  1499,  1502,  1506,  1511,  1518,  1518,  1522,
    1522,  1529,  1529,  1534,  1534,  1539,  1539,  1544,  1544,  1557,
    1558,  1566,  1567,  1584,  1587,  1590,  1593,  1596,  1599,  1612,
    1616,  1631,  1632,  1636,  1636,  1640,  1640,  1640,  1641,  1642,
    1647,  1647,  1650,  1650,  1654,  1655,  1658,  1662,  1663,  1663,
    1680,  1680,  1680,  1680,  1684,  1691,  1692,  1695,  1695,  1698,
    1698,  1707,  1704,  1720,  1720,  1722,  1722,  1724,  1726,  1728,
    1730,  1733,  1737,  1737,  1738,  1738,  1742,  1742,  1754,  1754,
    1759,  1763,  1765,  1766,  1769,  1769,  1769,  1773,  1774,  1775,
    1776,  1783,  1784,  1785,  1786,  1789,  1790,  1791,  1792,  1796,
    1801,  1806,  1810,  1813,  1817,  1818,  1819,  1820,  1821,  1822,
    1823,  1824,  1827,  1828,  1829,  1861,  1865,  1867,  1869,  1869,
    1876,  1880,  1880,  1884,  1885,  1886,  1887,  1888,  1889,  1890,
    1896,  1896,  1899,  1901,  1907,  1909,  1915,  1923,  1923,  1926,
    1927,  1928,  1929,  1930,  1931,  1932,  1938,  1941,  1941,  1954,
    1954,  1961,  1962,  1963,  1965,  1966,  1968,  1970,  1971,  1972,
    1973,  1978,  1984,  1990,  1991,  1993,  1995,  1996,  1997,  1998,
    1999,  2000,  2003,  2004,  2011,  2019,  2019,  2027,  2024,  2039,
    2039,  2041,  2041,  2049,  2049,  2052,  2055,  2056,  2061,  2073,
    2077,  2080,  2083,  2084,  2085,  2086,  2087,  2092,  2099,  2105,
    2110,  2114,  2110,  2125,  2127,  2132,  2137,  2137,  2141,  2141,
    2144,  2144,  2150,  2150,  2156,  2156,  2172,  2175,  2189,  2191,
    2193,  2195,  2197,  2199,  2201,  2207,  2209,  2213,  2215,  2217,
    2219,  2221,  2223,  2225,  2231,  2246,  2249,  2262,  2263,  2264,
    2265,  2266,  2270,  2271,  2272,  2276,  2281,  2288,  2289,  2290,
    2291,  2292,  2293,  2294,  2295,  2296,  2297,  2302,  2302,  2307,
    2307,  2310,  2316,  2324,  2330,  2340,  2341,  2349,  2356,  2360,
    2370,  2374,  2379,  2384,  2386,  2396,  2409,  2417,  2430,  2435,
    2441,  2446,  2451,  2452,  2458,  2529,  2535,  2540,  2548,  2548,
    2564,  2568,  2575,  2578,  2586,  2597,  2607,  2613,  2622,  2627,
    2635,  2639,  2643,  2647,  2654,  2662,  2670,  2675,  2679,  2684,
    2688,  2692,  2699,  2702,  2705,  2709,  2713,  2717,  2721,  2729,
    2739,  2744,  2737,  2759,  2764,  2759,  2781,  2781,  2781,  2784,
    2784,  2784,  2787,  2787,  2787,  2790,  2790,  2790,  2793,  2798,
    2803,  2808,  2813,  2818,  2827,  2827,  2831,  2831,  2837,  2838,
    2844,  2845,  2850,  2853,  2857,  2861,  2862,  2865,  2870,  2876,
    2880,  2884,  2887,  2889,  2892,  2895,  2901,  2902,  2903,  2914,
    2918,  2913,  2926,  2929,  2943,  2947,  2952,  2942,  2972,  2978,
    2972,  2992,  2992,  2994,  2995,  2999,  2999,  3003,  3003,  3008,
    3008,  3015,  3016,  3020,  3020,  3024,  3024,  3029,  3029,  3036,
    3040,  3041,  3042,  3047,  3047,  3050,  3050,  3054,  3054,  3058,
    3058,  3062,  3062,  3067,  3067,  3072,  3072,  3077,  3077,  3082,
    3082,  3098,  3115,  3116,  3117,  3118,  3119,  3120,  3123,  3123,
    3126,  3128,  3131,  3134,  3135,  3136,  3137,  3139,  3141,  3143,
    3145,  3149,  3156,  3158,  3164,  3169,  3174,  3179,  3179,  3182,
    3193,  3198,  3201,  3208,  3208,  3210,  3216,  3220,  3221,  3223,
    3225,  3227,  3229,  3233,  3242,  3242,  3249,  3250,  3251,  3252,
    3253,  3254,  3255,  3256,  3257,  3258,  3259,  3260,  3261,  3262,
    3263,  3264,  3265,  3266,  3267,  3268,  3269,  3270,  3271,  3272,
    3273,  3274,  3275,  3276,  3277,  3278,  3279,  3280,  3281,  3282,
    3283,  3284,  3285,  3286,  3287,  3288,  3289,  3290,  3291,  3303,
    3316,  3323,  3323,  3327,  3332,  3338,  3342,  3346,  3352,  3356,
    3360,  3366,  3366,  3374,  3375,  3379,  3379,  3383,  3384,  3387,
    3390,  3390,  3393,  3395,  3395,  3398,  3400,  3400,  3401,  3403,
    3403,  3412,  3410,  3422,  3422,  3422,  3425,  3427,  3425,  3434,
    3440,  3450,  3450,  3454,  3460,  3460,  3464,  3465,  3476,  3477,
    3479,  3481,  3486,  3486,  3490,  3489,  3496,  3495,  3501,  3501,
    3506,  3506,  3512,  3512,  3517,  3517,  3522,  3522,  3527,  3527,
    3532,  3532,  3540,  3541,  3549,  3550,  3555,  3556,  3565,  3566,
    3573,  3574,  3582,  3583,  3592,  3597,  3602,  3603,  3604,  3608,
    3607,  3618,  3623,  3628,  3628,  3639,  3644,  3645,  3646,  3647,
    3650,  3650,  3656,  3656,  3658,  3661,  3661,  3663,  3667,  3667,
    3670,  3671,  3674,  3674,  3679,  3679,  3682,  3683,  3684,  3685,
    3686,  3687,  3688,  3689,  3690,  3691,  3692,  3693,  3694,  3695,
    3696,  3697,  3701,  3719,  3719,  3719,  3745,  3756,  3763,  3769,
    3775,  3781,  3792,  3815,  3814,  3831,  3831,  3835,  3836,  3844,
    3845,  3846,  3847,  3854,  3855,  3857,  3858,  3862,  3867,  3868,
    3869,  3870,  3871,  3872,  3873,  3874,  3875,  3876,  3877,  3880,
    3880,  3882,  3882,  3882,  3884,  3888,  3888,  3897,  3902,  3910,
    3916,  3896,  3930,  3944,  3953,  3943,  3966,  3973,  3973,  3978,
    3983,  3988,  3989,  3992,  3992,  3992,  3995,  3995,  4003,  4009,
    4023,  4027,  4040,  4022,  4058,  4058,  4071,  4082,  4081,  4093,
    4089,  4106,  4103,  4116,  4116,  4118,  4119,  4121,  4122,  4125,
    4126,  4127,  4129,  4134,  4139,  4145,  4147,  4148,  4151,  4152,
    4155,  4157,  4166,  4172,  4166,  4183,  4184,  4188,  4188,  4198,
    4198,  4210,  4213,  4217,  4221,  4226,  4230,  4231,  4232,  4233,
    4234,  4238,  4238,  4240,  4240,  4243,  4252,  4290,  4290,  4293,
    4297,  4302,  4340,  4341,  4342,  4345,  4359,  4371,  4371,  4376,
    4377,  4383,  4438,  4443,  4450,  4455,  4463,  4469,  4490,  4493,
    4494,  4532,  4533,  4537,  4538,  4542,  4595,  4599,  4602,  4608,
    4619,  4626,  4634,  4634,  4637,  4638,  4639,  4640,  4641,  4644,
    4647,  4653,  4656,  4660,  4664,  4671,  4676,  4683,  4686,  4692,
    4694,  4694,  4694,  4698,  4712,  4719,  4726,  4729,  4743,  4750,
    4751,  4754,  4755,  4759,  4765,  4770,  4776,  4777,  4782,  4786,
    4786,  4790,  4791,  4794,  4795,  4799,  4807,  4810,  4816,  4817,
    4819,  4821,  4825,  4825,  4826,  4831,  4839,  4840,  4845,  4846,
    4848,  4861,  4863,  4864,  4866,  4869,  4872,  4875,  4878,  4881,
    4884,  4888,  4892,  4896,  4899,  4903,  4906,  4907,  4908,  4911,
    4914,  4917,  4920,  4923,  4926,  4929,  4945,  4953,  4953,  4955,
    4962,  4969,  4984,  4982,  5002,  5007,  5008,  5012,  5013,  5015,
    5016,  5018,  5018,  5026,  5035,  5035,  5045,  5046,  5049,  5050,
    5053,  5053,  5065,  5070,  5075,  5080,  5090,  5090,  5094,  5097,
    5097,  5099,  5109,  5116,  5118,  5122,  5125,  5125,  5129,  5128,
    5132,  5131,  5135,  5134,  5138,  5137,  5141,  5140,  5143,  5143,
    5159,  5158,  5180,  5181,  5182,  5183,  5184,  5185,  5188,  5188,
    5194,  5194,  5197,  5197,  5207,  5208,  5209,  5216,  5228,  5229,
    5232,  5233,  5236,  5239,  5239,  5244,  5248,  5253,  5259,  5260,
    5261,  5265,  5266,  5267,  5268,  5272,  5282,  5284,  5289,  5292,
    5297,  5303,  5310,  5317,  5326,  5333,  5340,  5347,  5354,  5363,
    5363,  5365,  5365,  5368,  5369,  5370,  5371,  5372,  5373,  5374,
    5375,  5376,  5377,  5380,  5380,  5383,  5384,  5385,  5386,  5389,
    5389,  5392,  5392,  5395,  5396,  5397,  5398,  5399,  5400,  5401,
    5402,  5404,  5405,  5406,  5407,  5409,  5410,  5411,  5412,  5414,
    5415,  5416,  5417,  5418,  5419,  5420,  5421,  5425,  5431,  5439,
    5450,  5459,  5469,  5473,  5477,  5483,  5449,  5496,  5499,  5507,
    5519,  5521,  5526,  5531,  5540,  5543,  5547,  5555,  5525,  5564,
    5568,  5572,  5576,  5568,  5586,  5587,  5588,  5589,  5594,  5596,
    5599,  5603,  5606,  5613,  5618,  5619,  5620,  5624,  5631,  5633,
    5633,  5633,  5635,  5635,  5635,  5637,  5643,  5644,  5650,  5651,
    5656,  5657,  5658,  5662,  5663,  5668,  5669,  5675,  5676,  5681,
    5685,  5691,  5692,  5697,  5698,  5699,  5700,  5701,  5702,  5703,
    5708,  5711,  5718,  5719,  5725,  5726,  5733,  5736,  5743,  5744,
    5749,  5753,  5756,  5762,  5763,  5769,  5774,  5775,  5779,  5785,
    5786,  5793,  5794,  5799,  5800,  5805,  5816,  5817,  5818,  5819,
    5820,  5821,  5822,  5823,  5824,  5827,  5830,  5836,  5836,  5842,
    5842,  5853,  5867,  5871,  5872,  5877,  5886,  5887,  5888,  5892,
    5893,  5905,  5905,  5912,  5914,  5920,  5921,  5924,  5925,  5928,
    5928,  5928,  5931,  5941,  5941,  5947,  5947,  5950,  5953,  5954,
    5960,  5961,  5966,  5967,  5972,  5973,  5978,  5982,  5977,  5992,
    5996,  6003,  6007,  6007,  6020,  6024,  6024,  6039,  6041,  6043,
    6045,  6047,  6049,  6051,  6053,  6059,  6069,  6074,  6079,  6080,
    6084,  6086,  6087,  6090,  6091,  6092,  6095,  6100,  6107,  6108,
    6114,  6127,  6127,  6132,  6137,  6143,  6144,  6147,  6148,  6155,
    6162,  6166,  6176,  6177,  6181,  6189,  6193,  6194,  6199,  6201,
    6205,  6206,  6210,  6211,  6212,  6213,  6217,  6218,  6223,  6224,
    6229,  6230,  6235,  6236,  6241,  6245,  6246,  6251,  6252,  6256,
    6257,  6262,  6268,  6273,  6278,  6282,  6283,  6288,  6289,  6295,
    6297,  6302,  6303,  6309,  6310,  6311,  6316,  6318,  6329,  6333,
    6334,  6337,  6338,  6343,  6345,  6347,  6348,  6354,  6359,  6364,
    6368,  6369,  6374,  6375,  6384,  6390,  6395,  6396,  6401,  6406,
    6410,  6411,  6416,  6417,  6418,  6421,  6422,  6427,  6427,  6431,
    6442,  6443,  6446,  6447,  6450,  6451,  6456,  6457,  6462,  6463,
    6468,  6469,  6474,  6475,  6481,  6482,  6487,  6489,  6494,  6495,
    6496,  6499,  6503,  6504,  6512,  6517,  6521,  6526,  6528,  6530,
    6532,  6538,  6539,  6543,  6544,  6549,  6551,  6553,  6555,  6557,
    6559,  6565,  6566,  6567,  6568,  6569,  6570,  6571,  6572,  6573,
    6574,  6579,  6580,  6581,  6582,  6584,  6585,  6586,  6587,  6596,
    6597,  6598,  6602,  6603,  6608,  6610,  6611,  6612,  6614,  6615,
    6616,  6617,  6619,  6620,  6622,  6623,  6625,  6626,  6627,  6628,
    6630,  6634,  6635,  6641,  6643,  6644,  6645,  6646,  6651,  6655,
    6659,  6663,  6664,  6668,  6669,  6676,  6684,  6685,  6686,  6689,
    6694,  6699,  6709,  6713,  6717,  6718,  6719,  6720,  6722,  6724,
    6726,  6728,  6731,  6734,  6738,  6739,  6743,  6744,  6748,  6748,
    6748,  6748,  6748,  6748,  6749,  6752,  6757,  6757,  6757,  6757,
    6757,  6757,  6759,  6762,  6768,  6768,  6768,  6768,  6768,  6768,
    6768,  6769,  6769,  6769,  6769,  6769,  6769,  6769,  6771,  6772,
    6775,  6785,  6784,  6790,  6790,  6796,  6796,  6802,  6802,  6812,
    6813,  6814,  6817,  6817,  6820,  6821,  6822,  6827,  6828,  6834,
    6837,  6842,  6856,  6858,  6853,  6871,  6880,  6880,  6883,  6891,
    6892,  6896,  6897,  6898,  6902,  6905,  6906,  6915,  6920,  6924,
    6925,  6926,  6927,  6931,  6932,  6936,  6937,  6938,  6943,  6948,
    6950,  6952,  6954,  6956,  6958,  6959,  6960,  6961,  6962,  6963,
    6964,  6966,  6968,  6970,  6972,  6974,  6976,  6978,  6980,  6981,
    6985,  6985,  6987,  6988,  6991,  6999,  7004,  7004,  7008,  7008,
    7013,  7013,  7017,  7017,  7021,  7027,  7027,  7030,  7030,  7036,
    7043,  7044,  7045,  7049,  7050,  7053,  7054,  7058,  7064,  7074,
    7075,  7083,  7084,  7085,  7086,  7087,  7088,  7092,  7093,  7094,
    7177,  7189,  7189,  7193,  7194,  7195,  7196,  7200,  7201,  7202,
    7205,  7217,  7315,  7317,  7319,  7321,  7325,  7330,  7332,  7334,
    7336,  7340,  7343,  7348,  7353,  7357,  7366,  7367,  7371,  7383,
    7386,  7382,  7405,  7405,  7409,  7410,  7413,  7414,  7415,  7416,
    7417,  7418,  7419,  7424,  7425,  7429,  7432,  7437,  7441,  7446,
    7450,  7455,  7459,  7462,  7466,  7469,  7474,  7478,  7489,  7495,
    7495,  7496,  7497,  7504,  7513,  7513,  7515,  7516,  7517,  7518,
    7519,  7520,  7521,  7522,  7523,  7524,  7525,  7526,  7527,  7528,
    7529,  7530,  7531,  7532,  7533,  7534,  7535,  7536,  7537,  7538,
    7539,  7540,  7541,  7542,  7543,  7544,  7545,  7546,  7547,  7548,
    7549,  7550,  7551,  7552,  7553,  7554,  7555,  7556,  7557,  7558,
    7559,  7560,  7561,  7562,  7563,  7564,  7565,  7566,  7567,  7568,
    7569,  7570,  7571,  7572,  7573,  7574,  7575,  7576,  7577,  7578,
    7579,  7580,  7581,  7582,  7583,  7584,  7585,  7586,  7587,  7588,
    7589,  7590,  7591,  7592,  7593,  7594,  7595,  7596,  7597
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
  "KW_CEND", "USER_DTYPE", "ALTER_TABLE", "CREATE_DATABASE", 
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
  "CONTINUE_CASE", "CONTINUE_MENU", "DISPLAY_ARRAY", "END_CONSTRUCT", 
  "FIELD_TOUCHED", "FINISH_REPORT", "INFACC", "INPUT_NO_WRAP", 
  "LOCKMODEPAGE", "SETPMOFF", "UNCONSTRAINED", "PAGE_TRAILER", "SETPMON", 
  "BEFGROUP", "CLOSE_WINDOW", "COMMENT_LINE", "CONTINUE_FOR", "CREATE_DB", 
  "CREATE_TABLE", "DEFAULT_NULL", "DELETE_USING", "DISPLAY_FORM", 
  "END_FUNCTION", "EXIT_DISPLAY", "EXIT_FOREACH", "EXIT_PROGRAM", 
  "INFCOLS", "LOCKMODEROW", "ON_EVERY_ROW", "OPEN_SESSION", 
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
  "CHARACTER", "CONSTRUCT", "DELIMITER", "DOWNSHIFT", "DROP_VIEW", 
  "END_INPUT", "END_WHILE", "EXCLUSIVE", "EXIT_CASE", "EXIT_MENU", 
  "FORM_LINE", "INTERRUPT", "INTO_TEMP", "INVISIBLE", "IN_MEMORY", 
  "LINKED_TO", "LOAD_FROM", "LOCKTAB", "MENU_LINE", "OPEN_FORM", 
  "OTHERWISE", "PRECISION", "PRIOR", "PROCEDURE", "REPORT_TO", 
  "RETURNING", "UNDERLINE", "UNLOAD_TO", "BEFROW", "UNLOAD_T", "VARIABLE", 
  "ABSOLUTE", "AFTROW", "BUFFERED", "CONSTANT", "CONST", "CONTINUE", 
  "DATABASE", "DATETIME", "DEFAULTS", "DISTINCT", "END_CASE", "END_MAIN", 
  "END_MENU", "END_TYPE", "EXIT_FOR", "EXTERNAL", "FRACTION", "FUNCTION", 
  "GROUP_BY", "INTERVAL", "KWMESSAGE", "NOT_LIKE", "NOT_NULL", "PASSWORD", 
  "PREVIOUS", "READONLY", "REGISTER", "RELATIVE", "RESOURCE", "SMALLINT", 
  "VALIDATE", "WHENEVER", "WITH_LOG", "WORDWRAP", "BY_NAME", "IN_FILE", 
  "IS_NULL", "AVERAGE", "BETWEEN", "CAPTION", "CLIPPED", "CLOSE_BRACKET", 
  "COLUMNS", "COMMENT", "CONNECT", "CURRENT", "DBYNAME", "DECIMAL", 
  "DECLARE", "DEFAULT", "DISPLAY", "ENDCODE", "EXECUTE", "FOREACH", 
  "FOREIGN", "GLOBALS", "INFIELD", "INTEGER", "KWWINDOW", "MAGENTA", 
  "NUMERIC", "OPTIONS", "PERCENT", "PREPARE", "PROGRAM", "RECOVER", 
  "REVERSE", "SECTION", "SESSION", "SYNONYM", "THRU", "TRAILER", 
  "UPSHIFT", "VARCHAR", "WAITING", "CLOSE_SHEV", "CLOSE_SQUARE", 
  "KW_FALSE", "NOT_IN", "ONKEY", "OPEN_BRACKET", "BORDER", "BOTTOM", 
  "COLUMN", "COMMIT", "CREATE", "CURSOR", "DEFINE", "DELETE", "DOUBLE", 
  "END_IF", "ESCAPE", "EXISTS", "EXTEND", "EXTENT", "FINISH", "FORMAT", 
  "HAVING", "HEADER", "INSERT", "LOCATE", "MARGIN", "MEMORY", "MINUTE", 
  "MODIFY", "NORMAL", "EQUAL_EQUAL", "OPEN_SHEV", "OPEN_SQUARE", "OPTION", 
  "OUTPUT", "PROMPT", "PUBLIC", "RECORD", "REPORT", "RETURN", "REVOKE", 
  "SCHEMA", "SCROLL_USING", "SCROLL", "SECOND", "SELECT", "SERIAL", 
  "SETL", "SHARED", "SPACES", "UNIQUE", "UNLOCK", "UPDATE", "VALUES", 
  "YELLOW", "AFTER", "KWLINE", "KW_NULL", "KW_TRUE", "SINGLE_KEY", 
  "ALTER", "ARRAY", "ASCII", "AUDIT", "BLACK", "BLINK", "CHECK", "CLEAR", 
  "CLOSE", "CODE_C", "COUNT", "DEFER", "ERROR", "EVERY", "FETCH", "FIRST", 
  "FLOAT", "FLUSH", "FOUND", "GRANT", "GREEN", "GROUP", "INDEX", "KWFORM", 
  "LABEL", "LOCAL", "MONEY", "MONTH", "ORDER", "OUTER", "PAUSE", 
  "PRINT_IMAGE", "PRINT_FILE", "PRINT", "RIGHT", "SEMICOLON", "SLEEP", 
  "TUPLE", "UNION", "WHERE", "WHILE", "WHITE", "CCODE", "ANSI", "BLUE", 
  "BOLD", "BYTE", "FCALL", "CASE", "CHAR", "CYAN", "DATE", "DESC", "DOWN", 
  "TAB", "DROP", "ELSE", "EXEC", "EXIT", "FREE", "FROM", "GOTO", 
  "HELP_FILE", "LANG_FILE", "HELP", "HIDE", "HOUR", "INTO", "LAST", 
  "LEFT", "LIKE", "MAIN", "MENU", "MODE", "NEED", "NEXT", "NOCR", "OPEN", 
  "QUIT", "REAL", "ROWS", "SHOW", "SIZE", "SKIP", "SOME", "STEP", "STOP", 
  "TEMP", "TEXT", "THEN", "USER", "WAIT", "WHEN", "WITH", "WORK", "YEAR", 
  "KW_IS", "XSET", "ADD", "ALL", "ANY", "ASC", "AVG", "COLON", "DAY", 
  "DBA", "DEC", "DIM", "FKEY", "FOR", "KEY", "KWNO", "LET", "LOG", "XMAX", 
  "XMIN", "NOT", "PAD", "PUT", "RED", "ROW", "RUN", "SQL", "SUM", "TOP", 
  "USE", "ATSIGN", "AS_TIFF", "AS_GIF", "AS_PNG", "AS_JPEG", "AS", "AT", 
  "BY", "DOT", "GO", "IF", "IN", "OF", "ON", "TO", "UP", "FONT_NAME", 
  "FONT_SIZE", "PAPER_SIZE_IS_LETTER", "PAPER_SIZE_IS_LEGAL", 
  "PAPER_SIZE_IS_A5", "PAPER_SIZE_IS_A4", "PAPER_SIZE_IS_LETTER_L", 
  "PAPER_SIZE_IS_LEGAL_L", "PAPER_SIZE_IS_A5_L", "PAPER_SIZE_IS_A4_L", 
  "FORMHANDLER", "END_FORMHANDLER", "BEFORE_EVENT", "BEFORE_OPEN_FORM", 
  "AFTER_EVENT", "BEFORE_CLOSE_FORM", "BEFORE_ANY", "AFTER_ANY", 
  "MENUHANDLER", "END_MENUHANDLER", "BEFORE_SHOW_MENU", "DISABLE_PROGRAM", 
  "DISABLE_ALL", "BUTTONS", "CHECK_MENUITEM", "DISABLE_FORM", 
  "DISABLE_MENUITEMS", "DISABLE", "ENABLE_FORM", "ENABLE_MENUITEMS", 
  "ENABLE", "KWFIELD", "ICON", "MESSAGEBOX", "TO_DEFAULTS", 
  "UNCHECK_MENUITEM", "BEFORE", "INPUT", "END", "INT_TO_ID", "$accept", 
  "pause_screen_on_cmd", "pause_screen_off_cmd", "start_rpc_cmd", 
  "stop_rpc_cmd", "valid_port", "remote_func_list", "remote_func", 
  "arr_expr", "arr_next_math", "arr_int_sign", "opt_attributes", 
  "attributes_def", "@1", "attribs_sec", "attribute", "win_attributes", 
  "win_attributes_def", "@2", "wattribs_sec", "wattribute", "call_cmd", 
  "call_ext", "@3", "@4", "@5", "@6", "@7", "@8", "@9", "@10", "@11", 
  "@12", "@13", "@14", "@15", "opt_return", "opt_return_remote", 
  "opt_func_call_args", "func_call_args", "func_arg", "remote_host_name", 
  "remote_func_name", "case_cmd", "@16", "@17", "when_unit", 
  "when_unit_expr", "end_case_command", "op_otherwise_command", "@18", 
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
  "where_upd", "set_clause_list", "special_upd_clause", "upd_columns", 
  "upd_column_name", "col_1", "upd_col_list", "upd_val_list", "upd_val", 
  "rollback_statement", "insert_statement", "@156", "ins_2", "@157", 
  "op_insert_column_list", "insert_column_list", "insert_value_list", 
  "insert_value", "fetch_statement", "@158", "@159", "fetch_part", 
  "opt_into_fetch_part", "@160", "opt_foreach_into_fetch_part", "@161", 
  "fetch_place", "delete_statement_position", "delete_statement_search", 
  "order_by_clause", "sort_specification_list", "sort_specification", 
  "sort_spec", "op_asc_desc", "begin_statement", "commit_statement", 
  "op_exclusive", "set_database_cmd", "sql_cmd", "@162", "sql_commands", 
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
  "op_not", "comparison_predicate", "comp_op", "predicate", "op_all", 
  "data_type", "char_string_type", "exact_numeric_type", "op_scale", 
  "approx_numeric_type", "length", "precision", "scale", "table_name", 
  "authorization_identifier", "col_arr", "column_name", 
  "correlation_name", "literal", "curr_v_clause", "curr_clause", 
  "cur_part", "cur_v_part", "s_curr_v", "e_curr_v", "s_curr", "e_curr", 
  "dbase_name", "flush_cmd", "declare_cmd", "@163", "@164", "@165", 
  "@166", "curs_forupdate", "cur_update_list", "colident", 
  "cursor_specification_all", "cursor_specification_sel", 
  "select_statement_full", "select_statement", "@167", "@168", 
  "in_select_statement", "select_statement2", "select_statement21", 
  "sel_p2", "tmp_tabname", "opt_into_sel", "query_specification", 
  "subquery", "op_ad", "select_list", "value_expression_pls", 
  "column_specification", "value_expression", "value_expr_list", 
  "value_specification", "unload_cmd", "load_cmd", "opt_delim", 
  "char_or_var", "opt_col_list", "col_list", "simple_column_name", 
  "ufile", "opt_use", "conn_id", "misc_sql", "rename_stmt", "rentabname", 
  "rencolname", "unlock_stmt", "lock_stmt", "share_or_exclusive", 
  "units_qual", "extend_qual", "var_ident", "var2", "var3", "aft_dot", 
  "var_ident_ibind", "whenever_cmd", "when_do", "label_goto", 
  "function_name_when", "while_cmd", "@169", "@170", "op_clr_fields", 
  "op_to_defs", "clear_cmd", "fld_list", "current_win_cmd", "window_type", 
  "show_cmd", "op_mnfile", "menu_name", "menu_handler", "hide_cmd", 
  "move_cmd", "NAMED", "commands", "all_commands", "command1", 
  "commands_all", "@171", "commands_all1", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const unsigned short yytoknum[] =
{
       0,   256,  1630,  1631,  1632,  1547,  1587,  1542,  1478,  1357,
    1465,  1461,  1375,  1537,  1274,  1332,  1406,  1573,  1560,  1493,
    1466,  1561,  1339,  1633,  1634,  1635,  1636,  1637,  1638,  1639,
    1640,  1641,  1000,  1001,  1002,  1003,  1004,  1005,  1006,  1007,
    1008,  1009,  1010,  1011,  1012,  1013,  1014,  1015,  1016,  1017,
    1018,  1019,  1020,  1021,  1022,  1023,  1024,  1025,  1026,  1027,
    1028,  1029,  1030,  1031,  1032,  1033,  1034,  1035,  1036,  1037,
    1038,  1039,  1040,  1041,  1042,  1043,  1044,  1045,  1046,  1047,
    1048,  1049,  1050,  1051,  1052,  1053,  1054,  1055,  1056,  1057,
    1058,  1059,  1060,  1061,  1062,  1063,  1064,  1065,  1066,  1067,
    1068,  1069,  1070,  1071,  1072,  1073,  1074,  1075,  1076,  1077,
    1078,  1079,  1080,  1081,  1082,  1083,  1084,  1085,  1086,  1087,
    1088,  1089,  1090,  1091,  1092,  1093,  1094,  1095,  1096,  1097,
    1098,  1099,  1100,  1101,  1102,  1103,  1104,  1105,  1106,  1107,
    1108,  1109,  1110,  1111,  1112,  1113,  1114,  1115,  1116,  1117,
    1118,  1119,  1120,  1121,  1122,  1123,  1124,  1125,  1126,  1127,
    1128,  1129,  1130,  1131,  1132,  1133,  1134,  1135,  1136,  1137,
    1138,  1139,  1140,  1141,  1142,  1143,  1144,  1145,  1146,  1147,
    1148,  1149,  1150,  1151,  1152,  1153,  1154,  1155,  1156,  1157,
    1158,  1159,  1160,  1161,  1162,  1163,  1164,  1165,  1166,  1167,
    1168,  1169,  1170,  1171,  1172,  1173,  1174,  1175,  1176,  1177,
    1178,  1179,  1180,  1181,  1182,  1183,  1184,  1185,  1186,  1187,
    1188,  1189,  1190,  1191,  1192,  1193,  1194,  1195,  1196,  1197,
    1198,  1199,  1200,  1201,  1202,  1203,  1204,  1205,  1206,  1207,
    1208,  1209,  1210,  1211,  1212,  1213,  1214,  1215,  1216,  1217,
    1218,  1219,  1220,  1221,  1222,  1223,  1224,  1225,  1226,  1227,
    1228,  1229,  1230,  1231,  1232,  1233,  1234,  1235,  1236,  1237,
    1238,  1239,  1240,  1241,  1242,  1243,  1244,  1245,  1246,  1247,
    1248,  1249,  1250,  1251,  1252,  1253,  1254,  1255,  1256,  1257,
    1258,  1259,  1260,  1261,  1262,  1263,  1264,  1265,  1266,  1267,
    1268,  1269,  1270,  1271,  1272,  1273,  1275,  1276,  1277,  1278,
    1279,  1280,  1281,  1282,  1283,  1284,  1285,  1286,  1287,  1288,
    1289,  1290,  1291,  1292,  1293,  1294,  1295,  1296,  1297,  1298,
    1299,  1300,  1301,  1302,  1303,  1304,  1305,  1306,  1307,  1308,
    1309,  1310,  1311,  1312,  1313,  1314,  1315,  1316,  1317,  1318,
    1319,  1320,  1321,  1322,  1323,  1324,  1325,  1326,  1327,  1328,
    1329,  1330,  1331,  1333,  1334,  1335,  1336,  1337,  1338,  1340,
    1341,  1342,  1343,  1344,  1345,  1346,  1347,  1348,  1349,  1350,
    1351,  1352,  1353,  1354,  1355,  1356,  1358,  1359,  1360,  1361,
    1362,  1363,  1364,  1365,  1366,  1367,  1368,  1369,  1370,  1371,
    1372,  1373,  1374,  1376,  1377,  1378,  1379,  1380,  1381,  1382,
    1383,  1384,  1385,  1386,  1387,  1388,  1389,  1390,  1391,  1392,
    1393,  1394,  1395,  1396,  1397,  1398,  1399,  1400,  1401,  1402,
    1403,  1404,  1405,  1407,  1408,  1409,  1410,  1411,  1412,  1413,
    1414,  1415,  1416,  1417,  1418,  1419,  1420,  1421,  1422,  1423,
    1424,  1425,  1426,  1427,  1428,  1429,  1430,  1431,  1432,  1433,
    1434,  1435,  1436,  1437,  1438,  1439,  1440,  1441,  1442,  1443,
    1444,  1445,  1446,  1447,  1448,  1449,  1450,  1451,  1452,  1453,
    1454,  1455,  1456,  1457,  1458,  1459,  1460,  1462,  1463,  1464,
    1467,  1468,  1469,  1470,  1471,  1472,  1473,  1474,  1475,  1476,
    1477,  1479,  1480,  1481,  1482,  1483,  1484,  1485,  1486,  1487,
    1488,  1489,  1490,  1491,  1492,  1494,  1495,  1496,  1497,  1498,
    1499,  1500,  1501,  1502,  1503,  1504,  1505,  1506,  1507,  1508,
    1509,  1510,  1511,  1512,  1513,  1514,  1515,  1516,  1517,  1518,
    1519,  1520,  1521,  1522,  1523,  1524,  1525,  1526,  1527,  1528,
    1529,  1530,  1531,  1532,  1533,  1534,  1535,  1536,  1538,  1539,
    1540,  1541,  1543,  1544,  1545,  1546,  1548,  1549,  1550,  1551,
    1552,  1553,  1554,  1555,  1556,  1557,  1558,  1559,  1562,  1563,
    1564,  1565,  1566,  1567,  1568,  1569,  1570,  1571,  1572,  1574,
    1575,  1576,  1577,  1578,  1579,  1580,  1581,  1582,  1583,  1584,
    1585,  1586,  1588,  1589,  1590,  1591,  1592,  1593,  1594,  1595,
    1596,  1597,  1598,  1599,  1600,  1601,  1602,  1603,  1604,  1605,
    1606,  1607,  1608,  1609,  1610,  1611,  1612,  1613,  1614,  1615,
    1616,  1617,  1618,  1619,  1620,  1621,  1622,  1623,  1624,  1625,
    1626,  1627,  1628,  1629
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const unsigned short yyr1[] =
{
       0,   644,   645,   646,   647,   648,   649,   649,   650,   650,
     651,   652,   652,   652,   652,   652,   653,   653,   653,   653,
     653,   654,   654,   655,   655,   657,   656,   656,   658,   658,
     659,   659,   659,   659,   659,   659,   659,   659,   659,   659,
     659,   659,   659,   659,   659,   659,   660,   660,   662,   661,
     663,   663,   664,   664,   664,   664,   664,   664,   664,   664,
     664,   665,   666,   667,   666,   666,   666,   666,   666,   668,
     669,   666,   670,   671,   672,   666,   673,   674,   666,   675,
     676,   666,   677,   678,   679,   666,   680,   680,   681,   681,
     681,   682,   682,   683,   683,   684,   685,   685,   686,   686,
     688,   687,   689,   687,   690,   690,   691,   691,   692,   693,
     694,   693,   695,   696,   695,   698,   697,   700,   699,   701,
     701,   701,   701,   701,   701,   702,   703,   703,   704,   704,
     705,   706,   706,   707,   708,   710,   711,   709,   712,   712,
     713,   713,   714,   714,   715,   715,   715,   716,   716,   718,
     717,   719,   717,   720,   717,   721,   717,   722,   717,   723,
     723,   724,   724,   725,   725,   725,   725,   725,   725,   726,
     726,   727,   727,   728,   728,   730,   731,   729,   729,   729,
     732,   732,   734,   733,   735,   735,   735,   735,   736,   735,
     737,   737,   737,   737,   738,   739,   739,   740,   740,   742,
     741,   743,   741,   744,   744,   745,   745,   746,   747,   747,
     747,   748,   750,   749,   751,   749,   752,   749,   753,   753,
     754,   755,   756,   756,   758,   759,   757,   760,   760,   760,
     760,   760,   760,   760,   760,   760,   760,   760,   760,   760,
     760,   760,   760,   760,   760,   760,   760,   760,   760,   760,
     760,   760,   760,   760,   760,   761,   762,   763,   764,   764,
     765,   767,   766,   768,   768,   768,   768,   768,   768,   768,
     770,   769,   771,   771,   772,   772,   773,   775,   774,   776,
     776,   776,   776,   776,   776,   776,   777,   778,   778,   780,
     779,   781,   781,   781,   781,   781,   781,   781,   781,   781,
     781,   781,   781,   781,   781,   781,   781,   781,   781,   781,
     781,   781,   781,   781,   782,   784,   783,   785,   783,   787,
     786,   788,   786,   789,   789,   790,   791,   791,   792,   793,
     793,   793,   793,   793,   793,   793,   793,   794,   795,   796,
     798,   799,   797,   800,   800,   801,   802,   802,   803,   803,
     805,   804,   806,   804,   807,   804,   808,   808,   809,   809,
     809,   809,   809,   809,   809,   809,   809,   810,   810,   810,
     810,   810,   810,   810,   810,   811,   811,   812,   812,   812,
     812,   812,   812,   812,   812,   812,   812,   813,   813,   813,
     813,   813,   813,   813,   813,   813,   813,   814,   814,   815,
     815,   816,   816,   817,   817,   818,   818,   819,   820,   820,
     821,   821,   821,   821,   821,   821,   822,   822,   823,   823,
     823,   823,   824,   824,   825,   826,   826,   826,   827,   826,
     828,   828,   829,   829,   830,   830,   830,   830,   831,   831,
     832,   832,   832,   832,   833,   834,   835,   835,   835,   835,
     835,   835,   836,   836,   836,   836,   836,   836,   836,   837,
     839,   840,   838,   841,   842,   838,   844,   845,   843,   846,
     847,   843,   848,   849,   843,   850,   851,   843,   843,   843,
     843,   843,   843,   843,   852,   852,   853,   853,   854,   854,
     854,   854,   854,   854,   854,   854,   854,   855,   855,   856,
     856,   856,   856,   857,   857,   857,   858,   858,   858,   860,
     861,   859,   862,   862,   864,   865,   866,   863,   868,   869,
     867,   870,   870,   871,   871,   872,   872,   874,   873,   875,
     873,   876,   876,   877,   877,   879,   878,   880,   878,   881,
     882,   882,   882,   883,   883,   884,   884,   885,   885,   886,
     886,   888,   887,   889,   887,   890,   887,   891,   887,   892,
     887,   893,   894,   894,   894,   894,   894,   894,   895,   895,
     896,   897,   898,   899,   899,   899,   899,   899,   899,   899,
     899,   900,   901,   902,   903,   904,   905,   906,   906,   907,
     908,   909,   909,   910,   910,   911,   912,   913,   913,   913,
     913,   913,   913,   914,   915,   915,   916,   916,   916,   916,
     916,   916,   916,   916,   916,   916,   916,   916,   916,   916,
     916,   916,   916,   916,   916,   916,   916,   916,   916,   916,
     916,   916,   916,   916,   916,   916,   916,   916,   916,   916,
     916,   916,   916,   916,   916,   916,   916,   916,   916,   917,
     918,   919,   919,   920,   921,   922,   922,   922,   923,   923,
     923,   925,   924,   926,   926,   927,   927,   928,   928,   929,
     930,   930,   931,   932,   932,   933,   934,   934,   935,   936,
     936,   938,   937,   939,   940,   939,   941,   942,   939,   943,
     944,   946,   945,   945,   947,   947,   948,   948,   949,   949,
     950,   950,   951,   951,   953,   952,   954,   952,   955,   952,
     956,   952,   957,   952,   958,   952,   959,   952,   960,   952,
     961,   952,   962,   962,   963,   963,   964,   964,   965,   965,
     966,   966,   967,   967,   968,   969,   970,   970,   970,   972,
     971,   973,   973,   974,   973,   975,   976,   976,   976,   976,
     977,   977,   979,   978,   978,   981,   980,   982,   984,   983,
     985,   985,   986,   986,   988,   987,   989,   989,   989,   989,
     989,   989,   989,   989,   989,   989,   989,   989,   989,   989,
     989,   989,   990,   992,   993,   991,   994,   994,   995,   996,
     997,   998,   998,  1000,   999,  1001,  1001,  1002,  1002,  1003,
    1003,  1003,  1003,  1004,  1004,  1005,  1005,  1006,  1007,  1007,
    1007,  1007,  1007,  1007,  1007,  1007,  1007,  1007,  1007,  1008,
    1008,  1009,  1009,  1009,  1010,  1011,  1011,  1013,  1014,  1015,
    1016,  1012,  1017,  1019,  1020,  1018,  1021,  1022,  1022,  1023,
    1024,  1025,  1025,  1026,  1026,  1026,  1028,  1027,  1029,  1029,
    1031,  1032,  1033,  1030,  1035,  1034,  1036,  1038,  1037,  1039,
    1037,  1040,  1037,  1041,  1041,  1042,  1042,  1043,  1043,  1044,
    1044,  1044,  1045,  1046,  1047,  1048,  1048,  1048,  1049,  1049,
    1050,  1050,  1052,  1053,  1051,  1054,  1054,  1056,  1055,  1057,
    1055,  1058,  1059,  1059,  1059,  1059,  1060,  1060,  1060,  1060,
    1060,  1062,  1061,  1063,  1063,  1064,  1065,  1066,  1066,  1067,
    1068,  1068,  1068,  1068,  1068,  1069,  1070,  1071,  1071,  1072,
    1072,  1073,  1074,  1074,  1075,  1075,  1076,  1077,  1078,  1078,
    1078,  1078,  1078,  1079,  1079,  1080,  1081,  1081,  1082,  1082,
    1083,  1083,  1084,  1084,  1085,  1085,  1085,  1085,  1085,  1086,
    1086,  1087,  1087,  1088,  1088,  1089,  1090,  1091,  1091,  1092,
    1093,  1093,  1093,  1094,  1095,  1095,  1096,  1096,  1097,  1098,
    1098,  1099,  1099,  1100,  1101,  1102,  1103,  1103,  1104,  1105,
    1105,  1106,  1106,  1107,  1107,  1108,  1109,  1109,  1110,  1110,
    1110,  1110,  1111,  1111,  1111,  1112,  1113,  1113,  1114,  1114,
    1114,  1115,  1116,  1116,  1117,  1117,  1117,  1117,  1117,  1117,
    1117,  1117,  1117,  1117,  1117,  1117,  1117,  1117,  1117,  1117,
    1117,  1117,  1117,  1117,  1117,  1117,  1118,  1119,  1119,  1120,
    1120,  1121,  1123,  1122,  1124,  1125,  1125,  1126,  1126,  1127,
    1127,  1129,  1128,  1130,  1132,  1131,  1133,  1133,  1134,  1134,
    1135,  1135,  1136,  1136,  1136,  1136,  1137,  1137,  1138,  1139,
    1139,  1140,  1141,  1142,  1143,  1143,  1144,  1144,  1146,  1145,
    1147,  1145,  1148,  1145,  1149,  1145,  1150,  1145,  1151,  1145,
    1152,  1145,  1153,  1153,  1153,  1153,  1153,  1153,  1155,  1154,
    1156,  1156,  1158,  1157,  1157,  1157,  1157,  1157,  1159,  1159,
    1160,  1160,  1161,  1162,  1162,  1163,  1164,  1165,  1166,  1166,
    1166,  1167,  1167,  1167,  1167,  1168,  1169,  1169,  1170,  1170,
    1171,  1172,  1172,  1172,  1172,  1172,  1172,  1172,  1172,  1173,
    1173,  1174,  1174,  1175,  1175,  1175,  1175,  1175,  1175,  1175,
    1175,  1175,  1175,  1176,  1176,  1177,  1177,  1177,  1177,  1178,
    1178,  1179,  1179,  1180,  1180,  1180,  1180,  1180,  1180,  1180,
    1180,  1180,  1180,  1180,  1180,  1180,  1180,  1180,  1180,  1180,
    1180,  1180,  1180,  1180,  1180,  1180,  1180,  1181,  1181,  1181,
    1183,  1184,  1185,  1186,  1187,  1188,  1182,  1189,  1189,  1190,
    1191,  1191,  1193,  1194,  1195,  1196,  1197,  1198,  1192,  1199,
    1201,  1202,  1203,  1200,  1204,  1204,  1204,  1204,  1205,  1205,
    1205,  1205,  1205,  1206,  1207,  1207,  1207,  1208,  1209,  1210,
    1211,  1209,  1212,  1213,  1209,  1209,  1214,  1214,  1215,  1215,
    1216,  1216,  1216,  1217,  1217,  1218,  1218,  1219,  1219,  1220,
    1221,  1222,  1222,  1223,  1223,  1223,  1223,  1223,  1223,  1223,
    1224,  1224,  1225,  1225,  1226,  1226,  1227,  1227,  1228,  1228,
    1229,  1230,  1230,  1231,  1231,  1232,  1233,  1233,  1234,  1235,
    1235,  1236,  1236,  1237,  1237,  1238,  1239,  1239,  1239,  1239,
    1239,  1239,  1239,  1239,  1239,  1239,  1239,  1240,  1240,  1241,
    1241,  1242,  1243,  1244,  1244,  1244,  1245,  1245,  1245,  1246,
    1246,  1247,  1247,  1248,  1249,  1250,  1250,  1251,  1251,  1252,
    1252,  1252,  1253,  1255,  1254,  1257,  1256,  1256,  1258,  1258,
    1259,  1259,  1260,  1260,  1261,  1261,  1263,  1264,  1262,  1265,
    1265,  1266,  1267,  1266,  1268,  1269,  1268,  1270,  1270,  1270,
    1270,  1270,  1270,  1270,  1270,  1271,  1272,  1273,  1274,  1274,
    1275,  1276,  1276,  1277,  1277,  1277,  1278,  1279,  1280,  1280,
    1281,  1283,  1282,  1284,  1284,  1284,  1284,  1284,  1284,  1284,
    1284,  1284,  1284,  1284,  1284,  1285,  1286,  1286,  1287,  1287,
    1288,  1288,  1289,  1289,  1289,  1289,  1290,  1290,  1291,  1291,
    1292,  1292,  1293,  1293,  1294,  1295,  1295,  1296,  1296,  1297,
    1297,  1298,  1299,  1300,  1301,  1302,  1302,  1303,  1303,  1304,
    1304,  1305,  1305,  1306,  1306,  1306,  1307,  1307,  1308,  1309,
    1309,  1310,  1310,  1311,  1311,  1311,  1311,  1312,  1313,  1314,
    1315,  1315,  1316,  1316,  1317,  1318,  1319,  1319,  1320,  1321,
    1322,  1322,  1323,  1323,  1323,  1324,  1324,  1325,  1325,  1326,
    1327,  1327,  1328,  1328,  1329,  1329,  1330,  1330,  1331,  1331,
    1332,  1332,  1333,  1333,  1334,  1334,  1335,  1335,  1336,  1336,
    1336,  1337,  1338,  1338,  1339,  1340,  1341,  1342,  1342,  1342,
    1342,  1343,  1343,  1344,  1344,  1345,  1345,  1345,  1345,  1345,
    1345,  1346,  1346,  1346,  1346,  1346,  1346,  1346,  1346,  1346,
    1346,  1347,  1347,  1347,  1347,  1348,  1348,  1348,  1348,  1349,
    1349,  1349,  1350,  1350,  1351,  1351,  1351,  1351,  1351,  1351,
    1351,  1351,  1351,  1351,  1351,  1351,  1351,  1351,  1351,  1351,
    1351,  1352,  1352,  1353,  1353,  1353,  1353,  1353,  1354,  1355,
    1356,  1357,  1357,  1357,  1357,  1358,  1359,  1359,  1359,  1360,
    1360,  1360,  1361,  1362,  1362,  1362,  1362,  1362,  1362,  1362,
    1362,  1362,  1363,  1364,  1365,  1365,  1366,  1366,  1367,  1367,
    1367,  1367,  1367,  1367,  1367,  1367,  1368,  1368,  1368,  1368,
    1368,  1368,  1368,  1368,  1369,  1369,  1369,  1369,  1369,  1369,
    1369,  1370,  1370,  1370,  1370,  1370,  1370,  1370,  1371,  1371,
    1372,  1374,  1373,  1375,  1373,  1376,  1373,  1377,  1373,  1378,
    1378,  1378,  1379,  1379,  1380,  1380,  1380,  1381,  1381,  1382,
    1382,  1383,  1385,  1386,  1384,  1387,  1388,  1388,  1389,  1390,
    1390,  1390,  1390,  1390,  1391,  1392,  1392,  1393,  1394,  1395,
    1395,  1395,  1395,  1396,  1396,  1397,  1397,  1397,  1398,  1399,
    1399,  1399,  1399,  1399,  1399,  1399,  1399,  1399,  1399,  1399,
    1399,  1399,  1399,  1399,  1399,  1399,  1399,  1399,  1399,  1399,
    1400,  1400,  1401,  1401,  1402,  1403,  1404,  1404,  1405,  1405,
    1406,  1406,  1407,  1407,  1408,  1409,  1409,  1410,  1410,  1411,
    1412,  1412,  1412,  1413,  1413,  1414,  1415,  1416,  1417,  1418,
    1418,  1419,  1419,  1419,  1419,  1419,  1419,  1420,  1420,  1420,
    1421,  1422,  1422,  1423,  1423,  1423,  1423,  1424,  1424,  1424,
    1425,  1425,  1426,  1426,  1426,  1426,  1426,  1426,  1426,  1426,
    1426,  1427,  1427,  1427,  1427,  1427,  1428,  1428,  1429,  1431,
    1432,  1430,  1433,  1433,  1434,  1434,  1435,  1435,  1435,  1435,
    1435,  1435,  1435,  1436,  1436,  1437,  1437,  1438,  1438,  1439,
    1439,  1440,  1440,  1441,  1442,  1443,  1444,  1444,  1445,  1446,
    1446,  1447,  1448,  1448,  1450,  1449,  1451,  1451,  1451,  1451,
    1451,  1451,  1451,  1451,  1451,  1451,  1451,  1451,  1451,  1451,
    1451,  1451,  1451,  1451,  1451,  1451,  1451,  1451,  1451,  1451,
    1451,  1451,  1451,  1451,  1451,  1451,  1451,  1451,  1451,  1451,
    1451,  1451,  1451,  1451,  1451,  1451,  1451,  1451,  1451,  1451,
    1451,  1451,  1451,  1451,  1451,  1451,  1451,  1451,  1451,  1451,
    1451,  1451,  1451,  1451,  1451,  1451,  1451,  1451,  1451,  1451,
    1451,  1451,  1451,  1451,  1451,  1451,  1451,  1451,  1451,  1451,
    1451,  1451,  1451,  1451,  1451,  1451,  1451,  1451,  1451
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
       1,     2,     5,     0,     2,     2,     1,     7,     1,     5,
       3,     1,     3,     1,     3,     1,     3,     1,     3,     1,
       1,     1,     1,     0,     5,     0,     5,     1,     0,     3,
       1,     3,     1,     3,     1,     1,     0,     0,     5,     2,
       1,     0,     0,     3,     0,     0,     3,     1,     1,     1,
       1,     1,     1,     2,     2,     4,     3,     3,     1,     3,
       2,     1,     1,     0,     1,     1,     1,     1,     0,     1,
       3,     0,     3,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     7,     0,     1,     1,     1,
       1,     3,     1,     1,     1,     2,     0,     3,     1,     3,
       1,     3,     1,     1,     6,     0,     3,     1,     3,     0,
       1,     4,     5,     2,     1,     1,     4,     1,     3,     4,
       4,     1,     3,     1,     1,     1,     2,     1,     4,     0,
       1,     0,     2,     1,     1,     1,     4,     3,     1,     1,
       1,     2,     1,     1,     2,     2,     1,     3,     2,     2,
       1,     3,     1,     2,     4,     1,     2,     1,     3,     4,
       0,     1,     0,     1,     0,     1,     1,     3,     1,     3,
       1,     2,     1,     3,     2,     2,     4,     3,     0,     1,
       1,     1,     1,     1,     2,     1,     1,     5,     3,     5,
       3,     1,     3,     0,     1,     3,     3,     3,     3,     6,
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
       1,     1,     1,     1,     3,     1,     2,     2,     1,     3,
       2,     3,     3,     3,     1,     1,     1,     1,     1,     1,
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
     795,     0,   595,     0,     0,     0,     0,     0,     0,     0,
    1725,     0,   595,   595,   846,   175,   819,   824,   173,   178,
     799,     0,   793,   796,   797,   800,   802,   845,   801,   840,
     841,   843,   179,   133,   130,     0,   126,   128,   127,   131,
     690,     0,  1731,   595,   595,  1734,     0,  1730,  1727,  1724,
    1722,  1723,  1729,  1728,  1726,   289,  1599,  1598,   839,   171,
     182,   174,   179,     1,   803,   798,   844,   842,   820,   125,
     129,   132,  1768,   596,  1738,  1735,   595,  1736,  1733,   595,
       0,   568,   595,     0,   172,   849,   913,   569,   847,   603,
     906,   595,   907,   914,   912,   182,   176,   194,   595,   180,
     195,   224,   826,  1192,   595,   595,   825,   134,  1180,   833,
     595,   595,   816,   818,   815,   817,   794,   804,   805,   827,
     808,   809,   810,   813,   811,   812,   814,   589,  1737,  1732,
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
       0,   234,   222,  1193,     0,     0,  1181,  1774,   519,   883,
     828,     0,   203,   204,     0,   270,   272,   267,   268,   264,
     266,   263,   265,   262,     0,   272,   283,   284,   280,   282,
     279,   281,   274,     0,     0,     0,   323,     0,   326,   328,
     211,     0,   210,     0,     0,   182,    11,    12,   925,   595,
     911,   605,   193,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   182,   223,   226,   595,   689,   850,   595,     0,
    1772,  1774,  1116,  1687,   821,     0,   595,     0,     0,   259,
       0,     0,   269,   286,   260,   285,     0,   278,     0,   301,
       0,   295,   595,   320,   595,   325,   315,     0,     0,   304,
     294,   257,   314,     0,     0,     0,     0,     0,   239,     0,
     231,   213,   199,     0,   242,   230,   255,   942,     0,   937,
     938,   595,     0,   835,  1773,  1771,   595,   595,   595,   595,
     595,   595,   595,  1755,   595,  1282,  1281,   595,  1283,   595,
     371,  1280,  1222,   595,     5,  1279,   372,   369,   595,   374,
     169,   459,  1094,     0,     0,  1289,   122,   368,   367,  1214,
     362,   595,  1238,  1746,   595,   373,   340,   595,     3,     2,
     595,   370,  1219,   595,   595,   363,   360,   375,   595,   595,
     595,   595,   595,  1277,   366,   595,   595,   595,   595,   595,
     595,   595,   595,  1276,   595,   595,   595,   170,  1216,   359,
     358,   595,   595,  1750,  1749,   595,   595,   595,   135,  1215,
     365,   364,   595,   595,   361,   901,   459,   595,   514,     0,
     595,   595,   459,   595,   595,   595,   459,   782,  1190,   595,
     595,  1098,   595,  1739,   595,   102,   595,   595,   854,   595,
     595,   595,   595,   783,   595,   595,   595,     0,   595,   595,
     595,   595,   595,   595,   595,   661,   595,   595,  1776,  1777,
    1778,  1779,  1780,  1781,  1782,  1783,  1784,  1785,  1786,  1787,
    1788,  1789,  1790,  1791,  1792,  1793,  1794,  1795,  1796,  1797,
    1798,  1799,  1800,  1801,  1802,  1803,  1804,  1805,  1806,  1807,
    1808,  1809,  1810,  1811,  1812,  1813,  1814,  1815,  1816,  1817,
    1818,  1819,  1820,  1821,  1822,   892,  1823,  1824,  1825,  1826,
    1827,  1828,  1829,  1830,  1831,  1832,  1833,  1834,  1835,  1836,
    1837,  1838,  1085,  1087,  1082,  1084,  1083,  1086,  1839,  1840,
    1213,  1841,  1217,  1842,  1843,  1239,  1844,  1845,  1846,  1847,
    1848,  1849,  1850,  1851,  1361,  1852,  1853,  1854,  1855,  1856,
    1857,  1858,  1775,   822,   523,   823,   595,   887,     0,   885,
       0,   322,   205,   206,     0,   271,   276,     0,     0,     0,
       0,   324,   327,     0,   209,     0,   923,   215,     0,   182,
       0,     0,     0,     0,   595,  1194,   595,     0,  1182,     0,
    1225,     0,   807,  1748,   583,   121,     0,   595,  1714,  1713,
     996,  1710,  1712,  1763,     0,  1232,     0,  1228,  1237,     7,
       0,     6,   595,  1756,  1058,  1059,   595,  1150,  1149,  1097,
    1148,  1096,   595,   595,   418,   420,     0,  1187,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   595,  1566,
       0,     0,     0,   412,   595,   595,     0,     0,   411,   595,
       0,   428,     0,   498,     0,     0,     0,     0,     0,   595,
       0,   407,  1290,     0,   378,   377,   384,   424,   421,   379,
     496,   488,   380,   382,   495,   383,   913,   419,   422,   427,
    1278,   497,  1689,  1284,   123,   595,  1062,   120,   595,   789,
      23,   585,   376,     0,   788,  1055,   790,     0,  1288,   876,
     875,   878,   874,   877,  1765,     0,   872,     0,   584,   969,
     873,  1759,     0,  1747,   119,   966,   691,   964,     0,   581,
    1742,   737,   736,     0,   738,   573,   734,     0,   595,   979,
     586,  1358,   595,   595,  1031,  1029,   595,  1023,  1025,  1024,
    1022,  1021,   595,   595,   595,  1020,   595,   764,   595,   595,
       0,     0,     0,     0,   595,   595,     0,     0,     0,  1010,
    1001,  1002,     0,  1043,   405,    23,   836,   397,  1753,     0,
    1744,   124,   582,   595,  1028,  1027,  1191,  1189,  1115,     0,
    1678,  1679,  1116,  1204,  1116,  1099,  1100,  1103,  1118,  1291,
     595,     0,     0,     0,     0,     0,   595,     0,   595,     0,
      61,     0,   913,     0,    67,     0,   100,   561,   649,   595,
    1088,   986,  1092,     0,   595,  1044,  1208,     0,  1095,   653,
     650,   651,     0,   655,   656,     0,   658,   659,   595,   654,
     946,   948,   595,   595,   947,   739,   944,   700,   940,   905,
       0,   595,   595,     0,   665,   666,     0,     0,   903,   899,
     900,   896,   897,   898,   891,   895,   894,   595,   595,   595,
     595,   595,     0,   527,   529,   521,   524,   525,   889,  1774,
     884,   886,   829,     0,   273,   275,   302,   296,     0,     0,
     305,     0,   220,     0,   218,   240,   232,   224,   243,   943,
     171,   939,   851,   171,     0,   595,     0,  1266,  1267,   595,
     595,   595,  1240,  1241,  1243,  1244,  1245,  1249,  1248,  1246,
    1247,     0,   596,   591,   595,  1711,   595,   595,   998,   595,
     595,  1231,  1230,   595,  1218,     0,  1542,  1543,     0,  1060,
       0,    23,  1145,  1147,  1146,   386,   385,   595,   595,  1122,
     463,   595,   595,   595,   595,     0,   595,     0,     0,   595,
     426,  1574,  1572,  1573,  1569,  1571,  1568,  1570,  1562,     0,
     595,     0,   595,     0,   425,     0,   595,   501,     0,     0,
     469,   466,   475,   595,   472,   595,   595,   410,   595,   595,
     595,   595,   595,   595,   595,   595,   595,   595,   595,   595,
     595,   595,   595,   595,   595,   163,   164,   165,   166,   167,
     168,   503,   504,   505,   439,   595,   595,   438,   444,     0,
     595,   390,   595,     0,   391,   381,   387,   389,   392,   393,
     394,   395,   396,   388,   417,   416,   460,   595,   956,     0,
       0,   345,    24,   339,   595,   595,  1052,   595,   595,   595,
     595,   595,   595,     0,   973,  1688,   595,   595,   182,     0,
     595,   595,  1744,   595,   595,   595,   595,   595,   136,     0,
     595,   983,   975,   976,   981,  1359,  1360,   902,   329,   403,
     595,   515,   566,   565,   563,  1004,   567,  1009,  1005,  1008,
     757,     0,  1006,  1007,   758,  1014,  1018,  1011,  1012,  1016,
    1017,  1015,  1013,  1019,     0,   791,   595,   595,     0,   400,
     401,   398,   399,   595,     0,     0,   747,   746,   745,  1745,
    1752,    23,  1111,  1112,  1113,  1114,  1108,  1106,  1205,  1120,
    1105,  1101,   595,     0,  1102,  1740,    79,   595,     0,   595,
     595,    96,     0,    97,   595,     0,   595,    72,   595,   595,
     109,   104,     0,   881,     0,   880,     0,   459,  1090,   595,
     931,   932,   955,   927,   928,   784,   953,  1046,  1210,   595,
    1212,  1211,   681,   595,   595,   595,   670,   700,   700,   698,
     595,   595,   701,     0,    25,   669,   672,     0,   679,   675,
     904,   893,  1685,  1686,  1676,  1676,     0,     0,  1600,   595,
     182,  1312,   595,   595,  1313,  1356,   182,   595,  1357,   595,
    1639,   595,  1326,     0,  1374,  1372,  1371,  1370,  1368,  1369,
    1367,  1365,  1362,  1433,  1432,  1363,  1364,  1373,  1609,  1366,
    1692,  1691,  1690,  1774,  1774,   540,   531,   522,     0,   526,
    1774,   888,   171,     0,   316,   208,     0,   182,   217,   200,
    1195,   171,  1183,  1424,   595,  1423,     0,     0,  1425,  1269,
       0,  1275,  1271,  1268,     0,     0,   595,     0,     0,     0,
    1265,  1261,  1415,  1414,  1413,  1236,  1235,   595,  1260,  1256,
     595,  1252,  1250,     0,   595,   590,     0,     0,   997,   595,
       0,   995,  1717,  1719,  1718,  1715,  1764,  1761,  1229,   595,
     595,   595,  1223,   459,   337,     0,  1188,    91,     0,     0,
       0,     0,  1639,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   413,     0,     0,     0,     0,
       0,   429,   595,   595,   595,     0,   595,     0,     0,     0,
     431,   430,   445,   440,   451,   454,   455,   452,   458,   457,
     456,   446,   447,   449,   448,   450,   441,   443,   459,   453,
     442,   459,    91,   423,   595,  1220,   988,  1056,  1057,  1054,
    1053,     0,   879,     0,     0,   570,     0,     0,   595,   967,
     965,     0,   693,   694,     0,     0,  1743,  1751,     0,     0,
     577,     0,   579,   735,     0,   140,   595,   977,   984,     0,
     595,   992,   595,   332,   595,   595,   595,   595,    23,  1030,
    1334,     0,     0,   781,   769,   779,   780,   767,   768,   775,
     771,   774,   770,   778,   773,   776,   777,   766,   772,   765,
     764,  1003,   792,   406,   595,  1035,   595,  1754,   748,   749,
     356,   595,  1116,   595,  1119,  1104,  1774,    91,     0,     0,
       0,     0,   595,     0,   595,    62,    91,     0,   115,   110,
       0,   105,   595,   112,   106,   865,   857,   863,     0,  1089,
     595,  1091,  1093,     0,   595,   935,     0,   595,     0,   595,
    1045,  1209,  1774,   652,   657,   660,   673,   671,   587,     0,
     595,   595,   716,   754,   714,   710,   708,   752,     0,     0,
     740,     0,   702,   712,   945,   941,   595,     0,     0,     0,
     678,   595,     0,   595,   595,     0,     0,   595,  1545,     0,
    1428,  1429,  1697,  1395,  1450,   595,     0,  1695,     0,     0,
    1641,  1642,  1640,   595,     0,   595,  1378,  1384,  1383,  1382,
    1386,     0,  1379,  1380,   595,  1610,  1621,   528,   530,   595,
       0,   543,   535,   537,     0,   532,   533,   595,   595,   551,
     553,   595,     0,   549,   890,   830,   207,     0,     0,   219,
    1151,   852,  1129,  1403,  1405,     0,  1273,   595,     0,   595,
     595,     0,  1263,   595,   595,  1537,  1535,  1522,  1524,  1520,
       0,  1519,     0,  1528,  1515,  1536,     0,  1527,  1512,  1518,
    1534,  1526,  1419,  1509,  1510,  1511,     0,  1258,  1254,     0,
     595,  1242,   594,     0,   593,   595,   963,     0,   595,   595,
    1760,     4,     8,    10,  1541,  1544,   595,   459,   494,   464,
      92,    93,    95,   491,   490,   493,   489,   595,   415,   500,
     484,   484,     0,   486,   486,     0,  1187,     0,  1582,  1580,
    1581,  1577,  1579,  1576,  1578,  1567,   492,  1187,   499,   414,
       0,     0,   502,     0,  1187,   470,   467,   476,  1187,   473,
    1187,  1187,  1187,   595,     0,   595,     0,   461,     0,   595,
     595,   985,   595,   595,   595,   595,   595,     0,   595,   182,
     692,   595,   574,   576,   595,   595,   157,   155,   595,   595,
     137,     0,   147,   153,   700,   142,   144,   595,   982,   993,
     994,     0,   404,   331,   336,   572,   330,   595,   333,   338,
    1335,   516,   564,   562,   764,   759,   760,  1034,  1036,   595,
     402,   357,  1109,  1107,  1206,  1207,     0,    80,    65,  1200,
       0,     0,     0,    98,     0,     0,    73,    69,  1774,  1774,
     108,   103,   117,   113,     0,   107,   755,   866,   587,  1774,
     856,   855,   864,   987,   595,     0,   595,   954,   459,     0,
       0,  1659,  1553,  1556,  1660,  1564,  1554,  1657,   595,     0,
    1051,  1656,     0,   595,  1658,     0,     0,     0,     0,  1714,
    1555,  1047,  1048,  1655,  1561,  1050,  1720,  1654,   683,   676,
     674,     0,    23,   595,   730,   704,   732,   706,  1774,  1774,
    1774,  1774,   764,   725,   724,   720,   722,   729,   728,   718,
     726,   699,   703,  1774,   587,    45,    43,    40,    34,    38,
      42,    37,    30,    39,    33,    36,    31,    41,    32,    44,
      35,     0,    28,     0,   680,  1677,   595,   595,  1674,  1626,
    1627,  1619,  1605,  1620,     0,     0,   595,  1026,  1427,  1430,
     595,     0,   595,   595,  1451,  1346,  1318,  1700,  1699,  1698,
     595,   595,  1622,  1643,  1645,   595,  1341,   595,  1340,   595,
    1342,  1337,  1338,  1339,  1330,  1327,   595,   595,  1385,   595,
       0,     0,  1614,  1611,  1612,   542,   547,   595,   595,  1774,
    1774,   520,   534,   557,   545,   559,  1774,  1774,   555,   539,
     550,   821,   317,   201,     0,  1177,  1196,   821,     0,  1184,
    1177,   595,     0,  1270,     0,   595,     0,   595,     0,  1456,
    1458,  1460,  1504,  1503,  1502,  1501,  1462,     0,  1483,  1272,
    1546,     0,  1404,   595,  1407,     0,  1411,   595,  1262,     0,
       0,  1590,  1588,  1589,  1585,  1587,  1584,  1586,     0,     0,
       0,     0,     0,     0,     0,     0,  1417,     0,  1420,  1421,
     595,  1257,   595,  1251,  1253,   592,  1716,   595,     0,  1762,
     595,     0,  1233,   595,     0,     0,   595,     0,   481,     0,
     482,     0,   478,     0,   479,     0,  1125,  1575,     0,  1124,
       0,     0,     0,  1123,     0,     0,     0,  1126,     0,  1128,
    1127,  1121,   432,     0,   435,     0,   434,     0,     0,     0,
     595,     0,  1285,  1767,  1766,   571,   595,     0,    46,   595,
     697,   696,   695,  1286,   595,     0,   700,  1774,  1774,   149,
     597,   159,   151,   161,   141,   148,  1774,   595,     0,   595,
       0,   595,     0,   595,  1774,     0,   762,   587,   595,  1741,
       0,    91,   595,    63,   595,   595,   595,    76,     0,    91,
     116,   111,  1774,  1774,   101,   764,   867,   861,   869,   868,
     858,   512,   916,   933,   934,   929,   595,  1558,  1557,  1560,
    1559,  1563,     0,     0,   595,  1505,     0,  1505,  1505,  1505,
    1505,   595,   595,   595,   595,   595,   595,  1701,  1702,  1703,
    1704,  1705,  1706,  1650,   595,   686,   684,     0,   663,   677,
     588,   741,     0,   595,  1774,   595,  1774,   717,   715,   711,
     709,   753,     0,  1774,     0,  1774,   713,    23,     0,    26,
       0,  1680,  1639,  1609,   595,   595,  1618,  1601,  1617,  1431,
       0,  1397,     0,  1345,  1438,   595,     0,  1696,     0,  1693,
     595,  1635,   627,   612,   625,   631,   646,   611,   623,   606,
     639,   642,   645,   609,   640,   618,   622,   633,   644,   641,
     643,   634,   616,   614,   638,   620,   619,   607,   608,   610,
     613,   624,   636,   615,   648,   626,   630,   632,   647,   621,
     635,   637,   617,   628,   629,  1647,  1646,     0,   595,  1293,
    1296,  1298,     0,  1301,  1303,  1344,  1343,  1331,  1329,     0,
    1388,     0,  1381,   595,   595,   595,   595,   544,   541,   536,
     538,   595,  1774,  1774,   552,   554,  1774,  1774,     0,     0,
    1175,  1176,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1174,     0,     0,  1162,  1163,  1164,  1161,
    1166,  1167,  1168,  1165,  1152,  1143,   595,     0,  1199,     0,
    1774,     0,  1138,     0,     0,     0,     0,     0,     0,   595,
    1130,  1131,     0,  1063,     0,  1274,     0,  1465,   595,     0,
    1483,  1464,  1461,   595,  1426,   595,  1497,  1493,  1494,  1491,
    1500,  1499,  1492,  1495,  1496,  1498,   595,     0,  1484,     0,
       0,   595,     0,  1549,     0,   595,     0,   595,  1410,  1264,
    1409,  1401,     0,     0,     0,  1539,  1531,  1531,     0,     0,
    1531,  1538,     0,  1553,  1416,  1418,  1421,  1259,  1255,  1000,
     595,     9,   595,  1226,   838,  1061,   465,    94,   595,  1450,
    1629,     0,   484,     0,   486,     0,     0,   508,     0,   471,
     468,   477,   474,   595,   437,   436,   462,   343,  1221,     0,
     595,  1758,     0,     0,   968,    47,     0,   578,   580,   575,
     750,   158,   156,   595,  1774,   595,   595,   595,  1774,   154,
     143,   595,   146,   145,   595,   974,   978,   335,   595,   951,
    1336,   949,     0,   764,   761,    23,  1110,    86,  1201,    68,
     595,     0,    99,    66,    91,    74,     0,   118,   114,   756,
    1774,   871,   587,   870,   595,   509,   595,   786,   787,   785,
       0,  1668,     0,     0,     0,  1507,  1508,  1506,   595,   595,
     595,   595,   595,   595,  1670,     0,  1049,  1652,  1653,  1649,
    1651,  1721,   595,  1774,   682,   667,   664,     0,   731,   705,
     733,   707,   723,   721,   727,   719,   742,    29,    27,   595,
    1675,   595,  1606,  1607,  1603,  1609,   595,  1396,   595,  1399,
       0,  1320,  1315,  1314,  1317,   595,  1644,   595,  1623,   595,
    1305,     0,   595,   595,  1292,   595,   595,  1332,  1328,   595,
    1387,   595,     0,  1615,  1613,   548,   546,   558,   560,   556,
       0,     0,   224,  1169,  1170,  1171,  1173,  1156,  1154,  1153,
    1157,  1158,  1155,  1172,  1159,  1160,  1144,   960,  1179,   957,
     595,     0,  1197,     0,  1142,  1141,  1136,  1134,  1133,  1137,
    1135,  1139,  1140,  1132,  1185,  1406,  1639,  1463,  1457,  1459,
    1467,  1672,  1480,  1672,  1478,  1486,  1485,   595,  1672,   595,
    1472,  1471,  1473,     0,  1469,  1470,  1488,  1487,     0,  1402,
    1408,   595,  1412,  1597,  1595,  1596,  1592,  1594,  1591,  1593,
    1521,     0,  1523,     0,     0,     0,     0,  1529,  1533,     0,
    1513,  1422,   999,  1234,  1227,  1224,   595,  1439,  1440,  1442,
    1445,  1452,   595,     0,  1505,  1631,  1625,   485,   483,   487,
     480,  1583,   506,   507,   433,   595,    23,     0,   595,   991,
     595,    48,   971,     0,    23,   160,   150,     0,   599,   601,
     162,   152,   750,     0,   334,   595,   595,   517,   763,  1032,
     595,    81,     0,    64,     0,    77,    86,    70,   862,   859,
     513,  1774,     0,  1565,     0,     0,     0,  1669,     0,   595,
       0,     0,     0,     0,   595,  1666,     0,   685,   662,   668,
     587,  1684,     0,  1682,  1635,  1609,  1609,  1602,  1398,  1639,
    1400,  1394,   595,  1319,     0,  1694,  1636,     0,   595,  1310,
    1300,  1307,  1311,  1309,   595,     0,  1294,  1295,  1302,  1304,
     595,  1389,  1392,  1376,  1390,  1393,   595,   832,   831,   318,
     202,   962,   961,   959,   595,  1178,  1064,  1068,  1070,   595,
    1074,   595,  1072,  1076,  1065,  1066,     0,   853,     0,   595,
       0,  1673,  1481,     0,     0,     0,  1475,  1466,     0,  1547,
    1551,  1546,     0,  1540,  1532,  1516,  1514,     0,  1517,   595,
    1443,   595,  1552,  1446,   595,  1453,  1454,  1634,  1226,   595,
     595,   595,   344,   341,   595,   989,     0,     0,     0,   970,
     751,   138,   598,    23,   980,   952,   950,  1037,    87,  1202,
      82,     0,    75,    86,  1774,   510,   930,     0,     0,     0,
    1665,     0,  1661,  1662,  1663,  1664,  1671,   687,   743,   595,
    1681,     0,  1608,  1604,   595,  1321,   595,  1629,     0,  1309,
     595,  1306,     0,  1333,   595,  1377,  1375,  1616,   958,  1774,
    1774,  1078,  1774,  1080,  1774,  1774,  1067,  1198,  1186,     0,
    1672,  1479,  1477,   595,  1672,  1490,     0,  1550,     0,  1530,
    1447,     0,  1441,  1435,  1436,  1648,   595,  1455,  1449,  1632,
    1351,  1347,  1348,  1353,  1352,  1630,  1226,   346,   990,  1757,
     595,   595,   595,   595,   595,   595,    53,     0,    52,     0,
      50,   595,   595,   139,  1041,  1033,     0,  1039,    86,    91,
      86,    71,   860,     0,     0,  1709,     0,  1667,  1774,    23,
    1683,  1629,     0,  1325,     0,  1322,  1324,  1624,  1299,  1308,
     595,  1391,  1069,  1071,  1774,  1075,  1774,  1073,  1077,     0,
    1482,  1489,  1474,  1476,  1548,  1525,   595,  1444,   595,  1434,
     595,  1355,  1354,  1350,  1633,   352,   350,   342,     0,   348,
     354,    55,    60,    57,    59,    56,    58,    54,     0,    49,
       0,   600,   602,  1774,  1038,  1040,  1203,    83,    78,   511,
    1707,  1708,   683,   744,  1628,  1637,   595,  1316,     0,  1079,
    1081,  1638,  1448,  1437,  1349,  1774,  1774,   347,   349,  1774,
      51,   595,  1042,     0,   688,  1323,  1297,   353,   351,   355,
       0,    84,   972,    88,    90,   595,    85,    89
};

/* YYDEFGOTO[NTERM-NUM]. */
static const short yydefgoto[] =
{
      -1,   548,   549,   550,   551,   700,  1701,  1702,   188,   264,
     189,  1121,  1122,  1587,  1921,  2948,  2454,  2455,  2847,  2949,
    2950,   552,   890,  2490,  2149,  2863,  1536,  2148,  2726,  2494,
    2861,  1527,  2140,  2959,  3053,  3063,  2721,  3066,  1709,  1710,
    1711,  1222,  1822,   553,  1232,   895,  1230,  1543,  1831,  1540,
    1829,  1834,  2153,  1231,  1828,  1544,  2152,   554,    16,    35,
      36,    37,    38,    39,   113,   557,   818,  1475,  1148,  1780,
    1784,  1785,  1781,  1782,  2464,  2468,  2126,  2118,  2117,  2119,
    2122,  1104,   558,    83,    84,    18,    60,   142,    96,   255,
      98,    99,   200,   277,   100,   101,   242,   228,   672,  2319,
     304,   654,  1647,   331,   332,   229,   286,   279,   281,   973,
     974,   146,   354,   147,   148,   292,   230,   231,  1461,   392,
     243,   246,   244,   245,   313,   369,   370,   372,   377,   657,
     247,   248,   322,   374,   196,    19,    80,   177,   178,   179,
     663,  2318,   180,   251,   240,   325,   326,   327,   328,  1488,
     559,   560,   561,   562,   775,  2937,  2696,  1123,  3007,  3008,
    3009,  3046,  3045,  3049,   563,   564,   565,   566,   751,  1105,
     856,  1190,  1191,  1158,   853,  1159,   753,   754,   755,   756,
     757,   758,   759,  1059,  1106,  2093,  1107,  1108,  1109,  1110,
    1111,  1112,  1113,   706,   760,  1442,  2097,  1387,  2065,   761,
    1413,  2085,  1412,  2084,  1416,  2088,  1414,  2086,  2068,  2072,
     762,   763,   764,   765,  1408,   567,  2731,  2963,  2505,   568,
     826,  1490,  2134,   114,   237,   364,  1316,   955,   956,   957,
    1313,  1314,  1634,  1635,  1636,  1979,  1980,  1317,  1318,  1630,
    1983,  1975,  1642,  1643,  1986,  1987,  2316,  2312,  2313,   569,
    1165,    85,  1456,  1457,  1796,   858,   808,   861,   683,   797,
     780,   819,  1882,    86,   684,  1002,  1693,    41,   127,  2121,
      87,   767,  2285,   570,   571,   910,   911,   572,   573,   574,
     575,   918,  2535,   939,  2748,   940,  1566,   941,  1879,   942,
    2198,   943,  1590,   576,  1562,  2197,  2533,  2532,  2968,   115,
      20,   577,  1139,  1462,  1463,  1580,  1263,  1581,  1582,  2204,
    2206,  1891,  1890,  1903,  1889,  1888,  2215,  2213,  1895,  1896,
    1899,  1900,  1885,  1887,   578,   579,   816,   580,  1259,   925,
    2969,   581,  1198,  2704,  1583,  1892,  1837,  2155,   849,  1175,
    1510,  1805,  2135,  1806,  1171,  1509,   582,   583,   904,  1558,
    2509,   584,   585,   586,   587,    21,    64,    22,    23,    24,
     116,   117,   588,   118,    25,   644,    26,   119,   120,   157,
     366,  1322,  1991,  2788,   121,   153,   297,   589,  2064,    27,
      28,    29,    30,    31,    59,    88,   122,   411,  1331,  1997,
     590,   899,  1841,  1547,  1839,  2864,  2500,  1548,  1838,  2158,
    2502,   591,   592,   593,   791,   792,  1234,   123,   238,   365,
     648,   649,   959,  1320,   594,   944,   945,   595,   822,  1271,
     946,   768,    90,    91,    92,    93,  1241,   183,   138,    94,
     135,   191,   192,  1242,  1243,  2165,  1244,   408,   409,   927,
     410,   928,  2480,  2481,  1245,  1246,  1119,  2608,  2609,  2793,
     689,   806,   807,   596,  1134,  2849,   597,  2476,   598,  1152,
    1153,  1154,  1481,  1479,   599,   600,  1761,  1791,   601,  1008,
    1371,   602,   850,   851,   603,   866,   604,  1931,   605,  2857,
     606,  1809,  2955,  2956,  2957,  3023,   855,   607,  1247,  1560,
    1871,  1872,   608,  1449,   705,  1020,   609,   610,  1999,  2612,
    2804,  2805,  2899,  2900,  2904,  2902,  2905,  2984,  2986,   611,
     612,  1236,  1552,   613,  1238,   874,   875,   876,  1214,   614,
     615,   616,  1522,  1206,   869,   199,   877,   878,   769,  2000,
    2360,  2361,  2344,   709,   710,  1995,  2345,  2348,   124,   152,
     358,   983,  1652,  2362,  2808,  1029,   617,   867,   125,   149,
     355,   980,  1650,  2349,  2806,  1996,   894,  2141,  2722,  2958,
    1209,   618,   619,   620,   621,   622,   778,  1759,   702,  1706,
    2675,   696,   697,  2061,  1350,   623,   624,   625,   992,   993,
     994,  1362,  1689,   995,  1686,  1359,   996,  1661,  1351,   997,
     998,   999,  1000,  1655,  1342,   626,   787,   770,   627,  1294,
    2574,  2289,  2290,  2291,  2292,  2293,  2571,  2770,  2771,  1295,
    1296,  1605,  2563,  2764,  2236,  2560,  2974,  2975,  1297,  1615,
    2297,  1965,  2578,  2780,  1801,  2133,  1966,  1298,  1299,  2685,
    2931,  2932,  2933,  3003,  1300,  1301,  1156,   628,   629,   952,
    1302,  1303,  2896,  1621,  1622,  1623,  1968,  2299,  2783,  2784,
    1304,  1941,  2230,  2761,  1352,  1353,  1338,  2021,  1653,  2022,
    1354,  2025,  1355,  2048,  1356,  2049,  2415,  1656,  1305,  1599,
    1600,  1938,  1306,  2927,  2835,  2923,  1944,  2429,  2677,  2678,
    2679,  2921,  2430,  1945,  2836,  2928,  2008,  2009,  2010,  2011,
    2012,  2013,  2643,  2644,  2645,  2915,  2815,  2992,  2014,  2810,
    2390,  2015,  2391,  2016,  2518,  1682,  1683,  1684,  2664,  1685,
    2412,  2406,  2824,  2023,  2785,  2393,  2294,  2833,  1873,   771,
    1874,  2171,  1048,  2069,  1735,  2038,  2660,    58,   630,   631,
    2555,  2756,  2223,  2755,  1626,  1973,  1974,  2227,  1932,  1307,
    1933,  2241,  2767,  1393,  1928,  1929,  2686,  2838,  2568,  2559,
    2017,  1613,  1952,  1953,  2924,  2018,  2525,  2812,   632,   633,
    1592,  1930,  2550,  2752,  2753,  1274,   634,   773,  1309,  1310,
    1608,  2238,  1311,  1312,  1949,  2193,  2514,   690,  1876,   692,
    1375,  1877,    62,    47,    78,    75,   636,   880,  1526,  1142,
    1200,   637,   859,   638,  2108,   639,  1700,   694,  1377,   640,
     641,    73,   359,   360,   361,   362,   363,   642
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -2593
static const short yypact[] =
{
     788,  1028, -2593,   636,   636,   636,   636,   636,   636,   636,
   -2593,   636, -2593,   306, -2593, -2593, -2593,  2115, -2593, -2593,
   -2593,   266, -2593,   788, -2593, -2593, -2593, -2593, -2593,  1569,
   -2593, -2593, -2593, -2593, -2593,   330,   315, -2593,   378, -2593,
   -2593,   355, -2593, -2593,  -141, -2593,  -172, -2593, -2593, -2593,
   -2593, -2593, -2593, -2593, -2593, -2593, -2593, -2593, -2593,  1392,
     292, -2593, -2593, -2593,  1227, -2593, -2593, -2593, -2593, -2593,
   -2593, -2593, -2593, -2593, -2593, -2593, -2593, -2593, -2593,  -141,
    -154, -2593, -2593,   460,  2115, -2593,   657, -2593, -2593, -2593,
   -2593,   473,    92, -2593, -2593, -2593,   769,   501, -2593, -2593,
   -2593,   809, -2593, -2593, -2593, -2593, -2593, -2593, -2593, -2593,
   -2593, -2593, -2593, -2593, -2593, -2593, -2593,  1227, -2593, -2593,
   -2593, -2593, -2593, -2593, -2593, -2593, -2593, -2593, -2593, -2593,
    6172,    92, -2593,   113,   164, -2593, -2593,   515, -2593,   299,
     923,   292,   464, -2593, -2593, -2593, -2593, -2593,  7499, -2593,
     569,   888, -2593,  2115, -2593, -2593, -2593, -2593, -2593, -2593,
     474,   920, -2593, -2593,   603, -2593,   607, -2593,   585, -2593,
   -2593,   643, -2593,   645, -2593, -2593, -2593, -2593, -2593, -2593,
   -2593, -2593, -2593,   664, -2593, -2593, -2593,   164,  1407,  1059,
   -2593,   144, -2593,   164, -2593, -2593,    74, -2593, -2593, -2593,
      61, -2593, -2593, -2593, -2593, -2593, -2593, -2593, -2593,   474,
   -2593,   920, -2593, -2593,   707, -2593,   713, -2593,   677, -2593,
   -2593,   719, -2593,   734, -2593, -2593, -2593, -2593, -2593, -2593,
   -2593, -2593,   743,  1140, -2593,   762, -2593,  2115,  2115,   781,
   -2593, -2593,   -85, -2593,   601,  1097, -2593,   612,  1163,  1194,
    1209, -2593,  1214,  1217,  1221, -2593,   654, -2593,   936, -2593,
   -2593, -2593, -2593, -2593,   164, -2593,   164,   820,   170, -2593,
   -2593, -2593,  1239, -2593,  1243, -2593, -2593, -2593, -2593, -2593,
     -85, -2593, -2593, -2593,  1251,  1257,   292,  1214,  1261,  1263,
     663, -2593,  1255, -2593,   939,   903, -2593,   978, -2593, -2593,
   -2593,   729, -2593, -2593,  1304, -2593,   927, -2593, -2593, -2593,
   -2593, -2593, -2593, -2593,  1163,   927, -2593, -2593, -2593, -2593,
   -2593, -2593,   933,   235,   242,   228, -2593,  5661, -2593, -2593,
   -2593,   938,  1336,   248,   980, -2593, -2593,  1407, -2593,   164,
   -2593, -2593, -2593,   749,  1331,  1123,   250,   268,   245,   958,
     275,  1021, -2593, -2593, -2593,  1029, -2593, -2593,  1029,  1024,
   -2593,  3290,   464,  4320,  2596,   293,  1029,  1370,   -64, -2593,
    1097,  1372, -2593, -2593, -2593, -2593,  1374, -2593,  1375, -2593,
    1376, -2593, -2593, -2593, -2593, -2593, -2593,  1214,  1383, -2593,
   -2593, -2593, -2593,   172,  1395,   -64,   989,  1396, -2593,  1397,
   -2593, -2593, -2593,  1413, -2593, -2593, -2593,   821,  1053,  1438,
   -2593,  1029,  1080, -2593, -2593, -2593, -2593, -2593, -2593, -2593,
   -2593,   114, -2593, -2593, -2593, -2593, -2593, -2593, -2593,    81,
   -2593, -2593, -2593, -2593, -2593, -2593, -2593, -2593, -2593, -2593,
   -2593, -2593, -2593,    57,    57,  6031, -2593, -2593, -2593, -2593,
   -2593, -2593, -2593, -2593, -2593, -2593, -2593, -2593, -2593, -2593,
   -2593, -2593, -2593,   864, -2593, -2593, -2593,  6031, -2593,   864,
   -2593,   864,  1018, -2593, -2593,   128, -2593, -2593,   128, -2593,
   -2593,   128, -2593, -2593, -2593, -2593, -2593, -2593, -2593, -2593,
   -2593,   864, -2593, -2593, -2593, -2593,  -127, -2593, -2593, -2593,
   -2593, -2593, -2593,   114, -2593, -2593, -2593, -2593, -2593,  2333,
     864,  6974, -2593,   812,   812, -2593, -2593, -2593,   137,   864,
     134,  6031,  6974, -2593,  1456,  6031, -2593,  -141, -2593,  6974,
   -2593,  6974,   864, -2593, -2593,  6974,  6974,    57, -2593, -2593,
   -2593,   812, -2593, -2593,   812, -2593, -2593,   119, -2593, -2593,
   -2593, -2593, -2593, -2593, -2593, -2593, -2593, -2593, -2593, -2593,
   -2593, -2593, -2593, -2593, -2593, -2593, -2593, -2593, -2593, -2593,
   -2593, -2593, -2593, -2593, -2593, -2593, -2593, -2593, -2593, -2593,
   -2593, -2593, -2593, -2593, -2593, -2593, -2593, -2593, -2593, -2593,
   -2593, -2593, -2593, -2593, -2593,    39, -2593, -2593, -2593, -2593,
   -2593, -2593, -2593, -2593, -2593, -2593, -2593, -2593, -2593, -2593,
   -2593, -2593, -2593, -2593, -2593, -2593, -2593, -2593, -2593, -2593,
   -2593, -2593, -2593, -2593, -2593, -2593, -2593, -2593, -2593, -2593,
   -2593, -2593, -2593, -2593,   994, -2593, -2593, -2593, -2593, -2593,
   -2593, -2593, -2593, -2593,   530, -2593, -2593, -2593,   314, -2593,
    1090, -2593, -2593, -2593,  1180, -2593, -2593,  1093,  1099,  1100,
    1101, -2593, -2593,   859,  1459,  1103, -2593, -2593,  1203, -2593,
    1105,  1120,   889,  1127, -2593, -2593, -2593,  1131, -2593,   349,
   -2593,   205, -2593, -2593, -2593, -2593,   906,  1479,  1074, -2593,
     917, -2593,   916, -2593,  1505,  -212,   281, -2593, -2593, -2593,
    1113, -2593,  1492, -2593, -2593,  1073,   116, -2593, -2593, -2593,
    1234, -2593,  6974,  6974, -2593, -2593,  1126,  1032,  1138,  1144,
    1147,  1148,  1150,  1153,  1166,  1173,  1174,  1175,  6974,  1270,
    1176,  1187,  1188, -2593,  6974,  6974,  1189,  1191, -2593,  6974,
    1193, -2593,  1196,  1200,  1201,  1202,  1207,  1215,  1223,  6974,
    1224,  5428, -2593,    67, -2593, -2593, -2593, -2593, -2593, -2593,
   -2593, -2593, -2593, -2593, -2593, -2593,   -65, -2593,  1141, -2593,
   -2593, -2593, -2593, -2593, -2593,   864, -2593, -2593,  1492, -2593,
     -58, -2593, -2593,  1287, -2593,   103, -2593,  1104, -2593, -2593,
   -2593, -2593,  1595, -2593, -2593,  -260, -2593,  1026, -2593,  1033,
    1595, -2593,  1060, -2593, -2593,  1236,   106, -2593,  1198, -2593,
    1002, -2593, -2593,  1232, -2593,  -178, -2593,  1005,   354,  -239,
   -2593,  1339,  6974,  6974, -2593,  1636, -2593, -2593, -2593, -2593,
   -2593, -2593,   243,   243,   243, -2593,   243, -2593,   243,   243,
    1075,   -58,  1075,  1075,   141,   141,  1075,  1075,   -58, -2593,
    1640, -2593,   -21,  1643, -2593,   -58, -2593,  5896, -2593,    64,
      54, -2593, -2593,  6974, -2593, -2593, -2593, -2593, -2593,   705,
   -2593, -2593,   464,  1292,   464,  6031, -2593,    65, -2593, -2593,
    6974,  1247,  1250,  1254,  1258,  1262,  1642,  1265,   134,  1200,
   -2593,  1354,   535,  1110, -2593,  1124, -2593, -2593, -2593,   147,
   -2593,  1668, -2593,  1666, -2593, -2593,    55,  1129, -2593, -2593,
    1680, -2593,  1052,  1680,  1684,  1057,  1680,  1684,  6974,  1680,
   -2593, -2593,   116,   864, -2593, -2593,  1300,   258, -2593, -2593,
    1294,   864,  6974,  1299, -2593, -2593,  1673,  1681,  1663, -2593,
   -2593, -2593, -2593, -2593, -2593, -2593, -2593,   150,   150, -2593,
   -2593, -2593,  2674, -2593, -2593,  1641,   530, -2593, -2593,   393,
   -2593, -2593, -2593,  1275, -2593, -2593, -2593, -2593,  6172,  1214,
   -2593,  1285, -2593,   288, -2593, -2593, -2593, -2593, -2593, -2593,
    2115, -2593, -2593,  2115,   790,  1316,  1698, -2593, -2593,   761,
    1321,  1023,  1728, -2593, -2593, -2593, -2593, -2593, -2593, -2593,
   -2593,  1334, -2593, -2593,  1479,   916,   164,   114,  -244,  1721,
   -2593, -2593, -2593, -2593, -2593,  1171,  1149,  1181,  1343, -2593,
    1344,    95, -2593, -2593, -2593,   972,   972,   812,  6974, -2593,
   -2593,   812,   812,   812,   812,  1305,  6974,  1079,  1133,  6974,
    5428,  1348, -2593, -2593, -2593, -2593, -2593, -2593, -2593,  1156,
     812,  1735,  6974,  4630,  5428,  1305,   -90,  5428,  1748,   396,
   -2593, -2593, -2593,  6974, -2593,  6974,  6974,  5428,  6974,  6974,
    6974,  6974,  6974,  6974,  6974,  6974,  6974,  6974,  6974,  6974,
    6974,  6974,  6974,  6974,  6974, -2593, -2593, -2593, -2593, -2593,
   -2593, -2593, -2593, -2593, -2593,  6974,  6974, -2593, -2593,  1363,
    6974, -2593,  6974,  1364, -2593, -2593, -2593, -2593, -2593, -2593,
   -2593, -2593, -2593, -2593, -2593, -2593, -2593,   864, -2593,  1169,
    1369, -2593, -2593, -2593,   114,   156, -2593,   156,   134,   128,
    6974,  6974,  6974,  1377, -2593, -2593,   864,   864, -2593,  1179,
     134,   812,  1154, -2593,   164,    48,  -127,   864, -2593,  1186,
    6974,  1462, -2593, -2593,  1259, -2593, -2593,  1643,    66, -2593,
     116, -2593, -2593,  1765,  1775, -2593, -2593, -2593, -2593, -2593,
   -2593,   876, -2593, -2593, -2593, -2593, -2593, -2593, -2593, -2593,
   -2593, -2593, -2593, -2593,  2333, -2593,   141,  6974,  -112, -2593,
   -2593,  1789, -2593,   812,  1774,  1777, -2593, -2593, -2593, -2593,
   -2593,   102, -2593, -2593, -2593, -2593,  1670, -2593,  1609, -2593,
   -2593, -2593,  6974,    57, -2593, -2593, -2593, -2593,  1780,   812,
     812, -2593,  1241, -2593,   812,  1208,   864, -2593, -2593,  6974,
    -104, -2593,  1269, -2593,   740, -2593,  1351, -2593,  1366,  6974,
     737, -2593, -2593,    92, -2593,  1807, -2593,  1306, -2593,   864,
   -2593, -2593, -2593, -2593,   812,   812,   178,   258,  1702,   850,
     864,   116, -2593,  1309, -2593, -2593,  1821,  1809,  1457, -2593,
   -2593, -2593, -2593, -2593,  1538,  1538,   220,  1317, -2593, -2593,
   -2593, -2593,  1492,  1492, -2593, -2593, -2593, -2593, -2593, -2593,
     547,  1492, -2593,   741, -2593, -2593, -2593, -2593, -2593, -2593,
   -2593, -2593, -2593, -2593, -2593, -2593, -2593, -2593,   930, -2593,
   -2593, -2593, -2593,   182,   182,    68,   593, -2593,   766, -2593,
     393, -2593,  2115,  1815, -2593, -2593,  1815, -2593, -2593, -2593,
   -2593,  2115, -2593, -2593,  1492, -2593,   844,  1439, -2593, -2593,
     844, -2593, -2593, -2593,  1440,  1441,    14,  1445,  1446,  2100,
   -2593, -2593, -2593, -2593, -2593, -2593, -2593, -2593, -2593, -2593,
      14,  1219, -2593,   349,  1830, -2593,  1267,   189, -2593,   134,
    1312, -2593, -2593,  1074, -2593, -2593, -2593,  1346, -2593, -2593,
   -2593, -2593, -2593, -2593, -2593,  1499,  5428,  6031,  1504,  1511,
    1512,   312,   547,  1513,  4661,  1515,   -88,  1516,   -77,  4762,
    1845,  1301,  1517,  1522,  5029, -2593,  1530,   382,  1531,  1880,
    1535, -2593,  6974,  6974,  6974,  5128,  6974,  5161,  5257,  5292,
    3861,  5527,  5658,  5699,  5794,  2829,  3022,  3045,  3614,  5763,
    1503,   972,   972,   239,  3717,  3293,  5428,  5428,  1305,  5428,
    5428,  1305,  6031, -2593, -2593, -2593,  1310, -2593, -2593, -2593,
   -2593,  1302, -2593,  1900,  1903, -2593,  1904,  1355,  6974, -2593,
   -2593,  1322,  1915, -2593,  1463,  1323,  1684, -2593,  1556,   373,
   -2593,  1520, -2593, -2593,  1326,  1205, -2593, -2593, -2593,  1523,
   -2593,   653,  6974, -2593, -2593, -2593,  6974,  -248,   -58,  1927,
    1404,  1912,  1914, -2593, -2593, -2593, -2593, -2593, -2593, -2593,
   -2593, -2593, -2593, -2593, -2593, -2593, -2593, -2593, -2593, -2593,
    1536, -2593, -2593, -2593,   864,  1432,  6293, -2593, -2593, -2593,
    1902,  6974,   464,   142, -2593, -2593,  1651,  6031,  1589,  1961,
    1601,   313, -2593,  1603,   134, -2593,  6031,  1565, -2593, -2593,
    1637, -2593,  6974,   -93, -2593,  1400, -2593, -2593,   168, -2593,
    6974, -2593, -2593,  1385,   113, -2593,  1378, -2593,  1964,  7115,
   -2593, -2593,   136, -2593,  1684,  1684,  1342, -2593,  1464,  1466,
     812,   812, -2593, -2593, -2593, -2593, -2593, -2593,   461,   510,
   -2593,   558, -2593, -2593, -2593, -2593,   812,  2843,  1987,  1968,
   -2593,   134,  1770,    63,  1554,  1924,    52,   160, -2593,    16,
   -2593, -2593, -2593,  1598,    76,  1492,   124, -2593,  1412,  1409,
   -2593, -2593, -2593,  7250,  1450,  1717, -2593, -2593, -2593, -2593,
    1606,  1416,  2013, -2593,  1997, -2593, -2593, -2593, -2593,   864,
     173, -2593, -2593, -2593,  1408,   593, -2593, -2593, -2593, -2593,
   -2593, -2593,   703, -2593, -2593, -2593, -2593,  1622,  1624, -2593,
    1592, -2593,  1593, -2593,  1626,   356, -2593,  5972,   403,  1492,
    1492,   416, -2593,  1492,  5972, -2593, -2593,  1518,  1518, -2593,
    1627, -2593,  1646,  1647, -2593,  1649,  1650, -2593,  1653, -2593,
   -2593, -2593,   577, -2593, -2593, -2593,   435, -2593, -2593,   436,
   -2593, -2593, -2593,  1675,    92,  1721, -2593,  2037,   134,  6974,
   -2593,  2042, -2593, -2593, -2593, -2593,    14, -2593, -2593, -2593,
    2044, -2593,  5428, -2593, -2593, -2593, -2593,  7250, -2593, -2593,
    1270,  1270,  2032,  1270,  1270,  2038,  1032,  1704,  1659, -2593,
   -2593, -2593, -2593, -2593, -2593, -2593, -2593,  1032, -2593, -2593,
    1270,  1471, -2593,  1270,  1032,  5428,  5428,  5428,  1032,  5428,
    1032,  1032,  1032,  6974,  1707,  6974,  1710, -2593,  1482,    14,
     130, -2593,   134,  6974,  6974,  6974,  6476,  2074,   966, -2593,
   -2593,   134, -2593,  1484, -2593, -2593, -2593, -2593, -2593, -2593,
   -2593,  1102, -2593, -2593,   279, -2593,  1485,  6974, -2593, -2593,
   -2593,  2075, -2593, -2593, -2593, -2593, -2593, -2593,  1684, -2593,
   -2593, -2593, -2593, -2593, -2593, -2593, -2593, -2593, -2593,   864,
   -2593, -2593,  3747, -2593, -2593, -2593,  1785, -2593, -2593, -2593,
    1767,  1769,  1656,  1496,  1776,  1688, -2593, -2593,   -37,  1759,
   -2593, -2593, -2593, -2593,  1637, -2593, -2593, -2593,    93,   786,
   -2593, -2593, -2593,  1821,  6974,  1705,  2083, -2593, -2593,    90,
     123, -2593,   906, -2593, -2593,  1518, -2593, -2593,  7250,  1699,
   -2593, -2593,  1708, -2593, -2593,  1711,  1712,  1713,  1715,   506,
   -2593,  2108, -2593, -2593, -2593,  2217,  1726, -2593,   132,  1497,
   -2593,  2112,   -58, -2593, -2593,  2135, -2593,  2137,  1260,  1260,
    1260,  1260,  1536, -2593, -2593,  2143, -2593, -2593, -2593,  2156,
   -2593, -2593, -2593,  1260,    99, -2593, -2593, -2593, -2593, -2593,
   -2593, -2593, -2593, -2593, -2593, -2593, -2593, -2593, -2593, -2593,
   -2593,   446, -2593,  2138, -2593, -2593,  1492, -2593, -2593, -2593,
   -2593, -2593, -2593, -2593,  1594,  1597,    22, -2593,    16, -2593,
    1492,  1573, -2593,  5972, -2593, -2593,  1756, -2593, -2593, -2593,
   -2593, -2593,  2165, -2593,  3756,   201, -2593,  6974, -2593,  6974,
   -2593, -2593, -2593, -2593, -2593, -2593, -2593,  1492, -2593,  1492,
     -51,  1575,  1577,  2169, -2593,  2170, -2593,   864, -2593,   491,
     491, -2593, -2593,  2171, -2593,  2171,   945,   945,  2171, -2593,
   -2593,  2596, -2593, -2593,  6192,    88, -2593,  2596,  2023, -2593,
      88,  1492,   844, -2593,  1781,  2204,  1781,  6195,   233,  2179,
   -2593, -2593, -2593, -2593, -2593, -2593, -2593,   433,   776, -2593,
    -159,  1823,  2183, -2593, -2593,   448, -2593,    14, -2593,   449,
     237, -2593, -2593, -2593, -2593, -2593, -2593, -2593,  1596,    28,
    2168,  2168,  2175,  2168,  2168,  2177, -2593,   110, -2593,   844,
   -2593, -2593,    14, -2593, -2593, -2593,  1599,   134,  2196, -2593,
   -2593,   452, -2593,  6712,  1840,  1841,  6974,   174, -2593,  1618,
   -2593,  1858, -2593,  1628, -2593,  1864, -2593, -2593,  2207, -2593,
    1648,  1301,  1654, -2593,  1872,  1876,  1877, -2593,  1878, -2593,
   -2593, -2593,  5428,   455, -2593,   457, -2593,  1881,  2229,   465,
     134,  2247, -2593, -2593, -2593, -2593,  6974,  1718,  2003,  6974,
   -2593, -2593, -2593, -2593,  2245,  1895,   279,  1296,  1296,  2261,
    -173, -2593,  2262, -2593, -2593, -2593,  1296, -2593,  1747,  2250,
    2266, -2593,  -136,   864,  2056,   466, -2593,  1464,  6974, -2593,
    1906,  6031,   864, -2593,    81, -2593,   864, -2593,  1907,  6031,
   -2593, -2593,   -37,  1759, -2593,  1536, -2593, -2593,   140, -2593,
   -2593,  1729, -2593, -2593,  1846, -2593,  6895, -2593, -2593, -2593,
   -2593, -2593,  1676,  1134,   169,   576,  1869,   576,   576,   576,
     576,  7250,  7115,  7250,  7250,  7250,  7250, -2593, -2593, -2593,
   -2593, -2593, -2593, -2593,   114, -2593, -2593,  1866,   674, -2593,
   -2593, -2593,  1687,   812,  1260,   812,  1260, -2593, -2593, -2593,
   -2593, -2593,   461,  1260,   510,  1260, -2593,   -58,  2843, -2593,
    1917,  1879,   547,   930,  1554,  1554, -2593, -2593, -2593, -2593,
     467, -2593,  1847, -2593,  2287,  1492,  -119, -2593,  1697, -2593,
    7250,  1778, -2593, -2593, -2593, -2593, -2593, -2593, -2593, -2593,
   -2593, -2593, -2593, -2593, -2593, -2593, -2593, -2593, -2593, -2593,
   -2593, -2593, -2593, -2593, -2593, -2593, -2593, -2593, -2593, -2593,
   -2593, -2593, -2593, -2593, -2593, -2593, -2593, -2593, -2593, -2593,
   -2593, -2593, -2593, -2593, -2593, -2593, -2593,  2292,  1492,    83,
   -2593,  2301,  2297, -2593, -2593, -2593, -2593,  1784, -2593,   468,
   -2593,  1720, -2593, -2593, -2593,  1997,   864, -2593,  2171, -2593,
   -2593, -2593,   945,   945, -2593, -2593,   945,  2128,  1719,  1724,
   -2593, -2593,    57,    57,    57,  2291,    57,    57,    57,    57,
      57,    57,  2293, -2593,  2307,    57, -2593, -2593, -2593, -2593,
   -2593, -2593, -2593, -2593,  6192, -2593,   864,  1730, -2593,  1910,
    2128,  2311, -2593,  2313,  2318,  2319,  2323,  2324,  2325,   161,
    2023, -2593,  1910, -2593,   469, -2593,  1905, -2593, -2593,   411,
    1802, -2593, -2593,  5972, -2593,  5972, -2593, -2593, -2593, -2593,
   -2593, -2593, -2593, -2593, -2593, -2593,  7250,  1948, -2593,  1950,
     602,  5566,  2332, -2593,  2086,  1492,  1764,  1492, -2593, -2593,
   -2593, -2593,  1639,  2338,  1639, -2593,  2359,  2359,   470,  1998,
    2359, -2593,  2000, -2593, -2593, -2593,   844, -2593, -2593, -2593,
     134, -2593,    14,  2124,  1821, -2593, -2593, -2593,   146,  1868,
     533,  1301,  1270,  1301,  1270,  2005,  1301, -2593,  1301, -2593,
   -2593, -2593, -2593,  6974, -2593, -2593, -2593,  1932, -2593,   183,
     134, -2593,  2372,  1973, -2593, -2593,  2014, -2593, -2593, -2593,
    1856, -2593, -2593, -2593,  1296,   164,  2365, -2593,  1296, -2593,
   -2593,   812, -2593, -2593,  6974, -2593, -2593, -2593,   812,  1991,
    2383, -2593,  2174, -2593, -2593,   -58,  5428,  2071, -2593, -2593,
     116,  1990, -2593, -2593,  6031, -2593,  2027, -2593, -2593, -2593,
     786, -2593,  1464, -2593,  6974, -2593,   164, -2593,  1643, -2593,
    1639, -2593,   837,  2391,  2030, -2593, -2593, -2593,  7250, -2593,
    7250,  7250,  7250,  7250,  2217,   478, -2593,  2585,  2585,  1360,
    1888, -2593,  6974,  1983, -2593,  2082, -2593,  2384, -2593, -2593,
   -2593, -2593, -2593, -2593, -2593, -2593, -2593, -2593, -2593, -2593,
   -2593,  7250, -2593, -2593, -2593,   930,  1492, -2593, -2593,  2286,
     485, -2593, -2593, -2593, -2593, -2593, -2593,   864, -2593,  7129,
   -2593,   486, -2593,  5972, -2593,  1492,  7157, -2593, -2593,  1492,
   -2593,  1969,  1812, -2593, -2593, -2593, -2593, -2593, -2593, -2593,
    2224,  6172, -2593, -2593, -2593, -2593, -2593, -2593, -2593, -2593,
   -2593, -2593, -2593, -2593, -2593, -2593, -2593,  -175,  2406, -2593,
     864,  2242, -2593,  2224, -2593, -2593, -2593, -2593, -2593, -2593,
   -2593, -2593, -2593, -2593, -2593, -2593,   547, -2593,  2179, -2593,
    2217,   247, -2593,   247, -2593, -2593, -2593,  7250,   110,  7194,
   -2593, -2593, -2593,  1781, -2593, -2593, -2593,  2217,   194, -2593,
   -2593,  2393, -2593, -2593, -2593, -2593, -2593, -2593, -2593, -2593,
   -2593,  2047, -2593,  2390,  2049,  2051,  2396, -2593, -2593,  2055,
   -2593, -2593, -2593, -2593, -2593, -2593,   129,  2423, -2593, -2593,
    2405,  2088, -2593,  1842,   576,  2131, -2593, -2593, -2593, -2593,
   -2593, -2593, -2593, -2593,  5428,   812,   -58,  2091,   134, -2593,
    6974, -2593,  1899,  2424,   -58, -2593, -2593,   380, -2593, -2593,
   -2593, -2593,   157,  2084,  1684,   864,   864, -2593, -2593, -2593,
     116, -2593,  2085,  1927,  2048, -2593,  2071, -2593, -2593, -2593,
   -2593,  2233,   197, -2593,  1518,  1851,  1518, -2593,  1544,  7250,
    1664,  1966,  2080,  2139,  7250, -2593,  1909, -2593, -2593, -2593,
    1464, -2593,   487, -2593,   118,   930,   930, -2593, -2593,   547,
   -2593, -2593,  1492, -2593,  2050, -2593,  2383,  1936,  6560, -2593,
    2454, -2593, -2593,  2217,  1492,  2450, -2593,  2287, -2593, -2593,
     864, -2593, -2593,   252, -2593, -2593, -2593, -2593, -2593, -2593,
   -2593, -2593, -2593, -2593,   864,  2406, -2593, -2593, -2593,   864,
   -2593,   864, -2593, -2593,  1916, -2593,  2251, -2593,  2252,  7250,
     495, -2593, -2593,   497,  2918,  2053, -2593, -2593,  2443, -2593,
   -2593,  2041,  1875, -2593, -2593, -2593, -2593,  2111, -2593,   146,
   -2593,   146, -2593, -2593,  7250, -2593,  2057, -2593,  2124,  1289,
      63, -2593, -2593, -2593,   134, -2593,  2113,  7492,  2076, -2593,
   -2593, -2593,  1889,   -58, -2593, -2593, -2593,   592,  1927, -2593,
   -2593,  2117, -2593,  2071,   786, -2593, -2593,  1885,  1639,  1886,
   -2593,   498, -2593, -2593, -2593, -2593,  2217, -2593, -2593, -2593,
   -2593,  1936, -2593, -2593,  7250, -2593,  7309,   533,   500,  1134,
    7157, -2593,  2087,  2383,  1969, -2593, -2593, -2593, -2593,  1633,
    1633, -2593,  1633, -2593,  1633,  1633, -2593, -2593, -2593,   174,
     110, -2593, -2593,  7250,   110, -2593,  2089, -2593,  1639, -2593,
   -2593,   502, -2593,  2484, -2593,  2217,  5972, -2593, -2593, -2593,
   -2593,  2489, -2593,  -148, -2593, -2593,  2124,  1142, -2593, -2593,
     243,   243,   243,   243,   243,   243, -2593,  2471, -2593,   509,
   -2593,  6974,  2477, -2593, -2593, -2593,   647, -2593,  2071,  6031,
    2071, -2593, -2593,  2281,  1639, -2593,  1639, -2593,   136,   -58,
   -2593,   533,   174, -2593,   513, -2593,  2217, -2593, -2593, -2593,
    7157, -2593, -2593, -2593,  1633, -2593,  1633, -2593, -2593,  2133,
   -2593,  2217, -2593, -2593, -2593, -2593,   146, -2593,  7250,  2287,
    1289, -2593, -2593, -2593, -2593, -2593, -2593, -2593,   730, -2593,
   -2593, -2593, -2593, -2593, -2593, -2593, -2593, -2593,  7492, -2593,
    2496, -2593, -2593,   756, -2593, -2593, -2593, -2593, -2593, -2593,
   -2593, -2593,   132, -2593, -2593, -2593,  7309, -2593,   523, -2593,
   -2593, -2593, -2593, -2593, -2593,  1122,  1122, -2593, -2593,  1122,
   -2593,  6974, -2593,  2136, -2593, -2593, -2593, -2593, -2593, -2593,
    2140, -2593, -2593,   112, -2593,   116, -2593,  1927
};

/* YYPGOTO[NTERM-NUM].  */
static const short yypgoto[] =
{
   -2593, -2593, -2593, -2593, -2593,   361, -2593,   451,  -186, -2593,
   -2593,  -843,  -238, -2593, -2593, -1520, -2593, -2593, -2593, -2593,
    -510, -2593, -2593, -2593, -2593, -2593, -2593, -2593, -2593, -2593,
   -2593, -2593, -2593, -2593, -2593, -2593, -1920, -2593, -1407, -2593,
     443, -2593, -2593, -2593, -2593, -2593, -2593, -2593,   676, -2593,
   -2593, -2593, -2593,  1293, -2593,   974, -2593, -2593,   -57, -2593,
   -2593,  2479, -2593,  2486,  2162, -2593, -2593, -2593, -2593, -2593,
     751,   400, -2593,   748, -2593, -2593, -2593, -2593, -2593, -2593,
   -2593, -2593, -2593,  -106,   362,   270, -2593, -2593,  2248,    15,
   -2593,  2394, -2593, -2593,  2386, -2593,  2327, -2593, -2593, -2593,
    2257,  2145,  1216,  2256,  -311, -2593, -2593, -2593, -2593, -2593,
    1218,  -964, -2593, -2593, -2593, -2593, -2593, -2593,  -144,  2192,
    2335,  2339, -2593, -2593,  2180, -2593, -2593,  2237, -2593, -2593,
   -2593, -2593,  2239, -2593, -2593, -2593, -2593,  -323, -2593, -2593,
   -2593, -2593, -2593, -2593, -2593, -2593,  2173, -2593,  2172, -2593,
   -2593, -2593, -2593, -2593, -2593, -2593, -2593,  -848, -2593, -2593,
    -451, -2593, -2593, -2593, -2593, -2593, -2593, -2593,  -515, -2593,
   -2593,  1042, -2593,  -888,  -807,   232, -2593, -2593, -2593, -2593,
   -2593, -2593, -2593, -2593, -2593,   804, -2593, -2593, -2593, -2593,
   -2593, -2593, -2593,  -479, -2593, -2593, -2593, -2593, -2593,  2036,
   -2593, -2593, -2593, -2593, -2593, -2593, -2593, -2593, -1676, -1670,
   -2593, -2593, -2593, -2593, -2593, -2593, -2593, -2593, -2593, -2593,
   -2593, -2593, -2593, -2593, -2593, -2593, -2593, -2593, -2593,  1605,
   -2593, -2593, -2593, -2593,   929, -2593, -2593, -2593, -2593, -2593,
   -1429, -2593, -2593,   924, -2593, -2593, -2593, -2593, -2593, -2593,
    -810,  -639,   797,  1083, -2593,  -438,   450,  -792,  1226, -2593,
    -195, -2593, -1799,    -2,  -210, -2593, -2593,  1844,  1563, -1717,
    -105,   683, -2593, -2593, -2593,   431,  1319, -2593, -2593, -2593,
   -2593, -2593, -2593,   372, -2593,    41, -2593,  1324, -2593,  1015,
   -2593,   704, -2593, -2593, -2593,  -450, -2593, -2593, -2593, -2593,
   -2593, -2593, -2593, -2593,   815, -2593, -1194, -2593,  1004, -2593,
   -2593, -2593, -2593, -2593, -2593, -2593, -2593, -2593, -2593,   374,
   -2593,   375, -2593, -2593, -2593, -2593,  1448, -2593, -2593, -2593,
   -2593, -2593, -2593,  -125, -1459, -2593, -2593, -2593, -2593,   389,
   -2593, -1666, -2593,  -834, -2593, -2593, -2593, -2593, -2593, -2593,
   -2593, -2593, -2593, -2593, -2593, -2593, -2593, -2593, -2593,  2568,
   -2593, -2593, -2593,  2475,  2566, -1693, -2593, -2593, -2593, -2593,
   -2593, -2593, -2593,   -17, -2593, -2593, -2593, -2593, -2593, -2593,
   -2593, -2593,  2569, -2593, -2593, -2593, -2593, -2593, -2593, -2593,
   -2593, -2593, -2593,  1051, -2593, -2593, -2593, -2593, -2593, -2593,
   -2593, -2593, -2593, -2593,  -412,  2120, -2593, -2593, -2593, -2593,
   -2593,  1955, -2593, -2593, -2593, -2593, -2593, -2593, -2593, -2593,
   -2593,  1591, -2593, -2593,   -62, -2593, -2593,  1055, -2593, -2593,
    1379,  -188,  2340, -2593, -2593, -2593, -2593,   -35, -2593,  -704,
    1938,  1356, -2322,  -101, -2593,  1063,  1693,    11,  -170, -2593,
    -944, -2593,  1490, -2593, -2593, -2593, -2593, -2593, -2593, -2593,
   -2593, -2593, -2593, -2593, -2593, -2593, -2593, -2593, -2593, -2593,
   -2593, -2593, -2593,  1444, -2593,  1034, -2593,  -362, -2593, -2593,
   -2593, -2593, -2593, -2593,  -327, -2593, -2593, -2593, -2593, -2593,
   -2593,   454, -2593,  1506,   476, -2593, -2593, -2593, -2593,   272,
   -2593,  -174, -2593, -2593, -2593, -2593, -2593, -2593, -2593, -2593,
   -2593, -2593, -2593, -2593, -2593, -2593, -2593,  1757, -2593, -2593,
   -2593, -2593, -2593, -2593, -2593,  -301, -2593,  1427,  1581, -2593,
   -2593,   282, -2593,  -436, -2593, -2593,   300,   648, -2593, -2593,
   -2593, -2593, -2593, -2593, -2593,  -477, -2593, -2593, -2593, -2593,
   -2593, -2593, -2593, -2593, -2593, -2593, -2593, -2593, -2593, -2593,
   -2593, -2593, -2593, -2593, -2593, -2593, -2593, -2593, -2593, -2593,
   -2571, -2593,  1632,   893,  -934, -2593, -2593, -2593, -2593,  1290,
   -2593, -1307, -2593, -2593, -2593, -1314, -2593, -2593, -1300, -2593,
   -2593, -2593, -2593,  1325, -2593, -2593, -2593, -2593, -2593, -2593,
   -2593, -2593, -2593, -2593, -2152,    86, -2593, -2449, -2375, -2593,
     726, -2593, -2593, -2593, -2593, -2593, -2593,  -373, -2593, -2593,
   -2593, -2593, -2593, -2593, -2593, -2593, -2593, -2593, -2593, -2593,
   -2593,  -334, -2593, -2593, -2593, -2593, -2593, -2593, -2593, -2593,
   -2593, -2593, -2593, -2593, -2593,   697, -2593, -2593, -2593,  -226,
   -2593, -2593, -2593, -2593, -2593, -2593,   277, -2593, -2593,   668,
   -2593,  1009, -2593, -2593, -2593, -2593,   257,  -966, -2593, -2593,
   -2593, -2593, -1412, -2593, -2593, -2593, -2593, -2593, -2593, -1908,
      -1, -2593, -1962,   253, -2593, -2593, -1628,   304,   309,   672,
   -2593, -2593, -2593, -2593, -2593, -2593, -2593, -2593, -2593,    53,
   -2593, -2593,   670, -2593, -1963, -2593, -2593, -2593, -1734, -2593,
   -2593, -1115, -2593,  -685,  1402,  -132, -1538, -2593, -2007, -2593,
   -2593, -2593, -2593,  -638, -1255, -1619, -2058, -2593, -2593, -2593,
   -2593, -2593, -2593, -2593, -2128, -2593,   386, -2593, -1740, -2593,
    1733, -2593, -2593,  -827,  -146, -2593, -2592,  -149,   -59,   471,
   -1956, -1378, -1695,   462,  -297,   638,   -36, -2434, -2593, -2593,
    1430,  -499, -2593, -2593,  -169,  1763, -2593,   718, -2593, -2593,
   -1238,   148, -2593, -2593, -2593, -2593, -2593,  -431,  -415,  -496,
    1017, -2593,     9,  1908,   107, -2593, -2593, -2593, -2593, -2593,
    1572, -2593,  -489, -2593, -2593, -2593, -2593, -2593, -2593, -2593,
   -2593,  -662,  1092,  2354, -2593, -2593, -2593, -2593
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1771
static const short yytable[] =
{
      40,   258,  1021,  1170,   385,   268,   691,   112,   711,    32,
      55,    57,  1188,  1329,  1717,  1157,  1783,  1018,  1339,  1003,
     131,   872,  2067,  1167,  1168,   860,  1169,   823,  1172,  1173,
    1256,   256,    32,   857,  1161,  1757,  2030,   863,    68,  2157,
    2414,    74,    77,  1687,  1266,  2070,  1662,   236,  2367,  2039,
    2371,  1609,   914,  1688,  2074,   917,  1201,  1361,   814,  1193,
     112,   415,  2123,  1568,  1569,  1374,   796,  1922,  1470,  1193,
    1212,  1482,   821,   126,   128,    97,   664,    77,   337,   274,
     269,   290,   707,   929,   269,   275,   276,   870,   691,   137,
     269,  1049,  1114,  1120,  -595,  2552,   144,   269,   270,   271,
    1261,   908,   150,   151,  1193,  2217,   699,  1187,   154,   155,
     140,  1137,  1483,   269,  1484,  2167,  1485,  2156,  1194,  -595,
    1817,  2024,  2026,  2240,  1195,  2026,   126,  1849,  1850,  1826,
    1935,   298,   299,   269,  2413,  1853,  2570,   181,   686,   269,
     920,   921,   269,   920,   921,   825,   269,   232,  2169,   266,
     235,   393,   789,  1016,   870,   239,    97,  1276,   870,  1278,
     201,   864,  1193,  -595,  2501,    81,  -595,  1814,  1125,  1126,
    1016,  1233,  2195,  1384,  1272,   266, -1769,   266,  1977,  2240,
    1447,   184,   185,  1482,   864,  2621,   129,  1939,  2697,   186,
    1545,  1005,   930,  1016,   266,  1248,  2228,  1025,  1026,  2818,
    2346,  2779,   266,  1942,  2816,  1179,  1180,   680,  1514,  1985,
    2572,  1539,  1988,  1040,  2520,  2521,  2522,  2523,  1257,  1053,
    1054,  2287,  1833,   811,  1057,  1016,  2211,  1282,  1406,  2477,
    2111,    72,   295,   382,  1067,  1344,  2172,  1797,   301,  2373,
     378,   772,   291,  2373,   772,  2766,  1284,   380,  1345,   329,
     141, -1769,  3064,   388,   781,   397,  1144,  2894,   772,  1083,
    1084,  2465,   772,  1261,  1849,  1850,    63,  2929,  1162,   798,
     269,  2413,  1853,   399,   772,  2392,   781,  1947, -1769,  1721,
     403,  1407,   809,  1150,  2127,   781,  1013,    61,  1185,   930,
    1724,   804,   820,  1327,   343,  2977,   345,   824,  2317, -1769,
     810,    97,  1011,   652,  2350,   862,   555,   643,  1369,  1085,
    1086,  1087,  1088,  1089,  1090,  2234,   809,  1193,  1193,  2888,
     809,   302,  1783,   412,   809,  1091,  1092,  1093,  2558,   781,
      56,   650,   781,  1594,  1595,  1130,  2562,   653,  2485,  2791,
    1186,  1116,  1131,    34,   912,   930,  2662,   915,   303,  1370,
     391,  1012,   930,   407,    61,  1151,   407,   938,  1520,   931,
      69,  2002,    17,  1617,   407,  3004,  3001,   391,   133,   134,
    2895,  1948,   635,   645,  1618,  1249,   677,  2369,  1546,  3034,
     329,    72,   329,   984,   985,    17,  1262,  1740,  2792,  1225,
     259,   260,   261,   262,   263,   813,  1619,   259,   260,   261,
     262,   263,  2231,  1620,   932,    33,  1381,  1262,  2002,   407,
     812,   986,   987,   988,   679,  3002,   682,  2373,  1145,   688,
     693,  2027,   695,  2466,    76,   698,  1361,  2757,  1629,  2300,
      79,  2632,  3065,  2634,  2403,  2646,   704, -1543,   717,   130,
    2050,  2052,  2376,   766,  2377,  2378,  2379,  2380,  2381,  2382,
    1229,  2218,  2733,  2397,  2397,   704,  1489,  2422,  2893,  1515,
    2443,  1542,  2443,  2024,  1094,   766,  1347,  1095,   704,  1290,
    2422,  2483,  2556,  2579,  2395,  2666,  2990,  1722,   799,   922,
    2993,  1855,  1348,  2744,  2553,  2554,   933,   383,  1725,  2499,
    2762,  2774,  2879,   136,   815,   817,  1856,  1293,    82,  2478,
    2910,   688,  2910,  2744,   401,  2890,  1840,  2996,  1366,   766,
    1927,   815,   815,  1386,  3018,  2979,   813, -1769,  3036,   766,
     766,  1394,   892,   766,  1399,    77,  2229,   766,  2890,   766,
    1001,  3038,  2698,   766,   766,  2829,   909,  1404,   909,   815,
    2512,   909,   815,   932,   909,  1391,   267,  1512,  1415,  2308,
    1417,  1418, -1769,  1419,  1420,  1421,  1422,  1423,  1424,  1425,
    1426,  1427,  1428,  1429,  1430,  1431,  1432,  1433,  1434,  1435,
     187,  1207,   340,  1210,   666,  1250,  1368,  1943,  2347,  1196,
    1436,  1437,   923,   933,  2573,  1439,  1096,  1440,  1277,  1385,
    2128,  1696,   691,  1388,  1389,  1390,  2819,  1603,  1604,  2866,
    2374,  1097,   379,  1176,  2401,  1098,  1614,  2288,  1251,   381,
    1183,  1754,  1402,  2772,  1756,   389,   862,   398,  1855,  1881,
    2772,    95,  2891,  1936,  2811,  1881,  2811,  2882,  2883,  1451,
    2404,  2811,  1596,  1856,   898,   400,  2513,  2676,  1138,   933,
    1799,  1465,   404,  1099,   958,  1324,   933,  2567,  1014,  1654,
    2196,    82,  1466,   272, -1769,  1328,    82,   272,  1325,  1213,
    1486,  2383,  1843,   272,   934,   935,   936,  1197,  1487,    82,
     272,  1100,   979,  2665,   407,   937,  2669,   752,   132,  1716,
    1821,    82,  2100,  2703,   972,   688,   272,  2817,  -595,   790,
    1101,  1471,  1199,  1446,  2368,  1978,  2428,  2561,  2547,   782,
    1017,    82,   687,  2729,    82,  1127,   272,    82,   814,   691,
     766,   766,   272,  2239,  1147,   272,    82,  1452,    82,   272,
    1163,  2840,    82,  2003,  1041,    82,   766,  2399,    82,    82,
      82,  1531,   766,   766,  2488,    82,  2417,   766,    82,   862,
     824,   862,  2496,   854,    82,  2418,  2705,   766,    82,    82,
    2710,  1374,    82,   873,   879,  1517,  2688,   896,  1550,   727,
    2046,   900,  1545,   902,  2690,  1564,  1565,   906,   907,  1741,
    2019,  1102,  2062,  1164,   141,  1773,  1017,  1525,  2627,   989,
    2384,  1530,  2852,  2028,   731,  2376,  1533,  2377,  2378,  2379,
    2380,  2381,  2382,  2183,  2184,  2185,  2186, -1769, -1769, -1769,
   -1769, -1769,  2051,  2053,  1570,  2887,  2862,  1571, -1769,  1572,
    2965,  1042,  2772,  2219,   145,  2398,  2400,     1,  1367,  2423,
     766,   766,  2444,  1964,  2445,  2062,  2437,  2635,  1043,  1573,
     143,    82,  2448,  2484,  2557,  2580,  2625,  2667,  1103,  1574,
    2682,     2,  2734,   272,  2551,  2745,  2187,  2188,  2189,  2190,
    2191,  2192,  2763,  2775,  2880,   766,  2754,  2650,  1901,  2652,
    2995,   766,  2911,  1573,  2912,  2967,   990,  2978,   740,  2997,
    1697,  1044,  1712,   766,  1330,  1893,  3019,  1332,   766,   273,
    3037,  1575,  1610,   278,  1223,  1576,  1894,  1616,     3,     4,
    3056,     5,     6,  2735,   646,   194,     7,  1745,  1746,  1747,
    1493,  1749,  1240,  2811,  1707,  3024,  3030,  2811,  3031,   991,
    1045,  2515,  2181,     8,     9,   646,   766,   647,  1573,  2971,
    1946,  2920,  2460,  2922,  1897,  1333,  2407,  1712,  2409,  2410,
     766,    10,    11,   776,  2772,  1898,   195,   960,   647,  1046,
    1006,  1227,    82,  2961,  3047,  2777,   785,  2989,  1047,   193,
    1546,  2878,  2047,   259,   260,   261,   262,   263,  1469,  1753,
     745,   198,  1755,  1577,  2636,  2385,  2637,    42,   133,   134,
    2136,   913,   747,   748,   916,   233,   897,   919,   234,  1333,
     901,   750,  1344,  1341,   905,   241,  2110,  1349,  1358,  1349,
    1016,  1082,  1083,  1084, -1769,  1345, -1769,  1577,  1798,  1611,
      12,  1573,   688,  1989,  2383,   688,  1812,  1373,  1376,   249,
    3035,   695,  1712,   250, -1769,  1578, -1769, -1769,  2758,   252,
    1448,  1712,  1448,  2683,  2772,   815,   766, -1769,  2516,   815,
     815,   815,   815,  2684,   766,  1825,  2365,   766,  3026,  2201,
    3028,  2781,  1085,  1086,  1087,  1088,  1089,  1090,   815,   253,
     766,   254,  1577,  3005,   854,    33,    34,  3006,  1091,  1092,
    1093,   766,  1334,   766,   766,   257,   766,   766,   766,   766,
     766,   766,   766,   766,   766,   766,   766,   766,   766,   766,
     766,   766,   766,  2416,   265,  2073,  2073,  2725,  3042,  1192,
     133,   134,  1925,   766,   766,   854,  1570,  1904,   766,  1571,
     766,  1572,  2080,  1395,  1396,  2082, -1769,   873,  1612, -1769,
   -1769,   287,  1215,   284,  2909,  2867,  1334,  2869,  1361,   285,
      13,  1573,   688,  2384, -1769,   288,   708,   708,   766,   766,
     766,  1574,  1884,  1886,  2638,  1577,  1602,  2517,  1335,   815,
     289,  1468,  1606,  1472,   815,    43,   953,   954,   766,   293,
    2233,  2183,  2184,  2185,  2186,  1617,  1494,  1397,  1398,    44,
    1637, -1769,  1495,  1496,  1497,   294,  1618,  1346,   296,    14,
    1554,   134,   774,  1575,  2298,  2424,  2687,  1576,  2689,  2031,
    2387,  2692,  1498,  2693,    45,   766,   783,   300,  1619,  2972,
     788,   815,  1335,  1624,  1625,  1620,  1336,  1094,  1579,  2058,
    1095,    15,   802,   305,  2187,  2188,  2189,  2190,  2191,  2192,
     766,  1632,  1633,  1347,   314,  1528,  1645,   815,   815,   323,
     708,  1813,   815,  1637,  2885,  1651,  1537,   766,  2063,  1348,
     924,  1177,  1178,    46,   324,  1181,  1182,   766,  2092,   330,
    2092,  2221,   333,  1776,  1344, -1769,   334,  1777,  2809,  2076,
     335,   909,   815,   815,   339,  1577,     1,  1345,  1337,   352,
    2079,  2101,  -261,  2102,   341,   102,  2032,  2083,   342,  2124,
    1788,  2087,  2113,  2089,  2090,  2091,   346,  1598,  1789,  1790,
    1017,  1017,   347,  2033,  2301,  1607,   350,  1607,   351,  1017,
    1499,   353,  2286,  1500,  1202,  1203,  1204,  1205,  2999,   934,
     935,  2934,  1694,   336,  1638,   947,   356,  1578,  2385,   357,
     103,   104,  1337,  1016,  2930, -1769,   948,  1501,   105,  1096,
    1022,  1023,  1024,  1639,  1640,   367,  2034,     3,     4,   368,
       5,     6,  1017,   371,  1097,     7, -1769,  1502,  1098,   376,
     386,   387,   972,  1641,  1349,   394,  1776,   390,  1778,  -261,
    1777,  1779,     8,     9,  2388,  1358,   395,   396,  1349,  2508,
     402,   413,  1453,  1454,  1455,  2035,  -261,  1638,   949,  2166,
      10,    11,  1503,  1573,  2546,  2389,  1099,  1703,  1704,  1705,
    2186,  2884,  1477,   950,   824,   766,  1639,  1640,   405,   924,
     651,  1504,  1505, -1769,  2036,   669,  -936,   656,  2954,   658,
     659,   660, -1769,  2037,  1100,   862,  1641,  1506,   665,  -261,
     766,   766,   766,  1573,   766,   667,    81,   674,  -595,  1513,
     675,   670,   671,  1101,   259,   260,   261,   262,   263,  1360,
    2187,  2188,  2189,  2190,  2191,  2192,  1115, -1769,   673,   306,
     766, -1769,  1758,   676,   873, -1769,  1507,   678,  -261, -1769,
    2416,  1778,    82, -1287,  1779,   813,   766,   962,   963,   968,
     964,  1538,  2934, -1769,   969,  3005,   965,   966,   967,  3006,
     970,  1553,   975,   951,  1786,  1347,  1573,  -261,  3010,  1508,
     766,   971,  1793,  1794,   766,   815,  -261,   976,  2673,   977,
    1579,  1348,     3,     4,   978,     5,     6,  2954,   982,   881,
       7,  2511,  1004,   686,  1102,   315, -1769,  1577,  1006, -1769,
    1007, -1769,  1009,  1010,   766,  1015,  1016,     8,     9,   766,
    1080,  1081,  1082,  1083,  1084,   766,   307, -1769,  1019,  1124,
    1823, -1769,  1027,  1028,   766,    10,    11,  1117,   882,  1128,
     766, -1769, -1769,   308,  1030, -1769, -1769,  1577,   766,  3010,
    1031,  1712,  3027,  1032,  1033,  1240,  1034,  1869,  2419,  1035,
   -1769,  2183,  2184,  2185,  2186, -1769, -1769, -1769,   815,   815,
     106,  1103,  1036,  1085,  1086,  1087,  1088,  1089,  1090,  1037,
    1038,  1039,  1050, -1769,   815, -1769,   309, -1769,   883,  1091,
    1092,  1093,   316,  1051,  1052,  1055,   107,  1056,     1,  1058,
    1129,  2449,  1060,  1017,    12,   924,  1061,  1062,  1063,   317,
    1577,  1869,  1041,  1064,  2187,  2188,  2189,  2190,  2191,  2192,
    1132,  1065,  1972,  2486,   884,   310,  1712,  1133,  2790,  1066,
    1068,  1135,  1136,  1140,  1712,  1984,  1984,  1141,  1143,  1984,
    1146,  1155,  2719,  1728,  1160,  1184,   685,  1174,  1187,  2718,
      89,  1208,   318,  1216,   311,  1869,  1217,  2020,  2020,   703,
    1218,  2020,  1869,   312,  1219, -1769,  1221,   108,  1220,     3,
       4,  1224,     5,     6,  1226,  1228,  1237,     7,  1229,  1239,
    1252,  2183,  2184,  2185,  2186,  1253,   777,  1254,  2054,  1193,
    1767,   319,  1255,  1373,     8,     9,  1260,   766,  1268,  1042,
    1264, -1769,   794,   795,  1349,  1267,  1269,  1270,   801,  1323,
    1315,   803,    10,    11,  1792,  1869,  1043, -1769,  1455,  1326,
     320,   885,  1340,  1343,   182,   190,   824,  1357,  1094,   321,
    1729,  1095,   862,  1363,  2187,  2188,  2189,  2190,  2191,  2192,
    1364,  1372,  1379,  2680, -1769,  1380,  1381,  1730,  1192,  1382,
    1383,   766,  1392,   766,  1400,  1403,   862,  1349,  1401,  1044,
     109,   766,   766,   766,   766,  2538,  2020,  2540,  1410,  1438,
    1441,  1444,  2115,  1786,  1832,  1445,  2120,  2120,   190,  2531,
    2776,  1464,  1491,  1458,   190,   766,  2723,  1476,  1478,   725,
    1731,  1480,  1199,  1492,  1516,  2132,  2073,   886,  1045,  1518,
    1521,   726,  1519,  1523,  1529,    15,  1532,  1534, -1769,  1549,
   -1769,  2376,  1557,  2377,  2378,  2379,  2380,  2381,  2382,  2183,
    2184,  2185,  2186,  1542,  1551, -1769,  1482,  1046,  1559,  1732,
    1262,  1586,  1589, -1769,  1588,  1591,  1047, -1769,   887,  1597,
    1646,   110,   766,   924,  2164,  1657,  1659,  1660, -1769,   111,
    1096,  1663,  1664,  2843,  1692,   190,  1869,   190,  1733,  1690,
    2031,  2851, -1769,  1695,  1698,  1097,  1708,  1734,  1699,  1098,
    1727,  1713,  2187,  2188,  2189,  2190,  2191,  2192,  1714,  1715,
    1718,  2202,  1720,  1723,  1736,  1743,  2593,  2594,  2595,  1737,
    2597,  2598,  2599,  2600,  2601,  2602,   708,  1739,  1742,  2605,
   -1769,    13,  1744,  1760,  1762,  1763,   888,  1099,  1764,  1765,
    1766,  2870,    48,    49,    50,    51,    52,    53,  1768,    54,
    1769,  2672,  1770,  1772,  1017,  1771,  1774,  1775,  2694,  1787,
     190,  2059,  1261,  1800,   643,  1100,   139,  1802,  2020,  1803,
     643,  1869,  1804,  1808,   924,   742,  1811,  2032,  2237,  1607,
      14,  2699, -1769,  2020,  1101,   766,  1818,   766,  2187,  2188,
    2189,  2190,  2191,  2192,  2033,  2020,  1819,  1017,  1820,   889,
    1824,  1827,  1836,  1830,  1846,   139,  1984,  1848,   937,  1712,
      82,  2653,  2712,  2183,  2184,  2185,  2186,  1844,  1883,  2714,
    1881,  2680,  1923,  1924,  1926,  2103,  2104,  1455,  2107,  2020,
     645,  1290,  1934,  1869,  1940,  1869,   645,  2034,  1950,  1955,
    2953,  1951,  1967,   744,   824,   824,  2858,  1969,  1970,  2130,
     701,  1971,   746,  1981,  1992,  1349,  1993,  2797,  1994,  1998,
    2383,  2872,  2001,  2040,  1956,  1102,  2187,  2188,  2189,  2190,
    2191,  2192,  2055,  1957,    82,  2057,  2035,  2060,  1358,  2066,
    1349,  1321,  2041,  2042,   779,  2043,  2044,  2071,  1703,  2045,
     784,   766,   786,  2075,   766,  2078,   793,  1958,  2654,   793,
    1959,  2077,   793,  2081,  2094,  2036,  2161,  2096,  2098,  2109,
    2114,  2129,   805,  2131,  2037,  2655,  2139,  2142,  1960,  2143,
    2144,  2798,  2145,  2799,  2147, -1769,  2146,  2183,  2184,  2185,
    2186,   852,  1103,  2163,   766,  2174,  2162,   766,  2800,   865,
     868,   871,  2458,  2182,  2175,   893,  2801,  2177,  2178,  2179,
    2802,  2180,  2194,   903,   936,  1786,  3033,  2473,  2656,  2475,
    3011,  3012,  3013,  3014,  3015,  3016,   766,  2200,   926,   766,
    2203,  1665,  2205,  2492,  2680,  2803,  2680,   766,  2212,  2384,
    2187,  2188,  2189,  2190,  2191,  2192,  2183,  2184,  2185,  2186,
    2351,  2214,  2235,  2220,   766,  2224,  2232,  2657,  2225,  2511,
    2240,  2303,  2020,  2304,  2305,  2306,  2311,  2352,  2353,  1869,
    1869,  1869,  1869,  1869,  1869,  2354,  2375,  2366,  2395,  2295,
    2394,  2296,   688,  2405,  1961, -1715,  2658,  1875,  2402,  2845,
    2408,   815,  2411,   815,  2420,  2659,  2387,  2425,  2426,  2187,
    2188,  2189,  2190,  2191,  2192,     3,     4,  2355,     5,     6,
    2431,  1849,  1850,     7,  1851,  2432,  2356,   269,  1852,  1853,
    2433,  2434,  2435,  2020,  2183,  2184,  2185,  2186,  1869,  2439,
       8,     9,  1870,  2440,  2441,  2442,  1854,  1962,  2446,  2447,
    2436,  1954,  2450,  2453,  1963,  2357,  2438,  2842,    10,    11,
    2452,   681,  2459,   681,   681,  2457,  2463,  2467,  2789,  2471,
    2472,  2474, -1769,  2487,  2495,  2519,  2504,   681,  2510,  2707,
    2506,  2796,  2534,  2537,  2548,  2549,  2020,  2187,  2188,  2189,
    2190,  2191,  2192,  2373,  2558,   681,  1870,   926,   681,  2565,
    2358,  2582,  2583,  1972,   681,  2569,  2575,  2567,   681,  2586,
    2576,  2680,   681,  2577, -1769,  2596,   681,  2603,  2732,  2591,
     681,   681,  2581,   681,  2592,  2610,   681,    12,   681,   681,
     681,  2604,  2611,  2873,  2385,  2614,   681,  2615,  2451,   681,
    1870,  2456,  2359,  2616,  2617,  2938,   681,  1870,  2618,  2619,
    2620,   681,  2368,  2797,  2631,  1954,  2633,  2648,  1334,   681,
    2651,  3067,   862,  2661,  2663,  2668,  1118,  2670,  2674,  1943,
     681,  1869,  2691,  1869,   681,  1666,  2695,  2700,   681,  2701,
    2388,  2702,  2703,   681,  1869,  2708,   681,  2715,  2716,  1869,
    2717,  2720,  2724,  2020,  2727,  2020,  2736,  2737,   854, -1769,
    1870,  2389,   931,  2760,  2750,  1627,  1628,  2782,  2786,  1149,
    2787,  2794,  1644,  2820,  2822,  2823,  2825,  2798,  2826,  2799,
    1349,  2827,  2828,  1166,  1166,  1166,  1017,  1166,  2831,  1166,
    1166,  -595,  2834,  1667,  2800,    89,    89,  2839,  2841,   827,
    2844,   766,  2801,  2848,  1712,  1668,  2802,  2874,   828,  2850,
   -1769,  2854,  2859,  2868,  2860,  1669,  2886,   829,  2428,  2890,
    2877,  2120,   830,  2892,  2709,  2120,  2907,  2908,  2916,   815,
    2914,  2803,   766,  1670,  2004,  2392,   815,  2918,  2919,   871,
    2926,  2939,  2951,  1671,  2960,  2952,  1672,  2964,  2966,  2998,
    1235,  2994,   766,  2980,  3000,  3017,  2173,  3021,  3029,  1673,
    3041,  3051,   766,  3061,   831,  2491,  2875,  3062,  3050,  2427,
    2154,  2421,   832,   926,  1118,    70,  1869,  1835,  1869,  1869,
    1869,  1869,  1265,  1541,    71,   556,  2116,  2470,    15,  2125,
     766,   202,  2168,  2170,   348,   197,   280,   344,  1273,  1273,
     668,  1870,  1648,   349,   406,  1649,   282,  2751,  1674,  1869,
     655,   283,   375,   373,  2020,   661,   662,  3048,  1810,  2095,
     891,  1319,  2105,  2237,  1982,  1365,  1990,  1869,   833,  1795,
    2536,  1869,  1563,  2020,  1869,  1855,  2749,  2020,  1675,  1598,
    1567,  1880,  3054,  2199,  2112,  1902,  2542,  2853,  1676,  2544,
    1856,    65,   156,   834,  1473,    66,  2807,   190,    67,  1842,
     835,   800,   836,   961,  2185,  2186,   338,  1857,  1677,  1845,
    2005,  1678,   837,  1679,   981,  2856,  1258,  1585,  1816,  1555,
    1847,  2795,  2006,  1859,  2898,     1,  1870,  1460,  1511,  3025,
    2906,  1937,  1211,  1450,  2624,  1869,  2526,  1869,   838,  1524,
    1411,  1680,  2623,  2370,  2606,  1378,   839,  1409,  2363,  2821,
    1681,  2368,  2099,  1691,  1878,  2187,  2188,  2189,  2190,  2191,
    2192,  2778,  2226,  3055,  1861,  1658,  3044,  2302,  2981,  2364,
     681,  2649,  2029,  2671,  1017,  2830,  1862,  2628,  2832,  2372,
    2837,  1601,  2681,   840,  2629,  1308,  2813,  2386,  1870,  2917,
    1870,  2584,  2936,   815,  2935,  2881,     3,     4,   766,     5,
       6,  3043,  2566,  2871,     7,  1593,  2713,  2564,  1443,   841,
    2970,  1275,  2056,  2765,  1467,   414,    89,  1863,    89,   871,
     793,     8,     9,     0,     0,     0,     0,  1459,   805,     0,
    1870,   871,     0,     0,     0,   190,  2730,  1869,  1474,    10,
      11,     0,  1869,     0,     0,     0,     0,   842,     0,     0,
       0,   926,     0,     0,     0,     0,  1864,     0,   843,     0,
    2020,     0,     0,     0,  2746,     0,  1869,     0,  1865,     0,
    1279,     0,  2020,     0,     0,     0,     0,    89,     0,     0,
    1866,  1867,  2007,     0,  2897,     0,     0,     0,     0,  1868,
       0,     0,   687,   681,   681,   681,     0,     0,     0,     0,
     272,     0,     0,     0,     0,     0,     0,  1869,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1535,     0,  2524,
    1875,  2527,  2528,  2529,  2530,     0,     0,  1017,     0,  1017,
       0,     0,  1869,     0,     0,     0,     0,  2020,     0,  2837,
    1561,  1075,  1076,  1077,  1078,  1079,  1080,  1081,  1082,  1083,
    1084,  1584,   926,     0,     0,     0,     0,   844,   845,   846,
       0,     0,     0,     0,  1870,  1870,  1870,  1870,  1870,  1870,
     847,  1280,     0,     0,     0,     0,     0,  2751,  1954,  1281,
       0,     0,  1869,     0,  1869,  1282,     0,  1283,  1869,     0,
       0,     0,  1598,     0,     0,     0,     0,     0,  1284,  1085,
    1086,  1087,  1088,  1089,  1090,     0,  1631,     0,     0,     0,
       0,  1869,     0,     0,     0,  1091,  1092,  1093,     0,  1905,
    2150,  2151,     0,  1870,  1869,  2913,  1285,     0,     0,     0,
       0,  2160,  2846,     0,     0,  2183,  2184,  2185,  2186,     0,
       0,     0,  1286,     0,     0,     0,     0,  1287,     0,   766,
    3022,     0,     0,     0,     0,     0,     0,   766,     0,  1288,
     871,     0,     0,     0,     0,     0,  1289,     0,     0,     0,
       0,     0,     0,     0,   848,     0,     0,     0,  1869,     0,
    2207,  2208,  2209,  2210,     0,     0,     0,     0,  2187,  2188,
    2189,  2190,  2191,  2192,  1017,  2216,  1869,     0,  2020,     0,
       0,     0,     0,     0,     0,   708,   708,   708,     0,   708,
     708,   708,   708,   708,   708,     0,     0,     0,   708,     0,
       0,     0,     0,     0,  2630,     0,     0,     0,     0,  2647,
       0,     0,     0,     0,  1869,  1076,  1077,  1078,  1079,  1080,
    1081,  1082,  1083,  1084,     0,     0,     0,     0,     0,   766,
       0,     0,     0,     0,  1094,     0,  1870,  1095,  1870,  1077,
    1078,  1079,  1080,  1081,  1082,  1083,  1084,     0,     0,  1870,
       0,  2309,  2310,     0,  1870,     0,     0,     0,  2314,  2315,
       0,     0,     0,     0,     0,     0,     0,  1556,     0,     0,
       0,     0,  1085,  1086,  1087,  1088,  1089,  1090,     0,     0,
       0,     0,     0,     0,     0,  1807,     0,     0,  1091,  1092,
    1093,     0,     0,     0,  1815,  1085,  1086,  1087,  1088,  1089,
    1090,  1290,     0,     0,     0,   871,     0,     0,  1291,     0,
       0,  1091,  1092,  1093,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   182,     0,     0,     0,     0,
    1292,  1906,     0,     0,     0,  1293,  2738,     0,  2740,  2741,
    2742,  2743,     0,     0,  1907,     0,     0,     0,     0,     0,
       0,     0,     0,   924,     0,     0,  1096,     0,     0,     0,
       0,     0,   871,  3020,   871,     0,     0,     0,   865,  1954,
       0,  1097,     0,     0,     0,  1098,     0,     0,     0,     0,
       0,  1870,     0,  1870,  1870,  1870,  1870,  2773,     0,  2461,
    2462,     0,     0,     0,  2773,     0,     0,     0,  2469,     0,
    1976,     0,     0,     0,     0,     0,  2482,     0,  1908,     0,
       0,     0,     0,  1099,  1870,  1909,     0,     0,     0,     0,
       0,     0,     0,     0,  2497,  2498,     0,  1094,     0,     0,
    1095,     0,  1870,     0,     0,     0,  1870,     0,     0,  1870,
       0,  1100,     0,     0,     0,     0,     0,     0,     0,     0,
    1094,     0,     0,  1095,  1910,  2814,     0,  2173,     0,     0,
    1101,     0,     0,  3060,     0,     0,     0,     0,     0,   871,
       0,     0,     0,     0,     0,     0,  2539,     0,  2541,  1911,
       0,     0,     0,     0,     0,  2543,     0,  2545,     0,  1912,
    1913,     0, -1770,     0,  1870,     0,  1870,     0,     0,     0,
    1870,  1870,  1870,     0,   681,  1914,     0,     0,     0,     0,
   -1770,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1915,     0,     0,  1916,
    1917,   871,     0,   871,     0,  1918,     0,     0,     0, -1770,
       0,  1102,   871,  1085,  1086,  1087,  1088,  1089,  1090,  1096,
       0,     0,     0,     0,     0,     0,     0,  2524,     0,  1091,
    1092,  1093,  2876,     0,  1097,     0,     0,     0,  1098,     0,
       0,     0,  1096,     0,     0,     0,     0,     0,     0,     0,
    2137, -1770,     0,   924,  2587,  2588,  2889,  1097,  2589,  2590,
       0,  1098,  1919,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1870,     0,  1920,     0,  1099,  1870,  1103,  2159,
       0, -1770,     0,     0,     0, -1770,     0,     0,   681,     0,
       0,     0,  2613,     0,     0,     0,     0,  1954,     0,  1099,
       0,  1870,     0,     0,  1100,     0,     0, -1770,     0,   681,
       0,     0,     0,     0,     0, -1770,     0, -1770,     0,     0,
       0,     0,  2925,  1101,     0,     0, -1770,  1100,     0,     0,
       0,     0, -1770,     0,     0,     0,     0,     0,     0,     0,
   -1770,     0,  1870,     0, -1770,     0,  1101,     0,     0,     0,
   -1770,     0,     0,     0, -1770, -1770, -1770, -1770,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1870,  1094, -1770,
       0,  1095,  1954,     0,  2976,     0,     0,     0,  2773,     0,
       0,     0,     0,     0,     0,     0, -1770,     0,   139, -1770,
       0, -1770,     0,     0,     0,     0,     0,     0, -1770,     0,
       0,  2991,     0,     0,  1102,     0,  2706,     0,     0,     0,
    2711, -1770,     0,     0,     0,     0,     0,  1870,  2307,  1870,
       0, -1770,     0,  1870,     0,     0,     0,  1102,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
   -1770, -1770,  2728,  1870,     0,     0,  1870,  1870,     0,     0,
       0,     0,     0,     0,     0, -1770,     0,     0,     0,  1870,
       0,     0,     0, -1770,     0,     0,     0, -1770,  2773,     0,
       0,  1103,     0,     0,     0,  2747, -1770, -1770, -1770,  1078,
    1079,  1080,  1081,  1082,  1083,  1084,  2925,     0,     0,     0,
    1096,     0,     0,     0,  1103,     0,     0,     0,   871,     0,
       0,     0,     0,     0,     0,  1097,     0,     0,     0,  1098,
       0,     0,     0,  1870,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  2976,     0,     0,     0,     0,     0,
       0,  1870,     0,     0,  1085,  1086,  1087,  1088,  1089,  1090,
       0,   871,     0,     0,     0, -1770,     0,  1099,     0,     0,
    1091,  1092,  1093,     0,     0,     0, -1770,  2176,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1870,
       0,     0,     0,     0,  2479,  1100,     0,     0,     0,     0,
       0,     0,     0,  2489,     0,   701,     0,  2493,  1084,     0,
       0,     0,     0,     0,  1101,     0,     0, -1770,   924,  2503,
       0,     0,  2138,  1069,  1070,  1071,  1072,  1073,  1074,  1075,
    1076,  1077,  1078,  1079,  1080,  1081,  1082,  1083,  1084,     0,
       0,  2222,     0,  2183,  2184,  2185,  2186,     0,     0,     0,
     681,     0,    72,     0,     0,     0,   681,  1085,  1086,  1087,
    1088,  1089,  1090,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1091,  1092,  1093,     0,     0, -1770,     0,
     681,     0,     0,     0,     0,     0,     0,  1085,  1086,  1087,
    1088,  1089,  1090,  2865,     0,  1102,  2187,  2188,  2189,  2190,
    2191,  2192,     0,  1091,  1092,  1093,     0,     0,     0,  1094,
       0,     0,  1095,     0, -1770,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  2396,  1070,  1071,
    1072,  1073,  1074,  1075,  1076,  1077,  1078,  1079,  1080,  1081,
    1082,  1083,  1084,     0,     0,     0,     0,     0,     0,     0,
       0, -1770,  1103,     0,     0,     0,     0,  2585,     0,     0,
       0,     0,     0,     0,     0, -1770, -1770, -1770, -1770, -1770,
   -1770, -1770,     0, -1770, -1770,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
   -1770,  1085,  1086,  1087,  1088,  1089,  1090,  2607,     0,     0,
       0,     0,  1094,     0,     0,  1095,     0,  1091,  1092,  1093,
    2622,     0,     0,     0,     0,     0,  2962,     0,     0,     0,
       0,  1096,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1094,     0,     0,  1095,  1097,     0,     0,     0,
    1098,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  2982,  2983,     0,  2985,     0,  2987,  2988,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   871,  2242,     0,     0,     0,     0,     0,  1099,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   871,     0,     0,     0,     0,  1100,     0,     0,     0,
       0,     0,  2243,  2244,  2245,     0,   190,     0,     0,     0,
    3032,     0,     0,     0,  1096,  1101,     0,     0,   681,   681,
       0,     0,     0,     0,     0,     0,  3039,  2246,  3040,  1097,
       0,   926,     0,  1098,     0,  2247,  1094,     0,     0,  1095,
    2248,     0,     0,     0,  1096,     0,     0,   190,     0,     0,
       0,     0,     0,     0,     0,  2249,     0,     0,     0,  1097,
    2250,     0,  2251,  1098,     0,  3052,     0,     0,     0,  2252,
       0,  1099,  2253,     0,     0,  2254,     0,     0,  2255,     0,
       0,  2256,     0,     0,     0,     0,  2257,  3057,  3058,     0,
       0,  3059,     0,     0,     0,     0,  1102,     0,     0,  1100,
       0,  1099,     0,     0,  2258,     0,     0,     0,  2479,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1101,     0,
    2259,     0,     0,  2260,  2261,     0,     0,     0,     0,  1100,
    2262,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  2263,     0,     0,     0,     0,     0,     0,  1101,     0,
       0,  2607,     0,     0,     0,     0,     0,  2264,  1096,     0,
       0,     0,  2626,  1103,  2265,     0,     0,     0,     0,     0,
       0,  2266,     0,  1097,  2267,  2268,  2269,  1098,  2270,  2271,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  2272,     0,     0,     0,  1102,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1099,     0,     0,  2273,  2274,
    2275,  2276,     0,  2277,     0,     0,     0,     0,     0,  1102,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   871,
    2278,  2279,     0,  1100,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  2855,  2479,     0,     0,
       0,   926,  1101,  2280,     0,     0,  1103,     0,     0,     0,
       0,     0,  2281,  2282,     0,  2283,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1103,     0,     0,     1,
       0,     0,   416,   417,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  2739,     0,   418,     0,   419,     0,     0,
       0,  2479,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   420,     0,     0,     0,  2607,     0,  2284,   421,     0,
    2901,     0,  2903,  1102,     0,     0,     0,     0,     0,   422,
     423,   424,  2759,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   425,   681,   426,   427,   428,
       3,     4,   429,     5,     6,   430,     0,   431,     7,   432,
     433,   871,     0,     0,     0,   871,   434,     0,     0,   435,
       0,   436,   437,   438,     0,     8,     9,     0,     0,     0,
       0,   439,     0,   440,   441,     0,   442,     0,   443,   444,
    1103,     0,   445,    10,    11,     0,     0,   446,   447,   448,
       0,   449,   450,     0,     0,     0,   451,   452,     0,   453,
       0,     0,     0,   454,     0,   455,   456,     0,     0,   457,
       0,     0,     0,   458,     0,     0,   459,     0,   460,     0,
     461,     0,   462,     0,   463,   464,     0,   465,   466,   467,
       0,     0,     0,   468,     0,   469,   470,     0,   471,     0,
       0,     0,     0,     0,     0,     0,   472,   473,     0,     0,
       0,  1166,  1166,  1166,  1166,  1166,  1166,     0,     0,   474,
       0,     0,   475,   476,     0,     0,   477,   478,     0,     0,
     479,   480,     0,     0,     0,     0,     0,     0,     0,   481,
     482,   483,     0,   484,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   485,   486,   487,     0,   488,     0,     0,
       0,   489,   490,     0,     0,     0,   491,     0,     0,     0,
       0,     0,     0,     0,   492,     0,     0,     0,     0,     0,
       0,     0,   493,   494,   495,     0,     0,     0,     0,     0,
     496,   497,     0,     0,     0,     0,   498,     0,     0,   499,
       0,     0,     0,   500,   501,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   502,     0,  1069,  1070,  1071,  1072,
    1073,  1074,  1075,  1076,  1077,  1078,  1079,  1080,  1081,  1082,
    1083,  1084,   503,     0,     0,     0,   926,     0,     0,     0,
     504,     0,     0,     0,     0,     0,   505,  1069,  1070,  1071,
    1072,  1073,  1074,  1075,  1076,  1077,  1078,  1079,  1080,  1081,
    1082,  1083,  1084,     0,     0,     0,     0,     0,     0,   107,
       0,     0,     0,     0,     0,     0,   506,     0,   507,   508,
    1085,  1086,  1087,  1088,  1089,  1090,     0,   509,     0,     0,
       0,     0,     0,     0,     0,     0,  1091,  1092,  1093,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1085,  1086,  1087,  1088,  1089,  1090,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   510,  1091,  1092,  1093,
       0,     0,     0,     0,     0,     0,     0,   511,     0,     0,
       0,   512,     0,     0,     0,   513,     0,     0,  1069,  1070,
    1071,  1072,  1073,  1074,  1075,  1076,  1077,  1078,  1079,  1080,
    1081,  1082,  1083,  1084,     0,     0,     0,     0,     0,   514,
     515,     0,     0,     0,   516,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   517,     0,     0,     0,
       0,     0,   518,   519,   520,   521,     0,     0,   522,     0,
       0,     0,   523,     0,     0,     0,     0,     0,     0,   524,
     525,     0,  1085,  1086,  1087,  1088,  1089,  1090,     0,     0,
       0,   526,     0,   527,     0,     0,     0,     0,  1091,  1092,
    1093,     0,     0,     0,   528,  1094,   529,     0,  1095,   530,
       0,     0,     0,     0,     0,   531,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1094,     0,     0,  1095,
       0,   532,     0,     0,   533,     0,     0,     0,     0,     0,
     534,     0,     0,   535,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   536,     0,
       0,     0,     0,     0,     0,   537,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   538,   539,
     540,   541,   542,   543,   544,     0,     0,   545,     0,   546,
       0,   547,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1096,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1094,     0,     0,
    1095,     0,  1097,     0,     0,     0,  1098,  1405,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1096,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1097,     0,     0,     0,  1098,  1719,     0,
       0,     0,     0,     0,  1099,  1069,  1070,  1071,  1072,  1073,
    1074,  1075,  1076,  1077,  1078,  1079,  1080,  1081,  1082,  1083,
    1084,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1100,     0,     0,  1099,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1101,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1100,     0,     0,     0,     0,     0,  1085,
    1086,  1087,  1088,  1089,  1090,     0,     0,     0,     0,  1096,
       0,     0,  1101,     0,     0,  1091,  1092,  1093,     0,     0,
       0,     0,     0,     0,  1097,     0,     0,     0,  1098,  1726,
       0,     0,     0,     0,  1069,  1070,  1071,  1072,  1073,  1074,
    1075,  1076,  1077,  1078,  1079,  1080,  1081,  1082,  1083,  1084,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1102,     0,     0,     0,  1099,  1069,  1070,  1071,
    1072,  1073,  1074,  1075,  1076,  1077,  1078,  1079,  1080,  1081,
    1082,  1083,  1084,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1102,  1100,     0,     0,     0,  1085,  1086,
    1087,  1088,  1089,  1090,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1101,  1091,  1092,  1093,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1103,
       0,  1085,  1086,  1087,  1088,  1089,  1090,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1091,  1092,  1093,
       0,     0,     0,     0,  1094,     0,     0,  1095,     0,     0,
    1103,     0,     0,  1069,  1070,  1071,  1072,  1073,  1074,  1075,
    1076,  1077,  1078,  1079,  1080,  1081,  1082,  1083,  1084,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1102,     0,     0,     0,  1069,  1070,
    1071,  1072,  1073,  1074,  1075,  1076,  1077,  1078,  1079,  1080,
    1081,  1082,  1083,  1084,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1085,  1086,  1087,
    1088,  1089,  1090,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1091,  1092,  1093,     0,     0,     0,     0,
       0,     0,     0,  1094,     0,     0,  1095,     0,     0,     0,
       0,  1103,  1085,  1086,  1087,  1088,  1089,  1090,     0,     0,
       0,     0,     0,     0,     0,     0,  1096,     0,  1091,  1092,
    1093,     0,     0,     0,     0,     0,  1094,     0,     0,  1095,
       0,  1097,     0,     0,     0,  1098,  1738,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1099,  1069,  1070,  1071,  1072,  1073,  1074,
    1075,  1076,  1077,  1078,  1079,  1080,  1081,  1082,  1083,  1084,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1100,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1096,     0,     0,     0,     0,
    1101,     0,  1094,     0,     0,  1095,     0,     0,     0,     0,
    1097,     0,     0,     0,  1098,  1748,     0,     0,  1085,  1086,
    1087,  1088,  1089,  1090,     0,     0,     0,     0,  1096,     0,
       0,     0,     0,     0,  1091,  1092,  1093,  1094,     0,     0,
    1095,     0,     0,  1097,     0,     0,     0,  1098,  1750,     0,
       0,     0,  1099,     0,     0,  1071,  1072,  1073,  1074,  1075,
    1076,  1077,  1078,  1079,  1080,  1081,  1082,  1083,  1084,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1100,  1102,     0,     0,     0,  1099,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1101,
       0,     0,     0,  1849,  1850,     0,  1851,     0,     0,   269,
    1852,  1853,     0,  1100,     0,     0,     0,  1085,  1086,  1087,
    1088,  1089,  1090,     0,  1096,     0,     0,     0,  1854,     0,
       0,     0,  1101,  1091,  1092,  1093,     0,     0,     0,  1097,
       0,     0,     0,  1098,  1751,     0,     0,     0,  1103,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1096,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1094,  1097,     0,  1095,     0,  1098,  1752,
    1102,  1099,     0,     0,     0,     0,   384,  1072,  1073,  1074,
    1075,  1076,  1077,  1078,  1079,  1080,  1081,  1082,  1083,  1084,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1100,
       0,     0,     0,  1102,     0,     0,  1099,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1101,  1073,
    1074,  1075,  1076,  1077,  1078,  1079,  1080,  1081,  1082,  1083,
    1084,     0,     0,     0,  1100,     0,     0,  1103,  1085,  1086,
    1087,  1088,  1089,  1090,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1101,  1091,  1092,  1093,     0,     0,     0,
       0,     0,  1094,     0,     0,  1095,     0,     0,     0,     0,
    1103,     0,     0,     0,     0,     0,     0,     0,     0,  1085,
    1086,  1087,  1088,  1089,  1090,  1096,     0,     0,     0,  1079,
    1080,  1081,  1082,  1083,  1084,  1091,  1092,  1093,     0,  1102,
    1097,     0,     0,     0,  1098,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1074,  1075,  1076,  1077,  1078,
    1079,  1080,  1081,  1082,  1083,  1084,     0,     0,     0,     0,
       0,     0,     0,     0,  1102,     0,     0,     0,     0,     0,
       0,     0,  1099,  1085,  1086,  1087,  1088,  1089,  1090,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1091,
    1092,  1093,     0,     0,     0,     0,  1103,     0,     0,     0,
    1100,     0,     0,     0,  1085,  1086,  1087,  1088,  1089,  1090,
       0,     0,     0,     0,  1096,     0,     0,     0,     0,  1101,
    1091,  1092,  1093,  1094,     0,     0,  1095,     0,     0,  1097,
       0,  1103,     0,  1098,     0,     0,     0,   158,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   712,   713,     0,     0,     0,     0,   269,
     714,   715,  -595,     0,  1094,     0,     0,  1095,     0,     0,
       0,  1099,     0,   716,     0,     0,   159,  1855,   717,   718,
       0,     0,     0,     0,     0,   719,     0,     0,     0,     0,
       0,     0,  1856,     0,     0,   160,     0,     0,     0,  1100,
    1102,     0,     0,     0,     0,     0,     0,     0,     0,  1857,
       0,     0,  2639,   720,     0,     0,     0,     0,  1101,     0,
       0,     0,     0,     0,     0,  1859,     0,     0,  1094,  1849,
    1850,  1095,  1851,     0,   161,   269,  1852,  1853,     0,     0,
       0,     0,     0,     0,     0,  1096,   162,     0,     0,     0,
       0,     0,     0,     0,  1854,     0,   163,     0,     0,  1094,
    1097,     0,  1095,     0,  1098,     0,  1861,  1103,     0,     0,
       0,     0,     0,     0,   164,     0,     0,     0,  1862,     0,
       0,     0,     0,     0,   165,     0,  1096,     0,   712,   713,
       0,     0,     0,     0,   269,   714,   715,  -595,     0,  1102,
     166,  1097,  1099,     0,   721,  1098,     0,     0,   716,     0,
       0,     0,     0,   717,   718,     0,     0,     0,     0,  1863,
     719,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1100,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     167,     0,     0,  1099,     0,     0,     0,     0,   720,  1101,
    1096,     0,  2640,     0,     0,     0,     0,     0,  1864,     0,
       0,     0,     0,     0,   168,  1097,  1103,  2641,  2642,  1098,
    1865,  1100,     0,     0,     0,     0,     0,     0,     0,   169,
       0,  1096,  1866,  1867,     0,     0,   170,     0,     0,   171,
    1101,  1868,     0,     0,   687,     0,  1097,     0,     0,     0,
    1098,   722,   272,     0,     0,     0,   723,  1099,     0,   172,
       0,     0,   173,     0,   174,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1102,     0,     0,   175,   724,  1100,     0,     0,  1099,   721,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   176,  1849,  1850,  1101,  1851,     0,     0,   269,  1852,
    1853,     0,     0,     0,     0,     0,  1100,     0,     0,   725,
       0,  1102,     0,     0,     0,     0,     0,  1854,     0,     0,
       0,   726,  2004,  2320,  2321,  1101,     0,  2322,  2323,  2324,
       0,     0,     0,     0,     0,     0,     0,  1103,     0,   727,
       0,     0,     0,     0,   728,     0,     0,   729,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   730,     0,
       0,     0,     0,     0,   731,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   732,  1102,   722,     0,  1103,   733,
       0,   723,   734,     0,     0,   735,     0,     0,     0,     0,
     712,   713,     0,     0,   736,   737,   269,   714,   715,     0,
       0,     0,     0,     0,     0,     0,  1102,     0,     0,   724,
     716,     0,     0,     0,     0,   717,   718,     0,     0,     0,
       0,     0,   719,  1855,     0,     0,     0,  2325,     0,     0,
       0,     0,     0,     0,  2326,  1189,   738,     0,  1856,     0,
     739,     0,  1103,     0,   725,     0,     0,     0,   740,     0,
     720,     0,     0,     0,     0,  1857,   726,     0,  2005,   741,
       0,     0,     0,     0,     0,   742,  2327,     0,     0,     0,
    2006,  1859,     0,  1103,   727,  2328,     0,     0,     0,   728,
       0,     0,   729,     0,     0,     0,     0,     0,   158,   743,
       0,     0,     0,   730,     0,     0,     0,     0,     0,   731,
       0,     0,     0,     0,  2329,  2330,     0,     0,     0,   732,
       0,     0,  1861,     0,   733,     0,     0,   734,     0,     0,
     735,     0,     0,     0,  1862,     0,     0,   159,     0,   736,
     737,     0,     0,   744,     0,     0,     0,     0,     0,     0,
     745,   721,   746,     0,     0,  2004,   160,     0,     0,  2331,
       0,     0,   747,   748,   749,     0,     0,     0,     0,     0,
       0,   750,     0,     0,    82,  1863,     0,     0,     0,     0,
       0,   738,   272,   712,   713,   739,     0,     0,     0,   269,
     714,   715,     0,   740,     0,   161,     0,     0,     0,     0,
       0,  2332,     0,   716,   741,     0,     0,   162,   717,   718,
     742,     0,     0,     0,  1864,   719,     0,   163,     0,     0,
       0,     0,     0,     0,     0,     0,  1865,     0,     0,     0,
       0,     0,     0,     0,   743,   164,     0,     0,  1866,  1867,
    2007,     0,     0,   720,     0,   165,     0,  1868,   722,     0,
     687,     0,     0,   723,     0,     0,  1855,  2333,   272,     0,
       0,   166,     0,     0,     0,     0,     0,  1849,  1850,     0,
    1851,  1856,     0,   269,  1852,  1853,     0,     0,   744,     0,
       0,   724,     0,     0,     0,   745,     0,   746,  1857,     0,
       0,  2005,  1854,     0,     0,     0,     0,   747,   748,   749,
       0,   167,     0,  2006,  1859,     0,   750,     0,     0,    82,
       0,     0,     0,     0,     0,     0,   725,   272,     0,     0,
       0,     0,     0,     0,     0,   168,     0,     0,   726,     0,
       0,     0,     0,     0,   721,     0,     0,     0,     0,     0,
     169,     0,     0,     0,     0,  1861,   727,   170,     0,     0,
     171,   728,     0,     0,   729,     0,     0,  1862,     0,     0,
       0,     0,     0,     0,     0,   730,     0,     0,     0,     0,
     172,   731,     0,   173,     0,   174,     0,     0,     0,     0,
       0,   732,     0,     0,     0,     0,   733,     0,     0,   734,
       0,     0,   735,     0,   175,     0,     0,     0,  1863,     0,
       0,   736,   737,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   176,     0,     0,     0,     0,     0,     0,   712,
     713,     0,     0,     0,     0,   269,   714,   715,     0,     0,
       0,   722,     0,     0,     0,     0,   723,  1864,     0,   716,
       0,     0,  1189,   738,   717,   718,     0,   739,     0,  1865,
       0,   719,     0,     0,     0,   740,     0,     0,     0,     0,
       0,  1866,  1867,     0,   724,     0,   741,     0,     0,     0,
    1868,     0,   742,   687,     0,     0,     0,     0,     0,   720,
       0,   272,     0,     0,     0,     0,  2334,  2335,  2336,  2337,
    2338,  2339,  2340,  2341,  2342,  2343,   743,     0,     0,   725,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   726,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   727,
       0,     0,     0,     0,   728,     0,     0,   729,     0,     0,
     744,     0,     0,     0,     0,     0,     0,   745,   730,   746,
       0,     0,     0,     0,   731,     0,     0,     0,     0,   747,
     748,   749,     0,     0,   732,     0,     0,     0,   750,   733,
     721,    82,   734,     0,     0,   735,     0,     0,     0,   272,
       0,     0,     0,     0,   736,   737,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   712,   713,     0,     0,     0,     0,   269,   714,
     715,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1855,   716,     0,     0,     0,   738,   717,   718,     0,
     739,     0,     0,     0,   719,     0,  1856,     0,   740,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   741,
       0,  2106,     0,  1857,     0,   742,  2639,     0,     0,     0,
       0,     0,   720,     0,     0,     0,     0,   722,     0,  1859,
       0,     0,   723,     0,     0,     0,     0,     0,     0,   743,
       0,   712,   713,     0,     0,     0,     0,   269,   714,   715,
       0,     0,     0,     0,     0,     0,     0,  2368,     0,     0,
     724,   716,     0,     0,     0,     0,   717,   718,     0,  2769,
    1861,     0,     0,   719,     0,     0,     0,     0,     0,     0,
       0,     0,  1862,   744,     0,     0,     0,     0,     0,     0,
     745,     0,   746,     0,     0,   725,     0,     0,     0,     0,
       0,   720,   747,   748,   749,     0,     0,   726,     0,     0,
       0,   750,     0,   721,    82,     0,     0,     0,     0,     0,
       0,     0,   272,  1863,     0,   727,     0,     0,     0,  -837,
     728,     0,     0,   729,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   730,     0,     0,     0,     0,     0,
     731,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     732,     0,  1864,     0,     0,   733,     0,     0,   734,     0,
       0,   735,     0,     0,  1865,     0,     0,     0,     0,     0,
     736,   737,  1849,  1850,     0,  1851,  1866,  1867,   269,  1852,
    1853,     0,   721,     0,     0,  1868,  1849,  1850,   687,  1851,
       0,     0,   269,  1852,  1853,     0,   272,  1854,     0,     0,
     722,     0,     0,     0,     0,   723,     0,     0,     0,     0,
       0,  1854,   738,     0,  1849,  1850,   739,  1851,     0,     0,
     269,  1852,  1853,     0,   740,     0,     0,     0,     0,     0,
       0,     0,     0,   724,     0,   741,     0,     0,     0,  1854,
       0,   742,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1849,  1850,     0,  1851,     0,     0,   269,  1852,  1853,
       0,     0,     0,     0,     0,   743,     0,     0,   725,     0,
       0,     0,     0,     0,     0,     0,  1854,     0,     0,   722,
     726,     0,     0,     0,   723,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   727,     0,
       0,     0,     0,   728,     0,     0,   729,  1849,  1850,   744,
    1851,     0,   724,   269,  1852,  1853,   745,   730,   746,     0,
       0,     0,     0,   731,     0,     0,     0,     0,   747,   748,
     749,     0,  1854,   732,     0,     0,     0,   750,   733,     0,
      82,   734,     0,     0,   735,     0,     0,   725,   272,     0,
       0,     0,     0,   736,   737,     0,     0,     0,     0,   726,
       0,     0,     0,     0,     0,     0,  1849,  1850,     0,  1851,
       0,     0,   269,  1852,  1853,     0,     0,   727,     0,     0,
       0,     0,   728,     0,     0,   729,     0,     0,     0,     0,
       0,  1854,     0,     0,  2507,   738,   730,     0,     0,   739,
       0,     0,   731,     0,     0,     0,     0,   740,     0,     0,
       0,     0,   732,     0,     0,     0,     0,   733,   741,     0,
     734,     0,     0,   735,   742,     0,     0,     0,     0,     0,
       0,     0,   736,   737,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   743,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   738,     0,     0,     0,   739,     0,
       0,     0,     0,     0,     0,     0,   740,     0,     0,     0,
       0,     0,   744,     0,     0,     0,     0,   741,     0,   745,
       0,   746,     0,   742,     0,     0,     0,     0,     0,     0,
       0,   747,   748,   749,     0,     0,     0,     0,     0,     0,
     750,     0,     0,    82,     0,     0,  1855,   743,     0,     0,
       0,   272,     0,     0,     0,     0,     0,     0,     0,     0,
    1855,  1856,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1856,     0,     0,  1857,     0,
       0,  1858,     0,     0,     0,     0,     0,     0,  1855,     0,
     203,   744,  1857,     0,  1859,  2768,     0,     0,   745,     0,
     746,     0,     0,  1856,     0,     0,     0,     0,  1859,     0,
     747,   748,   749,     0,     0,     0,     0,   204,   205,   750,
    1857,     0,    82,  2639,     0,  1855,   206,     0,  1905,     0,
     272,     0,     0,     0,  1860,  1861,  1859,     0,     0,     0,
    1856,     0,     0,     0,     0,     0,     0,  1862,  2769,  1861,
       0,     0,     0,     0,     0,     0,     0,  1857,     0,     0,
    1858,  1862,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1859,     0,     0,  2769,  1861,     0,     0,
       0,  1855,     0,     0,     0,     0,     0,     0,  1863,  1862,
       0,     0,     0,     0,     0,     0,  1856,     0,     0,     0,
       0,  2368,  1863,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1857,  1861,     0,  1858,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1862,  1864,     0,  1859,
    1863,  2940,     0,     0,     0,     0,     0,     0,     0,  1865,
    1855,  1864,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1866,  1867,  1865,     0,  1856,     0,     0,     0,     0,
    1868,     0,     0,   687,     0,  1866,  1867,  1863,     0,  1864,
    1861,   272,  1857,     0,  1868,  1858,     0,   687,     0,     0,
       0,  1865,  1862,     0,     0,   272,     0,  2941,  1859,     0,
       0,     0,     0,  1866,  1867,   207,     0,     0,     0,     0,
       0,     0,  1868,     0,     0,   687,  1864,     0,     0,     0,
       0,     0,  2942,   272,     0,     0,     0,     0,  1865,     0,
       0,  2943,     0,  1863,     0,     0,     0,     0,  2973,  1861,
    1866,  1867,     0,     0,   208,     0,     0,     0,     0,  1868,
       0,  1862,   687,     0,     0,     0,     0,     0,     0,     0,
     272,     0,     0,   209,     0,     0,     0,  2944,     0,     0,
    1906,     0,  1864,     0,     0,  2945,     0,     0,     0,   210,
       0,     0,     0,  1907,  1865,     0,     0,     0,     0,     0,
       0,     0,  1863,     0,     0,     0,  1866,  1867,     0,     0,
       0,     0,   211,     0,     0,  1868,     0,     0,   687,     0,
       0,     0,     0,     0,   212,     0,   272,     0,     0,     0,
       0,     0,     0,     0,   213,     0,     0,     0,     0,     0,
       0,  1864,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   214,  1865,     0,     0,     0,  1908,     0,     0,
       0,     0,   215,     0,  1909,  1866,  1867,     0,     0,     0,
       0,     0,     0,     0,  1868,     0,     0,   687,   216,  2946,
       0,     0,     0,     0,     0,   272,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1910,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   217,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1911,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1912,  1913,
       0,     0,   218,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1914,     0,     0,   219,     0,     0,
       0,     0,     0,     0,   220,     0,     0,   221,     0,     0,
       0,     0,     0,     0,     0,  1915,     0,     0,  1916,  1917,
       0,     0,     0,     0,  1918,     0,     0,   222,     0,     0,
     223,     0,   224,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   225,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   226,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1919,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  2947,     0,  1920,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   227
};

static const short yycheck[] =
{
       2,   187,   706,   837,   327,   193,   421,    64,   444,     0,
      12,    13,   855,   977,  1392,   822,  1475,   702,   984,   681,
      82,   520,  1717,   833,   834,   514,   836,   506,   838,   839,
     918,   175,    23,   512,   826,  1442,  1664,   516,    29,  1838,
    2047,    43,    44,  1357,   932,  1721,  1346,   153,  2004,  1668,
    2006,  1289,   541,  1360,  1724,   544,   863,   991,   496,     5,
     117,   362,  1779,  1257,  1258,  1009,   478,  1587,    20,     5,
       5,     5,   503,    64,    76,    60,   387,    79,   264,    18,
      23,   225,    25,    44,    23,    24,    25,    24,   503,    91,
      23,   729,    25,   778,    26,  2223,    98,    23,    24,    25,
       5,   537,   104,   105,     5,  1904,    25,     5,   110,   111,
      95,     5,    46,    23,    48,    25,    50,    24,    54,    26,
    1527,  1659,  1660,     5,    60,  1663,   117,    17,    18,  1536,
      78,   237,   238,    23,    24,    25,  2288,    24,    24,    23,
      24,    25,    23,    24,    25,   507,    23,   149,    25,     5,
     152,   339,    24,    24,    24,   157,   141,   949,    24,   951,
     145,    24,     5,    26,    24,    24,    26,    25,    65,    66,
      24,    24,    40,  1021,    24,     5,    40,     5,     5,     5,
      24,    17,    18,     5,    24,    24,    79,  1599,     5,    25,
      22,   687,   250,    24,     5,   140,  1936,   712,   713,     5,
     112,  2576,     5,   127,  2638,   844,   845,   417,   320,  1638,
     127,   315,  1641,   728,  2177,  2178,  2179,  2180,   922,   734,
     735,    20,   315,   350,   739,    24,  1892,   211,  1055,   365,
    1768,    26,   234,     5,   749,   221,  1855,   485,   240,     6,
       5,   451,   227,     6,   454,  2567,   224,     5,   234,   251,
       5,    69,   140,     5,   464,     5,   434,     5,   468,    20,
      21,   434,   472,     5,    17,    18,     0,  2838,    25,   479,
      23,    24,    25,     5,   484,   434,   486,   153,   315,   367,
       5,   371,   492,   522,     5,   495,     5,    17,   309,   250,
     367,   486,   502,     5,   279,  2887,   281,   507,  1991,   336,
     495,   286,   514,   367,  1997,   515,   363,   364,   552,    70,
      71,    72,    73,    74,    75,  1943,   526,     5,     5,  2768,
     530,   406,  1781,   358,   534,    86,    87,    88,   447,   539,
      24,   366,   542,   113,   114,   595,   455,   401,  2137,   514,
     361,   406,   602,    28,   539,   250,  2404,   542,   433,   593,
     335,   563,   250,   355,    84,   594,   358,   595,  1201,   320,
      30,     5,     0,   414,   366,  2936,   514,   352,   433,   434,
     118,   247,   363,   364,   425,   320,   411,  2005,   210,  2971,
     382,    26,   384,    34,    35,    23,   128,     5,   563,   888,
      17,    18,    19,    20,    21,   643,   447,    17,    18,    19,
      20,    21,  1940,   454,   365,    27,   565,   128,     5,   411,
     537,    62,    63,    64,   416,   563,   418,     6,   596,   421,
     422,     5,   424,   596,   565,   427,  1360,  2555,   360,  1967,
     602,  2387,   320,  2389,   406,  2391,   438,   596,    42,   593,
       5,     5,     9,   445,    11,    12,    13,    14,    15,    16,
     554,     5,  2510,     5,     5,   457,  1160,     5,  2780,   571,
       5,   554,     5,  2001,   225,   467,   452,   228,   470,   447,
       5,     5,     5,     5,     5,     5,  2910,   565,   480,   360,
    2914,   371,   468,     5,  2224,  2225,   544,   259,   565,  2155,
       5,     5,     5,    20,   496,   497,   386,   481,   588,   635,
       5,   503,     5,     5,   259,     5,   338,     5,  1004,   511,
     447,   513,   514,  1028,     5,  2890,   643,   554,     5,   521,
     522,  1036,   524,   525,  1039,   527,  1938,   529,     5,   531,
     325,  2980,   349,   535,   536,   406,   538,  1052,   540,   541,
     371,   543,   544,   365,   546,  1034,   402,  1186,  1063,  1978,
    1065,  1066,   416,  1068,  1069,  1070,  1071,  1072,  1073,  1074,
    1075,  1076,  1077,  1078,  1079,  1080,  1081,  1082,  1083,  1084,
     406,   872,   402,   874,   402,   520,  1007,   501,   490,   515,
    1095,  1096,   463,   544,   501,  1100,   347,  1102,   950,  1027,
    1784,   402,  1007,  1031,  1032,  1033,   402,  1282,  1283,   402,
     367,   362,   367,   841,   367,   366,  1291,   406,   553,   367,
     848,  1438,  1050,  2569,  1441,   367,   826,   367,   371,   526,
    2576,   329,  2774,   571,  2631,   526,  2633,  2755,  2756,  1128,
     602,  2638,   412,   386,   527,   367,  2174,   491,   532,   544,
    1488,  1140,   367,   404,   646,   968,   544,   529,   367,  1334,
     518,   588,  1141,   596,   518,   367,   588,   596,   969,   594,
     594,   228,  1550,   596,   625,   626,   627,   603,   602,   588,
     596,   432,   674,  2407,   676,   636,  2410,   445,   218,   367,
     367,   588,   552,   526,   669,   687,   596,  2643,   596,   561,
     451,   643,   638,  1124,   447,   522,   522,  2235,  2218,   467,
     702,   588,   588,  2502,   588,   602,   596,   588,  1146,  1124,
     712,   713,   596,  1951,   360,   596,   588,  1129,   588,   596,
     477,  2684,   588,   367,   342,   588,   728,  2027,   588,   588,
     588,  1220,   734,   735,  2141,   588,  2050,   739,   588,   949,
     950,   951,  2149,   511,   588,  2052,  2463,   749,   588,   588,
    2467,  1695,   588,   521,   522,  1193,  2432,   525,  1237,   363,
     183,   529,    22,   531,  2434,  1254,  1255,   535,   536,  1407,
     367,   532,  1706,   530,     5,   402,   778,  1213,   367,   430,
     347,  1219,   402,   367,   388,     9,  1224,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,   615,   616,   617,
     618,   619,   367,   367,   246,  2767,  2726,   249,    22,   251,
    2868,   429,  2768,   367,     5,   367,   367,    29,  1006,   367,
     822,   823,   367,  1615,   367,  1759,  2081,   225,   446,   271,
     329,   588,   367,   367,   367,   367,   367,   367,   599,   281,
     307,    53,     5,   596,  2222,   367,    70,    71,    72,    73,
      74,    75,   367,   367,   367,   857,  2551,  2395,   300,  2397,
    2918,   863,   367,   271,   367,   367,   517,   367,   472,   367,
    1369,   489,  1387,   875,   980,   414,   367,   983,   880,   196,
     367,   323,   335,   200,   886,   327,   425,   146,   100,   101,
     367,   103,   104,  2512,   601,   596,   108,  1412,  1413,  1414,
      24,  1416,   904,  2910,  1383,   258,  2964,  2914,  2966,   560,
     528,   335,   406,   125,   126,   601,   918,   624,   271,  2881,
    1605,  2829,  2116,  2831,   414,   135,  2041,  1442,  2043,  2044,
     932,   143,   144,   457,  2890,   425,    13,   623,   624,   557,
     434,   406,   588,  2863,   214,  2573,   470,  2909,   566,   434,
     210,  2750,   375,    17,    18,    19,    20,    21,  1144,  1438,
     564,   497,  1441,   405,   362,   532,   364,   331,   433,   434,
    1804,   540,   576,   577,   543,   406,   526,   546,    90,   135,
     530,   585,   221,   985,   534,   511,    20,   989,   990,   991,
      24,    19,    20,    21,   601,   234,   210,   405,  1487,   452,
     212,   271,  1004,   300,   228,  1007,  1521,  1009,  1010,   406,
    2972,  1013,  1527,   406,   258,   457,   623,   624,  2556,   434,
    1125,  1536,  1127,   490,  2980,  1027,  1028,   271,   452,  1031,
    1032,  1033,  1034,   500,  1036,  1534,  2002,  1039,  2958,  1882,
    2960,  2579,    70,    71,    72,    73,    74,    75,  1050,   406,
    1052,   406,   405,   323,   822,    27,    28,   327,    86,    87,
      88,  1063,   272,  1065,  1066,   401,  1068,  1069,  1070,  1071,
    1072,  1073,  1074,  1075,  1076,  1077,  1078,  1079,  1080,  1081,
    1082,  1083,  1084,  2049,    25,  1723,  1724,  2494,  2996,   857,
     433,   434,  1591,  1095,  1096,   863,   246,  1586,  1100,   249,
    1102,   251,  1740,    24,    25,  1743,   615,   875,   561,   618,
     619,   434,   880,   406,  2809,  2734,   272,  2736,  2052,   406,
     332,   271,  1124,   347,   338,   406,   443,   444,  1130,  1131,
    1132,   281,  1570,  1571,   532,   405,  1280,   561,   348,  1141,
     406,  1143,  1286,  1145,  1146,   509,   616,   617,  1150,   406,
    1942,    17,    18,    19,    20,   414,   280,    24,    25,   523,
     457,   405,   286,   287,   288,    25,   425,   406,   406,   381,
     433,   434,   454,   323,  1966,  2063,  2431,   327,  2433,   342,
     404,  2436,   306,  2438,   548,  1187,   468,   406,   447,  2884,
     472,  1193,   348,   263,   264,   454,   406,   225,   640,  1698,
     228,   413,   484,   602,    70,    71,    72,    73,    74,    75,
    1212,   618,   619,   452,   602,  1217,  1322,  1219,  1220,    25,
     537,  1522,  1224,   457,  2762,  1331,  1228,  1229,  1707,   468,
     547,   842,   843,   597,    25,   846,   847,  1239,  1753,    25,
    1755,  1926,    25,   141,   221,   300,    25,   145,  2626,  1726,
     596,  1253,  1254,  1255,   434,   405,    29,   234,   468,   596,
    1737,  1760,   342,  1762,    25,    38,   429,  1744,    25,   167,
    1480,  1748,  1771,  1750,  1751,  1752,    25,  1279,   625,   626,
    1282,  1283,    25,   446,  1969,  1287,    25,  1289,    25,  1291,
     414,    36,  1954,   417,   589,   590,   591,   592,  2926,   625,
     626,  2839,  1364,   367,   601,   311,   367,   457,   532,   406,
      83,    84,   468,    24,    25,   337,   322,   441,    91,   347,
      86,    87,    88,   620,   621,   596,   489,   100,   101,    25,
     103,   104,  1334,   406,   362,   108,   214,   461,   366,   406,
     402,     5,  1327,   640,  1346,   596,   141,   367,   246,   429,
     145,   249,   125,   126,   578,  1357,    25,   234,  1360,  2166,
     402,   337,  1130,  1131,  1132,   528,   446,   601,   374,  1848,
     143,   144,   496,   271,  2217,   599,   404,  1379,  1380,  1381,
      20,  2759,  1150,   389,  1594,  1387,   620,   621,   367,   706,
      20,   515,   516,   271,   557,   406,   367,    25,  2857,    25,
      25,    25,   457,   566,   432,  1615,   640,   531,    25,   489,
    1412,  1413,  1414,   271,  1416,    20,    24,   596,    26,  1187,
     367,    25,    25,   451,    17,    18,    19,    20,    21,   406,
      70,    71,    72,    73,    74,    75,   753,   141,    25,   342,
    1442,   145,  1444,     5,  1212,   323,   570,   367,   528,   327,
    2416,   246,   588,   435,   249,   643,  1458,   367,   278,   600,
     367,  1229,  3000,   167,     5,   323,   367,   367,   367,   327,
     367,  1239,   367,   479,  1476,   452,   271,   557,  2937,   603,
    1482,   278,  1484,  1485,  1486,  1487,   566,   367,  2422,   600,
     640,   468,   100,   101,   367,   103,   104,  2956,   367,    43,
     108,   367,   596,    24,   532,   342,   246,   405,   434,   249,
     593,   251,   596,     8,  1516,   402,    24,   125,   126,  1521,
      17,    18,    19,    20,    21,  1527,   429,   405,   455,   242,
    1532,   271,   406,   501,  1536,   143,   144,   396,    82,   435,
    1542,   281,   246,   446,   406,   249,   601,   405,  1550,  3008,
     406,  2066,  2959,   406,   406,  1557,   406,  1559,  2057,   406,
     300,    17,    18,    19,    20,   620,   621,   271,  1570,  1571,
     343,   599,   406,    70,    71,    72,    73,    74,    75,   406,
     406,   406,   406,   323,  1586,   640,   489,   327,   132,    86,
      87,    88,   429,   406,   406,   406,   369,   406,    29,   406,
       5,  2100,   406,  1605,   212,   922,   406,   406,   406,   446,
     405,  1613,   342,   406,    70,    71,    72,    73,    74,    75,
     594,   406,  1624,  2138,   168,   528,  2141,   594,  2592,   406,
     406,   571,   396,   435,  2149,  1637,  1638,   635,   406,  1641,
     635,   302,  2485,   342,     8,     5,   420,   572,     5,  2483,
      59,   359,   489,   406,   557,  1657,   406,  1659,  1660,   433,
     406,  1663,  1664,   566,   406,   405,    24,   440,   406,   100,
     101,   406,   103,   104,   320,   565,     8,   108,   554,    13,
     551,    17,    18,    19,    20,     5,   460,   635,  1690,     5,
    1458,   528,   635,  1695,   125,   126,   396,  1699,    25,   429,
     406,   405,   476,   477,  1706,   406,    25,    44,   482,   434,
      69,   485,   143,   144,  1482,  1717,   446,   457,  1486,   434,
     557,   265,   406,    25,   133,   134,  1936,   406,   225,   566,
     429,   228,  1942,     5,    70,    71,    72,    73,    74,    75,
     406,    20,   571,  2428,   111,   596,   565,   446,  1516,   406,
     406,  1753,   447,  1755,   406,    20,  1966,  1759,   602,   489,
     533,  1763,  1764,  1765,  1766,  2203,  1768,  2205,    20,   406,
     406,   602,  1774,  1775,  1542,   406,  1778,  1779,   187,  2194,
    2572,   602,    17,   406,   193,  1787,  2490,   601,   326,   333,
     489,   532,   638,    18,     5,  1797,  2434,   341,   528,    25,
     130,   345,    25,   194,    24,   413,   565,   599,   175,   458,
     177,     9,     5,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,   554,   458,   192,     5,   557,   522,   528,
     128,   522,   375,   200,    25,   297,   566,   204,   382,   522,
      25,   614,  1844,  1160,  1846,   406,   406,   406,   215,   622,
     347,   406,   406,  2696,    24,   264,  1858,   266,   557,   640,
     342,  2704,   229,   596,   552,   362,   367,   566,   522,   366,
      25,   367,    70,    71,    72,    73,    74,    75,   367,   367,
     367,  1883,   367,   367,   367,     5,  2322,  2323,  2324,   367,
    2326,  2327,  2328,  2329,  2330,  2331,  1213,   367,   367,  2335,
     640,   332,   367,   593,   602,     5,   450,   404,     5,     5,
     555,   367,     4,     5,     6,     7,     8,     9,   596,    11,
       5,  2420,   459,   367,  1926,   602,   406,   601,  2443,   406,
     339,  1699,     5,   529,  1991,   432,    92,    25,  1940,    25,
    1997,  1943,   406,   511,  1261,   489,    44,   429,  1950,  1951,
     381,  2450,   301,  1955,   451,  1957,   367,  1959,    70,    71,
      72,    73,    74,    75,   446,  1967,     5,  1969,   367,   513,
     367,   406,   572,   336,   596,   131,  1978,    13,   636,  2494,
     588,   342,  2471,    17,    18,    19,    20,   602,   522,  2478,
     526,  2676,     5,    25,   224,  1763,  1764,  1765,  1766,  2001,
    1991,   447,    78,  2005,   406,  2007,  1997,   489,   596,   559,
    2853,   602,   406,   557,  2224,  2225,  2720,   601,     5,  1787,
     429,    24,   566,   615,   402,  2027,   402,   111,   436,   436,
     228,   367,   406,   406,   317,   532,    70,    71,    72,    73,
      74,    75,   367,   326,   588,     8,   528,     5,  2050,     5,
    2052,   959,   406,   406,   463,   406,   406,    25,  2060,   406,
     469,  2063,   471,    25,  2066,   406,   475,   350,   429,   478,
     353,   367,   481,   602,   367,   557,  1844,   367,   596,     5,
     596,   596,   491,     8,   566,   446,   301,   320,   371,   320,
     434,   175,   596,   177,   406,   336,   320,    17,    18,    19,
      20,   510,   599,    20,  2106,   406,   401,  2109,   192,   518,
     519,   520,  2114,     5,   406,   524,   200,   406,   406,   406,
     204,   406,   396,   532,   627,  2127,  2969,  2129,   489,  2131,
    2940,  2941,  2942,  2943,  2944,  2945,  2138,    25,   547,  2141,
       5,    41,     5,  2145,  2829,   229,  2831,  2149,     5,   347,
      70,    71,    72,    73,    74,    75,    17,    18,    19,    20,
     137,     5,   406,    25,  2166,   571,   593,   528,   571,   367,
       5,   596,  2174,   596,     5,     5,     5,   154,   155,  2181,
    2182,  2183,  2184,  2185,  2186,   162,     7,   406,     5,  1957,
     367,  1959,  2194,    25,   477,   596,   557,  1559,   602,  2698,
      25,  2203,    25,  2205,     8,   566,   404,   367,   367,    70,
      71,    72,    73,    74,    75,   100,   101,   194,   103,   104,
     602,    17,    18,   108,    20,   367,   203,    23,    24,    25,
     602,   367,    25,  2235,    17,    18,    19,    20,  2240,   367,
     125,   126,  1559,   367,   367,   367,    42,   530,   367,    20,
     602,  1613,     5,   250,   537,   232,   602,  2695,   143,   144,
     542,   417,   367,   419,   420,    20,     5,     5,  2591,   522,
      20,     5,   216,   367,   367,   406,   547,   433,   602,  2465,
     434,    39,   416,   596,   367,   406,  2288,    70,    71,    72,
      73,    74,    75,     6,   447,   451,  1613,   706,   454,   602,
     277,  2303,  2304,  2305,   460,    13,     5,   529,   464,  2311,
      13,  2996,   468,   529,   186,    24,   472,    24,  2506,   600,
     476,   477,   602,   479,   600,   595,   482,   212,   484,   485,
     486,    24,   422,   367,   532,    24,   492,    24,  2106,   495,
    1657,  2109,   319,    25,    25,  2844,   502,  1664,    25,    25,
      25,   507,   447,   111,   406,  1717,   406,    25,   272,   515,
     596,  3065,  2572,    25,     5,   367,   775,   367,   244,   501,
     526,  2373,   367,  2375,   530,   275,   444,     5,   534,   406,
     578,   367,   526,   539,  2386,    20,   542,   396,     5,  2391,
     216,   320,   402,  2395,   367,  2397,     5,   367,  2166,   416,
    1717,   599,   320,   117,    20,  1313,  1314,   438,   596,   818,
     186,     5,  1320,    20,   367,    25,   367,   175,   367,   177,
    2422,    25,   367,   832,   833,   834,  2428,   836,     5,   838,
     839,    26,   344,   333,   192,   844,   845,   595,   307,   106,
     349,  2443,   200,   544,  2959,   345,   204,   367,   115,    25,
     217,   367,   367,   602,   406,   355,   406,   124,   522,     5,
     551,  2463,   129,    13,  2466,  2467,   215,   215,    25,  2471,
     417,   229,  2474,   373,   270,   434,  2478,   602,   367,   888,
     423,   368,   406,   383,   367,   596,   386,   602,   602,     5,
     899,   402,  2494,   406,     5,    24,  1858,    20,   217,   399,
     367,     5,  2504,   367,   171,  2144,   367,   367,  3018,  2066,
    1834,  2060,   179,   922,   923,    36,  2518,  1543,  2520,  2521,
    2522,  2523,   931,  1230,    38,   363,  1775,  2127,   413,  1781,
    2532,   145,  1849,  1850,   286,   141,   209,   280,   947,   948,
     395,  1858,  1326,   287,   352,  1327,   211,  2549,   448,  2551,
     370,   212,   315,   314,  2556,   382,   384,  3008,  1516,  1755,
     524,   956,  1765,  2565,  1635,  1002,  1642,  2569,   235,  1486,
    2198,  2573,  1253,  2575,  2576,   371,  2535,  2579,   478,  2581,
    1256,  1566,  3032,  1879,  1769,  1581,  2212,  2712,   488,  2214,
     386,    23,   117,   260,  1146,    29,  2613,  1006,    29,  1548,
     267,   481,   269,   648,    19,    20,   266,   403,   508,  1554,
     406,   511,   279,   513,   676,  2716,   923,  1261,  1526,  1240,
    1557,  2610,   418,   419,  2794,    29,  1943,  1137,  1184,  2956,
    2804,  1597,   875,  1127,  2362,  2637,  2182,  2639,   305,  1212,
    1059,   541,  2360,  2005,  2344,  1013,   313,  1056,  2000,  2651,
     550,   447,  1759,  1363,  1562,    70,    71,    72,    73,    74,
      75,  2575,  1936,  3036,   460,  1340,  3000,  1970,  2894,  2001,
     826,  2394,  1663,  2416,  2676,  2676,   472,  2373,  2680,  2007,
    2682,  1279,  2429,   350,  2375,   952,  2633,  2017,  2005,  2821,
    2007,  2305,  2841,  2695,  2840,  2754,   100,   101,  2700,   103,
     104,  2998,  2240,  2739,   108,  1275,  2474,  2236,  1117,   376,
    2879,   948,  1695,  2565,  1142,   361,  1125,   513,  1127,  1128,
    1129,   125,   126,    -1,    -1,    -1,    -1,  1136,  1137,    -1,
    2047,  1140,    -1,    -1,    -1,  1144,  2504,  2739,  1147,   143,
     144,    -1,  2744,    -1,    -1,    -1,    -1,   414,    -1,    -1,
      -1,  1160,    -1,    -1,    -1,    -1,   552,    -1,   425,    -1,
    2762,    -1,    -1,    -1,  2532,    -1,  2768,    -1,   564,    -1,
      96,    -1,  2774,    -1,    -1,    -1,    -1,  1186,    -1,    -1,
     576,   577,   578,    -1,  2786,    -1,    -1,    -1,    -1,   585,
      -1,    -1,   588,   949,   950,   951,    -1,    -1,    -1,    -1,
     596,    -1,    -1,    -1,    -1,    -1,    -1,  2809,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1226,    -1,  2181,
    2182,  2183,  2184,  2185,  2186,    -1,    -1,  2829,    -1,  2831,
      -1,    -1,  2834,    -1,    -1,    -1,    -1,  2839,    -1,  2841,
    1249,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,  1260,  1261,    -1,    -1,    -1,    -1,   524,   525,   526,
      -1,    -1,    -1,    -1,  2181,  2182,  2183,  2184,  2185,  2186,
     537,   197,    -1,    -1,    -1,    -1,    -1,  2879,  2240,   205,
      -1,    -1,  2884,    -1,  2886,   211,    -1,   213,  2890,    -1,
      -1,    -1,  2894,    -1,    -1,    -1,    -1,    -1,   224,    70,
      71,    72,    73,    74,    75,    -1,  1315,    -1,    -1,    -1,
      -1,  2913,    -1,    -1,    -1,    86,    87,    88,    -1,    76,
    1828,  1829,    -1,  2240,  2926,     7,   252,    -1,    -1,    -1,
      -1,  1839,  2700,    -1,    -1,    17,    18,    19,    20,    -1,
      -1,    -1,   268,    -1,    -1,    -1,    -1,   273,    -1,  2951,
    2952,    -1,    -1,    -1,    -1,    -1,    -1,  2959,    -1,   285,
    1369,    -1,    -1,    -1,    -1,    -1,   292,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   641,    -1,    -1,    -1,  2980,    -1,
    1888,  1889,  1890,  1891,    -1,    -1,    -1,    -1,    70,    71,
      72,    73,    74,    75,  2996,  1903,  2998,    -1,  3000,    -1,
      -1,    -1,    -1,    -1,    -1,  2322,  2323,  2324,    -1,  2326,
    2327,  2328,  2329,  2330,  2331,    -1,    -1,    -1,  2335,    -1,
      -1,    -1,    -1,    -1,  2386,    -1,    -1,    -1,    -1,  2391,
      -1,    -1,    -1,    -1,  3036,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    -1,    -1,    -1,    -1,    -1,  3051,
      -1,    -1,    -1,    -1,   225,    -1,  2373,   228,  2375,    14,
      15,    16,    17,    18,    19,    20,    21,    -1,    -1,  2386,
      -1,  1979,  1980,    -1,  2391,    -1,    -1,    -1,  1986,  1987,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1243,    -1,    -1,
      -1,    -1,    70,    71,    72,    73,    74,    75,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1514,    -1,    -1,    86,    87,
      88,    -1,    -1,    -1,  1523,    70,    71,    72,    73,    74,
      75,   447,    -1,    -1,    -1,  1534,    -1,    -1,   454,    -1,
      -1,    86,    87,    88,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1554,    -1,    -1,    -1,    -1,
     476,   308,    -1,    -1,    -1,   481,  2518,    -1,  2520,  2521,
    2522,  2523,    -1,    -1,   321,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  2490,    -1,    -1,   347,    -1,    -1,    -1,
      -1,    -1,  1591,  2951,  1593,    -1,    -1,    -1,  1597,  2551,
      -1,   362,    -1,    -1,    -1,   366,    -1,    -1,    -1,    -1,
      -1,  2518,    -1,  2520,  2521,  2522,  2523,  2569,    -1,  2117,
    2118,    -1,    -1,    -1,  2576,    -1,    -1,    -1,  2126,    -1,
    1629,    -1,    -1,    -1,    -1,    -1,  2134,    -1,   385,    -1,
      -1,    -1,    -1,   404,  2551,   392,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  2152,  2153,    -1,   225,    -1,    -1,
     228,    -1,  2569,    -1,    -1,    -1,  2573,    -1,    -1,  2576,
      -1,   432,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     225,    -1,    -1,   228,   431,  2637,    -1,  2639,    -1,    -1,
     451,    -1,    -1,  3051,    -1,    -1,    -1,    -1,    -1,  1698,
      -1,    -1,    -1,    -1,    -1,    -1,  2204,    -1,  2206,   456,
      -1,    -1,    -1,    -1,    -1,  2213,    -1,  2215,    -1,   466,
     467,    -1,    22,    -1,  2631,    -1,  2633,    -1,    -1,    -1,
    2637,  2638,  2639,    -1,  1480,   482,    -1,    -1,    -1,    -1,
      40,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   503,    -1,    -1,   506,
     507,  1760,    -1,  1762,    -1,   512,    -1,    -1,    -1,    69,
      -1,   532,  1771,    70,    71,    72,    73,    74,    75,   347,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  2739,    -1,    86,
      87,    88,  2744,    -1,   362,    -1,    -1,    -1,   366,    -1,
      -1,    -1,   347,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1809,   111,    -1,  2720,  2312,  2313,  2768,   362,  2316,  2317,
      -1,   366,   569,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  2739,    -1,   581,    -1,   404,  2744,   599,  1838,
      -1,   141,    -1,    -1,    -1,   145,    -1,    -1,  1594,    -1,
      -1,    -1,  2350,    -1,    -1,    -1,    -1,  2809,    -1,   404,
      -1,  2768,    -1,    -1,   432,    -1,    -1,   167,    -1,  1615,
      -1,    -1,    -1,    -1,    -1,   175,    -1,   177,    -1,    -1,
      -1,    -1,  2834,   451,    -1,    -1,   186,   432,    -1,    -1,
      -1,    -1,   192,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     200,    -1,  2809,    -1,   204,    -1,   451,    -1,    -1,    -1,
     210,    -1,    -1,    -1,   214,   215,   216,   217,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  2834,   225,   229,
      -1,   228,  2884,    -1,  2886,    -1,    -1,    -1,  2890,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   246,    -1,  1694,   249,
      -1,   251,    -1,    -1,    -1,    -1,    -1,    -1,   258,    -1,
      -1,  2913,    -1,    -1,   532,    -1,  2464,    -1,    -1,    -1,
    2468,   271,    -1,    -1,    -1,    -1,    -1,  2884,  1977,  2886,
      -1,   281,    -1,  2890,    -1,    -1,    -1,   532,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     300,   301,  2500,  2910,    -1,    -1,  2913,  2914,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   315,    -1,    -1,    -1,  2926,
      -1,    -1,    -1,   323,    -1,    -1,    -1,   327,  2980,    -1,
      -1,   599,    -1,    -1,    -1,  2533,   336,   337,   338,    15,
      16,    17,    18,    19,    20,    21,  2998,    -1,    -1,    -1,
     347,    -1,    -1,    -1,   599,    -1,    -1,    -1,  2057,    -1,
      -1,    -1,    -1,    -1,    -1,   362,    -1,    -1,    -1,   366,
      -1,    -1,    -1,  2980,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  3036,    -1,    -1,    -1,    -1,    -1,
      -1,  2998,    -1,    -1,    70,    71,    72,    73,    74,    75,
      -1,  2100,    -1,    -1,    -1,   405,    -1,   404,    -1,    -1,
      86,    87,    88,    -1,    -1,    -1,   416,  1863,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  3036,
      -1,    -1,    -1,    -1,  2133,   432,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  2142,    -1,  2144,    -1,  2146,    21,    -1,
      -1,    -1,    -1,    -1,   451,    -1,    -1,   457,  3065,  2158,
      -1,    -1,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    -1,
      -1,  1927,    -1,    17,    18,    19,    20,    -1,    -1,    -1,
    1936,    -1,    26,    -1,    -1,    -1,  1942,    70,    71,    72,
      73,    74,    75,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    86,    87,    88,    -1,    -1,   518,    -1,
    1966,    -1,    -1,    -1,    -1,    -1,    -1,    70,    71,    72,
      73,    74,    75,  2731,    -1,   532,    70,    71,    72,    73,
      74,    75,    -1,    86,    87,    88,    -1,    -1,    -1,   225,
      -1,    -1,   228,    -1,   554,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  2023,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   601,   599,    -1,    -1,    -1,    -1,  2306,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   615,   616,   617,   618,   619,
     620,   621,    -1,   623,   624,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     640,    70,    71,    72,    73,    74,    75,  2346,    -1,    -1,
      -1,    -1,   225,    -1,    -1,   228,    -1,    86,    87,    88,
    2359,    -1,    -1,    -1,    -1,    -1,  2864,    -1,    -1,    -1,
      -1,   347,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   225,    -1,    -1,   228,   362,    -1,    -1,    -1,
     366,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  2899,  2900,    -1,  2902,    -1,  2904,  2905,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  2420,   256,    -1,    -1,    -1,    -1,    -1,   404,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  2450,    -1,    -1,    -1,    -1,   432,    -1,    -1,    -1,
      -1,    -1,   296,   297,   298,    -1,  2465,    -1,    -1,    -1,
    2968,    -1,    -1,    -1,   347,   451,    -1,    -1,  2224,  2225,
      -1,    -1,    -1,    -1,    -1,    -1,  2984,   321,  2986,   362,
      -1,  2490,    -1,   366,    -1,   329,   225,    -1,    -1,   228,
     334,    -1,    -1,    -1,   347,    -1,    -1,  2506,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   349,    -1,    -1,    -1,   362,
     354,    -1,   356,   366,    -1,  3023,    -1,    -1,    -1,   363,
      -1,   404,   366,    -1,    -1,   369,    -1,    -1,   372,    -1,
      -1,   375,    -1,    -1,    -1,    -1,   380,  3045,  3046,    -1,
      -1,  3049,    -1,    -1,    -1,    -1,   532,    -1,    -1,   432,
      -1,   404,    -1,    -1,   398,    -1,    -1,    -1,  2567,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   451,    -1,
     414,    -1,    -1,   417,   418,    -1,    -1,    -1,    -1,   432,
     424,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   435,    -1,    -1,    -1,    -1,    -1,    -1,   451,    -1,
      -1,  2610,    -1,    -1,    -1,    -1,    -1,   451,   347,    -1,
      -1,    -1,  2368,   599,   458,    -1,    -1,    -1,    -1,    -1,
      -1,   465,    -1,   362,   468,   469,   470,   366,   472,   473,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   489,    -1,    -1,    -1,   532,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   404,    -1,    -1,   512,   513,
     514,   515,    -1,   517,    -1,    -1,    -1,    -1,    -1,   532,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2698,
     534,   535,    -1,   432,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  2715,  2716,    -1,    -1,
      -1,  2720,   451,   557,    -1,    -1,   599,    -1,    -1,    -1,
      -1,    -1,   566,   567,    -1,   569,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   599,    -1,    -1,    29,
      -1,    -1,    32,    33,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  2519,    -1,    45,    -1,    47,    -1,    -1,
      -1,  2780,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    61,    -1,    -1,    -1,  2794,    -1,   631,    68,    -1,
    2799,    -1,  2801,   532,    -1,    -1,    -1,    -1,    -1,    79,
      80,    81,  2558,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    95,  2572,    97,    98,    99,
     100,   101,   102,   103,   104,   105,    -1,   107,   108,   109,
     110,  2840,    -1,    -1,    -1,  2844,   116,    -1,    -1,   119,
      -1,   121,   122,   123,    -1,   125,   126,    -1,    -1,    -1,
      -1,   131,    -1,   133,   134,    -1,   136,    -1,   138,   139,
     599,    -1,   142,   143,   144,    -1,    -1,   147,   148,   149,
      -1,   151,   152,    -1,    -1,    -1,   156,   157,    -1,   159,
      -1,    -1,    -1,   163,    -1,   165,   166,    -1,    -1,   169,
      -1,    -1,    -1,   173,    -1,    -1,   176,    -1,   178,    -1,
     180,    -1,   182,    -1,   184,   185,    -1,   187,   188,   189,
      -1,    -1,    -1,   193,    -1,   195,   196,    -1,   198,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   206,   207,    -1,    -1,
      -1,  2940,  2941,  2942,  2943,  2944,  2945,    -1,    -1,   219,
      -1,    -1,   222,   223,    -1,    -1,   226,   227,    -1,    -1,
     230,   231,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   239,
     240,   241,    -1,   243,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   253,   254,   255,    -1,   257,    -1,    -1,
      -1,   261,   262,    -1,    -1,    -1,   266,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   274,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   282,   283,   284,    -1,    -1,    -1,    -1,    -1,
     290,   291,    -1,    -1,    -1,    -1,   296,    -1,    -1,   299,
      -1,    -1,    -1,   303,   304,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   314,    -1,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,   332,    -1,    -1,    -1,  3065,    -1,    -1,    -1,
     340,    -1,    -1,    -1,    -1,    -1,   346,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    -1,    -1,    -1,    -1,    -1,    -1,   369,
      -1,    -1,    -1,    -1,    -1,    -1,   376,    -1,   378,   379,
      70,    71,    72,    73,    74,    75,    -1,   387,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    86,    87,    88,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    70,    71,    72,    73,    74,    75,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   426,    86,    87,    88,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   437,    -1,    -1,
      -1,   441,    -1,    -1,    -1,   445,    -1,    -1,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    -1,    -1,    -1,    -1,    -1,   469,
     470,    -1,    -1,    -1,   474,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   486,    -1,    -1,    -1,
      -1,    -1,   492,   493,   494,   495,    -1,    -1,   498,    -1,
      -1,    -1,   502,    -1,    -1,    -1,    -1,    -1,    -1,   509,
     510,    -1,    70,    71,    72,    73,    74,    75,    -1,    -1,
      -1,   521,    -1,   523,    -1,    -1,    -1,    -1,    86,    87,
      88,    -1,    -1,    -1,   534,   225,   536,    -1,   228,   539,
      -1,    -1,    -1,    -1,    -1,   545,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   225,    -1,    -1,   228,
      -1,   571,    -1,    -1,   574,    -1,    -1,    -1,    -1,    -1,
     580,    -1,    -1,   583,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   598,    -1,
      -1,    -1,    -1,    -1,    -1,   605,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   628,   629,
     630,   631,   632,   633,   634,    -1,    -1,   637,    -1,   639,
      -1,   641,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   347,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   225,    -1,    -1,
     228,    -1,   362,    -1,    -1,    -1,   366,   367,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   347,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   362,    -1,    -1,    -1,   366,   367,    -1,
      -1,    -1,    -1,    -1,   404,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   432,    -1,    -1,   404,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   451,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   432,    -1,    -1,    -1,    -1,    -1,    70,
      71,    72,    73,    74,    75,    -1,    -1,    -1,    -1,   347,
      -1,    -1,   451,    -1,    -1,    86,    87,    88,    -1,    -1,
      -1,    -1,    -1,    -1,   362,    -1,    -1,    -1,   366,   367,
      -1,    -1,    -1,    -1,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   532,    -1,    -1,    -1,   404,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   532,   432,    -1,    -1,    -1,    70,    71,
      72,    73,    74,    75,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   451,    86,    87,    88,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   599,
      -1,    70,    71,    72,    73,    74,    75,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    86,    87,    88,
      -1,    -1,    -1,    -1,   225,    -1,    -1,   228,    -1,    -1,
     599,    -1,    -1,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   532,    -1,    -1,    -1,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    70,    71,    72,
      73,    74,    75,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    86,    87,    88,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   225,    -1,    -1,   228,    -1,    -1,    -1,
      -1,   599,    70,    71,    72,    73,    74,    75,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   347,    -1,    86,    87,
      88,    -1,    -1,    -1,    -1,    -1,   225,    -1,    -1,   228,
      -1,   362,    -1,    -1,    -1,   366,   367,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   404,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   432,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   347,    -1,    -1,    -1,    -1,
     451,    -1,   225,    -1,    -1,   228,    -1,    -1,    -1,    -1,
     362,    -1,    -1,    -1,   366,   367,    -1,    -1,    70,    71,
      72,    73,    74,    75,    -1,    -1,    -1,    -1,   347,    -1,
      -1,    -1,    -1,    -1,    86,    87,    88,   225,    -1,    -1,
     228,    -1,    -1,   362,    -1,    -1,    -1,   366,   367,    -1,
      -1,    -1,   404,    -1,    -1,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     432,   532,    -1,    -1,    -1,   404,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   451,
      -1,    -1,    -1,    17,    18,    -1,    20,    -1,    -1,    23,
      24,    25,    -1,   432,    -1,    -1,    -1,    70,    71,    72,
      73,    74,    75,    -1,   347,    -1,    -1,    -1,    42,    -1,
      -1,    -1,   451,    86,    87,    88,    -1,    -1,    -1,   362,
      -1,    -1,    -1,   366,   367,    -1,    -1,    -1,   599,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   347,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   225,   362,    -1,   228,    -1,   366,   367,
     532,   404,    -1,    -1,    -1,    -1,     5,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   432,
      -1,    -1,    -1,   532,    -1,    -1,   404,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   451,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    -1,    -1,    -1,   432,    -1,    -1,   599,    70,    71,
      72,    73,    74,    75,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   451,    86,    87,    88,    -1,    -1,    -1,
      -1,    -1,   225,    -1,    -1,   228,    -1,    -1,    -1,    -1,
     599,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    70,
      71,    72,    73,    74,    75,   347,    -1,    -1,    -1,    16,
      17,    18,    19,    20,    21,    86,    87,    88,    -1,   532,
     362,    -1,    -1,    -1,   366,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   532,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   404,    70,    71,    72,    73,    74,    75,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    86,
      87,    88,    -1,    -1,    -1,    -1,   599,    -1,    -1,    -1,
     432,    -1,    -1,    -1,    70,    71,    72,    73,    74,    75,
      -1,    -1,    -1,    -1,   347,    -1,    -1,    -1,    -1,   451,
      86,    87,    88,   225,    -1,    -1,   228,    -1,    -1,   362,
      -1,   599,    -1,   366,    -1,    -1,    -1,   236,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    17,    18,    -1,    -1,    -1,    -1,    23,
      24,    25,    26,    -1,   225,    -1,    -1,   228,    -1,    -1,
      -1,   404,    -1,    37,    -1,    -1,   275,   371,    42,    43,
      -1,    -1,    -1,    -1,    -1,    49,    -1,    -1,    -1,    -1,
      -1,    -1,   386,    -1,    -1,   294,    -1,    -1,    -1,   432,
     532,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   403,
      -1,    -1,   406,    77,    -1,    -1,    -1,    -1,   451,    -1,
      -1,    -1,    -1,    -1,    -1,   419,    -1,    -1,   225,    17,
      18,   228,    20,    -1,   333,    23,    24,    25,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   347,   345,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    42,    -1,   355,    -1,    -1,   225,
     362,    -1,   228,    -1,   366,    -1,   460,   599,    -1,    -1,
      -1,    -1,    -1,    -1,   373,    -1,    -1,    -1,   472,    -1,
      -1,    -1,    -1,    -1,   383,    -1,   347,    -1,    17,    18,
      -1,    -1,    -1,    -1,    23,    24,    25,    26,    -1,   532,
     399,   362,   404,    -1,   168,   366,    -1,    -1,    37,    -1,
      -1,    -1,    -1,    42,    43,    -1,    -1,    -1,    -1,   513,
      49,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     432,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     439,    -1,    -1,   404,    -1,    -1,    -1,    -1,    77,   451,
     347,    -1,   546,    -1,    -1,    -1,    -1,    -1,   552,    -1,
      -1,    -1,    -1,    -1,   463,   362,   599,   561,   562,   366,
     564,   432,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   478,
      -1,   347,   576,   577,    -1,    -1,   485,    -1,    -1,   488,
     451,   585,    -1,    -1,   588,    -1,   362,    -1,    -1,    -1,
     366,   265,   596,    -1,    -1,    -1,   270,   404,    -1,   508,
      -1,    -1,   511,    -1,   513,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     532,    -1,    -1,   532,   298,   432,    -1,    -1,   404,   168,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   550,    17,    18,   451,    20,    -1,    -1,    23,    24,
      25,    -1,    -1,    -1,    -1,    -1,   432,    -1,    -1,   333,
      -1,   532,    -1,    -1,    -1,    -1,    -1,    42,    -1,    -1,
      -1,   345,   270,    51,    52,   451,    -1,    55,    56,    57,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   599,    -1,   363,
      -1,    -1,    -1,    -1,   368,    -1,    -1,   371,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   382,    -1,
      -1,    -1,    -1,    -1,   388,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   398,   532,   265,    -1,   599,   403,
      -1,   270,   406,    -1,    -1,   409,    -1,    -1,    -1,    -1,
      17,    18,    -1,    -1,   418,   419,    23,    24,    25,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   532,    -1,    -1,   298,
      37,    -1,    -1,    -1,    -1,    42,    43,    -1,    -1,    -1,
      -1,    -1,    49,   371,    -1,    -1,    -1,   155,    -1,    -1,
      -1,    -1,    -1,    -1,   162,   459,   460,    -1,   386,    -1,
     464,    -1,   599,    -1,   333,    -1,    -1,    -1,   472,    -1,
      77,    -1,    -1,    -1,    -1,   403,   345,    -1,   406,   483,
      -1,    -1,    -1,    -1,    -1,   489,   194,    -1,    -1,    -1,
     418,   419,    -1,   599,   363,   203,    -1,    -1,    -1,   368,
      -1,    -1,   371,    -1,    -1,    -1,    -1,    -1,   236,   513,
      -1,    -1,    -1,   382,    -1,    -1,    -1,    -1,    -1,   388,
      -1,    -1,    -1,    -1,   232,   233,    -1,    -1,    -1,   398,
      -1,    -1,   460,    -1,   403,    -1,    -1,   406,    -1,    -1,
     409,    -1,    -1,    -1,   472,    -1,    -1,   275,    -1,   418,
     419,    -1,    -1,   557,    -1,    -1,    -1,    -1,    -1,    -1,
     564,   168,   566,    -1,    -1,   270,   294,    -1,    -1,   277,
      -1,    -1,   576,   577,   578,    -1,    -1,    -1,    -1,    -1,
      -1,   585,    -1,    -1,   588,   513,    -1,    -1,    -1,    -1,
      -1,   460,   596,    17,    18,   464,    -1,    -1,    -1,    23,
      24,    25,    -1,   472,    -1,   333,    -1,    -1,    -1,    -1,
      -1,   319,    -1,    37,   483,    -1,    -1,   345,    42,    43,
     489,    -1,    -1,    -1,   552,    49,    -1,   355,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   564,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   513,   373,    -1,    -1,   576,   577,
     578,    -1,    -1,    77,    -1,   383,    -1,   585,   265,    -1,
     588,    -1,    -1,   270,    -1,    -1,   371,   375,   596,    -1,
      -1,   399,    -1,    -1,    -1,    -1,    -1,    17,    18,    -1,
      20,   386,    -1,    23,    24,    25,    -1,    -1,   557,    -1,
      -1,   298,    -1,    -1,    -1,   564,    -1,   566,   403,    -1,
      -1,   406,    42,    -1,    -1,    -1,    -1,   576,   577,   578,
      -1,   439,    -1,   418,   419,    -1,   585,    -1,    -1,   588,
      -1,    -1,    -1,    -1,    -1,    -1,   333,   596,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   463,    -1,    -1,   345,    -1,
      -1,    -1,    -1,    -1,   168,    -1,    -1,    -1,    -1,    -1,
     478,    -1,    -1,    -1,    -1,   460,   363,   485,    -1,    -1,
     488,   368,    -1,    -1,   371,    -1,    -1,   472,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   382,    -1,    -1,    -1,    -1,
     508,   388,    -1,   511,    -1,   513,    -1,    -1,    -1,    -1,
      -1,   398,    -1,    -1,    -1,    -1,   403,    -1,    -1,   406,
      -1,    -1,   409,    -1,   532,    -1,    -1,    -1,   513,    -1,
      -1,   418,   419,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   550,    -1,    -1,    -1,    -1,    -1,    -1,    17,
      18,    -1,    -1,    -1,    -1,    23,    24,    25,    -1,    -1,
      -1,   265,    -1,    -1,    -1,    -1,   270,   552,    -1,    37,
      -1,    -1,   459,   460,    42,    43,    -1,   464,    -1,   564,
      -1,    49,    -1,    -1,    -1,   472,    -1,    -1,    -1,    -1,
      -1,   576,   577,    -1,   298,    -1,   483,    -1,    -1,    -1,
     585,    -1,   489,   588,    -1,    -1,    -1,    -1,    -1,    77,
      -1,   596,    -1,    -1,    -1,    -1,   604,   605,   606,   607,
     608,   609,   610,   611,   612,   613,   513,    -1,    -1,   333,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   345,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   363,
      -1,    -1,    -1,    -1,   368,    -1,    -1,   371,    -1,    -1,
     557,    -1,    -1,    -1,    -1,    -1,    -1,   564,   382,   566,
      -1,    -1,    -1,    -1,   388,    -1,    -1,    -1,    -1,   576,
     577,   578,    -1,    -1,   398,    -1,    -1,    -1,   585,   403,
     168,   588,   406,    -1,    -1,   409,    -1,    -1,    -1,   596,
      -1,    -1,    -1,    -1,   418,   419,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    17,    18,    -1,    -1,    -1,    -1,    23,    24,
      25,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   371,    37,    -1,    -1,    -1,   460,    42,    43,    -1,
     464,    -1,    -1,    -1,    49,    -1,   386,    -1,   472,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   483,
      -1,   485,    -1,   403,    -1,   489,   406,    -1,    -1,    -1,
      -1,    -1,    77,    -1,    -1,    -1,    -1,   265,    -1,   419,
      -1,    -1,   270,    -1,    -1,    -1,    -1,    -1,    -1,   513,
      -1,    17,    18,    -1,    -1,    -1,    -1,    23,    24,    25,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   447,    -1,    -1,
     298,    37,    -1,    -1,    -1,    -1,    42,    43,    -1,   459,
     460,    -1,    -1,    49,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   472,   557,    -1,    -1,    -1,    -1,    -1,    -1,
     564,    -1,   566,    -1,    -1,   333,    -1,    -1,    -1,    -1,
      -1,    77,   576,   577,   578,    -1,    -1,   345,    -1,    -1,
      -1,   585,    -1,   168,   588,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   596,   513,    -1,   363,    -1,    -1,    -1,   367,
     368,    -1,    -1,   371,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   382,    -1,    -1,    -1,    -1,    -1,
     388,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     398,    -1,   552,    -1,    -1,   403,    -1,    -1,   406,    -1,
      -1,   409,    -1,    -1,   564,    -1,    -1,    -1,    -1,    -1,
     418,   419,    17,    18,    -1,    20,   576,   577,    23,    24,
      25,    -1,   168,    -1,    -1,   585,    17,    18,   588,    20,
      -1,    -1,    23,    24,    25,    -1,   596,    42,    -1,    -1,
     265,    -1,    -1,    -1,    -1,   270,    -1,    -1,    -1,    -1,
      -1,    42,   460,    -1,    17,    18,   464,    20,    -1,    -1,
      23,    24,    25,    -1,   472,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   298,    -1,   483,    -1,    -1,    -1,    42,
      -1,   489,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    17,    18,    -1,    20,    -1,    -1,    23,    24,    25,
      -1,    -1,    -1,    -1,    -1,   513,    -1,    -1,   333,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    42,    -1,    -1,   265,
     345,    -1,    -1,    -1,   270,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   363,    -1,
      -1,    -1,    -1,   368,    -1,    -1,   371,    17,    18,   557,
      20,    -1,   298,    23,    24,    25,   564,   382,   566,    -1,
      -1,    -1,    -1,   388,    -1,    -1,    -1,    -1,   576,   577,
     578,    -1,    42,   398,    -1,    -1,    -1,   585,   403,    -1,
     588,   406,    -1,    -1,   409,    -1,    -1,   333,   596,    -1,
      -1,    -1,    -1,   418,   419,    -1,    -1,    -1,    -1,   345,
      -1,    -1,    -1,    -1,    -1,    -1,    17,    18,    -1,    20,
      -1,    -1,    23,    24,    25,    -1,    -1,   363,    -1,    -1,
      -1,    -1,   368,    -1,    -1,   371,    -1,    -1,    -1,    -1,
      -1,    42,    -1,    -1,   459,   460,   382,    -1,    -1,   464,
      -1,    -1,   388,    -1,    -1,    -1,    -1,   472,    -1,    -1,
      -1,    -1,   398,    -1,    -1,    -1,    -1,   403,   483,    -1,
     406,    -1,    -1,   409,   489,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   418,   419,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   513,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   460,    -1,    -1,    -1,   464,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   472,    -1,    -1,    -1,
      -1,    -1,   557,    -1,    -1,    -1,    -1,   483,    -1,   564,
      -1,   566,    -1,   489,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   576,   577,   578,    -1,    -1,    -1,    -1,    -1,    -1,
     585,    -1,    -1,   588,    -1,    -1,   371,   513,    -1,    -1,
      -1,   596,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     371,   386,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   386,    -1,    -1,   403,    -1,
      -1,   406,    -1,    -1,    -1,    -1,    -1,    -1,   371,    -1,
      31,   557,   403,    -1,   419,   406,    -1,    -1,   564,    -1,
     566,    -1,    -1,   386,    -1,    -1,    -1,    -1,   419,    -1,
     576,   577,   578,    -1,    -1,    -1,    -1,    58,    59,   585,
     403,    -1,   588,   406,    -1,   371,    67,    -1,    76,    -1,
     596,    -1,    -1,    -1,   459,   460,   419,    -1,    -1,    -1,
     386,    -1,    -1,    -1,    -1,    -1,    -1,   472,   459,   460,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   403,    -1,    -1,
     406,   472,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   419,    -1,    -1,   459,   460,    -1,    -1,
      -1,   371,    -1,    -1,    -1,    -1,    -1,    -1,   513,   472,
      -1,    -1,    -1,    -1,    -1,    -1,   386,    -1,    -1,    -1,
      -1,   447,   513,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   403,   460,    -1,   406,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   472,   552,    -1,   419,
     513,   179,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   564,
     371,   552,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   576,   577,   564,    -1,   386,    -1,    -1,    -1,    -1,
     585,    -1,    -1,   588,    -1,   576,   577,   513,    -1,   552,
     460,   596,   403,    -1,   585,   406,    -1,   588,    -1,    -1,
      -1,   564,   472,    -1,    -1,   596,    -1,   235,   419,    -1,
      -1,    -1,    -1,   576,   577,   236,    -1,    -1,    -1,    -1,
      -1,    -1,   585,    -1,    -1,   588,   552,    -1,    -1,    -1,
      -1,    -1,   260,   596,    -1,    -1,    -1,    -1,   564,    -1,
      -1,   269,    -1,   513,    -1,    -1,    -1,    -1,   459,   460,
     576,   577,    -1,    -1,   275,    -1,    -1,    -1,    -1,   585,
      -1,   472,   588,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     596,    -1,    -1,   294,    -1,    -1,    -1,   305,    -1,    -1,
     308,    -1,   552,    -1,    -1,   313,    -1,    -1,    -1,   310,
      -1,    -1,    -1,   321,   564,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   513,    -1,    -1,    -1,   576,   577,    -1,    -1,
      -1,    -1,   333,    -1,    -1,   585,    -1,    -1,   588,    -1,
      -1,    -1,    -1,    -1,   345,    -1,   596,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   355,    -1,    -1,    -1,    -1,    -1,
      -1,   552,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   373,   564,    -1,    -1,    -1,   385,    -1,    -1,
      -1,    -1,   383,    -1,   392,   576,   577,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   585,    -1,    -1,   588,   399,   407,
      -1,    -1,    -1,    -1,    -1,   596,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   431,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   439,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   456,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   466,   467,
      -1,    -1,   463,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   482,    -1,    -1,   478,    -1,    -1,
      -1,    -1,    -1,    -1,   485,    -1,    -1,   488,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   503,    -1,    -1,   506,   507,
      -1,    -1,    -1,    -1,   512,    -1,    -1,   508,    -1,    -1,
     511,    -1,   513,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   532,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   550,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   569,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   579,    -1,   581,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   593
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const unsigned short yystos[] =
{
       0,    29,    53,   100,   101,   103,   104,   108,   125,   126,
     143,   144,   212,   332,   381,   413,   702,   728,   729,   779,
     944,   999,  1001,  1002,  1003,  1008,  1010,  1023,  1024,  1025,
    1026,  1027,  1426,    27,    28,   703,   704,   705,   706,   707,
     907,   911,   331,   509,   523,   548,   597,  1427,  1427,  1427,
    1427,  1427,  1427,  1427,  1427,   907,    24,   907,  1371,  1028,
     730,   729,  1426,     0,  1000,  1003,  1008,  1026,  1426,    30,
     705,   707,    26,  1445,   907,  1429,   565,   907,  1428,   602,
     780,    24,   588,   727,   728,   895,   907,   914,  1029,  1065,
    1066,  1067,  1068,  1069,  1073,   329,   732,   733,   734,   735,
     738,   739,    38,    83,    84,    91,   343,   369,   440,   533,
     614,   622,   702,   708,   867,   943,  1004,  1005,  1007,  1011,
    1012,  1018,  1030,  1051,  1182,  1192,  1426,   912,   907,  1428,
     593,  1068,   218,   433,   434,  1074,    20,   907,  1072,   911,
     733,     5,   731,   329,   907,     5,   755,   757,   758,  1193,
     907,   907,  1183,  1019,   907,   907,  1007,  1013,   236,   275,
     294,   333,   345,   355,   373,   383,   399,   439,   463,   478,
     485,   488,   508,   511,   513,   532,   550,   781,   782,   783,
     786,    24,  1065,  1071,    17,    18,    25,   406,   652,   654,
    1065,  1075,  1076,   434,   596,    13,   778,   735,   497,  1169,
     736,   733,   738,    31,    58,    59,    67,   236,   275,   294,
     310,   333,   345,   355,   373,   383,   399,   439,   463,   478,
     485,   488,   508,   511,   513,   532,   550,   593,   741,   749,
     760,   761,   907,   406,    90,   907,   727,   868,  1052,   907,
     788,   511,   740,   764,   766,   767,   765,   774,   775,   406,
     406,   787,   434,   406,   406,   733,   762,   401,   652,    17,
      18,    19,    20,    21,   653,    25,     5,   402,  1075,    23,
      24,    25,   596,   915,    18,    24,    25,   737,   915,   751,
     740,   752,   764,   765,   406,   406,   750,   434,   406,   406,
     762,   733,   759,   406,    25,   907,   406,  1020,   727,   727,
     406,   907,   406,   433,   744,   602,   342,   429,   446,   489,
     528,   557,   566,   768,   602,   342,   429,   446,   489,   528,
     557,   566,   776,    25,    25,   789,   790,   791,   792,   907,
      25,   747,   748,    25,    25,   596,   367,   652,  1076,   434,
     402,    25,    25,   733,   744,   733,    25,    25,   732,   747,
      25,    25,   596,    36,   756,  1194,   367,   406,  1184,  1446,
    1447,  1448,  1449,  1450,   869,  1053,  1014,   596,    25,   769,
     770,   406,   771,   776,   777,   771,   406,   772,     5,   367,
       5,   367,     5,   259,     5,   781,   402,     5,     5,   367,
     367,   733,   763,  1075,   596,    25,   234,     5,   367,     5,
     367,   259,   402,     5,   367,   367,   763,   907,  1081,  1082,
    1084,  1031,  1081,   337,  1447,  1169,    32,    33,    45,    47,
      61,    68,    79,    80,    81,    95,    97,    98,    99,   102,
     105,   107,   109,   110,   116,   119,   121,   122,   123,   131,
     133,   134,   136,   138,   139,   142,   147,   148,   149,   151,
     152,   156,   157,   159,   163,   165,   166,   169,   173,   176,
     178,   180,   182,   184,   185,   187,   188,   189,   193,   195,
     196,   198,   206,   207,   219,   222,   223,   226,   227,   230,
     231,   239,   240,   241,   243,   253,   254,   255,   257,   261,
     262,   266,   274,   282,   283,   284,   290,   291,   296,   299,
     303,   304,   314,   332,   340,   346,   376,   378,   379,   387,
     426,   437,   441,   445,   469,   470,   474,   486,   492,   493,
     494,   495,   498,   502,   509,   510,   521,   523,   534,   536,
     539,   545,   571,   574,   580,   583,   598,   605,   628,   629,
     630,   631,   632,   633,   634,   637,   639,   641,   645,   646,
     647,   648,   665,   687,   701,   702,   708,   709,   726,   794,
     795,   796,   797,   808,   809,   810,   811,   859,   863,   893,
     917,   918,   921,   922,   923,   924,   937,   945,   968,   969,
     971,   975,   990,   991,   995,   996,   997,   998,  1006,  1021,
    1034,  1045,  1046,  1047,  1058,  1061,  1097,  1100,  1102,  1108,
    1109,  1112,  1115,  1118,  1120,  1122,  1124,  1131,  1136,  1140,
    1141,  1153,  1154,  1157,  1163,  1164,  1165,  1190,  1205,  1206,
    1207,  1208,  1209,  1219,  1220,  1221,  1239,  1242,  1281,  1282,
    1372,  1373,  1402,  1403,  1410,  1426,  1430,  1435,  1437,  1439,
    1443,  1444,  1451,   702,  1009,  1426,   601,   624,  1054,  1055,
    1081,    20,   367,   401,   745,   768,    25,   773,    25,    25,
      25,   790,   792,   784,   748,    25,   402,    20,   745,   406,
      25,    25,   742,    25,   596,   367,     5,  1081,   367,   907,
     908,   911,   907,   902,   908,   902,    24,   588,   907,  1094,
    1421,  1422,  1423,   907,  1441,   907,  1215,  1216,   907,    25,
     649,  1065,  1212,   902,   907,  1138,   837,    25,   915,  1177,
    1178,  1177,    17,    18,    24,    25,    37,    42,    43,    49,
      77,   168,   265,   270,   298,   333,   345,   363,   368,   371,
     382,   388,   398,   403,   406,   409,   418,   419,   460,   464,
     472,   483,   489,   513,   557,   564,   566,   576,   577,   578,
     585,   812,   819,   820,   821,   822,   823,   824,   825,   826,
     838,   843,   854,   855,   856,   857,   907,   915,  1065,  1172,
    1241,  1363,   908,  1411,  1411,   798,  1138,   902,  1210,  1065,
     904,   908,   819,  1411,  1065,  1138,  1065,  1240,  1411,    24,
     561,  1048,  1049,  1065,   902,   902,  1048,   903,   908,   907,
    1049,   902,  1411,   902,   904,  1065,  1095,  1096,   900,   908,
     904,   350,   537,   643,   899,   907,   970,   907,   710,   905,
     908,  1421,  1062,   837,   908,  1121,   864,   106,   115,   124,
     129,   171,   179,   235,   260,   267,   269,   279,   305,   313,
     350,   376,   414,   425,   524,   525,   526,   537,   641,   982,
    1116,  1117,  1065,   818,   819,  1130,   814,   837,   899,  1436,
    1436,   901,   908,   837,    24,  1065,  1119,  1191,  1065,  1168,
      24,  1065,  1405,   819,  1159,  1160,  1161,  1170,  1171,   819,
    1431,    43,    82,   132,   168,   265,   341,   382,   450,   513,
     666,   843,   907,  1065,  1200,   689,   819,   900,  1428,  1035,
     819,   900,   819,  1065,   992,   900,   819,   819,  1177,   907,
     919,   920,   904,   919,  1436,   904,   919,  1436,   925,   919,
      24,    25,   360,   463,   915,   973,  1065,  1083,  1085,    44,
     250,   320,   365,   544,   625,   626,   627,   636,   656,   927,
     929,   931,   933,   935,  1059,  1060,  1064,   311,   322,   374,
     389,   479,  1283,   616,   617,   871,   872,   873,   907,  1056,
     623,  1055,   367,   278,   367,   367,   367,   367,   600,     5,
     367,   278,   733,   753,   754,   367,   367,   600,   367,   907,
    1195,  1084,   367,  1185,    34,    35,    62,    63,    64,   430,
     517,   560,  1222,  1223,  1224,  1227,  1230,  1233,  1234,  1235,
    1236,   325,   909,  1445,   596,  1423,   434,   593,  1113,   596,
       8,   514,   563,     5,   367,   402,    24,   907,  1357,   455,
    1139,  1083,    86,    87,    88,   812,   812,   406,   501,  1189,
     406,   406,   406,   406,   406,   406,   406,   406,   406,   406,
     812,   342,   429,   446,   489,   528,   557,   566,  1366,  1367,
     406,   406,   406,   812,   812,   406,   406,   812,   406,   827,
     406,   406,   406,   406,   406,   406,   406,   812,   406,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    70,    71,    72,    73,    74,
      75,    86,    87,    88,   225,   228,   347,   362,   366,   404,
     432,   451,   532,   599,   725,   813,   828,   830,   831,   832,
     833,   834,   835,   836,    25,   915,   406,   396,  1065,  1090,
    1357,   655,   656,   801,   242,    65,    66,   602,   435,     5,
     595,   602,   594,   594,  1098,   571,   396,     5,   532,   946,
     435,   635,  1433,   406,   434,   596,   635,   360,   712,  1065,
     522,   594,  1103,  1104,  1105,   302,  1280,   818,   817,   819,
       8,   901,    25,   477,   530,   894,  1065,   894,   894,   894,
     987,   988,   894,   894,   572,   983,   656,   983,   983,   895,
     895,   983,   983,   656,     5,   309,   361,     5,   655,   459,
     815,   816,   819,     5,    54,    60,   515,   603,   976,   638,
    1434,   818,   589,   590,   591,   592,  1167,  1169,   359,  1204,
    1169,  1161,     5,   594,  1162,   819,   406,   406,   406,   406,
     406,    24,   685,   907,   406,  1405,   320,   406,   565,   554,
     690,   697,   688,    24,  1050,  1065,  1155,     8,  1158,    13,
     907,  1070,  1077,  1078,  1080,  1088,  1089,  1132,   140,   320,
     520,   553,   551,     5,   635,   635,   817,  1083,  1090,   972,
     396,     5,   128,   950,   406,  1065,   817,   406,    25,    25,
      44,  1063,    24,  1065,  1409,  1409,   901,  1121,   901,    96,
     197,   205,   211,   213,   224,   252,   268,   273,   285,   292,
     447,   454,   476,   481,  1243,  1253,  1254,  1262,  1271,  1272,
    1278,  1279,  1284,  1285,  1294,  1312,  1316,  1383,  1384,  1412,
    1413,  1416,  1417,   874,   875,    69,   870,   881,   882,   873,
    1057,  1446,  1015,   434,   781,   748,   434,     5,   367,   755,
     727,  1032,   727,   135,   272,   348,   406,   468,  1300,  1311,
     406,   907,  1238,    25,   221,   234,   406,   452,   468,   907,
    1218,  1232,  1298,  1299,  1304,  1306,  1308,   406,   907,  1229,
     406,  1218,  1225,     5,   406,   912,  1423,  1075,  1421,   552,
     593,  1114,    20,   907,  1094,  1424,   907,  1442,  1216,   571,
     596,   565,   406,   406,   801,   899,   812,   841,   899,   899,
     899,  1436,   447,  1387,   812,    24,    25,    24,    25,   812,
     406,   602,   899,    20,   812,   367,  1387,   371,   858,  1065,
      20,  1172,   846,   844,   850,   812,   848,   812,   812,   812,
     812,   812,   812,   812,   812,   812,   812,   812,   812,   812,
     812,   812,   812,   812,   812,   812,   812,   812,   406,   812,
     812,   406,   839,  1065,   602,   406,  1421,    24,   914,  1137,
    1137,  1405,  1048,   819,   819,   819,   896,   897,   406,  1065,
    1096,   762,   947,   948,   602,  1405,  1436,  1434,   907,   652,
      20,   643,   907,   970,  1065,   711,   601,   819,   326,  1107,
     532,  1106,     5,    46,    48,    50,   594,   602,   793,  1083,
     865,    17,    18,    24,   280,   286,   287,   288,   306,   414,
     417,   441,   461,   496,   515,   516,   531,   570,   603,   989,
     984,  1117,   895,   819,   320,   571,     5,   899,    25,    25,
     655,   130,  1166,   194,  1171,  1177,  1432,   675,   907,    24,
     899,  1436,   565,   899,   599,  1065,   670,   907,   819,   315,
     693,   697,   554,   691,   699,    22,   210,  1037,  1041,   458,
     837,   458,  1156,   819,   433,  1074,   911,     5,   993,   522,
    1133,  1065,   938,   920,  1436,  1436,   930,   931,   950,   950,
     246,   249,   251,   271,   281,   323,   327,   405,   457,   640,
     949,   951,   952,   978,  1065,  1085,   522,   657,    25,   375,
     936,   297,  1404,  1404,   113,   114,   412,   522,   907,  1313,
    1314,  1358,   762,  1357,  1357,  1255,   762,   907,  1414,  1414,
     335,   452,   561,  1395,  1357,  1263,   146,   414,   425,   447,
     454,  1287,  1288,  1289,   263,   264,  1378,  1446,  1446,   360,
     883,  1065,   618,   619,   876,   877,   878,   457,   601,   620,
     621,   640,   886,   887,  1446,   727,    25,   746,   746,   754,
    1196,   727,  1186,  1302,  1357,  1237,  1311,   406,  1237,   406,
     406,  1231,  1232,   406,   406,    41,   275,   333,   345,   355,
     373,   383,   386,   399,   448,   478,   488,   508,   511,   513,
     541,   550,  1349,  1350,  1351,  1353,  1228,  1229,  1225,  1226,
     640,  1223,    24,   910,  1068,   596,   402,  1405,   552,   522,
    1440,   650,   651,   907,   907,   907,  1213,   837,   367,   682,
     683,   684,   812,   367,   367,   367,   367,  1395,   367,   367,
     367,   367,   565,   367,   367,   565,   367,    25,   342,   429,
     446,   489,   528,   557,   566,  1368,   367,   367,   367,   367,
       5,  1367,   367,     5,   367,   812,   812,   812,   367,   812,
     367,   367,   367,   837,  1387,   837,  1387,   682,   907,  1211,
     593,  1110,   602,     5,     5,     5,   555,   819,   596,     5,
     459,   602,   367,   402,   406,   601,   141,   145,   246,   249,
     713,   716,   717,   978,   714,   715,   907,   406,   908,   625,
     626,  1111,   819,   907,   907,   897,   898,   485,  1436,   801,
     529,  1268,    25,    25,   406,   985,   987,  1065,   511,  1125,
     815,    44,   812,  1169,    25,  1065,  1446,   682,   367,     5,
     367,   367,   686,   907,   367,  1405,   682,   406,   698,   694,
     336,   692,   819,   315,   695,   699,   572,   980,  1042,  1038,
     338,  1036,  1037,   817,   602,  1071,   596,  1089,    13,    17,
      18,    20,    24,    25,    42,   371,   386,   403,   406,   419,
     459,   460,   472,   513,   552,   564,   576,   577,   585,   907,
     915,  1134,  1135,  1362,  1364,  1399,  1422,  1425,  1446,   932,
     933,   526,   906,   522,   899,   966,   899,   967,   959,   958,
     956,   955,   979,   414,   425,   962,   963,   414,   425,   964,
     965,   300,   952,   957,  1436,    76,   308,   321,   385,   392,
     431,   456,   466,   467,   482,   503,   506,   507,   512,   569,
     581,   658,   659,     5,    25,  1405,   224,   447,  1388,  1389,
    1405,  1121,  1382,  1384,    78,    78,   571,  1119,  1315,  1316,
     406,  1295,   127,   501,  1320,  1327,  1357,   153,   247,  1418,
     596,   602,  1396,  1397,  1399,   559,   317,   326,   350,   353,
     371,   477,   530,   537,   901,  1265,  1270,   406,  1290,   601,
       5,    24,   907,  1379,  1380,   885,  1065,     5,   522,   879,
     880,   615,   878,   884,   907,   884,   888,   889,   884,   300,
     887,  1016,   402,   402,   436,  1179,  1199,  1033,   436,  1142,
    1173,   406,     5,   367,   270,   406,   418,   578,  1330,  1331,
    1332,  1333,  1334,  1335,  1342,  1345,  1347,  1394,  1399,   367,
     907,  1301,  1303,  1357,  1360,  1305,  1360,     5,   367,  1305,
    1330,   342,   429,   446,   489,   528,   557,   566,  1369,  1369,
     406,   406,   406,   406,   406,   406,   183,   375,  1307,  1309,
       5,   367,     5,   367,   907,   367,  1424,     8,  1405,   819,
       5,  1217,  1218,   837,  1022,   842,     5,  1396,   852,  1367,
     852,    25,   853,  1367,   853,    25,  1189,   367,   406,  1189,
    1367,   602,  1367,  1189,   847,   845,   851,  1189,   849,  1189,
    1189,  1189,   812,   829,   367,   829,   367,   840,   596,  1217,
     552,  1405,  1405,   819,   819,   896,   485,   819,  1438,     5,
      20,  1360,   948,  1405,   596,   907,   714,   722,   721,   723,
     907,   913,   724,   913,   167,   717,   720,     5,   950,   596,
     819,     8,   907,  1269,   866,   986,   987,  1065,     5,   301,
     676,  1201,   320,   320,   434,   596,   320,   406,   671,   668,
    1446,  1446,   700,   696,   692,   981,    24,   906,  1043,  1065,
    1446,   819,   401,    20,   907,  1079,   837,    25,   915,    25,
     915,  1365,  1369,  1399,   406,   406,   911,   406,   406,   406,
     406,   406,     5,    17,    18,    19,    20,    70,    71,    72,
      73,    74,    75,  1419,   396,    40,   518,   939,   934,   935,
      25,   655,   907,     5,   953,     5,   954,  1446,  1446,  1446,
    1446,   985,     5,   961,     5,   960,  1446,   906,     5,   367,
      25,  1357,   911,  1376,   571,   571,  1254,  1381,  1382,  1316,
    1296,  1360,   593,   901,  1330,   406,  1258,   907,  1415,  1414,
       5,  1385,   256,   296,   297,   298,   321,   329,   334,   349,
     354,   356,   363,   366,   369,   372,   375,   380,   398,   414,
     417,   418,   424,   435,   451,   458,   465,   468,   469,   470,
     472,   473,   489,   512,   513,   514,   515,   517,   534,   535,
     557,   566,   567,   569,   631,   916,  1445,    20,   406,  1245,
    1246,  1247,  1248,  1249,  1360,   819,   819,  1264,   901,  1291,
    1360,  1357,  1289,   596,   596,     5,     5,  1065,   884,  1446,
    1446,     5,   891,   892,  1446,  1446,   890,  1009,   785,   743,
      51,    52,    55,    56,    57,   155,   162,   194,   203,   232,
     233,   277,   319,   375,   604,   605,   606,   607,   608,   609,
     610,   611,   612,   613,  1176,  1180,   112,   490,  1181,  1197,
    1009,   137,   154,   155,   162,   194,   203,   232,   277,   319,
    1174,  1175,  1187,  1181,  1303,  1311,   406,  1394,   447,  1330,
    1399,  1394,  1333,     6,   367,     7,     9,    11,    12,    13,
      14,    15,    16,   228,   347,   532,  1346,   404,   578,   599,
    1344,  1346,   434,  1359,   367,     5,   911,     5,   367,  1232,
     367,   367,   602,   406,   602,    25,  1355,  1355,    25,  1355,
    1355,    25,  1354,    24,  1362,  1310,  1311,  1229,  1225,  1405,
       8,   651,     5,   367,   817,   367,   367,   684,   522,  1321,
    1326,   602,   367,   602,   367,    25,   602,  1368,   602,   367,
     367,   367,   367,     5,   367,   367,   367,    20,   367,  1405,
       5,   819,   542,   250,   660,   661,   819,    20,   907,   367,
     950,  1446,  1446,     5,   718,   434,   596,     5,   719,  1446,
     715,   522,    20,   907,     5,   907,  1101,   365,   635,  1065,
    1086,  1087,  1446,     5,   367,   906,   812,   367,   682,  1065,
     667,   649,   907,  1065,   673,   367,   682,  1446,  1446,   985,
    1040,    24,  1044,  1065,   547,   862,   434,   459,   818,   994,
     602,   367,   371,  1360,  1420,   335,   452,   561,  1348,   406,
    1348,  1348,  1348,  1348,  1399,  1400,  1135,  1399,  1399,  1399,
    1399,  1422,   941,   940,   416,   926,   927,   596,   899,  1446,
     899,  1446,   963,  1446,   965,  1446,   655,   659,   367,   406,
    1406,  1395,  1378,  1382,  1382,  1374,     5,   367,   447,  1393,
    1259,  1360,   455,  1256,  1393,   602,  1397,   529,  1392,    13,
    1248,  1250,   127,   501,  1244,     5,    13,   529,  1266,     5,
     367,   602,   907,   907,  1380,  1065,   907,  1446,  1446,  1446,
    1446,   600,   600,  1177,  1177,  1177,    24,  1177,  1177,  1177,
    1177,  1177,  1177,    24,    24,  1177,  1180,  1065,  1091,  1092,
     595,   422,  1143,  1446,    24,    24,    25,    25,    25,    25,
      25,    24,  1065,  1175,  1143,   367,   911,   367,  1331,  1332,
    1399,   406,  1394,   406,  1394,   225,   362,   364,   532,   406,
     546,   561,   562,  1336,  1337,  1338,  1394,  1399,    25,  1300,
    1360,   596,  1360,   342,   429,   446,   489,   528,   557,   566,
    1370,    25,  1370,     5,  1352,  1352,     5,   367,   367,  1352,
     367,  1310,  1405,  1218,   244,  1214,   491,  1322,  1323,  1324,
    1357,  1327,   307,   490,   500,  1273,  1390,  1368,   852,  1368,
     853,   367,  1368,  1368,   812,   444,   800,     5,   349,  1405,
       5,   406,   367,   526,   977,   913,  1446,   652,    20,   907,
     913,  1446,  1436,   819,  1436,   396,     5,   216,   987,   655,
     320,   680,  1202,  1083,   402,   682,   672,   367,  1446,   906,
     819,   860,  1075,  1370,     5,  1369,     5,   367,  1399,   911,
    1399,  1399,  1399,  1399,     5,   367,   819,  1446,   928,   929,
      20,   907,  1407,  1408,  1396,  1377,  1375,  1378,  1360,   911,
     117,  1297,     5,   367,  1257,  1415,  1086,  1386,   406,   459,
    1251,  1252,  1394,  1399,     5,   367,   901,  1330,  1249,  1252,
    1267,  1360,   438,  1292,  1293,  1358,   596,   186,  1017,   781,
     755,   514,   563,  1093,     5,  1091,    39,   111,   175,   177,
     192,   200,   204,   229,  1144,  1145,  1198,  1017,  1188,  1395,
    1343,  1362,  1401,  1343,  1399,  1340,  1401,  1394,     5,   402,
      20,   907,   367,    25,  1356,   367,   367,    25,   367,   406,
    1324,     5,   907,  1361,   344,  1318,  1328,   907,  1391,   595,
    1348,   307,   899,   655,   349,  1405,   819,   662,   544,  1099,
      25,   655,   402,   977,   367,  1065,  1087,  1123,  1083,   367,
     406,   674,   680,   669,  1039,  1446,   402,  1369,   602,  1369,
     367,  1400,   367,   367,   367,   367,  1399,   551,   906,     5,
     367,  1392,  1378,  1378,  1395,  1360,   406,  1326,  1251,  1399,
       5,  1248,    13,  1086,     5,   118,  1286,   907,  1092,  1146,
    1147,  1065,  1149,  1065,  1148,  1150,  1145,   215,   215,  1396,
       5,   367,   367,     7,   417,  1339,    25,  1359,   602,   367,
    1323,  1325,  1323,  1319,  1398,  1399,   423,  1317,  1329,  1214,
      25,  1274,  1275,  1276,  1360,  1388,  1391,   799,  1405,   368,
     179,   235,   260,   269,   305,   313,   407,   579,   659,   663,
     664,   406,   596,   655,   978,  1126,  1127,  1128,  1203,   677,
     367,   680,  1446,   861,   602,  1370,   602,   367,   942,   974,
    1408,  1326,  1396,   459,  1260,  1261,  1399,  1390,   367,  1252,
     406,  1293,  1446,  1446,  1151,  1446,  1152,  1446,  1446,  1326,
    1401,  1399,  1341,  1401,   402,  1370,     5,   367,     5,  1330,
       5,   514,   563,  1277,  1214,   323,   327,   802,   803,   804,
     978,   894,   894,   894,   894,   894,   894,    24,     5,   367,
     819,    20,   907,  1129,   258,  1128,   680,   682,   680,   217,
    1370,  1370,  1446,   655,  1390,  1326,     5,   367,  1251,  1446,
    1446,   367,  1323,  1398,  1275,   806,   805,   214,   804,   807,
     664,     5,  1446,   678,   939,  1261,   367,  1446,  1446,  1446,
     819,   367,   367,   679,   140,   320,   681,  1083
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
#line 873 "fgl.yacc"
    { print_screen_mode(0);}
    break;

  case 3:
#line 876 "fgl.yacc"
    { print_screen_mode(1);}
    break;

  case 4:
#line 880 "fgl.yacc"
    {
		print_start_server(yyvsp[-3].str,yyvsp[0].str);
	}
    break;

  case 5:
#line 886 "fgl.yacc"
    {
	print_stop_external();
	}
    break;

  case 6:
#line 891 "fgl.yacc"
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
#line 903 "fgl.yacc"
    {
	sprintf(yyval.str,"%s%s",yyvsp[-2].str,yyvsp[0].str);
	}
    break;

  case 10:
#line 908 "fgl.yacc"
    {
	print_remote_func(yyvsp[0].str);
	sprintf(yyval.str,"unregister_func(\"%s\",aclfgl_%s);\n",yyvsp[0].str,yyvsp[0].str);
	addmap("Call Remote",yyvsp[0].str,curr_func,yylineno,infilename);
	}
    break;

  case 11:
#line 926 "fgl.yacc"
    {sprintf(yyval.str,"(%s)",yyvsp[-1].str);}
    break;

  case 12:
#line 927 "fgl.yacc"
    { sprintf(yyval.str,"%s%s%s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 13:
#line 928 "fgl.yacc"
    {sprintf(yyval.str,"%d",atoi(yyvsp[0].str));}
    break;

  case 14:
#line 929 "fgl.yacc"
    {sprintf(yyval.str,"(%s%s)",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 15:
#line 930 "fgl.yacc"
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
#line 944 "fgl.yacc"
    {strcpy(yyval.str,"+");}
    break;

  case 17:
#line 945 "fgl.yacc"
    {strcpy(yyval.str,"-");}
    break;

  case 18:
#line 946 "fgl.yacc"
    {strcpy(yyval.str,"*");}
    break;

  case 19:
#line 947 "fgl.yacc"
    {strcpy(yyval.str,"/");}
    break;

  case 20:
#line 948 "fgl.yacc"
    {strcpy(yyval.str,"%");}
    break;

  case 21:
#line 953 "fgl.yacc"
    {strcpy(yyval.str,"+");}
    break;

  case 22:
#line 954 "fgl.yacc"
    {strcpy(yyval.str,"-");}
    break;

  case 23:
#line 965 "fgl.yacc"
    {
		debug("Using default attribute of WHITE");
		sprintf(yyval.str,"%d",0);}
    break;

  case 24:
#line 968 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 25:
#line 971 "fgl.yacc"
    {start_state("attribute",1);}
    break;

  case 26:
#line 971 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[-1].str);
debug("Got Attributes : %s",yyvsp[-1].str);
start_state("attribute",0);
}
    break;

  case 28:
#line 978 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 29:
#line 979 "fgl.yacc"
    {
sprintf(yyval.str,"%d",atoi(yyvsp[-2].str)|atoi(yyvsp[0].str));
}
    break;

  case 30:
#line 985 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("BLACK"));}
    break;

  case 31:
#line 986 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("BLUE"));}
    break;

  case 32:
#line 987 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("CYAN"));}
    break;

  case 33:
#line 988 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("GREEN"));}
    break;

  case 34:
#line 989 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("MAGENTA"));}
    break;

  case 35:
#line 990 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("RED"));}
    break;

  case 36:
#line 991 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("WHITE"));}
    break;

  case 37:
#line 992 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("YELLOW"));}
    break;

  case 38:
#line 993 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("REVERSE"));}
    break;

  case 39:
#line 994 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("BLINK"));}
    break;

  case 40:
#line 995 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("UNDERLINE"));}
    break;

  case 41:
#line 996 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("BOLD"));}
    break;

  case 42:
#line 997 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("NORMAL"));}
    break;

  case 43:
#line 998 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("INVISIBLE"));}
    break;

  case 44:
#line 999 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("DIM"));}
    break;

  case 45:
#line 1000 "fgl.yacc"
    {inp_flags=inp_flags | 0x1; strcpy(yyval.str,"0");}
    break;

  case 48:
#line 1007 "fgl.yacc"
    {
debug("win_attributes_def");
start_state("attribute",1);
debug("Started states");
form_attrib.attrib=0;}
    break;

  case 49:
#line 1011 "fgl.yacc"
    {start_state("attribute",0);strcpy(yyval.str,"");
}
    break;

  case 50:
#line 1015 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 51:
#line 1016 "fgl.yacc"
    {sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 52:
#line 1020 "fgl.yacc"
    { 
/*printf("Window attribute = %s\n",$<str>1);*/
form_attrib.attrib      =form_attrib.attrib|atoi(yyvsp[0].str);
/*printf("Window attribute = %d\n",form_attrib.attrib);*/
}
    break;

  case 53:
#line 1026 "fgl.yacc"
    { form_attrib.border      =1;}
    break;

  case 54:
#line 1028 "fgl.yacc"
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
#line 1039 "fgl.yacc"
    { form_attrib.comment_line=atoi(yyvsp[0].str); }
    break;

  case 56:
#line 1041 "fgl.yacc"
    { form_attrib.form_line   =atoi(yyvsp[0].str); }
    break;

  case 57:
#line 1043 "fgl.yacc"
    { form_attrib.error_line  =atoi(yyvsp[0].str); }
    break;

  case 58:
#line 1045 "fgl.yacc"
    { form_attrib.menu_line   =atoi(yyvsp[0].str); 
debug("Set menu line to %s",yyvsp[0].str);
}
    break;

  case 59:
#line 1049 "fgl.yacc"
    { form_attrib.message_line=atoi(yyvsp[0].str); }
    break;

  case 60:
#line 1051 "fgl.yacc"
    { form_attrib.prompt_line =atoi(yyvsp[0].str); }
    break;

  case 61:
#line 1112 "fgl.yacc"
    {strcpy(yyval.str,"CALL");}
    break;

  case 62:
#line 1116 "fgl.yacc"
    { debug("print_expr (3)"); 
		print_expr(yyvsp[-2].ptr);
		print_pop_variable(yyvsp[0].str);
	}
    break;

  case 63:
#line 1120 "fgl.yacc"
    {
	print_getfldbuf(yyvsp[-2].str);
	}
    break;

  case 64:
#line 1123 "fgl.yacc"
    {
	print_returning();
}
    break;

  case 65:
#line 1127 "fgl.yacc"
    {
	print_form_is_compiled(yyvsp[-1].str);
	}
    break;

  case 66:
#line 1131 "fgl.yacc"
    {
	print_field_func('I',yyvsp[-3].str,yyvsp[0].str);
   }
    break;

  case 68:
#line 1135 "fgl.yacc"
    { 
	print_field_func('T',yyvsp[-3].str,yyvsp[0].str);
     }
    break;

  case 69:
#line 1138 "fgl.yacc"
    {
	new_counter();
   	addmap("Call",yyvsp[-3].str,curr_func,yylineno,infilename);
   }
    break;

  case 70:
#line 1144 "fgl.yacc"
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
#line 1153 "fgl.yacc"
    {
	print_returning();
	strcpy(yyval.str,yyvsp[-4].str); /* ? */
   }
    break;

  case 72:
#line 1157 "fgl.yacc"
    {
	new_counter();
   	addmap("Call",yyvsp[-1].str,curr_func,yylineno,infilename);
   }
    break;

  case 73:
#line 1162 "fgl.yacc"
    {
	debug("Got args");
   }
    break;

  case 74:
#line 1166 "fgl.yacc"
    {
	int a;
	dump_expr(yyvsp[-2].ptr);
	a=get_counter_val();
	drop_counter();
  	print_func_call(yyvsp[-5].str,yyvsp[-2].ptr,a);
   }
    break;

  case 75:
#line 1174 "fgl.yacc"
    {
	print_returning();
	strcpy(yyval.str,yyvsp[-3].str); /* ? */
   }
    break;

  case 76:
#line 1178 "fgl.yacc"
    {
	A4GLSQL_set_status(0,0);
	new_counter();
	}
    break;

  case 77:
#line 1182 "fgl.yacc"
    {
   sprintf(yyval.str,"%d",get_counter_val());drop_counter();
}
    break;

  case 78:
#line 1185 "fgl.yacc"
    {
        print_expr ((struct expr_str *)yyvsp[-3].ptr);  
	print_call_shared(yyvsp[-6].str,yyvsp[-8].str,atoi(yyvsp[-2].str));
	print_returning();
	print_end_call_shared();
}
    break;

  case 79:
#line 1191 "fgl.yacc"
    {
	sprintf(yyval.str,"\"%s\",\"%s\"",get_idents(0),get_idents(1));
	A4GLSQL_set_status(0,0);
	new_counter();
	}
    break;

  case 80:
#line 1196 "fgl.yacc"
    {
   	sprintf(yyval.str,"%d",get_counter_val());drop_counter();
}
    break;

  case 81:
#line 1199 "fgl.yacc"
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
#line 1215 "fgl.yacc"
    {
   char buff[256];
   new_counter();
   sprintf(buff,"%s:%s(%p)",yyvsp[-6].str,yyvsp[-4].str,yyvsp[-2].str);
   addmap("External",buff,curr_func,yylineno,infilename);
   }
    break;

  case 83:
#line 1222 "fgl.yacc"
    {
   sprintf(yyval.str,"%d",get_counter_val());drop_counter();
   }
    break;

  case 84:
#line 1226 "fgl.yacc"
    {
	 debug("print_expr (6)");print_expr(yyvsp[-2].ptr);
   }
    break;

  case 85:
#line 1230 "fgl.yacc"
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
#line 1252 "fgl.yacc"
    {start_bind('i',0);strcpy(yyval.str,"0");}
    break;

  case 87:
#line 1252 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);
}
    break;

  case 88:
#line 1256 "fgl.yacc"
    {start_bind('i',0);strcpy(yyval.str,"0");}
    break;

  case 89:
#line 1257 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 90:
#line 1258 "fgl.yacc"
    {strcpy(yyval.str,"WITHOUT WAITING"); }
    break;

  case 91:
#line 1263 "fgl.yacc"
    {
			yyval.ptr=new_expr("");
		}
    break;

  case 92:
#line 1266 "fgl.yacc"
    {
			yyval.ptr=yyvsp[0].ptr;
		}
    break;

  case 93:
#line 1272 "fgl.yacc"
    {
	yyval.ptr=yyvsp[0].ptr;
}
    break;

  case 94:
#line 1275 "fgl.yacc"
    {
		yyval.ptr=append_expr_expr(yyvsp[-2].ptr,yyvsp[0].ptr);
}
    break;

  case 97:
#line 1287 "fgl.yacc"
    {
sprintf(yyval.str,"\"%s\"",yyvsp[0].str);
}
    break;

  case 98:
#line 1293 "fgl.yacc"
    {
sprintf(yyval.str,"\"%s\"",yyvsp[0].str);
}
    break;

  case 99:
#line 1296 "fgl.yacc"
    { sprintf(yyval.str,"\"%s.%s\"",yyvsp[-2].str,yyvsp[0].str); }
    break;

  case 100:
#line 1311 "fgl.yacc"
    {
push_blockcommand("CASE");
setinc(1);
incprint();
print_case(1);
setinc(1);
}
    break;

  case 101:
#line 1321 "fgl.yacc"
    {
print_after_when(0);
pop_blockcommand("CASE");
}
    break;

  case 102:
#line 1327 "fgl.yacc"
    {  push_blockcommand("CASE"); 
setinc(1);
incprint(); 
print_case(0);
setinc(1);
}
    break;

  case 103:
#line 1336 "fgl.yacc"
    {
print_after_when(0);
pop_blockcommand("CASE");
}
    break;

  case 108:
#line 1349 "fgl.yacc"
    {setinc(-1);incprint();}
    break;

  case 110:
#line 1352 "fgl.yacc"
    {
incprint();
}
    break;

  case 111:
#line 1354 "fgl.yacc"
    {incprint();
print_after_when(0);
}
    break;

  case 113:
#line 1360 "fgl.yacc"
    {incprint();}
    break;

  case 114:
#line 1362 "fgl.yacc"
    {incprint();
print_after_when(0);
}
    break;

  case 115:
#line 1367 "fgl.yacc"
    {
print_when(0);

incprint();
}
    break;

  case 116:
#line 1372 "fgl.yacc"
    {incprint();
print_after_when(1);
setinc(-1);}
    break;

  case 117:
#line 1378 "fgl.yacc"
    {
incprint();
print_when(1);
}
    break;

  case 118:
#line 1382 "fgl.yacc"
    {incprint();
print_after_when(1);
setinc(-1);}
    break;

  case 119:
#line 1397 "fgl.yacc"
    {
  print_close('F',yyvsp[0].str);
 }
    break;

  case 120:
#line 1400 "fgl.yacc"
    {
  print_close('W',yyvsp[0].str);
}
    break;

  case 121:
#line 1403 "fgl.yacc"
    {
  print_close('W',yyvsp[0].str);
}
    break;

  case 122:
#line 1406 "fgl.yacc"
    {
  print_close('D',0);
}
    break;

  case 123:
#line 1409 "fgl.yacc"
    {
  print_close('S',yyvsp[0].str);
}
    break;

  case 124:
#line 1412 "fgl.yacc"
    {
  print_close('C',yyvsp[0].str);
}
    break;

  case 130:
#line 1434 "fgl.yacc"
    {
			lex_printc("%s",yyvsp[0].str);
}
    break;

  case 133:
#line 1443 "fgl.yacc"
    {
			lex_printc("%s\n",yyvsp[0].str);
}
    break;

  case 134:
#line 1453 "fgl.yacc"
    {
/* This aint used - its filtered by the lexer first... */
	lex_printc("FIXME : Comment : %s\n");
}
    break;

  case 135:
#line 1467 "fgl.yacc"
    {
push_blockcommand("CONSTRUCT");
}
    break;

  case 136:
#line 1471 "fgl.yacc"
    {
	print_construct_1();
}
    break;

  case 137:
#line 1474 "fgl.yacc"
    {
	print_construct_2(yyvsp[-2].str);
}
    break;

  case 138:
#line 1482 "fgl.yacc"
    {
	print_construct_3(1,yyvsp[-5].str,yyvsp[0].str);
	strcpy(yyval.str,"form_loop(&_inp_io)"); /* FIXME */
	reset_constr();
}
    break;

  case 139:
#line 1488 "fgl.yacc"
    {
	print_construct_3(0,yyvsp[-7].str,yyvsp[0].str);
	strcpy(yyval.str,"form_loop(&_inp_io)"); /* FIXME */
	reset_constr();
}
    break;

  case 144:
#line 1503 "fgl.yacc"
    {
                push_construct("",yyval.str);
             }
    break;

  case 145:
#line 1507 "fgl.yacc"
    {
                sprintf(yyval.str,"%s.%s",yyvsp[-2].str,yyvsp[0].str);
                push_construct(yyvsp[-2].str,yyvsp[0].str); 
             }
    break;

  case 146:
#line 1512 "fgl.yacc"
    {
                push_construct(yyvsp[-2].str,"*");
             }
    break;

  case 149:
#line 1522 "fgl.yacc"
    {
		print_befaft_field_1(yyvsp[0].str);
	}
    break;

  case 150:
#line 1525 "fgl.yacc"
    {
		print_befaft_field_2();

	}
    break;

  case 151:
#line 1529 "fgl.yacc"
    {
		print_befaft_field_1(yyvsp[0].str);
	}
    break;

  case 152:
#line 1531 "fgl.yacc"
    {
		print_befaft_field_2();
	}
    break;

  case 153:
#line 1534 "fgl.yacc"
    {
		print_onkey_1(yyvsp[0].str);
	}
    break;

  case 154:
#line 1536 "fgl.yacc"
    {
		print_onkey_2();
	}
    break;

  case 155:
#line 1539 "fgl.yacc"
    {
		print_befaft_field_1("AFTER_INP");
	}
    break;

  case 156:
#line 1541 "fgl.yacc"
    {
		print_befaft_field_2();
	}
    break;

  case 157:
#line 1544 "fgl.yacc"
    {
		print_befaft_field_1("BEFORE_INP");
		}
    break;

  case 158:
#line 1547 "fgl.yacc"
    {
		print_befaft_field_2();
	}
    break;

  case 159:
#line 1557 "fgl.yacc"
    {sprintf(yyval.str,"BEF_FIELD_CHK(%s)",yyvsp[0].str);}
    break;

  case 160:
#line 1558 "fgl.yacc"
    {
	  char buff[80];
	  sprintf(buff,"BEF_FIELD_CHK(%s)",yyvsp[0].str);
	  generate_or(yyval.str,yyvsp[-2].str,buff);
	}
    break;

  case 161:
#line 1566 "fgl.yacc"
    {sprintf(yyval.str,"AFT_FIELD_CHK(%s)",yyvsp[0].str);}
    break;

  case 162:
#line 1567 "fgl.yacc"
    {
	  char buff[80];
	  sprintf(buff,"AFT_FIELD_CHK(%s)",yyvsp[0].str);
	  generate_or(yyval.str,yyvsp[-2].str,buff);
	}
    break;

  case 163:
#line 1584 "fgl.yacc"
    {
        	yyval.ptr=new_expr("pushop(OP_YEAR);");
	}
    break;

  case 164:
#line 1587 "fgl.yacc"
    {
        	yyval.ptr=new_expr("pushop(OP_MONTH);");
	}
    break;

  case 165:
#line 1590 "fgl.yacc"
    {
        	yyval.ptr=new_expr("pushop(OP_DAY);");
	}
    break;

  case 166:
#line 1593 "fgl.yacc"
    {
        	yyval.ptr=new_expr("pushop(OP_HOUR);");
	}
    break;

  case 167:
#line 1596 "fgl.yacc"
    {
        	yyval.ptr=new_expr("pushop(OP_MINUTE);");
	}
    break;

  case 168:
#line 1599 "fgl.yacc"
    {
        	yyval.ptr=new_expr("pushop(OP_SECOND);");
	}
    break;

  case 169:
#line 1612 "fgl.yacc"
    {
				print_defer(0);
			}
    break;

  case 170:
#line 1616 "fgl.yacc"
    {
				print_defer(1);
			}
    break;

  case 171:
#line 1631 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 172:
#line 1632 "fgl.yacc"
    {strcpy(yyval.str,"");lastlineno=yylineno;}
    break;

  case 175:
#line 1640 "fgl.yacc"
    {dtypelist[0]=0;lex_printcomment("/* define */\n");}
    break;

  case 176:
#line 1640 "fgl.yacc"
    {lex_printcomment("/*end def */\n");}
    break;

  case 182:
#line 1650 "fgl.yacc"
    {in_define=1;}
    break;

  case 183:
#line 1650 "fgl.yacc"
    {in_define=0;strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 184:
#line 1654 "fgl.yacc"
    { add_constant('c',yyvsp[0].str,yyvsp[-2].str); addmap("Constant",yyvsp[-2].str,curr_func,yylineno,infilename); }
    break;

  case 185:
#line 1655 "fgl.yacc"
    { add_constant('f',yyvsp[0].str,yyvsp[-2].str);
addmap("Constant",yyvsp[-2].str,curr_func,yylineno,infilename);
 }
    break;

  case 186:
#line 1658 "fgl.yacc"
    { 
add_constant('i',yyvsp[0].str,yyvsp[-2].str);
addmap("Constant",yyvsp[-2].str,curr_func,yylineno,infilename);
 }
    break;

  case 188:
#line 1663 "fgl.yacc"
    { }
    break;

  case 189:
#line 1663 "fgl.yacc"
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
#line 1680 "fgl.yacc"
    {
		sprintf(yyval.str,"-%p",yyvsp[0].str);}
    break;

  case 194:
#line 1684 "fgl.yacc"
    {
/*AF CygWin FIX */
push_name(yyval.str,0);
addmap("Define",yyvsp[0].str,curr_func,yylineno,infilename);
}
    break;

  case 199:
#line 1698 "fgl.yacc"
    {
	debug("defines array %s",yyvsp[-1].str);
	push_type(0,0,yyvsp[-1].str);
}
    break;

  case 201:
#line 1707 "fgl.yacc"
    {
	push_associate(yyvsp[-5].str,yyvsp[-1].str);
	push_type(0,0,yyvsp[-1].str);
}
    break;

  case 202:
#line 1711 "fgl.yacc"
    {
    /* void pop_associate (char *a); */
	pop_associate(0);

}
    break;

  case 208:
#line 1727 "fgl.yacc"
    {sprintf(yyval.str,"%s][%s][%s",yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str); debug("Triplet");}
    break;

  case 209:
#line 1729 "fgl.yacc"
    {sprintf(yyval.str,"%s][%s",yyvsp[-2].str,yyvsp[0].str); debug("double");}
    break;

  case 210:
#line 1730 "fgl.yacc"
    {debug("Single");}
    break;

  case 212:
#line 1737 "fgl.yacc"
    {push_record();in_record++;}
    break;

  case 213:
#line 1737 "fgl.yacc"
    {pop_record();in_record--;}
    break;

  case 214:
#line 1738 "fgl.yacc"
    {in_record++;push_record();debug("Like\n");}
    break;

  case 215:
#line 1739 "fgl.yacc"
    {debug("Link Table : %s\n",yyvsp[-2].str);
                  push_rectab(yyvsp[-2].str);
                  pop_record();in_record--;}
    break;

  case 216:
#line 1742 "fgl.yacc"
    {
		push_record();debug("Like\n");}
    break;

  case 217:
#line 1744 "fgl.yacc"
    {
		  debug("Table:%s\n",yyvsp[-4].str);
		  add_link_to(yyvsp[-4].str,yyvsp[-1].str);
	          debug("Push record...\n");
                  push_rectab(yyvsp[-4].str);
                  pop_record();
}
    break;

  case 219:
#line 1754 "fgl.yacc"
    {
	sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 224:
#line 1769 "fgl.yacc"
    {start_state("dtype",1);}
    break;

  case 225:
#line 1769 "fgl.yacc"
    {start_state("dtype",0);}
    break;

  case 229:
#line 1775 "fgl.yacc"
    {push_type("char","1",0);}
    break;

  case 230:
#line 1776 "fgl.yacc"
    {
/* char buff[80]; */
if (atoi(yyvsp[-1].str)==4) {
	addmap("size=4","----",curr_func,yylineno,infilename);
}
push_type("char",yyvsp[-1].str,0);
}
    break;

  case 231:
#line 1783 "fgl.yacc"
    {push_type("char",yyvsp[-1].str,0);}
    break;

  case 232:
#line 1784 "fgl.yacc"
    {push_type("char",yyvsp[-3].str,0);}
    break;

  case 233:
#line 1785 "fgl.yacc"
    {push_type("long",0,0);}
    break;

  case 234:
#line 1786 "fgl.yacc"
    {
debug("Using specified type...");
push_dim(yyvsp[0].str);}
    break;

  case 235:
#line 1789 "fgl.yacc"
    {push_type("int",0,0);}
    break;

  case 236:
#line 1790 "fgl.yacc"
    {push_type("form",0,0);}
    break;

  case 237:
#line 1791 "fgl.yacc"
    {push_type("form",0,0);}
    break;

  case 238:
#line 1792 "fgl.yacc"
    { char buff[256];
				sprintf(buff,"%d",16*256+2);
				push_type("fgldecimal",buff,0);
				}
    break;

  case 239:
#line 1796 "fgl.yacc"
    {
				char buff[256];
				sprintf(buff,"%d",atoi(yyvsp[-1].str)*256+2);
				push_type("fgldecimal",buff,0);
}
    break;

  case 240:
#line 1801 "fgl.yacc"
    {
char buff[256];
sprintf(buff,"%d",atoi(yyvsp[-3].str)*256+atoi(yyvsp[-1].str));
push_type("fgldecimal",buff,0);
}
    break;

  case 241:
#line 1806 "fgl.yacc"
    {
			char buff[256];
			sprintf(buff,"%d",16*256+2);
			push_type("fglmoney",buff,0);}
    break;

  case 242:
#line 1810 "fgl.yacc"
    {
		char buff[256];sprintf(buff,"%d",atoi(yyvsp[-1].str)*256+2);
			push_type("fglmoney",buff,0);}
    break;

  case 243:
#line 1813 "fgl.yacc"
    {
char buff[256];
sprintf(buff,"%d",atoi(yyvsp[-3].str)*256+atoi(yyvsp[-1].str));
push_type("fglmoney",buff,0);}
    break;

  case 244:
#line 1817 "fgl.yacc"
    {push_type("double",0,0);}
    break;

  case 245:
#line 1818 "fgl.yacc"
    {push_type("float",0,0);}
    break;

  case 246:
#line 1819 "fgl.yacc"
    {push_type("fgldate",0,0);}
    break;

  case 247:
#line 1820 "fgl.yacc"
    {push_type("fglbyte",0,0);}
    break;

  case 248:
#line 1821 "fgl.yacc"
    {push_type("fglbyte",0,0);}
    break;

  case 249:
#line 1822 "fgl.yacc"
    {push_type("fgltext",0,0);}
    break;

  case 250:
#line 1823 "fgl.yacc"
    {push_type("fgltext",0,0);}
    break;

  case 251:
#line 1824 "fgl.yacc"
    {
push_type("struct_dtime",yyvsp[0].str,0);
}
    break;

  case 252:
#line 1827 "fgl.yacc"
    {push_type("struct_ival",yyvsp[0].str,0);}
    break;

  case 253:
#line 1828 "fgl.yacc"
    {push_like(yyvsp[0].str);lex_printcomment("/*added(XXXXX)\n */");}
    break;

  case 254:
#line 1829 "fgl.yacc"
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
#line 1861 "fgl.yacc"
    {
lex_printcomment("/*column like(ZZZ)\n*/"); sprintf(yyval.str,"%s.%s",yyvsp[-2].str,yyvsp[0].str); lex_printcomment ("/*set col...(ZZZ)\n*/");}
    break;

  case 256:
#line 1865 "fgl.yacc"
    {debug("--->%s\n",yyvsp[0].str);strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 257:
#line 1867 "fgl.yacc"
    {debug("--->%s\n",yyvsp[0].str);strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 258:
#line 1869 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 259:
#line 1871 "fgl.yacc"
    {
debug("Real datetime %s to %s\n",yyvsp[-2].str,yyvsp[0].str);
sprintf(yyval.str,"%d",(atoi(yyvsp[-2].str)*16)+atoi(yyvsp[0].str)); }
    break;

  case 260:
#line 1876 "fgl.yacc"
    {
sprintf(yyval.str,"%d",(atoi(yyvsp[-2].str)*16)+atoi(yyvsp[0].str)); 
}
    break;

  case 261:
#line 1880 "fgl.yacc"
    {start_state("dtime_val",1);}
    break;

  case 262:
#line 1880 "fgl.yacc"
    {start_state("dtime_val",0); strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 263:
#line 1884 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 264:
#line 1885 "fgl.yacc"
    {strcpy(yyval.str,"2");}
    break;

  case 265:
#line 1886 "fgl.yacc"
    {strcpy(yyval.str,"3");}
    break;

  case 266:
#line 1887 "fgl.yacc"
    {strcpy(yyval.str,"4");}
    break;

  case 267:
#line 1888 "fgl.yacc"
    {strcpy(yyval.str,"5");}
    break;

  case 268:
#line 1889 "fgl.yacc"
    {strcpy(yyval.str,"6");}
    break;

  case 269:
#line 1891 "fgl.yacc"
    {
debug("opt_frac returns %s",yyvsp[0].str);
sprintf(yyval.str,"%d",atoi(yyvsp[0].str)+6); }
    break;

  case 270:
#line 1896 "fgl.yacc"
    {start_state("dtime_val",1);}
    break;

  case 271:
#line 1896 "fgl.yacc"
    { debug ("Got end");start_state("dtime_val",0);  strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 272:
#line 1899 "fgl.yacc"
    {
debug("Nothing in fraction - assume 2");
strcpy(yyval.str,"2");}
    break;

  case 273:
#line 1901 "fgl.yacc"
    {
debug("Read fraction .. ");
debug("    %s",yyvsp[-1].str);
strcpy(yyval.str,yyvsp[-1].str);
}
    break;

  case 274:
#line 1907 "fgl.yacc"
    {
debug("Nothing in fraction - assume 2");
strcpy(yyval.str,"2");}
    break;

  case 275:
#line 1909 "fgl.yacc"
    {
debug("    %s",yyvsp[-1].str);
strcpy(yyval.str,yyvsp[-1].str);
}
    break;

  case 276:
#line 1915 "fgl.yacc"
    {
if (atoi(yyvsp[0].str)>5) {
yyerror("Fraction values are between 0 and 5");
YYERROR;
}
}
    break;

  case 277:
#line 1923 "fgl.yacc"
    {start_state("interval_val",1);}
    break;

  case 278:
#line 1923 "fgl.yacc"
    {start_state("interval_val",0); sprintf(yyval.str,"%d",atoi(yyvsp[0].str)*16+atoi(yyvsp[-1].str));}
    break;

  case 279:
#line 1926 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 280:
#line 1927 "fgl.yacc"
    {strcpy(yyval.str,"2");}
    break;

  case 281:
#line 1928 "fgl.yacc"
    {strcpy(yyval.str,"3");}
    break;

  case 282:
#line 1929 "fgl.yacc"
    {strcpy(yyval.str,"4");}
    break;

  case 283:
#line 1930 "fgl.yacc"
    {strcpy(yyval.str,"5");}
    break;

  case 284:
#line 1931 "fgl.yacc"
    {strcpy(yyval.str,"6");}
    break;

  case 285:
#line 1933 "fgl.yacc"
    {
debug("opt_frac returns %s",yyvsp[0].str);
sprintf(yyval.str,"%d",atoi(yyvsp[0].str)+6); }
    break;

  case 289:
#line 1954 "fgl.yacc"
    {
              	dim_set_name(yyvsp[0].str);
              }
    break;

  case 293:
#line 1963 "fgl.yacc"
    {dim_push_type("char","1",0);}
    break;

  case 294:
#line 1965 "fgl.yacc"
    {dim_push_type("char",yyvsp[-1].str,0);}
    break;

  case 295:
#line 1967 "fgl.yacc"
    {dim_push_type("char",yyvsp[-1].str,0);}
    break;

  case 296:
#line 1969 "fgl.yacc"
    {dim_push_type("char",yyvsp[-3].str,0);}
    break;

  case 297:
#line 1970 "fgl.yacc"
    {dim_push_type("long",0,0);}
    break;

  case 298:
#line 1971 "fgl.yacc"
    {dim_push_type("integer",0,0);}
    break;

  case 299:
#line 1972 "fgl.yacc"
    {dim_push_type("FORM",0,0);}
    break;

  case 300:
#line 1973 "fgl.yacc"
    {
char buff[256];
sprintf(buff,"%d",16*256+2);
dim_push_type("fgldecimal",buff,0);
}
    break;

  case 301:
#line 1978 "fgl.yacc"
    {

char buff[256];
sprintf(buff,"%d",atoi(yyvsp[-1].str)*256+2);
dim_push_type("fgldecimal",buff,0);
}
    break;

  case 302:
#line 1985 "fgl.yacc"
    {
char buff[256];
sprintf(buff,"%d",atoi(yyvsp[-3].str)*256+atoi(yyvsp[-1].str));
dim_push_type("fgldecimal",buff,0);
}
    break;

  case 303:
#line 1990 "fgl.yacc"
    {dim_push_type("fglmoney",0,0);}
    break;

  case 304:
#line 1992 "fgl.yacc"
    {dim_push_type("fglmoney",0,0);}
    break;

  case 305:
#line 1994 "fgl.yacc"
    {dim_push_type("fglmoney",0,0);}
    break;

  case 306:
#line 1995 "fgl.yacc"
    {dim_push_type("double",0,0);}
    break;

  case 307:
#line 1996 "fgl.yacc"
    {dim_push_type("float",0,0);}
    break;

  case 308:
#line 1997 "fgl.yacc"
    {dim_push_type("fgldate",0,0);}
    break;

  case 309:
#line 1998 "fgl.yacc"
    {dim_push_type("fglbyte",0,0);}
    break;

  case 310:
#line 1999 "fgl.yacc"
    {dim_push_type("fgltext",0,0);}
    break;

  case 311:
#line 2000 "fgl.yacc"
    {
dim_push_type("struct_dtime",yyvsp[0].str,0);
}
    break;

  case 312:
#line 2003 "fgl.yacc"
    {dim_push_type("struct_ival",0,0);}
    break;

  case 313:
#line 2005 "fgl.yacc"
    {dim_push_like(yyvsp[0].str);lex_printcomment("/*added(XXXXX)\n */");}
    break;

  case 314:
#line 2011 "fgl.yacc"
    {
lex_printcomment("/*column like(ZZZ)\n*/");
sprintf(yyval.str,"%s.%s",yyvsp[-2].str,yyvsp[0].str)
; lex_printcomment ("/*set col...(ZZZ)\n*/");}
    break;

  case 315:
#line 2019 "fgl.yacc"
    {
dim_push_type(0,0,yyvsp[-1].str);
}
    break;

  case 317:
#line 2027 "fgl.yacc"
    {
dim_push_associate(yyvsp[-5].str,yyvsp[-1].str);
dim_push_type(0,0,yyvsp[-1].str);
}
    break;

  case 318:
#line 2031 "fgl.yacc"
    {
	/* void dim_pop_associate (char *a); */
	dim_pop_associate(0);
}
    break;

  case 319:
#line 2039 "fgl.yacc"
    {dim_push_record();}
    break;

  case 320:
#line 2040 "fgl.yacc"
    {dim_pop_record();}
    break;

  case 321:
#line 2041 "fgl.yacc"
    {dim_push_record();debug("Like\n");}
    break;

  case 322:
#line 2042 "fgl.yacc"
    {debug("Table:%s\n",yyvsp[-2].str);
                                  dim_push_rectab(yyvsp[-2].str);
                                  dim_pop_record();}
    break;

  case 328:
#line 2061 "fgl.yacc"
    { dim_push_name(yyval.str,0); }
    break;

  case 329:
#line 2073 "fgl.yacc"
    {
	print_display_line();
		strcpy(yyval.str,get_display_str(0,0,0));
	}
    break;

  case 330:
#line 2077 "fgl.yacc"
    {
		strcpy(yyval.str,get_display_str(1,0,0)); /* FIXME */
	}
    break;

  case 331:
#line 2080 "fgl.yacc"
    { 
	strcpy(yyval.str,"#error not implemented yet");
	}
    break;

  case 332:
#line 2083 "fgl.yacc"
    { strcpy(yyval.str, get_display_str(4,0,0)); }
    break;

  case 333:
#line 2084 "fgl.yacc"
    { strcpy(yyval.str, get_display_str(2,yyvsp[0].str,0)); }
    break;

  case 334:
#line 2085 "fgl.yacc"
    { strcpy(yyval.str, get_display_str(3,yyvsp[0].str,yyvsp[-2].str)); }
    break;

  case 335:
#line 2086 "fgl.yacc"
    { strcpy(yyval.str, get_display_str(5,yyvsp[-1].str,0)); }
    break;

  case 336:
#line 2087 "fgl.yacc"
    { 
	strcpy(yyval.str,"#error not implemented yet");
 }
    break;

  case 337:
#line 2093 "fgl.yacc"
    {
		print_display_by_name(yyvsp[0].str);
                }
    break;

  case 338:
#line 2100 "fgl.yacc"
    { 
				print_display(yyvsp[-1].str,yyvsp[-2].str,yyvsp[0].str);
		}
    break;

  case 339:
#line 2105 "fgl.yacc"
    {
		print_display_form(yyvsp[-1].str,yyvsp[0].str);
	}
    break;

  case 340:
#line 2110 "fgl.yacc"
    {
		push_blockcommand("DISPLAY");
		}
    break;

  case 341:
#line 2114 "fgl.yacc"
    {
		print_display_array_p1(yyvsp[-6].str,yyvsp[-4].str,yyvsp[-1].str,yyvsp[0].str);
		}
    break;

  case 342:
#line 2117 "fgl.yacc"
    {
		add_continue_blockcommand ("DISPLAY");  
		print_display_array_p2();
		pop_blockcommand("DISPLAY");
}
    break;

  case 343:
#line 2125 "fgl.yacc"
    {
strcpy(yyval.str,"0,0");
}
    break;

  case 344:
#line 2127 "fgl.yacc"
    {
	strcpy(yyval.str,yyvsp[0].str);
}
    break;

  case 345:
#line 2132 "fgl.yacc"
    {
				sprintf(yyval.str,"0x%lx",atol(yyvsp[0].str));
			}
    break;

  case 350:
#line 2144 "fgl.yacc"
    {
		print_befaft_field_1("AFT_ROW");
		}
    break;

  case 351:
#line 2147 "fgl.yacc"
    {
		print_befaft_field_2();
	}
    break;

  case 352:
#line 2150 "fgl.yacc"
    {
		print_befaft_field_1("BEF_ROW");
		}
    break;

  case 353:
#line 2153 "fgl.yacc"
    {
		print_befaft_field_2();
	}
    break;

  case 354:
#line 2156 "fgl.yacc"
    {
		print_onkey_1(yyvsp[0].str);
		}
    break;

  case 355:
#line 2159 "fgl.yacc"
    {
		print_onkey_2();
	}
    break;

  case 356:
#line 2172 "fgl.yacc"
    {
			print_error(yyvsp[0].str,0);
		}
    break;

  case 357:
#line 2175 "fgl.yacc"
    { 
			print_error(yyvsp[-1].str,1);
	}
    break;

  case 358:
#line 2190 "fgl.yacc"
    { if (in_command("WHILE")) { exit_loop("WHILE"); } else { YYERROR;} }
    break;

  case 359:
#line 2192 "fgl.yacc"
    { if (in_command("INPUT")) { exit_loop("INPUT"); } else { YYERROR;} }
    break;

  case 360:
#line 2194 "fgl.yacc"
    { if (in_command("FOREACH")) { exit_loop("FOREACH"); } else { YYERROR;} }
    break;

  case 361:
#line 2196 "fgl.yacc"
    { if (in_command("FOR")) { exit_loop("FOR"); } else { YYERROR;} }
    break;

  case 362:
#line 2198 "fgl.yacc"
    { if (in_command("CONSTRUCT")) { exit_loop("CONSTRUCT"); } else { YYERROR;} }
    break;

  case 363:
#line 2200 "fgl.yacc"
    { if (in_command("DISPLAY")) { exit_loop("DISPLAY"); } else { YYERROR;} }
    break;

  case 364:
#line 2201 "fgl.yacc"
    {
	if (in_command("MENU")) {
		exit_loop("MENU");
		/* lex_printc("cmd_no=-3;continue;\n"); */
	} 
              else YYERROR;}
    break;

  case 365:
#line 2208 "fgl.yacc"
    { if (in_command("CASE")) { exit_loop("CASE"); } else { YYERROR;} }
    break;

  case 366:
#line 2210 "fgl.yacc"
    { if (in_command("PROMPT")) { exit_loop("PROMPT"); } else { YYERROR;} }
    break;

  case 367:
#line 2214 "fgl.yacc"
    { if (in_command("WHILE")) { continue_loop("WHILE");  } else { YYERROR;} }
    break;

  case 368:
#line 2216 "fgl.yacc"
    { if (in_command("INPUT")) { continue_loop("INPUT"); } else { YYERROR;} }
    break;

  case 369:
#line 2218 "fgl.yacc"
    { if (in_command("FOREACH")) { continue_loop("FOREACH");} else { YYERROR;} }
    break;

  case 370:
#line 2220 "fgl.yacc"
    { if (in_command("FOR")) { continue_loop("FOR"); } else { YYERROR;} }
    break;

  case 371:
#line 2222 "fgl.yacc"
    { if (in_command("CONSTRUCT")) { continue_loop("CONSTRUCT"); } else { YYERROR;} }
    break;

  case 372:
#line 2224 "fgl.yacc"
    { if (in_command("DISPLAY")) { continue_loop("DISPLAY"); } else { YYERROR;} }
    break;

  case 373:
#line 2226 "fgl.yacc"
    { if (in_command("MENU")) {  continue_loop("MENU");  } else { YYERROR;} }
    break;

  case 374:
#line 2232 "fgl.yacc"
    { if (in_command("PROMPT")) { continue_loop("PROMPT"); } else { YYERROR;} }
    break;

  case 375:
#line 2246 "fgl.yacc"
    {
	print_exit_program(0);
}
    break;

  case 376:
#line 2249 "fgl.yacc"
    {
	print_exit_program(1);
}
    break;

  case 381:
#line 2266 "fgl.yacc"
    {
	dec_counter();
	yyval.ptr=append_expr_expr(yyvsp[-1].ptr,yyvsp[0].ptr);
}
    break;

  case 384:
#line 2272 "fgl.yacc"
    {
	debug("Got literal ptr=%p",yyvsp[0].ptr);
}
    break;

  case 385:
#line 2276 "fgl.yacc"
    {
	yyval.ptr=new_expr("push_int(0);");
	yyval.ptr=append_expr_expr(yyval.ptr,yyvsp[0].ptr);
	yyval.ptr=append_expr(yyval.ptr,"pushop(OP_SUB);");
}
    break;

  case 386:
#line 2281 "fgl.yacc"
    {
	yyval.ptr=yyvsp[0].ptr;
}
    break;

  case 390:
#line 2291 "fgl.yacc"
    { yyval.ptr=new_expr("add_spaces();"); }
    break;

  case 397:
#line 2302 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 398:
#line 2302 "fgl.yacc"
    {
strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 400:
#line 2307 "fgl.yacc"
    {yyval.ptr=new_expr("push_null()");}
    break;

  case 401:
#line 2311 "fgl.yacc"
    {
	/*set_counter(0);*/
	sprintf(yyval.str,"%d",get_counter_val());
	lex_printcomment("/*L1 %s*/\n",yyval.str);
}
    break;

  case 402:
#line 2317 "fgl.yacc"
    {
	sprintf(yyval.str,"%d",get_counter_val());
	lex_printcomment("/*L2 %s*/\n",yyval.str);
}
    break;

  case 403:
#line 2325 "fgl.yacc"
    {
	/*set_counter(0);*/
	sprintf(yyval.str,"%d",get_counter_val());
	lex_printcomment("/*L1 %s*/\n",yyval.str);
}
    break;

  case 404:
#line 2331 "fgl.yacc"
    {
	sprintf(yyval.str,"%d",get_counter_val());
	lex_printcomment("/*L2 %s*/\n",yyval.str);
}
    break;

  case 405:
#line 2340 "fgl.yacc"
    {sprintf(yyval.str,"%d",get_counter_val());}
    break;

  case 406:
#line 2342 "fgl.yacc"
    {
	print_op("OP_CONCAT");
	dec_counter();sprintf(yyval.str,"%d",get_counter_val());
}
    break;

  case 407:
#line 2349 "fgl.yacc"
    {
	debug("Print expr (2)");
	print_expr(yyvsp[0].ptr);
}
    break;

  case 408:
#line 2357 "fgl.yacc"
    {
	strcpy(yyval.str,"+");
}
    break;

  case 409:
#line 2361 "fgl.yacc"
    {
	strcpy(yyval.str,"-");
}
    break;

  case 410:
#line 2370 "fgl.yacc"
    {
	
	yyval.ptr=append_expr(yyvsp[0].ptr,"pushop(OP_NOT);");
}
    break;

  case 411:
#line 2375 "fgl.yacc"
    {
	yyval.ptr=new_expr("push_int(1);");
        inc_counter();
}
    break;

  case 412:
#line 2380 "fgl.yacc"
    {
	inc_counter();
	yyval.ptr=new_expr("push_int(0);");
}
    break;

  case 413:
#line 2384 "fgl.yacc"
    { yyval.ptr=yyvsp[-1].ptr; }
    break;

  case 414:
#line 2386 "fgl.yacc"
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
#line 2396 "fgl.yacc"
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
#line 2410 "fgl.yacc"
    {
	debug("init expr %s %s",yyvsp[-1].str,yyvsp[0].str);
	sprintf(yyval.str,"%s%p",yyvsp[-1].str,yyvsp[0].str);
	sprintf(yyval.str,"%s",get_push_literal('D',yyval.str));
	yyval.ptr=new_expr(yyval.str);
        inc_counter();
}
    break;

  case 417:
#line 2418 "fgl.yacc"
    {
	debug("init expr int %s %d",yyvsp[-1].str,atoi(yyvsp[0].str));
	sprintf(yyval.str,"%s%p",yyvsp[-1].str,yyvsp[0].str);
	sprintf(yyval.str,"%s",get_push_literal('L',yyval.str));
	yyval.ptr=new_expr(yyval.str);
	inc_counter();
}
    break;

  case 418:
#line 2430 "fgl.yacc"
    {
	sprintf(yyval.str,"%s",get_push_literal('S',yyvsp[0].str));
	yyval.ptr=new_expr(yyval.str);
	inc_counter();
}
    break;

  case 419:
#line 2436 "fgl.yacc"
    {
	sprintf(yyval.str,"%s",get_push_literal('D',yyvsp[0].str));
	yyval.ptr=new_expr(yyval.str);
	inc_counter();
}
    break;

  case 420:
#line 2442 "fgl.yacc"
    {
	sprintf(yyval.str,"%s",get_push_literal('L',yyvsp[0].str));
	yyval.ptr=new_expr(yyval.str);
	inc_counter();
}
    break;

  case 423:
#line 2452 "fgl.yacc"
    {
		sprintf(yyval.str,"%s\n%s",yyvsp[-2].str,yyvsp[0].str);
	}
    break;

  case 424:
#line 2458 "fgl.yacc"
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
#line 2530 "fgl.yacc"
    {
	sprintf(yyval.str,"%sset_column(&rep);",ispdf());
	yyval.ptr=append_expr(yyvsp[0].ptr,yyval.str);
}
    break;

  case 426:
#line 2536 "fgl.yacc"
    {
sprintf(yyval.str,"%sset_column(&rep);",ispdf());
yyval.ptr=append_expr(yyvsp[0].ptr,yyval.str);
}
    break;

  case 427:
#line 2540 "fgl.yacc"
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
#line 2548 "fgl.yacc"
    {insql=1;set_ingroup();}
    break;

  case 429:
#line 2548 "fgl.yacc"
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
#line 2565 "fgl.yacc"
    {
	yyval.ptr=append_expr(yyvsp[0].ptr,"pushop(OP_AND);");
}
    break;

  case 431:
#line 2569 "fgl.yacc"
    {
	yyval.ptr=append_expr(yyvsp[0].ptr,"pushop(OP_OR);");
}
    break;

  case 432:
#line 2575 "fgl.yacc"
    {
	yyval.ptr=yyvsp[0].ptr;
	}
    break;

  case 433:
#line 2578 "fgl.yacc"
    {
		debug("Adding to list...");
		yyval.ptr=append_expr_expr(yyvsp[-2].ptr,yyvsp[0].ptr);
	}
    break;

  case 434:
#line 2586 "fgl.yacc"
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
#line 2597 "fgl.yacc"
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
#line 2607 "fgl.yacc"
    {
	char buff[256];
	sprintf(buff,"push_int(%d);",length_expr(yyvsp[-1].ptr));
	yyval.ptr=append_expr(yyvsp[-1].ptr,buff);
	append_expr(yyval.ptr,"pushop(OP_IN);");
}
    break;

  case 437:
#line 2613 "fgl.yacc"
    {
	char buff[256];
	sprintf(buff,"push_int(%d);",length_expr(yyvsp[-1].ptr));
	yyval.ptr=append_expr(yyvsp[-1].ptr,buff);
	append_expr(yyval.ptr,"pushop(OP_NOTIN);");
}
    break;

  case 438:
#line 2623 "fgl.yacc"
    { 
	strcpy(yyval.str,"pushop(OP_ISNULL);");
	yyval.ptr=new_expr(yyval.str);
}
    break;

  case 439:
#line 2628 "fgl.yacc"
    {
	strcpy(yyval.str,"pushop(OP_ISNOTNULL);");
	yyval.ptr=new_expr(yyval.str);
}
    break;

  case 440:
#line 2636 "fgl.yacc"
    {
	yyval.ptr=append_expr(yyvsp[0].ptr,"pushop(OP_MATCHES);");
}
    break;

  case 441:
#line 2640 "fgl.yacc"
    {
	yyval.ptr=append_expr(yyvsp[0].ptr,"pushop(OP_MATCHES);pushop(OP_NOT);");
}
    break;

  case 442:
#line 2644 "fgl.yacc"
    {
	yyval.ptr=append_expr(yyvsp[0].ptr,"pushop(OP_LIKE);");
}
    break;

  case 443:
#line 2648 "fgl.yacc"
    {
	yyval.ptr=append_expr(yyvsp[0].ptr,"pushop(OP_LIKE);pushop(OP_NOT);");
}
    break;

  case 444:
#line 2655 "fgl.yacc"
    {
	strcpy(yyval.str,"pushop(OP_CLIP);");
	yyval.ptr=new_expr(yyval.str);
	inc_counter();
}
    break;

  case 445:
#line 2663 "fgl.yacc"
    {
	sprintf(yyval.str,"%s pushop(OP_USING);",yyvsp[0].str);
	yyval.ptr=append_expr(yyvsp[0].ptr,"pushop(OP_USING);");
}
    break;

  case 446:
#line 2671 "fgl.yacc"
    {
	debug("PLUS in math_expr $<ptr>2 = %p",yyvsp[0].ptr);
	yyval.ptr=append_expr(yyvsp[0].ptr,"pushop(OP_ADD);");
}
    break;

  case 447:
#line 2676 "fgl.yacc"
    {
	yyval.ptr=append_expr(yyvsp[0].ptr,"pushop(OP_SUB);");
}
    break;

  case 448:
#line 2680 "fgl.yacc"
    {
      sprintf(yyval.str,"%s pushop(OP_MULT);",yyvsp[0].str);
	yyval.ptr=append_expr(yyvsp[0].ptr,"pushop(OP_MULT);");
}
    break;

  case 449:
#line 2685 "fgl.yacc"
    {
	yyval.ptr=append_expr(yyvsp[0].ptr,"pushop(OP_DIV);");
}
    break;

  case 450:
#line 2689 "fgl.yacc"
    {
	yyval.ptr=append_expr(yyvsp[0].ptr,"pushop(OP_MOD);");
}
    break;

  case 451:
#line 2693 "fgl.yacc"
    {
	yyval.ptr=append_expr(yyvsp[0].ptr,"pushop(OP_POWER);");
}
    break;

  case 452:
#line 2699 "fgl.yacc"
    {
	yyval.ptr=append_expr(yyvsp[0].ptr,"pushop(OP_EQUAL);");
}
    break;

  case 453:
#line 2702 "fgl.yacc"
    {
	yyval.ptr=append_expr(yyvsp[0].ptr,"pushop(OP_EQUAL);");
}
    break;

  case 454:
#line 2706 "fgl.yacc"
    {
	yyval.ptr=append_expr(yyvsp[0].ptr,"pushop(OP_LESS_THAN);");
}
    break;

  case 455:
#line 2710 "fgl.yacc"
    {
	yyval.ptr=append_expr(yyvsp[0].ptr,"pushop(OP_GREATER_THAN);");
}
    break;

  case 456:
#line 2714 "fgl.yacc"
    {
	yyval.ptr=append_expr(yyvsp[0].ptr,"pushop(OP_NOT_EQUAL);");
}
    break;

  case 457:
#line 2718 "fgl.yacc"
    {
	yyval.ptr=append_expr(yyvsp[0].ptr,"pushop(OP_LESS_THAN_EQ);");
}
    break;

  case 458:
#line 2722 "fgl.yacc"
    {
	yyval.ptr=append_expr(yyvsp[0].ptr,"pushop(OP_GREATER_THAN_EQ);");
}
    break;

  case 459:
#line 2729 "fgl.yacc"
    {
	reset_counter();
}
    break;

  case 460:
#line 2739 "fgl.yacc"
    { 
		addmap("Call",yyvsp[-1].str,curr_func,yylineno,infilename);
		new_counter(); 
		}
    break;

  case 461:
#line 2744 "fgl.yacc"
    { 
		sprintf(yyval.str,"%d",get_counter_val()); 
		lex_printcomment("/*function_call_expr2 %s*/\n",yyval.str);
		drop_counter(); 
		}
    break;

  case 462:
#line 2750 "fgl.yacc"
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
#line 2759 "fgl.yacc"
    {
        sprintf(yyval.str,"\"%s\",\"%s\"",get_idents(0),get_idents(1));
	debug("NEWFORMAT : %s\n",yyval.str);
        A4GLSQL_set_status(0,0);
        new_counter();
}
    break;

  case 464:
#line 2764 "fgl.yacc"
    {
	sprintf(yyval.str,"%d",get_counter_val());  
	drop_counter();
}
    break;

  case 465:
#line 2767 "fgl.yacc"
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
#line 2781 "fgl.yacc"
    {inc_counter();chk4var=1;}
    break;

  case 467:
#line 2781 "fgl.yacc"
    {chk4var=0;}
    break;

  case 468:
#line 2781 "fgl.yacc"
    {
	yyval.ptr=append_expr(yyvsp[-2].ptr,"aclfgl_date(1);");
inc_counter();}
    break;

  case 469:
#line 2784 "fgl.yacc"
    {inc_counter();chk4var=1;}
    break;

  case 470:
#line 2784 "fgl.yacc"
    {chk4var=0;}
    break;

  case 471:
#line 2784 "fgl.yacc"
    {
	yyval.ptr=append_expr(yyvsp[-2].ptr,"aclfgl_month(1);");
inc_counter();}
    break;

  case 472:
#line 2787 "fgl.yacc"
    {inc_counter();chk4var=1;}
    break;

  case 473:
#line 2787 "fgl.yacc"
    {chk4var=0;}
    break;

  case 474:
#line 2787 "fgl.yacc"
    {
	yyval.ptr=append_expr(yyvsp[-2].ptr,"aclfgl_day(1);");
inc_counter();}
    break;

  case 475:
#line 2790 "fgl.yacc"
    {inc_counter();chk4var=1;}
    break;

  case 476:
#line 2790 "fgl.yacc"
    {chk4var=0;}
    break;

  case 477:
#line 2790 "fgl.yacc"
    {
	yyval.ptr=append_expr(yyvsp[-2].ptr,"aclfgl_year(1);");
inc_counter();}
    break;

  case 478:
#line 2793 "fgl.yacc"
    {
	char buff[256];
	sprintf(buff,"acli_interval(%s,%s)",yyvsp[-2].str,yyvsp[0].str);
	yyval.ptr=new_expr(buff);
}
    break;

  case 479:
#line 2798 "fgl.yacc"
    {
	char buff[256];
	sprintf(buff,"acli_interval(\"%s\",%s)",yyvsp[-2].str,yyvsp[0].str);
	yyval.ptr=new_expr(buff);
}
    break;

  case 480:
#line 2803 "fgl.yacc"
    {
	char buff[256];
	sprintf(buff,"acli_interval(\"%s:%s\",%s)",yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str);
	yyval.ptr=new_expr(buff);
}
    break;

  case 481:
#line 2808 "fgl.yacc"
    {
	char buff[256];
	sprintf(buff,"acli_datetime(%s,%s)",yyvsp[-2].str,yyvsp[0].str);
	yyval.ptr=new_expr(buff);
}
    break;

  case 482:
#line 2813 "fgl.yacc"
    {
	char buff[256];
	sprintf(buff,"acli_datetime(\"%s\",%s)",yyvsp[-2].str,yyvsp[0].str);
	yyval.ptr=new_expr(buff);
}
    break;

  case 483:
#line 2818 "fgl.yacc"
    {
	char buff[256];
	sprintf(buff,"acli_datetime(\"%s:%s\",%s)",yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str);
	yyval.ptr=new_expr(buff);
}
    break;

  case 484:
#line 2827 "fgl.yacc"
    {strcpy(yyval.str,"-1,-1");}
    break;

  case 485:
#line 2828 "fgl.yacc"
    {sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 486:
#line 2831 "fgl.yacc"
    {strcpy(yyval.str,"-1,-1");}
    break;

  case 487:
#line 2832 "fgl.yacc"
    {sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 489:
#line 2838 "fgl.yacc"
    {
sprintf(yyval.str,"{int _retvars;\n_retvars=fgl_getfldbuf(%s);\nif (_retvars != 1 ) {A4GLSQL_set_status(-3001,0);chk_err(%d,\"%s\");}\n}\n",
	yyvsp[-1].str, lastlineno,infilename); 
	yyval.ptr=new_expr(yyval.str);

}
    break;

  case 490:
#line 2844 "fgl.yacc"
    {sprintf(yyval.str,"push_int(fgl_fieldnametoid(\"\",%s));",yyvsp[-1].str); yyval.ptr=new_expr(yyval.str); }
    break;

  case 491:
#line 2845 "fgl.yacc"
    {
sprintf(yyval.str,"push_int(fgl_fieldnametoid(\"\",%s));",yyvsp[-1].str); yyval.ptr=new_expr(yyval.str); 
addmap("Get Field",yyvsp[-1].str,curr_func,yylineno,infilename);
}
    break;

  case 492:
#line 2850 "fgl.yacc"
    {sprintf(yyval.str,"push_int(fgl_infield(%s));",yyvsp[-1].str); 
	yyval.ptr=new_expr(yyval.str);
}
    break;

  case 493:
#line 2854 "fgl.yacc"
    { sprintf(yyval.str,"push_int(fgl_fieldtouched(%s));",yyvsp[-1].str); 
	yyval.ptr=new_expr(yyval.str);
}
    break;

  case 494:
#line 2858 "fgl.yacc"
    { sprintf(yyval.str,"push_int(!fgl_fieldtouched(%s));",yyvsp[-1].str); 
	yyval.ptr=new_expr(yyval.str);
}
    break;

  case 497:
#line 2865 "fgl.yacc"
    {
		inc_counter();
               sprintf(yyval.str,"push_current(%s);",yyvsp[0].str);
		yyval.ptr=new_expr(yyval.str);
          	}
    break;

  case 498:
#line 2870 "fgl.yacc"
    { inc_counter(); strcpy(yyval.str,"push_today();");
		yyval.ptr=new_expr(yyval.str);
		}
    break;

  case 499:
#line 2877 "fgl.yacc"
    { 
	yyval.ptr=append_expr(yyvsp[-1].ptr,"upshift_stk();");
}
    break;

  case 500:
#line 2881 "fgl.yacc"
    { 
	yyval.ptr=append_expr(yyvsp[-1].ptr,"downshift_stk();");
}
    break;

  case 501:
#line 2884 "fgl.yacc"
    { 
	yyval.ptr=append_expr(yyvsp[0].ptr,"push_ascii();");
}
    break;

  case 502:
#line 2887 "fgl.yacc"
    { 
	sprintf(yyval.str,"%s",yyvsp[-1].str); yyval.ptr=new_expr(yyval.str); }
    break;

  case 503:
#line 2889 "fgl.yacc"
    {
	yyval.ptr=append_expr(yyvsp[-1].ptr,"push_double(-1);pushop(OP_MULT);");
}
    break;

  case 504:
#line 2892 "fgl.yacc"
    {
	yyval.ptr=append_expr(yyvsp[-1].ptr,"push_double(-28.3465);pushop(OP_MULT);");
}
    break;

  case 505:
#line 2895 "fgl.yacc"
    {
	yyval.ptr=append_expr(yyvsp[-1].ptr,"push_double(-72.0);pushop(OP_MULT);");
}
    break;

  case 506:
#line 2901 "fgl.yacc"
    { sprintf(yyval.str,"aclfgli_current(%s,%s);",yyvsp[-2].str,yyvsp[0].str); }
    break;

  case 507:
#line 2902 "fgl.yacc"
    { sprintf(yyval.str,"aclfgli_extend(%s,%s,%s);",yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str); }
    break;

  case 508:
#line 2903 "fgl.yacc"
    { sprintf(yyval.str,"aclfgli_current(%s,%s);",yyvsp[-2].str,yyvsp[0].str); }
    break;

  case 509:
#line 2914 "fgl.yacc"
    {
print_for_start(yyvsp[-5].str);
push_blockcommand("FOR");
}
    break;

  case 510:
#line 2918 "fgl.yacc"
    {debug("For_cmds\n");}
    break;

  case 511:
#line 2919 "fgl.yacc"
    {

pop_blockcommand("FOR");
print_for_end();
lex_printcomment(" /*END FOR*/\n");}
    break;

  case 512:
#line 2926 "fgl.yacc"
    {
		print_for_default_step();
	}
    break;

  case 514:
#line 2943 "fgl.yacc"
    {
push_blockcommand("FOREACH");
}
    break;

  case 515:
#line 2947 "fgl.yacc"
    {
print_foreach_start();
lex_printcomment(" /* foreach */\n");
}
    break;

  case 516:
#line 2952 "fgl.yacc"
    {
print_foreach_next(yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 517:
#line 2956 "fgl.yacc"
    {
add_continue_blockcommand ("FOREACH");
print_foreach_end();
pop_blockcommand("FOREACH");
}
    break;

  case 518:
#line 2972 "fgl.yacc"
    {
		sprintf(curr_func,"%s",yyvsp[0].str); 
		print_formhandler(yyvsp[0].str);
		start_state("formhandler",1);
	push_blockcommand("FORMHANDLER");
        }
    break;

  case 519:
#line 2978 "fgl.yacc"
    {
		print_variables();
		print_getwin();
	}
    break;

  case 520:
#line 2986 "fgl.yacc"
    {
pop_blockcommand("FORMHANDLER");
print_end_formhandler(); 
start_state("formhandler",0);}
    break;

  case 527:
#line 3003 "fgl.yacc"
    {
		print_event('B');
        }
    break;

  case 528:
#line 3005 "fgl.yacc"
    {
		print_event_2();
        }
    break;

  case 529:
#line 3008 "fgl.yacc"
    {
		print_event('b');
        }
    break;

  case 530:
#line 3010 "fgl.yacc"
    {
		print_event_2();
        }
    break;

  case 535:
#line 3024 "fgl.yacc"
    {
		print_event('A');
        }
    break;

  case 536:
#line 3026 "fgl.yacc"
    {
		print_event_2();
        }
    break;

  case 537:
#line 3029 "fgl.yacc"
    {
		print_event('a');
        }
    break;

  case 538:
#line 3031 "fgl.yacc"
    {
		print_event_2();
        }
    break;

  case 551:
#line 3062 "fgl.yacc"
    { 
			print_gtk_field('B',0);
		}
    break;

  case 552:
#line 3064 "fgl.yacc"
    {
			print_gtk_field_2();
		}
    break;

  case 553:
#line 3067 "fgl.yacc"
    { 
			print_gtk_field('A',0);
		}
    break;

  case 554:
#line 3069 "fgl.yacc"
    {
			print_gtk_field_2();
		}
    break;

  case 555:
#line 3072 "fgl.yacc"
    {
			print_gtk_field('b',yyvsp[0].str);
		}
    break;

  case 556:
#line 3074 "fgl.yacc"
    { 
			print_gtk_field_2();
		}
    break;

  case 557:
#line 3077 "fgl.yacc"
    {
			print_gtk_field('a',yyvsp[0].str);
		}
    break;

  case 558:
#line 3079 "fgl.yacc"
    { 
			print_gtk_field_2();
		}
    break;

  case 559:
#line 3082 "fgl.yacc"
    { 
			print_gtk_field('o',yyvsp[0].str);
		}
    break;

  case 560:
#line 3084 "fgl.yacc"
    { 
			print_gtk_field_2();
		}
    break;

  case 561:
#line 3099 "fgl.yacc"
    {
		//print_niy("Free Cursor");
		lex_printcomment(" /* FIXME: Not implemented: Free Cursor */\n");;

		strcpy(yyval.str,"");
		}
    break;

  case 562:
#line 3115 "fgl.yacc"
    {sprintf(yyval.str,"%d",-1-(atoi(yyvsp[0].str)));}
    break;

  case 563:
#line 3116 "fgl.yacc"
    {strcpy(yyval.str,"-1");}
    break;

  case 564:
#line 3117 "fgl.yacc"
    {sprintf (yyval.str,"%d",atoi(yyvsp[0].str)+1);}
    break;

  case 565:
#line 3118 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 566:
#line 3119 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 567:
#line 3120 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 571:
#line 3128 "fgl.yacc"
    {sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str); }
    break;

  case 573:
#line 3134 "fgl.yacc"
    {sprintf(yyval.str,"\"%s\",1",yyvsp[0].str);}
    break;

  case 574:
#line 3135 "fgl.yacc"
    { sprintf(yyval.str,"int_to_id(%s)",yyvsp[-1].str); }
    break;

  case 575:
#line 3136 "fgl.yacc"
    { sprintf(yyval.str,"int_to_id(%s.%s)",yyvsp[-5].str,yyvsp[-1].str); }
    break;

  case 576:
#line 3138 "fgl.yacc"
    {sprintf(yyval.str,"\"%s\",%s",yyvsp[-3].str,yyvsp[-1].str);}
    break;

  case 577:
#line 3140 "fgl.yacc"
    {sprintf(yyval.str,"\"%s.*\",1",yyvsp[-2].str);}
    break;

  case 578:
#line 3142 "fgl.yacc"
    {sprintf(yyval.str,"\"%s.*\",%s",yyvsp[-5].str,yyvsp[-3].str);}
    break;

  case 579:
#line 3144 "fgl.yacc"
    {sprintf(yyval.str,"\"%s.%s\",1",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 580:
#line 3146 "fgl.yacc"
    {sprintf(yyval.str,"\"%s.%s\",%s",yyvsp[-5].str,yyvsp[0].str,yyvsp[-3].str);}
    break;

  case 581:
#line 3149 "fgl.yacc"
    {
				print_pushchar(yyvsp[0].str);
				addmap("Cursor",last_var,curr_func,yylineno,infilename);
			}
    break;

  case 582:
#line 3156 "fgl.yacc"
    {sprintf(yyval.str,"%s",yyvsp[0].str);}
    break;

  case 583:
#line 3158 "fgl.yacc"
    {sprintf(yyval.str,"%s",yyvsp[0].str);
addmap("Window",last_var,curr_func,yylineno,infilename);
}
    break;

  case 584:
#line 3164 "fgl.yacc"
    {sprintf(yyval.str,"%s",yyvsp[0].str);
addmap("Open Window",last_var,curr_func,yylineno,infilename);
}
    break;

  case 585:
#line 3169 "fgl.yacc"
    {sprintf(yyval.str,"%s",yyvsp[0].str);
addmap("Form",last_var,curr_func,yylineno,infilename);
}
    break;

  case 586:
#line 3174 "fgl.yacc"
    {sprintf(yyval.str,"%s",yyvsp[0].str);
addmap("Open Form",last_var,curr_func,yylineno,infilename);
}
    break;

  case 587:
#line 3179 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 588:
#line 3179 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 589:
#line 3182 "fgl.yacc"
    { 
			strcpy(yyval.str,downshift(yyvsp[-1].str)) ;
}
    break;

  case 590:
#line 3193 "fgl.yacc"
    {
			sprintf(yyval.str,"%s",yyvsp[-1].str) ;
			}
    break;

  case 591:
#line 3198 "fgl.yacc"
    {
sprintf(yyval.str,"\"%s_%s\"",clobber,downshift(yyvsp[0].str)) ;
strcpy(last_var,downshift(yyvsp[0].str));
}
    break;

  case 592:
#line 3202 "fgl.yacc"
    {
		sprintf(yyval.str,"aclfgli_str_to_id(%s)",yyvsp[-1].str);
		sprintf(last_var,"->%s",yyvsp[-1].str);
	}
    break;

  case 595:
#line 3210 "fgl.yacc"
    {
		debug("Setident\n");
		/* chk4var=1; */
	strcpy(yyval.str,"");
	   }
    break;

  case 596:
#line 3216 "fgl.yacc"
    {
		debug("Unsetident\n");
		chk4var=0;
		}
    break;

  case 597:
#line 3220 "fgl.yacc"
    {sprintf(yyval.str,"\"%s\",1",yyvsp[0].str);}
    break;

  case 598:
#line 3222 "fgl.yacc"
    {sprintf(yyval.str,"\"%s\",%s",yyvsp[-3].str,yyvsp[-1].str);}
    break;

  case 599:
#line 3224 "fgl.yacc"
    {sprintf(yyval.str,"\"%s.*\",1",yyvsp[-2].str);}
    break;

  case 600:
#line 3226 "fgl.yacc"
    {sprintf(yyval.str,"\"%s.*\",%s",yyvsp[-5].str,yyvsp[-3].str);}
    break;

  case 601:
#line 3228 "fgl.yacc"
    {sprintf(yyval.str,"\"%s.%s\",1",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 602:
#line 3230 "fgl.yacc"
    {sprintf(yyval.str,"\"%s.%s\",%s",yyvsp[-5].str,yyvsp[0].str,yyvsp[-3].str);}
    break;

  case 603:
#line 3233 "fgl.yacc"
    {
debug("Scanvar=%d",scan_variable(yyvsp[0].str)&15);
if ((scan_variable(yyvsp[0].str)&15)!=0) {
yyerror("Only a character variable can be used for this");
YYERROR;
}
}
    break;

  case 605:
#line 3242 "fgl.yacc"
    {
		sprintf(yyval.str,".%s",yyvsp[0].str);
}
    break;

  case 649:
#line 3303 "fgl.yacc"
    {
	char buff[256];
	print_goto(yyvsp[0].str);
}
    break;

  case 650:
#line 3317 "fgl.yacc"
    {
print_gui_do_menuitems(yyvsp[0].str,'C');
}
    break;

  case 652:
#line 3324 "fgl.yacc"
    {sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 653:
#line 3327 "fgl.yacc"
    {
        sprintf(yyval.str,"\"%s\"",yyvsp[0].str);
}
    break;

  case 654:
#line 3333 "fgl.yacc"
    {
print_gui_do_menuitems(yyvsp[0].str,'U');
}
    break;

  case 655:
#line 3339 "fgl.yacc"
    {
print_gui_do_menuitems(yyvsp[0].str,'D');
}
    break;

  case 656:
#line 3343 "fgl.yacc"
    {
print_gui_do_fields(yyvsp[0].str,'D');
}
    break;

  case 657:
#line 3347 "fgl.yacc"
    {
print_gui_do_form(yyvsp[-2].str,yyvsp[0].str,'D');
}
    break;

  case 658:
#line 3353 "fgl.yacc"
    {
print_gui_do_menuitems(yyvsp[0].str,'E');
}
    break;

  case 659:
#line 3357 "fgl.yacc"
    {
print_gui_do_fields(yyvsp[0].str,'E');
}
    break;

  case 660:
#line 3361 "fgl.yacc"
    {
print_gui_do_form(yyvsp[-2].str,yyvsp[0].str,'E');
}
    break;

  case 661:
#line 3366 "fgl.yacc"
    {start_state("messagebox",1);}
    break;

  case 662:
#line 3371 "fgl.yacc"
    {start_state("messagebox",0);}
    break;

  case 681:
#line 3412 "fgl.yacc"
    {
		print_if_start();
	}
    break;

  case 682:
#line 3417 "fgl.yacc"
    {
		print_if_end();
	}
    break;

  case 684:
#line 3422 "fgl.yacc"
    {
		print_if_else();
	}
    break;

  case 686:
#line 3425 "fgl.yacc"
    {
		print_if_else();
		}
    break;

  case 687:
#line 3427 "fgl.yacc"
    {

		print_if_start();
	}
    break;

  case 688:
#line 3430 "fgl.yacc"
    {
		print_if_end();
	}
    break;

  case 689:
#line 3435 "fgl.yacc"
    {
	print_import(yyvsp[-3].str,atoi(yyvsp[-1].str));
}
    break;

  case 690:
#line 3440 "fgl.yacc"
    { add_ex_dtype(yyvsp[0].str); }
    break;

  case 691:
#line 3450 "fgl.yacc"
    {debug("init to\n");}
    break;

  case 692:
#line 3451 "fgl.yacc"
    {
	print_init();
 }
    break;

  case 693:
#line 3454 "fgl.yacc"
    {
	print_init_table(yyvsp[0].str);
}
    break;

  case 695:
#line 3460 "fgl.yacc"
    {sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 696:
#line 3464 "fgl.yacc"
    {setrecord(yyval.str,yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 697:
#line 3465 "fgl.yacc"
    {setrecord(yyval.str,yyvsp[-2].str,0);}
    break;

  case 700:
#line 3479 "fgl.yacc"
    {
sprintf(yyval.str,"0");
}
    break;

  case 701:
#line 3481 "fgl.yacc"
    {
sprintf(yyval.str,"1");
}
    break;

  case 704:
#line 3490 "fgl.yacc"
    {
		print_befaft_field_1(yyvsp[0].str);
}
    break;

  case 705:
#line 3492 "fgl.yacc"
    {
	print_befaft_field_2();
}
    break;

  case 706:
#line 3496 "fgl.yacc"
    {
		print_befaft_field_1(yyvsp[0].str);
}
    break;

  case 707:
#line 3498 "fgl.yacc"
    {
	print_befaft_field_2();
}
    break;

  case 708:
#line 3501 "fgl.yacc"
    {
		print_befaft_field_1("AFT_ROW");
}
    break;

  case 709:
#line 3503 "fgl.yacc"
    {
	print_befaft_field_2();
}
    break;

  case 710:
#line 3506 "fgl.yacc"
    {
		lex_printcomment("/* before row */ \n");
		print_befaft_field_1("BEF_ROW");
}
    break;

  case 711:
#line 3509 "fgl.yacc"
    {
	print_befaft_field_2();
		}
    break;

  case 712:
#line 3512 "fgl.yacc"
    {
	print_onkey_1(yyvsp[0].str);
}
    break;

  case 713:
#line 3514 "fgl.yacc"
    {
	print_onkey_2();
}
    break;

  case 714:
#line 3517 "fgl.yacc"
    {
		print_befaft_field_1("AFTER_INP");
}
    break;

  case 715:
#line 3519 "fgl.yacc"
    {
	print_befaft_field_2();
}
    break;

  case 716:
#line 3522 "fgl.yacc"
    {
		print_befaft_field_1("BEFORE_INP");
}
    break;

  case 717:
#line 3524 "fgl.yacc"
    {
	print_befaft_field_2();
}
    break;

  case 718:
#line 3527 "fgl.yacc"
    {lex_printcomment("/* before insert/delete */ \n");
		print_befaft_field_1(yyvsp[0].str);
}
    break;

  case 719:
#line 3529 "fgl.yacc"
    {
	print_befaft_field_2();
}
    break;

  case 720:
#line 3532 "fgl.yacc"
    {
		print_befaft_field_1(yyvsp[0].str);
}
    break;

  case 721:
#line 3534 "fgl.yacc"
    {
	print_befaft_field_2();
}
    break;

  case 722:
#line 3540 "fgl.yacc"
    {sprintf(yyval.str,"(%s)",yyvsp[0].str);}
    break;

  case 723:
#line 3541 "fgl.yacc"
    {
	char buff[256];
	sprintf(buff,"(%s)",yyvsp[0].str);
	generate_or(yyval.str,yyvsp[-2].str,buff);
	}
    break;

  case 724:
#line 3549 "fgl.yacc"
    {strcpy(yyval.str,"AFT_INSERT");}
    break;

  case 725:
#line 3550 "fgl.yacc"
    {strcpy(yyval.str,"AFT_DELETE");}
    break;

  case 726:
#line 3555 "fgl.yacc"
    {sprintf(yyval.str,"(%s)",yyvsp[0].str);}
    break;

  case 727:
#line 3556 "fgl.yacc"
    {
	char buff[80];
		sprintf(buff,"(%s)",yyvsp[0].str);
		generate_or(yyval.str,yyvsp[-2].str,yyvsp[0].str);
 }
    break;

  case 728:
#line 3565 "fgl.yacc"
    {strcpy(yyval.str,"BEF_INSERT");}
    break;

  case 729:
#line 3566 "fgl.yacc"
    {strcpy(yyval.str,"BEF_DELETE");}
    break;

  case 730:
#line 3573 "fgl.yacc"
    {sprintf(yyval.str,"BEF_FIELD_CHK(%s)",yyvsp[0].str);}
    break;

  case 731:
#line 3574 "fgl.yacc"
    {
	char buff[80];
	sprintf(buff,"BEF_FIELD_CHK(%s)",yyvsp[0].str);
	generate_or(yyval.str,yyvsp[-2].str,buff);
	}
    break;

  case 732:
#line 3582 "fgl.yacc"
    {sprintf(yyval.str,"AFT_FIELD_CHK(%s)",yyvsp[0].str);}
    break;

  case 733:
#line 3583 "fgl.yacc"
    {
	char buff[80];
	sprintf(buff,"AFT_FIELD_CHK(%s)",yyvsp[0].str);
	generate_or(yyval.str,yyvsp[-2].str,buff);
	}
    break;

  case 734:
#line 3592 "fgl.yacc"
    {
print_next_field(yyvsp[0].str);
}
    break;

  case 735:
#line 3597 "fgl.yacc"
    {
print_next_form_field(yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 736:
#line 3602 "fgl.yacc"
    {sprintf(yyval.str,"\"+\",0");}
    break;

  case 737:
#line 3603 "fgl.yacc"
    {sprintf(yyval.str,"\"-\",0");}
    break;

  case 739:
#line 3608 "fgl.yacc"
    {
print_input_1();
}
    break;

  case 740:
#line 3611 "fgl.yacc"
    {
print_input_2(yyvsp[-2].str);
}
    break;

  case 741:
#line 3619 "fgl.yacc"
    {
print_input(1,yyvsp[-2].str,yyvsp[-1].str,0);
strcpy(yyval.str,get_formloop_str(0));
}
    break;

  case 742:
#line 3624 "fgl.yacc"
    {
print_input(0,yyvsp[-4].str,yyvsp[-1].str,yyvsp[-2].str);
strcpy(yyval.str,get_formloop_str(0));
}
    break;

  case 743:
#line 3628 "fgl.yacc"
    {
inp_flags=0;}
    break;

  case 744:
#line 3630 "fgl.yacc"
    {
strcpy(yyval.str,print_input_array(yyvsp[-8].str,yyvsp[-2].str,yyvsp[-7].str,yyvsp[-5].str,yyvsp[0].str));
}
    break;

  case 745:
#line 3639 "fgl.yacc"
    {
		print_scroll(yyvsp[-1].str,yyvsp[0].str);
	}
    break;

  case 746:
#line 3644 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 747:
#line 3645 "fgl.yacc"
    {strcpy(yyval.str,"-1");}
    break;

  case 748:
#line 3646 "fgl.yacc"
    {sprintf(yyval.str,"%s",yyvsp[0].str);}
    break;

  case 749:
#line 3647 "fgl.yacc"
    {sprintf(yyval.str,"-%s",yyvsp[0].str);}
    break;

  case 750:
#line 3650 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 752:
#line 3656 "fgl.yacc"
    {iskey=1;}
    break;

  case 753:
#line 3656 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);iskey=0;}
    break;

  case 754:
#line 3658 "fgl.yacc"
    {strcpy(yyval.str,"->ANY");}
    break;

  case 755:
#line 3661 "fgl.yacc"
    {iskey=1;}
    break;

  case 756:
#line 3661 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);iskey=0;}
    break;

  case 757:
#line 3663 "fgl.yacc"
    {sprintf(yyval.str,"key_val(\"%s\")",yyvsp[0].str);iskey=0;}
    break;

  case 758:
#line 3667 "fgl.yacc"
    {start_state("keymode",1);iskey=1;}
    break;

  case 759:
#line 3667 "fgl.yacc"
    {sprintf(yyval.str,"key_val(\"%s\")",yyvsp[0].str);iskey=0;start_state("keymode",0);}
    break;

  case 760:
#line 3670 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 761:
#line 3671 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[-1].str);}
    break;

  case 763:
#line 3674 "fgl.yacc"
    {
	sprintf(yyval.str,"%s||%s",yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 764:
#line 3679 "fgl.yacc"
    {start_state("keymode",1);}
    break;

  case 765:
#line 3679 "fgl.yacc"
    {start_state("keymode",0);strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 770:
#line 3686 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 771:
#line 3687 "fgl.yacc"
    {strcpy(yyval.str,"escape");}
    break;

  case 772:
#line 3688 "fgl.yacc"
    {strcpy(yyval.str,"up");}
    break;

  case 773:
#line 3689 "fgl.yacc"
    {strcpy(yyval.str,"down");}
    break;

  case 774:
#line 3690 "fgl.yacc"
    {strcpy(yyval.str,"return");}
    break;

  case 775:
#line 3691 "fgl.yacc"
    {strcpy(yyval.str,"delete");}
    break;

  case 776:
#line 3692 "fgl.yacc"
    {strcpy(yyval.str,"tab");}
    break;

  case 777:
#line 3693 "fgl.yacc"
    {strcpy(yyval.str,"left");}
    break;

  case 778:
#line 3694 "fgl.yacc"
    {strcpy(yyval.str,"right");}
    break;

  case 779:
#line 3695 "fgl.yacc"
    {strcpy(yyval.str,"nextpage");}
    break;

  case 780:
#line 3696 "fgl.yacc"
    {strcpy(yyval.str,"prevpage");}
    break;

  case 781:
#line 3697 "fgl.yacc"
    { rm_quotes(yyvsp[0].str); strcpy(yyval.str,yyvsp[0].str); }
    break;

  case 782:
#line 3701 "fgl.yacc"
    { 
char buff[256];
printf("Label : %s\n",get_idents(0));
strcpy(buff,get_idents(0));
convlower(buff);
print_label(buff);
}
    break;

  case 783:
#line 3719 "fgl.yacc"
    {chk4var=1;}
    break;

  case 784:
#line 3719 "fgl.yacc"
    {chk4var=0;
expand_obind();
lex_printcomment("/*let3*/\n");}
    break;

  case 785:
#line 3722 "fgl.yacc"
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
#line 3745 "fgl.yacc"
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
#line 3763 "fgl.yacc"
    {
		if (!print_linked_cmd('S',yyvsp[0].str)) yyerror("Not a linked variable");
	}
    break;

  case 789:
#line 3769 "fgl.yacc"
    {
		 if (!print_linked_cmd('D',yyvsp[0].str)) yyerror("Not a linked variable");
	}
    break;

  case 790:
#line 3775 "fgl.yacc"
    {
		 if (!print_linked_cmd('U',yyvsp[0].str)) yyerror("Not a linked variable");
}
    break;

  case 791:
#line 3781 "fgl.yacc"
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
#line 3792 "fgl.yacc"
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
#line 3815 "fgl.yacc"
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
#line 3831 "fgl.yacc"
    {
	}
    break;

  case 803:
#line 3854 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 807:
#line 3862 "fgl.yacc"
    {
		print_at_termination(yyvsp[0].str);
	}
    break;

  case 825:
#line 3888 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 826:
#line 3889 "fgl.yacc"
    {
strcpy(yyval.str,"static ");
}
    break;

  case 827:
#line 3897 "fgl.yacc"
    {
  clr_variable(); lastlineno=yylineno;
  clr_function_constants (); 
}
    break;

  case 828:
#line 3902 "fgl.yacc"
    { 
  sprintf(curr_func,"%s",yyvsp[-1].str);
  addmap("Declare Function",curr_func,"MODULE",yylineno,infilename);
  print_func_start(yyvsp[-3].str,yyvsp[-1].str,0);
  printDeclareFunctionStack(yyvsp[-1].str);
  cnt=0;
}
    break;

  case 829:
#line 3910 "fgl.yacc"
    {
  lex_printcomment("/* new function %s parameters*/\n",yyvsp[-1].str);
  push_blockcommand("FUNC");
  lex_printcomment("/* define section */\n");
}
    break;

  case 830:
#line 3916 "fgl.yacc"
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
#line 3931 "fgl.yacc"
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
#line 3944 "fgl.yacc"
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
#line 3953 "fgl.yacc"
    {
	print_variables();
    printDeclareFunctionStack("MAIN");
    print_fgllib_start(hdr_dbname);
    printInitFunctionStack();
    printPushFunction();
  }
    break;

  case 835:
#line 3960 "fgl.yacc"
    {
pop_blockcommand("MAIN");
print_main_end();
lex_printcomment("/*end main */\n");}
    break;

  case 836:
#line 3967 "fgl.yacc"
    {
    printPopFunction();
    print_return(atoi(yyvsp[0].str));
  }
    break;

  case 837:
#line 3973 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 838:
#line 3973 "fgl.yacc"
    {
lex_printcomment("/* Got expr list */");
sprintf(yyval.str,"%s",yyvsp[0].str);}
    break;

  case 839:
#line 3978 "fgl.yacc"
    {open_db(yyvsp[0].str);
			strcpy(hdr_dbname,yyvsp[0].str);
			lastlineno=yylineno;}
    break;

  case 840:
#line 3983 "fgl.yacc"
    {
}
    break;

  case 846:
#line 3995 "fgl.yacc"
    {
strcpy(curr_func,"[Globals]");
set_current_variable_scope('g');
lex_printcomment("/* start of globals */\n");
}
    break;

  case 848:
#line 4003 "fgl.yacc"
    {
	lex_printcomment("/* end of globals */");
	debug("end of globals\n");
	lastlineno=yylineno;
	set_current_variable_scope('m');
}
    break;

  case 849:
#line 4009 "fgl.yacc"
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
#line 4023 "fgl.yacc"
    {
  addmap("Define Member Function",curr_func,"MODULE",yylineno,infilename);
}
    break;

  case 851:
#line 4027 "fgl.yacc"
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
#line 4040 "fgl.yacc"
    {
	print_variables();
  lex_printcomment("/*end of define section */\n");
  print_param('f');
  printPushFunction();
  print_func_args(atoi(yyvsp[-3].str));
}
    break;

  case 854:
#line 4058 "fgl.yacc"
    {
	start_state("menu",1);
   	menu_cnt=npush_menu();
   	menu_cmd_cnt[menu_cnt]=1;
   	push_blockcommand("MENU");
	print_menu_1();
	}
    break;

  case 855:
#line 4065 "fgl.yacc"
    {
	start_state("menu",0);
	}
    break;

  case 856:
#line 4071 "fgl.yacc"
    {
   print_end_menu_1();
   add_continue_blockcommand ("MENU");
print_end_menu_2();
   pop_blockcommand("MENU");
   pop_menu();
}
    break;

  case 857:
#line 4082 "fgl.yacc"
    {
	 lex_printcomment("/* Block%d_m2 (Before menu) */",menu_cnt);
		print_menu_block(-2) ;
                  }
    break;

  case 858:
#line 4086 "fgl.yacc"
    {
		print_menu_block_end();
	}
    break;

  case 859:
#line 4093 "fgl.yacc"
    {
debug("Menu=%d menu cnt=%d",menu_cnt,menu_cmd_cnt[menu_cnt]);
		push_command(menu_cnt,menu_cmd_cnt[menu_cnt],yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);
		lex_printcomment("/* Block%d_%d */",menu_cnt,menu_cmd_cnt[menu_cnt]-1);
		print_menu_block(menu_cmd_cnt[menu_cnt]-1);
		menu_cmd_cnt[menu_cnt]++;
		}
    break;

  case 860:
#line 4100 "fgl.yacc"
    {
		print_menu_block_end();
}
    break;

  case 861:
#line 4106 "fgl.yacc"
    {
		push_command(menu_cnt,menu_cmd_cnt[menu_cnt],yyvsp[-1].str,"\"\"","\"\"",0);
		print_menu_block(menu_cmd_cnt[menu_cnt]-1);
		menu_cmd_cnt[menu_cnt]++;
		}
    break;

  case 862:
#line 4111 "fgl.yacc"
    {
		print_menu_block_end();
}
    break;

  case 865:
#line 4118 "fgl.yacc"
    {strcpy(yyval.str,"\"EMPTY\"");}
    break;

  case 866:
#line 4119 "fgl.yacc"
    {sprintf(yyval.str,"\"%s\"",yyvsp[0].str);}
    break;

  case 867:
#line 4121 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str); }
    break;

  case 868:
#line 4122 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 869:
#line 4125 "fgl.yacc"
    {strcpy(yyval.str,"\"\"");}
    break;

  case 870:
#line 4126 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 871:
#line 4127 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 872:
#line 4129 "fgl.yacc"
    {
	print_option_op('N',yyvsp[0].str);
}
    break;

  case 873:
#line 4134 "fgl.yacc"
    {
	print_option_op('S',yyvsp[0].str);
}
    break;

  case 874:
#line 4139 "fgl.yacc"
    {
	print_option_op('H',yyvsp[0].str);
}
    break;

  case 875:
#line 4146 "fgl.yacc"
    {sprintf(yyval.str,"MENU_ALL");}
    break;

  case 879:
#line 4153 "fgl.yacc"
    {sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 880:
#line 4155 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);  
push_menu_title(yyval.str);}
    break;

  case 881:
#line 4157 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str); 
push_menu_title(yyval.str);}
    break;

  case 882:
#line 4166 "fgl.yacc"
    {
                strcpy(menuhandler,yyvsp[0].str);
	sprintf(curr_func,"%s",yyvsp[0].str); 
	print_gtk_menuhandler_1(yyvsp[0].str);
                push_blockcommand("MENUH");
}
    break;

  case 883:
#line 4172 "fgl.yacc"
    {
		print_variables();
        }
    break;

  case 884:
#line 4176 "fgl.yacc"
    {
                        pop_blockcommand("MENUH");
			print_gtk_menuhandler_end();
                }
    break;

  case 887:
#line 4188 "fgl.yacc"
    {

		print_gtk_menuhandler_bsm();

                push_blockcommand("BSM");
        }
    break;

  case 888:
#line 4193 "fgl.yacc"
    {
                pop_blockcommand("BSM");
		print_gtk_menuhandler_bsm_end();

        }
    break;

  case 889:
#line 4198 "fgl.yacc"
    {
print_gtk_menuhandler_on(yyvsp[0].str);
                push_blockcommand("ON");
        }
    break;

  case 890:
#line 4201 "fgl.yacc"
    {
                pop_blockcommand("ON");
		print_gtk_menuhandler_on_end();
}
    break;

  case 891:
#line 4210 "fgl.yacc"
    {start_state("message",0);}
    break;

  case 892:
#line 4213 "fgl.yacc"
    {
		print_message(0,"0",0);
		start_state("message",0);
	   }
    break;

  case 893:
#line 4217 "fgl.yacc"
    { 
		print_message(0,yyvsp[-1].str,atoi(yyvsp[0].str));
		start_state("message",0);
	  }
    break;

  case 894:
#line 4221 "fgl.yacc"
    { 
		print_message(0,"0",atoi(yyvsp[0].str));
		start_state("message",0);
	  }
    break;

  case 901:
#line 4238 "fgl.yacc"
    {start_state("message",1);}
    break;

  case 903:
#line 4240 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 904:
#line 4240 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 905:
#line 4243 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 906:
#line 4253 "fgl.yacc"
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
#line 4290 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 910:
#line 4297 "fgl.yacc"
    { 
         sprintf (yyval.str, "%s.%s", yyvsp[-1].str, yyvsp[0].str); 
         lex_printcomment("/* record building -> %s */\n",yyval.str);
         }
    break;

  case 911:
#line 4302 "fgl.yacc"
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
#line 4346 "fgl.yacc"
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
#line 4360 "fgl.yacc"
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
#line 4384 "fgl.yacc"
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
#line 4438 "fgl.yacc"
    {
		debug("---> Subscript or substring");
		strcpy(yyval.str,yyvsp[-1].str);
	}
    break;

  case 923:
#line 4443 "fgl.yacc"
    {
		debug("---> Subscript & substring");
		sprintf(yyval.str,"%s:%s",yyvsp[-4].str,yyvsp[-1].str);
	}
    break;

  case 924:
#line 4451 "fgl.yacc"
    {
debug("List element");
  sprintf (yyval.str, "%s", yyvsp[0].str);
}
    break;

  case 925:
#line 4456 "fgl.yacc"
    {
debug("List element continues");
  sprintf (yyval.str, "%s,%s", yyvsp[-2].str, yyvsp[0].str);
}
    break;

  case 926:
#line 4464 "fgl.yacc"
    {
  sprintf (yyval.str, "%s", yyvsp[0].str);
}
    break;

  case 927:
#line 4470 "fgl.yacc"
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
#line 4490 "fgl.yacc"
    {
		debug("Array..");
}
    break;

  case 929:
#line 4493 "fgl.yacc"
    { sprintf (yyval.str, "%s.%s", yyvsp[-3].str, yyvsp[0].str); }
    break;

  case 930:
#line 4495 "fgl.yacc"
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
#line 4543 "fgl.yacc"
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
#line 4595 "fgl.yacc"
    {
start_bind('f',0);
start_bind('O',0);
strcpy(yyval.str,"0");}
    break;

  case 938:
#line 4602 "fgl.yacc"
    {
start_bind('f',yyvsp[0].str);
start_bind('O',yyvsp[0].str);
sprintf(yyval.str,"1");
}
    break;

  case 939:
#line 4608 "fgl.yacc"
    {
int c;
c=add_bind('f',yyvsp[0].str);
c=add_bind('O',yyvsp[0].str);
sprintf(yyval.str,"%d",c); 
}
    break;

  case 940:
#line 4619 "fgl.yacc"
    {
lex_printcomment("/*STarted bind %s*/\n",yyvsp[0].str);
start_bind('i',yyvsp[0].str);
lex_printcomment("/*STarted bind 2*/\n");
strcpy(yyval.str,"");
}
    break;

  case 941:
#line 4626 "fgl.yacc"
    {
lex_printcomment("/* Added */\n");
add_bind('i',yyvsp[0].str);
strcpy(yyval.str,"");
}
    break;

  case 943:
#line 4634 "fgl.yacc"
    {sprintf(yyval.str,"%s.%s",yyvsp[-2].str,yyvsp[-1].str);}
    break;

  case 944:
#line 4637 "fgl.yacc"
    {lex_printcomment("/* Variable */\n");}
    break;

  case 945:
#line 4638 "fgl.yacc"
    { debug("Got an ibind thru..."); sprintf(yyval.str,"%s\n%s",yyvsp[-2].str,yyvsp[0].str); }
    break;

  case 947:
#line 4640 "fgl.yacc"
    {sprintf(yyval.str,"\"%s\"",yyvsp[0].str);}
    break;

  case 948:
#line 4641 "fgl.yacc"
    {sprintf(yyval.str,"\"%s\"",yyvsp[0].str);}
    break;

  case 949:
#line 4644 "fgl.yacc"
    {
start_bind('o',yyvsp[0].str);
}
    break;

  case 950:
#line 4647 "fgl.yacc"
    {
add_bind('o',yyvsp[0].str);
strcpy(yyval.str,"");
}
    break;

  case 951:
#line 4653 "fgl.yacc"
    {
	addmap("OBIND",yyvsp[0].str,curr_func,yylineno,infilename);
	}
    break;

  case 952:
#line 4656 "fgl.yacc"
    { debug("Got an obind thru..."); sprintf(yyval.str,"%s\n%s",yyvsp[-2].str,yyvsp[0].str); }
    break;

  case 953:
#line 4660 "fgl.yacc"
    {
lex_printcomment("/* start obind with  %s*/\n",yyvsp[0].str);
start_bind('o',yyvsp[0].str);
}
    break;

  case 954:
#line 4664 "fgl.yacc"
    {
lex_printcomment("/* add to obind %s */\n",yyvsp[0].str);
add_bind('o',yyvsp[0].str);
strcpy(yyval.str,"");
}
    break;

  case 955:
#line 4671 "fgl.yacc"
    {
lex_printcomment("/* Read variable %s*/\n",yyvsp[0].str);
}
    break;

  case 956:
#line 4676 "fgl.yacc"
    {
    lex_printcomment("/* use_arr_var */\n");
    start_arr_bind('o',yyvsp[0].str);
    lex_printcomment("/* use_arr_var complete */\n");
}
    break;

  case 957:
#line 4683 "fgl.yacc"
    {
start_bind('O',yyvsp[0].str);
}
    break;

  case 958:
#line 4686 "fgl.yacc"
    {
               add_bind('O',yyvsp[0].str);
               strcpy(yyval.str,"");
}
    break;

  case 963:
#line 4699 "fgl.yacc"
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
#line 4712 "fgl.yacc"
    {
lex_printcomment("/*STarted bind %s*/\n",yyvsp[0].str);
start_bind('N',yyvsp[0].str);
lex_printcomment("/*STarted bind 2*/\n");
strcpy(yyval.str,"");
}
    break;

  case 965:
#line 4719 "fgl.yacc"
    {
lex_printcomment("/* Added */\n");
add_bind('N',yyvsp[0].str);
strcpy(yyval.str,"");
}
    break;

  case 966:
#line 4726 "fgl.yacc"
    {
		strcpy(yyval.str,yyvsp[0].str);
	}
    break;

  case 967:
#line 4729 "fgl.yacc"
    {
			sprintf(yyval.str,"%s\n%s",yyvsp[-2].str,yyvsp[0].str);
		}
    break;

  case 968:
#line 4743 "fgl.yacc"
    {
form_attrib.iswindow=1;
print_open_window(yyvsp[-5].str,yyvsp[-1].str);
sprintf(yyval.str,"open window");
}
    break;

  case 973:
#line 4760 "fgl.yacc"
    {
	print_niy("OPEN_STATUSBOX");
}
    break;

  case 974:
#line 4765 "fgl.yacc"
    {
addmap("Call Formhandler",yyvsp[0].str,curr_func,yylineno,infilename); 
}
    break;

  case 975:
#line 4771 "fgl.yacc"
    {
		print_open_form(yyvsp[0].str,yyvsp[-1].str,yyvsp[-1].str);
		}
    break;

  case 977:
#line 4778 "fgl.yacc"
    { form_attrib.iswindow=0;strcpy(yyval.str,"open_form(%s);"); }
    break;

  case 978:
#line 4783 "fgl.yacc"
    {sprintf(yyval.str,"open_gui_form(%%s,%s,%s,%s,hnd_e_%s,hnd_c_%s);",yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[0].str,yyvsp[0].str);}
    break;

  case 979:
#line 4786 "fgl.yacc"
    {strcpy(yyval.str,"0,0");}
    break;

  case 980:
#line 4787 "fgl.yacc"
    {sprintf(yyval.str,"%s,2",yyvsp[-5].str);}
    break;

  case 981:
#line 4790 "fgl.yacc"
    {strcpy(yyval.str,"\"\"");}
    break;

  case 982:
#line 4791 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 983:
#line 4794 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 984:
#line 4795 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 985:
#line 4800 "fgl.yacc"
    {
print_open_session(yyvsp[-3].str,yyvsp[-1].str,yyvsp[0].str);

}
    break;

  case 986:
#line 4807 "fgl.yacc"
    {
	print_open_cursor(yyvsp[0].str,"0");
}
    break;

  case 987:
#line 4810 "fgl.yacc"
    {
	print_open_cursor(yyvsp[-3].str,yyvsp[0].str); /* CHANGED from $<str>4 */
}
    break;

  case 988:
#line 4816 "fgl.yacc"
    {sprintf(yyval.str,"0,0");}
    break;

  case 989:
#line 4818 "fgl.yacc"
    {sprintf(yyval.str,"%s, %s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 990:
#line 4820 "fgl.yacc"
    {sprintf(yyval.str,"%s, %s",yyvsp[-3].str,yyvsp[0].str);}
    break;

  case 991:
#line 4822 "fgl.yacc"
    {sprintf(yyval.str,"%s, %s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 992:
#line 4825 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 993:
#line 4825 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 994:
#line 4826 "fgl.yacc"
    {strcpy(yyval.str,"2");}
    break;

  case 995:
#line 4831 "fgl.yacc"
    {
	print_open_session(yyvsp[-1].str,yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 996:
#line 4839 "fgl.yacc"
    {strcpy(yyval.str,"\"default_conn\"");}
    break;

  case 997:
#line 4840 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 998:
#line 4845 "fgl.yacc"
    {sprintf(yyval.str,"0,0");}
    break;

  case 999:
#line 4847 "fgl.yacc"
    {sprintf(yyval.str,"%s, %s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1000:
#line 4849 "fgl.yacc"
    {sprintf(yyval.str,"%s, %s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1004:
#line 4866 "fgl.yacc"
    {
print_options('C',yyvsp[0].str);
}
    break;

  case 1005:
#line 4869 "fgl.yacc"
    {
print_options('E',yyvsp[0].str);
}
    break;

  case 1006:
#line 4872 "fgl.yacc"
    {
print_options('F',yyvsp[0].str);
}
    break;

  case 1007:
#line 4875 "fgl.yacc"
    {
lex_printc("set_option_value('M',%s);\n",yyvsp[0].str);
}
    break;

  case 1008:
#line 4878 "fgl.yacc"
    {
print_options('m',yyvsp[0].str);
}
    break;

  case 1009:
#line 4881 "fgl.yacc"
    {
print_options('P',yyvsp[0].str);
}
    break;

  case 1010:
#line 4884 "fgl.yacc"
    {
print_options('A',yyvsp[0].str);
iskey=0;
}
    break;

  case 1011:
#line 4888 "fgl.yacc"
    {
print_options('D',yyvsp[0].str);
iskey=0;
}
    break;

  case 1012:
#line 4892 "fgl.yacc"
    {
print_options('I',yyvsp[0].str);
iskey=0;
}
    break;

  case 1013:
#line 4896 "fgl.yacc"
    {
print_options('N',yyvsp[0].str);
}
    break;

  case 1014:
#line 4899 "fgl.yacc"
    {
print_options('p',yyvsp[0].str);
iskey=0;
}
    break;

  case 1015:
#line 4903 "fgl.yacc"
    {
print_options('H',yyvsp[0].str);
}
    break;

  case 1016:
#line 4906 "fgl.yacc"
    { print_set_helpfile(yyvsp[0].str); }
    break;

  case 1017:
#line 4907 "fgl.yacc"
    { print_set_langfile(yyvsp[0].str); }
    break;

  case 1018:
#line 4908 "fgl.yacc"
    {
print_options('d',yyvsp[0].str);
}
    break;

  case 1019:
#line 4911 "fgl.yacc"
    {
print_options('i',yyvsp[0].str);
}
    break;

  case 1020:
#line 4914 "fgl.yacc"
    {
print_options('W',"1");
}
    break;

  case 1021:
#line 4917 "fgl.yacc"
    {
print_options('W',"0");
}
    break;

  case 1022:
#line 4920 "fgl.yacc"
    {
print_options('f',"1");
}
    break;

  case 1023:
#line 4923 "fgl.yacc"
    {
print_options('f',"0");
}
    break;

  case 1024:
#line 4926 "fgl.yacc"
    {
print_options('S',"1");
}
    break;

  case 1025:
#line 4929 "fgl.yacc"
    {
print_options('S',"0");
}
    break;

  case 1026:
#line 4946 "fgl.yacc"
    {
	print_prepare(yyvsp[-2].str,yyvsp[0].str);
	addmap("Prepare",yyvsp[-2].str,curr_func,yylineno,infilename);
	print_undo_use(yyvsp[-4].str);
}
    break;

  case 1029:
#line 4956 "fgl.yacc"
    {

print_execute(yyvsp[0].str,0);

addmap("Execute",yyvsp[0].str,curr_func,yylineno,infilename);
}
    break;

  case 1030:
#line 4963 "fgl.yacc"
    {
	addmap("Execute",yyvsp[-2].str,curr_func,yylineno,infilename);
	print_execute(yyvsp[-2].str,1);
}
    break;

  case 1032:
#line 4984 "fgl.yacc"
    {
                push_blockcommand("PROMPT");

	print_prompt_1(yyvsp[-5].str,yyvsp[-3].str,yyvsp[-1].str,yyvsp[0].str) ;
}
    break;

  case 1033:
#line 4989 "fgl.yacc"
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
#line 5002 "fgl.yacc"
    {
		print_niy("GUI PROMPT");
	}
    break;

  case 1035:
#line 5007 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 1036:
#line 5008 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 1037:
#line 5012 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1041:
#line 5018 "fgl.yacc"
    {
	print_onkey_1(yyvsp[0].str);
}
    break;

  case 1042:
#line 5020 "fgl.yacc"
    {
	print_onkey_2_prompt();
}
    break;

  case 1044:
#line 5035 "fgl.yacc"
    {
		start_bind('i',0);
		}
    break;

  case 1045:
#line 5039 "fgl.yacc"
    {
		print_put();
	}
    break;

  case 1046:
#line 5045 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1047:
#line 5046 "fgl.yacc"
    { strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1048:
#line 5049 "fgl.yacc"
    {push_gen(PUTVAL,yyvsp[0].str);}
    break;

  case 1049:
#line 5050 "fgl.yacc"
    {push_gen(PUTVAL,yyvsp[0].str); sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1052:
#line 5066 "fgl.yacc"
    {
addmap("Start Report",yyvsp[-1].str,curr_func,yylineno,infilename);
print_start_report("P","\"lp\"",yyvsp[-1].str);
}
    break;

  case 1053:
#line 5071 "fgl.yacc"
    {
addmap("Start Report",yyvsp[-2].str,curr_func,yylineno,infilename);
print_start_report("F",yyvsp[0].str,yyvsp[-2].str);
}
    break;

  case 1054:
#line 5076 "fgl.yacc"
    {
addmap("Start Report",yyvsp[-2].str,curr_func,yylineno,infilename);
print_start_report("P",yyvsp[0].str,yyvsp[-2].str);
}
    break;

  case 1055:
#line 5081 "fgl.yacc"
    {
addmap("Start Report",yyvsp[0].str,curr_func,yylineno,infilename);
print_start_report("","\"\"",yyvsp[0].str);
}
    break;

  case 1061:
#line 5103 "fgl.yacc"
    {
addmap("Output to report",yyvsp[-5].str,curr_func,yylineno,infilename);
print_output_to_report(yyvsp[-5].str,yyvsp[-1].str); 
}
    break;

  case 1062:
#line 5110 "fgl.yacc"
    {
addmap("Finish Report",yyvsp[0].str,curr_func,yylineno,infilename);
print_finish_report(yyvsp[0].str);
}
    break;

  case 1063:
#line 5116 "fgl.yacc"
    { strcpy(yyval.str,yyvsp[0].str); }
    break;

  case 1064:
#line 5118 "fgl.yacc"
    {
	print_format_every_row();
}
    break;

  case 1068:
#line 5129 "fgl.yacc"
    { push_report_block("FIRST",'P');}
    break;

  case 1069:
#line 5130 "fgl.yacc"
    {print_rep_ret(0);}
    break;

  case 1070:
#line 5132 "fgl.yacc"
    { push_report_block("TRAILER",'T');}
    break;

  case 1071:
#line 5133 "fgl.yacc"
    {print_rep_ret(0);}
    break;

  case 1072:
#line 5135 "fgl.yacc"
    { push_report_block("HEADER",'p');}
    break;

  case 1073:
#line 5136 "fgl.yacc"
    {print_rep_ret(0);}
    break;

  case 1074:
#line 5138 "fgl.yacc"
    { push_report_block("EVERY",'E');}
    break;

  case 1075:
#line 5139 "fgl.yacc"
    {print_rep_ret(0);}
    break;

  case 1076:
#line 5141 "fgl.yacc"
    { push_report_block("LAST",'L');}
    break;

  case 1077:
#line 5142 "fgl.yacc"
    {print_rep_ret(0);}
    break;

  case 1078:
#line 5143 "fgl.yacc"
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
#line 5157 "fgl.yacc"
    {print_rep_ret(0);}
    break;

  case 1080:
#line 5159 "fgl.yacc"
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
#line 5176 "fgl.yacc"
    {print_rep_ret(0);}
    break;

  case 1088:
#line 5188 "fgl.yacc"
    {start_state("skip",1);}
    break;

  case 1089:
#line 5188 "fgl.yacc"
    {
	print_need_lines();
	start_state("skip",0);
}
    break;

  case 1090:
#line 5194 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 1091:
#line 5194 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 1092:
#line 5197 "fgl.yacc"
    {start_state("KWLINE",1);}
    break;

  case 1093:
#line 5197 "fgl.yacc"
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
#line 5207 "fgl.yacc"
    { print_skip_top(); }
    break;

  case 1095:
#line 5208 "fgl.yacc"
    { print_niy("FONT SIZE"); }
    break;

  case 1096:
#line 5209 "fgl.yacc"
    {
			if (rep_type!=REP_TYPE_PDF) {
				yyerror("SKIP BY is only in PDF reports");
				YYERROR;
			}
			print_skip_by(yyvsp[0].str);
		}
    break;

  case 1097:
#line 5216 "fgl.yacc"
    {
			if (rep_type!=REP_TYPE_PDF) {
				yyerror("SKIP TO is only in PDF reports");
				YYERROR;
			}
			print_skip_to(yyvsp[0].str);
		}
    break;

  case 1098:
#line 5228 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1104:
#line 5239 "fgl.yacc"
    {
	print_niy("PRINT AT...");
}
    break;

  case 1105:
#line 5244 "fgl.yacc"
    {
	print_report_print(0,yyvsp[0].str,0);
}
    break;

  case 1106:
#line 5248 "fgl.yacc"
    { 
	print_report_print_file(yyvsp[-1].str,yyvsp[0].str);
}
    break;

  case 1107:
#line 5253 "fgl.yacc"
    { 
	print_report_print_img(yyvsp[-1].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 1108:
#line 5259 "fgl.yacc"
    { strcpy(yyval.str,get_default_scaling());}
    break;

  case 1109:
#line 5260 "fgl.yacc"
    { strcpy(yyval.str,yyvsp[0].str); strcat(yyval.str,yyvsp[0].str); }
    break;

  case 1110:
#line 5261 "fgl.yacc"
    {sprintf(yyval.str,"%s %s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1111:
#line 5265 "fgl.yacc"
    {strcpy(yyval.str,"tiff");}
    break;

  case 1112:
#line 5266 "fgl.yacc"
    {strcpy(yyval.str,"gif");}
    break;

  case 1113:
#line 5267 "fgl.yacc"
    {strcpy(yyval.str,"png");}
    break;

  case 1114:
#line 5268 "fgl.yacc"
    {strcpy(yyval.str,"jpeg");}
    break;

  case 1115:
#line 5272 "fgl.yacc"
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
#line 5282 "fgl.yacc"
    {
strcpy(yyval.str,"0");
}
    break;

  case 1117:
#line 5284 "fgl.yacc"
    {
strcpy(yyval.str,"1");
}
    break;

  case 1118:
#line 5289 "fgl.yacc"
    {
	print_report_print(1,0,yyvsp[0].str);
	}
    break;

  case 1119:
#line 5292 "fgl.yacc"
    {
	print_report_print(1,0,yyvsp[0].str); /* changed from $<str>1 */
}
    break;

  case 1120:
#line 5297 "fgl.yacc"
    {
	strcpy(yyval.str,yyvsp[0].str); 
	}
    break;

  case 1121:
#line 5304 "fgl.yacc"
    {
int a;
a=add_report_agg('S',yyvsp[-2].ptr,yyvsp[0].ptr,racnt);
sprintf(yyval.str,"push_double(_g%d);\n",racnt);
racnt+=a;
}
    break;

  case 1122:
#line 5311 "fgl.yacc"
    {
int a;
a=add_report_agg('C',0,yyvsp[0].ptr,racnt);
sprintf(yyval.str,"push_int(_g%d);\n",racnt);
racnt+=a;
}
    break;

  case 1123:
#line 5318 "fgl.yacc"
    {
int a;
a=add_report_agg('C',0,yyvsp[0].ptr,racnt);
sprintf(yyval.str,"push_int(_g%d);\n",racnt);
racnt+=a;
}
    break;

  case 1124:
#line 5327 "fgl.yacc"
    {
int a;
a=add_report_agg('P',yyvsp[-2].ptr,yyvsp[0].ptr,racnt);
sprintf(yyval.str,"push_double((double)_g%d/(double)_g%d);\n",racnt,racnt+1);
racnt+=a;
}
    break;

  case 1125:
#line 5334 "fgl.yacc"
    {
int a;
a=add_report_agg('A',yyvsp[-2].ptr,yyvsp[0].ptr,racnt);
sprintf(yyval.str,"push_double(_g%d/(double)_g%d);\n",racnt,racnt+1);
racnt+=a;
}
    break;

  case 1126:
#line 5341 "fgl.yacc"
    {
int a;
a=add_report_agg('A',yyvsp[-2].ptr,yyvsp[0].ptr,racnt);
sprintf(yyval.str,"push_double(_g%d/_g%d);\n",racnt,racnt+1);
racnt+=a;
}
    break;

  case 1127:
#line 5348 "fgl.yacc"
    {
int a;
a=add_report_agg('N',yyvsp[-2].ptr,yyvsp[0].ptr,racnt);
sprintf(yyval.str,"push_double(_g%d);\n",racnt);
racnt+=a;
}
    break;

  case 1128:
#line 5355 "fgl.yacc"
    {
int a;
a=add_report_agg('X',yyvsp[-2].ptr,yyvsp[0].ptr,racnt);
sprintf(yyval.str,"push_double(_g%d);\n",racnt);
racnt+=a;
}
    break;

  case 1133:
#line 5368 "fgl.yacc"
    {rep_struct.left_margin=atoi(yyvsp[0].str);}
    break;

  case 1134:
#line 5369 "fgl.yacc"
    {rep_struct.right_margin=atoi(yyvsp[0].str);}
    break;

  case 1135:
#line 5370 "fgl.yacc"
    {rep_struct.top_margin=atoi(yyvsp[0].str);}
    break;

  case 1136:
#line 5371 "fgl.yacc"
    {rep_struct.bottom_margin=atoi(yyvsp[0].str);}
    break;

  case 1137:
#line 5372 "fgl.yacc"
    {rep_struct.page_length=atoi(yyvsp[0].str);}
    break;

  case 1138:
#line 5373 "fgl.yacc"
    { rep_struct.output_mode='P';strcpy(rep_struct.output_loc,"\"lp\"");}
    break;

  case 1139:
#line 5374 "fgl.yacc"
    {rep_struct.output_mode='F';strcpy(rep_struct.output_loc,yyvsp[0].str);}
    break;

  case 1140:
#line 5375 "fgl.yacc"
    {rep_struct.output_mode='F';strcpy(rep_struct.output_loc,yyvsp[0].str);}
    break;

  case 1141:
#line 5376 "fgl.yacc"
    {rep_struct.output_mode='P';strcpy(rep_struct.output_loc,yyvsp[0].str);}
    break;

  case 1142:
#line 5377 "fgl.yacc"
    {strcpy(rep_struct.top_of_page,yyvsp[0].str);}
    break;

  case 1145:
#line 5383 "fgl.yacc"
    {sprintf(yyval.str,"-%f",atof(yyvsp[-1].str));}
    break;

  case 1146:
#line 5384 "fgl.yacc"
    {sprintf(yyval.str,"-%f",atof(yyvsp[-1].str)*72.0); }
    break;

  case 1147:
#line 5385 "fgl.yacc"
    {sprintf(yyval.str,"-%f",atof(yyvsp[-1].str)*2.83465);}
    break;

  case 1148:
#line 5386 "fgl.yacc"
    {sprintf(yyval.str,"%f",atof(yyvsp[0].str));}
    break;

  case 1153:
#line 5395 "fgl.yacc"
    {pdf_rep_struct.left_margin=atof(yyvsp[0].str);debug("Left margin=%s\n",yyvsp[0].str);}
    break;

  case 1154:
#line 5396 "fgl.yacc"
    {pdf_rep_struct.right_margin=atof(yyvsp[0].str);}
    break;

  case 1155:
#line 5397 "fgl.yacc"
    {pdf_rep_struct.top_margin=atof(yyvsp[0].str);}
    break;

  case 1156:
#line 5398 "fgl.yacc"
    {pdf_rep_struct.bottom_margin=atof(yyvsp[0].str);}
    break;

  case 1157:
#line 5399 "fgl.yacc"
    {pdf_rep_struct.page_length=atof(yyvsp[0].str);}
    break;

  case 1158:
#line 5400 "fgl.yacc"
    {pdf_rep_struct.page_width=atof(yyvsp[0].str);}
    break;

  case 1159:
#line 5401 "fgl.yacc"
    {strcpy(pdf_rep_struct.font_name,yyvsp[0].str);}
    break;

  case 1160:
#line 5402 "fgl.yacc"
    {pdf_rep_struct.font_size=atof(yyvsp[0].str);}
    break;

  case 1161:
#line 5404 "fgl.yacc"
    {pdf_rep_struct.paper_size=1;}
    break;

  case 1162:
#line 5405 "fgl.yacc"
    {pdf_rep_struct.paper_size=2;}
    break;

  case 1163:
#line 5406 "fgl.yacc"
    {pdf_rep_struct.paper_size=3;}
    break;

  case 1164:
#line 5407 "fgl.yacc"
    {pdf_rep_struct.paper_size=5;}
    break;

  case 1165:
#line 5409 "fgl.yacc"
    {pdf_rep_struct.paper_size=-1;}
    break;

  case 1166:
#line 5410 "fgl.yacc"
    {pdf_rep_struct.paper_size=-2;}
    break;

  case 1167:
#line 5411 "fgl.yacc"
    {pdf_rep_struct.paper_size=-3;}
    break;

  case 1168:
#line 5412 "fgl.yacc"
    {pdf_rep_struct.paper_size=-5;}
    break;

  case 1172:
#line 5417 "fgl.yacc"
    {pdf_rep_struct.output_mode='F';strcpy(pdf_rep_struct.output_loc,yyvsp[0].str);}
    break;

  case 1173:
#line 5418 "fgl.yacc"
    {pdf_rep_struct.output_mode='P';strcpy(pdf_rep_struct.output_loc,yyvsp[0].str);}
    break;

  case 1177:
#line 5425 "fgl.yacc"
    {
int a;
a=print_bind('O');
print_order_by_type(2);
sprintf(yyval.str,"%d",a);
}
    break;

  case 1178:
#line 5432 "fgl.yacc"
    {
int a;
a=print_bind('O');
print_order_by_type(1);
sprintf(yyval.str,"%d",a);
debug("Order by Gives :%d\n",a);
}
    break;

  case 1179:
#line 5439 "fgl.yacc"
    {
int a;
a=print_bind('O');
print_order_by_type(2);
sprintf(yyval.str,"%d",a);
debug("Order by Gives :%d\n",a);
}
    break;

  case 1180:
#line 5450 "fgl.yacc"
    { 
		rep_type=REP_TYPE_NORMAL; 
		clr_function_constants (); 
		clr_variable(); 
		lastlineno=yylineno; 
		init_report_structure(&rep_struct); 
		}
    break;

  case 1181:
#line 5459 "fgl.yacc"
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
#line 5469 "fgl.yacc"
    {
		lastlineno=yylineno;
		}
    break;

  case 1183:
#line 5473 "fgl.yacc"
    {
		print_variables();
		}
    break;

  case 1184:
#line 5477 "fgl.yacc"
    {
		print_report_2(0,yyvsp[0].str);
		rordcnt=atoi(yyvsp[0].str);
		debug("SET rordcnt=%d %s",rordcnt,yyvsp[0].str);
		}
    break;

  case 1185:
#line 5483 "fgl.yacc"
    {
		print_report_ctrl();
		}
    break;

  case 1186:
#line 5488 "fgl.yacc"
    {
		pop_blockcommand("REPORT");
		print_report_end() ;
		}
    break;

  case 1187:
#line 5496 "fgl.yacc"
    { strcpy(yyval.str,"");
	yyval.ptr=0;
}
    break;

  case 1188:
#line 5499 "fgl.yacc"
    {
	yyval.ptr=yyvsp[0].ptr;
//sprintf($<str>$,"%s", $<str>2);
}
    break;

  case 1189:
#line 5508 "fgl.yacc"
    {
if (!in_command("REPORT")) {
	yyerror("PAUSE can only be used in reportes");
	YYERROR;
        }

print_pause(yyvsp[0].str) ;
}
    break;

  case 1190:
#line 5519 "fgl.yacc"
    {strcpy(yyval.str,"\"\"");}
    break;

  case 1192:
#line 5526 "fgl.yacc"
    {
rep_type=REP_TYPE_PDF;
clr_variable(); lastlineno=yylineno; pdf_init_report_structure(&pdf_rep_struct);
}
    break;

  case 1193:
#line 5531 "fgl.yacc"
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
#line 5540 "fgl.yacc"
    {
lastlineno=yylineno;
}
    break;

  case 1195:
#line 5543 "fgl.yacc"
    {
	print_variables();
}
    break;

  case 1196:
#line 5547 "fgl.yacc"
    {
print_variables();
resize_paper(&pdf_rep_struct);
	print_report_2(1,yyvsp[0].str);
debug("SET rordcnt=%d (%s)",rordcnt,yyvsp[0].str);
	rordcnt=atoi(yyvsp[0].str);
}
    break;

  case 1197:
#line 5555 "fgl.yacc"
    {
print_report_ctrl();
}
    break;

  case 1198:
#line 5558 "fgl.yacc"
    {
	pop_blockcommand("REPORT");
	print_report_end();
}
    break;

  case 1199:
#line 5564 "fgl.yacc"
    { strcpy(yyval.str,yyvsp[0].str); }
    break;

  case 1200:
#line 5568 "fgl.yacc"
    {new_counter();
   		addmap("CALL",yyvsp[-1].str,curr_func,yylineno,infilename);
   		}
    break;

  case 1201:
#line 5572 "fgl.yacc"
    {
		sprintf(yyval.str,"%d",get_counter_val());drop_counter();
		}
    break;

  case 1202:
#line 5576 "fgl.yacc"
    {
		print_pdf_call(yyvsp[-5].str,yyvsp[-2].ptr,yyvsp[-1].str);
   		}
    break;

  case 1203:
#line 5580 "fgl.yacc"
    {
	print_returning();
   }
    break;

  case 1204:
#line 5586 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 1205:
#line 5587 "fgl.yacc"
    { strcpy(yyval.str,"rep.right_margin"); }
    break;

  case 1206:
#line 5588 "fgl.yacc"
    { sprintf(yyval.str,"%s",yyvsp[0].str); }
    break;

  case 1207:
#line 5589 "fgl.yacc"
    { sprintf(yyval.str,"%s",yyvsp[0].str); }
    break;

  case 1208:
#line 5594 "fgl.yacc"
    {
print_system_run(0,0);
}
    break;

  case 1209:
#line 5596 "fgl.yacc"
    {
print_system_run(1,yyvsp[0].str);
}
    break;

  case 1210:
#line 5599 "fgl.yacc"
    {
print_system_run(2,0);
}
    break;

  case 1211:
#line 5603 "fgl.yacc"
    {
print_system_run(0,0);
}
    break;

  case 1212:
#line 5606 "fgl.yacc"
    {
print_system_run(0,0);
/* FIXME */
}
    break;

  case 1213:
#line 5613 "fgl.yacc"
    {
	print_exec_sql(yyvsp[0].str);
}
    break;

  case 1214:
#line 5618 "fgl.yacc"
    {sprintf(yyval.str, "%s",yyvsp[0].str);}
    break;

  case 1215:
#line 5619 "fgl.yacc"
    {sprintf(yyval.str,  "%s",yyvsp[0].str);}
    break;

  case 1216:
#line 5620 "fgl.yacc"
    {sprintf(yyval.str,"%s",yyvsp[0].str);}
    break;

  case 1217:
#line 5624 "fgl.yacc"
    {
	print_exec_sql(yyvsp[0].str);

}
    break;

  case 1218:
#line 5632 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1219:
#line 5633 "fgl.yacc"
    {insql=1;}
    break;

  case 1220:
#line 5633 "fgl.yacc"
    {insql=0;}
    break;

  case 1221:
#line 5634 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s %s",yyvsp[-6].str,yyvsp[-4].str,yyvsp[-3].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1222:
#line 5635 "fgl.yacc"
    {insql=1;}
    break;

  case 1223:
#line 5635 "fgl.yacc"
    {insql=0;}
    break;

  case 1224:
#line 5636 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s %s %s",yyvsp[-7].str,yyvsp[-5].str,yyvsp[-4].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1225:
#line 5637 "fgl.yacc"
    {
		yyerror("You cannot create a database from within Aubit4gl....");
	}
    break;

  case 1226:
#line 5643 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1227:
#line 5645 "fgl.yacc"
    {sprintf(yyval.str," %s ",yyvsp[0].str);}
    break;

  case 1229:
#line 5652 "fgl.yacc"
    {sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1230:
#line 5656 "fgl.yacc"
    {sprintf(yyval.str,"%s ASC",yyvsp[-1].str);}
    break;

  case 1231:
#line 5657 "fgl.yacc"
    {sprintf(yyval.str,"%s DESC",yyvsp[-1].str);}
    break;

  case 1234:
#line 5664 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1237:
#line 5675 "fgl.yacc"
    {sprintf(yyval.str,"%s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1239:
#line 5681 "fgl.yacc"
    {
	print_exec_sql(yyvsp[0].str);
}
    break;

  case 1240:
#line 5685 "fgl.yacc"
    {
	sprintf(yyval.str,"%s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);
}
    break;

  case 1242:
#line 5692 "fgl.yacc"
    {sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1250:
#line 5708 "fgl.yacc"
    {
		sprintf(yyval.str,"ADD %s",yyvsp[0].str);
	}
    break;

  case 1251:
#line 5711 "fgl.yacc"
    {
		sprintf(yyval.str,"%s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);
	}
    break;

  case 1253:
#line 5719 "fgl.yacc"
    {
		sprintf(yyval.str,"%s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);
	}
    break;

  case 1255:
#line 5726 "fgl.yacc"
    {
		sprintf(yyval.str,"%s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);
	}
    break;

  case 1256:
#line 5733 "fgl.yacc"
    {
		sprintf(yyval.str,"DROP %s",yyvsp[0].str);
	}
    break;

  case 1257:
#line 5736 "fgl.yacc"
    {
		sprintf(yyval.str,"DROP (%s)",yyvsp[-1].str);
	}
    break;

  case 1259:
#line 5744 "fgl.yacc"
    {
		sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);
	}
    break;

  case 1261:
#line 5753 "fgl.yacc"
    {
		sprintf(yyval.str,"MODIFY %s",yyvsp[0].str);
	}
    break;

  case 1262:
#line 5756 "fgl.yacc"
    {
		sprintf(yyval.str,"MODIFY (%s)",yyvsp[-1].str);
	}
    break;

  case 1264:
#line 5763 "fgl.yacc"
    {
		sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);
	}
    break;

  case 1266:
#line 5774 "fgl.yacc"
    {strcpy(yyval.str,"LOCK MODE PAGE");}
    break;

  case 1267:
#line 5775 "fgl.yacc"
    {strcpy(yyval.str,"LOCK MODE ROW");}
    break;

  case 1268:
#line 5779 "fgl.yacc"
    {
		sprintf(yyval.str,"MODIFT NEXT SIZE %d",atoi(yyvsp[0].str));
	}
    break;

  case 1270:
#line 5786 "fgl.yacc"
    {
		sprintf(yyval.str,"ADD CONSTRAINT (%s)",yyvsp[-1].str);
	}
    break;

  case 1272:
#line 5794 "fgl.yacc"
    {
		sprintf(yyval.str,"ADD CONSTRAINT (%s)",yyvsp[-1].str);
	}
    break;

  case 1274:
#line 5800 "fgl.yacc"
    {
		sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);
	}
    break;

  case 1278:
#line 5818 "fgl.yacc"
    {sprintf(yyval.str,"%s %s /*FIXME */",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1284:
#line 5824 "fgl.yacc"
    { 
	print_set_conn(yyvsp[0].str);
}
    break;

  case 1285:
#line 5827 "fgl.yacc"
    {
	print_set_options("conn",yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 1286:
#line 5830 "fgl.yacc"
    {
	print_set_options("stmt",yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 1287:
#line 5836 "fgl.yacc"
    {strcpy(yyval.str,"\"default\"");}
    break;

  case 1289:
#line 5842 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1291:
#line 5853 "fgl.yacc"
    {
		print_sleep();
	}
    break;

  case 1292:
#line 5868 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s %s",yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1293:
#line 5871 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1294:
#line 5872 "fgl.yacc"
    { 
		pop_all_gen(UPDCOL,"!"); pop_all_gen(UPDVAL,"!");
		rm_quotes(yyvsp[0].str);
		sprintf(yyval.str," %s %s",yyvsp[-1].str,yyvsp[0].str);
}
    break;

  case 1295:
#line 5878 "fgl.yacc"
    {
pop_all_gen(UPDCOL,"!"); pop_all_gen(UPDVAL,"!");
sprintf(yyval.str," %s %s",yyvsp[-1].str,yyvsp[0].str);
}
    break;

  case 1297:
#line 5887 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s %s %s %s",yyvsp[-6].str,yyvsp[-5].str,yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1299:
#line 5892 "fgl.yacc"
    {sprintf(yyval.str,"%s %s %s %s %s ",yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1300:
#line 5893 "fgl.yacc"
    {
		char *ptr;
		ptr=yyvsp[0].str;
		printf("upd_val_list = '%s'\n",yyvsp[0].str) ;
		if (ptr[0]==' ' && ptr[1]=='(') {
			sprintf(yyval.str," %s %s %s  ",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);
		} else {
			sprintf(yyval.str," %s %s(%s) ",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);
		}
		}
    break;

  case 1302:
#line 5906 "fgl.yacc"
    {
sprintf(yyval.str," %s , %s",yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 1304:
#line 5915 "fgl.yacc"
    {
sprintf(yyval.str," %s = %s",yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 1305:
#line 5920 "fgl.yacc"
    {push_gen(UPDCOL,yyvsp[0].str); strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1306:
#line 5921 "fgl.yacc"
    {push_gen(UPDCOL,yyvsp[0].str); sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1307:
#line 5924 "fgl.yacc"
    {push_gen(UPDVAL,yyvsp[0].str);}
    break;

  case 1308:
#line 5925 "fgl.yacc"
    {push_gen(UPDVAL,yyvsp[0].str); sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1312:
#line 5932 "fgl.yacc"
    {
		print_sql_commit(0);
		}
    break;

  case 1313:
#line 5941 "fgl.yacc"
    { insql=1;start_bind('i',0);}
    break;

  case 1314:
#line 5942 "fgl.yacc"
    {
sprintf(yyval.str," %s %s %s %s",yyvsp[-4].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);
}
    break;

  case 1315:
#line 5947 "fgl.yacc"
    {insql=1;}
    break;

  case 1316:
#line 5947 "fgl.yacc"
    {
insql=0;
sprintf(yyval.str," %s %s %s %s" ,yyvsp[-4].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1318:
#line 5953 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1319:
#line 5955 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1321:
#line 5962 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1323:
#line 5968 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1326:
#line 5978 "fgl.yacc"
    {
      print_fetch_1();
    }
    break;

  case 1327:
#line 5982 "fgl.yacc"
    {
      print_fetch_2();
    }
    break;

  case 1328:
#line 5986 "fgl.yacc"
    {
      print_fetch_3(yyvsp[-2].str,yyvsp[0].str);
    }
    break;

  case 1329:
#line 5993 "fgl.yacc"
    {sprintf(yyval.str,"%s,%s",yyvsp[0].str,yyvsp[-1].str);
addmap("Fetch Cursor",yyvsp[0].str,curr_func,yylineno,infilename);
}
    break;

  case 1330:
#line 5997 "fgl.yacc"
    {sprintf(yyval.str,"%s,%d,1",yyvsp[0].str,FETCH_RELATIVE);

addmap("Fetch Cursor",yyvsp[0].str,curr_func,yylineno,infilename);
}
    break;

  case 1331:
#line 6003 "fgl.yacc"
    {
debug("no into\n");
strcpy(yyval.str,"0,0");
}
    break;

  case 1332:
#line 6007 "fgl.yacc"
    {
	debug("FETCH INTO  ...");
	/* start_bind('i',0,-1); */
    start_bind('o',0);
}
    break;

  case 1333:
#line 6013 "fgl.yacc"
    {
	int no;
	no=print_bind('o');
	sprintf(yyval.str,"%d,obind",no);
}
    break;

  case 1334:
#line 6020 "fgl.yacc"
    {
debug("no into\n");
strcpy(yyval.str,"0,0");
}
    break;

  case 1335:
#line 6024 "fgl.yacc"
    {
	debug("FETCH INTO  ...");
	/* start_bind('i',0,-1); */
    start_bind('o',0);
}
    break;

  case 1336:
#line 6029 "fgl.yacc"
    {
/*
int ni;
ni=print_bind('i');
sprintf($<str>$,"%d,ibind",ni);
*/
}
    break;

  case 1337:
#line 6039 "fgl.yacc"
    {
sprintf(yyval.str,"%d,1",FETCH_ABSOLUTE);}
    break;

  case 1338:
#line 6042 "fgl.yacc"
    {sprintf(yyval.str,"%d,-1",FETCH_ABSOLUTE);}
    break;

  case 1339:
#line 6044 "fgl.yacc"
    {sprintf(yyval.str,"%d,1",FETCH_RELATIVE);}
    break;

  case 1340:
#line 6046 "fgl.yacc"
    {sprintf(yyval.str,"%d,-1",FETCH_RELATIVE);}
    break;

  case 1341:
#line 6048 "fgl.yacc"
    {sprintf(yyval.str,"%d,-1",FETCH_RELATIVE);}
    break;

  case 1342:
#line 6050 "fgl.yacc"
    {sprintf(yyval.str,"%d,0",FETCH_RELATIVE);}
    break;

  case 1343:
#line 6052 "fgl.yacc"
    {sprintf(yyval.str,"%d,pop_int()",FETCH_RELATIVE);}
    break;

  case 1344:
#line 6054 "fgl.yacc"
    {sprintf(yyval.str,"%d,pop_int()",FETCH_ABSOLUTE);}
    break;

  case 1345:
#line 6060 "fgl.yacc"
    {
 
rm_quotes(yyvsp[0].str);
sprintf(yyval.str," %s %s %s %s ",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str
);}
    break;

  case 1346:
#line 6070 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1347:
#line 6075 "fgl.yacc"
    {sprintf(yyval.str,"%s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1349:
#line 6081 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1353:
#line 6090 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1356:
#line 6095 "fgl.yacc"
    {
print_sql_commit(-1);
}
    break;

  case 1357:
#line 6100 "fgl.yacc"
    {
		print_sql_commit(1);
	}
    break;

  case 1358:
#line 6107 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1359:
#line 6108 "fgl.yacc"
    {
		strcpy(yyval.str,"EXCLUSIVE");
	}
    break;

  case 1360:
#line 6115 "fgl.yacc"
    {
if (strcmp(yyvsp[-1].str,"?")==0) {
	print_init_conn(0);
} else {
	print_init_conn(yyvsp[-1].str);
}
}
    break;

  case 1361:
#line 6127 "fgl.yacc"
    {insql=1;}
    break;

  case 1362:
#line 6127 "fgl.yacc"
    {
print_undo_use(yyvsp[-2].str);
insql=0;strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1363:
#line 6132 "fgl.yacc"
    {lex_printcomment("/*  schema */\n");
	print_exec_sql(yyvsp[0].str);

strcpy(yyval.str,"Schema");
}
    break;

  case 1364:
#line 6137 "fgl.yacc"
    {lex_printcomment("/*  schema  2*/\n");

	print_exec_sql(yyvsp[0].str);

strcpy(yyval.str,"Schema Element");
}
    break;

  case 1366:
#line 6144 "fgl.yacc"
    {
	print_exec_sql(yyvsp[0].str);
 }
    break;

  case 1368:
#line 6148 "fgl.yacc"
    {

lex_printcomment("/*  delete 1 */\n");

print_exec_sql_bound(yyvsp[0].str);
strcpy(yyval.str,"Delete where current...");
}
    break;

  case 1369:
#line 6155 "fgl.yacc"
    {

lex_printcomment("/*  delete 2 */\n");

print_exec_sql_bound(yyvsp[0].str);
strcpy(yyval.str,"Delete where ...");
}
    break;

  case 1370:
#line 6162 "fgl.yacc"
    {
strcpy(yyval.str,"Fetch");
lex_printcomment("/*  fetch */\n");
}
    break;

  case 1371:
#line 6166 "fgl.yacc"
    {

lex_printcomment("/*  insert */\n");

print_exec_sql_bound(yyvsp[0].str);


strcpy(yyval.str,"insert");

}
    break;

  case 1373:
#line 6177 "fgl.yacc"
    {
	print_do_select(yyvsp[0].str);
	strcpy(yyval.str,"select");
}
    break;

  case 1374:
#line 6181 "fgl.yacc"
    {

print_exec_sql_bound(yyvsp[0].str);
strcpy(yyval.str,"update");
}
    break;

  case 1375:
#line 6190 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s %s %s %s",yyvsp[-6].str,yyvsp[-5].str,yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1376:
#line 6193 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1377:
#line 6195 "fgl.yacc"
    {sprintf(yyval.str," %s ",yyvsp[0].str);}
    break;

  case 1378:
#line 6200 "fgl.yacc"
    {sprintf(yyval.str," %s ",yyvsp[0].str);}
    break;

  case 1381:
#line 6207 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1385:
#line 6214 "fgl.yacc"
    {sprintf(yyval.str," %s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1386:
#line 6217 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1387:
#line 6219 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1389:
#line 6225 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1391:
#line 6231 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1394:
#line 6242 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s %s %s",yyvsp[-5].str,yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1395:
#line 6245 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1396:
#line 6247 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1398:
#line 6253 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1399:
#line 6256 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1401:
#line 6263 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1402:
#line 6269 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s %s",yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1403:
#line 6274 "fgl.yacc"
    {sprintf(yyval.str," %s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1406:
#line 6284 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1408:
#line 6290 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1409:
#line 6296 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1410:
#line 6298 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1412:
#line 6304 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1416:
#line 6317 "fgl.yacc"
    {sprintf(yyval.str," %s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1417:
#line 6319 "fgl.yacc"
    {sprintf(yyval.str," %s",yyvsp[0].str);}
    break;

  case 1418:
#line 6330 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1419:
#line 6333 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1421:
#line 6337 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1422:
#line 6339 "fgl.yacc"
    {sprintf(yyval.str," %s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1423:
#line 6344 "fgl.yacc"
    {sprintf(yyval.str," %s ",yyvsp[0].str);}
    break;

  case 1424:
#line 6346 "fgl.yacc"
    {sprintf(yyval.str," %s ",yyvsp[0].str);}
    break;

  case 1426:
#line 6349 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1427:
#line 6355 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1428:
#line 6360 "fgl.yacc"
    {sprintf(yyval.str," %s",yyvsp[0].str);}
    break;

  case 1431:
#line 6370 "fgl.yacc"
    {sprintf(yyval.str," %s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1434:
#line 6385 "fgl.yacc"
    {sprintf(yyval.str," %s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1435:
#line 6391 "fgl.yacc"
    {sprintf(yyval.str," %s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1438:
#line 6401 "fgl.yacc"
    {sprintf(yyval.str,"%s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1439:
#line 6406 "fgl.yacc"
    {sprintf(yyval.str,"%s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1441:
#line 6412 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1442:
#line 6416 "fgl.yacc"
    {sprintf(yyval.str," %s ", yyvsp[0].str);}
    break;

  case 1443:
#line 6417 "fgl.yacc"
    {sprintf(yyval.str," %s %s ",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1444:
#line 6418 "fgl.yacc"
    {sprintf(yyval.str," %s (%s) ",yyvsp[-3].str,yyvsp[-1].str);}
    break;

  case 1446:
#line 6422 "fgl.yacc"
    {sprintf(yyval.str,"%s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1448:
#line 6427 "fgl.yacc"
    { sprintf(yyval.str," %s,%s ",yyvsp[-2].str,yyvsp[0].str);  }
    break;

  case 1449:
#line 6435 "fgl.yacc"
    {
sprintf(yyval.str,"%s %s %s %s",
yyvsp[-3].str,yyvsp[-2].str,
yyvsp[-1].str,yyvsp[0].str);
}
    break;

  case 1450:
#line 6442 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1451:
#line 6443 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1452:
#line 6446 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1453:
#line 6447 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1454:
#line 6450 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1455:
#line 6451 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1457:
#line 6458 "fgl.yacc"
    {sprintf(yyval.str,"%s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1459:
#line 6464 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1461:
#line 6470 "fgl.yacc"
    {sprintf(yyval.str," %s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1463:
#line 6476 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1464:
#line 6481 "fgl.yacc"
    {sprintf(yyval.str," %s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1465:
#line 6482 "fgl.yacc"
    {sprintf(yyval.str," %s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1466:
#line 6488 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1467:
#line 6490 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1468:
#line 6494 "fgl.yacc"
    {strcpy(yyval.str," ALL ");}
    break;

  case 1474:
#line 6513 "fgl.yacc"
    {sprintf(yyval.str," %s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1477:
#line 6527 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s %s",yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1478:
#line 6529 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1479:
#line 6531 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s %s",yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1480:
#line 6533 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1482:
#line 6540 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1483:
#line 6543 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1485:
#line 6550 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1486:
#line 6552 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1487:
#line 6554 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1488:
#line 6556 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1489:
#line 6558 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s %s %s",yyvsp[-5].str,yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1490:
#line 6560 "fgl.yacc"
    {sprintf(yyval.str," %s %s Like %s %s",yyvsp[-4].str,yyvsp[-3].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1492:
#line 6566 "fgl.yacc"
    {strcpy(yyval.str,"!=");}
    break;

  case 1498:
#line 6572 "fgl.yacc"
    {strcpy(yyval.str,"likE");}
    break;

  case 1499:
#line 6573 "fgl.yacc"
    {strcpy(yyval.str,"<=");}
    break;

  case 1500:
#line 6574 "fgl.yacc"
    {strcpy(yyval.str,">=");}
    break;

  case 1505:
#line 6584 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1513:
#line 6604 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1514:
#line 6609 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s %s",yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1515:
#line 6610 "fgl.yacc"
    {strcpy(yyval.str,"SERIAL");}
    break;

  case 1517:
#line 6613 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s %s",yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1521:
#line 6618 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1523:
#line 6621 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1525:
#line 6624 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s %s %s %s",yyvsp[-6].str,yyvsp[-5].str,yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1529:
#line 6629 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1530:
#line 6631 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s %s %s",yyvsp[-5].str,yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1531:
#line 6634 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1532:
#line 6635 "fgl.yacc"
    {
		sprintf(yyval.str,",%s",yyvsp[0].str);
}
    break;

  case 1533:
#line 6642 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1537:
#line 6647 "fgl.yacc"
    {sprintf(yyval.str," %s",yyvsp[0].str);}
    break;

  case 1541:
#line 6663 "fgl.yacc"
    { sprintf(yyval.str,"\\\"%s\\\"%s%s",strip_quotes(yyvsp[-2].str),yyvsp[-1].str,yyvsp[0].str); addmap("Use Table",yyval.str,curr_func,yylineno,infilename); }
    break;

  case 1542:
#line 6664 "fgl.yacc"
    {
		sprintf(yyval.str," %s",strip_quotes(yyvsp[0].str));
		addmap("Use Table",yyval.str,curr_func,yylineno,infilename);
	}
    break;

  case 1543:
#line 6668 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str); addmap("Use Table",yyvsp[0].str,curr_func,yylineno,infilename); }
    break;

  case 1544:
#line 6669 "fgl.yacc"
    { sprintf(yyval.str," %s%s%s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str); addmap("Use Table",yyval.str,curr_func,yylineno,infilename); }
    break;

  case 1546:
#line 6684 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1547:
#line 6685 "fgl.yacc"
    {sprintf(yyval.str,"[%s]",yyvsp[-1].str);}
    break;

  case 1548:
#line 6686 "fgl.yacc"
    {sprintf(yyval.str,"[%s,%s]",yyvsp[-3].str,yyvsp[-1].str);}
    break;

  case 1549:
#line 6690 "fgl.yacc"
    { 
addmap("Use Column",yyvsp[-1].str,curr_func,yylineno,infilename);
sprintf(yyval.str,"%s%s",yyvsp[-1].str,yyvsp[0].str);
}
    break;

  case 1550:
#line 6695 "fgl.yacc"
    {
sprintf(yyval.str,"%s.%s%s",yyvsp[-4].str,yyvsp[-1].str,yyvsp[0].str);
addmap("Use Column",yyval.str,curr_func,yylineno,infilename);
}
    break;

  case 1551:
#line 6700 "fgl.yacc"
    {
sprintf(yyval.str,"%s.%s",yyvsp[-3].str,yyvsp[0].str);
addmap("Use Column",yyval.str,curr_func,yylineno,infilename);
}
    break;

  case 1553:
#line 6713 "fgl.yacc"
    {
	strcpy(yyval.str,convstrsql(yyvsp[0].str));
	debug("Set $<str>$ to %s\n",yyval.str);
}
    break;

  case 1557:
#line 6721 "fgl.yacc"
    {sprintf(yyval.str," %s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1558:
#line 6723 "fgl.yacc"
    {sprintf(yyval.str," %s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1559:
#line 6725 "fgl.yacc"
    {sprintf(yyval.str," %s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1560:
#line 6727 "fgl.yacc"
    {sprintf(yyval.str," %s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1562:
#line 6732 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1563:
#line 6735 "fgl.yacc"
    {sprintf(yyval.str," %s %s ",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1564:
#line 6738 "fgl.yacc"
    {strcpy(yyval.str," YEAR TO SECOND ");}
    break;

  case 1565:
#line 6740 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1566:
#line 6743 "fgl.yacc"
    {strcpy(yyval.str,"0,17");}
    break;

  case 1567:
#line 6745 "fgl.yacc"
    {sprintf(yyval.str," %s ,%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1568:
#line 6748 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 1569:
#line 6748 "fgl.yacc"
    {strcpy(yyval.str,"5");}
    break;

  case 1570:
#line 6748 "fgl.yacc"
    {strcpy(yyval.str,"8");}
    break;

  case 1571:
#line 6748 "fgl.yacc"
    {strcpy(yyval.str,"11");}
    break;

  case 1572:
#line 6748 "fgl.yacc"
    {strcpy(yyval.str,"14");}
    break;

  case 1573:
#line 6748 "fgl.yacc"
    {strcpy(yyval.str,"17");}
    break;

  case 1574:
#line 6749 "fgl.yacc"
    {
strcpy(yyval.str,"23");
}
    break;

  case 1575:
#line 6752 "fgl.yacc"
    {
strcpy(yyval.str,"23");
}
    break;

  case 1576:
#line 6757 "fgl.yacc"
    {strcpy(yyval.str,"4");}
    break;

  case 1577:
#line 6757 "fgl.yacc"
    {strcpy(yyval.str,"7");}
    break;

  case 1578:
#line 6757 "fgl.yacc"
    {strcpy(yyval.str,"10");}
    break;

  case 1579:
#line 6757 "fgl.yacc"
    {strcpy(yyval.str,"13");}
    break;

  case 1580:
#line 6757 "fgl.yacc"
    {strcpy(yyval.str,"16");}
    break;

  case 1581:
#line 6757 "fgl.yacc"
    {strcpy(yyval.str,"19");}
    break;

  case 1582:
#line 6759 "fgl.yacc"
    {
strcpy(yyval.str,"25");
}
    break;

  case 1583:
#line 6762 "fgl.yacc"
    {
strcpy(yyval.str,"25");
}
    break;

  case 1598:
#line 6771 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1599:
#line 6772 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1600:
#line 6776 "fgl.yacc"
    {
	print_flush_cursor(yyvsp[0].str);
		addmap("Flush Cursor",yyvsp[0].str,curr_func,yylineno,infilename);
print_undo_use(yyvsp[-2].str);
		}
    break;

  case 1601:
#line 6785 "fgl.yacc"
    {insql=0;chk4var=0;}
    break;

  case 1602:
#line 6785 "fgl.yacc"
    {
print_declare(yyvsp[0].str,yyvsp[-2].str,yyvsp[-5].str,0,0);
addmap("Declare Cursor",yyvsp[-5].str,curr_func,yylineno,infilename);
print_undo_use(yyvsp[-7].str);
}
    break;

  case 1603:
#line 6790 "fgl.yacc"
    {insql=0;chk4var=0;}
    break;

  case 1604:
#line 6790 "fgl.yacc"
    {
print_declare(yyvsp[0].str,yyvsp[-2].str,yyvsp[-6].str,2,0); 
addmap("Declare Cursor",yyvsp[-6].str,curr_func,yylineno,infilename);
print_undo_use(yyvsp[-8].str);
}
    break;

  case 1605:
#line 6796 "fgl.yacc"
    {insql=0;chk4var=0;}
    break;

  case 1606:
#line 6797 "fgl.yacc"
    {
print_declare(yyvsp[0].str,yyvsp[-2].str,yyvsp[-4].str,0,1); 
addmap("Declare Cursor",yyvsp[-4].str,curr_func,yylineno,infilename);
print_undo_use(yyvsp[-6].str);
}
    break;

  case 1607:
#line 6802 "fgl.yacc"
    {insql=0;chk4var=0;}
    break;

  case 1608:
#line 6803 "fgl.yacc"
    {
print_declare(yyvsp[0].str,yyvsp[-2].str,yyvsp[-6].str,0,1); 
addmap("Declare Cursor",yyvsp[-6].str,curr_func,yylineno,infilename);
print_undo_use(yyvsp[-8].str);
}
    break;

  case 1609:
#line 6812 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 1610:
#line 6813 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 1611:
#line 6814 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 1615:
#line 6821 "fgl.yacc"
    {sprintf(yyval.str,"%s.%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1616:
#line 6822 "fgl.yacc"
    {sprintf(yyval.str,"\\\"%s\\\".%s.%s",strip_quotes(yyvsp[-4].str),yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1618:
#line 6828 "fgl.yacc"
    { 
		strcpy(yyval.str,print_curr_spec(1,yyvsp[0].str));
	}
    break;

  case 1619:
#line 6834 "fgl.yacc"
    {
		strcpy(yyval.str,print_curr_spec(2,yyvsp[0].str));
}
    break;

  case 1621:
#line 6843 "fgl.yacc"
    {
	sprintf(yyval.str,"%s",yyvsp[-1].str);
	if (atoi(yyvsp[0].str)) {
		printf("Warning SELECT ... FOR UPDATE when not declaring a cursor currently has no locking effect\n");
	}

	}
    break;

  case 1622:
#line 6856 "fgl.yacc"
    {debug("Got select list...\n");}
    break;

  case 1623:
#line 6858 "fgl.yacc"
    { /* start_bind('i',0,-1); */ start_bind('i',0); lex_printcomment("/* startbind */"); }
    break;

  case 1624:
#line 6860 "fgl.yacc"
    {
             char buff[1024];
             sprintf(buff,"%s %s %s %s %s %s", yyvsp[-7].str, yyvsp[-6].str, yyvsp[-5].str, yyvsp[-3].str, yyvsp[-1].str,yyvsp[0].str);
	     debug("call print_select_all with %s\n",buff);
	     strcpy(yyval.str,print_select_all(buff));

}
    break;

  case 1625:
#line 6871 "fgl.yacc"
    {
             char buff[1024];

             sprintf(buff,"%s %s %s %s %s", yyvsp[-4].str, yyvsp[-3].str, yyvsp[-2].str, yyvsp[-1].str, yyvsp[0].str);
             sprintf(yyval.str,"push_char(\"%s\");",buff);
}
    break;

  case 1628:
#line 6887 "fgl.yacc"
    {sprintf(yyval.str,"%s %s %s %s %s %s %s", yyvsp[-6].str, yyvsp[-5].str, yyvsp[-4].str, yyvsp[-3].str, yyvsp[-2].str, yyvsp[-1].str, yyvsp[0].str);}
    break;

  case 1629:
#line 6891 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1630:
#line 6892 "fgl.yacc"
    {
       lex_printcomment("/* UNION */");
       sprintf(yyval.str,"%s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);
       }
    break;

  case 1632:
#line 6897 "fgl.yacc"
    { sprintf(yyval.str,"%s %s %s ",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str); }
    break;

  case 1633:
#line 6898 "fgl.yacc"
    { sprintf(yyval.str,"%s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str); }
    break;

  case 1635:
#line 6905 "fgl.yacc"
    { start_bind('o',0);strcpy(yyval.str,""); }
    break;

  case 1636:
#line 6906 "fgl.yacc"
    { 
		
		strcpy(yyval.str,get_into_part(get_bind_cnt('o'))); 
	}
    break;

  case 1637:
#line 6916 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s",yyvsp[-4].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1638:
#line 6921 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s %s %s %s",yyvsp[-6].str,yyvsp[-5].str,yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1639:
#line 6924 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1640:
#line 6925 "fgl.yacc"
    {strcpy(yyval.str,"ALL");}
    break;

  case 1641:
#line 6926 "fgl.yacc"
    {strcpy(yyval.str,"DISTINCT");}
    break;

  case 1642:
#line 6927 "fgl.yacc"
    {strcpy(yyval.str,"DISTINCT");}
    break;

  case 1644:
#line 6932 "fgl.yacc"
    { sprintf(yyval.str," %s,%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1646:
#line 6937 "fgl.yacc"
    {sprintf(yyval.str," %s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1647:
#line 6938 "fgl.yacc"
    {sprintf(yyval.str," %s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1649:
#line 6949 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1650:
#line 6951 "fgl.yacc"
    {sprintf(yyval.str," %s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1651:
#line 6953 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1652:
#line 6955 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1653:
#line 6957 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1659:
#line 6963 "fgl.yacc"
    {sprintf(yyval.str," %s ",yyvsp[0].str);}
    break;

  case 1660:
#line 6965 "fgl.yacc"
    {sprintf(yyval.str," %s",yyvsp[0].str);}
    break;

  case 1661:
#line 6967 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s %s",yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1662:
#line 6969 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s %s",yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1663:
#line 6971 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s %s",yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1664:
#line 6973 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s %s",yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1665:
#line 6975 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s %s",yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1666:
#line 6977 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1667:
#line 6979 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s %s %s",yyvsp[-5].str,yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1668:
#line 6980 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1669:
#line 6981 "fgl.yacc"
    {sprintf(yyval.str,"extend(%s)",yyvsp[-1].str);}
    break;

  case 1674:
#line 6991 "fgl.yacc"
    {

print_unload(yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);
print_undo_use(yyvsp[-4].str);
}
    break;

  case 1675:
#line 6999 "fgl.yacc"
    {
print_load(yyvsp[-4].str,yyvsp[-3].str,yyvsp[-1].str,yyvsp[0].str);
print_undo_use(yyvsp[-6].str);
}
    break;

  case 1676:
#line 7004 "fgl.yacc"
    {strcpy(yyval.str,"\"|\"");}
    break;

  case 1677:
#line 7004 "fgl.yacc"
    {
strcpy(yyval.str,yyvsp[0].str);
}
    break;

  case 1679:
#line 7008 "fgl.yacc"
    {
if ((scan_variable(yyvsp[0].str)&15)!=0) {yyerror("Variable must be of type char for a delimiter..");YYERROR;}
}
    break;

  case 1680:
#line 7013 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 1681:
#line 7013 "fgl.yacc"
    {
sprintf(yyval.str,"%s,0",yyvsp[-1].str);
}
    break;

  case 1683:
#line 7017 "fgl.yacc"
    {
    sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 1684:
#line 7021 "fgl.yacc"
    {
     sprintf(yyval.str,"\"%s\"",yyvsp[0].str);
}
    break;

  case 1687:
#line 7030 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1688:
#line 7030 "fgl.yacc"
    {
print_use_session(yyvsp[0].str);
strcpy(yyval.str,get_undo_use());
}
    break;

  case 1693:
#line 7049 "fgl.yacc"
    { sprintf(yyval.str,"%s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str); }
    break;

  case 1694:
#line 7050 "fgl.yacc"
    { sprintf(yyval.str,"%s %s %s %s",yyvsp[-5].str,yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str); }
    break;

  case 1697:
#line 7058 "fgl.yacc"
    {
		sprintf(yyval.str,"%s %s",yyvsp[-1].str,yyvsp[0].str);
	}
    break;

  case 1698:
#line 7064 "fgl.yacc"
    {
		sprintf(yyval.str,"%s %s %s",
					yyvsp[-2].str,
					yyvsp[-1].str,
					yyvsp[0].str
					);
		}
    break;

  case 1701:
#line 7083 "fgl.yacc"
    {strcpy(yyval.str,"UNITS YEAR");}
    break;

  case 1702:
#line 7084 "fgl.yacc"
    {strcpy(yyval.str,"UNITS MONTH"); }
    break;

  case 1703:
#line 7085 "fgl.yacc"
    {strcpy(yyval.str,"UNITS DAY);"); }
    break;

  case 1704:
#line 7086 "fgl.yacc"
    {strcpy(yyval.str,"UNITS HOUR);"); }
    break;

  case 1705:
#line 7087 "fgl.yacc"
    {strcpy(yyval.str,"UNITS MINUTE);"); }
    break;

  case 1706:
#line 7088 "fgl.yacc"
    {strcpy(yyval.str,"UNITS SECOND);"); }
    break;

  case 1707:
#line 7092 "fgl.yacc"
    {sprintf(yyval.str,"%s %s %s %s %s",yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1708:
#line 7093 "fgl.yacc"
    {sprintf(yyval.str,"%s %s %s %s %s",yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1709:
#line 7094 "fgl.yacc"
    {sprintf(yyval.str,"%s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1710:
#line 7178 "fgl.yacc"
    {
	if (scan_variable(yyvsp[0].str)!=-1)
	{
		print_push_variable(yyvsp[0].str);
		strcpy(yyval.str,"?");
	}
}
    break;

  case 1711:
#line 7189 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1715:
#line 7195 "fgl.yacc"
    {sprintf(yyval.str,"%s.%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1716:
#line 7196 "fgl.yacc"
    {sprintf(yyval.str,"\\\"%s\\\".%s.%s",strip_quotes(yyvsp[-4].str),yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1720:
#line 7206 "fgl.yacc"
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

  case 1721:
#line 7218 "fgl.yacc"
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

  case 1722:
#line 7316 "fgl.yacc"
    {set_whenever(WHEN_NOTFOUND|atoi(yyvsp[0].str),0);}
    break;

  case 1723:
#line 7318 "fgl.yacc"
    {set_whenever(WHEN_SQLERROR|atoi(yyvsp[0].str),0);}
    break;

  case 1724:
#line 7320 "fgl.yacc"
    {set_whenever(WHEN_ANYERROR|atoi(yyvsp[0].str),0);}
    break;

  case 1725:
#line 7321 "fgl.yacc"
    {
 		set_whento("");
		set_whenever(WHEN_ERROR+WHEN_CONTINUE,0);
}
    break;

  case 1726:
#line 7326 "fgl.yacc"
    {
debug("Whenever error...%d %d",WHEN_ERROR,atoi(yyvsp[0].str));
set_whenever(WHEN_ERROR+atoi(yyvsp[0].str),0);
}
    break;

  case 1727:
#line 7331 "fgl.yacc"
    {set_whenever(WHEN_SQLWARNING|atoi(yyvsp[0].str),0);}
    break;

  case 1728:
#line 7333 "fgl.yacc"
    {set_whenever(WHEN_WARNING|atoi(yyvsp[0].str),0);}
    break;

  case 1729:
#line 7335 "fgl.yacc"
    {set_whenever(WHEN_SUCCESS|atoi(yyvsp[0].str),0);}
    break;

  case 1730:
#line 7337 "fgl.yacc"
    {set_whenever(WHEN_SQLSUCCESS|atoi(yyvsp[0].str),0);}
    break;

  case 1731:
#line 7340 "fgl.yacc"
    {
 set_whento("");
			sprintf(yyval.str,"%d",WHEN_CONTINUE); }
    break;

  case 1732:
#line 7344 "fgl.yacc"
    {
set_whento(yyvsp[0].str);
sprintf(yyval.str,"%d",WHEN_GOTO);
 }
    break;

  case 1733:
#line 7349 "fgl.yacc"
    {
set_whento(yyvsp[0].str); 
sprintf(yyval.str,"%d",WHEN_GOTO);
}
    break;

  case 1734:
#line 7354 "fgl.yacc"
    { set_whento(""); 
sprintf(yyval.str,"%d",WHEN_STOP);
}
    break;

  case 1735:
#line 7358 "fgl.yacc"
    {
set_whento(yyvsp[0].str);
sprintf(yyval.str,"%d",WHEN_CALL);
}
    break;

  case 1737:
#line 7368 "fgl.yacc"
    {sprintf(yyval.str,"%s",yyvsp[0].str);}
    break;

  case 1739:
#line 7383 "fgl.yacc"
    {
print_while_1();
push_blockcommand("WHILE");
}
    break;

  case 1740:
#line 7386 "fgl.yacc"
    {
print_while_2();
}
    break;

  case 1741:
#line 7390 "fgl.yacc"
    {
print_while_3();
pop_blockcommand("WHILE");
}
    break;

  case 1744:
#line 7409 "fgl.yacc"
    { strcpy(yyval.str,"0"); }
    break;

  case 1745:
#line 7410 "fgl.yacc"
    { strcpy(yyval.str,"1"); }
    break;

  case 1746:
#line 7413 "fgl.yacc"
    { print_clr_window("\"screen\""); }
    break;

  case 1747:
#line 7414 "fgl.yacc"
    { print_clr_window(yyvsp[0].str); }
    break;

  case 1748:
#line 7415 "fgl.yacc"
    { print_clr_window(yyvsp[0].str); }
    break;

  case 1749:
#line 7416 "fgl.yacc"
    { print_clr_form(0,0,"0"); }
    break;

  case 1750:
#line 7417 "fgl.yacc"
    { print_clr_form(0,0,"1"); }
    break;

  case 1751:
#line 7418 "fgl.yacc"
    { print_clr_form(yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str); }
    break;

  case 1752:
#line 7419 "fgl.yacc"
    {
	print_clr_fields(yyvsp[-1].str,yyvsp[0].str);
}
    break;

  case 1753:
#line 7424 "fgl.yacc"
    {sprintf(yyval.str,"%s",yyvsp[0].str);}
    break;

  case 1754:
#line 7425 "fgl.yacc"
    {sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1755:
#line 7429 "fgl.yacc"
    {
	print_current_window("\"screen\"");
}
    break;

  case 1756:
#line 7433 "fgl.yacc"
    {
	print_current_window(yyvsp[0].str);
}
    break;

  case 1757:
#line 7437 "fgl.yacc"
    {
sprintf(yyval.str,"cr_window");
reset_attrib(&form_attrib);
}
    break;

  case 1758:
#line 7441 "fgl.yacc"
    {
sprintf(yyval.str,"cr_window_form");
reset_attrib(&form_attrib);
}
    break;

  case 1759:
#line 7446 "fgl.yacc"
    {
	print_show_window(yyvsp[0].str);
	addmap("Show Window",yyvsp[0].str,curr_func,yylineno,infilename); 
}
    break;

  case 1760:
#line 7450 "fgl.yacc"
    {
	print_show_menu(yyvsp[-3].str,yyvsp[-1].str);
	addmap("Call Menuhandler",yyvsp[-1].str,curr_func,yylineno,infilename); 
}
    break;

  case 1761:
#line 7455 "fgl.yacc"
    {

print_def_mn_file();

}
    break;

  case 1763:
#line 7463 "fgl.yacc"
    {addmap("Use Menu",yyvsp[0].str,curr_func,yylineno,infilename); }
    break;

  case 1765:
#line 7469 "fgl.yacc"
    {
	print_hide_window(yyvsp[0].str);
}
    break;

  case 1766:
#line 7475 "fgl.yacc"
    {
print_move_window(yyvsp[-4].str,0);
}
    break;

  case 1767:
#line 7479 "fgl.yacc"
    {
print_move_window(yyvsp[-4].str,1);
}
    break;

  case 1772:
#line 7497 "fgl.yacc"
    {
chk4var=0;lex_printcomment("/* [Comm:%s] */\n",yyval.str);
if (acl_getenv("INCLINES"))
lex_printc("{debug(\"Line %d %s:%s\");}",lastlineno,infilename,convstrsql(larr));
	prchkerr(lastlineno,infilename);
	lastlineno=yylineno;
}
    break;

  case 1773:
#line 7504 "fgl.yacc"
    {
lex_printcomment("/* [COMM:%s] */\n",yyvsp[0].str);chk4var=0;
if (acl_getenv("INCLINES"))
lex_printc("{debug(\"Line %d %s:%s\");}",lastlineno,infilename,convstrsql(larr));
if (aubit_strcasecmp(yyval.str,"whenever")!=0) prchkerr(lastlineno,infilename);
lastlineno=yylineno;
}
    break;

  case 1774:
#line 7513 "fgl.yacc"
    {print_cmd_start();}
    break;

  case 1775:
#line 7513 "fgl.yacc"
    {print_cmd_end();}
    break;


    }

/* Line 991 of yacc.c.  */
#line 15512 "y.tab.c"

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


#line 7606 "fgl.yacc"

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



