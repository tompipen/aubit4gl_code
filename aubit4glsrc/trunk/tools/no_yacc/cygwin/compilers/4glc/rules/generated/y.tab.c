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
     NAME = 1708,
     UMINUS = 1709,
     COMMA = 1614,
     KW_OR = 1654,
     KW_AND = 1609,
     KW_USING = 1546,
     NOT = 1629,
     MATCHES = 1426,
     POWER = 1532,
     LESS_THAN = 1528,
     GREATER_THAN = 1443,
     EQUAL = 1604,
     GREATER_THAN_EQ = 1345,
     LESS_THAN_EQ = 1402,
     NOT_EQUAL = 1474,
     PLUS = 1640,
     MINUS = 1627,
     MULTIPLY = 1533,
     DIVIDE = 1560,
     MOD = 1628,
     COMMAND = 1409,
     NUMBER_VALUE = 1710,
     CHAR_VALUE = 1711,
     INT_VALUE = 1712,
     NAMED_GEN = 1713,
     CLINE = 1714,
     SQLLINE = 1715,
     KW_CSTART = 1716,
     KW_CEND = 1717,
     USER_DTYPE = 1718,
     SQL_TEXT = 1719,
     KW_WHENEVER_SET = 1720,
     COMMENT = 1721,
     DYNAMIC_ARRAY = 1000,
     RESIZE_ARRAY = 1001,
     ALLOCATE_ARRAY = 1002,
     DEALLOCATE_ARRAY = 1003,
     AFTER_INSERT_DELETE = 1004,
     BEFORE_INSERT_DELETE = 1005,
     BEFORE_INSERT = 1006,
     CONCAT_PIPES = 1007,
     BEFORE_DELETE = 1008,
     DROP_TRIGGER = 1009,
     AFTER_INSERT = 1010,
     AFTER_DELETE = 1011,
     EXECUTE_IMMEDIATE = 1012,
     DELETE_ROW_EQUAL_TRUE = 1013,
     INSERT_ROW_EQUAL_TRUE = 1014,
     DELETE_ROW_EQUAL_FALSE = 1015,
     INSERT_ROW_EQUAL_FALSE = 1016,
     CURRENT_ROW_DISPLAY_EQUAL = 1017,
     MAXCOUNT = 1018,
     ALTER_TABLE = 1019,
     ALTER_INDEX = 1020,
     NEXT_SIZE = 1021,
     DISPLAY_ATTR_FORM = 1022,
     DISPLAY_ATTR_WINDOW = 1023,
     INPUT_ATTR_FORM = 1024,
     INPUT_ATTR_WINDOW = 1025,
     WHENEVER_ERROR_CONTINUE = 1026,
     WHENEVER_ANY_ERROR_CONTINUE = 1027,
     WHENEVER_WARNING_CONTINUE = 1028,
     WHENEVER_SQLSUCCESS_CONTINUE = 1029,
     WHENEVER_SQLWARNING_CONTINUE = 1030,
     WHENEVER_NOT_FOUND_CONTINUE = 1031,
     WHENEVER_SQLERROR_CONTINUE = 1032,
     WHENEVER_SUCCESS_CONTINUE = 1033,
     WHENEVER_ERROR_GOTO = 1034,
     WHENEVER_ANY_ERROR_GOTO = 1035,
     WHENEVER_WARNING_GOTO = 1036,
     WHENEVER_SQLSUCCESS_GOTO = 1037,
     WHENEVER_SQLWARNING_GOTO = 1038,
     WHENEVER_NOT_FOUND_GOTO = 1039,
     WHENEVER_SQLERROR_GOTO = 1040,
     WHENEVER_SUCCESS_GOTO = 1041,
     WHENEVER_ERROR_CALL = 1042,
     WHENEVER_ANY_ERROR_CALL = 1043,
     WHENEVER_WARNING_CALL = 1044,
     WHENEVER_SQLSUCCESS_CALL = 1045,
     WHENEVER_SQLWARNING_CALL = 1046,
     WHENEVER_NOT_FOUND_CALL = 1047,
     WHENEVER_SQLERROR_CALL = 1048,
     WHENEVER_SUCCESS_CALL = 1049,
     WHENEVER_ERROR_STOP = 1050,
     WHENEVER_ANY_ERROR_STOP = 1051,
     WHENEVER_WARNING_STOP = 1052,
     WHENEVER_SQLSUCCESS_STOP = 1053,
     WHENEVER_SQLWARNING_STOP = 1054,
     WHENEVER_NOT_FOUND_STOP = 1055,
     WHENEVER_SQLERROR_STOP = 1056,
     WHENEVER_SUCCESS_STOP = 1057,
     XSET_MULTIPLY_EQUAL_OPEN_BRACKET = 1058,
     XSET_ident_DOT_MULTIPLY_EQUAL_OPEN_BRACKET = 1059,
     XSET_ident_DOT_MULTIPLY_EQUAL = 1060,
     XSET_MULTIPLY_EQUAL = 1061,
     XSET_OPEN_BRACKET = 1062,
     NEWFORMATSHARED = 1063,
     CREATE_DATABASE = 1064,
     DROP_DATABASE = 1065,
     IMPORT_LEGACY_FUNCTION = 1066,
     ADD_CONSTRAINT = 1067,
     DROP_CONSTRAINT = 1068,
     DROP_SYNONYM = 1069,
     CONSTRAINT = 1070,
     AS_STATIC = 1071,
     NOT_FIELD_TOUCHED = 1072,
     LOCAL_FUNCTION = 1073,
     EVERY_ROW = 1074,
     ELIF = 1075,
     DOUBLE_PRECISION = 1076,
     COUNT_MULTIPLY = 1077,
     WAIT_FOR_KEY = 1078,
     AT_TERMINATION_CALL = 1079,
     TERMINATE_REPORT = 1080,
     TO_MAIN_CAPTION = 1081,
     CLEARSTAT = 1082,
     TO_MENUITEM = 1083,
     ID_TO_INT = 1084,
     TO_STATUSBOX = 1085,
     ASCII_HEIGHT_ALL = 1086,
     ASCII_WIDTH_ALL = 1087,
     IMPORT_DATATYPE = 1088,
     PAGE_TRAILER_SIZE = 1089,
     PAGE_HEADER_SIZE = 1090,
     FIRST_PAGE_HEADER_SIZE = 1091,
     BYTES_USE_AS_IMAGE = 1092,
     BYTES_USE_AS_ASCII = 1093,
     KWUP_BY = 1094,
     KWDOWN_BY = 1095,
     CLOSE_STATUSBOX = 1096,
     MODIFY_NEXT_SIZE = 1097,
     LOCK_MODE_PAGE = 1098,
     LOCK_MODE_ROW = 1099,
     TO_PIPE = 1100,
     TO_PRINTER = 1101,
     STATUSBOX = 1102,
     FORMHANDLER_INPUT = 1103,
     UNITS_YEAR = 1104,
     UNITS_MONTH = 1105,
     UNITS_DAY = 1106,
     UNITS_HOUR = 1107,
     UNITS_MINUTE = 1108,
     UNITS_SECOND = 1109,
     NO_NEW_LINES = 1110,
     FIELDTOWIDGET = 1111,
     WITH_HOLD = 1112,
     SHOW_MENU = 1113,
     TO_CLUSTER = 1114,
     TO_NOT_CLUSTER = 1115,
     CWIS = 1116,
     CREATE_IDX = 1117,
     FORM_IS_COMPILED = 1118,
     PDF_REPORT = 1119,
     IMPORT_FUNCTION = 1120,
     PROMPT_MANY = 1121,
     POINTS = 1122,
     MM = 1123,
     INCHES = 1124,
     PREPEND = 1125,
     MEMBER_OF = 1126,
     MEMBER_FUNCTION = 1127,
     APPEND = 1128,
     TEMPLATE = 1129,
     END_TEMPLATE = 1130,
     SQLSICS = 1131,
     CREATE_SCHEMA = 1132,
     SQLSIRR = 1133,
     UPDATESTATS_T = 1134,
     SQLSICR = 1135,
     WHENEVER_SQLSUCCESS = 1136,
     WHENEVER_SQLWARNING = 1137,
     WHENEVER_ANY_ERROR = 1138,
     WHENEVER_NOT_FOUND = 1139,
     WHENEVER_SQLERROR = 1140,
     WHENEVER_SUCCESS = 1141,
     WHENEVER_ERROR = 1142,
     START_EXTERN = 1143,
     CONTINUE_CONSTRUCT = 1144,
     FOUNCONSTR = 1145,
     SQLSIDR = 1146,
     CREATE_TEMP_TABLE = 1147,
     CURRENT_WINDOW_IS = 1148,
     FIRST_PAGE_HEADER = 1149,
     ORDER_EXTERNAL_BY = 1150,
     SCROLL_CURSOR_FOR = 1151,
     SCROLL_CURSOR = 1152,
     SQL_INTERRUPT_OFF = 1153,
     STOP_ALL_EXTERNAL = 1154,
     WITH_CHECK_OPTION = 1155,
     WITH_GRANT_OPTION = 1156,
     SQLSLMNW = 1157,
     ADDCONSTUNIQ = 1158,
     CONTINUE_DISPLAY = 1159,
     CONTINUE_FOREACH = 1160,
     OUTPUT_TO_REPORT = 1161,
     SQL_INTERRUPT_ON = 1162,
     WHERE_CURRENT_OF = 1163,
     WITHOUT_DEFAULTS = 1164,
     FOCONSTR = 1165,
     SCALED_BY = 1166,
     CONTINUE_PROMPT = 1167,
     PDF_FUNCTION = 1168,
     DEFER_INTERRUPT = 1169,
     DISPLAY_BY_NAME = 1170,
     NOT_NULL_UNIQUE = 1171,
     SKIP_TO_TOP = 1172,
     TOP_OF_PAGE = 1173,
     SKIP_TO = 1174,
     SKIP_BY = 1175,
     WITHOUT_WAITING = 1176,
     BEFCONSTRUCT = 1177,
     SQLSLMW = 1178,
     AFTCONSTRUCT = 1179,
     ALL_PRIVILEGES = 1180,
     CLOSE_DATABASE = 1181,
     CONTINUE_INPUT = 1182,
     CONTINUE_WHILE = 1183,
     CREATE_SYNONYM = 1184,
     DROP_TABLE = 1185,
     EXIT_CONSTRUCT = 1186,
     INEXCLUSIVE = 1187,
     REPORT_TO_PRINTER = 1188,
     REPORT_TO_PIPE = 1189,
     RETURN = 1190,
     SET_SESSION_TO = 1191,
     UPDATESTATS = 1192,
     WITHOUT_HEAD = 1193,
     CLEARSCR = 1194,
     WITH_B_LOG = 1195,
     AUTHORIZATION = 1196,
     BOTTOM_MARGIN = 1197,
     CLOSE_SESSION = 1198,
     CONTINUE_CASE = 1199,
     CONTINUE_MENU = 1200,
     DISPLAY_ARRAY = 1201,
     END_SQL = 1202,
     DOLLAR = 1203,
     END_CONSTRUCT = 1204,
     FIELD_TOUCHED = 1205,
     FINISH_REPORT = 1206,
     INFACC = 1207,
     INPUT_NO_WRAP = 1208,
     SETPMOFF = 1209,
     UNCONSTRAINED = 1210,
     PAGE_TRAILER = 1211,
     SETPMON = 1212,
     BEFGROUP = 1213,
     CLOSE_WINDOW = 1214,
     COMMENT_LINE = 1215,
     CONTINUE_FOR = 1216,
     CREATE_DB = 1217,
     CREATE_TABLE = 1218,
     DEFAULT_NULL = 1219,
     DEFAULT_TODAY = 1220,
     DEFAULT_USER = 1221,
     DELETE_USING = 1222,
     DISPLAY_FORM = 1223,
     END_FUNCTION = 1224,
     EXIT_DISPLAY = 1225,
     EXIT_FOREACH = 1226,
     EXIT_PROGRAM = 1227,
     INFCOLS = 1228,
     ON_EVERY_ROW = 1229,
     OPEN_SESSION = 1230,
     RIGHT_MARGIN = 1231,
     SELECT_USING = 1232,
     START_REPORT = 1233,
     UNLOCK_TABLE = 1234,
     UPDATE_USING = 1235,
     ACL_BUILTIN = 1236,
     AFTGROUP = 1237,
     INFIDX = 1238,
     INFSTAT = 1239,
     LEFT_MARGIN = 1240,
     PAGE_HEADER = 1241,
     ROLLBACK_W = 1242,
     SET_SESSION = 1243,
     SQLSEOFF = 1244,
     WITH_A_LOG = 1245,
     BEFDISP = 1246,
     BEFORE_MENU = 1247,
     CREATE_VIEW = 1248,
     DEFINE_TYPE = 1249,
     DELETE_FROM = 1250,
     END_DISPLAY = 1251,
     END_REPORT = 1252,
     END_FOREACH = 1253,
     END_FOR = 1254,
     END_GLOBALS = 1255,
     EXIT_PROMPT = 1256,
     EXTENT_SIZE = 1257,
     FOREIGN_KEY = 1258,
     HIDE_OPTION = 1259,
     HIDE_WINDOW = 1260,
     INSERT_INTO = 1261,
     IS_NOT_NULL = 1262,
     MOVE_WINDOW = 1263,
     NEXT_OPTION = 1264,
     NOT_MATCHES = 1265,
     ON_LAST_ROW = 1266,
     OPEN_WINDOW = 1267,
     OPEN_STATUSBOX = 1268,
     PAGE_LENGTH = 1269,
     PAGE_WIDTH = 1270,
     PRIMARY_KEY = 1271,
     PROMPT_LINE = 1272,
     RECORD_LIKE = 1273,
     ROLLFORWARD = 1274,
     SETBL = 1275,
     SHOW_OPTION = 1276,
     SHOW_WINDOW = 1277,
     SQLSEON = 1278,
     TO_DATABASE = 1279,
     USE_SESSION = 1280,
     WITH_NO_LOG = 1281,
     AFTDISP = 1282,
     BEFFIELD = 1283,
     INSHARE = 1284,
     UNLOCKTAB = 1285,
     AFTFIELD = 1286,
     ATTRIBUTES = 1287,
     BEFINP = 1288,
     BEGIN_WORK = 1289,
     CLEARWIN = 1290,
     CLOSE_FORM = 1291,
     DEFER_QUIT = 1292,
     DESCENDING = 1293,
     DROP_INDEX = 1294,
     END_PROMPT = 1295,
     END_RECORD = 1296,
     ERROR_LINE = 1297,
     EXIT_INPUT = 1298,
     EXIT_WHILE = 1299,
     FOR_UPDATE_OF = 1300,
     FOR_UPDATE = 1301,
     GET_FLDBUF = 1302,
     INITIALIZE = 1303,
     INPUT_WRAP = 1304,
     LOCK_TABLE = 1305,
     MSG_LINE = 1306,
     NOT_EXISTS = 1307,
     ON_ANY_KEY = 1308,
     REFERENCES = 1309,
     RENCOL = 1310,
     SET_CURSOR = 1311,
     SMALLFLOAT = 1312,
     SQLSUCCESS = 1313,
     TOP_MARGIN = 1314,
     WITH_ARRAY = 1315,
     ACCEPTKEY = 1316,
     ACCEPT = 1317,
     AFTINP = 1318,
     CLEARFORMTODEFAULTS = 1319,
     CLEARFORM = 1320,
     CLEAR_X_FORM = 1321,
     COMMIT_W = 1322,
     NEXTPAGE = 1323,
     PREVPAGE = 1324,
     CTRL_KEY = 1325,
     INFTABS = 1326,
     NEXTFIELD = 1327,
     NEXTFORM = 1328,
     RENTAB = 1329,
     ASCENDING = 1330,
     ASSOCIATE = 1331,
     CHAR = 1332,
     NCHAR = 1333,
     NVARCHAR = 1334,
     CONSTRUCT = 1335,
     DELIMITER = 1336,
     DOWNSHIFT = 1337,
     DROP_VIEW = 1338,
     END_INPUT = 1339,
     END_WHILE = 1340,
     EXCLUSIVE = 1341,
     EXIT_CASE = 1342,
     EXIT_MENU = 1343,
     FORM_LINE = 1344,
     INTERRUPT = 1346,
     INTO_TEMP = 1347,
     INVISIBLE = 1348,
     IN_MEMORY = 1349,
     LINKED_TO = 1350,
     LOAD_FROM = 1351,
     LOCKTAB = 1352,
     MENU_LINE = 1353,
     OPEN_FORM = 1354,
     OTHERWISE = 1355,
     PRECISION = 1356,
     PRIOR = 1357,
     PROCEDURE = 1358,
     REPORT_TO = 1359,
     RETURNING = 1360,
     UNDERLINE = 1361,
     UNLOAD_TO = 1362,
     BEFROW = 1363,
     UNLOAD_T = 1364,
     VARIABLE = 1365,
     ABSOLUTE = 1366,
     AFTROW = 1367,
     BUFFERED = 1368,
     CONSTANT = 1369,
     CONST = 1370,
     DATABASE = 1371,
     DATETIME = 1372,
     DEFAULTS = 1373,
     DISTINCT = 1374,
     END_CASE = 1375,
     END_MAIN = 1376,
     END_MENU = 1377,
     END_TYPE = 1378,
     EXIT_FOR = 1379,
     EXTERNAL = 1380,
     FRACTION = 1381,
     FUNCTION = 1382,
     GROUP_BY = 1383,
     INTERVAL = 1384,
     KWMESSAGE = 1385,
     NOT_LIKE = 1386,
     NOT_ILIKE = 1387,
     NOT_NULL = 1388,
     PASSWORD = 1389,
     PREVIOUS = 1390,
     READONLY = 1391,
     REGISTER = 1392,
     RELATIVE = 1393,
     RESOURCE = 1394,
     SMALLINT = 1395,
     VALIDATE = 1396,
     WITH_LOG = 1397,
     WORDWRAP = 1398,
     BY_NAME = 1399,
     IN_FILE = 1400,
     IS_NULL = 1401,
     AVERAGE = 1403,
     BETWEEN = 1404,
     CAPTION = 1405,
     CLIPPED = 1406,
     CLOSE_BRACKET = 1407,
     COLUMNS = 1408,
     CONNECT = 1410,
     CURRENT = 1411,
     DBYNAME = 1412,
     DECIMAL = 1413,
     DECLARE = 1414,
     DEFAULT = 1415,
     DISPLAY = 1416,
     ENDCODE = 1417,
     EXECUTE = 1418,
     FOREACH = 1419,
     FOREIGN = 1420,
     GLOBALS = 1421,
     INFIELD = 1422,
     INTEGER = 1423,
     KWWINDOW = 1424,
     MAGENTA = 1425,
     OPTIONS = 1427,
     PERCENT = 1428,
     PREPARE = 1429,
     PROGRAM = 1430,
     RECOVER = 1431,
     REVERSE = 1432,
     SECTION = 1433,
     SESSION = 1434,
     SYNONYM = 1435,
     THRU = 1436,
     TRAILER = 1437,
     UPSHIFT = 1438,
     VARCHAR = 1439,
     WAITING = 1440,
     CLOSE_SHEV = 1441,
     CLOSE_SQUARE = 1442,
     KW_FALSE = 1444,
     NOT_IN = 1445,
     ONKEY = 1446,
     OPEN_BRACKET = 1447,
     BORDER = 1448,
     BOTTOM = 1449,
     COLUMN = 1450,
     COMMIT = 1451,
     CREATE = 1452,
     CURSOR = 1453,
     DEFINE = 1454,
     DELETE = 1455,
     DOUBLE = 1456,
     END_IF = 1457,
     ESCAPE = 1458,
     EXISTS = 1459,
     EXTEND = 1460,
     EXTENT = 1461,
     FINISH = 1462,
     FORMAT = 1463,
     HAVING = 1464,
     HEADER = 1465,
     INSERT = 1466,
     LOCATE = 1467,
     MARGIN = 1468,
     MEMORY = 1469,
     MINUTE = 1470,
     MODIFY = 1471,
     NORMAL = 1472,
     EQUAL_EQUAL = 1473,
     OPEN_SHEV = 1475,
     OPEN_SQUARE = 1476,
     OPTION = 1477,
     OUTPUT = 1478,
     PROMPT = 1479,
     PUBLIC = 1480,
     RECORD = 1481,
     REPORT = 1482,
     REVOKE = 1483,
     SCHEMA = 1484,
     SCROLL_USING = 1485,
     SCROLL = 1486,
     SECOND = 1487,
     SELECT = 1488,
     SERIAL = 1489,
     SETL = 1490,
     SHARED = 1491,
     SPACES = 1492,
     UNIQUE = 1493,
     UNLOCK = 1494,
     UPDATE = 1495,
     VALUES = 1496,
     YELLOW = 1497,
     AFTER = 1498,
     KWLINE = 1499,
     KW_NULL = 1500,
     KW_TRUE = 1501,
     SINGLE_KEY = 1502,
     ALTER = 1503,
     ARRAY = 1504,
     ASCII = 1505,
     AUDIT = 1506,
     BLACK = 1507,
     BLINK = 1508,
     CHECK = 1509,
     CLEAR = 1510,
     CLOSE = 1511,
     CODE_C = 1512,
     COUNT = 1513,
     DEFER = 1514,
     ERROR = 1515,
     EVERY = 1516,
     FETCH = 1517,
     FIRST = 1518,
     FLOAT = 1519,
     FLUSH = 1520,
     FOUND = 1521,
     GRANT = 1522,
     GREEN = 1523,
     GROUP = 1524,
     INDEX = 1525,
     KWFORM = 1526,
     LABEL = 1527,
     LOCAL = 1529,
     MONEY = 1530,
     MONTH = 1531,
     ORDER = 1534,
     OUTER = 1535,
     PAUSE = 1536,
     PRINT_IMAGE = 1537,
     PRINT_FILE = 1538,
     PRINT = 1539,
     RIGHT = 1540,
     DOUBLE_COLON = 1541,
     SEMICOLON = 1542,
     SLEEP = 1543,
     TUPLE = 1544,
     UNION = 1545,
     WHERE = 1547,
     WHILE = 1548,
     WHITE = 1549,
     CCODE = 1550,
     ANSI = 1551,
     BLUE = 1552,
     BOLD = 1553,
     BYTE = 1554,
     FCALL = 1555,
     CASE = 1556,
     CYAN = 1557,
     DATE = 1558,
     DESC = 1559,
     KWDOWN = 1561,
     TAB = 1562,
     DROP = 1563,
     ELSE = 1564,
     EXEC = 1565,
     EXIT = 1566,
     FREE = 1567,
     FROM = 1568,
     GOTO = 1569,
     HELP_FILE = 1570,
     LANG_FILE = 1571,
     HELP = 1572,
     HIDE = 1573,
     HOUR = 1574,
     INTO = 1575,
     LAST = 1576,
     LEFT = 1577,
     LIKE = 1578,
     MAIN = 1579,
     MENU = 1580,
     MODE = 1581,
     NEED = 1582,
     NEXT = 1583,
     NOCR = 1584,
     OPEN = 1585,
     QUIT = 1586,
     REAL = 1587,
     ROWS = 1588,
     SHOW = 1589,
     SIZE = 1590,
     SKIP = 1591,
     SOME = 1592,
     STEP = 1593,
     STOP = 1594,
     TEMP = 1595,
     TEXT = 1596,
     THEN = 1597,
     USER = 1598,
     WAIT = 1599,
     WHEN = 1600,
     WITH = 1601,
     WORK = 1602,
     YEAR = 1603,
     KW_IS = 1605,
     XSET = 1606,
     ADD = 1607,
     ALL = 1608,
     ANY = 1610,
     ASC = 1611,
     AVG = 1612,
     COLON = 1613,
     DAY = 1615,
     DBA = 1616,
     DEC = 1617,
     DIM = 1618,
     FKEY = 1619,
     FOR = 1620,
     KEY = 1621,
     KWNO = 1622,
     LET = 1623,
     LOG = 1624,
     XMAX = 1625,
     XMIN = 1626,
     PAD = 1630,
     PUT = 1631,
     RED = 1632,
     ROW = 1633,
     RUN = 1634,
     SQL = 1635,
     SUM = 1636,
     TOP = 1637,
     USE = 1638,
     ATSIGN = 1639,
     AS_TIFF = 1641,
     AS_GIF = 1642,
     AS_PNG = 1643,
     AS_JPEG = 1644,
     AS = 1645,
     AT = 1646,
     BY = 1647,
     DOT = 1648,
     GO = 1649,
     IF = 1650,
     IN = 1651,
     OF = 1652,
     ON = 1653,
     TO = 1655,
     KWUP = 1656,
     FONT_NAME = 1657,
     FONT_SIZE = 1658,
     PAPER_SIZE_IS_LETTER = 1659,
     PAPER_SIZE_IS_LEGAL = 1660,
     PAPER_SIZE_IS_A5 = 1661,
     PAPER_SIZE_IS_A4 = 1662,
     PAPER_SIZE_IS_LETTER_L = 1663,
     PAPER_SIZE_IS_LEGAL_L = 1664,
     PAPER_SIZE_IS_A5_L = 1665,
     PAPER_SIZE_IS_A4_L = 1666,
     FORMHANDLER = 1667,
     END_FORMHANDLER = 1668,
     BEFORE_EVENT = 1669,
     BEFORE_OPEN_FORM = 1670,
     AFTER_EVENT = 1671,
     BEFORE_CLOSE_FORM = 1672,
     BEFORE_ANY = 1673,
     AFTER_ANY = 1674,
     MENUHANDLER = 1675,
     END_MENUHANDLER = 1676,
     BEFORE_SHOW_MENU = 1677,
     DISABLE_PROGRAM = 1678,
     DISABLE_ALL = 1679,
     BUTTONS = 1680,
     CHECK_MENUITEM = 1681,
     DISABLE_FORM = 1682,
     DISABLE_MENUITEMS = 1683,
     DISABLE = 1684,
     ENABLE_FORM = 1685,
     ENABLE_MENUITEMS = 1686,
     ENABLE = 1687,
     KWFIELD = 1688,
     ICON = 1689,
     MESSAGEBOX = 1690,
     TO_DEFAULTS = 1691,
     UNCHECK_MENUITEM = 1692,
     BEFORE = 1693,
     INPUT = 1694,
     END = 1695,
     INT_TO_ID = 1696,
     TIMEOUT = 1697,
     OFF = 1698,
     WITH_1_DIMENSION = 1699,
     WITH_2_DIMENSION = 1700,
     WITH_3_DIMENSION = 1701,
     TILDE = 1702,
     ILIKE = 1703,
     FGL_ISDYNARR_ALLOCATED = 1704,
     FGL_DYNARR_EXTENTSIZE = 1705,
     FILLFACTOR = 1706
   };
#endif
#define NAME 1708
#define UMINUS 1709
#define COMMA 1614
#define KW_OR 1654
#define KW_AND 1609
#define KW_USING 1546
#define NOT 1629
#define MATCHES 1426
#define POWER 1532
#define LESS_THAN 1528
#define GREATER_THAN 1443
#define EQUAL 1604
#define GREATER_THAN_EQ 1345
#define LESS_THAN_EQ 1402
#define NOT_EQUAL 1474
#define PLUS 1640
#define MINUS 1627
#define MULTIPLY 1533
#define DIVIDE 1560
#define MOD 1628
#define COMMAND 1409
#define NUMBER_VALUE 1710
#define CHAR_VALUE 1711
#define INT_VALUE 1712
#define NAMED_GEN 1713
#define CLINE 1714
#define SQLLINE 1715
#define KW_CSTART 1716
#define KW_CEND 1717
#define USER_DTYPE 1718
#define SQL_TEXT 1719
#define KW_WHENEVER_SET 1720
#define COMMENT 1721
#define DYNAMIC_ARRAY 1000
#define RESIZE_ARRAY 1001
#define ALLOCATE_ARRAY 1002
#define DEALLOCATE_ARRAY 1003
#define AFTER_INSERT_DELETE 1004
#define BEFORE_INSERT_DELETE 1005
#define BEFORE_INSERT 1006
#define CONCAT_PIPES 1007
#define BEFORE_DELETE 1008
#define DROP_TRIGGER 1009
#define AFTER_INSERT 1010
#define AFTER_DELETE 1011
#define EXECUTE_IMMEDIATE 1012
#define DELETE_ROW_EQUAL_TRUE 1013
#define INSERT_ROW_EQUAL_TRUE 1014
#define DELETE_ROW_EQUAL_FALSE 1015
#define INSERT_ROW_EQUAL_FALSE 1016
#define CURRENT_ROW_DISPLAY_EQUAL 1017
#define MAXCOUNT 1018
#define ALTER_TABLE 1019
#define ALTER_INDEX 1020
#define NEXT_SIZE 1021
#define DISPLAY_ATTR_FORM 1022
#define DISPLAY_ATTR_WINDOW 1023
#define INPUT_ATTR_FORM 1024
#define INPUT_ATTR_WINDOW 1025
#define WHENEVER_ERROR_CONTINUE 1026
#define WHENEVER_ANY_ERROR_CONTINUE 1027
#define WHENEVER_WARNING_CONTINUE 1028
#define WHENEVER_SQLSUCCESS_CONTINUE 1029
#define WHENEVER_SQLWARNING_CONTINUE 1030
#define WHENEVER_NOT_FOUND_CONTINUE 1031
#define WHENEVER_SQLERROR_CONTINUE 1032
#define WHENEVER_SUCCESS_CONTINUE 1033
#define WHENEVER_ERROR_GOTO 1034
#define WHENEVER_ANY_ERROR_GOTO 1035
#define WHENEVER_WARNING_GOTO 1036
#define WHENEVER_SQLSUCCESS_GOTO 1037
#define WHENEVER_SQLWARNING_GOTO 1038
#define WHENEVER_NOT_FOUND_GOTO 1039
#define WHENEVER_SQLERROR_GOTO 1040
#define WHENEVER_SUCCESS_GOTO 1041
#define WHENEVER_ERROR_CALL 1042
#define WHENEVER_ANY_ERROR_CALL 1043
#define WHENEVER_WARNING_CALL 1044
#define WHENEVER_SQLSUCCESS_CALL 1045
#define WHENEVER_SQLWARNING_CALL 1046
#define WHENEVER_NOT_FOUND_CALL 1047
#define WHENEVER_SQLERROR_CALL 1048
#define WHENEVER_SUCCESS_CALL 1049
#define WHENEVER_ERROR_STOP 1050
#define WHENEVER_ANY_ERROR_STOP 1051
#define WHENEVER_WARNING_STOP 1052
#define WHENEVER_SQLSUCCESS_STOP 1053
#define WHENEVER_SQLWARNING_STOP 1054
#define WHENEVER_NOT_FOUND_STOP 1055
#define WHENEVER_SQLERROR_STOP 1056
#define WHENEVER_SUCCESS_STOP 1057
#define XSET_MULTIPLY_EQUAL_OPEN_BRACKET 1058
#define XSET_ident_DOT_MULTIPLY_EQUAL_OPEN_BRACKET 1059
#define XSET_ident_DOT_MULTIPLY_EQUAL 1060
#define XSET_MULTIPLY_EQUAL 1061
#define XSET_OPEN_BRACKET 1062
#define NEWFORMATSHARED 1063
#define CREATE_DATABASE 1064
#define DROP_DATABASE 1065
#define IMPORT_LEGACY_FUNCTION 1066
#define ADD_CONSTRAINT 1067
#define DROP_CONSTRAINT 1068
#define DROP_SYNONYM 1069
#define CONSTRAINT 1070
#define AS_STATIC 1071
#define NOT_FIELD_TOUCHED 1072
#define LOCAL_FUNCTION 1073
#define EVERY_ROW 1074
#define ELIF 1075
#define DOUBLE_PRECISION 1076
#define COUNT_MULTIPLY 1077
#define WAIT_FOR_KEY 1078
#define AT_TERMINATION_CALL 1079
#define TERMINATE_REPORT 1080
#define TO_MAIN_CAPTION 1081
#define CLEARSTAT 1082
#define TO_MENUITEM 1083
#define ID_TO_INT 1084
#define TO_STATUSBOX 1085
#define ASCII_HEIGHT_ALL 1086
#define ASCII_WIDTH_ALL 1087
#define IMPORT_DATATYPE 1088
#define PAGE_TRAILER_SIZE 1089
#define PAGE_HEADER_SIZE 1090
#define FIRST_PAGE_HEADER_SIZE 1091
#define BYTES_USE_AS_IMAGE 1092
#define BYTES_USE_AS_ASCII 1093
#define KWUP_BY 1094
#define KWDOWN_BY 1095
#define CLOSE_STATUSBOX 1096
#define MODIFY_NEXT_SIZE 1097
#define LOCK_MODE_PAGE 1098
#define LOCK_MODE_ROW 1099
#define TO_PIPE 1100
#define TO_PRINTER 1101
#define STATUSBOX 1102
#define FORMHANDLER_INPUT 1103
#define UNITS_YEAR 1104
#define UNITS_MONTH 1105
#define UNITS_DAY 1106
#define UNITS_HOUR 1107
#define UNITS_MINUTE 1108
#define UNITS_SECOND 1109
#define NO_NEW_LINES 1110
#define FIELDTOWIDGET 1111
#define WITH_HOLD 1112
#define SHOW_MENU 1113
#define TO_CLUSTER 1114
#define TO_NOT_CLUSTER 1115
#define CWIS 1116
#define CREATE_IDX 1117
#define FORM_IS_COMPILED 1118
#define PDF_REPORT 1119
#define IMPORT_FUNCTION 1120
#define PROMPT_MANY 1121
#define POINTS 1122
#define MM 1123
#define INCHES 1124
#define PREPEND 1125
#define MEMBER_OF 1126
#define MEMBER_FUNCTION 1127
#define APPEND 1128
#define TEMPLATE 1129
#define END_TEMPLATE 1130
#define SQLSICS 1131
#define CREATE_SCHEMA 1132
#define SQLSIRR 1133
#define UPDATESTATS_T 1134
#define SQLSICR 1135
#define WHENEVER_SQLSUCCESS 1136
#define WHENEVER_SQLWARNING 1137
#define WHENEVER_ANY_ERROR 1138
#define WHENEVER_NOT_FOUND 1139
#define WHENEVER_SQLERROR 1140
#define WHENEVER_SUCCESS 1141
#define WHENEVER_ERROR 1142
#define START_EXTERN 1143
#define CONTINUE_CONSTRUCT 1144
#define FOUNCONSTR 1145
#define SQLSIDR 1146
#define CREATE_TEMP_TABLE 1147
#define CURRENT_WINDOW_IS 1148
#define FIRST_PAGE_HEADER 1149
#define ORDER_EXTERNAL_BY 1150
#define SCROLL_CURSOR_FOR 1151
#define SCROLL_CURSOR 1152
#define SQL_INTERRUPT_OFF 1153
#define STOP_ALL_EXTERNAL 1154
#define WITH_CHECK_OPTION 1155
#define WITH_GRANT_OPTION 1156
#define SQLSLMNW 1157
#define ADDCONSTUNIQ 1158
#define CONTINUE_DISPLAY 1159
#define CONTINUE_FOREACH 1160
#define OUTPUT_TO_REPORT 1161
#define SQL_INTERRUPT_ON 1162
#define WHERE_CURRENT_OF 1163
#define WITHOUT_DEFAULTS 1164
#define FOCONSTR 1165
#define SCALED_BY 1166
#define CONTINUE_PROMPT 1167
#define PDF_FUNCTION 1168
#define DEFER_INTERRUPT 1169
#define DISPLAY_BY_NAME 1170
#define NOT_NULL_UNIQUE 1171
#define SKIP_TO_TOP 1172
#define TOP_OF_PAGE 1173
#define SKIP_TO 1174
#define SKIP_BY 1175
#define WITHOUT_WAITING 1176
#define BEFCONSTRUCT 1177
#define SQLSLMW 1178
#define AFTCONSTRUCT 1179
#define ALL_PRIVILEGES 1180
#define CLOSE_DATABASE 1181
#define CONTINUE_INPUT 1182
#define CONTINUE_WHILE 1183
#define CREATE_SYNONYM 1184
#define DROP_TABLE 1185
#define EXIT_CONSTRUCT 1186
#define INEXCLUSIVE 1187
#define REPORT_TO_PRINTER 1188
#define REPORT_TO_PIPE 1189
#define RETURN 1190
#define SET_SESSION_TO 1191
#define UPDATESTATS 1192
#define WITHOUT_HEAD 1193
#define CLEARSCR 1194
#define WITH_B_LOG 1195
#define AUTHORIZATION 1196
#define BOTTOM_MARGIN 1197
#define CLOSE_SESSION 1198
#define CONTINUE_CASE 1199
#define CONTINUE_MENU 1200
#define DISPLAY_ARRAY 1201
#define END_SQL 1202
#define DOLLAR 1203
#define END_CONSTRUCT 1204
#define FIELD_TOUCHED 1205
#define FINISH_REPORT 1206
#define INFACC 1207
#define INPUT_NO_WRAP 1208
#define SETPMOFF 1209
#define UNCONSTRAINED 1210
#define PAGE_TRAILER 1211
#define SETPMON 1212
#define BEFGROUP 1213
#define CLOSE_WINDOW 1214
#define COMMENT_LINE 1215
#define CONTINUE_FOR 1216
#define CREATE_DB 1217
#define CREATE_TABLE 1218
#define DEFAULT_NULL 1219
#define DEFAULT_TODAY 1220
#define DEFAULT_USER 1221
#define DELETE_USING 1222
#define DISPLAY_FORM 1223
#define END_FUNCTION 1224
#define EXIT_DISPLAY 1225
#define EXIT_FOREACH 1226
#define EXIT_PROGRAM 1227
#define INFCOLS 1228
#define ON_EVERY_ROW 1229
#define OPEN_SESSION 1230
#define RIGHT_MARGIN 1231
#define SELECT_USING 1232
#define START_REPORT 1233
#define UNLOCK_TABLE 1234
#define UPDATE_USING 1235
#define ACL_BUILTIN 1236
#define AFTGROUP 1237
#define INFIDX 1238
#define INFSTAT 1239
#define LEFT_MARGIN 1240
#define PAGE_HEADER 1241
#define ROLLBACK_W 1242
#define SET_SESSION 1243
#define SQLSEOFF 1244
#define WITH_A_LOG 1245
#define BEFDISP 1246
#define BEFORE_MENU 1247
#define CREATE_VIEW 1248
#define DEFINE_TYPE 1249
#define DELETE_FROM 1250
#define END_DISPLAY 1251
#define END_REPORT 1252
#define END_FOREACH 1253
#define END_FOR 1254
#define END_GLOBALS 1255
#define EXIT_PROMPT 1256
#define EXTENT_SIZE 1257
#define FOREIGN_KEY 1258
#define HIDE_OPTION 1259
#define HIDE_WINDOW 1260
#define INSERT_INTO 1261
#define IS_NOT_NULL 1262
#define MOVE_WINDOW 1263
#define NEXT_OPTION 1264
#define NOT_MATCHES 1265
#define ON_LAST_ROW 1266
#define OPEN_WINDOW 1267
#define OPEN_STATUSBOX 1268
#define PAGE_LENGTH 1269
#define PAGE_WIDTH 1270
#define PRIMARY_KEY 1271
#define PROMPT_LINE 1272
#define RECORD_LIKE 1273
#define ROLLFORWARD 1274
#define SETBL 1275
#define SHOW_OPTION 1276
#define SHOW_WINDOW 1277
#define SQLSEON 1278
#define TO_DATABASE 1279
#define USE_SESSION 1280
#define WITH_NO_LOG 1281
#define AFTDISP 1282
#define BEFFIELD 1283
#define INSHARE 1284
#define UNLOCKTAB 1285
#define AFTFIELD 1286
#define ATTRIBUTES 1287
#define BEFINP 1288
#define BEGIN_WORK 1289
#define CLEARWIN 1290
#define CLOSE_FORM 1291
#define DEFER_QUIT 1292
#define DESCENDING 1293
#define DROP_INDEX 1294
#define END_PROMPT 1295
#define END_RECORD 1296
#define ERROR_LINE 1297
#define EXIT_INPUT 1298
#define EXIT_WHILE 1299
#define FOR_UPDATE_OF 1300
#define FOR_UPDATE 1301
#define GET_FLDBUF 1302
#define INITIALIZE 1303
#define INPUT_WRAP 1304
#define LOCK_TABLE 1305
#define MSG_LINE 1306
#define NOT_EXISTS 1307
#define ON_ANY_KEY 1308
#define REFERENCES 1309
#define RENCOL 1310
#define SET_CURSOR 1311
#define SMALLFLOAT 1312
#define SQLSUCCESS 1313
#define TOP_MARGIN 1314
#define WITH_ARRAY 1315
#define ACCEPTKEY 1316
#define ACCEPT 1317
#define AFTINP 1318
#define CLEARFORMTODEFAULTS 1319
#define CLEARFORM 1320
#define CLEAR_X_FORM 1321
#define COMMIT_W 1322
#define NEXTPAGE 1323
#define PREVPAGE 1324
#define CTRL_KEY 1325
#define INFTABS 1326
#define NEXTFIELD 1327
#define NEXTFORM 1328
#define RENTAB 1329
#define ASCENDING 1330
#define ASSOCIATE 1331
#define CHAR 1332
#define NCHAR 1333
#define NVARCHAR 1334
#define CONSTRUCT 1335
#define DELIMITER 1336
#define DOWNSHIFT 1337
#define DROP_VIEW 1338
#define END_INPUT 1339
#define END_WHILE 1340
#define EXCLUSIVE 1341
#define EXIT_CASE 1342
#define EXIT_MENU 1343
#define FORM_LINE 1344
#define INTERRUPT 1346
#define INTO_TEMP 1347
#define INVISIBLE 1348
#define IN_MEMORY 1349
#define LINKED_TO 1350
#define LOAD_FROM 1351
#define LOCKTAB 1352
#define MENU_LINE 1353
#define OPEN_FORM 1354
#define OTHERWISE 1355
#define PRECISION 1356
#define PRIOR 1357
#define PROCEDURE 1358
#define REPORT_TO 1359
#define RETURNING 1360
#define UNDERLINE 1361
#define UNLOAD_TO 1362
#define BEFROW 1363
#define UNLOAD_T 1364
#define VARIABLE 1365
#define ABSOLUTE 1366
#define AFTROW 1367
#define BUFFERED 1368
#define CONSTANT 1369
#define CONST 1370
#define DATABASE 1371
#define DATETIME 1372
#define DEFAULTS 1373
#define DISTINCT 1374
#define END_CASE 1375
#define END_MAIN 1376
#define END_MENU 1377
#define END_TYPE 1378
#define EXIT_FOR 1379
#define EXTERNAL 1380
#define FRACTION 1381
#define FUNCTION 1382
#define GROUP_BY 1383
#define INTERVAL 1384
#define KWMESSAGE 1385
#define NOT_LIKE 1386
#define NOT_ILIKE 1387
#define NOT_NULL 1388
#define PASSWORD 1389
#define PREVIOUS 1390
#define READONLY 1391
#define REGISTER 1392
#define RELATIVE 1393
#define RESOURCE 1394
#define SMALLINT 1395
#define VALIDATE 1396
#define WITH_LOG 1397
#define WORDWRAP 1398
#define BY_NAME 1399
#define IN_FILE 1400
#define IS_NULL 1401
#define AVERAGE 1403
#define BETWEEN 1404
#define CAPTION 1405
#define CLIPPED 1406
#define CLOSE_BRACKET 1407
#define COLUMNS 1408
#define CONNECT 1410
#define CURRENT 1411
#define DBYNAME 1412
#define DECIMAL 1413
#define DECLARE 1414
#define DEFAULT 1415
#define DISPLAY 1416
#define ENDCODE 1417
#define EXECUTE 1418
#define FOREACH 1419
#define FOREIGN 1420
#define GLOBALS 1421
#define INFIELD 1422
#define INTEGER 1423
#define KWWINDOW 1424
#define MAGENTA 1425
#define OPTIONS 1427
#define PERCENT 1428
#define PREPARE 1429
#define PROGRAM 1430
#define RECOVER 1431
#define REVERSE 1432
#define SECTION 1433
#define SESSION 1434
#define SYNONYM 1435
#define THRU 1436
#define TRAILER 1437
#define UPSHIFT 1438
#define VARCHAR 1439
#define WAITING 1440
#define CLOSE_SHEV 1441
#define CLOSE_SQUARE 1442
#define KW_FALSE 1444
#define NOT_IN 1445
#define ONKEY 1446
#define OPEN_BRACKET 1447
#define BORDER 1448
#define BOTTOM 1449
#define COLUMN 1450
#define COMMIT 1451
#define CREATE 1452
#define CURSOR 1453
#define DEFINE 1454
#define DELETE 1455
#define DOUBLE 1456
#define END_IF 1457
#define ESCAPE 1458
#define EXISTS 1459
#define EXTEND 1460
#define EXTENT 1461
#define FINISH 1462
#define FORMAT 1463
#define HAVING 1464
#define HEADER 1465
#define INSERT 1466
#define LOCATE 1467
#define MARGIN 1468
#define MEMORY 1469
#define MINUTE 1470
#define MODIFY 1471
#define NORMAL 1472
#define EQUAL_EQUAL 1473
#define OPEN_SHEV 1475
#define OPEN_SQUARE 1476
#define OPTION 1477
#define OUTPUT 1478
#define PROMPT 1479
#define PUBLIC 1480
#define RECORD 1481
#define REPORT 1482
#define REVOKE 1483
#define SCHEMA 1484
#define SCROLL_USING 1485
#define SCROLL 1486
#define SECOND 1487
#define SELECT 1488
#define SERIAL 1489
#define SETL 1490
#define SHARED 1491
#define SPACES 1492
#define UNIQUE 1493
#define UNLOCK 1494
#define UPDATE 1495
#define VALUES 1496
#define YELLOW 1497
#define AFTER 1498
#define KWLINE 1499
#define KW_NULL 1500
#define KW_TRUE 1501
#define SINGLE_KEY 1502
#define ALTER 1503
#define ARRAY 1504
#define ASCII 1505
#define AUDIT 1506
#define BLACK 1507
#define BLINK 1508
#define CHECK 1509
#define CLEAR 1510
#define CLOSE 1511
#define CODE_C 1512
#define COUNT 1513
#define DEFER 1514
#define ERROR 1515
#define EVERY 1516
#define FETCH 1517
#define FIRST 1518
#define FLOAT 1519
#define FLUSH 1520
#define FOUND 1521
#define GRANT 1522
#define GREEN 1523
#define GROUP 1524
#define INDEX 1525
#define KWFORM 1526
#define LABEL 1527
#define LOCAL 1529
#define MONEY 1530
#define MONTH 1531
#define ORDER 1534
#define OUTER 1535
#define PAUSE 1536
#define PRINT_IMAGE 1537
#define PRINT_FILE 1538
#define PRINT 1539
#define RIGHT 1540
#define DOUBLE_COLON 1541
#define SEMICOLON 1542
#define SLEEP 1543
#define TUPLE 1544
#define UNION 1545
#define WHERE 1547
#define WHILE 1548
#define WHITE 1549
#define CCODE 1550
#define ANSI 1551
#define BLUE 1552
#define BOLD 1553
#define BYTE 1554
#define FCALL 1555
#define CASE 1556
#define CYAN 1557
#define DATE 1558
#define DESC 1559
#define KWDOWN 1561
#define TAB 1562
#define DROP 1563
#define ELSE 1564
#define EXEC 1565
#define EXIT 1566
#define FREE 1567
#define FROM 1568
#define GOTO 1569
#define HELP_FILE 1570
#define LANG_FILE 1571
#define HELP 1572
#define HIDE 1573
#define HOUR 1574
#define INTO 1575
#define LAST 1576
#define LEFT 1577
#define LIKE 1578
#define MAIN 1579
#define MENU 1580
#define MODE 1581
#define NEED 1582
#define NEXT 1583
#define NOCR 1584
#define OPEN 1585
#define QUIT 1586
#define REAL 1587
#define ROWS 1588
#define SHOW 1589
#define SIZE 1590
#define SKIP 1591
#define SOME 1592
#define STEP 1593
#define STOP 1594
#define TEMP 1595
#define TEXT 1596
#define THEN 1597
#define USER 1598
#define WAIT 1599
#define WHEN 1600
#define WITH 1601
#define WORK 1602
#define YEAR 1603
#define KW_IS 1605
#define XSET 1606
#define ADD 1607
#define ALL 1608
#define ANY 1610
#define ASC 1611
#define AVG 1612
#define COLON 1613
#define DAY 1615
#define DBA 1616
#define DEC 1617
#define DIM 1618
#define FKEY 1619
#define FOR 1620
#define KEY 1621
#define KWNO 1622
#define LET 1623
#define LOG 1624
#define XMAX 1625
#define XMIN 1626
#define PAD 1630
#define PUT 1631
#define RED 1632
#define ROW 1633
#define RUN 1634
#define SQL 1635
#define SUM 1636
#define TOP 1637
#define USE 1638
#define ATSIGN 1639
#define AS_TIFF 1641
#define AS_GIF 1642
#define AS_PNG 1643
#define AS_JPEG 1644
#define AS 1645
#define AT 1646
#define BY 1647
#define DOT 1648
#define GO 1649
#define IF 1650
#define IN 1651
#define OF 1652
#define ON 1653
#define TO 1655
#define KWUP 1656
#define FONT_NAME 1657
#define FONT_SIZE 1658
#define PAPER_SIZE_IS_LETTER 1659
#define PAPER_SIZE_IS_LEGAL 1660
#define PAPER_SIZE_IS_A5 1661
#define PAPER_SIZE_IS_A4 1662
#define PAPER_SIZE_IS_LETTER_L 1663
#define PAPER_SIZE_IS_LEGAL_L 1664
#define PAPER_SIZE_IS_A5_L 1665
#define PAPER_SIZE_IS_A4_L 1666
#define FORMHANDLER 1667
#define END_FORMHANDLER 1668
#define BEFORE_EVENT 1669
#define BEFORE_OPEN_FORM 1670
#define AFTER_EVENT 1671
#define BEFORE_CLOSE_FORM 1672
#define BEFORE_ANY 1673
#define AFTER_ANY 1674
#define MENUHANDLER 1675
#define END_MENUHANDLER 1676
#define BEFORE_SHOW_MENU 1677
#define DISABLE_PROGRAM 1678
#define DISABLE_ALL 1679
#define BUTTONS 1680
#define CHECK_MENUITEM 1681
#define DISABLE_FORM 1682
#define DISABLE_MENUITEMS 1683
#define DISABLE 1684
#define ENABLE_FORM 1685
#define ENABLE_MENUITEMS 1686
#define ENABLE 1687
#define KWFIELD 1688
#define ICON 1689
#define MESSAGEBOX 1690
#define TO_DEFAULTS 1691
#define UNCHECK_MENUITEM 1692
#define BEFORE 1693
#define INPUT 1694
#define END 1695
#define INT_TO_ID 1696
#define TIMEOUT 1697
#define OFF 1698
#define WITH_1_DIMENSION 1699
#define WITH_2_DIMENSION 1700
#define WITH_3_DIMENSION 1701
#define TILDE 1702
#define ILIKE 1703
#define FGL_ISDYNARR_ALLOCATED 1704
#define FGL_DYNARR_EXTENTSIZE 1705
#define FILLFACTOR 1706




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
#line 1700 "y.tab.c"
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 214 of yacc.c.  */
#line 1712 "y.tab.c"

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
#define YYLAST   11247

/* YYNTOKENS -- Number of terminals. */
#define YYNTOKENS  724
/* YYNNTS -- Number of nonterminals. */
#define YYNNTS  864
/* YYNRULES -- Number of rules. */
#define YYNRULES  2353
/* YYNRULES -- Number of states. */
#define YYNSTATES  3761

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   1721

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
     376,   377,   378,   379,   380,    15,   381,   382,   383,   384,
     385,   386,   387,   388,   389,   390,   391,   392,   393,   394,
     395,   396,   397,   398,   399,   400,   401,   402,   403,   404,
     405,   406,   407,   408,   409,   410,   411,   412,   413,   414,
     415,   416,   417,   418,   419,   420,   421,   422,   423,   424,
     425,   426,   427,   428,   429,   430,   431,   432,   433,   434,
     435,   436,    16,   437,   438,   439,   440,   441,   442,    23,
     443,   444,   445,   446,   447,   448,   449,   450,   451,   452,
     453,   454,   455,   456,   457,   458,    10,   459,   460,   461,
     462,   463,   464,   465,   466,   467,   468,   469,   470,   471,
     472,   473,   474,    13,   475,   476,   477,   478,   479,   480,
     481,   482,   483,   484,   485,   486,   487,   488,   489,   490,
     491,   492,   493,   494,   495,   496,   497,   498,   499,   500,
     501,   502,   503,   504,    17,   505,   506,   507,   508,   509,
     510,   511,   512,   513,   514,   515,   516,   517,   518,   519,
     520,   521,   522,   523,   524,   525,   526,   527,   528,   529,
     530,   531,   532,   533,   534,   535,   536,   537,   538,   539,
     540,   541,   542,   543,   544,   545,   546,   547,   548,   549,
     550,   551,   552,   553,   554,   555,   556,   557,    12,   558,
     559,   560,    11,    20,   561,   562,   563,   564,   565,   566,
     567,   568,   569,   570,   571,   572,     8,   573,   574,   575,
     576,   577,   578,   579,   580,   581,   582,   583,   584,   585,
      21,   586,   587,   588,   589,   590,   591,   592,   593,   594,
     595,   596,   597,   598,   599,   600,   601,   602,   603,   604,
     605,   606,   607,   608,   609,   610,   611,   612,   613,   614,
     615,   616,   617,   618,   619,   620,   621,   622,   623,   624,
     625,   626,   627,   628,    14,   629,   630,   631,   632,     7,
     633,   634,   635,   636,     5,   637,   638,   639,   640,   641,
     642,   643,   644,   645,   646,   647,   648,    19,    22,     9,
     649,   650,   651,   652,   653,   654,   655,   656,   657,   658,
      18,   659,   660,   661,   662,   663,   664,   665,   666,   667,
     668,   669,   670,   671,     6,   672,   673,   674,   675,   676,
     677,   678,   679,   680,   681,   682,   683,   684,   685,   686,
     687,   688,   689,   690,   691,   692,   693,   694,   695,   696,
     697,   698,   699,   700,   701,   702,   703,   704,   705,   706,
     707,   708,   709,   710,   711,   712,   713,   714,   715,   716,
     717,   718,   719,   720,   721,   722,   723,     2,     3,     4,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35
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
    1115,  1118,  1123,  1129,  1131,  1133,  1135,  1137,  1139,  1141,
    1143,  1145,  1147,  1149,  1151,  1153,  1155,  1157,  1159,  1161,
    1163,  1165,  1168,  1170,  1172,  1174,  1176,  1179,  1181,  1183,
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
    1679,  1691,  1692,  1695,  1696,  1697,  1698,  1708,  1709,  1713,
    1714,  1715,  1726,  1727,  1729,  1730,  1732,  1734,  1737,  1738,
    1742,  1743,  1747,  1748,  1750,  1752,  1755,  1756,  1760,  1761,
    1765,  1769,  1771,  1776,  1780,  1782,  1786,  1788,  1792,  1794,
    1798,  1800,  1803,  1804,  1808,  1809,  1813,  1814,  1819,  1820,
    1825,  1826,  1831,  1834,  1838,  1840,  1844,  1846,  1848,  1850,
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
    2271,  2275,  2278,  2281,  2283,  2285,  2286,  2289,  2291,  2294,
    2298,  2302,  2306,  2310,  2312,  2314,  2316,  2318,  2319,  2323,
    2325,  2326,  2330,  2333,  2336,  2338,  2342,  2344,  2348,  2350,
    2352,  2354,  2356,  2358,  2360,  2362,  2364,  2366,  2368,  2370,
    2372,  2374,  2376,  2378,  2380,  2382,  2384,  2386,  2388,  2389,
    2390,  2398,  2400,  2402,  2405,  2408,  2411,  2415,  2420,  2421,
    2425,  2426,  2428,  2430,  2433,  2435,  2437,  2439,  2441,  2443,
    2445,  2446,  2448,  2450,  2453,  2456,  2458,  2460,  2462,  2464,
    2466,  2468,  2470,  2472,  2474,  2476,  2478,  2479,  2481,  2483,
    2485,  2487,  2488,  2489,  2490,  2491,  2505,  2507,  2508,  2509,
    2516,  2519,  2521,  2524,  2527,  2530,  2532,  2534,  2537,  2539,
    2540,  2544,  2547,  2549,  2551,  2553,  2554,  2555,  2556,  2571,
    2572,  2578,  2580,  2581,  2585,  2586,  2594,  2595,  2601,  2603,
    2606,  2607,  2609,  2611,  2613,  2614,  2616,  2618,  2621,  2624,
    2627,  2629,  2631,  2633,  2635,  2639,  2641,  2643,  2644,  2645,
    2653,  2655,  2658,  2659,  2663,  2664,  2669,  2672,  2673,  2676,
    2678,  2680,  2682,  2684,  2686,  2688,  2690,  2694,  2695,  2697,
    2699,  2701,  2703,  2706,  2709,  2712,  2718,  2727,  2729,  2731,
    2733,  2738,  2743,  2745,  2747,  2749,  2751,  2754,  2758,  2765,
    2767,  2771,  2773,  2775,  2777,  2781,  2788,  2798,  2800,  2802,
    2804,  2806,  2809,  2810,  2812,  2814,  2818,  2820,  2824,  2826,
    2830,  2832,  2836,  2838,  2840,  2842,  2844,  2848,  2850,  2854,
    2856,  2860,  2862,  2864,  2866,  2870,  2873,  2874,  2876,  2878,
    2880,  2884,  2886,  2890,  2898,  2899,  2907,  2908,  2915,  2919,
    2921,  2925,  2927,  2930,  2936,  2937,  2945,  2946,  2949,  2950,
    2952,  2958,  2961,  2967,  2968,  2974,  2981,  2986,  2987,  2989,
    2991,  2997,  2998,  3001,  3002,  3008,  3013,  3016,  3018,  3022,
    3025,  3028,  3031,  3034,  3037,  3040,  3042,  3045,  3048,  3051,
    3054,  3057,  3060,  3063,  3065,  3067,  3069,  3071,  3074,  3077,
    3079,  3081,  3083,  3085,  3087,  3089,  3095,  3097,  3099,  3102,
    3107,  3112,  3119,  3122,  3124,  3125,  3137,  3138,  3141,  3147,
    3148,  3150,  3151,  3154,  3156,  3159,  3160,  3164,  3166,  3167,
    3172,  3173,  3176,  3178,  3182,  3184,  3186,  3190,  3195,  3200,
    3203,  3205,  3207,  3209,  3210,  3212,  3220,  3223,  3226,  3229,
    3232,  3235,  3237,  3240,  3241,  3245,  3246,  3250,  3251,  3255,
    3256,  3260,  3261,  3265,  3266,  3271,  3272,  3277,  3279,  3281,
    3283,  3285,  3287,  3289,  3290,  3295,  3296,  3298,  3299,  3304,
    3306,  3309,  3312,  3315,  3316,  3318,  3320,  3323,  3326,  3327,
    3330,  3331,  3336,  3340,  3346,  3347,  3350,  3355,  3357,  3359,
    3361,  3363,  3365,  3366,  3368,  3370,  3374,  3377,  3383,  3386,
    3392,  3398,  3404,  3410,  3416,  3422,  3423,  3426,  3428,  3431,
    3434,  3437,  3440,  3443,  3446,  3448,  3451,  3454,  3457,  3460,
    3462,  3465,  3468,  3471,  3474,  3476,  3478,  3480,  3481,  3484,
    3487,  3490,  3493,  3496,  3499,  3502,  3505,  3508,  3510,  3512,
    3514,  3516,  3518,  3520,  3522,  3524,  3527,  3530,  3533,  3536,
    3539,  3541,  3543,  3545,  3546,  3550,  3553,  3554,  3555,  3556,
    3557,  3558,  3559,  3575,  3576,  3579,  3582,  3583,  3585,  3586,
    3587,  3588,  3589,  3590,  3591,  3607,  3610,  3611,  3612,  3613,
    3624,  3625,  3627,  3631,  3635,  3638,  3643,  3647,  3651,  3655,
    3657,  3660,  3663,  3666,  3669,  3671,  3673,  3674,  3675,  3684,
    3685,  3686,  3696,  3697,  3699,  3701,  3704,  3707,  3710,  3713,
    3715,  3717,  3719,  3720,  3722,  3724,  3727,  3730,  3733,  3742,
    3745,  3748,  3753,  3756,  3757,  3759,  3761,  3765,  3768,  3771,
    3773,  3775,  3779,  3781,  3783,  3786,  3788,  3792,  3796,  3800,
    3802,  3806,  3808,  3810,  3812,  3814,  3816,  3818,  3820,  3823,
    3828,  3830,  3834,  3836,  3840,  3843,  3848,  3850,  3854,  3856,
    3859,  3864,  3866,  3870,  3872,  3874,  3876,  3879,  3883,  3888,
    3891,  3896,  3897,  3900,  3903,  3908,  3910,  3914,  3916,  3918,
    3920,  3923,  3925,  3927,  3929,  3931,  3933,  3936,  3943,  3950,
    3951,  3953,  3954,  3956,  3959,  3961,  3962,  3968,  3969,  3975,
    3977,  3978,  3982,  3984,  3988,  3990,  3994,  3996,  3998,  3999,
    4004,  4006,  4009,  4011,  4012,  4013,  4017,  4018,  4019,  4023,
    4025,  4027,  4029,  4031,  4033,  4035,  4038,  4041,  4046,  4050,
    4054,  4056,  4060,  4063,  4065,  4067,  4068,  4070,  4072,  4074,
    4076,  4077,  4079,  4083,  4085,  4089,  4091,  4092,  4096,  4098,
    4100,  4102,  4104,  4106,  4108,  4110,  4112,  4114,  4116,  4118,
    4120,  4128,  4135,  4140,  4145,  4147,  4149,  4151,  4152,  4154,
    4157,  4159,  4161,  4163,  4165,  4169,  4172,  4174,  4176,  4179,
    4181,  4183,  4184,  4188,  4190,  4194,  4196,  4200,  4202,  4204,
    4211,  4212,  4216,  4218,  4222,  4223,  4225,  4230,  4236,  4239,
    4241,  4243,  4248,  4250,  4254,  4259,  4264,  4269,  4271,  4275,
    4277,  4279,  4281,  4284,  4286,  4288,  4290,  4295,  4296,  4298,
    4299,  4301,  4303,  4306,  4309,  4311,  4313,  4315,  4317,  4319,
    4324,  4326,  4330,  4332,  4334,  4336,  4339,  4341,  4343,  4346,
    4349,  4351,  4355,  4358,  4361,  4363,  4367,  4369,  4372,  4377,
    4379,  4382,  4384,  4388,  4393,  4394,  4396,  4397,  4399,  4400,
    4402,  4404,  4408,  4410,  4414,  4416,  4419,  4421,  4425,  4428,
    4431,  4432,  4435,  4437,  4439,  4445,  4449,  4455,  4459,  4461,
    4465,  4467,  4469,  4470,  4472,  4476,  4480,  4484,  4491,  4496,
    4501,  4506,  4511,  4517,  4519,  4521,  4523,  4525,  4527,  4529,
    4531,  4533,  4535,  4537,  4539,  4541,  4542,  4544,  4546,  4548,
    4550,  4552,  4554,  4556,  4561,  4562,  4564,  4569,  4571,  4577,
    4583,  4585,  4587,  4589,  4591,  4593,  4598,  4600,  4605,  4612,
    4617,  4619,  4624,  4626,  4634,  4636,  4638,  4640,  4645,  4652,
    4653,  4656,  4661,  4663,  4665,  4667,  4669,  4671,  4673,  4675,
    4679,  4681,  4683,  4687,  4693,  4697,  4703,  4711,  4715,  4717,
    4719,  4723,  4729,  4733,  4739,  4747,  4749,  4750,  4754,  4760,
    4762,  4765,  4768,  4773,  4777,  4779,  4781,  4783,  4785,  4787,
    4790,  4793,  4794,  4798,  4799,  4803,  4805,  4807,  4809,  4811,
    4813,  4815,  4817,  4822,  4824,  4826,  4828,  4830,  4832,  4834,
    4836,  4841,  4843,  4845,  4847,  4849,  4851,  4853,  4855,  4857,
    4859,  4861,  4863,  4865,  4867,  4869,  4874,  4876,  4880,  4882,
    4886,  4887,  4895,  4896,  4905,  4906,  4913,  4914,  4923,  4924,
    4926,  4929,  4931,  4935,  4937,  4941,  4947,  4949,  4951,  4953,
    4955,  4957,  4958,  4959,  4969,  4975,  4977,  4979,  4986,  4987,
    4991,  4993,  4997,  5002,  5004,  5005,  5008,  5013,  5020,  5021,
    5023,  5025,  5027,  5029,  5033,  5035,  5038,  5042,  5044,  5046,
    5049,  5052,  5054,  5056,  5058,  5061,  5064,  5067,  5070,  5075,
    5079,  5082,  5086,  5090,  5094,  5096,  5098,  5100,  5102,  5104,
    5106,  5112,  5118,  5124,  5130,  5136,  5141,  5146,  5150,  5155,
    5157,  5159,  5161,  5165,  5167,  5173,  5181,  5187,  5188,  5191,
    5193,  5195,  5196,  5200,  5202,  5206,  5208,  5210,  5212,  5213,
    5217,  5219,  5221,  5223,  5225,  5230,  5237,  5239,  5241,  5244,
    5248,  5250,  5252,  5254,  5256,  5258,  5260,  5262,  5264,  5270,
    5276,  5281,  5287,  5289,  5294,  5299,  5304,  5311,  5318,  5327,
    5336,  5350,  5362,  5364,  5372,  5377,  5382,  5387,  5394,  5401,
    5410,  5419,  5420,  5425,  5427,  5430,  5432,  5434,  5436,  5438,
    5440,  5442,  5444,  5446,  5448,  5450,  5452,  5454,  5456,  5458,
    5460,  5462,  5464,  5466,  5468,  5470,  5472,  5474,  5476,  5478,
    5480,  5482,  5484,  5486,  5488,  5490,  5492,  5494,  5496,  5498,
    5500,  5502,  5504,  5506,  5508,  5510,  5512,  5514,  5516,  5518,
    5520,  5522,  5524,  5526,  5528,  5530,  5532,  5534,  5536,  5538,
    5540,  5542,  5544,  5546,  5548,  5550,  5552,  5554,  5556,  5558,
    5560,  5562,  5564,  5566,  5568,  5570,  5572,  5574,  5576,  5578,
    5580,  5582,  5584,  5586,  5588,  5590,  5592,  5594,  5596,  5598,
    5600,  5602,  5604,  5606,  5608,  5610,  5612,  5614,  5616,  5618,
    5620,  5622,  5624,  5626,  5628,  5630,  5632,  5634,  5636,  5638,
    5640,  5642,  5644,  5646,  5648,  5650,  5652,  5654,  5656,  5658,
    5660,  5662,  5664,  5666,  5668,  5670,  5672,  5674,  5676,  5678,
    5680,  5682,  5684,  5686,  5688,  5690,  5692,  5694,  5696,  5698,
    5700,  5702,  5704,  5706,  5708,  5710,  5712,  5714,  5716,  5718,
    5720,  5722,  5724,  5726,  5728,  5730,  5732,  5734,  5736,  5738,
    5740,  5742,  5744,  5746,  5748,  5750,  5752,  5754,  5756,  5758,
    5760,  5762,  5764,  5766,  5768,  5770,  5772,  5774,  5776,  5778,
    5780,  5782,  5784,  5786,  5788,  5790,  5792,  5794,  5796,  5798,
    5800,  5802,  5804,  5806,  5808,  5810,  5812,  5814,  5816,  5818,
    5820,  5822,  5824,  5826,  5828,  5830,  5832,  5834,  5836,  5838,
    5840,  5842,  5844,  5846,  5848,  5850,  5852,  5854,  5856,  5858,
    5860,  5862,  5864,  5866,  5868,  5870,  5872,  5874,  5876,  5878,
    5880,  5882,  5884,  5886,  5888,  5890,  5892,  5894,  5896,  5898,
    5900,  5902,  5904,  5906,  5908,  5910,  5912,  5914,  5916,  5918,
    5920,  5922,  5924,  5926,  5928,  5930,  5932,  5934,  5936,  5938,
    5940,  5942,  5944,  5946,  5948,  5950,  5952,  5954,  5956,  5958,
    5960,  5962,  5964,  5966,  5968,  5970,  5972,  5974,  5976,  5978,
    5980,  5982,  5984,  5986,  5988,  5990,  5992,  5994,  5996,  5998,
    6000,  6002,  6004,  6006,  6008,  6010,  6012,  6014,  6016,  6018,
    6020,  6022,  6024,  6026,  6028,  6030,  6032,  6034,  6036,  6038,
    6040,  6042,  6044,  6046,  6048,  6050,  6052,  6054,  6056,  6058,
    6060,  6062,  6064,  6066,  6067,  6071,  6072,  6076,  6077,  6078,
    6085,  6086,  6089,  6092,  6100,  6104,  6108,  6111,  6114,  6117,
    6119,  6123,  6125,  6129,  6131,  6135,  6137,  6141,  6143,  6145,
    6147,  6150,  6153,  6155,  6157,  6160,  6165,  6171,  6179,  6187,
    6197,  6199,  6201,  6203,  6205,  6207,  6209,  6213,  6216,  6220,
    6224,  6228,  6234,  6240,  6246,  6252,  6258,  6263,  6268,  6272,
    6277,  6279,  6281,  6283,  6285,  6289,  6290,  6296,  6298,  6302,
    6306,  6310,  6312,  6314,  6317,  6319,  6321,  6325,  6327,  6331,
    6335,  6337,  6339,  6341,  6345,  6348,  6352,  6359,  6361,  6365,
    6367,  6369,  6370,  6371,  6378,  6379,  6382,  6383,  6385,  6387,
    6390,  6393,  6395,  6397,  6402,  6406,  6408,  6411,  6417,  6420,
    6423,  6429,  6430,  6433,  6435,  6437,  6440,  6447,  6454,  6456,
    6457,  6459,  6462,  6464,  6467,  6468,  6471,  6473,  6475,  6477,
    6479,  6481,  6483,  6485,  6487,  6489,  6491,  6493,  6495,  6497,
    6499,  6501,  6503,  6505,  6507,  6509,  6511,  6513,  6515,  6517,
    6519,  6521,  6523,  6525,  6527,  6529,  6531,  6533,  6535,  6537,
    6539,  6541,  6543,  6545,  6547,  6549,  6551,  6553,  6555,  6557,
    6559,  6561,  6563,  6565,  6567,  6569,  6571,  6573,  6575,  6577,
    6579,  6581,  6583,  6585,  6587,  6589,  6591,  6593,  6595,  6597,
    6599,  6601,  6603,  6605,  6607,  6609,  6611,  6613,  6615,  6617,
    6619,  6621,  6623,  6625,  6627,  6629,  6631,  6633,  6635,  6637,
    6639,  6641,  6643,  6645
};

/* YYRHS -- A `-1'-separated list of the rules' RHS. */
static const short yyrhs[] =
{
    1096,     0,    -1,   248,    -1,   245,    -1,   179,   729,   474,
     642,   730,    -1,   190,    -1,  1161,    -1,    26,    -1,   731,
      -1,   730,     5,   731,    -1,  1004,    -1,   478,   732,   441,
      -1,   732,   733,   732,    -1,    26,    -1,   734,    26,    -1,
    1161,    -1,   944,    -1,    18,    -1,    19,    -1,    20,    -1,
      21,    -1,    22,    -1,    18,    -1,    19,    -1,    -1,   736,
      -1,    -1,   323,   478,   737,   738,   441,    -1,   615,   478,
      26,     5,    26,   441,    -1,   739,    -1,   738,     5,   739,
      -1,   537,    -1,   578,    -1,   583,    -1,   553,    -1,   458,
      -1,   651,    -1,   575,    -1,   527,    -1,   464,    -1,   538,
      -1,   396,    -1,   579,    -1,   503,    -1,   383,    -1,   640,
      -1,   146,    -1,  1075,    -1,    -1,   741,    -1,    -1,   323,
     478,   742,   743,   441,    -1,   744,    -1,   743,     5,   744,
      -1,   739,    -1,   479,    -1,   649,    25,    -1,   251,   990,
      -1,   380,   990,    -1,   333,   990,    -1,   388,   990,    -1,
     342,   990,    -1,   308,   990,    -1,   581,   746,    -1,   933,
     395,  1161,    -1,    -1,   338,   478,   952,   441,   395,   747,
    1179,    -1,   154,   478,  1004,     5,    25,     5,    25,   441,
      -1,   455,   478,   996,   441,   395,  1161,    -1,  1298,    -1,
     241,   478,   952,   441,   395,  1161,    -1,    -1,    -1,  1161,
     636,  1004,   478,   748,   762,   441,   749,   760,    -1,    -1,
      -1,    -1,  1004,   478,   750,   762,   751,   441,   752,   760,
      -1,    -1,    -1,   521,  1507,   669,  1507,   478,   753,   762,
     754,   441,   760,    -1,    -1,    -1,  1004,   568,  1004,   478,
     755,   762,   756,   441,   760,    -1,    -1,    -1,    -1,   415,
     765,   636,   766,   506,   729,   474,   478,   757,   762,   758,
     441,   759,   761,    -1,    -1,   395,  1179,    -1,    -1,   395,
    1179,    -1,   212,    -1,    -1,   763,    -1,   764,    -1,   763,
       5,   764,    -1,   902,    -1,   530,    -1,    25,    -1,  1004,
      -1,  1004,    -1,  1004,   666,  1004,    -1,    -1,   582,   909,
     768,   771,   775,   772,    -1,    -1,   582,   769,   770,   773,
     772,    -1,   777,    -1,   770,   777,    -1,   779,    -1,   771,
     779,    -1,   410,    -1,    -1,    -1,   390,   774,  1582,    -1,
      -1,    -1,   390,   776,  1582,    -1,    -1,   625,   909,   778,
    1582,    -1,    -1,   625,   909,   780,  1582,    -1,   327,  1001,
      -1,   250,   999,    -1,   132,   999,    -1,   217,    -1,   234,
    1513,    -1,   541,   998,    -1,    30,   783,    31,    -1,   784,
      -1,   786,    -1,   785,    -1,   784,   785,    -1,    29,    -1,
     787,    -1,   786,   787,    -1,    28,    -1,    -1,    -1,   371,
     789,   791,   790,   792,    -1,   434,  1161,   671,   793,  1047,
    1074,   735,    -1,  1161,   671,   793,  1047,   593,   952,  1074,
     735,    -1,    -1,   795,   240,    -1,   794,    -1,   793,     5,
     794,    -1,  1004,    -1,  1004,   666,  1004,    -1,  1004,   666,
      20,    -1,   796,    -1,   795,   796,    -1,    -1,   319,   802,
     797,  1582,    -1,    -1,   322,   803,   798,  1582,    -1,    -1,
    1077,   799,  1582,    -1,    -1,   215,   800,  1582,    -1,    -1,
     213,   801,  1582,    -1,  1008,    -1,   802,     5,  1008,    -1,
    1008,    -1,   803,     5,  1008,    -1,   140,    -1,   141,    -1,
     142,    -1,   143,    -1,   144,    -1,   145,    -1,   478,   902,
     806,   441,    -1,    -1,     5,   853,   672,   856,    -1,   205,
      -1,   328,    -1,    -1,   809,    -1,   810,    -1,   809,   810,
      -1,    -1,    -1,   485,   811,   813,   812,  1267,    -1,   866,
      -1,   816,    -1,   813,     5,   816,    -1,    -1,   815,  1004,
      -1,   404,   814,   865,    25,    -1,   404,   814,   865,  1004,
      -1,   404,   814,   865,  1010,    -1,   404,   814,   865,    26,
      -1,   820,   838,    -1,    -1,   814,   404,   817,   818,    -1,
      26,    -1,    25,    -1,  1010,    -1,    19,    26,    -1,   814,
      -1,   819,    -1,   820,     5,   819,    -1,    -1,   368,    -1,
      -1,   716,    -1,   717,    -1,   718,    -1,    -1,   534,   506,
     830,   474,   824,   670,   838,    -1,    -1,    36,   822,   825,
     670,   838,    -1,    -1,   367,   821,   827,    26,   828,   351,
     506,   829,   474,   826,   670,   838,    -1,   478,    -1,   505,
      -1,   441,    -1,   473,    -1,    26,    -1,   831,     5,   831,
       5,   831,    -1,   831,     5,   831,    -1,   831,    -1,    26,
      -1,    -1,   511,   833,   813,   332,    -1,    -1,   309,   834,
     814,   666,    20,    -1,    -1,   385,   835,   814,   307,   478,
     836,   441,    -1,   837,    -1,   836,     5,   837,    -1,   814,
      -1,   840,    -1,    -1,   107,    -1,    -1,    -1,   841,   843,
     842,   839,    -1,   823,    -1,   832,    -1,   368,    -1,   369,
      -1,   368,   478,    26,   441,    -1,   369,   478,    26,   441,
      -1,   471,   478,    26,   441,    -1,   471,   478,    26,     5,
      26,   441,    -1,   370,   478,    26,   441,    -1,   370,   478,
      26,     5,    26,   441,    -1,   456,    -1,   663,   814,    -1,
     430,    -1,   556,    -1,   138,    -1,   446,    -1,   446,   478,
      26,   441,    -1,   446,   478,    26,     5,    26,   441,    -1,
     559,    -1,   559,   478,    26,   441,    -1,   559,   478,    26,
       5,    26,   441,    -1,    -1,   549,   844,   847,    -1,    -1,
     112,   845,   847,    -1,    -1,   348,   846,   847,    -1,   584,
      -1,   580,    -1,   128,    -1,   129,    -1,   621,    -1,   407,
     851,    -1,   419,   852,    -1,   848,    -1,    32,    -1,    -1,
     478,    26,   441,    -1,   603,   849,   666,   850,    -1,   814,
      -1,   814,    -1,    -1,   853,   672,   856,    -1,   861,   672,
     864,    -1,    -1,   854,   855,    -1,   628,    -1,   560,    -1,
     637,    -1,   599,    -1,   501,    -1,   517,    -1,   416,   858,
      -1,    -1,   857,   855,    -1,    -1,   478,   860,   441,    -1,
      -1,   478,    26,   441,    -1,    26,    -1,    -1,   862,   863,
     859,    -1,   628,    -1,   560,    -1,   637,    -1,   599,    -1,
     501,    -1,   517,    -1,   416,   858,    -1,   863,    -1,    -1,
      14,    -1,    -1,   285,  1004,   867,   663,   868,    -1,   870,
      -1,   873,    -1,   368,    -1,   368,   478,    26,   441,    -1,
     471,   478,    26,   441,    -1,   471,   478,    26,     5,    26,
     441,    -1,   456,    -1,   430,    -1,   556,    -1,   446,    -1,
     446,   478,    26,   441,    -1,   446,   478,    26,     5,    26,
     441,    -1,   559,    -1,   559,   478,    26,   441,    -1,   559,
     478,    26,     5,    26,   441,    -1,   549,    -1,   348,    -1,
     584,    -1,   580,    -1,   621,    -1,   407,   851,    -1,   419,
     852,    -1,   869,    -1,   603,   849,   666,   850,    -1,    -1,
     534,   506,   830,   474,   871,   670,   868,    -1,    -1,   367,
     821,   827,    26,   828,   351,   506,   829,   474,   872,   670,
     868,    -1,    -1,   511,   874,   876,   332,    -1,    -1,   309,
     875,  1004,   666,    20,    -1,   877,    -1,   876,     5,   877,
      -1,   878,   868,    -1,   879,    -1,   878,     5,   879,    -1,
    1004,    -1,    -1,   664,   994,    -1,   119,  1004,    -1,   117,
      -1,   672,   952,    -1,   672,   556,  1004,   705,   952,    -1,
     672,   556,  1004,   439,    -1,   121,  1004,    -1,   206,   927,
    1179,   888,    -1,   449,   927,   907,   880,   888,    -1,   259,
    1001,   888,    -1,    -1,    -1,   237,   885,  1186,   672,  1004,
     666,    20,   887,   735,   886,   889,    -1,    -1,   515,   995,
      -1,   735,    -1,    -1,   890,   287,    -1,   287,    -1,   891,
      -1,   890,   891,    -1,    -1,   402,   892,  1582,    -1,    -1,
     398,   893,  1582,    -1,    -1,  1077,   894,  1582,    -1,    38,
    1161,    -1,    39,  1161,    -1,    37,  1161,    -1,   545,   927,
     908,   735,    -1,   545,   927,   908,   735,   114,    -1,   335,
      -1,   334,    -1,   262,    -1,   414,    -1,   222,    -1,   261,
      -1,   379,    -1,   378,    -1,   292,    -1,   219,    -1,   218,
      -1,   196,    -1,   252,    -1,   180,    -1,   195,    -1,   236,
      -1,   203,    -1,   263,    -1,   263,   909,    -1,   912,    -1,
     911,    -1,   916,    -1,   944,    -1,   902,   903,    -1,   945,
      -1,   947,    -1,   913,    -1,    19,   902,    -1,    18,   902,
      -1,   918,    -1,   926,    -1,   920,    -1,   522,    -1,   804,
      -1,   921,    -1,   922,    -1,   923,    -1,   924,    -1,   925,
      -1,    43,   902,    -1,   927,    -1,   927,   906,    -1,   909,
      -1,   530,    -1,   905,    -1,   906,     5,   905,    -1,   909,
      -1,   907,     5,   909,    -1,   909,    -1,   908,     5,   909,
      -1,   902,    -1,    18,    -1,    19,    -1,     9,   902,    -1,
     531,    -1,   475,    -1,   478,   902,   441,    -1,   490,   478,
    1487,   441,    -1,   343,   478,  1487,   441,    -1,   910,  1010,
      -1,   910,    26,    -1,    25,    -1,  1010,    -1,    26,    -1,
     915,    -1,  1161,    -1,  1161,   468,  1161,    -1,   914,    -1,
     481,   902,    -1,   442,   902,    -1,  1270,    -1,    -1,   554,
     917,  1270,    -1,     7,   902,    -1,     6,   902,    -1,   902,
      -1,   919,     5,   902,    -1,   669,   478,  1487,   441,    -1,
     476,   478,  1487,   441,    -1,   669,   478,   927,   919,   441,
      -1,   476,   478,   927,   919,   441,    -1,   436,    -1,   298,
      -1,    10,   902,    -1,   301,   902,    -1,    10,   902,   489,
      25,    -1,   301,   902,   489,    25,    -1,   603,   902,    -1,
     421,   902,    -1,   603,   902,   489,    25,    -1,   421,   902,
     489,    25,    -1,   440,    -1,     8,   902,    -1,    18,   902,
      -1,    19,   902,    -1,    20,   902,    -1,    21,   902,    -1,
      22,   902,    -1,    11,   902,    -1,    14,   902,    -1,   504,
     902,    -1,    12,   902,    -1,    13,   902,    -1,    17,   902,
      -1,    16,   902,    -1,    15,   902,    -1,    -1,    -1,    -1,
    1004,   478,   929,   762,   930,   441,    -1,    -1,    -1,  1004,
     568,  1004,   478,   931,   762,   932,   441,    -1,    -1,    -1,
     584,   478,   934,   902,   935,   441,    -1,    -1,    -1,   560,
     478,   936,   902,   937,   441,    -1,    -1,    -1,   637,   478,
     938,   902,   939,   441,    -1,    -1,    -1,   628,   478,   940,
     902,   941,   441,    -1,   419,   478,   948,   441,   943,    -1,
     407,   478,    25,   441,   942,    -1,   407,   478,    26,   441,
     942,    -1,   407,   478,    26,   636,    26,   441,   942,    -1,
     407,   478,    26,    19,    26,   441,   942,    -1,   407,   478,
      26,    19,    26,    19,    26,   441,   942,    -1,   721,   478,
    1161,   441,    -1,   722,   478,  1161,     5,    26,   441,    -1,
      -1,  1467,   672,  1468,    -1,   852,    -1,   933,    -1,   338,
     478,   952,   441,    -1,   147,   478,   995,   441,    -1,   120,
     478,   995,   441,    -1,   455,   478,   953,   441,    -1,   241,
     478,   952,   441,    -1,   108,   478,   952,   441,    -1,   946,
      -1,   928,    -1,  1463,    -1,   584,    -1,   470,   478,   902,
     441,    -1,   373,   478,   902,   441,    -1,   535,   902,    -1,
     491,   805,    -1,   902,   158,    -1,   902,   159,    -1,   902,
     160,    -1,    25,    -1,   949,    -1,    19,   949,    -1,   951,
      -1,   950,    -1,    26,    -1,    26,    26,    -1,    26,    26,
     636,    26,    -1,    26,    26,   636,    26,   636,    26,    -1,
      26,    26,   636,    26,   636,    24,    -1,    26,   636,    26,
      -1,    26,   636,    26,   636,    26,    -1,    26,   636,    26,
     636,    24,    -1,    26,   636,    24,    -1,    24,    -1,    26,
      -1,    26,    19,    26,    -1,   995,    -1,   952,     5,   995,
      -1,   996,    -1,   953,     5,   996,    -1,    -1,    -1,   642,
    1161,    14,   909,   672,   909,   957,   955,  1582,   956,   290,
      -1,    -1,   618,   909,    -1,    -1,    -1,    -1,   452,   959,
     998,   960,   962,  1365,   961,  1582,   289,    -1,    -1,     8,
     927,   907,    -1,    -1,    -1,   684,  1004,   964,   808,   965,
    1106,   967,   966,   972,   685,    -1,    -1,   977,    -1,    -1,
     968,    -1,   969,    -1,   968,   969,    -1,    -1,   686,   970,
    1582,    -1,    -1,   687,   971,  1582,    -1,    -1,   973,    -1,
     974,    -1,   973,   974,    -1,    -1,   688,   975,  1582,    -1,
      -1,   689,   976,  1582,    -1,   978,   982,   375,    -1,   139,
      -1,   139,   979,   593,   980,    -1,   139,   434,   981,    -1,
    1161,    -1,   979,     5,  1161,    -1,  1004,    -1,   980,     5,
    1004,    -1,  1161,    -1,   981,     5,  1161,    -1,   983,    -1,
     982,   983,    -1,    -1,   690,   984,  1582,    -1,    -1,   691,
     985,  1582,    -1,    -1,   710,   980,   986,  1582,    -1,    -1,
     528,   980,   987,  1582,    -1,    -1,   671,   980,   988,  1582,
      -1,   592,   997,    -1,   601,    19,    26,    -1,   601,    -1,
     548,    18,    26,    -1,   548,    -1,    26,    -1,  1161,    -1,
     715,    -1,    25,    -1,  1009,    -1,   909,    -1,   992,     5,
     992,    -1,   993,    -1,  1004,    -1,   713,   478,  1004,   441,
      -1,  1004,   666,   713,   478,  1004,   441,    -1,  1004,   506,
     732,   474,    -1,  1004,   666,    20,    -1,  1004,   506,   732,
     474,   666,    20,    -1,  1004,   666,  1004,    -1,  1004,   506,
     732,   474,   666,  1004,    -1,   995,    -1,    25,    -1,  1005,
      -1,  1005,    -1,  1005,    -1,  1005,    -1,  1005,    -1,  1005,
      -1,    -1,   597,    26,    -1,  1581,    -1,  1006,    -1,  1581,
      -1,   400,   478,  1007,   441,    -1,  1164,    -1,    25,    -1,
    1004,    -1,  1004,   506,   732,   474,    -1,  1004,   666,    20,
      -1,  1004,   506,   732,   474,   666,    20,    -1,  1004,   666,
    1004,    -1,  1004,   506,   732,   474,   666,  1004,    -1,  1161,
      -1,    24,    -1,   666,    26,    -1,   594,  1012,    -1,  1004,
      -1,   636,  1004,    -1,   698,  1014,    -1,  1015,    -1,  1014,
       5,  1015,    -1,  1004,    -1,   709,  1014,    -1,   700,  1014,
      -1,   701,   952,    -1,   699,  1001,   705,   952,    -1,   703,
    1014,    -1,   704,   952,    -1,   702,  1001,   705,   952,    -1,
      -1,   707,  1020,   907,  1025,  1027,  1029,  1021,  1023,    -1,
      -1,  1022,    -1,   695,    -1,   696,    -1,    -1,  1024,    -1,
     395,  1161,    -1,    -1,  1026,    -1,   439,   907,    -1,    -1,
    1028,    -1,   706,    26,    -1,    -1,  1030,    -1,   697,    26,
    1031,    -1,    -1,   448,    26,    -1,    -1,    -1,   668,   909,
     622,  1033,  1582,  1034,  1035,   488,    -1,    -1,    -1,   589,
    1036,  1582,    -1,    -1,    -1,   111,  1037,   909,   622,  1038,
    1582,  1035,    -1,   156,  1004,   478,    26,   441,    -1,   102,
    1004,    -1,   124,  1004,    -1,    -1,   339,  1190,  1042,   672,
     530,    -1,   339,  1190,   603,  1043,    -1,  1044,    -1,  1043,
       5,  1044,    -1,  1045,   666,  1459,    -1,  1045,   666,    20,
      -1,  1455,    -1,    -1,  1048,   375,    -1,   375,    -1,    -1,
     200,    -1,  1049,    -1,  1048,  1049,    -1,    -1,   319,  1063,
    1050,  1582,    -1,    -1,   322,  1064,  1051,  1582,    -1,    -1,
     402,  1052,  1582,    -1,    -1,   398,  1053,  1582,    -1,    -1,
    1077,  1054,  1582,    -1,    -1,   354,  1055,  1582,    -1,    -1,
     324,  1056,  1582,    -1,    -1,    44,  1057,  1582,    -1,    -1,
      42,  1058,  1582,    -1,    -1,    41,  1059,  1582,    -1,    -1,
      40,  1060,  1582,    -1,    -1,    47,  1061,  1582,    -1,    -1,
      46,  1062,  1582,    -1,   995,    -1,  1063,     5,   995,    -1,
     995,    -1,  1064,     5,   995,    -1,   363,  1067,    -1,   364,
    1004,   705,  1067,    -1,   608,    -1,   425,    -1,   995,    -1,
      -1,   711,  1070,  1069,  1046,    -1,   434,  1179,  1047,  1003,
     735,    -1,  1179,  1047,   593,   952,  1003,   735,    -1,    -1,
     534,  1186,  1047,   593,  1004,   666,    20,  1003,  1071,   735,
      -1,   516,   952,  1073,    -1,   130,    26,    -1,   131,    26,
      -1,   673,    -1,   586,    -1,    -1,   597,    26,    -1,  1076,
      -1,    53,    25,    -1,   543,    14,    26,    -1,   543,    14,
    1161,    -1,    54,    14,    26,    -1,    54,    14,  1161,    -1,
      50,    -1,    52,    -1,    49,    -1,    51,    -1,    -1,   477,
    1078,  1083,    -1,   344,    -1,    -1,   643,  1080,  1083,    -1,
     352,  1085,    -1,   643,  1083,    -1,  1085,    -1,   478,  1084,
     441,    -1,  1085,    -1,  1084,     5,  1085,    -1,  1086,    -1,
     641,    -1,   361,    -1,   381,    -1,   353,    -1,   532,    -1,
     489,    -1,   673,    -1,   597,    -1,   586,    -1,   226,    -1,
     486,    -1,   497,    -1,   587,    -1,   602,    -1,   567,    -1,
     359,    -1,   360,    -1,    25,    -1,   557,    -1,    -1,    -1,
     645,  1089,  1184,  1090,    14,   927,  1091,    -1,   530,    -1,
     908,    -1,   268,  1161,    -1,   258,  1161,    -1,   271,  1161,
      -1,   498,  1182,   384,    -1,   498,  1182,   435,   991,    -1,
      -1,  1098,  1097,  1101,    -1,    -1,  1099,    -1,  1100,    -1,
    1099,  1100,    -1,  1040,    -1,  1105,    -1,  1566,    -1,  1121,
      -1,  1107,    -1,  1120,    -1,    -1,  1102,    -1,  1104,    -1,
    1102,  1104,    -1,   115,  1004,    -1,  1109,    -1,  1115,    -1,
    1127,    -1,  1280,    -1,  1290,    -1,  1148,    -1,   963,    -1,
     782,    -1,  1039,    -1,  1566,    -1,   782,    -1,    -1,   782,
      -1,   809,    -1,   417,    -1,   109,    -1,    -1,    -1,    -1,
      -1,  1108,  1110,  1004,   478,  1111,  1177,   441,  1112,   808,
    1113,  1106,  1582,  1114,    -1,   260,    -1,    -1,    -1,   604,
    1116,   808,  1117,  1582,   411,    -1,   226,   904,    -1,   927,
      -1,   927,   907,    -1,   406,  1471,    -1,   514,  1471,    -1,
    1122,    -1,  1123,    -1,  1122,  1123,    -1,  1124,    -1,    -1,
     454,  1125,  1126,    -1,   808,   291,    -1,   991,    -1,  1105,
      -1,  1120,    -1,    -1,    -1,    -1,   163,  1004,   162,  1004,
     478,  1128,  1177,   441,  1129,   808,  1130,  1106,  1582,  1114,
      -1,    -1,   605,  1132,  1147,  1138,  1133,    -1,   412,    -1,
      -1,   283,  1135,  1582,    -1,    -1,    23,  1139,  1140,  1141,
    1003,  1136,  1582,    -1,    -1,    23,  1139,  1003,  1137,  1582,
      -1,  1134,    -1,  1138,  1134,    -1,    -1,  1079,    -1,    25,
      -1,  1161,    -1,    -1,  1161,    -1,    25,    -1,   300,  1145,
      -1,   312,  1146,    -1,   295,  1146,    -1,   632,    -1,    25,
      -1,  1161,    -1,  1145,    -1,  1146,     5,  1145,    -1,  1161,
      -1,    25,    -1,    -1,    -1,   692,  1004,  1149,   808,  1150,
    1151,   693,    -1,  1152,    -1,  1151,  1152,    -1,    -1,   694,
    1153,  1582,    -1,    -1,   671,  1004,  1154,  1582,    -1,  1158,
    1156,    -1,    -1,   736,  1159,    -1,  1160,    -1,  1157,    -1,
    1026,    -1,  1028,    -1,  1030,    -1,  1022,    -1,  1024,    -1,
     420,   927,   907,    -1,    -1,   114,    -1,   114,    -1,  1162,
      -1,  1164,    -1,   239,  1164,    -1,  1164,   666,    -1,  1163,
    1168,    -1,  1163,  1004,   506,  1171,   474,    -1,  1163,  1004,
     506,  1171,   474,   506,  1171,   474,    -1,  1169,    -1,  1004,
      -1,  1165,    -1,  1004,   505,  1167,   473,    -1,  1004,   505,
    1167,   473,    -1,  1161,    -1,    25,    -1,    20,    -1,  1004,
      -1,  1004,  1170,    -1,   506,  1171,   474,    -1,   506,  1171,
     474,   506,  1171,   474,    -1,  1172,    -1,  1171,     5,  1172,
      -1,   732,    -1,  1174,    -1,  1176,    -1,  1174,   666,  1175,
      -1,  1174,   666,  1004,   506,  1171,   474,    -1,  1174,   666,
    1004,   506,  1171,   474,   506,  1171,   474,    -1,  1004,    -1,
    1166,    -1,    20,    -1,  1004,    -1,  1004,  1170,    -1,    -1,
    1178,    -1,  1180,    -1,  1178,     5,  1180,    -1,  1181,    -1,
    1179,     5,  1181,    -1,  1004,    -1,  1004,   666,  1004,    -1,
    1161,    -1,  1161,   468,  1161,    -1,    25,    -1,  1010,    -1,
      26,    -1,  1183,    -1,  1182,     5,  1183,    -1,  1161,    -1,
    1161,   468,  1161,    -1,  1185,    -1,  1184,     5,  1185,    -1,
    1173,    -1,  1161,    -1,  1188,    -1,  1187,     5,  1188,    -1,
    1161,  1189,    -1,    -1,   634,    -1,   585,    -1,  1191,    -1,
    1190,     5,  1191,    -1,  1161,    -1,  1161,   468,  1161,    -1,
     303,  1000,   664,   993,   626,  1574,   740,    -1,    -1,   664,
     478,   909,     5,   909,   441,  1194,    -1,    -1,   615,   478,
     909,     5,   909,   441,    -1,   304,  1004,  1193,    -1,  1004,
      -1,   389,  1002,  1198,    -1,  1199,    -1,   593,   909,    -1,
    1200,  1201,  1206,     8,  1196,    -1,    -1,   664,  1202,   478,
     909,     5,   909,   441,    -1,    -1,   603,  1005,    -1,    -1,
     401,    -1,   266,  1513,   315,  1555,  1205,    -1,   610,   997,
      -1,   610,   997,     8,   927,   907,    -1,    -1,   663,   623,
    1507,   424,  1507,    -1,   663,   623,  1507,     5,   424,  1507,
      -1,   663,  1507,     5,  1507,    -1,    -1,   695,    -1,   696,
      -1,   443,   672,  1555,  1208,  1209,    -1,    -1,   663,  1555,
      -1,    -1,   663,   623,  1507,     8,  1507,    -1,   623,  1507,
       8,  1507,    -1,   459,  1211,    -1,  1212,    -1,  1211,     5,
    1212,    -1,   251,   990,    -1,   333,   990,    -1,   380,   990,
      -1,   388,   990,    -1,   342,   990,    -1,   308,   990,    -1,
    1081,    -1,   486,  1082,    -1,   497,  1082,    -1,   608,  1082,
      -1,   425,  1082,    -1,   597,  1082,    -1,   595,   991,    -1,
     596,   991,    -1,    58,    -1,    59,    -1,    60,    -1,    61,
      -1,   449,   736,    -1,   711,   736,    -1,   340,    -1,   244,
      -1,   201,    -1,   181,    -1,   198,    -1,   189,    -1,  1512,
     461,  1216,   593,  1214,    -1,  1161,    -1,    25,    -1,   451,
    1216,    -1,   451,  1216,     8,  1179,    -1,   451,  1216,   600,
    1182,    -1,   451,  1216,   600,  1182,     8,  1179,    -1,    48,
    1214,    -1,  1005,    -1,    -1,   509,  1226,   735,   642,  1221,
    1161,  1219,  1003,   735,  1218,  1222,    -1,    -1,   714,    26,
      -1,   509,  1226,   735,   395,  1161,    -1,    -1,   368,    -1,
      -1,  1223,   331,    -1,  1224,    -1,  1223,  1224,    -1,    -1,
    1077,  1225,  1582,    -1,   908,    -1,    -1,   650,   997,  1228,
    1229,    -1,    -1,   593,  1230,    -1,  1231,    -1,  1230,     5,
    1231,    -1,  1499,    -1,   530,    -1,   269,  1234,   137,    -1,
     269,  1234,   672,  1233,    -1,   269,  1234,   136,  1233,    -1,
     269,  1234,    -1,    25,    -1,  1009,    -1,  1004,    -1,    -1,
     526,    -1,   197,  1234,  1235,   478,   927,  1119,   441,    -1,
     242,  1234,    -1,   116,  1234,    -1,  1271,  1279,    -1,   494,
     110,    -1,   494,  1241,    -1,  1242,    -1,  1241,  1242,    -1,
      -1,   185,  1243,  1582,    -1,    -1,   247,  1244,  1582,    -1,
      -1,   277,  1245,  1582,    -1,    -1,   265,  1246,  1582,    -1,
      -1,   302,  1247,  1582,    -1,    -1,   249,  1161,  1248,  1582,
      -1,    -1,   273,  1161,  1249,  1582,    -1,  1260,    -1,  1263,
      -1,  1262,    -1,  1251,    -1,  1288,    -1,  1254,    -1,    -1,
     607,   909,  1252,   529,    -1,    -1,   529,    -1,    -1,   616,
      26,  1255,  1253,    -1,   208,    -1,   675,  1275,    -1,   211,
    1275,    -1,   210,  1275,    -1,    -1,  1257,    -1,  1258,    -1,
    1257,  1258,    -1,  1268,  1259,    -1,    -1,   664,  1275,    -1,
      -1,   566,  1261,  1256,  1267,    -1,   565,  1507,  1267,    -1,
     564,  1266,  1265,  1264,  1267,    -1,    -1,   202,   902,    -1,
     202,   902,     5,   902,    -1,   659,    -1,   660,    -1,   661,
      -1,   662,    -1,  1161,    -1,    -1,   569,    -1,  1269,    -1,
    1268,     5,  1269,    -1,   909,  1302,    -1,   655,   478,   902,
     441,  1287,    -1,   113,  1287,    -1,   543,   478,    20,   441,
    1287,    -1,   460,   478,    20,   441,  1287,    -1,   437,   478,
     902,   441,  1287,    -1,   635,   478,   902,   441,  1287,    -1,
     648,   478,   902,   441,  1287,    -1,   647,   478,   902,   441,
    1287,    -1,    -1,   508,  1272,    -1,  1273,    -1,  1272,  1273,
      -1,   276,    26,    -1,   267,    26,    -1,   350,    26,    -1,
     233,    26,    -1,   305,    26,    -1,   224,    -1,   394,    25,
      -1,   394,  1161,    -1,   225,    25,    -1,   209,    25,    -1,
    1278,    -1,  1274,  1278,    -1,  1276,   158,    -1,  1276,   160,
      -1,  1276,   159,    -1,  1276,    -1,  1010,    -1,    26,    -1,
      -1,   508,  1274,    -1,   276,  1275,    -1,   267,  1275,    -1,
     350,  1275,    -1,   233,  1275,    -1,   305,  1275,    -1,   306,
    1275,    -1,   674,    25,    -1,   675,  1275,    -1,   679,    -1,
     676,    -1,   677,    -1,   678,    -1,   683,    -1,   680,    -1,
     681,    -1,   682,    -1,   125,  1275,    -1,   126,  1275,    -1,
     127,  1275,    -1,   394,    25,    -1,   225,    25,    -1,   448,
      -1,   122,    -1,   123,    -1,    -1,   561,   665,  1187,    -1,
     186,  1187,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   512,
    1281,  1004,   478,  1282,  1177,   441,  1283,   808,  1284,  1239,
    1285,  1240,  1286,   288,    -1,    -1,   573,   902,    -1,   563,
    1289,    -1,    -1,  1214,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   155,  1291,  1004,   478,  1292,  1177,   441,  1293,   808,
    1294,  1297,  1295,  1240,  1296,   288,    -1,  1277,  1279,    -1,
      -1,    -1,    -1,   204,   478,    25,     5,  1299,   762,  1300,
     441,  1301,   760,    -1,    -1,   433,    -1,   433,   267,    26,
      -1,   433,   267,  1161,    -1,   653,   909,    -1,   653,   909,
     395,  1161,    -1,   653,   909,   212,    -1,   653,   909,   624,
      -1,   653,   909,   591,    -1,  1305,    -1,   221,  1455,    -1,
     374,  1455,    -1,   330,  1456,    -1,    45,  1004,    -1,  1319,
      -1,  1307,    -1,    -1,    -1,   254,  1308,  1455,   478,  1309,
    1323,   441,  1312,    -1,    -1,    -1,   183,  1310,  1455,   478,
    1311,  1323,   441,  1312,  1320,    -1,    -1,  1313,    -1,  1314,
      -1,  1313,  1314,    -1,   669,  1315,    -1,   293,    26,    -1,
      57,    26,    -1,   134,    -1,   135,    -1,  1581,    -1,    -1,
    1317,    -1,  1318,    -1,  1317,  1318,    -1,   669,  1315,    -1,
     723,    26,    -1,   153,  1456,   671,  1455,   478,  1321,   441,
    1316,    -1,   100,  1005,    -1,   101,  1005,    -1,   220,  1455,
     642,  1455,    -1,   105,  1455,    -1,    -1,   317,    -1,  1322,
      -1,  1321,     5,  1322,    -1,  1004,   634,    -1,  1004,   585,
      -1,  1004,    -1,  1324,    -1,  1323,     5,  1324,    -1,  1407,
      -1,  1405,    -1,   170,  1004,    -1,   228,    -1,    55,  1004,
    1327,    -1,    56,  1456,   150,    -1,    56,  1456,   151,    -1,
    1328,    -1,  1327,     5,  1328,    -1,  1329,    -1,  1332,    -1,
    1335,    -1,  1340,    -1,  1343,    -1,  1339,    -1,  1338,    -1,
     631,  1330,    -1,   631,   478,  1331,   441,    -1,  1324,    -1,
    1324,   710,  1004,    -1,  1330,    -1,  1331,     5,  1330,    -1,
     588,  1334,    -1,   588,   478,  1333,   441,    -1,  1334,    -1,
    1333,     5,  1334,    -1,  1004,    -1,   502,  1337,    -1,   502,
     478,  1336,   441,    -1,  1337,    -1,  1336,     5,  1337,    -1,
    1324,    -1,   134,    -1,   135,    -1,   133,    26,    -1,   103,
    1405,  1342,    -1,   103,   478,  1341,   441,    -1,  1405,  1342,
      -1,  1341,     5,  1405,  1342,    -1,    -1,   106,  1004,    -1,
     104,  1344,    -1,   104,   478,  1344,   441,    -1,  1345,    -1,
    1344,     5,  1345,    -1,  1004,    -1,   314,    -1,   280,    -1,
     214,  1348,    -1,   193,    -1,   182,    -1,   169,    -1,   167,
      -1,   171,    -1,   227,  1513,    -1,   279,  1347,   507,  1507,
     672,  1507,    -1,   347,   997,   507,  1507,   672,  1507,    -1,
      -1,  1513,    -1,    -1,   909,    -1,   570,   909,    -1,   278,
      -1,    -1,   297,  1352,  1455,  1355,  1353,    -1,    -1,   526,
    1354,   478,  1357,   441,    -1,  1493,    -1,    -1,   478,  1356,
     441,    -1,  1459,    -1,  1356,     5,  1459,    -1,  1358,    -1,
    1357,     5,  1358,    -1,  1499,    -1,   530,    -1,    -1,   547,
    1360,  1362,  1363,    -1,  1005,    -1,  1367,   998,    -1,   998,
      -1,    -1,    -1,   600,  1364,  1182,    -1,    -1,    -1,   600,
    1366,  1182,    -1,   548,    -1,   601,    -1,   608,    -1,   425,
      -1,   392,    -1,   444,    -1,   428,   909,    -1,   401,   909,
      -1,   286,  1455,   199,   998,    -1,   286,  1455,  1428,    -1,
     561,   665,  1371,    -1,  1372,    -1,  1371,     5,  1372,    -1,
    1373,  1374,    -1,    26,    -1,  1459,    -1,    -1,   634,    -1,
     585,    -1,   325,    -1,   358,    -1,    -1,   377,    -1,   406,
    1379,  1377,    -1,  1555,    -1,  1555,   658,  1004,    -1,    25,
      -1,    -1,  1512,  1381,  1382,    -1,  1413,    -1,  1417,    -1,
    1376,    -1,  1514,    -1,  1375,    -1,  1368,    -1,  1369,    -1,
    1359,    -1,  1351,    -1,  1350,    -1,  1483,    -1,  1535,    -1,
     552,  1386,   671,  1455,   672,  1391,  1385,    -1,   513,  1386,
     671,  1455,   593,  1391,    -1,   552,  1384,   672,  1391,    -1,
     513,  1384,   593,  1391,    -1,   443,    -1,   429,    -1,   638,
      -1,    -1,   192,    -1,   663,  1004,    -1,   216,    -1,   632,
      -1,  1387,    -1,  1388,    -1,  1387,     5,  1388,    -1,   518,
    1389,    -1,   497,    -1,   486,    -1,   525,  1389,    -1,   533,
      -1,   555,    -1,    -1,   478,  1390,   441,    -1,  1459,    -1,
    1390,     5,  1459,    -1,  1392,    -1,  1391,     5,  1392,    -1,
     510,    -1,  1457,    -1,   284,  1455,  1394,   663,  1493,  1396,
      -1,    -1,   478,  1395,   441,    -1,  1459,    -1,  1395,     5,
    1459,    -1,    -1,   191,    -1,   539,   478,  1431,   441,    -1,
     294,   478,  1400,   441,  1399,    -1,   345,  1401,    -1,  1402,
      -1,  1455,    -1,  1455,   478,  1402,   441,    -1,  1459,    -1,
    1402,     5,  1459,    -1,   523,   478,  1404,   441,    -1,   409,
     478,  1404,   441,    -1,   307,   478,  1404,   441,    -1,  1459,
      -1,  1404,     5,  1459,    -1,  1403,    -1,  1398,    -1,  1397,
      -1,   448,  1462,    -1,   257,    -1,   256,    -1,   255,    -1,
    1004,  1447,  1408,  1409,    -1,    -1,  1406,    -1,    -1,  1410,
      -1,  1411,    -1,  1410,  1411,    -1,  1412,  1342,    -1,   423,
      -1,   207,    -1,   523,    -1,   409,    -1,  1399,    -1,   539,
     478,  1431,   441,    -1,   307,    -1,   168,  1414,  1416,    -1,
    1415,    -1,  1457,    -1,  1417,    -1,  1416,  1417,    -1,  1393,
      -1,  1383,    -1,   495,  1431,    -1,   418,  1420,    -1,  1498,
      -1,  1420,     5,  1498,    -1,   573,  1431,    -1,   593,  1423,
      -1,  1424,    -1,  1423,     5,  1424,    -1,  1425,    -1,   562,
    1425,    -1,   562,   478,  1426,   441,    -1,  1455,    -1,  1455,
    1461,    -1,  1424,    -1,  1426,     5,  1424,    -1,  1422,  1428,
    1429,  1430,    -1,    -1,  1421,    -1,    -1,  1419,    -1,    -1,
    1418,    -1,  1432,    -1,  1431,     6,  1432,    -1,  1433,    -1,
    1432,     7,  1433,    -1,  1434,    -1,     9,  1434,    -1,  1445,
      -1,   478,  1431,   441,    -1,   490,  1494,    -1,   343,  1494,
      -1,    -1,   489,  1438,    -1,  1500,    -1,  1503,    -1,  1499,
     669,   478,  1440,   441,    -1,  1499,   669,  1494,    -1,  1499,
     476,   478,  1440,   441,    -1,  1499,   476,  1494,    -1,  1441,
      -1,  1440,     5,  1441,    -1,  1561,    -1,  1462,    -1,    -1,
       9,    -1,  1499,  1442,   436,    -1,  1499,  1442,   298,    -1,
    1499,  1444,  1499,    -1,  1499,  1442,   438,  1499,     7,  1499,
      -1,  1499,   603,  1437,  1436,    -1,  1499,   421,  1437,  1436,
      -1,  1499,   720,  1437,  1436,    -1,  1499,   422,  1437,  1436,
      -1,  1499,  1442,    10,  1437,  1436,    -1,    14,    -1,    17,
      -1,    12,    -1,    13,    -1,   301,    -1,    10,    -1,   719,
      -1,    16,    -1,    15,    -1,  1443,    -1,  1439,    -1,  1435,
      -1,    -1,   632,    -1,   409,    -1,   523,    -1,  1448,    -1,
    1449,    -1,  1451,    -1,   368,    -1,   368,   478,  1452,   441,
      -1,    -1,   519,    -1,   519,   478,    26,   441,    -1,   446,
      -1,   446,   478,  1453,  1450,   441,    -1,   559,   478,  1453,
    1450,   441,    -1,   559,    -1,   584,    -1,   456,    -1,   430,
      -1,   369,    -1,   369,   478,  1452,   441,    -1,   370,    -1,
     370,   478,    26,   441,    -1,   370,   478,    26,     5,    26,
     441,    -1,   407,  1469,   672,  1470,    -1,   407,    -1,   419,
    1469,   672,  1470,    -1,   419,    -1,   419,  1469,   478,    26,
     441,   672,  1470,    -1,   621,    -1,   580,    -1,   471,    -1,
     471,   478,    26,   441,    -1,   471,   478,    26,     5,    26,
     441,    -1,    -1,     5,  1454,    -1,   549,   478,  1453,   441,
      -1,   612,    -1,   348,    -1,   549,    -1,   112,    -1,    26,
      -1,    26,    -1,    26,    -1,    25,   666,  1004,    -1,    25,
      -1,  1004,    -1,  1004,   636,  1004,    -1,  1004,   636,    25,
     666,  1004,    -1,  1004,   658,  1004,    -1,  1004,   658,  1004,
     636,  1004,    -1,  1004,   658,  1004,   636,    25,   666,  1004,
      -1,    25,   666,  1004,    -1,    25,    -1,  1004,    -1,  1004,
     636,  1004,    -1,  1004,   636,    25,   666,  1004,    -1,  1004,
     658,  1004,    -1,  1004,   658,  1004,   636,  1004,    -1,  1004,
     658,  1004,   636,    25,   666,  1004,    -1,  1004,    -1,    -1,
     506,    26,   474,    -1,   506,    26,     5,    26,   474,    -1,
    1460,    -1,   658,  1460,    -1,  1004,  1458,    -1,  1455,   666,
    1004,  1458,    -1,  1455,   666,    20,    -1,  1004,    -1,    25,
      -1,  1010,    -1,    26,    -1,  1464,    -1,   444,  1466,    -1,
     444,  1465,    -1,    -1,  1469,   672,  1470,    -1,    -1,  1467,
     672,  1467,    -1,   628,    -1,   560,    -1,   637,    -1,   599,
      -1,   501,    -1,   517,    -1,   416,    -1,   416,   478,    26,
     441,    -1,   628,    -1,   560,    -1,   637,    -1,   599,    -1,
     501,    -1,   517,    -1,   416,    -1,   416,   478,    26,   441,
      -1,   628,    -1,   560,    -1,   637,    -1,   599,    -1,   501,
      -1,   517,    -1,   416,    -1,   628,    -1,   560,    -1,   637,
      -1,   599,    -1,   501,    -1,   517,    -1,   416,    -1,   416,
     478,    26,   441,    -1,  1004,    -1,  1004,   658,  1004,    -1,
      25,    -1,  1512,   550,   998,    -1,    -1,  1512,   447,  1361,
     484,   642,  1481,  1474,    -1,    -1,  1512,   447,  1361,   484,
     148,   642,  1482,  1475,    -1,    -1,  1512,   447,  1361,   187,
    1482,  1476,    -1,    -1,  1512,   447,  1361,   188,   148,   642,
    1482,  1477,    -1,    -1,   337,    -1,   336,  1479,    -1,  1480,
      -1,  1479,     5,  1480,    -1,  1004,    -1,  1004,   666,  1004,
      -1,    25,   666,  1004,   666,  1004,    -1,  1482,    -1,  1351,
      -1,  1216,    -1,  1484,    -1,  1484,    -1,    -1,    -1,   518,
    1495,  1485,  1496,  1486,  1492,  1427,  1490,  1478,    -1,   518,
    1495,  1496,  1427,  1490,    -1,  1489,    -1,  1507,    -1,   518,
    1495,  1496,  1492,  1427,  1490,    -1,    -1,   572,  1446,  1488,
      -1,  1370,    -1,   382,  1491,  1320,    -1,  1370,   382,  1491,
    1320,    -1,  1004,    -1,    -1,   600,  1182,    -1,   518,  1495,
    1496,  1427,    -1,   478,   518,  1495,  1496,  1427,   441,    -1,
      -1,   632,    -1,   409,    -1,   523,    -1,  1497,    -1,  1496,
       5,  1497,    -1,  1499,    -1,  1499,  1004,    -1,  1499,   663,
    1004,    -1,  1499,    -1,  1500,    -1,    19,  1500,    -1,    18,
    1500,    -1,  1501,    -1,  1561,    -1,  1494,    -1,   632,  1494,
      -1,   633,  1494,    -1,   617,  1494,    -1,   658,  1004,    -1,
     658,  1004,   666,  1004,    -1,  1500,    21,  1499,    -1,  1500,
    1521,    -1,  1500,    20,  1499,    -1,  1500,    18,  1499,    -1,
    1500,    19,  1499,    -1,  1462,    -1,   531,    -1,   475,    -1,
     623,    -1,    20,    -1,   113,    -1,   635,   478,  1446,  1499,
     441,    -1,   647,   478,  1446,  1499,   441,    -1,   648,   478,
    1446,  1499,   441,    -1,   655,   478,  1446,  1499,   441,    -1,
     543,   478,  1446,  1499,   441,    -1,  1004,   478,  1502,   441,
      -1,   584,   478,  1502,   441,    -1,   478,  1499,   441,    -1,
     491,   478,  1522,   441,    -1,  1523,    -1,  1525,    -1,  1499,
      -1,  1502,     5,  1499,    -1,  1462,    -1,  1512,   397,  1511,
    1506,  1488,    -1,  1512,   386,  1511,  1506,   297,  1455,  1508,
      -1,  1512,   386,  1511,  1506,  1161,    -1,    -1,   372,  1507,
      -1,    25,    -1,  1161,    -1,    -1,   478,  1509,   441,    -1,
    1510,    -1,  1509,     5,  1510,    -1,  1004,    -1,    25,    -1,
    1161,    -1,    -1,   316,  1513,   642,    -1,  1005,    -1,  1519,
      -1,  1518,    -1,  1515,    -1,   365,  1516,   672,  1516,    -1,
     346,  1455,   666,  1517,   672,  1517,    -1,  1004,    -1,  1004,
      -1,   270,  1455,    -1,   341,  1455,  1520,    -1,   320,    -1,
     223,    -1,   140,    -1,   141,    -1,   142,    -1,   143,    -1,
     144,    -1,   145,    -1,   444,     5,  1469,   672,  1470,    -1,
    1561,     5,  1469,   672,  1470,    -1,   444,  1469,   672,  1470,
      -1,  1499,     5,  1469,   672,  1470,    -1,  1524,    -1,  1524,
    1469,   672,  1470,    -1,   407,   478,    25,   441,    -1,   407,
     478,    26,   441,    -1,   407,   478,    26,    19,    26,   441,
      -1,   407,   478,    26,   636,    26,   441,    -1,   407,   478,
      26,    19,    26,    19,    26,   441,    -1,   407,   478,    26,
     636,    26,   636,    26,   441,    -1,   407,   478,    26,    19,
      26,    19,    26,    26,   636,    26,   636,    26,   441,    -1,
     407,   478,    26,    19,    26,    19,    26,    26,   636,    26,
     441,    -1,  1526,    -1,  1526,  1469,   478,    26,   441,   672,
    1470,    -1,  1526,  1469,   672,  1470,    -1,   419,   478,    25,
     441,    -1,   419,   478,    26,   441,    -1,   419,   478,    26,
      19,    26,   441,    -1,   419,   478,    26,   636,    26,   441,
      -1,   419,   478,    26,    19,    26,    19,    26,   441,    -1,
     419,   478,    26,   636,    26,   636,    26,   441,    -1,    -1,
     654,  1528,  1529,   238,    -1,  1530,    -1,  1529,  1530,    -1,
      33,    -1,  1531,    -1,  1533,    -1,   401,    -1,   353,    -1,
     272,    -1,   631,    -1,   528,    -1,   632,    -1,   533,    -1,
     577,    -1,   633,    -1,   164,    -1,   534,    -1,   663,    -1,
     634,    -1,   366,    -1,   535,    -1,   367,    -1,   664,    -1,
     658,    -1,   323,    -1,   536,    -1,   232,    -1,   437,    -1,
     635,    -1,   710,    -1,   438,    -1,   537,    -1,   538,    -1,
     578,    -1,   579,    -1,   479,    -1,   480,    -1,   403,    -1,
     697,    -1,   665,    -1,   580,    -1,   439,    -1,   582,    -1,
     576,    -1,   368,    -1,   539,    -1,   540,    -1,   440,    -1,
     541,    -1,   441,    -1,   474,    -1,   542,    -1,   636,    -1,
     481,    -1,   442,    -1,     5,    -1,    23,    -1,   482,    -1,
     443,    -1,   405,    -1,   404,    -1,   371,    -1,   543,    -1,
     483,    -1,   444,    -1,   484,    -1,   583,    -1,   406,    -1,
     584,    -1,   407,    -1,   637,    -1,   638,    -1,   445,    -1,
     639,    -1,   446,    -1,   447,    -1,   448,    -1,   408,    -1,
     544,    -1,   485,    -1,   486,    -1,   372,    -1,   585,    -1,
     329,    -1,   640,    -1,   701,    -1,   449,    -1,   409,    -1,
      21,    -1,   666,    -1,   487,    -1,   373,    -1,   588,    -1,
     111,    -1,   589,    -1,   704,    -1,   450,    -1,    14,    -1,
     545,    -1,   489,    -1,   546,    -1,   377,    -1,   590,    -1,
     451,    -1,   490,    -1,   591,    -1,   491,    -1,   492,    -1,
     415,    -1,   581,    -1,   547,    -1,   147,    -1,   241,    -1,
     493,    -1,   548,    -1,   641,    -1,   549,    -1,   550,    -1,
     642,    -1,   452,    -1,   453,    -1,   494,    -1,   684,    -1,
     139,    -1,   154,    -1,   551,    -1,   416,    -1,   592,    -1,
     593,    -1,   417,    -1,   338,    -1,   454,    -1,   667,    -1,
     594,    -1,   552,    -1,    13,    -1,   553,    -1,   554,    -1,
     495,    -1,   496,    -1,   597,    -1,   598,    -1,   599,    -1,
     706,    -1,   120,    -1,   668,    -1,   669,    -1,   160,    -1,
     555,    -1,   455,    -1,   339,    -1,   711,    -1,   497,    -1,
     456,    -1,   381,    -1,   419,    -1,   713,    -1,   383,    -1,
     643,    -1,   586,    -1,   705,    -1,   556,    -1,   529,    -1,
     420,    -1,   644,    -1,   673,    -1,   457,    -1,     7,    -1,
     475,    -1,   629,    -1,   530,    -1,     6,    -1,   531,    -1,
       8,    -1,   601,    -1,   602,    -1,    12,    -1,   645,    -1,
     603,    -1,   558,    -1,   498,    -1,   646,    -1,   458,    -1,
     604,    -1,   499,    -1,    10,    -1,    54,    -1,   500,    -1,
     605,    -1,   692,    -1,   707,    -1,    19,    -1,   501,    -1,
     159,    -1,    22,    -1,   606,    -1,   502,    -1,   559,    -1,
     560,    -1,    20,    -1,   607,    -1,   608,    -1,   359,    -1,
     609,    -1,   503,    -1,     9,    -1,   670,    -1,   715,    -1,
     671,    -1,   610,    -1,   478,    -1,   506,    -1,   507,    -1,
     459,    -1,   561,    -1,   390,    -1,   562,    -1,   508,    -1,
     649,    -1,   424,    -1,   563,    -1,   204,    -1,   155,    -1,
     460,    -1,    18,    -1,   158,    -1,   391,    -1,   461,    -1,
     161,    -1,   425,    -1,   360,    -1,   566,    -1,   392,    -1,
     393,    -1,   462,    -1,   509,    -1,   510,    -1,   650,    -1,
     611,    -1,   426,    -1,   612,    -1,   511,    -1,   463,    -1,
     651,    -1,   345,    -1,   427,    -1,   428,    -1,   512,    -1,
     429,    -1,   226,    -1,   395,    -1,   464,    -1,   513,    -1,
     567,    -1,   310,    -1,   652,    -1,   613,    -1,   653,    -1,
     514,    -1,   516,    -1,   517,    -1,   465,    -1,   518,    -1,
     569,    -1,   519,    -1,   466,    -1,   521,    -1,   614,    -1,
     532,    -1,   615,    -1,   616,    -1,   570,    -1,   348,    -1,
     430,    -1,   617,    -1,   522,    -1,   654,    -1,   349,    -1,
     138,    -1,   618,    -1,   619,    -1,   655,    -1,   467,    -1,
     587,    -1,   620,    -1,   165,    -1,   621,    -1,   622,    -1,
     468,    -1,   714,    -1,   672,    -1,   656,    -1,   469,    -1,
     571,    -1,   246,    -1,   396,    -1,   572,    -1,   523,    -1,
     524,    -1,   525,    -1,   470,    -1,   657,    -1,   623,    -1,
     431,    -1,   526,    -1,   471,    -1,   400,    -1,   624,    -1,
     472,    -1,   625,    -1,   573,    -1,   574,    -1,   575,    -1,
     626,    -1,   433,    -1,   627,    -1,   647,    -1,   648,    -1,
     630,    -1,   628,    -1,   527,    -1,    -1,   239,  1532,  1561,
      -1,    -1,   600,  1534,  1182,    -1,    -1,    -1,   525,  1455,
    1536,  1539,  1537,  1538,    -1,    -1,   199,   998,    -1,   573,
    1431,    -1,    98,  1543,   441,    14,   478,  1544,   441,    -1,
      94,  1544,   441,    -1,    95,  1544,   441,    -1,   630,  1540,
      -1,    97,  1544,    -1,    96,  1544,    -1,  1542,    -1,  1540,
       5,  1542,    -1,  1459,    -1,  1541,    14,  1545,    -1,  1541,
      -1,  1543,     5,  1541,    -1,  1545,    -1,  1544,     5,  1545,
      -1,   530,    -1,  1546,    -1,  1547,    -1,    19,  1547,    -1,
      18,  1547,    -1,  1549,    -1,  1494,    -1,   658,  1004,    -1,
     658,  1004,   666,  1004,    -1,   658,  1004,   506,    26,   474,
      -1,   658,  1004,   666,  1004,   506,    26,   474,    -1,   658,
    1004,   506,    26,     5,    26,   474,    -1,   658,  1004,   666,
    1004,   506,    26,     5,    26,   474,    -1,  1548,    -1,  1462,
      -1,   531,    -1,   475,    -1,   623,    -1,   113,    -1,  1547,
      21,  1546,    -1,  1547,  1521,    -1,  1547,    20,  1546,    -1,
    1547,    18,  1546,    -1,  1547,    19,  1546,    -1,   635,   478,
    1446,  1546,   441,    -1,   647,   478,  1446,  1546,   441,    -1,
     648,   478,  1446,  1546,   441,    -1,   655,   478,  1446,  1546,
     441,    -1,   543,   478,  1446,  1546,   441,    -1,  1004,   478,
    1550,   441,    -1,   584,   478,  1550,   441,    -1,   478,  1546,
     441,    -1,   491,   478,  1522,   441,    -1,  1523,    -1,  1525,
      -1,  1561,    -1,  1546,    -1,  1550,     5,  1546,    -1,    -1,
     431,  1190,   603,  1552,  1553,    -1,  1554,    -1,  1553,     5,
    1554,    -1,  1455,   666,  1459,    -1,  1455,   666,    20,    -1,
    1557,    -1,  1557,    -1,   239,  1558,    -1,  1558,    -1,  1559,
      -1,    25,   666,  1559,    -1,  1560,    -1,  1559,   666,  1560,
      -1,  1559,   666,    20,    -1,  1562,    -1,  1004,    -1,  1556,
      -1,  1556,   468,  1556,    -1,  1004,  1563,    -1,   506,  1564,
     474,    -1,   506,  1564,   474,   506,  1564,   474,    -1,  1565,
      -1,  1564,     5,  1565,    -1,   732,    -1,    34,    -1,    -1,
      -1,   574,  1568,   909,  1569,  1582,   376,    -1,    -1,   705,
     952,    -1,    -1,   708,    -1,   230,    -1,   326,   999,    -1,
     118,   999,    -1,   356,    -1,   355,    -1,   357,  1001,  1570,
    1571,    -1,   540,   952,  1571,    -1,   152,    -1,   184,   999,
      -1,   909,   613,     5,   909,   442,    -1,   556,   909,    -1,
     313,   999,    -1,   149,  1577,     8,  1578,  1576,    -1,    -1,
     593,   909,    -1,  1004,    -1,  1004,    -1,   296,   999,    -1,
     299,   999,   672,   909,     5,   909,    -1,   299,   999,   665,
     909,     5,   909,    -1,    27,    -1,    -1,  1584,    -1,  1585,
    1267,    -1,  1583,    -1,  1584,  1583,    -1,    -1,  1586,  1587,
      -1,   725,    -1,   726,    -1,   727,    -1,   728,    -1,   745,
      -1,   767,    -1,   781,    -1,   782,    -1,   788,    -1,   807,
      -1,   881,    -1,   882,    -1,   883,    -1,   884,    -1,   895,
      -1,   896,    -1,   897,    -1,   898,    -1,   899,    -1,   900,
      -1,   901,    -1,   954,    -1,   958,    -1,   989,    -1,  1011,
      -1,  1013,    -1,  1016,    -1,  1017,    -1,  1018,    -1,  1019,
      -1,  1032,    -1,  1041,    -1,  1065,    -1,  1066,    -1,  1068,
      -1,  1072,    -1,  1087,    -1,  1088,    -1,  1092,    -1,  1093,
      -1,  1094,    -1,  1095,    -1,  1103,    -1,  1118,    -1,  1131,
      -1,  1142,    -1,  1143,    -1,  1144,    -1,  1155,    -1,  1192,
      -1,  1195,    -1,  1197,    -1,  1203,    -1,  1204,    -1,  1207,
      -1,  1210,    -1,  1213,    -1,  1215,    -1,  1217,    -1,  1220,
      -1,  1227,    -1,  1232,    -1,  1236,    -1,  1237,    -1,  1238,
      -1,  1250,    -1,  1303,    -1,  1304,    -1,  1306,    -1,  1325,
      -1,  1326,    -1,  1346,    -1,  1349,    -1,  1378,    -1,  1380,
      -1,  1472,    -1,  1473,    -1,  1504,    -1,  1505,    -1,  1527,
      -1,  1551,    -1,  1566,    -1,  1567,    -1,  1572,    -1,  1573,
      -1,  1575,    -1,  1579,    -1,  1580,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const unsigned short yyrline[] =
{
       0,   996,   996,   999,  1002,  1008,  1014,  1021,  1025,  1025,
    1031,  1054,  1055,  1056,  1057,  1058,  1069,  1075,  1076,  1077,
    1078,  1079,  1084,  1085,  1096,  1099,  1102,  1102,  1106,  1109,
    1110,  1116,  1117,  1118,  1119,  1120,  1121,  1122,  1123,  1124,
    1125,  1126,  1127,  1128,  1129,  1130,  1131,  1132,  1135,  1136,
    1139,  1139,  1154,  1155,  1158,  1164,  1166,  1177,  1179,  1181,
    1183,  1187,  1189,  1251,  1255,  1259,  1259,  1269,  1273,  1276,
    1277,  1284,  1290,  1284,  1303,  1308,  1312,  1303,  1324,  1328,
    1324,  1336,  1341,  1336,  1360,  1367,  1371,  1359,  1397,  1397,
    1401,  1402,  1403,  1408,  1411,  1416,  1420,  1428,  1429,  1432,
    1432,  1438,  1442,  1457,  1455,  1473,  1473,  1488,  1488,  1491,
    1491,  1495,  1498,  1498,  1498,  1505,  1506,  1505,  1513,  1513,
    1524,  1524,  1543,  1546,  1549,  1552,  1555,  1558,  1571,  1576,
    1576,  1577,  1577,  1580,  1585,  1585,  1589,  1608,  1613,  1607,
    1624,  1630,  1638,  1639,  1642,  1642,  1645,  1649,  1654,  1661,
    1661,  1665,  1665,  1666,  1666,  1667,  1667,  1668,  1668,  1669,
    1669,  1677,  1681,  1687,  1691,  1706,  1709,  1712,  1715,  1718,
    1721,  1727,  1738,  1743,  1756,  1760,  1775,  1776,  1780,  1780,
    1784,  1784,  1784,  1785,  1790,  1790,  1793,  1793,  1802,  1803,
    1804,  1807,  1811,  1812,  1812,  1829,  1829,  1829,  1829,  1833,
    1840,  1841,  1844,  1844,  1848,  1849,  1850,  1851,  1856,  1856,
    1862,  1862,  1871,  1868,  1884,  1884,  1886,  1886,  1888,  1890,
    1892,  1894,  1897,  1901,  1901,  1902,  1902,  1906,  1906,  1918,
    1918,  1923,  1927,  1929,  1930,  1933,  1933,  1933,  1937,  1938,
    1939,  1940,  1941,  1942,  1943,  1944,  1945,  1946,  1947,  1948,
    1951,  1952,  1953,  1954,  1958,  1963,  1968,  1972,  1975,  1979,
    1979,  1980,  1980,  1981,  1981,  1982,  1983,  1984,  1985,  1986,
    1987,  1990,  1991,  1992,  2022,  2022,  2027,  2031,  2033,  2035,
    2035,  2042,  2046,  2046,  2050,  2051,  2052,  2053,  2054,  2055,
    2056,  2062,  2062,  2065,  2067,  2073,  2075,  2081,  2089,  2089,
    2092,  2093,  2094,  2095,  2096,  2097,  2098,  2104,  2107,  2107,
    2120,  2120,  2127,  2128,  2129,  2131,  2132,  2135,  2139,  2140,
    2141,  2142,  2147,  2153,  2159,  2160,  2162,  2164,  2165,  2166,
    2167,  2168,  2169,  2172,  2173,  2180,  2188,  2188,  2196,  2193,
    2208,  2208,  2210,  2210,  2218,  2218,  2221,  2224,  2225,  2230,
    2242,  2246,  2249,  2252,  2253,  2254,  2255,  2256,  2261,  2268,
    2274,  2279,  2284,  2279,  2297,  2299,  2304,  2309,  2309,  2309,
    2313,  2313,  2316,  2316,  2323,  2323,  2330,  2330,  2341,  2359,
    2365,  2389,  2392,  2406,  2408,  2410,  2412,  2414,  2416,  2418,
    2424,  2426,  2430,  2432,  2434,  2436,  2438,  2440,  2442,  2448,
    2463,  2466,  2479,  2480,  2481,  2482,  2483,  2487,  2488,  2489,
    2493,  2498,  2505,  2506,  2507,  2508,  2509,  2510,  2511,  2512,
    2513,  2514,  2515,  2522,  2522,  2527,  2527,  2530,  2536,  2544,
    2550,  2560,  2561,  2569,  2576,  2580,  2590,  2594,  2599,  2604,
    2606,  2609,  2615,  2623,  2636,  2641,  2647,  2652,  2657,  2658,
    2664,  2735,  2746,  2755,  2763,  2763,  2778,  2782,  2789,  2792,
    2800,  2804,  2807,  2813,  2822,  2827,  2835,  2838,  2841,  2846,
    2853,  2858,  2863,  2868,  2878,  2886,  2894,  2899,  2903,  2908,
    2912,  2916,  2923,  2926,  2929,  2933,  2937,  2941,  2945,  2953,
    2963,  2968,  2961,  2984,  2989,  2984,  3006,  3006,  3006,  3009,
    3009,  3009,  3013,  3013,  3013,  3017,  3017,  3017,  3021,  3027,
    3033,  3039,  3045,  3051,  3060,  3066,  3076,  3076,  3080,  3084,
    3085,  3096,  3097,  3103,  3113,  3123,  3133,  3134,  3137,  3142,
    3148,  3152,  3156,  3159,  3165,  3168,  3171,  3188,  3191,  3197,
    3198,  3199,  3203,  3204,  3205,  3206,  3207,  3209,  3210,  3211,
    3213,  3214,  3218,  3219,  3224,  3228,  3233,  3237,  3252,  3256,
    3251,  3264,  3267,  3281,  3285,  3291,  3280,  3304,  3305,  3317,
    3323,  3317,  3337,  3337,  3339,  3340,  3344,  3344,  3348,  3348,
    3353,  3353,  3360,  3361,  3365,  3365,  3369,  3369,  3374,  3374,
    3381,  3385,  3386,  3387,  3392,  3392,  3395,  3395,  3399,  3399,
    3403,  3403,  3407,  3407,  3412,  3412,  3417,  3417,  3422,  3422,
    3427,  3427,  3443,  3460,  3461,  3462,  3463,  3464,  3465,  3466,
    3469,  3469,  3472,  3474,  3477,  3480,  3483,  3488,  3493,  3496,
    3501,  3506,  3511,  3518,  3519,  3526,  3533,  3535,  3541,  3546,
    3551,  3556,  3556,  3559,  3565,  3570,  3573,  3580,  3580,  3582,
    3585,  3588,  3593,  3598,  3603,  3610,  3619,  3619,  3681,  3689,
    3690,  3698,  3705,  3705,  3709,  3714,  3720,  3724,  3728,  3734,
    3738,  3742,  3748,  3748,  3756,  3757,  3761,  3761,  3765,  3766,
    3769,  3772,  3772,  3775,  3777,  3777,  3780,  3782,  3782,  3783,
    3785,  3785,  3794,  3801,  3792,  3822,  3822,  3822,  3825,  3827,
    3825,  3834,  3837,  3843,  3854,  3854,  3858,  3864,  3864,  3868,
    3869,  3873,  3883,  3884,  3885,  3888,  3890,  3895,  3895,  3899,
    3898,  3906,  3905,  3912,  3912,  3918,  3918,  3925,  3925,  3931,
    3931,  3937,  3937,  3943,  3943,  3947,  3947,  3948,  3948,  3949,
    3949,  3950,  3950,  3954,  3954,  3965,  3969,  3975,  3979,  3984,
    3989,  3994,  3995,  3996,  4000,  3999,  4012,  4017,  4022,  4022,
    4038,  4044,  4045,  4046,  4047,  4050,  4050,  4053,  4060,  4061,
    4062,  4063,  4064,  4065,  4066,  4067,  4068,  4073,  4073,  4075,
    4078,  4078,  4080,  4084,  4087,  4088,  4091,  4091,  4096,  4099,
    4100,  4101,  4102,  4103,  4104,  4105,  4106,  4107,  4108,  4109,
    4110,  4111,  4112,  4113,  4114,  4115,  4116,  4120,  4138,  4138,
    4138,  4165,  4176,  4183,  4189,  4195,  4201,  4213,  4238,  4237,
    4254,  4254,  4258,  4259,  4267,  4268,  4269,  4270,  4271,  4272,
    4279,  4280,  4282,  4283,  4287,  4292,  4293,  4294,  4295,  4296,
    4297,  4298,  4299,  4300,  4302,  4305,  4307,  4307,  4309,  4313,
    4313,  4322,  4327,  4343,  4349,  4321,  4363,  4377,  4387,  4376,
    4400,  4407,  4407,  4412,  4418,  4426,  4431,  4432,  4435,  4438,
    4438,  4446,  4452,  4463,  4464,  4468,  4472,  4485,  4467,  4503,
    4503,  4517,  4528,  4527,  4539,  4535,  4552,  4549,  4562,  4562,
    4564,  4565,  4567,  4568,  4571,  4572,  4573,  4575,  4580,  4585,
    4591,  4593,  4594,  4597,  4598,  4601,  4603,  4611,  4617,  4611,
    4628,  4629,  4633,  4633,  4640,  4640,  4649,  4652,  4655,  4658,
    4662,  4666,  4667,  4668,  4669,  4670,  4674,  4679,  4679,  4682,
    4709,  4767,  4767,  4770,  4774,  4778,  4821,  4863,  4864,  4865,
    4868,  4882,  4894,  4894,  4899,  4900,  4906,  4971,  4976,  4983,
    4988,  4996,  5002,  5035,  5038,  5039,  5080,  5123,  5124,  5128,
    5129,  5133,  5186,  5191,  5195,  5200,  5211,  5218,  5226,  5226,
    5229,  5230,  5231,  5232,  5233,  5236,  5239,  5245,  5248,  5252,
    5257,  5265,  5270,  5277,  5279,  5285,  5287,  5287,  5287,  5311,
    5318,  5325,  5328,  5342,  5349,  5350,  5353,  5354,  5358,  5364,
    5369,  5375,  5376,  5381,  5385,  5385,  5389,  5390,  5393,  5394,
    5398,  5406,  5409,  5415,  5416,  5418,  5420,  5424,  5424,  5425,
    5430,  5438,  5439,  5444,  5445,  5447,  5460,  5462,  5463,  5466,
    5467,  5468,  5469,  5470,  5471,  5472,  5473,  5474,  5475,  5476,
    5477,  5478,  5479,  5480,  5481,  5482,  5483,  5484,  5485,  5486,
    5487,  5488,  5489,  5490,  5491,  5505,  5513,  5513,  5515,  5519,
    5523,  5527,  5531,  5536,  5551,  5549,  5569,  5570,  5574,  5579,
    5580,  5584,  5585,  5587,  5588,  5590,  5590,  5599,  5608,  5608,
    5618,  5619,  5624,  5625,  5628,  5641,  5655,  5659,  5663,  5667,
    5676,  5676,  5680,  5683,  5683,  5685,  5691,  5699,  5705,  5707,
    5711,  5714,  5714,  5717,  5717,  5722,  5722,  5731,  5731,  5735,
    5735,  5736,  5736,  5737,  5737,  5751,  5751,  5771,  5772,  5773,
    5774,  5775,  5776,  5779,  5779,  5785,  5785,  5788,  5788,  5804,
    5805,  5806,  5815,  5827,  5828,  5831,  5832,  5835,  5838,  5838,
    5843,  5843,  5864,  5869,  5875,  5876,  5877,  5881,  5882,  5883,
    5884,  5888,  5898,  5900,  5905,  5908,  5913,  5919,  5926,  5933,
    5942,  5949,  5956,  5963,  5970,  5979,  5979,  5981,  5981,  5984,
    5985,  5986,  5987,  5988,  5989,  5990,  5991,  5992,  5993,  5996,
    5996,  5999,  6000,  6001,  6002,  6005,  6005,  6008,  6008,  6011,
    6012,  6013,  6014,  6015,  6016,  6017,  6018,  6020,  6021,  6022,
    6023,  6025,  6026,  6027,  6028,  6030,  6031,  6032,  6033,  6034,
    6035,  6036,  6037,  6041,  6049,  6059,  6072,  6081,  6092,  6096,
    6100,  6106,  6071,  6119,  6122,  6130,  6142,  6144,  6149,  6157,
    6167,  6170,  6174,  6182,  6148,  6191,  6195,  6199,  6203,  6195,
    6213,  6214,  6215,  6216,  6221,  6223,  6226,  6230,  6233,  6240,
    6245,  6246,  6247,  6248,  6253,  6254,  6260,  6260,  6260,  6265,
    6265,  6265,  6273,  6274,  6278,  6279,  6284,  6285,  6286,  6287,
    6288,  6291,  6293,  6293,  6296,  6297,  6301,  6302,  6305,  6306,
    6309,  6312,  6315,  6321,  6322,  6334,  6335,  6340,  6341,  6342,
    6346,  6349,  6355,  6358,  6366,  6367,  6373,  6377,  6381,  6387,
    6390,  6399,  6402,  6405,  6408,  6411,  6414,  6417,  6424,  6427,
    6434,  6437,  6443,  6446,  6453,  6456,  6463,  6464,  6469,  6473,
    6476,  6482,  6485,  6491,  6498,  6499,  6503,  6513,  6516,  6522,
    6524,  6529,  6530,  6534,  6536,  6542,  6543,  6556,  6568,  6569,
    6570,  6571,  6572,  6573,  6574,  6575,  6576,  6579,  6582,  6588,
    6588,  6594,  6594,  6605,  6618,  6628,  6628,  6633,  6633,  6637,
    6641,  6642,  6648,  6649,  6654,  6658,  6665,  6668,  6675,  6674,
    6685,  6689,  6693,  6700,  6703,  6703,  6716,  6720,  6720,  6735,
    6737,  6739,  6741,  6743,  6745,  6747,  6749,  6755,  6765,  6772,
    6777,  6778,  6782,  6785,  6786,  6789,  6790,  6791,  6794,  6799,
    6806,  6807,  6813,  6825,  6826,  6827,  6830,  6830,  6835,  6840,
    6845,  6846,  6849,  6850,  6855,  6860,  6864,  6869,  6870,  6874,
    6881,  6882,  6883,  6884,  6889,  6890,  6891,  6894,  6895,  6896,
    6900,  6901,  6902,  6906,  6907,  6911,  6912,  6913,  6914,  6915,
    6916,  6919,  6920,  6925,  6926,  6931,  6932,  6937,  6938,  6943,
    6948,  6949,  6954,  6955,  6959,  6960,  6965,  6972,  6977,  6982,
    6986,  6987,  6992,  6993,  6999,  7000,  7001,  7006,  7007,  7013,
    7016,  7019,  7026,  7027,  7028,  7029,  7043,  7048,  7049,  7052,
    7054,  7061,  7064,  7070,  7078,  7082,  7086,  7090,  7094,  7097,
    7100,  7107,  7114,  7119,  7123,  7124,  7130,  7133,  7144,  7151,
    7157,  7160,  7167,  7174,  7180,  7181,  7187,  7188,  7189,  7192,
    7193,  7198,  7198,  7202,  7210,  7211,  7214,  7217,  7222,  7223,
    7228,  7231,  7237,  7240,  7246,  7249,  7255,  7258,  7265,  7266,
    7295,  7296,  7301,  7309,  7314,  7317,  7320,  7323,  7329,  7330,
    7334,  7337,  7340,  7341,  7346,  7349,  7352,  7355,  7358,  7361,
    7364,  7367,  7372,  7378,  7379,  7380,  7381,  7382,  7384,  7385,
    7387,  7388,  7393,  7396,  7400,  7406,  7407,  7408,  7409,  7421,
    7422,  7423,  7427,  7428,  7432,  7433,  7434,  7435,  7436,  7438,
    7440,  7441,  7442,  7443,  7444,  7445,  7446,  7447,  7449,  7451,
    7453,  7454,  7456,  7457,  7459,  7460,  7461,  7462,  7464,  7468,
    7469,  7475,  7477,  7478,  7479,  7480,  7485,  7489,  7493,  7497,
    7504,  7508,  7509,  7510,  7518,  7519,  7520,  7531,  7538,  7543,
    7544,  7545,  7553,  7554,  7555,  7572,  7581,  7582,  7583,  7587,
    7590,  7595,  7600,  7605,  7613,  7617,  7622,  7623,  7631,  7634,
    7637,  7651,  7665,  7678,  7679,  7683,  7683,  7683,  7683,  7683,
    7683,  7684,  7687,  7692,  7692,  7692,  7692,  7692,  7692,  7694,
    7697,  7703,  7703,  7703,  7703,  7703,  7703,  7703,  7704,  7704,
    7704,  7704,  7704,  7704,  7704,  7704,  7707,  7708,  7709,  7712,
    7721,  7721,  7727,  7727,  7734,  7734,  7740,  7740,  7748,  7749,
    7750,  7753,  7753,  7756,  7757,  7758,  7769,  7772,  7778,  7783,
    7790,  7803,  7804,  7801,  7822,  7833,  7836,  7841,  7853,  7856,
    7860,  7863,  7864,  7870,  7873,  7874,  7883,  7892,  7897,  7898,
    7899,  7900,  7907,  7910,  7916,  7919,  7926,  7938,  7947,  7950,
    7953,  7959,  7965,  7968,  7969,  7970,  7971,  7972,  7975,  7981,
    7983,  7985,  7987,  7989,  7991,  7992,  7993,  7994,  7995,  7996,
    7997,  7999,  8001,  8003,  8005,  8007,  8009,  8011,  8012,  8014,
    8015,  8021,  8022,  8029,  8032,  8040,  8044,  8051,  8051,  8055,
    8055,  8060,  8060,  8064,  8064,  8068,  8074,  8074,  8077,  8077,
    8083,  8090,  8091,  8092,  8096,  8097,  8100,  8101,  8105,  8111,
    8121,  8122,  8130,  8131,  8132,  8133,  8134,  8135,  8139,  8140,
    8141,  8142,  8146,  8147,  8151,  8152,  8153,  8154,  8155,  8156,
    8157,  8159,  8163,  8164,  8165,  8169,  8170,  8171,  8172,  8173,
    8174,  8177,  8177,  8189,  8190,  8194,  8195,  8196,  8197,  8198,
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
    8369,  8370,  8371,  8372,  8373,  8374,  8375,  8376,  8377,  8378,
    8379,  8380,  8381,  8382,  8383,  8384,  8385,  8386,  8387,  8388,
    8389,  8390,  8391,  8392,  8393,  8394,  8395,  8396,  8398,  8399,
    8400,  8401,  8402,  8403,  8404,  8405,  8406,  8407,  8408,  8409,
    8410,  8411,  8412,  8413,  8414,  8415,  8416,  8417,  8418,  8419,
    8420,  8421,  8422,  8423,  8424,  8425,  8426,  8427,  8428,  8429,
    8430,  8431,  8432,  8433,  8434,  8435,  8436,  8437,  8438,  8439,
    8440,  8441,  8442,  8443,  8444,  8445,  8446,  8447,  8448,  8449,
    8450,  8451,  8452,  8453,  8454,  8455,  8456,  8457,  8458,  8459,
    8460,  8461,  8462,  8463,  8464,  8465,  8466,  8467,  8468,  8469,
    8470,  8471,  8472,  8473,  8474,  8475,  8476,  8477,  8478,  8479,
    8480,  8481,  8482,  8483,  8484,  8485,  8486,  8487,  8488,  8489,
    8490,  8491,  8492,  8493,  8494,  8495,  8496,  8497,  8498,  8499,
    8500,  8501,  8502,  8503,  8504,  8505,  8506,  8507,  8508,  8509,
    8510,  8511,  8512,  8520,  8520,  8527,  8527,  8615,  8619,  8615,
    8628,  8632,  8638,  8646,  8656,  8666,  8678,  8681,  8700,  8726,
    8729,  8735,  8738,  8743,  8746,  8754,  8762,  8775,  8778,  8786,
    8789,  8792,  8800,  8804,  8805,  8806,  8807,  8808,  8809,  8810,
    8811,  8815,  8816,  8817,  8818,  8819,  8825,  8826,  8827,  8828,
    8829,  8830,  8831,  8832,  8833,  8834,  8835,  8836,  8837,  8838,
    8839,  8840,  8845,  8851,  8852,  8860,  8860,  8868,  8868,  8872,
    8876,  8891,  8906,  8912,  8914,  8922,  8923,  8927,  8928,  8931,
    8938,  8941,  8970,  8996,  9042,  9078,  9087,  9098,  9101,  9106,
    9120,  9134,  9137,  9133,  9156,  9156,  9162,  9163,  9166,  9167,
    9168,  9169,  9170,  9171,  9172,  9183,  9186,  9191,  9195,  9200,
    9204,  9209,  9213,  9216,  9220,  9223,  9228,  9232,  9243,  9249,
    9249,  9250,  9251,  9258,  9268,  9268,  9270,  9271,  9272,  9273,
    9274,  9275,  9276,  9277,  9278,  9279,  9280,  9281,  9282,  9283,
    9284,  9285,  9286,  9287,  9288,  9289,  9290,  9291,  9292,  9293,
    9294,  9295,  9296,  9297,  9298,  9299,  9300,  9301,  9302,  9303,
    9304,  9305,  9306,  9307,  9308,  9309,  9310,  9311,  9312,  9313,
    9314,  9315,  9316,  9317,  9318,  9319,  9320,  9321,  9322,  9323,
    9324,  9325,  9326,  9327,  9328,  9329,  9330,  9331,  9332,  9333,
    9334,  9335,  9336,  9337,  9338,  9339,  9340,  9341,  9342,  9343,
    9344,  9345,  9346,  9347,  9348,  9349,  9350,  9351,  9352,  9353,
    9354,  9355,  9356,  9357
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
  "CONCAT_PIPES", "BEFORE_DELETE", "DROP_TRIGGER", "AFTER_INSERT", 
  "AFTER_DELETE", "EXECUTE_IMMEDIATE", "DELETE_ROW_EQUAL_TRUE", 
  "INSERT_ROW_EQUAL_TRUE", "DELETE_ROW_EQUAL_FALSE", 
  "INSERT_ROW_EQUAL_FALSE", "CURRENT_ROW_DISPLAY_EQUAL", "MAXCOUNT", 
  "ALTER_TABLE", "ALTER_INDEX", "NEXT_SIZE", "DISPLAY_ATTR_FORM", 
  "DISPLAY_ATTR_WINDOW", "INPUT_ATTR_FORM", "INPUT_ATTR_WINDOW", 
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
  "dealloc_arr_cmd", "resize_arr_cmd", "error_cmd", "ext_cmd", 
  "continue_cmd", "exit_prog_cmd", "fgl_expr_c", "fgl_next", 
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
  "for_cmd", "@70", "@71", "for_step", "foreach_cmd", "@72", "@73", "@74", 
  "opt_foreach_using_part", "formhandler_def", "@75", "@76", 
  "op_input_section", "op_bef_ev_list", "bef_ev_list", "bef_ev", "@77", 
  "@78", "op_aft_ev_list", "aft_ev_list", "aft_ev", "@79", "@80", 
  "input_section", "input_sub_section", "in_variable_list", "in_id_list", 
  "in_bn_variable_list", "field_ops", "field_op", "@81", "@82", "@83", 
  "@84", "@85", "free_cmd", "line_no", "file_name", "a_number", "coords", 
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
  "mem_func_def", "@120", "@121", "@122", "menu_cmd", "@123", 
  "end_menu_command", "menu_block_command", "@124", "@125", "@126", 
  "menu_commands", "opt_key", "menu_opt_name", "menu_optional_desc", 
  "next_option_cmd", "show_option_cmd", "hide_option_cmd", "opt_name", 
  "opt_name_list", "menu_title", "menu_def", "@127", "@128", 
  "menu_handler_elements", "menu_handler_element", "@129", "@130", 
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
  "put_val", "start_cmd", "rout", "rep_name", "op_values", "output_cmd", 
  "finish_cmd", "term_rep_cmd", "report_section", "format_section", 
  "format_actions", "format_action", "@134", "@135", "@136", "@137", 
  "@138", "@139", "@140", "report_cmd", "need_command", "@141", 
  "op_lines", "skip_command", "@142", "opt_rep_expr_list", 
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
       0,   256,  1707,  1708,  1709,  1614,  1654,  1609,  1546,  1629,
    1426,  1532,  1528,  1443,  1604,  1345,  1402,  1474,  1640,  1627,
    1533,  1560,  1628,  1409,  1710,  1711,  1712,  1713,  1714,  1715,
    1716,  1717,  1718,  1719,  1720,  1721,  1000,  1001,  1002,  1003,
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
    1344,  1346,  1347,  1348,  1349,  1350,  1351,  1352,  1353,  1354,
    1355,  1356,  1357,  1358,  1359,  1360,  1361,  1362,  1363,  1364,
    1365,  1366,  1367,  1368,  1369,  1370,  1371,  1372,  1373,  1374,
    1375,  1376,  1377,  1378,  1379,  1380,  1381,  1382,  1383,  1384,
    1385,  1386,  1387,  1388,  1389,  1390,  1391,  1392,  1393,  1394,
    1395,  1396,  1397,  1398,  1399,  1400,  1401,  1403,  1404,  1405,
    1406,  1407,  1408,  1410,  1411,  1412,  1413,  1414,  1415,  1416,
    1417,  1418,  1419,  1420,  1421,  1422,  1423,  1424,  1425,  1427,
    1428,  1429,  1430,  1431,  1432,  1433,  1434,  1435,  1436,  1437,
    1438,  1439,  1440,  1441,  1442,  1444,  1445,  1446,  1447,  1448,
    1449,  1450,  1451,  1452,  1453,  1454,  1455,  1456,  1457,  1458,
    1459,  1460,  1461,  1462,  1463,  1464,  1465,  1466,  1467,  1468,
    1469,  1470,  1471,  1472,  1473,  1475,  1476,  1477,  1478,  1479,
    1480,  1481,  1482,  1483,  1484,  1485,  1486,  1487,  1488,  1489,
    1490,  1491,  1492,  1493,  1494,  1495,  1496,  1497,  1498,  1499,
    1500,  1501,  1502,  1503,  1504,  1505,  1506,  1507,  1508,  1509,
    1510,  1511,  1512,  1513,  1514,  1515,  1516,  1517,  1518,  1519,
    1520,  1521,  1522,  1523,  1524,  1525,  1526,  1527,  1529,  1530,
    1531,  1534,  1535,  1536,  1537,  1538,  1539,  1540,  1541,  1542,
    1543,  1544,  1545,  1547,  1548,  1549,  1550,  1551,  1552,  1553,
    1554,  1555,  1556,  1557,  1558,  1559,  1561,  1562,  1563,  1564,
    1565,  1566,  1567,  1568,  1569,  1570,  1571,  1572,  1573,  1574,
    1575,  1576,  1577,  1578,  1579,  1580,  1581,  1582,  1583,  1584,
    1585,  1586,  1587,  1588,  1589,  1590,  1591,  1592,  1593,  1594,
    1595,  1596,  1597,  1598,  1599,  1600,  1601,  1602,  1603,  1605,
    1606,  1607,  1608,  1610,  1611,  1612,  1613,  1615,  1616,  1617,
    1618,  1619,  1620,  1621,  1622,  1623,  1624,  1625,  1626,  1630,
    1631,  1632,  1633,  1634,  1635,  1636,  1637,  1638,  1639,  1641,
    1642,  1643,  1644,  1645,  1646,  1647,  1648,  1649,  1650,  1651,
    1652,  1653,  1655,  1656,  1657,  1658,  1659,  1660,  1661,  1662,
    1663,  1664,  1665,  1666,  1667,  1668,  1669,  1670,  1671,  1672,
    1673,  1674,  1675,  1676,  1677,  1678,  1679,  1680,  1681,  1682,
    1683,  1684,  1685,  1686,  1687,  1688,  1689,  1690,  1691,  1692,
    1693,  1694,  1695,  1696,  1697,  1698,  1699,  1700,  1701,  1702,
    1703,  1704,  1705,  1706
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const unsigned short yyr1[] =
{
       0,   724,   725,   726,   727,   728,   729,   729,   730,   730,
     731,   732,   732,   732,   732,   732,   732,   733,   733,   733,
     733,   733,   734,   734,   735,   735,   737,   736,   736,   738,
     738,   739,   739,   739,   739,   739,   739,   739,   739,   739,
     739,   739,   739,   739,   739,   739,   739,   739,   740,   740,
     742,   741,   743,   743,   744,   744,   744,   744,   744,   744,
     744,   744,   744,   745,   746,   747,   746,   746,   746,   746,
     746,   748,   749,   746,   750,   751,   752,   746,   753,   754,
     746,   755,   756,   746,   757,   758,   759,   746,   760,   760,
     761,   761,   761,   762,   762,   763,   763,   764,   764,   765,
     765,   766,   766,   768,   767,   769,   767,   770,   770,   771,
     771,   772,   773,   774,   773,   775,   776,   775,   778,   777,
     780,   779,   781,   781,   781,   781,   781,   781,   782,   783,
     783,   784,   784,   785,   786,   786,   787,   789,   790,   788,
     791,   791,   792,   792,   793,   793,   794,   794,   794,   795,
     795,   797,   796,   798,   796,   799,   796,   800,   796,   801,
     796,   802,   802,   803,   803,   804,   804,   804,   804,   804,
     804,   805,   806,   806,   807,   807,   808,   808,   809,   809,
     811,   812,   810,   810,   813,   813,   815,   814,   816,   816,
     816,   816,   816,   817,   816,   818,   818,   818,   818,   819,
     820,   820,   821,   821,   822,   822,   822,   822,   824,   823,
     825,   823,   826,   823,   827,   827,   828,   828,   829,   830,
     830,   830,   831,   833,   832,   834,   832,   835,   832,   836,
     836,   837,   838,   839,   839,   841,   842,   840,   843,   843,
     843,   843,   843,   843,   843,   843,   843,   843,   843,   843,
     843,   843,   843,   843,   843,   843,   843,   843,   843,   844,
     843,   845,   843,   846,   843,   843,   843,   843,   843,   843,
     843,   843,   843,   843,   847,   847,   848,   849,   850,   851,
     851,   852,   854,   853,   855,   855,   855,   855,   855,   855,
     855,   857,   856,   858,   858,   859,   859,   860,   862,   861,
     863,   863,   863,   863,   863,   863,   863,   864,   865,   865,
     867,   866,   868,   868,   868,   868,   868,   868,   868,   868,
     868,   868,   868,   868,   868,   868,   868,   868,   868,   868,
     868,   868,   868,   868,   868,   869,   871,   870,   872,   870,
     874,   873,   875,   873,   876,   876,   877,   878,   878,   879,
     880,   880,   880,   880,   880,   880,   880,   880,   881,   882,
     883,   885,   886,   884,   887,   887,   888,   889,   889,   889,
     890,   890,   892,   891,   893,   891,   894,   891,   895,   896,
     897,   898,   898,   899,   899,   899,   899,   899,   899,   899,
     899,   899,   900,   900,   900,   900,   900,   900,   900,   900,
     901,   901,   902,   902,   902,   902,   902,   902,   902,   902,
     902,   902,   903,   903,   903,   903,   903,   903,   903,   903,
     903,   903,   903,   904,   904,   905,   905,   906,   906,   907,
     907,   908,   908,   909,   910,   910,   911,   911,   911,   911,
     911,   911,   912,   912,   913,   913,   913,   913,   914,   914,
     915,   916,   916,   916,   917,   916,   918,   918,   919,   919,
     920,   920,   920,   920,   921,   921,   922,   922,   922,   922,
     922,   922,   922,   922,   923,   924,   925,   925,   925,   925,
     925,   925,   926,   926,   926,   926,   926,   926,   926,   927,
     929,   930,   928,   931,   932,   928,   934,   935,   933,   936,
     937,   933,   938,   939,   933,   940,   941,   933,   933,   933,
     933,   933,   933,   933,   933,   933,   942,   942,   943,   944,
     944,   944,   944,   944,   944,   944,   944,   944,   945,   945,
     946,   946,   946,   946,   947,   947,   947,   948,   948,   949,
     949,   949,   950,   950,   950,   950,   950,   950,   950,   950,
     950,   950,   951,   951,   952,   952,   953,   953,   955,   956,
     954,   957,   957,   959,   960,   961,   958,   962,   962,   964,
     965,   963,   966,   966,   967,   967,   968,   968,   970,   969,
     971,   969,   972,   972,   973,   973,   975,   974,   976,   974,
     977,   978,   978,   978,   979,   979,   980,   980,   981,   981,
     982,   982,   984,   983,   985,   983,   986,   983,   987,   983,
     988,   983,   989,   990,   990,   990,   990,   990,   990,   990,
     991,   991,   992,   993,   994,   995,   995,   995,   995,   995,
     995,   995,   995,   996,   996,   997,   998,   999,  1000,  1001,
    1002,  1003,  1003,  1004,  1005,  1006,  1006,  1007,  1007,  1008,
    1008,  1008,  1008,  1008,  1008,  1009,  1010,  1010,  1011,  1012,
    1012,  1013,  1014,  1014,  1015,  1016,  1017,  1017,  1017,  1018,
    1018,  1018,  1020,  1019,  1021,  1021,  1022,  1022,  1023,  1023,
    1024,  1025,  1025,  1026,  1027,  1027,  1028,  1029,  1029,  1030,
    1031,  1031,  1033,  1034,  1032,  1035,  1036,  1035,  1037,  1038,
    1035,  1039,  1039,  1040,  1042,  1041,  1041,  1043,  1043,  1044,
    1044,  1045,  1046,  1046,  1046,  1047,  1047,  1048,  1048,  1050,
    1049,  1051,  1049,  1052,  1049,  1053,  1049,  1054,  1049,  1055,
    1049,  1056,  1049,  1057,  1049,  1058,  1049,  1059,  1049,  1060,
    1049,  1061,  1049,  1062,  1049,  1063,  1063,  1064,  1064,  1065,
    1066,  1067,  1067,  1067,  1069,  1068,  1070,  1070,  1071,  1070,
    1072,  1073,  1073,  1073,  1073,  1074,  1074,  1075,  1076,  1076,
    1076,  1076,  1076,  1076,  1076,  1076,  1076,  1078,  1077,  1077,
    1080,  1079,  1081,  1082,  1083,  1083,  1084,  1084,  1085,  1086,
    1086,  1086,  1086,  1086,  1086,  1086,  1086,  1086,  1086,  1086,
    1086,  1086,  1086,  1086,  1086,  1086,  1086,  1087,  1089,  1090,
    1088,  1091,  1091,  1092,  1093,  1094,  1095,  1095,  1097,  1096,
    1098,  1098,  1099,  1099,  1100,  1100,  1100,  1100,  1100,  1100,
    1101,  1101,  1102,  1102,  1103,  1104,  1104,  1104,  1104,  1104,
    1104,  1104,  1104,  1104,  1104,  1105,  1106,  1106,  1107,  1108,
    1108,  1110,  1111,  1112,  1113,  1109,  1114,  1116,  1117,  1115,
    1118,  1119,  1119,  1120,  1120,  1121,  1122,  1122,  1123,  1125,
    1124,  1126,  1126,  1126,  1126,  1128,  1129,  1130,  1127,  1132,
    1131,  1133,  1135,  1134,  1136,  1134,  1137,  1134,  1138,  1138,
    1139,  1139,  1140,  1140,  1141,  1141,  1141,  1142,  1143,  1144,
    1145,  1145,  1145,  1146,  1146,  1147,  1147,  1149,  1150,  1148,
    1151,  1151,  1153,  1152,  1154,  1152,  1155,  1156,  1156,  1156,
    1156,  1157,  1157,  1157,  1157,  1157,  1158,  1159,  1159,  1160,
    1161,  1162,  1162,  1163,  1164,  1164,  1164,  1164,  1164,  1164,
    1165,  1166,  1167,  1167,  1168,  1168,  1169,  1170,  1170,  1171,
    1171,  1172,  1173,  1174,  1174,  1174,  1174,  1174,  1174,  1175,
    1175,  1176,  1177,  1177,  1178,  1178,  1179,  1179,  1180,  1180,
    1181,  1181,  1181,  1181,  1181,  1182,  1182,  1183,  1183,  1184,
    1184,  1185,  1186,  1187,  1187,  1188,  1189,  1189,  1189,  1190,
    1190,  1191,  1191,  1192,  1193,  1193,  1194,  1194,  1195,  1196,
    1197,  1198,  1198,  1199,  1200,  1200,  1201,  1201,  1202,  1202,
    1203,  1204,  1204,  1205,  1205,  1205,  1205,  1206,  1206,  1206,
    1207,  1208,  1208,  1209,  1209,  1209,  1210,  1211,  1211,  1212,
    1212,  1212,  1212,  1212,  1212,  1212,  1212,  1212,  1212,  1212,
    1212,  1212,  1212,  1212,  1212,  1212,  1212,  1212,  1212,  1212,
    1212,  1212,  1212,  1212,  1212,  1213,  1214,  1214,  1215,  1215,
    1215,  1215,  1215,  1216,  1218,  1217,  1219,  1219,  1220,  1221,
    1221,  1222,  1222,  1223,  1223,  1225,  1224,  1226,  1228,  1227,
    1229,  1229,  1230,  1230,  1231,  1231,  1232,  1232,  1232,  1232,
    1233,  1233,  1234,  1235,  1235,  1236,  1237,  1238,  1239,  1240,
    1240,  1241,  1241,  1243,  1242,  1244,  1242,  1245,  1242,  1246,
    1242,  1247,  1242,  1248,  1242,  1249,  1242,  1250,  1250,  1250,
    1250,  1250,  1250,  1252,  1251,  1253,  1253,  1255,  1254,  1254,
    1254,  1254,  1254,  1256,  1256,  1257,  1257,  1258,  1259,  1259,
    1261,  1260,  1262,  1263,  1264,  1264,  1264,  1265,  1265,  1265,
    1265,  1266,  1267,  1267,  1268,  1268,  1269,  1270,  1270,  1270,
    1270,  1270,  1270,  1270,  1270,  1271,  1271,  1272,  1272,  1273,
    1273,  1273,  1273,  1273,  1273,  1273,  1273,  1273,  1273,  1274,
    1274,  1275,  1275,  1275,  1275,  1276,  1276,  1277,  1277,  1278,
    1278,  1278,  1278,  1278,  1278,  1278,  1278,  1278,  1278,  1278,
    1278,  1278,  1278,  1278,  1278,  1278,  1278,  1278,  1278,  1278,
    1278,  1278,  1278,  1279,  1279,  1279,  1281,  1282,  1283,  1284,
    1285,  1286,  1280,  1287,  1287,  1288,  1289,  1289,  1291,  1292,
    1293,  1294,  1295,  1296,  1290,  1297,  1299,  1300,  1301,  1298,
    1302,  1302,  1302,  1302,  1303,  1303,  1303,  1303,  1303,  1304,
    1305,  1305,  1305,  1305,  1306,  1306,  1308,  1309,  1307,  1310,
    1311,  1307,  1312,  1312,  1313,  1313,  1314,  1314,  1314,  1314,
    1314,  1315,  1316,  1316,  1317,  1317,  1318,  1318,  1319,  1319,
    1319,  1319,  1319,  1320,  1320,  1321,  1321,  1322,  1322,  1322,
    1323,  1323,  1324,  1324,  1325,  1325,  1326,  1326,  1326,  1327,
    1327,  1328,  1328,  1328,  1328,  1328,  1328,  1328,  1329,  1329,
    1330,  1330,  1331,  1331,  1332,  1332,  1333,  1333,  1334,  1335,
    1335,  1336,  1336,  1337,  1338,  1338,  1339,  1340,  1340,  1341,
    1341,  1342,  1342,  1343,  1343,  1344,  1344,  1345,  1346,  1346,
    1346,  1346,  1346,  1346,  1346,  1346,  1346,  1346,  1346,  1347,
    1347,  1348,  1348,  1349,  1350,  1352,  1351,  1354,  1353,  1353,
    1355,  1355,  1356,  1356,  1357,  1357,  1358,  1358,  1360,  1359,
    1361,  1362,  1362,  1363,  1364,  1363,  1365,  1366,  1365,  1367,
    1367,  1367,  1367,  1367,  1367,  1367,  1367,  1368,  1369,  1370,
    1371,  1371,  1372,  1373,  1373,  1374,  1374,  1374,  1375,  1376,
    1377,  1377,  1378,  1379,  1379,  1379,  1381,  1380,  1382,  1382,
    1382,  1382,  1382,  1382,  1382,  1382,  1382,  1382,  1382,  1382,
    1383,  1383,  1383,  1383,  1384,  1384,  1384,  1385,  1385,  1385,
    1386,  1386,  1386,  1387,  1387,  1388,  1388,  1388,  1388,  1388,
    1388,  1389,  1389,  1390,  1390,  1391,  1391,  1392,  1392,  1393,
    1394,  1394,  1395,  1395,  1396,  1396,  1397,  1398,  1399,  1400,
    1401,  1401,  1402,  1402,  1403,  1403,  1403,  1404,  1404,  1405,
    1405,  1405,  1406,  1406,  1406,  1406,  1407,  1408,  1408,  1409,
    1409,  1410,  1410,  1411,  1412,  1412,  1412,  1412,  1412,  1412,
    1412,  1413,  1414,  1415,  1416,  1416,  1417,  1417,  1418,  1419,
    1420,  1420,  1421,  1422,  1423,  1423,  1424,  1424,  1424,  1425,
    1425,  1426,  1426,  1427,  1428,  1428,  1429,  1429,  1430,  1430,
    1431,  1431,  1432,  1432,  1433,  1433,  1434,  1434,  1435,  1435,
    1436,  1436,  1437,  1438,  1439,  1439,  1439,  1439,  1440,  1440,
    1441,  1441,  1442,  1442,  1443,  1443,  1443,  1443,  1443,  1443,
    1443,  1443,  1443,  1444,  1444,  1444,  1444,  1444,  1444,  1444,
    1444,  1444,  1445,  1445,  1445,  1446,  1446,  1446,  1446,  1447,
    1447,  1447,  1448,  1448,  1449,  1449,  1449,  1449,  1449,  1449,
    1449,  1449,  1449,  1449,  1449,  1449,  1449,  1449,  1449,  1449,
    1449,  1449,  1449,  1449,  1449,  1449,  1449,  1449,  1449,  1450,
    1450,  1451,  1451,  1451,  1451,  1451,  1452,  1453,  1454,  1455,
    1455,  1455,  1455,  1455,  1455,  1455,  1455,  1456,  1456,  1456,
    1456,  1456,  1456,  1456,  1456,  1457,  1458,  1458,  1458,  1459,
    1459,  1460,  1460,  1460,  1461,  1462,  1462,  1462,  1462,  1463,
    1464,  1465,  1465,  1466,  1466,  1467,  1467,  1467,  1467,  1467,
    1467,  1467,  1467,  1468,  1468,  1468,  1468,  1468,  1468,  1468,
    1468,  1469,  1469,  1469,  1469,  1469,  1469,  1469,  1470,  1470,
    1470,  1470,  1470,  1470,  1470,  1470,  1471,  1471,  1471,  1472,
    1474,  1473,  1475,  1473,  1476,  1473,  1477,  1473,  1478,  1478,
    1478,  1479,  1479,  1480,  1480,  1480,  1481,  1481,  1482,  1482,
    1483,  1485,  1486,  1484,  1487,  1488,  1488,  1489,  1490,  1490,
    1490,  1490,  1490,  1491,  1492,  1492,  1493,  1494,  1495,  1495,
    1495,  1495,  1496,  1496,  1497,  1497,  1497,  1498,  1499,  1499,
    1499,  1500,  1500,  1500,  1500,  1500,  1500,  1500,  1500,  1501,
    1501,  1501,  1501,  1501,  1501,  1501,  1501,  1501,  1501,  1501,
    1501,  1501,  1501,  1501,  1501,  1501,  1501,  1501,  1501,  1501,
    1501,  1502,  1502,  1503,  1504,  1505,  1505,  1506,  1506,  1507,
    1507,  1508,  1508,  1509,  1509,  1510,  1511,  1511,  1512,  1512,
    1513,  1514,  1514,  1514,  1515,  1515,  1516,  1517,  1518,  1519,
    1520,  1520,  1521,  1521,  1521,  1521,  1521,  1521,  1522,  1522,
    1522,  1522,  1523,  1523,  1524,  1524,  1524,  1524,  1524,  1524,
    1524,  1524,  1525,  1525,  1525,  1526,  1526,  1526,  1526,  1526,
    1526,  1528,  1527,  1529,  1529,  1530,  1530,  1530,  1530,  1530,
    1530,  1530,  1530,  1530,  1530,  1530,  1530,  1530,  1530,  1530,
    1530,  1530,  1530,  1530,  1530,  1530,  1530,  1530,  1530,  1530,
    1530,  1530,  1530,  1530,  1530,  1530,  1530,  1530,  1530,  1530,
    1530,  1530,  1530,  1530,  1530,  1530,  1530,  1530,  1530,  1530,
    1530,  1530,  1530,  1530,  1530,  1530,  1530,  1530,  1530,  1530,
    1530,  1530,  1530,  1530,  1530,  1530,  1530,  1530,  1530,  1530,
    1530,  1530,  1530,  1530,  1530,  1530,  1530,  1530,  1530,  1530,
    1530,  1530,  1530,  1530,  1530,  1530,  1530,  1530,  1530,  1530,
    1530,  1530,  1530,  1530,  1530,  1530,  1530,  1530,  1530,  1530,
    1530,  1530,  1530,  1530,  1530,  1530,  1530,  1530,  1530,  1530,
    1530,  1530,  1530,  1530,  1530,  1530,  1530,  1530,  1530,  1530,
    1530,  1530,  1530,  1530,  1530,  1530,  1530,  1530,  1530,  1530,
    1530,  1530,  1530,  1530,  1530,  1530,  1530,  1530,  1530,  1530,
    1530,  1530,  1530,  1530,  1530,  1530,  1530,  1530,  1530,  1530,
    1530,  1530,  1530,  1530,  1530,  1530,  1530,  1530,  1530,  1530,
    1530,  1530,  1530,  1530,  1530,  1530,  1530,  1530,  1530,  1530,
    1530,  1530,  1530,  1530,  1530,  1530,  1530,  1530,  1530,  1530,
    1530,  1530,  1530,  1530,  1530,  1530,  1530,  1530,  1530,  1530,
    1530,  1530,  1530,  1530,  1530,  1530,  1530,  1530,  1530,  1530,
    1530,  1530,  1530,  1530,  1530,  1530,  1530,  1530,  1530,  1530,
    1530,  1530,  1530,  1530,  1530,  1530,  1530,  1530,  1530,  1530,
    1530,  1530,  1530,  1530,  1530,  1530,  1530,  1530,  1530,  1530,
    1530,  1530,  1530,  1530,  1530,  1530,  1530,  1530,  1530,  1530,
    1530,  1530,  1530,  1530,  1530,  1530,  1530,  1530,  1530,  1530,
    1530,  1530,  1530,  1530,  1530,  1530,  1530,  1530,  1530,  1530,
    1530,  1530,  1530,  1530,  1530,  1530,  1530,  1530,  1530,  1530,
    1530,  1530,  1530,  1530,  1530,  1530,  1530,  1530,  1530,  1530,
    1530,  1530,  1530,  1530,  1530,  1530,  1530,  1530,  1530,  1530,
    1530,  1530,  1530,  1530,  1530,  1530,  1530,  1530,  1530,  1530,
    1530,  1530,  1530,  1530,  1530,  1530,  1530,  1530,  1530,  1530,
    1530,  1530,  1530,  1530,  1530,  1530,  1530,  1530,  1530,  1530,
    1530,  1530,  1530,  1532,  1531,  1534,  1533,  1536,  1537,  1535,
    1538,  1538,  1538,  1539,  1539,  1539,  1539,  1539,  1539,  1540,
    1540,  1541,  1542,  1543,  1543,  1544,  1544,  1545,  1545,  1546,
    1546,  1546,  1547,  1547,  1547,  1547,  1547,  1547,  1547,  1547,
    1547,  1547,  1547,  1547,  1547,  1547,  1548,  1548,  1548,  1548,
    1548,  1548,  1548,  1548,  1548,  1548,  1548,  1548,  1548,  1548,
    1548,  1548,  1549,  1550,  1550,  1552,  1551,  1553,  1553,  1554,
    1554,  1555,  1556,  1557,  1557,  1558,  1558,  1559,  1559,  1559,
    1560,  1560,  1561,  1561,  1562,  1563,  1563,  1564,  1564,  1565,
    1566,  1568,  1569,  1567,  1570,  1570,  1571,  1571,  1572,  1572,
    1572,  1572,  1572,  1572,  1572,  1573,  1573,  1574,  1574,  1575,
    1575,  1576,  1576,  1577,  1578,  1579,  1580,  1580,  1581,  1582,
    1582,  1583,  1584,  1584,  1586,  1585,  1587,  1587,  1587,  1587,
    1587,  1587,  1587,  1587,  1587,  1587,  1587,  1587,  1587,  1587,
    1587,  1587,  1587,  1587,  1587,  1587,  1587,  1587,  1587,  1587,
    1587,  1587,  1587,  1587,  1587,  1587,  1587,  1587,  1587,  1587,
    1587,  1587,  1587,  1587,  1587,  1587,  1587,  1587,  1587,  1587,
    1587,  1587,  1587,  1587,  1587,  1587,  1587,  1587,  1587,  1587,
    1587,  1587,  1587,  1587,  1587,  1587,  1587,  1587,  1587,  1587,
    1587,  1587,  1587,  1587,  1587,  1587,  1587,  1587,  1587,  1587,
    1587,  1587,  1587,  1587,  1587,  1587,  1587,  1587,  1587,  1587,
    1587,  1587,  1587,  1587
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
       5,     7,     7,     9,     4,     6,     0,     3,     1,     1,
       4,     4,     4,     4,     4,     4,     1,     1,     1,     1,
       4,     4,     2,     2,     2,     2,     2,     1,     1,     2,
       1,     1,     1,     2,     4,     6,     6,     3,     5,     5,
       3,     1,     1,     3,     1,     3,     1,     3,     0,     0,
      11,     0,     2,     0,     0,     0,     9,     0,     3,     0,
       0,    10,     0,     1,     0,     1,     1,     2,     0,     3,
       0,     3,     0,     1,     1,     2,     0,     3,     0,     3,
       3,     1,     4,     3,     1,     3,     1,     3,     1,     3,
       1,     2,     0,     3,     0,     3,     0,     4,     0,     4,
       0,     4,     2,     3,     1,     3,     1,     1,     1,     1,
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
       3,     2,     2,     1,     1,     0,     2,     1,     2,     3,
       3,     3,     3,     1,     1,     1,     1,     0,     3,     1,
       0,     3,     2,     2,     1,     3,     1,     3,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     0,     0,
       7,     1,     1,     2,     2,     2,     3,     4,     0,     3,
       0,     1,     1,     2,     1,     1,     1,     1,     1,     1,
       0,     1,     1,     2,     2,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     0,     1,     1,     1,
       1,     0,     0,     0,     0,    13,     1,     0,     0,     6,
       2,     1,     2,     2,     2,     1,     1,     2,     1,     0,
       3,     2,     1,     1,     1,     0,     0,     0,    14,     0,
       5,     1,     0,     3,     0,     7,     0,     5,     1,     2,
       0,     1,     1,     1,     0,     1,     1,     2,     2,     2,
       1,     1,     1,     1,     3,     1,     1,     0,     0,     7,
       1,     2,     0,     3,     0,     4,     2,     0,     2,     1,
       1,     1,     1,     1,     1,     1,     3,     0,     1,     1,
       1,     1,     2,     2,     2,     5,     8,     1,     1,     1,
       4,     4,     1,     1,     1,     1,     2,     3,     6,     1,
       3,     1,     1,     1,     3,     6,     9,     1,     1,     1,
       1,     2,     0,     1,     1,     3,     1,     3,     1,     3,
       1,     3,     1,     1,     1,     1,     3,     1,     3,     1,
       3,     1,     1,     1,     3,     2,     0,     1,     1,     1,
       3,     1,     3,     7,     0,     7,     0,     6,     3,     1,
       3,     1,     2,     5,     0,     7,     0,     2,     0,     1,
       5,     2,     5,     0,     5,     6,     4,     0,     1,     1,
       5,     0,     2,     0,     5,     4,     2,     1,     3,     2,
       2,     2,     2,     2,     2,     1,     2,     2,     2,     2,
       2,     2,     2,     1,     1,     1,     1,     2,     2,     1,
       1,     1,     1,     1,     1,     5,     1,     1,     2,     4,
       4,     6,     2,     1,     0,    11,     0,     2,     5,     0,
       1,     0,     2,     1,     2,     0,     3,     1,     0,     4,
       0,     2,     1,     3,     1,     1,     3,     4,     4,     2,
       1,     1,     1,     0,     1,     7,     2,     2,     2,     2,
       2,     1,     2,     0,     3,     0,     3,     0,     3,     0,
       3,     0,     3,     0,     4,     0,     4,     1,     1,     1,
       1,     1,     1,     0,     4,     0,     1,     0,     4,     1,
       2,     2,     2,     0,     1,     1,     2,     2,     0,     2,
       0,     4,     3,     5,     0,     2,     4,     1,     1,     1,
       1,     1,     0,     1,     1,     3,     2,     5,     2,     5,
       5,     5,     5,     5,     5,     0,     2,     1,     2,     2,
       2,     2,     2,     2,     1,     2,     2,     2,     2,     1,
       2,     2,     2,     2,     1,     1,     1,     0,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     1,     1,     1,
       1,     1,     1,     1,     1,     2,     2,     2,     2,     2,
       1,     1,     1,     0,     3,     2,     0,     0,     0,     0,
       0,     0,    15,     0,     2,     2,     0,     1,     0,     0,
       0,     0,     0,     0,    15,     2,     0,     0,     0,    10,
       0,     1,     3,     3,     2,     4,     3,     3,     3,     1,
       2,     2,     2,     2,     1,     1,     0,     0,     8,     0,
       0,     9,     0,     1,     1,     2,     2,     2,     2,     1,
       1,     1,     0,     1,     1,     2,     2,     2,     8,     2,
       2,     4,     2,     0,     1,     1,     3,     2,     2,     1,
       1,     3,     1,     1,     2,     1,     3,     3,     3,     1,
       3,     1,     1,     1,     1,     1,     1,     1,     2,     4,
       1,     3,     1,     3,     2,     4,     1,     3,     1,     2,
       4,     1,     3,     1,     1,     1,     2,     3,     4,     2,
       4,     0,     2,     2,     4,     1,     3,     1,     1,     1,
       2,     1,     1,     1,     1,     1,     2,     6,     6,     0,
       1,     0,     1,     2,     1,     0,     5,     0,     5,     1,
       0,     3,     1,     3,     1,     3,     1,     1,     0,     4,
       1,     2,     1,     0,     0,     3,     0,     0,     3,     1,
       1,     1,     1,     1,     1,     2,     2,     4,     3,     3,
       1,     3,     2,     1,     1,     0,     1,     1,     1,     1,
       0,     1,     3,     1,     3,     1,     0,     3,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       7,     6,     4,     4,     1,     1,     1,     0,     1,     2,
       1,     1,     1,     1,     3,     2,     1,     1,     2,     1,
       1,     0,     3,     1,     3,     1,     3,     1,     1,     6,
       0,     3,     1,     3,     0,     1,     4,     5,     2,     1,
       1,     4,     1,     3,     4,     4,     4,     1,     3,     1,
       1,     1,     2,     1,     1,     1,     4,     0,     1,     0,
       1,     1,     2,     2,     1,     1,     1,     1,     1,     4,
       1,     3,     1,     1,     1,     2,     1,     1,     2,     2,
       1,     3,     2,     2,     1,     3,     1,     2,     4,     1,
       2,     1,     3,     4,     0,     1,     0,     1,     0,     1,
       1,     3,     1,     3,     1,     2,     1,     3,     2,     2,
       0,     2,     1,     1,     5,     3,     5,     3,     1,     3,
       1,     1,     0,     1,     3,     3,     3,     6,     4,     4,
       4,     4,     5,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     0,     1,     1,     1,     1,
       1,     1,     1,     4,     0,     1,     4,     1,     5,     5,
       1,     1,     1,     1,     1,     4,     1,     4,     6,     4,
       1,     4,     1,     7,     1,     1,     1,     4,     6,     0,
       2,     4,     1,     1,     1,     1,     1,     1,     1,     3,
       1,     1,     3,     5,     3,     5,     7,     3,     1,     1,
       3,     5,     3,     5,     7,     1,     0,     3,     5,     1,
       2,     2,     4,     3,     1,     1,     1,     1,     1,     2,
       2,     0,     3,     0,     3,     1,     1,     1,     1,     1,
       1,     1,     4,     1,     1,     1,     1,     1,     1,     1,
       4,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     4,     1,     3,     1,     3,
       0,     7,     0,     8,     0,     6,     0,     8,     0,     1,
       2,     1,     3,     1,     3,     5,     1,     1,     1,     1,
       1,     0,     0,     9,     5,     1,     1,     6,     0,     3,
       1,     3,     4,     1,     0,     2,     4,     6,     0,     1,
       1,     1,     1,     3,     1,     2,     3,     1,     1,     2,
       2,     1,     1,     1,     2,     2,     2,     2,     4,     3,
       2,     3,     3,     3,     1,     1,     1,     1,     1,     1,
       5,     5,     5,     5,     5,     4,     4,     3,     4,     1,
       1,     1,     3,     1,     5,     7,     5,     0,     2,     1,
       1,     0,     3,     1,     3,     1,     1,     1,     0,     3,
       1,     1,     1,     1,     4,     6,     1,     1,     2,     3,
       1,     1,     1,     1,     1,     1,     1,     1,     5,     5,
       4,     5,     1,     4,     4,     4,     6,     6,     8,     8,
      13,    11,     1,     7,     4,     4,     4,     6,     6,     8,
       8,     0,     4,     1,     2,     1,     1,     1,     1,     1,
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
       1,     1,     1,     0,     3,     0,     3,     0,     0,     6,
       0,     2,     2,     7,     3,     3,     2,     2,     2,     1,
       3,     1,     3,     1,     3,     1,     3,     1,     1,     1,
       2,     2,     1,     1,     2,     4,     5,     7,     7,     9,
       1,     1,     1,     1,     1,     1,     3,     2,     3,     3,
       3,     5,     5,     5,     5,     5,     4,     4,     3,     4,
       1,     1,     1,     1,     3,     0,     5,     1,     3,     3,
       3,     1,     1,     2,     1,     1,     3,     1,     3,     3,
       1,     1,     1,     3,     2,     3,     6,     1,     3,     1,
       1,     0,     0,     6,     0,     2,     0,     1,     1,     2,
       2,     1,     1,     4,     3,     1,     2,     5,     2,     2,
       5,     0,     2,     1,     1,     2,     6,     6,     1,     0,
       1,     2,     1,     2,     0,     2,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const unsigned short yydefact[] =
{
     820,     0,  2230,     0,     0,     0,   869,   180,     0,   845,
     848,   178,   183,   824,     0,   818,   821,   822,   825,   828,
     829,   827,   865,   866,   868,   826,   136,   133,     0,   129,
     131,   130,   134,  2258,   703,   643,   310,  1678,  1676,   863,
     176,   186,   864,   179,     1,   830,   823,   867,   128,   132,
     135,     0,     0,   620,     0,     0,   177,   872,   938,   621,
     873,   874,   870,   655,   930,     0,   931,   939,   937,   186,
     181,   199,     0,   184,   200,   235,     0,   850,  1228,     0,
       0,   849,  1216,   857,     0,     0,   842,   841,   843,   819,
     831,   832,   851,   835,   836,   837,   840,   838,   839,   844,
       0,  1677,   932,   871,     0,     0,   946,   944,   945,   934,
     933,   308,   186,  1152,   193,   187,   186,   192,   232,     0,
     702,     0,     0,     0,     0,   176,   569,   907,   833,     0,
     342,   328,   202,   314,   279,   298,   319,   321,   318,     0,
     340,     0,   327,   320,   324,   330,   329,   186,   331,   311,
     334,   312,   313,   943,   942,     0,    22,    23,    13,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   951,     0,
     527,   519,    16,   526,   938,    15,     0,   949,     0,   309,
       0,   185,  1153,   182,     0,   199,   201,   273,   204,   261,
     267,   268,   252,   225,   263,   202,   240,   241,     0,   227,
     279,   298,   250,   253,   248,     0,   223,     0,   259,   251,
     256,   266,   265,   186,   269,   186,   238,   239,   236,   272,
       0,     0,     0,     0,   858,   176,   176,     0,     0,   203,
       0,     0,   332,     0,     0,   333,     0,     0,     0,     0,
       0,     0,     0,   277,     0,   940,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   533,     0,
       0,     0,   656,   444,   446,  1223,     0,     0,     0,  1643,
       0,   438,     0,     0,     0,   437,     0,   454,   529,     0,
       0,     0,     0,     0,   532,     0,   403,   402,   409,   450,
     447,   404,   405,   407,   408,   445,   448,   453,   528,   499,
     496,   505,   502,     0,     0,    17,    18,    19,    20,    21,
       0,    14,   490,     0,     0,   947,     0,   188,   191,   189,
     190,     0,   196,   195,   194,   197,   205,   206,   207,   210,
     274,   186,   274,     0,     0,     0,     0,   186,   270,   271,
       0,     0,   186,     0,   274,     0,     0,   249,   233,  1229,
       0,     0,  1217,  2264,   570,   908,   852,     0,   214,   215,
       0,     0,   291,   293,   288,   289,   285,   287,   284,   286,
     283,     0,   293,   304,   305,   301,   303,   300,   302,   295,
       0,     0,     0,   344,     0,   347,   349,   222,     0,   221,
       0,   186,     0,     0,   554,   625,     0,     0,     0,     0,
       0,     0,     0,     0,   551,   537,   542,     0,   538,   541,
     540,   634,     0,   633,   556,     0,    11,   172,   436,   411,
     410,     0,  1158,     0,     0,   452,  1651,  1649,  1650,  1646,
    1648,  1645,  1647,  1639,     0,     0,     0,   451,     0,     0,
       0,     0,     0,     0,     0,   657,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   165,   166,   167,   168,   169,   170,   534,
     535,   536,   465,     0,     0,   464,   474,     0,     0,   415,
       0,     0,   416,   406,   412,   414,   417,   418,   419,   420,
     421,   413,   443,   442,     0,     0,     0,     0,     0,     0,
       0,    12,    93,     0,   950,     0,   935,   198,     0,     0,
     262,     0,   264,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   260,     0,   186,   234,   237,   962,   701,   875,
     962,     0,  2262,  2264,  1152,  1778,   846,     0,   962,     0,
       0,   315,   280,     0,     0,   290,   307,   281,   306,     0,
     299,     0,   322,     0,   316,     0,   341,     0,   346,   336,
       0,     0,   325,   278,   335,     0,     0,   525,     0,     0,
     522,   521,   524,   520,   531,   516,     0,   516,     0,   539,
       0,   543,     0,   298,     0,   523,   530,   282,     0,  1224,
    1718,     0,     0,     0,     0,     0,   439,     0,     0,   455,
       0,     0,     0,     0,   457,   456,   475,   466,   481,   484,
     485,   482,   488,   487,   486,   476,   477,   478,   479,   480,
     422,   467,   471,   489,   483,   470,   489,   449,   500,   497,
     506,   503,   514,     0,    98,   491,    94,    95,    97,   493,
       0,     0,   235,     0,     0,     0,   242,   243,     0,   246,
       0,     0,   254,     0,   244,   224,   208,     0,   257,   276,
     968,     0,   963,   964,   962,     0,   859,  2263,  2261,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  2245,     0,  1344,  1343,     0,  1345,
       0,   396,  1342,  1259,     0,     5,  1341,   397,   394,     0,
     399,   174,   489,  1129,     0,     0,  1351,   125,   393,   392,
       0,     0,   387,   489,     0,  1295,  2238,     0,   398,   361,
       0,     3,     2,     0,   395,  1256,     0,     0,   388,   385,
     400,     0,     0,     0,     0,  1349,  1339,   391,     0,     0,
       0,     0,     0,     0,     0,     0,  1338,     0,     0,     0,
     175,     0,   384,   383,     0,     0,  2242,  2241,     0,     0,
       0,   137,     0,   390,   389,     0,     0,   386,   489,     0,
       0,   489,     0,   563,     0,     0,     0,     0,     0,     0,
     489,   807,  1226,     0,     0,  1140,     0,  2231,     0,   105,
       0,     0,   879,     0,     0,     0,     0,   808,     0,     0,
    1821,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     672,     0,     0,  2266,  2267,  2268,  2269,  2270,  2271,  2272,
    2273,  2274,  2275,  2276,  2277,  2278,  2279,  2280,  2281,  2282,
    2283,  2284,  2285,  2286,  2287,  2288,  2289,  2290,  2291,  2292,
    2293,  2294,  2295,  2296,  2297,  2298,  2299,  2300,  2301,  2302,
    2303,  2304,  2305,  2306,  2307,  2308,  2309,  2310,  2311,  2312,
    2313,  2314,   917,  2315,  2316,  2317,  2318,  2319,  2320,  2321,
    2322,  2323,  2324,  2325,  2326,  2327,  2328,  2329,  2330,  2331,
    1120,  1122,  1117,  1119,  1118,  1121,  2332,  2333,  1249,  2334,
    1255,  1254,  2335,  2336,  2337,  2338,  2339,  2340,  2341,  2342,
    2343,  2344,  1406,  2345,  2346,  2347,  2348,  2349,  2350,  2351,
    2352,  2353,  2265,   847,   574,     0,   912,     0,   910,     0,
     343,   216,   217,     0,   292,   297,     0,     0,     0,     0,
     345,   348,     0,   220,     0,     0,   555,     0,   629,     0,
     631,   509,     0,     0,   510,     0,   553,     0,   550,   547,
     518,   508,   557,     0,   171,  1720,  1721,  1719,     0,   441,
    1223,     0,  1644,  1223,   440,  1223,  1223,  1223,  1223,  1223,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    93,   948,     0,   211,   275,
     226,     0,     0,   186,     0,     0,     0,     0,     0,  1230,
       0,     0,  1218,   380,   378,   379,  1253,  1057,  1056,  1062,
       0,  1618,  1619,     0,     0,  1279,   644,   645,  1280,  1610,
    1611,  1282,   834,  1092,  1097,  2240,   637,   124,  2253,     0,
       0,  1294,     7,     0,     6,     0,  2246,  1093,     0,  1186,
    1185,  1132,  1184,  1131,   433,  1352,  1340,     0,  1250,   860,
     423,  1780,  1346,   126,     0,  1096,   123,     0,   814,    24,
     639,   401,     0,   813,  1089,   815,     0,  1350,   901,   900,
     903,   899,   902,  2255,     0,   897,     0,   638,   994,   898,
    2249,     0,  2239,   122,  1252,   991,   704,   989,     0,   635,
    2234,   752,   751,   753,   749,     0,     0,  1251,  1004,   640,
    1405,     0,  2221,  1400,  1403,  2211,  2214,  2215,  2217,  2220,
       0,     0,     0,     0,  1063,  1058,     0,  1043,  1044,  1045,
    1046,  1052,  1054,  1053,  1051,  1050,     0,     0,     0,  1049,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1035,  1026,  1027,   977,     0,   975,  1077,
     431,    24,     0,  2236,   127,   636,     0,  1227,  1225,  1151,
       0,  1769,  1770,  1152,  1133,  1353,     0,     0,     0,     0,
       0,     0,     0,     0,    63,     0,   938,     0,    69,     0,
     103,   612,     0,   659,   658,     0,  1123,  1011,  1127,     0,
       0,  1078,  1244,     0,     0,  1130,   664,   661,   662,     0,
     666,   667,     0,   669,   670,     0,   665,   972,   974,     0,
       0,   973,   754,   970,   715,   966,   929,     0,     0,     0,
       0,   676,   677,     0,     0,   927,   924,   925,   921,   922,
     923,   916,   920,   919,     0,     0,     0,     0,     0,     0,
     578,   580,   572,   575,   576,   914,  2264,   909,   911,   853,
       0,   294,   296,   323,   317,     0,     0,   326,   626,   628,
       0,     0,     0,   516,   516,   544,     0,   291,     0,     0,
    1748,  1635,  1637,  1749,     0,     0,  1641,  1746,     0,     0,
    1745,     0,     0,     0,  1747,     0,     0,     0,     0,     0,
       0,     0,  2221,  1636,  1744,  1638,  1733,     0,  1722,  1724,
    1728,  1731,  1759,  1802,  1760,  1812,  2222,  2212,  1732,  1161,
    1652,  1160,  1159,  1162,  1164,  1163,  1157,   468,   469,   473,
     458,     0,   461,   472,     0,   460,   501,   498,   507,   504,
     515,   492,    96,   494,   936,     0,   247,   231,     0,   229,
     255,   245,   235,   258,   969,   176,   965,   876,   176,     0,
       0,     0,  1324,  1325,     0,     0,     0,  1296,  1299,  1301,
    1302,  1303,  1307,  1306,  1304,  1305,     0,     0,     0,  1297,
    1298,     0,     0,     0,     0,     0,     0,     0,     0,  1094,
       0,    24,  1181,  1183,  1182,     0,   426,   427,   424,   425,
     982,     0,     0,   366,    25,   360,     0,     0,  1086,     0,
       0,     0,     0,     0,     0,     0,   998,  1779,     0,     0,
       0,     0,     0,     0,  2236,     0,     0,   138,     0,     0,
    1008,  1000,  1001,  1006,     0,     0,  2213,     0,  2224,  1401,
    1402,     0,     0,   926,   429,  2205,  1021,   350,     0,     0,
     564,   617,   616,   614,   619,  1029,   618,  1034,  1030,  1033,
     806,   798,   792,   804,   805,   790,   791,   799,   794,   800,
     793,   803,   797,   801,   796,   802,   789,   795,   782,   788,
    1031,  1032,     0,  1039,  1047,  1036,  1037,  1041,  1042,  1040,
    1038,  1048,     0,     0,     0,   816,     0,     0,     0,     0,
       0,   764,   763,   760,  2237,  2244,    24,  1147,  1148,  1149,
    1150,  1144,  1142,  1240,  1152,  1134,  1135,  1138,  1154,  2232,
       0,     0,     0,     0,    99,     0,   100,     0,     0,     0,
      74,     0,     0,     0,   112,   107,     0,   660,   906,     0,
     905,     0,   489,  1125,     0,   957,   958,   981,   952,   953,
     809,   979,  1080,  1246,     0,  1248,  1247,  1877,  1993,  1989,
    1995,  2027,  2007,  1998,  1957,  1919,  2046,  2013,  2021,  1910,
    2016,  1878,  1825,  2008,  1915,  1966,  2100,  1945,  1933,  1946,
    2044,  2047,  2015,  1969,  2050,  1837,  2107,  2043,  2071,  1848,
    2143,  1934,  2116,  1830,  2076,  1846,  1905,  1952,  1972,  2066,
    2094,  2099,  1829,  2024,  2052,  1841,  1843,  1866,  1883,  1903,
    1913,  1923,  1976,  1979,  2037,  2048,  2054,  2055,  2072,  2117,
    2128,  1828,  1859,  1882,  1881,  1889,  1891,  1899,  1909,  1930,
    1948,  1951,  1977,  1985,  2041,  2051,  2061,  2067,  2068,  2070,
    2095,  2125,  2136,  1849,  1852,  1863,  1869,  1871,  1876,  1880,
    1886,  1894,  1896,  1897,  1898,  1908,  1918,  1925,  1941,  1942,
    1953,  1971,  1975,  1988,  2004,  2035,  2045,  2049,  2056,  2064,
    2073,  2083,  2087,  2104,  2110,  2114,  2122,  2127,  2130,  1872,
    1990,  2032,  1857,  1858,  1875,  1879,  1885,  1887,  1901,  1902,
    1912,  1921,  1926,  1928,  1929,  1935,  1943,  1960,  1961,  1974,
    2002,  2006,  2009,  2014,  2018,  2026,  2033,  2034,  2039,  2057,
    2058,  2063,  2069,  2074,  2080,  2081,  2082,  2084,  2086,  2088,
    2097,  2119,  2120,  2121,  2126,  2142,  1832,  1984,  1992,  1994,
    2090,  1834,  1838,  1842,  1847,  1853,  1854,  1867,  1868,  1870,
    1873,  1884,  1900,  1920,  1922,  1932,  1936,  1938,  1939,  1947,
    1956,  1958,  1959,  1970,  1983,  2001,  2019,  2020,  2036,  2038,
    2042,  2053,  2075,  2085,  2093,  2115,  2118,  2132,  2133,  2134,
    1865,  1835,  1855,  1856,  1862,  1931,  1864,  1888,  1890,  1904,
    1981,  2105,  1914,  1916,  1924,  1927,  1949,  1950,  1955,  1962,
    1963,  1964,  2145,  1996,  1997,  2000,  2005,  2010,  2017,  2022,
    2023,  2025,  2031,  2060,  2062,  2078,  2089,  2091,  2092,  2096,
    2101,  2102,  2106,  2108,  2109,  2124,  2129,  2131,  2135,  2137,
    2141,  1991,  2140,  1831,  1833,  1836,  1840,  1850,  1874,  1892,
    1893,  1895,  1906,  1937,  1940,  1980,  1986,  1999,  2003,  2138,
    2139,  2040,  2059,  2065,  2077,  2079,  2098,  2103,  2113,  2123,
    1845,  1839,  1844,  1861,  1911,  1954,  1967,  1968,  2028,  2030,
    2112,  1987,  1944,  2011,  1860,  1907,  1917,  1982,  1965,  2012,
    1851,  1973,  1978,  2111,  2029,     0,  1823,  1826,  1827,   692,
       0,     0,     0,   681,   715,   715,   712,     0,     0,   716,
       0,    26,   680,   683,     0,   690,   686,   928,   918,  1776,
    1777,  1767,  1767,  1370,     0,     0,  1679,     0,     0,  1354,
       0,     0,  1355,  1398,     0,     0,  1399,     0,     0,  1718,
       0,  1368,     0,  1417,  1416,  1415,  1413,  1414,  1412,  1410,
    1407,  1497,  1496,  1408,  1409,  1418,  1700,  1411,  1783,  1782,
    1781,  1419,  2264,  2264,   591,   582,   573,     0,   577,  2264,
     913,   176,     0,   337,   219,     0,     0,  1659,  1657,  1658,
    1654,  1656,  1653,  1655,   517,     0,   512,   511,     0,   549,
     548,   173,  1730,  1729,     0,     0,  1667,  1665,  1666,  1662,
    1664,  1661,  1663,  1640,     0,  1718,     0,     0,  1565,     0,
       0,  1736,  1734,  1735,  1565,  1565,  1565,  1565,  1737,     0,
       0,     0,  1514,  1708,     0,  1725,     0,     0,     0,     0,
    1792,  1793,  1794,  1795,  1796,  1797,  1740,     0,     0,     0,
       0,   463,   462,     0,     0,   186,   228,   209,  1231,   176,
    1219,     0,     0,     0,     0,     0,     0,  1471,  1470,  1469,
    1331,     0,  1337,  1333,  1335,  1326,     0,  1574,  1323,  1319,
    1293,  1292,     0,  1318,  1314,     0,  1310,  1308,     0,  1617,
       0,  1620,  1622,   648,     0,   647,  1609,     0,  1612,  1614,
    2254,  2251,     0,     0,  1260,   489,   358,  1281,     0,     0,
    1257,  1013,  1090,  1091,  1088,  1087,     0,   904,     0,     0,
     622,     0,     0,     0,   992,   990,   706,   707,     0,   711,
       0,     0,  2235,  2243,   750,     0,   142,     0,  1002,  1009,
       0,     0,  1017,  2216,  2229,     0,  2227,  1404,  2219,  2218,
       0,     0,     0,  1023,   353,     0,     0,     0,     0,    24,
    1059,  1060,   567,     0,     0,     0,   783,   784,  1028,   978,
     976,   817,   432,     0,  1069,   761,   762,   381,     0,  1152,
    1241,  1156,  1141,  1136,     0,     0,  1137,  2264,     0,     0,
       0,     0,     0,     0,     0,    64,    93,     0,     0,   118,
     113,     0,   108,     0,   115,   109,   890,   882,   888,     0,
    1124,     0,  1126,  1128,     0,     0,   961,     0,     0,     0,
       0,  1079,  1245,     0,     0,  1822,  1824,  2264,   663,   668,
     671,   684,   682,   641,     0,   739,   737,   735,   733,   743,
     741,     0,     0,   731,   779,   729,   714,   725,   723,   777,
     755,     0,   717,   727,   971,   967,     0,     0,     0,     0,
     689,     0,     0,     0,     0,     0,     0,     0,  1625,     0,
    1492,  1493,  1788,  1450,  1514,     0,     0,     0,  1786,     0,
    1430,  1425,  1424,  1437,  1436,  1441,  1441,  1439,  1440,  1431,
    1426,     0,     0,  1432,  1433,  1701,  2147,     0,     0,     0,
     579,   581,     0,     0,   594,   586,   588,     0,   583,   584,
       0,     0,   602,   604,     0,     0,   600,   915,   854,   218,
       0,   630,   632,   627,     0,   516,   546,   545,     0,     0,
       0,     0,     0,     0,  1757,  1641,     0,     0,  1732,  1567,
    1568,  1566,     0,  1761,     0,     0,     0,     0,     0,     0,
       0,  1723,     0,  1503,  1504,  1506,  1509,     0,  1515,  1516,
       0,     0,  1565,  1710,  1704,  1726,  1742,  1743,  1741,  1739,
       0,     0,     0,  2223,   459,   495,     0,   230,  1187,   877,
    1165,     0,     0,     0,     0,  1331,     0,     0,     0,  1327,
       0,     0,     0,  1321,  1605,  1603,  1572,  1584,  1586,  1590,
    1592,  1583,  1577,  1582,  1596,  1575,  1604,  1580,  1595,  1581,
    1602,  1594,  1477,  1569,  1570,  1571,     0,  1316,  1312,     0,
       0,  1300,     0,     0,   646,     0,     0,     0,  2250,     0,
       4,     8,    10,     0,   489,   428,     0,     0,     0,  1010,
       0,     0,     0,     0,     0,     0,     0,     0,   705,     0,
       0,   159,   157,     0,     0,   139,     0,   149,   155,   715,
     144,   146,     0,  1007,  1018,  1019,     0,     0,  2225,   430,
       0,  2206,  2207,  1022,     0,     0,  1020,   352,   357,   624,
     351,     0,   354,   359,     0,   489,  1376,   615,   613,     0,
     786,  1068,  1070,     0,   382,  1145,  1143,     0,  1155,  1139,
       0,     0,  1236,     0,     0,     0,   101,     0,     0,    75,
      81,    71,  2264,  2264,   111,   106,   120,   116,     0,   110,
     780,   891,   641,  2264,   881,   880,   889,  1012,     0,     0,
     959,   960,   954,   980,   489,  1085,  1081,  1082,  1084,  2144,
    2146,   693,   687,   685,     0,    24,     0,  2264,  2264,  2264,
    2264,  2264,  2264,   745,   719,   747,   721,  2264,  2264,  2264,
    2264,     0,   713,   718,  2264,   641,   775,   773,   776,   774,
       0,     0,    46,    44,    41,    35,    39,    43,    38,    31,
      40,     0,    34,    37,    32,    42,    33,    45,    36,     0,
      29,    47,   767,     0,   691,  1768,     0,  1766,  1718,  1764,
    1705,  1706,  1698,  1684,  1699,     0,     0,     0,  1055,  1491,
    1494,     0,     0,     0,  1388,  1360,  1791,  1790,  1789,     0,
       0,     0,  1435,  1438,     0,     0,     0,     0,     0,  1383,
       0,  1382,     0,  1384,  1379,  1380,  1381,  1372,  1373,     0,
       0,     0,   593,   598,     0,     0,  2264,  2264,   571,   585,
     608,   596,   610,  2264,  2264,   606,   590,   601,   846,   338,
       0,   513,  1804,     0,  1805,     0,  1815,     0,  1816,     0,
    1674,  1672,  1673,  1669,  1671,  1668,  1670,  1642,     0,     0,
       0,     0,  1758,     0,     0,     0,  1756,     0,     0,     0,
       0,  1738,  1755,     0,  1507,     0,  1634,  1510,     0,     0,
       0,     0,  1502,  1520,  1522,  1524,  1564,  1563,  1562,  1526,
    1542,     0,  1517,  1518,  1713,  1283,     0,     0,     0,  1803,
       0,  1814,   212,     0,  1213,  1232,   846,     0,  1220,  1213,
       0,  1626,     0,  1459,     0,  1462,  1629,     0,  1467,     0,
       0,  1328,  1329,     0,     0,  1332,  1334,  1336,     0,  1320,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1475,  1474,  1473,     0,  1478,  1479,     0,  1315,     0,  1309,
    1311,  1621,     0,  1623,  1613,     0,  1615,  2252,  1289,     0,
    1285,     0,     0,  1290,   861,     0,     0,     0,     0,     0,
    1347,  2257,  2256,   623,     0,     0,    48,     0,   708,   710,
     709,  1348,   715,  2264,  2264,   151,   649,   161,   153,   163,
     143,   150,  2264,     0,     0,     0,     0,     0,  2228,     0,
       0,     0,     0,     0,     0,  1061,     0,  1377,   565,     0,
     785,  1066,     0,  1242,  1243,  2233,     0,    93,     0,    65,
       0,     0,     0,    78,     0,    93,    93,   119,   114,  2264,
    2264,   104,     0,   892,   886,   894,   893,   883,   561,   941,
       0,     0,     0,   695,   674,   688,   642,   756,     0,   740,
     738,   736,   734,   744,   742,     0,  2264,     0,  2264,   732,
     730,   726,   724,   778,   728,    24,   768,     0,     0,     0,
      27,     0,  1771,     0,  1685,     0,     0,  1697,  1680,  1696,
    1495,     0,  1452,     0,  1387,     0,     0,  1787,     0,  1784,
       0,  1443,  1447,  1423,  1445,  1448,     0,  1434,  1702,     0,
       0,     0,     0,     0,     0,  2148,  1386,  1385,  1374,  1369,
    1371,  1422,     0,     0,   595,   592,   587,   589,     0,  2264,
    2264,   603,   605,  2264,  2264,     0,  1660,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1754,  1762,  1750,
    1751,  1752,  1753,  1511,     0,  1505,  1525,  1529,     0,  1542,
    1528,     0,     0,  1543,  1558,  1555,  1556,  1553,  1561,  1560,
    1554,  1557,     0,     0,     0,     0,     0,  1559,     0,     0,
       0,  1499,  1500,  1727,     0,  1519,  1513,  1284,  1711,  1393,
    1389,  1390,  1395,  1394,  1709,  1283,     0,     0,  1211,  1212,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1210,     0,     0,  1198,  1199,  1200,  1197,  1202,  1203,
    1204,  1201,  1188,  1179,     0,     0,  1235,     0,  2264,     0,
    1174,     0,     0,     0,     0,     0,     0,     0,  1166,  1167,
       0,  1098,  1630,     0,  1631,     0,     0,     0,     0,  1466,
    1465,  1331,  1464,  1456,  1322,  1606,     0,     0,     0,     0,
       0,     0,  1607,  1599,     0,     0,     0,  1599,  1635,  1472,
    1485,  1490,     0,  1487,  1484,  1486,     0,  1488,  1476,  1480,
    1481,  1331,  1317,  1313,     0,     0,  1288,  1287,     0,  1272,
       9,     0,  1262,   862,  1095,   364,  1262,     0,     0,  2248,
       0,     0,   993,    49,     0,   765,   160,   158,     0,  2264,
       0,     0,     0,  2264,   156,   145,     0,   148,   147,     0,
     999,  1003,     0,  2210,  2209,  2208,     0,     0,   356,     0,
     568,     0,  2264,   787,     0,   641,  1146,     0,  1237,    70,
       0,     0,   102,    68,    93,    76,    82,     0,   121,   117,
     781,  2264,   896,   641,   895,     0,   558,     0,   811,   812,
     810,  1083,   698,   696,     0,   678,   675,     0,   746,   720,
     748,   722,   757,   771,   772,   769,   770,    30,    28,     0,
    1765,  1714,  1686,  1682,  1681,     0,  1451,  1718,  1454,     0,
    1362,  1357,  1356,  1359,     0,     0,  1442,     0,     0,  1714,
       0,     0,  2185,  2183,     0,     0,  2167,  2182,     0,     0,
    2184,     0,     0,     0,     0,     0,  2221,  2181,  2173,  2200,
    2201,     0,  2165,  2168,  2169,  2180,  2172,  2202,     0,  2158,
    2157,  2161,  2163,     0,  2156,     0,  2159,  2150,     0,     0,
     599,   597,   609,   611,   607,     0,     0,     0,  1806,  1807,
       0,     0,  1817,  1818,     0,     0,  1717,     0,  1642,     0,
       0,     0,  1508,  1527,  1521,  1523,  1530,  1532,  1530,     0,
    1537,  1530,     0,  1535,  1530,     0,  1545,  1544,     0,  1546,
       0,  1498,     0,  1397,  1396,  1392,  1712,     0,   235,  1205,
    1206,  1207,  1209,  1192,  1190,  1189,  1193,  1194,  1191,  1208,
    1195,  1196,  1180,   986,  1215,   983,     0,     0,  1233,     0,
    1178,  1177,  1172,  1170,  1169,  1173,  1171,  1175,  1176,  1168,
    1221,     0,  1457,  1463,  1633,  1626,  1468,  1330,  1573,  1585,
       0,  1587,  1589,     0,  1591,     0,     0,     0,  1597,  1576,
    1601,     0,  1458,  1460,     0,  1482,  1483,  1624,  1616,  1286,
       0,     0,  1278,  1273,  1274,  1291,     0,  1269,  1270,     0,
       0,  1283,  1263,  1264,     0,    24,  1258,     0,     0,  1016,
       0,    50,   996,     0,    24,   162,   152,     0,   651,   653,
     164,   154,   765,     0,  2226,  1025,     0,   355,  1378,     0,
    1067,    24,     0,     0,    66,     0,    79,    88,     0,    72,
     887,   884,   562,  2264,   955,     0,  2264,   694,   673,   679,
     641,  1775,     0,  1773,     0,     0,  1687,  1683,  1453,     0,
    1455,  1449,     0,  1361,     0,  1785,  1444,  1446,  1421,     0,
    2171,  2170,     0,     0,  1565,     0,  1565,  1565,  1565,  1565,
    2174,     0,     0,  2154,     0,     0,     0,     0,  2187,  2155,
       0,     0,     0,     0,     0,     0,  2149,  1375,  1427,   856,
     855,   339,     0,     0,     0,     0,  1675,  1798,  1801,  1799,
    1512,     0,  1549,  1551,     0,  1538,  1541,  1540,  1548,     0,
    1550,  1530,     0,  1501,  1391,  1813,   213,   988,   987,   985,
       0,  1214,  1099,  1103,  1105,     0,  1109,     0,  1107,  1111,
    1100,  1101,     0,   878,     0,     0,  1627,  1632,     0,     0,
    1608,  1600,  1578,     0,  1579,     0,     0,  1276,  1271,  1277,
    1275,  1268,  1267,  1266,  1261,  1265,   365,   362,     0,  1014,
       0,     0,     0,   995,   766,   140,   650,    24,  1005,  1024,
     566,  1064,    67,  1238,    84,     0,     0,    77,    88,    88,
    2264,   559,     0,     0,   697,   758,     0,  1772,  1715,  1708,
       0,  1363,     0,  1708,  2198,     0,     0,  2203,     0,     0,
       0,     0,     0,     0,     0,     0,  2166,  2189,  2190,  2188,
    2186,  2164,     0,  2160,  2162,  2151,  2152,  1428,     0,  1420,
       0,  1808,  1809,  1819,  1820,  1531,  1763,  1533,     0,  1536,
    1534,  1552,     0,   984,  2264,  2264,  1113,  2264,  1115,  2264,
    2264,  1102,  1234,  1222,     0,  1588,     0,  1598,     0,  1489,
     367,  1015,  2247,     0,     0,     0,     0,     0,     0,    55,
       0,    54,     0,    52,     0,     0,   141,  1071,    88,    93,
      88,    89,    83,    73,   885,     0,     0,   699,    24,  1774,
    1707,  1716,  1367,     0,  1364,  1366,  1688,  2199,     0,     0,
    2197,     0,     0,     0,     0,     0,  2175,  2196,     0,  1429,
       0,  1539,  1547,  1104,  1106,  2264,  1110,  2264,  1108,  1112,
    1628,  1593,  1461,   369,   374,   372,   363,     0,   370,   376,
      57,    62,    59,    61,    58,    60,    56,     0,    51,     0,
     652,   654,  1075,  1065,     0,  1073,  1239,    85,    80,   560,
     956,  2264,   759,     0,  1358,     0,  1689,  1703,  2195,  2204,
    2191,  2192,  2193,  2194,     0,  2176,     0,     0,     0,  1114,
    1116,  2264,  2264,   368,   371,  2264,    53,     0,  2264,  1072,
    1074,     0,   695,  1365,     0,  1693,  1690,  1691,     0,     0,
    2153,  1811,     0,   375,   373,   377,     0,  1076,    86,   700,
       0,     0,     0,  2178,     0,  2177,     0,   997,    90,     0,
    1694,  1692,     0,  1810,    92,     0,    87,     0,  2179,    91,
    1695
};

/* YYDEFGOTO[NTERM-NUM]. */
static const short yydefgoto[] =
{
      -1,   823,   824,   825,   826,  1043,  2400,  2401,   178,   320,
     179,  1403,  1404,  2227,  2559,  3611,  3082,  3083,  3511,  3612,
    3613,   827,  1184,  3120,  2816,  3529,  2166,  2814,  3377,  3124,
    3525,  2815,  3378,  3619,  3721,  3748,  3527,  3756,   645,   646,
     647,  1525,  2475,   828,  1536,  1189,  1534,  2174,  2485,  2171,
    2483,  2488,  2820,  1535,  2482,  2175,  2819,   829,     9,    28,
      29,    30,    31,    32,   831,  1106,  2106,  1427,  2425,  2429,
    2430,  2426,  2427,  3089,  3093,  2782,  2774,  2773,  2775,  2778,
     492,   268,   598,   832,    55,    56,    11,    41,   113,    70,
      71,    72,    73,   194,   334,    74,    75,   240,   339,   226,
    1006,   518,  2977,   370,   933,  2290,   398,   399,   227,   352,
     341,   347,  1348,  1349,   117,   536,   118,   119,   358,   228,
     354,   340,   342,   520,   229,   254,   574,   242,   245,   243,
     244,   380,   552,   553,   555,   560,   936,   246,   247,   389,
     557,   190,    12,    51,   149,   150,   151,   942,  2915,   152,
     250,   238,   392,   393,   394,   395,  2129,   833,   834,   835,
     836,  1064,  3600,  3345,  1405,  3666,  3667,  3668,  3712,  3711,
    3715,   837,   838,   839,   840,   841,   842,   843,  1054,   493,
    1059,  1397,  1398,  1443,  1159,  1444,   295,   296,   297,   298,
     299,   300,   301,   450,   494,  1331,   495,   496,   497,   498,
     499,   500,   501,   983,   180,   512,   993,   995,  2023,   181,
     506,   989,   505,   988,   508,   991,   507,   990,   951,   961,
     302,   303,   183,   304,   417,   418,   419,   420,   403,   422,
     844,  3383,  3625,  3136,   845,  1126,  2132,  3112,  2456,    87,
     235,   546,  1945,  1252,  1253,  1254,  1942,  1943,  2277,  2278,
    2279,  2616,  2617,  1946,  1947,  2273,  2620,  2612,  2285,  2286,
    2623,  2624,  2913,  2909,  2910,   846,  1455,    57,  2091,  2092,
    2450,   404,   424,  1098,  1164,  1035,  1086,  1069,  1108,  2515,
     184,  1036,  1026,  2064,  2777,    59,   305,   847,  1194,   848,
    1207,  1208,   849,   850,   851,   852,  1215,  3145,  1236,  3388,
    1237,  2201,  1238,  2512,  1239,  2834,  1240,  2230,   853,  2197,
    2833,  3144,  3386,  3385,  3691,    88,    13,   854,  1421,  2096,
    2097,  2098,  2220,  1890,  2221,  2222,  2846,  2848,  2530,  2529,
    2534,  2528,  2527,  2520,  2519,  2518,  2517,  2522,  2521,  2524,
    2526,   855,   856,  1104,   857,  1886,  1222,  3628,   858,  1503,
    3354,  2561,  2562,  2223,  2531,  2491,  2822,  1153,  1483,  2136,
    2459,  2137,  1479,   859,   860,  1200,  2189,  3140,   861,   862,
     863,   864,    14,    45,    15,    16,    17,    89,    90,   865,
      91,    18,   924,    19,    92,    93,   129,   548,  1951,  2628,
    3440,    94,   125,   363,   866,  2755,    20,    21,    22,    23,
      24,    40,    62,    95,   674,  2029,  2696,   867,  1195,  2495,
    2178,  2493,  3530,  3131,  2179,  2492,  2825,  3133,   868,   869,
     870,  1080,  1081,  1539,    96,   236,   547,   927,   928,  1256,
    1949,   871,  1241,  1242,   872,  1898,  1243,   306,    64,    65,
      66,    67,  1546,   155,   109,    68,   106,   186,   187,  1547,
    1548,  2502,  1549,   671,   672,  1224,   673,  1225,  1157,  1158,
    1550,  1551,  1401,  3284,  3285,  3469,  1096,  1097,   873,  1416,
    3513,   874,  3101,   875,  1431,  1432,  1433,  2112,  2110,   876,
     877,  2409,  2436,   878,  2123,  2446,   879,  1154,  1155,   880,
    1019,   881,  2572,   882,  3617,  3115,   883,  2463,  3683,  3684,
    3685,  3718,  1161,   884,  1552,  2191,  2506,  2507,   885,  2084,
    1034,  1390,   886,   887,   888,  2698,  3288,  3480,  3481,  3584,
    3585,  3589,  3587,  3590,  3655,  3657,   889,   890,  1541,  2183,
     891,  1543,  1514,  1515,  1516,  2156,   892,  1174,   893,   894,
    2149,  1511,  1170,   193,  1517,  1518,   307,  2699,  3018,  3019,
    3002,  1051,  1052,  2694,  3003,  3006,    97,   124,   540,  1358,
    2350,  3020,  3484,   432,   895,  1168,    98,   121,   537,  1355,
    2348,  3007,  3482,  2695,  1188,  2807,  3373,  3618,  2151,   896,
     897,   898,   899,   900,  1067,  2407,  1045,  2403,  3341,  3342,
    3343,  3497,  3332,  3333,  3334,   901,  2968,  2749,  2750,  2752,
    2048,   902,   903,  1367,  1368,  1369,  2057,  2389,  1370,  2386,
    2054,  1371,  2362,  2049,  1372,  1373,  1374,  2354,  2359,  1375,
    2043,  2044,   904,  1076,  1056,   905,  1923,  1924,  2245,  3172,
    3404,  2876,  3169,  3633,  3634,  1925,  2267,  1904,  2608,  2899,
    3218,  2798,  3111,  2609,  1926,  1927,  2333,  2970,  2971,  2972,
    3265,  1928,  1929,  1440,   906,  1113,   907,  1249,  1930,  1931,
    2261,  3569,  2262,  2263,  2264,  2592,  2880,  2883,  2884,  1932,
    2582,  2871,  3401,  2037,  2038,  3057,  2702,  3322,  2703,  2039,
    2707,  2050,  2734,  2051,  2735,  3058,  3059,  3060,  3061,  1933,
    2239,  2240,  2579,  1934,  2965,  2682,  2961,  2328,  2002,  2323,
    2324,  2325,  2934,  2003,  2329,  2683,  2966,  2672,  2673,  2674,
    2675,  2676,  3452,  3246,  3575,  2677,  3454,  3455,  2959,  2678,
    2960,  2679,  2312,  2382,  2383,  2384,  3316,  2385,  3036,  3043,
    3491,  2704,  1023,  2885,  3024,  3211,  2706,  2667,  1304,   308,
    1305,  1983,   443,   952,  1964,  1984,  2647,    39,   908,   909,
    3164,  3397,  2864,  3396,  3697,  3726,  3727,  2868,  2573,  1935,
    2574,  2597,  3179,   601,  2569,  2570,  2334,  2685,  3395,  3168,
    1306,   968,  1307,  1308,  2962,  2680,  1310,  1311,  2314,  3577,
     910,   911,  2232,  2571,  3160,  3392,  3393,  1901,   912,  1062,
    1937,  1938,  2249,  2878,  1939,  1940,  2588,  2016,  2307,  1312,
    1313,  1314,  1315,   913,  1203,  1875,  1876,  1877,  2193,  1878,
    2194,  1941,  2598,  3217,  3436,  2895,  3214,  3215,  3216,  3213,
    3201,  3202,  3203,  3204,  3205,  3206,  3548,   914,  2121,  2441,
    2442,  1114,  1316,  1317,  1116,  1117,  1118,  1318,  1119,  1438,
    2115,  2116,    25,   916,  1176,  2157,  1424,  1505,   917,   918,
    2766,   919,  2398,  1039,  2071,   920,   921,    35,   541,   542,
     543,   544,   545,   922
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -2813
static const short yypact[] =
{
     837,  1124, -2813,   361,   361,   882, -2813, -2813,   882, -2813,
      14, -2813, -2813, -2813,   452, -2813,   837, -2813, -2813, -2813,
   -2813, -2813,   -16, -2813, -2813, -2813, -2813, -2813,   462,   488,
   -2813,   460, -2813, -2813, -2813, -2813, -2813, -2813,  -129, -2813,
     587,   471, -2813, -2813, -2813,   204, -2813, -2813, -2813, -2813,
   -2813,  -102,   361, -2813,   361,   661,    14, -2813,   960, -2813,
   -2813, -2813, -2813, -2813, -2813,   459,   -69, -2813, -2813, -2813,
     965,   604,   361, -2813, -2813,  1036,   361, -2813, -2813,   361,
     361, -2813, -2813, -2813,   361,   361, -2813, -2813, -2813, -2813,
     204, -2813, -2813, -2813, -2813, -2813, -2813, -2813, -2813, -2813,
    5537, -2813,   -69, -2813,   959,  3374, -2813, -2813,   540, -2813,
   -2813,  1040,   471,   499, -2813, -2813, -2813, -2813, -2813, 10378,
   -2813,   361,   628,   954,   361,    14, -2813, -2813, -2813,   361,
   -2813, -2813,   768,   684,   998, -2813, -2813,   740, -2813,   748,
   -2813,   724, -2813, -2813,   762, -2813, -2813, -2813, -2813, -2813,
   -2813, -2813, -2813, -2813, -2813,   717, -2813, -2813, -2813,   790,
     799,   808,   811,   833,   842,   848,   888,   907,   940,  3374,
     946,  5273,   962,   977,  1018,  1023,  1027,  1049,  1838,  1289,
   -2813, -2813, -2813, -2813,   969, -2813,   183, -2813,  3374, -2813,
     143, -2813, -2813, -2813,   108, -2813, -2813, -2813,   478, -2813,
   -2813, -2813, -2813, -2813, -2813,   768,  1055,  1070,  1076, -2813,
     998, -2813, -2813,  1086, -2813,  1106, -2813,   854, -2813, -2813,
    1110, -2813, -2813, -2813, -2813, -2813, -2813, -2813, -2813, -2813,
    1113,  1487,   361,  1122, -2813,    14,    14,  1126,   361, -2813,
    -100,  1492, -2813,   935,  1146, -2813,   942,  1171,  1602,  1615,
     361,  1619,  1630, -2813,   957, -2813,    68,    68,    68,    68,
      68,  5273,  1385,  1255,    62,  5273,   643,  5273, -2813,  5273,
    5273,  5273, -2813, -2813, -2813,  1085,  1203,  1213,  5273,  1224,
    1215, -2813,  5273,  5273,  1216, -2813,  1227, -2813,   977,  1231,
    1234,  1235,  1238,  1688,  9176,   104, -2813, -2813, -2813, -2813,
   -2813, -2813, -2813, -2813, -2813, -2813,  1251, -2813, -2813, -2813,
   -2813, -2813, -2813,   321,   321, -2813, -2813, -2813, -2813, -2813,
    3374, -2813, -2813,   361,  3374,  1220,   312, -2813, -2813, -2813,
   -2813,  1695, -2813, -2813, -2813, -2813, -2813, -2813, -2813, -2813,
    1244, -2813,  1244,  -100,  1701,  1702,  1704, -2813, -2813, -2813,
    1706,  1708,   471,  1619,  1244,  1712,  1074, -2813,  1635, -2813,
    1306,  1271, -2813,  1339, -2813, -2813, -2813,  1091, -2813, -2813,
    1732,  1319, -2813,  1284, -2813, -2813, -2813, -2813, -2813, -2813,
   -2813,  1171,  1284, -2813, -2813, -2813, -2813, -2813, -2813,  1286,
     232,   386,   299, -2813,  5331, -2813, -2813, -2813,  1298,  1756,
     388, -2813,  1295,   398, -2813,  -143,  1334,  1348,   424,   432,
    8100,  1349,    87,  1322, -2813, -2813,    88,  1350, -2813, -2813,
   -2813, -2813,   437, -2813, -2813,  8311, -2813,  4187,  9403,  3481,
    3481,  5273, -2813,  1262,  5273,  9176,  1314, -2813, -2813, -2813,
   -2813, -2813, -2813, -2813,  1130,  1762,  8349,  9176,  1262,  1778,
     294,  5273,  5273,  5273,  5273, -2813,  5273,  5273,  5273,  5273,
    5273,  5273,  5273,  5273,  5273,  5273,  5273,  5273,  5273,  5273,
    5273,  5273,  5273, -2813, -2813, -2813, -2813, -2813, -2813, -2813,
   -2813, -2813, -2813,  5273,  5273, -2813, -2813,  1331,  5273, -2813,
    5273,  1332, -2813, -2813, -2813, -2813, -2813, -2813, -2813, -2813,
   -2813, -2813, -2813, -2813,   321,  5273,  5273,  5273,  5273,  1371,
    1808,  1838,  4040,  1338, -2813,  3374,  1315, -2813,  1152,  1792,
   -2813,  1159, -2813,  1801,  1389,  1390,   449,  1526,   454,   456,
     302,  1360, -2813,   457, -2813, -2813, -2813,   361, -2813, -2813,
     361,  1427, -2813,  7338,   499,  7641,  1809,   306,   361,  1821,
       9, -2813, -2813,  1146,  1816, -2813, -2813, -2813, -2813,  1825,
   -2813,  1841, -2813,  1842, -2813,   361, -2813,   361, -2813, -2813,
    1619,  1844, -2813, -2813, -2813,   361,    68, -2813,  3374,    65,
   -2813, -2813, -2813, -2813, -2813,  1224,  1845,  1224,  1846, -2813,
    1848,  1211,   990, -2813,    62, -2813, -2813, -2813,  1434,  9176,
     525,  1440,  8403,  1850,  1224,  1442, -2813,  1446,  1447, -2813,
    8567,  8617,  8659,  8870,  9365,  5309,  9403,  4637,  9436,  9616,
    9675,  9706,  9778,  9883,  5423,  3481,  3481,  5415,  5415,  4142,
    9176,  8923,  9097,  1262,  9176,  9135,  1262, -2813,  9176,  9176,
    9176,  9176, -2813,  1860, -2813, -2813,  1885, -2813,  9176, -2813,
     313,  3374, -2813,  1452,  1875,     9, -2813, -2813,  1870, -2813,
    1421,  1876, -2813,  1880, -2813, -2813, -2813,  1884, -2813, -2813,
    1247,  1474,  1913, -2813,   361,  1478, -2813, -2813, -2813,   321,
     321,   321,   361,  1077,   361,  1239,   275,   275,  1312,   361,
     361,   275,   275,   361, -2813,  1239, -2813, -2813,   361, -2813,
     343, -2813, -2813, -2813,   275, -2813, -2813, -2813, -2813,   361,
   -2813, -2813, -2813, -2813,   139,   139,  5273, -2813, -2813, -2813,
    1312,  1312, -2813, -2813,   275, -2813, -2813,   275, -2813, -2813,
     361, -2813, -2813,   275, -2813, -2813,   321,   275, -2813, -2813,
    5273,   275,   321,   361,   321,   275, -2813, -2813,   172,   275,
     275,   172,   275,   361,   172,   275, -2813,   275,   275,   275,
   -2813,  1239, -2813, -2813,   321,   275, -2813, -2813,   275,    66,
     361, -2813,  1312, -2813, -2813,   275,  1088, -2813, -2813,   321,
    1248, -2813,   275, -2813,  1368,   321,  5273,    68,    68,   275,
   -2813, -2813,  1077,   321,  1101, -2813,  5273, -2813,  1115,  5273,
     275,    92, -2813,  5273,   275,  1895,   321, -2813,   275,  5273,
   -2813,  5273,   139,   361,   275,   361,    68,   275,   361,    68,
   -2813,   361,   169, -2813, -2813, -2813, -2813, -2813, -2813, -2813,
   -2813, -2813, -2813, -2813, -2813, -2813, -2813, -2813, -2813, -2813,
   -2813, -2813, -2813, -2813, -2813, -2813, -2813, -2813, -2813, -2813,
   -2813, -2813, -2813, -2813, -2813, -2813, -2813, -2813, -2813, -2813,
   -2813, -2813, -2813, -2813, -2813, -2813, -2813, -2813, -2813, -2813,
   -2813, -2813,   215, -2813, -2813, -2813, -2813, -2813, -2813, -2813,
   -2813, -2813, -2813, -2813, -2813, -2813, -2813, -2813, -2813, -2813,
   -2813, -2813, -2813, -2813, -2813, -2813, -2813, -2813, -2813, -2813,
   -2813, -2813, -2813, -2813, -2813, -2813, -2813, -2813, -2813, -2813,
   -2813, -2813,   847, -2813, -2813, -2813, -2813, -2813, -2813, -2813,
   -2813, -2813, -2813, -2813,   885,   361, -2813,   594, -2813,  1481,
   -2813, -2813, -2813,  1572, -2813, -2813,  1484,  1493,  1497,  1504,
   -2813, -2813,  1263,  1941,  1506,  1509, -2813,   485, -2813,  1475,
   -2813, -2813,  1282,   229, -2813,  1517, -2813,  1933, -2813,  1324,
   -2813, -2813, -2813,  1294, -2813, -2813, -2813, -2813, 10147, -2813,
    1085,  1520, -2813,  1085, -2813,  1085,  1085,  1085,  1085,  1085,
    1944,  1949,  1955,  5273,  1536,  1960,  5273,  1542,  1552,  1553,
    1554,  1561,  1566,  1567,  4040,  4040, -2813,   348, -2813, -2813,
   -2813,  1648,  1569, -2813,  1571,  1573,  1343,  1576,   361, -2813,
     361,  1577, -2813, -2813, -2813, -2813, -2813, -2813, -2813, -2813,
     336,  1353,   391,  1394,  1543, -2813, -2813, -2813, -2813,  1361,
     564, -2813, -2813, -2813, -2813, -2813, -2813, -2813, -2813,  2020,
    1358, -2813, -2813,  1556, -2813,  1312, -2813,  1507,   225, -2813,
   -2813, -2813,  1435, -2813,  9176, -2813, -2813,  1392, -2813, -2813,
    4347, -2813, -2813, -2813,   321, -2813, -2813,  1312, -2813,    54,
   -2813, -2813,  1717, -2813,   127, -2813,  1529, -2813, -2813, -2813,
   -2813,  2032, -2813, -2813,   261, -2813,  1375, -2813,  1391,  2032,
   -2813,  1412, -2813, -2813, -2813,  1591,   118, -2813,  1555, -2813,
    1359, -2813, -2813, -2813, -2813,  1362,   209, -2813,  -220, -2813,
    1397,  1445,  1560,  1691,  1411, -2813, -2813,  1405, -2813, -2813,
    5273,   133,  1133,  5273, -2813,   134,   275, -2813, -2813, -2813,
   -2813, -2813, -2813, -2813, -2813, -2813,    57,    57,    57, -2813,
      57,  3009,    57,    57,  1431,    54,  1431,  1431,  1156,  1156,
    1431,  1431,    54, -2813,  2070, -2813,  1609,   254, -2813,  2076,
   -2813,    54,   110,    47, -2813, -2813,  5273, -2813, -2813, -2813,
     989, -2813, -2813,   499,  5273, -2813,  5273,  1604,  1606,  1608,
    1610,  1489,  1611,  1101, -2813,  1692,  1030,  1469, -2813,  1482,
   -2813, -2813,   361, -2813, -2813,  1161, -2813,  2098, -2813,  2094,
     361, -2813,   382,  6702,  1488, -2813, -2813,  2106, -2813,  1407,
    2106,  2109,  1415,  2106,  2109,  5273,  2106, -2813, -2813,   225,
     321, -2813, -2813,  1649,   384, -2813, -2813,  1638,   321,  5273,
    1643, -2813, -2813,  2102,  2112,  2010, -2813, -2813, -2813, -2813,
   -2813, -2813, -2813, -2813,  1166,  1166,   275,   275,   275,  3572,
   -2813, -2813,  2002,   885, -2813, -2813,   700, -2813, -2813, -2813,
    1645, -2813, -2813, -2813, -2813,  5537,  1619, -2813, -2813,  1476,
     361,  1236,  2118,  1224,  1224,  1518,  1535, -2813,  9783,  9783,
   -2813,  1397, -2813, -2813,  1674,  1675,  1254, -2813,  9658,  1677,
   -2813,  1678,  1679,  1680, -2813,  1680,  1680,  1682,  1684,  1685,
    1686,   361,    -4, -2813, -2813, -2813, -2813,   144, -2813,    63,
    1952, -2813, -2813,  1254, -2813,  1254,  1697, -2813, -2813, -2813,
   -2813, -2813, -2813, -2813, -2813, -2813, -2813, -2813, -2813, -2813,
    9176,   463, -2813, -2813,   467, -2813, -2813, -2813, -2813, -2813,
   -2813, -2813, -2813, -2813, -2813,  1661, -2813, -2813,   472, -2813,
   -2813, -2813, -2813, -2813, -2813,    14, -2813, -2813,    14,   956,
     182,  2147, -2813, -2813,   572,   241,   620,  2169, -2813, -2813,
   -2813, -2813, -2813, -2813, -2813, -2813,   361,  1540,   361, -2813,
   -2813,  1558,   361,  1574,   361,   361,  1312,  1533,  1698, -2813,
    1699,   173, -2813, -2813, -2813,  1312, -2813, -2813,  2173, -2813,
   -2813,  1511,  1703, -2813, -2813, -2813,  1133,  1174, -2813,  1174,
    1101,   172,  5273,  5273,  5273,  1710, -2813, -2813,   321,   321,
    1312,  1514,  1101,    68,  1471,    66,   321, -2813,  1521,  5273,
    1788, -2813, -2813,  1590,   361,  1397, -2813,  3374, -2813, -2813,
   -2813,   361,  1100,  2189, -2813, -2813,  1532,    93,   225,   321,
   -2813, -2813,  2178,  2179, -2813, -2813, -2813, -2813, -2813, -2813,
   -2813, -2813, -2813, -2813, -2813, -2813, -2813, -2813, -2813, -2813,
   -2813, -2813, -2813, -2813, -2813, -2813, -2813, -2813, -2813, -2813,
   -2813, -2813,  2443, -2813, -2813, -2813, -2813, -2813, -2813, -2813,
   -2813, -2813,  1368,   321,   321, -2813,  1156,  5273,   -76,  2171,
    2174, -2813, -2813, -2813, -2813, -2813,   210, -2813, -2813, -2813,
   -2813,  1997, -2813,  1768,   499,  5273, -2813,   107, -2813, -2813,
     361,  2180,    68,    68, -2813,  1568, -2813,    62,  1534,   321,
   -2813,   361,   361,  5273,   -81, -2813,  1581, -2813, -2813,   291,
   -2813,  1681, -2813,  1683,  5273,  1128, -2813, -2813,  1545, -2813,
    2208, -2813,  1621, -2813,   321, -2813, -2813, -2813, -2813, -2813,
   -2813, -2813, -2813, -2813, -2813, -2813, -2813, -2813, -2813, -2813,
   -2813, -2813, -2813, -2813, -2813, -2813, -2813, -2813, -2813, -2813,
   -2813, -2813, -2813, -2813, -2813, -2813, -2813, -2813, -2813, -2813,
   -2813, -2813, -2813, -2813, -2813, -2813, -2813, -2813, -2813, -2813,
   -2813, -2813, -2813, -2813, -2813, -2813, -2813, -2813, -2813, -2813,
   -2813, -2813, -2813, -2813, -2813, -2813, -2813, -2813, -2813, -2813,
   -2813, -2813, -2813, -2813, -2813, -2813, -2813, -2813, -2813, -2813,
   -2813, -2813, -2813, -2813, -2813, -2813, -2813, -2813, -2813, -2813,
   -2813, -2813, -2813, -2813, -2813, -2813, -2813, -2813, -2813, -2813,
   -2813, -2813, -2813, -2813, -2813, -2813, -2813, -2813, -2813, -2813,
   -2813, -2813, -2813, -2813, -2813, -2813, -2813, -2813, -2813, -2813,
   -2813, -2813, -2813, -2813, -2813, -2813, -2813, -2813, -2813, -2813,
   -2813, -2813, -2813, -2813, -2813, -2813, -2813, -2813, -2813, -2813,
   -2813, -2813, -2813, -2813, -2813, -2813, -2813, -2813, -2813, -2813,
   -2813, -2813, -2813, -2813, -2813, -2813, -2813, -2813, -2813, -2813,
   -2813, -2813, -2813, -2813, -2813, -2813, -2813, -2813, -2813, -2813,
   -2813, -2813, -2813, -2813, -2813, -2813, -2813, -2813, -2813, -2813,
   -2813, -2813, -2813, -2813, -2813, -2813, -2813, -2813, -2813, -2813,
   -2813, -2813, -2813, -2813, -2813, -2813, -2813, -2813, -2813, -2813,
   -2813, -2813, -2813, -2813, -2813, -2813, -2813, -2813, -2813, -2813,
   -2813, -2813, -2813, -2813, -2813, -2813, -2813, -2813, -2813, -2813,
   -2813, -2813, -2813, -2813, -2813, -2813, -2813, -2813, -2813, -2813,
   -2813, -2813, -2813, -2813, -2813, -2813, -2813, -2813, -2813, -2813,
   -2813, -2813, -2813, -2813, -2813, -2813, -2813, -2813, -2813, -2813,
   -2813, -2813, -2813, -2813, -2813, -2813, -2813, -2813, -2813, -2813,
   -2813, -2813, -2813, -2813, -2813, -2813, -2813, -2813, -2813, -2813,
   -2813, -2813, -2813, -2813, -2813, -2813, -2813, -2813, -2813, -2813,
   -2813, -2813, -2813, -2813, -2813, -2813, -2813, -2813, -2813, -2813,
   -2813, -2813, -2813, -2813, -2813, -2813, -2813, -2813, -2813, -2813,
   -2813, -2813, -2813, -2813, -2813, -2813, -2813, -2813, -2813, -2813,
   -2813, -2813, -2813, -2813, -2813, -2813, -2813, -2813, -2813, -2813,
   -2813, -2813, -2813, -2813, -2813,  5991, -2813, -2813, -2813, -2813,
     361,    68,    68,   438,   384,  2015,  1613,   321,   225, -2813,
    1624, -2813, -2813,  2189,  2192,  1771, -2813, -2813, -2813, -2813,
   -2813,  1849,  1849, -2813,   405,  1627, -2813,   361,  1312, -2813,
    1312,  1312, -2813, -2813,  1312,  1312, -2813,   361,  1035,   525,
    1312, -2813,  1035, -2813, -2813, -2813, -2813, -2813, -2813, -2813,
   -2813, -2813, -2813, -2813, -2813, -2813, -2813, -2813, -2813, -2813,
   -2813, -2813,   161,   161,   858,   949, -2813,   771, -2813,   700,
   -2813,    14,  2196, -2813, -2813,  1121,  1783,  1747, -2813, -2813,
   -2813, -2813, -2813, -2813, -2813,  1785, -2813, -2813,  1579, -2813,
   -2813, -2813,  1786,  1786,  1636,  1640, -2813, -2813, -2813, -2813,
   -2813, -2813, -2813, -2813,  1559,   525,  1791, 10197,   555, 10147,
    1709, -2813, -2813, -2813,   555,   555,   555,   555,  1570, 10147,
   10147,   235,  1666,   -30,   361, -2813, 10147, 10147, 10147, 10147,
   -2813, -2813, -2813, -2813, -2813, -2813, -2813,  1575,  -154,  1133,
    5273, -2813, -2813,  1799,  2196, -2813, -2813, -2813, -2813,    14,
   -2813,  1763,  1765,  1770,   773,  1777,  1780, -2813, -2813, -2813,
    2143,   361, -2813,  2255, -2813, -2813,   624,  2497, -2813, -2813,
   -2813, -2813,   361, -2813, -2813,   624,  1578, -2813,   336, -2813,
    1598, -2813,  1629, -2813,  1822,   -69, -2813,  1614, -2813,  1634,
   -2813,  1689,  1805,   361, -2813, -2813, -2813, -2813,  4347,   361,
   -2813,  1616, -2813, -2813, -2813, -2813,  1612, -2813,  2281,  2282,
   -2813,  2284,  1667,  5273, -2813, -2813,  2289, -2813,  1631, -2813,
    1766,  1623,  2109, -2813, -2813,  1637,   910,   361, -2813, -2813,
    1827,   275,   973,  1405,  1838,   366, -2813, -2813, -2813, -2813,
    5273,  1312,  1133,  -208, -2813,   361,   361,  5273,    33,    54,
    2301,  1240,  2299,  2285,  2292,  3009, -2813, -2813, -2813, -2813,
   -2813, -2813, -2813,   321,  1953, -2813, -2813,  2206,  5273,   499,
    2058, -2813, -2813, -2813,  5273,   139, -2813,  1950,  2326,  2333,
     475,   482,   361,  1899,  1101, -2813,  4040,  1864,  1867, -2813,
   -2813,  1934, -2813,  5273,   276, -2813,  1713, -2813, -2813,   616,
   -2813,  5273, -2813, -2813,  1687,   959, -2813,  1270,   361,  2332,
    9965, -2813, -2813,  1133,   321, -2813, -2813,    48, -2813,  2109,
    2109,  1641, -2813,  1755,  1764, -2813, -2813, -2813, -2813, -2813,
   -2813,    68,    68, -2813, -2813, -2813, -2813, -2813, -2813, -2813,
   -2813,  2678, -2813, -2813, -2813, -2813,    68,  5716,  2355,  2335,
   -2813,  1101,   905,   242,   126,  2214,    10,  1077, -2813,   544,
   -2813, -2813, -2813,  1886,    75,  1312,   193,  1700, -2813,  1693,
   -2813, -2813, -2813, -2813, -2813,  1889,  1889, -2813, -2813, -2813,
   -2813,  1775,  1705,  2358, -2813, -2813, -2813,   492,  1711,  1707,
   -2813, -2813,   321,   208, -2813, -2813, -2813,  1690,   949, -2813,
     361,   361, -2813, -2813,   361,   678, -2813, -2813, -2813, -2813,
    1897, -2813, -2813, -2813,  2343,  1224, -2813, -2813,  1931,    89,
    1932,   160,  1264, 10147, -2813,   316,  2369,  1936,  2375, -2813,
   -2813, -2813, 10147, -2813,   484, 10147, 10147, 10147, 10147,   361,
     487, -2813,   206,  2376, -2813, -2813,   361,  9471, -2813,  1964,
     361,  1719,   555,  2003, -2813, -2813, -2813, -2813, -2813, -2813,
    1264,  2360,  1264, -2813,  9176, -2813,  1914, -2813,  1883, -2813,
    1887,   148,   148,   148,   489,  2143,   148,  9471,   361, -2813,
     509,   361,   510, -2813, -2813, -2813,  1916,  1919,  1921,  1254,
    1254, -2813,  1923, -2813,  1924,  1925,  1928,  1930, -2813, -2813,
   -2813, -2813,   982, -2813, -2813, -2813,   516, -2813, -2813,   522,
     361, -2813,   361,  1583, -2813,   361,  1588,  5273, -2813,   361,
    2404, -2813, -2813,   624, -2813, -2813,  1744,   624,   157, -2813,
    1101,  5273,  5273,  5273,  4710,  2406,  1312,    77, -2813,  1101,
     361, -2813, -2813,   361,   361, -2813,   747, -2813, -2813,   409,
   -2813,  1746,  5273, -2813, -2813, -2813,  2407,  3374,  1912, -2813,
    1753,  2417, -2813, -2813,  1101,  1802, -2813, -2813, -2813, -2813,
   -2813,   361,  2109, -2813,   225, -2813,  1824, -2813, -2813,   527,
   -2813, -2813, -2813,   321, -2813,  5615, -2813,  1032, -2813, -2813,
    2054,  2408, -2813,  2037,  2039,  1929,  1772,  2041,  1959, -2813,
   -2813, -2813,   529,  2029, -2813, -2813, -2813, -2813,  1934, -2813,
   -2813, -2813,   217,   623, -2813, -2813, -2813,  2189,  5273,  1967,
   -2813,  1938, -2813, -2813, -2813, -2813,  2437, -2813, -2813, -2813,
    2440, -2813,  1749, -2813,  2421,    54,   361,  3165,  3165,  3165,
    3165,  3165,  3165, -2813,  2444, -2813,  2445,  3165,  3165,  3165,
    3165,  2443, -2813, -2813,  3165,   223, -2813, -2813, -2813, -2813,
    2427,  2439, -2813, -2813, -2813, -2813, -2813, -2813, -2813, -2813,
   -2813,  2442, -2813, -2813, -2813, -2813, -2813, -2813, -2813,   530,
   -2813, -2813, -2813,  2428, -2813, -2813,  1312, -2813,   525, -2813,
   -2813, -2813, -2813, -2813, -2813,  1817,  1819,   154, -2813,   544,
   -2813,   148,  1800,   275, -2813,  1984, -2813, -2813, -2813,   361,
     361,   148, -2813, -2813,   119,  1312,  1221, 10147,   181, -2813,
    5273, -2813,  5273, -2813, -2813, -2813, -2813, -2813,  1869,   275,
     119,  1312,  2461, -2813,   321,   361,   788,   788, -2813, -2813,
    2462, -2813,  2462,   699,   699,  2462, -2813, -2813,  1809, -2813,
    2030, -2813, -2813,  2446, -2813,  2447, -2813,  2448, -2813,  2449,
    1992, -2813, -2813, -2813, -2813, -2813, -2813, -2813,   144,  1254,
    1804,  1254, -2813,  1254,  2036, 10147, -2813,  2038,  2040,  2042,
    2045, -2813, -2813,   235, -2813,   235, -2813, -2813,  4226,  1680,
    2226,  1680,  2472,  2473, -2813, -2813, -2813, -2813, -2813, -2813,
     277, 10147, -2813,  1987, -2813,  2170,   198,   242,   361, -2813,
    2047, -2813, -2813,   899,    72, -2813,  1809,  1715, -2813,    72,
    1312,   659,  2050,  2494,  1834, -2813, -2813,   535, -2813,   538,
     773, -2813, -2813,   541,   274, -2813, -2813, -2813,   624, -2813,
    2476,  2476,  2477,  1832,   427,  2479,  2480,  2481,  2479,  2479,
   -2813, -2813, -2813,   196, -2813,   805,   361, -2813,   624, -2813,
   -2813, -2813,  1843, -2813, -2813,  1851, -2813, -2813,  -187,   550,
   -2813,   361,   551, -2813,  5273,  2067,  2490,   553,  1101,  2506,
   -2813, -2813, -2813, -2813,  5273,  1901,  2195,  5273, -2813, -2813,
   -2813, -2813,   409,  1267,  1267,  2507,   503, -2813,  2510, -2813,
   -2813, -2813,  1267,   361,  1927,  1283,  2516,   361, -2813,  3374,
     165,  1312,  2514,  1101,   -64,  2301,  5273, -2813, -2813,  3009,
   -2813,  1810,  5273, -2813, -2813, -2813,  2518,  4040,   321, -2813,
     343,   361,   321, -2813,  2085,  4040,  4040, -2813, -2813,   529,
    2029, -2813,  2443, -2813, -2813,  1209, -2813, -2813,  1909, -2813,
    3374,  4943,  9965,   116,  1008, -2813, -2813, -2813,  1862, -2813,
   -2813, -2813, -2813, -2813, -2813,    68,  3165,    68,  3165, -2813,
   -2813, -2813, -2813, -2813, -2813,    54, -2813,  1063,  1182,  5716,
   -2813,  2088,  2053, 10147, -2813,   126,   126, -2813, -2813, -2813,
   -2813,   554, -2813,  2014, -2813,   148,   376, -2813,  1861, -2813,
     558, -2813, -2813,  2529, -2813, -2813,  1942, -2813,  2531,  6983,
    6983,  6983,  6983,   148,   148, -2813, -2813, -2813, -2813, -2813,
   -2813,  2529,  1865,   321, -2813,  2462, -2813, -2813,   361,   699,
     699, -2813, -2813,   699,  2279,  1871, -2813,   247,   -11,   414,
     502,  2517,  2099,  1872,  1264,  1873,  1877, -2813, -2813, -2813,
   -2813, -2813, -2813, -2813,   560, -2813, -2813, -2813,   412,   410,
   -2813,  9471,  9471, -2813, -2813, -2813, -2813, -2813, -2813, -2813,
   -2813, -2813,  9783,  9783,  2064,  9783,  2069, -2813,  9783,   639,
   10147,  2543, -2813, -2813,  9471, -2813, -2813, -2813, -2813, -2813,
    2545, -2813,   -46, -2813, -2813,  2170,  1879,  1882, -2813, -2813,
     139,   139,   139,  2528,   139,   139,   139,   139,   139,   139,
    2530, -2813,  2532,   139, -2813, -2813, -2813, -2813, -2813, -2813,
   -2813, -2813,   899, -2813,   321,  1891, -2813,  2060,  2279,  2533,
   -2813,  2534,  2535,  2536,  2538,  2539,  2540,  1228,  1715, -2813,
    2060, -2813, -2813,  2541, -2813,  2215,   148,  1287,   148, -2813,
   -2813,  2143, -2813, -2813, -2813, -2813,  2127,  2130,   570,  1264,
    2546,  1264, -2813,  2570,   574,  2135,  2136,  2570, -2813, -2813,
   -2813, -2813,  1312, -2813, -2813, -2813,  2103, -2813, -2813,   805,
   -2813,  2143, -2813, -2813,   361,   361, -2813, -2813,   361,  -319,
   -2813,   624,   231,  2189, -2813,  2065,   231,   298,  1101, -2813,
    2584,  2117, -2813, -2813,  2149,  1999, -2813, -2813,   361,  1267,
    3374,  1304,   361,  1267, -2813, -2813,    68, -2813, -2813,  5273,
   -2813, -2813,   369, -2813, -2813, -2813,  1101,  2589, -2813,    68,
    2189,   321,  2310, -2813,  2575,  1755,  9176,  2577, -2813, -2813,
     225,  2129, -2813, -2813,  4040, -2813, -2813,  2163, -2813, -2813,
   -2813,   623, -2813,  1755, -2813,  5273, -2813,   378, -2813,  2076,
   -2813, -2813, -2813, -2813,  2122,  2210, -2813,  2586, -2813, -2813,
   -2813, -2813, -2813, -2813, -2813, -2813, -2813, -2813, -2813,   361,
   -2813,   120, -2813, -2813, -2813,   148, -2813,   525,  2422,   576,
   -2813, -2813, -2813, -2813,   361,   148, -2813,   119,   119,  2016,
    4613,  4613, -2813, -2813,  1425,  2137, -2813, -2813,  2139,  2140,
   -2813,  2141,  2142,  2148,  2151,   361,   559, -2813, -2813, -2813,
   -2813,   578, -2813, -2813,  2005, -2813, -2813, -2813,   590,  2609,
    2609, -2813, -2813,   591,  2616,  2613, -2813,    86,   321,   119,
   -2813, -2813, -2813, -2813, -2813,  2370,  5537,  2605, -2813, -2813,
    2608,  2610, -2813, -2813,  2611,  2194, -2813,  1264,  2197,  1264,
    1264,   235, -2813, -2813,  2473, -2813,  2150,  1952,  2150,   192,
   -2813,  2150,   192, -2813,  2150,  9783, -2813, -2813, 10147, -2813,
   10147,  2472,   198, -2813, -2813, -2813, -2813,  1264, -2813, -2813,
   -2813, -2813, -2813, -2813, -2813, -2813, -2813, -2813, -2813, -2813,
   -2813, -2813, -2813,   355,  2636, -2813,   321,  1486, -2813,  2370,
   -2813, -2813, -2813, -2813, -2813, -2813, -2813, -2813, -2813, -2813,
   -2813,   380, -2813, -2813, -2813,  2138, -2813, -2813, -2813, -2813,
    2617, -2813, -2813,  2201, -2813,  2620,  2207,  2621, -2813, -2813,
   -2813,  2209, -2813,  2175,  9471, -2813, -2813, -2813, -2813, -2813,
     361,  2623, -2813,  -319, -2813, -2813,  2625, -2813, -2813,  2628,
     361,  2170,   231, -2813,    68,    54, -2813,  2231,  1101, -2813,
    5273, -2813,  2044,  2630,    54, -2813, -2813,   549, -2813, -2813,
   -2813, -2813,   227,  2216, -2813, -2813,  1101,  2109,  2440,  2374,
   -2813,    54,  2225,  2227,  2301,  2193, -2813,  2277,  2232, -2813,
   -2813, -2813, -2813,  2384,  2176,  5273,  2187, -2813, -2813, -2813,
    1755, -2813,   593, -2813,   321,  2084, -2813, -2813, -2813, 10147,
   -2813, -2813,   148, -2813,  2202, -2813, -2813, -2813,  2529,  2084,
    1958,  1958,  2238, 10197,   555, 10225,   555,   555,   555,   555,
     565, 10225,  6983, -2813, 10225, 10225, 10225, 10225, -2813, -2813,
     148,  2674,   148,  6983,   275,  9471, -2813,  2440,   105, -2813,
   -2813, -2813,   272,  2250,  2251,  2252, -2813, -2813, -2813, -2813,
   -2813,   196, -2813, -2813,   595, -2813, -2813, -2813, -2813,   597,
   -2813,  2150,  2687, -2813, -2813, -2813, -2813, -2813, -2813, -2813,
     321,  2636, -2813, -2813, -2813,   321, -2813,   321, -2813, -2813,
    1866, -2813,  2410, -2813,  2411,  2670, -2813, -2813,  2259,  2031,
   -2813, -2813, -2813,  2261, -2813,   148,   422, -2813, -2813, -2813,
   -2813, -2813, -2813, -2813, -2813, -2813, -2813, -2813,  1101, -2813,
    2263, 10596,  2228, -2813, -2813, -2813,  2043,    54, -2813, -2813,
   -2813, -2813, -2813, -2813, -2813,  2266,   225, -2813,  2277,  2277,
     623, -2813,  3374,  2086, -2813, -2813,   361, -2813,  2440,   -30,
     144, -2813, 10044,   -30, -2813,  2269, 10225, -2813,   602, 10225,
   10225, 10225, 10225,  2685,   361,   603, -2813, -2813, -2813, -2813,
   -2813, -2813,  2234, -2813, -2813, -2813,  2472, -2813,   361, -2813,
    2078, -2813, -2813, -2813, -2813, -2813, -2813, -2813,   178, -2813,
   -2813, -2813, 10147, -2813,  1538,  1538, -2813,  1538, -2813,  1538,
    1538, -2813, -2813, -2813,  2247, -2813,  1264, -2813,   606, -2813,
    1148, -2813, -2813,    57,    57,    57,    57,    57,    57, -2813,
    2698, -2813,   611, -2813,  5273,  1325, -2813,    43,  2277,  4040,
    2277,  2301, -2813, -2813, -2813,  2438,   385, -2813,    54, -2813,
   -2813, -2813, -2813,   621, -2813, -2813,  1341, -2813,  2286, 10225,
   -2813,  2288,  2290,  2291,  2293,   387,  2224, -2813,  6983, -2813,
    2711, -2813, -2813, -2813, -2813,  1538, -2813,  1538, -2813, -2813,
   -2813, -2813, -2813, -2813, -2813, -2813, -2813,  1154, -2813, -2813,
   -2813, -2813, -2813, -2813, -2813, -2813, -2813, 10596, -2813,  2733,
   -2813, -2813, -2813, -2813,   654, -2813, -2813, -2813, -2813, -2813,
   -2813,    48, -2813, 10044, -2813,  1597, -2813, -2813, -2813, -2813,
   -2813, -2813, -2813, -2813,  2713, -2813,  2714,   622,   531, -2813,
   -2813,  1219,  1219, -2813, -2813,  1219, -2813,  5273,   841, -2813,
   -2813,  2300,   116, -2813,  2077,  2079,  2737, -2813,  2272,   396,
   -2813, -2813,  2721, -2813, -2813, -2813,  2308, -2813, -2813, -2813,
     361,   361,  1597, -2813,  2724, -2813,  2311, -2813,   100,  2090,
   -2813, -2813,  2280, -2813, -2813,   225, -2813,   361, -2813,  2301,
   -2813
};

/* YYPGOTO[NTERM-NUM].  */
static const short yypgoto[] =
{
   -2813, -2813, -2813, -2813, -2813,   -52, -2813,     8,  -165, -2813,
   -2813, -1138,  -517, -2813, -2813, -2107, -2813, -2813, -2813, -2813,
    -917, -2813, -2813, -2813, -2813, -2813, -2813, -2813, -2813, -2813,
   -2813, -2813, -2813, -2813, -2813, -2813, -2282, -2813,  -987, -2813,
    1767, -2813, -2813, -2813, -2813, -2813, -2813, -2813,   278, -2813,
   -2813, -2813, -2813,  1229, -2813,   599, -2813, -2813,   -35, -2813,
   -2813,  2735, -2813,  2734, -2813, -2813, -2813, -2813, -2813,   347,
     -15, -2813,   345, -2813, -2813, -2813, -2813, -2813, -2813, -2813,
   -2813, -2813, -2813, -2813,   -85,   988,   305, -2813, -2813,  2423,
     -25, -2813,  2662, -2813, -2813,  2665, -2813,  2578, -2813, -2813,
   -2813, -2813, -2813,  2450,  2131,   761,  2436,  -523, -2813, -2813,
   -2813, -2813, -2813,   766,  -640, -2813, -2813, -2813, -2813, -2813,
   -2813, -2813, -2813,    55, -2813,  2569,  2260,  2585,    60,  2204,
   -2813,  2245,  1522, -2813,  2429, -2813, -2813, -2813, -2813,  2431,
   -2813, -2813, -2813, -2813,  -391, -2813, -2813, -2813, -2813, -2813,
   -2813, -2813, -2813,  2248, -2813,  2249, -2813, -2813, -2813, -2813,
   -2813, -2813, -2813, -2813, -1337, -2813, -2813,  -853, -2813, -2813,
   -2813, -2813, -2813, -2813, -2813, -2813, -2813, -2813,  -126, -2813,
   -2813,   737, -2813, -1067, -1157,   365, -2813, -2813, -2813, -2813,
   -2813, -2813, -2813, -2813, -2813,  1831, -2813, -2813, -2813, -2813,
   -2813, -2813, -2813,  -607, -2813, -2813, -2813, -2813, -2813,  2021,
   -2813, -2813, -2813, -2813, -2813, -2813, -2813, -2813,  -580, -2813,
     -94, -2813, -2813, -2813, -2813,  2405, -2813, -2813,  -239, -2813,
   -2813, -2813, -2813, -2813, -2813, -2813, -2813, -2813, -2813, -2813,
   -2813, -2813, -2813, -2813, -2813,  1580, -2813, -2813, -2813, -2813,
     542, -2813, -2813, -2813, -2813, -2813, -2011, -2813, -2813,   536,
   -2813, -2813, -2813, -2813, -2813, -2813, -1110,  -866,   413,   696,
   -2813,  -222,  -553,   415, -1112,   609, -2813,   726, -2813, -2424,
      -3,  -628, -2813, -2813, -2350,   237,   983, -2813, -2813, -2813,
     581,   945, -2813, -2813, -2813, -2813, -2813, -2813,    -7, -2813,
    -317, -2813,   947, -2813,   630, -2813,   320, -2813, -2813, -2813,
   -2813,  -888, -2813, -2813, -2813, -2813, -2813, -2813, -2813, -2813,
     420, -2813, -2813, -1814, -2813,   617, -2813, -2813, -2813, -2813,
   -2813, -2813, -2813, -2813, -2813, -2813, -2813, -2813, -2813, -2813,
   -2813, -2813, -2813,  1414, -2813, -2813, -2813, -2813, -2813, -2813,
    -525, -2813, -2813, -2075, -2813, -2813, -2813, -2813,   286, -2236,
   -2813, -1117, -2813, -2813, -2813, -2813, -2813, -2813, -2813, -2813,
   -2813, -2813, -2813, -2813, -2813, -2813,  2824, -2813, -2813, -2813,
    2751,  2806, -2218, -2813, -2813, -2813, -2813, -2813, -2813, -2813,
    -442, -2813, -2813, -2813, -2813, -2813,  2808, -2813, -2813,  2828,
   -2813, -2813, -2813, -2813, -2813, -2813, -2813, -2813, -2813, -2813,
     672, -2813, -2813, -2813, -2813, -2813, -2813, -2813, -2813, -2813,
   -2813,  -648,  2108, -2813, -2813, -2813, -2813, -2813,  1926, -2813,
   -2813, -2813, -2813, -2813, -2813, -2813, -2813,  2582, -2813, -2813,
     -28, -2813, -2813,   667, -2813, -2813,  1311,  -166,  2544, -2813,
   -2813, -2813, -2813,   712, -2813, -1042,  1859,   987, -1432,  1382,
   -2813,   689,  1658,  -407,  -590, -2813,  2104,  1463, -2813, -2813,
   -2813, -2813, -2813, -2813, -2813, -2813, -2813, -2813, -2813, -2813,
   -2813, -2813, -2813, -2813, -2813, -2813, -2813, -2813,  1393, -2813,
    -774, -2813,  -543, -2813, -2813, -2813, -2813, -2813, -2813, -2813,
    -791, -2813, -2813, -2813, -2813, -2813, -2813,    67, -2813,  1485,
     260, -2813, -2813, -2813, -2813, -2813,  -123, -2813,  -582, -2813,
   -2813, -2813, -2813, -2813, -2813, -2813, -2813, -2813, -2813, -2813,
   -2813, -2813, -2813, -2813,  1386, -2813, -2813, -2813, -2813, -2813,
   -2813, -2813, -2813,  -531, -2813,   749,  2457, -2813, -2813,  -110,
   -2813,  -652, -2813, -2813,   -89,   216, -2813, -2813, -2813, -2813,
   -2813, -2813, -2813,  1157, -2813, -2813, -2813, -2813, -2813, -2813,
   -2813, -2813, -2813, -2813, -2813, -2813, -2813, -2813, -2813, -2813,
   -2813, -2813, -2813, -2813, -2813, -2813, -2813, -2813,  -162, -2813,
    -425,  -422, -2813, -2813,  -414, -2813, -2674, -2813,  -148,   517,
   -1347, -2813, -2813, -2813,   865, -2813, -1994, -2813, -2813, -2813,
   -1980, -2813, -2813, -1989, -2813, -2813, -2813, -2813, -2267, -2813,
     887,   569, -2813, -2813, -2813, -2813, -2813,   349, -2813, -2813,
   -2813, -2813, -2813, -2813,  -762, -2813, -2813, -2813, -2813, -2813,
   -2813, -2813, -2813, -2813, -2813, -2813, -2813, -2813,  -329, -2813,
   -2813, -2813, -2813, -2813, -2813, -2813, -2813, -2813, -2813, -2813,
    1012, -2813,  1013, -2813,   340,   685, -2813, -2419,  -235, -2813,
   -2813, -2813, -2813, -2813, -2813,   -80, -2813, -2813,  -551, -2813,
    -955, -1334, -2813, -2813, -2813, -2813, -2813,  -113, -2813, -2813,
   -2813, -2813, -2813, -1955, -2813, -2813, -2813, -2813, -2813, -2813,
   -2420,   629, -2813, -2602,   703, -2813, -2813, -2314,    13,    16,
     288, -2813, -1992, -2368, -2813, -2813,  -293,  -618, -2813, -2813,
   -2813, -2813, -1930, -2813, -2813, -2813,   -84, -2813,   243, -1045,
   -2813,   -65,  -261,  1059,  -343, -2145,   269, -2813,    20, -2813,
   -2813, -2813, -2813,     2, -2813, -1149, -2292,  2963, -2813, -2813,
   -2813, -2813, -2813, -2813, -2813, -2813,  -769, -2813, -1695, -2813,
    1725, -2813, -2813,   625,   289, -2813, -2488,   290,  -202,   103,
     334, -1885, -2250,   980,  -279,   267, -1263, -2813,   985, -2813,
   -2813, -2813,  1083,  -708, -2813, -2813,  -550,  1743, -2813,   875,
   -2813, -2813,   403,  -180, -2813, -2813, -2813, -2301,  -418, -2339,
   -2813, -1380, -2813, -2813, -2813, -2813,  1129, -2813, -2813, -2813,
   -2813, -2813, -2813, -2813, -2813, -2813, -2813, -2628,  -433, -2813,
   -2812, -2315, -2092, -1495, -2813, -2813,  -415, -2813, -2813, -2813,
     218, -1083,   992,  -738,  1896,  1584,  1585, -1123, -2813, -2813,
     219,   575,   156, -2813, -2813, -2813, -2813,  1589, -2813, -2813,
   -2813, -2813, -2813, -2813, -2813, -2813, -2813,  -292,  1516,  2474,
   -2813, -2813, -2813, -2813
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -2261
static const short yytable[] =
{
      34,    36,    38,   568,   266,    38,  1391,   954,  1343,  1506,
      86,   182,   998,   678,  1450,  1972,  1973,  2131,  1167,  2056,
     408,   409,   326,  1498,  1478,  2040,   102,  1457,  1458,   986,
    1459,  2428,  1480,  1481,  2265,   406,   407,    58,  1115,  1446,
     234,   962,   423,  2714,   111,   294,  2922,   943,  2689,   101,
    2691,    58,   576,  2648,  2076,    86,  1447,  2363,  1025,  1028,
      33,  2388,   108,  1053,  2315,  2316,  2317,  2318,  2824,   115,
    2203,  2204,  2387,   120,  2779,   182,   122,   123,  3208,  3209,
    3210,   126,   127,  1451,    33,   948,  1173,   421,  2712,    33,
      33,   195,    33,    33,   182,    33,  1061,  2769,  2120,  1061,
    2303,    58,  1029,  1085,    33,  1048,   586,   590,  2633,  1070,
    3177,  2855,  2154,  1061,   591,   576,  1060,  1061,   230,    33,
    2560,   233,   253,  1419,  1087,  2000,   237,   331,   272,  1061,
     502,  1070,   272,   332,   333,   410,  1906,  1099,  1419,   425,
    1070,   427,  1448,   428,   429,   430,    33,  1109,  1883,  2000,
     364,   365,   435,    33,  1124,   511,   446,   447,  2576, -2259,
    1205,  1165,  1893,   272,  2017,  1049,  2018,   272,   327,   328,
      33,  1120,  1099,  1029,  1123,    33,  1099,  1884,  1888,  2637,
    1099,    33,  1171,  1166,    33,  3103,  1070,   329,   324,  1070,
    1029,  2901,    33,   272,  1217,  1218,    33,  1078,   253,    33,
     357,    99,   272,  1281,  1282,    33,  2705,  2708,  2708,    33,
    2124,  2708,  2125,  2614,  2126,  1497,   272,  1281,  1282,    33,
     272,  3048,  1282,  1029,  2969,    33,   182,  3142,   576,   361,
     182,  1029,   576,    33,     1,   367,    33,   561,     2,  1125,
    1499,  1500,  2823,  2933,    33,  2935,    99,   396,  1272,   272,
    1217,  1218,    33,   405,   405,   405,   405,   405,  3004,  1494,
    1029,   405,    33,  1407,  1408,  3212,  3227,  1171,    33,    33,
    2622,   349,  2770,  2625,  2583,  2889,  2890,  2891,  2892,  2893,
    2941,   444,  1487,  1488,  2580,  3434,  2943,  2944,  3336,  2945,
    2946,  2947,  2948,  2949,  2950,  2853,    54,  3567,  3570,     4,
   -2259,  3266,    33,  3347,   565,   599,    76,   112,   602,  2170,
      58,    58,  3754,    77,  2176,    43,   521,   324,   324,  2143,
     513,  2649,   527,  2081,  2341,   610,   611,   612,   613,  1226,
     614,   615,   616,   617,   618,   619,   620,   621,   622,   623,
     624,   625,   626,   627,   628,   629,   630,  2888,    33,   650,
    3330,  2428,  2330,   324,   946,  1235,  2938,   631,   632,    78,
      79,    43,   634,   578,   635,  3337,  3338,    80,  2147,  1042,
      33,  2437,   423,  1429,  2437,  3108,   573,  1227,   368,   638,
     639,   640,   641,   324,  1115,  3485,   648,  2214,    33,  1888,
     324,   563,  3704,   571,  1027,  1027,    54,   522,  3066,  1027,
    1027,  3744,  2687,   576,  3331,   369,  2130,   275,    54,   532,
    2914,    54,  1027,   947,  2783,  2444,  2586,  1111,  2941,  2943,
    2944,   182,  2945,  2946,  2947,  2948,  2949,  2950,  2941,   576,
    3229,  1111,  1027,  3231,  1040,  1027,  2872,   576,     6,  1359,
    1360,  1027,   594,  2120,  1430,  1027,  2881,  3067,    54,  1027,
     931,  1912,    44,  1027,   658,  2445,    54,  1027,  1027,   661,
    1027,   663,   667,  1027,    54,  1027,  1027,  1027,  2020,  1361,
    1362,  1363,  2020,  1027,  1999,  1528,  1027,  2025,  3008,   107,
     576,    54,   932,  1027,   182,   997,    33,   576,    26,  2655,
    1027,  1101,  2655,    48,  2710,  3755,  1227,  1027,  1165,     7,
    1094,    58,  1437,   315,   316,   317,   318,   319,  1027,   573,
     830,   923,  1027,  2587,  2361,  2718,  1027,    27,  2342,    33,
    2219,  2736,  1027,   579,  3339,  1027,  1024,  2738,   587,    52,
    2634,  2331,  2799,  1227,   670,  2859, -2259,   670,  1227,  3263,
    3028,  2973,  2332,  3028,  1533,   670,  3028,  1103,  1162,  1163,
    3199,  3199,  3199,  3199,  1024,  3068,  3071,   182,  3071,  3165,
      54,   100,   396,  3175,   396,  3241,  2144,   315,   316,   317,
     318,   319,   945,   405,  2177,  3310,   950,  1211,  2951,  3317,
    1214,  3402,    54,  3422,  1889,  3248,  3130,  3251,  3264,  2451,
    3254,   405,  2234,  2235,  1553,  3422,  3430,   110,  3536,    33,
    3578,  2638,  3578,  1219,  2905,  1452,   972,  3639,  3639,  1889,
    1228,  3026,    53,  3161,    33,  2784,  3677,     1,  1903,  1124,
    1165,    81,  1286,  1031,  2870,  3230,  3693,  3422,  1484,  2882,
    2141,   566,  3238,  3005,   665,  1491,  1286, -2259,  1495,  2176,
    1286,  3109,  1512,  1426,  1919,  3104, -2259,    33,  2327,  3255,
    3261,    33,  2577,   960,  1229,  1057,  1058,   325,  1453,  3435,
    2041,   315,   316,   317,   318,   319,  2487,  3504,  1115,  1230,
    1273,   670,  1919,   562,  1102,  1024,    58,    58,    58,  1016,
      58,  1020,  1022,  2863,  2663,  1030,  1032,  1033,  3228,  1496,
    1038,  3371,  1022,  1966,  1967,  1041,  1501,    58,  2952,  2953,
    2355,   915,  2086,  1220,  1905,  3143,  1033,  1107,  2056,  3381,
    1985,  2951,  2027,  3571,  2101,  3033,    82,  1030,  1030,  2052,
    3394,  1420,  3348,   588,   592,  2635,  2004,  1033,  1192,  3034,
    3170,   277,  1976,    58,  1449,  2700,  1445,  2001,  3355,    58,
    1033,    58,  3360,  1954,  3063,    58,   402,  3312,    58,  3314,
    1088,    58,  3157,  2954,   280,  1504,  3062,  2127,  1022,  3408,
    2568,    58,  2510,  2087,  3307,  2128,   405,  1105,  3568,  1030,
     293,  2155,  1454,  1112,   293,   402,    58,  1554,   949,   402,
    2758,   402,    58,  1502,   405,   405,   516,   996,  1230,    58,
      58,    58,  2453,  3539,  3326,  1186,  2639,  2322,  1193,  1409,
    3438,  2615,  3561,    58,  1079,   293,  2700,  3543,    83,   293,
    1206,  2894,  1206,   405,  2514,  1206,   405,  1977,  1206,    58,
    2514,  3450,  1344,  2700,  3353,  1230,    54,   564,  1910,   572,
    1230,  2952,  2953,  1978,  1027,   293,  3707,   286,  1364,   577,
    2438,  3199,  3199,  3364,   293,  3199, -2259, -2259, -2259, -2259,
   -2259,  2304,  3384,  3243,  3486,  3232,  2700,  1330,   293,  3690,
    1330,  3705,   293,  3599,  2308,   582,  2031,     1,   648,   648,
    3745,     2,     4,   583,  1953,    69,  1979,  1229,   595,  2032,
    2955,  3303,  2869,  3306,  2599,    33,  2954,  3461,    84,  2236,
     659,   293,  1024,  2600,  3167,   662,    85,   664,   668,  2177,
    3340,  2173,  3171,  3428,  2021,  3040, -2259,    37,  2022,    33,
    1231,  1232,  1233,  2026,  2031,  1980,  2473,  2601,  2031, -2259,
    2602,  1234,  1255,  2474,  1365,  2656,  1412,  2032,  2662,   289,
    2711,  2032,    33,  1413,   965,  2181,  2603,  3256,  3631, -2259,
    3467,   290,   291,  3233,  1981,  3447,  2956,  3448,  3449,   292,
    2716,  2719,   103,  1982,  1027,  1027,  1027,  2737,  3085,  1269,
    2421,     3,  2422,  2739,  2309,  1302,  3535,  1366,  2800,  1047,
     112,  2860,  3731,  1555,  2163,  3465,  3029,   925,  1347,  3030,
    1388,  2033,  3032,  2152,   153,  3719,    33,  2780,    10,  3468,
    1065,  3069,  3072,     5,  3076,  3166,  2957,  2958,  2214,  3176,
     926,  3242,  1402,  1074,    10,  1354,  1556,   670,   114,  3090,
    3496,  3311,  3050,  2955,   958,  3318,   959,  3403,  2460,  3423,
    3398,  2978,  2979,  3516,  2980,  2981,  2982,  1377,  2494,  2033,
    3406,  3429,  3431,  2033,  3537, -2259,  3579,  3421,  3580,  2443,
    2604,   116,  1030,  3640,  3647,    58,   188,  3662,   966,  1378,
    2046,  3630,  3678,  2626,   189,  3636,  2753,  1918,  2803,    33,
    2753,    58,  3694,  3730,  1030,  1437,  2423,  2031,   192,  2424,
    2509,  3553,     7,   607, -2259,  3257,  3199,  3258,  2310,  2956,
    2032,  1055,  3199,  3199,   426,  3199,  3199,  3199,  3199,  3153,
      33,  2214,  3412,  2605,  3199,  2035,  1922,    54,  2055,  3041,
    2606,     8,  1017,    58,    33,  1071,   231,  3556,  1112,  3428,
    3428,  2036,  3051,  1110,  2497,    33,   232,  2973,  3564,  1112,
    2118,  3566,     4,  2421,  2983,  2422,  1171,    33,    33,  2957,
    2958,  2219,  2984,    58,    58,    58,   239,    58,  3234,    58,
      58,  2291,    33,  2035,    54,    58,    58,  2035,    33,  3540,
    3052,  1160,    26,    27, -2259,  2607,  2650,   967,  1435,  2036,
      33,  1175,   241,  2036,  1190,  3023,  2985,  3732,  1196,  3091,
    3162,  3163, -2259,   330,  1202,  2986,  1204,   335,  1526,  2479,
      58,    53,  2033,    33,  2102, -2259,  1538,  2311,    33,  1537,
     255,  1899,    58,    33,   336,   337,   338,  1545,    54,  2082,
    1383,    33,  2566,  1103,  2987,  2988,  2280,  3199,  3155,    33,
    3199,  3199,  3199,  3199,  3053,  1191,    58,    58,   248,  1197,
    2723,  2724,  1384,  1201,  2219,    58,   249, -2259,  3054,  2423,
     251,  3554,  2424,  1244,  3132,  1309,    33,  2730,  2731,  2732,
     252,    58,    58,     5,  1245,  1494,  3622,  3623,  2454,  2989,
    2031,  2250,   675,  3297,  2214,    33,  3453,  3541,   984,  3458,
     929,   987,  3460,  2032,  1021,   925,    33,  1956,   256,  1177,
    2028,    54,  2114,  2030,   413,  1302,  1302,   257,   503,   414,
     415,   416,  3399,  2160,  2161,  1302,   258,  1257,   926,   259,
    2500,     6,  2272,  2990,  1246,  1383,  2035,    33,  1998,  2280,
    3199,  1037,    54,  3097,  3661,   423,  2005,  3304,  1247,  3199,
      33,   260,  2036,  1046,    33,   321,    54,  1384, -2259,  1178,
     261,  2072,     7,  3547,  3358, -1611,   262,  1111,  3055,  3547,
    2077,    33,  3557,  3558,  3559,  3560,  3686,  1029,  3688,    33,
      54,   413,  1066,   182,  3056,  3680,   414,  2991,   416,  2281,
    2705,     8,    33,  2065,    54,  2099,  1179,  2042,  1083,  1084,
     353,  2047,  2053,  2047,  1090,  2033,   263,  1092,  2282,  2283,
   -2259, -2259,  1111,  2059,  2061,  2062,  3031,  2837,    58,  2066,
    2068,  2069,  2070,  1030,  1115,   264,  1011,  2219,  2284, -2259,
   -2259,  2056,  1030, -2259, -2259,    54,  1210,  1248,  2709,  1213,
      54,  2713,  1216,  1112,    58,    54,    58,    58,    58, -2259,
     411,   412,  2795,    54,  -282,    58,    58,  1030,   265,    58,
     405,    54,   405,    58,   267,  1399,  1127,  1128,  1129,  1130,
    2733,  1112,  1485,  1486,  2034,  3663,  1489,  1490,  2117,  1112,
     309,  3713,  2281,  3180,  3181,    58,    58,   322,    54,   272,
    1281,  1282,    33,  1180,  3638,   310,  2478,  3641,  3642,  3643,
    3644,  2282,  2283,  2578,  2251,   104,   105,    54,  2404,  3581,
    1435,  2874,    33, -2259,   104,   105, -2259, -2259,  2252,  2035,
   -2259,  2284, -2259,  2433,  3546,  1093,  3549,  3550,  3551,  3552,
      58,    58,  2214,    58,  1100,  2036,   311,  2900,  2214,  -282,
    2923,   312,  2925,  2469,  2926,   313, -2259, -2259,  1530,  3200,
    3200,  3200,  3200,   360,  1524,  -282,    33,  2158,   371,   405,
     405,  2253,   165,  2565,   405,  3669,    58,   314,  2167,  2168,
    1181,  1160,  2254,   344,   166,   104,   105,   323,  3182,  1513,
    1209,  1519,  3682,  1212,  1379,  1380,  3664,  3699,   345,  1131,
    3665,    58,  3664,  2255,   346,  1986,  3665,  1132,  -282,  1969,
    2256,  1970,   373, -2259,   350,  2060,  1133,    33,  2257,  1134,
    1182,  1250,  1251,  2992,  2993,  2994,  2995,  2996,  2997,  2998,
    2999,  3000,  3001,  2063,   351,    33, -2259,   382,   355, -2259,
    2258,   359,  3669,  1392,  1393,  1394,  3472,  -282,  1531,  2067,
     362,    33,  1063,  2296,   366,  2297,  1124,   372,  2742,  3682,
      33, -2259,  1135,  2745,   381,    33,  1072, -2259,  2466,  1136,
    1077, -2259,  3724,   401,    33,  2219,  -282,  1991,   390,  1992,
    1993,  2219,  1091,  2185,   105,  -282,  1183,  2275,  2276,  1165,
     436,   391,  2199,  2200,  2083,   397,  2083,   374,  1507,  1508,
    1509,  1510,  1957,  2205,  2206,  2207,   400,  2208,   431,  2209,
    2210,  2298,  2299,   375,  1111,  2300,  2301,  2259,  2434,  2435,
    1976,  3473,   383,  2260,  3139,   172,  1137,  3695,  3696,  3368,
    2640,   433,  3113,  3046,  3047,  3410,  3411,  3073,   384,  3247,
    3247,   434,  3247,   445,   448,  3247, -2259,  1050,  1050,   173,
    2759,  1138,  2760,  1231,  1232,   449,   376,  2253,  1139,   451,
    1140,  2771,   452,   453,   455,  2631,   454,  3152,  2254,   504,
    1141,   517,   519, -2259,  3335,   437,   515,   524,   525,  3110,
     526,   385,   528,  3474,   529,  3475,  2792,  1958,   533,  2255,
     534,   438,   535,   174, -2259,   377,  2256,   538,  1142,   539,
   -2259,  3476,   175,  1959,  2257,  1977,  1143,   549,   550,  3477,
     551,   570,   554,  3478,   559,  2641,  3207,  3207,  3207,  3207,
     386,  1978,   569,   575,   378,   580,  2258,  2088,  2089,  2090,
     600,  2642,   605,   379,   439, -2259,  3437, -2259,  3479,   581,
     585,   593,   603,  1144,  2108,  1050,  1960,  2754,   608,   387,
    3200,  3200,   604, -2259,  3200,  1221,  2008,  2009,   388,   633,
     636, -2259,   642,   643,  1979, -2259,   649,  1145,   653,  1027,
    3118,   651,   652,   440,  2643,   654, -2259,   655,  3126,  3127,
     656,   657,  1284,   660,   666,  1961,   176,   177,   676,     1,
   -2259,   930,   935,  2242,  1285,  2243,  2244,   957,  2796,  2246,
    2247,   937,   441,  1980,  1146,  2266,   315,   316,   317,   318,
     319,   442,  2142,  2644,  1962,  1147,  2288,   938,   939,  1286,
     944,   953,   955,  1963,   956,   964,   971,  1206,   405,   405,
    1513,   969,  1981,   973,    58,    58,   992,   974,   975,  2452,
     994,  1982,  2645,   999,  2344,  1000,  1002,  2831,  2169,  1003,
    3183,  2646,  1004,  3184,  2238,  1030,  1005,  1030,  1030,  2184,
    1007,  1030,  1030,  1008,  2248,  1009,  3185,  1030,  1010,  1012,
    1122,  1198,  1259,  1260,  3009,  1261,  2010,  2011,  2012,  2013,
    2014,  2015,  2211,  1265,  1262,  2212,  2326,  2213,  1263,  3010,
    3011,    58,  1027,  1985,  2349,  1264,  1266,  1267,  3012,  1124,
    1268,  1303,  2292,  1270,  1271,  1165,  3187,  2214,  1274,  1275,
    1276,  1320,  3538,  1148,  1149,  1150,  1277,  2215,  3188,  1327,
    2006,  2007,  2008,  2009,  1328,  1027,  1151,  1332,  3426,  3427,
    1329,  1165,  3013,  1335,  1302,  1333,  1302,  2535,  2216,  2523,
    2525,  3014,  3247,  1336,  1337,  1338,  1302,  1302,  1030,  1345,
    1347,  2335,  1339,  1302,  1302,  1302,  1302,  1340,  1341,  3189,
    1346,  2217,  1350,  1352,  1351,  2218,  1112,  1353,  1357,  1376,
    3015,  1381,  2465,  3424,  3425,  3426,  3427,  1382,  1385,  1386,
    1387,  1221,  1406,  1389,  1395,  3200,  1410,  1411,  2042,  1414,
     648,  3200,  3200,  2047,  3200,  3200,  3200,  3200,  3190,  2053,
    3077,  3473,  2047,  3200,  1417,  1415,  2440,  3207,  3207,  1418,
    3191,  3207,  1422,  1434,  1423,  3016,  1437,  1425,  1439,  1441,
    2402,  1442,  3192,  3193,  1482,  1492,  2406,  1493,  3374,  1152,
    3194,  1497,  1520,  3195,  1521,  3107,  1522,  1529,  1523,  1527,
    2219,   293,  2010,  2011,  2012,  2013,  2014,  2015,  2010,  2011,
    2012,  2013,  2014,  2015,  2431,  1532,  1542,  1533,  1544,  3017,
    1879,  1880,  1881,  3474,   576,  3475,  1891,  1887,  1030,  1112,
    1882,  1894,  2447,  2448,  1897,   405,  3457,  1319,  1895,  3457,
    1321,  3476,  1322,  1323,  1324,  1325,  1326,  3376,  1896,  3477,
      58,  1944,  1955,  3478,  1965,  2010,  2011,  2012,  2013,  2014,
    2015,  1952,  1974,  1975,  1968,  1987,  1988,  1989,  1990,  2476,
    1994,    58,  1995,  1996,  1997,  2019,  3200,  2024,  3479,  3200,
    3200,  3200,  3200,  2045,  2058,  2073,  2074,  2075,  2078,  1504,
    2585,  2080,    58,  2079,  2501,  1545,  2100,  1302,  2093,  2109,
    1112,    58,  2107,  2111,  2120,  2122,  2133,  2145,  2134,  2148,
    2146,  2150,  1221,  2164,  2162,  2159,  2173,  3507,   405,   405,
    2180,  2187,  2182,  2188,  2190,  1889,  3515,  2226,  2228,  2229,
    2237,  2231,  2289,   405,  2293,  2294,  2295,  1985,    58,    58,
      58,  2302,  2304,  3521,    58,  2668,  2319,  1124,  1124,  2327,
    2345,  2351,  1030,  2352,  1278,  1279,  1280,  2340,  2353,  2358,
     272,  1281,  1282,    33,  2306,  2356,  2313,  2326,  2357,  3200,
    2361,  1303,  1303,  2394,  2392,  2393,  2313,  1309,  3200,    58,
    2396,  1303,  2114,  2336,  2337,  2338,  2339,  2621,  2621,  2408,
    2395,  2621,  2397,  2399,  2410,  1027,  2411,  2412,  2390,  2413,
    2308,  1027,  3207,  2414,  2416,  2419,  2418,  2417,  3207,  3207,
    1302,  3207,  3207,  3207,  3207,  2432,  1888,  2455,  2420,  1302,
    3207,  2457,  1302,  1302,  1302,  1302,  2661,  1027,  2458,  1030,
    2464,  2462,  3565,  2666,  1302,  2467, -2259,  2684,  3269,  3270,
    3271,  2471,  3273,  3274,  3275,  3276,  3277,  3278,  2472,  1283,
    2477,  3281,  2480,   182,  2484,  2481,  2504,  1234,  2701,  2701,
    2701,  2099,  2514,  2701,  1302,  2715,  2490,  2516,  2042,  2498,
    2563,  2564,  2575,  2596,  2581,  2590,  2589,  2591,  2594,  2630,
    3349,  2629,  2632,  2636,  2651,  2618,  2595,  2652,  2611,  3616,
    2653,  2665,  2681,  2610,  2686,  2688,  2690,  2740,  2692,  2741,
    2743,  2693,  2744,  2746,  2720,  2697,  2748,  2721,  3365,  2722,
    2047,  2725,  2726,  2727,  2047,    58,  2728,    58,  2729,  2751,
    2756,  2767,  2785,  1030,  2701,  2787,    58,  2431,  2789,  2790,
    2776,  2776,  2791,  3207,  2797,  2793,  3207,  3207,  3207,  3207,
    2805,  1221,  2808,  2806,  2809,  2810,  2812,  2813,  2811, -2259,
    2829,    58,  2832,  1399,  2830,  1494,  1233,  2836,  2794,  2845,
    2847,    58,  2856,  2857,  2861,  3457,  2858,  2508,  2415,  2865,
      58,  2866,  2875,  2873,    58,  1111,  2903,  2908,  1460,  2898,
    2921,  2916,  2917,  2918,  2919,  2920,  2924,  2927,  2941,  2929,
    2942,  2930,  2964,  2931,  3621,  2439,  2932,  2967,  2976,    58,
    3692,  3025,  2090,  3670,  3671,  3672,  3673,  3674,  3675,  3026,
    3027,  2862,  3035,  3038,  3039,  3042,  3044,  3045,  3074,  3064,
    3075,  3078,  3088,  2838,  3080,  3092,  3207,  3065,  3081,  1513,
    3096,  3099,  3106,  3117,  3114,  3207,  3125,  3135,  3147,  3158,
    2886,  3159,  3167,  3174,  3177,  3178,  2000,  3219,  2486, -2259,
    3236,  3226,  3249,  3235,  3237,  3239,  2902,  3252,  3260,  3240,
    3262,  3267,  3268,  3272,  3287,  3279,  3286,  3280,  3290,  3291,
    3052,  3292,  3293,  1030,  3294,  3295,  3296,  3301,  3308,  2669,
    1309,  3309,  3313,  1027,  1027,  3315,  3319,  3320,  2701,  2654,
    3344,  3324,  2657,  2658,  2659,  2660,  2877,  2248,  2701,  3350,
    3352,  2238,  1030,   923,  1302,  3351,  3353,  3366,  2326, -2259,
    2326,  3370,  3372,  3375,  3379,  1228,  3390,  2238,  1030,  2364,
    3387,    58,  2621,  3400,  3422,  3413,  3394,  3414,  3415,  3416,
    3417,  3432,    63,  3148,  2114,  3150,  3418,  3433,  3466,  3419,
    3439,  3442,  3687,  1284,  3443,  3446,  3444,  3445, -1800,  3451,
    3509,  3470,  3489,  3488,  3023,  1285,  3490,  3493,  3492,  3499,
    3494,  3501,  1302,  3495,  3502,  3508,  3514,  3518,  3519,  3512,
    1030,   923,  1030,  3520,  3137,  1302,  3522,  1302,  3523,  1461,
    1286,  3524,  3526,  3528, -2259, -2259,  3116,  2001,  1302,  3544,
    3542,   648,  3532,  2701,    58,  2684,   154,   185,  3562,   648,
     648,  3572,  3573,  3574,  3582,   182,  3594,  2701,  3592,  3593,
    3595,  1287,  3597,  3596,  2670,  3602,  3614,  3620,  3627,  3615,
    3637,  3645,  3648,  3759,  3650,  2047,  2671,  1289,  2205,  2206,
    2207,  3660,  2208,  3676,  2209,  2210,  2440,  3698,  3689,  3700,
    3706,  3701,  3702,  2053,  3703,  2047,   182,  3708,  3717,  3728,
    3729,  3738,  3742,  3740,  1985,  3741,  3743,  3746,  2402,  3747,
    3752,   185,  3753,  3049,  3758,    58,  3757,  1290,  3121,  3070,
    3716,  1342,  2747,  2172,    49,    50,  2821,  2772,  3095,  1291,
     185,  2781,  1950,  2489,   191,   530,  2761,  2762,  2090,  2765,
    2431,   196,  3098,   343,  3100,  2346,  1001,  2701,  1030,   531,
      58,  2347,   356,   523,   669,   348,  1462,  2786,   934,  1971,
    3601,   963,  1463,  1464,  1465,    58,  1165,    58,  3122,    58,
    1292,   558,   556,   940,  3714,  2405,   941,  1334,   589,  1185,
    2619,  2627,    58,  2449,  1466,  2198,  2763,  3146,  3389,  1302,
    2202,  2513,  2835,  1948,  3739,  3441,  2768,  3517,  2533,  2104,
      46,   128,   405,  1293,   405,  2365,    60,  3483,    61,  1294,
      47,  2496,  2499,  1258,    58,    58,  2186,  3362,  1295,  1296,
    1302,  1297,  1089,  2828,  1309,  2366,  2367,  2368,   514,  1356,
    3367,  1221,  2701,  1298,  1299,  2225,  2140,  2503,  1885,  3471,
    3583,  1300,  2095,  1121,  1301,  2138,  3196,  3196,  3196,  3196,
    2701,  2701,   293,  3720,  2085,   509,   510,  3300,  3591,  3141,
      58,  2153,   185,  2468,  2369,  3221,   185,   609,  3299,  3197,
    3197,  3197,  3197,  3282,  3346,  3021,  2370,  3505,  3503,  3500,
    3329,  2135,  2928,  2391,  2757,  3357,  2867,  2371,  2360,  1467,
    2717,  3723,  1468,  3464,  2268,  2269,  2887,  2939,  1302,  1302,
    1469,  2593,  3407,  2372,  3598,  3302,  3325,  2584,  2963,  1302,
    1302,  2664,  1302,  2373,  3244,  1302,  2936,  1302,  3245,  3459,
    3651,  1302,  3487,  3321,  3037,  2896,  2241,  2897,  2374,  3022,
    1303,    42,  1303,  3751,  1936,  1470,  2974,  3409,  2975,  3173,
    2321,  3463,  1303,  1303,  2320,  2233,  3629,  3323,  1902,  1303,
    1303,  1303,  1303,  2879,  3405,  3545,   182,  2211,   648,  3563,
    2212,    58,  2213,  2937,  2196,  2940,  3555,  1436,  3102,  3105,
    1471,  2343,  2788,  2103,    58,     0,  2375,   677,  2113,     0,
       0,     0,  2214,  2701,  3305,  2701,     0,  2119,     0,  1472,
    1473,     0,  2215,     0,  1460,     0,     0,     0,  3498,     0,
    1474,     0,     0,     0,     0,  1475,  2376,     0,  3498,  1030,
       0,     0,     0,  2532,     0,     0,  2377,     0,     0,     0,
       0,  3327,  3328,     0,     0,  2748,     0,     0,  2047,     0,
       0,     0,     0,     0,     0,    58,  2217,  2378,     0,     0,
    2218,  2379,     0,     0,  1476,  2776,   637,     0,  3359,  2776,
       0,     0,     0,   405,     0,     0,     0,   185,     0,  2508,
       0,     0,     0,    58,     0,     0,   405,     0,    58,  2380,
       0,     0,     0,     0,     0,     0,  1477,    58,  2381,     0,
       0,     0,  3506,     0,     0,     0,     0,     0,     0,  3079,
    1309,     0,  3084,     0,     0,     0,     0,     0,  1050,     0,
       0,     0,  1027,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  2219,  3391,     0,     0,     0,
     185,     0,  2701,     0,     0,     0,     0,     0,     0,     0,
       0,  2877,  2701,  1303,  2238,  2238,  2326,  3196,  3196,     0,
       0,  3196,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  3420,     0,     0,     0,  1160,     0,     0,     0,
    3197,  3197,     0,     0,  3197, -2259, -2259, -2259,     0, -2259,
       0, -2259, -2259,     0,     0,    58,  2238,     0,     0,     0,
       0,     0,     0,  3198,  3198,  3198,  3198,  3259,     0,     0,
       0,     0,     0,   185,     0,  1461,     0,     0,  1030,     0,
       0,     0,     0,     0,     0,     0,  1112,     0,     0,  1112,
       0,     0,  1302,     0,     0,  1302,     0,  1302,     0,  2701,
       0,  1013,  1014,  1015,     0,  1018,     0,     0,     0,  3456,
       0,     0,  3456,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1044,    58,     0,     0,  1303,     0,  3250,     0,
    3253,     0,     0,     0,     0,  1303,     0,     0,  1303,  1303,
    1303,  1303,     0,     0,     0,     0,     0,     0,     0,     0,
    1303,     0,     0,     0,     0,     0,     0,     0,  1068,     0,
       0,  1302,     0,     0,  1073,     0,  1075,     0,     0,     0,
    1082,     0,     0,  1082,     0,     0,  1082,     0,     0,     0,
    1303,   405,     0,     0,     0,    58,  1095,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1095,  1462,    58,     0,     0,  3626,  1156,  1463,  1464,
    1465,     0,     0,     0,  1018,  1169,  1172,     0,     0,     0,
    1187,     0,     0,     0,     0,     0,     0,     0,  1199,     0,
    1466,    58,   156,   157,     0,     0,  1302,     0,     0,  2701,
     158,    33,     0,     0,  1223,     0,     0,     0,     0,     0,
    1302,     0,  3196,     0,     0,     0,     0,     0,  3196,  3196,
       0,  3196,  3196,  3196,  3196,     0,     0,  2701,     0,  2701,
    3196,     0,  1302,     0,     0,  3197,     0,  1221,   182,     0,
       0,  3197,  3197,     0,  3197,  3197,  3197,  3197,     0,     0,
       0,     0,     0,  3197,     0,     0,     0,     0,  2270,  2271,
       0,     0,     0,     0,  3363,  2287,     0,    58,     0,     0,
       0,  3576,    58,     0,    58,     0,     0,     0,     0,     0,
       0,     0,   159,     0, -2259,     0,     0, -2259,     0, -2259,
       0,     0,  2701,   648,   160,  1467,     0,     0,  1468,     0,
    3382,   469,   470,   471,     0,    58,  1469,     0,     0, -2259,
       0,     0,     0,     0,  3198,  3198,     0,     0,  3198, -2259,
       0,   161,     0,    58,   472,  3462,     0,  2963,     0,     0,
       0,     0,     0,  3391,     0,     0,     0,     0,     0,  1302,
   -2259,  1470,     0,  3196,     0,     0,  3196,  3196,  3196,  3196,
       0,  3646,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0, -2259,     0,  3649,  3197, -2259,     0,  3197,
    3197,  3197,  3197,     0,     0,  1112,  1471,     0,     0,  1302,
    1303,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1472,  1473,     0,  3456,     0,
      58,    58,    58,    58,    58,    58,  1474,     0,     0,     0,
       0,  1475,  3681,    54,     0,   162,     0,     0,     0,     0,
       0,   473,   474,   475,   476,   477,   478,     0,     0,     0,
    1223,     0,     0,     0,     0,     0,  3196,     0,  1303,   479,
     480,   481, -2259,     0,     0,  3196,  1400,     0,     0,     0,
    1476,  1303,     0,  1303,     0,     0,     0,     0,     0,  3197,
       0,     0,     0,     0,  1303,     0,  1309,     0,  3197,     0,
       0,     0,     0,  2470,     0,     0,     0,     0,     0,     0,
    2306,     0,  1477,     0,     0,     0,     0,     0,  1428,     0,
    1302,     0,  3725,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   163,  2511,     0,  3510,  1303,     0,  1456,  1456,
    1456,     0,  1456,     0,  1456,  1456,     0,     0,     0,     0,
      63,    63,     0,     0,     0,     0,     0,  3749,  3750,  3725,
    1907,     0,     0,     0,     0,     0,     0,   164,     0,  3198,
    3533,     0,    58,     0,  3760,  3198,  3198,     0,  3198,  3198,
    3198,  3198,     0,     0,     0,  1172,     0,  3198,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1540,     0,   482,
       0,   165,   483,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   166,     0,     0,     0,     0,     0,     0,
       0,  1223,  1400,     0,     0,     0,     0,     0,     0,  3635,
    1892,     0,     0,     0,     0,  1303,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1900,  1900,     0,   167,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1908,     0,   168,     0,  1303,     0,     0,  3652,
    1909,     0,   169,     0,     0,     0,  1910,     0,  1911,     0,
       0,     0,     0,     0,     0,   170,     0,     0,     0,  1912,
       0,     0,  1303,  1303,  1303,  1303,     0,     0,     0,     0,
    3198,     0,     0,  3198,  3198,  3198,  3198,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1913,     0,     0,
       0,     0,   484,     0,     0,     0,     0,     0,     0,   171,
       0,     0,     0,  1914,     0,     0,     0,   485,  1915,     0,
       0,   486,     0,     0,  1303,  1303,     0,     0,     0,     0,
    1916,     0,     0,     0,   172,  1303,  1303,  1917,  1303,     0,
       0,  1303,     0,  1303,     0,     0,     0,  1303,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   487,   173,     0,
    3635,     0,     0,  1050,  1050,  1050,     0,  1050,  1050,  1050,
    1050,  1050,  1050,  3198,     0,     0,  1050,     0,     0,  3679,
       0,     0,  3198,     0,     0,   488,     0,     0,     0,    63,
       0,    63,  1172,  1082,     0,     0,     0,     0,  2817,  2818,
    2094,  1095,   174,   489,  1172,     0,     0,     0,  2105,  2827,
       0,   175,     0,     0,     0,     0,     0,     0,     0,   185,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1223,  1156,     0,  2839,  2840,  2841,  2842,  2843,  2844,     0,
       0,     0,     0,  2849,  2850,  2851,  2852,     0,     0,   269,
    2854,     0,     0,     0,     0,     0,     0,     0,   270,   271,
       0,     0,     0,     0,   272,   273,   274,    33,     0,     0,
       0,     0,     0,     0,     0,  2139,  1156,     0,    63,     0,
       0,     0,  3736,     0,   490,  1918,     0,     0,     0,     0,
    1919,     0,     0,     0,     0,   176,   177,  1920,     0,     0,
       0,     0,     0,  1221,     0,     0,     0,     0,     0,     0,
       0,  2165,     0,     0,     0,     0,     0,     0,     0,  1921,
       0,     0,     0,     0,  1922,     0,     0,     0,     0,     0,
       0,     0,  2906,  2907,     0,     0,  2192,     0,     0,  2911,
    2912,     0,     0,     0,     0,     0,     0,     0,   159,     0,
     491,     0,     0,   275,     0,     0,     0,     0,     0,     0,
     160,     0,     0,  1303,  1303,     0,     0,  1303,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   472,     0,   161,     0,     0,
       0,     0,   597,   456,   457,   458,     0,   459,   460,   461,
     462,   463,   464,   465,   466,   467,   468,   469,   470,   471,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     472,     0,  1303,     0,     0,  1303,     0,     0,  1303,     0,
       0,  1303,     0,  1303,  1278,  1279,  1280,     0,     0,     0,
     272,  1281,  1282,    33,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    54,
       0,   162,   473,   474,   475,   476,   477,   478,     0,  3086,
    3087,     0,     0,     0,     0,     0,     0,     0,  3094,     0,
     479,   480,   481,     0,     0,     0,     0,  1303,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   473,   474,   475,
     476,   477,   478,     0,     0,  3128,  3129,     0,     0,  1283,
       0,     0,     0,     0,     0,   479,   480,   481,     0,     0,
       0,     0,     0,     0,     0,     0,   269,     0,     0,     0,
       0,     0,  3149,     0,  3151,   270,   271,     0,     0,     0,
       0,   272,   273,   274,    33,     0,     0,     0,   163,     0,
       0,     0,  1303,   276,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1303,     0,  1303,     0,
       0,     0,     0,     0,  1303,  1303,     0,  1303,  1303,  1303,
    1303,     0,     0,   164,     0,     0,  1303,     0,  1303,     0,
       0,     0,     0,     0,     0,  3222,  3223,     0,     0,  3224,
    3225,     0,     0,     0,  1303,     0,     0,     0,     0,     0,
     482,     0,     0,   483,     0,     0,     0,   165,     0,     0,
       0,     0,     0,     0,     0,   159,     0,     0,     0,   166,
     275,     0,     0,     0,     0,  1111,     0,   160,     0,  2224,
    1223,     0,     0,     0,     0,     0,     0,   277,     0,     0,
       0,     0,   278,     0,   279,   482,     0,     0,   483,     0,
       0,     0,     0,     0,   161,   167,     0,     0,     0,     0,
     280,     0,     0,     0,     0,     0,     0,     0,     0,  1221,
     168,     0,     0,     0,     0,   281,     0,     0,   282,     0,
       0,   283,     0,     0,  3289,  1303,  2274,     0,     0,  1303,
     284,   170,  1303,  1303,  1303,  1303,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1303,     0,   484,     0,  1303,     0,     0,     0,  2669,
     644,   285,     0,     0,     0,   171,     0,     0,   485,     0,
       0,     0,   486,   286,     0,     0,    54,     0,   162,     0,
       0,     0,     0,     0,   287,     0,     0,     0,     0,     0,
     172,     0,     0,     0,     0,  3356,     0,     0,   484,  3361,
       0,     0,     0,     0,     0,     0,     0,     0,   487,     0,
       0,     0,  1303,   485,   288,     0,     0,   486,  3369,     0,
       0,  1303,     0,  1284,     0,     0,     0,   272,  1281,  1282,
      33,     0,     0,     0,     0,  1285,   488,  3380,   460,   461,
     462,   463,   464,   465,   466,   467,   468,   469,   470,   471,
       0,     0,     0,   487,   489,     0,     0,     0,   174,     0,
    1286,     0,     0,     0,     0,   289,  1303,   175,     0,     0,
     472,     0,     0,     0,     0,   163,     0,   290,   291,     0,
     276,   488,     0,     0,     0,   292,     0,     0,     0,     0,
       0,  1287,     0,     0,  2670,     0,   293,     0,     0,   489,
       0,     0,     0,     0,     0,     0,  2671,  1289,     0,   269,
     164,     0,     0,     0,     0,  2461,  3182,     0,   270,   271,
       0,     0,     0,     0,   272,   273,   274,    33,  1221,     0,
       0,     0,     0,     0,     0,   490,  1172,     0,     0,     0,
       0,     0,     0,     0,   165,     0,     0,  1290,     0,     0,
       0,   176,   177,     0,     0,     0,   166,   154,     0,  1291,
       0,     0,     0,     0,     0,     0,  1156,   473,   474,   475,
     476,   477,   478,     0,   277,     0,     0,     0,     0,   278,
     490,   279,     0,     0,     0,   479,   480,   481,     0,     0,
       0,     0,   167,     0,     0,     0,     0,   280,     0,     0,
    1292,   491,     0,  1172,  2567,  1172,     0,   168,   159,  1018,
       0,     0,   281,   275,     0,   282,     0,     0,   283,     0,
     160,     0,     0,     0,     0,     0,     0,   284,   170,     0,
       0,     0,     0,  1293,     0,     0,     0,     0,     0,  1294,
       0,     0,  1111,     0,  2613,     0,   491,   161,  1295,  1296,
       0,  1297,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1298,  1299,     0,     0,  1396,   285,     0,
       0,  1300,   171,     0,  1301,     0,     0,     0,     0,     0,
     286,     0,   293,     0,     0,     0,     0,     0,     0,  3531,
       0,   287,  3534,     0,     0,     0,     0,   172,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   288,     0,     0,     0,   482,     0,     0,   483,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    54,
       0,   162,   269,     0,     0,     0,     0,     0,     0,     0,
       0,   270,   271,     0,     0,     0,     0,   272,   273,   274,
      33,     0,     0,     0,     0,   174,     0,     0,     0,     0,
       0,     0,   289,     0,   175,     0,     0,     0,     0,     0,
    1172,     0,  1172,     0,   290,   291,     0,     0,     0,     0,
       0,  1172,   292,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   293,     0,     0,     0,     0,     0,   185,
    1284,     0,     0,     0,     0,     0,  1172,     0,     0,     0,
       0,     0,  1285,     0,     0,     0,  1223,     0,     0,     0,
       0,     0,     0,     0,     0,  2801,  3624,     0,   163,  2804,
       0,   159,     0,   276,     0,     0,   275,  1286,   484,     0,
       0,     0,     0,   160,     0,     0,     0,     0,   176,   177,
       0,     0,     0,   485,  2826,     0,     0,   486,     0,     0,
       0,     0,     0,   164,     0,     0,     0,     0,  3183,     0,
     161,  3184,     0,     0,     0,     0,     0,     0,     0,     0,
    3653,  3654,     0,  3656,  3185,  3658,  3659,     0,     0,     0,
       0,     0,     0,   487,     0,     0,     0,   165,     0,     0,
       0,     0,     0,     0,     0,     0,   980,     0,     0,   166,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   488,     0,     0,  3187,     0,     0,   277,     0,     0,
       0,     0,   278,     0,   279,     0,  3188,     0,     0,   489,
       0,     0,     0,     0,     0,   167,     0,     0,     0,     0,
     280,  3709,     0,  3710,     0,     0,     0,     0,     0,     0,
     168,     0,    54,     0,   162,   281,     0,     0,   282,     0,
       0,   283,     0,     0,     0,     0,  2904,  3189,     0,     0,
     284,   170,     0,     0,     0,     0,     0,  3722,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  3733,  3734,     0,
       0,  3735,     0,     0,  3737,     0,  3190,     0,     0,     0,
     490,   285,     0,     0,     0,   171,     0,     0,  3191,     0,
       0,     0,     0,   286,     0,     0,     0,     0,     0,     0,
    3192,  3193,     0,     0,   287,     0,  2764,     0,  3194,  1172,
     172,  3195,     0,     0,     0,     0,     0,     0,     0,   293,
       0,   163,   269,     0,     0,     0,   276,     0,     0,     0,
       0,   270,   271,     0,   288,     0,     0,   272,   273,   274,
      33,     0,     0,     0,     0,     0,   491,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   164,   458,     0,   459,
     460,   461,   462,   463,   464,   465,   466,   467,   468,   469,
     470,   471,     0,     0,     0,     0,   567,     0,   174,     0,
    1172,     0,     0,     0,     0,   289,     0,   175,     0,     0,
     165,     0,   472,     0,     0,     0,     0,   290,   291,     0,
       0,     0,   166,     0,     0,   292,     0,     0,     0,     0,
       0,   185,     0,     0,     0,  1172,   293,     0,     0,     0,
     277,   159,     0,     0,     0,   278,   275,   279,     0,     0,
    3119,     0,  1044,   160,  3123,     0,     0,     0,   167,     0,
       0,     0,     0,   280,     0,     0,     0,  3134,     0,     0,
       0,     0,   185,   168,     0,     0,     0,     0,   281,     0,
     161,   282,     0,     0,   283,     0,     0,     0,     0,     0,
       0,   176,   177,   284,   170,     0,     0,   471,     0,  3154,
    3156,   467,   468,   469,   470,   471,     0,     0,     0,   473,
     474,   475,   476,   477,   478,     0,     0,     0,   472,     0,
       0,     0,     0,     0,     0,     0,   472,   479,   480,   481,
       0,     0,     0,  3138,   285,     0,     0,     0,   171,     0,
       0,     0,     0,     0,     0,  3220,   286,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   287,     0,     0,
       0,     0,     0,   172,     0,     0,     0,     0,     0,     0,
       0,     0,    54,     0,   162,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   288,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   473,   474,   475,   476,   477,
     478,     0,     0,   473,   474,   475,   476,   477,   478,     0,
       0,   174,     0,   479,   480,   481,     0,     0,   289,     0,
     175,   479,   480,   481,     0,     0,  3283,     0,     0,     0,
     290,   291,     0,     0,     0,     0,     0,     0,   292,  3298,
       0,     0,     0,     0,     0,     0,     0,   482,     0,   293,
     483,   163,     0,     0,     0,     0,   276,     0,     0,     0,
    2802,   456,   457,   458,     0,   459,   460,   461,   462,   463,
     464,   465,   466,   467,   468,   469,   470,   471,     0,     0,
     130,     0,     0,     0,     0,     0,   164,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   472,     0,
    1172,     0,     0,     0,   176,   177,     0,     0,     0,     0,
       0,     0,   185,     0,     0,     0,     0,     0,     0,   131,
     165,     0,     0,     0,     0,     0,     0,     0,  1172,     0,
       0,     0,   166,  1156,     0,     0,     0,     0,   132,   133,
       0,     0,  1223,     0,     0,     0,     0,     0,     0,     0,
     277,     0,     0,   482,     0,   278,   483,   279,     0,     0,
       0,   482,     0,     0,   483,     0,     0,     0,   167,     0,
     484,     0,     0,   280,     0,     0,     0,     0,   134,     0,
       0,     0,     0,   168,     0,   485,     0,     0,   281,   486,
     135,   282,     0,     0,   283,   473,   474,   475,   476,   477,
     478,   136,     0,   284,   170,  2536,  2537,  2538,  2539,  2540,
    2541,     0,     0,   479,   480,   481,     0,   137,     0,     0,
       0,     0,     0,     0,     0,   487,     0,   138,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1156,     0,   139,     0,   285,     0,     0,     0,   171,     0,
       0,     0,     0,   488,     0,     0,   286,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   287,     0,     0,
       0,   489,     0,   172,     0,     0,   484,     0,     0,     0,
       0,     0,   140,     0,   484,     0,   130,     0,     0,     0,
       0,   485,     0,     0,     0,   486,     0,   288,     0,   485,
       0,     0,  2542,   486,     0,   141,     0,     0,  3283,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     142,     0,     0,     0,     0,   131,     0,   143,     0,     0,
     144,   487,     0,     0,     0,     0,     0,     0,     0,   487,
       0,   174,     0,     0,   132,   133,     0,     0,   289,     0,
     175,   145,   490,   482,     0,   146,   483,     0,     0,   488,
     290,   291,     0,     0,     0,     0,     0,   488,   292,     0,
    1172,     0,     0,     0,   147,     0,     0,   489,     0,   293,
       0,     0,     0,     0,   134,   489,     0,     0,  1172,     0,
       0,     0,   148,     0,     0,     0,   135,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   136,     0,     0,
       0,     0,     0,     0,     0,     0,  1156,     0,   491,     0,
       0,     0,     0,   137,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   138,   176,   177,  1557,  1558,  1559,  1560,
    1561,  1562,     0,  1563,  1564,  1565,     0,     0,   139,  1566,
    1567,  1568,  1569,  1570,  1571,     0,     0,     0,   490,     0,
       0,     0,     0,     0,  1572,     0,   490,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   484,     0,     0,     0,
       0,     0,     0,     0,     0,  1573,     0,     0,   140,     0,
       0,   485,  3283,     0,     0,   486,     0,  3586,     0,  3588,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   141,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   491,     0,   142,     0,     0,     0,
    1172,   487,   491,   143,     0,     0,   144,     0,     0,  2543,
       0,     0,  1574,     0,     0,     0,     0,     0,  1223,     0,
       0,  1575,  2544,     0,   185,     0,     0,   145,     0,   488,
       0,   146,     0,     0,     0,     0,     0,     0,     0,  1576,
    1577,     0,     0,     0,     0,     0,     0,   489,  1578,     0,
     147,     0,     0,     0,     0,  1579,  1580,     0,     0,  1581,
    1582,  1583,  1584,     0,     0,  1585,  1586,     0,   148,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  2545,     0,     0,     0,     0,     0,
    2546,     0,     0,     0,     0,  1456,  1456,  1456,  1456,  1456,
    1456,     0,     0,     0,     0,  1587,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1588,   490,  2547,
       0,     0,     0,  1589,     0,     0,     0,     0,     0,  2195,
    1590,     0,  1591,     0,     0,     0,     0,  1592,     0,     0,
       0,     0,     0,  2548,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  2549,  2550,     0,     0,     0,     0,  2551,
       0,     0,     0,  1593,     0,     0,     0,     0,     0,  2552,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   491,     0,     0,     0,     0,     0,
       0,  2553,     0,     0,  2554,  2555,     0,     0,     0,  2556,
       0,  1594,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1595,     0,     0,     0,     0,     0,
    1596,     0,     0,     0,     0,     0,     0,     0,     0,  1597,
    1598,     0,     0,     0,     0,     0,  1599,  1223,     0,  1600,
    1601,     0,     0,     0,  1602,     0,     0,     0,     0,     0,
    1603,  1604,     0,     0,     0,     0,  2557,  1605,  1606,  1607,
       0,     0,  1608,  1609,  1610,     0,     0,  2558,  1611,     0,
       0,     0,  1612,     0,  1613,     0,     0,     0,     0,     0,
       0,  1614,  1615,  1616,  1617,     0,  1618,  1619,     0,     0,
       0,  1620,  1621,     0,  1622,  1623,  1624,  1625,  1626,  1627,
    1628,     0,     0,     0,     0,     0,  1629,  1630,  1631,     0,
    1632,  1633,     0,     0,     0,  1634,  1635,  1636,  1637,  1638,
    1639,  1640,  1641,     0,  1642,     0,     0,     0,  1643,  1644,
    1645,  1646,  1647,  1648,  1649,  1650,  1651,  1652,  1653,  1654,
    1655,  1656,  1657,  1658,  1659,  1660,  1661,  1662,  1663,  1664,
    1665,  1666,  1667,  1668,  1669,  1670,  1671,  1672,  1673,  1674,
    1675,  1676,  1677,  1678,     0,  1679,  1680,     0,     0,  1681,
    1682,  1683,  1684,  1685,  1686,  1687,  1688,  1689,  1690,     0,
    1691,  1692,  1693,  1694,  1695,  1696,  1697,  1698,  1699,  1700,
    1701,  1702,  1703,  1704,  1705,     0,     0,  1706,  1707,  1708,
    1709,  1710,  1711,  1712,  1713,  1714,     0,  1715,  1716,  1717,
    1718,     0,  1719,  1720,  1721,  1722,  1723,  1724,  1725,  1726,
    1727,  1728,  1729,  1730,  1731,  1732,  1733,  1734,  1735,  1736,
    1737,  1738,  1739,  1740,  1741,  1742,  1743,  1744,  1745,  1746,
    1747,  1748,  1749,  1750,  1751,  1752,  1753,  1754,     0,  1755,
    1756,  1757,  1758,  1759,  1760,     0,     0,  1761,  1762,     0,
    1763,  1764,  1765,  1766,  1767,  1768,  1769,  1770,  1771,  1772,
    1773,  1774,  1775,  1776,  1777,  1778,  1779,  1780,  1781,  1782,
    1783,  1784,  1785,  1786,  1787,  1788,     0,     0,  1789,  1790,
    1791,  1792,  1793,  1794,  1795,  1796,  1797,  1798,  1799,  1800,
    1801,  1802,  1803,  1804,  1805,  1806,  1807,  1808,  1809,  1810,
    1811,  1812,  1813,  1814,  1815,  1816,  1817,  1818,  1819,  1820,
    1821,  1822,  1823,  1824,  1825,  1826,  1827,  1828,  1829,  1830,
    1831,  1832,  1833,  1834,  1835,  1836,  1837,  1838,  1839,  1840,
    1841,  1842,  1843,  1844,  1845,  1846,  1847,  1848,  1849,  1850,
       0,     0,     0,     0,  1851,  1852,  1853,  1854,  1855,  1856,
    1857,  1858,  1859,  1860,  1861,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1862,     0,     0,     0,     0,
       0,     0,     0,  1863,     0,     0,     0,     0,  1864,     0,
       0,     0,  1865,     0,     0,  1866,  1867,  1868,  1869,     0,
       0,  1870,  1871,     0,  1872,  1873,  1874,  1557,  1558,  1559,
    1560,  1561,  1562,     0,  1563,  1564,  1565,     0,     0,     0,
    1566,  1567,  1568,  1569,  1570,  1571,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1572,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1573,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1574,     0,     0,     0,     0,     0,     0,
       0,     0,  1575,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1576,  1577,     0,     0,     0,     0,     0,     0,     0,  1578,
       0,     0,     0,     0,     0,     0,  1579,  1580,     0,     0,
    1581,  1582,  1583,  1584,     0,     0,  1585,  1586,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1587,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1588,     0,
       0,     0,     0,     0,  1589,     0,     0,     0,     0,     0,
       0,  1590,     0,  1591,     0,     0,     0,     0,  1592,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1593,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  3180,  3181,     0,     0,     0,     0,   272,  1281,  1282,
      33,     0,  1594,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1595,     0,     0,     0,     0,
       0,  1596,     0,     0,     0,     0,     0,     0,     0,     0,
    1597,  1598,     0,     0,     0,     0,     0,  1599,     0,     0,
    1600,  1601,     0,     0,     0,  1602,     0,     0,     0,     0,
       0,  1603,  1604,     0,     0,     0,     0,     0,  1605,  1606,
    1607,     0,     0,  1608,  1609,  1610,     0,     0,     0,  1611,
       0,     0,     0,  1612,     0,  1613,     0,     0,     0,     0,
       0,     0,  1614,  1615,  1616,  1617,  3182,  1618,  1619,     0,
       0,     0,  1620,  1621,     0,  1622,  1623,  1624,  1625,  1626,
    1627,  1628,     0,     0,     0,     0,     0,  1629,  1630,  1631,
       0,  1632,  1633,     0,     0,     0,  1634,  1635,  1636,  1637,
    1638,  1639,  1640,  1641,     0,  1642,     0,     0,     0,  1643,
    1644,  1645,  1646,  1647,  1648,  1649,  1650,  1651,  1652,  1653,
    1654,  1655,  1656,  1657,  1658,  1659,  1660,  1661,  1662,  1663,
    1664,  1665,  1666,  1667,  1668,  1669,  1670,  1671,  1672,  1673,
    1674,  1675,  1676,  1677,  1678,     0,  1679,  1680,     0,     0,
    1681,  1682,  1683,  1684,  1685,  1686,  1687,  1688,  1689,  1690,
       0,  1691,  1692,  1693,  1694,  1695,  1696,  1697,  1698,  1699,
    1700,  1701,  1702,  1703,  1704,  1705,     0,     0,  1706,  1707,
    1708,  1709,  1710,  1711,  1712,  1713,  1714,     0,  1715,  1716,
    1717,  1718,  1111,  1719,  1720,  1721,  1722,  1723,  1724,  1725,
    1726,  1727,  1728,  1729,  1730,  1731,  1732,  1733,  1734,  1735,
    1736,  1737,  1738,  1739,  1740,  1741,  1742,  1743,  1744,  1745,
    1746,  1747,  1748,  1749,  1750,  1751,  1752,  1753,  1754,     0,
    1755,  1756,  1757,  1758,  1759,  1760,     0,     0,  1761,  1762,
       0,  1763,  1764,  1765,  1766,  1767,  1768,  1769,  1770,  1771,
    1772,  1773,  1774,  1775,  1776,  1777,  1778,  1779,  1780,  1781,
    1782,  1783,  1784,  1785,  1786,  1787,  1788,     0,     0,  1789,
    1790,  1791,  1792,  1793,  1794,  1795,  1796,  1797,  1798,  1799,
    1800,  1801,  1802,  1803,  1804,  1805,  1806,  1807,  1808,  1809,
    1810,  1811,  1812,  1813,  1814,  1815,  1816,  1817,  1818,  1819,
    1820,  1821,  1822,  1823,  1824,  1825,  1826,  1827,  1828,  1829,
    1830,  1831,  1832,  1833,  1834,  1835,  1836,  1837,  1838,  1839,
    1840,  1841,  1842,  1843,  1844,  1845,  1846,  1847,  1848,  1849,
    1850, -2260,     0,     0,     0,  1851,  1852,  1853,  1854,  1855,
    1856,  1857,  1858,  1859,  1860,  1861,     0,     0, -2260, -2260,
   -2260,     0, -2260,     0, -2260, -2260,  1862,     0,     0,     0,
    1284,     0,     0,     0,  1863,     0,     0,     0,     0,  1864,
       0,     0,  1285,  1865,     0,     0,  1866,  1867,  1868,  1869,
       0,     0,  1870,  1871,     0,  1872,  1873,  1874,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1286,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0, -2260,
       0,     0,     0,     0,     0,     0,     0,     0,  3183,     0,
       0,  3184,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  3185,     0,     0, -2260,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  3186,  3187,     0,     0,     0,     0,     0,
       0,     0,     0, -2260,     0,     0,  3188,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0, -2260,     0, -2260,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  3189,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0, -2260,     0,
       0,     0,     0,     0,     0, -2260,     0, -2260,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0, -2260,     0,
       0,     0,     0, -2260,     0,     0,  3190,     0,     0,     0,
       0, -2260,     0,     0,     0, -2260,     0,     0,  3191,     0,
       0, -2260,     0,     0,     0, -2260, -2260, -2260, -2260,     0,
    3192,  3193,     0,     0,     0,     0,     0,     0,  3194,     0,
   -2260,  3195,     0,     0,     0,     0,     0,     0,     0,   293,
       0,     0,     0,     0,     0,     0,     0, -2260,     0,     0,
   -2260,     0, -2260,     0,     0,     0,     0,     0,     0, -2260,
       0,     1,     0,     0,     0,     2,     0,     0,   679,   680,
     681,     0, -2260,     0,     0,     0,   682,     0,     0,   683,
       0,     0, -2260,     0,     0,     0,   684,   685,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0, -2260, -2260,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0, -2260,     0,
       0,     0,     0,     0,     0,     0, -2260,     0,     0,     0,
   -2260,   686,   687,     0,     0,     0,   688,     0, -2260, -2260,
   -2260,     0,     0,     0,     0,     0,   689,   690,     0,   691,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   692,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     693,     0,     0,   694,   695,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   696,     0,
     697,   698,   699,     0,     0, -2260,     0,     0,     0,     0,
     700,   701,     0,   702,   703,   704, -2260,     0,     0,     0,
       0,   705,     0,     0,   706,     0,   707,   708,   709,     0,
       0,     0,     0,     0,   710,     0,   711,   712,     0,   713,
       0,   714,   715,     0,     0,   716,     0,     0,   717,   718,
     719,   720,   721,   722,     0,     0, -2260,   723,   724,   725,
       0,   726,     0,     0,     0,   727,     0,   728,   729,     0,
       0,     0,     0,   730,     0,     0,   731,     0,     0,   732,
       0,   733,     0,   734,     0,   735,     0,     0,     0,   736,
     737,     0,   738,   739,   740,     0,     0,   741,     0,   742,
     743,     0,   744,     0,     0,     0,     0,     0,     0,     0,
     745,   746,     0,     0,     0,     0,     0, -2260,     0,     0,
       0,     0,     0,   747,     0,     0,   748,   749,     0,     0,
     750,   751,     0,     0,   752,   753,     0,     0,     0,     0,
       0,     0,     0,   754,   755,   756,     0,   757,     0,     0,
       0,     0,     0, -2260,     0,     0,     0,   758,   759,   760,
       0,   761,     0,     0,     0,   762,   763,     0,     0,     0,
     764,     0,     0,     0,     0,     0,     0,     0,   765,     0,
       0,     0,     0,     0,     0,     0,   766,   767,   768,     0,
       0,     0,     0,     0,   769,   770,     0,     0,     0, -2260,
       0,     0,   771,     0,     0,   772,     0,     0,     0,   773,
     774,     0,     0, -2260, -2260, -2260, -2260, -2260, -2260, -2260,
     775, -2260, -2260,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   776, -2260,     0,
       0,     0,     0,     0,     0,   777,     0,     0,     0,     0,
       0,   778,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   779,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   780,     0,     0,     0,     0,     0,
     781,     0,   782,   783,     0,     0,     0,     0,     0,     0,
     784,     0,     0,     0,     0,     0,   456,   457,   458,     0,
     459,   460,   461,   462,   463,   464,   465,   466,   467,   468,
     469,   470,   471,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   785,
       0,     0,     0,   472,     0,     0,     0,     0,     0,     0,
     786,     0,     0,     0,     0,     0,     0,   787,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   788,   789,     0,     0,     0,   790,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   791,     0,
       0,     0,     0,     0,   792,   793,   794,   795,     0,     0,
       0,   796,     0,     0,     0,   797,     0,     0,     0,     0,
       0,     0,   798,   799,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   800,     0,   801,     0,     0,     0,     0,
     473,   474,   475,   476,   477,   478,   802,     0,   803,     0,
       0,   804,     0,     0,     0,     0,     0,   805,   479,   480,
     481,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   806,     0,     0,   807,     0,     0,     0,
       0,   808,     0,     0,   809,   810,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   811,
       0,     0,     0,     0,     0,     0,   812,   456,   457,   458,
       0,   459,   460,   461,   462,   463,   464,   465,   466,   467,
     468,   469,   470,   471,     0,     0,     0,     0,     0,   813,
     814,   815,   816,   817,   818,   819,     0,     0,   820,     0,
     821,     0,   822,     0,   472,   456,   457,   458,     0,   459,
     460,   461,   462,   463,   464,   465,   466,   467,   468,   469,
     470,   471,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   472,     0,     0,     0,     0,     0,   482,     0,
       0,   483,     0,     0,     0,     0,     0,     0,     0,   456,
     457,   458,     0,   459,   460,   461,   462,   463,   464,   465,
     466,   467,   468,   469,   470,   471,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   472,     0,     0,     0,
       0,   473,   474,   475,   476,   477,   478,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   479,
     480,   481,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   473,
     474,   475,   476,   477,   478,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   479,   480,   481,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   484,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   485,     0,     0,     0,
     486,   584,     0,   473,   474,   475,   476,   477,   478,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   479,   480,   481,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   456,   457,   458,   487,   459,   460,   461,
     462,   463,   464,   465,   466,   467,   468,   469,   470,   471,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   488,     0,     0,     0,     0,   482,
     472,     0,   483,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   489,   456,   457,   458,     0,   459,   460,   461,
     462,   463,   464,   465,   466,   467,   468,   469,   470,   471,
       0,     0,     0,     0,     0,     0,     0,   482,     0,     0,
     483,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     472,     0,     0,     0,     0,   456,   457,   458,     0,   459,
     460,   461,   462,   463,   464,   465,   466,   467,   468,   469,
     470,   471,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   482,   472,   490,   483,     0,     0,   473,   474,   475,
     476,   477,   478,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   479,   480,   481,     0,     0,
       0,     0,   484,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   485,     0,     0,
       0,   486,   596,     0,     0,     0,     0,   473,   474,   475,
     476,   477,   478,     0,     0,     0,     0,     0,     0,   491,
     484,     0,     0,     0,     0,   479,   480,   481,     0,     0,
       0,     0,     0,     0,     0,   485,     0,   487,     0,   486,
     606,     0,     0,     0,     0,     0,     0,     0,     0,   473,
     474,   475,   476,   477,   478,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   488,     0,   479,   480,   481,
       0,     0,     0,     0,   484,   487,     0,     0,     0,     0,
       0,     0,     0,   489,     0,     0,     0,     0,     0,   485,
       0,     0,     0,   486,   970,     0,     0,     0,     0,     0,
       0,     0,     0,   488,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   482,     0,     0,   483,     0,
       0,   489,     0,     0,     0,     0,   456,   457,   458,   487,
     459,   460,   461,   462,   463,   464,   465,   466,   467,   468,
     469,   470,   471,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   488,     0,     0,
       0,     0,     0,   472,   490,   482,     0,     0,   483,     0,
       0,     0,     0,     0,     0,   489,     0,     0,     0,   456,
     457,   458,     0,   459,   460,   461,   462,   463,   464,   465,
     466,   467,   468,   469,   470,   471,     0,     0,     0,     0,
       0,     0,   490,     0,     0,     0,     0,   482,     0,     0,
     483,     0,     0,     0,     0,     0,   472,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     491,     0,     0,     0,     0,     0,     0,     0,   484,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   485,     0,     0,   490,   486,   976,     0,
     473,   474,   475,   476,   477,   478,     0,     0,   491,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   479,   480,
     481,     0,     0,     0,     0,     0,     0,     0,   484,     0,
       0,     0,     0,   487,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   485,     0,     0,     0,   486,   977,     0,
       0,     0,     0,   473,   474,   475,   476,   477,   478,     0,
       0,   488,   491,     0,     0,     0,     0,     0,     0,     0,
     484,   479,   480,   481,     0,     0,     0,     0,     0,   489,
       0,     0,     0,   487,     0,   485,     0,     0,     0,   486,
     978,     0,     0,   456,   457,   458,     0,   459,   460,   461,
     462,   463,   464,   465,   466,   467,   468,   469,   470,   471,
       0,   488,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   487,     0,     0,     0,   489,
     472,   456,   457,   458,     0,   459,   460,   461,   462,   463,
     464,   465,   466,   467,   468,   469,   470,   471,     0,     0,
       0,     0,     0,   488,     0,     0,     0,     0,   482,     0,
     490,   483,     0,     0,     0,     0,     0,     0,   472,     0,
       0,   489,   456,   457,   458,     0,   459,   460,   461,   462,
     463,   464,   465,   466,   467,   468,   469,   470,   471,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   472,
     490,   482,     0,     0,   483,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   491,   473,   474,   475,
     476,   477,   478,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   479,   480,   481,     0,     0,
       0,     0,   490,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   473,   474,   475,   476,   477,
     478,     0,     0,     0,     0,     0,   491,     0,     0,     0,
       0,   484,     0,   479,   480,   481,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   485,     0,     0,     0,
     486,   979,     0,     0,     0,     0,   473,   474,   475,   476,
     477,   478,     0,     0,     0,     0,     0,     0,   491,     0,
       0,     0,     0,     0,   479,   480,   481,     0,     0,     0,
       0,     0,     0,     0,   484,     0,   487,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   485,
       0,     0,     0,   486,     0,     0,     0,     0,     0,     0,
       0,     0,   457,   458,   488,   459,   460,   461,   462,   463,
     464,   465,   466,   467,   468,   469,   470,   471,     0,     0,
       0,     0,   489,     0,     0,   482,     0,     0,   483,   487,
       0,     0,     0,     0,     0,     0,     0,     0,   472,     0,
       0,     0,   981,   459,   460,   461,   462,   463,   464,   465,
     466,   467,   468,   469,   470,   471,     0,   488,     0,     0,
       0,     0,     0,   482,     0,     0,   483,     0,     0,     0,
       0,     0,     0,     0,     0,   489,   472,     0,   461,   462,
     463,   464,   465,   466,   467,   468,   469,   470,   471,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   490,   482,     0,     0,   483,     0,   472,
    2668,     0,     0,     0,     0,     0,     0,     0,     0,  1278,
    1279,  1280,     0,     0,     0,   272,  1281,  1282,    33,     0,
       0,     0,     0,     0,     0,   473,   474,   475,   476,   477,
     478,     0,     0,     0,     0,     0,     0,     0,   484,     0,
       0,     0,     0,   479,   480,   481,   490,     0,     0,     0,
       0,     0,     0,   485,     0,     0,     0,   486,     0,   491,
       0,     0,     0,   473,   474,   475,   476,   477,   478,     0,
       0,     0,     0,     0,     0,     0,   484,     0,     0,     0,
       0,   479,   480,   481,     0,     0,     0,     0,     0,     0,
       0,   485,     0,   487,     0,   486,   473,   474,   475,   476,
     477,   478,     0,     0,  1283,     0,   982,     0,     0,     0,
       0,     0,   491,     0,   479,   480,   481,   484,     0,     0,
       0,   488,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   487,   485,     0,     0,     0,   486,     0,     0,   489,
       0,     0,     0,     0,   985,     0,     0,     0,     0,   462,
     463,   464,   465,   466,   467,   468,   469,   470,   471,   488,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   487,     0,     0,     0,     0,   489,     0,   472,
       0,     0,     0,   482,     0,     0,   483,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1278,  1279,  1280,     0,
     488,     0,   272,  1281,  1282,    33,     0,     0,     0,   463,
     464,   465,   466,   467,   468,   469,   470,   471,   489,     0,
     490,   482,     0,     0,   483,     0,     0,     0,     0,     0,
    1111,     0,     0,     0,     0,     0,     0,     0,   472,     0,
       0,   464,   465,   466,   467,   468,   469,   470,   471,     0,
       0,     0,     0,     0,   482,     0,     0,   483,   490,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   472,
       0,     0,     0,     0,     0,     0,   473,   474,   475,   476,
     477,   478,     0,     0,     0,     0,   491,     0,     0,     0,
       0,  1283,     0,     0,   479,   480,   481,     0,     0,   490,
       0,     0,     0,     0,     0,     0,   484,     0,     0,     0,
       0,     0,     0,     0,   465,   466,   467,   468,   469,   470,
     471,   485,     0,  1280,   491,   486,     0,   272,  1281,  1282,
      33,     0,     0,     0,  2669,   473,   474,   475,   476,   477,
     478,   472,     0,     0,   484,     0,     0,     0,     0,     0,
       0,     0,     0,   479,   480,   481,     0,     0,     0,   485,
       0,   487,     0,   486,     0,   491,   473,   474,   475,   476,
     477,   478,     0,     0,     0,     0,     0,   484,     0,     0,
       0,     0,     0,     0,   479,   480,   481,     0,     0,   488,
       0,     0,   485,     0,     0,     0,   486,     0,  1284,   487,
       0,     0,     0,     0,     0,     0,     0,   489,     0,     0,
    1285,     0,     0,     0,     0,     0,  1283,  1111,     0,     0,
     466,   467,   468,   469,   470,   471,     0,   488,     0,     0,
       0,     0,   487,     0,   482,  1286,     0,   483,   473,   474,
     475,   476,   477,   478,     0,   489,   472,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   479,   480,   481,     0,
     488,     0,     0,     0,     0,     0,  1287,     0,     0,  2670,
       0,     0,     0,     0,     0,     0,     0,     0,   489,     0,
       0,  2671,  1289,     0,     0,     0,     0,     0,   490,     0,
       0,     0,     0,   482,     0,     0,   483,     0,     0,     0,
       0,     0,     0,  1278,  1279,  1280,     0,     0,     0,   272,
    1281,  1282,    33,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1290,     0,   482,     0,   490,   483,     0,     0,
       0,     0,     0,     0,  1291,     0,     0,     0,     0,     0,
       0,     0,  1111,   473,   474,   475,   476,   477,   478,     0,
       0,     0,     0,     0,   491,     0,     0,   484,     0,   490,
       0,   479,   480,   481,     0,     0,     0,     0,     0,     0,
       0,     0,   485,     0,     0,  1292,   486,     0,     0,     0,
       0,     0,  1278,  1279,  1280,  1284,     0,     0,   272,  1281,
    1282,    33,   491,     0,     0,     0,   482,  1285,  1283,   483,
       0,     0,     0,     0,     0,     0,     0,     0,  1293,     0,
       0,     0,   487,     0,  1294,     0,   484,     0,     0,     0,
       0,     0,  1286,  1295,  1296,   491,  1297,     0,     0,     0,
       0,   485,     0,     0,     0,   486,     0,     0,  1298,  1299,
     488,     0,     0,     0,     0,     0,  1300,   484,     0,  1301,
       0,     0,     0,  1287,     0,     0,  1288,   293,   489,     0,
       0,     0,   485,     0,     0,     0,   486,     0,     0,  1289,
       0,   487,     0,     0,     0,     0,     0,  1283,     0,     0,
       0,     0,     0,     0,     0,  1278,  1279,  1280,     0,     0,
       0,   272,  1281,  1282,    33,     0,  1985,     0,     0,   488,
       0,   482,   487,     0,   483,     0,     0,     0,     0,  1290,
    1284,     0,     0,     0,     0,     0,     0,   489,     0,   484,
       0,  1291,  1285,     0,  1111,     0,     0,     0,     0,     0,
     488,     0,     0,     0,   485,  1278,  1279,  1280,   486,   490,
       0,   272,  1281,  1282,    33,     0,     0,  1286,   489,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1292,  3180,  3181,     0,     0,     0,     0,   272,
    1281,  1282,    33,     0,   487,     0,     0,     0,  1287,     0,
    1283,  1288,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1289,  1293,     0,     0,   490,     0,
       0,  1294,   488,  1111,     0,   491,     0,     0,     0,     0,
    1295,  1296,     0,  1297,     0,     0,     0,     0,     0,     0,
     489,     0,     0,     0,   484,  1298,  1299,     0,     0,   490,
    1283,     0,     0,  1300,  1290,     0,  1301,     0,     0,   485,
       0,     0,     0,   486,   293,     0,  1291,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  3182,     0,
       0,     0,     0,     0,   491,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   487,
       0,     0,     0,     0,     0,     0,     0,  1292,     0,     0,
       0,     0,  1284,     0,     0,   491,     0,     0,     0,     0,
       0,   490,     0,     0,  1285,     0,  1111,   488,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1293,     0,     0,     0,     0,   489,  1294,     0,     0,  1286,
     197,     0,     0,     0,   198,  1295,  1296,     0,  1297,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1298,  1299,     0,     0,     0,     0,  1111,     0,  1300,     0,
    1287,  1301,     0,  1288,     0,     0,     0,   491,     0,   293,
       0,  1284,     0,     0,     0,     0,  1289,     0,     0,     0,
       0,     0,     0,  1285,  1111,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   490,     0,  1286,     0,
     199,     0,     0,     0,     0,  2505,  1290,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   200,   201,  1291,     0,
       0,     0,     0,     0,     0,     0,   202,     0,     0,  1287,
       0,     0,  1288,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1289,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1292,
       0,     0,   491,     0,  1284,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1285,     0,     0,     0,
       0,     0,     0,     0,  3632,  1290,     0,     0,     0,     0,
       0,     0,  1293,     0,     0,     0,     0,  1291,  1294,     0,
       0,  1286,     0,     0,     0,     0,     0,  1295,  1296,     0,
    1297,     0,     0,     0,  1284,     0,     0,     0,     0,     0,
       0,     0,  1298,  1299,     0,     0,  1285,     0,     0,     0,
    1300,     0,  1287,  1301,     0,  1288,     0,     0,  1292,     0,
       0,   293,  1284,     0,     0,     0,     0,     0,  1289,     0,
       0,  2305,     0,     0,  1285,  2536,  2537,  2538,  2539,  2540,
    2541,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1293,     0,     0,     0,     0,     0,  1294,     0,  1286,
       0,     0,  1287,     0,     0,  1288,  1295,  1296,  1290,  1297,
       0,     0,     0,     0,     0,     0,     0,   203,  1289,     0,
    1291,  1298,  1299,     0,     0,     0,     0,     0,     0,  1300,
    3183,     0,  1301,  3184,     0,     0,     0,     0,     0,     0,
     293,     0,     0,     0,     0,     0,  3185,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   204,     0,  1290,     0,
       0,  1292,     0,     0,     0,     0,     0,     0,     0,     0,
    1291,     0,  2542,     0,     0,   205,   206,   207,   208,     0,
       0,     0,     0,     0,     0,     0,  3187,     0,     0,     0,
       0,     0,     0,   209,  1293,     0,     0,     0,  3188,     0,
    1294,     0,     0,     0,     0,     0,     0,     0,     0,  1295,
    1296,  1292,  1297,     0,     0,   210,     0,     0,     0,     0,
       0,     0,     0,     0,  1298,  1299,     0,   211,     0,     0,
       0,     0,  1300,     0,     0,  1301,     0,     0,   212,  3189,
       0,     0,     0,   293,  1293,     0,     0,     0,     0,     0,
    1294,     0,     0,     0,   213,     0,     0,     0,     0,  1295,
    1296,     0,  1297,     0,   214,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1298,  1299,     0,  3603,  3190,   215,
       0,     0,  1300,     0,     0,  1301,     0,     0,     0,     0,
    3191,     0,     0,   293,     0,     0,     0,     0,     0,     0,
       0,     0,  3192,  3193,     0,     0,     0,     0,     0,     0,
    3194,     0,     0,  3195,     0,     0,     0,     0,     0,   216,
       0,   293,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  3604,     0,     0,     0,     0,     0,
       0,     0,   217,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   218,     0,  3605,
       0,     0,     0,     0,   219,     0,     0,   220,  3606,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   221,     0,
       0,     0,   222,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  3607,     0,     0,  2543,
       0,   223,     0,     0,  3608,     0,     0,     0,     0,     0,
       0,     0,  2544,     0,     0,     0,     0,     0,     0,   224,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   225,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  2545,     0,     0,     0,     0,     0,
    2546,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  3609,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  2547,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  2548,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  2549,  2550,     0,     0,     0,     0,  2551,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  2552,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  2553,     0,     0,  2554,  2555,     0,     0,     0,  2556,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  2557,     0,     0,     0,
       0,     0,     0,     0,     0,  3610,     0,  2558
};

static const short yycheck[] =
{
       3,     4,     5,   394,   169,     8,  1048,   587,   995,  1166,
      45,   105,   652,   544,  1126,  1278,  1279,  1449,   792,  1366,
     259,   260,   188,  1161,  1141,  1359,    54,  1137,  1138,   636,
    1140,  2106,  1142,  1143,  1919,   257,   258,    40,   776,  1122,
     125,   594,   264,  2357,    69,   171,  2648,   570,  2340,    52,
    2342,    54,     5,  2303,  1391,    90,  1123,  2046,   686,   687,
      27,  2055,    65,   715,  1994,  1995,  1996,  1997,  2492,    72,
    1884,  1885,  2052,    76,  2424,   169,    79,    80,  2890,  2891,
    2892,    84,    85,    26,    27,    20,   794,    25,  2355,    27,
      27,   116,    27,    27,   188,    27,   724,    20,     5,   727,
    1985,   104,    25,   751,    27,   712,    19,    19,    19,   737,
       5,  2535,     5,   741,    26,     5,   723,   745,   121,    27,
    2227,   124,   147,     5,   752,     5,   129,    19,    24,   757,
      26,   759,    24,    25,    26,   261,  1248,   765,     5,   265,
     768,   267,     8,   269,   270,   271,    27,   775,  1215,     5,
     235,   236,   278,    27,   782,   320,   282,   283,   148,   111,
     812,   789,  1229,    24,  1313,    26,  1315,    24,    25,    26,
      27,   778,   800,    25,   781,    27,   804,  1219,     5,    19,
     808,    27,    25,   790,    27,    20,   814,   190,     5,   817,
      25,  2610,    27,    24,    25,    26,    27,    25,   223,    27,
     225,    45,    24,    25,    26,    27,  2351,  2352,  2353,    27,
     117,  2356,   119,     5,   121,     5,    24,    25,    26,    27,
      24,    25,    26,    25,    26,    27,   320,   111,     5,   232,
     324,    25,     5,    27,    30,   238,    27,     5,    34,   782,
     130,   131,    25,  2663,    27,  2665,    90,   250,    19,    24,
      25,    26,    27,   256,   257,   258,   259,   260,   186,     5,
      25,   264,    27,   136,   137,  2893,    19,    25,    27,    27,
    2281,   211,  2417,  2284,   199,    94,    95,    96,    97,    98,
       6,   279,  1148,  1149,  2239,   199,     9,    10,    57,    12,
      13,    14,    15,    16,    17,  2531,   239,   192,    26,   285,
     139,  2975,    27,     5,     5,   431,   102,     5,   434,   390,
     313,   314,   212,   109,    23,    10,   341,     5,     5,   395,
     323,     5,   347,  1406,   478,   451,   452,   453,   454,   114,
     456,   457,   458,   459,   460,   461,   462,   463,   464,   465,
     466,   467,   468,   469,   470,   471,   472,  2597,    27,   515,
     669,  2426,   382,     5,   576,   872,  2670,   483,   484,   155,
     156,    56,   488,   506,   490,   134,   135,   163,  1506,    26,
      27,     5,   594,   593,     5,   439,   401,   323,   478,   505,
     506,   507,   508,     5,  1122,     5,   512,   344,    27,     5,
       5,     5,     5,     5,   686,   687,   239,   342,   585,   691,
     692,     5,  2332,     5,   723,   505,  1448,   113,   239,   354,
    2628,   239,   704,   578,     5,   623,   223,   239,     6,     9,
      10,   515,    12,    13,    14,    15,    16,    17,     6,     5,
     441,   239,   724,    19,   695,   727,  2581,     5,   454,   103,
     104,   733,     5,     5,   664,   737,  2591,   634,   239,   741,
     441,   297,     0,   745,     5,   663,   239,   749,   750,     5,
     752,     5,     5,   755,   239,   757,   758,   759,     5,   133,
     134,   135,     5,   765,   478,  1183,   768,     5,  2696,    20,
       5,   239,   473,   775,   578,   651,    27,     5,    28,     5,
     782,   425,     5,    31,     5,   395,   323,   789,  1126,   485,
     761,   504,   506,    18,    19,    20,    21,    22,   800,   534,
     545,   546,   804,   320,     5,     5,   808,    29,   672,    27,
     477,     5,   814,   666,   293,   817,   400,     5,   441,   658,
     441,   561,     5,   323,   537,     5,   488,   540,   323,   585,
       5,  2686,   572,     5,   625,   548,     5,   769,   787,   788,
    2889,  2890,  2891,  2892,   400,     5,     5,   651,     5,     5,
     239,   663,   565,     5,   567,     5,   642,    18,    19,    20,
      21,    22,   575,   576,   283,     5,   579,   816,   301,     5,
     819,     5,   239,     5,   200,  2953,  2822,  2955,   634,   556,
    2958,   594,   187,   188,   212,     5,     5,   666,     5,    27,
       5,   441,     5,   434,  2615,   548,   604,     5,     5,   200,
     395,     5,    25,  2863,    27,  2429,     5,    30,  1246,  1247,
    1248,   417,   444,   688,  2579,   636,     5,     5,  1145,   510,
    1496,   332,  2924,   561,   332,  1152,   444,   589,   384,    23,
     444,   705,  1173,   434,   518,  2790,    23,    27,   573,    10,
    2964,    27,   642,   593,   439,   720,   721,   474,   601,   573,
     478,    18,    19,    20,    21,    22,   390,  3341,  1406,   615,
     441,   674,   518,   441,   608,   400,   679,   680,   681,   682,
     683,   684,   685,  2568,   478,   688,   689,   690,   441,   435,
     693,  3115,   695,  1273,  1274,   698,   586,   700,   421,   422,
    2034,   545,  1410,   534,  1247,   589,   709,   772,  2055,  3133,
     518,   301,  1352,   441,  1422,   441,   512,   720,   721,   478,
     600,   603,   424,   636,   636,   636,   663,   730,   636,  2718,
    2875,   437,   416,   736,   600,   658,   603,   593,  3088,   742,
     743,   744,  3092,  1266,  2738,   748,   713,  3039,   751,  3041,
     753,   754,  2859,   476,   460,   708,  2736,   664,   761,  3178,
     518,   764,  2194,  1411,  3031,   672,   769,   770,   663,   772,
     666,   664,   715,   776,   666,   713,   779,   395,   713,   713,
     623,   713,   785,   673,   787,   788,   474,   474,   615,   792,
     793,   794,  2129,  3395,  3061,   798,   636,   562,   801,   672,
    3219,   593,  3430,   806,   632,   666,   658,  3409,   604,   666,
     813,   630,   815,   816,   597,   818,   819,   501,   821,   822,
     597,  3241,   474,   658,   597,   615,   239,   441,   284,   441,
     615,   421,   422,   517,  1126,   666,  3648,   543,   502,   441,
     474,  3180,  3181,   474,   666,  3184,   685,   686,   687,   688,
     689,   441,   474,   441,   474,   441,   658,   983,   666,   474,
     986,   474,   666,   441,  1987,   441,   294,    30,   994,   995,
     474,    34,   285,   441,  1265,   404,   560,   439,   441,   307,
     603,  3026,  2577,  3028,   392,    27,   476,  3255,   684,   484,
     441,   666,   400,   401,   518,   441,   692,   441,   441,   283,
     669,   625,   526,  3204,   441,   478,   283,    25,   441,    27,
     695,   696,   697,   441,   294,   599,   441,   425,   294,   390,
     428,   706,   925,   441,   588,   441,   665,   307,   441,   635,
     441,   307,    27,   672,   409,  1542,   444,   298,  3540,   410,
     585,   647,   648,   441,   628,  3237,   669,  3239,  3240,   655,
     441,   441,   291,   637,  1246,  1247,  1248,   441,  2772,   474,
     213,   124,   215,   441,   409,   968,  3390,   631,   441,   709,
       5,   441,   441,   591,  1527,  3267,   441,   671,  1003,   441,
    1045,   409,   441,  1514,    25,   331,    27,   240,     0,   634,
     730,   441,   441,   406,   441,   441,   719,   720,   344,   441,
     694,   441,  1067,   743,    16,  1008,   624,  1010,   404,   506,
    3324,   441,   207,   603,    24,   441,    26,   441,  2135,   441,
    3165,   122,   123,   474,   125,   126,   127,   636,   412,   409,
    3175,   441,   441,   409,   441,   412,   441,   478,   441,  2122,
     548,     5,  1045,   441,   441,  1048,   506,   441,   523,   658,
     478,  3539,   441,   375,    14,  3543,  2403,   513,    26,    27,
    2407,  1064,   441,   441,  1067,   506,   319,   294,   569,   322,
    2193,   506,   485,   448,   375,   436,  3415,   438,   523,   669,
     307,   716,  3421,  3422,   441,  3424,  3425,  3426,  3427,    26,
      27,   344,  3184,   601,  3433,   523,   552,   239,   478,   672,
     608,   514,    25,  1106,    27,   740,   478,  3422,  1111,  3410,
    3411,   539,   307,    25,  2181,    27,   162,  3262,  3433,  1122,
      20,  3435,   285,   213,   225,   215,    25,    27,    27,   719,
     720,   477,   233,  1136,  1137,  1138,   368,  1140,   636,  1142,
    1143,    20,    27,   523,   239,  1148,  1149,   523,    27,  3399,
     345,   786,    28,    29,   625,  2267,  2305,   632,    25,   539,
      27,   796,   478,   539,   799,   506,   267,   636,   803,   666,
    2865,  2866,   331,   190,   809,   276,   811,   194,  1181,  2166,
    1183,    25,   409,    27,  1423,   344,    25,   632,    27,  1192,
     473,    25,  1195,    27,   716,   717,   718,  1200,   239,    25,
     636,    27,   297,  1425,   305,   306,   528,  3546,    26,    27,
    3549,  3550,  3551,  3552,   409,   800,  1219,  1220,   478,   804,
    2369,  2370,   658,   808,   477,  1228,   478,   528,   423,   319,
     506,   666,   322,   386,    25,   968,    27,   255,   256,   257,
     478,  1244,  1245,   406,   397,     5,  3528,  3529,     8,   350,
     294,   216,   540,    25,   344,    27,  3248,  3402,   633,  3251,
     548,   636,  3254,   307,    25,   671,    27,  1270,   478,   154,
    1355,   239,  1437,  1358,    19,  1278,  1279,   478,   295,    24,
      25,    26,  3167,  1522,  1523,  1288,   478,   693,   694,   478,
      20,   454,   434,   394,   447,   636,   523,    27,  1301,   528,
    3639,   692,   239,    20,  3596,  1527,  1309,    20,   461,  3648,
      27,   478,   539,   704,    27,    26,   239,   658,   477,   204,
     478,  1386,   485,  3415,    20,   666,   478,   239,   523,  3421,
    1395,    27,  3424,  3425,  3426,  3427,  3618,    25,  3620,    27,
     239,    19,   733,  1437,   539,    20,    24,   448,    26,   671,
    3495,   514,    27,  1381,   239,  1420,   241,  1360,   749,   750,
     506,  1364,  1365,  1366,   755,   409,   478,   758,   690,   691,
     671,   671,   239,  1376,  1377,  1378,  2710,  2515,  1381,  1382,
    1383,  1384,  1385,  1386,  2122,   478,   674,   477,   710,   690,
     691,  2738,  1395,   693,   694,   239,   815,   550,  2353,   818,
     239,  2356,   821,  1406,  1407,   239,  1409,  1410,  1411,   710,
      25,    26,  2454,   239,   416,  1418,  1419,  1420,   478,  1422,
    1423,   239,  1425,  1426,   478,  1060,    58,    59,    60,    61,
     448,  1434,  1146,  1147,   478,   287,  1150,  1151,  1441,  1442,
     478,   287,   671,    18,    19,  1448,  1449,   478,   239,    24,
      25,    26,    27,   338,  3546,   478,  2164,  3549,  3550,  3551,
    3552,   690,   691,  2237,   429,   505,   506,   239,  2075,  3461,
      25,  2583,    27,   685,   505,   506,   688,   689,   443,   523,
     213,   710,   215,  2111,  3414,   759,  3416,  3417,  3418,  3419,
    1493,  1494,   344,  1496,   768,   539,   478,  2609,   344,   501,
    2649,   478,  2651,  2155,  2653,   478,   287,   240,   478,  2889,
    2890,  2891,  2892,    26,    25,   517,    27,  1520,    26,  1522,
    1523,   486,   407,  2231,  1527,  3600,  1529,   478,  1531,  1532,
     415,  1166,   497,   478,   419,   505,   506,   568,   113,  1174,
     814,  1176,  3617,   817,   150,   151,   398,  3639,   478,   181,
     402,  1554,   398,   518,   478,  1288,   402,   189,   560,    24,
     525,    26,   416,   344,   478,    25,   198,    27,   533,   201,
     455,   686,   687,   674,   675,   676,   677,   678,   679,   680,
     681,   682,   683,    25,   478,    27,   319,   416,   478,   322,
     555,   478,  3667,   158,   159,   160,   110,   599,   568,    25,
     478,    27,   727,    24,   478,    26,  2234,   672,    25,  3684,
      27,   344,   244,    25,   672,    27,   741,   398,  2149,   251,
     745,   402,    25,   666,    27,   477,   628,  1293,    26,  1295,
    1296,   477,   757,   505,   506,   637,   521,   688,   689,  2267,
     416,    26,  1881,  1882,  1407,    26,  1409,   501,   659,   660,
     661,   662,   416,    40,    41,    42,    26,    44,   573,    46,
      47,    25,    26,   517,   239,    25,    26,   632,   695,   696,
     416,   185,   501,   638,  2831,   560,   308,   336,   337,  3111,
     416,   478,  2799,  2728,  2729,  3180,  3181,  2754,   517,  2952,
    2953,   478,  2955,   478,   478,  2958,   477,   714,   715,   584,
    2408,   333,  2410,   695,   696,   478,   560,   486,   340,   478,
     342,  2419,   478,   478,    26,  2295,   478,  2855,   497,   468,
     352,    26,   478,   185,  3071,   501,   506,    26,    26,  2796,
      26,   560,    26,   247,    26,   249,  2444,   501,    26,   518,
     666,   517,   107,   628,   477,   599,   525,   441,   380,   478,
     411,   265,   637,   517,   533,   501,   388,   666,    26,   273,
     441,     5,   478,   277,   478,   501,  2889,  2890,  2891,  2892,
     599,   517,   474,   478,   628,   441,   555,  1412,  1413,  1414,
     518,   517,    20,   637,   560,   247,  3218,   249,   302,   441,
     441,   441,   478,   425,  1429,   812,   560,  2404,    20,   628,
    3180,  3181,   672,   265,  3184,   822,    20,    21,   637,   478,
     478,   273,   441,     5,   560,   277,   478,   449,    26,  2111,
    2807,   506,   670,   599,   560,   666,   288,    26,  2815,  2816,
     441,   441,   407,   307,   474,   599,   721,   722,   411,    30,
     302,    20,    26,  1908,   419,  1910,  1911,   636,  2455,  1914,
    1915,    26,   628,   599,   486,  1920,    18,    19,    20,    21,
      22,   637,  1497,   599,   628,   497,  1951,    26,    26,   444,
      26,    26,    26,   637,    26,   441,    26,  1880,  1881,  1882,
    1515,   441,   628,   441,  1887,  1888,    26,   441,   441,  2128,
       5,   637,   628,   441,  2020,    20,    26,  2504,  1533,   478,
     475,   637,    26,   478,  1907,  1908,    26,  1910,  1911,  1544,
      26,  1914,  1915,   666,  1917,   441,   491,  1920,     5,   441,
     672,    26,   441,   351,   209,   441,   140,   141,   142,   143,
     144,   145,   319,   670,   441,   322,  2001,   324,   441,   224,
     225,  1944,  2234,   518,  2029,   441,     5,   441,   233,  2577,
     441,   968,  1955,   478,   672,  2583,   531,   344,   441,    26,
     636,   441,  3394,   595,   596,   597,   672,   354,   543,    25,
      18,    19,    20,    21,    25,  2267,   608,   441,    20,    21,
      25,  2609,   267,   441,  1987,    25,  1989,  2226,   375,  2211,
    2212,   276,  3255,   441,   441,   441,  1999,  2000,  2001,   351,
    2025,  2004,   441,  2006,  2007,  2008,  2009,   441,   441,   584,
     441,   398,   441,   670,   441,   402,  2019,   441,   441,   666,
     305,   478,  2148,    18,    19,    20,    21,   666,     8,   671,
     474,  1048,   315,   526,   642,  3415,   507,     5,  2041,   664,
    2166,  3421,  3422,  2046,  3424,  3425,  3426,  3427,   623,  2052,
    2758,   185,  2055,  3433,   642,   664,  2121,  3180,  3181,   468,
     635,  3184,   507,   666,   705,   350,   506,   705,   377,   658,
    2073,   666,   647,   648,   643,     5,  2079,   468,  3120,   711,
     655,     5,   478,   658,   478,  2793,   478,   395,   478,   478,
     477,   666,   140,   141,   142,   143,   144,   145,   140,   141,
     142,   143,   144,   145,  2107,   636,     8,   625,    14,   394,
     622,     5,   705,   247,     5,   249,   478,   468,  2121,  2122,
     705,   478,  2125,  2126,   114,  2128,  3249,   970,    26,  3252,
     973,   265,   975,   976,   977,   978,   979,  3124,    26,   273,
    2143,   139,   666,   277,    26,   140,   141,   142,   143,   144,
     145,   506,   478,   478,   636,   478,   478,   478,   478,  2162,
     478,  2164,   478,   478,   478,   468,  3546,   506,   302,  3549,
    3550,  3551,  3552,    26,     5,   642,   478,   478,     5,   708,
    2245,   478,  2185,   672,  2187,  2188,   672,  2190,   478,   401,
    2193,  2194,   671,   603,     5,   663,    18,    26,    19,   202,
      26,   433,  1219,   669,   636,    25,   625,  3345,  2211,  2212,
     529,   666,   529,     5,   593,   200,  3354,   593,    26,   448,
     593,   372,    26,  2226,   441,   478,   441,   518,  2231,  2232,
    2233,   672,   441,  3371,  2237,     9,   666,  2865,  2866,   573,
     441,   478,  2245,   478,    18,    19,    20,   672,   478,   106,
      24,    25,    26,    27,  1987,   478,  1989,  2322,   478,  3639,
       5,  1278,  1279,   441,   666,   636,  1999,  2000,  3648,  2272,
     636,  1288,  2437,  2006,  2007,  2008,  2009,  2280,  2281,   663,
     666,  2284,   593,   478,   672,  2577,     5,     5,   710,     5,
    3413,  2583,  3415,   626,     5,   672,   530,   666,  3421,  3422,
    2303,  3424,  3425,  3426,  3427,   478,     5,     8,   671,  2312,
    3433,    26,  2315,  2316,  2317,  2318,  2319,  2609,    26,  2322,
     114,   368,  3434,  2326,  2327,   267,   376,  2330,  2980,  2981,
    2982,     5,  2984,  2985,  2986,  2987,  2988,  2989,     5,   113,
     441,  2993,   478,  2437,   410,   478,    14,   706,  2351,  2352,
    2353,  2416,   597,  2356,  2357,  2358,   643,   593,  2361,   672,
       5,    26,   148,     5,   478,   672,   666,   478,   593,    26,
    3078,   474,   441,   441,     5,   685,   671,   441,   671,  3517,
       5,     5,   418,   672,   665,   382,    26,  2390,   474,  2392,
    2393,   508,  2395,  2396,   478,   508,  2399,   478,  3106,   478,
    2403,   478,   478,   478,  2407,  2408,   478,  2410,   478,     5,
     666,     5,   666,  2416,  2417,     8,  2419,  2420,   506,   666,
    2423,  2424,     5,  3546,   600,   623,  3549,  3550,  3551,  3552,
     376,  1448,   395,    25,   395,   506,   395,   478,   666,   410,
     473,  2444,     5,  2078,   506,     5,   697,    26,  2451,     5,
       5,  2454,    25,    14,    26,  3578,    14,  2190,  2093,   642,
    2463,   642,   478,   663,  2467,   239,     5,     5,    25,   600,
     478,   441,    26,    26,    26,    26,   672,   441,     6,   441,
       7,   441,   495,   441,  3526,  2120,   441,   317,   441,  2492,
    3628,   441,  2127,  3603,  3604,  3605,  3606,  3607,  3608,     5,
     666,  2566,    26,    26,   672,    26,    26,    26,   441,   666,
      20,     5,     5,  2516,   613,     5,  3639,   666,   323,  2154,
     593,     5,     8,     5,   714,  3648,   441,   618,   666,   441,
    2595,   478,   518,   672,     5,   593,     5,   672,  2173,   260,
     441,   670,   478,    26,   672,   672,  2611,   478,     5,   672,
       5,   672,   670,    25,   494,    25,   665,    25,    25,    25,
     345,    26,    26,  2566,    26,    26,    26,    26,   441,   343,
    2303,   441,    26,  2865,  2866,     5,   441,   441,  2581,  2312,
     515,   478,  2315,  2316,  2317,  2318,  2589,  2590,  2591,     5,
     441,  2594,  2595,  2628,  2597,   478,   597,     8,  2663,   289,
    2665,    26,    25,   474,   441,   395,    20,  2610,  2611,   112,
     488,  2614,  2615,   191,     5,   478,   600,   478,   478,   478,
     478,     5,    40,  2845,  2789,  2847,   478,    14,  3268,   478,
     260,    26,  3619,   407,    26,   441,    26,    26,   441,   489,
    3348,     5,   441,    26,   506,   419,    26,    26,   441,    26,
     441,    26,  2655,   478,    26,   424,    26,   441,  3366,   615,
    2663,  2696,  2665,   289,  2830,  2668,   441,  2670,   441,   226,
     444,   478,   395,   441,   290,   488,  2802,   593,  2681,   441,
     478,  2807,   506,  2686,  2687,  2688,   104,   105,    14,  2815,
    2816,   441,   441,   441,     7,  2789,    26,  2700,   288,   288,
     441,   475,   441,   672,   478,   442,   478,   441,   622,   666,
     441,    26,   478,  3755,   636,  2718,   490,   491,    40,    41,
      42,   474,    44,    25,    46,    47,  2791,   441,   290,   441,
     506,   441,   441,  2736,   441,  2738,  2830,    26,     5,    26,
      26,   441,     5,   666,   518,   666,   474,    26,  2751,   441,
      26,   169,   441,  2733,   474,  2758,   666,   531,  2810,  2751,
    3677,   994,  2397,  1534,    29,    31,  2488,  2420,  2783,   543,
     188,  2426,  1256,  2174,   112,   352,  2411,  2412,  2413,  2414,
    2783,   116,  2785,   205,  2787,  2024,   655,  2790,  2791,   353,
    2793,  2025,   223,   343,   534,   210,   353,  2432,   553,  1277,
    3508,   597,   359,   360,   361,  2808,  3434,  2810,  2811,  2812,
     584,   382,   381,   565,  3667,  2078,   567,   986,   413,   798,
    2278,  2285,  2825,  2127,   381,  1880,  2413,  2834,  3145,  2832,
    1883,  2201,  2512,  1253,  3722,  3226,  2416,  3362,  2221,  1425,
      16,    90,  2845,   617,  2847,   348,    40,  3289,    40,   623,
      22,  2179,  2185,   927,  2857,  2858,  1545,  3096,   632,   633,
    2863,   635,   754,  2498,  2597,   368,   369,   370,   324,  1010,
    3109,  1888,  2875,   647,   648,  1888,  1494,  2188,  1220,  3286,
    3470,   655,  1419,   779,   658,  1492,  2889,  2890,  2891,  2892,
    2893,  2894,   666,  3684,  1409,   313,   314,  3020,  3480,  2832,
    2903,  1515,   320,  2154,   407,  2908,   324,   450,  3018,  2889,
    2890,  2891,  2892,  3002,  3076,  2699,   419,  3342,  3340,  3333,
    3068,   478,  2655,  2058,  2407,  3090,  2577,   430,  2041,   486,
    2361,  3693,   489,  3262,  1922,  1922,  2596,  2670,  2941,  2942,
     497,  2256,  3177,   446,  3495,  3025,  3059,  2244,  2681,  2952,
    2953,  2322,  2955,   456,  2941,  2958,  2668,  2960,  2942,  3252,
    3578,  2964,  3305,  3047,  2721,  2600,  1907,  2602,   471,  2700,
    1987,     8,  1989,  3742,  1249,   532,  2687,  3179,  2688,  2876,
    2000,  3260,  1999,  2000,  1999,  1902,  3536,  3052,  1245,  2006,
    2007,  2008,  2009,  2590,  3174,  3413,  3090,   319,  3124,  3432,
     322,  3004,   324,  2669,  1875,  2671,  3421,  1111,  2789,  2791,
     567,  2019,  2437,  1424,  3017,    -1,   519,   543,  1434,    -1,
      -1,    -1,   344,  3026,  3027,  3028,    -1,  1442,    -1,   586,
     587,    -1,   354,    -1,    25,    -1,    -1,    -1,  3330,    -1,
     597,    -1,    -1,    -1,    -1,   602,   549,    -1,  3340,  3052,
      -1,    -1,    -1,   375,    -1,    -1,   559,    -1,    -1,    -1,
      -1,  3064,  3065,    -1,    -1,  3068,    -1,    -1,  3071,    -1,
      -1,    -1,    -1,    -1,    -1,  3078,   398,   580,    -1,    -1,
     402,   584,    -1,    -1,   641,  3088,   504,    -1,  3091,  3092,
      -1,    -1,    -1,  3096,    -1,    -1,    -1,   515,    -1,  2832,
      -1,    -1,    -1,  3106,    -1,    -1,  3109,    -1,  3111,   612,
      -1,    -1,    -1,    -1,    -1,    -1,   673,  3120,   621,    -1,
      -1,    -1,  3344,    -1,    -1,    -1,    -1,    -1,    -1,  2764,
    2863,    -1,  2767,    -1,    -1,    -1,    -1,    -1,  2155,    -1,
      -1,    -1,  3434,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   477,  3159,    -1,    -1,    -1,
     578,    -1,  3165,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  3174,  3175,  2190,  3177,  3178,  3241,  3180,  3181,    -1,
      -1,  3184,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  3195,    -1,    -1,    -1,  2831,    -1,    -1,    -1,
    3180,  3181,    -1,    -1,  3184,    40,    41,    42,    -1,    44,
      -1,    46,    47,    -1,    -1,  3218,  3219,    -1,    -1,    -1,
      -1,    -1,    -1,  2889,  2890,  2891,  2892,  2960,    -1,    -1,
      -1,    -1,    -1,   651,    -1,   226,    -1,    -1,  3241,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  3249,    -1,    -1,  3252,
      -1,    -1,  3255,    -1,    -1,  3258,    -1,  3260,    -1,  3262,
      -1,   679,   680,   681,    -1,   683,    -1,    -1,    -1,  3249,
      -1,    -1,  3252,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   700,  3286,    -1,    -1,  2303,    -1,  2954,    -1,
    2956,    -1,    -1,    -1,    -1,  2312,    -1,    -1,  2315,  2316,
    2317,  2318,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    2327,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   736,    -1,
      -1,  3324,    -1,    -1,   742,    -1,   744,    -1,    -1,    -1,
     748,    -1,    -1,   751,    -1,    -1,   754,    -1,    -1,    -1,
    2357,  3344,    -1,    -1,    -1,  3348,   764,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   779,   353,  3366,    -1,    -1,  3532,   785,   359,   360,
     361,    -1,    -1,    -1,   792,   793,   794,    -1,    -1,    -1,
     798,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   806,    -1,
     381,  3394,    18,    19,    -1,    -1,  3399,    -1,    -1,  3402,
      26,    27,    -1,    -1,   822,    -1,    -1,    -1,    -1,    -1,
    3413,    -1,  3415,    -1,    -1,    -1,    -1,    -1,  3421,  3422,
      -1,  3424,  3425,  3426,  3427,    -1,    -1,  3430,    -1,  3432,
    3433,    -1,  3435,    -1,    -1,  3415,    -1,  2454,  3532,    -1,
      -1,  3421,  3422,    -1,  3424,  3425,  3426,  3427,    -1,    -1,
      -1,    -1,    -1,  3433,    -1,    -1,    -1,    -1,  1942,  1943,
      -1,    -1,    -1,    -1,  3099,  1949,    -1,  3470,    -1,    -1,
      -1,  3451,  3475,    -1,  3477,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   108,    -1,   319,    -1,    -1,   322,    -1,   324,
      -1,    -1,  3495,  3619,   120,   486,    -1,    -1,   489,    -1,
    3135,    20,    21,    22,    -1,  3508,   497,    -1,    -1,   344,
      -1,    -1,    -1,    -1,  3180,  3181,    -1,    -1,  3184,   354,
      -1,   147,    -1,  3526,    43,  3258,    -1,  3260,    -1,    -1,
      -1,    -1,    -1,  3536,    -1,    -1,    -1,    -1,    -1,  3542,
     375,   532,    -1,  3546,    -1,    -1,  3549,  3550,  3551,  3552,
      -1,  3554,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   398,    -1,  3568,  3546,   402,    -1,  3549,
    3550,  3551,  3552,    -1,    -1,  3578,   567,    -1,    -1,  3582,
    2597,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   586,   587,    -1,  3578,    -1,
    3603,  3604,  3605,  3606,  3607,  3608,   597,    -1,    -1,    -1,
      -1,   602,  3615,   239,    -1,   241,    -1,    -1,    -1,    -1,
      -1,   140,   141,   142,   143,   144,   145,    -1,    -1,    -1,
    1048,    -1,    -1,    -1,    -1,    -1,  3639,    -1,  2655,   158,
     159,   160,   477,    -1,    -1,  3648,  1064,    -1,    -1,    -1,
     641,  2668,    -1,  2670,    -1,    -1,    -1,    -1,    -1,  3639,
      -1,    -1,    -1,    -1,  2681,    -1,  3399,    -1,  3648,    -1,
      -1,    -1,    -1,  2157,    -1,    -1,    -1,    -1,    -1,    -1,
    3413,    -1,   673,    -1,    -1,    -1,    -1,    -1,  1106,    -1,
    3693,    -1,  3695,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   338,  2197,    -1,  3350,  2733,    -1,  1136,  1137,
    1138,    -1,  1140,    -1,  1142,  1143,    -1,    -1,    -1,    -1,
    1148,  1149,    -1,    -1,    -1,    -1,    -1,  3740,  3741,  3742,
     168,    -1,    -1,    -1,    -1,    -1,    -1,   373,    -1,  3415,
    3385,    -1,  3755,    -1,  3757,  3421,  3422,    -1,  3424,  3425,
    3426,  3427,    -1,    -1,    -1,  1183,    -1,  3433,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1195,    -1,   298,
      -1,   407,   301,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   419,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1219,  1220,    -1,    -1,    -1,    -1,    -1,    -1,  3542,
    1228,    -1,    -1,    -1,    -1,  2832,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1244,  1245,    -1,   455,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   270,    -1,   470,    -1,  2863,    -1,    -1,  3582,
     278,    -1,   478,    -1,    -1,    -1,   284,    -1,   286,    -1,
      -1,    -1,    -1,    -1,    -1,   491,    -1,    -1,    -1,   297,
      -1,    -1,  2889,  2890,  2891,  2892,    -1,    -1,    -1,    -1,
    3546,    -1,    -1,  3549,  3550,  3551,  3552,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   325,    -1,    -1,
      -1,    -1,   421,    -1,    -1,    -1,    -1,    -1,    -1,   535,
      -1,    -1,    -1,   341,    -1,    -1,    -1,   436,   346,    -1,
      -1,   440,    -1,    -1,  2941,  2942,    -1,    -1,    -1,    -1,
     358,    -1,    -1,    -1,   560,  2952,  2953,   365,  2955,    -1,
      -1,  2958,    -1,  2960,    -1,    -1,    -1,  2964,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   476,   584,    -1,
    3693,    -1,    -1,  2980,  2981,  2982,    -1,  2984,  2985,  2986,
    2987,  2988,  2989,  3639,    -1,    -1,  2993,    -1,    -1,  3614,
      -1,    -1,  3648,    -1,    -1,   504,    -1,    -1,    -1,  1407,
      -1,  1409,  1410,  1411,    -1,    -1,    -1,    -1,  2482,  2483,
    1418,  1419,   628,   522,  1422,    -1,    -1,    -1,  1426,  2493,
      -1,   637,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1437,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1448,  1449,    -1,  2517,  2518,  2519,  2520,  2521,  2522,    -1,
      -1,    -1,    -1,  2527,  2528,  2529,  2530,    -1,    -1,     9,
    2534,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    18,    19,
      -1,    -1,    -1,    -1,    24,    25,    26,    27,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1493,  1494,    -1,  1496,    -1,
      -1,    -1,  3717,    -1,   603,   513,    -1,    -1,    -1,    -1,
     518,    -1,    -1,    -1,    -1,   721,   722,   525,    -1,    -1,
      -1,    -1,    -1,  3120,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1529,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   547,
      -1,    -1,    -1,    -1,   552,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  2616,  2617,    -1,    -1,  1554,    -1,    -1,  2623,
    2624,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   108,    -1,
     669,    -1,    -1,   113,    -1,    -1,    -1,    -1,    -1,    -1,
     120,    -1,    -1,  3180,  3181,    -1,    -1,  3184,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    43,    -1,   147,    -1,    -1,
      -1,    -1,     5,     6,     7,     8,    -1,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      43,    -1,  3249,    -1,    -1,  3252,    -1,    -1,  3255,    -1,
      -1,  3258,    -1,  3260,    18,    19,    20,    -1,    -1,    -1,
      24,    25,    26,    27,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   239,
      -1,   241,   140,   141,   142,   143,   144,   145,    -1,  2773,
    2774,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2782,    -1,
     158,   159,   160,    -1,    -1,    -1,    -1,  3324,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   140,   141,   142,
     143,   144,   145,    -1,    -1,  2819,  2820,    -1,    -1,   113,
      -1,    -1,    -1,    -1,    -1,   158,   159,   160,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,     9,    -1,    -1,    -1,
      -1,    -1,  2846,    -1,  2848,    18,    19,    -1,    -1,    -1,
      -1,    24,    25,    26,    27,    -1,    -1,    -1,   338,    -1,
      -1,    -1,  3399,   343,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  3413,    -1,  3415,    -1,
      -1,    -1,    -1,    -1,  3421,  3422,    -1,  3424,  3425,  3426,
    3427,    -1,    -1,   373,    -1,    -1,  3433,    -1,  3435,    -1,
      -1,    -1,    -1,    -1,    -1,  2909,  2910,    -1,    -1,  2913,
    2914,    -1,    -1,    -1,  3451,    -1,    -1,    -1,    -1,    -1,
     298,    -1,    -1,   301,    -1,    -1,    -1,   407,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   108,    -1,    -1,    -1,   419,
     113,    -1,    -1,    -1,    -1,   239,    -1,   120,    -1,  1887,
    1888,    -1,    -1,    -1,    -1,    -1,    -1,   437,    -1,    -1,
      -1,    -1,   442,    -1,   444,   298,    -1,    -1,   301,    -1,
      -1,    -1,    -1,    -1,   147,   455,    -1,    -1,    -1,    -1,
     460,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  3526,
     470,    -1,    -1,    -1,    -1,   475,    -1,    -1,   478,    -1,
      -1,   481,    -1,    -1,  3008,  3542,  1944,    -1,    -1,  3546,
     490,   491,  3549,  3550,  3551,  3552,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  3578,    -1,   421,    -1,  3582,    -1,    -1,    -1,   343,
     530,   531,    -1,    -1,    -1,   535,    -1,    -1,   436,    -1,
      -1,    -1,   440,   543,    -1,    -1,   239,    -1,   241,    -1,
      -1,    -1,    -1,    -1,   554,    -1,    -1,    -1,    -1,    -1,
     560,    -1,    -1,    -1,    -1,  3089,    -1,    -1,   421,  3093,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   476,    -1,
      -1,    -1,  3639,   436,   584,    -1,    -1,   440,  3112,    -1,
      -1,  3648,    -1,   407,    -1,    -1,    -1,    24,    25,    26,
      27,    -1,    -1,    -1,    -1,   419,   504,  3131,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      -1,    -1,    -1,   476,   522,    -1,    -1,    -1,   628,    -1,
     444,    -1,    -1,    -1,    -1,   635,  3693,   637,    -1,    -1,
      43,    -1,    -1,    -1,    -1,   338,    -1,   647,   648,    -1,
     343,   504,    -1,    -1,    -1,   655,    -1,    -1,    -1,    -1,
      -1,   475,    -1,    -1,   478,    -1,   666,    -1,    -1,   522,
      -1,    -1,    -1,    -1,    -1,    -1,   490,   491,    -1,     9,
     373,    -1,    -1,    -1,    -1,  2143,   113,    -1,    18,    19,
      -1,    -1,    -1,    -1,    24,    25,    26,    27,  3755,    -1,
      -1,    -1,    -1,    -1,    -1,   603,  2164,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   407,    -1,    -1,   531,    -1,    -1,
      -1,   721,   722,    -1,    -1,    -1,   419,  2185,    -1,   543,
      -1,    -1,    -1,    -1,    -1,    -1,  2194,   140,   141,   142,
     143,   144,   145,    -1,   437,    -1,    -1,    -1,    -1,   442,
     603,   444,    -1,    -1,    -1,   158,   159,   160,    -1,    -1,
      -1,    -1,   455,    -1,    -1,    -1,    -1,   460,    -1,    -1,
     584,   669,    -1,  2231,  2232,  2233,    -1,   470,   108,  2237,
      -1,    -1,   475,   113,    -1,   478,    -1,    -1,   481,    -1,
     120,    -1,    -1,    -1,    -1,    -1,    -1,   490,   491,    -1,
      -1,    -1,    -1,   617,    -1,    -1,    -1,    -1,    -1,   623,
      -1,    -1,   239,    -1,  2272,    -1,   669,   147,   632,   633,
      -1,   635,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   647,   648,    -1,    -1,   530,   531,    -1,
      -1,   655,   535,    -1,   658,    -1,    -1,    -1,    -1,    -1,
     543,    -1,   666,    -1,    -1,    -1,    -1,    -1,    -1,  3383,
      -1,   554,  3386,    -1,    -1,    -1,    -1,   560,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   584,    -1,    -1,    -1,   298,    -1,    -1,   301,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   239,
      -1,   241,     9,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    18,    19,    -1,    -1,    -1,    -1,    24,    25,    26,
      27,    -1,    -1,    -1,    -1,   628,    -1,    -1,    -1,    -1,
      -1,    -1,   635,    -1,   637,    -1,    -1,    -1,    -1,    -1,
    2408,    -1,  2410,    -1,   647,   648,    -1,    -1,    -1,    -1,
      -1,  2419,   655,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   666,    -1,    -1,    -1,    -1,    -1,  2437,
     407,    -1,    -1,    -1,    -1,    -1,  2444,    -1,    -1,    -1,
      -1,    -1,   419,    -1,    -1,    -1,  2454,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  2463,  3530,    -1,   338,  2467,
      -1,   108,    -1,   343,    -1,    -1,   113,   444,   421,    -1,
      -1,    -1,    -1,   120,    -1,    -1,    -1,    -1,   721,   722,
      -1,    -1,    -1,   436,  2492,    -1,    -1,   440,    -1,    -1,
      -1,    -1,    -1,   373,    -1,    -1,    -1,    -1,   475,    -1,
     147,   478,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    3584,  3585,    -1,  3587,   491,  3589,  3590,    -1,    -1,    -1,
      -1,    -1,    -1,   476,    -1,    -1,    -1,   407,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   489,    -1,    -1,   419,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   504,    -1,    -1,   531,    -1,    -1,   437,    -1,    -1,
      -1,    -1,   442,    -1,   444,    -1,   543,    -1,    -1,   522,
      -1,    -1,    -1,    -1,    -1,   455,    -1,    -1,    -1,    -1,
     460,  3655,    -1,  3657,    -1,    -1,    -1,    -1,    -1,    -1,
     470,    -1,   239,    -1,   241,   475,    -1,    -1,   478,    -1,
      -1,   481,    -1,    -1,    -1,    -1,  2614,   584,    -1,    -1,
     490,   491,    -1,    -1,    -1,    -1,    -1,  3691,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  3711,  3712,    -1,
      -1,  3715,    -1,    -1,  3718,    -1,   623,    -1,    -1,    -1,
     603,   531,    -1,    -1,    -1,   535,    -1,    -1,   635,    -1,
      -1,    -1,    -1,   543,    -1,    -1,    -1,    -1,    -1,    -1,
     647,   648,    -1,    -1,   554,    -1,   556,    -1,   655,  2687,
     560,   658,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   666,
      -1,   338,     9,    -1,    -1,    -1,   343,    -1,    -1,    -1,
      -1,    18,    19,    -1,   584,    -1,    -1,    24,    25,    26,
      27,    -1,    -1,    -1,    -1,    -1,   669,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   373,     8,    -1,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    -1,    -1,    -1,    -1,     5,    -1,   628,    -1,
    2758,    -1,    -1,    -1,    -1,   635,    -1,   637,    -1,    -1,
     407,    -1,    43,    -1,    -1,    -1,    -1,   647,   648,    -1,
      -1,    -1,   419,    -1,    -1,   655,    -1,    -1,    -1,    -1,
      -1,  2789,    -1,    -1,    -1,  2793,   666,    -1,    -1,    -1,
     437,   108,    -1,    -1,    -1,   442,   113,   444,    -1,    -1,
    2808,    -1,  2810,   120,  2812,    -1,    -1,    -1,   455,    -1,
      -1,    -1,    -1,   460,    -1,    -1,    -1,  2825,    -1,    -1,
      -1,    -1,  2830,   470,    -1,    -1,    -1,    -1,   475,    -1,
     147,   478,    -1,    -1,   481,    -1,    -1,    -1,    -1,    -1,
      -1,   721,   722,   490,   491,    -1,    -1,    22,    -1,  2857,
    2858,    18,    19,    20,    21,    22,    -1,    -1,    -1,   140,
     141,   142,   143,   144,   145,    -1,    -1,    -1,    43,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    43,   158,   159,   160,
      -1,    -1,    -1,   530,   531,    -1,    -1,    -1,   535,    -1,
      -1,    -1,    -1,    -1,    -1,  2903,   543,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   554,    -1,    -1,
      -1,    -1,    -1,   560,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   239,    -1,   241,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   584,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   140,   141,   142,   143,   144,
     145,    -1,    -1,   140,   141,   142,   143,   144,   145,    -1,
      -1,   628,    -1,   158,   159,   160,    -1,    -1,   635,    -1,
     637,   158,   159,   160,    -1,    -1,  3004,    -1,    -1,    -1,
     647,   648,    -1,    -1,    -1,    -1,    -1,    -1,   655,  3017,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   298,    -1,   666,
     301,   338,    -1,    -1,    -1,    -1,   343,    -1,    -1,    -1,
       5,     6,     7,     8,    -1,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    -1,    -1,
     309,    -1,    -1,    -1,    -1,    -1,   373,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    43,    -1,
    3078,    -1,    -1,    -1,   721,   722,    -1,    -1,    -1,    -1,
      -1,    -1,  3090,    -1,    -1,    -1,    -1,    -1,    -1,   348,
     407,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  3106,    -1,
      -1,    -1,   419,  3111,    -1,    -1,    -1,    -1,   367,   368,
      -1,    -1,  3120,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     437,    -1,    -1,   298,    -1,   442,   301,   444,    -1,    -1,
      -1,   298,    -1,    -1,   301,    -1,    -1,    -1,   455,    -1,
     421,    -1,    -1,   460,    -1,    -1,    -1,    -1,   407,    -1,
      -1,    -1,    -1,   470,    -1,   436,    -1,    -1,   475,   440,
     419,   478,    -1,    -1,   481,   140,   141,   142,   143,   144,
     145,   430,    -1,   490,   491,    49,    50,    51,    52,    53,
      54,    -1,    -1,   158,   159,   160,    -1,   446,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   476,    -1,   456,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    3218,    -1,   471,    -1,   531,    -1,    -1,    -1,   535,    -1,
      -1,    -1,    -1,   504,    -1,    -1,   543,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   554,    -1,    -1,
      -1,   522,    -1,   560,    -1,    -1,   421,    -1,    -1,    -1,
      -1,    -1,   511,    -1,   421,    -1,   309,    -1,    -1,    -1,
      -1,   436,    -1,    -1,    -1,   440,    -1,   584,    -1,   436,
      -1,    -1,   146,   440,    -1,   534,    -1,    -1,  3286,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     549,    -1,    -1,    -1,    -1,   348,    -1,   556,    -1,    -1,
     559,   476,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   476,
      -1,   628,    -1,    -1,   367,   368,    -1,    -1,   635,    -1,
     637,   580,   603,   298,    -1,   584,   301,    -1,    -1,   504,
     647,   648,    -1,    -1,    -1,    -1,    -1,   504,   655,    -1,
    3348,    -1,    -1,    -1,   603,    -1,    -1,   522,    -1,   666,
      -1,    -1,    -1,    -1,   407,   522,    -1,    -1,  3366,    -1,
      -1,    -1,   621,    -1,    -1,    -1,   419,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   430,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  3394,    -1,   669,    -1,
      -1,    -1,    -1,   446,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   456,   721,   722,     5,     6,     7,     8,
       9,    10,    -1,    12,    13,    14,    -1,    -1,   471,    18,
      19,    20,    21,    22,    23,    -1,    -1,    -1,   603,    -1,
      -1,    -1,    -1,    -1,    33,    -1,   603,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   421,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    54,    -1,    -1,   511,    -1,
      -1,   436,  3470,    -1,    -1,   440,    -1,  3475,    -1,  3477,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   534,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   669,    -1,   549,    -1,    -1,    -1,
    3508,   476,   669,   556,    -1,    -1,   559,    -1,    -1,   383,
      -1,    -1,   111,    -1,    -1,    -1,    -1,    -1,  3526,    -1,
      -1,   120,   396,    -1,  3532,    -1,    -1,   580,    -1,   504,
      -1,   584,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   138,
     139,    -1,    -1,    -1,    -1,    -1,    -1,   522,   147,    -1,
     603,    -1,    -1,    -1,    -1,   154,   155,    -1,    -1,   158,
     159,   160,   161,    -1,    -1,   164,   165,    -1,   621,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   458,    -1,    -1,    -1,    -1,    -1,
     464,    -1,    -1,    -1,    -1,  3603,  3604,  3605,  3606,  3607,
    3608,    -1,    -1,    -1,    -1,   204,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   226,   603,   503,
      -1,    -1,    -1,   232,    -1,    -1,    -1,    -1,    -1,   238,
     239,    -1,   241,    -1,    -1,    -1,    -1,   246,    -1,    -1,
      -1,    -1,    -1,   527,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   537,   538,    -1,    -1,    -1,    -1,   543,
      -1,    -1,    -1,   272,    -1,    -1,    -1,    -1,    -1,   553,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   669,    -1,    -1,    -1,    -1,    -1,
      -1,   575,    -1,    -1,   578,   579,    -1,    -1,    -1,   583,
      -1,   310,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   323,    -1,    -1,    -1,    -1,    -1,
     329,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   338,
     339,    -1,    -1,    -1,    -1,    -1,   345,  3755,    -1,   348,
     349,    -1,    -1,    -1,   353,    -1,    -1,    -1,    -1,    -1,
     359,   360,    -1,    -1,    -1,    -1,   640,   366,   367,   368,
      -1,    -1,   371,   372,   373,    -1,    -1,   651,   377,    -1,
      -1,    -1,   381,    -1,   383,    -1,    -1,    -1,    -1,    -1,
      -1,   390,   391,   392,   393,    -1,   395,   396,    -1,    -1,
      -1,   400,   401,    -1,   403,   404,   405,   406,   407,   408,
     409,    -1,    -1,    -1,    -1,    -1,   415,   416,   417,    -1,
     419,   420,    -1,    -1,    -1,   424,   425,   426,   427,   428,
     429,   430,   431,    -1,   433,    -1,    -1,    -1,   437,   438,
     439,   440,   441,   442,   443,   444,   445,   446,   447,   448,
     449,   450,   451,   452,   453,   454,   455,   456,   457,   458,
     459,   460,   461,   462,   463,   464,   465,   466,   467,   468,
     469,   470,   471,   472,    -1,   474,   475,    -1,    -1,   478,
     479,   480,   481,   482,   483,   484,   485,   486,   487,    -1,
     489,   490,   491,   492,   493,   494,   495,   496,   497,   498,
     499,   500,   501,   502,   503,    -1,    -1,   506,   507,   508,
     509,   510,   511,   512,   513,   514,    -1,   516,   517,   518,
     519,    -1,   521,   522,   523,   524,   525,   526,   527,   528,
     529,   530,   531,   532,   533,   534,   535,   536,   537,   538,
     539,   540,   541,   542,   543,   544,   545,   546,   547,   548,
     549,   550,   551,   552,   553,   554,   555,   556,    -1,   558,
     559,   560,   561,   562,   563,    -1,    -1,   566,   567,    -1,
     569,   570,   571,   572,   573,   574,   575,   576,   577,   578,
     579,   580,   581,   582,   583,   584,   585,   586,   587,   588,
     589,   590,   591,   592,   593,   594,    -1,    -1,   597,   598,
     599,   600,   601,   602,   603,   604,   605,   606,   607,   608,
     609,   610,   611,   612,   613,   614,   615,   616,   617,   618,
     619,   620,   621,   622,   623,   624,   625,   626,   627,   628,
     629,   630,   631,   632,   633,   634,   635,   636,   637,   638,
     639,   640,   641,   642,   643,   644,   645,   646,   647,   648,
     649,   650,   651,   652,   653,   654,   655,   656,   657,   658,
      -1,    -1,    -1,    -1,   663,   664,   665,   666,   667,   668,
     669,   670,   671,   672,   673,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   684,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   692,    -1,    -1,    -1,    -1,   697,    -1,
      -1,    -1,   701,    -1,    -1,   704,   705,   706,   707,    -1,
      -1,   710,   711,    -1,   713,   714,   715,     5,     6,     7,
       8,     9,    10,    -1,    12,    13,    14,    -1,    -1,    -1,
      18,    19,    20,    21,    22,    23,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    33,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    54,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   111,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   120,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     138,   139,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   147,
      -1,    -1,    -1,    -1,    -1,    -1,   154,   155,    -1,    -1,
     158,   159,   160,   161,    -1,    -1,   164,   165,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   204,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   226,    -1,
      -1,    -1,    -1,    -1,   232,    -1,    -1,    -1,    -1,    -1,
      -1,   239,    -1,   241,    -1,    -1,    -1,    -1,   246,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   272,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    18,    19,    -1,    -1,    -1,    -1,    24,    25,    26,
      27,    -1,   310,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   323,    -1,    -1,    -1,    -1,
      -1,   329,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     338,   339,    -1,    -1,    -1,    -1,    -1,   345,    -1,    -1,
     348,   349,    -1,    -1,    -1,   353,    -1,    -1,    -1,    -1,
      -1,   359,   360,    -1,    -1,    -1,    -1,    -1,   366,   367,
     368,    -1,    -1,   371,   372,   373,    -1,    -1,    -1,   377,
      -1,    -1,    -1,   381,    -1,   383,    -1,    -1,    -1,    -1,
      -1,    -1,   390,   391,   392,   393,   113,   395,   396,    -1,
      -1,    -1,   400,   401,    -1,   403,   404,   405,   406,   407,
     408,   409,    -1,    -1,    -1,    -1,    -1,   415,   416,   417,
      -1,   419,   420,    -1,    -1,    -1,   424,   425,   426,   427,
     428,   429,   430,   431,    -1,   433,    -1,    -1,    -1,   437,
     438,   439,   440,   441,   442,   443,   444,   445,   446,   447,
     448,   449,   450,   451,   452,   453,   454,   455,   456,   457,
     458,   459,   460,   461,   462,   463,   464,   465,   466,   467,
     468,   469,   470,   471,   472,    -1,   474,   475,    -1,    -1,
     478,   479,   480,   481,   482,   483,   484,   485,   486,   487,
      -1,   489,   490,   491,   492,   493,   494,   495,   496,   497,
     498,   499,   500,   501,   502,   503,    -1,    -1,   506,   507,
     508,   509,   510,   511,   512,   513,   514,    -1,   516,   517,
     518,   519,   239,   521,   522,   523,   524,   525,   526,   527,
     528,   529,   530,   531,   532,   533,   534,   535,   536,   537,
     538,   539,   540,   541,   542,   543,   544,   545,   546,   547,
     548,   549,   550,   551,   552,   553,   554,   555,   556,    -1,
     558,   559,   560,   561,   562,   563,    -1,    -1,   566,   567,
      -1,   569,   570,   571,   572,   573,   574,   575,   576,   577,
     578,   579,   580,   581,   582,   583,   584,   585,   586,   587,
     588,   589,   590,   591,   592,   593,   594,    -1,    -1,   597,
     598,   599,   600,   601,   602,   603,   604,   605,   606,   607,
     608,   609,   610,   611,   612,   613,   614,   615,   616,   617,
     618,   619,   620,   621,   622,   623,   624,   625,   626,   627,
     628,   629,   630,   631,   632,   633,   634,   635,   636,   637,
     638,   639,   640,   641,   642,   643,   644,   645,   646,   647,
     648,   649,   650,   651,   652,   653,   654,   655,   656,   657,
     658,    23,    -1,    -1,    -1,   663,   664,   665,   666,   667,
     668,   669,   670,   671,   672,   673,    -1,    -1,    40,    41,
      42,    -1,    44,    -1,    46,    47,   684,    -1,    -1,    -1,
     407,    -1,    -1,    -1,   692,    -1,    -1,    -1,    -1,   697,
      -1,    -1,   419,   701,    -1,    -1,   704,   705,   706,   707,
      -1,    -1,   710,   711,    -1,   713,   714,   715,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   444,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   111,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   475,    -1,
      -1,   478,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   491,    -1,    -1,   139,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   530,   531,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   185,    -1,    -1,   543,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   213,    -1,   215,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   584,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   240,    -1,
      -1,    -1,    -1,    -1,    -1,   247,    -1,   249,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   260,    -1,
      -1,    -1,    -1,   265,    -1,    -1,   623,    -1,    -1,    -1,
      -1,   273,    -1,    -1,    -1,   277,    -1,    -1,   635,    -1,
      -1,   283,    -1,    -1,    -1,   287,   288,   289,   290,    -1,
     647,   648,    -1,    -1,    -1,    -1,    -1,    -1,   655,    -1,
     302,   658,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   666,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   319,    -1,    -1,
     322,    -1,   324,    -1,    -1,    -1,    -1,    -1,    -1,   331,
      -1,    30,    -1,    -1,    -1,    34,    -1,    -1,    37,    38,
      39,    -1,   344,    -1,    -1,    -1,    45,    -1,    -1,    48,
      -1,    -1,   354,    -1,    -1,    -1,    55,    56,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   375,   376,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   390,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   398,    -1,    -1,    -1,
     402,   100,   101,    -1,    -1,    -1,   105,    -1,   410,   411,
     412,    -1,    -1,    -1,    -1,    -1,   115,   116,    -1,   118,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   132,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     149,    -1,    -1,   152,   153,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   167,    -1,
     169,   170,   171,    -1,    -1,   477,    -1,    -1,    -1,    -1,
     179,   180,    -1,   182,   183,   184,   488,    -1,    -1,    -1,
      -1,   190,    -1,    -1,   193,    -1,   195,   196,   197,    -1,
      -1,    -1,    -1,    -1,   203,    -1,   205,   206,    -1,   208,
      -1,   210,   211,    -1,    -1,   214,    -1,    -1,   217,   218,
     219,   220,   221,   222,    -1,    -1,   528,   226,   227,   228,
      -1,   230,    -1,    -1,    -1,   234,    -1,   236,   237,    -1,
      -1,    -1,    -1,   242,    -1,    -1,   245,    -1,    -1,   248,
      -1,   250,    -1,   252,    -1,   254,    -1,    -1,    -1,   258,
     259,    -1,   261,   262,   263,    -1,    -1,   266,    -1,   268,
     269,    -1,   271,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     279,   280,    -1,    -1,    -1,    -1,    -1,   589,    -1,    -1,
      -1,    -1,    -1,   292,    -1,    -1,   295,   296,    -1,    -1,
     299,   300,    -1,    -1,   303,   304,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   312,   313,   314,    -1,   316,    -1,    -1,
      -1,    -1,    -1,   625,    -1,    -1,    -1,   326,   327,   328,
      -1,   330,    -1,    -1,    -1,   334,   335,    -1,    -1,    -1,
     339,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   347,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   355,   356,   357,    -1,
      -1,    -1,    -1,    -1,   363,   364,    -1,    -1,    -1,   671,
      -1,    -1,   371,    -1,    -1,   374,    -1,    -1,    -1,   378,
     379,    -1,    -1,   685,   686,   687,   688,   689,   690,   691,
     389,   693,   694,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   406,   710,    -1,
      -1,    -1,    -1,    -1,    -1,   414,    -1,    -1,    -1,    -1,
      -1,   420,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   431,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   443,    -1,    -1,    -1,    -1,    -1,
     449,    -1,   451,   452,    -1,    -1,    -1,    -1,    -1,    -1,
     459,    -1,    -1,    -1,    -1,    -1,     6,     7,     8,    -1,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   498,
      -1,    -1,    -1,    43,    -1,    -1,    -1,    -1,    -1,    -1,
     509,    -1,    -1,    -1,    -1,    -1,    -1,   516,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   540,   541,    -1,    -1,    -1,   545,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   557,    -1,
      -1,    -1,    -1,    -1,   563,   564,   565,   566,    -1,    -1,
      -1,   570,    -1,    -1,    -1,   574,    -1,    -1,    -1,    -1,
      -1,    -1,   581,   582,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   592,    -1,   594,    -1,    -1,    -1,    -1,
     140,   141,   142,   143,   144,   145,   605,    -1,   607,    -1,
      -1,   610,    -1,    -1,    -1,    -1,    -1,   616,   158,   159,
     160,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   642,    -1,    -1,   645,    -1,    -1,    -1,
      -1,   650,    -1,    -1,   653,   654,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   668,
      -1,    -1,    -1,    -1,    -1,    -1,   675,     6,     7,     8,
      -1,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    -1,    -1,    -1,    -1,    -1,   698,
     699,   700,   701,   702,   703,   704,    -1,    -1,   707,    -1,
     709,    -1,   711,    -1,    43,     6,     7,     8,    -1,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    43,    -1,    -1,    -1,    -1,    -1,   298,    -1,
      -1,   301,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     6,
       7,     8,    -1,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    43,    -1,    -1,    -1,
      -1,   140,   141,   142,   143,   144,   145,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   158,
     159,   160,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   140,
     141,   142,   143,   144,   145,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   158,   159,   160,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   421,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   436,    -1,    -1,    -1,
     440,   441,    -1,   140,   141,   142,   143,   144,   145,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   158,   159,   160,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,     6,     7,     8,   476,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   504,    -1,    -1,    -1,    -1,   298,
      43,    -1,   301,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   522,     6,     7,     8,    -1,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   298,    -1,    -1,
     301,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      43,    -1,    -1,    -1,    -1,     6,     7,     8,    -1,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   298,    43,   603,   301,    -1,    -1,   140,   141,   142,
     143,   144,   145,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   158,   159,   160,    -1,    -1,
      -1,    -1,   421,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   436,    -1,    -1,
      -1,   440,   441,    -1,    -1,    -1,    -1,   140,   141,   142,
     143,   144,   145,    -1,    -1,    -1,    -1,    -1,    -1,   669,
     421,    -1,    -1,    -1,    -1,   158,   159,   160,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   436,    -1,   476,    -1,   440,
     441,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   140,
     141,   142,   143,   144,   145,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   504,    -1,   158,   159,   160,
      -1,    -1,    -1,    -1,   421,   476,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   522,    -1,    -1,    -1,    -1,    -1,   436,
      -1,    -1,    -1,   440,   441,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   504,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   298,    -1,    -1,   301,    -1,
      -1,   522,    -1,    -1,    -1,    -1,     6,     7,     8,   476,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   504,    -1,    -1,
      -1,    -1,    -1,    43,   603,   298,    -1,    -1,   301,    -1,
      -1,    -1,    -1,    -1,    -1,   522,    -1,    -1,    -1,     6,
       7,     8,    -1,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    -1,    -1,    -1,    -1,
      -1,    -1,   603,    -1,    -1,    -1,    -1,   298,    -1,    -1,
     301,    -1,    -1,    -1,    -1,    -1,    43,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     669,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   421,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   436,    -1,    -1,   603,   440,   441,    -1,
     140,   141,   142,   143,   144,   145,    -1,    -1,   669,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   158,   159,
     160,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   421,    -1,
      -1,    -1,    -1,   476,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   436,    -1,    -1,    -1,   440,   441,    -1,
      -1,    -1,    -1,   140,   141,   142,   143,   144,   145,    -1,
      -1,   504,   669,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     421,   158,   159,   160,    -1,    -1,    -1,    -1,    -1,   522,
      -1,    -1,    -1,   476,    -1,   436,    -1,    -1,    -1,   440,
     441,    -1,    -1,     6,     7,     8,    -1,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      -1,   504,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   476,    -1,    -1,    -1,   522,
      43,     6,     7,     8,    -1,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    -1,    -1,
      -1,    -1,    -1,   504,    -1,    -1,    -1,    -1,   298,    -1,
     603,   301,    -1,    -1,    -1,    -1,    -1,    -1,    43,    -1,
      -1,   522,     6,     7,     8,    -1,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    43,
     603,   298,    -1,    -1,   301,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   669,   140,   141,   142,
     143,   144,   145,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   158,   159,   160,    -1,    -1,
      -1,    -1,   603,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   140,   141,   142,   143,   144,
     145,    -1,    -1,    -1,    -1,    -1,   669,    -1,    -1,    -1,
      -1,   421,    -1,   158,   159,   160,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   436,    -1,    -1,    -1,
     440,   441,    -1,    -1,    -1,    -1,   140,   141,   142,   143,
     144,   145,    -1,    -1,    -1,    -1,    -1,    -1,   669,    -1,
      -1,    -1,    -1,    -1,   158,   159,   160,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   421,    -1,   476,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   436,
      -1,    -1,    -1,   440,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,     7,     8,   504,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    -1,    -1,
      -1,    -1,   522,    -1,    -1,   298,    -1,    -1,   301,   476,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    43,    -1,
      -1,    -1,   489,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    -1,   504,    -1,    -1,
      -1,    -1,    -1,   298,    -1,    -1,   301,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   522,    43,    -1,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   603,   298,    -1,    -1,   301,    -1,    43,
       9,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    18,
      19,    20,    -1,    -1,    -1,    24,    25,    26,    27,    -1,
      -1,    -1,    -1,    -1,    -1,   140,   141,   142,   143,   144,
     145,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   421,    -1,
      -1,    -1,    -1,   158,   159,   160,   603,    -1,    -1,    -1,
      -1,    -1,    -1,   436,    -1,    -1,    -1,   440,    -1,   669,
      -1,    -1,    -1,   140,   141,   142,   143,   144,   145,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   421,    -1,    -1,    -1,
      -1,   158,   159,   160,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   436,    -1,   476,    -1,   440,   140,   141,   142,   143,
     144,   145,    -1,    -1,   113,    -1,   489,    -1,    -1,    -1,
      -1,    -1,   669,    -1,   158,   159,   160,   421,    -1,    -1,
      -1,   504,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   476,   436,    -1,    -1,    -1,   440,    -1,    -1,   522,
      -1,    -1,    -1,    -1,   489,    -1,    -1,    -1,    -1,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,   504,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   476,    -1,    -1,    -1,    -1,   522,    -1,    43,
      -1,    -1,    -1,   298,    -1,    -1,   301,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    18,    19,    20,    -1,
     504,    -1,    24,    25,    26,    27,    -1,    -1,    -1,    14,
      15,    16,    17,    18,    19,    20,    21,    22,   522,    -1,
     603,   298,    -1,    -1,   301,    -1,    -1,    -1,    -1,    -1,
     239,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    43,    -1,
      -1,    15,    16,    17,    18,    19,    20,    21,    22,    -1,
      -1,    -1,    -1,    -1,   298,    -1,    -1,   301,   603,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    43,
      -1,    -1,    -1,    -1,    -1,    -1,   140,   141,   142,   143,
     144,   145,    -1,    -1,    -1,    -1,   669,    -1,    -1,    -1,
      -1,   113,    -1,    -1,   158,   159,   160,    -1,    -1,   603,
      -1,    -1,    -1,    -1,    -1,    -1,   421,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    16,    17,    18,    19,    20,    21,
      22,   436,    -1,    20,   669,   440,    -1,    24,    25,    26,
      27,    -1,    -1,    -1,   343,   140,   141,   142,   143,   144,
     145,    43,    -1,    -1,   421,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   158,   159,   160,    -1,    -1,    -1,   436,
      -1,   476,    -1,   440,    -1,   669,   140,   141,   142,   143,
     144,   145,    -1,    -1,    -1,    -1,    -1,   421,    -1,    -1,
      -1,    -1,    -1,    -1,   158,   159,   160,    -1,    -1,   504,
      -1,    -1,   436,    -1,    -1,    -1,   440,    -1,   407,   476,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   522,    -1,    -1,
     419,    -1,    -1,    -1,    -1,    -1,   113,   239,    -1,    -1,
      17,    18,    19,    20,    21,    22,    -1,   504,    -1,    -1,
      -1,    -1,   476,    -1,   298,   444,    -1,   301,   140,   141,
     142,   143,   144,   145,    -1,   522,    43,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   158,   159,   160,    -1,
     504,    -1,    -1,    -1,    -1,    -1,   475,    -1,    -1,   478,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   522,    -1,
      -1,   490,   491,    -1,    -1,    -1,    -1,    -1,   603,    -1,
      -1,    -1,    -1,   298,    -1,    -1,   301,    -1,    -1,    -1,
      -1,    -1,    -1,    18,    19,    20,    -1,    -1,    -1,    24,
      25,    26,    27,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   531,    -1,   298,    -1,   603,   301,    -1,    -1,
      -1,    -1,    -1,    -1,   543,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   239,   140,   141,   142,   143,   144,   145,    -1,
      -1,    -1,    -1,    -1,   669,    -1,    -1,   421,    -1,   603,
      -1,   158,   159,   160,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   436,    -1,    -1,   584,   440,    -1,    -1,    -1,
      -1,    -1,    18,    19,    20,   407,    -1,    -1,    24,    25,
      26,    27,   669,    -1,    -1,    -1,   298,   419,   113,   301,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   617,    -1,
      -1,    -1,   476,    -1,   623,    -1,   421,    -1,    -1,    -1,
      -1,    -1,   444,   632,   633,   669,   635,    -1,    -1,    -1,
      -1,   436,    -1,    -1,    -1,   440,    -1,    -1,   647,   648,
     504,    -1,    -1,    -1,    -1,    -1,   655,   421,    -1,   658,
      -1,    -1,    -1,   475,    -1,    -1,   478,   666,   522,    -1,
      -1,    -1,   436,    -1,    -1,    -1,   440,    -1,    -1,   491,
      -1,   476,    -1,    -1,    -1,    -1,    -1,   113,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    18,    19,    20,    -1,    -1,
      -1,    24,    25,    26,    27,    -1,   518,    -1,    -1,   504,
      -1,   298,   476,    -1,   301,    -1,    -1,    -1,    -1,   531,
     407,    -1,    -1,    -1,    -1,    -1,    -1,   522,    -1,   421,
      -1,   543,   419,    -1,   239,    -1,    -1,    -1,    -1,    -1,
     504,    -1,    -1,    -1,   436,    18,    19,    20,   440,   603,
      -1,    24,    25,    26,    27,    -1,    -1,   444,   522,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   584,    18,    19,    -1,    -1,    -1,    -1,    24,
      25,    26,    27,    -1,   476,    -1,    -1,    -1,   475,    -1,
     113,   478,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   491,   617,    -1,    -1,   603,    -1,
      -1,   623,   504,   239,    -1,   669,    -1,    -1,    -1,    -1,
     632,   633,    -1,   635,    -1,    -1,    -1,    -1,    -1,    -1,
     522,    -1,    -1,    -1,   421,   647,   648,    -1,    -1,   603,
     113,    -1,    -1,   655,   531,    -1,   658,    -1,    -1,   436,
      -1,    -1,    -1,   440,   666,    -1,   543,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   113,    -1,
      -1,    -1,    -1,    -1,   669,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   476,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   584,    -1,    -1,
      -1,    -1,   407,    -1,    -1,   669,    -1,    -1,    -1,    -1,
      -1,   603,    -1,    -1,   419,    -1,   239,   504,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     617,    -1,    -1,    -1,    -1,   522,   623,    -1,    -1,   444,
      32,    -1,    -1,    -1,    36,   632,   633,    -1,   635,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     647,   648,    -1,    -1,    -1,    -1,   239,    -1,   655,    -1,
     475,   658,    -1,   478,    -1,    -1,    -1,   669,    -1,   666,
      -1,   407,    -1,    -1,    -1,    -1,   491,    -1,    -1,    -1,
      -1,    -1,    -1,   419,   239,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   603,    -1,   444,    -1,
     112,    -1,    -1,    -1,    -1,   530,   531,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   128,   129,   543,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   138,    -1,    -1,   475,
      -1,    -1,   478,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   491,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   584,
      -1,    -1,   669,    -1,   407,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   419,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   530,   531,    -1,    -1,    -1,    -1,
      -1,    -1,   617,    -1,    -1,    -1,    -1,   543,   623,    -1,
      -1,   444,    -1,    -1,    -1,    -1,    -1,   632,   633,    -1,
     635,    -1,    -1,    -1,   407,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   647,   648,    -1,    -1,   419,    -1,    -1,    -1,
     655,    -1,   475,   658,    -1,   478,    -1,    -1,   584,    -1,
      -1,   666,   407,    -1,    -1,    -1,    -1,    -1,   491,    -1,
      -1,   444,    -1,    -1,   419,    49,    50,    51,    52,    53,
      54,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   617,    -1,    -1,    -1,    -1,    -1,   623,    -1,   444,
      -1,    -1,   475,    -1,    -1,   478,   632,   633,   531,   635,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   309,   491,    -1,
     543,   647,   648,    -1,    -1,    -1,    -1,    -1,    -1,   655,
     475,    -1,   658,   478,    -1,    -1,    -1,    -1,    -1,    -1,
     666,    -1,    -1,    -1,    -1,    -1,   491,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   348,    -1,   531,    -1,
      -1,   584,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     543,    -1,   146,    -1,    -1,   367,   368,   369,   370,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   531,    -1,    -1,    -1,
      -1,    -1,    -1,   385,   617,    -1,    -1,    -1,   543,    -1,
     623,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   632,
     633,   584,   635,    -1,    -1,   407,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   647,   648,    -1,   419,    -1,    -1,
      -1,    -1,   655,    -1,    -1,   658,    -1,    -1,   430,   584,
      -1,    -1,    -1,   666,   617,    -1,    -1,    -1,    -1,    -1,
     623,    -1,    -1,    -1,   446,    -1,    -1,    -1,    -1,   632,
     633,    -1,   635,    -1,   456,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   647,   648,    -1,   251,   623,   471,
      -1,    -1,   655,    -1,    -1,   658,    -1,    -1,    -1,    -1,
     635,    -1,    -1,   666,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   647,   648,    -1,    -1,    -1,    -1,    -1,    -1,
     655,    -1,    -1,   658,    -1,    -1,    -1,    -1,    -1,   511,
      -1,   666,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   308,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   534,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   549,    -1,   333,
      -1,    -1,    -1,    -1,   556,    -1,    -1,   559,   342,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   580,    -1,
      -1,    -1,   584,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   380,    -1,    -1,   383,
      -1,   603,    -1,    -1,   388,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   396,    -1,    -1,    -1,    -1,    -1,    -1,   621,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   663,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   458,    -1,    -1,    -1,    -1,    -1,
     464,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   479,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   503,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   527,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   537,   538,    -1,    -1,    -1,    -1,   543,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   553,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   575,    -1,    -1,   578,   579,    -1,    -1,    -1,   583,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   640,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   649,    -1,   651
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const unsigned short yystos[] =
{
       0,    30,    34,   124,   285,   406,   454,   485,   514,   782,
     809,   810,   866,  1040,  1096,  1098,  1099,  1100,  1105,  1107,
    1120,  1121,  1122,  1123,  1124,  1566,    28,    29,   783,   784,
     785,   786,   787,    27,  1004,  1581,  1004,    25,  1004,  1471,
    1125,   811,  1471,   810,     0,  1097,  1100,  1123,    31,   785,
     787,   867,   658,    25,   239,   808,   809,   991,  1004,  1009,
    1105,  1120,  1126,  1161,  1162,  1163,  1164,  1165,  1169,   404,
     813,   814,   815,   816,   819,   820,   102,   109,   155,   156,
     163,   417,   512,   604,   684,   692,   782,   963,  1039,  1101,
    1102,  1104,  1108,  1109,  1115,  1127,  1148,  1280,  1290,  1566,
     663,  1004,  1164,   291,   505,   506,  1170,    20,  1004,  1168,
     666,   814,     5,   812,   404,  1004,     5,   838,   840,   841,
    1004,  1291,  1004,  1004,  1281,  1116,  1004,  1004,  1104,  1110,
     309,   348,   367,   368,   407,   419,   430,   446,   456,   471,
     511,   534,   549,   556,   559,   580,   584,   603,   621,   868,
     869,   870,   873,    25,  1161,  1167,    18,    19,    26,   108,
     120,   147,   241,   338,   373,   407,   419,   455,   470,   478,
     491,   535,   560,   584,   628,   637,   721,   722,   732,   734,
     928,   933,   944,   946,  1004,  1161,  1171,  1172,   506,    14,
     865,   816,   569,  1267,   817,   814,   819,    32,    36,   112,
     128,   129,   138,   309,   348,   367,   368,   369,   370,   385,
     407,   419,   430,   446,   456,   471,   511,   534,   549,   556,
     559,   580,   584,   603,   621,   663,   823,   832,   843,   848,
    1004,   478,   162,  1004,   808,   964,  1149,  1004,   875,   368,
     821,   478,   851,   853,   854,   852,   861,   862,   478,   478,
     874,   506,   478,   814,   849,   473,   478,   478,   478,   478,
     478,   478,   478,   478,   478,   478,   732,   478,   805,     9,
      18,    19,    24,    25,    26,   113,   343,   437,   442,   444,
     460,   475,   478,   481,   490,   531,   543,   554,   584,   635,
     647,   648,   655,   666,   902,   910,   911,   912,   913,   914,
     915,   916,   944,   945,   947,  1010,  1161,  1270,  1463,   478,
     478,   478,   478,   478,   478,    18,    19,    20,    21,    22,
     733,    26,   478,   568,     5,   474,  1171,    25,    26,  1004,
    1010,    19,    25,    26,   818,  1010,   716,   717,   718,   822,
     845,   834,   846,   821,   478,   478,   478,   835,   851,   852,
     478,   478,   833,   506,   844,   478,   849,   814,   842,   478,
      26,  1004,   478,  1117,   808,   808,   478,  1004,   478,   505,
     827,    26,   672,   416,   501,   517,   560,   599,   628,   637,
     855,   672,   416,   501,   517,   560,   599,   628,   637,   863,
      26,    26,   876,   877,   878,   879,  1004,    26,   830,   831,
      26,   666,   713,   952,   995,  1004,   995,   995,   952,   952,
     902,    25,    26,    19,    24,    25,    26,   948,   949,   950,
     951,    25,   953,   995,   996,   902,   441,   902,   902,   902,
     902,   573,  1287,   478,   478,   902,   416,   501,   517,   560,
     599,   628,   637,  1466,  1467,   478,   902,   902,   478,   478,
     917,   478,   478,   478,   478,    26,     6,     7,     8,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    43,   140,   141,   142,   143,   144,   145,   158,
     159,   160,   298,   301,   421,   436,   440,   476,   504,   522,
     603,   669,   804,   903,   918,   920,   921,   922,   923,   924,
     925,   926,    26,  1010,   468,   936,   934,   940,   938,  1161,
    1161,   732,   929,  1004,  1172,   506,   474,    26,   825,   478,
     847,   814,   847,   827,    26,    26,    26,   814,    26,    26,
     813,   830,   847,    26,   666,   107,   839,  1292,   441,   478,
    1282,  1582,  1583,  1584,  1585,  1586,   965,  1150,  1111,   666,
      26,   441,   856,   857,   478,   858,   863,   864,   858,   478,
     859,     5,   441,     5,   441,     5,   332,     5,   868,   474,
       5,     5,   441,   814,   850,   478,     5,   441,   506,   666,
     441,   441,   441,   441,   441,   441,    19,   441,   636,   949,
      19,    26,   636,   441,     5,   441,   441,     5,   806,   902,
     518,  1487,   902,   478,   672,    20,   441,  1487,    20,  1270,
     902,   902,   902,   902,   902,   902,   902,   902,   902,   902,
     902,   902,   902,   902,   902,   902,   902,   902,   902,   902,
     902,   902,   902,   478,   902,   902,   478,  1161,   902,   902,
     902,   902,   441,     5,   530,   762,   763,   764,   902,   478,
    1171,   506,   670,    26,   666,    26,   441,   441,     5,   441,
     307,     5,   441,     5,   441,   332,   474,     5,   441,   850,
    1004,  1177,  1178,  1180,  1128,  1177,   411,  1583,  1267,    37,
      38,    39,    45,    48,    55,    56,   100,   101,   105,   115,
     116,   118,   132,   149,   152,   153,   167,   169,   170,   171,
     179,   180,   182,   183,   184,   190,   193,   195,   196,   197,
     203,   205,   206,   208,   210,   211,   214,   217,   218,   219,
     220,   221,   222,   226,   227,   228,   230,   234,   236,   237,
     242,   245,   248,   250,   252,   254,   258,   259,   261,   262,
     263,   266,   268,   269,   271,   279,   280,   292,   295,   296,
     299,   300,   303,   304,   312,   313,   314,   316,   326,   327,
     328,   330,   334,   335,   339,   347,   355,   356,   357,   363,
     364,   371,   374,   378,   379,   389,   406,   414,   420,   431,
     443,   449,   451,   452,   459,   498,   509,   516,   540,   541,
     545,   557,   563,   564,   565,   566,   570,   574,   581,   582,
     592,   594,   605,   607,   610,   616,   642,   645,   650,   653,
     654,   668,   675,   698,   699,   700,   701,   702,   703,   704,
     707,   709,   711,   725,   726,   727,   728,   745,   767,   781,
     782,   788,   807,   881,   882,   883,   884,   895,   896,   897,
     898,   899,   900,   901,   954,   958,   989,  1011,  1013,  1016,
    1017,  1018,  1019,  1032,  1041,  1065,  1066,  1068,  1072,  1087,
    1088,  1092,  1093,  1094,  1095,  1103,  1118,  1131,  1142,  1143,
    1144,  1155,  1158,  1192,  1195,  1197,  1203,  1204,  1207,  1210,
    1213,  1215,  1217,  1220,  1227,  1232,  1236,  1237,  1238,  1250,
    1251,  1254,  1260,  1262,  1263,  1288,  1303,  1304,  1305,  1306,
    1307,  1319,  1325,  1326,  1346,  1349,  1378,  1380,  1472,  1473,
    1504,  1505,  1512,  1527,  1551,  1566,  1567,  1572,  1573,  1575,
    1579,  1580,  1587,   782,  1106,   671,   694,  1151,  1152,  1177,
      20,   441,   473,   828,   855,    26,   860,    26,    26,    26,
     877,   879,   871,   831,    26,  1004,   995,   732,    20,   713,
    1004,   942,  1467,    26,   942,    26,    26,   636,    24,    26,
     852,   943,   996,   853,   441,   409,   523,   632,  1495,   441,
     441,    26,  1467,   441,   441,   441,   441,   441,   441,   441,
     489,   489,   489,   927,  1487,   489,   927,  1487,   937,   935,
     941,   939,    26,   930,     5,   931,   474,  1171,   838,   441,
      20,   828,    26,   478,    26,    26,   824,    26,   666,   441,
       5,  1177,   441,  1161,  1161,  1161,  1004,    25,  1161,  1214,
    1004,    25,  1004,  1456,   400,  1005,  1006,  1581,  1005,    25,
    1004,  1455,  1004,  1004,  1234,   999,  1005,   999,  1004,  1577,
    1456,  1004,    26,   729,  1161,  1310,   999,  1234,   927,    26,
    1010,  1275,  1276,  1275,   902,   909,  1348,  1455,  1455,   904,
     927,  1005,  1513,  1513,   885,  1234,   999,  1308,  1161,  1001,
    1005,   909,  1513,  1161,  1234,  1161,  1347,  1513,    25,   632,
    1145,  1146,  1161,   999,   999,  1145,  1000,  1005,  1004,  1146,
     999,  1513,   999,  1001,  1456,  1161,  1190,  1191,   997,  1005,
    1001,   425,   608,   995,  1067,  1004,   789,  1455,  1002,  1005,
      25,   239,  1004,  1379,  1555,  1557,  1558,  1559,  1560,  1562,
     927,  1190,   672,   927,  1005,  1216,   959,    58,    59,    60,
      61,   181,   189,   198,   201,   244,   251,   308,   333,   340,
     342,   352,   380,   388,   425,   449,   486,   497,   595,   596,
     597,   608,   711,  1081,  1211,  1212,  1161,  1182,  1183,   908,
     909,  1226,   952,   952,   998,  1005,   927,  1214,  1289,  1161,
    1266,    25,  1161,  1507,  1261,   909,  1568,   154,   204,   241,
     338,   415,   455,   521,   746,   933,  1004,  1161,  1298,   769,
     909,   997,   636,  1004,  1012,  1132,   909,   997,    26,  1161,
    1089,   997,   909,  1528,   909,  1275,  1004,  1014,  1015,  1001,
    1014,   952,  1001,  1014,   952,  1020,  1014,    25,    26,   434,
     534,  1010,  1070,  1161,  1179,  1181,   114,   323,   395,   439,
     615,   695,   696,   697,   706,   736,  1022,  1024,  1026,  1028,
    1030,  1156,  1157,  1160,   386,   397,   447,   461,   550,  1381,
     686,   687,   967,   968,   969,  1004,  1153,   693,  1152,   441,
     351,   441,   441,   441,   441,   670,     5,   441,   441,   474,
     478,   672,    19,   441,   441,    26,   636,   672,    18,    19,
      20,    25,    26,   113,   407,   419,   444,   475,   478,   491,
     531,   543,   584,   617,   623,   632,   633,   635,   647,   648,
     655,   658,  1004,  1010,  1462,  1464,  1494,  1496,  1497,  1499,
    1500,  1501,  1523,  1524,  1525,  1526,  1556,  1557,  1561,  1287,
     441,  1287,  1287,  1287,  1287,  1287,  1287,    25,    25,    25,
     902,   919,   441,    25,   919,   441,   441,   441,   441,   441,
     441,   441,   764,   762,   474,   351,   441,   814,   836,   837,
     441,   441,   670,   441,  1004,  1293,  1180,   441,  1283,   103,
     104,   133,   134,   135,   502,   588,   631,  1327,  1328,  1329,
    1332,  1335,  1338,  1339,  1340,  1343,   666,   636,   658,   150,
     151,   478,   666,   636,   658,     8,   671,   474,  1455,   526,
    1235,  1179,   158,   159,   160,   642,   530,   905,   906,   909,
    1161,  1186,  1455,   735,   736,   888,   315,   136,   137,   672,
     507,     5,   665,   672,   664,   664,  1193,   642,   468,     5,
     603,  1042,   507,   705,  1570,   705,   434,   791,  1161,   593,
     664,  1198,  1199,  1200,   666,    25,  1558,   506,  1563,   377,
    1377,   658,   666,   907,   909,   603,  1555,   907,     8,   600,
     998,    26,   548,   601,   715,   990,  1161,   990,   990,   990,
      25,   226,   353,   359,   360,   361,   381,   486,   489,   497,
     532,   567,   586,   587,   597,   602,   641,   673,  1085,  1086,
     990,   990,   643,  1082,   736,  1082,  1082,   991,   991,  1082,
    1082,   736,     5,   468,     5,   384,   435,     5,   735,   130,
     131,   586,   673,  1073,   708,  1571,   908,   659,   660,   661,
     662,  1265,  1267,   909,  1256,  1257,  1258,  1268,  1269,   909,
     478,   478,   478,   478,    25,   765,  1004,   478,  1507,   395,
     478,   568,   636,   625,   770,   777,   768,  1004,    25,  1147,
    1161,  1252,     8,  1255,    14,  1004,  1166,  1173,  1174,  1176,
    1184,  1185,  1228,   212,   395,   591,   624,     5,     6,     7,
       8,     9,    10,    12,    13,    14,    18,    19,    20,    21,
      22,    23,    33,    54,   111,   120,   138,   139,   147,   154,
     155,   158,   159,   160,   161,   164,   165,   204,   226,   232,
     239,   241,   246,   272,   310,   323,   329,   338,   339,   345,
     348,   349,   353,   359,   360,   366,   367,   368,   371,   372,
     373,   377,   381,   383,   390,   391,   392,   393,   395,   396,
     400,   401,   403,   404,   405,   406,   407,   408,   409,   415,
     416,   417,   419,   420,   424,   425,   426,   427,   428,   429,
     430,   431,   433,   437,   438,   439,   440,   441,   442,   443,
     444,   445,   446,   447,   448,   449,   450,   451,   452,   453,
     454,   455,   456,   457,   458,   459,   460,   461,   462,   463,
     464,   465,   466,   467,   468,   469,   470,   471,   472,   474,
     475,   478,   479,   480,   481,   482,   483,   484,   485,   486,
     487,   489,   490,   491,   492,   493,   494,   495,   496,   497,
     498,   499,   500,   501,   502,   503,   506,   507,   508,   509,
     510,   511,   512,   513,   514,   516,   517,   518,   519,   521,
     522,   523,   524,   525,   526,   527,   528,   529,   530,   531,
     532,   533,   534,   535,   536,   537,   538,   539,   540,   541,
     542,   543,   544,   545,   546,   547,   548,   549,   550,   551,
     552,   553,   554,   555,   556,   558,   559,   560,   561,   562,
     563,   566,   567,   569,   570,   571,   572,   573,   574,   575,
     576,   577,   578,   579,   580,   581,   582,   583,   584,   585,
     586,   587,   588,   589,   590,   591,   592,   593,   594,   597,
     598,   599,   600,   601,   602,   603,   604,   605,   606,   607,
     608,   609,   610,   611,   612,   613,   614,   615,   616,   617,
     618,   619,   620,   621,   622,   623,   624,   625,   626,   627,
     628,   629,   630,   631,   632,   633,   634,   635,   636,   637,
     638,   639,   640,   641,   642,   643,   644,   645,   646,   647,
     648,   649,   650,   651,   652,   653,   654,   655,   656,   657,
     658,   663,   664,   665,   666,   667,   668,   669,   670,   671,
     672,   673,   684,   692,   697,   701,   704,   705,   706,   707,
     710,   711,   713,   714,   715,  1529,  1530,  1531,  1533,   622,
       5,   705,   705,   907,  1179,  1186,  1069,   468,     5,   200,
    1047,   478,  1161,   907,   478,    26,    26,   114,  1159,    25,
    1161,  1511,  1511,  1005,  1361,  1216,   998,   168,   270,   278,
     284,   286,   297,   325,   341,   346,   358,   365,   513,   518,
     525,   547,   552,  1350,  1351,  1359,  1368,  1369,  1375,  1376,
    1382,  1383,  1393,  1413,  1417,  1483,  1484,  1514,  1515,  1518,
    1519,  1535,   970,   971,   139,   966,   977,   978,   969,  1154,
    1582,  1112,   506,   868,   831,   666,  1004,   416,   501,   517,
     560,   599,   628,   637,  1468,    26,   942,   942,   636,    24,
      26,   856,  1500,  1500,   478,   478,   416,   501,   517,   560,
     599,   628,   637,  1465,  1469,   518,  1499,   478,   478,   478,
     478,  1494,  1494,  1494,   478,   478,   478,   478,  1004,   478,
       5,   593,  1422,  1427,   663,  1004,    18,    19,    20,    21,
     140,   141,   142,   143,   144,   145,  1521,  1469,  1469,   468,
       5,   441,   441,   932,   506,     5,   441,   838,   808,  1129,
     808,   294,   307,   409,   478,   523,   539,  1397,  1398,  1403,
    1405,   478,  1004,  1344,  1345,    26,   478,  1004,  1324,  1337,
    1405,  1407,   478,  1004,  1334,   478,  1324,  1330,     5,  1004,
      25,  1004,  1004,    25,  1007,  1164,  1004,    25,  1004,  1004,
    1004,  1578,  1455,   642,   478,   478,   888,  1455,     5,   672,
     478,  1555,    25,  1009,  1233,  1233,  1507,  1145,   909,   909,
     909,   992,   993,   478,  1161,  1191,  1043,  1044,  1045,  1455,
     672,  1507,   952,  1571,  1067,  1161,   790,   671,   909,   401,
    1202,   603,  1201,  1559,   732,  1564,  1565,  1004,    20,  1560,
       5,  1552,   663,  1208,   117,   119,   121,   664,   672,   880,
    1179,  1182,   960,    18,    19,   478,  1083,  1085,  1212,  1161,
    1183,   991,   909,   395,   642,    26,    26,   735,   202,  1264,
     433,  1302,  1267,  1258,     5,   664,  1259,  1569,  1004,    25,
     952,   952,   636,   996,   669,  1161,   750,  1004,  1004,   909,
     390,   773,   777,   625,   771,   779,    23,   283,  1134,  1138,
     529,   927,   529,  1253,   909,   505,  1170,   666,     5,  1090,
     593,  1229,  1161,  1532,  1534,   238,  1530,  1033,  1015,   952,
     952,  1025,  1026,  1047,  1047,    40,    41,    42,    44,    46,
      47,   319,   322,   324,   344,   354,   375,   398,   402,   477,
    1046,  1048,  1049,  1077,  1161,  1181,   593,   737,    26,   448,
    1031,   372,  1506,  1506,   187,   188,   484,   593,  1004,  1414,
    1415,  1457,  1455,  1455,  1455,  1352,  1455,  1455,  1004,  1516,
     216,   429,   443,   486,   497,   518,   525,   533,   555,   632,
     638,  1384,  1386,  1387,  1388,  1495,  1455,  1360,  1384,  1386,
    1582,  1582,   434,   979,  1161,   688,   689,   972,   973,   974,
     528,   671,   690,   691,   710,   982,   983,  1582,   808,    26,
     829,    20,  1004,   441,   478,   441,    24,    26,    25,    26,
      25,    26,   672,  1495,   441,   444,  1499,  1522,  1561,   409,
     523,   632,  1446,  1499,  1502,  1446,  1446,  1446,  1446,   666,
    1502,  1497,   562,  1423,  1424,  1425,  1455,   573,  1421,  1428,
     382,   561,   572,  1370,  1490,  1004,  1499,  1499,  1499,  1499,
     672,   478,   672,  1556,   902,   441,   829,   837,  1294,   808,
    1284,   478,   478,   478,  1341,  1405,   478,   478,   106,  1342,
    1344,     5,  1336,  1337,   112,   348,   368,   369,   370,   407,
     419,   430,   446,   456,   471,   519,   549,   559,   580,   584,
     612,   621,  1447,  1448,  1449,  1451,  1333,  1334,  1330,  1331,
     710,  1328,   666,   636,   441,   666,   636,   593,  1576,   478,
     730,   731,  1004,  1311,   927,   905,  1004,  1309,   663,  1205,
     672,     5,     5,     5,   626,   909,     5,   666,   530,   672,
     671,   213,   215,   319,   322,   792,   795,   796,  1077,   793,
     794,  1004,   478,  1005,   695,   696,  1206,     5,   474,   909,
    1455,  1553,  1554,  1555,   623,   663,  1209,  1004,  1004,   993,
     994,   556,   952,   888,     8,     8,   962,    26,    26,  1084,
    1085,  1161,   368,  1221,   114,   902,  1267,   267,  1269,  1275,
    1582,     5,     5,   441,   441,   766,  1004,   441,  1507,   762,
     478,   478,   778,   774,   410,   772,   909,   390,   775,   779,
     643,  1079,  1139,  1135,   412,  1133,  1134,   907,   672,  1167,
      20,  1004,  1175,  1185,    14,   530,  1230,  1231,  1499,  1561,
    1182,  1582,  1027,  1028,   597,  1003,   593,  1060,  1059,  1058,
    1057,  1062,  1061,   995,  1063,   995,  1064,  1056,  1055,  1053,
    1052,  1078,   375,  1049,  1054,   952,    49,    50,    51,    52,
      53,    54,   146,   383,   396,   458,   464,   503,   527,   537,
     538,   543,   553,   575,   578,   579,   583,   640,   651,   738,
     739,  1075,  1076,     5,    26,  1507,   297,  1161,   518,  1488,
    1489,  1507,  1216,  1482,  1484,   148,   148,   642,  1214,  1416,
    1417,   478,  1394,   199,  1428,  1455,   223,   320,  1520,   666,
     672,   478,  1389,  1389,   593,   671,     5,  1485,  1536,   392,
     401,   425,   428,   444,   548,   601,   608,   998,  1362,  1367,
     672,   671,   981,  1161,     5,   593,   975,   976,   685,   974,
     980,  1004,   980,   984,   985,   980,   375,   983,  1113,   474,
      26,   942,   441,    19,   441,   636,   441,    19,   441,   636,
     416,   501,   517,   560,   599,   628,   637,  1470,  1496,     5,
    1469,     5,   441,     5,  1499,     5,   441,  1499,  1499,  1499,
    1499,  1004,   441,   478,  1425,     5,  1004,  1461,     9,   343,
     478,   490,  1431,  1432,  1433,  1434,  1435,  1439,  1443,  1445,
    1499,   418,  1419,  1429,  1004,  1491,   665,  1446,   382,  1470,
      26,  1470,   474,   508,  1277,  1297,  1130,   508,  1239,  1271,
     658,  1004,  1400,  1402,  1455,  1459,  1460,  1404,  1459,  1404,
       5,   441,  1342,  1404,  1431,  1004,   441,  1345,     5,   441,
     478,   478,   478,  1469,  1469,   478,   478,   478,   478,   478,
     255,   256,   257,   448,  1406,  1408,     5,   441,     5,   441,
    1004,  1004,    25,  1004,  1004,    25,  1004,   909,  1004,  1321,
    1322,     5,  1323,  1324,   927,  1119,   666,  1323,   623,  1507,
    1507,   909,   909,   992,   556,   909,  1574,     5,  1044,    20,
    1459,  1507,   793,   801,   800,   802,  1004,  1008,   803,  1008,
     240,   796,   799,     5,  1047,   666,   909,     8,  1565,   506,
     666,     5,  1507,   623,  1004,  1179,   927,   600,  1365,     5,
     441,  1161,     5,    26,  1161,   376,    25,  1299,   395,   395,
     506,   666,   395,   478,   751,   755,   748,  1582,  1582,   780,
     776,   772,  1080,    25,  1003,  1140,  1161,  1582,   909,   473,
     506,   927,     5,  1034,  1029,  1030,    26,   735,  1004,  1582,
    1582,  1582,  1582,  1582,  1582,     5,  1050,     5,  1051,  1582,
    1582,  1582,  1582,  1083,  1582,  1003,    25,    14,    14,     5,
     441,    26,  1455,  1495,  1476,   642,   642,  1351,  1481,  1482,
    1417,  1395,  1459,   663,   998,   478,  1355,  1004,  1517,  1516,
    1390,  1459,   510,  1391,  1392,  1457,  1455,  1388,  1496,    94,
      95,    96,    97,    98,   630,  1539,   909,   909,   600,  1363,
     998,  1391,  1455,     5,  1161,   980,  1582,  1582,     5,   987,
     988,  1582,  1582,   986,  1106,   872,   441,    26,    26,    26,
      26,   478,  1427,  1469,   672,  1469,  1469,   441,  1499,   441,
     441,   441,   441,  1424,  1426,  1424,  1434,  1494,  1431,  1499,
    1494,     6,     7,     9,    10,    12,    13,    14,    15,    16,
      17,   301,   421,   422,   476,   603,   669,   719,   720,  1442,
    1444,  1420,  1498,  1499,   495,  1418,  1430,   317,  1320,    26,
    1371,  1372,  1373,  1459,  1488,  1491,   441,   826,   122,   123,
     125,   126,   127,   225,   233,   267,   276,   305,   306,   350,
     394,   448,   674,   675,   676,   677,   678,   679,   680,   681,
     682,   683,  1274,  1278,   186,   561,  1279,  1295,  1106,   209,
     224,   225,   233,   267,   276,   305,   350,   394,  1272,  1273,
    1285,  1279,  1460,   506,  1458,   441,     5,   666,     5,   441,
     441,  1405,   441,   441,  1337,    26,  1452,  1452,    26,   672,
     478,   672,    26,  1453,    26,    26,  1453,  1453,    25,  1462,
     207,   307,   345,   409,   423,   523,   539,  1399,  1409,  1410,
    1411,  1412,  1334,  1330,   666,   666,   585,   634,     5,   441,
     731,     5,   441,   907,   441,    20,   441,  1507,     5,   909,
     613,   323,   740,   741,   909,  1047,  1582,  1582,     5,   797,
     506,   666,     5,   798,  1582,   794,   593,    20,  1004,     5,
    1004,  1196,  1564,    20,  1459,  1554,     8,  1507,   439,   705,
     907,  1366,   961,  1085,   714,  1219,   902,     5,   762,  1161,
     747,   729,  1004,  1161,   753,   441,   762,   762,  1582,  1582,
    1083,  1137,    25,  1141,  1161,   618,   957,  1171,   530,   908,
    1091,  1231,   111,   589,  1035,  1021,  1022,   666,   995,  1582,
     995,  1582,   735,    26,  1161,    26,  1161,   739,   441,   478,
    1508,  1496,  1482,  1482,  1474,     5,   441,   518,  1493,  1356,
    1459,   526,  1353,  1493,   672,     5,   441,     5,   593,  1486,
      18,    19,   113,   475,   478,   491,   530,   531,   543,   584,
     623,   635,   647,   648,   655,   658,  1004,  1462,  1494,  1523,
    1525,  1544,  1545,  1546,  1547,  1548,  1549,  1561,  1544,  1544,
    1544,  1459,  1541,  1543,  1540,  1541,  1542,  1537,  1364,   672,
    1161,  1004,  1582,  1582,  1582,  1582,   670,    19,   441,   441,
     636,    19,   441,   441,   636,    26,   441,   672,  1470,   672,
     672,     5,   441,   441,  1432,  1433,  1437,  1500,  1437,   478,
    1494,  1437,   478,  1494,  1437,    10,   298,   436,   438,  1499,
       5,  1431,     5,   585,   634,  1374,  1320,   672,   670,  1275,
    1275,  1275,    25,  1275,  1275,  1275,  1275,  1275,  1275,    25,
      25,  1275,  1278,  1161,  1187,  1188,   665,   494,  1240,  1582,
      25,    25,    26,    26,    26,    26,    26,    25,  1161,  1273,
    1240,    26,  1399,  1459,    20,  1004,  1459,  1342,   441,   441,
       5,   441,  1470,    26,  1470,     5,  1450,     5,   441,   441,
     441,  1450,  1401,  1455,   478,  1411,  1342,  1004,  1004,  1322,
     669,   723,  1316,  1317,  1318,  1324,    57,   134,   135,   293,
     669,  1312,  1313,  1314,   515,   887,  1312,     5,   424,  1507,
       5,   478,   441,   597,  1074,  1008,  1582,   732,    20,  1004,
    1008,  1582,   952,   909,   474,  1507,     8,   952,  1182,  1582,
      26,  1003,    25,  1300,  1179,   474,   762,   752,   756,   441,
    1582,  1003,   909,   955,   474,  1037,  1036,   488,  1023,  1024,
      20,  1004,  1509,  1510,   600,  1492,  1477,  1475,  1459,  1495,
     191,  1396,     5,   441,  1354,  1517,  1459,  1392,  1391,  1492,
    1547,  1547,  1546,   478,   478,   478,   478,   478,   478,   478,
    1004,   478,     5,   441,    18,    19,    20,    21,  1521,   441,
       5,   441,     5,    14,   199,   573,  1538,  1182,  1391,   260,
    1114,   868,    26,    26,    26,    26,   441,  1470,  1470,  1470,
    1424,   489,  1436,  1436,  1440,  1441,  1462,  1561,  1436,  1440,
    1436,  1437,  1499,  1498,  1372,  1470,   838,   585,   634,  1189,
       5,  1187,   110,   185,   247,   249,   265,   273,   277,   302,
    1241,  1242,  1296,  1114,  1286,     5,   474,  1458,    26,   441,
      26,  1454,   441,    26,   441,   478,  1431,  1315,  1581,    26,
    1318,    26,    26,  1315,  1320,  1314,   995,   735,   424,  1507,
     909,   742,   615,  1194,    26,   735,   474,  1074,   441,  1507,
     289,   735,   441,   441,   478,   754,   395,   760,   441,   749,
    1136,  1582,   506,   909,  1582,  1003,     5,   441,  1182,  1427,
    1496,  1459,   478,  1427,   441,  1522,  1446,  1546,  1550,  1446,
    1446,  1446,  1446,   506,   666,  1550,  1545,  1546,  1546,  1546,
    1546,  1541,    14,  1542,  1545,   998,  1431,   192,   663,  1385,
      26,   441,   441,   441,   441,  1438,  1462,  1503,     5,   441,
     441,  1436,     7,  1188,  1243,  1244,  1161,  1246,  1161,  1245,
    1247,  1242,   288,   288,    26,   441,   672,   441,  1402,   441,
     886,  1507,   442,   251,   308,   333,   342,   380,   388,   479,
     649,   739,   743,   744,   478,   666,   735,  1218,  1301,   757,
     441,  1179,   760,   760,  1582,   956,  1171,   622,  1071,  1510,
    1490,  1427,   530,  1357,  1358,  1499,  1490,   441,  1546,     5,
     441,  1546,  1546,  1546,  1546,    26,  1004,   441,   478,  1004,
     636,  1441,  1499,  1582,  1582,  1248,  1582,  1249,  1582,  1582,
     474,  1470,   441,   287,   398,   402,   889,   890,   891,  1077,
     990,   990,   990,   990,   990,   990,    25,     5,   441,   909,
      20,  1004,  1077,  1222,  1223,  1224,   760,   762,   760,   290,
     474,  1038,   735,     5,   441,   336,   337,  1478,   441,  1546,
     441,   441,   441,   441,     5,   474,   506,  1544,    26,  1582,
    1582,   893,   892,   287,   891,   894,   744,     5,  1225,   331,
    1224,   758,  1582,  1358,    25,  1004,  1479,  1480,    26,    26,
     441,   441,   636,  1582,  1582,  1582,   909,  1582,   441,  1035,
     666,   666,     5,   474,     5,   474,    26,   441,   759,  1004,
    1004,  1480,    26,   441,   212,   395,   761,   666,   474,  1179,
    1004
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
#line 996 "fgl.yacc"
    { print_screen_mode(0);}
    break;

  case 3:
#line 999 "fgl.yacc"
    { print_screen_mode(1);}
    break;

  case 4:
#line 1003 "fgl.yacc"
    {
		print_start_server(yyvsp[-3].str,yyvsp[0].str);
	}
    break;

  case 5:
#line 1009 "fgl.yacc"
    {
	print_stop_external();
	}
    break;

  case 6:
#line 1014 "fgl.yacc"
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
#line 1026 "fgl.yacc"
    {
	sprintf(yyval.str,"%s%s",yyvsp[-2].str,yyvsp[0].str);
	}
    break;

  case 10:
#line 1031 "fgl.yacc"
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
#line 1054 "fgl.yacc"
    {sprintf(yyval.str,"(%s)",yyvsp[-1].str);}
    break;

  case 12:
#line 1055 "fgl.yacc"
    { sprintf(yyval.str,"%s%s%s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 13:
#line 1056 "fgl.yacc"
    {sprintf(yyval.str,"%d",atoi(yyvsp[0].str));}
    break;

  case 14:
#line 1057 "fgl.yacc"
    {sprintf(yyval.str,"(%s%s)",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 15:
#line 1058 "fgl.yacc"
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
#line 1069 "fgl.yacc"
    {
	sprintf(yyval.str,print_arr_expr_fcall(yyvsp[0].ptr));
}
    break;

  case 17:
#line 1075 "fgl.yacc"
    {strcpy(yyval.str,"+");}
    break;

  case 18:
#line 1076 "fgl.yacc"
    {strcpy(yyval.str,"-");}
    break;

  case 19:
#line 1077 "fgl.yacc"
    {strcpy(yyval.str,"*");}
    break;

  case 20:
#line 1078 "fgl.yacc"
    {strcpy(yyval.str,"/");}
    break;

  case 21:
#line 1079 "fgl.yacc"
    {strcpy(yyval.str,"%");}
    break;

  case 22:
#line 1084 "fgl.yacc"
    {strcpy(yyval.str,"+");}
    break;

  case 23:
#line 1085 "fgl.yacc"
    {strcpy(yyval.str,"-");}
    break;

  case 24:
#line 1096 "fgl.yacc"
    {
	 A4GL_debug("Using default attribute of WHITE");
		sprintf(yyval.str,"%d",0);}
    break;

  case 25:
#line 1099 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 26:
#line 1102 "fgl.yacc"
    {start_state("attribute",1);}
    break;

  case 27:
#line 1102 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[-1].str);
A4GL_debug("Got Attributes : %s",yyvsp[-1].str);
start_state("attribute",0);
}
    break;

  case 29:
#line 1109 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 30:
#line 1110 "fgl.yacc"
    {
sprintf(yyval.str,"%d",atoi(yyvsp[-2].str)|atoi(yyvsp[0].str));
}
    break;

  case 31:
#line 1116 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("BLACK"));}
    break;

  case 32:
#line 1117 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("BLUE"));}
    break;

  case 33:
#line 1118 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("CYAN"));}
    break;

  case 34:
#line 1119 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("GREEN"));}
    break;

  case 35:
#line 1120 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("MAGENTA"));}
    break;

  case 36:
#line 1121 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("RED"));}
    break;

  case 37:
#line 1122 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("WHITE"));}
    break;

  case 38:
#line 1123 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("YELLOW"));}
    break;

  case 39:
#line 1124 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("REVERSE"));}
    break;

  case 40:
#line 1125 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("BLINK"));}
    break;

  case 41:
#line 1126 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("UNDERLINE"));}
    break;

  case 42:
#line 1127 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("BOLD"));}
    break;

  case 43:
#line 1128 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("NORMAL"));}
    break;

  case 44:
#line 1129 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("INVISIBLE"));}
    break;

  case 45:
#line 1130 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("DIM"));}
    break;

  case 46:
#line 1131 "fgl.yacc"
    {inp_flags=inp_flags | 0x1; strcpy(yyval.str,"0");}
    break;

  case 47:
#line 1132 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 50:
#line 1139 "fgl.yacc"
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
#line 1150 "fgl.yacc"
    {start_state("attribute",0);strcpy(yyval.str,"");
}
    break;

  case 52:
#line 1154 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 53:
#line 1155 "fgl.yacc"
    {sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 54:
#line 1159 "fgl.yacc"
    { 
/*printf("Window attribute = %s\n",$<str>1);*/
form_attrib.attrib      =form_attrib.attrib|atoi(yyvsp[0].str);
/*printf("Window attribute = %d\n",form_attrib.attrib);*/
}
    break;

  case 55:
#line 1165 "fgl.yacc"
    { form_attrib.border      =1;}
    break;

  case 56:
#line 1167 "fgl.yacc"
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
#line 1178 "fgl.yacc"
    { form_attrib.comment_line=atoi(yyvsp[0].str); }
    break;

  case 58:
#line 1180 "fgl.yacc"
    { form_attrib.form_line   =atoi(yyvsp[0].str); }
    break;

  case 59:
#line 1182 "fgl.yacc"
    { form_attrib.error_line  =atoi(yyvsp[0].str); }
    break;

  case 60:
#line 1184 "fgl.yacc"
    { form_attrib.menu_line   =atoi(yyvsp[0].str); 
A4GL_debug("Set menu line to %s",yyvsp[0].str);
}
    break;

  case 61:
#line 1188 "fgl.yacc"
    { form_attrib.message_line=atoi(yyvsp[0].str); }
    break;

  case 62:
#line 1190 "fgl.yacc"
    { form_attrib.prompt_line =atoi(yyvsp[0].str); }
    break;

  case 63:
#line 1251 "fgl.yacc"
    {strcpy(yyval.str,"CALL");}
    break;

  case 64:
#line 1255 "fgl.yacc"
    { A4GL_debug("print_expr (3)"); 
		print_expr(yyvsp[-2].ptr);
		print_pop_variable(yyvsp[0].str);
	}
    break;

  case 65:
#line 1259 "fgl.yacc"
    {
        if (!isin_command("INPUT")&&!isin_command("CONSTRUCT")) {
                a4gl_yyerror("get_fldbuf can only be used in an input or construct");
                YYERROR;
        }
	print_getfldbuf(field_name_list_as_char(yyvsp[-2].field_list));
	}
    break;

  case 66:
#line 1266 "fgl.yacc"
    {
		print_returning();
	}
    break;

  case 67:
#line 1269 "fgl.yacc"
    {
	print_form_is_compiled(yyvsp[-5].str,yyvsp[-3].str,yyvsp[-1].str);
	}
    break;

  case 68:
#line 1273 "fgl.yacc"
    {
		print_field_func('I',field_name_as_char(yyvsp[-3].field_entry),yyvsp[0].str);
   }
    break;

  case 70:
#line 1277 "fgl.yacc"
    { 
        if (!isin_command("INPUT")&&!isin_command("CONSTRUCT")) {
                a4gl_yyerror("get_fldbuf can only be used in an input or construct");
                YYERROR;
        }
	print_field_func('T',field_name_list_as_char(yyvsp[-3].field_list),yyvsp[0].str);
   }
    break;

  case 71:
#line 1284 "fgl.yacc"
    {
	new_counter();
   	addmap("Call",yyvsp[-3].str,curr_func,yylineno,infilename);
   }
    break;

  case 72:
#line 1290 "fgl.yacc"
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
#line 1299 "fgl.yacc"
    {
	print_returning();
	/* strcpy($<str>$,$<str>5); */
   }
    break;

  case 74:
#line 1303 "fgl.yacc"
    {
	new_counter();
   	addmap("Call",yyvsp[-1].str,curr_func,yylineno,infilename);
   }
    break;

  case 75:
#line 1308 "fgl.yacc"
    {
 A4GL_debug("Got args");
   }
    break;

  case 76:
#line 1312 "fgl.yacc"
    {
	int a;
	dump_expr(yyvsp[-2].ptr);
	a=get_counter_val();
	drop_counter();
  	print_func_call(yyvsp[-5].str,yyvsp[-2].ptr,a);
   }
    break;

  case 77:
#line 1320 "fgl.yacc"
    {
	print_returning();
	/* strcpy($<str>$,$<str>5);  */
   }
    break;

  case 78:
#line 1324 "fgl.yacc"
    {
	A4GLSQL_set_status(0,0);
	new_counter();
	}
    break;

  case 79:
#line 1328 "fgl.yacc"
    {
   sprintf(yyval.str,"%d",get_counter_val());drop_counter();
}
    break;

  case 80:
#line 1330 "fgl.yacc"
    {
        print_expr ((struct expr_str *)yyvsp[-3].ptr);  
	print_call_shared(yyvsp[-6].str,yyvsp[-8].str,atoi(yyvsp[-2].str));
	print_returning();
	print_end_call_shared();
}
    break;

  case 81:
#line 1336 "fgl.yacc"
    {
	sprintf(yyval.str,"\"%s\",\"%s\"",yyvsp[-3].str,yyvsp[-1].str);
	A4GLSQL_set_status(0,0);
	new_counter();
	}
    break;

  case 82:
#line 1341 "fgl.yacc"
    {
   	sprintf(yyval.str,"%d",get_counter_val());drop_counter();
}
    break;

  case 83:
#line 1344 "fgl.yacc"
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
#line 1360 "fgl.yacc"
    {
   char buff[256];
   new_counter();
   sprintf(buff,"%s:%s(%p)",yyvsp[-6].str,yyvsp[-4].str,yyvsp[-2].str);
   addmap("External",buff,curr_func,yylineno,infilename);
   }
    break;

  case 85:
#line 1367 "fgl.yacc"
    {
   sprintf(yyval.str,"%d",get_counter_val());drop_counter();
   }
    break;

  case 86:
#line 1371 "fgl.yacc"
    {
	 A4GL_debug("print_expr (6)");print_expr(yyvsp[-2].ptr);
   }
    break;

  case 87:
#line 1375 "fgl.yacc"
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
#line 1397 "fgl.yacc"
    {start_bind('i',0);strcpy(yyval.str,"0");}
    break;

  case 89:
#line 1397 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);
}
    break;

  case 90:
#line 1401 "fgl.yacc"
    {start_bind('i',0);strcpy(yyval.str,"0");}
    break;

  case 91:
#line 1402 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 92:
#line 1403 "fgl.yacc"
    {strcpy(yyval.str,"WITHOUT WAITING"); }
    break;

  case 93:
#line 1408 "fgl.yacc"
    {
			yyval.ptr=A4GL_new_expr("");
		}
    break;

  case 94:
#line 1411 "fgl.yacc"
    {
			yyval.ptr=yyvsp[0].ptr;
		}
    break;

  case 95:
#line 1417 "fgl.yacc"
    {
	yyval.ptr=yyvsp[0].ptr;
}
    break;

  case 96:
#line 1420 "fgl.yacc"
    {
		yyval.ptr=A4GL_append_expr_expr(yyvsp[-2].ptr,yyvsp[0].ptr);
}
    break;

  case 98:
#line 1429 "fgl.yacc"
    {yyval.ptr=A4GL_new_expr("A4GL_push_null(2,0);");}
    break;

  case 100:
#line 1433 "fgl.yacc"
    {
sprintf(yyval.str,"\"%s\"",yyvsp[0].str);
}
    break;

  case 101:
#line 1439 "fgl.yacc"
    {
sprintf(yyval.str,"\"%s\"",yyvsp[0].str);
}
    break;

  case 102:
#line 1442 "fgl.yacc"
    { sprintf(yyval.str,"\"%s.%s\"",yyvsp[-2].str,yyvsp[0].str); }
    break;

  case 103:
#line 1457 "fgl.yacc"
    {
push_blockcommand("CASE");
setinc(1);
A4GL_incprint();
print_case(1);
setinc(1);
}
    break;

  case 104:
#line 1467 "fgl.yacc"
    {
print_after_when(0);
pop_blockcommand("CASE");
}
    break;

  case 105:
#line 1473 "fgl.yacc"
    {  push_blockcommand("CASE"); 
setinc(1);
A4GL_incprint(); 
print_case(0);
setinc(1);
}
    break;

  case 106:
#line 1482 "fgl.yacc"
    {
print_after_when(0);
pop_blockcommand("CASE");
}
    break;

  case 111:
#line 1495 "fgl.yacc"
    {setinc(-1);A4GL_incprint();}
    break;

  case 113:
#line 1498 "fgl.yacc"
    {
A4GL_incprint();
}
    break;

  case 114:
#line 1500 "fgl.yacc"
    {A4GL_incprint();
print_after_when(0);
}
    break;

  case 116:
#line 1506 "fgl.yacc"
    {A4GL_incprint();}
    break;

  case 117:
#line 1508 "fgl.yacc"
    {A4GL_incprint();
print_after_when(0);
}
    break;

  case 118:
#line 1513 "fgl.yacc"
    {
print_when(0);

A4GL_incprint();
}
    break;

  case 119:
#line 1518 "fgl.yacc"
    {A4GL_incprint();
print_after_when(1);
setinc(-1);}
    break;

  case 120:
#line 1524 "fgl.yacc"
    {
A4GL_incprint();
print_when(1);
}
    break;

  case 121:
#line 1528 "fgl.yacc"
    {A4GL_incprint();
print_after_when(1);
setinc(-1);}
    break;

  case 122:
#line 1543 "fgl.yacc"
    {
  print_close('F',yyvsp[0].str);
 }
    break;

  case 123:
#line 1546 "fgl.yacc"
    {
  print_close('W',yyvsp[0].str);
}
    break;

  case 124:
#line 1549 "fgl.yacc"
    {
  print_close('W',yyvsp[0].str);
}
    break;

  case 125:
#line 1552 "fgl.yacc"
    {
  print_close('D',0);
}
    break;

  case 126:
#line 1555 "fgl.yacc"
    {
  print_close('S',yyvsp[0].str);
}
    break;

  case 127:
#line 1558 "fgl.yacc"
    {
  print_close('C',yyvsp[0].str);
}
    break;

  case 133:
#line 1580 "fgl.yacc"
    {
			A4GL_lex_printc("%s",yyvsp[0].str);
}
    break;

  case 136:
#line 1589 "fgl.yacc"
    {
			A4GL_lex_printc("%s\n",yyvsp[0].str);
}
    break;

  case 137:
#line 1608 "fgl.yacc"
    {
push_blockcommand("CONSTRUCT");
A4GL_new_events();
}
    break;

  case 138:
#line 1613 "fgl.yacc"
    {
	print_construct_1();
}
    break;

  case 139:
#line 1616 "fgl.yacc"
    {
	print_construct_2(yyvsp[-2].str);
A4GL_drop_events();
}
    break;

  case 140:
#line 1625 "fgl.yacc"
    {
	print_construct_3(1,yyvsp[-5].str,0,yyvsp[0].str,atoi(yyvsp[0].str));
	strcpy(yyval.str,A4GL_get_formloop_str(0));
	reset_constr();
}
    break;

  case 141:
#line 1631 "fgl.yacc"
    {
	print_construct_3(0,yyvsp[-7].str,field_name_list_as_char(yyvsp[-2].field_list),yyvsp[0].str,atoi(yyvsp[0].str));
	strcpy(yyval.str,A4GL_get_formloop_str(0));
	reset_constr();
}
    break;

  case 146:
#line 1646 "fgl.yacc"
    {
                push_construct("",yyval.str);
             }
    break;

  case 147:
#line 1650 "fgl.yacc"
    {
                sprintf(yyval.str,"%s.%s",yyvsp[-2].str,yyvsp[0].str);
                push_construct(yyvsp[-2].str,yyvsp[0].str); 
             }
    break;

  case 148:
#line 1655 "fgl.yacc"
    {
                push_construct(yyvsp[-2].str,"*");
             }
    break;

  case 151:
#line 1665 "fgl.yacc"
    { A4GL_add_event(-97,field_name_list_as_or_char(yyvsp[0].field_list)); print_befaft_field_1(field_name_list_as_or_char(yyvsp[0].field_list)); }
    break;

  case 152:
#line 1665 "fgl.yacc"
    { print_befaft_field_2(); }
    break;

  case 153:
#line 1666 "fgl.yacc"
    { A4GL_add_event(-98,field_name_list_as_or_char(yyvsp[0].field_list)); print_befaft_field_1(field_name_list_as_or_char(yyvsp[0].field_list)); }
    break;

  case 154:
#line 1666 "fgl.yacc"
    { print_befaft_field_2(); }
    break;

  case 155:
#line 1667 "fgl.yacc"
    { A4GL_add_onkey_key(yyvsp[0].str); print_onkey_1(yyvsp[0].str); }
    break;

  case 156:
#line 1667 "fgl.yacc"
    { print_onkey_2(); }
    break;

  case 157:
#line 1668 "fgl.yacc"
    { A4GL_add_event(-95,""); print_befaft_field_1("AFTER_INP"); }
    break;

  case 158:
#line 1668 "fgl.yacc"
    { print_befaft_field_2(); }
    break;

  case 159:
#line 1669 "fgl.yacc"
    { A4GL_add_event(-99,""); print_befaft_field_1("BEFORE_INP"); }
    break;

  case 160:
#line 1669 "fgl.yacc"
    { print_befaft_field_2(); }
    break;

  case 161:
#line 1677 "fgl.yacc"
    {
			yyval.field_list=new_field_list();
			yyval.field_list=append_field_to_list(yyval.field_list,yyvsp[0].field_entry);
	}
    break;

  case 162:
#line 1681 "fgl.yacc"
    {
			yyval.field_list=append_field_to_list(yyvsp[-2].field_list,yyvsp[0].field_entry);
	}
    break;

  case 163:
#line 1687 "fgl.yacc"
    {
			yyval.field_list=new_field_list();
			yyval.field_list=append_field_to_list(yyval.field_list,yyvsp[0].field_entry);
	}
    break;

  case 164:
#line 1691 "fgl.yacc"
    {
			yyval.field_list=append_field_to_list(yyvsp[-2].field_list,yyvsp[0].field_entry);
	}
    break;

  case 165:
#line 1706 "fgl.yacc"
    {
        	yyval.ptr=A4GL_new_expr("A4GL_pushop(OP_YEAR);");
	}
    break;

  case 166:
#line 1709 "fgl.yacc"
    {
        	yyval.ptr=A4GL_new_expr("A4GL_pushop(OP_MONTH);");
	}
    break;

  case 167:
#line 1712 "fgl.yacc"
    {
        	yyval.ptr=A4GL_new_expr("A4GL_pushop(OP_DAY);");
	}
    break;

  case 168:
#line 1715 "fgl.yacc"
    {
        	yyval.ptr=A4GL_new_expr("A4GL_pushop(OP_HOUR);");
	}
    break;

  case 169:
#line 1718 "fgl.yacc"
    {
        	yyval.ptr=A4GL_new_expr("A4GL_pushop(OP_MINUTE);");
	}
    break;

  case 170:
#line 1721 "fgl.yacc"
    {
        	yyval.ptr=A4GL_new_expr("A4GL_pushop(OP_SECOND);");
	}
    break;

  case 171:
#line 1730 "fgl.yacc"
    {
			yyval.ptr=A4GL_append_expr_expr(yyvsp[-2].ptr,yyvsp[-1].ptr);
		}
    break;

  case 172:
#line 1738 "fgl.yacc"
    { 
	char buff[50];
	sprintf(buff,"A4GL_push_int(%d);",(19*16)+10); 
	yyval.ptr=A4GL_new_expr(buff);
}
    break;

  case 173:
#line 1743 "fgl.yacc"
    { 
	char buff[50];
	sprintf(buff,"A4GL_push_int(%d);",(atoi(yyvsp[-2].str)*16) +atoi(yyvsp[0].str)  ); 
	yyval.ptr=A4GL_new_expr(buff);
}
    break;

  case 174:
#line 1756 "fgl.yacc"
    {
				print_defer(0);
			}
    break;

  case 175:
#line 1760 "fgl.yacc"
    {
				print_defer(1);
			}
    break;

  case 176:
#line 1775 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 177:
#line 1776 "fgl.yacc"
    {strcpy(yyval.str,"");lastlineno=yylineno;}
    break;

  case 180:
#line 1784 "fgl.yacc"
    {dtypelist[0]=0;A4GL_lex_printcomment("/* define */\n");}
    break;

  case 181:
#line 1784 "fgl.yacc"
    {A4GL_lex_printcomment("/*end def */\n");}
    break;

  case 186:
#line 1793 "fgl.yacc"
    {in_define=1;}
    break;

  case 187:
#line 1793 "fgl.yacc"
    {in_define=0;strcpy(yyval.str,yyvsp[0].str);
                        set_yytext(yyval.str);
                        if (A4GL_bad_identifiers(yyval.str)) {
                                a4gl_yyerror("You can't use this identifier as it is a reserved word in the target language");
                        }
}
    break;

  case 188:
#line 1802 "fgl.yacc"
    { add_constant('c',yyvsp[0].str,yyvsp[-2].str); addmap("Constant",yyvsp[-2].str,curr_func,yylineno,infilename); }
    break;

  case 189:
#line 1803 "fgl.yacc"
    { add_constant('C',yyvsp[0].str,yyvsp[-2].str); addmap("Constant",yyvsp[-2].str,curr_func,yylineno,infilename); }
    break;

  case 190:
#line 1804 "fgl.yacc"
    { add_constant('f',yyvsp[0].str,yyvsp[-2].str);
addmap("Constant",yyvsp[-2].str,curr_func,yylineno,infilename);
 }
    break;

  case 191:
#line 1807 "fgl.yacc"
    { 
add_constant('i',yyvsp[0].str,yyvsp[-2].str);
addmap("Constant",yyvsp[-2].str,curr_func,yylineno,infilename);
 }
    break;

  case 193:
#line 1812 "fgl.yacc"
    { }
    break;

  case 194:
#line 1812 "fgl.yacc"
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
#line 1829 "fgl.yacc"
    {
		sprintf(yyval.str,"-%p",yyvsp[0].str);}
    break;

  case 199:
#line 1833 "fgl.yacc"
    {
/*AF CygWin FIX */
push_name(yyval.str,0);
addmap("Define",yyvsp[0].str,curr_func,yylineno,infilename);
}
    break;

  case 204:
#line 1848 "fgl.yacc"
    {strcpy(yyval.str,"-1");}
    break;

  case 205:
#line 1849 "fgl.yacc"
    {strcpy(yyval.str,"-1");}
    break;

  case 206:
#line 1850 "fgl.yacc"
    {strcpy(yyval.str,"-2");}
    break;

  case 207:
#line 1851 "fgl.yacc"
    {strcpy(yyval.str,"-3");}
    break;

  case 208:
#line 1856 "fgl.yacc"
    {
 A4GL_debug("defines array %s",yyvsp[-1].str);
	push_type(0,0,yyvsp[-1].str);
}
    break;

  case 210:
#line 1862 "fgl.yacc"
    {
 A4GL_debug("defines array %s",yyvsp[0].str);
	push_type(0,0,yyvsp[0].str);
}
    break;

  case 212:
#line 1871 "fgl.yacc"
    {
	push_associate(yyvsp[-5].str,yyvsp[-1].str);
	push_type(0,0,yyvsp[-1].str);
}
    break;

  case 213:
#line 1875 "fgl.yacc"
    {
    /* void pop_associate (char *a); */
	pop_associate(0);

}
    break;

  case 219:
#line 1891 "fgl.yacc"
    {sprintf(yyval.str,"%s][%s][%s",yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str); A4GL_debug("Triplet");}
    break;

  case 220:
#line 1893 "fgl.yacc"
    {sprintf(yyval.str,"%s][%s",yyvsp[-2].str,yyvsp[0].str); A4GL_debug("double");}
    break;

  case 221:
#line 1894 "fgl.yacc"
    {A4GL_debug("Single");}
    break;

  case 223:
#line 1901 "fgl.yacc"
    {push_record();in_record++;}
    break;

  case 224:
#line 1901 "fgl.yacc"
    {pop_record();in_record--;}
    break;

  case 225:
#line 1902 "fgl.yacc"
    {in_record++;push_record();A4GL_debug("Like\n");}
    break;

  case 226:
#line 1903 "fgl.yacc"
    {A4GL_debug("Link Table : %s\n",yyvsp[-2].str);
                  push_rectab(yyvsp[-2].str);
                  pop_record();in_record--;}
    break;

  case 227:
#line 1906 "fgl.yacc"
    {
		push_record();A4GL_debug("Like\n");}
    break;

  case 228:
#line 1908 "fgl.yacc"
    {
		  A4GL_debug("Table:%s\n",yyvsp[-4].str);
		  add_link_to(yyvsp[-4].str,yyvsp[-1].str);
	          A4GL_debug("Push record...\n");
                  push_rectab(yyvsp[-4].str);
                  pop_record();
}
    break;

  case 230:
#line 1918 "fgl.yacc"
    {
	sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 235:
#line 1933 "fgl.yacc"
    {start_state("dtype",1);}
    break;

  case 236:
#line 1933 "fgl.yacc"
    {start_state("dtype",0);}
    break;

  case 240:
#line 1939 "fgl.yacc"
    {push_type("char","1",0);}
    break;

  case 241:
#line 1940 "fgl.yacc"
    {push_type("char","1",0);}
    break;

  case 242:
#line 1941 "fgl.yacc"
    { if (atoi(yyvsp[-1].str)==4) { addmap("size=4","----",curr_func,yylineno,infilename); } push_type("char",yyvsp[-1].str,0); }
    break;

  case 243:
#line 1942 "fgl.yacc"
    { if (atoi(yyvsp[-1].str)==4) { addmap("size=4","----",curr_func,yylineno,infilename); } push_type("char",yyvsp[-1].str,0); }
    break;

  case 244:
#line 1943 "fgl.yacc"
    {push_type("varchar",yyvsp[-1].str,0);}
    break;

  case 245:
#line 1944 "fgl.yacc"
    {push_type("varchar",yyvsp[-3].str,0);}
    break;

  case 246:
#line 1945 "fgl.yacc"
    {push_type("char",yyvsp[-1].str,0);}
    break;

  case 247:
#line 1946 "fgl.yacc"
    {push_type("char",yyvsp[-3].str,0);}
    break;

  case 248:
#line 1947 "fgl.yacc"
    {push_type("long",0,0);}
    break;

  case 249:
#line 1948 "fgl.yacc"
    {
A4GL_debug("Using specified type...");
push_dim(yyvsp[0].str);}
    break;

  case 250:
#line 1951 "fgl.yacc"
    {push_type("int",0,0);}
    break;

  case 251:
#line 1952 "fgl.yacc"
    {push_type("form",0,0);}
    break;

  case 252:
#line 1953 "fgl.yacc"
    {push_type("form",0,0);}
    break;

  case 253:
#line 1954 "fgl.yacc"
    { char buff[256];
				sprintf(buff,"%d",16*256+2);
				push_type("fgldecimal",buff,0);
				}
    break;

  case 254:
#line 1958 "fgl.yacc"
    {
				char buff[256];
				sprintf(buff,"%d",atoi(yyvsp[-1].str)*256+2);
				push_type("fgldecimal",buff,0);
}
    break;

  case 255:
#line 1963 "fgl.yacc"
    {
char buff[256];
sprintf(buff,"%d",atoi(yyvsp[-3].str)*256+atoi(yyvsp[-1].str));
push_type("fgldecimal",buff,0);
}
    break;

  case 256:
#line 1968 "fgl.yacc"
    {
			char buff[256];
			sprintf(buff,"%d",16*256+2);
			push_type("fglmoney",buff,0);}
    break;

  case 257:
#line 1972 "fgl.yacc"
    {
		char buff[256];sprintf(buff,"%d",atoi(yyvsp[-1].str)*256+2);
			push_type("fglmoney",buff,0);}
    break;

  case 258:
#line 1975 "fgl.yacc"
    {
char buff[256];
sprintf(buff,"%d",atoi(yyvsp[-3].str)*256+atoi(yyvsp[-1].str));
push_type("fglmoney",buff,0);}
    break;

  case 259:
#line 1979 "fgl.yacc"
    {push_type("double",0,0);}
    break;

  case 261:
#line 1980 "fgl.yacc"
    {push_type("double",0,0);}
    break;

  case 263:
#line 1981 "fgl.yacc"
    {push_type("float",0,0);}
    break;

  case 265:
#line 1982 "fgl.yacc"
    {push_type("fgldate",0,0);}
    break;

  case 266:
#line 1983 "fgl.yacc"
    {push_type("fglbyte",0,0);}
    break;

  case 267:
#line 1984 "fgl.yacc"
    {push_type("fglbyte",0,0);}
    break;

  case 268:
#line 1985 "fgl.yacc"
    {push_type("fgltext",0,0);}
    break;

  case 269:
#line 1986 "fgl.yacc"
    {push_type("fgltext",0,0);}
    break;

  case 270:
#line 1987 "fgl.yacc"
    {
push_type("struct_dtime",yyvsp[0].str,0);
}
    break;

  case 271:
#line 1990 "fgl.yacc"
    {push_type("struct_ival",yyvsp[0].str,0);}
    break;

  case 272:
#line 1991 "fgl.yacc"
    {push_like(yyvsp[0].str);A4GL_lex_printcomment("/*added(XXXXX)\n */");}
    break;

  case 273:
#line 1992 "fgl.yacc"
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
#line 2027 "fgl.yacc"
    {
A4GL_lex_printcomment("/*column like(ZZZ)\n*/"); sprintf(yyval.str,"%s.%s",yyvsp[-2].str,yyvsp[0].str); A4GL_lex_printcomment ("/*set col...(ZZZ)\n*/");}
    break;

  case 277:
#line 2031 "fgl.yacc"
    {A4GL_debug("--->%s\n",yyvsp[0].str);strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 278:
#line 2033 "fgl.yacc"
    {A4GL_debug("--->%s\n",yyvsp[0].str);strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 279:
#line 2035 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 280:
#line 2037 "fgl.yacc"
    {
A4GL_debug("Real datetime %s to %s\n",yyvsp[-2].str,yyvsp[0].str);
sprintf(yyval.str,"%d",(atoi(yyvsp[-2].str)*16)+atoi(yyvsp[0].str)); }
    break;

  case 281:
#line 2042 "fgl.yacc"
    {
	sprintf(yyval.str,"%d",(atoi(yyvsp[-2].str)*16)+atoi(yyvsp[0].str)); 
}
    break;

  case 282:
#line 2046 "fgl.yacc"
    {start_state("dtime_val",1);}
    break;

  case 283:
#line 2046 "fgl.yacc"
    {start_state("dtime_val",0); strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 284:
#line 2050 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 285:
#line 2051 "fgl.yacc"
    {strcpy(yyval.str,"2");}
    break;

  case 286:
#line 2052 "fgl.yacc"
    {strcpy(yyval.str,"3");}
    break;

  case 287:
#line 2053 "fgl.yacc"
    {strcpy(yyval.str,"4");}
    break;

  case 288:
#line 2054 "fgl.yacc"
    {strcpy(yyval.str,"5");}
    break;

  case 289:
#line 2055 "fgl.yacc"
    {strcpy(yyval.str,"6");}
    break;

  case 290:
#line 2057 "fgl.yacc"
    {
A4GL_debug("opt_frac returns %s",yyvsp[0].str);
sprintf(yyval.str,"%d",atoi(yyvsp[0].str)+6); }
    break;

  case 291:
#line 2062 "fgl.yacc"
    {start_state("dtime_val",1);}
    break;

  case 292:
#line 2062 "fgl.yacc"
    { A4GL_debug ("Got end");start_state("dtime_val",0);  strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 293:
#line 2065 "fgl.yacc"
    {
A4GL_debug("Nothing in fraction - assume 2");
strcpy(yyval.str,"2");}
    break;

  case 294:
#line 2067 "fgl.yacc"
    {
A4GL_debug("Read fraction .. ");
A4GL_debug("    %s",yyvsp[-1].str);
strcpy(yyval.str,yyvsp[-1].str);
}
    break;

  case 295:
#line 2073 "fgl.yacc"
    {
A4GL_debug("Nothing in fraction - assume 2");
strcpy(yyval.str,"2");}
    break;

  case 296:
#line 2075 "fgl.yacc"
    {
A4GL_debug("    %s",yyvsp[-1].str);
strcpy(yyval.str,yyvsp[-1].str);
}
    break;

  case 297:
#line 2081 "fgl.yacc"
    {
if (atoi(yyvsp[0].str)>5) {
a4gl_yyerror("Fraction values are between 0 and 5");
YYERROR;
}
}
    break;

  case 298:
#line 2089 "fgl.yacc"
    {start_state("interval_val",1);}
    break;

  case 299:
#line 2089 "fgl.yacc"
    {start_state("interval_val",0); sprintf(yyval.str,"%d",atoi(yyvsp[0].str)*16+atoi(yyvsp[-1].str));}
    break;

  case 300:
#line 2092 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 301:
#line 2093 "fgl.yacc"
    {strcpy(yyval.str,"2");}
    break;

  case 302:
#line 2094 "fgl.yacc"
    {strcpy(yyval.str,"3");}
    break;

  case 303:
#line 2095 "fgl.yacc"
    {strcpy(yyval.str,"4");}
    break;

  case 304:
#line 2096 "fgl.yacc"
    {strcpy(yyval.str,"5");}
    break;

  case 305:
#line 2097 "fgl.yacc"
    {strcpy(yyval.str,"6");}
    break;

  case 306:
#line 2099 "fgl.yacc"
    {
A4GL_debug("opt_frac returns %s",yyvsp[0].str);
sprintf(yyval.str,"%d",atoi(yyvsp[0].str)+6); }
    break;

  case 310:
#line 2120 "fgl.yacc"
    {
              	dim_set_name(yyvsp[0].str);
              }
    break;

  case 314:
#line 2129 "fgl.yacc"
    {dim_push_type("char","1",0);}
    break;

  case 315:
#line 2131 "fgl.yacc"
    {dim_push_type("char",yyvsp[-1].str,0);}
    break;

  case 316:
#line 2132 "fgl.yacc"
    {
						dim_push_type("varchar",yyvsp[-1].str,0);
				}
    break;

  case 317:
#line 2135 "fgl.yacc"
    {
						char buff[256];
						sprintf(buff,"%d",atoi(yyvsp[-3].str)*256+atoi(yyvsp[-1].str));
						dim_push_type("varchar",buff,0);}
    break;

  case 318:
#line 2139 "fgl.yacc"
    {dim_push_type("long",0,0);}
    break;

  case 319:
#line 2140 "fgl.yacc"
    {dim_push_type("integer",0,0);}
    break;

  case 320:
#line 2141 "fgl.yacc"
    {dim_push_type("FORM",0,0);}
    break;

  case 321:
#line 2142 "fgl.yacc"
    {
char buff[256];
sprintf(buff,"%d",16*256+2);
dim_push_type("fgldecimal",buff,0);
}
    break;

  case 322:
#line 2147 "fgl.yacc"
    {

char buff[256];
sprintf(buff,"%d",atoi(yyvsp[-1].str)*256+2);
dim_push_type("fgldecimal",buff,0);
}
    break;

  case 323:
#line 2154 "fgl.yacc"
    {
char buff[256];
sprintf(buff,"%d",atoi(yyvsp[-3].str)*256+atoi(yyvsp[-1].str));
dim_push_type("fgldecimal",buff,0);
}
    break;

  case 324:
#line 2159 "fgl.yacc"
    {dim_push_type("fglmoney",0,0);}
    break;

  case 325:
#line 2161 "fgl.yacc"
    {dim_push_type("fglmoney",0,0);}
    break;

  case 326:
#line 2163 "fgl.yacc"
    {dim_push_type("fglmoney",0,0);}
    break;

  case 327:
#line 2164 "fgl.yacc"
    {dim_push_type("double",0,0);}
    break;

  case 328:
#line 2165 "fgl.yacc"
    {dim_push_type("float",0,0);}
    break;

  case 329:
#line 2166 "fgl.yacc"
    {dim_push_type("fgldate",0,0);}
    break;

  case 330:
#line 2167 "fgl.yacc"
    {dim_push_type("fglbyte",0,0);}
    break;

  case 331:
#line 2168 "fgl.yacc"
    {dim_push_type("fgltext",0,0);}
    break;

  case 332:
#line 2169 "fgl.yacc"
    {
dim_push_type("struct_dtime",yyvsp[0].str,0);
}
    break;

  case 333:
#line 2172 "fgl.yacc"
    {dim_push_type("struct_ival",0,0);}
    break;

  case 334:
#line 2174 "fgl.yacc"
    {dim_push_like(yyvsp[0].str);A4GL_lex_printcomment("/*added(XXXXX)\n */");}
    break;

  case 335:
#line 2180 "fgl.yacc"
    {
A4GL_lex_printcomment("/*column like(ZZZ)\n*/");
sprintf(yyval.str,"%s.%s",yyvsp[-2].str,yyvsp[0].str)
; A4GL_lex_printcomment ("/*set col...(ZZZ)\n*/");}
    break;

  case 336:
#line 2188 "fgl.yacc"
    {
dim_push_type(0,0,yyvsp[-1].str);
}
    break;

  case 338:
#line 2196 "fgl.yacc"
    {
dim_push_associate(yyvsp[-5].str,yyvsp[-1].str);
dim_push_type(0,0,yyvsp[-1].str);
}
    break;

  case 339:
#line 2200 "fgl.yacc"
    {
	/* void dim_pop_associate (char *a); */
	dim_pop_associate(0);
}
    break;

  case 340:
#line 2208 "fgl.yacc"
    {dim_push_record();}
    break;

  case 341:
#line 2209 "fgl.yacc"
    {dim_pop_record();}
    break;

  case 342:
#line 2210 "fgl.yacc"
    {dim_push_record();A4GL_debug("Like\n");}
    break;

  case 343:
#line 2211 "fgl.yacc"
    {A4GL_debug("Table:%s\n",yyvsp[-2].str);
                                  dim_push_rectab(yyvsp[-2].str);
                                  dim_pop_record();}
    break;

  case 349:
#line 2230 "fgl.yacc"
    { dim_push_name(yyval.str,0); }
    break;

  case 350:
#line 2242 "fgl.yacc"
    {
	print_display_line();
		strcpy(yyval.str,A4GL_get_display_str(0,0,0));
	}
    break;

  case 351:
#line 2246 "fgl.yacc"
    {
		strcpy(yyval.str,A4GL_get_display_str(1,0,0)); /* FIXME */
	}
    break;

  case 352:
#line 2249 "fgl.yacc"
    { 
	strcpy(yyval.str,"#error not implemented yet");
	}
    break;

  case 353:
#line 2252 "fgl.yacc"
    { strcpy(yyval.str, A4GL_get_display_str(4,0,0)); }
    break;

  case 354:
#line 2253 "fgl.yacc"
    { strcpy(yyval.str, A4GL_get_display_str(2,field_name_list_as_char(yyvsp[0].field_list),0)); }
    break;

  case 355:
#line 2254 "fgl.yacc"
    { strcpy(yyval.str, A4GL_get_display_str(3,field_name_list_as_char(yyvsp[0].field_list),yyvsp[-2].str)); }
    break;

  case 356:
#line 2255 "fgl.yacc"
    { strcpy(yyval.str, A4GL_get_display_str(5,yyvsp[-1].str,0)); }
    break;

  case 357:
#line 2256 "fgl.yacc"
    { 
	strcpy(yyval.str,"#error not implemented yet");
 }
    break;

  case 358:
#line 2262 "fgl.yacc"
    {
		print_display_by_name(yyvsp[0].str);
                }
    break;

  case 359:
#line 2269 "fgl.yacc"
    { 
				print_display(yyvsp[-1].str,yyvsp[-2].str,yyvsp[0].str);
		}
    break;

  case 360:
#line 2274 "fgl.yacc"
    {
		print_display_form(yyvsp[-1].str,yyvsp[0].str);
	}
    break;

  case 361:
#line 2279 "fgl.yacc"
    {
		push_blockcommand("DISPLAY");
		curr_input_array_attribs.curr_row_display=0;
		}
    break;

  case 362:
#line 2284 "fgl.yacc"
    {
		print_display_array_p1(fgl_add_scope(yyvsp[-6].str,0),yyvsp[-4].str,yyvsp[-1].str,yyvsp[0].str,&curr_input_array_attribs);
	  	A4GL_new_events();
		}
    break;

  case 363:
#line 2288 "fgl.yacc"
    {
		add_continue_blockcommand ("DISPLAY");  
		print_display_array_p2();
		pop_blockcommand("DISPLAY");
	  	A4GL_drop_events();
}
    break;

  case 364:
#line 2297 "fgl.yacc"
    {
strcpy(yyval.str,"0,0");
}
    break;

  case 365:
#line 2299 "fgl.yacc"
    {
	strcpy(yyval.str,field_name_as_char(yyvsp[0].field_entry));
}
    break;

  case 366:
#line 2304 "fgl.yacc"
    {
				sprintf(yyval.str,"0x%lx",atol(yyvsp[0].str));
			}
    break;

  case 372:
#line 2316 "fgl.yacc"
    {
		A4GL_add_event(-11,"");
		print_befaft_field_1("AFT_ROW");
		}
    break;

  case 373:
#line 2320 "fgl.yacc"
    {
		print_befaft_field_2();
	}
    break;

  case 374:
#line 2323 "fgl.yacc"
    {
		A4GL_add_event(-10,"");
		print_befaft_field_1("BEF_ROW");
		}
    break;

  case 375:
#line 2327 "fgl.yacc"
    {
		print_befaft_field_2();
	}
    break;

  case 376:
#line 2330 "fgl.yacc"
    {
		A4GL_add_onkey_key(yyvsp[0].str);
		print_onkey_1(yyvsp[0].str);
		}
    break;

  case 377:
#line 2334 "fgl.yacc"
    {
		print_onkey_2();
	}
    break;

  case 378:
#line 2341 "fgl.yacc"
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
#line 2359 "fgl.yacc"
    {
		print_dealloc_arr(yyvsp[0].str);
	}
    break;

  case 380:
#line 2365 "fgl.yacc"
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
#line 2389 "fgl.yacc"
    {
			print_error(yyvsp[0].str,0);
		}
    break;

  case 382:
#line 2392 "fgl.yacc"
    { 
			print_error(yyvsp[-1].str,1);
	}
    break;

  case 383:
#line 2407 "fgl.yacc"
    { if (in_command("WHILE")) { exit_loop("WHILE"); } else { YYERROR;} }
    break;

  case 384:
#line 2409 "fgl.yacc"
    { if (in_command("INPUT")) { exit_loop("INPUT"); } else { YYERROR;} }
    break;

  case 385:
#line 2411 "fgl.yacc"
    { if (in_command("FOREACH")) { exit_loop("FOREACH"); } else { YYERROR;} }
    break;

  case 386:
#line 2413 "fgl.yacc"
    { if (in_command("FOR")) { exit_loop("FOR"); } else { YYERROR;} }
    break;

  case 387:
#line 2415 "fgl.yacc"
    { if (in_command("CONSTRUCT")) { exit_loop("CONSTRUCT"); } else { YYERROR;} }
    break;

  case 388:
#line 2417 "fgl.yacc"
    { if (in_command("DISPLAY")) { exit_loop("DISPLAY"); } else { YYERROR;} }
    break;

  case 389:
#line 2418 "fgl.yacc"
    {
	if (in_command("MENU")) {
		exit_loop("MENU");
		/* A4GL_lex_printc("cmd_no=-3;continue;\n"); */
	} 
              else YYERROR;}
    break;

  case 390:
#line 2425 "fgl.yacc"
    { if (in_command("CASE")) { exit_loop("CASE"); } else { YYERROR;} }
    break;

  case 391:
#line 2427 "fgl.yacc"
    { if (in_command("PROMPT")) { exit_loop("PROMPT"); } else { YYERROR;} }
    break;

  case 392:
#line 2431 "fgl.yacc"
    { if (in_command("WHILE")) { continue_loop("WHILE");  } else { YYERROR;} }
    break;

  case 393:
#line 2433 "fgl.yacc"
    { if (in_command("INPUT")) { continue_loop("INPUT"); } else { YYERROR;} }
    break;

  case 394:
#line 2435 "fgl.yacc"
    { if (in_command("FOREACH")) { continue_loop("FOREACH");} else { YYERROR;} }
    break;

  case 395:
#line 2437 "fgl.yacc"
    { if (in_command("FOR")) { continue_loop("FOR"); } else { YYERROR;} }
    break;

  case 396:
#line 2439 "fgl.yacc"
    { if (in_command("CONSTRUCT")) { continue_loop("CONSTRUCT"); } else { YYERROR;} }
    break;

  case 397:
#line 2441 "fgl.yacc"
    { if (in_command("DISPLAY")) { continue_loop("DISPLAY"); } else { YYERROR;} }
    break;

  case 398:
#line 2443 "fgl.yacc"
    { if (in_command("MENU")) {  continue_loop("MENU");  } else { YYERROR;} }
    break;

  case 399:
#line 2449 "fgl.yacc"
    { if (in_command("PROMPT")) { continue_loop("PROMPT"); } else { YYERROR;} }
    break;

  case 400:
#line 2463 "fgl.yacc"
    {
	print_exit_program(0);
}
    break;

  case 401:
#line 2466 "fgl.yacc"
    {
	print_exit_program(1);
}
    break;

  case 406:
#line 2483 "fgl.yacc"
    {
	dec_counter();
	yyval.ptr=A4GL_append_expr_expr(yyvsp[-1].ptr,yyvsp[0].ptr);
}
    break;

  case 409:
#line 2489 "fgl.yacc"
    {
	A4GL_debug("Got literal ptr=%p",yyvsp[0].ptr);
}
    break;

  case 410:
#line 2493 "fgl.yacc"
    {
	yyval.ptr=A4GL_new_expr("A4GL_push_int(0);");
	yyval.ptr=A4GL_append_expr_expr(yyval.ptr,yyvsp[0].ptr);
	yyval.ptr=A4GL_append_expr(yyval.ptr,"A4GL_pushop(OP_SUB);");
}
    break;

  case 411:
#line 2498 "fgl.yacc"
    {
	yyval.ptr=yyvsp[0].ptr;
}
    break;

  case 415:
#line 2508 "fgl.yacc"
    { yyval.ptr=A4GL_new_expr("A4GL_add_spaces();"); }
    break;

  case 416:
#line 2509 "fgl.yacc"
    {inc_counter();}
    break;

  case 422:
#line 2515 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_CONCAT);");
}
    break;

  case 423:
#line 2522 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 424:
#line 2522 "fgl.yacc"
    {
strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 426:
#line 2527 "fgl.yacc"
    {yyval.ptr=A4GL_new_expr("A4GL_push_null(2,0);");}
    break;

  case 427:
#line 2531 "fgl.yacc"
    {
	/*set_counter(0);*/
	sprintf(yyval.str,"%d",get_counter_val());
	A4GL_lex_printcomment("/*L1 %s*/\n",yyval.str);
}
    break;

  case 428:
#line 2537 "fgl.yacc"
    {
	sprintf(yyval.str,"%d",get_counter_val());
	A4GL_lex_printcomment("/*L2 %s*/\n",yyval.str);
}
    break;

  case 429:
#line 2545 "fgl.yacc"
    {
	/*set_counter(0);*/
	sprintf(yyval.str,"%d",get_counter_val());
	A4GL_lex_printcomment("/*L1 %s*/\n",yyval.str);
}
    break;

  case 430:
#line 2551 "fgl.yacc"
    {
	sprintf(yyval.str,"%d",get_counter_val());
	A4GL_lex_printcomment("/*L2 %s*/\n",yyval.str);
}
    break;

  case 431:
#line 2560 "fgl.yacc"
    {sprintf(yyval.str,"%d",get_counter_val());}
    break;

  case 432:
#line 2562 "fgl.yacc"
    {
	print_op("OP_CONCAT");
	dec_counter();sprintf(yyval.str,"%d",get_counter_val());
}
    break;

  case 433:
#line 2569 "fgl.yacc"
    {
	A4GL_debug("Print expr (2)");
	print_expr(yyvsp[0].ptr);
}
    break;

  case 434:
#line 2577 "fgl.yacc"
    {
	strcpy(yyval.str,"+");
}
    break;

  case 435:
#line 2581 "fgl.yacc"
    {
	strcpy(yyval.str,"-");
}
    break;

  case 436:
#line 2590 "fgl.yacc"
    {
	
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_NOT);");
}
    break;

  case 437:
#line 2595 "fgl.yacc"
    {
	yyval.ptr=A4GL_new_expr("A4GL_push_int(1);");
        inc_counter();
}
    break;

  case 438:
#line 2600 "fgl.yacc"
    {
	inc_counter();
	yyval.ptr=A4GL_new_expr("A4GL_push_int(0);");
}
    break;

  case 439:
#line 2604 "fgl.yacc"
    { yyval.ptr=yyvsp[-1].ptr; }
    break;

  case 440:
#line 2606 "fgl.yacc"
    {
	yyval.ptr=get_in_exists_sql(yyvsp[-1].sql_string,'E');
}
    break;

  case 441:
#line 2609 "fgl.yacc"
    {
	yyval.ptr=get_in_exists_sql(yyvsp[-1].sql_string,'e');
}
    break;

  case 442:
#line 2616 "fgl.yacc"
    {
	A4GL_debug("init expr %s %s",yyvsp[-1].str,yyvsp[0].str);
	sprintf(yyval.str,"%s%p",yyvsp[-1].str,yyvsp[0].str);
	sprintf(yyval.str,"%s",A4GL_get_push_literal('D',yyval.str));
	yyval.ptr=A4GL_new_expr(yyval.str);
        inc_counter();
}
    break;

  case 443:
#line 2624 "fgl.yacc"
    {
	A4GL_debug("init expr int %s %d",yyvsp[-1].str,atoi(yyvsp[0].str));
	sprintf(yyval.str,"%s%p",yyvsp[-1].str,yyvsp[0].str);
	sprintf(yyval.str,"%s",A4GL_get_push_literal('L',yyval.str));
	yyval.ptr=A4GL_new_expr(yyval.str);
	inc_counter();
}
    break;

  case 444:
#line 2636 "fgl.yacc"
    {
	sprintf(yyval.str,"%s",A4GL_get_push_literal('S',yyvsp[0].str));
	yyval.ptr=A4GL_new_expr(yyval.str);
	inc_counter();
}
    break;

  case 445:
#line 2642 "fgl.yacc"
    {
	sprintf(yyval.str,"%s",A4GL_get_push_literal('D',yyvsp[0].str));
	yyval.ptr=A4GL_new_expr(yyval.str);
	inc_counter();
}
    break;

  case 446:
#line 2648 "fgl.yacc"
    {
	sprintf(yyval.str,"%s",A4GL_get_push_literal('L',yyvsp[0].str));
	yyval.ptr=A4GL_new_expr(yyval.str);
	inc_counter();
}
    break;

  case 449:
#line 2658 "fgl.yacc"
    {
		sprintf(yyval.str,"%s\n%s",yyvsp[-2].str,yyvsp[0].str);
	}
    break;

  case 450:
#line 2664 "fgl.yacc"
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
#line 2736 "fgl.yacc"
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
#line 2747 "fgl.yacc"
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
#line 2755 "fgl.yacc"
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
#line 2763 "fgl.yacc"
    {insql=1;set_ingroup();}
    break;

  case 455:
#line 2763 "fgl.yacc"
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
#line 2779 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_AND);");
}
    break;

  case 457:
#line 2783 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_OR);");
}
    break;

  case 458:
#line 2789 "fgl.yacc"
    {
	yyval.ptr=yyvsp[0].ptr;
	}
    break;

  case 459:
#line 2792 "fgl.yacc"
    {
		A4GL_debug("Adding to list...");
		yyval.ptr=A4GL_append_expr_expr(yyvsp[-2].ptr,yyvsp[0].ptr);
	}
    break;

  case 460:
#line 2800 "fgl.yacc"
    {
	yyval.ptr=get_in_exists_sql(yyvsp[-1].sql_string,'I');
}
    break;

  case 461:
#line 2804 "fgl.yacc"
    {
	yyval.ptr=get_in_exists_sql(yyvsp[-1].sql_string,'i');
}
    break;

  case 462:
#line 2807 "fgl.yacc"
    {
	char buff[256];
	sprintf(buff,"A4GL_push_int(%d);",length_expr(yyvsp[-1].ptr));
	yyval.ptr=A4GL_append_expr(yyvsp[-1].ptr,buff);
	A4GL_append_expr(yyval.ptr,"A4GL_pushop(OP_IN);");
}
    break;

  case 463:
#line 2813 "fgl.yacc"
    {
	char buff[256];
	sprintf(buff,"A4GL_push_int(%d);",length_expr(yyvsp[-1].ptr));
	yyval.ptr=A4GL_append_expr(yyvsp[-1].ptr,buff);
	A4GL_append_expr(yyval.ptr,"A4GL_pushop(OP_NOTIN);");
}
    break;

  case 464:
#line 2823 "fgl.yacc"
    { 
	strcpy(yyval.str,"A4GL_pushop(OP_ISNULL);");
	yyval.ptr=A4GL_new_expr(yyval.str);
}
    break;

  case 465:
#line 2828 "fgl.yacc"
    {
	strcpy(yyval.str,"A4GL_pushop(OP_ISNOTNULL);");
	yyval.ptr=A4GL_new_expr(yyval.str);
}
    break;

  case 466:
#line 2835 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_push_char(\"\\\\\");A4GL_pushop(OP_MATCHES);");
 }
    break;

  case 467:
#line 2838 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_push_char(\"\\\\\");A4GL_pushop(OP_MATCHES);A4GL_pushop(OP_NOT);");
}
    break;

  case 468:
#line 2841 "fgl.yacc"
    {
	char buff[40];
	sprintf(buff,"A4GL_push_char(%s);A4GL_pushop(OP_MATCHES);",yyvsp[0].str);
	yyval.ptr=A4GL_append_expr(yyvsp[-2].ptr,buff);
 }
    break;

  case 469:
#line 2846 "fgl.yacc"
    {
	char buff[40];
	sprintf(buff,"A4GL_push_char(%s);A4GL_pushop(OP_MATCHES);A4GL_pushop(OP_NOT);",yyvsp[0].str);
	yyval.ptr=A4GL_append_expr(yyvsp[-2].ptr,buff);
}
    break;

  case 470:
#line 2853 "fgl.yacc"
    {
	char buff[40];
	sprintf(buff,"A4GL_push_char(\"\\\\\");A4GL_pushop(OP_LIKE);");
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,buff);
}
    break;

  case 471:
#line 2858 "fgl.yacc"
    {
	char buff[40];
	sprintf(buff,"A4GL_push_char(\"\\\\\");A4GL_pushop(OP_LIKE);A4GL_pushop(OP_NOT);");
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,buff);
}
    break;

  case 472:
#line 2863 "fgl.yacc"
    {
	char buff[40];
	sprintf(buff,"A4GL_push_char(%s);A4GL_pushop(OP_LIKE);",yyvsp[0].str);
	yyval.ptr=A4GL_append_expr(yyvsp[-2].ptr,buff);
}
    break;

  case 473:
#line 2868 "fgl.yacc"
    {
	char buff[40];
	sprintf(buff,"A4GL_push_char(%s);A4GL_pushop(OP_LIKE);A4GL_pushop(OP_NOT);",yyvsp[0].str);
	yyval.ptr=A4GL_append_expr(yyvsp[-2].ptr,buff);
}
    break;

  case 474:
#line 2879 "fgl.yacc"
    {
	strcpy(yyval.str,"A4GL_pushop(OP_CLIP);");
	yyval.ptr=A4GL_new_expr(yyval.str);
	inc_counter();
}
    break;

  case 475:
#line 2887 "fgl.yacc"
    {
	sprintf(yyval.str,"%s A4GL_pushop(OP_USING);",yyvsp[0].str);
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_USING);");
}
    break;

  case 476:
#line 2895 "fgl.yacc"
    {
	A4GL_debug("PLUS in math_expr $<ptr>2 = %p",yyvsp[0].ptr);
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_ADD);");
}
    break;

  case 477:
#line 2900 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_SUB);");
}
    break;

  case 478:
#line 2904 "fgl.yacc"
    {
      sprintf(yyval.str,"%s A4GL_A4GL_pushop(OP_MULT);",yyvsp[0].str);
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_MULT);");
}
    break;

  case 479:
#line 2909 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_DIV);");
}
    break;

  case 480:
#line 2913 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_MOD);");
}
    break;

  case 481:
#line 2917 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_POWER);");
}
    break;

  case 482:
#line 2923 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_EQUAL);");
}
    break;

  case 483:
#line 2926 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_EQUAL);");
}
    break;

  case 484:
#line 2930 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_LESS_THAN);");
}
    break;

  case 485:
#line 2934 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_GREATER_THAN);");
}
    break;

  case 486:
#line 2938 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_NOT_EQUAL);");
}
    break;

  case 487:
#line 2942 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_LESS_THAN_EQ);");
}
    break;

  case 488:
#line 2946 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_GREATER_THAN_EQ);");
}
    break;

  case 489:
#line 2953 "fgl.yacc"
    {
	reset_counter();
}
    break;

  case 490:
#line 2963 "fgl.yacc"
    { 
		addmap("Call",yyvsp[-1].str,curr_func,yylineno,infilename);
		new_counter(); 
		}
    break;

  case 491:
#line 2968 "fgl.yacc"
    { 
		sprintf(yyval.str,"%d",get_counter_val()); 
		A4GL_lex_printcomment("/*function_call_expr2 %s*/\n",yyval.str);
		drop_counter(); 
		}
    break;

  case 492:
#line 2974 "fgl.yacc"
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
#line 2984 "fgl.yacc"
    {
        sprintf(yyval.str,"\"%s\",\"%s\"",yyvsp[-3].str,yyvsp[-1].str);
	A4GL_debug("NEWFORMAT : %s\n",yyval.str);
        A4GLSQL_set_status(0,0);
        new_counter();
}
    break;

  case 494:
#line 2989 "fgl.yacc"
    {
	sprintf(yyval.str,"%d",get_counter_val());  
	drop_counter();
}
    break;

  case 495:
#line 2992 "fgl.yacc"
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
#line 3006 "fgl.yacc"
    {chk4var=1;}
    break;

  case 497:
#line 3006 "fgl.yacc"
    {chk4var=0;}
    break;

  case 498:
#line 3006 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[-2].ptr,"aclfgl_date(1);");
}
    break;

  case 499:
#line 3009 "fgl.yacc"
    {chk4var=1;}
    break;

  case 500:
#line 3009 "fgl.yacc"
    {chk4var=0;}
    break;

  case 501:
#line 3009 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[-2].ptr,"aclfgl_month(1);");
	/* consumes and replaces a fgl_expr_c - so we don't need to dec or inc_counter */
}
    break;

  case 502:
#line 3013 "fgl.yacc"
    {chk4var=1;}
    break;

  case 503:
#line 3013 "fgl.yacc"
    {chk4var=0;}
    break;

  case 504:
#line 3013 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[-2].ptr,"aclfgl_day(1);");
	/* consumes and replaces a fgl_expr_c - so we don't need to dec or inc_counter */
}
    break;

  case 505:
#line 3017 "fgl.yacc"
    {chk4var=1;}
    break;

  case 506:
#line 3017 "fgl.yacc"
    {chk4var=0;}
    break;

  case 507:
#line 3017 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[-2].ptr,"aclfgl_year(1);");
	/* consumes and replaces a fgl_expr_c - so we don't need to dec or inc_counter */
}
    break;

  case 508:
#line 3021 "fgl.yacc"
    {
	char buff[256];
	sprintf(buff,"acli_interval(%s,%s);",yyvsp[-2].str,yyvsp[0].str);
	yyval.ptr=A4GL_new_expr(buff);
	inc_counter();
}
    break;

  case 509:
#line 3027 "fgl.yacc"
    {
	char buff[256];
	sprintf(buff,"acli_datetime(%s,%s);",yyvsp[-2].str,yyvsp[0].str);
	yyval.ptr=A4GL_new_expr(buff);
	inc_counter();
}
    break;

  case 510:
#line 3033 "fgl.yacc"
    {
	char buff[256];
	sprintf(buff,"acli_datetime(\"%s\",%s);",yyvsp[-2].str,yyvsp[0].str);
	yyval.ptr=A4GL_new_expr(buff);
	inc_counter();
}
    break;

  case 511:
#line 3039 "fgl.yacc"
    {
	char buff[256];
	sprintf(buff,"acli_datetime(\"%s:%s\",%s);",yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str);
	yyval.ptr=A4GL_new_expr(buff);
	inc_counter();
}
    break;

  case 512:
#line 3045 "fgl.yacc"
    {
	char buff[256];
	sprintf(buff,"acli_datetime(\"%s-%s\",%s);",yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str);
	yyval.ptr=A4GL_new_expr(buff);
	inc_counter();
}
    break;

  case 513:
#line 3051 "fgl.yacc"
    {
	char buff[256];
	sprintf(buff,"acli_datetime(\"%s-%s-%s\",%s);",yyvsp[-6].str,yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str);
	yyval.ptr=A4GL_new_expr(buff);
	inc_counter();
}
    break;

  case 514:
#line 3060 "fgl.yacc"
    {
	char buff[256];
	sprintf(buff,"A4GL_isdynarr_allocated(&%s);",yyvsp[-1].str);
        yyval.ptr=A4GL_new_expr(buff);
        inc_counter();
}
    break;

  case 515:
#line 3066 "fgl.yacc"
    { 
        char buff[256];
        sprintf(buff,"A4GL_dynarr_extent(&%s,%d);",yyvsp[-3].str,atoi(yyvsp[-1].str));
        yyval.ptr=A4GL_new_expr(buff);
        inc_counter();
}
    break;

  case 516:
#line 3076 "fgl.yacc"
    {strcpy(yyval.str,"-1");}
    break;

  case 517:
#line 3077 "fgl.yacc"
    {sprintf(yyval.str,"%d",atoi(yyvsp[-2].str)*16+atoi(yyvsp[0].str));}
    break;

  case 520:
#line 3085 "fgl.yacc"
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

  case 521:
#line 3096 "fgl.yacc"
    {sprintf(yyval.str,"A4GL_push_int(A4GL_fgl_fieldnametoid(\"\",%s));",field_name_as_char(yyvsp[-1].field_entry)); yyval.ptr=A4GL_new_expr(yyval.str); }
    break;

  case 522:
#line 3097 "fgl.yacc"
    {
sprintf(yyval.str,"A4GL_push_int(A4GL_fgl_fieldnametoid(\"\",%s));",field_name_as_char(yyvsp[-1].field_entry)); yyval.ptr=A4GL_new_expr(yyval.str); 
addmap("Get Field",field_name_as_char(yyvsp[-1].field_entry),curr_func,yylineno,infilename);
	inc_counter();
}
    break;

  case 523:
#line 3103 "fgl.yacc"
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

  case 524:
#line 3114 "fgl.yacc"
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

  case 525:
#line 3124 "fgl.yacc"
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

  case 528:
#line 3137 "fgl.yacc"
    {
		inc_counter();
               sprintf(yyval.str,"A4GL_push_current(%s);",yyvsp[0].str);
		yyval.ptr=A4GL_new_expr(yyval.str);
          	}
    break;

  case 529:
#line 3142 "fgl.yacc"
    { inc_counter(); strcpy(yyval.str,"A4GL_push_today();");
		yyval.ptr=A4GL_new_expr(yyval.str);
		}
    break;

  case 530:
#line 3149 "fgl.yacc"
    { 
	yyval.ptr=A4GL_append_expr(yyvsp[-1].ptr,"A4GL_upshift_stk();");
}
    break;

  case 531:
#line 3153 "fgl.yacc"
    { 
	yyval.ptr=A4GL_append_expr(yyvsp[-1].ptr,"A4GL_downshift_stk();");
}
    break;

  case 532:
#line 3156 "fgl.yacc"
    { 
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_push_ascii();");
}
    break;

  case 533:
#line 3159 "fgl.yacc"
    { 
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"aclfgli_extend();"); }
    break;

  case 534:
#line 3165 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[-1].ptr,"A4GL_push_double(-1);A4GL_pushop(OP_MULT);");
}
    break;

  case 535:
#line 3168 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[-1].ptr,"A4GL_push_double(-28.3465);A4GL_pushop(OP_MULT);");
}
    break;

  case 536:
#line 3171 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[-1].ptr,"A4GL_push_double(-72.0);A4GL_pushop(OP_MULT);");
}
    break;

  case 537:
#line 3188 "fgl.yacc"
    {
	strcpy(yyval.str,yyvsp[0].str);
}
    break;

  case 538:
#line 3191 "fgl.yacc"
    {
	strcpy(yyval.str,yyvsp[0].str);
}
    break;

  case 539:
#line 3197 "fgl.yacc"
    {sprintf(yyval.str,"-%s",yyvsp[0].str);}
    break;

  case 540:
#line 3198 "fgl.yacc"
    {sprintf(yyval.str,"\"%s\"",yyvsp[0].str);}
    break;

  case 541:
#line 3199 "fgl.yacc"
    {sprintf(yyval.str,"\"%s\"",yyvsp[0].str);}
    break;

  case 543:
#line 3204 "fgl.yacc"
    {sprintf(yyval.str,"%s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 544:
#line 3205 "fgl.yacc"
    {sprintf(yyval.str,"%s %s:%s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 545:
#line 3206 "fgl.yacc"
    {sprintf(yyval.str,"%s %s:%s:%s",yyvsp[-5].str,yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 546:
#line 3207 "fgl.yacc"
    {sprintf(yyval.str,"%s %s:%s:%s",yyvsp[-5].str,yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 547:
#line 3209 "fgl.yacc"
    {sprintf(yyval.str,"%s:%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 548:
#line 3210 "fgl.yacc"
    {sprintf(yyval.str,"%s:%s:%s",yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 549:
#line 3211 "fgl.yacc"
    {sprintf(yyval.str,"%s:%s:%s",yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 550:
#line 3213 "fgl.yacc"
    {sprintf(yyval.str,"%s:%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 551:
#line 3214 "fgl.yacc"
    {sprintf(yyval.str,"%s",yyvsp[0].str);}
    break;

  case 553:
#line 3220 "fgl.yacc"
    {sprintf(yyval.str,"%s-%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 554:
#line 3224 "fgl.yacc"
    {
                        yyval.field_list=new_field_list();
                        yyval.field_list=append_field_to_list(yyval.field_list,yyvsp[0].field_entry);
		}
    break;

  case 555:
#line 3228 "fgl.yacc"
    {
                        yyval.field_list=append_field_to_list(yyvsp[-2].field_list,yyvsp[0].field_entry);
	}
    break;

  case 556:
#line 3233 "fgl.yacc"
    {
                        yyval.field_list=new_field_list();
                        yyval.field_list=append_field_to_list(yyval.field_list,yyvsp[0].field_entry);
		}
    break;

  case 557:
#line 3237 "fgl.yacc"
    {
                        yyval.field_list=append_field_to_list(yyvsp[-2].field_list,yyvsp[0].field_entry);
	}
    break;

  case 558:
#line 3252 "fgl.yacc"
    {
print_for_start(yyvsp[-5].str);
push_blockcommand("FOR");
}
    break;

  case 559:
#line 3256 "fgl.yacc"
    {A4GL_debug("For_cmds\n");}
    break;

  case 560:
#line 3257 "fgl.yacc"
    {

pop_blockcommand("FOR");
print_for_end();
A4GL_lex_printcomment(" /*END FOR*/\n");}
    break;

  case 561:
#line 3264 "fgl.yacc"
    {
		print_for_default_step();
	}
    break;

  case 563:
#line 3281 "fgl.yacc"
    {
push_blockcommand("FOREACH");
}
    break;

  case 564:
#line 3285 "fgl.yacc"
    {
print_foreach_start();
A4GL_lex_printcomment(" /* foreach */\n");
}
    break;

  case 565:
#line 3291 "fgl.yacc"
    {
print_foreach_next(yyvsp[-3].str,yyvsp[-1].str,yyvsp[0].str);
}
    break;

  case 566:
#line 3295 "fgl.yacc"
    {
add_continue_blockcommand ("FOREACH");
print_foreach_end(yyvsp[-6].str);
pop_blockcommand("FOREACH"); 
print_foreach_close(yyvsp[-6].str);
}
    break;

  case 567:
#line 3304 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 568:
#line 3305 "fgl.yacc"
    {
		strcpy(yyval.str,yyvsp[0].str);
	}
    break;

  case 569:
#line 3317 "fgl.yacc"
    {
		sprintf(curr_func,"%s",yyvsp[0].str); 
		print_formhandler(yyvsp[0].str);
		start_state("formhandler",1);
	push_blockcommand("FORMHANDLER");
        }
    break;

  case 570:
#line 3323 "fgl.yacc"
    {
		print_variables();
		print_getwin();
	}
    break;

  case 571:
#line 3331 "fgl.yacc"
    {
pop_blockcommand("FORMHANDLER");
print_end_formhandler(); 
start_state("formhandler",0);}
    break;

  case 578:
#line 3348 "fgl.yacc"
    {
		print_event('B');
        }
    break;

  case 579:
#line 3350 "fgl.yacc"
    {
		print_event_2();
        }
    break;

  case 580:
#line 3353 "fgl.yacc"
    {
		print_event('b');
        }
    break;

  case 581:
#line 3355 "fgl.yacc"
    {
		print_event_2();
        }
    break;

  case 586:
#line 3369 "fgl.yacc"
    {
		print_event('A');
        }
    break;

  case 587:
#line 3371 "fgl.yacc"
    {
		print_event_2();
        }
    break;

  case 588:
#line 3374 "fgl.yacc"
    {
		print_event('a');
        }
    break;

  case 589:
#line 3376 "fgl.yacc"
    {
		print_event_2();
        }
    break;

  case 602:
#line 3407 "fgl.yacc"
    { 
			print_gtk_field('B',0);
		}
    break;

  case 603:
#line 3409 "fgl.yacc"
    {
			print_gtk_field_2();
		}
    break;

  case 604:
#line 3412 "fgl.yacc"
    { 
			print_gtk_field('A',0);
		}
    break;

  case 605:
#line 3414 "fgl.yacc"
    {
			print_gtk_field_2();
		}
    break;

  case 606:
#line 3417 "fgl.yacc"
    {
			print_gtk_field('b',yyvsp[0].str);
		}
    break;

  case 607:
#line 3419 "fgl.yacc"
    { 
			print_gtk_field_2();
		}
    break;

  case 608:
#line 3422 "fgl.yacc"
    {
			print_gtk_field('a',yyvsp[0].str);
		}
    break;

  case 609:
#line 3424 "fgl.yacc"
    { 
			print_gtk_field_2();
		}
    break;

  case 610:
#line 3427 "fgl.yacc"
    { 
			print_gtk_field('o',yyvsp[0].str);
		}
    break;

  case 611:
#line 3429 "fgl.yacc"
    { 
			print_gtk_field_2();
		}
    break;

  case 612:
#line 3444 "fgl.yacc"
    {
		//print_niy("Free Cursor");
		A4GL_lex_printcomment(" /* FIXME: Not implemented: Free Cursor */\n");;

		strcpy(yyval.str,"");
		}
    break;

  case 613:
#line 3460 "fgl.yacc"
    {sprintf(yyval.str,"%d",-1-(atoi(yyvsp[0].str)));}
    break;

  case 614:
#line 3461 "fgl.yacc"
    {strcpy(yyval.str,"-1");}
    break;

  case 615:
#line 3462 "fgl.yacc"
    {sprintf (yyval.str,"%d",atoi(yyvsp[0].str)+1);}
    break;

  case 616:
#line 3463 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 617:
#line 3464 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 618:
#line 3465 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 619:
#line 3466 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 623:
#line 3474 "fgl.yacc"
    {sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str); }
    break;

  case 625:
#line 3480 "fgl.yacc"
    { 
			yyval.field_entry=new_field_entry(yyvsp[0].str,"1",1);
		}
    break;

  case 626:
#line 3483 "fgl.yacc"
    { 
				char buff[256];
				sprintf(buff,"int_to_id(%s)",yyvsp[-1].str);
				yyval.field_entry=new_field_entry(buff,"1",0); 
		}
    break;

  case 627:
#line 3488 "fgl.yacc"
    { 
				char buff[256];
				sprintf(buff,"int_to_id(%s.%s)",yyvsp[-5].str,yyvsp[-1].str); 
				yyval.field_entry=new_field_entry(buff,"1",0); 
		}
    break;

  case 628:
#line 3493 "fgl.yacc"
    {
				yyval.field_entry=new_field_entry(yyvsp[-3].str,yyvsp[-1].str,1);
		}
    break;

  case 629:
#line 3496 "fgl.yacc"
    {
				char buff[256];
				sprintf(buff,"%s.*",yyvsp[-2].str);
				yyval.field_entry=new_field_entry(buff,"1",1);
		}
    break;

  case 630:
#line 3501 "fgl.yacc"
    {
				char buff[256];
				sprintf(buff,"%s.*",yyvsp[-5].str);
				yyval.field_entry=new_field_entry(buff,yyvsp[-3].str,1);
		}
    break;

  case 631:
#line 3506 "fgl.yacc"
    {
				char buff[256];
				sprintf(buff,"%s.%s",yyvsp[-2].str,yyvsp[0].str);
				yyval.field_entry=new_field_entry(buff,"1",1);
		}
    break;

  case 632:
#line 3511 "fgl.yacc"
    {
				char buff[256];
				sprintf(buff,"%s.%s",yyvsp[-5].str,yyvsp[0].str);
				yyval.field_entry=new_field_entry(buff,yyvsp[-3].str,1);
		}
    break;

  case 633:
#line 3518 "fgl.yacc"
    {yyval.field_entry=yyvsp[0].field_entry;}
    break;

  case 634:
#line 3519 "fgl.yacc"
    { 
                 char buff[256];
                 sprintf(buff,"%s",yyvsp[0].str);
                 yyval.field_entry=new_field_entry(buff,"1",0);
	}
    break;

  case 635:
#line 3526 "fgl.yacc"
    {
				print_pushchar(yyvsp[0].str);
				addmap("Cursor",last_var,curr_func,yylineno,infilename);
			}
    break;

  case 636:
#line 3533 "fgl.yacc"
    {sprintf(yyval.str,"%s",yyvsp[0].str);}
    break;

  case 637:
#line 3535 "fgl.yacc"
    {sprintf(yyval.str,"%s",yyvsp[0].str);
addmap("Window",last_var,curr_func,yylineno,infilename);
}
    break;

  case 638:
#line 3541 "fgl.yacc"
    {sprintf(yyval.str,"%s",yyvsp[0].str);
addmap("Open Window",last_var,curr_func,yylineno,infilename);
}
    break;

  case 639:
#line 3546 "fgl.yacc"
    {sprintf(yyval.str,"%s",yyvsp[0].str);
addmap("Form",last_var,curr_func,yylineno,infilename);
}
    break;

  case 640:
#line 3551 "fgl.yacc"
    {sprintf(yyval.str,"%s",yyvsp[0].str);
addmap("Open Form",last_var,curr_func,yylineno,infilename);
}
    break;

  case 641:
#line 3556 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 642:
#line 3556 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 643:
#line 3559 "fgl.yacc"
    { 
			strcpy(yyval.str,downshift(yyvsp[0].str)) ;
}
    break;

  case 644:
#line 3565 "fgl.yacc"
    {
			sprintf(yyval.str,"%s",downshift(yyvsp[0].str)) ;
			}
    break;

  case 645:
#line 3570 "fgl.yacc"
    {
	strcpy(yyval.str,do_clobbering(clobber,downshift(yyvsp[0].str))) ;
	strcpy(last_var,downshift(yyvsp[0].str));
}
    break;

  case 646:
#line 3574 "fgl.yacc"
    {
		sprintf(yyval.str,"aclfgli_str_to_id(%s)",yyvsp[-1].str);
		sprintf(last_var,"->%s",yyvsp[-1].str);
	}
    break;

  case 649:
#line 3582 "fgl.yacc"
    {
					yyval.field_entry=new_field_entry(yyvsp[0].str,"1",1); 
				}
    break;

  case 650:
#line 3585 "fgl.yacc"
    {
					yyval.field_entry=new_field_entry(yyvsp[-3].str,yyvsp[-1].str,1); 
				}
    break;

  case 651:
#line 3588 "fgl.yacc"
    {
					char buff[256];
					sprintf(buff,"%s.*",yyvsp[-2].str);
					yyval.field_entry=new_field_entry(buff,"1",1); 
				}
    break;

  case 652:
#line 3593 "fgl.yacc"
    {
					char buff[256];
					sprintf(buff,"%s.*",yyvsp[-5].str);
					yyval.field_entry=new_field_entry(buff,yyvsp[-3].str,1); 
				}
    break;

  case 653:
#line 3598 "fgl.yacc"
    {
					char buff[256];
					sprintf(buff,"%s.%s",yyvsp[-2].str,yyvsp[0].str);
					yyval.field_entry=new_field_entry(buff,"1",1); 
				}
    break;

  case 654:
#line 3603 "fgl.yacc"
    {
					char buff[256];
					sprintf(buff,"%s.%s",yyvsp[-5].str,yyvsp[0].str);
					yyval.field_entry=new_field_entry(buff,yyvsp[-3].str,1); 
				}
    break;

  case 655:
#line 3610 "fgl.yacc"
    {
A4GL_debug("Scanvar=%d",scan_variable(yyvsp[0].str)&15);
if ((scan_variable(yyvsp[0].str)&15)!=0) {
a4gl_yyerror("Only a character variable can be used for this");
YYERROR;
}
}
    break;

  case 657:
#line 3619 "fgl.yacc"
    {
		sprintf(yyval.str,".%s",yyvsp[0].str);
}
    break;

  case 658:
#line 3681 "fgl.yacc"
    {
	char buff[256];
	strcpy(buff,yyvsp[0].str);
	A4GL_convlower(buff);
	print_goto(buff);
}
    break;

  case 660:
#line 3690 "fgl.yacc"
    {sprintf(yyval.str,"%s",yyvsp[0].str);}
    break;

  case 661:
#line 3699 "fgl.yacc"
    {
print_gui_do_menuitems(yyvsp[0].str,'C');
}
    break;

  case 663:
#line 3706 "fgl.yacc"
    {sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 664:
#line 3709 "fgl.yacc"
    {
        sprintf(yyval.str,"\"%s\"",yyvsp[0].str);
}
    break;

  case 665:
#line 3715 "fgl.yacc"
    {
print_gui_do_menuitems(yyvsp[0].str,'U');
}
    break;

  case 666:
#line 3721 "fgl.yacc"
    {
print_gui_do_menuitems(yyvsp[0].str,'D');
}
    break;

  case 667:
#line 3725 "fgl.yacc"
    {
print_gui_do_fields(field_name_list_as_char(yyvsp[0].field_list),'D');
}
    break;

  case 668:
#line 3729 "fgl.yacc"
    {
print_gui_do_form(yyvsp[-2].str,field_name_list_as_char(yyvsp[0].field_list),'D');
}
    break;

  case 669:
#line 3735 "fgl.yacc"
    {
print_gui_do_menuitems(yyvsp[0].str,'E');
}
    break;

  case 670:
#line 3739 "fgl.yacc"
    {
print_gui_do_fields(field_name_list_as_char(yyvsp[0].field_list),'E');
}
    break;

  case 671:
#line 3743 "fgl.yacc"
    {
print_gui_do_form(field_name_list_as_char(yyvsp[-2].field_list),yyvsp[0].str,'E');
}
    break;

  case 672:
#line 3748 "fgl.yacc"
    {start_state("messagebox",1);}
    break;

  case 673:
#line 3753 "fgl.yacc"
    {start_state("messagebox",0);}
    break;

  case 692:
#line 3794 "fgl.yacc"
    {
		if_print_stack_cnt++;
		if_print_stack[if_print_stack_cnt][0]=0;
		if_print_stack[if_print_stack_cnt][1]=0;
		if_print_section[if_print_stack_cnt]=0;
		print_if_start();
	}
    break;

  case 693:
#line 3801 "fgl.yacc"
    {
		if_print_section[if_print_stack_cnt]=1;
	}
    break;

  case 694:
#line 3803 "fgl.yacc"
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
#line 3822 "fgl.yacc"
    {
		print_if_else();
	}
    break;

  case 698:
#line 3825 "fgl.yacc"
    {
		print_if_else();
		}
    break;

  case 699:
#line 3827 "fgl.yacc"
    {

		print_if_start();
	}
    break;

  case 700:
#line 3830 "fgl.yacc"
    {
		print_if_end();
	}
    break;

  case 701:
#line 3834 "fgl.yacc"
    {
		print_import(yyvsp[-3].str,atoi(yyvsp[-1].str));
	}
    break;

  case 702:
#line 3837 "fgl.yacc"
    {
		print_import_legacy(yyvsp[0].str);
	}
    break;

  case 703:
#line 3843 "fgl.yacc"
    { add_ex_dtype(yyvsp[0].str); }
    break;

  case 704:
#line 3854 "fgl.yacc"
    {A4GL_debug("init to\n");}
    break;

  case 705:
#line 3855 "fgl.yacc"
    {
	print_init();
 }
    break;

  case 706:
#line 3858 "fgl.yacc"
    {
	print_init_table(yyvsp[0].str);
}
    break;

  case 708:
#line 3864 "fgl.yacc"
    {sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 709:
#line 3868 "fgl.yacc"
    {setrecord(yyval.str,yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 710:
#line 3869 "fgl.yacc"
    {setrecord(yyval.str,yyvsp[-2].str,0);}
    break;

  case 711:
#line 3873 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 715:
#line 3888 "fgl.yacc"
    {
sprintf(yyval.str,"0");
}
    break;

  case 716:
#line 3890 "fgl.yacc"
    {
sprintf(yyval.str,"1");
}
    break;

  case 719:
#line 3899 "fgl.yacc"
    {
		A4GL_add_event(-97,field_name_list_as_or_char(yyvsp[0].field_list));
		print_befaft_field_1(field_name_list_as_or_char(yyvsp[0].field_list));
}
    break;

  case 720:
#line 3902 "fgl.yacc"
    {
	print_befaft_field_2();
}
    break;

  case 721:
#line 3906 "fgl.yacc"
    {
		A4GL_add_event(-98,field_name_list_as_or_char(yyvsp[0].field_list));
		print_befaft_field_1(field_name_list_as_or_char(yyvsp[0].field_list));
}
    break;

  case 722:
#line 3909 "fgl.yacc"
    {
	print_befaft_field_2();
}
    break;

  case 723:
#line 3912 "fgl.yacc"
    {
		A4GL_add_event(-11,"");
		print_befaft_field_1("AFT_ROW");
}
    break;

  case 724:
#line 3915 "fgl.yacc"
    {
	print_befaft_field_2();
}
    break;

  case 725:
#line 3918 "fgl.yacc"
    {
		A4GL_add_event(-10,"");
		A4GL_lex_printcomment("/* before row */ \n");
		print_befaft_field_1("BEF_ROW");
}
    break;

  case 726:
#line 3922 "fgl.yacc"
    {
	print_befaft_field_2();
		}
    break;

  case 727:
#line 3925 "fgl.yacc"
    {
	A4GL_add_onkey_key(yyvsp[0].str);
	print_onkey_1(yyvsp[0].str);
}
    break;

  case 728:
#line 3928 "fgl.yacc"
    {
	print_onkey_2();
}
    break;

  case 729:
#line 3931 "fgl.yacc"
    {
		A4GL_add_event(-95,"");
		print_befaft_field_1("AFTER_INP");
}
    break;

  case 730:
#line 3934 "fgl.yacc"
    {
	print_befaft_field_2();
}
    break;

  case 731:
#line 3937 "fgl.yacc"
    {
		A4GL_add_event(-99,"");
		print_befaft_field_1("BEFORE_INP");
}
    break;

  case 732:
#line 3940 "fgl.yacc"
    {
	print_befaft_field_2();
}
    break;

  case 733:
#line 3943 "fgl.yacc"
    {
		A4GL_add_event(-12,"");
		print_befaft_field_1("DO_BEFORE_DELETE");
	}
    break;

  case 734:
#line 3946 "fgl.yacc"
    { print_befaft_field_2(); }
    break;

  case 735:
#line 3947 "fgl.yacc"
    { A4GL_add_event(-14,""); print_befaft_field_1("DO_BEFORE_INSERT"); }
    break;

  case 736:
#line 3947 "fgl.yacc"
    { print_befaft_field_2(); }
    break;

  case 737:
#line 3948 "fgl.yacc"
    { A4GL_add_event(-17,""); print_befaft_field_1("DO_BEFORE_INSERT_DELETE"); }
    break;

  case 738:
#line 3948 "fgl.yacc"
    { print_befaft_field_2(); }
    break;

  case 739:
#line 3949 "fgl.yacc"
    { A4GL_add_event(-18,""); print_befaft_field_1("DO_AFTER_INSERT_DELETE"); }
    break;

  case 740:
#line 3949 "fgl.yacc"
    { print_befaft_field_2(); }
    break;

  case 741:
#line 3950 "fgl.yacc"
    {
		A4GL_add_event(-13,"");
		print_befaft_field_1("DO_AFTER_DELETE");
	}
    break;

  case 742:
#line 3953 "fgl.yacc"
    { print_befaft_field_2(); }
    break;

  case 743:
#line 3954 "fgl.yacc"
    {
		A4GL_add_event(-15,"");
		print_befaft_field_1("DO_AFTER_INSERT");
	}
    break;

  case 744:
#line 3957 "fgl.yacc"
    { print_befaft_field_2(); }
    break;

  case 745:
#line 3965 "fgl.yacc"
    {
                        yyval.field_list=new_field_list();
                        yyval.field_list=append_field_to_list(yyval.field_list,yyvsp[0].field_entry);
        }
    break;

  case 746:
#line 3969 "fgl.yacc"
    {
                        yyval.field_list=append_field_to_list(yyvsp[-2].field_list,yyvsp[0].field_entry);
        }
    break;

  case 747:
#line 3975 "fgl.yacc"
    {
                        yyval.field_list=new_field_list();
                        yyval.field_list=append_field_to_list(yyval.field_list,yyvsp[0].field_entry);
        }
    break;

  case 748:
#line 3979 "fgl.yacc"
    {
                        yyval.field_list=append_field_to_list(yyvsp[-2].field_list,yyvsp[0].field_entry);
        }
    break;

  case 749:
#line 3984 "fgl.yacc"
    {
print_next_field(yyvsp[0].str);
}
    break;

  case 750:
#line 3989 "fgl.yacc"
    {
print_next_form_field(yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 751:
#line 3994 "fgl.yacc"
    {sprintf(yyval.str,"\"+\"");}
    break;

  case 752:
#line 3995 "fgl.yacc"
    {sprintf(yyval.str,"\"-\"");}
    break;

  case 753:
#line 3996 "fgl.yacc"
    {sprintf(yyval.str,field_name_as_char(yyvsp[0].field_entry));}
    break;

  case 754:
#line 4000 "fgl.yacc"
    {
print_input_1();
  A4GL_new_events();
}
    break;

  case 755:
#line 4004 "fgl.yacc"
    {
print_input_2(yyvsp[-2].str);
A4GL_drop_events();
}
    break;

  case 756:
#line 4013 "fgl.yacc"
    {
print_input(1,yyvsp[-2].str,yyvsp[-1].str,0,atoi(yyvsp[0].str));
strcpy(yyval.str,A4GL_get_formloop_str(0));
}
    break;

  case 757:
#line 4018 "fgl.yacc"
    {
print_input(0,yyvsp[-4].str,yyvsp[-1].str,field_name_list_as_char(yyvsp[-2].field_list),atoi(yyvsp[0].str));
strcpy(yyval.str,A4GL_get_formloop_str(0));
}
    break;

  case 758:
#line 4022 "fgl.yacc"
    {
curr_input_array_attribs.maxcount=0;
curr_input_array_attribs.count=0;
curr_input_array_attribs.allow_insert=1;
curr_input_array_attribs.allow_delete=1;
curr_input_array_attribs.curr_row_display=0;
inp_flags=0;}
    break;

  case 759:
#line 4029 "fgl.yacc"
    {
strcpy(yyval.str,print_input_array(fgl_add_scope(yyvsp[-8].str,0),yyvsp[-2].str,yyvsp[-7].str,yyvsp[-5].str,yyvsp[0].str,&curr_input_array_attribs));
}
    break;

  case 760:
#line 4038 "fgl.yacc"
    {
		print_scroll(field_name_list_as_char(yyvsp[-1].field_list),yyvsp[0].str);
	}
    break;

  case 761:
#line 4044 "fgl.yacc"
    {sprintf(yyval.str,"%s",yyvsp[0].str);}
    break;

  case 762:
#line 4045 "fgl.yacc"
    {sprintf(yyval.str,"-%s",yyvsp[0].str);}
    break;

  case 763:
#line 4046 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 764:
#line 4047 "fgl.yacc"
    {strcpy(yyval.str,"-1");}
    break;

  case 765:
#line 4050 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 767:
#line 4053 "fgl.yacc"
    {
	strcpy(yyval.str,"");
}
    break;

  case 768:
#line 4060 "fgl.yacc"
    { curr_input_array_attribs.curr_row_display=strdup(yyvsp[0].str); }
    break;

  case 769:
#line 4061 "fgl.yacc"
    { curr_input_array_attribs.count=strdup(yyvsp[0].str); }
    break;

  case 770:
#line 4062 "fgl.yacc"
    { curr_input_array_attribs.count=strdup(yyvsp[0].str); }
    break;

  case 771:
#line 4063 "fgl.yacc"
    { curr_input_array_attribs.maxcount=strdup(yyvsp[0].str); }
    break;

  case 772:
#line 4064 "fgl.yacc"
    { curr_input_array_attribs.maxcount=strdup(yyvsp[0].str); }
    break;

  case 773:
#line 4065 "fgl.yacc"
    { curr_input_array_attribs.allow_insert=1; }
    break;

  case 774:
#line 4066 "fgl.yacc"
    { curr_input_array_attribs.allow_insert=0; }
    break;

  case 775:
#line 4067 "fgl.yacc"
    { curr_input_array_attribs.allow_delete=1; }
    break;

  case 776:
#line 4068 "fgl.yacc"
    { curr_input_array_attribs.allow_delete=0; }
    break;

  case 777:
#line 4073 "fgl.yacc"
    {iskey=1;}
    break;

  case 778:
#line 4073 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);iskey=0;}
    break;

  case 779:
#line 4075 "fgl.yacc"
    {strcpy(yyval.str,"->ANY");}
    break;

  case 780:
#line 4078 "fgl.yacc"
    {iskey=1;}
    break;

  case 781:
#line 4078 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);iskey=0;}
    break;

  case 782:
#line 4080 "fgl.yacc"
    {sprintf(yyval.str,"A4GL_key_val(\"%s\")",yyvsp[0].str);iskey=0;}
    break;

  case 783:
#line 4084 "fgl.yacc"
    {sprintf(yyval.str,"A4GL_key_val(\"%s\")",yyvsp[0].str);iskey=0;}
    break;

  case 784:
#line 4087 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 785:
#line 4088 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[-1].str);}
    break;

  case 787:
#line 4091 "fgl.yacc"
    {
	sprintf(yyval.str,"%s||%s",yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 793:
#line 4103 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 794:
#line 4104 "fgl.yacc"
    {strcpy(yyval.str,"escape");}
    break;

  case 795:
#line 4105 "fgl.yacc"
    {strcpy(yyval.str,"up");}
    break;

  case 796:
#line 4106 "fgl.yacc"
    {strcpy(yyval.str,"help");}
    break;

  case 797:
#line 4107 "fgl.yacc"
    {strcpy(yyval.str,"down");}
    break;

  case 798:
#line 4108 "fgl.yacc"
    {strcpy(yyval.str,"return");}
    break;

  case 799:
#line 4109 "fgl.yacc"
    {strcpy(yyval.str,"delete");}
    break;

  case 800:
#line 4110 "fgl.yacc"
    {strcpy(yyval.str,"insert");}
    break;

  case 801:
#line 4111 "fgl.yacc"
    {strcpy(yyval.str,"tab");}
    break;

  case 802:
#line 4112 "fgl.yacc"
    {strcpy(yyval.str,"left");}
    break;

  case 803:
#line 4113 "fgl.yacc"
    {strcpy(yyval.str,"right");}
    break;

  case 804:
#line 4114 "fgl.yacc"
    {strcpy(yyval.str,"nextpage");}
    break;

  case 805:
#line 4115 "fgl.yacc"
    {strcpy(yyval.str,"prevpage");}
    break;

  case 806:
#line 4116 "fgl.yacc"
    { rm_quotes(yyvsp[0].str); strcpy(yyval.str,yyvsp[0].str); }
    break;

  case 807:
#line 4120 "fgl.yacc"
    {
char buff[256];
A4GL_debug("Label : %s\n",get_idents(0));
strcpy(buff,get_idents(0));
A4GL_convlower(buff);
print_label(buff);
}
    break;

  case 808:
#line 4138 "fgl.yacc"
    {chk4var=1;}
    break;

  case 809:
#line 4138 "fgl.yacc"
    {chk4var=0;
expand_obind();
A4GL_lex_printcomment("/*let3*/\n");}
    break;

  case 810:
#line 4141 "fgl.yacc"
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

  case 811:
#line 4165 "fgl.yacc"
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

  case 813:
#line 4183 "fgl.yacc"
    {
		if (!print_linked_cmd('S',yyvsp[0].str)) a4gl_yyerror("Not a linked variable");
	}
    break;

  case 814:
#line 4189 "fgl.yacc"
    {
		 if (!print_linked_cmd('D',yyvsp[0].str)) a4gl_yyerror("Not a linked variable");
	}
    break;

  case 815:
#line 4195 "fgl.yacc"
    {
		 if (!print_linked_cmd('U',yyvsp[0].str)) a4gl_yyerror("Not a linked variable");
}
    break;

  case 816:
#line 4201 "fgl.yacc"
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

  case 817:
#line 4213 "fgl.yacc"
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

  case 818:
#line 4238 "fgl.yacc"
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

  case 821:
#line 4254 "fgl.yacc"
    {
	}
    break;

  case 830:
#line 4279 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 834:
#line 4287 "fgl.yacc"
    {
		print_at_termination(yyvsp[0].str);
	}
    break;

  case 849:
#line 4313 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 850:
#line 4314 "fgl.yacc"
    {
strcpy(yyval.str,"static ");
}
    break;

  case 851:
#line 4322 "fgl.yacc"
    {
  clr_variable(); lastlineno=yylineno;
  clr_function_constants (); 
}
    break;

  case 852:
#line 4327 "fgl.yacc"
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

  case 853:
#line 4343 "fgl.yacc"
    {
  A4GL_lex_printcomment("/* new function %s parameters*/\n",yyvsp[-1].str);
  push_blockcommand("FUNC");
  A4GL_lex_printcomment("/* define section */\n");
}
    break;

  case 854:
#line 4349 "fgl.yacc"
    {
  int c;
  A4GL_lex_printcomment("/*end of define section */\n");
	print_variables();
  c=print_param('f');
  printPushFunction();
  print_func_args(c);
}
    break;

  case 856:
#line 4364 "fgl.yacc"
    {
    printPopFunction();
    print_func_defret0();
    pop_blockcommand("FUNC");
    print_func_end();
    clr_function_constants ();
    A4GL_lex_printcomment("/*end function*/\n");
  }
    break;

  case 857:
#line 4377 "fgl.yacc"
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

  case 858:
#line 4387 "fgl.yacc"
    {
	print_variables();
    printDeclareFunctionStack("MAIN");
    print_fgllib_start(hdr_dbname);
    printInitFunctionStack();
    printPushFunction();
  }
    break;

  case 859:
#line 4394 "fgl.yacc"
    {
pop_blockcommand("MAIN");
print_main_end();
A4GL_lex_printcomment("/*end main */\n");}
    break;

  case 860:
#line 4401 "fgl.yacc"
    {
    printPopFunction();
    print_return(atoi(yyvsp[0].str));
  }
    break;

  case 861:
#line 4407 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 862:
#line 4407 "fgl.yacc"
    {
A4GL_lex_printcomment("/* Got expr list */");
sprintf(yyval.str,"%s",yyvsp[0].str);}
    break;

  case 863:
#line 4412 "fgl.yacc"
    {
					open_db(yyvsp[0].str);
					strcpy(hdr_dbname,yyvsp[0].str);
					lastlineno=yylineno;
					is_schema=0;
			}
    break;

  case 864:
#line 4418 "fgl.yacc"
    {
					open_db(yyvsp[0].str);
					strcpy(hdr_dbname,yyvsp[0].str);
					lastlineno=yylineno;
					is_schema=1;
			}
    break;

  case 865:
#line 4426 "fgl.yacc"
    {
}
    break;

  case 869:
#line 4438 "fgl.yacc"
    {
strcpy(curr_func,"[Globals]");
set_current_variable_scope('g');
A4GL_lex_printcomment("/* start of globals */\n");
}
    break;

  case 871:
#line 4446 "fgl.yacc"
    {
 A4GL_lex_printcomment("/* end of globals */");
	A4GL_debug("end of globals\n");
	lastlineno=yylineno;
	set_current_variable_scope('m');
}
    break;

  case 872:
#line 4452 "fgl.yacc"
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

  case 875:
#line 4468 "fgl.yacc"
    {
  addmap("Define Member Function",curr_func,"MODULE",yylineno,infilename);
}
    break;

  case 876:
#line 4472 "fgl.yacc"
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

  case 877:
#line 4485 "fgl.yacc"
    {
	print_variables();
  A4GL_lex_printcomment("/*end of define section */\n");
  print_param('f');
  printPushFunction();
  print_func_args(atoi(yyvsp[-3].str));
}
    break;

  case 879:
#line 4503 "fgl.yacc"
    {
	start_state("menu",1);
   	menu_cnt=npush_menu();
   	menu_cmd_cnt[menu_cnt]=1;
   	push_blockcommand("MENU");
        menu_blk[menu_cnt]=get_blk_no();
	do_print_menu_1();
	}
    break;

  case 880:
#line 4511 "fgl.yacc"
    {
	start_state("menu",0);
	}
    break;

  case 881:
#line 4517 "fgl.yacc"
    {
   print_end_menu_1(menu_blk[menu_cnt]);
   add_continue_blockcommand ("MENU");
print_end_menu_2(menu_blk[menu_cnt]);
   pop_blockcommand("MENU");
   pop_menu();
}
    break;

  case 882:
#line 4528 "fgl.yacc"
    {
	 A4GL_lex_printcomment("/* Block%d_m2 (Before menu) */",menu_cnt);
		print_menu_block(menu_blk[menu_cnt],-2) ;
                  }
    break;

  case 883:
#line 4532 "fgl.yacc"
    {
		do_print_menu_block_end();
	}
    break;

  case 884:
#line 4539 "fgl.yacc"
    {
A4GL_debug("Menu=%d menu cnt=%d",menu_cnt,menu_cmd_cnt[menu_cnt]);
		push_command(menu_cnt,menu_cmd_cnt[menu_cnt],yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);
	 A4GL_lex_printcomment("/* Block%d_%d */",menu_cnt,menu_cmd_cnt[menu_cnt]-1);
		print_menu_block(menu_blk[menu_cnt],menu_cmd_cnt[menu_cnt]-1);
		menu_cmd_cnt[menu_cnt]++;
		}
    break;

  case 885:
#line 4546 "fgl.yacc"
    {
		do_print_menu_block_end();
}
    break;

  case 886:
#line 4552 "fgl.yacc"
    {
		push_command(menu_cnt,menu_cmd_cnt[menu_cnt],yyvsp[-1].str,"\"\"","\"\"",0);
		print_menu_block(menu_blk[menu_cnt],menu_cmd_cnt[menu_cnt]-1);
		menu_cmd_cnt[menu_cnt]++;
		}
    break;

  case 887:
#line 4557 "fgl.yacc"
    {
		do_print_menu_block_end();
}
    break;

  case 890:
#line 4564 "fgl.yacc"
    {strcpy(yyval.str,"\"EMPTY\"");}
    break;

  case 891:
#line 4565 "fgl.yacc"
    {sprintf(yyval.str,"\"%s\"",yyvsp[0].str);}
    break;

  case 892:
#line 4567 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str); }
    break;

  case 893:
#line 4568 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 894:
#line 4571 "fgl.yacc"
    {strcpy(yyval.str,"\"\"");}
    break;

  case 895:
#line 4572 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 896:
#line 4573 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 897:
#line 4575 "fgl.yacc"
    {
	print_option_op('N',yyvsp[0].str,menu_blk[menu_cnt]);
}
    break;

  case 898:
#line 4580 "fgl.yacc"
    {
	print_option_op('S',yyvsp[0].str,menu_blk[menu_cnt]);
}
    break;

  case 899:
#line 4585 "fgl.yacc"
    {
	print_option_op('H',yyvsp[0].str,menu_blk[menu_cnt]);
}
    break;

  case 900:
#line 4592 "fgl.yacc"
    {sprintf(yyval.str,"MENU_ALL");}
    break;

  case 904:
#line 4599 "fgl.yacc"
    {sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 905:
#line 4601 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);  
push_menu_title(yyval.str);}
    break;

  case 906:
#line 4603 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str); 
push_menu_title(yyval.str);}
    break;

  case 907:
#line 4611 "fgl.yacc"
    {
                strcpy(menuhandler,yyvsp[0].str);
	sprintf(curr_func,"%s",yyvsp[0].str); 
	print_gtk_menuhandler_1(yyvsp[0].str);
                push_blockcommand("MENUH");
}
    break;

  case 908:
#line 4617 "fgl.yacc"
    {
		print_variables();
        }
    break;

  case 909:
#line 4621 "fgl.yacc"
    {
                        pop_blockcommand("MENUH");
			print_gtk_menuhandler_end();
                }
    break;

  case 912:
#line 4633 "fgl.yacc"
    {
		print_gtk_menuhandler_bsm();
                push_blockcommand("BSM");
        }
    break;

  case 913:
#line 4636 "fgl.yacc"
    {
                pop_blockcommand("BSM");
		print_gtk_menuhandler_bsm_end();
        }
    break;

  case 914:
#line 4640 "fgl.yacc"
    {
		print_gtk_menuhandler_on(yyvsp[0].str);
                push_blockcommand("ON");
        }
    break;

  case 915:
#line 4643 "fgl.yacc"
    {
                pop_blockcommand("ON");
		print_gtk_menuhandler_on_end();
}
    break;

  case 917:
#line 4652 "fgl.yacc"
    {
		print_message(0,"0",0,message_cnt);
	   }
    break;

  case 918:
#line 4655 "fgl.yacc"
    { 
		print_message(0,yyvsp[-1].str,atoi(yyvsp[0].str),message_cnt);
	  }
    break;

  case 919:
#line 4658 "fgl.yacc"
    { 
		print_message(0,"0",atoi(yyvsp[0].str),message_cnt);
	  }
    break;

  case 926:
#line 4674 "fgl.yacc"
    {
		strcpy(yyval.str,yyvsp[0].str);
		message_cnt=atoi(yyvsp[0].str);
		}
    break;

  case 927:
#line 4679 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 928:
#line 4679 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 929:
#line 4682 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 930:
#line 4710 "fgl.yacc"
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

  case 932:
#line 4767 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 934:
#line 4774 "fgl.yacc"
    { 
         sprintf (yyval.str, "%s.%s", yyvsp[-1].str, yyvsp[0].str); 
         A4GL_lex_printcomment("/* record building -> %s */\n",yyval.str);
         }
    break;

  case 935:
#line 4778 "fgl.yacc"
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

  case 936:
#line 4821 "fgl.yacc"
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

  case 940:
#line 4869 "fgl.yacc"
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

  case 941:
#line 4883 "fgl.yacc"
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

  case 946:
#line 4907 "fgl.yacc"
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

  case 947:
#line 4971 "fgl.yacc"
    {
	 A4GL_debug("---> Subscript or substring");
		strcpy(yyval.str,yyvsp[-1].str);
	}
    break;

  case 948:
#line 4976 "fgl.yacc"
    {
	 A4GL_debug("---> Subscript & substring");
		sprintf(yyval.str,"%s:%s",yyvsp[-4].str,yyvsp[-1].str);
	}
    break;

  case 949:
#line 4984 "fgl.yacc"
    {
A4GL_debug("List element");
  sprintf (yyval.str, "%s", yyvsp[0].str);
}
    break;

  case 950:
#line 4989 "fgl.yacc"
    {
A4GL_debug("List element continues");
  sprintf (yyval.str, "%s,%s", yyvsp[-2].str, yyvsp[0].str); 
}
    break;

  case 951:
#line 4997 "fgl.yacc"
    {
  sprintf (yyval.str, "%s", yyvsp[0].str);
}
    break;

  case 952:
#line 5003 "fgl.yacc"
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

  case 953:
#line 5035 "fgl.yacc"
    {
	 A4GL_debug("Array..");
}
    break;

  case 954:
#line 5038 "fgl.yacc"
    { sprintf (yyval.str, "%s.%s", yyvsp[-2].str, yyvsp[0].str); }
    break;

  case 955:
#line 5040 "fgl.yacc"
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

  case 956:
#line 5081 "fgl.yacc"
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

  case 961:
#line 5134 "fgl.yacc"
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

  case 962:
#line 5186 "fgl.yacc"
    {
		start_bind('f',0);
		/*start_bind('O',0);*/
		strcpy(yyval.str,"0");
		}
    break;

  case 964:
#line 5195 "fgl.yacc"
    {
				start_bind('f',yyvsp[0].str);
				start_bind('O',0);
				sprintf(yyval.str,"1");
			}
    break;

  case 965:
#line 5200 "fgl.yacc"
    {
				int c;
				c=add_bind('f',yyvsp[0].str);
				/*c=add_bind('O',$<str>3); */
				sprintf(yyval.str,"%d",c); 
			}
    break;

  case 966:
#line 5211 "fgl.yacc"
    {
A4GL_lex_printcomment("/*STarted bind %s*/\n",yyvsp[0].str);
start_bind('i',yyvsp[0].str);
A4GL_lex_printcomment("/*STarted bind 2*/\n");
strcpy(yyval.str,"");
}
    break;

  case 967:
#line 5218 "fgl.yacc"
    {
A4GL_lex_printcomment("/* Added */\n");
add_bind('i',yyvsp[0].str);
strcpy(yyval.str,"");
}
    break;

  case 969:
#line 5226 "fgl.yacc"
    {sprintf(yyval.str,"%s.%s",yyvsp[-2].str,yyvsp[-1].str);}
    break;

  case 970:
#line 5229 "fgl.yacc"
    {A4GL_lex_printcomment("/* Variable */\n");}
    break;

  case 971:
#line 5230 "fgl.yacc"
    { A4GL_debug("Got an ibind thru..."); sprintf(yyval.str,"%s\n%s",yyvsp[-2].str,yyvsp[0].str); }
    break;

  case 973:
#line 5232 "fgl.yacc"
    {sprintf(yyval.str,"\"%s\"",yyvsp[0].str);}
    break;

  case 974:
#line 5233 "fgl.yacc"
    {sprintf(yyval.str,"\"%s\"",yyvsp[0].str);}
    break;

  case 975:
#line 5236 "fgl.yacc"
    {
start_bind('o',yyvsp[0].str);
}
    break;

  case 976:
#line 5239 "fgl.yacc"
    {
add_bind('o',yyvsp[0].str);
strcpy(yyval.str,"");
}
    break;

  case 977:
#line 5245 "fgl.yacc"
    {
	addmap("OBIND",yyvsp[0].str,curr_func,yylineno,infilename);
	}
    break;

  case 978:
#line 5248 "fgl.yacc"
    { A4GL_debug("Got an obind thru..."); sprintf(yyval.str,"%s\n%s",yyvsp[-2].str,yyvsp[0].str); }
    break;

  case 979:
#line 5252 "fgl.yacc"
    {
A4GL_lex_printcomment("/* start obind with  %s*/\n",yyvsp[0].str);
A4GL_debug("obind_var_let_list ---> %s\n",yyvsp[0].str);
start_bind('o',yyvsp[0].str);
}
    break;

  case 980:
#line 5257 "fgl.yacc"
    {
A4GL_lex_printcomment("/* add to obind %s */\n",yyvsp[0].str);
add_bind('o',yyvsp[0].str);
A4GL_debug("obind_var_let_list ---> %s\n",yyvsp[0].str);
strcpy(yyval.str,"");
}
    break;

  case 981:
#line 5265 "fgl.yacc"
    {
A4GL_lex_printcomment("/* Read variable %s*/\n",yyvsp[0].str);
}
    break;

  case 982:
#line 5270 "fgl.yacc"
    {
    A4GL_lex_printcomment("/* use_arr_var */\n");
    start_arr_bind('o',yyvsp[0].str);
    A4GL_lex_printcomment("/* use_arr_var complete */\n");
}
    break;

  case 983:
#line 5277 "fgl.yacc"
    {
		start_bind('O',yyvsp[0].str);
	}
    break;

  case 984:
#line 5279 "fgl.yacc"
    {
               add_bind('O',yyvsp[0].str);
               strcpy(yyval.str,"");
	}
    break;

  case 989:
#line 5311 "fgl.yacc"
    {
A4GL_lex_printcomment("/*STarted bind %s*/\n",yyvsp[0].str);
start_bind('N',yyvsp[0].str);
A4GL_lex_printcomment("/*STarted bind 2*/\n");
strcpy(yyval.str,"");
}
    break;

  case 990:
#line 5318 "fgl.yacc"
    {
A4GL_lex_printcomment("/* Added */\n");
add_bind('N',yyvsp[0].str);
strcpy(yyval.str,"");
}
    break;

  case 991:
#line 5325 "fgl.yacc"
    {
		strcpy(yyval.str,yyvsp[0].str);
	}
    break;

  case 992:
#line 5328 "fgl.yacc"
    {
			sprintf(yyval.str,"%s\n%s",yyvsp[-2].str,yyvsp[0].str);
		}
    break;

  case 993:
#line 5342 "fgl.yacc"
    {
form_attrib.iswindow=1;
print_open_window(yyvsp[-5].str,yyvsp[-1].str);
sprintf(yyval.str,"open window");
}
    break;

  case 998:
#line 5359 "fgl.yacc"
    {
	print_niy("OPEN_STATUSBOX");
}
    break;

  case 999:
#line 5364 "fgl.yacc"
    {
addmap("Call Formhandler",yyvsp[0].str,curr_func,yylineno,infilename); 
}
    break;

  case 1000:
#line 5370 "fgl.yacc"
    {
		print_open_form(yyvsp[0].str,yyvsp[-1].str,yyvsp[-1].str);
		}
    break;

  case 1002:
#line 5377 "fgl.yacc"
    { form_attrib.iswindow=0;strcpy(yyval.str,"A4GL_open_form(%s);"); }
    break;

  case 1003:
#line 5382 "fgl.yacc"
    {sprintf(yyval.str,"A4GL_open_gui_form(&%%s,%%s,%s,%s,%s,hnd_e_%s,hnd_c_%s);",yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[0].str,yyvsp[0].str);}
    break;

  case 1004:
#line 5385 "fgl.yacc"
    {strcpy(yyval.str,"0,0");}
    break;

  case 1005:
#line 5386 "fgl.yacc"
    {sprintf(yyval.str,"%s,2",yyvsp[-5].str);}
    break;

  case 1006:
#line 5389 "fgl.yacc"
    {strcpy(yyval.str,"\"\"");}
    break;

  case 1007:
#line 5390 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1008:
#line 5393 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 1009:
#line 5394 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 1010:
#line 5399 "fgl.yacc"
    {
print_open_session(yyvsp[-3].str,yyvsp[-1].str,yyvsp[0].str);

}
    break;

  case 1011:
#line 5406 "fgl.yacc"
    {
	print_open_cursor(yyvsp[0].str,"0");
}
    break;

  case 1012:
#line 5409 "fgl.yacc"
    {
	print_open_cursor(yyvsp[-3].str,yyvsp[0].str); /* CHANGED from $<str>4 */
}
    break;

  case 1013:
#line 5415 "fgl.yacc"
    {sprintf(yyval.str,"0,0");}
    break;

  case 1014:
#line 5417 "fgl.yacc"
    {sprintf(yyval.str,"%s, %s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1015:
#line 5419 "fgl.yacc"
    {sprintf(yyval.str,"%s, %s",yyvsp[-3].str,yyvsp[0].str);}
    break;

  case 1016:
#line 5421 "fgl.yacc"
    {sprintf(yyval.str,"%s, %s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1017:
#line 5424 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 1018:
#line 5424 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 1019:
#line 5425 "fgl.yacc"
    {strcpy(yyval.str,"2");}
    break;

  case 1020:
#line 5430 "fgl.yacc"
    {
	print_open_session(yyvsp[-1].str,yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 1021:
#line 5438 "fgl.yacc"
    {strcpy(yyval.str,"\"default_conn\"");}
    break;

  case 1022:
#line 5439 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1023:
#line 5444 "fgl.yacc"
    {sprintf(yyval.str,"0,0");}
    break;

  case 1024:
#line 5446 "fgl.yacc"
    {sprintf(yyval.str,"%s, %s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1025:
#line 5448 "fgl.yacc"
    {sprintf(yyval.str,"%s, %s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1029:
#line 5466 "fgl.yacc"
    { print_options('C',yyvsp[0].str); }
    break;

  case 1030:
#line 5467 "fgl.yacc"
    { print_options('E',yyvsp[0].str); }
    break;

  case 1031:
#line 5468 "fgl.yacc"
    { print_options('F',yyvsp[0].str); }
    break;

  case 1032:
#line 5469 "fgl.yacc"
    { print_options('M',yyvsp[0].str); }
    break;

  case 1033:
#line 5470 "fgl.yacc"
    { print_options('m',yyvsp[0].str); }
    break;

  case 1034:
#line 5471 "fgl.yacc"
    { print_options('P',yyvsp[0].str); }
    break;

  case 1035:
#line 5472 "fgl.yacc"
    { print_options('A',yyvsp[0].str); iskey=0; }
    break;

  case 1036:
#line 5473 "fgl.yacc"
    { print_options('D',yyvsp[0].str); iskey=0; }
    break;

  case 1037:
#line 5474 "fgl.yacc"
    { print_options('I',yyvsp[0].str); iskey=0; }
    break;

  case 1038:
#line 5475 "fgl.yacc"
    { print_options('N',yyvsp[0].str); }
    break;

  case 1039:
#line 5476 "fgl.yacc"
    { print_options('p',yyvsp[0].str); iskey=0; }
    break;

  case 1040:
#line 5477 "fgl.yacc"
    { print_options('H',yyvsp[0].str); }
    break;

  case 1041:
#line 5478 "fgl.yacc"
    { print_set_helpfile(yyvsp[0].str); }
    break;

  case 1042:
#line 5479 "fgl.yacc"
    { print_set_langfile(yyvsp[0].str); }
    break;

  case 1043:
#line 5480 "fgl.yacc"
    { print_options('Z',"1"); }
    break;

  case 1044:
#line 5481 "fgl.yacc"
    { print_options('Z',"2"); }
    break;

  case 1045:
#line 5482 "fgl.yacc"
    { print_options('Y',"1"); }
    break;

  case 1046:
#line 5483 "fgl.yacc"
    { print_options('Y',"2"); }
    break;

  case 1047:
#line 5484 "fgl.yacc"
    { print_options('d',yyvsp[0].str);print_options('Z',"0"); }
    break;

  case 1048:
#line 5485 "fgl.yacc"
    { print_options('i',yyvsp[0].str); print_options('Y',"0");}
    break;

  case 1049:
#line 5486 "fgl.yacc"
    { print_options('W',"1"); }
    break;

  case 1050:
#line 5487 "fgl.yacc"
    { print_options('W',"0"); }
    break;

  case 1051:
#line 5488 "fgl.yacc"
    { print_options('f',"1"); }
    break;

  case 1052:
#line 5489 "fgl.yacc"
    { print_options('f',"0"); }
    break;

  case 1053:
#line 5490 "fgl.yacc"
    { print_options('S',"1"); }
    break;

  case 1054:
#line 5491 "fgl.yacc"
    { print_options('S',"0"); }
    break;

  case 1055:
#line 5506 "fgl.yacc"
    {
	print_prepare(yyvsp[-2].str,yyvsp[0].str);
	addmap("Prepare",yyvsp[-2].str,curr_func,yylineno,infilename);
	print_undo_use(yyvsp[-4].str);
}
    break;

  case 1058:
#line 5515 "fgl.yacc"
    {
		print_execute(yyvsp[0].str,0);
		addmap("Execute",yyvsp[0].str,curr_func,yylineno,infilename);
		}
    break;

  case 1059:
#line 5519 "fgl.yacc"
    {
		addmap("Execute",yyvsp[-2].str,curr_func,yylineno,infilename);
		print_execute(yyvsp[-2].str,1);
	}
    break;

  case 1060:
#line 5523 "fgl.yacc"
    {
		addmap("Execute",yyvsp[-2].str,curr_func,yylineno,infilename);
		print_execute(yyvsp[-2].str,2);
	}
    break;

  case 1061:
#line 5527 "fgl.yacc"
    {
		addmap("Execute",yyvsp[-4].str,curr_func,yylineno,infilename);
		print_execute(yyvsp[-4].str,3);
	}
    break;

  case 1062:
#line 5531 "fgl.yacc"
    {
		print_execute_immediate(yyvsp[0].str);
	}
    break;

  case 1064:
#line 5551 "fgl.yacc"
    {
                push_blockcommand("PROMPT");
	A4GL_new_events();
	print_prompt_1(yyvsp[-6].str,yyvsp[-4].str,yyvsp[-1].str,yyvsp[0].str,atoi(yyvsp[-2].str)) ;
}
    break;

  case 1065:
#line 5556 "fgl.yacc"
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

  case 1066:
#line 5569 "fgl.yacc"
    {sprintf(yyval.str,"0");}
    break;

  case 1067:
#line 5570 "fgl.yacc"
    {sprintf(yyval.str,yyvsp[0].str);}
    break;

  case 1068:
#line 5574 "fgl.yacc"
    {
		print_niy("GUI PROMPT");
	}
    break;

  case 1069:
#line 5579 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 1070:
#line 5580 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 1071:
#line 5584 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1075:
#line 5590 "fgl.yacc"
    {
	A4GL_add_onkey_key(yyvsp[0].str);
	print_onkey_1(yyvsp[0].str);
}
    break;

  case 1076:
#line 5593 "fgl.yacc"
    {
	print_onkey_2_prompt();
}
    break;

  case 1078:
#line 5608 "fgl.yacc"
    {
		start_bind('i',0);
		}
    break;

  case 1079:
#line 5612 "fgl.yacc"
    {
		print_put(yyvsp[-2].str,yyvsp[0].str);
	}
    break;

  case 1080:
#line 5618 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1081:
#line 5619 "fgl.yacc"
    { strcpy(yyval.str,yyvsp[0].str);
A4GL_debug("putlist = %s\n",yyval.str);
}
    break;

  case 1082:
#line 5624 "fgl.yacc"
    {push_gen(PUTVAL,yyvsp[0].str);}
    break;

  case 1083:
#line 5625 "fgl.yacc"
    {push_gen(PUTVAL,yyvsp[0].str); sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1084:
#line 5628 "fgl.yacc"
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

  case 1086:
#line 5655 "fgl.yacc"
    {
			addmap("Start Report",yyvsp[-1].str,curr_func,yylineno,infilename);
			print_start_report("P","acl_getenv(\"DBPRINT\")",yyvsp[-1].str);
			}
    break;

  case 1087:
#line 5659 "fgl.yacc"
    {
			addmap("Start Report",yyvsp[-2].str,curr_func,yylineno,infilename);
			print_start_report("F",yyvsp[0].str,yyvsp[-2].str);
			}
    break;

  case 1088:
#line 5663 "fgl.yacc"
    {
			addmap("Start Report",yyvsp[-2].str,curr_func,yylineno,infilename);
			print_start_report("P",yyvsp[0].str,yyvsp[-2].str);
			}
    break;

  case 1089:
#line 5667 "fgl.yacc"
    {
			addmap("Start Report",yyvsp[0].str,curr_func,yylineno,infilename);
			print_start_report("","\"\"",yyvsp[0].str);
			}
    break;

  case 1095:
#line 5685 "fgl.yacc"
    {
		addmap("Output to report",yyvsp[-5].str,curr_func,yylineno,infilename);
		print_output_to_report(yyvsp[-5].str,yyvsp[-1].str); 
		}
    break;

  case 1096:
#line 5691 "fgl.yacc"
    {
		addmap("Finish Report",yyvsp[0].str,curr_func,yylineno,infilename);
		print_finish_report(yyvsp[0].str);
		}
    break;

  case 1097:
#line 5699 "fgl.yacc"
    {
		addmap("Finish Report",yyvsp[0].str,curr_func,yylineno,infilename);
		print_terminate_report(yyvsp[0].str);
}
    break;

  case 1098:
#line 5705 "fgl.yacc"
    { strcpy(yyval.str,yyvsp[0].str); }
    break;

  case 1099:
#line 5707 "fgl.yacc"
    {
	print_format_every_row();
}
    break;

  case 1103:
#line 5717 "fgl.yacc"
    { push_report_block("FIRST",'P');}
    break;

  case 1104:
#line 5717 "fgl.yacc"
    {
		rep_struct.lines_in_first_header=if_print_stack[0][0];
		pdf_rep_struct.lines_in_first_header=if_print_stack[0][0];
		print_rep_ret(0,1);
		}
    break;

  case 1105:
#line 5722 "fgl.yacc"
    { 
		push_report_block("TRAILER",'T');
		if_print_stack[0][0]=0;
		if_print_stack[0][1]=0;
	}
    break;

  case 1106:
#line 5726 "fgl.yacc"
    {
		rep_struct.lines_in_trailer=if_print_stack[0][0];
		pdf_rep_struct.lines_in_trailer=if_print_stack[0][0];
		print_rep_ret(0,1);
	}
    break;

  case 1107:
#line 5731 "fgl.yacc"
    { push_report_block("HEADER",'p');}
    break;

  case 1108:
#line 5731 "fgl.yacc"
    {
		rep_struct.lines_in_header=if_print_stack[0][0];
		pdf_rep_struct.lines_in_header=if_print_stack[0][0];
		print_rep_ret(0,1);}
    break;

  case 1109:
#line 5735 "fgl.yacc"
    { push_report_block("EVERY",'E');}
    break;

  case 1110:
#line 5735 "fgl.yacc"
    {print_rep_ret(0,1);}
    break;

  case 1111:
#line 5736 "fgl.yacc"
    { push_report_block("LAST",'L');}
    break;

  case 1112:
#line 5736 "fgl.yacc"
    {print_rep_ret(0,1);}
    break;

  case 1113:
#line 5737 "fgl.yacc"
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

  case 1114:
#line 5750 "fgl.yacc"
    {print_rep_ret(0,1);}
    break;

  case 1115:
#line 5751 "fgl.yacc"
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

  case 1116:
#line 5767 "fgl.yacc"
    {print_rep_ret(0,1);}
    break;

  case 1123:
#line 5779 "fgl.yacc"
    {start_state("skip",1);}
    break;

  case 1124:
#line 5779 "fgl.yacc"
    {
	print_need_lines();
	start_state("skip",0);
}
    break;

  case 1125:
#line 5785 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 1126:
#line 5785 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 1127:
#line 5788 "fgl.yacc"
    {start_state("KWLINE",1);}
    break;

  case 1128:
#line 5788 "fgl.yacc"
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

  case 1129:
#line 5804 "fgl.yacc"
    { print_skip_top(); }
    break;

  case 1130:
#line 5805 "fgl.yacc"
    { print_niy("FONT SIZE"); }
    break;

  case 1131:
#line 5806 "fgl.yacc"
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

  case 1132:
#line 5815 "fgl.yacc"
    {
			if (rep_type!=REP_TYPE_PDF) {
				a4gl_yyerror("SKIP TO is only in PDF reports");
				YYERROR;
			}
			print_skip_to(yyvsp[0].str);
		}
    break;

  case 1133:
#line 5827 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1139:
#line 5838 "fgl.yacc"
    {
	print_niy("PRINT AT...");
}
    break;

  case 1140:
#line 5843 "fgl.yacc"
    {doing_a_print=1;}
    break;

  case 1141:
#line 5843 "fgl.yacc"
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

  case 1142:
#line 5864 "fgl.yacc"
    { 
	print_report_print_file(yyvsp[-1].str,yyvsp[0].str);
}
    break;

  case 1143:
#line 5869 "fgl.yacc"
    { 
	print_report_print_img(yyvsp[-1].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 1144:
#line 5875 "fgl.yacc"
    { strcpy(yyval.str,A4GL_get_default_scaling());}
    break;

  case 1145:
#line 5876 "fgl.yacc"
    { strcpy(yyval.str,yyvsp[0].str); strcat(yyval.str,yyvsp[0].str); }
    break;

  case 1146:
#line 5877 "fgl.yacc"
    {sprintf(yyval.str,"%s %s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1147:
#line 5881 "fgl.yacc"
    {strcpy(yyval.str,"tiff");}
    break;

  case 1148:
#line 5882 "fgl.yacc"
    {strcpy(yyval.str,"gif");}
    break;

  case 1149:
#line 5883 "fgl.yacc"
    {strcpy(yyval.str,"png");}
    break;

  case 1150:
#line 5884 "fgl.yacc"
    {strcpy(yyval.str,"jpeg");}
    break;

  case 1151:
#line 5888 "fgl.yacc"
    {
	int vtype;
	vtype=scan_variable(yyvsp[0].str);
	if (vtype!=11&&vtype!=12) {
	a4gl_yyerror("Only Blobs may be printed...");
	YYERROR;
	}
}
    break;

  case 1152:
#line 5898 "fgl.yacc"
    {
strcpy(yyval.str,"0");
}
    break;

  case 1153:
#line 5900 "fgl.yacc"
    {
strcpy(yyval.str,"1");
}
    break;

  case 1154:
#line 5905 "fgl.yacc"
    {
	print_report_print(1,0,yyvsp[0].str);
	}
    break;

  case 1155:
#line 5908 "fgl.yacc"
    {
	print_report_print(1,0,yyvsp[0].str); /* changed from $<str>1 */
}
    break;

  case 1156:
#line 5913 "fgl.yacc"
    {
	strcpy(yyval.str,yyvsp[0].str); 
	}
    break;

  case 1157:
#line 5920 "fgl.yacc"
    {
int a;
a=add_report_agg('S',yyvsp[-2].ptr,yyvsp[0].ptr,racnt);
sprintf(yyval.str,"A4GL_push_double(_g%d);\n",racnt);
racnt+=a;
}
    break;

  case 1158:
#line 5927 "fgl.yacc"
    {
int a;
a=add_report_agg('C',0,yyvsp[0].ptr,racnt);
sprintf(yyval.str,"A4GL_push_int(_g%d);\n",racnt);
racnt+=a;
}
    break;

  case 1159:
#line 5934 "fgl.yacc"
    {
int a;
a=add_report_agg('C',0,yyvsp[0].ptr,racnt);
sprintf(yyval.str,"A4GL_push_int(_g%d);\n",racnt);
racnt+=a;
}
    break;

  case 1160:
#line 5943 "fgl.yacc"
    {
int a;
a=add_report_agg('P',yyvsp[-2].ptr,yyvsp[0].ptr,racnt);
sprintf(yyval.str,"A4GL_push_double((double)_g%d/(double)_g%d);\n",racnt,racnt+1);
racnt+=a;
}
    break;

  case 1161:
#line 5950 "fgl.yacc"
    {
int a;
a=add_report_agg('A',yyvsp[-2].ptr,yyvsp[0].ptr,racnt);
sprintf(yyval.str,"A4GL_push_double(_g%d/(double)_g%d);\n",racnt,racnt+1);
racnt+=a;
}
    break;

  case 1162:
#line 5957 "fgl.yacc"
    {
int a;
a=add_report_agg('A',yyvsp[-2].ptr,yyvsp[0].ptr,racnt);
sprintf(yyval.str,"A4GL_push_double(_g%d/_g%d);\n",racnt,racnt+1);
racnt+=a;
}
    break;

  case 1163:
#line 5964 "fgl.yacc"
    {
int a;
a=add_report_agg('N',yyvsp[-2].ptr,yyvsp[0].ptr,racnt);
sprintf(yyval.str,"A4GL_push_double(_g%d);\n",racnt);
racnt+=a;
}
    break;

  case 1164:
#line 5971 "fgl.yacc"
    {
int a;
a=add_report_agg('X',yyvsp[-2].ptr,yyvsp[0].ptr,racnt);
sprintf(yyval.str,"A4GL_push_double(_g%d);\n",racnt);
racnt+=a;
}
    break;

  case 1169:
#line 5984 "fgl.yacc"
    {rep_struct.left_margin=atoi(yyvsp[0].str);}
    break;

  case 1170:
#line 5985 "fgl.yacc"
    {rep_struct.right_margin=atoi(yyvsp[0].str);}
    break;

  case 1171:
#line 5986 "fgl.yacc"
    {rep_struct.top_margin=atoi(yyvsp[0].str);}
    break;

  case 1172:
#line 5987 "fgl.yacc"
    {rep_struct.bottom_margin=atoi(yyvsp[0].str);}
    break;

  case 1173:
#line 5988 "fgl.yacc"
    {rep_struct.page_length=atoi(yyvsp[0].str);}
    break;

  case 1174:
#line 5989 "fgl.yacc"
    { rep_struct.output_mode='P';strcpy(rep_struct.output_loc,"acl_getenv(\"DBPRINT\")");}
    break;

  case 1175:
#line 5990 "fgl.yacc"
    {rep_struct.output_mode='F';strcpy(rep_struct.output_loc,yyvsp[0].str);}
    break;

  case 1176:
#line 5991 "fgl.yacc"
    {rep_struct.output_mode='F';strcpy(rep_struct.output_loc,yyvsp[0].str);}
    break;

  case 1177:
#line 5992 "fgl.yacc"
    {rep_struct.output_mode='P';strcpy(rep_struct.output_loc,yyvsp[0].str);}
    break;

  case 1178:
#line 5993 "fgl.yacc"
    {strcpy(rep_struct.top_of_page,yyvsp[0].str);}
    break;

  case 1181:
#line 5999 "fgl.yacc"
    {sprintf(yyval.str,"-%f",atof(yyvsp[-1].str));}
    break;

  case 1182:
#line 6000 "fgl.yacc"
    {sprintf(yyval.str,"-%f",atof(yyvsp[-1].str)*72.0); }
    break;

  case 1183:
#line 6001 "fgl.yacc"
    {sprintf(yyval.str,"-%f",atof(yyvsp[-1].str)*2.83465);}
    break;

  case 1184:
#line 6002 "fgl.yacc"
    {sprintf(yyval.str,"%f",atof(yyvsp[0].str));}
    break;

  case 1189:
#line 6011 "fgl.yacc"
    {pdf_rep_struct.left_margin=atof(yyvsp[0].str);A4GL_debug("Left margin=%s\n",yyvsp[0].str);}
    break;

  case 1190:
#line 6012 "fgl.yacc"
    {pdf_rep_struct.right_margin=atof(yyvsp[0].str);}
    break;

  case 1191:
#line 6013 "fgl.yacc"
    {pdf_rep_struct.top_margin=atof(yyvsp[0].str);}
    break;

  case 1192:
#line 6014 "fgl.yacc"
    {pdf_rep_struct.bottom_margin=atof(yyvsp[0].str);}
    break;

  case 1193:
#line 6015 "fgl.yacc"
    {pdf_rep_struct.page_length=atof(yyvsp[0].str);}
    break;

  case 1194:
#line 6016 "fgl.yacc"
    {pdf_rep_struct.page_width=atof(yyvsp[0].str);}
    break;

  case 1195:
#line 6017 "fgl.yacc"
    {strcpy(pdf_rep_struct.font_name,yyvsp[0].str);}
    break;

  case 1196:
#line 6018 "fgl.yacc"
    {pdf_rep_struct.font_size=atof(yyvsp[0].str);}
    break;

  case 1197:
#line 6020 "fgl.yacc"
    {pdf_rep_struct.paper_size=1;}
    break;

  case 1198:
#line 6021 "fgl.yacc"
    {pdf_rep_struct.paper_size=2;}
    break;

  case 1199:
#line 6022 "fgl.yacc"
    {pdf_rep_struct.paper_size=3;}
    break;

  case 1200:
#line 6023 "fgl.yacc"
    {pdf_rep_struct.paper_size=5;}
    break;

  case 1201:
#line 6025 "fgl.yacc"
    {pdf_rep_struct.paper_size=-1;}
    break;

  case 1202:
#line 6026 "fgl.yacc"
    {pdf_rep_struct.paper_size=-2;}
    break;

  case 1203:
#line 6027 "fgl.yacc"
    {pdf_rep_struct.paper_size=-3;}
    break;

  case 1204:
#line 6028 "fgl.yacc"
    {pdf_rep_struct.paper_size=-5;}
    break;

  case 1208:
#line 6033 "fgl.yacc"
    {pdf_rep_struct.output_mode='F';strcpy(pdf_rep_struct.output_loc,yyvsp[0].str);}
    break;

  case 1209:
#line 6034 "fgl.yacc"
    {pdf_rep_struct.output_mode='P';strcpy(pdf_rep_struct.output_loc,yyvsp[0].str);}
    break;

  case 1213:
#line 6041 "fgl.yacc"
    {
int a;
set_rep_no_orderby(1);
if (get_bind_cnt('f')&&!get_bind_cnt('O')) { A4GL_copy_fbind_to_Obind(); }
a=print_bind_definition('O');
print_order_by_type(2,-1);
sprintf(yyval.str,"%d",a);
}
    break;

  case 1214:
#line 6050 "fgl.yacc"
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

  case 1215:
#line 6059 "fgl.yacc"
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

  case 1216:
#line 6072 "fgl.yacc"
    { 
		rep_type=REP_TYPE_NORMAL; 
		clr_function_constants (); 
		clr_variable(); 
		lastlineno=yylineno; 
		init_report_structure(&rep_struct); 
		}
    break;

  case 1217:
#line 6081 "fgl.yacc"
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

  case 1218:
#line 6092 "fgl.yacc"
    {
		lastlineno=yylineno;
		}
    break;

  case 1219:
#line 6096 "fgl.yacc"
    {
		print_variables();
		}
    break;

  case 1220:
#line 6100 "fgl.yacc"
    {
		print_report_2(0,yyvsp[0].str);
		rordcnt=atoi(yyvsp[0].str);
	 A4GL_debug("SET rordcnt=%d %s",rordcnt,yyvsp[0].str);
		}
    break;

  case 1221:
#line 6106 "fgl.yacc"
    {
		print_report_ctrl();
		}
    break;

  case 1222:
#line 6111 "fgl.yacc"
    {
		pop_blockcommand("REPORT");
		print_report_end() ;
		}
    break;

  case 1223:
#line 6119 "fgl.yacc"
    { strcpy(yyval.str,"");
	yyval.ptr=0;
}
    break;

  case 1224:
#line 6122 "fgl.yacc"
    {
	yyval.ptr=yyvsp[0].ptr;
//sprintf($<str>$,"%s", $<str>2);
}
    break;

  case 1225:
#line 6131 "fgl.yacc"
    {
if (!in_command("REPORT")) {
	a4gl_yyerror("PAUSE can only be used in reportes");
	YYERROR;
        }

print_pause(yyvsp[0].str) ;
}
    break;

  case 1226:
#line 6142 "fgl.yacc"
    {strcpy(yyval.str,"\"\"");}
    break;

  case 1228:
#line 6149 "fgl.yacc"
    {
rep_type=REP_TYPE_PDF;
clr_function_constants();
clr_variable(); 
lastlineno=yylineno; 
pdf_init_report_structure(&pdf_rep_struct);
}
    break;

  case 1229:
#line 6157 "fgl.yacc"
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

  case 1230:
#line 6167 "fgl.yacc"
    {
lastlineno=yylineno;
}
    break;

  case 1231:
#line 6170 "fgl.yacc"
    {
	print_variables();
}
    break;

  case 1232:
#line 6174 "fgl.yacc"
    {
//print_variables();
resize_paper(&pdf_rep_struct);
	print_report_2(1,yyvsp[0].str);
A4GL_debug("SET rordcnt=%d (%s)",rordcnt,yyvsp[0].str);
	rordcnt=atoi(yyvsp[0].str);
}
    break;

  case 1233:
#line 6182 "fgl.yacc"
    {
print_report_ctrl();
}
    break;

  case 1234:
#line 6185 "fgl.yacc"
    {
	pop_blockcommand("REPORT");
	print_report_end();
}
    break;

  case 1235:
#line 6191 "fgl.yacc"
    { strcpy(yyval.str,yyvsp[0].str); }
    break;

  case 1236:
#line 6195 "fgl.yacc"
    {new_counter();
   		addmap("CALL",yyvsp[-1].str,curr_func,yylineno,infilename);
   		}
    break;

  case 1237:
#line 6199 "fgl.yacc"
    {
		sprintf(yyval.str,"%d",get_counter_val());drop_counter();
		}
    break;

  case 1238:
#line 6203 "fgl.yacc"
    {
		print_pdf_call(yyvsp[-5].str,yyvsp[-2].ptr,yyvsp[-1].str);
   		}
    break;

  case 1239:
#line 6207 "fgl.yacc"
    {
	print_returning();
   }
    break;

  case 1240:
#line 6213 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 1241:
#line 6214 "fgl.yacc"
    { strcpy(yyval.str,"_rep.right_margin"); }
    break;

  case 1242:
#line 6215 "fgl.yacc"
    { sprintf(yyval.str,"%s",yyvsp[0].str); }
    break;

  case 1243:
#line 6216 "fgl.yacc"
    { sprintf(yyval.str,"%s",yyvsp[0].str); }
    break;

  case 1244:
#line 6221 "fgl.yacc"
    {
print_system_run(0,0);
}
    break;

  case 1245:
#line 6223 "fgl.yacc"
    {
print_system_run(1,yyvsp[0].str);
}
    break;

  case 1246:
#line 6226 "fgl.yacc"
    {
print_system_run(2,0);
}
    break;

  case 1247:
#line 6230 "fgl.yacc"
    {
print_system_run(0,0);
}
    break;

  case 1248:
#line 6233 "fgl.yacc"
    {
print_system_run(0,0);
/* FIXME */
}
    break;

  case 1249:
#line 6240 "fgl.yacc"
    {
	print_exec_sql(yyvsp[0].str);
}
    break;

  case 1250:
#line 6245 "fgl.yacc"
    {sprintf(yyval.str, "%s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1251:
#line 6246 "fgl.yacc"
    {sprintf(yyval.str,  "%s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1252:
#line 6247 "fgl.yacc"
    {sprintf(yyval.str,"%s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1253:
#line 6248 "fgl.yacc"
    {sprintf(yyval.str,"%s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1254:
#line 6253 "fgl.yacc"
    { print_exec_sql(yyvsp[0].str); }
    break;

  case 1255:
#line 6254 "fgl.yacc"
    { print_exec_sql(yyvsp[0].sql_string); 
	free(yyvsp[0].sql_string);
}
    break;

  case 1256:
#line 6260 "fgl.yacc"
    {insql=1;}
    break;

  case 1257:
#line 6260 "fgl.yacc"
    {insql=0;}
    break;

  case 1258:
#line 6260 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-7].str," ",yyvsp[-5].str," ",yyvsp[-4].str,yyvsp[-2].sql_string,yyvsp[-1].str,yyvsp[0].str,0);
		free(yyvsp[-2].sql_string);
	}
    break;

  case 1259:
#line 6265 "fgl.yacc"
    {insql=1;}
    break;

  case 1260:
#line 6265 "fgl.yacc"
    {insql=0;}
    break;

  case 1261:
#line 6265 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-8].str," ",yyvsp[-6].str," ",yyvsp[-5].str,yyvsp[-3].sql_string,yyvsp[-2].str, " ",yyvsp[-1].str,yyvsp[0].str,0);
		free(yyvsp[-3].sql_string);
	}
    break;

  case 1262:
#line 6273 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1263:
#line 6274 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1265:
#line 6279 "fgl.yacc"
    {sprintf(yyval.str,"%s%s",yyvsp[-1].str,yyvsp[0].str); }
    break;

  case 1266:
#line 6284 "fgl.yacc"
    {sprintf(yyval.str," IN %s",yyvsp[0].str);}
    break;

  case 1267:
#line 6285 "fgl.yacc"
    {sprintf(yyval.str," EXTENT SIZE %s",yyvsp[0].str); }
    break;

  case 1268:
#line 6286 "fgl.yacc"
    {sprintf(yyval.str," NEXT SIZE %s",yyvsp[0].str); }
    break;

  case 1269:
#line 6287 "fgl.yacc"
    {sprintf(yyval.str," LOCK MODE PAGE");}
    break;

  case 1270:
#line 6288 "fgl.yacc"
    {sprintf(yyval.str," LOCK MODE ROW");}
    break;

  case 1272:
#line 6293 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1273:
#line 6293 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1275:
#line 6297 "fgl.yacc"
    {sprintf(yyval.str,"%s%s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1276:
#line 6301 "fgl.yacc"
    {sprintf(yyval.str," IN %s",yyvsp[0].str);}
    break;

  case 1277:
#line 6302 "fgl.yacc"
    {sprintf(yyval.str,"FILLFACTOR %s",yyvsp[0].str);}
    break;

  case 1278:
#line 6305 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s %s %s %s %s",yyvsp[-7].str,yyvsp[-6].str,yyvsp[-5].str,yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1279:
#line 6306 "fgl.yacc"
    {
		a4gl_yyerror("You cannot create a database from within Aubit4gl - if the target database allows - prepare and execute it manually");
	}
    break;

  case 1280:
#line 6309 "fgl.yacc"
    {
		a4gl_yyerror("You cannot drop a database from within Aubit4gl - if the target database allows - prepare and execute it manually");
	}
    break;

  case 1281:
#line 6312 "fgl.yacc"
    {
		sprintf(yyval.str,"%s %s FOR %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[0].str);
	}
    break;

  case 1282:
#line 6315 "fgl.yacc"
    {
		sprintf(yyval.str,"%s %s",yyvsp[-1].str,yyvsp[0].str);
	}
    break;

  case 1283:
#line 6321 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1284:
#line 6323 "fgl.yacc"
    {
if (A4GL_isyes(acl_getenv("A4GL_OMIT_NO_LOG"))) {
	strcpy(yyval.str,"");
} else {
	sprintf(yyval.str," %s ",yyvsp[0].str);
}
}
    break;

  case 1286:
#line 6336 "fgl.yacc"
    {sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1287:
#line 6340 "fgl.yacc"
    {sprintf(yyval.str,"%s ASC",yyvsp[-1].str);}
    break;

  case 1288:
#line 6341 "fgl.yacc"
    {sprintf(yyval.str,"%s DESC",yyvsp[-1].str);}
    break;

  case 1290:
#line 6346 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1291:
#line 6349 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",",yyvsp[0].sql_string,0);
	}
    break;

  case 1292:
#line 6355 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1293:
#line 6358 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1294:
#line 6366 "fgl.yacc"
    {sprintf(yyval.str,"%s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1296:
#line 6373 "fgl.yacc"
    {
	yyval.sql_string=make_sql_string(yyvsp[-2].str," ",yyvsp[-1].str," ",yyvsp[0].sql_string,0);
	print_exec_sql(yyval.sql_string); 
}
    break;

  case 1297:
#line 6377 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("ALTER INDEX ",yyvsp[-1].str," TO CLUSTER",0);
		print_exec_sql(yyval.sql_string); 
		}
    break;

  case 1298:
#line 6381 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("ALTER INDEX ",yyvsp[-1].str," TO NOT CLUSTER",0);
		}
    break;

  case 1299:
#line 6387 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1300:
#line 6390 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",",yyvsp[0].sql_string,0);
	}
    break;

  case 1301:
#line 6399 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1302:
#line 6402 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1303:
#line 6405 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1304:
#line 6408 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1305:
#line 6411 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1306:
#line 6414 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1307:
#line 6417 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1308:
#line 6424 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("ADD ",yyvsp[0].sql_string,0);
	}
    break;

  case 1309:
#line 6427 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("ADD (",yyvsp[-1].sql_string,")",0);
	}
    break;

  case 1310:
#line 6434 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1311:
#line 6437 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string," BEFORE ",yyvsp[0].str,0);
	}
    break;

  case 1312:
#line 6443 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1313:
#line 6446 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",",yyvsp[0].sql_string,0);
	}
    break;

  case 1314:
#line 6453 "fgl.yacc"
    {
		sprintf(yyval.str,"DROP %s",yyvsp[0].str);
	}
    break;

  case 1315:
#line 6456 "fgl.yacc"
    {
		sprintf(yyval.str,"DROP (%s)",yyvsp[-1].str);
	}
    break;

  case 1317:
#line 6464 "fgl.yacc"
    {
		sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);
	}
    break;

  case 1319:
#line 6473 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("MODIFY ",yyvsp[0].sql_string,0);
	}
    break;

  case 1320:
#line 6476 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("MODIFY (",yyvsp[-1].sql_string,")",0);
	}
    break;

  case 1321:
#line 6482 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1322:
#line 6485 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",",yyvsp[0].sql_string,0);
	}
    break;

  case 1323:
#line 6491 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1324:
#line 6498 "fgl.yacc"
    {strcpy(yyval.str,"LOCK MODE (PAGE)");}
    break;

  case 1325:
#line 6499 "fgl.yacc"
    {strcpy(yyval.str,"LOCK MODE (ROW)");}
    break;

  case 1326:
#line 6503 "fgl.yacc"
    {
		sprintf(yyval.str,"MODIFY NEXT SIZE %d",atoi(yyvsp[0].str));
	}
    break;

  case 1327:
#line 6513 "fgl.yacc"
    {
		sprintf(yyval.str,"ADD CONSTRAINT %s%s",yyvsp[-1].sql_string,yyvsp[0].str);
	}
    break;

  case 1328:
#line 6516 "fgl.yacc"
    {
		sprintf(yyval.str,"ADD CONSTRAINT (%s)",yyvsp[-1].sql_string);
	}
    break;

  case 1329:
#line 6522 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-1].sql_string,yyvsp[0].str,0);
}
    break;

  case 1330:
#line 6524 "fgl.yacc"
    {
	yyval.sql_string=make_sql_string(yyvsp[-3].sql_string,",",yyvsp[-1].sql_string,yyvsp[0].str, 0);
}
    break;

  case 1331:
#line 6529 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1332:
#line 6530 "fgl.yacc"
    {sprintf(yyval.str," %s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1333:
#line 6535 "fgl.yacc"
    { sprintf(yyval.str,"DROP CONSTRAINT %s",yyvsp[0].str); }
    break;

  case 1334:
#line 6536 "fgl.yacc"
    {
		sprintf(yyval.str,"DROP CONSTRAINT (%s)",yyvsp[-1].str);
	}
    break;

  case 1335:
#line 6542 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1336:
#line 6543 "fgl.yacc"
    {sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1340:
#line 6570 "fgl.yacc"
    {sprintf(yyval.str,"%s %s /*FIXME */",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1346:
#line 6576 "fgl.yacc"
    { 
	print_set_conn(yyvsp[0].str);
}
    break;

  case 1347:
#line 6579 "fgl.yacc"
    {
	print_set_options("conn",yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 1348:
#line 6582 "fgl.yacc"
    {
	print_set_options("stmt",yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 1349:
#line 6588 "fgl.yacc"
    {strcpy(yyval.str,"\"default\"");}
    break;

  case 1351:
#line 6594 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1353:
#line 6605 "fgl.yacc"
    {
		print_sleep();
	}
    break;

  case 1354:
#line 6619 "fgl.yacc"
    {
		print_sql_commit(0);
		}
    break;

  case 1355:
#line 6628 "fgl.yacc"
    { insql=1;start_bind('i',0);}
    break;

  case 1356:
#line 6628 "fgl.yacc"
    {
	yyval.sql_string=make_sql_string(yyvsp[-4].str," ",yyvsp[-2].str," ",yyvsp[-1].str," ",yyvsp[0].sql_string,0);
}
    break;

  case 1357:
#line 6633 "fgl.yacc"
    {insql=1;}
    break;

  case 1358:
#line 6633 "fgl.yacc"
    {
insql=0;
	//printf("Value = %s\n",$<sql_string>4);
yyval.sql_string=make_sql_string(yyvsp[-4].str," (",yyvsp[-1].sql_string,")",0);}
    break;

  case 1359:
#line 6638 "fgl.yacc"
    {yyval.sql_string=yyvsp[0].sql_string;}
    break;

  case 1360:
#line 6641 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1361:
#line 6643 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1363:
#line 6650 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1364:
#line 6654 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	//printf(" 1. Value = %s\n",$<sql_string>$);
	}
    break;

  case 1365:
#line 6658 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",", yyvsp[0].sql_string,0);
	//printf(" 2. Value = %s\n",$<sql_string>$);
	}
    break;

  case 1366:
#line 6665 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1367:
#line 6668 "fgl.yacc"
    {
		yyval.sql_string=strdup("NULL");
	}
    break;

  case 1368:
#line 6675 "fgl.yacc"
    {
      print_fetch_1();
    }
    break;

  case 1369:
#line 6679 "fgl.yacc"
    {
      print_fetch_2();
      print_fetch_3(yyvsp[-1].str,yyvsp[0].str);
    }
    break;

  case 1370:
#line 6685 "fgl.yacc"
    {sprintf(yyval.str,"%s",yyvsp[0].str);doing_declare=1;}
    break;

  case 1371:
#line 6690 "fgl.yacc"
    {sprintf(yyval.str,"%s, %s",yyvsp[0].str,yyvsp[-1].str);
addmap("Fetch Cursor",yyvsp[0].str,curr_func,yylineno,infilename);
}
    break;

  case 1372:
#line 6694 "fgl.yacc"
    {sprintf(yyval.str,"%s, %d, 1",yyvsp[0].str,FETCH_RELATIVE);

addmap("Fetch Cursor",yyvsp[0].str,curr_func,yylineno,infilename);
}
    break;

  case 1373:
#line 6700 "fgl.yacc"
    {
A4GL_debug("no into\n");
strcpy(yyval.str,"0,0");
}
    break;

  case 1374:
#line 6703 "fgl.yacc"
    {
 A4GL_debug("FETCH INTO  ...");
	/* start_bind('i',0,-1); */
    start_bind('o',0);
}
    break;

  case 1375:
#line 6709 "fgl.yacc"
    {
	int no;
	no=get_bind_cnt('o');
	sprintf(yyval.str,"%d,obind",no);
}
    break;

  case 1376:
#line 6716 "fgl.yacc"
    {
A4GL_debug("no into\n");
strcpy(yyval.str,"0,0");
}
    break;

  case 1377:
#line 6720 "fgl.yacc"
    {
 A4GL_debug("FETCH INTO  ...");
	/* start_bind('i',0,-1); */
    start_bind('o',0);
}
    break;

  case 1378:
#line 6725 "fgl.yacc"
    {
/*
int ni;
ni=print_bind('i');
sprintf($<str>$,"%d,ibind",ni);
*/
}
    break;

  case 1379:
#line 6735 "fgl.yacc"
    {
		sprintf(yyval.str,"%d,1",FETCH_ABSOLUTE);}
    break;

  case 1380:
#line 6738 "fgl.yacc"
    {sprintf(yyval.str,"%d,-1",FETCH_ABSOLUTE);}
    break;

  case 1381:
#line 6740 "fgl.yacc"
    {sprintf(yyval.str,"%d,1",FETCH_RELATIVE);}
    break;

  case 1382:
#line 6742 "fgl.yacc"
    {sprintf(yyval.str,"%d,-1",FETCH_RELATIVE);}
    break;

  case 1383:
#line 6744 "fgl.yacc"
    {sprintf(yyval.str,"%d,-1",FETCH_RELATIVE);}
    break;

  case 1384:
#line 6746 "fgl.yacc"
    {sprintf(yyval.str,"%d,0",FETCH_RELATIVE);}
    break;

  case 1385:
#line 6748 "fgl.yacc"
    {sprintf(yyval.str,"%d,A4GL_pop_int()",FETCH_RELATIVE);}
    break;

  case 1386:
#line 6750 "fgl.yacc"
    {sprintf(yyval.str,"%d,A4GL_pop_int()",FETCH_ABSOLUTE);}
    break;

  case 1387:
#line 6756 "fgl.yacc"
    {
 
rm_quotes(yyvsp[0].str);
sprintf(yyval.str," %s %s %s %s ",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str
);}
    break;

  case 1388:
#line 6766 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].str," ",yyvsp[-1].str," ",yyvsp[0].sql_string,0);
		}
    break;

  case 1389:
#line 6773 "fgl.yacc"
    {sprintf(yyval.str,"%s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1391:
#line 6779 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1392:
#line 6782 "fgl.yacc"
    {sprintf(yyval.str,"%s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1395:
#line 6789 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1398:
#line 6794 "fgl.yacc"
    {
print_sql_commit(-1);
}
    break;

  case 1399:
#line 6799 "fgl.yacc"
    {
		print_sql_commit(1);
	}
    break;

  case 1400:
#line 6806 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1401:
#line 6807 "fgl.yacc"
    {
		strcpy(yyval.str,"EXCLUSIVE");
	}
    break;

  case 1402:
#line 6814 "fgl.yacc"
    {
if (strcmp(yyvsp[-1].str,"?")==0) {
	print_init_conn(0);
} else {
	print_init_conn(yyvsp[-1].str);
}
}
    break;

  case 1403:
#line 6825 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1404:
#line 6826 "fgl.yacc"
    {sprintf(yyval.str,"%s@%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1405:
#line 6827 "fgl.yacc"
    {strcpy(yyval.str, A4GL_strip_quotes (yyvsp[0].str));}
    break;

  case 1406:
#line 6830 "fgl.yacc"
    {insql=1;}
    break;

  case 1407:
#line 6830 "fgl.yacc"
    {
print_undo_use(yyvsp[-2].str);
insql=0;strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1408:
#line 6835 "fgl.yacc"
    {
		 A4GL_lex_printcomment("/*  schema */\n");
			print_exec_sql(yyvsp[0].sql_string);
			strcpy(yyval.str,"Schema");
	}
    break;

  case 1409:
#line 6840 "fgl.yacc"
    {
	 A4GL_lex_printcomment("/*  schema  2*/\n");
		print_exec_sql(yyvsp[0].sql_string);
		strcpy(yyval.str,"Schema Element");
	}
    break;

  case 1411:
#line 6846 "fgl.yacc"
    {
		print_exec_sql(yyvsp[0].str);
 	}
    break;

  case 1413:
#line 6850 "fgl.yacc"
    {
	 A4GL_lex_printcomment("/*  delete 1 */\n");
		print_exec_sql_bound(yyvsp[0].str);
		strcpy(yyval.str,"Delete where current...");
	}
    break;

  case 1414:
#line 6855 "fgl.yacc"
    {
	 A4GL_lex_printcomment("/*  delete 2 */\n");
		print_exec_sql_bound(yyvsp[0].sql_string);
		strcpy(yyval.str,"Delete where ...");
	}
    break;

  case 1415:
#line 6860 "fgl.yacc"
    {
		strcpy(yyval.str,"Fetch");
	 A4GL_lex_printcomment("/*  fetch */\n");
	}
    break;

  case 1416:
#line 6864 "fgl.yacc"
    {
	 A4GL_lex_printcomment("/*  insert */\n");
		print_exec_sql_bound(yyvsp[0].sql_string);
		strcpy(yyval.str,"insert");
	}
    break;

  case 1418:
#line 6870 "fgl.yacc"
    {
		print_do_select(yyvsp[0].sql_string);
		strcpy(yyval.str,"select");
	}
    break;

  case 1419:
#line 6874 "fgl.yacc"
    {
		print_exec_sql_bound(yyvsp[0].sql_string);
		strcpy(yyval.str,"update");
	}
    break;

  case 1420:
#line 6881 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s %s %s %s",yyvsp[-6].str,yyvsp[-5].str,yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1421:
#line 6882 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s %s %s",yyvsp[-5].str,yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1422:
#line 6883 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s ",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1423:
#line 6884 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s ",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1427:
#line 6894 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1428:
#line 6895 "fgl.yacc"
    {sprintf(yyval.str," %s ",yyvsp[0].str);}
    break;

  case 1429:
#line 6896 "fgl.yacc"
    {sprintf(yyval.str," %s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1430:
#line 6900 "fgl.yacc"
    {sprintf(yyval.str," %s ",yyvsp[0].str);}
    break;

  case 1431:
#line 6901 "fgl.yacc"
    {sprintf(yyval.str," %s ",yyvsp[0].str);}
    break;

  case 1434:
#line 6908 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1435:
#line 6911 "fgl.yacc"
    {sprintf(yyval.str," %s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1438:
#line 6914 "fgl.yacc"
    {sprintf(yyval.str," %s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1441:
#line 6919 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1442:
#line 6921 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1444:
#line 6927 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1446:
#line 6933 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1449:
#line 6943 "fgl.yacc"
    {
yyval.sql_string=make_sql_string(yyvsp[-5].str," ",yyvsp[-4].str," ",yyvsp[-3].str," ",yyvsp[-2].str," ",yyvsp[-1].sql_string," ",yyvsp[0].str,0);
}
    break;

  case 1450:
#line 6948 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1451:
#line 6950 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1453:
#line 6956 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1454:
#line 6959 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1456:
#line 6965 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("CHECK(",yyvsp[-1].sql_string,")",0);
	}
    break;

  case 1457:
#line 6973 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s %s",yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1458:
#line 6978 "fgl.yacc"
    {sprintf(yyval.str," %s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1461:
#line 6988 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1463:
#line 6994 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1464:
#line 6999 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1465:
#line 7000 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1466:
#line 7002 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1468:
#line 7008 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1469:
#line 7013 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1470:
#line 7016 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1471:
#line 7019 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1472:
#line 7026 "fgl.yacc"
    {sprintf(yyval.str," %s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1473:
#line 7027 "fgl.yacc"
    {sprintf(yyval.str," DEFAULT USER");}
    break;

  case 1474:
#line 7028 "fgl.yacc"
    {sprintf(yyval.str," DEFAULT TODAY");}
    break;

  case 1475:
#line 7030 "fgl.yacc"
    {sprintf(yyval.str," %s",yyvsp[0].str);}
    break;

  case 1476:
#line 7043 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-3].str," ",yyvsp[-2].str," ",yyvsp[-1].str," ",yyvsp[0].sql_string,0);
	}
    break;

  case 1477:
#line 7048 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1479:
#line 7052 "fgl.yacc"
    {
		yyval.sql_string=strdup("");
	}
    break;

  case 1480:
#line 7054 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1481:
#line 7061 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1482:
#line 7064 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-1].sql_string,yyvsp[0].sql_string,0);
	}
    break;

  case 1483:
#line 7070 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-1].sql_string,yyvsp[0].str,0);
	}
    break;

  case 1484:
#line 7078 "fgl.yacc"
    {
		sprintf(yyval.str," %s ",yyvsp[0].str);
		yyval.sql_string=strdup(yyval.str);
	}
    break;

  case 1485:
#line 7082 "fgl.yacc"
    {
		sprintf(yyval.str," %s ",yyvsp[0].str);
		yyval.sql_string=strdup(yyval.str);
	}
    break;

  case 1486:
#line 7086 "fgl.yacc"
    {
		sprintf(yyval.str," %s ",yyvsp[0].str);
		yyval.sql_string=strdup(yyval.str);
	}
    break;

  case 1487:
#line 7090 "fgl.yacc"
    {
		sprintf(yyval.str," %s ",yyvsp[0].str);
		yyval.sql_string=strdup(yyval.str);
	}
    break;

  case 1488:
#line 7094 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1489:
#line 7097 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-3].str," ",yyvsp[-2].str," ",yyvsp[-1].sql_string," ",yyvsp[0].str,0);
	}
    break;

  case 1490:
#line 7100 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(" PRIMARY KEY ",0);
	}
    break;

  case 1491:
#line 7108 "fgl.yacc"
    {
yyval.sql_string=make_sql_string(yyvsp[-2].str," ",yyvsp[-1].str," ",yyvsp[0].str,0);
}
    break;

  case 1492:
#line 7115 "fgl.yacc"
    {sprintf(yyval.str," %s",yyvsp[0].str);}
    break;

  case 1495:
#line 7124 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-1].sql_string," ",yyvsp[0].sql_string,0);
	}
    break;

  case 1496:
#line 7130 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1497:
#line 7133 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1498:
#line 7144 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-1].str," ",yyvsp[0].sql_string,0);
	}
    break;

  case 1499:
#line 7151 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("GROUP BY ",yyvsp[0].sql_string,0);
	}
    break;

  case 1500:
#line 7157 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1501:
#line 7160 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",",yyvsp[0].sql_string,0);
	}
    break;

  case 1502:
#line 7167 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("WHERE ",yyvsp[0].sql_string,0);
	}
    break;

  case 1503:
#line 7174 "fgl.yacc"
    {
		sprintf(yyval.str,"%s %s",yyvsp[-1].str,yyvsp[0].str);
	}
    break;

  case 1505:
#line 7181 "fgl.yacc"
    {
		sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);
	}
    break;

  case 1506:
#line 7187 "fgl.yacc"
    {sprintf(yyval.str," %s ", yyvsp[0].str);}
    break;

  case 1507:
#line 7188 "fgl.yacc"
    {sprintf(yyval.str," %s %s ",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1508:
#line 7189 "fgl.yacc"
    {sprintf(yyval.str," %s (%s) ",yyvsp[-3].str,yyvsp[-1].str);}
    break;

  case 1510:
#line 7193 "fgl.yacc"
    {sprintf(yyval.str,"%s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1512:
#line 7198 "fgl.yacc"
    { sprintf(yyval.str," %s,%s ",yyvsp[-2].str,yyvsp[0].str);  }
    break;

  case 1513:
#line 7205 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-3].str," ",yyvsp[-2].sql_string," ",yyvsp[-1].sql_string," ",yyvsp[0].sql_string,0);
	}
    break;

  case 1514:
#line 7210 "fgl.yacc"
    { yyval.sql_string=strdup("");}
    break;

  case 1515:
#line 7211 "fgl.yacc"
    {yyval.sql_string=yyvsp[0].sql_string;}
    break;

  case 1516:
#line 7214 "fgl.yacc"
    {
	yyval.sql_string=strdup("");
}
    break;

  case 1517:
#line 7217 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
}
    break;

  case 1518:
#line 7222 "fgl.yacc"
    {yyval.sql_string=strdup("");}
    break;

  case 1519:
#line 7223 "fgl.yacc"
    {yyval.sql_string=yyvsp[0].sql_string;}
    break;

  case 1520:
#line 7228 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1521:
#line 7231 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string," OR ",yyvsp[0].sql_string,0);
	}
    break;

  case 1522:
#line 7237 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1523:
#line 7240 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string," AND ",yyvsp[0].sql_string,0);
	}
    break;

  case 1524:
#line 7246 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1525:
#line 7249 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-1].str," ",yyvsp[0].sql_string,0);
	}
    break;

  case 1526:
#line 7255 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1527:
#line 7258 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].str,yyvsp[-1].sql_string,yyvsp[0].str,0);
	}
    break;

  case 1528:
#line 7265 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-1].str," ",yyvsp[0].sql_string,0);}
    break;

  case 1529:
#line 7266 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-1].str," ",yyvsp[0].sql_string,0);}
    break;

  case 1530:
#line 7295 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1531:
#line 7297 "fgl.yacc"
    {sprintf(yyval.str," %s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1532:
#line 7301 "fgl.yacc"
    {yyval.sql_string=yyvsp[0].sql_string;}
    break;

  case 1534:
#line 7314 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-4].sql_string," IN (",yyvsp[-1].str,")",0);
	}
    break;

  case 1535:
#line 7317 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string," ",yyvsp[-1].str," ",yyvsp[0].sql_string,0);
	}
    break;

  case 1536:
#line 7320 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-4].sql_string," NOT IN (",yyvsp[-1].str,")",0);
	}
    break;

  case 1537:
#line 7323 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string," ",yyvsp[-1].str," ",yyvsp[0].sql_string,0);
	}
    break;

  case 1539:
#line 7331 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1540:
#line 7334 "fgl.yacc"
    {
		strcpy(yyval.str,yyvsp[0].sql_string);
	}
    break;

  case 1542:
#line 7340 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1544:
#line 7346 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string," ",yyvsp[-1].str," IS NULL",0);
	}
    break;

  case 1545:
#line 7349 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string," ",yyvsp[-1].str," IS NOT NULL",0);
	}
    break;

  case 1546:
#line 7352 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string," ",yyvsp[-1].str," ",yyvsp[0].sql_string,0);
	}
    break;

  case 1547:
#line 7355 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-5].sql_string," ",yyvsp[-4].str," BETWEEN ",yyvsp[-2].sql_string," AND ",yyvsp[0].sql_string,0);
	}
    break;

  case 1548:
#line 7358 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-3].sql_string," ",yyvsp[-2].str," ",yyvsp[-1].sql_string,yyvsp[0].str,0);
	}
    break;

  case 1549:
#line 7361 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-3].sql_string," ",yyvsp[-2].str," ",yyvsp[-1].sql_string,yyvsp[0].str,0);
	}
    break;

  case 1550:
#line 7364 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-3].sql_string," ",yyvsp[-2].str," ",yyvsp[-1].sql_string,yyvsp[0].str,0);
	}
    break;

  case 1551:
#line 7367 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-3].sql_string," ",yyvsp[-2].str," ",yyvsp[-1].sql_string,yyvsp[0].str,0);
	}
    break;

  case 1552:
#line 7372 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-4].sql_string," ",yyvsp[-3].str," MATCHES ",yyvsp[-1].sql_string,yyvsp[0].str,0);
	}
    break;

  case 1554:
#line 7379 "fgl.yacc"
    {strcpy(yyval.str,"!=");}
    break;

  case 1560:
#line 7387 "fgl.yacc"
    {strcpy(yyval.str,"<=");}
    break;

  case 1561:
#line 7388 "fgl.yacc"
    {strcpy(yyval.str,">=");}
    break;

  case 1562:
#line 7393 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1563:
#line 7396 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1564:
#line 7400 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1565:
#line 7406 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1566:
#line 7407 "fgl.yacc"
    {strcpy(yyval.str," ALL ");}
    break;

  case 1567:
#line 7408 "fgl.yacc"
    {strcpy(yyval.str," DISTINCT ");}
    break;

  case 1568:
#line 7409 "fgl.yacc"
    {
		ansi_violation("Use DISTINCT not UNIQUE",0);
		strcpy(yyval.str," DISTINCT ");
	}
    break;

  case 1573:
#line 7429 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1575:
#line 7433 "fgl.yacc"
    {strcpy(yyval.str,"SERIAL");}
    break;

  case 1576:
#line 7434 "fgl.yacc"
    {sprintf(yyval.str,"SERIAL(%s)",yyvsp[-1].str);}
    break;

  case 1578:
#line 7437 "fgl.yacc"
    {sprintf(yyval.str," DECIMAL(%s%s)",yyvsp[-2].str,yyvsp[-1].str);}
    break;

  case 1579:
#line 7439 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s %s",yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1587:
#line 7448 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1588:
#line 7450 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s %s %s",yyvsp[-5].str,yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1589:
#line 7452 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1591:
#line 7455 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1593:
#line 7458 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s %s %s %s",yyvsp[-6].str,yyvsp[-5].str,yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1597:
#line 7463 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1598:
#line 7465 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s %s %s",yyvsp[-5].str,yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1599:
#line 7468 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1600:
#line 7469 "fgl.yacc"
    {
		sprintf(yyval.str,",%s",yyvsp[0].str);
}
    break;

  case 1601:
#line 7476 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1605:
#line 7481 "fgl.yacc"
    {sprintf(yyval.str," %s",yyvsp[0].str);}
    break;

  case 1609:
#line 7497 "fgl.yacc"
    { 
			if (A4GL_escape_quote_owner()) {
				sprintf(yyval.str,"\\\"%s\\\"%s%s", A4GL_strip_quotes (yyvsp[-2].str),yyvsp[-1].str,yyvsp[0].str); addmap("Use Table",yyval.str,curr_func,yylineno,infilename); 
			} else {
				sprintf(yyval.str,"\"%s\"%s%s", A4GL_strip_quotes (yyvsp[-2].str),yyvsp[-1].str,yyvsp[0].str); addmap("Use Table",yyval.str,curr_func,yylineno,infilename); 
			}
	}
    break;

  case 1610:
#line 7504 "fgl.yacc"
    {
		sprintf(yyval.str," %s", A4GL_strip_quotes (yyvsp[0].str));
		addmap("Use Table",yyval.str,curr_func,yylineno,infilename);
	}
    break;

  case 1611:
#line 7508 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str); addmap("Use Table",yyvsp[0].str,curr_func,yylineno,infilename); }
    break;

  case 1612:
#line 7509 "fgl.yacc"
    { sprintf(yyval.str," %s%s%s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str); addmap("Use Table",yyval.str,curr_func,yylineno,infilename); }
    break;

  case 1613:
#line 7510 "fgl.yacc"
    { 
                        if (A4GL_escape_quote_owner()) {
				sprintf(yyval.str," %s:\\\"%s\\\".%s",yyvsp[-4].str,A4GL_strip_quotes(yyvsp[-2].str),yyvsp[0].str); addmap("Use Table",yyval.str,curr_func,yylineno,infilename); 
                        } else {
				sprintf(yyval.str," %s:%s.%s",yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str); addmap("Use Table",yyval.str,curr_func,yylineno,infilename); 
                        }
	}
    break;

  case 1614:
#line 7518 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[-2].str); addmap("Use Table",yyvsp[-2].str,curr_func,yylineno,infilename); }
    break;

  case 1615:
#line 7519 "fgl.yacc"
    { sprintf(yyval.str," %s@%s%s%s",yyvsp[-4].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str); addmap("Use Table",yyval.str,curr_func,yylineno,infilename); }
    break;

  case 1616:
#line 7520 "fgl.yacc"
    { 
                        if (A4GL_escape_quote_owner()) {
				sprintf(yyval.str," %s@%s:\\\"%s\\\".%s",yyvsp[-6].str,yyvsp[-4].str,A4GL_strip_quotes(yyvsp[-2].str),yyvsp[0].str); addmap("Use Table",yyval.str,curr_func,yylineno,infilename); 
                        } else {
				sprintf(yyval.str," %s@%s:%s.%s",yyvsp[-6].str,yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str); addmap("Use Table",yyval.str,curr_func,yylineno,infilename); 
                        }
	}
    break;

  case 1617:
#line 7531 "fgl.yacc"
    { 
			if (A4GL_escape_quote_owner()) {
				sprintf(yyval.str,"\\\"%s\\\"%s%s", A4GL_strip_quotes (yyvsp[-2].str),yyvsp[-1].str,yyvsp[0].str); addmap("Use Index",yyval.str,curr_func,yylineno,infilename); 
			} else {
				sprintf(yyval.str,"\"%s\"%s%s", A4GL_strip_quotes (yyvsp[-2].str),yyvsp[-1].str,yyvsp[0].str); addmap("Use Index",yyval.str,curr_func,yylineno,infilename); 
			}
	}
    break;

  case 1618:
#line 7538 "fgl.yacc"
    {
		sprintf(yyval.str," %s", A4GL_strip_quotes (yyvsp[0].str));
		addmap("Use Index",yyval.str,curr_func,yylineno,infilename);
	}
    break;

  case 1619:
#line 7543 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str); addmap("Use Index",yyvsp[0].str,curr_func,yylineno,infilename); }
    break;

  case 1620:
#line 7544 "fgl.yacc"
    { sprintf(yyval.str," %s%s%s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str); addmap("Use Index",yyval.str,curr_func,yylineno,infilename); }
    break;

  case 1621:
#line 7545 "fgl.yacc"
    { 
                        if (A4GL_escape_quote_owner()) {
				sprintf(yyval.str," %s:\\\"%s\\\".%s",yyvsp[-4].str,A4GL_strip_quotes(yyvsp[-2].str),yyvsp[0].str); addmap("Use Index",yyval.str,curr_func,yylineno,infilename); 
                        } else {
				sprintf(yyval.str," %s:%s.%s",yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str); addmap("Use Index",yyval.str,curr_func,yylineno,infilename); 
                        }
	}
    break;

  case 1622:
#line 7553 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[-2].str); addmap("Use Index",yyvsp[-2].str,curr_func,yylineno,infilename); }
    break;

  case 1623:
#line 7554 "fgl.yacc"
    { sprintf(yyval.str," %s@%s%s%s",yyvsp[-4].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str); addmap("Use Index",yyval.str,curr_func,yylineno,infilename); }
    break;

  case 1624:
#line 7555 "fgl.yacc"
    { 
                        if (A4GL_escape_quote_owner()) {
				sprintf(yyval.str," %s@%s:\\\"%s\\\".%s",yyvsp[-6].str,yyvsp[-4].str,A4GL_strip_quotes(yyvsp[-2].str),yyvsp[0].str); addmap("Use Index",yyval.str,curr_func,yylineno,infilename); 
                        } else {
				sprintf(yyval.str," %s@%s:%s.%s",yyvsp[-6].str,yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str); addmap("Use Index",yyval.str,curr_func,yylineno,infilename); 
                        }
	}
    break;

  case 1626:
#line 7581 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1627:
#line 7582 "fgl.yacc"
    {sprintf(yyval.str,"[%s]",yyvsp[-1].str);}
    break;

  case 1628:
#line 7583 "fgl.yacc"
    {sprintf(yyval.str,"[%s,%s]",yyvsp[-3].str,yyvsp[-1].str);}
    break;

  case 1629:
#line 7587 "fgl.yacc"
    {
		strcpy(yyval.str,yyvsp[0].str);
	}
    break;

  case 1630:
#line 7590 "fgl.yacc"
    {
		strcpy(yyval.str,yyvsp[0].str);
	}
    break;

  case 1631:
#line 7596 "fgl.yacc"
    { 
addmap("Use Column",yyvsp[-1].str,curr_func,yylineno,infilename);
sprintf(yyval.str,"%s%s",yyvsp[-1].str,yyvsp[0].str);
}
    break;

  case 1632:
#line 7601 "fgl.yacc"
    {
sprintf(yyval.str,"%s.%s%s",yyvsp[-3].str,yyvsp[-1].str,yyvsp[0].str);
addmap("Use Column",yyval.str,curr_func,yylineno,infilename);
}
    break;

  case 1633:
#line 7606 "fgl.yacc"
    {
sprintf(yyval.str,"%s.%s",yyvsp[-2].str,yyvsp[0].str);
addmap("Use Column",yyval.str,curr_func,yylineno,infilename);
}
    break;

  case 1635:
#line 7617 "fgl.yacc"
    {
	strcpy(yyval.str,convstrsql(yyvsp[0].str));
 A4GL_debug("Set $<str>$ to %s\n",yyval.str);
}
    break;

  case 1639:
#line 7635 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1640:
#line 7638 "fgl.yacc"
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

  case 1641:
#line 7651 "fgl.yacc"
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

  case 1642:
#line 7666 "fgl.yacc"
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

  case 1643:
#line 7678 "fgl.yacc"
    {strcpy(yyval.str,"1,10");}
    break;

  case 1644:
#line 7680 "fgl.yacc"
    {sprintf(yyval.str," %s ,%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1645:
#line 7683 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 1646:
#line 7683 "fgl.yacc"
    {strcpy(yyval.str,"2");}
    break;

  case 1647:
#line 7683 "fgl.yacc"
    {strcpy(yyval.str,"3");}
    break;

  case 1648:
#line 7683 "fgl.yacc"
    {strcpy(yyval.str,"4");}
    break;

  case 1649:
#line 7683 "fgl.yacc"
    {strcpy(yyval.str,"5");}
    break;

  case 1650:
#line 7683 "fgl.yacc"
    {strcpy(yyval.str,"6");}
    break;

  case 1651:
#line 7684 "fgl.yacc"
    {
sprintf(yyval.str,"%d",6+2);
}
    break;

  case 1652:
#line 7687 "fgl.yacc"
    {
sprintf(yyval.str,"%d",atoi(yyvsp[-1].str)+6);
}
    break;

  case 1653:
#line 7692 "fgl.yacc"
    {strcpy(yyval.str,"4");}
    break;

  case 1654:
#line 7692 "fgl.yacc"
    {strcpy(yyval.str,"7");}
    break;

  case 1655:
#line 7692 "fgl.yacc"
    {strcpy(yyval.str,"10");}
    break;

  case 1656:
#line 7692 "fgl.yacc"
    {strcpy(yyval.str,"13");}
    break;

  case 1657:
#line 7692 "fgl.yacc"
    {strcpy(yyval.str,"16");}
    break;

  case 1658:
#line 7692 "fgl.yacc"
    {strcpy(yyval.str,"19");}
    break;

  case 1659:
#line 7694 "fgl.yacc"
    {
strcpy(yyval.str,"25");
}
    break;

  case 1660:
#line 7697 "fgl.yacc"
    {
strcpy(yyval.str,"25");
}
    break;

  case 1675:
#line 7704 "fgl.yacc"
    {sprintf(yyval.str,"FRACTION(%s)",yyvsp[-1].str);}
    break;

  case 1676:
#line 7707 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1677:
#line 7708 "fgl.yacc"
    {sprintf(yyval.str,"%s@%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1678:
#line 7709 "fgl.yacc"
    {strcpy(yyval.str, A4GL_strip_quotes (yyvsp[0].str));}
    break;

  case 1679:
#line 7713 "fgl.yacc"
    {
	print_flush_cursor(yyvsp[0].str);
		addmap("Flush Cursor",yyvsp[0].str,curr_func,yylineno,infilename);
print_undo_use(yyvsp[-2].str);
		}
    break;

  case 1680:
#line 7721 "fgl.yacc"
    {insql=0;chk4var=0;}
    break;

  case 1681:
#line 7721 "fgl.yacc"
    {
		print_declare("",yyvsp[-1].sql_string,yyvsp[-4].str,0,0);
		addmap("Declare Cursor",yyvsp[-4].str,curr_func,yylineno,infilename);
		print_undo_use(yyvsp[-6].str);
		doing_declare=0;
	}
    break;

  case 1682:
#line 7727 "fgl.yacc"
    {insql=0;chk4var=0;}
    break;

  case 1683:
#line 7727 "fgl.yacc"
    {
		print_declare("",yyvsp[-1].sql_string,yyvsp[-5].str,2,0); 
		addmap("Declare Cursor",yyvsp[-5].str,curr_func,yylineno,infilename);
		print_undo_use(yyvsp[-7].str);
		doing_declare=0;
	}
    break;

  case 1684:
#line 7734 "fgl.yacc"
    {insql=0;chk4var=0;}
    break;

  case 1685:
#line 7734 "fgl.yacc"
    {
		print_declare("",yyvsp[-1].sql_string,yyvsp[-3].str,0,1); 
		addmap("Declare Cursor",yyvsp[-3].str,curr_func,yylineno,infilename);
		print_undo_use(yyvsp[-5].str);
		doing_declare=0;
	}
    break;

  case 1686:
#line 7740 "fgl.yacc"
    {insql=0;chk4var=0;}
    break;

  case 1687:
#line 7740 "fgl.yacc"
    {
		print_declare("",yyvsp[-1].sql_string,yyvsp[-5].str,2,1); 
		addmap("Declare Cursor",yyvsp[-5].str,curr_func,yylineno,infilename);
		print_undo_use(yyvsp[-7].str);
		doing_declare=0;
	}
    break;

  case 1688:
#line 7748 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1689:
#line 7749 "fgl.yacc"
    {strcpy(yyval.str," FOR UPDATE");}
    break;

  case 1690:
#line 7750 "fgl.yacc"
    {sprintf(yyval.str," FOR UPDATE OF %s",yyvsp[0].str);}
    break;

  case 1691:
#line 7753 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1692:
#line 7753 "fgl.yacc"
    {sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1694:
#line 7757 "fgl.yacc"
    {sprintf(yyval.str,"%s.%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1695:
#line 7758 "fgl.yacc"
    {
			if (A4GL_escape_quote_owner()) {
				sprintf(yyval.str,"\\\"%s\\\".%s.%s", A4GL_strip_quotes (yyvsp[-4].str),yyvsp[-2].str,yyvsp[0].str);
			} else {
				sprintf(yyval.str,"\"%s\".%s.%s", A4GL_strip_quotes (yyvsp[-4].str),yyvsp[-2].str,yyvsp[0].str);
			}
	}
    break;

  case 1696:
#line 7769 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1697:
#line 7772 "fgl.yacc"
    { 
		yyval.sql_string=make_sql_string(print_curr_spec(1,yyvsp[0].sql_string),0);
	}
    break;

  case 1698:
#line 7778 "fgl.yacc"
    {
		start_bind('i',0);
		start_bind('o',0);
		yyval.sql_string=make_sql_string(print_curr_spec(2,yyvsp[0].str) ,0);
	}
    break;

  case 1699:
#line 7783 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1700:
#line 7791 "fgl.yacc"
    {
	yyval.sql_string=yyvsp[0].sql_string;
	if (strstr(yyvsp[0].str,"FOR UPDATE")) {
		printf("Warning SELECT ... FOR UPDATE when not declaring a cursor currently has no locking effect\n");
	}
}
    break;

  case 1701:
#line 7803 "fgl.yacc"
    { start_bind('i',0); }
    break;

  case 1702:
#line 7804 "fgl.yacc"
    {A4GL_debug("Got select list...\n");}
    break;

  case 1703:
#line 7807 "fgl.yacc"
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

  case 1704:
#line 7822 "fgl.yacc"
    {
		/*$<sql_string>$=make_sql_string("A4GL_push_char(\"", $<str>1, " ",$<str>2," ", $<sql_string>3, " ",$<sql_string>4, " ",$<sql_string>5, "\");",0); */
		yyval.sql_string=make_sql_string(yyvsp[-4].str, " ",yyvsp[-3].str," ", yyvsp[-2].sql_string, " ",yyvsp[-1].sql_string, " ",yyvsp[0].sql_string,0);
	free(yyvsp[-2].sql_string);
	free(yyvsp[-1].sql_string);
	free(yyvsp[0].sql_string);
}
    break;

  case 1705:
#line 7833 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	 }
    break;

  case 1706:
#line 7836 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1707:
#line 7844 "fgl.yacc"
    {
	yyval.sql_string=make_sql_string(yyvsp[-5].str, " ",yyvsp[-4].str," ",yyvsp[-3].sql_string," ", yyvsp[-2].sql_string," ", yyvsp[-1].sql_string, " ",yyvsp[0].sql_string,0);
	free(yyvsp[-3].sql_string);
	free(yyvsp[-1].sql_string);
	free(yyvsp[0].sql_string);
}
    break;

  case 1708:
#line 7853 "fgl.yacc"
    {
		yyval.sql_string=strdup("");
		}
    break;

  case 1709:
#line 7856 "fgl.yacc"
    {
       A4GL_lex_printcomment("/* UNION */");
	yyval.sql_string=make_sql_string(yyvsp[-2].str," ",yyvsp[-1].str," ",yyvsp[0].sql_string,0);
       }
    break;

  case 1710:
#line 7860 "fgl.yacc"
    {
	yyval.sql_string=strdup(yyvsp[0].str);
}
    break;

  case 1711:
#line 7863 "fgl.yacc"
    { yyval.sql_string=make_sql_string(yyvsp[-2].str," ",yyvsp[-1].str," ",yyvsp[0].str,0); }
    break;

  case 1712:
#line 7864 "fgl.yacc"
    { 
	yyval.sql_string=make_sql_string(yyvsp[-3].str," ",yyvsp[-2].str," ",yyvsp[-1].str," ",yyvsp[0].str,0);
}
    break;

  case 1714:
#line 7873 "fgl.yacc"
    { start_bind('o',0);yyval.sql_string=make_sql_string("",0); }
    break;

  case 1715:
#line 7874 "fgl.yacc"
    { 
		yyval.sql_string=make_sql_string(A4GL_get_into_part(doing_declare,get_bind_cnt('o')),0 ); 

	}
    break;

  case 1716:
#line 7883 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-3].str," ",yyvsp[-2].str," ", yyvsp[-1].sql_string," ",yyvsp[0].sql_string,0);
		free(yyvsp[-1].sql_string);
		//free($<sql_string>4);

	}
    break;

  case 1717:
#line 7892 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("(",yyvsp[-4].str," ",yyvsp[-3].str," ",yyvsp[-2].sql_string," ",yyvsp[-1].sql_string,")",0);
	}
    break;

  case 1718:
#line 7897 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1719:
#line 7898 "fgl.yacc"
    {strcpy(yyval.str,"ALL ");}
    break;

  case 1720:
#line 7899 "fgl.yacc"
    {strcpy(yyval.str," DISTINCT ");}
    break;

  case 1721:
#line 7900 "fgl.yacc"
    {strcpy(yyval.str," DISTINCT ");
		ansi_violation("Use DISTINCT not UNIQUE",0);
		strcpy(yyval.str," DISTINCT ");
}
    break;

  case 1722:
#line 7907 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1723:
#line 7910 "fgl.yacc"
    { 
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",",yyvsp[0].sql_string,0);
	}
    break;

  case 1724:
#line 7916 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1725:
#line 7919 "fgl.yacc"
    {
		if (A4GL_isyes(acl_getenv("A4GL_USE_ALIAS_AS"))) {
			yyval.sql_string=make_sql_string(yyvsp[-1].sql_string," AS ",yyvsp[0].str,0);
		} else {
			yyval.sql_string=make_sql_string(yyvsp[-1].sql_string," ",yyvsp[0].str,0);
		}
	}
    break;

  case 1726:
#line 7926 "fgl.yacc"
    {
		if (A4GL_isyes(acl_getenv("A4GL_USE_ALIAS_AS"))) {
			yyval.sql_string=make_sql_string(yyvsp[-2].sql_string," AS ",yyvsp[0].str,0);
		} else {
			yyval.sql_string=make_sql_string(yyvsp[-2].sql_string," ",yyvsp[0].str,0);
		}
	}
    break;

  case 1727:
#line 7938 "fgl.yacc"
    {
	yyval.sql_string=yyvsp[0].sql_string;
}
    break;

  case 1728:
#line 7947 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1729:
#line 7950 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("-",yyvsp[0].sql_string,0);
	}
    break;

  case 1730:
#line 7953 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("+",yyvsp[0].sql_string,0);
	}
    break;

  case 1731:
#line 7959 "fgl.yacc"
    {
			if (strlen(current_upd_table)) {
				push_gen(UPDVAL,yyvsp[0].sql_string);
			}
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1732:
#line 7965 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1733:
#line 7968 "fgl.yacc"
    { yyval.sql_string=yyvsp[0].sql_string; }
    break;

  case 1734:
#line 7969 "fgl.yacc"
    { yyval.sql_string=make_sql_string("ALL ",yyvsp[0].sql_string,0); }
    break;

  case 1735:
#line 7970 "fgl.yacc"
    { yyval.sql_string=make_sql_string("ANY ",yyvsp[0].sql_string,0); }
    break;

  case 1736:
#line 7971 "fgl.yacc"
    { yyval.sql_string=make_sql_string("SOME ",yyvsp[0].sql_string,0); }
    break;

  case 1737:
#line 7972 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1738:
#line 7975 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].str,".",yyvsp[0].str,0);
	}
    break;

  case 1739:
#line 7982 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,"/",yyvsp[0].sql_string,0);}
    break;

  case 1740:
#line 7984 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-1].sql_string," ",yyvsp[0].str,0);}
    break;

  case 1741:
#line 7986 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,"*",yyvsp[0].sql_string,0);}
    break;

  case 1742:
#line 7988 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,"+",yyvsp[0].sql_string,0);}
    break;

  case 1743:
#line 7990 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,"-",yyvsp[0].sql_string,0);}
    break;

  case 1744:
#line 7991 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[0].str,0);}
    break;

  case 1745:
#line 7992 "fgl.yacc"
    {yyval.sql_string=make_sql_string("1",0);}
    break;

  case 1746:
#line 7993 "fgl.yacc"
    {yyval.sql_string=make_sql_string("0",0);}
    break;

  case 1747:
#line 7994 "fgl.yacc"
    {yyval.sql_string=make_sql_string("USER",0);}
    break;

  case 1748:
#line 7995 "fgl.yacc"
    {yyval.sql_string=make_sql_string("*",0);}
    break;

  case 1749:
#line 7996 "fgl.yacc"
    {yyval.sql_string=make_sql_string("COUNT(*)",0);}
    break;

  case 1750:
#line 7998 "fgl.yacc"
    {yyval.sql_string=make_sql_string("AVG(",yyvsp[-2].str,yyvsp[-1].sql_string,")",0);}
    break;

  case 1751:
#line 8000 "fgl.yacc"
    {yyval.sql_string=make_sql_string("MAX(",yyvsp[-2].str,yyvsp[-1].sql_string,")",0);}
    break;

  case 1752:
#line 8002 "fgl.yacc"
    {yyval.sql_string=make_sql_string("MIN(",yyvsp[-2].str,yyvsp[-1].sql_string,")",0);}
    break;

  case 1753:
#line 8004 "fgl.yacc"
    {yyval.sql_string=make_sql_string("SUM(",yyvsp[-2].str,yyvsp[-1].sql_string,")",0);}
    break;

  case 1754:
#line 8006 "fgl.yacc"
    {yyval.sql_string=make_sql_string("COUNT(",yyvsp[-2].str,yyvsp[-1].sql_string,")",0);}
    break;

  case 1755:
#line 8008 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-3].str,"(",yyvsp[-1].sql_string,")",0);}
    break;

  case 1756:
#line 8010 "fgl.yacc"
    {yyval.sql_string=make_sql_string("DATE(",yyvsp[-1].sql_string,")",0);}
    break;

  case 1757:
#line 8011 "fgl.yacc"
    {yyval.sql_string=make_sql_string("(",yyvsp[-1].sql_string,")",0);}
    break;

  case 1758:
#line 8013 "fgl.yacc"
    {yyval.sql_string=make_sql_string("EXTEND(",yyvsp[-1].sql_string,")",0);}
    break;

  case 1759:
#line 8014 "fgl.yacc"
    { yyval.sql_string=make_sql_string(yyvsp[0].str,0);}
    break;

  case 1760:
#line 8015 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[0].str,0);}
    break;

  case 1761:
#line 8021 "fgl.yacc"
    {yyval.sql_string=yyvsp[0].sql_string;}
    break;

  case 1762:
#line 8022 "fgl.yacc"
    {
	yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",",yyvsp[0].sql_string,0);
}
    break;

  case 1764:
#line 8032 "fgl.yacc"
    {
print_unload(yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].sql_string);
print_undo_use(yyvsp[-4].str);
}
    break;

  case 1765:
#line 8040 "fgl.yacc"
    {
print_load(yyvsp[-4].str,yyvsp[-3].str,yyvsp[-1].str,yyvsp[0].str);
print_undo_use(yyvsp[-6].str);
}
    break;

  case 1766:
#line 8044 "fgl.yacc"
    {
print_load_str(yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);
print_undo_use(yyvsp[-4].str);
}
    break;

  case 1767:
#line 8051 "fgl.yacc"
    {strcpy(yyval.str,"\"|\"");}
    break;

  case 1768:
#line 8051 "fgl.yacc"
    {
strcpy(yyval.str,yyvsp[0].str);
}
    break;

  case 1770:
#line 8055 "fgl.yacc"
    {
		if ((scan_variable(yyvsp[0].str)&15)!=0) {a4gl_yyerror("Variable must be of type charr..");YYERROR;}
}
    break;

  case 1771:
#line 8060 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 1772:
#line 8060 "fgl.yacc"
    {
sprintf(yyval.str,"%s,0",yyvsp[-1].str);
}
    break;

  case 1774:
#line 8064 "fgl.yacc"
    {
    sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 1775:
#line 8068 "fgl.yacc"
    {
     sprintf(yyval.str,"\"%s\"",yyvsp[0].str);
}
    break;

  case 1778:
#line 8077 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1779:
#line 8077 "fgl.yacc"
    {
print_use_session(yyvsp[0].str);
strcpy(yyval.str,A4GL_get_undo_use());
}
    break;

  case 1784:
#line 8096 "fgl.yacc"
    { sprintf(yyval.str,"%s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str); }
    break;

  case 1785:
#line 8097 "fgl.yacc"
    { sprintf(yyval.str,"RENAME COLUMN  %s.%s TO %s",yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str); }
    break;

  case 1788:
#line 8105 "fgl.yacc"
    {
		sprintf(yyval.str,"%s %s",yyvsp[-1].str,yyvsp[0].str);
	}
    break;

  case 1789:
#line 8111 "fgl.yacc"
    {
		sprintf(yyval.str,"%s %s %s",
					yyvsp[-2].str,
					yyvsp[-1].str,
					yyvsp[0].str
					);
		}
    break;

  case 1792:
#line 8130 "fgl.yacc"
    {strcpy(yyval.str,"UNITS YEAR");}
    break;

  case 1793:
#line 8131 "fgl.yacc"
    {strcpy(yyval.str,"UNITS MONTH"); }
    break;

  case 1794:
#line 8132 "fgl.yacc"
    {strcpy(yyval.str,"UNITS DAY"); }
    break;

  case 1795:
#line 8133 "fgl.yacc"
    {strcpy(yyval.str,"UNITS HOUR"); }
    break;

  case 1796:
#line 8134 "fgl.yacc"
    {strcpy(yyval.str,"UNITS MINUTE"); }
    break;

  case 1797:
#line 8135 "fgl.yacc"
    {strcpy(yyval.str,"UNITS SECOND"); }
    break;

  case 1798:
#line 8139 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str," ",yyvsp[-1].str," ",yyvsp[0].str,0);}
    break;

  case 1799:
#line 8140 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-4].sql_string,yyvsp[-3].str,yyvsp[-2].str," ",yyvsp[-1].str," ",yyvsp[0].str,0);}
    break;

  case 1800:
#line 8141 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-3].str,yyvsp[-2].str," ",yyvsp[-1].str," ",yyvsp[0].str,0);}
    break;

  case 1802:
#line 8146 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1803:
#line 8147 "fgl.yacc"
    {sprintf(yyval.str,"%s %s TO %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1804:
#line 8151 "fgl.yacc"
    {sprintf(yyval.str,"DATETIME (\\\"%s\\\")",A4GL_strip_quotes(yyvsp[-1].str));}
    break;

  case 1805:
#line 8152 "fgl.yacc"
    {sprintf(yyval.str,"DATETIME(%s)",yyvsp[-1].str);}
    break;

  case 1806:
#line 8153 "fgl.yacc"
    {sprintf(yyval.str,"DATETIME(%s-%s)",yyvsp[-3].str,yyvsp[-1].str);}
    break;

  case 1807:
#line 8154 "fgl.yacc"
    {sprintf(yyval.str,"DATETIME(%s:%s)",yyvsp[-3].str,yyvsp[-1].str);}
    break;

  case 1808:
#line 8155 "fgl.yacc"
    {sprintf(yyval.str,"DATETIME(%s-%s-%s)",yyvsp[-5].str,yyvsp[-3].str,yyvsp[-1].str);}
    break;

  case 1809:
#line 8156 "fgl.yacc"
    {sprintf(yyval.str,"DATETIME(%s:%s:%s)",yyvsp[-5].str,yyvsp[-3].str,yyvsp[-1].str);}
    break;

  case 1810:
#line 8157 "fgl.yacc"
    {sprintf(yyval.str,
		"DATETIME(%s-%s-%s %s:%s:%s)",yyvsp[-10].str,yyvsp[-8].str,yyvsp[-6].str,yyvsp[-5].str,yyvsp[-3].str,yyvsp[-1].str);}
    break;

  case 1811:
#line 8159 "fgl.yacc"
    {sprintf(yyval.str,"DATETIME(%s-%s-%s %s:%s)",yyvsp[-8].str,yyvsp[-6].str,yyvsp[-4].str,yyvsp[-3].str,yyvsp[-1].str);}
    break;

  case 1812:
#line 8163 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1813:
#line 8164 "fgl.yacc"
    {sprintf(yyval.str,"%s %s(%s) TO %s",yyvsp[-6].str,yyvsp[-5].str,yyvsp[-3].str,yyvsp[0].str);}
    break;

  case 1814:
#line 8165 "fgl.yacc"
    {sprintf(yyval.str,"%s %s TO %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1815:
#line 8169 "fgl.yacc"
    {sprintf(yyval.str,"INTERVAL(\\\"%s\\\")",A4GL_strip_quotes(yyvsp[-1].str));}
    break;

  case 1816:
#line 8170 "fgl.yacc"
    {sprintf(yyval.str,"INTERVAL(%s)",yyvsp[-1].str);}
    break;

  case 1817:
#line 8171 "fgl.yacc"
    {sprintf(yyval.str,"INTERVAL(%s-%s)",yyvsp[-3].str,yyvsp[-1].str);}
    break;

  case 1818:
#line 8172 "fgl.yacc"
    {sprintf(yyval.str,"INTERVAL(%s:%s)",yyvsp[-3].str,yyvsp[-1].str);}
    break;

  case 1819:
#line 8173 "fgl.yacc"
    {sprintf(yyval.str,"INTERVAL(%s-%s-%s)",yyvsp[-5].str,yyvsp[-3].str,yyvsp[-1].str);}
    break;

  case 1820:
#line 8174 "fgl.yacc"
    {sprintf(yyval.str,"INTERVAL(%s:%s:%s)",yyvsp[-5].str,yyvsp[-3].str,yyvsp[-1].str);}
    break;

  case 1821:
#line 8177 "fgl.yacc"
    {
		sql_mode=1;
		start_bind('i',0);
		start_bind('o',0);
	}
    break;

  case 1822:
#line 8181 "fgl.yacc"
    {
			sql_mode=0;
			print_sql_block_cmd(yyvsp[-1].str);
	}
    break;

  case 1824:
#line 8190 "fgl.yacc"
    {sprintf(yyval.str,"%s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1826:
#line 8195 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1827:
#line 8196 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 2143:
#line 8520 "fgl.yacc"
    {sql_mode=0;}
    break;

  case 2144:
#line 8520 "fgl.yacc"
    {
		strcpy(yyval.str,yyvsp[0].sql_string);
		sql_mode=1;
	}
    break;

  case 2145:
#line 8527 "fgl.yacc"
    {sql_mode=0;}
    break;

  case 2146:
#line 8527 "fgl.yacc"
    {
 		strcpy(yyval.str,A4GL_get_into_part(doing_declare,get_bind_cnt('o')));
		sql_mode=1;
	}
    break;

  case 2147:
#line 8615 "fgl.yacc"
    {
		strcpy(current_upd_table,yyvsp[0].str);
		pop_all_gen(UPDCOL,"!"); pop_all_gen(UPDVAL,"!"); pop_all_gen(UPDVAL2,"!");
		yyval.sql_string=strdup("");
	}
    break;

  case 2148:
#line 8619 "fgl.yacc"
    {
		strcpy(current_upd_table,"");
	}
    break;

  case 2149:
#line 8621 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-5].str," ",yyvsp[-4].str," ",yyvsp[-2].sql_string," ",yyvsp[0].sql_string,0);
	}
    break;

  case 2150:
#line 8628 "fgl.yacc"
    {
		pop_all_gen(UPDCOL,"!"); pop_all_gen(UPDVAL,"!"); pop_all_gen(UPDVAL2,"!");
		yyval.sql_string=strdup("");
	}
    break;

  case 2151:
#line 8632 "fgl.yacc"
    { 
		pop_all_gen(UPDCOL,"!"); pop_all_gen(UPDVAL,"!"); pop_all_gen(UPDVAL2,"!");
		rm_quotes(yyvsp[0].str);
		sprintf(yyval.str,"%s %s",yyvsp[-1].str,yyvsp[0].str);
		yyval.sql_string=make_sql_string(yyval.str,0);
	}
    break;

  case 2152:
#line 8638 "fgl.yacc"
    {
		pop_all_gen(UPDCOL,"!"); pop_all_gen(UPDVAL,"!"); pop_all_gen(UPDVAL2,"!");
		yyval.sql_string=make_sql_string("WHERE ",yyvsp[0].sql_string,0);
	}
    break;

  case 2153:
#line 8646 "fgl.yacc"
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

  case 2154:
#line 8656 "fgl.yacc"
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

  case 2155:
#line 8666 "fgl.yacc"
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

  case 2156:
#line 8678 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("SET ",yyvsp[0].sql_string,0);
    }
    break;

  case 2157:
#line 8681 "fgl.yacc"
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

  case 2158:
#line 8700 "fgl.yacc"
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

  case 2159:
#line 8726 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 2160:
#line 8729 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",",yyvsp[0].sql_string,0);
	}
    break;

  case 2162:
#line 8738 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].str,"=",yyvsp[0].sql_string,0);
	}
    break;

  case 2163:
#line 8743 "fgl.yacc"
    {
			push_gen(UPDCOL,yyvsp[0].str); strcpy(yyval.str,yyvsp[0].str);
		}
    break;

  case 2164:
#line 8746 "fgl.yacc"
    {
			push_gen(UPDCOL,yyvsp[0].str); sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);
		}
    break;

  case 2165:
#line 8754 "fgl.yacc"
    { 
		yyval.sql_string=yyvsp[0].sql_string; 
		if (gen_cnt(UPDVAL2)) {
			copy_gen(UPDVAL,UPDVAL2);
		} else {
                	push_gen(UPDVAL,yyvsp[0].sql_string);
		}
	}
    break;

  case 2166:
#line 8762 "fgl.yacc"
    { 
		if (gen_cnt(UPDVAL2)) {
			copy_gen(UPDVAL,UPDVAL2);
		} else {
                	push_gen(UPDVAL,yyvsp[0].sql_string);
		}
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",",yyvsp[0].sql_string,0); 
	}
    break;

  case 2167:
#line 8775 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 2168:
#line 8778 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 2169:
#line 8786 "fgl.yacc"
    {
                yyval.sql_string=yyvsp[0].sql_string;
        }
    break;

  case 2170:
#line 8789 "fgl.yacc"
    {
                yyval.sql_string=make_sql_string("-",yyvsp[0].sql_string,0);
        }
    break;

  case 2171:
#line 8792 "fgl.yacc"
    {
                yyval.sql_string=make_sql_string("+",yyvsp[0].sql_string,0);
        }
    break;

  case 2172:
#line 8800 "fgl.yacc"
    { 
		
		yyval.sql_string=yyvsp[0].sql_string; 
	}
    break;

  case 2173:
#line 8804 "fgl.yacc"
    { yyval.sql_string=yyvsp[0].sql_string; }
    break;

  case 2174:
#line 8805 "fgl.yacc"
    { yyval.sql_string=strdup(yyvsp[0].str); }
    break;

  case 2175:
#line 8806 "fgl.yacc"
    { yyval.sql_string=make_sql_string(yyvsp[-2].str,".",yyvsp[0].str,0); }
    break;

  case 2176:
#line 8807 "fgl.yacc"
    { yyval.sql_string=make_sql_string(yyvsp[-3].str,"[",yyvsp[-1].str,"]",0); }
    break;

  case 2177:
#line 8808 "fgl.yacc"
    { yyval.sql_string=make_sql_string(yyvsp[-5].str,".",yyvsp[-3].str,"[",yyvsp[-1].str,"]",0); }
    break;

  case 2178:
#line 8809 "fgl.yacc"
    { yyval.sql_string=make_sql_string(yyvsp[-5].str,"[",yyvsp[-3].str,",",yyvsp[-1].str,"]",0); }
    break;

  case 2179:
#line 8810 "fgl.yacc"
    { yyval.sql_string=make_sql_string(yyvsp[-7].str,".",yyvsp[-5].str,"[",yyvsp[-3].str,",",yyvsp[-1].str,"]",0); }
    break;

  case 2180:
#line 8811 "fgl.yacc"
    { 
		yyval.sql_string=yyvsp[0].sql_string; 
		pop_all_gen(UPDVAL2,"!");
	}
    break;

  case 2181:
#line 8815 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[0].str,0);}
    break;

  case 2182:
#line 8816 "fgl.yacc"
    {yyval.sql_string=make_sql_string("TRUE",0);}
    break;

  case 2183:
#line 8817 "fgl.yacc"
    {yyval.sql_string=make_sql_string("FALSE",0);}
    break;

  case 2184:
#line 8818 "fgl.yacc"
    {yyval.sql_string=make_sql_string("USER",0);}
    break;

  case 2185:
#line 8819 "fgl.yacc"
    {yyval.sql_string=make_sql_string("COUNT(*)",0);}
    break;

  case 2186:
#line 8825 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,"/",yyvsp[0].sql_string,0);}
    break;

  case 2187:
#line 8826 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-1].sql_string,yyvsp[0].str,0);}
    break;

  case 2188:
#line 8827 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,"*",yyvsp[0].sql_string,0);}
    break;

  case 2189:
#line 8828 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,"+",yyvsp[0].sql_string,0);}
    break;

  case 2190:
#line 8829 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,"-",yyvsp[0].sql_string,0);}
    break;

  case 2191:
#line 8830 "fgl.yacc"
    {yyval.sql_string=make_sql_string("AVERAGE(",yyvsp[-2].str,yyvsp[-1].sql_string,")",0);}
    break;

  case 2192:
#line 8831 "fgl.yacc"
    {yyval.sql_string=make_sql_string("MAX(",yyvsp[-2].str,yyvsp[-1].sql_string,")",0);}
    break;

  case 2193:
#line 8832 "fgl.yacc"
    {yyval.sql_string=make_sql_string("MIN(",yyvsp[-2].str,yyvsp[-1].sql_string,")",0);}
    break;

  case 2194:
#line 8833 "fgl.yacc"
    {yyval.sql_string=make_sql_string("SUM(",yyvsp[-2].str,yyvsp[-1].sql_string,")",0);}
    break;

  case 2195:
#line 8834 "fgl.yacc"
    {yyval.sql_string=make_sql_string("COUNT(",yyvsp[-2].str,yyvsp[-1].sql_string,")",0);}
    break;

  case 2196:
#line 8835 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-3].str,"(",yyvsp[-1].sql_string,")",0);}
    break;

  case 2197:
#line 8836 "fgl.yacc"
    {yyval.sql_string=make_sql_string("DATE(",yyvsp[-1].sql_string,")",0);}
    break;

  case 2198:
#line 8837 "fgl.yacc"
    {yyval.sql_string=make_sql_string("(",yyvsp[-1].sql_string,")",0);}
    break;

  case 2199:
#line 8838 "fgl.yacc"
    {yyval.sql_string=make_sql_string("EXTEND(",yyvsp[-1].sql_string,")",0);}
    break;

  case 2200:
#line 8839 "fgl.yacc"
    { yyval.sql_string=make_sql_string(yyvsp[0].str,0);}
    break;

  case 2201:
#line 8840 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[0].str,0);}
    break;

  case 2202:
#line 8845 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
}
    break;

  case 2203:
#line 8851 "fgl.yacc"
    {yyval.sql_string=yyvsp[0].sql_string;}
    break;

  case 2204:
#line 8852 "fgl.yacc"
    {
        yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",",yyvsp[0].sql_string,0);
}
    break;

  case 2205:
#line 8860 "fgl.yacc"
    {
	clr_validate_list();
}
    break;

  case 2206:
#line 8862 "fgl.yacc"
    {
	print_validate();
}
    break;

  case 2208:
#line 8868 "fgl.yacc"
    {sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 2209:
#line 8872 "fgl.yacc"
    {
		sprintf(yyval.str,"%s.%s",yyvsp[-2].str,yyvsp[0].str);
		push_validate(yyval.str);
	}
    break;

  case 2210:
#line 8876 "fgl.yacc"
    {
		sprintf(yyval.str,"%s.*",yyvsp[-2].str);
		push_validate(yyval.str);
	}
    break;

  case 2211:
#line 8892 "fgl.yacc"
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

  case 2212:
#line 8906 "fgl.yacc"
    {
		strcpy(yyval.str,variable_usage_as_string(yyvsp[0].var_usg,VAR_USG_ANY));
	}
    break;

  case 2213:
#line 8912 "fgl.yacc"
    {
		yyval.var_usg=yyvsp[0].var_usg;
	}
    break;

  case 2214:
#line 8914 "fgl.yacc"
    {
		yyval.var_usg=yyvsp[0].var_usg;
	}
    break;

  case 2218:
#line 8928 "fgl.yacc"
    {
		yyval.var_usg=append_variable_usage(yyvsp[-2].var_usg,yyvsp[0].var_usg);
	}
    break;

  case 2219:
#line 8931 "fgl.yacc"
    {
		yyval.var_usg=new_variable_usage(yyvsp[-2].var_usg,"*",0);
	}
    break;

  case 2220:
#line 8938 "fgl.yacc"
    {
			yyval.var_usg=yyvsp[0].var_usg;
	}
    break;

  case 2221:
#line 8941 "fgl.yacc"
    { yyval.var_usg=new_variable_usage(0,yyvsp[0].str,0); }
    break;

  case 2222:
#line 8971 "fgl.yacc"
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

  case 2223:
#line 8996 "fgl.yacc"
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

  case 2224:
#line 9043 "fgl.yacc"
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

  case 2225:
#line 9078 "fgl.yacc"
    {
		struct array_list *al;
         	A4GL_debug("---> Subscript or substring");
		al=malloc(sizeof(struct array_list));
		al->array=yyvsp[-1].num_list;
		al->substr=0;
		yyval.array_list=al;

        }
    break;

  case 2226:
#line 9087 "fgl.yacc"
    {
		struct array_list *al;
         	A4GL_debug("---> Subscript & substring");
		al=malloc(sizeof(struct array_list));
		al->array=yyvsp[-4].num_list;
		al->substr=yyvsp[-1].num_list;
		yyval.array_list=al;
        }
    break;

  case 2227:
#line 9098 "fgl.yacc"
    { 
			yyval.num_list=yyvsp[0].num_list; 
		}
    break;

  case 2228:
#line 9101 "fgl.yacc"
    { 
			yyval.num_list=append_num_list_items(yyvsp[-2].num_list,yyvsp[0].num_list); 
		}
    break;

  case 2229:
#line 9107 "fgl.yacc"
    {
  yyval.num_list=new_num_list_item(yyvsp[0].str);
}
    break;

  case 2230:
#line 9120 "fgl.yacc"
    {
		set_whenever_from_store();
}
    break;

  case 2231:
#line 9134 "fgl.yacc"
    {
print_while_1();
push_blockcommand("WHILE");
}
    break;

  case 2232:
#line 9137 "fgl.yacc"
    {
print_while_2();
}
    break;

  case 2233:
#line 9141 "fgl.yacc"
    {
print_while_3();
pop_blockcommand("WHILE");
}
    break;

  case 2234:
#line 9156 "fgl.yacc"
    {yyval.field_list=0;}
    break;

  case 2235:
#line 9156 "fgl.yacc"
    {
	yyval.field_list=yyvsp[0].field_list;
}
    break;

  case 2236:
#line 9162 "fgl.yacc"
    { strcpy(yyval.str,"0"); }
    break;

  case 2237:
#line 9163 "fgl.yacc"
    { strcpy(yyval.str,"1"); }
    break;

  case 2238:
#line 9166 "fgl.yacc"
    { print_current_window("\"screen\""); print_clr_window("\"screen\""); }
    break;

  case 2239:
#line 9167 "fgl.yacc"
    { print_clr_window(yyvsp[0].str); }
    break;

  case 2240:
#line 9168 "fgl.yacc"
    { print_clr_window(yyvsp[0].str); }
    break;

  case 2241:
#line 9169 "fgl.yacc"
    { print_clr_form(0,0,"0"); }
    break;

  case 2242:
#line 9170 "fgl.yacc"
    { print_clr_form(0,0,"1"); }
    break;

  case 2243:
#line 9171 "fgl.yacc"
    { print_clr_form(yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str); }
    break;

  case 2244:
#line 9172 "fgl.yacc"
    {
	print_clr_fields(field_name_list_as_char(yyvsp[-1].field_list),yyvsp[0].str);
}
    break;

  case 2245:
#line 9183 "fgl.yacc"
    {
	print_current_window("\"screen\"");
}
    break;

  case 2246:
#line 9187 "fgl.yacc"
    {
	print_current_window(yyvsp[0].str);
}
    break;

  case 2247:
#line 9191 "fgl.yacc"
    {
sprintf(yyval.str,"A4GL_cr_window");
reset_attrib(&form_attrib);
}
    break;

  case 2248:
#line 9195 "fgl.yacc"
    {
sprintf(yyval.str,"A4GL_cr_window_form");
reset_attrib(&form_attrib);
}
    break;

  case 2249:
#line 9200 "fgl.yacc"
    {
	print_show_window(yyvsp[0].str);
	addmap("Show Window",yyvsp[0].str,curr_func,yylineno,infilename); 
}
    break;

  case 2250:
#line 9204 "fgl.yacc"
    {
	print_show_menu(yyvsp[-3].str,yyvsp[-1].str);
	addmap("Call Menuhandler",yyvsp[-1].str,curr_func,yylineno,infilename); 
}
    break;

  case 2251:
#line 9209 "fgl.yacc"
    {

print_def_mn_file();

}
    break;

  case 2253:
#line 9217 "fgl.yacc"
    {addmap("Use Menu",yyvsp[0].str,curr_func,yylineno,infilename); }
    break;

  case 2255:
#line 9223 "fgl.yacc"
    {
	print_hide_window(yyvsp[0].str);
}
    break;

  case 2256:
#line 9229 "fgl.yacc"
    {
print_move_window(yyvsp[-4].str,0);
}
    break;

  case 2257:
#line 9233 "fgl.yacc"
    {
print_move_window(yyvsp[-4].str,1);
}
    break;

  case 2262:
#line 9251 "fgl.yacc"
    {
chk4var=0;A4GL_lex_printcomment("/* [Comm:%s] */\n",yyval.str);
if (A4GL_isyes(acl_getenv("INCLINES")))
A4GL_lex_printc("{A4GL_debug(\"Line %d %s:%s\");}",lastlineno,infilename,convstrsql(larr));
	A4GL_prchkerr(lastlineno,infilename);
	lastlineno=yylineno;
}
    break;

  case 2263:
#line 9258 "fgl.yacc"
    {
A4GL_lex_printcomment("/* [COMM:%s] */\n",yyvsp[0].str);chk4var=0;
if (A4GL_isyes(acl_getenv("INCLINES")))
A4GL_lex_printc("{A4GL_debug(\"Line %d %s:%s\");}",lastlineno,infilename,convstrsql(larr));
/* if (A4GL_aubit_strcasecmp($<str>$,"whenever")!=0)  */
A4GL_prchkerr(lastlineno,infilename);
lastlineno=yylineno;
}
    break;

  case 2264:
#line 9268 "fgl.yacc"
    {print_cmd_start();}
    break;

  case 2265:
#line 9268 "fgl.yacc"
    {print_cmd_end();}
    break;


    }

/* Line 991 of yacc.c.  */
#line 19214 "y.tab.c"

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


#line 996 "fgl.yacc"

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



