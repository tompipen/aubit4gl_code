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

/* If NAME_PREFIX is specified substitute the variables and functions
   names.  */
#define yyparse a4gl_yyparse
#define yylex   a4gl_yylex
#define yyerror a4gl_yyerror
#define yylval  a4gl_yylval
#define yychar  a4gl_yychar
#define yydebug a4gl_yydebug
#define yynerrs a4gl_yynerrs


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     NAME = 1699,
     UMINUS = 1700,
     COMMA = 1606,
     KW_OR = 1646,
     KW_AND = 1601,
     KW_USING = 1538,
     NOT = 1621,
     MATCHES = 1417,
     POWER = 1524,
     LESS_THAN = 1520,
     GREATER_THAN = 1435,
     EQUAL = 1596,
     GREATER_THAN_EQ = 1334,
     LESS_THAN_EQ = 1392,
     NOT_EQUAL = 1466,
     PLUS = 1632,
     MINUS = 1619,
     MULTIPLY = 1525,
     DIVIDE = 1552,
     MOD = 1620,
     COMMAND = 1399,
     NUMBER_VALUE = 1701,
     CHAR_VALUE = 1702,
     INT_VALUE = 1703,
     NAMED_GEN = 1704,
     CLINE = 1705,
     SQLLINE = 1706,
     KW_CSTART = 1707,
     KW_CEND = 1708,
     USER_DTYPE = 1709,
     SQL_TEXT = 1710,
     DYNAMIC_ARRAY = 1000,
     RESIZE_ARRAY = 1001,
     ALLOCATE_ARRAY = 1002,
     DEALLOCATE_ARRAY = 1003,
     BEFORE_INSERT = 1004,
     CONCAT_PIPES = 1005,
     BEFORE_DELETE = 1006,
     AFTER_INSERT = 1007,
     AFTER_DELETE = 1008,
     EXECUTE_IMMEDIATE = 1009,
     DELETE_ROW_EQUAL_TRUE = 1010,
     INSERT_ROW_EQUAL_TRUE = 1011,
     DELETE_ROW_EQUAL_FALSE = 1012,
     INSERT_ROW_EQUAL_FALSE = 1013,
     CURRENT_ROW_DISPLAY_EQUAL = 1014,
     MAXCOUNT = 1015,
     ALTER_TABLE = 1016,
     ALTER_INDEX = 1017,
     WHENEVER_ERROR_CONTINUE = 1018,
     WHENEVER_ANY_ERROR_CONTINUE = 1019,
     WHENEVER_WARNING_CONTINUE = 1020,
     WHENEVER_SQLSUCCESS_CONTINUE = 1021,
     WHENEVER_SQLWARNING_CONTINUE = 1022,
     WHENEVER_NOT_FOUND_CONTINUE = 1023,
     WHENEVER_SQLERROR_CONTINUE = 1024,
     WHENEVER_SUCCESS_CONTINUE = 1025,
     WHENEVER_ERROR_GOTO = 1026,
     WHENEVER_ANY_ERROR_GOTO = 1027,
     WHENEVER_WARNING_GOTO = 1028,
     WHENEVER_SQLSUCCESS_GOTO = 1029,
     WHENEVER_SQLWARNING_GOTO = 1030,
     WHENEVER_NOT_FOUND_GOTO = 1031,
     WHENEVER_SQLERROR_GOTO = 1032,
     WHENEVER_SUCCESS_GOTO = 1033,
     WHENEVER_ERROR_CALL = 1034,
     WHENEVER_ANY_ERROR_CALL = 1035,
     WHENEVER_WARNING_CALL = 1036,
     WHENEVER_SQLSUCCESS_CALL = 1037,
     WHENEVER_SQLWARNING_CALL = 1038,
     WHENEVER_NOT_FOUND_CALL = 1039,
     WHENEVER_SQLERROR_CALL = 1040,
     WHENEVER_SUCCESS_CALL = 1041,
     WHENEVER_ERROR_STOP = 1042,
     WHENEVER_ANY_ERROR_STOP = 1043,
     WHENEVER_WARNING_STOP = 1044,
     WHENEVER_SQLSUCCESS_STOP = 1045,
     WHENEVER_SQLWARNING_STOP = 1046,
     WHENEVER_NOT_FOUND_STOP = 1047,
     WHENEVER_SQLERROR_STOP = 1048,
     WHENEVER_SUCCESS_STOP = 1049,
     XSET_MULTIPLY_EQUAL_OPEN_BRACKET = 1050,
     XSET_ident_DOT_MULTIPLY_EQUAL_OPEN_BRACKET = 1051,
     XSET_ident_DOT_MULTIPLY_EQUAL = 1052,
     XSET_MULTIPLY_EQUAL = 1053,
     XSET_OPEN_BRACKET = 1054,
     NEWFORMATSHARED = 1055,
     CREATE_DATABASE = 1056,
     IMPORT_LEGACY_FUNCTION = 1057,
     ADD_CONSTRAINT = 1058,
     DROP_CONSTRAINT = 1059,
     AS_STATIC = 1060,
     NOT_FIELD_TOUCHED = 1061,
     LOCAL_FUNCTION = 1062,
     EVERY_ROW = 1063,
     ELIF = 1064,
     DOUBLE_PRECISION = 1065,
     COUNT_MULTIPLY = 1066,
     WAIT_FOR_KEY = 1067,
     AT_TERMINATION_CALL = 1068,
     TERMINATE_REPORT = 1069,
     TO_MAIN_CAPTION = 1070,
     CLEARSTAT = 1071,
     TO_MENUITEM = 1072,
     ID_TO_INT = 1073,
     TO_STATUSBOX = 1074,
     ASCII_HEIGHT_ALL = 1075,
     ASCII_WIDTH_ALL = 1076,
     IMPORT_DATATYPE = 1077,
     PAGE_TRAILER_SIZE = 1078,
     PAGE_HEADER_SIZE = 1079,
     FIRST_PAGE_HEADER_SIZE = 1080,
     BYTES_USE_AS_IMAGE = 1081,
     BYTES_USE_AS_ASCII = 1082,
     KWUP_BY = 1083,
     KWDOWN_BY = 1084,
     CLOSE_STATUSBOX = 1085,
     MODIFY_NEXT_SIZE = 1086,
     LOCK_MODE_PAGE = 1087,
     LOCK_MODE_ROW = 1088,
     TO_PIPE = 1089,
     TO_PRINTER = 1090,
     STATUSBOX = 1091,
     CONNECT_TO = 1092,
     FORMHANDLER_INPUT = 1093,
     UNITS_YEAR = 1094,
     UNITS_MONTH = 1095,
     UNITS_DAY = 1096,
     UNITS_HOUR = 1097,
     UNITS_MINUTE = 1098,
     UNITS_SECOND = 1099,
     NO_NEW_LINES = 1100,
     FIELDTOWIDGET = 1101,
     WITH_HOLD = 1102,
     SHOW_MENU = 1103,
     TO_CLUSTER = 1104,
     TO_NOT_CLUSTER = 1105,
     CWIS = 1106,
     CREATE_IDX = 1107,
     FORM_IS_COMPILED = 1108,
     PDF_REPORT = 1109,
     IMPORT_FUNCTION = 1110,
     PROMPT_MANY = 1111,
     POINTS = 1112,
     MM = 1113,
     INCHES = 1114,
     PREPEND = 1115,
     MEMBER_OF = 1116,
     MEMBER_FUNCTION = 1117,
     APPEND = 1118,
     TEMPLATE = 1119,
     END_TEMPLATE = 1120,
     SQLSICS = 1121,
     CREATE_SCHEMA = 1122,
     SQLSIRR = 1123,
     UPDATESTATS_T = 1124,
     SQLSICR = 1125,
     WHENEVER_SQLSUCCESS = 1126,
     WHENEVER_SQLWARNING = 1127,
     WHENEVER_ANY_ERROR = 1128,
     WHENEVER_NOT_FOUND = 1129,
     WHENEVER_SQLERROR = 1130,
     WHENEVER_SUCCESS = 1131,
     WHENEVER_WARNING = 1132,
     WHENEVER_ERROR = 1133,
     START_EXTERN = 1134,
     CONTINUE_CONSTRUCT = 1135,
     FOUNCONSTR = 1136,
     SQLSIDR = 1137,
     CREATE_TEMP_TABLE = 1138,
     CURRENT_WINDOW_IS = 1139,
     FIRST_PAGE_HEADER = 1140,
     ORDER_EXTERNAL_BY = 1141,
     SCROLL_CURSOR_FOR = 1142,
     SCROLL_CURSOR = 1143,
     SQL_INTERRUPT_OFF = 1144,
     STOP_ALL_EXTERNAL = 1145,
     WITH_CHECK_OPTION = 1146,
     WITH_GRANT_OPTION = 1147,
     SQLSLMNW = 1148,
     ADDCONSTUNIQ = 1149,
     CONTINUE_DISPLAY = 1150,
     CONTINUE_FOREACH = 1151,
     OUTPUT_TO_REPORT = 1152,
     SQL_INTERRUPT_ON = 1153,
     WHERE_CURRENT_OF = 1154,
     WITHOUT_DEFAULTS = 1155,
     FOCONSTR = 1156,
     SCALED_BY = 1157,
     CONTINUE_PROMPT = 1158,
     PDF_FUNCTION = 1159,
     DEFER_INTERRUPT = 1160,
     DISPLAY_BY_NAME = 1161,
     NOT_NULL_UNIQUE = 1162,
     SKIP_TO_TOP = 1163,
     TOP_OF_PAGE = 1164,
     SKIP_TO = 1165,
     SKIP_BY = 1166,
     WITHOUT_WAITING = 1167,
     BEFCONSTRUCT = 1168,
     SQLSLMW = 1169,
     AFTCONSTRUCT = 1170,
     ALL_PRIVILEGES = 1171,
     CLOSE_DATABASE = 1172,
     CONTINUE_INPUT = 1173,
     CONTINUE_WHILE = 1174,
     CREATE_SYNONYM = 1175,
     DROP_TABLE = 1176,
     EXIT_CONSTRUCT = 1177,
     INEXCLUSIVE = 1178,
     REPORT_TO_PRINTER = 1179,
     REPORT_TO_PIPE = 1180,
     RETURN = 1181,
     SET_SESSION_TO = 1182,
     UPDATESTATS = 1183,
     WITHOUT_HEAD = 1184,
     CLEARSCR = 1185,
     WITH_B_LOG = 1186,
     AUTHORIZATION = 1187,
     BOTTOM_MARGIN = 1188,
     CLOSE_SESSION = 1189,
     CONTINUE_CASE = 1190,
     CONTINUE_MENU = 1191,
     DISPLAY_ARRAY = 1192,
     END_SQL = 1193,
     DOLLAR = 1194,
     END_CONSTRUCT = 1195,
     FIELD_TOUCHED = 1196,
     FINISH_REPORT = 1197,
     INFACC = 1198,
     INPUT_NO_WRAP = 1199,
     LOCKMODEPAGE = 1200,
     SETPMOFF = 1201,
     UNCONSTRAINED = 1202,
     PAGE_TRAILER = 1203,
     SETPMON = 1204,
     BEFGROUP = 1205,
     CLOSE_WINDOW = 1206,
     COMMENT_LINE = 1207,
     CONTINUE_FOR = 1208,
     CREATE_DB = 1209,
     CREATE_TABLE = 1210,
     DEFAULT_NULL = 1211,
     DELETE_USING = 1212,
     DISPLAY_FORM = 1213,
     END_FUNCTION = 1214,
     EXIT_DISPLAY = 1215,
     EXIT_FOREACH = 1216,
     EXIT_PROGRAM = 1217,
     INFCOLS = 1218,
     LOCKMODEROW = 1219,
     ON_EVERY_ROW = 1220,
     OPEN_SESSION = 1221,
     RIGHT_MARGIN = 1222,
     SELECT_USING = 1223,
     START_REPORT = 1224,
     UNLOCK_TABLE = 1225,
     UPDATE_USING = 1226,
     ACL_BUILTIN = 1227,
     AFTGROUP = 1228,
     INFIDX = 1229,
     INFSTAT = 1230,
     LEFT_MARGIN = 1231,
     PAGE_HEADER = 1232,
     ROLLBACK_W = 1233,
     SET_SESSION = 1234,
     SQLSEOFF = 1235,
     WITH_A_LOG = 1236,
     BEFDISP = 1237,
     BEFORE_MENU = 1238,
     CREATE_VIEW = 1239,
     DEFINE_TYPE = 1240,
     DELETE_FROM = 1241,
     END_DISPLAY = 1242,
     END_REPORT = 1243,
     END_FOREACH = 1244,
     END_FOR = 1245,
     END_GLOBALS = 1246,
     EXIT_PROMPT = 1247,
     EXTENT_SIZE = 1248,
     FOREIGN_KEY = 1249,
     HIDE_OPTION = 1250,
     HIDE_WINDOW = 1251,
     INSERT_INTO = 1252,
     IS_NOT_NULL = 1253,
     MOVE_WINDOW = 1254,
     NEXT_OPTION = 1255,
     NOT_MATCHES = 1256,
     ON_LAST_ROW = 1257,
     OPEN_WINDOW = 1258,
     OPEN_STATUSBOX = 1259,
     PAGE_LENGTH = 1260,
     PAGE_WIDTH = 1261,
     PRIMARY_KEY = 1262,
     PROMPT_LINE = 1263,
     RECORD_LIKE = 1264,
     ROLLFORWARD = 1265,
     SETBL = 1266,
     SHOW_OPTION = 1267,
     SHOW_WINDOW = 1268,
     SQLSEON = 1269,
     TO_DATABASE = 1270,
     USE_SESSION = 1271,
     WITH_NO_LOG = 1272,
     AFTDISP = 1273,
     BEFFIELD = 1274,
     INSHARE = 1275,
     UNLOCKTAB = 1276,
     AFTFIELD = 1277,
     ATTRIBUTES = 1278,
     BEFINP = 1279,
     BEGIN_WORK = 1280,
     CLEARWIN = 1281,
     CLOSE_FORM = 1282,
     DEFER_QUIT = 1283,
     DESCENDING = 1284,
     DROP_INDEX = 1285,
     END_PROMPT = 1286,
     END_RECORD = 1287,
     ERROR_LINE = 1288,
     EXIT_INPUT = 1289,
     EXIT_WHILE = 1290,
     FOR_UPDATE_OF = 1291,
     FOR_UPDATE = 1292,
     GET_FLDBUF = 1293,
     INITIALIZE = 1294,
     INPUT_WRAP = 1295,
     LOCK_TABLE = 1296,
     MSG_LINE = 1297,
     NOT_EXISTS = 1298,
     ON_ANY_KEY = 1299,
     REFERENCES = 1300,
     RENCOL = 1301,
     SET_CURSOR = 1302,
     SMALLFLOAT = 1303,
     SQLSUCCESS = 1304,
     TOP_MARGIN = 1305,
     WITH_ARRAY = 1306,
     ACCEPTKEY = 1307,
     ACCEPT = 1308,
     AFTINP = 1309,
     CLEARFORMTODEFAULTS = 1310,
     CLEARFORM = 1311,
     CLEAR_X_FORM = 1312,
     COMMIT_W = 1313,
     NEXTPAGE = 1314,
     PREVPAGE = 1315,
     CTRL_KEY = 1316,
     INFTABS = 1317,
     NEXTFIELD = 1318,
     NEXTFORM = 1319,
     RENTAB = 1320,
     ASCENDING = 1321,
     ASSOCIATE = 1322,
     CHAR = 1323,
     CONSTRUCT = 1324,
     DELIMITER = 1325,
     DOWNSHIFT = 1326,
     DROP_VIEW = 1327,
     END_INPUT = 1328,
     END_WHILE = 1329,
     EXCLUSIVE = 1330,
     EXIT_CASE = 1331,
     EXIT_MENU = 1332,
     FORM_LINE = 1333,
     INTERRUPT = 1335,
     INTO_TEMP = 1336,
     INVISIBLE = 1337,
     IN_MEMORY = 1338,
     LINKED_TO = 1339,
     LOAD_FROM = 1340,
     LOCKTAB = 1341,
     MENU_LINE = 1342,
     OPEN_FORM = 1343,
     OTHERWISE = 1344,
     PRECISION = 1345,
     PRIOR = 1346,
     PROCEDURE = 1347,
     REPORT_TO = 1348,
     RETURNING = 1349,
     UNDERLINE = 1350,
     UNLOAD_TO = 1351,
     BEFROW = 1352,
     UNLOAD_T = 1353,
     VARIABLE = 1354,
     ABSOLUTE = 1355,
     AFTROW = 1356,
     BUFFERED = 1357,
     CONSTANT = 1358,
     CONST = 1359,
     CONTINUE = 1360,
     DATABASE = 1361,
     DATETIME = 1362,
     DEFAULTS = 1363,
     DISTINCT = 1364,
     END_CASE = 1365,
     END_MAIN = 1366,
     END_MENU = 1367,
     END_TYPE = 1368,
     EXIT_FOR = 1369,
     EXTERNAL = 1370,
     FRACTION = 1371,
     FUNCTION = 1372,
     GROUP_BY = 1373,
     INTERVAL = 1374,
     KWMESSAGE = 1375,
     NOT_LIKE = 1376,
     NOT_ILIKE = 1377,
     NOT_NULL = 1378,
     PASSWORD = 1379,
     PREVIOUS = 1380,
     READONLY = 1381,
     REGISTER = 1382,
     RELATIVE = 1383,
     RESOURCE = 1384,
     SMALLINT = 1385,
     VALIDATE = 1386,
     WITH_LOG = 1387,
     WORDWRAP = 1388,
     BY_NAME = 1389,
     IN_FILE = 1390,
     IS_NULL = 1391,
     AVERAGE = 1393,
     BETWEEN = 1394,
     CAPTION = 1395,
     CLIPPED = 1396,
     CLOSE_BRACKET = 1397,
     COLUMNS = 1398,
     COMMENT = 1400,
     CONNECT = 1401,
     CURRENT = 1402,
     DBYNAME = 1403,
     DECIMAL = 1404,
     DECLARE = 1405,
     DEFAULT = 1406,
     DISPLAY = 1407,
     ENDCODE = 1408,
     EXECUTE = 1409,
     FOREACH = 1410,
     FOREIGN = 1411,
     GLOBALS = 1412,
     INFIELD = 1413,
     INTEGER = 1414,
     KWWINDOW = 1415,
     MAGENTA = 1416,
     NUMERIC = 1418,
     OPTIONS = 1419,
     PERCENT = 1420,
     PREPARE = 1421,
     PROGRAM = 1422,
     RECOVER = 1423,
     REVERSE = 1424,
     SECTION = 1425,
     SESSION = 1426,
     SYNONYM = 1427,
     THRU = 1428,
     TRAILER = 1429,
     UPSHIFT = 1430,
     VARCHAR = 1431,
     WAITING = 1432,
     CLOSE_SHEV = 1433,
     CLOSE_SQUARE = 1434,
     KW_FALSE = 1436,
     NOT_IN = 1437,
     ONKEY = 1438,
     OPEN_BRACKET = 1439,
     BORDER = 1440,
     BOTTOM = 1441,
     COLUMN = 1442,
     COMMIT = 1443,
     CREATE = 1444,
     CURSOR = 1445,
     DEFINE = 1446,
     DELETE = 1447,
     DOUBLE = 1448,
     END_IF = 1449,
     ESCAPE = 1450,
     EXISTS = 1451,
     EXTEND = 1452,
     EXTENT = 1453,
     FINISH = 1454,
     FORMAT = 1455,
     HAVING = 1456,
     HEADER = 1457,
     INSERT = 1458,
     LOCATE = 1459,
     MARGIN = 1460,
     MEMORY = 1461,
     MINUTE = 1462,
     MODIFY = 1463,
     NORMAL = 1464,
     EQUAL_EQUAL = 1465,
     OPEN_SHEV = 1467,
     OPEN_SQUARE = 1468,
     OPTION = 1469,
     OUTPUT = 1470,
     PROMPT = 1471,
     PUBLIC = 1472,
     RECORD = 1473,
     REPORT = 1474,
     REVOKE = 1475,
     SCHEMA = 1476,
     SCROLL_USING = 1477,
     SCROLL = 1478,
     SECOND = 1479,
     SELECT = 1480,
     SERIAL = 1481,
     SETL = 1482,
     SHARED = 1483,
     SPACES = 1484,
     UNIQUE = 1485,
     UNLOCK = 1486,
     UPDATE = 1487,
     VALUES = 1488,
     YELLOW = 1489,
     AFTER = 1490,
     KWLINE = 1491,
     KW_NULL = 1492,
     KW_TRUE = 1493,
     SINGLE_KEY = 1494,
     ALTER = 1495,
     ARRAY = 1496,
     ASCII = 1497,
     AUDIT = 1498,
     BLACK = 1499,
     BLINK = 1500,
     CHECK = 1501,
     CLEAR = 1502,
     CLOSE = 1503,
     CODE_C = 1504,
     COUNT = 1505,
     DEFER = 1506,
     ERROR = 1507,
     EVERY = 1508,
     FETCH = 1509,
     FIRST = 1510,
     FLOAT = 1511,
     FLUSH = 1512,
     FOUND = 1513,
     GRANT = 1514,
     GREEN = 1515,
     GROUP = 1516,
     INDEX = 1517,
     KWFORM = 1518,
     LABEL = 1519,
     LOCAL = 1521,
     MONEY = 1522,
     MONTH = 1523,
     ORDER = 1526,
     OUTER = 1527,
     PAUSE = 1528,
     PRINT_IMAGE = 1529,
     PRINT_FILE = 1530,
     PRINT = 1531,
     RIGHT = 1532,
     DOUBLE_COLON = 1533,
     SEMICOLON = 1534,
     SLEEP = 1535,
     TUPLE = 1536,
     UNION = 1537,
     WHERE = 1539,
     WHILE = 1540,
     WHITE = 1541,
     CCODE = 1542,
     ANSI = 1543,
     BLUE = 1544,
     BOLD = 1545,
     BYTE = 1546,
     FCALL = 1547,
     CASE = 1548,
     CYAN = 1549,
     DATE = 1550,
     DESC = 1551,
     KWDOWN = 1553,
     TAB = 1554,
     DROP = 1555,
     ELSE = 1556,
     EXEC = 1557,
     EXIT = 1558,
     FREE = 1559,
     FROM = 1560,
     GOTO = 1561,
     HELP_FILE = 1562,
     LANG_FILE = 1563,
     HELP = 1564,
     HIDE = 1565,
     HOUR = 1566,
     INTO = 1567,
     LAST = 1568,
     LEFT = 1569,
     LIKE = 1570,
     MAIN = 1571,
     MENU = 1572,
     MODE = 1573,
     NEED = 1574,
     NEXT = 1575,
     NOCR = 1576,
     OPEN = 1577,
     QUIT = 1578,
     REAL = 1579,
     ROWS = 1580,
     SHOW = 1581,
     SIZE = 1582,
     SKIP = 1583,
     SOME = 1584,
     STEP = 1585,
     STOP = 1586,
     TEMP = 1587,
     TEXT = 1588,
     THEN = 1589,
     USER = 1590,
     WAIT = 1591,
     WHEN = 1592,
     WITH = 1593,
     WORK = 1594,
     YEAR = 1595,
     KW_IS = 1597,
     XSET = 1598,
     ADD = 1599,
     ALL = 1600,
     ANY = 1602,
     ASC = 1603,
     AVG = 1604,
     COLON = 1605,
     DAY = 1607,
     DBA = 1608,
     DEC = 1609,
     DIM = 1610,
     FKEY = 1611,
     FOR = 1612,
     KEY = 1613,
     KWNO = 1614,
     LET = 1615,
     LOG = 1616,
     XMAX = 1617,
     XMIN = 1618,
     PAD = 1622,
     PUT = 1623,
     RED = 1624,
     ROW = 1625,
     RUN = 1626,
     SQL = 1627,
     SUM = 1628,
     TOP = 1629,
     USE = 1630,
     ATSIGN = 1631,
     AS_TIFF = 1633,
     AS_GIF = 1634,
     AS_PNG = 1635,
     AS_JPEG = 1636,
     AS = 1637,
     AT = 1638,
     BY = 1639,
     DOT = 1640,
     GO = 1641,
     IF = 1642,
     IN = 1643,
     OF = 1644,
     ON = 1645,
     TO = 1647,
     KWUP = 1648,
     FONT_NAME = 1649,
     FONT_SIZE = 1650,
     PAPER_SIZE_IS_LETTER = 1651,
     PAPER_SIZE_IS_LEGAL = 1652,
     PAPER_SIZE_IS_A5 = 1653,
     PAPER_SIZE_IS_A4 = 1654,
     PAPER_SIZE_IS_LETTER_L = 1655,
     PAPER_SIZE_IS_LEGAL_L = 1656,
     PAPER_SIZE_IS_A5_L = 1657,
     PAPER_SIZE_IS_A4_L = 1658,
     FORMHANDLER = 1659,
     END_FORMHANDLER = 1660,
     BEFORE_EVENT = 1661,
     BEFORE_OPEN_FORM = 1662,
     AFTER_EVENT = 1663,
     BEFORE_CLOSE_FORM = 1664,
     BEFORE_ANY = 1665,
     AFTER_ANY = 1666,
     MENUHANDLER = 1667,
     END_MENUHANDLER = 1668,
     BEFORE_SHOW_MENU = 1669,
     DISABLE_PROGRAM = 1670,
     DISABLE_ALL = 1671,
     BUTTONS = 1672,
     CHECK_MENUITEM = 1673,
     DISABLE_FORM = 1674,
     DISABLE_MENUITEMS = 1675,
     DISABLE = 1676,
     ENABLE_FORM = 1677,
     ENABLE_MENUITEMS = 1678,
     ENABLE = 1679,
     KWFIELD = 1680,
     ICON = 1681,
     MESSAGEBOX = 1682,
     TO_DEFAULTS = 1683,
     UNCHECK_MENUITEM = 1684,
     BEFORE = 1685,
     INPUT = 1686,
     END = 1687,
     INT_TO_ID = 1688,
     TIMEOUT = 1689,
     OFF = 1690,
     WITH_1_DIMENSION = 1691,
     WITH_2_DIMENSION = 1692,
     WITH_3_DIMENSION = 1693,
     TILDE = 1694,
     ILIKE = 1695,
     FGL_ISDYNARR_ALLOCATED = 1696,
     FGL_DYNARR_EXTENTSIZE = 1697
   };
#endif
#define NAME 1699
#define UMINUS 1700
#define COMMA 1606
#define KW_OR 1646
#define KW_AND 1601
#define KW_USING 1538
#define NOT 1621
#define MATCHES 1417
#define POWER 1524
#define LESS_THAN 1520
#define GREATER_THAN 1435
#define EQUAL 1596
#define GREATER_THAN_EQ 1334
#define LESS_THAN_EQ 1392
#define NOT_EQUAL 1466
#define PLUS 1632
#define MINUS 1619
#define MULTIPLY 1525
#define DIVIDE 1552
#define MOD 1620
#define COMMAND 1399
#define NUMBER_VALUE 1701
#define CHAR_VALUE 1702
#define INT_VALUE 1703
#define NAMED_GEN 1704
#define CLINE 1705
#define SQLLINE 1706
#define KW_CSTART 1707
#define KW_CEND 1708
#define USER_DTYPE 1709
#define SQL_TEXT 1710
#define DYNAMIC_ARRAY 1000
#define RESIZE_ARRAY 1001
#define ALLOCATE_ARRAY 1002
#define DEALLOCATE_ARRAY 1003
#define BEFORE_INSERT 1004
#define CONCAT_PIPES 1005
#define BEFORE_DELETE 1006
#define AFTER_INSERT 1007
#define AFTER_DELETE 1008
#define EXECUTE_IMMEDIATE 1009
#define DELETE_ROW_EQUAL_TRUE 1010
#define INSERT_ROW_EQUAL_TRUE 1011
#define DELETE_ROW_EQUAL_FALSE 1012
#define INSERT_ROW_EQUAL_FALSE 1013
#define CURRENT_ROW_DISPLAY_EQUAL 1014
#define MAXCOUNT 1015
#define ALTER_TABLE 1016
#define ALTER_INDEX 1017
#define WHENEVER_ERROR_CONTINUE 1018
#define WHENEVER_ANY_ERROR_CONTINUE 1019
#define WHENEVER_WARNING_CONTINUE 1020
#define WHENEVER_SQLSUCCESS_CONTINUE 1021
#define WHENEVER_SQLWARNING_CONTINUE 1022
#define WHENEVER_NOT_FOUND_CONTINUE 1023
#define WHENEVER_SQLERROR_CONTINUE 1024
#define WHENEVER_SUCCESS_CONTINUE 1025
#define WHENEVER_ERROR_GOTO 1026
#define WHENEVER_ANY_ERROR_GOTO 1027
#define WHENEVER_WARNING_GOTO 1028
#define WHENEVER_SQLSUCCESS_GOTO 1029
#define WHENEVER_SQLWARNING_GOTO 1030
#define WHENEVER_NOT_FOUND_GOTO 1031
#define WHENEVER_SQLERROR_GOTO 1032
#define WHENEVER_SUCCESS_GOTO 1033
#define WHENEVER_ERROR_CALL 1034
#define WHENEVER_ANY_ERROR_CALL 1035
#define WHENEVER_WARNING_CALL 1036
#define WHENEVER_SQLSUCCESS_CALL 1037
#define WHENEVER_SQLWARNING_CALL 1038
#define WHENEVER_NOT_FOUND_CALL 1039
#define WHENEVER_SQLERROR_CALL 1040
#define WHENEVER_SUCCESS_CALL 1041
#define WHENEVER_ERROR_STOP 1042
#define WHENEVER_ANY_ERROR_STOP 1043
#define WHENEVER_WARNING_STOP 1044
#define WHENEVER_SQLSUCCESS_STOP 1045
#define WHENEVER_SQLWARNING_STOP 1046
#define WHENEVER_NOT_FOUND_STOP 1047
#define WHENEVER_SQLERROR_STOP 1048
#define WHENEVER_SUCCESS_STOP 1049
#define XSET_MULTIPLY_EQUAL_OPEN_BRACKET 1050
#define XSET_ident_DOT_MULTIPLY_EQUAL_OPEN_BRACKET 1051
#define XSET_ident_DOT_MULTIPLY_EQUAL 1052
#define XSET_MULTIPLY_EQUAL 1053
#define XSET_OPEN_BRACKET 1054
#define NEWFORMATSHARED 1055
#define CREATE_DATABASE 1056
#define IMPORT_LEGACY_FUNCTION 1057
#define ADD_CONSTRAINT 1058
#define DROP_CONSTRAINT 1059
#define AS_STATIC 1060
#define NOT_FIELD_TOUCHED 1061
#define LOCAL_FUNCTION 1062
#define EVERY_ROW 1063
#define ELIF 1064
#define DOUBLE_PRECISION 1065
#define COUNT_MULTIPLY 1066
#define WAIT_FOR_KEY 1067
#define AT_TERMINATION_CALL 1068
#define TERMINATE_REPORT 1069
#define TO_MAIN_CAPTION 1070
#define CLEARSTAT 1071
#define TO_MENUITEM 1072
#define ID_TO_INT 1073
#define TO_STATUSBOX 1074
#define ASCII_HEIGHT_ALL 1075
#define ASCII_WIDTH_ALL 1076
#define IMPORT_DATATYPE 1077
#define PAGE_TRAILER_SIZE 1078
#define PAGE_HEADER_SIZE 1079
#define FIRST_PAGE_HEADER_SIZE 1080
#define BYTES_USE_AS_IMAGE 1081
#define BYTES_USE_AS_ASCII 1082
#define KWUP_BY 1083
#define KWDOWN_BY 1084
#define CLOSE_STATUSBOX 1085
#define MODIFY_NEXT_SIZE 1086
#define LOCK_MODE_PAGE 1087
#define LOCK_MODE_ROW 1088
#define TO_PIPE 1089
#define TO_PRINTER 1090
#define STATUSBOX 1091
#define CONNECT_TO 1092
#define FORMHANDLER_INPUT 1093
#define UNITS_YEAR 1094
#define UNITS_MONTH 1095
#define UNITS_DAY 1096
#define UNITS_HOUR 1097
#define UNITS_MINUTE 1098
#define UNITS_SECOND 1099
#define NO_NEW_LINES 1100
#define FIELDTOWIDGET 1101
#define WITH_HOLD 1102
#define SHOW_MENU 1103
#define TO_CLUSTER 1104
#define TO_NOT_CLUSTER 1105
#define CWIS 1106
#define CREATE_IDX 1107
#define FORM_IS_COMPILED 1108
#define PDF_REPORT 1109
#define IMPORT_FUNCTION 1110
#define PROMPT_MANY 1111
#define POINTS 1112
#define MM 1113
#define INCHES 1114
#define PREPEND 1115
#define MEMBER_OF 1116
#define MEMBER_FUNCTION 1117
#define APPEND 1118
#define TEMPLATE 1119
#define END_TEMPLATE 1120
#define SQLSICS 1121
#define CREATE_SCHEMA 1122
#define SQLSIRR 1123
#define UPDATESTATS_T 1124
#define SQLSICR 1125
#define WHENEVER_SQLSUCCESS 1126
#define WHENEVER_SQLWARNING 1127
#define WHENEVER_ANY_ERROR 1128
#define WHENEVER_NOT_FOUND 1129
#define WHENEVER_SQLERROR 1130
#define WHENEVER_SUCCESS 1131
#define WHENEVER_WARNING 1132
#define WHENEVER_ERROR 1133
#define START_EXTERN 1134
#define CONTINUE_CONSTRUCT 1135
#define FOUNCONSTR 1136
#define SQLSIDR 1137
#define CREATE_TEMP_TABLE 1138
#define CURRENT_WINDOW_IS 1139
#define FIRST_PAGE_HEADER 1140
#define ORDER_EXTERNAL_BY 1141
#define SCROLL_CURSOR_FOR 1142
#define SCROLL_CURSOR 1143
#define SQL_INTERRUPT_OFF 1144
#define STOP_ALL_EXTERNAL 1145
#define WITH_CHECK_OPTION 1146
#define WITH_GRANT_OPTION 1147
#define SQLSLMNW 1148
#define ADDCONSTUNIQ 1149
#define CONTINUE_DISPLAY 1150
#define CONTINUE_FOREACH 1151
#define OUTPUT_TO_REPORT 1152
#define SQL_INTERRUPT_ON 1153
#define WHERE_CURRENT_OF 1154
#define WITHOUT_DEFAULTS 1155
#define FOCONSTR 1156
#define SCALED_BY 1157
#define CONTINUE_PROMPT 1158
#define PDF_FUNCTION 1159
#define DEFER_INTERRUPT 1160
#define DISPLAY_BY_NAME 1161
#define NOT_NULL_UNIQUE 1162
#define SKIP_TO_TOP 1163
#define TOP_OF_PAGE 1164
#define SKIP_TO 1165
#define SKIP_BY 1166
#define WITHOUT_WAITING 1167
#define BEFCONSTRUCT 1168
#define SQLSLMW 1169
#define AFTCONSTRUCT 1170
#define ALL_PRIVILEGES 1171
#define CLOSE_DATABASE 1172
#define CONTINUE_INPUT 1173
#define CONTINUE_WHILE 1174
#define CREATE_SYNONYM 1175
#define DROP_TABLE 1176
#define EXIT_CONSTRUCT 1177
#define INEXCLUSIVE 1178
#define REPORT_TO_PRINTER 1179
#define REPORT_TO_PIPE 1180
#define RETURN 1181
#define SET_SESSION_TO 1182
#define UPDATESTATS 1183
#define WITHOUT_HEAD 1184
#define CLEARSCR 1185
#define WITH_B_LOG 1186
#define AUTHORIZATION 1187
#define BOTTOM_MARGIN 1188
#define CLOSE_SESSION 1189
#define CONTINUE_CASE 1190
#define CONTINUE_MENU 1191
#define DISPLAY_ARRAY 1192
#define END_SQL 1193
#define DOLLAR 1194
#define END_CONSTRUCT 1195
#define FIELD_TOUCHED 1196
#define FINISH_REPORT 1197
#define INFACC 1198
#define INPUT_NO_WRAP 1199
#define LOCKMODEPAGE 1200
#define SETPMOFF 1201
#define UNCONSTRAINED 1202
#define PAGE_TRAILER 1203
#define SETPMON 1204
#define BEFGROUP 1205
#define CLOSE_WINDOW 1206
#define COMMENT_LINE 1207
#define CONTINUE_FOR 1208
#define CREATE_DB 1209
#define CREATE_TABLE 1210
#define DEFAULT_NULL 1211
#define DELETE_USING 1212
#define DISPLAY_FORM 1213
#define END_FUNCTION 1214
#define EXIT_DISPLAY 1215
#define EXIT_FOREACH 1216
#define EXIT_PROGRAM 1217
#define INFCOLS 1218
#define LOCKMODEROW 1219
#define ON_EVERY_ROW 1220
#define OPEN_SESSION 1221
#define RIGHT_MARGIN 1222
#define SELECT_USING 1223
#define START_REPORT 1224
#define UNLOCK_TABLE 1225
#define UPDATE_USING 1226
#define ACL_BUILTIN 1227
#define AFTGROUP 1228
#define INFIDX 1229
#define INFSTAT 1230
#define LEFT_MARGIN 1231
#define PAGE_HEADER 1232
#define ROLLBACK_W 1233
#define SET_SESSION 1234
#define SQLSEOFF 1235
#define WITH_A_LOG 1236
#define BEFDISP 1237
#define BEFORE_MENU 1238
#define CREATE_VIEW 1239
#define DEFINE_TYPE 1240
#define DELETE_FROM 1241
#define END_DISPLAY 1242
#define END_REPORT 1243
#define END_FOREACH 1244
#define END_FOR 1245
#define END_GLOBALS 1246
#define EXIT_PROMPT 1247
#define EXTENT_SIZE 1248
#define FOREIGN_KEY 1249
#define HIDE_OPTION 1250
#define HIDE_WINDOW 1251
#define INSERT_INTO 1252
#define IS_NOT_NULL 1253
#define MOVE_WINDOW 1254
#define NEXT_OPTION 1255
#define NOT_MATCHES 1256
#define ON_LAST_ROW 1257
#define OPEN_WINDOW 1258
#define OPEN_STATUSBOX 1259
#define PAGE_LENGTH 1260
#define PAGE_WIDTH 1261
#define PRIMARY_KEY 1262
#define PROMPT_LINE 1263
#define RECORD_LIKE 1264
#define ROLLFORWARD 1265
#define SETBL 1266
#define SHOW_OPTION 1267
#define SHOW_WINDOW 1268
#define SQLSEON 1269
#define TO_DATABASE 1270
#define USE_SESSION 1271
#define WITH_NO_LOG 1272
#define AFTDISP 1273
#define BEFFIELD 1274
#define INSHARE 1275
#define UNLOCKTAB 1276
#define AFTFIELD 1277
#define ATTRIBUTES 1278
#define BEFINP 1279
#define BEGIN_WORK 1280
#define CLEARWIN 1281
#define CLOSE_FORM 1282
#define DEFER_QUIT 1283
#define DESCENDING 1284
#define DROP_INDEX 1285
#define END_PROMPT 1286
#define END_RECORD 1287
#define ERROR_LINE 1288
#define EXIT_INPUT 1289
#define EXIT_WHILE 1290
#define FOR_UPDATE_OF 1291
#define FOR_UPDATE 1292
#define GET_FLDBUF 1293
#define INITIALIZE 1294
#define INPUT_WRAP 1295
#define LOCK_TABLE 1296
#define MSG_LINE 1297
#define NOT_EXISTS 1298
#define ON_ANY_KEY 1299
#define REFERENCES 1300
#define RENCOL 1301
#define SET_CURSOR 1302
#define SMALLFLOAT 1303
#define SQLSUCCESS 1304
#define TOP_MARGIN 1305
#define WITH_ARRAY 1306
#define ACCEPTKEY 1307
#define ACCEPT 1308
#define AFTINP 1309
#define CLEARFORMTODEFAULTS 1310
#define CLEARFORM 1311
#define CLEAR_X_FORM 1312
#define COMMIT_W 1313
#define NEXTPAGE 1314
#define PREVPAGE 1315
#define CTRL_KEY 1316
#define INFTABS 1317
#define NEXTFIELD 1318
#define NEXTFORM 1319
#define RENTAB 1320
#define ASCENDING 1321
#define ASSOCIATE 1322
#define CHAR 1323
#define CONSTRUCT 1324
#define DELIMITER 1325
#define DOWNSHIFT 1326
#define DROP_VIEW 1327
#define END_INPUT 1328
#define END_WHILE 1329
#define EXCLUSIVE 1330
#define EXIT_CASE 1331
#define EXIT_MENU 1332
#define FORM_LINE 1333
#define INTERRUPT 1335
#define INTO_TEMP 1336
#define INVISIBLE 1337
#define IN_MEMORY 1338
#define LINKED_TO 1339
#define LOAD_FROM 1340
#define LOCKTAB 1341
#define MENU_LINE 1342
#define OPEN_FORM 1343
#define OTHERWISE 1344
#define PRECISION 1345
#define PRIOR 1346
#define PROCEDURE 1347
#define REPORT_TO 1348
#define RETURNING 1349
#define UNDERLINE 1350
#define UNLOAD_TO 1351
#define BEFROW 1352
#define UNLOAD_T 1353
#define VARIABLE 1354
#define ABSOLUTE 1355
#define AFTROW 1356
#define BUFFERED 1357
#define CONSTANT 1358
#define CONST 1359
#define CONTINUE 1360
#define DATABASE 1361
#define DATETIME 1362
#define DEFAULTS 1363
#define DISTINCT 1364
#define END_CASE 1365
#define END_MAIN 1366
#define END_MENU 1367
#define END_TYPE 1368
#define EXIT_FOR 1369
#define EXTERNAL 1370
#define FRACTION 1371
#define FUNCTION 1372
#define GROUP_BY 1373
#define INTERVAL 1374
#define KWMESSAGE 1375
#define NOT_LIKE 1376
#define NOT_ILIKE 1377
#define NOT_NULL 1378
#define PASSWORD 1379
#define PREVIOUS 1380
#define READONLY 1381
#define REGISTER 1382
#define RELATIVE 1383
#define RESOURCE 1384
#define SMALLINT 1385
#define VALIDATE 1386
#define WITH_LOG 1387
#define WORDWRAP 1388
#define BY_NAME 1389
#define IN_FILE 1390
#define IS_NULL 1391
#define AVERAGE 1393
#define BETWEEN 1394
#define CAPTION 1395
#define CLIPPED 1396
#define CLOSE_BRACKET 1397
#define COLUMNS 1398
#define COMMENT 1400
#define CONNECT 1401
#define CURRENT 1402
#define DBYNAME 1403
#define DECIMAL 1404
#define DECLARE 1405
#define DEFAULT 1406
#define DISPLAY 1407
#define ENDCODE 1408
#define EXECUTE 1409
#define FOREACH 1410
#define FOREIGN 1411
#define GLOBALS 1412
#define INFIELD 1413
#define INTEGER 1414
#define KWWINDOW 1415
#define MAGENTA 1416
#define NUMERIC 1418
#define OPTIONS 1419
#define PERCENT 1420
#define PREPARE 1421
#define PROGRAM 1422
#define RECOVER 1423
#define REVERSE 1424
#define SECTION 1425
#define SESSION 1426
#define SYNONYM 1427
#define THRU 1428
#define TRAILER 1429
#define UPSHIFT 1430
#define VARCHAR 1431
#define WAITING 1432
#define CLOSE_SHEV 1433
#define CLOSE_SQUARE 1434
#define KW_FALSE 1436
#define NOT_IN 1437
#define ONKEY 1438
#define OPEN_BRACKET 1439
#define BORDER 1440
#define BOTTOM 1441
#define COLUMN 1442
#define COMMIT 1443
#define CREATE 1444
#define CURSOR 1445
#define DEFINE 1446
#define DELETE 1447
#define DOUBLE 1448
#define END_IF 1449
#define ESCAPE 1450
#define EXISTS 1451
#define EXTEND 1452
#define EXTENT 1453
#define FINISH 1454
#define FORMAT 1455
#define HAVING 1456
#define HEADER 1457
#define INSERT 1458
#define LOCATE 1459
#define MARGIN 1460
#define MEMORY 1461
#define MINUTE 1462
#define MODIFY 1463
#define NORMAL 1464
#define EQUAL_EQUAL 1465
#define OPEN_SHEV 1467
#define OPEN_SQUARE 1468
#define OPTION 1469
#define OUTPUT 1470
#define PROMPT 1471
#define PUBLIC 1472
#define RECORD 1473
#define REPORT 1474
#define REVOKE 1475
#define SCHEMA 1476
#define SCROLL_USING 1477
#define SCROLL 1478
#define SECOND 1479
#define SELECT 1480
#define SERIAL 1481
#define SETL 1482
#define SHARED 1483
#define SPACES 1484
#define UNIQUE 1485
#define UNLOCK 1486
#define UPDATE 1487
#define VALUES 1488
#define YELLOW 1489
#define AFTER 1490
#define KWLINE 1491
#define KW_NULL 1492
#define KW_TRUE 1493
#define SINGLE_KEY 1494
#define ALTER 1495
#define ARRAY 1496
#define ASCII 1497
#define AUDIT 1498
#define BLACK 1499
#define BLINK 1500
#define CHECK 1501
#define CLEAR 1502
#define CLOSE 1503
#define CODE_C 1504
#define COUNT 1505
#define DEFER 1506
#define ERROR 1507
#define EVERY 1508
#define FETCH 1509
#define FIRST 1510
#define FLOAT 1511
#define FLUSH 1512
#define FOUND 1513
#define GRANT 1514
#define GREEN 1515
#define GROUP 1516
#define INDEX 1517
#define KWFORM 1518
#define LABEL 1519
#define LOCAL 1521
#define MONEY 1522
#define MONTH 1523
#define ORDER 1526
#define OUTER 1527
#define PAUSE 1528
#define PRINT_IMAGE 1529
#define PRINT_FILE 1530
#define PRINT 1531
#define RIGHT 1532
#define DOUBLE_COLON 1533
#define SEMICOLON 1534
#define SLEEP 1535
#define TUPLE 1536
#define UNION 1537
#define WHERE 1539
#define WHILE 1540
#define WHITE 1541
#define CCODE 1542
#define ANSI 1543
#define BLUE 1544
#define BOLD 1545
#define BYTE 1546
#define FCALL 1547
#define CASE 1548
#define CYAN 1549
#define DATE 1550
#define DESC 1551
#define KWDOWN 1553
#define TAB 1554
#define DROP 1555
#define ELSE 1556
#define EXEC 1557
#define EXIT 1558
#define FREE 1559
#define FROM 1560
#define GOTO 1561
#define HELP_FILE 1562
#define LANG_FILE 1563
#define HELP 1564
#define HIDE 1565
#define HOUR 1566
#define INTO 1567
#define LAST 1568
#define LEFT 1569
#define LIKE 1570
#define MAIN 1571
#define MENU 1572
#define MODE 1573
#define NEED 1574
#define NEXT 1575
#define NOCR 1576
#define OPEN 1577
#define QUIT 1578
#define REAL 1579
#define ROWS 1580
#define SHOW 1581
#define SIZE 1582
#define SKIP 1583
#define SOME 1584
#define STEP 1585
#define STOP 1586
#define TEMP 1587
#define TEXT 1588
#define THEN 1589
#define USER 1590
#define WAIT 1591
#define WHEN 1592
#define WITH 1593
#define WORK 1594
#define YEAR 1595
#define KW_IS 1597
#define XSET 1598
#define ADD 1599
#define ALL 1600
#define ANY 1602
#define ASC 1603
#define AVG 1604
#define COLON 1605
#define DAY 1607
#define DBA 1608
#define DEC 1609
#define DIM 1610
#define FKEY 1611
#define FOR 1612
#define KEY 1613
#define KWNO 1614
#define LET 1615
#define LOG 1616
#define XMAX 1617
#define XMIN 1618
#define PAD 1622
#define PUT 1623
#define RED 1624
#define ROW 1625
#define RUN 1626
#define SQL 1627
#define SUM 1628
#define TOP 1629
#define USE 1630
#define ATSIGN 1631
#define AS_TIFF 1633
#define AS_GIF 1634
#define AS_PNG 1635
#define AS_JPEG 1636
#define AS 1637
#define AT 1638
#define BY 1639
#define DOT 1640
#define GO 1641
#define IF 1642
#define IN 1643
#define OF 1644
#define ON 1645
#define TO 1647
#define KWUP 1648
#define FONT_NAME 1649
#define FONT_SIZE 1650
#define PAPER_SIZE_IS_LETTER 1651
#define PAPER_SIZE_IS_LEGAL 1652
#define PAPER_SIZE_IS_A5 1653
#define PAPER_SIZE_IS_A4 1654
#define PAPER_SIZE_IS_LETTER_L 1655
#define PAPER_SIZE_IS_LEGAL_L 1656
#define PAPER_SIZE_IS_A5_L 1657
#define PAPER_SIZE_IS_A4_L 1658
#define FORMHANDLER 1659
#define END_FORMHANDLER 1660
#define BEFORE_EVENT 1661
#define BEFORE_OPEN_FORM 1662
#define AFTER_EVENT 1663
#define BEFORE_CLOSE_FORM 1664
#define BEFORE_ANY 1665
#define AFTER_ANY 1666
#define MENUHANDLER 1667
#define END_MENUHANDLER 1668
#define BEFORE_SHOW_MENU 1669
#define DISABLE_PROGRAM 1670
#define DISABLE_ALL 1671
#define BUTTONS 1672
#define CHECK_MENUITEM 1673
#define DISABLE_FORM 1674
#define DISABLE_MENUITEMS 1675
#define DISABLE 1676
#define ENABLE_FORM 1677
#define ENABLE_MENUITEMS 1678
#define ENABLE 1679
#define KWFIELD 1680
#define ICON 1681
#define MESSAGEBOX 1682
#define TO_DEFAULTS 1683
#define UNCHECK_MENUITEM 1684
#define BEFORE 1685
#define INPUT 1686
#define END 1687
#define INT_TO_ID 1688
#define TIMEOUT 1689
#define OFF 1690
#define WITH_1_DIMENSION 1691
#define WITH_2_DIMENSION 1692
#define WITH_3_DIMENSION 1693
#define TILDE 1694
#define ILIKE 1695
#define FGL_ISDYNARR_ALLOCATED 1696
#define FGL_DYNARR_EXTENTSIZE 1697




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
#define UPDVAL2 	4

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
extern int compiling_system_4gl;

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

int 		is_schema=0;
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
int 		menu_blk[20]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
int 		in_sql=0;
int 		continue_cmd[]={0,1,1,1,1,1,1,1,1,0};
int 		in_cmd[]={0,0,0,0,0,0,0,0,0,0};
int 		fcall_cnt=0;
int 		doing_declare=0;
int 		message_cnt=0;

struct 		rep_structure rep_struct;
struct 		pdf_rep_structure pdf_rep_struct;
struct 		form_attr form_attrib;
char *		make_sql_string(char *first,...);
void copy_gen (int a, int b);
char *get_namespace (char *s);
void set_yytext (char *s);
int isin_command (char *cmd_type);
int a4gl_yylex (void *pyylval, int yystate, void *yys1, void *yys2);
char *do_clobbering(char *f,char *s);
struct input_array_attribs curr_input_array_attribs;

int if_print_stack[100][2];
int if_print_stack_cnt=0;
int if_print_section[100]={0,0,0,0};

#include "../generic.h"
#include "../field_handling.h"



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
#line 212 "fgl.yacc"
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
	int 	integer_val;
	float 	float_val;
	} YYSTYPE;
/* Line 191 of yacc.c.  */
#line 1673 "y.tab.c"
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 214 of yacc.c.  */
#line 1685 "y.tab.c"

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
#define YYFINAL  42
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   10110

/* YYNTOKENS -- Number of terminals. */
#define YYNTOKENS  713
/* YYNNTS -- Number of nonterminals. */
#define YYNNTS  837
/* YYNRULES -- Number of rules. */
#define YYNRULES  2234
/* YYNRULES -- Number of states. */
#define YYNSTATES  3518

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   1710

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
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    93,
      94,    95,    96,    97,    98,    99,   100,   101,   102,   103,
     104,   105,   106,   107,   108,   109,   110,   111,   112,   113,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   131,   132,   133,
     134,   135,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,   146,   147,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
     174,   175,   176,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   192,   193,
     194,   195,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,   256,   257,   258,   259,   260,   261,   262,   263,
     264,   265,   266,   267,   268,   269,   270,   271,   272,   273,
     274,   275,   276,   277,   278,   279,   280,   281,   282,   283,
     284,   285,   286,   287,   288,   289,   290,   291,   292,   293,
     294,   295,   296,   297,   298,   299,   300,   301,   302,   303,
     304,   305,   306,   307,   308,   309,   310,   311,   312,   313,
     314,   315,   316,   317,   318,   319,   320,   321,   322,   323,
     324,   325,   326,   327,   328,   329,   330,   331,   332,   333,
     334,   335,   336,   337,   338,   339,   340,   341,   342,   343,
     344,   345,   346,   347,   348,   349,   350,   351,   352,   353,
     354,   355,   356,   357,   358,   359,   360,   361,   362,   363,
     364,   365,   366,   367,    15,   368,   369,   370,   371,   372,
     373,   374,   375,   376,   377,   378,   379,   380,   381,   382,
     383,   384,   385,   386,   387,   388,   389,   390,   391,   392,
     393,   394,   395,   396,   397,   398,   399,   400,   401,   402,
     403,   404,   405,   406,   407,   408,   409,   410,   411,   412,
     413,   414,   415,   416,   417,   418,   419,   420,   421,   422,
     423,   424,    16,   425,   426,   427,   428,   429,   430,    23,
     431,   432,   433,   434,   435,   436,   437,   438,   439,   440,
     441,   442,   443,   444,   445,   446,   447,    10,   448,   449,
     450,   451,   452,   453,   454,   455,   456,   457,   458,   459,
     460,   461,   462,   463,   464,    13,   465,   466,   467,   468,
     469,   470,   471,   472,   473,   474,   475,   476,   477,   478,
     479,   480,   481,   482,   483,   484,   485,   486,   487,   488,
     489,   490,   491,   492,   493,   494,    17,   495,   496,   497,
     498,   499,   500,   501,   502,   503,   504,   505,   506,   507,
     508,   509,   510,   511,   512,   513,   514,   515,   516,   517,
     518,   519,   520,   521,   522,   523,   524,   525,   526,   527,
     528,   529,   530,   531,   532,   533,   534,   535,   536,   537,
     538,   539,   540,   541,   542,   543,   544,   545,   546,   547,
      12,   548,   549,   550,    11,    20,   551,   552,   553,   554,
     555,   556,   557,   558,   559,   560,   561,   562,     8,   563,
     564,   565,   566,   567,   568,   569,   570,   571,   572,   573,
     574,   575,    21,   576,   577,   578,   579,   580,   581,   582,
     583,   584,   585,   586,   587,   588,   589,   590,   591,   592,
     593,   594,   595,   596,   597,   598,   599,   600,   601,   602,
     603,   604,   605,   606,   607,   608,   609,   610,   611,   612,
     613,   614,   615,   616,   617,   618,    14,   619,   620,   621,
     622,     7,   623,   624,   625,   626,     5,   627,   628,   629,
     630,   631,   632,   633,   634,   635,   636,   637,   638,    19,
      22,     9,   639,   640,   641,   642,   643,   644,   645,   646,
     647,   648,    18,   649,   650,   651,   652,   653,   654,   655,
     656,   657,   658,   659,   660,   661,     6,   662,   663,   664,
     665,   666,   667,   668,   669,   670,   671,   672,   673,   674,
     675,   676,   677,   678,   679,   680,   681,   682,   683,   684,
     685,   686,   687,   688,   689,   690,   691,   692,   693,   694,
     695,   696,   697,   698,   699,   700,   701,   702,   703,   704,
     705,   706,   707,   708,   709,   710,   711,   712,     2,     3,
       4,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const unsigned short yyprhs[] =
{
       0,     0,     3,     5,     7,    13,    15,    17,    19,    21,
      25,    27,    31,    35,    37,    40,    42,    44,    46,    48,
      50,    52,    54,    56,    58,    59,    61,    62,    68,    75,
      77,    81,    83,    85,    87,    89,    91,    93,    95,    97,
      99,   101,   103,   105,   107,   109,   111,   113,   115,   116,
     118,   119,   125,   127,   131,   133,   135,   138,   141,   144,
     147,   150,   153,   156,   159,   163,   164,   172,   181,   188,
     190,   197,   198,   199,   209,   210,   211,   212,   221,   222,
     223,   234,   235,   236,   246,   247,   248,   249,   264,   265,
     268,   269,   272,   274,   275,   277,   279,   283,   285,   287,
     289,   291,   295,   296,   303,   304,   310,   312,   315,   317,
     320,   322,   323,   324,   328,   329,   330,   334,   335,   340,
     341,   346,   349,   352,   355,   357,   360,   363,   367,   369,
     371,   373,   376,   378,   380,   383,   385,   387,   388,   389,
     395,   403,   412,   413,   416,   418,   422,   424,   428,   432,
     434,   437,   438,   443,   444,   449,   450,   454,   455,   459,
     460,   464,   466,   470,   472,   476,   478,   480,   482,   484,
     486,   488,   493,   494,   499,   501,   503,   504,   506,   508,
     511,   512,   513,   519,   521,   523,   527,   528,   531,   536,
     541,   546,   551,   554,   555,   560,   562,   564,   566,   569,
     571,   573,   577,   578,   580,   581,   583,   585,   587,   588,
     596,   597,   603,   604,   617,   619,   621,   623,   625,   627,
     633,   637,   639,   641,   642,   647,   648,   654,   655,   663,
     665,   669,   671,   673,   674,   676,   677,   678,   683,   685,
     687,   689,   694,   699,   706,   708,   711,   713,   715,   717,
     719,   724,   731,   733,   738,   745,   747,   749,   751,   753,
     755,   757,   759,   762,   765,   767,   769,   774,   776,   778,
     779,   783,   787,   788,   791,   793,   795,   797,   799,   801,
     803,   806,   807,   810,   811,   815,   816,   820,   822,   823,
     827,   829,   831,   833,   835,   837,   839,   842,   844,   845,
     847,   848,   854,   856,   858,   860,   865,   870,   877,   879,
     881,   883,   885,   890,   897,   899,   904,   911,   913,   915,
     917,   919,   921,   924,   927,   929,   934,   935,   943,   944,
     957,   958,   963,   964,   970,   972,   976,   979,   981,   985,
     987,   988,   991,   994,   996,   999,  1005,  1010,  1013,  1018,
    1024,  1028,  1029,  1030,  1042,  1043,  1046,  1048,  1049,  1052,
    1054,  1056,  1059,  1060,  1064,  1065,  1069,  1070,  1074,  1077,
    1080,  1083,  1088,  1094,  1096,  1098,  1100,  1102,  1104,  1106,
    1108,  1110,  1112,  1114,  1116,  1118,  1120,  1122,  1124,  1126,
    1128,  1130,  1133,  1135,  1137,  1139,  1141,  1144,  1146,  1148,
    1150,  1153,  1156,  1158,  1160,  1162,  1164,  1166,  1168,  1170,
    1172,  1174,  1176,  1179,  1181,  1184,  1186,  1188,  1190,  1194,
    1196,  1200,  1202,  1206,  1208,  1210,  1212,  1215,  1217,  1219,
    1223,  1228,  1233,  1236,  1239,  1241,  1243,  1245,  1247,  1249,
    1253,  1255,  1258,  1261,  1263,  1264,  1268,  1271,  1274,  1276,
    1280,  1285,  1290,  1296,  1302,  1304,  1306,  1309,  1312,  1317,
    1322,  1325,  1328,  1333,  1338,  1340,  1343,  1346,  1349,  1352,
    1355,  1358,  1361,  1364,  1367,  1370,  1373,  1376,  1379,  1382,
    1383,  1384,  1385,  1392,  1393,  1394,  1403,  1404,  1405,  1412,
    1413,  1414,  1421,  1422,  1423,  1430,  1431,  1432,  1439,  1445,
    1451,  1457,  1465,  1470,  1477,  1478,  1482,  1484,  1486,  1491,
    1496,  1501,  1506,  1511,  1516,  1518,  1520,  1522,  1524,  1529,
    1534,  1537,  1540,  1543,  1546,  1549,  1551,  1553,  1556,  1558,
    1560,  1562,  1565,  1570,  1577,  1584,  1588,  1594,  1600,  1604,
    1606,  1608,  1612,  1614,  1618,  1619,  1620,  1632,  1633,  1636,
    1637,  1638,  1639,  1649,  1650,  1654,  1655,  1656,  1667,  1668,
    1670,  1671,  1673,  1675,  1678,  1679,  1683,  1684,  1688,  1689,
    1691,  1693,  1696,  1697,  1701,  1702,  1706,  1710,  1712,  1717,
    1721,  1723,  1727,  1729,  1733,  1735,  1739,  1741,  1744,  1745,
    1749,  1750,  1754,  1755,  1760,  1761,  1766,  1767,  1772,  1775,
    1779,  1781,  1785,  1787,  1789,  1791,  1793,  1795,  1797,  1799,
    1803,  1805,  1807,  1812,  1819,  1824,  1828,  1835,  1839,  1846,
    1848,  1850,  1852,  1854,  1856,  1858,  1859,  1862,  1864,  1866,
    1868,  1873,  1875,  1877,  1879,  1884,  1888,  1895,  1899,  1906,
    1908,  1910,  1913,  1916,  1918,  1921,  1924,  1926,  1930,  1932,
    1935,  1938,  1941,  1946,  1949,  1952,  1957,  1958,  1967,  1968,
    1970,  1972,  1974,  1975,  1977,  1980,  1981,  1983,  1986,  1987,
    1989,  1992,  1993,  1995,  1999,  2000,  2003,  2004,  2005,  2014,
    2015,  2016,  2020,  2021,  2022,  2030,  2036,  2039,  2042,  2043,
    2049,  2054,  2056,  2060,  2064,  2068,  2069,  2072,  2074,  2075,
    2077,  2079,  2082,  2083,  2088,  2089,  2094,  2095,  2099,  2100,
    2104,  2105,  2109,  2110,  2114,  2115,  2119,  2120,  2124,  2125,
    2129,  2130,  2134,  2135,  2139,  2141,  2145,  2147,  2151,  2154,
    2159,  2161,  2163,  2165,  2166,  2171,  2177,  2184,  2185,  2196,
    2200,  2203,  2206,  2208,  2210,  2211,  2214,  2216,  2219,  2223,
    2227,  2231,  2235,  2237,  2239,  2241,  2243,  2244,  2248,  2250,
    2251,  2255,  2258,  2261,  2263,  2267,  2269,  2273,  2275,  2277,
    2279,  2281,  2283,  2285,  2287,  2289,  2291,  2293,  2295,  2297,
    2299,  2301,  2303,  2305,  2307,  2309,  2311,  2313,  2314,  2315,
    2323,  2325,  2327,  2330,  2333,  2336,  2340,  2345,  2346,  2350,
    2351,  2353,  2355,  2358,  2360,  2362,  2364,  2366,  2367,  2369,
    2371,  2374,  2377,  2379,  2381,  2383,  2385,  2387,  2389,  2391,
    2393,  2395,  2397,  2399,  2400,  2402,  2404,  2406,  2408,  2409,
    2410,  2411,  2412,  2426,  2428,  2429,  2430,  2437,  2440,  2442,
    2445,  2448,  2451,  2453,  2455,  2458,  2460,  2462,  2464,  2465,
    2469,  2472,  2474,  2475,  2476,  2477,  2492,  2493,  2499,  2501,
    2502,  2506,  2507,  2515,  2516,  2522,  2524,  2527,  2528,  2530,
    2532,  2534,  2535,  2537,  2539,  2542,  2545,  2548,  2550,  2552,
    2554,  2556,  2560,  2562,  2564,  2565,  2566,  2574,  2576,  2579,
    2580,  2584,  2585,  2590,  2593,  2594,  2597,  2599,  2601,  2603,
    2605,  2607,  2609,  2611,  2615,  2616,  2618,  2620,  2622,  2624,
    2627,  2630,  2633,  2639,  2648,  2650,  2652,  2654,  2659,  2664,
    2666,  2668,  2670,  2672,  2675,  2678,  2682,  2689,  2691,  2695,
    2697,  2699,  2701,  2705,  2712,  2722,  2724,  2726,  2728,  2730,
    2733,  2734,  2736,  2738,  2742,  2744,  2748,  2750,  2754,  2756,
    2760,  2762,  2764,  2766,  2768,  2772,  2774,  2778,  2780,  2784,
    2786,  2788,  2790,  2794,  2797,  2798,  2800,  2802,  2807,  2809,
    2813,  2815,  2819,  2827,  2828,  2836,  2837,  2844,  2848,  2850,
    2854,  2856,  2859,  2865,  2866,  2874,  2875,  2878,  2879,  2881,
    2887,  2890,  2896,  2897,  2903,  2910,  2915,  2916,  2918,  2920,
    2925,  2926,  2929,  2930,  2936,  2941,  2944,  2946,  2950,  2953,
    2956,  2959,  2962,  2965,  2968,  2970,  2973,  2976,  2979,  2982,
    2985,  2988,  2991,  2994,  2997,  2999,  3001,  3003,  3005,  3007,
    3009,  3015,  3017,  3019,  3022,  3027,  3030,  3032,  3033,  3045,
    3046,  3049,  3055,  3056,  3058,  3059,  3062,  3064,  3067,  3068,
    3072,  3074,  3075,  3080,  3081,  3084,  3086,  3090,  3092,  3094,
    3098,  3103,  3108,  3111,  3113,  3115,  3117,  3118,  3120,  3128,
    3131,  3134,  3137,  3140,  3143,  3145,  3148,  3149,  3153,  3154,
    3158,  3159,  3163,  3164,  3168,  3169,  3173,  3174,  3179,  3180,
    3185,  3187,  3189,  3191,  3193,  3195,  3197,  3198,  3203,  3204,
    3206,  3207,  3212,  3214,  3217,  3220,  3223,  3224,  3226,  3228,
    3231,  3234,  3235,  3238,  3242,  3246,  3252,  3253,  3256,  3261,
    3263,  3265,  3267,  3269,  3271,  3272,  3274,  3276,  3280,  3283,
    3289,  3292,  3298,  3304,  3310,  3316,  3322,  3328,  3329,  3332,
    3334,  3337,  3340,  3343,  3346,  3349,  3352,  3354,  3357,  3360,
    3363,  3366,  3368,  3371,  3374,  3377,  3380,  3382,  3384,  3386,
    3387,  3390,  3393,  3396,  3399,  3402,  3405,  3408,  3411,  3414,
    3416,  3418,  3420,  3422,  3424,  3426,  3428,  3430,  3433,  3436,
    3439,  3442,  3445,  3447,  3449,  3451,  3452,  3456,  3459,  3460,
    3461,  3462,  3463,  3464,  3465,  3481,  3482,  3485,  3488,  3489,
    3491,  3492,  3493,  3494,  3495,  3496,  3497,  3513,  3516,  3517,
    3518,  3519,  3530,  3531,  3533,  3537,  3541,  3544,  3549,  3553,
    3557,  3561,  3563,  3565,  3567,  3569,  3571,  3573,  3574,  3575,
    3583,  3584,  3585,  3594,  3602,  3605,  3606,  3608,  3610,  3614,
    3617,  3620,  3622,  3624,  3628,  3630,  3632,  3635,  3637,  3641,
    3645,  3649,  3651,  3655,  3657,  3659,  3661,  3663,  3665,  3667,
    3669,  3672,  3677,  3679,  3683,  3685,  3689,  3692,  3697,  3699,
    3703,  3705,  3708,  3713,  3715,  3719,  3721,  3723,  3725,  3728,
    3731,  3736,  3739,  3744,  3746,  3750,  3752,  3754,  3756,  3759,
    3761,  3763,  3765,  3767,  3769,  3772,  3779,  3786,  3787,  3789,
    3790,  3792,  3795,  3797,  3798,  3804,  3805,  3811,  3813,  3814,
    3818,  3820,  3824,  3826,  3830,  3832,  3834,  3835,  3836,  3842,
    3844,  3847,  3849,  3850,  3851,  3855,  3856,  3857,  3861,  3863,
    3865,  3867,  3869,  3871,  3873,  3876,  3879,  3884,  3888,  3892,
    3894,  3898,  3901,  3903,  3905,  3906,  3908,  3910,  3912,  3914,
    3915,  3917,  3921,  3923,  3927,  3929,  3930,  3934,  3936,  3938,
    3940,  3942,  3944,  3946,  3948,  3950,  3952,  3954,  3956,  3958,
    3966,  3967,  3969,  3971,  3973,  3975,  3979,  3981,  3983,  3985,
    3988,  3989,  3993,  3995,  3999,  4001,  4005,  4007,  4009,  4016,
    4017,  4021,  4023,  4027,  4028,  4030,  4035,  4041,  4044,  4046,
    4048,  4053,  4055,  4059,  4064,  4069,  4071,  4075,  4077,  4079,
    4081,  4084,  4086,  4091,  4092,  4094,  4095,  4097,  4099,  4102,
    4104,  4106,  4108,  4110,  4115,  4119,  4121,  4123,  4125,  4128,
    4130,  4132,  4135,  4138,  4140,  4144,  4147,  4150,  4152,  4156,
    4158,  4161,  4166,  4168,  4171,  4173,  4177,  4182,  4183,  4185,
    4186,  4188,  4189,  4191,  4193,  4197,  4199,  4203,  4205,  4208,
    4210,  4214,  4217,  4220,  4221,  4224,  4226,  4228,  4234,  4238,
    4244,  4248,  4250,  4254,  4256,  4258,  4259,  4261,  4265,  4269,
    4273,  4280,  4285,  4290,  4295,  4300,  4306,  4308,  4310,  4312,
    4314,  4316,  4318,  4320,  4322,  4324,  4326,  4328,  4330,  4331,
    4333,  4335,  4337,  4339,  4341,  4343,  4345,  4350,  4356,  4358,
    4364,  4370,  4372,  4374,  4376,  4381,  4383,  4388,  4390,  4398,
    4400,  4402,  4404,  4409,  4416,  4417,  4420,  4425,  4427,  4429,
    4431,  4433,  4435,  4437,  4439,  4443,  4445,  4447,  4451,  4455,
    4457,  4459,  4463,  4465,  4466,  4470,  4476,  4478,  4481,  4484,
    4489,  4493,  4495,  4497,  4499,  4501,  4503,  4505,  4508,  4511,
    4512,  4516,  4517,  4521,  4523,  4525,  4527,  4529,  4531,  4533,
    4535,  4540,  4542,  4544,  4546,  4548,  4550,  4552,  4554,  4559,
    4561,  4563,  4565,  4567,  4569,  4571,  4573,  4575,  4577,  4579,
    4581,  4583,  4585,  4587,  4592,  4594,  4598,  4600,  4604,  4605,
    4613,  4614,  4623,  4624,  4631,  4632,  4641,  4642,  4644,  4647,
    4649,  4653,  4655,  4659,  4665,  4667,  4669,  4671,  4673,  4675,
    4676,  4677,  4687,  4693,  4695,  4697,  4704,  4705,  4709,  4711,
    4715,  4720,  4722,  4723,  4726,  4731,  4738,  4739,  4741,  4743,
    4745,  4747,  4751,  4753,  4756,  4758,  4760,  4763,  4766,  4768,
    4770,  4772,  4775,  4780,  4784,  4787,  4791,  4795,  4799,  4801,
    4803,  4805,  4807,  4809,  4811,  4817,  4823,  4829,  4835,  4841,
    4846,  4851,  4855,  4860,  4862,  4866,  4868,  4874,  4882,  4888,
    4889,  4892,  4894,  4896,  4897,  4901,  4903,  4907,  4909,  4911,
    4913,  4914,  4918,  4920,  4922,  4924,  4926,  4931,  4938,  4940,
    4942,  4945,  4949,  4951,  4953,  4955,  4957,  4959,  4961,  4963,
    4965,  4971,  4977,  4982,  4983,  4988,  4990,  4993,  4995,  4997,
    4999,  5001,  5003,  5005,  5007,  5009,  5011,  5013,  5015,  5017,
    5019,  5021,  5023,  5025,  5027,  5029,  5031,  5033,  5035,  5037,
    5039,  5041,  5043,  5045,  5047,  5049,  5051,  5053,  5055,  5057,
    5059,  5061,  5063,  5065,  5067,  5069,  5071,  5073,  5075,  5077,
    5079,  5081,  5083,  5085,  5087,  5089,  5091,  5093,  5095,  5097,
    5099,  5101,  5103,  5105,  5107,  5109,  5111,  5113,  5115,  5117,
    5119,  5121,  5123,  5125,  5127,  5129,  5131,  5133,  5135,  5137,
    5139,  5141,  5143,  5145,  5147,  5149,  5151,  5153,  5155,  5157,
    5159,  5161,  5163,  5165,  5167,  5169,  5171,  5173,  5175,  5177,
    5179,  5181,  5183,  5185,  5187,  5189,  5191,  5193,  5195,  5197,
    5199,  5201,  5203,  5205,  5207,  5209,  5211,  5213,  5215,  5217,
    5219,  5221,  5223,  5225,  5227,  5229,  5231,  5233,  5235,  5237,
    5239,  5241,  5243,  5245,  5247,  5249,  5251,  5253,  5255,  5257,
    5259,  5261,  5263,  5265,  5267,  5269,  5271,  5273,  5275,  5277,
    5279,  5281,  5283,  5285,  5287,  5289,  5291,  5293,  5295,  5297,
    5299,  5301,  5303,  5305,  5307,  5309,  5311,  5313,  5315,  5317,
    5319,  5321,  5323,  5325,  5327,  5329,  5331,  5333,  5335,  5337,
    5339,  5341,  5343,  5345,  5347,  5349,  5351,  5353,  5355,  5357,
    5359,  5361,  5363,  5365,  5367,  5369,  5371,  5373,  5375,  5377,
    5379,  5381,  5383,  5385,  5387,  5389,  5391,  5393,  5395,  5397,
    5399,  5401,  5403,  5405,  5407,  5409,  5411,  5413,  5415,  5417,
    5419,  5421,  5423,  5425,  5427,  5429,  5431,  5433,  5435,  5437,
    5439,  5441,  5443,  5445,  5447,  5449,  5451,  5453,  5455,  5457,
    5459,  5461,  5463,  5465,  5467,  5469,  5471,  5473,  5475,  5477,
    5479,  5481,  5483,  5485,  5487,  5489,  5491,  5493,  5495,  5497,
    5499,  5501,  5503,  5505,  5507,  5509,  5511,  5513,  5515,  5517,
    5519,  5521,  5523,  5525,  5527,  5529,  5531,  5533,  5535,  5537,
    5539,  5541,  5543,  5545,  5547,  5549,  5551,  5553,  5555,  5557,
    5559,  5561,  5563,  5565,  5567,  5569,  5571,  5573,  5575,  5577,
    5579,  5581,  5583,  5585,  5587,  5589,  5591,  5593,  5595,  5597,
    5599,  5601,  5603,  5605,  5607,  5609,  5611,  5613,  5615,  5617,
    5619,  5621,  5623,  5625,  5627,  5629,  5631,  5633,  5634,  5638,
    5639,  5643,  5644,  5645,  5652,  5653,  5656,  5659,  5667,  5671,
    5675,  5678,  5681,  5684,  5686,  5690,  5692,  5696,  5698,  5702,
    5704,  5708,  5710,  5712,  5714,  5717,  5720,  5722,  5724,  5727,
    5732,  5734,  5736,  5738,  5740,  5742,  5744,  5748,  5751,  5755,
    5759,  5763,  5769,  5775,  5781,  5787,  5793,  5798,  5803,  5807,
    5812,  5814,  5816,  5820,  5821,  5827,  5829,  5833,  5837,  5841,
    5843,  5846,  5848,  5850,  5852,  5856,  5862,  5864,  5866,  5868,
    5870,  5874,  5875,  5876,  5883,  5884,  5887,  5888,  5890,  5892,
    5895,  5898,  5900,  5902,  5907,  5911,  5913,  5915,  5918,  5924,
    5927,  5930,  5936,  5937,  5940,  5942,  5944,  5947,  5954,  5961,
    5963,  5964,  5966,  5969,  5971,  5974,  5975,  5978,  5980,  5982,
    5984,  5986,  5988,  5990,  5992,  5994,  5996,  5998,  6000,  6002,
    6004,  6006,  6008,  6010,  6012,  6014,  6016,  6018,  6020,  6022,
    6024,  6026,  6028,  6030,  6032,  6034,  6036,  6038,  6040,  6042,
    6044,  6046,  6048,  6050,  6052,  6054,  6056,  6058,  6060,  6062,
    6064,  6066,  6068,  6070,  6072,  6074,  6076,  6078,  6080,  6082,
    6084,  6086,  6088,  6090,  6092,  6094,  6096,  6098,  6100,  6102,
    6104,  6106,  6108,  6110,  6112,  6114,  6116,  6118,  6120,  6122,
    6124,  6126,  6128,  6130,  6132,  6134,  6136,  6138,  6140,  6142,
    6144,  6146,  6148,  6150,  6152
};

/* YYRHS -- A `-1'-separated list of the rules' RHS. */
static const short yyrhs[] =
{
    1077,     0,    -1,   238,    -1,   235,    -1,   168,   718,   464,
     632,   719,    -1,   179,    -1,  1142,    -1,    26,    -1,   720,
      -1,   719,     5,   720,    -1,   988,    -1,   468,   721,   429,
      -1,   721,   722,   721,    -1,    26,    -1,   723,    26,    -1,
    1142,    -1,   930,    -1,    18,    -1,    19,    -1,    20,    -1,
      21,    -1,    22,    -1,    18,    -1,    19,    -1,    -1,   725,
      -1,    -1,   312,   468,   726,   727,   429,    -1,   605,   468,
      26,     5,    26,   429,    -1,   728,    -1,   727,     5,   728,
      -1,   527,    -1,   568,    -1,   573,    -1,   543,    -1,   447,
      -1,   641,    -1,   565,    -1,   517,    -1,   454,    -1,   528,
      -1,   383,    -1,   569,    -1,   493,    -1,   370,    -1,   630,
      -1,   134,    -1,  1056,    -1,    -1,   730,    -1,    -1,   312,
     468,   731,   732,   429,    -1,   733,    -1,   732,     5,   733,
      -1,   728,    -1,   469,    -1,   639,    25,    -1,   241,   975,
      -1,   367,   975,    -1,   322,   975,    -1,   375,   975,    -1,
     331,   975,    -1,   297,   975,    -1,   571,   735,    -1,   919,
     382,  1142,    -1,    -1,   327,   468,  1534,   429,   382,   736,
    1161,    -1,   142,   468,   988,     5,    25,     5,    25,   429,
      -1,   444,   468,   980,   429,   382,  1142,    -1,  1280,    -1,
     230,   468,   938,   429,   382,  1142,    -1,    -1,    -1,  1142,
     626,   988,   468,   737,   751,   429,   738,   749,    -1,    -1,
      -1,    -1,   988,   468,   739,   751,   740,   429,   741,   749,
      -1,    -1,    -1,   511,  1479,   659,  1479,   468,   742,   751,
     743,   429,   749,    -1,    -1,    -1,   988,   558,   988,   468,
     744,   751,   745,   429,   749,    -1,    -1,    -1,    -1,   403,
     754,   626,   755,   496,   718,   464,   468,   746,   751,   747,
     429,   748,   750,    -1,    -1,   382,  1161,    -1,    -1,   382,
    1161,    -1,   201,    -1,    -1,   752,    -1,   753,    -1,   752,
       5,   753,    -1,   888,    -1,    25,    -1,   988,    -1,   988,
      -1,   988,   656,   988,    -1,    -1,   572,   895,   757,   760,
     764,   761,    -1,    -1,   572,   758,   759,   762,   761,    -1,
     766,    -1,   759,   766,    -1,   768,    -1,   760,   768,    -1,
     398,    -1,    -1,    -1,   377,   763,  1544,    -1,    -1,    -1,
     377,   765,  1544,    -1,    -1,   615,   895,   767,  1544,    -1,
      -1,   615,   895,   769,  1544,    -1,   316,   985,    -1,   240,
     983,    -1,   119,   983,    -1,   206,    -1,   223,  1485,    -1,
     531,   982,    -1,    30,   772,    31,    -1,   773,    -1,   775,
      -1,   774,    -1,   773,   774,    -1,    29,    -1,   776,    -1,
     775,   776,    -1,    28,    -1,   431,    -1,    -1,    -1,   358,
     779,   781,   780,   782,    -1,   422,  1142,   661,   783,  1030,
    1055,   724,    -1,  1142,   661,   783,  1030,   583,  1534,  1055,
     724,    -1,    -1,   785,   229,    -1,   784,    -1,   783,     5,
     784,    -1,   988,    -1,   988,   656,   988,    -1,   988,   656,
      20,    -1,   786,    -1,   785,   786,    -1,    -1,   308,   792,
     787,  1544,    -1,    -1,   311,   793,   788,  1544,    -1,    -1,
    1058,   789,  1544,    -1,    -1,   204,   790,  1544,    -1,    -1,
     202,   791,  1544,    -1,   992,    -1,   792,     5,   992,    -1,
     992,    -1,   793,     5,   992,    -1,   128,    -1,   129,    -1,
     130,    -1,   131,    -1,   132,    -1,   133,    -1,   468,   888,
     796,   429,    -1,    -1,     5,   839,   662,   842,    -1,   194,
      -1,   317,    -1,    -1,   799,    -1,   800,    -1,   799,   800,
      -1,    -1,    -1,   475,   801,   803,   802,  1249,    -1,   852,
      -1,   806,    -1,   803,     5,   806,    -1,    -1,   805,   988,
      -1,   391,   804,   851,    25,    -1,   391,   804,   851,   988,
      -1,   391,   804,   851,   994,    -1,   391,   804,   851,    26,
      -1,   810,   828,    -1,    -1,   804,   391,   807,   808,    -1,
      26,    -1,    25,    -1,   994,    -1,    19,    26,    -1,   804,
      -1,   809,    -1,   810,     5,   809,    -1,    -1,   357,    -1,
      -1,   706,    -1,   707,    -1,   708,    -1,    -1,   524,   496,
     820,   464,   814,   660,   828,    -1,    -1,    34,   812,   815,
     660,   828,    -1,    -1,   356,   811,   817,    26,   818,   340,
     496,   819,   464,   816,   660,   828,    -1,   468,    -1,   495,
      -1,   429,    -1,   463,    -1,    26,    -1,   821,     5,   821,
       5,   821,    -1,   821,     5,   821,    -1,   821,    -1,    26,
      -1,    -1,   501,   823,   803,   321,    -1,    -1,   298,   824,
     804,   656,    20,    -1,    -1,   372,   825,   804,   296,   468,
     826,   429,    -1,   827,    -1,   826,     5,   827,    -1,   804,
      -1,   830,    -1,    -1,    94,    -1,    -1,    -1,   831,   833,
     832,   829,    -1,   813,    -1,   822,    -1,   357,    -1,   357,
     468,    26,   429,    -1,   461,   468,    26,   429,    -1,   461,
     468,    26,     5,    26,   429,    -1,   445,    -1,   653,   804,
      -1,   418,    -1,   546,    -1,   125,    -1,   435,    -1,   435,
     468,    26,   429,    -1,   435,   468,    26,     5,    26,   429,
      -1,   549,    -1,   549,   468,    26,   429,    -1,   549,   468,
      26,     5,    26,   429,    -1,   539,    -1,   337,    -1,   574,
      -1,   570,    -1,   115,    -1,   116,    -1,   611,    -1,   395,
     837,    -1,   407,   838,    -1,   834,    -1,    32,    -1,   593,
     835,   656,   836,    -1,   804,    -1,   804,    -1,    -1,   839,
     662,   842,    -1,   847,   662,   850,    -1,    -1,   840,   841,
      -1,   618,    -1,   550,    -1,   627,    -1,   589,    -1,   491,
      -1,   507,    -1,   404,   844,    -1,    -1,   843,   841,    -1,
      -1,   468,   846,   429,    -1,    -1,   468,    26,   429,    -1,
      26,    -1,    -1,   848,   849,   845,    -1,   618,    -1,   550,
      -1,   627,    -1,   589,    -1,   491,    -1,   507,    -1,   404,
     844,    -1,   849,    -1,    -1,    14,    -1,    -1,   274,   988,
     853,   653,   854,    -1,   856,    -1,   859,    -1,   357,    -1,
     357,   468,    26,   429,    -1,   461,   468,    26,   429,    -1,
     461,   468,    26,     5,    26,   429,    -1,   445,    -1,   418,
      -1,   546,    -1,   435,    -1,   435,   468,    26,   429,    -1,
     435,   468,    26,     5,    26,   429,    -1,   549,    -1,   549,
     468,    26,   429,    -1,   549,   468,    26,     5,    26,   429,
      -1,   539,    -1,   337,    -1,   574,    -1,   570,    -1,   611,
      -1,   395,   837,    -1,   407,   838,    -1,   855,    -1,   593,
     835,   656,   836,    -1,    -1,   524,   496,   820,   464,   857,
     660,   854,    -1,    -1,   356,   811,   817,    26,   818,   340,
     496,   819,   464,   858,   660,   854,    -1,    -1,   501,   860,
     862,   321,    -1,    -1,   298,   861,   988,   656,    20,    -1,
     863,    -1,   862,     5,   863,    -1,   864,   854,    -1,   865,
      -1,   864,     5,   865,    -1,   988,    -1,    -1,   654,   979,
      -1,   106,   988,    -1,   104,    -1,   662,  1534,    -1,   662,
     546,   988,   695,  1534,    -1,   662,   546,   988,   427,    -1,
     108,   988,    -1,   195,   913,  1161,   874,    -1,   438,   913,
     893,   866,   874,    -1,   247,   985,   874,    -1,    -1,    -1,
     226,   871,  1168,   662,   988,   656,    20,   873,   724,   872,
     875,    -1,    -1,   505,   980,    -1,   724,    -1,    -1,   876,
     276,    -1,   276,    -1,   877,    -1,   876,   877,    -1,    -1,
     389,   878,  1544,    -1,    -1,   385,   879,  1544,    -1,    -1,
    1058,   880,  1544,    -1,    36,  1142,    -1,    37,  1142,    -1,
      35,  1142,    -1,   535,   913,   894,   724,    -1,   535,   913,
     894,   724,   101,    -1,   324,    -1,   323,    -1,   250,    -1,
     402,    -1,   211,    -1,   249,    -1,   366,    -1,   365,    -1,
     281,    -1,   208,    -1,   207,    -1,   185,    -1,   242,    -1,
     169,    -1,   184,    -1,   225,    -1,   192,    -1,   251,    -1,
     251,   895,    -1,   898,    -1,   897,    -1,   902,    -1,   930,
      -1,   888,   889,    -1,   931,    -1,   933,    -1,   899,    -1,
      19,   888,    -1,    18,   888,    -1,   904,    -1,   912,    -1,
     906,    -1,   512,    -1,   794,    -1,   907,    -1,   908,    -1,
     909,    -1,   910,    -1,   911,    -1,    39,   888,    -1,   913,
      -1,   913,   892,    -1,   895,    -1,   520,    -1,   891,    -1,
     892,     5,   891,    -1,   895,    -1,   893,     5,   895,    -1,
     895,    -1,   894,     5,   895,    -1,   888,    -1,    18,    -1,
      19,    -1,     9,   888,    -1,   521,    -1,   465,    -1,   468,
     888,   429,    -1,   480,   468,  1459,   429,    -1,   332,   468,
    1459,   429,    -1,   896,   994,    -1,   896,    26,    -1,    25,
      -1,   994,    -1,    26,    -1,   901,    -1,  1142,    -1,  1142,
     458,  1142,    -1,   900,    -1,   471,   888,    -1,   430,   888,
      -1,  1252,    -1,    -1,   544,   903,  1252,    -1,     7,   888,
      -1,     6,   888,    -1,   888,    -1,   905,     5,   888,    -1,
     659,   468,  1459,   429,    -1,   466,   468,  1459,   429,    -1,
     659,   468,   913,   905,   429,    -1,   466,   468,   913,   905,
     429,    -1,   424,    -1,   287,    -1,    10,   888,    -1,   290,
     888,    -1,    10,   888,   479,    25,    -1,   290,   888,   479,
      25,    -1,   593,   888,    -1,   409,   888,    -1,   593,   888,
     479,    25,    -1,   409,   888,   479,    25,    -1,   428,    -1,
       8,   888,    -1,    18,   888,    -1,    19,   888,    -1,    20,
     888,    -1,    21,   888,    -1,    22,   888,    -1,    11,   888,
      -1,    14,   888,    -1,   494,   888,    -1,    12,   888,    -1,
      13,   888,    -1,    17,   888,    -1,    16,   888,    -1,    15,
     888,    -1,    -1,    -1,    -1,   988,   468,   915,   751,   916,
     429,    -1,    -1,    -1,   988,   558,   988,   468,   917,   751,
     918,   429,    -1,    -1,    -1,   574,   468,   920,   888,   921,
     429,    -1,    -1,    -1,   550,   468,   922,   888,   923,   429,
      -1,    -1,    -1,   627,   468,   924,   888,   925,   429,    -1,
      -1,    -1,   618,   468,   926,   888,   927,   429,    -1,   407,
     468,   934,   429,   929,    -1,   395,   468,    25,   429,   928,
      -1,   395,   468,    26,   429,   928,    -1,   395,   468,    26,
     626,    26,   429,   928,    -1,   711,   468,  1142,   429,    -1,
     712,   468,  1142,     5,    26,   429,    -1,    -1,  1439,   662,
    1440,    -1,   838,    -1,   919,    -1,   327,   468,  1534,   429,
      -1,   135,   468,   980,   429,    -1,   107,   468,   980,   429,
      -1,   444,   468,  1534,   429,    -1,   230,   468,  1534,   429,
      -1,    95,   468,  1534,   429,    -1,   932,    -1,   914,    -1,
    1435,    -1,   574,    -1,   460,   468,   888,   429,    -1,   360,
     468,   888,   429,    -1,   525,   888,    -1,   481,   795,    -1,
     888,   146,    -1,   888,   147,    -1,   888,   148,    -1,    25,
      -1,   935,    -1,    19,   935,    -1,   937,    -1,   936,    -1,
      26,    -1,    26,    26,    -1,    26,    26,   626,    26,    -1,
      26,    26,   626,    26,   626,    26,    -1,    26,    26,   626,
      26,   626,    24,    -1,    26,   626,    26,    -1,    26,   626,
      26,   626,    26,    -1,    26,   626,    26,   626,    24,    -1,
      26,   626,    24,    -1,    24,    -1,    26,    -1,    26,    19,
      26,    -1,   980,    -1,   938,     5,   980,    -1,    -1,    -1,
     632,  1142,    14,   895,   662,   895,   942,   940,  1544,   941,
     279,    -1,    -1,   608,   895,    -1,    -1,    -1,    -1,   441,
     944,   982,   945,   947,  1339,   946,  1544,   278,    -1,    -1,
       8,   913,   893,    -1,    -1,    -1,   674,   988,   949,   798,
     950,  1087,   952,   951,   957,   675,    -1,    -1,   962,    -1,
      -1,   953,    -1,   954,    -1,   953,   954,    -1,    -1,   676,
     955,  1544,    -1,    -1,   677,   956,  1544,    -1,    -1,   958,
      -1,   959,    -1,   958,   959,    -1,    -1,   678,   960,  1544,
      -1,    -1,   679,   961,  1544,    -1,   963,   967,   362,    -1,
     127,    -1,   127,   964,   583,   965,    -1,   127,   422,   966,
      -1,  1142,    -1,   964,     5,  1142,    -1,   988,    -1,   965,
       5,   988,    -1,  1142,    -1,   966,     5,  1142,    -1,   968,
      -1,   967,   968,    -1,    -1,   680,   969,  1544,    -1,    -1,
     681,   970,  1544,    -1,    -1,   700,   965,   971,  1544,    -1,
      -1,   518,   965,   972,  1544,    -1,    -1,   661,   965,   973,
    1544,    -1,   582,   981,    -1,   591,    19,    26,    -1,   591,
      -1,   538,    18,    26,    -1,   538,    -1,    26,    -1,  1142,
      -1,   705,    -1,    25,    -1,   993,    -1,   895,    -1,   977,
       5,   977,    -1,   978,    -1,   988,    -1,   703,   468,   988,
     429,    -1,   988,   656,   703,   468,   988,   429,    -1,   988,
     496,   721,   464,    -1,   988,   656,    20,    -1,   988,   496,
     721,   464,   656,    20,    -1,   988,   656,   988,    -1,   988,
     496,   721,   464,   656,   988,    -1,   989,    -1,   989,    -1,
     989,    -1,   989,    -1,   989,    -1,   989,    -1,    -1,   587,
      26,    -1,  1543,    -1,   990,    -1,  1543,    -1,   387,   468,
     991,   429,    -1,  1145,    -1,    25,    -1,   988,    -1,   988,
     496,   721,   464,    -1,   988,   656,    20,    -1,   988,   496,
     721,   464,   656,    20,    -1,   988,   656,   988,    -1,   988,
     496,   721,   464,   656,   988,    -1,  1142,    -1,    24,    -1,
     656,    26,    -1,   584,   996,    -1,   988,    -1,   626,   988,
      -1,   688,   998,    -1,   999,    -1,   998,     5,   999,    -1,
     988,    -1,   699,   998,    -1,   690,   998,    -1,   691,  1534,
      -1,   689,   985,   695,  1534,    -1,   693,   998,    -1,   694,
    1534,    -1,   692,   985,   695,  1534,    -1,    -1,   697,  1004,
     893,  1009,  1011,  1013,  1005,  1007,    -1,    -1,  1006,    -1,
     685,    -1,   686,    -1,    -1,  1008,    -1,   382,  1142,    -1,
      -1,  1010,    -1,   427,   893,    -1,    -1,  1012,    -1,   696,
      26,    -1,    -1,  1014,    -1,   687,    26,  1015,    -1,    -1,
     437,    26,    -1,    -1,    -1,   658,   895,   612,  1017,  1544,
    1018,  1019,   478,    -1,    -1,    -1,   579,  1020,  1544,    -1,
      -1,    -1,    98,  1021,   895,   612,  1022,  1544,  1019,    -1,
     144,   988,   468,    26,   429,    -1,    91,   988,    -1,   111,
     988,    -1,    -1,   328,  1173,  1026,   662,   520,    -1,   328,
    1173,   593,  1027,    -1,  1028,    -1,  1027,     5,  1028,    -1,
     835,   656,  1431,    -1,   835,   656,    20,    -1,    -1,  1031,
     362,    -1,   362,    -1,    -1,   189,    -1,  1032,    -1,  1031,
    1032,    -1,    -1,   308,  1044,  1033,  1544,    -1,    -1,   311,
    1045,  1034,  1544,    -1,    -1,   389,  1035,  1544,    -1,    -1,
     385,  1036,  1544,    -1,    -1,  1058,  1037,  1544,    -1,    -1,
     343,  1038,  1544,    -1,    -1,   313,  1039,  1544,    -1,    -1,
      40,  1040,  1544,    -1,    -1,    38,  1041,  1544,    -1,    -1,
      42,  1042,  1544,    -1,    -1,    41,  1043,  1544,    -1,   980,
      -1,  1044,     5,   980,    -1,   980,    -1,  1045,     5,   980,
      -1,   352,  1048,    -1,   353,   988,   695,  1048,    -1,   598,
      -1,   413,    -1,   980,    -1,    -1,   701,  1051,  1050,  1029,
      -1,   422,  1161,  1030,   987,   724,    -1,  1161,  1030,   583,
    1534,   987,   724,    -1,    -1,   524,  1168,  1030,   583,   988,
     656,    20,   987,  1052,   724,    -1,   506,  1534,  1054,    -1,
     117,    26,    -1,   118,    26,    -1,   663,    -1,   576,    -1,
      -1,   587,    26,    -1,  1057,    -1,    48,    25,    -1,   533,
      14,    26,    -1,   533,    14,  1142,    -1,    49,    14,    26,
      -1,    49,    14,  1142,    -1,    45,    -1,    47,    -1,    44,
      -1,    46,    -1,    -1,   467,  1059,  1064,    -1,   333,    -1,
      -1,   633,  1061,  1064,    -1,   341,  1066,    -1,   633,  1064,
      -1,  1066,    -1,   468,  1065,   429,    -1,  1066,    -1,  1065,
       5,  1066,    -1,  1067,    -1,   631,    -1,   350,    -1,   368,
      -1,   342,    -1,   522,    -1,   479,    -1,   663,    -1,   587,
      -1,   576,    -1,   215,    -1,   476,    -1,   487,    -1,   577,
      -1,   592,    -1,   557,    -1,   348,    -1,   349,    -1,    25,
      -1,   547,    -1,    -1,    -1,   635,  1070,  1166,  1071,    14,
     913,  1072,    -1,   520,    -1,   894,    -1,   257,  1142,    -1,
     246,  1142,    -1,   260,  1142,    -1,   488,  1142,   371,    -1,
     488,  1142,   423,   976,    -1,    -1,  1079,  1078,  1082,    -1,
      -1,  1080,    -1,  1081,    -1,  1080,  1081,    -1,  1024,    -1,
    1086,    -1,  1102,    -1,  1088,    -1,    -1,  1083,    -1,  1085,
      -1,  1083,  1085,    -1,   102,   988,    -1,  1090,    -1,  1096,
      -1,  1108,    -1,  1262,    -1,  1272,    -1,  1129,    -1,   948,
      -1,   771,    -1,  1023,    -1,   777,    -1,   771,    -1,    -1,
     771,    -1,   799,    -1,   405,    -1,    96,    -1,    -1,    -1,
      -1,    -1,  1089,  1091,   988,   468,  1092,  1159,   429,  1093,
     798,  1094,  1087,  1544,  1095,    -1,   248,    -1,    -1,    -1,
     594,  1097,   798,  1098,  1544,   399,    -1,   215,   890,    -1,
     913,    -1,   913,   893,    -1,   394,  1443,    -1,   504,  1443,
      -1,  1103,    -1,  1104,    -1,  1103,  1104,    -1,  1105,    -1,
    1086,    -1,  1101,    -1,    -1,   443,  1106,  1107,    -1,   798,
     280,    -1,   976,    -1,    -1,    -1,    -1,   151,   988,   150,
     988,   468,  1109,  1159,   429,  1110,   798,  1111,  1087,  1544,
    1095,    -1,    -1,   595,  1113,  1128,  1119,  1114,    -1,   400,
      -1,    -1,   272,  1116,  1544,    -1,    -1,    23,  1120,  1121,
    1122,   987,  1117,  1544,    -1,    -1,    23,  1120,   987,  1118,
    1544,    -1,  1115,    -1,  1119,  1115,    -1,    -1,  1060,    -1,
      25,    -1,  1142,    -1,    -1,  1142,    -1,    25,    -1,   289,
    1126,    -1,   301,  1127,    -1,   284,  1127,    -1,   622,    -1,
      25,    -1,  1142,    -1,  1126,    -1,  1127,     5,  1126,    -1,
    1142,    -1,    25,    -1,    -1,    -1,   682,   988,  1130,   798,
    1131,  1132,   683,    -1,  1133,    -1,  1132,  1133,    -1,    -1,
     684,  1134,  1544,    -1,    -1,   661,   988,  1135,  1544,    -1,
    1139,  1137,    -1,    -1,   725,  1140,    -1,  1141,    -1,  1138,
      -1,  1010,    -1,  1012,    -1,  1014,    -1,  1006,    -1,  1008,
      -1,   408,   913,   893,    -1,    -1,   101,    -1,   101,    -1,
    1143,    -1,  1145,    -1,   228,  1145,    -1,  1145,   656,    -1,
    1144,  1149,    -1,  1144,   988,   496,  1153,   464,    -1,  1144,
     988,   496,  1153,   464,   496,  1153,   464,    -1,  1150,    -1,
     988,    -1,  1146,    -1,   988,   495,  1148,   463,    -1,   988,
     495,  1148,   463,    -1,  1142,    -1,    25,    -1,    20,    -1,
     988,    -1,   988,  1152,    -1,   988,  1152,    -1,   496,  1153,
     464,    -1,   496,  1153,   464,   496,  1153,   464,    -1,  1154,
      -1,  1153,     5,  1154,    -1,   721,    -1,  1156,    -1,  1158,
      -1,  1156,   656,  1157,    -1,  1156,   656,   988,   496,  1153,
     464,    -1,  1156,   656,   988,   496,  1153,   464,   496,  1153,
     464,    -1,   988,    -1,  1147,    -1,    20,    -1,   988,    -1,
     988,  1152,    -1,    -1,  1160,    -1,  1162,    -1,  1160,     5,
    1162,    -1,  1163,    -1,  1161,     5,  1163,    -1,   988,    -1,
     988,   656,   988,    -1,  1142,    -1,  1142,   458,  1142,    -1,
      25,    -1,   994,    -1,    26,    -1,  1165,    -1,  1164,     5,
    1165,    -1,  1142,    -1,  1142,   458,  1142,    -1,  1167,    -1,
    1166,     5,  1167,    -1,  1155,    -1,  1142,    -1,  1170,    -1,
    1169,     5,  1170,    -1,  1142,  1171,    -1,    -1,   624,    -1,
     575,    -1,   988,   496,  1153,   464,    -1,  1174,    -1,  1173,
       5,  1174,    -1,  1142,    -1,  1142,   458,  1142,    -1,   292,
     984,   654,   978,   616,  1536,   729,    -1,    -1,   654,   468,
     895,     5,   895,   429,  1177,    -1,    -1,   605,   468,   895,
       5,   895,   429,    -1,   293,   988,  1176,    -1,   988,    -1,
     376,   986,  1181,    -1,  1182,    -1,   583,   895,    -1,  1183,
    1184,  1189,     8,  1179,    -1,    -1,   654,  1185,   468,   895,
       5,   895,   429,    -1,    -1,   593,   989,    -1,    -1,   388,
      -1,   255,  1485,   304,  1523,  1188,    -1,   600,   981,    -1,
     600,   981,     8,   913,   893,    -1,    -1,   653,   613,  1479,
     412,  1479,    -1,   653,   613,  1479,     5,   412,  1479,    -1,
     653,  1479,     5,  1479,    -1,    -1,   685,    -1,   686,    -1,
     126,  1523,  1191,  1192,    -1,    -1,   653,  1523,    -1,    -1,
     653,   613,  1479,     8,  1479,    -1,   613,  1479,     8,  1479,
      -1,   449,  1194,    -1,  1195,    -1,  1194,     5,  1195,    -1,
     241,   975,    -1,   322,   975,    -1,   367,   975,    -1,   375,
     975,    -1,   331,   975,    -1,   297,   975,    -1,  1062,    -1,
     476,  1063,    -1,   487,  1063,    -1,   598,  1063,    -1,   413,
    1063,    -1,   587,  1063,    -1,   585,   976,    -1,   586,   976,
      -1,   438,   725,    -1,   701,   725,    -1,   329,    -1,   233,
      -1,   190,    -1,   170,    -1,   187,    -1,   178,    -1,  1484,
     451,  1199,   583,  1197,    -1,  1142,    -1,    25,    -1,   440,
    1199,    -1,   440,  1199,     8,  1161,    -1,    43,  1197,    -1,
     989,    -1,    -1,   499,  1209,   724,   632,  1204,  1142,  1202,
     987,   724,  1201,  1205,    -1,    -1,   704,    26,    -1,   499,
    1209,   724,   382,  1142,    -1,    -1,   357,    -1,    -1,  1206,
     320,    -1,  1207,    -1,  1206,  1207,    -1,    -1,  1058,  1208,
    1544,    -1,   894,    -1,    -1,   640,   981,  1211,  1212,    -1,
      -1,   583,  1213,    -1,  1214,    -1,  1213,     5,  1214,    -1,
    1471,    -1,   520,    -1,   258,  1217,   124,    -1,   258,  1217,
     662,  1216,    -1,   258,  1217,   123,  1216,    -1,   258,  1217,
      -1,    25,    -1,   993,    -1,   988,    -1,    -1,   516,    -1,
     186,  1217,  1218,   468,   913,  1100,   429,    -1,   231,  1217,
      -1,   103,  1217,    -1,  1253,  1261,    -1,   484,    97,    -1,
     484,  1224,    -1,  1225,    -1,  1224,  1225,    -1,    -1,   174,
    1226,  1544,    -1,    -1,   237,  1227,  1544,    -1,    -1,   266,
    1228,  1544,    -1,    -1,   254,  1229,  1544,    -1,    -1,   291,
    1230,  1544,    -1,    -1,   239,  1142,  1231,  1544,    -1,    -1,
     262,  1142,  1232,  1544,    -1,  1243,    -1,  1245,    -1,  1244,
      -1,  1234,    -1,  1270,    -1,  1237,    -1,    -1,   597,   895,
    1235,   519,    -1,    -1,   519,    -1,    -1,   606,    26,  1238,
    1236,    -1,   197,    -1,   665,  1257,    -1,   200,  1257,    -1,
     199,  1257,    -1,    -1,  1240,    -1,  1241,    -1,  1240,  1241,
      -1,  1250,  1242,    -1,    -1,   654,  1257,    -1,   556,  1239,
    1249,    -1,   555,  1479,  1249,    -1,   554,  1248,  1247,  1246,
    1249,    -1,    -1,   191,   888,    -1,   191,   888,     5,   888,
      -1,   649,    -1,   650,    -1,   651,    -1,   652,    -1,  1142,
      -1,    -1,   559,    -1,  1251,    -1,  1250,     5,  1251,    -1,
     895,  1284,    -1,   645,   468,   888,   429,  1269,    -1,   100,
    1269,    -1,   533,   468,    20,   429,  1269,    -1,   450,   468,
      20,   429,  1269,    -1,   425,   468,   888,   429,  1269,    -1,
     625,   468,   888,   429,  1269,    -1,   638,   468,   888,   429,
    1269,    -1,   637,   468,   888,   429,  1269,    -1,    -1,   498,
    1254,    -1,  1255,    -1,  1254,  1255,    -1,   265,    26,    -1,
     256,    26,    -1,   339,    26,    -1,   222,    26,    -1,   294,
      26,    -1,   213,    -1,   381,    25,    -1,   381,  1142,    -1,
     214,    25,    -1,   198,    25,    -1,  1260,    -1,  1256,  1260,
      -1,  1258,   146,    -1,  1258,   148,    -1,  1258,   147,    -1,
    1258,    -1,   994,    -1,    26,    -1,    -1,   498,  1256,    -1,
     265,  1257,    -1,   256,  1257,    -1,   339,  1257,    -1,   222,
    1257,    -1,   294,  1257,    -1,   295,  1257,    -1,   664,    25,
      -1,   665,  1257,    -1,   669,    -1,   666,    -1,   667,    -1,
     668,    -1,   673,    -1,   670,    -1,   671,    -1,   672,    -1,
     112,  1257,    -1,   113,  1257,    -1,   114,  1257,    -1,   381,
      25,    -1,   214,    25,    -1,   437,    -1,   109,    -1,   110,
      -1,    -1,   551,   655,  1169,    -1,   175,  1169,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   502,  1263,   988,   468,  1264,
    1159,   429,  1265,   798,  1266,  1222,  1267,  1223,  1268,   277,
      -1,    -1,   563,   888,    -1,   553,  1271,    -1,    -1,  1197,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   143,  1273,   988,
     468,  1274,  1159,   429,  1275,   798,  1276,  1279,  1277,  1223,
    1278,   277,    -1,  1259,  1261,    -1,    -1,    -1,    -1,   193,
     468,    25,     5,  1281,   751,  1282,   429,  1283,   749,    -1,
      -1,   421,    -1,   421,   256,    26,    -1,   421,   256,  1142,
      -1,   643,   895,    -1,   643,   895,   382,  1142,    -1,   643,
     895,   201,    -1,   643,   895,   614,    -1,   643,   895,   581,
      -1,  1287,    -1,   210,    -1,   361,    -1,   319,    -1,  1294,
      -1,  1289,    -1,    -1,    -1,   244,  1290,  1427,   468,  1291,
    1298,   429,    -1,    -1,    -1,   172,  1292,  1427,   468,  1293,
    1298,   429,  1295,    -1,   141,  1428,   661,  1427,   468,  1296,
     429,    -1,    90,   989,    -1,    -1,   306,    -1,  1297,    -1,
    1296,     5,  1297,    -1,   988,   624,    -1,   988,   575,    -1,
     988,    -1,  1299,    -1,  1298,     5,  1299,    -1,  1380,    -1,
    1378,    -1,   158,   988,    -1,   217,    -1,    50,   988,  1302,
      -1,    51,  1428,   138,    -1,    51,  1428,   139,    -1,  1303,
      -1,  1302,     5,  1303,    -1,  1304,    -1,  1307,    -1,  1310,
      -1,  1315,    -1,  1316,    -1,  1314,    -1,  1313,    -1,   621,
    1305,    -1,   621,   468,  1306,   429,    -1,  1299,    -1,  1299,
     700,   988,    -1,  1305,    -1,  1306,     5,  1305,    -1,   578,
    1309,    -1,   578,   468,  1308,   429,    -1,  1309,    -1,  1308,
       5,  1309,    -1,   988,    -1,   492,  1312,    -1,   492,   468,
    1311,   429,    -1,  1312,    -1,  1311,     5,  1312,    -1,  1299,
      -1,   121,    -1,   122,    -1,   120,    26,    -1,    92,  1384,
      -1,    92,   468,  1317,   429,    -1,    93,  1318,    -1,    93,
     468,  1317,   429,    -1,  1384,    -1,  1317,     5,  1384,    -1,
     988,    -1,   303,    -1,   269,    -1,   203,  1321,    -1,   182,
      -1,   171,    -1,   157,    -1,   155,    -1,   159,    -1,   216,
    1485,    -1,   268,  1320,   497,  1479,   662,  1479,    -1,   336,
     981,   497,  1479,   662,  1479,    -1,    -1,  1485,    -1,    -1,
     895,    -1,   560,   895,    -1,   267,    -1,    -1,   286,  1325,
    1427,  1328,  1326,    -1,    -1,   516,  1327,   468,  1330,   429,
      -1,  1465,    -1,    -1,   468,  1329,   429,    -1,  1431,    -1,
    1329,     5,  1431,    -1,  1331,    -1,  1330,     5,  1331,    -1,
    1471,    -1,   520,    -1,    -1,    -1,   537,  1333,  1336,  1334,
    1337,    -1,   989,    -1,  1341,   982,    -1,   982,    -1,    -1,
      -1,   590,  1338,  1164,    -1,    -1,    -1,   590,  1340,  1164,
      -1,   538,    -1,   591,    -1,   598,    -1,   413,    -1,   379,
      -1,   433,    -1,   416,   895,    -1,   388,   895,    -1,   275,
    1427,   188,   982,    -1,   275,  1427,  1400,    -1,   551,   655,
    1345,    -1,  1346,    -1,  1345,     5,  1346,    -1,  1347,  1348,
      -1,    26,    -1,  1431,    -1,    -1,   624,    -1,   575,    -1,
     314,    -1,   347,    -1,    -1,   364,    -1,   394,  1353,  1351,
      -1,  1523,    -1,  1523,   648,   988,    -1,    25,    -1,    -1,
    1484,  1355,  1356,    -1,  1385,    -1,  1389,    -1,  1350,    -1,
    1486,    -1,  1349,    -1,  1342,    -1,  1343,    -1,  1332,    -1,
    1324,    -1,  1323,    -1,  1455,    -1,  1503,    -1,   542,  1359,
     661,  1427,   662,  1364,  1358,    -1,    -1,   181,    -1,   205,
      -1,  1360,    -1,  1361,    -1,  1360,     5,  1361,    -1,   508,
      -1,   487,    -1,   476,    -1,   515,  1362,    -1,    -1,   468,
    1363,   429,    -1,  1431,    -1,  1363,     5,  1431,    -1,  1365,
      -1,  1364,     5,  1365,    -1,   500,    -1,  1429,    -1,   273,
    1427,  1367,   653,  1465,  1369,    -1,    -1,   468,  1368,   429,
      -1,  1431,    -1,  1368,     5,  1431,    -1,    -1,   180,    -1,
     529,   468,  1403,   429,    -1,   283,   468,  1373,   429,  1372,
      -1,   334,  1374,    -1,  1375,    -1,  1427,    -1,  1427,   468,
    1375,   429,    -1,  1431,    -1,  1375,     5,  1431,    -1,   513,
     468,  1377,   429,    -1,   296,   468,  1377,   429,    -1,  1431,
      -1,  1377,     5,  1431,    -1,  1376,    -1,  1371,    -1,  1370,
      -1,   437,  1434,    -1,   245,    -1,   988,  1419,  1381,  1382,
      -1,    -1,  1379,    -1,    -1,  1383,    -1,  1384,    -1,  1383,
    1384,    -1,   411,    -1,   196,    -1,   513,    -1,  1372,    -1,
     529,   468,  1403,   429,    -1,   156,  1386,  1388,    -1,  1387,
      -1,  1429,    -1,  1389,    -1,  1388,  1389,    -1,  1366,    -1,
    1357,    -1,   485,  1403,    -1,   406,  1392,    -1,  1470,    -1,
    1392,     5,  1470,    -1,   563,  1403,    -1,   583,  1395,    -1,
    1396,    -1,  1395,     5,  1396,    -1,  1397,    -1,   552,  1397,
      -1,   552,   468,  1398,   429,    -1,  1427,    -1,  1427,  1433,
      -1,  1396,    -1,  1398,     5,  1396,    -1,  1394,  1400,  1401,
    1402,    -1,    -1,  1393,    -1,    -1,  1391,    -1,    -1,  1390,
      -1,  1404,    -1,  1403,     6,  1404,    -1,  1405,    -1,  1404,
       7,  1405,    -1,  1406,    -1,     9,  1406,    -1,  1417,    -1,
     468,  1403,   429,    -1,   480,  1466,    -1,   332,  1466,    -1,
      -1,   479,  1410,    -1,  1472,    -1,  1475,    -1,  1471,   659,
     468,  1412,   429,    -1,  1471,   659,  1466,    -1,  1471,   466,
     468,  1412,   429,    -1,  1471,   466,  1466,    -1,  1413,    -1,
    1412,     5,  1413,    -1,  1527,    -1,  1434,    -1,    -1,     9,
      -1,  1471,  1414,   424,    -1,  1471,  1414,   287,    -1,  1471,
    1416,  1471,    -1,  1471,  1414,   426,  1471,     7,  1471,    -1,
    1471,   593,  1409,  1408,    -1,  1471,   409,  1409,  1408,    -1,
    1471,   710,  1409,  1408,    -1,  1471,   410,  1409,  1408,    -1,
    1471,  1414,    10,  1409,  1408,    -1,    14,    -1,    17,    -1,
      12,    -1,    13,    -1,   290,    -1,    10,    -1,   709,    -1,
      16,    -1,    15,    -1,  1415,    -1,  1411,    -1,  1407,    -1,
      -1,   622,    -1,   397,    -1,   513,    -1,  1420,    -1,  1421,
      -1,  1423,    -1,   357,    -1,   357,   468,  1424,   429,    -1,
     448,   468,  1425,  1422,   429,    -1,   509,    -1,   435,   468,
    1425,  1422,   429,    -1,   549,   468,  1425,  1422,   429,    -1,
     574,    -1,   445,    -1,   418,    -1,   395,  1441,   662,  1442,
      -1,   395,    -1,   407,  1441,   662,  1442,    -1,   407,    -1,
     407,  1441,   468,    26,   429,   662,  1442,    -1,   611,    -1,
     570,    -1,   461,    -1,   461,   468,    26,   429,    -1,   461,
     468,    26,     5,    26,   429,    -1,    -1,     5,  1426,    -1,
     539,   468,  1425,   429,    -1,   602,    -1,   337,    -1,   539,
      -1,    99,    -1,    26,    -1,    26,    -1,    26,    -1,    25,
     656,   988,    -1,    25,    -1,   988,    -1,   988,   626,   988,
      -1,    25,   656,   988,    -1,    25,    -1,   988,    -1,   988,
     626,   988,    -1,   988,    -1,    -1,   496,    26,   464,    -1,
     496,    26,     5,    26,   464,    -1,  1432,    -1,   648,  1432,
      -1,   988,  1430,    -1,  1427,   656,   988,  1430,    -1,  1427,
     656,    20,    -1,   988,    -1,    25,    -1,   448,    -1,   994,
      -1,    26,    -1,  1436,    -1,   433,  1438,    -1,   433,  1437,
      -1,    -1,  1441,   662,  1442,    -1,    -1,  1439,   662,  1439,
      -1,   618,    -1,   550,    -1,   627,    -1,   589,    -1,   491,
      -1,   507,    -1,   404,    -1,   404,   468,    26,   429,    -1,
     618,    -1,   550,    -1,   627,    -1,   589,    -1,   491,    -1,
     507,    -1,   404,    -1,   404,   468,    26,   429,    -1,   618,
      -1,   550,    -1,   627,    -1,   589,    -1,   491,    -1,   507,
      -1,   404,    -1,   618,    -1,   550,    -1,   627,    -1,   589,
      -1,   491,    -1,   507,    -1,   404,    -1,   404,   468,    26,
     429,    -1,   988,    -1,   988,   648,   988,    -1,    25,    -1,
    1484,   540,   982,    -1,    -1,  1484,   436,  1335,   474,   632,
    1453,  1446,    -1,    -1,  1484,   436,  1335,   474,   136,   632,
    1454,  1447,    -1,    -1,  1484,   436,  1335,   176,  1454,  1448,
      -1,    -1,  1484,   436,  1335,   177,   136,   632,  1454,  1449,
      -1,    -1,   326,    -1,   325,  1451,    -1,  1452,    -1,  1451,
       5,  1452,    -1,   988,    -1,   988,   656,   988,    -1,    25,
     656,   988,   656,   988,    -1,  1454,    -1,  1324,    -1,  1199,
      -1,  1456,    -1,  1456,    -1,    -1,    -1,   508,  1467,  1457,
    1468,  1458,  1464,  1399,  1462,  1450,    -1,   508,  1467,  1468,
    1399,  1462,    -1,  1461,    -1,  1479,    -1,   508,  1467,  1468,
    1464,  1399,  1462,    -1,    -1,   562,  1418,  1460,    -1,  1344,
      -1,   369,  1463,  1295,    -1,  1344,   369,  1463,  1295,    -1,
     988,    -1,    -1,   590,  1164,    -1,   508,  1467,  1468,  1399,
      -1,   468,   508,  1467,  1468,  1399,   429,    -1,    -1,   622,
      -1,   397,    -1,   513,    -1,  1469,    -1,  1468,     5,  1469,
      -1,  1471,    -1,  1471,   988,    -1,  1471,    -1,  1472,    -1,
      19,  1472,    -1,    18,  1472,    -1,  1473,    -1,  1527,    -1,
    1466,    -1,   648,   988,    -1,   648,   988,   656,   988,    -1,
    1472,    21,  1471,    -1,  1472,  1493,    -1,  1472,    20,  1471,
      -1,  1472,    18,  1471,    -1,  1472,    19,  1471,    -1,  1434,
      -1,   521,    -1,   465,    -1,   613,    -1,    20,    -1,   100,
      -1,   625,   468,  1418,  1471,   429,    -1,   637,   468,  1418,
    1471,   429,    -1,   638,   468,  1418,  1471,   429,    -1,   645,
     468,  1418,  1471,   429,    -1,   533,   468,  1418,  1471,   429,
      -1,   988,   468,  1474,   429,    -1,   574,   468,  1474,   429,
      -1,   468,  1471,   429,    -1,   481,   468,  1494,   429,    -1,
    1471,    -1,  1474,     5,  1471,    -1,  1434,    -1,  1484,   384,
    1483,  1478,  1460,    -1,  1484,   373,  1483,  1478,   286,  1427,
    1480,    -1,  1484,   373,  1483,  1478,  1142,    -1,    -1,   359,
    1479,    -1,    25,    -1,  1142,    -1,    -1,   468,  1481,   429,
      -1,  1482,    -1,  1481,     5,  1482,    -1,   988,    -1,    25,
      -1,  1142,    -1,    -1,   305,  1485,   632,    -1,   989,    -1,
    1491,    -1,  1490,    -1,  1487,    -1,   354,  1488,   662,  1488,
      -1,   335,  1488,   656,  1489,   662,  1489,    -1,   988,    -1,
     988,    -1,   259,   835,    -1,   330,   835,  1492,    -1,   309,
      -1,   212,    -1,   128,    -1,   129,    -1,   130,    -1,   131,
      -1,   132,    -1,   133,    -1,   433,     5,  1441,   662,  1442,
      -1,  1527,     5,  1441,   662,  1442,    -1,   433,  1441,   662,
    1442,    -1,    -1,   644,  1496,  1497,   227,    -1,  1498,    -1,
    1497,  1498,    -1,    33,    -1,  1499,    -1,  1501,    -1,   388,
      -1,   342,    -1,   261,    -1,   621,    -1,   518,    -1,   622,
      -1,   523,    -1,   567,    -1,   623,    -1,   152,    -1,   524,
      -1,   653,    -1,   624,    -1,   355,    -1,   525,    -1,   356,
      -1,   654,    -1,   648,    -1,   312,    -1,   526,    -1,   221,
      -1,   425,    -1,   625,    -1,   700,    -1,   426,    -1,   527,
      -1,   528,    -1,   568,    -1,   569,    -1,   469,    -1,   470,
      -1,   390,    -1,   687,    -1,   655,    -1,   570,    -1,   427,
      -1,   572,    -1,   566,    -1,   357,    -1,   529,    -1,   530,
      -1,   428,    -1,   531,    -1,   429,    -1,   464,    -1,   532,
      -1,   626,    -1,   471,    -1,   430,    -1,     5,    -1,    23,
      -1,   431,    -1,   472,    -1,   432,    -1,   392,    -1,   391,
      -1,   358,    -1,   533,    -1,   473,    -1,   433,    -1,   474,
      -1,   573,    -1,   394,    -1,   574,    -1,   395,    -1,   627,
      -1,   628,    -1,   434,    -1,   629,    -1,   435,    -1,   436,
      -1,   437,    -1,   396,    -1,   534,    -1,   475,    -1,   476,
      -1,   359,    -1,   575,    -1,   318,    -1,   630,    -1,   691,
      -1,   438,    -1,   397,    -1,    21,    -1,   656,    -1,   477,
      -1,   360,    -1,   578,    -1,    98,    -1,   579,    -1,   694,
      -1,   439,    -1,    14,    -1,   535,    -1,   479,    -1,   536,
      -1,   364,    -1,   580,    -1,   440,    -1,   480,    -1,   581,
      -1,   481,    -1,   482,    -1,   403,    -1,   571,    -1,   537,
      -1,   135,    -1,   230,    -1,   483,    -1,   538,    -1,   631,
      -1,   539,    -1,   540,    -1,   632,    -1,   441,    -1,   442,
      -1,   484,    -1,   674,    -1,   127,    -1,   142,    -1,   541,
      -1,   404,    -1,   582,    -1,   583,    -1,   405,    -1,   327,
      -1,   443,    -1,   657,    -1,   584,    -1,   542,    -1,    13,
      -1,   543,    -1,   544,    -1,   485,    -1,   486,    -1,   587,
      -1,   588,    -1,   589,    -1,   696,    -1,   107,    -1,   658,
      -1,   659,    -1,   148,    -1,   545,    -1,   444,    -1,   328,
      -1,   701,    -1,   487,    -1,   445,    -1,   368,    -1,   407,
      -1,   703,    -1,   370,    -1,   633,    -1,   576,    -1,   695,
      -1,   546,    -1,   519,    -1,   408,    -1,   634,    -1,   663,
      -1,   446,    -1,     7,    -1,   465,    -1,   619,    -1,   520,
      -1,     6,    -1,   521,    -1,     8,    -1,   591,    -1,   592,
      -1,    12,    -1,   635,    -1,   593,    -1,   548,    -1,   488,
      -1,   636,    -1,   447,    -1,   594,    -1,   489,    -1,    10,
      -1,    49,    -1,   490,    -1,   595,    -1,   682,    -1,   697,
      -1,    19,    -1,   491,    -1,   147,    -1,    22,    -1,   596,
      -1,   492,    -1,   549,    -1,   550,    -1,    20,    -1,   597,
      -1,   598,    -1,   348,    -1,   599,    -1,   493,    -1,     9,
      -1,   448,    -1,   660,    -1,   705,    -1,   661,    -1,   600,
      -1,   468,    -1,   496,    -1,   497,    -1,   449,    -1,   551,
      -1,   377,    -1,   552,    -1,   498,    -1,   639,    -1,   412,
      -1,   553,    -1,   193,    -1,   143,    -1,   450,    -1,    18,
      -1,   146,    -1,   378,    -1,   451,    -1,   149,    -1,   413,
      -1,   349,    -1,   556,    -1,   379,    -1,   380,    -1,   452,
      -1,   499,    -1,   500,    -1,   640,    -1,   601,    -1,   414,
      -1,   602,    -1,   501,    -1,   453,    -1,   641,    -1,   334,
      -1,   415,    -1,   416,    -1,   502,    -1,   417,    -1,   215,
      -1,   382,    -1,   454,    -1,   503,    -1,   557,    -1,   299,
      -1,   642,    -1,   603,    -1,   643,    -1,   504,    -1,   506,
      -1,   507,    -1,   455,    -1,   508,    -1,   559,    -1,   509,
      -1,   456,    -1,   511,    -1,   604,    -1,   522,    -1,   605,
      -1,   606,    -1,   560,    -1,   337,    -1,   418,    -1,   607,
      -1,   512,    -1,   644,    -1,   338,    -1,   125,    -1,   608,
      -1,   609,    -1,   645,    -1,   457,    -1,   577,    -1,   610,
      -1,   153,    -1,   611,    -1,   612,    -1,   458,    -1,   704,
      -1,   662,    -1,   646,    -1,   459,    -1,   561,    -1,   236,
      -1,   383,    -1,   562,    -1,   513,    -1,   514,    -1,   515,
      -1,   460,    -1,   647,    -1,   613,    -1,   419,    -1,   516,
      -1,   461,    -1,   387,    -1,   614,    -1,   462,    -1,   615,
      -1,   563,    -1,   564,    -1,   565,    -1,   616,    -1,   421,
      -1,   617,    -1,   637,    -1,   638,    -1,   620,    -1,   618,
      -1,   517,    -1,    -1,   228,  1500,  1527,    -1,    -1,   590,
    1502,  1164,    -1,    -1,    -1,   515,  1427,  1504,  1507,  1505,
    1506,    -1,    -1,   188,   982,    -1,   563,  1403,    -1,    88,
    1511,   429,    14,   468,  1512,   429,    -1,    84,  1512,   429,
      -1,    85,  1512,   429,    -1,   620,  1508,    -1,    87,  1512,
      -1,    86,  1512,    -1,  1510,    -1,  1508,     5,  1510,    -1,
    1431,    -1,  1509,    14,  1513,    -1,  1509,    -1,  1511,     5,
    1509,    -1,  1513,    -1,  1512,     5,  1513,    -1,   520,    -1,
    1514,    -1,  1515,    -1,    19,  1515,    -1,    18,  1515,    -1,
    1517,    -1,  1466,    -1,   648,   988,    -1,   648,   988,   656,
     988,    -1,  1516,    -1,  1434,    -1,   521,    -1,   465,    -1,
     613,    -1,   100,    -1,  1515,    21,  1514,    -1,  1515,  1493,
      -1,  1515,    20,  1514,    -1,  1515,    18,  1514,    -1,  1515,
      19,  1514,    -1,   625,   468,  1418,  1514,   429,    -1,   637,
     468,  1418,  1514,   429,    -1,   638,   468,  1418,  1514,   429,
      -1,   645,   468,  1418,  1514,   429,    -1,   533,   468,  1418,
    1514,   429,    -1,   988,   468,  1518,   429,    -1,   574,   468,
    1518,   429,    -1,   468,  1514,   429,    -1,   481,   468,  1494,
     429,    -1,  1527,    -1,  1514,    -1,  1518,     5,  1514,    -1,
      -1,   419,  1173,   593,  1520,  1521,    -1,  1522,    -1,  1521,
       5,  1522,    -1,   835,   656,  1431,    -1,   835,   656,    20,
      -1,  1524,    -1,   228,  1525,    -1,  1525,    -1,  1151,    -1,
     988,    -1,  1525,   656,  1526,    -1,    25,   656,  1525,   656,
    1526,    -1,    20,    -1,  1172,    -1,   988,    -1,  1524,    -1,
    1524,   458,  1524,    -1,    -1,    -1,   564,  1529,   895,  1530,
    1544,   363,    -1,    -1,   695,  1534,    -1,    -1,   698,    -1,
     219,    -1,   315,   983,    -1,   105,   983,    -1,   345,    -1,
     344,    -1,   346,   985,  1531,  1532,    -1,   530,  1534,  1532,
      -1,   938,    -1,   140,    -1,   173,   983,    -1,   895,   603,
       5,   895,   430,    -1,   546,   895,    -1,   302,   983,    -1,
     137,  1539,     8,  1540,  1538,    -1,    -1,   583,   895,    -1,
     988,    -1,   988,    -1,   285,   983,    -1,   288,   983,   662,
     895,     5,   895,    -1,   288,   983,   655,   895,     5,   895,
      -1,    27,    -1,    -1,  1546,    -1,  1547,  1249,    -1,  1545,
      -1,  1546,  1545,    -1,    -1,  1548,  1549,    -1,   714,    -1,
     715,    -1,   716,    -1,   717,    -1,   734,    -1,   756,    -1,
     770,    -1,   771,    -1,   777,    -1,   778,    -1,   797,    -1,
     867,    -1,   868,    -1,   869,    -1,   870,    -1,   881,    -1,
     882,    -1,   883,    -1,   884,    -1,   885,    -1,   886,    -1,
     887,    -1,   939,    -1,   943,    -1,   974,    -1,   995,    -1,
     997,    -1,  1000,    -1,  1001,    -1,  1002,    -1,  1003,    -1,
    1016,    -1,  1025,    -1,  1046,    -1,  1047,    -1,  1049,    -1,
    1053,    -1,  1068,    -1,  1069,    -1,  1073,    -1,  1074,    -1,
    1075,    -1,  1076,    -1,  1084,    -1,  1099,    -1,  1112,    -1,
    1123,    -1,  1124,    -1,  1125,    -1,  1136,    -1,  1175,    -1,
    1178,    -1,  1180,    -1,  1186,    -1,  1187,    -1,  1190,    -1,
    1193,    -1,  1196,    -1,  1198,    -1,  1200,    -1,  1203,    -1,
    1210,    -1,  1215,    -1,  1219,    -1,  1220,    -1,  1221,    -1,
    1233,    -1,  1285,    -1,  1286,    -1,  1288,    -1,  1300,    -1,
    1301,    -1,  1319,    -1,  1322,    -1,  1352,    -1,  1354,    -1,
    1444,    -1,  1445,    -1,  1476,    -1,  1477,    -1,  1495,    -1,
    1519,    -1,  1528,    -1,  1533,    -1,  1535,    -1,  1537,    -1,
    1541,    -1,  1542,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const unsigned short yyrline[] =
{
       0,   980,   980,   983,   986,   992,   998,  1005,  1009,  1009,
    1015,  1038,  1039,  1040,  1041,  1042,  1053,  1059,  1060,  1061,
    1062,  1063,  1068,  1069,  1080,  1083,  1086,  1086,  1090,  1093,
    1094,  1100,  1101,  1102,  1103,  1104,  1105,  1106,  1107,  1108,
    1109,  1110,  1111,  1112,  1113,  1114,  1115,  1116,  1119,  1120,
    1123,  1123,  1138,  1139,  1142,  1148,  1150,  1161,  1163,  1165,
    1167,  1171,  1173,  1235,  1239,  1243,  1243,  1253,  1257,  1260,
    1261,  1268,  1274,  1268,  1287,  1292,  1296,  1287,  1308,  1312,
    1308,  1320,  1325,  1320,  1344,  1351,  1355,  1343,  1381,  1381,
    1385,  1386,  1387,  1392,  1395,  1400,  1404,  1412,  1415,  1415,
    1421,  1425,  1440,  1438,  1456,  1456,  1471,  1471,  1474,  1474,
    1478,  1481,  1481,  1481,  1488,  1489,  1488,  1496,  1496,  1507,
    1507,  1526,  1529,  1532,  1535,  1538,  1541,  1554,  1559,  1559,
    1560,  1560,  1563,  1568,  1568,  1572,  1582,  1596,  1601,  1595,
    1612,  1618,  1626,  1627,  1630,  1630,  1633,  1637,  1642,  1649,
    1649,  1653,  1653,  1654,  1654,  1655,  1655,  1656,  1656,  1657,
    1657,  1665,  1669,  1675,  1679,  1694,  1697,  1700,  1703,  1706,
    1709,  1715,  1726,  1731,  1744,  1748,  1763,  1764,  1768,  1768,
    1772,  1772,  1772,  1773,  1778,  1778,  1781,  1781,  1790,  1791,
    1792,  1795,  1799,  1800,  1800,  1817,  1817,  1817,  1817,  1821,
    1828,  1829,  1832,  1832,  1836,  1837,  1838,  1839,  1844,  1844,
    1850,  1850,  1859,  1856,  1872,  1872,  1874,  1874,  1876,  1878,
    1880,  1882,  1885,  1889,  1889,  1890,  1890,  1894,  1894,  1906,
    1906,  1911,  1915,  1917,  1918,  1921,  1921,  1921,  1925,  1926,
    1927,  1928,  1935,  1936,  1937,  1938,  1941,  1942,  1943,  1944,
    1948,  1953,  1958,  1962,  1965,  1969,  1970,  1971,  1972,  1973,
    1974,  1975,  1976,  1979,  1980,  1981,  2013,  2017,  2019,  2021,
    2021,  2028,  2032,  2032,  2036,  2037,  2038,  2039,  2040,  2041,
    2042,  2048,  2048,  2051,  2053,  2059,  2061,  2067,  2075,  2075,
    2078,  2079,  2080,  2081,  2082,  2083,  2084,  2090,  2093,  2093,
    2106,  2106,  2113,  2114,  2115,  2117,  2118,  2120,  2122,  2123,
    2124,  2125,  2130,  2136,  2142,  2143,  2145,  2147,  2148,  2149,
    2150,  2151,  2152,  2155,  2156,  2163,  2171,  2171,  2179,  2176,
    2191,  2191,  2193,  2193,  2201,  2201,  2204,  2207,  2208,  2213,
    2225,  2229,  2232,  2235,  2236,  2237,  2238,  2239,  2244,  2251,
    2257,  2262,  2267,  2262,  2280,  2282,  2287,  2292,  2292,  2292,
    2296,  2296,  2299,  2299,  2306,  2306,  2313,  2313,  2324,  2342,
    2348,  2372,  2375,  2389,  2391,  2393,  2395,  2397,  2399,  2401,
    2407,  2409,  2413,  2415,  2417,  2419,  2421,  2423,  2425,  2431,
    2446,  2449,  2462,  2463,  2464,  2465,  2466,  2470,  2471,  2472,
    2476,  2481,  2488,  2489,  2490,  2491,  2492,  2493,  2494,  2495,
    2496,  2497,  2498,  2505,  2505,  2510,  2510,  2513,  2519,  2527,
    2533,  2543,  2544,  2552,  2559,  2563,  2573,  2577,  2582,  2587,
    2589,  2592,  2598,  2606,  2619,  2624,  2630,  2635,  2640,  2641,
    2647,  2718,  2724,  2729,  2737,  2737,  2752,  2756,  2763,  2766,
    2774,  2778,  2781,  2787,  2796,  2801,  2809,  2812,  2815,  2820,
    2827,  2832,  2837,  2842,  2852,  2860,  2868,  2873,  2877,  2882,
    2886,  2890,  2897,  2900,  2903,  2907,  2911,  2915,  2919,  2927,
    2937,  2942,  2935,  2958,  2963,  2958,  2980,  2980,  2980,  2983,
    2983,  2983,  2987,  2987,  2987,  2991,  2991,  2991,  2995,  3001,
    3007,  3013,  3019,  3025,  3035,  3035,  3039,  3043,  3044,  3055,
    3056,  3062,  3072,  3082,  3092,  3093,  3096,  3101,  3107,  3111,
    3115,  3118,  3124,  3127,  3130,  3147,  3150,  3156,  3157,  3158,
    3162,  3163,  3164,  3165,  3166,  3168,  3169,  3170,  3172,  3173,
    3177,  3178,  3183,  3187,  3202,  3206,  3201,  3214,  3217,  3231,
    3235,  3241,  3230,  3254,  3255,  3267,  3273,  3267,  3287,  3287,
    3289,  3290,  3294,  3294,  3298,  3298,  3303,  3303,  3310,  3311,
    3315,  3315,  3319,  3319,  3324,  3324,  3331,  3335,  3336,  3337,
    3342,  3342,  3345,  3345,  3349,  3349,  3353,  3353,  3357,  3357,
    3362,  3362,  3367,  3367,  3372,  3372,  3377,  3377,  3393,  3410,
    3411,  3412,  3413,  3414,  3415,  3416,  3419,  3419,  3422,  3424,
    3427,  3430,  3433,  3438,  3443,  3446,  3451,  3456,  3461,  3468,
    3475,  3477,  3483,  3488,  3493,  3498,  3498,  3501,  3507,  3512,
    3515,  3522,  3522,  3524,  3527,  3530,  3535,  3540,  3545,  3552,
    3561,  3561,  3623,  3628,  3629,  3637,  3644,  3644,  3648,  3653,
    3659,  3663,  3667,  3673,  3677,  3681,  3687,  3687,  3695,  3696,
    3700,  3700,  3704,  3705,  3708,  3711,  3711,  3714,  3716,  3716,
    3719,  3721,  3721,  3722,  3724,  3724,  3733,  3740,  3731,  3761,
    3761,  3761,  3764,  3766,  3764,  3773,  3776,  3782,  3793,  3793,
    3797,  3803,  3803,  3807,  3808,  3819,  3820,  3821,  3824,  3826,
    3831,  3831,  3835,  3834,  3842,  3841,  3848,  3848,  3854,  3854,
    3861,  3861,  3867,  3867,  3873,  3873,  3879,  3879,  3883,  3883,
    3887,  3887,  3891,  3891,  3902,  3906,  3912,  3916,  3921,  3926,
    3931,  3932,  3933,  3937,  3936,  3949,  3954,  3959,  3959,  3975,
    3981,  3982,  3983,  3984,  3987,  3987,  3990,  3997,  3998,  3999,
    4000,  4001,  4002,  4003,  4004,  4005,  4010,  4010,  4012,  4015,
    4015,  4017,  4021,  4024,  4025,  4028,  4028,  4033,  4036,  4037,
    4038,  4039,  4040,  4041,  4042,  4043,  4044,  4045,  4046,  4047,
    4048,  4049,  4050,  4051,  4052,  4053,  4057,  4075,  4075,  4075,
    4102,  4113,  4120,  4126,  4132,  4138,  4149,  4172,  4171,  4188,
    4188,  4192,  4193,  4201,  4202,  4203,  4204,  4211,  4212,  4214,
    4215,  4219,  4224,  4225,  4226,  4227,  4228,  4229,  4230,  4231,
    4232,  4233,  4236,  4238,  4238,  4240,  4244,  4244,  4253,  4258,
    4274,  4280,  4252,  4294,  4308,  4318,  4307,  4331,  4338,  4338,
    4343,  4349,  4357,  4362,  4363,  4366,  4366,  4366,  4369,  4369,
    4377,  4383,  4397,  4401,  4414,  4396,  4432,  4432,  4446,  4457,
    4456,  4468,  4464,  4481,  4478,  4491,  4491,  4493,  4494,  4496,
    4497,  4500,  4501,  4502,  4504,  4509,  4514,  4520,  4522,  4523,
    4526,  4527,  4530,  4532,  4541,  4547,  4541,  4558,  4559,  4563,
    4563,  4573,  4573,  4585,  4588,  4591,  4594,  4598,  4602,  4603,
    4604,  4605,  4606,  4610,  4615,  4615,  4618,  4644,  4702,  4702,
    4705,  4709,  4713,  4756,  4798,  4799,  4800,  4803,  4817,  4829,
    4829,  4834,  4835,  4841,  4901,  4958,  4963,  4970,  4975,  4983,
    4989,  5022,  5025,  5026,  5067,  5110,  5111,  5115,  5116,  5120,
    5173,  5177,  5180,  5186,  5197,  5204,  5212,  5212,  5215,  5216,
    5217,  5218,  5219,  5222,  5225,  5231,  5234,  5238,  5243,  5251,
    5256,  5263,  5266,  5272,  5274,  5274,  5274,  5278,  5298,  5305,
    5312,  5315,  5329,  5336,  5337,  5340,  5341,  5345,  5351,  5356,
    5362,  5363,  5368,  5372,  5372,  5376,  5377,  5380,  5381,  5385,
    5393,  5396,  5402,  5403,  5405,  5407,  5411,  5411,  5412,  5417,
    5425,  5426,  5431,  5432,  5434,  5447,  5449,  5450,  5452,  5455,
    5458,  5461,  5465,  5468,  5471,  5475,  5479,  5483,  5486,  5490,
    5493,  5494,  5495,  5498,  5501,  5504,  5507,  5510,  5513,  5516,
    5532,  5540,  5540,  5542,  5549,  5553,  5558,  5573,  5571,  5591,
    5592,  5596,  5601,  5602,  5606,  5607,  5609,  5610,  5612,  5612,
    5621,  5630,  5630,  5640,  5641,  5646,  5647,  5650,  5663,  5677,
    5682,  5687,  5692,  5702,  5702,  5706,  5709,  5709,  5711,  5721,
    5730,  5737,  5739,  5743,  5746,  5746,  5750,  5749,  5757,  5756,
    5767,  5766,  5773,  5772,  5776,  5775,  5778,  5778,  5794,  5793,
    5815,  5816,  5817,  5818,  5819,  5820,  5823,  5823,  5829,  5829,
    5832,  5832,  5848,  5849,  5850,  5859,  5871,  5872,  5875,  5876,
    5879,  5882,  5882,  5887,  5907,  5912,  5918,  5919,  5920,  5924,
    5925,  5926,  5927,  5931,  5941,  5943,  5948,  5951,  5956,  5962,
    5969,  5976,  5985,  5992,  5999,  6006,  6013,  6022,  6022,  6024,
    6024,  6027,  6028,  6029,  6030,  6031,  6032,  6033,  6034,  6035,
    6036,  6039,  6039,  6042,  6043,  6044,  6045,  6048,  6048,  6051,
    6051,  6054,  6055,  6056,  6057,  6058,  6059,  6060,  6061,  6063,
    6064,  6065,  6066,  6068,  6069,  6070,  6071,  6073,  6074,  6075,
    6076,  6077,  6078,  6079,  6080,  6084,  6091,  6100,  6112,  6121,
    6132,  6136,  6140,  6146,  6111,  6159,  6162,  6170,  6182,  6184,
    6189,  6197,  6207,  6210,  6214,  6222,  6188,  6231,  6235,  6239,
    6243,  6235,  6253,  6254,  6255,  6256,  6261,  6263,  6266,  6270,
    6273,  6280,  6285,  6286,  6287,  6292,  6293,  6299,  6299,  6299,
    6304,  6304,  6304,  6315,  6316,  6322,  6323,  6335,  6336,  6341,
    6342,  6343,  6347,  6350,  6356,  6359,  6367,  6368,  6374,  6378,
    6382,  6388,  6391,  6400,  6403,  6406,  6409,  6412,  6415,  6418,
    6425,  6428,  6435,  6438,  6444,  6447,  6454,  6457,  6464,  6465,
    6470,  6474,  6477,  6483,  6486,  6492,  6499,  6500,  6504,  6510,
    6513,  6520,  6521,  6528,  6531,  6536,  6547,  6548,  6549,  6550,
    6551,  6552,  6553,  6554,  6555,  6558,  6561,  6567,  6567,  6573,
    6573,  6584,  6597,  6607,  6607,  6612,  6612,  6616,  6620,  6621,
    6627,  6628,  6633,  6637,  6644,  6647,  6654,  6658,  6653,  6667,
    6671,  6675,  6682,  6686,  6686,  6699,  6703,  6703,  6718,  6720,
    6722,  6724,  6726,  6728,  6730,  6732,  6738,  6748,  6755,  6760,
    6761,  6765,  6768,  6769,  6772,  6773,  6774,  6777,  6782,  6789,
    6790,  6796,  6808,  6809,  6810,  6813,  6813,  6818,  6823,  6828,
    6829,  6832,  6833,  6838,  6843,  6847,  6852,  6853,  6857,  6864,
    6868,  6869,  6874,  6876,  6880,  6881,  6885,  6886,  6887,  6888,
    6892,  6893,  6898,  6899,  6904,  6905,  6910,  6911,  6916,  6921,
    6922,  6927,  6928,  6932,  6933,  6938,  6945,  6950,  6955,  6959,
    6960,  6965,  6966,  6972,  6974,  6979,  6980,  6986,  6989,  6992,
    6999,  7001,  7015,  7020,  7021,  7024,  7026,  7033,  7036,  7042,
    7046,  7050,  7054,  7057,  7064,  7071,  7076,  7080,  7081,  7087,
    7090,  7101,  7108,  7114,  7117,  7124,  7131,  7137,  7138,  7144,
    7145,  7146,  7149,  7150,  7155,  7155,  7159,  7167,  7168,  7171,
    7174,  7179,  7180,  7185,  7188,  7194,  7197,  7203,  7206,  7212,
    7215,  7222,  7223,  7252,  7253,  7258,  7266,  7271,  7274,  7277,
    7280,  7286,  7287,  7291,  7294,  7297,  7298,  7303,  7306,  7309,
    7312,  7315,  7318,  7321,  7324,  7329,  7335,  7336,  7337,  7338,
    7339,  7341,  7342,  7344,  7345,  7350,  7353,  7357,  7363,  7364,
    7365,  7366,  7378,  7379,  7380,  7384,  7385,  7390,  7392,  7393,
    7394,  7396,  7397,  7398,  7399,  7401,  7402,  7404,  7405,  7407,
    7408,  7409,  7410,  7412,  7416,  7417,  7423,  7425,  7426,  7427,
    7428,  7433,  7437,  7441,  7445,  7452,  7456,  7457,  7461,  7468,
    7472,  7473,  7482,  7491,  7492,  7493,  7497,  7500,  7505,  7510,
    7515,  7523,  7527,  7531,  7532,  7533,  7538,  7541,  7544,  7558,
    7572,  7585,  7586,  7590,  7590,  7590,  7590,  7590,  7590,  7591,
    7594,  7599,  7599,  7599,  7599,  7599,  7599,  7601,  7604,  7610,
    7610,  7610,  7610,  7610,  7610,  7610,  7611,  7611,  7611,  7611,
    7611,  7611,  7611,  7611,  7614,  7615,  7616,  7619,  7628,  7628,
    7634,  7634,  7641,  7641,  7647,  7647,  7655,  7656,  7657,  7660,
    7660,  7663,  7664,  7665,  7676,  7679,  7685,  7690,  7697,  7710,
    7711,  7708,  7729,  7740,  7743,  7748,  7760,  7763,  7767,  7770,
    7771,  7777,  7780,  7781,  7790,  7799,  7804,  7805,  7806,  7807,
    7814,  7817,  7823,  7826,  7836,  7845,  7848,  7851,  7857,  7863,
    7866,  7869,  7872,  7878,  7880,  7882,  7884,  7886,  7888,  7889,
    7890,  7891,  7892,  7893,  7894,  7896,  7898,  7900,  7902,  7904,
    7906,  7908,  7909,  7914,  7915,  7922,  7925,  7934,  7938,  7945,
    7945,  7949,  7949,  7954,  7954,  7958,  7958,  7962,  7968,  7968,
    7971,  7971,  7977,  7984,  7985,  7986,  7990,  7991,  7994,  7995,
    7999,  8005,  8015,  8016,  8024,  8025,  8026,  8027,  8028,  8029,
    8033,  8034,  8035,  8039,  8039,  8051,  8052,  8056,  8057,  8058,
    8059,  8060,  8061,  8062,  8063,  8064,  8065,  8066,  8067,  8068,
    8069,  8070,  8071,  8072,  8073,  8074,  8075,  8076,  8077,  8078,
    8079,  8080,  8081,  8082,  8083,  8084,  8085,  8086,  8087,  8088,
    8089,  8090,  8091,  8092,  8093,  8094,  8095,  8096,  8097,  8098,
    8099,  8100,  8101,  8102,  8103,  8104,  8105,  8106,  8107,  8108,
    8109,  8110,  8111,  8112,  8113,  8114,  8115,  8116,  8117,  8118,
    8119,  8120,  8121,  8122,  8123,  8124,  8125,  8126,  8127,  8128,
    8129,  8130,  8131,  8132,  8133,  8134,  8135,  8136,  8137,  8138,
    8139,  8140,  8141,  8142,  8143,  8144,  8145,  8146,  8147,  8148,
    8149,  8150,  8151,  8152,  8153,  8154,  8155,  8156,  8157,  8158,
    8159,  8160,  8161,  8162,  8163,  8164,  8165,  8166,  8167,  8168,
    8169,  8170,  8171,  8172,  8173,  8174,  8175,  8176,  8177,  8178,
    8179,  8180,  8181,  8182,  8183,  8184,  8185,  8186,  8187,  8188,
    8189,  8190,  8191,  8192,  8193,  8194,  8195,  8196,  8197,  8198,
    8199,  8200,  8201,  8202,  8203,  8204,  8205,  8206,  8207,  8208,
    8209,  8210,  8211,  8212,  8213,  8214,  8215,  8216,  8217,  8218,
    8219,  8220,  8221,  8222,  8223,  8224,  8225,  8226,  8227,  8228,
    8229,  8230,  8231,  8232,  8233,  8234,  8235,  8236,  8237,  8238,
    8239,  8240,  8241,  8242,  8243,  8244,  8245,  8246,  8247,  8248,
    8249,  8250,  8251,  8252,  8253,  8254,  8255,  8256,  8257,  8258,
    8259,  8260,  8261,  8262,  8263,  8264,  8265,  8266,  8267,  8268,
    8269,  8270,  8271,  8272,  8273,  8274,  8275,  8276,  8277,  8278,
    8279,  8280,  8281,  8282,  8283,  8284,  8285,  8286,  8287,  8288,
    8289,  8290,  8291,  8292,  8293,  8294,  8295,  8296,  8297,  8298,
    8299,  8300,  8301,  8302,  8303,  8304,  8305,  8306,  8307,  8308,
    8309,  8310,  8311,  8312,  8313,  8314,  8315,  8316,  8317,  8318,
    8319,  8320,  8321,  8322,  8323,  8324,  8325,  8326,  8327,  8328,
    8329,  8330,  8331,  8332,  8333,  8334,  8335,  8336,  8337,  8338,
    8339,  8340,  8341,  8342,  8343,  8344,  8345,  8346,  8347,  8348,
    8349,  8350,  8351,  8352,  8353,  8354,  8355,  8356,  8357,  8358,
    8359,  8360,  8361,  8362,  8363,  8364,  8365,  8366,  8367,  8368,
    8369,  8370,  8371,  8372,  8373,  8374,  8375,  8383,  8383,  8390,
    8390,  8478,  8482,  8478,  8491,  8495,  8501,  8509,  8519,  8529,
    8541,  8544,  8563,  8589,  8592,  8598,  8601,  8606,  8609,  8617,
    8625,  8638,  8641,  8649,  8652,  8655,  8663,  8667,  8670,  8673,
    8676,  8680,  8681,  8682,  8683,  8684,  8690,  8691,  8692,  8693,
    8694,  8695,  8696,  8697,  8698,  8699,  8700,  8701,  8702,  8703,
    8707,  8713,  8714,  8722,  8722,  8730,  8730,  8734,  8738,  8753,
    8773,  8773,  8777,  8778,  8779,  8780,  8790,  8791,  8792,  8797,
    8823,  8888,  8891,  8887,  8910,  8910,  8916,  8917,  8920,  8921,
    8922,  8923,  8924,  8925,  8926,  8932,  8944,  8947,  8952,  8956,
    8961,  8965,  8970,  8974,  8977,  8981,  8984,  8989,  8993,  9004,
    9010,  9010,  9011,  9012,  9019,  9029,  9029,  9031,  9032,  9033,
    9034,  9035,  9036,  9037,  9038,  9039,  9040,  9041,  9042,  9043,
    9044,  9045,  9046,  9047,  9048,  9049,  9050,  9051,  9052,  9053,
    9054,  9055,  9056,  9057,  9058,  9059,  9060,  9061,  9062,  9063,
    9064,  9065,  9066,  9067,  9068,  9069,  9070,  9071,  9072,  9073,
    9074,  9075,  9076,  9077,  9078,  9079,  9080,  9081,  9082,  9083,
    9084,  9085,  9086,  9087,  9088,  9089,  9090,  9091,  9092,  9093,
    9094,  9095,  9096,  9097,  9098,  9099,  9100,  9101,  9102,  9103,
    9104,  9105,  9106,  9107,  9108,  9109,  9110,  9111,  9112,  9113,
    9114,  9115,  9116,  9117,  9118
};
#endif

#if YYDEBUG || YYERROR_VERBOSE
/* YYTNME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals. */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "NAME", "UMINUS", "COMMA", "KW_OR", 
  "KW_AND", "KW_USING", "NOT", "MATCHES", "POWER", "LESS_THAN", 
  "GREATER_THAN", "EQUAL", "GREATER_THAN_EQ", "LESS_THAN_EQ", "NOT_EQUAL", 
  "PLUS", "MINUS", "MULTIPLY", "DIVIDE", "MOD", "COMMAND", "NUMBER_VALUE", 
  "CHAR_VALUE", "INT_VALUE", "NAMED_GEN", "CLINE", "SQLLINE", "KW_CSTART", 
  "KW_CEND", "USER_DTYPE", "SQL_TEXT", "DYNAMIC_ARRAY", "RESIZE_ARRAY", 
  "ALLOCATE_ARRAY", "DEALLOCATE_ARRAY", "BEFORE_INSERT", "CONCAT_PIPES", 
  "BEFORE_DELETE", "AFTER_INSERT", "AFTER_DELETE", "EXECUTE_IMMEDIATE", 
  "DELETE_ROW_EQUAL_TRUE", "INSERT_ROW_EQUAL_TRUE", 
  "DELETE_ROW_EQUAL_FALSE", "INSERT_ROW_EQUAL_FALSE", 
  "CURRENT_ROW_DISPLAY_EQUAL", "MAXCOUNT", "ALTER_TABLE", "ALTER_INDEX", 
  "WHENEVER_ERROR_CONTINUE", "WHENEVER_ANY_ERROR_CONTINUE", 
  "WHENEVER_WARNING_CONTINUE", "WHENEVER_SQLSUCCESS_CONTINUE", 
  "WHENEVER_SQLWARNING_CONTINUE", "WHENEVER_NOT_FOUND_CONTINUE", 
  "WHENEVER_SQLERROR_CONTINUE", "WHENEVER_SUCCESS_CONTINUE", 
  "WHENEVER_ERROR_GOTO", "WHENEVER_ANY_ERROR_GOTO", 
  "WHENEVER_WARNING_GOTO", "WHENEVER_SQLSUCCESS_GOTO", 
  "WHENEVER_SQLWARNING_GOTO", "WHENEVER_NOT_FOUND_GOTO", 
  "WHENEVER_SQLERROR_GOTO", "WHENEVER_SUCCESS_GOTO", 
  "WHENEVER_ERROR_CALL", "WHENEVER_ANY_ERROR_CALL", 
  "WHENEVER_WARNING_CALL", "WHENEVER_SQLSUCCESS_CALL", 
  "WHENEVER_SQLWARNING_CALL", "WHENEVER_NOT_FOUND_CALL", 
  "WHENEVER_SQLERROR_CALL", "WHENEVER_SUCCESS_CALL", 
  "WHENEVER_ERROR_STOP", "WHENEVER_ANY_ERROR_STOP", 
  "WHENEVER_WARNING_STOP", "WHENEVER_SQLSUCCESS_STOP", 
  "WHENEVER_SQLWARNING_STOP", "WHENEVER_NOT_FOUND_STOP", 
  "WHENEVER_SQLERROR_STOP", "WHENEVER_SUCCESS_STOP", 
  "XSET_MULTIPLY_EQUAL_OPEN_BRACKET", 
  "XSET_ident_DOT_MULTIPLY_EQUAL_OPEN_BRACKET", 
  "XSET_ident_DOT_MULTIPLY_EQUAL", "XSET_MULTIPLY_EQUAL", 
  "XSET_OPEN_BRACKET", "NEWFORMATSHARED", "CREATE_DATABASE", 
  "IMPORT_LEGACY_FUNCTION", "ADD_CONSTRAINT", "DROP_CONSTRAINT", 
  "AS_STATIC", "NOT_FIELD_TOUCHED", "LOCAL_FUNCTION", "EVERY_ROW", "ELIF", 
  "DOUBLE_PRECISION", "COUNT_MULTIPLY", "WAIT_FOR_KEY", 
  "AT_TERMINATION_CALL", "TERMINATE_REPORT", "TO_MAIN_CAPTION", 
  "CLEARSTAT", "TO_MENUITEM", "ID_TO_INT", "TO_STATUSBOX", 
  "ASCII_HEIGHT_ALL", "ASCII_WIDTH_ALL", "IMPORT_DATATYPE", 
  "PAGE_TRAILER_SIZE", "PAGE_HEADER_SIZE", "FIRST_PAGE_HEADER_SIZE", 
  "BYTES_USE_AS_IMAGE", "BYTES_USE_AS_ASCII", "KWUP_BY", "KWDOWN_BY", 
  "CLOSE_STATUSBOX", "MODIFY_NEXT_SIZE", "LOCK_MODE_PAGE", 
  "LOCK_MODE_ROW", "TO_PIPE", "TO_PRINTER", "STATUSBOX", "CONNECT_TO", 
  "FORMHANDLER_INPUT", "UNITS_YEAR", "UNITS_MONTH", "UNITS_DAY", 
  "UNITS_HOUR", "UNITS_MINUTE", "UNITS_SECOND", "NO_NEW_LINES", 
  "FIELDTOWIDGET", "WITH_HOLD", "SHOW_MENU", "TO_CLUSTER", 
  "TO_NOT_CLUSTER", "CWIS", "CREATE_IDX", "FORM_IS_COMPILED", 
  "PDF_REPORT", "IMPORT_FUNCTION", "PROMPT_MANY", "POINTS", "MM", 
  "INCHES", "PREPEND", "MEMBER_OF", "MEMBER_FUNCTION", "APPEND", 
  "TEMPLATE", "END_TEMPLATE", "SQLSICS", "CREATE_SCHEMA", "SQLSIRR", 
  "UPDATESTATS_T", "SQLSICR", "WHENEVER_SQLSUCCESS", 
  "WHENEVER_SQLWARNING", "WHENEVER_ANY_ERROR", "WHENEVER_NOT_FOUND", 
  "WHENEVER_SQLERROR", "WHENEVER_SUCCESS", "WHENEVER_WARNING", 
  "WHENEVER_ERROR", "START_EXTERN", "CONTINUE_CONSTRUCT", "FOUNCONSTR", 
  "SQLSIDR", "CREATE_TEMP_TABLE", "CURRENT_WINDOW_IS", 
  "FIRST_PAGE_HEADER", "ORDER_EXTERNAL_BY", "SCROLL_CURSOR_FOR", 
  "SCROLL_CURSOR", "SQL_INTERRUPT_OFF", "STOP_ALL_EXTERNAL", 
  "WITH_CHECK_OPTION", "WITH_GRANT_OPTION", "SQLSLMNW", "ADDCONSTUNIQ", 
  "CONTINUE_DISPLAY", "CONTINUE_FOREACH", "OUTPUT_TO_REPORT", 
  "SQL_INTERRUPT_ON", "WHERE_CURRENT_OF", "WITHOUT_DEFAULTS", "FOCONSTR", 
  "SCALED_BY", "CONTINUE_PROMPT", "PDF_FUNCTION", "DEFER_INTERRUPT", 
  "DISPLAY_BY_NAME", "NOT_NULL_UNIQUE", "SKIP_TO_TOP", "TOP_OF_PAGE", 
  "SKIP_TO", "SKIP_BY", "WITHOUT_WAITING", "BEFCONSTRUCT", "SQLSLMW", 
  "AFTCONSTRUCT", "ALL_PRIVILEGES", "CLOSE_DATABASE", "CONTINUE_INPUT", 
  "CONTINUE_WHILE", "CREATE_SYNONYM", "DROP_TABLE", "EXIT_CONSTRUCT", 
  "INEXCLUSIVE", "REPORT_TO_PRINTER", "REPORT_TO_PIPE", "RETURN", 
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
  "NEXTFORM", "RENTAB", "ASCENDING", "ASSOCIATE", "CHAR", "CONSTRUCT", 
  "DELIMITER", "DOWNSHIFT", "DROP_VIEW", "END_INPUT", "END_WHILE", 
  "EXCLUSIVE", "EXIT_CASE", "EXIT_MENU", "FORM_LINE", "INTERRUPT", 
  "INTO_TEMP", "INVISIBLE", "IN_MEMORY", "LINKED_TO", "LOAD_FROM", 
  "LOCKTAB", "MENU_LINE", "OPEN_FORM", "OTHERWISE", "PRECISION", "PRIOR", 
  "PROCEDURE", "REPORT_TO", "RETURNING", "UNDERLINE", "UNLOAD_TO", 
  "BEFROW", "UNLOAD_T", "VARIABLE", "ABSOLUTE", "AFTROW", "BUFFERED", 
  "CONSTANT", "CONST", "CONTINUE", "DATABASE", "DATETIME", "DEFAULTS", 
  "DISTINCT", "END_CASE", "END_MAIN", "END_MENU", "END_TYPE", "EXIT_FOR", 
  "EXTERNAL", "FRACTION", "FUNCTION", "GROUP_BY", "INTERVAL", "KWMESSAGE", 
  "NOT_LIKE", "NOT_ILIKE", "NOT_NULL", "PASSWORD", "PREVIOUS", "READONLY", 
  "REGISTER", "RELATIVE", "RESOURCE", "SMALLINT", "VALIDATE", "WITH_LOG", 
  "WORDWRAP", "BY_NAME", "IN_FILE", "IS_NULL", "AVERAGE", "BETWEEN", 
  "CAPTION", "CLIPPED", "CLOSE_BRACKET", "COLUMNS", "COMMENT", "CONNECT", 
  "CURRENT", "DBYNAME", "DECIMAL", "DECLARE", "DEFAULT", "DISPLAY", 
  "ENDCODE", "EXECUTE", "FOREACH", "FOREIGN", "GLOBALS", "INFIELD", 
  "INTEGER", "KWWINDOW", "MAGENTA", "NUMERIC", "OPTIONS", "PERCENT", 
  "PREPARE", "PROGRAM", "RECOVER", "REVERSE", "SECTION", "SESSION", 
  "SYNONYM", "THRU", "TRAILER", "UPSHIFT", "VARCHAR", "WAITING", 
  "CLOSE_SHEV", "CLOSE_SQUARE", "KW_FALSE", "NOT_IN", "ONKEY", 
  "OPEN_BRACKET", "BORDER", "BOTTOM", "COLUMN", "COMMIT", "CREATE", 
  "CURSOR", "DEFINE", "DELETE", "DOUBLE", "END_IF", "ESCAPE", "EXISTS", 
  "EXTEND", "EXTENT", "FINISH", "FORMAT", "HAVING", "HEADER", "INSERT", 
  "LOCATE", "MARGIN", "MEMORY", "MINUTE", "MODIFY", "NORMAL", 
  "EQUAL_EQUAL", "OPEN_SHEV", "OPEN_SQUARE", "OPTION", "OUTPUT", "PROMPT", 
  "PUBLIC", "RECORD", "REPORT", "REVOKE", "SCHEMA", "SCROLL_USING", 
  "SCROLL", "SECOND", "SELECT", "SERIAL", "SETL", "SHARED", "SPACES", 
  "UNIQUE", "UNLOCK", "UPDATE", "VALUES", "YELLOW", "AFTER", "KWLINE", 
  "KW_NULL", "KW_TRUE", "SINGLE_KEY", "ALTER", "ARRAY", "ASCII", "AUDIT", 
  "BLACK", "BLINK", "CHECK", "CLEAR", "CLOSE", "CODE_C", "COUNT", "DEFER", 
  "ERROR", "EVERY", "FETCH", "FIRST", "FLOAT", "FLUSH", "FOUND", "GRANT", 
  "GREEN", "GROUP", "INDEX", "KWFORM", "LABEL", "LOCAL", "MONEY", "MONTH", 
  "ORDER", "OUTER", "PAUSE", "PRINT_IMAGE", "PRINT_FILE", "PRINT", 
  "RIGHT", "DOUBLE_COLON", "SEMICOLON", "SLEEP", "TUPLE", "UNION", 
  "WHERE", "WHILE", "WHITE", "CCODE", "ANSI", "BLUE", "BOLD", "BYTE", 
  "FCALL", "CASE", "CYAN", "DATE", "DESC", "KWDOWN", "TAB", "DROP", 
  "ELSE", "EXEC", "EXIT", "FREE", "FROM", "GOTO", "HELP_FILE", 
  "LANG_FILE", "HELP", "HIDE", "HOUR", "INTO", "LAST", "LEFT", "LIKE", 
  "MAIN", "MENU", "MODE", "NEED", "NEXT", "NOCR", "OPEN", "QUIT", "REAL", 
  "ROWS", "SHOW", "SIZE", "SKIP", "SOME", "STEP", "STOP", "TEMP", "TEXT", 
  "THEN", "USER", "WAIT", "WHEN", "WITH", "WORK", "YEAR", "KW_IS", "XSET", 
  "ADD", "ALL", "ANY", "ASC", "AVG", "COLON", "DAY", "DBA", "DEC", "DIM", 
  "FKEY", "FOR", "KEY", "KWNO", "LET", "LOG", "XMAX", "XMIN", "PAD", 
  "PUT", "RED", "ROW", "RUN", "SQL", "SUM", "TOP", "USE", "ATSIGN", 
  "AS_TIFF", "AS_GIF", "AS_PNG", "AS_JPEG", "AS", "AT", "BY", "DOT", "GO", 
  "IF", "IN", "OF", "ON", "TO", "KWUP", "FONT_NAME", "FONT_SIZE", 
  "PAPER_SIZE_IS_LETTER", "PAPER_SIZE_IS_LEGAL", "PAPER_SIZE_IS_A5", 
  "PAPER_SIZE_IS_A4", "PAPER_SIZE_IS_LETTER_L", "PAPER_SIZE_IS_LEGAL_L", 
  "PAPER_SIZE_IS_A5_L", "PAPER_SIZE_IS_A4_L", "FORMHANDLER", 
  "END_FORMHANDLER", "BEFORE_EVENT", "BEFORE_OPEN_FORM", "AFTER_EVENT", 
  "BEFORE_CLOSE_FORM", "BEFORE_ANY", "AFTER_ANY", "MENUHANDLER", 
  "END_MENUHANDLER", "BEFORE_SHOW_MENU", "DISABLE_PROGRAM", "DISABLE_ALL", 
  "BUTTONS", "CHECK_MENUITEM", "DISABLE_FORM", "DISABLE_MENUITEMS", 
  "DISABLE", "ENABLE_FORM", "ENABLE_MENUITEMS", "ENABLE", "KWFIELD", 
  "ICON", "MESSAGEBOX", "TO_DEFAULTS", "UNCHECK_MENUITEM", "BEFORE", 
  "INPUT", "END", "INT_TO_ID", "TIMEOUT", "OFF", "WITH_1_DIMENSION", 
  "WITH_2_DIMENSION", "WITH_3_DIMENSION", "TILDE", "ILIKE", 
  "FGL_ISDYNARR_ALLOCATED", "FGL_DYNARR_EXTENTSIZE", "$accept", 
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
  "bef_c_field_list_as_struct", "aft_c_field_list_as_struct", 
  "interval_expr", "extend_parameters", "op_datetime_qual", "defer_cmd", 
  "define_section", "define_multiple", "define_set", "@29", "@30", 
  "def_part", "define_ident", "@31", "def_part2", "@32", "constant_value", 
  "var_def_name", "var_def_list", "op_char", "ranking", "array_variable", 
  "@33", "@34", "@35", "assoc_open_bracket", "assoc_close_bracket", 
  "number_arr_assoc", "number_arr_list", "number_value_arr", 
  "record_variable", "@36", "@37", "@38", "link_to_pk_list", "link_to_pk", 
  "dtype_ident", "op_as_static", "dtype2", "@39", "@40", "dtype", 
  "like_var", "tab_name", "col_name", "datetime_qual", "interval_qual", 
  "dtime_start", "@41", "dtime_val", "dtime_end", "@42", "opt_frac", 
  "opt_unit_size", "dtfrac", "int_start", "@43", "int_start_unit", 
  "int_end", "op_equal", "dim_section", "@44", "dim_dtype", 
  "dim_like_var", "dim_array_variable", "@45", "@46", 
  "dim_record_variable", "@47", "@48", "dim_def_part", "dim_def_part2", 
  "dim_var_def_list", "dim_var_def_name", "opt_at", "display_b_n_cmd", 
  "display_cmd", "display_form_cmd", "display_array_cmd", "@49", "@50", 
  "opt_scroll", "display_attr", "disp_rest", "disp_field_commands", 
  "disp_field_command", "@51", "@52", "@53", "alloc_arr_cmd", 
  "dealloc_arr_cmd", "resize_arr_cmd", "error_cmd", "ext_cmd", 
  "continue_cmd", "exit_prog_cmd", "fgl_expr_c", "fgl_next", 
  "op_fgl_expr_ret_list", "fgl_expr_ret", "fgl_expr_ret_list", 
  "fgl_expr_list", "fgl_expr_concat", "fgl_expr", "int_sign", 
  "boolean_expr", "initial_expr", "literal_expr", "variable_entry_2", 
  "variable_entry", "report_only_expr", "@54", "and_or_expr", 
  "inexpr_list", "in_expr", "null_expr", "string_match_expr", "clip_expr", 
  "using_expr", "math_expr", "comparison_expr", "reset_cnt", 
  "function_call_expr2", "@55", "@56", "@57", "@58", "function_callb", 
  "@59", "@60", "@61", "@62", "@63", "@64", "@65", "@66", "op_extend_d", 
  "op_extend_i", "function_call_expr", "builtin_expr", "builtin_funcs", 
  "pdf_expr", "interval_func_params", "numeric_time_interval", 
  "numeric_time_unit_small", "numeric_time_unit_big", 
  "field_name_list_as_struct", "for_cmd", "@67", "@68", "for_step", 
  "foreach_cmd", "@69", "@70", "@71", "opt_foreach_using_part", 
  "formhandler_def", "@72", "@73", "op_input_section", "op_bef_ev_list", 
  "bef_ev_list", "bef_ev", "@74", "@75", "op_aft_ev_list", "aft_ev_list", 
  "aft_ev", "@76", "@77", "input_section", "input_sub_section", 
  "in_variable_list", "in_id_list", "in_bn_variable_list", "field_ops", 
  "field_op", "@78", "@79", "@80", "@81", "@82", "free_cmd", "line_no", 
  "file_name", "a_number", "coords", "display_coords", 
  "field_name_as_struct", "cursor_name", "fetch_cursor_name", "win_name", 
  "open_win_name", "form_name", "open_form_name", "opt_help_no", 
  "identifier", "ident_or_var", "ident_p2", "var_or_string", 
  "field_name2_as_struct", "cvariable", "real_number", "goto_cmd", 
  "label_goto", "check_menu_cmd", "menu_item_list", "menu_item", 
  "uncheck_menu_cmd", "disable_cmd", "enable_cmd", "msg_box_cmd", "@83", 
  "op_disable_msg", "gm_disable_msg", "op_returning_msg", 
  "gm_returning_msg", "op_caption", "gm_caption", "op_icon", "gm_icon", 
  "op_buttons", "gm_buttons", "op_def_but", "if_cmd", "@84", "@85", 
  "op_else", "@86", "@87", "@88", "import_m", "module_import", "init_cmd", 
  "@89", "init_tab_list", "init_tab", "end_input", "opt_defs", 
  "field_commands", "field_command", "@90", "@91", "@92", "@93", "@94", 
  "@95", "@96", "@97", "@98", "@99", "@100", "bef_field_list_as_struct", 
  "aft_field_list_as_struct", "next_field_cmd", "next_form_cmd", 
  "next_field", "input_cmd", "@101", "inp_rest", "@102", "scroll_cmd", 
  "up_or_down", "op_help", "input_array_attributes", 
  "input_array_attributes_int", "on_key_command", "@103", "key_val", 
  "@104", "accept_key", "single_key_val", "key_do", "key_value_list", 
  "key_value", "key_value_1", "label_cmd", "let_cmd", "@105", "@106", 
  "op_expr_null", "linked_cmd", "linked_del_cmd", "linked_upd_cmd", 
  "locate_cmd", "module", "@107", "op_module_header", "module_header", 
  "module_entry", "func_main_def", "func_or_main2", "at_term_cmd", 
  "func_or_main", "module_code", "op_code", "module_define_section", 
  "ldeffunction", "func_def", "@108", "@109", "@110", "@111", 
  "end_func_command", "main_def", "@112", "@113", "return_cmd", 
  "op_fgl_expr_list", "db_section", "module_globals_section", 
  "actual_globals_section", "xglobals_entry", "globals_entry", "@114", 
  "glob_section", "mem_func_def", "@115", "@116", "@117", "menu_cmd", 
  "@118", "end_menu_command", "menu_block_command", "@119", "@120", 
  "@121", "menu_commands", "opt_key", "menu_opt_name", 
  "menu_optional_desc", "next_option_cmd", "show_option_cmd", 
  "hide_option_cmd", "opt_name", "opt_name_list", "menu_title", 
  "menu_def", "@122", "@123", "menu_handler_elements", 
  "menu_handler_element", "@124", "@125", "message_cmd", "msg_next", 
  "gui_message", "msg_start", "op_msg_wait", "msg_wait", "variable", 
  "var_int", "varsetidentdot", "var", "assoc_var_read", "assoc_var_write", 
  "assoc_sub", "dot_part_var", "array_r_variable", 
  "array_r_variable_or_ident", "arr_subscripts", "num_list", 
  "num_list_element", "let_variable", "let_var", "let_var_dot", 
  "let_array_r_variable", "op_param_var_list", "fparam_var_list", 
  "ibind_var_list", "func_def_var", "ibind_var", "obind_var_list", 
  "obind_var", "obind_var_let_list", "obind_let_var", "use_arr_var", 
  "obind_var_list_ord", "obind_var_ord", "optional_asc_desc", 
  "array_r_varid", "init_bind_var_list", "init_bind_var", 
  "open_window_cmd", "op_at_statusbox", "op_size_statusbox", 
  "open_statusbox_cmd", "formhandler_name", "open_form_cmd", 
  "open_form_rest", "open_form_gui", "op_at_gui", "op_like_gui", 
  "op_absolute", "open_session_cmd", "open_cursor_cmd", "user_details", 
  "op_disable", "connect_cmd", "op_connect_as", "con_user_details", 
  "options_cmd", "opt_options", "opt_allopts", "prepare_cmd", 
  "var_or_char", "execute_cmd", "stmt_id", "prompt_cmd", "@126", 
  "opt_timeout", "gui_prompt_cmd", "opt_char", "prompt_key_sec", 
  "prompt_key_clause", "on_key_command_prompt", "@127", "prompt_title", 
  "put_cmd", "@128", "put_from", "put_val_list", "put_val", "start_cmd", 
  "rout", "rep_name", "op_values", "output_cmd", "finish_cmd", 
  "term_rep_cmd", "report_section", "format_section", "format_actions", 
  "format_action", "@129", "@130", "@131", "@132", "@133", "@134", "@135", 
  "report_cmd", "need_command", "@136", "op_lines", "skip_command", 
  "@137", "opt_rep_expr_list", "xrep_expr_list", "xxrep_expr_list", 
  "opt_print_at", "print_command", "print_file_command", 
  "print_img_command", "opt_scaling", "img_types", "blob_var", "opt_semi", 
  "rep_expr_list", "rep_expr", "rep_agg", "op_output_section", 
  "output_commands", "output_command", "pdf_output_commands", "nval", 
  "nval_number", "pdf_op_output_section", "pdf_output_command", 
  "op_rep_order_by", "report_def", "@138", "@139", "@140", "@141", "@142", 
  "@143", "rep_where", "pause_command", "pause_msg", "pdf_report_def", 
  "@144", "@145", "@146", "@147", "@148", "@149", "pdf_report_section", 
  "pdf_functions", "@150", "@151", "@152", "op_wordwrap", "run_cmd", 
  "drops_cmd", "drops_c", "create_cmd", "create_c_2_ss", "@153", "@154", 
  "@155", "@156", "create_c_1", "op_no_log", "idx_column_list", 
  "idx_column", "table_element_list_ss", "table_element_ss", 
  "upd_stats_cmd", "alter_cmd", "alter_clauses_ss", "alter_clause_ss", 
  "alter_add_clause_ss", "add_column_clause_ss", "add_column_clauses_ss", 
  "alter_drop_clause", "drop_column_list", "drop_column", 
  "alter_modify_clause", "modify_column_clauses_ss", 
  "modify_column_clause_ss", "alter_lock_mode", "alter_modify_next", 
  "alter_add_constraint_clause", "alter_drop_contraint_clause", 
  "column_constraints_ss", "constraint_name", "set_cmd", "op_conn_id", 
  "op_fgl_expr", "sleep_cmd", "rollback_statement", "insert_statement_ss", 
  "@157", "ins_2_ss", "@158", "op_insert_column_list", 
  "insert_column_list", "insert_value_list_ss", "insert_value_ss", 
  "fetch_statement", "@159", "@160", "declare_cursor_name", "fetch_part", 
  "opt_into_fetch_part", "@161", "opt_foreach_into_fetch_part", "@162", 
  "fetch_place", "delete_statement_position", 
  "delete_statement_search_ss", "order_by_clause", 
  "sort_specification_list", "sort_specification", "sort_spec", 
  "op_asc_desc", "begin_statement", "commit_statement", "op_exclusive", 
  "set_database_cmd", "var_ident_qchar", "sql_cmd", "@163", 
  "sql_commands", "privilege_definition", "op_with_grant_option", 
  "privileges", "action_list", "action", "op_grant_column_list", 
  "grant_column_list", "grantee_list", "grantee", "view_definition_ss", 
  "op_view_column_list", "view_column_list", "op_with_check_option", 
  "check_constraint_definition_ss", "referential_constraint_definition", 
  "references_specification", "references_columns", 
  "referenced_table_and_columns", "references_column_list", 
  "unique_constraint_definition", "unique_column_list", 
  "table_constraint_definition_ss", "default_clause", 
  "ct_column_definiton_ss", "op_default_clause", 
  "op_column_constraint_list_ss", "column_constraint_list_ss", 
  "column_constraint_ss", "schema_ss", "schema_authorization_clause", 
  "schema_authorization_identifier", "schema_element_list_ss", 
  "schema_element_ss", "having_clause_ss", "group_by_clause_ss", 
  "column_specification_list_ss", "where_clause_ss", "from_clause", 
  "table_reference_list", "table_reference", "tname", "tname_list", 
  "table_expression_ss", "op_where_clause_ss", "op_group_by_clause_ss", 
  "op_having_clause_ss", "search_condition_ss", "boolean_term_ss", 
  "boolean_factor_ss", "boolean_primary_ss", "exists_predicate_ss", 
  "op_escape", "pattern_ss", "escape_character", "in_predicate_ss", 
  "in_value_list", "in_value_specification", "op_not", 
  "comparison_predicate_ss", "comp_op", "predicate_ss", "op_all", 
  "data_type", "char_string_type", "exact_numeric_type", "op_scale", 
  "approx_numeric_type", "length", "precision", "scale", "table_name", 
  "idx_name", "authorization_identifier", "col_arr", "column_name", 
  "column_name_specific", "correlation_name", "literal", "curr_v_clause", 
  "curr_clause", "cur_part", "cur_v_part", "s_curr_v", "e_curr_v", 
  "s_curr", "e_curr", "dbase_name", "flush_cmd", "declare_cmd", "@164", 
  "@165", "@166", "@167", "curs_forupdate", "cur_update_list", "colident", 
  "cursor_specification_all_ss", "cursor_specification_sel_ss", 
  "select_statement_full_ss", "select_statement_ss", "@168", "@169", 
  "in_select_statement_ss", "select_statement2_ss", 
  "select_statement21_ss", "sel_p2_ss", "tmp_tabname", "opt_into_sel_ss", 
  "query_specification_ss", "subquery_ss", "op_ad", "select_list_ss", 
  "value_expression_pls_ss", "column_specification_ss", 
  "value_expression_ss", "value_expression_initial_ss", 
  "value_expression_complex_ss", "value_expr_list_ss", 
  "value_specification", "unload_cmd", "load_cmd", "opt_delim", 
  "char_or_var", "opt_col_list", "col_list", "simple_column_name", 
  "ufile", "opt_use", "conn_id", "misc_sql", "rename_stmt", "rentabname", 
  "rencolname", "unlock_stmt", "lock_stmt", "share_or_exclusive", 
  "units_qual", "extend_qual_ss", "sql_block_cmd", "@170", "sql_block", 
  "sql_block_entry", "in_var", "@171", "sql_block_into", "@172", 
  "update_statement_ss", "@173", "@174", "where_upd_ss", 
  "set_clause_list_ss", "upd_columns_ss", "upd_column_name", "col_1_ss", 
  "upd_col_list", "upd_val_list_ss", "upd_val_ss", 
  "upd_value_expression_ss", "upd_value_expression_initial_ss", 
  "upd_value_expression_complex_ss", "upd_var_ident_ibind_ss", 
  "upd_value_expr_list_ss", "validate_cmd", "@175", "validate_tab_list", 
  "validate_tab", "var_ident", "var2", "var3", "aft_dot", 
  "var_ident_ibind_ss", "while_cmd", "@176", "@177", "op_clr_fields", 
  "op_to_defs", "clear_cmd", "fld_list_as_struct", "current_win_cmd", 
  "window_type", "show_cmd", "op_mnfile", "menu_name", "menu_handler", 
  "hide_cmd", "move_cmd", "NAMED", "commands", "all_commands", "command1", 
  "commands_all", "@178", "commands_all1", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const unsigned short yytoknum[] =
{
       0,   256,  1698,  1699,  1700,  1606,  1646,  1601,  1538,  1621,
    1417,  1524,  1520,  1435,  1596,  1334,  1392,  1466,  1632,  1619,
    1525,  1552,  1620,  1399,  1701,  1702,  1703,  1704,  1705,  1706,
    1707,  1708,  1709,  1710,  1000,  1001,  1002,  1003,  1004,  1005,
    1006,  1007,  1008,  1009,  1010,  1011,  1012,  1013,  1014,  1015,
    1016,  1017,  1018,  1019,  1020,  1021,  1022,  1023,  1024,  1025,
    1026,  1027,  1028,  1029,  1030,  1031,  1032,  1033,  1034,  1035,
    1036,  1037,  1038,  1039,  1040,  1041,  1042,  1043,  1044,  1045,
    1046,  1047,  1048,  1049,  1050,  1051,  1052,  1053,  1054,  1055,
    1056,  1057,  1058,  1059,  1060,  1061,  1062,  1063,  1064,  1065,
    1066,  1067,  1068,  1069,  1070,  1071,  1072,  1073,  1074,  1075,
    1076,  1077,  1078,  1079,  1080,  1081,  1082,  1083,  1084,  1085,
    1086,  1087,  1088,  1089,  1090,  1091,  1092,  1093,  1094,  1095,
    1096,  1097,  1098,  1099,  1100,  1101,  1102,  1103,  1104,  1105,
    1106,  1107,  1108,  1109,  1110,  1111,  1112,  1113,  1114,  1115,
    1116,  1117,  1118,  1119,  1120,  1121,  1122,  1123,  1124,  1125,
    1126,  1127,  1128,  1129,  1130,  1131,  1132,  1133,  1134,  1135,
    1136,  1137,  1138,  1139,  1140,  1141,  1142,  1143,  1144,  1145,
    1146,  1147,  1148,  1149,  1150,  1151,  1152,  1153,  1154,  1155,
    1156,  1157,  1158,  1159,  1160,  1161,  1162,  1163,  1164,  1165,
    1166,  1167,  1168,  1169,  1170,  1171,  1172,  1173,  1174,  1175,
    1176,  1177,  1178,  1179,  1180,  1181,  1182,  1183,  1184,  1185,
    1186,  1187,  1188,  1189,  1190,  1191,  1192,  1193,  1194,  1195,
    1196,  1197,  1198,  1199,  1200,  1201,  1202,  1203,  1204,  1205,
    1206,  1207,  1208,  1209,  1210,  1211,  1212,  1213,  1214,  1215,
    1216,  1217,  1218,  1219,  1220,  1221,  1222,  1223,  1224,  1225,
    1226,  1227,  1228,  1229,  1230,  1231,  1232,  1233,  1234,  1235,
    1236,  1237,  1238,  1239,  1240,  1241,  1242,  1243,  1244,  1245,
    1246,  1247,  1248,  1249,  1250,  1251,  1252,  1253,  1254,  1255,
    1256,  1257,  1258,  1259,  1260,  1261,  1262,  1263,  1264,  1265,
    1266,  1267,  1268,  1269,  1270,  1271,  1272,  1273,  1274,  1275,
    1276,  1277,  1278,  1279,  1280,  1281,  1282,  1283,  1284,  1285,
    1286,  1287,  1288,  1289,  1290,  1291,  1292,  1293,  1294,  1295,
    1296,  1297,  1298,  1299,  1300,  1301,  1302,  1303,  1304,  1305,
    1306,  1307,  1308,  1309,  1310,  1311,  1312,  1313,  1314,  1315,
    1316,  1317,  1318,  1319,  1320,  1321,  1322,  1323,  1324,  1325,
    1326,  1327,  1328,  1329,  1330,  1331,  1332,  1333,  1335,  1336,
    1337,  1338,  1339,  1340,  1341,  1342,  1343,  1344,  1345,  1346,
    1347,  1348,  1349,  1350,  1351,  1352,  1353,  1354,  1355,  1356,
    1357,  1358,  1359,  1360,  1361,  1362,  1363,  1364,  1365,  1366,
    1367,  1368,  1369,  1370,  1371,  1372,  1373,  1374,  1375,  1376,
    1377,  1378,  1379,  1380,  1381,  1382,  1383,  1384,  1385,  1386,
    1387,  1388,  1389,  1390,  1391,  1393,  1394,  1395,  1396,  1397,
    1398,  1400,  1401,  1402,  1403,  1404,  1405,  1406,  1407,  1408,
    1409,  1410,  1411,  1412,  1413,  1414,  1415,  1416,  1418,  1419,
    1420,  1421,  1422,  1423,  1424,  1425,  1426,  1427,  1428,  1429,
    1430,  1431,  1432,  1433,  1434,  1436,  1437,  1438,  1439,  1440,
    1441,  1442,  1443,  1444,  1445,  1446,  1447,  1448,  1449,  1450,
    1451,  1452,  1453,  1454,  1455,  1456,  1457,  1458,  1459,  1460,
    1461,  1462,  1463,  1464,  1465,  1467,  1468,  1469,  1470,  1471,
    1472,  1473,  1474,  1475,  1476,  1477,  1478,  1479,  1480,  1481,
    1482,  1483,  1484,  1485,  1486,  1487,  1488,  1489,  1490,  1491,
    1492,  1493,  1494,  1495,  1496,  1497,  1498,  1499,  1500,  1501,
    1502,  1503,  1504,  1505,  1506,  1507,  1508,  1509,  1510,  1511,
    1512,  1513,  1514,  1515,  1516,  1517,  1518,  1519,  1521,  1522,
    1523,  1526,  1527,  1528,  1529,  1530,  1531,  1532,  1533,  1534,
    1535,  1536,  1537,  1539,  1540,  1541,  1542,  1543,  1544,  1545,
    1546,  1547,  1548,  1549,  1550,  1551,  1553,  1554,  1555,  1556,
    1557,  1558,  1559,  1560,  1561,  1562,  1563,  1564,  1565,  1566,
    1567,  1568,  1569,  1570,  1571,  1572,  1573,  1574,  1575,  1576,
    1577,  1578,  1579,  1580,  1581,  1582,  1583,  1584,  1585,  1586,
    1587,  1588,  1589,  1590,  1591,  1592,  1593,  1594,  1595,  1597,
    1598,  1599,  1600,  1602,  1603,  1604,  1605,  1607,  1608,  1609,
    1610,  1611,  1612,  1613,  1614,  1615,  1616,  1617,  1618,  1622,
    1623,  1624,  1625,  1626,  1627,  1628,  1629,  1630,  1631,  1633,
    1634,  1635,  1636,  1637,  1638,  1639,  1640,  1641,  1642,  1643,
    1644,  1645,  1647,  1648,  1649,  1650,  1651,  1652,  1653,  1654,
    1655,  1656,  1657,  1658,  1659,  1660,  1661,  1662,  1663,  1664,
    1665,  1666,  1667,  1668,  1669,  1670,  1671,  1672,  1673,  1674,
    1675,  1676,  1677,  1678,  1679,  1680,  1681,  1682,  1683,  1684,
    1685,  1686,  1687,  1688,  1689,  1690,  1691,  1692,  1693,  1694,
    1695,  1696,  1697
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const unsigned short yyr1[] =
{
       0,   713,   714,   715,   716,   717,   718,   718,   719,   719,
     720,   721,   721,   721,   721,   721,   721,   722,   722,   722,
     722,   722,   723,   723,   724,   724,   726,   725,   725,   727,
     727,   728,   728,   728,   728,   728,   728,   728,   728,   728,
     728,   728,   728,   728,   728,   728,   728,   728,   729,   729,
     731,   730,   732,   732,   733,   733,   733,   733,   733,   733,
     733,   733,   733,   734,   735,   736,   735,   735,   735,   735,
     735,   737,   738,   735,   739,   740,   741,   735,   742,   743,
     735,   744,   745,   735,   746,   747,   748,   735,   749,   749,
     750,   750,   750,   751,   751,   752,   752,   753,   754,   754,
     755,   755,   757,   756,   758,   756,   759,   759,   760,   760,
     761,   762,   763,   762,   764,   765,   764,   767,   766,   769,
     768,   770,   770,   770,   770,   770,   770,   771,   772,   772,
     773,   773,   774,   775,   775,   776,   777,   779,   780,   778,
     781,   781,   782,   782,   783,   783,   784,   784,   784,   785,
     785,   787,   786,   788,   786,   789,   786,   790,   786,   791,
     786,   792,   792,   793,   793,   794,   794,   794,   794,   794,
     794,   795,   796,   796,   797,   797,   798,   798,   799,   799,
     801,   802,   800,   800,   803,   803,   805,   804,   806,   806,
     806,   806,   806,   807,   806,   808,   808,   808,   808,   809,
     810,   810,   811,   811,   812,   812,   812,   812,   814,   813,
     815,   813,   816,   813,   817,   817,   818,   818,   819,   820,
     820,   820,   821,   823,   822,   824,   822,   825,   822,   826,
     826,   827,   828,   829,   829,   831,   832,   830,   833,   833,
     833,   833,   833,   833,   833,   833,   833,   833,   833,   833,
     833,   833,   833,   833,   833,   833,   833,   833,   833,   833,
     833,   833,   833,   833,   833,   833,   834,   835,   836,   837,
     837,   838,   840,   839,   841,   841,   841,   841,   841,   841,
     841,   843,   842,   844,   844,   845,   845,   846,   848,   847,
     849,   849,   849,   849,   849,   849,   849,   850,   851,   851,
     853,   852,   854,   854,   854,   854,   854,   854,   854,   854,
     854,   854,   854,   854,   854,   854,   854,   854,   854,   854,
     854,   854,   854,   854,   854,   855,   857,   856,   858,   856,
     860,   859,   861,   859,   862,   862,   863,   864,   864,   865,
     866,   866,   866,   866,   866,   866,   866,   866,   867,   868,
     869,   871,   872,   870,   873,   873,   874,   875,   875,   875,
     876,   876,   878,   877,   879,   877,   880,   877,   881,   882,
     883,   884,   884,   885,   885,   885,   885,   885,   885,   885,
     885,   885,   886,   886,   886,   886,   886,   886,   886,   886,
     887,   887,   888,   888,   888,   888,   888,   888,   888,   888,
     888,   888,   889,   889,   889,   889,   889,   889,   889,   889,
     889,   889,   889,   890,   890,   891,   891,   892,   892,   893,
     893,   894,   894,   895,   896,   896,   897,   897,   897,   897,
     897,   897,   898,   898,   899,   899,   899,   899,   900,   900,
     901,   902,   902,   902,   903,   902,   904,   904,   905,   905,
     906,   906,   906,   906,   907,   907,   908,   908,   908,   908,
     908,   908,   908,   908,   909,   910,   911,   911,   911,   911,
     911,   911,   912,   912,   912,   912,   912,   912,   912,   913,
     915,   916,   914,   917,   918,   914,   920,   921,   919,   922,
     923,   919,   924,   925,   919,   926,   927,   919,   919,   919,
     919,   919,   919,   919,   928,   928,   929,   930,   930,   930,
     930,   930,   930,   930,   930,   930,   931,   931,   932,   932,
     932,   932,   933,   933,   933,   934,   934,   935,   935,   935,
     936,   936,   936,   936,   936,   936,   936,   936,   936,   936,
     937,   937,   938,   938,   940,   941,   939,   942,   942,   944,
     945,   946,   943,   947,   947,   949,   950,   948,   951,   951,
     952,   952,   953,   953,   955,   954,   956,   954,   957,   957,
     958,   958,   960,   959,   961,   959,   962,   963,   963,   963,
     964,   964,   965,   965,   966,   966,   967,   967,   969,   968,
     970,   968,   971,   968,   972,   968,   973,   968,   974,   975,
     975,   975,   975,   975,   975,   975,   976,   976,   977,   978,
     979,   980,   980,   980,   980,   980,   980,   980,   980,   981,
     982,   983,   984,   985,   986,   987,   987,   988,   989,   990,
     990,   991,   991,   992,   992,   992,   992,   992,   992,   993,
     994,   994,   995,   996,   996,   997,   998,   998,   999,  1000,
    1001,  1001,  1001,  1002,  1002,  1002,  1004,  1003,  1005,  1005,
    1006,  1006,  1007,  1007,  1008,  1009,  1009,  1010,  1011,  1011,
    1012,  1013,  1013,  1014,  1015,  1015,  1017,  1018,  1016,  1019,
    1020,  1019,  1021,  1022,  1019,  1023,  1023,  1024,  1026,  1025,
    1025,  1027,  1027,  1028,  1028,  1029,  1029,  1029,  1030,  1030,
    1031,  1031,  1033,  1032,  1034,  1032,  1035,  1032,  1036,  1032,
    1037,  1032,  1038,  1032,  1039,  1032,  1040,  1032,  1041,  1032,
    1042,  1032,  1043,  1032,  1044,  1044,  1045,  1045,  1046,  1047,
    1048,  1048,  1048,  1050,  1049,  1051,  1051,  1052,  1051,  1053,
    1054,  1054,  1054,  1054,  1055,  1055,  1056,  1057,  1057,  1057,
    1057,  1057,  1057,  1057,  1057,  1057,  1059,  1058,  1058,  1061,
    1060,  1062,  1063,  1064,  1064,  1065,  1065,  1066,  1067,  1067,
    1067,  1067,  1067,  1067,  1067,  1067,  1067,  1067,  1067,  1067,
    1067,  1067,  1067,  1067,  1067,  1067,  1068,  1070,  1071,  1069,
    1072,  1072,  1073,  1074,  1075,  1076,  1076,  1078,  1077,  1079,
    1079,  1080,  1080,  1081,  1081,  1081,  1081,  1082,  1082,  1083,
    1083,  1084,  1085,  1085,  1085,  1085,  1085,  1085,  1085,  1085,
    1085,  1085,  1086,  1087,  1087,  1088,  1089,  1089,  1091,  1092,
    1093,  1094,  1090,  1095,  1097,  1098,  1096,  1099,  1100,  1100,
    1101,  1101,  1102,  1103,  1103,  1104,  1104,  1104,  1106,  1105,
    1107,  1107,  1109,  1110,  1111,  1108,  1113,  1112,  1114,  1116,
    1115,  1117,  1115,  1118,  1115,  1119,  1119,  1120,  1120,  1121,
    1121,  1122,  1122,  1122,  1123,  1124,  1125,  1126,  1126,  1126,
    1127,  1127,  1128,  1128,  1130,  1131,  1129,  1132,  1132,  1134,
    1133,  1135,  1133,  1136,  1137,  1137,  1137,  1137,  1138,  1138,
    1138,  1138,  1138,  1139,  1140,  1140,  1141,  1142,  1143,  1143,
    1144,  1145,  1145,  1145,  1145,  1145,  1145,  1146,  1147,  1148,
    1148,  1149,  1149,  1150,  1151,  1152,  1152,  1153,  1153,  1154,
    1155,  1156,  1156,  1156,  1156,  1156,  1156,  1157,  1157,  1158,
    1159,  1159,  1160,  1160,  1161,  1161,  1162,  1162,  1163,  1163,
    1163,  1163,  1163,  1164,  1164,  1165,  1165,  1166,  1166,  1167,
    1168,  1169,  1169,  1170,  1171,  1171,  1171,  1172,  1173,  1173,
    1174,  1174,  1175,  1176,  1176,  1177,  1177,  1178,  1179,  1180,
    1181,  1181,  1182,  1183,  1183,  1184,  1184,  1185,  1185,  1186,
    1187,  1187,  1188,  1188,  1188,  1188,  1189,  1189,  1189,  1190,
    1191,  1191,  1192,  1192,  1192,  1193,  1194,  1194,  1195,  1195,
    1195,  1195,  1195,  1195,  1195,  1195,  1195,  1195,  1195,  1195,
    1195,  1195,  1195,  1195,  1195,  1195,  1195,  1195,  1195,  1195,
    1196,  1197,  1197,  1198,  1198,  1198,  1199,  1201,  1200,  1202,
    1202,  1203,  1204,  1204,  1205,  1205,  1206,  1206,  1208,  1207,
    1209,  1211,  1210,  1212,  1212,  1213,  1213,  1214,  1214,  1215,
    1215,  1215,  1215,  1216,  1216,  1217,  1218,  1218,  1219,  1220,
    1221,  1222,  1223,  1223,  1224,  1224,  1226,  1225,  1227,  1225,
    1228,  1225,  1229,  1225,  1230,  1225,  1231,  1225,  1232,  1225,
    1233,  1233,  1233,  1233,  1233,  1233,  1235,  1234,  1236,  1236,
    1238,  1237,  1237,  1237,  1237,  1237,  1239,  1239,  1240,  1240,
    1241,  1242,  1242,  1243,  1244,  1245,  1246,  1246,  1246,  1247,
    1247,  1247,  1247,  1248,  1249,  1249,  1250,  1250,  1251,  1252,
    1252,  1252,  1252,  1252,  1252,  1252,  1252,  1253,  1253,  1254,
    1254,  1255,  1255,  1255,  1255,  1255,  1255,  1255,  1255,  1255,
    1255,  1256,  1256,  1257,  1257,  1257,  1257,  1258,  1258,  1259,
    1259,  1260,  1260,  1260,  1260,  1260,  1260,  1260,  1260,  1260,
    1260,  1260,  1260,  1260,  1260,  1260,  1260,  1260,  1260,  1260,
    1260,  1260,  1260,  1260,  1260,  1261,  1261,  1261,  1263,  1264,
    1265,  1266,  1267,  1268,  1262,  1269,  1269,  1270,  1271,  1271,
    1273,  1274,  1275,  1276,  1277,  1278,  1272,  1279,  1281,  1282,
    1283,  1280,  1284,  1284,  1284,  1284,  1285,  1285,  1285,  1285,
    1285,  1286,  1287,  1287,  1287,  1288,  1288,  1290,  1291,  1289,
    1292,  1293,  1289,  1294,  1294,  1295,  1295,  1296,  1296,  1297,
    1297,  1297,  1298,  1298,  1299,  1299,  1300,  1300,  1301,  1301,
    1301,  1302,  1302,  1303,  1303,  1303,  1303,  1303,  1303,  1303,
    1304,  1304,  1305,  1305,  1306,  1306,  1307,  1307,  1308,  1308,
    1309,  1310,  1310,  1311,  1311,  1312,  1313,  1313,  1314,  1315,
    1315,  1316,  1316,  1317,  1317,  1318,  1319,  1319,  1319,  1319,
    1319,  1319,  1319,  1319,  1319,  1319,  1319,  1320,  1320,  1321,
    1321,  1322,  1323,  1325,  1324,  1327,  1326,  1326,  1328,  1328,
    1329,  1329,  1330,  1330,  1331,  1331,  1333,  1334,  1332,  1335,
    1336,  1336,  1337,  1338,  1337,  1339,  1340,  1339,  1341,  1341,
    1341,  1341,  1341,  1341,  1341,  1341,  1342,  1343,  1344,  1345,
    1345,  1346,  1347,  1347,  1348,  1348,  1348,  1349,  1350,  1351,
    1351,  1352,  1353,  1353,  1353,  1355,  1354,  1356,  1356,  1356,
    1356,  1356,  1356,  1356,  1356,  1356,  1356,  1356,  1356,  1357,
    1358,  1358,  1359,  1359,  1360,  1360,  1361,  1361,  1361,  1361,
    1362,  1362,  1363,  1363,  1364,  1364,  1365,  1365,  1366,  1367,
    1367,  1368,  1368,  1369,  1369,  1370,  1371,  1372,  1373,  1374,
    1374,  1375,  1375,  1376,  1376,  1377,  1377,  1378,  1378,  1378,
    1379,  1379,  1380,  1381,  1381,  1382,  1382,  1383,  1383,  1384,
    1384,  1384,  1384,  1384,  1385,  1386,  1387,  1388,  1388,  1389,
    1389,  1390,  1391,  1392,  1392,  1393,  1394,  1395,  1395,  1396,
    1396,  1396,  1397,  1397,  1398,  1398,  1399,  1400,  1400,  1401,
    1401,  1402,  1402,  1403,  1403,  1404,  1404,  1405,  1405,  1406,
    1406,  1407,  1407,  1408,  1408,  1409,  1410,  1411,  1411,  1411,
    1411,  1412,  1412,  1413,  1413,  1414,  1414,  1415,  1415,  1415,
    1415,  1415,  1415,  1415,  1415,  1415,  1416,  1416,  1416,  1416,
    1416,  1416,  1416,  1416,  1416,  1417,  1417,  1417,  1418,  1418,
    1418,  1418,  1419,  1419,  1419,  1420,  1420,  1421,  1421,  1421,
    1421,  1421,  1421,  1421,  1421,  1421,  1421,  1421,  1421,  1421,
    1421,  1421,  1421,  1421,  1422,  1422,  1423,  1423,  1423,  1423,
    1423,  1424,  1425,  1426,  1427,  1427,  1427,  1427,  1428,  1428,
    1428,  1428,  1429,  1430,  1430,  1430,  1431,  1431,  1432,  1432,
    1432,  1433,  1434,  1434,  1434,  1434,  1434,  1435,  1436,  1437,
    1437,  1438,  1438,  1439,  1439,  1439,  1439,  1439,  1439,  1439,
    1439,  1440,  1440,  1440,  1440,  1440,  1440,  1440,  1440,  1441,
    1441,  1441,  1441,  1441,  1441,  1441,  1442,  1442,  1442,  1442,
    1442,  1442,  1442,  1442,  1443,  1443,  1443,  1444,  1446,  1445,
    1447,  1445,  1448,  1445,  1449,  1445,  1450,  1450,  1450,  1451,
    1451,  1452,  1452,  1452,  1453,  1453,  1454,  1454,  1455,  1457,
    1458,  1456,  1459,  1460,  1460,  1461,  1462,  1462,  1462,  1462,
    1462,  1463,  1464,  1464,  1465,  1466,  1467,  1467,  1467,  1467,
    1468,  1468,  1469,  1469,  1470,  1471,  1471,  1471,  1472,  1472,
    1472,  1472,  1472,  1473,  1473,  1473,  1473,  1473,  1473,  1473,
    1473,  1473,  1473,  1473,  1473,  1473,  1473,  1473,  1473,  1473,
    1473,  1473,  1473,  1474,  1474,  1475,  1476,  1477,  1477,  1478,
    1478,  1479,  1479,  1480,  1480,  1481,  1481,  1482,  1483,  1483,
    1484,  1484,  1485,  1486,  1486,  1486,  1487,  1487,  1488,  1489,
    1490,  1491,  1492,  1492,  1493,  1493,  1493,  1493,  1493,  1493,
    1494,  1494,  1494,  1496,  1495,  1497,  1497,  1498,  1498,  1498,
    1498,  1498,  1498,  1498,  1498,  1498,  1498,  1498,  1498,  1498,
    1498,  1498,  1498,  1498,  1498,  1498,  1498,  1498,  1498,  1498,
    1498,  1498,  1498,  1498,  1498,  1498,  1498,  1498,  1498,  1498,
    1498,  1498,  1498,  1498,  1498,  1498,  1498,  1498,  1498,  1498,
    1498,  1498,  1498,  1498,  1498,  1498,  1498,  1498,  1498,  1498,
    1498,  1498,  1498,  1498,  1498,  1498,  1498,  1498,  1498,  1498,
    1498,  1498,  1498,  1498,  1498,  1498,  1498,  1498,  1498,  1498,
    1498,  1498,  1498,  1498,  1498,  1498,  1498,  1498,  1498,  1498,
    1498,  1498,  1498,  1498,  1498,  1498,  1498,  1498,  1498,  1498,
    1498,  1498,  1498,  1498,  1498,  1498,  1498,  1498,  1498,  1498,
    1498,  1498,  1498,  1498,  1498,  1498,  1498,  1498,  1498,  1498,
    1498,  1498,  1498,  1498,  1498,  1498,  1498,  1498,  1498,  1498,
    1498,  1498,  1498,  1498,  1498,  1498,  1498,  1498,  1498,  1498,
    1498,  1498,  1498,  1498,  1498,  1498,  1498,  1498,  1498,  1498,
    1498,  1498,  1498,  1498,  1498,  1498,  1498,  1498,  1498,  1498,
    1498,  1498,  1498,  1498,  1498,  1498,  1498,  1498,  1498,  1498,
    1498,  1498,  1498,  1498,  1498,  1498,  1498,  1498,  1498,  1498,
    1498,  1498,  1498,  1498,  1498,  1498,  1498,  1498,  1498,  1498,
    1498,  1498,  1498,  1498,  1498,  1498,  1498,  1498,  1498,  1498,
    1498,  1498,  1498,  1498,  1498,  1498,  1498,  1498,  1498,  1498,
    1498,  1498,  1498,  1498,  1498,  1498,  1498,  1498,  1498,  1498,
    1498,  1498,  1498,  1498,  1498,  1498,  1498,  1498,  1498,  1498,
    1498,  1498,  1498,  1498,  1498,  1498,  1498,  1498,  1498,  1498,
    1498,  1498,  1498,  1498,  1498,  1498,  1498,  1498,  1498,  1498,
    1498,  1498,  1498,  1498,  1498,  1498,  1498,  1498,  1498,  1498,
    1498,  1498,  1498,  1498,  1498,  1498,  1498,  1498,  1498,  1498,
    1498,  1498,  1498,  1498,  1498,  1498,  1498,  1498,  1498,  1498,
    1498,  1498,  1498,  1498,  1498,  1498,  1498,  1498,  1498,  1498,
    1498,  1498,  1498,  1498,  1498,  1498,  1498,  1498,  1498,  1498,
    1498,  1498,  1498,  1498,  1498,  1498,  1498,  1498,  1498,  1498,
    1498,  1498,  1498,  1498,  1498,  1498,  1498,  1498,  1498,  1498,
    1498,  1498,  1498,  1498,  1498,  1498,  1498,  1500,  1499,  1502,
    1501,  1504,  1505,  1503,  1506,  1506,  1506,  1507,  1507,  1507,
    1507,  1507,  1507,  1508,  1508,  1509,  1510,  1511,  1511,  1512,
    1512,  1513,  1513,  1514,  1514,  1514,  1515,  1515,  1515,  1515,
    1515,  1515,  1515,  1515,  1515,  1515,  1516,  1516,  1516,  1516,
    1516,  1516,  1516,  1516,  1516,  1516,  1516,  1516,  1516,  1516,
    1517,  1518,  1518,  1520,  1519,  1521,  1521,  1522,  1522,  1523,
    1524,  1524,  1525,  1525,  1525,  1525,  1526,  1526,  1526,  1527,
    1527,  1529,  1530,  1528,  1531,  1531,  1532,  1532,  1533,  1533,
    1533,  1533,  1533,  1533,  1533,  1534,  1535,  1535,  1536,  1536,
    1537,  1537,  1538,  1538,  1539,  1540,  1541,  1542,  1542,  1543,
    1544,  1544,  1545,  1546,  1546,  1548,  1547,  1549,  1549,  1549,
    1549,  1549,  1549,  1549,  1549,  1549,  1549,  1549,  1549,  1549,
    1549,  1549,  1549,  1549,  1549,  1549,  1549,  1549,  1549,  1549,
    1549,  1549,  1549,  1549,  1549,  1549,  1549,  1549,  1549,  1549,
    1549,  1549,  1549,  1549,  1549,  1549,  1549,  1549,  1549,  1549,
    1549,  1549,  1549,  1549,  1549,  1549,  1549,  1549,  1549,  1549,
    1549,  1549,  1549,  1549,  1549,  1549,  1549,  1549,  1549,  1549,
    1549,  1549,  1549,  1549,  1549,  1549,  1549,  1549,  1549,  1549,
    1549,  1549,  1549,  1549,  1549,  1549,  1549,  1549,  1549,  1549,
    1549,  1549,  1549,  1549,  1549
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const unsigned char yyr2[] =
{
       0,     2,     1,     1,     5,     1,     1,     1,     1,     3,
       1,     3,     3,     1,     2,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     0,     1,     0,     5,     6,     1,
       3,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     0,     1,
       0,     5,     1,     3,     1,     1,     2,     2,     2,     2,
       2,     2,     2,     2,     3,     0,     7,     8,     6,     1,
       6,     0,     0,     9,     0,     0,     0,     8,     0,     0,
      10,     0,     0,     9,     0,     0,     0,    14,     0,     2,
       0,     2,     1,     0,     1,     1,     3,     1,     1,     1,
       1,     3,     0,     6,     0,     5,     1,     2,     1,     2,
       1,     0,     0,     3,     0,     0,     3,     0,     4,     0,
       4,     2,     2,     2,     1,     2,     2,     3,     1,     1,
       1,     2,     1,     1,     2,     1,     1,     0,     0,     5,
       7,     8,     0,     2,     1,     3,     1,     3,     3,     1,
       2,     0,     4,     0,     4,     0,     3,     0,     3,     0,
       3,     1,     3,     1,     3,     1,     1,     1,     1,     1,
       1,     4,     0,     4,     1,     1,     0,     1,     1,     2,
       0,     0,     5,     1,     1,     3,     0,     2,     4,     4,
       4,     4,     2,     0,     4,     1,     1,     1,     2,     1,
       1,     3,     0,     1,     0,     1,     1,     1,     0,     7,
       0,     5,     0,    12,     1,     1,     1,     1,     1,     5,
       3,     1,     1,     0,     4,     0,     5,     0,     7,     1,
       3,     1,     1,     0,     1,     0,     0,     4,     1,     1,
       1,     4,     4,     6,     1,     2,     1,     1,     1,     1,
       4,     6,     1,     4,     6,     1,     1,     1,     1,     1,
       1,     1,     2,     2,     1,     1,     4,     1,     1,     0,
       3,     3,     0,     2,     1,     1,     1,     1,     1,     1,
       2,     0,     2,     0,     3,     0,     3,     1,     0,     3,
       1,     1,     1,     1,     1,     1,     2,     1,     0,     1,
       0,     5,     1,     1,     1,     4,     4,     6,     1,     1,
       1,     1,     4,     6,     1,     4,     6,     1,     1,     1,
       1,     1,     2,     2,     1,     4,     0,     7,     0,    12,
       0,     4,     0,     5,     1,     3,     2,     1,     3,     1,
       0,     2,     2,     1,     2,     5,     4,     2,     4,     5,
       3,     0,     0,    11,     0,     2,     1,     0,     2,     1,
       1,     2,     0,     3,     0,     3,     0,     3,     2,     2,
       2,     4,     5,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     2,     1,     1,     1,     1,     2,     1,     1,     1,
       2,     2,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     2,     1,     2,     1,     1,     1,     3,     1,
       3,     1,     3,     1,     1,     1,     2,     1,     1,     3,
       4,     4,     2,     2,     1,     1,     1,     1,     1,     3,
       1,     2,     2,     1,     0,     3,     2,     2,     1,     3,
       4,     4,     5,     5,     1,     1,     2,     2,     4,     4,
       2,     2,     4,     4,     1,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     0,
       0,     0,     6,     0,     0,     8,     0,     0,     6,     0,
       0,     6,     0,     0,     6,     0,     0,     6,     5,     5,
       5,     7,     4,     6,     0,     3,     1,     1,     4,     4,
       4,     4,     4,     4,     1,     1,     1,     1,     4,     4,
       2,     2,     2,     2,     2,     1,     1,     2,     1,     1,
       1,     2,     4,     6,     6,     3,     5,     5,     3,     1,
       1,     3,     1,     3,     0,     0,    11,     0,     2,     0,
       0,     0,     9,     0,     3,     0,     0,    10,     0,     1,
       0,     1,     1,     2,     0,     3,     0,     3,     0,     1,
       1,     2,     0,     3,     0,     3,     3,     1,     4,     3,
       1,     3,     1,     3,     1,     3,     1,     2,     0,     3,
       0,     3,     0,     4,     0,     4,     0,     4,     2,     3,
       1,     3,     1,     1,     1,     1,     1,     1,     1,     3,
       1,     1,     4,     6,     4,     3,     6,     3,     6,     1,
       1,     1,     1,     1,     1,     0,     2,     1,     1,     1,
       4,     1,     1,     1,     4,     3,     6,     3,     6,     1,
       1,     2,     2,     1,     2,     2,     1,     3,     1,     2,
       2,     2,     4,     2,     2,     4,     0,     8,     0,     1,
       1,     1,     0,     1,     2,     0,     1,     2,     0,     1,
       2,     0,     1,     3,     0,     2,     0,     0,     8,     0,
       0,     3,     0,     0,     7,     5,     2,     2,     0,     5,
       4,     1,     3,     3,     3,     0,     2,     1,     0,     1,
       1,     2,     0,     4,     0,     4,     0,     3,     0,     3,
       0,     3,     0,     3,     0,     3,     0,     3,     0,     3,
       0,     3,     0,     3,     1,     3,     1,     3,     2,     4,
       1,     1,     1,     0,     4,     5,     6,     0,    10,     3,
       2,     2,     1,     1,     0,     2,     1,     2,     3,     3,
       3,     3,     1,     1,     1,     1,     0,     3,     1,     0,
       3,     2,     2,     1,     3,     1,     3,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     0,     0,     7,
       1,     1,     2,     2,     2,     3,     4,     0,     3,     0,
       1,     1,     2,     1,     1,     1,     1,     0,     1,     1,
       2,     2,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     0,     1,     1,     1,     1,     0,     0,
       0,     0,    13,     1,     0,     0,     6,     2,     1,     2,
       2,     2,     1,     1,     2,     1,     1,     1,     0,     3,
       2,     1,     0,     0,     0,    14,     0,     5,     1,     0,
       3,     0,     7,     0,     5,     1,     2,     0,     1,     1,
       1,     0,     1,     1,     2,     2,     2,     1,     1,     1,
       1,     3,     1,     1,     0,     0,     7,     1,     2,     0,
       3,     0,     4,     2,     0,     2,     1,     1,     1,     1,
       1,     1,     1,     3,     0,     1,     1,     1,     1,     2,
       2,     2,     5,     8,     1,     1,     1,     4,     4,     1,
       1,     1,     1,     2,     2,     3,     6,     1,     3,     1,
       1,     1,     3,     6,     9,     1,     1,     1,     1,     2,
       0,     1,     1,     3,     1,     3,     1,     3,     1,     3,
       1,     1,     1,     1,     3,     1,     3,     1,     3,     1,
       1,     1,     3,     2,     0,     1,     1,     4,     1,     3,
       1,     3,     7,     0,     7,     0,     6,     3,     1,     3,
       1,     2,     5,     0,     7,     0,     2,     0,     1,     5,
       2,     5,     0,     5,     6,     4,     0,     1,     1,     4,
       0,     2,     0,     5,     4,     2,     1,     3,     2,     2,
       2,     2,     2,     2,     1,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     1,     1,     1,     1,     1,     1,
       5,     1,     1,     2,     4,     2,     1,     0,    11,     0,
       2,     5,     0,     1,     0,     2,     1,     2,     0,     3,
       1,     0,     4,     0,     2,     1,     3,     1,     1,     3,
       4,     4,     2,     1,     1,     1,     0,     1,     7,     2,
       2,     2,     2,     2,     1,     2,     0,     3,     0,     3,
       0,     3,     0,     3,     0,     3,     0,     4,     0,     4,
       1,     1,     1,     1,     1,     1,     0,     4,     0,     1,
       0,     4,     1,     2,     2,     2,     0,     1,     1,     2,
       2,     0,     2,     3,     3,     5,     0,     2,     4,     1,
       1,     1,     1,     1,     0,     1,     1,     3,     2,     5,
       2,     5,     5,     5,     5,     5,     5,     0,     2,     1,
       2,     2,     2,     2,     2,     2,     1,     2,     2,     2,
       2,     1,     2,     2,     2,     2,     1,     1,     1,     0,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     1,
       1,     1,     1,     1,     1,     1,     1,     2,     2,     2,
       2,     2,     1,     1,     1,     0,     3,     2,     0,     0,
       0,     0,     0,     0,    15,     0,     2,     2,     0,     1,
       0,     0,     0,     0,     0,     0,    15,     2,     0,     0,
       0,    10,     0,     1,     3,     3,     2,     4,     3,     3,
       3,     1,     1,     1,     1,     1,     1,     0,     0,     7,
       0,     0,     8,     7,     2,     0,     1,     1,     3,     2,
       2,     1,     1,     3,     1,     1,     2,     1,     3,     3,
       3,     1,     3,     1,     1,     1,     1,     1,     1,     1,
       2,     4,     1,     3,     1,     3,     2,     4,     1,     3,
       1,     2,     4,     1,     3,     1,     1,     1,     2,     2,
       4,     2,     4,     1,     3,     1,     1,     1,     2,     1,
       1,     1,     1,     1,     2,     6,     6,     0,     1,     0,
       1,     2,     1,     0,     5,     0,     5,     1,     0,     3,
       1,     3,     1,     3,     1,     1,     0,     0,     5,     1,
       2,     1,     0,     0,     3,     0,     0,     3,     1,     1,
       1,     1,     1,     1,     2,     2,     4,     3,     3,     1,
       3,     2,     1,     1,     0,     1,     1,     1,     1,     0,
       1,     3,     1,     3,     1,     0,     3,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     7,
       0,     1,     1,     1,     1,     3,     1,     1,     1,     2,
       0,     3,     1,     3,     1,     3,     1,     1,     6,     0,
       3,     1,     3,     0,     1,     4,     5,     2,     1,     1,
       4,     1,     3,     4,     4,     1,     3,     1,     1,     1,
       2,     1,     4,     0,     1,     0,     1,     1,     2,     1,
       1,     1,     1,     4,     3,     1,     1,     1,     2,     1,
       1,     2,     2,     1,     3,     2,     2,     1,     3,     1,
       2,     4,     1,     2,     1,     3,     4,     0,     1,     0,
       1,     0,     1,     1,     3,     1,     3,     1,     2,     1,
       3,     2,     2,     0,     2,     1,     1,     5,     3,     5,
       3,     1,     3,     1,     1,     0,     1,     3,     3,     3,
       6,     4,     4,     4,     4,     5,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     0,     1,
       1,     1,     1,     1,     1,     1,     4,     5,     1,     5,
       5,     1,     1,     1,     4,     1,     4,     1,     7,     1,
       1,     1,     4,     6,     0,     2,     4,     1,     1,     1,
       1,     1,     1,     1,     3,     1,     1,     3,     3,     1,
       1,     3,     1,     0,     3,     5,     1,     2,     2,     4,
       3,     1,     1,     1,     1,     1,     1,     2,     2,     0,
       3,     0,     3,     1,     1,     1,     1,     1,     1,     1,
       4,     1,     1,     1,     1,     1,     1,     1,     4,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     4,     1,     3,     1,     3,     0,     7,
       0,     8,     0,     6,     0,     8,     0,     1,     2,     1,
       3,     1,     3,     5,     1,     1,     1,     1,     1,     0,
       0,     9,     5,     1,     1,     6,     0,     3,     1,     3,
       4,     1,     0,     2,     4,     6,     0,     1,     1,     1,
       1,     3,     1,     2,     1,     1,     2,     2,     1,     1,
       1,     2,     4,     3,     2,     3,     3,     3,     1,     1,
       1,     1,     1,     1,     5,     5,     5,     5,     5,     4,
       4,     3,     4,     1,     3,     1,     5,     7,     5,     0,
       2,     1,     1,     0,     3,     1,     3,     1,     1,     1,
       0,     3,     1,     1,     1,     1,     4,     6,     1,     1,
       2,     3,     1,     1,     1,     1,     1,     1,     1,     1,
       5,     5,     4,     0,     4,     1,     2,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     0,     3,     0,
       3,     0,     0,     6,     0,     2,     2,     7,     3,     3,
       2,     2,     2,     1,     3,     1,     3,     1,     3,     1,
       3,     1,     1,     1,     2,     2,     1,     1,     2,     4,
       1,     1,     1,     1,     1,     1,     3,     2,     3,     3,
       3,     5,     5,     5,     5,     5,     4,     4,     3,     4,
       1,     1,     3,     0,     5,     1,     3,     3,     3,     1,
       2,     1,     1,     1,     3,     5,     1,     1,     1,     1,
       3,     0,     0,     6,     0,     2,     0,     1,     1,     2,
       2,     1,     1,     4,     3,     1,     1,     2,     5,     2,
       2,     5,     0,     2,     1,     1,     2,     6,     6,     1,
       0,     1,     2,     1,     2,     0,     2,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const unsigned short yydefact[] =
{
     799,     0,     0,     0,     0,   848,   180,     0,   822,   825,
     178,   183,   803,     0,   797,   800,   801,   804,   806,   847,
     805,   842,   843,   845,   135,   132,     0,   128,   130,   129,
     133,  2139,   687,   627,   300,  1596,  1594,   840,   176,   186,
     841,   179,     1,   807,   802,   846,   844,   127,   131,   134,
       0,     0,   606,     0,     0,   177,   851,   915,   607,   849,
     639,   907,     0,   908,   916,   914,   186,   181,   199,     0,
     184,   200,   235,     0,   827,  1200,     0,     0,   826,   136,
    1188,   834,     0,     0,   819,   821,   818,   820,   798,   808,
     809,   828,   812,   813,   814,   817,   815,   816,     0,  1595,
     909,   850,     0,     0,   923,   921,   922,   911,   910,   298,
     186,  1124,   193,   187,   186,   192,   232,     0,   686,     0,
       0,     0,     0,   176,   555,   884,   810,     0,   332,   318,
     202,   304,   269,   288,   309,   311,   308,     0,   330,     0,
     317,   310,   314,   320,   319,   186,   321,   301,   324,   302,
     303,   920,   919,     0,    22,    23,    13,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   929,     0,   515,   507,
      16,   514,   915,    15,     0,   927,     0,   299,     0,   185,
    1125,   182,     0,   199,   201,   265,   204,   259,   260,   248,
     225,   256,   202,   240,   227,   269,   288,   246,   249,   244,
       0,   223,     0,   255,   247,   252,   258,   257,   186,   261,
     186,   238,   239,   236,   264,     0,     0,     0,     0,   835,
     176,   176,     0,     0,   203,     0,     0,   322,     0,     0,
     323,     0,     0,     0,     0,     0,     0,     0,   267,     0,
     917,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   521,     0,     0,     0,   640,   434,   436,
    1195,     0,     0,     0,  1561,     0,   428,     0,     0,     0,
     427,     0,   444,   517,     0,     0,     0,     0,     0,   520,
       0,   393,   392,   399,   440,   437,   394,   395,   397,   398,
     435,   438,   443,   516,   489,   486,   495,   492,     0,     0,
      17,    18,    19,    20,    21,     0,    14,   480,     0,     0,
     925,     0,   188,   191,   189,   190,     0,   196,   195,   194,
     197,   205,   206,   207,   210,   186,     0,     0,   186,   262,
     263,     0,     0,   186,     0,     0,     0,   245,   233,  1201,
       0,     0,  1189,  2145,   556,   885,   829,     0,   214,   215,
       0,     0,   281,   283,   278,   279,   275,   277,   274,   276,
     273,     0,   283,   294,   295,   291,   293,   290,   292,   285,
       0,     0,     0,   334,     0,   337,   339,   222,     0,   221,
       0,   186,     0,  2125,   542,   611,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   539,   525,   530,     0,   526,
     529,   528,     0,     0,    11,   172,   426,   401,   400,     0,
    1130,     0,     0,   442,  1569,  1567,  1568,  1564,  1566,  1563,
    1565,  1557,     0,     0,     0,   441,     0,     0,     0,     0,
       0,     0,     0,   641,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   165,   166,   167,   168,   169,   170,   522,   523,   524,
     455,     0,     0,   454,   464,     0,     0,   405,     0,     0,
     406,   396,   402,   404,   407,   408,   409,   410,   411,   403,
     433,   432,     0,     0,     0,     0,     0,     0,     0,    12,
      93,     0,   928,     0,   912,   198,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   186,   234,   237,   940,
     685,   852,   940,     0,  2143,  2145,  1124,  1690,   823,     0,
     940,     0,     0,   305,   270,     0,     0,   280,   297,   271,
     296,     0,   289,     0,   312,     0,   306,     0,   331,     0,
     336,   326,     0,     0,   315,   268,   325,     0,     0,     0,
       0,   513,   510,   509,   512,   508,   519,   504,   504,     0,
     527,     0,   531,     0,   288,   511,   518,   272,     0,  1196,
    1636,     0,     0,     0,     0,     0,   429,     0,     0,   445,
       0,     0,     0,     0,   447,   446,   465,   456,   471,   474,
     475,   472,   478,   477,   476,   466,   467,   468,   469,   470,
     412,   457,   461,   479,   473,   460,   479,   439,   490,   487,
     496,   493,   502,     0,   481,    94,    95,    97,   483,     0,
       0,   235,     0,     0,   241,     0,     0,   250,     0,   242,
     224,   208,     0,   253,   266,   946,     0,   941,   942,   940,
       0,   836,  2144,  2142,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  2126,     0,  1292,
    1291,     0,  1293,     0,   386,  1290,  1230,     0,     5,  1289,
     387,   384,     0,   389,   174,   479,  1102,     0,     0,  1299,
     124,   383,   382,  1222,   377,   479,     0,  1247,  2118,     0,
     388,   351,     0,     3,     2,     0,   385,  1227,     0,     0,
     378,   375,   390,     0,     0,     0,     0,  1297,  1287,   381,
       0,     0,     0,     0,     0,     0,     0,     0,  1286,     0,
       0,     0,   175,  1224,   374,   373,     0,     0,  2122,  2121,
       0,     0,     0,   137,  1223,   380,   379,     0,     0,   376,
     479,     0,   479,     0,   549,     0,     0,     0,     0,     0,
       0,   479,   786,  1198,     0,     0,  1106,     0,  2111,     0,
     104,     0,     0,   856,     0,     0,     0,     0,   787,     0,
       0,  1713,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   656,     0,     0,  2147,  2148,  2149,  2150,  2151,  2152,
    2153,  2154,  2155,  2156,  2157,  2158,  2159,  2160,  2161,  2162,
    2163,  2164,  2165,  2166,  2167,  2168,  2169,  2170,  2171,  2172,
    2173,  2174,  2175,  2176,  2177,  2178,  2179,  2180,  2181,  2182,
    2183,  2184,  2185,  2186,  2187,  2188,  2189,  2190,  2191,  2192,
    2193,  2194,  2195,  2196,   894,  2197,  2198,  2199,  2200,  2201,
    2202,  2203,  2204,  2205,  2206,  2207,  2208,  2209,  2210,  2211,
    2212,  2213,  1093,  1095,  1090,  1092,  1091,  1094,  2214,  2215,
    1221,  2216,  1226,  1225,  2217,  2218,  2219,  2220,  2221,  2222,
    2223,  2224,  2225,  2226,  1355,  2227,  2228,  2229,  2230,  2231,
    2232,  2233,  2234,  2146,   824,   560,     0,   889,     0,   887,
       0,   333,   216,   217,     0,   282,   287,     0,     0,     0,
       0,   335,   338,     0,   220,     0,     0,   543,     0,   615,
       0,   617,   499,     0,   500,     0,   541,     0,   538,   535,
     506,   498,     0,   171,  1638,  1639,  1637,     0,   431,  1195,
       0,  1562,  1195,   430,  1195,  1195,  1195,  1195,  1195,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    93,   926,     0,   211,   226,     0,
     186,     0,     0,     0,     0,     0,  1202,     0,     0,  1190,
     370,   368,   369,  1032,  1031,  1035,     0,  1539,  1540,     0,
       0,  1234,   628,   629,   811,  1065,  1070,  2120,   621,   123,
       0,     0,  2103,  2102,  1000,  2099,  2101,  2134,     0,     0,
    1246,     7,     0,     6,     0,  2127,  1066,     0,  1158,  1157,
    1105,  1156,  1104,   423,  1300,  1288,   837,   413,  1692,  1294,
     125,     0,  1069,   122,     0,   793,    24,   623,   391,     0,
     792,  1062,   794,     0,  1298,   878,   877,   880,   876,   879,
    2136,     0,   874,     0,   622,   973,   875,  2130,     0,  2119,
     121,   970,   688,   968,     0,   619,  2114,   731,   730,   732,
     728,     0,     0,   983,   624,  1354,  1349,  1352,     0,     0,
       0,  1036,  1033,     0,  1027,  1029,  1028,  1026,  1025,     0,
       0,     0,  1024,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1014,  1005,  1006,     0,
    1050,   421,    24,     0,  2116,   126,   620,     0,  1199,  1197,
    1123,     0,  1681,  1682,  1124,  1212,  1124,  1107,  1108,  1111,
    1126,  1301,     0,     0,     0,     0,     0,     0,     0,     0,
      63,     0,   915,     0,    69,     0,   102,   598,     0,   643,
     642,     0,  1096,   990,  1100,     0,     0,  1051,  1216,     0,
       0,  1103,   648,   645,   646,     0,   650,   651,     0,   653,
     654,     0,   649,   950,   952,     0,     0,   951,   733,   948,
     698,   944,   906,     0,     0,     0,     0,   660,   661,     0,
       0,   904,   901,   902,   898,   899,   900,   893,   897,   896,
       0,     0,     0,     0,     0,     0,   564,   566,   558,   561,
     562,   891,  2145,   886,   888,   830,     0,   284,   286,   313,
     307,     0,     0,   316,   612,   614,     0,     0,   504,   532,
       0,   281,     0,     0,  1662,  1552,  1555,  1663,  1559,  1553,
    1660,     0,     0,  1659,     0,     0,  1661,     0,     0,     0,
       0,     0,  2103,  1554,  1658,  1556,  1650,     0,  1640,  1642,
    1645,  1648,  2109,  1649,  1133,  1570,  1132,  1131,  1134,  1136,
    1135,  1129,   458,   459,   463,   448,     0,   451,   462,     0,
     450,   491,   488,   497,   494,   503,   482,    96,   484,   913,
       0,   231,     0,   229,   251,   243,   235,   254,   947,   176,
     943,   853,   176,     0,     0,     0,  1276,  1277,     0,     0,
       0,  1248,  1251,  1253,  1254,  1255,  1259,  1258,  1256,  1257,
       0,     0,  1249,  1250,     0,     0,  2100,   924,     0,  1002,
       0,     0,     0,     0,  1535,  1536,     0,  1067,     0,    24,
    1153,  1155,  1154,   416,   417,   414,   415,   960,     0,     0,
     356,    25,   350,     0,     0,  1059,     0,     0,     0,     0,
       0,     0,     0,   977,  1691,     0,     0,   186,     0,     0,
       0,  2116,     0,     0,   138,     0,     0,   987,   979,   980,
     985,  1350,  1351,     0,   903,   419,  2093,   340,     0,   550,
     603,   602,   600,   605,  1008,   604,  1013,  1009,  1012,   785,
     777,   771,   783,   784,   769,   770,   778,   773,   779,   772,
     782,   776,   780,   775,   781,   768,   774,   761,   767,  1010,
    1011,     0,  1018,  1022,  1015,  1016,  1020,  1021,  1019,  1017,
    1023,     0,   795,     0,     0,     0,     0,     0,   743,   742,
     739,  2117,  2124,    24,  1119,  1120,  1121,  1122,  1116,  1114,
    1213,  1128,  1113,  1109,     0,     0,  1110,  2112,     0,     0,
       0,     0,    98,     0,    99,     0,     0,     0,    74,     0,
       0,     0,   111,   106,     0,   644,   883,     0,   882,     0,
     479,  1098,     0,   935,   936,   959,   930,   931,   788,   957,
    1053,  1218,     0,  1220,  1219,  1769,  1886,  1882,  1888,  1920,
    1900,  1891,  1850,  1812,  1940,  1906,  1914,  1803,  1909,  1770,
    1717,  1901,  1808,  1859,  1994,  1838,  1826,  1839,  1938,  1941,
    1908,  1862,  1944,  1729,  2001,  1937,  1965,  1740,  2037,  1827,
    2010,  1722,  1970,  1738,  1798,  1845,  1865,  1960,  1988,  1993,
    1721,  1917,  1946,  1733,  1735,  1758,  1776,  1796,  1806,  1816,
    1869,  1872,  1931,  1942,  1948,  1949,  1966,  2011,  2022,  1720,
    1751,  1775,  1774,  1782,  1784,  1792,  1802,  1823,  1841,  1844,
    1870,  1878,  1935,  1945,  1955,  1961,  1962,  1964,  1989,  2019,
    2030,  1741,  1744,  1755,  1761,  1763,  1768,  1771,  1773,  1779,
    1787,  1789,  1790,  1791,  1801,  1811,  1818,  1834,  1835,  1846,
    1864,  1868,  1881,  1897,  1921,  1929,  1939,  1943,  1950,  1958,
    1967,  1977,  1981,  1998,  2004,  2008,  2016,  2021,  2024,  1764,
    1883,  1926,  1749,  1750,  1767,  1772,  1778,  1780,  1794,  1795,
    1805,  1814,  1819,  1821,  1822,  1828,  1836,  1853,  1854,  1867,
    1895,  1899,  1902,  1907,  1911,  1919,  1927,  1928,  1933,  1951,
    1952,  1957,  1963,  1968,  1974,  1975,  1976,  1978,  1980,  1982,
    1991,  2013,  2014,  2015,  2020,  2036,  1724,  1877,  1885,  1887,
    1984,  1726,  1730,  1734,  1739,  1745,  1746,  1759,  1760,  1762,
    1765,  1777,  1793,  1813,  1815,  1825,  1829,  1831,  1832,  1840,
    1849,  1851,  1852,  1863,  1876,  1894,  1912,  1913,  1930,  1932,
    1936,  1947,  1969,  1979,  1987,  2009,  2012,  2026,  2027,  2028,
    1757,  1727,  1747,  1748,  1754,  1824,  1756,  1781,  1783,  1797,
    1874,  1999,  1807,  1809,  1817,  1820,  1842,  1843,  1848,  1855,
    1856,  1857,  2039,  1889,  1890,  1893,  1898,  1903,  1910,  1915,
    1916,  1918,  1925,  1954,  1956,  1972,  1983,  1985,  1986,  1990,
    1995,  1996,  2000,  2002,  2003,  2018,  2023,  2025,  2029,  2031,
    2035,  1884,  2034,  1723,  1725,  1728,  1732,  1742,  1766,  1785,
    1786,  1788,  1799,  1830,  1833,  1873,  1879,  1892,  1896,  2032,
    2033,  1934,  1953,  1959,  1971,  1973,  1992,  1997,  2007,  2017,
    1737,  1731,  1736,  1753,  1804,  1847,  1860,  1861,  1922,  1924,
    2006,  1880,  1837,  1904,  1752,  1800,  1810,  1875,  1858,  1905,
    1743,  1866,  1871,  2005,  1923,     0,  1715,  1718,  1719,   676,
       0,     0,     0,   665,   698,   698,   695,     0,     0,   699,
       0,    26,   664,   667,     0,   674,   670,   905,   895,  1688,
    1689,  1679,  1679,  1319,     0,     0,  1597,     0,   186,  1302,
       0,     0,  1303,  1347,   186,     0,  1348,     0,  1636,     0,
    1316,     0,  1366,  1365,  1364,  1362,  1363,  1361,  1359,  1356,
    1430,  1429,  1357,  1358,  1367,  1618,  1360,  1695,  1694,  1693,
    1368,  2145,  2145,   577,   568,   559,     0,   563,  2145,   890,
     176,     0,   327,   219,     0,     0,  1577,  1575,  1576,  1572,
    1574,  1571,  1573,   505,   501,     0,   537,   536,   173,  1647,
    1646,  1585,  1583,  1584,  1580,  1582,  1579,  1581,  1558,     0,
    1636,     0,     0,  1498,     0,  1498,  1498,  1498,  1498,  1651,
       0,     0,     0,  1447,  1626,  1643,     0,     0,     0,     0,
    1704,  1705,  1706,  1707,  1708,  1709,  1654,     0,     0,   453,
     452,     0,     0,   186,   228,   209,  1203,   176,  1191,  1420,
       0,  1419,     0,  1421,     0,  1422,  1279,     0,  1285,  1281,
    1278,     0,     0,     0,     0,     0,     0,  1275,  1271,  1409,
    1408,  1407,  1245,  1244,     0,  1270,  1266,     0,  1262,  1260,
       0,  1538,  1541,   632,     0,   631,     0,  1001,     0,     0,
     999,  2106,  2108,  2107,  2104,  2135,  2132,     0,     0,     0,
       0,  1231,   479,   348,     0,     0,  1228,   992,  1063,  1064,
    1061,  1060,     0,   881,     0,     0,   608,     0,     0,     0,
     971,   969,     0,   690,   691,     0,     0,  2115,  2123,   729,
       0,   142,     0,   981,   988,     0,     0,   996,  1353,     0,
     186,   343,     0,     0,     0,     0,    24,  1034,   553,     0,
       0,     0,   762,   763,  1007,   796,   422,     0,  1042,   740,
     741,   371,     0,  1124,     0,  1127,  1112,  2145,     0,     0,
       0,     0,     0,     0,     0,    64,    93,     0,     0,   117,
     112,     0,   107,     0,   114,   108,   867,   859,   865,     0,
    1097,     0,  1099,  1101,     0,     0,   939,     0,     0,     0,
       0,  1052,  1217,     0,     0,  1714,  1716,  2145,   647,   652,
     655,   668,   666,   625,     0,   718,   716,   722,   720,     0,
       0,   714,   758,   712,   697,   708,   706,   756,   734,     0,
     700,   710,   949,   945,     0,     0,     0,     0,   673,     0,
       0,     0,     0,     0,     0,     0,  1542,     0,  1425,  1426,
    1700,  1389,  1447,     0,     0,  1698,     0,     0,  1619,  2041,
       0,  1372,  1378,  1377,  1376,  1380,     0,  1373,  1374,   565,
     567,     0,     0,   580,   572,   574,     0,   569,   570,     0,
       0,   588,   590,     0,     0,   586,   892,   831,   218,     0,
     616,   618,   613,     0,   534,   533,     0,     0,  1671,     0,
       0,     0,  1500,  1501,  1499,     0,  1673,     0,     0,     0,
       0,     0,     0,     0,  1641,     0,  1436,  1437,  1439,  1442,
       0,  1448,  1449,     0,     0,  1498,  1628,  1622,  1656,  1657,
    1655,  1653,  2110,   449,   485,     0,   230,  1159,   854,  1137,
    1397,  1399,     0,  1283,     0,     0,     0,     0,     0,  1273,
       0,     0,  1530,  1528,  1505,  1515,  1517,  1513,     0,  1512,
       0,  1521,  1508,  1529,     0,  1520,  1511,  1527,  1519,  1413,
    1502,  1503,  1504,     0,  1268,  1264,     0,     0,  1252,   630,
       0,     0,     0,     0,     0,  2131,     0,     4,     8,    10,
    1534,  1537,     0,   479,   418,     0,     0,     0,   989,     0,
       0,     0,     0,     0,     0,     0,   186,   689,     0,     0,
     159,   157,     0,     0,   139,     0,   149,   155,   698,   144,
     146,     0,   986,   997,   998,     0,   420,     0,  2094,  2095,
     342,   347,   610,   341,     0,   344,   349,   479,  1325,   601,
     599,     0,   765,  1041,  1043,     0,   372,  1117,  1115,  1214,
    1215,     0,     0,  1208,     0,     0,     0,   100,     0,     0,
      75,    81,    71,  2145,  2145,   110,   105,   119,   115,     0,
     109,   759,   868,   625,  2145,   858,   857,   866,   991,     0,
       0,   937,   938,   932,   958,   479,  1058,  1054,  1055,  1057,
    2038,   955,  2040,   953,   677,   671,   669,     0,    24,     0,
    2145,  2145,  2145,  2145,   724,   702,   726,   704,  2145,  2145,
    2145,  2145,     0,   696,   701,  2145,   625,   754,   752,   755,
     753,     0,     0,    46,    44,    41,    35,    39,    43,    38,
      31,    40,     0,    34,    37,    32,    42,    33,    45,    36,
       0,    29,    47,   746,     0,   675,  1680,     0,  1678,  1636,
    1676,  1623,  1624,  1616,  1602,  1617,     0,     0,     0,  1030,
    1424,  1427,     0,     0,     0,  1337,  1308,  1703,  1702,  1701,
       0,     0,     0,     0,  1332,     0,  1331,     0,  1333,  1328,
    1329,  1330,  1321,  1317,     0,     0,  1379,     0,     0,   579,
     584,     0,     0,  2145,  2145,   557,   571,   594,   582,   596,
    2145,  2145,   592,   576,   587,   823,   328,     0,  1592,  1590,
    1591,  1587,  1589,  1586,  1588,  1560,     0,     0,     0,  1672,
       0,     0,     0,  1670,     0,     0,     0,     0,  1652,  1669,
       0,  1440,     0,  1551,  1443,     0,     0,     0,     0,  1435,
    1453,  1455,  1457,  1497,  1496,  1495,  1459,  1475,     0,  1450,
    1451,  1631,  1235,     0,     0,     0,   212,     0,  1185,  1204,
     823,     0,  1192,  1185,     0,     0,  1280,     0,  1282,     0,
    1543,     0,  1398,     0,  1401,  1546,     0,  1405,     0,  1272,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1411,     0,  1414,  1415,     0,  1267,     0,  1261,  1263,  2105,
       0,     0,     0,  2133,  1241,     0,  1237,     0,     0,  1242,
     838,     0,     0,     0,     0,     0,  1295,  2138,  2137,   609,
       0,     0,    48,     0,   694,   693,   692,  1296,   698,  2145,
    2145,   151,   633,   161,   153,   163,   143,   150,  2145,     0,
       0,     0,     0,     0,     0,   186,     0,     0,  1326,   551,
       0,   764,  1039,     0,  2113,     0,    93,     0,    65,     0,
       0,     0,    78,     0,    93,    93,   118,   113,  2145,  2145,
     103,     0,   869,   863,   871,   870,   860,   547,   918,     0,
       0,     0,     0,     0,   679,   658,   672,   626,   735,     0,
     719,   717,   723,   721,     0,  2145,     0,  2145,   715,   713,
     709,   707,   757,   711,    24,   747,     0,     0,     0,    27,
       0,  1683,     0,  1603,     0,     0,  1615,  1598,  1614,  1428,
       0,  1391,     0,  1336,     0,     0,  1699,     0,  1696,  1620,
       0,     0,     0,     0,     0,     0,  2042,  1335,  1334,  1322,
    1320,     0,  1382,     0,  1375,     0,   581,   578,   573,   575,
       0,  2145,  2145,   589,   591,  2145,  2145,     0,  1578,     0,
       0,     0,     0,     0,  1668,  1674,  1664,  1665,  1666,  1667,
    1444,     0,  1438,  1458,     0,  1462,     0,  1475,  1461,     0,
       0,  1476,  1491,  1488,  1489,  1486,  1494,  1493,  1487,  1490,
       0,     0,     0,     0,     0,  1492,     0,     0,     0,  1432,
    1433,  1644,     0,  1452,  1446,  1236,  1629,  1342,  1338,  1339,
    1344,  1343,  1627,  1235,     0,  1183,  1184,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1182,     0,
       0,  1170,  1171,  1172,  1169,  1174,  1175,  1176,  1173,  1160,
    1151,     0,     0,  1207,     0,  2145,     0,  1146,     0,     0,
       0,     0,     0,     0,     0,  1138,  1139,     0,  1071,     0,
    1284,  1423,  1547,     0,  1548,     0,     0,     0,     0,  1404,
    1274,  1403,  1395,  1531,     0,     0,     0,     0,  1532,  1524,
    1524,     0,     0,  1524,  1552,  1410,  1412,  1416,  1417,  1269,
    1265,  1004,     0,   967,  1240,  1239,     0,  1233,     9,     0,
    1235,   839,  1068,   354,  1229,     0,     0,  2129,     0,     0,
     972,    49,     0,   744,   160,   158,     0,  2145,     0,     0,
       0,  2145,   156,   145,     0,   148,   147,     0,   978,   982,
    2098,  2097,  2096,   346,     0,   554,     0,  2145,   766,     0,
     625,  1118,     0,  1209,    70,     0,     0,   101,    68,    93,
      76,    82,     0,   120,   116,   760,  2145,   873,   625,   872,
       0,   544,     0,   790,   791,   789,  1056,   956,   954,   682,
     680,     0,   662,   659,     0,   725,   703,   727,   705,   736,
     750,   751,   748,   749,    30,    28,     0,  1677,  1632,  1604,
    1600,  1599,     0,  1390,  1636,  1393,     0,  1310,  1305,  1304,
    1307,     0,  1632,     0,     0,  2075,  2073,     0,     0,  2061,
    2072,     0,     0,  2074,     0,     0,     0,     0,     0,  2103,
    2071,  2067,     0,  2059,  2062,  2063,  2070,  2066,  2090,     0,
    2052,  2051,  2055,  2057,     0,  2050,     0,  2053,  2044,  1323,
    1318,     0,  1381,     0,   585,   583,   595,   597,   593,     0,
       0,     0,  1635,     0,  1712,     0,     0,  1441,  1460,  1454,
    1456,  1463,  1465,  1463,     0,  1470,  1463,     0,  1468,  1463,
       0,  1478,  1477,     0,  1479,     0,  1431,     0,  1346,  1345,
    1341,  1630,   235,  1177,  1178,  1179,  1181,  1164,  1162,  1161,
    1165,  1166,  1163,  1180,  1167,  1168,  1152,   964,  1187,   961,
       0,     0,  1205,     0,  1150,  1149,  1144,  1142,  1141,  1145,
    1143,  1147,  1148,  1140,  1193,  1400,     0,  1396,  1402,  1550,
    1543,  1406,  1506,  1514,     0,  1516,     0,     0,     0,     0,
    1522,  1526,     0,  1418,  1003,  1238,  1243,  1232,     0,    24,
       0,     0,   995,     0,    50,   975,     0,    24,   162,   152,
       0,   635,   637,   164,   154,   744,     0,   345,  1327,     0,
    1040,    24,     0,     0,    66,     0,    79,    88,     0,    72,
     864,   861,   548,  2145,   933,     0,  2145,   678,   657,   663,
     625,  1687,     0,  1685,     0,     0,  1605,  1601,  1392,     0,
    1394,  1388,     0,  1309,     0,  1697,     0,  2065,  2064,     0,
       0,  1498,     0,  1498,  1498,  1498,  1498,  2068,     0,     0,
    2048,     0,     0,     0,     0,  2077,  2049,     0,     0,     0,
       0,     0,     0,  2043,     0,  1383,  1386,  1370,  1384,  1387,
     833,   832,   329,  1593,  1710,  1711,  1445,     0,  1482,  1484,
       0,  1471,  1474,  1473,  1481,     0,  1483,  1463,     0,  1434,
    1340,   213,   966,   965,   963,     0,  1186,  1072,  1076,  1078,
       0,  1082,     0,  1080,  1084,  1073,  1074,     0,   855,     0,
       0,  1544,  1549,     0,  1533,  1525,  1509,  1507,     0,  1510,
     355,   352,     0,   993,     0,     0,     0,   974,   745,   140,
     634,    24,   984,   552,  1037,    67,  1210,    84,     0,     0,
      77,    88,    88,  2145,   545,     0,     0,   681,   737,     0,
    1684,  1633,  1626,     0,  1311,     0,  1626,  2088,     0,     0,
    2091,     0,     0,     0,     0,     0,     0,     0,  2060,  2079,
    2080,  2078,  2076,  2058,     0,  2054,  2056,  2045,  2046,  1324,
       0,  1371,  1369,  1464,  1675,  1466,     0,  1469,  1467,  1485,
       0,   962,  2145,  2145,  1086,  2145,  1088,  2145,  2145,  1075,
    1206,  1194,     0,     0,  1523,   357,   994,  2128,     0,     0,
       0,     0,     0,     0,    55,     0,    54,     0,    52,     0,
       0,   141,  1044,    88,    93,    88,    89,    83,    73,   862,
       0,     0,   683,    24,  1686,  1625,  1634,  1315,     0,  1312,
    1314,  1606,  2089,     0,     0,  2087,     0,     0,     0,     0,
    2069,  2086,     0,  1385,  1472,  1480,  1077,  1079,  2145,  1083,
    2145,  1081,  1085,  1545,  1518,   359,   364,   362,   353,     0,
     360,   366,    57,    62,    59,    61,    58,    60,    56,     0,
      51,     0,   636,   638,  1048,  1038,     0,  1046,  1211,    85,
      80,   546,   934,  2145,   738,     0,  1306,     0,  1607,  1621,
    2085,  2092,  2081,  2082,  2083,  2084,     0,  1087,  1089,  2145,
    2145,   358,   361,  2145,    53,     0,  2145,  1045,  1047,     0,
     679,  1313,     0,  1611,  1608,  1609,  2047,   365,   363,   367,
       0,  1049,    86,   684,     0,     0,     0,   976,    90,     0,
    1612,  1610,    92,     0,    87,     0,    91,  1613
};

/* YYDEFGOTO[NTERM-NUM]. */
static const short yydefgoto[] =
{
      -1,   794,   795,   796,   797,  1012,  2297,  2298,   176,   315,
     177,  1350,  1351,  2145,  2450,  3386,  2920,  2921,  3295,  3387,
    3388,   798,  1140,  2955,  2675,  3312,  2086,  2673,  3177,  2959,
    3308,  2674,  3178,  3394,  3489,  3508,  3310,  3514,   624,   625,
     626,  1463,  2366,   799,  1474,  1145,  1472,  2094,  2376,  2091,
    2374,  2379,  2679,  1473,  2373,  2095,  2678,   800,     8,    26,
      27,    28,    29,    30,    85,   803,  1072,  2041,  1374,  2324,
    2328,  2329,  2325,  2326,  2927,  2931,  2648,  2640,  2639,  2641,
    2644,   480,   263,   578,   804,    54,    55,    10,    39,   111,
      67,   248,    69,    70,   192,   329,    71,    72,   235,   334,
     221,   973,   506,  2824,   360,   904,  2199,   388,   389,   222,
     343,   335,   338,  1292,  1293,   115,   518,   116,   117,   348,
     223,   224,  2032,   556,   237,   240,   238,   239,   370,   534,
     535,   537,   542,   907,   241,   242,   379,   539,   188,    11,
      50,   147,   148,   149,   913,  2767,   150,   245,   233,   382,
     383,   384,   385,  2056,   805,   806,   807,   808,  1031,  3375,
    3149,  1352,  3438,  3439,  3440,  3480,  3479,  3483,   809,   810,
     811,   812,   813,   814,   815,  1023,   481,  1026,  1344,  1345,
    1384,  1110,  1385,   290,   291,   292,   293,   294,   295,   296,
     438,   482,  1276,   483,   484,   485,   486,   487,   488,   489,
     952,   178,   500,   962,   964,  1951,   179,   494,   958,   493,
     957,   496,   960,   495,   959,   922,   931,   297,   298,   181,
     299,   408,   409,   410,   411,   393,   816,  3183,  3400,  2971,
     817,  1083,  2058,  2947,  2348,    86,   230,   528,  1884,  1208,
    1209,  1210,  1881,  1882,  2186,  2187,  2188,  2503,  2504,  1885,
    1886,  2182,  2507,  2499,  2194,  2195,  2510,  2511,  2765,  2761,
    2762,   818,  1394,    56,  2027,  2028,  2343,   394,  1064,  1115,
     997,  1053,  1036,  1073,  2408,   182,   998,   992,  1994,  2643,
      58,   300,   819,  1150,   820,  1163,  1164,   821,   822,   823,
     824,  1171,  2982,  1192,  3188,  1193,  2121,  1194,  2405,  1195,
    2695,  1196,  2148,   825,  2117,  2694,  2981,  3186,  3185,  3463,
      87,    12,   826,  1368,  2033,  2034,  2138,  1830,  2139,  2140,
    2705,  2707,  2421,  2420,  2425,  2419,  2418,  2411,  2410,  2413,
    2412,  2415,  2417,   827,   828,  1070,   829,  1826,  1178,  3403,
     830,  1440,  3157,  2452,  2453,  2141,  2422,  2382,  2681,  1106,
    1422,  2062,  2351,  2063,  1418,   831,   832,  1156,  2109,  2975,
     833,   834,   835,   836,    13,    43,    14,    15,    16,    88,
      89,   837,    90,    17,   895,    18,    91,    92,   127,   530,
    1890,  2515,  3241,    93,   123,   353,   838,  2621,    19,    20,
      21,    22,    23,    38,    59,    94,   649,  1957,  2570,   839,
    1151,  2386,  2098,  2384,  3313,  2966,  2099,  2383,  2684,  2968,
     840,   841,   842,  1047,  1048,  1477,    95,   231,   529,   898,
     899,  1212,  1888,   843,  1197,  1198,   844,  1838,  1199,   301,
      61,    62,    63,    64,  1484,   153,   107,    65,  1003,   104,
     184,   185,  1485,  1486,  2393,  1487,   646,   647,  1180,   648,
    1181,  2402,  2403,  1488,  1489,  1348,  3108,  3109,  3264,  2003,
    1062,  1063,   845,  1363,  3297,   846,  2939,   847,  1378,  1379,
    1380,  2047,  2045,   848,   849,  2308,  2335,   850,  1329,  2000,
     851,  1107,  1108,   852,   985,   853,  2463,   854,  3392,  2950,
     855,  2355,  3455,  3456,  3457,  3486,  1112,   856,  1490,  2111,
    2397,  2398,   857,  2020,   996,  1338,   858,   859,   860,  2572,
    3112,  3275,  3276,  3362,  3363,  3367,  3365,  3368,  3428,  3430,
     861,   862,  1479,  2103,   863,  1481,  1126,  1127,  1128,  1456,
     864,   865,   866,  2073,  1448,  1121,   191,  1129,  1130,   302,
    2573,  2865,  2866,  2849,  1020,  1021,  2568,  2850,  2853,    96,
     122,   522,  1302,  2249,  2867,  3279,   420,   867,  1119,    97,
     119,   519,  1299,  2247,  2854,  3277,  2569,  1144,  2666,  3173,
    3393,  1451,   868,   869,   870,   871,   872,  1034,  2306,  1014,
    2302,   873,  2816,  2615,  2616,  2618,  1977,   874,   875,  1311,
    1312,  1313,  1989,  2286,  1314,  2283,  1986,  1315,  2258,  1978,
    1316,  1317,  1318,  1319,  2252,  1969,   876,  1043,  1025,   877,
    1862,  1863,  2163,  3009,  3204,  2735,  3006,  3408,  3409,  1864,
    2170,  2749,  1844,  2493,  3050,  3234,  2659,  2946,  2494,  1865,
    1866,  2236,  2818,  2819,  2820,  3090,  1867,  1868,  1382,   878,
    1076,   879,  1205,  1869,  1870,  3352,  2176,  2177,  2178,  2496,
    2751,  3237,  3238,  1871,  2473,  2730,  3201,  1979,  1980,  1965,
    2581,  2250,  2582,  1981,  2586,  1982,  2602,  1983,  2603,  2896,
    2897,  2253,  1872,  2157,  2158,  2470,  1873,  2813,  2559,  2809,
    2231,  1933,  2226,  2227,  2228,  2781,  1934,  2232,  2560,  2814,
    2549,  2550,  2551,  2552,  2553,  3248,  3071,  3353,  2554,  3250,
    3251,  2807,  2555,  2808,  2556,  2215,  2279,  2280,  2281,  3137,
    2282,  2884,  2889,  3285,  2583,   989,  3239,  2874,  3042,  2585,
    2544,  1254,   303,  1255,  1918,   431,   923,  1903,  1919,  2525,
      37,   880,   881,  3001,  3197,  2723,  3196,  3469,  3494,  3495,
    2727,  2464,  1874,  2465,  2482,  3012,   581,  2460,  2461,  2237,
    2562,  3195,  3005,  1256,   937,  1257,  1258,  2810,  2557,  1260,
    1261,  2217,  3355,   882,   883,  2150,  2462,  2997,  3192,  3193,
    1841,   884,  1029,  1876,  1877,  2166,  2737,  1878,  1879,  2479,
    1946,  2210,   885,  1159,  1815,  1816,  1817,  2113,  1818,  2114,
    1880,  2483,  3048,  3233,  2746,  3045,  3046,  3047,  3044,  3032,
    3033,  3034,  3035,  3036,  3037,  3331,   886,  2050,  2338,  2339,
    1004,  1262,  1006,  2004,  1263,   887,  1132,  2077,  1371,  1442,
     888,   396,   889,  2632,   890,  2295,  1008,  2006,   891,   892,
      33,   523,   524,   525,   526,   527,   893
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -2659
static const short yypact[] =
{
     632,   373,   333,   333,  1286, -2659, -2659,  1286, -2659,   121,
   -2659, -2659, -2659,   423, -2659,   632, -2659, -2659, -2659, -2659,
   -2659,   175, -2659, -2659, -2659, -2659,   436,   545, -2659,   460,
   -2659, -2659, -2659, -2659, -2659, -2659,  -119, -2659,   418,   155,
   -2659, -2659, -2659,   340, -2659, -2659, -2659, -2659, -2659, -2659,
     -42,   333, -2659,   333,   385,   121, -2659,   649, -2659, -2659,
   -2659, -2659,   345,   -36, -2659, -2659, -2659,   717,   487,   333,
   -2659, -2659,   836,   333, -2659, -2659,   333,   333, -2659, -2659,
   -2659, -2659,   333,   333, -2659, -2659, -2659, -2659, -2659,   340,
   -2659, -2659, -2659, -2659, -2659, -2659, -2659, -2659,  4777, -2659,
     -36, -2659,   783,  2243, -2659, -2659,   462, -2659, -2659,   867,
     155,   413, -2659, -2659, -2659, -2659, -2659,  9325, -2659,   333,
     457,   834,   333,   121, -2659, -2659, -2659,   333, -2659, -2659,
     648,   550,   720, -2659, -2659,   578, -2659,   704, -2659,   531,
   -2659, -2659,   710, -2659, -2659, -2659, -2659, -2659, -2659, -2659,
   -2659, -2659, -2659,   690, -2659, -2659, -2659,   724,   732,   748,
     798,   815,   859,   869,   885,   894,   906,  2243,   917,  4711,
     949,   955,   959,   968,   973,   979,  1612,  1222, -2659, -2659,
   -2659, -2659,   776, -2659,   119, -2659,  2243, -2659,   157, -2659,
   -2659, -2659,   136, -2659, -2659, -2659,   754, -2659, -2659, -2659,
   -2659, -2659,   648,   998, -2659,   720, -2659, -2659,  1013, -2659,
    1019, -2659,   765, -2659, -2659,  1024, -2659, -2659, -2659, -2659,
   -2659, -2659, -2659, -2659, -2659,  1031,  1371,   333,  1042, -2659,
     121,   121,  1046,   333, -2659,   509,  1425, -2659,   814,  1206,
   -2659,   856,  1212,  1525,  1531,   333,  1539,  1549, -2659,   924,
   -2659,    39,    39,    39,    39,    39,  4711,  1210,  1690,    39,
    4711,  1040,  4711, -2659,  4711,  4711,  4711, -2659, -2659, -2659,
    1036,  1135,  1147,  4711,  1252,  1150, -2659,  4711,  4711,  1153,
   -2659,  1154, -2659,   955,  1156,  1158,  1168,  1170,  1579,  8461,
      70, -2659, -2659, -2659, -2659, -2659, -2659, -2659, -2659, -2659,
   -2659,  1185, -2659, -2659, -2659, -2659, -2659, -2659,   386,   386,
   -2659, -2659, -2659, -2659, -2659,  2243, -2659, -2659,   333,  2243,
    1148,   122, -2659, -2659, -2659, -2659,  1625, -2659, -2659, -2659,
   -2659, -2659, -2659, -2659, -2659, -2659,   509,  1628, -2659, -2659,
   -2659,  1648,  1656,   155,  1539,  1658,  1030, -2659,  1589, -2659,
    1260,  1230, -2659,  1300, -2659, -2659, -2659,  1044, -2659, -2659,
    1675,  1273, -2659,  1237, -2659, -2659, -2659, -2659, -2659, -2659,
   -2659,  1212,  1237, -2659, -2659, -2659, -2659, -2659, -2659,  1240,
     198,   232,   318, -2659,  1003, -2659, -2659, -2659,  1247,  1715,
     354, -2659,  1255,  1719, -2659,   -64,  1299,  1303,  1304,  1315,
    1316,  7450,  1318,  -155,  1079, -2659, -2659,    73,  1319, -2659,
   -2659, -2659,  1320,  7491, -2659,  7239,  8918,  1607,  1607,  4711,
   -2659,  1242,  4711,  8461,  1283, -2659, -2659, -2659, -2659, -2659,
   -2659, -2659,  1090,  1737,  7554,  8461,  1242,  1738,   406,  4711,
    4711,  4711,  4711, -2659,  4711,  4711,  4711,  4711,  4711,  4711,
    4711,  4711,  4711,  4711,  4711,  4711,  4711,  4711,  4711,  4711,
    4711, -2659, -2659, -2659, -2659, -2659, -2659, -2659, -2659, -2659,
   -2659,  4711,  4711, -2659, -2659,  1292,  4711, -2659,  4711,  1297,
   -2659, -2659, -2659, -2659, -2659, -2659, -2659, -2659, -2659, -2659,
   -2659, -2659,   386,  4711,  4711,  4711,  4711,  1337,  1764,  1612,
    4711,  1302, -2659,  2243,  1275, -2659,  1112,  1117,  1748,  1347,
    1482,   366,   369,   324,  1322,   377, -2659, -2659, -2659,   333,
   -2659, -2659,   333,  1388, -2659,  4731,   413,  6794,  1758,   450,
     333,  1772,   348, -2659, -2659,  1206,  1768, -2659, -2659, -2659,
   -2659,  1770, -2659,  1774, -2659,  1777, -2659,   333, -2659,   333,
   -2659, -2659,  1539,  1778, -2659, -2659, -2659,   333,    39,  2243,
      35, -2659, -2659, -2659, -2659, -2659, -2659,  1252,  1252,  1782,
   -2659,  1785,  1187,  1307, -2659, -2659, -2659, -2659,  1386,  8461,
       0,  1392,  7705,  1791,  1252,  1393, -2659,  1394,  1399, -2659,
    7777,  7994,  8145,  8208,  8678,  8746,  8918,  1651,  3890,  3164,
    8963,  8993,  2834,  4425,  5167,  1607,  1607,   823,   823,  3119,
    8461,  8243,  8394,  1242,  8461,  8431,  1242, -2659,  8461,  8461,
    8461,  8461, -2659,  1805, -2659,  1830, -2659,  8461, -2659,   208,
    2243, -2659,  1816,   348, -2659,  1375,  1818, -2659,  1820, -2659,
   -2659, -2659,  1826, -2659, -2659,  1198,  1427,  1853, -2659,   333,
    1430, -2659, -2659, -2659,   386,   386,   386,   919,   333,  1504,
     245,   333,   333,   245,   245,   920,   333, -2659,  1504, -2659,
   -2659,   333, -2659,  1027, -2659, -2659, -2659,   245, -2659, -2659,
   -2659, -2659,   333, -2659, -2659, -2659, -2659,   117,   117,  4711,
   -2659, -2659, -2659, -2659, -2659, -2659,   245, -2659, -2659,   245,
   -2659, -2659,   333, -2659, -2659,   245, -2659, -2659,   386,   245,
   -2659, -2659,  4711,   245,   386,   333,   386,   245, -2659, -2659,
     251,   245,   245,   251,   245,   333,   251,   245, -2659,   245,
     245,   245, -2659, -2659, -2659, -2659,   386,   245, -2659, -2659,
     245,    50,   333, -2659, -2659, -2659, -2659,   245,   958, -2659,
   -2659,   386, -2659,   245, -2659,  9361,   386,  4711,    39,    39,
     245, -2659, -2659,   919,   386,  1041,  4711,  4711, -2659,   205,
    4711,   245,    81, -2659,  4711,   245,  1834,   386, -2659,   245,
    4711, -2659,  4711,   117,   333,   245,   333,    39,   245,   333,
      39, -2659,   333,   184, -2659, -2659, -2659, -2659, -2659, -2659,
   -2659, -2659, -2659, -2659, -2659, -2659, -2659, -2659, -2659, -2659,
   -2659, -2659, -2659, -2659, -2659, -2659, -2659, -2659, -2659, -2659,
   -2659, -2659, -2659, -2659, -2659, -2659, -2659, -2659, -2659, -2659,
   -2659, -2659, -2659, -2659, -2659, -2659, -2659, -2659, -2659, -2659,
   -2659, -2659, -2659, -2659,   241, -2659, -2659, -2659, -2659, -2659,
   -2659, -2659, -2659, -2659, -2659, -2659, -2659, -2659, -2659, -2659,
   -2659, -2659, -2659, -2659, -2659, -2659, -2659, -2659, -2659, -2659,
   -2659, -2659, -2659, -2659, -2659, -2659, -2659, -2659, -2659, -2659,
   -2659, -2659, -2659, -2659,  1034, -2659, -2659, -2659, -2659, -2659,
   -2659, -2659, -2659, -2659, -2659,   601,   333, -2659,   705, -2659,
    1435, -2659, -2659, -2659,  1527, -2659, -2659,  1436,  1439,  1442,
    1445, -2659, -2659,  1215,  1872,  1449,  1451, -2659,   474, -2659,
    1414, -2659, -2659,  1221, -2659,  1456, -2659,  1860, -2659,  1261,
   -2659, -2659,  1229, -2659, -2659, -2659, -2659,  9168, -2659,  1036,
    1467, -2659,  1036, -2659,  1036,  1036,  1036,  1036,  1036,  1873,
    1874,  1875,  4711,  1475,  1880,  4711,  1477,  1479,  1486,  1488,
    1489,  1494,  1495,  4711,  4711, -2659,   304, -2659, -2659,  1585,
   -2659,  1497,  1510,  1271,  1514,   333, -2659,   333,  1515, -2659,
   -2659, -2659, -2659, -2659, -2659, -2659,   429,  1277,  1321,  1149,
    1478, -2659, -2659, -2659, -2659, -2659, -2659, -2659, -2659, -2659,
    1293,  1511,  1454, -2659,  1298, -2659,  1301, -2659,  1945,  1294,
   -2659, -2659,  1490, -2659,  1518, -2659,  1440,   209, -2659, -2659,
   -2659,  1501, -2659,  8461, -2659, -2659, -2659,  3670, -2659, -2659,
   -2659,   386, -2659, -2659,  1518, -2659,    19, -2659, -2659,  1655,
   -2659,   118, -2659,  1463, -2659, -2659, -2659, -2659,  1958, -2659,
   -2659,   104, -2659,  1311, -2659,  1313,  1958, -2659,  1336, -2659,
   -2659,  1516,    93, -2659,  1472, -2659,  1280, -2659, -2659, -2659,
   -2659,  1281,   197,  -226, -2659,  1293,  1606,  1324,  4711,   111,
    4711, -2659,  1970,   245, -2659, -2659, -2659, -2659, -2659,    42,
      42,    42, -2659,    42,  2042,    42,    42,  1346,    19,  1346,
    1346,  1047,  1047,  1346,  1346,    19, -2659,  1975, -2659,    18,
    1976, -2659,    19,   236,  1285, -2659, -2659,  4711, -2659, -2659,
   -2659,  1008, -2659, -2659,   413,  1566,   413,  4711, -2659,    48,
   -2659, -2659,  4711,  1521,  1522,  1524,  1526,  1537,  1529,  1041,
   -2659,  1611,   800,  1369, -2659,  1383, -2659, -2659,   333, -2659,
   -2659,  1058, -2659,  1991, -2659,  1986,   333, -2659,   466,  6160,
    1397, -2659, -2659,  2005, -2659,  1317,  2005, -2659,  1323,  2005,
   -2659,  4711,  2005, -2659, -2659,   209,   386, -2659, -2659,  1553,
     731, -2659, -2659,  1547,   386,  4711,  1554, -2659, -2659,  1993,
    1995,  1916, -2659, -2659, -2659, -2659, -2659, -2659, -2659, -2659,
    1096,  1096,   245,   245,   245,  4082, -2659, -2659,  1896,   601,
   -2659, -2659,   711, -2659, -2659, -2659,  1528, -2659, -2659, -2659,
   -2659,  4777,  1539, -2659, -2659,  1370,   333,  1284,  1252,  1411,
    1502, -2659,  7415,  7415, -2659,  1293, -2659, -2659,  1359, -2659,
   -2659,  5077,  1557, -2659,  1568,  1570, -2659,  1573,  1574,  1577,
    1578,   333,   -30, -2659, -2659, -2659, -2659,   137, -2659,   333,
    1563, -2659,  1576, -2659, -2659, -2659, -2659, -2659, -2659, -2659,
   -2659, -2659, -2659, -2659, -2659,  8461,   378, -2659, -2659,   421,
   -2659, -2659, -2659, -2659, -2659, -2659, -2659, -2659, -2659, -2659,
    1552, -2659,   424, -2659, -2659, -2659, -2659, -2659, -2659,   121,
   -2659, -2659,   121,   786,   170,  2021, -2659, -2659,   589,   173,
     599,  2044, -2659, -2659, -2659, -2659, -2659, -2659, -2659, -2659,
     333,   333, -2659, -2659,  1551,  1511,  1301, -2659,   920,  -144,
    1164,   333,  1518,  1422,  1402,  1433,  1596, -2659,  1600,   132,
   -2659, -2659, -2659, -2659, -2659,  2064, -2659, -2659,  1416,  1602,
   -2659, -2659, -2659,   920,  1113, -2659,  1113,  1041,   251,  4711,
    4711,  4711,  1608, -2659, -2659,   386,   386, -2659,  1423,  1041,
      39,  1285,    50,   386, -2659,  1431,  4711,  1698, -2659, -2659,
    1498, -2659, -2659,   333,  2083, -2659, -2659,    71,   209, -2659,
   -2659,  2075,  2076, -2659, -2659, -2659, -2659, -2659, -2659, -2659,
   -2659, -2659, -2659, -2659, -2659, -2659, -2659, -2659, -2659, -2659,
   -2659, -2659, -2659, -2659, -2659, -2659, -2659, -2659, -2659, -2659,
   -2659,  1130, -2659, -2659, -2659, -2659, -2659, -2659, -2659, -2659,
   -2659,  9361, -2659,  1047,  4711,   -44,  2068,  2071, -2659, -2659,
   -2659, -2659, -2659,   164, -2659, -2659, -2659, -2659,  1908, -2659,
    1844, -2659, -2659, -2659,  4711,   117, -2659, -2659,   333,  2077,
      39,    39, -2659,  1481, -2659,    39,  1455,   386, -2659,   333,
     333,  4711,    -8, -2659,  1503, -2659, -2659,   299, -2659,  1597,
   -2659,  1601,  4711,   853, -2659, -2659,  1448, -2659,  2117, -2659,
    1540, -2659,   386, -2659, -2659, -2659, -2659, -2659, -2659, -2659,
   -2659, -2659, -2659, -2659, -2659, -2659, -2659, -2659, -2659, -2659,
   -2659, -2659, -2659, -2659, -2659, -2659, -2659, -2659, -2659, -2659,
   -2659, -2659, -2659, -2659, -2659, -2659, -2659, -2659, -2659, -2659,
   -2659, -2659, -2659, -2659, -2659, -2659, -2659, -2659, -2659, -2659,
   -2659, -2659, -2659, -2659, -2659, -2659, -2659, -2659, -2659, -2659,
   -2659, -2659, -2659, -2659, -2659, -2659, -2659, -2659, -2659, -2659,
   -2659, -2659, -2659, -2659, -2659, -2659, -2659, -2659, -2659, -2659,
   -2659, -2659, -2659, -2659, -2659, -2659, -2659, -2659, -2659, -2659,
   -2659, -2659, -2659, -2659, -2659, -2659, -2659, -2659, -2659, -2659,
   -2659, -2659, -2659, -2659, -2659, -2659, -2659, -2659, -2659, -2659,
   -2659, -2659, -2659, -2659, -2659, -2659, -2659, -2659, -2659, -2659,
   -2659, -2659, -2659, -2659, -2659, -2659, -2659, -2659, -2659, -2659,
   -2659, -2659, -2659, -2659, -2659, -2659, -2659, -2659, -2659, -2659,
   -2659, -2659, -2659, -2659, -2659, -2659, -2659, -2659, -2659, -2659,
   -2659, -2659, -2659, -2659, -2659, -2659, -2659, -2659, -2659, -2659,
   -2659, -2659, -2659, -2659, -2659, -2659, -2659, -2659, -2659, -2659,
   -2659, -2659, -2659, -2659, -2659, -2659, -2659, -2659, -2659, -2659,
   -2659, -2659, -2659, -2659, -2659, -2659, -2659, -2659, -2659, -2659,
   -2659, -2659, -2659, -2659, -2659, -2659, -2659, -2659, -2659, -2659,
   -2659, -2659, -2659, -2659, -2659, -2659, -2659, -2659, -2659, -2659,
   -2659, -2659, -2659, -2659, -2659, -2659, -2659, -2659, -2659, -2659,
   -2659, -2659, -2659, -2659, -2659, -2659, -2659, -2659, -2659, -2659,
   -2659, -2659, -2659, -2659, -2659, -2659, -2659, -2659, -2659, -2659,
   -2659, -2659, -2659, -2659, -2659, -2659, -2659, -2659, -2659, -2659,
   -2659, -2659, -2659, -2659, -2659, -2659, -2659, -2659, -2659, -2659,
   -2659, -2659, -2659, -2659, -2659, -2659, -2659, -2659, -2659, -2659,
   -2659, -2659, -2659, -2659, -2659, -2659, -2659, -2659, -2659, -2659,
   -2659, -2659, -2659, -2659, -2659, -2659, -2659, -2659, -2659, -2659,
   -2659, -2659, -2659, -2659, -2659, -2659, -2659, -2659, -2659, -2659,
   -2659, -2659, -2659, -2659, -2659, -2659, -2659, -2659, -2659, -2659,
   -2659, -2659, -2659, -2659, -2659, -2659, -2659, -2659, -2659, -2659,
   -2659, -2659, -2659, -2659, -2659,  5459, -2659, -2659, -2659, -2659,
     333,    39,    39,   351,   731,  1935,  1342,   386,   209, -2659,
    1543, -2659, -2659,  2083,  2103,  1696, -2659, -2659, -2659, -2659,
   -2659,  1775,  1775, -2659,   326,  1555, -2659,   333, -2659, -2659,
    1518,  1518, -2659, -2659, -2659,   333, -2659,   333,     0,  1518,
   -2659,   714, -2659, -2659, -2659, -2659, -2659, -2659, -2659, -2659,
   -2659, -2659, -2659, -2659, -2659, -2659, -2659, -2659, -2659, -2659,
   -2659,   150,   150,   252,   727, -2659,   515, -2659,   711, -2659,
     121,  2109, -2659, -2659,  1182,  1710,  1673, -2659, -2659, -2659,
   -2659, -2659, -2659, -2659, -2659,  1561, -2659, -2659, -2659,  1548,
    1548, -2659, -2659, -2659, -2659, -2659, -2659, -2659, -2659,  1484,
       0,  1714,   548,   517,  9168,   517,   517,   517,   517,  1506,
    9168,  9168,   229,  1581,   694, -2659,  9168,  9168,  9168,  9168,
   -2659, -2659, -2659, -2659, -2659, -2659, -2659,   920,  4711, -2659,
   -2659,  1726,  2109, -2659, -2659, -2659, -2659,   121, -2659, -2659,
    1518, -2659,   745, -2659,  1689, -2659, -2659,   745, -2659, -2659,
   -2659,  1691,  1692,   231,  1708,  1709,  3657, -2659, -2659, -2659,
   -2659, -2659, -2659, -2659,   333, -2659, -2659,   231,  1458, -2659,
     429, -2659, -2659, -2659,  1756,   -36,  1530, -2659,  1041,  1580,
   -2659, -2659,  1693, -2659, -2659, -2659,  1609,  1722,   333,   333,
     333, -2659, -2659, -2659,  3670,   333, -2659,  1541, -2659, -2659,
   -2659, -2659,  1533, -2659,  2192,  2193, -2659,  2194,  1586,  4711,
   -2659, -2659,  1545,  2198, -2659,  1684,  1544, -2659, -2659, -2659,
    1550,   983,   333, -2659, -2659,  1740,   245,   821, -2659,  4711,
   -2659, -2659,   333,   333,  4711,    38,    19,  2204,  2202,  2186,
    2188,  2042, -2659, -2659, -2659, -2659, -2659,   386,  1858, -2659,
   -2659,  2120,  4711,   413,  1070, -2659, -2659,  1861,  2217,  2220,
     434,  1797,   333,  1801,  1041, -2659,  4711,  1767,  1779, -2659,
   -2659,  1845, -2659,  4711,   186, -2659,  1613, -2659, -2659,   780,
   -2659,  4711, -2659, -2659,  1587,   783, -2659,  1214,   333,  2228,
    8636, -2659, -2659,   920,   386, -2659, -2659,    98, -2659, -2659,
   -2659,  1560, -2659,  1661,  1667, -2659, -2659, -2659, -2659,    39,
      39, -2659, -2659, -2659, -2659, -2659, -2659, -2659, -2659,  1499,
   -2659, -2659, -2659, -2659,    39,  3580,  2246,  2227, -2659,  1041,
     897,   240,   203,  2124,   -50,   919, -2659,    60, -2659, -2659,
   -2659,  1795,   272,  1518,   139, -2659,  1616,  1603, -2659, -2659,
     451, -2659, -2659, -2659, -2659,  1796,  1619,  2262, -2659, -2659,
   -2659,   386,   145, -2659, -2659, -2659,  1593,   727, -2659,   333,
     333, -2659, -2659,   333,   604, -2659, -2659, -2659, -2659,  1809,
   -2659, -2659, -2659,  2255, -2659, -2659,  1412,  9168, -2659,   368,
    1854,  2277, -2659, -2659, -2659,  9168, -2659,   437,  9168,  9168,
    9168,  9168,   333,   445, -2659,   283,  2279, -2659, -2659,   333,
    2870, -2659,  1883,   333,  1636,   517,  1923, -2659, -2659, -2659,
   -2659, -2659, -2659,  8461, -2659,  1829, -2659,  1798, -2659,  1799,
   -2659,  1831,   459, -2659,  2870,   468,   151,   151,   472, -2659,
     151,  2870, -2659, -2659,  1833,  1359,  1359, -2659,  1835, -2659,
    1840,  1843, -2659,  1846,  1847, -2659, -2659, -2659, -2659,   154,
   -2659, -2659, -2659,   476, -2659, -2659,   480,   333, -2659, -2659,
    1164,  2290,  1041,  2243,  4711, -2659,   333,  2297, -2659, -2659,
   -2659, -2659,   231, -2659, -2659,  1662,   231,   196, -2659,  1041,
    4711,  4711,  4711,  4063,  2307,   146, -2659, -2659,  1041,   333,
   -2659, -2659,   333,   333, -2659,   929, -2659, -2659,   974, -2659,
    1663,  4711, -2659, -2659, -2659,  2320, -2659,  1674,  2324, -2659,
   -2659, -2659, -2659, -2659,   333, -2659, -2659, -2659,  1741, -2659,
   -2659,   481, -2659, -2659, -2659,   386, -2659,  7391, -2659, -2659,
   -2659,  1969,  2308, -2659,  1952,  1953,  1841,  1680,  1959,  1876,
   -2659, -2659, -2659,   502,  1947, -2659, -2659, -2659, -2659,  1845,
   -2659, -2659, -2659,   237,   793, -2659, -2659, -2659,  2083,  4711,
    1884, -2659,  1852, -2659, -2659, -2659, -2659,  2338, -2659, -2659,
   -2659,  1891,  2346, -2659, -2659,  1665, -2659,  2328,    19,   333,
    1599,  1599,  1599,  1599, -2659,  2350, -2659,  2351,  1599,  1599,
    1599,  1599,  1130, -2659, -2659,  1599,  1661, -2659, -2659, -2659,
   -2659,  2332,  2344, -2659, -2659, -2659, -2659, -2659, -2659, -2659,
   -2659, -2659,  2345, -2659, -2659, -2659, -2659, -2659, -2659, -2659,
     482, -2659, -2659, -2659,  2334, -2659, -2659,  1518, -2659,     0,
   -2659, -2659, -2659, -2659, -2659, -2659,  1729,  1730,    95, -2659,
      60, -2659,   151,  1711,   245, -2659,  1895, -2659, -2659, -2659,
     333,   333,  9168,   292, -2659,  4711, -2659,  4711, -2659, -2659,
   -2659, -2659, -2659, -2659,   245,   151, -2659,  1518,   569,  2361,
   -2659,   386,   333,   774,   774, -2659, -2659,  2363, -2659,  2363,
     612,   612,  2363, -2659, -2659,  1758, -2659,  1941,  1903, -2659,
   -2659, -2659, -2659, -2659, -2659, -2659,   137,  1359,  1712, -2659,
    1359,  1943,  9168, -2659,  1944,  1946,  1948,  1950, -2659, -2659,
     229, -2659,   229, -2659, -2659,  4029,  1912,  3142,  1912,  2370,
    2375, -2659, -2659, -2659, -2659, -2659, -2659,   442,  9168, -2659,
    1898, -2659,  2079,   213,   240,   333, -2659,  3309,    86, -2659,
    1758,  1512, -2659,    86,   151,   745, -2659,   211, -2659,  1518,
     337,  1957,  2382,  1732, -2659, -2659,   484, -2659,   231, -2659,
     493,   214,  2367,  1727,   -61,  2368,  2368,  2369,  2368,  2368,
   -2659,   109, -2659,   745,   333, -2659,   231, -2659, -2659,  1742,
    1041,  2388,   310, -2659,     4,   500, -2659,   333,   507, -2659,
    4711,  1968,  2379,   513,  1041,  2395, -2659, -2659, -2659, -2659,
    4711,  1802,  2089,  4711, -2659, -2659, -2659, -2659,   974,  1175,
    1175,  2397,   380, -2659,  2401, -2659, -2659, -2659,  1175,   333,
    1825,  1232,  2404,   333,   174, -2659,  -220,  4711, -2659, -2659,
    2042, -2659,  1707,  4711, -2659,  2407,  4711,   386, -2659,  1027,
     333,   386, -2659,  1984,  4711,  4711, -2659, -2659,   502,  1947,
   -2659,  1130, -2659, -2659,  1137, -2659, -2659,  1807, -2659,  2243,
    4318,  8636,   386,   386,    72,   862, -2659, -2659, -2659,  1760,
   -2659, -2659, -2659, -2659,    39,  1599,    39,  1599, -2659, -2659,
   -2659, -2659, -2659, -2659,    19, -2659,  1082,  1162,  3580, -2659,
    1988,  1951,  9168, -2659,   203,   203, -2659, -2659, -2659, -2659,
     514, -2659,  1910, -2659,   151,   399, -2659,  1759, -2659,  2415,
    9016,  9016,  9016,  9016,   151,   151, -2659, -2659, -2659,  1832,
   -2659,   519, -2659,  1763, -2659,   386, -2659,  2363, -2659, -2659,
     333,   612,   612, -2659, -2659,   612,  2178,  1769, -2659,  2402,
    2001,  1771,  1412,  1773, -2659, -2659, -2659, -2659, -2659, -2659,
   -2659,   520, -2659, -2659,  1924, -2659,   249,   405, -2659,  2870,
    2870, -2659, -2659, -2659, -2659, -2659, -2659, -2659, -2659, -2659,
    7415,  7415,  1966,  7415,  1972, -2659,  7415,   615,  9168,  2431,
   -2659, -2659,  2870, -2659, -2659, -2659, -2659, -2659,  2433, -2659,
     503, -2659, -2659,  2079,  1781, -2659, -2659,   117,   117,   117,
    2418,   117,   117,   117,   117,   117,   117,  2419, -2659,  2420,
     117, -2659, -2659, -2659, -2659, -2659, -2659, -2659, -2659,  3309,
   -2659,   386,  1792, -2659,  1962,  2178,  2423, -2659,  2425,  2426,
    2427,  2428,  2430,  2432,  1201,  1512, -2659,  1962, -2659,   538,
   -2659, -2659, -2659,  2434, -2659,  2123,   151,  1233,   151, -2659,
   -2659, -2659, -2659, -2659,  2022,  1412,  2435,  1412, -2659,  2454,
    2454,   539,  2033,  2454, -2659, -2659, -2659,   745, -2659, -2659,
   -2659, -2659,  1041, -2659, -2659, -2659,   333, -2659, -2659,   231,
    2079,  2083, -2659,  1960, -2659,   263,  1041, -2659,  2458,  1999,
   -2659, -2659,  2045,  1888, -2659, -2659,   333,  1175,  2243,  1312,
     333,  1175, -2659, -2659,    39, -2659, -2659,  4711, -2659, -2659,
   -2659, -2659, -2659, -2659,    39,  2083,   386,  2199, -2659,  2450,
    1661,  8461,  2457, -2659, -2659,   209,  2019, -2659, -2659,  4711,
   -2659, -2659,  2055, -2659, -2659, -2659,   793, -2659,  1661, -2659,
    4711, -2659,   322, -2659,  1976, -2659, -2659, -2659, -2659, -2659,
   -2659,  2007,  2104, -2659,  2468, -2659, -2659, -2659, -2659, -2659,
   -2659, -2659, -2659, -2659, -2659, -2659,   333, -2659,   160, -2659,
   -2659, -2659,   151, -2659,     0,  2309,   547, -2659, -2659, -2659,
   -2659,   333,  1900,  8925,  8925, -2659, -2659,  9124,  2023, -2659,
   -2659,  2024,  2026, -2659,  2028,  2029,  2030,  2034,   333,   -22,
   -2659, -2659,   559, -2659, -2659,  2146, -2659, -2659, -2659,   561,
    2496,  2496, -2659, -2659,   562,  2498,  2491, -2659,   273, -2659,
   -2659,   151, -2659,   158, -2659, -2659, -2659, -2659, -2659,  2260,
    4777,  2082, -2659,  1412, -2659,  1412,   229, -2659, -2659,  2375,
   -2659,  2035,  1563,  2035,   165, -2659,  2035,   165, -2659,  2035,
    7415, -2659, -2659,  9168, -2659,  9168,  2370,   213, -2659, -2659,
   -2659, -2659, -2659, -2659, -2659, -2659, -2659, -2659, -2659, -2659,
   -2659, -2659, -2659, -2659, -2659, -2659, -2659,   551,  2507, -2659,
     386,  1766, -2659,  2260, -2659, -2659, -2659, -2659, -2659, -2659,
   -2659, -2659, -2659, -2659, -2659, -2659,   325, -2659, -2659, -2659,
    2017, -2659, -2659, -2659,  2088, -2659,  2494,  2093,  2094,  2499,
   -2659, -2659,  2095, -2659, -2659, -2659, -2659, -2659,    39,    19,
    2114,  1041, -2659,  4711, -2659,  1922,  2502,    19, -2659, -2659,
     516, -2659, -2659, -2659, -2659,  1888,  2102, -2659,  2346,  2254,
   -2659,    19,  2105,  2106,  2204,  2069, -2659,  2154,  2110, -2659,
   -2659, -2659, -2659,  2267,  2051,  4711,  2063, -2659, -2659, -2659,
    1661, -2659,   563, -2659,   386,  1965, -2659, -2659, -2659,  9168,
   -2659, -2659,   151, -2659,  2081, -2659,  1965,  2041,  2041,  2121,
     548,   517,  9238,   517,   517,   517,   517,  1897,  9238,  9016,
   -2659,  9238,  9238,  9238,  9238, -2659, -2659,   151,  2537,   151,
    9016,   245,  2870, -2659,   386, -2659, -2659,   359, -2659, -2659,
   -2659, -2659, -2659, -2659, -2659, -2659, -2659,   109, -2659, -2659,
     565, -2659, -2659, -2659, -2659,   567, -2659,  2035,  2547, -2659,
   -2659, -2659, -2659, -2659, -2659,   386,  2507, -2659, -2659, -2659,
     386, -2659,   386, -2659, -2659,  1790, -2659,  2278, -2659,  2280,
    2532, -2659, -2659,  1904, -2659, -2659, -2659, -2659,  2130, -2659,
   -2659, -2659,  1041, -2659,  2135,  9469,  2092, -2659, -2659, -2659,
    1911,    19, -2659, -2659, -2659, -2659, -2659, -2659,  2139,   209,
   -2659,  2154,  2154,   793, -2659,  2243,  1961, -2659, -2659,   333,
   -2659,  2346,   694,   137, -2659,  8970,   694, -2659,  2140,  9238,
   -2659,   580,  9238,  9238,  9238,  9238,   333,   584, -2659, -2659,
   -2659, -2659, -2659, -2659,  2107, -2659, -2659, -2659,  2370,  2346,
     158, -2659, -2659, -2659, -2659, -2659,   202, -2659, -2659, -2659,
    9168, -2659,  1859,  1859, -2659,  1859, -2659,  1859,  1859, -2659,
   -2659, -2659,  2112,  1412, -2659,  1045, -2659, -2659,    42,    42,
      42,    42,    42,    42, -2659,  2546, -2659,   588, -2659,  4711,
    1408, -2659,   570,  2154,  4711,  2154,  2204, -2659, -2659, -2659,
    2295,   338, -2659,    19, -2659, -2659, -2659, -2659,   594, -2659,
   -2659,  1246, -2659,  2149,  9238, -2659,  2150,  2151,  2152,  2153,
   -2659, -2659,  9016, -2659, -2659, -2659, -2659, -2659,  1859, -2659,
    1859, -2659, -2659, -2659, -2659, -2659, -2659, -2659, -2659,  1099,
   -2659, -2659, -2659, -2659, -2659, -2659, -2659, -2659, -2659,  9469,
   -2659,  2578, -2659, -2659, -2659, -2659,   796, -2659, -2659, -2659,
   -2659, -2659, -2659,    98, -2659,  8970, -2659,  1575, -2659, -2659,
   -2659, -2659, -2659, -2659, -2659, -2659,   605, -2659, -2659,  1178,
    1178, -2659, -2659,  1178, -2659,  4711,   890, -2659, -2659,  2155,
      72, -2659,  1929,  1931,  2583, -2659, -2659, -2659, -2659, -2659,
    2160, -2659, -2659, -2659,   333,   333,  1575, -2659,   144,  1934,
   -2659, -2659, -2659,   209, -2659,   333,  2204, -2659
};

/* YYPGOTO[NTERM-NUM].  */
static const short yypgoto[] =
{
   -2659, -2659, -2659, -2659, -2659,   -78, -2659,   -23,  -163, -2659,
   -2659, -1094,    52, -2659, -2659, -2034, -2659, -2659, -2659, -2659,
    -856, -2659, -2659, -2659, -2659, -2659, -2659, -2659, -2659, -2659,
   -2659, -2659, -2659, -2659, -2659, -2659, -1969, -2659,  -945, -2659,
    1632, -2659, -2659, -2659, -2659, -2659, -2659, -2659,   217, -2659,
   -2659, -2659, -2659,  1125, -2659,   504, -2659, -2659,   -28, -2659,
   -2659,  2573, -2659,  2572,  2078, -2659, -2659, -2659, -2659, -2659,
     287,   -40, -2659,   285, -2659, -2659, -2659, -2659, -2659, -2659,
   -2659, -2659, -2659, -2659, -2659,   -85,  1290,   379, -2659, -2659,
    2268,    49, -2659,  2503, -2659, -2659,  2500, -2659,  2410, -2659,
   -2659, -2659, -2659, -2659,  2281,  1983,   668,  2282,  -507, -2659,
   -2659, -2659, -2659, -2659,   670,  -620, -2659, -2659, -2659, -2659,
   -2659, -2659,  -136,  2108,  2416,    96,  2048, -2659,  2096,  1396,
   -2659,  2256, -2659, -2659, -2659, -2659,  2259, -2659, -2659, -2659,
   -2659,  -377, -2659, -2659, -2659, -2659, -2659, -2659, -2659, -2659,
    2085, -2659,  2084, -2659, -2659, -2659, -2659, -2659, -2659, -2659,
   -2659, -1298, -2659, -2659,  -804, -2659, -2659, -2659, -2659, -2659,
   -2659, -2659, -2659, -2659, -2659,  -159, -2659, -2659,   622, -2659,
   -1032, -1089,  1657, -2659, -2659, -2659, -2659, -2659, -2659, -2659,
   -2659, -2659,  1682, -2659, -2659, -2659, -2659, -2659, -2659, -2659,
    -557, -2659, -2659, -2659, -2659, -2659,  1870, -2659, -2659, -2659,
   -2659, -2659, -2659, -2659, -2659,  -525, -2659,   -97, -2659, -2659,
   -2659, -2659,  2236, -2659, -2659,  1181, -2659, -2659, -2659, -2659,
   -2659, -2659, -2659, -2659, -2659, -2659, -2659, -2659, -2659, -2659,
   -2659,  1434, -2659, -2659, -2659, -2659,   458, -2659, -2659, -2659,
   -2659, -2659, -1682, -2659, -2659,   452, -2659, -2659, -2659, -2659,
   -2659, -2659, -1056,  -797,   332,   600, -2659,  -240,   734, -1075,
    1410, -2659,   706, -2659, -2353,    -2,  -385, -2659, -2659, -2221,
     257,  1054, -2659, -2659, -2659,   685,   828, -2659, -2659, -2659,
   -2659, -2659, -2659,   -39, -2659,  -329, -2659,   832, -2659,   536,
   -2659,   254, -2659, -2659, -2659, -2659,  -830, -2659, -2659, -2659,
   -2659, -2659, -2659, -2659, -2659,   346, -2659, -1768, -2659,   522,
   -2659, -2659, -2659, -2659, -2659, -2659, -2659, -2659, -2659, -2659,
   -2659, -2659, -2659, -2659, -2659,  1291, -2659, -2659, -2659, -2659,
   -2659, -2659,  -501, -2659, -2659, -1999, -2659, -2659, -2659, -2659,
     417, -2064, -2659, -1074, -2659, -2659, -2659, -2659, -2659, -2659,
   -2659, -2659, -2659, -2659, -2659, -2659, -2659, -2659,  2651, -2659,
   -2659, -2659,  2581,  2650, -2066, -2659, -2659, -2659, -2659, -2659,
   -2659, -2659,  -441, -2659, -2659, -2659, -2659, -2659, -2659, -2659,
   -2659,  2655, -2659, -2659, -2659, -2659, -2659, -2659, -2659, -2659,
   -2659, -2659,   579, -2659, -2659, -2659, -2659, -2659, -2659, -2659,
   -2659, -2659, -2659,  -665,  1954, -2659, -2659, -2659, -2659, -2659,
    1788, -2659, -2659, -2659, -2659, -2659, -2659, -2659, -2659,  2366,
   -2659, -2659,   -24, -2659, -2659,   572, -2659, -2659, -2659,  -986,
    -183,  2360, -2659, -2659, -2659, -2659,   518, -2659, -1003,  1716,
     860, -2351,    -1, -2659,   586,  1519,  -414,  -568, -2659, -2659,
    1949,  1332, -2659, -2659, -2659, -2659, -2659, -2659, -2659, -2659,
   -2659, -2659, -2659, -2659, -2659, -2659, -2659, -2659, -2659, -2659,
   -2659, -2659,  1268, -2659,  -740, -2659,  -622, -2659, -2659, -2659,
   -2659, -2659, -2659, -2659,  -755, -2659, -2659, -2659, -2659, -2659,
   -2659,    16, -2659,  1352,   404, -2659, -2659, -2659, -2659, -2659,
    -158, -2659,  -565, -2659, -2659, -2659, -2659, -2659, -2659, -2659,
   -2659, -2659, -2659, -2659, -2659, -2659, -2659, -2659,  1590, -2659,
   -2659, -2659, -2659, -2659, -2659, -2659,  -482, -2659,  1258,  2275,
   -2659, -2659,  -147, -2659,  -595, -2659, -2659,  -130,   148, -2659,
   -2659, -2659, -2659, -2659, -2659, -2659,  1236, -2659, -2659, -2659,
   -2659, -2659, -2659, -2659, -2659, -2659, -2659, -2659, -2659, -2659,
   -2659, -2659, -2659, -2659, -2659, -2659, -2659, -2659, -2659, -2659,
   -2659, -2659, -2457, -2659,  -184,   419, -1286, -2659, -2659, -2659,
     733, -2659, -1909, -2659, -2659, -2659, -1921, -2659, -2659, -1894,
   -2659, -2659, -2659, -2659,   759, -2659, -2659, -2659, -2659, -2659,
   -2659,   259, -2659, -2659, -2659, -2659, -2659, -2659,  -737, -2659,
   -2659, -2659, -2659, -2659, -2659, -2659, -2659, -2659, -2659, -2659,
   -2659, -2659, -2659,  -358, -2659, -2659, -2659, -2659, -2659, -2659,
   -2659, -2659, -2659, -2659, -2659, -2659, -2659, -2659,   233, -2659,
   -2659, -2659,  -617, -2659, -2659, -2659, -2659, -2659, -2659,  -145,
   -2659, -2659,   161, -2659,   477, -2659, -2659, -2659, -2659, -2659,
   -2659, -1278, -2659, -2659, -2659, -2659, -1753, -2659, -2659, -2659,
   -2659, -2659, -2659, -2269,   511, -2659, -2476,   582, -2659, -2659,
   -2207,   -55,   -45,   201, -2659, -2114, -1730, -2659, -2659,  -328,
    -608, -2659, -2659, -2659, -2659, -1681, -2659, -2659, -2659, -2036,
   -2659, -2659, -1103, -2659,  -982,  2086,   903,  -379, -2147,   176,
   -2659, -2053, -2659, -2659, -2659, -2659,    10, -2659, -1105, -2524,
    2745, -2659, -2659, -2659, -2659, -2659, -2659, -2659, -2659,  -750,
   -2659, -2209, -2659,  1556, -2659, -2659,   592,   193, -2659, -2316,
     194,  -252,    27, -2332, -1825, -2161,   833,  -322,  -718, -1211,
   -2659,   837, -2659, -2659, -2659,   927,  -748, -2659, -2659,  -553,
    1569, -2659,   674, -2659, -2659, -1785,  -239, -2659, -2659, -2659,
   -2630,  -439, -2659, -2659, -2659,   960, -2659, -2659, -2659, -2659,
   -2659, -2659, -2659, -2659, -2659, -2659, -2623,  -456, -2659, -2658,
   -2138, -1779, -1406, -2659, -2659,  -442, -2659, -2659, -2659,   123,
    -618,  -601,  -634,   489, -1810, -2659, -2659, -2659, -2659,  1406,
   -2659,  -228, -2659, -2659, -2659, -2659, -2659, -2659, -2659, -2659,
    -573,  1059,  2257, -2659, -2659, -2659, -2659
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -2142
static const short yytable[] =
{
      32,    34,    36,   321,   261,    36,   180,   550,  1389,   249,
     289,   967,   397,   398,  1339,    84,  1327,  1124,  1435,  1288,
    1417,  1909,  1910,  1118,  1988,  1966,   399,   400,  1443,   100,
    2683,   412,  1336,  2168,  1396,  1397,    57,  1398,   229,  1419,
    1420,  2013,  2327,   924,   653,   914,  2526,  2577,  1387,    99,
    2770,    57,  1349,  1454,  2591,   919,  2123,  2124,  1052,   955,
     106,    84,    31,  2284,  1005,    31,    31,   113,  1390,    31,
     180,   118,  2167,  2714,   120,   121,  2049,    31,  2285,  2259,
     124,   125,   346,  3039,  3040,  3041,  2467,   993,    68,   180,
     993,   993,   571,  1022,   267,  2207,   490,   401,  1366,   572,
      57,   413,  2645,   415,   993,   416,   417,   418,    31,  2584,
    2587,  2451,  2211,  2587,   423,   109,  1366,   225,   434,   435,
     228,  3043,    31,   993,   319,   232,   993,   319,  1017,  1846,
    1077,  1082,   993,   267,  2894,  1236,   993,  1828,  1027,  1823,
     993,   267,  1931,  1018,   993,   354,   355,  1005,   993,   993,
    2501,   993,   499,  1833,   993,   326,   993,   993,   993,    68,
     267,   327,   328,   193,   993,  1931,  2634,   993,  2635,  1434,
    2979,  1334,  1824,    31,   993,  2051,  1334,  2052,    31,  2053,
     993,   267,   322,   323,    31,    31,   324,   993,  1161,   267,
    1235,  1236,    31,  1078,  2940,  1080, -2140,    31,   993,  1334,
      31,    31,   993,   543,  1117,     1,   993,  2943,   267,  1173,
    1174,    31,   993,   319,  2785,   993,  2788,  2789,   180,  1259,
    2789,  1122,   180,    31,    31,   351,   267,  1235,  1236,    31,
      31,   357,    31,   267,  1173,  1174,    31,   545,  1334,  2817,
      31,  1354,  1355,   386,  2218,  2219,  2220,  2221,  3064,   395,
     395,   395,   395,   395,  1334,  2789,    31,   395,    31,  2728,
     579,  2851,  2682,   582,    31,  1122,  1327,    31,  3150,   347,
      53,  2780,    31,  2782,   568,   991,  1045, -2140,    31,    31,
     590,   591,   592,   593,   432,   594,   595,   596,   597,   598,
     599,   600,   601,   602,   603,   604,   605,   606,   607,   608,
     609,   610,   340,  2400,  1426,  1427,    57,    57,  1334,   319,
      31,  1028,   611,   612,  1028,   319,   501,   614,   917,   615,
     629,  2739,  2096,   547,  1037,  2731,  2327,   319,  1028,   110,
    3280,  1183,  1028,  1850,   618,   619,   620,   621,  2067,  1054,
    2786,   627,  1182,   319,  1028,  3512,  1037,  1133,  2752,  2071,
    2007,  2477,  1065,  1436,  1437,  1037,  2049,  1376,  2712,   553,
      31,  3133,  1074,  3135,  3350,   105,  3091,  1326,  1081,  2090,
       1,   636,    31,  2527,   638,  1116,  2740,  2741,  2742,  2743,
    2744,  1852,   642,  1948,   507,  2057,  1065,   510,    41,  1432,
    1065,  1466,    68,  1001,  1065,     3,   918,   934,  1134,  2600,
    1037,    24,    25,  1037,  2471,  3225,   180,  2886,  3031,  3031,
    3031,  3031,    53,    31,  2791,  2792,  2821,  2793,  2794,  2795,
    2796,  2797,  2798,    42,    53,    53,  1948,  2584,  1377,  1953,
    1001,    73,   559,    53,    41,  1135,    74,    53,  1930,   558,
     555,  1433,  2532,    52,  1183,    31,  3218,   966,  2478,  2766,
    2532,  2791,  2792,  3147,  2793,  2794,  2795,  2796,  2797,  2798,
    2474,  3231,   180,  1067,  2575,    53,   103,    47,    53,  1998,
    3075,   569,  3078,  2575,   103,  2944,  1183,  2588,    31,    53,
      53,  2604,   990,    75,    76,  2606,  2660,  2718,    24,  2878,
      57,    77,   310,   311,   312,   313,   314,  2106,  2878,   801,
     894,  1069,  2152,  2153,  2855,  2906,   270,  2941,  2509,  1999,
     993,  2512,  2909,   935,  1971,  2999,  3000,   645,  2909,  3002,
     645,  1303,  1304,  1921,  3051,  3066,  3513,  1972,   645,    51,
    1113,  1114,  1136,   180,   310,   311,   312,   313,   314,  3244,
    3351,  3245,  1238,  2876,  3139,   386,    66,   386,  2895,  1305,
    1306,  1307,  3202,  1183,  2564,   916,   395,  1239,   921,  1167,
    2650,  2998,  1170,  2378,  3219,   555,  3219,  3227,  3319,     4,
    3356,  2097,  3356,  1000,    25,    31, -2140,  3225,  3225,  2904,
    1391,  1845,  2468,   320,  2344,  3414,   504,  3007,  2068,  3414,
     990,  2601,   560,  3449,   941,  3168,     6,  3171,  1238,  3465,
     163,  2887,  1861,  1858,  3343,  3086,  1175,  1471,  1137,  2022,
    3219,    98,   164,  1239,    53,  3181,    31,  2965,     5,  1373,
     108,  2036,   936,  1184,  1186,  3080,    31,   544,  2905,   993,
     993,   993,   990,  1392,  2722,  1238,  2065,  2852,  1967,   548,
    2871,  1984,  1449,  2882,  1452,   640,    53,   645,  1068,  1138,
    1239,  2980,    57,    57,    57,    57,   986,   988,  3236,   994,
     995,   546,     1,  1002,  1007,   101,   988,  1491,  1185,  1010,
     930,    57,   965,  1920,  2181,  3151,  1955, -2140,  3068,     7,
     995,  3031,  3031,  2899,  2994,  3031,  1367,  3030,  3030,  3030,
    3030,  1996,     3,  2023,  2880,  2799,  2738,  2900,  1116,   573,
     995,  1988,  1455,  1904,  1386,  3158,    57,  1148,  1176,  3163,
    1997,  1858,    57,   995,    57,  1893,  1139,  2729,    57,  3322,
    1932,    57,   110,  1055,    57,  2054,   288,  1005,  2502,  3128,
    3326,  3131,  2799,  2055,    57,  2017,  1828,  1186,   920,   395,
    1071,   392,   392,     2,  1974,    78,  1002,  1393,  2459,    57,
    3194,  2540,  1005,   392,    57,   170,   395,   395,  2346,  1359,
    1975,    57,    57,    57,  3476,   288,  1360,  1142,  1289,  1186,
    1149,    79,  1911,   288,  2903,    57,  1001,   902,  1185,   171,
    1356,  2225,  1162,   554,  1162,   395,  3184,  1162,   395,  3281,
    1162,    57,   288,  1275,  2579,   637,  1275,  3246,   639,  2579,
    2154,  2093,  3462,  2096,   627,   627,   643,  1949,   151,  2624,
      31,   903,  1438,   288,  2800,  2801, -2140,  1843,  1081,  1116,
    2757,   288,  2579,   172,  2407, -2140, -2140, -2140, -2140, -2140,
    2484,   272,   173,  2873,  2208,  2230,  3232,  3318,   990,  2485,
     288,   114,    80,  3321,  1892,   459,  1186,  3406,  1492,  3434,
    1950,  2800,  2801,  1954,  3138,  3198,   275,  3142,   288,  1912,
    2076,  2579,   460,  2364,  2486,   288,  2533,  2487,  2161,  2162,
    2923,  2802,  1971,  1046,  2539,  1913,  2928,  2169,   112, -2140,
    3031,   187,  1971,  3349,  2488,  1972,  3031,  3031,  2576,  3031,
    3031,  3031,  3031,     6,  1211,  1972,  1191,  2578,  3031,  1439,
   -2140,  2589,  3081,  2132,  3235,  2605,     3,  3004,  2802,  2607,
    2661,  2719,  2745,  2879,  2212,  3008,   174,   175,  1914,  2171,
    1829,  1308,  2881,  2101,    31,   226,  1187,  1188,  1189,  2907,
    3038,  3038,  3038,  3038,    81,  1252,  2910,  1190,  1225,   281,
    2821,  1959,  2914,  3003,   983,  1000,    31,    31,  3052,  3067,
    2229,   461,   462,   463,   464,   465,   466,  1915,   186,  3249,
    3030,  3030,  3254,  2010,  3030,  3256,  2513,  3125,  3140,   467,
     468,   469,   190,  1298, -2140,   645,  3203,   358,  2251,  2649,
    3300,  2209,  1959,  1075,   227,    31,  1916,  2352,  3220,  2489,
    3226,  3228,  3320, -1536,  3357,  1917,  3358,  3031,  2803,  1002,
    3031,  3031,  3031,  3031,   359,   234,  3405,  1309,   549,  3415,
    3411,    53,  1335,  3421,    82,    57,  2619,  3450,   236,  1291,
    2619,  3252,    83,  3466,  3252,  3348,     4,   246,   587,    57,
    2213,   284,  1335,  2189,  3496,  2803,  2929,  2137,  3323,  3082,
     650,  3083,  2490,   285,   286,  2172,   243,  1493,   900,  2491,
    1310,   287,  2097,  1011,    31,  3324,  2173,  1973,   310,   311,
     312,   313,   314,  2233,  2804, -2140,  1122,  1987,    31,  2388,
      57,  3073,    52,  3076,    31,     5,  3079,  2174,  3088,  1960,
    1494,  3338,  3031,  1476,  2175,    31,  1016,    57,    57,    57,
    3031,    57,  3346,    57,    57,  2492,  2359,    31,   404,    57,
      57,  2804,  1974,   405,  2528,   407,  1032,     6,  2990,    31,
     470,   896,  1974,   471,  2805,  2806,  3487, -2140,  1975,  1041,
    1960,  1839,  2189,    31,  -272,    53,  3262,  3089,  1975,  2132,
   -2140,  2320,  1069,  2321,   897,  1464,     7,    57,  2018,  2214,
      31,  2370,  2037,  3359,   102,   103,  1475,    53,  1001,    57,
    1423,  2805,  2806,   250,  1483,  1399,  1961,  1430,  2646,  3030,
    2593,  2594,  2967,  1829,    31,  3030,  3030,   978,  3030,  3030,
    3030,  3030,   244,    57,    57,  3263,  2190,  3030,   247,  3199,
    2385,  2476,    57,  2457,  2001,  2320,  1001,  2321,  2992,    31,
    2172,    31,   251, -2140,  3354,  2191,  2192,  1961,    57,    57,
     252,  2173,  2200,  3038,  3038,   953,  2216,  3038,   956,    31,
   -2140,  -272,  2216,  1259,  1956,  2193,   253,  1958,  2238,  2239,
    2240,  2241,  2174, -2140,  1895,  2083,  3121,  -272,    31,  2175,
    1252,  1252,   472,  2081,  2391,   402,   403,  2322,  3209,  1252,
    2323,    31,   325,  2229,   317,  2234,   330,   473,   316,  1929,
    2291,   474,  2935,  3129,  1962,    53,  2235,  1935,  1963,    31,
      31,   344,  2132,  2137,  3253,  2190,   254,  3253,  1468,    53,
    -272,   102,   103, -2140,  1964,    53,  3030,  1206,  1207,  3030,
    3030,  3030,  3030,   255,  2191,  2192,    53,  1322,  1323,   475,
       9,  2322, -2140, -2140,  2323,   102,   103,  2870,    53,  1963,
    1995,   128,  1968,  3252,  2193,     9,  1976,  1985,  1976,  -272,
      53,    35, -2140,    31,  2698,  1964,  2132,   476,  1991,  1992,
    1988,  3435,    57,  1002,    53,  2898,  1002,   256,  2002,  2005,
    1335,   928,  3161,   929,   318,   477,  2369,   257,  -272,    31,
     129,    53,  3397,  3398,   491,  1400,  2242,  -272,  2105,   103,
    3257,  1002,    57,   258,    57,    57,    57, -2140,  1469,   130,
     131,  3030,   259,    57,    57,    53,   896,    57,   395,  3030,
     395,    57, -2140,  1030,   260,  3481,  3441, -2140,  2132, -2140,
    2125,  2048,  2126,  2127,  2128,   262,    57,  1039,  1213,   897,
      53,  1044,  2399,  3454, -2140, -2140,  2137,   350,   132,  2733,
    2211,  2456,  3038,  1058, -2140,  2184,  2185,  1200,  3038,  3038,
     133,  3038,  3038,  3038,  3038,  2469,   478,   304,  1201,  2750,
    3038,   134,  2771,   305,  3458,  2773,  3460,   306,  3452,    53,
    3436,    57,  2132,  3330,  3437,    31,   307,  1060,   135,  3330,
    3441,   308,  3339,  3340,  3341,  3342,  1066,   309,   136, -2140,
    2137,   361, -2140, -2140, -2140,  2303,  2078,  3454,   395,   395,
     331,   332,   333,   395,   137,    57,   337,  2087,  2088,   414,
    1202,  1166,  1401,   993,  1169,  2721,   362,  1172,  1402,  1403,
    1404,   341,   479, -2140,  3436,  1203, -2140,   342,  3437,  1259,
      57,  1165,   345,  2890,  1168,  2892,  2893,  2531,  1405,   349,
    2534,  2535,  2536,  2537,   138,  1147,  2333,  2334, -2140,  1153,
     352, -2140,  2137,  1157,   356,  2753,  1424,  1425,   371,  3038,
    1428,  1429,  3038,  3038,  3038,  3038,  1906,   139,  1907,   987,
    3329,    31,  3332,  3333,  3334,  3335,  1000,  2125,    31,  2126,
    2127,  2128,   140,  1334,  2611,    31,  3253,  1187,  1188,   141,
    3413,   380,   142,  3416,  3417,  3418,  3419,   381,  2229,  2625,
    2229,  2626,  1462, -2140,    31,   387,  2137, -2140,  1938,  1939,
    2637,  3467,  3468,   143,  1204,   390,  1993,   144,    31,   993,
     391,  1936,  1937,  1938,  1939,  2204,  2948,  2205,  2911,  3072,
    3072,  2358,  3072,  2119,  2120,  3072,   145,   993,  2061,   419,
    3492,  2974,    31,   421,  3038,   443,  1406,  3207,  3208,  1407,
     363,  2019,  3038,  2019,   146,   422,   372,  1408,   433,  3143,
    2989,   436,   437,  3146,   439,  2945,   440,   457,   458,   459,
     310,   311,   312,   313,   314,  3471,   441, -2140,   442, -2140,
   -2140, -2140, -2140,   492,   503, -2140,   460,  1340,  1341,  1342,
    2129,   505,  1409,  2130,   509,  2131,   424,  1444,  1445,  1446,
    1447,  2332,   448,   449,   450,   451,   452,   453,   454,   455,
     456,   457,   458,   459,   511,  2132,  1940,  1941,  1942,  1943,
    1944,  1945,   512,   517,   515,  2133,   516,  1410,  1896,   520,
     460,  1940,  1941,  1942,  1943,  1944,  1945,   364,   521, -2140,
     531,   532,   533,   373,  2134,   536,  1411,  1412,   541,   404,
    2856,   551,  2160,   365,   405,   406,   407,  1413,  2164,   374,
     552,  2953,  1414,   557,   558,  2857,  2858,  2135,   561,  2961,
    2962,  2136,   562,   563,  2859,   461,   462,   463,   464,   465,
     466,  1019,  1019,   425,   564,   565,  2620,   567,   574,   575,
     580,   583,   584,   467,   468,   469,   366,   585,   588,   426,
     613,  1415,   375,  1911,  1259,   616,   622,  1081,  2860,   623,
     628,   630,   631,   632,   633,  1897,   634,  2861,   635,   461,
     462,   463,   464,   465,   466,  1116,   641,   651,     1,  2243,
    2657,  1898,   901,  1416,   906,   367,   908,   467,   468,   469,
     909,   376,   427,   910,   915,  2197,  2862,  2129,   925,  2137,
    2130,   926,  2131,   927,  2775,   933,  2518,   940,  1162,   395,
     395,   938,   942,   943,   368,    57,    57,  2345,   944,  2787,
     377,   961,  2132,   369,  1899,   963,   968,  1019,  2690,   378,
    2811,   428,  2133,   970,   971,  2156,   972,  1177,  1335,  1335,
    1912,  2863,   974,  2165,   975,  2165,   976,  1335,   977,   979,
    1154,  2423,  2901,  3267,  1215,  1217,  1913,  1216,  1218,  3072,
     429,  1219,  2248,  1900,  1220,  1221,  2915,  1222,  1223,   430,
    1224,    57,  1226,  1227,  2135,  1228,  1229,  1230,  2136,  2414,
    2416,  1231,  2201,  2864,   470,   993,  1265,   471,  1272,  1273,
    1274,   993,  1901,  2519,  1277,  1278,  1280, -2140,  1281,  1914,
   -2140,  1902, -2140,  2357,  2337,  1282,  2426,  1283,  1284,  2520,
    1002,   993,  1252,  1285,  1286,  1290,  1294,   627,  1252,  1252,
    1335,  1296, -2140,  1320,  1252,  1252,  1252,  1252,   470,  1295,
    3268,   471, -2140,  1297,  1301,  1002,  1324,  1321,  1915,  1325,
     103,  1328,  3174,  1331,  1333,  1332,  1337,  1330,  1335,  1353,
    1357, -2140,  2521,  1358,  3268,  1361,  2137,  1362,  1364,  1369,
    1381,  1976,  1383,  2399,  1365,  1370,  1372,  1916,  1388,  1421,
    1431,  1434,  1985,  1441, -2140,  1976,  1917,  1450, -2140,  1458,
    1459,  1253,  1460,  1467,  1461,  1470,    57,  1465,  1471,  1480,
    1482,  2522,  1291,  3269,  1259,  3270,  2299,  2300,  2301,  1819,
    1820,  1827,  1821,  2305,  3176,  1831,   472,  1837,  1822,  1835,
    3271,  1836,  1834,  1883,  1891,  1922,  1894,  3269,  3272,  3270,
    2523,   473,  3273, -2140,  1947,   474,  1923,  1905,  1924,  2524,
    2330,  1925,  1926,  1327,  3271,  1927,  1928,  1970,  1952,  1990,
    2340,  2341,  3272,   395,  2008,  3291,  3273,  3274,  2009,  2010,
     472,  3223,  3224,  3299,  2011,    57, -2140,  1399,  2012,  2014,
    2016,  1177,    57,   475,   999,   473,  2029,  3304,  2015,   474,
    2367,  3274,    57,  1081,  2229,  2035,  2044,  1015,  2049,  1116,
    3084,  2046,  2042,  2059,  2069,  2060, -2140,  2070, -2140,  2072,
    2074,   476,  2079,    57,  2107,  2392,  1483,  2082,  1252,  1116,
    2612,  1002,    57, -2140,  2084,  1033,  2100,   475,  2093,   477,
    2102, -2140,  2108,  2110,  1829, -2140,  2144,   395,   395,  2146,
     949,  1050,  1051,  2147,  2149,  2198, -2140,  1057,  2155,  2202,
    1059,  2203,   395,  2208,  2230,   476,  2206,    57,    57,    57,
   -2140,   993,   993,    57,  3144,  2244,  3347,  2254,  2287,  2256,
    2257,  1335,  2222,   477,  3221,  3222,  3223,  3224,  3152,  1940,
    1941,  1942,  1943,  1944,  1945,  1264,  2260,  2261,  1266,    57,
    1267,  1268,  1269,  1270,  1271,  2289,  2290,  2508,  2508,  2293,
    2296,  2508,  2294,  2292,  2307,  2309,   180,  2310,  2311,  2312,
     478,  2315,  2313,  2316,  2317,  1252,  2318,  3391,  2331,  1828,
    2347,  2319,  2349,  1252,  2350,  2354,  1252,  1252,  1252,  1252,
    2538,  2356,  2362,  1335, -2140,  2363,  2365,  2543,  1252,  1177,
    2368,  2561,  3093,  3094,  3095,  2371,  3097,  3098,  3099,  3100,
    3101,  3102,  2395,  2375,   478,  3105,  2381,  2372,  2407,  2389,
    2409,  2454,  1252,  2455,  2580,  2580,  1190,  1400,  2580,  1252,
    2466,   154,   155,  2472,  2495,  2481,   479,  2498,  2505,   156,
      31,  1889,  2480,  2516,  1940,  1941,  1942,  1943,  1944,  1945,
    2497,  2517,  2530,  2529,  2542,  2608,  1253,  1253,  2002,  2558,
      57,  2563,  2565,  2566,  2614,  1253,  2567,  2571,  2610,  2574,
    1976,  2592,  2617,  2595,  1976,    57,  3396,    57,  2596,  3464,
     479,  2597,  2633,  2580,  2598,  2599,    57,  2330,  2622,  2651,
    2642,  2642,  3442,  3443,  3444,  3445,  3446,  3447,  2653,  2655,
    2654,  2658,  2664,  2665,  2667,  2668,  2670,  2669,   157,  1081,
    1081,  2671,  2656,  2691,  2672, -2140,  1024,  2688,  2689,  2692,
     158,  2693,  1189,    57,  2697,  2704,  2706,  2715,  2716,  2717,
    2720,  2724,  2725,  2734,  2732,  3258,  2755,  2811,  2760,  1038,
    2768,  2769,  2774,  2776,  2772,  2777,  2789,  2778,   159,  2779,
    2784,    57,  2790,  2812,  1401,  2815,  2875,  2876,  2877,  2885,
    1402,  1403,  1404,  2883,  2888,  2891,  2902,  2912, -2104,  2913,
    2916,  2919,  2926,  3293,    60,  2918,  2930,  2699,  2934,  2937,
    1405,  2949,  2952,  2960,  1111,  2970,  2984,  2995,  3004,  2996,
    1931,  3011,  3049,  1125,  1131,  3053, -2140,  1146,  3061,  3060,
    3062,  1152,  1920,  3063,  3074,  3065,  3085,  1158,  3087,  1160,
    3077,  3092,  1177,  3096,  3103,  3104,  3111,  3110,  3114,  3459,
    3115,  3132,  3116,  3117,  3118,  1335,  3119,  1960,  3120,  3136,
    3126,  3134,  3141,  3153,  2985,  3148,  2987,  3154,   152,   183,
    2580,    53,  3261,   160,  3155,  3156,  3170, -2140,  2736,  2165,
    1252,  1259,  3172,  3175,  3179,  3187,  1184,   894,  3190,  3200,
    3194,  3210,  3211,  2580,  3212,  1335,  3213,  3214,  3215,    57,
    2508,  3219,  3216,  3229,  2951,  3230,  2972,   627,  3240,  1019,
    3516,  3243,  3265,  2873,  3247,   627,   627,  3283,  1406,  2337,
    3284,  1407,  3286,  3287,  3289,  3288,  3292,  3296,  3298,  1408,
    1252,  3302,  3303,   183,  3305,  3306,  3309,  3307,  1335,  3311,
    1335, -2140,   894,  1252,  3376,  1252, -2140,  3315,  1932,  3325,
    3327,  3344,   183,  3336,  3360,  3370,  1252,  3371,  3372,  3374,
    3389,  2580,    57,  2561,  1409,  3377,  3373,  3390,  3395,  3412,
     161,  3448,  2580,  3402,  3461,  3422,  3433,  2580,  3470,  3472,
    3473,  3474,  3475,  3485,  3502,  3504,  1976,  3505,  3506,  3507,
    3515,  2956,   180,  3484,  2908,  1287,  2680,  2092,  2380,  1410,
      48,    49,  1985,   162,  1976,   802,  2638,  3410,    57,  2933,
    2647,   513,   336,   189,   194,  2299,   969,   508,  1411,  1412,
    2245,   339,    57,  2246,   644,   932,   514,  1908,   540,  1413,
     538,   905,   911,   912,  1414,  3482,  2304,  1279,   163,  1141,
     570,  2080,  3425,  1887,  2629,  2506,  2514,  2330,  2118,  2936,
     164,  2938,  2580,  3189,  2342,  2122,  2983,  2406,   993,  2696,
    3503,  2424,  2636,  2039,  3301,    57,    44,    57,  2957,    57,
     126,    45,  3278,  1415,   497,   498,    46,  2390,  2387,   502,
    1056,   183,    57,  3242,  1346,   183,  1214,   165,  2143,  1252,
      57,    57,  2978,  1300,  2394,  1825,  3266,  3361,  2031,  2064,
    1079,  3488,   395,   166,   395,  1416,  3165,  2976,  2021,  3124,
    3369,   167,  2075,   589,    57,    57,  3167,  1453,  3123,  3106,
    1252,  2868,  3145,  2288,   168,  2623,  2255,  2726,  3491,  3260,
    3127,  2754,  2580,  3423,  3069,  2869,  2541,  2590,  3029,  3029,
    3029,  3029,  2580,  2580,  2475,  3070,  2783,  3410,  3424,  3255,
    2159,  3282,    40,    57,  1009,  2872,  3511,  2822,  3055,  2823,
    3206,  1875,  3010,  3259,  2224,  3160,  3404,  2223,   169,  2151,
    1842,  3328,  3205,  3345,  1111,  2116,  3337,  2038,  2942,  2609,
       0,     0,   652,     0,  1125,     0,     0,  1252,  1252,  1457,
       0,     0,     0,   170,     0,     0,     0,     0,  1252,  1252,
     627,  1252,     0,     0,  1252,     0,  1252,     0,     0,     0,
    1252,     0,     0,     0,     0,     0,     0,   171,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   180,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1116,     0,     0,    57,
     453,   454,   455,   456,   457,   458,   459,     0,   617,     0,
       0,   172,    57,     0,     0,     0,     0,     0,     0,   183,
     173,     0,     0,   460,  2580,  3130,  2580,     0,     0,  2545,
       0,     0,  1177,     0,     0,     0,     0,     0,  1232,  1233,
    1234,     0,     0,     0,   267,  1235,  1236,    31,     0,     0,
      57,     0,     0,     0,  2614,     0,     0,  1976,  3290,     0,
       0,     0,     0,     0,    57,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  2642,   183,     0,  3162,  2642,     0,
       0,     0,   395,     0,     0,     0,     0,     0,     0,     0,
    2179,  2180,   395,     0,    57,     0,     0,  2196,     0,     0,
       0,     0,     0,    57,   174,   175,     0,     0,     0,     0,
       0,     0,   461,   462,   463,   464,   465,   466,     0,     0,
    1237,     0,     0,     0,     0,     0,     0,     0,  1253,     0,
     467,   468,   469,     0,  1253,  1253,     0,     0,     0,     0,
    1253,  1253,  1253,  1253,  3191,     0,   183,     0,     0,     0,
    2580,     0,     0,     0,     0,     0,     0,     0,     0,  2736,
       0,  3029,  3029,     0,     0,  3029,  2024,  2025,  2026,     0,
     980,   981,   982,   984,     0,     0,  3217,     0,     0,     0,
       0,     0,     0,  2043,     0,     0,     0,     0,     0,  1013,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  2580,
       0,  2156,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1335,     0,     0,     0,     0,     0,
       0,     0,  1002,     0,  1035,  1002,     0,     0,  1252,     0,
    1040,  1252,  1042,  1252,     0,  2580,  1049,     0,     0,  1049,
       0,  2066,  1049,     0,     0,     0,     0,     0,  1001,     0,
       0,     0,  1061,     0,     0,     0,     0,     0,    57,     0,
       0,  1125,     0,     0,     0,     0,     0,  1061,     0,     0,
       0,   470,  1109,     0,   471,     0,     0,     0,  2089,   984,
    1120,  1123,  3401,     0,     0,  1143,  2361,     0,     0,  2104,
       0,     0,     0,  1155,     0,     0,   395,     0,     0,    57,
       0,  2545,     0,     0,     0,     0,     0,     0,   460,  1179,
    1232,  1233,  1234,     0,  1253,     0,   267,  1235,  1236,    31,
       0,     0,     0,     0,     0,     0,  2404,   450,   451,   452,
     453,   454,   455,   456,   457,   458,   459,     0,     0,     0,
       0,     0,    57,     0,     0,     0,     0,  1252,     0,     0,
    2580,     0,  2546,   460,     0,     0,     0,     0,  1002,     0,
    3029,     0,     0,     0,     0,     0,  3029,  3029,   180,  3029,
    3029,  3029,  3029,     0,     0,  2580,     0,  2580,  3029,     0,
    1252,     0,    57,     0,     0,   627,     0,     0,     0,     0,
       0,     0,  1237,   472,     0,     0,     0,   461,   462,   463,
     464,   465,   466,     0,     0,     0,     0,     0,   473,     0,
       0,  1253,   474,    57,     0,   467,   468,   469,    57,  1253,
      57,     0,  1253,  1253,  1253,  1253,     0,     0,     0,     0,
       0,     0,     0,     0,  1253,     0,     0,     0,     0,     0,
      57,     0,   461,   462,   463,   464,   465,   466,     0,     0,
     475,     0,     0,  1238,     0,     0,     0,    57,  1253,     0,
     467,   468,   469,     0,     0,  1253,     0,  3191,  1239,     0,
       0,     0,     0,  1252,     0,     0,     0,  3029,   476,     0,
    3029,  3029,  3029,  3029,  3420,  1240,     0,     0,  2547,     0,
       0,     0,     0,     0,     0,     0,   477,     0,  2156,     0,
    2548,  1242,     0,     0,  1002,     0,     0,     0,  1252,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1001,     0,     0,     0,     0,     0,    57,    57,    57,    57,
      57,    57,     0,  1179,     0,     0,     0,     0,  3453,     0,
       0,  1243,     0,     0,     0,     0,     0,  1347,     0,     0,
       0,     0,     0,  1244,     0,     0,   470,     0,     0,   471,
       0,     0,  3029,     0,     0,     0,     0,     0,  2825,  2826,
    3029,  2827,  2828,  2829,     0,     0,     0,   478,     0,     0,
       0,     0,  2676,  2677,     0,     0,     0,     0,  1375,     0,
       0,     0,     0,  2686,  1245,     0,     0,     0,     0,     0,
       0,   470,     0,     0,   471,  1395,  1395,  1395,     0,  1395,
       0,  1395,  1395,  1252,     0,  3493,     0,    60,    60,  2700,
    2701,  2702,  2703,     0,  2546,     0,     0,  2708,  2709,  2710,
    2711,     0,     0,  1246,  2713,     0,     0,     0,     0,     0,
       0,     0,     0,   479,     0,  1247,     0,     0,     0,     0,
       0,     0,  3509,  3510,  3493,  1123,     0,  1248,  1249,     0,
       0,    57,     0,  3517,     0,  1250,     0,  1478,  1251,     0,
       0,     0,     0,  2830,     0,     0,   288,     0,   472,     0,
       0,  2831,     0,     0,     0,     0,  1253,     0,     0,     0,
       0,  1179,  1347,   473,     0,     0,     0,   474,     0,     0,
    1832,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  2758,  2759,     0,  2832,  1840,  1840,     0,  2763,
    2764,     0,     0,   472,  2833,  1238,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   475,  1253,     0,   473,     0,
    1239,     0,   474,     0,     0,     0,     0,     0,     0,  1253,
       0,  1253,     0,  2834,  2835,     0,     0,  1240,     0,     0,
    2547,     0,  1253,   476,     0,     0,     0,     0,     0,     0,
       0,     0,  2548,  1242,  2427,  2428,  2429,  2430,  2431,  2432,
     475,   477,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  2836,     0,
    1920,     0,     0,     0,     0,  1253,     0,     0,   476,     0,
       0,     0,     0,  1243,     0,     0,     0,     0,     0,     0,
       0,  1346,     0,     0,     0,  1244,   477,     0,     0,   264,
       0,     0,     0,     0,     0,     0,  2314,     0,   265,   266,
    2837,     0,     0,     0,   267,   268,   269,    31,  2924,  2925,
       0,     0,     0,     0,     0,     0,  2336,  2932,     0,     0,
       0,  2026,   478,     0,  2433,     0,  1245,     0,     0,     0,
      60,     0,    60,  1123,  1049,     0,     0,     0,     0,     0,
       0,  2030,  1061,     0,     0,  1123,     0,  2963,  2964,  2040,
       0,     0,     0,     0,     0,  1253,  2838,     0,     0,     0,
    2377,     0,     0,     0,  1179,  1246,  2262,   478,     0,     0,
       0,     0,     0,     0,  2986,   157,  2988,  1247,     0,     0,
     270,     0,     0,     0,     0,     0,  1253,   158,   479,  1248,
    1249,     0,     0,     0,     0,     0,     0,  1250,     0,     0,
    1251,     0,     0,     0,  1253,  1253,  1253,  1253,   288,    60,
       0,     0,     0,     0,     0,   159,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    3056,  3057,     0,   479,  3058,  3059,     0,     0,     0,     0,
       0,     0,     0,  2085,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1253,  1253,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1253,  1253,     0,  1253,  2112,     0,
    1253,     0,  1253,     0,     0,     0,  1253,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1019,  1019,  1019,     0,  1019,  1019,  1019,  1019,  1019,
    1019,     0,     0,     0,  1019,     0,     0,     0,    53,     0,
     160,     0,   449,   450,   451,   452,   453,   454,   455,   456,
     457,   458,   459,     0,  3113,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   460,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    2434,  2613,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  2435,     0,     0,     0,  2627,  2628,  2026,
    2631,     0,     0,  2839,  2840,  2841,  2842,  2843,  2844,  2845,
    2846,  2847,  2848,     0,     0,     0,  3159,     0,  2652,     0,
    3164,     0,     0,     0,  2263,     0,     0,   161,     0,     0,
       0,     0,   271,     0,     0,     0,  3169,     0,     0,  1177,
       0,     0,     0,     0,  2264,     0,     0,     0,   461,   462,
     463,   464,   465,   466,     0,  3180,     0,  2436,     0,     0,
     162,     0,     0,     0,  2437,     0,   467,   468,   469,     0,
       0,     0,     0,     0,     0,     0,  2687,  1232,  1233,  1234,
       0,     0,  2265,   267,  1235,  1236,    31,     0,     0,     0,
       0,     0,     0,     0,  2266,   163,     0,  1253,  1253,     0,
       0,  1253,   264,  2438,     0,  2267,     0,   164,     0,     0,
       0,   265,   266,     0,     0,     0,     0,   267,   268,   269,
      31,     0,  2268,     0,     0,   272,     0,  2439,     0,     0,
     273,     0,  2269,   274,     0,  2270,     0,  2440,  2441,     0,
       0,     0,     0,  2442,   165,     0,     0,     0,  2271,     0,
     275,     0,     0,  2443,     0,     0,     0,     0,  1253,  1237,
     166,  1253,     0,     0,  1253,   276,     0,  1253,   277,  1253,
       0,   278,  2747,     0,  2748,  2444,     0,     0,  2445,  2446,
     279,   168,     0,  2447,     0,     0,     0,     0,   157,     0,
       0,     0,     0,   270,     0,     0,  2272,     0,     0,     0,
     158,     0,     0,     0,     0,     0,     0,   470,     0,     0,
     471,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1343,   280,     0,  2142,  1179,   169,  2273,     0,   159,     0,
       0,     0,     0,   281,     0,     0,  2274,     0,     0,     0,
    2448,     0,     0,     0,   282,     0,     0,     0,     0,     0,
     170,  2449,     0,     0,     0,     0,     0,  2275,     0,     0,
       0,  2276,     0,     0,     0,     0,     0,     0,  1847,     0,
       0,     0,  3314,     0,   283,  3317,     0,     0,     0,  2183,
       0,     0,     0,  1253,     0,     0,     0,  1001,     0,  2277,
       0,     0,     0,     0,     0,     0,  1253,     0,  2278,     0,
       0,     0,  1253,  1253,     0,  1253,  1253,  1253,  1253,     0,
       0,     0,     0,     0,  1253,     0,  1253,  2917,   172,     0,
    2922,    53,     0,   160,     0,   284,     0,   173,     0,   472,
       0,  1253,     0,     0,     0,     0,     0,   285,   286,     0,
       0,     0,     0,     0,   473,   287,     0,     0,   474,     0,
       0,     0,     0,     0,     0,     0,   288,   264,     0,     0,
       0,     0,     0,     0,     0,     0,   265,   266,     0,     0,
       0,  1848,   267,   268,   269,    31,     0,  1111,     0,  1849,
       0,     0,     0,     0,     0,  1850,   475,  1851,     0,     0,
       0,  2546,     0,  1177,  1123,     0,     0,     0,  1852,     0,
       0,     0,  3399,     0,     0,     0,     0,     0,     0,  1253,
       0,   174,   175,  1253,   476,     0,  1253,  1253,  1253,  1253,
     161,     0,     0,     0,     0,   271,  1853,     0,     0,     0,
       0,     0,   477,     0,     0,     0,     0,     0,     0,     0,
    1253,     0,  1854,   157,  1253,     0,     0,  1855,   270,     0,
       0,  3426,  3427,   162,  3429,   158,  3431,  3432,     0,  1856,
       0,     0,     0,  2353,     0,     0,  1857,     0,     0,     0,
    2360,     0,   454,   455,   456,   457,   458,   459,     0,     0,
    1123,     0,     0,   159,     0,     0,     0,     0,   163,     0,
       0,     0,  1238,     0,   460,     0,     0,     0,  1253,     0,
     164,   152,     0,     0,     0,     0,  1253,  1239,     0,     0,
    2401,     0,     0,   478,     0,     0,     0,  3477,   272,  3478,
       0,     0,     0,   273,  1240,     0,   274,  2547,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   165,     0,  2548,
    1242,     0,     0,   275,     0,  1123,  2458,  1123,     0,  1253,
       0,   984,  3490,   166,     0,     0,     0,     0,   276,     0,
       0,   277,     0,     0,   278,     0,     0,     0,  3497,  3498,
       0,     0,  3499,   279,   168,  3501,    53,  2500,   160,   479,
    1243,     0,     0,   461,   462,   463,   464,   465,   466,     0,
       0,     0,  1244,     0,     0,     0,     0,  1177,     0,     0,
       0,   467,   468,   469,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   280,     0,     0,     0,   169,     0,
    1858,     0,     0,     0,  3166,     0,   281,  1859,     0,     0,
       0,     0,     0,  1245,     0,     0,     0,   282,     0,  2630,
       0,     0,     0,   170,     0,     0,     0,     0,     0,  1860,
       0,     0,     0,     0,  1861,     0,     0,  3182,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   283,     0,     0,
       0,     0,  1246,     0,     0,   161,     0,     0,     0,     0,
     271,     0,     0,     0,  1247,     0,     0,     0,  1123,   183,
       0,     0,     0,     0,     0,     0,  1248,  1249,     0,     0,
       0,     0,     0,  1123,  1250,  1123,     0,  1251,   162,     0,
       0,   172,     0,     0,  1123,   288,     0,     0,   284,     0,
     173,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     285,   286,     0,     0,     0,     0,     0,     0,   287,     0,
       0,     0,   470,   163,     0,   471,     0,     0,     0,   288,
     264,  2662,     0,     0,     0,   164,     0,     0,     0,   265,
     266,     0,     0,     0,     0,   267,   268,   269,    31,     0,
       0,     0,     0,   272,     0,     0,     0,     0,   273,  2685,
       0,   274,     0,     0, -2141,     0,     0,     0,     0,     0,
       0,     0,   165,     0,     0,     0,     0,     0,   275, -2141,
       0, -2141, -2141, -2141,   174,   175,     0,     0,   166,     0,
       0,     0,     0,   276,     0,     0,   277,     0,     0,   278,
       0,     0,     0,     0,     0,     0,     0,     0,   279,   168,
       0,     0,     0,     0,     0,     0,   157,     0,     0,     0,
    3294,   270,     0,     0,     0,     0,     0,     0,   158,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0, -2141,
       0,     0,     0,     0,   472,     0,     0,     0,  2973,   280,
       0,     0,  3316,   169,     0,     0,   159,     0,     0,   473,
       0,   281,     0,   474,     0,     0,     0,     0, -2141,     0,
       0,     0,   282,     0,     0,     0,     0,  2756,   170,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   475,   283,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0, -2141,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   476,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1123,     0,     0, -2141,     0, -2141,   172,   477,     0,    53,
       0,   160,     0,   284,     0,   173,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   285,   286,     0,     0,     0,
   -2141,     0,     0,   287,     0,     0,     0,     0, -2141,     0,
   -2141,     0,     0,     0,   288,     0,  1123,     0,     0, -2141,
       0,     0,     0,     0,     0, -2141,     0,     0,     0,     0,
    1123,     0,     0, -2141,     0,     0,     0, -2141,     0,     0,
       0,     0,     0, -2141,     0,     0,     0, -2141, -2141, -2141,
   -2141,     0,     0,     0,     0,     0,     0,     0,   478,     0,
       0,     0, -2141,     0,     0,     0,     0,     0,     0,   174,
     175,     0,     0,  2954,     0,  1013,     0,  2958,   161, -2141,
       0,     0, -2141,   271, -2141,     0,  3451,     0,     0,     0,
    2969, -2141,     0,     0,     0,   183,     0,     0,  2977,  2401,
       0,     0,     0,     0, -2141,     0,     0,     0,     0,     0,
       0,   162,     0,     0, -2141,   128,     0,     0,     0,     0,
       0,     0,  2991,  2993,   479,     0,     0,     0,     0,     0,
       0,     0,     0, -2141, -2141,  1232,  1233,  1234,     0,     0,
       0,   267,  1235,  1236,    31,     0,   163,     0, -2141,     0,
       0,     0,     0,     0,   129,     0, -2141,     0,   164,     0,
   -2141,  3054,     0,     0,     0,     0,     0,     0,     0, -2141,
   -2141, -2141,     0,   130,   131,     0,   272,     0,     0,     0,
       0,   273,  3500,     0,   274,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   165,     0,     0,     0,     0,
       0,   275,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   166,   132,     0,     0,     0,   276,  1237,     0,   277,
       0,     0,   278,     0,   133,   455,   456,   457,   458,   459,
       0,   279,   168,     0,     0,   134,     0,     0, -2141,     0,
       0,     0,     0,     0,     0,     0,   460,     0,     0, -2141,
       0,     0,   135,     0,     0,     0,     0,  3107,     0,     0,
       0,     0,   136,     0,     0,     0,     0,     0,     0,     0,
    3122,     0,   280,     0,     0,     0,   169,     0,   137,     0,
       0,     0,     0,     0,   281,     0,     0,     0,     0, -2141,
       0,     0,     0,     0,     0,   282,     0,     0,     0,     0,
       0,   170,     0,     0,     0,     0,     0,     0,  1123,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   138,     0,
       0,     0,  1123,     0,     0,   283,     0,     0,     0,     0,
       0,     0,     0,     0,   183,   461,   462,   463,   464,   465,
     466,   139,     0,     0,     0,  1001,     0,     0,     0,     0,
   -2141,     0,  2401,   467,   468,   469,   140,     0,     0,     0,
       0,  1179,     0,   141,     0,     0,   142,     0,     0,   172,
       0,     0,     0,     0,     0,     0,   284,     0,   173,     0,
       0,     0,     0,     0,     0,     0, -2141,   143,   285,   286,
       0,   144,     0,     0,     0,     0,   287,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   288,     0,     0,
     145,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   146,     0,
       0,     0, -2141,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0, -2141, -2141, -2141, -2141,
   -2141, -2141, -2141,     0, -2141, -2141,     0,     0,     0,     0,
       0,     0,   174,   175,     0,     0,     0,     0,     0,     0,
       0, -2141,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   470,     0,     0,   471,     0,     0,
       0,     0,     0,     0,  1495,  1496,  1497,  1498,  1499,  1500,
       0,  1501,  1502,  1503,     0,     0,  3107,  1504,  1505,  1506,
    1507,  1508,  1509,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1510,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1511,     0,
    1238,     0,     0,     0,     0,     0,     0,  1123,     0,     0,
       0,     0,     0,     0,     0,  1239,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1240,     0,     0,  1241,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1512,  1242,     0,
    2401,     0,     0,     0,     0,     0,  1513,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   472,     0,     0,     0,
       0,     0,     0,     0,  1514,  1920,  1515,     0,     0,     0,
       0,   473,     0,     0,  1516,   474,     0,     0,  1243,     0,
    2401,  1517,  1518,     0,     0,  1519,  1520,  1521,  1522,     0,
    1244,  1523,  1524,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  3107,     0,   475,     0,     0,  3364,     0,  3366,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1245,  1525,     0,     0,     0,     0,     0,  1123,     0,
       0,   476,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1526,  1179,     0,     0,     0,   477,
    1527,   183,     0,     0,     0,     0,  2115,  1528,     0,  1529,
    1246,     0,     0,     0,     0,  1530,     0,     0,     0,     0,
       0,     0,  1247,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1248,  1249,     0,     0,     0,     0,
    1531,     0,  1250,     0,     0,  1251,     0,     0,     0,     0,
       0,     0,     0,   288,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1395,  1395,  1395,  1395,  1395,  1395,
       0,     0,     0,     0,     0,     0,     0,     0,  1532,     0,
     478,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1533,     0,     0,     0,     0,     0,  1534,     0,     0,
       0,     0,     0,     0,     0,     0,  1535,  1536,     0,     0,
       0,     0,     0,  1537,     0,     0,  1538,  1539,     0,     0,
       0,  1540,     0,     0,     0,     0,     0,  1541,  1542,     0,
       0,     0,     0,     0,  1543,  1544,  1545,  1546,  1547,  1548,
       0,     0,     0,  1549,     0,     0,   479,  1550,     0,  1551,
       0,     0,     0,     0,     0,     0,  1552,  1553,  1554,  1555,
       0,  1556,  1557,     0,     0,     0,  1558,  1559,     0,  1560,
    1561,  1562,     0,  1563,  1564,  1565,  1566,     0,     0,     0,
       0,     0,  1567,  1568,  1569,     0,  1570,  1571,     0,     0,
       0,  1572,  1573,  1574,  1575,  1576,  1577,  1578,  1579,  1179,
    1580,     0,     0,     0,  1581,  1582,  1583,  1584,  1585,  1586,
    1587,  1588,  1589,  1590,  1591,  1592,  1593,  1594,  1595,  1596,
    1597,  1598,  1599,  1600,  1601,  1602,  1603,  1604,  1605,  1606,
    1607,  1608,  1609,  1610,  1611,  1612,  1613,  1614,  1615,  1616,
    1617,  1618,     0,  1619,  1620,     0,     0,  1621,  1622,  1623,
    1624,  1625,  1626,  1627,  1628,  1629,  1630,     0,  1631,  1632,
    1633,  1634,  1635,  1636,  1637,  1638,  1639,  1640,  1641,  1642,
    1643,  1644,  1645,     0,     0,  1646,  1647,  1648,  1649,  1650,
    1651,  1652,  1653,  1654,     0,  1655,  1656,  1657,  1658,     0,
    1659,  1660,  1661,  1662,  1663,  1664,  1665,  1666,  1667,  1668,
    1669,  1670,  1671,  1672,  1673,  1674,  1675,  1676,  1677,  1678,
    1679,  1680,  1681,  1682,  1683,  1684,  1685,  1686,  1687,  1688,
    1689,  1690,  1691,  1692,  1693,  1694,     0,  1695,  1696,  1697,
    1698,  1699,  1700,     0,     0,  1701,  1702,     0,  1703,  1704,
    1705,  1706,  1707,  1708,  1709,  1710,  1711,  1712,  1713,  1714,
    1715,  1716,  1717,  1718,  1719,  1720,  1721,  1722,  1723,  1724,
    1725,  1726,  1727,  1728,     0,     0,  1729,  1730,  1731,  1732,
    1733,  1734,  1735,  1736,  1737,  1738,  1739,  1740,  1741,  1742,
    1743,  1744,  1745,  1746,  1747,  1748,  1749,  1750,  1751,  1752,
    1753,  1754,  1755,  1756,  1757,  1758,  1759,  1760,  1761,  1762,
    1763,  1764,  1765,  1766,  1767,  1768,  1769,  1770,  1771,  1772,
    1773,  1774,  1775,  1776,  1777,  1778,  1779,  1780,  1781,  1782,
    1783,  1784,  1785,  1786,  1787,  1788,  1789,  1790,     0,     0,
       0,     0,  1791,  1792,  1793,  1794,  1795,  1796,  1797,  1798,
    1799,  1800,  1801,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1802,     0,     0,     0,     0,     0,     0,
       0,  1803,     0,     0,     0,     0,  1804,     0,     0,     0,
    1805,     0,     0,  1806,  1807,  1808,  1809,     0,     0,  1810,
    1811,     0,  1812,  1813,  1814,  1495,  1496,  1497,  1498,  1499,
    1500,     0,  1501,  1502,  1503,     0,     0,     0,  1504,  1505,
    1506,  1507,  1508,  1509,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1510,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1511,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1512,     0,
       0,     0,     0,     0,     0,     0,     0,  1513,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1514,     0,  1515,     0,     0,
       0,     0,     0,     0,     0,  1516,     0,     0,     0,     0,
       0,     0,  1517,  1518,     0,     0,  1519,  1520,  1521,  1522,
       0,     0,  1523,  1524,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1525,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1526,     0,     0,     0,     0,
       0,  1527,     0,     0,     0,     0,     0,     0,  1528,     0,
    1529,     0,     0,     0,     0,     0,  1530,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1531,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1532,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1533,     0,     0,     0,     0,     0,  1534,     0,
       0,     0,     0,     0,     0,     0,     0,  1535,  1536,     0,
       0,     0,     0,     0,  1537,     0,     0,  1538,  1539,     0,
       0,     0,  1540,     0,     0,     0,     0,     0,  1541,  1542,
       0,     0,     0,     0,     0,  1543,  1544,  1545,  1546,  1547,
    1548,     0,     0,     0,  1549,     0,     0,     0,  1550,     0,
    1551,     0,     0,     0,     0,     0,     0,  1552,  1553,  1554,
    1555,     0,  1556,  1557,     0,     0,     0,  1558,  1559,     0,
    1560,  1561,  1562,     0,  1563,  1564,  1565,  1566,     0,     0,
       0,     0,     0,  1567,  1568,  1569,     0,  1570,  1571,     0,
       0,     0,  1572,  1573,  1574,  1575,  1576,  1577,  1578,  1579,
       0,  1580,     0,     0,     0,  1581,  1582,  1583,  1584,  1585,
    1586,  1587,  1588,  1589,  1590,  1591,  1592,  1593,  1594,  1595,
    1596,  1597,  1598,  1599,  1600,  1601,  1602,  1603,  1604,  1605,
    1606,  1607,  1608,  1609,  1610,  1611,  1612,  1613,  1614,  1615,
    1616,  1617,  1618,     0,  1619,  1620,     0,     0,  1621,  1622,
    1623,  1624,  1625,  1626,  1627,  1628,  1629,  1630,     0,  1631,
    1632,  1633,  1634,  1635,  1636,  1637,  1638,  1639,  1640,  1641,
    1642,  1643,  1644,  1645,     0,     0,  1646,  1647,  1648,  1649,
    1650,  1651,  1652,  1653,  1654,     0,  1655,  1656,  1657,  1658,
       0,  1659,  1660,  1661,  1662,  1663,  1664,  1665,  1666,  1667,
    1668,  1669,  1670,  1671,  1672,  1673,  1674,  1675,  1676,  1677,
    1678,  1679,  1680,  1681,  1682,  1683,  1684,  1685,  1686,  1687,
    1688,  1689,  1690,  1691,  1692,  1693,  1694,     0,  1695,  1696,
    1697,  1698,  1699,  1700,     0,     0,  1701,  1702,     0,  1703,
    1704,  1705,  1706,  1707,  1708,  1709,  1710,  1711,  1712,  1713,
    1714,  1715,  1716,  1717,  1718,  1719,  1720,  1721,  1722,  1723,
    1724,  1725,  1726,  1727,  1728,     0,     0,  1729,  1730,  1731,
    1732,  1733,  1734,  1735,  1736,  1737,  1738,  1739,  1740,  1741,
    1742,  1743,  1744,  1745,  1746,  1747,  1748,  1749,  1750,  1751,
    1752,  1753,  1754,  1755,  1756,  1757,  1758,  1759,  1760,  1761,
    1762,  1763,  1764,  1765,  1766,  1767,  1768,  1769,  1770,  1771,
    1772,  1773,  1774,  1775,  1776,  1777,  1778,  1779,  1780,  1781,
    1782,  1783,  1784,  1785,  1786,  1787,  1788,  1789,  1790,     0,
       0,     0,     0,  1791,  1792,  1793,  1794,  1795,  1796,  1797,
    1798,  1799,  1800,  1801,     1,     0,     0,     0,     0,   654,
     655,   656,     0,     0,  1802,     0,     0,   657,     0,     0,
       0,     0,  1803,     0,   658,   659,     0,  1804,     0,     0,
       0,  1805,     0,     0,  1806,  1807,  1808,  1809,     0,     0,
    1810,  1811,     0,  1812,  1813,  1814,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   660,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   661,   662,     0,   663,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   664,     0,     0,     0,     0,     0,     0,
     665,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   666,     0,     0,   667,   668,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   669,
       0,   670,   671,   672,     0,     0,     0,     0,     0,     0,
       0,     0,   673,   674,     0,   675,   676,   677,     0,     0,
       0,     0,     0,   678,     0,     0,   679,     0,   680,   681,
     682,     0,     0,     0,     0,     0,   683,     0,   684,   685,
       0,   686,     0,   687,   688,     0,     0,   689,     0,     0,
     690,   691,   692,     0,   693,   694,     0,     0,     0,   695,
     696,   697,     0,   698,     0,     0,     0,   699,     0,   700,
     701,     0,     0,     0,     0,   702,     0,     0,     0,   703,
       0,     0,   704,     0,   705,     0,   706,     0,   707,     0,
     708,   709,     0,   710,   711,   712,     0,     0,     0,   713,
       0,   714,   715,     0,   716,     0,     0,     0,     0,     0,
       0,     0,   717,   718,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   719,     0,     0,   720,   721,
       0,     0,   722,   723,     0,     0,   724,   725,     0,     0,
       0,     0,     0,     0,     0,   726,   727,   728,     0,   729,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   730,
     731,   732,     0,   733,     0,     0,     0,   734,   735,     0,
       0,     0,   736,     0,     0,     0,     0,     0,     0,     0,
     737,     0,     0,     0,     0,     0,     0,     0,   738,   739,
     740,     0,     0,     0,     0,     0,   741,   742,     0,     0,
       0,     0,   743,     0,     0,   744,     0,     0,     0,   745,
     746,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     747,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   748,     0,
       0,     0,     0,     0,     0,     0,   749,     0,     0,     0,
       0,     0,   750,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   751,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    79,     0,     0,     0,     0,
       0,     0,   752,     0,   753,   754,     0,     0,     0,     0,
       0,     0,     0,   755,   577,   444,   445,   446,     0,   447,
     448,   449,   450,   451,   452,   453,   454,   455,   456,   457,
     458,   459,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   460,     0,
       0,     0,   756,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   757,     0,     0,     0,     0,     0,     0,
     758,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   759,   760,     0,     0,     0,   761,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   762,     0,     0,     0,     0,     0,   763,   764,   765,
     766,     0,     0,     0,   767,     0,     0,     0,   768,     0,
       0,     0,     0,     0,     0,   769,   770,   461,   462,   463,
     464,   465,   466,     0,     0,     0,   771,     0,   772,     0,
       0,     0,     0,     0,     0,   467,   468,   469,     0,   773,
       0,   774,     0,     0,   775,     0,  2663,   444,   445,   446,
     776,   447,   448,   449,   450,   451,   452,   453,   454,   455,
     456,   457,   458,   459,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   777,     0,     0,   778,
     460,     0,     0,     0,   779,  1234,     0,   780,   781,   267,
    1235,  1236,    31,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   782,     0,     0,     0,   444,   445,   446,   783,
     447,   448,   449,   450,   451,   452,   453,   454,   455,   456,
     457,   458,   459,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   784,   785,   786,   787,   788,   789,   790,   460,
       0,   791,     0,   792,     0,   793,     0,   444,   445,   446,
       0,   447,   448,   449,   450,   451,   452,   453,   454,   455,
     456,   457,   458,   459,     0,  1237,     0,     0,     0,   461,
     462,   463,   464,   465,   466,     0,   470,     0,     0,   471,
     460,     0,     0,     0,     0,     0,     0,   467,   468,   469,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     444,   445,   446,     0,   447,   448,   449,   450,   451,   452,
     453,   454,   455,   456,   457,   458,   459,     0,   461,   462,
     463,   464,   465,   466,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   460,     0,     0,   467,   468,   469,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   461,
     462,   463,   464,   465,   466,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   467,   468,   469,
       0,     0,     0,  1001,     0,     0,     0,     0,   472,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   473,     0,     0,     0,   474,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   470,     0,
       0,   471,   461,   462,   463,   464,   465,   466,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     467,   468,   469,     0,     0,   475,     0,     0,     0,     0,
       0,   444,   445,   446,     0,   447,   448,   449,   450,   451,
     452,   453,   454,   455,   456,   457,   458,   459,     0,     0,
       0,     0,     0,   476,     0,     0,     0,   470,     0,     0,
     471,     0,     0,     0,   460,     0,     0,     0,     0,     0,
       0,   477,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   470,     0,
       0,   471,     0,   444,   445,   446,     0,   447,   448,   449,
     450,   451,   452,   453,   454,   455,   456,   457,   458,   459,
     472,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   473,   460,     0,     0,   474,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   478,   461,   462,   463,   464,   465,   466,     0,
       0,   470,     0,     0,   471,     0,     0,     0,  1238,     0,
       0,   467,   468,   469,     0,     0,     0,   475,     0,   472,
       0,     0,     0,  1239,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   473,     0,     0,     0,   474,   566,
    1240,     0,     0,  1241,     0,   476,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1242,     0,   479,     0,
     472,     0,     0,   477,     0,   461,   462,   463,   464,   465,
     466,     0,     0,     0,     0,   473,   475,     0,     0,   474,
     576,     0,     0,   467,   468,   469,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1243,     0,     0,     0,
       0,     0,     0,     0,   476,     0,     0,     0,  1244,     0,
       0,     0,     0,     0,     0,     0,     0,   475,     0,     0,
       0,     0,   477,   472,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   473,     0,
       0,     0,   474,   586,   478,   476,     0,     0,     0,  1245,
       0,     0,   470,     0,     0,   471,     0,     0,     0,     0,
     444,   445,   446,   477,   447,   448,   449,   450,   451,   452,
     453,   454,   455,   456,   457,   458,   459,     0,     0,     0,
     475,     0,     0,     0,     0,     0,     0,     0,  1246,     0,
       0,     0,     0,   460,     0,     0,     0,     0,     0,     0,
    1247,     0,     0,   478,     0,     0,     0,     0,   476,     0,
     479,     0,  1248,  1249,     0,     0,     0,     0,     0,     0,
    1250,     0,     0,  1251,   470,     0,   477,   471,     0,     0,
       0,   288,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   478,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   479,
       0,     0,     0,     0,   472,     0,     0,     0,     0,     0,
       0,     0,   461,   462,   463,   464,   465,   466,     0,   473,
       0,     0,     0,   474,   939,     0,     0,     0,     0,     0,
     467,   468,   469,     0,     0,     0,     0,   478,     0,     0,
     479,   444,   445,   446,     0,   447,   448,   449,   450,   451,
     452,   453,   454,   455,   456,   457,   458,   459,     0,     0,
       0,   475,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   460,     0,   472,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   476,
       0,   473,     0,     0,     0,   474,   945,     0,     0,     0,
       0,     0,     0,   479,   444,   445,   446,   477,   447,   448,
     449,   450,   451,   452,   453,   454,   455,   456,   457,   458,
     459,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   475,     0,     0,     0,   460,     0,   444,
     445,   446,     0,   447,   448,   449,   450,   451,   452,   453,
     454,   455,   456,   457,   458,   459,     0,     0,     0,     0,
       0,   476,     0,   461,   462,   463,   464,   465,   466,     0,
       0,   470,   460,     0,   471,     0,     0,     0,     0,   477,
       0,   467,   468,   469,     0,     0,     0,     0,   478,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   461,   462,   463,   464,
     465,   466,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   467,   468,   469,     0,     0,     0,
       0,     0,     0,     0,   479,     0,     0,     0,     0,     0,
     478,   461,   462,   463,   464,   465,   466,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   467,
     468,   469,     0,     0,     0,     0,     0,     0,     0,     0,
     444,   445,   446,   472,   447,   448,   449,   450,   451,   452,
     453,   454,   455,   456,   457,   458,   459,     0,   473,     0,
       0,     0,   474,   946,     0,     0,     0,     0,     0,     0,
       0,     0,   470,   460,     0,   471,   479,   444,   445,   446,
       0,   447,   448,   449,   450,   451,   452,   453,   454,   455,
     456,   457,   458,   459,     0,     0,     0,     0,     0,     0,
     475,     0,     0,     0,     0,     0,     0,   444,   445,   446,
     460,   447,   448,   449,   450,   451,   452,   453,   454,   455,
     456,   457,   458,   459,     0,     0,     0,     0,   476,     0,
       0,     0,     0,     0,     0,   470,     0,     0,   471,     0,
     460,     0,     0,     0,     0,     0,   477,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   461,   462,   463,   464,   465,   466,     0,     0,
     470,     0,     0,   471,     0,     0,     0,     0,     0,     0,
     467,   468,   469,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   472,     0,     0,     0,     0,   461,
     462,   463,   464,   465,   466,     0,     0,     0,     0,   473,
       0,     0,     0,   474,   947,     0,     0,   467,   468,   469,
       0,     0,     0,     0,     0,     0,     0,   478,     0,   461,
     462,   463,   464,   465,   466,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   467,   468,   469,
       0,   475,     0,     0,     0,     0,     0,   472,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   473,     0,     0,     0,   474,   948,     0,   476,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   472,   479,  1232,  1233,  1234,   477,     0,     0,
     267,  1235,  1236,    31,     0,     0,     0,   473,     0,     0,
       0,   474,     0,     0,   475,     0,     0,     0,     0,     0,
       0,   470,     0,     0,   471,   445,   446,     0,   447,   448,
     449,   450,   451,   452,   453,   454,   455,   456,   457,   458,
     459,     0,   476,     0,     0,     0,     0,     0,     0,   475,
       0,     0,     0,     0,     0,     0,     0,   460,   470,     0,
     477,   471,   950,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1237,   476,   478,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   470,     0,
       0,   471,     0,     0,   446,   477,   447,   448,   449,   450,
     451,   452,   453,   454,   455,   456,   457,   458,   459,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   460,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   478,     0,   472,   479,     0,   461,   462,   463,   464,
     465,   466,     0,     0,     0,     0,     0,     0,   473,     0,
       0,     0,   474,     0,   467,   468,   469,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   478,     0,     0,     0,
     472,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   473,     0,     0,     0,   474,
     475,     0,     0,     0,  1001,     0,     0,   479,     0,     0,
     472,     0,     0,   951,   461,   462,   463,   464,   465,   466,
       0,     0,     0,     0,     0,   473,     0,     0,   476,   474,
       0,     0,   467,   468,   469,     0,     0,   475,     0,     0,
       0,     0,   479,     0,     0,     0,   477,     0,     0,     0,
     954,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   476,     0,   475,   447,   448,
     449,   450,   451,   452,   453,   454,   455,   456,   457,   458,
     459,     0,     0,   477,     0,     0,     0,     0,     0,   267,
    1235,  1236,    31,     0,     0,   476,     0,   460,     0,     0,
       0,     0,     0,     0,     0,   470,     0,     0,   471,     0,
       0,     0,     0,   477,     0,     0,     0,   451,   452,   453,
     454,   455,   456,   457,   458,   459,     0,   478,  1232,  1233,
    1234,     0,     0,     0,   267,  1235,  1236,    31,     0,     0,
       0,     0,   460,     0,     0,     0,     0,     0,   452,   453,
     454,   455,   456,   457,   458,   459,     0,     0,     0,     0,
       0,     0,     0,     0,   478,  3015,     0,     0,     0,     0,
       0,     0,   460,   470,  3013,  3014,   471,     0,     0,     0,
     267,  1235,  1236,    31,     0,     0,   461,   462,   463,   464,
     465,   466,     0,   479,   478,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   467,   468,   469,     0,     0,  1238,
    1237,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1239,     0,     0,   472,     0,     0,
     479,   461,   462,   463,   464,   465,   466,     0,     0,     0,
       0,  1240,   473,     0,  1241,     0,   474,     0,     0,   467,
     468,   469,     0,     0,     0,     0,  3015,  1242,     0,     0,
     479,   461,   462,   463,   464,   465,   466,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   467,
     468,   469,  3013,  3014,   475,     0,     0,     0,   267,  1235,
    1236,    31,     0,  1001,     0,   472,  2396,  1243,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1244,
     473,     0,   476,     0,   474,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1232,  1233,  1234,     0,
     477,     0,   267,  1235,  1236,    31,     0,     0,  1001,     0,
       0,     0,     0,     0,     0,   470,     0,     0,   471,     0,
    1245,     0,   475,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  3015,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     476,     0,     0,     0,  1001,     0,     0,     0,     0,  1246,
     470,     0,     0,   471,     0,     0,  3013,  3014,   477,     0,
       0,  1247,   267,  1235,  1236,    31,     0,     0,  1237,     0,
       0,   478,     0,  1248,  1249,     0,     0,     0,     0,     0,
     470,  1250,     0,   471,  1251,     0,     0,     0,     0,     0,
       0,     0,   288,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   472,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   479,  3015,   478,
       0,     0,   473,     0,     0,     0,   474,     0,     0,     0,
       0,     0,  1001,     0,     0,     0,     0,   195,  1238,   196,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   472,  1239,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   475,     0,     0,   473,     0,     0,
    3016,   474,     0,  3017,     0,     0,  1001,     0,     0,     0,
       0,     0,   472,  1238,     0,   479,  3018,     0,     0,     0,
       0,     0,   476,     0,     0,     0,     0,   473,  1239,     0,
       0,   474,     0,     0,     0,     0,     0,     0,     0,   475,
     477,     0,     0,     0,     0,  1240,     0,     0,  1241,     0,
     197,   198,     0,     0,     0,     0,  3020,     0,     0,  1238,
     199,  1242,     0,     0,     0,     0,     0,   476,  3021,   475,
       0,     0,     0,     0,  1239,     0,  1001,     0,     0,     0,
       0,     0,     0,     0,     0,   477,     0,     0,     0,     0,
       0,  3016,     0,     0,  3017,     0,     0,   476,     0,     0,
    3407,  1243,     0,     0,     0,     0,     0,  3018,     0,  3022,
       0,     0,     0,  1244,     0,   477,     0,     0,     0,     0,
       0,   478,     0,  2427,  2428,  2429,  2430,  2431,  2432,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1084,     0,     0,     0,     0,  3019,  3020,  3023,  1085,
       0,     0,     0,     0,  1245,     0,     0,     0,  1086,  3021,
    3024,  1087,     0,     0,     0,     0,   478,  1238,     0,     0,
       0,     0,  3025,  3026,     0,     0,     0,     0,     0,     0,
    3027,     0,  1239,  3028,     0,     0,     0,   479,     0,     0,
       0,   288,     0,  1246,     0,     0,   478,     0,     0,  3016,
    3022,     0,  3017,     0,  1088,  1247,     0,     0,     0,     0,
       0,  1238,  1089,  2433,     0,  3018,     0,  1248,  1249,     0,
       0,     0,     0,     0,     0,  1250,  1239,     0,  1251,     0,
       0,     0,   479,   200,     0,     0,   288,     0,     0,  3023,
       0,     0,  1920,  1240,     0,     0,  1241,     0,     0,     0,
       0,  3024,     0,     0,     0,  3020,     0,     0,     0,  1242,
       0,     0,   479,  3025,  3026,     0,     0,  3021,  1090,     0,
       0,  3027,   201,     0,  3028,     0,     0,     0,     0,     0,
       0,  1238,   288,     0,     0,     0,     0,     0,     0,     0,
       0,   202,   203,  1091,     0,     0,  1239,     0,     0,  1243,
    1092,     0,  1093,     0,     0,     0,     0,   204,  3022,     0,
       0,  1244,  1094,  3016,     0,     0,  3017,     0,     0,     0,
    3378,     0,     0,     0,     0,     0,     0,     0,     0,  3018,
     205,     0,     0,     0,     0,     0,     0,     0,  1095,     0,
       0,     0,   206,     0,     0,     0,  1096,  3023,     0,     0,
       0,     0,  1245,   207,     0,     0,     0,     0,     0,  3024,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  3020,
     208,  3025,  3026,     0,     0,     0,  3379,     0,     0,  3027,
     209,  3021,  3028,     0,  1097,     0,     0,     0,     0,     0,
     288,  1246,     0,     0,     0,     0,   210,     0,     0,     0,
       0,  3380,     0,  1247,     0,     0,     0,     0,     0,  1098,
    3381,     0,     0,     0,     0,  1248,  1249,     0,     0,     0,
       0,     0,  3022,  1250,     0,     0,  1251,     0,     0,     0,
       0,     0,     0,     0,   288,     0,   211,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  3382,  1099,     0,  2434,
       0,     0,     0,     0,  3383,     0,     0,     0,  1100,   212,
       0,  3023,  2435,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  3024,   213,     0,     0,     0,     0,     0,
       0,   214,     0,     0,   215,  3025,  3026,     0,     0,     0,
       0,     0,     0,  3027,     0,     0,  3028,     0,     0,     0,
       0,     0,     0,     0,   288,   216,     0,     0,     0,   217,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  2436,     0,   218,     0,
       0,     0,     0,  2437,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   219,     0,  3384,     0,
       0,     0,     0,     0,     0,     0,  1101,  1102,  1103,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1104,
       0,     0,  2438,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   220,     0,
       0,     0,     0,     0,     0,     0,  2439,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  2440,  2441,     0,     0,
       0,     0,  2442,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  2443,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  2444,     0,     0,  2445,  2446,     0,
       0,     0,  2447,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1105,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  2448,
       0,     0,     0,     0,     0,     0,     0,     0,  3385,     0,
    2449
};

static const short yycheck[] =
{
       2,     3,     4,   186,   167,     7,   103,   384,  1083,   145,
     169,   631,   252,   253,  1017,    43,  1002,   765,  1112,   964,
    1094,  1232,  1233,   763,  1310,  1303,   254,   255,  1117,    53,
    2383,   259,  1014,  1858,  1090,  1091,    38,  1093,   123,  1095,
    1096,  1339,  2041,   568,   526,   552,  2207,  2254,  1080,    51,
    2526,    53,  1034,     5,  2261,    20,  1824,  1825,   723,   616,
      62,    89,    27,  1984,   665,    27,    27,    69,    26,    27,
     167,    73,  1857,  2426,    76,    77,     5,    27,  1987,  1973,
      82,    83,   218,  2741,  2742,  2743,   136,   660,    39,   186,
     663,   664,    19,   688,    24,  1920,    26,   256,     5,    26,
     102,   260,  2323,   262,   677,   264,   265,   266,    27,  2256,
    2257,  2145,  1922,  2260,   273,    66,     5,   119,   277,   278,
     122,  2744,    27,   696,     5,   127,   699,     5,   685,  1204,
     748,   753,   705,    24,    25,    26,   709,     5,   695,  1171,
     713,    24,     5,    26,   717,   230,   231,   748,   721,   722,
       5,   724,   315,  1185,   727,    19,   729,   730,   731,   110,
      24,    25,    26,   114,   737,     5,    20,   740,  2315,     5,
      98,    25,  1175,    27,   747,   104,    25,   106,    27,   108,
     753,    24,    25,    26,    27,    27,   188,   760,   783,    24,
      25,    26,    27,   750,    20,   752,    98,    27,   771,    25,
      27,    27,   775,     5,   761,    30,   779,   427,    24,    25,
      26,    27,   785,     5,  2546,   788,  2548,     6,   315,   937,
       6,    25,   319,    27,    27,   227,    24,    25,    26,    27,
      27,   233,    27,    24,    25,    26,    27,     5,    25,    26,
      27,   123,   124,   245,  1925,  1926,  1927,  1928,  2772,   251,
     252,   253,   254,   255,    25,     6,    27,   259,    27,  2468,
     419,   175,    25,   422,    27,    25,  1252,    27,     5,   220,
     228,  2540,    27,  2542,   429,   660,    25,   127,    27,    27,
     439,   440,   441,   442,   274,   444,   445,   446,   447,   448,
     449,   450,   451,   452,   453,   454,   455,   456,   457,   458,
     459,   460,   206,  2113,  1101,  1102,   308,   309,    25,     5,
      27,   696,   471,   472,   699,     5,   318,   476,   558,   478,
     503,  2482,    23,     5,   709,  2472,  2325,     5,   713,     5,
       5,   312,   717,   273,   493,   494,   495,   496,   382,   724,
    2547,   500,   101,     5,   729,   201,   731,   142,  2495,  1443,
    1332,   212,   737,   117,   118,   740,     5,   583,  2422,     5,
      27,  2885,   747,  2887,     5,    20,  2823,  1001,   753,   377,
      30,     5,    27,     5,     5,   760,    84,    85,    86,    87,
      88,   286,     5,     5,   335,  1388,   771,   338,     9,   371,
     775,  1139,   343,   228,   779,   274,   559,   397,   193,   245,
     785,    28,    29,   788,  2157,  3035,   503,   468,  2740,  2741,
    2742,  2743,   228,    27,     9,    10,  2563,    12,    13,    14,
      15,    16,    17,     0,   228,   228,     5,  2574,   654,     5,
     228,    91,   496,   228,    55,   230,    96,   228,   468,     5,
     391,   423,     5,    25,   312,    27,   468,   630,   309,  2515,
       5,     9,    10,  2910,    12,    13,    14,    15,    16,    17,
     188,   188,   559,   413,     5,   228,   496,    31,   228,   613,
    2802,   626,  2804,     5,   496,   695,   312,     5,    27,   228,
     228,     5,   387,   143,   144,     5,     5,     5,    28,     5,
     492,   151,    18,    19,    20,    21,    22,  1483,     5,   527,
     528,   741,   176,   177,  2570,     5,   100,  2654,  2190,   653,
    1083,  2193,     5,   513,   283,  2724,  2725,   519,     5,     5,
     522,    92,    93,  1241,     5,     5,   382,   296,   530,   648,
     758,   759,   327,   630,    18,    19,    20,    21,    22,  3063,
     181,  3065,   433,     5,     5,   547,   391,   549,  2601,   120,
     121,   122,     5,   312,  2235,   557,   558,   448,   560,   787,
    2328,  2722,   790,   377,     5,   516,     5,     5,     5,   394,
       5,   272,     5,    25,    29,    27,   478,  3207,  3208,   575,
     538,  1203,   632,   464,   546,     5,   464,  2734,   632,     5,
     387,   437,   656,     5,   584,  2946,   475,  2950,   433,     5,
     395,   662,   542,   508,  3227,  2812,   422,   615,   403,  1357,
       5,   653,   407,   448,   228,  2968,    27,  2681,   443,   422,
     656,  1369,   622,   382,   605,    10,    27,   429,   624,  1202,
    1203,  1204,   387,   591,  2459,   433,  1433,   551,   468,   321,
     429,   468,  1124,   429,  1126,   321,   228,   649,   598,   444,
     448,   579,   654,   655,   656,   657,   658,   659,   500,   661,
     662,   429,    30,   665,   666,   280,   668,   201,   427,   671,
     574,   673,   464,   508,   422,   412,  1296,   579,   429,   504,
     682,  3013,  3014,  2604,  2718,  3017,   593,  2740,  2741,  2742,
    2743,  1325,   274,  1358,  2588,   290,  2481,  2606,  1083,   626,
     702,  1987,   654,  1228,   593,  2926,   708,   626,   524,  2930,
    1328,   508,   714,   715,   716,  1222,   511,  2470,   720,  3195,
     583,   723,     5,   725,   726,   654,   656,  1328,   583,  2876,
    3206,  2878,   290,   662,   736,  1353,     5,   605,   703,   741,
     742,   703,   703,   111,   513,   405,   748,   705,   508,   751,
     590,   468,  1353,   703,   756,   550,   758,   759,  2056,   655,
     529,   763,   764,   765,  3422,   656,   662,   769,   464,   605,
     772,   431,   404,   656,   464,   777,   228,   429,   427,   574,
     662,   552,   784,   429,   786,   787,   464,   789,   790,   464,
     792,   793,   656,   952,   648,   429,   955,  3066,   429,   648,
     474,   615,   464,    23,   963,   964,   429,   429,    25,   613,
      27,   463,   576,   656,   409,   410,    23,  1202,  1203,  1204,
    2502,   656,   648,   618,   587,   675,   676,   677,   678,   679,
     379,   425,   627,   496,   429,   563,   563,  3190,   387,   388,
     656,     5,   502,  3194,  1221,    22,   605,  3323,   382,  3373,
     429,   409,   410,   429,  2890,  3002,   450,  2893,   656,   491,
    1455,   648,    39,   429,   413,   656,   429,   416,  1850,  1851,
    2638,   466,   283,   622,   429,   507,   496,  1859,   391,   377,
    3212,    14,   283,  3234,   433,   296,  3218,  3219,   429,  3221,
    3222,  3223,  3224,   475,   896,   296,   844,   429,  3230,   663,
     398,   429,   287,   333,  3051,   429,   274,   508,   466,   429,
     429,   429,   620,   429,   397,   516,   711,   712,   550,   205,
     189,   492,   429,  1480,    27,   468,   685,   686,   687,   429,
    2740,  2741,  2742,  2743,   594,   937,   429,   696,   464,   533,
    3087,   196,   429,   429,    25,    25,    27,    27,   429,   429,
    1932,   128,   129,   130,   131,   132,   133,   589,   496,  3073,
    3013,  3014,  3076,   626,  3017,  3079,   362,   429,   429,   146,
     147,   148,   559,   975,   362,   977,   429,   468,  1960,     5,
     464,   433,   196,    25,   150,    27,   618,  2061,   429,   538,
     429,   429,   429,   656,   429,   627,   429,  3329,   593,  1001,
    3332,  3333,  3334,  3335,   495,   357,  3322,   578,     5,   429,
    3326,   228,  1014,   429,   674,  1017,  2302,   429,   468,   970,
    2306,  3074,   682,   429,  3077,  3232,   394,   496,   436,  1031,
     513,   625,  1034,   518,   429,   593,   656,   467,  3199,   424,
     522,   426,   591,   637,   638,   476,   468,   581,   530,   598,
     621,   645,   272,    26,    27,  3202,   487,   468,    18,    19,
      20,    21,    22,   369,   659,   272,    25,   468,    27,  2101,
    1072,  2801,    25,  2803,    27,   443,  2806,   508,   575,   334,
     614,  3219,  3414,    25,   515,    27,   682,  1089,  1090,  1091,
    3422,  1093,  3230,  1095,  1096,  2170,    26,    27,    19,  1101,
    1102,   659,   513,    24,  2209,    26,   702,   475,    26,    27,
     287,   661,   513,   290,   709,   710,   320,   615,   529,   715,
     334,    25,   518,    27,   404,   228,   575,   624,   529,   333,
     518,   202,  1372,   204,   684,  1137,   504,  1139,    25,   622,
      27,  2086,  1370,  3257,   495,   496,  1148,   228,   228,  1151,
    1098,   709,   710,   463,  1156,    25,   411,  1105,   229,  3212,
    2265,  2266,    25,   189,    27,  3218,  3219,   649,  3221,  3222,
    3223,  3224,   468,  1175,  1176,   624,   661,  3230,   468,  3004,
     400,  2163,  1184,   286,    20,   202,   228,   204,    26,    27,
     476,    27,   468,   400,  3247,   680,   681,   411,  1200,  1201,
     468,   487,    20,  3013,  3014,   613,  1924,  3017,   616,    27,
     320,   491,  1930,  1931,  1299,   700,   468,  1302,  1936,  1937,
    1938,  1939,   508,   333,  1226,  1465,    25,   507,    27,   515,
    1232,  1233,   409,  1461,    20,    25,    26,   308,  3017,  1241,
     311,    27,   188,  2225,   468,   551,   192,   424,    26,  1251,
    1998,   428,    20,    20,   468,   228,   562,  1259,   513,    27,
      27,   496,   333,   467,  3074,   661,   468,  3077,   468,   228,
     550,   495,   496,   661,   529,   228,  3329,   676,   677,  3332,
    3333,  3334,  3335,   468,   680,   681,   228,   138,   139,   466,
       0,   308,   680,   681,   311,   495,   496,  2575,   228,   513,
    1324,   298,  1304,  3356,   700,    15,  1308,  1309,  1310,   589,
     228,    25,   700,    27,  2408,   529,   333,   494,  1320,  1321,
    2606,   276,  1324,  1325,   228,  2603,  1328,   468,  1330,  1331,
    1332,    24,    20,    26,   558,   512,  2084,   468,   618,    27,
     337,   228,  3311,  3312,   290,   215,  1947,   627,   495,   496,
    3080,  1353,  1354,   468,  1356,  1357,  1358,   467,   558,   356,
     357,  3414,   468,  1365,  1366,   228,   661,  1369,  1370,  3422,
    1372,  1373,   661,   699,   468,   276,  3375,   202,   333,   204,
      38,  1383,    40,    41,    42,   468,  1388,   713,   683,   684,
     228,   717,  2110,  3392,   683,   684,   467,    26,   395,  2474,
    3210,  2149,  3212,   729,   229,   678,   679,   373,  3218,  3219,
     407,  3221,  3222,  3223,  3224,  2155,   593,   468,   384,  2494,
    3230,   418,  2527,   468,  3393,  2530,  3395,   468,    20,   228,
     385,  1433,   333,  3212,   389,    27,   468,   731,   435,  3218,
    3439,   468,  3221,  3222,  3223,  3224,   740,   468,   445,   675,
     467,    26,   678,   679,   276,  2012,  1458,  3456,  1460,  1461,
     706,   707,   708,  1465,   461,  1467,   468,  1469,  1470,   429,
     436,   786,   342,  2046,   789,  2457,   662,   792,   348,   349,
     350,   468,   659,   308,   385,   451,   311,   468,   389,  2207,
    1492,   785,   468,  2596,   788,  2598,  2599,  2215,   368,   468,
    2218,  2219,  2220,  2221,   501,   771,   685,   686,   333,   775,
     468,   333,   467,   779,   468,  2497,  1099,  1100,   662,  3329,
    1103,  1104,  3332,  3333,  3334,  3335,    24,   524,    26,    25,
    3211,    27,  3213,  3214,  3215,  3216,    25,    38,    27,    40,
      41,    42,   539,    25,  2292,    27,  3356,   685,   686,   546,
    3329,    26,   549,  3332,  3333,  3334,  3335,    26,  2540,  2307,
    2542,  2309,    25,   385,    27,    26,   467,   389,    20,    21,
    2318,   325,   326,   570,   540,    26,    25,   574,    27,  2152,
     656,    18,    19,    20,    21,    24,  2660,    26,  2620,  2800,
    2801,  2073,  2803,  1821,  1822,  2806,   593,  2170,   468,   563,
      25,  2690,    27,   468,  3414,    26,   476,  3013,  3014,   479,
     404,  1354,  3422,  1356,   611,   468,   404,   487,   468,  2897,
    2714,   468,   468,  2909,   468,  2657,   468,    20,    21,    22,
      18,    19,    20,    21,    22,  3414,   468,    38,   468,    40,
      41,    42,   467,   458,   496,   467,    39,   146,   147,   148,
     308,    26,   522,   311,    26,   313,   404,   649,   650,   651,
     652,  2046,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    26,   333,   128,   129,   130,   131,
     132,   133,    26,    94,    26,   343,   656,   557,   404,   429,
      39,   128,   129,   130,   131,   132,   133,   491,   468,   399,
     656,    26,   429,   491,   362,   468,   576,   577,   468,    19,
     198,   464,  1848,   507,    24,    25,    26,   587,  1854,   507,
       5,  2666,   592,   468,     5,   213,   214,   385,   429,  2674,
    2675,   389,   429,   429,   222,   128,   129,   130,   131,   132,
     133,   687,   688,   491,   429,   429,  2303,   429,   429,   429,
     508,   468,   662,   146,   147,   148,   550,    20,    20,   507,
     468,   631,   550,   404,  2482,   468,   429,  2152,   256,     5,
     468,   496,   660,   656,    26,   491,   429,   265,   296,   128,
     129,   130,   131,   132,   133,  2170,   464,   399,    30,  1948,
    2347,   507,    20,   663,    26,   589,    26,   146,   147,   148,
      26,   589,   550,    26,    26,  1890,   294,   308,    26,   467,
     311,    26,   313,   626,  2532,   429,   404,    26,  1820,  1821,
    1822,   429,   429,   429,   618,  1827,  1828,  2055,   429,  2547,
     618,    26,   333,   627,   550,     5,    20,   783,  2395,   627,
    2558,   589,   343,   468,    26,  1847,    26,   793,  1850,  1851,
     491,   339,    26,  1855,   656,  1857,   429,  1859,     5,   429,
      26,   362,  2610,    97,   429,   429,   507,   340,   429,  3080,
     618,   429,  1957,   589,   429,   660,  2624,     5,   429,   627,
     429,  1883,   468,   662,   385,   429,    26,   626,   389,  2129,
    2130,   662,  1894,   381,   287,  2468,   429,   290,    25,    25,
      25,  2474,   618,   491,   429,    25,   429,   308,   429,   550,
     311,   627,   313,  2072,  2050,   429,  2144,   429,   429,   507,
    1922,  2494,  1924,   429,   429,   340,   429,  2086,  1930,  1931,
    1932,   660,   333,   656,  1936,  1937,  1938,  1939,   287,   429,
     174,   290,   343,   429,   429,  1947,   468,   626,   589,   656,
     496,   653,  2955,     8,   464,   661,   516,   656,  1960,   304,
     497,   362,   550,     5,   174,   654,   467,   654,   632,   497,
     364,  1973,   648,  2691,   458,   695,   695,   618,     8,   633,
       5,     5,  1984,   698,   385,  1987,   627,   421,   389,   468,
     468,   937,   468,   382,   468,   626,  1998,   468,   615,     8,
      14,   589,  1953,   237,  2722,   239,  2008,  2009,  2010,   612,
       5,   458,   695,  2015,  2959,   468,   409,   101,   695,    26,
     254,    26,   468,   127,   496,   468,   656,   237,   262,   239,
     618,   424,   266,   174,   458,   428,   468,   626,   468,   627,
    2042,   468,   468,  3029,   254,   468,   468,    26,   496,     5,
    2052,  2053,   262,  2055,   632,  3149,   266,   291,   656,   626,
     409,    20,    21,  3157,   468,  2067,   467,    25,   468,     5,
     468,  1017,  2074,   466,   664,   424,   468,  3171,   662,   428,
    2082,   291,  2084,  2468,  3066,   662,   388,   677,     5,  2474,
    2808,   593,   661,    18,    26,    19,   237,    26,   239,   191,
     256,   494,    25,  2105,   656,  2107,  2108,   626,  2110,  2494,
    2293,  2113,  2114,   254,   659,   705,   519,   466,   615,   512,
     519,   262,     5,   583,   189,   266,   583,  2129,  2130,    26,
     479,   721,   722,   437,   359,    26,   277,   727,   583,   429,
     730,   468,  2144,   429,   563,   494,   662,  2149,  2150,  2151,
     291,  2724,  2725,  2155,  2902,   429,  3231,   468,   700,   468,
     468,  2163,   656,   512,    18,    19,    20,    21,  2916,   128,
     129,   130,   131,   132,   133,   939,   468,   468,   942,  2181,
     944,   945,   946,   947,   948,   429,   656,  2189,  2190,   496,
     468,  2193,   583,   613,   653,   662,  2293,     5,     5,     5,
     593,   656,   616,     5,   520,  2207,   662,  3301,   468,     5,
       8,   661,    26,  2215,    26,   357,  2218,  2219,  2220,  2221,
    2222,   101,     5,  2225,   363,     5,   429,  2229,  2230,  1175,
     429,  2233,  2827,  2828,  2829,   468,  2831,  2832,  2833,  2834,
    2835,  2836,    14,   398,   593,  2840,   633,   468,   587,   662,
     583,     5,  2254,    26,  2256,  2257,   696,   215,  2260,  2261,
     136,    18,    19,   468,   468,   662,   659,     5,   675,    26,
      27,  1212,   656,   464,   128,   129,   130,   131,   132,   133,
     661,    26,     5,   429,     5,  2287,  1232,  1233,  2290,   406,
    2292,   655,   369,   464,  2296,  1241,   498,   498,     8,   468,
    2302,   468,     5,   468,  2306,  2307,  3309,  2309,   468,  3403,
     659,   468,     5,  2315,   468,   468,  2318,  2319,   656,   656,
    2322,  2323,  3378,  3379,  3380,  3381,  3382,  3383,     8,     5,
     656,   590,   363,    25,   382,   382,   656,   496,    95,  2724,
    2725,   382,  2344,     5,   468,   398,   689,   463,   496,   458,
     107,     5,   687,  2355,    26,     5,     5,    25,    14,    14,
      26,   632,   632,   468,   653,  3083,     5,  3085,     5,   712,
     429,   468,   429,   429,   662,   429,     6,   429,   135,   429,
     468,  2383,     7,   485,   342,   306,   429,     5,   656,   662,
     348,   349,   350,    26,    26,    26,     8,   429,   656,    20,
       5,   312,     5,  3151,    38,   603,     5,  2409,   583,     5,
     368,   704,     5,   429,   757,   608,   656,   429,   508,   468,
       5,   662,   590,   766,   767,   662,   248,   770,    26,   660,
     429,   774,   508,   662,   468,   662,     5,   780,     5,   782,
     468,   660,  1388,    25,    25,    25,   484,   655,    25,  3394,
      25,   429,    26,    26,    26,  2457,    26,   334,    26,     5,
      26,    26,   429,     5,  2704,   505,  2706,   468,   102,   103,
    2472,   228,  3092,   230,   429,   587,    26,   278,  2480,  2481,
    2482,  3199,    25,   464,   429,   478,   382,  2515,    20,   180,
     590,   468,   468,  2495,   468,  2497,   468,   468,   468,  2501,
    2502,     5,   468,     5,  2663,    14,  2689,  2666,   248,  1455,
    3513,   429,     5,   496,   479,  2674,  2675,   429,   476,  2655,
      26,   479,   429,   429,   429,    26,   412,   605,    26,   487,
    2532,   429,   278,   167,   429,   429,   382,   468,  2540,   429,
    2542,   478,  2570,  2545,  3292,  2547,   279,   496,   583,   468,
     429,    14,   186,   656,     7,   277,  2558,   277,    26,   429,
     468,  2563,  2564,  2565,   522,   430,   662,   656,   429,   429,
     327,    25,  2574,   612,   279,   468,   464,  2579,   429,   429,
     429,   429,   429,     5,   429,   656,  2588,   656,     5,   429,
     656,  2669,  2689,  3449,  2617,   963,  2379,  1472,  2094,   557,
      27,    29,  2604,   360,  2606,   527,  2319,  3325,  2610,  2649,
    2325,   343,   202,   110,   114,  2617,   633,   336,   576,   577,
    1952,   205,  2624,  1953,   516,   577,   344,  1231,   372,   587,
     371,   535,   547,   549,   592,  3439,  2014,   955,   395,   769,
     404,  1460,  3360,  1209,  2312,  2187,  2194,  2649,  1820,  2651,
     407,  2653,  2654,  2982,  2054,  1823,  2695,  2121,  3231,  2405,
    3490,  2139,  2316,  1372,  3165,  2667,    15,  2669,  2670,  2671,
      89,    21,  3113,   631,   308,   309,    21,  2105,  2099,   319,
     726,   315,  2684,  3060,  1027,   319,   898,   444,  1828,  2691,
    2692,  2693,  2693,   977,  2108,  1176,  3110,  3265,  1366,  1431,
     751,  3456,  2704,   460,  2706,   663,  2934,  2691,  1356,  2867,
    3275,   468,  1454,   438,  2716,  2717,  2944,  1127,  2865,  2849,
    2722,  2573,  2906,  1990,   481,  2306,  1967,  2468,  3465,  3087,
    2875,  2498,  2734,  3350,  2789,  2574,  2225,  2260,  2740,  2741,
    2742,  2743,  2744,  2745,  2162,  2790,  2545,  3465,  3356,  3077,
    1847,  3130,     7,  2755,   668,  2579,  3506,  2564,  2760,  2565,
    3012,  1205,  2735,  3085,  1931,  2928,  3319,  1930,   525,  1842,
    1201,  3210,  3011,  3229,  1117,  1815,  3218,  1371,  2655,  2290,
      -1,    -1,   525,    -1,  1127,    -1,    -1,  2789,  2790,  1132,
      -1,    -1,    -1,   550,    -1,    -1,    -1,    -1,  2800,  2801,
    2959,  2803,    -1,    -1,  2806,    -1,  2808,    -1,    -1,    -1,
    2812,    -1,    -1,    -1,    -1,    -1,    -1,   574,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  2928,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  3231,    -1,    -1,  2851,
      16,    17,    18,    19,    20,    21,    22,    -1,   492,    -1,
      -1,   618,  2864,    -1,    -1,    -1,    -1,    -1,    -1,   503,
     627,    -1,    -1,    39,  2876,  2877,  2878,    -1,    -1,     9,
      -1,    -1,  1828,    -1,    -1,    -1,    -1,    -1,    18,    19,
      20,    -1,    -1,    -1,    24,    25,    26,    27,    -1,    -1,
    2902,    -1,    -1,    -1,  2906,    -1,    -1,  2909,  3148,    -1,
      -1,    -1,    -1,    -1,  2916,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  2926,   559,    -1,  2929,  2930,    -1,
      -1,    -1,  2934,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1881,  1882,  2944,    -1,  2946,    -1,    -1,  1888,    -1,    -1,
      -1,    -1,    -1,  2955,   711,   712,    -1,    -1,    -1,    -1,
      -1,    -1,   128,   129,   130,   131,   132,   133,    -1,    -1,
     100,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1924,    -1,
     146,   147,   148,    -1,  1930,  1931,    -1,    -1,    -1,    -1,
    1936,  1937,  1938,  1939,  2996,    -1,   630,    -1,    -1,    -1,
    3002,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  3011,
      -1,  3013,  3014,    -1,    -1,  3017,  1359,  1360,  1361,    -1,
     654,   655,   656,   657,    -1,    -1,  3028,    -1,    -1,    -1,
      -1,    -1,    -1,  1376,    -1,    -1,    -1,    -1,    -1,   673,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  3051,
      -1,  3053,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  3066,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  3074,    -1,   708,  3077,    -1,    -1,  3080,    -1,
     714,  3083,   716,  3085,    -1,  3087,   720,    -1,    -1,   723,
      -1,  1434,   726,    -1,    -1,    -1,    -1,    -1,   228,    -1,
      -1,    -1,   736,    -1,    -1,    -1,    -1,    -1,  3110,    -1,
      -1,  1454,    -1,    -1,    -1,    -1,    -1,   751,    -1,    -1,
      -1,   287,   756,    -1,   290,    -1,    -1,    -1,  1471,   763,
     764,   765,  3315,    -1,    -1,   769,  2077,    -1,    -1,  1482,
      -1,    -1,    -1,   777,    -1,    -1,  3148,    -1,    -1,  3151,
      -1,     9,    -1,    -1,    -1,    -1,    -1,    -1,    39,   793,
      18,    19,    20,    -1,  2110,    -1,    24,    25,    26,    27,
      -1,    -1,    -1,    -1,    -1,    -1,  2117,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    -1,    -1,    -1,
      -1,    -1,  3194,    -1,    -1,    -1,    -1,  3199,    -1,    -1,
    3202,    -1,   332,    39,    -1,    -1,    -1,    -1,  3210,    -1,
    3212,    -1,    -1,    -1,    -1,    -1,  3218,  3219,  3315,  3221,
    3222,  3223,  3224,    -1,    -1,  3227,    -1,  3229,  3230,    -1,
    3232,    -1,  3234,    -1,    -1,  3394,    -1,    -1,    -1,    -1,
      -1,    -1,   100,   409,    -1,    -1,    -1,   128,   129,   130,
     131,   132,   133,    -1,    -1,    -1,    -1,    -1,   424,    -1,
      -1,  2207,   428,  3265,    -1,   146,   147,   148,  3270,  2215,
    3272,    -1,  2218,  2219,  2220,  2221,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  2230,    -1,    -1,    -1,    -1,    -1,
    3292,    -1,   128,   129,   130,   131,   132,   133,    -1,    -1,
     466,    -1,    -1,   433,    -1,    -1,    -1,  3309,  2254,    -1,
     146,   147,   148,    -1,    -1,  2261,    -1,  3319,   448,    -1,
      -1,    -1,    -1,  3325,    -1,    -1,    -1,  3329,   494,    -1,
    3332,  3333,  3334,  3335,  3336,   465,    -1,    -1,   468,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   512,    -1,  3350,    -1,
     480,   481,    -1,    -1,  3356,    -1,    -1,    -1,  3360,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     228,    -1,    -1,    -1,    -1,    -1,  3378,  3379,  3380,  3381,
    3382,  3383,    -1,  1017,    -1,    -1,    -1,    -1,  3390,    -1,
      -1,   521,    -1,    -1,    -1,    -1,    -1,  1031,    -1,    -1,
      -1,    -1,    -1,   533,    -1,    -1,   287,    -1,    -1,   290,
      -1,    -1,  3414,    -1,    -1,    -1,    -1,    -1,   109,   110,
    3422,   112,   113,   114,    -1,    -1,    -1,   593,    -1,    -1,
      -1,    -1,  2373,  2374,    -1,    -1,    -1,    -1,  1072,    -1,
      -1,    -1,    -1,  2384,   574,    -1,    -1,    -1,    -1,    -1,
      -1,   287,    -1,    -1,   290,  1089,  1090,  1091,    -1,  1093,
      -1,  1095,  1096,  3465,    -1,  3467,    -1,  1101,  1102,  2410,
    2411,  2412,  2413,    -1,   332,    -1,    -1,  2418,  2419,  2420,
    2421,    -1,    -1,   613,  2425,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   659,    -1,   625,    -1,    -1,    -1,    -1,
      -1,    -1,  3504,  3505,  3506,  1139,    -1,   637,   638,    -1,
      -1,  3513,    -1,  3515,    -1,   645,    -1,  1151,   648,    -1,
      -1,    -1,    -1,   214,    -1,    -1,   656,    -1,   409,    -1,
      -1,   222,    -1,    -1,    -1,    -1,  2482,    -1,    -1,    -1,
      -1,  1175,  1176,   424,    -1,    -1,    -1,   428,    -1,    -1,
    1184,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  2503,  2504,    -1,   256,  1200,  1201,    -1,  2510,
    2511,    -1,    -1,   409,   265,   433,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   466,  2532,    -1,   424,    -1,
     448,    -1,   428,    -1,    -1,    -1,    -1,    -1,    -1,  2545,
      -1,  2547,    -1,   294,   295,    -1,    -1,   465,    -1,    -1,
     468,    -1,  2558,   494,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   480,   481,    44,    45,    46,    47,    48,    49,
     466,   512,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   339,    -1,
     508,    -1,    -1,    -1,    -1,  2601,    -1,    -1,   494,    -1,
      -1,    -1,    -1,   521,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  2014,    -1,    -1,    -1,   533,   512,    -1,    -1,     9,
      -1,    -1,    -1,    -1,    -1,    -1,  2029,    -1,    18,    19,
     381,    -1,    -1,    -1,    24,    25,    26,    27,  2639,  2640,
      -1,    -1,    -1,    -1,    -1,    -1,  2049,  2648,    -1,    -1,
      -1,  2054,   593,    -1,   134,    -1,   574,    -1,    -1,    -1,
    1354,    -1,  1356,  1357,  1358,    -1,    -1,    -1,    -1,    -1,
      -1,  1365,  1366,    -1,    -1,  1369,    -1,  2678,  2679,  1373,
      -1,    -1,    -1,    -1,    -1,  2691,   437,    -1,    -1,    -1,
    2093,    -1,    -1,    -1,  1388,   613,    99,   593,    -1,    -1,
      -1,    -1,    -1,    -1,  2705,    95,  2707,   625,    -1,    -1,
     100,    -1,    -1,    -1,    -1,    -1,  2722,   107,   659,   637,
     638,    -1,    -1,    -1,    -1,    -1,    -1,   645,    -1,    -1,
     648,    -1,    -1,    -1,  2740,  2741,  2742,  2743,   656,  1433,
      -1,    -1,    -1,    -1,    -1,   135,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    2761,  2762,    -1,   659,  2765,  2766,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1467,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  2789,  2790,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  2800,  2801,    -1,  2803,  1492,    -1,
    2806,    -1,  2808,    -1,    -1,    -1,  2812,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  2827,  2828,  2829,    -1,  2831,  2832,  2833,  2834,  2835,
    2836,    -1,    -1,    -1,  2840,    -1,    -1,    -1,   228,    -1,
     230,    -1,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    -1,  2855,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    39,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     370,  2294,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   383,    -1,    -1,    -1,  2310,  2311,  2312,
    2313,    -1,    -1,   664,   665,   666,   667,   668,   669,   670,
     671,   672,   673,    -1,    -1,    -1,  2927,    -1,  2331,    -1,
    2931,    -1,    -1,    -1,   337,    -1,    -1,   327,    -1,    -1,
      -1,    -1,   332,    -1,    -1,    -1,  2947,    -1,    -1,  2955,
      -1,    -1,    -1,    -1,   357,    -1,    -1,    -1,   128,   129,
     130,   131,   132,   133,    -1,  2966,    -1,   447,    -1,    -1,
     360,    -1,    -1,    -1,   454,    -1,   146,   147,   148,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  2389,    18,    19,    20,
      -1,    -1,   395,    24,    25,    26,    27,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   407,   395,    -1,  3013,  3014,    -1,
      -1,  3017,     9,   493,    -1,   418,    -1,   407,    -1,    -1,
      -1,    18,    19,    -1,    -1,    -1,    -1,    24,    25,    26,
      27,    -1,   435,    -1,    -1,   425,    -1,   517,    -1,    -1,
     430,    -1,   445,   433,    -1,   448,    -1,   527,   528,    -1,
      -1,    -1,    -1,   533,   444,    -1,    -1,    -1,   461,    -1,
     450,    -1,    -1,   543,    -1,    -1,    -1,    -1,  3074,   100,
     460,  3077,    -1,    -1,  3080,   465,    -1,  3083,   468,  3085,
      -1,   471,  2485,    -1,  2487,   565,    -1,    -1,   568,   569,
     480,   481,    -1,   573,    -1,    -1,    -1,    -1,    95,    -1,
      -1,    -1,    -1,   100,    -1,    -1,   509,    -1,    -1,    -1,
     107,    -1,    -1,    -1,    -1,    -1,    -1,   287,    -1,    -1,
     290,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     520,   521,    -1,  1827,  1828,   525,   539,    -1,   135,    -1,
      -1,    -1,    -1,   533,    -1,    -1,   549,    -1,    -1,    -1,
     630,    -1,    -1,    -1,   544,    -1,    -1,    -1,    -1,    -1,
     550,   641,    -1,    -1,    -1,    -1,    -1,   570,    -1,    -1,
      -1,   574,    -1,    -1,    -1,    -1,    -1,    -1,   156,    -1,
      -1,    -1,  3183,    -1,   574,  3186,    -1,    -1,    -1,  1883,
      -1,    -1,    -1,  3199,    -1,    -1,    -1,   228,    -1,   602,
      -1,    -1,    -1,    -1,    -1,    -1,  3212,    -1,   611,    -1,
      -1,    -1,  3218,  3219,    -1,  3221,  3222,  3223,  3224,    -1,
      -1,    -1,    -1,    -1,  3230,    -1,  3232,  2630,   618,    -1,
    2633,   228,    -1,   230,    -1,   625,    -1,   627,    -1,   409,
      -1,  3247,    -1,    -1,    -1,    -1,    -1,   637,   638,    -1,
      -1,    -1,    -1,    -1,   424,   645,    -1,    -1,   428,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   656,     9,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    18,    19,    -1,    -1,
      -1,   259,    24,    25,    26,    27,    -1,  2690,    -1,   267,
      -1,    -1,    -1,    -1,    -1,   273,   466,   275,    -1,    -1,
      -1,   332,    -1,  3309,  1998,    -1,    -1,    -1,   286,    -1,
      -1,    -1,  3313,    -1,    -1,    -1,    -1,    -1,    -1,  3325,
      -1,   711,   712,  3329,   494,    -1,  3332,  3333,  3334,  3335,
     327,    -1,    -1,    -1,    -1,   332,   314,    -1,    -1,    -1,
      -1,    -1,   512,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    3356,    -1,   330,    95,  3360,    -1,    -1,   335,   100,    -1,
      -1,  3362,  3363,   360,  3365,   107,  3367,  3368,    -1,   347,
      -1,    -1,    -1,  2067,    -1,    -1,   354,    -1,    -1,    -1,
    2074,    -1,    17,    18,    19,    20,    21,    22,    -1,    -1,
    2084,    -1,    -1,   135,    -1,    -1,    -1,    -1,   395,    -1,
      -1,    -1,   433,    -1,    39,    -1,    -1,    -1,  3414,    -1,
     407,  2105,    -1,    -1,    -1,    -1,  3422,   448,    -1,    -1,
    2114,    -1,    -1,   593,    -1,    -1,    -1,  3428,   425,  3430,
      -1,    -1,    -1,   430,   465,    -1,   433,   468,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   444,    -1,   480,
     481,    -1,    -1,   450,    -1,  2149,  2150,  2151,    -1,  3465,
      -1,  2155,  3463,   460,    -1,    -1,    -1,    -1,   465,    -1,
      -1,   468,    -1,    -1,   471,    -1,    -1,    -1,  3479,  3480,
      -1,    -1,  3483,   480,   481,  3486,   228,  2181,   230,   659,
     521,    -1,    -1,   128,   129,   130,   131,   132,   133,    -1,
      -1,    -1,   533,    -1,    -1,    -1,    -1,  3513,    -1,    -1,
      -1,   146,   147,   148,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   521,    -1,    -1,    -1,   525,    -1,
     508,    -1,    -1,    -1,  2937,    -1,   533,   515,    -1,    -1,
      -1,    -1,    -1,   574,    -1,    -1,    -1,   544,    -1,   546,
      -1,    -1,    -1,   550,    -1,    -1,    -1,    -1,    -1,   537,
      -1,    -1,    -1,    -1,   542,    -1,    -1,  2970,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   574,    -1,    -1,
      -1,    -1,   613,    -1,    -1,   327,    -1,    -1,    -1,    -1,
     332,    -1,    -1,    -1,   625,    -1,    -1,    -1,  2292,  2293,
      -1,    -1,    -1,    -1,    -1,    -1,   637,   638,    -1,    -1,
      -1,    -1,    -1,  2307,   645,  2309,    -1,   648,   360,    -1,
      -1,   618,    -1,    -1,  2318,   656,    -1,    -1,   625,    -1,
     627,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     637,   638,    -1,    -1,    -1,    -1,    -1,    -1,   645,    -1,
      -1,    -1,   287,   395,    -1,   290,    -1,    -1,    -1,   656,
       9,  2355,    -1,    -1,    -1,   407,    -1,    -1,    -1,    18,
      19,    -1,    -1,    -1,    -1,    24,    25,    26,    27,    -1,
      -1,    -1,    -1,   425,    -1,    -1,    -1,    -1,   430,  2383,
      -1,   433,    -1,    -1,    23,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   444,    -1,    -1,    -1,    -1,    -1,   450,    38,
      -1,    40,    41,    42,   711,   712,    -1,    -1,   460,    -1,
      -1,    -1,    -1,   465,    -1,    -1,   468,    -1,    -1,   471,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   480,   481,
      -1,    -1,    -1,    -1,    -1,    -1,    95,    -1,    -1,    -1,
    3153,   100,    -1,    -1,    -1,    -1,    -1,    -1,   107,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    98,
      -1,    -1,    -1,    -1,   409,    -1,    -1,    -1,   520,   521,
      -1,    -1,  3185,   525,    -1,    -1,   135,    -1,    -1,   424,
      -1,   533,    -1,   428,    -1,    -1,    -1,    -1,   127,    -1,
      -1,    -1,   544,    -1,    -1,    -1,    -1,  2501,   550,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   466,   574,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   174,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   494,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    2564,    -1,    -1,   202,    -1,   204,   618,   512,    -1,   228,
      -1,   230,    -1,   625,    -1,   627,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   637,   638,    -1,    -1,    -1,
     229,    -1,    -1,   645,    -1,    -1,    -1,    -1,   237,    -1,
     239,    -1,    -1,    -1,   656,    -1,  2610,    -1,    -1,   248,
      -1,    -1,    -1,    -1,    -1,   254,    -1,    -1,    -1,    -1,
    2624,    -1,    -1,   262,    -1,    -1,    -1,   266,    -1,    -1,
      -1,    -1,    -1,   272,    -1,    -1,    -1,   276,   277,   278,
     279,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   593,    -1,
      -1,    -1,   291,    -1,    -1,    -1,    -1,    -1,    -1,   711,
     712,    -1,    -1,  2667,    -1,  2669,    -1,  2671,   327,   308,
      -1,    -1,   311,   332,   313,    -1,  3389,    -1,    -1,    -1,
    2684,   320,    -1,    -1,    -1,  2689,    -1,    -1,  2692,  2693,
      -1,    -1,    -1,    -1,   333,    -1,    -1,    -1,    -1,    -1,
      -1,   360,    -1,    -1,   343,   298,    -1,    -1,    -1,    -1,
      -1,    -1,  2716,  2717,   659,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   362,   363,    18,    19,    20,    -1,    -1,
      -1,    24,    25,    26,    27,    -1,   395,    -1,   377,    -1,
      -1,    -1,    -1,    -1,   337,    -1,   385,    -1,   407,    -1,
     389,  2755,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   398,
     399,   400,    -1,   356,   357,    -1,   425,    -1,    -1,    -1,
      -1,   430,  3485,    -1,   433,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   444,    -1,    -1,    -1,    -1,
      -1,   450,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   460,   395,    -1,    -1,    -1,   465,   100,    -1,   468,
      -1,    -1,   471,    -1,   407,    18,    19,    20,    21,    22,
      -1,   480,   481,    -1,    -1,   418,    -1,    -1,   467,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    39,    -1,    -1,   478,
      -1,    -1,   435,    -1,    -1,    -1,    -1,  2851,    -1,    -1,
      -1,    -1,   445,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    2864,    -1,   521,    -1,    -1,    -1,   525,    -1,   461,    -1,
      -1,    -1,    -1,    -1,   533,    -1,    -1,    -1,    -1,   518,
      -1,    -1,    -1,    -1,    -1,   544,    -1,    -1,    -1,    -1,
      -1,   550,    -1,    -1,    -1,    -1,    -1,    -1,  2902,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   501,    -1,
      -1,    -1,  2916,    -1,    -1,   574,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  2928,   128,   129,   130,   131,   132,
     133,   524,    -1,    -1,    -1,   228,    -1,    -1,    -1,    -1,
     579,    -1,  2946,   146,   147,   148,   539,    -1,    -1,    -1,
      -1,  2955,    -1,   546,    -1,    -1,   549,    -1,    -1,   618,
      -1,    -1,    -1,    -1,    -1,    -1,   625,    -1,   627,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   615,   570,   637,   638,
      -1,   574,    -1,    -1,    -1,    -1,   645,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   656,    -1,    -1,
     593,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   611,    -1,
      -1,    -1,   661,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   675,   676,   677,   678,
     679,   680,   681,    -1,   683,   684,    -1,    -1,    -1,    -1,
      -1,    -1,   711,   712,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   700,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   287,    -1,    -1,   290,    -1,    -1,
      -1,    -1,    -1,    -1,     5,     6,     7,     8,     9,    10,
      -1,    12,    13,    14,    -1,    -1,  3110,    18,    19,    20,
      21,    22,    23,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    33,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    49,    -1,
     433,    -1,    -1,    -1,    -1,    -1,    -1,  3151,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   448,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   465,    -1,    -1,   468,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    98,   481,    -1,
    3194,    -1,    -1,    -1,    -1,    -1,   107,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   409,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   125,   508,   127,    -1,    -1,    -1,
      -1,   424,    -1,    -1,   135,   428,    -1,    -1,   521,    -1,
    3234,   142,   143,    -1,    -1,   146,   147,   148,   149,    -1,
     533,   152,   153,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  3265,    -1,   466,    -1,    -1,  3270,    -1,  3272,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   574,   193,    -1,    -1,    -1,    -1,    -1,  3292,    -1,
      -1,   494,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   215,  3309,    -1,    -1,    -1,   512,
     221,  3315,    -1,    -1,    -1,    -1,   227,   228,    -1,   230,
     613,    -1,    -1,    -1,    -1,   236,    -1,    -1,    -1,    -1,
      -1,    -1,   625,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   637,   638,    -1,    -1,    -1,    -1,
     261,    -1,   645,    -1,    -1,   648,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   656,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  3378,  3379,  3380,  3381,  3382,  3383,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   299,    -1,
     593,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   312,    -1,    -1,    -1,    -1,    -1,   318,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   327,   328,    -1,    -1,
      -1,    -1,    -1,   334,    -1,    -1,   337,   338,    -1,    -1,
      -1,   342,    -1,    -1,    -1,    -1,    -1,   348,   349,    -1,
      -1,    -1,    -1,    -1,   355,   356,   357,   358,   359,   360,
      -1,    -1,    -1,   364,    -1,    -1,   659,   368,    -1,   370,
      -1,    -1,    -1,    -1,    -1,    -1,   377,   378,   379,   380,
      -1,   382,   383,    -1,    -1,    -1,   387,   388,    -1,   390,
     391,   392,    -1,   394,   395,   396,   397,    -1,    -1,    -1,
      -1,    -1,   403,   404,   405,    -1,   407,   408,    -1,    -1,
      -1,   412,   413,   414,   415,   416,   417,   418,   419,  3513,
     421,    -1,    -1,    -1,   425,   426,   427,   428,   429,   430,
     431,   432,   433,   434,   435,   436,   437,   438,   439,   440,
     441,   442,   443,   444,   445,   446,   447,   448,   449,   450,
     451,   452,   453,   454,   455,   456,   457,   458,   459,   460,
     461,   462,    -1,   464,   465,    -1,    -1,   468,   469,   470,
     471,   472,   473,   474,   475,   476,   477,    -1,   479,   480,
     481,   482,   483,   484,   485,   486,   487,   488,   489,   490,
     491,   492,   493,    -1,    -1,   496,   497,   498,   499,   500,
     501,   502,   503,   504,    -1,   506,   507,   508,   509,    -1,
     511,   512,   513,   514,   515,   516,   517,   518,   519,   520,
     521,   522,   523,   524,   525,   526,   527,   528,   529,   530,
     531,   532,   533,   534,   535,   536,   537,   538,   539,   540,
     541,   542,   543,   544,   545,   546,    -1,   548,   549,   550,
     551,   552,   553,    -1,    -1,   556,   557,    -1,   559,   560,
     561,   562,   563,   564,   565,   566,   567,   568,   569,   570,
     571,   572,   573,   574,   575,   576,   577,   578,   579,   580,
     581,   582,   583,   584,    -1,    -1,   587,   588,   589,   590,
     591,   592,   593,   594,   595,   596,   597,   598,   599,   600,
     601,   602,   603,   604,   605,   606,   607,   608,   609,   610,
     611,   612,   613,   614,   615,   616,   617,   618,   619,   620,
     621,   622,   623,   624,   625,   626,   627,   628,   629,   630,
     631,   632,   633,   634,   635,   636,   637,   638,   639,   640,
     641,   642,   643,   644,   645,   646,   647,   648,    -1,    -1,
      -1,    -1,   653,   654,   655,   656,   657,   658,   659,   660,
     661,   662,   663,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   674,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   682,    -1,    -1,    -1,    -1,   687,    -1,    -1,    -1,
     691,    -1,    -1,   694,   695,   696,   697,    -1,    -1,   700,
     701,    -1,   703,   704,   705,     5,     6,     7,     8,     9,
      10,    -1,    12,    13,    14,    -1,    -1,    -1,    18,    19,
      20,    21,    22,    23,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    33,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    49,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    98,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   107,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   125,    -1,   127,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   135,    -1,    -1,    -1,    -1,
      -1,    -1,   142,   143,    -1,    -1,   146,   147,   148,   149,
      -1,    -1,   152,   153,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   193,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   215,    -1,    -1,    -1,    -1,
      -1,   221,    -1,    -1,    -1,    -1,    -1,    -1,   228,    -1,
     230,    -1,    -1,    -1,    -1,    -1,   236,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   261,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   299,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   312,    -1,    -1,    -1,    -1,    -1,   318,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   327,   328,    -1,
      -1,    -1,    -1,    -1,   334,    -1,    -1,   337,   338,    -1,
      -1,    -1,   342,    -1,    -1,    -1,    -1,    -1,   348,   349,
      -1,    -1,    -1,    -1,    -1,   355,   356,   357,   358,   359,
     360,    -1,    -1,    -1,   364,    -1,    -1,    -1,   368,    -1,
     370,    -1,    -1,    -1,    -1,    -1,    -1,   377,   378,   379,
     380,    -1,   382,   383,    -1,    -1,    -1,   387,   388,    -1,
     390,   391,   392,    -1,   394,   395,   396,   397,    -1,    -1,
      -1,    -1,    -1,   403,   404,   405,    -1,   407,   408,    -1,
      -1,    -1,   412,   413,   414,   415,   416,   417,   418,   419,
      -1,   421,    -1,    -1,    -1,   425,   426,   427,   428,   429,
     430,   431,   432,   433,   434,   435,   436,   437,   438,   439,
     440,   441,   442,   443,   444,   445,   446,   447,   448,   449,
     450,   451,   452,   453,   454,   455,   456,   457,   458,   459,
     460,   461,   462,    -1,   464,   465,    -1,    -1,   468,   469,
     470,   471,   472,   473,   474,   475,   476,   477,    -1,   479,
     480,   481,   482,   483,   484,   485,   486,   487,   488,   489,
     490,   491,   492,   493,    -1,    -1,   496,   497,   498,   499,
     500,   501,   502,   503,   504,    -1,   506,   507,   508,   509,
      -1,   511,   512,   513,   514,   515,   516,   517,   518,   519,
     520,   521,   522,   523,   524,   525,   526,   527,   528,   529,
     530,   531,   532,   533,   534,   535,   536,   537,   538,   539,
     540,   541,   542,   543,   544,   545,   546,    -1,   548,   549,
     550,   551,   552,   553,    -1,    -1,   556,   557,    -1,   559,
     560,   561,   562,   563,   564,   565,   566,   567,   568,   569,
     570,   571,   572,   573,   574,   575,   576,   577,   578,   579,
     580,   581,   582,   583,   584,    -1,    -1,   587,   588,   589,
     590,   591,   592,   593,   594,   595,   596,   597,   598,   599,
     600,   601,   602,   603,   604,   605,   606,   607,   608,   609,
     610,   611,   612,   613,   614,   615,   616,   617,   618,   619,
     620,   621,   622,   623,   624,   625,   626,   627,   628,   629,
     630,   631,   632,   633,   634,   635,   636,   637,   638,   639,
     640,   641,   642,   643,   644,   645,   646,   647,   648,    -1,
      -1,    -1,    -1,   653,   654,   655,   656,   657,   658,   659,
     660,   661,   662,   663,    30,    -1,    -1,    -1,    -1,    35,
      36,    37,    -1,    -1,   674,    -1,    -1,    43,    -1,    -1,
      -1,    -1,   682,    -1,    50,    51,    -1,   687,    -1,    -1,
      -1,   691,    -1,    -1,   694,   695,   696,   697,    -1,    -1,
     700,   701,    -1,   703,   704,   705,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    90,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   102,   103,    -1,   105,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   119,    -1,    -1,    -1,    -1,    -1,    -1,
     126,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   137,    -1,    -1,   140,   141,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   155,
      -1,   157,   158,   159,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   168,   169,    -1,   171,   172,   173,    -1,    -1,
      -1,    -1,    -1,   179,    -1,    -1,   182,    -1,   184,   185,
     186,    -1,    -1,    -1,    -1,    -1,   192,    -1,   194,   195,
      -1,   197,    -1,   199,   200,    -1,    -1,   203,    -1,    -1,
     206,   207,   208,    -1,   210,   211,    -1,    -1,    -1,   215,
     216,   217,    -1,   219,    -1,    -1,    -1,   223,    -1,   225,
     226,    -1,    -1,    -1,    -1,   231,    -1,    -1,    -1,   235,
      -1,    -1,   238,    -1,   240,    -1,   242,    -1,   244,    -1,
     246,   247,    -1,   249,   250,   251,    -1,    -1,    -1,   255,
      -1,   257,   258,    -1,   260,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   268,   269,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   281,    -1,    -1,   284,   285,
      -1,    -1,   288,   289,    -1,    -1,   292,   293,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   301,   302,   303,    -1,   305,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   315,
     316,   317,    -1,   319,    -1,    -1,    -1,   323,   324,    -1,
      -1,    -1,   328,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     336,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   344,   345,
     346,    -1,    -1,    -1,    -1,    -1,   352,   353,    -1,    -1,
      -1,    -1,   358,    -1,    -1,   361,    -1,    -1,    -1,   365,
     366,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     376,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   394,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   402,    -1,    -1,    -1,
      -1,    -1,   408,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   419,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   431,    -1,    -1,    -1,    -1,
      -1,    -1,   438,    -1,   440,   441,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   449,     5,     6,     7,     8,    -1,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    39,    -1,
      -1,    -1,   488,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   499,    -1,    -1,    -1,    -1,    -1,    -1,
     506,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   530,   531,    -1,    -1,    -1,   535,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   547,    -1,    -1,    -1,    -1,    -1,   553,   554,   555,
     556,    -1,    -1,    -1,   560,    -1,    -1,    -1,   564,    -1,
      -1,    -1,    -1,    -1,    -1,   571,   572,   128,   129,   130,
     131,   132,   133,    -1,    -1,    -1,   582,    -1,   584,    -1,
      -1,    -1,    -1,    -1,    -1,   146,   147,   148,    -1,   595,
      -1,   597,    -1,    -1,   600,    -1,     5,     6,     7,     8,
     606,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   632,    -1,    -1,   635,
      39,    -1,    -1,    -1,   640,    20,    -1,   643,   644,    24,
      25,    26,    27,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   658,    -1,    -1,    -1,     6,     7,     8,   665,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   688,   689,   690,   691,   692,   693,   694,    39,
      -1,   697,    -1,   699,    -1,   701,    -1,     6,     7,     8,
      -1,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    -1,   100,    -1,    -1,    -1,   128,
     129,   130,   131,   132,   133,    -1,   287,    -1,    -1,   290,
      39,    -1,    -1,    -1,    -1,    -1,    -1,   146,   147,   148,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
       6,     7,     8,    -1,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    -1,   128,   129,
     130,   131,   132,   133,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    39,    -1,    -1,   146,   147,   148,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   128,
     129,   130,   131,   132,   133,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   146,   147,   148,
      -1,    -1,    -1,   228,    -1,    -1,    -1,    -1,   409,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   424,    -1,    -1,    -1,   428,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   287,    -1,
      -1,   290,   128,   129,   130,   131,   132,   133,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     146,   147,   148,    -1,    -1,   466,    -1,    -1,    -1,    -1,
      -1,     6,     7,     8,    -1,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    -1,    -1,
      -1,    -1,    -1,   494,    -1,    -1,    -1,   287,    -1,    -1,
     290,    -1,    -1,    -1,    39,    -1,    -1,    -1,    -1,    -1,
      -1,   512,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   287,    -1,
      -1,   290,    -1,     6,     7,     8,    -1,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
     409,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   424,    39,    -1,    -1,   428,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   593,   128,   129,   130,   131,   132,   133,    -1,
      -1,   287,    -1,    -1,   290,    -1,    -1,    -1,   433,    -1,
      -1,   146,   147,   148,    -1,    -1,    -1,   466,    -1,   409,
      -1,    -1,    -1,   448,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   424,    -1,    -1,    -1,   428,   429,
     465,    -1,    -1,   468,    -1,   494,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   481,    -1,   659,    -1,
     409,    -1,    -1,   512,    -1,   128,   129,   130,   131,   132,
     133,    -1,    -1,    -1,    -1,   424,   466,    -1,    -1,   428,
     429,    -1,    -1,   146,   147,   148,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   521,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   494,    -1,    -1,    -1,   533,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   466,    -1,    -1,
      -1,    -1,   512,   409,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   424,    -1,
      -1,    -1,   428,   429,   593,   494,    -1,    -1,    -1,   574,
      -1,    -1,   287,    -1,    -1,   290,    -1,    -1,    -1,    -1,
       6,     7,     8,   512,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    -1,    -1,    -1,
     466,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   613,    -1,
      -1,    -1,    -1,    39,    -1,    -1,    -1,    -1,    -1,    -1,
     625,    -1,    -1,   593,    -1,    -1,    -1,    -1,   494,    -1,
     659,    -1,   637,   638,    -1,    -1,    -1,    -1,    -1,    -1,
     645,    -1,    -1,   648,   287,    -1,   512,   290,    -1,    -1,
      -1,   656,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   593,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   659,
      -1,    -1,    -1,    -1,   409,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   128,   129,   130,   131,   132,   133,    -1,   424,
      -1,    -1,    -1,   428,   429,    -1,    -1,    -1,    -1,    -1,
     146,   147,   148,    -1,    -1,    -1,    -1,   593,    -1,    -1,
     659,     6,     7,     8,    -1,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    -1,    -1,
      -1,   466,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    39,    -1,   409,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   494,
      -1,   424,    -1,    -1,    -1,   428,   429,    -1,    -1,    -1,
      -1,    -1,    -1,   659,     6,     7,     8,   512,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   466,    -1,    -1,    -1,    39,    -1,     6,
       7,     8,    -1,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    -1,    -1,    -1,    -1,
      -1,   494,    -1,   128,   129,   130,   131,   132,   133,    -1,
      -1,   287,    39,    -1,   290,    -1,    -1,    -1,    -1,   512,
      -1,   146,   147,   148,    -1,    -1,    -1,    -1,   593,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   128,   129,   130,   131,
     132,   133,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   146,   147,   148,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   659,    -1,    -1,    -1,    -1,    -1,
     593,   128,   129,   130,   131,   132,   133,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   146,
     147,   148,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
       6,     7,     8,   409,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    -1,   424,    -1,
      -1,    -1,   428,   429,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   287,    39,    -1,   290,   659,     6,     7,     8,
      -1,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    -1,    -1,    -1,    -1,    -1,    -1,
     466,    -1,    -1,    -1,    -1,    -1,    -1,     6,     7,     8,
      39,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    -1,    -1,    -1,    -1,   494,    -1,
      -1,    -1,    -1,    -1,    -1,   287,    -1,    -1,   290,    -1,
      39,    -1,    -1,    -1,    -1,    -1,   512,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   128,   129,   130,   131,   132,   133,    -1,    -1,
     287,    -1,    -1,   290,    -1,    -1,    -1,    -1,    -1,    -1,
     146,   147,   148,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   409,    -1,    -1,    -1,    -1,   128,
     129,   130,   131,   132,   133,    -1,    -1,    -1,    -1,   424,
      -1,    -1,    -1,   428,   429,    -1,    -1,   146,   147,   148,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   593,    -1,   128,
     129,   130,   131,   132,   133,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   146,   147,   148,
      -1,   466,    -1,    -1,    -1,    -1,    -1,   409,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   424,    -1,    -1,    -1,   428,   429,    -1,   494,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   409,   659,    18,    19,    20,   512,    -1,    -1,
      24,    25,    26,    27,    -1,    -1,    -1,   424,    -1,    -1,
      -1,   428,    -1,    -1,   466,    -1,    -1,    -1,    -1,    -1,
      -1,   287,    -1,    -1,   290,     7,     8,    -1,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    -1,   494,    -1,    -1,    -1,    -1,    -1,    -1,   466,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    39,   287,    -1,
     512,   290,   479,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   100,   494,   593,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   287,    -1,
      -1,   290,    -1,    -1,     8,   512,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    39,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   593,    -1,   409,   659,    -1,   128,   129,   130,   131,
     132,   133,    -1,    -1,    -1,    -1,    -1,    -1,   424,    -1,
      -1,    -1,   428,    -1,   146,   147,   148,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   593,    -1,    -1,    -1,
     409,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   424,    -1,    -1,    -1,   428,
     466,    -1,    -1,    -1,   228,    -1,    -1,   659,    -1,    -1,
     409,    -1,    -1,   479,   128,   129,   130,   131,   132,   133,
      -1,    -1,    -1,    -1,    -1,   424,    -1,    -1,   494,   428,
      -1,    -1,   146,   147,   148,    -1,    -1,   466,    -1,    -1,
      -1,    -1,   659,    -1,    -1,    -1,   512,    -1,    -1,    -1,
     479,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   494,    -1,   466,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    -1,    -1,   512,    -1,    -1,    -1,    -1,    -1,    24,
      25,    26,    27,    -1,    -1,   494,    -1,    39,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   287,    -1,    -1,   290,    -1,
      -1,    -1,    -1,   512,    -1,    -1,    -1,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    -1,   593,    18,    19,
      20,    -1,    -1,    -1,    24,    25,    26,    27,    -1,    -1,
      -1,    -1,    39,    -1,    -1,    -1,    -1,    -1,    15,    16,
      17,    18,    19,    20,    21,    22,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   593,   100,    -1,    -1,    -1,    -1,
      -1,    -1,    39,   287,    18,    19,   290,    -1,    -1,    -1,
      24,    25,    26,    27,    -1,    -1,   128,   129,   130,   131,
     132,   133,    -1,   659,   593,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   146,   147,   148,    -1,    -1,   433,
     100,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   448,    -1,    -1,   409,    -1,    -1,
     659,   128,   129,   130,   131,   132,   133,    -1,    -1,    -1,
      -1,   465,   424,    -1,   468,    -1,   428,    -1,    -1,   146,
     147,   148,    -1,    -1,    -1,    -1,   100,   481,    -1,    -1,
     659,   128,   129,   130,   131,   132,   133,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   146,
     147,   148,    18,    19,   466,    -1,    -1,    -1,    24,    25,
      26,    27,    -1,   228,    -1,   409,   520,   521,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   533,
     424,    -1,   494,    -1,   428,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    18,    19,    20,    -1,
     512,    -1,    24,    25,    26,    27,    -1,    -1,   228,    -1,
      -1,    -1,    -1,    -1,    -1,   287,    -1,    -1,   290,    -1,
     574,    -1,   466,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   100,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     494,    -1,    -1,    -1,   228,    -1,    -1,    -1,    -1,   613,
     287,    -1,    -1,   290,    -1,    -1,    18,    19,   512,    -1,
      -1,   625,    24,    25,    26,    27,    -1,    -1,   100,    -1,
      -1,   593,    -1,   637,   638,    -1,    -1,    -1,    -1,    -1,
     287,   645,    -1,   290,   648,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   656,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   409,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   659,   100,   593,
      -1,    -1,   424,    -1,    -1,    -1,   428,    -1,    -1,    -1,
      -1,    -1,   228,    -1,    -1,    -1,    -1,    32,   433,    34,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   409,   448,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   466,    -1,    -1,   424,    -1,    -1,
     465,   428,    -1,   468,    -1,    -1,   228,    -1,    -1,    -1,
      -1,    -1,   409,   433,    -1,   659,   481,    -1,    -1,    -1,
      -1,    -1,   494,    -1,    -1,    -1,    -1,   424,   448,    -1,
      -1,   428,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   466,
     512,    -1,    -1,    -1,    -1,   465,    -1,    -1,   468,    -1,
     115,   116,    -1,    -1,    -1,    -1,   521,    -1,    -1,   433,
     125,   481,    -1,    -1,    -1,    -1,    -1,   494,   533,   466,
      -1,    -1,    -1,    -1,   448,    -1,   228,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   512,    -1,    -1,    -1,    -1,
      -1,   465,    -1,    -1,   468,    -1,    -1,   494,    -1,    -1,
     520,   521,    -1,    -1,    -1,    -1,    -1,   481,    -1,   574,
      -1,    -1,    -1,   533,    -1,   512,    -1,    -1,    -1,    -1,
      -1,   593,    -1,    44,    45,    46,    47,    48,    49,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   170,    -1,    -1,    -1,    -1,   520,   521,   613,   178,
      -1,    -1,    -1,    -1,   574,    -1,    -1,    -1,   187,   533,
     625,   190,    -1,    -1,    -1,    -1,   593,   433,    -1,    -1,
      -1,    -1,   637,   638,    -1,    -1,    -1,    -1,    -1,    -1,
     645,    -1,   448,   648,    -1,    -1,    -1,   659,    -1,    -1,
      -1,   656,    -1,   613,    -1,    -1,   593,    -1,    -1,   465,
     574,    -1,   468,    -1,   233,   625,    -1,    -1,    -1,    -1,
      -1,   433,   241,   134,    -1,   481,    -1,   637,   638,    -1,
      -1,    -1,    -1,    -1,    -1,   645,   448,    -1,   648,    -1,
      -1,    -1,   659,   298,    -1,    -1,   656,    -1,    -1,   613,
      -1,    -1,   508,   465,    -1,    -1,   468,    -1,    -1,    -1,
      -1,   625,    -1,    -1,    -1,   521,    -1,    -1,    -1,   481,
      -1,    -1,   659,   637,   638,    -1,    -1,   533,   297,    -1,
      -1,   645,   337,    -1,   648,    -1,    -1,    -1,    -1,    -1,
      -1,   433,   656,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   356,   357,   322,    -1,    -1,   448,    -1,    -1,   521,
     329,    -1,   331,    -1,    -1,    -1,    -1,   372,   574,    -1,
      -1,   533,   341,   465,    -1,    -1,   468,    -1,    -1,    -1,
     241,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   481,
     395,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   367,    -1,
      -1,    -1,   407,    -1,    -1,    -1,   375,   613,    -1,    -1,
      -1,    -1,   574,   418,    -1,    -1,    -1,    -1,    -1,   625,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   521,
     435,   637,   638,    -1,    -1,    -1,   297,    -1,    -1,   645,
     445,   533,   648,    -1,   413,    -1,    -1,    -1,    -1,    -1,
     656,   613,    -1,    -1,    -1,    -1,   461,    -1,    -1,    -1,
      -1,   322,    -1,   625,    -1,    -1,    -1,    -1,    -1,   438,
     331,    -1,    -1,    -1,    -1,   637,   638,    -1,    -1,    -1,
      -1,    -1,   574,   645,    -1,    -1,   648,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   656,    -1,   501,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   367,   476,    -1,   370,
      -1,    -1,    -1,    -1,   375,    -1,    -1,    -1,   487,   524,
      -1,   613,   383,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   625,   539,    -1,    -1,    -1,    -1,    -1,
      -1,   546,    -1,    -1,   549,   637,   638,    -1,    -1,    -1,
      -1,    -1,    -1,   645,    -1,    -1,   648,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   656,   570,    -1,    -1,    -1,   574,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   447,    -1,   593,    -1,
      -1,    -1,    -1,   454,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   611,    -1,   469,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   585,   586,   587,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   598,
      -1,    -1,   493,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   653,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   517,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   527,   528,    -1,    -1,
      -1,    -1,   533,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   543,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   565,    -1,    -1,   568,   569,    -1,
      -1,    -1,   573,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   701,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   630,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   639,    -1,
     641
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const unsigned short yystos[] =
{
       0,    30,   111,   274,   394,   443,   475,   504,   771,   799,
     800,   852,  1024,  1077,  1079,  1080,  1081,  1086,  1088,  1101,
    1102,  1103,  1104,  1105,    28,    29,   772,   773,   774,   775,
     776,    27,   988,  1543,   988,    25,   988,  1443,  1106,   801,
    1443,   800,     0,  1078,  1081,  1086,  1104,    31,   774,   776,
     853,   648,    25,   228,   798,   799,   976,   988,   993,  1107,
    1142,  1143,  1144,  1145,  1146,  1150,   391,   803,   804,   805,
     806,   809,   810,    91,    96,   143,   144,   151,   405,   431,
     502,   594,   674,   682,   771,   777,   948,  1023,  1082,  1083,
    1085,  1089,  1090,  1096,  1108,  1129,  1262,  1272,   653,   988,
    1145,   280,   495,   496,  1152,    20,   988,  1149,   656,   804,
       5,   802,   391,   988,     5,   828,   830,   831,   988,  1273,
     988,   988,  1263,  1097,   988,   988,  1085,  1091,   298,   337,
     356,   357,   395,   407,   418,   435,   445,   461,   501,   524,
     539,   546,   549,   570,   574,   593,   611,   854,   855,   856,
     859,    25,  1142,  1148,    18,    19,    26,    95,   107,   135,
     230,   327,   360,   395,   407,   444,   460,   468,   481,   525,
     550,   574,   618,   627,   711,   712,   721,   723,   914,   919,
     930,   932,   988,  1142,  1153,  1154,   496,    14,   851,   806,
     559,  1249,   807,   804,   809,    32,    34,   115,   116,   125,
     298,   337,   356,   357,   372,   395,   407,   418,   435,   445,
     461,   501,   524,   539,   546,   549,   570,   574,   593,   611,
     653,   813,   822,   833,   834,   988,   468,   150,   988,   798,
     949,  1130,   988,   861,   357,   811,   468,   837,   839,   840,
     838,   847,   848,   468,   468,   860,   496,   468,   804,   835,
     463,   468,   468,   468,   468,   468,   468,   468,   468,   468,
     468,   721,   468,   795,     9,    18,    19,    24,    25,    26,
     100,   332,   425,   430,   433,   450,   465,   468,   471,   480,
     521,   533,   544,   574,   625,   637,   638,   645,   656,   888,
     896,   897,   898,   899,   900,   901,   902,   930,   931,   933,
     994,  1142,  1252,  1435,   468,   468,   468,   468,   468,   468,
      18,    19,    20,    21,    22,   722,    26,   468,   558,     5,
     464,  1153,    25,    26,   988,   994,    19,    25,    26,   808,
     994,   706,   707,   708,   812,   824,   811,   468,   825,   837,
     838,   468,   468,   823,   496,   468,   835,   804,   832,   468,
      26,   988,   468,  1098,   798,   798,   468,   988,   468,   495,
     817,    26,   662,   404,   491,   507,   550,   589,   618,   627,
     841,   662,   404,   491,   507,   550,   589,   618,   627,   849,
      26,    26,   862,   863,   864,   865,   988,    26,   820,   821,
      26,   656,   703,   938,   980,   988,  1534,   980,   980,  1534,
    1534,   888,    25,    26,    19,    24,    25,    26,   934,   935,
     936,   937,  1534,   888,   429,   888,   888,   888,   888,   563,
    1269,   468,   468,   888,   404,   491,   507,   550,   589,   618,
     627,  1438,  1439,   468,   888,   888,   468,   468,   903,   468,
     468,   468,   468,    26,     6,     7,     8,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      39,   128,   129,   130,   131,   132,   133,   146,   147,   148,
     287,   290,   409,   424,   428,   466,   494,   512,   593,   659,
     794,   889,   904,   906,   907,   908,   909,   910,   911,   912,
      26,   994,   458,   922,   920,   926,   924,  1142,  1142,   721,
     915,   988,  1154,   496,   464,    26,   815,   804,   817,    26,
     804,    26,    26,   803,   820,    26,   656,    94,   829,  1274,
     429,   468,  1264,  1544,  1545,  1546,  1547,  1548,   950,  1131,
    1092,   656,    26,   429,   842,   843,   468,   844,   849,   850,
     844,   468,   845,     5,   429,     5,   429,     5,   321,     5,
     854,   464,     5,     5,   429,   804,   836,   468,     5,   496,
     656,   429,   429,   429,   429,   429,   429,   429,   429,   626,
     935,    19,    26,   626,   429,   429,   429,     5,   796,   888,
     508,  1459,   888,   468,   662,    20,   429,  1459,    20,  1252,
     888,   888,   888,   888,   888,   888,   888,   888,   888,   888,
     888,   888,   888,   888,   888,   888,   888,   888,   888,   888,
     888,   888,   888,   468,   888,   888,   468,  1142,   888,   888,
     888,   888,   429,     5,   751,   752,   753,   888,   468,  1153,
     496,   660,   656,    26,   429,   296,     5,   429,     5,   429,
     321,   464,     5,   429,   836,   988,  1159,  1160,  1162,  1109,
    1159,   399,  1545,  1249,    35,    36,    37,    43,    50,    51,
      90,   102,   103,   105,   119,   126,   137,   140,   141,   155,
     157,   158,   159,   168,   169,   171,   172,   173,   179,   182,
     184,   185,   186,   192,   194,   195,   197,   199,   200,   203,
     206,   207,   208,   210,   211,   215,   216,   217,   219,   223,
     225,   226,   231,   235,   238,   240,   242,   244,   246,   247,
     249,   250,   251,   255,   257,   258,   260,   268,   269,   281,
     284,   285,   288,   289,   292,   293,   301,   302,   303,   305,
     315,   316,   317,   319,   323,   324,   328,   336,   344,   345,
     346,   352,   353,   358,   361,   365,   366,   376,   394,   402,
     408,   419,   438,   440,   441,   449,   488,   499,   506,   530,
     531,   535,   547,   553,   554,   555,   556,   560,   564,   571,
     572,   582,   584,   595,   597,   600,   606,   632,   635,   640,
     643,   644,   658,   665,   688,   689,   690,   691,   692,   693,
     694,   697,   699,   701,   714,   715,   716,   717,   734,   756,
     770,   771,   777,   778,   797,   867,   868,   869,   870,   881,
     882,   883,   884,   885,   886,   887,   939,   943,   974,   995,
     997,  1000,  1001,  1002,  1003,  1016,  1025,  1046,  1047,  1049,
    1053,  1068,  1069,  1073,  1074,  1075,  1076,  1084,  1099,  1112,
    1123,  1124,  1125,  1136,  1139,  1175,  1178,  1180,  1186,  1187,
    1190,  1193,  1196,  1198,  1200,  1203,  1210,  1215,  1219,  1220,
    1221,  1233,  1234,  1237,  1243,  1244,  1245,  1270,  1285,  1286,
    1287,  1288,  1289,  1294,  1300,  1301,  1319,  1322,  1352,  1354,
    1444,  1445,  1476,  1477,  1484,  1495,  1519,  1528,  1533,  1535,
    1537,  1541,  1542,  1549,   771,  1087,   661,   684,  1132,  1133,
    1159,    20,   429,   463,   818,   841,    26,   846,    26,    26,
      26,   863,   865,   857,   821,    26,   988,   980,   721,    20,
     703,   988,   928,  1439,   928,    26,    26,   626,    24,    26,
     838,   929,   839,   429,   397,   513,   622,  1467,   429,   429,
      26,  1439,   429,   429,   429,   429,   429,   429,   429,   479,
     479,   479,   913,  1459,   479,   913,  1459,   923,   921,   927,
     925,    26,   916,     5,   917,   464,  1153,   828,    20,   818,
     468,    26,    26,   814,    26,   656,   429,     5,  1159,   429,
    1142,  1142,  1142,    25,  1142,  1197,   988,    25,   988,  1428,
     387,   989,   990,  1543,   988,   988,  1217,   983,   989,   983,
      25,   228,   988,  1151,  1523,  1524,  1525,   988,  1539,  1428,
     988,    26,   718,  1142,  1292,   983,  1217,   913,    26,   994,
    1257,  1258,  1257,   888,   895,  1321,   890,   913,   989,  1485,
    1485,   871,  1217,   983,  1290,  1142,   985,   989,   895,  1485,
    1142,  1217,  1142,  1320,  1485,    25,   622,  1126,  1127,  1142,
     983,   983,  1126,   984,   989,   988,  1127,   983,  1485,   983,
     985,  1142,  1173,  1174,   981,   989,   985,   413,   598,   980,
    1048,   988,   779,   986,   989,    25,  1353,  1523,   913,  1173,
     913,   989,  1199,   944,   170,   178,   187,   190,   233,   241,
     297,   322,   329,   331,   341,   367,   375,   413,   438,   476,
     487,   585,   586,   587,   598,   701,  1062,  1194,  1195,  1142,
     894,   895,  1209,  1534,  1534,   982,   989,   913,  1197,  1271,
    1142,  1248,    25,  1142,  1479,   895,  1239,  1240,  1241,  1250,
    1251,   895,  1529,   142,   193,   230,   327,   403,   444,   511,
     735,   919,   988,  1142,  1280,   758,   895,   981,   626,   988,
     996,  1113,   895,   981,    26,  1142,  1070,   981,   895,  1496,
     895,  1257,   988,   998,   999,   985,   998,  1534,   985,   998,
    1534,  1004,   998,    25,    26,   422,   524,   994,  1051,  1142,
    1161,  1163,   101,   312,   382,   427,   605,   685,   686,   687,
     696,   725,  1006,  1008,  1010,  1012,  1014,  1137,  1138,  1141,
     373,   384,   436,   451,   540,  1355,   676,   677,   952,   953,
     954,   988,  1134,   683,  1133,   429,   340,   429,   429,   429,
     429,   660,     5,   429,   429,   464,   468,   662,   429,    26,
     626,   662,    18,    19,    20,    25,    26,   100,   433,   448,
     465,   468,   481,   521,   533,   574,   613,   625,   637,   638,
     645,   648,   988,   994,  1434,  1436,  1466,  1468,  1469,  1471,
    1472,  1473,  1524,  1527,  1269,   429,  1269,  1269,  1269,  1269,
    1269,  1269,    25,    25,    25,   888,   905,   429,    25,   905,
     429,   429,   429,   429,   429,   429,   429,   753,   751,   464,
     340,   804,   826,   827,   429,   429,   660,   429,   988,  1275,
    1162,   429,  1265,    92,    93,   120,   121,   122,   492,   578,
     621,  1302,  1303,  1304,  1307,  1310,  1313,  1314,  1315,  1316,
     656,   626,   138,   139,   468,   656,  1525,  1152,   653,  1191,
     656,     8,   661,   464,    25,   988,  1427,   516,  1218,  1161,
     146,   147,   148,   520,   891,   892,   895,  1142,  1168,  1427,
     724,   725,   874,   304,   123,   124,   662,   497,     5,   655,
     662,   654,   654,  1176,   632,   458,     5,   593,  1026,   497,
     695,  1531,   695,   422,   781,  1142,   583,   654,  1181,  1182,
    1183,   364,  1351,   648,   893,   895,   593,   893,     8,   982,
      26,   538,   591,   705,   975,  1142,   975,   975,   975,    25,
     215,   342,   348,   349,   350,   368,   476,   479,   487,   522,
     557,   576,   577,   587,   592,   631,   663,  1066,  1067,   975,
     975,   633,  1063,   725,  1063,  1063,   976,   976,  1063,  1063,
     725,     5,   371,   423,     5,   724,   117,   118,   576,   663,
    1054,   698,  1532,   894,   649,   650,   651,   652,  1247,  1249,
     421,  1284,  1249,  1241,     5,   654,  1242,   895,   468,   468,
     468,   468,    25,   754,   988,   468,  1479,   382,   468,   558,
     626,   615,   759,   766,   757,   988,    25,  1128,  1142,  1235,
       8,  1238,    14,   988,  1147,  1155,  1156,  1158,  1166,  1167,
    1211,   201,   382,   581,   614,     5,     6,     7,     8,     9,
      10,    12,    13,    14,    18,    19,    20,    21,    22,    23,
      33,    49,    98,   107,   125,   127,   135,   142,   143,   146,
     147,   148,   149,   152,   153,   193,   215,   221,   228,   230,
     236,   261,   299,   312,   318,   327,   328,   334,   337,   338,
     342,   348,   349,   355,   356,   357,   358,   359,   360,   364,
     368,   370,   377,   378,   379,   380,   382,   383,   387,   388,
     390,   391,   392,   394,   395,   396,   397,   403,   404,   405,
     407,   408,   412,   413,   414,   415,   416,   417,   418,   419,
     421,   425,   426,   427,   428,   429,   430,   431,   432,   433,
     434,   435,   436,   437,   438,   439,   440,   441,   442,   443,
     444,   445,   446,   447,   448,   449,   450,   451,   452,   453,
     454,   455,   456,   457,   458,   459,   460,   461,   462,   464,
     465,   468,   469,   470,   471,   472,   473,   474,   475,   476,
     477,   479,   480,   481,   482,   483,   484,   485,   486,   487,
     488,   489,   490,   491,   492,   493,   496,   497,   498,   499,
     500,   501,   502,   503,   504,   506,   507,   508,   509,   511,
     512,   513,   514,   515,   516,   517,   518,   519,   520,   521,
     522,   523,   524,   525,   526,   527,   528,   529,   530,   531,
     532,   533,   534,   535,   536,   537,   538,   539,   540,   541,
     542,   543,   544,   545,   546,   548,   549,   550,   551,   552,
     553,   556,   557,   559,   560,   561,   562,   563,   564,   565,
     566,   567,   568,   569,   570,   571,   572,   573,   574,   575,
     576,   577,   578,   579,   580,   581,   582,   583,   584,   587,
     588,   589,   590,   591,   592,   593,   594,   595,   596,   597,
     598,   599,   600,   601,   602,   603,   604,   605,   606,   607,
     608,   609,   610,   611,   612,   613,   614,   615,   616,   617,
     618,   619,   620,   621,   622,   623,   624,   625,   626,   627,
     628,   629,   630,   631,   632,   633,   634,   635,   636,   637,
     638,   639,   640,   641,   642,   643,   644,   645,   646,   647,
     648,   653,   654,   655,   656,   657,   658,   659,   660,   661,
     662,   663,   674,   682,   687,   691,   694,   695,   696,   697,
     700,   701,   703,   704,   705,  1497,  1498,  1499,  1501,   612,
       5,   695,   695,   893,  1161,  1168,  1050,   458,     5,   189,
    1030,   468,  1142,   893,   468,    26,    26,   101,  1140,    25,
    1142,  1483,  1483,   989,  1335,  1199,   982,   156,   259,   267,
     273,   275,   286,   314,   330,   335,   347,   354,   508,   515,
     537,   542,  1323,  1324,  1332,  1342,  1343,  1349,  1350,  1356,
    1357,  1366,  1385,  1389,  1455,  1456,  1486,  1487,  1490,  1491,
    1503,   955,   956,   127,   951,   962,   963,   954,  1135,  1544,
    1093,   496,   854,   821,   656,   988,   404,   491,   507,   550,
     589,   618,   627,  1440,   928,   626,    24,    26,   842,  1472,
    1472,   404,   491,   507,   550,   589,   618,   627,  1437,  1441,
     508,  1471,   468,   468,   468,   468,   468,   468,   468,   988,
     468,     5,   583,  1394,  1399,   988,    18,    19,    20,    21,
     128,   129,   130,   131,   132,   133,  1493,   458,     5,   429,
     429,   918,   496,     5,   429,   828,   798,  1110,   798,   196,
     334,   411,   468,   513,   529,  1372,  1384,   468,   988,  1318,
      26,   283,   296,   468,   513,   529,   988,  1299,  1312,  1370,
    1371,  1376,  1378,  1380,   468,   988,  1309,   468,  1299,  1305,
       5,   988,   988,    25,   991,  1145,  1525,  1523,   613,   653,
    1192,    20,   988,  1172,  1526,   988,  1540,  1427,   632,   656,
     626,   468,   468,   874,     5,   662,   468,  1523,    25,   993,
    1216,  1216,  1479,  1126,   895,   895,   895,   977,   978,   468,
    1142,  1174,   835,  1027,  1028,   662,  1479,  1534,  1532,  1048,
    1142,   780,   661,   895,   388,  1185,   593,  1184,   988,     5,
    1520,   104,   106,   108,   654,   662,   866,  1161,   945,    18,
      19,   468,  1064,  1066,  1195,   976,   895,   382,   632,    26,
      26,   724,   191,  1246,   256,  1251,  1257,  1530,   988,    25,
     938,  1534,   626,   980,   659,  1142,   739,   988,   988,   895,
     377,   762,   766,   615,   760,   768,    23,   272,  1115,  1119,
     519,   913,   519,  1236,   895,   495,  1152,   656,     5,  1071,
     583,  1212,  1142,  1500,  1502,   227,  1498,  1017,   999,  1534,
    1534,  1009,  1010,  1030,  1030,    38,    40,    41,    42,   308,
     311,   313,   333,   343,   362,   385,   389,   467,  1029,  1031,
    1032,  1058,  1142,  1163,   583,   726,    26,   437,  1015,   359,
    1478,  1478,   176,   177,   474,   583,   988,  1386,  1387,  1429,
     835,  1427,  1427,  1325,   835,   988,  1488,  1488,  1467,  1427,
    1333,   205,   476,   487,   508,   515,  1359,  1360,  1361,  1544,
    1544,   422,   964,  1142,   678,   679,   957,   958,   959,   518,
     661,   680,   681,   700,   967,   968,  1544,   798,    26,   819,
      20,   988,   429,   468,    24,    26,   662,  1467,   429,   433,
    1494,  1527,   397,   513,   622,  1418,  1471,  1474,  1418,  1418,
    1418,  1418,   656,  1474,  1469,   552,  1395,  1396,  1397,  1427,
     563,  1393,  1400,   369,   551,   562,  1344,  1462,  1471,  1471,
    1471,  1471,  1524,   888,   429,   819,   827,  1276,   798,  1266,
    1374,  1427,  1317,  1384,   468,  1317,   468,   468,  1311,  1312,
     468,   468,    99,   337,   357,   395,   407,   418,   435,   445,
     448,   461,   509,   539,   549,   570,   574,   602,   611,  1419,
    1420,  1421,  1423,  1308,  1309,  1305,  1306,   700,  1303,   429,
     656,  1479,   613,   496,   583,  1538,   468,   719,   720,   988,
     988,   988,  1293,   913,   891,   988,  1291,   653,  1188,   662,
       5,     5,     5,   616,   895,   656,     5,   520,   662,   661,
     202,   204,   308,   311,   782,   785,   786,  1058,   783,   784,
     988,   468,   989,   685,   686,  1189,   895,   835,  1521,  1522,
     988,   988,   978,   979,   546,  1534,   874,     8,   947,    26,
      26,  1065,  1066,  1142,   357,  1204,   101,   888,  1249,    26,
    1142,  1544,     5,     5,   429,   429,   755,   988,   429,  1479,
     751,   468,   468,   767,   763,   398,   761,   895,   377,   764,
     768,   633,  1060,  1120,  1116,   400,  1114,  1115,   893,   662,
    1148,    20,   988,  1157,  1167,    14,   520,  1213,  1214,  1471,
    1527,  1142,  1164,  1165,  1544,  1011,  1012,   587,   987,   583,
    1041,  1040,  1043,  1042,   980,  1044,   980,  1045,  1039,  1038,
    1036,  1035,  1059,   362,  1032,  1037,  1534,    44,    45,    46,
      47,    48,    49,   134,   370,   383,   447,   454,   493,   517,
     527,   528,   533,   543,   565,   568,   569,   573,   630,   641,
     727,   728,  1056,  1057,     5,    26,  1479,   286,  1142,   508,
    1460,  1461,  1479,  1199,  1454,  1456,   136,   136,   632,  1197,
    1388,  1389,   468,  1367,   188,  1400,  1427,   212,   309,  1492,
     656,   662,  1457,  1504,   379,   388,   413,   416,   433,   538,
     591,   598,   982,  1336,  1341,   468,  1362,   661,     5,   966,
    1142,     5,   583,   960,   961,   675,   959,   965,   988,   965,
     969,   970,   965,   362,   968,  1094,   464,    26,   404,   491,
     507,   550,   589,   618,   627,  1442,  1468,     5,  1441,   429,
       5,  1471,     5,   429,  1471,  1471,  1471,  1471,   988,   429,
     468,  1397,     5,   988,  1433,     9,   332,   468,   480,  1403,
    1404,  1405,  1406,  1407,  1411,  1415,  1417,  1471,   406,  1391,
    1401,   988,  1463,   655,  1418,   369,   464,   498,  1259,  1279,
    1111,   498,  1222,  1253,   468,     5,   429,  1403,   429,   648,
     988,  1373,  1375,  1427,  1431,  1432,  1377,  1431,     5,   429,
    1377,  1403,   468,  1441,  1441,   468,   468,   468,   468,   468,
     245,   437,  1379,  1381,     5,   429,     5,   429,   988,  1526,
       8,  1479,  1153,   895,   988,  1296,  1297,     5,  1298,  1299,
     913,  1100,   656,  1298,   613,  1479,  1479,   895,   895,   977,
     546,   895,  1536,     5,    20,  1431,  1028,  1479,   783,   791,
     790,   792,   988,   992,   793,   992,   229,   786,   789,     5,
    1030,   656,   895,     8,   656,     5,   988,   913,   590,  1339,
       5,   429,  1142,     5,   363,    25,  1281,   382,   382,   496,
     656,   382,   468,   740,   744,   737,  1544,  1544,   769,   765,
     761,  1061,    25,   987,  1121,  1142,  1544,   895,   463,   496,
     913,     5,   458,     5,  1018,  1013,  1014,    26,   724,   988,
    1544,  1544,  1544,  1544,     5,  1033,     5,  1034,  1544,  1544,
    1544,  1544,  1064,  1544,   987,    25,    14,    14,     5,   429,
      26,  1427,  1467,  1448,   632,   632,  1324,  1453,  1454,  1389,
    1368,  1431,   653,   982,   468,  1328,   988,  1489,  1488,  1468,
      84,    85,    86,    87,    88,   620,  1507,   895,   895,  1334,
     982,  1363,  1431,  1427,  1361,     5,  1142,   965,  1544,  1544,
       5,   972,   973,  1544,  1544,   971,  1087,   858,   429,   468,
    1399,  1441,   662,  1441,   429,  1471,   429,   429,   429,   429,
    1396,  1398,  1396,  1406,   468,  1466,  1403,  1471,  1466,     6,
       7,     9,    10,    12,    13,    14,    15,    16,    17,   290,
     409,   410,   466,   593,   659,   709,   710,  1414,  1416,  1392,
    1470,  1471,   485,  1390,  1402,   306,  1295,    26,  1345,  1346,
    1347,  1431,  1460,  1463,   816,   109,   110,   112,   113,   114,
     214,   222,   256,   265,   294,   295,   339,   381,   437,   664,
     665,   666,   667,   668,   669,   670,   671,   672,   673,  1256,
    1260,   175,   551,  1261,  1277,  1087,   198,   213,   214,   222,
     256,   265,   294,   339,   381,  1254,  1255,  1267,  1261,  1375,
    1384,   429,  1432,   496,  1430,   429,     5,   656,     5,   429,
    1312,   429,   429,    26,  1424,   662,   468,   662,    26,  1425,
    1425,    26,  1425,  1425,    25,  1434,  1382,  1383,  1384,  1309,
    1305,  1479,     8,   464,   575,   624,     5,   429,   720,     5,
     429,   893,   429,    20,   429,  1479,     5,   895,   603,   312,
     729,   730,   895,  1030,  1544,  1544,     5,   787,   496,   656,
       5,   788,  1544,   784,   583,    20,   988,     5,   988,  1179,
      20,  1431,  1522,   427,   695,   893,  1340,   946,  1066,   704,
    1202,   888,     5,   751,  1142,   736,   718,   988,  1142,   742,
     429,   751,   751,  1544,  1544,  1064,  1118,    25,  1122,  1142,
     608,   942,  1153,   520,   894,  1072,  1214,  1142,  1165,    98,
     579,  1019,  1005,  1006,   656,   980,  1544,   980,  1544,   724,
      26,  1142,    26,  1142,   728,   429,   468,  1480,  1468,  1454,
    1454,  1446,     5,   429,   508,  1465,  1329,  1431,   516,  1326,
    1465,   662,  1458,    18,    19,   100,   465,   468,   481,   520,
     521,   533,   574,   613,   625,   637,   638,   645,   648,   988,
    1434,  1466,  1512,  1513,  1514,  1515,  1516,  1517,  1527,  1512,
    1512,  1512,  1431,  1509,  1511,  1508,  1509,  1510,  1505,   590,
    1337,     5,   429,   662,  1142,   988,  1544,  1544,  1544,  1544,
     660,    26,   429,   662,  1442,   662,     5,   429,   429,  1404,
    1405,  1409,  1472,  1409,   468,  1466,  1409,   468,  1466,  1409,
      10,   287,   424,   426,  1471,     5,  1403,     5,   575,   624,
    1348,  1295,   660,  1257,  1257,  1257,    25,  1257,  1257,  1257,
    1257,  1257,  1257,    25,    25,  1257,  1260,  1142,  1169,  1170,
     655,   484,  1223,  1544,    25,    25,    26,    26,    26,    26,
      26,    25,  1142,  1255,  1223,   429,    26,  1372,  1431,    20,
     988,  1431,   429,  1442,    26,  1442,     5,  1422,  1422,     5,
     429,   429,  1422,  1384,  1479,  1297,  1299,  1295,   505,   873,
       5,   412,  1479,     5,   468,   429,   587,  1055,   992,  1544,
     721,    20,   988,   992,  1544,  1534,   895,  1534,  1164,  1544,
      26,   987,    25,  1282,  1161,   464,   751,   741,   745,   429,
    1544,   987,   895,   940,   464,  1021,  1020,   478,  1007,  1008,
      20,   988,  1481,  1482,   590,  1464,  1449,  1447,  1431,  1467,
     180,  1369,     5,   429,  1327,  1489,  1464,  1515,  1515,  1514,
     468,   468,   468,   468,   468,   468,   468,   988,   468,     5,
     429,    18,    19,    20,    21,  1493,   429,     5,   429,     5,
      14,   188,   563,  1506,  1338,  1431,   500,  1364,  1365,  1429,
     248,  1095,   854,   429,  1442,  1442,  1396,   479,  1408,  1408,
    1412,  1413,  1434,  1527,  1408,  1412,  1408,  1409,  1471,  1470,
    1346,   828,   575,   624,  1171,     5,  1169,    97,   174,   237,
     239,   254,   262,   266,   291,  1224,  1225,  1278,  1095,  1268,
       5,   464,  1430,   429,    26,  1426,   429,   429,    26,   429,
     980,   724,   412,  1479,   895,   731,   605,  1177,    26,   724,
     464,  1055,   429,   278,   724,   429,   429,   468,   743,   382,
     749,   429,   738,  1117,  1544,   496,   895,  1544,   987,     5,
     429,  1164,  1399,  1468,  1431,   468,  1399,   429,  1494,  1418,
    1514,  1518,  1418,  1418,  1418,  1418,   656,  1518,  1513,  1514,
    1514,  1514,  1514,  1509,    14,  1510,  1513,   982,  1403,  1164,
       5,   181,  1358,  1410,  1434,  1475,     5,   429,   429,  1408,
       7,  1170,  1226,  1227,  1142,  1229,  1142,  1228,  1230,  1225,
     277,   277,    26,   662,   429,   872,  1479,   430,   241,   297,
     322,   331,   367,   375,   469,   639,   728,   732,   733,   468,
     656,   724,  1201,  1283,   746,   429,  1161,   749,   749,  1544,
     941,  1153,   612,  1052,  1482,  1462,  1399,   520,  1330,  1331,
    1471,  1462,   429,  1514,     5,   429,  1514,  1514,  1514,  1514,
     988,   429,   468,  1365,  1413,  1471,  1544,  1544,  1231,  1544,
    1232,  1544,  1544,   464,  1442,   276,   385,   389,   875,   876,
     877,  1058,   975,   975,   975,   975,   975,   975,    25,     5,
     429,   895,    20,   988,  1058,  1205,  1206,  1207,   749,   751,
     749,   279,   464,  1022,   724,     5,   429,   325,   326,  1450,
     429,  1514,   429,   429,   429,   429,  1512,  1544,  1544,   879,
     878,   276,   877,   880,   733,     5,  1208,   320,  1207,   747,
    1544,  1331,    25,   988,  1451,  1452,   429,  1544,  1544,  1544,
     895,  1544,   429,  1019,   656,   656,     5,   429,   748,   988,
     988,  1452,   201,   382,   750,   656,  1161,   988
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
#line 980 "fgl.yacc"
    { print_screen_mode(0);}
    break;

  case 3:
#line 983 "fgl.yacc"
    { print_screen_mode(1);}
    break;

  case 4:
#line 987 "fgl.yacc"
    {
		print_start_server(yyvsp[-3].str,yyvsp[0].str);
	}
    break;

  case 5:
#line 993 "fgl.yacc"
    {
	print_stop_external();
	}
    break;

  case 6:
#line 998 "fgl.yacc"
    {
		if (scan_variable(yyvsp[0].str)!=2) {
		char buff[256];
			strcpy(buff,"START EXTERNAL ..ON must be an integer");
			a4gl_yyerror(buff);
			YYERROR;
		}
	}
    break;

  case 9:
#line 1010 "fgl.yacc"
    {
	sprintf(yyval.str,"%s%s",yyvsp[-2].str,yyvsp[0].str);
	}
    break;

  case 10:
#line 1015 "fgl.yacc"
    {
	print_remote_func(yyvsp[0].str);
	sprintf(yyval.str,
		"A4GL_unregister_func(\"%s\",%s%s);\n",
			yyvsp[0].str,
			(char *)get_namespace(yyvsp[0].str),
			yyvsp[0].str
	);
	addmap("Call Remote",yyvsp[0].str,curr_func,yylineno,infilename);
	}
    break;

  case 11:
#line 1038 "fgl.yacc"
    {sprintf(yyval.str,"(%s)",yyvsp[-1].str);}
    break;

  case 12:
#line 1039 "fgl.yacc"
    { sprintf(yyval.str,"%s%s%s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 13:
#line 1040 "fgl.yacc"
    {sprintf(yyval.str,"%d",atoi(yyvsp[0].str));}
    break;

  case 14:
#line 1041 "fgl.yacc"
    {sprintf(yyval.str,"(%s%s)",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 15:
#line 1042 "fgl.yacc"
    {
  int a;
  a=scan_variable(yyvsp[0].str)&15;
  if (a!=1&&a!=2) {
    
    a4gl_yyerror("Only INTEGER/SMALLINT variables may be used as subscripts");
    YYERROR;
    /* error processing */;
  }
  sprintf(yyval.str,"%s",fgl_add_scope(yyvsp[0].str,0));
}
    break;

  case 16:
#line 1053 "fgl.yacc"
    {
	sprintf(yyval.str,print_arr_expr_fcall(yyvsp[0].ptr));
}
    break;

  case 17:
#line 1059 "fgl.yacc"
    {strcpy(yyval.str,"+");}
    break;

  case 18:
#line 1060 "fgl.yacc"
    {strcpy(yyval.str,"-");}
    break;

  case 19:
#line 1061 "fgl.yacc"
    {strcpy(yyval.str,"*");}
    break;

  case 20:
#line 1062 "fgl.yacc"
    {strcpy(yyval.str,"/");}
    break;

  case 21:
#line 1063 "fgl.yacc"
    {strcpy(yyval.str,"%");}
    break;

  case 22:
#line 1068 "fgl.yacc"
    {strcpy(yyval.str,"+");}
    break;

  case 23:
#line 1069 "fgl.yacc"
    {strcpy(yyval.str,"-");}
    break;

  case 24:
#line 1080 "fgl.yacc"
    {
	 A4GL_debug("Using default attribute of WHITE");
		sprintf(yyval.str,"%d",0);}
    break;

  case 25:
#line 1083 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 26:
#line 1086 "fgl.yacc"
    {start_state("attribute",1);}
    break;

  case 27:
#line 1086 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[-1].str);
A4GL_debug("Got Attributes : %s",yyvsp[-1].str);
start_state("attribute",0);
}
    break;

  case 29:
#line 1093 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 30:
#line 1094 "fgl.yacc"
    {
sprintf(yyval.str,"%d",atoi(yyvsp[-2].str)|atoi(yyvsp[0].str));
}
    break;

  case 31:
#line 1100 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("BLACK"));}
    break;

  case 32:
#line 1101 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("BLUE"));}
    break;

  case 33:
#line 1102 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("CYAN"));}
    break;

  case 34:
#line 1103 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("GREEN"));}
    break;

  case 35:
#line 1104 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("MAGENTA"));}
    break;

  case 36:
#line 1105 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("RED"));}
    break;

  case 37:
#line 1106 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("WHITE"));}
    break;

  case 38:
#line 1107 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("YELLOW"));}
    break;

  case 39:
#line 1108 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("REVERSE"));}
    break;

  case 40:
#line 1109 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("BLINK"));}
    break;

  case 41:
#line 1110 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("UNDERLINE"));}
    break;

  case 42:
#line 1111 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("BOLD"));}
    break;

  case 43:
#line 1112 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("NORMAL"));}
    break;

  case 44:
#line 1113 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("INVISIBLE"));}
    break;

  case 45:
#line 1114 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("DIM"));}
    break;

  case 46:
#line 1115 "fgl.yacc"
    {inp_flags=inp_flags | 0x1; strcpy(yyval.str,"0");}
    break;

  case 47:
#line 1116 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 50:
#line 1123 "fgl.yacc"
    {
A4GL_debug("win_attributes_def");
start_state("attribute",1);
A4GL_debug("Started states");
form_attrib.attrib=0;
form_attrib.comment_line=0xff;
form_attrib.form_line=0xff;
form_attrib.error_line=0xff;
form_attrib.menu_line=0xff;
form_attrib.message_line=0xff;
form_attrib.prompt_line=0xff;
}
    break;

  case 51:
#line 1134 "fgl.yacc"
    {start_state("attribute",0);strcpy(yyval.str,"");
}
    break;

  case 52:
#line 1138 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 53:
#line 1139 "fgl.yacc"
    {sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 54:
#line 1143 "fgl.yacc"
    { 
/*printf("Window attribute = %s\n",$<str>1);*/
form_attrib.attrib      =form_attrib.attrib|atoi(yyvsp[0].str);
/*printf("Window attribute = %d\n",form_attrib.attrib);*/
}
    break;

  case 55:
#line 1149 "fgl.yacc"
    { form_attrib.border      =1;}
    break;

  case 56:
#line 1151 "fgl.yacc"
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

  case 57:
#line 1162 "fgl.yacc"
    { form_attrib.comment_line=atoi(yyvsp[0].str); }
    break;

  case 58:
#line 1164 "fgl.yacc"
    { form_attrib.form_line   =atoi(yyvsp[0].str); }
    break;

  case 59:
#line 1166 "fgl.yacc"
    { form_attrib.error_line  =atoi(yyvsp[0].str); }
    break;

  case 60:
#line 1168 "fgl.yacc"
    { form_attrib.menu_line   =atoi(yyvsp[0].str); 
A4GL_debug("Set menu line to %s",yyvsp[0].str);
}
    break;

  case 61:
#line 1172 "fgl.yacc"
    { form_attrib.message_line=atoi(yyvsp[0].str); }
    break;

  case 62:
#line 1174 "fgl.yacc"
    { form_attrib.prompt_line =atoi(yyvsp[0].str); }
    break;

  case 63:
#line 1235 "fgl.yacc"
    {strcpy(yyval.str,"CALL");}
    break;

  case 64:
#line 1239 "fgl.yacc"
    { A4GL_debug("print_expr (3)"); 
		print_expr(yyvsp[-2].ptr);
		print_pop_variable(yyvsp[0].str);
	}
    break;

  case 65:
#line 1243 "fgl.yacc"
    {
        if (!isin_command("INPUT")&&!isin_command("CONSTRUCT")) {
                a4gl_yyerror("get_fldbuf can only be used in an input or construct");
                YYERROR;
        }
	print_getfldbuf(field_name_list_as_char(yyvsp[-2].field_list));
	}
    break;

  case 66:
#line 1250 "fgl.yacc"
    {
		print_returning();
	}
    break;

  case 67:
#line 1253 "fgl.yacc"
    {
	print_form_is_compiled(yyvsp[-5].str,yyvsp[-3].str,yyvsp[-1].str);
	}
    break;

  case 68:
#line 1257 "fgl.yacc"
    {
		print_field_func('I',field_name_as_char(yyvsp[-3].field_entry),yyvsp[0].str);
   }
    break;

  case 70:
#line 1261 "fgl.yacc"
    { 
        if (!isin_command("INPUT")&&!isin_command("CONSTRUCT")) {
                a4gl_yyerror("get_fldbuf can only be used in an input or construct");
                YYERROR;
        }
	print_field_func('T',field_name_list_as_char(yyvsp[-3].field_list),yyvsp[0].str);
   }
    break;

  case 71:
#line 1268 "fgl.yacc"
    {
	new_counter();
   	addmap("Call",yyvsp[-3].str,curr_func,yylineno,infilename);
   }
    break;

  case 72:
#line 1274 "fgl.yacc"
    {
	int a;
	dump_expr(yyvsp[-1].ptr);
	a=get_counter_val();
	drop_counter();
 A4GL_debug("Printing call_func_call...");
  	print_class_func_call(yyvsp[-6].str,yyvsp[-4].str,yyvsp[-1].ptr,a);
   }
    break;

  case 73:
#line 1283 "fgl.yacc"
    {
	print_returning();
	strcpy(yyval.str,yyvsp[-4].str); /* ? */
   }
    break;

  case 74:
#line 1287 "fgl.yacc"
    {
	new_counter();
   	addmap("Call",yyvsp[-1].str,curr_func,yylineno,infilename);
   }
    break;

  case 75:
#line 1292 "fgl.yacc"
    {
 A4GL_debug("Got args");
   }
    break;

  case 76:
#line 1296 "fgl.yacc"
    {
	int a;
	dump_expr(yyvsp[-2].ptr);
	a=get_counter_val();
	drop_counter();
  	print_func_call(yyvsp[-5].str,yyvsp[-2].ptr,a);
   }
    break;

  case 77:
#line 1304 "fgl.yacc"
    {
	print_returning();
	strcpy(yyval.str,yyvsp[-3].str); /* ? */
   }
    break;

  case 78:
#line 1308 "fgl.yacc"
    {
	A4GLSQL_set_status(0,0);
	new_counter();
	}
    break;

  case 79:
#line 1312 "fgl.yacc"
    {
   sprintf(yyval.str,"%d",get_counter_val());drop_counter();
}
    break;

  case 80:
#line 1314 "fgl.yacc"
    {
        print_expr ((struct expr_str *)yyvsp[-3].ptr);  
	print_call_shared(yyvsp[-6].str,yyvsp[-8].str,atoi(yyvsp[-2].str));
	print_returning();
	print_end_call_shared();
}
    break;

  case 81:
#line 1320 "fgl.yacc"
    {
	sprintf(yyval.str,"\"%s\",\"%s\"",yyvsp[-3].str,yyvsp[-1].str);
	A4GLSQL_set_status(0,0);
	new_counter();
	}
    break;

  case 82:
#line 1325 "fgl.yacc"
    {
   	sprintf(yyval.str,"%d",get_counter_val());drop_counter();
}
    break;

  case 83:
#line 1328 "fgl.yacc"
    {
	char buff[256];
	char *ptr;
 A4GL_debug("STR6 = %s",yyvsp[-4].str);
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

  case 84:
#line 1344 "fgl.yacc"
    {
   char buff[256];
   new_counter();
   sprintf(buff,"%s:%s(%p)",yyvsp[-6].str,yyvsp[-4].str,yyvsp[-2].str);
   addmap("External",buff,curr_func,yylineno,infilename);
   }
    break;

  case 85:
#line 1351 "fgl.yacc"
    {
   sprintf(yyval.str,"%d",get_counter_val());drop_counter();
   }
    break;

  case 86:
#line 1355 "fgl.yacc"
    {
	 A4GL_debug("print_expr (6)");print_expr(yyvsp[-2].ptr);
   }
    break;

  case 87:
#line 1359 "fgl.yacc"
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

  case 88:
#line 1381 "fgl.yacc"
    {start_bind('i',0);strcpy(yyval.str,"0");}
    break;

  case 89:
#line 1381 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);
}
    break;

  case 90:
#line 1385 "fgl.yacc"
    {start_bind('i',0);strcpy(yyval.str,"0");}
    break;

  case 91:
#line 1386 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 92:
#line 1387 "fgl.yacc"
    {strcpy(yyval.str,"WITHOUT WAITING"); }
    break;

  case 93:
#line 1392 "fgl.yacc"
    {
			yyval.ptr=A4GL_new_expr("");
		}
    break;

  case 94:
#line 1395 "fgl.yacc"
    {
			yyval.ptr=yyvsp[0].ptr;
		}
    break;

  case 95:
#line 1401 "fgl.yacc"
    {
	yyval.ptr=yyvsp[0].ptr;
}
    break;

  case 96:
#line 1404 "fgl.yacc"
    {
		yyval.ptr=A4GL_append_expr_expr(yyvsp[-2].ptr,yyvsp[0].ptr);
}
    break;

  case 99:
#line 1416 "fgl.yacc"
    {
sprintf(yyval.str,"\"%s\"",yyvsp[0].str);
}
    break;

  case 100:
#line 1422 "fgl.yacc"
    {
sprintf(yyval.str,"\"%s\"",yyvsp[0].str);
}
    break;

  case 101:
#line 1425 "fgl.yacc"
    { sprintf(yyval.str,"\"%s.%s\"",yyvsp[-2].str,yyvsp[0].str); }
    break;

  case 102:
#line 1440 "fgl.yacc"
    {
push_blockcommand("CASE");
setinc(1);
A4GL_incprint();
print_case(1);
setinc(1);
}
    break;

  case 103:
#line 1450 "fgl.yacc"
    {
print_after_when(0);
pop_blockcommand("CASE");
}
    break;

  case 104:
#line 1456 "fgl.yacc"
    {  push_blockcommand("CASE"); 
setinc(1);
A4GL_incprint(); 
print_case(0);
setinc(1);
}
    break;

  case 105:
#line 1465 "fgl.yacc"
    {
print_after_when(0);
pop_blockcommand("CASE");
}
    break;

  case 110:
#line 1478 "fgl.yacc"
    {setinc(-1);A4GL_incprint();}
    break;

  case 112:
#line 1481 "fgl.yacc"
    {
A4GL_incprint();
}
    break;

  case 113:
#line 1483 "fgl.yacc"
    {A4GL_incprint();
print_after_when(0);
}
    break;

  case 115:
#line 1489 "fgl.yacc"
    {A4GL_incprint();}
    break;

  case 116:
#line 1491 "fgl.yacc"
    {A4GL_incprint();
print_after_when(0);
}
    break;

  case 117:
#line 1496 "fgl.yacc"
    {
print_when(0);

A4GL_incprint();
}
    break;

  case 118:
#line 1501 "fgl.yacc"
    {A4GL_incprint();
print_after_when(1);
setinc(-1);}
    break;

  case 119:
#line 1507 "fgl.yacc"
    {
A4GL_incprint();
print_when(1);
}
    break;

  case 120:
#line 1511 "fgl.yacc"
    {A4GL_incprint();
print_after_when(1);
setinc(-1);}
    break;

  case 121:
#line 1526 "fgl.yacc"
    {
  print_close('F',yyvsp[0].str);
 }
    break;

  case 122:
#line 1529 "fgl.yacc"
    {
  print_close('W',yyvsp[0].str);
}
    break;

  case 123:
#line 1532 "fgl.yacc"
    {
  print_close('W',yyvsp[0].str);
}
    break;

  case 124:
#line 1535 "fgl.yacc"
    {
  print_close('D',0);
}
    break;

  case 125:
#line 1538 "fgl.yacc"
    {
  print_close('S',yyvsp[0].str);
}
    break;

  case 126:
#line 1541 "fgl.yacc"
    {
  print_close('C',yyvsp[0].str);
}
    break;

  case 132:
#line 1563 "fgl.yacc"
    {
			A4GL_lex_printc("%s",yyvsp[0].str);
}
    break;

  case 135:
#line 1572 "fgl.yacc"
    {
			A4GL_lex_printc("%s\n",yyvsp[0].str);
}
    break;

  case 136:
#line 1582 "fgl.yacc"
    {
/* This aint used - its filtered by the lexer first... */
	A4GL_lex_printc("FIXME : Comment : %s\n");
}
    break;

  case 137:
#line 1596 "fgl.yacc"
    {
push_blockcommand("CONSTRUCT");
A4GL_new_events();
}
    break;

  case 138:
#line 1601 "fgl.yacc"
    {
	print_construct_1();
}
    break;

  case 139:
#line 1604 "fgl.yacc"
    {
	print_construct_2(yyvsp[-2].str);
A4GL_drop_events();
}
    break;

  case 140:
#line 1613 "fgl.yacc"
    {
	print_construct_3(1,yyvsp[-5].str,0,yyvsp[0].str,atoi(yyvsp[0].str));
	strcpy(yyval.str,A4GL_get_formloop_str(0));
	reset_constr();
}
    break;

  case 141:
#line 1619 "fgl.yacc"
    {
	print_construct_3(0,yyvsp[-7].str,field_name_list_as_char(yyvsp[-2].field_list),yyvsp[0].str,atoi(yyvsp[0].str));
	strcpy(yyval.str,A4GL_get_formloop_str(0));
	reset_constr();
}
    break;

  case 146:
#line 1634 "fgl.yacc"
    {
                push_construct("",yyval.str);
             }
    break;

  case 147:
#line 1638 "fgl.yacc"
    {
                sprintf(yyval.str,"%s.%s",yyvsp[-2].str,yyvsp[0].str);
                push_construct(yyvsp[-2].str,yyvsp[0].str); 
             }
    break;

  case 148:
#line 1643 "fgl.yacc"
    {
                push_construct(yyvsp[-2].str,"*");
             }
    break;

  case 151:
#line 1653 "fgl.yacc"
    { A4GL_add_event(-97,field_name_list_as_or_char(yyvsp[0].field_list)); print_befaft_field_1(field_name_list_as_or_char(yyvsp[0].field_list)); }
    break;

  case 152:
#line 1653 "fgl.yacc"
    { print_befaft_field_2(); }
    break;

  case 153:
#line 1654 "fgl.yacc"
    { A4GL_add_event(-98,field_name_list_as_or_char(yyvsp[0].field_list)); print_befaft_field_1(field_name_list_as_or_char(yyvsp[0].field_list)); }
    break;

  case 154:
#line 1654 "fgl.yacc"
    { print_befaft_field_2(); }
    break;

  case 155:
#line 1655 "fgl.yacc"
    { A4GL_add_onkey_key(yyvsp[0].str); print_onkey_1(yyvsp[0].str); }
    break;

  case 156:
#line 1655 "fgl.yacc"
    { print_onkey_2(); }
    break;

  case 157:
#line 1656 "fgl.yacc"
    { A4GL_add_event(-95,""); print_befaft_field_1("AFTER_INP"); }
    break;

  case 158:
#line 1656 "fgl.yacc"
    { print_befaft_field_2(); }
    break;

  case 159:
#line 1657 "fgl.yacc"
    { A4GL_add_event(-99,""); print_befaft_field_1("BEFORE_INP"); }
    break;

  case 160:
#line 1657 "fgl.yacc"
    { print_befaft_field_2(); }
    break;

  case 161:
#line 1665 "fgl.yacc"
    {
			yyval.field_list=new_field_list();
			yyval.field_list=append_field_to_list(yyval.field_list,yyvsp[0].field_entry);
	}
    break;

  case 162:
#line 1669 "fgl.yacc"
    {
			yyval.field_list=append_field_to_list(yyvsp[-2].field_list,yyvsp[0].field_entry);
	}
    break;

  case 163:
#line 1675 "fgl.yacc"
    {
			yyval.field_list=new_field_list();
			yyval.field_list=append_field_to_list(yyval.field_list,yyvsp[0].field_entry);
	}
    break;

  case 164:
#line 1679 "fgl.yacc"
    {
			yyval.field_list=append_field_to_list(yyvsp[-2].field_list,yyvsp[0].field_entry);
	}
    break;

  case 165:
#line 1694 "fgl.yacc"
    {
        	yyval.ptr=A4GL_new_expr("A4GL_pushop(OP_YEAR);");
	}
    break;

  case 166:
#line 1697 "fgl.yacc"
    {
        	yyval.ptr=A4GL_new_expr("A4GL_pushop(OP_MONTH);");
	}
    break;

  case 167:
#line 1700 "fgl.yacc"
    {
        	yyval.ptr=A4GL_new_expr("A4GL_pushop(OP_DAY);");
	}
    break;

  case 168:
#line 1703 "fgl.yacc"
    {
        	yyval.ptr=A4GL_new_expr("A4GL_pushop(OP_HOUR);");
	}
    break;

  case 169:
#line 1706 "fgl.yacc"
    {
        	yyval.ptr=A4GL_new_expr("A4GL_pushop(OP_MINUTE);");
	}
    break;

  case 170:
#line 1709 "fgl.yacc"
    {
        	yyval.ptr=A4GL_new_expr("A4GL_pushop(OP_SECOND);");
	}
    break;

  case 171:
#line 1718 "fgl.yacc"
    {
			yyval.ptr=A4GL_append_expr_expr(yyvsp[-2].ptr,yyvsp[-1].ptr);
		}
    break;

  case 172:
#line 1726 "fgl.yacc"
    { 
	char buff[50];
	sprintf(buff,"A4GL_push_int(%d);",(19*16)+10); 
	yyval.ptr=A4GL_new_expr(buff);
}
    break;

  case 173:
#line 1731 "fgl.yacc"
    { 
	char buff[50];
	sprintf(buff,"A4GL_push_int(%d);",(atoi(yyvsp[-2].str)*16) +atoi(yyvsp[0].str)  ); 
	yyval.ptr=A4GL_new_expr(buff);
}
    break;

  case 174:
#line 1744 "fgl.yacc"
    {
				print_defer(0);
			}
    break;

  case 175:
#line 1748 "fgl.yacc"
    {
				print_defer(1);
			}
    break;

  case 176:
#line 1763 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 177:
#line 1764 "fgl.yacc"
    {strcpy(yyval.str,"");lastlineno=yylineno;}
    break;

  case 180:
#line 1772 "fgl.yacc"
    {dtypelist[0]=0;A4GL_lex_printcomment("/* define */\n");}
    break;

  case 181:
#line 1772 "fgl.yacc"
    {A4GL_lex_printcomment("/*end def */\n");}
    break;

  case 186:
#line 1781 "fgl.yacc"
    {in_define=1;}
    break;

  case 187:
#line 1781 "fgl.yacc"
    {in_define=0;strcpy(yyval.str,yyvsp[0].str);
                        set_yytext(yyval.str);
                        if (A4GL_bad_identifiers(yyval.str)) {
                                a4gl_yyerror("You can't use this identifier as it is a reserved word in the target language");
                        }
}
    break;

  case 188:
#line 1790 "fgl.yacc"
    { add_constant('c',yyvsp[0].str,yyvsp[-2].str); addmap("Constant",yyvsp[-2].str,curr_func,yylineno,infilename); }
    break;

  case 189:
#line 1791 "fgl.yacc"
    { add_constant('C',yyvsp[0].str,yyvsp[-2].str); addmap("Constant",yyvsp[-2].str,curr_func,yylineno,infilename); }
    break;

  case 190:
#line 1792 "fgl.yacc"
    { add_constant('f',yyvsp[0].str,yyvsp[-2].str);
addmap("Constant",yyvsp[-2].str,curr_func,yylineno,infilename);
 }
    break;

  case 191:
#line 1795 "fgl.yacc"
    { 
add_constant('i',yyvsp[0].str,yyvsp[-2].str);
addmap("Constant",yyvsp[-2].str,curr_func,yylineno,infilename);
 }
    break;

  case 193:
#line 1800 "fgl.yacc"
    { }
    break;

  case 194:
#line 1800 "fgl.yacc"
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

  case 198:
#line 1817 "fgl.yacc"
    {
		sprintf(yyval.str,"-%p",yyvsp[0].str);}
    break;

  case 199:
#line 1821 "fgl.yacc"
    {
/*AF CygWin FIX */
push_name(yyval.str,0);
addmap("Define",yyvsp[0].str,curr_func,yylineno,infilename);
}
    break;

  case 204:
#line 1836 "fgl.yacc"
    {strcpy(yyval.str,"-1");}
    break;

  case 205:
#line 1837 "fgl.yacc"
    {strcpy(yyval.str,"-1");}
    break;

  case 206:
#line 1838 "fgl.yacc"
    {strcpy(yyval.str,"-2");}
    break;

  case 207:
#line 1839 "fgl.yacc"
    {strcpy(yyval.str,"-3");}
    break;

  case 208:
#line 1844 "fgl.yacc"
    {
 A4GL_debug("defines array %s",yyvsp[-1].str);
	push_type(0,0,yyvsp[-1].str);
}
    break;

  case 210:
#line 1850 "fgl.yacc"
    {
 A4GL_debug("defines array %s",yyvsp[0].str);
	push_type(0,0,yyvsp[0].str);
}
    break;

  case 212:
#line 1859 "fgl.yacc"
    {
	push_associate(yyvsp[-5].str,yyvsp[-1].str);
	push_type(0,0,yyvsp[-1].str);
}
    break;

  case 213:
#line 1863 "fgl.yacc"
    {
    /* void pop_associate (char *a); */
	pop_associate(0);

}
    break;

  case 219:
#line 1879 "fgl.yacc"
    {sprintf(yyval.str,"%s][%s][%s",yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str); A4GL_debug("Triplet");}
    break;

  case 220:
#line 1881 "fgl.yacc"
    {sprintf(yyval.str,"%s][%s",yyvsp[-2].str,yyvsp[0].str); A4GL_debug("double");}
    break;

  case 221:
#line 1882 "fgl.yacc"
    {A4GL_debug("Single");}
    break;

  case 223:
#line 1889 "fgl.yacc"
    {push_record();in_record++;}
    break;

  case 224:
#line 1889 "fgl.yacc"
    {pop_record();in_record--;}
    break;

  case 225:
#line 1890 "fgl.yacc"
    {in_record++;push_record();A4GL_debug("Like\n");}
    break;

  case 226:
#line 1891 "fgl.yacc"
    {A4GL_debug("Link Table : %s\n",yyvsp[-2].str);
                  push_rectab(yyvsp[-2].str);
                  pop_record();in_record--;}
    break;

  case 227:
#line 1894 "fgl.yacc"
    {
		push_record();A4GL_debug("Like\n");}
    break;

  case 228:
#line 1896 "fgl.yacc"
    {
		  A4GL_debug("Table:%s\n",yyvsp[-4].str);
		  add_link_to(yyvsp[-4].str,yyvsp[-1].str);
	          A4GL_debug("Push record...\n");
                  push_rectab(yyvsp[-4].str);
                  pop_record();
}
    break;

  case 230:
#line 1906 "fgl.yacc"
    {
	sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 235:
#line 1921 "fgl.yacc"
    {start_state("dtype",1);}
    break;

  case 236:
#line 1921 "fgl.yacc"
    {start_state("dtype",0);}
    break;

  case 240:
#line 1927 "fgl.yacc"
    {push_type("char","1",0);}
    break;

  case 241:
#line 1928 "fgl.yacc"
    {
/* char buff[80]; */
if (atoi(yyvsp[-1].str)==4) {
	addmap("size=4","----",curr_func,yylineno,infilename);
}
push_type("char",yyvsp[-1].str,0);
}
    break;

  case 242:
#line 1935 "fgl.yacc"
    {push_type("char",yyvsp[-1].str,0);}
    break;

  case 243:
#line 1936 "fgl.yacc"
    {push_type("char",yyvsp[-3].str,0);}
    break;

  case 244:
#line 1937 "fgl.yacc"
    {push_type("long",0,0);}
    break;

  case 245:
#line 1938 "fgl.yacc"
    {
A4GL_debug("Using specified type...");
push_dim(yyvsp[0].str);}
    break;

  case 246:
#line 1941 "fgl.yacc"
    {push_type("int",0,0);}
    break;

  case 247:
#line 1942 "fgl.yacc"
    {push_type("form",0,0);}
    break;

  case 248:
#line 1943 "fgl.yacc"
    {push_type("form",0,0);}
    break;

  case 249:
#line 1944 "fgl.yacc"
    { char buff[256];
				sprintf(buff,"%d",16*256+2);
				push_type("fgldecimal",buff,0);
				}
    break;

  case 250:
#line 1948 "fgl.yacc"
    {
				char buff[256];
				sprintf(buff,"%d",atoi(yyvsp[-1].str)*256+2);
				push_type("fgldecimal",buff,0);
}
    break;

  case 251:
#line 1953 "fgl.yacc"
    {
char buff[256];
sprintf(buff,"%d",atoi(yyvsp[-3].str)*256+atoi(yyvsp[-1].str));
push_type("fgldecimal",buff,0);
}
    break;

  case 252:
#line 1958 "fgl.yacc"
    {
			char buff[256];
			sprintf(buff,"%d",16*256+2);
			push_type("fglmoney",buff,0);}
    break;

  case 253:
#line 1962 "fgl.yacc"
    {
		char buff[256];sprintf(buff,"%d",atoi(yyvsp[-1].str)*256+2);
			push_type("fglmoney",buff,0);}
    break;

  case 254:
#line 1965 "fgl.yacc"
    {
char buff[256];
sprintf(buff,"%d",atoi(yyvsp[-3].str)*256+atoi(yyvsp[-1].str));
push_type("fglmoney",buff,0);}
    break;

  case 255:
#line 1969 "fgl.yacc"
    {push_type("double",0,0);}
    break;

  case 256:
#line 1970 "fgl.yacc"
    {push_type("float",0,0);}
    break;

  case 257:
#line 1971 "fgl.yacc"
    {push_type("fgldate",0,0);}
    break;

  case 258:
#line 1972 "fgl.yacc"
    {push_type("fglbyte",0,0);}
    break;

  case 259:
#line 1973 "fgl.yacc"
    {push_type("fglbyte",0,0);}
    break;

  case 260:
#line 1974 "fgl.yacc"
    {push_type("fgltext",0,0);}
    break;

  case 261:
#line 1975 "fgl.yacc"
    {push_type("fgltext",0,0);}
    break;

  case 262:
#line 1976 "fgl.yacc"
    {
push_type("struct_dtime",yyvsp[0].str,0);
}
    break;

  case 263:
#line 1979 "fgl.yacc"
    {push_type("struct_ival",yyvsp[0].str,0);}
    break;

  case 264:
#line 1980 "fgl.yacc"
    {push_like(yyvsp[0].str);A4GL_lex_printcomment("/*added(XXXXX)\n */");}
    break;

  case 265:
#line 1981 "fgl.yacc"
    {
			char buff[256];
			strcpy(buff,yyvsp[0].str);
		 A4GL_debug("Got a rogue datatype");

			if (A4GL_find_datatype(upshift(buff))) 
			{
				char *(*function) (void);
			 A4GL_debug("Checking ...");
				function=A4GL_get_datatype_function_n(upshift(buff),"OUTPUT");
			 A4GL_debug("Got function as %p",function);

                /*  warning: comparison between pointer and integer */
				if ((int)function != -1 && (int)function != 0)
				{
				 A4GL_debug("call returns %s\n",function());
					strcpy(buff,function());
				 A4GL_debug("Set up buff as %s");
					push_type(function(),0,0);
				 A4GL_debug("Pushed type : %s\n",function());
				}
			} else {
				/* yyerror("Unknown datatype : %s",$<str>1); */
                a4gl_yyerror("Unknown datatype.");
			}
		}
    break;

  case 266:
#line 2013 "fgl.yacc"
    {
A4GL_lex_printcomment("/*column like(ZZZ)\n*/"); sprintf(yyval.str,"%s.%s",yyvsp[-2].str,yyvsp[0].str); A4GL_lex_printcomment ("/*set col...(ZZZ)\n*/");}
    break;

  case 267:
#line 2017 "fgl.yacc"
    {A4GL_debug("--->%s\n",yyvsp[0].str);strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 268:
#line 2019 "fgl.yacc"
    {A4GL_debug("--->%s\n",yyvsp[0].str);strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 269:
#line 2021 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 270:
#line 2023 "fgl.yacc"
    {
A4GL_debug("Real datetime %s to %s\n",yyvsp[-2].str,yyvsp[0].str);
sprintf(yyval.str,"%d",(atoi(yyvsp[-2].str)*16)+atoi(yyvsp[0].str)); }
    break;

  case 271:
#line 2028 "fgl.yacc"
    {
	sprintf(yyval.str,"%d",(atoi(yyvsp[-2].str)*16)+atoi(yyvsp[0].str)); 
}
    break;

  case 272:
#line 2032 "fgl.yacc"
    {start_state("dtime_val",1);}
    break;

  case 273:
#line 2032 "fgl.yacc"
    {start_state("dtime_val",0); strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 274:
#line 2036 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 275:
#line 2037 "fgl.yacc"
    {strcpy(yyval.str,"2");}
    break;

  case 276:
#line 2038 "fgl.yacc"
    {strcpy(yyval.str,"3");}
    break;

  case 277:
#line 2039 "fgl.yacc"
    {strcpy(yyval.str,"4");}
    break;

  case 278:
#line 2040 "fgl.yacc"
    {strcpy(yyval.str,"5");}
    break;

  case 279:
#line 2041 "fgl.yacc"
    {strcpy(yyval.str,"6");}
    break;

  case 280:
#line 2043 "fgl.yacc"
    {
A4GL_debug("opt_frac returns %s",yyvsp[0].str);
sprintf(yyval.str,"%d",atoi(yyvsp[0].str)+6); }
    break;

  case 281:
#line 2048 "fgl.yacc"
    {start_state("dtime_val",1);}
    break;

  case 282:
#line 2048 "fgl.yacc"
    { A4GL_debug ("Got end");start_state("dtime_val",0);  strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 283:
#line 2051 "fgl.yacc"
    {
A4GL_debug("Nothing in fraction - assume 2");
strcpy(yyval.str,"2");}
    break;

  case 284:
#line 2053 "fgl.yacc"
    {
A4GL_debug("Read fraction .. ");
A4GL_debug("    %s",yyvsp[-1].str);
strcpy(yyval.str,yyvsp[-1].str);
}
    break;

  case 285:
#line 2059 "fgl.yacc"
    {
A4GL_debug("Nothing in fraction - assume 2");
strcpy(yyval.str,"2");}
    break;

  case 286:
#line 2061 "fgl.yacc"
    {
A4GL_debug("    %s",yyvsp[-1].str);
strcpy(yyval.str,yyvsp[-1].str);
}
    break;

  case 287:
#line 2067 "fgl.yacc"
    {
if (atoi(yyvsp[0].str)>5) {
a4gl_yyerror("Fraction values are between 0 and 5");
YYERROR;
}
}
    break;

  case 288:
#line 2075 "fgl.yacc"
    {start_state("interval_val",1);}
    break;

  case 289:
#line 2075 "fgl.yacc"
    {start_state("interval_val",0); sprintf(yyval.str,"%d",atoi(yyvsp[0].str)*16+atoi(yyvsp[-1].str));}
    break;

  case 290:
#line 2078 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 291:
#line 2079 "fgl.yacc"
    {strcpy(yyval.str,"2");}
    break;

  case 292:
#line 2080 "fgl.yacc"
    {strcpy(yyval.str,"3");}
    break;

  case 293:
#line 2081 "fgl.yacc"
    {strcpy(yyval.str,"4");}
    break;

  case 294:
#line 2082 "fgl.yacc"
    {strcpy(yyval.str,"5");}
    break;

  case 295:
#line 2083 "fgl.yacc"
    {strcpy(yyval.str,"6");}
    break;

  case 296:
#line 2085 "fgl.yacc"
    {
A4GL_debug("opt_frac returns %s",yyvsp[0].str);
sprintf(yyval.str,"%d",atoi(yyvsp[0].str)+6); }
    break;

  case 300:
#line 2106 "fgl.yacc"
    {
              	dim_set_name(yyvsp[0].str);
              }
    break;

  case 304:
#line 2115 "fgl.yacc"
    {dim_push_type("char","1",0);}
    break;

  case 305:
#line 2117 "fgl.yacc"
    {dim_push_type("char",yyvsp[-1].str,0);}
    break;

  case 306:
#line 2119 "fgl.yacc"
    {dim_push_type("char",yyvsp[-1].str,0);}
    break;

  case 307:
#line 2121 "fgl.yacc"
    {dim_push_type("char",yyvsp[-3].str,0);}
    break;

  case 308:
#line 2122 "fgl.yacc"
    {dim_push_type("long",0,0);}
    break;

  case 309:
#line 2123 "fgl.yacc"
    {dim_push_type("integer",0,0);}
    break;

  case 310:
#line 2124 "fgl.yacc"
    {dim_push_type("FORM",0,0);}
    break;

  case 311:
#line 2125 "fgl.yacc"
    {
char buff[256];
sprintf(buff,"%d",16*256+2);
dim_push_type("fgldecimal",buff,0);
}
    break;

  case 312:
#line 2130 "fgl.yacc"
    {

char buff[256];
sprintf(buff,"%d",atoi(yyvsp[-1].str)*256+2);
dim_push_type("fgldecimal",buff,0);
}
    break;

  case 313:
#line 2137 "fgl.yacc"
    {
char buff[256];
sprintf(buff,"%d",atoi(yyvsp[-3].str)*256+atoi(yyvsp[-1].str));
dim_push_type("fgldecimal",buff,0);
}
    break;

  case 314:
#line 2142 "fgl.yacc"
    {dim_push_type("fglmoney",0,0);}
    break;

  case 315:
#line 2144 "fgl.yacc"
    {dim_push_type("fglmoney",0,0);}
    break;

  case 316:
#line 2146 "fgl.yacc"
    {dim_push_type("fglmoney",0,0);}
    break;

  case 317:
#line 2147 "fgl.yacc"
    {dim_push_type("double",0,0);}
    break;

  case 318:
#line 2148 "fgl.yacc"
    {dim_push_type("float",0,0);}
    break;

  case 319:
#line 2149 "fgl.yacc"
    {dim_push_type("fgldate",0,0);}
    break;

  case 320:
#line 2150 "fgl.yacc"
    {dim_push_type("fglbyte",0,0);}
    break;

  case 321:
#line 2151 "fgl.yacc"
    {dim_push_type("fgltext",0,0);}
    break;

  case 322:
#line 2152 "fgl.yacc"
    {
dim_push_type("struct_dtime",yyvsp[0].str,0);
}
    break;

  case 323:
#line 2155 "fgl.yacc"
    {dim_push_type("struct_ival",0,0);}
    break;

  case 324:
#line 2157 "fgl.yacc"
    {dim_push_like(yyvsp[0].str);A4GL_lex_printcomment("/*added(XXXXX)\n */");}
    break;

  case 325:
#line 2163 "fgl.yacc"
    {
A4GL_lex_printcomment("/*column like(ZZZ)\n*/");
sprintf(yyval.str,"%s.%s",yyvsp[-2].str,yyvsp[0].str)
; A4GL_lex_printcomment ("/*set col...(ZZZ)\n*/");}
    break;

  case 326:
#line 2171 "fgl.yacc"
    {
dim_push_type(0,0,yyvsp[-1].str);
}
    break;

  case 328:
#line 2179 "fgl.yacc"
    {
dim_push_associate(yyvsp[-5].str,yyvsp[-1].str);
dim_push_type(0,0,yyvsp[-1].str);
}
    break;

  case 329:
#line 2183 "fgl.yacc"
    {
	/* void dim_pop_associate (char *a); */
	dim_pop_associate(0);
}
    break;

  case 330:
#line 2191 "fgl.yacc"
    {dim_push_record();}
    break;

  case 331:
#line 2192 "fgl.yacc"
    {dim_pop_record();}
    break;

  case 332:
#line 2193 "fgl.yacc"
    {dim_push_record();A4GL_debug("Like\n");}
    break;

  case 333:
#line 2194 "fgl.yacc"
    {A4GL_debug("Table:%s\n",yyvsp[-2].str);
                                  dim_push_rectab(yyvsp[-2].str);
                                  dim_pop_record();}
    break;

  case 339:
#line 2213 "fgl.yacc"
    { dim_push_name(yyval.str,0); }
    break;

  case 340:
#line 2225 "fgl.yacc"
    {
	print_display_line();
		strcpy(yyval.str,A4GL_get_display_str(0,0,0));
	}
    break;

  case 341:
#line 2229 "fgl.yacc"
    {
		strcpy(yyval.str,A4GL_get_display_str(1,0,0)); /* FIXME */
	}
    break;

  case 342:
#line 2232 "fgl.yacc"
    { 
	strcpy(yyval.str,"#error not implemented yet");
	}
    break;

  case 343:
#line 2235 "fgl.yacc"
    { strcpy(yyval.str, A4GL_get_display_str(4,0,0)); }
    break;

  case 344:
#line 2236 "fgl.yacc"
    { strcpy(yyval.str, A4GL_get_display_str(2,field_name_list_as_char(yyvsp[0].field_list),0)); }
    break;

  case 345:
#line 2237 "fgl.yacc"
    { strcpy(yyval.str, A4GL_get_display_str(3,field_name_list_as_char(yyvsp[0].field_list),yyvsp[-2].str)); }
    break;

  case 346:
#line 2238 "fgl.yacc"
    { strcpy(yyval.str, A4GL_get_display_str(5,yyvsp[-1].str,0)); }
    break;

  case 347:
#line 2239 "fgl.yacc"
    { 
	strcpy(yyval.str,"#error not implemented yet");
 }
    break;

  case 348:
#line 2245 "fgl.yacc"
    {
		print_display_by_name(yyvsp[0].str);
                }
    break;

  case 349:
#line 2252 "fgl.yacc"
    { 
				print_display(yyvsp[-1].str,yyvsp[-2].str,yyvsp[0].str);
		}
    break;

  case 350:
#line 2257 "fgl.yacc"
    {
		print_display_form(yyvsp[-1].str,yyvsp[0].str);
	}
    break;

  case 351:
#line 2262 "fgl.yacc"
    {
		push_blockcommand("DISPLAY");
		curr_input_array_attribs.curr_row_display=0;
		}
    break;

  case 352:
#line 2267 "fgl.yacc"
    {
		print_display_array_p1(fgl_add_scope(yyvsp[-6].str,0),yyvsp[-4].str,yyvsp[-1].str,yyvsp[0].str,&curr_input_array_attribs);
	  	A4GL_new_events();
		}
    break;

  case 353:
#line 2271 "fgl.yacc"
    {
		add_continue_blockcommand ("DISPLAY");  
		print_display_array_p2();
		pop_blockcommand("DISPLAY");
	  	A4GL_drop_events();
}
    break;

  case 354:
#line 2280 "fgl.yacc"
    {
strcpy(yyval.str,"0,0");
}
    break;

  case 355:
#line 2282 "fgl.yacc"
    {
	strcpy(yyval.str,field_name_as_char(yyvsp[0].field_entry));
}
    break;

  case 356:
#line 2287 "fgl.yacc"
    {
				sprintf(yyval.str,"0x%lx",atol(yyvsp[0].str));
			}
    break;

  case 362:
#line 2299 "fgl.yacc"
    {
		A4GL_add_event(-11,"");
		print_befaft_field_1("AFT_ROW");
		}
    break;

  case 363:
#line 2303 "fgl.yacc"
    {
		print_befaft_field_2();
	}
    break;

  case 364:
#line 2306 "fgl.yacc"
    {
		A4GL_add_event(-10,"");
		print_befaft_field_1("BEF_ROW");
		}
    break;

  case 365:
#line 2310 "fgl.yacc"
    {
		print_befaft_field_2();
	}
    break;

  case 366:
#line 2313 "fgl.yacc"
    {
		A4GL_add_onkey_key(yyvsp[0].str);
		print_onkey_1(yyvsp[0].str);
		}
    break;

  case 367:
#line 2317 "fgl.yacc"
    {
		print_onkey_2();
	}
    break;

  case 368:
#line 2324 "fgl.yacc"
    {
		char buff[256];
		char *s;
		strcpy(buff,yyvsp[0].str);
		s=strchr(buff,'[');
		if (!s) {
			a4gl_yyerror("Expecting an array and size");
			YYERROR;
		}
		*s=0;
		s++;

		print_alloc_arr(buff,s);
	}
    break;

  case 369:
#line 2342 "fgl.yacc"
    {
		print_dealloc_arr(yyvsp[0].str);
	}
    break;

  case 370:
#line 2348 "fgl.yacc"
    {
		char buff[256];
		char *s;
		strcpy(buff,yyvsp[0].str);
		s=strchr(buff,'[');
		if (!s) {
			a4gl_yyerror("Expecting an array and size");
			YYERROR;
		}
		*s=0;
		s++;

		print_realloc_arr(buff,s);
	}
    break;

  case 371:
#line 2372 "fgl.yacc"
    {
			print_error(yyvsp[0].str,0);
		}
    break;

  case 372:
#line 2375 "fgl.yacc"
    { 
			print_error(yyvsp[-1].str,1);
	}
    break;

  case 373:
#line 2390 "fgl.yacc"
    { if (in_command("WHILE")) { exit_loop("WHILE"); } else { YYERROR;} }
    break;

  case 374:
#line 2392 "fgl.yacc"
    { if (in_command("INPUT")) { exit_loop("INPUT"); } else { YYERROR;} }
    break;

  case 375:
#line 2394 "fgl.yacc"
    { if (in_command("FOREACH")) { exit_loop("FOREACH"); } else { YYERROR;} }
    break;

  case 376:
#line 2396 "fgl.yacc"
    { if (in_command("FOR")) { exit_loop("FOR"); } else { YYERROR;} }
    break;

  case 377:
#line 2398 "fgl.yacc"
    { if (in_command("CONSTRUCT")) { exit_loop("CONSTRUCT"); } else { YYERROR;} }
    break;

  case 378:
#line 2400 "fgl.yacc"
    { if (in_command("DISPLAY")) { exit_loop("DISPLAY"); } else { YYERROR;} }
    break;

  case 379:
#line 2401 "fgl.yacc"
    {
	if (in_command("MENU")) {
		exit_loop("MENU");
		/* A4GL_lex_printc("cmd_no=-3;continue;\n"); */
	} 
              else YYERROR;}
    break;

  case 380:
#line 2408 "fgl.yacc"
    { if (in_command("CASE")) { exit_loop("CASE"); } else { YYERROR;} }
    break;

  case 381:
#line 2410 "fgl.yacc"
    { if (in_command("PROMPT")) { exit_loop("PROMPT"); } else { YYERROR;} }
    break;

  case 382:
#line 2414 "fgl.yacc"
    { if (in_command("WHILE")) { continue_loop("WHILE");  } else { YYERROR;} }
    break;

  case 383:
#line 2416 "fgl.yacc"
    { if (in_command("INPUT")) { continue_loop("INPUT"); } else { YYERROR;} }
    break;

  case 384:
#line 2418 "fgl.yacc"
    { if (in_command("FOREACH")) { continue_loop("FOREACH");} else { YYERROR;} }
    break;

  case 385:
#line 2420 "fgl.yacc"
    { if (in_command("FOR")) { continue_loop("FOR"); } else { YYERROR;} }
    break;

  case 386:
#line 2422 "fgl.yacc"
    { if (in_command("CONSTRUCT")) { continue_loop("CONSTRUCT"); } else { YYERROR;} }
    break;

  case 387:
#line 2424 "fgl.yacc"
    { if (in_command("DISPLAY")) { continue_loop("DISPLAY"); } else { YYERROR;} }
    break;

  case 388:
#line 2426 "fgl.yacc"
    { if (in_command("MENU")) {  continue_loop("MENU");  } else { YYERROR;} }
    break;

  case 389:
#line 2432 "fgl.yacc"
    { if (in_command("PROMPT")) { continue_loop("PROMPT"); } else { YYERROR;} }
    break;

  case 390:
#line 2446 "fgl.yacc"
    {
	print_exit_program(0);
}
    break;

  case 391:
#line 2449 "fgl.yacc"
    {
	print_exit_program(1);
}
    break;

  case 396:
#line 2466 "fgl.yacc"
    {
	dec_counter();
	yyval.ptr=A4GL_append_expr_expr(yyvsp[-1].ptr,yyvsp[0].ptr);
}
    break;

  case 399:
#line 2472 "fgl.yacc"
    {
	A4GL_debug("Got literal ptr=%p",yyvsp[0].ptr);
}
    break;

  case 400:
#line 2476 "fgl.yacc"
    {
	yyval.ptr=A4GL_new_expr("A4GL_push_int(0);");
	yyval.ptr=A4GL_append_expr_expr(yyval.ptr,yyvsp[0].ptr);
	yyval.ptr=A4GL_append_expr(yyval.ptr,"A4GL_pushop(OP_SUB);");
}
    break;

  case 401:
#line 2481 "fgl.yacc"
    {
	yyval.ptr=yyvsp[0].ptr;
}
    break;

  case 405:
#line 2491 "fgl.yacc"
    { yyval.ptr=A4GL_new_expr("A4GL_add_spaces();"); }
    break;

  case 406:
#line 2492 "fgl.yacc"
    {inc_counter();}
    break;

  case 412:
#line 2498 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_CONCAT);");
}
    break;

  case 413:
#line 2505 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 414:
#line 2505 "fgl.yacc"
    {
strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 416:
#line 2510 "fgl.yacc"
    {yyval.ptr=A4GL_new_expr("A4GL_push_null(2,0)");}
    break;

  case 417:
#line 2514 "fgl.yacc"
    {
	/*set_counter(0);*/
	sprintf(yyval.str,"%d",get_counter_val());
	A4GL_lex_printcomment("/*L1 %s*/\n",yyval.str);
}
    break;

  case 418:
#line 2520 "fgl.yacc"
    {
	sprintf(yyval.str,"%d",get_counter_val());
	A4GL_lex_printcomment("/*L2 %s*/\n",yyval.str);
}
    break;

  case 419:
#line 2528 "fgl.yacc"
    {
	/*set_counter(0);*/
	sprintf(yyval.str,"%d",get_counter_val());
	A4GL_lex_printcomment("/*L1 %s*/\n",yyval.str);
}
    break;

  case 420:
#line 2534 "fgl.yacc"
    {
	sprintf(yyval.str,"%d",get_counter_val());
	A4GL_lex_printcomment("/*L2 %s*/\n",yyval.str);
}
    break;

  case 421:
#line 2543 "fgl.yacc"
    {sprintf(yyval.str,"%d",get_counter_val());}
    break;

  case 422:
#line 2545 "fgl.yacc"
    {
	print_op("OP_CONCAT");
	dec_counter();sprintf(yyval.str,"%d",get_counter_val());
}
    break;

  case 423:
#line 2552 "fgl.yacc"
    {
	A4GL_debug("Print expr (2)");
	print_expr(yyvsp[0].ptr);
}
    break;

  case 424:
#line 2560 "fgl.yacc"
    {
	strcpy(yyval.str,"+");
}
    break;

  case 425:
#line 2564 "fgl.yacc"
    {
	strcpy(yyval.str,"-");
}
    break;

  case 426:
#line 2573 "fgl.yacc"
    {
	
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_NOT);");
}
    break;

  case 427:
#line 2578 "fgl.yacc"
    {
	yyval.ptr=A4GL_new_expr("A4GL_push_int(1);");
        inc_counter();
}
    break;

  case 428:
#line 2583 "fgl.yacc"
    {
	inc_counter();
	yyval.ptr=A4GL_new_expr("A4GL_push_int(0);");
}
    break;

  case 429:
#line 2587 "fgl.yacc"
    { yyval.ptr=yyvsp[-1].ptr; }
    break;

  case 430:
#line 2589 "fgl.yacc"
    {
	yyval.ptr=get_in_exists_sql(yyvsp[-1].sql_string,'E');
}
    break;

  case 431:
#line 2592 "fgl.yacc"
    {
	yyval.ptr=get_in_exists_sql(yyvsp[-1].sql_string,'e');
}
    break;

  case 432:
#line 2599 "fgl.yacc"
    {
	A4GL_debug("init expr %s %s",yyvsp[-1].str,yyvsp[0].str);
	sprintf(yyval.str,"%s%p",yyvsp[-1].str,yyvsp[0].str);
	sprintf(yyval.str,"%s",A4GL_get_push_literal('D',yyval.str));
	yyval.ptr=A4GL_new_expr(yyval.str);
        inc_counter();
}
    break;

  case 433:
#line 2607 "fgl.yacc"
    {
	A4GL_debug("init expr int %s %d",yyvsp[-1].str,atoi(yyvsp[0].str));
	sprintf(yyval.str,"%s%p",yyvsp[-1].str,yyvsp[0].str);
	sprintf(yyval.str,"%s",A4GL_get_push_literal('L',yyval.str));
	yyval.ptr=A4GL_new_expr(yyval.str);
	inc_counter();
}
    break;

  case 434:
#line 2619 "fgl.yacc"
    {
	sprintf(yyval.str,"%s",A4GL_get_push_literal('S',yyvsp[0].str));
	yyval.ptr=A4GL_new_expr(yyval.str);
	inc_counter();
}
    break;

  case 435:
#line 2625 "fgl.yacc"
    {
	sprintf(yyval.str,"%s",A4GL_get_push_literal('D',yyvsp[0].str));
	yyval.ptr=A4GL_new_expr(yyval.str);
	inc_counter();
}
    break;

  case 436:
#line 2631 "fgl.yacc"
    {
	sprintf(yyval.str,"%s",A4GL_get_push_literal('L',yyvsp[0].str));
	yyval.ptr=A4GL_new_expr(yyval.str);
	inc_counter();
}
    break;

  case 439:
#line 2641 "fgl.yacc"
    {
		sprintf(yyval.str,"%s\n%s",yyvsp[-2].str,yyvsp[0].str);
	}
    break;

  case 440:
#line 2647 "fgl.yacc"
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
          		if (A4GL_aubit_strcasecmp(yyvsp[0].str,"today")==0) {
               		flg=1;
               		strcpy(yyval.str,"A4GL_push_today();");
          		}
		
          		if (A4GL_aubit_strcasecmp(yyvsp[0].str,"time")==0) {
               		flg=1;
               		strcpy(yyval.str,"A4GL_push_time();");
          		}
		
          		if (A4GL_aubit_strcasecmp(yyvsp[0].str,"pageno")==0) {
               		flg=1;
               		strcpy(yyval.str,"A4GL_push_variable(&rep.page_no,2);");
                  		}
          		if (A4GL_aubit_strcasecmp(yyvsp[0].str,"lineno")==0) {
               		flg=1;
               		strcpy(yyval.str,"A4GL_push_variable(&rep.line_no,2);");
          		}

         		if (flg==0) {
         				sprintf(yyval.str,"A4GL_push_variable(&%s,0x%x);",yyvsp[0].str,(int)scan_variable(yyvsp[0].str));
         		}
      			p1=A4GL_new_expr(yyval.str);
       			yyval.ptr=p1;
			inc_counter();
   		}



        	if (a==-1)
        	{
                	sprintf(yyval.str,"A4GL_push_char(%s);",yyvsp[0].str);inc_counter();
      			p1=A4GL_new_expr(yyval.str);
       			yyval.ptr=p1;
			inc_counter();
        	}


        	if (a==-2)
        	{
			p1=A4GL_new_expr("");
	        	incvcnt=print_push_rec(yyvsp[0].str,&p1);
	        	inc_counter_by(incvcnt);
			yyval.ptr=p1;
        	}




	}
    break;

  case 441:
#line 2719 "fgl.yacc"
    {
	sprintf(yyval.str,"A4GL_%sset_column(&rep);",ispdf());
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,yyval.str);
}
    break;

  case 442:
#line 2725 "fgl.yacc"
    {
sprintf(yyval.str,"A4GL_%sset_column(&rep);",ispdf());
yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,yyval.str);
}
    break;

  case 443:
#line 2729 "fgl.yacc"
    {
   if (!isin_command("REPORT")) {
   a4gl_yyerror("This can only be done in a report!");
   YYERROR;
} 
insql=0;
	yyval.ptr=A4GL_new_expr(yyvsp[0].str);
}
    break;

  case 444:
#line 2737 "fgl.yacc"
    {insql=1;set_ingroup();}
    break;

  case 445:
#line 2737 "fgl.yacc"
    {
	char buff[256];
      if (!isin_command("REPORT")) {
        a4gl_yyerror("This can only be done in a report!");YYERROR;
      } insql=0; 
	A4GL_lex_printcomment("/* rep_Agg = %s\n*/",yyvsp[0].str);
        strcpy(buff,yyvsp[0].str);
	A4GL_debug("report aggregate :  %s",buff);
	yyval.ptr=A4GL_new_expr(buff);
      }
    break;

  case 446:
#line 2753 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_AND);");
}
    break;

  case 447:
#line 2757 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_OR);");
}
    break;

  case 448:
#line 2763 "fgl.yacc"
    {
	yyval.ptr=yyvsp[0].ptr;
	}
    break;

  case 449:
#line 2766 "fgl.yacc"
    {
		A4GL_debug("Adding to list...");
		yyval.ptr=A4GL_append_expr_expr(yyvsp[-2].ptr,yyvsp[0].ptr);
	}
    break;

  case 450:
#line 2774 "fgl.yacc"
    {
	yyval.ptr=get_in_exists_sql(yyvsp[-1].sql_string,'I');
}
    break;

  case 451:
#line 2778 "fgl.yacc"
    {
	yyval.ptr=get_in_exists_sql(yyvsp[-1].sql_string,'i');
}
    break;

  case 452:
#line 2781 "fgl.yacc"
    {
	char buff[256];
	sprintf(buff,"A4GL_push_int(%d);",length_expr(yyvsp[-1].ptr));
	yyval.ptr=A4GL_append_expr(yyvsp[-1].ptr,buff);
	A4GL_append_expr(yyval.ptr,"A4GL_pushop(OP_IN);");
}
    break;

  case 453:
#line 2787 "fgl.yacc"
    {
	char buff[256];
	sprintf(buff,"A4GL_push_int(%d);",length_expr(yyvsp[-1].ptr));
	yyval.ptr=A4GL_append_expr(yyvsp[-1].ptr,buff);
	A4GL_append_expr(yyval.ptr,"A4GL_pushop(OP_NOTIN);");
}
    break;

  case 454:
#line 2797 "fgl.yacc"
    { 
	strcpy(yyval.str,"A4GL_pushop(OP_ISNULL);");
	yyval.ptr=A4GL_new_expr(yyval.str);
}
    break;

  case 455:
#line 2802 "fgl.yacc"
    {
	strcpy(yyval.str,"A4GL_pushop(OP_ISNOTNULL);");
	yyval.ptr=A4GL_new_expr(yyval.str);
}
    break;

  case 456:
#line 2809 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_push_char(\"\\\\\");A4GL_pushop(OP_MATCHES);");
 }
    break;

  case 457:
#line 2812 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_push_char(\"\\\\\");A4GL_pushop(OP_MATCHES);A4GL_pushop(OP_NOT);");
}
    break;

  case 458:
#line 2815 "fgl.yacc"
    {
	char buff[40];
	sprintf(buff,"A4GL_push_char(%s);A4GL_pushop(OP_MATCHES);",yyvsp[0].str);
	yyval.ptr=A4GL_append_expr(yyvsp[-2].ptr,buff);
 }
    break;

  case 459:
#line 2820 "fgl.yacc"
    {
	char buff[40];
	sprintf(buff,"A4GL_push_char(%s);A4GL_pushop(OP_MATCHES);A4GL_pushop(OP_NOT);",yyvsp[0].str);
	yyval.ptr=A4GL_append_expr(yyvsp[-2].ptr,buff);
}
    break;

  case 460:
#line 2827 "fgl.yacc"
    {
	char buff[40];
	sprintf(buff,"A4GL_push_char(\"\\\\\");A4GL_pushop(OP_LIKE);");
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,buff);
}
    break;

  case 461:
#line 2832 "fgl.yacc"
    {
	char buff[40];
	sprintf(buff,"A4GL_push_char(\"\\\\\");A4GL_pushop(OP_LIKE);A4GL_pushop(OP_NOT);");
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,buff);
}
    break;

  case 462:
#line 2837 "fgl.yacc"
    {
	char buff[40];
	sprintf(buff,"A4GL_push_char(%s);A4GL_pushop(OP_LIKE);",yyvsp[0].str);
	yyval.ptr=A4GL_append_expr(yyvsp[-2].ptr,buff);
}
    break;

  case 463:
#line 2842 "fgl.yacc"
    {
	char buff[40];
	sprintf(buff,"A4GL_push_char(%s);A4GL_pushop(OP_LIKE);A4GL_pushop(OP_NOT);",yyvsp[0].str);
	yyval.ptr=A4GL_append_expr(yyvsp[-2].ptr,buff);
}
    break;

  case 464:
#line 2853 "fgl.yacc"
    {
	strcpy(yyval.str,"A4GL_pushop(OP_CLIP);");
	yyval.ptr=A4GL_new_expr(yyval.str);
	inc_counter();
}
    break;

  case 465:
#line 2861 "fgl.yacc"
    {
	sprintf(yyval.str,"%s A4GL_pushop(OP_USING);",yyvsp[0].str);
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_USING);");
}
    break;

  case 466:
#line 2869 "fgl.yacc"
    {
	A4GL_debug("PLUS in math_expr $<ptr>2 = %p",yyvsp[0].ptr);
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_ADD);");
}
    break;

  case 467:
#line 2874 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_SUB);");
}
    break;

  case 468:
#line 2878 "fgl.yacc"
    {
      sprintf(yyval.str,"%s A4GL_A4GL_pushop(OP_MULT);",yyvsp[0].str);
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_MULT);");
}
    break;

  case 469:
#line 2883 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_DIV);");
}
    break;

  case 470:
#line 2887 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_MOD);");
}
    break;

  case 471:
#line 2891 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_POWER);");
}
    break;

  case 472:
#line 2897 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_EQUAL);");
}
    break;

  case 473:
#line 2900 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_EQUAL);");
}
    break;

  case 474:
#line 2904 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_LESS_THAN);");
}
    break;

  case 475:
#line 2908 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_GREATER_THAN);");
}
    break;

  case 476:
#line 2912 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_NOT_EQUAL);");
}
    break;

  case 477:
#line 2916 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_LESS_THAN_EQ);");
}
    break;

  case 478:
#line 2920 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_GREATER_THAN_EQ);");
}
    break;

  case 479:
#line 2927 "fgl.yacc"
    {
	reset_counter();
}
    break;

  case 480:
#line 2937 "fgl.yacc"
    { 
		addmap("Call",yyvsp[-1].str,curr_func,yylineno,infilename);
		new_counter(); 
		}
    break;

  case 481:
#line 2942 "fgl.yacc"
    { 
		sprintf(yyval.str,"%d",get_counter_val()); 
		A4GL_lex_printcomment("/*function_call_expr2 %s*/\n",yyval.str);
		drop_counter(); 
		}
    break;

  case 482:
#line 2948 "fgl.yacc"
    {
		int cnt;
		cnt=1;
		A4GL_debug("Print expr (1)");
		/* print_expr($<ptr>4); */

		strcpy(yyval.str,A4GL_expr_for_call(yyvsp[-5].str,yyvsp[-1].str,lastlineno,infilename));
		yyval.ptr=A4GL_append_expr(yyvsp[-2].ptr,yyval.str);
		inc_counter();
		}
    break;

  case 483:
#line 2958 "fgl.yacc"
    {
        sprintf(yyval.str,"\"%s\",\"%s\"",yyvsp[-3].str,yyvsp[-1].str);
	A4GL_debug("NEWFORMAT : %s\n",yyval.str);
        A4GLSQL_set_status(0,0);
        new_counter();
}
    break;

  case 484:
#line 2963 "fgl.yacc"
    {
	sprintf(yyval.str,"%d",get_counter_val());  
	drop_counter();
}
    break;

  case 485:
#line 2966 "fgl.yacc"
    {
	char buff[256];
        char *ptr;
        strcpy(buff,yyvsp[-3].str);
        ptr=strchr(buff,',');
        *ptr=0;
        ptr++;
	sprintf(yyval.str,"{int _retvars;\n_retvars=A4GL_call_4gl_dll(%s,%s,%d); {\nif (_retvars!= 1 ) {A4GLSQL_set_status(-3001,0);A4GL_chk_err(%d,\"%s\");A4GL_pop_args(_retvars);A4GL_push_null(2,0);}\n}\n}\n", buff,ptr,atoi(yyvsp[-1].str), lastlineno,infilename);
	yyval.ptr=A4GL_append_expr(yyvsp[-2].ptr,yyval.str);
}
    break;

  case 486:
#line 2980 "fgl.yacc"
    {chk4var=1;}
    break;

  case 487:
#line 2980 "fgl.yacc"
    {chk4var=0;}
    break;

  case 488:
#line 2980 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[-2].ptr,"aclfgl_date(1);");
}
    break;

  case 489:
#line 2983 "fgl.yacc"
    {chk4var=1;}
    break;

  case 490:
#line 2983 "fgl.yacc"
    {chk4var=0;}
    break;

  case 491:
#line 2983 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[-2].ptr,"aclfgl_month(1);");
	/* consumes and replaces a fgl_expr_c - so we don't need to dec or inc_counter */
}
    break;

  case 492:
#line 2987 "fgl.yacc"
    {chk4var=1;}
    break;

  case 493:
#line 2987 "fgl.yacc"
    {chk4var=0;}
    break;

  case 494:
#line 2987 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[-2].ptr,"aclfgl_day(1);");
	/* consumes and replaces a fgl_expr_c - so we don't need to dec or inc_counter */
}
    break;

  case 495:
#line 2991 "fgl.yacc"
    {chk4var=1;}
    break;

  case 496:
#line 2991 "fgl.yacc"
    {chk4var=0;}
    break;

  case 497:
#line 2991 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[-2].ptr,"aclfgl_year(1);");
	/* consumes and replaces a fgl_expr_c - so we don't need to dec or inc_counter */
}
    break;

  case 498:
#line 2995 "fgl.yacc"
    {
	char buff[256];
	sprintf(buff,"acli_interval(%s,%s);",yyvsp[-2].str,yyvsp[0].str);
	yyval.ptr=A4GL_new_expr(buff);
	inc_counter();
}
    break;

  case 499:
#line 3001 "fgl.yacc"
    {
	char buff[256];
	sprintf(buff,"acli_datetime(%s,%s);",yyvsp[-2].str,yyvsp[0].str);
	yyval.ptr=A4GL_new_expr(buff);
	inc_counter();
}
    break;

  case 500:
#line 3007 "fgl.yacc"
    {
	char buff[256];
	sprintf(buff,"acli_datetime(\"%s\",%s);",yyvsp[-2].str,yyvsp[0].str);
	yyval.ptr=A4GL_new_expr(buff);
	inc_counter();
}
    break;

  case 501:
#line 3013 "fgl.yacc"
    {
	char buff[256];
	sprintf(buff,"acli_datetime(\"%s:%s\",%s);",yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str);
	yyval.ptr=A4GL_new_expr(buff);
	inc_counter();
}
    break;

  case 502:
#line 3019 "fgl.yacc"
    {
	char buff[256];
	sprintf(buff,"A4GL_isdynarr_allocated(&%s);",yyvsp[-1].str);
        yyval.ptr=A4GL_new_expr(buff);
        inc_counter();
}
    break;

  case 503:
#line 3025 "fgl.yacc"
    { 
        char buff[256];
        sprintf(buff,"A4GL_dynarr_extent(&%s,%d);",yyvsp[-3].str,atoi(yyvsp[-1].str));
        yyval.ptr=A4GL_new_expr(buff);
        inc_counter();
}
    break;

  case 504:
#line 3035 "fgl.yacc"
    {strcpy(yyval.str,"-1");}
    break;

  case 505:
#line 3036 "fgl.yacc"
    {sprintf(yyval.str,"%d",atoi(yyvsp[-2].str)*16+atoi(yyvsp[0].str));}
    break;

  case 508:
#line 3044 "fgl.yacc"
    {
	if (!isin_command("INPUT")&&!isin_command("CONSTRUCT")) { 
   		a4gl_yyerror("get_fldbuf can only be used in an input or construct");
   		YYERROR;
	}
sprintf(yyval.str,"{int _retvars;\n_retvars=A4GL_fgl_getfldbuf(_sio,_inp_io_type,%s,0,0);\nif (_retvars != 1 ) {A4GLSQL_set_status(-3001,0);A4GL_chk_err(%d,\"%s\");}\n}\n",
	field_name_list_as_char(yyvsp[-1].field_list), lastlineno,infilename); 
	yyval.ptr=A4GL_new_expr(yyval.str);	
	inc_counter();

}
    break;

  case 509:
#line 3055 "fgl.yacc"
    {sprintf(yyval.str,"A4GL_push_int(A4GL_fgl_fieldnametoid(\"\",%s));",field_name_as_char(yyvsp[-1].field_entry)); yyval.ptr=A4GL_new_expr(yyval.str); }
    break;

  case 510:
#line 3056 "fgl.yacc"
    {
sprintf(yyval.str,"A4GL_push_int(A4GL_fgl_fieldnametoid(\"\",%s));",field_name_as_char(yyvsp[-1].field_entry)); yyval.ptr=A4GL_new_expr(yyval.str); 
addmap("Get Field",field_name_as_char(yyvsp[-1].field_entry),curr_func,yylineno,infilename);
	inc_counter();
}
    break;

  case 511:
#line 3062 "fgl.yacc"
    {
/* Informix allows this outside of a input/construct... */
	if (isin_command("INPUT")&&!isin_command("CONSTRUCT")) { 
		sprintf(yyval.str,"A4GL_push_int(A4GL_fgl_infield(_sio,_inp_io_type,%s,0,0));",field_name_list_as_char(yyvsp[-1].field_list)); 
	} else {
		sprintf(yyval.str,"A4GL_push_int(A4GL_fgl_infield(0,0,%s,0,0));",field_name_list_as_char(yyvsp[-1].field_list)); 
	}
	yyval.ptr=A4GL_new_expr(yyval.str);
	inc_counter();
}
    break;

  case 512:
#line 3073 "fgl.yacc"
    { 
	if (!isin_command("INPUT")&&!isin_command("CONSTRUCT")) { 
   		a4gl_yyerror("field_touched can only be used in an input or construct");
   		YYERROR;
	}
	sprintf(yyval.str,"A4GL_push_int(A4GL_fgl_fieldtouched(_sio,_inp_io_type,%s,0,0));",field_name_list_as_char(yyvsp[-1].field_list)); 
	yyval.ptr=A4GL_new_expr(yyval.str);
	inc_counter();
}
    break;

  case 513:
#line 3083 "fgl.yacc"
    { 
	if (!isin_command("INPUT")&&!isin_command("CONSTRUCT")) { 
   		a4gl_yyerror("field_touched can only be used in an input or construct");
   		YYERROR;
	}
	sprintf(yyval.str,"A4GL_push_int(!A4GL_fgl_fieldtouched(_sio,_inp_io_type,%s,0,0));",field_name_list_as_char(yyvsp[-1].field_list)); 
	yyval.ptr=A4GL_new_expr(yyval.str);
	inc_counter();
}
    break;

  case 516:
#line 3096 "fgl.yacc"
    {
		inc_counter();
               sprintf(yyval.str,"A4GL_push_current(%s);",yyvsp[0].str);
		yyval.ptr=A4GL_new_expr(yyval.str);
          	}
    break;

  case 517:
#line 3101 "fgl.yacc"
    { inc_counter(); strcpy(yyval.str,"A4GL_push_today();");
		yyval.ptr=A4GL_new_expr(yyval.str);
		}
    break;

  case 518:
#line 3108 "fgl.yacc"
    { 
	yyval.ptr=A4GL_append_expr(yyvsp[-1].ptr,"A4GL_upshift_stk();");
}
    break;

  case 519:
#line 3112 "fgl.yacc"
    { 
	yyval.ptr=A4GL_append_expr(yyvsp[-1].ptr,"A4GL_downshift_stk();");
}
    break;

  case 520:
#line 3115 "fgl.yacc"
    { 
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_push_ascii();");
}
    break;

  case 521:
#line 3118 "fgl.yacc"
    { 
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"aclfgli_extend();"); }
    break;

  case 522:
#line 3124 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[-1].ptr,"A4GL_push_double(-1);A4GL_pushop(OP_MULT);");
}
    break;

  case 523:
#line 3127 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[-1].ptr,"A4GL_push_double(-28.3465);A4GL_pushop(OP_MULT);");
}
    break;

  case 524:
#line 3130 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[-1].ptr,"A4GL_push_double(-72.0);A4GL_pushop(OP_MULT);");
}
    break;

  case 525:
#line 3147 "fgl.yacc"
    {
	strcpy(yyval.str,yyvsp[0].str);
}
    break;

  case 526:
#line 3150 "fgl.yacc"
    {
	strcpy(yyval.str,yyvsp[0].str);
}
    break;

  case 527:
#line 3156 "fgl.yacc"
    {sprintf(yyval.str,"-%s",yyvsp[0].str);}
    break;

  case 528:
#line 3157 "fgl.yacc"
    {sprintf(yyval.str,"\"%s\"",yyvsp[0].str);}
    break;

  case 529:
#line 3158 "fgl.yacc"
    {sprintf(yyval.str,"\"%s\"",yyvsp[0].str);}
    break;

  case 531:
#line 3163 "fgl.yacc"
    {sprintf(yyval.str,"%s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 532:
#line 3164 "fgl.yacc"
    {sprintf(yyval.str,"%s %s:%s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 533:
#line 3165 "fgl.yacc"
    {sprintf(yyval.str,"%s %s:%s:%s",yyvsp[-5].str,yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 534:
#line 3166 "fgl.yacc"
    {sprintf(yyval.str,"%s %s:%s:%s",yyvsp[-5].str,yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 535:
#line 3168 "fgl.yacc"
    {sprintf(yyval.str,"%s:%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 536:
#line 3169 "fgl.yacc"
    {sprintf(yyval.str,"%s:%s:%s",yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 537:
#line 3170 "fgl.yacc"
    {sprintf(yyval.str,"%s:%s:%s",yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 538:
#line 3172 "fgl.yacc"
    {sprintf(yyval.str,"%s:%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 539:
#line 3173 "fgl.yacc"
    {sprintf(yyval.str,"%s",yyvsp[0].str);}
    break;

  case 541:
#line 3179 "fgl.yacc"
    {sprintf(yyval.str,"%s-%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 542:
#line 3183 "fgl.yacc"
    {
                        yyval.field_list=new_field_list();
                        yyval.field_list=append_field_to_list(yyval.field_list,yyvsp[0].field_entry);
		}
    break;

  case 543:
#line 3187 "fgl.yacc"
    {
                        yyval.field_list=append_field_to_list(yyvsp[-2].field_list,yyvsp[0].field_entry);


	sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);
	}
    break;

  case 544:
#line 3202 "fgl.yacc"
    {
print_for_start(yyvsp[-5].str);
push_blockcommand("FOR");
}
    break;

  case 545:
#line 3206 "fgl.yacc"
    {A4GL_debug("For_cmds\n");}
    break;

  case 546:
#line 3207 "fgl.yacc"
    {

pop_blockcommand("FOR");
print_for_end();
A4GL_lex_printcomment(" /*END FOR*/\n");}
    break;

  case 547:
#line 3214 "fgl.yacc"
    {
		print_for_default_step();
	}
    break;

  case 549:
#line 3231 "fgl.yacc"
    {
push_blockcommand("FOREACH");
}
    break;

  case 550:
#line 3235 "fgl.yacc"
    {
print_foreach_start();
A4GL_lex_printcomment(" /* foreach */\n");
}
    break;

  case 551:
#line 3241 "fgl.yacc"
    {
print_foreach_next(yyvsp[-3].str,yyvsp[-1].str,yyvsp[0].str);
}
    break;

  case 552:
#line 3245 "fgl.yacc"
    {
add_continue_blockcommand ("FOREACH");
print_foreach_end(yyvsp[-6].str);
pop_blockcommand("FOREACH"); 
print_foreach_close(yyvsp[-6].str);
}
    break;

  case 553:
#line 3254 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 554:
#line 3255 "fgl.yacc"
    {
		strcpy(yyval.str,yyvsp[0].str);
	}
    break;

  case 555:
#line 3267 "fgl.yacc"
    {
		sprintf(curr_func,"%s",yyvsp[0].str); 
		print_formhandler(yyvsp[0].str);
		start_state("formhandler",1);
	push_blockcommand("FORMHANDLER");
        }
    break;

  case 556:
#line 3273 "fgl.yacc"
    {
		print_variables();
		print_getwin();
	}
    break;

  case 557:
#line 3281 "fgl.yacc"
    {
pop_blockcommand("FORMHANDLER");
print_end_formhandler(); 
start_state("formhandler",0);}
    break;

  case 564:
#line 3298 "fgl.yacc"
    {
		print_event('B');
        }
    break;

  case 565:
#line 3300 "fgl.yacc"
    {
		print_event_2();
        }
    break;

  case 566:
#line 3303 "fgl.yacc"
    {
		print_event('b');
        }
    break;

  case 567:
#line 3305 "fgl.yacc"
    {
		print_event_2();
        }
    break;

  case 572:
#line 3319 "fgl.yacc"
    {
		print_event('A');
        }
    break;

  case 573:
#line 3321 "fgl.yacc"
    {
		print_event_2();
        }
    break;

  case 574:
#line 3324 "fgl.yacc"
    {
		print_event('a');
        }
    break;

  case 575:
#line 3326 "fgl.yacc"
    {
		print_event_2();
        }
    break;

  case 588:
#line 3357 "fgl.yacc"
    { 
			print_gtk_field('B',0);
		}
    break;

  case 589:
#line 3359 "fgl.yacc"
    {
			print_gtk_field_2();
		}
    break;

  case 590:
#line 3362 "fgl.yacc"
    { 
			print_gtk_field('A',0);
		}
    break;

  case 591:
#line 3364 "fgl.yacc"
    {
			print_gtk_field_2();
		}
    break;

  case 592:
#line 3367 "fgl.yacc"
    {
			print_gtk_field('b',yyvsp[0].str);
		}
    break;

  case 593:
#line 3369 "fgl.yacc"
    { 
			print_gtk_field_2();
		}
    break;

  case 594:
#line 3372 "fgl.yacc"
    {
			print_gtk_field('a',yyvsp[0].str);
		}
    break;

  case 595:
#line 3374 "fgl.yacc"
    { 
			print_gtk_field_2();
		}
    break;

  case 596:
#line 3377 "fgl.yacc"
    { 
			print_gtk_field('o',yyvsp[0].str);
		}
    break;

  case 597:
#line 3379 "fgl.yacc"
    { 
			print_gtk_field_2();
		}
    break;

  case 598:
#line 3394 "fgl.yacc"
    {
		//print_niy("Free Cursor");
		A4GL_lex_printcomment(" /* FIXME: Not implemented: Free Cursor */\n");;

		strcpy(yyval.str,"");
		}
    break;

  case 599:
#line 3410 "fgl.yacc"
    {sprintf(yyval.str,"%d",-1-(atoi(yyvsp[0].str)));}
    break;

  case 600:
#line 3411 "fgl.yacc"
    {strcpy(yyval.str,"-1");}
    break;

  case 601:
#line 3412 "fgl.yacc"
    {sprintf (yyval.str,"%d",atoi(yyvsp[0].str)+1);}
    break;

  case 602:
#line 3413 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 603:
#line 3414 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 604:
#line 3415 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 605:
#line 3416 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 609:
#line 3424 "fgl.yacc"
    {sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str); }
    break;

  case 611:
#line 3430 "fgl.yacc"
    { 
			yyval.field_entry=new_field_entry(yyvsp[0].str,"1",1);
		}
    break;

  case 612:
#line 3433 "fgl.yacc"
    { 
				char buff[256];
				sprintf(buff,"int_to_id(%s)",yyvsp[-1].str);
				yyval.field_entry=new_field_entry(buff,"1",0); 
		}
    break;

  case 613:
#line 3438 "fgl.yacc"
    { 
				char buff[256];
				sprintf(buff,"int_to_id(%s.%s)",yyvsp[-5].str,yyvsp[-1].str); 
				yyval.field_entry=new_field_entry(buff,"1",0); 
		}
    break;

  case 614:
#line 3443 "fgl.yacc"
    {
				yyval.field_entry=new_field_entry(yyvsp[-3].str,yyvsp[-1].str,1);
		}
    break;

  case 615:
#line 3446 "fgl.yacc"
    {
				char buff[256];
				sprintf(buff,"%s.*",yyvsp[-2].str);
				yyval.field_entry=new_field_entry(buff,"1",1);
		}
    break;

  case 616:
#line 3451 "fgl.yacc"
    {
				char buff[256];
				sprintf(buff,"%s.*",yyvsp[-5].str);
				yyval.field_entry=new_field_entry(buff,yyvsp[-3].str,1);
		}
    break;

  case 617:
#line 3456 "fgl.yacc"
    {
				char buff[256];
				sprintf(buff,"%s.%s",yyvsp[-2].str,yyvsp[0].str);
				yyval.field_entry=new_field_entry(buff,"1",1);
		}
    break;

  case 618:
#line 3461 "fgl.yacc"
    {
				char buff[256];
				sprintf(buff,"%s.%s",yyvsp[-5].str,yyvsp[0].str);
				yyval.field_entry=new_field_entry(buff,yyvsp[-3].str,1);
		}
    break;

  case 619:
#line 3468 "fgl.yacc"
    {
				print_pushchar(yyvsp[0].str);
				addmap("Cursor",last_var,curr_func,yylineno,infilename);
			}
    break;

  case 620:
#line 3475 "fgl.yacc"
    {sprintf(yyval.str,"%s",yyvsp[0].str);}
    break;

  case 621:
#line 3477 "fgl.yacc"
    {sprintf(yyval.str,"%s",yyvsp[0].str);
addmap("Window",last_var,curr_func,yylineno,infilename);
}
    break;

  case 622:
#line 3483 "fgl.yacc"
    {sprintf(yyval.str,"%s",yyvsp[0].str);
addmap("Open Window",last_var,curr_func,yylineno,infilename);
}
    break;

  case 623:
#line 3488 "fgl.yacc"
    {sprintf(yyval.str,"%s",yyvsp[0].str);
addmap("Form",last_var,curr_func,yylineno,infilename);
}
    break;

  case 624:
#line 3493 "fgl.yacc"
    {sprintf(yyval.str,"%s",yyvsp[0].str);
addmap("Open Form",last_var,curr_func,yylineno,infilename);
}
    break;

  case 625:
#line 3498 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 626:
#line 3498 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 627:
#line 3501 "fgl.yacc"
    { 
			strcpy(yyval.str,downshift(yyvsp[0].str)) ;
}
    break;

  case 628:
#line 3507 "fgl.yacc"
    {
			sprintf(yyval.str,"%s",downshift(yyvsp[0].str)) ;
			}
    break;

  case 629:
#line 3512 "fgl.yacc"
    {
	strcpy(yyval.str,do_clobbering(clobber,downshift(yyvsp[0].str))) ;
	strcpy(last_var,downshift(yyvsp[0].str));
}
    break;

  case 630:
#line 3516 "fgl.yacc"
    {
		sprintf(yyval.str,"aclfgli_str_to_id(%s)",yyvsp[-1].str);
		sprintf(last_var,"->%s",yyvsp[-1].str);
	}
    break;

  case 633:
#line 3524 "fgl.yacc"
    {
					yyval.field_entry=new_field_entry(yyvsp[0].str,"1",0); 
				}
    break;

  case 634:
#line 3527 "fgl.yacc"
    {
					yyval.field_entry=new_field_entry(yyvsp[-3].str,yyvsp[-1].str,0); 
				}
    break;

  case 635:
#line 3530 "fgl.yacc"
    {
					char buff[256];
					sprintf(buff,"%s.*",yyvsp[-2].str);
					yyval.field_entry=new_field_entry(buff,"1",1); 
				}
    break;

  case 636:
#line 3535 "fgl.yacc"
    {
					char buff[256];
					sprintf(buff,"%s.*",yyvsp[-5].str);
					yyval.field_entry=new_field_entry(buff,yyvsp[-3].str,1); 
				}
    break;

  case 637:
#line 3540 "fgl.yacc"
    {
					char buff[256];
					sprintf(buff,"%s.%s",yyvsp[-2].str,yyvsp[0].str);
					yyval.field_entry=new_field_entry(buff,"1",1); 
				}
    break;

  case 638:
#line 3545 "fgl.yacc"
    {
					char buff[256];
					sprintf(buff,"%s.%s",yyvsp[-5].str,yyvsp[0].str);
					yyval.field_entry=new_field_entry(buff,yyvsp[-3].str,1); 
				}
    break;

  case 639:
#line 3552 "fgl.yacc"
    {
A4GL_debug("Scanvar=%d",scan_variable(yyvsp[0].str)&15);
if ((scan_variable(yyvsp[0].str)&15)!=0) {
a4gl_yyerror("Only a character variable can be used for this");
YYERROR;
}
}
    break;

  case 641:
#line 3561 "fgl.yacc"
    {
		sprintf(yyval.str,".%s",yyvsp[0].str);
}
    break;

  case 642:
#line 3623 "fgl.yacc"
    {
	print_goto(yyvsp[0].str);
}
    break;

  case 644:
#line 3629 "fgl.yacc"
    {sprintf(yyval.str,"%s",yyvsp[0].str);}
    break;

  case 645:
#line 3638 "fgl.yacc"
    {
print_gui_do_menuitems(yyvsp[0].str,'C');
}
    break;

  case 647:
#line 3645 "fgl.yacc"
    {sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 648:
#line 3648 "fgl.yacc"
    {
        sprintf(yyval.str,"\"%s\"",yyvsp[0].str);
}
    break;

  case 649:
#line 3654 "fgl.yacc"
    {
print_gui_do_menuitems(yyvsp[0].str,'U');
}
    break;

  case 650:
#line 3660 "fgl.yacc"
    {
print_gui_do_menuitems(yyvsp[0].str,'D');
}
    break;

  case 651:
#line 3664 "fgl.yacc"
    {
print_gui_do_fields(field_name_list_as_char(yyvsp[0].field_list),'D');
}
    break;

  case 652:
#line 3668 "fgl.yacc"
    {
print_gui_do_form(yyvsp[-2].str,field_name_list_as_char(yyvsp[0].field_list),'D');
}
    break;

  case 653:
#line 3674 "fgl.yacc"
    {
print_gui_do_menuitems(yyvsp[0].str,'E');
}
    break;

  case 654:
#line 3678 "fgl.yacc"
    {
print_gui_do_fields(field_name_list_as_char(yyvsp[0].field_list),'E');
}
    break;

  case 655:
#line 3682 "fgl.yacc"
    {
print_gui_do_form(field_name_list_as_char(yyvsp[-2].field_list),yyvsp[0].str,'E');
}
    break;

  case 656:
#line 3687 "fgl.yacc"
    {start_state("messagebox",1);}
    break;

  case 657:
#line 3692 "fgl.yacc"
    {start_state("messagebox",0);}
    break;

  case 676:
#line 3733 "fgl.yacc"
    {
		if_print_stack_cnt++;
		if_print_stack[if_print_stack_cnt][0]=0;
		if_print_stack[if_print_stack_cnt][1]=0;
		if_print_section[if_print_stack_cnt]=0;
		print_if_start();
	}
    break;

  case 677:
#line 3740 "fgl.yacc"
    {
		if_print_section[if_print_stack_cnt]=1;
	}
    break;

  case 678:
#line 3742 "fgl.yacc"
    {
		char wt;
		print_if_end();
	        wt=get_curr_report_stack_whytype();
		//if (wt=='P'||wt=='p'||wt=='T') {
		if (wt=='T') {
			if (if_print_stack[if_print_stack_cnt][0]!=if_print_stack[if_print_stack_cnt][0]) {
				a4gl_yyerror("Number of lines printed in an IF.. THEN must be the same for TRUE and FALSE");
				YYERROR;
			}
			
			if (if_print_stack_cnt>=1) {
				if_print_stack[if_print_stack_cnt-1][if_print_section[if_print_stack_cnt-1]]+=if_print_stack[if_print_stack_cnt][0];
			}
		}
		if_print_stack_cnt--;
	}
    break;

  case 680:
#line 3761 "fgl.yacc"
    {
		print_if_else();
	}
    break;

  case 682:
#line 3764 "fgl.yacc"
    {
		print_if_else();
		}
    break;

  case 683:
#line 3766 "fgl.yacc"
    {

		print_if_start();
	}
    break;

  case 684:
#line 3769 "fgl.yacc"
    {
		print_if_end();
	}
    break;

  case 685:
#line 3773 "fgl.yacc"
    {
		print_import(yyvsp[-3].str,atoi(yyvsp[-1].str));
	}
    break;

  case 686:
#line 3776 "fgl.yacc"
    {
		print_import_legacy(yyvsp[0].str);
	}
    break;

  case 687:
#line 3782 "fgl.yacc"
    { add_ex_dtype(yyvsp[0].str); }
    break;

  case 688:
#line 3793 "fgl.yacc"
    {A4GL_debug("init to\n");}
    break;

  case 689:
#line 3794 "fgl.yacc"
    {
	print_init();
 }
    break;

  case 690:
#line 3797 "fgl.yacc"
    {
	print_init_table(yyvsp[0].str);
}
    break;

  case 692:
#line 3803 "fgl.yacc"
    {sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 693:
#line 3807 "fgl.yacc"
    {setrecord(yyval.str,yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 694:
#line 3808 "fgl.yacc"
    {setrecord(yyval.str,yyvsp[-2].str,0);}
    break;

  case 698:
#line 3824 "fgl.yacc"
    {
sprintf(yyval.str,"0");
}
    break;

  case 699:
#line 3826 "fgl.yacc"
    {
sprintf(yyval.str,"1");
}
    break;

  case 702:
#line 3835 "fgl.yacc"
    {
		A4GL_add_event(-97,field_name_list_as_or_char(yyvsp[0].field_list));
		print_befaft_field_1(field_name_list_as_or_char(yyvsp[0].field_list));
}
    break;

  case 703:
#line 3838 "fgl.yacc"
    {
	print_befaft_field_2();
}
    break;

  case 704:
#line 3842 "fgl.yacc"
    {
		A4GL_add_event(-98,field_name_list_as_or_char(yyvsp[0].field_list));
		print_befaft_field_1(field_name_list_as_or_char(yyvsp[0].field_list));
}
    break;

  case 705:
#line 3845 "fgl.yacc"
    {
	print_befaft_field_2();
}
    break;

  case 706:
#line 3848 "fgl.yacc"
    {
		A4GL_add_event(-11,"");
		print_befaft_field_1("AFT_ROW");
}
    break;

  case 707:
#line 3851 "fgl.yacc"
    {
	print_befaft_field_2();
}
    break;

  case 708:
#line 3854 "fgl.yacc"
    {
		A4GL_add_event(-10,"");
		A4GL_lex_printcomment("/* before row */ \n");
		print_befaft_field_1("BEF_ROW");
}
    break;

  case 709:
#line 3858 "fgl.yacc"
    {
	print_befaft_field_2();
		}
    break;

  case 710:
#line 3861 "fgl.yacc"
    {
	A4GL_add_onkey_key(yyvsp[0].str);
	print_onkey_1(yyvsp[0].str);
}
    break;

  case 711:
#line 3864 "fgl.yacc"
    {
	print_onkey_2();
}
    break;

  case 712:
#line 3867 "fgl.yacc"
    {
		A4GL_add_event(-95,"");
		print_befaft_field_1("AFTER_INP");
}
    break;

  case 713:
#line 3870 "fgl.yacc"
    {
	print_befaft_field_2();
}
    break;

  case 714:
#line 3873 "fgl.yacc"
    {
		A4GL_add_event(-99,"");
		print_befaft_field_1("BEFORE_INP");
}
    break;

  case 715:
#line 3876 "fgl.yacc"
    {
	print_befaft_field_2();
}
    break;

  case 716:
#line 3879 "fgl.yacc"
    {
		A4GL_add_event(-12,"");
		print_befaft_field_1("DO_BEFORE_DELETE");
	}
    break;

  case 717:
#line 3882 "fgl.yacc"
    { print_befaft_field_2(); }
    break;

  case 718:
#line 3883 "fgl.yacc"
    {
		A4GL_add_event(-14,"");
		print_befaft_field_1("DO_BEFORE_INSERT");
	}
    break;

  case 719:
#line 3886 "fgl.yacc"
    { print_befaft_field_2(); }
    break;

  case 720:
#line 3887 "fgl.yacc"
    {
		A4GL_add_event(-13,"");
		print_befaft_field_1("DO_AFTER_DELETE");
	}
    break;

  case 721:
#line 3890 "fgl.yacc"
    { print_befaft_field_2(); }
    break;

  case 722:
#line 3891 "fgl.yacc"
    {
		A4GL_add_event(-15,"");
		print_befaft_field_1("DO_AFTER_INSERT");
	}
    break;

  case 723:
#line 3894 "fgl.yacc"
    { print_befaft_field_2(); }
    break;

  case 724:
#line 3902 "fgl.yacc"
    {
                        yyval.field_list=new_field_list();
                        yyval.field_list=append_field_to_list(yyval.field_list,yyvsp[0].field_entry);
        }
    break;

  case 725:
#line 3906 "fgl.yacc"
    {
                        yyval.field_list=append_field_to_list(yyvsp[-2].field_list,yyvsp[0].field_entry);
        }
    break;

  case 726:
#line 3912 "fgl.yacc"
    {
                        yyval.field_list=new_field_list();
                        yyval.field_list=append_field_to_list(yyval.field_list,yyvsp[0].field_entry);
        }
    break;

  case 727:
#line 3916 "fgl.yacc"
    {
                        yyval.field_list=append_field_to_list(yyvsp[-2].field_list,yyvsp[0].field_entry);
        }
    break;

  case 728:
#line 3921 "fgl.yacc"
    {
print_next_field(yyvsp[0].str);
}
    break;

  case 729:
#line 3926 "fgl.yacc"
    {
print_next_form_field(yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 730:
#line 3931 "fgl.yacc"
    {sprintf(yyval.str,"\"+\"");}
    break;

  case 731:
#line 3932 "fgl.yacc"
    {sprintf(yyval.str,"\"-\"");}
    break;

  case 732:
#line 3933 "fgl.yacc"
    {sprintf(yyval.str,field_name_as_char(yyvsp[0].field_entry));}
    break;

  case 733:
#line 3937 "fgl.yacc"
    {
print_input_1();
  A4GL_new_events();
}
    break;

  case 734:
#line 3941 "fgl.yacc"
    {
print_input_2(yyvsp[-2].str);
A4GL_drop_events();
}
    break;

  case 735:
#line 3950 "fgl.yacc"
    {
print_input(1,yyvsp[-2].str,yyvsp[-1].str,0,atoi(yyvsp[0].str));
strcpy(yyval.str,A4GL_get_formloop_str(0));
}
    break;

  case 736:
#line 3955 "fgl.yacc"
    {
print_input(0,yyvsp[-4].str,yyvsp[-1].str,field_name_list_as_char(yyvsp[-2].field_list),atoi(yyvsp[0].str));
strcpy(yyval.str,A4GL_get_formloop_str(0));
}
    break;

  case 737:
#line 3959 "fgl.yacc"
    {
curr_input_array_attribs.maxcount=0;
curr_input_array_attribs.count=0;
curr_input_array_attribs.allow_insert=1;
curr_input_array_attribs.allow_delete=1;
curr_input_array_attribs.curr_row_display=0;
inp_flags=0;}
    break;

  case 738:
#line 3966 "fgl.yacc"
    {
strcpy(yyval.str,print_input_array(fgl_add_scope(yyvsp[-8].str,0),yyvsp[-2].str,yyvsp[-7].str,yyvsp[-5].str,yyvsp[0].str,&curr_input_array_attribs));
}
    break;

  case 739:
#line 3975 "fgl.yacc"
    {
		print_scroll(field_name_list_as_char(yyvsp[-1].field_list),yyvsp[0].str);
	}
    break;

  case 740:
#line 3981 "fgl.yacc"
    {sprintf(yyval.str,"%s",yyvsp[0].str);}
    break;

  case 741:
#line 3982 "fgl.yacc"
    {sprintf(yyval.str,"-%s",yyvsp[0].str);}
    break;

  case 742:
#line 3983 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 743:
#line 3984 "fgl.yacc"
    {strcpy(yyval.str,"-1");}
    break;

  case 744:
#line 3987 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 746:
#line 3990 "fgl.yacc"
    {
	strcpy(yyval.str,"");
}
    break;

  case 747:
#line 3997 "fgl.yacc"
    { curr_input_array_attribs.curr_row_display=strdup(yyvsp[0].str); }
    break;

  case 748:
#line 3998 "fgl.yacc"
    { curr_input_array_attribs.count=strdup(yyvsp[0].str); }
    break;

  case 749:
#line 3999 "fgl.yacc"
    { curr_input_array_attribs.count=strdup(yyvsp[0].str); }
    break;

  case 750:
#line 4000 "fgl.yacc"
    { curr_input_array_attribs.maxcount=strdup(yyvsp[0].str); }
    break;

  case 751:
#line 4001 "fgl.yacc"
    { curr_input_array_attribs.maxcount=strdup(yyvsp[0].str); }
    break;

  case 752:
#line 4002 "fgl.yacc"
    { curr_input_array_attribs.allow_insert=1; }
    break;

  case 753:
#line 4003 "fgl.yacc"
    { curr_input_array_attribs.allow_insert=0; }
    break;

  case 754:
#line 4004 "fgl.yacc"
    { curr_input_array_attribs.allow_delete=1; }
    break;

  case 755:
#line 4005 "fgl.yacc"
    { curr_input_array_attribs.allow_delete=0; }
    break;

  case 756:
#line 4010 "fgl.yacc"
    {iskey=1;}
    break;

  case 757:
#line 4010 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);iskey=0;}
    break;

  case 758:
#line 4012 "fgl.yacc"
    {strcpy(yyval.str,"->ANY");}
    break;

  case 759:
#line 4015 "fgl.yacc"
    {iskey=1;}
    break;

  case 760:
#line 4015 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);iskey=0;}
    break;

  case 761:
#line 4017 "fgl.yacc"
    {sprintf(yyval.str,"A4GL_key_val(\"%s\")",yyvsp[0].str);iskey=0;}
    break;

  case 762:
#line 4021 "fgl.yacc"
    {sprintf(yyval.str,"A4GL_key_val(\"%s\")",yyvsp[0].str);iskey=0;}
    break;

  case 763:
#line 4024 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 764:
#line 4025 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[-1].str);}
    break;

  case 766:
#line 4028 "fgl.yacc"
    {
	sprintf(yyval.str,"%s||%s",yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 772:
#line 4040 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 773:
#line 4041 "fgl.yacc"
    {strcpy(yyval.str,"escape");}
    break;

  case 774:
#line 4042 "fgl.yacc"
    {strcpy(yyval.str,"up");}
    break;

  case 775:
#line 4043 "fgl.yacc"
    {strcpy(yyval.str,"help");}
    break;

  case 776:
#line 4044 "fgl.yacc"
    {strcpy(yyval.str,"down");}
    break;

  case 777:
#line 4045 "fgl.yacc"
    {strcpy(yyval.str,"return");}
    break;

  case 778:
#line 4046 "fgl.yacc"
    {strcpy(yyval.str,"delete");}
    break;

  case 779:
#line 4047 "fgl.yacc"
    {strcpy(yyval.str,"insert");}
    break;

  case 780:
#line 4048 "fgl.yacc"
    {strcpy(yyval.str,"tab");}
    break;

  case 781:
#line 4049 "fgl.yacc"
    {strcpy(yyval.str,"left");}
    break;

  case 782:
#line 4050 "fgl.yacc"
    {strcpy(yyval.str,"right");}
    break;

  case 783:
#line 4051 "fgl.yacc"
    {strcpy(yyval.str,"nextpage");}
    break;

  case 784:
#line 4052 "fgl.yacc"
    {strcpy(yyval.str,"prevpage");}
    break;

  case 785:
#line 4053 "fgl.yacc"
    { rm_quotes(yyvsp[0].str); strcpy(yyval.str,yyvsp[0].str); }
    break;

  case 786:
#line 4057 "fgl.yacc"
    {
char buff[256];
A4GL_debug("Label : %s\n",get_idents(0));
strcpy(buff,get_idents(0));
A4GL_convlower(buff);
print_label(buff);
}
    break;

  case 787:
#line 4075 "fgl.yacc"
    {chk4var=1;}
    break;

  case 788:
#line 4075 "fgl.yacc"
    {chk4var=0;
expand_obind();
A4GL_lex_printcomment("/*let3*/\n");}
    break;

  case 789:
#line 4078 "fgl.yacc"
    {
int to_vars;
	
	A4GL_debug("/*processing let*/\n");
	expand_obind();
	to_vars=how_many_in_bind('o');
	if (to_vars>=1)
	{

		if (!print_let_manyvars(yyvsp[0].str))
		{
	    		a4gl_yyerror("Number of variables in let not equal to number of values\n");YYERROR;
		}

	}
	else
	{
	    print_bind_pop1('o');
		start_bind('o',0);
	}

}
    break;

  case 790:
#line 4102 "fgl.yacc"
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

  case 792:
#line 4120 "fgl.yacc"
    {
		if (!print_linked_cmd('S',yyvsp[0].str)) a4gl_yyerror("Not a linked variable");
	}
    break;

  case 793:
#line 4126 "fgl.yacc"
    {
		 if (!print_linked_cmd('D',yyvsp[0].str)) a4gl_yyerror("Not a linked variable");
	}
    break;

  case 794:
#line 4132 "fgl.yacc"
    {
		 if (!print_linked_cmd('U',yyvsp[0].str)) a4gl_yyerror("Not a linked variable");
}
    break;

  case 795:
#line 4138 "fgl.yacc"
    {
int vtype;
vtype=scan_variable(yyvsp[-1].str);
if (vtype!=11&&vtype!=12) {
a4gl_yyerror("Only Byte & Text may be located...");
YYERROR;
}
print_locate('M',yyvsp[-1].str,"0");


}
    break;

  case 796:
#line 4149 "fgl.yacc"
    {
int vtype;
vtype=scan_variable(yyvsp[-2].str);
if (vtype!=11&&vtype!=12) {
a4gl_yyerror("Only Byte & Text may be located...");
YYERROR;
}

print_locate('F',yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 797:
#line 4172 "fgl.yacc"
    {
		if (glob_only==1) {
       			A4GL_debug("Read globals section so Im done\n");
       			YYACCEPT;
		}
	
		set_4gl_vars();

		set_current_variable_scope('g'); print_variables (); set_current_variable_scope('G'); print_variables (); set_current_variable_scope('m'); print_variables ();
print_module_variable_init();
		set_current_variable_scope('m');
	}
    break;

  case 800:
#line 4188 "fgl.yacc"
    {
	}
    break;

  case 807:
#line 4211 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 811:
#line 4219 "fgl.yacc"
    {
		print_at_termination(yyvsp[0].str);
	}
    break;

  case 826:
#line 4244 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 827:
#line 4245 "fgl.yacc"
    {
strcpy(yyval.str,"static ");
}
    break;

  case 828:
#line 4253 "fgl.yacc"
    {
  clr_variable(); lastlineno=yylineno;
  clr_function_constants (); 
}
    break;

  case 829:
#line 4258 "fgl.yacc"
    { 
if (is_builtin_func(yyvsp[-1].str)&&!compiling_system_4gl) {
	a4gl_yyerror("You can't use this name - this is the name of a builtin Aubit4GL function");
}

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

  case 830:
#line 4274 "fgl.yacc"
    {
  A4GL_lex_printcomment("/* new function %s parameters*/\n",yyvsp[-1].str);
  push_blockcommand("FUNC");
  A4GL_lex_printcomment("/* define section */\n");
}
    break;

  case 831:
#line 4280 "fgl.yacc"
    {
  int c;
  A4GL_lex_printcomment("/*end of define section */\n");
	print_variables();
  c=print_param('f');
  printPushFunction();
  print_func_args(c);
}
    break;

  case 833:
#line 4295 "fgl.yacc"
    {
    printPopFunction();
    print_func_defret0();
    pop_blockcommand("FUNC");
    print_func_end();
    clr_function_constants ();
    A4GL_lex_printcomment("/*end function*/\n");
  }
    break;

  case 834:
#line 4308 "fgl.yacc"
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

  case 835:
#line 4318 "fgl.yacc"
    {
	print_variables();
    printDeclareFunctionStack("MAIN");
    print_fgllib_start(hdr_dbname);
    printInitFunctionStack();
    printPushFunction();
  }
    break;

  case 836:
#line 4325 "fgl.yacc"
    {
pop_blockcommand("MAIN");
print_main_end();
A4GL_lex_printcomment("/*end main */\n");}
    break;

  case 837:
#line 4332 "fgl.yacc"
    {
    printPopFunction();
    print_return(atoi(yyvsp[0].str));
  }
    break;

  case 838:
#line 4338 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 839:
#line 4338 "fgl.yacc"
    {
A4GL_lex_printcomment("/* Got expr list */");
sprintf(yyval.str,"%s",yyvsp[0].str);}
    break;

  case 840:
#line 4343 "fgl.yacc"
    {
					open_db(yyvsp[0].str);
					strcpy(hdr_dbname,yyvsp[0].str);
					lastlineno=yylineno;
					is_schema=0;
			}
    break;

  case 841:
#line 4349 "fgl.yacc"
    {
					open_db(yyvsp[0].str);
					strcpy(hdr_dbname,yyvsp[0].str);
					lastlineno=yylineno;
					is_schema=1;
			}
    break;

  case 842:
#line 4357 "fgl.yacc"
    {
}
    break;

  case 848:
#line 4369 "fgl.yacc"
    {
strcpy(curr_func,"[Globals]");
set_current_variable_scope('g');
A4GL_lex_printcomment("/* start of globals */\n");
}
    break;

  case 850:
#line 4377 "fgl.yacc"
    {
 A4GL_lex_printcomment("/* end of globals */");
	A4GL_debug("end of globals\n");
	lastlineno=yylineno;
	set_current_variable_scope('m');
}
    break;

  case 851:
#line 4383 "fgl.yacc"
    {
char b[256];
	lastlineno=yylineno;
	strcpy(b,yyvsp[0].str);
	set_current_variable_scope('G');
	tr_glob_fname(b);
	A4GL_debug("Reading globals file %s\n",b);
	rm_quote(b);
	read_glob(b);
	set_current_variable_scope('m');
}
    break;

  case 852:
#line 4397 "fgl.yacc"
    {
  addmap("Define Member Function",curr_func,"MODULE",yylineno,infilename);
}
    break;

  case 853:
#line 4401 "fgl.yacc"
    {
  char buff[80];
  sprintf(buff,"%s_%s_%d",yyvsp[-4].str,yyvsp[-6].str,atoi(yyvsp[-1].str));
  sprintf(curr_func,"%s",buff);
  print_func_start("",buff,1);
  printDeclareFunctionStack(buff);

  cnt=0;
  A4GL_lex_printcomment("/* new function %s parameters*/\n",yyvsp[-1].str);
  push_blockcommand("FUNC");
  A4GL_lex_printcomment("/* define section */\n");
}
    break;

  case 854:
#line 4414 "fgl.yacc"
    {
	print_variables();
  A4GL_lex_printcomment("/*end of define section */\n");
  print_param('f');
  printPushFunction();
  print_func_args(atoi(yyvsp[-3].str));
}
    break;

  case 856:
#line 4432 "fgl.yacc"
    {
	start_state("menu",1);
   	menu_cnt=npush_menu();
   	menu_cmd_cnt[menu_cnt]=1;
   	push_blockcommand("MENU");
        menu_blk[menu_cnt]=get_blk_no();
	do_print_menu_1();
	}
    break;

  case 857:
#line 4440 "fgl.yacc"
    {
	start_state("menu",0);
	}
    break;

  case 858:
#line 4446 "fgl.yacc"
    {
   print_end_menu_1(menu_blk[menu_cnt]);
   add_continue_blockcommand ("MENU");
print_end_menu_2(menu_blk[menu_cnt]);
   pop_blockcommand("MENU");
   pop_menu();
}
    break;

  case 859:
#line 4457 "fgl.yacc"
    {
	 A4GL_lex_printcomment("/* Block%d_m2 (Before menu) */",menu_cnt);
		print_menu_block(menu_blk[menu_cnt],-2) ;
                  }
    break;

  case 860:
#line 4461 "fgl.yacc"
    {
		do_print_menu_block_end();
	}
    break;

  case 861:
#line 4468 "fgl.yacc"
    {
A4GL_debug("Menu=%d menu cnt=%d",menu_cnt,menu_cmd_cnt[menu_cnt]);
		push_command(menu_cnt,menu_cmd_cnt[menu_cnt],yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);
	 A4GL_lex_printcomment("/* Block%d_%d */",menu_cnt,menu_cmd_cnt[menu_cnt]-1);
		print_menu_block(menu_blk[menu_cnt],menu_cmd_cnt[menu_cnt]-1);
		menu_cmd_cnt[menu_cnt]++;
		}
    break;

  case 862:
#line 4475 "fgl.yacc"
    {
		do_print_menu_block_end();
}
    break;

  case 863:
#line 4481 "fgl.yacc"
    {
		push_command(menu_cnt,menu_cmd_cnt[menu_cnt],yyvsp[-1].str,"\"\"","\"\"",0);
		print_menu_block(menu_blk[menu_cnt],menu_cmd_cnt[menu_cnt]-1);
		menu_cmd_cnt[menu_cnt]++;
		}
    break;

  case 864:
#line 4486 "fgl.yacc"
    {
		do_print_menu_block_end();
}
    break;

  case 867:
#line 4493 "fgl.yacc"
    {strcpy(yyval.str,"\"EMPTY\"");}
    break;

  case 868:
#line 4494 "fgl.yacc"
    {sprintf(yyval.str,"\"%s\"",yyvsp[0].str);}
    break;

  case 869:
#line 4496 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str); }
    break;

  case 870:
#line 4497 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 871:
#line 4500 "fgl.yacc"
    {strcpy(yyval.str,"\"\"");}
    break;

  case 872:
#line 4501 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 873:
#line 4502 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 874:
#line 4504 "fgl.yacc"
    {
	print_option_op('N',yyvsp[0].str,menu_blk[menu_cnt]);
}
    break;

  case 875:
#line 4509 "fgl.yacc"
    {
	print_option_op('S',yyvsp[0].str,menu_blk[menu_cnt]);
}
    break;

  case 876:
#line 4514 "fgl.yacc"
    {
	print_option_op('H',yyvsp[0].str,menu_blk[menu_cnt]);
}
    break;

  case 877:
#line 4521 "fgl.yacc"
    {sprintf(yyval.str,"MENU_ALL");}
    break;

  case 881:
#line 4528 "fgl.yacc"
    {sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 882:
#line 4530 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);  
push_menu_title(yyval.str);}
    break;

  case 883:
#line 4532 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str); 
push_menu_title(yyval.str);}
    break;

  case 884:
#line 4541 "fgl.yacc"
    {
                strcpy(menuhandler,yyvsp[0].str);
	sprintf(curr_func,"%s",yyvsp[0].str); 
	print_gtk_menuhandler_1(yyvsp[0].str);
                push_blockcommand("MENUH");
}
    break;

  case 885:
#line 4547 "fgl.yacc"
    {
		print_variables();
        }
    break;

  case 886:
#line 4551 "fgl.yacc"
    {
                        pop_blockcommand("MENUH");
			print_gtk_menuhandler_end();
                }
    break;

  case 889:
#line 4563 "fgl.yacc"
    {

		print_gtk_menuhandler_bsm();

                push_blockcommand("BSM");
        }
    break;

  case 890:
#line 4568 "fgl.yacc"
    {
                pop_blockcommand("BSM");
		print_gtk_menuhandler_bsm_end();

        }
    break;

  case 891:
#line 4573 "fgl.yacc"
    {
print_gtk_menuhandler_on(yyvsp[0].str);
                push_blockcommand("ON");
        }
    break;

  case 892:
#line 4576 "fgl.yacc"
    {
                pop_blockcommand("ON");
		print_gtk_menuhandler_on_end();
}
    break;

  case 894:
#line 4588 "fgl.yacc"
    {
		print_message(0,"0",0,message_cnt);
	   }
    break;

  case 895:
#line 4591 "fgl.yacc"
    { 
		print_message(0,yyvsp[-1].str,atoi(yyvsp[0].str),message_cnt);
	  }
    break;

  case 896:
#line 4594 "fgl.yacc"
    { 
		print_message(0,"0",atoi(yyvsp[0].str),message_cnt);
	  }
    break;

  case 903:
#line 4610 "fgl.yacc"
    {
		strcpy(yyval.str,yyvsp[0].str);
		message_cnt=atoi(yyvsp[0].str);
		}
    break;

  case 904:
#line 4615 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 905:
#line 4615 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 906:
#line 4618 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 907:
#line 4645 "fgl.yacc"
    {
char buff[256];
char buff2[256];
int n;

if (strcmp(yyvsp[0].str,"status")==0) { strcpy(yyvsp[0].str,"a4gl_status"); }
if (strncmp(yyvsp[0].str,"sqlca.",6)==0) { 
	char xbuff[256];
	char xbuff2[256];
	strcpy(xbuff,"a4gl_sqlca.");
	strcpy(xbuff2,yyvsp[0].str);
	strcat(xbuff,&xbuff2[6]);
	strcpy(yyvsp[0].str,xbuff);
}
strcpy(buff,yyvsp[0].str);
A4GL_lex_printcomment("/* .. var %s*/",buff);
if (buff[0]!=' ') addmap("Use Variable",buff,curr_func,yylineno,infilename);

if (strncmp(buff," ASSOCIATE_",11)!=0) {
 A4GL_convlower(buff);
}

strcpy(yyval.str,buff);
A4GL_debug("Checking variable '%s'",buff);
strcpy(buff2,buff);
n=scan_variable(buff2);

  A4GL_debug("scan variable returns -> %d\n",n);

  if (n == -1&&buff[0]!=' ') {
           sprintf(buff2,"'%s' does not represent a defined variable (1)",buff);
           a4gl_yyerror(buff2);
           exit (0);
  }

  strcpy(buff2,yyvsp[0].str);


  if (strstr(buff,".*") && n!=-2) {
		char *ptr;
		strcpy(buff,yyvsp[0].str);
		printf("WARNING : Using a .* on a non-record - %s\n",yyvsp[0].str);
		ptr=strstr(buff,".*");
		*ptr=0;
                
		sprintf(yyval.str,"%s",fgl_add_scope(buff,0));
  } else {
                	sprintf(yyval.str,"%s",fgl_add_scope(yyvsp[0].str,0));
  }

 
  mcnt = 0;
}
    break;

  case 909:
#line 4702 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 911:
#line 4709 "fgl.yacc"
    { 
         sprintf (yyval.str, "%s.%s", yyvsp[-1].str, yyvsp[0].str); 
         A4GL_lex_printcomment("/* record building -> %s */\n",yyval.str);
         }
    break;

  case 912:
#line 4713 "fgl.yacc"
    {

         int type,arrsize,size,level;
         char buff[256];
         char buff2[256];
         char arrbuff[256];

         A4GL_lex_printcomment("/* OPEN_SQUARE.. */\n");

	if (strcmp(yyvsp[-4].str,"sqlca")==0) {
		strcpy(yyvsp[-4].str,"a4gl_sqlca");
	}
         sprintf(buff,"%s.%s",yyvsp[-4].str,yyvsp[-3].str);
         if (scan_variable(buff)==-1) {
	
           sprintf(buff2,"'%s' does not represent a defined variable (2)",buff);
           a4gl_yyerror(buff2);
           YYERROR;
         }

         A4GL_lex_printcomment("/*variable with [...]*/");
         get_variable_dets (buff,&type,&arrsize,&size,&level,arrbuff);
         A4GL_lex_printcomment("/* Arrsize = %d size = %d*/",arrsize,size);
	 
         if (arrsize>0)
         {
             A4GL_debug("Is array...");
             sprintf (yyval.str, "%s[%s]", buff, change_arr_elem(yyvsp[-1].str));
             A4GL_lex_printcomment ("/* array variable %s num_arr_elem=%d arrbuff=%d*/\n", yyval.str,num_arr_elem(yyvsp[-1].str),num_arr_elem(arrbuff));
         }
         else
         {
             A4GL_debug ("Is string...");
             sprintf (yyval.str, " a4gl_substr(%s , %d , %s , 0 ) /*1*/", fgl_add_scope(buff,0), (int)scan_variable (buff), yyvsp[-1].str);
      		dec_counter();

             addmap("Use Variable",buff,curr_func,yylineno,infilename);
             A4GL_lex_printcomment ("/*character variable %s*/\n", yyval.str);
         }

         mcnt++;
}
    break;

  case 913:
#line 4756 "fgl.yacc"
    {

         int type,arrsize,size,level;
         char buff[256];
         char buff2[256];
         char arrbuff[256];

         A4GL_lex_printcomment("/* OPEN_SQUARE.. */\n");

	if (strcmp(yyvsp[-7].str,"sqlca")==0) {
		strcpy(yyvsp[-7].str,"a4gl_sqlca");
	}
         sprintf(buff,"%s.%s",yyvsp[-7].str,yyvsp[-6].str);
         if (scan_variable(buff)==-1) {
           sprintf(buff2,"'%s' does not represent a defined variable (2)",buff);
           a4gl_yyerror(buff2);
           YYERROR;
         }

         A4GL_lex_printcomment("/*variable with [...]*/");
         get_variable_dets (buff,&type,&arrsize,&size,&level,arrbuff);
         A4GL_lex_printcomment("/* Arrsize = %d size = %d*/",arrsize,size);
	 
         if (arrsize>0)
         {
		char buff2[256];
             A4GL_debug("Is array...");
             sprintf (buff2, "%s[%s]", buff, change_arr_elem(yyvsp[-4].str));
             sprintf (yyval.str, " a4gl_substr(%s , %d , %s , 0 ) /*1*/", fgl_add_scope(buff2,0), (int)scan_variable (buff2), yyvsp[-4].str);
             A4GL_lex_printcomment ("/* array variable %s num_arr_elem=%d arrbuff=%d*/\n", yyval.str,num_arr_elem(yyvsp[-4].str),num_arr_elem(arrbuff));
      	dec_counter();
         }
         else
         {
		a4gl_yyerror("Expecting an array of chars...");
		YYERROR;

         }

         mcnt++;
}
    break;

  case 917:
#line 4804 "fgl.yacc"
    {
char buff2[256];
         if (scan_variable(yyvsp[-3].str)==-1) {
           sprintf(buff2,"'%s' does not represent a defined variable (3)",yyvsp[-3].str);
           a4gl_yyerror(buff2); 
           YYERROR;
         }

A4GL_lex_printcomment("/*Associative Variable : %s*/\n",yyvsp[-1].str);
sprintf(yyval.str," ASSOCIATE_%s(%s,1)",upshift(yyvsp[-3].str),yyvsp[-1].str);
}
    break;

  case 918:
#line 4818 "fgl.yacc"
    {
char buff2[256];
         if (scan_variable(yyvsp[-3].str)==-1) {
           sprintf(buff2,"'%s' does not represent a defined variable (4)",yyvsp[-3].str);
           a4gl_yyerror(buff2); 
           YYERROR;
         }
A4GL_lex_printcomment("/*Associative Variable : %s*/\n",yyvsp[-1].str);
sprintf(yyval.str," ASSOCIATE_%s(%s,0)",upshift(yyvsp[-3].str),yyvsp[-1].str);
}
    break;

  case 923:
#line 4842 "fgl.yacc"
    {
int type,arrsize,size,level;
char buff2[256];
char arrbuff[256];

  A4GL_debug("ARRAY (array_r_variable) : %s %s",yyvsp[-1].str,yyvsp[0].str);
  //printf("ARRAY (array_r_variable) : %s %s",$<str>1,$<str>2);
  A4GL_lex_printcomment("/*array variable nnn */");
  get_variable_dets (yyvsp[-1].str,&type,&arrsize,&size,&level,arrbuff);
  A4GL_lex_printcomment("/*here %s %x */",yyvsp[-1].str,type);
  if (scan_variable(yyvsp[-1].str)==-1) {
           sprintf(buff2,"'%s' does not represent a defined variable (7)",yyvsp[-1].str);
           a4gl_yyerror(buff2); 
           YYERROR;

	}


  A4GL_debug("Type=%d (%d) arrsize=%d",type,type&0xffff,arrsize);

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
        sprintf (yyval.str, " a4gl_substr(%s , 0x%x , %s , 0 ) /*1.1*/", fgl_add_scope(tmpbuff,0), (int)scan_variable (tmpbuff), rbuff);
      	dec_counter();
  } else {
 
  if (((type & 0xffff) != 0) || (arrsize>0))
    {
		A4GL_debug("MJA Path 1");
      A4GL_lex_printcomment("/* changing optbase for array: %s */\n",yyvsp[0].str);
      sprintf (yyval.str, "%s[%s]", yyvsp[-1].str, change_arr_elem(yyvsp[0].str));
      A4GL_lex_printcomment ("/* array variable %s*/\n", yyval.str);
    }
  else
    {
             sprintf (yyval.str, " a4gl_substr(%s , %d , %s , 0 ) /*1.2*/", fgl_add_scope(yyvsp[-1].str,0), (int)scan_variable (yyvsp[-1].str), yyvsp[0].str);
             addmap("Use Variable",yyvsp[-1].str,curr_func,yylineno,infilename);
      A4GL_lex_printcomment ("/*character variable %s*/\n", yyval.str);
      	dec_counter();
      	mcnt--;
    }
}

  mcnt++;
}
    break;

  case 924:
#line 4902 "fgl.yacc"
    {
  int type,arrsize,size,level;
  //char buff2[256];
  char arrbuff[256];
//printf("ARRAY (array_r_variable) : %s %s",$<str>1,$<str>2);
  A4GL_lex_printcomment("/*array variable nnn */");
  get_variable_dets (yyvsp[-1].str,&type,&arrsize,&size,&level,arrbuff);
  A4GL_lex_printcomment("/*here %s %x */",yyvsp[-1].str,type);
  if (scan_variable(yyvsp[-1].str)==-1) {
	sprintf(yyval.str,"%s[%s]",yyvsp[-1].str,yyvsp[0].str);
  } else {


  A4GL_debug("Type=%d (%d) arrsize=%d",type,type&0xffff,arrsize);

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
             sprintf (yyval.str, " a4gl_substr(%s , %d , %s , 0 ) /*1.3*/", fgl_add_scope(tmpbuff,0), (int)scan_variable (tmpbuff), rbuff);
      	dec_counter();
  } else {
 
  if (((type & 0xffff) != 0) || (arrsize>0))
    {
      A4GL_lex_printcomment("/* changing optbase for array: %s */\n",yyvsp[0].str);
      sprintf (yyval.str, "%s[%s]", yyvsp[-1].str, change_arr_elem(yyvsp[0].str));
      A4GL_lex_printcomment ("/* array variable %s*/\n", yyval.str);
    }
  else
    {
             sprintf (yyval.str, " a4gl_substr(%s , %d , %s , 0 ) /*1.4*/", fgl_add_scope(yyvsp[-1].str,0), (int)scan_variable (yyvsp[-1].str), yyvsp[0].str);
             addmap("Use Variable",yyvsp[-1].str,curr_func,yylineno,infilename);
      A4GL_lex_printcomment ("/*character variable %s*/\n", yyval.str);
      	dec_counter();
      	mcnt--;
    }
  }
}

  mcnt++;
}
    break;

  case 925:
#line 4958 "fgl.yacc"
    {
	 A4GL_debug("---> Subscript or substring");
		strcpy(yyval.str,yyvsp[-1].str);
	}
    break;

  case 926:
#line 4963 "fgl.yacc"
    {
	 A4GL_debug("---> Subscript & substring");
		sprintf(yyval.str,"%s:%s",yyvsp[-4].str,yyvsp[-1].str);
	}
    break;

  case 927:
#line 4971 "fgl.yacc"
    {
A4GL_debug("List element");
  sprintf (yyval.str, "%s", yyvsp[0].str);
}
    break;

  case 928:
#line 4976 "fgl.yacc"
    {
A4GL_debug("List element continues");
  sprintf (yyval.str, "%s,%s", yyvsp[-2].str, yyvsp[0].str); 
}
    break;

  case 929:
#line 4984 "fgl.yacc"
    {
  sprintf (yyval.str, "%s", yyvsp[0].str);
}
    break;

  case 930:
#line 4990 "fgl.yacc"
    {
char buff[256];
if (strcmp(yyvsp[0].str,"status")==0) { strcpy(yyvsp[0].str,"a4gl_status"); }
if (strncmp(yyvsp[0].str,"sqlca.",6)==0) {
        char xbuff[256];
        char xbuff2[256];
        strcpy(xbuff,"a4gl_sqlca.");
        strcpy(xbuff2,yyvsp[0].str);
        strcat(xbuff,&xbuff2[6]);
        strcpy(yyvsp[0].str,xbuff);
}
strcpy(buff,yyvsp[0].str);
addmap("Let Variable",buff,curr_func,yylineno,infilename);
if (strncmp(buff," ASSOCIATE_",11)!=0) {
A4GL_convlower(buff);
}
strcpy(yyval.str,buff);
A4GL_lex_printcomment("/* %s */\n",yyvsp[0].str);


  if (scan_variable (buff) == -1&&buff[0]!=' ')
    {
      A4GL_lex_printcomment ("/*NOt a variable*/");
      sprintf(buff,"%s is not a variable",yyvsp[0].str);
      a4gl_yyerror(buff);
    }


  sprintf(yyval.str,"%s",fgl_add_scope(yyvsp[0].str,0));
  mcnt = 0;
}
    break;

  case 931:
#line 5022 "fgl.yacc"
    {
	 A4GL_debug("Array..");
}
    break;

  case 932:
#line 5025 "fgl.yacc"
    { sprintf (yyval.str, "%s.%s", yyvsp[-2].str, yyvsp[0].str); }
    break;

  case 933:
#line 5027 "fgl.yacc"
    {
  int a;
  int b;
  char buff[256];
  char buff2[256];
  A4GL_lex_printcomment("/*array variable .let. */");
  if (strcmp(yyvsp[-5].str,"status")==0) { strcpy(yyvsp[-5].str,"a4gl_status"); }
  if (strcmp(yyvsp[-5].str,"sqlca")==0) {
        strcpy(yyvsp[-5].str,"a4gl_sqlca");
  }
  sprintf(yyval.str,"%s.%s",yyvsp[-5].str,yyvsp[-3].str);

         if (scan_variable(yyval.str)==-1) {
           sprintf(buff2,"'%s' does not represent a defined variable (5)",yyval.str);
           a4gl_yyerror(buff2); 
           YYERROR;
         }

  A4GL_debug("?1arrvar=%s",yyval.str);
  b = isarrvariable (yyval.str);
  a = scan_variable (yyval.str);

  A4GL_lex_printcomment("/*a=%x b=%x */\n",a,b);

  if (b != 0)
    {
      sprintf (yyval.str, "%s.%s[%s-1] ", yyvsp[-5].str, yyvsp[-3].str,yyvsp[-1].str);
      A4GL_lex_printcomment ("/* array variable %s*/\n", yyval.str);
    }
  else
    {
      sprintf(buff,"%s.%s",yyvsp[-5].str,yyvsp[-3].str);
      sprintf (yyval.str, " a4gl_let_substr(%s,%d,%s,0) /* M4 */", fgl_add_scope(buff,0), a, yyvsp[-1].str);
      addmap("Let Variable",buff,curr_func,yylineno,infilename);
      A4GL_lex_printcomment ("/*character variable %s*/\n", yyval.str);
    }

  mcnt++;

}
    break;

  case 934:
#line 5068 "fgl.yacc"
    {
  int a;
  int b;
  char buff[256];
  char buff2[256];
  A4GL_lex_printcomment("/*array variable .let. */");
  if (strcmp(yyvsp[-8].str,"status")==0) { strcpy(yyvsp[-8].str,"a4gl_status"); }
  if (strcmp(yyvsp[-8].str,"sqlca")==0) {
        strcpy(yyvsp[-8].str,"a4gl_sqlca");
  }
  sprintf(yyval.str,"%s.%s",yyvsp[-8].str,yyvsp[-6].str);

         if (scan_variable(yyval.str)==-1) {
           sprintf(buff2,"'%s' does not represent a defined variable (5)",yyval.str);
           a4gl_yyerror(buff2); 
           YYERROR;
         }

  A4GL_debug("?1arrvar=%s",yyval.str);
  b = isarrvariable (yyval.str);
  a = scan_variable (yyval.str);

  A4GL_lex_printcomment("/*a=%x b=%x */\n",a,b);

  if (b != 0)
    {
      sprintf (buff, "%s.%s[%s-1] ", yyvsp[-8].str, yyvsp[-6].str,yyvsp[-4].str);
      sprintf (yyval.str, " a4gl_let_substr(%s,%x,%s,0) /* M1 */", fgl_add_scope(buff,0), a, yyvsp[-1].str);
      A4GL_lex_printcomment ("/* subscript on array variable %s*/\n", yyval.str);
    }
  else
    {
		a4gl_yyerror("I was really hoping for an array");
		YYERROR;

    }

  mcnt++;

}
    break;

  case 939:
#line 5121 "fgl.yacc"
    {
/*OPEN_SQUARE num_list CLOSE_SQUARE*/
  int a;
  int b;
  char buff2[256];
  A4GL_lex_printcomment("/*.let. array variable */");

  A4GL_debug("?2 arrvar=%s",yyvsp[-1].str);
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
        sprintf (yyval.str, " a4gl_let_substr(%s,%d,%s,0) /* M2 */", fgl_add_scope(tmpbuff,0), (int)scan_variable (tmpbuff), rbuff);
  } else {
  	b = isarrvariable (yyvsp[-1].str);
  	a = scan_variable (yyvsp[-1].str);

         if (a==-1) {
           sprintf(buff2,"'%s' does not represent a defined variable (6)",yyvsp[-1].str);
           a4gl_yyerror(buff2); 
           YYERROR;
         }


  A4GL_debug("/*a=%d b=%d*/\n",a,b);

  if (b != 0)
    {
      sprintf (yyval.str, "%s[%s]", yyvsp[-1].str, A4GL_decode_array_string(yyvsp[0].str));
      A4GL_debug ("/* array variable %s*/\n", yyval.str);
    }
  else
    {
      sprintf (yyval.str, " a4gl_let_substr(%s,%d,%s,0) /* M3 */", fgl_add_scope(yyvsp[-1].str,0), (int)scan_variable (yyvsp[-1].str), yyvsp[0].str);

      addmap("Let Variable",yyvsp[-1].str,curr_func,yylineno,infilename);
      A4GL_debug ("/*character variable %s*/\n", yyval.str);
    }
 }
  mcnt++;

}
    break;

  case 940:
#line 5173 "fgl.yacc"
    {
start_bind('f',0);
start_bind('O',0);
strcpy(yyval.str,"0");}
    break;

  case 942:
#line 5180 "fgl.yacc"
    {
start_bind('f',yyvsp[0].str);
start_bind('O',yyvsp[0].str);
sprintf(yyval.str,"1");
}
    break;

  case 943:
#line 5186 "fgl.yacc"
    {
int c;
c=add_bind('f',yyvsp[0].str);
c=add_bind('O',yyvsp[0].str);
sprintf(yyval.str,"%d",c); 
}
    break;

  case 944:
#line 5197 "fgl.yacc"
    {
A4GL_lex_printcomment("/*STarted bind %s*/\n",yyvsp[0].str);
start_bind('i',yyvsp[0].str);
A4GL_lex_printcomment("/*STarted bind 2*/\n");
strcpy(yyval.str,"");
}
    break;

  case 945:
#line 5204 "fgl.yacc"
    {
A4GL_lex_printcomment("/* Added */\n");
add_bind('i',yyvsp[0].str);
strcpy(yyval.str,"");
}
    break;

  case 947:
#line 5212 "fgl.yacc"
    {sprintf(yyval.str,"%s.%s",yyvsp[-2].str,yyvsp[-1].str);}
    break;

  case 948:
#line 5215 "fgl.yacc"
    {A4GL_lex_printcomment("/* Variable */\n");}
    break;

  case 949:
#line 5216 "fgl.yacc"
    { A4GL_debug("Got an ibind thru..."); sprintf(yyval.str,"%s\n%s",yyvsp[-2].str,yyvsp[0].str); }
    break;

  case 951:
#line 5218 "fgl.yacc"
    {sprintf(yyval.str,"\"%s\"",yyvsp[0].str);}
    break;

  case 952:
#line 5219 "fgl.yacc"
    {sprintf(yyval.str,"\"%s\"",yyvsp[0].str);}
    break;

  case 953:
#line 5222 "fgl.yacc"
    {
start_bind('o',yyvsp[0].str);
}
    break;

  case 954:
#line 5225 "fgl.yacc"
    {
add_bind('o',yyvsp[0].str);
strcpy(yyval.str,"");
}
    break;

  case 955:
#line 5231 "fgl.yacc"
    {
	addmap("OBIND",yyvsp[0].str,curr_func,yylineno,infilename);
	}
    break;

  case 956:
#line 5234 "fgl.yacc"
    { A4GL_debug("Got an obind thru..."); sprintf(yyval.str,"%s\n%s",yyvsp[-2].str,yyvsp[0].str); }
    break;

  case 957:
#line 5238 "fgl.yacc"
    {
A4GL_lex_printcomment("/* start obind with  %s*/\n",yyvsp[0].str);
A4GL_debug("obind_var_let_list ---> %s\n",yyvsp[0].str);
start_bind('o',yyvsp[0].str);
}
    break;

  case 958:
#line 5243 "fgl.yacc"
    {
A4GL_lex_printcomment("/* add to obind %s */\n",yyvsp[0].str);
add_bind('o',yyvsp[0].str);
A4GL_debug("obind_var_let_list ---> %s\n",yyvsp[0].str);
strcpy(yyval.str,"");
}
    break;

  case 959:
#line 5251 "fgl.yacc"
    {
A4GL_lex_printcomment("/* Read variable %s*/\n",yyvsp[0].str);
}
    break;

  case 960:
#line 5256 "fgl.yacc"
    {
    A4GL_lex_printcomment("/* use_arr_var */\n");
    start_arr_bind('o',yyvsp[0].str);
    A4GL_lex_printcomment("/* use_arr_var complete */\n");
}
    break;

  case 961:
#line 5263 "fgl.yacc"
    {
start_bind('O',yyvsp[0].str);
}
    break;

  case 962:
#line 5266 "fgl.yacc"
    {
               add_bind('O',yyvsp[0].str);
               strcpy(yyval.str,"");
}
    break;

  case 967:
#line 5279 "fgl.yacc"
    {
  int type,arrsize,size,level;
  char arrbuff[256];
  A4GL_lex_printcomment("/*..array_r_varid..*/");

//printf("Got array %s %s\n",$<str>1,$<str>3);
if (get_variable_dets (yyvsp[-3].str,&type,&arrsize,&size,&level,arrbuff)>=0) {
	// Its a variable
	//printf("gvd = true\n");
  sprintf(yyval.str,"%s[%s]",yyvsp[-3].str,subtract_one(yyvsp[-1].str));
} else {
	// Its an sql identifier or similar
	//printf("gvd = false\n");
  sprintf(yyval.str,"%s[%s]",yyvsp[-3].str,yyvsp[-1].str);
}
//printf("All done - ARRAY (array_r_varid) : %s\n",$<str>$);
}
    break;

  case 968:
#line 5298 "fgl.yacc"
    {
A4GL_lex_printcomment("/*STarted bind %s*/\n",yyvsp[0].str);
start_bind('N',yyvsp[0].str);
A4GL_lex_printcomment("/*STarted bind 2*/\n");
strcpy(yyval.str,"");
}
    break;

  case 969:
#line 5305 "fgl.yacc"
    {
A4GL_lex_printcomment("/* Added */\n");
add_bind('N',yyvsp[0].str);
strcpy(yyval.str,"");
}
    break;

  case 970:
#line 5312 "fgl.yacc"
    {
		strcpy(yyval.str,yyvsp[0].str);
	}
    break;

  case 971:
#line 5315 "fgl.yacc"
    {
			sprintf(yyval.str,"%s\n%s",yyvsp[-2].str,yyvsp[0].str);
		}
    break;

  case 972:
#line 5329 "fgl.yacc"
    {
form_attrib.iswindow=1;
print_open_window(yyvsp[-5].str,yyvsp[-1].str);
sprintf(yyval.str,"open window");
}
    break;

  case 977:
#line 5346 "fgl.yacc"
    {
	print_niy("OPEN_STATUSBOX");
}
    break;

  case 978:
#line 5351 "fgl.yacc"
    {
addmap("Call Formhandler",yyvsp[0].str,curr_func,yylineno,infilename); 
}
    break;

  case 979:
#line 5357 "fgl.yacc"
    {
		print_open_form(yyvsp[0].str,yyvsp[-1].str,yyvsp[-1].str);
		}
    break;

  case 981:
#line 5364 "fgl.yacc"
    { form_attrib.iswindow=0;strcpy(yyval.str,"A4GL_open_form(%s);"); }
    break;

  case 982:
#line 5369 "fgl.yacc"
    {sprintf(yyval.str,"A4GL_open_gui_form(%%s,%s,%s,%s,hnd_e_%s,hnd_c_%s);",yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[0].str,yyvsp[0].str);}
    break;

  case 983:
#line 5372 "fgl.yacc"
    {strcpy(yyval.str,"0,0");}
    break;

  case 984:
#line 5373 "fgl.yacc"
    {sprintf(yyval.str,"%s,2",yyvsp[-5].str);}
    break;

  case 985:
#line 5376 "fgl.yacc"
    {strcpy(yyval.str,"\"\"");}
    break;

  case 986:
#line 5377 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 987:
#line 5380 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 988:
#line 5381 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 989:
#line 5386 "fgl.yacc"
    {
print_open_session(yyvsp[-3].str,yyvsp[-1].str,yyvsp[0].str);

}
    break;

  case 990:
#line 5393 "fgl.yacc"
    {
	print_open_cursor(yyvsp[0].str,"0");
}
    break;

  case 991:
#line 5396 "fgl.yacc"
    {
	print_open_cursor(yyvsp[-3].str,yyvsp[0].str); /* CHANGED from $<str>4 */
}
    break;

  case 992:
#line 5402 "fgl.yacc"
    {sprintf(yyval.str,"0,0");}
    break;

  case 993:
#line 5404 "fgl.yacc"
    {sprintf(yyval.str,"%s, %s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 994:
#line 5406 "fgl.yacc"
    {sprintf(yyval.str,"%s, %s",yyvsp[-3].str,yyvsp[0].str);}
    break;

  case 995:
#line 5408 "fgl.yacc"
    {sprintf(yyval.str,"%s, %s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 996:
#line 5411 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 997:
#line 5411 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 998:
#line 5412 "fgl.yacc"
    {strcpy(yyval.str,"2");}
    break;

  case 999:
#line 5417 "fgl.yacc"
    {
	print_open_session(yyvsp[-1].str,yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 1000:
#line 5425 "fgl.yacc"
    {strcpy(yyval.str,"\"default_conn\"");}
    break;

  case 1001:
#line 5426 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1002:
#line 5431 "fgl.yacc"
    {sprintf(yyval.str,"0,0");}
    break;

  case 1003:
#line 5433 "fgl.yacc"
    {sprintf(yyval.str,"%s, %s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1004:
#line 5435 "fgl.yacc"
    {sprintf(yyval.str,"%s, %s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1008:
#line 5452 "fgl.yacc"
    {
print_options('C',yyvsp[0].str);
}
    break;

  case 1009:
#line 5455 "fgl.yacc"
    {
print_options('E',yyvsp[0].str);
}
    break;

  case 1010:
#line 5458 "fgl.yacc"
    {
print_options('F',yyvsp[0].str);
}
    break;

  case 1011:
#line 5461 "fgl.yacc"
    {
//A4GL_lex_printc("A4GL_set_option_value('M',%s);\n",$<str>2);
print_options('M',yyvsp[0].str);
}
    break;

  case 1012:
#line 5465 "fgl.yacc"
    {
print_options('m',yyvsp[0].str);
}
    break;

  case 1013:
#line 5468 "fgl.yacc"
    {
print_options('P',yyvsp[0].str);
}
    break;

  case 1014:
#line 5471 "fgl.yacc"
    {
print_options('A',yyvsp[0].str);
iskey=0;
}
    break;

  case 1015:
#line 5475 "fgl.yacc"
    {
print_options('D',yyvsp[0].str);
iskey=0;
}
    break;

  case 1016:
#line 5479 "fgl.yacc"
    {
print_options('I',yyvsp[0].str);
iskey=0;
}
    break;

  case 1017:
#line 5483 "fgl.yacc"
    {
print_options('N',yyvsp[0].str);
}
    break;

  case 1018:
#line 5486 "fgl.yacc"
    {
print_options('p',yyvsp[0].str);
iskey=0;
}
    break;

  case 1019:
#line 5490 "fgl.yacc"
    {
print_options('H',yyvsp[0].str);
}
    break;

  case 1020:
#line 5493 "fgl.yacc"
    { print_set_helpfile(yyvsp[0].str); }
    break;

  case 1021:
#line 5494 "fgl.yacc"
    { print_set_langfile(yyvsp[0].str); }
    break;

  case 1022:
#line 5495 "fgl.yacc"
    {
print_options('d',yyvsp[0].str);
}
    break;

  case 1023:
#line 5498 "fgl.yacc"
    {
print_options('i',yyvsp[0].str);
}
    break;

  case 1024:
#line 5501 "fgl.yacc"
    {
print_options('W',"1");
}
    break;

  case 1025:
#line 5504 "fgl.yacc"
    {
print_options('W',"0");
}
    break;

  case 1026:
#line 5507 "fgl.yacc"
    {
print_options('f',"1");
}
    break;

  case 1027:
#line 5510 "fgl.yacc"
    {
print_options('f',"0");
}
    break;

  case 1028:
#line 5513 "fgl.yacc"
    {
print_options('S',"1");
}
    break;

  case 1029:
#line 5516 "fgl.yacc"
    {
print_options('S',"0");
}
    break;

  case 1030:
#line 5533 "fgl.yacc"
    {
	print_prepare(yyvsp[-2].str,yyvsp[0].str);
	addmap("Prepare",yyvsp[-2].str,curr_func,yylineno,infilename);
	print_undo_use(yyvsp[-4].str);
}
    break;

  case 1033:
#line 5543 "fgl.yacc"
    {

print_execute(yyvsp[0].str,0);

addmap("Execute",yyvsp[0].str,curr_func,yylineno,infilename);
}
    break;

  case 1034:
#line 5549 "fgl.yacc"
    {
	addmap("Execute",yyvsp[-2].str,curr_func,yylineno,infilename);
	print_execute(yyvsp[-2].str,1);
	}
    break;

  case 1035:
#line 5553 "fgl.yacc"
    {
		print_execute_immediate(yyvsp[0].str);
	}
    break;

  case 1037:
#line 5573 "fgl.yacc"
    {
                push_blockcommand("PROMPT");
	A4GL_new_events();
	print_prompt_1(yyvsp[-6].str,yyvsp[-4].str,yyvsp[-1].str,yyvsp[0].str,atoi(yyvsp[-2].str)) ;
}
    break;

  case 1038:
#line 5578 "fgl.yacc"
    {
		if (strcmp(yyvsp[-6].str,"1")==0) {
			print_prompt_forchar();
                }
		add_continue_blockcommand ("PROMPT");
		print_prompt_end(yyvsp[-5].str);
                pop_blockcommand("PROMPT");
		A4GL_drop_events();
                A4GL_lex_printcomment("/* END OF PROMPT */");
                }
    break;

  case 1039:
#line 5591 "fgl.yacc"
    {sprintf(yyval.str,"0");}
    break;

  case 1040:
#line 5592 "fgl.yacc"
    {sprintf(yyval.str,yyvsp[0].str);}
    break;

  case 1041:
#line 5596 "fgl.yacc"
    {
		print_niy("GUI PROMPT");
	}
    break;

  case 1042:
#line 5601 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 1043:
#line 5602 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 1044:
#line 5606 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1048:
#line 5612 "fgl.yacc"
    {
	A4GL_add_onkey_key(yyvsp[0].str);
	print_onkey_1(yyvsp[0].str);
}
    break;

  case 1049:
#line 5615 "fgl.yacc"
    {
	print_onkey_2_prompt();
}
    break;

  case 1051:
#line 5630 "fgl.yacc"
    {
		start_bind('i',0);
		}
    break;

  case 1052:
#line 5634 "fgl.yacc"
    {
		print_put(yyvsp[-2].str,yyvsp[0].str);
	}
    break;

  case 1053:
#line 5640 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1054:
#line 5641 "fgl.yacc"
    { strcpy(yyval.str,yyvsp[0].str);
A4GL_debug("putlist = %s\n",yyval.str);
}
    break;

  case 1055:
#line 5646 "fgl.yacc"
    {push_gen(PUTVAL,yyvsp[0].str);}
    break;

  case 1056:
#line 5647 "fgl.yacc"
    {push_gen(PUTVAL,yyvsp[0].str); sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1057:
#line 5650 "fgl.yacc"
    {
	char buff[256];	
	strcpy(buff,yyvsp[0].sql_string);
	A4GL_debug("put buff=%s\n",buff);
	if (buff[0]!='\''&&strncmp(buff,"?",1)!=0&&strncmp(buff," :",2)!=0) {
		A4GL_debug("Got : %s - expecting '..', : or ?",buff);
 		a4gl_yyerror("Put values must be variables, strings or 'NULL'");
		YYERROR;
	}

	A4GL_add_put_string(buff);
	strcpy(yyval.str,buff);

}
    break;

  case 1059:
#line 5678 "fgl.yacc"
    {
addmap("Start Report",yyvsp[-1].str,curr_func,yylineno,infilename);
print_start_report("P","acl_getenv(\"DBPRINT\")",yyvsp[-1].str);
}
    break;

  case 1060:
#line 5683 "fgl.yacc"
    {
addmap("Start Report",yyvsp[-2].str,curr_func,yylineno,infilename);
print_start_report("F",yyvsp[0].str,yyvsp[-2].str);
}
    break;

  case 1061:
#line 5688 "fgl.yacc"
    {
addmap("Start Report",yyvsp[-2].str,curr_func,yylineno,infilename);
print_start_report("P",yyvsp[0].str,yyvsp[-2].str);
}
    break;

  case 1062:
#line 5693 "fgl.yacc"
    {
addmap("Start Report",yyvsp[0].str,curr_func,yylineno,infilename);
print_start_report("","\"\"",yyvsp[0].str);
}
    break;

  case 1068:
#line 5715 "fgl.yacc"
    {
addmap("Output to report",yyvsp[-5].str,curr_func,yylineno,infilename);
print_output_to_report(yyvsp[-5].str,yyvsp[-1].str); 
}
    break;

  case 1069:
#line 5722 "fgl.yacc"
    {
addmap("Finish Report",yyvsp[0].str,curr_func,yylineno,infilename);
print_finish_report(yyvsp[0].str);
}
    break;

  case 1070:
#line 5731 "fgl.yacc"
    {
addmap("Finish Report",yyvsp[0].str,curr_func,yylineno,infilename);
print_terminate_report(yyvsp[0].str);
}
    break;

  case 1071:
#line 5737 "fgl.yacc"
    { strcpy(yyval.str,yyvsp[0].str); }
    break;

  case 1072:
#line 5739 "fgl.yacc"
    {
	print_format_every_row();
}
    break;

  case 1076:
#line 5750 "fgl.yacc"
    { push_report_block("FIRST",'P');}
    break;

  case 1077:
#line 5751 "fgl.yacc"
    {
rep_struct.lines_in_first_header=if_print_stack[0][0];
pdf_rep_struct.lines_in_first_header=if_print_stack[0][0];
print_rep_ret(0);
}
    break;

  case 1078:
#line 5757 "fgl.yacc"
    { push_report_block("TRAILER",'T');
if_print_stack[0][0]=0;
if_print_stack[0][1]=0;
}
    break;

  case 1079:
#line 5761 "fgl.yacc"
    {
rep_struct.lines_in_trailer=if_print_stack[0][0];
pdf_rep_struct.lines_in_trailer=if_print_stack[0][0];
print_rep_ret(0);
}
    break;

  case 1080:
#line 5767 "fgl.yacc"
    { push_report_block("HEADER",'p');}
    break;

  case 1081:
#line 5768 "fgl.yacc"
    {
rep_struct.lines_in_header=if_print_stack[0][0];
pdf_rep_struct.lines_in_header=if_print_stack[0][0];
print_rep_ret(0);}
    break;

  case 1082:
#line 5773 "fgl.yacc"
    { push_report_block("EVERY",'E');}
    break;

  case 1083:
#line 5774 "fgl.yacc"
    {print_rep_ret(0);}
    break;

  case 1084:
#line 5776 "fgl.yacc"
    { push_report_block("LAST",'L');}
    break;

  case 1085:
#line 5777 "fgl.yacc"
    {print_rep_ret(0);}
    break;

  case 1086:
#line 5778 "fgl.yacc"
    {
int a;
char buff[80];
A4GL_debug("rordcnt=%d",rordcnt);
a=scan_orderby(yyvsp[0].str,rordcnt);
if (a<0) {
   sprintf(buff,"%s is not in the order by list",yyvsp[0].str);
   a4gl_yyerror(buff);
	YYERROR;
}
sprintf(buff,"%d",a+1);
push_report_block(buff,'B');
set_curr_block(a+1);
}
    break;

  case 1087:
#line 5792 "fgl.yacc"
    {print_rep_ret(0);}
    break;

  case 1088:
#line 5794 "fgl.yacc"
    { 
int a;
char buff[80];

A4GL_debug("rordcnt=%d",rordcnt);
a=scan_orderby(yyvsp[0].str,rordcnt);
if (a<0) {
   sprintf(buff,"%s is not in the order by list",yyvsp[0].str);
   a4gl_yyerror(buff);
	YYERROR;
}

sprintf(buff,"%d",a+1);
push_report_block(buff,'A');
set_curr_block(a+1);

}
    break;

  case 1089:
#line 5811 "fgl.yacc"
    {print_rep_ret(0);}
    break;

  case 1096:
#line 5823 "fgl.yacc"
    {start_state("skip",1);}
    break;

  case 1097:
#line 5823 "fgl.yacc"
    {
	print_need_lines();
	start_state("skip",0);
}
    break;

  case 1098:
#line 5829 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 1099:
#line 5829 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 1100:
#line 5832 "fgl.yacc"
    {start_state("KWLINE",1);}
    break;

  case 1101:
#line 5832 "fgl.yacc"
    {
double n;
char buff[256];
strcpy(buff,yyvsp[0].str);
n=atof(yyvsp[-2].str);
if (buff[0]=='1') {
	print_skip_lines(n);
	if (if_print_stack_cnt==0) if_print_section[0]=0;
	if (get_curr_report_stack_whytype()=='T') {
		if_print_stack[if_print_stack_cnt][if_print_section[if_print_stack_cnt]]+=(int)n;
	}
} else {
	if (rep_type!=REP_TYPE_PDF) { a4gl_yyerror("SKIP BY is only in PDF reports"); YYERROR; } print_skip_by(n);
}
start_state("KWLINE",0); 
}
    break;

  case 1102:
#line 5848 "fgl.yacc"
    { print_skip_top(); }
    break;

  case 1103:
#line 5849 "fgl.yacc"
    { print_niy("FONT SIZE"); }
    break;

  case 1104:
#line 5850 "fgl.yacc"
    {
		double n;
			n=atof(yyvsp[0].str);
			if (rep_type!=REP_TYPE_PDF) {
				a4gl_yyerror("SKIP BY is only in PDF reports");
				YYERROR;
			}
			print_skip_by(n);
		}
    break;

  case 1105:
#line 5859 "fgl.yacc"
    {
			if (rep_type!=REP_TYPE_PDF) {
				a4gl_yyerror("SKIP TO is only in PDF reports");
				YYERROR;
			}
			print_skip_to(yyvsp[0].str);
		}
    break;

  case 1106:
#line 5871 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1112:
#line 5882 "fgl.yacc"
    {
	print_niy("PRINT AT...");
}
    break;

  case 1113:
#line 5887 "fgl.yacc"
    {
	char wt;
	print_report_print(0,yyvsp[0].str,0);
	wt=get_curr_report_stack_whytype();
	if (strcmp(yyvsp[0].str,"0")==0) {
		if (wt=='P'||wt=='p'||wt=='T') { /* Page header or trailer */
			if (isin_command("WHILE")||isin_command("FOR")) {
				a4gl_yyerror("You can't print within a loop in a PAGE HEADER or PAGE TRAILER");
				YYERROR;
			}
		}
	}
	if (strcmp(yyvsp[0].str,"0")==0) {
			if (if_print_stack_cnt==0) if_print_section[0]=0;
		if (get_curr_report_stack_whytype()=='T') {
			if_print_stack[if_print_stack_cnt][if_print_section[if_print_stack_cnt]]+=1;
		}
	}
}
    break;

  case 1114:
#line 5907 "fgl.yacc"
    { 
	print_report_print_file(yyvsp[-1].str,yyvsp[0].str);
}
    break;

  case 1115:
#line 5912 "fgl.yacc"
    { 
	print_report_print_img(yyvsp[-1].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 1116:
#line 5918 "fgl.yacc"
    { strcpy(yyval.str,A4GL_get_default_scaling());}
    break;

  case 1117:
#line 5919 "fgl.yacc"
    { strcpy(yyval.str,yyvsp[0].str); strcat(yyval.str,yyvsp[0].str); }
    break;

  case 1118:
#line 5920 "fgl.yacc"
    {sprintf(yyval.str,"%s %s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1119:
#line 5924 "fgl.yacc"
    {strcpy(yyval.str,"tiff");}
    break;

  case 1120:
#line 5925 "fgl.yacc"
    {strcpy(yyval.str,"gif");}
    break;

  case 1121:
#line 5926 "fgl.yacc"
    {strcpy(yyval.str,"png");}
    break;

  case 1122:
#line 5927 "fgl.yacc"
    {strcpy(yyval.str,"jpeg");}
    break;

  case 1123:
#line 5931 "fgl.yacc"
    {
	int vtype;
	vtype=scan_variable(yyvsp[0].str);
	if (vtype!=11&&vtype!=12) {
	a4gl_yyerror("Only Blobs may be printed...");
	YYERROR;
	}
}
    break;

  case 1124:
#line 5941 "fgl.yacc"
    {
strcpy(yyval.str,"0");
}
    break;

  case 1125:
#line 5943 "fgl.yacc"
    {
strcpy(yyval.str,"1");
}
    break;

  case 1126:
#line 5948 "fgl.yacc"
    {
	print_report_print(1,0,yyvsp[0].str);
	}
    break;

  case 1127:
#line 5951 "fgl.yacc"
    {
	print_report_print(1,0,yyvsp[0].str); /* changed from $<str>1 */
}
    break;

  case 1128:
#line 5956 "fgl.yacc"
    {
	strcpy(yyval.str,yyvsp[0].str); 
	}
    break;

  case 1129:
#line 5963 "fgl.yacc"
    {
int a;
a=add_report_agg('S',yyvsp[-2].ptr,yyvsp[0].ptr,racnt);
sprintf(yyval.str,"A4GL_push_double(_g%d);\n",racnt);
racnt+=a;
}
    break;

  case 1130:
#line 5970 "fgl.yacc"
    {
int a;
a=add_report_agg('C',0,yyvsp[0].ptr,racnt);
sprintf(yyval.str,"A4GL_push_int(_g%d);\n",racnt);
racnt+=a;
}
    break;

  case 1131:
#line 5977 "fgl.yacc"
    {
int a;
a=add_report_agg('C',0,yyvsp[0].ptr,racnt);
sprintf(yyval.str,"A4GL_push_int(_g%d);\n",racnt);
racnt+=a;
}
    break;

  case 1132:
#line 5986 "fgl.yacc"
    {
int a;
a=add_report_agg('P',yyvsp[-2].ptr,yyvsp[0].ptr,racnt);
sprintf(yyval.str,"A4GL_push_double((double)_g%d/(double)_g%d);\n",racnt,racnt+1);
racnt+=a;
}
    break;

  case 1133:
#line 5993 "fgl.yacc"
    {
int a;
a=add_report_agg('A',yyvsp[-2].ptr,yyvsp[0].ptr,racnt);
sprintf(yyval.str,"A4GL_push_double(_g%d/(double)_g%d);\n",racnt,racnt+1);
racnt+=a;
}
    break;

  case 1134:
#line 6000 "fgl.yacc"
    {
int a;
a=add_report_agg('A',yyvsp[-2].ptr,yyvsp[0].ptr,racnt);
sprintf(yyval.str,"A4GL_push_double(_g%d/_g%d);\n",racnt,racnt+1);
racnt+=a;
}
    break;

  case 1135:
#line 6007 "fgl.yacc"
    {
int a;
a=add_report_agg('N',yyvsp[-2].ptr,yyvsp[0].ptr,racnt);
sprintf(yyval.str,"A4GL_push_double(_g%d);\n",racnt);
racnt+=a;
}
    break;

  case 1136:
#line 6014 "fgl.yacc"
    {
int a;
a=add_report_agg('X',yyvsp[-2].ptr,yyvsp[0].ptr,racnt);
sprintf(yyval.str,"A4GL_push_double(_g%d);\n",racnt);
racnt+=a;
}
    break;

  case 1141:
#line 6027 "fgl.yacc"
    {rep_struct.left_margin=atoi(yyvsp[0].str);}
    break;

  case 1142:
#line 6028 "fgl.yacc"
    {rep_struct.right_margin=atoi(yyvsp[0].str);}
    break;

  case 1143:
#line 6029 "fgl.yacc"
    {rep_struct.top_margin=atoi(yyvsp[0].str);}
    break;

  case 1144:
#line 6030 "fgl.yacc"
    {rep_struct.bottom_margin=atoi(yyvsp[0].str);}
    break;

  case 1145:
#line 6031 "fgl.yacc"
    {rep_struct.page_length=atoi(yyvsp[0].str);}
    break;

  case 1146:
#line 6032 "fgl.yacc"
    { rep_struct.output_mode='P';strcpy(rep_struct.output_loc,"acl_getenv(\"DBPRINT\")");}
    break;

  case 1147:
#line 6033 "fgl.yacc"
    {rep_struct.output_mode='F';strcpy(rep_struct.output_loc,yyvsp[0].str);}
    break;

  case 1148:
#line 6034 "fgl.yacc"
    {rep_struct.output_mode='F';strcpy(rep_struct.output_loc,yyvsp[0].str);}
    break;

  case 1149:
#line 6035 "fgl.yacc"
    {rep_struct.output_mode='P';strcpy(rep_struct.output_loc,yyvsp[0].str);}
    break;

  case 1150:
#line 6036 "fgl.yacc"
    {strcpy(rep_struct.top_of_page,yyvsp[0].str);}
    break;

  case 1153:
#line 6042 "fgl.yacc"
    {sprintf(yyval.str,"-%f",atof(yyvsp[-1].str));}
    break;

  case 1154:
#line 6043 "fgl.yacc"
    {sprintf(yyval.str,"-%f",atof(yyvsp[-1].str)*72.0); }
    break;

  case 1155:
#line 6044 "fgl.yacc"
    {sprintf(yyval.str,"-%f",atof(yyvsp[-1].str)*2.83465);}
    break;

  case 1156:
#line 6045 "fgl.yacc"
    {sprintf(yyval.str,"%f",atof(yyvsp[0].str));}
    break;

  case 1161:
#line 6054 "fgl.yacc"
    {pdf_rep_struct.left_margin=atof(yyvsp[0].str);A4GL_debug("Left margin=%s\n",yyvsp[0].str);}
    break;

  case 1162:
#line 6055 "fgl.yacc"
    {pdf_rep_struct.right_margin=atof(yyvsp[0].str);}
    break;

  case 1163:
#line 6056 "fgl.yacc"
    {pdf_rep_struct.top_margin=atof(yyvsp[0].str);}
    break;

  case 1164:
#line 6057 "fgl.yacc"
    {pdf_rep_struct.bottom_margin=atof(yyvsp[0].str);}
    break;

  case 1165:
#line 6058 "fgl.yacc"
    {pdf_rep_struct.page_length=atof(yyvsp[0].str);}
    break;

  case 1166:
#line 6059 "fgl.yacc"
    {pdf_rep_struct.page_width=atof(yyvsp[0].str);}
    break;

  case 1167:
#line 6060 "fgl.yacc"
    {strcpy(pdf_rep_struct.font_name,yyvsp[0].str);}
    break;

  case 1168:
#line 6061 "fgl.yacc"
    {pdf_rep_struct.font_size=atof(yyvsp[0].str);}
    break;

  case 1169:
#line 6063 "fgl.yacc"
    {pdf_rep_struct.paper_size=1;}
    break;

  case 1170:
#line 6064 "fgl.yacc"
    {pdf_rep_struct.paper_size=2;}
    break;

  case 1171:
#line 6065 "fgl.yacc"
    {pdf_rep_struct.paper_size=3;}
    break;

  case 1172:
#line 6066 "fgl.yacc"
    {pdf_rep_struct.paper_size=5;}
    break;

  case 1173:
#line 6068 "fgl.yacc"
    {pdf_rep_struct.paper_size=-1;}
    break;

  case 1174:
#line 6069 "fgl.yacc"
    {pdf_rep_struct.paper_size=-2;}
    break;

  case 1175:
#line 6070 "fgl.yacc"
    {pdf_rep_struct.paper_size=-3;}
    break;

  case 1176:
#line 6071 "fgl.yacc"
    {pdf_rep_struct.paper_size=-5;}
    break;

  case 1180:
#line 6076 "fgl.yacc"
    {pdf_rep_struct.output_mode='F';strcpy(pdf_rep_struct.output_loc,yyvsp[0].str);}
    break;

  case 1181:
#line 6077 "fgl.yacc"
    {pdf_rep_struct.output_mode='P';strcpy(pdf_rep_struct.output_loc,yyvsp[0].str);}
    break;

  case 1185:
#line 6084 "fgl.yacc"
    {
int a;
set_rep_no_orderby(1);
a=print_bind('O');
print_order_by_type(2,-1);
sprintf(yyval.str,"%d",a);
}
    break;

  case 1186:
#line 6092 "fgl.yacc"
    {
int a;
set_rep_no_orderby(0);
a=print_bind('O');
print_order_by_type(1,a);
sprintf(yyval.str,"%d",a);
A4GL_debug("Order by Gives :%d\n",a);
}
    break;

  case 1187:
#line 6100 "fgl.yacc"
    {
int a;
set_rep_no_orderby(0);
a=print_bind('O');
print_order_by_type(2,a);
sprintf(yyval.str,"%d",a);
A4GL_debug("Order by Gives :%d\n",a);
}
    break;

  case 1188:
#line 6112 "fgl.yacc"
    { 
		rep_type=REP_TYPE_NORMAL; 
		clr_function_constants (); 
		clr_variable(); 
		lastlineno=yylineno; 
		init_report_structure(&rep_struct); 
		}
    break;

  case 1189:
#line 6121 "fgl.yacc"
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

  case 1190:
#line 6132 "fgl.yacc"
    {
		lastlineno=yylineno;
		}
    break;

  case 1191:
#line 6136 "fgl.yacc"
    {
		print_variables();
		}
    break;

  case 1192:
#line 6140 "fgl.yacc"
    {
		print_report_2(0,yyvsp[0].str);
		rordcnt=atoi(yyvsp[0].str);
	 A4GL_debug("SET rordcnt=%d %s",rordcnt,yyvsp[0].str);
		}
    break;

  case 1193:
#line 6146 "fgl.yacc"
    {
		print_report_ctrl();
		}
    break;

  case 1194:
#line 6151 "fgl.yacc"
    {
		pop_blockcommand("REPORT");
		print_report_end() ;
		}
    break;

  case 1195:
#line 6159 "fgl.yacc"
    { strcpy(yyval.str,"");
	yyval.ptr=0;
}
    break;

  case 1196:
#line 6162 "fgl.yacc"
    {
	yyval.ptr=yyvsp[0].ptr;
//sprintf($<str>$,"%s", $<str>2);
}
    break;

  case 1197:
#line 6171 "fgl.yacc"
    {
if (!in_command("REPORT")) {
	a4gl_yyerror("PAUSE can only be used in reportes");
	YYERROR;
        }

print_pause(yyvsp[0].str) ;
}
    break;

  case 1198:
#line 6182 "fgl.yacc"
    {strcpy(yyval.str,"\"\"");}
    break;

  case 1200:
#line 6189 "fgl.yacc"
    {
rep_type=REP_TYPE_PDF;
clr_function_constants();
clr_variable(); 
lastlineno=yylineno; 
pdf_init_report_structure(&pdf_rep_struct);
}
    break;

  case 1201:
#line 6197 "fgl.yacc"
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

  case 1202:
#line 6207 "fgl.yacc"
    {
lastlineno=yylineno;
}
    break;

  case 1203:
#line 6210 "fgl.yacc"
    {
	print_variables();
}
    break;

  case 1204:
#line 6214 "fgl.yacc"
    {
//print_variables();
resize_paper(&pdf_rep_struct);
	print_report_2(1,yyvsp[0].str);
A4GL_debug("SET rordcnt=%d (%s)",rordcnt,yyvsp[0].str);
	rordcnt=atoi(yyvsp[0].str);
}
    break;

  case 1205:
#line 6222 "fgl.yacc"
    {
print_report_ctrl();
}
    break;

  case 1206:
#line 6225 "fgl.yacc"
    {
	pop_blockcommand("REPORT");
	print_report_end();
}
    break;

  case 1207:
#line 6231 "fgl.yacc"
    { strcpy(yyval.str,yyvsp[0].str); }
    break;

  case 1208:
#line 6235 "fgl.yacc"
    {new_counter();
   		addmap("CALL",yyvsp[-1].str,curr_func,yylineno,infilename);
   		}
    break;

  case 1209:
#line 6239 "fgl.yacc"
    {
		sprintf(yyval.str,"%d",get_counter_val());drop_counter();
		}
    break;

  case 1210:
#line 6243 "fgl.yacc"
    {
		print_pdf_call(yyvsp[-5].str,yyvsp[-2].ptr,yyvsp[-1].str);
   		}
    break;

  case 1211:
#line 6247 "fgl.yacc"
    {
	print_returning();
   }
    break;

  case 1212:
#line 6253 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 1213:
#line 6254 "fgl.yacc"
    { strcpy(yyval.str,"rep.right_margin"); }
    break;

  case 1214:
#line 6255 "fgl.yacc"
    { sprintf(yyval.str,"%s",yyvsp[0].str); }
    break;

  case 1215:
#line 6256 "fgl.yacc"
    { sprintf(yyval.str,"%s",yyvsp[0].str); }
    break;

  case 1216:
#line 6261 "fgl.yacc"
    {
print_system_run(0,0);
}
    break;

  case 1217:
#line 6263 "fgl.yacc"
    {
print_system_run(1,yyvsp[0].str);
}
    break;

  case 1218:
#line 6266 "fgl.yacc"
    {
print_system_run(2,0);
}
    break;

  case 1219:
#line 6270 "fgl.yacc"
    {
print_system_run(0,0);
}
    break;

  case 1220:
#line 6273 "fgl.yacc"
    {
print_system_run(0,0);
/* FIXME */
}
    break;

  case 1221:
#line 6280 "fgl.yacc"
    {
	print_exec_sql(yyvsp[0].str);
}
    break;

  case 1222:
#line 6285 "fgl.yacc"
    {sprintf(yyval.str, "%s",yyvsp[0].str);}
    break;

  case 1223:
#line 6286 "fgl.yacc"
    {sprintf(yyval.str,  "%s",yyvsp[0].str);}
    break;

  case 1224:
#line 6287 "fgl.yacc"
    {sprintf(yyval.str,"%s",yyvsp[0].str);}
    break;

  case 1225:
#line 6292 "fgl.yacc"
    { print_exec_sql(yyvsp[0].str); }
    break;

  case 1226:
#line 6293 "fgl.yacc"
    { print_exec_sql(yyvsp[0].sql_string); 
	free(yyvsp[0].sql_string);
}
    break;

  case 1227:
#line 6299 "fgl.yacc"
    {insql=1;}
    break;

  case 1228:
#line 6299 "fgl.yacc"
    {insql=0;}
    break;

  case 1229:
#line 6299 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-6].str," ",yyvsp[-4].str," ",yyvsp[-3].str,yyvsp[-1].sql_string,yyvsp[0].str,0);
		free(yyvsp[-1].sql_string);
	}
    break;

  case 1230:
#line 6304 "fgl.yacc"
    {insql=1;}
    break;

  case 1231:
#line 6304 "fgl.yacc"
    {insql=0;}
    break;

  case 1232:
#line 6304 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-7].str," ",yyvsp[-5].str," ",yyvsp[-4].str,yyvsp[-2].sql_string,yyvsp[-1].str, " ",yyvsp[0].str,0);
		free(yyvsp[-2].sql_string);

}
    break;

  case 1233:
#line 6315 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s %s %s %s ",yyvsp[-6].str,yyvsp[-5].str,yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1234:
#line 6316 "fgl.yacc"
    {
		a4gl_yyerror("You cannot create a database from within Aubit4gl....");
	}
    break;

  case 1235:
#line 6322 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1236:
#line 6324 "fgl.yacc"
    {
if (A4GL_isyes(acl_getenv("A4GL_OMIT_NO_LOG"))) {
	strcpy(yyval.str,"");
} else {
	sprintf(yyval.str," %s ",yyvsp[0].str);
}
}
    break;

  case 1238:
#line 6337 "fgl.yacc"
    {sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1239:
#line 6341 "fgl.yacc"
    {sprintf(yyval.str,"%s ASC",yyvsp[-1].str);}
    break;

  case 1240:
#line 6342 "fgl.yacc"
    {sprintf(yyval.str,"%s DESC",yyvsp[-1].str);}
    break;

  case 1242:
#line 6347 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1243:
#line 6350 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",",yyvsp[0].sql_string,0);
	}
    break;

  case 1244:
#line 6356 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1245:
#line 6359 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1246:
#line 6367 "fgl.yacc"
    {sprintf(yyval.str,"%s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1248:
#line 6374 "fgl.yacc"
    {
	yyval.sql_string=make_sql_string(yyvsp[-2].str," ",yyvsp[-1].str," ",yyvsp[0].sql_string,0);
	print_exec_sql(yyval.sql_string); 
}
    break;

  case 1249:
#line 6378 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("ALTER INDEX ",yyvsp[-1].str," TO CLUSTER",0);
		print_exec_sql(yyval.sql_string); 
		}
    break;

  case 1250:
#line 6382 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("ALTER INDEX ",yyvsp[-1].str," TO NOT CLUSTER",0);
		}
    break;

  case 1251:
#line 6388 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1252:
#line 6391 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",",yyvsp[0].sql_string,0);
	}
    break;

  case 1253:
#line 6400 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1254:
#line 6403 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1255:
#line 6406 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1256:
#line 6409 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1257:
#line 6412 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1258:
#line 6415 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1259:
#line 6418 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1260:
#line 6425 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("ADD ",yyvsp[0].sql_string,0);
	}
    break;

  case 1261:
#line 6428 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("ADD (",yyvsp[-1].sql_string,")",0);
	}
    break;

  case 1262:
#line 6435 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1263:
#line 6438 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string," BEFORE ",yyvsp[0].str,0);
	}
    break;

  case 1264:
#line 6444 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1265:
#line 6447 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",",yyvsp[0].sql_string,0);
	}
    break;

  case 1266:
#line 6454 "fgl.yacc"
    {
		sprintf(yyval.str,"DROP %s",yyvsp[0].str);
	}
    break;

  case 1267:
#line 6457 "fgl.yacc"
    {
		sprintf(yyval.str,"DROP (%s)",yyvsp[-1].str);
	}
    break;

  case 1269:
#line 6465 "fgl.yacc"
    {
		sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);
	}
    break;

  case 1271:
#line 6474 "fgl.yacc"
    {
		sprintf(yyval.str,"MODIFY %s",yyvsp[0].sql_string);
	}
    break;

  case 1272:
#line 6477 "fgl.yacc"
    {
		sprintf(yyval.str,"MODIFY (%s)",yyvsp[-1].sql_string);
	}
    break;

  case 1273:
#line 6483 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1274:
#line 6486 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",",yyvsp[0].sql_string,0);
	}
    break;

  case 1275:
#line 6492 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1276:
#line 6499 "fgl.yacc"
    {strcpy(yyval.str,"LOCK MODE PAGE");}
    break;

  case 1277:
#line 6500 "fgl.yacc"
    {strcpy(yyval.str,"LOCK MODE ROW");}
    break;

  case 1278:
#line 6504 "fgl.yacc"
    {
		sprintf(yyval.str,"MODIFT NEXT SIZE %d",atoi(yyvsp[0].str));
	}
    break;

  case 1279:
#line 6510 "fgl.yacc"
    {
		sprintf(yyval.str,"ADD CONSTRAINT %s",yyvsp[0].sql_string);
	}
    break;

  case 1280:
#line 6513 "fgl.yacc"
    {
		sprintf(yyval.str,"ADD CONSTRAINT (%s)",yyvsp[-1].sql_string);
	}
    break;

  case 1282:
#line 6521 "fgl.yacc"
    {
		sprintf(yyval.str,"ADD CONSTRAINT (%s)",yyvsp[-1].sql_string);
	}
    break;

  case 1283:
#line 6528 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1284:
#line 6531 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",",yyvsp[0].sql_string,0);
	}
    break;

  case 1288:
#line 6549 "fgl.yacc"
    {sprintf(yyval.str,"%s %s /*FIXME */",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1294:
#line 6555 "fgl.yacc"
    { 
	print_set_conn(yyvsp[0].str);
}
    break;

  case 1295:
#line 6558 "fgl.yacc"
    {
	print_set_options("conn",yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 1296:
#line 6561 "fgl.yacc"
    {
	print_set_options("stmt",yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 1297:
#line 6567 "fgl.yacc"
    {strcpy(yyval.str,"\"default\"");}
    break;

  case 1299:
#line 6573 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1301:
#line 6584 "fgl.yacc"
    {
		print_sleep();
	}
    break;

  case 1302:
#line 6598 "fgl.yacc"
    {
		print_sql_commit(0);
		}
    break;

  case 1303:
#line 6607 "fgl.yacc"
    { insql=1;start_bind('i',0);}
    break;

  case 1304:
#line 6607 "fgl.yacc"
    {
	yyval.sql_string=make_sql_string(yyvsp[-4].str," ",yyvsp[-2].str," ",yyvsp[-1].str," ",yyvsp[0].sql_string,0);
}
    break;

  case 1305:
#line 6612 "fgl.yacc"
    {insql=1;}
    break;

  case 1306:
#line 6612 "fgl.yacc"
    {
insql=0;
	//printf("Value = %s\n",$<sql_string>4);
yyval.sql_string=make_sql_string(yyvsp[-4].str," (",yyvsp[-1].sql_string,")",0);}
    break;

  case 1307:
#line 6617 "fgl.yacc"
    {yyval.sql_string=yyvsp[0].sql_string;}
    break;

  case 1308:
#line 6620 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1309:
#line 6622 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1311:
#line 6629 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1312:
#line 6633 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	//printf(" 1. Value = %s\n",$<sql_string>$);
	}
    break;

  case 1313:
#line 6637 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",", yyvsp[0].sql_string,0);
	//printf(" 2. Value = %s\n",$<sql_string>$);
	}
    break;

  case 1314:
#line 6644 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1315:
#line 6647 "fgl.yacc"
    {
		yyval.sql_string=strdup("NULL");
	}
    break;

  case 1316:
#line 6654 "fgl.yacc"
    {
      print_fetch_1();
    }
    break;

  case 1317:
#line 6658 "fgl.yacc"
    {
      print_fetch_2();
    }
    break;

  case 1318:
#line 6662 "fgl.yacc"
    {
      print_fetch_3(yyvsp[-2].str,yyvsp[0].str);
    }
    break;

  case 1319:
#line 6667 "fgl.yacc"
    {sprintf(yyval.str,"%s",yyvsp[0].str);doing_declare=1;}
    break;

  case 1320:
#line 6672 "fgl.yacc"
    {sprintf(yyval.str,"%s, %s",yyvsp[0].str,yyvsp[-1].str);
addmap("Fetch Cursor",yyvsp[0].str,curr_func,yylineno,infilename);
}
    break;

  case 1321:
#line 6676 "fgl.yacc"
    {sprintf(yyval.str,"%s, %d, 1",yyvsp[0].str,FETCH_RELATIVE);

addmap("Fetch Cursor",yyvsp[0].str,curr_func,yylineno,infilename);
}
    break;

  case 1322:
#line 6682 "fgl.yacc"
    {
A4GL_debug("no into\n");
strcpy(yyval.str,"0,0");
}
    break;

  case 1323:
#line 6686 "fgl.yacc"
    {
 A4GL_debug("FETCH INTO  ...");
	/* start_bind('i',0,-1); */
    start_bind('o',0);
}
    break;

  case 1324:
#line 6692 "fgl.yacc"
    {
	int no;
	no=print_bind('o');
	sprintf(yyval.str,"%d,obind",no);
}
    break;

  case 1325:
#line 6699 "fgl.yacc"
    {
A4GL_debug("no into\n");
strcpy(yyval.str,"0,0");
}
    break;

  case 1326:
#line 6703 "fgl.yacc"
    {
 A4GL_debug("FETCH INTO  ...");
	/* start_bind('i',0,-1); */
    start_bind('o',0);
}
    break;

  case 1327:
#line 6708 "fgl.yacc"
    {
/*
int ni;
ni=print_bind('i');
sprintf($<str>$,"%d,ibind",ni);
*/
}
    break;

  case 1328:
#line 6718 "fgl.yacc"
    {
		sprintf(yyval.str,"%d,1",FETCH_ABSOLUTE);}
    break;

  case 1329:
#line 6721 "fgl.yacc"
    {sprintf(yyval.str,"%d,-1",FETCH_ABSOLUTE);}
    break;

  case 1330:
#line 6723 "fgl.yacc"
    {sprintf(yyval.str,"%d,1",FETCH_RELATIVE);}
    break;

  case 1331:
#line 6725 "fgl.yacc"
    {sprintf(yyval.str,"%d,-1",FETCH_RELATIVE);}
    break;

  case 1332:
#line 6727 "fgl.yacc"
    {sprintf(yyval.str,"%d,-1",FETCH_RELATIVE);}
    break;

  case 1333:
#line 6729 "fgl.yacc"
    {sprintf(yyval.str,"%d,0",FETCH_RELATIVE);}
    break;

  case 1334:
#line 6731 "fgl.yacc"
    {sprintf(yyval.str,"%d,A4GL_pop_int()",FETCH_RELATIVE);}
    break;

  case 1335:
#line 6733 "fgl.yacc"
    {sprintf(yyval.str,"%d,A4GL_pop_int()",FETCH_ABSOLUTE);}
    break;

  case 1336:
#line 6739 "fgl.yacc"
    {
 
rm_quotes(yyvsp[0].str);
sprintf(yyval.str," %s %s %s %s ",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str
);}
    break;

  case 1337:
#line 6749 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].str," ",yyvsp[-1].str," ",yyvsp[0].sql_string,0);
		}
    break;

  case 1338:
#line 6756 "fgl.yacc"
    {sprintf(yyval.str,"%s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1340:
#line 6762 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1341:
#line 6765 "fgl.yacc"
    {sprintf(yyval.str,"%s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1344:
#line 6772 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1347:
#line 6777 "fgl.yacc"
    {
print_sql_commit(-1);
}
    break;

  case 1348:
#line 6782 "fgl.yacc"
    {
		print_sql_commit(1);
	}
    break;

  case 1349:
#line 6789 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1350:
#line 6790 "fgl.yacc"
    {
		strcpy(yyval.str,"EXCLUSIVE");
	}
    break;

  case 1351:
#line 6797 "fgl.yacc"
    {
if (strcmp(yyvsp[-1].str,"?")==0) {
	print_init_conn(0);
} else {
	print_init_conn(yyvsp[-1].str);
}
}
    break;

  case 1352:
#line 6808 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1353:
#line 6809 "fgl.yacc"
    {sprintf(yyval.str,"%s@%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1354:
#line 6810 "fgl.yacc"
    {strcpy(yyval.str, A4GL_strip_quotes (yyvsp[0].str));}
    break;

  case 1355:
#line 6813 "fgl.yacc"
    {insql=1;}
    break;

  case 1356:
#line 6813 "fgl.yacc"
    {
print_undo_use(yyvsp[-2].str);
insql=0;strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1357:
#line 6818 "fgl.yacc"
    {
		 A4GL_lex_printcomment("/*  schema */\n");
			print_exec_sql(yyvsp[0].sql_string);
			strcpy(yyval.str,"Schema");
	}
    break;

  case 1358:
#line 6823 "fgl.yacc"
    {
	 A4GL_lex_printcomment("/*  schema  2*/\n");
		print_exec_sql(yyvsp[0].sql_string);
		strcpy(yyval.str,"Schema Element");
	}
    break;

  case 1360:
#line 6829 "fgl.yacc"
    {
		print_exec_sql(yyvsp[0].str);
 	}
    break;

  case 1362:
#line 6833 "fgl.yacc"
    {
	 A4GL_lex_printcomment("/*  delete 1 */\n");
		print_exec_sql_bound(yyvsp[0].str);
		strcpy(yyval.str,"Delete where current...");
	}
    break;

  case 1363:
#line 6838 "fgl.yacc"
    {
	 A4GL_lex_printcomment("/*  delete 2 */\n");
		print_exec_sql_bound(yyvsp[0].sql_string);
		strcpy(yyval.str,"Delete where ...");
	}
    break;

  case 1364:
#line 6843 "fgl.yacc"
    {
		strcpy(yyval.str,"Fetch");
	 A4GL_lex_printcomment("/*  fetch */\n");
	}
    break;

  case 1365:
#line 6847 "fgl.yacc"
    {
	 A4GL_lex_printcomment("/*  insert */\n");
		print_exec_sql_bound(yyvsp[0].sql_string);
		strcpy(yyval.str,"insert");
	}
    break;

  case 1367:
#line 6853 "fgl.yacc"
    {
		print_do_select(yyvsp[0].sql_string);
		strcpy(yyval.str,"select");
	}
    break;

  case 1368:
#line 6857 "fgl.yacc"
    {
		print_exec_sql_bound(yyvsp[0].sql_string);
		strcpy(yyval.str,"update");
	}
    break;

  case 1369:
#line 6865 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s %s %s %s",yyvsp[-6].str,yyvsp[-5].str,yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1370:
#line 6868 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1371:
#line 6870 "fgl.yacc"
    {sprintf(yyval.str," %s ",yyvsp[0].str);}
    break;

  case 1372:
#line 6875 "fgl.yacc"
    {sprintf(yyval.str," %s ",yyvsp[0].str);}
    break;

  case 1375:
#line 6882 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1379:
#line 6889 "fgl.yacc"
    {sprintf(yyval.str," %s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1380:
#line 6892 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1381:
#line 6894 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1383:
#line 6900 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1385:
#line 6906 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1388:
#line 6916 "fgl.yacc"
    {
yyval.sql_string=make_sql_string(yyvsp[-5].str," ",yyvsp[-4].str," ",yyvsp[-3].str," ",yyvsp[-2].str," ",yyvsp[-1].sql_string," ",yyvsp[0].str,0);
}
    break;

  case 1389:
#line 6921 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1390:
#line 6923 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1392:
#line 6929 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1393:
#line 6932 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1395:
#line 6938 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("CHECK(",yyvsp[-1].sql_string,")",0);
	}
    break;

  case 1396:
#line 6946 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s %s",yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1397:
#line 6951 "fgl.yacc"
    {sprintf(yyval.str," %s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1400:
#line 6961 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1402:
#line 6967 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1403:
#line 6973 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1404:
#line 6975 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1406:
#line 6981 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1407:
#line 6986 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1408:
#line 6989 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1409:
#line 6992 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1410:
#line 7000 "fgl.yacc"
    {sprintf(yyval.str," %s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1411:
#line 7002 "fgl.yacc"
    {sprintf(yyval.str," %s",yyvsp[0].str);}
    break;

  case 1412:
#line 7015 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-3].str," ",yyvsp[-2].str," ",yyvsp[-1].str," ",yyvsp[0].sql_string,0);
	}
    break;

  case 1413:
#line 7020 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1415:
#line 7024 "fgl.yacc"
    {
		yyval.sql_string=strdup("");
	}
    break;

  case 1416:
#line 7026 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1417:
#line 7033 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1418:
#line 7036 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-1].sql_string,yyvsp[0].sql_string,0);
	}
    break;

  case 1419:
#line 7042 "fgl.yacc"
    {
		sprintf(yyval.str," %s ",yyvsp[0].str);
		yyval.sql_string=strdup(yyval.str);
	}
    break;

  case 1420:
#line 7046 "fgl.yacc"
    {
		sprintf(yyval.str," %s ",yyvsp[0].str);
		yyval.sql_string=strdup(yyval.str);
	}
    break;

  case 1421:
#line 7050 "fgl.yacc"
    {
		sprintf(yyval.str," %s ",yyvsp[0].str);
		yyval.sql_string=strdup(yyval.str);
	}
    break;

  case 1422:
#line 7054 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1423:
#line 7057 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-3].str," ",yyvsp[-2].str," ",yyvsp[-1].sql_string," ",yyvsp[0].str,0);
	}
    break;

  case 1424:
#line 7065 "fgl.yacc"
    {
yyval.sql_string=make_sql_string(yyvsp[-2].str," ",yyvsp[-1].str," ",yyvsp[0].str,0);
}
    break;

  case 1425:
#line 7072 "fgl.yacc"
    {sprintf(yyval.str," %s",yyvsp[0].str);}
    break;

  case 1428:
#line 7081 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-1].sql_string," ",yyvsp[0].sql_string,0);
	}
    break;

  case 1429:
#line 7087 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1430:
#line 7090 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1431:
#line 7101 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-1].str," ",yyvsp[0].sql_string,0);
	}
    break;

  case 1432:
#line 7108 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("GROUP BY ",yyvsp[0].sql_string,0);
	}
    break;

  case 1433:
#line 7114 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1434:
#line 7117 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",",yyvsp[0].sql_string,0);
	}
    break;

  case 1435:
#line 7124 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("WHERE ",yyvsp[0].sql_string,0);
	}
    break;

  case 1436:
#line 7131 "fgl.yacc"
    {
		sprintf(yyval.str,"%s %s",yyvsp[-1].str,yyvsp[0].str);
	}
    break;

  case 1438:
#line 7138 "fgl.yacc"
    {
		sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);
	}
    break;

  case 1439:
#line 7144 "fgl.yacc"
    {sprintf(yyval.str," %s ", yyvsp[0].str);}
    break;

  case 1440:
#line 7145 "fgl.yacc"
    {sprintf(yyval.str," %s %s ",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1441:
#line 7146 "fgl.yacc"
    {sprintf(yyval.str," %s (%s) ",yyvsp[-3].str,yyvsp[-1].str);}
    break;

  case 1443:
#line 7150 "fgl.yacc"
    {sprintf(yyval.str,"%s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1445:
#line 7155 "fgl.yacc"
    { sprintf(yyval.str," %s,%s ",yyvsp[-2].str,yyvsp[0].str);  }
    break;

  case 1446:
#line 7162 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-3].str," ",yyvsp[-2].sql_string," ",yyvsp[-1].sql_string," ",yyvsp[0].sql_string,0);
	}
    break;

  case 1447:
#line 7167 "fgl.yacc"
    { yyval.sql_string=strdup("");}
    break;

  case 1448:
#line 7168 "fgl.yacc"
    {yyval.sql_string=yyvsp[0].sql_string;}
    break;

  case 1449:
#line 7171 "fgl.yacc"
    {
	yyval.sql_string=strdup("");
}
    break;

  case 1450:
#line 7174 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
}
    break;

  case 1451:
#line 7179 "fgl.yacc"
    {yyval.sql_string=strdup("");}
    break;

  case 1452:
#line 7180 "fgl.yacc"
    {yyval.sql_string=yyvsp[0].sql_string;}
    break;

  case 1453:
#line 7185 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1454:
#line 7188 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string," OR ",yyvsp[0].sql_string,0);
	}
    break;

  case 1455:
#line 7194 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1456:
#line 7197 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string," AND ",yyvsp[0].sql_string,0);
	}
    break;

  case 1457:
#line 7203 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1458:
#line 7206 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-1].str," ",yyvsp[0].sql_string,0);
	}
    break;

  case 1459:
#line 7212 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1460:
#line 7215 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].str,yyvsp[-1].sql_string,yyvsp[0].str,0);
	}
    break;

  case 1461:
#line 7222 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-1].str," ",yyvsp[0].sql_string,0);}
    break;

  case 1462:
#line 7223 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-1].str," ",yyvsp[0].sql_string,0);}
    break;

  case 1463:
#line 7252 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1464:
#line 7254 "fgl.yacc"
    {sprintf(yyval.str," %s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1465:
#line 7258 "fgl.yacc"
    {yyval.sql_string=yyvsp[0].sql_string;}
    break;

  case 1467:
#line 7271 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-4].sql_string," IN (",yyvsp[-1].str,")",0);
	}
    break;

  case 1468:
#line 7274 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string," ",yyvsp[-1].str," ",yyvsp[0].sql_string,0);
	}
    break;

  case 1469:
#line 7277 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-4].sql_string," NOT IN (",yyvsp[-1].str,")",0);
	}
    break;

  case 1470:
#line 7280 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string," ",yyvsp[-1].str," ",yyvsp[0].sql_string,0);
	}
    break;

  case 1472:
#line 7288 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1473:
#line 7291 "fgl.yacc"
    {
		strcpy(yyval.str,yyvsp[0].sql_string);
	}
    break;

  case 1475:
#line 7297 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1477:
#line 7303 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string," ",yyvsp[-1].str," IS NULL",0);
	}
    break;

  case 1478:
#line 7306 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string," ",yyvsp[-1].str," IS NOT NULL",0);
	}
    break;

  case 1479:
#line 7309 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string," ",yyvsp[-1].str," ",yyvsp[0].sql_string,0);
	}
    break;

  case 1480:
#line 7312 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-5].sql_string," ",yyvsp[-4].str," BETWEEN ",yyvsp[-2].sql_string," AND ",yyvsp[0].sql_string,0);
	}
    break;

  case 1481:
#line 7315 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-3].sql_string," ",yyvsp[-2].str," ",yyvsp[-1].sql_string,yyvsp[0].str,0);
	}
    break;

  case 1482:
#line 7318 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-3].sql_string," ",yyvsp[-2].str," ",yyvsp[-1].sql_string,yyvsp[0].str,0);
	}
    break;

  case 1483:
#line 7321 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-3].sql_string," ",yyvsp[-2].str," ",yyvsp[-1].sql_string,yyvsp[0].str,0);
	}
    break;

  case 1484:
#line 7324 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-3].sql_string," ",yyvsp[-2].str," ",yyvsp[-1].sql_string,yyvsp[0].str,0);
	}
    break;

  case 1485:
#line 7329 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-4].sql_string," ",yyvsp[-3].str," MATCHES ",yyvsp[-1].sql_string,yyvsp[0].str,0);
	}
    break;

  case 1487:
#line 7336 "fgl.yacc"
    {strcpy(yyval.str,"!=");}
    break;

  case 1493:
#line 7344 "fgl.yacc"
    {strcpy(yyval.str,"<=");}
    break;

  case 1494:
#line 7345 "fgl.yacc"
    {strcpy(yyval.str,">=");}
    break;

  case 1495:
#line 7350 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1496:
#line 7353 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1497:
#line 7357 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1498:
#line 7363 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1499:
#line 7364 "fgl.yacc"
    {strcpy(yyval.str," ALL ");}
    break;

  case 1500:
#line 7365 "fgl.yacc"
    {strcpy(yyval.str," DISTINCT ");}
    break;

  case 1501:
#line 7366 "fgl.yacc"
    {
		ansi_violation("Use DISTINCT not UNIQUE",0);
		strcpy(yyval.str," DISTINCT ");
	}
    break;

  case 1506:
#line 7386 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1507:
#line 7391 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s %s",yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1508:
#line 7392 "fgl.yacc"
    {strcpy(yyval.str,"SERIAL");}
    break;

  case 1510:
#line 7395 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s %s",yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1514:
#line 7400 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1516:
#line 7403 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1518:
#line 7406 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s %s %s %s",yyvsp[-6].str,yyvsp[-5].str,yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1522:
#line 7411 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1523:
#line 7413 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s %s %s",yyvsp[-5].str,yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1524:
#line 7416 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1525:
#line 7417 "fgl.yacc"
    {
		sprintf(yyval.str,",%s",yyvsp[0].str);
}
    break;

  case 1526:
#line 7424 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1530:
#line 7429 "fgl.yacc"
    {sprintf(yyval.str," %s",yyvsp[0].str);}
    break;

  case 1534:
#line 7445 "fgl.yacc"
    { 
			if (A4GL_escape_quote_owner()) {
				sprintf(yyval.str,"\\\"%s\\\"%s%s", A4GL_strip_quotes (yyvsp[-2].str),yyvsp[-1].str,yyvsp[0].str); addmap("Use Table",yyval.str,curr_func,yylineno,infilename); 
			} else {
				sprintf(yyval.str,"\"%s\"%s%s", A4GL_strip_quotes (yyvsp[-2].str),yyvsp[-1].str,yyvsp[0].str); addmap("Use Table",yyval.str,curr_func,yylineno,infilename); 
			}
	}
    break;

  case 1535:
#line 7452 "fgl.yacc"
    {
		sprintf(yyval.str," %s", A4GL_strip_quotes (yyvsp[0].str));
		addmap("Use Table",yyval.str,curr_func,yylineno,infilename);
	}
    break;

  case 1536:
#line 7456 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str); addmap("Use Table",yyvsp[0].str,curr_func,yylineno,infilename); }
    break;

  case 1537:
#line 7457 "fgl.yacc"
    { sprintf(yyval.str," %s%s%s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str); addmap("Use Table",yyval.str,curr_func,yylineno,infilename); }
    break;

  case 1538:
#line 7461 "fgl.yacc"
    { 
			if (A4GL_escape_quote_owner()) {
				sprintf(yyval.str,"\\\"%s\\\"%s%s", A4GL_strip_quotes (yyvsp[-2].str),yyvsp[-1].str,yyvsp[0].str); addmap("Use Index",yyval.str,curr_func,yylineno,infilename); 
			} else {
				sprintf(yyval.str,"\"%s\"%s%s", A4GL_strip_quotes (yyvsp[-2].str),yyvsp[-1].str,yyvsp[0].str); addmap("Use Index",yyval.str,curr_func,yylineno,infilename); 
			}
	}
    break;

  case 1539:
#line 7468 "fgl.yacc"
    {
		sprintf(yyval.str," %s", A4GL_strip_quotes (yyvsp[0].str));
		addmap("Use Index",yyval.str,curr_func,yylineno,infilename);
	}
    break;

  case 1540:
#line 7472 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str); addmap("Use Index",yyvsp[0].str,curr_func,yylineno,infilename); }
    break;

  case 1541:
#line 7473 "fgl.yacc"
    { sprintf(yyval.str," %s%s%s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str); addmap("Use Index",yyval.str,curr_func,yylineno,infilename); }
    break;

  case 1543:
#line 7491 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1544:
#line 7492 "fgl.yacc"
    {sprintf(yyval.str,"[%s]",yyvsp[-1].str);}
    break;

  case 1545:
#line 7493 "fgl.yacc"
    {sprintf(yyval.str,"[%s,%s]",yyvsp[-3].str,yyvsp[-1].str);}
    break;

  case 1546:
#line 7497 "fgl.yacc"
    {
		strcpy(yyval.str,yyvsp[0].str);
	}
    break;

  case 1547:
#line 7500 "fgl.yacc"
    {
		strcpy(yyval.str,yyvsp[0].str);
	}
    break;

  case 1548:
#line 7506 "fgl.yacc"
    { 
addmap("Use Column",yyvsp[-1].str,curr_func,yylineno,infilename);
sprintf(yyval.str,"%s%s",yyvsp[-1].str,yyvsp[0].str);
}
    break;

  case 1549:
#line 7511 "fgl.yacc"
    {
sprintf(yyval.str,"%s.%s%s",yyvsp[-3].str,yyvsp[-1].str,yyvsp[0].str);
addmap("Use Column",yyval.str,curr_func,yylineno,infilename);
}
    break;

  case 1550:
#line 7516 "fgl.yacc"
    {
sprintf(yyval.str,"%s.%s",yyvsp[-2].str,yyvsp[0].str);
addmap("Use Column",yyval.str,curr_func,yylineno,infilename);
}
    break;

  case 1552:
#line 7527 "fgl.yacc"
    {
	strcpy(yyval.str,convstrsql(yyvsp[0].str));
 A4GL_debug("Set $<str>$ to %s\n",yyval.str);
}
    break;

  case 1557:
#line 7542 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1558:
#line 7545 "fgl.yacc"
    {
char *ptr;
ptr=acl_getenv("SQL_CURRENT_FUNCTION");
if (ptr!=0) { if (strlen(ptr)==0) ptr=0; }

if (ptr) {
	sprintf(yyval.str," %s(%s) ",ptr,yyvsp[0].str);
} else {
	sprintf(yyval.str," %s %s ",yyvsp[-1].str,yyvsp[0].str);
}
}
    break;

  case 1559:
#line 7558 "fgl.yacc"
    {
//char *ptr;

//ptr=acl_getenv("SQL_CURRENT_FUNCTION");

//if (ptr!=0) { if (strlen(ptr)==0) ptr=0; }

//if (ptr) {
	sprintf(yyval.str,"'%s','%s'","YEAR","SECOND");
//} else {
	strcpy(yyval.str," YEAR TO SECOND ");
//}
	strcpy(yyval.str,"");
}
    break;

  case 1560:
#line 7573 "fgl.yacc"
    {
char *ptr;
ptr=acl_getenv("SQL_CURRENT_FUNCTION");
if (ptr!=0) { if (strlen(ptr)==0) ptr=0; }
if (ptr) {
	sprintf(yyval.str,"'%s','%s'",yyvsp[-2].str,yyvsp[0].str);
} else {
	sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);
}
}
    break;

  case 1561:
#line 7585 "fgl.yacc"
    {strcpy(yyval.str,"1,10");}
    break;

  case 1562:
#line 7587 "fgl.yacc"
    {sprintf(yyval.str," %s ,%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1563:
#line 7590 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 1564:
#line 7590 "fgl.yacc"
    {strcpy(yyval.str,"2");}
    break;

  case 1565:
#line 7590 "fgl.yacc"
    {strcpy(yyval.str,"3");}
    break;

  case 1566:
#line 7590 "fgl.yacc"
    {strcpy(yyval.str,"4");}
    break;

  case 1567:
#line 7590 "fgl.yacc"
    {strcpy(yyval.str,"5");}
    break;

  case 1568:
#line 7590 "fgl.yacc"
    {strcpy(yyval.str,"6");}
    break;

  case 1569:
#line 7591 "fgl.yacc"
    {
sprintf(yyval.str,"%d",6+2);
}
    break;

  case 1570:
#line 7594 "fgl.yacc"
    {
sprintf(yyval.str,"%d",atoi(yyvsp[-1].str)+6);
}
    break;

  case 1571:
#line 7599 "fgl.yacc"
    {strcpy(yyval.str,"4");}
    break;

  case 1572:
#line 7599 "fgl.yacc"
    {strcpy(yyval.str,"7");}
    break;

  case 1573:
#line 7599 "fgl.yacc"
    {strcpy(yyval.str,"10");}
    break;

  case 1574:
#line 7599 "fgl.yacc"
    {strcpy(yyval.str,"13");}
    break;

  case 1575:
#line 7599 "fgl.yacc"
    {strcpy(yyval.str,"16");}
    break;

  case 1576:
#line 7599 "fgl.yacc"
    {strcpy(yyval.str,"19");}
    break;

  case 1577:
#line 7601 "fgl.yacc"
    {
strcpy(yyval.str,"25");
}
    break;

  case 1578:
#line 7604 "fgl.yacc"
    {
strcpy(yyval.str,"25");
}
    break;

  case 1593:
#line 7611 "fgl.yacc"
    {sprintf(yyval.str,"FRACTION(%s)",yyvsp[-1].str);}
    break;

  case 1594:
#line 7614 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1595:
#line 7615 "fgl.yacc"
    {sprintf(yyval.str,"%s@%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1596:
#line 7616 "fgl.yacc"
    {strcpy(yyval.str, A4GL_strip_quotes (yyvsp[0].str));}
    break;

  case 1597:
#line 7620 "fgl.yacc"
    {
	print_flush_cursor(yyvsp[0].str);
		addmap("Flush Cursor",yyvsp[0].str,curr_func,yylineno,infilename);
print_undo_use(yyvsp[-2].str);
		}
    break;

  case 1598:
#line 7628 "fgl.yacc"
    {insql=0;chk4var=0;}
    break;

  case 1599:
#line 7628 "fgl.yacc"
    {
		print_declare("",yyvsp[-1].sql_string,yyvsp[-4].str,0,0);
		addmap("Declare Cursor",yyvsp[-4].str,curr_func,yylineno,infilename);
		print_undo_use(yyvsp[-6].str);
		doing_declare=0;
	}
    break;

  case 1600:
#line 7634 "fgl.yacc"
    {insql=0;chk4var=0;}
    break;

  case 1601:
#line 7634 "fgl.yacc"
    {
		print_declare("",yyvsp[-1].sql_string,yyvsp[-5].str,2,0); 
		addmap("Declare Cursor",yyvsp[-5].str,curr_func,yylineno,infilename);
		print_undo_use(yyvsp[-7].str);
		doing_declare=0;
	}
    break;

  case 1602:
#line 7641 "fgl.yacc"
    {insql=0;chk4var=0;}
    break;

  case 1603:
#line 7641 "fgl.yacc"
    {
		print_declare("",yyvsp[-1].sql_string,yyvsp[-3].str,0,1); 
		addmap("Declare Cursor",yyvsp[-3].str,curr_func,yylineno,infilename);
		print_undo_use(yyvsp[-5].str);
		doing_declare=0;
	}
    break;

  case 1604:
#line 7647 "fgl.yacc"
    {insql=0;chk4var=0;}
    break;

  case 1605:
#line 7647 "fgl.yacc"
    {
		print_declare("",yyvsp[-1].sql_string,yyvsp[-5].str,2,1); 
		addmap("Declare Cursor",yyvsp[-5].str,curr_func,yylineno,infilename);
		print_undo_use(yyvsp[-7].str);
		doing_declare=0;
	}
    break;

  case 1606:
#line 7655 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1607:
#line 7656 "fgl.yacc"
    {strcpy(yyval.str," FOR UPDATE");}
    break;

  case 1608:
#line 7657 "fgl.yacc"
    {sprintf(yyval.str," FOR UPDATE OF %s",yyvsp[0].str);}
    break;

  case 1609:
#line 7660 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1610:
#line 7660 "fgl.yacc"
    {sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1612:
#line 7664 "fgl.yacc"
    {sprintf(yyval.str,"%s.%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1613:
#line 7665 "fgl.yacc"
    {
			if (A4GL_escape_quote_owner()) {
				sprintf(yyval.str,"\\\"%s\\\".%s.%s", A4GL_strip_quotes (yyvsp[-4].str),yyvsp[-2].str,yyvsp[0].str);
			} else {
				sprintf(yyval.str,"\"%s\".%s.%s", A4GL_strip_quotes (yyvsp[-4].str),yyvsp[-2].str,yyvsp[0].str);
			}
	}
    break;

  case 1614:
#line 7676 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1615:
#line 7679 "fgl.yacc"
    { 
		yyval.sql_string=make_sql_string(print_curr_spec(1,yyvsp[0].sql_string),0);
	}
    break;

  case 1616:
#line 7685 "fgl.yacc"
    {
		start_bind('i',0);
		start_bind('o',0);
		yyval.sql_string=make_sql_string(print_curr_spec(2,yyvsp[0].str) ,0);
	}
    break;

  case 1617:
#line 7690 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1618:
#line 7698 "fgl.yacc"
    {
	yyval.sql_string=yyvsp[0].sql_string;
	if (strstr(yyvsp[0].str,"FOR UPDATE")) {
		printf("Warning SELECT ... FOR UPDATE when not declaring a cursor currently has no locking effect\n");
	}
}
    break;

  case 1619:
#line 7710 "fgl.yacc"
    { start_bind('i',0); }
    break;

  case 1620:
#line 7711 "fgl.yacc"
    {A4GL_debug("Got select list...\n");}
    break;

  case 1621:
#line 7714 "fgl.yacc"
    {
		char *ptr;
                ptr=make_sql_string("SELECT ",yyvsp[-7].str, yyvsp[-5].sql_string," ", yyvsp[-3].sql_string, " ",yyvsp[-2].sql_string," ",yyvsp[-1].sql_string,yyvsp[0].str,0);

		yyval.sql_string=strdup(print_select_all(ptr));
		free(ptr);
		free(yyvsp[-5].sql_string);
		free(yyvsp[-3].sql_string);
		free(yyvsp[-2].sql_string);
		free(yyvsp[-1].sql_string);
}
    break;

  case 1622:
#line 7729 "fgl.yacc"
    {
		/*$<sql_string>$=make_sql_string("A4GL_push_char(\"", $<str>1, " ",$<str>2," ", $<sql_string>3, " ",$<sql_string>4, " ",$<sql_string>5, "\");",0); */
		yyval.sql_string=make_sql_string(yyvsp[-4].str, " ",yyvsp[-3].str," ", yyvsp[-2].sql_string, " ",yyvsp[-1].sql_string, " ",yyvsp[0].sql_string,0);
	free(yyvsp[-2].sql_string);
	free(yyvsp[-1].sql_string);
	free(yyvsp[0].sql_string);
}
    break;

  case 1623:
#line 7740 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	 }
    break;

  case 1624:
#line 7743 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1625:
#line 7751 "fgl.yacc"
    {
	yyval.sql_string=make_sql_string(yyvsp[-5].str, " ",yyvsp[-4].str," ",yyvsp[-3].sql_string," ", yyvsp[-2].sql_string," ", yyvsp[-1].sql_string, " ",yyvsp[0].sql_string,0);
	free(yyvsp[-3].sql_string);
	free(yyvsp[-1].sql_string);
	free(yyvsp[0].sql_string);
}
    break;

  case 1626:
#line 7760 "fgl.yacc"
    {
		yyval.sql_string=strdup("");
		}
    break;

  case 1627:
#line 7763 "fgl.yacc"
    {
       A4GL_lex_printcomment("/* UNION */");
	yyval.sql_string=make_sql_string(yyvsp[-2].str," ",yyvsp[-1].str," ",yyvsp[0].sql_string,0);
       }
    break;

  case 1628:
#line 7767 "fgl.yacc"
    {
	yyval.sql_string=strdup(yyvsp[0].str);
}
    break;

  case 1629:
#line 7770 "fgl.yacc"
    { yyval.sql_string=make_sql_string(yyvsp[-2].str," ",yyvsp[-1].str," ",yyvsp[0].str,0); }
    break;

  case 1630:
#line 7771 "fgl.yacc"
    { 
	yyval.sql_string=make_sql_string(yyvsp[-3].str," ",yyvsp[-2].str," ",yyvsp[-1].str," ",yyvsp[0].str,0);
}
    break;

  case 1632:
#line 7780 "fgl.yacc"
    { start_bind('o',0);yyval.sql_string=make_sql_string("",0); }
    break;

  case 1633:
#line 7781 "fgl.yacc"
    { 
		yyval.sql_string=make_sql_string(A4GL_get_into_part(doing_declare,get_bind_cnt('o')),0 ); 

	}
    break;

  case 1634:
#line 7790 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-3].str," ",yyvsp[-2].str," ", yyvsp[-1].sql_string," ",yyvsp[0].sql_string,0);
		free(yyvsp[-1].sql_string);
		//free($<sql_string>4);

	}
    break;

  case 1635:
#line 7799 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("(",yyvsp[-4].str," ",yyvsp[-3].str," ",yyvsp[-2].sql_string," ",yyvsp[-1].sql_string,")",0);
	}
    break;

  case 1636:
#line 7804 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1637:
#line 7805 "fgl.yacc"
    {strcpy(yyval.str,"ALL ");}
    break;

  case 1638:
#line 7806 "fgl.yacc"
    {strcpy(yyval.str," DISTINCT ");}
    break;

  case 1639:
#line 7807 "fgl.yacc"
    {strcpy(yyval.str," DISTINCT ");
		ansi_violation("Use DISTINCT not UNIQUE",0);
		strcpy(yyval.str," DISTINCT ");
}
    break;

  case 1640:
#line 7814 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1641:
#line 7817 "fgl.yacc"
    { 
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",",yyvsp[0].sql_string,0);
	}
    break;

  case 1642:
#line 7823 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1643:
#line 7826 "fgl.yacc"
    {
		if (A4GL_isyes(acl_getenv("A4GL_USE_ALIAS_AS"))) {
			yyval.sql_string=make_sql_string(yyvsp[-1].sql_string," AS ",yyvsp[0].str,0);
		} else {
			yyval.sql_string=make_sql_string(yyvsp[-1].sql_string," ",yyvsp[0].str,0);
		}
	}
    break;

  case 1644:
#line 7836 "fgl.yacc"
    {
	yyval.sql_string=yyvsp[0].sql_string;
}
    break;

  case 1645:
#line 7845 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1646:
#line 7848 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("-",yyvsp[0].sql_string,0);
	}
    break;

  case 1647:
#line 7851 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("+",yyvsp[0].sql_string,0);
	}
    break;

  case 1648:
#line 7857 "fgl.yacc"
    {
			if (strlen(current_upd_table)) {
				push_gen(UPDVAL,yyvsp[0].sql_string);
			}
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1649:
#line 7863 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1650:
#line 7866 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1651:
#line 7869 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1652:
#line 7872 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].str,".",yyvsp[0].str);
	}
    break;

  case 1653:
#line 7879 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,"/",yyvsp[0].sql_string,0);}
    break;

  case 1654:
#line 7881 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-1].sql_string," ",yyvsp[0].str,0);}
    break;

  case 1655:
#line 7883 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,"*",yyvsp[0].sql_string,0);}
    break;

  case 1656:
#line 7885 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,"+",yyvsp[0].sql_string,0);}
    break;

  case 1657:
#line 7887 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,"-",yyvsp[0].sql_string,0);}
    break;

  case 1658:
#line 7888 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[0].str,0);}
    break;

  case 1659:
#line 7889 "fgl.yacc"
    {yyval.sql_string=make_sql_string("1",0);}
    break;

  case 1660:
#line 7890 "fgl.yacc"
    {yyval.sql_string=make_sql_string("0",0);}
    break;

  case 1661:
#line 7891 "fgl.yacc"
    {yyval.sql_string=make_sql_string("USER",0);}
    break;

  case 1662:
#line 7892 "fgl.yacc"
    {yyval.sql_string=make_sql_string("*",0);}
    break;

  case 1663:
#line 7893 "fgl.yacc"
    {yyval.sql_string=make_sql_string("COUNT(*)",0);}
    break;

  case 1664:
#line 7895 "fgl.yacc"
    {yyval.sql_string=make_sql_string("AVG(",yyvsp[-2].str,yyvsp[-1].sql_string,")",0);}
    break;

  case 1665:
#line 7897 "fgl.yacc"
    {yyval.sql_string=make_sql_string("MAX(",yyvsp[-2].str,yyvsp[-1].sql_string,")",0);}
    break;

  case 1666:
#line 7899 "fgl.yacc"
    {yyval.sql_string=make_sql_string("MIN(",yyvsp[-2].str,yyvsp[-1].sql_string,")",0);}
    break;

  case 1667:
#line 7901 "fgl.yacc"
    {yyval.sql_string=make_sql_string("SUM(",yyvsp[-2].str,yyvsp[-1].sql_string,")",0);}
    break;

  case 1668:
#line 7903 "fgl.yacc"
    {yyval.sql_string=make_sql_string("COUNT(",yyvsp[-2].str,yyvsp[-1].sql_string,")",0);}
    break;

  case 1669:
#line 7905 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-3].str,"(",yyvsp[-1].sql_string,")",0);}
    break;

  case 1670:
#line 7907 "fgl.yacc"
    {yyval.sql_string=make_sql_string("DATE(",yyvsp[-1].sql_string,")",0);}
    break;

  case 1671:
#line 7908 "fgl.yacc"
    {yyval.sql_string=make_sql_string("(",yyvsp[-1].sql_string,")",0);}
    break;

  case 1672:
#line 7910 "fgl.yacc"
    {yyval.sql_string=make_sql_string("EXTEND(",yyvsp[-1].sql_string,")",0);}
    break;

  case 1673:
#line 7914 "fgl.yacc"
    {yyval.sql_string=yyvsp[0].sql_string;}
    break;

  case 1674:
#line 7915 "fgl.yacc"
    {
	yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",",yyvsp[0].sql_string,0);
}
    break;

  case 1676:
#line 7925 "fgl.yacc"
    {

print_unload(yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].sql_string);
print_undo_use(yyvsp[-4].str);
}
    break;

  case 1677:
#line 7934 "fgl.yacc"
    {
print_load(yyvsp[-4].str,yyvsp[-3].str,yyvsp[-1].str,yyvsp[0].str);
print_undo_use(yyvsp[-6].str);
}
    break;

  case 1678:
#line 7938 "fgl.yacc"
    {
print_load_str(yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);
print_undo_use(yyvsp[-4].str);
}
    break;

  case 1679:
#line 7945 "fgl.yacc"
    {strcpy(yyval.str,"\"|\"");}
    break;

  case 1680:
#line 7945 "fgl.yacc"
    {
strcpy(yyval.str,yyvsp[0].str);
}
    break;

  case 1682:
#line 7949 "fgl.yacc"
    {
if ((scan_variable(yyvsp[0].str)&15)!=0) {a4gl_yyerror("Variable must be of type char for a delimiter..");YYERROR;}
}
    break;

  case 1683:
#line 7954 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 1684:
#line 7954 "fgl.yacc"
    {
sprintf(yyval.str,"%s,0",yyvsp[-1].str);
}
    break;

  case 1686:
#line 7958 "fgl.yacc"
    {
    sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 1687:
#line 7962 "fgl.yacc"
    {
     sprintf(yyval.str,"\"%s\"",yyvsp[0].str);
}
    break;

  case 1690:
#line 7971 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1691:
#line 7971 "fgl.yacc"
    {
print_use_session(yyvsp[0].str);
strcpy(yyval.str,A4GL_get_undo_use());
}
    break;

  case 1696:
#line 7990 "fgl.yacc"
    { sprintf(yyval.str,"%s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str); }
    break;

  case 1697:
#line 7991 "fgl.yacc"
    { sprintf(yyval.str,"%s %s %s %s",yyvsp[-5].str,yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str); }
    break;

  case 1700:
#line 7999 "fgl.yacc"
    {
		sprintf(yyval.str,"%s %s",yyvsp[-1].str,yyvsp[0].str);
	}
    break;

  case 1701:
#line 8005 "fgl.yacc"
    {
		sprintf(yyval.str,"%s %s %s",
					yyvsp[-2].str,
					yyvsp[-1].str,
					yyvsp[0].str
					);
		}
    break;

  case 1704:
#line 8024 "fgl.yacc"
    {strcpy(yyval.str,"UNITS YEAR");}
    break;

  case 1705:
#line 8025 "fgl.yacc"
    {strcpy(yyval.str,"UNITS MONTH"); }
    break;

  case 1706:
#line 8026 "fgl.yacc"
    {strcpy(yyval.str,"UNITS DAY"); }
    break;

  case 1707:
#line 8027 "fgl.yacc"
    {strcpy(yyval.str,"UNITS HOUR"); }
    break;

  case 1708:
#line 8028 "fgl.yacc"
    {strcpy(yyval.str,"UNITS MINUTE"); }
    break;

  case 1709:
#line 8029 "fgl.yacc"
    {strcpy(yyval.str,"UNITS SECOND"); }
    break;

  case 1710:
#line 8033 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str," ",yyvsp[-1].str," ",yyvsp[0].str,0);}
    break;

  case 1711:
#line 8034 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-4].sql_string,yyvsp[-3].str,yyvsp[-2].str," ",yyvsp[-1].str," ",yyvsp[0].str,0);}
    break;

  case 1712:
#line 8035 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-3].str,yyvsp[-2].str," ",yyvsp[-1].str," ",yyvsp[0].str,0);}
    break;

  case 1713:
#line 8039 "fgl.yacc"
    {
		sql_mode=1;
		start_bind('i',0);
		start_bind('o',0);
	}
    break;

  case 1714:
#line 8043 "fgl.yacc"
    {
			sql_mode=0;
			print_sql_block_cmd(yyvsp[-1].str);
	}
    break;

  case 1716:
#line 8052 "fgl.yacc"
    {sprintf(yyval.str,"%s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1718:
#line 8057 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1719:
#line 8058 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 2037:
#line 8383 "fgl.yacc"
    {sql_mode=0;}
    break;

  case 2038:
#line 8383 "fgl.yacc"
    {
		strcpy(yyval.str,yyvsp[0].sql_string);
		sql_mode=1;
	}
    break;

  case 2039:
#line 8390 "fgl.yacc"
    {sql_mode=0;}
    break;

  case 2040:
#line 8390 "fgl.yacc"
    {
 		strcpy(yyval.str,A4GL_get_into_part(doing_declare,get_bind_cnt('o')));
		sql_mode=1;
	}
    break;

  case 2041:
#line 8478 "fgl.yacc"
    {
		strcpy(current_upd_table,yyvsp[0].str);
		pop_all_gen(UPDCOL,"!"); pop_all_gen(UPDVAL,"!"); pop_all_gen(UPDVAL2,"!");
		yyval.sql_string=strdup("");
	}
    break;

  case 2042:
#line 8482 "fgl.yacc"
    {
		strcpy(current_upd_table,"");
	}
    break;

  case 2043:
#line 8484 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-5].str," ",yyvsp[-4].str," ",yyvsp[-2].sql_string," ",yyvsp[0].sql_string,0);
	}
    break;

  case 2044:
#line 8491 "fgl.yacc"
    {
		pop_all_gen(UPDCOL,"!"); pop_all_gen(UPDVAL,"!"); pop_all_gen(UPDVAL2,"!");
		yyval.sql_string=strdup("");
	}
    break;

  case 2045:
#line 8495 "fgl.yacc"
    { 
		pop_all_gen(UPDCOL,"!"); pop_all_gen(UPDVAL,"!"); pop_all_gen(UPDVAL2,"!");
		rm_quotes(yyvsp[0].str);
		sprintf(yyval.str,"%s %s",yyvsp[-1].str,yyvsp[0].str);
		yyval.sql_string=make_sql_string(yyval.str,0);
	}
    break;

  case 2046:
#line 8501 "fgl.yacc"
    {
		pop_all_gen(UPDCOL,"!"); pop_all_gen(UPDVAL,"!"); pop_all_gen(UPDVAL2,"!");
		yyval.sql_string=make_sql_string("WHERE ",yyvsp[0].sql_string,0);
	}
    break;

  case 2047:
#line 8509 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("SET (",yyvsp[-5].str,")=(",yyvsp[-1].sql_string,")",0);

		if (A4GL_isyes(acl_getenv("FIXUPDATE"))) { 
			yyval.sql_string=strdup(fix_update_expr(0)); 
			ansi_violation("Update (..)=(..)",0);
		}  else {
			ansi_violation("Update (..)=(..)",1);
		}
    }
    break;

  case 2048:
#line 8519 "fgl.yacc"
    {	
		yyval.sql_string=make_sql_string("SET *=(",yyvsp[-1].sql_string,")",0);
		push_gen(UPDCOL,"*");
		if (A4GL_isyes(acl_getenv("FIXUPDATE"))||1) { 
			yyval.sql_string=strdup(fix_update_expr(1));
			ansi_violation("Update (..)=(..)",0);
		} else {
			ansi_violation("Update (..)=(..)",1);
		}
    }
    break;

  case 2049:
#line 8529 "fgl.yacc"
    {	
		yyval.sql_string=make_sql_string("SET *=(",yyvsp[-1].sql_string,")",0);
		push_gen(UPDCOL,"*");
		if (A4GL_isyes(acl_getenv("FIXUPDATE"))||1) { 
			yyval.sql_string=strdup(fix_update_expr(1));
			ansi_violation("Update (..)=(..)",0);
		} else {
			ansi_violation("Update (..)=(..)",1);
		}
    }
    break;

  case 2050:
#line 8541 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("SET ",yyvsp[0].sql_string,0);
    }
    break;

  case 2051:
#line 8544 "fgl.yacc"
    {
		char *ptr;

		ptr=yyvsp[0].sql_string;
		push_gen(UPDCOL,"*");

		if (ptr[0]=='(') {
			yyval.sql_string=make_sql_string("SET *= ",yyvsp[0].sql_string,0);
		} else {
			yyval.sql_string=make_sql_string("SET *=(",yyvsp[0].sql_string,")",0);
		}

		if (A4GL_isyes(acl_getenv("FIXUPDATE"))||1) { 
			yyval.sql_string=strdup(fix_update_expr(1));
			ansi_violation("Update (..)=(..)",0);
		} else {
			ansi_violation("Update (..)=(..)",1);
		}
	}
    break;

  case 2052:
#line 8563 "fgl.yacc"
    {
		char *ptr;

		ptr=yyvsp[0].sql_string;
		push_gen(UPDCOL,"*");

		if (ptr[0]=='(') {
			yyval.sql_string=make_sql_string("SET *= ",yyvsp[0].sql_string,0);
		} else {
			yyval.sql_string=make_sql_string("SET *=(",yyvsp[0].sql_string,")",0);
		}

		if (A4GL_isyes(acl_getenv("FIXUPDATE"))||1) { 
			yyval.sql_string=strdup(fix_update_expr(1));
			ansi_violation("Update (..)=(..)",0);
		} else {
			ansi_violation("Update (..)=(..)",1);
		}
	}
    break;

  case 2053:
#line 8589 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 2054:
#line 8592 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",",yyvsp[0].sql_string,0);
	}
    break;

  case 2056:
#line 8601 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].str,"=",yyvsp[0].sql_string,0);
	}
    break;

  case 2057:
#line 8606 "fgl.yacc"
    {
			push_gen(UPDCOL,yyvsp[0].str); strcpy(yyval.str,yyvsp[0].str);
		}
    break;

  case 2058:
#line 8609 "fgl.yacc"
    {
			push_gen(UPDCOL,yyvsp[0].str); sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);
		}
    break;

  case 2059:
#line 8617 "fgl.yacc"
    { 
		yyval.sql_string=yyvsp[0].sql_string; 
		if (gen_cnt(UPDVAL2)) {
			copy_gen(UPDVAL,UPDVAL2);
		} else {
                	push_gen(UPDVAL,yyvsp[0].sql_string);
		}
	}
    break;

  case 2060:
#line 8625 "fgl.yacc"
    { 
		if (gen_cnt(UPDVAL2)) {
			copy_gen(UPDVAL,UPDVAL2);
		} else {
                	push_gen(UPDVAL,yyvsp[0].sql_string);
		}
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",",yyvsp[0].sql_string,0); 
	}
    break;

  case 2061:
#line 8638 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 2062:
#line 8641 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 2063:
#line 8649 "fgl.yacc"
    {
                yyval.sql_string=yyvsp[0].sql_string;
        }
    break;

  case 2064:
#line 8652 "fgl.yacc"
    {
                yyval.sql_string=make_sql_string("-",yyvsp[0].sql_string,0);
        }
    break;

  case 2065:
#line 8655 "fgl.yacc"
    {
                yyval.sql_string=make_sql_string("+",yyvsp[0].sql_string,0);
        }
    break;

  case 2066:
#line 8663 "fgl.yacc"
    {
                yyval.sql_string=yyvsp[0].sql_string;

        }
    break;

  case 2067:
#line 8667 "fgl.yacc"
    {
                yyval.sql_string=yyvsp[0].sql_string;
        }
    break;

  case 2068:
#line 8670 "fgl.yacc"
    {
                yyval.sql_string=strdup(yyvsp[0].str);
        }
    break;

  case 2069:
#line 8673 "fgl.yacc"
    {
                yyval.sql_string=make_sql_string(yyvsp[-2].str,".",yyvsp[0].str);
        }
    break;

  case 2070:
#line 8676 "fgl.yacc"
    { 
		yyval.sql_string=yyvsp[0].sql_string; 
		pop_all_gen(UPDVAL2,"!");
	}
    break;

  case 2071:
#line 8680 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[0].str,0);}
    break;

  case 2072:
#line 8681 "fgl.yacc"
    {yyval.sql_string=make_sql_string("TRUE",0);}
    break;

  case 2073:
#line 8682 "fgl.yacc"
    {yyval.sql_string=make_sql_string("FALSE",0);}
    break;

  case 2074:
#line 8683 "fgl.yacc"
    {yyval.sql_string=make_sql_string("USER",0);}
    break;

  case 2075:
#line 8684 "fgl.yacc"
    {yyval.sql_string=make_sql_string("COUNT(*)",0);}
    break;

  case 2076:
#line 8690 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,"/",yyvsp[0].sql_string,0);}
    break;

  case 2077:
#line 8691 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-1].sql_string,yyvsp[0].str,0);}
    break;

  case 2078:
#line 8692 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,"*",yyvsp[0].sql_string,0);}
    break;

  case 2079:
#line 8693 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,"+",yyvsp[0].sql_string,0);}
    break;

  case 2080:
#line 8694 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,"-",yyvsp[0].sql_string,0);}
    break;

  case 2081:
#line 8695 "fgl.yacc"
    {yyval.sql_string=make_sql_string("AVERAGE(",yyvsp[-2].str,yyvsp[-1].sql_string,")",0);}
    break;

  case 2082:
#line 8696 "fgl.yacc"
    {yyval.sql_string=make_sql_string("MAX(",yyvsp[-2].str,yyvsp[-1].sql_string,")",0);}
    break;

  case 2083:
#line 8697 "fgl.yacc"
    {yyval.sql_string=make_sql_string("MIN(",yyvsp[-2].str,yyvsp[-1].sql_string,")",0);}
    break;

  case 2084:
#line 8698 "fgl.yacc"
    {yyval.sql_string=make_sql_string("SUM(",yyvsp[-2].str,yyvsp[-1].sql_string,")",0);}
    break;

  case 2085:
#line 8699 "fgl.yacc"
    {yyval.sql_string=make_sql_string("COUNT(",yyvsp[-2].str,yyvsp[-1].sql_string,")",0);}
    break;

  case 2086:
#line 8700 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-3].str,"(",yyvsp[-1].sql_string,")",0);}
    break;

  case 2087:
#line 8701 "fgl.yacc"
    {yyval.sql_string=make_sql_string("DATE(",yyvsp[-1].sql_string,")",0);}
    break;

  case 2088:
#line 8702 "fgl.yacc"
    {yyval.sql_string=make_sql_string("(",yyvsp[-1].sql_string,")",0);}
    break;

  case 2089:
#line 8703 "fgl.yacc"
    {yyval.sql_string=make_sql_string("EXTEND(",yyvsp[-1].sql_string,")",0);}
    break;

  case 2090:
#line 8707 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
}
    break;

  case 2091:
#line 8713 "fgl.yacc"
    {yyval.sql_string=yyvsp[0].sql_string;}
    break;

  case 2092:
#line 8714 "fgl.yacc"
    {
        yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",",yyvsp[0].sql_string,0);
}
    break;

  case 2093:
#line 8722 "fgl.yacc"
    {
	clr_validate_list();
}
    break;

  case 2094:
#line 8724 "fgl.yacc"
    {
	print_validate();
}
    break;

  case 2096:
#line 8730 "fgl.yacc"
    {sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 2097:
#line 8734 "fgl.yacc"
    {
		sprintf(yyval.str,"%s.%s",yyvsp[-2].str,yyvsp[0].str);
		push_validate(yyval.str);
	}
    break;

  case 2098:
#line 8738 "fgl.yacc"
    {
		sprintf(yyval.str,"%s.*",yyvsp[-2].str);
		push_validate(yyval.str);
	}
    break;

  case 2099:
#line 8754 "fgl.yacc"
    {
	if (scan_variable(yyvsp[0].str)!=-1)
	{
		char buff[1024];
			sprintf(buff,"%s",fgl_add_scope(yyvsp[0].str,0));

		print_push_variable(buff);

		strcpy(yyval.str,"?");

	} else {
		strcpy(yyval.str,yyvsp[0].str);
	}

}
    break;

  case 2100:
#line 8773 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 2104:
#line 8779 "fgl.yacc"
    {sprintf(yyval.str,"%s.%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 2105:
#line 8780 "fgl.yacc"
    {
		if (A4GL_escape_quote_owner()) {
			sprintf(yyval.str,"\\\"%s\\\".%s.%s", A4GL_strip_quotes (yyvsp[-4].str),yyvsp[-2].str,yyvsp[0].str);
		} else {
			sprintf(yyval.str,"\"%s\".%s.%s", A4GL_strip_quotes (yyvsp[-4].str),yyvsp[-2].str,yyvsp[0].str);
		}
	}
    break;

  case 2109:
#line 8798 "fgl.yacc"
    {
	int sv_val;
	//printf("var_ident_ibind_ss : %s\n",$<str>1);
	sv_val=scan_variable(yyvsp[0].str);

	if (strncmp(yyvsp[0].str," a4gl_sub",9)==0) {
		// Its a substring of a variable
		sv_val=1;
	}

	if (sv_val!=-1&&(!system_var(yyvsp[0].str)))
	{
		// Its a variable
		int z = 0,a = 0;
		//printf("add as bind\n");
		a=get_bind_cnt('i');
		z=add_bind('i',yyvsp[0].str);
		z-=a;
		yyval.sql_string=strdup(A4GL_set_var_sql(doing_declare,z));

	} else { 
		// Its a column
		yyval.sql_string=strdup(get_column_transform(yyvsp[0].str));
	}
}
    break;

  case 2110:
#line 8824 "fgl.yacc"
    {
char buff[256];
char was_str[40000];
int z = 0,a = 0;
strcpy(was_str,"");
printf("THRU : %s %s\n",yyvsp[-2].str,yyvsp[0].str);

A4GL_debug("Starting THRU");

sprintf(buff,"%s\n%s",yyvsp[-2].str,yyvsp[0].str);
a=get_bind_cnt('i');
printf("get_bind_cnt=%d\n",a);
z=add_bind('i',buff);
z-=a;
for (a=0;a<z;a++)  {
         if (strlen(was_str)) {strcat(was_str,",");}
         strcat(was_str,"?");
}


	/* split_record(buff,&v_r,&v_1,&v_2);

	v_loop=v_1;

	while (1) {
                //strcpy(kp,was_str);
                sprintf(buff,"%s.%s",r1,v_loop->names.name);

		if (scan_variable(buff)!=-1&&(!system_var(buff))) {
			a=get_bind_cnt('i');
			z=add_bind('i',buff);
			z-=a;
        	}

		for (a=0;a<z;a++)  {
			if (strlen(was_str)) {strcat(was_str,",");}
         		strcat(was_str,"?");
		}
		v_loop=get_next_variable(v_r,v_loop,v_2);
	}
*/
	yyval.sql_string=strdup(was_str);
}
    break;

  case 2111:
#line 8888 "fgl.yacc"
    {
print_while_1();
push_blockcommand("WHILE");
}
    break;

  case 2112:
#line 8891 "fgl.yacc"
    {
print_while_2();
}
    break;

  case 2113:
#line 8895 "fgl.yacc"
    {
print_while_3();
pop_blockcommand("WHILE");
}
    break;

  case 2114:
#line 8910 "fgl.yacc"
    {yyval.field_list=0;}
    break;

  case 2115:
#line 8910 "fgl.yacc"
    {
	yyval.field_list=yyvsp[0].field_list;
}
    break;

  case 2116:
#line 8916 "fgl.yacc"
    { strcpy(yyval.str,"0"); }
    break;

  case 2117:
#line 8917 "fgl.yacc"
    { strcpy(yyval.str,"1"); }
    break;

  case 2118:
#line 8920 "fgl.yacc"
    { print_current_window("\"screen\""); print_clr_window("\"screen\""); }
    break;

  case 2119:
#line 8921 "fgl.yacc"
    { print_clr_window(yyvsp[0].str); }
    break;

  case 2120:
#line 8922 "fgl.yacc"
    { print_clr_window(yyvsp[0].str); }
    break;

  case 2121:
#line 8923 "fgl.yacc"
    { print_clr_form(0,0,"0"); }
    break;

  case 2122:
#line 8924 "fgl.yacc"
    { print_clr_form(0,0,"1"); }
    break;

  case 2123:
#line 8925 "fgl.yacc"
    { print_clr_form(yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str); }
    break;

  case 2124:
#line 8926 "fgl.yacc"
    {
	print_clr_fields(field_name_list_as_char(yyvsp[-1].field_list),yyvsp[0].str);
}
    break;

  case 2125:
#line 8932 "fgl.yacc"
    {yyval.field_list=yyvsp[0].field_list;}
    break;

  case 2126:
#line 8944 "fgl.yacc"
    {
	print_current_window("\"screen\"");
}
    break;

  case 2127:
#line 8948 "fgl.yacc"
    {
	print_current_window(yyvsp[0].str);
}
    break;

  case 2128:
#line 8952 "fgl.yacc"
    {
sprintf(yyval.str,"A4GL_cr_window");
reset_attrib(&form_attrib);
}
    break;

  case 2129:
#line 8956 "fgl.yacc"
    {
sprintf(yyval.str,"A4GL_cr_window_form");
reset_attrib(&form_attrib);
}
    break;

  case 2130:
#line 8961 "fgl.yacc"
    {
	print_show_window(yyvsp[0].str);
	addmap("Show Window",yyvsp[0].str,curr_func,yylineno,infilename); 
}
    break;

  case 2131:
#line 8965 "fgl.yacc"
    {
	print_show_menu(yyvsp[-3].str,yyvsp[-1].str);
	addmap("Call Menuhandler",yyvsp[-1].str,curr_func,yylineno,infilename); 
}
    break;

  case 2132:
#line 8970 "fgl.yacc"
    {

print_def_mn_file();

}
    break;

  case 2134:
#line 8978 "fgl.yacc"
    {addmap("Use Menu",yyvsp[0].str,curr_func,yylineno,infilename); }
    break;

  case 2136:
#line 8984 "fgl.yacc"
    {
	print_hide_window(yyvsp[0].str);
}
    break;

  case 2137:
#line 8990 "fgl.yacc"
    {
print_move_window(yyvsp[-4].str,0);
}
    break;

  case 2138:
#line 8994 "fgl.yacc"
    {
print_move_window(yyvsp[-4].str,1);
}
    break;

  case 2143:
#line 9012 "fgl.yacc"
    {
chk4var=0;A4GL_lex_printcomment("/* [Comm:%s] */\n",yyval.str);
if (A4GL_isyes(acl_getenv("INCLINES")))
A4GL_lex_printc("{A4GL_debug(\"Line %d %s:%s\");}",lastlineno,infilename,convstrsql(larr));
	A4GL_prchkerr(lastlineno,infilename);
	lastlineno=yylineno;
}
    break;

  case 2144:
#line 9019 "fgl.yacc"
    {
A4GL_lex_printcomment("/* [COMM:%s] */\n",yyvsp[0].str);chk4var=0;
if (A4GL_isyes(acl_getenv("INCLINES")))
A4GL_lex_printc("{A4GL_debug(\"Line %d %s:%s\");}",lastlineno,infilename,convstrsql(larr));
/* if (A4GL_aubit_strcasecmp($<str>$,"whenever")!=0)  */
A4GL_prchkerr(lastlineno,infilename);
lastlineno=yylineno;
}
    break;

  case 2145:
#line 9029 "fgl.yacc"
    {print_cmd_start();}
    break;

  case 2146:
#line 9029 "fgl.yacc"
    {print_cmd_end();}
    break;


    }

/* Line 991 of yacc.c.  */
#line 18227 "y.tab.c"

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


#line 9127 "fgl.yacc"

/* programmer routines */
/*
# include "lex.yy.c"
# include "lexify.c"
*/

void
set_clobber(char *c)
{
	char *ptr;
	//char *ptr2;
	ptr=strrchr(c,'/');
	if (ptr) { strcpy(clobber,ptr+1); return; }

/* Do dos mode ? */
	ptr=strrchr(c,'\\');
	if (ptr) { strcpy(clobber,ptr+1); return; }

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



