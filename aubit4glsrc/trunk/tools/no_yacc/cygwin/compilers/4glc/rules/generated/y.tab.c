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
     NAME = 1709,
     UMINUS = 1710,
     COMMA = 1615,
     KW_OR = 1655,
     KW_AND = 1610,
     KW_USING = 1547,
     NOT = 1630,
     MATCHES = 1427,
     POWER = 1533,
     LESS_THAN = 1529,
     GREATER_THAN = 1444,
     EQUAL = 1605,
     GREATER_THAN_EQ = 1346,
     LESS_THAN_EQ = 1403,
     NOT_EQUAL = 1475,
     PLUS = 1641,
     MINUS = 1628,
     MULTIPLY = 1534,
     DIVIDE = 1561,
     MOD = 1629,
     COMMAND = 1410,
     NUMBER_VALUE = 1711,
     CHAR_VALUE = 1712,
     INT_VALUE = 1713,
     NAMED_GEN = 1714,
     CLINE = 1715,
     SQLLINE = 1716,
     KW_CSTART = 1717,
     KW_CEND = 1718,
     USER_DTYPE = 1719,
     SQL_TEXT = 1720,
     KW_WHENEVER_SET = 1721,
     COMMENT = 1722,
     DYNAMIC_ARRAY = 1000,
     RESIZE_ARRAY = 1001,
     ALLOCATE_ARRAY = 1002,
     DEALLOCATE_ARRAY = 1003,
     AFTER_INSERT_DELETE = 1004,
     BEFORE_INSERT_DELETE = 1005,
     BEFORE_INSERT = 1006,
     AS_CONVERTABLE = 1007,
     CONCAT_PIPES = 1008,
     BEFORE_DELETE = 1009,
     DROP_TRIGGER = 1010,
     AFTER_INSERT = 1011,
     AFTER_DELETE = 1012,
     EXECUTE_IMMEDIATE = 1013,
     DELETE_ROW_EQUAL_TRUE = 1014,
     INSERT_ROW_EQUAL_TRUE = 1015,
     DELETE_ROW_EQUAL_FALSE = 1016,
     INSERT_ROW_EQUAL_FALSE = 1017,
     CURRENT_ROW_DISPLAY_EQUAL = 1018,
     MAXCOUNT = 1019,
     ALTER_TABLE = 1020,
     ALTER_INDEX = 1021,
     NEXT_SIZE = 1022,
     DISPLAY_ATTR_FORM = 1023,
     DISPLAY_ATTR_WINDOW = 1024,
     INPUT_ATTR_FORM = 1025,
     INPUT_ATTR_WINDOW = 1026,
     WHENEVER_ERROR_CONTINUE = 1027,
     WHENEVER_ANY_ERROR_CONTINUE = 1028,
     WHENEVER_WARNING_CONTINUE = 1029,
     WHENEVER_SQLSUCCESS_CONTINUE = 1030,
     WHENEVER_SQLWARNING_CONTINUE = 1031,
     WHENEVER_NOT_FOUND_CONTINUE = 1032,
     WHENEVER_SQLERROR_CONTINUE = 1033,
     WHENEVER_SUCCESS_CONTINUE = 1034,
     WHENEVER_ERROR_GOTO = 1035,
     WHENEVER_ANY_ERROR_GOTO = 1036,
     WHENEVER_WARNING_GOTO = 1037,
     WHENEVER_SQLSUCCESS_GOTO = 1038,
     WHENEVER_SQLWARNING_GOTO = 1039,
     WHENEVER_NOT_FOUND_GOTO = 1040,
     WHENEVER_SQLERROR_GOTO = 1041,
     WHENEVER_SUCCESS_GOTO = 1042,
     WHENEVER_ERROR_CALL = 1043,
     WHENEVER_ANY_ERROR_CALL = 1044,
     WHENEVER_WARNING_CALL = 1045,
     WHENEVER_SQLSUCCESS_CALL = 1046,
     WHENEVER_SQLWARNING_CALL = 1047,
     WHENEVER_NOT_FOUND_CALL = 1048,
     WHENEVER_SQLERROR_CALL = 1049,
     WHENEVER_SUCCESS_CALL = 1050,
     WHENEVER_ERROR_STOP = 1051,
     WHENEVER_ANY_ERROR_STOP = 1052,
     WHENEVER_WARNING_STOP = 1053,
     WHENEVER_SQLSUCCESS_STOP = 1054,
     WHENEVER_SQLWARNING_STOP = 1055,
     WHENEVER_NOT_FOUND_STOP = 1056,
     WHENEVER_SQLERROR_STOP = 1057,
     WHENEVER_SUCCESS_STOP = 1058,
     XSET_MULTIPLY_EQUAL_OPEN_BRACKET = 1059,
     XSET_ident_DOT_MULTIPLY_EQUAL_OPEN_BRACKET = 1060,
     XSET_ident_DOT_MULTIPLY_EQUAL = 1061,
     XSET_MULTIPLY_EQUAL = 1062,
     XSET_OPEN_BRACKET = 1063,
     NEWFORMATSHARED = 1064,
     CREATE_DATABASE = 1065,
     DROP_DATABASE = 1066,
     IMPORT_LEGACY_FUNCTION = 1067,
     ADD_CONSTRAINT = 1068,
     DROP_CONSTRAINT = 1069,
     DROP_SYNONYM = 1070,
     CONSTRAINT = 1071,
     AS_STATIC = 1072,
     NOT_FIELD_TOUCHED = 1073,
     LOCAL_FUNCTION = 1074,
     EVERY_ROW = 1075,
     ELIF = 1076,
     DOUBLE_PRECISION = 1077,
     COUNT_MULTIPLY = 1078,
     WAIT_FOR_KEY = 1079,
     AT_TERMINATION_CALL = 1080,
     TERMINATE_REPORT = 1081,
     TO_MAIN_CAPTION = 1082,
     CLEARSTAT = 1083,
     TO_MENUITEM = 1084,
     ID_TO_INT = 1085,
     TO_STATUSBOX = 1086,
     ASCII_HEIGHT_ALL = 1087,
     ASCII_WIDTH_ALL = 1088,
     IMPORT_DATATYPE = 1089,
     PAGE_TRAILER_SIZE = 1090,
     PAGE_HEADER_SIZE = 1091,
     FIRST_PAGE_HEADER_SIZE = 1092,
     BYTES_USE_AS_IMAGE = 1093,
     BYTES_USE_AS_ASCII = 1094,
     KWUP_BY = 1095,
     KWDOWN_BY = 1096,
     CLOSE_STATUSBOX = 1097,
     MODIFY_NEXT_SIZE = 1098,
     LOCK_MODE_PAGE = 1099,
     LOCK_MODE_ROW = 1100,
     TO_PIPE = 1101,
     TO_PRINTER = 1102,
     STATUSBOX = 1103,
     FORMHANDLER_INPUT = 1104,
     UNITS_YEAR = 1105,
     UNITS_MONTH = 1106,
     UNITS_DAY = 1107,
     UNITS_HOUR = 1108,
     UNITS_MINUTE = 1109,
     UNITS_SECOND = 1110,
     NO_NEW_LINES = 1111,
     FIELDTOWIDGET = 1112,
     WITH_HOLD = 1113,
     SHOW_MENU = 1114,
     TO_CLUSTER = 1115,
     TO_NOT_CLUSTER = 1116,
     CWIS = 1117,
     CREATE_IDX = 1118,
     FORM_IS_COMPILED = 1119,
     PDF_REPORT = 1120,
     IMPORT_FUNCTION = 1121,
     PROMPT_MANY = 1122,
     POINTS = 1123,
     MM = 1124,
     INCHES = 1125,
     PREPEND = 1126,
     MEMBER_OF = 1127,
     MEMBER_FUNCTION = 1128,
     APPEND = 1129,
     TEMPLATE = 1130,
     END_TEMPLATE = 1131,
     SQLSICS = 1132,
     CREATE_SCHEMA = 1133,
     SQLSIRR = 1134,
     UPDATESTATS_T = 1135,
     SQLSICR = 1136,
     WHENEVER_SQLSUCCESS = 1137,
     WHENEVER_SQLWARNING = 1138,
     WHENEVER_ANY_ERROR = 1139,
     WHENEVER_NOT_FOUND = 1140,
     WHENEVER_SQLERROR = 1141,
     WHENEVER_SUCCESS = 1142,
     WHENEVER_ERROR = 1143,
     START_EXTERN = 1144,
     CONTINUE_CONSTRUCT = 1145,
     FOUNCONSTR = 1146,
     SQLSIDR = 1147,
     CREATE_TEMP_TABLE = 1148,
     CURRENT_WINDOW_IS = 1149,
     FIRST_PAGE_HEADER = 1150,
     ORDER_EXTERNAL_BY = 1151,
     SCROLL_CURSOR_FOR = 1152,
     SCROLL_CURSOR = 1153,
     SQL_INTERRUPT_OFF = 1154,
     STOP_ALL_EXTERNAL = 1155,
     WITH_CHECK_OPTION = 1156,
     WITH_GRANT_OPTION = 1157,
     SQLSLMNW = 1158,
     ADDCONSTUNIQ = 1159,
     CONTINUE_DISPLAY = 1160,
     CONTINUE_FOREACH = 1161,
     OUTPUT_TO_REPORT = 1162,
     SQL_INTERRUPT_ON = 1163,
     WHERE_CURRENT_OF = 1164,
     WITHOUT_DEFAULTS = 1165,
     FOCONSTR = 1166,
     SCALED_BY = 1167,
     CONTINUE_PROMPT = 1168,
     PDF_FUNCTION = 1169,
     DEFER_INTERRUPT = 1170,
     DISPLAY_BY_NAME = 1171,
     NOT_NULL_UNIQUE = 1172,
     SKIP_TO_TOP = 1173,
     TOP_OF_PAGE = 1174,
     SKIP_TO = 1175,
     SKIP_BY = 1176,
     WITHOUT_WAITING = 1177,
     BEFCONSTRUCT = 1178,
     SQLSLMW = 1179,
     AFTCONSTRUCT = 1180,
     ALL_PRIVILEGES = 1181,
     CLOSE_DATABASE = 1182,
     CONTINUE_INPUT = 1183,
     CONTINUE_WHILE = 1184,
     CREATE_SYNONYM = 1185,
     DROP_TABLE = 1186,
     EXIT_CONSTRUCT = 1187,
     INEXCLUSIVE = 1188,
     REPORT_TO_PRINTER = 1189,
     REPORT_TO_PIPE = 1190,
     RETURN = 1191,
     SET_SESSION_TO = 1192,
     UPDATESTATS = 1193,
     WITHOUT_HEAD = 1194,
     CLEARSCR = 1195,
     WITH_B_LOG = 1196,
     AUTHORIZATION = 1197,
     BOTTOM_MARGIN = 1198,
     CLOSE_SESSION = 1199,
     CONTINUE_CASE = 1200,
     CONTINUE_MENU = 1201,
     DISPLAY_ARRAY = 1202,
     END_SQL = 1203,
     DOLLAR = 1204,
     END_CONSTRUCT = 1205,
     FIELD_TOUCHED = 1206,
     FINISH_REPORT = 1207,
     INFACC = 1208,
     INPUT_NO_WRAP = 1209,
     SETPMOFF = 1210,
     UNCONSTRAINED = 1211,
     PAGE_TRAILER = 1212,
     SETPMON = 1213,
     BEFGROUP = 1214,
     CLOSE_WINDOW = 1215,
     COMMENT_LINE = 1216,
     CONTINUE_FOR = 1217,
     CREATE_DB = 1218,
     CREATE_TABLE = 1219,
     DEFAULT_NULL = 1220,
     DEFAULT_TODAY = 1221,
     DEFAULT_USER = 1222,
     DELETE_USING = 1223,
     DISPLAY_FORM = 1224,
     END_FUNCTION = 1225,
     EXIT_DISPLAY = 1226,
     EXIT_FOREACH = 1227,
     EXIT_PROGRAM = 1228,
     INFCOLS = 1229,
     ON_EVERY_ROW = 1230,
     OPEN_SESSION = 1231,
     RIGHT_MARGIN = 1232,
     SELECT_USING = 1233,
     START_REPORT = 1234,
     UNLOCK_TABLE = 1235,
     UPDATE_USING = 1236,
     ACL_BUILTIN = 1237,
     AFTGROUP = 1238,
     INFIDX = 1239,
     INFSTAT = 1240,
     LEFT_MARGIN = 1241,
     PAGE_HEADER = 1242,
     ROLLBACK_W = 1243,
     SET_SESSION = 1244,
     SQLSEOFF = 1245,
     WITH_A_LOG = 1246,
     BEFDISP = 1247,
     BEFORE_MENU = 1248,
     CREATE_VIEW = 1249,
     DEFINE_TYPE = 1250,
     DELETE_FROM = 1251,
     END_DISPLAY = 1252,
     END_REPORT = 1253,
     END_FOREACH = 1254,
     END_FOR = 1255,
     END_GLOBALS = 1256,
     EXIT_PROMPT = 1257,
     EXTENT_SIZE = 1258,
     FOREIGN_KEY = 1259,
     HIDE_OPTION = 1260,
     HIDE_WINDOW = 1261,
     INSERT_INTO = 1262,
     IS_NOT_NULL = 1263,
     MOVE_WINDOW = 1264,
     NEXT_OPTION = 1265,
     NOT_MATCHES = 1266,
     ON_LAST_ROW = 1267,
     OPEN_WINDOW = 1268,
     OPEN_STATUSBOX = 1269,
     PAGE_LENGTH = 1270,
     PAGE_WIDTH = 1271,
     PRIMARY_KEY = 1272,
     PROMPT_LINE = 1273,
     RECORD_LIKE = 1274,
     ROLLFORWARD = 1275,
     SETBL = 1276,
     SHOW_OPTION = 1277,
     SHOW_WINDOW = 1278,
     SQLSEON = 1279,
     TO_DATABASE = 1280,
     USE_SESSION = 1281,
     WITH_NO_LOG = 1282,
     AFTDISP = 1283,
     BEFFIELD = 1284,
     INSHARE = 1285,
     UNLOCKTAB = 1286,
     AFTFIELD = 1287,
     ATTRIBUTES = 1288,
     BEFINP = 1289,
     BEGIN_WORK = 1290,
     CLEARWIN = 1291,
     CLOSE_FORM = 1292,
     DEFER_QUIT = 1293,
     DESCENDING = 1294,
     DROP_INDEX = 1295,
     END_PROMPT = 1296,
     END_RECORD = 1297,
     ERROR_LINE = 1298,
     EXIT_INPUT = 1299,
     EXIT_WHILE = 1300,
     FOR_UPDATE_OF = 1301,
     FOR_UPDATE = 1302,
     GET_FLDBUF = 1303,
     INITIALIZE = 1304,
     INPUT_WRAP = 1305,
     LOCK_TABLE = 1306,
     MSG_LINE = 1307,
     NOT_EXISTS = 1308,
     ON_ANY_KEY = 1309,
     REFERENCES = 1310,
     RENCOL = 1311,
     SET_CURSOR = 1312,
     SMALLFLOAT = 1313,
     SQLSUCCESS = 1314,
     TOP_MARGIN = 1315,
     WITH_ARRAY = 1316,
     ACCEPTKEY = 1317,
     ACCEPT = 1318,
     AFTINP = 1319,
     CLEARFORMTODEFAULTS = 1320,
     CLEARFORM = 1321,
     CLEAR_X_FORM = 1322,
     COMMIT_W = 1323,
     NEXTPAGE = 1324,
     PREVPAGE = 1325,
     CTRL_KEY = 1326,
     INFTABS = 1327,
     NEXTFIELD = 1328,
     NEXTFORM = 1329,
     RENTAB = 1330,
     ASCENDING = 1331,
     ASSOCIATE = 1332,
     CHAR = 1333,
     NCHAR = 1334,
     NVARCHAR = 1335,
     CONSTRUCT = 1336,
     DELIMITER = 1337,
     DOWNSHIFT = 1338,
     DROP_VIEW = 1339,
     END_INPUT = 1340,
     END_WHILE = 1341,
     EXCLUSIVE = 1342,
     EXIT_CASE = 1343,
     EXIT_MENU = 1344,
     FORM_LINE = 1345,
     INTERRUPT = 1347,
     INTO_TEMP = 1348,
     INVISIBLE = 1349,
     IN_MEMORY = 1350,
     LINKED_TO = 1351,
     LOAD_FROM = 1352,
     LOCKTAB = 1353,
     MENU_LINE = 1354,
     OPEN_FORM = 1355,
     OTHERWISE = 1356,
     PRECISION = 1357,
     PRIOR = 1358,
     PROCEDURE = 1359,
     REPORT_TO = 1360,
     RETURNING = 1361,
     UNDERLINE = 1362,
     UNLOAD_TO = 1363,
     BEFROW = 1364,
     UNLOAD_T = 1365,
     VARIABLE = 1366,
     ABSOLUTE = 1367,
     AFTROW = 1368,
     BUFFERED = 1369,
     CONSTANT = 1370,
     CONST = 1371,
     DATABASE = 1372,
     DATETIME = 1373,
     DEFAULTS = 1374,
     DISTINCT = 1375,
     END_CASE = 1376,
     END_MAIN = 1377,
     END_MENU = 1378,
     END_TYPE = 1379,
     EXIT_FOR = 1380,
     EXTERNAL = 1381,
     FRACTION = 1382,
     FUNCTION = 1383,
     GROUP_BY = 1384,
     INTERVAL = 1385,
     KWMESSAGE = 1386,
     NOT_LIKE = 1387,
     NOT_ILIKE = 1388,
     NOT_NULL = 1389,
     PASSWORD = 1390,
     PREVIOUS = 1391,
     READONLY = 1392,
     REGISTER = 1393,
     RELATIVE = 1394,
     RESOURCE = 1395,
     SMALLINT = 1396,
     VALIDATE = 1397,
     WITH_LOG = 1398,
     WORDWRAP = 1399,
     BY_NAME = 1400,
     IN_FILE = 1401,
     IS_NULL = 1402,
     AVERAGE = 1404,
     BETWEEN = 1405,
     CAPTION = 1406,
     CLIPPED = 1407,
     CLOSE_BRACKET = 1408,
     COLUMNS = 1409,
     CONNECT = 1411,
     CURRENT = 1412,
     DBYNAME = 1413,
     DECIMAL = 1414,
     DECLARE = 1415,
     DEFAULT = 1416,
     DISPLAY = 1417,
     ENDCODE = 1418,
     EXECUTE = 1419,
     FOREACH = 1420,
     FOREIGN = 1421,
     GLOBALS = 1422,
     INFIELD = 1423,
     INTEGER = 1424,
     KWWINDOW = 1425,
     MAGENTA = 1426,
     OPTIONS = 1428,
     PERCENT = 1429,
     PREPARE = 1430,
     PROGRAM = 1431,
     RECOVER = 1432,
     REVERSE = 1433,
     SECTION = 1434,
     SESSION = 1435,
     SYNONYM = 1436,
     THRU = 1437,
     TRAILER = 1438,
     UPSHIFT = 1439,
     VARCHAR = 1440,
     WAITING = 1441,
     CLOSE_SHEV = 1442,
     CLOSE_SQUARE = 1443,
     KW_FALSE = 1445,
     NOT_IN = 1446,
     ONKEY = 1447,
     OPEN_BRACKET = 1448,
     BORDER = 1449,
     BOTTOM = 1450,
     COLUMN = 1451,
     COMMIT = 1452,
     CREATE = 1453,
     CURSOR = 1454,
     DEFINE = 1455,
     DELETE = 1456,
     DOUBLE = 1457,
     END_IF = 1458,
     ESCAPE = 1459,
     EXISTS = 1460,
     EXTEND = 1461,
     EXTENT = 1462,
     FINISH = 1463,
     FORMAT = 1464,
     HAVING = 1465,
     HEADER = 1466,
     INSERT = 1467,
     LOCATE = 1468,
     MARGIN = 1469,
     MEMORY = 1470,
     MINUTE = 1471,
     MODIFY = 1472,
     NORMAL = 1473,
     EQUAL_EQUAL = 1474,
     OPEN_SHEV = 1476,
     OPEN_SQUARE = 1477,
     OPTION = 1478,
     OUTPUT = 1479,
     PROMPT = 1480,
     PUBLIC = 1481,
     RECORD = 1482,
     REPORT = 1483,
     REVOKE = 1484,
     SCHEMA = 1485,
     SCROLL_USING = 1486,
     SCROLL = 1487,
     SECOND = 1488,
     SELECT = 1489,
     SERIAL = 1490,
     SETL = 1491,
     SHARED = 1492,
     SPACES = 1493,
     UNIQUE = 1494,
     UNLOCK = 1495,
     UPDATE = 1496,
     VALUES = 1497,
     YELLOW = 1498,
     AFTER = 1499,
     KWLINE = 1500,
     KW_NULL = 1501,
     KW_TRUE = 1502,
     SINGLE_KEY = 1503,
     ALTER = 1504,
     ARRAY = 1505,
     ASCII = 1506,
     AUDIT = 1507,
     BLACK = 1508,
     BLINK = 1509,
     CHECK = 1510,
     CLEAR = 1511,
     CLOSE = 1512,
     CODE_C = 1513,
     COUNT = 1514,
     DEFER = 1515,
     ERROR = 1516,
     EVERY = 1517,
     FETCH = 1518,
     FIRST = 1519,
     FLOAT = 1520,
     FLUSH = 1521,
     FOUND = 1522,
     GRANT = 1523,
     GREEN = 1524,
     GROUP = 1525,
     INDEX = 1526,
     KWFORM = 1527,
     LABEL = 1528,
     LOCAL = 1530,
     MONEY = 1531,
     MONTH = 1532,
     ORDER = 1535,
     OUTER = 1536,
     PAUSE = 1537,
     PRINT_IMAGE = 1538,
     PRINT_FILE = 1539,
     PRINT = 1540,
     RIGHT = 1541,
     DOUBLE_COLON = 1542,
     SEMICOLON = 1543,
     SLEEP = 1544,
     TUPLE = 1545,
     UNION = 1546,
     WHERE = 1548,
     WHILE = 1549,
     WHITE = 1550,
     CCODE = 1551,
     ANSI = 1552,
     BLUE = 1553,
     BOLD = 1554,
     BYTE = 1555,
     FCALL = 1556,
     CASE = 1557,
     CYAN = 1558,
     DATE = 1559,
     DESC = 1560,
     KWDOWN = 1562,
     TAB = 1563,
     DROP = 1564,
     ELSE = 1565,
     EXEC = 1566,
     EXIT = 1567,
     FREE = 1568,
     FROM = 1569,
     GOTO = 1570,
     HELP_FILE = 1571,
     LANG_FILE = 1572,
     HELP = 1573,
     HIDE = 1574,
     HOUR = 1575,
     INTO = 1576,
     LAST = 1577,
     LEFT = 1578,
     LIKE = 1579,
     MAIN = 1580,
     MENU = 1581,
     MODE = 1582,
     NEED = 1583,
     NEXT = 1584,
     NOCR = 1585,
     OPEN = 1586,
     QUIT = 1587,
     REAL = 1588,
     ROWS = 1589,
     SHOW = 1590,
     SIZE = 1591,
     SKIP = 1592,
     SOME = 1593,
     STEP = 1594,
     STOP = 1595,
     TEMP = 1596,
     TEXT = 1597,
     THEN = 1598,
     USER = 1599,
     WAIT = 1600,
     WHEN = 1601,
     WITH = 1602,
     WORK = 1603,
     YEAR = 1604,
     KW_IS = 1606,
     XSET = 1607,
     ADD = 1608,
     ALL = 1609,
     ANY = 1611,
     ASC = 1612,
     AVG = 1613,
     COLON = 1614,
     DAY = 1616,
     DBA = 1617,
     DEC = 1618,
     DIM = 1619,
     FKEY = 1620,
     FOR = 1621,
     KEY = 1622,
     KWNO = 1623,
     LET = 1624,
     LOG = 1625,
     XMAX = 1626,
     XMIN = 1627,
     PAD = 1631,
     PUT = 1632,
     RED = 1633,
     ROW = 1634,
     RUN = 1635,
     SQL = 1636,
     SUM = 1637,
     TOP = 1638,
     USE = 1639,
     ATSIGN = 1640,
     AS_TIFF = 1642,
     AS_GIF = 1643,
     AS_PNG = 1644,
     AS_JPEG = 1645,
     AS = 1646,
     AT = 1647,
     BY = 1648,
     DOT = 1649,
     GO = 1650,
     IF = 1651,
     IN = 1652,
     OF = 1653,
     ON = 1654,
     TO = 1656,
     KWUP = 1657,
     FONT_NAME = 1658,
     FONT_SIZE = 1659,
     PAPER_SIZE_IS_LETTER = 1660,
     PAPER_SIZE_IS_LEGAL = 1661,
     PAPER_SIZE_IS_A5 = 1662,
     PAPER_SIZE_IS_A4 = 1663,
     PAPER_SIZE_IS_LETTER_L = 1664,
     PAPER_SIZE_IS_LEGAL_L = 1665,
     PAPER_SIZE_IS_A5_L = 1666,
     PAPER_SIZE_IS_A4_L = 1667,
     FORMHANDLER = 1668,
     END_FORMHANDLER = 1669,
     BEFORE_EVENT = 1670,
     BEFORE_OPEN_FORM = 1671,
     AFTER_EVENT = 1672,
     BEFORE_CLOSE_FORM = 1673,
     BEFORE_ANY = 1674,
     AFTER_ANY = 1675,
     MENUHANDLER = 1676,
     END_MENUHANDLER = 1677,
     BEFORE_SHOW_MENU = 1678,
     DISABLE_PROGRAM = 1679,
     DISABLE_ALL = 1680,
     BUTTONS = 1681,
     CHECK_MENUITEM = 1682,
     DISABLE_FORM = 1683,
     DISABLE_MENUITEMS = 1684,
     DISABLE = 1685,
     ENABLE_FORM = 1686,
     ENABLE_MENUITEMS = 1687,
     ENABLE = 1688,
     KWFIELD = 1689,
     ICON = 1690,
     MESSAGEBOX = 1691,
     TO_DEFAULTS = 1692,
     UNCHECK_MENUITEM = 1693,
     BEFORE = 1694,
     INPUT = 1695,
     END = 1696,
     INT_TO_ID = 1697,
     TIMEOUT = 1698,
     OFF = 1699,
     WITH_1_DIMENSION = 1700,
     WITH_2_DIMENSION = 1701,
     WITH_3_DIMENSION = 1702,
     TILDE = 1703,
     ILIKE = 1704,
     FGL_ISDYNARR_ALLOCATED = 1705,
     FGL_DYNARR_EXTENTSIZE = 1706,
     FILLFACTOR = 1707
   };
#endif
#define NAME 1709
#define UMINUS 1710
#define COMMA 1615
#define KW_OR 1655
#define KW_AND 1610
#define KW_USING 1547
#define NOT 1630
#define MATCHES 1427
#define POWER 1533
#define LESS_THAN 1529
#define GREATER_THAN 1444
#define EQUAL 1605
#define GREATER_THAN_EQ 1346
#define LESS_THAN_EQ 1403
#define NOT_EQUAL 1475
#define PLUS 1641
#define MINUS 1628
#define MULTIPLY 1534
#define DIVIDE 1561
#define MOD 1629
#define COMMAND 1410
#define NUMBER_VALUE 1711
#define CHAR_VALUE 1712
#define INT_VALUE 1713
#define NAMED_GEN 1714
#define CLINE 1715
#define SQLLINE 1716
#define KW_CSTART 1717
#define KW_CEND 1718
#define USER_DTYPE 1719
#define SQL_TEXT 1720
#define KW_WHENEVER_SET 1721
#define COMMENT 1722
#define DYNAMIC_ARRAY 1000
#define RESIZE_ARRAY 1001
#define ALLOCATE_ARRAY 1002
#define DEALLOCATE_ARRAY 1003
#define AFTER_INSERT_DELETE 1004
#define BEFORE_INSERT_DELETE 1005
#define BEFORE_INSERT 1006
#define AS_CONVERTABLE 1007
#define CONCAT_PIPES 1008
#define BEFORE_DELETE 1009
#define DROP_TRIGGER 1010
#define AFTER_INSERT 1011
#define AFTER_DELETE 1012
#define EXECUTE_IMMEDIATE 1013
#define DELETE_ROW_EQUAL_TRUE 1014
#define INSERT_ROW_EQUAL_TRUE 1015
#define DELETE_ROW_EQUAL_FALSE 1016
#define INSERT_ROW_EQUAL_FALSE 1017
#define CURRENT_ROW_DISPLAY_EQUAL 1018
#define MAXCOUNT 1019
#define ALTER_TABLE 1020
#define ALTER_INDEX 1021
#define NEXT_SIZE 1022
#define DISPLAY_ATTR_FORM 1023
#define DISPLAY_ATTR_WINDOW 1024
#define INPUT_ATTR_FORM 1025
#define INPUT_ATTR_WINDOW 1026
#define WHENEVER_ERROR_CONTINUE 1027
#define WHENEVER_ANY_ERROR_CONTINUE 1028
#define WHENEVER_WARNING_CONTINUE 1029
#define WHENEVER_SQLSUCCESS_CONTINUE 1030
#define WHENEVER_SQLWARNING_CONTINUE 1031
#define WHENEVER_NOT_FOUND_CONTINUE 1032
#define WHENEVER_SQLERROR_CONTINUE 1033
#define WHENEVER_SUCCESS_CONTINUE 1034
#define WHENEVER_ERROR_GOTO 1035
#define WHENEVER_ANY_ERROR_GOTO 1036
#define WHENEVER_WARNING_GOTO 1037
#define WHENEVER_SQLSUCCESS_GOTO 1038
#define WHENEVER_SQLWARNING_GOTO 1039
#define WHENEVER_NOT_FOUND_GOTO 1040
#define WHENEVER_SQLERROR_GOTO 1041
#define WHENEVER_SUCCESS_GOTO 1042
#define WHENEVER_ERROR_CALL 1043
#define WHENEVER_ANY_ERROR_CALL 1044
#define WHENEVER_WARNING_CALL 1045
#define WHENEVER_SQLSUCCESS_CALL 1046
#define WHENEVER_SQLWARNING_CALL 1047
#define WHENEVER_NOT_FOUND_CALL 1048
#define WHENEVER_SQLERROR_CALL 1049
#define WHENEVER_SUCCESS_CALL 1050
#define WHENEVER_ERROR_STOP 1051
#define WHENEVER_ANY_ERROR_STOP 1052
#define WHENEVER_WARNING_STOP 1053
#define WHENEVER_SQLSUCCESS_STOP 1054
#define WHENEVER_SQLWARNING_STOP 1055
#define WHENEVER_NOT_FOUND_STOP 1056
#define WHENEVER_SQLERROR_STOP 1057
#define WHENEVER_SUCCESS_STOP 1058
#define XSET_MULTIPLY_EQUAL_OPEN_BRACKET 1059
#define XSET_ident_DOT_MULTIPLY_EQUAL_OPEN_BRACKET 1060
#define XSET_ident_DOT_MULTIPLY_EQUAL 1061
#define XSET_MULTIPLY_EQUAL 1062
#define XSET_OPEN_BRACKET 1063
#define NEWFORMATSHARED 1064
#define CREATE_DATABASE 1065
#define DROP_DATABASE 1066
#define IMPORT_LEGACY_FUNCTION 1067
#define ADD_CONSTRAINT 1068
#define DROP_CONSTRAINT 1069
#define DROP_SYNONYM 1070
#define CONSTRAINT 1071
#define AS_STATIC 1072
#define NOT_FIELD_TOUCHED 1073
#define LOCAL_FUNCTION 1074
#define EVERY_ROW 1075
#define ELIF 1076
#define DOUBLE_PRECISION 1077
#define COUNT_MULTIPLY 1078
#define WAIT_FOR_KEY 1079
#define AT_TERMINATION_CALL 1080
#define TERMINATE_REPORT 1081
#define TO_MAIN_CAPTION 1082
#define CLEARSTAT 1083
#define TO_MENUITEM 1084
#define ID_TO_INT 1085
#define TO_STATUSBOX 1086
#define ASCII_HEIGHT_ALL 1087
#define ASCII_WIDTH_ALL 1088
#define IMPORT_DATATYPE 1089
#define PAGE_TRAILER_SIZE 1090
#define PAGE_HEADER_SIZE 1091
#define FIRST_PAGE_HEADER_SIZE 1092
#define BYTES_USE_AS_IMAGE 1093
#define BYTES_USE_AS_ASCII 1094
#define KWUP_BY 1095
#define KWDOWN_BY 1096
#define CLOSE_STATUSBOX 1097
#define MODIFY_NEXT_SIZE 1098
#define LOCK_MODE_PAGE 1099
#define LOCK_MODE_ROW 1100
#define TO_PIPE 1101
#define TO_PRINTER 1102
#define STATUSBOX 1103
#define FORMHANDLER_INPUT 1104
#define UNITS_YEAR 1105
#define UNITS_MONTH 1106
#define UNITS_DAY 1107
#define UNITS_HOUR 1108
#define UNITS_MINUTE 1109
#define UNITS_SECOND 1110
#define NO_NEW_LINES 1111
#define FIELDTOWIDGET 1112
#define WITH_HOLD 1113
#define SHOW_MENU 1114
#define TO_CLUSTER 1115
#define TO_NOT_CLUSTER 1116
#define CWIS 1117
#define CREATE_IDX 1118
#define FORM_IS_COMPILED 1119
#define PDF_REPORT 1120
#define IMPORT_FUNCTION 1121
#define PROMPT_MANY 1122
#define POINTS 1123
#define MM 1124
#define INCHES 1125
#define PREPEND 1126
#define MEMBER_OF 1127
#define MEMBER_FUNCTION 1128
#define APPEND 1129
#define TEMPLATE 1130
#define END_TEMPLATE 1131
#define SQLSICS 1132
#define CREATE_SCHEMA 1133
#define SQLSIRR 1134
#define UPDATESTATS_T 1135
#define SQLSICR 1136
#define WHENEVER_SQLSUCCESS 1137
#define WHENEVER_SQLWARNING 1138
#define WHENEVER_ANY_ERROR 1139
#define WHENEVER_NOT_FOUND 1140
#define WHENEVER_SQLERROR 1141
#define WHENEVER_SUCCESS 1142
#define WHENEVER_ERROR 1143
#define START_EXTERN 1144
#define CONTINUE_CONSTRUCT 1145
#define FOUNCONSTR 1146
#define SQLSIDR 1147
#define CREATE_TEMP_TABLE 1148
#define CURRENT_WINDOW_IS 1149
#define FIRST_PAGE_HEADER 1150
#define ORDER_EXTERNAL_BY 1151
#define SCROLL_CURSOR_FOR 1152
#define SCROLL_CURSOR 1153
#define SQL_INTERRUPT_OFF 1154
#define STOP_ALL_EXTERNAL 1155
#define WITH_CHECK_OPTION 1156
#define WITH_GRANT_OPTION 1157
#define SQLSLMNW 1158
#define ADDCONSTUNIQ 1159
#define CONTINUE_DISPLAY 1160
#define CONTINUE_FOREACH 1161
#define OUTPUT_TO_REPORT 1162
#define SQL_INTERRUPT_ON 1163
#define WHERE_CURRENT_OF 1164
#define WITHOUT_DEFAULTS 1165
#define FOCONSTR 1166
#define SCALED_BY 1167
#define CONTINUE_PROMPT 1168
#define PDF_FUNCTION 1169
#define DEFER_INTERRUPT 1170
#define DISPLAY_BY_NAME 1171
#define NOT_NULL_UNIQUE 1172
#define SKIP_TO_TOP 1173
#define TOP_OF_PAGE 1174
#define SKIP_TO 1175
#define SKIP_BY 1176
#define WITHOUT_WAITING 1177
#define BEFCONSTRUCT 1178
#define SQLSLMW 1179
#define AFTCONSTRUCT 1180
#define ALL_PRIVILEGES 1181
#define CLOSE_DATABASE 1182
#define CONTINUE_INPUT 1183
#define CONTINUE_WHILE 1184
#define CREATE_SYNONYM 1185
#define DROP_TABLE 1186
#define EXIT_CONSTRUCT 1187
#define INEXCLUSIVE 1188
#define REPORT_TO_PRINTER 1189
#define REPORT_TO_PIPE 1190
#define RETURN 1191
#define SET_SESSION_TO 1192
#define UPDATESTATS 1193
#define WITHOUT_HEAD 1194
#define CLEARSCR 1195
#define WITH_B_LOG 1196
#define AUTHORIZATION 1197
#define BOTTOM_MARGIN 1198
#define CLOSE_SESSION 1199
#define CONTINUE_CASE 1200
#define CONTINUE_MENU 1201
#define DISPLAY_ARRAY 1202
#define END_SQL 1203
#define DOLLAR 1204
#define END_CONSTRUCT 1205
#define FIELD_TOUCHED 1206
#define FINISH_REPORT 1207
#define INFACC 1208
#define INPUT_NO_WRAP 1209
#define SETPMOFF 1210
#define UNCONSTRAINED 1211
#define PAGE_TRAILER 1212
#define SETPMON 1213
#define BEFGROUP 1214
#define CLOSE_WINDOW 1215
#define COMMENT_LINE 1216
#define CONTINUE_FOR 1217
#define CREATE_DB 1218
#define CREATE_TABLE 1219
#define DEFAULT_NULL 1220
#define DEFAULT_TODAY 1221
#define DEFAULT_USER 1222
#define DELETE_USING 1223
#define DISPLAY_FORM 1224
#define END_FUNCTION 1225
#define EXIT_DISPLAY 1226
#define EXIT_FOREACH 1227
#define EXIT_PROGRAM 1228
#define INFCOLS 1229
#define ON_EVERY_ROW 1230
#define OPEN_SESSION 1231
#define RIGHT_MARGIN 1232
#define SELECT_USING 1233
#define START_REPORT 1234
#define UNLOCK_TABLE 1235
#define UPDATE_USING 1236
#define ACL_BUILTIN 1237
#define AFTGROUP 1238
#define INFIDX 1239
#define INFSTAT 1240
#define LEFT_MARGIN 1241
#define PAGE_HEADER 1242
#define ROLLBACK_W 1243
#define SET_SESSION 1244
#define SQLSEOFF 1245
#define WITH_A_LOG 1246
#define BEFDISP 1247
#define BEFORE_MENU 1248
#define CREATE_VIEW 1249
#define DEFINE_TYPE 1250
#define DELETE_FROM 1251
#define END_DISPLAY 1252
#define END_REPORT 1253
#define END_FOREACH 1254
#define END_FOR 1255
#define END_GLOBALS 1256
#define EXIT_PROMPT 1257
#define EXTENT_SIZE 1258
#define FOREIGN_KEY 1259
#define HIDE_OPTION 1260
#define HIDE_WINDOW 1261
#define INSERT_INTO 1262
#define IS_NOT_NULL 1263
#define MOVE_WINDOW 1264
#define NEXT_OPTION 1265
#define NOT_MATCHES 1266
#define ON_LAST_ROW 1267
#define OPEN_WINDOW 1268
#define OPEN_STATUSBOX 1269
#define PAGE_LENGTH 1270
#define PAGE_WIDTH 1271
#define PRIMARY_KEY 1272
#define PROMPT_LINE 1273
#define RECORD_LIKE 1274
#define ROLLFORWARD 1275
#define SETBL 1276
#define SHOW_OPTION 1277
#define SHOW_WINDOW 1278
#define SQLSEON 1279
#define TO_DATABASE 1280
#define USE_SESSION 1281
#define WITH_NO_LOG 1282
#define AFTDISP 1283
#define BEFFIELD 1284
#define INSHARE 1285
#define UNLOCKTAB 1286
#define AFTFIELD 1287
#define ATTRIBUTES 1288
#define BEFINP 1289
#define BEGIN_WORK 1290
#define CLEARWIN 1291
#define CLOSE_FORM 1292
#define DEFER_QUIT 1293
#define DESCENDING 1294
#define DROP_INDEX 1295
#define END_PROMPT 1296
#define END_RECORD 1297
#define ERROR_LINE 1298
#define EXIT_INPUT 1299
#define EXIT_WHILE 1300
#define FOR_UPDATE_OF 1301
#define FOR_UPDATE 1302
#define GET_FLDBUF 1303
#define INITIALIZE 1304
#define INPUT_WRAP 1305
#define LOCK_TABLE 1306
#define MSG_LINE 1307
#define NOT_EXISTS 1308
#define ON_ANY_KEY 1309
#define REFERENCES 1310
#define RENCOL 1311
#define SET_CURSOR 1312
#define SMALLFLOAT 1313
#define SQLSUCCESS 1314
#define TOP_MARGIN 1315
#define WITH_ARRAY 1316
#define ACCEPTKEY 1317
#define ACCEPT 1318
#define AFTINP 1319
#define CLEARFORMTODEFAULTS 1320
#define CLEARFORM 1321
#define CLEAR_X_FORM 1322
#define COMMIT_W 1323
#define NEXTPAGE 1324
#define PREVPAGE 1325
#define CTRL_KEY 1326
#define INFTABS 1327
#define NEXTFIELD 1328
#define NEXTFORM 1329
#define RENTAB 1330
#define ASCENDING 1331
#define ASSOCIATE 1332
#define CHAR 1333
#define NCHAR 1334
#define NVARCHAR 1335
#define CONSTRUCT 1336
#define DELIMITER 1337
#define DOWNSHIFT 1338
#define DROP_VIEW 1339
#define END_INPUT 1340
#define END_WHILE 1341
#define EXCLUSIVE 1342
#define EXIT_CASE 1343
#define EXIT_MENU 1344
#define FORM_LINE 1345
#define INTERRUPT 1347
#define INTO_TEMP 1348
#define INVISIBLE 1349
#define IN_MEMORY 1350
#define LINKED_TO 1351
#define LOAD_FROM 1352
#define LOCKTAB 1353
#define MENU_LINE 1354
#define OPEN_FORM 1355
#define OTHERWISE 1356
#define PRECISION 1357
#define PRIOR 1358
#define PROCEDURE 1359
#define REPORT_TO 1360
#define RETURNING 1361
#define UNDERLINE 1362
#define UNLOAD_TO 1363
#define BEFROW 1364
#define UNLOAD_T 1365
#define VARIABLE 1366
#define ABSOLUTE 1367
#define AFTROW 1368
#define BUFFERED 1369
#define CONSTANT 1370
#define CONST 1371
#define DATABASE 1372
#define DATETIME 1373
#define DEFAULTS 1374
#define DISTINCT 1375
#define END_CASE 1376
#define END_MAIN 1377
#define END_MENU 1378
#define END_TYPE 1379
#define EXIT_FOR 1380
#define EXTERNAL 1381
#define FRACTION 1382
#define FUNCTION 1383
#define GROUP_BY 1384
#define INTERVAL 1385
#define KWMESSAGE 1386
#define NOT_LIKE 1387
#define NOT_ILIKE 1388
#define NOT_NULL 1389
#define PASSWORD 1390
#define PREVIOUS 1391
#define READONLY 1392
#define REGISTER 1393
#define RELATIVE 1394
#define RESOURCE 1395
#define SMALLINT 1396
#define VALIDATE 1397
#define WITH_LOG 1398
#define WORDWRAP 1399
#define BY_NAME 1400
#define IN_FILE 1401
#define IS_NULL 1402
#define AVERAGE 1404
#define BETWEEN 1405
#define CAPTION 1406
#define CLIPPED 1407
#define CLOSE_BRACKET 1408
#define COLUMNS 1409
#define CONNECT 1411
#define CURRENT 1412
#define DBYNAME 1413
#define DECIMAL 1414
#define DECLARE 1415
#define DEFAULT 1416
#define DISPLAY 1417
#define ENDCODE 1418
#define EXECUTE 1419
#define FOREACH 1420
#define FOREIGN 1421
#define GLOBALS 1422
#define INFIELD 1423
#define INTEGER 1424
#define KWWINDOW 1425
#define MAGENTA 1426
#define OPTIONS 1428
#define PERCENT 1429
#define PREPARE 1430
#define PROGRAM 1431
#define RECOVER 1432
#define REVERSE 1433
#define SECTION 1434
#define SESSION 1435
#define SYNONYM 1436
#define THRU 1437
#define TRAILER 1438
#define UPSHIFT 1439
#define VARCHAR 1440
#define WAITING 1441
#define CLOSE_SHEV 1442
#define CLOSE_SQUARE 1443
#define KW_FALSE 1445
#define NOT_IN 1446
#define ONKEY 1447
#define OPEN_BRACKET 1448
#define BORDER 1449
#define BOTTOM 1450
#define COLUMN 1451
#define COMMIT 1452
#define CREATE 1453
#define CURSOR 1454
#define DEFINE 1455
#define DELETE 1456
#define DOUBLE 1457
#define END_IF 1458
#define ESCAPE 1459
#define EXISTS 1460
#define EXTEND 1461
#define EXTENT 1462
#define FINISH 1463
#define FORMAT 1464
#define HAVING 1465
#define HEADER 1466
#define INSERT 1467
#define LOCATE 1468
#define MARGIN 1469
#define MEMORY 1470
#define MINUTE 1471
#define MODIFY 1472
#define NORMAL 1473
#define EQUAL_EQUAL 1474
#define OPEN_SHEV 1476
#define OPEN_SQUARE 1477
#define OPTION 1478
#define OUTPUT 1479
#define PROMPT 1480
#define PUBLIC 1481
#define RECORD 1482
#define REPORT 1483
#define REVOKE 1484
#define SCHEMA 1485
#define SCROLL_USING 1486
#define SCROLL 1487
#define SECOND 1488
#define SELECT 1489
#define SERIAL 1490
#define SETL 1491
#define SHARED 1492
#define SPACES 1493
#define UNIQUE 1494
#define UNLOCK 1495
#define UPDATE 1496
#define VALUES 1497
#define YELLOW 1498
#define AFTER 1499
#define KWLINE 1500
#define KW_NULL 1501
#define KW_TRUE 1502
#define SINGLE_KEY 1503
#define ALTER 1504
#define ARRAY 1505
#define ASCII 1506
#define AUDIT 1507
#define BLACK 1508
#define BLINK 1509
#define CHECK 1510
#define CLEAR 1511
#define CLOSE 1512
#define CODE_C 1513
#define COUNT 1514
#define DEFER 1515
#define ERROR 1516
#define EVERY 1517
#define FETCH 1518
#define FIRST 1519
#define FLOAT 1520
#define FLUSH 1521
#define FOUND 1522
#define GRANT 1523
#define GREEN 1524
#define GROUP 1525
#define INDEX 1526
#define KWFORM 1527
#define LABEL 1528
#define LOCAL 1530
#define MONEY 1531
#define MONTH 1532
#define ORDER 1535
#define OUTER 1536
#define PAUSE 1537
#define PRINT_IMAGE 1538
#define PRINT_FILE 1539
#define PRINT 1540
#define RIGHT 1541
#define DOUBLE_COLON 1542
#define SEMICOLON 1543
#define SLEEP 1544
#define TUPLE 1545
#define UNION 1546
#define WHERE 1548
#define WHILE 1549
#define WHITE 1550
#define CCODE 1551
#define ANSI 1552
#define BLUE 1553
#define BOLD 1554
#define BYTE 1555
#define FCALL 1556
#define CASE 1557
#define CYAN 1558
#define DATE 1559
#define DESC 1560
#define KWDOWN 1562
#define TAB 1563
#define DROP 1564
#define ELSE 1565
#define EXEC 1566
#define EXIT 1567
#define FREE 1568
#define FROM 1569
#define GOTO 1570
#define HELP_FILE 1571
#define LANG_FILE 1572
#define HELP 1573
#define HIDE 1574
#define HOUR 1575
#define INTO 1576
#define LAST 1577
#define LEFT 1578
#define LIKE 1579
#define MAIN 1580
#define MENU 1581
#define MODE 1582
#define NEED 1583
#define NEXT 1584
#define NOCR 1585
#define OPEN 1586
#define QUIT 1587
#define REAL 1588
#define ROWS 1589
#define SHOW 1590
#define SIZE 1591
#define SKIP 1592
#define SOME 1593
#define STEP 1594
#define STOP 1595
#define TEMP 1596
#define TEXT 1597
#define THEN 1598
#define USER 1599
#define WAIT 1600
#define WHEN 1601
#define WITH 1602
#define WORK 1603
#define YEAR 1604
#define KW_IS 1606
#define XSET 1607
#define ADD 1608
#define ALL 1609
#define ANY 1611
#define ASC 1612
#define AVG 1613
#define COLON 1614
#define DAY 1616
#define DBA 1617
#define DEC 1618
#define DIM 1619
#define FKEY 1620
#define FOR 1621
#define KEY 1622
#define KWNO 1623
#define LET 1624
#define LOG 1625
#define XMAX 1626
#define XMIN 1627
#define PAD 1631
#define PUT 1632
#define RED 1633
#define ROW 1634
#define RUN 1635
#define SQL 1636
#define SUM 1637
#define TOP 1638
#define USE 1639
#define ATSIGN 1640
#define AS_TIFF 1642
#define AS_GIF 1643
#define AS_PNG 1644
#define AS_JPEG 1645
#define AS 1646
#define AT 1647
#define BY 1648
#define DOT 1649
#define GO 1650
#define IF 1651
#define IN 1652
#define OF 1653
#define ON 1654
#define TO 1656
#define KWUP 1657
#define FONT_NAME 1658
#define FONT_SIZE 1659
#define PAPER_SIZE_IS_LETTER 1660
#define PAPER_SIZE_IS_LEGAL 1661
#define PAPER_SIZE_IS_A5 1662
#define PAPER_SIZE_IS_A4 1663
#define PAPER_SIZE_IS_LETTER_L 1664
#define PAPER_SIZE_IS_LEGAL_L 1665
#define PAPER_SIZE_IS_A5_L 1666
#define PAPER_SIZE_IS_A4_L 1667
#define FORMHANDLER 1668
#define END_FORMHANDLER 1669
#define BEFORE_EVENT 1670
#define BEFORE_OPEN_FORM 1671
#define AFTER_EVENT 1672
#define BEFORE_CLOSE_FORM 1673
#define BEFORE_ANY 1674
#define AFTER_ANY 1675
#define MENUHANDLER 1676
#define END_MENUHANDLER 1677
#define BEFORE_SHOW_MENU 1678
#define DISABLE_PROGRAM 1679
#define DISABLE_ALL 1680
#define BUTTONS 1681
#define CHECK_MENUITEM 1682
#define DISABLE_FORM 1683
#define DISABLE_MENUITEMS 1684
#define DISABLE 1685
#define ENABLE_FORM 1686
#define ENABLE_MENUITEMS 1687
#define ENABLE 1688
#define KWFIELD 1689
#define ICON 1690
#define MESSAGEBOX 1691
#define TO_DEFAULTS 1692
#define UNCHECK_MENUITEM 1693
#define BEFORE 1694
#define INPUT 1695
#define END 1696
#define INT_TO_ID 1697
#define TIMEOUT 1698
#define OFF 1699
#define WITH_1_DIMENSION 1700
#define WITH_2_DIMENSION 1701
#define WITH_3_DIMENSION 1702
#define TILDE 1703
#define ILIKE 1704
#define FGL_ISDYNARR_ALLOCATED 1705
#define FGL_DYNARR_EXTENTSIZE 1706
#define FILLFACTOR 1707




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
#include "var_handling.h"

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
int 		doing_a_print=0;

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
#line 214 "fgl.yacc"
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
/* Line 191 of yacc.c.  */
#line 1702 "y.tab.c"
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 214 of yacc.c.  */
#line 1714 "y.tab.c"

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
#define YYFINAL  44
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   11129

/* YYNTOKENS -- Number of terminals. */
#define YYNTOKENS  725
/* YYNNTS -- Number of nonterminals. */
#define YYNNTS  865
/* YYNRULES -- Number of rules. */
#define YYNRULES  2357
/* YYNRULES -- Number of states. */
#define YYNSTATES  3768

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   1722

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
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    93,    94,    95,
      96,    97,    98,    99,   100,   101,   102,   103,   104,   105,
     106,   107,   108,   109,   110,   111,   112,   113,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   131,   132,   133,   134,   135,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
     146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,   158,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,   173,   174,   175,
     176,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,   192,   193,   194,   195,
     196,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
     256,   257,   258,   259,   260,   261,   262,   263,   264,   265,
     266,   267,   268,   269,   270,   271,   272,   273,   274,   275,
     276,   277,   278,   279,   280,   281,   282,   283,   284,   285,
     286,   287,   288,   289,   290,   291,   292,   293,   294,   295,
     296,   297,   298,   299,   300,   301,   302,   303,   304,   305,
     306,   307,   308,   309,   310,   311,   312,   313,   314,   315,
     316,   317,   318,   319,   320,   321,   322,   323,   324,   325,
     326,   327,   328,   329,   330,   331,   332,   333,   334,   335,
     336,   337,   338,   339,   340,   341,   342,   343,   344,   345,
     346,   347,   348,   349,   350,   351,   352,   353,   354,   355,
     356,   357,   358,   359,   360,   361,   362,   363,   364,   365,
     366,   367,   368,   369,   370,   371,   372,   373,   374,   375,
     376,   377,   378,   379,   380,   381,    15,   382,   383,   384,
     385,   386,   387,   388,   389,   390,   391,   392,   393,   394,
     395,   396,   397,   398,   399,   400,   401,   402,   403,   404,
     405,   406,   407,   408,   409,   410,   411,   412,   413,   414,
     415,   416,   417,   418,   419,   420,   421,   422,   423,   424,
     425,   426,   427,   428,   429,   430,   431,   432,   433,   434,
     435,   436,   437,    16,   438,   439,   440,   441,   442,   443,
      23,   444,   445,   446,   447,   448,   449,   450,   451,   452,
     453,   454,   455,   456,   457,   458,   459,    10,   460,   461,
     462,   463,   464,   465,   466,   467,   468,   469,   470,   471,
     472,   473,   474,   475,    13,   476,   477,   478,   479,   480,
     481,   482,   483,   484,   485,   486,   487,   488,   489,   490,
     491,   492,   493,   494,   495,   496,   497,   498,   499,   500,
     501,   502,   503,   504,   505,    17,   506,   507,   508,   509,
     510,   511,   512,   513,   514,   515,   516,   517,   518,   519,
     520,   521,   522,   523,   524,   525,   526,   527,   528,   529,
     530,   531,   532,   533,   534,   535,   536,   537,   538,   539,
     540,   541,   542,   543,   544,   545,   546,   547,   548,   549,
     550,   551,   552,   553,   554,   555,   556,   557,   558,    12,
     559,   560,   561,    11,    20,   562,   563,   564,   565,   566,
     567,   568,   569,   570,   571,   572,   573,     8,   574,   575,
     576,   577,   578,   579,   580,   581,   582,   583,   584,   585,
     586,    21,   587,   588,   589,   590,   591,   592,   593,   594,
     595,   596,   597,   598,   599,   600,   601,   602,   603,   604,
     605,   606,   607,   608,   609,   610,   611,   612,   613,   614,
     615,   616,   617,   618,   619,   620,   621,   622,   623,   624,
     625,   626,   627,   628,   629,    14,   630,   631,   632,   633,
       7,   634,   635,   636,   637,     5,   638,   639,   640,   641,
     642,   643,   644,   645,   646,   647,   648,   649,    19,    22,
       9,   650,   651,   652,   653,   654,   655,   656,   657,   658,
     659,    18,   660,   661,   662,   663,   664,   665,   666,   667,
     668,   669,   670,   671,   672,     6,   673,   674,   675,   676,
     677,   678,   679,   680,   681,   682,   683,   684,   685,   686,
     687,   688,   689,   690,   691,   692,   693,   694,   695,   696,
     697,   698,   699,   700,   701,   702,   703,   704,   705,   706,
     707,   708,   709,   710,   711,   712,   713,   714,   715,   716,
     717,   718,   719,   720,   721,   722,   723,   724,     2,     3,
       4,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35
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
     289,   291,   293,   297,   298,   305,   306,   312,   314,   317,
     319,   322,   324,   325,   326,   330,   331,   332,   336,   337,
     342,   343,   348,   351,   354,   357,   359,   362,   365,   369,
     371,   373,   375,   378,   380,   382,   385,   387,   388,   389,
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
     687,   689,   691,   696,   701,   706,   713,   718,   725,   727,
     730,   732,   734,   736,   738,   743,   750,   752,   757,   764,
     765,   769,   770,   774,   775,   779,   781,   783,   785,   787,
     789,   792,   795,   797,   799,   800,   804,   809,   811,   813,
     814,   818,   822,   823,   826,   828,   830,   832,   834,   836,
     838,   841,   842,   845,   846,   850,   851,   855,   857,   858,
     862,   864,   866,   868,   870,   872,   874,   877,   879,   880,
     882,   883,   889,   891,   893,   895,   900,   905,   912,   914,
     916,   918,   920,   925,   932,   934,   939,   946,   948,   950,
     952,   954,   956,   959,   962,   964,   969,   970,   978,   979,
     992,   993,   998,   999,  1005,  1007,  1011,  1014,  1016,  1020,
    1022,  1023,  1026,  1029,  1031,  1034,  1040,  1045,  1048,  1053,
    1059,  1063,  1064,  1065,  1077,  1078,  1081,  1083,  1084,  1087,
    1089,  1091,  1094,  1095,  1099,  1100,  1104,  1105,  1109,  1112,
    1115,  1118,  1123,  1129,  1131,  1134,  1136,  1138,  1140,  1142,
    1144,  1146,  1148,  1150,  1152,  1154,  1156,  1158,  1160,  1162,
    1164,  1166,  1168,  1170,  1172,  1174,  1176,  1179,  1181,  1183,
    1185,  1188,  1191,  1193,  1195,  1197,  1199,  1201,  1203,  1205,
    1207,  1209,  1211,  1214,  1216,  1219,  1221,  1223,  1225,  1229,
    1231,  1235,  1237,  1241,  1243,  1245,  1247,  1250,  1252,  1254,
    1258,  1263,  1268,  1271,  1274,  1276,  1278,  1280,  1282,  1284,
    1288,  1290,  1293,  1296,  1298,  1299,  1303,  1306,  1309,  1311,
    1315,  1320,  1325,  1331,  1337,  1339,  1341,  1344,  1347,  1352,
    1357,  1360,  1363,  1368,  1373,  1375,  1378,  1381,  1384,  1387,
    1390,  1393,  1396,  1399,  1402,  1405,  1408,  1411,  1414,  1417,
    1418,  1419,  1420,  1427,  1428,  1429,  1438,  1439,  1440,  1447,
    1448,  1449,  1456,  1457,  1458,  1465,  1466,  1467,  1474,  1480,
    1486,  1492,  1500,  1508,  1518,  1523,  1530,  1531,  1535,  1537,
    1539,  1544,  1549,  1554,  1559,  1564,  1569,  1571,  1573,  1575,
    1577,  1582,  1587,  1590,  1593,  1596,  1599,  1602,  1604,  1606,
    1609,  1611,  1613,  1615,  1618,  1623,  1630,  1637,  1641,  1647,
    1653,  1657,  1659,  1661,  1665,  1667,  1671,  1673,  1677,  1678,
    1679,  1680,  1690,  1691,  1695,  1696,  1697,  1708,  1709,  1711,
    1712,  1714,  1716,  1719,  1720,  1724,  1725,  1729,  1730,  1732,
    1734,  1737,  1738,  1742,  1743,  1747,  1751,  1753,  1758,  1762,
    1764,  1768,  1770,  1774,  1776,  1780,  1782,  1785,  1786,  1790,
    1791,  1795,  1796,  1801,  1802,  1807,  1808,  1813,  1814,  1815,
    1827,  1828,  1831,  1834,  1838,  1840,  1844,  1846,  1848,  1850,
    1852,  1854,  1856,  1858,  1862,  1864,  1866,  1871,  1878,  1883,
    1887,  1894,  1898,  1905,  1907,  1909,  1911,  1913,  1915,  1917,
    1919,  1921,  1922,  1925,  1927,  1929,  1931,  1936,  1938,  1940,
    1942,  1947,  1951,  1958,  1962,  1969,  1971,  1973,  1976,  1979,
    1981,  1984,  1987,  1989,  1993,  1995,  1998,  2001,  2004,  2009,
    2012,  2015,  2020,  2021,  2030,  2031,  2033,  2035,  2037,  2038,
    2040,  2043,  2044,  2046,  2049,  2050,  2052,  2055,  2056,  2058,
    2062,  2063,  2066,  2067,  2068,  2077,  2078,  2079,  2083,  2084,
    2085,  2093,  2099,  2102,  2105,  2106,  2112,  2117,  2119,  2123,
    2127,  2131,  2133,  2134,  2137,  2139,  2140,  2142,  2144,  2147,
    2148,  2153,  2154,  2159,  2160,  2164,  2165,  2169,  2170,  2174,
    2175,  2179,  2180,  2184,  2185,  2189,  2190,  2194,  2195,  2199,
    2200,  2204,  2205,  2209,  2210,  2214,  2216,  2220,  2222,  2226,
    2229,  2234,  2236,  2238,  2240,  2241,  2246,  2252,  2259,  2260,
    2271,  2275,  2278,  2281,  2283,  2285,  2288,  2291,  2292,  2295,
    2297,  2300,  2304,  2308,  2312,  2316,  2318,  2320,  2322,  2324,
    2325,  2329,  2331,  2332,  2336,  2339,  2342,  2344,  2348,  2350,
    2354,  2356,  2358,  2360,  2362,  2364,  2366,  2368,  2370,  2372,
    2374,  2376,  2378,  2380,  2382,  2384,  2386,  2388,  2390,  2392,
    2394,  2395,  2396,  2404,  2406,  2408,  2411,  2414,  2417,  2421,
    2426,  2427,  2431,  2432,  2434,  2436,  2439,  2441,  2443,  2445,
    2447,  2449,  2451,  2452,  2454,  2456,  2459,  2462,  2464,  2466,
    2468,  2470,  2472,  2474,  2476,  2478,  2480,  2482,  2484,  2485,
    2487,  2489,  2491,  2493,  2494,  2495,  2496,  2497,  2511,  2513,
    2514,  2515,  2522,  2525,  2527,  2530,  2533,  2536,  2538,  2540,
    2543,  2545,  2546,  2550,  2553,  2555,  2557,  2559,  2560,  2561,
    2562,  2577,  2578,  2579,  2587,  2589,  2592,  2593,  2597,  2598,
    2603,  2604,  2610,  2612,  2613,  2617,  2618,  2626,  2627,  2633,
    2635,  2638,  2639,  2641,  2643,  2645,  2646,  2648,  2650,  2653,
    2656,  2659,  2661,  2663,  2665,  2667,  2671,  2673,  2675,  2678,
    2679,  2682,  2684,  2686,  2688,  2690,  2692,  2694,  2696,  2700,
    2701,  2703,  2705,  2707,  2709,  2712,  2715,  2718,  2724,  2733,
    2735,  2737,  2739,  2744,  2749,  2751,  2753,  2755,  2757,  2760,
    2764,  2771,  2773,  2777,  2779,  2781,  2783,  2787,  2794,  2804,
    2806,  2808,  2810,  2812,  2815,  2816,  2818,  2820,  2824,  2826,
    2830,  2832,  2836,  2838,  2842,  2844,  2846,  2848,  2850,  2854,
    2856,  2860,  2862,  2866,  2868,  2870,  2872,  2876,  2879,  2880,
    2882,  2884,  2886,  2890,  2892,  2896,  2904,  2905,  2913,  2914,
    2921,  2925,  2927,  2931,  2933,  2936,  2942,  2943,  2951,  2952,
    2955,  2956,  2958,  2964,  2967,  2973,  2974,  2980,  2987,  2992,
    2993,  2995,  2997,  3003,  3004,  3007,  3008,  3014,  3019,  3022,
    3024,  3028,  3031,  3034,  3037,  3040,  3043,  3046,  3048,  3051,
    3054,  3057,  3060,  3063,  3066,  3069,  3071,  3073,  3075,  3077,
    3080,  3083,  3085,  3087,  3089,  3091,  3093,  3095,  3101,  3103,
    3105,  3108,  3113,  3118,  3125,  3128,  3130,  3131,  3143,  3144,
    3147,  3153,  3154,  3156,  3157,  3160,  3162,  3165,  3166,  3170,
    3172,  3173,  3178,  3179,  3182,  3184,  3188,  3190,  3192,  3197,
    3203,  3209,  3213,  3214,  3216,  3218,  3220,  3222,  3223,  3225,
    3233,  3236,  3239,  3242,  3245,  3248,  3250,  3253,  3254,  3258,
    3259,  3263,  3264,  3268,  3269,  3273,  3274,  3278,  3279,  3284,
    3285,  3290,  3292,  3294,  3296,  3298,  3300,  3302,  3303,  3308,
    3309,  3311,  3312,  3317,  3319,  3322,  3325,  3328,  3329,  3331,
    3333,  3336,  3339,  3340,  3343,  3344,  3349,  3353,  3359,  3360,
    3363,  3368,  3370,  3372,  3374,  3376,  3378,  3379,  3381,  3383,
    3387,  3390,  3396,  3399,  3405,  3411,  3417,  3423,  3429,  3435,
    3436,  3439,  3441,  3444,  3447,  3450,  3453,  3456,  3459,  3461,
    3464,  3467,  3470,  3473,  3475,  3478,  3481,  3484,  3487,  3489,
    3491,  3493,  3494,  3497,  3500,  3503,  3506,  3509,  3512,  3515,
    3518,  3521,  3523,  3525,  3527,  3529,  3531,  3533,  3535,  3537,
    3540,  3543,  3546,  3549,  3552,  3554,  3556,  3558,  3559,  3563,
    3566,  3567,  3568,  3569,  3570,  3571,  3572,  3588,  3589,  3592,
    3595,  3596,  3598,  3599,  3600,  3601,  3602,  3603,  3604,  3620,
    3623,  3624,  3625,  3626,  3637,  3638,  3640,  3644,  3648,  3651,
    3656,  3660,  3664,  3668,  3670,  3673,  3676,  3679,  3682,  3684,
    3686,  3687,  3688,  3697,  3698,  3699,  3709,  3710,  3712,  3714,
    3717,  3720,  3723,  3726,  3728,  3730,  3732,  3733,  3735,  3737,
    3740,  3743,  3746,  3755,  3758,  3761,  3766,  3769,  3770,  3772,
    3774,  3778,  3781,  3784,  3786,  3788,  3792,  3794,  3796,  3799,
    3801,  3805,  3809,  3813,  3815,  3819,  3821,  3823,  3825,  3827,
    3829,  3831,  3833,  3836,  3841,  3843,  3847,  3849,  3853,  3856,
    3861,  3863,  3867,  3869,  3872,  3877,  3879,  3883,  3885,  3887,
    3889,  3892,  3896,  3901,  3904,  3909,  3910,  3913,  3916,  3921,
    3923,  3927,  3929,  3931,  3933,  3936,  3938,  3940,  3942,  3944,
    3946,  3949,  3956,  3963,  3964,  3966,  3967,  3969,  3972,  3974,
    3975,  3981,  3982,  3988,  3990,  3991,  3995,  3997,  4001,  4003,
    4007,  4009,  4011,  4012,  4017,  4019,  4022,  4024,  4025,  4026,
    4030,  4031,  4032,  4036,  4038,  4040,  4042,  4044,  4046,  4048,
    4051,  4054,  4059,  4063,  4067,  4069,  4073,  4076,  4078,  4080,
    4081,  4083,  4085,  4087,  4089,  4090,  4092,  4096,  4098,  4102,
    4104,  4105,  4109,  4111,  4113,  4115,  4117,  4119,  4121,  4123,
    4125,  4127,  4129,  4131,  4133,  4141,  4148,  4153,  4158,  4160,
    4162,  4164,  4165,  4167,  4170,  4172,  4174,  4176,  4178,  4182,
    4185,  4187,  4189,  4192,  4194,  4196,  4197,  4201,  4203,  4207,
    4209,  4213,  4215,  4217,  4224,  4225,  4229,  4231,  4235,  4236,
    4238,  4243,  4249,  4252,  4254,  4256,  4261,  4263,  4267,  4272,
    4277,  4282,  4284,  4288,  4290,  4292,  4294,  4297,  4299,  4301,
    4303,  4308,  4309,  4311,  4312,  4314,  4316,  4319,  4322,  4324,
    4326,  4328,  4330,  4332,  4337,  4339,  4343,  4345,  4347,  4349,
    4352,  4354,  4356,  4359,  4362,  4364,  4368,  4371,  4374,  4376,
    4380,  4382,  4385,  4390,  4392,  4395,  4397,  4401,  4406,  4407,
    4409,  4410,  4412,  4413,  4415,  4417,  4421,  4423,  4427,  4429,
    4432,  4434,  4438,  4441,  4444,  4445,  4448,  4450,  4452,  4458,
    4462,  4468,  4472,  4474,  4478,  4480,  4482,  4483,  4485,  4489,
    4493,  4497,  4504,  4509,  4514,  4519,  4524,  4530,  4532,  4534,
    4536,  4538,  4540,  4542,  4544,  4546,  4548,  4550,  4552,  4554,
    4555,  4557,  4559,  4561,  4563,  4565,  4567,  4569,  4574,  4575,
    4577,  4582,  4584,  4590,  4596,  4598,  4600,  4602,  4604,  4606,
    4611,  4613,  4618,  4625,  4630,  4632,  4637,  4639,  4647,  4649,
    4651,  4653,  4658,  4665,  4666,  4669,  4674,  4676,  4678,  4680,
    4682,  4684,  4686,  4688,  4692,  4694,  4696,  4700,  4706,  4710,
    4716,  4724,  4728,  4730,  4732,  4736,  4742,  4746,  4752,  4760,
    4762,  4763,  4767,  4773,  4775,  4778,  4781,  4786,  4790,  4792,
    4794,  4796,  4798,  4800,  4803,  4806,  4807,  4811,  4812,  4816,
    4818,  4820,  4822,  4824,  4826,  4828,  4830,  4835,  4837,  4839,
    4841,  4843,  4845,  4847,  4849,  4854,  4856,  4858,  4860,  4862,
    4864,  4866,  4868,  4870,  4872,  4874,  4876,  4878,  4880,  4882,
    4887,  4889,  4893,  4895,  4899,  4900,  4908,  4909,  4918,  4919,
    4926,  4927,  4936,  4937,  4939,  4942,  4944,  4948,  4950,  4954,
    4960,  4962,  4964,  4966,  4968,  4970,  4971,  4972,  4982,  4988,
    4990,  4992,  4999,  5000,  5004,  5006,  5010,  5015,  5017,  5018,
    5021,  5026,  5033,  5034,  5036,  5038,  5040,  5042,  5046,  5048,
    5051,  5055,  5057,  5059,  5062,  5065,  5067,  5069,  5071,  5074,
    5077,  5080,  5083,  5088,  5092,  5095,  5099,  5103,  5107,  5109,
    5111,  5113,  5115,  5117,  5119,  5125,  5131,  5137,  5143,  5149,
    5154,  5159,  5163,  5168,  5170,  5172,  5174,  5178,  5180,  5186,
    5194,  5200,  5201,  5204,  5206,  5208,  5209,  5213,  5215,  5219,
    5221,  5223,  5225,  5226,  5230,  5232,  5234,  5236,  5238,  5243,
    5250,  5252,  5254,  5257,  5261,  5263,  5265,  5267,  5269,  5271,
    5273,  5275,  5277,  5283,  5289,  5294,  5300,  5302,  5307,  5312,
    5317,  5324,  5331,  5340,  5349,  5363,  5375,  5377,  5385,  5390,
    5395,  5400,  5407,  5414,  5423,  5432,  5433,  5438,  5440,  5443,
    5445,  5447,  5449,  5451,  5453,  5455,  5457,  5459,  5461,  5463,
    5465,  5467,  5469,  5471,  5473,  5475,  5477,  5479,  5481,  5483,
    5485,  5487,  5489,  5491,  5493,  5495,  5497,  5499,  5501,  5503,
    5505,  5507,  5509,  5511,  5513,  5515,  5517,  5519,  5521,  5523,
    5525,  5527,  5529,  5531,  5533,  5535,  5537,  5539,  5541,  5543,
    5545,  5547,  5549,  5551,  5553,  5555,  5557,  5559,  5561,  5563,
    5565,  5567,  5569,  5571,  5573,  5575,  5577,  5579,  5581,  5583,
    5585,  5587,  5589,  5591,  5593,  5595,  5597,  5599,  5601,  5603,
    5605,  5607,  5609,  5611,  5613,  5615,  5617,  5619,  5621,  5623,
    5625,  5627,  5629,  5631,  5633,  5635,  5637,  5639,  5641,  5643,
    5645,  5647,  5649,  5651,  5653,  5655,  5657,  5659,  5661,  5663,
    5665,  5667,  5669,  5671,  5673,  5675,  5677,  5679,  5681,  5683,
    5685,  5687,  5689,  5691,  5693,  5695,  5697,  5699,  5701,  5703,
    5705,  5707,  5709,  5711,  5713,  5715,  5717,  5719,  5721,  5723,
    5725,  5727,  5729,  5731,  5733,  5735,  5737,  5739,  5741,  5743,
    5745,  5747,  5749,  5751,  5753,  5755,  5757,  5759,  5761,  5763,
    5765,  5767,  5769,  5771,  5773,  5775,  5777,  5779,  5781,  5783,
    5785,  5787,  5789,  5791,  5793,  5795,  5797,  5799,  5801,  5803,
    5805,  5807,  5809,  5811,  5813,  5815,  5817,  5819,  5821,  5823,
    5825,  5827,  5829,  5831,  5833,  5835,  5837,  5839,  5841,  5843,
    5845,  5847,  5849,  5851,  5853,  5855,  5857,  5859,  5861,  5863,
    5865,  5867,  5869,  5871,  5873,  5875,  5877,  5879,  5881,  5883,
    5885,  5887,  5889,  5891,  5893,  5895,  5897,  5899,  5901,  5903,
    5905,  5907,  5909,  5911,  5913,  5915,  5917,  5919,  5921,  5923,
    5925,  5927,  5929,  5931,  5933,  5935,  5937,  5939,  5941,  5943,
    5945,  5947,  5949,  5951,  5953,  5955,  5957,  5959,  5961,  5963,
    5965,  5967,  5969,  5971,  5973,  5975,  5977,  5979,  5981,  5983,
    5985,  5987,  5989,  5991,  5993,  5995,  5997,  5999,  6001,  6003,
    6005,  6007,  6009,  6011,  6013,  6015,  6017,  6019,  6021,  6023,
    6025,  6027,  6029,  6031,  6033,  6035,  6037,  6039,  6041,  6043,
    6045,  6047,  6049,  6051,  6053,  6055,  6057,  6059,  6061,  6063,
    6065,  6067,  6069,  6071,  6073,  6075,  6077,  6079,  6080,  6084,
    6085,  6089,  6090,  6091,  6098,  6099,  6102,  6105,  6113,  6117,
    6121,  6124,  6127,  6130,  6132,  6136,  6138,  6142,  6144,  6148,
    6150,  6154,  6156,  6158,  6160,  6163,  6166,  6168,  6170,  6173,
    6178,  6184,  6192,  6200,  6210,  6212,  6214,  6216,  6218,  6220,
    6222,  6226,  6229,  6233,  6237,  6241,  6247,  6253,  6259,  6265,
    6271,  6276,  6281,  6285,  6290,  6292,  6294,  6296,  6298,  6302,
    6303,  6309,  6311,  6315,  6319,  6323,  6325,  6327,  6330,  6332,
    6334,  6338,  6340,  6344,  6348,  6350,  6352,  6354,  6358,  6361,
    6365,  6372,  6374,  6378,  6380,  6382,  6383,  6384,  6391,  6392,
    6395,  6396,  6398,  6400,  6403,  6406,  6408,  6410,  6415,  6419,
    6421,  6424,  6430,  6433,  6436,  6442,  6443,  6446,  6448,  6450,
    6453,  6460,  6467,  6469,  6470,  6472,  6475,  6477,  6480,  6481,
    6484,  6486,  6488,  6490,  6492,  6494,  6496,  6498,  6500,  6502,
    6504,  6506,  6508,  6510,  6512,  6514,  6516,  6518,  6520,  6522,
    6524,  6526,  6528,  6530,  6532,  6534,  6536,  6538,  6540,  6542,
    6544,  6546,  6548,  6550,  6552,  6554,  6556,  6558,  6560,  6562,
    6564,  6566,  6568,  6570,  6572,  6574,  6576,  6578,  6580,  6582,
    6584,  6586,  6588,  6590,  6592,  6594,  6596,  6598,  6600,  6602,
    6604,  6606,  6608,  6610,  6612,  6614,  6616,  6618,  6620,  6622,
    6624,  6626,  6628,  6630,  6632,  6634,  6636,  6638,  6640,  6642,
    6644,  6646,  6648,  6650,  6652,  6654,  6656,  6658
};

/* YYRHS -- A `-1'-separated list of the rules' RHS. */
static const short yyrhs[] =
{
    1097,     0,    -1,   249,    -1,   246,    -1,   180,   730,   475,
     643,   731,    -1,   191,    -1,  1162,    -1,    26,    -1,   732,
      -1,   731,     5,   732,    -1,  1005,    -1,   479,   733,   442,
      -1,   733,   734,   733,    -1,    26,    -1,   735,    26,    -1,
    1162,    -1,   945,    -1,    18,    -1,    19,    -1,    20,    -1,
      21,    -1,    22,    -1,    18,    -1,    19,    -1,    -1,   737,
      -1,    -1,   324,   479,   738,   739,   442,    -1,   616,   479,
      26,     5,    26,   442,    -1,   740,    -1,   739,     5,   740,
      -1,   538,    -1,   579,    -1,   584,    -1,   554,    -1,   459,
      -1,   652,    -1,   576,    -1,   528,    -1,   465,    -1,   539,
      -1,   397,    -1,   580,    -1,   504,    -1,   384,    -1,   641,
      -1,   147,    -1,  1076,    -1,    -1,   742,    -1,    -1,   324,
     479,   743,   744,   442,    -1,   745,    -1,   744,     5,   745,
      -1,   740,    -1,   480,    -1,   650,    25,    -1,   252,   991,
      -1,   381,   991,    -1,   334,   991,    -1,   389,   991,    -1,
     343,   991,    -1,   309,   991,    -1,   582,   747,    -1,   934,
     396,  1162,    -1,    -1,   339,   479,   953,   442,   396,   748,
    1180,    -1,   155,   479,  1005,     5,    25,     5,    25,   442,
      -1,   456,   479,   997,   442,   396,  1162,    -1,  1300,    -1,
     242,   479,   953,   442,   396,  1162,    -1,    -1,    -1,  1162,
     637,  1005,   479,   749,   763,   442,   750,   761,    -1,    -1,
      -1,    -1,  1005,   479,   751,   763,   752,   442,   753,   761,
      -1,    -1,    -1,   522,  1509,   670,  1509,   479,   754,   763,
     755,   442,   761,    -1,    -1,    -1,  1005,   569,  1005,   479,
     756,   763,   757,   442,   761,    -1,    -1,    -1,    -1,   416,
     766,   637,   767,   507,   730,   475,   479,   758,   763,   759,
     442,   760,   762,    -1,    -1,   396,  1180,    -1,    -1,   396,
    1180,    -1,   213,    -1,    -1,   764,    -1,   765,    -1,   764,
       5,   765,    -1,   903,    -1,   531,    -1,    25,    -1,  1005,
      -1,  1005,    -1,  1005,   667,  1005,    -1,    -1,   583,   910,
     769,   772,   776,   773,    -1,    -1,   583,   770,   771,   774,
     773,    -1,   778,    -1,   771,   778,    -1,   780,    -1,   772,
     780,    -1,   411,    -1,    -1,    -1,   391,   775,  1584,    -1,
      -1,    -1,   391,   777,  1584,    -1,    -1,   626,   910,   779,
    1584,    -1,    -1,   626,   910,   781,  1584,    -1,   328,  1002,
      -1,   251,  1000,    -1,   133,  1000,    -1,   218,    -1,   235,
    1515,    -1,   542,   999,    -1,    30,   784,    31,    -1,   785,
      -1,   787,    -1,   786,    -1,   785,   786,    -1,    29,    -1,
     788,    -1,   787,   788,    -1,    28,    -1,    -1,    -1,   372,
     790,   792,   791,   793,    -1,   435,  1162,   672,   794,  1048,
    1075,   736,    -1,  1162,   672,   794,  1048,   594,   953,  1075,
     736,    -1,    -1,   796,   241,    -1,   795,    -1,   794,     5,
     795,    -1,  1005,    -1,  1005,   667,  1005,    -1,  1005,   667,
      20,    -1,   797,    -1,   796,   797,    -1,    -1,   320,   803,
     798,  1584,    -1,    -1,   323,   804,   799,  1584,    -1,    -1,
    1078,   800,  1584,    -1,    -1,   216,   801,  1584,    -1,    -1,
     214,   802,  1584,    -1,  1009,    -1,   803,     5,  1009,    -1,
    1009,    -1,   804,     5,  1009,    -1,   141,    -1,   142,    -1,
     143,    -1,   144,    -1,   145,    -1,   146,    -1,   479,   903,
     807,   442,    -1,    -1,     5,   854,   673,   857,    -1,   206,
      -1,   329,    -1,    -1,   810,    -1,   811,    -1,   810,   811,
      -1,    -1,    -1,   486,   812,   814,   813,  1269,    -1,   867,
      -1,   817,    -1,   814,     5,   817,    -1,    -1,   816,  1005,
      -1,   405,   815,   866,    25,    -1,   405,   815,   866,  1005,
      -1,   405,   815,   866,  1011,    -1,   405,   815,   866,    26,
      -1,   821,   839,    -1,    -1,   815,   405,   818,   819,    -1,
      26,    -1,    25,    -1,  1011,    -1,    19,    26,    -1,   815,
      -1,   820,    -1,   821,     5,   820,    -1,    -1,   369,    -1,
      -1,   717,    -1,   718,    -1,   719,    -1,    -1,   535,   507,
     831,   475,   825,   671,   839,    -1,    -1,    36,   823,   826,
     671,   839,    -1,    -1,   368,   822,   828,    26,   829,   352,
     507,   830,   475,   827,   671,   839,    -1,   479,    -1,   506,
      -1,   442,    -1,   474,    -1,    26,    -1,   832,     5,   832,
       5,   832,    -1,   832,     5,   832,    -1,   832,    -1,    26,
      -1,    -1,   512,   834,   814,   333,    -1,    -1,   310,   835,
     815,   667,    20,    -1,    -1,   386,   836,   815,   308,   479,
     837,   442,    -1,   838,    -1,   837,     5,   838,    -1,   815,
      -1,   841,    -1,    -1,   108,    -1,    -1,    -1,   842,   844,
     843,   840,    -1,   824,    -1,   833,    -1,   369,    -1,   370,
      -1,   369,   479,    26,   442,    -1,   370,   479,    26,   442,
      -1,   472,   479,    26,   442,    -1,   472,   479,    26,     5,
      26,   442,    -1,   371,   479,    26,   442,    -1,   371,   479,
      26,     5,    26,   442,    -1,   457,    -1,   664,   815,    -1,
     431,    -1,   557,    -1,   139,    -1,   447,    -1,   447,   479,
      26,   442,    -1,   447,   479,    26,     5,    26,   442,    -1,
     560,    -1,   560,   479,    26,   442,    -1,   560,   479,    26,
       5,    26,   442,    -1,    -1,   550,   845,   848,    -1,    -1,
     113,   846,   848,    -1,    -1,   349,   847,   848,    -1,   585,
      -1,   581,    -1,   129,    -1,   130,    -1,   622,    -1,   408,
     852,    -1,   420,   853,    -1,   849,    -1,    32,    -1,    -1,
     479,    26,   442,    -1,   604,   850,   667,   851,    -1,   815,
      -1,   815,    -1,    -1,   854,   673,   857,    -1,   862,   673,
     865,    -1,    -1,   855,   856,    -1,   629,    -1,   561,    -1,
     638,    -1,   600,    -1,   502,    -1,   518,    -1,   417,   859,
      -1,    -1,   858,   856,    -1,    -1,   479,   861,   442,    -1,
      -1,   479,    26,   442,    -1,    26,    -1,    -1,   863,   864,
     860,    -1,   629,    -1,   561,    -1,   638,    -1,   600,    -1,
     502,    -1,   518,    -1,   417,   859,    -1,   864,    -1,    -1,
      14,    -1,    -1,   286,  1005,   868,   664,   869,    -1,   871,
      -1,   874,    -1,   369,    -1,   369,   479,    26,   442,    -1,
     472,   479,    26,   442,    -1,   472,   479,    26,     5,    26,
     442,    -1,   457,    -1,   431,    -1,   557,    -1,   447,    -1,
     447,   479,    26,   442,    -1,   447,   479,    26,     5,    26,
     442,    -1,   560,    -1,   560,   479,    26,   442,    -1,   560,
     479,    26,     5,    26,   442,    -1,   550,    -1,   349,    -1,
     585,    -1,   581,    -1,   622,    -1,   408,   852,    -1,   420,
     853,    -1,   870,    -1,   604,   850,   667,   851,    -1,    -1,
     535,   507,   831,   475,   872,   671,   869,    -1,    -1,   368,
     822,   828,    26,   829,   352,   507,   830,   475,   873,   671,
     869,    -1,    -1,   512,   875,   877,   333,    -1,    -1,   310,
     876,  1005,   667,    20,    -1,   878,    -1,   877,     5,   878,
      -1,   879,   869,    -1,   880,    -1,   879,     5,   880,    -1,
    1005,    -1,    -1,   665,   995,    -1,   120,  1005,    -1,   118,
      -1,   673,   953,    -1,   673,   557,  1005,   706,   953,    -1,
     673,   557,  1005,   440,    -1,   122,  1005,    -1,   207,   928,
    1180,   889,    -1,   450,   928,   908,   881,   889,    -1,   260,
    1002,   889,    -1,    -1,    -1,   238,   886,  1187,   673,  1005,
     667,    20,   888,   736,   887,   890,    -1,    -1,   516,   996,
      -1,   736,    -1,    -1,   891,   288,    -1,   288,    -1,   892,
      -1,   891,   892,    -1,    -1,   403,   893,  1584,    -1,    -1,
     399,   894,  1584,    -1,    -1,  1078,   895,  1584,    -1,    38,
    1162,    -1,    39,  1162,    -1,    37,  1162,    -1,   546,   928,
     909,   736,    -1,   546,   928,   909,   736,   115,    -1,   264,
      -1,   264,   910,    -1,   336,    -1,   335,    -1,   263,    -1,
     415,    -1,   223,    -1,   262,    -1,   380,    -1,   379,    -1,
     293,    -1,   220,    -1,   219,    -1,   197,    -1,   253,    -1,
     181,    -1,   196,    -1,   237,    -1,   204,    -1,   913,    -1,
     912,    -1,   917,    -1,   945,    -1,   903,   904,    -1,   946,
      -1,   948,    -1,   914,    -1,    19,   903,    -1,    18,   903,
      -1,   919,    -1,   927,    -1,   921,    -1,   523,    -1,   805,
      -1,   922,    -1,   923,    -1,   924,    -1,   925,    -1,   926,
      -1,    44,   903,    -1,   928,    -1,   928,   907,    -1,   910,
      -1,   531,    -1,   906,    -1,   907,     5,   906,    -1,   910,
      -1,   908,     5,   910,    -1,   910,    -1,   909,     5,   910,
      -1,   903,    -1,    18,    -1,    19,    -1,     9,   903,    -1,
     532,    -1,   476,    -1,   479,   903,   442,    -1,   491,   479,
    1489,   442,    -1,   344,   479,  1489,   442,    -1,   911,  1011,
      -1,   911,    26,    -1,    25,    -1,  1011,    -1,    26,    -1,
     916,    -1,  1162,    -1,  1162,   469,  1162,    -1,   915,    -1,
     482,   903,    -1,   443,   903,    -1,  1272,    -1,    -1,   555,
     918,  1272,    -1,     7,   903,    -1,     6,   903,    -1,   903,
      -1,   920,     5,   903,    -1,   670,   479,  1489,   442,    -1,
     477,   479,  1489,   442,    -1,   670,   479,   928,   920,   442,
      -1,   477,   479,   928,   920,   442,    -1,   437,    -1,   299,
      -1,    10,   903,    -1,   302,   903,    -1,    10,   903,   490,
      25,    -1,   302,   903,   490,    25,    -1,   604,   903,    -1,
     422,   903,    -1,   604,   903,   490,    25,    -1,   422,   903,
     490,    25,    -1,   441,    -1,     8,   903,    -1,    18,   903,
      -1,    19,   903,    -1,    20,   903,    -1,    21,   903,    -1,
      22,   903,    -1,    11,   903,    -1,    14,   903,    -1,   505,
     903,    -1,    12,   903,    -1,    13,   903,    -1,    17,   903,
      -1,    16,   903,    -1,    15,   903,    -1,    -1,    -1,    -1,
    1005,   479,   930,   763,   931,   442,    -1,    -1,    -1,  1005,
     569,  1005,   479,   932,   763,   933,   442,    -1,    -1,    -1,
     585,   479,   935,   903,   936,   442,    -1,    -1,    -1,   561,
     479,   937,   903,   938,   442,    -1,    -1,    -1,   638,   479,
     939,   903,   940,   442,    -1,    -1,    -1,   629,   479,   941,
     903,   942,   442,    -1,   420,   479,   949,   442,   944,    -1,
     408,   479,    25,   442,   943,    -1,   408,   479,    26,   442,
     943,    -1,   408,   479,    26,   637,    26,   442,   943,    -1,
     408,   479,    26,    19,    26,   442,   943,    -1,   408,   479,
      26,    19,    26,    19,    26,   442,   943,    -1,   722,   479,
    1162,   442,    -1,   723,   479,  1162,     5,    26,   442,    -1,
      -1,  1469,   673,  1470,    -1,   853,    -1,   934,    -1,   339,
     479,   953,   442,    -1,   148,   479,   996,   442,    -1,   121,
     479,   996,   442,    -1,   456,   479,   954,   442,    -1,   242,
     479,   953,   442,    -1,   109,   479,   953,   442,    -1,   947,
      -1,   929,    -1,  1465,    -1,   585,    -1,   471,   479,   903,
     442,    -1,   374,   479,   903,   442,    -1,   536,   903,    -1,
     492,   806,    -1,   903,   159,    -1,   903,   160,    -1,   903,
     161,    -1,    25,    -1,   950,    -1,    19,   950,    -1,   952,
      -1,   951,    -1,    26,    -1,    26,    26,    -1,    26,    26,
     637,    26,    -1,    26,    26,   637,    26,   637,    26,    -1,
      26,    26,   637,    26,   637,    24,    -1,    26,   637,    26,
      -1,    26,   637,    26,   637,    26,    -1,    26,   637,    26,
     637,    24,    -1,    26,   637,    24,    -1,    24,    -1,    26,
      -1,    26,    19,    26,    -1,   996,    -1,   953,     5,   996,
      -1,   997,    -1,   954,     5,   997,    -1,    -1,    -1,    -1,
     453,   956,   999,   957,   959,  1367,   958,  1584,   290,    -1,
      -1,     8,   928,   908,    -1,    -1,    -1,   685,  1005,   961,
     809,   962,  1107,   964,   963,   969,   686,    -1,    -1,   974,
      -1,    -1,   965,    -1,   966,    -1,   965,   966,    -1,    -1,
     687,   967,  1584,    -1,    -1,   688,   968,  1584,    -1,    -1,
     970,    -1,   971,    -1,   970,   971,    -1,    -1,   689,   972,
    1584,    -1,    -1,   690,   973,  1584,    -1,   975,   979,   376,
      -1,   140,    -1,   140,   976,   594,   977,    -1,   140,   435,
     978,    -1,  1162,    -1,   976,     5,  1162,    -1,  1005,    -1,
     977,     5,  1005,    -1,  1162,    -1,   978,     5,  1162,    -1,
     980,    -1,   979,   980,    -1,    -1,   691,   981,  1584,    -1,
      -1,   692,   982,  1584,    -1,    -1,   711,   977,   983,  1584,
      -1,    -1,   529,   977,   984,  1584,    -1,    -1,   672,   977,
     985,  1584,    -1,    -1,    -1,   643,  1162,    14,   910,   673,
     910,   989,   987,  1584,   988,   291,    -1,    -1,   619,   910,
      -1,   593,   998,    -1,   602,    19,    26,    -1,   602,    -1,
     549,    18,    26,    -1,   549,    -1,    26,    -1,  1162,    -1,
     716,    -1,    25,    -1,  1010,    -1,   910,    -1,   993,     5,
     993,    -1,   994,    -1,  1005,    -1,   714,   479,  1005,   442,
      -1,  1005,   667,   714,   479,  1005,   442,    -1,  1005,   507,
     733,   475,    -1,  1005,   667,    20,    -1,  1005,   507,   733,
     475,   667,    20,    -1,  1005,   667,  1005,    -1,  1005,   507,
     733,   475,   667,  1005,    -1,   996,    -1,    25,    -1,  1006,
      -1,  1006,    -1,  1006,    -1,  1006,    -1,  1006,    -1,  1006,
      -1,    -1,   598,    26,    -1,  1583,    -1,  1007,    -1,  1583,
      -1,   401,   479,  1008,   442,    -1,  1165,    -1,    25,    -1,
    1005,    -1,  1005,   507,   733,   475,    -1,  1005,   667,    20,
      -1,  1005,   507,   733,   475,   667,    20,    -1,  1005,   667,
    1005,    -1,  1005,   507,   733,   475,   667,  1005,    -1,  1162,
      -1,    24,    -1,   667,    26,    -1,   595,  1013,    -1,  1005,
      -1,   637,  1005,    -1,   699,  1015,    -1,  1016,    -1,  1015,
       5,  1016,    -1,  1005,    -1,   710,  1015,    -1,   701,  1015,
      -1,   702,   953,    -1,   700,  1002,   706,   953,    -1,   704,
    1015,    -1,   705,   953,    -1,   703,  1002,   706,   953,    -1,
      -1,   708,  1021,   908,  1026,  1028,  1030,  1022,  1024,    -1,
      -1,  1023,    -1,   696,    -1,   697,    -1,    -1,  1025,    -1,
     396,  1162,    -1,    -1,  1027,    -1,   440,   908,    -1,    -1,
    1029,    -1,   707,    26,    -1,    -1,  1031,    -1,   698,    26,
    1032,    -1,    -1,   449,    26,    -1,    -1,    -1,   669,   910,
     623,  1034,  1584,  1035,  1036,   489,    -1,    -1,    -1,   590,
    1037,  1584,    -1,    -1,    -1,   112,  1038,   910,   623,  1039,
    1584,  1036,    -1,   157,  1005,   479,    26,   442,    -1,   103,
    1005,    -1,   125,  1005,    -1,    -1,   340,  1191,  1043,   673,
     531,    -1,   340,  1191,   604,  1044,    -1,  1045,    -1,  1044,
       5,  1045,    -1,  1046,   667,  1461,    -1,  1046,   667,    20,
      -1,  1457,    -1,    -1,  1049,   376,    -1,   376,    -1,    -1,
     201,    -1,  1050,    -1,  1049,  1050,    -1,    -1,   320,  1064,
    1051,  1584,    -1,    -1,   323,  1065,  1052,  1584,    -1,    -1,
     403,  1053,  1584,    -1,    -1,   399,  1054,  1584,    -1,    -1,
    1078,  1055,  1584,    -1,    -1,   355,  1056,  1584,    -1,    -1,
     325,  1057,  1584,    -1,    -1,    45,  1058,  1584,    -1,    -1,
      42,  1059,  1584,    -1,    -1,    41,  1060,  1584,    -1,    -1,
      40,  1061,  1584,    -1,    -1,    48,  1062,  1584,    -1,    -1,
      47,  1063,  1584,    -1,   996,    -1,  1064,     5,   996,    -1,
     996,    -1,  1065,     5,   996,    -1,   364,  1068,    -1,   365,
    1005,   706,  1068,    -1,   609,    -1,   426,    -1,   996,    -1,
      -1,   712,  1071,  1070,  1047,    -1,   435,  1180,  1048,  1004,
     736,    -1,  1180,  1048,   594,   953,  1004,   736,    -1,    -1,
     535,  1187,  1048,   594,  1005,   667,    20,  1004,  1072,   736,
      -1,   517,   953,  1074,    -1,   131,    26,    -1,   132,    26,
      -1,   674,    -1,   587,    -1,   131,  1162,    -1,   132,  1162,
      -1,    -1,   598,    26,    -1,  1077,    -1,    54,    25,    -1,
     544,    14,    26,    -1,   544,    14,  1162,    -1,    55,    14,
      26,    -1,    55,    14,  1162,    -1,    51,    -1,    53,    -1,
      50,    -1,    52,    -1,    -1,   478,  1079,  1084,    -1,   345,
      -1,    -1,   644,  1081,  1084,    -1,   353,  1086,    -1,   644,
    1084,    -1,  1086,    -1,   479,  1085,   442,    -1,  1086,    -1,
    1085,     5,  1086,    -1,  1087,    -1,   642,    -1,   362,    -1,
     382,    -1,   354,    -1,   533,    -1,   490,    -1,   674,    -1,
     598,    -1,   587,    -1,   227,    -1,   487,    -1,   498,    -1,
     588,    -1,   603,    -1,   568,    -1,   360,    -1,   361,    -1,
      25,    -1,   558,    -1,    -1,    -1,   646,  1090,  1185,  1091,
      14,   928,  1092,    -1,   531,    -1,   909,    -1,   269,  1162,
      -1,   259,  1162,    -1,   272,  1162,    -1,   499,  1183,   385,
      -1,   499,  1183,   436,   992,    -1,    -1,  1099,  1098,  1102,
      -1,    -1,  1100,    -1,  1101,    -1,  1100,  1101,    -1,  1041,
      -1,  1106,    -1,  1568,    -1,  1122,    -1,  1108,    -1,  1121,
      -1,    -1,  1103,    -1,  1105,    -1,  1103,  1105,    -1,   116,
    1005,    -1,  1110,    -1,  1116,    -1,  1128,    -1,  1282,    -1,
    1292,    -1,  1132,    -1,   960,    -1,   783,    -1,  1040,    -1,
    1568,    -1,   783,    -1,    -1,   783,    -1,   810,    -1,   418,
      -1,   110,    -1,    -1,    -1,    -1,    -1,  1109,  1111,  1005,
     479,  1112,  1178,   442,  1113,   809,  1114,  1107,  1584,  1115,
      -1,   261,    -1,    -1,    -1,   605,  1117,   809,  1118,  1584,
     412,    -1,   227,   905,    -1,   928,    -1,   928,   908,    -1,
     407,  1473,    -1,   515,  1473,    -1,  1123,    -1,  1124,    -1,
    1123,  1124,    -1,  1125,    -1,    -1,   455,  1126,  1127,    -1,
     809,   292,    -1,   992,    -1,  1106,    -1,  1121,    -1,    -1,
      -1,    -1,   164,  1005,   163,  1005,   479,  1129,  1178,   442,
    1130,   809,  1131,  1107,  1584,  1115,    -1,    -1,    -1,   693,
    1005,  1133,   809,  1134,  1135,   694,    -1,  1136,    -1,  1135,
    1136,    -1,    -1,   695,  1137,  1584,    -1,    -1,   672,  1005,
    1138,  1584,    -1,    -1,   606,  1140,  1155,  1146,  1141,    -1,
     413,    -1,    -1,   284,  1143,  1584,    -1,    -1,    23,  1147,
    1148,  1149,  1004,  1144,  1584,    -1,    -1,    23,  1147,  1004,
    1145,  1584,    -1,  1142,    -1,  1146,  1142,    -1,    -1,  1080,
      -1,    25,    -1,  1162,    -1,    -1,  1162,    -1,    25,    -1,
     301,  1153,    -1,   313,  1154,    -1,   296,  1154,    -1,   633,
      -1,    25,    -1,  1162,    -1,  1153,    -1,  1154,     5,  1153,
      -1,  1162,    -1,    25,    -1,  1159,  1157,    -1,    -1,   737,
    1160,    -1,  1161,    -1,  1158,    -1,  1027,    -1,  1029,    -1,
    1031,    -1,  1023,    -1,  1025,    -1,   421,   928,   908,    -1,
      -1,   115,    -1,   115,    -1,  1163,    -1,  1165,    -1,   240,
    1165,    -1,  1165,   667,    -1,  1164,  1169,    -1,  1164,  1005,
     507,  1172,   475,    -1,  1164,  1005,   507,  1172,   475,   507,
    1172,   475,    -1,  1170,    -1,  1005,    -1,  1166,    -1,  1005,
     506,  1168,   474,    -1,  1005,   506,  1168,   474,    -1,  1162,
      -1,    25,    -1,    20,    -1,  1005,    -1,  1005,  1171,    -1,
     507,  1172,   475,    -1,   507,  1172,   475,   507,  1172,   475,
      -1,  1173,    -1,  1172,     5,  1173,    -1,   733,    -1,  1175,
      -1,  1177,    -1,  1175,   667,  1176,    -1,  1175,   667,  1005,
     507,  1172,   475,    -1,  1175,   667,  1005,   507,  1172,   475,
     507,  1172,   475,    -1,  1005,    -1,  1167,    -1,    20,    -1,
    1005,    -1,  1005,  1171,    -1,    -1,  1179,    -1,  1181,    -1,
    1179,     5,  1181,    -1,  1182,    -1,  1180,     5,  1182,    -1,
    1005,    -1,  1005,   667,  1005,    -1,  1162,    -1,  1162,   469,
    1162,    -1,    25,    -1,  1011,    -1,    26,    -1,  1184,    -1,
    1183,     5,  1184,    -1,  1162,    -1,  1162,   469,  1162,    -1,
    1186,    -1,  1185,     5,  1186,    -1,  1174,    -1,  1162,    -1,
    1189,    -1,  1188,     5,  1189,    -1,  1162,  1190,    -1,    -1,
     635,    -1,   586,    -1,  1192,    -1,  1191,     5,  1192,    -1,
    1162,    -1,  1162,   469,  1162,    -1,   304,  1001,   665,   994,
     627,  1576,   741,    -1,    -1,   665,   479,   910,     5,   910,
     442,  1195,    -1,    -1,   616,   479,   910,     5,   910,   442,
      -1,   305,  1005,  1194,    -1,  1005,    -1,   390,  1003,  1199,
      -1,  1200,    -1,   594,   910,    -1,  1201,  1202,  1207,     8,
    1197,    -1,    -1,   665,  1203,   479,   910,     5,   910,   442,
      -1,    -1,   604,  1006,    -1,    -1,   402,    -1,   267,  1515,
     316,  1557,  1206,    -1,   611,   998,    -1,   611,   998,     8,
     928,   908,    -1,    -1,   664,   624,  1509,   425,  1509,    -1,
     664,   624,  1509,     5,   425,  1509,    -1,   664,  1509,     5,
    1509,    -1,    -1,   696,    -1,   697,    -1,   444,   673,  1557,
    1209,  1210,    -1,    -1,   664,  1557,    -1,    -1,   664,   624,
    1509,     8,  1509,    -1,   624,  1509,     8,  1509,    -1,   460,
    1212,    -1,  1213,    -1,  1212,     5,  1213,    -1,   252,   991,
      -1,   334,   991,    -1,   381,   991,    -1,   389,   991,    -1,
     343,   991,    -1,   309,   991,    -1,  1082,    -1,   487,  1083,
      -1,   498,  1083,    -1,   609,  1083,    -1,   426,  1083,    -1,
     598,  1083,    -1,   596,   992,    -1,   597,   992,    -1,    59,
      -1,    60,    -1,    61,    -1,    62,    -1,   450,   737,    -1,
     712,   737,    -1,   341,    -1,   245,    -1,   202,    -1,   182,
      -1,   199,    -1,   190,    -1,  1514,   462,  1217,   594,  1215,
      -1,  1162,    -1,    25,    -1,   452,  1217,    -1,   452,  1217,
       8,  1180,    -1,   452,  1217,   601,  1183,    -1,   452,  1217,
     601,  1183,     8,  1180,    -1,    49,  1215,    -1,  1006,    -1,
      -1,   510,  1227,   736,   643,  1222,  1162,  1220,  1004,   736,
    1219,  1223,    -1,    -1,   715,    26,    -1,   510,  1227,   736,
     396,  1162,    -1,    -1,   369,    -1,    -1,  1224,   332,    -1,
    1225,    -1,  1224,  1225,    -1,    -1,  1078,  1226,  1584,    -1,
     909,    -1,    -1,   651,   998,  1229,  1230,    -1,    -1,   594,
    1231,    -1,  1232,    -1,  1231,     5,  1232,    -1,  1501,    -1,
     531,    -1,   270,  1236,   138,  1234,    -1,   270,  1236,   673,
    1235,  1234,    -1,   270,  1236,   137,  1235,  1234,    -1,   270,
    1236,  1234,    -1,    -1,    43,    -1,    25,    -1,  1010,    -1,
    1005,    -1,    -1,   527,    -1,   198,  1236,  1237,   479,   928,
    1120,   442,    -1,   243,  1236,    -1,   117,  1236,    -1,  1273,
    1281,    -1,   495,   111,    -1,   495,  1243,    -1,  1244,    -1,
    1243,  1244,    -1,    -1,   186,  1245,  1584,    -1,    -1,   248,
    1246,  1584,    -1,    -1,   278,  1247,  1584,    -1,    -1,   266,
    1248,  1584,    -1,    -1,   303,  1249,  1584,    -1,    -1,   250,
    1162,  1250,  1584,    -1,    -1,   274,  1162,  1251,  1584,    -1,
    1262,    -1,  1265,    -1,  1264,    -1,  1253,    -1,  1290,    -1,
    1256,    -1,    -1,   608,   910,  1254,   530,    -1,    -1,   530,
      -1,    -1,   617,    26,  1257,  1255,    -1,   209,    -1,   676,
    1277,    -1,   212,  1277,    -1,   211,  1277,    -1,    -1,  1259,
      -1,  1260,    -1,  1259,  1260,    -1,  1270,  1261,    -1,    -1,
     665,  1277,    -1,    -1,   567,  1263,  1258,  1269,    -1,   566,
    1509,  1269,    -1,   565,  1268,  1267,  1266,  1269,    -1,    -1,
     203,   903,    -1,   203,   903,     5,   903,    -1,   660,    -1,
     661,    -1,   662,    -1,   663,    -1,  1162,    -1,    -1,   570,
      -1,  1271,    -1,  1270,     5,  1271,    -1,   910,  1304,    -1,
     656,   479,   903,   442,  1289,    -1,   114,  1289,    -1,   544,
     479,    20,   442,  1289,    -1,   461,   479,    20,   442,  1289,
      -1,   438,   479,   903,   442,  1289,    -1,   636,   479,   903,
     442,  1289,    -1,   649,   479,   903,   442,  1289,    -1,   648,
     479,   903,   442,  1289,    -1,    -1,   509,  1274,    -1,  1275,
      -1,  1274,  1275,    -1,   277,    26,    -1,   268,    26,    -1,
     351,    26,    -1,   234,    26,    -1,   306,    26,    -1,   225,
      -1,   395,    25,    -1,   395,  1162,    -1,   226,    25,    -1,
     210,    25,    -1,  1280,    -1,  1276,  1280,    -1,  1278,   159,
      -1,  1278,   161,    -1,  1278,   160,    -1,  1278,    -1,  1011,
      -1,    26,    -1,    -1,   509,  1276,    -1,   277,  1277,    -1,
     268,  1277,    -1,   351,  1277,    -1,   234,  1277,    -1,   306,
    1277,    -1,   307,  1277,    -1,   675,    25,    -1,   676,  1277,
      -1,   680,    -1,   677,    -1,   678,    -1,   679,    -1,   684,
      -1,   681,    -1,   682,    -1,   683,    -1,   126,  1277,    -1,
     127,  1277,    -1,   128,  1277,    -1,   395,    25,    -1,   226,
      25,    -1,   449,    -1,   123,    -1,   124,    -1,    -1,   562,
     666,  1188,    -1,   187,  1188,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   513,  1283,  1005,   479,  1284,  1178,   442,  1285,
     809,  1286,  1241,  1287,  1242,  1288,   289,    -1,    -1,   574,
     903,    -1,   564,  1291,    -1,    -1,  1215,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   156,  1293,  1005,   479,  1294,  1178,
     442,  1295,   809,  1296,  1299,  1297,  1242,  1298,   289,    -1,
    1279,  1281,    -1,    -1,    -1,    -1,   205,   479,    25,     5,
    1301,   763,  1302,   442,  1303,   761,    -1,    -1,   434,    -1,
     434,   268,    26,    -1,   434,   268,  1162,    -1,   654,   910,
      -1,   654,   910,   396,  1162,    -1,   654,   910,   213,    -1,
     654,   910,   625,    -1,   654,   910,   592,    -1,  1307,    -1,
     222,  1457,    -1,   375,  1457,    -1,   331,  1458,    -1,    46,
    1005,    -1,  1321,    -1,  1309,    -1,    -1,    -1,   255,  1310,
    1457,   479,  1311,  1325,   442,  1314,    -1,    -1,    -1,   184,
    1312,  1457,   479,  1313,  1325,   442,  1314,  1322,    -1,    -1,
    1315,    -1,  1316,    -1,  1315,  1316,    -1,   670,  1317,    -1,
     294,    26,    -1,    58,    26,    -1,   135,    -1,   136,    -1,
    1583,    -1,    -1,  1319,    -1,  1320,    -1,  1319,  1320,    -1,
     670,  1317,    -1,   724,    26,    -1,   154,  1458,   672,  1457,
     479,  1323,   442,  1318,    -1,   101,  1006,    -1,   102,  1006,
      -1,   221,  1457,   643,  1457,    -1,   106,  1457,    -1,    -1,
     318,    -1,  1324,    -1,  1323,     5,  1324,    -1,  1005,   635,
      -1,  1005,   586,    -1,  1005,    -1,  1326,    -1,  1325,     5,
    1326,    -1,  1409,    -1,  1407,    -1,   171,  1005,    -1,   229,
      -1,    56,  1005,  1329,    -1,    57,  1458,   151,    -1,    57,
    1458,   152,    -1,  1330,    -1,  1329,     5,  1330,    -1,  1331,
      -1,  1334,    -1,  1337,    -1,  1342,    -1,  1345,    -1,  1341,
      -1,  1340,    -1,   632,  1332,    -1,   632,   479,  1333,   442,
      -1,  1326,    -1,  1326,   711,  1005,    -1,  1332,    -1,  1333,
       5,  1332,    -1,   589,  1336,    -1,   589,   479,  1335,   442,
      -1,  1336,    -1,  1335,     5,  1336,    -1,  1005,    -1,   503,
    1339,    -1,   503,   479,  1338,   442,    -1,  1339,    -1,  1338,
       5,  1339,    -1,  1326,    -1,   135,    -1,   136,    -1,   134,
      26,    -1,   104,  1407,  1344,    -1,   104,   479,  1343,   442,
      -1,  1407,  1344,    -1,  1343,     5,  1407,  1344,    -1,    -1,
     107,  1005,    -1,   105,  1346,    -1,   105,   479,  1346,   442,
      -1,  1347,    -1,  1346,     5,  1347,    -1,  1005,    -1,   315,
      -1,   281,    -1,   215,  1350,    -1,   194,    -1,   183,    -1,
     170,    -1,   168,    -1,   172,    -1,   228,  1515,    -1,   280,
    1349,   508,  1509,   673,  1509,    -1,   348,   998,   508,  1509,
     673,  1509,    -1,    -1,  1515,    -1,    -1,   910,    -1,   571,
     910,    -1,   279,    -1,    -1,   298,  1354,  1457,  1357,  1355,
      -1,    -1,   527,  1356,   479,  1359,   442,    -1,  1495,    -1,
      -1,   479,  1358,   442,    -1,  1461,    -1,  1358,     5,  1461,
      -1,  1360,    -1,  1359,     5,  1360,    -1,  1501,    -1,   531,
      -1,    -1,   548,  1362,  1364,  1365,    -1,  1006,    -1,  1369,
     999,    -1,   999,    -1,    -1,    -1,   601,  1366,  1183,    -1,
      -1,    -1,   601,  1368,  1183,    -1,   549,    -1,   602,    -1,
     609,    -1,   426,    -1,   393,    -1,   445,    -1,   429,   910,
      -1,   402,   910,    -1,   287,  1457,   200,   999,    -1,   287,
    1457,  1430,    -1,   562,   666,  1373,    -1,  1374,    -1,  1373,
       5,  1374,    -1,  1375,  1376,    -1,    26,    -1,  1461,    -1,
      -1,   635,    -1,   586,    -1,   326,    -1,   359,    -1,    -1,
     378,    -1,   407,  1381,  1379,    -1,  1557,    -1,  1557,   659,
    1005,    -1,    25,    -1,    -1,  1514,  1383,  1384,    -1,  1415,
      -1,  1419,    -1,  1378,    -1,  1516,    -1,  1377,    -1,  1370,
      -1,  1371,    -1,  1361,    -1,  1353,    -1,  1352,    -1,  1485,
      -1,  1537,    -1,   553,  1388,   672,  1457,   673,  1393,  1387,
      -1,   514,  1388,   672,  1457,   594,  1393,    -1,   553,  1386,
     673,  1393,    -1,   514,  1386,   594,  1393,    -1,   444,    -1,
     430,    -1,   639,    -1,    -1,   193,    -1,   664,  1005,    -1,
     217,    -1,   633,    -1,  1389,    -1,  1390,    -1,  1389,     5,
    1390,    -1,   519,  1391,    -1,   498,    -1,   487,    -1,   526,
    1391,    -1,   534,    -1,   556,    -1,    -1,   479,  1392,   442,
      -1,  1461,    -1,  1392,     5,  1461,    -1,  1394,    -1,  1393,
       5,  1394,    -1,   511,    -1,  1459,    -1,   285,  1457,  1396,
     664,  1495,  1398,    -1,    -1,   479,  1397,   442,    -1,  1461,
      -1,  1397,     5,  1461,    -1,    -1,   192,    -1,   540,   479,
    1433,   442,    -1,   295,   479,  1402,   442,  1401,    -1,   346,
    1403,    -1,  1404,    -1,  1457,    -1,  1457,   479,  1404,   442,
      -1,  1461,    -1,  1404,     5,  1461,    -1,   524,   479,  1406,
     442,    -1,   410,   479,  1406,   442,    -1,   308,   479,  1406,
     442,    -1,  1461,    -1,  1406,     5,  1461,    -1,  1405,    -1,
    1400,    -1,  1399,    -1,   449,  1464,    -1,   258,    -1,   257,
      -1,   256,    -1,  1005,  1449,  1410,  1411,    -1,    -1,  1408,
      -1,    -1,  1412,    -1,  1413,    -1,  1412,  1413,    -1,  1414,
    1344,    -1,   424,    -1,   208,    -1,   524,    -1,   410,    -1,
    1401,    -1,   540,   479,  1433,   442,    -1,   308,    -1,   169,
    1416,  1418,    -1,  1417,    -1,  1459,    -1,  1419,    -1,  1418,
    1419,    -1,  1395,    -1,  1385,    -1,   496,  1433,    -1,   419,
    1422,    -1,  1500,    -1,  1422,     5,  1500,    -1,   574,  1433,
      -1,   594,  1425,    -1,  1426,    -1,  1425,     5,  1426,    -1,
    1427,    -1,   563,  1427,    -1,   563,   479,  1428,   442,    -1,
    1457,    -1,  1457,  1463,    -1,  1426,    -1,  1428,     5,  1426,
      -1,  1424,  1430,  1431,  1432,    -1,    -1,  1423,    -1,    -1,
    1421,    -1,    -1,  1420,    -1,  1434,    -1,  1433,     6,  1434,
      -1,  1435,    -1,  1434,     7,  1435,    -1,  1436,    -1,     9,
    1436,    -1,  1447,    -1,   479,  1433,   442,    -1,   491,  1496,
      -1,   344,  1496,    -1,    -1,   490,  1440,    -1,  1502,    -1,
    1505,    -1,  1501,   670,   479,  1442,   442,    -1,  1501,   670,
    1496,    -1,  1501,   477,   479,  1442,   442,    -1,  1501,   477,
    1496,    -1,  1443,    -1,  1442,     5,  1443,    -1,  1563,    -1,
    1464,    -1,    -1,     9,    -1,  1501,  1444,   437,    -1,  1501,
    1444,   299,    -1,  1501,  1446,  1501,    -1,  1501,  1444,   439,
    1501,     7,  1501,    -1,  1501,   604,  1439,  1438,    -1,  1501,
     422,  1439,  1438,    -1,  1501,   721,  1439,  1438,    -1,  1501,
     423,  1439,  1438,    -1,  1501,  1444,    10,  1439,  1438,    -1,
      14,    -1,    17,    -1,    12,    -1,    13,    -1,   302,    -1,
      10,    -1,   720,    -1,    16,    -1,    15,    -1,  1445,    -1,
    1441,    -1,  1437,    -1,    -1,   633,    -1,   410,    -1,   524,
      -1,  1450,    -1,  1451,    -1,  1453,    -1,   369,    -1,   369,
     479,  1454,   442,    -1,    -1,   520,    -1,   520,   479,    26,
     442,    -1,   447,    -1,   447,   479,  1455,  1452,   442,    -1,
     560,   479,  1455,  1452,   442,    -1,   560,    -1,   585,    -1,
     457,    -1,   431,    -1,   370,    -1,   370,   479,  1454,   442,
      -1,   371,    -1,   371,   479,    26,   442,    -1,   371,   479,
      26,     5,    26,   442,    -1,   408,  1471,   673,  1472,    -1,
     408,    -1,   420,  1471,   673,  1472,    -1,   420,    -1,   420,
    1471,   479,    26,   442,   673,  1472,    -1,   622,    -1,   581,
      -1,   472,    -1,   472,   479,    26,   442,    -1,   472,   479,
      26,     5,    26,   442,    -1,    -1,     5,  1456,    -1,   550,
     479,  1455,   442,    -1,   613,    -1,   349,    -1,   550,    -1,
     113,    -1,    26,    -1,    26,    -1,    26,    -1,    25,   667,
    1005,    -1,    25,    -1,  1005,    -1,  1005,   637,  1005,    -1,
    1005,   637,    25,   667,  1005,    -1,  1005,   659,  1005,    -1,
    1005,   659,  1005,   637,  1005,    -1,  1005,   659,  1005,   637,
      25,   667,  1005,    -1,    25,   667,  1005,    -1,    25,    -1,
    1005,    -1,  1005,   637,  1005,    -1,  1005,   637,    25,   667,
    1005,    -1,  1005,   659,  1005,    -1,  1005,   659,  1005,   637,
    1005,    -1,  1005,   659,  1005,   637,    25,   667,  1005,    -1,
    1005,    -1,    -1,   507,    26,   475,    -1,   507,    26,     5,
      26,   475,    -1,  1462,    -1,   659,  1462,    -1,  1005,  1460,
      -1,  1457,   667,  1005,  1460,    -1,  1457,   667,    20,    -1,
    1005,    -1,    25,    -1,  1011,    -1,    26,    -1,  1466,    -1,
     445,  1468,    -1,   445,  1467,    -1,    -1,  1471,   673,  1472,
      -1,    -1,  1469,   673,  1469,    -1,   629,    -1,   561,    -1,
     638,    -1,   600,    -1,   502,    -1,   518,    -1,   417,    -1,
     417,   479,    26,   442,    -1,   629,    -1,   561,    -1,   638,
      -1,   600,    -1,   502,    -1,   518,    -1,   417,    -1,   417,
     479,    26,   442,    -1,   629,    -1,   561,    -1,   638,    -1,
     600,    -1,   502,    -1,   518,    -1,   417,    -1,   629,    -1,
     561,    -1,   638,    -1,   600,    -1,   502,    -1,   518,    -1,
     417,    -1,   417,   479,    26,   442,    -1,  1005,    -1,  1005,
     659,  1005,    -1,    25,    -1,  1514,   551,   999,    -1,    -1,
    1514,   448,  1363,   485,   643,  1483,  1476,    -1,    -1,  1514,
     448,  1363,   485,   149,   643,  1484,  1477,    -1,    -1,  1514,
     448,  1363,   188,  1484,  1478,    -1,    -1,  1514,   448,  1363,
     189,   149,   643,  1484,  1479,    -1,    -1,   338,    -1,   337,
    1481,    -1,  1482,    -1,  1481,     5,  1482,    -1,  1005,    -1,
    1005,   667,  1005,    -1,    25,   667,  1005,   667,  1005,    -1,
    1484,    -1,  1353,    -1,  1217,    -1,  1486,    -1,  1486,    -1,
      -1,    -1,   519,  1497,  1487,  1498,  1488,  1494,  1429,  1492,
    1480,    -1,   519,  1497,  1498,  1429,  1492,    -1,  1491,    -1,
    1509,    -1,   519,  1497,  1498,  1494,  1429,  1492,    -1,    -1,
     573,  1448,  1490,    -1,  1372,    -1,   383,  1493,  1322,    -1,
    1372,   383,  1493,  1322,    -1,  1005,    -1,    -1,   601,  1183,
      -1,   519,  1497,  1498,  1429,    -1,   479,   519,  1497,  1498,
    1429,   442,    -1,    -1,   633,    -1,   410,    -1,   524,    -1,
    1499,    -1,  1498,     5,  1499,    -1,  1501,    -1,  1501,  1005,
      -1,  1501,   664,  1005,    -1,  1501,    -1,  1502,    -1,    19,
    1502,    -1,    18,  1502,    -1,  1503,    -1,  1563,    -1,  1496,
      -1,   633,  1496,    -1,   634,  1496,    -1,   618,  1496,    -1,
     659,  1005,    -1,   659,  1005,   667,  1005,    -1,  1502,    21,
    1501,    -1,  1502,  1523,    -1,  1502,    20,  1501,    -1,  1502,
      18,  1501,    -1,  1502,    19,  1501,    -1,  1464,    -1,   532,
      -1,   476,    -1,   624,    -1,    20,    -1,   114,    -1,   636,
     479,  1448,  1501,   442,    -1,   648,   479,  1448,  1501,   442,
      -1,   649,   479,  1448,  1501,   442,    -1,   656,   479,  1448,
    1501,   442,    -1,   544,   479,  1448,  1501,   442,    -1,  1005,
     479,  1504,   442,    -1,   585,   479,  1504,   442,    -1,   479,
    1501,   442,    -1,   492,   479,  1524,   442,    -1,  1525,    -1,
    1527,    -1,  1501,    -1,  1504,     5,  1501,    -1,  1464,    -1,
    1514,   398,  1513,  1508,  1490,    -1,  1514,   387,  1513,  1508,
     298,  1457,  1510,    -1,  1514,   387,  1513,  1508,  1162,    -1,
      -1,   373,  1509,    -1,    25,    -1,  1162,    -1,    -1,   479,
    1511,   442,    -1,  1512,    -1,  1511,     5,  1512,    -1,  1005,
      -1,    25,    -1,  1162,    -1,    -1,   317,  1515,   643,    -1,
    1006,    -1,  1521,    -1,  1520,    -1,  1517,    -1,   366,  1518,
     673,  1518,    -1,   347,  1457,   667,  1519,   673,  1519,    -1,
    1005,    -1,  1005,    -1,   271,  1457,    -1,   342,  1457,  1522,
      -1,   321,    -1,   224,    -1,   141,    -1,   142,    -1,   143,
      -1,   144,    -1,   145,    -1,   146,    -1,   445,     5,  1471,
     673,  1472,    -1,  1563,     5,  1471,   673,  1472,    -1,   445,
    1471,   673,  1472,    -1,  1501,     5,  1471,   673,  1472,    -1,
    1526,    -1,  1526,  1471,   673,  1472,    -1,   408,   479,    25,
     442,    -1,   408,   479,    26,   442,    -1,   408,   479,    26,
      19,    26,   442,    -1,   408,   479,    26,   637,    26,   442,
      -1,   408,   479,    26,    19,    26,    19,    26,   442,    -1,
     408,   479,    26,   637,    26,   637,    26,   442,    -1,   408,
     479,    26,    19,    26,    19,    26,    26,   637,    26,   637,
      26,   442,    -1,   408,   479,    26,    19,    26,    19,    26,
      26,   637,    26,   442,    -1,  1528,    -1,  1528,  1471,   479,
      26,   442,   673,  1472,    -1,  1528,  1471,   673,  1472,    -1,
     420,   479,    25,   442,    -1,   420,   479,    26,   442,    -1,
     420,   479,    26,    19,    26,   442,    -1,   420,   479,    26,
     637,    26,   442,    -1,   420,   479,    26,    19,    26,    19,
      26,   442,    -1,   420,   479,    26,   637,    26,   637,    26,
     442,    -1,    -1,   655,  1530,  1531,   239,    -1,  1532,    -1,
    1531,  1532,    -1,    33,    -1,  1533,    -1,  1535,    -1,   402,
      -1,   354,    -1,   273,    -1,   632,    -1,   529,    -1,   633,
      -1,   534,    -1,   578,    -1,   634,    -1,   165,    -1,   535,
      -1,   664,    -1,   635,    -1,   367,    -1,   536,    -1,   368,
      -1,   665,    -1,   659,    -1,   324,    -1,   537,    -1,   233,
      -1,   438,    -1,   636,    -1,   711,    -1,   439,    -1,   538,
      -1,   539,    -1,   579,    -1,   580,    -1,   480,    -1,   481,
      -1,   404,    -1,   698,    -1,   666,    -1,   581,    -1,   440,
      -1,   583,    -1,   577,    -1,   369,    -1,   540,    -1,   541,
      -1,   441,    -1,   542,    -1,   442,    -1,   475,    -1,   543,
      -1,   637,    -1,   482,    -1,   443,    -1,     5,    -1,    23,
      -1,   483,    -1,   444,    -1,   406,    -1,   405,    -1,   372,
      -1,   544,    -1,   484,    -1,   445,    -1,   485,    -1,   584,
      -1,   407,    -1,   585,    -1,   408,    -1,   638,    -1,   639,
      -1,   446,    -1,   640,    -1,   447,    -1,   448,    -1,   449,
      -1,   409,    -1,   545,    -1,   486,    -1,   487,    -1,   373,
      -1,   586,    -1,   330,    -1,   641,    -1,   702,    -1,   450,
      -1,   410,    -1,    21,    -1,   667,    -1,   488,    -1,   374,
      -1,   589,    -1,   112,    -1,   590,    -1,   705,    -1,   451,
      -1,    14,    -1,   546,    -1,   490,    -1,   547,    -1,   378,
      -1,   591,    -1,   452,    -1,   491,    -1,   592,    -1,   492,
      -1,   493,    -1,   416,    -1,   582,    -1,   548,    -1,   148,
      -1,   242,    -1,   494,    -1,   549,    -1,   642,    -1,   550,
      -1,   551,    -1,   643,    -1,   453,    -1,   454,    -1,   495,
      -1,   685,    -1,   140,    -1,   155,    -1,   552,    -1,   417,
      -1,   593,    -1,   594,    -1,   418,    -1,   339,    -1,   455,
      -1,   668,    -1,   595,    -1,   553,    -1,    13,    -1,   554,
      -1,   555,    -1,   496,    -1,   497,    -1,   598,    -1,   599,
      -1,   600,    -1,   707,    -1,   121,    -1,   669,    -1,   670,
      -1,   161,    -1,   556,    -1,   456,    -1,   340,    -1,   712,
      -1,   498,    -1,   457,    -1,   382,    -1,   420,    -1,   714,
      -1,   384,    -1,   644,    -1,   587,    -1,   706,    -1,   557,
      -1,   530,    -1,   421,    -1,   645,    -1,   674,    -1,   458,
      -1,     7,    -1,   476,    -1,   630,    -1,   531,    -1,     6,
      -1,   532,    -1,     8,    -1,   602,    -1,   603,    -1,    12,
      -1,   646,    -1,   604,    -1,   559,    -1,   499,    -1,   647,
      -1,   459,    -1,   605,    -1,   500,    -1,    10,    -1,    55,
      -1,   501,    -1,   606,    -1,   693,    -1,   708,    -1,    19,
      -1,   502,    -1,   160,    -1,    22,    -1,   607,    -1,   503,
      -1,   560,    -1,   561,    -1,    20,    -1,   608,    -1,   609,
      -1,   360,    -1,   610,    -1,   504,    -1,     9,    -1,   671,
      -1,   716,    -1,   672,    -1,   611,    -1,   479,    -1,   507,
      -1,   508,    -1,   460,    -1,   562,    -1,   391,    -1,   563,
      -1,   509,    -1,   650,    -1,   425,    -1,   564,    -1,   205,
      -1,   156,    -1,   461,    -1,    18,    -1,   159,    -1,   392,
      -1,   462,    -1,   162,    -1,   426,    -1,   361,    -1,   567,
      -1,   393,    -1,   394,    -1,   463,    -1,   510,    -1,   511,
      -1,   651,    -1,   612,    -1,   427,    -1,   613,    -1,   512,
      -1,   464,    -1,   652,    -1,   346,    -1,   428,    -1,   429,
      -1,   513,    -1,   430,    -1,   227,    -1,   396,    -1,   465,
      -1,   514,    -1,   568,    -1,   311,    -1,   653,    -1,   614,
      -1,   654,    -1,   515,    -1,   517,    -1,   518,    -1,   466,
      -1,   519,    -1,   570,    -1,   520,    -1,   467,    -1,   522,
      -1,   615,    -1,   533,    -1,   616,    -1,   617,    -1,   571,
      -1,   349,    -1,   431,    -1,   618,    -1,   523,    -1,   655,
      -1,   350,    -1,   139,    -1,   619,    -1,   620,    -1,   656,
      -1,   468,    -1,   588,    -1,   621,    -1,   166,    -1,   622,
      -1,   623,    -1,   469,    -1,   715,    -1,   673,    -1,   657,
      -1,   470,    -1,   572,    -1,   247,    -1,   397,    -1,   573,
      -1,   524,    -1,   525,    -1,   526,    -1,   471,    -1,   658,
      -1,   624,    -1,   432,    -1,   527,    -1,   472,    -1,   401,
      -1,   625,    -1,   473,    -1,   626,    -1,   574,    -1,   575,
      -1,   576,    -1,   627,    -1,   434,    -1,   628,    -1,   648,
      -1,   649,    -1,   631,    -1,   629,    -1,   528,    -1,    -1,
     240,  1534,  1563,    -1,    -1,   601,  1536,  1183,    -1,    -1,
      -1,   526,  1457,  1538,  1541,  1539,  1540,    -1,    -1,   200,
     999,    -1,   574,  1433,    -1,    99,  1545,   442,    14,   479,
    1546,   442,    -1,    95,  1546,   442,    -1,    96,  1546,   442,
      -1,   631,  1542,    -1,    98,  1546,    -1,    97,  1546,    -1,
    1544,    -1,  1542,     5,  1544,    -1,  1461,    -1,  1543,    14,
    1547,    -1,  1543,    -1,  1545,     5,  1543,    -1,  1547,    -1,
    1546,     5,  1547,    -1,   531,    -1,  1548,    -1,  1549,    -1,
      19,  1549,    -1,    18,  1549,    -1,  1551,    -1,  1496,    -1,
     659,  1005,    -1,   659,  1005,   667,  1005,    -1,   659,  1005,
     507,    26,   475,    -1,   659,  1005,   667,  1005,   507,    26,
     475,    -1,   659,  1005,   507,    26,     5,    26,   475,    -1,
     659,  1005,   667,  1005,   507,    26,     5,    26,   475,    -1,
    1550,    -1,  1464,    -1,   532,    -1,   476,    -1,   624,    -1,
     114,    -1,  1549,    21,  1548,    -1,  1549,  1523,    -1,  1549,
      20,  1548,    -1,  1549,    18,  1548,    -1,  1549,    19,  1548,
      -1,   636,   479,  1448,  1548,   442,    -1,   648,   479,  1448,
    1548,   442,    -1,   649,   479,  1448,  1548,   442,    -1,   656,
     479,  1448,  1548,   442,    -1,   544,   479,  1448,  1548,   442,
      -1,  1005,   479,  1552,   442,    -1,   585,   479,  1552,   442,
      -1,   479,  1548,   442,    -1,   492,   479,  1524,   442,    -1,
    1525,    -1,  1527,    -1,  1563,    -1,  1548,    -1,  1552,     5,
    1548,    -1,    -1,   432,  1191,   604,  1554,  1555,    -1,  1556,
      -1,  1555,     5,  1556,    -1,  1457,   667,  1461,    -1,  1457,
     667,    20,    -1,  1559,    -1,  1559,    -1,   240,  1560,    -1,
    1560,    -1,  1561,    -1,    25,   667,  1561,    -1,  1562,    -1,
    1561,   667,  1562,    -1,  1561,   667,    20,    -1,  1564,    -1,
    1005,    -1,  1558,    -1,  1558,   469,  1558,    -1,  1005,  1565,
      -1,   507,  1566,   475,    -1,   507,  1566,   475,   507,  1566,
     475,    -1,  1567,    -1,  1566,     5,  1567,    -1,   733,    -1,
      34,    -1,    -1,    -1,   575,  1570,   910,  1571,  1584,   377,
      -1,    -1,   706,   953,    -1,    -1,   709,    -1,   231,    -1,
     327,  1000,    -1,   119,  1000,    -1,   357,    -1,   356,    -1,
     358,  1002,  1572,  1573,    -1,   541,   953,  1573,    -1,   153,
      -1,   185,  1000,    -1,   910,   614,     5,   910,   443,    -1,
     557,   910,    -1,   314,  1000,    -1,   150,  1579,     8,  1580,
    1578,    -1,    -1,   594,   910,    -1,  1005,    -1,  1005,    -1,
     297,  1000,    -1,   300,  1000,   673,   910,     5,   910,    -1,
     300,  1000,   666,   910,     5,   910,    -1,    27,    -1,    -1,
    1586,    -1,  1587,  1269,    -1,  1585,    -1,  1586,  1585,    -1,
      -1,  1588,  1589,    -1,   726,    -1,   727,    -1,   728,    -1,
     729,    -1,   746,    -1,   768,    -1,   782,    -1,   783,    -1,
     789,    -1,   808,    -1,   882,    -1,   883,    -1,   884,    -1,
     885,    -1,   896,    -1,   897,    -1,   898,    -1,   899,    -1,
     900,    -1,   901,    -1,   902,    -1,   955,    -1,   986,    -1,
     990,    -1,  1012,    -1,  1014,    -1,  1017,    -1,  1018,    -1,
    1019,    -1,  1020,    -1,  1033,    -1,  1042,    -1,  1066,    -1,
    1067,    -1,  1069,    -1,  1073,    -1,  1088,    -1,  1089,    -1,
    1093,    -1,  1094,    -1,  1095,    -1,  1096,    -1,  1104,    -1,
    1119,    -1,  1139,    -1,  1150,    -1,  1151,    -1,  1152,    -1,
    1156,    -1,  1193,    -1,  1196,    -1,  1198,    -1,  1204,    -1,
    1205,    -1,  1208,    -1,  1211,    -1,  1214,    -1,  1216,    -1,
    1218,    -1,  1221,    -1,  1228,    -1,  1233,    -1,  1238,    -1,
    1239,    -1,  1240,    -1,  1252,    -1,  1305,    -1,  1306,    -1,
    1308,    -1,  1327,    -1,  1328,    -1,  1348,    -1,  1351,    -1,
    1380,    -1,  1382,    -1,  1474,    -1,  1475,    -1,  1506,    -1,
    1507,    -1,  1529,    -1,  1553,    -1,  1568,    -1,  1569,    -1,
    1574,    -1,  1575,    -1,  1577,    -1,  1581,    -1,  1582,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const unsigned short yyrline[] =
{
       0,   997,   997,  1000,  1003,  1009,  1015,  1022,  1026,  1026,
    1032,  1055,  1056,  1057,  1058,  1059,  1070,  1076,  1077,  1078,
    1079,  1080,  1085,  1086,  1097,  1100,  1103,  1103,  1107,  1110,
    1111,  1117,  1118,  1119,  1120,  1121,  1122,  1123,  1124,  1125,
    1126,  1127,  1128,  1129,  1130,  1131,  1132,  1133,  1136,  1137,
    1140,  1140,  1155,  1156,  1159,  1165,  1167,  1178,  1180,  1182,
    1184,  1188,  1190,  1252,  1256,  1260,  1260,  1270,  1274,  1277,
    1278,  1285,  1291,  1285,  1304,  1309,  1313,  1304,  1325,  1329,
    1325,  1337,  1342,  1337,  1361,  1368,  1372,  1360,  1398,  1398,
    1402,  1403,  1404,  1409,  1412,  1417,  1421,  1429,  1430,  1433,
    1433,  1439,  1443,  1458,  1456,  1474,  1474,  1489,  1489,  1492,
    1492,  1496,  1499,  1499,  1499,  1506,  1507,  1506,  1514,  1514,
    1525,  1525,  1544,  1547,  1550,  1553,  1556,  1559,  1572,  1577,
    1577,  1578,  1578,  1581,  1586,  1586,  1590,  1609,  1614,  1608,
    1625,  1631,  1639,  1640,  1643,  1643,  1646,  1650,  1655,  1662,
    1662,  1666,  1666,  1667,  1667,  1668,  1668,  1669,  1669,  1670,
    1670,  1678,  1682,  1688,  1692,  1707,  1710,  1713,  1716,  1719,
    1722,  1728,  1739,  1744,  1757,  1761,  1776,  1777,  1781,  1781,
    1785,  1785,  1785,  1786,  1791,  1791,  1794,  1794,  1803,  1804,
    1805,  1808,  1812,  1813,  1813,  1830,  1830,  1830,  1830,  1834,
    1841,  1842,  1845,  1845,  1849,  1850,  1851,  1852,  1857,  1857,
    1863,  1863,  1872,  1869,  1885,  1885,  1887,  1887,  1889,  1891,
    1893,  1895,  1898,  1902,  1902,  1903,  1903,  1907,  1907,  1919,
    1919,  1924,  1928,  1930,  1931,  1934,  1934,  1934,  1938,  1939,
    1940,  1941,  1942,  1943,  1944,  1945,  1946,  1947,  1948,  1949,
    1952,  1953,  1954,  1955,  1959,  1964,  1969,  1973,  1976,  1980,
    1980,  1981,  1981,  1982,  1982,  1983,  1984,  1985,  1986,  1987,
    1988,  1991,  1992,  1993,  2023,  2023,  2028,  2032,  2034,  2036,
    2036,  2043,  2047,  2047,  2051,  2052,  2053,  2054,  2055,  2056,
    2057,  2063,  2063,  2066,  2068,  2074,  2076,  2082,  2090,  2090,
    2093,  2094,  2095,  2096,  2097,  2098,  2099,  2105,  2108,  2108,
    2121,  2121,  2128,  2129,  2130,  2132,  2133,  2136,  2140,  2141,
    2142,  2143,  2148,  2154,  2160,  2161,  2163,  2165,  2166,  2167,
    2168,  2169,  2170,  2173,  2174,  2181,  2189,  2189,  2197,  2194,
    2209,  2209,  2211,  2211,  2219,  2219,  2222,  2225,  2226,  2231,
    2243,  2247,  2250,  2253,  2254,  2255,  2256,  2257,  2262,  2269,
    2275,  2280,  2285,  2280,  2298,  2300,  2305,  2310,  2310,  2310,
    2314,  2314,  2317,  2317,  2324,  2324,  2331,  2331,  2342,  2360,
    2366,  2390,  2393,  2408,  2411,  2424,  2426,  2428,  2430,  2432,
    2434,  2436,  2442,  2444,  2448,  2450,  2452,  2454,  2456,  2458,
    2460,  2466,  2480,  2481,  2482,  2483,  2484,  2488,  2489,  2490,
    2494,  2499,  2506,  2507,  2508,  2509,  2510,  2511,  2512,  2513,
    2514,  2515,  2516,  2523,  2523,  2528,  2528,  2531,  2537,  2545,
    2551,  2561,  2562,  2570,  2577,  2581,  2591,  2595,  2600,  2605,
    2607,  2610,  2616,  2624,  2637,  2642,  2648,  2653,  2658,  2659,
    2665,  2736,  2747,  2756,  2764,  2764,  2779,  2783,  2790,  2793,
    2801,  2805,  2808,  2814,  2823,  2828,  2836,  2839,  2842,  2847,
    2854,  2859,  2864,  2869,  2879,  2887,  2895,  2900,  2904,  2909,
    2913,  2917,  2924,  2927,  2930,  2934,  2938,  2942,  2946,  2954,
    2964,  2969,  2962,  2985,  2990,  2985,  3007,  3007,  3007,  3010,
    3010,  3010,  3014,  3014,  3014,  3018,  3018,  3018,  3022,  3028,
    3034,  3040,  3046,  3052,  3061,  3067,  3077,  3077,  3081,  3085,
    3086,  3097,  3098,  3104,  3114,  3124,  3134,  3135,  3138,  3143,
    3149,  3153,  3157,  3160,  3166,  3169,  3172,  3189,  3192,  3198,
    3199,  3200,  3204,  3205,  3206,  3207,  3208,  3210,  3211,  3212,
    3214,  3215,  3219,  3220,  3225,  3229,  3234,  3238,  3253,  3257,
    3263,  3252,  3276,  3277,  3289,  3295,  3289,  3309,  3309,  3311,
    3312,  3316,  3316,  3320,  3320,  3325,  3325,  3332,  3333,  3337,
    3337,  3341,  3341,  3346,  3346,  3353,  3357,  3358,  3359,  3364,
    3364,  3367,  3367,  3371,  3371,  3375,  3375,  3379,  3379,  3384,
    3384,  3389,  3389,  3394,  3394,  3399,  3399,  3415,  3419,  3414,
    3427,  3430,  3444,  3461,  3462,  3463,  3464,  3465,  3466,  3467,
    3470,  3470,  3473,  3475,  3478,  3481,  3484,  3489,  3494,  3497,
    3502,  3507,  3512,  3519,  3520,  3527,  3534,  3536,  3542,  3547,
    3552,  3557,  3557,  3560,  3566,  3571,  3574,  3581,  3581,  3583,
    3586,  3589,  3594,  3599,  3604,  3611,  3620,  3620,  3682,  3690,
    3691,  3699,  3706,  3706,  3710,  3715,  3721,  3725,  3729,  3735,
    3739,  3743,  3749,  3749,  3757,  3758,  3762,  3762,  3766,  3767,
    3770,  3773,  3773,  3776,  3778,  3778,  3781,  3783,  3783,  3784,
    3786,  3786,  3795,  3802,  3793,  3823,  3823,  3823,  3826,  3828,
    3826,  3835,  3838,  3844,  3855,  3855,  3859,  3865,  3865,  3869,
    3870,  3874,  3884,  3885,  3886,  3889,  3891,  3896,  3896,  3900,
    3899,  3907,  3906,  3913,  3913,  3919,  3919,  3926,  3926,  3932,
    3932,  3938,  3938,  3944,  3944,  3948,  3948,  3949,  3949,  3950,
    3950,  3951,  3951,  3955,  3955,  3966,  3970,  3976,  3980,  3985,
    3990,  3995,  3996,  3997,  4001,  4000,  4013,  4018,  4023,  4023,
    4039,  4045,  4046,  4047,  4048,  4049,  4059,  4073,  4073,  4076,
    4083,  4084,  4085,  4086,  4087,  4088,  4089,  4090,  4091,  4096,
    4096,  4098,  4101,  4101,  4103,  4107,  4110,  4111,  4114,  4114,
    4119,  4122,  4123,  4124,  4125,  4126,  4127,  4128,  4129,  4130,
    4131,  4132,  4133,  4134,  4135,  4136,  4137,  4138,  4139,  4143,
    4161,  4161,  4161,  4188,  4199,  4206,  4212,  4218,  4224,  4236,
    4261,  4260,  4277,  4277,  4281,  4282,  4290,  4291,  4292,  4293,
    4294,  4295,  4302,  4303,  4305,  4306,  4310,  4315,  4316,  4317,
    4318,  4319,  4320,  4321,  4322,  4323,  4325,  4328,  4330,  4330,
    4332,  4336,  4336,  4345,  4350,  4366,  4372,  4344,  4386,  4400,
    4410,  4399,  4423,  4430,  4430,  4435,  4441,  4449,  4454,  4455,
    4458,  4461,  4461,  4469,  4475,  4486,  4487,  4491,  4495,  4508,
    4490,  4521,  4527,  4521,  4538,  4539,  4543,  4543,  4550,  4550,
    4565,  4565,  4579,  4590,  4589,  4601,  4597,  4614,  4611,  4624,
    4624,  4626,  4627,  4629,  4630,  4633,  4634,  4635,  4637,  4642,
    4647,  4653,  4655,  4656,  4659,  4660,  4663,  4665,  4672,  4675,
    4678,  4681,  4685,  4689,  4690,  4691,  4692,  4693,  4697,  4702,
    4702,  4705,  4732,  4790,  4790,  4793,  4797,  4801,  4844,  4886,
    4887,  4888,  4891,  4905,  4917,  4917,  4922,  4923,  4929,  4994,
    4999,  5006,  5011,  5019,  5025,  5058,  5061,  5062,  5103,  5146,
    5147,  5151,  5152,  5156,  5209,  5214,  5218,  5223,  5234,  5241,
    5249,  5249,  5252,  5253,  5254,  5255,  5256,  5259,  5262,  5268,
    5271,  5275,  5280,  5288,  5293,  5300,  5302,  5308,  5310,  5310,
    5310,  5334,  5341,  5348,  5351,  5365,  5372,  5373,  5376,  5377,
    5381,  5387,  5392,  5398,  5399,  5404,  5408,  5408,  5412,  5413,
    5416,  5417,  5421,  5429,  5432,  5438,  5439,  5441,  5443,  5447,
    5447,  5448,  5453,  5461,  5462,  5467,  5468,  5470,  5483,  5485,
    5486,  5489,  5490,  5491,  5492,  5493,  5494,  5495,  5496,  5497,
    5498,  5499,  5500,  5501,  5502,  5503,  5504,  5505,  5506,  5507,
    5508,  5509,  5510,  5511,  5512,  5513,  5514,  5528,  5536,  5536,
    5538,  5542,  5546,  5550,  5554,  5559,  5574,  5572,  5592,  5593,
    5597,  5602,  5603,  5607,  5608,  5610,  5611,  5613,  5613,  5622,
    5631,  5631,  5641,  5642,  5647,  5648,  5651,  5664,  5678,  5682,
    5686,  5690,  5697,  5698,  5701,  5701,  5705,  5708,  5708,  5710,
    5716,  5724,  5730,  5732,  5736,  5739,  5739,  5742,  5742,  5747,
    5747,  5756,  5756,  5760,  5760,  5761,  5761,  5762,  5762,  5776,
    5776,  5796,  5797,  5798,  5799,  5800,  5801,  5804,  5804,  5810,
    5810,  5813,  5813,  5829,  5830,  5831,  5840,  5852,  5853,  5856,
    5857,  5860,  5863,  5863,  5868,  5868,  5889,  5894,  5900,  5901,
    5902,  5906,  5907,  5908,  5909,  5913,  5923,  5925,  5930,  5933,
    5938,  5944,  5951,  5958,  5967,  5974,  5981,  5988,  5995,  6004,
    6004,  6006,  6006,  6009,  6010,  6011,  6012,  6013,  6014,  6015,
    6016,  6017,  6018,  6021,  6021,  6024,  6025,  6026,  6027,  6030,
    6030,  6033,  6033,  6036,  6037,  6038,  6039,  6040,  6041,  6042,
    6043,  6045,  6046,  6047,  6048,  6050,  6051,  6052,  6053,  6055,
    6056,  6057,  6058,  6059,  6060,  6061,  6062,  6066,  6074,  6084,
    6097,  6106,  6117,  6121,  6125,  6131,  6096,  6144,  6147,  6155,
    6167,  6169,  6174,  6182,  6192,  6195,  6199,  6207,  6173,  6216,
    6220,  6224,  6228,  6220,  6238,  6239,  6240,  6241,  6246,  6248,
    6251,  6255,  6258,  6265,  6270,  6271,  6272,  6273,  6278,  6279,
    6285,  6285,  6285,  6290,  6290,  6290,  6298,  6299,  6303,  6304,
    6309,  6310,  6311,  6312,  6313,  6316,  6318,  6318,  6321,  6322,
    6326,  6327,  6330,  6331,  6334,  6337,  6340,  6346,  6347,  6359,
    6360,  6365,  6366,  6367,  6371,  6374,  6380,  6383,  6391,  6392,
    6398,  6402,  6406,  6412,  6415,  6424,  6427,  6430,  6433,  6436,
    6439,  6442,  6449,  6452,  6459,  6462,  6468,  6471,  6478,  6481,
    6488,  6489,  6494,  6498,  6501,  6507,  6510,  6516,  6523,  6524,
    6528,  6538,  6541,  6547,  6549,  6554,  6555,  6559,  6561,  6567,
    6568,  6581,  6593,  6594,  6595,  6596,  6597,  6598,  6599,  6600,
    6601,  6604,  6607,  6613,  6613,  6619,  6619,  6630,  6643,  6653,
    6653,  6658,  6658,  6662,  6666,  6667,  6673,  6674,  6679,  6683,
    6690,  6693,  6700,  6699,  6710,  6714,  6718,  6725,  6728,  6728,
    6741,  6745,  6745,  6760,  6762,  6764,  6766,  6768,  6770,  6772,
    6774,  6780,  6790,  6797,  6802,  6803,  6807,  6810,  6811,  6814,
    6815,  6816,  6819,  6824,  6831,  6832,  6838,  6850,  6851,  6852,
    6855,  6855,  6860,  6865,  6870,  6871,  6874,  6875,  6880,  6885,
    6889,  6894,  6895,  6899,  6906,  6907,  6908,  6909,  6914,  6915,
    6916,  6919,  6920,  6921,  6925,  6926,  6927,  6931,  6932,  6936,
    6937,  6938,  6939,  6940,  6941,  6944,  6945,  6950,  6951,  6956,
    6957,  6962,  6963,  6968,  6973,  6974,  6979,  6980,  6984,  6985,
    6990,  6997,  7002,  7007,  7011,  7012,  7017,  7018,  7024,  7025,
    7026,  7031,  7032,  7038,  7041,  7044,  7051,  7052,  7053,  7054,
    7068,  7073,  7074,  7077,  7079,  7086,  7089,  7095,  7103,  7107,
    7111,  7115,  7119,  7122,  7125,  7132,  7139,  7144,  7148,  7149,
    7155,  7158,  7169,  7176,  7182,  7185,  7192,  7199,  7205,  7206,
    7212,  7213,  7214,  7217,  7218,  7223,  7223,  7227,  7235,  7236,
    7239,  7242,  7247,  7248,  7253,  7256,  7262,  7265,  7271,  7274,
    7280,  7283,  7290,  7291,  7320,  7321,  7326,  7334,  7339,  7342,
    7345,  7348,  7354,  7355,  7359,  7362,  7365,  7366,  7371,  7374,
    7377,  7380,  7383,  7386,  7389,  7392,  7397,  7403,  7404,  7405,
    7406,  7407,  7409,  7410,  7412,  7413,  7418,  7421,  7425,  7431,
    7432,  7433,  7434,  7446,  7447,  7448,  7452,  7453,  7457,  7458,
    7459,  7460,  7461,  7463,  7465,  7466,  7467,  7468,  7469,  7470,
    7471,  7472,  7474,  7476,  7478,  7479,  7481,  7482,  7484,  7485,
    7486,  7487,  7489,  7493,  7494,  7500,  7502,  7503,  7504,  7505,
    7510,  7514,  7518,  7522,  7529,  7533,  7534,  7535,  7543,  7544,
    7545,  7556,  7563,  7568,  7569,  7570,  7578,  7579,  7580,  7597,
    7606,  7607,  7608,  7612,  7615,  7620,  7625,  7630,  7638,  7642,
    7647,  7648,  7656,  7659,  7662,  7676,  7690,  7703,  7704,  7708,
    7708,  7708,  7708,  7708,  7708,  7709,  7712,  7717,  7717,  7717,
    7717,  7717,  7717,  7719,  7722,  7728,  7728,  7728,  7728,  7728,
    7728,  7728,  7729,  7729,  7729,  7729,  7729,  7729,  7729,  7729,
    7732,  7733,  7734,  7737,  7746,  7746,  7752,  7752,  7759,  7759,
    7765,  7765,  7773,  7774,  7775,  7778,  7778,  7781,  7782,  7783,
    7794,  7797,  7803,  7808,  7815,  7828,  7829,  7826,  7847,  7858,
    7861,  7866,  7878,  7881,  7885,  7888,  7889,  7895,  7898,  7899,
    7908,  7917,  7922,  7923,  7924,  7925,  7932,  7935,  7941,  7944,
    7951,  7963,  7972,  7975,  7978,  7984,  7990,  7993,  7994,  7995,
    7996,  7997,  8000,  8006,  8008,  8010,  8012,  8014,  8016,  8017,
    8018,  8019,  8020,  8021,  8022,  8024,  8026,  8028,  8030,  8032,
    8034,  8036,  8037,  8039,  8040,  8046,  8047,  8054,  8057,  8065,
    8069,  8076,  8076,  8080,  8080,  8085,  8085,  8089,  8089,  8093,
    8099,  8099,  8102,  8102,  8108,  8115,  8116,  8117,  8121,  8122,
    8125,  8126,  8130,  8136,  8146,  8147,  8155,  8156,  8157,  8158,
    8159,  8160,  8164,  8165,  8166,  8167,  8171,  8172,  8176,  8177,
    8178,  8179,  8180,  8181,  8182,  8184,  8188,  8189,  8190,  8194,
    8195,  8196,  8197,  8198,  8199,  8202,  8202,  8214,  8215,  8219,
    8220,  8221,  8222,  8223,  8224,  8225,  8226,  8227,  8228,  8229,
    8230,  8231,  8232,  8233,  8234,  8235,  8236,  8237,  8238,  8239,
    8240,  8241,  8242,  8243,  8244,  8245,  8246,  8247,  8248,  8249,
    8250,  8251,  8252,  8253,  8254,  8255,  8256,  8257,  8258,  8259,
    8260,  8261,  8262,  8263,  8264,  8265,  8266,  8267,  8268,  8269,
    8270,  8271,  8272,  8273,  8274,  8275,  8276,  8277,  8278,  8279,
    8280,  8281,  8282,  8283,  8284,  8285,  8286,  8287,  8288,  8289,
    8290,  8291,  8292,  8293,  8294,  8295,  8296,  8297,  8298,  8299,
    8300,  8301,  8302,  8303,  8304,  8305,  8306,  8307,  8308,  8309,
    8310,  8311,  8312,  8313,  8314,  8315,  8316,  8317,  8318,  8319,
    8320,  8321,  8322,  8323,  8324,  8325,  8326,  8327,  8328,  8329,
    8330,  8331,  8332,  8333,  8334,  8335,  8336,  8337,  8338,  8339,
    8340,  8341,  8342,  8343,  8344,  8345,  8346,  8347,  8348,  8349,
    8350,  8351,  8352,  8353,  8354,  8355,  8356,  8357,  8358,  8359,
    8360,  8361,  8362,  8363,  8364,  8365,  8366,  8367,  8368,  8369,
    8370,  8371,  8372,  8373,  8374,  8375,  8376,  8377,  8378,  8379,
    8380,  8381,  8382,  8383,  8384,  8385,  8386,  8387,  8388,  8389,
    8390,  8391,  8392,  8393,  8394,  8395,  8396,  8397,  8398,  8399,
    8400,  8401,  8402,  8403,  8404,  8405,  8406,  8407,  8408,  8409,
    8410,  8411,  8412,  8413,  8414,  8415,  8416,  8417,  8418,  8419,
    8420,  8421,  8423,  8424,  8425,  8426,  8427,  8428,  8429,  8430,
    8431,  8432,  8433,  8434,  8435,  8436,  8437,  8438,  8439,  8440,
    8441,  8442,  8443,  8444,  8445,  8446,  8447,  8448,  8449,  8450,
    8451,  8452,  8453,  8454,  8455,  8456,  8457,  8458,  8459,  8460,
    8461,  8462,  8463,  8464,  8465,  8466,  8467,  8468,  8469,  8470,
    8471,  8472,  8473,  8474,  8475,  8476,  8477,  8478,  8479,  8480,
    8481,  8482,  8483,  8484,  8485,  8486,  8487,  8488,  8489,  8490,
    8491,  8492,  8493,  8494,  8495,  8496,  8497,  8498,  8499,  8500,
    8501,  8502,  8503,  8504,  8505,  8506,  8507,  8508,  8509,  8510,
    8511,  8512,  8513,  8514,  8515,  8516,  8517,  8518,  8519,  8520,
    8521,  8522,  8523,  8524,  8525,  8526,  8527,  8528,  8529,  8530,
    8531,  8532,  8533,  8534,  8535,  8536,  8537,  8545,  8545,  8552,
    8552,  8640,  8644,  8640,  8653,  8657,  8663,  8671,  8681,  8691,
    8703,  8706,  8725,  8751,  8754,  8760,  8763,  8768,  8771,  8779,
    8787,  8800,  8803,  8811,  8814,  8817,  8825,  8829,  8830,  8831,
    8832,  8833,  8834,  8835,  8836,  8840,  8841,  8842,  8843,  8844,
    8850,  8851,  8852,  8853,  8854,  8855,  8856,  8857,  8858,  8859,
    8860,  8861,  8862,  8863,  8864,  8865,  8870,  8876,  8877,  8885,
    8885,  8893,  8893,  8897,  8901,  8916,  8931,  8937,  8939,  8947,
    8948,  8952,  8953,  8956,  8963,  8966,  8995,  9021,  9075,  9111,
    9120,  9131,  9134,  9139,  9153,  9167,  9170,  9166,  9189,  9189,
    9195,  9196,  9199,  9200,  9201,  9202,  9203,  9204,  9205,  9216,
    9219,  9224,  9228,  9233,  9237,  9242,  9246,  9249,  9253,  9256,
    9261,  9265,  9276,  9282,  9282,  9283,  9284,  9291,  9301,  9301,
    9303,  9304,  9305,  9306,  9307,  9308,  9309,  9310,  9311,  9312,
    9313,  9314,  9315,  9316,  9317,  9318,  9319,  9320,  9321,  9322,
    9323,  9324,  9325,  9326,  9327,  9328,  9329,  9330,  9331,  9332,
    9333,  9334,  9335,  9336,  9337,  9338,  9339,  9340,  9341,  9342,
    9343,  9344,  9345,  9346,  9347,  9348,  9349,  9350,  9351,  9352,
    9353,  9354,  9355,  9356,  9357,  9358,  9359,  9360,  9361,  9362,
    9363,  9364,  9365,  9366,  9367,  9368,  9369,  9370,  9371,  9372,
    9373,  9374,  9375,  9376,  9377,  9378,  9379,  9380,  9381,  9382,
    9383,  9384,  9385,  9386,  9387,  9388,  9389,  9390
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
  "KW_CEND", "USER_DTYPE", "SQL_TEXT", "KW_WHENEVER_SET", "COMMENT", 
  "DYNAMIC_ARRAY", "RESIZE_ARRAY", "ALLOCATE_ARRAY", "DEALLOCATE_ARRAY", 
  "AFTER_INSERT_DELETE", "BEFORE_INSERT_DELETE", "BEFORE_INSERT", 
  "AS_CONVERTABLE", "CONCAT_PIPES", "BEFORE_DELETE", "DROP_TRIGGER", 
  "AFTER_INSERT", "AFTER_DELETE", "EXECUTE_IMMEDIATE", 
  "DELETE_ROW_EQUAL_TRUE", "INSERT_ROW_EQUAL_TRUE", 
  "DELETE_ROW_EQUAL_FALSE", "INSERT_ROW_EQUAL_FALSE", 
  "CURRENT_ROW_DISPLAY_EQUAL", "MAXCOUNT", "ALTER_TABLE", "ALTER_INDEX", 
  "NEXT_SIZE", "DISPLAY_ATTR_FORM", "DISPLAY_ATTR_WINDOW", 
  "INPUT_ATTR_FORM", "INPUT_ATTR_WINDOW", "WHENEVER_ERROR_CONTINUE", 
  "WHENEVER_ANY_ERROR_CONTINUE", "WHENEVER_WARNING_CONTINUE", 
  "WHENEVER_SQLSUCCESS_CONTINUE", "WHENEVER_SQLWARNING_CONTINUE", 
  "WHENEVER_NOT_FOUND_CONTINUE", "WHENEVER_SQLERROR_CONTINUE", 
  "WHENEVER_SUCCESS_CONTINUE", "WHENEVER_ERROR_GOTO", 
  "WHENEVER_ANY_ERROR_GOTO", "WHENEVER_WARNING_GOTO", 
  "WHENEVER_SQLSUCCESS_GOTO", "WHENEVER_SQLWARNING_GOTO", 
  "WHENEVER_NOT_FOUND_GOTO", "WHENEVER_SQLERROR_GOTO", 
  "WHENEVER_SUCCESS_GOTO", "WHENEVER_ERROR_CALL", 
  "WHENEVER_ANY_ERROR_CALL", "WHENEVER_WARNING_CALL", 
  "WHENEVER_SQLSUCCESS_CALL", "WHENEVER_SQLWARNING_CALL", 
  "WHENEVER_NOT_FOUND_CALL", "WHENEVER_SQLERROR_CALL", 
  "WHENEVER_SUCCESS_CALL", "WHENEVER_ERROR_STOP", 
  "WHENEVER_ANY_ERROR_STOP", "WHENEVER_WARNING_STOP", 
  "WHENEVER_SQLSUCCESS_STOP", "WHENEVER_SQLWARNING_STOP", 
  "WHENEVER_NOT_FOUND_STOP", "WHENEVER_SQLERROR_STOP", 
  "WHENEVER_SUCCESS_STOP", "XSET_MULTIPLY_EQUAL_OPEN_BRACKET", 
  "XSET_ident_DOT_MULTIPLY_EQUAL_OPEN_BRACKET", 
  "XSET_ident_DOT_MULTIPLY_EQUAL", "XSET_MULTIPLY_EQUAL", 
  "XSET_OPEN_BRACKET", "NEWFORMATSHARED", "CREATE_DATABASE", 
  "DROP_DATABASE", "IMPORT_LEGACY_FUNCTION", "ADD_CONSTRAINT", 
  "DROP_CONSTRAINT", "DROP_SYNONYM", "CONSTRAINT", "AS_STATIC", 
  "NOT_FIELD_TOUCHED", "LOCAL_FUNCTION", "EVERY_ROW", "ELIF", 
  "DOUBLE_PRECISION", "COUNT_MULTIPLY", "WAIT_FOR_KEY", 
  "AT_TERMINATION_CALL", "TERMINATE_REPORT", "TO_MAIN_CAPTION", 
  "CLEARSTAT", "TO_MENUITEM", "ID_TO_INT", "TO_STATUSBOX", 
  "ASCII_HEIGHT_ALL", "ASCII_WIDTH_ALL", "IMPORT_DATATYPE", 
  "PAGE_TRAILER_SIZE", "PAGE_HEADER_SIZE", "FIRST_PAGE_HEADER_SIZE", 
  "BYTES_USE_AS_IMAGE", "BYTES_USE_AS_ASCII", "KWUP_BY", "KWDOWN_BY", 
  "CLOSE_STATUSBOX", "MODIFY_NEXT_SIZE", "LOCK_MODE_PAGE", 
  "LOCK_MODE_ROW", "TO_PIPE", "TO_PRINTER", "STATUSBOX", 
  "FORMHANDLER_INPUT", "UNITS_YEAR", "UNITS_MONTH", "UNITS_DAY", 
  "UNITS_HOUR", "UNITS_MINUTE", "UNITS_SECOND", "NO_NEW_LINES", 
  "FIELDTOWIDGET", "WITH_HOLD", "SHOW_MENU", "TO_CLUSTER", 
  "TO_NOT_CLUSTER", "CWIS", "CREATE_IDX", "FORM_IS_COMPILED", 
  "PDF_REPORT", "IMPORT_FUNCTION", "PROMPT_MANY", "POINTS", "MM", 
  "INCHES", "PREPEND", "MEMBER_OF", "MEMBER_FUNCTION", "APPEND", 
  "TEMPLATE", "END_TEMPLATE", "SQLSICS", "CREATE_SCHEMA", "SQLSIRR", 
  "UPDATESTATS_T", "SQLSICR", "WHENEVER_SQLSUCCESS", 
  "WHENEVER_SQLWARNING", "WHENEVER_ANY_ERROR", "WHENEVER_NOT_FOUND", 
  "WHENEVER_SQLERROR", "WHENEVER_SUCCESS", "WHENEVER_ERROR", 
  "START_EXTERN", "CONTINUE_CONSTRUCT", "FOUNCONSTR", "SQLSIDR", 
  "CREATE_TEMP_TABLE", "CURRENT_WINDOW_IS", "FIRST_PAGE_HEADER", 
  "ORDER_EXTERNAL_BY", "SCROLL_CURSOR_FOR", "SCROLL_CURSOR", 
  "SQL_INTERRUPT_OFF", "STOP_ALL_EXTERNAL", "WITH_CHECK_OPTION", 
  "WITH_GRANT_OPTION", "SQLSLMNW", "ADDCONSTUNIQ", "CONTINUE_DISPLAY", 
  "CONTINUE_FOREACH", "OUTPUT_TO_REPORT", "SQL_INTERRUPT_ON", 
  "WHERE_CURRENT_OF", "WITHOUT_DEFAULTS", "FOCONSTR", "SCALED_BY", 
  "CONTINUE_PROMPT", "PDF_FUNCTION", "DEFER_INTERRUPT", "DISPLAY_BY_NAME", 
  "NOT_NULL_UNIQUE", "SKIP_TO_TOP", "TOP_OF_PAGE", "SKIP_TO", "SKIP_BY", 
  "WITHOUT_WAITING", "BEFCONSTRUCT", "SQLSLMW", "AFTCONSTRUCT", 
  "ALL_PRIVILEGES", "CLOSE_DATABASE", "CONTINUE_INPUT", "CONTINUE_WHILE", 
  "CREATE_SYNONYM", "DROP_TABLE", "EXIT_CONSTRUCT", "INEXCLUSIVE", 
  "REPORT_TO_PRINTER", "REPORT_TO_PIPE", "RETURN", "SET_SESSION_TO", 
  "UPDATESTATS", "WITHOUT_HEAD", "CLEARSCR", "WITH_B_LOG", 
  "AUTHORIZATION", "BOTTOM_MARGIN", "CLOSE_SESSION", "CONTINUE_CASE", 
  "CONTINUE_MENU", "DISPLAY_ARRAY", "END_SQL", "DOLLAR", "END_CONSTRUCT", 
  "FIELD_TOUCHED", "FINISH_REPORT", "INFACC", "INPUT_NO_WRAP", "SETPMOFF", 
  "UNCONSTRAINED", "PAGE_TRAILER", "SETPMON", "BEFGROUP", "CLOSE_WINDOW", 
  "COMMENT_LINE", "CONTINUE_FOR", "CREATE_DB", "CREATE_TABLE", 
  "DEFAULT_NULL", "DEFAULT_TODAY", "DEFAULT_USER", "DELETE_USING", 
  "DISPLAY_FORM", "END_FUNCTION", "EXIT_DISPLAY", "EXIT_FOREACH", 
  "EXIT_PROGRAM", "INFCOLS", "ON_EVERY_ROW", "OPEN_SESSION", 
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
  "CHAR", "NCHAR", "NVARCHAR", "CONSTRUCT", "DELIMITER", "DOWNSHIFT", 
  "DROP_VIEW", "END_INPUT", "END_WHILE", "EXCLUSIVE", "EXIT_CASE", 
  "EXIT_MENU", "FORM_LINE", "INTERRUPT", "INTO_TEMP", "INVISIBLE", 
  "IN_MEMORY", "LINKED_TO", "LOAD_FROM", "LOCKTAB", "MENU_LINE", 
  "OPEN_FORM", "OTHERWISE", "PRECISION", "PRIOR", "PROCEDURE", 
  "REPORT_TO", "RETURNING", "UNDERLINE", "UNLOAD_TO", "BEFROW", 
  "UNLOAD_T", "VARIABLE", "ABSOLUTE", "AFTROW", "BUFFERED", "CONSTANT", 
  "CONST", "DATABASE", "DATETIME", "DEFAULTS", "DISTINCT", "END_CASE", 
  "END_MAIN", "END_MENU", "END_TYPE", "EXIT_FOR", "EXTERNAL", "FRACTION", 
  "FUNCTION", "GROUP_BY", "INTERVAL", "KWMESSAGE", "NOT_LIKE", 
  "NOT_ILIKE", "NOT_NULL", "PASSWORD", "PREVIOUS", "READONLY", "REGISTER", 
  "RELATIVE", "RESOURCE", "SMALLINT", "VALIDATE", "WITH_LOG", "WORDWRAP", 
  "BY_NAME", "IN_FILE", "IS_NULL", "AVERAGE", "BETWEEN", "CAPTION", 
  "CLIPPED", "CLOSE_BRACKET", "COLUMNS", "CONNECT", "CURRENT", "DBYNAME", 
  "DECIMAL", "DECLARE", "DEFAULT", "DISPLAY", "ENDCODE", "EXECUTE", 
  "FOREACH", "FOREIGN", "GLOBALS", "INFIELD", "INTEGER", "KWWINDOW", 
  "MAGENTA", "OPTIONS", "PERCENT", "PREPARE", "PROGRAM", "RECOVER", 
  "REVERSE", "SECTION", "SESSION", "SYNONYM", "THRU", "TRAILER", 
  "UPSHIFT", "VARCHAR", "WAITING", "CLOSE_SHEV", "CLOSE_SQUARE", 
  "KW_FALSE", "NOT_IN", "ONKEY", "OPEN_BRACKET", "BORDER", "BOTTOM", 
  "COLUMN", "COMMIT", "CREATE", "CURSOR", "DEFINE", "DELETE", "DOUBLE", 
  "END_IF", "ESCAPE", "EXISTS", "EXTEND", "EXTENT", "FINISH", "FORMAT", 
  "HAVING", "HEADER", "INSERT", "LOCATE", "MARGIN", "MEMORY", "MINUTE", 
  "MODIFY", "NORMAL", "EQUAL_EQUAL", "OPEN_SHEV", "OPEN_SQUARE", "OPTION", 
  "OUTPUT", "PROMPT", "PUBLIC", "RECORD", "REPORT", "REVOKE", "SCHEMA", 
  "SCROLL_USING", "SCROLL", "SECOND", "SELECT", "SERIAL", "SETL", 
  "SHARED", "SPACES", "UNIQUE", "UNLOCK", "UPDATE", "VALUES", "YELLOW", 
  "AFTER", "KWLINE", "KW_NULL", "KW_TRUE", "SINGLE_KEY", "ALTER", "ARRAY", 
  "ASCII", "AUDIT", "BLACK", "BLINK", "CHECK", "CLEAR", "CLOSE", "CODE_C", 
  "COUNT", "DEFER", "ERROR", "EVERY", "FETCH", "FIRST", "FLOAT", "FLUSH", 
  "FOUND", "GRANT", "GREEN", "GROUP", "INDEX", "KWFORM", "LABEL", "LOCAL", 
  "MONEY", "MONTH", "ORDER", "OUTER", "PAUSE", "PRINT_IMAGE", 
  "PRINT_FILE", "PRINT", "RIGHT", "DOUBLE_COLON", "SEMICOLON", "SLEEP", 
  "TUPLE", "UNION", "WHERE", "WHILE", "WHITE", "CCODE", "ANSI", "BLUE", 
  "BOLD", "BYTE", "FCALL", "CASE", "CYAN", "DATE", "DESC", "KWDOWN", 
  "TAB", "DROP", "ELSE", "EXEC", "EXIT", "FREE", "FROM", "GOTO", 
  "HELP_FILE", "LANG_FILE", "HELP", "HIDE", "HOUR", "INTO", "LAST", 
  "LEFT", "LIKE", "MAIN", "MENU", "MODE", "NEED", "NEXT", "NOCR", "OPEN", 
  "QUIT", "REAL", "ROWS", "SHOW", "SIZE", "SKIP", "SOME", "STEP", "STOP", 
  "TEMP", "TEXT", "THEN", "USER", "WAIT", "WHEN", "WITH", "WORK", "YEAR", 
  "KW_IS", "XSET", "ADD", "ALL", "ANY", "ASC", "AVG", "COLON", "DAY", 
  "DBA", "DEC", "DIM", "FKEY", "FOR", "KEY", "KWNO", "LET", "LOG", "XMAX", 
  "XMIN", "PAD", "PUT", "RED", "ROW", "RUN", "SQL", "SUM", "TOP", "USE", 
  "ATSIGN", "AS_TIFF", "AS_GIF", "AS_PNG", "AS_JPEG", "AS", "AT", "BY", 
  "DOT", "GO", "IF", "IN", "OF", "ON", "TO", "KWUP", "FONT_NAME", 
  "FONT_SIZE", "PAPER_SIZE_IS_LETTER", "PAPER_SIZE_IS_LEGAL", 
  "PAPER_SIZE_IS_A5", "PAPER_SIZE_IS_A4", "PAPER_SIZE_IS_LETTER_L", 
  "PAPER_SIZE_IS_LEGAL_L", "PAPER_SIZE_IS_A5_L", "PAPER_SIZE_IS_A4_L", 
  "FORMHANDLER", "END_FORMHANDLER", "BEFORE_EVENT", "BEFORE_OPEN_FORM", 
  "AFTER_EVENT", "BEFORE_CLOSE_FORM", "BEFORE_ANY", "AFTER_ANY", 
  "MENUHANDLER", "END_MENUHANDLER", "BEFORE_SHOW_MENU", "DISABLE_PROGRAM", 
  "DISABLE_ALL", "BUTTONS", "CHECK_MENUITEM", "DISABLE_FORM", 
  "DISABLE_MENUITEMS", "DISABLE", "ENABLE_FORM", "ENABLE_MENUITEMS", 
  "ENABLE", "KWFIELD", "ICON", "MESSAGEBOX", "TO_DEFAULTS", 
  "UNCHECK_MENUITEM", "BEFORE", "INPUT", "END", "INT_TO_ID", "TIMEOUT", 
  "OFF", "WITH_1_DIMENSION", "WITH_2_DIMENSION", "WITH_3_DIMENSION", 
  "TILDE", "ILIKE", "FGL_ISDYNARR_ALLOCATED", "FGL_DYNARR_EXTENTSIZE", 
  "FILLFACTOR", "$accept", "pause_screen_on_cmd", "pause_screen_off_cmd", 
  "start_rpc_cmd", "stop_rpc_cmd", "valid_port", "remote_func_list", 
  "remote_func", "arr_expr", "arr_next_math", "arr_int_sign", 
  "opt_attributes", "attributes_def", "@1", "attribs_sec", "attribute", 
  "win_attributes", "win_attributes_def", "@2", "wattribs_sec", 
  "wattribute", "call_cmd", "call_ext", "@3", "@4", "@5", "@6", "@7", 
  "@8", "@9", "@10", "@11", "@12", "@13", "@14", "@15", "opt_return", 
  "opt_return_remote", "opt_func_call_args", "func_call_args", "func_arg", 
  "remote_host_name", "remote_func_name", "case_cmd", "@16", "@17", 
  "when_unit", "when_unit_expr", "end_case_command", 
  "op_otherwise_command", "@18", "op_otherwise_command_expr", "@19", 
  "when_command", "@20", "when_command_expr", "@21", "close_cmd", 
  "code_cmd", "emb_code", "sql_code", "sql_code_part", "c_code", 
  "c_code_part", "construct_cmd", "@22", "@23", "constr_rest", 
  "end_constr", "constr_col_list", "constr_col", "constr_extra_commands", 
  "constr_extra_command", "@24", "@25", "@26", "@27", "@28", 
  "bef_c_field_list_as_struct", "aft_c_field_list_as_struct", 
  "interval_expr", "extend_parameters", "op_datetime_qual", "defer_cmd", 
  "define_section", "define_multiple", "define_set", "@29", "@30", 
  "def_part", "define_ident", "@31", "def_part2", "@32", "constant_value", 
  "var_def_name", "var_def_list", "op_char", "ranking", "array_variable", 
  "@33", "@34", "@35", "assoc_open_bracket", "assoc_close_bracket", 
  "number_arr_assoc", "number_arr_list", "number_value_arr", 
  "record_variable", "@36", "@37", "@38", "link_to_pk_list", "link_to_pk", 
  "dtype_ident", "op_as_static", "dtype2", "@39", "@40", "dtype", "@41", 
  "@42", "@43", "op_prec", "like_var", "tab_name", "col_name", 
  "datetime_qual", "interval_qual", "dtime_start", "@44", "dtime_val", 
  "dtime_end", "@45", "opt_frac", "opt_unit_size", "dtfrac", "int_start", 
  "@46", "int_start_unit", "int_end", "op_equal", "dim_section", "@47", 
  "dim_dtype", "dim_like_var", "dim_array_variable", "@48", "@49", 
  "dim_record_variable", "@50", "@51", "dim_def_part", "dim_def_part2", 
  "dim_var_def_list", "dim_var_def_name", "opt_at", "display_b_n_cmd", 
  "display_cmd", "display_form_cmd", "display_array_cmd", "@52", "@53", 
  "opt_scroll", "display_attr", "disp_rest", "disp_field_commands", 
  "disp_field_command", "@54", "@55", "@56", "alloc_arr_cmd", 
  "dealloc_arr_cmd", "resize_arr_cmd", "error_cmd", "exit_prog_cmd", 
  "ext_cmd", "continue_cmd", "fgl_expr_c", "fgl_next", 
  "op_fgl_expr_ret_list", "fgl_expr_ret", "fgl_expr_ret_list", 
  "fgl_expr_list", "fgl_expr_concat", "fgl_expr", "int_sign", 
  "boolean_expr", "initial_expr", "literal_expr", "variable_entry_2", 
  "variable_entry", "report_only_expr", "@57", "and_or_expr", 
  "inexpr_list", "in_expr", "null_expr", "string_match_expr", "clip_expr", 
  "using_expr", "math_expr", "comparison_expr", "reset_cnt", 
  "function_call_expr2", "@58", "@59", "@60", "@61", "function_callb", 
  "@62", "@63", "@64", "@65", "@66", "@67", "@68", "@69", "op_extend_d", 
  "op_extend_i", "function_call_expr", "builtin_expr", "builtin_funcs", 
  "pdf_expr", "interval_func_params", "numeric_time_interval", 
  "numeric_time_unit_small", "numeric_time_unit_big", 
  "field_name_list_as_struct", "field_name_list_or_char_as_struct", 
  "foreach_cmd", "@70", "@71", "@72", "opt_foreach_using_part", 
  "formhandler_def", "@73", "@74", "op_input_section", "op_bef_ev_list", 
  "bef_ev_list", "bef_ev", "@75", "@76", "op_aft_ev_list", "aft_ev_list", 
  "aft_ev", "@77", "@78", "input_section", "input_sub_section", 
  "in_variable_list", "in_id_list", "in_bn_variable_list", "field_ops", 
  "field_op", "@79", "@80", "@81", "@82", "@83", "for_cmd", "@84", "@85", 
  "for_step", "free_cmd", "line_no", "file_name", "a_number", "coords", 
  "display_coords", "field_name_as_struct", 
  "field_name_or_char_as_struct", "cursor_name", "fetch_cursor_name", 
  "win_name", "open_win_name", "form_name", "open_form_name", 
  "opt_help_no", "identifier", "ident_or_var", "ident_p2", 
  "var_or_string", "field_name2_as_struct", "cvariable", "real_number", 
  "goto_cmd", "label_goto", "check_menu_cmd", "menu_item_list", 
  "menu_item", "uncheck_menu_cmd", "disable_cmd", "enable_cmd", 
  "msg_box_cmd", "@86", "op_disable_msg", "gm_disable_msg", 
  "op_returning_msg", "gm_returning_msg", "op_caption", "gm_caption", 
  "op_icon", "gm_icon", "op_buttons", "gm_buttons", "op_def_but", 
  "if_cmd", "@87", "@88", "op_else", "@89", "@90", "@91", "import_m", 
  "module_import", "init_cmd", "@92", "init_tab_list", "init_tab", 
  "init_table_name", "end_input", "opt_defs", "field_commands", 
  "field_command", "@93", "@94", "@95", "@96", "@97", "@98", "@99", 
  "@100", "@101", "@102", "@103", "@104", "@105", 
  "bef_field_list_as_struct", "aft_field_list_as_struct", 
  "next_field_cmd", "next_form_cmd", "next_field", "input_cmd", "@106", 
  "inp_rest", "@107", "scroll_cmd", "up_or_down", "op_help", 
  "input_array_attributes", "input_array_attributes_int", 
  "on_key_command", "@108", "key_val", "@109", "accept_key", 
  "single_key_val", "key_do", "key_value_list", "key_value", 
  "key_value_1", "label_cmd", "let_cmd", "@110", "@111", "op_expr_null", 
  "linked_cmd", "linked_del_cmd", "linked_upd_cmd", "locate_cmd", 
  "module", "@112", "op_module_header", "module_header", "module_entry", 
  "func_main_def", "func_or_main2", "at_term_cmd", "func_or_main", 
  "module_code", "op_code", "module_define_section", "ldeffunction", 
  "func_def", "@113", "@114", "@115", "@116", "end_func_command", 
  "main_def", "@117", "@118", "return_cmd", "op_fgl_expr_list", 
  "db_section", "module_globals_section", "actual_globals_section", 
  "xglobals_entry", "globals_entry", "@119", "glob_section", 
  "mem_func_def", "@120", "@121", "@122", "menu_def", "@123", "@124", 
  "menu_handler_elements", "menu_handler_element", "@125", "@126", 
  "menu_cmd", "@127", "end_menu_command", "menu_block_command", "@128", 
  "@129", "@130", "menu_commands", "opt_key", "menu_opt_name", 
  "menu_optional_desc", "next_option_cmd", "show_option_cmd", 
  "hide_option_cmd", "opt_name", "opt_name_list", "menu_title", 
  "message_cmd", "msg_next", "gui_message", "msg_start", "op_msg_wait", 
  "msg_wait", "variable", "var_int", "varsetidentdot", "var", 
  "assoc_var_read", "assoc_var_write", "assoc_sub", "dot_part_var", 
  "array_r_variable", "arr_subscripts", "num_list", "num_list_element", 
  "let_variable", "let_var", "let_var_dot", "let_array_r_variable", 
  "op_param_var_list", "fparam_var_list", "ibind_var_list", 
  "func_def_var", "ibind_var", "obind_var_list", "obind_var", 
  "obind_var_let_list", "obind_let_var", "use_arr_var", 
  "obind_var_list_ord", "obind_var_ord", "optional_asc_desc", 
  "init_bind_var_list", "init_bind_var", "open_window_cmd", 
  "op_at_statusbox", "op_size_statusbox", "open_statusbox_cmd", 
  "formhandler_name", "open_form_cmd", "open_form_rest", "open_form_gui", 
  "op_at_gui", "op_like_gui", "op_absolute", "open_session_cmd", 
  "open_cursor_cmd", "user_details", "op_disable", "connect_cmd", 
  "op_connect_as", "con_user_details", "options_cmd", "opt_options", 
  "opt_allopts", "prepare_cmd", "var_or_char", "execute_cmd", "stmt_id", 
  "prompt_cmd", "@131", "opt_timeout", "gui_prompt_cmd", "opt_char", 
  "prompt_key_sec", "prompt_key_clause", "on_key_command_prompt", "@132", 
  "prompt_title", "put_cmd", "@133", "put_from", "put_val_list", 
  "put_val", "start_cmd", "op_convert", "rout", "rep_name", "op_values", 
  "output_cmd", "finish_cmd", "term_rep_cmd", "report_section", 
  "format_section", "format_actions", "format_action", "@134", "@135", 
  "@136", "@137", "@138", "@139", "@140", "report_cmd", "need_command", 
  "@141", "op_lines", "skip_command", "@142", "opt_rep_expr_list", 
  "xrep_expr_list", "xxrep_expr_list", "opt_print_at", "print_command", 
  "@143", "print_file_command", "print_img_command", "opt_scaling", 
  "img_types", "blob_var", "opt_semi", "rep_expr_list", "rep_expr", 
  "rep_agg", "op_output_section", "output_commands", "output_command", 
  "pdf_output_commands", "nval", "nval_number", "pdf_op_output_section", 
  "pdf_output_command", "op_rep_order_by", "report_def", "@144", "@145", 
  "@146", "@147", "@148", "@149", "rep_where", "pause_command", 
  "pause_msg", "pdf_report_def", "@150", "@151", "@152", "@153", "@154", 
  "@155", "pdf_report_section", "pdf_functions", "@156", "@157", "@158", 
  "op_wordwrap", "run_cmd", "drops_cmd", "drops_c", "create_cmd", 
  "create_c_2_ss", "@159", "@160", "@161", "@162", "opt_cr_table_extra", 
  "cr_table_extra", "cr_table_extra_entry", "space_name", 
  "op_cr_index_extra", "cr_index_extra", "cr_index_extra_entry", 
  "create_c_1", "op_no_log", "idx_column_list", "idx_column", 
  "table_element_list_ss", "table_element_ss", "upd_stats_cmd", 
  "alter_cmd", "alter_clauses_ss", "alter_clause_ss", 
  "alter_add_clause_ss", "add_column_clause_ss", "add_column_clauses_ss", 
  "alter_drop_clause", "drop_column_list", "drop_column", 
  "alter_modify_clause_ss", "modify_column_clauses_ss", 
  "modify_column_clause_ss", "alter_lock_mode", "alter_modify_next", 
  "alter_add_constraint_clause", "table_constraint_definition_list_ss", 
  "opt_constraint_name", "alter_drop_constraint_clause", 
  "constraint_names", "constraint_name", "set_cmd", "op_conn_id", 
  "op_fgl_expr", "sleep_cmd", "rollback_statement", "insert_statement_ss", 
  "@163", "ins_2_ss", "@164", "op_insert_column_list", 
  "insert_column_list", "insert_value_list_ss", "insert_value_ss", 
  "fetch_statement", "@165", "declare_cursor_name", "fetch_part", 
  "opt_into_fetch_part", "@166", "opt_foreach_into_fetch_part", "@167", 
  "fetch_place", "delete_statement_position", 
  "delete_statement_search_ss", "order_by_clause", 
  "sort_specification_list", "sort_specification", "sort_spec", 
  "op_asc_desc", "begin_statement", "commit_statement", "op_exclusive", 
  "set_database_cmd", "var_ident_qchar", "sql_cmd", "@168", 
  "sql_commands", "privilege_definition", "db_priv", 
  "op_with_grant_option", "privileges", "action_list", "action", 
  "op_grant_column_list", "grant_column_list", "grantee_list", "grantee", 
  "view_definition_ss", "op_view_column_list", "view_column_list", 
  "op_with_check_option", "check_constraint_definition_ss", 
  "referential_constraint_definition", "references_specification", 
  "references_columns", "referenced_table_and_columns", 
  "references_column_list", "unique_constraint_definition", 
  "unique_column_list", "table_constraint_definition_ss", 
  "default_clause", "ct_column_definiton_ss", "op_default_clause", 
  "op_column_constraint_list_ss", "column_constraint_list_ss", 
  "column_constraint_ss", "column_constraint_ss_1", "schema_ss", 
  "schema_authorization_clause", "schema_authorization_identifier", 
  "schema_element_list_ss", "schema_element_ss", "having_clause_ss", 
  "group_by_clause_ss", "column_specification_list_ss", "where_clause_ss", 
  "from_clause", "table_reference_list", "table_reference", "tname", 
  "tname_list", "table_expression_ss", "op_where_clause_ss", 
  "op_group_by_clause_ss", "op_having_clause_ss", "search_condition_ss", 
  "boolean_term_ss", "boolean_factor_ss", "boolean_primary_ss", 
  "exists_predicate_ss", "op_escape", "pattern_ss", "escape_character", 
  "in_predicate_ss", "in_value_list", "in_value_specification", "op_not", 
  "comparison_predicate_ss", "comp_op", "predicate_ss", "op_all", 
  "data_type", "char_string_type", "exact_numeric_type", "op_scale", 
  "approx_numeric_type", "length", "precision", "scale", "table_name", 
  "idx_name", "authorization_identifier", "col_arr", "column_name", 
  "column_name_specific", "correlation_name", "literal", "curr_v_clause", 
  "curr_clause", "cur_part", "cur_v_part", "s_curr_v", "e_curr_v", 
  "s_curr", "e_curr", "dbase_name", "flush_cmd", "declare_cmd", "@169", 
  "@170", "@171", "@172", "curs_forupdate", "cur_update_list", "colident", 
  "cursor_specification_all_ss", "cursor_specification_sel_ss", 
  "select_statement_full_ss", "select_statement_ss", "@173", "@174", 
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
  "units_qual", "extend_qual_ss", "datetime_value_qualified", 
  "datetime_value", "interval_value_qualified", "interval_value", 
  "sql_block_cmd", "@175", "sql_block", "sql_block_entry", "in_var", 
  "@176", "sql_block_into", "@177", "update_statement_ss", "@178", "@179", 
  "where_upd_ss", "set_clause_list_ss", "upd_columns_ss", 
  "upd_column_name", "col_1_ss", "upd_col_list", "upd_val_list_ss", 
  "upd_val_ss", "upd_value_expression_ss", 
  "upd_value_expression_initial_ss", "upd_value_expression_complex_ss", 
  "upd_var_ident_ibind_ss", "upd_value_expr_list_ss", "validate_cmd", 
  "@180", "validate_tab_list", "validate_tab", "var_ident", 
  "var2_as_string", "var2_vu", "var3_vu", "var4_vu", "var4_item_vu", 
  "var_ident_ibind_ss", "array_r_variable_or_ident_vu", 
  "arr_subscripts_al", "num_list_nl", "num_list_element_nl", 
  "whenever_cmd", "while_cmd", "@181", "@182", "op_clr_fields", 
  "op_to_defs", "clear_cmd", "current_win_cmd", "window_type", "show_cmd", 
  "op_mnfile", "menu_name", "menu_handler", "hide_cmd", "move_cmd", 
  "NAMED", "commands", "all_commands", "command1", "commands_all", "@183", 
  "commands_all1", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const unsigned short yytoknum[] =
{
       0,   256,  1708,  1709,  1710,  1615,  1655,  1610,  1547,  1630,
    1427,  1533,  1529,  1444,  1605,  1346,  1403,  1475,  1641,  1628,
    1534,  1561,  1629,  1410,  1711,  1712,  1713,  1714,  1715,  1716,
    1717,  1718,  1719,  1720,  1721,  1722,  1000,  1001,  1002,  1003,
    1004,  1005,  1006,  1007,  1008,  1009,  1010,  1011,  1012,  1013,
    1014,  1015,  1016,  1017,  1018,  1019,  1020,  1021,  1022,  1023,
    1024,  1025,  1026,  1027,  1028,  1029,  1030,  1031,  1032,  1033,
    1034,  1035,  1036,  1037,  1038,  1039,  1040,  1041,  1042,  1043,
    1044,  1045,  1046,  1047,  1048,  1049,  1050,  1051,  1052,  1053,
    1054,  1055,  1056,  1057,  1058,  1059,  1060,  1061,  1062,  1063,
    1064,  1065,  1066,  1067,  1068,  1069,  1070,  1071,  1072,  1073,
    1074,  1075,  1076,  1077,  1078,  1079,  1080,  1081,  1082,  1083,
    1084,  1085,  1086,  1087,  1088,  1089,  1090,  1091,  1092,  1093,
    1094,  1095,  1096,  1097,  1098,  1099,  1100,  1101,  1102,  1103,
    1104,  1105,  1106,  1107,  1108,  1109,  1110,  1111,  1112,  1113,
    1114,  1115,  1116,  1117,  1118,  1119,  1120,  1121,  1122,  1123,
    1124,  1125,  1126,  1127,  1128,  1129,  1130,  1131,  1132,  1133,
    1134,  1135,  1136,  1137,  1138,  1139,  1140,  1141,  1142,  1143,
    1144,  1145,  1146,  1147,  1148,  1149,  1150,  1151,  1152,  1153,
    1154,  1155,  1156,  1157,  1158,  1159,  1160,  1161,  1162,  1163,
    1164,  1165,  1166,  1167,  1168,  1169,  1170,  1171,  1172,  1173,
    1174,  1175,  1176,  1177,  1178,  1179,  1180,  1181,  1182,  1183,
    1184,  1185,  1186,  1187,  1188,  1189,  1190,  1191,  1192,  1193,
    1194,  1195,  1196,  1197,  1198,  1199,  1200,  1201,  1202,  1203,
    1204,  1205,  1206,  1207,  1208,  1209,  1210,  1211,  1212,  1213,
    1214,  1215,  1216,  1217,  1218,  1219,  1220,  1221,  1222,  1223,
    1224,  1225,  1226,  1227,  1228,  1229,  1230,  1231,  1232,  1233,
    1234,  1235,  1236,  1237,  1238,  1239,  1240,  1241,  1242,  1243,
    1244,  1245,  1246,  1247,  1248,  1249,  1250,  1251,  1252,  1253,
    1254,  1255,  1256,  1257,  1258,  1259,  1260,  1261,  1262,  1263,
    1264,  1265,  1266,  1267,  1268,  1269,  1270,  1271,  1272,  1273,
    1274,  1275,  1276,  1277,  1278,  1279,  1280,  1281,  1282,  1283,
    1284,  1285,  1286,  1287,  1288,  1289,  1290,  1291,  1292,  1293,
    1294,  1295,  1296,  1297,  1298,  1299,  1300,  1301,  1302,  1303,
    1304,  1305,  1306,  1307,  1308,  1309,  1310,  1311,  1312,  1313,
    1314,  1315,  1316,  1317,  1318,  1319,  1320,  1321,  1322,  1323,
    1324,  1325,  1326,  1327,  1328,  1329,  1330,  1331,  1332,  1333,
    1334,  1335,  1336,  1337,  1338,  1339,  1340,  1341,  1342,  1343,
    1344,  1345,  1347,  1348,  1349,  1350,  1351,  1352,  1353,  1354,
    1355,  1356,  1357,  1358,  1359,  1360,  1361,  1362,  1363,  1364,
    1365,  1366,  1367,  1368,  1369,  1370,  1371,  1372,  1373,  1374,
    1375,  1376,  1377,  1378,  1379,  1380,  1381,  1382,  1383,  1384,
    1385,  1386,  1387,  1388,  1389,  1390,  1391,  1392,  1393,  1394,
    1395,  1396,  1397,  1398,  1399,  1400,  1401,  1402,  1404,  1405,
    1406,  1407,  1408,  1409,  1411,  1412,  1413,  1414,  1415,  1416,
    1417,  1418,  1419,  1420,  1421,  1422,  1423,  1424,  1425,  1426,
    1428,  1429,  1430,  1431,  1432,  1433,  1434,  1435,  1436,  1437,
    1438,  1439,  1440,  1441,  1442,  1443,  1445,  1446,  1447,  1448,
    1449,  1450,  1451,  1452,  1453,  1454,  1455,  1456,  1457,  1458,
    1459,  1460,  1461,  1462,  1463,  1464,  1465,  1466,  1467,  1468,
    1469,  1470,  1471,  1472,  1473,  1474,  1476,  1477,  1478,  1479,
    1480,  1481,  1482,  1483,  1484,  1485,  1486,  1487,  1488,  1489,
    1490,  1491,  1492,  1493,  1494,  1495,  1496,  1497,  1498,  1499,
    1500,  1501,  1502,  1503,  1504,  1505,  1506,  1507,  1508,  1509,
    1510,  1511,  1512,  1513,  1514,  1515,  1516,  1517,  1518,  1519,
    1520,  1521,  1522,  1523,  1524,  1525,  1526,  1527,  1528,  1530,
    1531,  1532,  1535,  1536,  1537,  1538,  1539,  1540,  1541,  1542,
    1543,  1544,  1545,  1546,  1548,  1549,  1550,  1551,  1552,  1553,
    1554,  1555,  1556,  1557,  1558,  1559,  1560,  1562,  1563,  1564,
    1565,  1566,  1567,  1568,  1569,  1570,  1571,  1572,  1573,  1574,
    1575,  1576,  1577,  1578,  1579,  1580,  1581,  1582,  1583,  1584,
    1585,  1586,  1587,  1588,  1589,  1590,  1591,  1592,  1593,  1594,
    1595,  1596,  1597,  1598,  1599,  1600,  1601,  1602,  1603,  1604,
    1606,  1607,  1608,  1609,  1611,  1612,  1613,  1614,  1616,  1617,
    1618,  1619,  1620,  1621,  1622,  1623,  1624,  1625,  1626,  1627,
    1631,  1632,  1633,  1634,  1635,  1636,  1637,  1638,  1639,  1640,
    1642,  1643,  1644,  1645,  1646,  1647,  1648,  1649,  1650,  1651,
    1652,  1653,  1654,  1656,  1657,  1658,  1659,  1660,  1661,  1662,
    1663,  1664,  1665,  1666,  1667,  1668,  1669,  1670,  1671,  1672,
    1673,  1674,  1675,  1676,  1677,  1678,  1679,  1680,  1681,  1682,
    1683,  1684,  1685,  1686,  1687,  1688,  1689,  1690,  1691,  1692,
    1693,  1694,  1695,  1696,  1697,  1698,  1699,  1700,  1701,  1702,
    1703,  1704,  1705,  1706,  1707
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const unsigned short yyr1[] =
{
       0,   725,   726,   727,   728,   729,   730,   730,   731,   731,
     732,   733,   733,   733,   733,   733,   733,   734,   734,   734,
     734,   734,   735,   735,   736,   736,   738,   737,   737,   739,
     739,   740,   740,   740,   740,   740,   740,   740,   740,   740,
     740,   740,   740,   740,   740,   740,   740,   740,   741,   741,
     743,   742,   744,   744,   745,   745,   745,   745,   745,   745,
     745,   745,   745,   746,   747,   748,   747,   747,   747,   747,
     747,   749,   750,   747,   751,   752,   753,   747,   754,   755,
     747,   756,   757,   747,   758,   759,   760,   747,   761,   761,
     762,   762,   762,   763,   763,   764,   764,   765,   765,   766,
     766,   767,   767,   769,   768,   770,   768,   771,   771,   772,
     772,   773,   774,   775,   774,   776,   777,   776,   779,   778,
     781,   780,   782,   782,   782,   782,   782,   782,   783,   784,
     784,   785,   785,   786,   787,   787,   788,   790,   791,   789,
     792,   792,   793,   793,   794,   794,   795,   795,   795,   796,
     796,   798,   797,   799,   797,   800,   797,   801,   797,   802,
     797,   803,   803,   804,   804,   805,   805,   805,   805,   805,
     805,   806,   807,   807,   808,   808,   809,   809,   810,   810,
     812,   813,   811,   811,   814,   814,   816,   815,   817,   817,
     817,   817,   817,   818,   817,   819,   819,   819,   819,   820,
     821,   821,   822,   822,   823,   823,   823,   823,   825,   824,
     826,   824,   827,   824,   828,   828,   829,   829,   830,   831,
     831,   831,   832,   834,   833,   835,   833,   836,   833,   837,
     837,   838,   839,   840,   840,   842,   843,   841,   844,   844,
     844,   844,   844,   844,   844,   844,   844,   844,   844,   844,
     844,   844,   844,   844,   844,   844,   844,   844,   844,   845,
     844,   846,   844,   847,   844,   844,   844,   844,   844,   844,
     844,   844,   844,   844,   848,   848,   849,   850,   851,   852,
     852,   853,   855,   854,   856,   856,   856,   856,   856,   856,
     856,   858,   857,   859,   859,   860,   860,   861,   863,   862,
     864,   864,   864,   864,   864,   864,   864,   865,   866,   866,
     868,   867,   869,   869,   869,   869,   869,   869,   869,   869,
     869,   869,   869,   869,   869,   869,   869,   869,   869,   869,
     869,   869,   869,   869,   869,   870,   872,   871,   873,   871,
     875,   874,   876,   874,   877,   877,   878,   879,   879,   880,
     881,   881,   881,   881,   881,   881,   881,   881,   882,   883,
     884,   886,   887,   885,   888,   888,   889,   890,   890,   890,
     891,   891,   893,   892,   894,   892,   895,   892,   896,   897,
     898,   899,   899,   900,   900,   901,   901,   901,   901,   901,
     901,   901,   901,   901,   902,   902,   902,   902,   902,   902,
     902,   902,   903,   903,   903,   903,   903,   903,   903,   903,
     903,   903,   904,   904,   904,   904,   904,   904,   904,   904,
     904,   904,   904,   905,   905,   906,   906,   907,   907,   908,
     908,   909,   909,   910,   911,   911,   912,   912,   912,   912,
     912,   912,   913,   913,   914,   914,   914,   914,   915,   915,
     916,   917,   917,   917,   918,   917,   919,   919,   920,   920,
     921,   921,   921,   921,   922,   922,   923,   923,   923,   923,
     923,   923,   923,   923,   924,   925,   926,   926,   926,   926,
     926,   926,   927,   927,   927,   927,   927,   927,   927,   928,
     930,   931,   929,   932,   933,   929,   935,   936,   934,   937,
     938,   934,   939,   940,   934,   941,   942,   934,   934,   934,
     934,   934,   934,   934,   934,   934,   943,   943,   944,   945,
     945,   945,   945,   945,   945,   945,   945,   945,   946,   946,
     947,   947,   947,   947,   948,   948,   948,   949,   949,   950,
     950,   950,   951,   951,   951,   951,   951,   951,   951,   951,
     951,   951,   952,   952,   953,   953,   954,   954,   956,   957,
     958,   955,   959,   959,   961,   962,   960,   963,   963,   964,
     964,   965,   965,   967,   966,   968,   966,   969,   969,   970,
     970,   972,   971,   973,   971,   974,   975,   975,   975,   976,
     976,   977,   977,   978,   978,   979,   979,   981,   980,   982,
     980,   983,   980,   984,   980,   985,   980,   987,   988,   986,
     989,   989,   990,   991,   991,   991,   991,   991,   991,   991,
     992,   992,   993,   994,   995,   996,   996,   996,   996,   996,
     996,   996,   996,   997,   997,   998,   999,  1000,  1001,  1002,
    1003,  1004,  1004,  1005,  1006,  1007,  1007,  1008,  1008,  1009,
    1009,  1009,  1009,  1009,  1009,  1010,  1011,  1011,  1012,  1013,
    1013,  1014,  1015,  1015,  1016,  1017,  1018,  1018,  1018,  1019,
    1019,  1019,  1021,  1020,  1022,  1022,  1023,  1023,  1024,  1024,
    1025,  1026,  1026,  1027,  1028,  1028,  1029,  1030,  1030,  1031,
    1032,  1032,  1034,  1035,  1033,  1036,  1037,  1036,  1038,  1039,
    1036,  1040,  1040,  1041,  1043,  1042,  1042,  1044,  1044,  1045,
    1045,  1046,  1047,  1047,  1047,  1048,  1048,  1049,  1049,  1051,
    1050,  1052,  1050,  1053,  1050,  1054,  1050,  1055,  1050,  1056,
    1050,  1057,  1050,  1058,  1050,  1059,  1050,  1060,  1050,  1061,
    1050,  1062,  1050,  1063,  1050,  1064,  1064,  1065,  1065,  1066,
    1067,  1068,  1068,  1068,  1070,  1069,  1071,  1071,  1072,  1071,
    1073,  1074,  1074,  1074,  1074,  1074,  1074,  1075,  1075,  1076,
    1077,  1077,  1077,  1077,  1077,  1077,  1077,  1077,  1077,  1079,
    1078,  1078,  1081,  1080,  1082,  1083,  1084,  1084,  1085,  1085,
    1086,  1087,  1087,  1087,  1087,  1087,  1087,  1087,  1087,  1087,
    1087,  1087,  1087,  1087,  1087,  1087,  1087,  1087,  1087,  1088,
    1090,  1091,  1089,  1092,  1092,  1093,  1094,  1095,  1096,  1096,
    1098,  1097,  1099,  1099,  1100,  1100,  1101,  1101,  1101,  1101,
    1101,  1101,  1102,  1102,  1103,  1103,  1104,  1105,  1105,  1105,
    1105,  1105,  1105,  1105,  1105,  1105,  1105,  1106,  1107,  1107,
    1108,  1109,  1109,  1111,  1112,  1113,  1114,  1110,  1115,  1117,
    1118,  1116,  1119,  1120,  1120,  1121,  1121,  1122,  1123,  1123,
    1124,  1126,  1125,  1127,  1127,  1127,  1127,  1129,  1130,  1131,
    1128,  1133,  1134,  1132,  1135,  1135,  1137,  1136,  1138,  1136,
    1140,  1139,  1141,  1143,  1142,  1144,  1142,  1145,  1142,  1146,
    1146,  1147,  1147,  1148,  1148,  1149,  1149,  1149,  1150,  1151,
    1152,  1153,  1153,  1153,  1154,  1154,  1155,  1155,  1156,  1157,
    1157,  1157,  1157,  1158,  1158,  1158,  1158,  1158,  1159,  1160,
    1160,  1161,  1162,  1163,  1163,  1164,  1165,  1165,  1165,  1165,
    1165,  1165,  1166,  1167,  1168,  1168,  1169,  1169,  1170,  1171,
    1171,  1172,  1172,  1173,  1174,  1175,  1175,  1175,  1175,  1175,
    1175,  1176,  1176,  1177,  1178,  1178,  1179,  1179,  1180,  1180,
    1181,  1181,  1182,  1182,  1182,  1182,  1182,  1183,  1183,  1184,
    1184,  1185,  1185,  1186,  1187,  1188,  1188,  1189,  1190,  1190,
    1190,  1191,  1191,  1192,  1192,  1193,  1194,  1194,  1195,  1195,
    1196,  1197,  1198,  1199,  1199,  1200,  1201,  1201,  1202,  1202,
    1203,  1203,  1204,  1205,  1205,  1206,  1206,  1206,  1206,  1207,
    1207,  1207,  1208,  1209,  1209,  1210,  1210,  1210,  1211,  1212,
    1212,  1213,  1213,  1213,  1213,  1213,  1213,  1213,  1213,  1213,
    1213,  1213,  1213,  1213,  1213,  1213,  1213,  1213,  1213,  1213,
    1213,  1213,  1213,  1213,  1213,  1213,  1213,  1214,  1215,  1215,
    1216,  1216,  1216,  1216,  1216,  1217,  1219,  1218,  1220,  1220,
    1221,  1222,  1222,  1223,  1223,  1224,  1224,  1226,  1225,  1227,
    1229,  1228,  1230,  1230,  1231,  1231,  1232,  1232,  1233,  1233,
    1233,  1233,  1234,  1234,  1235,  1235,  1236,  1237,  1237,  1238,
    1239,  1240,  1241,  1242,  1242,  1243,  1243,  1245,  1244,  1246,
    1244,  1247,  1244,  1248,  1244,  1249,  1244,  1250,  1244,  1251,
    1244,  1252,  1252,  1252,  1252,  1252,  1252,  1254,  1253,  1255,
    1255,  1257,  1256,  1256,  1256,  1256,  1256,  1258,  1258,  1259,
    1259,  1260,  1261,  1261,  1263,  1262,  1264,  1265,  1266,  1266,
    1266,  1267,  1267,  1267,  1267,  1268,  1269,  1269,  1270,  1270,
    1271,  1272,  1272,  1272,  1272,  1272,  1272,  1272,  1272,  1273,
    1273,  1274,  1274,  1275,  1275,  1275,  1275,  1275,  1275,  1275,
    1275,  1275,  1275,  1276,  1276,  1277,  1277,  1277,  1277,  1278,
    1278,  1279,  1279,  1280,  1280,  1280,  1280,  1280,  1280,  1280,
    1280,  1280,  1280,  1280,  1280,  1280,  1280,  1280,  1280,  1280,
    1280,  1280,  1280,  1280,  1280,  1280,  1280,  1281,  1281,  1281,
    1283,  1284,  1285,  1286,  1287,  1288,  1282,  1289,  1289,  1290,
    1291,  1291,  1293,  1294,  1295,  1296,  1297,  1298,  1292,  1299,
    1301,  1302,  1303,  1300,  1304,  1304,  1304,  1304,  1305,  1305,
    1305,  1305,  1305,  1306,  1307,  1307,  1307,  1307,  1308,  1308,
    1310,  1311,  1309,  1312,  1313,  1309,  1314,  1314,  1315,  1315,
    1316,  1316,  1316,  1316,  1316,  1317,  1318,  1318,  1319,  1319,
    1320,  1320,  1321,  1321,  1321,  1321,  1321,  1322,  1322,  1323,
    1323,  1324,  1324,  1324,  1325,  1325,  1326,  1326,  1327,  1327,
    1328,  1328,  1328,  1329,  1329,  1330,  1330,  1330,  1330,  1330,
    1330,  1330,  1331,  1331,  1332,  1332,  1333,  1333,  1334,  1334,
    1335,  1335,  1336,  1337,  1337,  1338,  1338,  1339,  1340,  1340,
    1341,  1342,  1342,  1343,  1343,  1344,  1344,  1345,  1345,  1346,
    1346,  1347,  1348,  1348,  1348,  1348,  1348,  1348,  1348,  1348,
    1348,  1348,  1348,  1349,  1349,  1350,  1350,  1351,  1352,  1354,
    1353,  1356,  1355,  1355,  1357,  1357,  1358,  1358,  1359,  1359,
    1360,  1360,  1362,  1361,  1363,  1364,  1364,  1365,  1366,  1365,
    1367,  1368,  1367,  1369,  1369,  1369,  1369,  1369,  1369,  1369,
    1369,  1370,  1371,  1372,  1373,  1373,  1374,  1375,  1375,  1376,
    1376,  1376,  1377,  1378,  1379,  1379,  1380,  1381,  1381,  1381,
    1383,  1382,  1384,  1384,  1384,  1384,  1384,  1384,  1384,  1384,
    1384,  1384,  1384,  1384,  1385,  1385,  1385,  1385,  1386,  1386,
    1386,  1387,  1387,  1387,  1388,  1388,  1388,  1389,  1389,  1390,
    1390,  1390,  1390,  1390,  1390,  1391,  1391,  1392,  1392,  1393,
    1393,  1394,  1394,  1395,  1396,  1396,  1397,  1397,  1398,  1398,
    1399,  1400,  1401,  1402,  1403,  1403,  1404,  1404,  1405,  1405,
    1405,  1406,  1406,  1407,  1407,  1407,  1408,  1408,  1408,  1408,
    1409,  1410,  1410,  1411,  1411,  1412,  1412,  1413,  1414,  1414,
    1414,  1414,  1414,  1414,  1414,  1415,  1416,  1417,  1418,  1418,
    1419,  1419,  1420,  1421,  1422,  1422,  1423,  1424,  1425,  1425,
    1426,  1426,  1426,  1427,  1427,  1428,  1428,  1429,  1430,  1430,
    1431,  1431,  1432,  1432,  1433,  1433,  1434,  1434,  1435,  1435,
    1436,  1436,  1437,  1437,  1438,  1438,  1439,  1440,  1441,  1441,
    1441,  1441,  1442,  1442,  1443,  1443,  1444,  1444,  1445,  1445,
    1445,  1445,  1445,  1445,  1445,  1445,  1445,  1446,  1446,  1446,
    1446,  1446,  1446,  1446,  1446,  1446,  1447,  1447,  1447,  1448,
    1448,  1448,  1448,  1449,  1449,  1449,  1450,  1450,  1451,  1451,
    1451,  1451,  1451,  1451,  1451,  1451,  1451,  1451,  1451,  1451,
    1451,  1451,  1451,  1451,  1451,  1451,  1451,  1451,  1451,  1451,
    1451,  1451,  1451,  1452,  1452,  1453,  1453,  1453,  1453,  1453,
    1454,  1455,  1456,  1457,  1457,  1457,  1457,  1457,  1457,  1457,
    1457,  1458,  1458,  1458,  1458,  1458,  1458,  1458,  1458,  1459,
    1460,  1460,  1460,  1461,  1461,  1462,  1462,  1462,  1463,  1464,
    1464,  1464,  1464,  1465,  1466,  1467,  1467,  1468,  1468,  1469,
    1469,  1469,  1469,  1469,  1469,  1469,  1469,  1470,  1470,  1470,
    1470,  1470,  1470,  1470,  1470,  1471,  1471,  1471,  1471,  1471,
    1471,  1471,  1472,  1472,  1472,  1472,  1472,  1472,  1472,  1472,
    1473,  1473,  1473,  1474,  1476,  1475,  1477,  1475,  1478,  1475,
    1479,  1475,  1480,  1480,  1480,  1481,  1481,  1482,  1482,  1482,
    1483,  1483,  1484,  1484,  1485,  1487,  1488,  1486,  1489,  1490,
    1490,  1491,  1492,  1492,  1492,  1492,  1492,  1493,  1494,  1494,
    1495,  1496,  1497,  1497,  1497,  1497,  1498,  1498,  1499,  1499,
    1499,  1500,  1501,  1501,  1501,  1502,  1502,  1502,  1502,  1502,
    1502,  1502,  1502,  1503,  1503,  1503,  1503,  1503,  1503,  1503,
    1503,  1503,  1503,  1503,  1503,  1503,  1503,  1503,  1503,  1503,
    1503,  1503,  1503,  1503,  1503,  1504,  1504,  1505,  1506,  1507,
    1507,  1508,  1508,  1509,  1509,  1510,  1510,  1511,  1511,  1512,
    1513,  1513,  1514,  1514,  1515,  1516,  1516,  1516,  1517,  1517,
    1518,  1519,  1520,  1521,  1522,  1522,  1523,  1523,  1523,  1523,
    1523,  1523,  1524,  1524,  1524,  1524,  1525,  1525,  1526,  1526,
    1526,  1526,  1526,  1526,  1526,  1526,  1527,  1527,  1527,  1528,
    1528,  1528,  1528,  1528,  1528,  1530,  1529,  1531,  1531,  1532,
    1532,  1532,  1532,  1532,  1532,  1532,  1532,  1532,  1532,  1532,
    1532,  1532,  1532,  1532,  1532,  1532,  1532,  1532,  1532,  1532,
    1532,  1532,  1532,  1532,  1532,  1532,  1532,  1532,  1532,  1532,
    1532,  1532,  1532,  1532,  1532,  1532,  1532,  1532,  1532,  1532,
    1532,  1532,  1532,  1532,  1532,  1532,  1532,  1532,  1532,  1532,
    1532,  1532,  1532,  1532,  1532,  1532,  1532,  1532,  1532,  1532,
    1532,  1532,  1532,  1532,  1532,  1532,  1532,  1532,  1532,  1532,
    1532,  1532,  1532,  1532,  1532,  1532,  1532,  1532,  1532,  1532,
    1532,  1532,  1532,  1532,  1532,  1532,  1532,  1532,  1532,  1532,
    1532,  1532,  1532,  1532,  1532,  1532,  1532,  1532,  1532,  1532,
    1532,  1532,  1532,  1532,  1532,  1532,  1532,  1532,  1532,  1532,
    1532,  1532,  1532,  1532,  1532,  1532,  1532,  1532,  1532,  1532,
    1532,  1532,  1532,  1532,  1532,  1532,  1532,  1532,  1532,  1532,
    1532,  1532,  1532,  1532,  1532,  1532,  1532,  1532,  1532,  1532,
    1532,  1532,  1532,  1532,  1532,  1532,  1532,  1532,  1532,  1532,
    1532,  1532,  1532,  1532,  1532,  1532,  1532,  1532,  1532,  1532,
    1532,  1532,  1532,  1532,  1532,  1532,  1532,  1532,  1532,  1532,
    1532,  1532,  1532,  1532,  1532,  1532,  1532,  1532,  1532,  1532,
    1532,  1532,  1532,  1532,  1532,  1532,  1532,  1532,  1532,  1532,
    1532,  1532,  1532,  1532,  1532,  1532,  1532,  1532,  1532,  1532,
    1532,  1532,  1532,  1532,  1532,  1532,  1532,  1532,  1532,  1532,
    1532,  1532,  1532,  1532,  1532,  1532,  1532,  1532,  1532,  1532,
    1532,  1532,  1532,  1532,  1532,  1532,  1532,  1532,  1532,  1532,
    1532,  1532,  1532,  1532,  1532,  1532,  1532,  1532,  1532,  1532,
    1532,  1532,  1532,  1532,  1532,  1532,  1532,  1532,  1532,  1532,
    1532,  1532,  1532,  1532,  1532,  1532,  1532,  1532,  1532,  1532,
    1532,  1532,  1532,  1532,  1532,  1532,  1532,  1532,  1532,  1532,
    1532,  1532,  1532,  1532,  1532,  1532,  1532,  1532,  1532,  1532,
    1532,  1532,  1532,  1532,  1532,  1532,  1532,  1532,  1532,  1532,
    1532,  1532,  1532,  1532,  1532,  1532,  1532,  1532,  1532,  1532,
    1532,  1532,  1532,  1532,  1532,  1532,  1532,  1532,  1532,  1532,
    1532,  1532,  1532,  1532,  1532,  1532,  1532,  1534,  1533,  1536,
    1535,  1538,  1539,  1537,  1540,  1540,  1540,  1541,  1541,  1541,
    1541,  1541,  1541,  1542,  1542,  1543,  1544,  1545,  1545,  1546,
    1546,  1547,  1547,  1548,  1548,  1548,  1549,  1549,  1549,  1549,
    1549,  1549,  1549,  1549,  1549,  1549,  1549,  1549,  1549,  1549,
    1550,  1550,  1550,  1550,  1550,  1550,  1550,  1550,  1550,  1550,
    1550,  1550,  1550,  1550,  1550,  1550,  1551,  1552,  1552,  1554,
    1553,  1555,  1555,  1556,  1556,  1557,  1558,  1559,  1559,  1560,
    1560,  1561,  1561,  1561,  1562,  1562,  1563,  1563,  1564,  1565,
    1565,  1566,  1566,  1567,  1568,  1570,  1571,  1569,  1572,  1572,
    1573,  1573,  1574,  1574,  1574,  1574,  1574,  1574,  1574,  1575,
    1575,  1576,  1576,  1577,  1577,  1578,  1578,  1579,  1580,  1581,
    1582,  1582,  1583,  1584,  1584,  1585,  1586,  1586,  1588,  1587,
    1589,  1589,  1589,  1589,  1589,  1589,  1589,  1589,  1589,  1589,
    1589,  1589,  1589,  1589,  1589,  1589,  1589,  1589,  1589,  1589,
    1589,  1589,  1589,  1589,  1589,  1589,  1589,  1589,  1589,  1589,
    1589,  1589,  1589,  1589,  1589,  1589,  1589,  1589,  1589,  1589,
    1589,  1589,  1589,  1589,  1589,  1589,  1589,  1589,  1589,  1589,
    1589,  1589,  1589,  1589,  1589,  1589,  1589,  1589,  1589,  1589,
    1589,  1589,  1589,  1589,  1589,  1589,  1589,  1589,  1589,  1589,
    1589,  1589,  1589,  1589,  1589,  1589,  1589,  1589,  1589,  1589,
    1589,  1589,  1589,  1589,  1589,  1589,  1589,  1589
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
       1,     1,     3,     0,     6,     0,     5,     1,     2,     1,
       2,     1,     0,     0,     3,     0,     0,     3,     0,     4,
       0,     4,     2,     2,     2,     1,     2,     2,     3,     1,
       1,     1,     2,     1,     1,     2,     1,     0,     0,     5,
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
       1,     1,     4,     4,     4,     6,     4,     6,     1,     2,
       1,     1,     1,     1,     4,     6,     1,     4,     6,     0,
       3,     0,     3,     0,     3,     1,     1,     1,     1,     1,
       2,     2,     1,     1,     0,     3,     4,     1,     1,     0,
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
       2,     4,     5,     1,     2,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     2,     1,     1,     1,
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
       5,     7,     7,     9,     4,     6,     0,     3,     1,     1,
       4,     4,     4,     4,     4,     4,     1,     1,     1,     1,
       4,     4,     2,     2,     2,     2,     2,     1,     1,     2,
       1,     1,     1,     2,     4,     6,     6,     3,     5,     5,
       3,     1,     1,     3,     1,     3,     1,     3,     0,     0,
       0,     9,     0,     3,     0,     0,    10,     0,     1,     0,
       1,     1,     2,     0,     3,     0,     3,     0,     1,     1,
       2,     0,     3,     0,     3,     3,     1,     4,     3,     1,
       3,     1,     3,     1,     3,     1,     2,     0,     3,     0,
       3,     0,     4,     0,     4,     0,     4,     0,     0,    11,
       0,     2,     2,     3,     1,     3,     1,     1,     1,     1,
       1,     1,     1,     3,     1,     1,     4,     6,     4,     3,
       6,     3,     6,     1,     1,     1,     1,     1,     1,     1,
       1,     0,     2,     1,     1,     1,     4,     1,     1,     1,
       4,     3,     6,     3,     6,     1,     1,     2,     2,     1,
       2,     2,     1,     3,     1,     2,     2,     2,     4,     2,
       2,     4,     0,     8,     0,     1,     1,     1,     0,     1,
       2,     0,     1,     2,     0,     1,     2,     0,     1,     3,
       0,     2,     0,     0,     8,     0,     0,     3,     0,     0,
       7,     5,     2,     2,     0,     5,     4,     1,     3,     3,
       3,     1,     0,     2,     1,     0,     1,     1,     2,     0,
       4,     0,     4,     0,     3,     0,     3,     0,     3,     0,
       3,     0,     3,     0,     3,     0,     3,     0,     3,     0,
       3,     0,     3,     0,     3,     1,     3,     1,     3,     2,
       4,     1,     1,     1,     0,     4,     5,     6,     0,    10,
       3,     2,     2,     1,     1,     2,     2,     0,     2,     1,
       2,     3,     3,     3,     3,     1,     1,     1,     1,     0,
       3,     1,     0,     3,     2,     2,     1,     3,     1,     3,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       0,     0,     7,     1,     1,     2,     2,     2,     3,     4,
       0,     3,     0,     1,     1,     2,     1,     1,     1,     1,
       1,     1,     0,     1,     1,     2,     2,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     0,     1,
       1,     1,     1,     0,     0,     0,     0,    13,     1,     0,
       0,     6,     2,     1,     2,     2,     2,     1,     1,     2,
       1,     0,     3,     2,     1,     1,     1,     0,     0,     0,
      14,     0,     0,     7,     1,     2,     0,     3,     0,     4,
       0,     5,     1,     0,     3,     0,     7,     0,     5,     1,
       2,     0,     1,     1,     1,     0,     1,     1,     2,     2,
       2,     1,     1,     1,     1,     3,     1,     1,     2,     0,
       2,     1,     1,     1,     1,     1,     1,     1,     3,     0,
       1,     1,     1,     1,     2,     2,     2,     5,     8,     1,
       1,     1,     4,     4,     1,     1,     1,     1,     2,     3,
       6,     1,     3,     1,     1,     1,     3,     6,     9,     1,
       1,     1,     1,     2,     0,     1,     1,     3,     1,     3,
       1,     3,     1,     3,     1,     1,     1,     1,     3,     1,
       3,     1,     3,     1,     1,     1,     3,     2,     0,     1,
       1,     1,     3,     1,     3,     7,     0,     7,     0,     6,
       3,     1,     3,     1,     2,     5,     0,     7,     0,     2,
       0,     1,     5,     2,     5,     0,     5,     6,     4,     0,
       1,     1,     5,     0,     2,     0,     5,     4,     2,     1,
       3,     2,     2,     2,     2,     2,     2,     1,     2,     2,
       2,     2,     2,     2,     2,     1,     1,     1,     1,     2,
       2,     1,     1,     1,     1,     1,     1,     5,     1,     1,
       2,     4,     4,     6,     2,     1,     0,    11,     0,     2,
       5,     0,     1,     0,     2,     1,     2,     0,     3,     1,
       0,     4,     0,     2,     1,     3,     1,     1,     4,     5,
       5,     3,     0,     1,     1,     1,     1,     0,     1,     7,
       2,     2,     2,     2,     2,     1,     2,     0,     3,     0,
       3,     0,     3,     0,     3,     0,     3,     0,     4,     0,
       4,     1,     1,     1,     1,     1,     1,     0,     4,     0,
       1,     0,     4,     1,     2,     2,     2,     0,     1,     1,
       2,     2,     0,     2,     0,     4,     3,     5,     0,     2,
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
       3,     3,     3,     1,     2,     2,     2,     2,     1,     1,
       0,     0,     8,     0,     0,     9,     0,     1,     1,     2,
       2,     2,     2,     1,     1,     1,     0,     1,     1,     2,
       2,     2,     8,     2,     2,     4,     2,     0,     1,     1,
       3,     2,     2,     1,     1,     3,     1,     1,     2,     1,
       3,     3,     3,     1,     3,     1,     1,     1,     1,     1,
       1,     1,     2,     4,     1,     3,     1,     3,     2,     4,
       1,     3,     1,     2,     4,     1,     3,     1,     1,     1,
       2,     3,     4,     2,     4,     0,     2,     2,     4,     1,
       3,     1,     1,     1,     2,     1,     1,     1,     1,     1,
       2,     6,     6,     0,     1,     0,     1,     2,     1,     0,
       5,     0,     5,     1,     0,     3,     1,     3,     1,     3,
       1,     1,     0,     4,     1,     2,     1,     0,     0,     3,
       0,     0,     3,     1,     1,     1,     1,     1,     1,     2,
       2,     4,     3,     3,     1,     3,     2,     1,     1,     0,
       1,     1,     1,     1,     0,     1,     3,     1,     3,     1,
       0,     3,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     7,     6,     4,     4,     1,     1,
       1,     0,     1,     2,     1,     1,     1,     1,     3,     2,
       1,     1,     2,     1,     1,     0,     3,     1,     3,     1,
       3,     1,     1,     6,     0,     3,     1,     3,     0,     1,
       4,     5,     2,     1,     1,     4,     1,     3,     4,     4,
       4,     1,     3,     1,     1,     1,     2,     1,     1,     1,
       4,     0,     1,     0,     1,     1,     2,     2,     1,     1,
       1,     1,     1,     4,     1,     3,     1,     1,     1,     2,
       1,     1,     2,     2,     1,     3,     2,     2,     1,     3,
       1,     2,     4,     1,     2,     1,     3,     4,     0,     1,
       0,     1,     0,     1,     1,     3,     1,     3,     1,     2,
       1,     3,     2,     2,     0,     2,     1,     1,     5,     3,
       5,     3,     1,     3,     1,     1,     0,     1,     3,     3,
       3,     6,     4,     4,     4,     4,     5,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     0,
       1,     1,     1,     1,     1,     1,     1,     4,     0,     1,
       4,     1,     5,     5,     1,     1,     1,     1,     1,     4,
       1,     4,     6,     4,     1,     4,     1,     7,     1,     1,
       1,     4,     6,     0,     2,     4,     1,     1,     1,     1,
       1,     1,     1,     3,     1,     1,     3,     5,     3,     5,
       7,     3,     1,     1,     3,     5,     3,     5,     7,     1,
       0,     3,     5,     1,     2,     2,     4,     3,     1,     1,
       1,     1,     1,     2,     2,     0,     3,     0,     3,     1,
       1,     1,     1,     1,     1,     1,     4,     1,     1,     1,
       1,     1,     1,     1,     4,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     4,
       1,     3,     1,     3,     0,     7,     0,     8,     0,     6,
       0,     8,     0,     1,     2,     1,     3,     1,     3,     5,
       1,     1,     1,     1,     1,     0,     0,     9,     5,     1,
       1,     6,     0,     3,     1,     3,     4,     1,     0,     2,
       4,     6,     0,     1,     1,     1,     1,     3,     1,     2,
       3,     1,     1,     2,     2,     1,     1,     1,     2,     2,
       2,     2,     4,     3,     2,     3,     3,     3,     1,     1,
       1,     1,     1,     1,     5,     5,     5,     5,     5,     4,
       4,     3,     4,     1,     1,     1,     3,     1,     5,     7,
       5,     0,     2,     1,     1,     0,     3,     1,     3,     1,
       1,     1,     0,     3,     1,     1,     1,     1,     4,     6,
       1,     1,     2,     3,     1,     1,     1,     1,     1,     1,
       1,     1,     5,     5,     4,     5,     1,     4,     4,     4,
       6,     6,     8,     8,    13,    11,     1,     7,     4,     4,
       4,     6,     6,     8,     8,     0,     4,     1,     2,     1,
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
       5,     7,     7,     9,     1,     1,     1,     1,     1,     1,
       3,     2,     3,     3,     3,     5,     5,     5,     5,     5,
       4,     4,     3,     4,     1,     1,     1,     1,     3,     0,
       5,     1,     3,     3,     3,     1,     1,     2,     1,     1,
       3,     1,     3,     3,     1,     1,     1,     3,     2,     3,
       6,     1,     3,     1,     1,     0,     0,     6,     0,     2,
       0,     1,     1,     2,     2,     1,     1,     4,     3,     1,
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
       1,     1,     1,     1,     1,     1,     1,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const unsigned short yydefact[] =
{
     822,     0,  2234,     0,     0,     0,   871,   180,     0,   847,
     850,   178,   183,   826,     0,   820,   823,   824,   827,   830,
     831,   829,   867,   868,   870,   828,   136,   133,     0,   129,
     131,   130,   134,  2262,   703,   643,   310,  1682,  1680,   865,
     176,   186,   866,   179,     1,   832,   825,   869,   128,   132,
     135,     0,     0,   620,     0,     0,   177,   874,   940,   621,
     875,   876,   872,   655,   932,     0,   933,   941,   939,   186,
     181,   199,     0,   184,   200,   235,     0,   852,  1232,     0,
       0,   851,  1220,   859,     0,     0,   844,   843,   845,   821,
     833,   834,   853,   837,   838,   839,   842,   840,   841,   846,
       0,  1681,   934,   873,     0,     0,   948,   946,   947,   936,
     935,   308,   186,  1156,   193,   187,   186,   192,   232,     0,
     702,     0,     0,     0,     0,   176,   564,   881,   835,     0,
     342,   328,   202,   314,   279,   298,   319,   321,   318,     0,
     340,     0,   327,   320,   324,   330,   329,   186,   331,   311,
     334,   312,   313,   945,   944,     0,    22,    23,    13,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   953,     0,
     527,   519,    16,   526,   940,    15,     0,   951,     0,   309,
       0,   185,  1157,   182,     0,   199,   201,   273,   204,   261,
     267,   268,   252,   225,   263,   202,   240,   241,     0,   227,
     279,   298,   250,   253,   248,     0,   223,     0,   259,   251,
     256,   266,   265,   186,   269,   186,   238,   239,   236,   272,
       0,     0,     0,     0,   860,   176,   176,     0,     0,   203,
       0,     0,   332,     0,     0,   333,     0,     0,     0,     0,
       0,     0,     0,   277,     0,   942,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   533,     0,
       0,     0,   656,   444,   446,  1227,     0,     0,     0,  1647,
       0,   438,     0,     0,     0,   437,     0,   454,   529,     0,
       0,     0,     0,     0,   532,     0,   403,   402,   409,   450,
     447,   404,   405,   407,   408,   445,   448,   453,   528,   499,
     496,   505,   502,     0,     0,    17,    18,    19,    20,    21,
       0,    14,   490,     0,     0,   949,     0,   188,   191,   189,
     190,     0,   196,   195,   194,   197,   205,   206,   207,   210,
     274,   186,   274,     0,     0,     0,     0,   186,   270,   271,
       0,     0,   186,     0,   274,     0,     0,   249,   233,  1233,
       0,     0,  1221,  2268,   565,   882,   854,     0,   214,   215,
       0,     0,   291,   293,   288,   289,   285,   287,   284,   286,
     283,     0,   293,   304,   305,   301,   303,   300,   302,   295,
       0,     0,     0,   344,     0,   347,   349,   222,     0,   221,
       0,   186,     0,     0,   554,   625,     0,     0,     0,     0,
       0,     0,     0,     0,   551,   537,   542,     0,   538,   541,
     540,   634,     0,   633,   556,     0,    11,   172,   436,   411,
     410,     0,  1162,     0,     0,   452,  1655,  1653,  1654,  1650,
    1652,  1649,  1651,  1643,     0,     0,     0,   451,     0,     0,
       0,     0,     0,     0,     0,   657,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   165,   166,   167,   168,   169,   170,   534,
     535,   536,   465,     0,     0,   464,   474,     0,     0,   415,
       0,     0,   416,   406,   412,   414,   417,   418,   419,   420,
     421,   413,   443,   442,     0,     0,     0,     0,     0,     0,
       0,    12,    93,     0,   952,     0,   937,   198,     0,     0,
     262,     0,   264,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   260,     0,   186,   234,   237,   964,   701,   877,
     964,     0,  2266,  2268,  1156,  1782,   848,     0,   964,     0,
       0,   315,   280,     0,     0,   290,   307,   281,   306,     0,
     299,     0,   322,     0,   316,     0,   341,     0,   346,   336,
       0,     0,   325,   278,   335,     0,     0,   525,     0,     0,
     522,   521,   524,   520,   531,   516,     0,   516,     0,   539,
       0,   543,     0,   298,     0,   523,   530,   282,     0,  1228,
    1722,     0,     0,     0,     0,     0,   439,     0,     0,   455,
       0,     0,     0,     0,   457,   456,   475,   466,   481,   484,
     485,   482,   488,   487,   486,   476,   477,   478,   479,   480,
     422,   467,   471,   489,   483,   470,   489,   449,   500,   497,
     506,   503,   514,     0,    98,   491,    94,    95,    97,   493,
       0,     0,   235,     0,     0,     0,   242,   243,     0,   246,
       0,     0,   254,     0,   244,   224,   208,     0,   257,   276,
     970,     0,   965,   966,   964,     0,   861,  2267,  2265,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  2249,     0,  1348,  1347,     0,  1349,
       0,   398,  1346,  1263,     0,     5,  1345,   399,   396,     0,
     401,   174,   489,  1133,     0,     0,  1355,   125,   395,   394,
       0,     0,   389,   489,     0,  1299,  2242,     0,   400,   361,
       0,     3,     2,     0,   397,  1260,     0,     0,   390,   387,
     383,     0,     0,     0,     0,  1353,  1343,   393,     0,     0,
       0,     0,     0,     0,     0,     0,  1342,     0,     0,     0,
     175,     0,   386,   385,     0,     0,  2246,  2245,     0,     0,
       0,   137,     0,   392,   391,     0,     0,   388,   489,     0,
       0,   489,     0,   558,     0,     0,     0,     0,     0,     0,
     489,   809,  1230,     0,     0,  1144,     0,  2235,     0,   105,
       0,     0,   890,     0,     0,     0,     0,   810,     0,     0,
    1825,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     672,     0,     0,  2270,  2271,  2272,  2273,  2274,  2275,  2276,
    2277,  2278,  2279,  2280,  2281,  2282,  2283,  2284,  2285,  2286,
    2287,  2288,  2289,  2290,  2291,  2292,  2293,  2294,  2295,  2296,
    2297,  2298,  2299,  2300,  2301,  2302,  2303,  2304,  2305,  2306,
    2307,  2308,  2309,  2310,  2311,  2312,  2313,  2314,  2315,  2316,
    2317,  2318,   919,  2319,  2320,  2321,  2322,  2323,  2324,  2325,
    2326,  2327,  2328,  2329,  2330,  2331,  2332,  2333,  2334,  2335,
    1124,  1126,  1121,  1123,  1122,  1125,  2336,  2337,  1253,  2338,
    1259,  1258,  2339,  2340,  2341,  2342,  2343,  2344,  2345,  2346,
    2347,  2348,  1410,  2349,  2350,  2351,  2352,  2353,  2354,  2355,
    2356,  2357,  2269,   849,   569,     0,   886,     0,   884,     0,
     343,   216,   217,     0,   292,   297,     0,     0,     0,     0,
     345,   348,     0,   220,     0,     0,   555,     0,   629,     0,
     631,   509,     0,     0,   510,     0,   553,     0,   550,   547,
     518,   508,   557,     0,   171,  1724,  1725,  1723,     0,   441,
    1227,     0,  1648,  1227,   440,  1227,  1227,  1227,  1227,  1227,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    93,   950,     0,   211,   275,
     226,     0,     0,   186,     0,     0,     0,     0,     0,  1234,
       0,     0,  1222,   380,   378,   379,  1257,  1059,  1058,  1064,
       0,  1622,  1623,     0,     0,  1283,   644,   645,  1284,  1614,
    1615,  1286,   836,  1096,  1101,  2244,   637,   124,  2257,     0,
       0,  1298,     7,     0,     6,     0,  2250,  1097,     0,  1190,
    1189,  1136,  1188,  1135,   433,  1356,  1344,     0,  1254,   862,
     423,  1784,  1350,   126,     0,  1100,   123,     0,   816,    24,
     639,   384,     0,   815,  1092,   817,     0,  1354,   912,   911,
     914,   910,   913,  2259,     0,   908,     0,   638,   996,   909,
    2253,     0,  2243,   122,  1256,   993,   704,   991,     0,   635,
    2238,   752,   751,   753,   749,     0,     0,  1255,  1006,   640,
    1409,     0,  2225,  1404,  1407,  2215,  2218,  2219,  2221,  2224,
       0,     0,     0,     0,  1065,  1060,     0,  1045,  1046,  1047,
    1048,  1054,  1056,  1055,  1053,  1052,     0,     0,     0,  1051,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1037,  1028,  1029,   979,     0,   977,  1079,
     431,    24,     0,  2240,   127,   636,     0,  1231,  1229,  1155,
       0,  1773,  1774,  1156,  1137,  1357,     0,     0,     0,     0,
       0,     0,     0,     0,    63,     0,   940,     0,    69,     0,
     103,   612,     0,   659,   658,     0,  1127,  1013,  1131,     0,
       0,  1080,  1248,     0,     0,  1134,   664,   661,   662,     0,
     666,   667,     0,   669,   670,     0,   665,   974,   976,     0,
       0,   975,   754,   972,   715,   968,   931,     0,     0,     0,
       0,   676,   677,     0,     0,   929,   926,   927,   923,   924,
     925,   918,   922,   921,     0,     0,     0,     0,     0,     0,
     573,   575,   567,   570,   571,   888,  2268,   883,   885,   855,
       0,   294,   296,   323,   317,     0,     0,   326,   626,   628,
       0,     0,     0,   516,   516,   544,     0,   291,     0,     0,
    1752,  1639,  1641,  1753,     0,     0,  1645,  1750,     0,     0,
    1749,     0,     0,     0,  1751,     0,     0,     0,     0,     0,
       0,     0,  2225,  1640,  1748,  1642,  1737,     0,  1726,  1728,
    1732,  1735,  1763,  1806,  1764,  1816,  2226,  2216,  1736,  1165,
    1656,  1164,  1163,  1166,  1168,  1167,  1161,   468,   469,   473,
     458,     0,   461,   472,     0,   460,   501,   498,   507,   504,
     515,   492,    96,   494,   938,     0,   247,   231,     0,   229,
     255,   245,   235,   258,   971,   176,   967,   878,   176,     0,
       0,     0,  1328,  1329,     0,     0,     0,  1300,  1303,  1305,
    1306,  1307,  1311,  1310,  1308,  1309,     0,     0,     0,  1301,
    1302,     0,     0,     0,     0,     0,     0,     0,     0,  1098,
       0,    24,  1185,  1187,  1186,     0,   426,   427,   424,   425,
     984,     0,     0,   366,    25,   360,     0,  1093,     0,  1092,
       0,  1091,     0,     0,     0,     0,     0,     0,  1000,  1783,
       0,     0,     0,     0,     0,     0,  2240,     0,     0,   138,
       0,     0,  1010,  1002,  1003,  1008,     0,     0,  2217,     0,
    2228,  1405,  1406,     0,     0,   928,   429,  2209,  1023,   350,
       0,     0,   559,   617,   616,   614,   619,  1031,   618,  1036,
    1032,  1035,   808,   800,   794,   806,   807,   792,   793,   801,
     796,   802,   795,   805,   799,   803,   798,   804,   791,   797,
     784,   790,  1033,  1034,     0,  1041,  1049,  1038,  1039,  1043,
    1044,  1042,  1040,  1050,     0,     0,     0,   818,     0,     0,
       0,     0,     0,   764,   763,   760,  2241,  2248,    24,  1151,
    1152,  1153,  1154,  1148,  1146,  1244,  1156,  1138,  1139,  1142,
    1158,  2236,     0,     0,     0,     0,    99,     0,   100,     0,
       0,     0,    74,     0,     0,     0,   112,   107,     0,   660,
     917,     0,   916,     0,   489,  1129,     0,   959,   960,   983,
     954,   955,   811,   981,  1082,  1250,     0,  1252,  1251,  1881,
    1997,  1993,  1999,  2031,  2011,  2002,  1961,  1923,  2050,  2017,
    2025,  1914,  2020,  1882,  1829,  2012,  1919,  1970,  2104,  1949,
    1937,  1950,  2048,  2051,  2019,  1973,  2054,  1841,  2111,  2047,
    2075,  1852,  2147,  1938,  2120,  1834,  2080,  1850,  1909,  1956,
    1976,  2070,  2098,  2103,  1833,  2028,  2056,  1845,  1847,  1870,
    1887,  1907,  1917,  1927,  1980,  1983,  2041,  2052,  2058,  2059,
    2076,  2121,  2132,  1832,  1863,  1886,  1885,  1893,  1895,  1903,
    1913,  1934,  1952,  1955,  1981,  1989,  2045,  2055,  2065,  2071,
    2072,  2074,  2099,  2129,  2140,  1853,  1856,  1867,  1873,  1875,
    1880,  1884,  1890,  1898,  1900,  1901,  1902,  1912,  1922,  1929,
    1945,  1946,  1957,  1975,  1979,  1992,  2008,  2039,  2049,  2053,
    2060,  2068,  2077,  2087,  2091,  2108,  2114,  2118,  2126,  2131,
    2134,  1876,  1994,  2036,  1861,  1862,  1879,  1883,  1889,  1891,
    1905,  1906,  1916,  1925,  1930,  1932,  1933,  1939,  1947,  1964,
    1965,  1978,  2006,  2010,  2013,  2018,  2022,  2030,  2037,  2038,
    2043,  2061,  2062,  2067,  2073,  2078,  2084,  2085,  2086,  2088,
    2090,  2092,  2101,  2123,  2124,  2125,  2130,  2146,  1836,  1988,
    1996,  1998,  2094,  1838,  1842,  1846,  1851,  1857,  1858,  1871,
    1872,  1874,  1877,  1888,  1904,  1924,  1926,  1936,  1940,  1942,
    1943,  1951,  1960,  1962,  1963,  1974,  1987,  2005,  2023,  2024,
    2040,  2042,  2046,  2057,  2079,  2089,  2097,  2119,  2122,  2136,
    2137,  2138,  1869,  1839,  1859,  1860,  1866,  1935,  1868,  1892,
    1894,  1908,  1985,  2109,  1918,  1920,  1928,  1931,  1953,  1954,
    1959,  1966,  1967,  1968,  2149,  2000,  2001,  2004,  2009,  2014,
    2021,  2026,  2027,  2029,  2035,  2064,  2066,  2082,  2093,  2095,
    2096,  2100,  2105,  2106,  2110,  2112,  2113,  2128,  2133,  2135,
    2139,  2141,  2145,  1995,  2144,  1835,  1837,  1840,  1844,  1854,
    1878,  1896,  1897,  1899,  1910,  1941,  1944,  1984,  1990,  2003,
    2007,  2142,  2143,  2044,  2063,  2069,  2081,  2083,  2102,  2107,
    2117,  2127,  1849,  1843,  1848,  1865,  1915,  1958,  1971,  1972,
    2032,  2034,  2116,  1991,  1948,  2015,  1864,  1911,  1921,  1986,
    1969,  2016,  1855,  1977,  1982,  2115,  2033,     0,  1827,  1830,
    1831,   692,     0,     0,     0,   681,   715,   715,   712,     0,
       0,   716,     0,    26,   680,   683,     0,   690,   686,   930,
     920,  1780,  1781,  1771,  1771,  1374,     0,     0,  1683,     0,
       0,  1358,     0,     0,  1359,  1402,     0,     0,  1403,     0,
       0,  1722,     0,  1372,     0,  1421,  1420,  1419,  1417,  1418,
    1416,  1414,  1411,  1501,  1500,  1412,  1413,  1422,  1704,  1415,
    1787,  1786,  1785,  1423,  2268,  2268,   586,   577,   568,     0,
     572,  2268,   887,   176,     0,   337,   219,     0,     0,  1663,
    1661,  1662,  1658,  1660,  1657,  1659,   517,     0,   512,   511,
       0,   549,   548,   173,  1734,  1733,     0,     0,  1671,  1669,
    1670,  1666,  1668,  1665,  1667,  1644,     0,  1722,     0,     0,
    1569,     0,     0,  1740,  1738,  1739,  1569,  1569,  1569,  1569,
    1741,     0,     0,     0,  1518,  1712,     0,  1729,     0,     0,
       0,     0,  1796,  1797,  1798,  1799,  1800,  1801,  1744,     0,
       0,     0,     0,   463,   462,     0,     0,   186,   228,   209,
    1235,   176,  1223,     0,     0,     0,     0,     0,     0,  1475,
    1474,  1473,  1335,     0,  1341,  1337,  1339,  1330,     0,  1578,
    1327,  1323,  1297,  1296,     0,  1322,  1318,     0,  1314,  1312,
       0,  1621,     0,  1624,  1626,   648,     0,   647,  1613,     0,
    1616,  1618,  2258,  2255,     0,     0,  1264,   489,   358,  1285,
       0,     0,  1261,  1015,  1094,  1095,  1092,  1088,  1092,     0,
     915,     0,     0,   622,     0,     0,     0,   994,   992,   706,
     707,     0,   711,     0,     0,  2239,  2247,   750,     0,   142,
       0,  1004,  1011,     0,     0,  1019,  2220,  2233,     0,  2231,
    1408,  2223,  2222,     0,     0,     0,  1025,   353,     0,     0,
       0,     0,    24,  1061,  1062,   562,     0,     0,     0,   785,
     786,  1030,   980,   978,   819,   432,     0,  1071,   761,   765,
     762,   766,   381,     0,  1156,  1245,  1160,  1145,  1140,     0,
       0,  1141,  2268,     0,     0,     0,     0,     0,     0,     0,
      64,    93,     0,     0,   118,   113,     0,   108,     0,   115,
     109,   901,   893,   899,     0,  1128,     0,  1130,  1132,     0,
       0,   963,     0,     0,     0,     0,  1081,  1249,     0,     0,
    1826,  1828,  2268,   663,   668,   671,   684,   682,   641,     0,
     739,   737,   735,   733,   743,   741,     0,     0,   731,   781,
     729,   714,   725,   723,   779,   755,     0,   717,   727,   973,
     969,     0,     0,     0,     0,   689,     0,     0,     0,     0,
       0,     0,     0,  1629,     0,  1496,  1497,  1792,  1454,  1518,
       0,     0,     0,  1790,     0,  1434,  1429,  1428,  1441,  1440,
    1445,  1445,  1443,  1444,  1435,  1430,     0,     0,  1436,  1437,
    1705,  2151,     0,     0,     0,   574,   576,     0,     0,   589,
     581,   583,     0,   578,   579,     0,     0,   597,   599,     0,
       0,   595,   889,   856,   218,     0,   630,   632,   627,     0,
     516,   546,   545,     0,     0,     0,     0,     0,     0,  1761,
    1645,     0,     0,  1736,  1571,  1572,  1570,     0,  1765,     0,
       0,     0,     0,     0,     0,     0,  1727,     0,  1507,  1508,
    1510,  1513,     0,  1519,  1520,     0,     0,  1569,  1714,  1708,
    1730,  1746,  1747,  1745,  1743,     0,     0,     0,  2227,   459,
     495,     0,   230,  1191,   879,  1169,     0,     0,     0,     0,
    1335,     0,     0,     0,  1331,     0,     0,     0,  1325,  1609,
    1607,  1576,  1588,  1590,  1594,  1596,  1587,  1581,  1586,  1600,
    1579,  1608,  1584,  1599,  1585,  1606,  1598,  1481,  1573,  1574,
    1575,     0,  1320,  1316,     0,     0,  1304,     0,     0,   646,
       0,     0,     0,  2254,     0,     4,     8,    10,     0,   489,
     428,     0,     0,     0,  1012,  1090,  1089,     0,     0,     0,
       0,     0,     0,     0,     0,   705,     0,     0,   159,   157,
       0,     0,   139,     0,   149,   155,   715,   144,   146,     0,
    1009,  1020,  1021,     0,     0,  2229,   430,     0,  2210,  2211,
    1024,     0,     0,  1022,   352,   357,   624,   351,     0,   354,
     359,     0,   489,  1380,   615,   613,     0,   788,  1070,  1072,
       0,   382,  1149,  1147,     0,  1159,  1143,     0,     0,  1240,
       0,     0,     0,   101,     0,     0,    75,    81,    71,  2268,
    2268,   111,   106,   120,   116,     0,   110,   782,   902,   641,
    2268,   892,   891,   900,  1014,     0,     0,   961,   962,   956,
     982,   489,  1087,  1083,  1084,  1086,  2148,  2150,   693,   687,
     685,     0,    24,     0,  2268,  2268,  2268,  2268,  2268,  2268,
     745,   719,   747,   721,  2268,  2268,  2268,  2268,     0,   713,
     718,  2268,   641,   777,   775,   778,   776,     0,     0,    46,
      44,    41,    35,    39,    43,    38,    31,    40,     0,    34,
      37,    32,    42,    33,    45,    36,     0,    29,    47,   769,
       0,   691,  1772,     0,  1770,  1722,  1768,  1709,  1710,  1702,
    1688,  1703,     0,     0,     0,  1057,  1495,  1498,     0,     0,
       0,  1392,  1364,  1795,  1794,  1793,     0,     0,     0,  1439,
    1442,     0,     0,     0,     0,     0,  1387,     0,  1386,     0,
    1388,  1383,  1384,  1385,  1376,  1377,     0,     0,     0,   588,
     593,     0,     0,  2268,  2268,   566,   580,   603,   591,   605,
    2268,  2268,   601,   585,   596,   848,   338,     0,   513,  1808,
       0,  1809,     0,  1819,     0,  1820,     0,  1678,  1676,  1677,
    1673,  1675,  1672,  1674,  1646,     0,     0,     0,     0,  1762,
       0,     0,     0,  1760,     0,     0,     0,     0,  1742,  1759,
       0,  1511,     0,  1638,  1514,     0,     0,     0,     0,  1506,
    1524,  1526,  1528,  1568,  1567,  1566,  1530,  1546,     0,  1521,
    1522,  1717,  1287,     0,     0,     0,  1807,     0,  1818,   212,
       0,  1217,  1236,   848,     0,  1224,  1217,     0,  1630,     0,
    1463,     0,  1466,  1633,     0,  1471,     0,     0,  1332,  1333,
       0,     0,  1336,  1338,  1340,     0,  1324,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1479,  1478,  1477,
       0,  1482,  1483,     0,  1319,     0,  1313,  1315,  1625,     0,
    1627,  1617,     0,  1619,  2256,  1293,     0,  1289,     0,     0,
    1294,   863,     0,     0,     0,     0,     0,  1351,  2261,  2260,
     623,     0,     0,    48,     0,   708,   710,   709,  1352,   715,
    2268,  2268,   151,   649,   161,   153,   163,   143,   150,  2268,
       0,     0,     0,     0,     0,  2232,     0,     0,     0,     0,
       0,     0,  1063,     0,  1381,   560,     0,   787,  1068,     0,
    1246,  1247,  2237,     0,    93,     0,    65,     0,     0,     0,
      78,     0,    93,    93,   119,   114,  2268,  2268,   104,     0,
     903,   897,   905,   904,   894,   610,   943,     0,     0,     0,
     695,   674,   688,   642,   756,     0,   740,   738,   736,   734,
     744,   742,     0,  2268,     0,  2268,   732,   730,   726,   724,
     780,   728,    24,   770,     0,     0,     0,    27,     0,  1775,
       0,  1689,     0,     0,  1701,  1684,  1700,  1499,     0,  1456,
       0,  1391,     0,     0,  1791,     0,  1788,     0,  1447,  1451,
    1427,  1449,  1452,     0,  1438,  1706,     0,     0,     0,     0,
       0,     0,  2152,  1390,  1389,  1378,  1373,  1375,  1426,     0,
       0,   590,   587,   582,   584,     0,  2268,  2268,   598,   600,
    2268,  2268,     0,  1664,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1758,  1766,  1754,  1755,  1756,  1757,
    1515,     0,  1509,  1529,  1533,     0,  1546,  1532,     0,     0,
    1547,  1562,  1559,  1560,  1557,  1565,  1564,  1558,  1561,     0,
       0,     0,     0,     0,  1563,     0,     0,     0,  1503,  1504,
    1731,     0,  1523,  1517,  1288,  1715,  1397,  1393,  1394,  1399,
    1398,  1713,  1287,     0,     0,  1215,  1216,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1214,     0,
       0,  1202,  1203,  1204,  1201,  1206,  1207,  1208,  1205,  1192,
    1183,     0,     0,  1239,     0,  2268,     0,  1178,     0,     0,
       0,     0,     0,     0,     0,  1170,  1171,     0,  1102,  1634,
       0,  1635,     0,     0,     0,     0,  1470,  1469,  1335,  1468,
    1460,  1326,  1610,     0,     0,     0,     0,     0,     0,  1611,
    1603,     0,     0,     0,  1603,  1639,  1476,  1489,  1494,     0,
    1491,  1488,  1490,     0,  1492,  1480,  1484,  1485,  1335,  1321,
    1317,     0,     0,  1292,  1291,     0,  1276,     9,     0,  1266,
     864,  1099,   364,  1266,     0,     0,  2252,     0,     0,   995,
      49,     0,   767,   160,   158,     0,  2268,     0,     0,     0,
    2268,   156,   145,     0,   148,   147,     0,  1001,  1005,     0,
    2214,  2213,  2212,     0,     0,   356,     0,   563,     0,  2268,
     789,     0,   641,  1150,     0,  1241,    70,     0,     0,   102,
      68,    93,    76,    82,     0,   121,   117,   783,  2268,   907,
     641,   906,     0,   607,     0,   813,   814,   812,  1085,   698,
     696,     0,   678,   675,     0,   746,   720,   748,   722,   757,
     773,   774,   771,   772,    30,    28,     0,  1769,  1718,  1690,
    1686,  1685,     0,  1455,  1722,  1458,     0,  1366,  1361,  1360,
    1363,     0,     0,  1446,     0,     0,  1718,     0,     0,  2189,
    2187,     0,     0,  2171,  2186,     0,     0,  2188,     0,     0,
       0,     0,     0,  2225,  2185,  2177,  2204,  2205,     0,  2169,
    2172,  2173,  2184,  2176,  2206,     0,  2162,  2161,  2165,  2167,
       0,  2160,     0,  2163,  2154,     0,     0,   594,   592,   604,
     606,   602,     0,     0,     0,  1810,  1811,     0,     0,  1821,
    1822,     0,     0,  1721,     0,  1646,     0,     0,     0,  1512,
    1531,  1525,  1527,  1534,  1536,  1534,     0,  1541,  1534,     0,
    1539,  1534,     0,  1549,  1548,     0,  1550,     0,  1502,     0,
    1401,  1400,  1396,  1716,     0,   235,  1209,  1210,  1211,  1213,
    1196,  1194,  1193,  1197,  1198,  1195,  1212,  1199,  1200,  1184,
     988,  1219,   985,     0,     0,  1237,     0,  1182,  1181,  1176,
    1174,  1173,  1177,  1175,  1179,  1180,  1172,  1225,     0,  1461,
    1467,  1637,  1630,  1472,  1334,  1577,  1589,     0,  1591,  1593,
       0,  1595,     0,     0,     0,  1601,  1580,  1605,     0,  1462,
    1464,     0,  1486,  1487,  1628,  1620,  1290,     0,     0,  1282,
    1277,  1278,  1295,     0,  1273,  1274,     0,     0,  1287,  1267,
    1268,     0,    24,  1262,     0,     0,  1018,     0,    50,   998,
       0,    24,   162,   152,     0,   651,   653,   164,   154,   767,
       0,  2230,  1027,     0,   355,  1382,     0,  1069,    24,     0,
       0,    66,     0,    79,    88,     0,    72,   898,   895,   611,
    2268,   957,     0,  2268,   694,   673,   679,   641,  1779,     0,
    1777,     0,     0,  1691,  1687,  1457,     0,  1459,  1453,     0,
    1365,     0,  1789,  1448,  1450,  1425,     0,  2175,  2174,     0,
       0,  1569,     0,  1569,  1569,  1569,  1569,  2178,     0,     0,
    2158,     0,     0,     0,     0,  2191,  2159,     0,     0,     0,
       0,     0,     0,  2153,  1379,  1431,   858,   857,   339,     0,
       0,     0,     0,  1679,  1802,  1805,  1803,  1516,     0,  1553,
    1555,     0,  1542,  1545,  1544,  1552,     0,  1554,  1534,     0,
    1505,  1395,  1817,   213,   990,   989,   987,     0,  1218,  1103,
    1107,  1109,     0,  1113,     0,  1111,  1115,  1104,  1105,     0,
     880,     0,     0,  1631,  1636,     0,     0,  1612,  1604,  1582,
       0,  1583,     0,     0,  1280,  1275,  1281,  1279,  1272,  1271,
    1270,  1265,  1269,   365,   362,     0,  1016,     0,     0,     0,
     997,   768,   140,   650,    24,  1007,  1026,   561,  1066,    67,
    1242,    84,     0,     0,    77,    88,    88,  2268,   608,     0,
       0,   697,   758,     0,  1776,  1719,  1712,     0,  1367,     0,
    1712,  2202,     0,     0,  2207,     0,     0,     0,     0,     0,
       0,     0,     0,  2170,  2193,  2194,  2192,  2190,  2168,     0,
    2164,  2166,  2155,  2156,  1432,     0,  1424,     0,  1812,  1813,
    1823,  1824,  1535,  1767,  1537,     0,  1540,  1538,  1556,     0,
     986,  2268,  2268,  1117,  2268,  1119,  2268,  2268,  1106,  1238,
    1226,     0,  1592,     0,  1602,     0,  1493,   367,  1017,  2251,
       0,     0,     0,     0,     0,     0,    55,     0,    54,     0,
      52,     0,     0,   141,  1073,    88,    93,    88,    89,    83,
      73,   896,     0,     0,   699,    24,  1778,  1711,  1720,  1371,
       0,  1368,  1370,  1692,  2203,     0,     0,  2201,     0,     0,
       0,     0,     0,  2179,  2200,     0,  1433,     0,  1543,  1551,
    1108,  1110,  2268,  1114,  2268,  1112,  1116,  1632,  1597,  1465,
     369,   374,   372,   363,     0,   370,   376,    57,    62,    59,
      61,    58,    60,    56,     0,    51,     0,   652,   654,  1077,
    1067,     0,  1075,  1243,    85,    80,   609,   958,  2268,   759,
       0,  1362,     0,  1693,  1707,  2199,  2208,  2195,  2196,  2197,
    2198,     0,  2180,     0,     0,     0,  1118,  1120,  2268,  2268,
     368,   371,  2268,    53,     0,  2268,  1074,  1076,     0,   695,
    1369,     0,  1697,  1694,  1695,     0,     0,  2157,  1815,     0,
     375,   373,   377,     0,  1078,    86,   700,     0,     0,     0,
    2182,     0,  2181,     0,   999,    90,     0,  1698,  1696,     0,
    1814,    92,     0,    87,     0,  2183,    91,  1699
};

/* YYDEFGOTO[NTERM-NUM]. */
static const short yydefgoto[] =
{
      -1,   823,   824,   825,   826,  1043,  2405,  2406,   178,   320,
     179,  1403,  1404,  2232,  2566,  3618,  3089,  3090,  3518,  3619,
    3620,   827,  1184,  3127,  2823,  3536,  2171,  2821,  3384,  3131,
    3532,  2822,  3385,  3626,  3728,  3755,  3534,  3763,   645,   646,
     647,  1527,  2482,   828,  1538,  1189,  1536,  2179,  2492,  2176,
    2490,  2495,  2827,  1537,  2489,  2180,  2826,   829,     9,    28,
      29,    30,    31,    32,   831,  1106,  2109,  1429,  2432,  2436,
    2437,  2433,  2434,  3096,  3100,  2789,  2781,  2780,  2782,  2785,
     492,   268,   598,   832,    55,    56,    11,    41,   113,    70,
      71,    72,    73,   194,   334,    74,    75,   240,   339,   226,
    1006,   518,  2984,   370,   933,  2295,   398,   399,   227,   352,
     341,   347,  1348,  1349,   117,   536,   118,   119,   358,   228,
     354,   340,   342,   520,   229,   254,   574,   242,   245,   243,
     244,   380,   552,   553,   555,   560,   936,   246,   247,   389,
     557,   190,    12,    51,   149,   150,   151,   942,  2922,   152,
     250,   238,   392,   393,   394,   395,  2132,   833,   834,   835,
     836,  1064,  3607,  3352,  1405,  3673,  3674,  3675,  3719,  3718,
    3722,   837,   838,   839,   840,   841,   842,   843,  1054,   493,
    1059,  1397,  1398,  1445,  1159,  1446,   295,   296,   297,   298,
     299,   300,   301,   450,   494,  1331,   495,   496,   497,   498,
     499,   500,   501,   983,   180,   512,   993,   995,  2025,   181,
     506,   989,   505,   988,   508,   991,   507,   990,   951,   961,
     302,   303,   183,   304,   417,   418,   419,   420,   403,   422,
     844,  1126,  2135,  3119,  2463,    87,   235,   546,  1947,  1252,
    1253,  1254,  1944,  1945,  2282,  2283,  2284,  2623,  2624,  1948,
    1949,  2278,  2627,  2619,  2290,  2291,  2630,  2631,  2920,  2916,
    2917,   845,  3390,  3632,  3143,   846,  1457,    57,  2094,  2095,
    2457,   404,   424,  1098,  1164,  1035,  1086,  1069,  1108,  2522,
     184,  1036,  1026,  2066,  2784,    59,   305,   847,  1194,   848,
    1207,  1208,   849,   850,   851,   852,  1215,  3152,  1236,  3395,
    1237,  2206,  1238,  2519,  1239,  2841,  1240,  2235,   853,  2202,
    2840,  3151,  3393,  3392,  3698,    88,    13,   854,  1423,  2099,
    2100,  2101,  2225,  1892,  2226,  2227,  2853,  2855,  2537,  2536,
    2541,  2535,  2534,  2527,  2526,  2525,  2524,  2529,  2528,  2531,
    2533,   855,   856,  1104,   857,  1888,  1222,  3635,   858,  1505,
    3361,  2568,  2569,  2228,  2538,  2498,  2829,  1153,  1485,  2139,
    2466,  2140,  1481,   859,   860,  1200,  2194,  3147,   861,   862,
     863,   864,    14,    45,    15,    16,    17,    89,    90,   865,
      91,    18,   924,    19,    92,    93,   129,   548,  1953,  2635,
    3447,    94,   125,   363,   866,  2762,    20,    21,    22,    23,
      24,    40,    62,    95,   674,  2031,  2703,    96,   236,   547,
     927,   928,  1256,  1951,   867,  1195,  2502,  2183,  2500,  3537,
    3138,  2184,  2499,  2832,  3140,   868,   869,   870,  1080,  1081,
    1541,   871,  1241,  1242,   872,  1900,  1243,   306,    64,    65,
      66,    67,  1548,   155,   109,    68,   106,   186,   187,  1549,
    1550,  2509,  1551,   671,   672,  1224,   673,  1225,  1157,  1158,
    1552,  1553,  1401,  3291,  3292,  3476,  1096,  1097,   873,  1418,
    3520,   874,  3108,   875,  1433,  1434,  1435,  2115,  2113,   876,
     877,  2414,  2443,   878,  2126,  2453,   879,  1154,  1155,   880,
    1019,   881,  2579,   882,  3624,  3122,   883,  2470,  3690,  3691,
    3692,  3725,  1161,   884,  1554,  2196,  2513,  2514,   885,  1411,
    2086,  1034,  1390,   886,   887,   888,  2705,  3295,  3487,  3488,
    3591,  3592,  3596,  3594,  3597,  3662,  3664,   889,   890,  1543,
    2188,   891,  1545,  1516,  1517,  1518,  2161,   892,  1174,   893,
     894,  2154,  1513,  1170,   193,  1519,  1520,   307,  2706,  3025,
    3026,  3009,  1051,  1052,  2701,  3010,  3013,    97,   124,   540,
    1358,  2355,  3027,  3491,   432,   895,  1168,    98,   121,   537,
    1355,  2353,  3014,  3489,  2702,  1188,  2814,  3380,  3625,  2156,
     896,   897,   898,   899,   900,  1067,  2412,  1045,  2408,  3348,
    3349,  3350,  3504,  3339,  3340,  3341,   901,  2975,  2756,  2757,
    2759,  2050,   902,   903,  1367,  1368,  1369,  2059,  2394,  1370,
    2391,  2056,  1371,  2367,  2051,  1372,  1373,  1374,  2359,  2364,
    1375,  2045,  2046,   904,  1076,  1056,   905,  1925,  1926,  2250,
    3179,  3411,  2883,  3176,  3640,  3641,  1927,  2272,  1906,  2615,
    2906,  3225,  2805,  3118,  2616,  1928,  1929,  2338,  2977,  2978,
    2979,  3272,  1930,  1931,  1442,   906,  1113,   907,  1249,  1932,
    1933,  2266,  3576,  2267,  2268,  2269,  2599,  2887,  2890,  2891,
    1934,  2589,  2878,  3408,  2039,  2040,  3064,  2709,  3329,  2710,
    2041,  2714,  2052,  2741,  2053,  2742,  3065,  3066,  3067,  3068,
    1935,  2244,  2245,  2586,  1936,  2972,  2689,  2968,  2333,  2004,
    2328,  2329,  2330,  2941,  2005,  2334,  2690,  2973,  2679,  2680,
    2681,  2682,  2683,  3459,  3253,  3582,  2684,  3461,  3462,  2966,
    2685,  2967,  2686,  2317,  2387,  2388,  2389,  3323,  2390,  3043,
    3050,  3498,  2711,  1023,  2892,  3031,  3218,  2713,  2674,  1304,
     308,  1305,  1985,   443,   952,  1966,  1986,  2654,    39,   908,
     909,  3171,  3404,  2871,  3403,  3704,  3733,  3734,  2875,  2580,
    1937,  2581,  2604,  3186,   601,  2576,  2577,  2339,  2692,  3402,
    3175,  1306,   968,  1307,  1308,  2969,  2687,  1310,  1311,  2319,
    3584,   910,   911,  2237,  2578,  3167,  3399,  3400,  1903,   912,
    1062,  1939,  1940,  2254,  2885,  1941,  1942,  2595,  2018,  2312,
    1312,  1313,  1314,  1315,   913,  1203,  1877,  1878,  1879,  2198,
    1880,  2199,  1943,  2605,  3224,  3443,  2902,  3221,  3222,  3223,
    3220,  3208,  3209,  3210,  3211,  3212,  3213,  3555,   914,  2124,
    2448,  2449,  1114,  1316,  1317,  1116,  1117,  1118,  1318,  1119,
    1440,  2118,  2119,    25,   916,  1176,  2162,  1426,  1507,   917,
     918,  2773,   919,  2403,  1039,  2073,   920,   921,    35,   541,
     542,   543,   544,   545,   922
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -2820
static const short yypact[] =
{
     814,  1114, -2820,   243,   243,  1230, -2820, -2820,  1230, -2820,
     -38, -2820, -2820, -2820,   305, -2820,   814, -2820, -2820, -2820,
   -2820, -2820,   -78, -2820, -2820, -2820, -2820, -2820,   419,   441,
   -2820,   496, -2820, -2820, -2820, -2820, -2820, -2820,  -248, -2820,
     873,   124, -2820, -2820, -2820,   383, -2820, -2820, -2820, -2820,
   -2820,   -22,   243, -2820,   243,   431,   -38, -2820,   863, -2820,
   -2820, -2820, -2820, -2820, -2820,  1171,   228, -2820, -2820, -2820,
     903,   613,   243, -2820, -2820,   938,   243, -2820, -2820,   243,
     243, -2820, -2820, -2820,   243,   243, -2820, -2820, -2820, -2820,
     383, -2820, -2820, -2820, -2820, -2820, -2820, -2820, -2820, -2820,
    5393, -2820,   228, -2820,  1003,  1531, -2820, -2820,   442, -2820,
   -2820,   949,   124,   399, -2820, -2820, -2820, -2820, -2820,  5741,
   -2820,   243,   595,   923,   243,   -38, -2820, -2820, -2820,   243,
   -2820, -2820,   722,   631,   645, -2820, -2820,   651, -2820,   669,
   -2820,   689, -2820, -2820,   679, -2820, -2820, -2820, -2820, -2820,
   -2820, -2820, -2820, -2820, -2820,   726, -2820, -2820, -2820,   736,
     741,   747,   752,   761,   784,   789,   807,   825,   834,  1531,
     840,  5355,   849,   886,   932,   952,   964,   975,  1811,  1228,
   -2820, -2820, -2820, -2820,   958, -2820,   197, -2820,  1531, -2820,
     207, -2820, -2820, -2820,   144, -2820, -2820, -2820,   770, -2820,
   -2820, -2820, -2820, -2820, -2820,   722,   983,   989,  1000, -2820,
     645, -2820, -2820,  1033, -2820,  1036, -2820,   878, -2820, -2820,
    1062, -2820, -2820, -2820, -2820, -2820, -2820, -2820, -2820, -2820,
    1073,  1376,   243,  1120, -2820,   -38,   -38,  1126,   243, -2820,
     -72,  1402, -2820,   897,   806, -2820,   901,   982,  1510,  1553,
     243,  1559,  1590, -2820,   967, -2820,    72,    72,    72,    72,
      72,  5355,  1324,  1499,    63,  5355,   971,  5355, -2820,  5355,
    5355,  5355, -2820, -2820, -2820,  1077,  1176,  1185,  5355,  1139,
    1201, -2820,  5355,  5355,  1207, -2820,  1210, -2820,   886,  1213,
    1216,  1218,  1236,  1632,  9173,   140, -2820, -2820, -2820, -2820,
   -2820, -2820, -2820, -2820, -2820, -2820,  1202, -2820, -2820, -2820,
   -2820, -2820, -2820,   874,   874, -2820, -2820, -2820, -2820, -2820,
    1531, -2820, -2820,   243,  1531,  1220,   260, -2820, -2820, -2820,
   -2820,  1697, -2820, -2820, -2820, -2820, -2820, -2820, -2820, -2820,
    1246, -2820,  1246,   -72,  1706,  1712,  1727, -2820, -2820, -2820,
    1730,  1739,   124,  1559,  1246,  1746,  1111, -2820,  1668, -2820,
    1338,  1308, -2820,  1377, -2820, -2820, -2820,  1125, -2820, -2820,
    1765,  1353, -2820,  1318, -2820, -2820, -2820, -2820, -2820, -2820,
   -2820,   982,  1318, -2820, -2820, -2820, -2820, -2820, -2820,  1319,
     212,   223,   166, -2820,  3394, -2820, -2820, -2820,  1334,  1794,
     231, -2820,  1331,   241, -2820,  -183,  1369,  1370,   386,   401,
    5251,  1379,    93,  1240, -2820, -2820,    94,  1382, -2820, -2820,
   -2820, -2820,   418, -2820, -2820,  8132, -2820,  4087,  3345,  2806,
    2806,  5355, -2820,  1306,  5355,  9173,  1355, -2820, -2820, -2820,
   -2820, -2820, -2820, -2820,  1168,  1824,  8191,  9173,  1306,  1827,
     424,  5355,  5355,  5355,  5355, -2820,  5355,  5355,  5355,  5355,
    5355,  5355,  5355,  5355,  5355,  5355,  5355,  5355,  5355,  5355,
    5355,  5355,  5355, -2820, -2820, -2820, -2820, -2820, -2820, -2820,
   -2820, -2820, -2820,  5355,  5355, -2820, -2820,  1358,  5355, -2820,
    5355,  1371, -2820, -2820, -2820, -2820, -2820, -2820, -2820, -2820,
   -2820, -2820, -2820, -2820,   874,  5355,  5355,  5355,  5355,  1406,
    1844,  1811,  4234,  1373, -2820,  1531,  1346, -2820,  1196,  1830,
   -2820,  1205, -2820,  1837,  1433,  1436,   430,  1574,   467,   470,
     296,  1409, -2820,   474, -2820, -2820, -2820,   243, -2820, -2820,
     243,  1473, -2820,  7370,   399,  7673,  1862,   411,   243,  1868,
     -37, -2820, -2820,   806,  1867, -2820, -2820, -2820, -2820,  1873,
   -2820,  1874, -2820,  1875, -2820,   243, -2820,   243, -2820, -2820,
    1559,  1876, -2820, -2820, -2820,   243,    72, -2820,  1531,    45,
   -2820, -2820, -2820, -2820, -2820,  1139,  1877,  1139,  1878, -2820,
    1882,  1257,  1310, -2820,    63, -2820, -2820, -2820,  1475,  9173,
     423,  1476,  8381,  1889,  1139,  1479, -2820,  1480,  1481, -2820,
    8402,  8441,  8628,  8705,  5289,  9243,  3345,  9349,  9511,  9546,
    9619,  9581,  4267,  4478,  9081,  2806,  2806,  3418,  3418,  3634,
    9173,  8937,  8976,  1306,  9173,  9011,  1306, -2820,  9173,  9173,
    9173,  9173, -2820,  1898, -2820, -2820,  1920, -2820,  9173, -2820,
     272,  1531, -2820,  1484,  1916,   -37, -2820, -2820,  1915, -2820,
    1463,  1918, -2820,  1921, -2820, -2820, -2820,  1923, -2820, -2820,
    1279,  1508,  1947, -2820,   243,  1511, -2820, -2820, -2820,   874,
     874,   874,   243,  1057,   243,  1269,   235,   235,  1387,   243,
     243,   235,   235,   243, -2820,  1269, -2820, -2820,   243, -2820,
     968, -2820, -2820, -2820,   235, -2820, -2820, -2820, -2820,   243,
   -2820, -2820, -2820, -2820,   162,   162,  5355, -2820, -2820, -2820,
    1387,  1387, -2820, -2820,   235, -2820, -2820,   235, -2820, -2820,
     243, -2820, -2820,   235, -2820, -2820,   874,   235, -2820, -2820,
    5355,   235,   874,   243,   874,   235, -2820, -2820,   213,   235,
     235,   213,   235,   243,   213,   235, -2820,   235,   235,   235,
   -2820,  1269, -2820, -2820,   874,   235, -2820, -2820,   235,    82,
     243, -2820,  1387, -2820, -2820,   235,  1074, -2820, -2820,   874,
    1284, -2820,   235, -2820,  1485,   874,  5355,    72,    72,   235,
   -2820, -2820,  1057,   874,  1091, -2820,  5355, -2820,   716,  5355,
     235,   107, -2820,  5355,   235,  1932,   874, -2820,   235,  5355,
   -2820,  5355,   162,   243,   235,   243,    72,   235,   243,    72,
   -2820,   243,   168, -2820, -2820, -2820, -2820, -2820, -2820, -2820,
   -2820, -2820, -2820, -2820, -2820, -2820, -2820, -2820, -2820, -2820,
   -2820, -2820, -2820, -2820, -2820, -2820, -2820, -2820, -2820, -2820,
   -2820, -2820, -2820, -2820, -2820, -2820, -2820, -2820, -2820, -2820,
   -2820, -2820, -2820, -2820, -2820, -2820, -2820, -2820, -2820, -2820,
   -2820, -2820,   208, -2820, -2820, -2820, -2820, -2820, -2820, -2820,
   -2820, -2820, -2820, -2820, -2820, -2820, -2820, -2820, -2820, -2820,
   -2820, -2820, -2820, -2820, -2820, -2820, -2820, -2820, -2820, -2820,
   -2820, -2820, -2820, -2820, -2820, -2820, -2820, -2820, -2820, -2820,
   -2820, -2820,  1029, -2820, -2820, -2820, -2820, -2820, -2820, -2820,
   -2820, -2820, -2820, -2820,   872,   243, -2820,   778, -2820,  1517,
   -2820, -2820, -2820,  1608, -2820, -2820,  1520,  1521,  1523,  1525,
   -2820, -2820,  1299,  1968,  1534,  1535, -2820,   382, -2820,  1501,
   -2820, -2820,  1309,   153, -2820,  1542, -2820,  1955, -2820,  1348,
   -2820, -2820, -2820,  1316, -2820, -2820, -2820, -2820, 10047, -2820,
    1077,  1550, -2820,  1077, -2820,  1077,  1077,  1077,  1077,  1077,
    1969,  1970,  1972,  5355,  1567,  1992,  5355,  1577,  1579,  1580,
    1582,  1583,  1584,  1585,  4234,  4234, -2820,   285, -2820, -2820,
   -2820,  1678,  1589, -2820,  1593,  1597,  1361,  1601,   243, -2820,
     243,  1605, -2820, -2820, -2820, -2820, -2820, -2820, -2820, -2820,
     291,  1367,   523,  1458,  1557, -2820, -2820, -2820, -2820,  1381,
     528, -2820, -2820, -2820, -2820, -2820, -2820, -2820, -2820,  2029,
    1366, -2820, -2820,  1575, -2820,  1387, -2820,  1526,   200, -2820,
   -2820, -2820,  1453, -2820,  9173, -2820, -2820,  1416, -2820, -2820,
    4693, -2820, -2820, -2820,   874, -2820, -2820,  1387, -2820,   -36,
   -2820, -2820,  1736, -2820,   157, -2820,  1552, -2820, -2820, -2820,
   -2820,  2057, -2820, -2820,   573, -2820,  1398, -2820,  1399,  2057,
   -2820,  1422, -2820, -2820, -2820,  1600,   122, -2820,  1558, -2820,
    1365, -2820, -2820, -2820, -2820,  1378,   775, -2820,  -313, -2820,
    1401,  1432,  1572,  1707,  1430, -2820, -2820,  1420, -2820, -2820,
    5355,   133,  1095,  5355, -2820,   115,   235, -2820, -2820, -2820,
   -2820, -2820, -2820, -2820, -2820, -2820,    59,    59,    59, -2820,
      59,   868,    59,    59,  1444,   -36,  1444,  1444,  1100,  1100,
    1444,  1444,   -36, -2820,  2085, -2820,  1622,   278, -2820,  2088,
   -2820,   -36,    79,    65, -2820, -2820,  5355, -2820, -2820, -2820,
    1155, -2820, -2820,   399,  5355, -2820,  5355,  1623,  1625,  1626,
    1630,  1539,  1631,  1091, -2820,  1715,   979,  1477, -2820,  1486,
   -2820, -2820,   243, -2820, -2820,  1124, -2820,  2107, -2820,  2109,
     243, -2820,   454,  6731,  1504, -2820, -2820,  2124, -2820,  1424,
    2124,  2126,  1427,  2124,  2126,  5355,  2124, -2820, -2820,   200,
     874, -2820, -2820,  1665,   261, -2820, -2820,  1656,   874,  5355,
    1659, -2820, -2820,  2113,  2115,  2030, -2820, -2820, -2820, -2820,
   -2820, -2820, -2820, -2820,  1137,  1137,   235,   235,   235,  2954,
   -2820, -2820,  2006,   872, -2820, -2820,   844, -2820, -2820, -2820,
    1640, -2820, -2820, -2820, -2820,  5393,  1559, -2820, -2820,  1482,
     243,  1175,  2122,  1139,  1139,  1513,  1576, -2820, 10223, 10223,
   -2820,  1401, -2820, -2820,  1672,  1679,  1222, -2820,  9692,  1680,
   -2820,  1684,  1686,  1688, -2820,  1688,  1688,  1691,  1705,  1709,
    1719,   243,  -186, -2820, -2820, -2820, -2820,   117, -2820,    64,
    2037, -2820, -2820,  1222, -2820,  1222,  1716, -2820, -2820, -2820,
   -2820, -2820, -2820, -2820, -2820, -2820, -2820, -2820, -2820, -2820,
    9173,   477, -2820, -2820,   478, -2820, -2820, -2820, -2820, -2820,
   -2820, -2820, -2820, -2820, -2820,  1687, -2820, -2820,   482, -2820,
   -2820, -2820, -2820, -2820, -2820,   -38, -2820, -2820,   -38,   929,
     128,  2160, -2820, -2820,   591,   181,   671,  2186, -2820, -2820,
   -2820, -2820, -2820, -2820, -2820, -2820,   243,  1592,   243, -2820,
   -2820,  1596,   243,  1599,   243,   243,  1387,  1556,  1721, -2820,
    1722,    97, -2820, -2820, -2820,  1387, -2820, -2820,  2197, -2820,
   -2820,  1530,  1725, -2820, -2820, -2820,  1095, -2820,  1149,  2162,
    1149, -2820,  1091,   213,  5355,  5355,  5355,  1728, -2820, -2820,
     874,   874,  1387,  1544,  1091,    72,  1503,    82,   874, -2820,
    1536,  5355,  1816, -2820, -2820,  1615,   243,  1401, -2820,  1531,
   -2820, -2820, -2820,   243,  1272,  2216, -2820, -2820,  1560,   149,
     200,   874, -2820, -2820,  2204,  2206, -2820, -2820, -2820, -2820,
   -2820, -2820, -2820, -2820, -2820, -2820, -2820, -2820, -2820, -2820,
   -2820, -2820, -2820, -2820, -2820, -2820, -2820, -2820, -2820, -2820,
   -2820, -2820, -2820, -2820,  2503, -2820, -2820, -2820, -2820, -2820,
   -2820, -2820, -2820, -2820,  1485,   874,   874, -2820,  1100,  5355,
      26,  1008,  1067, -2820, -2820, -2820, -2820, -2820,   130, -2820,
   -2820, -2820, -2820,  2020, -2820,  1793,   399,  5355, -2820,   100,
   -2820, -2820,   243,  2205,    72,    72, -2820,  1609, -2820,    63,
    1561,   874, -2820,   243,   243,  5355,   -84, -2820,  1610, -2820,
   -2820,   252, -2820,  1708, -2820,  1718,  5355,  1203, -2820, -2820,
    1570, -2820,  2245, -2820,  1657, -2820,   874, -2820, -2820, -2820,
   -2820, -2820, -2820, -2820, -2820, -2820, -2820, -2820, -2820, -2820,
   -2820, -2820, -2820, -2820, -2820, -2820, -2820, -2820, -2820, -2820,
   -2820, -2820, -2820, -2820, -2820, -2820, -2820, -2820, -2820, -2820,
   -2820, -2820, -2820, -2820, -2820, -2820, -2820, -2820, -2820, -2820,
   -2820, -2820, -2820, -2820, -2820, -2820, -2820, -2820, -2820, -2820,
   -2820, -2820, -2820, -2820, -2820, -2820, -2820, -2820, -2820, -2820,
   -2820, -2820, -2820, -2820, -2820, -2820, -2820, -2820, -2820, -2820,
   -2820, -2820, -2820, -2820, -2820, -2820, -2820, -2820, -2820, -2820,
   -2820, -2820, -2820, -2820, -2820, -2820, -2820, -2820, -2820, -2820,
   -2820, -2820, -2820, -2820, -2820, -2820, -2820, -2820, -2820, -2820,
   -2820, -2820, -2820, -2820, -2820, -2820, -2820, -2820, -2820, -2820,
   -2820, -2820, -2820, -2820, -2820, -2820, -2820, -2820, -2820, -2820,
   -2820, -2820, -2820, -2820, -2820, -2820, -2820, -2820, -2820, -2820,
   -2820, -2820, -2820, -2820, -2820, -2820, -2820, -2820, -2820, -2820,
   -2820, -2820, -2820, -2820, -2820, -2820, -2820, -2820, -2820, -2820,
   -2820, -2820, -2820, -2820, -2820, -2820, -2820, -2820, -2820, -2820,
   -2820, -2820, -2820, -2820, -2820, -2820, -2820, -2820, -2820, -2820,
   -2820, -2820, -2820, -2820, -2820, -2820, -2820, -2820, -2820, -2820,
   -2820, -2820, -2820, -2820, -2820, -2820, -2820, -2820, -2820, -2820,
   -2820, -2820, -2820, -2820, -2820, -2820, -2820, -2820, -2820, -2820,
   -2820, -2820, -2820, -2820, -2820, -2820, -2820, -2820, -2820, -2820,
   -2820, -2820, -2820, -2820, -2820, -2820, -2820, -2820, -2820, -2820,
   -2820, -2820, -2820, -2820, -2820, -2820, -2820, -2820, -2820, -2820,
   -2820, -2820, -2820, -2820, -2820, -2820, -2820, -2820, -2820, -2820,
   -2820, -2820, -2820, -2820, -2820, -2820, -2820, -2820, -2820, -2820,
   -2820, -2820, -2820, -2820, -2820, -2820, -2820, -2820, -2820, -2820,
   -2820, -2820, -2820, -2820, -2820, -2820, -2820, -2820, -2820, -2820,
   -2820, -2820, -2820, -2820, -2820, -2820, -2820, -2820, -2820, -2820,
   -2820, -2820, -2820, -2820, -2820, -2820, -2820, -2820, -2820, -2820,
   -2820, -2820, -2820, -2820, -2820, -2820, -2820, -2820, -2820, -2820,
   -2820, -2820, -2820, -2820, -2820, -2820, -2820, -2820, -2820, -2820,
   -2820, -2820, -2820, -2820, -2820, -2820, -2820,  6019, -2820, -2820,
   -2820, -2820,   243,    72,    72,   186,   261,  2051,  1270,   874,
     200, -2820,  1661, -2820, -2820,  2216,  2230,  1808, -2820, -2820,
   -2820, -2820, -2820,  1885,  1885, -2820,   676,  1666, -2820,   243,
    1387, -2820,  1387,  1387, -2820, -2820,  1387,  1387, -2820,   243,
    1110,   423,  1387, -2820,  1110, -2820, -2820, -2820, -2820, -2820,
   -2820, -2820, -2820, -2820, -2820, -2820, -2820, -2820, -2820, -2820,
   -2820, -2820, -2820, -2820,   152,   152,   867,  1032, -2820,   680,
   -2820,   844, -2820,   -38,  2236, -2820, -2820,  1296,  1821,  1785,
   -2820, -2820, -2820, -2820, -2820, -2820, -2820,  1823, -2820, -2820,
    1621, -2820, -2820, -2820,  1870,  1870,  1693,  1720, -2820, -2820,
   -2820, -2820, -2820, -2820, -2820, -2820,  1598,   423,  1825, 10128,
     520, 10047,  1747, -2820, -2820, -2820,   520,   520,   520,   520,
    1611, 10047, 10047,   225,  1698,   555,   243, -2820, 10047, 10047,
   10047, 10047, -2820, -2820, -2820, -2820, -2820, -2820, -2820,  1604,
    -171,  1095,  5355, -2820, -2820,  1838,  2236, -2820, -2820, -2820,
   -2820,   -38, -2820,  1800,  1802,  1806,   797,  1809,  1810, -2820,
   -2820, -2820,  2180,   243, -2820,  2286, -2820, -2820,   492,  3819,
   -2820, -2820, -2820, -2820,   243, -2820, -2820,   492,  1581, -2820,
     291, -2820,  1633, -2820,  1660, -2820,  1851,   228, -2820,  1634,
   -2820,  1662, -2820,  1704,  1828,   243, -2820, -2820, -2820, -2820,
    4693,   243, -2820,  1638, -2820, -2820,  2162, -2820,  2162,  1637,
   -2820,  2298,  2299, -2820,  2301,  1689,  5355, -2820, -2820,  2306,
   -2820,  1646, -2820,  1784,  1650,  2126, -2820, -2820,  1653,  1106,
     243, -2820, -2820,  1848,   235,  1054,  1420,  1811,   348, -2820,
   -2820, -2820, -2820,  5355,  1387,  1095,   286, -2820,   243,   243,
    5355,    67,   -36,  2326,  1061,  2325,  2308,  2309,   868, -2820,
   -2820, -2820, -2820, -2820, -2820, -2820,   874,  1967, -2820, -2820,
   -2820, -2820,  2222,  5355,   399,  2070, -2820, -2820, -2820,  5355,
     162, -2820,  1962,  2335,  2337,   484,   485,   243,  1902,  1091,
   -2820,  4234,  1866,  1869, -2820, -2820,  1935, -2820,  5355,   -43,
   -2820,  1703, -2820, -2820,   257, -2820,  5355, -2820, -2820,  1676,
    1003, -2820,  1305,   243,  2336,  9749, -2820, -2820,  1095,   874,
   -2820, -2820,    37, -2820,  2126,  2126,  1644, -2820,  1754,  1762,
   -2820, -2820, -2820, -2820, -2820, -2820,    72,    72, -2820, -2820,
   -2820, -2820, -2820, -2820, -2820, -2820,  1817, -2820, -2820, -2820,
   -2820,    72,  2102,  2356,  2341, -2820,  1091,   276,   264,   120,
    2225,   -10,  1057, -2820,    17, -2820, -2820, -2820,  1896,    78,
    1387,    55,  1713, -2820,  1710, -2820, -2820, -2820, -2820, -2820,
    1897,  1897, -2820, -2820, -2820, -2820,  1787,  1714,  2374, -2820,
   -2820, -2820,   488,  1711,  1717, -2820, -2820,   874,   126, -2820,
   -2820, -2820,  1696,  1032, -2820,   243,   243, -2820, -2820,   243,
     521, -2820, -2820, -2820, -2820,  1910, -2820, -2820, -2820,  2361,
    1139, -2820, -2820,  1946,   118,  1949,   171,  1239, 10047, -2820,
     307,  2388,  1957,  2391, -2820, -2820, -2820, 10047, -2820,   487,
   10047, 10047, 10047, 10047,   243,   489, -2820,   432,  2395, -2820,
   -2820,   243,  9458, -2820,  1983,   243,  1737,   520,  2021, -2820,
   -2820, -2820, -2820, -2820, -2820,  1239,  2381,  1239, -2820,  9173,
   -2820,  1933, -2820,  1903, -2820,  1904,   193,   193,   193,   495,
    2180,   193,  9458,   243, -2820,   500,   243,   502, -2820, -2820,
   -2820,  1938,  1939,  1940,  1222,  1222, -2820,  1943, -2820,  1950,
    1953,  1956,  1958, -2820, -2820, -2820, -2820,   719, -2820, -2820,
   -2820,   504, -2820, -2820,   506,   243, -2820,   243,  1636, -2820,
     243,  1643,  5355, -2820,   243,  2406, -2820, -2820,   492, -2820,
   -2820,  1759,   492,   148, -2820, -2820, -2820,  1091,  5355,  5355,
    5355,  5084,  2428,  1387,    83, -2820,  1091,   243, -2820, -2820,
     243,   243, -2820,   882, -2820, -2820,   279, -2820,  1767,  5355,
   -2820, -2820, -2820,  2430,  1531,  1929, -2820,  1772,  2435, -2820,
   -2820,  1091,  1818, -2820, -2820, -2820, -2820, -2820,   243,  2126,
   -2820,   200, -2820,  1842, -2820, -2820,   513, -2820, -2820, -2820,
     874, -2820,  4310, -2820,  1128, -2820, -2820,  2067,  2420, -2820,
    2050,  2053,  1944,  1780,  2054,  1973, -2820, -2820, -2820,   632,
    2042, -2820, -2820, -2820, -2820,  1935, -2820, -2820, -2820,   233,
     608, -2820, -2820, -2820,  2216,  5355,  1980, -2820,  1952, -2820,
   -2820, -2820, -2820,  2451, -2820, -2820, -2820,  2455, -2820,  1763,
   -2820,  2436,   -36,   243,  2228,  2228,  2228,  2228,  2228,  2228,
   -2820,  2458, -2820,  2459,  2228,  2228,  2228,  2228,  2503, -2820,
   -2820,  2228,   127, -2820, -2820, -2820, -2820,  2440,  2452, -2820,
   -2820, -2820, -2820, -2820, -2820, -2820, -2820, -2820,  2454, -2820,
   -2820, -2820, -2820, -2820, -2820, -2820,   539, -2820, -2820, -2820,
    2443, -2820, -2820,  1387, -2820,   423, -2820, -2820, -2820, -2820,
   -2820, -2820,  1829,  1831,   121, -2820,    17, -2820,   193,  1812,
     235, -2820,  1991, -2820, -2820, -2820,   243,   243,   193, -2820,
   -2820,   132,  1387,  1109, 10047,   220, -2820,  5355, -2820,  5355,
   -2820, -2820, -2820, -2820, -2820,  1872,   235,   132,  1387,  2470,
   -2820,   874,   243,   843,   843, -2820, -2820,  2472, -2820,  2472,
     542,   542,  2472, -2820, -2820,  1862, -2820,  2036, -2820, -2820,
    2457, -2820,  2461, -2820,  2462, -2820,  2465,  2005, -2820, -2820,
   -2820, -2820, -2820, -2820, -2820,   117,  1222,  1820,  1222, -2820,
    1222,  2043, 10047, -2820,  2052,  2055,  2056,  2058, -2820, -2820,
     225, -2820,   225, -2820, -2820,  9642,  1688,  5638,  1688,  2489,
    2494, -2820, -2820, -2820, -2820, -2820, -2820,   167, 10047, -2820,
    2007, -2820,  2184,    90,   264,   243, -2820,  2062, -2820, -2820,
    5658,    89, -2820,  1862,  1428, -2820,    89,  1387,  1115,  2063,
    2501,  1840, -2820, -2820,   541, -2820,   544,   797, -2820, -2820,
     554,   215, -2820, -2820, -2820,   492, -2820,  2482,  2482,  2483,
    1845,   -63,  2484,  2485,  2493,  2484,  2484, -2820, -2820, -2820,
     217, -2820,   980,   243, -2820,   492, -2820, -2820, -2820,  1854,
   -2820, -2820,  1855, -2820, -2820,  -144,   556, -2820,   243,   558,
   -2820,  5355,  2081,  2504,   561,  1091,  2520, -2820, -2820, -2820,
   -2820,  5355,  1912,  2203,  5355, -2820, -2820, -2820, -2820,   279,
    1362,  1362,  2528,  -182, -2820,  2529, -2820, -2820, -2820,  1362,
     243,  1941,  1403,  2531,   243, -2820,  1531,   224,  1387,  2530,
    1091,  -181,  2326,  5355, -2820, -2820,   868, -2820,  1822,  5355,
   -2820, -2820, -2820,  2534,  4234,   874, -2820,   968,   243,   874,
   -2820,  2098,  4234,  4234, -2820, -2820,   632,  2042, -2820,  2503,
   -2820, -2820,  1154, -2820, -2820,  1922, -2820,  1531,  5098,  9749,
      38,  1063, -2820, -2820, -2820,  1880, -2820, -2820, -2820, -2820,
   -2820, -2820,    72,  2228,    72,  2228, -2820, -2820, -2820, -2820,
   -2820, -2820,   -36, -2820,  1192,  1209,  2102, -2820,  2100,  2064,
   10047, -2820,   120,   120, -2820, -2820, -2820, -2820,   562, -2820,
    2026, -2820,   193,   538, -2820,  1879, -2820,   564, -2820, -2820,
    2544, -2820, -2820,  1960, -2820,  2545,  9898,  9898,  9898,  9898,
     193,   193, -2820, -2820, -2820, -2820, -2820, -2820,  2544,  1883,
     874, -2820,  2472, -2820, -2820,   243,   542,   542, -2820, -2820,
     542,  2294,  1886, -2820,   211,   -52,   226,   515,  2532,  2117,
    1887,  1239,  1890,  1891, -2820, -2820, -2820, -2820, -2820, -2820,
   -2820,   566, -2820, -2820, -2820,   262,   357, -2820,  9458,  9458,
   -2820, -2820, -2820, -2820, -2820, -2820, -2820, -2820, -2820, 10223,
   10223,  2086, 10223,  2087, -2820, 10223,   665, 10047,  2563, -2820,
   -2820,  9458, -2820, -2820, -2820, -2820, -2820,  2564, -2820,   -56,
   -2820, -2820,  2184,  1899,  1900, -2820, -2820,   162,   162,   162,
    2549,   162,   162,   162,   162,   162,   162,  2550, -2820,  2551,
     162, -2820, -2820, -2820, -2820, -2820, -2820, -2820, -2820,  5658,
   -2820,   874,  1911, -2820,  2089,  2294,  2555, -2820,  2556,  2560,
    2561,  2562,  2565,  2570,  1158,  1428, -2820,  2089, -2820, -2820,
    2571, -2820,  2243,   193,  1443,   193, -2820, -2820,  2180, -2820,
   -2820, -2820, -2820,  2140,  2148,   572,  1239,  2574,  1239, -2820,
    2600,   582,  2165,  2166,  2600, -2820, -2820, -2820, -2820,  1387,
   -2820, -2820, -2820,  2130, -2820, -2820,   980, -2820,  2180, -2820,
   -2820,   243,   243, -2820, -2820,   243,  -246, -2820,   492,   151,
    2216, -2820,  2094,   151,   269,  1091, -2820,  2606,  2133, -2820,
   -2820,  2171,  2018, -2820, -2820,   243,  1362,  1531,  1447,   243,
    1362, -2820, -2820,    72, -2820, -2820,  5355, -2820, -2820,   352,
   -2820, -2820, -2820,  1091,  2609, -2820,    72,  2216,   874,  2330,
   -2820,  2595,  1754,  9173,  2597, -2820, -2820,   200,  2149, -2820,
   -2820,  4234, -2820, -2820,  2183, -2820, -2820, -2820,   608, -2820,
    1754, -2820,  5355, -2820,   370, -2820,  2088, -2820, -2820, -2820,
   -2820,  2145,  2239, -2820,  2617, -2820, -2820, -2820, -2820, -2820,
   -2820, -2820, -2820, -2820, -2820, -2820,   243, -2820,   106, -2820,
   -2820, -2820,   193, -2820,   423,  2446,   583, -2820, -2820, -2820,
   -2820,   243,   193, -2820,   132,   132,  2044, 10320, 10320, -2820,
   -2820, 10178,  2164, -2820, -2820,  2168,  2169, -2820,  2170,  2172,
    2174,  2175,   243,   -11, -2820, -2820, -2820, -2820,   587, -2820,
   -2820,  2099, -2820, -2820, -2820,   589,  2639,  2639, -2820, -2820,
     594,  2650,  2643, -2820,   317,   874,   132, -2820, -2820, -2820,
   -2820, -2820,  2397,  5393,  2634, -2820, -2820,  2635,  2636, -2820,
   -2820,  2637,  2223, -2820,  1239,  2224,  1239,  1239,   225, -2820,
   -2820,  2494, -2820,  2178,  2037,  2178,   189, -2820,  2178,   189,
   -2820,  2178, 10223, -2820, -2820, 10047, -2820, 10047,  2489,    90,
   -2820, -2820, -2820, -2820,  1239, -2820, -2820, -2820, -2820, -2820,
   -2820, -2820, -2820, -2820, -2820, -2820, -2820, -2820, -2820, -2820,
     440,  2659, -2820,   874,  1595, -2820,  2397, -2820, -2820, -2820,
   -2820, -2820, -2820, -2820, -2820, -2820, -2820, -2820,   374, -2820,
   -2820, -2820,  2173, -2820, -2820, -2820, -2820,  2645, -2820, -2820,
    2231, -2820,  2649,  2234,  2651, -2820, -2820, -2820,  2241, -2820,
    2208,  9458, -2820, -2820, -2820, -2820, -2820,   243,  2662, -2820,
    -246, -2820, -2820,  2670, -2820, -2820,  2673,   243,  2184,   151,
   -2820,    72,   -36, -2820,  2275,  1091, -2820,  5355, -2820,  2091,
    2675,   -36, -2820, -2820,   536, -2820, -2820, -2820, -2820,   194,
    2260, -2820, -2820,  1091,  2126,  2455,  2413, -2820,   -36,  2263,
    2266,  2326,  2232, -2820,  2313,  2268, -2820, -2820, -2820, -2820,
    2421,  2209,  5355,  2226, -2820, -2820, -2820,  1754, -2820,   596,
   -2820,   874,  2123, -2820, -2820, -2820, 10047, -2820, -2820,   193,
   -2820,  2240, -2820, -2820, -2820,  2544,  2123,  1954,  1954,  2276,
   10128,   520, 10278,   520,   520,   520,   520,   -71, 10278,  9898,
   -2820, 10278, 10278, 10278, 10278, -2820, -2820,   193,  2709,   193,
    9898,   235,  9458, -2820,  2455,    92, -2820, -2820, -2820,   196,
    2282,  2283,  2284, -2820, -2820, -2820, -2820, -2820,   217, -2820,
   -2820,   597, -2820, -2820, -2820, -2820,   606, -2820,  2178,  2720,
   -2820, -2820, -2820, -2820, -2820, -2820, -2820,   874,  2659, -2820,
   -2820, -2820,   874, -2820,   874, -2820, -2820,  1858, -2820,  2439,
   -2820,  2442,  2703, -2820, -2820,  2290,  2060, -2820, -2820, -2820,
    2292, -2820,   193,   267, -2820, -2820, -2820, -2820, -2820, -2820,
   -2820, -2820, -2820, -2820, -2820,  1091, -2820,  2295, 10477,  2256,
   -2820, -2820, -2820,  2072,   -36, -2820, -2820, -2820, -2820, -2820,
   -2820, -2820,  2302,   200, -2820,  2313,  2313,   608, -2820,  1531,
    2114, -2820, -2820,   243, -2820,  2455,   555,   117, -2820,  9981,
     555, -2820,  2303, 10278, -2820,   607, 10278, 10278, 10278, 10278,
    2715,   243,   609, -2820, -2820, -2820, -2820, -2820, -2820,  2267,
   -2820, -2820, -2820,  2489, -2820,   243, -2820,  2110, -2820, -2820,
   -2820, -2820, -2820, -2820, -2820,   180, -2820, -2820, -2820, 10047,
   -2820,  1690,  1690, -2820,  1690, -2820,  1690,  1690, -2820, -2820,
   -2820,  2273, -2820,  1239, -2820,   610, -2820,   906, -2820, -2820,
      59,    59,    59,    59,    59,    59, -2820,  2724, -2820,   612,
   -2820,  5355,  1470, -2820,   -47,  2313,  4234,  2313,  2326, -2820,
   -2820, -2820,  2460,   379, -2820,   -36, -2820, -2820, -2820, -2820,
     616, -2820, -2820,  1429, -2820,  2310, 10278, -2820,  2311,  2314,
    2315,  2317,   380,  2253, -2820,  9898, -2820,  2735, -2820, -2820,
   -2820, -2820,  1690, -2820,  1690, -2820, -2820, -2820, -2820, -2820,
   -2820, -2820, -2820, -2820,  1164, -2820, -2820, -2820, -2820, -2820,
   -2820, -2820, -2820, -2820, 10477, -2820,  2745, -2820, -2820, -2820,
   -2820,   -32, -2820, -2820, -2820, -2820, -2820, -2820,    37, -2820,
    9981, -2820,  1647, -2820, -2820, -2820, -2820, -2820, -2820, -2820,
   -2820,  2737, -2820,  2738,   617,   532, -2820, -2820,  1172,  1172,
   -2820, -2820,  1172, -2820,  5355,    19, -2820, -2820,  2323,    38,
   -2820,  2101,  2105,  2761, -2820,  2300,   384, -2820, -2820,  2741,
   -2820, -2820, -2820,  2327, -2820, -2820, -2820,   243,   243,  1647,
   -2820,  2747, -2820,  2334, -2820,   239,  2111, -2820, -2820,  2304,
   -2820, -2820,   200, -2820,   243, -2820,  2326, -2820
};

/* YYPGOTO[NTERM-NUM].  */
static const short yypgoto[] =
{
   -2820, -2820, -2820, -2820, -2820,   -35, -2820,    22,  -160, -2820,
   -2820, -1146,  -143, -2820, -2820, -2134, -2820, -2820, -2820, -2820,
    -903, -2820, -2820, -2820, -2820, -2820, -2820, -2820, -2820, -2820,
   -2820, -2820, -2820, -2820, -2820, -2820, -2332, -2820,  -987, -2820,
    1789, -2820, -2820, -2820, -2820, -2820, -2820, -2820,   289, -2820,
   -2820, -2820, -2820,  1249, -2820,   611, -2820, -2820,   -33, -2820,
   -2820,  2757, -2820,  2762, -2820, -2820, -2820, -2820, -2820,   361,
       6, -2820,   365, -2820, -2820, -2820, -2820, -2820, -2820, -2820,
   -2820, -2820, -2820, -2820,  -111,   997,   376, -2820, -2820,  2447,
      14, -2820,  2688, -2820, -2820,  2685, -2820,  2598, -2820, -2820,
   -2820, -2820, -2820,  2463,  2147,   779,  2456,  -503, -2820, -2820,
   -2820, -2820, -2820,   777,  -642, -2820, -2820, -2820, -2820, -2820,
   -2820, -2820, -2820,   571, -2820,  2584,  2274,  2601,    71,  2213,
   -2820,  2264,  1541, -2820,  2437, -2820, -2820, -2820, -2820,  2441,
   -2820, -2820, -2820, -2820,  -388, -2820, -2820, -2820, -2820, -2820,
   -2820, -2820, -2820,  2258, -2820,  2265, -2820, -2820, -2820, -2820,
   -2820, -2820, -2820, -2820, -1327, -2820, -2820,  -849, -2820, -2820,
   -2820, -2820, -2820, -2820, -2820, -2820, -2820, -2820,  -125, -2820,
   -2820,   750, -2820, -1101, -1147,   795, -2820, -2820, -2820, -2820,
   -2820, -2820, -2820, -2820, -2820,  1847, -2820, -2820, -2820, -2820,
   -2820, -2820, -2820,  -616, -2820, -2820, -2820, -2820, -2820,  2033,
   -2820, -2820, -2820, -2820, -2820, -2820, -2820, -2820,  -574, -2820,
    -101, -2820, -2820, -2820, -2820,  2422, -2820, -2820,  -235, -2820,
   -2820, -2820, -2820, -2820, -2820, -2820, -2820, -2820, -2820, -2820,
   -2820,  1586, -2820, -2820, -2820, -2820,   551, -2820, -2820, -2820,
   -2820, -2820, -1423, -2820, -2820,   547, -2820, -2820, -2820, -2820,
   -2820, -2820, -2820, -2820, -2820, -2820, -1098,  -852,   420,   708,
   -2820,  -226,  -551,   452, -1115,  1179, -2820,   628, -2820, -2438,
      -3,  -159, -2820, -2820, -2302,   268,  1594, -2820, -2820, -2820,
     463,   959, -2820, -2820, -2820, -2820, -2820, -2820,     1, -2820,
    -309, -2820,   961, -2820,   638, -2820,   328, -2820, -2820, -2820,
   -2820,  -881, -2820, -2820, -2820, -2820, -2820, -2820, -2820, -2820,
     429, -2820, -2820, -1839, -2820,   627, -2820, -2820, -2820, -2820,
   -2820, -2820, -2820, -2820, -2820, -2820, -2820, -2820, -2820, -2820,
   -2820, -2820, -2820,  1431, -2820, -2820, -2820, -2820, -2820, -2820,
    -515, -2820, -2820, -2073, -2820, -2820, -2820, -2820,   422, -2326,
   -2820, -1118, -2820, -2820, -2820, -2820, -2820, -2820, -2820, -2820,
   -2820, -2820, -2820, -2820, -2820, -2820,  2839, -2820, -2820, -2820,
    2766,  2819, -2236, -2820, -2820, -2820, -2820, -2820, -2820, -2820,
    -436, -2820, -2820, -2820, -2820, -2820,  2826, -2820, -2820,  2847,
   -2820, -2820, -2820, -2820, -2820, -2820, -2820, -2820, -2820, -2820,
   -2820,  1951, -2820, -2820, -2820, -2820, -2820,   686, -2820, -2820,
   -2820, -2820, -2820, -2820, -2820, -2820, -2820, -2820,  -656,  2120,
   -2820, -2820, -2820, -2820, -2820, -2820, -2820,  2589, -2820, -2820,
     -25, -2820, -2820,   681, -2820, -2820,  1329,  -185,  2553, -2820,
   -2820, -2820, -2820,   -99, -2820, -1041,  1894,   993, -1435,  1384,
   -2820,   691,  1667,  -407,  -589, -2820,  2121,  1468, -2820, -2820,
   -2820, -2820, -2820, -2820, -2820, -2820, -2820, -2820, -2820, -2820,
   -2820, -2820, -2820, -2820, -2820, -2820, -2820, -2820,  1396, -2820,
    -766, -2820,  -615, -2820, -2820, -2820, -2820, -2820, -2820, -2820,
    -799, -2820, -2820, -2820, -2820, -2820, -2820,    60, -2820, -1334,
    1491,   310, -2820, -2820, -2820, -2820, -2820,  -122, -2820,  -581,
   -2820, -2820, -2820, -2820, -2820, -2820, -2820, -2820, -2820, -2820,
   -2820, -2820, -2820, -2820, -2820,  1391, -2820, -2820, -2820, -2820,
   -2820, -2820, -2820, -2820,  -517, -2820,   751,  2464, -2820, -2820,
    -114, -2820,  -623, -2820, -2820,   -94,   210, -2820, -2820, -2820,
   -2820, -2820, -2820, -2820,  1198, -2820, -2820, -2820, -2820, -2820,
   -2820, -2820, -2820, -2820, -2820, -2820, -2820, -2820, -2820, -2820,
   -2820, -2820, -2820, -2820, -2820, -2820, -2820, -2820, -2820,  -166,
   -2820,  -430,  -427, -2820, -2820,  -419, -2820, -2797, -2820,  -153,
     511, -1345, -2820, -2820, -2820,   864, -2820, -1983, -2820, -2820,
   -2820, -1965, -2820, -2820, -1955, -2820, -2820, -2820, -2820, -2300,
   -2820,   883,   563, -2820, -2820, -2820, -2820, -2820,   343, -2820,
   -2820, -2820, -2820, -2820, -2820,  -772, -2820, -2820, -2820, -2820,
   -2820, -2820, -2820, -2820, -2820, -2820, -2820, -2820, -2820,  -339,
   -2820, -2820, -2820, -2820, -2820, -2820, -2820, -2820, -2820, -2820,
   -2820,  1007, -2820,  1009, -2820,   329,   673, -2820, -2511,  -249,
   -2820, -2820, -2820, -2820, -2820, -2820,   -96, -2820, -2820,  -564,
   -2820, -1374, -1331, -2820, -2820, -2820, -2820, -2820,  -127, -2820,
   -2820, -2820, -2820, -2820, -1981, -2820, -2820, -2820, -2820, -2820,
   -2820, -2529,   614, -2820, -2596,   693, -2820, -2820, -2321,    -8,
      -6,   280, -2820, -2117, -1980, -2820, -2820,  -315,  -632, -2820,
   -2820, -2820, -2820, -1943, -2820, -2820, -2820,   -93, -2820,   230,
    -966, -2820,  -569,  -317,  1051,  -349, -2160,   263, -2820,   254,
   -2820, -2820, -2820, -2820,    43, -2820, -1263, -2312,  2961, -2820,
   -2820, -2820, -2820, -2820, -2820, -2820, -2820,  -778, -2820, -1702,
   -2820,  1723, -2820, -2820,   493,   281, -2820, -2373,   282,  -212,
      95,  -417, -1887, -2250,   974,  -288,  -247, -1261, -2820,   984,
   -2820, -2820, -2820,  1076,  -723, -2820, -2820,  -562,  1738, -2820,
     990, -2820, -2820,   387,  -195, -2820, -2820, -2820, -2251,  -433,
   -1626, -2820,  -367, -2820, -2820, -2820, -2820,  1112, -2820, -2820,
   -2820, -2820, -2820, -2820, -2820, -2820, -2820, -2820, -2744,  -451,
   -2820, -2819, -2254, -1845, -1402, -2820, -2820,  -437, -2820, -2820,
   -2820,   199, -1092,   977,  -710,  1881,  1563,  1551, -1926, -2820,
   -2820,   204,   559,   259, -2820, -2820, -2820, -2820,  1578, -2820,
   -2820, -2820, -2820, -2820, -2820, -2820, -2820, -2820,  -294,  1347,
    2466, -2820, -2820, -2820, -2820
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -2265
static const short yytable[] =
{
      34,    36,    38,   326,   182,    38,   568,  1391,  1343,   266,
     998,  1452,    86,   954,   234,  1500,  2134,  1974,  1975,  1508,
     986,  2058,  1449,  1480,   408,   409,  1167,   678,  2042,   102,
    1448,   406,   407,  2696,  2270,  2698,  2435,    58,   423,  1459,
    1460,  2721,  1461,   962,  1482,  1483,   294,  2208,  2209,   101,
    2019,    58,  2020,  2320,  2321,  2322,  2323,    86,  2655,  2929,
    2719,  2831,   108,  2313,  2078,   948,  1115,   943,   182,   115,
     576,  1173,    33,   120,  2393,  2087,   122,   123,  3215,  3216,
    3217,   126,   127,   111,   576,  1453,    33,   182,   421,  2392,
      33,    33,  1053,  2368,    33,  1085,  1048,  3184,  2567,    33,
    2308,    58,  1890,  2776,  2862,  2159,  2908,  1060,  1029,    33,
      33,  2002,   586,   590,  1885,  1029,  2976,    33,   230,  1031,
     591,   233,  2002,  1450,   364,   365,   237,  1421,  1895,  2786,
     195,  2621,   576,  1908,    33,  1499,   410,  2640,  1421,  2583,
     425,  2940,   427,  2942,   428,   429,   430,    33,    33, -2263,
    3149,  1057,  1058,   435,  2123,    33,  3219,   446,   447,    33,
     511,   253,  1120,   331,   272,  1123,   502,  1125,   272,   332,
     333,   565,  1272,  1171,  1166,    33,  2950,  2951,  1886,  2952,
    2953,  2954,  2955,  2956,  2957,  3273,   272,   329,  1049,  1205,
    2644,  2123,   272,  1217,  1218,    33,  2712,  2715,  2715,   576,
    1407,  2715,   324,  1107,   272,  1281,  1282,    33,    33,  3343,
    1501,  1502,  2860,   272,  1281,  1282,    33,   561,  1029,   182,
      33,  2948,  3577,   182,   272,  1217,  1218,    33,   563,   361,
    3234,   272,   327,   328,    33,   367,   571,   253,  1078,   357,
      33,   272,  3055,  1282,  3110,  3238,   576,   396,     4,  1029,
    1029,    33,    33,   405,   405,   405,   405,   405,  2830,  3115,
      33,   405,    33,  2587,  2777,   324,  1890,  2127,  2948,  2128,
      33,  2129,  2516,  2948,  3354,  2181,  3011,   324,  2590,  2593,
    2181,  1431,   349,  1496,  2790,  3574,  3344,  3345,  1227,  1171,
     324,    33, -2263,  2001,  1408,  1409,  1489,  1490,  2219,    54,
    3726,   112,  1912,    33,    99,    44,   599,  2175,  2346,   602,
      58,    58,  2656,  2219,  2083,  2896,  2897,  2898,  2899,  2900,
     513,  1439,   444,  1226,   578,  3097,   610,   611,   612,   613,
     650,   614,   615,   616,   617,   618,   619,   620,   621,   622,
     623,   624,   625,   626,   627,   628,   629,   630,  2494,    99,
     946, -2263,  1432,  2444,  2895,   521,  2945,  2444,   631,   632,
    2435,   527,  2152,   634, -2263,   635,  2950,  2951,   423,  2952,
    2953,  2954,  2955,  2956,  2957,   324,  2594,     6,  1040,  3492,
     638,   639,   640,   641,   324,  3711,    43,   648,    54,  3751,
    3236,   576,  1027,  1027,  2694,  1359,  1360,  1027,  1027,  2921,
     315,   316,   317,   318,   319,   931,   576,   368,    54,  2133,
    1027,    52,  1115,     1,   182,   573,  3047,     2,   947,  1914,
    1111,  1227,  2146,   594,  3337,  1361,  1362,  1363,  2879,  1111,
    1027,  2224,    43,  1027,   369,   658,  3560,   932,  2888,  1027,
      54,   675,  3073,  1027,  1094,  3346,  2224,  1027,     7,   929,
      48,  1027,  3761,    54,  1227,  1027,  1027,  1029,  1027,    33,
    1530,  1027,  1891,  1027,  1027,  1027,   997,  3015,  3428,  2958,
      27,  1027,   661,    54,  1027,   663,  1388,   182,  3338,   667,
    1891,  1027,  2022,  2022,   579,  3098,    76,  2027,  1027,   576,
     576,  3074,  2662,    77,  2662,  1027,  1439, -2263,  1402,   566,
    2717,    58,  2347,  3137,    54,  2366,  1027,  2725,  1101,  2743,
    1027,  2745,   830,   923,  1027,    33,    54,  3441,  2806,    33,
    1027,  1024,  1024,  1027,    26,  3116, -2263,  1025,  1028,    69,
    3270,  1920,  1227,  2980,   670,   587,  2182,   670,   275,    78,
      79,  2182,  1535,  1103,  2866,   670,  3035,    80,   573,  3035,
     182,  3511,  1162,  1163,   315,   316,   317,   318,   319,  3035,
    2641,  3075,   396,  3078,   396,  1061,  3078,  3172,  1061,  3182,
    1924,  3248,   945,   405,  2573,  1011,   950,  3317,  1070,  3271,
    1230,  1211,  1061,  2178,  1214,  3237,  1061,  3324,  3409,  2959,
    2960,   405,  3429,  1087,  3429,  1273,  3561,  2791,  1061,  3437,
    1070,  3543,  3585,  1219,  1228,  2877,  1099,  2043,  1454,  1070,
    3048,  3585,  3646,  2645,  3646,  3033,  1109,  3684,    33,  3245,
    3168,  3700,  3429,  1124,  2458,  1286,  1229, -2263,  3150,   665,
    1165, -2263,  1907,  2584,  1286,  3762,  1024,  3111,  3578,  1921,
    1921,  1099,   100,  2889,  2961,  1099,  2144,   972,  1229,  1099,
    3268,  3012,  2332,  3235,   562,  1070,  1514,  3040,  1070,  2958,
    2054,  1455,  1286,  1497,   960,   564,  1503,  1555,  3239,  2147,
    2501,   670,   325,   572,  3415,  3262,    58,    58,    58,  1016,
      58,  1020,  1022,   577,  3378,  1030,  1032,  1033,  2870,  2089,
    1038,  1102,  1022,  3568,  3355,  1041,  1115,    58,    33,  1968,
    1969,  2104,  3388,  1220,  3250,  2360,  1033,  3401,  1987,  3606,
    2029,  2003,  2058,  1230,  1498,  3445,  1451,  1030,  1030,  3457,
    2622,  1309,  3177,   103,  1978,  2521,  1422,  1033,  2006,  1235,
     588,   592,  3164,    58,  3319,   516,  3321,  1447,  3314,    58,
    1033,    58,  2707,    33,  1192,    58,  1230,   996,    58,  2707,
    1088,    58,  2415,  1504,  2416,  2642,  3575,  2090,  1022,   949,
    1344,    58,  3070,  1956,  2517,  2160,   405,  1105,  3333,  1030,
    3041,  2962,  2765,  1112,  1506,  1456,    58,   402,  3069,  2959,
    2960,   402,    58,  2575,   405,   405,   402,  2033,  2327,    58,
      58,    58,  3360,  3362,  1364,  1186,   402,  3367,  1193,  2309,
    2034,    81,    33,    58,   915,  2460,  3546,   293,  2646,  1979,
    1206,   293,  1206,   405,  2130,  1206,   405,  2074,  1206,    58,
    3550,  3347,  2131,  2445,  1230,  1980,  2079,  3371,   582,   293,
    1410,  2521,  1027,   965,  2961,   293,  3714,  2963, -2263, -2263,
   -2263, -2263, -2263,   583,     1,  3391,  1079,   293,     2,  3493,
    1556,  2901,  2707,  2102,  3697,  3712,   293,  1269,  1330,  3752,
     595,  1330,   277,  2629,  2239,  2240,  2632,   293,  1981,   648,
     648,  1177,   659,  3310,   293,  3313,  1993,  1955,  1994,  1995,
    1365,  2606,  2876,  2707,   293,   280,  2033,  2964,  2965,  1024,
    2607,  3442, -2263,  1462,    33,   110,    82,  2633,    53,  2034,
      33,    33,  2035,     1,  1231,  1232,  1233,  1982,   112,   662,
    2451,  2670,   664,   522,  2608,  1234,   668,  2609, -2263,  2023,
    2024,  1178,  1255,  1366,  2028,   532,  2480,  2481,  2186,  2663,
    2314,  2669,  3454,  2610,  3455,  3456,  1983,  2718,  2335,     3,
    3092,   607,  2723,   116,  2726,  1984,  2744,   966,  2746,   188,
    2452,  3638,  1027,  1027,  1027,  2807,    54,  3240,  1179,  3542,
    3435,  2962,  3472,   189,  3263,  1302,  2033,  1165,   286,   192,
    3214,  3214,  3214,  3214,  3738,  2737,  2738,  2739,  2168,  2034,
    3255,  2867,  3258,  3036,  2716,  3261,  3037,  2720,    83,   315,
     316,   317,   318,   319,  1042,    33,  3039,    10,  3076,  2157,
    3079,  2035,  1486,  3083,  3173,  1354,  3183,   670,  3249,  1493,
    3503,  3523,  3405,    10,  3318,    54,  2037,  1347,   114,  1047,
    2467, -2263,  3413, -2263,  3325,  3410,  3474,  2963,   153,  3430,
      33,  3436,  2038,  2450,  2148,    33,  3438,  2611,  3544,  3586,
    1065,  1988,  1030, -2263,  2315,    58,  1557,  2657,  3587,  3647,
    2285,  3654,  3669,  1074,  3685,  1180,   967,  3174,  3701,  3737,
     289,    58,  -282,  2760,  1030,  3178,  1496,  2760,    84,  2461,
    2048, -2263,   290,   291,   231,  3475,    85,  2964,  2965,  1558,
     292,  2035,  1017,   925,    33,  2504,   232,  1905,  1124,  1165,
    2612,   239,  2033,  2150,    33,  1463,  2428,  2613,  2429,  1110,
       4,    33,  3264,    58,  3265,  2034,   926,    54,  1112,  2980,
     241,  2730,  2731,    54,    54,  2037,  1171,  2336,    33,  1112,
    1437,  3573,    33,  2787,   165,    53,   984,    33,  2337,   987,
     248,  2038,  1181,    58,    58,    58,   166,    58,  3460,    58,
      58,  3465,    26,    27,  3467,    58,    58,  -282,   249,  1540,
    2057,    33,  3241,  2316,  2810,    33,  3547,  2614,   252,     4,
    1377,  2241,  1901,  -282,    33,  1383,  3435,  3435,  2740,  3739,
    3169,  3170,  1182,  3637,  2084,  3563,    33,  3643,  1528,  3139,
      58,    33,  1378,  3304,  2486,    33,  3571,  1384,  3057,  1539,
    2105,   107,    58,  2286,  3670,  2037,   251,  1547,    33,  2912,
     255,  1103,  2430,  3629,  3630,  2431,  -282,  2035,    54,  2285,
    1428,  2038,  2287,  2288, -2263,   256,    58,    58,  3160,    33,
     257,     5,  1464,   373,  2033,    58,   258,  2219,  1465,  1466,
    1467,   259,  2289, -2263, -2263,  3162,    33,  2034,  1183,  1414,
     260,    58,    58,    54,  2030,  -282,  1415,  2032,    54,  3548,
    1468,  2219,  1191, -2263,   321,    37,  1197,    33, -2263,   413,
    1201,  3214,  3214,   261,   414,  3214,   416,  1958,   262,     6,
    3206,  3206,  3206,  3206,  -282,  1302,  1302,   172,  1210,  2117,
       5,  1213,  3468,  -282,  1216,  1302,   263,  3406,  3058,  2165,
    2166,  3668,  2121,  3693,  1021,  3695,    33,    54,  2000,    33,
       7,   173,  2277,   423,   264,  3671,  2007,    54,   374,  3672,
    2210,  2211,  2212,   265,  1111,  2213,  2296,  2214,  2215,   267,
    2428,  2037,  2429,    33,   375,  2507,  3059,  2255,   309,     8,
    3464,    54,    33,  3464,   958,  1111,   959,  2038,   182,  2035,
      54,  2247,  2712,  2248,  2249,   174,  3419,  2251,  2252,   411,
     412,  3588,  2286,  2271,   175,  1469,  2067,  2044,  1470,     7,
    2224,  2049,  2055,  2049,    54,   310,  1471,   376,    54,   104,
     105,  2287,  2288,  2061,  2063,  2064,  2844,    54,    58,  2068,
    2070,  2071,  2072,  1030,  2224,   353,  3038,  1093,     8,    54,
    3060,  2289,  1030,  2930,    54,  2932,  1100,  2933,    54,   382,
    2058,  1472,   360,  1112,  3061,    58,   377,    58,  2036,    58,
      58,   311,  1029,   426,    33,  1115,  1244,    58,    58,  1030,
    2802,    58,   405,  3104,   405,    58,  2430,  1245,   371,  2431,
      33,   312,    54,  1112,  2331,   378,  1473,   322,   176,   177,
    2120,  1112,  1209,   313,   379,  1212,  2485,    58,    58,    54,
     925,  2219,  3720,  2037,   314,  1474,  1475,  1437,  1532,    33,
   -2263,  2409,   344,  3311,   104,   105,  1476,  3365,   345,  2038,
      33,  1477,  1257,   926,    33,  2881,  2585,  1246,  3553,   346,
    3556,  3557,  3558,  3559,   383,   104,   105,   336,   337,   338,
    3687,  1247,    58,    58,  2313,    58,  3214,    33,    58,    58,
     384,  2907,  3214,  3214,  3062,  3214,  3214,  3214,  3214,  2219,
    1478,  1055,   350,  2572,  3214,   351, -2263, -2263,   413,  2163,
    3063,   405,   405,   414,   415,   416,   405,   323,    58, -2263,
    2172,  2173, -2263, -2263,  3676,  1071,   390,  2476, -2263, -2263,
    2256,   355,  1479,   385,  1127,  1128,  1129,  1130,  1533,   156,
     157,  3689,   359,    58,  2257,  2447,   436,   158,    33,  1250,
    1251,  3206,  3206,  3671,  1526,  3206,    33,  3672,  1487,  1488,
     372, -2263,  1491,  1492,   381, -2263, -2263,  3554, -2263,   391,
    1248,  1160,   386,  3554,  2224,   397,  3564,  3565,  3566,  3567,
    2216,  1175,  1959,  2217,  1190,  2218,  2258,  2258,  1196,   362,
    1971,  3676,  1972, -2263,  1202,   366,  1204,  2259,  2259,  1379,
    1380,   387,  1392,  1393,  1394,  2219,   400,  2062,  3689,    33,
     388,  2065,  3030,    33,  2069,  2220,    33,  3214,  2260,  2260,
    3214,  3214,  3214,  3214,   401,  2261,  2261,  2473,  3016,  1978,
     159,   437,  2224,  2262,  2262,  2301,  2221,  2302,  2204,  2205,
   -2263,   431,   160,  3017,  3018,   433,  2647,   438,   455,  3464,
    3080,  2749,  3019,    33,   434,  2263,  2263,  1131,  2752,  2222,
      33,   504,  3731,  2223,    33,  1132,  2085,  1960,  2085,   161,
     445,  2592, -2263,  3375,  1133, -2263,   448,  1134,  3120,   449,
    2766,  3146,   451,  1961,  2767,   452,  3020,   453,  3254,  3254,
     439,  3254,  3117,  2778,  3254,  3021,  3479, -2263,  3645,  2190,
     105,  3648,  3649,  3650,  3651,   454,  3159,  1063,  2303,  2304,
    3214,  2280,  2281,   517,  1979,   519,  2638,   515,  2799,  3214,
    1135,  1072,   524,  3342,  3022,  1077,  1962,  1136,   525,   440,
    1980,  2648,  2311,  2264,  2318,  2305,  2306,  1091,  2224,  2265,
    2441,  2442,  1383,   526,  2318,  1309,   528,  2649,  2331,  1231,
    1232,  2341,  2342,  2343,  2344,   529,  3702,  3703,   441,  3053,
    3054,    54,   533,   162,  1384,  1963,   535,   442,   534,  3023,
     538,  3480, -1615,  1981,   330,  3417,  3418,   539,   335, -2263,
    3444,   550,   549,  2761,  1137,   551,  3206,   554,   559,   570,
    2650,  3706,  3206,  3206,  1964,  3206,  3206,  3206,  3206,   569,
     575,   580,   581,  1965,  3206,  1509,  1510,  1511,  1512,  1138,
    1027,   585,  1982,  3024,   593,   600,  1139,  3125,  1140,   315,
     316,   317,   318,   319,   603,  3133,  3134,   633,  1141,  2651,
   -2263,   604,  2293,  3481,   605,  3482,  2803,   608,   642,   643,
     636,  1983,   649,   651,  2102,  1399,   653,  2210,  2211,  2212,
    1984,  3483,  2213,   655,  2214,  2215,  1142,   652,  2652,  3484,
     163,  1037,   654,  3485,  1143,   656, -2263,  2653,   657,  1206,
     405,   405,   660,  1046,   666,   676,    58,    58,   930,   503,
    2010,  2011,     1,   935,   957,  2838,  2459,  2349,  3486,   937,
     938,   939,   944,   953,   955,   164,  2243,  1030,   956,  1030,
    1030,  1144,  1066,  1030,  1030,   971,  2253,   964,   969,  1030,
    2354,   973,   974,   975,   992,   994,   999,  3206,  1083,  1084,
    3206,  3206,  3206,  3206,  1090,  1145,  1000,  1092, -2263,   165,
   -2263,  1002,  1003,    58,  1004,  1027,  1008,  1005,  2515,  1007,
    1009,   166,  1010,  1012,  2297,  2440, -2263,  1122,  1198,  1259,
    1260,  1160,  1261,  1262, -2263,  1263,  3545,  1264, -2263,  1515,
    1265,  1521,  1146,  1266,  3433,  3434,  1267,  1268,  1027, -2263,
    1270,  1275,  1271,  1147,  1274,  1276,  1302,   167,  1302,  1277,
    2530,  2532,  1320, -2263,  1327,  1328,  2542,  1329,  1302,  1302,
    1030,  3254,   168,  2340,  2869,  1302,  1302,  1302,  1302,  1332,
     169,  2012,  2013,  2014,  2015,  2016,  2017,  1333,  1112,  1335,
    3206,  1336,  1337,   170,  1338,  1339,  1340,  1341,  2472,  3206,
    1345,  1346,  1352,  2893,  1376,  1350,  1381,  1385,  1386,  1351,
    2044,  1347,  3084,  1353,  3480,  2049,   648,  1357,  1382,  2909,
    1387,  2055,  1406,  1389,  2049,  2008,  2009,  2010,  2011,  1395,
    1412,  1309,  1413,  1416,  1417,  1419,  1424,   171,  1436,  1420,
    2661,  1425,  2407,  2664,  2665,  2666,  2667,  3114,  2411,  1439,
    1124,  1148,  1149,  1150,  1427,  1441,  3381,  1444,  1484,  1443,
    1494,  1495,   172,  1499,  1151,  2012,  2013,  2014,  2015,  2016,
    2017,  2331,  1522,  2331,  1523,  1524,  3481,  2438,  3482,  1525,
    1529,  1531,  1535,  1165,  1534,  1544,   173,  3431,  3432,  3433,
    3434,  1030,  1112,  1546,  3483,  2454,  2455,  1881,   405,  1882,
    1883,   576,  3484,  1884,  1889,  1893,  3485,  2216,  1896,  1897,
    2217,  1898,  2218,    58,  3383,  1899,  1946,  1954,  1967,  1957,
    1970,  1976,  2543,  2544,  2545,  2546,  2547,  2548,  1977,  1989,
     174,  3486,  2219,  1990,  2483,  1991,    58,  1992,  1319,   175,
    1996,  1321,  2220,  1322,  1323,  1324,  1325,  1326,  2012,  2013,
    2014,  2015,  2016,  2017,  1997,  2021,  2047,    58,  1998,  2508,
    1547,  2060,  1302,  2539,  2026,  1112,    58,  1152,  1999,  2075,
    2076,  2077,  2080,  2081,  2082,  1407,  3514,  2096,  2110,  2091,
    2092,  2093,  1506,   405,   405,  3522,  2222,  2103,  2112,  2114,
    2223,  2123,  2136,  2153,  2125,  2137,  2111,  2155,   405,  2447,
    2164,  2169,  3528,    58,    58,    58,  2178,  2192,  2185,    58,
    2012,  2013,  2014,  2015,  2016,  2017,  2167,  1030,  2187,  2549,
    2193,  2195,  1891,   176,   177,  2231,  2233,  2234,  2236,  2944,
    2242,  2947,  2294,  2298,  2299,  2300,  1987,  2309, -2263, -2263,
   -2263,  2307,  2332, -2263,    58, -2263, -2263,  2345,  2324,  2356,
    2350,  2357,  2628,  2628,  2117,  2358,  2628,  2363,  2361,  2362,
    1027,  2366,  2395,  2399,  2145,  2224,  1027,  2398,  2402,  2401,
    2397,  2400,  2413,  2418,  2419,  1302,  2420,  2404,  1050,  1050,
    2417,  2423,  1515,  2424,  1302,  2425,  2421,  1302,  1302,  1302,
    1302,  2668,  1027,  2426,  1030,  2427,  3572,  2439,  2673,  1302,
    2174,  1890,  2691,  2462,  2464,  2465,  2469,  2471,  2474, -2263,
    2478,  2189,  2479,   182,  2484,  2487,  2491,  2497,  2488,  2505,
    2511,  1234,  2521,  2708,  2708,  2708,  2523,  1309,  2708,  1302,
    2722,  2570,  3356,  2044,  3276,  3277,  3278,  2571,  3280,  3281,
    3282,  3283,  3284,  3285,  2582,  2588,  2598,  3288,  3623,  2603,
    2596,  2601,  2625,  2597,  2617,  2636,  2602,  2637,  2639,  2618,
    3372,  2643,  2747,  2658,  2748,  2750,  2660,  2751,  2753,  2659,
    2672,  2755,  2688,  2693,  2695,  2049,  1050,  2697,  2699,  2049,
      58,  2758,  2700,  2704,    58,  2935,  1221,  2727,  2728,  2729,
    1030,  2708,  2732,    58,  2438,  1124,  2763,  2783,  2783,  2733,
    2946,  1165,  2734,  2774,  2792,  2735,  2796,  2736,  2794,  2797,
    2798,  2970,  2800,  2804,  2812,  2813,  2815,  2818,    58,  2816,
    2819,  2817,  2820, -2263,  2836,  2801,  2839,  1165,    58,  2837,
    1496,  1233,  2843,  2852,  2854,  2863,  2864,    58,  2865,  2868,
    2882,    58,  2872,  2905,  2873,  2910,  2880,  2915,  2923,  3205,
    3205,  3205,  3205,  2924,  2928,  2934,  2550,  2925,  2926,  3699,
    3330,  2927,  3628,  2931,  2936,  2948,    58,  2937,  2938,  2551,
    2939,  2949,  2974,  2971,  2983,  3032,  3033,  3034,  3042,  3045,
    3049,  3051,  3677,  3678,  3679,  3680,  3681,  3682,  3046,  3052,
    2845,  3071,  3072,  3081,  3082,  3085,  3087,  3088,  1462,  3207,
    3207,  3207,  3207,  3095,  3099,  3103,  3106,  3121,  3113,  3124,
    3132,  3142,  3165,  3166,  3257,  3174,  3260,  3154, -2263,  3184,
    2002, -2263,  3181, -2263,  3185, -2263,  3226,  3233,  3242,  3243,
    3244,  2552,  1303,  3246,  3247,  3256,  3259,  2553,  3267,  3269,
    1030,  3275,  3274, -2263,  3279,  3286,  3287,  3293,  1027,  1027,
    3297,  3298,  3315, -2263,  3294,  2708,  3299,  3300,  3301,  3059,
    3316,  3302,  2515,  2884,  2253,  2708,  3303,  3308,  2243,  1030,
    3320,  1302,   923,  1952, -2263,  3322,  2554,  3326,  3327,  3331,
    3351,  3357,  3358,  3359,  2243,  1030,  3360,  3373,    58,  2628,
   -2263,  3377,  3379,  1309,  3382,  3386,  3155, -2263,  3157,    63,
    2555, -2263,  3516,  3473,  3394,  1228,  2117,  3397,  3407,  3694,
    2556,  2557,  1221,  3420,  3429,  3401,  2558,  3421,  3422,  3423,
    3526,  3424,  3144,  3425,  3426,  3439,  2559,  3440,  3446,  1302,
    3449,  3450,  3451,  3452,  3477,  3453, -1804,  1030,  3458,  1030,
     923,  3495,  1302,  3496,  1302,  3497,  3499,  3500,  2560,  2331,
    3030,  2561,  2562,  3501,  3123,  1302,  2563,  3502,  3506,   648,
    2708,    58,  2691,   154,   185,   182,  3508,   648,   648,  3509,
    3515,  3521,  3525,  3527,  2708,  3529, -2263,  3519,  3530,  3533,
    3535,  3531, -2263,  1124,  1124, -2263,  3539,  2003,  3551,  3549,
    3266,  3766,  2049,  3569,  3579,  3580,  3581,  3589,  3599,  3601,
    1463,  3600,  3602,  3603,  3604,  3621,   182,  3634,  3609,  3622,
    2055,  3652,  2049,  2564,  3627,  3644,  3655,  3657,  3667,  3683,
    3724,  3696,  3705,  3707,  2565,  2407,  3708,  3709,   185,  3710,
    3713,  3715,    58,  3735,  3736,  3745,  3749,  3753,  3747,  3754,
    3205,  3205,  3748,  3759,  3205,  3750,  3760,   185,  3764,  3765,
    3077,  3723,  3128,  1342,  2828,  2177,    49,  2438,  2779,  3105,
    2496,  3107,  3608,    50,  2708,  1030,  3102,    58,  2788,   530,
     191,   196,  1001,   343,  2352,  2351,   523,   356,   669,   531,
     963,   348,    58,  1221,    58,  3129,    58,   934,  1973,   558,
    3207,  3207,   556,   940,  3207,  3721,   469,   470,   471,    58,
    2410,  1185,   941,  1334,  2626,   589,  1302,  2634,  2456,  1950,
    2770,  2203,  3153,  3396,  2520,  3448,  2207,  2842,  3746,   405,
     472,   405,  2775,  2540,  3524,    46,   128,  1464,  2107,    60,
    3490,    58,    58,  1465,  1466,  1467,    61,  1302,  3369,    47,
    2503,  2506,  1303,  1303,  1089,  1399,  2191,   514,  1258,  2708,
    2143,  3374,  1303,  2230,  2510,  1468,  3478,  1887,  3590,  2098,
    2141,  2422,  3727,  3203,  3203,  3203,  3203,  2708,  2708,  3148,
    1121,  2088,   509,   510,  1356,  3307,  3598,    58,  2158,   185,
    2475,  3306,  3228,   185,   609,  3289,  3028,  3353,  2446,  3512,
    3510,  3507,  3336,  2764,  2396,  2093,  2365,  2874,  3730,  2724,
    3471,  2273,  2894,  2274,  2600,  3414,  3309,  3364,  3605,  3332,
    3251,  2671,  2591,  3252,  3466,  1302,  1302,   473,   474,   475,
     476,   477,   478,  3658,  1515,  2943,  1302,  1302,  3044,  1302,
    2246,  3328,  1302,  3494,  1302,   479,   480,   481,  1302,    42,
    3029,  3758,  1938,  2493,  3416,  2981,  2326,  2982,  3180,  3470,
    2238,  3636,  2138,  1904,  2886,  2325,  3412,  3552,  3570,  2201,
    1469,  3562,  1438,  1470,  3056,  2122,   182,  3112,  2348,  2116,
    3109,  1471,     0,  2795,  2106,  3205,   648,     0,    58,   677,
       0,  3205,  3205,     0,  3205,  3205,  3205,  3205,  3469,     0,
    2970,    58,     0,  3205,     0,     0,     0,     0,     0,     0,
    2708,  3312,  2708,     0,     0,     0,  1472,     0,     0,     0,
       0,     0,     0,  3505,  1221,     0,     0,     0,     0,     0,
       0,     0,     0,  3505,     0,  3207,  1030,     0,     0,     0,
       0,  3207,  3207,     0,  3207,  3207,  3207,  3207,  3334,  3335,
       0,  1473,  2755,  3207,     0,  2049,     0,     0,     0,     0,
       0,     0,    58,     0,     0,     0,     0,     0,     0,     0,
    1474,  1475,  2783,   637,     0,  3366,  2783,     0,     0,     0,
     405,  1476,     0,     0,   185,   482,  1477,     0,   483,     0,
      58,     0,     0,   405,     0,    58,     0,     0,     0,     0,
       0,     0,     0,  1909,    58,  3513,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  3205,     0,     0,  3205,
    3205,  3205,  3205,     0,     0,  1478,     0,  1027,     0,     0,
    3204,  3204,  3204,  3204,     0,     0,     0,     0,     0,  1309,
       0,     0,     0,  3398,     0,     0,     0,   185,     0,  2708,
       0,     0,     0,  2311,     0,     0,     0,  1479,  2884,  2708,
       0,  2243,  2243,     0,  3203,  3203,  3207,     0,  3203,  3207,
    3207,  3207,  3207,     0,     0,     0,     0,  2754,     0,  3427,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  2768,  2769,  2093,  2772,     0,     0,     0,
       0,     0,    58,  2243,     0,  1910,     0,     0,   484,  3205,
       0,     0,     0,  1911,  2793,     0,     0,     0,  3205,  1912,
     185,  1913,     0,   485,     0,  1030,     0,   486,     0,     0,
       0,     0,  1914,  1112,     0,     0,  1112,     0,     0,  1302,
       0,     0,  1302,     0,  1302,     0,  2708,     0,  1013,  1014,
    1015,     0,  1018,     0,     0,     0,     0,     0,     0,  3207,
    1915,     0,  1165,   487,     0,     0,     0,     0,  3207,  1044,
      58,  2275,  2276,     0,     0,     0,  1916,     0,  2292,     0,
    2835,  1917,  3642,     0,     0,     0,     0,     0,     0,     0,
       0,   488,     0,  1918,     0,     0,     0,     0,     0,     0,
    1919,     0,     0,     0,     0,  1068,     0,     0,  1302,   489,
       0,  1073,     0,  1075,     0,     0,     0,  1082,     0,     0,
    1082,     0,  3659,  1082,     0,     0,     0,     0,   405,     0,
       0,     0,    58,  1095,  3633,   459,   460,   461,   462,   463,
     464,   465,   466,   467,   468,   469,   470,   471,  1095,     0,
      58,     0,     0,     0,  1156,     0,     0,     0,     0,     0,
       0,  1018,  1169,  1172,     0,     0,     0,  1187,     0,   472,
       0,     0,     0,     0,     0,  1199,     0,     0,    58,   567,
       0,     0,  2903,  1302,  2904,     0,  2708,     0,     0,     0,
     490,  1223,     0,     0,     0,     0,     0,  1302,     0,  3203,
       0,     0,     0,     0,     0,  3203,  3203,     0,  3203,  3203,
    3203,  3203,     0,     0,  2708,     0,  2708,  3203,   182,  1302,
     471,  3204,  3204,     0,     0,  3204,     0,     0,     0,     0,
       0,     0,     0,  3642,     0,     0,     0,     0,     0,     0,
       0,     0,   472,     0,     0,     0,     0,     0,  1920,     0,
       0,     0,     0,  1921,    58,     0,   491,     0,     0,    58,
    1922,    58,     0,     0,  1221,     0,   473,   474,   475,   476,
     477,   478,     0,     0,     0,     0,     0,     0,     0,  2708,
       0,   648,  1923,     0,   479,   480,   481,  1924,     0,  2477,
    3463,     0,    58,  3463,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      58,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    3398,     0,     0,     0,     0,     0,  1302,     0,     0,  2518,
    3203,     0,     0,  3203,  3203,  3203,  3203,     0,  3653,   473,
     474,   475,   476,   477,   478,     0,  3086,     0,     0,  3091,
       0,     0,  3656,     0,     0,     0,     0,   479,   480,   481,
       0,     0,  1112,  1303,     0,  1303,  1302,     0,     0,     0,
       0,     0,     0,     0,     0,  1303,  1303,     0,     0,     0,
       0,     0,  1303,  1303,  1303,  1303,     0,    58,    58,    58,
      58,    58,    58,     0,     0,     0,     0,     0,     0,  3688,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1160,     0,     0,     0,  1223,     0,     0,
       0,     0,     0,  3203,   482,     0,     0,   483,     0,     0,
       0,     0,  3203,  1400,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  3204,     0,   472,     0,
       0,     0,  3204,  3204,     0,  3204,  3204,  3204,  3204,     0,
       0,     0,     0,     0,  3204,  1430,     0,  1302,     0,  3732,
       0,     0,     0,     0,   130,     0,     0,     0,     0,     0,
       0,     0,  3583,     0,     0,     0,     0,   482,     0,     0,
     483,     0,     0,     0,     0,  1458,  1458,  1458,     0,  1458,
       0,  1458,  1458,     0,     0,     0,     0,    63,    63,     0,
       0,     0,     0,   131,  3756,  3757,  3732,     0,     0,     0,
       0,     0,     0,     0,  1050,     0,     0,     0,     0,    58,
       0,  3767,   132,   133,     0,     0,     0,   484,     0,     0,
       0,     0,  1172,     0,     0,   473,   474,   475,   476,   477,
     478,     0,   485,     0,  1542,     0,   486,     0,     0,  1303,
       0,     0,     0,   479,   480,   481,     0,     0,     0,     0,
       0,     0,   134,     0,     0,     0,     0,  3204,  1223,  1400,
    3204,  3204,  3204,  3204,   135,     0,     0,  1894,     0,     0,
       0,     0,   487,     0,     0,   136,     0,     0,     0,     0,
       0,     0,     0,  1902,  1902,     0,  2824,  2825,     0,  3463,
     484,   137,     0,     0,     0,     0,     0,  2834,     0,     0,
     488,   138,     0,     0,     0,   485,     0,     0,     0,   486,
       0,     0,     0,     0,     0,     0,   139,     0,   489,     0,
       0,  2846,  2847,  2848,  2849,  2850,  2851,     0,     0,     0,
       0,  2856,  2857,  2858,  2859,     0,     0,     0,  2861,     0,
       0,     0,     0,     0,     0,   487,     0,     0,     0,     0,
    3204,  3370,  1303,     0,     0,     0,   140,     0,     0,  3204,
       0,  1303,     0,     0,  1303,  1303,  1303,  1303,     0,     0,
       0,     0,     0,   488,     0,     0,  1303,     0,     0,   141,
       0,     0,  2369,   482,     0,     0,   483,  3389,     0,     0,
       0,   489,     0,     0,   142,     0,     0,     0,     0,   490,
       0,   143,     0,     0,   144,     0,  1303,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    2913,  2914,     0,     0,     0,   145,     0,  2918,  2919,   146,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    63,   147,    63,
       0,  1172,  1082,     0,     0,     0,     0,     0,     0,  2097,
    1095,     0,     0,  1172,     0,   491,   148,  2108,     0,     0,
       0,     0,   490,     0,     0,     0,     0,     0,   185,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1223,
    1156,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1221,   484,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   485,     0,     0,     0,   486,     0,     0,     0,     0,
       0,     0,     0,     0,  2142,  1156,     0,    63,   491,     0,
    2149,  2151,   597,   456,   457,   458,     0,   459,   460,   461,
     462,   463,   464,   465,   466,   467,   468,   469,   470,   471,
       0,   487,     0,     0,     0,     0,     0,     0,     0,     0,
    2170,     0,     0,     0,     0,     0,     0,  3093,  3094,     0,
       0,   472,     0,     0,     0,     0,  3101,     0,     0,   488,
       0,     0,     0,     0,     0,  2197,     0,     0,     0,     0,
       0,     0,  3517,     0,     0,     0,     0,   489,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  2370,     0,
       0,     0,     0,  3135,  3136,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  3540,  2371,  2372,
    2373,     0,     0,     0,     0,     0,     0,     0,  1303,     0,
    3156,     0,  3158,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  2374,   473,   474,
     475,   476,   477,   478,     0,     0,     0,     0,   490,  2375,
       0,     0,     0,   269,     0,     0,   479,   480,   481,     0,
    2376,     0,   270,   271,     0,     0,  1303,     0,   272,   273,
     274,    33,     0,  3229,  3230,     0,  2377,  3231,  3232,  1303,
       0,  1303,     0,     0,     0,     0,  2378,     0,     0,     0,
       0,     0,  1303,   465,   466,   467,   468,   469,   470,   471,
       0,  2379,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   491,     0,     0,     0,     0,     0,
       0,   472,     0,     0,     0,  2809,   456,   457,   458,     0,
     459,   460,   461,   462,   463,   464,   465,   466,   467,   468,
     469,   470,   471,     0,  1303,     0,     0,     0,     0,  2380,
       0,     0,     0,   159,     0,     0,     0,     0,   275,     0,
       0,     0,     0,     0,   472,   160,     0,     0,     0,     0,
       0,     0,  3296,     0,     0,     0,     0,     0,     0,  2381,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  2382,
       0,     0,   161,     0,     0,     0,   482,     0,     0,   483,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    2383,     0,     0,     0,  2384,     0,     0,     0,   473,   474,
     475,   476,   477,   478,     0,     0,  3686,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   479,   480,   481,     0,
       0,     0,  2385,  1303,     0,     0,     0,     0,     0,     0,
       0,  2386,     0,  3363,     0,     0,     0,  3368,     0,     0,
       0,   473,   474,   475,   476,   477,   478,     0,     0,     0,
       0,     0,     0,     0,  1303,     0,  3376,     0,     0,   479,
     480,   481,     0,     0,    54,     0,   162,     0,  2229,  1223,
       0,     0,     0,     0,     0,  3387,     0,     0,     0,     0,
    1303,  1303,  1303,  1303,     0,   466,   467,   468,   469,   470,
     471,     0,     0,     0,     0,     0,     0,     0,     0,   484,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  3743,
       0,     0,   472,     0,   485,     0,     0,     0,   486,     0,
       0,     0,     0,     0,     0,  2279,     0,     0,     0,     0,
       0,     0,  1303,  1303,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1303,  1303,     0,  1303,     0,     0,  1303,
       0,  1303,     0,     0,   487,  1303,   482,     0,     0,   483,
       0,     0,     0,   163,     0,     0,     0,     0,   276,     0,
       0,  1050,  1050,  1050,     0,  1050,  1050,  1050,  1050,  1050,
    1050,     0,   488,     0,  1050,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   164,   482,
     489,     0,   483,     0,     0,     0,     0,     0,     0,   473,
     474,   475,   476,   477,   478,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   479,   480,   481,
       0,     0,   165,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   166,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   277,     0,     0,     0,     0,   278,     0,   279,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   484,
     167,   490,     0,     0,     0,   280,     0,     0,     0,     0,
       0,     0,   269,     0,   485,   168,     0,     0,   486,     0,
     281,   270,   271,   282,     0,     0,   283,   272,   273,   274,
      33,  1221,     0,     0,     0,   284,   170,     0,     0,     0,
       0,     0,   484,     0,     0,  2468,     0,  3538,     0,     0,
    3541,     0,     0,     0,   487,     0,     0,   485,     0,     0,
       0,   486,     0,     0,     0,     0,     0,   491,  1172,     0,
       0,     0,     0,     0,     0,   644,   285,     0,     0,     0,
     171,     0,   488,     0,     0,     0,     0,   482,   286,   154,
     483,  1303,  1303,     0,     0,  1303,     0,   487,  1156,   287,
     489,     0,     0,     0,     0,   172,     0,     0,     0,     0,
       0,     0,   159,     0,     0,     0,     0,   275,     0,     0,
       0,     0,     0,     0,   160,   488,     0,     0,     0,   288,
       0,     0,     0,     0,     0,  1172,  2574,  1172,     0,     0,
       0,  1018,     0,   489,     0,     0,     0,     0,     0,     0,
       0,   161,     0,     0,     0,     0,     0,     0,     0,     0,
    1303,     0,     0,  1303,     0,     0,  1303,     0,     0,  1303,
       0,  1303,     0,   174,     0,     0,  2620,     0,     0,     0,
     289,   490,   175,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   290,   291,  3631,     0,     0,     0,     0,     0,
     292,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     484,   293,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   490,   485,     0,     0,     0,   486,
       0,     0,     0,     0,     0,  1303,     0,     0,     0,     0,
       0,     0,     0,    54,     0,   162,     0,   491,  3660,  3661,
       0,  3663,     0,  3665,  3666,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   487,   176,   177,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     491,     0,     0,   488,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1303,   489,  1172,     0,     0,     0,  1172,     0,     0,  3716,
       0,  3717,     0,     0,  1303,  1172,  1303,     0,     0,     0,
       0,     0,  1303,  1303,     0,  1303,  1303,  1303,  1303,     0,
       0,     0,   163,   185,  1303,     0,  1303,   276,     0,     0,
    1172,     0,     0,     0,     0,  3729,     0,     0,     0,     0,
    1223,     0,  1303,     0,     0,     0,     0,     0,     0,  2808,
       0,     0,     0,  2811,     0,  3740,  3741,   164,     0,  3742,
       0,     0,  3744,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   490,     0,     0,     0,     0,     0,  2833,     0,
       0,     0,     0,   269,     0,     0,     0,     0,     0,     0,
       0,   165,   270,   271,     0,     0,     0,   269,   272,   273,
     274,    33,     0,   166,     0,     0,   270,   271,     0,     0,
       0,     0,   272,   273,   274,    33,     0,  1221,     0,     0,
       0,   277,     0,     0,     0,     0,   278,     0,   279,     0,
       0,     0,     0,  1303,     0,     0,     0,  1303,   491,   167,
    1303,  1303,  1303,  1303,   280,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   168,     0,     0,     0,     0,   281,
       0,     0,   282,     0,     0,   283,     0,     0,     0,  1303,
       0,     0,     0,  1303,   284,   170,     0,     0,     0,     0,
       0,     0,     0,   159,     0,     0,     0,     0,   275,     0,
       0,     0,     0,     0,     0,   160,     0,   159,     0,     0,
    2911,     0,   275,     0,     0,     0,     0,     0,     0,   160,
       0,     0,     0,     0,  1396,   285,     0,     0,     0,   171,
       0,     0,   161,     0,     0,     0,     0,   286,     0,     0,
    1303,     0,     0,     0,     0,     0,   161,     0,   287,  1303,
       0,     0,     0,     0,   172,     0,     0,   456,   457,   458,
       0,   459,   460,   461,   462,   463,   464,   465,   466,   467,
     468,   469,   470,   471,     0,     0,     0,     0,   288,     0,
       0,     0,     0,  1172,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1303,   472,   457,   458,     0,   459,
     460,   461,   462,   463,   464,   465,   466,   467,   468,   469,
     470,   471,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   174,     0,    54,     0,   162,     0,     0,   289,
       0,   175,     0,   472,     0,     0,     0,     0,    54,     0,
     162,   290,   291,     0,     0,     0,     0,     0,     0,   292,
       0,     0,     0,     0,  1172,     0,  1221,     0,     0,     0,
     293,     0,     0,     0,   269,     0,     0,     0,     0,     0,
       0,     0,     0,   270,   271,     0,     0,     0,     0,   272,
     273,   274,    33,     0,     0,   185,     0,     0,     0,  1172,
       0,     0,   473,   474,   475,   476,   477,   478,     0,     0,
       0,     0,     0,     0,  3126,     0,  1044,     0,  3130,     0,
     479,   480,   481,     0,     0,   176,   177,     0,     0,     0,
       0,  3141,     0,   163,     0,     0,   185,     0,   276,     0,
     473,   474,   475,   476,   477,   478,     0,   163,     0,     0,
       0,     0,   276,     0,     0,     0,     0,     0,   479,   480,
     481,     0,     0,  3161,  3163,     0,     0,     0,   164,     0,
       0,     0,     0,     0,   159,     0,     0,     0,     0,   275,
       0,     0,   164,     0,     0,     0,   160,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   165,     0,     0,     0,     0,     0,     0,  3227,
       0,     0,     0,   161,   166,     0,   165,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   166,     0,
       0,     0,   277,     0,     0,     0,     0,   278,     0,   279,
       0,     0,     0,     0,     0,     0,   277,     0,     0,     0,
     167,   278,     0,   279,     0,   280,     0,     0,     0,     0,
     482,     0,     0,   483,   167,   168,     0,     0,     0,   280,
     281,     0,     0,   282,     0,     0,   283,     0,     0,   168,
       0,     0,     0,     0,   281,   284,   170,   282,     0,     0,
     283,     0,     0,     0,     0,     0,     0,     0,   482,   284,
     170,   483,     0,     0,     0,    54,     0,   162,     0,     0,
    3290,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  3305,     0,     0,   285,     0,     0,     0,
     171,     0,     0,     0,     0,     0,     0,     0,   286,  3145,
     285,     0,     0,     0,   171,     0,     0,     0,     0,   287,
       0,  2771,   286,     0,     0,   172,     0,  2675,     0,     0,
       0,     0,     0,   287,     0,     0,  1278,  1279,  1280,   172,
       0,     0,   272,  1281,  1282,    33,     0,     0,     0,   288,
       0,     0,     0,   484,  1172,     0,     0,     0,     0,     0,
       0,     0,     0,   288,     0,     0,   185,     0,   485,     0,
       0,     0,   486,   584,   163,     0,     0,     0,     0,   276,
       0,     0,  1172,   130,     0,     0,     0,  1156,     0,     0,
       0,   484,     0,   174,     0,     0,  1223,     0,     0,     0,
     289,     0,   175,     0,     0,     0,   485,   174,   487,   164,
     486,     0,   290,   291,   289,     0,   175,     0,     0,     0,
     292,     0,   131,     0,     0,     0,   290,   291,     0,     0,
       0,   293,  1283,     0,   292,     0,   488,     0,     0,     0,
       0,   132,   133,   165,     0,   293,   487,     0,     0,     0,
       0,     0,     0,   197,   489,   166,     0,   198,     0,     0,
       0,  2985,  2986,     0,  2987,  2988,  2989,     0,     0,     0,
       0,     0,     0,   277,   488,     0,     0,     0,   278,     0,
     279,   134,     0,     0,     0,     0,   176,   177,     0,     0,
       0,   167,   489,   135,  1156,     0,   280,     0,     0,     0,
     176,   177,     0,     0,   136,     0,   168,     0,     0,     0,
       0,   281,     0,     0,   282,     0,     0,   283,     0,     0,
     137,     0,     0,     0,     0,     0,   284,   170,     0,     0,
     138,     0,     0,     0,   199,   490,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   139,     0,     0,     0,     0,
     200,   201,     0,     0,     0,     0,     0,     0,  1111,     0,
     202,     0,  3290,     0,  2990,     0,     0,   285,     0,     0,
       0,   171,  2991,   490,     0,     0,     0,     0,     0,   286,
       0,     0,     0,     0,     0,   140,     0,     0,     0,     0,
     287,     0,     0,     0,     0,     0,   172,     0,     0,     0,
       0,   491,     0,     0,     0,     0,  2992,     0,   141,     0,
       0,     0,     0,     0,     0,  2993,     0,     0,     0,     0,
     288,     0,     0,   142,  1172,     0,     0,     0,     0,     0,
     143,     0,     0,   144,     0,     0,     0,     0,     0,   491,
       0,     0,  1172,     0,  2994,  2995,     0,     0,     0,     0,
       0,     0,     0,     0,   145,     0,     0,     0,   146,     0,
       0,     0,  2676,     0,   174,     0,     0,     0,     0,     0,
    1156,   289,     0,   175,     0,     0,     0,   147,     0,     0,
       0,     0,     0,   290,   291,     0,     0,     0,     0,  2996,
       0,   292,     0,     0,     0,   148,     0,     0,     0,     0,
       0,     0,   293,     0,  1559,  1560,  1561,  1562,  1563,  1564,
       0,  1565,  1566,  1567,     0,     0,     0,  1568,  1569,  1570,
    1571,  1572,  1573,     0,     0,     0,  1284,     0,     0,     0,
       0,   203,  1574,  2997,     0,     0,     0,     0,  1285,     0,
       0,     0,     0,     0,     0,     0,  3290,     0,     0,     0,
       0,  3593,     0,  3595,  1575,     0,     0,   176,   177,     0,
       0,     0,     0,  1286,     0,     0,     0,     0,     0,     0,
     204,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1172,     0,     0,  2998,     0,   205,
     206,   207,   208,     0,  1287,     0,     0,  2677,     0,     0,
       0,     0,  1223,     0,     0,     0,     0,   209,   185,  2678,
    1289,  1576,     0,     0,     0,     0,     0,     0,     0,     0,
    1577,     0,     0,     0,     0,     0,     0,     0,     0,   210,
       0,     0,     0,     0,     0,     0,     0,  1987,  1578,  1579,
       0,   211,     0,     0,     0,     0,     0,  1580,     0,     0,
    1290,     0,   212,     0,  1581,  1582,     0,     0,  1583,  1584,
    1585,  1586,  1291,     0,  1587,  1588,     0,     0,   213,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   214,  1458,
    1458,  1458,  1458,  1458,  1458,     0,     0,     0,     0,     0,
       0,     0,     0,   215,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1292,  1589,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1590,     0,     0,     0,
       0,     0,  1591,   216,     0,     0,  1293,     0,  2200,  1592,
       0,  1593,  1294,     0,     0,     0,  1594,     0,     0,     0,
       0,  1295,  1296,     0,  1297,     0,   217,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1298,  1299,     0,     0,
       0,   218,  1595,     0,  1300,     0,     0,  1301,   219,     0,
       0,   220,     0,     0,     0,   293,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   221,     0,     0,     0,   222,     0,     0,     0,
    1596,     0,     0,  2999,  3000,  3001,  3002,  3003,  3004,  3005,
    3006,  3007,  3008,  1597,     0,   223,     0,     0,     0,  1598,
       0,  1223,     0,     0,     0,     0,     0,     0,  1599,  1600,
       0,     0,     0,   224,     0,  1601,     0,     0,  1602,  1603,
       0,     0,     0,  1604,     0,     0,     0,     0,     0,  1605,
    1606,     0,     0,     0,     0,     0,  1607,  1608,  1609,     0,
       0,  1610,  1611,  1612,     0,     0,     0,  1613,     0,     0,
       0,  1614,     0,  1615,     0,   225,     0,     0,     0,     0,
    1616,  1617,  1618,  1619,     0,  1620,  1621,     0,     0,     0,
    1622,  1623,     0,  1624,  1625,  1626,  1627,  1628,  1629,  1630,
       0,     0,     0,     0,     0,  1631,  1632,  1633,     0,  1634,
    1635,     0,     0,     0,  1636,  1637,  1638,  1639,  1640,  1641,
    1642,  1643,     0,  1644,     0,     0,     0,  1645,  1646,  1647,
    1648,  1649,  1650,  1651,  1652,  1653,  1654,  1655,  1656,  1657,
    1658,  1659,  1660,  1661,  1662,  1663,  1664,  1665,  1666,  1667,
    1668,  1669,  1670,  1671,  1672,  1673,  1674,  1675,  1676,  1677,
    1678,  1679,  1680,     0,  1681,  1682,     0,     0,  1683,  1684,
    1685,  1686,  1687,  1688,  1689,  1690,  1691,  1692,     0,  1693,
    1694,  1695,  1696,  1697,  1698,  1699,  1700,  1701,  1702,  1703,
    1704,  1705,  1706,  1707,     0,     0,  1708,  1709,  1710,  1711,
    1712,  1713,  1714,  1715,  1716,     0,  1717,  1718,  1719,  1720,
       0,  1721,  1722,  1723,  1724,  1725,  1726,  1727,  1728,  1729,
    1730,  1731,  1732,  1733,  1734,  1735,  1736,  1737,  1738,  1739,
    1740,  1741,  1742,  1743,  1744,  1745,  1746,  1747,  1748,  1749,
    1750,  1751,  1752,  1753,  1754,  1755,  1756,     0,  1757,  1758,
    1759,  1760,  1761,  1762,     0,     0,  1763,  1764,     0,  1765,
    1766,  1767,  1768,  1769,  1770,  1771,  1772,  1773,  1774,  1775,
    1776,  1777,  1778,  1779,  1780,  1781,  1782,  1783,  1784,  1785,
    1786,  1787,  1788,  1789,  1790,     0,     0,  1791,  1792,  1793,
    1794,  1795,  1796,  1797,  1798,  1799,  1800,  1801,  1802,  1803,
    1804,  1805,  1806,  1807,  1808,  1809,  1810,  1811,  1812,  1813,
    1814,  1815,  1816,  1817,  1818,  1819,  1820,  1821,  1822,  1823,
    1824,  1825,  1826,  1827,  1828,  1829,  1830,  1831,  1832,  1833,
    1834,  1835,  1836,  1837,  1838,  1839,  1840,  1841,  1842,  1843,
    1844,  1845,  1846,  1847,  1848,  1849,  1850,  1851,  1852,     0,
       0,     0,     0,  1853,  1854,  1855,  1856,  1857,  1858,  1859,
    1860,  1861,  1862,  1863,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1864,     0,     0,     0,     0,     0,
       0,     0,  1865,     0,     0,     0,     0,  1866,     0,     0,
       0,  1867,     0,     0,  1868,  1869,  1870,  1871,     0,     0,
    1872,  1873,     0,  1874,  1875,  1876,  1559,  1560,  1561,  1562,
    1563,  1564,     0,  1565,  1566,  1567,     0,     0,     0,  1568,
    1569,  1570,  1571,  1572,  1573,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1574,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1575,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1576,     0,     0,     0,     0,     0,     0,
       0,     0,  1577,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1578,  1579,     0,     0,     0,     0,     0,     0,     0,  1580,
       0,     0,     0,     0,     0,     0,  1581,  1582,     0,     0,
    1583,  1584,  1585,  1586,     0,     0,  1587,  1588,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1589,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1590,     0,
       0,     0,     0,     0,  1591,     0,     0,     0,     0,     0,
       0,  1592,     0,  1593,     0,     0,     0,     0,  1594,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1595,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1596,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1597,     0,     0,     0,     0,
       0,  1598,     0,     0,     0,     0,     0,     0,     0,     0,
    1599,  1600,     0,     0,     0,     0,     0,  1601,     0,     0,
    1602,  1603,     0,     0,     0,  1604,     0,     0,     0,     0,
       0,  1605,  1606,     0,     0,     0,     0,     0,  1607,  1608,
    1609,     0,     0,  1610,  1611,  1612,     0,     0,     0,  1613,
       0,     0,     0,  1614,     0,  1615,     0,     0,     0,     0,
       0,     0,  1616,  1617,  1618,  1619,     0,  1620,  1621,     0,
       0,     0,  1622,  1623,     0,  1624,  1625,  1626,  1627,  1628,
    1629,  1630,     0,     0,     0,     0,     0,  1631,  1632,  1633,
       0,  1634,  1635,     0,     0,     0,  1636,  1637,  1638,  1639,
    1640,  1641,  1642,  1643,     0,  1644,     0,     0,     0,  1645,
    1646,  1647,  1648,  1649,  1650,  1651,  1652,  1653,  1654,  1655,
    1656,  1657,  1658,  1659,  1660,  1661,  1662,  1663,  1664,  1665,
    1666,  1667,  1668,  1669,  1670,  1671,  1672,  1673,  1674,  1675,
    1676,  1677,  1678,  1679,  1680,     0,  1681,  1682,     0,     0,
    1683,  1684,  1685,  1686,  1687,  1688,  1689,  1690,  1691,  1692,
       0,  1693,  1694,  1695,  1696,  1697,  1698,  1699,  1700,  1701,
    1702,  1703,  1704,  1705,  1706,  1707,     0,     0,  1708,  1709,
    1710,  1711,  1712,  1713,  1714,  1715,  1716,     0,  1717,  1718,
    1719,  1720,     0,  1721,  1722,  1723,  1724,  1725,  1726,  1727,
    1728,  1729,  1730,  1731,  1732,  1733,  1734,  1735,  1736,  1737,
    1738,  1739,  1740,  1741,  1742,  1743,  1744,  1745,  1746,  1747,
    1748,  1749,  1750,  1751,  1752,  1753,  1754,  1755,  1756,     0,
    1757,  1758,  1759,  1760,  1761,  1762,     0,     0,  1763,  1764,
       0,  1765,  1766,  1767,  1768,  1769,  1770,  1771,  1772,  1773,
    1774,  1775,  1776,  1777,  1778,  1779,  1780,  1781,  1782,  1783,
    1784,  1785,  1786,  1787,  1788,  1789,  1790,     0,     0,  1791,
    1792,  1793,  1794,  1795,  1796,  1797,  1798,  1799,  1800,  1801,
    1802,  1803,  1804,  1805,  1806,  1807,  1808,  1809,  1810,  1811,
    1812,  1813,  1814,  1815,  1816,  1817,  1818,  1819,  1820,  1821,
    1822,  1823,  1824,  1825,  1826,  1827,  1828,  1829,  1830,  1831,
    1832,  1833,  1834,  1835,  1836,  1837,  1838,  1839,  1840,  1841,
    1842,  1843,  1844,  1845,  1846,  1847,  1848,  1849,  1850,  1851,
    1852,     0,     0, -2264,     0,  1853,  1854,  1855,  1856,  1857,
    1858,  1859,  1860,  1861,  1862,  1863,     0,     0,     0,     0,
   -2264, -2264, -2264,     0,     0, -2264,  1864, -2264, -2264,     0,
       0,     0,     0,     0,  1865,     0,     0,     0,     0,  1866,
       0,     0,     0,  1867,     0,     0,  1868,  1869,  1870,  1871,
       0,     0,  1872,  1873,     0,  1874,  1875,  1876,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0, -2264,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
   -2264,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0, -2264,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0, -2264,     0, -2264,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0, -2264,     0,     0,     0,     0,     0,     0, -2264,     0,
   -2264,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0, -2264,     0,     0,     0,     0, -2264,     0,     0,     0,
       0,     0,     0,     0, -2264,     0,     0,     0, -2264,     0,
       0,     0,     0,     0, -2264,     0,     0,     0, -2264, -2264,
   -2264, -2264,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0, -2264,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
   -2264,     0,     0, -2264,     0, -2264,     0,     0,     0,     0,
       0,     0, -2264,     1,     0,     0,     0,     2,     0,     0,
     679,   680,   681,     0,     0, -2264,     0,     0,     0,   682,
       0,     0,   683,     0,     0, -2264,     0,     0,     0,   684,
     685,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0, -2264, -2264,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0, -2264,     0,     0,     0,     0,     0,     0,     0, -2264,
       0,     0,     0, -2264,   686,   687,     0,     0,     0,   688,
       0, -2264, -2264, -2264,     0,     0,     0,     0,     0,   689,
     690,     0,   691,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   692,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   693,     0,     0,   694,   695,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   696,     0,   697,   698,   699,     0,     0, -2264,     0,
       0,     0,     0,   700,   701,     0,   702,   703,   704, -2264,
       0,     0,     0,     0,   705,     0,     0,   706,     0,   707,
     708,   709,     0,     0,     0,     0,     0,   710,     0,   711,
     712,     0,   713,     0,   714,   715,     0,     0,   716,     0,
       0,   717,   718,   719,   720,   721,   722,     0,     0, -2264,
     723,   724,   725,     0,   726,     0,     0,     0,   727,     0,
     728,   729,     0,     0,     0,     0,   730,     0,     0,   731,
       0,     0,   732,     0,   733,     0,   734,     0,   735,     0,
       0,     0,   736,   737,     0,   738,   739,   740,     0,     0,
     741,     0,   742,   743,     0,   744,     0,     0,     0,     0,
       0,     0,     0,   745,   746,     0,     0,     0,     0,     0,
   -2264,     0,     0,     0,     0,     0,   747,     0,     0,   748,
     749,     0,     0,   750,   751,     0,     0,   752,   753,     0,
       0,     0,     0,     0,     0,     0,   754,   755,   756,     0,
     757,     0,     0,     0,     0,     0, -2264,     0,     0,     0,
     758,   759,   760,     0,   761,     0,     0,     0,   762,   763,
       0,     0,     0,   764,     0,     0,     0,     0,     0,     0,
       0,   765,     0,     0,     0,     0,     0,     0,     0,   766,
     767,   768,     0,     0,     0,     0,     0,   769,   770,     0,
       0,     0, -2264,     0,     0,   771,     0,     0,   772,     0,
       0,     0,   773,   774,     0,     0, -2264, -2264, -2264, -2264,
   -2264, -2264, -2264,   775, -2264, -2264,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     776, -2264,     0,     0,     0,     0,     0,     0,   777,     0,
       0,     0,     0,     0,   778,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   779,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   780,     0,     0,
       0,     0,     0,   781,     0,   782,   783,     0,     0,     0,
       0,     0,     0,   784,     0,     0,     0,     0,   456,   457,
     458,     0,   459,   460,   461,   462,   463,   464,   465,   466,
     467,   468,   469,   470,   471,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   785,     0,     0,     0,   472,     0,     0,     0,
       0,     0,     0,   786,     0,     0,     0,     0,     0,     0,
     787,     0,     0,     0,     0,     0,     0,   456,   457,   458,
       0,   459,   460,   461,   462,   463,   464,   465,   466,   467,
     468,   469,   470,   471,   788,   789,     0,     0,     0,   790,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   791,     0,     0,     0,   472,     0,   792,   793,   794,
     795,     0,     0,     0,   796,     0,     0,     0,   797,     0,
       0,     0,     0,     0,     0,   798,   799,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   800,     0,   801,     0,
       0,     0,     0,   473,   474,   475,   476,   477,   478,   802,
       0,   803,     0,     0,   804,     0,     0,     0,     0,     0,
     805,   479,   480,   481,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   806,     0,     0,   807,
       0,     0,     0,     0,   808,     0,     0,   809,   810,     0,
       0,     0,   473,   474,   475,   476,   477,   478,     0,     0,
       0,     0,   811,     0,     0,     0,     0,     0,     0,   812,
     479,   480,   481,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   813,   814,   815,   816,   817,   818,   819,     0,
       0,   820,     0,   821,     0,   822,     0,   456,   457,   458,
       0,   459,   460,   461,   462,   463,   464,   465,   466,   467,
     468,   469,   470,   471,     0,     0,     0,     0,   456,   457,
     458,     0,   459,   460,   461,   462,   463,   464,   465,   466,
     467,   468,   469,   470,   471,   472,     0,     0,     0,     0,
       0,   482,     0,     0,   483,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   472,   456,   457,   458,
       0,   459,   460,   461,   462,   463,   464,   465,   466,   467,
     468,   469,   470,   471,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   472,     0,     0,     0,     0,
     482,     0,     0,   483,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   473,   474,   475,   476,   477,   478,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     479,   480,   481,   473,   474,   475,   476,   477,   478,     0,
       0,     0,     0,     0,   484,     0,     0,     0,     0,     0,
       0,   479,   480,   481,     0,     0,     0,     0,     0,   485,
       0,     0,     0,   486,   596,     0,     0,     0,     0,     0,
       0,     0,   473,   474,   475,   476,   477,   478,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     479,   480,   481,     0,     0,     0,     0,     0,     0,   487,
       0,     0,     0,   484,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   485,     0,
       0,     0,   486,   606,   456,   457,   458,   488,   459,   460,
     461,   462,   463,   464,   465,   466,   467,   468,   469,   470,
     471,     0,     0,     0,     0,   489,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   487,     0,
       0,     0,   472,     0,     0,     0,     0,     0,     0,     0,
     482,     0,     0,   483,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   488,     0,     0,     0,
       0,   482,     0,     0,   483,     0,     0,     0,     0,     0,
       0,   456,   457,   458,   489,   459,   460,   461,   462,   463,
     464,   465,   466,   467,   468,   469,   470,   471,     0,     0,
       0,     0,     0,     0,     0,     0,   490,     0,     0,     0,
     482,     0,     0,   483,     0,     0,     0,     0,     0,   472,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   473,
     474,   475,   476,   477,   478,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   479,   480,   481,
       0,     0,     0,     0,     0,   490,     0,     0,     0,     0,
       0,     0,   491,   484,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   485,     0,
       0,     0,   486,   970,   484,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   485,
       0,     0,     0,   486,   976,     0,   473,   474,   475,   476,
     477,   478,     0,     0,     0,     0,     0,     0,   487,     0,
       0,   491,     0,   484,   479,   480,   481,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   485,   487,
       0,     0,   486,   977,     0,     0,   488,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   489,     0,     0,   488,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   487,     0,
       0,     0,     0,     0,     0,   489,     0,   482,     0,     0,
     483,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   456,   457,   458,   488,   459,   460,   461,
     462,   463,   464,   465,   466,   467,   468,   469,   470,   471,
       0,     0,     0,     0,   489,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   472,   456,   457,   458,   490,   459,   460,   461,   462,
     463,   464,   465,   466,   467,   468,   469,   470,   471,     0,
       0,     0,     0,     0,   482,     0,   490,   483,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   456,   457,   458,
     472,   459,   460,   461,   462,   463,   464,   465,   466,   467,
     468,   469,   470,   471,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   490,     0,     0,     0,     0,
     484,   491,     0,     0,     0,   472,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   485,     0,     0,     0,   486,
     978,     0,   491,     0,     0,     0,     0,     0,   473,   474,
     475,   476,   477,   478,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   479,   480,   481,   467,
     468,   469,   470,   471,     0,   487,     0,     0,     0,     0,
       0,   491,     0,     0,     0,     0,     0,   473,   474,   475,
     476,   477,   478,     0,     0,   472,     0,   484,     0,     0,
       0,     0,     0,   488,     0,   479,   480,   481,     0,     0,
       0,     0,   485,     0,     0,     0,   486,   979,     0,     0,
       0,   489,   473,   474,   475,   476,   477,   478,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     479,   480,   481,     0,     0,     0,     0,     0,     0,   456,
     457,   458,   487,   459,   460,   461,   462,   463,   464,   465,
     466,   467,   468,   469,   470,   471,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     488,     0,     0,     0,     0,     0,     0,   472,     0,     0,
       0,     0,   473,   474,   475,   476,   477,   478,   489,     0,
       0,     0,   490,     0,     0,     0,   482,     0,     0,   483,
     479,   480,   481,     0,     0,     0,     0,     0,     0,     0,
       0,   458,     0,   459,   460,   461,   462,   463,   464,   465,
     466,   467,   468,   469,   470,   471,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   482,     0,     0,   483,     0,
       0,     0,     0,     0,     0,     0,     0,   472,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   491,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   490,
     482,     0,     0,   483,   473,   474,   475,   476,   477,   478,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   479,   480,   481,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   484,
     460,   461,   462,   463,   464,   465,   466,   467,   468,   469,
     470,   471,     0,     0,   485,   491,     0,     0,   486,     0,
     482,     0,     0,   483,   473,   474,   475,   476,   477,   478,
       0,     0,     0,   472,     0,     0,     0,     0,   484,     0,
       0,     0,   479,   480,   481,     0,     0,     0,     0,     0,
       0,     0,     0,   485,   487,     0,     0,   486,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   981,     0,     0,
       0,     0,     0,   484,     0,     0,     0,     0,     0,     0,
       0,     0,   488,     0,     0,     0,     0,     0,   485,     0,
       0,     0,   486,   487,     0,     0,     0,     0,     0,     0,
     489,     0,     0,     0,     0,     0,   982,  2675,     0,     0,
       0,     0,   482,     0,     0,   483,  1278,  1279,  1280,     0,
       0,   488,   272,  1281,  1282,    33,     0,     0,   487,     0,
     473,   474,   475,   476,   477,   478,     0,     0,     0,   489,
       0,   985,     0,   484,     0,     0,     0,     0,   479,   480,
     481,     0,     0,     0,     0,     0,   488,     0,   485,     0,
       0,     0,   486,   461,   462,   463,   464,   465,   466,   467,
     468,   469,   470,   471,   489,     0,     0,     0,     0,     0,
       0,   490,   482,     0,     0,   483,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   472,     0,     0,   487,   462,
     463,   464,   465,   466,   467,   468,   469,   470,   471,     0,
       0,     0,  1283,     0,     0,     0,     0,     0,     0,     0,
     490,     0,     0,     0,     0,     0,   488,     0,     0,     0,
     472,     0,     0,     0,     0,   484,   464,   465,   466,   467,
     468,   469,   470,   471,   489,     0,     0,   491,     0,     0,
     485,     0,     0,     0,   486,   490,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   472,     0,     0,     0,     0,
       0,     0,     0,   463,   464,   465,   466,   467,   468,   469,
     470,   471,     0,     0,     0,     0,   491,     0,   482,     0,
     487,   483,   473,   474,   475,   476,   477,   478,     0,     0,
    1278,  1279,  1280,   472,     0,   484,   272,  1281,  1282,    33,
     479,   480,   481,     0,     0,     0,     0,     0,   488,     0,
     485,   491,     0,     0,   486,   490,     0,   473,   474,   475,
     476,   477,   478,     0,     0,     0,   489,     0,  1111,     0,
       0,     0,     0,     0,     0,   479,   480,   481,     0,     0,
    1278,  1279,  1280,     0,     0,     0,   272,  1281,  1282,    33,
     487,     0,   473,   474,   475,   476,   477,   478,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     479,   480,   481,     0,     0,     0,     0,     0,   488,     0,
       0,   491,     0,     0,     0,     0,  1283,     0,     0,     0,
     473,   474,   475,   476,   477,   478,   489,  1278,  1279,  1280,
       0,   484,     0,   272,  1281,  1282,    33,   490,   479,   480,
     481,     0,     0,     0,     0,     0,   485,     0,     0,     0,
     486,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  2676,     0,     0,     0,  1283,     0,     0,     0,
     482,     0,     0,   483,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   487,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   980,
       0,     0,     0,   491,     0,   482,     0,   490,   483,     0,
       0,     0,     0,     0,   488,     0,     0,     0,     0,     0,
       0,     0,     0,  1283,     0,     0,  1284,     0,     0,     0,
       0,     0,   489,     0,     0,     0,     0,     0,  1285,     0,
     482,     0,  1111,   483,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1286,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   491,     0,     0,  3187,  3188,   482,     0,
       0,   483,   272,  1281,  1282,    33,     0,     0,     0,     0,
       0,     0,  1111,   484,  1287,     0,     0,  2677,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   485,  2678,
    1289,     0,   486,   490,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   484,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   485,     0,     0,  2676,   486,   487,  1111,
    1290,     0,     0,     0,     0,     0,     0,     0,     0,  1278,
    1279,  1280,  1291,   484,     0,   272,  1281,  1282,    33,     0,
       0,     0,  3189,     0,     0,     0,   488,     0,   485,   491,
       0,     0,   486,   487,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   489,     0,     0,     0,     0,     0,
       0,   484,     0,  1292,     0,     0,     0,     0,     0,     0,
    1284,   488,     0,     0,     0,     0,   485,     0,   487,     0,
     486,     0,  1285,     0,     0,  1278,  1279,  1280,     0,   489,
       0,   272,  1281,  1282,    33,     0,  1293,     0,     0,     0,
       0,     0,  1294,     0,     0,     0,   488,  1286,     0,     0,
       0,  1295,  1296,     0,  1297,  1283,   487,     0,     0,     0,
    1284,     0,     0,     0,   489,     0,  1298,  1299,     0,     0,
       0,     0,  1285,     0,  1300,   490,     0,  1301,  1287,     0,
       0,  2677,     0,     0,   488,   293,     0,     0,     0,     0,
       0,     0,     0,  2678,  1289,     0,     0,  1286,  1111,     0,
       0,     0,   489,     0,     0,     0,  1278,  1279,  1280,     0,
     490,     0,   272,  1281,  1282,    33,     0,  1284,     0,     0,
       0,  1283,     0,     0,     0,     0,     0,     0,  1287,  1285,
       0,  1288,     0,     0,  1290,     0,     0,     0,     0,     0,
       0,   491,     0,     0,  1289,   490,  1291,     0,     0,     0,
       0,     0,     0,     0,  1286,     0,  3187,  3188,     0,     0,
       0,     0,   272,  1281,  1282,    33,     0,     0,     0,     0,
       0,  1987,     0,     0,     0,     0,   491,     0,     0,     0,
       0,  1111,     0,   490,  1290,  1287,     0,  1292,  1288,     0,
       0,     0,     0,     0,     0,     0,  1291,     0,     0,     0,
       0,  1289,  1283,  1280,     0,     0,     0,   272,  1281,  1282,
      33,   491,     0,     0,     0,     0,     0,     0,     0,     0,
    1293,     0,     0,     0,     0,     0,  1294,     0,     0,     0,
       0,     0,     0,     0,     0,  1295,  1296,  1292,  1297,     0,
    2512,  1290,     0,     0,     0,     0,     0,  1111,     0,   491,
    1298,  1299,  3189,  1291,     0,     0,  3187,  3188,  1300,     0,
       0,  1301,   272,  1281,  1282,    33,  1284,     0,     0,   293,
    1293,     0,     0,     0,     0,     0,  1294,     0,  1285,     0,
       0,     0,     0,     0,     0,  1295,  1296,     0,  1297,     0,
       0,     0,     0,     0,  1292,     0,     0,  1283,     0,     0,
    1298,  1299,     0,  1286,   272,  1281,  1282,    33,  1300,     0,
       0,  1301,     0,     0,     0,     0,     0,     0,     0,   293,
       0,     0,     0,     0,     0,     0,     0,  1293,  1111,     0,
       0,     0,     0,  1294,  3190,     0,     0,  3191,     0,     0,
       0,     0,  1295,  1296,     0,  1297,     0,     0,     0,  1284,
    3192,     0,  3189,     0,     0,     0,     0,  1298,  1299,     0,
       0,  1285,     0,     0,     0,  1300,     0,     0,  1301,     0,
       0,     0,     0,     0,     0,     0,   293,     0,  1111,     0,
       0,     0,     0,     0,     0,     0,  1286,     0,     0,  3193,
    3194,     0,     0,     0,  3189,     0,     0,     0,     0,     0,
       0,     0,  3195,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1284,     0,  1287,     0,     0,
    1288,     0,     0,  1111,     0,     0,     0,  1285,     0,     0,
       0,     0,     0,  1289,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  3196,     0,     0,     0,     0,     0,     0,
       0,     0,  1286,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  3639,  1290,     0,     0,     0,     0,  1111,     0,
       0,     0,  3197,  1287,     0,  1291,  1288,  2543,  2544,  2545,
    2546,  2547,  2548,     0,  3198,     0,  1284,     0,     0,  1289,
       0,     0,     0,     0,     0,     0,  3199,  3200,  1285,     0,
       0,     0,     0,     0,  3201,     0,     0,  3202,     0,     0,
    1111,     0,     0,     0,     0,   293,  1292,     0,     0,     0,
       0,     0,     0,  2310,     0,     0,     0,     0,     0,  1290,
       0,     0,     0,     0,     0,     0,  1284,     0,     0,     0,
       0,  1291,     0,     0,     0,     0,     0,     0,  1285,  1293,
       0,     0,     0,     0,  1287,  1294,     0,  1288,     0,     0,
       0,     0,     0,     0,  1295,  1296,     0,  1297,     0,     0,
    1289,     0,     0,  1286,  2549,     0,     0,     0,     0,  1298,
    1299,  1284,  1292,     0,     0,     0,     0,  1300,     0,     0,
    1301,     0,     0,  1285,     0,     0,     0,     0,   293,     0,
       0,     0,     0,     0,  3190,     0,     0,  3191,     0,     0,
    1290,     0,     0,     0,     0,  1293,     0,     0,  1286,     0,
    3192,  1294,  1291,     0,     0,     0,     0,     0,     0,     0,
    1295,  1296,     0,  1297,     0,     0,  1284,     0,     0,     0,
       0,     0,     0,     0,     0,  1298,  1299,  1987,  1285,  1287,
       0,     0,  1288,  1300,     0,     0,  1301,     0,     0,     0,
    3194,     0,     0,  1292,   293,  1289,     0,     0,     0,     0,
       0,     0,  3195,  1286,     0,     0,     0,     0,  1284,  3610,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1285,     0,     0,     0,     0,     0,  1293,     0,     0,     0,
       0,     0,  1294,     0,  3190,  1290,     0,  3191,     0,     0,
       0,  1295,  1296,  3196,  1297,  1286,     0,  1291,     0,     0,
    3192,     0,     0,     0,     0,     0,  1298,  1299,     0,     0,
       0,     0,     0,     0,  1300,     0,  3611,  1301,     0,     0,
       0,     0,     0,     0,     0,   293,  3190,     0,     0,  3191,
       0,     0,  3197,     0,     0,     0,     0,     0,  1292,     0,
    3194,  3612,  3192,     0,  3198,     0,     0,     0,     0,     0,
    3613,     0,  3195,     0,     0,     0,  3199,  3200,     0,     0,
       0,     0,     0,     0,  3201,     0,     0,  3202,     0,     0,
       0,  1293,     0,     0,     0,   293,     0,  1294,     0,     0,
       0,     0,  3194,     0,     0,     0,  1295,  1296,  3614,  1297,
       0,  2550,     0,  3196,  3195,     0,  3615,     0,     0,     0,
       0,  1298,  1299,     0,  2551,     0,     0,     0,     0,  1300,
       0,     0,  1301,     0,     0,     0,     0,     0,     0,     0,
     293,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  3197,     0,     0,  3196,     0,     0,     0,     0,
       0,     0,     0,     0,  3198,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  3199,  3200,     0,     0,
       0,     0,     0,     0,  3201,     0,  2552,  3202,     0,     0,
       0,     0,  2553,     0,  3197,   293,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  3198,  3616,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  3199,  3200,
       0,     0,     0,     0,     0,     0,  3201,     0,     0,  3202,
       0,  2554,     0,     0,     0,     0,     0,   293,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  2555,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  2556,  2557,     0,     0,     0,
       0,  2558,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  2559,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  2560,     0,     0,  2561,  2562,     0,     0,
       0,  2563,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  2564,     0,
       0,     0,     0,     0,     0,     0,     0,  3617,     0,  2565
};

static const short yycheck[] =
{
       3,     4,     5,   188,   105,     8,   394,  1048,   995,   169,
     652,  1126,    45,   587,   125,  1161,  1451,  1278,  1279,  1166,
     636,  1366,  1123,  1141,   259,   260,   792,   544,  1359,    54,
    1122,   257,   258,  2345,  1921,  2347,  2109,    40,   264,  1137,
    1138,  2362,  1140,   594,  1142,  1143,   171,  1886,  1887,    52,
    1313,    54,  1315,  1996,  1997,  1998,  1999,    90,  2308,  2655,
    2360,  2499,    65,  1989,  1391,    20,   776,   570,   169,    72,
       5,   794,    27,    76,  2057,  1409,    79,    80,  2897,  2898,
    2899,    84,    85,    69,     5,    26,    27,   188,    25,  2054,
      27,    27,   715,  2048,    27,   751,   712,     5,  2232,    27,
    1987,   104,     5,    20,  2542,     5,  2617,   723,    25,    27,
      27,     5,    19,    19,  1215,    25,    26,    27,   121,   688,
      26,   124,     5,     8,   235,   236,   129,     5,  1229,  2431,
     116,     5,     5,  1248,    27,     5,   261,    19,     5,   149,
     265,  2670,   267,  2672,   269,   270,   271,    27,    27,   112,
     112,   720,   721,   278,     5,    27,  2900,   282,   283,    27,
     320,   147,   778,    19,    24,   781,    26,   782,    24,    25,
      26,     5,    19,    25,   790,    27,     9,    10,  1219,    12,
      13,    14,    15,    16,    17,  2982,    24,   190,    26,   812,
      19,     5,    24,    25,    26,    27,  2356,  2357,  2358,     5,
      43,  2361,     5,   772,    24,    25,    26,    27,    27,    58,
     131,   132,  2538,    24,    25,    26,    27,     5,    25,   320,
      27,     6,    26,   324,    24,    25,    26,    27,     5,   232,
      19,    24,    25,    26,    27,   238,     5,   223,    25,   225,
      27,    24,    25,    26,    20,    19,     5,   250,   286,    25,
      25,    27,    27,   256,   257,   258,   259,   260,    25,   440,
      27,   264,    27,  2244,  2424,     5,     5,   118,     6,   120,
      27,   122,  2198,     6,     5,    23,   187,     5,   200,   224,
      23,   594,   211,     5,     5,   193,   135,   136,   324,    25,
       5,    27,   140,   479,   137,   138,  1148,  1149,   345,   240,
     332,     5,   285,    27,    45,     0,   431,   391,   479,   434,
     313,   314,     5,   345,  1406,    95,    96,    97,    98,    99,
     323,   507,   279,   115,   507,   507,   451,   452,   453,   454,
     515,   456,   457,   458,   459,   460,   461,   462,   463,   464,
     465,   466,   467,   468,   469,   470,   471,   472,   391,    90,
     576,   332,   665,     5,  2604,   341,  2677,     5,   483,   484,
    2433,   347,  1508,   488,   345,   490,     9,    10,   594,    12,
      13,    14,    15,    16,    17,     5,   321,   455,   695,     5,
     505,   506,   507,   508,     5,     5,    10,   512,   240,     5,
     442,     5,   686,   687,  2337,   104,   105,   691,   692,  2635,
      18,    19,    20,    21,    22,   442,     5,   479,   240,  1450,
     704,   659,  1122,    30,   515,   401,   479,    34,   578,   298,
     240,   324,   396,     5,   670,   134,   135,   136,  2588,   240,
     724,   478,    56,   727,   506,     5,   507,   474,  2598,   733,
     240,   540,   586,   737,   761,   294,   478,   741,   486,   548,
      31,   745,   213,   240,   324,   749,   750,    25,   752,    27,
    1183,   755,   201,   757,   758,   759,   651,  2703,   479,   302,
      29,   765,     5,   240,   768,     5,  1045,   578,   724,     5,
     201,   775,     5,     5,   667,   667,   103,     5,   782,     5,
       5,   635,     5,   110,     5,   789,   507,   478,  1067,   333,
       5,   504,   673,  2829,   240,     5,   800,     5,   426,     5,
     804,     5,   545,   546,   808,    27,   240,   200,     5,    27,
     814,   401,   401,   817,    28,   706,   489,   686,   687,   405,
     586,   514,   324,  2693,   537,   442,   284,   540,   114,   156,
     157,   284,   626,   769,     5,   548,     5,   164,   534,     5,
     651,  3348,   787,   788,    18,    19,    20,    21,    22,     5,
     442,     5,   565,     5,   567,   724,     5,     5,   727,     5,
     553,     5,   575,   576,   298,   674,   579,     5,   737,   635,
     616,   816,   741,   626,   819,   637,   745,     5,     5,   422,
     423,   594,     5,   752,     5,   442,   667,  2436,   757,     5,
     759,     5,     5,   435,   396,  2586,   765,   479,   549,   768,
     673,     5,     5,   442,     5,     5,   775,     5,    27,  2931,
    2870,     5,     5,   782,   557,   445,   440,   590,   590,   333,
     789,    23,  1247,   643,   445,   396,   401,  2797,   442,   519,
     519,   800,   664,   511,   477,   804,  1498,   604,   440,   808,
    2971,   562,   574,   442,   442,   814,  1173,   442,   817,   302,
     479,   602,   445,   385,   593,   442,   587,   213,   442,   643,
     413,   674,   475,   442,  3185,    10,   679,   680,   681,   682,
     683,   684,   685,   442,  3122,   688,   689,   690,  2575,  1412,
     693,   609,   695,  3437,   425,   698,  1406,   700,    27,  1273,
    1274,  1424,  3140,   535,   442,  2036,   709,   601,   519,   442,
    1352,   594,  2057,   616,   436,  3226,   601,   720,   721,  3248,
     594,   968,  2882,   292,   417,   598,   604,   730,   664,   872,
     637,   637,  2866,   736,  3046,   475,  3048,   604,  3038,   742,
     743,   744,   659,    27,   637,   748,   616,   475,   751,   659,
     753,   754,  2086,   674,  2088,   637,   664,  1413,   761,   714,
     475,   764,  2745,  1266,  2199,   665,   769,   770,  3068,   772,
    2725,   604,   624,   776,   709,   716,   779,   714,  2743,   422,
     423,   714,   785,   519,   787,   788,   714,   295,   563,   792,
     793,   794,   598,  3095,   503,   798,   714,  3099,   801,   442,
     308,   418,    27,   806,   545,  2132,  3402,   667,   637,   502,
     813,   667,   815,   816,   665,   818,   819,  1386,   821,   822,
    3416,   670,   673,   475,   616,   518,  1395,   475,   442,   667,
     673,   598,  1126,   410,   477,   667,  3655,   670,   686,   687,
     688,   689,   690,   442,    30,   475,   633,   667,    34,   475,
     396,   631,   659,  1422,   475,   475,   667,   475,   983,   475,
     442,   986,   438,  2286,   188,   189,  2289,   667,   561,   994,
     995,   155,   442,  3033,   667,  3035,  1293,  1265,  1295,  1296,
     589,   393,  2584,   659,   667,   461,   295,   720,   721,   401,
     402,   574,   284,    25,    27,   667,   513,   376,    25,   308,
      27,    27,   410,    30,   696,   697,   698,   600,     5,   442,
     624,   479,   442,   342,   426,   707,   442,   429,   376,   442,
     442,   205,   925,   632,   442,   354,   442,   442,  1544,   442,
     410,   442,  3244,   445,  3246,  3247,   629,   442,   383,   125,
    2779,   448,   442,     5,   442,   638,   442,   524,   442,   507,
     664,  3547,  1246,  1247,  1248,   442,   240,   442,   242,  3397,
    3211,   604,  3274,    14,   299,   968,   295,  1126,   544,   570,
    2896,  2897,  2898,  2899,   442,   256,   257,   258,  1529,   308,
    2960,   442,  2962,   442,  2358,  2965,   442,  2361,   605,    18,
      19,    20,    21,    22,    26,    27,   442,     0,   442,  1516,
     442,   410,  1145,   442,   442,  1008,   442,  1010,   442,  1152,
    3331,   475,  3172,    16,   442,   240,   524,  1003,   405,   709,
    2138,   413,  3182,   391,   442,   442,   586,   670,    25,   442,
      27,   442,   540,  2125,    26,    27,   442,   549,   442,   442,
     730,  1288,  1045,   411,   524,  1048,   592,  2310,   442,   442,
     529,   442,   442,   743,   442,   339,   633,   519,   442,   442,
     636,  1064,   417,  2408,  1067,   527,     5,  2412,   685,     8,
     479,   529,   648,   649,   479,   635,   693,   720,   721,   625,
     656,   410,    25,   672,    27,  2186,   163,  1246,  1247,  1248,
     602,   369,   295,    26,    27,   227,   214,   609,   216,    25,
     286,    27,   437,  1106,   439,   308,   695,   240,  1111,  3269,
     479,  2374,  2375,   240,   240,   524,    25,   562,    27,  1122,
      25,  3442,    27,   241,   408,    25,   633,    27,   573,   636,
     479,   540,   416,  1136,  1137,  1138,   420,  1140,  3255,  1142,
    1143,  3258,    28,    29,  3261,  1148,  1149,   502,   479,    25,
     479,    27,   637,   633,    26,    27,  3406,  2272,   479,   286,
     637,   485,    25,   518,    27,   637,  3417,  3418,   449,   637,
    2872,  2873,   456,  3546,    25,  3429,    27,  3550,  1181,    25,
    1183,    27,   659,    25,  2171,    27,  3440,   659,   208,  1192,
    1425,    20,  1195,   672,   288,   524,   507,  1200,    27,  2622,
     474,  1427,   320,  3535,  3536,   323,   561,   410,   240,   529,
     435,   540,   691,   692,   672,   479,  1219,  1220,    26,    27,
     479,   407,   354,   417,   295,  1228,   479,   345,   360,   361,
     362,   479,   711,   691,   692,    26,    27,   308,   522,   666,
     479,  1244,  1245,   240,  1355,   600,   673,  1358,   240,  3409,
     382,   345,   800,   711,    26,    25,   804,    27,   626,    19,
     808,  3187,  3188,   479,    24,  3191,    26,  1270,   479,   455,
    2896,  2897,  2898,  2899,   629,  1278,  1279,   561,   815,  1439,
     407,   818,  3262,   638,   821,  1288,   479,  3174,   308,  1524,
    1525,  3603,    20,  3625,    25,  3627,    27,   240,  1301,    27,
     486,   585,   435,  1529,   479,   399,  1309,   240,   502,   403,
      40,    41,    42,   479,   240,    45,    20,    47,    48,   479,
     214,   524,   216,    27,   518,    20,   346,   217,   479,   515,
    3256,   240,    27,  3259,    24,   240,    26,   540,  1439,   410,
     240,  1910,  3502,  1912,  1913,   629,  3191,  1916,  1917,    25,
      26,  3468,   672,  1922,   638,   487,  1381,  1360,   490,   486,
     478,  1364,  1365,  1366,   240,   479,   498,   561,   240,   506,
     507,   691,   692,  1376,  1377,  1378,  2522,   240,  1381,  1382,
    1383,  1384,  1385,  1386,   478,   507,  2717,   759,   515,   240,
     410,   711,  1395,  2656,   240,  2658,   768,  2660,   240,   417,
    2745,   533,    26,  1406,   424,  1408,   600,  1410,   479,  1412,
    1413,   479,    25,   442,    27,  2125,   387,  1420,  1421,  1422,
    2461,  1424,  1425,    20,  1427,  1428,   320,   398,    26,   323,
      27,   479,   240,  1436,  2003,   629,   568,   479,   722,   723,
    1443,  1444,   814,   479,   638,   817,  2169,  1450,  1451,   240,
     672,   345,   288,   524,   479,   587,   588,    25,   479,    27,
     288,  2077,   479,    20,   506,   507,   598,    20,   479,   540,
      27,   603,   694,   695,    27,  2590,  2242,   448,  3421,   479,
    3423,  3424,  3425,  3426,   502,   506,   507,   717,   718,   719,
      20,   462,  1495,  1496,  3420,  1498,  3422,    27,  1501,  1502,
     518,  2616,  3428,  3429,   524,  3431,  3432,  3433,  3434,   345,
     642,   716,   479,  2236,  3440,   479,   672,   345,    19,  1522,
     540,  1524,  1525,    24,    25,    26,  1529,   569,  1531,   686,
    1533,  1534,   689,   690,  3607,   740,    26,  2160,   694,   695,
     430,   479,   674,   561,    59,    60,    61,    62,   569,    18,
      19,  3624,   479,  1556,   444,  2124,   417,    26,    27,   687,
     688,  3187,  3188,   399,    25,  3191,    27,   403,  1146,  1147,
     673,   399,  1150,  1151,   673,   403,   214,  3422,   216,    26,
     551,   786,   600,  3428,   478,    26,  3431,  3432,  3433,  3434,
     320,   796,   417,   323,   799,   325,   487,   487,   803,   479,
      24,  3674,    26,   241,   809,   479,   811,   498,   498,   151,
     152,   629,   159,   160,   161,   345,    26,    25,  3691,    27,
     638,    25,   507,    27,    25,   355,    27,  3553,   519,   519,
    3556,  3557,  3558,  3559,   667,   526,   526,  2154,   210,   417,
     109,   502,   478,   534,   534,    24,   376,    26,  1883,  1884,
     478,   574,   121,   225,   226,   479,   417,   518,    26,  3585,
    2761,    25,   234,    27,   479,   556,   556,   182,    25,   399,
      27,   469,    25,   403,    27,   190,  1408,   502,  1410,   148,
     479,  2250,   320,  3118,   199,   323,   479,   202,  2806,   479,
    2413,  2838,   479,   518,  2417,   479,   268,   479,  2959,  2960,
     561,  2962,  2803,  2426,  2965,   277,   111,   345,  3553,   506,
     507,  3556,  3557,  3558,  3559,   479,  2862,   727,    25,    26,
    3646,   689,   690,    26,   502,   479,  2300,   507,  2451,  3655,
     245,   741,    26,  3078,   306,   745,   561,   252,    26,   600,
     518,   502,  1989,   633,  1991,    25,    26,   757,   478,   639,
     696,   697,   637,    26,  2001,  2002,    26,   518,  2327,   696,
     697,  2008,  2009,  2010,  2011,    26,   337,   338,   629,  2735,
    2736,   240,    26,   242,   659,   600,   108,   638,   667,   351,
     442,   186,   667,   561,   190,  3187,  3188,   479,   194,   412,
    3225,    26,   667,  2409,   309,   442,  3422,   479,   479,     5,
     561,  3646,  3428,  3429,   629,  3431,  3432,  3433,  3434,   475,
     479,   442,   442,   638,  3440,   660,   661,   662,   663,   334,
    2114,   442,   600,   395,   442,   519,   341,  2814,   343,    18,
      19,    20,    21,    22,   479,  2822,  2823,   479,   353,   600,
     478,   673,  1953,   248,    20,   250,  2462,    20,   442,     5,
     479,   629,   479,   507,  2423,  1060,    26,    40,    41,    42,
     638,   266,    45,    26,    47,    48,   381,   671,   629,   274,
     339,   692,   667,   278,   389,   442,   186,   638,   442,  1882,
    1883,  1884,   308,   704,   475,   412,  1889,  1890,    20,   295,
      20,    21,    30,    26,   637,  2511,  2131,  2022,   303,    26,
      26,    26,    26,    26,    26,   374,  1909,  1910,    26,  1912,
    1913,   426,   733,  1916,  1917,    26,  1919,   442,   442,  1922,
    2031,   442,   442,   442,    26,     5,   442,  3553,   749,   750,
    3556,  3557,  3558,  3559,   755,   450,    20,   758,   248,   408,
     250,    26,   479,  1946,    26,  2239,   667,    26,  2195,    26,
     442,   420,     5,   442,  1957,  2114,   266,   673,    26,   442,
     352,  1166,   442,   442,   274,   442,  3401,   442,   278,  1174,
     671,  1176,   487,     5,    20,    21,   442,   442,  2272,   289,
     479,    26,   673,   498,   442,   637,  1989,   456,  1991,   673,
    2216,  2217,   442,   303,    25,    25,  2231,    25,  2001,  2002,
    2003,  3262,   471,  2006,  2573,  2008,  2009,  2010,  2011,   442,
     479,   141,   142,   143,   144,   145,   146,    25,  2021,   442,
    3646,   442,   442,   492,   442,   442,   442,   442,  2153,  3655,
     352,   442,   671,  2602,   667,   442,   479,     8,   672,   442,
    2043,  2027,  2765,   442,   186,  2048,  2171,   442,   667,  2618,
     475,  2054,   316,   527,  2057,    18,    19,    20,    21,   643,
     508,  2308,     5,   665,   665,   643,   508,   536,   667,   469,
    2317,   706,  2075,  2320,  2321,  2322,  2323,  2800,  2081,   507,
    2239,   596,   597,   598,   706,   378,  3127,   667,   644,   659,
       5,   469,   561,     5,   609,   141,   142,   143,   144,   145,
     146,  2670,   479,  2672,   479,   479,   248,  2110,   250,   479,
     479,   396,   626,  2272,   637,     8,   585,    18,    19,    20,
      21,  2124,  2125,    14,   266,  2128,  2129,   623,  2131,     5,
     706,     5,   274,   706,   469,   479,   278,   320,   479,    26,
     323,    26,   325,  2146,  3131,   115,   140,   507,    26,   667,
     637,   479,    50,    51,    52,    53,    54,    55,   479,   479,
     629,   303,   345,   479,  2167,   479,  2169,   479,   970,   638,
     479,   973,   355,   975,   976,   977,   978,   979,   141,   142,
     143,   144,   145,   146,   479,   469,    26,  2190,   479,  2192,
    2193,     5,  2195,   376,   507,  2198,  2199,   712,   479,   643,
     479,   479,     5,   673,   479,    43,  3352,   479,   672,  1414,
    1415,  1416,   709,  2216,  2217,  3361,   399,   673,   402,   604,
     403,     5,    18,   203,   664,    19,  1431,   434,  2231,  2798,
      25,   670,  3378,  2236,  2237,  2238,   626,   667,   530,  2242,
     141,   142,   143,   144,   145,   146,   637,  2250,   530,   147,
       5,   594,   201,   722,   723,   594,    26,   449,   373,  2676,
     594,  2678,    26,   442,   479,   442,   519,   442,    40,    41,
      42,   673,   574,    45,  2277,    47,    48,   673,   667,   479,
     442,   479,  2285,  2286,  2444,   479,  2289,   107,   479,   479,
    2584,     5,   711,   442,  1499,   478,  2590,   637,   594,   637,
     667,   667,   664,     5,     5,  2308,     5,   479,   714,   715,
     673,     5,  1517,   667,  2317,   531,   627,  2320,  2321,  2322,
    2323,  2324,  2616,   673,  2327,   672,  3441,   479,  2331,  2332,
    1535,     5,  2335,     8,    26,    26,   369,   115,   268,   377,
       5,  1546,     5,  2444,   442,   479,   411,   644,   479,   673,
      14,   707,   598,  2356,  2357,  2358,   594,  2604,  2361,  2362,
    2363,     5,  3085,  2366,  2987,  2988,  2989,    26,  2991,  2992,
    2993,  2994,  2995,  2996,   149,   479,   479,  3000,  3524,     5,
     667,   594,   686,   673,   673,   475,   672,    26,   442,   672,
    3113,   442,  2395,     5,  2397,  2398,     5,  2400,  2401,   442,
       5,  2404,   419,   666,   383,  2408,   812,    26,   475,  2412,
    2413,     5,   509,   509,  2417,  2662,   822,   479,   479,   479,
    2423,  2424,   479,  2426,  2427,  2584,   667,  2430,  2431,   479,
    2677,  2590,   479,     5,   667,   479,   507,   479,     8,   667,
       5,  2688,   624,   601,   377,    25,   396,   667,  2451,   396,
     396,   507,   479,   411,   474,  2458,     5,  2616,  2461,   507,
       5,   698,    26,     5,     5,    25,    14,  2470,    14,    26,
     479,  2474,   643,   601,   643,     5,   664,     5,   442,  2896,
    2897,  2898,  2899,    26,   479,   442,   384,    26,    26,  3635,
    3059,    26,  3533,   673,   442,     6,  2499,   442,   442,   397,
     442,     7,   318,   496,   442,   442,     5,   667,    26,    26,
      26,    26,  3610,  3611,  3612,  3613,  3614,  3615,   673,    26,
    2523,   667,   667,   442,    20,     5,   614,   324,    25,  2896,
    2897,  2898,  2899,     5,     5,   594,     5,   715,     8,     5,
     442,   619,   442,   479,  2961,   519,  2963,   667,   320,     5,
       5,   323,   673,   325,   594,   261,   673,   671,    26,   442,
     673,   459,   968,   673,   673,   479,   479,   465,     5,     5,
    2573,   671,   673,   345,    25,    25,    25,   666,  2872,  2873,
      25,    25,   442,   355,   495,  2588,    26,    26,    26,   346,
     442,    26,  2839,  2596,  2597,  2598,    26,    26,  2601,  2602,
      26,  2604,  2635,  1256,   376,     5,   504,   442,   442,   479,
     516,     5,   479,   442,  2617,  2618,   598,     8,  2621,  2622,
     290,    26,    25,  2870,   475,   442,  2852,   399,  2854,    40,
     528,   403,  3355,  3275,   489,   396,  2796,    20,   192,  3626,
     538,   539,  1048,   479,     5,   601,   544,   479,   479,   479,
    3373,   479,  2837,   479,   479,     5,   554,    14,   261,  2662,
      26,    26,    26,    26,     5,   442,   442,  2670,   490,  2672,
    2703,    26,  2675,   442,  2677,    26,   442,    26,   576,  3248,
     507,   579,   580,   442,  2809,  2688,   584,   479,    26,  2814,
    2693,  2694,  2695,   104,   105,  2796,    26,  2822,  2823,    26,
     425,    26,   442,   290,  2707,   442,   478,   616,   442,   396,
     442,   479,   291,  2872,  2873,   489,   507,   594,   442,   479,
    2967,  3762,  2725,    14,   442,   442,   442,     7,   289,    26,
     227,   289,   442,   673,   442,   479,  2837,   623,   443,   667,
    2743,    26,  2745,   641,   442,   442,   479,   637,   475,    25,
       5,   291,   442,   442,   652,  2758,   442,   442,   169,   442,
     507,    26,  2765,    26,    26,   442,     5,    26,   667,   442,
    3187,  3188,   667,    26,  3191,   475,   442,   188,   667,   475,
    2758,  3684,  2817,   994,  2495,  1536,    29,  2790,  2427,  2792,
    2179,  2794,  3515,    31,  2797,  2798,  2790,  2800,  2433,   352,
     112,   116,   655,   205,  2027,  2026,   343,   223,   534,   353,
     597,   210,  2815,  1219,  2817,  2818,  2819,   553,  1277,   382,
    3187,  3188,   381,   565,  3191,  3674,    20,    21,    22,  2832,
    2080,   798,   567,   986,  2283,   413,  2839,  2290,  2130,  1253,
    2420,  1882,  2841,  3152,  2206,  3233,  1885,  2519,  3729,  2852,
      44,  2854,  2423,  2226,  3369,    16,    90,   354,  1427,    40,
    3296,  2864,  2865,   360,   361,   362,    40,  2870,  3103,    22,
    2184,  2190,  1278,  1279,   754,  2080,  1547,   324,   927,  2882,
    1496,  3116,  1288,  1890,  2193,   382,  3293,  1220,  3477,  1421,
    1494,  2096,  3691,  2896,  2897,  2898,  2899,  2900,  2901,  2839,
     779,  1410,   313,   314,  1010,  3027,  3487,  2910,  1517,   320,
    2159,  3025,  2915,   324,   450,  3009,  2706,  3083,  2123,  3349,
    3347,  3340,  3075,  2412,  2060,  2130,  2043,  2584,  3700,  2366,
    3269,  1924,  2603,  1924,  2261,  3184,  3032,  3097,  3502,  3066,
    2948,  2327,  2249,  2949,  3259,  2948,  2949,   141,   142,   143,
     144,   145,   146,  3585,  2159,  2675,  2959,  2960,  2728,  2962,
    1909,  3054,  2965,  3312,  2967,   159,   160,   161,  2971,     8,
    2707,  3749,  1249,  2178,  3186,  2694,  2002,  2695,  2883,  3267,
    1904,  3543,   479,  1245,  2597,  2001,  3181,  3420,  3439,  1877,
     487,  3428,  1111,   490,  2740,  1444,  3097,  2798,  2021,  1436,
    2796,   498,    -1,  2444,  1426,  3422,  3131,    -1,  3011,   543,
      -1,  3428,  3429,    -1,  3431,  3432,  3433,  3434,  3265,    -1,
    3267,  3024,    -1,  3440,    -1,    -1,    -1,    -1,    -1,    -1,
    3033,  3034,  3035,    -1,    -1,    -1,   533,    -1,    -1,    -1,
      -1,    -1,    -1,  3337,  1450,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  3347,    -1,  3422,  3059,    -1,    -1,    -1,
      -1,  3428,  3429,    -1,  3431,  3432,  3433,  3434,  3071,  3072,
      -1,   568,  3075,  3440,    -1,  3078,    -1,    -1,    -1,    -1,
      -1,    -1,  3085,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     587,   588,  3095,   504,    -1,  3098,  3099,    -1,    -1,    -1,
    3103,   598,    -1,    -1,   515,   299,   603,    -1,   302,    -1,
    3113,    -1,    -1,  3116,    -1,  3118,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   169,  3127,  3351,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  3553,    -1,    -1,  3556,
    3557,  3558,  3559,    -1,    -1,   642,    -1,  3441,    -1,    -1,
    2896,  2897,  2898,  2899,    -1,    -1,    -1,    -1,    -1,  3406,
      -1,    -1,    -1,  3166,    -1,    -1,    -1,   578,    -1,  3172,
      -1,    -1,    -1,  3420,    -1,    -1,    -1,   674,  3181,  3182,
      -1,  3184,  3185,    -1,  3187,  3188,  3553,    -1,  3191,  3556,
    3557,  3558,  3559,    -1,    -1,    -1,    -1,  2402,    -1,  3202,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  2418,  2419,  2420,  2421,    -1,    -1,    -1,
      -1,    -1,  3225,  3226,    -1,   271,    -1,    -1,   422,  3646,
      -1,    -1,    -1,   279,  2439,    -1,    -1,    -1,  3655,   285,
     651,   287,    -1,   437,    -1,  3248,    -1,   441,    -1,    -1,
      -1,    -1,   298,  3256,    -1,    -1,  3259,    -1,    -1,  3262,
      -1,    -1,  3265,    -1,  3267,    -1,  3269,    -1,   679,   680,
     681,    -1,   683,    -1,    -1,    -1,    -1,    -1,    -1,  3646,
     326,    -1,  3441,   477,    -1,    -1,    -1,    -1,  3655,   700,
    3293,  1944,  1945,    -1,    -1,    -1,   342,    -1,  1951,    -1,
    2505,   347,  3549,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   505,    -1,   359,    -1,    -1,    -1,    -1,    -1,    -1,
     366,    -1,    -1,    -1,    -1,   736,    -1,    -1,  3331,   523,
      -1,   742,    -1,   744,    -1,    -1,    -1,   748,    -1,    -1,
     751,    -1,  3589,   754,    -1,    -1,    -1,    -1,  3351,    -1,
      -1,    -1,  3355,   764,  3539,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,   779,    -1,
    3373,    -1,    -1,    -1,   785,    -1,    -1,    -1,    -1,    -1,
      -1,   792,   793,   794,    -1,    -1,    -1,   798,    -1,    44,
      -1,    -1,    -1,    -1,    -1,   806,    -1,    -1,  3401,     5,
      -1,    -1,  2607,  3406,  2609,    -1,  3409,    -1,    -1,    -1,
     604,   822,    -1,    -1,    -1,    -1,    -1,  3420,    -1,  3422,
      -1,    -1,    -1,    -1,    -1,  3428,  3429,    -1,  3431,  3432,
    3433,  3434,    -1,    -1,  3437,    -1,  3439,  3440,  3539,  3442,
      22,  3187,  3188,    -1,    -1,  3191,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  3700,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    44,    -1,    -1,    -1,    -1,    -1,   514,    -1,
      -1,    -1,    -1,   519,  3477,    -1,   670,    -1,    -1,  3482,
     526,  3484,    -1,    -1,  1890,    -1,   141,   142,   143,   144,
     145,   146,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  3502,
      -1,  3626,   548,    -1,   159,   160,   161,   553,    -1,  2162,
    3256,    -1,  3515,  3259,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    3533,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    3543,    -1,    -1,    -1,    -1,    -1,  3549,    -1,    -1,  2202,
    3553,    -1,    -1,  3556,  3557,  3558,  3559,    -1,  3561,   141,
     142,   143,   144,   145,   146,    -1,  2771,    -1,    -1,  2774,
      -1,    -1,  3575,    -1,    -1,    -1,    -1,   159,   160,   161,
      -1,    -1,  3585,  1989,    -1,  1991,  3589,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  2001,  2002,    -1,    -1,    -1,
      -1,    -1,  2008,  2009,  2010,  2011,    -1,  3610,  3611,  3612,
    3613,  3614,  3615,    -1,    -1,    -1,    -1,    -1,    -1,  3622,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  2838,    -1,    -1,    -1,  1048,    -1,    -1,
      -1,    -1,    -1,  3646,   299,    -1,    -1,   302,    -1,    -1,
      -1,    -1,  3655,  1064,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  3422,    -1,    44,    -1,
      -1,    -1,  3428,  3429,    -1,  3431,  3432,  3433,  3434,    -1,
      -1,    -1,    -1,    -1,  3440,  1106,    -1,  3700,    -1,  3702,
      -1,    -1,    -1,    -1,   310,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  3458,    -1,    -1,    -1,    -1,   299,    -1,    -1,
     302,    -1,    -1,    -1,    -1,  1136,  1137,  1138,    -1,  1140,
      -1,  1142,  1143,    -1,    -1,    -1,    -1,  1148,  1149,    -1,
      -1,    -1,    -1,   349,  3747,  3748,  3749,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  2160,    -1,    -1,    -1,    -1,  3762,
      -1,  3764,   368,   369,    -1,    -1,    -1,   422,    -1,    -1,
      -1,    -1,  1183,    -1,    -1,   141,   142,   143,   144,   145,
     146,    -1,   437,    -1,  1195,    -1,   441,    -1,    -1,  2195,
      -1,    -1,    -1,   159,   160,   161,    -1,    -1,    -1,    -1,
      -1,    -1,   408,    -1,    -1,    -1,    -1,  3553,  1219,  1220,
    3556,  3557,  3558,  3559,   420,    -1,    -1,  1228,    -1,    -1,
      -1,    -1,   477,    -1,    -1,   431,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1244,  1245,    -1,  2489,  2490,    -1,  3585,
     422,   447,    -1,    -1,    -1,    -1,    -1,  2500,    -1,    -1,
     505,   457,    -1,    -1,    -1,   437,    -1,    -1,    -1,   441,
      -1,    -1,    -1,    -1,    -1,    -1,   472,    -1,   523,    -1,
      -1,  2524,  2525,  2526,  2527,  2528,  2529,    -1,    -1,    -1,
      -1,  2534,  2535,  2536,  2537,    -1,    -1,    -1,  2541,    -1,
      -1,    -1,    -1,    -1,    -1,   477,    -1,    -1,    -1,    -1,
    3646,  3106,  2308,    -1,    -1,    -1,   512,    -1,    -1,  3655,
      -1,  2317,    -1,    -1,  2320,  2321,  2322,  2323,    -1,    -1,
      -1,    -1,    -1,   505,    -1,    -1,  2332,    -1,    -1,   535,
      -1,    -1,   113,   299,    -1,    -1,   302,  3142,    -1,    -1,
      -1,   523,    -1,    -1,   550,    -1,    -1,    -1,    -1,   604,
      -1,   557,    -1,    -1,   560,    -1,  2362,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    2623,  2624,    -1,    -1,    -1,   581,    -1,  2630,  2631,   585,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1408,   604,  1410,
      -1,  1412,  1413,    -1,    -1,    -1,    -1,    -1,    -1,  1420,
    1421,    -1,    -1,  1424,    -1,   670,   622,  1428,    -1,    -1,
      -1,    -1,   604,    -1,    -1,    -1,    -1,    -1,  1439,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1450,
    1451,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  2461,   422,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   437,    -1,    -1,    -1,   441,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1495,  1496,    -1,  1498,   670,    -1,
    1501,  1502,     5,     6,     7,     8,    -1,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      -1,   477,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1531,    -1,    -1,    -1,    -1,    -1,    -1,  2780,  2781,    -1,
      -1,    44,    -1,    -1,    -1,    -1,  2789,    -1,    -1,   505,
      -1,    -1,    -1,    -1,    -1,  1556,    -1,    -1,    -1,    -1,
      -1,    -1,  3357,    -1,    -1,    -1,    -1,   523,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   349,    -1,
      -1,    -1,    -1,  2826,  2827,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  3392,   369,   370,
     371,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2604,    -1,
    2853,    -1,  2855,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   408,   141,   142,
     143,   144,   145,   146,    -1,    -1,    -1,    -1,   604,   420,
      -1,    -1,    -1,     9,    -1,    -1,   159,   160,   161,    -1,
     431,    -1,    18,    19,    -1,    -1,  2662,    -1,    24,    25,
      26,    27,    -1,  2916,  2917,    -1,   447,  2920,  2921,  2675,
      -1,  2677,    -1,    -1,    -1,    -1,   457,    -1,    -1,    -1,
      -1,    -1,  2688,    16,    17,    18,    19,    20,    21,    22,
      -1,   472,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   670,    -1,    -1,    -1,    -1,    -1,
      -1,    44,    -1,    -1,    -1,     5,     6,     7,     8,    -1,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    -1,  2740,    -1,    -1,    -1,    -1,   520,
      -1,    -1,    -1,   109,    -1,    -1,    -1,    -1,   114,    -1,
      -1,    -1,    -1,    -1,    44,   121,    -1,    -1,    -1,    -1,
      -1,    -1,  3015,    -1,    -1,    -1,    -1,    -1,    -1,   550,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   560,
      -1,    -1,   148,    -1,    -1,    -1,   299,    -1,    -1,   302,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     581,    -1,    -1,    -1,   585,    -1,    -1,    -1,   141,   142,
     143,   144,   145,   146,    -1,    -1,  3621,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   159,   160,   161,    -1,
      -1,    -1,   613,  2839,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   622,    -1,  3096,    -1,    -1,    -1,  3100,    -1,    -1,
      -1,   141,   142,   143,   144,   145,   146,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  2870,    -1,  3119,    -1,    -1,   159,
     160,   161,    -1,    -1,   240,    -1,   242,    -1,  1889,  1890,
      -1,    -1,    -1,    -1,    -1,  3138,    -1,    -1,    -1,    -1,
    2896,  2897,  2898,  2899,    -1,    17,    18,    19,    20,    21,
      22,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   422,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  3724,
      -1,    -1,    44,    -1,   437,    -1,    -1,    -1,   441,    -1,
      -1,    -1,    -1,    -1,    -1,  1946,    -1,    -1,    -1,    -1,
      -1,    -1,  2948,  2949,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  2959,  2960,    -1,  2962,    -1,    -1,  2965,
      -1,  2967,    -1,    -1,   477,  2971,   299,    -1,    -1,   302,
      -1,    -1,    -1,   339,    -1,    -1,    -1,    -1,   344,    -1,
      -1,  2987,  2988,  2989,    -1,  2991,  2992,  2993,  2994,  2995,
    2996,    -1,   505,    -1,  3000,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   374,   299,
     523,    -1,   302,    -1,    -1,    -1,    -1,    -1,    -1,   141,
     142,   143,   144,   145,   146,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   159,   160,   161,
      -1,    -1,   408,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   420,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   438,    -1,    -1,    -1,    -1,   443,    -1,   445,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   422,
     456,   604,    -1,    -1,    -1,   461,    -1,    -1,    -1,    -1,
      -1,    -1,     9,    -1,   437,   471,    -1,    -1,   441,    -1,
     476,    18,    19,   479,    -1,    -1,   482,    24,    25,    26,
      27,  3127,    -1,    -1,    -1,   491,   492,    -1,    -1,    -1,
      -1,    -1,   422,    -1,    -1,  2146,    -1,  3390,    -1,    -1,
    3393,    -1,    -1,    -1,   477,    -1,    -1,   437,    -1,    -1,
      -1,   441,    -1,    -1,    -1,    -1,    -1,   670,  2169,    -1,
      -1,    -1,    -1,    -1,    -1,   531,   532,    -1,    -1,    -1,
     536,    -1,   505,    -1,    -1,    -1,    -1,   299,   544,  2190,
     302,  3187,  3188,    -1,    -1,  3191,    -1,   477,  2199,   555,
     523,    -1,    -1,    -1,    -1,   561,    -1,    -1,    -1,    -1,
      -1,    -1,   109,    -1,    -1,    -1,    -1,   114,    -1,    -1,
      -1,    -1,    -1,    -1,   121,   505,    -1,    -1,    -1,   585,
      -1,    -1,    -1,    -1,    -1,  2236,  2237,  2238,    -1,    -1,
      -1,  2242,    -1,   523,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   148,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    3256,    -1,    -1,  3259,    -1,    -1,  3262,    -1,    -1,  3265,
      -1,  3267,    -1,   629,    -1,    -1,  2277,    -1,    -1,    -1,
     636,   604,   638,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   648,   649,  3537,    -1,    -1,    -1,    -1,    -1,
     656,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     422,   667,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   604,   437,    -1,    -1,    -1,   441,
      -1,    -1,    -1,    -1,    -1,  3331,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   240,    -1,   242,    -1,   670,  3591,  3592,
      -1,  3594,    -1,  3596,  3597,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   477,   722,   723,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     670,    -1,    -1,   505,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    3406,   523,  2413,    -1,    -1,    -1,  2417,    -1,    -1,  3662,
      -1,  3664,    -1,    -1,  3420,  2426,  3422,    -1,    -1,    -1,
      -1,    -1,  3428,  3429,    -1,  3431,  3432,  3433,  3434,    -1,
      -1,    -1,   339,  2444,  3440,    -1,  3442,   344,    -1,    -1,
    2451,    -1,    -1,    -1,    -1,  3698,    -1,    -1,    -1,    -1,
    2461,    -1,  3458,    -1,    -1,    -1,    -1,    -1,    -1,  2470,
      -1,    -1,    -1,  2474,    -1,  3718,  3719,   374,    -1,  3722,
      -1,    -1,  3725,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   604,    -1,    -1,    -1,    -1,    -1,  2499,    -1,
      -1,    -1,    -1,     9,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   408,    18,    19,    -1,    -1,    -1,     9,    24,    25,
      26,    27,    -1,   420,    -1,    -1,    18,    19,    -1,    -1,
      -1,    -1,    24,    25,    26,    27,    -1,  3533,    -1,    -1,
      -1,   438,    -1,    -1,    -1,    -1,   443,    -1,   445,    -1,
      -1,    -1,    -1,  3549,    -1,    -1,    -1,  3553,   670,   456,
    3556,  3557,  3558,  3559,   461,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   471,    -1,    -1,    -1,    -1,   476,
      -1,    -1,   479,    -1,    -1,   482,    -1,    -1,    -1,  3585,
      -1,    -1,    -1,  3589,   491,   492,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   109,    -1,    -1,    -1,    -1,   114,    -1,
      -1,    -1,    -1,    -1,    -1,   121,    -1,   109,    -1,    -1,
    2621,    -1,   114,    -1,    -1,    -1,    -1,    -1,    -1,   121,
      -1,    -1,    -1,    -1,   531,   532,    -1,    -1,    -1,   536,
      -1,    -1,   148,    -1,    -1,    -1,    -1,   544,    -1,    -1,
    3646,    -1,    -1,    -1,    -1,    -1,   148,    -1,   555,  3655,
      -1,    -1,    -1,    -1,   561,    -1,    -1,     6,     7,     8,
      -1,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    -1,    -1,    -1,    -1,   585,    -1,
      -1,    -1,    -1,  2694,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  3700,    44,     7,     8,    -1,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   629,    -1,   240,    -1,   242,    -1,    -1,   636,
      -1,   638,    -1,    44,    -1,    -1,    -1,    -1,   240,    -1,
     242,   648,   649,    -1,    -1,    -1,    -1,    -1,    -1,   656,
      -1,    -1,    -1,    -1,  2765,    -1,  3762,    -1,    -1,    -1,
     667,    -1,    -1,    -1,     9,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    18,    19,    -1,    -1,    -1,    -1,    24,
      25,    26,    27,    -1,    -1,  2796,    -1,    -1,    -1,  2800,
      -1,    -1,   141,   142,   143,   144,   145,   146,    -1,    -1,
      -1,    -1,    -1,    -1,  2815,    -1,  2817,    -1,  2819,    -1,
     159,   160,   161,    -1,    -1,   722,   723,    -1,    -1,    -1,
      -1,  2832,    -1,   339,    -1,    -1,  2837,    -1,   344,    -1,
     141,   142,   143,   144,   145,   146,    -1,   339,    -1,    -1,
      -1,    -1,   344,    -1,    -1,    -1,    -1,    -1,   159,   160,
     161,    -1,    -1,  2864,  2865,    -1,    -1,    -1,   374,    -1,
      -1,    -1,    -1,    -1,   109,    -1,    -1,    -1,    -1,   114,
      -1,    -1,   374,    -1,    -1,    -1,   121,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   408,    -1,    -1,    -1,    -1,    -1,    -1,  2910,
      -1,    -1,    -1,   148,   420,    -1,   408,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   420,    -1,
      -1,    -1,   438,    -1,    -1,    -1,    -1,   443,    -1,   445,
      -1,    -1,    -1,    -1,    -1,    -1,   438,    -1,    -1,    -1,
     456,   443,    -1,   445,    -1,   461,    -1,    -1,    -1,    -1,
     299,    -1,    -1,   302,   456,   471,    -1,    -1,    -1,   461,
     476,    -1,    -1,   479,    -1,    -1,   482,    -1,    -1,   471,
      -1,    -1,    -1,    -1,   476,   491,   492,   479,    -1,    -1,
     482,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   299,   491,
     492,   302,    -1,    -1,    -1,   240,    -1,   242,    -1,    -1,
    3011,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  3024,    -1,    -1,   532,    -1,    -1,    -1,
     536,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   544,   531,
     532,    -1,    -1,    -1,   536,    -1,    -1,    -1,    -1,   555,
      -1,   557,   544,    -1,    -1,   561,    -1,     9,    -1,    -1,
      -1,    -1,    -1,   555,    -1,    -1,    18,    19,    20,   561,
      -1,    -1,    24,    25,    26,    27,    -1,    -1,    -1,   585,
      -1,    -1,    -1,   422,  3085,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   585,    -1,    -1,  3097,    -1,   437,    -1,
      -1,    -1,   441,   442,   339,    -1,    -1,    -1,    -1,   344,
      -1,    -1,  3113,   310,    -1,    -1,    -1,  3118,    -1,    -1,
      -1,   422,    -1,   629,    -1,    -1,  3127,    -1,    -1,    -1,
     636,    -1,   638,    -1,    -1,    -1,   437,   629,   477,   374,
     441,    -1,   648,   649,   636,    -1,   638,    -1,    -1,    -1,
     656,    -1,   349,    -1,    -1,    -1,   648,   649,    -1,    -1,
      -1,   667,   114,    -1,   656,    -1,   505,    -1,    -1,    -1,
      -1,   368,   369,   408,    -1,   667,   477,    -1,    -1,    -1,
      -1,    -1,    -1,    32,   523,   420,    -1,    36,    -1,    -1,
      -1,   123,   124,    -1,   126,   127,   128,    -1,    -1,    -1,
      -1,    -1,    -1,   438,   505,    -1,    -1,    -1,   443,    -1,
     445,   408,    -1,    -1,    -1,    -1,   722,   723,    -1,    -1,
      -1,   456,   523,   420,  3225,    -1,   461,    -1,    -1,    -1,
     722,   723,    -1,    -1,   431,    -1,   471,    -1,    -1,    -1,
      -1,   476,    -1,    -1,   479,    -1,    -1,   482,    -1,    -1,
     447,    -1,    -1,    -1,    -1,    -1,   491,   492,    -1,    -1,
     457,    -1,    -1,    -1,   113,   604,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   472,    -1,    -1,    -1,    -1,
     129,   130,    -1,    -1,    -1,    -1,    -1,    -1,   240,    -1,
     139,    -1,  3293,    -1,   226,    -1,    -1,   532,    -1,    -1,
      -1,   536,   234,   604,    -1,    -1,    -1,    -1,    -1,   544,
      -1,    -1,    -1,    -1,    -1,   512,    -1,    -1,    -1,    -1,
     555,    -1,    -1,    -1,    -1,    -1,   561,    -1,    -1,    -1,
      -1,   670,    -1,    -1,    -1,    -1,   268,    -1,   535,    -1,
      -1,    -1,    -1,    -1,    -1,   277,    -1,    -1,    -1,    -1,
     585,    -1,    -1,   550,  3355,    -1,    -1,    -1,    -1,    -1,
     557,    -1,    -1,   560,    -1,    -1,    -1,    -1,    -1,   670,
      -1,    -1,  3373,    -1,   306,   307,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   581,    -1,    -1,    -1,   585,    -1,
      -1,    -1,   344,    -1,   629,    -1,    -1,    -1,    -1,    -1,
    3401,   636,    -1,   638,    -1,    -1,    -1,   604,    -1,    -1,
      -1,    -1,    -1,   648,   649,    -1,    -1,    -1,    -1,   351,
      -1,   656,    -1,    -1,    -1,   622,    -1,    -1,    -1,    -1,
      -1,    -1,   667,    -1,     5,     6,     7,     8,     9,    10,
      -1,    12,    13,    14,    -1,    -1,    -1,    18,    19,    20,
      21,    22,    23,    -1,    -1,    -1,   408,    -1,    -1,    -1,
      -1,   310,    33,   395,    -1,    -1,    -1,    -1,   420,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  3477,    -1,    -1,    -1,
      -1,  3482,    -1,  3484,    55,    -1,    -1,   722,   723,    -1,
      -1,    -1,    -1,   445,    -1,    -1,    -1,    -1,    -1,    -1,
     349,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  3515,    -1,    -1,   449,    -1,   368,
     369,   370,   371,    -1,   476,    -1,    -1,   479,    -1,    -1,
      -1,    -1,  3533,    -1,    -1,    -1,    -1,   386,  3539,   491,
     492,   112,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     121,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   408,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   519,   139,   140,
      -1,   420,    -1,    -1,    -1,    -1,    -1,   148,    -1,    -1,
     532,    -1,   431,    -1,   155,   156,    -1,    -1,   159,   160,
     161,   162,   544,    -1,   165,   166,    -1,    -1,   447,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   457,  3610,
    3611,  3612,  3613,  3614,  3615,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   472,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   585,   205,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   227,    -1,    -1,    -1,
      -1,    -1,   233,   512,    -1,    -1,   618,    -1,   239,   240,
      -1,   242,   624,    -1,    -1,    -1,   247,    -1,    -1,    -1,
      -1,   633,   634,    -1,   636,    -1,   535,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   648,   649,    -1,    -1,
      -1,   550,   273,    -1,   656,    -1,    -1,   659,   557,    -1,
      -1,   560,    -1,    -1,    -1,   667,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   581,    -1,    -1,    -1,   585,    -1,    -1,    -1,
     311,    -1,    -1,   675,   676,   677,   678,   679,   680,   681,
     682,   683,   684,   324,    -1,   604,    -1,    -1,    -1,   330,
      -1,  3762,    -1,    -1,    -1,    -1,    -1,    -1,   339,   340,
      -1,    -1,    -1,   622,    -1,   346,    -1,    -1,   349,   350,
      -1,    -1,    -1,   354,    -1,    -1,    -1,    -1,    -1,   360,
     361,    -1,    -1,    -1,    -1,    -1,   367,   368,   369,    -1,
      -1,   372,   373,   374,    -1,    -1,    -1,   378,    -1,    -1,
      -1,   382,    -1,   384,    -1,   664,    -1,    -1,    -1,    -1,
     391,   392,   393,   394,    -1,   396,   397,    -1,    -1,    -1,
     401,   402,    -1,   404,   405,   406,   407,   408,   409,   410,
      -1,    -1,    -1,    -1,    -1,   416,   417,   418,    -1,   420,
     421,    -1,    -1,    -1,   425,   426,   427,   428,   429,   430,
     431,   432,    -1,   434,    -1,    -1,    -1,   438,   439,   440,
     441,   442,   443,   444,   445,   446,   447,   448,   449,   450,
     451,   452,   453,   454,   455,   456,   457,   458,   459,   460,
     461,   462,   463,   464,   465,   466,   467,   468,   469,   470,
     471,   472,   473,    -1,   475,   476,    -1,    -1,   479,   480,
     481,   482,   483,   484,   485,   486,   487,   488,    -1,   490,
     491,   492,   493,   494,   495,   496,   497,   498,   499,   500,
     501,   502,   503,   504,    -1,    -1,   507,   508,   509,   510,
     511,   512,   513,   514,   515,    -1,   517,   518,   519,   520,
      -1,   522,   523,   524,   525,   526,   527,   528,   529,   530,
     531,   532,   533,   534,   535,   536,   537,   538,   539,   540,
     541,   542,   543,   544,   545,   546,   547,   548,   549,   550,
     551,   552,   553,   554,   555,   556,   557,    -1,   559,   560,
     561,   562,   563,   564,    -1,    -1,   567,   568,    -1,   570,
     571,   572,   573,   574,   575,   576,   577,   578,   579,   580,
     581,   582,   583,   584,   585,   586,   587,   588,   589,   590,
     591,   592,   593,   594,   595,    -1,    -1,   598,   599,   600,
     601,   602,   603,   604,   605,   606,   607,   608,   609,   610,
     611,   612,   613,   614,   615,   616,   617,   618,   619,   620,
     621,   622,   623,   624,   625,   626,   627,   628,   629,   630,
     631,   632,   633,   634,   635,   636,   637,   638,   639,   640,
     641,   642,   643,   644,   645,   646,   647,   648,   649,   650,
     651,   652,   653,   654,   655,   656,   657,   658,   659,    -1,
      -1,    -1,    -1,   664,   665,   666,   667,   668,   669,   670,
     671,   672,   673,   674,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   685,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   693,    -1,    -1,    -1,    -1,   698,    -1,    -1,
      -1,   702,    -1,    -1,   705,   706,   707,   708,    -1,    -1,
     711,   712,    -1,   714,   715,   716,     5,     6,     7,     8,
       9,    10,    -1,    12,    13,    14,    -1,    -1,    -1,    18,
      19,    20,    21,    22,    23,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    33,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    55,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   112,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   121,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     139,   140,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   148,
      -1,    -1,    -1,    -1,    -1,    -1,   155,   156,    -1,    -1,
     159,   160,   161,   162,    -1,    -1,   165,   166,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   205,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   227,    -1,
      -1,    -1,    -1,    -1,   233,    -1,    -1,    -1,    -1,    -1,
      -1,   240,    -1,   242,    -1,    -1,    -1,    -1,   247,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   273,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   311,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   324,    -1,    -1,    -1,    -1,
      -1,   330,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     339,   340,    -1,    -1,    -1,    -1,    -1,   346,    -1,    -1,
     349,   350,    -1,    -1,    -1,   354,    -1,    -1,    -1,    -1,
      -1,   360,   361,    -1,    -1,    -1,    -1,    -1,   367,   368,
     369,    -1,    -1,   372,   373,   374,    -1,    -1,    -1,   378,
      -1,    -1,    -1,   382,    -1,   384,    -1,    -1,    -1,    -1,
      -1,    -1,   391,   392,   393,   394,    -1,   396,   397,    -1,
      -1,    -1,   401,   402,    -1,   404,   405,   406,   407,   408,
     409,   410,    -1,    -1,    -1,    -1,    -1,   416,   417,   418,
      -1,   420,   421,    -1,    -1,    -1,   425,   426,   427,   428,
     429,   430,   431,   432,    -1,   434,    -1,    -1,    -1,   438,
     439,   440,   441,   442,   443,   444,   445,   446,   447,   448,
     449,   450,   451,   452,   453,   454,   455,   456,   457,   458,
     459,   460,   461,   462,   463,   464,   465,   466,   467,   468,
     469,   470,   471,   472,   473,    -1,   475,   476,    -1,    -1,
     479,   480,   481,   482,   483,   484,   485,   486,   487,   488,
      -1,   490,   491,   492,   493,   494,   495,   496,   497,   498,
     499,   500,   501,   502,   503,   504,    -1,    -1,   507,   508,
     509,   510,   511,   512,   513,   514,   515,    -1,   517,   518,
     519,   520,    -1,   522,   523,   524,   525,   526,   527,   528,
     529,   530,   531,   532,   533,   534,   535,   536,   537,   538,
     539,   540,   541,   542,   543,   544,   545,   546,   547,   548,
     549,   550,   551,   552,   553,   554,   555,   556,   557,    -1,
     559,   560,   561,   562,   563,   564,    -1,    -1,   567,   568,
      -1,   570,   571,   572,   573,   574,   575,   576,   577,   578,
     579,   580,   581,   582,   583,   584,   585,   586,   587,   588,
     589,   590,   591,   592,   593,   594,   595,    -1,    -1,   598,
     599,   600,   601,   602,   603,   604,   605,   606,   607,   608,
     609,   610,   611,   612,   613,   614,   615,   616,   617,   618,
     619,   620,   621,   622,   623,   624,   625,   626,   627,   628,
     629,   630,   631,   632,   633,   634,   635,   636,   637,   638,
     639,   640,   641,   642,   643,   644,   645,   646,   647,   648,
     649,   650,   651,   652,   653,   654,   655,   656,   657,   658,
     659,    -1,    -1,    23,    -1,   664,   665,   666,   667,   668,
     669,   670,   671,   672,   673,   674,    -1,    -1,    -1,    -1,
      40,    41,    42,    -1,    -1,    45,   685,    47,    48,    -1,
      -1,    -1,    -1,    -1,   693,    -1,    -1,    -1,    -1,   698,
      -1,    -1,    -1,   702,    -1,    -1,   705,   706,   707,   708,
      -1,    -1,   711,   712,    -1,   714,   715,   716,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   112,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     140,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   186,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   214,    -1,   216,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   241,    -1,    -1,    -1,    -1,    -1,    -1,   248,    -1,
     250,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   261,    -1,    -1,    -1,    -1,   266,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   274,    -1,    -1,    -1,   278,    -1,
      -1,    -1,    -1,    -1,   284,    -1,    -1,    -1,   288,   289,
     290,   291,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   303,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     320,    -1,    -1,   323,    -1,   325,    -1,    -1,    -1,    -1,
      -1,    -1,   332,    30,    -1,    -1,    -1,    34,    -1,    -1,
      37,    38,    39,    -1,    -1,   345,    -1,    -1,    -1,    46,
      -1,    -1,    49,    -1,    -1,   355,    -1,    -1,    -1,    56,
      57,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   376,   377,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   391,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   399,
      -1,    -1,    -1,   403,   101,   102,    -1,    -1,    -1,   106,
      -1,   411,   412,   413,    -1,    -1,    -1,    -1,    -1,   116,
     117,    -1,   119,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   133,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   150,    -1,    -1,   153,   154,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   168,    -1,   170,   171,   172,    -1,    -1,   478,    -1,
      -1,    -1,    -1,   180,   181,    -1,   183,   184,   185,   489,
      -1,    -1,    -1,    -1,   191,    -1,    -1,   194,    -1,   196,
     197,   198,    -1,    -1,    -1,    -1,    -1,   204,    -1,   206,
     207,    -1,   209,    -1,   211,   212,    -1,    -1,   215,    -1,
      -1,   218,   219,   220,   221,   222,   223,    -1,    -1,   529,
     227,   228,   229,    -1,   231,    -1,    -1,    -1,   235,    -1,
     237,   238,    -1,    -1,    -1,    -1,   243,    -1,    -1,   246,
      -1,    -1,   249,    -1,   251,    -1,   253,    -1,   255,    -1,
      -1,    -1,   259,   260,    -1,   262,   263,   264,    -1,    -1,
     267,    -1,   269,   270,    -1,   272,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   280,   281,    -1,    -1,    -1,    -1,    -1,
     590,    -1,    -1,    -1,    -1,    -1,   293,    -1,    -1,   296,
     297,    -1,    -1,   300,   301,    -1,    -1,   304,   305,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   313,   314,   315,    -1,
     317,    -1,    -1,    -1,    -1,    -1,   626,    -1,    -1,    -1,
     327,   328,   329,    -1,   331,    -1,    -1,    -1,   335,   336,
      -1,    -1,    -1,   340,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   348,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   356,
     357,   358,    -1,    -1,    -1,    -1,    -1,   364,   365,    -1,
      -1,    -1,   672,    -1,    -1,   372,    -1,    -1,   375,    -1,
      -1,    -1,   379,   380,    -1,    -1,   686,   687,   688,   689,
     690,   691,   692,   390,   694,   695,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     407,   711,    -1,    -1,    -1,    -1,    -1,    -1,   415,    -1,
      -1,    -1,    -1,    -1,   421,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   432,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   444,    -1,    -1,
      -1,    -1,    -1,   450,    -1,   452,   453,    -1,    -1,    -1,
      -1,    -1,    -1,   460,    -1,    -1,    -1,    -1,     6,     7,
       8,    -1,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   499,    -1,    -1,    -1,    44,    -1,    -1,    -1,
      -1,    -1,    -1,   510,    -1,    -1,    -1,    -1,    -1,    -1,
     517,    -1,    -1,    -1,    -1,    -1,    -1,     6,     7,     8,
      -1,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,   541,   542,    -1,    -1,    -1,   546,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   558,    -1,    -1,    -1,    44,    -1,   564,   565,   566,
     567,    -1,    -1,    -1,   571,    -1,    -1,    -1,   575,    -1,
      -1,    -1,    -1,    -1,    -1,   582,   583,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   593,    -1,   595,    -1,
      -1,    -1,    -1,   141,   142,   143,   144,   145,   146,   606,
      -1,   608,    -1,    -1,   611,    -1,    -1,    -1,    -1,    -1,
     617,   159,   160,   161,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   643,    -1,    -1,   646,
      -1,    -1,    -1,    -1,   651,    -1,    -1,   654,   655,    -1,
      -1,    -1,   141,   142,   143,   144,   145,   146,    -1,    -1,
      -1,    -1,   669,    -1,    -1,    -1,    -1,    -1,    -1,   676,
     159,   160,   161,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   699,   700,   701,   702,   703,   704,   705,    -1,
      -1,   708,    -1,   710,    -1,   712,    -1,     6,     7,     8,
      -1,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    -1,    -1,    -1,    -1,     6,     7,
       8,    -1,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    44,    -1,    -1,    -1,    -1,
      -1,   299,    -1,    -1,   302,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    44,     6,     7,     8,
      -1,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    44,    -1,    -1,    -1,    -1,
     299,    -1,    -1,   302,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   141,   142,   143,   144,   145,   146,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     159,   160,   161,   141,   142,   143,   144,   145,   146,    -1,
      -1,    -1,    -1,    -1,   422,    -1,    -1,    -1,    -1,    -1,
      -1,   159,   160,   161,    -1,    -1,    -1,    -1,    -1,   437,
      -1,    -1,    -1,   441,   442,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   141,   142,   143,   144,   145,   146,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     159,   160,   161,    -1,    -1,    -1,    -1,    -1,    -1,   477,
      -1,    -1,    -1,   422,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   437,    -1,
      -1,    -1,   441,   442,     6,     7,     8,   505,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    -1,    -1,    -1,    -1,   523,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   477,    -1,
      -1,    -1,    44,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     299,    -1,    -1,   302,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   505,    -1,    -1,    -1,
      -1,   299,    -1,    -1,   302,    -1,    -1,    -1,    -1,    -1,
      -1,     6,     7,     8,   523,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   604,    -1,    -1,    -1,
     299,    -1,    -1,   302,    -1,    -1,    -1,    -1,    -1,    44,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   141,
     142,   143,   144,   145,   146,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   159,   160,   161,
      -1,    -1,    -1,    -1,    -1,   604,    -1,    -1,    -1,    -1,
      -1,    -1,   670,   422,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   437,    -1,
      -1,    -1,   441,   442,   422,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   437,
      -1,    -1,    -1,   441,   442,    -1,   141,   142,   143,   144,
     145,   146,    -1,    -1,    -1,    -1,    -1,    -1,   477,    -1,
      -1,   670,    -1,   422,   159,   160,   161,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   437,   477,
      -1,    -1,   441,   442,    -1,    -1,   505,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   523,    -1,    -1,   505,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   477,    -1,
      -1,    -1,    -1,    -1,    -1,   523,    -1,   299,    -1,    -1,
     302,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,     6,     7,     8,   505,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      -1,    -1,    -1,    -1,   523,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    44,     6,     7,     8,   604,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    -1,
      -1,    -1,    -1,    -1,   299,    -1,   604,   302,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,     6,     7,     8,
      44,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   604,    -1,    -1,    -1,    -1,
     422,   670,    -1,    -1,    -1,    44,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   437,    -1,    -1,    -1,   441,
     442,    -1,   670,    -1,    -1,    -1,    -1,    -1,   141,   142,
     143,   144,   145,   146,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   159,   160,   161,    18,
      19,    20,    21,    22,    -1,   477,    -1,    -1,    -1,    -1,
      -1,   670,    -1,    -1,    -1,    -1,    -1,   141,   142,   143,
     144,   145,   146,    -1,    -1,    44,    -1,   422,    -1,    -1,
      -1,    -1,    -1,   505,    -1,   159,   160,   161,    -1,    -1,
      -1,    -1,   437,    -1,    -1,    -1,   441,   442,    -1,    -1,
      -1,   523,   141,   142,   143,   144,   145,   146,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     159,   160,   161,    -1,    -1,    -1,    -1,    -1,    -1,     6,
       7,     8,   477,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     505,    -1,    -1,    -1,    -1,    -1,    -1,    44,    -1,    -1,
      -1,    -1,   141,   142,   143,   144,   145,   146,   523,    -1,
      -1,    -1,   604,    -1,    -1,    -1,   299,    -1,    -1,   302,
     159,   160,   161,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,     8,    -1,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   299,    -1,    -1,   302,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    44,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   670,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   604,
     299,    -1,    -1,   302,   141,   142,   143,   144,   145,   146,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   159,   160,   161,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   422,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    -1,    -1,   437,   670,    -1,    -1,   441,    -1,
     299,    -1,    -1,   302,   141,   142,   143,   144,   145,   146,
      -1,    -1,    -1,    44,    -1,    -1,    -1,    -1,   422,    -1,
      -1,    -1,   159,   160,   161,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   437,   477,    -1,    -1,   441,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   490,    -1,    -1,
      -1,    -1,    -1,   422,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   505,    -1,    -1,    -1,    -1,    -1,   437,    -1,
      -1,    -1,   441,   477,    -1,    -1,    -1,    -1,    -1,    -1,
     523,    -1,    -1,    -1,    -1,    -1,   490,     9,    -1,    -1,
      -1,    -1,   299,    -1,    -1,   302,    18,    19,    20,    -1,
      -1,   505,    24,    25,    26,    27,    -1,    -1,   477,    -1,
     141,   142,   143,   144,   145,   146,    -1,    -1,    -1,   523,
      -1,   490,    -1,   422,    -1,    -1,    -1,    -1,   159,   160,
     161,    -1,    -1,    -1,    -1,    -1,   505,    -1,   437,    -1,
      -1,    -1,   441,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,   523,    -1,    -1,    -1,    -1,    -1,
      -1,   604,   299,    -1,    -1,   302,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    44,    -1,    -1,   477,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    -1,
      -1,    -1,   114,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     604,    -1,    -1,    -1,    -1,    -1,   505,    -1,    -1,    -1,
      44,    -1,    -1,    -1,    -1,   422,    15,    16,    17,    18,
      19,    20,    21,    22,   523,    -1,    -1,   670,    -1,    -1,
     437,    -1,    -1,    -1,   441,   604,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    44,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    -1,    -1,    -1,    -1,   670,    -1,   299,    -1,
     477,   302,   141,   142,   143,   144,   145,   146,    -1,    -1,
      18,    19,    20,    44,    -1,   422,    24,    25,    26,    27,
     159,   160,   161,    -1,    -1,    -1,    -1,    -1,   505,    -1,
     437,   670,    -1,    -1,   441,   604,    -1,   141,   142,   143,
     144,   145,   146,    -1,    -1,    -1,   523,    -1,   240,    -1,
      -1,    -1,    -1,    -1,    -1,   159,   160,   161,    -1,    -1,
      18,    19,    20,    -1,    -1,    -1,    24,    25,    26,    27,
     477,    -1,   141,   142,   143,   144,   145,   146,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     159,   160,   161,    -1,    -1,    -1,    -1,    -1,   505,    -1,
      -1,   670,    -1,    -1,    -1,    -1,   114,    -1,    -1,    -1,
     141,   142,   143,   144,   145,   146,   523,    18,    19,    20,
      -1,   422,    -1,    24,    25,    26,    27,   604,   159,   160,
     161,    -1,    -1,    -1,    -1,    -1,   437,    -1,    -1,    -1,
     441,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   344,    -1,    -1,    -1,   114,    -1,    -1,    -1,
     299,    -1,    -1,   302,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   477,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   490,
      -1,    -1,    -1,   670,    -1,   299,    -1,   604,   302,    -1,
      -1,    -1,    -1,    -1,   505,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   114,    -1,    -1,   408,    -1,    -1,    -1,
      -1,    -1,   523,    -1,    -1,    -1,    -1,    -1,   420,    -1,
     299,    -1,   240,   302,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   445,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   670,    -1,    -1,    18,    19,   299,    -1,
      -1,   302,    24,    25,    26,    27,    -1,    -1,    -1,    -1,
      -1,    -1,   240,   422,   476,    -1,    -1,   479,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   437,   491,
     492,    -1,   441,   604,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   422,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   437,    -1,    -1,   344,   441,   477,   240,
     532,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    18,
      19,    20,   544,   422,    -1,    24,    25,    26,    27,    -1,
      -1,    -1,   114,    -1,    -1,    -1,   505,    -1,   437,   670,
      -1,    -1,   441,   477,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   523,    -1,    -1,    -1,    -1,    -1,
      -1,   422,    -1,   585,    -1,    -1,    -1,    -1,    -1,    -1,
     408,   505,    -1,    -1,    -1,    -1,   437,    -1,   477,    -1,
     441,    -1,   420,    -1,    -1,    18,    19,    20,    -1,   523,
      -1,    24,    25,    26,    27,    -1,   618,    -1,    -1,    -1,
      -1,    -1,   624,    -1,    -1,    -1,   505,   445,    -1,    -1,
      -1,   633,   634,    -1,   636,   114,   477,    -1,    -1,    -1,
     408,    -1,    -1,    -1,   523,    -1,   648,   649,    -1,    -1,
      -1,    -1,   420,    -1,   656,   604,    -1,   659,   476,    -1,
      -1,   479,    -1,    -1,   505,   667,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   491,   492,    -1,    -1,   445,   240,    -1,
      -1,    -1,   523,    -1,    -1,    -1,    18,    19,    20,    -1,
     604,    -1,    24,    25,    26,    27,    -1,   408,    -1,    -1,
      -1,   114,    -1,    -1,    -1,    -1,    -1,    -1,   476,   420,
      -1,   479,    -1,    -1,   532,    -1,    -1,    -1,    -1,    -1,
      -1,   670,    -1,    -1,   492,   604,   544,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   445,    -1,    18,    19,    -1,    -1,
      -1,    -1,    24,    25,    26,    27,    -1,    -1,    -1,    -1,
      -1,   519,    -1,    -1,    -1,    -1,   670,    -1,    -1,    -1,
      -1,   240,    -1,   604,   532,   476,    -1,   585,   479,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   544,    -1,    -1,    -1,
      -1,   492,   114,    20,    -1,    -1,    -1,    24,    25,    26,
      27,   670,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     618,    -1,    -1,    -1,    -1,    -1,   624,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   633,   634,   585,   636,    -1,
     531,   532,    -1,    -1,    -1,    -1,    -1,   240,    -1,   670,
     648,   649,   114,   544,    -1,    -1,    18,    19,   656,    -1,
      -1,   659,    24,    25,    26,    27,   408,    -1,    -1,   667,
     618,    -1,    -1,    -1,    -1,    -1,   624,    -1,   420,    -1,
      -1,    -1,    -1,    -1,    -1,   633,   634,    -1,   636,    -1,
      -1,    -1,    -1,    -1,   585,    -1,    -1,   114,    -1,    -1,
     648,   649,    -1,   445,    24,    25,    26,    27,   656,    -1,
      -1,   659,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   667,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   618,   240,    -1,
      -1,    -1,    -1,   624,   476,    -1,    -1,   479,    -1,    -1,
      -1,    -1,   633,   634,    -1,   636,    -1,    -1,    -1,   408,
     492,    -1,   114,    -1,    -1,    -1,    -1,   648,   649,    -1,
      -1,   420,    -1,    -1,    -1,   656,    -1,    -1,   659,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   667,    -1,   240,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   445,    -1,    -1,   531,
     532,    -1,    -1,    -1,   114,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   544,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   408,    -1,   476,    -1,    -1,
     479,    -1,    -1,   240,    -1,    -1,    -1,   420,    -1,    -1,
      -1,    -1,    -1,   492,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   585,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   445,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   531,   532,    -1,    -1,    -1,    -1,   240,    -1,
      -1,    -1,   624,   476,    -1,   544,   479,    50,    51,    52,
      53,    54,    55,    -1,   636,    -1,   408,    -1,    -1,   492,
      -1,    -1,    -1,    -1,    -1,    -1,   648,   649,   420,    -1,
      -1,    -1,    -1,    -1,   656,    -1,    -1,   659,    -1,    -1,
     240,    -1,    -1,    -1,    -1,   667,   585,    -1,    -1,    -1,
      -1,    -1,    -1,   445,    -1,    -1,    -1,    -1,    -1,   532,
      -1,    -1,    -1,    -1,    -1,    -1,   408,    -1,    -1,    -1,
      -1,   544,    -1,    -1,    -1,    -1,    -1,    -1,   420,   618,
      -1,    -1,    -1,    -1,   476,   624,    -1,   479,    -1,    -1,
      -1,    -1,    -1,    -1,   633,   634,    -1,   636,    -1,    -1,
     492,    -1,    -1,   445,   147,    -1,    -1,    -1,    -1,   648,
     649,   408,   585,    -1,    -1,    -1,    -1,   656,    -1,    -1,
     659,    -1,    -1,   420,    -1,    -1,    -1,    -1,   667,    -1,
      -1,    -1,    -1,    -1,   476,    -1,    -1,   479,    -1,    -1,
     532,    -1,    -1,    -1,    -1,   618,    -1,    -1,   445,    -1,
     492,   624,   544,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     633,   634,    -1,   636,    -1,    -1,   408,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   648,   649,   519,   420,   476,
      -1,    -1,   479,   656,    -1,    -1,   659,    -1,    -1,    -1,
     532,    -1,    -1,   585,   667,   492,    -1,    -1,    -1,    -1,
      -1,    -1,   544,   445,    -1,    -1,    -1,    -1,   408,   252,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     420,    -1,    -1,    -1,    -1,    -1,   618,    -1,    -1,    -1,
      -1,    -1,   624,    -1,   476,   532,    -1,   479,    -1,    -1,
      -1,   633,   634,   585,   636,   445,    -1,   544,    -1,    -1,
     492,    -1,    -1,    -1,    -1,    -1,   648,   649,    -1,    -1,
      -1,    -1,    -1,    -1,   656,    -1,   309,   659,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   667,   476,    -1,    -1,   479,
      -1,    -1,   624,    -1,    -1,    -1,    -1,    -1,   585,    -1,
     532,   334,   492,    -1,   636,    -1,    -1,    -1,    -1,    -1,
     343,    -1,   544,    -1,    -1,    -1,   648,   649,    -1,    -1,
      -1,    -1,    -1,    -1,   656,    -1,    -1,   659,    -1,    -1,
      -1,   618,    -1,    -1,    -1,   667,    -1,   624,    -1,    -1,
      -1,    -1,   532,    -1,    -1,    -1,   633,   634,   381,   636,
      -1,   384,    -1,   585,   544,    -1,   389,    -1,    -1,    -1,
      -1,   648,   649,    -1,   397,    -1,    -1,    -1,    -1,   656,
      -1,    -1,   659,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     667,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   624,    -1,    -1,   585,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   636,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   648,   649,    -1,    -1,
      -1,    -1,    -1,    -1,   656,    -1,   459,   659,    -1,    -1,
      -1,    -1,   465,    -1,   624,   667,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   636,   480,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   648,   649,
      -1,    -1,    -1,    -1,    -1,    -1,   656,    -1,    -1,   659,
      -1,   504,    -1,    -1,    -1,    -1,    -1,   667,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   528,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   538,   539,    -1,    -1,    -1,
      -1,   544,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   554,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   576,    -1,    -1,   579,   580,    -1,    -1,
      -1,   584,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   641,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   650,    -1,   652
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const unsigned short yystos[] =
{
       0,    30,    34,   125,   286,   407,   455,   486,   515,   783,
     810,   811,   867,  1041,  1097,  1099,  1100,  1101,  1106,  1108,
    1121,  1122,  1123,  1124,  1125,  1568,    28,    29,   784,   785,
     786,   787,   788,    27,  1005,  1583,  1005,    25,  1005,  1473,
    1126,   812,  1473,   811,     0,  1098,  1101,  1124,    31,   786,
     788,   868,   659,    25,   240,   809,   810,   992,  1005,  1010,
    1106,  1121,  1127,  1162,  1163,  1164,  1165,  1166,  1170,   405,
     814,   815,   816,   817,   820,   821,   103,   110,   156,   157,
     164,   418,   513,   605,   685,   693,   783,   960,  1040,  1102,
    1103,  1105,  1109,  1110,  1116,  1128,  1132,  1282,  1292,  1568,
     664,  1005,  1165,   292,   506,   507,  1171,    20,  1005,  1169,
     667,   815,     5,   813,   405,  1005,     5,   839,   841,   842,
    1005,  1293,  1005,  1005,  1283,  1117,  1005,  1005,  1105,  1111,
     310,   349,   368,   369,   408,   420,   431,   447,   457,   472,
     512,   535,   550,   557,   560,   581,   585,   604,   622,   869,
     870,   871,   874,    25,  1162,  1168,    18,    19,    26,   109,
     121,   148,   242,   339,   374,   408,   420,   456,   471,   479,
     492,   536,   561,   585,   629,   638,   722,   723,   733,   735,
     929,   934,   945,   947,  1005,  1162,  1172,  1173,   507,    14,
     866,   817,   570,  1269,   818,   815,   820,    32,    36,   113,
     129,   130,   139,   310,   349,   368,   369,   370,   371,   386,
     408,   420,   431,   447,   457,   472,   512,   535,   550,   557,
     560,   581,   585,   604,   622,   664,   824,   833,   844,   849,
    1005,   479,   163,  1005,   809,   961,  1133,  1005,   876,   369,
     822,   479,   852,   854,   855,   853,   862,   863,   479,   479,
     875,   507,   479,   815,   850,   474,   479,   479,   479,   479,
     479,   479,   479,   479,   479,   479,   733,   479,   806,     9,
      18,    19,    24,    25,    26,   114,   344,   438,   443,   445,
     461,   476,   479,   482,   491,   532,   544,   555,   585,   636,
     648,   649,   656,   667,   903,   911,   912,   913,   914,   915,
     916,   917,   945,   946,   948,  1011,  1162,  1272,  1465,   479,
     479,   479,   479,   479,   479,    18,    19,    20,    21,    22,
     734,    26,   479,   569,     5,   475,  1172,    25,    26,  1005,
    1011,    19,    25,    26,   819,  1011,   717,   718,   719,   823,
     846,   835,   847,   822,   479,   479,   479,   836,   852,   853,
     479,   479,   834,   507,   845,   479,   850,   815,   843,   479,
      26,  1005,   479,  1118,   809,   809,   479,  1005,   479,   506,
     828,    26,   673,   417,   502,   518,   561,   600,   629,   638,
     856,   673,   417,   502,   518,   561,   600,   629,   638,   864,
      26,    26,   877,   878,   879,   880,  1005,    26,   831,   832,
      26,   667,   714,   953,   996,  1005,   996,   996,   953,   953,
     903,    25,    26,    19,    24,    25,    26,   949,   950,   951,
     952,    25,   954,   996,   997,   903,   442,   903,   903,   903,
     903,   574,  1289,   479,   479,   903,   417,   502,   518,   561,
     600,   629,   638,  1468,  1469,   479,   903,   903,   479,   479,
     918,   479,   479,   479,   479,    26,     6,     7,     8,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    44,   141,   142,   143,   144,   145,   146,   159,
     160,   161,   299,   302,   422,   437,   441,   477,   505,   523,
     604,   670,   805,   904,   919,   921,   922,   923,   924,   925,
     926,   927,    26,  1011,   469,   937,   935,   941,   939,  1162,
    1162,   733,   930,  1005,  1173,   507,   475,    26,   826,   479,
     848,   815,   848,   828,    26,    26,    26,   815,    26,    26,
     814,   831,   848,    26,   667,   108,   840,  1294,   442,   479,
    1284,  1584,  1585,  1586,  1587,  1588,   962,  1134,  1112,   667,
      26,   442,   857,   858,   479,   859,   864,   865,   859,   479,
     860,     5,   442,     5,   442,     5,   333,     5,   869,   475,
       5,     5,   442,   815,   851,   479,     5,   442,   507,   667,
     442,   442,   442,   442,   442,   442,    19,   442,   637,   950,
      19,    26,   637,   442,     5,   442,   442,     5,   807,   903,
     519,  1489,   903,   479,   673,    20,   442,  1489,    20,  1272,
     903,   903,   903,   903,   903,   903,   903,   903,   903,   903,
     903,   903,   903,   903,   903,   903,   903,   903,   903,   903,
     903,   903,   903,   479,   903,   903,   479,  1162,   903,   903,
     903,   903,   442,     5,   531,   763,   764,   765,   903,   479,
    1172,   507,   671,    26,   667,    26,   442,   442,     5,   442,
     308,     5,   442,     5,   442,   333,   475,     5,   442,   851,
    1005,  1178,  1179,  1181,  1129,  1178,   412,  1585,  1269,    37,
      38,    39,    46,    49,    56,    57,   101,   102,   106,   116,
     117,   119,   133,   150,   153,   154,   168,   170,   171,   172,
     180,   181,   183,   184,   185,   191,   194,   196,   197,   198,
     204,   206,   207,   209,   211,   212,   215,   218,   219,   220,
     221,   222,   223,   227,   228,   229,   231,   235,   237,   238,
     243,   246,   249,   251,   253,   255,   259,   260,   262,   263,
     264,   267,   269,   270,   272,   280,   281,   293,   296,   297,
     300,   301,   304,   305,   313,   314,   315,   317,   327,   328,
     329,   331,   335,   336,   340,   348,   356,   357,   358,   364,
     365,   372,   375,   379,   380,   390,   407,   415,   421,   432,
     444,   450,   452,   453,   460,   499,   510,   517,   541,   542,
     546,   558,   564,   565,   566,   567,   571,   575,   582,   583,
     593,   595,   606,   608,   611,   617,   643,   646,   651,   654,
     655,   669,   676,   699,   700,   701,   702,   703,   704,   705,
     708,   710,   712,   726,   727,   728,   729,   746,   768,   782,
     783,   789,   808,   882,   883,   884,   885,   896,   897,   898,
     899,   900,   901,   902,   955,   986,   990,  1012,  1014,  1017,
    1018,  1019,  1020,  1033,  1042,  1066,  1067,  1069,  1073,  1088,
    1089,  1093,  1094,  1095,  1096,  1104,  1119,  1139,  1150,  1151,
    1152,  1156,  1159,  1193,  1196,  1198,  1204,  1205,  1208,  1211,
    1214,  1216,  1218,  1221,  1228,  1233,  1238,  1239,  1240,  1252,
    1253,  1256,  1262,  1264,  1265,  1290,  1305,  1306,  1307,  1308,
    1309,  1321,  1327,  1328,  1348,  1351,  1380,  1382,  1474,  1475,
    1506,  1507,  1514,  1529,  1553,  1568,  1569,  1574,  1575,  1577,
    1581,  1582,  1589,   783,  1107,   672,   695,  1135,  1136,  1178,
      20,   442,   474,   829,   856,    26,   861,    26,    26,    26,
     878,   880,   872,   832,    26,  1005,   996,   733,    20,   714,
    1005,   943,  1469,    26,   943,    26,    26,   637,    24,    26,
     853,   944,   997,   854,   442,   410,   524,   633,  1497,   442,
     442,    26,  1469,   442,   442,   442,   442,   442,   442,   442,
     490,   490,   490,   928,  1489,   490,   928,  1489,   938,   936,
     942,   940,    26,   931,     5,   932,   475,  1172,   839,   442,
      20,   829,    26,   479,    26,    26,   825,    26,   667,   442,
       5,  1178,   442,  1162,  1162,  1162,  1005,    25,  1162,  1215,
    1005,    25,  1005,  1458,   401,  1006,  1007,  1583,  1006,    25,
    1005,  1457,  1005,  1005,  1236,  1000,  1006,  1000,  1005,  1579,
    1458,  1005,    26,   730,  1162,  1312,  1000,  1236,   928,    26,
    1011,  1277,  1278,  1277,   903,   910,  1350,  1457,  1457,   905,
     928,  1006,  1515,  1515,   886,  1236,  1000,  1310,  1162,  1002,
    1006,   910,  1515,  1162,  1236,  1162,  1349,  1515,    25,   633,
    1153,  1154,  1162,  1000,  1000,  1153,  1001,  1006,  1005,  1154,
    1000,  1515,  1000,  1002,  1458,  1162,  1191,  1192,   998,  1006,
    1002,   426,   609,   996,  1068,  1005,   790,  1457,  1003,  1006,
      25,   240,  1005,  1381,  1557,  1559,  1560,  1561,  1562,  1564,
     928,  1191,   673,   928,  1006,  1217,   956,    59,    60,    61,
      62,   182,   190,   199,   202,   245,   252,   309,   334,   341,
     343,   353,   381,   389,   426,   450,   487,   498,   596,   597,
     598,   609,   712,  1082,  1212,  1213,  1162,  1183,  1184,   909,
     910,  1227,   953,   953,   999,  1006,   928,  1215,  1291,  1162,
    1268,    25,  1162,  1509,  1263,   910,  1570,   155,   205,   242,
     339,   416,   456,   522,   747,   934,  1005,  1162,  1300,   770,
     910,   998,   637,  1005,  1013,  1140,   910,   998,    26,  1162,
    1090,   998,   910,  1530,   910,  1277,  1005,  1015,  1016,  1002,
    1015,   953,  1002,  1015,   953,  1021,  1015,    25,    26,   435,
     535,  1011,  1071,  1162,  1180,  1182,   115,   324,   396,   440,
     616,   696,   697,   698,   707,   737,  1023,  1025,  1027,  1029,
    1031,  1157,  1158,  1161,   387,   398,   448,   462,   551,  1383,
     687,   688,   964,   965,   966,  1005,  1137,   694,  1136,   442,
     352,   442,   442,   442,   442,   671,     5,   442,   442,   475,
     479,   673,    19,   442,   442,    26,   637,   673,    18,    19,
      20,    25,    26,   114,   408,   420,   445,   476,   479,   492,
     532,   544,   585,   618,   624,   633,   634,   636,   648,   649,
     656,   659,  1005,  1011,  1464,  1466,  1496,  1498,  1499,  1501,
    1502,  1503,  1525,  1526,  1527,  1528,  1558,  1559,  1563,  1289,
     442,  1289,  1289,  1289,  1289,  1289,  1289,    25,    25,    25,
     903,   920,   442,    25,   920,   442,   442,   442,   442,   442,
     442,   442,   765,   763,   475,   352,   442,   815,   837,   838,
     442,   442,   671,   442,  1005,  1295,  1181,   442,  1285,   104,
     105,   134,   135,   136,   503,   589,   632,  1329,  1330,  1331,
    1334,  1337,  1340,  1341,  1342,  1345,   667,   637,   659,   151,
     152,   479,   667,   637,   659,     8,   672,   475,  1457,   527,
    1237,  1180,   159,   160,   161,   643,   531,   906,   907,   910,
    1162,  1187,  1457,   736,   737,   889,   316,    43,   137,   138,
     673,  1234,   508,     5,   666,   673,   665,   665,  1194,   643,
     469,     5,   604,  1043,   508,   706,  1572,   706,   435,   792,
    1162,   594,   665,  1199,  1200,  1201,   667,    25,  1560,   507,
    1565,   378,  1379,   659,   667,   908,   910,   604,  1557,   908,
       8,   601,   999,    26,   549,   602,   716,   991,  1162,   991,
     991,   991,    25,   227,   354,   360,   361,   362,   382,   487,
     490,   498,   533,   568,   587,   588,   598,   603,   642,   674,
    1086,  1087,   991,   991,   644,  1083,   737,  1083,  1083,   992,
     992,  1083,  1083,   737,     5,   469,     5,   385,   436,     5,
     736,   131,   132,   587,   674,  1074,   709,  1573,   909,   660,
     661,   662,   663,  1267,  1269,   910,  1258,  1259,  1260,  1270,
    1271,   910,   479,   479,   479,   479,    25,   766,  1005,   479,
    1509,   396,   479,   569,   637,   626,   771,   778,   769,  1005,
      25,  1155,  1162,  1254,     8,  1257,    14,  1005,  1167,  1174,
    1175,  1177,  1185,  1186,  1229,   213,   396,   592,   625,     5,
       6,     7,     8,     9,    10,    12,    13,    14,    18,    19,
      20,    21,    22,    23,    33,    55,   112,   121,   139,   140,
     148,   155,   156,   159,   160,   161,   162,   165,   166,   205,
     227,   233,   240,   242,   247,   273,   311,   324,   330,   339,
     340,   346,   349,   350,   354,   360,   361,   367,   368,   369,
     372,   373,   374,   378,   382,   384,   391,   392,   393,   394,
     396,   397,   401,   402,   404,   405,   406,   407,   408,   409,
     410,   416,   417,   418,   420,   421,   425,   426,   427,   428,
     429,   430,   431,   432,   434,   438,   439,   440,   441,   442,
     443,   444,   445,   446,   447,   448,   449,   450,   451,   452,
     453,   454,   455,   456,   457,   458,   459,   460,   461,   462,
     463,   464,   465,   466,   467,   468,   469,   470,   471,   472,
     473,   475,   476,   479,   480,   481,   482,   483,   484,   485,
     486,   487,   488,   490,   491,   492,   493,   494,   495,   496,
     497,   498,   499,   500,   501,   502,   503,   504,   507,   508,
     509,   510,   511,   512,   513,   514,   515,   517,   518,   519,
     520,   522,   523,   524,   525,   526,   527,   528,   529,   530,
     531,   532,   533,   534,   535,   536,   537,   538,   539,   540,
     541,   542,   543,   544,   545,   546,   547,   548,   549,   550,
     551,   552,   553,   554,   555,   556,   557,   559,   560,   561,
     562,   563,   564,   567,   568,   570,   571,   572,   573,   574,
     575,   576,   577,   578,   579,   580,   581,   582,   583,   584,
     585,   586,   587,   588,   589,   590,   591,   592,   593,   594,
     595,   598,   599,   600,   601,   602,   603,   604,   605,   606,
     607,   608,   609,   610,   611,   612,   613,   614,   615,   616,
     617,   618,   619,   620,   621,   622,   623,   624,   625,   626,
     627,   628,   629,   630,   631,   632,   633,   634,   635,   636,
     637,   638,   639,   640,   641,   642,   643,   644,   645,   646,
     647,   648,   649,   650,   651,   652,   653,   654,   655,   656,
     657,   658,   659,   664,   665,   666,   667,   668,   669,   670,
     671,   672,   673,   674,   685,   693,   698,   702,   705,   706,
     707,   708,   711,   712,   714,   715,   716,  1531,  1532,  1533,
    1535,   623,     5,   706,   706,   908,  1180,  1187,  1070,   469,
       5,   201,  1048,   479,  1162,   908,   479,    26,    26,   115,
    1160,    25,  1162,  1513,  1513,  1006,  1363,  1217,   999,   169,
     271,   279,   285,   287,   298,   326,   342,   347,   359,   366,
     514,   519,   526,   548,   553,  1352,  1353,  1361,  1370,  1371,
    1377,  1378,  1384,  1385,  1395,  1415,  1419,  1485,  1486,  1516,
    1517,  1520,  1521,  1537,   967,   968,   140,   963,   974,   975,
     966,  1138,  1584,  1113,   507,   869,   832,   667,  1005,   417,
     502,   518,   561,   600,   629,   638,  1470,    26,   943,   943,
     637,    24,    26,   857,  1502,  1502,   479,   479,   417,   502,
     518,   561,   600,   629,   638,  1467,  1471,   519,  1501,   479,
     479,   479,   479,  1496,  1496,  1496,   479,   479,   479,   479,
    1005,   479,     5,   594,  1424,  1429,   664,  1005,    18,    19,
      20,    21,   141,   142,   143,   144,   145,   146,  1523,  1471,
    1471,   469,     5,   442,   442,   933,   507,     5,   442,   839,
     809,  1130,   809,   295,   308,   410,   479,   524,   540,  1399,
    1400,  1405,  1407,   479,  1005,  1346,  1347,    26,   479,  1005,
    1326,  1339,  1407,  1409,   479,  1005,  1336,   479,  1326,  1332,
       5,  1005,    25,  1005,  1005,    25,  1008,  1165,  1005,    25,
    1005,  1005,  1005,  1580,  1457,   643,   479,   479,   889,  1457,
       5,   673,   479,  1557,    25,  1010,  1235,  1234,  1235,  1509,
    1153,   910,   910,   910,   993,   994,   479,  1162,  1192,  1044,
    1045,  1046,  1457,   673,  1509,   953,  1573,  1068,  1162,   791,
     672,   910,   402,  1203,   604,  1202,  1561,   733,  1566,  1567,
    1005,    20,  1562,     5,  1554,   664,  1209,   118,   120,   122,
     665,   673,   881,  1180,  1183,   957,    18,    19,   479,  1084,
    1086,  1213,  1162,  1184,   992,   910,   396,   643,    26,  1162,
      26,  1162,   736,   203,  1266,   434,  1304,  1269,  1260,     5,
     665,  1261,  1571,  1005,    25,   953,   953,   637,   997,   670,
    1162,   751,  1005,  1005,   910,   391,   774,   778,   626,   772,
     780,    23,   284,  1142,  1146,   530,   928,   530,  1255,   910,
     506,  1171,   667,     5,  1091,   594,  1230,  1162,  1534,  1536,
     239,  1532,  1034,  1016,   953,   953,  1026,  1027,  1048,  1048,
      40,    41,    42,    45,    47,    48,   320,   323,   325,   345,
     355,   376,   399,   403,   478,  1047,  1049,  1050,  1078,  1162,
    1182,   594,   738,    26,   449,  1032,   373,  1508,  1508,   188,
     189,   485,   594,  1005,  1416,  1417,  1459,  1457,  1457,  1457,
    1354,  1457,  1457,  1005,  1518,   217,   430,   444,   487,   498,
     519,   526,   534,   556,   633,   639,  1386,  1388,  1389,  1390,
    1497,  1457,  1362,  1386,  1388,  1584,  1584,   435,   976,  1162,
     689,   690,   969,   970,   971,   529,   672,   691,   692,   711,
     979,   980,  1584,   809,    26,   830,    20,  1005,   442,   479,
     442,    24,    26,    25,    26,    25,    26,   673,  1497,   442,
     445,  1501,  1524,  1563,   410,   524,   633,  1448,  1501,  1504,
    1448,  1448,  1448,  1448,   667,  1504,  1499,   563,  1425,  1426,
    1427,  1457,   574,  1423,  1430,   383,   562,   573,  1372,  1492,
    1005,  1501,  1501,  1501,  1501,   673,   479,   673,  1558,   903,
     442,   830,   838,  1296,   809,  1286,   479,   479,   479,  1343,
    1407,   479,   479,   107,  1344,  1346,     5,  1338,  1339,   113,
     349,   369,   370,   371,   408,   420,   431,   447,   457,   472,
     520,   550,   560,   581,   585,   613,   622,  1449,  1450,  1451,
    1453,  1335,  1336,  1332,  1333,   711,  1330,   667,   637,   442,
     667,   637,   594,  1578,   479,   731,   732,  1005,  1313,   928,
     906,  1005,  1311,   664,  1206,  1234,  1234,   673,     5,     5,
       5,   627,   910,     5,   667,   531,   673,   672,   214,   216,
     320,   323,   793,   796,   797,  1078,   794,   795,  1005,   479,
    1006,   696,   697,  1207,     5,   475,   910,  1457,  1555,  1556,
    1557,   624,   664,  1210,  1005,  1005,   994,   995,   557,   953,
     889,     8,     8,   959,    26,    26,  1085,  1086,  1162,   369,
    1222,   115,   903,  1269,   268,  1271,  1277,  1584,     5,     5,
     442,   442,   767,  1005,   442,  1509,   763,   479,   479,   779,
     775,   411,   773,   910,   391,   776,   780,   644,  1080,  1147,
    1143,   413,  1141,  1142,   908,   673,  1168,    20,  1005,  1176,
    1186,    14,   531,  1231,  1232,  1501,  1563,  1183,  1584,  1028,
    1029,   598,  1004,   594,  1061,  1060,  1059,  1058,  1063,  1062,
     996,  1064,   996,  1065,  1057,  1056,  1054,  1053,  1079,   376,
    1050,  1055,   953,    50,    51,    52,    53,    54,    55,   147,
     384,   397,   459,   465,   504,   528,   538,   539,   544,   554,
     576,   579,   580,   584,   641,   652,   739,   740,  1076,  1077,
       5,    26,  1509,   298,  1162,   519,  1490,  1491,  1509,  1217,
    1484,  1486,   149,   149,   643,  1215,  1418,  1419,   479,  1396,
     200,  1430,  1457,   224,   321,  1522,   667,   673,   479,  1391,
    1391,   594,   672,     5,  1487,  1538,   393,   402,   426,   429,
     445,   549,   602,   609,   999,  1364,  1369,   673,   672,   978,
    1162,     5,   594,   972,   973,   686,   971,   977,  1005,   977,
     981,   982,   977,   376,   980,  1114,   475,    26,   943,   442,
      19,   442,   637,   442,    19,   442,   637,   417,   502,   518,
     561,   600,   629,   638,  1472,  1498,     5,  1471,     5,   442,
       5,  1501,     5,   442,  1501,  1501,  1501,  1501,  1005,   442,
     479,  1427,     5,  1005,  1463,     9,   344,   479,   491,  1433,
    1434,  1435,  1436,  1437,  1441,  1445,  1447,  1501,   419,  1421,
    1431,  1005,  1493,   666,  1448,   383,  1472,    26,  1472,   475,
     509,  1279,  1299,  1131,   509,  1241,  1273,   659,  1005,  1402,
    1404,  1457,  1461,  1462,  1406,  1461,  1406,     5,   442,  1344,
    1406,  1433,  1005,   442,  1347,     5,   442,   479,   479,   479,
    1471,  1471,   479,   479,   479,   479,   479,   256,   257,   258,
     449,  1408,  1410,     5,   442,     5,   442,  1005,  1005,    25,
    1005,  1005,    25,  1005,   910,  1005,  1323,  1324,     5,  1325,
    1326,   928,  1120,   667,  1325,   624,  1509,  1509,   910,   910,
     993,   557,   910,  1576,     5,  1045,    20,  1461,  1509,   794,
     802,   801,   803,  1005,  1009,   804,  1009,   241,   797,   800,
       5,  1048,   667,   910,     8,  1567,   507,   667,     5,  1509,
     624,  1005,  1180,   928,   601,  1367,     5,   442,  1162,     5,
      26,  1162,   377,    25,  1301,   396,   396,   507,   667,   396,
     479,   752,   756,   749,  1584,  1584,   781,   777,   773,  1081,
      25,  1004,  1148,  1162,  1584,   910,   474,   507,   928,     5,
    1035,  1030,  1031,    26,   736,  1005,  1584,  1584,  1584,  1584,
    1584,  1584,     5,  1051,     5,  1052,  1584,  1584,  1584,  1584,
    1084,  1584,  1004,    25,    14,    14,     5,   442,    26,  1457,
    1497,  1478,   643,   643,  1353,  1483,  1484,  1419,  1397,  1461,
     664,   999,   479,  1357,  1005,  1519,  1518,  1392,  1461,   511,
    1393,  1394,  1459,  1457,  1390,  1498,    95,    96,    97,    98,
      99,   631,  1541,   910,   910,   601,  1365,   999,  1393,  1457,
       5,  1162,   977,  1584,  1584,     5,   984,   985,  1584,  1584,
     983,  1107,   873,   442,    26,    26,    26,    26,   479,  1429,
    1471,   673,  1471,  1471,   442,  1501,   442,   442,   442,   442,
    1426,  1428,  1426,  1436,  1496,  1433,  1501,  1496,     6,     7,
       9,    10,    12,    13,    14,    15,    16,    17,   302,   422,
     423,   477,   604,   670,   720,   721,  1444,  1446,  1422,  1500,
    1501,   496,  1420,  1432,   318,  1322,    26,  1373,  1374,  1375,
    1461,  1490,  1493,   442,   827,   123,   124,   126,   127,   128,
     226,   234,   268,   277,   306,   307,   351,   395,   449,   675,
     676,   677,   678,   679,   680,   681,   682,   683,   684,  1276,
    1280,   187,   562,  1281,  1297,  1107,   210,   225,   226,   234,
     268,   277,   306,   351,   395,  1274,  1275,  1287,  1281,  1462,
     507,  1460,   442,     5,   667,     5,   442,   442,  1407,   442,
     442,  1339,    26,  1454,  1454,    26,   673,   479,   673,    26,
    1455,    26,    26,  1455,  1455,    25,  1464,   208,   308,   346,
     410,   424,   524,   540,  1401,  1411,  1412,  1413,  1414,  1336,
    1332,   667,   667,   586,   635,     5,   442,   732,     5,   442,
     908,   442,    20,   442,  1509,     5,   910,   614,   324,   741,
     742,   910,  1048,  1584,  1584,     5,   798,   507,   667,     5,
     799,  1584,   795,   594,    20,  1005,     5,  1005,  1197,  1566,
      20,  1461,  1556,     8,  1509,   440,   706,   908,  1368,   958,
    1086,   715,  1220,   903,     5,   763,  1162,   748,   730,  1005,
    1162,   754,   442,   763,   763,  1584,  1584,  1084,  1145,    25,
    1149,  1162,   619,   989,  1172,   531,   909,  1092,  1232,   112,
     590,  1036,  1022,  1023,   667,   996,  1584,   996,  1584,   736,
      26,  1162,    26,  1162,   740,   442,   479,  1510,  1498,  1484,
    1484,  1476,     5,   442,   519,  1495,  1358,  1461,   527,  1355,
    1495,   673,     5,   442,     5,   594,  1488,    18,    19,   114,
     476,   479,   492,   531,   532,   544,   585,   624,   636,   648,
     649,   656,   659,  1005,  1464,  1496,  1525,  1527,  1546,  1547,
    1548,  1549,  1550,  1551,  1563,  1546,  1546,  1546,  1461,  1543,
    1545,  1542,  1543,  1544,  1539,  1366,   673,  1162,  1005,  1584,
    1584,  1584,  1584,   671,    19,   442,   442,   637,    19,   442,
     442,   637,    26,   442,   673,  1472,   673,   673,     5,   442,
     442,  1434,  1435,  1439,  1502,  1439,   479,  1496,  1439,   479,
    1496,  1439,    10,   299,   437,   439,  1501,     5,  1433,     5,
     586,   635,  1376,  1322,   673,   671,  1277,  1277,  1277,    25,
    1277,  1277,  1277,  1277,  1277,  1277,    25,    25,  1277,  1280,
    1162,  1188,  1189,   666,   495,  1242,  1584,    25,    25,    26,
      26,    26,    26,    26,    25,  1162,  1275,  1242,    26,  1401,
    1461,    20,  1005,  1461,  1344,   442,   442,     5,   442,  1472,
      26,  1472,     5,  1452,     5,   442,   442,   442,  1452,  1403,
    1457,   479,  1413,  1344,  1005,  1005,  1324,   670,   724,  1318,
    1319,  1320,  1326,    58,   135,   136,   294,   670,  1314,  1315,
    1316,   516,   888,  1314,     5,   425,  1509,     5,   479,   442,
     598,  1075,  1009,  1584,   733,    20,  1005,  1009,  1584,   953,
     910,   475,  1509,     8,   953,  1183,  1584,    26,  1004,    25,
    1302,  1180,   475,   763,   753,   757,   442,  1584,  1004,   910,
     987,   475,  1038,  1037,   489,  1024,  1025,    20,  1005,  1511,
    1512,   601,  1494,  1479,  1477,  1461,  1497,   192,  1398,     5,
     442,  1356,  1519,  1461,  1394,  1393,  1494,  1549,  1549,  1548,
     479,   479,   479,   479,   479,   479,   479,  1005,   479,     5,
     442,    18,    19,    20,    21,  1523,   442,     5,   442,     5,
      14,   200,   574,  1540,  1183,  1393,   261,  1115,   869,    26,
      26,    26,    26,   442,  1472,  1472,  1472,  1426,   490,  1438,
    1438,  1442,  1443,  1464,  1563,  1438,  1442,  1438,  1439,  1501,
    1500,  1374,  1472,   839,   586,   635,  1190,     5,  1188,   111,
     186,   248,   250,   266,   274,   278,   303,  1243,  1244,  1298,
    1115,  1288,     5,   475,  1460,    26,   442,    26,  1456,   442,
      26,   442,   479,  1433,  1317,  1583,    26,  1320,    26,    26,
    1317,  1322,  1316,   996,   736,   425,  1509,   910,   743,   616,
    1195,    26,   736,   475,  1075,   442,  1509,   290,   736,   442,
     442,   479,   755,   396,   761,   442,   750,  1144,  1584,   507,
     910,  1584,  1004,     5,   442,  1183,  1429,  1498,  1461,   479,
    1429,   442,  1524,  1448,  1548,  1552,  1448,  1448,  1448,  1448,
     507,   667,  1552,  1547,  1548,  1548,  1548,  1548,  1543,    14,
    1544,  1547,   999,  1433,   193,   664,  1387,    26,   442,   442,
     442,   442,  1440,  1464,  1505,     5,   442,   442,  1438,     7,
    1189,  1245,  1246,  1162,  1248,  1162,  1247,  1249,  1244,   289,
     289,    26,   442,   673,   442,  1404,   442,   887,  1509,   443,
     252,   309,   334,   343,   381,   389,   480,   650,   740,   744,
     745,   479,   667,   736,  1219,  1303,   758,   442,  1180,   761,
     761,  1584,   988,  1172,   623,  1072,  1512,  1492,  1429,   531,
    1359,  1360,  1501,  1492,   442,  1548,     5,   442,  1548,  1548,
    1548,  1548,    26,  1005,   442,   479,  1005,   637,  1443,  1501,
    1584,  1584,  1250,  1584,  1251,  1584,  1584,   475,  1472,   442,
     288,   399,   403,   890,   891,   892,  1078,   991,   991,   991,
     991,   991,   991,    25,     5,   442,   910,    20,  1005,  1078,
    1223,  1224,  1225,   761,   763,   761,   291,   475,  1039,   736,
       5,   442,   337,   338,  1480,   442,  1548,   442,   442,   442,
     442,     5,   475,   507,  1546,    26,  1584,  1584,   894,   893,
     288,   892,   895,   745,     5,  1226,   332,  1225,   759,  1584,
    1360,    25,  1005,  1481,  1482,    26,    26,   442,   442,   637,
    1584,  1584,  1584,   910,  1584,   442,  1036,   667,   667,     5,
     475,     5,   475,    26,   442,   760,  1005,  1005,  1482,    26,
     442,   213,   396,   762,   667,   475,  1180,  1005
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
#line 997 "fgl.yacc"
    { print_screen_mode(0);}
    break;

  case 3:
#line 1000 "fgl.yacc"
    { print_screen_mode(1);}
    break;

  case 4:
#line 1004 "fgl.yacc"
    {
		print_start_server(yyvsp[-3].str,yyvsp[0].str);
	}
    break;

  case 5:
#line 1010 "fgl.yacc"
    {
	print_stop_external();
	}
    break;

  case 6:
#line 1015 "fgl.yacc"
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
#line 1027 "fgl.yacc"
    {
	sprintf(yyval.str,"%s%s",yyvsp[-2].str,yyvsp[0].str);
	}
    break;

  case 10:
#line 1032 "fgl.yacc"
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
#line 1055 "fgl.yacc"
    {sprintf(yyval.str,"(%s)",yyvsp[-1].str);}
    break;

  case 12:
#line 1056 "fgl.yacc"
    { sprintf(yyval.str,"%s%s%s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 13:
#line 1057 "fgl.yacc"
    {sprintf(yyval.str,"%d",atoi(yyvsp[0].str));}
    break;

  case 14:
#line 1058 "fgl.yacc"
    {sprintf(yyval.str,"(%s%s)",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 15:
#line 1059 "fgl.yacc"
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
#line 1070 "fgl.yacc"
    {
	sprintf(yyval.str,print_arr_expr_fcall(yyvsp[0].ptr));
}
    break;

  case 17:
#line 1076 "fgl.yacc"
    {strcpy(yyval.str,"+");}
    break;

  case 18:
#line 1077 "fgl.yacc"
    {strcpy(yyval.str,"-");}
    break;

  case 19:
#line 1078 "fgl.yacc"
    {strcpy(yyval.str,"*");}
    break;

  case 20:
#line 1079 "fgl.yacc"
    {strcpy(yyval.str,"/");}
    break;

  case 21:
#line 1080 "fgl.yacc"
    {strcpy(yyval.str,"%");}
    break;

  case 22:
#line 1085 "fgl.yacc"
    {strcpy(yyval.str,"+");}
    break;

  case 23:
#line 1086 "fgl.yacc"
    {strcpy(yyval.str,"-");}
    break;

  case 24:
#line 1097 "fgl.yacc"
    {
	 A4GL_debug("Using default attribute of WHITE");
		sprintf(yyval.str,"%d",0);}
    break;

  case 25:
#line 1100 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 26:
#line 1103 "fgl.yacc"
    {start_state("attribute",1);}
    break;

  case 27:
#line 1103 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[-1].str);
A4GL_debug("Got Attributes : %s",yyvsp[-1].str);
start_state("attribute",0);
}
    break;

  case 29:
#line 1110 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 30:
#line 1111 "fgl.yacc"
    {
sprintf(yyval.str,"%d",atoi(yyvsp[-2].str)|atoi(yyvsp[0].str));
}
    break;

  case 31:
#line 1117 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("BLACK"));}
    break;

  case 32:
#line 1118 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("BLUE"));}
    break;

  case 33:
#line 1119 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("CYAN"));}
    break;

  case 34:
#line 1120 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("GREEN"));}
    break;

  case 35:
#line 1121 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("MAGENTA"));}
    break;

  case 36:
#line 1122 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("RED"));}
    break;

  case 37:
#line 1123 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("WHITE"));}
    break;

  case 38:
#line 1124 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("YELLOW"));}
    break;

  case 39:
#line 1125 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("REVERSE"));}
    break;

  case 40:
#line 1126 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("BLINK"));}
    break;

  case 41:
#line 1127 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("UNDERLINE"));}
    break;

  case 42:
#line 1128 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("BOLD"));}
    break;

  case 43:
#line 1129 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("NORMAL"));}
    break;

  case 44:
#line 1130 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("INVISIBLE"));}
    break;

  case 45:
#line 1131 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("DIM"));}
    break;

  case 46:
#line 1132 "fgl.yacc"
    {inp_flags=inp_flags | 0x1; strcpy(yyval.str,"0");}
    break;

  case 47:
#line 1133 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 50:
#line 1140 "fgl.yacc"
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
#line 1151 "fgl.yacc"
    {start_state("attribute",0);strcpy(yyval.str,"");
}
    break;

  case 52:
#line 1155 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 53:
#line 1156 "fgl.yacc"
    {sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 54:
#line 1160 "fgl.yacc"
    { 
/*printf("Window attribute = %s\n",$<str>1);*/
form_attrib.attrib      =form_attrib.attrib|atoi(yyvsp[0].str);
/*printf("Window attribute = %d\n",form_attrib.attrib);*/
}
    break;

  case 55:
#line 1166 "fgl.yacc"
    { form_attrib.border      =1;}
    break;

  case 56:
#line 1168 "fgl.yacc"
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
#line 1179 "fgl.yacc"
    { form_attrib.comment_line=atoi(yyvsp[0].str); }
    break;

  case 58:
#line 1181 "fgl.yacc"
    { form_attrib.form_line   =atoi(yyvsp[0].str); }
    break;

  case 59:
#line 1183 "fgl.yacc"
    { form_attrib.error_line  =atoi(yyvsp[0].str); }
    break;

  case 60:
#line 1185 "fgl.yacc"
    { form_attrib.menu_line   =atoi(yyvsp[0].str); 
A4GL_debug("Set menu line to %s",yyvsp[0].str);
}
    break;

  case 61:
#line 1189 "fgl.yacc"
    { form_attrib.message_line=atoi(yyvsp[0].str); }
    break;

  case 62:
#line 1191 "fgl.yacc"
    { form_attrib.prompt_line =atoi(yyvsp[0].str); }
    break;

  case 63:
#line 1252 "fgl.yacc"
    {strcpy(yyval.str,"CALL");}
    break;

  case 64:
#line 1256 "fgl.yacc"
    { A4GL_debug("print_expr (3)"); 
		print_expr(yyvsp[-2].ptr);
		print_pop_variable(yyvsp[0].str);
	}
    break;

  case 65:
#line 1260 "fgl.yacc"
    {
        if (!isin_command("INPUT")&&!isin_command("CONSTRUCT")) {
                a4gl_yyerror("get_fldbuf can only be used in an input or construct");
                YYERROR;
        }
	print_getfldbuf(field_name_list_as_char(yyvsp[-2].field_list));
	}
    break;

  case 66:
#line 1267 "fgl.yacc"
    {
		print_returning();
	}
    break;

  case 67:
#line 1270 "fgl.yacc"
    {
	print_form_is_compiled(yyvsp[-5].str,yyvsp[-3].str,yyvsp[-1].str);
	}
    break;

  case 68:
#line 1274 "fgl.yacc"
    {
		print_field_func('I',field_name_as_char(yyvsp[-3].field_entry),yyvsp[0].str);
   }
    break;

  case 70:
#line 1278 "fgl.yacc"
    { 
        if (!isin_command("INPUT")&&!isin_command("CONSTRUCT")) {
                a4gl_yyerror("get_fldbuf can only be used in an input or construct");
                YYERROR;
        }
	print_field_func('T',field_name_list_as_char(yyvsp[-3].field_list),yyvsp[0].str);
   }
    break;

  case 71:
#line 1285 "fgl.yacc"
    {
	new_counter();
   	addmap("Call",yyvsp[-3].str,curr_func,yylineno,infilename);
   }
    break;

  case 72:
#line 1291 "fgl.yacc"
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
#line 1300 "fgl.yacc"
    {
	print_returning();
	/* strcpy($<str>$,$<str>5); */
   }
    break;

  case 74:
#line 1304 "fgl.yacc"
    {
	new_counter();
   	addmap("Call",yyvsp[-1].str,curr_func,yylineno,infilename);
   }
    break;

  case 75:
#line 1309 "fgl.yacc"
    {
 A4GL_debug("Got args");
   }
    break;

  case 76:
#line 1313 "fgl.yacc"
    {
	int a;
	dump_expr(yyvsp[-2].ptr);
	a=get_counter_val();
	drop_counter();
  	print_func_call(yyvsp[-5].str,yyvsp[-2].ptr,a);
   }
    break;

  case 77:
#line 1321 "fgl.yacc"
    {
	print_returning();
	/* strcpy($<str>$,$<str>5);  */
   }
    break;

  case 78:
#line 1325 "fgl.yacc"
    {
	A4GLSQL_set_status(0,0);
	new_counter();
	}
    break;

  case 79:
#line 1329 "fgl.yacc"
    {
   sprintf(yyval.str,"%d",get_counter_val());drop_counter();
}
    break;

  case 80:
#line 1331 "fgl.yacc"
    {
        print_expr ((struct expr_str *)yyvsp[-3].ptr);  
	print_call_shared(yyvsp[-6].str,yyvsp[-8].str,atoi(yyvsp[-2].str));
	print_returning();
	print_end_call_shared();
}
    break;

  case 81:
#line 1337 "fgl.yacc"
    {
	sprintf(yyval.str,"\"%s\",\"%s\"",yyvsp[-3].str,yyvsp[-1].str);
	A4GLSQL_set_status(0,0);
	new_counter();
	}
    break;

  case 82:
#line 1342 "fgl.yacc"
    {
   	sprintf(yyval.str,"%d",get_counter_val());drop_counter();
}
    break;

  case 83:
#line 1345 "fgl.yacc"
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
#line 1361 "fgl.yacc"
    {
   char buff[256];
   new_counter();
   sprintf(buff,"%s:%s(%p)",yyvsp[-6].str,yyvsp[-4].str,yyvsp[-2].str);
   addmap("External",buff,curr_func,yylineno,infilename);
   }
    break;

  case 85:
#line 1368 "fgl.yacc"
    {
   sprintf(yyval.str,"%d",get_counter_val());drop_counter();
   }
    break;

  case 86:
#line 1372 "fgl.yacc"
    {
	 A4GL_debug("print_expr (6)");print_expr(yyvsp[-2].ptr);
   }
    break;

  case 87:
#line 1376 "fgl.yacc"
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
#line 1398 "fgl.yacc"
    {start_bind('i',0);strcpy(yyval.str,"0");}
    break;

  case 89:
#line 1398 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);
}
    break;

  case 90:
#line 1402 "fgl.yacc"
    {start_bind('i',0);strcpy(yyval.str,"0");}
    break;

  case 91:
#line 1403 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 92:
#line 1404 "fgl.yacc"
    {strcpy(yyval.str,"WITHOUT WAITING"); }
    break;

  case 93:
#line 1409 "fgl.yacc"
    {
			yyval.ptr=A4GL_new_expr("");
		}
    break;

  case 94:
#line 1412 "fgl.yacc"
    {
			yyval.ptr=yyvsp[0].ptr;
		}
    break;

  case 95:
#line 1418 "fgl.yacc"
    {
	yyval.ptr=yyvsp[0].ptr;
}
    break;

  case 96:
#line 1421 "fgl.yacc"
    {
		yyval.ptr=A4GL_append_expr_expr(yyvsp[-2].ptr,yyvsp[0].ptr);
}
    break;

  case 98:
#line 1430 "fgl.yacc"
    {yyval.ptr=A4GL_new_expr("A4GL_push_null(2,0);");}
    break;

  case 100:
#line 1434 "fgl.yacc"
    {
sprintf(yyval.str,"\"%s\"",yyvsp[0].str);
}
    break;

  case 101:
#line 1440 "fgl.yacc"
    {
sprintf(yyval.str,"\"%s\"",yyvsp[0].str);
}
    break;

  case 102:
#line 1443 "fgl.yacc"
    { sprintf(yyval.str,"\"%s.%s\"",yyvsp[-2].str,yyvsp[0].str); }
    break;

  case 103:
#line 1458 "fgl.yacc"
    {
push_blockcommand("CASE");
setinc(1);
A4GL_incprint();
print_case(1);
setinc(1);
}
    break;

  case 104:
#line 1468 "fgl.yacc"
    {
print_after_when(0);
pop_blockcommand("CASE");
}
    break;

  case 105:
#line 1474 "fgl.yacc"
    {  push_blockcommand("CASE"); 
setinc(1);
A4GL_incprint(); 
print_case(0);
setinc(1);
}
    break;

  case 106:
#line 1483 "fgl.yacc"
    {
print_after_when(0);
pop_blockcommand("CASE");
}
    break;

  case 111:
#line 1496 "fgl.yacc"
    {setinc(-1);A4GL_incprint();}
    break;

  case 113:
#line 1499 "fgl.yacc"
    {
A4GL_incprint();
}
    break;

  case 114:
#line 1501 "fgl.yacc"
    {A4GL_incprint();
print_after_when(0);
}
    break;

  case 116:
#line 1507 "fgl.yacc"
    {A4GL_incprint();}
    break;

  case 117:
#line 1509 "fgl.yacc"
    {A4GL_incprint();
print_after_when(0);
}
    break;

  case 118:
#line 1514 "fgl.yacc"
    {
print_when(0);

A4GL_incprint();
}
    break;

  case 119:
#line 1519 "fgl.yacc"
    {A4GL_incprint();
print_after_when(1);
setinc(-1);}
    break;

  case 120:
#line 1525 "fgl.yacc"
    {
A4GL_incprint();
print_when(1);
}
    break;

  case 121:
#line 1529 "fgl.yacc"
    {A4GL_incprint();
print_after_when(1);
setinc(-1);}
    break;

  case 122:
#line 1544 "fgl.yacc"
    {
  print_close('F',yyvsp[0].str);
 }
    break;

  case 123:
#line 1547 "fgl.yacc"
    {
  print_close('W',yyvsp[0].str);
}
    break;

  case 124:
#line 1550 "fgl.yacc"
    {
  print_close('W',yyvsp[0].str);
}
    break;

  case 125:
#line 1553 "fgl.yacc"
    {
  print_close('D',0);
}
    break;

  case 126:
#line 1556 "fgl.yacc"
    {
  print_close('S',yyvsp[0].str);
}
    break;

  case 127:
#line 1559 "fgl.yacc"
    {
  print_close('C',yyvsp[0].str);
}
    break;

  case 133:
#line 1581 "fgl.yacc"
    {
			A4GL_lex_printc("%s",yyvsp[0].str);
}
    break;

  case 136:
#line 1590 "fgl.yacc"
    {
			A4GL_lex_printc("%s\n",yyvsp[0].str);
}
    break;

  case 137:
#line 1609 "fgl.yacc"
    {
push_blockcommand("CONSTRUCT");
A4GL_new_events();
}
    break;

  case 138:
#line 1614 "fgl.yacc"
    {
	print_construct_1();
}
    break;

  case 139:
#line 1617 "fgl.yacc"
    {
	print_construct_2(yyvsp[-2].str);
A4GL_drop_events();
}
    break;

  case 140:
#line 1626 "fgl.yacc"
    {
	print_construct_3(1,yyvsp[-5].str,0,yyvsp[0].str,atoi(yyvsp[0].str));
	strcpy(yyval.str,A4GL_get_formloop_str(0));
	reset_constr();
}
    break;

  case 141:
#line 1632 "fgl.yacc"
    {
	print_construct_3(0,yyvsp[-7].str,field_name_list_as_char(yyvsp[-2].field_list),yyvsp[0].str,atoi(yyvsp[0].str));
	strcpy(yyval.str,A4GL_get_formloop_str(0));
	reset_constr();
}
    break;

  case 146:
#line 1647 "fgl.yacc"
    {
                push_construct("",yyval.str);
             }
    break;

  case 147:
#line 1651 "fgl.yacc"
    {
                sprintf(yyval.str,"%s.%s",yyvsp[-2].str,yyvsp[0].str);
                push_construct(yyvsp[-2].str,yyvsp[0].str); 
             }
    break;

  case 148:
#line 1656 "fgl.yacc"
    {
                push_construct(yyvsp[-2].str,"*");
             }
    break;

  case 151:
#line 1666 "fgl.yacc"
    { A4GL_add_event(-97,field_name_list_as_or_char(yyvsp[0].field_list)); print_befaft_field_1(field_name_list_as_or_char(yyvsp[0].field_list)); }
    break;

  case 152:
#line 1666 "fgl.yacc"
    { print_befaft_field_2(); }
    break;

  case 153:
#line 1667 "fgl.yacc"
    { A4GL_add_event(-98,field_name_list_as_or_char(yyvsp[0].field_list)); print_befaft_field_1(field_name_list_as_or_char(yyvsp[0].field_list)); }
    break;

  case 154:
#line 1667 "fgl.yacc"
    { print_befaft_field_2(); }
    break;

  case 155:
#line 1668 "fgl.yacc"
    { A4GL_add_onkey_key(yyvsp[0].str); print_onkey_1(yyvsp[0].str); }
    break;

  case 156:
#line 1668 "fgl.yacc"
    { print_onkey_2(); }
    break;

  case 157:
#line 1669 "fgl.yacc"
    { A4GL_add_event(-95,""); print_befaft_field_1("AFTER_INP"); }
    break;

  case 158:
#line 1669 "fgl.yacc"
    { print_befaft_field_2(); }
    break;

  case 159:
#line 1670 "fgl.yacc"
    { A4GL_add_event(-99,""); print_befaft_field_1("BEFORE_INP"); }
    break;

  case 160:
#line 1670 "fgl.yacc"
    { print_befaft_field_2(); }
    break;

  case 161:
#line 1678 "fgl.yacc"
    {
			yyval.field_list=new_field_list();
			yyval.field_list=append_field_to_list(yyval.field_list,yyvsp[0].field_entry);
	}
    break;

  case 162:
#line 1682 "fgl.yacc"
    {
			yyval.field_list=append_field_to_list(yyvsp[-2].field_list,yyvsp[0].field_entry);
	}
    break;

  case 163:
#line 1688 "fgl.yacc"
    {
			yyval.field_list=new_field_list();
			yyval.field_list=append_field_to_list(yyval.field_list,yyvsp[0].field_entry);
	}
    break;

  case 164:
#line 1692 "fgl.yacc"
    {
			yyval.field_list=append_field_to_list(yyvsp[-2].field_list,yyvsp[0].field_entry);
	}
    break;

  case 165:
#line 1707 "fgl.yacc"
    {
        	yyval.ptr=A4GL_new_expr("A4GL_pushop(OP_YEAR);");
	}
    break;

  case 166:
#line 1710 "fgl.yacc"
    {
        	yyval.ptr=A4GL_new_expr("A4GL_pushop(OP_MONTH);");
	}
    break;

  case 167:
#line 1713 "fgl.yacc"
    {
        	yyval.ptr=A4GL_new_expr("A4GL_pushop(OP_DAY);");
	}
    break;

  case 168:
#line 1716 "fgl.yacc"
    {
        	yyval.ptr=A4GL_new_expr("A4GL_pushop(OP_HOUR);");
	}
    break;

  case 169:
#line 1719 "fgl.yacc"
    {
        	yyval.ptr=A4GL_new_expr("A4GL_pushop(OP_MINUTE);");
	}
    break;

  case 170:
#line 1722 "fgl.yacc"
    {
        	yyval.ptr=A4GL_new_expr("A4GL_pushop(OP_SECOND);");
	}
    break;

  case 171:
#line 1731 "fgl.yacc"
    {
			yyval.ptr=A4GL_append_expr_expr(yyvsp[-2].ptr,yyvsp[-1].ptr);
		}
    break;

  case 172:
#line 1739 "fgl.yacc"
    { 
	char buff[50];
	sprintf(buff,"A4GL_push_int(%d);",(19*16)+10); 
	yyval.ptr=A4GL_new_expr(buff);
}
    break;

  case 173:
#line 1744 "fgl.yacc"
    { 
	char buff[50];
	sprintf(buff,"A4GL_push_int(%d);",(atoi(yyvsp[-2].str)*16) +atoi(yyvsp[0].str)  ); 
	yyval.ptr=A4GL_new_expr(buff);
}
    break;

  case 174:
#line 1757 "fgl.yacc"
    {
				print_defer(0);
			}
    break;

  case 175:
#line 1761 "fgl.yacc"
    {
				print_defer(1);
			}
    break;

  case 176:
#line 1776 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 177:
#line 1777 "fgl.yacc"
    {strcpy(yyval.str,"");lastlineno=yylineno;}
    break;

  case 180:
#line 1785 "fgl.yacc"
    {dtypelist[0]=0;A4GL_lex_printcomment("/* define */\n");}
    break;

  case 181:
#line 1785 "fgl.yacc"
    {A4GL_lex_printcomment("/*end def */\n");}
    break;

  case 186:
#line 1794 "fgl.yacc"
    {in_define=1;}
    break;

  case 187:
#line 1794 "fgl.yacc"
    {in_define=0;strcpy(yyval.str,yyvsp[0].str);
                        set_yytext(yyval.str);
                        if (A4GL_bad_identifiers(yyval.str)) {
                                a4gl_yyerror("You can't use this identifier as it is a reserved word in the target language");
                        }
}
    break;

  case 188:
#line 1803 "fgl.yacc"
    { add_constant('c',yyvsp[0].str,yyvsp[-2].str); addmap("Constant",yyvsp[-2].str,curr_func,yylineno,infilename); }
    break;

  case 189:
#line 1804 "fgl.yacc"
    { add_constant('C',yyvsp[0].str,yyvsp[-2].str); addmap("Constant",yyvsp[-2].str,curr_func,yylineno,infilename); }
    break;

  case 190:
#line 1805 "fgl.yacc"
    { add_constant('f',yyvsp[0].str,yyvsp[-2].str);
addmap("Constant",yyvsp[-2].str,curr_func,yylineno,infilename);
 }
    break;

  case 191:
#line 1808 "fgl.yacc"
    { 
add_constant('i',yyvsp[0].str,yyvsp[-2].str);
addmap("Constant",yyvsp[-2].str,curr_func,yylineno,infilename);
 }
    break;

  case 193:
#line 1813 "fgl.yacc"
    { }
    break;

  case 194:
#line 1813 "fgl.yacc"
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
#line 1830 "fgl.yacc"
    {
		sprintf(yyval.str,"-%p",yyvsp[0].str);}
    break;

  case 199:
#line 1834 "fgl.yacc"
    {
/*AF CygWin FIX */
push_name(yyval.str,0);
addmap("Define",yyvsp[0].str,curr_func,yylineno,infilename);
}
    break;

  case 204:
#line 1849 "fgl.yacc"
    {strcpy(yyval.str,"-1");}
    break;

  case 205:
#line 1850 "fgl.yacc"
    {strcpy(yyval.str,"-1");}
    break;

  case 206:
#line 1851 "fgl.yacc"
    {strcpy(yyval.str,"-2");}
    break;

  case 207:
#line 1852 "fgl.yacc"
    {strcpy(yyval.str,"-3");}
    break;

  case 208:
#line 1857 "fgl.yacc"
    {
 A4GL_debug("defines array %s",yyvsp[-1].str);
	push_type(0,0,yyvsp[-1].str);
}
    break;

  case 210:
#line 1863 "fgl.yacc"
    {
 A4GL_debug("defines array %s",yyvsp[0].str);
	push_type(0,0,yyvsp[0].str);
}
    break;

  case 212:
#line 1872 "fgl.yacc"
    {
	push_associate(yyvsp[-5].str,yyvsp[-1].str);
	push_type(0,0,yyvsp[-1].str);
}
    break;

  case 213:
#line 1876 "fgl.yacc"
    {
    /* void pop_associate (char *a); */
	pop_associate(0);

}
    break;

  case 219:
#line 1892 "fgl.yacc"
    {sprintf(yyval.str,"%s][%s][%s",yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str); A4GL_debug("Triplet");}
    break;

  case 220:
#line 1894 "fgl.yacc"
    {sprintf(yyval.str,"%s][%s",yyvsp[-2].str,yyvsp[0].str); A4GL_debug("double");}
    break;

  case 221:
#line 1895 "fgl.yacc"
    {A4GL_debug("Single");}
    break;

  case 223:
#line 1902 "fgl.yacc"
    {push_record();in_record++;}
    break;

  case 224:
#line 1902 "fgl.yacc"
    {pop_record();in_record--;}
    break;

  case 225:
#line 1903 "fgl.yacc"
    {in_record++;push_record();A4GL_debug("Like\n");}
    break;

  case 226:
#line 1904 "fgl.yacc"
    {A4GL_debug("Link Table : %s\n",yyvsp[-2].str);
                  push_rectab(yyvsp[-2].str);
                  pop_record();in_record--;}
    break;

  case 227:
#line 1907 "fgl.yacc"
    {
		push_record();A4GL_debug("Like\n");}
    break;

  case 228:
#line 1909 "fgl.yacc"
    {
		  A4GL_debug("Table:%s\n",yyvsp[-4].str);
		  add_link_to(yyvsp[-4].str,yyvsp[-1].str);
	          A4GL_debug("Push record...\n");
                  push_rectab(yyvsp[-4].str);
                  pop_record();
}
    break;

  case 230:
#line 1919 "fgl.yacc"
    {
	sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 235:
#line 1934 "fgl.yacc"
    {start_state("dtype",1);}
    break;

  case 236:
#line 1934 "fgl.yacc"
    {start_state("dtype",0);}
    break;

  case 240:
#line 1940 "fgl.yacc"
    {push_type("char","1",0);}
    break;

  case 241:
#line 1941 "fgl.yacc"
    {push_type("char","1",0);}
    break;

  case 242:
#line 1942 "fgl.yacc"
    { if (atoi(yyvsp[-1].str)==4) { addmap("size=4","----",curr_func,yylineno,infilename); } push_type("char",yyvsp[-1].str,0); }
    break;

  case 243:
#line 1943 "fgl.yacc"
    { if (atoi(yyvsp[-1].str)==4) { addmap("size=4","----",curr_func,yylineno,infilename); } push_type("char",yyvsp[-1].str,0); }
    break;

  case 244:
#line 1944 "fgl.yacc"
    {push_type("varchar",yyvsp[-1].str,0);}
    break;

  case 245:
#line 1945 "fgl.yacc"
    {push_type("varchar",yyvsp[-3].str,0);}
    break;

  case 246:
#line 1946 "fgl.yacc"
    {push_type("char",yyvsp[-1].str,0);}
    break;

  case 247:
#line 1947 "fgl.yacc"
    {push_type("char",yyvsp[-3].str,0);}
    break;

  case 248:
#line 1948 "fgl.yacc"
    {push_type("long",0,0);}
    break;

  case 249:
#line 1949 "fgl.yacc"
    {
A4GL_debug("Using specified type...");
push_dim(yyvsp[0].str);}
    break;

  case 250:
#line 1952 "fgl.yacc"
    {push_type("int",0,0);}
    break;

  case 251:
#line 1953 "fgl.yacc"
    {push_type("form",0,0);}
    break;

  case 252:
#line 1954 "fgl.yacc"
    {push_type("form",0,0);}
    break;

  case 253:
#line 1955 "fgl.yacc"
    { char buff[256];
				sprintf(buff,"%d",16*256+2);
				push_type("fgldecimal",buff,0);
				}
    break;

  case 254:
#line 1959 "fgl.yacc"
    {
				char buff[256];
				sprintf(buff,"%d",atoi(yyvsp[-1].str)*256+2);
				push_type("fgldecimal",buff,0);
}
    break;

  case 255:
#line 1964 "fgl.yacc"
    {
char buff[256];
sprintf(buff,"%d",atoi(yyvsp[-3].str)*256+atoi(yyvsp[-1].str));
push_type("fgldecimal",buff,0);
}
    break;

  case 256:
#line 1969 "fgl.yacc"
    {
			char buff[256];
			sprintf(buff,"%d",16*256+2);
			push_type("fglmoney",buff,0);}
    break;

  case 257:
#line 1973 "fgl.yacc"
    {
		char buff[256];sprintf(buff,"%d",atoi(yyvsp[-1].str)*256+2);
			push_type("fglmoney",buff,0);}
    break;

  case 258:
#line 1976 "fgl.yacc"
    {
char buff[256];
sprintf(buff,"%d",atoi(yyvsp[-3].str)*256+atoi(yyvsp[-1].str));
push_type("fglmoney",buff,0);}
    break;

  case 259:
#line 1980 "fgl.yacc"
    {push_type("double",0,0);}
    break;

  case 261:
#line 1981 "fgl.yacc"
    {push_type("double",0,0);}
    break;

  case 263:
#line 1982 "fgl.yacc"
    {push_type("float",0,0);}
    break;

  case 265:
#line 1983 "fgl.yacc"
    {push_type("fgldate",0,0);}
    break;

  case 266:
#line 1984 "fgl.yacc"
    {push_type("fglbyte",0,0);}
    break;

  case 267:
#line 1985 "fgl.yacc"
    {push_type("fglbyte",0,0);}
    break;

  case 268:
#line 1986 "fgl.yacc"
    {push_type("fgltext",0,0);}
    break;

  case 269:
#line 1987 "fgl.yacc"
    {push_type("fgltext",0,0);}
    break;

  case 270:
#line 1988 "fgl.yacc"
    {
push_type("struct_dtime",yyvsp[0].str,0);
}
    break;

  case 271:
#line 1991 "fgl.yacc"
    {push_type("struct_ival",yyvsp[0].str,0);}
    break;

  case 272:
#line 1992 "fgl.yacc"
    {push_like(yyvsp[0].str);A4GL_lex_printcomment("/*added(XXXXX)\n */");}
    break;

  case 273:
#line 1993 "fgl.yacc"
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

  case 276:
#line 2028 "fgl.yacc"
    {
A4GL_lex_printcomment("/*column like(ZZZ)\n*/"); sprintf(yyval.str,"%s.%s",yyvsp[-2].str,yyvsp[0].str); A4GL_lex_printcomment ("/*set col...(ZZZ)\n*/");}
    break;

  case 277:
#line 2032 "fgl.yacc"
    {A4GL_debug("--->%s\n",yyvsp[0].str);strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 278:
#line 2034 "fgl.yacc"
    {A4GL_debug("--->%s\n",yyvsp[0].str);strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 279:
#line 2036 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 280:
#line 2038 "fgl.yacc"
    {
A4GL_debug("Real datetime %s to %s\n",yyvsp[-2].str,yyvsp[0].str);
sprintf(yyval.str,"%d",(atoi(yyvsp[-2].str)*16)+atoi(yyvsp[0].str)); }
    break;

  case 281:
#line 2043 "fgl.yacc"
    {
	sprintf(yyval.str,"%d",(atoi(yyvsp[-2].str)*16)+atoi(yyvsp[0].str)); 
}
    break;

  case 282:
#line 2047 "fgl.yacc"
    {start_state("dtime_val",1);}
    break;

  case 283:
#line 2047 "fgl.yacc"
    {start_state("dtime_val",0); strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 284:
#line 2051 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 285:
#line 2052 "fgl.yacc"
    {strcpy(yyval.str,"2");}
    break;

  case 286:
#line 2053 "fgl.yacc"
    {strcpy(yyval.str,"3");}
    break;

  case 287:
#line 2054 "fgl.yacc"
    {strcpy(yyval.str,"4");}
    break;

  case 288:
#line 2055 "fgl.yacc"
    {strcpy(yyval.str,"5");}
    break;

  case 289:
#line 2056 "fgl.yacc"
    {strcpy(yyval.str,"6");}
    break;

  case 290:
#line 2058 "fgl.yacc"
    {
A4GL_debug("opt_frac returns %s",yyvsp[0].str);
sprintf(yyval.str,"%d",atoi(yyvsp[0].str)+6); }
    break;

  case 291:
#line 2063 "fgl.yacc"
    {start_state("dtime_val",1);}
    break;

  case 292:
#line 2063 "fgl.yacc"
    { A4GL_debug ("Got end");start_state("dtime_val",0);  strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 293:
#line 2066 "fgl.yacc"
    {
A4GL_debug("Nothing in fraction - assume 2");
strcpy(yyval.str,"2");}
    break;

  case 294:
#line 2068 "fgl.yacc"
    {
A4GL_debug("Read fraction .. ");
A4GL_debug("    %s",yyvsp[-1].str);
strcpy(yyval.str,yyvsp[-1].str);
}
    break;

  case 295:
#line 2074 "fgl.yacc"
    {
A4GL_debug("Nothing in fraction - assume 2");
strcpy(yyval.str,"2");}
    break;

  case 296:
#line 2076 "fgl.yacc"
    {
A4GL_debug("    %s",yyvsp[-1].str);
strcpy(yyval.str,yyvsp[-1].str);
}
    break;

  case 297:
#line 2082 "fgl.yacc"
    {
if (atoi(yyvsp[0].str)>5) {
a4gl_yyerror("Fraction values are between 0 and 5");
YYERROR;
}
}
    break;

  case 298:
#line 2090 "fgl.yacc"
    {start_state("interval_val",1);}
    break;

  case 299:
#line 2090 "fgl.yacc"
    {start_state("interval_val",0); sprintf(yyval.str,"%d",atoi(yyvsp[0].str)*16+atoi(yyvsp[-1].str));}
    break;

  case 300:
#line 2093 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 301:
#line 2094 "fgl.yacc"
    {strcpy(yyval.str,"2");}
    break;

  case 302:
#line 2095 "fgl.yacc"
    {strcpy(yyval.str,"3");}
    break;

  case 303:
#line 2096 "fgl.yacc"
    {strcpy(yyval.str,"4");}
    break;

  case 304:
#line 2097 "fgl.yacc"
    {strcpy(yyval.str,"5");}
    break;

  case 305:
#line 2098 "fgl.yacc"
    {strcpy(yyval.str,"6");}
    break;

  case 306:
#line 2100 "fgl.yacc"
    {
A4GL_debug("opt_frac returns %s",yyvsp[0].str);
sprintf(yyval.str,"%d",atoi(yyvsp[0].str)+6); }
    break;

  case 310:
#line 2121 "fgl.yacc"
    {
              	dim_set_name(yyvsp[0].str);
              }
    break;

  case 314:
#line 2130 "fgl.yacc"
    {dim_push_type("char","1",0);}
    break;

  case 315:
#line 2132 "fgl.yacc"
    {dim_push_type("char",yyvsp[-1].str,0);}
    break;

  case 316:
#line 2133 "fgl.yacc"
    {
						dim_push_type("varchar",yyvsp[-1].str,0);
				}
    break;

  case 317:
#line 2136 "fgl.yacc"
    {
						char buff[256];
						sprintf(buff,"%d",atoi(yyvsp[-3].str)*256+atoi(yyvsp[-1].str));
						dim_push_type("varchar",buff,0);}
    break;

  case 318:
#line 2140 "fgl.yacc"
    {dim_push_type("long",0,0);}
    break;

  case 319:
#line 2141 "fgl.yacc"
    {dim_push_type("integer",0,0);}
    break;

  case 320:
#line 2142 "fgl.yacc"
    {dim_push_type("FORM",0,0);}
    break;

  case 321:
#line 2143 "fgl.yacc"
    {
char buff[256];
sprintf(buff,"%d",16*256+2);
dim_push_type("fgldecimal",buff,0);
}
    break;

  case 322:
#line 2148 "fgl.yacc"
    {

char buff[256];
sprintf(buff,"%d",atoi(yyvsp[-1].str)*256+2);
dim_push_type("fgldecimal",buff,0);
}
    break;

  case 323:
#line 2155 "fgl.yacc"
    {
char buff[256];
sprintf(buff,"%d",atoi(yyvsp[-3].str)*256+atoi(yyvsp[-1].str));
dim_push_type("fgldecimal",buff,0);
}
    break;

  case 324:
#line 2160 "fgl.yacc"
    {dim_push_type("fglmoney",0,0);}
    break;

  case 325:
#line 2162 "fgl.yacc"
    {dim_push_type("fglmoney",0,0);}
    break;

  case 326:
#line 2164 "fgl.yacc"
    {dim_push_type("fglmoney",0,0);}
    break;

  case 327:
#line 2165 "fgl.yacc"
    {dim_push_type("double",0,0);}
    break;

  case 328:
#line 2166 "fgl.yacc"
    {dim_push_type("float",0,0);}
    break;

  case 329:
#line 2167 "fgl.yacc"
    {dim_push_type("fgldate",0,0);}
    break;

  case 330:
#line 2168 "fgl.yacc"
    {dim_push_type("fglbyte",0,0);}
    break;

  case 331:
#line 2169 "fgl.yacc"
    {dim_push_type("fgltext",0,0);}
    break;

  case 332:
#line 2170 "fgl.yacc"
    {
dim_push_type("struct_dtime",yyvsp[0].str,0);
}
    break;

  case 333:
#line 2173 "fgl.yacc"
    {dim_push_type("struct_ival",0,0);}
    break;

  case 334:
#line 2175 "fgl.yacc"
    {dim_push_like(yyvsp[0].str);A4GL_lex_printcomment("/*added(XXXXX)\n */");}
    break;

  case 335:
#line 2181 "fgl.yacc"
    {
A4GL_lex_printcomment("/*column like(ZZZ)\n*/");
sprintf(yyval.str,"%s.%s",yyvsp[-2].str,yyvsp[0].str)
; A4GL_lex_printcomment ("/*set col...(ZZZ)\n*/");}
    break;

  case 336:
#line 2189 "fgl.yacc"
    {
dim_push_type(0,0,yyvsp[-1].str);
}
    break;

  case 338:
#line 2197 "fgl.yacc"
    {
dim_push_associate(yyvsp[-5].str,yyvsp[-1].str);
dim_push_type(0,0,yyvsp[-1].str);
}
    break;

  case 339:
#line 2201 "fgl.yacc"
    {
	/* void dim_pop_associate (char *a); */
	dim_pop_associate(0);
}
    break;

  case 340:
#line 2209 "fgl.yacc"
    {dim_push_record();}
    break;

  case 341:
#line 2210 "fgl.yacc"
    {dim_pop_record();}
    break;

  case 342:
#line 2211 "fgl.yacc"
    {dim_push_record();A4GL_debug("Like\n");}
    break;

  case 343:
#line 2212 "fgl.yacc"
    {A4GL_debug("Table:%s\n",yyvsp[-2].str);
                                  dim_push_rectab(yyvsp[-2].str);
                                  dim_pop_record();}
    break;

  case 349:
#line 2231 "fgl.yacc"
    { dim_push_name(yyval.str,0); }
    break;

  case 350:
#line 2243 "fgl.yacc"
    {
	print_display_line();
		strcpy(yyval.str,A4GL_get_display_str(0,0,0));
	}
    break;

  case 351:
#line 2247 "fgl.yacc"
    {
		strcpy(yyval.str,A4GL_get_display_str(1,0,0)); /* FIXME */
	}
    break;

  case 352:
#line 2250 "fgl.yacc"
    { 
	strcpy(yyval.str,"#error not implemented yet");
	}
    break;

  case 353:
#line 2253 "fgl.yacc"
    { strcpy(yyval.str, A4GL_get_display_str(4,0,0)); }
    break;

  case 354:
#line 2254 "fgl.yacc"
    { strcpy(yyval.str, A4GL_get_display_str(2,field_name_list_as_char(yyvsp[0].field_list),0)); }
    break;

  case 355:
#line 2255 "fgl.yacc"
    { strcpy(yyval.str, A4GL_get_display_str(3,field_name_list_as_char(yyvsp[0].field_list),yyvsp[-2].str)); }
    break;

  case 356:
#line 2256 "fgl.yacc"
    { strcpy(yyval.str, A4GL_get_display_str(5,yyvsp[-1].str,0)); }
    break;

  case 357:
#line 2257 "fgl.yacc"
    { 
	strcpy(yyval.str,"#error not implemented yet");
 }
    break;

  case 358:
#line 2263 "fgl.yacc"
    {
		print_display_by_name(yyvsp[0].str);
                }
    break;

  case 359:
#line 2270 "fgl.yacc"
    { 
				print_display(yyvsp[-1].str,yyvsp[-2].str,yyvsp[0].str);
		}
    break;

  case 360:
#line 2275 "fgl.yacc"
    {
		print_display_form(yyvsp[-1].str,yyvsp[0].str);
	}
    break;

  case 361:
#line 2280 "fgl.yacc"
    {
		push_blockcommand("DISPLAY");
		curr_input_array_attribs.curr_row_display=0;
		}
    break;

  case 362:
#line 2285 "fgl.yacc"
    {
		print_display_array_p1(fgl_add_scope(yyvsp[-6].str,0),yyvsp[-4].str,yyvsp[-1].str,yyvsp[0].str,&curr_input_array_attribs);
	  	A4GL_new_events();
		}
    break;

  case 363:
#line 2289 "fgl.yacc"
    {
		add_continue_blockcommand ("DISPLAY");  
		print_display_array_p2();
		pop_blockcommand("DISPLAY");
	  	A4GL_drop_events();
}
    break;

  case 364:
#line 2298 "fgl.yacc"
    {
strcpy(yyval.str,"0,0");
}
    break;

  case 365:
#line 2300 "fgl.yacc"
    {
	strcpy(yyval.str,field_name_as_char(yyvsp[0].field_entry));
}
    break;

  case 366:
#line 2305 "fgl.yacc"
    {
				sprintf(yyval.str,"0x%lx",atol(yyvsp[0].str));
			}
    break;

  case 372:
#line 2317 "fgl.yacc"
    {
		A4GL_add_event(-11,"");
		print_befaft_field_1("AFT_ROW");
		}
    break;

  case 373:
#line 2321 "fgl.yacc"
    {
		print_befaft_field_2();
	}
    break;

  case 374:
#line 2324 "fgl.yacc"
    {
		A4GL_add_event(-10,"");
		print_befaft_field_1("BEF_ROW");
		}
    break;

  case 375:
#line 2328 "fgl.yacc"
    {
		print_befaft_field_2();
	}
    break;

  case 376:
#line 2331 "fgl.yacc"
    {
		A4GL_add_onkey_key(yyvsp[0].str);
		print_onkey_1(yyvsp[0].str);
		}
    break;

  case 377:
#line 2335 "fgl.yacc"
    {
		print_onkey_2();
	}
    break;

  case 378:
#line 2342 "fgl.yacc"
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

  case 379:
#line 2360 "fgl.yacc"
    {
		print_dealloc_arr(yyvsp[0].str);
	}
    break;

  case 380:
#line 2366 "fgl.yacc"
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

  case 381:
#line 2390 "fgl.yacc"
    {
			print_error(yyvsp[0].str,0);
		}
    break;

  case 382:
#line 2393 "fgl.yacc"
    { 
			print_error(yyvsp[-1].str,1);
	}
    break;

  case 383:
#line 2408 "fgl.yacc"
    {
	print_exit_program(0);
}
    break;

  case 384:
#line 2411 "fgl.yacc"
    {
	print_exit_program(1);
}
    break;

  case 385:
#line 2425 "fgl.yacc"
    { if (in_command("WHILE")) { exit_loop("WHILE"); } else { YYERROR;} }
    break;

  case 386:
#line 2427 "fgl.yacc"
    { if (in_command("INPUT")) { exit_loop("INPUT"); } else { YYERROR;} }
    break;

  case 387:
#line 2429 "fgl.yacc"
    { if (in_command("FOREACH")) { exit_loop("FOREACH"); } else { YYERROR;} }
    break;

  case 388:
#line 2431 "fgl.yacc"
    { if (in_command("FOR")) { exit_loop("FOR"); } else { YYERROR;} }
    break;

  case 389:
#line 2433 "fgl.yacc"
    { if (in_command("CONSTRUCT")) { exit_loop("CONSTRUCT"); } else { YYERROR;} }
    break;

  case 390:
#line 2435 "fgl.yacc"
    { if (in_command("DISPLAY")) { exit_loop("DISPLAY"); } else { YYERROR;} }
    break;

  case 391:
#line 2436 "fgl.yacc"
    {
	if (in_command("MENU")) {
		exit_loop("MENU");
		/* A4GL_lex_printc("cmd_no=-3;continue;\n"); */
	} 
              else YYERROR;}
    break;

  case 392:
#line 2443 "fgl.yacc"
    { if (in_command("CASE")) { exit_loop("CASE"); } else { YYERROR;} }
    break;

  case 393:
#line 2445 "fgl.yacc"
    { if (in_command("PROMPT")) { exit_loop("PROMPT"); } else { YYERROR;} }
    break;

  case 394:
#line 2449 "fgl.yacc"
    { if (in_command("WHILE")) { continue_loop("WHILE");  } else { YYERROR;} }
    break;

  case 395:
#line 2451 "fgl.yacc"
    { if (in_command("INPUT")) { continue_loop("INPUT"); } else { YYERROR;} }
    break;

  case 396:
#line 2453 "fgl.yacc"
    { if (in_command("FOREACH")) { continue_loop("FOREACH");} else { YYERROR;} }
    break;

  case 397:
#line 2455 "fgl.yacc"
    { if (in_command("FOR")) { continue_loop("FOR"); } else { YYERROR;} }
    break;

  case 398:
#line 2457 "fgl.yacc"
    { if (in_command("CONSTRUCT")) { continue_loop("CONSTRUCT"); } else { YYERROR;} }
    break;

  case 399:
#line 2459 "fgl.yacc"
    { if (in_command("DISPLAY")) { continue_loop("DISPLAY"); } else { YYERROR;} }
    break;

  case 400:
#line 2461 "fgl.yacc"
    { if (in_command("MENU")) {  continue_loop("MENU");  } else { YYERROR;} }
    break;

  case 401:
#line 2467 "fgl.yacc"
    { if (in_command("PROMPT")) { continue_loop("PROMPT"); } else { YYERROR;} }
    break;

  case 406:
#line 2484 "fgl.yacc"
    {
	dec_counter();
	yyval.ptr=A4GL_append_expr_expr(yyvsp[-1].ptr,yyvsp[0].ptr);
}
    break;

  case 409:
#line 2490 "fgl.yacc"
    {
	A4GL_debug("Got literal ptr=%p",yyvsp[0].ptr);
}
    break;

  case 410:
#line 2494 "fgl.yacc"
    {
	yyval.ptr=A4GL_new_expr("A4GL_push_int(0);");
	yyval.ptr=A4GL_append_expr_expr(yyval.ptr,yyvsp[0].ptr);
	yyval.ptr=A4GL_append_expr(yyval.ptr,"A4GL_pushop(OP_SUB);");
}
    break;

  case 411:
#line 2499 "fgl.yacc"
    {
	yyval.ptr=yyvsp[0].ptr;
}
    break;

  case 415:
#line 2509 "fgl.yacc"
    { yyval.ptr=A4GL_new_expr("A4GL_add_spaces();"); }
    break;

  case 416:
#line 2510 "fgl.yacc"
    {inc_counter();}
    break;

  case 422:
#line 2516 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_CONCAT);");
}
    break;

  case 423:
#line 2523 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 424:
#line 2523 "fgl.yacc"
    {
strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 426:
#line 2528 "fgl.yacc"
    {yyval.ptr=A4GL_new_expr("A4GL_push_null(2,0);");}
    break;

  case 427:
#line 2532 "fgl.yacc"
    {
	/*set_counter(0);*/
	sprintf(yyval.str,"%d",get_counter_val());
	A4GL_lex_printcomment("/*L1 %s*/\n",yyval.str);
}
    break;

  case 428:
#line 2538 "fgl.yacc"
    {
	sprintf(yyval.str,"%d",get_counter_val());
	A4GL_lex_printcomment("/*L2 %s*/\n",yyval.str);
}
    break;

  case 429:
#line 2546 "fgl.yacc"
    {
	/*set_counter(0);*/
	sprintf(yyval.str,"%d",get_counter_val());
	A4GL_lex_printcomment("/*L1 %s*/\n",yyval.str);
}
    break;

  case 430:
#line 2552 "fgl.yacc"
    {
	sprintf(yyval.str,"%d",get_counter_val());
	A4GL_lex_printcomment("/*L2 %s*/\n",yyval.str);
}
    break;

  case 431:
#line 2561 "fgl.yacc"
    {sprintf(yyval.str,"%d",get_counter_val());}
    break;

  case 432:
#line 2563 "fgl.yacc"
    {
	print_op("OP_CONCAT");
	dec_counter();sprintf(yyval.str,"%d",get_counter_val());
}
    break;

  case 433:
#line 2570 "fgl.yacc"
    {
	A4GL_debug("Print expr (2)");
	print_expr(yyvsp[0].ptr);
}
    break;

  case 434:
#line 2578 "fgl.yacc"
    {
	strcpy(yyval.str,"+");
}
    break;

  case 435:
#line 2582 "fgl.yacc"
    {
	strcpy(yyval.str,"-");
}
    break;

  case 436:
#line 2591 "fgl.yacc"
    {
	
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_NOT);");
}
    break;

  case 437:
#line 2596 "fgl.yacc"
    {
	yyval.ptr=A4GL_new_expr("A4GL_push_int(1);");
        inc_counter();
}
    break;

  case 438:
#line 2601 "fgl.yacc"
    {
	inc_counter();
	yyval.ptr=A4GL_new_expr("A4GL_push_int(0);");
}
    break;

  case 439:
#line 2605 "fgl.yacc"
    { yyval.ptr=yyvsp[-1].ptr; }
    break;

  case 440:
#line 2607 "fgl.yacc"
    {
	yyval.ptr=get_in_exists_sql(yyvsp[-1].sql_string,'E');
}
    break;

  case 441:
#line 2610 "fgl.yacc"
    {
	yyval.ptr=get_in_exists_sql(yyvsp[-1].sql_string,'e');
}
    break;

  case 442:
#line 2617 "fgl.yacc"
    {
	A4GL_debug("init expr %s %s",yyvsp[-1].str,yyvsp[0].str);
	sprintf(yyval.str,"%s%p",yyvsp[-1].str,yyvsp[0].str);
	sprintf(yyval.str,"%s",A4GL_get_push_literal('D',yyval.str));
	yyval.ptr=A4GL_new_expr(yyval.str);
        inc_counter();
}
    break;

  case 443:
#line 2625 "fgl.yacc"
    {
	A4GL_debug("init expr int %s %d",yyvsp[-1].str,atoi(yyvsp[0].str));
	sprintf(yyval.str,"%s%p",yyvsp[-1].str,yyvsp[0].str);
	sprintf(yyval.str,"%s",A4GL_get_push_literal('L',yyval.str));
	yyval.ptr=A4GL_new_expr(yyval.str);
	inc_counter();
}
    break;

  case 444:
#line 2637 "fgl.yacc"
    {
	sprintf(yyval.str,"%s",A4GL_get_push_literal('S',yyvsp[0].str));
	yyval.ptr=A4GL_new_expr(yyval.str);
	inc_counter();
}
    break;

  case 445:
#line 2643 "fgl.yacc"
    {
	sprintf(yyval.str,"%s",A4GL_get_push_literal('D',yyvsp[0].str));
	yyval.ptr=A4GL_new_expr(yyval.str);
	inc_counter();
}
    break;

  case 446:
#line 2649 "fgl.yacc"
    {
	sprintf(yyval.str,"%s",A4GL_get_push_literal('L',yyvsp[0].str));
	yyval.ptr=A4GL_new_expr(yyval.str);
	inc_counter();
}
    break;

  case 449:
#line 2659 "fgl.yacc"
    {
		sprintf(yyval.str,"%s\n%s",yyvsp[-2].str,yyvsp[0].str);
	}
    break;

  case 450:
#line 2665 "fgl.yacc"
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
               		strcpy(yyval.str,"A4GL_push_variable(&_rep.page_no,2);");
                  		}
          		if (A4GL_aubit_strcasecmp(yyvsp[0].str,"lineno")==0) {
               		flg=1;
               		strcpy(yyval.str,"A4GL_push_variable(&_rep.line_no,2);");
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

  case 451:
#line 2737 "fgl.yacc"
    {
	if (doing_a_print) {
		sprintf(yyval.str,"A4GL_%sset_column(&_rep);",ispdf());
	} else {
		sprintf(yyval.str,"A4GL_ensure_column();");
	}
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,yyval.str);
	
}
    break;

  case 452:
#line 2748 "fgl.yacc"
    {
	if (doing_a_print) {
		sprintf(yyval.str,"A4GL_%sset_column(&_rep);",ispdf());
	} else {
		sprintf(yyval.str,"A4GL_ensure_column();");
	}
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,yyval.str);
}
    break;

  case 453:
#line 2756 "fgl.yacc"
    {
   if (!isin_command("REPORT")) {
   a4gl_yyerror("This can only be done in a report!");
   YYERROR;
} 
insql=0;
	yyval.ptr=A4GL_new_expr(yyvsp[0].str);
}
    break;

  case 454:
#line 2764 "fgl.yacc"
    {insql=1;set_ingroup();}
    break;

  case 455:
#line 2764 "fgl.yacc"
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

  case 456:
#line 2780 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_AND);");
}
    break;

  case 457:
#line 2784 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_OR);");
}
    break;

  case 458:
#line 2790 "fgl.yacc"
    {
	yyval.ptr=yyvsp[0].ptr;
	}
    break;

  case 459:
#line 2793 "fgl.yacc"
    {
		A4GL_debug("Adding to list...");
		yyval.ptr=A4GL_append_expr_expr(yyvsp[-2].ptr,yyvsp[0].ptr);
	}
    break;

  case 460:
#line 2801 "fgl.yacc"
    {
	yyval.ptr=get_in_exists_sql(yyvsp[-1].sql_string,'I');
}
    break;

  case 461:
#line 2805 "fgl.yacc"
    {
	yyval.ptr=get_in_exists_sql(yyvsp[-1].sql_string,'i');
}
    break;

  case 462:
#line 2808 "fgl.yacc"
    {
	char buff[256];
	sprintf(buff,"A4GL_push_int(%d);",length_expr(yyvsp[-1].ptr));
	yyval.ptr=A4GL_append_expr(yyvsp[-1].ptr,buff);
	A4GL_append_expr(yyval.ptr,"A4GL_pushop(OP_IN);");
}
    break;

  case 463:
#line 2814 "fgl.yacc"
    {
	char buff[256];
	sprintf(buff,"A4GL_push_int(%d);",length_expr(yyvsp[-1].ptr));
	yyval.ptr=A4GL_append_expr(yyvsp[-1].ptr,buff);
	A4GL_append_expr(yyval.ptr,"A4GL_pushop(OP_NOTIN);");
}
    break;

  case 464:
#line 2824 "fgl.yacc"
    { 
	strcpy(yyval.str,"A4GL_pushop(OP_ISNULL);");
	yyval.ptr=A4GL_new_expr(yyval.str);
}
    break;

  case 465:
#line 2829 "fgl.yacc"
    {
	strcpy(yyval.str,"A4GL_pushop(OP_ISNOTNULL);");
	yyval.ptr=A4GL_new_expr(yyval.str);
}
    break;

  case 466:
#line 2836 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_push_char(\"\\\\\");A4GL_pushop(OP_MATCHES);");
 }
    break;

  case 467:
#line 2839 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_push_char(\"\\\\\");A4GL_pushop(OP_MATCHES);A4GL_pushop(OP_NOT);");
}
    break;

  case 468:
#line 2842 "fgl.yacc"
    {
	char buff[40];
	sprintf(buff,"A4GL_push_char(%s);A4GL_pushop(OP_MATCHES);",yyvsp[0].str);
	yyval.ptr=A4GL_append_expr(yyvsp[-2].ptr,buff);
 }
    break;

  case 469:
#line 2847 "fgl.yacc"
    {
	char buff[40];
	sprintf(buff,"A4GL_push_char(%s);A4GL_pushop(OP_MATCHES);A4GL_pushop(OP_NOT);",yyvsp[0].str);
	yyval.ptr=A4GL_append_expr(yyvsp[-2].ptr,buff);
}
    break;

  case 470:
#line 2854 "fgl.yacc"
    {
	char buff[40];
	sprintf(buff,"A4GL_push_char(\"\\\\\");A4GL_pushop(OP_LIKE);");
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,buff);
}
    break;

  case 471:
#line 2859 "fgl.yacc"
    {
	char buff[40];
	sprintf(buff,"A4GL_push_char(\"\\\\\");A4GL_pushop(OP_LIKE);A4GL_pushop(OP_NOT);");
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,buff);
}
    break;

  case 472:
#line 2864 "fgl.yacc"
    {
	char buff[40];
	sprintf(buff,"A4GL_push_char(%s);A4GL_pushop(OP_LIKE);",yyvsp[0].str);
	yyval.ptr=A4GL_append_expr(yyvsp[-2].ptr,buff);
}
    break;

  case 473:
#line 2869 "fgl.yacc"
    {
	char buff[40];
	sprintf(buff,"A4GL_push_char(%s);A4GL_pushop(OP_LIKE);A4GL_pushop(OP_NOT);",yyvsp[0].str);
	yyval.ptr=A4GL_append_expr(yyvsp[-2].ptr,buff);
}
    break;

  case 474:
#line 2880 "fgl.yacc"
    {
	strcpy(yyval.str,"A4GL_pushop(OP_CLIP);");
	yyval.ptr=A4GL_new_expr(yyval.str);
	inc_counter();
}
    break;

  case 475:
#line 2888 "fgl.yacc"
    {
	sprintf(yyval.str,"%s A4GL_pushop(OP_USING);",yyvsp[0].str);
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_USING);");
}
    break;

  case 476:
#line 2896 "fgl.yacc"
    {
	A4GL_debug("PLUS in math_expr $<ptr>2 = %p",yyvsp[0].ptr);
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_ADD);");
}
    break;

  case 477:
#line 2901 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_SUB);");
}
    break;

  case 478:
#line 2905 "fgl.yacc"
    {
      sprintf(yyval.str,"%s A4GL_A4GL_pushop(OP_MULT);",yyvsp[0].str);
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_MULT);");
}
    break;

  case 479:
#line 2910 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_DIV);");
}
    break;

  case 480:
#line 2914 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_MOD);");
}
    break;

  case 481:
#line 2918 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_POWER);");
}
    break;

  case 482:
#line 2924 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_EQUAL);");
}
    break;

  case 483:
#line 2927 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_EQUAL);");
}
    break;

  case 484:
#line 2931 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_LESS_THAN);");
}
    break;

  case 485:
#line 2935 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_GREATER_THAN);");
}
    break;

  case 486:
#line 2939 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_NOT_EQUAL);");
}
    break;

  case 487:
#line 2943 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_LESS_THAN_EQ);");
}
    break;

  case 488:
#line 2947 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_GREATER_THAN_EQ);");
}
    break;

  case 489:
#line 2954 "fgl.yacc"
    {
	reset_counter();
}
    break;

  case 490:
#line 2964 "fgl.yacc"
    { 
		addmap("Call",yyvsp[-1].str,curr_func,yylineno,infilename);
		new_counter(); 
		}
    break;

  case 491:
#line 2969 "fgl.yacc"
    { 
		sprintf(yyval.str,"%d",get_counter_val()); 
		A4GL_lex_printcomment("/*function_call_expr2 %s*/\n",yyval.str);
		drop_counter(); 
		}
    break;

  case 492:
#line 2975 "fgl.yacc"
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

  case 493:
#line 2985 "fgl.yacc"
    {
        sprintf(yyval.str,"\"%s\",\"%s\"",yyvsp[-3].str,yyvsp[-1].str);
	A4GL_debug("NEWFORMAT : %s\n",yyval.str);
        A4GLSQL_set_status(0,0);
        new_counter();
}
    break;

  case 494:
#line 2990 "fgl.yacc"
    {
	sprintf(yyval.str,"%d",get_counter_val());  
	drop_counter();
}
    break;

  case 495:
#line 2993 "fgl.yacc"
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

  case 496:
#line 3007 "fgl.yacc"
    {chk4var=1;}
    break;

  case 497:
#line 3007 "fgl.yacc"
    {chk4var=0;}
    break;

  case 498:
#line 3007 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[-2].ptr,"aclfgl_date(1);");
}
    break;

  case 499:
#line 3010 "fgl.yacc"
    {chk4var=1;}
    break;

  case 500:
#line 3010 "fgl.yacc"
    {chk4var=0;}
    break;

  case 501:
#line 3010 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[-2].ptr,"aclfgl_month(1);");
	/* consumes and replaces a fgl_expr_c - so we don't need to dec or inc_counter */
}
    break;

  case 502:
#line 3014 "fgl.yacc"
    {chk4var=1;}
    break;

  case 503:
#line 3014 "fgl.yacc"
    {chk4var=0;}
    break;

  case 504:
#line 3014 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[-2].ptr,"aclfgl_day(1);");
	/* consumes and replaces a fgl_expr_c - so we don't need to dec or inc_counter */
}
    break;

  case 505:
#line 3018 "fgl.yacc"
    {chk4var=1;}
    break;

  case 506:
#line 3018 "fgl.yacc"
    {chk4var=0;}
    break;

  case 507:
#line 3018 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[-2].ptr,"aclfgl_year(1);");
	/* consumes and replaces a fgl_expr_c - so we don't need to dec or inc_counter */
}
    break;

  case 508:
#line 3022 "fgl.yacc"
    {
	char buff[256];
	sprintf(buff,"acli_interval(%s,%s);",yyvsp[-2].str,yyvsp[0].str);
	yyval.ptr=A4GL_new_expr(buff);
	inc_counter();
}
    break;

  case 509:
#line 3028 "fgl.yacc"
    {
	char buff[256];
	sprintf(buff,"acli_datetime(%s,%s);",yyvsp[-2].str,yyvsp[0].str);
	yyval.ptr=A4GL_new_expr(buff);
	inc_counter();
}
    break;

  case 510:
#line 3034 "fgl.yacc"
    {
	char buff[256];
	sprintf(buff,"acli_datetime(\"%s\",%s);",yyvsp[-2].str,yyvsp[0].str);
	yyval.ptr=A4GL_new_expr(buff);
	inc_counter();
}
    break;

  case 511:
#line 3040 "fgl.yacc"
    {
	char buff[256];
	sprintf(buff,"acli_datetime(\"%s:%s\",%s);",yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str);
	yyval.ptr=A4GL_new_expr(buff);
	inc_counter();
}
    break;

  case 512:
#line 3046 "fgl.yacc"
    {
	char buff[256];
	sprintf(buff,"acli_datetime(\"%s-%s\",%s);",yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str);
	yyval.ptr=A4GL_new_expr(buff);
	inc_counter();
}
    break;

  case 513:
#line 3052 "fgl.yacc"
    {
	char buff[256];
	sprintf(buff,"acli_datetime(\"%s-%s-%s\",%s);",yyvsp[-6].str,yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str);
	yyval.ptr=A4GL_new_expr(buff);
	inc_counter();
}
    break;

  case 514:
#line 3061 "fgl.yacc"
    {
	char buff[256];
	sprintf(buff,"A4GL_isdynarr_allocated(&%s);",yyvsp[-1].str);
        yyval.ptr=A4GL_new_expr(buff);
        inc_counter();
}
    break;

  case 515:
#line 3067 "fgl.yacc"
    { 
        char buff[256];
        sprintf(buff,"A4GL_dynarr_extent(&%s,%d);",yyvsp[-3].str,atoi(yyvsp[-1].str));
        yyval.ptr=A4GL_new_expr(buff);
        inc_counter();
}
    break;

  case 516:
#line 3077 "fgl.yacc"
    {strcpy(yyval.str,"-1");}
    break;

  case 517:
#line 3078 "fgl.yacc"
    {sprintf(yyval.str,"%d",atoi(yyvsp[-2].str)*16+atoi(yyvsp[0].str));}
    break;

  case 520:
#line 3086 "fgl.yacc"
    {
	if (!isin_command("INPUT")&&!isin_command("CONSTRUCT")) { 
   		a4gl_yyerror("get_fldbuf can only be used in an input or construct");
   		YYERROR;
	}
sprintf(yyval.str,"{int _retvars;\n_retvars=A4GL_fgl_getfldbuf(_sio_%d,_inp_io_type,%s,0,0);\nif (_retvars != 1 ) {A4GLSQL_set_status(-3001,0);A4GL_chk_err(%d,\"%s\");}\n}\n",get_sio_id("ALL"),
	field_name_list_as_char(yyvsp[-1].field_list), lastlineno,infilename); 
	yyval.ptr=A4GL_new_expr(yyval.str);	
	inc_counter();

}
    break;

  case 521:
#line 3097 "fgl.yacc"
    {sprintf(yyval.str,"A4GL_push_int(A4GL_fgl_fieldnametoid(\"\",%s));",field_name_as_char(yyvsp[-1].field_entry)); yyval.ptr=A4GL_new_expr(yyval.str); }
    break;

  case 522:
#line 3098 "fgl.yacc"
    {
sprintf(yyval.str,"A4GL_push_int(A4GL_fgl_fieldnametoid(\"\",%s));",field_name_as_char(yyvsp[-1].field_entry)); yyval.ptr=A4GL_new_expr(yyval.str); 
addmap("Get Field",field_name_as_char(yyvsp[-1].field_entry),curr_func,yylineno,infilename);
	inc_counter();
}
    break;

  case 523:
#line 3104 "fgl.yacc"
    {
/* Informix allows this outside of a input/construct... */
	if (isin_command("INPUT")&&!isin_command("CONSTRUCT")) { 
		sprintf(yyval.str,"A4GL_push_int(A4GL_fgl_infield(_sio_%d,_inp_io_type,%s,0,0));",get_sio_id("ALL"),field_name_list_as_char(yyvsp[-1].field_list)); 
	} else {
		sprintf(yyval.str,"A4GL_push_int(A4GL_fgl_infield(0,0,%s,0,0));",field_name_list_as_char(yyvsp[-1].field_list)); 
	}
	yyval.ptr=A4GL_new_expr(yyval.str);
	inc_counter();
}
    break;

  case 524:
#line 3115 "fgl.yacc"
    { 
	if (!isin_command("INPUT")&&!isin_command("CONSTRUCT")) { 
   		a4gl_yyerror("field_touched can only be used in an input or construct");
   		YYERROR;
	}
	sprintf(yyval.str,"A4GL_push_int(A4GL_fgl_fieldtouched(_sio_%d,_inp_io_type,%s,0,0));",get_sio_id("ALL"),field_name_list_as_char(yyvsp[-1].field_list)); 
	yyval.ptr=A4GL_new_expr(yyval.str);
	inc_counter();
}
    break;

  case 525:
#line 3125 "fgl.yacc"
    { 
	if (!isin_command("INPUT")&&!isin_command("CONSTRUCT")) { 
   		a4gl_yyerror("field_touched can only be used in an input or construct");
   		YYERROR;
	}
	sprintf(yyval.str,"A4GL_push_int(!A4GL_fgl_fieldtouched(_sio_%d,_inp_io_type,%s,0,0));",get_sio_id("ALL"),field_name_list_as_char(yyvsp[-1].field_list)); 
	yyval.ptr=A4GL_new_expr(yyval.str);
	inc_counter();
}
    break;

  case 528:
#line 3138 "fgl.yacc"
    {
		inc_counter();
               sprintf(yyval.str,"A4GL_push_current(%s);",yyvsp[0].str);
		yyval.ptr=A4GL_new_expr(yyval.str);
          	}
    break;

  case 529:
#line 3143 "fgl.yacc"
    { inc_counter(); strcpy(yyval.str,"A4GL_push_today();");
		yyval.ptr=A4GL_new_expr(yyval.str);
		}
    break;

  case 530:
#line 3150 "fgl.yacc"
    { 
	yyval.ptr=A4GL_append_expr(yyvsp[-1].ptr,"A4GL_upshift_stk();");
}
    break;

  case 531:
#line 3154 "fgl.yacc"
    { 
	yyval.ptr=A4GL_append_expr(yyvsp[-1].ptr,"A4GL_downshift_stk();");
}
    break;

  case 532:
#line 3157 "fgl.yacc"
    { 
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_push_ascii();");
}
    break;

  case 533:
#line 3160 "fgl.yacc"
    { 
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"aclfgli_extend();"); }
    break;

  case 534:
#line 3166 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[-1].ptr,"A4GL_push_double(-1);A4GL_pushop(OP_MULT);");
}
    break;

  case 535:
#line 3169 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[-1].ptr,"A4GL_push_double(-28.3465);A4GL_pushop(OP_MULT);");
}
    break;

  case 536:
#line 3172 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[-1].ptr,"A4GL_push_double(-72.0);A4GL_pushop(OP_MULT);");
}
    break;

  case 537:
#line 3189 "fgl.yacc"
    {
	strcpy(yyval.str,yyvsp[0].str);
}
    break;

  case 538:
#line 3192 "fgl.yacc"
    {
	strcpy(yyval.str,yyvsp[0].str);
}
    break;

  case 539:
#line 3198 "fgl.yacc"
    {sprintf(yyval.str,"-%s",yyvsp[0].str);}
    break;

  case 540:
#line 3199 "fgl.yacc"
    {sprintf(yyval.str,"\"%s\"",yyvsp[0].str);}
    break;

  case 541:
#line 3200 "fgl.yacc"
    {sprintf(yyval.str,"\"%s\"",yyvsp[0].str);}
    break;

  case 543:
#line 3205 "fgl.yacc"
    {sprintf(yyval.str,"%s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 544:
#line 3206 "fgl.yacc"
    {sprintf(yyval.str,"%s %s:%s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 545:
#line 3207 "fgl.yacc"
    {sprintf(yyval.str,"%s %s:%s:%s",yyvsp[-5].str,yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 546:
#line 3208 "fgl.yacc"
    {sprintf(yyval.str,"%s %s:%s:%s",yyvsp[-5].str,yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 547:
#line 3210 "fgl.yacc"
    {sprintf(yyval.str,"%s:%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 548:
#line 3211 "fgl.yacc"
    {sprintf(yyval.str,"%s:%s:%s",yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 549:
#line 3212 "fgl.yacc"
    {sprintf(yyval.str,"%s:%s:%s",yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 550:
#line 3214 "fgl.yacc"
    {sprintf(yyval.str,"%s:%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 551:
#line 3215 "fgl.yacc"
    {sprintf(yyval.str,"%s",yyvsp[0].str);}
    break;

  case 553:
#line 3221 "fgl.yacc"
    {sprintf(yyval.str,"%s-%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 554:
#line 3225 "fgl.yacc"
    {
                        yyval.field_list=new_field_list();
                        yyval.field_list=append_field_to_list(yyval.field_list,yyvsp[0].field_entry);
		}
    break;

  case 555:
#line 3229 "fgl.yacc"
    {
                        yyval.field_list=append_field_to_list(yyvsp[-2].field_list,yyvsp[0].field_entry);
	}
    break;

  case 556:
#line 3234 "fgl.yacc"
    {
                        yyval.field_list=new_field_list();
                        yyval.field_list=append_field_to_list(yyval.field_list,yyvsp[0].field_entry);
		}
    break;

  case 557:
#line 3238 "fgl.yacc"
    {
                        yyval.field_list=append_field_to_list(yyvsp[-2].field_list,yyvsp[0].field_entry);
	}
    break;

  case 558:
#line 3253 "fgl.yacc"
    {
push_blockcommand("FOREACH");
}
    break;

  case 559:
#line 3257 "fgl.yacc"
    {
print_foreach_start();
A4GL_lex_printcomment(" /* foreach */\n");
}
    break;

  case 560:
#line 3263 "fgl.yacc"
    {
print_foreach_next(yyvsp[-3].str,yyvsp[-1].str,yyvsp[0].str);
}
    break;

  case 561:
#line 3267 "fgl.yacc"
    {
add_continue_blockcommand ("FOREACH");
print_foreach_end(yyvsp[-6].str);
pop_blockcommand("FOREACH"); 
print_foreach_close(yyvsp[-6].str);
}
    break;

  case 562:
#line 3276 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 563:
#line 3277 "fgl.yacc"
    {
		strcpy(yyval.str,yyvsp[0].str);
	}
    break;

  case 564:
#line 3289 "fgl.yacc"
    {
		sprintf(curr_func,"%s",yyvsp[0].str); 
		print_formhandler(yyvsp[0].str);
		start_state("formhandler",1);
	push_blockcommand("FORMHANDLER");
        }
    break;

  case 565:
#line 3295 "fgl.yacc"
    {
		print_variables();
		print_getwin();
	}
    break;

  case 566:
#line 3303 "fgl.yacc"
    {
pop_blockcommand("FORMHANDLER");
print_end_formhandler(); 
start_state("formhandler",0);}
    break;

  case 573:
#line 3320 "fgl.yacc"
    {
		print_event('B');
        }
    break;

  case 574:
#line 3322 "fgl.yacc"
    {
		print_event_2();
        }
    break;

  case 575:
#line 3325 "fgl.yacc"
    {
		print_event('b');
        }
    break;

  case 576:
#line 3327 "fgl.yacc"
    {
		print_event_2();
        }
    break;

  case 581:
#line 3341 "fgl.yacc"
    {
		print_event('A');
        }
    break;

  case 582:
#line 3343 "fgl.yacc"
    {
		print_event_2();
        }
    break;

  case 583:
#line 3346 "fgl.yacc"
    {
		print_event('a');
        }
    break;

  case 584:
#line 3348 "fgl.yacc"
    {
		print_event_2();
        }
    break;

  case 597:
#line 3379 "fgl.yacc"
    { 
			print_gtk_field('B',0);
		}
    break;

  case 598:
#line 3381 "fgl.yacc"
    {
			print_gtk_field_2();
		}
    break;

  case 599:
#line 3384 "fgl.yacc"
    { 
			print_gtk_field('A',0);
		}
    break;

  case 600:
#line 3386 "fgl.yacc"
    {
			print_gtk_field_2();
		}
    break;

  case 601:
#line 3389 "fgl.yacc"
    {
			print_gtk_field('b',yyvsp[0].str);
		}
    break;

  case 602:
#line 3391 "fgl.yacc"
    { 
			print_gtk_field_2();
		}
    break;

  case 603:
#line 3394 "fgl.yacc"
    {
			print_gtk_field('a',yyvsp[0].str);
		}
    break;

  case 604:
#line 3396 "fgl.yacc"
    { 
			print_gtk_field_2();
		}
    break;

  case 605:
#line 3399 "fgl.yacc"
    { 
			print_gtk_field('o',yyvsp[0].str);
		}
    break;

  case 606:
#line 3401 "fgl.yacc"
    { 
			print_gtk_field_2();
		}
    break;

  case 607:
#line 3415 "fgl.yacc"
    {
print_for_start(yyvsp[-5].str);
push_blockcommand("FOR");
}
    break;

  case 608:
#line 3419 "fgl.yacc"
    {A4GL_debug("For_cmds\n");}
    break;

  case 609:
#line 3420 "fgl.yacc"
    {

pop_blockcommand("FOR");
print_for_end();
A4GL_lex_printcomment(" /*END FOR*/\n");}
    break;

  case 610:
#line 3427 "fgl.yacc"
    {
		print_for_default_step();
	}
    break;

  case 612:
#line 3445 "fgl.yacc"
    {
		//print_niy("Free Cursor");
		A4GL_lex_printcomment(" /* FIXME: Not implemented: Free Cursor */\n");;

		strcpy(yyval.str,"");
		}
    break;

  case 613:
#line 3461 "fgl.yacc"
    {sprintf(yyval.str,"%d",-1-(atoi(yyvsp[0].str)));}
    break;

  case 614:
#line 3462 "fgl.yacc"
    {strcpy(yyval.str,"-1");}
    break;

  case 615:
#line 3463 "fgl.yacc"
    {sprintf (yyval.str,"%d",atoi(yyvsp[0].str)+1);}
    break;

  case 616:
#line 3464 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 617:
#line 3465 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 618:
#line 3466 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 619:
#line 3467 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 623:
#line 3475 "fgl.yacc"
    {sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str); }
    break;

  case 625:
#line 3481 "fgl.yacc"
    { 
			yyval.field_entry=new_field_entry(yyvsp[0].str,"1",1);
		}
    break;

  case 626:
#line 3484 "fgl.yacc"
    { 
				char buff[256];
				sprintf(buff,"int_to_id(%s)",yyvsp[-1].str);
				yyval.field_entry=new_field_entry(buff,"1",0); 
		}
    break;

  case 627:
#line 3489 "fgl.yacc"
    { 
				char buff[256];
				sprintf(buff,"int_to_id(%s.%s)",yyvsp[-5].str,yyvsp[-1].str); 
				yyval.field_entry=new_field_entry(buff,"1",0); 
		}
    break;

  case 628:
#line 3494 "fgl.yacc"
    {
				yyval.field_entry=new_field_entry(yyvsp[-3].str,yyvsp[-1].str,1);
		}
    break;

  case 629:
#line 3497 "fgl.yacc"
    {
				char buff[256];
				sprintf(buff,"%s.*",yyvsp[-2].str);
				yyval.field_entry=new_field_entry(buff,"1",1);
		}
    break;

  case 630:
#line 3502 "fgl.yacc"
    {
				char buff[256];
				sprintf(buff,"%s.*",yyvsp[-5].str);
				yyval.field_entry=new_field_entry(buff,yyvsp[-3].str,1);
		}
    break;

  case 631:
#line 3507 "fgl.yacc"
    {
				char buff[256];
				sprintf(buff,"%s.%s",yyvsp[-2].str,yyvsp[0].str);
				yyval.field_entry=new_field_entry(buff,"1",1);
		}
    break;

  case 632:
#line 3512 "fgl.yacc"
    {
				char buff[256];
				sprintf(buff,"%s.%s",yyvsp[-5].str,yyvsp[0].str);
				yyval.field_entry=new_field_entry(buff,yyvsp[-3].str,1);
		}
    break;

  case 633:
#line 3519 "fgl.yacc"
    {yyval.field_entry=yyvsp[0].field_entry;}
    break;

  case 634:
#line 3520 "fgl.yacc"
    { 
                 char buff[256];
                 sprintf(buff,"%s",yyvsp[0].str);
                 yyval.field_entry=new_field_entry(buff,"1",0);
	}
    break;

  case 635:
#line 3527 "fgl.yacc"
    {
				print_pushchar(yyvsp[0].str);
				addmap("Cursor",last_var,curr_func,yylineno,infilename);
			}
    break;

  case 636:
#line 3534 "fgl.yacc"
    {sprintf(yyval.str,"%s",yyvsp[0].str);}
    break;

  case 637:
#line 3536 "fgl.yacc"
    {sprintf(yyval.str,"%s",yyvsp[0].str);
addmap("Window",last_var,curr_func,yylineno,infilename);
}
    break;

  case 638:
#line 3542 "fgl.yacc"
    {sprintf(yyval.str,"%s",yyvsp[0].str);
addmap("Open Window",last_var,curr_func,yylineno,infilename);
}
    break;

  case 639:
#line 3547 "fgl.yacc"
    {sprintf(yyval.str,"%s",yyvsp[0].str);
addmap("Form",last_var,curr_func,yylineno,infilename);
}
    break;

  case 640:
#line 3552 "fgl.yacc"
    {sprintf(yyval.str,"%s",yyvsp[0].str);
addmap("Open Form",last_var,curr_func,yylineno,infilename);
}
    break;

  case 641:
#line 3557 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 642:
#line 3557 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 643:
#line 3560 "fgl.yacc"
    { 
			strcpy(yyval.str,downshift(yyvsp[0].str)) ;
}
    break;

  case 644:
#line 3566 "fgl.yacc"
    {
			sprintf(yyval.str,"%s",downshift(yyvsp[0].str)) ;
			}
    break;

  case 645:
#line 3571 "fgl.yacc"
    {
	strcpy(yyval.str,do_clobbering(clobber,downshift(yyvsp[0].str))) ;
	strcpy(last_var,downshift(yyvsp[0].str));
}
    break;

  case 646:
#line 3575 "fgl.yacc"
    {
		sprintf(yyval.str,"aclfgli_str_to_id(%s)",yyvsp[-1].str);
		sprintf(last_var,"->%s",yyvsp[-1].str);
	}
    break;

  case 649:
#line 3583 "fgl.yacc"
    {
					yyval.field_entry=new_field_entry(yyvsp[0].str,"1",1); 
				}
    break;

  case 650:
#line 3586 "fgl.yacc"
    {
					yyval.field_entry=new_field_entry(yyvsp[-3].str,yyvsp[-1].str,1); 
				}
    break;

  case 651:
#line 3589 "fgl.yacc"
    {
					char buff[256];
					sprintf(buff,"%s.*",yyvsp[-2].str);
					yyval.field_entry=new_field_entry(buff,"1",1); 
				}
    break;

  case 652:
#line 3594 "fgl.yacc"
    {
					char buff[256];
					sprintf(buff,"%s.*",yyvsp[-5].str);
					yyval.field_entry=new_field_entry(buff,yyvsp[-3].str,1); 
				}
    break;

  case 653:
#line 3599 "fgl.yacc"
    {
					char buff[256];
					sprintf(buff,"%s.%s",yyvsp[-2].str,yyvsp[0].str);
					yyval.field_entry=new_field_entry(buff,"1",1); 
				}
    break;

  case 654:
#line 3604 "fgl.yacc"
    {
					char buff[256];
					sprintf(buff,"%s.%s",yyvsp[-5].str,yyvsp[0].str);
					yyval.field_entry=new_field_entry(buff,yyvsp[-3].str,1); 
				}
    break;

  case 655:
#line 3611 "fgl.yacc"
    {
A4GL_debug("Scanvar=%d",scan_variable(yyvsp[0].str)&15);
if ((scan_variable(yyvsp[0].str)&15)!=0) {
a4gl_yyerror("Only a character variable can be used for this");
YYERROR;
}
}
    break;

  case 657:
#line 3620 "fgl.yacc"
    {
		sprintf(yyval.str,".%s",yyvsp[0].str);
}
    break;

  case 658:
#line 3682 "fgl.yacc"
    {
	char buff[256];
	strcpy(buff,yyvsp[0].str);
	A4GL_convlower(buff);
	print_goto(buff);
}
    break;

  case 660:
#line 3691 "fgl.yacc"
    {sprintf(yyval.str,"%s",yyvsp[0].str);}
    break;

  case 661:
#line 3700 "fgl.yacc"
    {
print_gui_do_menuitems(yyvsp[0].str,'C');
}
    break;

  case 663:
#line 3707 "fgl.yacc"
    {sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 664:
#line 3710 "fgl.yacc"
    {
        sprintf(yyval.str,"\"%s\"",yyvsp[0].str);
}
    break;

  case 665:
#line 3716 "fgl.yacc"
    {
print_gui_do_menuitems(yyvsp[0].str,'U');
}
    break;

  case 666:
#line 3722 "fgl.yacc"
    {
print_gui_do_menuitems(yyvsp[0].str,'D');
}
    break;

  case 667:
#line 3726 "fgl.yacc"
    {
print_gui_do_fields(field_name_list_as_char(yyvsp[0].field_list),'D');
}
    break;

  case 668:
#line 3730 "fgl.yacc"
    {
print_gui_do_form(yyvsp[-2].str,field_name_list_as_char(yyvsp[0].field_list),'D');
}
    break;

  case 669:
#line 3736 "fgl.yacc"
    {
print_gui_do_menuitems(yyvsp[0].str,'E');
}
    break;

  case 670:
#line 3740 "fgl.yacc"
    {
print_gui_do_fields(field_name_list_as_char(yyvsp[0].field_list),'E');
}
    break;

  case 671:
#line 3744 "fgl.yacc"
    {
print_gui_do_form(field_name_list_as_char(yyvsp[-2].field_list),yyvsp[0].str,'E');
}
    break;

  case 672:
#line 3749 "fgl.yacc"
    {start_state("messagebox",1);}
    break;

  case 673:
#line 3754 "fgl.yacc"
    {start_state("messagebox",0);}
    break;

  case 692:
#line 3795 "fgl.yacc"
    {
		if_print_stack_cnt++;
		if_print_stack[if_print_stack_cnt][0]=0;
		if_print_stack[if_print_stack_cnt][1]=0;
		if_print_section[if_print_stack_cnt]=0;
		print_if_start();
	}
    break;

  case 693:
#line 3802 "fgl.yacc"
    {
		if_print_section[if_print_stack_cnt]=1;
	}
    break;

  case 694:
#line 3804 "fgl.yacc"
    {
		char wt;
		print_if_end();
	        wt=get_curr_report_stack_whytype_1();
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

  case 696:
#line 3823 "fgl.yacc"
    {
		print_if_else();
	}
    break;

  case 698:
#line 3826 "fgl.yacc"
    {
		print_if_else();
		}
    break;

  case 699:
#line 3828 "fgl.yacc"
    {

		print_if_start();
	}
    break;

  case 700:
#line 3831 "fgl.yacc"
    {
		print_if_end();
	}
    break;

  case 701:
#line 3835 "fgl.yacc"
    {
		print_import(yyvsp[-3].str,atoi(yyvsp[-1].str));
	}
    break;

  case 702:
#line 3838 "fgl.yacc"
    {
		print_import_legacy(yyvsp[0].str);
	}
    break;

  case 703:
#line 3844 "fgl.yacc"
    { add_ex_dtype(yyvsp[0].str); }
    break;

  case 704:
#line 3855 "fgl.yacc"
    {A4GL_debug("init to\n");}
    break;

  case 705:
#line 3856 "fgl.yacc"
    {
	print_init();
 }
    break;

  case 706:
#line 3859 "fgl.yacc"
    {
	print_init_table(yyvsp[0].str);
}
    break;

  case 708:
#line 3865 "fgl.yacc"
    {sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 709:
#line 3869 "fgl.yacc"
    {setrecord(yyval.str,yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 710:
#line 3870 "fgl.yacc"
    {setrecord(yyval.str,yyvsp[-2].str,0);}
    break;

  case 711:
#line 3874 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 715:
#line 3889 "fgl.yacc"
    {
sprintf(yyval.str,"0");
}
    break;

  case 716:
#line 3891 "fgl.yacc"
    {
sprintf(yyval.str,"1");
}
    break;

  case 719:
#line 3900 "fgl.yacc"
    {
		A4GL_add_event(-97,field_name_list_as_or_char(yyvsp[0].field_list));
		print_befaft_field_1(field_name_list_as_or_char(yyvsp[0].field_list));
}
    break;

  case 720:
#line 3903 "fgl.yacc"
    {
	print_befaft_field_2();
}
    break;

  case 721:
#line 3907 "fgl.yacc"
    {
		A4GL_add_event(-98,field_name_list_as_or_char(yyvsp[0].field_list));
		print_befaft_field_1(field_name_list_as_or_char(yyvsp[0].field_list));
}
    break;

  case 722:
#line 3910 "fgl.yacc"
    {
	print_befaft_field_2();
}
    break;

  case 723:
#line 3913 "fgl.yacc"
    {
		A4GL_add_event(-11,"");
		print_befaft_field_1("AFT_ROW");
}
    break;

  case 724:
#line 3916 "fgl.yacc"
    {
	print_befaft_field_2();
}
    break;

  case 725:
#line 3919 "fgl.yacc"
    {
		A4GL_add_event(-10,"");
		A4GL_lex_printcomment("/* before row */ \n");
		print_befaft_field_1("BEF_ROW");
}
    break;

  case 726:
#line 3923 "fgl.yacc"
    {
	print_befaft_field_2();
		}
    break;

  case 727:
#line 3926 "fgl.yacc"
    {
	A4GL_add_onkey_key(yyvsp[0].str);
	print_onkey_1(yyvsp[0].str);
}
    break;

  case 728:
#line 3929 "fgl.yacc"
    {
	print_onkey_2();
}
    break;

  case 729:
#line 3932 "fgl.yacc"
    {
		A4GL_add_event(-95,"");
		print_befaft_field_1("AFTER_INP");
}
    break;

  case 730:
#line 3935 "fgl.yacc"
    {
	print_befaft_field_2();
}
    break;

  case 731:
#line 3938 "fgl.yacc"
    {
		A4GL_add_event(-99,"");
		print_befaft_field_1("BEFORE_INP");
}
    break;

  case 732:
#line 3941 "fgl.yacc"
    {
	print_befaft_field_2();
}
    break;

  case 733:
#line 3944 "fgl.yacc"
    {
		A4GL_add_event(-12,"");
		print_befaft_field_1("DO_BEFORE_DELETE");
	}
    break;

  case 734:
#line 3947 "fgl.yacc"
    { print_befaft_field_2(); }
    break;

  case 735:
#line 3948 "fgl.yacc"
    { A4GL_add_event(-14,""); print_befaft_field_1("DO_BEFORE_INSERT"); }
    break;

  case 736:
#line 3948 "fgl.yacc"
    { print_befaft_field_2(); }
    break;

  case 737:
#line 3949 "fgl.yacc"
    { A4GL_add_event(-17,""); print_befaft_field_1("DO_BEFORE_INSERT_DELETE"); }
    break;

  case 738:
#line 3949 "fgl.yacc"
    { print_befaft_field_2(); }
    break;

  case 739:
#line 3950 "fgl.yacc"
    { A4GL_add_event(-18,""); print_befaft_field_1("DO_AFTER_INSERT_DELETE"); }
    break;

  case 740:
#line 3950 "fgl.yacc"
    { print_befaft_field_2(); }
    break;

  case 741:
#line 3951 "fgl.yacc"
    {
		A4GL_add_event(-13,"");
		print_befaft_field_1("DO_AFTER_DELETE");
	}
    break;

  case 742:
#line 3954 "fgl.yacc"
    { print_befaft_field_2(); }
    break;

  case 743:
#line 3955 "fgl.yacc"
    {
		A4GL_add_event(-15,"");
		print_befaft_field_1("DO_AFTER_INSERT");
	}
    break;

  case 744:
#line 3958 "fgl.yacc"
    { print_befaft_field_2(); }
    break;

  case 745:
#line 3966 "fgl.yacc"
    {
                        yyval.field_list=new_field_list();
                        yyval.field_list=append_field_to_list(yyval.field_list,yyvsp[0].field_entry);
        }
    break;

  case 746:
#line 3970 "fgl.yacc"
    {
                        yyval.field_list=append_field_to_list(yyvsp[-2].field_list,yyvsp[0].field_entry);
        }
    break;

  case 747:
#line 3976 "fgl.yacc"
    {
                        yyval.field_list=new_field_list();
                        yyval.field_list=append_field_to_list(yyval.field_list,yyvsp[0].field_entry);
        }
    break;

  case 748:
#line 3980 "fgl.yacc"
    {
                        yyval.field_list=append_field_to_list(yyvsp[-2].field_list,yyvsp[0].field_entry);
        }
    break;

  case 749:
#line 3985 "fgl.yacc"
    {
print_next_field(yyvsp[0].str);
}
    break;

  case 750:
#line 3990 "fgl.yacc"
    {
print_next_form_field(yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 751:
#line 3995 "fgl.yacc"
    {sprintf(yyval.str,"\"+\"");}
    break;

  case 752:
#line 3996 "fgl.yacc"
    {sprintf(yyval.str,"\"-\"");}
    break;

  case 753:
#line 3997 "fgl.yacc"
    {sprintf(yyval.str,field_name_as_char(yyvsp[0].field_entry));}
    break;

  case 754:
#line 4001 "fgl.yacc"
    {
print_input_1();
  A4GL_new_events();
}
    break;

  case 755:
#line 4005 "fgl.yacc"
    {
print_input_2(yyvsp[-2].str);
A4GL_drop_events();
}
    break;

  case 756:
#line 4014 "fgl.yacc"
    {
print_input(1,yyvsp[-2].str,yyvsp[-1].str,0,atoi(yyvsp[0].str));
strcpy(yyval.str,A4GL_get_formloop_str(0));
}
    break;

  case 757:
#line 4019 "fgl.yacc"
    {
print_input(0,yyvsp[-4].str,yyvsp[-1].str,field_name_list_as_char(yyvsp[-2].field_list),atoi(yyvsp[0].str));
strcpy(yyval.str,A4GL_get_formloop_str(0));
}
    break;

  case 758:
#line 4023 "fgl.yacc"
    {
curr_input_array_attribs.maxcount=0;
curr_input_array_attribs.count=0;
curr_input_array_attribs.allow_insert=1;
curr_input_array_attribs.allow_delete=1;
curr_input_array_attribs.curr_row_display=0;
inp_flags=0;}
    break;

  case 759:
#line 4030 "fgl.yacc"
    {
strcpy(yyval.str,print_input_array(fgl_add_scope(yyvsp[-8].str,0),yyvsp[-2].str,yyvsp[-7].str,yyvsp[-5].str,yyvsp[0].str,&curr_input_array_attribs));
}
    break;

  case 760:
#line 4039 "fgl.yacc"
    {
		print_scroll(field_name_list_as_char(yyvsp[-1].field_list),yyvsp[0].str);
	}
    break;

  case 761:
#line 4045 "fgl.yacc"
    {sprintf(yyval.str,"%s",yyvsp[0].str);}
    break;

  case 762:
#line 4046 "fgl.yacc"
    {sprintf(yyval.str,"-%s",yyvsp[0].str);}
    break;

  case 763:
#line 4047 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 764:
#line 4048 "fgl.yacc"
    {strcpy(yyval.str,"-1");}
    break;

  case 765:
#line 4049 "fgl.yacc"
    {
  		int a;
  		a=scan_variable(yyvsp[0].str)&15;
  		if (a!=1&&a!=2) {
    		a4gl_yyerror("Only INTEGER/SMALLINT variables may be here");
    		YYERROR;
    		/* error processing */;
  		}
  		sprintf(yyval.str,"%s",fgl_add_scope(yyvsp[0].str,0));
	}
    break;

  case 766:
#line 4059 "fgl.yacc"
    {
  		int a;
  		a=scan_variable(yyvsp[0].str)&15;
  		if (a!=1&&a!=2) {
    		a4gl_yyerror("Only INTEGER/SMALLINT variables may be here");
    		YYERROR;
    		/* error processing */;
  		}
  		sprintf(yyval.str,"%s",fgl_add_scope(yyvsp[0].str,0));
	}
    break;

  case 767:
#line 4073 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 769:
#line 4076 "fgl.yacc"
    {
	strcpy(yyval.str,"");
}
    break;

  case 770:
#line 4083 "fgl.yacc"
    { curr_input_array_attribs.curr_row_display=strdup(yyvsp[0].str); }
    break;

  case 771:
#line 4084 "fgl.yacc"
    { curr_input_array_attribs.count=strdup(yyvsp[0].str); }
    break;

  case 772:
#line 4085 "fgl.yacc"
    { curr_input_array_attribs.count=strdup(yyvsp[0].str); }
    break;

  case 773:
#line 4086 "fgl.yacc"
    { curr_input_array_attribs.maxcount=strdup(yyvsp[0].str); }
    break;

  case 774:
#line 4087 "fgl.yacc"
    { curr_input_array_attribs.maxcount=strdup(yyvsp[0].str); }
    break;

  case 775:
#line 4088 "fgl.yacc"
    { curr_input_array_attribs.allow_insert=1; }
    break;

  case 776:
#line 4089 "fgl.yacc"
    { curr_input_array_attribs.allow_insert=0; }
    break;

  case 777:
#line 4090 "fgl.yacc"
    { curr_input_array_attribs.allow_delete=1; }
    break;

  case 778:
#line 4091 "fgl.yacc"
    { curr_input_array_attribs.allow_delete=0; }
    break;

  case 779:
#line 4096 "fgl.yacc"
    {iskey=1;}
    break;

  case 780:
#line 4096 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);iskey=0;}
    break;

  case 781:
#line 4098 "fgl.yacc"
    {strcpy(yyval.str,"->ANY");}
    break;

  case 782:
#line 4101 "fgl.yacc"
    {iskey=1;}
    break;

  case 783:
#line 4101 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);iskey=0;}
    break;

  case 784:
#line 4103 "fgl.yacc"
    {sprintf(yyval.str,"A4GL_key_val(\"%s\")",yyvsp[0].str);iskey=0;}
    break;

  case 785:
#line 4107 "fgl.yacc"
    {sprintf(yyval.str,"A4GL_key_val(\"%s\")",yyvsp[0].str);iskey=0;}
    break;

  case 786:
#line 4110 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 787:
#line 4111 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[-1].str);}
    break;

  case 789:
#line 4114 "fgl.yacc"
    {
	sprintf(yyval.str,"%s||%s",yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 795:
#line 4126 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 796:
#line 4127 "fgl.yacc"
    {strcpy(yyval.str,"escape");}
    break;

  case 797:
#line 4128 "fgl.yacc"
    {strcpy(yyval.str,"up");}
    break;

  case 798:
#line 4129 "fgl.yacc"
    {strcpy(yyval.str,"help");}
    break;

  case 799:
#line 4130 "fgl.yacc"
    {strcpy(yyval.str,"down");}
    break;

  case 800:
#line 4131 "fgl.yacc"
    {strcpy(yyval.str,"return");}
    break;

  case 801:
#line 4132 "fgl.yacc"
    {strcpy(yyval.str,"delete");}
    break;

  case 802:
#line 4133 "fgl.yacc"
    {strcpy(yyval.str,"insert");}
    break;

  case 803:
#line 4134 "fgl.yacc"
    {strcpy(yyval.str,"tab");}
    break;

  case 804:
#line 4135 "fgl.yacc"
    {strcpy(yyval.str,"left");}
    break;

  case 805:
#line 4136 "fgl.yacc"
    {strcpy(yyval.str,"right");}
    break;

  case 806:
#line 4137 "fgl.yacc"
    {strcpy(yyval.str,"nextpage");}
    break;

  case 807:
#line 4138 "fgl.yacc"
    {strcpy(yyval.str,"prevpage");}
    break;

  case 808:
#line 4139 "fgl.yacc"
    { rm_quotes(yyvsp[0].str); strcpy(yyval.str,yyvsp[0].str); }
    break;

  case 809:
#line 4143 "fgl.yacc"
    {
char buff[256];
A4GL_debug("Label : %s\n",get_idents(0));
strcpy(buff,get_idents(0));
A4GL_convlower(buff);
print_label(buff);
}
    break;

  case 810:
#line 4161 "fgl.yacc"
    {chk4var=1;}
    break;

  case 811:
#line 4161 "fgl.yacc"
    {chk4var=0;
expand_obind();
A4GL_lex_printcomment("/*let3*/\n");}
    break;

  case 812:
#line 4164 "fgl.yacc"
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

  case 813:
#line 4188 "fgl.yacc"
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

  case 815:
#line 4206 "fgl.yacc"
    {
		if (!print_linked_cmd('S',yyvsp[0].str)) a4gl_yyerror("Not a linked variable");
	}
    break;

  case 816:
#line 4212 "fgl.yacc"
    {
		 if (!print_linked_cmd('D',yyvsp[0].str)) a4gl_yyerror("Not a linked variable");
	}
    break;

  case 817:
#line 4218 "fgl.yacc"
    {
		 if (!print_linked_cmd('U',yyvsp[0].str)) a4gl_yyerror("Not a linked variable");
}
    break;

  case 818:
#line 4224 "fgl.yacc"
    {
int vtype;
int a;
for (a=0;a<get_bind_cnt('o');a++) {
	vtype=scan_variable(get_bind_varname('o',a));
	if (vtype!=11&&vtype!=12) {
		a4gl_yyerror("Only Byte & Text may be located...");
		YYERROR;
	}
	print_locate('M',get_bind_varname('o',a),"0");
}
}
    break;

  case 819:
#line 4236 "fgl.yacc"
    {
int vtype;
int a;
for (a=0;a<get_bind_cnt('o');a++) {
	vtype=scan_variable(get_bind_varname('o',a));
	if (vtype!=11&&vtype!=12) {
		a4gl_yyerror("Only Byte & Text may be located...");
		YYERROR;
	}
	print_locate('F',get_bind_varname('o',a),yyvsp[0].str);
}
}
    break;

  case 820:
#line 4261 "fgl.yacc"
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

  case 823:
#line 4277 "fgl.yacc"
    {
	}
    break;

  case 832:
#line 4302 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 836:
#line 4310 "fgl.yacc"
    {
		print_at_termination(yyvsp[0].str);
	}
    break;

  case 851:
#line 4336 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 852:
#line 4337 "fgl.yacc"
    {
strcpy(yyval.str,"static ");
}
    break;

  case 853:
#line 4345 "fgl.yacc"
    {
  clr_variable(); lastlineno=yylineno;
  clr_function_constants (); 
}
    break;

  case 854:
#line 4350 "fgl.yacc"
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

  case 855:
#line 4366 "fgl.yacc"
    {
  A4GL_lex_printcomment("/* new function %s parameters*/\n",yyvsp[-1].str);
  push_blockcommand("FUNC");
  A4GL_lex_printcomment("/* define section */\n");
}
    break;

  case 856:
#line 4372 "fgl.yacc"
    {
  int c;
  A4GL_lex_printcomment("/*end of define section */\n");
	print_variables();
  c=print_param('f');
  printPushFunction();
  print_func_args(c);
}
    break;

  case 858:
#line 4387 "fgl.yacc"
    {
    printPopFunction();
    print_func_defret0();
    pop_blockcommand("FUNC");
    print_func_end();
    clr_function_constants ();
    A4GL_lex_printcomment("/*end function*/\n");
  }
    break;

  case 859:
#line 4400 "fgl.yacc"
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

  case 860:
#line 4410 "fgl.yacc"
    {
	print_variables();
    printDeclareFunctionStack("MAIN");
    print_fgllib_start(hdr_dbname);
    printInitFunctionStack();
    printPushFunction();
  }
    break;

  case 861:
#line 4417 "fgl.yacc"
    {
pop_blockcommand("MAIN");
print_main_end();
A4GL_lex_printcomment("/*end main */\n");}
    break;

  case 862:
#line 4424 "fgl.yacc"
    {
    printPopFunction();
    print_return(atoi(yyvsp[0].str));
  }
    break;

  case 863:
#line 4430 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 864:
#line 4430 "fgl.yacc"
    {
A4GL_lex_printcomment("/* Got expr list */");
sprintf(yyval.str,"%s",yyvsp[0].str);}
    break;

  case 865:
#line 4435 "fgl.yacc"
    {
					open_db(yyvsp[0].str);
					strcpy(hdr_dbname,yyvsp[0].str);
					lastlineno=yylineno;
					is_schema=0;
			}
    break;

  case 866:
#line 4441 "fgl.yacc"
    {
					open_db(yyvsp[0].str);
					strcpy(hdr_dbname,yyvsp[0].str);
					lastlineno=yylineno;
					is_schema=1;
			}
    break;

  case 867:
#line 4449 "fgl.yacc"
    {
}
    break;

  case 871:
#line 4461 "fgl.yacc"
    {
strcpy(curr_func,"[Globals]");
set_current_variable_scope('g');
A4GL_lex_printcomment("/* start of globals */\n");
}
    break;

  case 873:
#line 4469 "fgl.yacc"
    {
 A4GL_lex_printcomment("/* end of globals */");
	A4GL_debug("end of globals\n");
	lastlineno=yylineno;
	set_current_variable_scope('m');
}
    break;

  case 874:
#line 4475 "fgl.yacc"
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

  case 877:
#line 4491 "fgl.yacc"
    {
  addmap("Define Member Function",curr_func,"MODULE",yylineno,infilename);
}
    break;

  case 878:
#line 4495 "fgl.yacc"
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

  case 879:
#line 4508 "fgl.yacc"
    {
	print_variables();
  A4GL_lex_printcomment("/*end of define section */\n");
  print_param('f');
  printPushFunction();
  print_func_args(atoi(yyvsp[-3].str));
}
    break;

  case 881:
#line 4521 "fgl.yacc"
    {
                strcpy(menuhandler,yyvsp[0].str);
	sprintf(curr_func,"%s",yyvsp[0].str); 
	print_gtk_menuhandler_1(yyvsp[0].str);
                push_blockcommand("MENUH");
}
    break;

  case 882:
#line 4527 "fgl.yacc"
    {
		print_variables();
        }
    break;

  case 883:
#line 4531 "fgl.yacc"
    {
                        pop_blockcommand("MENUH");
			print_gtk_menuhandler_end();
                }
    break;

  case 886:
#line 4543 "fgl.yacc"
    {
		print_gtk_menuhandler_bsm();
                push_blockcommand("BSM");
        }
    break;

  case 887:
#line 4546 "fgl.yacc"
    {
                pop_blockcommand("BSM");
		print_gtk_menuhandler_bsm_end();
        }
    break;

  case 888:
#line 4550 "fgl.yacc"
    {
		print_gtk_menuhandler_on(yyvsp[0].str);
                push_blockcommand("ON");
        }
    break;

  case 889:
#line 4553 "fgl.yacc"
    {
                pop_blockcommand("ON");
		print_gtk_menuhandler_on_end();
}
    break;

  case 890:
#line 4565 "fgl.yacc"
    {
	start_state("menu",1);
   	menu_cnt=npush_menu();
   	menu_cmd_cnt[menu_cnt]=1;
   	push_blockcommand("MENU");
        menu_blk[menu_cnt]=get_blk_no();
	do_print_menu_1();
	}
    break;

  case 891:
#line 4573 "fgl.yacc"
    {
	start_state("menu",0);
	}
    break;

  case 892:
#line 4579 "fgl.yacc"
    {
   print_end_menu_1(menu_blk[menu_cnt]);
   add_continue_blockcommand ("MENU");
print_end_menu_2(menu_blk[menu_cnt]);
   pop_blockcommand("MENU");
   pop_menu();
}
    break;

  case 893:
#line 4590 "fgl.yacc"
    {
	 A4GL_lex_printcomment("/* Block%d_m2 (Before menu) */",menu_cnt);
		print_menu_block(menu_blk[menu_cnt],-2) ;
                  }
    break;

  case 894:
#line 4594 "fgl.yacc"
    {
		do_print_menu_block_end();
	}
    break;

  case 895:
#line 4601 "fgl.yacc"
    {
A4GL_debug("Menu=%d menu cnt=%d",menu_cnt,menu_cmd_cnt[menu_cnt]);
		push_command(menu_cnt,menu_cmd_cnt[menu_cnt],yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);
	 A4GL_lex_printcomment("/* Block%d_%d */",menu_cnt,menu_cmd_cnt[menu_cnt]-1);
		print_menu_block(menu_blk[menu_cnt],menu_cmd_cnt[menu_cnt]-1);
		menu_cmd_cnt[menu_cnt]++;
		}
    break;

  case 896:
#line 4608 "fgl.yacc"
    {
		do_print_menu_block_end();
}
    break;

  case 897:
#line 4614 "fgl.yacc"
    {
		push_command(menu_cnt,menu_cmd_cnt[menu_cnt],yyvsp[-1].str,"\"\"","\"\"",0);
		print_menu_block(menu_blk[menu_cnt],menu_cmd_cnt[menu_cnt]-1);
		menu_cmd_cnt[menu_cnt]++;
		}
    break;

  case 898:
#line 4619 "fgl.yacc"
    {
		do_print_menu_block_end();
}
    break;

  case 901:
#line 4626 "fgl.yacc"
    {strcpy(yyval.str,"\"EMPTY\"");}
    break;

  case 902:
#line 4627 "fgl.yacc"
    {sprintf(yyval.str,"\"%s\"",yyvsp[0].str);}
    break;

  case 903:
#line 4629 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str); }
    break;

  case 904:
#line 4630 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 905:
#line 4633 "fgl.yacc"
    {strcpy(yyval.str,"\"\"");}
    break;

  case 906:
#line 4634 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 907:
#line 4635 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 908:
#line 4637 "fgl.yacc"
    {
	print_option_op('N',yyvsp[0].str,menu_blk[menu_cnt]);
}
    break;

  case 909:
#line 4642 "fgl.yacc"
    {
	print_option_op('S',yyvsp[0].str,menu_blk[menu_cnt]);
}
    break;

  case 910:
#line 4647 "fgl.yacc"
    {
	print_option_op('H',yyvsp[0].str,menu_blk[menu_cnt]);
}
    break;

  case 911:
#line 4654 "fgl.yacc"
    {sprintf(yyval.str,"MENU_ALL");}
    break;

  case 915:
#line 4661 "fgl.yacc"
    {sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 916:
#line 4663 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);  
push_menu_title(yyval.str);}
    break;

  case 917:
#line 4665 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str); 
push_menu_title(yyval.str);}
    break;

  case 919:
#line 4675 "fgl.yacc"
    {
		print_message(0,"0",0,message_cnt);
	   }
    break;

  case 920:
#line 4678 "fgl.yacc"
    { 
		print_message(0,yyvsp[-1].str,atoi(yyvsp[0].str),message_cnt);
	  }
    break;

  case 921:
#line 4681 "fgl.yacc"
    { 
		print_message(0,"0",atoi(yyvsp[0].str),message_cnt);
	  }
    break;

  case 928:
#line 4697 "fgl.yacc"
    {
		strcpy(yyval.str,yyvsp[0].str);
		message_cnt=atoi(yyvsp[0].str);
		}
    break;

  case 929:
#line 4702 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 930:
#line 4702 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 931:
#line 4705 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 932:
#line 4733 "fgl.yacc"
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

  case 934:
#line 4790 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 936:
#line 4797 "fgl.yacc"
    { 
         sprintf (yyval.str, "%s.%s", yyvsp[-1].str, yyvsp[0].str); 
         A4GL_lex_printcomment("/* record building -> %s */\n",yyval.str);
         }
    break;

  case 937:
#line 4801 "fgl.yacc"
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

  case 938:
#line 4844 "fgl.yacc"
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

  case 942:
#line 4892 "fgl.yacc"
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

  case 943:
#line 4906 "fgl.yacc"
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

  case 948:
#line 4930 "fgl.yacc"
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

  case 949:
#line 4994 "fgl.yacc"
    {
	 A4GL_debug("---> Subscript or substring");
		strcpy(yyval.str,yyvsp[-1].str);
	}
    break;

  case 950:
#line 4999 "fgl.yacc"
    {
	 A4GL_debug("---> Subscript & substring");
		sprintf(yyval.str,"%s:%s",yyvsp[-4].str,yyvsp[-1].str);
	}
    break;

  case 951:
#line 5007 "fgl.yacc"
    {
A4GL_debug("List element");
  sprintf (yyval.str, "%s", yyvsp[0].str);
}
    break;

  case 952:
#line 5012 "fgl.yacc"
    {
A4GL_debug("List element continues");
  sprintf (yyval.str, "%s,%s", yyvsp[-2].str, yyvsp[0].str); 
}
    break;

  case 953:
#line 5020 "fgl.yacc"
    {
  sprintf (yyval.str, "%s", yyvsp[0].str);
}
    break;

  case 954:
#line 5026 "fgl.yacc"
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

  case 955:
#line 5058 "fgl.yacc"
    {
	 A4GL_debug("Array..");
}
    break;

  case 956:
#line 5061 "fgl.yacc"
    { sprintf (yyval.str, "%s.%s", yyvsp[-2].str, yyvsp[0].str); }
    break;

  case 957:
#line 5063 "fgl.yacc"
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

  case 958:
#line 5104 "fgl.yacc"
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

  case 963:
#line 5157 "fgl.yacc"
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

  case 964:
#line 5209 "fgl.yacc"
    {
		start_bind('f',0);
		/*start_bind('O',0);*/
		strcpy(yyval.str,"0");
		}
    break;

  case 966:
#line 5218 "fgl.yacc"
    {
				start_bind('f',yyvsp[0].str);
				start_bind('O',0);
				sprintf(yyval.str,"1");
			}
    break;

  case 967:
#line 5223 "fgl.yacc"
    {
				int c;
				c=add_bind('f',yyvsp[0].str);
				/*c=add_bind('O',$<str>3); */
				sprintf(yyval.str,"%d",c); 
			}
    break;

  case 968:
#line 5234 "fgl.yacc"
    {
A4GL_lex_printcomment("/*STarted bind %s*/\n",yyvsp[0].str);
start_bind('i',yyvsp[0].str);
A4GL_lex_printcomment("/*STarted bind 2*/\n");
strcpy(yyval.str,"");
}
    break;

  case 969:
#line 5241 "fgl.yacc"
    {
A4GL_lex_printcomment("/* Added */\n");
add_bind('i',yyvsp[0].str);
strcpy(yyval.str,"");
}
    break;

  case 971:
#line 5249 "fgl.yacc"
    {sprintf(yyval.str,"%s.%s",yyvsp[-2].str,yyvsp[-1].str);}
    break;

  case 972:
#line 5252 "fgl.yacc"
    {A4GL_lex_printcomment("/* Variable */\n");}
    break;

  case 973:
#line 5253 "fgl.yacc"
    { A4GL_debug("Got an ibind thru..."); sprintf(yyval.str,"%s\n%s",yyvsp[-2].str,yyvsp[0].str); }
    break;

  case 975:
#line 5255 "fgl.yacc"
    {sprintf(yyval.str,"\"%s\"",yyvsp[0].str);}
    break;

  case 976:
#line 5256 "fgl.yacc"
    {sprintf(yyval.str,"\"%s\"",yyvsp[0].str);}
    break;

  case 977:
#line 5259 "fgl.yacc"
    {
start_bind('o',yyvsp[0].str);
}
    break;

  case 978:
#line 5262 "fgl.yacc"
    {
add_bind('o',yyvsp[0].str);
strcpy(yyval.str,"");
}
    break;

  case 979:
#line 5268 "fgl.yacc"
    {
	addmap("OBIND",yyvsp[0].str,curr_func,yylineno,infilename);
	}
    break;

  case 980:
#line 5271 "fgl.yacc"
    { A4GL_debug("Got an obind thru..."); sprintf(yyval.str,"%s\n%s",yyvsp[-2].str,yyvsp[0].str); }
    break;

  case 981:
#line 5275 "fgl.yacc"
    {
A4GL_lex_printcomment("/* start obind with  %s*/\n",yyvsp[0].str);
A4GL_debug("obind_var_let_list ---> %s\n",yyvsp[0].str);
start_bind('o',yyvsp[0].str);
}
    break;

  case 982:
#line 5280 "fgl.yacc"
    {
A4GL_lex_printcomment("/* add to obind %s */\n",yyvsp[0].str);
add_bind('o',yyvsp[0].str);
A4GL_debug("obind_var_let_list ---> %s\n",yyvsp[0].str);
strcpy(yyval.str,"");
}
    break;

  case 983:
#line 5288 "fgl.yacc"
    {
A4GL_lex_printcomment("/* Read variable %s*/\n",yyvsp[0].str);
}
    break;

  case 984:
#line 5293 "fgl.yacc"
    {
    A4GL_lex_printcomment("/* use_arr_var */\n");
    start_arr_bind('o',yyvsp[0].str);
    A4GL_lex_printcomment("/* use_arr_var complete */\n");
}
    break;

  case 985:
#line 5300 "fgl.yacc"
    {
		start_bind('O',yyvsp[0].str);
	}
    break;

  case 986:
#line 5302 "fgl.yacc"
    {
               add_bind('O',yyvsp[0].str);
               strcpy(yyval.str,"");
	}
    break;

  case 991:
#line 5334 "fgl.yacc"
    {
A4GL_lex_printcomment("/*STarted bind %s*/\n",yyvsp[0].str);
start_bind('N',yyvsp[0].str);
A4GL_lex_printcomment("/*STarted bind 2*/\n");
strcpy(yyval.str,"");
}
    break;

  case 992:
#line 5341 "fgl.yacc"
    {
A4GL_lex_printcomment("/* Added */\n");
add_bind('N',yyvsp[0].str);
strcpy(yyval.str,"");
}
    break;

  case 993:
#line 5348 "fgl.yacc"
    {
		strcpy(yyval.str,yyvsp[0].str);
	}
    break;

  case 994:
#line 5351 "fgl.yacc"
    {
			sprintf(yyval.str,"%s\n%s",yyvsp[-2].str,yyvsp[0].str);
		}
    break;

  case 995:
#line 5365 "fgl.yacc"
    {
form_attrib.iswindow=1;
print_open_window(yyvsp[-5].str,yyvsp[-1].str);
sprintf(yyval.str,"open window");
}
    break;

  case 1000:
#line 5382 "fgl.yacc"
    {
	print_niy("OPEN_STATUSBOX");
}
    break;

  case 1001:
#line 5387 "fgl.yacc"
    {
addmap("Call Formhandler",yyvsp[0].str,curr_func,yylineno,infilename); 
}
    break;

  case 1002:
#line 5393 "fgl.yacc"
    {
		print_open_form(yyvsp[0].str,yyvsp[-1].str,yyvsp[-1].str);
		}
    break;

  case 1004:
#line 5400 "fgl.yacc"
    { form_attrib.iswindow=0;strcpy(yyval.str,"A4GL_open_form(%s);"); }
    break;

  case 1005:
#line 5405 "fgl.yacc"
    {sprintf(yyval.str,"A4GL_open_gui_form(&%%s,%%s,%s,%s,%s,hnd_e_%s,hnd_c_%s);",yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[0].str,yyvsp[0].str);}
    break;

  case 1006:
#line 5408 "fgl.yacc"
    {strcpy(yyval.str,"0,0");}
    break;

  case 1007:
#line 5409 "fgl.yacc"
    {sprintf(yyval.str,"%s,2",yyvsp[-5].str);}
    break;

  case 1008:
#line 5412 "fgl.yacc"
    {strcpy(yyval.str,"\"\"");}
    break;

  case 1009:
#line 5413 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1010:
#line 5416 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 1011:
#line 5417 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 1012:
#line 5422 "fgl.yacc"
    {
print_open_session(yyvsp[-3].str,yyvsp[-1].str,yyvsp[0].str);

}
    break;

  case 1013:
#line 5429 "fgl.yacc"
    {
	print_open_cursor(yyvsp[0].str,"0");
}
    break;

  case 1014:
#line 5432 "fgl.yacc"
    {
	print_open_cursor(yyvsp[-3].str,yyvsp[0].str); /* CHANGED from $<str>4 */
}
    break;

  case 1015:
#line 5438 "fgl.yacc"
    {sprintf(yyval.str,"0,0");}
    break;

  case 1016:
#line 5440 "fgl.yacc"
    {sprintf(yyval.str,"%s, %s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1017:
#line 5442 "fgl.yacc"
    {sprintf(yyval.str,"%s, %s",yyvsp[-3].str,yyvsp[0].str);}
    break;

  case 1018:
#line 5444 "fgl.yacc"
    {sprintf(yyval.str,"%s, %s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1019:
#line 5447 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 1020:
#line 5447 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 1021:
#line 5448 "fgl.yacc"
    {strcpy(yyval.str,"2");}
    break;

  case 1022:
#line 5453 "fgl.yacc"
    {
	print_open_session(yyvsp[-1].str,yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 1023:
#line 5461 "fgl.yacc"
    {strcpy(yyval.str,"\"default_conn\"");}
    break;

  case 1024:
#line 5462 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1025:
#line 5467 "fgl.yacc"
    {sprintf(yyval.str,"0,0");}
    break;

  case 1026:
#line 5469 "fgl.yacc"
    {sprintf(yyval.str,"%s, %s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1027:
#line 5471 "fgl.yacc"
    {sprintf(yyval.str,"%s, %s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1031:
#line 5489 "fgl.yacc"
    { print_options('C',yyvsp[0].str); }
    break;

  case 1032:
#line 5490 "fgl.yacc"
    { print_options('E',yyvsp[0].str); }
    break;

  case 1033:
#line 5491 "fgl.yacc"
    { print_options('F',yyvsp[0].str); }
    break;

  case 1034:
#line 5492 "fgl.yacc"
    { print_options('M',yyvsp[0].str); }
    break;

  case 1035:
#line 5493 "fgl.yacc"
    { print_options('m',yyvsp[0].str); }
    break;

  case 1036:
#line 5494 "fgl.yacc"
    { print_options('P',yyvsp[0].str); }
    break;

  case 1037:
#line 5495 "fgl.yacc"
    { print_options('A',yyvsp[0].str); iskey=0; }
    break;

  case 1038:
#line 5496 "fgl.yacc"
    { print_options('D',yyvsp[0].str); iskey=0; }
    break;

  case 1039:
#line 5497 "fgl.yacc"
    { print_options('I',yyvsp[0].str); iskey=0; }
    break;

  case 1040:
#line 5498 "fgl.yacc"
    { print_options('N',yyvsp[0].str); }
    break;

  case 1041:
#line 5499 "fgl.yacc"
    { print_options('p',yyvsp[0].str); iskey=0; }
    break;

  case 1042:
#line 5500 "fgl.yacc"
    { print_options('H',yyvsp[0].str); }
    break;

  case 1043:
#line 5501 "fgl.yacc"
    { print_set_helpfile(yyvsp[0].str); }
    break;

  case 1044:
#line 5502 "fgl.yacc"
    { print_set_langfile(yyvsp[0].str); }
    break;

  case 1045:
#line 5503 "fgl.yacc"
    { print_options('Z',"1"); }
    break;

  case 1046:
#line 5504 "fgl.yacc"
    { print_options('Z',"2"); }
    break;

  case 1047:
#line 5505 "fgl.yacc"
    { print_options('Y',"1"); }
    break;

  case 1048:
#line 5506 "fgl.yacc"
    { print_options('Y',"2"); }
    break;

  case 1049:
#line 5507 "fgl.yacc"
    { print_options('d',yyvsp[0].str);print_options('Z',"0"); }
    break;

  case 1050:
#line 5508 "fgl.yacc"
    { print_options('i',yyvsp[0].str); print_options('Y',"0");}
    break;

  case 1051:
#line 5509 "fgl.yacc"
    { print_options('W',"1"); }
    break;

  case 1052:
#line 5510 "fgl.yacc"
    { print_options('W',"0"); }
    break;

  case 1053:
#line 5511 "fgl.yacc"
    { print_options('f',"1"); }
    break;

  case 1054:
#line 5512 "fgl.yacc"
    { print_options('f',"0"); }
    break;

  case 1055:
#line 5513 "fgl.yacc"
    { print_options('S',"1"); }
    break;

  case 1056:
#line 5514 "fgl.yacc"
    { print_options('S',"0"); }
    break;

  case 1057:
#line 5529 "fgl.yacc"
    {
	print_prepare(yyvsp[-2].str,yyvsp[0].str);
	addmap("Prepare",yyvsp[-2].str,curr_func,yylineno,infilename);
	print_undo_use(yyvsp[-4].str);
}
    break;

  case 1060:
#line 5538 "fgl.yacc"
    {
		print_execute(yyvsp[0].str,0);
		addmap("Execute",yyvsp[0].str,curr_func,yylineno,infilename);
		}
    break;

  case 1061:
#line 5542 "fgl.yacc"
    {
		addmap("Execute",yyvsp[-2].str,curr_func,yylineno,infilename);
		print_execute(yyvsp[-2].str,1);
	}
    break;

  case 1062:
#line 5546 "fgl.yacc"
    {
		addmap("Execute",yyvsp[-2].str,curr_func,yylineno,infilename);
		print_execute(yyvsp[-2].str,2);
	}
    break;

  case 1063:
#line 5550 "fgl.yacc"
    {
		addmap("Execute",yyvsp[-4].str,curr_func,yylineno,infilename);
		print_execute(yyvsp[-4].str,3);
	}
    break;

  case 1064:
#line 5554 "fgl.yacc"
    {
		print_execute_immediate(yyvsp[0].str);
	}
    break;

  case 1066:
#line 5574 "fgl.yacc"
    {
                push_blockcommand("PROMPT");
	A4GL_new_events();
	print_prompt_1(yyvsp[-6].str,yyvsp[-4].str,yyvsp[-1].str,yyvsp[0].str,atoi(yyvsp[-2].str)) ;
}
    break;

  case 1067:
#line 5579 "fgl.yacc"
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

  case 1068:
#line 5592 "fgl.yacc"
    {sprintf(yyval.str,"0");}
    break;

  case 1069:
#line 5593 "fgl.yacc"
    {sprintf(yyval.str,yyvsp[0].str);}
    break;

  case 1070:
#line 5597 "fgl.yacc"
    {
		print_niy("GUI PROMPT");
	}
    break;

  case 1071:
#line 5602 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 1072:
#line 5603 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 1073:
#line 5607 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1077:
#line 5613 "fgl.yacc"
    {
	A4GL_add_onkey_key(yyvsp[0].str);
	print_onkey_1(yyvsp[0].str);
}
    break;

  case 1078:
#line 5616 "fgl.yacc"
    {
	print_onkey_2_prompt();
}
    break;

  case 1080:
#line 5631 "fgl.yacc"
    {
		start_bind('i',0);
		}
    break;

  case 1081:
#line 5635 "fgl.yacc"
    {
		print_put(yyvsp[-2].str,yyvsp[0].str);
	}
    break;

  case 1082:
#line 5641 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1083:
#line 5642 "fgl.yacc"
    { strcpy(yyval.str,yyvsp[0].str);
A4GL_debug("putlist = %s\n",yyval.str);
}
    break;

  case 1084:
#line 5647 "fgl.yacc"
    {push_gen(PUTVAL,yyvsp[0].str);}
    break;

  case 1085:
#line 5648 "fgl.yacc"
    {push_gen(PUTVAL,yyvsp[0].str); sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1086:
#line 5651 "fgl.yacc"
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

  case 1088:
#line 5678 "fgl.yacc"
    {
			addmap("Start Report",yyvsp[-2].str,curr_func,yylineno,infilename);
			print_start_report("P","acl_getenv(\"DBPRINT\")",yyvsp[-2].str);
			}
    break;

  case 1089:
#line 5682 "fgl.yacc"
    {
			addmap("Start Report",yyvsp[-3].str,curr_func,yylineno,infilename);
			print_start_report("F",yyvsp[-1].str,yyvsp[-3].str);
			}
    break;

  case 1090:
#line 5686 "fgl.yacc"
    {
			addmap("Start Report",yyvsp[-3].str,curr_func,yylineno,infilename);
			print_start_report("P",yyvsp[-1].str,yyvsp[-3].str);
			}
    break;

  case 1091:
#line 5690 "fgl.yacc"
    {
			addmap("Start Report",yyvsp[-1].str,curr_func,yylineno,infilename);
			print_start_report("","\"\"",yyvsp[-1].str);
			}
    break;

  case 1092:
#line 5697 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 1093:
#line 5698 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 1099:
#line 5710 "fgl.yacc"
    {
		addmap("Output to report",yyvsp[-5].str,curr_func,yylineno,infilename);
		print_output_to_report(yyvsp[-5].str,yyvsp[-1].str); 
		}
    break;

  case 1100:
#line 5716 "fgl.yacc"
    {
		addmap("Finish Report",yyvsp[0].str,curr_func,yylineno,infilename);
		print_finish_report(yyvsp[0].str);
		}
    break;

  case 1101:
#line 5724 "fgl.yacc"
    {
		addmap("Finish Report",yyvsp[0].str,curr_func,yylineno,infilename);
		print_terminate_report(yyvsp[0].str);
}
    break;

  case 1102:
#line 5730 "fgl.yacc"
    { strcpy(yyval.str,yyvsp[0].str); }
    break;

  case 1103:
#line 5732 "fgl.yacc"
    {
	print_format_every_row();
}
    break;

  case 1107:
#line 5742 "fgl.yacc"
    { push_report_block("FIRST",'P');}
    break;

  case 1108:
#line 5742 "fgl.yacc"
    {
		rep_struct.lines_in_first_header=if_print_stack[0][0];
		pdf_rep_struct.lines_in_first_header=if_print_stack[0][0];
		print_rep_ret(0,1);
		}
    break;

  case 1109:
#line 5747 "fgl.yacc"
    { 
		push_report_block("TRAILER",'T');
		if_print_stack[0][0]=0;
		if_print_stack[0][1]=0;
	}
    break;

  case 1110:
#line 5751 "fgl.yacc"
    {
		rep_struct.lines_in_trailer=if_print_stack[0][0];
		pdf_rep_struct.lines_in_trailer=if_print_stack[0][0];
		print_rep_ret(0,1);
	}
    break;

  case 1111:
#line 5756 "fgl.yacc"
    { push_report_block("HEADER",'p');}
    break;

  case 1112:
#line 5756 "fgl.yacc"
    {
		rep_struct.lines_in_header=if_print_stack[0][0];
		pdf_rep_struct.lines_in_header=if_print_stack[0][0];
		print_rep_ret(0,1);}
    break;

  case 1113:
#line 5760 "fgl.yacc"
    { push_report_block("EVERY",'E');}
    break;

  case 1114:
#line 5760 "fgl.yacc"
    {print_rep_ret(0,1);}
    break;

  case 1115:
#line 5761 "fgl.yacc"
    { push_report_block("LAST",'L');}
    break;

  case 1116:
#line 5761 "fgl.yacc"
    {print_rep_ret(0,1);}
    break;

  case 1117:
#line 5762 "fgl.yacc"
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

  case 1118:
#line 5775 "fgl.yacc"
    {print_rep_ret(0,1);}
    break;

  case 1119:
#line 5776 "fgl.yacc"
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

  case 1120:
#line 5792 "fgl.yacc"
    {print_rep_ret(0,1);}
    break;

  case 1127:
#line 5804 "fgl.yacc"
    {start_state("skip",1);}
    break;

  case 1128:
#line 5804 "fgl.yacc"
    {
	print_need_lines();
	start_state("skip",0);
}
    break;

  case 1129:
#line 5810 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 1130:
#line 5810 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 1131:
#line 5813 "fgl.yacc"
    {start_state("KWLINE",1);}
    break;

  case 1132:
#line 5813 "fgl.yacc"
    {
double n;
char buff[256];
strcpy(buff,yyvsp[0].str);
n=atof(yyvsp[-2].str);
if (buff[0]=='1') {
	print_skip_lines(n);
	if (if_print_stack_cnt==0) if_print_section[0]=0;
	if (get_curr_report_stack_whytype_1()=='T') {
		if_print_stack[if_print_stack_cnt][if_print_section[if_print_stack_cnt]]+=(int)n;
	}
} else {
	if (rep_type!=REP_TYPE_PDF) { a4gl_yyerror("SKIP BY is only in PDF reports"); YYERROR; } print_skip_by(n);
}
start_state("KWLINE",0); 
}
    break;

  case 1133:
#line 5829 "fgl.yacc"
    { print_skip_top(); }
    break;

  case 1134:
#line 5830 "fgl.yacc"
    { print_niy("FONT SIZE"); }
    break;

  case 1135:
#line 5831 "fgl.yacc"
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

  case 1136:
#line 5840 "fgl.yacc"
    {
			if (rep_type!=REP_TYPE_PDF) {
				a4gl_yyerror("SKIP TO is only in PDF reports");
				YYERROR;
			}
			print_skip_to(yyvsp[0].str);
		}
    break;

  case 1137:
#line 5852 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1143:
#line 5863 "fgl.yacc"
    {
	print_niy("PRINT AT...");
}
    break;

  case 1144:
#line 5868 "fgl.yacc"
    {doing_a_print=1;}
    break;

  case 1145:
#line 5868 "fgl.yacc"
    {
	char wt;
	doing_a_print=0;
	print_report_print(0,yyvsp[0].str,0);
	wt=get_curr_report_stack_whytype_1();
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
		if (get_curr_report_stack_whytype_1()=='T') {
			if_print_stack[if_print_stack_cnt][if_print_section[if_print_stack_cnt]]+=1;
		}
	}
}
    break;

  case 1146:
#line 5889 "fgl.yacc"
    { 
	print_report_print_file(yyvsp[-1].str,yyvsp[0].str);
}
    break;

  case 1147:
#line 5894 "fgl.yacc"
    { 
	print_report_print_img(yyvsp[-1].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 1148:
#line 5900 "fgl.yacc"
    { strcpy(yyval.str,A4GL_get_default_scaling());}
    break;

  case 1149:
#line 5901 "fgl.yacc"
    { strcpy(yyval.str,yyvsp[0].str); strcat(yyval.str,yyvsp[0].str); }
    break;

  case 1150:
#line 5902 "fgl.yacc"
    {sprintf(yyval.str,"%s %s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1151:
#line 5906 "fgl.yacc"
    {strcpy(yyval.str,"tiff");}
    break;

  case 1152:
#line 5907 "fgl.yacc"
    {strcpy(yyval.str,"gif");}
    break;

  case 1153:
#line 5908 "fgl.yacc"
    {strcpy(yyval.str,"png");}
    break;

  case 1154:
#line 5909 "fgl.yacc"
    {strcpy(yyval.str,"jpeg");}
    break;

  case 1155:
#line 5913 "fgl.yacc"
    {
	int vtype;
	vtype=scan_variable(yyvsp[0].str);
	if (vtype!=11&&vtype!=12) {
	a4gl_yyerror("Only Blobs may be printed...");
	YYERROR;
	}
}
    break;

  case 1156:
#line 5923 "fgl.yacc"
    {
strcpy(yyval.str,"0");
}
    break;

  case 1157:
#line 5925 "fgl.yacc"
    {
strcpy(yyval.str,"1");
}
    break;

  case 1158:
#line 5930 "fgl.yacc"
    {
	print_report_print(1,0,yyvsp[0].str);
	}
    break;

  case 1159:
#line 5933 "fgl.yacc"
    {
	print_report_print(1,0,yyvsp[0].str); /* changed from $<str>1 */
}
    break;

  case 1160:
#line 5938 "fgl.yacc"
    {
	strcpy(yyval.str,yyvsp[0].str); 
	}
    break;

  case 1161:
#line 5945 "fgl.yacc"
    {
int a;
a=add_report_agg('S',yyvsp[-2].ptr,yyvsp[0].ptr,racnt);
sprintf(yyval.str,"A4GL_push_double(_g%d);\n",racnt);
racnt+=a;
}
    break;

  case 1162:
#line 5952 "fgl.yacc"
    {
int a;
a=add_report_agg('C',0,yyvsp[0].ptr,racnt);
sprintf(yyval.str,"A4GL_push_int(_g%d);\n",racnt);
racnt+=a;
}
    break;

  case 1163:
#line 5959 "fgl.yacc"
    {
int a;
a=add_report_agg('C',0,yyvsp[0].ptr,racnt);
sprintf(yyval.str,"A4GL_push_int(_g%d);\n",racnt);
racnt+=a;
}
    break;

  case 1164:
#line 5968 "fgl.yacc"
    {
int a;
a=add_report_agg('P',yyvsp[-2].ptr,yyvsp[0].ptr,racnt);
sprintf(yyval.str,"A4GL_push_double((double)_g%d/(double)_g%d);\n",racnt,racnt+1);
racnt+=a;
}
    break;

  case 1165:
#line 5975 "fgl.yacc"
    {
int a;
a=add_report_agg('A',yyvsp[-2].ptr,yyvsp[0].ptr,racnt);
sprintf(yyval.str,"A4GL_push_double(_g%d/(double)_g%d);\n",racnt,racnt+1);
racnt+=a;
}
    break;

  case 1166:
#line 5982 "fgl.yacc"
    {
int a;
a=add_report_agg('A',yyvsp[-2].ptr,yyvsp[0].ptr,racnt);
sprintf(yyval.str,"A4GL_push_double(_g%d/_g%d);\n",racnt,racnt+1);
racnt+=a;
}
    break;

  case 1167:
#line 5989 "fgl.yacc"
    {
int a;
a=add_report_agg('N',yyvsp[-2].ptr,yyvsp[0].ptr,racnt);
sprintf(yyval.str,"A4GL_push_double(_g%d);\n",racnt);
racnt+=a;
}
    break;

  case 1168:
#line 5996 "fgl.yacc"
    {
int a;
a=add_report_agg('X',yyvsp[-2].ptr,yyvsp[0].ptr,racnt);
sprintf(yyval.str,"A4GL_push_double(_g%d);\n",racnt);
racnt+=a;
}
    break;

  case 1173:
#line 6009 "fgl.yacc"
    {rep_struct.left_margin=atoi(yyvsp[0].str);}
    break;

  case 1174:
#line 6010 "fgl.yacc"
    {rep_struct.right_margin=atoi(yyvsp[0].str);}
    break;

  case 1175:
#line 6011 "fgl.yacc"
    {rep_struct.top_margin=atoi(yyvsp[0].str);}
    break;

  case 1176:
#line 6012 "fgl.yacc"
    {rep_struct.bottom_margin=atoi(yyvsp[0].str);}
    break;

  case 1177:
#line 6013 "fgl.yacc"
    {rep_struct.page_length=atoi(yyvsp[0].str);}
    break;

  case 1178:
#line 6014 "fgl.yacc"
    { rep_struct.output_mode='P';strcpy(rep_struct.output_loc,"acl_getenv(\"DBPRINT\")");}
    break;

  case 1179:
#line 6015 "fgl.yacc"
    {rep_struct.output_mode='F';strcpy(rep_struct.output_loc,yyvsp[0].str);}
    break;

  case 1180:
#line 6016 "fgl.yacc"
    {rep_struct.output_mode='F';strcpy(rep_struct.output_loc,yyvsp[0].str);}
    break;

  case 1181:
#line 6017 "fgl.yacc"
    {rep_struct.output_mode='P';strcpy(rep_struct.output_loc,yyvsp[0].str);}
    break;

  case 1182:
#line 6018 "fgl.yacc"
    {strcpy(rep_struct.top_of_page,yyvsp[0].str);}
    break;

  case 1185:
#line 6024 "fgl.yacc"
    {sprintf(yyval.str,"-%f",atof(yyvsp[-1].str));}
    break;

  case 1186:
#line 6025 "fgl.yacc"
    {sprintf(yyval.str,"-%f",atof(yyvsp[-1].str)*72.0); }
    break;

  case 1187:
#line 6026 "fgl.yacc"
    {sprintf(yyval.str,"-%f",atof(yyvsp[-1].str)*2.83465);}
    break;

  case 1188:
#line 6027 "fgl.yacc"
    {sprintf(yyval.str,"%f",atof(yyvsp[0].str));}
    break;

  case 1193:
#line 6036 "fgl.yacc"
    {pdf_rep_struct.left_margin=atof(yyvsp[0].str);A4GL_debug("Left margin=%s\n",yyvsp[0].str);}
    break;

  case 1194:
#line 6037 "fgl.yacc"
    {pdf_rep_struct.right_margin=atof(yyvsp[0].str);}
    break;

  case 1195:
#line 6038 "fgl.yacc"
    {pdf_rep_struct.top_margin=atof(yyvsp[0].str);}
    break;

  case 1196:
#line 6039 "fgl.yacc"
    {pdf_rep_struct.bottom_margin=atof(yyvsp[0].str);}
    break;

  case 1197:
#line 6040 "fgl.yacc"
    {pdf_rep_struct.page_length=atof(yyvsp[0].str);}
    break;

  case 1198:
#line 6041 "fgl.yacc"
    {pdf_rep_struct.page_width=atof(yyvsp[0].str);}
    break;

  case 1199:
#line 6042 "fgl.yacc"
    {strcpy(pdf_rep_struct.font_name,yyvsp[0].str);}
    break;

  case 1200:
#line 6043 "fgl.yacc"
    {pdf_rep_struct.font_size=atof(yyvsp[0].str);}
    break;

  case 1201:
#line 6045 "fgl.yacc"
    {pdf_rep_struct.paper_size=1;}
    break;

  case 1202:
#line 6046 "fgl.yacc"
    {pdf_rep_struct.paper_size=2;}
    break;

  case 1203:
#line 6047 "fgl.yacc"
    {pdf_rep_struct.paper_size=3;}
    break;

  case 1204:
#line 6048 "fgl.yacc"
    {pdf_rep_struct.paper_size=5;}
    break;

  case 1205:
#line 6050 "fgl.yacc"
    {pdf_rep_struct.paper_size=-1;}
    break;

  case 1206:
#line 6051 "fgl.yacc"
    {pdf_rep_struct.paper_size=-2;}
    break;

  case 1207:
#line 6052 "fgl.yacc"
    {pdf_rep_struct.paper_size=-3;}
    break;

  case 1208:
#line 6053 "fgl.yacc"
    {pdf_rep_struct.paper_size=-5;}
    break;

  case 1212:
#line 6058 "fgl.yacc"
    {pdf_rep_struct.output_mode='F';strcpy(pdf_rep_struct.output_loc,yyvsp[0].str);}
    break;

  case 1213:
#line 6059 "fgl.yacc"
    {pdf_rep_struct.output_mode='P';strcpy(pdf_rep_struct.output_loc,yyvsp[0].str);}
    break;

  case 1217:
#line 6066 "fgl.yacc"
    {
int a;
set_rep_no_orderby(1);
if (get_bind_cnt('f')&&!get_bind_cnt('O')) { A4GL_copy_fbind_to_Obind(); }
a=print_bind_definition('O');
print_order_by_type(2,-1);
sprintf(yyval.str,"%d",a);
}
    break;

  case 1218:
#line 6075 "fgl.yacc"
    {
int a;
set_rep_no_orderby(0);
if (get_bind_cnt('f')&&!get_bind_cnt('O')) { A4GL_copy_fbind_to_Obind(); }
a=print_bind_definition('O');
print_order_by_type(1,a);
sprintf(yyval.str,"%d",a);
A4GL_debug("Order by Gives :%d\n",a);
}
    break;

  case 1219:
#line 6084 "fgl.yacc"
    {
int a;
set_rep_no_orderby(0);
if (get_bind_cnt('f')&&!get_bind_cnt('O')) { A4GL_copy_fbind_to_Obind(); }
a=print_bind_definition('O');
print_order_by_type(2,a);
sprintf(yyval.str,"%d",a);
A4GL_debug("Order by Gives :%d\n",a);
}
    break;

  case 1220:
#line 6097 "fgl.yacc"
    { 
		rep_type=REP_TYPE_NORMAL; 
		clr_function_constants (); 
		clr_variable(); 
		lastlineno=yylineno; 
		init_report_structure(&rep_struct); 
		}
    break;

  case 1221:
#line 6106 "fgl.yacc"
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

  case 1222:
#line 6117 "fgl.yacc"
    {
		lastlineno=yylineno;
		}
    break;

  case 1223:
#line 6121 "fgl.yacc"
    {
		print_variables();
		}
    break;

  case 1224:
#line 6125 "fgl.yacc"
    {
		print_report_2(0,yyvsp[0].str);
		rordcnt=atoi(yyvsp[0].str);
	 A4GL_debug("SET rordcnt=%d %s",rordcnt,yyvsp[0].str);
		}
    break;

  case 1225:
#line 6131 "fgl.yacc"
    {
		print_report_ctrl();
		}
    break;

  case 1226:
#line 6136 "fgl.yacc"
    {
		pop_blockcommand("REPORT");
		print_report_end() ;
		}
    break;

  case 1227:
#line 6144 "fgl.yacc"
    { strcpy(yyval.str,"");
	yyval.ptr=0;
}
    break;

  case 1228:
#line 6147 "fgl.yacc"
    {
	yyval.ptr=yyvsp[0].ptr;
//sprintf($<str>$,"%s", $<str>2);
}
    break;

  case 1229:
#line 6156 "fgl.yacc"
    {
if (!in_command("REPORT")) {
	a4gl_yyerror("PAUSE can only be used in reportes");
	YYERROR;
        }

print_pause(yyvsp[0].str) ;
}
    break;

  case 1230:
#line 6167 "fgl.yacc"
    {strcpy(yyval.str,"\"\"");}
    break;

  case 1232:
#line 6174 "fgl.yacc"
    {
rep_type=REP_TYPE_PDF;
clr_function_constants();
clr_variable(); 
lastlineno=yylineno; 
pdf_init_report_structure(&pdf_rep_struct);
}
    break;

  case 1233:
#line 6182 "fgl.yacc"
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

  case 1234:
#line 6192 "fgl.yacc"
    {
lastlineno=yylineno;
}
    break;

  case 1235:
#line 6195 "fgl.yacc"
    {
	print_variables();
}
    break;

  case 1236:
#line 6199 "fgl.yacc"
    {
//print_variables();
resize_paper(&pdf_rep_struct);
	print_report_2(1,yyvsp[0].str);
A4GL_debug("SET rordcnt=%d (%s)",rordcnt,yyvsp[0].str);
	rordcnt=atoi(yyvsp[0].str);
}
    break;

  case 1237:
#line 6207 "fgl.yacc"
    {
print_report_ctrl();
}
    break;

  case 1238:
#line 6210 "fgl.yacc"
    {
	pop_blockcommand("REPORT");
	print_report_end();
}
    break;

  case 1239:
#line 6216 "fgl.yacc"
    { strcpy(yyval.str,yyvsp[0].str); }
    break;

  case 1240:
#line 6220 "fgl.yacc"
    {new_counter();
   		addmap("CALL",yyvsp[-1].str,curr_func,yylineno,infilename);
   		}
    break;

  case 1241:
#line 6224 "fgl.yacc"
    {
		sprintf(yyval.str,"%d",get_counter_val());drop_counter();
		}
    break;

  case 1242:
#line 6228 "fgl.yacc"
    {
		print_pdf_call(yyvsp[-5].str,yyvsp[-2].ptr,yyvsp[-1].str);
   		}
    break;

  case 1243:
#line 6232 "fgl.yacc"
    {
	print_returning();
   }
    break;

  case 1244:
#line 6238 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 1245:
#line 6239 "fgl.yacc"
    { strcpy(yyval.str,"_rep.right_margin"); }
    break;

  case 1246:
#line 6240 "fgl.yacc"
    { sprintf(yyval.str,"%s",yyvsp[0].str); }
    break;

  case 1247:
#line 6241 "fgl.yacc"
    { sprintf(yyval.str,"%s",yyvsp[0].str); }
    break;

  case 1248:
#line 6246 "fgl.yacc"
    {
print_system_run(0,0);
}
    break;

  case 1249:
#line 6248 "fgl.yacc"
    {
print_system_run(1,yyvsp[0].str);
}
    break;

  case 1250:
#line 6251 "fgl.yacc"
    {
print_system_run(2,0);
}
    break;

  case 1251:
#line 6255 "fgl.yacc"
    {
print_system_run(0,0);
}
    break;

  case 1252:
#line 6258 "fgl.yacc"
    {
print_system_run(0,0);
/* FIXME */
}
    break;

  case 1253:
#line 6265 "fgl.yacc"
    {
	print_exec_sql(yyvsp[0].str);
}
    break;

  case 1254:
#line 6270 "fgl.yacc"
    {sprintf(yyval.str, "%s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1255:
#line 6271 "fgl.yacc"
    {sprintf(yyval.str,  "%s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1256:
#line 6272 "fgl.yacc"
    {sprintf(yyval.str,"%s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1257:
#line 6273 "fgl.yacc"
    {sprintf(yyval.str,"%s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1258:
#line 6278 "fgl.yacc"
    { print_exec_sql(yyvsp[0].str); }
    break;

  case 1259:
#line 6279 "fgl.yacc"
    { print_exec_sql(yyvsp[0].sql_string); 
	free(yyvsp[0].sql_string);
}
    break;

  case 1260:
#line 6285 "fgl.yacc"
    {insql=1;}
    break;

  case 1261:
#line 6285 "fgl.yacc"
    {insql=0;}
    break;

  case 1262:
#line 6285 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-7].str," ",yyvsp[-5].str," ",yyvsp[-4].str,yyvsp[-2].sql_string,yyvsp[-1].str,yyvsp[0].str,0);
		free(yyvsp[-2].sql_string);
	}
    break;

  case 1263:
#line 6290 "fgl.yacc"
    {insql=1;}
    break;

  case 1264:
#line 6290 "fgl.yacc"
    {insql=0;}
    break;

  case 1265:
#line 6290 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-8].str," ",yyvsp[-6].str," ",yyvsp[-5].str,yyvsp[-3].sql_string,yyvsp[-2].str, " ",yyvsp[-1].str,yyvsp[0].str,0);
		free(yyvsp[-3].sql_string);
	}
    break;

  case 1266:
#line 6298 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1267:
#line 6299 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1269:
#line 6304 "fgl.yacc"
    {sprintf(yyval.str,"%s%s",yyvsp[-1].str,yyvsp[0].str); }
    break;

  case 1270:
#line 6309 "fgl.yacc"
    {sprintf(yyval.str," IN %s",yyvsp[0].str);}
    break;

  case 1271:
#line 6310 "fgl.yacc"
    {sprintf(yyval.str," EXTENT SIZE %s",yyvsp[0].str); }
    break;

  case 1272:
#line 6311 "fgl.yacc"
    {sprintf(yyval.str," NEXT SIZE %s",yyvsp[0].str); }
    break;

  case 1273:
#line 6312 "fgl.yacc"
    {sprintf(yyval.str," LOCK MODE PAGE");}
    break;

  case 1274:
#line 6313 "fgl.yacc"
    {sprintf(yyval.str," LOCK MODE ROW");}
    break;

  case 1276:
#line 6318 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1277:
#line 6318 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1279:
#line 6322 "fgl.yacc"
    {sprintf(yyval.str,"%s%s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1280:
#line 6326 "fgl.yacc"
    {sprintf(yyval.str," IN %s",yyvsp[0].str);}
    break;

  case 1281:
#line 6327 "fgl.yacc"
    {sprintf(yyval.str,"FILLFACTOR %s",yyvsp[0].str);}
    break;

  case 1282:
#line 6330 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s %s %s %s %s",yyvsp[-7].str,yyvsp[-6].str,yyvsp[-5].str,yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1283:
#line 6331 "fgl.yacc"
    {
		a4gl_yyerror("You cannot create a database from within Aubit4gl - if the target database allows - prepare and execute it manually");
	}
    break;

  case 1284:
#line 6334 "fgl.yacc"
    {
		a4gl_yyerror("You cannot drop a database from within Aubit4gl - if the target database allows - prepare and execute it manually");
	}
    break;

  case 1285:
#line 6337 "fgl.yacc"
    {
		sprintf(yyval.str,"%s %s FOR %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[0].str);
	}
    break;

  case 1286:
#line 6340 "fgl.yacc"
    {
		sprintf(yyval.str,"%s %s",yyvsp[-1].str,yyvsp[0].str);
	}
    break;

  case 1287:
#line 6346 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1288:
#line 6348 "fgl.yacc"
    {
if (A4GL_isyes(acl_getenv("A4GL_OMIT_NO_LOG"))) {
	strcpy(yyval.str,"");
} else {
	sprintf(yyval.str," %s ",yyvsp[0].str);
}
}
    break;

  case 1290:
#line 6361 "fgl.yacc"
    {sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1291:
#line 6365 "fgl.yacc"
    {sprintf(yyval.str,"%s ASC",yyvsp[-1].str);}
    break;

  case 1292:
#line 6366 "fgl.yacc"
    {sprintf(yyval.str,"%s DESC",yyvsp[-1].str);}
    break;

  case 1294:
#line 6371 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1295:
#line 6374 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",",yyvsp[0].sql_string,0);
	}
    break;

  case 1296:
#line 6380 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1297:
#line 6383 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1298:
#line 6391 "fgl.yacc"
    {sprintf(yyval.str,"%s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1300:
#line 6398 "fgl.yacc"
    {
	yyval.sql_string=make_sql_string(yyvsp[-2].str," ",yyvsp[-1].str," ",yyvsp[0].sql_string,0);
	print_exec_sql(yyval.sql_string); 
}
    break;

  case 1301:
#line 6402 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("ALTER INDEX ",yyvsp[-1].str," TO CLUSTER",0);
		print_exec_sql(yyval.sql_string); 
		}
    break;

  case 1302:
#line 6406 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("ALTER INDEX ",yyvsp[-1].str," TO NOT CLUSTER",0);
		}
    break;

  case 1303:
#line 6412 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1304:
#line 6415 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",",yyvsp[0].sql_string,0);
	}
    break;

  case 1305:
#line 6424 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1306:
#line 6427 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1307:
#line 6430 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1308:
#line 6433 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1309:
#line 6436 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1310:
#line 6439 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1311:
#line 6442 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1312:
#line 6449 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("ADD ",yyvsp[0].sql_string,0);
	}
    break;

  case 1313:
#line 6452 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("ADD (",yyvsp[-1].sql_string,")",0);
	}
    break;

  case 1314:
#line 6459 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1315:
#line 6462 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string," BEFORE ",yyvsp[0].str,0);
	}
    break;

  case 1316:
#line 6468 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1317:
#line 6471 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",",yyvsp[0].sql_string,0);
	}
    break;

  case 1318:
#line 6478 "fgl.yacc"
    {
		sprintf(yyval.str,"DROP %s",yyvsp[0].str);
	}
    break;

  case 1319:
#line 6481 "fgl.yacc"
    {
		sprintf(yyval.str,"DROP (%s)",yyvsp[-1].str);
	}
    break;

  case 1321:
#line 6489 "fgl.yacc"
    {
		sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);
	}
    break;

  case 1323:
#line 6498 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("MODIFY ",yyvsp[0].sql_string,0);
	}
    break;

  case 1324:
#line 6501 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("MODIFY (",yyvsp[-1].sql_string,")",0);
	}
    break;

  case 1325:
#line 6507 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1326:
#line 6510 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",",yyvsp[0].sql_string,0);
	}
    break;

  case 1327:
#line 6516 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1328:
#line 6523 "fgl.yacc"
    {strcpy(yyval.str,"LOCK MODE (PAGE)");}
    break;

  case 1329:
#line 6524 "fgl.yacc"
    {strcpy(yyval.str,"LOCK MODE (ROW)");}
    break;

  case 1330:
#line 6528 "fgl.yacc"
    {
		sprintf(yyval.str,"MODIFY NEXT SIZE %d",atoi(yyvsp[0].str));
	}
    break;

  case 1331:
#line 6538 "fgl.yacc"
    {
		sprintf(yyval.str,"ADD CONSTRAINT %s%s",yyvsp[-1].sql_string,yyvsp[0].str);
	}
    break;

  case 1332:
#line 6541 "fgl.yacc"
    {
		sprintf(yyval.str,"ADD CONSTRAINT (%s)",yyvsp[-1].sql_string);
	}
    break;

  case 1333:
#line 6547 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-1].sql_string,yyvsp[0].str,0);
}
    break;

  case 1334:
#line 6549 "fgl.yacc"
    {
	yyval.sql_string=make_sql_string(yyvsp[-3].sql_string,",",yyvsp[-1].sql_string,yyvsp[0].str, 0);
}
    break;

  case 1335:
#line 6554 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1336:
#line 6555 "fgl.yacc"
    {sprintf(yyval.str," %s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1337:
#line 6560 "fgl.yacc"
    { sprintf(yyval.str,"DROP CONSTRAINT %s",yyvsp[0].str); }
    break;

  case 1338:
#line 6561 "fgl.yacc"
    {
		sprintf(yyval.str,"DROP CONSTRAINT (%s)",yyvsp[-1].str);
	}
    break;

  case 1339:
#line 6567 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1340:
#line 6568 "fgl.yacc"
    {sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1344:
#line 6595 "fgl.yacc"
    {sprintf(yyval.str,"%s %s /*FIXME */",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1350:
#line 6601 "fgl.yacc"
    { 
	print_set_conn(yyvsp[0].str);
}
    break;

  case 1351:
#line 6604 "fgl.yacc"
    {
	print_set_options("conn",yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 1352:
#line 6607 "fgl.yacc"
    {
	print_set_options("stmt",yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 1353:
#line 6613 "fgl.yacc"
    {strcpy(yyval.str,"\"default\"");}
    break;

  case 1355:
#line 6619 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1357:
#line 6630 "fgl.yacc"
    {
		print_sleep();
	}
    break;

  case 1358:
#line 6644 "fgl.yacc"
    {
		print_sql_commit(0);
		}
    break;

  case 1359:
#line 6653 "fgl.yacc"
    { insql=1;start_bind('i',0);}
    break;

  case 1360:
#line 6653 "fgl.yacc"
    {
	yyval.sql_string=make_sql_string(yyvsp[-4].str," ",yyvsp[-2].str," ",yyvsp[-1].str," ",yyvsp[0].sql_string,0);
}
    break;

  case 1361:
#line 6658 "fgl.yacc"
    {insql=1;}
    break;

  case 1362:
#line 6658 "fgl.yacc"
    {
insql=0;
	//printf("Value = %s\n",$<sql_string>4);
yyval.sql_string=make_sql_string(yyvsp[-4].str," (",yyvsp[-1].sql_string,")",0);}
    break;

  case 1363:
#line 6663 "fgl.yacc"
    {yyval.sql_string=yyvsp[0].sql_string;}
    break;

  case 1364:
#line 6666 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1365:
#line 6668 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1367:
#line 6675 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1368:
#line 6679 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	//printf(" 1. Value = %s\n",$<sql_string>$);
	}
    break;

  case 1369:
#line 6683 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",", yyvsp[0].sql_string,0);
	//printf(" 2. Value = %s\n",$<sql_string>$);
	}
    break;

  case 1370:
#line 6690 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1371:
#line 6693 "fgl.yacc"
    {
		yyval.sql_string=strdup("NULL");
	}
    break;

  case 1372:
#line 6700 "fgl.yacc"
    {
      print_fetch_1();
    }
    break;

  case 1373:
#line 6704 "fgl.yacc"
    {
      print_fetch_2();
      print_fetch_3(yyvsp[-1].str,yyvsp[0].str);
    }
    break;

  case 1374:
#line 6710 "fgl.yacc"
    {sprintf(yyval.str,"%s",yyvsp[0].str);doing_declare=1;}
    break;

  case 1375:
#line 6715 "fgl.yacc"
    {sprintf(yyval.str,"%s, %s",yyvsp[0].str,yyvsp[-1].str);
addmap("Fetch Cursor",yyvsp[0].str,curr_func,yylineno,infilename);
}
    break;

  case 1376:
#line 6719 "fgl.yacc"
    {sprintf(yyval.str,"%s, %d, 1",yyvsp[0].str,FETCH_RELATIVE);

addmap("Fetch Cursor",yyvsp[0].str,curr_func,yylineno,infilename);
}
    break;

  case 1377:
#line 6725 "fgl.yacc"
    {
A4GL_debug("no into\n");
strcpy(yyval.str,"0,0");
}
    break;

  case 1378:
#line 6728 "fgl.yacc"
    {
 A4GL_debug("FETCH INTO  ...");
	/* start_bind('i',0,-1); */
    start_bind('o',0);
}
    break;

  case 1379:
#line 6734 "fgl.yacc"
    {
	int no;
	no=get_bind_cnt('o');
	sprintf(yyval.str,"%d,obind",no);
}
    break;

  case 1380:
#line 6741 "fgl.yacc"
    {
A4GL_debug("no into\n");
strcpy(yyval.str,"0,0");
}
    break;

  case 1381:
#line 6745 "fgl.yacc"
    {
 A4GL_debug("FETCH INTO  ...");
	/* start_bind('i',0,-1); */
    start_bind('o',0);
}
    break;

  case 1382:
#line 6750 "fgl.yacc"
    {
/*
int ni;
ni=print_bind('i');
sprintf($<str>$,"%d,ibind",ni);
*/
}
    break;

  case 1383:
#line 6760 "fgl.yacc"
    {
		sprintf(yyval.str,"%d,1",FETCH_ABSOLUTE);}
    break;

  case 1384:
#line 6763 "fgl.yacc"
    {sprintf(yyval.str,"%d,-1",FETCH_ABSOLUTE);}
    break;

  case 1385:
#line 6765 "fgl.yacc"
    {sprintf(yyval.str,"%d,1",FETCH_RELATIVE);}
    break;

  case 1386:
#line 6767 "fgl.yacc"
    {sprintf(yyval.str,"%d,-1",FETCH_RELATIVE);}
    break;

  case 1387:
#line 6769 "fgl.yacc"
    {sprintf(yyval.str,"%d,-1",FETCH_RELATIVE);}
    break;

  case 1388:
#line 6771 "fgl.yacc"
    {sprintf(yyval.str,"%d,0",FETCH_RELATIVE);}
    break;

  case 1389:
#line 6773 "fgl.yacc"
    {sprintf(yyval.str,"%d,A4GL_pop_int()",FETCH_RELATIVE);}
    break;

  case 1390:
#line 6775 "fgl.yacc"
    {sprintf(yyval.str,"%d,A4GL_pop_int()",FETCH_ABSOLUTE);}
    break;

  case 1391:
#line 6781 "fgl.yacc"
    {
 
rm_quotes(yyvsp[0].str);
sprintf(yyval.str," %s %s %s %s ",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str
);}
    break;

  case 1392:
#line 6791 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].str," ",yyvsp[-1].str," ",yyvsp[0].sql_string,0);
		}
    break;

  case 1393:
#line 6798 "fgl.yacc"
    {sprintf(yyval.str,"%s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1395:
#line 6804 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1396:
#line 6807 "fgl.yacc"
    {sprintf(yyval.str,"%s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1399:
#line 6814 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1402:
#line 6819 "fgl.yacc"
    {
print_sql_commit(-1);
}
    break;

  case 1403:
#line 6824 "fgl.yacc"
    {
		print_sql_commit(1);
	}
    break;

  case 1404:
#line 6831 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1405:
#line 6832 "fgl.yacc"
    {
		strcpy(yyval.str,"EXCLUSIVE");
	}
    break;

  case 1406:
#line 6839 "fgl.yacc"
    {
if (strcmp(yyvsp[-1].str,"?")==0) {
	print_init_conn(0);
} else {
	print_init_conn(yyvsp[-1].str);
}
}
    break;

  case 1407:
#line 6850 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1408:
#line 6851 "fgl.yacc"
    {sprintf(yyval.str,"%s@%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1409:
#line 6852 "fgl.yacc"
    {strcpy(yyval.str, A4GL_strip_quotes (yyvsp[0].str));}
    break;

  case 1410:
#line 6855 "fgl.yacc"
    {insql=1;}
    break;

  case 1411:
#line 6855 "fgl.yacc"
    {
print_undo_use(yyvsp[-2].str);
insql=0;strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1412:
#line 6860 "fgl.yacc"
    {
		 A4GL_lex_printcomment("/*  schema */\n");
			print_exec_sql(yyvsp[0].sql_string);
			strcpy(yyval.str,"Schema");
	}
    break;

  case 1413:
#line 6865 "fgl.yacc"
    {
	 A4GL_lex_printcomment("/*  schema  2*/\n");
		print_exec_sql(yyvsp[0].sql_string);
		strcpy(yyval.str,"Schema Element");
	}
    break;

  case 1415:
#line 6871 "fgl.yacc"
    {
		print_exec_sql(yyvsp[0].str);
 	}
    break;

  case 1417:
#line 6875 "fgl.yacc"
    {
	 A4GL_lex_printcomment("/*  delete 1 */\n");
		print_exec_sql_bound(yyvsp[0].str);
		strcpy(yyval.str,"Delete where current...");
	}
    break;

  case 1418:
#line 6880 "fgl.yacc"
    {
	 A4GL_lex_printcomment("/*  delete 2 */\n");
		print_exec_sql_bound(yyvsp[0].sql_string);
		strcpy(yyval.str,"Delete where ...");
	}
    break;

  case 1419:
#line 6885 "fgl.yacc"
    {
		strcpy(yyval.str,"Fetch");
	 A4GL_lex_printcomment("/*  fetch */\n");
	}
    break;

  case 1420:
#line 6889 "fgl.yacc"
    {
	 A4GL_lex_printcomment("/*  insert */\n");
		print_exec_sql_bound(yyvsp[0].sql_string);
		strcpy(yyval.str,"insert");
	}
    break;

  case 1422:
#line 6895 "fgl.yacc"
    {
		print_do_select(yyvsp[0].sql_string);
		strcpy(yyval.str,"select");
	}
    break;

  case 1423:
#line 6899 "fgl.yacc"
    {
		print_exec_sql_bound(yyvsp[0].sql_string);
		strcpy(yyval.str,"update");
	}
    break;

  case 1424:
#line 6906 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s %s %s %s",yyvsp[-6].str,yyvsp[-5].str,yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1425:
#line 6907 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s %s %s",yyvsp[-5].str,yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1426:
#line 6908 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s ",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1427:
#line 6909 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s ",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1431:
#line 6919 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1432:
#line 6920 "fgl.yacc"
    {sprintf(yyval.str," %s ",yyvsp[0].str);}
    break;

  case 1433:
#line 6921 "fgl.yacc"
    {sprintf(yyval.str," %s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1434:
#line 6925 "fgl.yacc"
    {sprintf(yyval.str," %s ",yyvsp[0].str);}
    break;

  case 1435:
#line 6926 "fgl.yacc"
    {sprintf(yyval.str," %s ",yyvsp[0].str);}
    break;

  case 1438:
#line 6933 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1439:
#line 6936 "fgl.yacc"
    {sprintf(yyval.str," %s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1442:
#line 6939 "fgl.yacc"
    {sprintf(yyval.str," %s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1445:
#line 6944 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1446:
#line 6946 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1448:
#line 6952 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1450:
#line 6958 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1453:
#line 6968 "fgl.yacc"
    {
yyval.sql_string=make_sql_string(yyvsp[-5].str," ",yyvsp[-4].str," ",yyvsp[-3].str," ",yyvsp[-2].str," ",yyvsp[-1].sql_string," ",yyvsp[0].str,0);
}
    break;

  case 1454:
#line 6973 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1455:
#line 6975 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1457:
#line 6981 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1458:
#line 6984 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1460:
#line 6990 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("CHECK(",yyvsp[-1].sql_string,")",0);
	}
    break;

  case 1461:
#line 6998 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s %s",yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1462:
#line 7003 "fgl.yacc"
    {sprintf(yyval.str," %s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1465:
#line 7013 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1467:
#line 7019 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1468:
#line 7024 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1469:
#line 7025 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1470:
#line 7027 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1472:
#line 7033 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1473:
#line 7038 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1474:
#line 7041 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1475:
#line 7044 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1476:
#line 7051 "fgl.yacc"
    {sprintf(yyval.str," %s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1477:
#line 7052 "fgl.yacc"
    {sprintf(yyval.str," DEFAULT USER");}
    break;

  case 1478:
#line 7053 "fgl.yacc"
    {sprintf(yyval.str," DEFAULT TODAY");}
    break;

  case 1479:
#line 7055 "fgl.yacc"
    {sprintf(yyval.str," %s",yyvsp[0].str);}
    break;

  case 1480:
#line 7068 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-3].str," ",yyvsp[-2].str," ",yyvsp[-1].str," ",yyvsp[0].sql_string,0);
	}
    break;

  case 1481:
#line 7073 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1483:
#line 7077 "fgl.yacc"
    {
		yyval.sql_string=strdup("");
	}
    break;

  case 1484:
#line 7079 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1485:
#line 7086 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1486:
#line 7089 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-1].sql_string,yyvsp[0].sql_string,0);
	}
    break;

  case 1487:
#line 7095 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-1].sql_string,yyvsp[0].str,0);
	}
    break;

  case 1488:
#line 7103 "fgl.yacc"
    {
		sprintf(yyval.str," %s ",yyvsp[0].str);
		yyval.sql_string=strdup(yyval.str);
	}
    break;

  case 1489:
#line 7107 "fgl.yacc"
    {
		sprintf(yyval.str," %s ",yyvsp[0].str);
		yyval.sql_string=strdup(yyval.str);
	}
    break;

  case 1490:
#line 7111 "fgl.yacc"
    {
		sprintf(yyval.str," %s ",yyvsp[0].str);
		yyval.sql_string=strdup(yyval.str);
	}
    break;

  case 1491:
#line 7115 "fgl.yacc"
    {
		sprintf(yyval.str," %s ",yyvsp[0].str);
		yyval.sql_string=strdup(yyval.str);
	}
    break;

  case 1492:
#line 7119 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1493:
#line 7122 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-3].str," ",yyvsp[-2].str," ",yyvsp[-1].sql_string," ",yyvsp[0].str,0);
	}
    break;

  case 1494:
#line 7125 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(" PRIMARY KEY ",0);
	}
    break;

  case 1495:
#line 7133 "fgl.yacc"
    {
yyval.sql_string=make_sql_string(yyvsp[-2].str," ",yyvsp[-1].str," ",yyvsp[0].str,0);
}
    break;

  case 1496:
#line 7140 "fgl.yacc"
    {sprintf(yyval.str," %s",yyvsp[0].str);}
    break;

  case 1499:
#line 7149 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-1].sql_string," ",yyvsp[0].sql_string,0);
	}
    break;

  case 1500:
#line 7155 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1501:
#line 7158 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1502:
#line 7169 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-1].str," ",yyvsp[0].sql_string,0);
	}
    break;

  case 1503:
#line 7176 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("GROUP BY ",yyvsp[0].sql_string,0);
	}
    break;

  case 1504:
#line 7182 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1505:
#line 7185 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",",yyvsp[0].sql_string,0);
	}
    break;

  case 1506:
#line 7192 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("WHERE ",yyvsp[0].sql_string,0);
	}
    break;

  case 1507:
#line 7199 "fgl.yacc"
    {
		sprintf(yyval.str,"%s %s",yyvsp[-1].str,yyvsp[0].str);
	}
    break;

  case 1509:
#line 7206 "fgl.yacc"
    {
		sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);
	}
    break;

  case 1510:
#line 7212 "fgl.yacc"
    {sprintf(yyval.str," %s ", yyvsp[0].str);}
    break;

  case 1511:
#line 7213 "fgl.yacc"
    {sprintf(yyval.str," %s %s ",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1512:
#line 7214 "fgl.yacc"
    {sprintf(yyval.str," %s (%s) ",yyvsp[-3].str,yyvsp[-1].str);}
    break;

  case 1514:
#line 7218 "fgl.yacc"
    {sprintf(yyval.str,"%s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1516:
#line 7223 "fgl.yacc"
    { sprintf(yyval.str," %s,%s ",yyvsp[-2].str,yyvsp[0].str);  }
    break;

  case 1517:
#line 7230 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-3].str," ",yyvsp[-2].sql_string," ",yyvsp[-1].sql_string," ",yyvsp[0].sql_string,0);
	}
    break;

  case 1518:
#line 7235 "fgl.yacc"
    { yyval.sql_string=strdup("");}
    break;

  case 1519:
#line 7236 "fgl.yacc"
    {yyval.sql_string=yyvsp[0].sql_string;}
    break;

  case 1520:
#line 7239 "fgl.yacc"
    {
	yyval.sql_string=strdup("");
}
    break;

  case 1521:
#line 7242 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
}
    break;

  case 1522:
#line 7247 "fgl.yacc"
    {yyval.sql_string=strdup("");}
    break;

  case 1523:
#line 7248 "fgl.yacc"
    {yyval.sql_string=yyvsp[0].sql_string;}
    break;

  case 1524:
#line 7253 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1525:
#line 7256 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string," OR ",yyvsp[0].sql_string,0);
	}
    break;

  case 1526:
#line 7262 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1527:
#line 7265 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string," AND ",yyvsp[0].sql_string,0);
	}
    break;

  case 1528:
#line 7271 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1529:
#line 7274 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-1].str," ",yyvsp[0].sql_string,0);
	}
    break;

  case 1530:
#line 7280 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1531:
#line 7283 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].str,yyvsp[-1].sql_string,yyvsp[0].str,0);
	}
    break;

  case 1532:
#line 7290 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-1].str," ",yyvsp[0].sql_string,0);}
    break;

  case 1533:
#line 7291 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-1].str," ",yyvsp[0].sql_string,0);}
    break;

  case 1534:
#line 7320 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1535:
#line 7322 "fgl.yacc"
    {sprintf(yyval.str," %s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1536:
#line 7326 "fgl.yacc"
    {yyval.sql_string=yyvsp[0].sql_string;}
    break;

  case 1538:
#line 7339 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-4].sql_string," IN (",yyvsp[-1].str,")",0);
	}
    break;

  case 1539:
#line 7342 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string," ",yyvsp[-1].str," ",yyvsp[0].sql_string,0);
	}
    break;

  case 1540:
#line 7345 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-4].sql_string," NOT IN (",yyvsp[-1].str,")",0);
	}
    break;

  case 1541:
#line 7348 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string," ",yyvsp[-1].str," ",yyvsp[0].sql_string,0);
	}
    break;

  case 1543:
#line 7356 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1544:
#line 7359 "fgl.yacc"
    {
		strcpy(yyval.str,yyvsp[0].sql_string);
	}
    break;

  case 1546:
#line 7365 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1548:
#line 7371 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string," ",yyvsp[-1].str," IS NULL",0);
	}
    break;

  case 1549:
#line 7374 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string," ",yyvsp[-1].str," IS NOT NULL",0);
	}
    break;

  case 1550:
#line 7377 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string," ",yyvsp[-1].str," ",yyvsp[0].sql_string,0);
	}
    break;

  case 1551:
#line 7380 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-5].sql_string," ",yyvsp[-4].str," BETWEEN ",yyvsp[-2].sql_string," AND ",yyvsp[0].sql_string,0);
	}
    break;

  case 1552:
#line 7383 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-3].sql_string," ",yyvsp[-2].str," ",yyvsp[-1].sql_string,yyvsp[0].str,0);
	}
    break;

  case 1553:
#line 7386 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-3].sql_string," ",yyvsp[-2].str," ",yyvsp[-1].sql_string,yyvsp[0].str,0);
	}
    break;

  case 1554:
#line 7389 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-3].sql_string," ",yyvsp[-2].str," ",yyvsp[-1].sql_string,yyvsp[0].str,0);
	}
    break;

  case 1555:
#line 7392 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-3].sql_string," ",yyvsp[-2].str," ",yyvsp[-1].sql_string,yyvsp[0].str,0);
	}
    break;

  case 1556:
#line 7397 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-4].sql_string," ",yyvsp[-3].str," MATCHES ",yyvsp[-1].sql_string,yyvsp[0].str,0);
	}
    break;

  case 1558:
#line 7404 "fgl.yacc"
    {strcpy(yyval.str,"!=");}
    break;

  case 1564:
#line 7412 "fgl.yacc"
    {strcpy(yyval.str,"<=");}
    break;

  case 1565:
#line 7413 "fgl.yacc"
    {strcpy(yyval.str,">=");}
    break;

  case 1566:
#line 7418 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1567:
#line 7421 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1568:
#line 7425 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1569:
#line 7431 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1570:
#line 7432 "fgl.yacc"
    {strcpy(yyval.str," ALL ");}
    break;

  case 1571:
#line 7433 "fgl.yacc"
    {strcpy(yyval.str," DISTINCT ");}
    break;

  case 1572:
#line 7434 "fgl.yacc"
    {
		ansi_violation("Use DISTINCT not UNIQUE",0);
		strcpy(yyval.str," DISTINCT ");
	}
    break;

  case 1577:
#line 7454 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1579:
#line 7458 "fgl.yacc"
    {strcpy(yyval.str,"SERIAL");}
    break;

  case 1580:
#line 7459 "fgl.yacc"
    {sprintf(yyval.str,"SERIAL(%s)",yyvsp[-1].str);}
    break;

  case 1582:
#line 7462 "fgl.yacc"
    {sprintf(yyval.str," DECIMAL(%s%s)",yyvsp[-2].str,yyvsp[-1].str);}
    break;

  case 1583:
#line 7464 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s %s",yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1591:
#line 7473 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1592:
#line 7475 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s %s %s",yyvsp[-5].str,yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1593:
#line 7477 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1595:
#line 7480 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1597:
#line 7483 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s %s %s %s",yyvsp[-6].str,yyvsp[-5].str,yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1601:
#line 7488 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1602:
#line 7490 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s %s %s",yyvsp[-5].str,yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1603:
#line 7493 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1604:
#line 7494 "fgl.yacc"
    {
		sprintf(yyval.str,",%s",yyvsp[0].str);
}
    break;

  case 1605:
#line 7501 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1609:
#line 7506 "fgl.yacc"
    {sprintf(yyval.str," %s",yyvsp[0].str);}
    break;

  case 1613:
#line 7522 "fgl.yacc"
    { 
			if (A4GL_escape_quote_owner()) {
				sprintf(yyval.str,"\\\"%s\\\"%s%s", A4GL_strip_quotes (yyvsp[-2].str),yyvsp[-1].str,yyvsp[0].str); addmap("Use Table",yyval.str,curr_func,yylineno,infilename); 
			} else {
				sprintf(yyval.str,"\"%s\"%s%s", A4GL_strip_quotes (yyvsp[-2].str),yyvsp[-1].str,yyvsp[0].str); addmap("Use Table",yyval.str,curr_func,yylineno,infilename); 
			}
	}
    break;

  case 1614:
#line 7529 "fgl.yacc"
    {
		sprintf(yyval.str," %s", A4GL_strip_quotes (yyvsp[0].str));
		addmap("Use Table",yyval.str,curr_func,yylineno,infilename);
	}
    break;

  case 1615:
#line 7533 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str); addmap("Use Table",yyvsp[0].str,curr_func,yylineno,infilename); }
    break;

  case 1616:
#line 7534 "fgl.yacc"
    { sprintf(yyval.str," %s%s%s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str); addmap("Use Table",yyval.str,curr_func,yylineno,infilename); }
    break;

  case 1617:
#line 7535 "fgl.yacc"
    { 
                        if (A4GL_escape_quote_owner()) {
				sprintf(yyval.str," %s:\\\"%s\\\".%s",yyvsp[-4].str,A4GL_strip_quotes(yyvsp[-2].str),yyvsp[0].str); addmap("Use Table",yyval.str,curr_func,yylineno,infilename); 
                        } else {
				sprintf(yyval.str," %s:%s.%s",yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str); addmap("Use Table",yyval.str,curr_func,yylineno,infilename); 
                        }
	}
    break;

  case 1618:
#line 7543 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[-2].str); addmap("Use Table",yyvsp[-2].str,curr_func,yylineno,infilename); }
    break;

  case 1619:
#line 7544 "fgl.yacc"
    { sprintf(yyval.str," %s@%s%s%s",yyvsp[-4].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str); addmap("Use Table",yyval.str,curr_func,yylineno,infilename); }
    break;

  case 1620:
#line 7545 "fgl.yacc"
    { 
                        if (A4GL_escape_quote_owner()) {
				sprintf(yyval.str," %s@%s:\\\"%s\\\".%s",yyvsp[-6].str,yyvsp[-4].str,A4GL_strip_quotes(yyvsp[-2].str),yyvsp[0].str); addmap("Use Table",yyval.str,curr_func,yylineno,infilename); 
                        } else {
				sprintf(yyval.str," %s@%s:%s.%s",yyvsp[-6].str,yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str); addmap("Use Table",yyval.str,curr_func,yylineno,infilename); 
                        }
	}
    break;

  case 1621:
#line 7556 "fgl.yacc"
    { 
			if (A4GL_escape_quote_owner()) {
				sprintf(yyval.str,"\\\"%s\\\"%s%s", A4GL_strip_quotes (yyvsp[-2].str),yyvsp[-1].str,yyvsp[0].str); addmap("Use Index",yyval.str,curr_func,yylineno,infilename); 
			} else {
				sprintf(yyval.str,"\"%s\"%s%s", A4GL_strip_quotes (yyvsp[-2].str),yyvsp[-1].str,yyvsp[0].str); addmap("Use Index",yyval.str,curr_func,yylineno,infilename); 
			}
	}
    break;

  case 1622:
#line 7563 "fgl.yacc"
    {
		sprintf(yyval.str," %s", A4GL_strip_quotes (yyvsp[0].str));
		addmap("Use Index",yyval.str,curr_func,yylineno,infilename);
	}
    break;

  case 1623:
#line 7568 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str); addmap("Use Index",yyvsp[0].str,curr_func,yylineno,infilename); }
    break;

  case 1624:
#line 7569 "fgl.yacc"
    { sprintf(yyval.str," %s%s%s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str); addmap("Use Index",yyval.str,curr_func,yylineno,infilename); }
    break;

  case 1625:
#line 7570 "fgl.yacc"
    { 
                        if (A4GL_escape_quote_owner()) {
				sprintf(yyval.str," %s:\\\"%s\\\".%s",yyvsp[-4].str,A4GL_strip_quotes(yyvsp[-2].str),yyvsp[0].str); addmap("Use Index",yyval.str,curr_func,yylineno,infilename); 
                        } else {
				sprintf(yyval.str," %s:%s.%s",yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str); addmap("Use Index",yyval.str,curr_func,yylineno,infilename); 
                        }
	}
    break;

  case 1626:
#line 7578 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[-2].str); addmap("Use Index",yyvsp[-2].str,curr_func,yylineno,infilename); }
    break;

  case 1627:
#line 7579 "fgl.yacc"
    { sprintf(yyval.str," %s@%s%s%s",yyvsp[-4].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str); addmap("Use Index",yyval.str,curr_func,yylineno,infilename); }
    break;

  case 1628:
#line 7580 "fgl.yacc"
    { 
                        if (A4GL_escape_quote_owner()) {
				sprintf(yyval.str," %s@%s:\\\"%s\\\".%s",yyvsp[-6].str,yyvsp[-4].str,A4GL_strip_quotes(yyvsp[-2].str),yyvsp[0].str); addmap("Use Index",yyval.str,curr_func,yylineno,infilename); 
                        } else {
				sprintf(yyval.str," %s@%s:%s.%s",yyvsp[-6].str,yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str); addmap("Use Index",yyval.str,curr_func,yylineno,infilename); 
                        }
	}
    break;

  case 1630:
#line 7606 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1631:
#line 7607 "fgl.yacc"
    {sprintf(yyval.str,"[%s]",yyvsp[-1].str);}
    break;

  case 1632:
#line 7608 "fgl.yacc"
    {sprintf(yyval.str,"[%s,%s]",yyvsp[-3].str,yyvsp[-1].str);}
    break;

  case 1633:
#line 7612 "fgl.yacc"
    {
		strcpy(yyval.str,yyvsp[0].str);
	}
    break;

  case 1634:
#line 7615 "fgl.yacc"
    {
		strcpy(yyval.str,yyvsp[0].str);
	}
    break;

  case 1635:
#line 7621 "fgl.yacc"
    { 
addmap("Use Column",yyvsp[-1].str,curr_func,yylineno,infilename);
sprintf(yyval.str,"%s%s",yyvsp[-1].str,yyvsp[0].str);
}
    break;

  case 1636:
#line 7626 "fgl.yacc"
    {
sprintf(yyval.str,"%s.%s%s",yyvsp[-3].str,yyvsp[-1].str,yyvsp[0].str);
addmap("Use Column",yyval.str,curr_func,yylineno,infilename);
}
    break;

  case 1637:
#line 7631 "fgl.yacc"
    {
sprintf(yyval.str,"%s.%s",yyvsp[-2].str,yyvsp[0].str);
addmap("Use Column",yyval.str,curr_func,yylineno,infilename);
}
    break;

  case 1639:
#line 7642 "fgl.yacc"
    {
	strcpy(yyval.str,convstrsql(yyvsp[0].str));
 A4GL_debug("Set $<str>$ to %s\n",yyval.str);
}
    break;

  case 1643:
#line 7660 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1644:
#line 7663 "fgl.yacc"
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

  case 1645:
#line 7676 "fgl.yacc"
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

  case 1646:
#line 7691 "fgl.yacc"
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

  case 1647:
#line 7703 "fgl.yacc"
    {strcpy(yyval.str,"1,10");}
    break;

  case 1648:
#line 7705 "fgl.yacc"
    {sprintf(yyval.str," %s ,%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1649:
#line 7708 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 1650:
#line 7708 "fgl.yacc"
    {strcpy(yyval.str,"2");}
    break;

  case 1651:
#line 7708 "fgl.yacc"
    {strcpy(yyval.str,"3");}
    break;

  case 1652:
#line 7708 "fgl.yacc"
    {strcpy(yyval.str,"4");}
    break;

  case 1653:
#line 7708 "fgl.yacc"
    {strcpy(yyval.str,"5");}
    break;

  case 1654:
#line 7708 "fgl.yacc"
    {strcpy(yyval.str,"6");}
    break;

  case 1655:
#line 7709 "fgl.yacc"
    {
sprintf(yyval.str,"%d",6+2);
}
    break;

  case 1656:
#line 7712 "fgl.yacc"
    {
sprintf(yyval.str,"%d",atoi(yyvsp[-1].str)+6);
}
    break;

  case 1657:
#line 7717 "fgl.yacc"
    {strcpy(yyval.str,"4");}
    break;

  case 1658:
#line 7717 "fgl.yacc"
    {strcpy(yyval.str,"7");}
    break;

  case 1659:
#line 7717 "fgl.yacc"
    {strcpy(yyval.str,"10");}
    break;

  case 1660:
#line 7717 "fgl.yacc"
    {strcpy(yyval.str,"13");}
    break;

  case 1661:
#line 7717 "fgl.yacc"
    {strcpy(yyval.str,"16");}
    break;

  case 1662:
#line 7717 "fgl.yacc"
    {strcpy(yyval.str,"19");}
    break;

  case 1663:
#line 7719 "fgl.yacc"
    {
strcpy(yyval.str,"25");
}
    break;

  case 1664:
#line 7722 "fgl.yacc"
    {
strcpy(yyval.str,"25");
}
    break;

  case 1679:
#line 7729 "fgl.yacc"
    {sprintf(yyval.str,"FRACTION(%s)",yyvsp[-1].str);}
    break;

  case 1680:
#line 7732 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1681:
#line 7733 "fgl.yacc"
    {sprintf(yyval.str,"%s@%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1682:
#line 7734 "fgl.yacc"
    {strcpy(yyval.str, A4GL_strip_quotes (yyvsp[0].str));}
    break;

  case 1683:
#line 7738 "fgl.yacc"
    {
	print_flush_cursor(yyvsp[0].str);
		addmap("Flush Cursor",yyvsp[0].str,curr_func,yylineno,infilename);
print_undo_use(yyvsp[-2].str);
		}
    break;

  case 1684:
#line 7746 "fgl.yacc"
    {insql=0;chk4var=0;}
    break;

  case 1685:
#line 7746 "fgl.yacc"
    {
		print_declare("",yyvsp[-1].sql_string,yyvsp[-4].str,0,0);
		addmap("Declare Cursor",yyvsp[-4].str,curr_func,yylineno,infilename);
		print_undo_use(yyvsp[-6].str);
		doing_declare=0;
	}
    break;

  case 1686:
#line 7752 "fgl.yacc"
    {insql=0;chk4var=0;}
    break;

  case 1687:
#line 7752 "fgl.yacc"
    {
		print_declare("",yyvsp[-1].sql_string,yyvsp[-5].str,2,0); 
		addmap("Declare Cursor",yyvsp[-5].str,curr_func,yylineno,infilename);
		print_undo_use(yyvsp[-7].str);
		doing_declare=0;
	}
    break;

  case 1688:
#line 7759 "fgl.yacc"
    {insql=0;chk4var=0;}
    break;

  case 1689:
#line 7759 "fgl.yacc"
    {
		print_declare("",yyvsp[-1].sql_string,yyvsp[-3].str,0,1); 
		addmap("Declare Cursor",yyvsp[-3].str,curr_func,yylineno,infilename);
		print_undo_use(yyvsp[-5].str);
		doing_declare=0;
	}
    break;

  case 1690:
#line 7765 "fgl.yacc"
    {insql=0;chk4var=0;}
    break;

  case 1691:
#line 7765 "fgl.yacc"
    {
		print_declare("",yyvsp[-1].sql_string,yyvsp[-5].str,2,1); 
		addmap("Declare Cursor",yyvsp[-5].str,curr_func,yylineno,infilename);
		print_undo_use(yyvsp[-7].str);
		doing_declare=0;
	}
    break;

  case 1692:
#line 7773 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1693:
#line 7774 "fgl.yacc"
    {strcpy(yyval.str," FOR UPDATE");}
    break;

  case 1694:
#line 7775 "fgl.yacc"
    {sprintf(yyval.str," FOR UPDATE OF %s",yyvsp[0].str);}
    break;

  case 1695:
#line 7778 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1696:
#line 7778 "fgl.yacc"
    {sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1698:
#line 7782 "fgl.yacc"
    {sprintf(yyval.str,"%s.%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1699:
#line 7783 "fgl.yacc"
    {
			if (A4GL_escape_quote_owner()) {
				sprintf(yyval.str,"\\\"%s\\\".%s.%s", A4GL_strip_quotes (yyvsp[-4].str),yyvsp[-2].str,yyvsp[0].str);
			} else {
				sprintf(yyval.str,"\"%s\".%s.%s", A4GL_strip_quotes (yyvsp[-4].str),yyvsp[-2].str,yyvsp[0].str);
			}
	}
    break;

  case 1700:
#line 7794 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1701:
#line 7797 "fgl.yacc"
    { 
		yyval.sql_string=make_sql_string(print_curr_spec(1,yyvsp[0].sql_string),0);
	}
    break;

  case 1702:
#line 7803 "fgl.yacc"
    {
		start_bind('i',0);
		start_bind('o',0);
		yyval.sql_string=make_sql_string(print_curr_spec(2,yyvsp[0].str) ,0);
	}
    break;

  case 1703:
#line 7808 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1704:
#line 7816 "fgl.yacc"
    {
	yyval.sql_string=yyvsp[0].sql_string;
	if (strstr(yyvsp[0].str,"FOR UPDATE")) {
		printf("Warning SELECT ... FOR UPDATE when not declaring a cursor currently has no locking effect\n");
	}
}
    break;

  case 1705:
#line 7828 "fgl.yacc"
    { start_bind('i',0); }
    break;

  case 1706:
#line 7829 "fgl.yacc"
    {A4GL_debug("Got select list...\n");}
    break;

  case 1707:
#line 7832 "fgl.yacc"
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

  case 1708:
#line 7847 "fgl.yacc"
    {
		/*$<sql_string>$=make_sql_string("A4GL_push_char(\"", $<str>1, " ",$<str>2," ", $<sql_string>3, " ",$<sql_string>4, " ",$<sql_string>5, "\");",0); */
		yyval.sql_string=make_sql_string(yyvsp[-4].str, " ",yyvsp[-3].str," ", yyvsp[-2].sql_string, " ",yyvsp[-1].sql_string, " ",yyvsp[0].sql_string,0);
	free(yyvsp[-2].sql_string);
	free(yyvsp[-1].sql_string);
	free(yyvsp[0].sql_string);
}
    break;

  case 1709:
#line 7858 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	 }
    break;

  case 1710:
#line 7861 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1711:
#line 7869 "fgl.yacc"
    {
	yyval.sql_string=make_sql_string(yyvsp[-5].str, " ",yyvsp[-4].str," ",yyvsp[-3].sql_string," ", yyvsp[-2].sql_string," ", yyvsp[-1].sql_string, " ",yyvsp[0].sql_string,0);
	free(yyvsp[-3].sql_string);
	free(yyvsp[-1].sql_string);
	free(yyvsp[0].sql_string);
}
    break;

  case 1712:
#line 7878 "fgl.yacc"
    {
		yyval.sql_string=strdup("");
		}
    break;

  case 1713:
#line 7881 "fgl.yacc"
    {
       A4GL_lex_printcomment("/* UNION */");
	yyval.sql_string=make_sql_string(yyvsp[-2].str," ",yyvsp[-1].str," ",yyvsp[0].sql_string,0);
       }
    break;

  case 1714:
#line 7885 "fgl.yacc"
    {
	yyval.sql_string=strdup(yyvsp[0].str);
}
    break;

  case 1715:
#line 7888 "fgl.yacc"
    { yyval.sql_string=make_sql_string(yyvsp[-2].str," ",yyvsp[-1].str," ",yyvsp[0].str,0); }
    break;

  case 1716:
#line 7889 "fgl.yacc"
    { 
	yyval.sql_string=make_sql_string(yyvsp[-3].str," ",yyvsp[-2].str," ",yyvsp[-1].str," ",yyvsp[0].str,0);
}
    break;

  case 1718:
#line 7898 "fgl.yacc"
    { start_bind('o',0);yyval.sql_string=make_sql_string("",0); }
    break;

  case 1719:
#line 7899 "fgl.yacc"
    { 
		yyval.sql_string=make_sql_string(A4GL_get_into_part(doing_declare,get_bind_cnt('o')),0 ); 

	}
    break;

  case 1720:
#line 7908 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-3].str," ",yyvsp[-2].str," ", yyvsp[-1].sql_string," ",yyvsp[0].sql_string,0);
		free(yyvsp[-1].sql_string);
		//free($<sql_string>4);

	}
    break;

  case 1721:
#line 7917 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("(",yyvsp[-4].str," ",yyvsp[-3].str," ",yyvsp[-2].sql_string," ",yyvsp[-1].sql_string,")",0);
	}
    break;

  case 1722:
#line 7922 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1723:
#line 7923 "fgl.yacc"
    {strcpy(yyval.str,"ALL ");}
    break;

  case 1724:
#line 7924 "fgl.yacc"
    {strcpy(yyval.str," DISTINCT ");}
    break;

  case 1725:
#line 7925 "fgl.yacc"
    {strcpy(yyval.str," DISTINCT ");
		ansi_violation("Use DISTINCT not UNIQUE",0);
		strcpy(yyval.str," DISTINCT ");
}
    break;

  case 1726:
#line 7932 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1727:
#line 7935 "fgl.yacc"
    { 
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",",yyvsp[0].sql_string,0);
	}
    break;

  case 1728:
#line 7941 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1729:
#line 7944 "fgl.yacc"
    {
		if (A4GL_isyes(acl_getenv("A4GL_USE_ALIAS_AS"))) {
			yyval.sql_string=make_sql_string(yyvsp[-1].sql_string," AS ",yyvsp[0].str,0);
		} else {
			yyval.sql_string=make_sql_string(yyvsp[-1].sql_string," ",yyvsp[0].str,0);
		}
	}
    break;

  case 1730:
#line 7951 "fgl.yacc"
    {
		if (A4GL_isyes(acl_getenv("A4GL_USE_ALIAS_AS"))) {
			yyval.sql_string=make_sql_string(yyvsp[-2].sql_string," AS ",yyvsp[0].str,0);
		} else {
			yyval.sql_string=make_sql_string(yyvsp[-2].sql_string," ",yyvsp[0].str,0);
		}
	}
    break;

  case 1731:
#line 7963 "fgl.yacc"
    {
	yyval.sql_string=yyvsp[0].sql_string;
}
    break;

  case 1732:
#line 7972 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1733:
#line 7975 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("-",yyvsp[0].sql_string,0);
	}
    break;

  case 1734:
#line 7978 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("+",yyvsp[0].sql_string,0);
	}
    break;

  case 1735:
#line 7984 "fgl.yacc"
    {
			if (strlen(current_upd_table)) {
				push_gen(UPDVAL,yyvsp[0].sql_string);
			}
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1736:
#line 7990 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1737:
#line 7993 "fgl.yacc"
    { yyval.sql_string=yyvsp[0].sql_string; }
    break;

  case 1738:
#line 7994 "fgl.yacc"
    { yyval.sql_string=make_sql_string("ALL ",yyvsp[0].sql_string,0); }
    break;

  case 1739:
#line 7995 "fgl.yacc"
    { yyval.sql_string=make_sql_string("ANY ",yyvsp[0].sql_string,0); }
    break;

  case 1740:
#line 7996 "fgl.yacc"
    { yyval.sql_string=make_sql_string("SOME ",yyvsp[0].sql_string,0); }
    break;

  case 1741:
#line 7997 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1742:
#line 8000 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].str,".",yyvsp[0].str,0);
	}
    break;

  case 1743:
#line 8007 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,"/",yyvsp[0].sql_string,0);}
    break;

  case 1744:
#line 8009 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-1].sql_string," ",yyvsp[0].str,0);}
    break;

  case 1745:
#line 8011 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,"*",yyvsp[0].sql_string,0);}
    break;

  case 1746:
#line 8013 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,"+",yyvsp[0].sql_string,0);}
    break;

  case 1747:
#line 8015 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,"-",yyvsp[0].sql_string,0);}
    break;

  case 1748:
#line 8016 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[0].str,0);}
    break;

  case 1749:
#line 8017 "fgl.yacc"
    {yyval.sql_string=make_sql_string("1",0);}
    break;

  case 1750:
#line 8018 "fgl.yacc"
    {yyval.sql_string=make_sql_string("0",0);}
    break;

  case 1751:
#line 8019 "fgl.yacc"
    {yyval.sql_string=make_sql_string("USER",0);}
    break;

  case 1752:
#line 8020 "fgl.yacc"
    {yyval.sql_string=make_sql_string("*",0);}
    break;

  case 1753:
#line 8021 "fgl.yacc"
    {yyval.sql_string=make_sql_string("COUNT(*)",0);}
    break;

  case 1754:
#line 8023 "fgl.yacc"
    {yyval.sql_string=make_sql_string("AVG(",yyvsp[-2].str,yyvsp[-1].sql_string,")",0);}
    break;

  case 1755:
#line 8025 "fgl.yacc"
    {yyval.sql_string=make_sql_string("MAX(",yyvsp[-2].str,yyvsp[-1].sql_string,")",0);}
    break;

  case 1756:
#line 8027 "fgl.yacc"
    {yyval.sql_string=make_sql_string("MIN(",yyvsp[-2].str,yyvsp[-1].sql_string,")",0);}
    break;

  case 1757:
#line 8029 "fgl.yacc"
    {yyval.sql_string=make_sql_string("SUM(",yyvsp[-2].str,yyvsp[-1].sql_string,")",0);}
    break;

  case 1758:
#line 8031 "fgl.yacc"
    {yyval.sql_string=make_sql_string("COUNT(",yyvsp[-2].str,yyvsp[-1].sql_string,")",0);}
    break;

  case 1759:
#line 8033 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-3].str,"(",yyvsp[-1].sql_string,")",0);}
    break;

  case 1760:
#line 8035 "fgl.yacc"
    {yyval.sql_string=make_sql_string("DATE(",yyvsp[-1].sql_string,")",0);}
    break;

  case 1761:
#line 8036 "fgl.yacc"
    {yyval.sql_string=make_sql_string("(",yyvsp[-1].sql_string,")",0);}
    break;

  case 1762:
#line 8038 "fgl.yacc"
    {yyval.sql_string=make_sql_string("EXTEND(",yyvsp[-1].sql_string,")",0);}
    break;

  case 1763:
#line 8039 "fgl.yacc"
    { yyval.sql_string=make_sql_string(yyvsp[0].str,0);}
    break;

  case 1764:
#line 8040 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[0].str,0);}
    break;

  case 1765:
#line 8046 "fgl.yacc"
    {yyval.sql_string=yyvsp[0].sql_string;}
    break;

  case 1766:
#line 8047 "fgl.yacc"
    {
	yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",",yyvsp[0].sql_string,0);
}
    break;

  case 1768:
#line 8057 "fgl.yacc"
    {
print_unload(yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].sql_string);
print_undo_use(yyvsp[-4].str);
}
    break;

  case 1769:
#line 8065 "fgl.yacc"
    {
print_load(yyvsp[-4].str,yyvsp[-3].str,yyvsp[-1].str,yyvsp[0].str);
print_undo_use(yyvsp[-6].str);
}
    break;

  case 1770:
#line 8069 "fgl.yacc"
    {
print_load_str(yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);
print_undo_use(yyvsp[-4].str);
}
    break;

  case 1771:
#line 8076 "fgl.yacc"
    {strcpy(yyval.str,"\"|\"");}
    break;

  case 1772:
#line 8076 "fgl.yacc"
    {
strcpy(yyval.str,yyvsp[0].str);
}
    break;

  case 1774:
#line 8080 "fgl.yacc"
    {
		if ((scan_variable(yyvsp[0].str)&15)!=0) {a4gl_yyerror("Variable must be of type charr..");YYERROR;}
}
    break;

  case 1775:
#line 8085 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 1776:
#line 8085 "fgl.yacc"
    {
sprintf(yyval.str,"%s,0",yyvsp[-1].str);
}
    break;

  case 1778:
#line 8089 "fgl.yacc"
    {
    sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 1779:
#line 8093 "fgl.yacc"
    {
     sprintf(yyval.str,"\"%s\"",yyvsp[0].str);
}
    break;

  case 1782:
#line 8102 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1783:
#line 8102 "fgl.yacc"
    {
print_use_session(yyvsp[0].str);
strcpy(yyval.str,A4GL_get_undo_use());
}
    break;

  case 1788:
#line 8121 "fgl.yacc"
    { sprintf(yyval.str,"%s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str); }
    break;

  case 1789:
#line 8122 "fgl.yacc"
    { sprintf(yyval.str,"RENAME COLUMN  %s.%s TO %s",yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str); }
    break;

  case 1792:
#line 8130 "fgl.yacc"
    {
		sprintf(yyval.str,"%s %s",yyvsp[-1].str,yyvsp[0].str);
	}
    break;

  case 1793:
#line 8136 "fgl.yacc"
    {
		sprintf(yyval.str,"%s %s %s",
					yyvsp[-2].str,
					yyvsp[-1].str,
					yyvsp[0].str
					);
		}
    break;

  case 1796:
#line 8155 "fgl.yacc"
    {strcpy(yyval.str,"UNITS YEAR");}
    break;

  case 1797:
#line 8156 "fgl.yacc"
    {strcpy(yyval.str,"UNITS MONTH"); }
    break;

  case 1798:
#line 8157 "fgl.yacc"
    {strcpy(yyval.str,"UNITS DAY"); }
    break;

  case 1799:
#line 8158 "fgl.yacc"
    {strcpy(yyval.str,"UNITS HOUR"); }
    break;

  case 1800:
#line 8159 "fgl.yacc"
    {strcpy(yyval.str,"UNITS MINUTE"); }
    break;

  case 1801:
#line 8160 "fgl.yacc"
    {strcpy(yyval.str,"UNITS SECOND"); }
    break;

  case 1802:
#line 8164 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str," ",yyvsp[-1].str," ",yyvsp[0].str,0);}
    break;

  case 1803:
#line 8165 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-4].sql_string,yyvsp[-3].str,yyvsp[-2].str," ",yyvsp[-1].str," ",yyvsp[0].str,0);}
    break;

  case 1804:
#line 8166 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-3].str,yyvsp[-2].str," ",yyvsp[-1].str," ",yyvsp[0].str,0);}
    break;

  case 1806:
#line 8171 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1807:
#line 8172 "fgl.yacc"
    {sprintf(yyval.str,"%s %s TO %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1808:
#line 8176 "fgl.yacc"
    {sprintf(yyval.str,"DATETIME (\\\"%s\\\")",A4GL_strip_quotes(yyvsp[-1].str));}
    break;

  case 1809:
#line 8177 "fgl.yacc"
    {sprintf(yyval.str,"DATETIME(%s)",yyvsp[-1].str);}
    break;

  case 1810:
#line 8178 "fgl.yacc"
    {sprintf(yyval.str,"DATETIME(%s-%s)",yyvsp[-3].str,yyvsp[-1].str);}
    break;

  case 1811:
#line 8179 "fgl.yacc"
    {sprintf(yyval.str,"DATETIME(%s:%s)",yyvsp[-3].str,yyvsp[-1].str);}
    break;

  case 1812:
#line 8180 "fgl.yacc"
    {sprintf(yyval.str,"DATETIME(%s-%s-%s)",yyvsp[-5].str,yyvsp[-3].str,yyvsp[-1].str);}
    break;

  case 1813:
#line 8181 "fgl.yacc"
    {sprintf(yyval.str,"DATETIME(%s:%s:%s)",yyvsp[-5].str,yyvsp[-3].str,yyvsp[-1].str);}
    break;

  case 1814:
#line 8182 "fgl.yacc"
    {sprintf(yyval.str,
		"DATETIME(%s-%s-%s %s:%s:%s)",yyvsp[-10].str,yyvsp[-8].str,yyvsp[-6].str,yyvsp[-5].str,yyvsp[-3].str,yyvsp[-1].str);}
    break;

  case 1815:
#line 8184 "fgl.yacc"
    {sprintf(yyval.str,"DATETIME(%s-%s-%s %s:%s)",yyvsp[-8].str,yyvsp[-6].str,yyvsp[-4].str,yyvsp[-3].str,yyvsp[-1].str);}
    break;

  case 1816:
#line 8188 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1817:
#line 8189 "fgl.yacc"
    {sprintf(yyval.str,"%s %s(%s) TO %s",yyvsp[-6].str,yyvsp[-5].str,yyvsp[-3].str,yyvsp[0].str);}
    break;

  case 1818:
#line 8190 "fgl.yacc"
    {sprintf(yyval.str,"%s %s TO %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1819:
#line 8194 "fgl.yacc"
    {sprintf(yyval.str,"INTERVAL(\\\"%s\\\")",A4GL_strip_quotes(yyvsp[-1].str));}
    break;

  case 1820:
#line 8195 "fgl.yacc"
    {sprintf(yyval.str,"INTERVAL(%s)",yyvsp[-1].str);}
    break;

  case 1821:
#line 8196 "fgl.yacc"
    {sprintf(yyval.str,"INTERVAL(%s-%s)",yyvsp[-3].str,yyvsp[-1].str);}
    break;

  case 1822:
#line 8197 "fgl.yacc"
    {sprintf(yyval.str,"INTERVAL(%s:%s)",yyvsp[-3].str,yyvsp[-1].str);}
    break;

  case 1823:
#line 8198 "fgl.yacc"
    {sprintf(yyval.str,"INTERVAL(%s-%s-%s)",yyvsp[-5].str,yyvsp[-3].str,yyvsp[-1].str);}
    break;

  case 1824:
#line 8199 "fgl.yacc"
    {sprintf(yyval.str,"INTERVAL(%s:%s:%s)",yyvsp[-5].str,yyvsp[-3].str,yyvsp[-1].str);}
    break;

  case 1825:
#line 8202 "fgl.yacc"
    {
		sql_mode=1;
		start_bind('i',0);
		start_bind('o',0);
	}
    break;

  case 1826:
#line 8206 "fgl.yacc"
    {
			sql_mode=0;
			print_sql_block_cmd(yyvsp[-1].str);
	}
    break;

  case 1828:
#line 8215 "fgl.yacc"
    {sprintf(yyval.str,"%s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1830:
#line 8220 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1831:
#line 8221 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 2147:
#line 8545 "fgl.yacc"
    {sql_mode=0;}
    break;

  case 2148:
#line 8545 "fgl.yacc"
    {
		strcpy(yyval.str,yyvsp[0].sql_string);
		sql_mode=1;
	}
    break;

  case 2149:
#line 8552 "fgl.yacc"
    {sql_mode=0;}
    break;

  case 2150:
#line 8552 "fgl.yacc"
    {
 		strcpy(yyval.str,A4GL_get_into_part(doing_declare,get_bind_cnt('o')));
		sql_mode=1;
	}
    break;

  case 2151:
#line 8640 "fgl.yacc"
    {
		strcpy(current_upd_table,yyvsp[0].str);
		pop_all_gen(UPDCOL,"!"); pop_all_gen(UPDVAL,"!"); pop_all_gen(UPDVAL2,"!");
		yyval.sql_string=strdup("");
	}
    break;

  case 2152:
#line 8644 "fgl.yacc"
    {
		strcpy(current_upd_table,"");
	}
    break;

  case 2153:
#line 8646 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-5].str," ",yyvsp[-4].str," ",yyvsp[-2].sql_string," ",yyvsp[0].sql_string,0);
	}
    break;

  case 2154:
#line 8653 "fgl.yacc"
    {
		pop_all_gen(UPDCOL,"!"); pop_all_gen(UPDVAL,"!"); pop_all_gen(UPDVAL2,"!");
		yyval.sql_string=strdup("");
	}
    break;

  case 2155:
#line 8657 "fgl.yacc"
    { 
		pop_all_gen(UPDCOL,"!"); pop_all_gen(UPDVAL,"!"); pop_all_gen(UPDVAL2,"!");
		rm_quotes(yyvsp[0].str);
		sprintf(yyval.str,"%s %s",yyvsp[-1].str,yyvsp[0].str);
		yyval.sql_string=make_sql_string(yyval.str,0);
	}
    break;

  case 2156:
#line 8663 "fgl.yacc"
    {
		pop_all_gen(UPDCOL,"!"); pop_all_gen(UPDVAL,"!"); pop_all_gen(UPDVAL2,"!");
		yyval.sql_string=make_sql_string("WHERE ",yyvsp[0].sql_string,0);
	}
    break;

  case 2157:
#line 8671 "fgl.yacc"
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

  case 2158:
#line 8681 "fgl.yacc"
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

  case 2159:
#line 8691 "fgl.yacc"
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

  case 2160:
#line 8703 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("SET ",yyvsp[0].sql_string,0);
    }
    break;

  case 2161:
#line 8706 "fgl.yacc"
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

  case 2162:
#line 8725 "fgl.yacc"
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

  case 2163:
#line 8751 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 2164:
#line 8754 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",",yyvsp[0].sql_string,0);
	}
    break;

  case 2166:
#line 8763 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].str,"=",yyvsp[0].sql_string,0);
	}
    break;

  case 2167:
#line 8768 "fgl.yacc"
    {
			push_gen(UPDCOL,yyvsp[0].str); strcpy(yyval.str,yyvsp[0].str);
		}
    break;

  case 2168:
#line 8771 "fgl.yacc"
    {
			push_gen(UPDCOL,yyvsp[0].str); sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);
		}
    break;

  case 2169:
#line 8779 "fgl.yacc"
    { 
		yyval.sql_string=yyvsp[0].sql_string; 
		if (gen_cnt(UPDVAL2)) {
			copy_gen(UPDVAL,UPDVAL2);
		} else {
                	push_gen(UPDVAL,yyvsp[0].sql_string);
		}
	}
    break;

  case 2170:
#line 8787 "fgl.yacc"
    { 
		if (gen_cnt(UPDVAL2)) {
			copy_gen(UPDVAL,UPDVAL2);
		} else {
                	push_gen(UPDVAL,yyvsp[0].sql_string);
		}
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",",yyvsp[0].sql_string,0); 
	}
    break;

  case 2171:
#line 8800 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 2172:
#line 8803 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 2173:
#line 8811 "fgl.yacc"
    {
                yyval.sql_string=yyvsp[0].sql_string;
        }
    break;

  case 2174:
#line 8814 "fgl.yacc"
    {
                yyval.sql_string=make_sql_string("-",yyvsp[0].sql_string,0);
        }
    break;

  case 2175:
#line 8817 "fgl.yacc"
    {
                yyval.sql_string=make_sql_string("+",yyvsp[0].sql_string,0);
        }
    break;

  case 2176:
#line 8825 "fgl.yacc"
    { 
		
		yyval.sql_string=yyvsp[0].sql_string; 
	}
    break;

  case 2177:
#line 8829 "fgl.yacc"
    { yyval.sql_string=yyvsp[0].sql_string; }
    break;

  case 2178:
#line 8830 "fgl.yacc"
    { yyval.sql_string=strdup(yyvsp[0].str); }
    break;

  case 2179:
#line 8831 "fgl.yacc"
    { yyval.sql_string=make_sql_string(yyvsp[-2].str,".",yyvsp[0].str,0); }
    break;

  case 2180:
#line 8832 "fgl.yacc"
    { yyval.sql_string=make_sql_string(yyvsp[-3].str,"[",yyvsp[-1].str,"]",0); }
    break;

  case 2181:
#line 8833 "fgl.yacc"
    { yyval.sql_string=make_sql_string(yyvsp[-5].str,".",yyvsp[-3].str,"[",yyvsp[-1].str,"]",0); }
    break;

  case 2182:
#line 8834 "fgl.yacc"
    { yyval.sql_string=make_sql_string(yyvsp[-5].str,"[",yyvsp[-3].str,",",yyvsp[-1].str,"]",0); }
    break;

  case 2183:
#line 8835 "fgl.yacc"
    { yyval.sql_string=make_sql_string(yyvsp[-7].str,".",yyvsp[-5].str,"[",yyvsp[-3].str,",",yyvsp[-1].str,"]",0); }
    break;

  case 2184:
#line 8836 "fgl.yacc"
    { 
		yyval.sql_string=yyvsp[0].sql_string; 
		pop_all_gen(UPDVAL2,"!");
	}
    break;

  case 2185:
#line 8840 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[0].str,0);}
    break;

  case 2186:
#line 8841 "fgl.yacc"
    {yyval.sql_string=make_sql_string("TRUE",0);}
    break;

  case 2187:
#line 8842 "fgl.yacc"
    {yyval.sql_string=make_sql_string("FALSE",0);}
    break;

  case 2188:
#line 8843 "fgl.yacc"
    {yyval.sql_string=make_sql_string("USER",0);}
    break;

  case 2189:
#line 8844 "fgl.yacc"
    {yyval.sql_string=make_sql_string("COUNT(*)",0);}
    break;

  case 2190:
#line 8850 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,"/",yyvsp[0].sql_string,0);}
    break;

  case 2191:
#line 8851 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-1].sql_string,yyvsp[0].str,0);}
    break;

  case 2192:
#line 8852 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,"*",yyvsp[0].sql_string,0);}
    break;

  case 2193:
#line 8853 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,"+",yyvsp[0].sql_string,0);}
    break;

  case 2194:
#line 8854 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,"-",yyvsp[0].sql_string,0);}
    break;

  case 2195:
#line 8855 "fgl.yacc"
    {yyval.sql_string=make_sql_string("AVERAGE(",yyvsp[-2].str,yyvsp[-1].sql_string,")",0);}
    break;

  case 2196:
#line 8856 "fgl.yacc"
    {yyval.sql_string=make_sql_string("MAX(",yyvsp[-2].str,yyvsp[-1].sql_string,")",0);}
    break;

  case 2197:
#line 8857 "fgl.yacc"
    {yyval.sql_string=make_sql_string("MIN(",yyvsp[-2].str,yyvsp[-1].sql_string,")",0);}
    break;

  case 2198:
#line 8858 "fgl.yacc"
    {yyval.sql_string=make_sql_string("SUM(",yyvsp[-2].str,yyvsp[-1].sql_string,")",0);}
    break;

  case 2199:
#line 8859 "fgl.yacc"
    {yyval.sql_string=make_sql_string("COUNT(",yyvsp[-2].str,yyvsp[-1].sql_string,")",0);}
    break;

  case 2200:
#line 8860 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-3].str,"(",yyvsp[-1].sql_string,")",0);}
    break;

  case 2201:
#line 8861 "fgl.yacc"
    {yyval.sql_string=make_sql_string("DATE(",yyvsp[-1].sql_string,")",0);}
    break;

  case 2202:
#line 8862 "fgl.yacc"
    {yyval.sql_string=make_sql_string("(",yyvsp[-1].sql_string,")",0);}
    break;

  case 2203:
#line 8863 "fgl.yacc"
    {yyval.sql_string=make_sql_string("EXTEND(",yyvsp[-1].sql_string,")",0);}
    break;

  case 2204:
#line 8864 "fgl.yacc"
    { yyval.sql_string=make_sql_string(yyvsp[0].str,0);}
    break;

  case 2205:
#line 8865 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[0].str,0);}
    break;

  case 2206:
#line 8870 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
}
    break;

  case 2207:
#line 8876 "fgl.yacc"
    {yyval.sql_string=yyvsp[0].sql_string;}
    break;

  case 2208:
#line 8877 "fgl.yacc"
    {
        yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",",yyvsp[0].sql_string,0);
}
    break;

  case 2209:
#line 8885 "fgl.yacc"
    {
	clr_validate_list();
}
    break;

  case 2210:
#line 8887 "fgl.yacc"
    {
	print_validate();
}
    break;

  case 2212:
#line 8893 "fgl.yacc"
    {sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 2213:
#line 8897 "fgl.yacc"
    {
		sprintf(yyval.str,"%s.%s",yyvsp[-2].str,yyvsp[0].str);
		push_validate(yyval.str);
	}
    break;

  case 2214:
#line 8901 "fgl.yacc"
    {
		sprintf(yyval.str,"%s.*",yyvsp[-2].str);
		push_validate(yyval.str);
	}
    break;

  case 2215:
#line 8917 "fgl.yacc"
    {
	if (scan_variable(variable_usage_as_string(yyvsp[0].var_usg,VAR_USG_ANY))!=-1) {
		char buff[1024];
		sprintf(buff,"%s",fgl_add_scope(variable_usage_as_string(yyvsp[0].var_usg,VAR_USG_VARIABLE),0));
		print_push_variable(buff);
		strcpy(yyval.str,"?");
	} else {
		strcpy(yyval.str,variable_usage_as_string(yyvsp[0].var_usg,VAR_USG_IDENT));
	}

}
    break;

  case 2216:
#line 8931 "fgl.yacc"
    {
		strcpy(yyval.str,variable_usage_as_string(yyvsp[0].var_usg,VAR_USG_ANY));
	}
    break;

  case 2217:
#line 8937 "fgl.yacc"
    {
		yyval.var_usg=yyvsp[0].var_usg;
	}
    break;

  case 2218:
#line 8939 "fgl.yacc"
    {
		yyval.var_usg=yyvsp[0].var_usg;
	}
    break;

  case 2222:
#line 8953 "fgl.yacc"
    {
		yyval.var_usg=append_variable_usage(yyvsp[-2].var_usg,yyvsp[0].var_usg);
	}
    break;

  case 2223:
#line 8956 "fgl.yacc"
    {
		yyval.var_usg=new_variable_usage(yyvsp[-2].var_usg,"*",0);
	}
    break;

  case 2224:
#line 8963 "fgl.yacc"
    {
			yyval.var_usg=yyvsp[0].var_usg;
	}
    break;

  case 2225:
#line 8966 "fgl.yacc"
    { yyval.var_usg=new_variable_usage(0,yyvsp[0].str,0); }
    break;

  case 2226:
#line 8996 "fgl.yacc"
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

  case 2227:
#line 9021 "fgl.yacc"
    {
char buff[256];
char was_str[40000];
char lstr[1024];
int z = 0,a = 0;
strcpy(was_str,"");
printf("THRU : %s %s\n",yyvsp[-2].str,yyvsp[0].str);

A4GL_debug("Starting THRU");

sprintf(buff,"%s\n%s",yyvsp[-2].str,yyvsp[0].str);
a=get_bind_cnt('i');
printf("get_bind_cnt=%d\n",a);
z=add_bind('i',buff);
z-=a;

strcpy(was_str,A4GL_set_var_sql(doing_declare,z));
//for (a=0;a<z;a++)  {
         //if (strlen(was_str)) {strcat(was_str,",");}
	 //strcat(was_str,A4GL_set_var_sql(doing_declare,1));
//}



	/* split_record(buff,&v_r,&v_1,&v_2);

	v_loop=v_1;

	while (1) {
                //strcpy(kp,was_str);
                sprintf(buff,"%s.%s",r1,v_loop->names.name);

		if (scan_variable(buff)!=-1&&(!system_var(buff))) {
			a=get_bind_cnt('i');
			z=add_bind('i',buff);
			z-=a;
			if (strlen(was_str)) {strcat(was_str,",");}
			strcat(was_str,A4GL_set_var_sql(doing_declare,z));
        	}

		//for (a=0;a<z;a++)  {
			//if (strlen(was_str)) {strcat(was_str,",");}
         		//strcat(was_str,"?");
		//}
		v_loop=get_next_variable(v_r,v_loop,v_2);
	}
*/


yyval.sql_string=strdup(was_str);
}
    break;

  case 2228:
#line 9076 "fgl.yacc"
    {
  int type,arrsize,size,level;
  char arrbuff[256];
  struct num_list *array;
  struct num_list *substr;
  struct array_list *al;

  yyval.var_usg=new_variable_usage(0,yyvsp[-1].str,0);
  al=yyvsp[0].array_list;
  array=al->array;
  substr=al->substr;

  if (array) {
	int cnt;
	cnt=0;
	while (array) {
		set_variable_usage_subscript(yyval.var_usg,cnt,array->num);
		cnt++;
		array=array->next;
	}
  }

  if (substr) {
	int cnt;
	cnt=0;
	while (substr) {
		set_variable_usage_substr(yyval.var_usg,cnt,substr->num);
		cnt++;
		substr=substr->next;
	}
  }
}
    break;

  case 2229:
#line 9111 "fgl.yacc"
    {
		struct array_list *al;
         	A4GL_debug("---> Subscript or substring");
		al=malloc(sizeof(struct array_list));
		al->array=yyvsp[-1].num_list;
		al->substr=0;
		yyval.array_list=al;

        }
    break;

  case 2230:
#line 9120 "fgl.yacc"
    {
		struct array_list *al;
         	A4GL_debug("---> Subscript & substring");
		al=malloc(sizeof(struct array_list));
		al->array=yyvsp[-4].num_list;
		al->substr=yyvsp[-1].num_list;
		yyval.array_list=al;
        }
    break;

  case 2231:
#line 9131 "fgl.yacc"
    { 
			yyval.num_list=yyvsp[0].num_list; 
		}
    break;

  case 2232:
#line 9134 "fgl.yacc"
    { 
			yyval.num_list=append_num_list_items(yyvsp[-2].num_list,yyvsp[0].num_list); 
		}
    break;

  case 2233:
#line 9140 "fgl.yacc"
    {
  yyval.num_list=new_num_list_item(yyvsp[0].str);
}
    break;

  case 2234:
#line 9153 "fgl.yacc"
    {
		set_whenever_from_store();
}
    break;

  case 2235:
#line 9167 "fgl.yacc"
    {
print_while_1();
push_blockcommand("WHILE");
}
    break;

  case 2236:
#line 9170 "fgl.yacc"
    {
print_while_2();
}
    break;

  case 2237:
#line 9174 "fgl.yacc"
    {
print_while_3();
pop_blockcommand("WHILE");
}
    break;

  case 2238:
#line 9189 "fgl.yacc"
    {yyval.field_list=0;}
    break;

  case 2239:
#line 9189 "fgl.yacc"
    {
	yyval.field_list=yyvsp[0].field_list;
}
    break;

  case 2240:
#line 9195 "fgl.yacc"
    { strcpy(yyval.str,"0"); }
    break;

  case 2241:
#line 9196 "fgl.yacc"
    { strcpy(yyval.str,"1"); }
    break;

  case 2242:
#line 9199 "fgl.yacc"
    { print_current_window("\"screen\""); print_clr_window("\"screen\""); }
    break;

  case 2243:
#line 9200 "fgl.yacc"
    { print_clr_window(yyvsp[0].str); }
    break;

  case 2244:
#line 9201 "fgl.yacc"
    { print_clr_window(yyvsp[0].str); }
    break;

  case 2245:
#line 9202 "fgl.yacc"
    { print_clr_form(0,0,"0"); }
    break;

  case 2246:
#line 9203 "fgl.yacc"
    { print_clr_form(0,0,"1"); }
    break;

  case 2247:
#line 9204 "fgl.yacc"
    { print_clr_form(yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str); }
    break;

  case 2248:
#line 9205 "fgl.yacc"
    {
	print_clr_fields(field_name_list_as_char(yyvsp[-1].field_list),yyvsp[0].str);
}
    break;

  case 2249:
#line 9216 "fgl.yacc"
    {
	print_current_window("\"screen\"");
}
    break;

  case 2250:
#line 9220 "fgl.yacc"
    {
	print_current_window(yyvsp[0].str);
}
    break;

  case 2251:
#line 9224 "fgl.yacc"
    {
sprintf(yyval.str,"A4GL_cr_window");
reset_attrib(&form_attrib);
}
    break;

  case 2252:
#line 9228 "fgl.yacc"
    {
sprintf(yyval.str,"A4GL_cr_window_form");
reset_attrib(&form_attrib);
}
    break;

  case 2253:
#line 9233 "fgl.yacc"
    {
	print_show_window(yyvsp[0].str);
	addmap("Show Window",yyvsp[0].str,curr_func,yylineno,infilename); 
}
    break;

  case 2254:
#line 9237 "fgl.yacc"
    {
	print_show_menu(yyvsp[-3].str,yyvsp[-1].str);
	addmap("Call Menuhandler",yyvsp[-1].str,curr_func,yylineno,infilename); 
}
    break;

  case 2255:
#line 9242 "fgl.yacc"
    {

print_def_mn_file();

}
    break;

  case 2257:
#line 9250 "fgl.yacc"
    {addmap("Use Menu",yyvsp[0].str,curr_func,yylineno,infilename); }
    break;

  case 2259:
#line 9256 "fgl.yacc"
    {
	print_hide_window(yyvsp[0].str);
}
    break;

  case 2260:
#line 9262 "fgl.yacc"
    {
print_move_window(yyvsp[-4].str,0);
}
    break;

  case 2261:
#line 9266 "fgl.yacc"
    {
print_move_window(yyvsp[-4].str,1);
}
    break;

  case 2266:
#line 9284 "fgl.yacc"
    {
chk4var=0;A4GL_lex_printcomment("/* [Comm:%s] */\n",yyval.str);
if (A4GL_isyes(acl_getenv("INCLINES")))
A4GL_lex_printc("{A4GL_debug(\"Line %d %s:%s\");}",lastlineno,infilename,convstrsql(larr));
	A4GL_prchkerr(lastlineno,infilename);
	lastlineno=yylineno;
}
    break;

  case 2267:
#line 9291 "fgl.yacc"
    {
A4GL_lex_printcomment("/* [COMM:%s] */\n",yyvsp[0].str);chk4var=0;
if (A4GL_isyes(acl_getenv("INCLINES")))
A4GL_lex_printc("{A4GL_debug(\"Line %d %s:%s\");}",lastlineno,infilename,convstrsql(larr));
/* if (A4GL_aubit_strcasecmp($<str>$,"whenever")!=0)  */
A4GL_prchkerr(lastlineno,infilename);
lastlineno=yylineno;
}
    break;

  case 2268:
#line 9301 "fgl.yacc"
    {print_cmd_start();}
    break;

  case 2269:
#line 9301 "fgl.yacc"
    {print_cmd_end();}
    break;


    }

/* Line 991 of yacc.c.  */
#line 19239 "y.tab.c"

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


#line 9399 "fgl.yacc"

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



